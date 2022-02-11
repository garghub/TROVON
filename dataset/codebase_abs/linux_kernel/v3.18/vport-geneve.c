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
static T_1 F_7 ( T_2 * V_7 )
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
F_9 ( & V_16 , F_10 ( V_5 ) , V_17 , V_18 ,
V_13 -> V_28 , V_14 ) ;
F_11 ( V_2 , V_5 , & V_16 ) ;
}
static int F_12 ( const struct V_2 * V_2 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_29 * V_30 = F_13 ( V_1 -> V_11 -> V_31 -> V_30 ) ;
if ( F_14 ( V_5 , V_32 , F_15 ( V_30 -> V_33 ) ) )
return - V_34 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_17 ( V_1 -> V_11 ) ;
F_18 ( V_2 ) ;
}
static struct V_2 * F_19 ( const struct V_35 * V_36 )
{
struct V_37 * V_37 = F_20 ( V_36 -> V_38 ) ;
struct V_39 * V_28 = V_36 -> V_28 ;
struct V_1 * V_1 ;
struct V_10 * V_11 ;
struct V_2 * V_2 ;
struct V_39 * V_40 ;
int V_41 ;
T_4 V_42 ;
if ( ! V_28 ) {
V_41 = - V_43 ;
goto error;
}
V_40 = F_21 ( V_28 , V_32 ) ;
if ( V_40 && F_22 ( V_40 ) == sizeof( T_4 ) ) {
V_42 = F_23 ( V_40 ) ;
} else {
V_41 = - V_43 ;
goto error;
}
V_2 = F_24 ( sizeof( struct V_1 ) ,
& V_44 , V_36 ) ;
if ( F_25 ( V_2 ) )
return V_2 ;
V_1 = F_1 ( V_2 ) ;
strncpy ( V_1 -> V_45 , V_36 -> V_45 , V_46 ) ;
V_11 = F_26 ( V_37 , F_27 ( V_42 ) , F_8 , V_2 , true , 0 ) ;
if ( F_25 ( V_11 ) ) {
F_28 ( V_2 ) ;
return ( void * ) V_11 ;
}
V_1 -> V_11 = V_11 ;
return V_2 ;
error:
return F_29 ( V_41 ) ;
}
static int F_30 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
struct V_47 * V_48 ;
struct V_15 * V_16 ;
struct V_37 * V_37 = F_20 ( V_2 -> V_38 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_3 V_49 = F_13 ( V_1 -> V_11 -> V_31 -> V_30 ) -> V_33 ;
T_3 V_50 ;
struct V_51 * V_52 ;
struct V_53 V_54 ;
T_5 V_7 [ 3 ] ;
T_3 V_55 ;
int V_41 ;
V_16 = F_31 ( V_5 ) -> V_56 ;
if ( F_32 ( ! V_16 ) ) {
V_41 = - V_43 ;
goto error;
}
V_48 = & V_16 -> V_57 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_58 = V_48 -> V_59 ;
V_54 . V_60 = V_48 -> V_61 ;
V_54 . V_62 = F_33 ( V_48 -> V_63 ) ;
V_54 . V_64 = V_5 -> V_65 ;
V_54 . V_66 = V_67 ;
V_52 = F_34 ( V_37 , & V_54 ) ;
if ( F_25 ( V_52 ) ) {
V_41 = F_35 ( V_52 ) ;
goto error;
}
V_55 = V_48 -> V_68 & V_69 ? F_27 ( V_70 ) : 0 ;
V_50 = F_36 ( V_37 , V_5 , 1 , V_71 , true ) ;
F_5 ( V_48 -> V_6 , V_7 ) ;
V_5 -> V_72 = 1 ;
V_41 = F_37 ( V_1 -> V_11 , V_52 , V_5 , V_54 . V_60 ,
V_48 -> V_59 , V_48 -> V_63 ,
V_48 -> V_73 , V_55 , V_50 , V_49 ,
V_48 -> V_68 , V_7 ,
V_16 -> V_74 , ( T_5 * ) V_16 -> V_28 ,
false ) ;
if ( V_41 < 0 )
F_38 ( V_52 ) ;
error:
return V_41 ;
}
static const char * F_39 ( const struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
return V_1 -> V_45 ;
}
