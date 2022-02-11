static int F_1 ( struct V_1 * V_2 ,
int * V_3 , int * V_4 )
{
int V_5 = F_2 ( V_2 ) ;
switch ( V_5 ) {
case V_6 ... V_7 :
* V_3 = V_8 ;
* V_4 = 3 - ( V_5 - V_6 ) ;
break;
case V_9 ... V_10 :
* V_3 = V_11 ;
* V_4 = 7 - ( V_5 - V_9 ) ;
break;
case V_12 ... V_13 :
* V_3 = V_14 ;
* V_4 = 7 - ( V_5 - V_12 ) ;
break;
case V_15 ... V_16 :
* V_3 = V_8 ;
* V_4 = 7 - ( V_5 - V_15 ) ;
break;
case V_17 ... V_18 :
* V_3 = V_19 ;
* V_4 = 7 - ( V_5 - V_17 ) ;
break;
case V_20 ... V_21 :
* V_3 = V_22 ;
* V_4 = 7 - ( V_5 - V_20 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_4 ( V_2 ) ;
struct V_26 * V_27 = V_25 -> V_28 -> V_27 ;
int V_29 , V_3 , V_4 = 8 ;
T_1 V_30 ;
V_29 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_5 ( V_27 , V_3 , & V_30 ) ;
if ( V_29 )
return V_29 ;
return V_30 & ( 1 << V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_4 ( V_2 ) ;
struct V_26 * V_27 = V_25 -> V_28 -> V_27 ;
int V_3 , V_4 = 8 , V_29 ;
V_29 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_29 )
return V_29 ;
return F_7 ( V_27 , V_3 , 1 << V_4 , 1 << V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_4 ( V_2 ) ;
struct V_26 * V_27 = V_25 -> V_28 -> V_27 ;
int V_3 , V_4 = 8 , V_29 ;
V_29 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_29 )
return V_29 ;
return F_7 ( V_27 , V_3 , 0 , 1 << V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
int * V_31 , int * V_32 , int * V_33 )
{
int V_5 = F_2 ( V_2 ) ;
struct V_24 * V_25 = F_4 ( V_2 ) ;
int V_3 , V_4 = 0 , V_34 = 0xff ;
switch ( V_5 ) {
case V_6 ... V_35 :
V_3 = V_36 ;
V_34 = 0xf ;
if ( V_5 == V_6 )
V_4 = 4 ;
else
V_4 = 0 ;
break;
case V_37 ... V_38 :
V_3 = V_39 + ( V_5 - V_37 ) ;
break;
case V_40 ... V_41 :
V_3 = V_42 ;
V_34 = 0xf ;
if ( V_5 == V_40 )
V_4 = 4 ;
else
V_4 = 0 ;
break;
case V_43 ... V_44 :
V_3 = V_45 ;
if ( V_5 == V_43 ) {
V_4 = 5 ;
V_34 = 0x7 ;
} else {
V_4 = 0 ;
V_34 = 0x1f ;
}
break;
case V_46 ... V_13 :
V_3 = V_47 + ( V_5 - V_46 ) ;
break;
case V_15 :
V_3 = V_48 + V_25 -> V_49 ;
break;
case V_50 :
V_3 = V_51 + V_25 -> V_52 ;
break;
case V_53 :
V_3 = V_54 ;
break;
case V_16 :
V_3 = V_55 ;
break;
default:
return - V_23 ;
}
* V_31 = V_3 ;
* V_32 = V_4 ;
* V_33 = V_34 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_4 ( V_2 ) ;
struct V_26 * V_27 = V_25 -> V_28 -> V_27 ;
int V_3 , V_4 = 0 , V_34 , V_29 ;
T_1 V_30 ;
V_29 = F_9 ( V_2 , & V_3 , & V_4 , & V_34 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_5 ( V_27 , V_3 , & V_30 ) ;
if ( V_29 )
return V_29 ;
V_30 >>= V_4 ;
V_30 &= V_34 ;
return V_30 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_56 )
{
struct V_24 * V_25 = F_4 ( V_2 ) ;
struct V_26 * V_27 = V_25 -> V_28 -> V_27 ;
int V_3 , V_4 = 0 , V_34 , V_29 ;
V_29 = F_9 ( V_2 , & V_3 , & V_4 , & V_34 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_7 ( V_27 , V_3 , V_56 << V_4 , V_34 << V_4 ) ;
return V_29 ;
}
static inline void F_12 ( int V_57 , int V_58 , int V_59 )
{
F_13 ( V_57 , V_59 & 0x1 ) ;
F_13 ( V_58 , ( V_59 >> 1 ) & 0x1 ) ;
}
static inline void F_14 ( int V_60 , int V_59 )
{
F_13 ( V_60 , V_59 & 0x1 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_56 )
{
struct V_24 * V_25 = F_4 ( V_2 ) ;
struct V_61 * V_62 =
F_16 ( V_25 -> V_28 -> V_63 ) ;
struct V_26 * V_27 = V_25 -> V_28 -> V_27 ;
int V_64 = F_2 ( V_2 ) ;
int V_3 , V_4 = 0 , V_34 , V_29 , V_65 ;
static T_1 V_66 ;
V_29 = F_9 ( V_2 , & V_3 , & V_4 , & V_34 ) ;
if ( V_29 )
return V_29 ;
switch ( V_64 ) {
case V_15 :
F_17 ( V_25 -> V_63 ,
L_1
L_2 ,
V_56 , V_25 -> V_67 [ 0 ] , V_25 -> V_67 [ 1 ] ,
V_25 -> V_67 [ 2 ] , V_25 -> V_67 [ 3 ] ) ;
if ( F_18 ( V_62 -> V_68 ) &&
F_18 ( V_62 -> V_69 ) ) {
for ( V_65 = 0 ; V_65 < F_19 ( V_25 -> V_67 ) ; V_65 ++ ) {
if ( V_25 -> V_67 [ V_65 ] == V_56 ) {
V_25 -> V_49 = V_65 ;
F_12 ( V_62 -> V_68 ,
V_62 -> V_69 , V_65 ) ;
goto V_70;
}
}
if ( V_62 -> V_71 )
return - V_23 ;
V_25 -> V_49 = ( V_66 % 2 ) + 2 ;
F_17 ( V_25 -> V_63 , L_3 ,
V_25 -> V_49 ) ;
V_25 -> V_67 [ V_25 -> V_49 ] = V_56 ;
V_29 = F_9 ( V_2 , & V_3 ,
& V_4 ,
& V_34 ) ;
V_29 = F_20 ( V_27 , V_3 , V_56 ) ;
F_12 ( V_62 -> V_68 ,
V_62 -> V_69 , V_25 -> V_49 ) ;
V_66 ++ ;
V_70:
F_17 ( V_25 -> V_63 , L_4 ,
V_27 -> V_72 , F_21 ( V_62 -> V_68 ) ,
F_21 ( V_62 -> V_69 ) ) ;
break;
} else {
V_29 = F_20 ( V_27 , V_3 , V_56 ) ;
}
break;
case V_50 :
F_17 ( V_25 -> V_63 ,
L_5 ,
V_56 , V_25 -> V_73 [ 0 ] , V_25 -> V_73 [ 1 ] ) ;
if ( F_18 ( V_62 -> V_74 ) ) {
for ( V_65 = 0 ; V_65 < F_19 ( V_25 -> V_73 ) ; V_65 ++ ) {
if ( V_25 -> V_73 [ V_65 ] == V_56 ) {
V_25 -> V_52 = V_65 ;
F_14 ( V_62 -> V_74 , V_65 ) ;
goto V_75;
}
}
if ( V_62 -> V_71 )
return - V_23 ;
F_9 ( V_2 ,
& V_3 , & V_4 , & V_34 ) ;
V_29 = F_20 ( V_27 , V_3 , V_56 ) ;
V_25 -> V_73 [ V_25 -> V_52 ] = V_56 ;
F_14 ( V_62 -> V_74 , V_25 -> V_52 ) ;
V_75:
F_17 ( V_25 -> V_63 , L_6 , V_27 -> V_72 ,
F_21 ( V_62 -> V_74 ) ) ;
} else {
V_29 = F_20 ( V_27 , V_3 , V_56 ) ;
}
break;
case V_53 :
case V_16 :
V_29 = F_7 ( V_27 , V_3 , V_56 << V_4 ,
V_34 << V_4 ) ;
break;
}
return V_29 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned int V_76 ,
unsigned int V_77 )
{
struct V_24 * V_25 = F_4 ( V_2 ) ;
struct V_26 * V_27 = V_25 -> V_28 -> V_27 ;
const struct V_78 * V_79 ;
int V_64 = F_2 ( V_2 ) ;
T_1 V_30 = 0 ;
int V_80 , V_29 ;
if ( V_64 < V_15 || V_64 > V_16 )
return - V_23 ;
V_79 = V_81 [ V_64 ] ;
V_29 = F_5 ( V_27 , V_19 , & V_30 ) ;
if ( V_29 )
return V_29 ;
if ( V_25 -> V_28 -> type == V_82 && ! ( V_30 & V_83 ) )
return 0 ;
V_80 = ( V_77 - V_76 ) * V_79 -> V_84 / 1000 ;
if ( V_80 > 0 )
return F_23 ( V_80 , ( V_30 & 0x0f ) + 1 ) ;
return 0 ;
}
static int F_24 ( struct V_85 * V_86 )
{
struct V_87 * V_28 = F_25 ( V_86 -> V_63 . V_88 ) ;
struct V_61 * V_62 = F_16 ( V_28 -> V_63 ) ;
struct V_89 V_90 = { } ;
struct V_1 * * V_2 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_91 , V_29 , V_92 ;
if ( ! V_62 ) {
F_26 ( V_86 -> V_63 . V_88 , L_7 ) ;
return - V_93 ;
}
V_25 = F_27 ( & V_86 -> V_63 , sizeof( struct V_24 ) ,
V_94 ) ;
if ( ! V_25 )
return - V_95 ;
V_92 = sizeof( struct V_1 * ) * V_62 -> V_96 ;
V_25 -> V_2 = F_27 ( & V_86 -> V_63 , V_92 , V_94 ) ;
if ( ! V_25 -> V_2 )
return - V_95 ;
V_2 = V_25 -> V_2 ;
V_25 -> V_63 = & V_86 -> V_63 ;
V_25 -> V_28 = V_28 ;
V_25 -> V_96 = V_62 -> V_96 ;
F_28 ( V_86 , V_25 ) ;
V_27 = V_25 -> V_28 -> V_27 ;
V_25 -> V_49 = V_62 -> V_97 ;
V_25 -> V_52 = V_62 -> V_98 ;
if ( F_18 ( V_62 -> V_68 ) &&
F_18 ( V_62 -> V_69 ) ) {
if ( ! V_62 -> V_68 ) {
F_29 ( V_99 L_8 ) ;
F_30 ( ! V_62 -> V_68 ) ;
V_29 = - V_100 ;
goto V_101;
}
if ( ! V_62 -> V_69 ) {
F_29 ( V_99 L_9 ) ;
F_30 ( ! V_62 -> V_69 ) ;
V_29 = - V_100 ;
goto V_101;
}
F_31 ( V_62 -> V_68 , L_10 ) ;
F_32 ( V_62 -> V_68 ,
V_25 -> V_49 & 0x1 ) ;
F_31 ( V_62 -> V_69 , L_11 ) ;
F_32 ( V_62 -> V_69 ,
( V_25 -> V_49 >> 1 ) & 0x1 ) ;
V_91 = 0 ;
while ( V_102 . V_103 +
V_102 . V_84 * V_91
< V_62 -> V_104 )
V_91 ++ ;
V_25 -> V_67 [ 0 ] = V_91 ;
V_29 = F_20 ( V_27 , V_48 , V_91 ) ;
if ( V_29 )
goto V_101;
V_91 = 0 ;
while ( V_102 . V_103 +
V_102 . V_84 * V_91
< V_62 -> V_105 )
V_91 ++ ;
V_25 -> V_67 [ 1 ] = V_91 ;
V_29 = F_20 ( V_27 , V_106 , V_91 ) ;
if ( V_29 )
goto V_101;
V_91 = 0 ;
while ( V_102 . V_103 +
V_102 . V_84 * V_91
< V_62 -> V_107 )
V_91 ++ ;
V_25 -> V_67 [ 2 ] = V_91 ;
V_29 = F_20 ( V_27 , V_108 , V_91 ) ;
if ( V_29 )
goto V_101;
V_91 = 0 ;
while ( V_102 . V_103 +
V_102 . V_84 * V_91
< V_62 -> V_109 )
V_91 ++ ;
V_25 -> V_67 [ 3 ] = V_91 ;
V_29 = F_20 ( V_27 , V_110 , V_91 ) ;
if ( V_29 )
goto V_101;
}
if ( F_18 ( V_62 -> V_74 ) ) {
if ( ! V_62 -> V_74 ) {
F_29 ( V_99 L_12 ) ;
F_30 ( ! V_62 -> V_74 ) ;
V_29 = - V_100 ;
goto V_101;
}
F_31 ( V_62 -> V_74 , L_13 ) ;
F_32 ( V_62 -> V_74 ,
V_25 -> V_52 & 0x1 ) ;
V_91 = 0 ;
while ( V_102 . V_103 +
V_102 . V_84 * V_91
< V_62 -> V_111 )
V_91 ++ ;
V_25 -> V_73 [ 0 ] = V_91 ;
V_29 = F_20 ( V_27 , V_51 , V_91 ) ;
if ( V_29 )
goto V_101;
V_91 = 0 ;
while ( V_102 . V_103 +
V_102 . V_84 * V_91
< V_62 -> V_112 )
V_91 ++ ;
V_25 -> V_73 [ 1 ] = V_91 ;
V_29 = F_20 ( V_27 , V_113 , V_91 ) ;
if ( V_29 )
goto V_101;
}
for ( V_91 = 0 ; V_91 < V_62 -> V_96 ; V_91 ++ ) {
const struct V_78 * V_79 ;
int V_114 = V_62 -> V_115 [ V_91 ] . V_114 ;
int V_116 = V_114 - V_6 ;
V_79 = V_81 [ V_114 ] ;
if ( V_79 && V_115 [ V_116 ] . V_117 != & V_118 ) {
int V_119 = ( V_79 -> V_120 - V_79 -> V_103 ) / V_79 -> V_84 + 1 ;
V_115 [ V_116 ] . V_121 = V_119 ;
V_115 [ V_116 ] . V_122 = V_79 -> V_103 ;
V_115 [ V_116 ] . V_123 = V_79 -> V_84 ;
}
V_90 . V_63 = V_25 -> V_63 ;
V_90 . V_124 = V_62 -> V_115 [ V_91 ] . V_125 ;
V_90 . V_126 = V_25 ;
V_2 [ V_91 ] = F_33 ( & V_115 [ V_116 ] , & V_90 ) ;
if ( F_34 ( V_2 [ V_91 ] ) ) {
V_29 = F_35 ( V_2 [ V_91 ] ) ;
F_26 ( V_25 -> V_63 , L_14 ) ;
V_2 [ V_91 ] = NULL ;
goto V_127;
}
}
return 0 ;
V_127:
while ( -- V_91 >= 0 )
F_36 ( V_2 [ V_91 ] ) ;
V_101:
return V_29 ;
}
static int F_37 ( struct V_85 * V_86 )
{
struct V_24 * V_25 = F_38 ( V_86 ) ;
struct V_1 * * V_2 = V_25 -> V_2 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_25 -> V_96 ; V_91 ++ )
F_36 ( V_2 [ V_91 ] ) ;
return 0 ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_128 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_128 ) ;
}
