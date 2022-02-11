int F_1 ( struct V_1 * V_2 , T_1 * V_3 , unsigned int V_4 )
{
int V_5 ;
struct V_6 V_7 = {} ;
V_7 . V_8 = V_9 ;
if ( ! F_2 ( V_2 -> V_10 ) )
V_7 . V_11 = V_2 -> V_12 << 16 ;
V_7 . V_13 = V_14 | V_15 | V_16 ;
V_5 = F_3 ( V_2 -> V_10 , & V_7 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_3 )
* V_3 = V_7 . V_17 [ 0 ] ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 * V_3 )
{
return F_1 ( V_2 , V_3 , V_18 ) ;
}
static int F_5 ( struct V_19 * V_10 , struct V_1 * V_2 )
{
struct V_6 V_7 = {} ;
V_7 . V_8 = V_20 ;
if ( V_2 ) {
V_7 . V_11 = V_2 -> V_12 << 16 ;
V_7 . V_13 = V_15 | V_16 ;
} else {
V_7 . V_11 = 0 ;
V_7 . V_13 = V_21 | V_16 ;
}
return F_3 ( V_10 , & V_7 , V_18 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_10 , V_2 ) ;
}
int F_7 ( struct V_19 * V_10 )
{
return F_5 ( V_10 , NULL ) ;
}
int F_8 ( struct V_19 * V_10 )
{
struct V_6 V_7 = {} ;
V_7 . V_8 = V_22 ;
V_7 . V_11 = ( V_10 -> V_23 << 16 ) | 0xffff ;
V_7 . V_13 = V_21 | V_16 ;
return F_3 ( V_10 , & V_7 , V_18 ) ;
}
int F_9 ( struct V_19 * V_10 )
{
int V_5 ;
struct V_6 V_7 = {} ;
if ( ! F_2 ( V_10 ) ) {
F_10 ( V_10 , V_24 ) ;
F_11 ( 1 ) ;
}
V_7 . V_8 = V_25 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_26 | V_21 | V_27 ;
V_5 = F_3 ( V_10 , & V_7 , 0 ) ;
F_11 ( 1 ) ;
if ( ! F_2 ( V_10 ) ) {
F_10 ( V_10 , V_28 ) ;
F_11 ( 1 ) ;
}
V_10 -> V_29 = 0 ;
return V_5 ;
}
int F_12 ( struct V_19 * V_10 , T_1 V_30 , T_1 * V_31 )
{
struct V_6 V_7 = {} ;
int V_32 , V_5 = 0 ;
V_7 . V_8 = V_33 ;
V_7 . V_11 = F_2 ( V_10 ) ? 0 : V_30 ;
V_7 . V_13 = V_26 | V_34 | V_35 ;
for ( V_32 = 100 ; V_32 ; V_32 -- ) {
V_5 = F_3 ( V_10 , & V_7 , 0 ) ;
if ( V_5 )
break;
if ( V_30 == 0 )
break;
if ( F_2 ( V_10 ) ) {
if ( ! ( V_7 . V_17 [ 0 ] & V_36 ) )
break;
} else {
if ( V_7 . V_17 [ 0 ] & V_37 )
break;
}
V_5 = - V_38 ;
F_11 ( 10 ) ;
}
if ( V_31 && ! F_2 ( V_10 ) )
* V_31 = V_7 . V_17 [ 0 ] ;
return V_5 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_6 V_7 = {} ;
V_7 . V_8 = V_39 ;
V_7 . V_11 = V_2 -> V_12 << 16 ;
V_7 . V_13 = V_15 | V_16 ;
return F_3 ( V_2 -> V_10 , & V_7 , V_18 ) ;
}
static int
F_14 ( struct V_19 * V_10 , T_1 V_11 , T_1 * V_40 , int V_8 )
{
int V_5 ;
struct V_6 V_7 = {} ;
V_7 . V_8 = V_8 ;
V_7 . V_11 = V_11 ;
V_7 . V_13 = V_41 | V_16 ;
V_5 = F_3 ( V_10 , & V_7 , V_18 ) ;
if ( V_5 )
return V_5 ;
memcpy ( V_40 , V_7 . V_17 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_19 * V_10 ,
T_1 V_8 , void * V_42 , unsigned V_43 )
{
struct V_44 V_45 = {} ;
struct V_6 V_7 = {} ;
struct V_46 V_47 = {} ;
struct V_48 V_49 ;
V_45 . V_7 = & V_7 ;
V_45 . V_47 = & V_47 ;
V_7 . V_8 = V_8 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_26 | V_15 | V_50 ;
V_47 . V_51 = V_43 ;
V_47 . V_52 = 1 ;
V_47 . V_13 = V_53 ;
V_47 . V_49 = & V_49 ;
V_47 . V_54 = 1 ;
F_16 ( & V_49 , V_42 , V_43 ) ;
if ( V_8 == V_55 || V_8 == V_56 ) {
V_47 . V_57 = 0 ;
V_47 . V_58 = 64 ;
} else
F_17 ( & V_47 , V_2 ) ;
F_18 ( V_10 , & V_45 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_47 . error )
return V_47 . error ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_59 )
{
int V_60 , V_32 ;
T_2 * V_61 ;
V_61 = F_20 ( 16 , V_62 ) ;
if ( ! V_61 )
return - V_63 ;
V_60 = F_15 ( V_2 , V_2 -> V_10 , V_55 , V_61 , 16 ) ;
if ( V_60 )
goto V_5;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
V_59 [ V_32 ] = F_21 ( V_61 [ V_32 ] ) ;
V_5:
F_22 ( V_61 ) ;
return V_60 ;
}
int F_23 ( struct V_1 * V_2 , T_1 * V_59 )
{
if ( F_2 ( V_2 -> V_10 ) )
return F_19 ( V_2 , V_59 ) ;
return F_14 ( V_2 -> V_10 , V_2 -> V_12 << 16 , V_59 ,
V_55 ) ;
}
static int F_24 ( struct V_19 * V_10 , T_1 * V_64 )
{
int V_60 , V_32 ;
T_2 * V_65 ;
V_65 = F_20 ( 16 , V_62 ) ;
if ( ! V_65 )
return - V_63 ;
V_60 = F_15 ( NULL , V_10 , V_56 , V_65 , 16 ) ;
if ( V_60 )
goto V_5;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
V_64 [ V_32 ] = F_21 ( V_65 [ V_32 ] ) ;
V_5:
F_22 ( V_65 ) ;
return V_60 ;
}
int F_25 ( struct V_19 * V_10 , T_1 * V_64 )
{
if ( F_2 ( V_10 ) )
return F_24 ( V_10 , V_64 ) ;
return F_14 ( V_10 , 0 , V_64 , V_66 ) ;
}
int F_26 ( struct V_1 * V_2 , T_3 * * V_67 )
{
int V_5 ;
T_3 * V_68 ;
if ( ! V_2 || ! V_67 )
return - V_69 ;
if ( ! F_27 ( V_2 ) )
return - V_70 ;
V_68 = F_20 ( 512 , V_62 ) ;
if ( ! V_68 )
return - V_63 ;
V_5 = F_15 ( V_2 , V_2 -> V_10 , V_71 , V_68 ,
512 ) ;
if ( V_5 )
F_22 ( V_68 ) ;
else
* V_67 = V_68 ;
return V_5 ;
}
int F_28 ( struct V_19 * V_10 , int V_72 , T_1 * V_73 )
{
struct V_6 V_7 = {} ;
int V_5 ;
V_7 . V_8 = V_74 ;
V_7 . V_11 = V_72 ? ( 1 << 30 ) : 0 ;
V_7 . V_13 = V_75 ;
V_5 = F_3 ( V_10 , & V_7 , 0 ) ;
* V_73 = V_7 . V_17 [ 1 ] ;
return V_5 ;
}
int F_29 ( struct V_19 * V_10 , int V_76 )
{
struct V_6 V_7 = {} ;
int V_5 ;
V_7 . V_8 = V_77 ;
V_7 . V_13 = V_26 ;
V_7 . V_11 = V_76 ;
V_5 = F_3 ( V_10 , & V_7 , 0 ) ;
if ( ! V_5 )
V_10 -> V_29 = V_76 ;
return V_5 ;
}
static int F_30 ( struct V_19 * V_10 , T_1 V_3 )
{
if ( F_2 ( V_10 ) ) {
if ( V_3 & V_78 )
return - V_79 ;
} else {
if ( V_3 & 0xFDFFA000 )
F_31 ( L_1 ,
F_32 ( V_10 ) , V_3 ) ;
if ( V_3 & V_80 )
return - V_79 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , bool V_81 )
{
T_1 V_3 ;
int V_5 ;
V_5 = F_4 ( V_2 , & V_3 ) ;
if ( ! V_81 && V_5 == - V_82 )
return 0 ;
if ( V_5 )
return V_5 ;
return F_30 ( V_2 -> V_10 , V_3 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , true ) ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_83 ,
bool V_84 , bool V_85 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
int V_5 ;
unsigned long V_86 ;
T_1 V_3 = 0 ;
bool V_87 = false ;
bool V_88 = false ;
if ( ! V_83 )
V_83 = V_89 ;
if ( ! V_84 && ! V_10 -> V_90 -> V_91 ) {
F_11 ( V_83 ) ;
return 0 ;
}
V_86 = V_92 + F_36 ( V_83 ) + 1 ;
do {
V_87 = F_37 ( V_92 , V_86 ) ;
if ( V_10 -> V_90 -> V_91 ) {
V_88 = V_10 -> V_90 -> V_91 ( V_10 ) ;
} else {
V_5 = F_4 ( V_2 , & V_3 ) ;
if ( V_85 && V_5 == - V_82 ) {
V_88 = true ;
} else if ( V_5 ) {
return V_5 ;
} else {
V_5 = F_30 ( V_10 , V_3 ) ;
if ( V_5 )
return V_5 ;
V_88 = F_38 ( V_3 ) == V_93 ;
}
}
if ( V_87 && V_88 ) {
F_39 ( L_2 ,
F_32 ( V_10 ) , V_94 ) ;
return - V_38 ;
}
} while ( V_88 );
return 0 ;
}
int F_40 ( struct V_1 * V_2 , T_3 V_95 , T_3 V_96 , T_3 V_97 ,
unsigned int V_83 , unsigned char V_98 ,
bool V_99 , bool V_84 , bool V_85 )
{
struct V_19 * V_10 = V_2 -> V_10 ;
int V_5 ;
struct V_6 V_7 = {} ;
bool V_100 = V_99 ;
unsigned char V_101 = V_10 -> V_102 . V_98 ;
F_41 ( V_10 ) ;
if ( V_83 && V_10 -> V_103 &&
( V_83 > V_10 -> V_103 ) )
V_100 = false ;
V_7 . V_8 = V_104 ;
V_7 . V_11 = ( V_105 << 24 ) |
( V_96 << 16 ) |
( V_97 << 8 ) |
V_95 ;
V_7 . V_13 = V_16 ;
if ( V_100 ) {
V_7 . V_13 |= V_106 | V_107 ;
V_7 . V_108 = V_83 ;
} else {
V_7 . V_13 |= V_26 | V_15 ;
}
if ( V_96 == V_109 )
V_7 . V_110 = true ;
V_5 = F_3 ( V_10 , & V_7 , V_18 ) ;
if ( V_5 )
goto V_111;
if ( ! V_99 )
goto V_111;
if ( ( ( V_10 -> V_112 & V_113 ) && V_100 ) ||
F_2 ( V_10 ) )
goto V_114;
V_5 = F_35 ( V_2 , V_83 , V_84 , V_85 ) ;
if ( V_5 )
goto V_111;
V_114:
if ( V_98 )
F_42 ( V_10 , V_98 ) ;
if ( V_84 ) {
V_5 = F_34 ( V_2 ) ;
if ( V_5 && V_98 )
F_42 ( V_10 , V_101 ) ;
}
V_111:
F_43 ( V_10 ) ;
return V_5 ;
}
int F_44 ( struct V_1 * V_2 , T_3 V_95 , T_3 V_96 , T_3 V_97 ,
unsigned int V_83 )
{
return F_40 ( V_2 , V_95 , V_96 , V_97 , V_83 , 0 ,
true , true , false ) ;
}
int F_45 ( struct V_19 * V_10 , T_1 V_8 , int * V_115 )
{
struct V_44 V_45 = {} ;
struct V_6 V_7 = {} ;
struct V_46 V_47 = {} ;
struct V_48 V_49 ;
struct V_116 * V_102 = & V_10 -> V_102 ;
const T_3 * V_117 ;
int V_118 , V_5 = 0 ;
T_3 * V_119 ;
if ( V_102 -> V_120 == V_121 ) {
V_117 = V_122 ;
V_118 = sizeof( V_122 ) ;
} else if ( V_102 -> V_120 == V_123 ) {
V_117 = V_124 ;
V_118 = sizeof( V_124 ) ;
} else
return - V_69 ;
V_119 = F_20 ( V_118 , V_62 ) ;
if ( ! V_119 )
return - V_63 ;
V_45 . V_7 = & V_7 ;
V_45 . V_47 = & V_47 ;
V_7 . V_8 = V_8 ;
V_7 . V_13 = V_15 | V_50 ;
V_47 . V_51 = V_118 ;
V_47 . V_52 = 1 ;
V_47 . V_13 = V_53 ;
V_47 . V_57 = 150 * V_125 ;
V_47 . V_49 = & V_49 ;
V_47 . V_54 = 1 ;
F_16 ( & V_49 , V_119 , V_118 ) ;
F_18 ( V_10 , & V_45 ) ;
if ( V_115 )
* V_115 = V_7 . error ;
if ( V_7 . error ) {
V_5 = V_7 . error ;
goto V_111;
}
if ( V_47 . error ) {
V_5 = V_47 . error ;
goto V_111;
}
if ( memcmp ( V_119 , V_117 , V_118 ) )
V_5 = - V_126 ;
V_111:
F_22 ( V_119 ) ;
return V_5 ;
}
int F_46 ( struct V_19 * V_10 , T_1 V_8 )
{
struct V_6 V_7 = {} ;
if ( V_8 != V_127 )
return 0 ;
V_7 . V_8 = V_128 ;
V_7 . V_13 = V_26 | V_15 | V_16 ;
V_7 . V_108 = 150 ;
return F_3 ( V_10 , & V_7 , 0 ) ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_19 * V_10 , T_3 V_8 ,
T_3 V_43 )
{
struct V_44 V_45 = {} ;
struct V_6 V_7 = {} ;
struct V_46 V_47 = {} ;
struct V_48 V_49 ;
T_3 * V_119 ;
T_3 * V_129 ;
int V_32 , V_5 ;
static T_3 V_130 [ 8 ] = { 0x55 , 0xaa , 0 , 0 , 0 , 0 , 0 , 0 } ;
static T_3 V_131 [ 4 ] = { 0x5a , 0 , 0 , 0 } ;
V_119 = F_48 ( V_43 , V_62 ) ;
if ( ! V_119 )
return - V_63 ;
if ( V_43 == 8 )
V_129 = V_130 ;
else if ( V_43 == 4 )
V_129 = V_131 ;
else {
F_39 ( L_3 ,
F_32 ( V_10 ) , V_43 ) ;
F_22 ( V_119 ) ;
return - V_69 ;
}
if ( V_8 == V_132 )
memcpy ( V_119 , V_129 , V_43 ) ;
V_45 . V_7 = & V_7 ;
V_45 . V_47 = & V_47 ;
V_7 . V_8 = V_8 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_26 | V_15 | V_50 ;
V_47 . V_51 = V_43 ;
V_47 . V_52 = 1 ;
if ( V_8 == V_133 )
V_47 . V_13 = V_53 ;
else
V_47 . V_13 = V_134 ;
V_47 . V_49 = & V_49 ;
V_47 . V_54 = 1 ;
F_17 ( & V_47 , V_2 ) ;
F_16 ( & V_49 , V_119 , V_43 ) ;
F_18 ( V_10 , & V_45 ) ;
V_5 = 0 ;
if ( V_8 == V_133 ) {
for ( V_32 = 0 ; V_32 < V_43 / 4 ; V_32 ++ )
if ( ( V_129 [ V_32 ] ^ V_119 [ V_32 ] ) != 0xff ) {
V_5 = - V_126 ;
break;
}
}
F_22 ( V_119 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_47 . error )
return V_47 . error ;
return V_5 ;
}
int F_49 ( struct V_1 * V_2 , T_3 V_120 )
{
int V_135 ;
if ( V_120 == V_121 )
V_135 = 8 ;
else if ( V_120 == V_123 )
V_135 = 4 ;
else if ( V_120 == V_136 )
return 0 ;
else
return - V_69 ;
F_47 ( V_2 , V_2 -> V_10 , V_132 , V_135 ) ;
return F_47 ( V_2 , V_2 -> V_10 , V_133 , V_135 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_6 V_7 = {} ;
unsigned int V_8 ;
int V_5 ;
if ( ! V_2 -> V_68 . V_137 ) {
F_31 ( L_4 ,
F_32 ( V_2 -> V_10 ) ) ;
return - V_69 ;
}
V_8 = V_2 -> V_68 . V_138 ;
if ( V_8 == V_128 )
V_7 . V_13 = V_107 | V_16 ;
else if ( V_8 == V_9 )
V_7 . V_13 = V_15 | V_16 ;
V_7 . V_8 = V_8 ;
V_7 . V_11 = V_2 -> V_12 << 16 | 1 ;
V_5 = F_3 ( V_2 -> V_10 , & V_7 , 0 ) ;
if ( V_5 ) {
F_31 ( L_5
L_6 , F_32 ( V_2 -> V_10 ) ,
V_5 , V_7 . V_17 [ 0 ] ) ;
return V_5 ;
}
if ( V_3 )
* V_3 = V_7 . V_17 [ 0 ] ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_3 ;
unsigned long V_139 ;
if ( ! V_2 -> V_68 . V_140 ) {
F_52 ( L_7 , F_32 ( V_2 -> V_10 ) ) ;
return 1 ;
}
F_53 ( V_2 -> V_10 ) ;
V_5 = F_4 ( V_2 , & V_3 ) ;
if ( V_5 ) {
F_39 ( L_8 , F_32 ( V_2 -> V_10 ) ) ;
goto V_111;
}
switch ( F_38 ( V_3 ) ) {
case V_141 :
case V_142 :
case V_143 :
case V_144 :
goto V_111;
case V_93 :
break;
default:
F_54 ( L_9 ,
F_32 ( V_2 -> V_10 ) , F_38 ( V_3 ) ) ;
V_5 = - V_69 ;
goto V_111;
}
V_5 = F_50 ( V_2 , & V_3 ) ;
if ( V_5 )
goto V_111;
V_139 = V_92 + F_36 ( V_2 -> V_68 . V_145 ) ;
do {
V_5 = F_4 ( V_2 , & V_3 ) ;
if ( ! V_5 && F_38 ( V_3 ) == V_144 )
break;
if ( F_37 ( V_92 , V_139 ) )
V_5 = - V_38 ;
} while ( ! V_5 );
V_111:
F_55 ( V_2 -> V_10 ) ;
return V_5 ;
}
int F_27 ( struct V_1 * V_2 )
{
return ( V_2 && V_2 -> V_59 . V_146 > V_147 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
V_5 = F_51 ( V_2 ) ;
if ( ! V_5 || ( V_5 == - V_69 ) ) {
F_57 ( V_2 ) ;
F_43 ( V_2 -> V_10 ) ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_5 ;
T_3 * V_68 ;
F_53 ( V_2 -> V_10 ) ;
V_5 = F_26 ( V_2 , & V_68 ) ;
F_55 ( V_2 -> V_10 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_68 . V_148 = V_68 [ V_149 ] ;
V_2 -> V_68 . V_150 = V_68 [ V_151 ] ;
F_22 ( V_68 ) ;
return 0 ;
}
void F_59 ( struct V_1 * V_2 , bool V_152 )
{
int V_5 ;
int V_86 ;
bool V_99 ;
if ( ! V_2 -> V_68 . V_153 || F_60 ( V_2 ) )
return;
V_5 = F_58 ( V_2 ) ;
if ( V_5 ) {
F_39 ( L_10 ,
F_32 ( V_2 -> V_10 ) , V_5 ) ;
return;
}
if ( ! V_2 -> V_68 . V_148 )
return;
if ( V_2 -> V_68 . V_148 < V_154 &&
V_152 )
return;
F_53 ( V_2 -> V_10 ) ;
if ( V_2 -> V_68 . V_148 >= V_154 ) {
V_86 = V_89 ;
V_99 = true ;
} else {
V_86 = 0 ;
V_99 = false ;
}
F_41 ( V_2 -> V_10 ) ;
V_5 = F_40 ( V_2 , V_155 ,
V_156 , 1 , V_86 , 0 ,
V_99 , true , false ) ;
if ( V_5 ) {
F_31 ( L_11 ,
F_32 ( V_2 -> V_10 ) , V_5 ) ;
F_43 ( V_2 -> V_10 ) ;
goto V_111;
}
if ( ! V_99 )
F_61 ( V_2 ) ;
else
F_43 ( V_2 -> V_10 ) ;
V_111:
F_55 ( V_2 -> V_10 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
if ( F_63 ( V_2 ) &&
( V_2 -> V_68 . V_157 > 0 ) &&
( V_2 -> V_68 . V_158 & 1 ) ) {
V_5 = F_44 ( V_2 , V_155 ,
V_159 , 1 , 0 ) ;
if ( V_5 )
F_39 ( L_12 ,
F_32 ( V_2 -> V_10 ) , V_5 ) ;
}
return V_5 ;
}
static int F_64 ( struct V_1 * V_2 , bool V_160 )
{
T_3 V_161 = V_160 ? V_162 : 0 ;
int V_5 ;
if ( ! V_2 -> V_68 . V_163 )
return - V_70 ;
V_5 = F_44 ( V_2 , V_155 , V_164 ,
V_161 , V_2 -> V_68 . V_165 ) ;
if ( ! V_5 )
V_2 -> V_68 . V_166 = V_160 ;
return V_5 ;
}
int F_65 ( struct V_1 * V_2 )
{
return F_64 ( V_2 , true ) ;
}
int F_66 ( struct V_1 * V_2 )
{
return F_64 ( V_2 , false ) ;
}
