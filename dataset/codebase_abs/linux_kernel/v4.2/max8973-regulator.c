static bool F_1 ( struct V_1 * V_2 ,
int V_3 , int * V_4 , int * V_5 )
{
int V_6 ;
bool V_7 = false ;
int V_8 = V_2 -> V_9 [ V_10 - 1 ] ;
int V_11 = V_10 - 1 ;
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 ) {
if ( V_2 -> V_12 [ V_2 -> V_9 [ V_6 ] ] == V_3 ) {
V_8 = V_2 -> V_9 [ V_6 ] ;
V_11 = V_6 ;
V_7 = true ;
goto V_13;
}
}
V_13:
for ( V_6 = V_11 ; V_6 > 0 ; V_6 -- )
V_2 -> V_9 [ V_6 ] = V_2 -> V_9 [ V_6 - 1 ] ;
V_2 -> V_9 [ 0 ] = V_8 ;
* V_5 = V_8 ;
* V_4 = V_14 + V_8 ;
return V_7 ;
}
static int F_2 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_4 ( V_17 -> V_20 , V_17 -> V_21 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_1 ,
V_17 -> V_21 , V_19 ) ;
return V_19 ;
}
return V_18 & V_23 ;
}
static int F_6 ( struct V_15 * V_16 ,
unsigned V_24 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
int V_19 ;
bool V_7 = false ;
int V_4 = V_17 -> V_21 ;
int V_5 = V_17 -> V_25 ;
if ( F_7 ( V_17 -> V_26 ) )
V_7 = F_1 ( V_17 , V_24 ,
& V_4 , & V_5 ) ;
if ( ! V_7 ) {
V_19 = F_8 ( V_17 -> V_20 , V_4 ,
V_23 , V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_2 ,
V_4 , V_19 ) ;
return V_19 ;
}
V_17 -> V_21 = V_4 ;
V_17 -> V_12 [ V_5 ] = V_24 ;
}
if ( F_7 ( V_17 -> V_26 ) ) {
F_9 ( V_17 -> V_26 , V_5 & 0x1 ) ;
V_17 -> V_25 = V_5 ;
}
return 0 ;
}
static int F_10 ( struct V_15 * V_16 , unsigned int V_27 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
int V_19 ;
int V_28 ;
switch ( V_27 ) {
case V_29 :
V_28 = V_30 ;
break;
case V_31 :
V_28 = 0 ;
break;
default:
return - V_32 ;
}
V_19 = F_8 ( V_17 -> V_20 , V_33 ,
V_30 , V_28 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_2 ,
V_33 , V_19 ) ;
return V_19 ;
}
static unsigned int F_11 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_18 ;
int V_19 ;
V_19 = F_4 ( V_17 -> V_20 , V_33 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_3 ,
V_33 , V_19 ) ;
return V_19 ;
}
return ( V_18 & V_30 ) ?
V_29 : V_31 ;
}
static int F_12 ( struct V_15 * V_16 ,
int V_34 )
{
struct V_1 * V_17 = F_3 ( V_16 ) ;
unsigned int V_35 ;
int V_19 ;
int V_36 ;
if ( V_34 < 25000 ) {
V_35 = V_37 ;
V_36 = 12000 ;
} else if ( V_34 < 50000 ) {
V_35 = V_38 ;
V_36 = 25000 ;
} else if ( V_34 < 200000 ) {
V_35 = V_39 ;
V_36 = 50000 ;
} else {
V_35 = V_40 ;
V_36 = 200000 ;
}
V_19 = F_8 ( V_17 -> V_20 , V_33 ,
V_41 , V_35 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_4 ,
V_33 , V_19 ) ;
return V_19 ;
}
static int F_13 ( struct V_1 * V_17 ,
struct V_42 * V_43 )
{
int V_19 ;
T_1 V_44 = 0 ;
T_1 V_45 = 0 ;
unsigned int V_18 ;
V_19 = F_4 ( V_17 -> V_20 , V_33 , & V_18 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_5 ,
V_33 , V_19 ) ;
return V_19 ;
}
V_44 = V_18 & V_41 ;
switch ( V_44 ) {
case V_37 :
V_17 -> V_46 . V_34 = 12000 ;
break;
case V_38 :
V_17 -> V_46 . V_34 = 25000 ;
break;
case V_39 :
V_17 -> V_46 . V_34 = 50000 ;
break;
case V_40 :
V_17 -> V_46 . V_34 = 200000 ;
break;
}
if ( V_43 -> V_47 & V_48 )
V_44 |= V_49 ;
if ( ! ( V_43 -> V_47 & V_50 ) )
V_44 |= V_51 ;
if ( V_43 -> V_47 & V_52 )
V_44 |= V_53 ;
if ( V_43 -> V_47 & V_54 ) {
V_44 |= V_55 ;
V_17 -> V_46 . V_56 = 20 ;
} else {
V_17 -> V_46 . V_56 = 240 ;
}
if ( V_43 -> V_47 & V_57 )
V_44 |= V_58 ;
if ( ! ( V_43 -> V_47 & V_59 ) )
V_45 |= V_60 ;
switch ( V_43 -> V_47 & V_61 ) {
case V_62 :
V_45 |= V_63 ;
break;
case V_64 :
V_45 |= V_65 ;
break;
case V_66 :
V_45 |= V_67 ;
break;
case V_68 :
V_45 |= V_69 ;
break;
}
switch ( V_43 -> V_47 & V_70 ) {
case V_71 :
V_45 |= V_72 ;
break;
case V_73 :
V_45 |= V_74 ;
break;
case V_75 :
V_45 |= V_76 ;
break;
case V_77 :
V_45 |= V_78 ;
break;
}
V_19 = F_14 ( V_17 -> V_20 , V_33 , V_44 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_6 ,
V_33 , V_19 ) ;
return V_19 ;
}
V_19 = F_14 ( V_17 -> V_20 , V_79 , V_45 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_6 ,
V_79 , V_19 ) ;
return V_19 ;
}
if ( V_17 -> V_80 && ( V_17 -> V_81 == V_82 ) ) {
V_19 = F_8 ( V_17 -> V_20 , V_14 ,
V_83 , 0 ) ;
if ( V_19 < 0 )
F_5 ( V_17 -> V_22 , L_7 ,
V_14 , V_19 ) ;
}
return V_19 ;
}
static struct V_42 * F_15 (
struct V_84 * V_22 )
{
struct V_42 * V_43 ;
struct V_85 * V_86 = V_22 -> V_87 ;
int V_19 ;
T_2 V_88 ;
V_43 = F_16 ( V_22 , sizeof( * V_43 ) , V_89 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_90 = F_17 ( V_86 ,
L_8 ) ;
V_43 -> V_91 = F_18 ( V_86 , L_9 , 0 ) ;
V_43 -> V_26 = F_18 ( V_86 , L_10 , 0 ) ;
V_19 = F_19 ( V_86 , L_11 , & V_88 ) ;
if ( ! V_19 )
V_43 -> V_92 = V_88 ;
if ( F_17 ( V_86 , L_12 ) )
V_43 -> V_47 |= V_48 ;
if ( F_17 ( V_86 , L_13 ) )
V_43 -> V_47 |=
V_50 ;
if ( F_17 ( V_86 , L_14 ) )
V_43 -> V_47 |=
V_52 ;
if ( F_17 ( V_86 , L_15 ) )
V_43 -> V_47 |= V_57 ;
if ( F_17 ( V_86 , L_16 ) )
V_43 -> V_47 |= V_54 ;
return V_43 ;
}
static int F_20 ( struct V_93 * V_94 ,
const struct V_95 * V_81 )
{
struct V_42 * V_43 ;
struct V_96 * V_97 ;
struct V_98 V_99 = { } ;
struct V_15 * V_16 ;
struct V_1 * V_17 ;
bool V_100 = false ;
unsigned int V_101 ;
int V_19 ;
V_43 = F_21 ( & V_94 -> V_22 ) ;
if ( ! V_43 && V_94 -> V_22 . V_87 ) {
V_43 = F_15 ( & V_94 -> V_22 ) ;
V_100 = true ;
}
if ( ! V_43 ) {
F_5 ( & V_94 -> V_22 , L_17 ) ;
return - V_102 ;
}
if ( ( V_43 -> V_26 == - V_103 ) ||
( V_43 -> V_91 == - V_103 ) )
return - V_103 ;
V_17 = F_16 ( & V_94 -> V_22 , sizeof( * V_17 ) , V_89 ) ;
if ( ! V_17 )
return - V_104 ;
V_17 -> V_20 = F_22 ( V_94 , & V_105 ) ;
if ( F_23 ( V_17 -> V_20 ) ) {
V_19 = F_24 ( V_17 -> V_20 ) ;
F_5 ( & V_94 -> V_22 , L_18 , V_19 ) ;
return V_19 ;
}
if ( V_94 -> V_22 . V_87 ) {
const struct V_106 * V_107 ;
V_107 = F_25 ( F_26 ( V_108 ) ,
& V_94 -> V_22 ) ;
if ( ! V_107 )
return - V_109 ;
V_17 -> V_81 = ( T_2 ) ( ( V_110 ) V_107 -> V_18 ) ;
} else {
V_17 -> V_81 = V_81 -> V_111 ;
}
V_19 = F_4 ( V_17 -> V_20 , V_112 , & V_101 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_94 -> V_22 , L_19 , V_19 ) ;
return V_19 ;
}
F_27 ( & V_94 -> V_22 , L_20 ,
( V_101 >> 4 ) & 0xF , ( V_101 >> 1 ) & 0x7 ) ;
F_28 ( V_94 , V_17 ) ;
V_17 -> V_113 = V_114 ;
V_17 -> V_22 = & V_94 -> V_22 ;
V_17 -> V_46 . V_115 = V_81 -> V_115 ;
V_17 -> V_46 . V_81 = 0 ;
V_17 -> V_46 . V_113 = & V_17 -> V_113 ;
V_17 -> V_46 . type = V_116 ;
V_17 -> V_46 . V_117 = V_118 ;
V_17 -> V_46 . V_119 = V_120 ;
V_17 -> V_46 . V_121 = V_122 ;
V_17 -> V_46 . V_123 = V_124 ;
V_17 -> V_26 = ( V_43 -> V_26 ) ? V_43 -> V_26 : - V_32 ;
V_17 -> V_91 = ( V_43 -> V_91 ) ? V_43 -> V_91 : - V_32 ;
V_17 -> V_80 = V_43 -> V_90 ;
V_17 -> V_25 = V_43 -> V_92 ;
V_17 -> V_21 = V_14 + V_43 -> V_92 ;
if ( F_7 ( V_17 -> V_91 ) )
V_17 -> V_80 = true ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
if ( F_7 ( V_17 -> V_26 ) ) {
int V_125 ;
int V_6 ;
V_125 = ( V_43 -> V_92 ) ?
V_126 : V_127 ;
V_19 = F_29 ( & V_94 -> V_22 , V_17 -> V_26 ,
V_125 , L_21 ) ;
if ( V_19 ) {
F_5 ( & V_94 -> V_22 ,
L_22 ,
V_17 -> V_26 , V_19 ) ;
return V_19 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 )
V_17 -> V_9 [ V_6 ] = V_6 ;
V_17 -> V_9 [ 0 ] = V_17 -> V_21 ;
V_17 -> V_9 [ V_17 -> V_21 ] = 0 ;
}
if ( V_100 )
V_43 -> V_128 = F_30 ( & V_94 -> V_22 ,
V_94 -> V_22 . V_87 , & V_17 -> V_46 ) ;
V_97 = V_43 -> V_128 ;
switch ( V_17 -> V_81 ) {
case V_82 :
if ( ! V_43 -> V_90 ) {
V_17 -> V_46 . V_129 = V_14 ;
V_17 -> V_46 . V_130 = V_83 ;
V_17 -> V_113 . V_131 = V_132 ;
V_17 -> V_113 . V_133 = V_134 ;
V_17 -> V_113 . V_135 = V_136 ;
break;
}
if ( F_7 ( V_17 -> V_91 ) ) {
V_99 . V_137 = V_127 ;
if ( V_97 && ( V_97 -> V_138 . V_139 ||
V_97 -> V_138 . V_140 ) )
V_99 . V_137 = V_126 ;
V_99 . V_141 = V_17 -> V_91 ;
}
break;
case V_142 :
if ( F_7 ( V_17 -> V_91 ) ) {
V_19 = F_29 ( & V_94 -> V_22 ,
V_17 -> V_91 , V_126 ,
L_23 ) ;
if ( V_19 ) {
F_5 ( & V_94 -> V_22 ,
L_24 ,
V_17 -> V_91 , V_19 ) ;
return V_19 ;
}
}
V_17 -> V_46 . V_129 = V_14 ;
V_17 -> V_46 . V_130 = V_83 ;
V_17 -> V_113 . V_131 = V_132 ;
V_17 -> V_113 . V_133 = V_134 ;
V_17 -> V_113 . V_135 = V_136 ;
break;
default:
break;
}
V_19 = F_13 ( V_17 , V_43 ) ;
if ( V_19 < 0 ) {
F_5 ( V_17 -> V_22 , L_25 , V_19 ) ;
return V_19 ;
}
V_99 . V_22 = & V_94 -> V_22 ;
V_99 . V_143 = V_43 -> V_128 ;
V_99 . V_111 = V_17 ;
V_99 . V_87 = V_94 -> V_22 . V_87 ;
V_99 . V_20 = V_17 -> V_20 ;
V_16 = F_31 ( & V_94 -> V_22 , & V_17 -> V_46 , & V_99 ) ;
if ( F_23 ( V_16 ) ) {
V_19 = F_24 ( V_16 ) ;
F_5 ( V_17 -> V_22 , L_26 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_144 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_144 ) ;
}
