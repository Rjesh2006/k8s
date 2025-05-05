# 🚀 Exploring Kubernetes with Minikube & KIND

Welcome to this comprehensive Kubernetes learning repository! 🌐

Here, we dive deep into mastering Kubernetes using both **Minikube** and **KIND (Kubernetes in Docker)**. This repo will serve as a central hub for everything related to Kubernetes, including:

- Deployments
- Services 
- ConfigMaps
- Secrets
- StatefulSets
- PersistentVolumes (PV) & PersistentVolumeClaims (PVC)
- YAML configurations
- Real-world project deployments
- Docker image creation for custom apps
- CI/CD pipeline integration using **Jenkins**

This repository is designed to help DevOps enthusiasts and learners understand and implement essential Kubernetes components through hands-on experience.

💡 Whether you're just starting out or brushing up on your skills, this is your go-to resource for mastering Kubernetes the practical way.

**Stay tuned — continuous updates and real-world use cases will be added regularly. Let's master Kubernetes together! 🔧🐳🚀**



# 🚀 Study Material App (Laravel)

## Here we have the fullstack study material app which we're going to deploy on Kubernetes

Welcome to this comprehensive repository containing both:
1. A full-stack Laravel study material application
2. Kubernetes learning materials using Minikube & KIND

## 📚 Table of Contents
- [Laravel Application Setup](#-laravel-application-setup)
- [Kubernetes Learning Resources](#-kubernetes-learning-resources)
- [Deployment to Kubernetes](#-deployment-to-kubernetes)

## 🛠 Laravel Application Setup

To run the Laravel web application locally:

# Clone the repository
  git clone https://github.com/krishna1632/study_material_app.git
  cd study-material-app
# install php
   install php 
# Install backend dependencies
   composer install

# Setup environment
   cp .env.example .env
   php artisan key:generate

# Database setup (SQLite)
# Laravel will prompt you to create the SQLite file - type 'Yes' when asked:
# "The SQLite database configured for this application does not exist. Would you like to create it? (Yes/No)"
 #and if wann to crate this manually do it by this given follows extension file
  touch database/database.sqlite

# Run migrations and seed data
  php artisan migrate
  php artisan db:seed

# Install frontend dependencies
  npm install
  npm run dev

# Start the development server
  php artisan serve


# 📘 Kubernetes: Init & Sidecar Containers + Istio + mTLS + CRDs

This document is a complete reference for understanding key Kubernetes and Istio concepts including:

- Init Containers
- Sidecar Containers
- Istio Service Mesh
- mTLS (Mutual TLS)
- CRDs (Custom Resource Definitions)
- Real-world examples and commands

---

## 🚀 Init Containers

**Init containers** are special containers that run **before** the main container in a Pod starts.

### 🔧 Use Cases:

- Download dependencies
- Perform setup (e.g., DB migrations)
- Wait for other services to be ready
- Ensure config or secrets are available

### ✅ Key Features:

- Always run to completion
- Run sequentially
- Separate from the main container

### 🧪 Example:

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: example-pod
spec:
  initContainers:
  - name: init-myservice
    image: busybox
    command: ['sh', '-c', 'echo Waiting for DB... && sleep 10']
  containers:
  - name: main-app
    image: myapp:latest

# 📦 CRDs Created During Istio Installation  
When you install Istio, it automatically adds several **Custom Resource Definitions (CRDs)** to extend Kubernetes.  

| CRD Kind               | Purpose                                                                 |
|------------------------|-------------------------------------------------------------------------|
| `VirtualService`       | Defines smart routing rules (e.g., traffic splitting, retries, timeouts) |
| `DestinationRule`      | Configures subsets, traffic policies (e.g., load balancing, TLS settings) |
| `Gateway`              | Manages ingress/egress traffic for the mesh                              |
| `ServiceEntry`         | Allows external services to be part of the mesh (e.g., APIs, databases)  |
| `Sidecar`              | Configures sidecar proxy behavior for workloads                         |
| `PeerAuthentication`   | Enables **mTLS** (mutual TLS) for service-to-service communication      |
| `AuthorizationPolicy`  | Defines access control rules (e.g., RBAC, deny/allows)                  |
| `Telemetry`            | Customizes metrics, logs, and tracing configurations                    |
| `EnvoyFilter`          | Modifies low-level Envoy proxy behavior (advanced use cases)            |
| `WasmPlugin`           | Adds WebAssembly (WASM) filters to Envoy proxies                        |
| `WorkloadEntry`        | Registers VMs or bare-metal workloads into the mesh                     |
| `WorkloadGroup`        | Groups configuration for external workloads (e.g., VM templates)        |

### Example YAML Snippets  
```yaml
# Example VirtualService
apiVersion: networking.istio.io/v1alpha3
kind: VirtualService
metadata:
  name: reviews-route
spec:
  hosts:
    - reviews
  http:
    - route:
        - destination:
            host: reviews
            subset: v1
          weight: 80
        - destination:
            host: reviews
            subset: v2
          weight: 20
```

```yaml
# Example PeerAuthentication (mTLS)
apiVersion: security.istio.io/v1beta1
kind: PeerAuthentication
metadata:
  name: default
spec:
  mtls:
    mode: STRICT
```

> **Note**: Run `kubectl get crds | grep istio.io` to see all Istio CRDs installed in your cluster.  
