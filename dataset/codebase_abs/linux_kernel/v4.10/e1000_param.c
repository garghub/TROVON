static int F_1 ( unsigned int * V_1 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( * V_1 == V_6 ) {
* V_1 = V_3 -> V_7 ;
return 0 ;
}
switch ( V_3 -> type ) {
case V_8 :
switch ( * V_1 ) {
case V_9 :
F_2 ( L_1 , V_3 -> V_10 ) ;
return 0 ;
case V_11 :
F_2 ( L_2 , V_3 -> V_10 ) ;
return 0 ;
}
break;
case V_12 :
if ( * V_1 >= V_3 -> V_13 . V_14 . V_15 && * V_1 <= V_3 -> V_13 . V_14 . V_16 ) {
F_2 ( L_3 , V_3 -> V_10 , * V_1 ) ;
return 0 ;
}
break;
case V_17 : {
int V_18 ;
const struct V_19 * V_20 ;
for ( V_18 = 0 ; V_18 < V_3 -> V_13 . V_21 . V_22 ; V_18 ++ ) {
V_20 = & V_3 -> V_13 . V_21 . V_23 [ V_18 ] ;
if ( * V_1 == V_20 -> V_18 ) {
if ( V_20 -> V_24 [ 0 ] != '\0' )
F_2 ( L_4 , V_20 -> V_24 ) ;
return 0 ;
}
}
}
break;
default:
F_3 () ;
}
F_2 ( L_5 ,
V_3 -> V_10 , * V_1 , V_3 -> V_25 ) ;
* V_1 = V_3 -> V_7 ;
return - 1 ;
}
void F_4 ( struct V_4 * V_5 )
{
struct V_2 V_3 ;
int V_26 = V_5 -> V_27 ;
if ( V_26 >= V_28 ) {
F_5 ( L_6
L_7 , V_26 ) ;
}
{
struct V_29 * V_30 = V_5 -> V_30 ;
int V_18 ;
T_1 V_31 = V_5 -> V_32 . V_31 ;
V_3 = (struct V_2 ) {
. type = V_12 ,
. V_10 = L_8 ,
. V_25 = L_9
F_6 ( V_33 ) ,
. V_7 = V_33 ,
. V_13 = { . V_14 = {
. V_15 = V_34 ,
. V_16 = V_31 < V_35 ? V_36 : V_37
} }
} ;
if ( V_38 > V_26 ) {
V_30 -> V_39 = V_40 [ V_26 ] ;
F_1 ( & V_30 -> V_39 , & V_3 , V_5 ) ;
V_30 -> V_39 = F_7 ( V_30 -> V_39 ,
V_41 ) ;
} else {
V_30 -> V_39 = V_3 . V_7 ;
}
for ( V_18 = 0 ; V_18 < V_5 -> V_42 ; V_18 ++ )
V_30 [ V_18 ] . V_39 = V_30 -> V_39 ;
}
{
struct V_43 * V_44 = V_5 -> V_44 ;
int V_18 ;
T_1 V_31 = V_5 -> V_32 . V_31 ;
V_3 = (struct V_2 ) {
. type = V_12 ,
. V_10 = L_10 ,
. V_25 = L_9
F_6 ( V_45 ) ,
. V_7 = V_45 ,
. V_13 = { . V_14 = {
. V_15 = V_46 ,
. V_16 = V_31 < V_35 ? V_47 :
V_48
} }
} ;
if ( V_49 > V_26 ) {
V_44 -> V_39 = V_50 [ V_26 ] ;
F_1 ( & V_44 -> V_39 , & V_3 , V_5 ) ;
V_44 -> V_39 = F_7 ( V_44 -> V_39 ,
V_51 ) ;
} else {
V_44 -> V_39 = V_3 . V_7 ;
}
for ( V_18 = 0 ; V_18 < V_5 -> V_52 ; V_18 ++ )
V_44 [ V_18 ] . V_39 = V_44 -> V_39 ;
}
{
V_3 = (struct V_2 ) {
. type = V_8 ,
. V_10 = L_11 ,
. V_25 = L_12 ,
. V_7 = V_9
} ;
if ( V_53 > V_26 ) {
unsigned int V_54 = V_55 [ V_26 ] ;
F_1 ( & V_54 , & V_3 , V_5 ) ;
V_5 -> V_54 = V_54 ;
} else {
V_5 -> V_54 = V_3 . V_7 ;
}
}
{
static const struct V_19 V_56 [] = {
{ V_57 , L_13 } ,
{ V_58 , L_14 } ,
{ V_59 , L_15 } ,
{ V_60 , L_16 } ,
{ V_61 , L_17 }
} ;
V_3 = (struct V_2 ) {
. type = V_17 ,
. V_10 = L_18 ,
. V_25 = L_19 ,
. V_7 = V_61 ,
. V_13 = { . V_21 = { . V_22 = F_8 ( V_56 ) ,
. V_23 = V_56 } }
} ;
if ( V_62 > V_26 ) {
unsigned int V_63 = V_64 [ V_26 ] ;
F_1 ( & V_63 , & V_3 , V_5 ) ;
V_5 -> V_32 . V_63 = V_5 -> V_32 . V_65 = V_63 ;
} else {
V_5 -> V_32 . V_63 = V_5 -> V_32 . V_65 = V_3 . V_7 ;
}
}
{
V_3 = (struct V_2 ) {
. type = V_12 ,
. V_10 = L_20 ,
. V_25 = L_9 F_6 ( V_66 ) ,
. V_7 = V_66 ,
. V_13 = { . V_14 = { . V_15 = V_67 ,
. V_16 = V_68 } }
} ;
if ( V_69 > V_26 ) {
V_5 -> V_70 = V_71 [ V_26 ] ;
F_1 ( & V_5 -> V_70 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_70 = V_3 . V_7 ;
}
}
{
V_3 = (struct V_2 ) {
. type = V_12 ,
. V_10 = L_21 ,
. V_25 = L_9 F_6 ( V_72 ) ,
. V_7 = V_72 ,
. V_13 = { . V_14 = { . V_15 = V_73 ,
. V_16 = V_74 } }
} ;
if ( V_75 > V_26 ) {
V_5 -> V_76 = V_77 [ V_26 ] ;
F_1 ( & V_5 -> V_76 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_76 = V_3 . V_7 ;
}
}
{
V_3 = (struct V_2 ) {
. type = V_12 ,
. V_10 = L_22 ,
. V_25 = L_9 F_6 ( V_78 ) ,
. V_7 = V_78 ,
. V_13 = { . V_14 = { . V_15 = V_79 ,
. V_16 = V_80 } }
} ;
if ( V_81 > V_26 ) {
V_5 -> V_82 = V_83 [ V_26 ] ;
F_1 ( & V_5 -> V_82 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_82 = V_3 . V_7 ;
}
}
{
V_3 = (struct V_2 ) {
. type = V_12 ,
. V_10 = L_23 ,
. V_25 = L_9 F_6 ( V_84 ) ,
. V_7 = V_84 ,
. V_13 = { . V_14 = { . V_15 = V_85 ,
. V_16 = V_86 } }
} ;
if ( V_87 > V_26 ) {
V_5 -> V_88 = V_89 [ V_26 ] ;
F_1 ( & V_5 -> V_88 , & V_3 ,
V_5 ) ;
} else {
V_5 -> V_88 = V_3 . V_7 ;
}
}
{
V_3 = (struct V_2 ) {
. type = V_12 ,
. V_10 = L_24 ,
. V_25 = L_9 F_6 ( V_90 ) ,
. V_7 = V_90 ,
. V_13 = { . V_14 = { . V_15 = V_91 ,
. V_16 = V_92 } }
} ;
if ( V_93 > V_26 ) {
V_5 -> V_94 = V_95 [ V_26 ] ;
switch ( V_5 -> V_94 ) {
case 0 :
F_2 ( L_25 , V_3 . V_10 ) ;
break;
case 1 :
F_2 ( L_26 ,
V_3 . V_10 ) ;
V_5 -> V_96 = V_5 -> V_94 ;
V_5 -> V_94 = 20000 ;
break;
case 3 :
F_2 ( L_27
L_28 , V_3 . V_10 ) ;
V_5 -> V_96 = V_5 -> V_94 ;
V_5 -> V_94 = 20000 ;
break;
case 4 :
F_2 ( L_29
L_30 , V_3 . V_10 ) ;
V_5 -> V_96 = V_5 -> V_94 ;
break;
default:
F_1 ( & V_5 -> V_94 , & V_3 ,
V_5 ) ;
V_5 -> V_96 = V_5 -> V_94 & ~ 3 ;
break;
}
} else {
V_5 -> V_96 = V_3 . V_7 ;
V_5 -> V_94 = 20000 ;
}
}
{
V_3 = (struct V_2 ) {
. type = V_8 ,
. V_10 = L_31 ,
. V_25 = L_32 ,
. V_7 = V_11
} ;
if ( V_97 > V_26 ) {
unsigned int V_98 = V_99 [ V_26 ] ;
F_1 ( & V_98 , & V_3 , V_5 ) ;
V_5 -> V_100 = V_98 ;
} else {
V_5 -> V_100 = V_3 . V_7 ;
}
}
switch ( V_5 -> V_32 . V_101 ) {
case V_102 :
case V_103 :
F_9 ( V_5 ) ;
break;
case V_104 :
F_10 ( V_5 ) ;
break;
default:
F_3 () ;
}
}
static void F_9 ( struct V_4 * V_5 )
{
int V_26 = V_5 -> V_27 ;
if ( V_105 > V_26 ) {
F_2 ( L_33
L_34 ) ;
}
if ( V_106 > V_26 ) {
F_2 ( L_35
L_34 ) ;
}
if ( ( V_107 > V_26 ) && ( V_108 [ V_26 ] != 0x20 ) ) {
F_2 ( L_36
L_37 ) ;
}
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_2 V_3 ;
unsigned int V_109 , V_110 , V_111 ;
int V_26 = V_5 -> V_27 ;
{
static const struct V_19 V_112 [] = {
{ 0 , L_38 } ,
{ V_113 , L_38 } ,
{ V_114 , L_38 } ,
{ V_115 , L_38 } } ;
V_3 = (struct V_2 ) {
. type = V_17 ,
. V_10 = L_39 ,
. V_25 = L_40 ,
. V_7 = 0 ,
. V_13 = { . V_21 = { . V_22 = F_8 ( V_112 ) ,
. V_23 = V_112 } }
} ;
if ( V_105 > V_26 ) {
V_109 = V_116 [ V_26 ] ;
F_1 ( & V_109 , & V_3 , V_5 ) ;
} else {
V_109 = V_3 . V_7 ;
}
}
{
static const struct V_19 V_117 [] = {
{ 0 , L_38 } ,
{ V_118 , L_38 } ,
{ V_119 , L_38 } } ;
V_3 = (struct V_2 ) {
. type = V_17 ,
. V_10 = L_41 ,
. V_25 = L_40 ,
. V_7 = 0 ,
. V_13 = { . V_21 = { . V_22 = F_8 ( V_117 ) ,
. V_23 = V_117 } }
} ;
if ( V_106 > V_26 ) {
V_110 = V_120 [ V_26 ] ;
F_1 ( & V_110 , & V_3 , V_5 ) ;
} else {
V_110 = V_3 . V_7 ;
}
}
if ( ( V_107 > V_26 ) && ( V_109 != 0 || V_110 != 0 ) ) {
F_2 ( L_42
L_43 ) ;
V_5 -> V_32 . V_121 = V_122 ;
} else {
static const struct V_19 V_123 [] =
#define F_11 "AutoNeg advertising "
{ { 0x01 , F_11 L_44 } ,
{ 0x02 , F_11 L_45 } ,
{ 0x03 , F_11 L_46 } ,
{ 0x04 , F_11 L_47 } ,
{ 0x05 , F_11 L_48 } ,
{ 0x06 , F_11 L_49 } ,
{ 0x07 , F_11 L_50 } ,
{ 0x08 , F_11 L_51 } ,
{ 0x09 , F_11 L_52 } ,
{ 0x0a , F_11 L_53 } ,
{ 0x0b , F_11 L_54 } ,
{ 0x0c , F_11 L_55 } ,
{ 0x0d , F_11 L_56 } ,
{ 0x0e , F_11 L_57 } ,
{ 0x0f , F_11 L_58 } ,
{ 0x20 , F_11 L_59 } ,
{ 0x21 , F_11 L_60 } ,
{ 0x22 , F_11 L_61 } ,
{ 0x23 , F_11 L_62 } ,
{ 0x24 , F_11 L_63 } ,
{ 0x25 , F_11 L_64 } ,
{ 0x26 , F_11 L_65 } ,
{ 0x27 , F_11 L_66 } ,
{ 0x28 , F_11 L_67 } ,
{ 0x29 , F_11 L_68 } ,
{ 0x2a , F_11 L_69 } ,
{ 0x2b , F_11 L_70 } ,
{ 0x2c , F_11 L_71 } ,
{ 0x2d , F_11 L_72 } ,
{ 0x2e , F_11 L_73 } ,
{ 0x2f , F_11 L_74 } } ;
V_3 = (struct V_2 ) {
. type = V_17 ,
. V_10 = L_75 ,
. V_25 = L_40 ,
. V_7 = V_122 ,
. V_13 = { . V_21 = { . V_22 = F_8 ( V_123 ) ,
. V_23 = V_123 } }
} ;
if ( V_107 > V_26 ) {
V_111 = V_108 [ V_26 ] ;
F_1 ( & V_111 , & V_3 , V_5 ) ;
} else {
V_111 = V_3 . V_7 ;
}
V_5 -> V_32 . V_121 = V_111 ;
}
switch ( V_109 + V_110 ) {
case 0 :
V_5 -> V_32 . V_124 = V_5 -> V_125 = 1 ;
if ( ( V_105 > V_26 ) && ( V_109 != 0 || V_110 != 0 ) )
F_2 ( L_76
L_77 ) ;
break;
case V_118 :
F_2 ( L_78 ) ;
F_2 ( L_79 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 1 ;
V_5 -> V_32 . V_121 = V_126 |
V_127 ;
break;
case V_119 :
F_2 ( L_80 ) ;
F_2 ( L_81 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 1 ;
V_5 -> V_32 . V_121 = V_128 |
V_129 |
V_130 ;
break;
case V_113 :
F_2 ( L_82 ) ;
F_2 ( L_83 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 1 ;
V_5 -> V_32 . V_121 = V_126 |
V_128 ;
break;
case V_113 + V_118 :
F_2 ( L_84 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 0 ;
V_5 -> V_32 . V_131 = V_132 ;
V_5 -> V_32 . V_121 = 0 ;
break;
case V_113 + V_119 :
F_2 ( L_85 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 0 ;
V_5 -> V_32 . V_131 = V_133 ;
V_5 -> V_32 . V_121 = 0 ;
break;
case V_114 :
F_2 ( L_86 ) ;
F_2 ( L_87 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 1 ;
V_5 -> V_32 . V_121 = V_127 |
V_129 ;
break;
case V_114 + V_118 :
F_2 ( L_88 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 0 ;
V_5 -> V_32 . V_131 = V_134 ;
V_5 -> V_32 . V_121 = 0 ;
break;
case V_114 + V_119 :
F_2 ( L_89 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 0 ;
V_5 -> V_32 . V_131 = V_135 ;
V_5 -> V_32 . V_121 = 0 ;
break;
case V_115 :
F_2 ( L_90 ) ;
goto V_136;
case V_115 + V_118 :
F_2 ( L_91 ) ;
case V_115 + V_119 :
V_136:
F_2 ( L_92
L_93 ) ;
V_5 -> V_32 . V_124 = V_5 -> V_125 = 1 ;
V_5 -> V_32 . V_121 = V_130 ;
break;
default:
F_3 () ;
}
if ( F_12 ( & ( V_5 -> V_32 ) ) < 0 ) {
F_2 ( L_94
L_95 ) ;
}
}
