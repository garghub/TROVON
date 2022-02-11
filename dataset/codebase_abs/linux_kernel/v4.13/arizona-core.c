int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
V_1 -> V_4 ++ ;
if ( V_1 -> V_4 == 1 ) {
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
V_2 = F_3 ( V_1 -> V_8 ) ;
if ( V_2 != 0 )
goto V_9;
V_2 = F_4 ( V_1 -> V_10 [ V_11 ] ) ;
if ( V_2 != 0 )
goto V_12;
break;
case V_13 :
V_2 = F_4 ( V_1 -> V_10 [ V_14 ] ) ;
if ( V_2 != 0 )
goto V_9;
break;
}
V_2 = F_5 ( V_1 -> V_15 , V_16 ,
V_17 ,
V_17 ) ;
}
V_12:
F_6 ( V_1 -> V_8 ) ;
V_9:
if ( V_2 != 0 )
V_1 -> V_4 -- ;
F_7 ( & V_1 -> V_3 ) ;
return V_2 ;
}
int F_8 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_3 ) ;
F_9 ( V_1 -> V_4 <= 0 ) ;
V_1 -> V_4 -- ;
if ( V_1 -> V_4 == 0 ) {
F_5 ( V_1 -> V_15 , V_16 ,
V_17 , 0 ) ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
F_6 ( V_1 -> V_8 ) ;
F_10 ( V_1 -> V_10 [ V_11 ] ) ;
break;
case V_13 :
F_10 ( V_1 -> V_10 [ V_14 ] ) ;
break;
}
}
F_7 ( & V_1 -> V_3 ) ;
return 0 ;
}
static T_1 F_11 ( int V_18 , void * V_19 )
{
struct V_1 * V_1 = V_19 ;
F_12 ( V_1 -> V_8 , L_1 ) ;
return V_20 ;
}
static T_1 F_13 ( int V_18 , void * V_19 )
{
struct V_1 * V_1 = V_19 ;
unsigned int V_21 ;
int V_2 ;
V_2 = F_14 ( V_1 -> V_15 , V_22 ,
& V_21 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_2 ,
V_2 ) ;
return V_23 ;
}
if ( V_21 & V_24 )
F_12 ( V_1 -> V_8 , L_3 ) ;
if ( V_21 & V_25 )
F_12 ( V_1 -> V_8 , L_4 ) ;
if ( V_21 & V_26 )
F_12 ( V_1 -> V_8 , L_5 ) ;
if ( V_21 & V_27 )
F_12 ( V_1 -> V_8 , L_6 ) ;
if ( V_21 & V_28 )
F_12 ( V_1 -> V_8 , L_7 ) ;
if ( V_21 & V_29 )
F_12 ( V_1 -> V_8 , L_8 ) ;
if ( V_21 & V_30 )
F_12 ( V_1 -> V_8 , L_9 ) ;
if ( V_21 & V_31 )
F_12 ( V_1 -> V_8 , L_10 ) ;
if ( V_21 & V_32 )
F_12 ( V_1 -> V_8 , L_11 ) ;
if ( V_21 & V_33 )
F_12 ( V_1 -> V_8 , L_12 ) ;
if ( V_21 & V_34 )
F_12 ( V_1 -> V_8 , L_13 ) ;
return V_20 ;
}
static T_1 F_15 ( int V_18 , void * V_19 )
{
struct V_1 * V_1 = V_19 ;
unsigned int V_21 [ 3 ] ;
int V_2 ;
V_2 = F_16 ( V_1 -> V_15 , V_35 ,
& V_21 [ 0 ] , 3 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_14 ,
V_2 ) ;
return V_23 ;
}
switch ( V_1 -> type ) {
case V_36 :
case V_37 :
V_21 [ 0 ] = ( ( V_21 [ 0 ] & 0x60e0 ) >> 1 ) |
( ( V_21 [ 0 ] & 0x1e00 ) >> 2 ) |
( V_21 [ 0 ] & 0x000f ) ;
break;
default:
break;
}
if ( V_21 [ 0 ] & V_38 )
F_12 ( V_1 -> V_8 , L_15 ) ;
if ( V_21 [ 0 ] & V_39 )
F_12 ( V_1 -> V_8 , L_16 ) ;
if ( V_21 [ 0 ] & V_40 )
F_12 ( V_1 -> V_8 , L_17 ) ;
if ( V_21 [ 0 ] & V_41 )
F_12 ( V_1 -> V_8 , L_18 ) ;
if ( V_21 [ 0 ] & V_42 )
F_12 ( V_1 -> V_8 , L_19 ) ;
if ( V_21 [ 0 ] & V_43 )
F_12 ( V_1 -> V_8 , L_20 ) ;
if ( V_21 [ 0 ] & V_44 )
F_12 ( V_1 -> V_8 , L_21 ) ;
if ( V_21 [ 0 ] & V_45 )
F_12 ( V_1 -> V_8 , L_22 ) ;
if ( V_21 [ 0 ] & V_46 )
F_12 ( V_1 -> V_8 , L_23 ) ;
if ( V_21 [ 0 ] & V_47 )
F_12 ( V_1 -> V_8 , L_24 ) ;
if ( V_21 [ 1 ] & V_48 )
F_12 ( V_1 -> V_8 , L_25 ) ;
if ( V_21 [ 1 ] & V_49 )
F_12 ( V_1 -> V_8 , L_26 ) ;
if ( V_21 [ 1 ] & V_50 )
F_12 ( V_1 -> V_8 , L_27 ) ;
if ( V_21 [ 1 ] & V_51 )
F_12 ( V_1 -> V_8 , L_28 ) ;
if ( V_21 [ 1 ] & V_52 )
F_12 ( V_1 -> V_8 , L_29 ) ;
if ( V_21 [ 1 ] & V_53 )
F_12 ( V_1 -> V_8 , L_30 ) ;
if ( V_21 [ 1 ] & V_54 )
F_12 ( V_1 -> V_8 , L_31 ) ;
if ( V_21 [ 1 ] & V_55 )
F_12 ( V_1 -> V_8 , L_32 ) ;
if ( V_21 [ 1 ] & V_56 )
F_12 ( V_1 -> V_8 , L_33 ) ;
if ( V_21 [ 1 ] & V_57 )
F_12 ( V_1 -> V_8 , L_34 ) ;
if ( V_21 [ 1 ] & V_58 )
F_12 ( V_1 -> V_8 , L_35 ) ;
if ( V_21 [ 2 ] & V_59 )
F_12 ( V_1 -> V_8 , L_36 ) ;
return V_20 ;
}
static int F_17 ( struct V_1 * V_1 ,
int V_60 , unsigned int V_61 ,
unsigned int V_62 , unsigned int V_63 )
{
unsigned int V_21 = 0 ;
int V_2 ;
V_2 = F_18 ( V_1 -> V_15 ,
V_61 , V_21 , ( ( V_21 & V_62 ) == V_63 ) ,
V_64 ,
V_60 * 1000 ) ;
if ( V_2 )
F_12 ( V_1 -> V_8 , L_37 ,
V_61 , V_21 ) ;
return V_2 ;
}
static int F_19 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_17 ( V_1 , 30 , V_65 ,
V_66 , V_66 ) ;
if ( ! V_2 )
F_20 ( V_1 -> V_15 , V_67 ,
V_66 ) ;
F_21 ( V_1 -> V_8 ) ;
return V_2 ;
}
static inline void F_22 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 . V_68 )
F_23 ( V_1 -> V_5 . V_68 , 0 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 . V_68 ) {
switch ( V_1 -> type ) {
case V_69 :
case V_70 :
F_25 ( 5000 , 10000 ) ;
break;
default:
break;
}
F_23 ( V_1 -> V_5 . V_68 , 1 ) ;
F_25 ( 1000 , 5000 ) ;
}
}
static int F_26 ( struct V_1 * V_1 ,
struct V_71 * V_72 )
{
int V_2 , V_73 ;
V_2 = F_14 ( V_1 -> V_15 , V_74 , & V_72 -> V_75 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_38 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_14 ( V_1 -> V_15 , V_76 ,
& V_72 -> V_77 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_39 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_20 ( V_1 -> V_15 , V_74 ,
V_78 | V_79 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_40 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_17 ( V_1 , 180 , V_65 ,
V_80 ,
V_80 ) ;
if ( V_2 )
goto V_81;
V_2 = F_20 ( V_1 -> V_15 , V_76 , 0x0144 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_41 , V_2 ) ;
goto V_81;
}
return 0 ;
V_81:
V_73 = F_20 ( V_1 -> V_15 , V_74 , V_72 -> V_75 ) ;
if ( V_73 )
F_12 ( V_1 -> V_8 ,
L_42 , V_73 ) ;
return V_2 ;
}
static int F_27 ( struct V_1 * V_1 ,
struct V_71 * V_72 )
{
int V_2 ;
V_2 = F_20 ( V_1 -> V_15 , V_76 ,
V_72 -> V_77 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_43 , V_2 ) ;
return V_2 ;
}
V_2 = F_20 ( V_1 -> V_15 , V_74 , V_72 -> V_75 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_42 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_71 V_72 ;
int V_73 , V_2 ;
V_2 = F_26 ( V_1 , & V_72 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_20 ( V_1 -> V_15 , V_82 ,
V_83 | V_84 | 160 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_44 ,
V_2 ) ;
goto V_73;
}
V_2 = F_17 ( V_1 , 30 , V_85 ,
V_86 , 0 ) ;
if ( V_2 )
F_20 ( V_1 -> V_15 , V_82 ,
V_87 ) ;
V_73:
V_73 = F_27 ( V_1 , & V_72 ) ;
return V_2 ? : V_73 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_71 V_72 ;
int V_73 , V_2 ;
V_2 = F_26 ( V_1 , & V_72 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_30 ( V_1 -> V_15 ,
V_88 ,
F_31 ( V_88 ) ) ;
V_73 = F_27 ( V_1 , & V_72 ) ;
return V_2 ? : V_73 ;
}
static int F_32 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_20 ( V_1 -> V_15 , V_89 ,
0x0 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_45 , V_2 ) ;
return V_2 ;
}
F_22 ( V_1 ) ;
F_33 ( V_1 -> V_90 ) ;
F_34 ( 20 ) ;
V_2 = F_35 ( V_1 -> V_90 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_46 , V_2 ) ;
return V_2 ;
}
F_24 ( V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_5 ( V_1 -> V_15 ,
V_91 ,
V_92 ,
V_92 ) ;
if ( V_2 != 0 )
F_12 ( V_1 -> V_8 , L_47 , V_2 ) ;
return V_2 ;
}
static int F_37 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_5 ( V_1 -> V_15 ,
V_91 ,
V_92 , 0 ) ;
if ( V_2 != 0 )
F_12 ( V_1 -> V_8 , L_48 , V_2 ) ;
return V_2 ;
}
static int F_38 ( struct V_1 * V_1 )
{
unsigned int V_21 ;
int V_2 ;
V_2 = F_14 ( V_1 -> V_15 , V_93 , & V_21 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_49 , V_2 ) ;
return V_2 ;
} else if ( V_21 & V_94 ) {
return 1 ;
} else {
return 0 ;
}
}
static int F_39 ( struct V_95 * V_8 )
{
struct V_1 * V_1 = F_40 ( V_8 ) ;
int V_2 ;
F_41 ( V_1 -> V_8 , L_50 ) ;
if ( V_1 -> V_96 ) {
F_41 ( V_1 -> V_8 , L_51 ) ;
V_2 = F_42 ( V_1 -> V_97 ,
V_1 -> V_98 ) ;
if ( V_2 ) {
F_12 ( V_8 , L_52 ,
V_2 ) ;
return V_2 ;
}
}
V_2 = F_35 ( V_1 -> V_90 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_53 , V_2 ) ;
if ( V_1 -> V_96 )
F_43 ( V_1 -> V_97 ,
V_1 -> V_98 ) ;
return V_2 ;
}
if ( V_1 -> V_96 ) {
F_24 ( V_1 ) ;
F_44 ( V_1 -> V_18 ) ;
V_1 -> V_96 = false ;
}
F_45 ( V_1 -> V_15 , false ) ;
switch ( V_1 -> type ) {
case V_99 :
if ( V_1 -> V_100 ) {
V_2 = F_37 ( V_1 ) ;
if ( V_2 != 0 )
goto V_73;
}
V_2 = F_46 ( V_1 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_54 ,
V_2 ) ;
goto V_73;
}
V_2 = F_28 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_55 ,
V_2 ) ;
goto V_73;
}
break;
case V_69 :
case V_70 :
V_2 = F_19 ( V_1 ) ;
if ( V_2 )
goto V_73;
if ( V_1 -> V_100 ) {
V_2 = F_37 ( V_1 ) ;
if ( V_2 != 0 )
goto V_73;
} else {
V_2 = F_47 ( V_1 -> V_90 ,
1200000 , 1200000 ) ;
if ( V_2 < 0 ) {
F_12 ( V_1 -> V_8 ,
L_56 ,
V_2 ) ;
goto V_73;
}
}
V_2 = F_29 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_57 ,
V_2 ) ;
goto V_73;
}
break;
case V_101 :
case V_102 :
V_2 = F_19 ( V_1 ) ;
if ( V_2 != 0 )
goto V_73;
break;
default:
V_2 = F_19 ( V_1 ) ;
if ( V_2 != 0 )
goto V_73;
if ( V_1 -> V_100 ) {
V_2 = F_37 ( V_1 ) ;
if ( V_2 != 0 )
goto V_73;
}
break;
}
V_2 = F_48 ( V_1 -> V_15 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_58 ) ;
goto V_73;
}
return 0 ;
V_73:
F_45 ( V_1 -> V_15 , true ) ;
F_33 ( V_1 -> V_90 ) ;
return V_2 ;
}
static int F_49 ( struct V_95 * V_8 )
{
struct V_1 * V_1 = F_40 ( V_8 ) ;
int V_103 = 0 ;
int V_2 ;
F_41 ( V_1 -> V_8 , L_59 ) ;
switch ( V_1 -> type ) {
case V_69 :
case V_70 :
V_103 = F_38 ( V_1 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( V_1 -> V_100 ) {
V_2 = F_36 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
} else {
V_2 = F_47 ( V_1 -> V_90 ,
1175000 , 1175000 ) ;
if ( V_2 < 0 ) {
F_12 ( V_1 -> V_8 ,
L_60 ,
V_2 ) ;
return V_2 ;
}
}
break;
case V_99 :
V_103 = F_38 ( V_1 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( V_1 -> V_100 ) {
V_2 = F_36 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
}
if ( ! V_103 ) {
V_2 = F_20 ( V_1 -> V_15 ,
V_89 , 0x0 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_61 ,
V_2 ) ;
return V_2 ;
}
}
break;
case V_101 :
case V_102 :
break;
default:
V_103 = F_38 ( V_1 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( V_1 -> V_100 ) {
V_2 = F_36 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
}
break;
}
F_45 ( V_1 -> V_15 , true ) ;
F_50 ( V_1 -> V_15 ) ;
F_33 ( V_1 -> V_90 ) ;
if ( ! V_103 ) {
F_41 ( V_1 -> V_8 , L_62 ) ;
V_1 -> V_96 = true ;
F_51 ( V_1 -> V_18 ) ;
F_22 ( V_1 ) ;
F_43 ( V_1 -> V_97 ,
V_1 -> V_98 ) ;
}
return 0 ;
}
static int F_52 ( struct V_95 * V_8 )
{
struct V_1 * V_1 = F_40 ( V_8 ) ;
F_41 ( V_1 -> V_8 , L_63 ) ;
F_53 ( V_1 -> V_18 ) ;
return 0 ;
}
static int F_54 ( struct V_95 * V_8 )
{
struct V_1 * V_1 = F_40 ( V_8 ) ;
F_41 ( V_1 -> V_8 , L_64 ) ;
F_44 ( V_1 -> V_18 ) ;
return 0 ;
}
static int F_55 ( struct V_95 * V_8 )
{
struct V_1 * V_1 = F_40 ( V_8 ) ;
F_41 ( V_1 -> V_8 , L_65 ) ;
F_53 ( V_1 -> V_18 ) ;
return 0 ;
}
static int F_56 ( struct V_95 * V_8 )
{
struct V_1 * V_1 = F_40 ( V_8 ) ;
F_41 ( V_1 -> V_8 , L_66 ) ;
F_44 ( V_1 -> V_18 ) ;
return 0 ;
}
unsigned long F_57 ( struct V_95 * V_8 )
{
const struct V_104 * V_105 = F_58 ( V_106 , V_8 ) ;
if ( V_105 )
return ( unsigned long ) V_105 -> V_19 ;
else
return 0 ;
}
static int F_59 ( struct V_1 * V_1 )
{
struct V_107 * V_5 = & V_1 -> V_5 ;
struct V_108 * V_109 ;
const T_2 * V_110 ;
T_3 V_21 ;
T_3 V_111 [ V_112 ] ;
int V_2 , V_113 ;
int V_114 = 0 ;
V_5 -> V_68 = F_60 ( V_1 -> V_8 -> V_115 , L_67 , 0 ) ;
if ( V_5 -> V_68 == - V_116 ) {
return V_5 -> V_68 ;
} else if ( V_5 -> V_68 < 0 ) {
F_12 ( V_1 -> V_8 , L_68 ,
V_5 -> V_68 ) ;
V_5 -> V_68 = 0 ;
}
V_2 = F_61 ( V_1 -> V_8 -> V_115 ,
L_69 ,
V_5 -> V_117 ,
F_31 ( V_5 -> V_117 ) ) ;
if ( V_2 >= 0 ) {
for ( V_113 = 0 ; V_113 < F_31 ( V_5 -> V_117 ) ; V_113 ++ ) {
if ( V_5 -> V_117 [ V_113 ] > 0xffff )
V_5 -> V_117 [ V_113 ] = 0 ;
else if ( V_5 -> V_117 [ V_113 ] == 0 )
V_5 -> V_117 [ V_113 ] = 0x10000 ;
}
} else {
F_12 ( V_1 -> V_8 , L_70 ,
V_2 ) ;
}
F_62 (arizona->dev->of_node, L_71 , prop,
cur, val) {
if ( V_114 == F_31 ( V_5 -> V_118 ) )
break;
V_5 -> V_118 [ V_114 ] = V_21 ;
V_114 ++ ;
}
V_114 = 0 ;
F_62 (arizona->dev->of_node, L_72 , prop,
cur, val) {
if ( V_114 == F_31 ( V_5 -> V_119 ) )
break;
V_5 -> V_119 [ V_114 ] = V_21 ;
V_114 ++ ;
}
V_114 = 0 ;
F_62 (arizona->dev->of_node, L_73 , prop,
cur, val) {
if ( V_114 == F_31 ( V_5 -> V_120 ) )
break;
V_5 -> V_120 [ V_114 ] = ! ! V_21 ;
V_114 ++ ;
}
V_114 = 0 ;
F_62 (arizona->dev->of_node,
L_74 ,
prop, cur, val) {
if ( V_114 == F_31 ( V_5 -> V_121 ) )
break;
V_5 -> V_121 [ V_114 ] = V_21 ;
V_114 ++ ;
}
V_2 = F_61 ( V_1 -> V_8 -> V_115 ,
L_75 ,
V_111 ,
F_31 ( V_111 ) ) ;
if ( V_2 >= 0 )
for ( V_114 = 0 ; V_114 < F_31 ( V_5 -> V_122 ) ; ++ V_114 )
V_5 -> V_122 [ V_114 ] = V_111 [ V_114 ] ;
V_2 = F_61 ( V_1 -> V_8 -> V_115 ,
L_76 ,
V_111 ,
F_31 ( V_111 ) ) ;
if ( V_2 >= 0 )
for ( V_114 = 0 ; V_114 < F_31 ( V_5 -> V_123 ) ; ++ V_114 )
V_5 -> V_123 [ V_114 ] = V_111 [ V_114 ] ;
return 0 ;
}
static inline int F_59 ( struct V_1 * V_1 )
{
return 0 ;
}
int F_63 ( struct V_1 * V_1 )
{
const char * const V_124 [] = { L_77 , L_78 } ;
struct V_95 * V_8 = V_1 -> V_8 ;
const char * V_125 = NULL ;
unsigned int V_61 , V_21 , V_62 ;
int (* F_64)( struct V_1 * ) = NULL ;
const struct V_126 * V_127 = NULL ;
int V_128 , V_2 , V_113 ;
F_65 ( V_1 -> V_8 , V_1 ) ;
F_66 ( & V_1 -> V_3 ) ;
if ( F_67 ( V_1 -> V_8 ) ) {
memcpy ( & V_1 -> V_5 , F_67 ( V_1 -> V_8 ) ,
sizeof( V_1 -> V_5 ) ) ;
} else {
V_2 = F_59 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
}
F_68 ( F_31 ( V_1 -> V_10 ) != F_31 ( V_124 ) ) ;
for ( V_113 = 0 ; V_113 < F_31 ( V_1 -> V_10 ) ; V_113 ++ ) {
V_1 -> V_10 [ V_113 ] = F_69 ( V_1 -> V_8 , V_124 [ V_113 ] ) ;
if ( F_70 ( V_1 -> V_10 [ V_113 ] ) ) {
F_71 ( V_1 -> V_8 , L_79 ,
V_124 [ V_113 ] , F_72 ( V_1 -> V_10 [ V_113 ] ) ) ;
V_1 -> V_10 [ V_113 ] = NULL ;
}
}
F_45 ( V_1 -> V_15 , true ) ;
switch ( V_1 -> type ) {
case V_99 :
case V_69 :
case V_70 :
case V_129 :
case V_36 :
case V_37 :
case V_101 :
case V_102 :
for ( V_113 = 0 ; V_113 < F_31 ( V_130 ) ; V_113 ++ )
V_1 -> V_98 [ V_113 ] . V_131
= V_130 [ V_113 ] ;
V_1 -> V_97 = F_31 ( V_130 ) ;
break;
default:
F_12 ( V_1 -> V_8 , L_80 ,
V_1 -> type ) ;
return - V_132 ;
}
V_1 -> V_100 = true ;
switch ( V_1 -> type ) {
case V_101 :
case V_102 :
break;
default:
V_2 = F_73 ( V_1 -> V_8 , - 1 , V_133 ,
F_31 ( V_133 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_81 , V_2 ) ;
return V_2 ;
}
break;
}
V_2 = F_74 ( V_8 , V_1 -> V_97 ,
V_1 -> V_98 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_82 ,
V_2 ) ;
goto V_134;
}
V_1 -> V_90 = F_75 ( V_1 -> V_8 , L_83 ) ;
if ( F_70 ( V_1 -> V_90 ) ) {
V_2 = F_72 ( V_1 -> V_90 ) ;
F_12 ( V_8 , L_84 , V_2 ) ;
goto V_134;
}
if ( V_1 -> V_5 . V_68 ) {
V_2 = F_76 ( V_1 -> V_8 , V_1 -> V_5 . V_68 ,
V_135 | V_136 ,
L_85 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_86 , V_2 ) ;
goto V_137;
}
}
V_2 = F_42 ( V_1 -> V_97 ,
V_1 -> V_98 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_52 ,
V_2 ) ;
goto V_137;
}
V_2 = F_35 ( V_1 -> V_90 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_53 , V_2 ) ;
goto V_138;
}
F_24 ( V_1 ) ;
F_45 ( V_1 -> V_15 , false ) ;
V_2 = F_14 ( V_1 -> V_15 , V_139 , & V_61 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_87 , V_2 ) ;
goto V_140;
}
switch ( V_61 ) {
case 0x5102 :
case 0x5110 :
case 0x6349 :
case 0x6363 :
case 0x8997 :
break;
default:
F_12 ( V_1 -> V_8 , L_88 , V_61 ) ;
V_2 = - V_132 ;
goto V_140;
}
if ( ! V_1 -> V_5 . V_68 ) {
V_2 = F_20 ( V_1 -> V_15 , V_139 , 0 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_89 , V_2 ) ;
goto V_140;
}
F_25 ( 1000 , 5000 ) ;
}
switch ( V_1 -> type ) {
case V_99 :
V_2 = F_14 ( V_1 -> V_15 ,
V_89 , & V_21 ) ;
if ( V_2 ) {
F_12 ( V_8 ,
L_90 ,
V_2 ) ;
} else if ( V_21 & 0x01 ) {
V_2 = F_32 ( V_1 ) ;
if ( V_2 )
return V_2 ;
}
break;
default:
break;
}
V_2 = F_19 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_91 , V_2 ) ;
goto V_140;
}
V_2 = F_14 ( V_1 -> V_15 , V_139 , & V_61 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_87 , V_2 ) ;
goto V_140;
}
V_2 = F_14 ( V_1 -> V_15 , V_141 ,
& V_1 -> V_142 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_92 , V_2 ) ;
goto V_140;
}
V_1 -> V_142 &= V_143 ;
switch ( V_61 ) {
case 0x5102 :
if ( F_77 ( V_144 ) ) {
V_125 = L_93 ;
if ( V_1 -> type != V_99 ) {
F_78 ( V_1 -> V_8 ,
L_94 ,
V_1 -> type ) ;
V_1 -> type = V_99 ;
}
F_64 = F_46 ;
V_1 -> V_142 &= 0x7 ;
V_127 = V_145 ;
V_128 = F_31 ( V_145 ) ;
}
break;
case 0x5110 :
if ( F_77 ( V_146 ) ) {
switch ( V_1 -> type ) {
case V_69 :
V_125 = L_95 ;
break;
case V_70 :
V_125 = L_96 ;
break;
default:
V_125 = L_95 ;
F_78 ( V_1 -> V_8 ,
L_97 ,
V_1 -> type ) ;
V_1 -> type = V_69 ;
break;
}
F_64 = V_147 ;
V_127 = V_148 ;
V_128 = F_31 ( V_148 ) ;
}
break;
case 0x6363 :
if ( F_77 ( V_149 ) ) {
switch ( V_1 -> type ) {
case V_102 :
V_125 = L_98 ;
break;
case V_101 :
V_125 = L_99 ;
break;
default:
F_78 ( V_1 -> V_8 ,
L_100 ,
V_1 -> type ) ;
V_1 -> type = V_102 ;
break;
}
F_64 = V_150 ;
V_127 = V_151 ;
V_128 = F_31 ( V_151 ) ;
}
break;
case 0x8997 :
if ( F_77 ( V_152 ) ) {
V_125 = L_101 ;
if ( V_1 -> type != V_129 ) {
F_78 ( V_1 -> V_8 ,
L_102 ,
V_1 -> type ) ;
V_1 -> type = V_129 ;
}
F_64 = V_153 ;
V_127 = V_154 ;
V_128 = F_31 ( V_154 ) ;
}
break;
case 0x6349 :
if ( F_77 ( V_155 ) ) {
switch ( V_1 -> type ) {
case V_36 :
V_125 = L_103 ;
break;
case V_37 :
V_125 = L_104 ;
break;
default:
V_125 = L_103 ;
F_78 ( V_1 -> V_8 ,
L_105 ,
V_1 -> type ) ;
V_1 -> type = V_36 ;
}
F_64 = V_156 ;
V_127 = V_157 ;
V_128 = F_31 ( V_157 ) ;
}
break;
default:
F_12 ( V_1 -> V_8 , L_106 , V_61 ) ;
V_2 = - V_132 ;
goto V_140;
}
if ( ! V_127 ) {
F_12 ( V_1 -> V_8 ,
L_107 , V_61 ) ;
V_2 = - V_132 ;
goto V_140;
}
F_71 ( V_8 , L_108 , V_125 , V_1 -> V_142 + 'A' ) ;
if ( F_64 ) {
V_2 = F_64 ( V_1 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_54 ,
V_2 ) ;
goto V_140;
}
switch ( V_1 -> type ) {
case V_99 :
V_2 = F_28 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_55 ,
V_2 ) ;
goto V_140;
}
break;
case V_69 :
case V_70 :
V_2 = F_29 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_109 ,
V_2 ) ;
goto V_140;
}
break;
default:
break;
}
}
for ( V_113 = 0 ; V_113 < F_31 ( V_1 -> V_5 . V_117 ) ; V_113 ++ ) {
if ( ! V_1 -> V_5 . V_117 [ V_113 ] )
continue;
F_20 ( V_1 -> V_15 , V_158 + V_113 ,
V_1 -> V_5 . V_117 [ V_113 ] ) ;
}
if ( ! V_1 -> V_5 . V_6 )
V_1 -> V_5 . V_6 = V_13 ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
case V_13 :
F_5 ( V_1 -> V_15 , V_16 ,
V_159 ,
V_1 -> V_5 . V_6 - 1 ) ;
F_1 ( V_1 ) ;
break;
case V_160 :
F_5 ( V_1 -> V_15 , V_16 ,
V_159 , 2 ) ;
break;
default:
F_12 ( V_1 -> V_8 , L_110 ,
V_1 -> V_5 . V_6 ) ;
V_2 = - V_161 ;
goto V_140;
}
for ( V_113 = 0 ; V_113 < V_162 ; V_113 ++ ) {
if ( ! V_1 -> V_5 . V_163 [ V_113 ] . V_164 &&
! V_1 -> V_5 . V_163 [ V_113 ] . V_165 )
continue;
if ( ! V_1 -> V_5 . V_163 [ V_113 ] . V_164 )
V_1 -> V_5 . V_163 [ V_113 ] . V_164 = 2800 ;
V_21 = ( V_1 -> V_5 . V_163 [ V_113 ] . V_164 - 1500 ) / 100 ;
V_21 <<= V_166 ;
if ( V_1 -> V_5 . V_163 [ V_113 ] . V_167 )
V_21 |= V_168 ;
if ( V_1 -> V_5 . V_163 [ V_113 ] . V_169 )
V_21 |= V_170 ;
if ( V_1 -> V_5 . V_163 [ V_113 ] . V_171 )
V_21 |= V_172 ;
if ( V_1 -> V_5 . V_163 [ V_113 ] . V_165 )
V_21 |= V_173 ;
F_5 ( V_1 -> V_15 ,
V_174 + V_113 ,
V_175 |
V_168 |
V_170 |
V_173 |
V_172 , V_21 ) ;
}
for ( V_113 = 0 ; V_113 < V_176 ; V_113 ++ ) {
V_21 = V_1 -> V_5 . V_119 [ V_113 ]
<< V_177 ;
if ( V_1 -> V_5 . V_118 [ V_113 ] & V_178 )
V_21 |= 1 << V_179 ;
switch ( V_1 -> type ) {
case V_36 :
case V_37 :
F_5 ( V_1 -> V_15 ,
V_180 + ( V_113 * 8 ) ,
V_181 ,
( V_1 -> V_5 . V_118 [ V_113 ] & V_182 )
<< V_183 ) ;
F_5 ( V_1 -> V_15 ,
V_184 + ( V_113 * 8 ) ,
V_185 ,
( V_1 -> V_5 . V_118 [ V_113 ] & V_182 )
<< V_186 ) ;
V_62 = V_187 |
V_188 ;
break;
default:
if ( V_1 -> V_5 . V_118 [ V_113 ] & V_182 )
V_21 |= 1 << V_189 ;
V_62 = V_187 |
V_188 |
V_190 ;
break;
}
F_5 ( V_1 -> V_15 ,
V_191 + ( V_113 * 8 ) ,
V_62 , V_21 ) ;
}
for ( V_113 = 0 ; V_113 < V_192 ; V_113 ++ ) {
if ( V_1 -> V_5 . V_120 [ V_113 ] )
V_21 = V_193 ;
else
V_21 = 0 ;
F_5 ( V_1 -> V_15 ,
V_194 + ( V_113 * 8 ) ,
V_193 , V_21 ) ;
}
for ( V_113 = 0 ; V_113 < V_112 ; V_113 ++ ) {
if ( V_1 -> V_5 . V_123 [ V_113 ] )
F_5 ( V_1 -> V_15 ,
V_195 + ( V_113 * 2 ) ,
V_196 |
V_197 ,
V_1 -> V_5 . V_123 [ V_113 ] ) ;
if ( V_1 -> V_5 . V_122 [ V_113 ] )
F_5 ( V_1 -> V_15 ,
V_198 + ( V_113 * 2 ) ,
V_199 ,
V_1 -> V_5 . V_122 [ V_113 ] ) ;
}
F_79 ( V_1 -> V_8 ) ;
F_80 ( V_1 -> V_8 ) ;
V_2 = F_81 ( V_1 ) ;
if ( V_2 != 0 )
goto V_12;
F_82 ( V_1 -> V_8 , 100 ) ;
F_83 ( V_1 -> V_8 ) ;
F_84 ( V_1 , V_200 , L_111 ,
F_11 , V_1 ) ;
F_84 ( V_1 , V_201 , L_112 ,
F_15 , V_1 ) ;
F_84 ( V_1 , V_202 , L_113 ,
F_13 , V_1 ) ;
V_2 = F_73 ( V_1 -> V_8 , V_203 ,
V_127 , V_128 , NULL , 0 , NULL ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_114 , V_2 ) ;
goto V_204;
}
return 0 ;
V_204:
F_85 ( V_1 ) ;
V_12:
F_86 ( V_1 -> V_8 ) ;
V_140:
F_22 ( V_1 ) ;
F_33 ( V_1 -> V_90 ) ;
V_138:
F_43 ( V_1 -> V_97 ,
V_1 -> V_98 ) ;
V_137:
F_87 ( V_1 -> V_90 ) ;
V_134:
F_88 ( V_8 ) ;
return V_2 ;
}
int F_89 ( struct V_1 * V_1 )
{
F_53 ( V_1 -> V_18 ) ;
F_86 ( V_1 -> V_8 ) ;
F_33 ( V_1 -> V_90 ) ;
F_87 ( V_1 -> V_90 ) ;
F_88 ( V_1 -> V_8 ) ;
F_90 ( V_1 , V_202 , V_1 ) ;
F_90 ( V_1 , V_201 , V_1 ) ;
F_90 ( V_1 , V_200 , V_1 ) ;
F_85 ( V_1 ) ;
F_22 ( V_1 ) ;
F_43 ( V_1 -> V_97 ,
V_1 -> V_98 ) ;
return 0 ;
}
