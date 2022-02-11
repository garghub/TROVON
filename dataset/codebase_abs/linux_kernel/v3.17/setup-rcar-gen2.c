T_1 F_1 ( void )
{
static T_1 V_1 ;
static bool V_2 ;
if ( ! V_2 ) {
void T_2 * V_3 = F_2 ( V_4 , 4 ) ;
F_3 ( ! V_3 ) ;
V_1 = F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
V_2 = true ;
}
return V_1 ;
}
void T_3 F_6 ( void )
{
#if F_7 ( V_5 ) || F_7 ( V_6 )
T_1 V_1 = F_1 () ;
#endif
#ifdef V_5
void T_2 * V_7 ;
int V_8 = 0 ;
T_1 V_9 ;
switch ( V_1 & ( F_8 ( 14 ) | F_8 ( 13 ) ) ) {
case 0 :
V_8 = 15 ;
break;
case F_8 ( 13 ) :
V_8 = 20 ;
break;
case F_8 ( 14 ) :
V_8 = 26 ;
break;
case F_8 ( 13 ) | F_8 ( 14 ) :
V_8 = 30 ;
break;
}
V_9 = V_8 * ( 1000000 / 2 ) ;
V_7 = F_9 ( 0xe6080000 , V_10 ) ;
if ( ( F_4 ( V_7 + V_11 ) & 1 ) == 0 ||
F_4 ( V_7 + V_12 ) != V_9 ) {
F_10 ( V_9 , V_7 + V_12 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_10 ( 1 , V_7 + V_11 ) ;
}
F_5 ( V_7 ) ;
#endif
#ifdef V_6
F_11 ( V_1 ) ;
#endif
F_12 () ;
}
static int T_3 F_13 ( unsigned long V_13 , const char * V_14 ,
int V_15 , void * V_16 )
{
const char * type = F_14 ( V_13 , L_1 , NULL ) ;
const T_4 * V_17 , * V_18 ;
int V_19 ;
struct V_20 * V_21 = V_16 ;
T_5 V_22 = 1ULL << 32 ;
if ( type == NULL || strcmp ( type , L_2 ) )
return 0 ;
V_17 = F_14 ( V_13 , L_3 , & V_19 ) ;
if ( V_17 == NULL )
V_17 = F_14 ( V_13 , L_4 , & V_19 ) ;
if ( V_17 == NULL )
return 0 ;
V_18 = V_17 + ( V_19 / sizeof( T_4 ) ) ;
while ( ( V_18 - V_17 ) >= ( V_23 + V_24 ) ) {
T_5 V_7 , V_25 ;
V_7 = F_15 ( V_23 , & V_17 ) ;
V_25 = F_15 ( V_24 , & V_17 ) ;
if ( V_7 >= V_22 )
continue;
if ( ( V_7 + V_25 ) >= V_22 )
V_25 = V_22 - V_7 ;
if ( V_25 < V_21 -> V_26 )
continue;
if ( V_7 < V_21 -> V_7 )
continue;
V_21 -> V_7 = V_7 + V_25 - V_21 -> V_26 ;
V_21 -> V_25 = V_21 -> V_26 ;
}
return 0 ;
}
void T_3 F_16 ( void )
{
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_26 = V_27 ;
F_17 ( F_13 , & V_21 ) ;
#ifdef F_18
if ( V_21 . V_25 )
F_19 ( V_21 . V_25 , V_21 . V_7 , 0 ,
& V_28 , true ) ;
#endif
}
