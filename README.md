# OpenGL GLFW Base Project

A modern, extensible C++ foundation for exploring advanced graphics rendering techniques using OpenGL, GLFW, and GLM. This project provides a solid architectural base.

## Features

- **Window Management**: GLFW-based window creation and input handling
- **OpenGL Abstraction**: GLAD for modern OpenGL loading and GPU resource management
- **Entity Component System (ECS)**: Flexible architecture for game/graphics object management
- **Math Utilities**: GLM integration with custom transform and vector operations
- **GPU Resources**: Pre-built wrappers for VAO, VBO, EBO, and shader programs
- **Mesh System**: Built-in mesh loading and GPU buffer management
- **Modular Design**: Clean separation of concerns for easy extension

## Project Structure

```
├── src/
│   ├── Core/              # Application and window management
│   │   ├── application.h/cpp
│   │   └── window.h/cpp
│   ├── ECS/               # Entity Component System
│   │   ├── Component.h
│   │   ├── Entity.h
│   │   ├── System.h
│   │   ├── ComponentStore.h
│   │   └── Scene.h/cpp
│   ├── utils/
│   │   ├── Object/        # OpenGL abstractions
│   │   │   ├── VAO.h/cpp  # Vertex Array Objects
│   │   │   ├── VBO.h/cpp  # Vertex Buffer Objects
│   │   │   ├── EBO.h/cpp  # Element Buffer Objects
│   │   │   ├── mesh.h/cpp
│   │   │   └── shader.h/cpp
│   │   └── Math/          # Math utilities
│   │       ├── vector.h/cpp
│   │       ├── matrix.h/cpp
│   │       └── transform.h/cpp
│   ├── enum/              # Enum definitions
│   │   └── primitives.cpp
│   ├── glad.c
│   └── main.cpp
├── libs/
│   ├── glfw/              # GLFW3 for window management
│   └── glm/               # GLM for math operations
├── CMakeLists.txt
└── README.md
```

## Getting Started

### Prerequisites

- **CMake** 3.10 or higher
- **C++17** compatible compiler (MSVC, GCC, or Clang)
- **OpenGL 3.3+** capable GPU

### Building

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd Opengl-GLFW-Setup
   ```

2. Create a build directory and compile:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release
   ```

3. Run the executable:
   ```bash
   ./OpenGLProject
   ```

## Architecture Overview

### Application Flow

The project follows a simple but extensible lifecycle:

```
main.cpp
  └─> Application::Application()
       └─> Window creation & OpenGL context setup
  └─> Application::Run()
       └─> Main loop
            ├─> Input handling
            ├─> Update logic
            ├─> Render
            └─> Present
```

### Entity Component System (ECS)

The ECS architecture allows you to compose game objects from reusable components:

- **Entity**: A unique identifier for objects in your scene
- **Component**: Data containers (transform, mesh, physics, etc.)
- **System**: Logic that operates on entities with specific components
- **Scene**: Container for entities and components

Example usage pattern (to be implemented):

```cpp
Scene scene;
Entity player = scene.CreateEntity();
scene.AddComponent<TransformComponent>(player, {position, rotation, scale});
scene.AddComponent<MeshComponent>(player, meshData);
```

## Key Utilities

### GPU Resources

- **VAO (Vertex Array Object)**: Encapsulates vertex buffer layout
- **VBO (Vertex Buffer Object)**: GPU vertex data storage
- **EBO (Element Buffer Object)**: Index buffer for indexed rendering
- **Shader**: Shader program compilation and uniform management

### Math Operations

- **Vector**: 2D, 3D, 4D vector operations
- **Matrix**: 4x4 matrix for transformations
- **Transform**: Position, rotation, scale composition

### Spatial Queries

- **QuadTree**: Efficient 2D spatial partitioning for collision detection or visibility culling

## Extending the Project

This base project is designed to be easily extended. Here are some areas you can explore:

### Rendering Techniques

- **Deferred Rendering**: Implement G-buffer passes and deferred shading
- **Shadow Mapping**: Add real-time shadows using depth maps
- **Normal Mapping**: Advanced surface detail without geometry
- **Parallax Mapping**: Depth-based texture displacement
- **Screen-Space Ambient Occlusion (SSAO)**: Realistic shadowing in crevices

### Animation Systems

- **Skeletal Animation**: Bone-based character animation
- **Morphing**: Vertex-based animation blending
- **Keyframe Interpolation**: Smooth animation between keyframes
- **Inverse Kinematics (IK)**: Procedural pose generation

### Advanced Features

- **Particle Effects**: GPU particle simulation
- **Post-Processing**: Bloom, depth of field, motion blur
- **Instancing**: Efficient rendering of repeated geometry
- **Compute Shaders**: Data-parallel GPU operations
- **Physically-Based Rendering (PBR)**: Realistic material properties
- **Real-Time Ray Tracing**: NVIDIA RTX integration

## Common Workflows

### Adding a New Rendering Feature

1. Create shader files (`.vert`, `.frag`)
2. Extend `Shader` class if needed
3. Create a `System` in the ECS to handle the feature
4. Add `Component` types for required data
5. Integrate into the application loop

### Creating a New Entity Type

1. Define required components
2. Create an entity in `Scene`
3. Add components with relevant data
4. Create a system to process these entities

## Development Tips

- **Use CMake's message() for debugging** during build configuration
- **Enable OpenGL debug output** for GPU error detection
- **Profile with GPU tools** (NVIDIA Nsight, RenderDoc) for performance optimization
- **Start with simple geometry** (cubes, spheres) before complex models
- **Test incrementally** - validate each rendering technique in isolation

## Dependencies

- **GLFW 3.x**: Window creation, input, and context management
- **GLAD**: OpenGL function loader
- **GLM**: Header-only math library (vectors, matrices, quaternions)

All dependencies are included in the `libs/` directory.

## License

This project is provided as-is for educational and exploration purposes. See individual library licenses in their respective directories.

## Contributing

This is a personal project, but feel free to fork and extend it for your own graphics exploration and learning.

## Resources

- [Learn OpenGL](https://learnopengl.com/) - Comprehensive OpenGL tutorials
- [GLFW Documentation](https://www.glfw.org/documentation.html)
- [GLM Manual](https://github.com/g-truc/glm/blob/master/manual.md)
- [Real-Time Rendering](https://www.realtimerendering.com/) - Industry standard reference
- [Game Engine Architecture](https://www.gameenginebook.com/) - Advanced graphics techniques

---

**Happy rendering!** Start with basic shapes and transforms, then progressively add more advanced techniques as you become comfortable with the architecture.
