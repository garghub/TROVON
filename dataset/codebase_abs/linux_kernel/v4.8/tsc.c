int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_5 ;
T_1 V_6 ;
int V_7 = 0 ;
while ( 1 ) {
V_6 = V_2 -> V_8 ;
F_2 () ;
V_4 -> V_9 = V_2 -> V_9 ;
V_4 -> V_10 = V_2 -> V_10 ;
V_4 -> V_11 = V_2 -> V_11 ;
V_5 = V_2 -> V_5 ;
F_2 () ;
if ( V_2 -> V_8 == V_6 && ! ( V_6 & 1 ) )
break;
if ( ++ V_7 > 10000 ) {
F_3 ( L_1 ) ;
return - V_12 ;
}
}
if ( ! V_5 )
return - V_13 ;
return 0 ;
}
T_2 F_4 ( void )
{
unsigned int V_14 , V_15 ;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return V_14 | ( ( T_2 ) V_15 ) << 32 ;
}
int F_5 ( const struct V_1 * V_2 ,
struct V_16 * V_17 ,
T_3 V_18 ,
struct V_19 * V_19 )
{
union V_20 V_21 = {
. V_22 = {
. V_23 = {
. type = V_24 ,
. V_25 = sizeof( struct V_26 ) ,
} ,
} ,
} ;
struct V_3 V_4 ;
int V_27 ;
if ( ! V_2 )
return 0 ;
V_27 = F_1 ( V_2 , & V_4 ) ;
if ( V_27 == - V_13 )
return 0 ;
if ( V_27 )
return V_27 ;
F_6 ( L_2 ) ;
V_21 . V_22 . V_9 = V_4 . V_9 ;
V_21 . V_22 . V_10 = V_4 . V_10 ;
V_21 . V_22 . V_11 = V_4 . V_11 ;
return V_18 ( V_17 , & V_21 , NULL , V_19 ) ;
}
