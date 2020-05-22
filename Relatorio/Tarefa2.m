%% Tarefa 2

N_M = 10;
x = linspace(0, 1, N_M + 1);
t = linspace(0, 1, N_M + 1);

%% 2B
R2b = readmatrix('Output2B.txt', 'CommentStyle',{'='});
R2b(:,end) = [];

R2b1 = R2b(2:N_M+2,:);
figure(1)
surf(x, t, R2b1)
title('Funcao u do item 1A com metodo de Euler implicito')
xlabel('0 < x < 1') 
ylabel('0 < t < 1')
zlabel('Temperatura')
shading interp

R2b2 = R2b(N_M+4:2*N_M+4,:);
figure(2)
surf(x, t, R2b2)
title('Funcao u do item 1B com metodo de Euler implicito')
xlabel('0 < x < 1') 
ylabel('0 < t < 1')
zlabel('Temperatura')
colormap('summer')
shading interp

R2b3 = R2b(2*N_M+6:3*N_M+6,:);
figure(3)
surf(x, t, R2b3)
title('Funcao u do item 1C com metodo de Euler implicito')
xlabel('0 < x < 1')
ylabel('0 < t < 1')
zlabel('Temperatura')
colormap('spring')
shading interp

% 2B - Graficos 2D

figure(4)
hold
distancia = floor(N_M/10);
Ratual = R2b1(1, :);
plot(x, Ratual)
for v = 1:10
   Ratual = R2b1(1+v*distancia, :);
   plot(x, Ratual)
end
legend('t = 0','t = 0.1','t = 0.2','t = 0.3','t = 0.4','t = 0.5', 't = 0.6', 't = 0.7', 't = 0.8', 't = 0.9', 't = 1')
title('Funcao u do item 1A com metodo de Euler implicito')
xlabel('0 < x < 1') 
ylabel('Temperatura')

figure(5)
hold
distancia = floor(N_M/10);
Ratual = R2b2(1, :);
plot(x, Ratual)
for v = 1:10
   Ratual = R2b2(1+v*distancia, :);
   plot(x, Ratual)
end
legend('t = 0','t = 0.1','t = 0.2','t = 0.3','t = 0.4','t = 0.5', 't = 0.6', 't = 0.7', 't = 0.8', 't = 0.9', 't = 1')
title('Funcao u do item 1B com metodo de Euler implicito')
xlabel('0 < x < 1') 
ylabel('Temperatura')

figure(6)
hold
distancia = floor(N_M/10);
Ratual = R2b3(1, :);
plot(x, Ratual)
for v = 1:10
   Ratual = R2b3(1+v*distancia, :);
   plot(x, Ratual)
end
legend('t = 0','t = 0.1','t = 0.2','t = 0.3','t = 0.4','t = 0.5', 't = 0.6', 't = 0.7', 't = 0.8', 't = 0.9', 't = 1')
title('Funcao u do item 1C com metodo de Euler implicito')
xlabel('0 < x < 1') 
ylabel('Temperatura')

% Erros 2B

R2bErro = readmatrix('Erro2B.txt', 'CommentStyle',{'='});
R2bErro(:,end) = [];

R2bErro1 = R2bErro(2:N_M+2,:);
figure(7)
surf(x, t, R2bErro1)
title('Erro do item 1A com metodo de Euler implicito')
xlabel('0 < x < 1') 
ylabel('0 < t < 1')
zlabel('Temperatura')
shading interp

R2bErro2 = R2bErro(N_M+4:2*N_M+4,:);
figure(8)
surf(x, t, R2bErro2)
title('Erro do item 1B com metodo de Euler implicito')
xlabel('0 < x < 1') 
ylabel('0 < t < 1')
zlabel('Temperatura')
colormap('summer')
shading interp

%% 2C
R2c = readmatrix('Output2C.txt', 'CommentStyle',{'='});
R2c(:,end) = [];

R2c1 = R2c(2:N_M+2,:);
figure(9)
surf(x, t, R2c1)
title('Funcao u do item 1A com metodo de Crank Nicolson')
xlabel('0 < x < 1') 
ylabel('0 < t < 1')
zlabel('Temperatura')
shading interp

R2c2 = R2c(N_M+4:2*N_M+4,:);
figure(10)
surf(x, t, R2c2)
title('Funcao u do item 1B com metodo de Crank Nicolson')
xlabel('0 < x < 1') 
ylabel('0 < t < 1')
zlabel('Temperatura')
colormap('summer')
shading interp

R2c3 = R2c(2*N_M+6:3*N_M+6,:);
figure(11)
surf(x, t, R2c3)
title('Funcao u do item 1C com metodo de Crank Nicolson')
xlabel('0 < x < 1')
ylabel('0 < t < 1')
zlabel('Temperatura')
colormap('spring')
shading interp

% 2C - Graficos 2D

figure(12)
hold
distancia = floor(N_M/10);
Ratual = R2c1(1, :);
plot(x, Ratual)
for v = 1:10
   Ratual = R2c1(1+v*distancia, :);
   plot(x, Ratual)
end
legend('t = 0','t = 0.1','t = 0.2','t = 0.3','t = 0.4','t = 0.5', 't = 0.6', 't = 0.7', 't = 0.8', 't = 0.9', 't = 1')
title('Funcao u do item 1A com metodo de Crank Nicolson')
xlabel('0 < x < 1') 
ylabel('Temperatura')

figure(13)
hold
distancia = floor(N_M/10);
Ratual = R2c2(1, :);
plot(x, Ratual)
for v = 1:10
   Ratual = R2c2(1+v*distancia, :);
   plot(x, Ratual)
end
legend('t = 0','t = 0.1','t = 0.2','t = 0.3','t = 0.4','t = 0.5', 't = 0.6', 't = 0.7', 't = 0.8', 't = 0.9', 't = 1')
title('Funcao u do item 1B com metodo de Crank Nicolson')
xlabel('0 < x < 1') 
ylabel('Temperatura')

figure(14)
hold
distancia = floor(N_M/10);
Ratual = R2c3(1, :);
plot(x, Ratual)
for v = 1:10
   Ratual = R2c3(1+v*distancia, :);
   plot(x, Ratual)
end
legend('t = 0','t = 0.1','t = 0.2','t = 0.3','t = 0.4','t = 0.5', 't = 0.6', 't = 0.7', 't = 0.8', 't = 0.9', 't = 1')
title('Funcao u do item 1C com metodo de Crank Nicolson')
xlabel('0 < x < 1') 
ylabel('Temperatura')

% Erros 2C

R2cErro = readmatrix('Erro2C.txt', 'CommentStyle',{'='});
R2cErro(:,end) = [];

R2cErro1 = R2cErro(2:N_M+2,:);
figure(15)
surf(x, t, R2cErro1)
title('Erro do item 1A com metodo de Crank Nicolson')
xlabel('0 < x < 1') 
ylabel('0 < t < 1')
zlabel('Temperatura')
shading interp

R2cErro2 = R2cErro(N_M+4:2*N_M+4,:);
figure(16)
surf(x, t, R2cErro2)
title('Erro do item 1B com metodo de Crank Nicolson')
xlabel('0 < x < 1') 
ylabel('0 < t < 1')
zlabel('Temperatura')
colormap('summer')
shading interp