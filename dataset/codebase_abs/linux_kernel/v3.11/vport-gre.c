static T_1 F_1 ( T_2 V_1 )
{
#ifdef F_2
return ( V_2 T_1 ) V_1 ;
#else
return ( V_2 T_1 ) ( ( V_2 V_3 ) V_1 >> 32 ) ;
#endif
}
static T_3 F_3 ( T_3 V_4 )
{
return V_4 & ( V_5 | V_6 ) ;
}
static struct V_7 * F_4 ( struct V_7 * V_8 ,
int V_9 )
{
const struct V_10 * V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_12 V_13 ;
V_8 = F_6 ( V_8 , ! ! ( V_11 -> V_14 & V_5 ) ) ;
if ( F_7 ( V_8 ) )
return NULL ;
V_13 . V_4 = F_3 ( V_11 -> V_14 ) ;
V_13 . V_15 = F_8 ( V_16 ) ;
V_13 . V_17 = F_1 ( V_11 -> V_18 ) ;
V_13 . V_19 = 0 ;
F_9 ( V_8 , & V_13 , V_9 ) ;
return V_8 ;
}
static T_2 F_10 ( T_1 V_17 , T_1 V_19 )
{
#ifdef F_2
return ( V_2 T_2 ) ( ( V_2 V_3 ) V_19 << 32 | ( V_2 V_20 ) V_17 ) ;
#else
return ( V_2 T_2 ) ( ( V_2 V_3 ) V_17 << 32 | ( V_2 V_20 ) V_19 ) ;
#endif
}
static int F_11 ( struct V_7 * V_8 ,
const struct V_12 * V_13 )
{
struct V_10 V_11 ;
struct V_21 * V_21 ;
struct V_22 * V_22 ;
T_2 V_17 ;
V_21 = F_12 ( F_13 ( V_8 -> V_23 ) , V_24 ) ;
V_22 = F_14 ( V_21 -> V_25 . V_26 ) ;
if ( F_15 ( ! V_22 ) )
return V_27 ;
V_17 = F_10 ( V_13 -> V_17 , V_13 -> V_19 ) ;
F_16 ( & V_11 , F_17 ( V_8 ) , V_17 ,
F_3 ( V_13 -> V_4 ) ) ;
F_18 ( V_22 , V_8 , & V_11 ) ;
return V_28 ;
}
static int F_19 ( struct V_22 * V_22 , struct V_7 * V_8 )
{
struct V_29 * V_29 = F_20 ( V_22 -> V_30 ) ;
struct V_31 V_32 ;
struct V_33 * V_34 ;
int V_35 ;
int V_9 ;
T_3 V_36 ;
int V_37 ;
if ( F_15 ( ! F_5 ( V_8 ) -> V_11 ) ) {
V_37 = - V_38 ;
goto error;
}
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_39 = F_5 ( V_8 ) -> V_11 -> V_40 ;
V_32 . V_41 = F_5 ( V_8 ) -> V_11 -> V_42 ;
V_32 . V_43 = F_21 ( F_5 ( V_8 ) -> V_11 -> V_44 ) ;
V_32 . V_45 = V_8 -> V_46 ;
V_32 . V_47 = V_48 ;
V_34 = F_22 ( V_29 , & V_32 ) ;
if ( F_7 ( V_34 ) )
return F_23 ( V_34 ) ;
V_9 = F_24 ( F_5 ( V_8 ) -> V_11 -> V_14 ) ;
V_35 = F_25 ( V_34 -> V_49 . V_23 ) + V_34 -> V_49 . V_50
+ V_9 + sizeof( struct V_51 )
+ ( F_26 ( V_8 ) ? V_52 : 0 ) ;
if ( F_27 ( V_8 ) < V_35 || F_28 ( V_8 ) ) {
int V_53 = F_29 ( V_35 -
F_27 ( V_8 ) +
16 ) ;
V_37 = F_30 ( V_8 , F_31 ( int , V_53 , 0 ) ,
0 , V_54 ) ;
if ( F_15 ( V_37 ) )
goto V_55;
}
if ( F_26 ( V_8 ) ) {
if ( F_15 ( ! F_32 ( V_8 ,
V_8 -> V_56 ,
F_33 ( V_8 ) ) ) ) {
V_37 = - V_57 ;
goto V_55;
}
V_8 -> V_58 = 0 ;
}
V_8 = F_4 ( V_8 , V_9 ) ;
if ( F_15 ( ! V_8 ) ) {
V_37 = 0 ;
goto V_55;
}
V_36 = F_5 ( V_8 ) -> V_11 -> V_14 & V_59 ?
F_8 ( V_60 ) : 0 ;
V_8 -> V_61 = 1 ;
return F_34 ( V_29 , V_34 , V_8 , V_32 . V_41 ,
F_5 ( V_8 ) -> V_11 -> V_40 , V_48 ,
F_5 ( V_8 ) -> V_11 -> V_44 ,
F_5 ( V_8 ) -> V_11 -> V_62 , V_36 ) ;
V_55:
F_35 ( V_34 ) ;
error:
return V_37 ;
}
static int F_36 ( void )
{
int V_37 ;
V_63 ++ ;
if ( V_63 > 1 )
return 0 ;
V_37 = F_37 ( & V_64 ) ;
if ( V_37 )
F_38 ( L_1 ) ;
return V_37 ;
}
static void F_39 ( void )
{
V_63 -- ;
if ( V_63 > 0 )
return;
F_40 ( & V_64 ) ;
}
static const char * F_41 ( const struct V_22 * V_22 )
{
return F_42 ( V_22 ) ;
}
static struct V_22 * F_43 ( const struct V_65 * V_66 )
{
struct V_29 * V_29 = F_20 ( V_66 -> V_30 ) ;
struct V_21 * V_21 ;
struct V_22 * V_22 ;
int V_37 ;
V_37 = F_36 () ;
if ( V_37 )
return F_44 ( V_37 ) ;
V_21 = F_12 ( V_29 , V_24 ) ;
if ( F_45 ( V_21 -> V_25 . V_26 ) ) {
V_22 = F_44 ( - V_67 ) ;
goto error;
}
V_22 = F_46 ( V_68 , & V_69 , V_66 ) ;
if ( F_7 ( V_22 ) )
goto error;
strncpy ( F_42 ( V_22 ) , V_66 -> V_70 , V_68 ) ;
F_47 ( V_21 -> V_25 . V_26 , V_22 ) ;
return V_22 ;
error:
F_39 () ;
return V_22 ;
}
static void F_48 ( struct V_22 * V_22 )
{
struct V_29 * V_29 = F_20 ( V_22 -> V_30 ) ;
struct V_21 * V_21 ;
V_21 = F_12 ( V_29 , V_24 ) ;
F_47 ( V_21 -> V_25 . V_26 , NULL ) ;
F_49 ( V_22 ) ;
F_39 () ;
}
