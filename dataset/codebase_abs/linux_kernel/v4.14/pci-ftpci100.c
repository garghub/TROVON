static int F_1 ( T_1 V_1 ,
T_1 V_2 , T_2 * V_3 )
{
T_2 V_4 ;
switch ( V_2 ) {
case V_5 :
V_4 = V_6 ;
break;
case V_7 :
V_4 = V_8 ;
break;
case V_9 :
V_4 = V_10 ;
break;
case V_11 :
V_4 = V_12 ;
break;
case V_13 :
V_4 = V_14 ;
break;
case V_15 :
V_4 = V_16 ;
break;
case V_17 :
V_4 = V_18 ;
break;
case V_19 :
V_4 = V_20 ;
break;
case V_21 :
V_4 = V_22 ;
break;
case V_23 :
V_4 = V_24 ;
break;
case V_25 :
V_4 = V_26 ;
break;
case V_27 :
V_4 = V_28 ;
break;
default:
return - V_29 ;
}
V_4 <<= V_30 ;
if ( V_1 & ~ ( V_31 ) )
F_2 ( L_1 ) ;
V_4 |= ( V_1 & V_31 ) ;
F_3 ( L_2 ,
& V_1 , & V_2 , V_4 ) ;
* V_3 = V_4 ;
return 0 ;
}
static int F_4 ( struct V_32 * V_33 , int V_34 ,
unsigned int V_35 , int V_36 , int V_37 ,
T_2 * V_38 )
{
F_5 ( F_6 ( V_34 ) |
F_7 ( F_8 ( V_35 ) ) |
F_9 ( F_10 ( V_35 ) ) |
F_11 ( V_36 ) |
V_39 ,
V_33 -> V_40 + V_41 ) ;
* V_38 = F_12 ( V_33 -> V_40 + V_42 ) ;
if ( V_37 == 1 )
* V_38 = ( * V_38 >> ( 8 * ( V_36 & 3 ) ) ) & 0xFF ;
else if ( V_37 == 2 )
* V_38 = ( * V_38 >> ( 8 * ( V_36 & 3 ) ) ) & 0xFFFF ;
return V_43 ;
}
static int F_13 ( struct V_44 * V_45 , unsigned int V_35 ,
int V_36 , int V_37 , T_2 * V_38 )
{
struct V_32 * V_33 = V_45 -> V_46 ;
F_14 ( & V_45 -> V_47 ,
L_3 ,
F_8 ( V_35 ) , F_10 ( V_35 ) , V_36 , V_37 , * V_38 ) ;
return F_4 ( V_33 , V_45 -> V_48 , V_35 , V_36 , V_37 , V_38 ) ;
}
static int F_15 ( struct V_32 * V_33 , int V_34 ,
unsigned int V_35 , int V_36 , int V_37 ,
T_2 V_38 )
{
int V_49 = V_43 ;
F_5 ( F_6 ( V_34 ) |
F_7 ( F_8 ( V_35 ) ) |
F_9 ( F_10 ( V_35 ) ) |
F_11 ( V_36 ) |
V_39 ,
V_33 -> V_40 + V_41 ) ;
switch ( V_37 ) {
case 4 :
F_5 ( V_38 , V_33 -> V_40 + V_42 ) ;
break;
case 2 :
F_16 ( V_38 , V_33 -> V_40 + V_42 + ( V_36 & 3 ) ) ;
break;
case 1 :
F_17 ( V_38 , V_33 -> V_40 + V_42 + ( V_36 & 3 ) ) ;
break;
default:
V_49 = V_50 ;
}
return V_49 ;
}
static int F_18 ( struct V_44 * V_45 , unsigned int V_35 ,
int V_36 , int V_37 , T_2 V_38 )
{
struct V_32 * V_33 = V_45 -> V_46 ;
F_14 ( & V_45 -> V_47 ,
L_4 ,
F_8 ( V_35 ) , F_10 ( V_35 ) , V_36 , V_37 , V_38 ) ;
return F_15 ( V_33 , V_45 -> V_48 , V_35 , V_36 , V_37 ,
V_38 ) ;
}
static void F_19 ( struct V_51 * V_52 )
{
struct V_32 * V_33 = F_20 ( V_52 ) ;
unsigned int V_53 ;
F_4 ( V_33 , 0 , 0 , V_54 , 4 , & V_53 ) ;
V_53 &= ~ ( 0xF << V_55 ) ;
V_53 |= F_21 ( F_22 ( V_52 ) + V_55 ) ;
F_15 ( V_33 , 0 , 0 , V_54 , 4 , V_53 ) ;
}
static void F_23 ( struct V_51 * V_52 )
{
struct V_32 * V_33 = F_20 ( V_52 ) ;
unsigned int V_53 ;
F_4 ( V_33 , 0 , 0 , V_54 , 4 , & V_53 ) ;
V_53 &= ~ ( ( 0xF << V_55 )
| F_21 ( F_22 ( V_52 ) + V_56 ) ) ;
F_15 ( V_33 , 0 , 0 , V_54 , 4 , V_53 ) ;
}
static void F_24 ( struct V_51 * V_52 )
{
struct V_32 * V_33 = F_20 ( V_52 ) ;
unsigned int V_53 ;
F_4 ( V_33 , 0 , 0 , V_54 , 4 , & V_53 ) ;
V_53 &= ~ ( 0xF << V_55 ) ;
V_53 |= F_21 ( F_22 ( V_52 ) + V_56 ) ;
F_15 ( V_33 , 0 , 0 , V_54 , 4 , V_53 ) ;
}
static void F_25 ( struct V_57 * V_58 )
{
struct V_32 * V_33 = F_26 ( V_58 ) ;
struct V_59 * V_60 = F_27 ( V_58 ) ;
unsigned int V_61 , V_53 , V_62 ;
F_4 ( V_33 , 0 , 0 , V_54 , 4 , & V_53 ) ;
V_61 = V_53 >> V_55 ;
F_28 ( V_60 , V_58 ) ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
if ( ( V_61 & F_21 ( V_62 ) ) == 0 )
continue;
F_29 ( F_30 ( V_33 -> V_63 , V_62 ) ) ;
}
F_31 ( V_60 , V_58 ) ;
}
static int F_32 ( struct V_64 * V_65 , unsigned int V_66 ,
T_3 V_67 )
{
F_33 ( V_66 , & V_68 , V_69 ) ;
F_34 ( V_66 , V_65 -> V_70 ) ;
return 0 ;
}
static int F_35 ( struct V_32 * V_33 )
{
struct V_71 * V_72 = F_36 ( V_33 -> V_47 -> V_73 , NULL ) ;
int V_66 ;
int V_62 ;
if ( ! V_72 ) {
F_37 ( V_33 -> V_47 , L_5 ) ;
return - V_29 ;
}
V_66 = F_38 ( V_72 , 0 ) ;
if ( V_66 <= 0 ) {
F_37 ( V_33 -> V_47 , L_6 ) ;
return V_66 ? : - V_29 ;
}
V_33 -> V_63 = F_39 ( V_72 , V_74 ,
& V_75 , V_33 ) ;
if ( ! V_33 -> V_63 ) {
F_37 ( V_33 -> V_47 , L_7 ) ;
return - V_29 ;
}
F_40 ( V_66 , F_25 , V_33 ) ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ )
F_41 ( V_33 -> V_63 , V_62 ) ;
return 0 ;
}
static int F_42 ( struct V_76 * V_77 ,
struct V_71 * V_78 )
{
const int V_79 = 3 , V_80 = 2 ;
int V_81 ;
V_77 -> V_78 = V_78 ;
V_77 -> V_82 = F_43 ( V_78 ) ;
V_77 -> V_83 = V_77 -> V_82 + V_79 + V_80 ;
V_77 -> V_84 = F_44 ( V_78 , L_8 , & V_81 ) ;
if ( ! V_77 -> V_84 )
return - V_85 ;
V_77 -> V_86 = V_77 -> V_84 + V_81 / sizeof( V_87 ) ;
return 0 ;
}
static int F_45 ( struct V_32 * V_33 ,
struct V_71 * V_83 )
{
struct V_88 V_84 ;
struct V_76 V_77 ;
struct V_89 * V_47 = V_33 -> V_47 ;
T_2 V_90 [ 3 ] = {
V_91 ,
V_92 ,
V_93 ,
} ;
int V_62 = 0 ;
T_2 V_3 ;
if ( F_42 ( & V_77 , V_83 ) ) {
F_37 ( V_47 , L_9 ) ;
return - V_29 ;
}
F_46 (&parser, &range) {
T_4 V_86 = V_84 . V_94 + V_84 . V_37 - 1 ;
int V_49 ;
V_49 = F_1 ( V_84 . V_94 , V_84 . V_37 , & V_3 ) ;
if ( V_49 ) {
F_37 ( V_47 ,
L_10 , V_62 ) ;
return - V_29 ;
}
F_47 ( V_47 , L_11 ,
V_62 + 1 , V_84 . V_94 , V_86 , V_3 ) ;
if ( V_62 <= 2 ) {
F_15 ( V_33 , 0 , 0 , V_90 [ V_62 ] ,
4 , V_3 ) ;
} else {
F_37 ( V_47 , L_12 , V_62 ) ;
break;
}
V_62 ++ ;
}
return 0 ;
}
static int F_48 ( struct V_95 * V_96 )
{
struct V_89 * V_47 = & V_96 -> V_47 ;
const struct V_97 * V_98 =
F_49 ( V_47 ) ;
struct V_99 * V_100 ;
T_1 V_101 ;
struct V_102 * V_103 ;
struct V_32 * V_33 ;
struct V_99 * V_104 ;
struct V_99 * V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_108 ;
unsigned char V_109 = V_110 ;
unsigned char V_111 = V_110 ;
int V_49 ;
T_2 V_3 ;
F_50 ( V_112 ) ;
V_107 = F_51 ( V_47 , sizeof( * V_33 ) ) ;
if ( ! V_107 )
return - V_113 ;
V_107 -> V_47 . V_114 = V_47 ;
V_107 -> V_115 = & V_116 ;
V_107 -> V_117 = 0 ;
V_107 -> V_118 = NULL ;
V_107 -> V_119 = V_120 ;
V_107 -> V_121 = V_122 ;
V_33 = F_52 ( V_107 ) ;
V_107 -> V_46 = V_33 ;
V_33 -> V_47 = V_47 ;
V_108 = F_53 ( V_47 , L_13 ) ;
if ( F_54 ( V_108 ) )
return F_55 ( V_108 ) ;
V_49 = F_56 ( V_108 ) ;
if ( V_49 ) {
F_37 ( V_47 , L_14 ) ;
return V_49 ;
}
V_33 -> V_123 = F_53 ( V_47 , L_15 ) ;
if ( F_54 ( V_33 -> V_123 ) )
return F_55 ( V_108 ) ;
V_49 = F_56 ( V_33 -> V_123 ) ;
if ( V_49 ) {
F_37 ( V_47 , L_16 ) ;
return V_49 ;
}
V_100 = F_57 ( V_96 , V_124 , 0 ) ;
V_33 -> V_40 = F_58 ( V_47 , V_100 ) ;
if ( F_54 ( V_33 -> V_40 ) )
return F_55 ( V_33 -> V_40 ) ;
V_49 = F_59 ( V_47 -> V_73 , 0 , 0xff ,
& V_112 , & V_101 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_60 ( V_47 , & V_112 ) ;
if ( V_49 )
return V_49 ;
F_61 (win, &res) {
switch ( F_62 ( V_103 -> V_112 ) ) {
case V_125 :
V_105 = V_103 -> V_112 ;
V_105 -> V_126 = L_17 ;
if ( ! F_1 ( V_105 -> V_127 - V_103 -> V_128 ,
F_63 ( V_105 ) , & V_3 ) ) {
F_5 ( V_3 , V_33 -> V_40 + V_129 ) ;
} else {
F_37 ( V_47 , L_18 ) ;
return - V_29 ;
}
V_49 = F_64 ( V_105 , V_101 ) ;
if ( V_49 ) {
F_65 ( V_47 , L_19 ,
V_49 , V_105 ) ;
continue;
}
break;
case V_124 :
V_104 = V_103 -> V_112 ;
V_104 -> V_126 = L_20 ;
break;
case V_130 :
break;
default:
break;
}
}
V_3 = F_12 ( V_33 -> V_40 + V_131 ) ;
V_3 |= V_132 ;
V_3 |= V_133 ;
V_3 |= V_134 ;
F_5 ( V_3 , V_33 -> V_40 + V_131 ) ;
F_15 ( V_33 , 0 , 0 , V_54 + 2 , 2 , 0xF000 ) ;
if ( V_98 -> V_135 ) {
V_49 = F_35 ( V_33 ) ;
if ( V_49 ) {
F_37 ( V_47 , L_21 ) ;
return V_49 ;
}
}
if ( ! F_54 ( V_33 -> V_123 ) ) {
unsigned long V_136 ;
T_2 V_3 ;
F_4 ( V_33 , 0 , 0 ,
V_137 , 4 , & V_3 ) ;
V_136 = F_66 ( V_33 -> V_123 ) ;
if ( ( V_136 == 33000000 ) && ( V_3 & V_138 ) ) {
F_47 ( V_47 , L_22 ) ;
V_109 = V_139 ;
V_49 = F_67 ( V_33 -> V_123 , 66000000 ) ;
if ( V_49 )
F_37 ( V_47 , L_23 ) ;
} else {
F_47 ( V_47 , L_24 ) ;
V_109 = V_110 ;
}
V_136 = F_66 ( V_33 -> V_123 ) ;
if ( V_136 == 33000000 )
V_111 = V_110 ;
if ( V_136 == 66000000 )
V_111 = V_139 ;
}
V_49 = F_45 ( V_33 , V_47 -> V_73 ) ;
if ( V_49 )
return V_49 ;
F_68 ( & V_112 , & V_107 -> V_140 ) ;
V_49 = F_69 ( V_107 ) ;
if ( V_49 ) {
F_37 ( V_47 , L_25 , V_49 ) ;
return V_49 ;
}
V_33 -> V_45 = V_107 -> V_45 ;
V_33 -> V_45 -> V_109 = V_109 ;
V_33 -> V_45 -> V_111 = V_111 ;
F_70 ( V_33 -> V_45 ) ;
F_71 ( V_33 -> V_45 ) ;
F_72 ( & V_112 ) ;
return 0 ;
}
