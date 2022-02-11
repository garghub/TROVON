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
int V_2 , V_64 ;
for ( V_64 = 0 ; V_64 < V_60 ; V_64 ++ ) {
V_2 = F_14 ( V_1 -> V_15 , V_61 , & V_21 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_37 ,
V_61 , V_2 ) ;
continue;
}
if ( ( V_21 & V_62 ) == V_63 )
return 0 ;
F_18 ( 1000 , 5000 ) ;
}
F_12 ( V_1 -> V_8 , L_38 , V_61 , V_21 ) ;
return - V_65 ;
}
static int F_19 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_17 ( V_1 , 5 , V_66 ,
V_67 , V_67 ) ;
if ( ! V_2 )
F_20 ( V_1 -> V_15 , V_68 ,
V_67 ) ;
F_21 ( V_1 -> V_8 ) ;
return V_2 ;
}
static inline void F_22 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 . V_69 )
F_23 ( V_1 -> V_5 . V_69 , 0 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 . V_69 ) {
switch ( V_1 -> type ) {
case V_70 :
case V_71 :
F_18 ( 5000 , 10000 ) ;
break;
default:
break;
}
F_23 ( V_1 -> V_5 . V_69 , 1 ) ;
F_18 ( 1000 , 5000 ) ;
}
}
static int F_25 ( struct V_1 * V_1 ,
struct V_72 * V_73 )
{
int V_2 , V_74 ;
V_2 = F_14 ( V_1 -> V_15 , V_75 , & V_73 -> V_76 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_39 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_14 ( V_1 -> V_15 , V_77 ,
& V_73 -> V_78 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_40 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_20 ( V_1 -> V_15 , V_75 ,
V_79 | V_80 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_41 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_17 ( V_1 , 25 , V_66 ,
V_81 ,
V_81 ) ;
if ( V_2 ) {
V_2 = - V_65 ;
goto V_82;
}
V_2 = F_20 ( V_1 -> V_15 , V_77 , 0x0144 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_42 , V_2 ) ;
goto V_82;
}
return 0 ;
V_82:
V_74 = F_20 ( V_1 -> V_15 , V_75 , V_73 -> V_76 ) ;
if ( V_74 )
F_12 ( V_1 -> V_8 ,
L_43 , V_74 ) ;
return V_2 ;
}
static int F_26 ( struct V_1 * V_1 ,
struct V_72 * V_73 )
{
int V_2 ;
V_2 = F_20 ( V_1 -> V_15 , V_77 ,
V_73 -> V_78 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_44 , V_2 ) ;
return V_2 ;
}
V_2 = F_20 ( V_1 -> V_15 , V_75 , V_73 -> V_76 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_43 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_72 V_73 ;
int V_74 , V_2 ;
V_2 = F_25 ( V_1 , & V_73 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_20 ( V_1 -> V_15 , V_83 ,
V_84 | V_85 | 160 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_45 ,
V_2 ) ;
goto V_74;
}
V_2 = F_17 ( V_1 , 5 , V_86 ,
V_87 , 0 ) ;
if ( V_2 ) {
F_20 ( V_1 -> V_15 , V_83 ,
V_88 ) ;
V_2 = - V_65 ;
}
V_74:
V_74 = F_26 ( V_1 , & V_73 ) ;
return V_2 ? : V_74 ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_72 V_73 ;
int V_74 , V_2 ;
V_2 = F_25 ( V_1 , & V_73 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_29 ( V_1 -> V_15 ,
V_89 ,
F_30 ( V_89 ) ) ;
V_74 = F_26 ( V_1 , & V_73 ) ;
return V_2 ? : V_74 ;
}
static int F_31 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_20 ( V_1 -> V_15 , V_90 ,
0x0 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_46 , V_2 ) ;
return V_2 ;
}
F_22 ( V_1 ) ;
F_32 ( V_1 -> V_91 ) ;
F_33 ( 20 ) ;
V_2 = F_34 ( V_1 -> V_91 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_47 , V_2 ) ;
return V_2 ;
}
F_24 ( V_1 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_5 ( V_1 -> V_15 ,
V_92 ,
V_93 ,
V_93 ) ;
if ( V_2 != 0 )
F_12 ( V_1 -> V_8 , L_48 , V_2 ) ;
return V_2 ;
}
static int F_36 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_5 ( V_1 -> V_15 ,
V_92 ,
V_93 , 0 ) ;
if ( V_2 != 0 )
F_12 ( V_1 -> V_8 , L_49 , V_2 ) ;
return V_2 ;
}
static int F_37 ( struct V_1 * V_1 )
{
unsigned int V_21 ;
int V_2 ;
V_2 = F_14 ( V_1 -> V_15 , V_94 , & V_21 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_50 , V_2 ) ;
return V_2 ;
} else if ( V_21 & V_95 ) {
return 1 ;
} else {
return 0 ;
}
}
static int F_38 ( struct V_96 * V_8 )
{
struct V_1 * V_1 = F_39 ( V_8 ) ;
int V_2 ;
F_40 ( V_1 -> V_8 , L_51 ) ;
if ( V_1 -> V_97 ) {
F_40 ( V_1 -> V_8 , L_52 ) ;
V_2 = F_41 ( V_1 -> V_98 ,
V_1 -> V_99 ) ;
if ( V_2 ) {
F_12 ( V_8 , L_53 ,
V_2 ) ;
return V_2 ;
}
}
V_2 = F_34 ( V_1 -> V_91 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_54 , V_2 ) ;
if ( V_1 -> V_97 )
F_42 ( V_1 -> V_98 ,
V_1 -> V_99 ) ;
return V_2 ;
}
if ( V_1 -> V_97 ) {
F_24 ( V_1 ) ;
F_43 ( V_1 -> V_18 ) ;
V_1 -> V_97 = false ;
}
F_44 ( V_1 -> V_15 , false ) ;
switch ( V_1 -> type ) {
case V_100 :
if ( V_1 -> V_101 ) {
V_2 = F_36 ( V_1 ) ;
if ( V_2 != 0 )
goto V_74;
}
V_2 = F_45 ( V_1 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_55 ,
V_2 ) ;
goto V_74;
}
V_2 = F_27 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_56 ,
V_2 ) ;
goto V_74;
}
break;
case V_70 :
case V_71 :
V_2 = F_19 ( V_1 ) ;
if ( V_2 )
goto V_74;
if ( V_1 -> V_101 ) {
V_2 = F_36 ( V_1 ) ;
if ( V_2 != 0 )
goto V_74;
} else {
V_2 = F_46 ( V_1 -> V_91 ,
1200000 , 1200000 ) ;
if ( V_2 < 0 ) {
F_12 ( V_1 -> V_8 ,
L_57 ,
V_2 ) ;
goto V_74;
}
}
V_2 = F_28 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_58 ,
V_2 ) ;
goto V_74;
}
break;
case V_102 :
case V_103 :
V_2 = F_19 ( V_1 ) ;
if ( V_2 != 0 )
goto V_74;
break;
default:
V_2 = F_19 ( V_1 ) ;
if ( V_2 != 0 )
goto V_74;
if ( V_1 -> V_101 ) {
V_2 = F_36 ( V_1 ) ;
if ( V_2 != 0 )
goto V_74;
}
break;
}
V_2 = F_47 ( V_1 -> V_15 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_59 ) ;
goto V_74;
}
return 0 ;
V_74:
F_44 ( V_1 -> V_15 , true ) ;
F_32 ( V_1 -> V_91 ) ;
return V_2 ;
}
static int F_48 ( struct V_96 * V_8 )
{
struct V_1 * V_1 = F_39 ( V_8 ) ;
int V_104 = 0 ;
int V_2 ;
F_40 ( V_1 -> V_8 , L_60 ) ;
switch ( V_1 -> type ) {
case V_70 :
case V_71 :
V_104 = F_37 ( V_1 ) ;
if ( V_104 < 0 )
return V_104 ;
if ( V_1 -> V_101 ) {
V_2 = F_35 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
} else {
V_2 = F_46 ( V_1 -> V_91 ,
1175000 , 1175000 ) ;
if ( V_2 < 0 ) {
F_12 ( V_1 -> V_8 ,
L_61 ,
V_2 ) ;
return V_2 ;
}
}
break;
case V_100 :
V_104 = F_37 ( V_1 ) ;
if ( V_104 < 0 )
return V_104 ;
if ( V_1 -> V_101 ) {
V_2 = F_35 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
}
if ( ! V_104 ) {
V_2 = F_20 ( V_1 -> V_15 ,
V_90 , 0x0 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_62 ,
V_2 ) ;
return V_2 ;
}
}
break;
case V_102 :
case V_103 :
break;
default:
V_104 = F_37 ( V_1 ) ;
if ( V_104 < 0 )
return V_104 ;
if ( V_1 -> V_101 ) {
V_2 = F_35 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
}
break;
}
F_44 ( V_1 -> V_15 , true ) ;
F_49 ( V_1 -> V_15 ) ;
F_32 ( V_1 -> V_91 ) ;
if ( ! V_104 ) {
F_40 ( V_1 -> V_8 , L_63 ) ;
V_1 -> V_97 = true ;
F_50 ( V_1 -> V_18 ) ;
F_22 ( V_1 ) ;
F_42 ( V_1 -> V_98 ,
V_1 -> V_99 ) ;
}
return 0 ;
}
static int F_51 ( struct V_96 * V_8 )
{
struct V_1 * V_1 = F_39 ( V_8 ) ;
F_40 ( V_1 -> V_8 , L_64 ) ;
F_52 ( V_1 -> V_18 ) ;
return 0 ;
}
static int F_53 ( struct V_96 * V_8 )
{
struct V_1 * V_1 = F_39 ( V_8 ) ;
F_40 ( V_1 -> V_8 , L_65 ) ;
F_43 ( V_1 -> V_18 ) ;
return 0 ;
}
static int F_54 ( struct V_96 * V_8 )
{
struct V_1 * V_1 = F_39 ( V_8 ) ;
F_40 ( V_1 -> V_8 , L_66 ) ;
F_52 ( V_1 -> V_18 ) ;
return 0 ;
}
static int F_55 ( struct V_96 * V_8 )
{
struct V_1 * V_1 = F_39 ( V_8 ) ;
F_40 ( V_1 -> V_8 , L_67 ) ;
F_43 ( V_1 -> V_18 ) ;
return 0 ;
}
unsigned long F_56 ( struct V_96 * V_8 )
{
const struct V_105 * V_106 = F_57 ( V_107 , V_8 ) ;
if ( V_106 )
return ( unsigned long ) V_106 -> V_19 ;
else
return 0 ;
}
static int F_58 ( struct V_1 * V_1 )
{
struct V_108 * V_5 = & V_1 -> V_5 ;
struct V_109 * V_110 ;
const T_2 * V_111 ;
T_3 V_21 ;
T_3 V_112 [ V_113 ] ;
int V_2 , V_64 ;
int V_114 = 0 ;
V_5 -> V_69 = F_59 ( V_1 -> V_8 -> V_115 , L_68 , 0 ) ;
if ( V_5 -> V_69 == - V_116 ) {
return V_5 -> V_69 ;
} else if ( V_5 -> V_69 < 0 ) {
F_12 ( V_1 -> V_8 , L_69 ,
V_5 -> V_69 ) ;
V_5 -> V_69 = 0 ;
}
V_2 = F_60 ( V_1 -> V_8 -> V_115 ,
L_70 ,
V_5 -> V_117 ,
F_30 ( V_5 -> V_117 ) ) ;
if ( V_2 >= 0 ) {
for ( V_64 = 0 ; V_64 < F_30 ( V_5 -> V_117 ) ; V_64 ++ ) {
if ( V_5 -> V_117 [ V_64 ] > 0xffff )
V_5 -> V_117 [ V_64 ] = 0 ;
else if ( V_5 -> V_117 [ V_64 ] == 0 )
V_5 -> V_117 [ V_64 ] = 0x10000 ;
}
} else {
F_12 ( V_1 -> V_8 , L_71 ,
V_2 ) ;
}
F_61 (arizona->dev->of_node, L_72 , prop,
cur, val) {
if ( V_114 == F_30 ( V_5 -> V_118 ) )
break;
V_5 -> V_118 [ V_114 ] = V_21 ;
V_114 ++ ;
}
V_114 = 0 ;
F_61 (arizona->dev->of_node, L_73 , prop,
cur, val) {
if ( V_114 == F_30 ( V_5 -> V_119 ) )
break;
V_5 -> V_119 [ V_114 ] = V_21 ;
V_114 ++ ;
}
V_114 = 0 ;
F_61 (arizona->dev->of_node, L_74 , prop,
cur, val) {
if ( V_114 == F_30 ( V_5 -> V_120 ) )
break;
V_5 -> V_120 [ V_114 ] = ! ! V_21 ;
V_114 ++ ;
}
V_114 = 0 ;
F_61 (arizona->dev->of_node,
L_75 ,
prop, cur, val) {
if ( V_114 == F_30 ( V_5 -> V_121 ) )
break;
V_5 -> V_121 [ V_114 ] = V_21 ;
V_114 ++ ;
}
V_2 = F_60 ( V_1 -> V_8 -> V_115 ,
L_76 ,
V_112 ,
F_30 ( V_112 ) ) ;
if ( V_2 >= 0 )
for ( V_114 = 0 ; V_114 < F_30 ( V_5 -> V_122 ) ; ++ V_114 )
V_5 -> V_122 [ V_114 ] = V_112 [ V_114 ] ;
V_2 = F_60 ( V_1 -> V_8 -> V_115 ,
L_77 ,
V_112 ,
F_30 ( V_112 ) ) ;
if ( V_2 >= 0 )
for ( V_114 = 0 ; V_114 < F_30 ( V_5 -> V_123 ) ; ++ V_114 )
V_5 -> V_123 [ V_114 ] = V_112 [ V_114 ] ;
return 0 ;
}
static inline int F_58 ( struct V_1 * V_1 )
{
return 0 ;
}
int F_62 ( struct V_1 * V_1 )
{
const char * const V_124 [] = { L_78 , L_79 } ;
struct V_96 * V_8 = V_1 -> V_8 ;
const char * V_125 = NULL ;
unsigned int V_61 , V_21 , V_62 ;
int (* F_63)( struct V_1 * ) = NULL ;
const struct V_126 * V_127 = NULL ;
int V_128 , V_2 , V_64 ;
F_64 ( V_1 -> V_8 , V_1 ) ;
F_65 ( & V_1 -> V_3 ) ;
if ( F_66 ( V_1 -> V_8 ) ) {
memcpy ( & V_1 -> V_5 , F_66 ( V_1 -> V_8 ) ,
sizeof( V_1 -> V_5 ) ) ;
} else {
V_2 = F_58 ( V_1 ) ;
if ( V_2 < 0 )
return V_2 ;
}
F_67 ( F_30 ( V_1 -> V_10 ) != F_30 ( V_124 ) ) ;
for ( V_64 = 0 ; V_64 < F_30 ( V_1 -> V_10 ) ; V_64 ++ ) {
V_1 -> V_10 [ V_64 ] = F_68 ( V_1 -> V_8 , V_124 [ V_64 ] ) ;
if ( F_69 ( V_1 -> V_10 [ V_64 ] ) ) {
F_70 ( V_1 -> V_8 , L_80 ,
V_124 [ V_64 ] , F_71 ( V_1 -> V_10 [ V_64 ] ) ) ;
V_1 -> V_10 [ V_64 ] = NULL ;
}
}
F_44 ( V_1 -> V_15 , true ) ;
switch ( V_1 -> type ) {
case V_100 :
case V_70 :
case V_71 :
case V_129 :
case V_36 :
case V_37 :
case V_102 :
case V_103 :
for ( V_64 = 0 ; V_64 < F_30 ( V_130 ) ; V_64 ++ )
V_1 -> V_99 [ V_64 ] . V_131
= V_130 [ V_64 ] ;
V_1 -> V_98 = F_30 ( V_130 ) ;
break;
default:
F_12 ( V_1 -> V_8 , L_81 ,
V_1 -> type ) ;
return - V_132 ;
}
V_1 -> V_101 = true ;
switch ( V_1 -> type ) {
case V_102 :
case V_103 :
break;
default:
V_2 = F_72 ( V_1 -> V_8 , - 1 , V_133 ,
F_30 ( V_133 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_82 , V_2 ) ;
return V_2 ;
}
break;
}
V_2 = F_73 ( V_8 , V_1 -> V_98 ,
V_1 -> V_99 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_83 ,
V_2 ) ;
goto V_134;
}
V_1 -> V_91 = F_74 ( V_1 -> V_8 , L_84 ) ;
if ( F_69 ( V_1 -> V_91 ) ) {
V_2 = F_71 ( V_1 -> V_91 ) ;
F_12 ( V_8 , L_85 , V_2 ) ;
goto V_134;
}
if ( V_1 -> V_5 . V_69 ) {
V_2 = F_75 ( V_1 -> V_8 , V_1 -> V_5 . V_69 ,
V_135 | V_136 ,
L_86 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_87 , V_2 ) ;
goto V_137;
}
}
V_2 = F_41 ( V_1 -> V_98 ,
V_1 -> V_99 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_53 ,
V_2 ) ;
goto V_137;
}
V_2 = F_34 ( V_1 -> V_91 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_54 , V_2 ) ;
goto V_138;
}
F_24 ( V_1 ) ;
F_44 ( V_1 -> V_15 , false ) ;
V_2 = F_14 ( V_1 -> V_15 , V_139 , & V_61 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_88 , V_2 ) ;
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
F_12 ( V_1 -> V_8 , L_89 , V_61 ) ;
V_2 = - V_132 ;
goto V_140;
}
if ( ! V_1 -> V_5 . V_69 ) {
V_2 = F_20 ( V_1 -> V_15 , V_139 , 0 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_90 , V_2 ) ;
goto V_140;
}
F_18 ( 1000 , 5000 ) ;
}
switch ( V_1 -> type ) {
case V_100 :
V_2 = F_14 ( V_1 -> V_15 ,
V_90 , & V_21 ) ;
if ( V_2 ) {
F_12 ( V_8 ,
L_91 ,
V_2 ) ;
} else if ( V_21 & 0x01 ) {
V_2 = F_31 ( V_1 ) ;
if ( V_2 )
return V_2 ;
}
break;
default:
break;
}
V_2 = F_19 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_92 , V_2 ) ;
goto V_140;
}
V_2 = F_14 ( V_1 -> V_15 , V_139 , & V_61 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_88 , V_2 ) ;
goto V_140;
}
V_2 = F_14 ( V_1 -> V_15 , V_141 ,
& V_1 -> V_142 ) ;
if ( V_2 != 0 ) {
F_12 ( V_8 , L_93 , V_2 ) ;
goto V_140;
}
V_1 -> V_142 &= V_143 ;
switch ( V_61 ) {
case 0x5102 :
if ( F_76 ( V_144 ) ) {
V_125 = L_94 ;
if ( V_1 -> type != V_100 ) {
F_77 ( V_1 -> V_8 ,
L_95 ,
V_1 -> type ) ;
V_1 -> type = V_100 ;
}
F_63 = F_45 ;
V_1 -> V_142 &= 0x7 ;
V_127 = V_145 ;
V_128 = F_30 ( V_145 ) ;
}
break;
case 0x5110 :
if ( F_76 ( V_146 ) ) {
switch ( V_1 -> type ) {
case V_70 :
V_125 = L_96 ;
break;
case V_71 :
V_125 = L_97 ;
break;
default:
V_125 = L_96 ;
F_77 ( V_1 -> V_8 ,
L_98 ,
V_1 -> type ) ;
V_1 -> type = V_70 ;
break;
}
F_63 = V_147 ;
V_127 = V_148 ;
V_128 = F_30 ( V_148 ) ;
}
break;
case 0x6363 :
if ( F_76 ( V_149 ) ) {
switch ( V_1 -> type ) {
case V_103 :
V_125 = L_99 ;
break;
case V_102 :
V_125 = L_100 ;
break;
default:
F_77 ( V_1 -> V_8 ,
L_101 ,
V_1 -> type ) ;
V_1 -> type = V_103 ;
break;
}
F_63 = V_150 ;
V_127 = V_151 ;
V_128 = F_30 ( V_151 ) ;
}
break;
case 0x8997 :
if ( F_76 ( V_152 ) ) {
V_125 = L_102 ;
if ( V_1 -> type != V_129 ) {
F_77 ( V_1 -> V_8 ,
L_103 ,
V_1 -> type ) ;
V_1 -> type = V_129 ;
}
F_63 = V_153 ;
V_127 = V_154 ;
V_128 = F_30 ( V_154 ) ;
}
break;
case 0x6349 :
if ( F_76 ( V_155 ) ) {
switch ( V_1 -> type ) {
case V_36 :
V_125 = L_104 ;
break;
case V_37 :
V_125 = L_105 ;
break;
default:
V_125 = L_104 ;
F_77 ( V_1 -> V_8 ,
L_106 ,
V_1 -> type ) ;
V_1 -> type = V_36 ;
}
F_63 = V_156 ;
V_127 = V_157 ;
V_128 = F_30 ( V_157 ) ;
}
break;
default:
F_12 ( V_1 -> V_8 , L_107 , V_61 ) ;
V_2 = - V_132 ;
goto V_140;
}
if ( ! V_127 ) {
F_12 ( V_1 -> V_8 ,
L_108 , V_61 ) ;
V_2 = - V_132 ;
goto V_140;
}
F_70 ( V_8 , L_109 , V_125 , V_1 -> V_142 + 'A' ) ;
if ( F_63 ) {
V_2 = F_63 ( V_1 ) ;
if ( V_2 != 0 ) {
F_12 ( V_1 -> V_8 , L_55 ,
V_2 ) ;
goto V_140;
}
switch ( V_1 -> type ) {
case V_100 :
V_2 = F_27 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_56 ,
V_2 ) ;
goto V_140;
}
break;
case V_70 :
case V_71 :
V_2 = F_28 ( V_1 ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 ,
L_110 ,
V_2 ) ;
goto V_140;
}
break;
default:
break;
}
}
for ( V_64 = 0 ; V_64 < F_30 ( V_1 -> V_5 . V_117 ) ; V_64 ++ ) {
if ( ! V_1 -> V_5 . V_117 [ V_64 ] )
continue;
F_20 ( V_1 -> V_15 , V_158 + V_64 ,
V_1 -> V_5 . V_117 [ V_64 ] ) ;
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
F_12 ( V_1 -> V_8 , L_111 ,
V_1 -> V_5 . V_6 ) ;
V_2 = - V_161 ;
goto V_140;
}
for ( V_64 = 0 ; V_64 < V_162 ; V_64 ++ ) {
if ( ! V_1 -> V_5 . V_163 [ V_64 ] . V_164 &&
! V_1 -> V_5 . V_163 [ V_64 ] . V_165 )
continue;
if ( ! V_1 -> V_5 . V_163 [ V_64 ] . V_164 )
V_1 -> V_5 . V_163 [ V_64 ] . V_164 = 2800 ;
V_21 = ( V_1 -> V_5 . V_163 [ V_64 ] . V_164 - 1500 ) / 100 ;
V_21 <<= V_166 ;
if ( V_1 -> V_5 . V_163 [ V_64 ] . V_167 )
V_21 |= V_168 ;
if ( V_1 -> V_5 . V_163 [ V_64 ] . V_169 )
V_21 |= V_170 ;
if ( V_1 -> V_5 . V_163 [ V_64 ] . V_171 )
V_21 |= V_172 ;
if ( V_1 -> V_5 . V_163 [ V_64 ] . V_165 )
V_21 |= V_173 ;
F_5 ( V_1 -> V_15 ,
V_174 + V_64 ,
V_175 |
V_168 |
V_170 |
V_173 |
V_172 , V_21 ) ;
}
for ( V_64 = 0 ; V_64 < V_176 ; V_64 ++ ) {
V_21 = V_1 -> V_5 . V_119 [ V_64 ]
<< V_177 ;
if ( V_1 -> V_5 . V_118 [ V_64 ] & V_178 )
V_21 |= 1 << V_179 ;
switch ( V_1 -> type ) {
case V_36 :
case V_37 :
F_5 ( V_1 -> V_15 ,
V_180 + ( V_64 * 8 ) ,
V_181 ,
( V_1 -> V_5 . V_118 [ V_64 ] & V_182 )
<< V_183 ) ;
F_5 ( V_1 -> V_15 ,
V_184 + ( V_64 * 8 ) ,
V_185 ,
( V_1 -> V_5 . V_118 [ V_64 ] & V_182 )
<< V_186 ) ;
V_62 = V_187 |
V_188 ;
break;
default:
if ( V_1 -> V_5 . V_118 [ V_64 ] & V_182 )
V_21 |= 1 << V_189 ;
V_62 = V_187 |
V_188 |
V_190 ;
break;
}
F_5 ( V_1 -> V_15 ,
V_191 + ( V_64 * 8 ) ,
V_62 , V_21 ) ;
}
for ( V_64 = 0 ; V_64 < V_192 ; V_64 ++ ) {
if ( V_1 -> V_5 . V_120 [ V_64 ] )
V_21 = V_193 ;
else
V_21 = 0 ;
F_5 ( V_1 -> V_15 ,
V_194 + ( V_64 * 8 ) ,
V_193 , V_21 ) ;
}
for ( V_64 = 0 ; V_64 < V_113 ; V_64 ++ ) {
if ( V_1 -> V_5 . V_123 [ V_64 ] )
F_5 ( V_1 -> V_15 ,
V_195 + ( V_64 * 2 ) ,
V_196 |
V_197 ,
V_1 -> V_5 . V_123 [ V_64 ] ) ;
if ( V_1 -> V_5 . V_122 [ V_64 ] )
F_5 ( V_1 -> V_15 ,
V_198 + ( V_64 * 2 ) ,
V_199 ,
V_1 -> V_5 . V_122 [ V_64 ] ) ;
}
F_78 ( V_1 -> V_8 ) ;
F_79 ( V_1 -> V_8 ) ;
V_2 = F_80 ( V_1 ) ;
if ( V_2 != 0 )
goto V_12;
F_81 ( V_1 -> V_8 , 100 ) ;
F_82 ( V_1 -> V_8 ) ;
F_83 ( V_1 , V_200 , L_112 ,
F_11 , V_1 ) ;
F_83 ( V_1 , V_201 , L_113 ,
F_15 , V_1 ) ;
F_83 ( V_1 , V_202 , L_114 ,
F_13 , V_1 ) ;
V_2 = F_72 ( V_1 -> V_8 , V_203 ,
V_127 , V_128 , NULL , 0 , NULL ) ;
if ( V_2 ) {
F_12 ( V_1 -> V_8 , L_115 , V_2 ) ;
goto V_204;
}
return 0 ;
V_204:
F_84 ( V_1 ) ;
V_12:
F_85 ( V_1 -> V_8 ) ;
V_140:
F_22 ( V_1 ) ;
F_32 ( V_1 -> V_91 ) ;
V_138:
F_42 ( V_1 -> V_98 ,
V_1 -> V_99 ) ;
V_137:
F_86 ( V_1 -> V_91 ) ;
V_134:
F_87 ( V_8 ) ;
return V_2 ;
}
int F_88 ( struct V_1 * V_1 )
{
F_85 ( V_1 -> V_8 ) ;
F_32 ( V_1 -> V_91 ) ;
F_86 ( V_1 -> V_91 ) ;
F_87 ( V_1 -> V_8 ) ;
F_89 ( V_1 , V_202 , V_1 ) ;
F_89 ( V_1 , V_201 , V_1 ) ;
F_89 ( V_1 , V_200 , V_1 ) ;
F_84 ( V_1 ) ;
F_22 ( V_1 ) ;
F_42 ( V_1 -> V_98 ,
V_1 -> V_99 ) ;
return 0 ;
}
