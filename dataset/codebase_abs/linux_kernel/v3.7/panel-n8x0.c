static inline
struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline
struct V_5 * F_2 ( const struct V_2 * V_3 )
{
return & V_6 ;
}
static inline void F_3 ( T_1 V_7 )
{
F_4 ( & V_7 , 1 ) ;
}
static inline void F_5 ( T_1 V_7 , const T_1 * V_8 , int V_9 )
{
F_4 ( & V_7 , 1 ) ;
F_6 ( V_8 , V_9 ) ;
}
static inline void F_7 ( T_1 V_7 , T_1 * V_8 , int V_9 )
{
F_4 ( & V_7 , 1 ) ;
F_8 ( V_8 , V_9 ) ;
}
static T_1 F_9 ( T_1 V_7 )
{
T_1 V_4 ;
F_7 ( V_7 , & V_4 , 1 ) ;
return V_4 ;
}
static void F_10 ( struct V_2 * V_3 ,
int V_10 , int V_11 , int V_12 , int V_13 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
T_1 V_15 [ 18 ] ;
int V_16 , V_17 ;
V_16 = V_10 + V_12 - 1 ;
V_17 = V_11 + V_13 - 1 ;
V_15 [ 0 ] = V_10 ;
V_15 [ 1 ] = V_10 >> 8 ;
V_15 [ 2 ] = V_11 ;
V_15 [ 3 ] = V_11 >> 8 ;
V_15 [ 4 ] = V_16 ;
V_15 [ 5 ] = V_16 >> 8 ;
V_15 [ 6 ] = V_17 ;
V_15 [ 7 ] = V_17 >> 8 ;
V_15 [ 8 ] = V_10 ;
V_15 [ 9 ] = V_10 >> 8 ;
V_15 [ 10 ] = V_11 ;
V_15 [ 11 ] = V_11 >> 8 ;
V_15 [ 12 ] = V_16 ;
V_15 [ 13 ] = V_16 >> 8 ;
V_15 [ 14 ] = V_17 ;
V_15 [ 15 ] = V_17 >> 8 ;
V_15 [ 16 ] = V_18 ;
if ( V_14 -> V_19 == V_20 )
V_15 [ 17 ] = V_21 ;
else
V_15 [ 17 ] = V_14 -> V_19 == V_22 ?
V_23 :
V_24 ;
F_11 ( V_3 , 16 ) ;
F_12 ( V_3 , 8 ) ;
F_13 ( V_3 ) ;
F_5 ( V_25 , V_15 , 18 ) ;
F_11 ( V_3 , 16 ) ;
F_12 ( V_3 , 16 ) ;
F_13 ( V_3 ) ;
}
static void F_14 ( struct V_26 * V_27 , int V_7 , const T_1 * V_28 ,
int V_29 , T_1 * V_30 , int V_31 )
{
struct V_32 V_33 ;
struct V_34 * V_10 , V_35 [ 4 ] ;
T_2 V_12 ;
int V_36 ;
F_15 ( & V_33 ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
V_10 = & V_35 [ 0 ] ;
V_7 &= 0xff ;
V_10 -> V_37 = & V_7 ;
V_10 -> V_38 = 9 ;
V_10 -> V_9 = 2 ;
F_16 ( V_10 , & V_33 ) ;
if ( V_29 ) {
V_10 ++ ;
V_10 -> V_37 = V_28 ;
V_10 -> V_9 = V_29 ;
V_10 -> V_38 = 9 ;
F_16 ( V_10 , & V_33 ) ;
}
if ( V_31 ) {
V_10 ++ ;
V_10 -> V_39 = & V_12 ;
V_10 -> V_9 = 1 ;
F_16 ( V_10 , & V_33 ) ;
if ( V_31 > 1 ) {
V_10 -> V_38 = 9 ;
V_10 -> V_9 = 2 ;
V_10 ++ ;
V_10 -> V_39 = & V_30 [ 1 ] ;
V_10 -> V_9 = V_31 - 1 ;
F_16 ( V_10 , & V_33 ) ;
}
}
V_36 = F_17 ( V_27 , & V_33 ) ;
if ( V_36 < 0 )
F_18 ( & V_27 -> V_40 , L_1 , V_36 ) ;
if ( V_31 )
V_30 [ 0 ] = V_12 & 0xff ;
}
static inline void F_19 ( struct V_26 * V_27 , int V_7 )
{
F_14 ( V_27 , V_7 , NULL , 0 , NULL , 0 ) ;
}
static inline void F_20 ( struct V_26 * V_27 ,
int V_41 , const T_1 * V_8 , int V_9 )
{
F_14 ( V_27 , V_41 , V_8 , V_9 , NULL , 0 ) ;
}
static inline void F_21 ( struct V_26 * V_27 ,
int V_41 , T_1 * V_8 , int V_9 )
{
F_14 ( V_27 , V_41 , NULL , 0 , V_8 , V_9 ) ;
}
static void F_22 ( struct V_26 * V_27 , int V_42 )
{
T_2 V_43 ;
switch ( V_42 ) {
case 16 :
V_43 = 0x150 ;
break;
case 18 :
V_43 = 0x160 ;
break;
case 24 :
V_43 = 0x170 ;
break;
}
F_20 ( V_27 , 0x3a , ( T_1 * ) & V_43 , 2 ) ;
}
static void F_23 ( struct V_26 * V_27 )
{
T_2 V_44 [] = { 0x0102 , 0x0100 , 0x0100 } ;
F_20 ( V_27 , 0xc2 , ( T_1 * ) V_44 , sizeof( V_44 ) ) ;
}
static void F_24 ( struct V_26 * V_27 )
{
F_19 ( V_27 , V_45 ) ;
}
static void F_25 ( struct V_26 * V_27 )
{
F_19 ( V_27 , V_46 ) ;
}
static void F_26 ( struct V_26 * V_27 )
{
F_19 ( V_27 , V_47 ) ;
F_27 ( 120 ) ;
}
static void F_28 ( struct V_26 * V_27 )
{
F_19 ( V_27 , V_48 ) ;
F_27 ( 50 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_36 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_26 * V_27 = V_14 -> V_50 ;
T_1 V_51 , V_52 ;
T_1 V_53 [ 3 ] ;
const char * V_54 ;
if ( V_3 -> V_55 == V_56 )
return 0 ;
F_30 ( V_49 -> V_57 , 1 ) ;
if ( V_49 -> V_58 ) {
V_36 = V_49 -> V_58 ( V_3 ) ;
if ( V_36 )
goto V_59;
}
F_31 ( V_3 , V_3 -> V_60 . V_61 . V_62 ,
V_3 -> V_60 . V_61 . V_63 ) ;
F_11 ( V_3 , V_3 -> V_64 . V_65 ) ;
F_12 ( V_3 , V_3 -> V_66 . V_67 . V_42 ) ;
F_32 ( V_3 , & V_3 -> V_64 . V_68 ) ;
V_36 = F_33 ( V_3 ) ;
if ( V_36 )
goto V_69;
V_51 = F_9 ( V_70 ) ;
V_52 = F_9 ( V_71 ) ;
switch ( V_51 & 0xfc ) {
case 0x9c :
V_14 -> V_19 = V_22 ;
F_34 ( & V_3 -> V_40 , L_2
L_3 , V_51 & 0x03 , V_52 & 0x07 ) ;
break;
case 0xa4 :
V_14 -> V_19 = V_20 ;
F_34 ( & V_3 -> V_40 , L_4
L_3 , V_51 & 0x03 , V_52 & 0x07 ) ;
break;
default:
F_35 ( & V_3 -> V_40 , L_5 , V_51 ) ;
V_36 = - V_72 ;
goto V_73;
}
F_30 ( V_49 -> V_74 , 1 ) ;
F_21 ( V_27 , V_75 , V_53 , 3 ) ;
F_18 ( & V_27 -> V_40 , L_6 ,
V_53 [ 0 ] , V_53 [ 1 ] , V_53 [ 2 ] ) ;
switch ( V_53 [ 0 ] ) {
case 0x45 :
V_54 = L_7 ;
break;
case 0x83 :
V_54 = L_8 ;
break;
default:
F_35 ( & V_3 -> V_40 , L_9 ,
V_53 [ 0 ] ) ;
V_36 = - V_72 ;
goto V_76;
}
F_34 ( & V_3 -> V_40 , L_10 ,
V_54 , V_53 [ 1 ] ) ;
F_26 ( V_27 ) ;
F_23 ( V_27 ) ;
F_22 ( V_27 , 24 ) ;
F_24 ( V_27 ) ;
return 0 ;
V_76:
V_73:
F_36 ( V_3 ) ;
V_69:
if ( V_49 -> V_77 )
V_49 -> V_77 ( V_3 ) ;
V_59:
F_30 ( V_49 -> V_57 , 0 ) ;
return V_36 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_26 * V_27 = V_14 -> V_50 ;
if ( V_3 -> V_55 != V_56 )
return;
F_25 ( V_27 ) ;
F_28 ( V_27 ) ;
if ( V_49 -> V_77 )
V_49 -> V_77 ( V_3 ) ;
F_30 ( V_49 -> V_57 , 0 ) ;
F_36 ( V_3 ) ;
}
static int F_38 ( struct V_78 * V_40 )
{
struct V_2 * V_3 = F_39 ( & V_40 -> V_40 ) ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_5 * V_14 = F_2 ( V_3 ) ;
int V_36 ;
int V_79 ;
F_40 ( & V_14 -> V_80 ) ;
if ( V_40 -> V_81 . V_82 == V_83 &&
V_40 -> V_81 . V_84 == V_83 )
V_79 = V_40 -> V_81 . V_85 ;
else
V_79 = 0 ;
F_18 ( & V_3 -> V_40 , L_11 , V_79 ) ;
if ( ! V_49 -> V_86 )
V_36 = - V_87 ;
else
V_36 = V_49 -> V_86 ( V_3 , V_79 ) ;
F_41 ( & V_14 -> V_80 ) ;
return V_36 ;
}
static int F_42 ( struct V_78 * V_40 )
{
if ( V_40 -> V_81 . V_82 == V_83 &&
V_40 -> V_81 . V_84 == V_83 )
return V_40 -> V_81 . V_85 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_5 * V_14 ;
struct V_78 * V_88 ;
struct V_89 V_81 ;
int V_36 ;
F_18 ( & V_3 -> V_40 , L_12 ) ;
if ( ! V_49 )
return - V_87 ;
V_6 . V_3 = V_3 ;
V_14 = & V_6 ;
F_44 ( & V_14 -> V_80 ) ;
V_3 -> V_60 . V_61 . V_62 = 800 ;
V_3 -> V_60 . V_61 . V_63 = 480 ;
V_3 -> V_64 . V_65 = 16 ;
V_3 -> V_64 . V_68 = V_90 ;
V_3 -> V_91 = V_92 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_93 = 127 ;
V_81 . type = V_94 ;
V_88 = F_45 ( F_46 ( & V_3 -> V_40 ) , & V_3 -> V_40 ,
V_3 , & V_95 , & V_81 ) ;
if ( F_47 ( V_88 ) ) {
V_36 = F_48 ( V_88 ) ;
F_35 ( & V_3 -> V_40 , L_13 ) ;
return V_36 ;
}
V_14 -> V_88 = V_88 ;
V_88 -> V_81 . V_82 = V_83 ;
V_88 -> V_81 . V_84 = V_83 ;
V_88 -> V_81 . V_85 = 127 ;
F_38 ( V_88 ) ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_78 * V_88 ;
F_18 ( & V_3 -> V_40 , L_14 ) ;
V_88 = V_14 -> V_88 ;
V_88 -> V_81 . V_84 = V_96 ;
F_38 ( V_88 ) ;
F_50 ( V_88 ) ;
F_51 ( & V_3 -> V_40 , NULL ) ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
int V_36 ;
F_18 ( & V_3 -> V_40 , L_15 ) ;
F_40 ( & V_14 -> V_80 ) ;
F_53 () ;
V_36 = F_29 ( V_3 ) ;
F_54 () ;
if ( V_36 ) {
F_41 ( & V_14 -> V_80 ) ;
return V_36 ;
}
V_3 -> V_55 = V_56 ;
F_41 ( & V_14 -> V_80 ) ;
return 0 ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
F_18 ( & V_3 -> V_40 , L_16 ) ;
F_40 ( & V_14 -> V_80 ) ;
F_53 () ;
F_37 ( V_3 ) ;
F_54 () ;
V_3 -> V_55 = V_97 ;
F_41 ( & V_14 -> V_80 ) ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
F_18 ( & V_3 -> V_40 , L_17 ) ;
F_40 ( & V_14 -> V_80 ) ;
F_53 () ;
F_37 ( V_3 ) ;
F_54 () ;
V_3 -> V_55 = V_98 ;
F_41 ( & V_14 -> V_80 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
int V_36 ;
F_18 ( & V_3 -> V_40 , L_18 ) ;
F_40 ( & V_14 -> V_80 ) ;
F_53 () ;
V_36 = F_29 ( V_3 ) ;
F_54 () ;
if ( V_36 ) {
F_41 ( & V_14 -> V_80 ) ;
return V_36 ;
}
V_3 -> V_55 = V_56 ;
F_41 ( & V_14 -> V_80 ) ;
return 0 ;
}
static void F_58 ( struct V_2 * V_3 ,
T_2 * V_99 , T_2 * V_100 )
{
* V_99 = V_3 -> V_60 . V_61 . V_62 ;
* V_100 = V_3 -> V_60 . V_61 . V_63 ;
}
static void F_59 ( void * V_4 )
{
F_54 () ;
}
static int F_60 ( struct V_2 * V_3 ,
T_2 V_10 , T_2 V_11 , T_2 V_12 , T_2 V_13 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
T_2 V_101 , V_102 ;
F_18 ( & V_3 -> V_40 , L_19 ) ;
V_101 = V_3 -> V_60 . V_61 . V_62 ;
V_102 = V_3 -> V_60 . V_61 . V_63 ;
if ( V_10 != 0 || V_11 != 0 || V_12 != V_101 || V_13 != V_102 ) {
F_35 ( & V_3 -> V_40 , L_20 ,
V_10 , V_11 , V_12 , V_13 ) ;
return - V_87 ;
}
F_40 ( & V_14 -> V_80 ) ;
F_53 () ;
F_10 ( V_3 , V_10 , V_11 , V_12 , V_13 ) ;
F_61 ( V_3 , F_59 , NULL ) ;
F_41 ( & V_14 -> V_80 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
F_18 ( & V_3 -> V_40 , L_21 ) ;
F_40 ( & V_14 -> V_80 ) ;
F_53 () ;
F_54 () ;
F_41 ( & V_14 -> V_80 ) ;
return 0 ;
}
static int F_63 ( struct V_26 * V_27 )
{
F_18 ( & V_27 -> V_40 , L_22 ) ;
V_27 -> V_103 = V_104 ;
V_6 . V_50 = V_27 ;
return 0 ;
}
static int F_64 ( struct V_26 * V_27 )
{
F_18 ( & V_27 -> V_40 , L_23 ) ;
return 0 ;
}
static int T_3 F_65 ( void )
{
int V_36 ;
V_36 = F_66 ( & V_105 ) ;
if ( V_36 ) {
F_67 ( L_24 ) ;
return V_36 ;
}
V_36 = F_68 ( & V_106 ) ;
if ( V_36 ) {
F_67 ( L_25 ) ;
F_69 ( & V_105 ) ;
return V_36 ;
}
return 0 ;
}
static void T_4 F_70 ( void )
{
F_69 ( & V_105 ) ;
F_71 ( & V_106 ) ;
}
