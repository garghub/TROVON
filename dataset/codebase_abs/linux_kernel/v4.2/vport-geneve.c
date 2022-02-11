static inline struct V_1 * F_1 ( const struct V_2 * V_2 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( T_1 V_3 , T_2 * V_4 )
{
#ifdef F_4
V_4 [ 0 ] = ( V_5 T_2 ) ( V_3 >> 16 ) ;
V_4 [ 1 ] = ( V_5 T_2 ) ( V_3 >> 8 ) ;
V_4 [ 2 ] = ( V_5 T_2 ) V_3 ;
#else
V_4 [ 0 ] = ( V_5 T_2 ) ( ( V_5 V_6 ) V_3 >> 40 ) ;
V_4 [ 1 ] = ( V_5 T_2 ) ( ( V_5 V_6 ) V_3 >> 48 ) ;
V_4 [ 2 ] = ( V_5 T_2 ) ( ( V_5 V_6 ) V_3 >> 56 ) ;
#endif
}
static T_1 F_5 ( const T_2 * V_4 )
{
#ifdef F_4
return ( V_4 [ 0 ] << 16 ) | ( V_4 [ 1 ] << 8 ) | V_4 [ 2 ] ;
#else
return ( V_5 T_1 ) ( ( ( V_5 V_6 ) V_4 [ 0 ] << 40 ) |
( ( V_5 V_6 ) V_4 [ 1 ] << 48 ) |
( ( V_5 V_6 ) V_4 [ 2 ] << 56 ) ) ;
#endif
}
static void F_6 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_2 * V_2 = V_8 -> V_11 ;
struct V_12 * V_13 = F_7 ( V_10 ) ;
int V_14 ;
struct V_15 V_16 ;
T_1 V_17 ;
T_3 V_18 ;
V_14 = V_13 -> V_19 * 4 ;
V_18 = V_20 | V_21 |
( F_8 ( V_10 ) -> V_22 != 0 ? V_23 : 0 ) |
( V_13 -> V_24 ? V_25 : 0 ) |
( V_13 -> V_26 ? V_27 : 0 ) ;
V_17 = F_5 ( V_13 -> V_4 ) ;
F_9 ( & V_16 , F_10 ( V_10 ) ,
F_8 ( V_10 ) -> V_28 , F_8 ( V_10 ) -> V_29 ,
V_17 , V_18 ,
V_13 -> V_30 , V_14 ) ;
F_11 ( V_2 , V_10 , & V_16 ) ;
}
static int F_12 ( const struct V_2 * V_2 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_31 * V_32 = F_13 ( V_1 -> V_8 -> V_33 -> V_32 ) ;
if ( F_14 ( V_10 , V_34 , F_15 ( V_32 -> V_35 ) ) )
return - V_36 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_17 ( V_1 -> V_8 ) ;
F_18 ( V_2 ) ;
}
static struct V_2 * F_19 ( const struct V_37 * V_38 )
{
struct V_39 * V_39 = F_20 ( V_38 -> V_40 ) ;
struct V_41 * V_30 = V_38 -> V_30 ;
struct V_1 * V_1 ;
struct V_7 * V_8 ;
struct V_2 * V_2 ;
struct V_41 * V_42 ;
int V_43 ;
T_4 V_44 ;
if ( ! V_30 ) {
V_43 = - V_45 ;
goto error;
}
V_42 = F_21 ( V_30 , V_34 ) ;
if ( V_42 && F_22 ( V_42 ) == sizeof( T_4 ) ) {
V_44 = F_23 ( V_42 ) ;
} else {
V_43 = - V_45 ;
goto error;
}
V_2 = F_24 ( sizeof( struct V_1 ) ,
& V_46 , V_38 ) ;
if ( F_25 ( V_2 ) )
return V_2 ;
V_1 = F_1 ( V_2 ) ;
strncpy ( V_1 -> V_47 , V_38 -> V_47 , V_48 ) ;
V_8 = F_26 ( V_39 , F_27 ( V_44 ) , F_6 , V_2 , true , 0 ) ;
if ( F_25 ( V_8 ) ) {
F_28 ( V_2 ) ;
return ( void * ) V_8 ;
}
V_1 -> V_8 = V_8 ;
return V_2 ;
error:
return F_29 ( V_43 ) ;
}
static int F_30 ( struct V_2 * V_2 , struct V_9 * V_10 )
{
const struct V_49 * V_50 ;
struct V_15 * V_16 ;
struct V_39 * V_39 = F_20 ( V_2 -> V_40 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_3 V_51 = F_13 ( V_1 -> V_8 -> V_33 -> V_32 ) -> V_35 ;
T_3 V_52 ;
struct V_53 * V_54 ;
struct V_55 V_56 ;
T_5 V_4 [ 3 ] , V_14 , * V_57 ;
T_3 V_58 ;
int V_43 ;
V_16 = F_31 ( V_10 ) -> V_59 ;
if ( F_32 ( ! V_16 ) ) {
V_43 = - V_45 ;
goto error;
}
V_50 = & V_16 -> V_60 ;
V_54 = F_33 ( V_39 , V_50 , V_10 -> V_61 , & V_56 , V_62 ) ;
if ( F_25 ( V_54 ) ) {
V_43 = F_34 ( V_54 ) ;
goto error;
}
V_58 = V_50 -> V_63 & V_64 ? F_27 ( V_65 ) : 0 ;
V_52 = F_35 ( V_39 , V_10 , 1 , V_66 , true ) ;
F_3 ( V_50 -> V_3 , V_4 ) ;
V_10 -> V_67 = 1 ;
if ( V_50 -> V_63 & V_21 ) {
V_57 = ( T_5 * ) V_16 -> V_30 ;
V_14 = V_16 -> V_68 ;
} else {
V_57 = NULL ;
V_14 = 0 ;
}
V_43 = F_36 ( V_1 -> V_8 , V_54 , V_10 , V_56 . V_69 ,
V_50 -> V_70 , V_50 -> V_71 ,
V_50 -> V_72 , V_58 , V_52 , V_51 ,
V_50 -> V_63 , V_4 , V_14 , V_57 ,
! ! ( V_50 -> V_63 & V_23 ) , false ) ;
if ( V_43 < 0 )
F_37 ( V_54 ) ;
return V_43 ;
error:
F_38 ( V_10 ) ;
return V_43 ;
}
static const char * F_39 ( const struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
return V_1 -> V_47 ;
}
static int F_40 ( struct V_2 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_59 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_39 * V_39 = F_20 ( V_2 -> V_40 ) ;
T_3 V_51 = F_13 ( V_1 -> V_8 -> V_33 -> V_32 ) -> V_35 ;
T_3 V_52 = F_35 ( V_39 , V_10 , 1 , V_66 , true ) ;
return F_41 ( V_59 ,
F_20 ( V_2 -> V_40 ) ,
F_31 ( V_10 ) -> V_59 ,
V_62 , V_10 -> V_61 , V_52 , V_51 ) ;
}
static int T_6 F_42 ( void )
{
return F_43 ( & V_46 ) ;
}
static void T_7 F_44 ( void )
{
F_45 ( & V_46 ) ;
}
