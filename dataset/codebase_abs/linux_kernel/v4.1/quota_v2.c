static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 + V_2 - 1 ) >> V_3 ;
}
static inline T_1 F_2 ( T_1 V_4 )
{
return V_4 << V_3 ;
}
static int F_3 ( struct V_5 * V_6 , int type ,
struct V_7 * V_8 )
{
T_2 V_9 ;
V_9 = V_6 -> V_10 -> V_11 ( V_6 , type , ( char * ) V_8 ,
sizeof( struct V_7 ) , 0 ) ;
if ( V_9 != sizeof( struct V_7 ) ) {
F_4 ( V_6 , L_1 ,
sizeof( struct V_7 ) , V_9 ) ;
return 0 ;
}
return 1 ;
}
static int F_5 ( struct V_5 * V_6 , int type )
{
struct V_7 V_8 ;
static const T_3 V_12 [] = V_13 ;
static const T_3 V_14 [] = V_15 ;
if ( ! F_3 ( V_6 , type , & V_8 ) )
return 0 ;
if ( F_6 ( V_8 . V_16 ) != V_12 [ type ] ||
F_6 ( V_8 . V_17 ) > V_14 [ type ] )
return 0 ;
return 1 ;
}
static int F_7 ( struct V_5 * V_6 , int type )
{
struct V_18 V_19 ;
struct V_7 V_8 ;
struct V_20 * V_21 = F_8 ( V_6 , type ) ;
struct V_22 * V_23 ;
T_2 V_9 ;
unsigned int V_24 ;
if ( ! F_3 ( V_6 , type , & V_8 ) )
return - 1 ;
V_24 = F_6 ( V_8 . V_17 ) ;
if ( ( V_21 -> V_25 == V_26 && V_24 != 0 ) ||
( V_21 -> V_25 == V_27 && V_24 != 1 ) )
return - 1 ;
V_9 = V_6 -> V_10 -> V_11 ( V_6 , type , ( char * ) & V_19 ,
sizeof( struct V_18 ) , V_28 ) ;
if ( V_9 != sizeof( struct V_18 ) ) {
F_4 ( V_6 , L_2 ) ;
return - 1 ;
}
V_21 -> V_29 = F_9 ( sizeof( struct V_22 ) , V_30 ) ;
if ( ! V_21 -> V_29 ) {
F_10 ( V_31
L_3 ) ;
return - V_32 ;
}
V_23 = V_21 -> V_29 ;
if ( V_24 == 0 ) {
V_21 -> V_33 = 0xffffffffLL << V_3 ;
V_21 -> V_34 = 0xffffffff ;
} else {
V_21 -> V_33 = 0x7fffffffffffffffLL ;
V_21 -> V_34 = 0x7fffffffffffffffLL ;
}
V_21 -> V_35 = F_6 ( V_19 . V_35 ) ;
V_21 -> V_36 = F_6 ( V_19 . V_36 ) ;
V_21 -> V_37 = 0 ;
V_23 -> V_38 = V_6 ;
V_23 -> V_39 = type ;
V_23 -> V_40 = F_6 ( V_19 . V_40 ) ;
V_23 -> V_41 = F_6 ( V_19 . V_41 ) ;
V_23 -> V_42 = F_6 ( V_19 . V_42 ) ;
V_23 -> V_43 = V_44 ;
V_23 -> V_45 = 1 << V_44 ;
V_23 -> V_46 = F_11 ( V_23 ) ;
if ( V_24 == 0 ) {
V_23 -> V_47 = sizeof( struct V_48 ) ;
V_23 -> V_49 = & V_50 ;
} else {
V_23 -> V_47 = sizeof( struct V_51 ) ;
V_23 -> V_49 = & V_52 ;
}
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , int type )
{
struct V_18 V_19 ;
struct V_20 * V_21 = F_8 ( V_6 , type ) ;
struct V_22 * V_23 = V_21 -> V_29 ;
T_2 V_9 ;
F_13 ( & V_53 ) ;
V_21 -> V_37 &= ~ V_54 ;
V_19 . V_35 = F_14 ( V_21 -> V_35 ) ;
V_19 . V_36 = F_14 ( V_21 -> V_36 ) ;
V_19 . V_37 = F_14 ( 0 ) ;
F_15 ( & V_53 ) ;
V_19 . V_40 = F_14 ( V_23 -> V_40 ) ;
V_19 . V_41 = F_14 ( V_23 -> V_41 ) ;
V_19 . V_42 = F_14 ( V_23 -> V_42 ) ;
V_9 = V_6 -> V_10 -> V_55 ( V_6 , type , ( char * ) & V_19 ,
sizeof( struct V_18 ) , V_28 ) ;
if ( V_9 != sizeof( struct V_18 ) ) {
F_4 ( V_6 , L_4 ) ;
return - 1 ;
}
return 0 ;
}
static void F_16 ( struct V_56 * V_56 , void * V_57 )
{
struct V_48 * V_58 = V_57 , V_59 ;
struct V_60 * V_61 = & V_56 -> V_62 ;
V_61 -> V_63 = F_6 ( V_58 -> V_63 ) ;
V_61 -> V_64 = F_6 ( V_58 -> V_64 ) ;
V_61 -> V_65 = F_6 ( V_58 -> V_65 ) ;
V_61 -> V_66 = F_17 ( V_58 -> V_66 ) ;
V_61 -> V_67 = F_2 ( F_6 ( V_58 -> V_67 ) ) ;
V_61 -> V_68 = F_2 ( F_6 ( V_58 -> V_68 ) ) ;
V_61 -> V_69 = F_17 ( V_58 -> V_69 ) ;
V_61 -> V_70 = F_17 ( V_58 -> V_70 ) ;
memset ( & V_59 , 0 , sizeof( struct V_48 ) ) ;
V_59 . V_66 = F_18 ( 1 ) ;
if ( ! memcmp ( & V_59 , V_57 , sizeof( struct V_48 ) ) )
V_61 -> V_66 = 0 ;
}
static void F_19 ( void * V_57 , struct V_56 * V_56 )
{
struct V_48 * V_58 = V_57 ;
struct V_60 * V_61 = & V_56 -> V_62 ;
struct V_22 * V_21 =
F_8 ( V_56 -> V_71 , V_56 -> V_72 . type ) -> V_29 ;
V_58 -> V_63 = F_14 ( V_61 -> V_63 ) ;
V_58 -> V_64 = F_14 ( V_61 -> V_64 ) ;
V_58 -> V_65 = F_14 ( V_61 -> V_65 ) ;
V_58 -> V_66 = F_18 ( V_61 -> V_66 ) ;
V_58 -> V_67 = F_14 ( F_1 ( V_61 -> V_67 ) ) ;
V_58 -> V_68 = F_14 ( F_1 ( V_61 -> V_68 ) ) ;
V_58 -> V_69 = F_18 ( V_61 -> V_69 ) ;
V_58 -> V_70 = F_18 ( V_61 -> V_70 ) ;
V_58 -> V_73 = F_14 ( F_20 ( & V_74 , V_56 -> V_72 ) ) ;
if ( F_21 ( V_21 , V_57 ) )
V_58 -> V_66 = F_18 ( 1 ) ;
}
static int F_22 ( void * V_57 , struct V_56 * V_56 )
{
struct V_48 * V_58 = V_57 ;
struct V_22 * V_21 =
F_8 ( V_56 -> V_71 , V_56 -> V_72 . type ) -> V_29 ;
if ( F_21 ( V_21 , V_57 ) )
return 0 ;
return F_23 ( F_24 ( & V_74 , V_56 -> V_72 . type ,
F_6 ( V_58 -> V_73 ) ) ,
V_56 -> V_72 ) ;
}
static void F_25 ( struct V_56 * V_56 , void * V_57 )
{
struct V_51 * V_58 = V_57 , V_59 ;
struct V_60 * V_61 = & V_56 -> V_62 ;
V_61 -> V_63 = F_17 ( V_58 -> V_63 ) ;
V_61 -> V_64 = F_17 ( V_58 -> V_64 ) ;
V_61 -> V_65 = F_17 ( V_58 -> V_65 ) ;
V_61 -> V_66 = F_17 ( V_58 -> V_66 ) ;
V_61 -> V_67 = F_2 ( F_17 ( V_58 -> V_67 ) ) ;
V_61 -> V_68 = F_2 ( F_17 ( V_58 -> V_68 ) ) ;
V_61 -> V_69 = F_17 ( V_58 -> V_69 ) ;
V_61 -> V_70 = F_17 ( V_58 -> V_70 ) ;
memset ( & V_59 , 0 , sizeof( struct V_51 ) ) ;
V_59 . V_66 = F_18 ( 1 ) ;
if ( ! memcmp ( & V_59 , V_57 , sizeof( struct V_51 ) ) )
V_61 -> V_66 = 0 ;
}
static void F_26 ( void * V_57 , struct V_56 * V_56 )
{
struct V_51 * V_58 = V_57 ;
struct V_60 * V_61 = & V_56 -> V_62 ;
struct V_22 * V_21 =
F_8 ( V_56 -> V_71 , V_56 -> V_72 . type ) -> V_29 ;
V_58 -> V_63 = F_18 ( V_61 -> V_63 ) ;
V_58 -> V_64 = F_18 ( V_61 -> V_64 ) ;
V_58 -> V_65 = F_18 ( V_61 -> V_65 ) ;
V_58 -> V_66 = F_18 ( V_61 -> V_66 ) ;
V_58 -> V_67 = F_18 ( F_1 ( V_61 -> V_67 ) ) ;
V_58 -> V_68 = F_18 ( F_1 ( V_61 -> V_68 ) ) ;
V_58 -> V_69 = F_18 ( V_61 -> V_69 ) ;
V_58 -> V_70 = F_18 ( V_61 -> V_70 ) ;
V_58 -> V_73 = F_14 ( F_20 ( & V_74 , V_56 -> V_72 ) ) ;
if ( F_21 ( V_21 , V_57 ) )
V_58 -> V_66 = F_18 ( 1 ) ;
}
static int F_27 ( void * V_57 , struct V_56 * V_56 )
{
struct V_51 * V_58 = V_57 ;
struct V_22 * V_21 =
F_8 ( V_56 -> V_71 , V_56 -> V_72 . type ) -> V_29 ;
if ( F_21 ( V_21 , V_57 ) )
return 0 ;
return F_23 ( F_24 ( & V_74 , V_56 -> V_72 . type ,
F_6 ( V_58 -> V_73 ) ) ,
V_56 -> V_72 ) ;
}
static int F_28 ( struct V_56 * V_56 )
{
return F_29 ( F_8 ( V_56 -> V_71 , V_56 -> V_72 . type ) -> V_29 , V_56 ) ;
}
static int F_30 ( struct V_56 * V_56 )
{
return F_31 ( F_8 ( V_56 -> V_71 , V_56 -> V_72 . type ) -> V_29 , V_56 ) ;
}
static int F_32 ( struct V_56 * V_56 )
{
return F_33 ( F_8 ( V_56 -> V_71 , V_56 -> V_72 . type ) -> V_29 , V_56 ) ;
}
static int F_34 ( struct V_5 * V_6 , int type )
{
F_35 ( F_8 ( V_6 , type ) -> V_29 ) ;
return 0 ;
}
static int T_4 F_36 ( void )
{
int V_75 ;
V_75 = F_37 ( & V_76 ) ;
if ( V_75 )
return V_75 ;
return F_37 ( & V_77 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_76 ) ;
F_39 ( & V_77 ) ;
}
