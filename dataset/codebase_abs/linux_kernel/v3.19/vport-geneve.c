static inline struct V_1 * F_1 ( const struct V_2 * V_2 )
{
return F_2 ( V_2 ) ;
}
static inline struct V_3 * F_3 ( const struct V_4 * V_5 )
{
return (struct V_3 * ) ( F_4 ( V_5 ) + 1 ) ;
}
static void F_5 ( T_1 V_6 , T_2 * V_7 )
{
#ifdef F_6
V_7 [ 0 ] = ( V_8 T_2 ) ( V_6 >> 16 ) ;
V_7 [ 1 ] = ( V_8 T_2 ) ( V_6 >> 8 ) ;
V_7 [ 2 ] = ( V_8 T_2 ) V_6 ;
#else
V_7 [ 0 ] = ( V_8 T_2 ) ( ( V_8 V_9 ) V_6 >> 40 ) ;
V_7 [ 1 ] = ( V_8 T_2 ) ( ( V_8 V_9 ) V_6 >> 48 ) ;
V_7 [ 2 ] = ( V_8 T_2 ) ( ( V_8 V_9 ) V_6 >> 56 ) ;
#endif
}
static T_1 F_7 ( const T_2 * V_7 )
{
#ifdef F_6
return ( V_7 [ 0 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | V_7 [ 2 ] ;
#else
return ( V_8 T_1 ) ( ( ( V_8 V_9 ) V_7 [ 0 ] << 40 ) |
( ( V_8 V_9 ) V_7 [ 1 ] << 48 ) |
( ( V_8 V_9 ) V_7 [ 2 ] << 56 ) ) ;
#endif
}
static void F_8 ( struct V_10 * V_11 , struct V_4 * V_5 )
{
struct V_2 * V_2 = V_11 -> V_12 ;
struct V_3 * V_13 = F_3 ( V_5 ) ;
int V_14 ;
struct V_15 V_16 ;
T_1 V_17 ;
T_3 V_18 ;
V_14 = V_13 -> V_19 * 4 ;
V_18 = V_20 | V_21 |
( F_4 ( V_5 ) -> V_22 != 0 ? V_23 : 0 ) |
( V_13 -> V_24 ? V_25 : 0 ) |
( V_13 -> V_26 ? V_27 : 0 ) ;
V_17 = F_7 ( V_13 -> V_7 ) ;
F_9 ( & V_16 , F_10 ( V_5 ) ,
F_4 ( V_5 ) -> V_28 , F_4 ( V_5 ) -> V_29 ,
V_17 , V_18 ,
V_13 -> V_30 , V_14 ) ;
F_11 ( V_2 , V_5 , & V_16 ) ;
}
static int F_12 ( const struct V_2 * V_2 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_31 * V_32 = F_13 ( V_1 -> V_11 -> V_33 -> V_32 ) ;
if ( F_14 ( V_5 , V_34 , F_15 ( V_32 -> V_35 ) ) )
return - V_36 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_17 ( V_1 -> V_11 ) ;
F_18 ( V_2 ) ;
}
static struct V_2 * F_19 ( const struct V_37 * V_38 )
{
struct V_39 * V_39 = F_20 ( V_38 -> V_40 ) ;
struct V_41 * V_30 = V_38 -> V_30 ;
struct V_1 * V_1 ;
struct V_10 * V_11 ;
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
V_11 = F_26 ( V_39 , F_27 ( V_44 ) , F_8 , V_2 , true , 0 ) ;
if ( F_25 ( V_11 ) ) {
F_28 ( V_2 ) ;
return ( void * ) V_11 ;
}
V_1 -> V_11 = V_11 ;
return V_2 ;
error:
return F_29 ( V_43 ) ;
}
static int F_30 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
struct V_49 * V_50 ;
struct V_15 * V_16 ;
struct V_39 * V_39 = F_20 ( V_2 -> V_40 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_3 V_51 = F_13 ( V_1 -> V_11 -> V_33 -> V_32 ) -> V_35 ;
T_3 V_52 ;
struct V_53 * V_54 ;
struct V_55 V_56 ;
T_5 V_7 [ 3 ] ;
T_3 V_57 ;
int V_43 ;
V_16 = F_31 ( V_5 ) -> V_58 ;
if ( F_32 ( ! V_16 ) ) {
V_43 = - V_45 ;
goto error;
}
V_50 = & V_16 -> V_59 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_60 = V_50 -> V_61 ;
V_56 . V_62 = V_50 -> V_63 ;
V_56 . V_64 = F_33 ( V_50 -> V_65 ) ;
V_56 . V_66 = V_5 -> V_67 ;
V_56 . V_68 = V_69 ;
V_54 = F_34 ( V_39 , & V_56 ) ;
if ( F_25 ( V_54 ) ) {
V_43 = F_35 ( V_54 ) ;
goto error;
}
V_57 = V_50 -> V_70 & V_71 ? F_27 ( V_72 ) : 0 ;
V_52 = F_36 ( V_39 , V_5 , 1 , V_73 , true ) ;
F_5 ( V_50 -> V_6 , V_7 ) ;
V_5 -> V_74 = 1 ;
V_43 = F_37 ( V_1 -> V_11 , V_54 , V_5 , V_56 . V_62 ,
V_50 -> V_61 , V_50 -> V_65 ,
V_50 -> V_75 , V_57 , V_52 , V_51 ,
V_50 -> V_70 , V_7 ,
V_16 -> V_76 , ( T_5 * ) V_16 -> V_30 ,
false ) ;
if ( V_43 < 0 )
F_38 ( V_54 ) ;
return V_43 ;
error:
F_39 ( V_5 ) ;
return V_43 ;
}
static const char * F_40 ( const struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
return V_1 -> V_47 ;
}
static int F_41 ( struct V_2 * V_2 , struct V_4 * V_5 ,
struct V_15 * V_58 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_39 * V_39 = F_20 ( V_2 -> V_40 ) ;
T_3 V_51 = F_13 ( V_1 -> V_11 -> V_33 -> V_32 ) -> V_35 ;
T_3 V_52 = F_36 ( V_39 , V_5 , 1 , V_73 , true ) ;
return F_42 ( V_58 ,
F_20 ( V_2 -> V_40 ) ,
F_31 ( V_5 ) -> V_58 ,
V_69 , V_5 -> V_67 , V_52 , V_51 ) ;
}
static int T_6 F_43 ( void )
{
return F_44 ( & V_46 ) ;
}
static void T_7 F_45 ( void )
{
F_46 ( & V_46 ) ;
}
