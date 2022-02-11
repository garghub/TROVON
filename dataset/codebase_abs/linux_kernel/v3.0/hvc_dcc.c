static inline T_1 F_1 ( void )
{
T_1 V_1 ;
asm volatile("mrc p14, 0, %0, c0, c1, 0 @ read comms ctrl reg"
: "=r" (__ret) : : "cc");
return V_1 ;
}
static inline char F_2 ( void )
{
char V_2 ;
asm volatile("mrc p14, 0, %0, c0, c5, 0 @ read comms data reg"
: "=r" (__c));
return V_2 ;
}
static inline void F_3 ( char V_3 )
{
asm volatile("mcr p14, 0, %0, c0, c5, 0 @ write a char"
:
: "r" (c));
}
static int F_4 ( T_2 V_4 , const char * V_5 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
while ( F_1 () & V_8 )
F_5 () ;
F_3 ( V_5 [ V_7 ] ) ;
}
return V_6 ;
}
static int F_6 ( T_2 V_4 , char * V_5 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; ++ V_7 )
if ( F_1 () & V_9 )
V_5 [ V_7 ] = F_2 () ;
else
break;
return V_7 ;
}
static int T_3 F_7 ( void )
{
F_8 ( 0 , 0 , & V_10 ) ;
return 0 ;
}
static int T_3 F_9 ( void )
{
F_10 ( 0 , 0 , & V_10 , 128 ) ;
return 0 ;
}
