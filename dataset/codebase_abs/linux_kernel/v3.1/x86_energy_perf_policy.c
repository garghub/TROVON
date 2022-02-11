void F_1 ( void )
{
printf ( L_1
L_2 ,
V_1 ) ;
exit ( 1 ) ;
}
void F_2 ( int V_2 , char * * V_3 )
{
int V_4 ;
V_1 = V_3 [ 0 ] ;
while ( ( V_4 = F_3 ( V_2 , V_3 , L_3 ) ) != - 1 ) {
switch ( V_4 ) {
case 'c' :
V_5 = atoi ( V_6 ) ;
break;
case 'r' :
V_7 = 1 ;
break;
case 'v' :
V_8 ++ ;
break;
default:
F_1 () ;
}
}
if ( V_7 && ( V_2 > V_9 ) )
F_1 () ;
if ( ! V_7 ) {
if ( V_2 != V_9 + 1 ) {
printf ( L_4 ) ;
F_1 () ;
}
if ( ! strcmp ( L_5 , V_3 [ V_9 ] ) ) {
V_10 = V_11 ;
} else if ( ! strcmp ( L_6 , V_3 [ V_9 ] ) ) {
V_10 = V_12 ;
} else if ( ! strcmp ( L_7 , V_3 [ V_9 ] ) ) {
V_10 = V_13 ;
} else {
char * V_14 ;
V_10 = F_4 ( V_3 [ V_9 ] , & V_14 , 0 ) ;
if ( V_14 == V_3 [ V_9 ] ||
V_10 > V_13 ) {
fprintf ( V_15 , L_8 ,
V_3 [ V_9 ] ) ;
F_1 () ;
}
}
}
}
void F_5 ( void )
{
unsigned int V_16 , V_17 , V_18 , V_19 , V_20 ;
unsigned int V_21 , V_22 , V_23 , V_24 ;
V_16 = V_17 = V_18 = V_19 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx),
"=d" (edx) : "a" (0));
if ( V_17 != 0x756e6547 || V_19 != 0x49656e69 || V_18 != 0x6c65746e ) {
if ( V_8 )
fprintf ( V_15 , L_9 ,
( char * ) & V_17 , ( char * ) & V_19 , ( char * ) & V_18 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_22 = ( V_21 >> 8 ) & 0xf ;
V_23 = ( V_21 >> 4 ) & 0xf ;
V_24 = V_21 & 0xf ;
if ( V_22 == 6 || V_22 == 0xf )
V_23 += ( ( V_21 >> 16 ) & 0xf ) << 4 ;
if ( V_8 > 1 )
printf ( L_10
L_11 , V_20 ,
V_22 , V_23 , V_24 , V_22 , V_23 , V_24 ) ;
if ( ! ( V_19 & ( 1 << 5 ) ) ) {
if ( V_8 )
printf ( L_12 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (6));
if ( V_8 )
printf ( L_13 , V_18 ) ;
if ( ! ( V_18 & ( 1 << 3 ) ) ) {
if ( V_8 )
printf ( L_14 ) ;
exit ( 1 ) ;
}
return;
}
unsigned long long F_6 ( int V_5 , int V_25 )
{
unsigned long long V_26 ;
char V_27 [ 32 ] ;
int V_28 ;
int V_29 ;
sprintf ( V_27 , L_15 , V_5 ) ;
V_29 = F_7 ( V_27 , V_30 ) ;
if ( V_29 < 0 ) {
printf ( L_16 ) ;
perror ( V_27 ) ;
exit ( 1 ) ;
}
V_28 = F_8 ( V_29 , & V_26 , sizeof V_26 , V_25 ) ;
if ( V_28 != sizeof V_26 ) {
printf ( L_17 , V_5 , V_25 , V_28 ) ;
exit ( - 2 ) ;
}
F_9 ( V_29 ) ;
return V_26 ;
}
unsigned long long F_10 ( int V_5 , unsigned long long V_31 , int V_25 )
{
unsigned long long V_32 ;
char V_27 [ 32 ] ;
int V_28 ;
int V_29 ;
sprintf ( V_27 , L_15 , V_5 ) ;
V_29 = F_7 ( V_27 , V_33 ) ;
if ( V_29 < 0 ) {
perror ( V_27 ) ;
exit ( 1 ) ;
}
V_28 = F_8 ( V_29 , & V_32 , sizeof V_32 , V_25 ) ;
if ( V_28 != sizeof V_32 ) {
perror ( L_18 ) ;
printf ( L_17 , V_5 , V_25 , V_28 ) ;
exit ( - 2 ) ;
}
V_28 = F_11 ( V_29 , & V_31 , sizeof V_31 , V_25 ) ;
if ( V_28 != sizeof V_31 ) {
perror ( L_18 ) ;
printf ( L_19 , V_5 , V_25 , V_28 ) ;
exit ( - 2 ) ;
}
F_9 ( V_29 ) ;
return V_32 ;
}
void F_12 ( int V_5 )
{
printf ( L_20 ,
V_5 , F_6 ( V_5 , V_34 ) ) ;
}
void F_13 ( int V_5 )
{
unsigned long long V_35 ;
V_35 = F_10 ( V_5 , V_10 , V_34 ) ;
if ( V_8 )
printf ( L_21 ,
V_5 , V_34 , V_35 , V_10 ) ;
return;
}
void F_14 ( void (F_15)( int ) )
{
T_1 * V_36 ;
int V_28 ;
V_36 = fopen ( V_37 , L_22 ) ;
if ( V_36 == NULL ) {
perror ( V_37 ) ;
exit ( 1 ) ;
}
V_28 = fscanf ( V_36 , L_23 ) ;
if ( V_28 != 0 ) {
perror ( L_24 ) ;
exit ( 1 ) ;
}
while ( 1 ) {
int V_5 ;
V_28 = fscanf ( V_36 ,
L_25 ,
& V_5 ) ;
if ( V_28 != 1 )
return;
F_15 ( V_5 ) ;
}
fclose ( V_36 ) ;
}
int main ( int V_2 , char * * V_3 )
{
F_2 ( V_2 , V_3 ) ;
if ( V_8 > 1 )
printf ( L_26
L_27 ) ;
if ( V_8 > 1 && ! V_7 )
printf ( L_28 , V_10 ) ;
F_5 () ;
if ( V_5 != - 1 ) {
if ( V_7 )
F_12 ( V_5 ) ;
else
F_13 ( V_5 ) ;
} else {
if ( V_7 )
F_14 ( F_12 ) ;
else
F_14 ( F_13 ) ;
}
return 0 ;
}
