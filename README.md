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

```bash
# Clone the repository
git clone https://github.com/krishna1632/study_material_app.git
cd study-material-app

# Install backend dependencies
composer install

# Setup environment
cp .env.example .env
php artisan key:generate

# Database setup (SQLite)
# Laravel will prompt you to create the SQLite file - type 'Yes' when asked:
# "The SQLite database configured for this application does not exist. Would you like to create it? (Yes/No)"
touch database/database.sqlite

# Run migrations and seed data
php artisan migrate
php artisan db:seed

# Install frontend dependencies
npm install
npm run dev

# Start the development server
php artisan serve


