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
if ( V_9 < 0 )
return V_9 ;
return - V_12 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 , int type )
{
struct V_7 V_8 ;
static const T_3 V_13 [] = V_14 ;
static const T_3 V_15 [] = V_16 ;
if ( F_3 ( V_6 , type , & V_8 ) )
return 0 ;
if ( F_6 ( V_8 . V_17 ) != V_13 [ type ] ||
F_6 ( V_8 . V_18 ) > V_15 [ type ] )
return 0 ;
return 1 ;
}
static int F_7 ( struct V_5 * V_6 , int type )
{
struct V_19 V_20 ;
struct V_7 V_8 ;
struct V_21 * V_22 = F_8 ( V_6 ) ;
struct V_23 * V_24 = & V_22 -> V_24 [ type ] ;
struct V_25 * V_26 ;
T_2 V_9 ;
unsigned int V_27 ;
int V_28 ;
F_9 ( & V_22 -> V_29 ) ;
V_28 = F_3 ( V_6 , type , & V_8 ) ;
if ( V_28 < 0 )
goto V_30;
V_27 = F_6 ( V_8 . V_18 ) ;
if ( ( V_24 -> V_31 == V_32 && V_27 != 0 ) ||
( V_24 -> V_31 == V_33 && V_27 != 1 ) ) {
V_28 = - V_34 ;
goto V_30;
}
V_9 = V_6 -> V_10 -> V_11 ( V_6 , type , ( char * ) & V_20 ,
sizeof( struct V_19 ) , V_35 ) ;
if ( V_9 != sizeof( struct V_19 ) ) {
F_4 ( V_6 , L_2 ) ;
if ( V_9 < 0 )
V_28 = V_9 ;
else
V_28 = - V_12 ;
goto V_30;
}
V_24 -> V_36 = F_10 ( sizeof( struct V_25 ) , V_37 ) ;
if ( ! V_24 -> V_36 ) {
V_28 = - V_38 ;
goto V_30;
}
V_26 = V_24 -> V_36 ;
if ( V_27 == 0 ) {
V_24 -> V_39 = 0xffffffffLL << V_3 ;
V_24 -> V_40 = 0xffffffff ;
} else {
V_24 -> V_39 = 0x7fffffffffffffffLL ;
V_24 -> V_40 = 0x7fffffffffffffffLL ;
}
V_24 -> V_41 = F_6 ( V_20 . V_41 ) ;
V_24 -> V_42 = F_6 ( V_20 . V_42 ) ;
V_24 -> V_43 = 0 ;
V_26 -> V_44 = V_6 ;
V_26 -> V_45 = type ;
V_26 -> V_46 = F_6 ( V_20 . V_46 ) ;
V_26 -> V_47 = F_6 ( V_20 . V_47 ) ;
V_26 -> V_48 = F_6 ( V_20 . V_48 ) ;
V_26 -> V_49 = V_50 ;
V_26 -> V_51 = 1 << V_50 ;
V_26 -> V_52 = F_11 ( V_26 ) ;
if ( V_27 == 0 ) {
V_26 -> V_53 = sizeof( struct V_54 ) ;
V_26 -> V_55 = & V_56 ;
} else {
V_26 -> V_53 = sizeof( struct V_57 ) ;
V_26 -> V_55 = & V_58 ;
}
V_28 = 0 ;
V_30:
F_12 ( & V_22 -> V_29 ) ;
return V_28 ;
}
static int F_13 ( struct V_5 * V_6 , int type )
{
struct V_19 V_20 ;
struct V_21 * V_22 = F_8 ( V_6 ) ;
struct V_23 * V_24 = & V_22 -> V_24 [ type ] ;
struct V_25 * V_26 = V_24 -> V_36 ;
T_2 V_9 ;
F_14 ( & V_22 -> V_29 ) ;
F_15 ( & V_59 ) ;
V_24 -> V_43 &= ~ V_60 ;
V_20 . V_41 = F_16 ( V_24 -> V_41 ) ;
V_20 . V_42 = F_16 ( V_24 -> V_42 ) ;
V_20 . V_43 = F_16 ( 0 ) ;
F_17 ( & V_59 ) ;
V_20 . V_46 = F_16 ( V_26 -> V_46 ) ;
V_20 . V_47 = F_16 ( V_26 -> V_47 ) ;
V_20 . V_48 = F_16 ( V_26 -> V_48 ) ;
V_9 = V_6 -> V_10 -> V_61 ( V_6 , type , ( char * ) & V_20 ,
sizeof( struct V_19 ) , V_35 ) ;
F_18 ( & V_22 -> V_29 ) ;
if ( V_9 != sizeof( struct V_19 ) ) {
F_4 ( V_6 , L_3 ) ;
return - 1 ;
}
return 0 ;
}
static void F_19 ( struct V_62 * V_62 , void * V_63 )
{
struct V_54 * V_64 = V_63 , V_65 ;
struct V_66 * V_67 = & V_62 -> V_68 ;
V_67 -> V_69 = F_6 ( V_64 -> V_69 ) ;
V_67 -> V_70 = F_6 ( V_64 -> V_70 ) ;
V_67 -> V_71 = F_6 ( V_64 -> V_71 ) ;
V_67 -> V_72 = F_20 ( V_64 -> V_72 ) ;
V_67 -> V_73 = F_2 ( F_6 ( V_64 -> V_73 ) ) ;
V_67 -> V_74 = F_2 ( F_6 ( V_64 -> V_74 ) ) ;
V_67 -> V_75 = F_20 ( V_64 -> V_75 ) ;
V_67 -> V_76 = F_20 ( V_64 -> V_76 ) ;
memset ( & V_65 , 0 , sizeof( struct V_54 ) ) ;
V_65 . V_72 = F_21 ( 1 ) ;
if ( ! memcmp ( & V_65 , V_63 , sizeof( struct V_54 ) ) )
V_67 -> V_72 = 0 ;
}
static void F_22 ( void * V_63 , struct V_62 * V_62 )
{
struct V_54 * V_64 = V_63 ;
struct V_66 * V_67 = & V_62 -> V_68 ;
struct V_25 * V_24 =
F_23 ( V_62 -> V_77 , V_62 -> V_78 . type ) -> V_36 ;
V_64 -> V_69 = F_16 ( V_67 -> V_69 ) ;
V_64 -> V_70 = F_16 ( V_67 -> V_70 ) ;
V_64 -> V_71 = F_16 ( V_67 -> V_71 ) ;
V_64 -> V_72 = F_21 ( V_67 -> V_72 ) ;
V_64 -> V_73 = F_16 ( F_1 ( V_67 -> V_73 ) ) ;
V_64 -> V_74 = F_16 ( F_1 ( V_67 -> V_74 ) ) ;
V_64 -> V_75 = F_21 ( V_67 -> V_75 ) ;
V_64 -> V_76 = F_21 ( V_67 -> V_76 ) ;
V_64 -> V_79 = F_16 ( F_24 ( & V_80 , V_62 -> V_78 ) ) ;
if ( F_25 ( V_24 , V_63 ) )
V_64 -> V_72 = F_21 ( 1 ) ;
}
static int F_26 ( void * V_63 , struct V_62 * V_62 )
{
struct V_54 * V_64 = V_63 ;
struct V_25 * V_24 =
F_23 ( V_62 -> V_77 , V_62 -> V_78 . type ) -> V_36 ;
if ( F_25 ( V_24 , V_63 ) )
return 0 ;
return F_27 ( F_28 ( & V_80 , V_62 -> V_78 . type ,
F_6 ( V_64 -> V_79 ) ) ,
V_62 -> V_78 ) ;
}
static void F_29 ( struct V_62 * V_62 , void * V_63 )
{
struct V_57 * V_64 = V_63 , V_65 ;
struct V_66 * V_67 = & V_62 -> V_68 ;
V_67 -> V_69 = F_20 ( V_64 -> V_69 ) ;
V_67 -> V_70 = F_20 ( V_64 -> V_70 ) ;
V_67 -> V_71 = F_20 ( V_64 -> V_71 ) ;
V_67 -> V_72 = F_20 ( V_64 -> V_72 ) ;
V_67 -> V_73 = F_2 ( F_20 ( V_64 -> V_73 ) ) ;
V_67 -> V_74 = F_2 ( F_20 ( V_64 -> V_74 ) ) ;
V_67 -> V_75 = F_20 ( V_64 -> V_75 ) ;
V_67 -> V_76 = F_20 ( V_64 -> V_76 ) ;
memset ( & V_65 , 0 , sizeof( struct V_57 ) ) ;
V_65 . V_72 = F_21 ( 1 ) ;
if ( ! memcmp ( & V_65 , V_63 , sizeof( struct V_57 ) ) )
V_67 -> V_72 = 0 ;
}
static void F_30 ( void * V_63 , struct V_62 * V_62 )
{
struct V_57 * V_64 = V_63 ;
struct V_66 * V_67 = & V_62 -> V_68 ;
struct V_25 * V_24 =
F_23 ( V_62 -> V_77 , V_62 -> V_78 . type ) -> V_36 ;
V_64 -> V_69 = F_21 ( V_67 -> V_69 ) ;
V_64 -> V_70 = F_21 ( V_67 -> V_70 ) ;
V_64 -> V_71 = F_21 ( V_67 -> V_71 ) ;
V_64 -> V_72 = F_21 ( V_67 -> V_72 ) ;
V_64 -> V_73 = F_21 ( F_1 ( V_67 -> V_73 ) ) ;
V_64 -> V_74 = F_21 ( F_1 ( V_67 -> V_74 ) ) ;
V_64 -> V_75 = F_21 ( V_67 -> V_75 ) ;
V_64 -> V_76 = F_21 ( V_67 -> V_76 ) ;
V_64 -> V_79 = F_16 ( F_24 ( & V_80 , V_62 -> V_78 ) ) ;
if ( F_25 ( V_24 , V_63 ) )
V_64 -> V_72 = F_21 ( 1 ) ;
}
static int F_31 ( void * V_63 , struct V_62 * V_62 )
{
struct V_57 * V_64 = V_63 ;
struct V_25 * V_24 =
F_23 ( V_62 -> V_77 , V_62 -> V_78 . type ) -> V_36 ;
if ( F_25 ( V_24 , V_63 ) )
return 0 ;
return F_27 ( F_28 ( & V_80 , V_62 -> V_78 . type ,
F_6 ( V_64 -> V_79 ) ) ,
V_62 -> V_78 ) ;
}
static int F_32 ( struct V_62 * V_62 )
{
struct V_21 * V_22 = F_8 ( V_62 -> V_77 ) ;
int V_28 ;
F_9 ( & V_22 -> V_29 ) ;
V_28 = F_33 (
F_23 ( V_62 -> V_77 , V_62 -> V_78 . type ) -> V_36 ,
V_62 ) ;
F_12 ( & V_22 -> V_29 ) ;
return V_28 ;
}
static int F_34 ( struct V_62 * V_62 )
{
struct V_21 * V_22 = F_8 ( V_62 -> V_77 ) ;
int V_28 ;
bool V_81 = false ;
if ( ! V_62 -> V_82 ) {
V_81 = true ;
F_14 ( & V_22 -> V_29 ) ;
} else {
F_9 ( & V_22 -> V_29 ) ;
}
V_28 = F_35 (
F_23 ( V_62 -> V_77 , V_62 -> V_78 . type ) -> V_36 ,
V_62 ) ;
if ( V_81 )
F_18 ( & V_22 -> V_29 ) ;
else
F_12 ( & V_22 -> V_29 ) ;
return V_28 ;
}
static int F_36 ( struct V_62 * V_62 )
{
struct V_21 * V_22 = F_8 ( V_62 -> V_77 ) ;
int V_28 ;
F_14 ( & V_22 -> V_29 ) ;
V_28 = F_37 ( F_23 ( V_62 -> V_77 , V_62 -> V_78 . type ) -> V_36 , V_62 ) ;
F_18 ( & V_22 -> V_29 ) ;
return V_28 ;
}
static int F_38 ( struct V_5 * V_6 , int type )
{
F_39 ( F_23 ( V_6 , type ) -> V_36 ) ;
return 0 ;
}
static int F_40 ( struct V_5 * V_6 , struct V_83 * V_84 )
{
struct V_21 * V_22 = F_8 ( V_6 ) ;
int V_28 ;
F_9 ( & V_22 -> V_29 ) ;
V_28 = F_41 ( F_23 ( V_6 , V_84 -> type ) -> V_36 , V_84 ) ;
F_12 ( & V_22 -> V_29 ) ;
return V_28 ;
}
static int T_4 F_42 ( void )
{
int V_28 ;
V_28 = F_43 ( & V_85 ) ;
if ( V_28 )
return V_28 ;
return F_43 ( & V_86 ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_85 ) ;
F_45 ( & V_86 ) ;
}
