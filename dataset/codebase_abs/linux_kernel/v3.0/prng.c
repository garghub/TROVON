static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
static void F_3 ( void )
{
T_1 V_3 [ 4 ] ;
unsigned int V_4 ;
int V_5 ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
V_5 = F_4 ( V_6 , V_7 , ( char * ) V_3 ,
( char * ) V_3 , sizeof( V_3 ) ) ;
F_5 ( V_5 < 0 || V_5 != sizeof( V_3 ) ) ;
memcpy ( V_7 , V_3 , sizeof( V_3 ) ) ;
}
}
static void F_6 ( int V_8 )
{
char V_9 [ 16 ] ;
int V_4 = 0 ;
F_5 ( V_8 > 16 ) ;
F_7 ( V_9 , V_8 ) ;
while ( V_8 >= 8 ) {
* ( ( T_1 * ) V_7 ) ^= * ( ( T_1 * ) ( V_9 + V_4 ) ) ;
F_3 () ;
V_4 += 8 ;
V_8 -= 8 ;
}
F_3 () ;
}
static T_2 F_8 ( struct V_2 * V_2 , char T_3 * V_10 , T_4 V_8 ,
T_5 * V_11 )
{
int V_12 , V_13 ;
int V_5 = 0 ;
int V_14 ;
while ( V_8 ) {
if ( F_9 () ) {
if ( F_10 ( V_15 ) ) {
if ( V_5 == 0 )
V_5 = - V_16 ;
break;
}
F_11 () ;
}
V_12 = F_12 ( int , V_8 , V_17 ) ;
V_13 = ( V_12 + 7 ) & - 8 ;
if ( V_18 -> V_19 > V_20 )
F_6 ( 8 ) ;
asm volatile(".insn s,0xb27c0000,%0"
: "=m" (*((unsigned long long *)p->buf)) : : "cc");
V_14 = F_4 ( V_6 , V_7 , V_18 -> V_9 , V_18 -> V_9 , V_13 ) ;
F_5 ( ( V_14 < 0 ) || ( V_14 != V_13 ) ) ;
V_18 -> V_19 += V_13 ;
if ( F_13 ( V_10 , V_18 -> V_9 , V_12 ) )
return - V_21 ;
V_8 -= V_12 ;
V_5 += V_12 ;
V_10 += V_12 ;
}
return V_5 ;
}
static int T_6 F_14 ( void )
{
int V_5 ;
if ( ! F_15 ( V_6 , V_22 ) )
return - V_23 ;
if ( V_17 < 8 )
return - V_24 ;
V_18 = F_16 ( sizeof( struct V_25 ) , V_26 ) ;
if ( ! V_18 )
return - V_27 ;
V_18 -> V_19 = 0 ;
V_18 -> V_9 = F_16 ( V_17 , V_26 ) ;
if ( ! V_18 -> V_9 ) {
V_5 = - V_27 ;
goto V_28;
}
F_6 ( 16 ) ;
V_5 = F_17 ( & V_29 ) ;
if ( V_5 )
goto V_30;
return 0 ;
V_30:
F_18 ( V_18 -> V_9 ) ;
V_28:
F_18 ( V_18 ) ;
return V_5 ;
}
static void T_7 F_19 ( void )
{
F_20 ( V_18 -> V_9 ) ;
F_18 ( V_18 ) ;
F_21 ( & V_29 ) ;
}
