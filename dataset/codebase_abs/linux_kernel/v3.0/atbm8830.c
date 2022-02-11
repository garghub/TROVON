static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = 0 ;
T_2 V_6 ;
T_2 V_7 [] = { V_3 >> 8 , V_3 & 0xFF } ;
T_2 V_8 [] = { V_4 } ;
struct V_9 V_10 = { . V_11 = 0 , . V_12 = V_7 , . V_13 = 2 } ;
struct V_9 V_14 = { . V_11 = 0 , . V_12 = V_8 , . V_13 = 1 } ;
V_6 = V_2 -> V_15 -> V_16 ;
V_10 . V_17 = V_6 ;
V_14 . V_17 = V_6 ;
if ( V_18 >= 2 )
F_2 ( L_1 , V_19 , V_3 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_10 , 1 ) ;
if ( V_5 != 1 )
return - V_21 ;
V_5 = F_3 ( V_2 -> V_20 , & V_14 , 1 ) ;
return ( V_5 != 1 ) ? - V_21 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_22 )
{
int V_5 ;
T_2 V_6 ;
T_2 V_7 [] = { V_3 >> 8 , V_3 & 0xFF } ;
T_2 V_8 [] = { 0 } ;
struct V_9 V_10 = { . V_11 = 0 , . V_12 = V_7 , . V_13 = 2 } ;
struct V_9 V_14 = { . V_11 = V_23 , . V_12 = V_8 , . V_13 = 1 } ;
V_6 = V_2 -> V_15 -> V_16 ;
V_10 . V_17 = V_6 ;
V_14 . V_17 = V_6 ;
V_5 = F_3 ( V_2 -> V_20 , & V_10 , 1 ) ;
if ( V_5 != 1 ) {
F_2 ( L_2 , V_19 , V_3 , V_5 ) ;
return - V_21 ;
}
V_5 = F_3 ( V_2 -> V_20 , & V_14 , 1 ) ;
if ( V_5 != 1 )
return - V_21 ;
* V_22 = V_8 [ 0 ] ;
if ( V_18 >= 2 )
F_2 ( L_1 ,
V_19 , V_3 , V_8 [ 0 ] ) ;
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 , int V_24 )
{
return F_1 ( V_2 , V_25 , V_24 ? 1 : 0 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_3 V_26 )
{
T_3 V_27 ;
T_4 V_28 ;
V_28 = ( T_4 ) 0x100000 * V_26 ;
F_7 ( V_28 , 30400 ) ;
V_27 = V_28 ;
F_1 ( V_2 , V_29 , V_27 ) ;
F_1 ( V_2 , V_29 + 1 , V_27 >> 8 ) ;
F_1 ( V_2 , V_29 + 2 , V_27 >> 16 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_3 V_26 )
{
T_3 V_30 = V_2 -> V_15 -> V_31 ;
T_4 V_28 ;
T_3 V_27 ;
T_2 V_32 ;
if ( V_26 != 0 ) {
V_28 = ( T_4 ) 2 * 31416 * ( V_26 - V_30 ) ;
V_28 <<= 22 ;
F_7 ( V_28 , V_30 ) ;
F_7 ( V_28 , 1000 ) ;
V_27 = V_28 ;
F_1 ( V_2 , V_33 , 1 ) ;
F_1 ( V_2 , V_34 , V_27 ) ;
F_1 ( V_2 , V_34 + 1 , V_27 >> 8 ) ;
F_1 ( V_2 , V_34 + 2 , V_27 >> 16 ) ;
F_4 ( V_2 , V_35 , & V_32 ) ;
V_32 &= 0xFC ;
F_1 ( V_2 , V_35 , V_32 ) ;
} else {
F_1 ( V_2 , V_33 , 0 ) ;
F_4 ( V_2 , V_35 , & V_32 ) ;
V_32 &= 0xFC ;
V_32 |= 0x02 ;
F_1 ( V_2 , V_35 , V_32 ) ;
if ( V_2 -> V_15 -> V_36 )
F_1 ( V_2 , V_37 , 0x03 ) ;
else
F_1 ( V_2 , V_37 , 0x01 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 * V_38 )
{
T_2 V_39 ;
F_4 ( V_2 , V_40 , & V_39 ) ;
if ( V_38 != NULL )
* V_38 = ( V_39 == 1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_2 V_41 , T_2 V_42 , T_2 V_43 )
{
if ( ! V_41 && ! V_42 )
return 0 ;
F_1 ( V_2 , V_44 , V_41 ) ;
F_1 ( V_2 , V_45 , V_42 ) ;
F_1 ( V_2 , V_46 , V_43 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < 5 ; V_47 ++ )
F_1 ( V_2 , 0x099B + V_47 , 0x08 ) ;
F_1 ( V_2 , 0x095B , 0x7F ) ;
F_1 ( V_2 , 0x09CB , 0x01 ) ;
F_1 ( V_2 , 0x09CC , 0x7F ) ;
F_1 ( V_2 , 0x09CD , 0x7F ) ;
F_1 ( V_2 , 0x0E01 , 0x20 ) ;
F_1 ( V_2 , 0x0B03 , 0x0A ) ;
F_1 ( V_2 , 0x0935 , 0x10 ) ;
F_1 ( V_2 , 0x0936 , 0x08 ) ;
F_1 ( V_2 , 0x093E , 0x08 ) ;
F_1 ( V_2 , 0x096E , 0x06 ) ;
F_1 ( V_2 , 0x0B09 , 0x00 ) ;
F_1 ( V_2 , 0x0B0A , 0x08 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
const struct V_48 * V_49 = V_2 -> V_15 ;
F_1 ( V_2 , V_50 , V_49 -> V_51 ? 1 : 0 ) ;
F_1 ( V_2 , V_52 , V_49 -> V_51 ? 1 : 0 ) ;
F_1 ( V_2 , V_53 ,
V_49 -> V_54 ? 1 : 0 ) ;
F_1 ( V_2 , V_55 ,
V_49 -> V_56 ? 0 : 1 ) ;
return 0 ;
}
static int F_13 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
const struct V_48 * V_49 = V_2 -> V_15 ;
F_6 ( V_2 , V_49 -> V_31 ) ;
F_8 ( V_2 , V_49 -> V_60 ) ;
F_10 ( V_2 , V_49 -> V_61 , V_49 -> V_62 ,
V_49 -> V_63 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
F_1 ( V_2 , 0x000A , 0 ) ;
F_1 ( V_2 , 0x020C , 11 ) ;
F_1 ( V_2 , V_64 , 1 ) ;
return 0 ;
}
static void F_14 ( struct V_57 * V_58 )
{
struct V_1 * V_65 = V_58 -> V_59 ;
F_2 ( L_3 , V_19 ) ;
F_15 ( V_65 ) ;
}
static int F_16 ( struct V_57 * V_58 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
int V_47 ;
T_2 V_38 = 0 ;
F_2 ( L_3 , V_19 ) ;
if ( V_58 -> V_68 . V_69 . V_70 ) {
if ( V_58 -> V_68 . V_71 )
V_58 -> V_68 . V_71 ( V_58 , 1 ) ;
V_58 -> V_68 . V_69 . V_70 ( V_58 , V_67 ) ;
if ( V_58 -> V_68 . V_71 )
V_58 -> V_68 . V_71 ( V_58 , 0 ) ;
}
for ( V_47 = 0 ; V_47 < 10 ; V_47 ++ ) {
F_17 ( 100 ) ;
F_2 ( L_4 , V_47 ) ;
F_9 ( V_2 , & V_38 ) ;
if ( V_38 != 0 ) {
F_2 ( L_5 ) ;
break;
}
}
return 0 ;
}
static int F_18 ( struct V_57 * V_58 ,
struct V_66 * V_67 )
{
F_2 ( L_3 , V_19 ) ;
V_67 -> V_72 = V_73 ;
V_67 -> V_74 . V_75 . V_76 = V_77 ;
V_67 -> V_74 . V_75 . V_78 = V_79 ;
V_67 -> V_74 . V_75 . V_80 = V_79 ;
V_67 -> V_74 . V_75 . V_81 = V_82 ;
V_67 -> V_74 . V_75 . V_83 = V_84 ;
V_67 -> V_74 . V_75 . V_85 = V_86 ;
V_67 -> V_74 . V_75 . V_87 = V_88 ;
return 0 ;
}
static int F_19 ( struct V_57 * V_58 ,
struct V_89 * V_90 )
{
V_90 -> V_91 = 0 ;
V_90 -> V_92 = 0 ;
V_90 -> V_93 = 0 ;
return 0 ;
}
static int F_20 ( struct V_57 * V_58 , T_5 * V_94 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
T_2 V_38 = 0 ;
T_2 V_95 = 0 ;
F_2 ( L_3 , V_19 ) ;
* V_94 = 0 ;
F_9 ( V_2 , & V_38 ) ;
if ( V_38 ) {
* V_94 |= V_96 | V_97 |
V_98 | V_99 | V_100 ;
}
F_2 ( L_6 , V_19 , * V_94 ) ;
F_4 ( V_2 , V_101 , & V_95 ) ;
F_2 ( L_7 , V_95 ) ;
return 0 ;
}
static int F_21 ( struct V_57 * V_58 , T_3 * V_102 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
T_3 V_103 ;
T_2 V_28 ;
F_2 ( L_3 , V_19 ) ;
F_5 ( V_2 , 1 ) ;
F_4 ( V_2 , V_104 + 1 , & V_28 ) ;
V_103 = V_28 & 0x7F ;
V_103 <<= 8 ;
F_4 ( V_2 , V_104 , & V_28 ) ;
V_103 |= V_28 ;
F_5 ( V_2 , 0 ) ;
* V_102 = V_103 * 100 / 32767 ;
F_2 ( L_8 , V_19 , * V_102 ) ;
return 0 ;
}
static int F_22 ( struct V_57 * V_58 , T_1 * signal )
{
struct V_1 * V_2 = V_58 -> V_59 ;
T_3 V_105 ;
T_2 V_28 ;
F_2 ( L_3 , V_19 ) ;
F_5 ( V_2 , 1 ) ;
F_4 ( V_2 , V_106 + 1 , & V_28 ) ;
V_105 = V_28 & 0x03 ;
V_105 <<= 8 ;
F_4 ( V_2 , V_106 , & V_28 ) ;
V_105 |= V_28 ;
F_5 ( V_2 , 0 ) ;
F_2 ( L_9 , V_105 ) ;
V_105 = 0x400 - V_105 ;
* signal = V_105 * 0x10000 / 0x400 ;
return 0 ;
}
static int F_23 ( struct V_57 * V_58 , T_1 * V_107 )
{
F_2 ( L_3 , V_19 ) ;
* V_107 = 0 ;
return 0 ;
}
static int F_24 ( struct V_57 * V_58 , T_3 * V_108 )
{
F_2 ( L_3 , V_19 ) ;
* V_108 = 0 ;
return 0 ;
}
static int F_25 ( struct V_57 * V_58 , int V_109 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
return F_1 ( V_2 , V_110 , V_109 ? 1 : 0 ) ;
}
struct V_57 * F_26 ( const struct V_48 * V_15 ,
struct V_111 * V_20 )
{
struct V_1 * V_2 = NULL ;
T_2 V_4 = 0 ;
F_2 ( L_10 , V_19 ) ;
if ( V_15 == NULL || V_20 == NULL )
return NULL ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_112 ) ;
if ( V_2 == NULL )
goto V_113;
V_2 -> V_15 = V_15 ;
V_2 -> V_20 = V_20 ;
if ( F_4 ( V_2 , V_114 , & V_4 ) != 0 ) {
F_2 ( L_11 ,
V_19 , V_2 -> V_15 -> V_16 ) ;
goto V_113;
}
F_2 ( L_12 , V_4 ) ;
memcpy ( & V_2 -> V_115 . V_68 , & V_116 ,
sizeof( struct V_117 ) ) ;
V_2 -> V_115 . V_59 = V_2 ;
F_13 ( & V_2 -> V_115 ) ;
F_25 ( & V_2 -> V_115 , 1 ) ;
return & V_2 -> V_115 ;
V_113:
F_2 ( L_13 , V_19 ) ;
F_15 ( V_2 ) ;
return NULL ;
}
