static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned int V_5 = 0 , V_6 = 0 ;
unsigned int V_7 = 0 ;
int V_8 ;
switch ( V_4 -> type ) {
case V_9 :
case V_10 :
V_5 = 0 ;
break;
case V_11 :
case V_12 :
V_5 = V_13 | V_14 |
V_15 ;
if ( V_3 ) {
V_6 = V_13 ;
V_7 = V_16 ;
} else {
V_6 = V_14 | V_15 ;
V_7 = V_17 ;
}
V_8 = F_2 ( V_4 -> V_18 ,
V_19 ,
V_20 ,
V_7 ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 ,
L_1 , V_8 ) ;
break;
default:
V_5 = V_22 ;
if ( V_3 )
V_6 = V_22 ;
break;
}
F_4 ( V_4 -> V_23 ) ;
V_4 -> V_24 = V_3 ;
if ( V_3 ) {
V_8 = F_2 ( V_4 -> V_18 ,
V_25 ,
V_26 |
V_27 , 0 ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 ,
L_2 ,
V_8 ) ;
}
if ( V_5 ) {
V_8 = F_2 ( V_4 -> V_18 , V_28 ,
V_5 , V_6 ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 , L_3 ,
V_8 ) ;
V_8 = F_2 ( V_4 -> V_18 , V_29 ,
V_5 , V_6 ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 , L_3 ,
V_8 ) ;
}
if ( ! V_3 ) {
V_8 = F_2 ( V_4 -> V_18 ,
V_25 ,
V_26 |
V_27 , V_4 -> V_30 ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 ,
L_4 ,
V_8 ) ;
}
F_5 ( V_4 -> V_23 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_31 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
V_31 %= V_2 -> V_32 ;
if ( V_4 -> V_33 . V_34 > 0 )
F_7 ( V_4 -> V_33 . V_34 ,
V_2 -> V_35 [ V_31 ] . V_36 ) ;
else
F_8 ( V_2 -> V_34 ,
V_2 -> V_35 [ V_31 ] . V_36 ) ;
F_2 ( V_4 -> V_18 , V_37 ,
V_38 ,
V_2 -> V_35 [ V_31 ] . V_39 <<
V_40 ) ;
F_2 ( V_4 -> V_18 , V_41 ,
V_42 , V_2 -> V_35 [ V_31 ] . V_43 ) ;
V_2 -> V_44 = V_31 ;
F_9 ( V_4 -> V_21 , L_5 , V_31 ) ;
}
static const char * F_10 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_35 [ 0 ] . V_39 ) {
case 1 :
return L_6 ;
case 2 :
return L_7 ;
case 3 :
return L_8 ;
default:
return L_9 ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
const char * V_45 = F_10 ( V_2 ) ;
struct V_46 * V_23 = V_4 -> V_23 ;
int V_8 ;
V_8 = F_12 ( V_23 , V_45 ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 , L_10 ,
V_45 , V_8 ) ;
F_13 ( V_23 ) ;
if ( ! V_4 -> V_33 . V_47 ) {
V_8 = F_14 ( V_4 -> V_23 , V_45 ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 , L_11 ,
V_45 , V_8 ) ;
F_13 ( V_23 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
bool V_48 ;
int V_8 ;
unsigned int V_31 ;
F_16 ( V_2 -> V_21 ) ;
if ( V_2 -> V_49 ) {
V_8 = F_17 ( V_2 -> V_50 , false ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 ,
L_12 ,
V_8 ) ;
}
}
V_8 = F_19 ( V_2 -> V_50 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_13 ,
V_8 ) ;
}
if ( V_2 -> V_51 ) {
F_20 ( V_4 -> V_18 , 0x80 , 0x3 ) ;
F_20 ( V_4 -> V_18 , 0x294 , 0 ) ;
F_20 ( V_4 -> V_18 , 0x80 , 0x0 ) ;
}
if ( V_2 -> V_49 && V_4 -> V_33 . V_52 )
V_31 = V_53 ;
else
V_31 = V_54 ;
F_2 ( V_4 -> V_18 ,
V_41 ,
V_55 , V_31 ) ;
F_11 ( V_2 ) ;
F_21 ( V_4 -> V_18 , V_37 ,
V_56 , V_56 ,
& V_48 ) ;
if ( ! V_48 ) {
F_22 ( V_2 -> V_50 ) ;
F_23 ( V_2 -> V_21 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
const char * V_45 = F_10 ( V_2 ) ;
struct V_46 * V_23 = V_4 -> V_23 ;
bool V_48 ;
int V_8 ;
F_21 ( V_4 -> V_18 , V_37 ,
V_56 , 0 ,
& V_48 ) ;
V_8 = F_14 ( V_23 , V_45 ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 ,
L_11 ,
V_45 , V_8 ) ;
F_13 ( V_23 ) ;
if ( V_2 -> V_51 ) {
F_20 ( V_4 -> V_18 , 0x80 , 0x3 ) ;
F_20 ( V_4 -> V_18 , 0x294 , 2 ) ;
F_20 ( V_4 -> V_18 , 0x80 , 0x0 ) ;
}
V_8 = F_17 ( V_2 -> V_50 , true ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_14 ,
V_8 ) ;
}
if ( V_48 ) {
F_22 ( V_2 -> V_50 ) ;
F_25 ( V_2 -> V_21 ) ;
F_23 ( V_2 -> V_21 ) ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned int V_6 , V_57 ;
int V_8 ;
V_8 = F_27 ( V_4 -> V_18 , V_58 , & V_6 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_15 ,
V_8 ) ;
return V_8 ;
}
switch ( V_2 -> V_59 ) {
case 0 :
if ( ! ( V_6 & V_60 ) ) {
F_18 ( V_4 -> V_21 , L_16 ,
V_6 ) ;
return - V_61 ;
}
V_6 &= V_62 ;
break;
case 1 :
if ( ! ( V_6 & V_63 ) ) {
F_18 ( V_4 -> V_21 , L_16 ,
V_6 ) ;
return - V_61 ;
}
V_8 = F_27 ( V_4 -> V_18 , V_64 , & V_6 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_17 ,
V_8 ) ;
return - V_61 ;
}
F_27 ( V_4 -> V_18 , V_65 ,
& V_57 ) ;
V_57 = ( V_57 & V_66 )
>> V_67 ;
if ( V_57 < F_28 ( V_68 ) - 1 &&
( V_6 < V_68 [ V_57 ] . V_69 ||
V_6 >= V_70 ) ) {
V_57 ++ ;
F_9 ( V_4 -> V_21 , L_18 ,
V_57 ) ;
F_2 ( V_4 -> V_18 ,
V_65 ,
V_66 ,
V_57 <<
V_67 ) ;
return - V_61 ;
}
if ( V_6 < V_68 [ V_57 ] . V_69 ||
V_6 >= V_70 ) {
F_9 ( V_4 -> V_21 , L_19 ) ;
return V_71 ;
}
F_9 ( V_4 -> V_21 , L_20 ,
V_6 , V_57 ) ;
V_6 = V_68 [ V_57 ] . V_72
/ ( ( V_6 * 100 ) -
V_68 [ V_57 ] . V_73 ) ;
break;
case 2 :
if ( ! ( V_6 & V_63 ) ) {
F_18 ( V_4 -> V_21 , L_16 ,
V_6 ) ;
return - V_61 ;
}
V_6 &= V_74 ;
V_6 /= 2 ;
F_27 ( V_4 -> V_18 , V_65 ,
& V_57 ) ;
V_57 = ( V_57 & V_66 )
>> V_67 ;
if ( V_57 < F_28 ( V_75 ) - 1 &&
( V_6 >= V_75 [ V_57 ] . V_76 ) ) {
V_57 ++ ;
F_9 ( V_4 -> V_21 , L_21 ,
V_75 [ V_57 ] . V_77 ,
V_75 [ V_57 ] . V_76 ) ;
F_2 ( V_4 -> V_18 ,
V_65 ,
V_66 ,
V_57 <<
V_67 ) ;
return - V_61 ;
}
if ( V_57 && ( V_6 < V_75 [ V_57 ] . V_77 ) ) {
F_9 ( V_4 -> V_21 , L_22 ,
V_75 [ V_57 ] . V_77 ) ;
V_6 = V_75 [ V_57 ] . V_77 ;
}
break;
default:
F_3 ( V_4 -> V_21 , L_23 ,
V_2 -> V_59 ) ;
return - V_78 ;
}
F_9 ( V_4 -> V_21 , L_24 , V_6 ) ;
return V_6 ;
}
static int F_29 ( struct V_1 * V_2 , int * V_79 ,
bool * V_80 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_81 = V_4 -> V_33 . V_82 ;
if ( V_4 -> V_33 . V_83 ) {
V_2 -> V_84 [ V_2 -> V_85 ++ ] = * V_79 ;
if ( V_81 && V_2 -> V_85 == 1 ) {
F_9 ( V_4 -> V_21 , L_25 ) ;
F_2 ( V_4 -> V_18 ,
V_41 ,
V_55 |
V_42 ,
V_86 |
V_2 -> V_35 [ 0 ] . V_43 ) ;
F_7 ( V_81 , 1 ) ;
F_2 ( V_4 -> V_18 ,
V_65 ,
V_87 , V_87 ) ;
return - V_61 ;
}
F_9 ( V_4 -> V_21 , L_26 ,
V_2 -> V_84 [ 0 ] , V_2 -> V_84 [ 1 ] ) ;
* V_79 = V_2 -> V_84 [ 0 ] ;
if ( * V_79 >= V_71 && ! V_2 -> V_88 ) {
F_9 ( V_4 -> V_21 , L_27 ) ;
V_2 -> V_85 = 0 ;
V_2 -> V_88 = true ;
F_30 ( V_2 ) ;
F_31 ( V_2 -> V_21 ) ;
return - V_61 ;
}
if ( ! V_81 || V_2 -> V_84 [ 1 ] > 50 ) {
F_9 ( V_4 -> V_21 , L_28 ) ;
* V_80 = true ;
V_2 -> V_49 = true ;
} else {
F_9 ( V_4 -> V_21 , L_29 ) ;
}
F_2 ( V_4 -> V_18 ,
V_41 ,
V_42 ,
V_2 -> V_35 [ 0 ] . V_43 ) ;
}
return 0 ;
}
static T_1 F_32 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
struct V_4 * V_4 = V_2 -> V_4 ;
int V_81 = V_4 -> V_33 . V_82 ;
unsigned int V_91 = V_92 ;
int V_8 , V_79 ;
bool V_80 = false ;
F_33 ( & V_2 -> V_93 ) ;
if ( ! V_2 -> V_94 ) {
F_3 ( V_4 -> V_21 , L_30 ) ;
F_34 ( & V_2 -> V_93 ) ;
return V_95 ;
}
V_8 = F_35 ( V_2 -> V_96 , V_97 ) ;
if ( V_8 < 0 ) {
F_18 ( V_4 -> V_21 , L_31 ,
V_8 ) ;
goto V_98;
} else if ( ! V_8 ) {
F_9 ( V_4 -> V_21 , L_32 ) ;
goto V_99;
}
V_8 = F_26 ( V_2 ) ;
if ( V_8 == - V_61 )
goto V_98;
else if ( V_8 < 0 )
goto V_99;
V_79 = V_8 ;
F_2 ( V_4 -> V_18 ,
V_65 ,
V_66 | V_87 ,
0 ) ;
V_8 = F_29 ( V_2 , & V_79 , & V_80 ) ;
if ( V_8 == - V_61 )
goto V_98;
else if ( V_8 < 0 )
goto V_99;
if ( V_79 >= 5000 )
V_91 = V_100 ;
else
V_91 = V_92 ;
V_8 = F_36 ( V_2 -> V_96 , V_91 , true ) ;
if ( V_8 != 0 )
F_18 ( V_4 -> V_21 , L_33 ,
V_8 ) ;
V_99:
F_2 ( V_4 -> V_18 ,
V_65 ,
V_66 | V_87 ,
0 ) ;
F_1 ( V_2 , false ) ;
if ( V_81 )
F_7 ( V_81 , 0 ) ;
F_2 ( V_4 -> V_18 ,
V_41 ,
V_55 , V_54 ) ;
if ( V_80 || V_2 -> V_80 )
F_15 ( V_2 ) ;
if ( V_2 -> V_94 ) {
F_23 ( V_2 -> V_21 ) ;
V_2 -> V_94 = false ;
}
V_2 -> V_101 = true ;
V_98:
F_34 ( & V_2 -> V_93 ) ;
return V_102 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_8 ;
if ( V_2 -> V_101 )
return;
F_9 ( V_4 -> V_21 , L_34 ) ;
F_16 ( V_2 -> V_21 ) ;
V_2 -> V_94 = true ;
if ( V_2 -> V_80 )
F_24 ( V_2 ) ;
F_1 ( V_2 , true ) ;
V_8 = F_2 ( V_4 -> V_18 ,
V_41 ,
V_55 ,
V_4 -> V_33 . V_103 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_35 , V_8 ) ;
goto V_104;
}
V_8 = F_2 ( V_4 -> V_18 , V_65 ,
V_87 , V_87 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_36 ,
V_8 ) ;
goto V_104;
}
return;
V_104:
F_2 ( V_4 -> V_18 , V_41 ,
V_55 , V_54 ) ;
V_8 = F_36 ( V_2 -> V_96 , V_92 , true ) ;
if ( V_8 != 0 )
F_18 ( V_4 -> V_21 , L_37 , V_8 ) ;
if ( V_2 -> V_80 )
F_15 ( V_2 ) ;
V_2 -> V_94 = false ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
int V_105 = 32 ;
bool V_80 ;
int V_8 ;
F_9 ( V_4 -> V_21 , L_38 ) ;
F_38 ( V_2 -> V_21 ) ;
V_2 -> V_94 = true ;
F_1 ( V_2 , true ) ;
V_8 = F_2 ( V_4 -> V_18 ,
V_41 ,
V_42 | V_55 ,
V_2 -> V_35 [ 0 ] . V_43 |
V_4 -> V_33 . V_103 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_35 , V_8 ) ;
goto V_104;
}
if ( V_4 -> V_33 . V_106 ) {
V_8 = F_2 ( V_4 -> V_18 ,
V_65 ,
V_87 , V_87 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 ,
L_36 ,
V_8 ) ;
goto V_104;
}
} else {
F_29 ( V_2 , & V_105 , & V_80 ) ;
}
return;
V_104:
F_2 ( V_4 -> V_18 , V_41 ,
V_55 , V_54 ) ;
V_8 = F_36 ( V_2 -> V_96 , V_92 , true ) ;
if ( V_8 != 0 )
F_18 ( V_4 -> V_21 , L_37 , V_8 ) ;
V_2 -> V_94 = false ;
}
static void F_39 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_40 ( V_108 ,
struct V_1 ,
V_109 . V_108 ) ;
F_33 ( & V_2 -> V_93 ) ;
F_9 ( V_2 -> V_4 -> V_21 , L_39 ) ;
V_2 -> V_49 = false ;
F_37 ( V_2 ) ;
F_24 ( V_2 ) ;
F_34 ( & V_2 -> V_93 ) ;
}
static void F_41 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_40 ( V_108 ,
struct V_1 ,
V_110 . V_108 ) ;
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned int V_6 = 0 , V_111 ;
int V_8 , V_112 , V_113 ;
F_42 ( & V_2 -> V_109 ) ;
F_33 ( & V_2 -> V_93 ) ;
V_8 = F_35 ( V_2 -> V_96 , V_97 ) ;
if ( V_8 < 0 ) {
F_18 ( V_4 -> V_21 , L_31 ,
V_8 ) ;
F_34 ( & V_2 -> V_93 ) ;
return;
} else if ( ! V_8 ) {
F_9 ( V_4 -> V_21 , L_40 ) ;
F_34 ( & V_2 -> V_93 ) ;
return;
}
if ( V_2 -> V_49 && V_4 -> V_33 . V_52 ) {
F_2 ( V_4 -> V_18 , V_37 ,
V_56 , 0 ) ;
V_8 = F_27 ( V_4 -> V_18 , V_114 , & V_6 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 ,
L_41 ,
V_8 ) ;
F_34 ( & V_2 -> V_93 ) ;
return;
}
F_9 ( V_4 -> V_21 , L_42 , V_6 ) ;
V_6 &= V_115 ;
if ( V_6 < F_28 ( V_116 ) )
V_6 = V_116 [ V_6 ] ;
else
V_6 = V_117 ;
if ( V_6 <= V_118 )
V_6 = V_119 | V_120 ;
else if ( V_6 <= V_121 )
V_6 = V_119 | V_122 ;
else if ( V_6 <= V_123 )
V_6 = V_119 | V_124 ;
else
V_6 = V_124 ;
}
for ( V_112 = 0 ; V_112 < 10 && ! ( V_6 & V_125 ) ; V_112 ++ ) {
V_8 = F_27 ( V_4 -> V_18 , V_126 , & V_6 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 ,
L_43 , V_8 ) ;
F_34 ( & V_2 -> V_93 ) ;
return;
}
F_9 ( V_4 -> V_21 , L_44 , V_6 ) ;
if ( ! ( V_6 & V_127 ) ) {
F_3 ( V_4 -> V_21 ,
L_45 ) ;
F_34 ( & V_2 -> V_93 ) ;
return;
}
}
if ( V_112 == 10 && ! ( V_6 & V_125 ) ) {
F_18 ( V_4 -> V_21 , L_46 ) ;
F_34 ( & V_2 -> V_93 ) ;
return;
}
if ( ! ( V_6 & V_119 ) ) {
F_3 ( V_4 -> V_21 , L_47 ) ;
V_2 -> V_80 = false ;
F_24 ( V_2 ) ;
V_2 -> V_49 = false ;
F_37 ( V_2 ) ;
goto V_128;
}
if ( V_2 -> V_49 && ( V_6 & V_124 ) ) {
V_2 -> V_80 = true ;
V_2 -> V_49 = false ;
F_37 ( V_2 ) ;
V_8 = F_36 ( V_2 -> V_96 ,
V_129 , true ) ;
if ( V_8 != 0 )
F_18 ( V_4 -> V_21 , L_48 ,
V_8 ) ;
V_8 = F_17 ( V_2 -> V_50 , true ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_14 ,
V_8 ) ;
}
goto V_128;
}
if ( V_2 -> V_49 && ( V_6 & V_130 ) ) {
if ( V_2 -> V_131 >= V_2 -> V_32 * 10 ) {
F_9 ( V_4 -> V_21 , L_49 ) ;
V_2 -> V_49 = false ;
F_37 ( V_2 ) ;
F_24 ( V_2 ) ;
} else {
V_2 -> V_44 ++ ;
if ( V_2 -> V_44 == V_2 -> V_32 )
V_2 -> V_44 = 0 ;
F_6 ( V_2 , V_2 -> V_44 ) ;
V_2 -> V_131 ++ ;
}
goto V_128;
}
if ( V_6 & V_132 ) {
if ( V_2 -> V_80 ) {
F_9 ( V_4 -> V_21 , L_50 ) ;
V_111 = V_6 & V_133 ;
V_111 >>= V_134 ;
for ( V_112 = 0 ; V_112 < V_2 -> V_135 ; V_112 ++ )
F_43 ( V_2 -> V_136 ,
V_2 -> V_137 [ V_112 ] . V_113 , 0 ) ;
F_44 ( ! V_111 ) ;
F_44 ( F_45 ( V_111 ) - 1 >= V_2 -> V_135 ) ;
if ( V_111 && F_45 ( V_111 ) - 1 < V_2 -> V_135 ) {
V_113 = V_2 -> V_137 [ F_45 ( V_111 ) - 1 ] . V_113 ;
F_43 ( V_2 -> V_136 , V_113 , 1 ) ;
F_46 ( V_2 -> V_136 ) ;
}
} else if ( V_2 -> V_49 ) {
F_9 ( V_4 -> V_21 , L_51 ) ;
V_2 -> V_49 = false ;
F_24 ( V_2 ) ;
F_37 ( V_2 ) ;
} else {
F_3 ( V_4 -> V_21 , L_52 ,
V_6 ) ;
}
} else {
F_9 ( V_4 -> V_21 , L_53 ) ;
for ( V_112 = 0 ; V_112 < V_2 -> V_135 ; V_112 ++ )
F_43 ( V_2 -> V_136 ,
V_2 -> V_137 [ V_112 ] . V_113 , 0 ) ;
F_46 ( V_2 -> V_136 ) ;
F_11 ( V_2 ) ;
}
V_128:
if ( V_2 -> V_49 ) {
if ( V_4 -> V_33 . V_52 )
F_2 ( V_4 -> V_18 ,
V_37 ,
V_56 ,
V_56 ) ;
F_47 ( V_138 ,
& V_2 -> V_109 ,
F_48 ( V_2 -> V_139 ) ) ;
}
F_25 ( V_2 -> V_21 ) ;
F_34 ( & V_2 -> V_93 ) ;
}
static T_1 F_49 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
struct V_4 * V_4 = V_2 -> V_4 ;
int V_140 = V_4 -> V_33 . V_141 ;
F_42 ( & V_2 -> V_110 ) ;
F_42 ( & V_2 -> V_109 ) ;
F_33 ( & V_2 -> V_93 ) ;
if ( ! V_2 -> V_49 )
V_140 = 0 ;
F_34 ( & V_2 -> V_93 ) ;
if ( V_140 )
F_47 ( V_138 ,
& V_2 -> V_110 ,
F_48 ( V_140 ) ) ;
else
F_41 ( & V_2 -> V_110 . V_108 ) ;
return V_102 ;
}
static void F_50 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_40 ( V_108 ,
struct V_1 ,
V_142 . V_108 ) ;
F_33 ( & V_2 -> V_93 ) ;
F_30 ( V_2 ) ;
F_34 ( & V_2 -> V_93 ) ;
}
static T_1 F_51 ( int V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned int V_6 , V_143 , V_5 ;
bool V_144 , V_145 ;
int V_8 , V_112 ;
V_144 = F_42 ( & V_2 -> V_142 ) ;
V_145 = F_42 ( & V_2 -> V_109 ) ;
F_38 ( V_2 -> V_21 ) ;
F_33 ( & V_2 -> V_93 ) ;
if ( V_2 -> V_146 ) {
V_5 = V_147 ;
V_143 = 0 ;
} else {
V_5 = V_148 ;
if ( V_4 -> V_33 . V_149 )
V_143 = 0 ;
else
V_143 = V_148 ;
}
V_8 = F_27 ( V_4 -> V_18 , V_150 , & V_6 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_54 ,
V_8 ) ;
F_34 ( & V_2 -> V_93 ) ;
F_23 ( V_2 -> V_21 ) ;
return V_95 ;
}
V_6 &= V_5 ;
if ( V_6 == V_2 -> V_151 ) {
F_9 ( V_4 -> V_21 , L_55 ) ;
if ( V_144 )
F_47 ( V_138 ,
& V_2 -> V_142 ,
F_48 ( V_152 ) ) ;
if ( V_145 ) {
int V_139 = V_2 -> V_139 ;
F_47 ( V_138 ,
& V_2 -> V_109 ,
F_48 ( V_139 ) ) ;
}
goto V_98;
}
V_2 -> V_151 = V_6 ;
if ( V_2 -> V_151 == V_143 ) {
F_9 ( V_4 -> V_21 , L_56 ) ;
V_8 = F_36 ( V_2 -> V_96 ,
V_97 , true ) ;
if ( V_8 != 0 )
F_18 ( V_4 -> V_21 , L_57 ,
V_8 ) ;
if ( ! V_4 -> V_33 . V_83 ) {
V_2 -> V_49 = true ;
V_2 -> V_80 = false ;
V_2 -> V_131 = 0 ;
F_15 ( V_2 ) ;
} else {
F_47 ( V_138 ,
& V_2 -> V_142 ,
F_48 ( V_152 ) ) ;
}
if ( V_2 -> V_146 || ! V_4 -> V_33 . V_149 )
F_2 ( V_4 -> V_18 ,
V_153 ,
V_154 |
V_155 , 0 ) ;
} else {
F_9 ( V_4 -> V_21 , L_58 ) ;
F_24 ( V_2 ) ;
V_2 -> V_85 = 0 ;
for ( V_112 = 0 ; V_112 < F_28 ( V_2 -> V_84 ) ; V_112 ++ )
V_2 -> V_84 [ V_112 ] = 0 ;
V_2 -> V_80 = false ;
V_2 -> V_101 = false ;
V_2 -> V_88 = false ;
for ( V_112 = 0 ; V_112 < V_2 -> V_135 ; V_112 ++ )
F_43 ( V_2 -> V_136 ,
V_2 -> V_137 [ V_112 ] . V_113 , 0 ) ;
F_46 ( V_2 -> V_136 ) ;
for ( V_112 = 0 ; V_112 < F_28 ( V_156 ) - 1 ; V_112 ++ ) {
V_8 = F_36 ( V_2 -> V_96 ,
V_156 [ V_112 ] , false ) ;
if ( V_8 != 0 )
F_18 ( V_4 -> V_21 ,
L_59 , V_8 ) ;
}
F_2 ( V_4 -> V_18 ,
V_153 ,
V_154 | V_155 ,
V_154 | V_155 ) ;
}
if ( V_4 -> V_33 . V_139 )
V_2 -> V_139 = V_4 -> V_33 . V_139 ;
else
V_2 -> V_139 = V_157 ;
V_98:
F_20 ( V_4 -> V_18 , V_158 ,
V_159 |
V_160 |
V_161 |
V_162 ) ;
F_34 ( & V_2 -> V_93 ) ;
F_25 ( V_2 -> V_21 ) ;
F_23 ( V_2 -> V_21 ) ;
return V_102 ;
}
static void F_52 ( struct V_4 * V_4 , int V_163 ,
unsigned int V_164 )
{
int V_165 ;
unsigned int V_5 ;
V_165 = V_166 - ( V_163 / 2 ) ;
if ( ! ( V_163 % 2 ) ) {
V_5 = 0x3f00 ;
V_164 <<= 8 ;
} else {
V_5 = 0x3f ;
}
F_2 ( V_4 -> V_18 , V_165 , V_5 , V_164 ) ;
}
static int F_53 ( struct V_167 * V_21 ,
struct V_4 * V_4 )
{
const char * const V_168 = L_60 ;
const int V_169 = 3 ;
struct V_170 * V_171 ;
int V_172 , V_8 ;
int V_112 , V_173 ;
T_2 * V_174 ;
V_172 = F_54 ( V_4 -> V_21 , V_168 , NULL , 0 ) ;
if ( V_172 <= 0 )
return 0 ;
V_174 = F_55 ( V_172 , sizeof( T_2 ) , V_175 ) ;
if ( ! V_174 )
return - V_176 ;
V_8 = F_54 ( V_4 -> V_21 , V_168 , V_174 , V_172 ) ;
if ( V_8 < 0 )
goto V_98;
V_172 /= V_169 ;
V_171 = F_56 ( V_21 ,
V_172 * sizeof( struct V_177 ) ,
V_175 ) ;
if ( ! V_171 ) {
V_8 = - V_176 ;
goto V_98;
}
for ( V_112 = 0 , V_173 = 0 ; V_112 < V_172 ; ++ V_112 ) {
V_171 [ V_112 ] . V_43 = V_174 [ V_173 ++ ] ? V_42 : 0 ;
V_171 [ V_112 ] . V_39 = V_174 [ V_173 ++ ] ;
V_171 [ V_112 ] . V_36 = V_174 [ V_173 ++ ] ;
}
V_4 -> V_33 . V_171 = V_171 ;
V_4 -> V_33 . V_178 = V_172 ;
V_98:
F_57 ( V_174 ) ;
return V_8 ;
}
static int F_58 ( struct V_167 * V_21 ,
struct V_4 * V_4 )
{
struct V_179 * V_33 = & V_4 -> V_33 ;
unsigned int V_6 = V_180 ;
int V_8 ;
F_59 ( V_4 -> V_21 , L_61 , & V_6 ) ;
switch ( V_6 ) {
case V_180 :
case V_86 :
V_33 -> V_103 = V_6 ;
break;
default:
F_18 ( V_4 -> V_21 ,
L_62 , V_6 ) ;
V_33 -> V_103 = V_180 ;
}
F_59 ( V_4 -> V_21 , L_63 ,
& V_33 -> V_141 ) ;
F_59 ( V_4 -> V_21 , L_64 ,
& V_33 -> V_181 ) ;
F_59 ( V_4 -> V_21 , L_65 ,
& V_33 -> V_182 ) ;
F_59 ( V_4 -> V_21 , L_66 ,
& V_33 -> V_183 ) ;
F_59 ( V_4 -> V_21 , L_67 ,
& V_33 -> V_139 ) ;
V_33 -> V_47 = F_60 ( V_4 -> V_21 ,
L_68 ) ;
V_33 -> V_52 = F_60 ( V_4 -> V_21 ,
L_69 ) ;
V_33 -> V_149 = F_60 ( V_4 -> V_21 ,
L_70 ) ;
F_59 ( V_4 -> V_21 , L_71 , & V_33 -> V_184 ) ;
V_33 -> V_185 = F_60 ( V_4 -> V_21 ,
L_72 ) ;
V_33 -> V_186 = F_60 ( V_4 -> V_21 ,
L_73 ) ;
V_8 = F_53 ( V_21 , V_4 ) ;
if ( V_8 < 0 )
F_18 ( V_4 -> V_21 , L_74 , V_8 ) ;
return 0 ;
}
static int F_61 ( struct V_187 * V_188 )
{
struct V_4 * V_4 = F_62 ( V_188 -> V_21 . V_189 ) ;
struct V_179 * V_33 = & V_4 -> V_33 ;
struct V_1 * V_2 ;
unsigned int V_6 ;
unsigned int V_190 ;
int V_191 , V_192 ;
int V_8 , V_31 , V_112 , V_173 ;
if ( ! V_4 -> V_23 || ! V_4 -> V_23 -> V_193 )
return - V_194 ;
V_2 = F_56 ( & V_188 -> V_21 , sizeof( * V_2 ) , V_175 ) ;
if ( ! V_2 )
return - V_176 ;
if ( ! F_63 ( V_4 -> V_21 ) )
F_58 ( & V_188 -> V_21 , V_4 ) ;
V_2 -> V_50 = F_64 ( & V_188 -> V_21 , L_9 ) ;
if ( F_65 ( V_2 -> V_50 ) ) {
V_8 = F_66 ( V_2 -> V_50 ) ;
F_18 ( V_4 -> V_21 , L_75 , V_8 ) ;
return V_8 ;
}
F_67 ( & V_2 -> V_93 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_21 = & V_188 -> V_21 ;
V_2 -> V_151 = ~ ( V_147 | V_148 ) ;
F_68 ( & V_2 -> V_142 , F_50 ) ;
F_68 ( & V_2 -> V_110 , F_41 ) ;
F_68 ( & V_2 -> V_109 , F_39 ) ;
F_69 ( V_188 , V_2 ) ;
switch ( V_4 -> type ) {
case V_195 :
switch ( V_4 -> V_196 ) {
case 0 :
V_2 -> V_51 = true ;
break;
default:
V_2 -> V_146 = true ;
V_2 -> V_59 = 1 ;
break;
}
break;
case V_11 :
case V_12 :
switch ( V_4 -> V_196 ) {
case 0 ... 2 :
break;
default:
V_2 -> V_146 = true ;
V_2 -> V_59 = 2 ;
break;
}
break;
case V_9 :
case V_10 :
V_2 -> V_146 = true ;
V_2 -> V_59 = 2 ;
break;
default:
break;
}
V_2 -> V_96 = F_70 ( & V_188 -> V_21 , V_156 ) ;
if ( F_65 ( V_2 -> V_96 ) ) {
F_18 ( & V_188 -> V_21 , L_76 ) ;
return - V_176 ;
}
V_8 = F_71 ( & V_188 -> V_21 , V_2 -> V_96 ) ;
if ( V_8 < 0 ) {
F_18 ( V_4 -> V_21 , L_77 ,
V_8 ) ;
return V_8 ;
}
V_2 -> V_136 = F_72 ( & V_188 -> V_21 ) ;
if ( ! V_2 -> V_136 ) {
F_18 ( V_4 -> V_21 , L_78 ) ;
V_8 = - V_176 ;
goto V_197;
}
V_2 -> V_136 -> V_198 = L_79 ;
V_2 -> V_136 -> V_199 = L_80 ;
if ( V_33 -> V_178 ) {
V_2 -> V_35 = V_33 -> V_171 ;
V_2 -> V_32 = V_33 -> V_178 ;
} else {
V_2 -> V_35 = V_200 ;
V_2 -> V_32 = F_28 ( V_200 ) ;
}
if ( V_4 -> V_33 . V_184 > 0 )
F_2 ( V_4 -> V_18 , V_201 ,
V_202 , V_4 -> V_33 . V_184 ) ;
if ( V_4 -> V_33 . V_34 > 0 ) {
if ( V_2 -> V_35 [ 0 ] . V_36 )
V_31 = V_203 ;
else
V_31 = V_204 ;
V_8 = F_73 ( & V_188 -> V_21 ,
V_4 -> V_33 . V_34 ,
V_31 ,
L_81 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_82 ,
V_4 -> V_33 . V_34 , V_8 ) ;
goto V_197;
}
} else {
if ( V_2 -> V_35 [ 0 ] . V_36 )
V_31 = V_205 ;
else
V_31 = V_206 ;
V_2 -> V_34 = F_74 ( V_4 -> V_21 ,
L_83 ,
V_206 ) ;
if ( F_65 ( V_2 -> V_34 ) ) {
V_8 = F_66 ( V_2 -> V_34 ) ;
F_18 ( V_4 -> V_21 ,
L_84 ,
V_8 ) ;
goto V_197;
}
}
if ( V_4 -> V_33 . V_82 > 0 ) {
V_8 = F_73 ( & V_188 -> V_21 ,
V_4 -> V_33 . V_82 ,
V_204 ,
L_85 ) ;
if ( V_8 != 0 ) {
F_18 ( V_4 -> V_21 , L_82 ,
V_4 -> V_33 . V_82 , V_8 ) ;
goto V_207;
}
}
if ( V_4 -> V_33 . V_181 )
F_2 ( V_4 -> V_18 , V_37 ,
V_208 ,
V_4 -> V_33 . V_181
<< V_209 ) ;
if ( V_4 -> V_33 . V_182 )
F_2 ( V_4 -> V_18 , V_37 ,
V_210 ,
V_4 -> V_33 . V_182
<< V_211 ) ;
switch ( V_4 -> V_33 . V_183 ) {
case V_212 :
F_2 ( V_4 -> V_18 , V_37 ,
V_213 ,
V_214 ) ;
break;
case V_215 :
F_2 ( V_4 -> V_18 , V_37 ,
V_213 , 0 ) ;
break;
default:
break;
}
F_75 ( F_28 ( V_116 ) <
V_216 ) ;
if ( V_4 -> V_33 . V_135 ) {
V_2 -> V_137 = V_33 -> V_137 ;
V_2 -> V_135 = V_33 -> V_135 ;
} else {
V_2 -> V_137 = V_217 ;
V_2 -> V_135 = F_28 ( V_217 ) ;
}
if ( V_4 -> V_33 . V_135 > V_218 ) {
F_18 ( V_4 -> V_21 , L_86 ,
V_4 -> V_33 . V_135 ) ;
}
if ( V_2 -> V_135 > 1 ) {
for ( V_112 = 1 ; V_112 < V_2 -> V_135 ; V_112 ++ ) {
if ( V_2 -> V_137 [ V_112 - 1 ] . V_76 >
V_2 -> V_137 [ V_112 ] . V_76 ) {
F_18 ( V_4 -> V_21 ,
L_87 ) ;
V_8 = - V_78 ;
goto V_207;
}
}
}
F_2 ( V_4 -> V_18 , V_219 ,
V_220 , 0x81 ) ;
for ( V_112 = 0 ; V_112 < V_2 -> V_135 ; V_112 ++ ) {
for ( V_173 = 0 ; V_173 < V_216 ; V_173 ++ )
if ( V_116 [ V_173 ] >= V_2 -> V_137 [ V_112 ] . V_76 )
break;
if ( V_173 == V_216 ) {
F_18 ( V_4 -> V_21 , L_88 ,
V_2 -> V_137 [ V_112 ] . V_76 ) ;
V_8 = - V_78 ;
goto V_207;
}
F_9 ( V_4 -> V_21 , L_89 ,
V_116 [ V_173 ] , V_112 ) ;
F_52 ( V_4 , V_112 , V_173 ) ;
F_76 ( V_2 -> V_136 , V_221 ,
V_2 -> V_137 [ V_112 ] . V_113 ) ;
F_2 ( V_4 -> V_18 , V_219 ,
1 << V_112 , 1 << V_112 ) ;
}
for (; V_112 < V_218 ; V_112 ++ )
F_52 ( V_4 , V_112 , 0x3f ) ;
if ( V_2 -> V_146 ) {
if ( V_4 -> V_33 . V_185 ) {
V_6 = 0xc101 ;
if ( V_4 -> V_33 . V_186 )
V_6 &= ~ V_222 ;
F_20 ( V_4 -> V_18 , V_223 ,
V_6 ) ;
if ( V_4 -> V_33 . V_149 )
V_190 = V_224 ;
else
V_190 = V_225 ;
} else {
if ( V_4 -> V_33 . V_149 )
V_190 = V_226 ;
else
V_190 = V_227 ;
}
F_2 ( V_4 -> V_18 ,
V_228 ,
V_229 , V_190 ) ;
F_2 ( V_4 -> V_18 ,
V_153 ,
V_154 ,
V_154 ) ;
}
F_6 ( V_2 , 0 ) ;
F_77 ( & V_188 -> V_21 ) ;
F_78 ( & V_188 -> V_21 ) ;
F_38 ( & V_188 -> V_21 ) ;
if ( V_2 -> V_146 ) {
V_192 = V_230 ;
V_191 = V_231 ;
} else {
V_192 = V_232 ;
V_191 = V_233 ;
}
V_8 = F_79 ( V_4 , V_192 ,
L_90 , F_51 , V_2 ) ;
if ( V_8 != 0 ) {
F_18 ( & V_188 -> V_21 , L_91 ,
V_8 ) ;
goto V_207;
}
V_8 = F_80 ( V_4 , V_192 , 1 ) ;
if ( V_8 != 0 ) {
F_18 ( & V_188 -> V_21 , L_92 ,
V_8 ) ;
goto V_234;
}
V_8 = F_79 ( V_4 , V_191 ,
L_93 , F_51 , V_2 ) ;
if ( V_8 != 0 ) {
F_18 ( & V_188 -> V_21 , L_94 , V_8 ) ;
goto V_235;
}
V_8 = F_80 ( V_4 , V_191 , 1 ) ;
if ( V_8 != 0 ) {
F_18 ( & V_188 -> V_21 , L_95 ,
V_8 ) ;
goto V_236;
}
V_8 = F_79 ( V_4 , V_237 ,
L_96 , F_49 , V_2 ) ;
if ( V_8 != 0 ) {
F_18 ( & V_188 -> V_21 , L_97 , V_8 ) ;
goto V_238;
}
V_8 = F_79 ( V_4 , V_239 ,
L_85 , F_32 , V_2 ) ;
if ( V_8 != 0 ) {
F_18 ( & V_188 -> V_21 , L_98 , V_8 ) ;
goto V_240;
}
F_81 ( V_4 ) ;
F_2 ( V_4 -> V_18 , V_153 ,
V_155 , V_155 ) ;
F_2 ( V_4 -> V_18 , V_241 ,
V_242 , V_242 ) ;
V_8 = F_17 ( V_2 -> V_50 , true ) ;
if ( V_8 != 0 )
F_3 ( V_4 -> V_21 , L_99 ,
V_8 ) ;
F_31 ( & V_188 -> V_21 ) ;
V_8 = F_82 ( V_2 -> V_136 ) ;
if ( V_8 ) {
F_18 ( & V_188 -> V_21 , L_100 , V_8 ) ;
goto V_243;
}
return 0 ;
V_243:
F_83 ( V_4 , V_239 , V_2 ) ;
V_240:
F_83 ( V_4 , V_237 , V_2 ) ;
V_238:
F_80 ( V_4 , V_191 , 0 ) ;
V_236:
F_83 ( V_4 , V_191 , V_2 ) ;
V_235:
F_80 ( V_4 , V_192 , 0 ) ;
V_234:
F_83 ( V_4 , V_192 , V_2 ) ;
V_207:
F_84 ( V_2 -> V_34 ) ;
V_197:
F_85 ( & V_188 -> V_21 ) ;
return V_8 ;
}
static int F_86 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_87 ( V_188 ) ;
struct V_4 * V_4 = V_2 -> V_4 ;
int V_192 , V_191 ;
F_84 ( V_2 -> V_34 ) ;
F_85 ( & V_188 -> V_21 ) ;
F_2 ( V_4 -> V_18 ,
V_228 ,
V_229 , 0 ) ;
if ( V_2 -> V_146 ) {
V_192 = V_230 ;
V_191 = V_231 ;
} else {
V_192 = V_232 ;
V_191 = V_233 ;
}
F_80 ( V_4 , V_192 , 0 ) ;
F_80 ( V_4 , V_191 , 0 ) ;
F_83 ( V_4 , V_239 , V_2 ) ;
F_83 ( V_4 , V_237 , V_2 ) ;
F_83 ( V_4 , V_192 , V_2 ) ;
F_83 ( V_4 , V_191 , V_2 ) ;
F_42 ( & V_2 -> V_142 ) ;
F_2 ( V_4 -> V_18 , V_241 ,
V_242 , 0 ) ;
F_88 ( V_4 ) ;
return 0 ;
}
