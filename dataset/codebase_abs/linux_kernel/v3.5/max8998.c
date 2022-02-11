static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
const struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
int V_7 ;
if ( V_6 >= F_3 ( V_8 ) )
return - V_9 ;
V_5 = V_8 [ V_6 ] ;
if ( V_5 == NULL )
return - V_9 ;
V_7 = V_5 -> V_10 + V_5 -> V_11 * V_3 ;
if ( V_7 > V_5 -> V_12 )
return - V_9 ;
return V_7 * 1000 ;
}
static int F_4 ( struct V_1 * V_2 ,
int * V_13 , int * V_14 )
{
int V_6 = F_2 ( V_2 ) ;
switch ( V_6 ) {
case V_15 ... V_16 :
* V_13 = V_17 ;
* V_14 = 3 - ( V_6 - V_15 ) ;
break;
case V_18 ... V_19 :
* V_13 = V_20 ;
* V_14 = 7 - ( V_6 - V_18 ) ;
break;
case V_21 ... V_22 :
* V_13 = V_23 ;
* V_14 = 7 - ( V_6 - V_21 ) ;
break;
case V_24 ... V_25 :
* V_13 = V_17 ;
* V_14 = 7 - ( V_6 - V_24 ) ;
break;
case V_26 ... V_27 :
* V_13 = V_28 ;
* V_14 = 7 - ( V_6 - V_26 ) ;
break;
case V_29 ... V_30 :
* V_13 = V_31 ;
* V_14 = 7 - ( V_6 - V_29 ) ;
break;
default:
return - V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_6 ( V_2 ) ;
struct V_34 * V_35 = V_33 -> V_36 -> V_35 ;
int V_37 , V_13 , V_14 = 8 ;
T_1 V_7 ;
V_37 = F_4 ( V_2 , & V_13 , & V_14 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_7 ( V_35 , V_13 , & V_7 ) ;
if ( V_37 )
return V_37 ;
return V_7 & ( 1 << V_14 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_6 ( V_2 ) ;
struct V_34 * V_35 = V_33 -> V_36 -> V_35 ;
int V_13 , V_14 = 8 , V_37 ;
V_37 = F_4 ( V_2 , & V_13 , & V_14 ) ;
if ( V_37 )
return V_37 ;
return F_9 ( V_35 , V_13 , 1 << V_14 , 1 << V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_6 ( V_2 ) ;
struct V_34 * V_35 = V_33 -> V_36 -> V_35 ;
int V_13 , V_14 = 8 , V_37 ;
V_37 = F_4 ( V_2 , & V_13 , & V_14 ) ;
if ( V_37 )
return V_37 ;
return F_9 ( V_35 , V_13 , 0 , 1 << V_14 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
int * V_38 , int * V_39 , int * V_40 )
{
int V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_6 ( V_2 ) ;
int V_13 , V_14 = 0 , V_41 = 0xff ;
switch ( V_6 ) {
case V_15 ... V_42 :
V_13 = V_43 ;
V_41 = 0xf ;
if ( V_6 == V_15 )
V_14 = 4 ;
else
V_14 = 0 ;
break;
case V_44 ... V_45 :
V_13 = V_46 + ( V_6 - V_44 ) ;
break;
case V_47 ... V_48 :
V_13 = V_49 ;
V_41 = 0xf ;
if ( V_6 == V_47 )
V_14 = 4 ;
else
V_14 = 0 ;
break;
case V_50 ... V_51 :
V_13 = V_52 ;
if ( V_6 == V_50 ) {
V_14 = 5 ;
V_41 = 0x7 ;
} else {
V_14 = 0 ;
V_41 = 0x1f ;
}
break;
case V_53 ... V_22 :
V_13 = V_54 + ( V_6 - V_53 ) ;
break;
case V_24 :
V_13 = V_55 + V_33 -> V_56 ;
break;
case V_57 :
V_13 = V_58 + V_33 -> V_59 ;
break;
case V_60 :
V_13 = V_61 ;
break;
case V_25 :
V_13 = V_62 ;
break;
default:
return - V_9 ;
}
* V_38 = V_13 ;
* V_39 = V_14 ;
* V_40 = V_41 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_6 ( V_2 ) ;
struct V_34 * V_35 = V_33 -> V_36 -> V_35 ;
int V_13 , V_14 = 0 , V_41 , V_37 ;
T_1 V_7 ;
V_37 = F_11 ( V_2 , & V_13 , & V_14 , & V_41 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_7 ( V_35 , V_13 , & V_7 ) ;
if ( V_37 )
return V_37 ;
V_7 >>= V_14 ;
V_7 &= V_41 ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_63 , int V_64 , unsigned * V_3 )
{
struct V_32 * V_33 = F_6 ( V_2 ) ;
struct V_34 * V_35 = V_33 -> V_36 -> V_35 ;
int V_65 = V_63 / 1000 , V_66 = V_64 / 1000 ;
const struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
int V_13 , V_14 = 0 , V_41 , V_37 , V_67 ;
if ( V_6 >= F_3 ( V_8 ) )
return - V_9 ;
V_5 = V_8 [ V_6 ] ;
if ( V_5 == NULL )
return - V_9 ;
if ( V_66 < V_5 -> V_10 || V_65 > V_5 -> V_12 )
return - V_9 ;
if ( V_65 < V_5 -> V_10 )
V_65 = V_5 -> V_10 ;
V_67 = F_14 ( V_65 - V_5 -> V_10 , V_5 -> V_11 ) ;
if ( V_5 -> V_10 + V_5 -> V_11 * V_67 > V_66 )
return - V_9 ;
* V_3 = V_67 ;
V_37 = F_11 ( V_2 , & V_13 , & V_14 , & V_41 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_9 ( V_35 , V_13 , V_67 << V_14 , V_41 << V_14 ) ;
return V_37 ;
}
static inline void F_15 ( int V_68 , int V_69 , int V_70 )
{
F_16 ( V_68 , V_70 & 0x1 ) ;
F_16 ( V_69 , ( V_70 >> 1 ) & 0x1 ) ;
}
static inline void F_17 ( int V_71 , int V_70 )
{
F_16 ( V_71 , V_70 & 0x1 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_63 , int V_64 , unsigned * V_3 )
{
struct V_32 * V_33 = F_6 ( V_2 ) ;
struct V_72 * V_73 =
F_19 ( V_33 -> V_36 -> V_74 ) ;
struct V_34 * V_35 = V_33 -> V_36 -> V_35 ;
int V_65 = V_63 / 1000 , V_66 = V_64 / 1000 ;
const struct V_4 * V_5 ;
int V_75 = F_2 ( V_2 ) ;
int V_13 , V_14 = 0 , V_41 , V_37 ;
int V_67 , V_76 , V_77 ;
static T_1 V_78 ;
if ( V_75 >= F_3 ( V_8 ) )
return - V_9 ;
V_5 = V_8 [ V_75 ] ;
if ( V_5 == NULL )
return - V_9 ;
if ( V_66 < V_5 -> V_10 || V_65 > V_5 -> V_12 )
return - V_9 ;
if ( V_65 < V_5 -> V_10 )
V_65 = V_5 -> V_10 ;
V_67 = F_14 ( V_65 - V_5 -> V_10 , V_5 -> V_11 ) ;
if ( V_5 -> V_10 + V_5 -> V_11 * V_67 > V_66 )
return - V_9 ;
* V_3 = V_67 ;
V_37 = F_11 ( V_2 , & V_13 , & V_14 , & V_41 ) ;
if ( V_37 )
return V_37 ;
V_77 = F_12 ( V_2 ) ;
if ( V_77 == V_67 ) {
F_20 ( V_33 -> V_74 , L_1 ,
F_1 ( V_2 , V_77 ) ,
F_1 ( V_2 , V_67 ) ) ;
return V_37 ;
}
switch ( V_75 ) {
case V_24 :
F_20 ( V_33 -> V_74 ,
L_2
L_3 ,
V_67 , V_33 -> V_79 [ 0 ] , V_33 -> V_79 [ 1 ] ,
V_33 -> V_79 [ 2 ] , V_33 -> V_79 [ 3 ] ) ;
if ( F_21 ( V_73 -> V_80 ) &&
F_21 ( V_73 -> V_81 ) ) {
for ( V_76 = 0 ; V_76 < F_3 ( V_33 -> V_79 ) ; V_76 ++ ) {
if ( V_33 -> V_79 [ V_76 ] == V_67 ) {
V_33 -> V_56 = V_76 ;
F_15 ( V_73 -> V_80 ,
V_73 -> V_81 , V_76 ) ;
goto V_82;
}
}
if ( V_73 -> V_83 )
return - V_9 ;
V_33 -> V_56 = ( V_78 % 2 ) + 2 ;
F_20 ( V_33 -> V_74 , L_4 ,
V_33 -> V_56 ) ;
V_33 -> V_79 [ V_33 -> V_56 ] = V_67 ;
V_37 = F_11 ( V_2 , & V_13 ,
& V_14 ,
& V_41 ) ;
V_37 = F_22 ( V_35 , V_13 , V_67 ) ;
F_15 ( V_73 -> V_80 ,
V_73 -> V_81 , V_33 -> V_56 ) ;
V_78 ++ ;
V_82:
F_20 ( V_33 -> V_74 , L_5 ,
V_35 -> V_84 , F_23 ( V_73 -> V_80 ) ,
F_23 ( V_73 -> V_81 ) ) ;
break;
} else {
V_37 = F_22 ( V_35 , V_13 , V_67 ) ;
}
break;
case V_57 :
F_20 ( V_33 -> V_74 ,
L_6
, V_67 , V_33 -> V_85 [ 0 ] , V_33 -> V_85 [ 1 ] ) ;
if ( F_21 ( V_73 -> V_86 ) ) {
for ( V_76 = 0 ; V_76 < F_3 ( V_33 -> V_85 ) ; V_76 ++ ) {
if ( V_33 -> V_85 [ V_76 ] == V_67 ) {
V_33 -> V_59 = V_76 ;
F_17 ( V_73 -> V_86 , V_76 ) ;
goto V_87;
}
}
if ( V_73 -> V_83 )
return - V_9 ;
F_11 ( V_2 ,
& V_13 , & V_14 , & V_41 ) ;
V_37 = F_22 ( V_35 , V_13 , V_67 ) ;
V_33 -> V_85 [ V_33 -> V_59 ] = V_67 ;
F_17 ( V_73 -> V_86 , V_33 -> V_59 ) ;
V_87:
F_20 ( V_33 -> V_74 , L_7 , V_35 -> V_84 ,
F_23 ( V_73 -> V_86 ) ) ;
} else {
V_37 = F_22 ( V_35 , V_13 , V_67 ) ;
}
break;
case V_60 :
case V_25 :
V_37 = F_9 ( V_35 , V_13 , V_67 << V_14 , V_41 << V_14 ) ;
break;
}
return V_37 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned int V_88 ,
unsigned int V_89 )
{
struct V_32 * V_33 = F_6 ( V_2 ) ;
struct V_34 * V_35 = V_33 -> V_36 -> V_35 ;
const struct V_4 * V_5 ;
int V_75 = F_2 ( V_2 ) ;
T_1 V_7 = 0 ;
int V_90 , V_37 ;
if ( V_75 < V_24 || V_75 > V_25 )
return - V_9 ;
V_5 = V_8 [ V_75 ] ;
V_37 = F_7 ( V_35 , V_28 , & V_7 ) ;
if ( V_37 )
return V_37 ;
if ( V_33 -> V_36 -> type == V_91 && ! ( V_7 & V_92 ) )
return 0 ;
V_90 = ( V_89 - V_88 ) * V_5 -> V_11 ;
if ( V_90 > 0 )
return V_90 / ( ( V_7 & 0x0f ) + 1 ) ;
return 0 ;
}
static T_2 int F_25 ( struct V_93 * V_94 )
{
struct V_95 * V_36 = F_26 ( V_94 -> V_74 . V_96 ) ;
struct V_72 * V_73 = F_19 ( V_36 -> V_74 ) ;
struct V_97 V_98 = { } ;
struct V_1 * * V_2 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
int V_67 , V_37 , V_99 ;
if ( ! V_73 ) {
F_27 ( V_94 -> V_74 . V_96 , L_8 ) ;
return - V_100 ;
}
V_33 = F_28 ( & V_94 -> V_74 , sizeof( struct V_32 ) ,
V_101 ) ;
if ( ! V_33 )
return - V_102 ;
V_99 = sizeof( struct V_1 * ) * V_73 -> V_103 ;
V_33 -> V_2 = F_28 ( & V_94 -> V_74 , V_99 , V_101 ) ;
if ( ! V_33 -> V_2 )
return - V_102 ;
V_2 = V_33 -> V_2 ;
V_33 -> V_74 = & V_94 -> V_74 ;
V_33 -> V_36 = V_36 ;
V_33 -> V_103 = V_73 -> V_103 ;
F_29 ( V_94 , V_33 ) ;
V_35 = V_33 -> V_36 -> V_35 ;
V_33 -> V_56 = V_73 -> V_104 ;
V_33 -> V_59 = V_73 -> V_105 ;
if ( F_21 ( V_73 -> V_80 ) &&
F_21 ( V_73 -> V_81 ) ) {
if ( ! V_73 -> V_80 ) {
F_30 ( V_106 L_9 ) ;
F_31 ( ! V_73 -> V_80 ) ;
V_37 = - V_107 ;
goto V_108;
}
if ( ! V_73 -> V_81 ) {
F_30 ( V_106 L_10 ) ;
F_31 ( ! V_73 -> V_81 ) ;
V_37 = - V_107 ;
goto V_108;
}
F_32 ( V_73 -> V_80 , L_11 ) ;
F_33 ( V_73 -> V_80 ,
V_33 -> V_56 & 0x1 ) ;
F_32 ( V_73 -> V_81 , L_12 ) ;
F_33 ( V_73 -> V_81 ,
( V_33 -> V_56 >> 1 ) & 0x1 ) ;
V_67 = 0 ;
while ( V_109 . V_10 +
V_109 . V_11 * V_67
< ( V_73 -> V_110 / 1000 ) )
V_67 ++ ;
V_33 -> V_79 [ 0 ] = V_67 ;
V_37 = F_22 ( V_35 , V_55 , V_67 ) ;
if ( V_37 )
goto V_108;
V_67 = 0 ;
while ( V_109 . V_10 +
V_109 . V_11 * V_67
< ( V_73 -> V_111 / 1000 ) )
V_67 ++ ;
V_33 -> V_79 [ 1 ] = V_67 ;
V_37 = F_22 ( V_35 , V_112 , V_67 ) ;
if ( V_37 )
goto V_108;
V_67 = 0 ;
while ( V_109 . V_10 +
V_109 . V_11 * V_67
< ( V_73 -> V_113 / 1000 ) )
V_67 ++ ;
V_33 -> V_79 [ 2 ] = V_67 ;
V_37 = F_22 ( V_35 , V_114 , V_67 ) ;
if ( V_37 )
goto V_108;
V_67 = 0 ;
while ( V_109 . V_10 +
V_109 . V_11 * V_67
< ( V_73 -> V_115 / 1000 ) )
V_67 ++ ;
V_33 -> V_79 [ 3 ] = V_67 ;
V_37 = F_22 ( V_35 , V_116 , V_67 ) ;
if ( V_37 )
goto V_108;
}
if ( F_21 ( V_73 -> V_86 ) ) {
if ( ! V_73 -> V_86 ) {
F_30 ( V_106 L_13 ) ;
F_31 ( ! V_73 -> V_86 ) ;
V_37 = - V_107 ;
goto V_108;
}
F_32 ( V_73 -> V_86 , L_14 ) ;
F_33 ( V_73 -> V_86 ,
V_33 -> V_59 & 0x1 ) ;
V_67 = 0 ;
while ( V_109 . V_10 +
V_109 . V_11 * V_67
< ( V_73 -> V_117 / 1000 ) )
V_67 ++ ;
V_33 -> V_85 [ 0 ] = V_67 ;
V_37 = F_22 ( V_35 , V_58 , V_67 ) ;
if ( V_37 )
goto V_108;
V_67 = 0 ;
while ( V_109 . V_10 +
V_109 . V_11 * V_67
< ( V_73 -> V_118 / 1000 ) )
V_67 ++ ;
V_33 -> V_85 [ 1 ] = V_67 ;
V_37 = F_22 ( V_35 , V_119 , V_67 ) ;
if ( V_37 )
goto V_108;
}
for ( V_67 = 0 ; V_67 < V_73 -> V_103 ; V_67 ++ ) {
const struct V_4 * V_5 ;
int V_120 = V_73 -> V_121 [ V_67 ] . V_120 ;
int V_122 = V_120 - V_15 ;
V_5 = V_8 [ V_120 ] ;
if ( V_5 && V_121 [ V_122 ] . V_123 != & V_124 ) {
int V_125 = ( V_5 -> V_12 - V_5 -> V_10 ) / V_5 -> V_11 + 1 ;
V_121 [ V_122 ] . V_126 = V_125 ;
}
V_98 . V_74 = V_33 -> V_74 ;
V_98 . V_127 = V_73 -> V_121 [ V_67 ] . V_128 ;
V_98 . V_129 = V_33 ;
V_2 [ V_67 ] = F_34 ( & V_121 [ V_122 ] , & V_98 ) ;
if ( F_35 ( V_2 [ V_67 ] ) ) {
V_37 = F_36 ( V_2 [ V_67 ] ) ;
F_27 ( V_33 -> V_74 , L_15 ) ;
V_2 [ V_67 ] = NULL ;
goto V_130;
}
}
return 0 ;
V_130:
while ( -- V_67 >= 0 )
F_37 ( V_2 [ V_67 ] ) ;
V_108:
return V_37 ;
}
static int T_3 F_38 ( struct V_93 * V_94 )
{
struct V_32 * V_33 = F_39 ( V_94 ) ;
struct V_1 * * V_2 = V_33 -> V_2 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_33 -> V_103 ; V_67 ++ )
F_37 ( V_2 [ V_67 ] ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_131 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_131 ) ;
}
