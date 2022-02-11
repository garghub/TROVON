static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( & V_2 -> V_3 ) ) {
struct V_4 * V_5 ;
V_5 = F_3 ( V_2 -> V_3 . V_6 , struct V_4 ,
V_3 ) ;
V_5 -> V_7 ( V_2 ) ;
}
}
int F_4 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 1 ;
F_5 ( F_6 ( & V_2 -> V_8 ) == 0 ) ;
if ( F_7 ( & V_2 -> V_8 ) ) {
F_8 () ;
F_1 ( V_2 ) ;
F_9 () ;
F_10 ( V_9 , V_2 ) ;
return 1 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_8 () ;
if ( ! F_2 ( & V_2 -> V_3 ) ) {
struct V_4 * V_5 ;
V_5 = F_3 ( V_2 -> V_3 . V_6 , struct V_4 ,
V_3 ) ;
V_5 -> exit ( V_2 ) ;
}
F_9 () ;
}
void F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
F_13 ( V_11 ) ;
V_2 = V_11 -> V_1 ;
V_11 -> V_1 = NULL ;
F_14 ( V_11 ) ;
if ( F_15 ( & V_2 -> V_12 ) )
F_11 ( V_2 ) ;
F_4 ( V_2 ) ;
}
struct V_1 * F_16 ( T_1 V_13 , int V_14 )
{
struct V_1 * V_15 ;
V_15 = F_17 ( V_9 , V_13 , V_14 ) ;
if ( V_15 ) {
F_18 ( & V_15 -> V_8 , 1 ) ;
F_19 ( & V_15 -> V_12 , 1 ) ;
F_20 ( & V_15 -> V_16 ) ;
V_15 -> V_17 = 0 ;
V_15 -> V_18 = 0 ;
V_15 -> V_19 = 0 ;
V_15 -> V_20 = 0 ;
F_21 ( & V_15 -> V_21 , V_22 | V_23 ) ;
F_22 ( & V_15 -> V_3 ) ;
V_15 -> V_24 = NULL ;
#if F_23 ( V_25 ) || F_23 ( V_26 )
V_15 -> V_27 = 0 ;
#endif
}
return V_15 ;
}
struct V_1 * F_24 ( T_1 V_13 , int V_14 )
{
struct V_10 * V_28 = V_29 ;
struct V_1 * V_15 ;
V_15 = V_28 -> V_1 ;
if ( F_25 ( V_15 ) )
return V_15 ;
V_15 = F_16 ( V_13 , V_14 ) ;
if ( V_15 ) {
F_26 () ;
V_28 -> V_1 = V_15 ;
}
return V_15 ;
}
struct V_1 * F_27 ( T_1 V_13 , int V_14 )
{
struct V_1 * V_15 = NULL ;
do {
V_15 = F_24 ( V_13 , V_14 ) ;
if ( F_28 ( ! V_15 ) )
break;
} while ( ! F_29 ( & V_15 -> V_8 ) );
return V_15 ;
}
static int T_2 F_30 ( void )
{
V_9 = F_31 ( L_1 ,
sizeof( struct V_1 ) , 0 , V_30 , NULL ) ;
return 0 ;
}
