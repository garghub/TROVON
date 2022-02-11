static void F_1 ( void )
{
#ifndef F_2
F_3 () ;
#endif
}
static void F_4 ( void )
{
#ifndef F_2
F_5 () ;
#endif
}
static T_1 F_6 ( void T_2 * V_1 , unsigned int V_2 )
{
return F_7 ( V_1 + V_2 ) ;
}
static void F_8 ( T_1 V_3 , void T_2 * V_1 , unsigned int V_2 )
{
return F_9 ( V_3 , V_1 + V_2 ) ;
}
static int F_10 ( struct V_4 * V_5 , int V_6 )
{
struct V_7 * V_8 = F_11 ( V_5 , struct V_7 , V_5 ) ;
int V_9 ;
if ( V_8 -> V_10 )
return V_8 -> V_10 ;
for ( V_9 = 0 ; V_9 < 20 ; V_9 ++ ) {
F_1 () ;
if ( ! ( F_6 ( V_8 -> V_1 , V_11 )
& V_12 ) ) {
V_8 -> V_13 [ 0 ] =
F_6 ( V_8 -> V_1 , F_12 ( 0 ) ) ;
V_8 -> V_13 [ 1 ] =
F_6 ( V_8 -> V_1 , F_12 ( 1 ) ) ;
V_8 -> V_13 [ 2 ] =
F_6 ( V_8 -> V_1 , F_12 ( 2 ) ) ;
V_8 -> V_10 =
sizeof( V_8 -> V_13 ) / sizeof( V_14 ) ;
F_8 ( V_12 ,
V_8 -> V_1 , V_11 ) ;
V_6 = 0 ;
}
F_4 () ;
if ( ! V_6 )
break;
F_13 ( 90 * 5 ) ;
}
return V_8 -> V_10 ;
}
static int F_14 ( struct V_4 * V_5 , V_14 * V_15 )
{
struct V_7 * V_8 = F_11 ( V_5 , struct V_7 , V_5 ) ;
V_8 -> V_10 -- ;
* V_15 = * ( ( V_14 * ) & V_8 -> V_13 + V_8 -> V_10 ) ;
return sizeof( V_14 ) ;
}
static int T_3 F_15 ( struct V_16 * V_17 )
{
struct V_7 * V_8 ;
struct V_18 * V_19 ;
int V_9 ;
V_8 = F_16 ( & V_17 -> V_17 , sizeof( * V_8 ) , V_20 ) ;
if ( ! V_8 )
return - V_21 ;
V_19 = F_17 ( V_17 , V_22 , 0 ) ;
V_8 -> V_1 = F_18 ( & V_17 -> V_17 , V_19 ) ;
if ( F_19 ( V_8 -> V_1 ) )
return F_20 ( V_8 -> V_1 ) ;
V_8 -> V_5 . V_23 = F_21 ( & V_17 -> V_17 ) ;
V_8 -> V_5 . V_24 = F_10 ;
V_8 -> V_5 . V_25 = F_14 ;
F_1 () ;
F_8 ( V_26 , V_8 -> V_1 , V_11 ) ;
F_8 ( 0 , V_8 -> V_1 , V_11 ) ;
F_8 ( V_12 , V_8 -> V_1 , V_11 ) ;
F_4 () ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_8 -> V_10 = 0 ;
if ( ! F_10 ( & V_8 -> V_5 , 1 ) )
return - V_27 ;
}
F_22 ( V_17 , V_8 ) ;
return F_23 ( & V_17 -> V_17 , & V_8 -> V_5 ) ;
}
