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
int V_3 , V_4 = 0 , V_34 , V_29 ;
int V_65 , V_66 ;
static T_1 V_67 ;
V_29 = F_9 ( V_2 , & V_3 , & V_4 , & V_34 ) ;
if ( V_29 )
return V_29 ;
V_66 = F_10 ( V_2 ) ;
if ( V_66 == V_56 ) {
F_17 ( V_25 -> V_63 , L_1 ,
F_18 ( V_2 , V_66 ) ,
F_18 ( V_2 , V_56 ) ) ;
return V_29 ;
}
switch ( V_64 ) {
case V_15 :
F_17 ( V_25 -> V_63 ,
L_2
L_3 ,
V_56 , V_25 -> V_68 [ 0 ] , V_25 -> V_68 [ 1 ] ,
V_25 -> V_68 [ 2 ] , V_25 -> V_68 [ 3 ] ) ;
if ( F_19 ( V_62 -> V_69 ) &&
F_19 ( V_62 -> V_70 ) ) {
for ( V_65 = 0 ; V_65 < F_20 ( V_25 -> V_68 ) ; V_65 ++ ) {
if ( V_25 -> V_68 [ V_65 ] == V_56 ) {
V_25 -> V_49 = V_65 ;
F_12 ( V_62 -> V_69 ,
V_62 -> V_70 , V_65 ) ;
goto V_71;
}
}
if ( V_62 -> V_72 )
return - V_23 ;
V_25 -> V_49 = ( V_67 % 2 ) + 2 ;
F_17 ( V_25 -> V_63 , L_4 ,
V_25 -> V_49 ) ;
V_25 -> V_68 [ V_25 -> V_49 ] = V_56 ;
V_29 = F_9 ( V_2 , & V_3 ,
& V_4 ,
& V_34 ) ;
V_29 = F_21 ( V_27 , V_3 , V_56 ) ;
F_12 ( V_62 -> V_69 ,
V_62 -> V_70 , V_25 -> V_49 ) ;
V_67 ++ ;
V_71:
F_17 ( V_25 -> V_63 , L_5 ,
V_27 -> V_73 , F_22 ( V_62 -> V_69 ) ,
F_22 ( V_62 -> V_70 ) ) ;
break;
} else {
V_29 = F_21 ( V_27 , V_3 , V_56 ) ;
}
break;
case V_50 :
F_17 ( V_25 -> V_63 ,
L_6 ,
V_56 , V_25 -> V_74 [ 0 ] , V_25 -> V_74 [ 1 ] ) ;
if ( F_19 ( V_62 -> V_75 ) ) {
for ( V_65 = 0 ; V_65 < F_20 ( V_25 -> V_74 ) ; V_65 ++ ) {
if ( V_25 -> V_74 [ V_65 ] == V_56 ) {
V_25 -> V_52 = V_65 ;
F_14 ( V_62 -> V_75 , V_65 ) ;
goto V_76;
}
}
if ( V_62 -> V_72 )
return - V_23 ;
F_9 ( V_2 ,
& V_3 , & V_4 , & V_34 ) ;
V_29 = F_21 ( V_27 , V_3 , V_56 ) ;
V_25 -> V_74 [ V_25 -> V_52 ] = V_56 ;
F_14 ( V_62 -> V_75 , V_25 -> V_52 ) ;
V_76:
F_17 ( V_25 -> V_63 , L_7 , V_27 -> V_73 ,
F_22 ( V_62 -> V_75 ) ) ;
} else {
V_29 = F_21 ( V_27 , V_3 , V_56 ) ;
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
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_77 ,
unsigned int V_78 )
{
struct V_24 * V_25 = F_4 ( V_2 ) ;
struct V_26 * V_27 = V_25 -> V_28 -> V_27 ;
const struct V_79 * V_80 ;
int V_64 = F_2 ( V_2 ) ;
T_1 V_30 = 0 ;
int V_81 , V_29 ;
if ( V_64 < V_15 || V_64 > V_16 )
return - V_23 ;
V_80 = V_82 [ V_64 ] ;
V_29 = F_5 ( V_27 , V_19 , & V_30 ) ;
if ( V_29 )
return V_29 ;
if ( V_25 -> V_28 -> type == V_83 && ! ( V_30 & V_84 ) )
return 0 ;
V_81 = ( V_78 - V_77 ) * V_80 -> V_85 / 1000 ;
if ( V_81 > 0 )
return F_24 ( V_81 , ( V_30 & 0x0f ) + 1 ) ;
return 0 ;
}
static int F_25 ( struct V_86 * V_87 )
{
struct V_88 * V_28 = F_26 ( V_87 -> V_63 . V_89 ) ;
struct V_61 * V_62 = F_16 ( V_28 -> V_63 ) ;
struct V_90 V_91 = { } ;
struct V_1 * * V_2 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_92 , V_29 , V_93 ;
if ( ! V_62 ) {
F_27 ( V_87 -> V_63 . V_89 , L_8 ) ;
return - V_94 ;
}
V_25 = F_28 ( & V_87 -> V_63 , sizeof( struct V_24 ) ,
V_95 ) ;
if ( ! V_25 )
return - V_96 ;
V_93 = sizeof( struct V_1 * ) * V_62 -> V_97 ;
V_25 -> V_2 = F_28 ( & V_87 -> V_63 , V_93 , V_95 ) ;
if ( ! V_25 -> V_2 )
return - V_96 ;
V_2 = V_25 -> V_2 ;
V_25 -> V_63 = & V_87 -> V_63 ;
V_25 -> V_28 = V_28 ;
V_25 -> V_97 = V_62 -> V_97 ;
F_29 ( V_87 , V_25 ) ;
V_27 = V_25 -> V_28 -> V_27 ;
V_25 -> V_49 = V_62 -> V_98 ;
V_25 -> V_52 = V_62 -> V_99 ;
if ( F_19 ( V_62 -> V_69 ) &&
F_19 ( V_62 -> V_70 ) ) {
if ( ! V_62 -> V_69 ) {
F_30 ( V_100 L_9 ) ;
F_31 ( ! V_62 -> V_69 ) ;
V_29 = - V_101 ;
goto V_102;
}
if ( ! V_62 -> V_70 ) {
F_30 ( V_100 L_10 ) ;
F_31 ( ! V_62 -> V_70 ) ;
V_29 = - V_101 ;
goto V_102;
}
F_32 ( V_62 -> V_69 , L_11 ) ;
F_33 ( V_62 -> V_69 ,
V_25 -> V_49 & 0x1 ) ;
F_32 ( V_62 -> V_70 , L_12 ) ;
F_33 ( V_62 -> V_70 ,
( V_25 -> V_49 >> 1 ) & 0x1 ) ;
V_92 = 0 ;
while ( V_103 . V_104 +
V_103 . V_85 * V_92
< V_62 -> V_105 )
V_92 ++ ;
V_25 -> V_68 [ 0 ] = V_92 ;
V_29 = F_21 ( V_27 , V_48 , V_92 ) ;
if ( V_29 )
goto V_102;
V_92 = 0 ;
while ( V_103 . V_104 +
V_103 . V_85 * V_92
< V_62 -> V_106 )
V_92 ++ ;
V_25 -> V_68 [ 1 ] = V_92 ;
V_29 = F_21 ( V_27 , V_107 , V_92 ) ;
if ( V_29 )
goto V_102;
V_92 = 0 ;
while ( V_103 . V_104 +
V_103 . V_85 * V_92
< V_62 -> V_108 )
V_92 ++ ;
V_25 -> V_68 [ 2 ] = V_92 ;
V_29 = F_21 ( V_27 , V_109 , V_92 ) ;
if ( V_29 )
goto V_102;
V_92 = 0 ;
while ( V_103 . V_104 +
V_103 . V_85 * V_92
< V_62 -> V_110 )
V_92 ++ ;
V_25 -> V_68 [ 3 ] = V_92 ;
V_29 = F_21 ( V_27 , V_111 , V_92 ) ;
if ( V_29 )
goto V_102;
}
if ( F_19 ( V_62 -> V_75 ) ) {
if ( ! V_62 -> V_75 ) {
F_30 ( V_100 L_13 ) ;
F_31 ( ! V_62 -> V_75 ) ;
V_29 = - V_101 ;
goto V_102;
}
F_32 ( V_62 -> V_75 , L_14 ) ;
F_33 ( V_62 -> V_75 ,
V_25 -> V_52 & 0x1 ) ;
V_92 = 0 ;
while ( V_103 . V_104 +
V_103 . V_85 * V_92
< V_62 -> V_112 )
V_92 ++ ;
V_25 -> V_74 [ 0 ] = V_92 ;
V_29 = F_21 ( V_27 , V_51 , V_92 ) ;
if ( V_29 )
goto V_102;
V_92 = 0 ;
while ( V_103 . V_104 +
V_103 . V_85 * V_92
< V_62 -> V_113 )
V_92 ++ ;
V_25 -> V_74 [ 1 ] = V_92 ;
V_29 = F_21 ( V_27 , V_114 , V_92 ) ;
if ( V_29 )
goto V_102;
}
for ( V_92 = 0 ; V_92 < V_62 -> V_97 ; V_92 ++ ) {
const struct V_79 * V_80 ;
int V_115 = V_62 -> V_116 [ V_92 ] . V_115 ;
int V_117 = V_115 - V_6 ;
V_80 = V_82 [ V_115 ] ;
if ( V_80 && V_116 [ V_117 ] . V_118 != & V_119 ) {
int V_120 = ( V_80 -> V_121 - V_80 -> V_104 ) / V_80 -> V_85 + 1 ;
V_116 [ V_117 ] . V_122 = V_120 ;
V_116 [ V_117 ] . V_123 = V_80 -> V_104 ;
V_116 [ V_117 ] . V_124 = V_80 -> V_85 ;
}
V_91 . V_63 = V_25 -> V_63 ;
V_91 . V_125 = V_62 -> V_116 [ V_92 ] . V_126 ;
V_91 . V_127 = V_25 ;
V_2 [ V_92 ] = F_34 ( & V_116 [ V_117 ] , & V_91 ) ;
if ( F_35 ( V_2 [ V_92 ] ) ) {
V_29 = F_36 ( V_2 [ V_92 ] ) ;
F_27 ( V_25 -> V_63 , L_15 ) ;
V_2 [ V_92 ] = NULL ;
goto V_128;
}
}
return 0 ;
V_128:
while ( -- V_92 >= 0 )
F_37 ( V_2 [ V_92 ] ) ;
V_102:
return V_29 ;
}
static int F_38 ( struct V_86 * V_87 )
{
struct V_24 * V_25 = F_39 ( V_87 ) ;
struct V_1 * * V_2 = V_25 -> V_2 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_25 -> V_97 ; V_92 ++ )
F_37 ( V_2 [ V_92 ] ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_129 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_129 ) ;
}
