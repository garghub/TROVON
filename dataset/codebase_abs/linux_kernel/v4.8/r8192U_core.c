double F_1 ( int V_1 )
{
return V_1 ;
}
unsigned int F_2 ( double V_2 )
{
return V_2 ;
}
double F_3 ( double V_3 , double V_4 )
{
return V_3 + V_4 ;
}
double F_4 ( float V_3 , float V_4 )
{
return V_3 + V_4 ;
}
double F_5 ( double V_3 , double V_4 )
{
return V_3 - V_4 ;
}
double F_6 ( float V_3 )
{
return V_3 ;
}
static void F_7 ( T_1 V_5 , struct V_6 * V_7 )
{
int V_1 , V_8 = - 1 , V_9 = - 1 ;
struct V_10 * V_11 = V_7 -> V_12 ;
switch ( V_5 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_8 ( V_11 ) ;
V_11 -> V_23 = false ;
if ( ( V_7 -> V_24 == V_25 ) || ( V_7 -> V_24 == V_26 ) ) {
V_9 = 1 ;
V_8 = 14 ;
} else {
F_9 ( V_27 ,
L_1 ,
V_28 ) ;
}
if ( V_29 [ V_5 ] . V_30 != 0 ) {
memset ( F_10 ( V_11 ) -> V_31 , 0 ,
sizeof( F_10 ( V_11 ) -> V_31 ) ) ;
for ( V_1 = 0 ; V_1 < V_29 [ V_5 ] . V_30 ; V_1 ++ ) {
if ( V_29 [ V_5 ] . V_32 [ V_1 ] < V_9 || V_29 [ V_5 ] . V_32 [ V_1 ] > V_8 )
break;
F_10 ( V_11 ) -> V_31 [ V_29 [ V_5 ] . V_32 [ V_1 ] ] = 1 ;
}
}
break;
case V_33 :
F_10 ( V_11 ) -> V_34 = 0 ;
F_11 ( V_11 ) ;
V_11 -> V_23 = true ;
break;
default:
break;
}
}
static void F_12 ( struct V_35 * V_36 )
{
T_2 V_37 = 0 ;
V_37 |= F_13 ( 31 ) | F_13 ( 30 ) ;
F_14 ( V_36 , V_38 , V_37 ) ;
}
void F_15 ( struct V_35 * V_36 , T_1 V_39 , T_2 V_40 )
{
F_14 ( V_36 , V_41 , V_40 ) ;
F_14 ( V_36 , V_38 , F_13 ( 31 ) | F_13 ( 16 ) | ( V_39 & 0xff ) ) ;
}
T_2 F_16 ( struct V_35 * V_36 , T_1 V_39 )
{
T_2 V_40 ;
F_14 ( V_36 , V_38 , 0x80000000 | ( V_39 & 0xff ) ) ;
F_17 ( V_36 , 0xa8 , & V_40 ) ;
return V_40 ;
}
int F_18 ( struct V_35 * V_36 , int V_42 , T_1 V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_1 * V_46 = F_20 ( sizeof( V_40 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
* V_46 = V_40 ;
V_43 = F_21 ( V_45 , F_22 ( V_45 , 0 ) ,
V_49 , V_50 ,
V_42 | 0xfe00 , 0 , V_46 , 1 , V_51 / 2 ) ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_2 ,
V_43 ) ;
return V_43 ;
}
return 0 ;
}
int F_25 ( struct V_35 * V_36 , int V_42 , T_1 * V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_1 * V_46 = F_20 ( sizeof( T_1 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
V_43 = F_21 ( V_45 , F_26 ( V_45 , 0 ) ,
V_52 , V_53 ,
V_42 | 0xfe00 , 0 , V_46 , 1 , V_51 / 2 ) ;
* V_40 = * V_46 ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_3 , V_28 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
int F_27 ( struct V_35 * V_36 , int V_42 , T_1 V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_1 * V_46 = F_20 ( sizeof( V_40 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
* V_46 = V_40 ;
V_43 = F_21 ( V_45 , F_22 ( V_45 , 0 ) ,
V_49 , V_50 ,
( V_42 & 0xff ) | 0xff00 , ( V_42 >> 8 ) & 0x0f ,
V_46 , 1 , V_51 / 2 ) ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_4 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
int F_28 ( struct V_35 * V_36 , int V_42 , T_3 V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_3 * V_46 = F_20 ( sizeof( V_40 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
* V_46 = V_40 ;
V_43 = F_21 ( V_45 , F_22 ( V_45 , 0 ) ,
V_49 , V_50 ,
( V_42 & 0xff ) | 0xff00 , ( V_42 >> 8 ) & 0x0f ,
V_46 , 2 , V_51 / 2 ) ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_5 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
int F_14 ( struct V_35 * V_36 , int V_42 , T_2 V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_2 * V_46 = F_20 ( sizeof( V_40 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
* V_46 = V_40 ;
V_43 = F_21 ( V_45 , F_22 ( V_45 , 0 ) ,
V_49 , V_50 ,
( V_42 & 0xff ) | 0xff00 , ( V_42 >> 8 ) & 0x0f ,
V_46 , 4 , V_51 / 2 ) ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_6 ,
V_43 ) ;
return V_43 ;
}
return 0 ;
}
int F_29 ( struct V_35 * V_36 , int V_42 , T_1 * V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_1 * V_46 = F_20 ( sizeof( T_1 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
V_43 = F_21 ( V_45 , F_26 ( V_45 , 0 ) ,
V_52 , V_53 ,
( V_42 & 0xff ) | 0xff00 , ( V_42 >> 8 ) & 0x0f ,
V_46 , 1 , V_51 / 2 ) ;
* V_40 = * V_46 ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_3 , V_28 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
int F_30 ( struct V_35 * V_36 , int V_42 , T_3 * V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_3 * V_46 = F_20 ( sizeof( T_3 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
V_43 = F_21 ( V_45 , F_26 ( V_45 , 0 ) ,
V_52 , V_53 ,
( V_42 & 0xff ) | 0xff00 , ( V_42 >> 8 ) & 0x0f ,
V_46 , 2 , V_51 / 2 ) ;
* V_40 = * V_46 ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_3 , V_28 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_31 ( struct V_35 * V_36 , int V_42 , T_3 * V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_3 * V_46 = F_20 ( sizeof( T_3 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
V_43 = F_21 ( V_45 , F_26 ( V_45 , 0 ) ,
V_52 , V_53 ,
V_42 | 0xfe00 , 0 , V_46 , 2 , V_51 / 2 ) ;
* V_40 = * V_46 ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_3 , V_28 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
int F_17 ( struct V_35 * V_36 , int V_42 , T_2 * V_40 )
{
int V_43 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
T_2 * V_46 = F_20 ( sizeof( T_2 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
V_43 = F_21 ( V_45 , F_26 ( V_45 , 0 ) ,
V_52 , V_53 ,
( V_42 & 0xff ) | 0xff00 , ( V_42 >> 8 ) & 0x0f ,
V_46 , 4 , V_51 / 2 ) ;
* V_40 = * V_46 ;
F_23 ( V_46 ) ;
if ( V_43 < 0 ) {
F_24 ( V_36 , L_3 , V_28 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
inline void F_32 ( struct V_35 * V_36 )
{
}
static int F_33 ( struct V_54 * V_55 , void * V_56 )
{
struct V_35 * V_36 = V_55 -> V_57 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_59 ;
F_34 (target, &ieee->network_list, list) {
const char * V_60 = L_7 ;
if ( V_59 -> V_61 > 0 || V_59 -> V_62 > 0 )
V_60 = L_8 ;
F_35 ( V_55 , L_9 , V_59 -> V_63 , V_60 ) ;
}
return 0 ;
}
static int F_36 ( struct V_54 * V_55 , void * V_56 )
{
struct V_35 * V_36 = V_55 -> V_57 ;
int V_1 , V_64 , V_65 = 0xff ;
T_1 V_66 ;
F_37 ( V_55 , L_10 ) ;
for ( V_64 = 0 ; V_64 <= V_65 ; ) {
F_35 ( V_55 , L_11 , V_64 ) ;
for ( V_1 = 0 ; V_1 < 16 && V_64 <= V_65 ; V_1 ++ , V_64 ++ ) {
F_29 ( V_36 , 0x000 | V_64 , & V_66 ) ;
F_35 ( V_55 , L_12 , V_66 ) ;
}
}
F_37 ( V_55 , L_13 ) ;
for ( V_64 = 0 ; V_64 <= V_65 ; ) {
F_35 ( V_55 , L_11 , V_64 ) ;
for ( V_1 = 0 ; V_1 < 16 && V_64 <= V_65 ; V_1 ++ , V_64 ++ ) {
F_29 ( V_36 , 0x100 | V_64 , & V_66 ) ;
F_35 ( V_55 , L_12 , V_66 ) ;
}
}
F_37 ( V_55 , L_14 ) ;
for ( V_64 = 0 ; V_64 <= V_65 ; ) {
F_35 ( V_55 , L_11 , V_64 ) ;
for ( V_1 = 0 ; V_1 < 16 && V_64 <= V_65 ; V_1 ++ , V_64 ++ ) {
F_29 ( V_36 , 0x300 | V_64 , & V_66 ) ;
F_35 ( V_55 , L_12 , V_66 ) ;
}
}
F_38 ( V_55 , '\n' ) ;
return 0 ;
}
static int F_39 ( struct V_54 * V_55 , void * V_56 )
{
struct V_35 * V_36 = V_55 -> V_57 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
F_35 ( V_55 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36
L_37
L_38 ,
V_7 -> V_67 . V_68 ,
V_7 -> V_67 . V_69 ,
V_7 -> V_67 . V_70 ,
V_7 -> V_67 . V_71 ,
V_7 -> V_67 . V_72 ,
V_7 -> V_67 . V_73 ,
V_7 -> V_67 . V_74 ,
V_7 -> V_67 . V_75 ,
V_7 -> V_67 . V_76 ,
V_7 -> V_67 . V_77 ,
V_7 -> V_67 . V_78 ,
V_7 -> V_67 . V_79 ,
V_7 -> V_67 . V_80 ,
F_40 ( V_36 ) ,
V_7 -> V_67 . V_81 ,
F_41 ( & ( V_7 -> V_82 [ V_83 ] ) ) ,
F_41 ( & ( V_7 -> V_82 [ V_84 ] ) ) ,
F_41 ( & ( V_7 -> V_82 [ V_85 ] ) ) ,
F_41 ( & ( V_7 -> V_82 [ V_86 ] ) ) ,
V_7 -> V_67 . V_87 ,
V_7 -> V_67 . V_88 ,
V_7 -> V_67 . V_89 ,
V_7 -> V_67 . V_90 ,
V_7 -> V_67 . V_91
) ;
return 0 ;
}
static int F_42 ( struct V_54 * V_55 , void * V_56 )
{
struct V_35 * V_36 = V_55 -> V_57 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
F_35 ( V_55 ,
L_39
L_40
L_41 ,
V_7 -> V_67 . V_92 ,
V_7 -> V_67 . V_93 ,
V_7 -> V_67 . V_94 ) ;
return 0 ;
}
static void F_43 ( void )
{
F_9 ( V_95 , L_42 ) ;
V_96 = F_44 ( V_97 , V_98 . V_99 ) ;
}
static int F_45 ( struct V_100 * V_100 , struct V_101 * V_101 )
{
struct V_35 * V_36 = F_46 ( V_100 ) ;
int (* F_47)( struct V_54 * , void * ) = F_48 ( V_100 ) ;
return F_49 ( V_101 , F_47 , V_36 ) ;
}
static void F_50 ( struct V_35 * V_36 )
{
const struct V_102 * V_103 ;
struct V_104 * V_105 ;
if ( V_96 ) {
V_105 = F_51 ( V_36 -> V_106 , 0 , V_96 , V_36 ) ;
if ( ! V_105 ) {
F_9 ( V_27 ,
L_43 ,
V_36 -> V_106 ) ;
return;
}
for ( V_103 = V_107 ; V_103 -> V_106 [ 0 ] ; V_103 ++ ) {
if ( ! F_52 ( V_103 -> V_106 , V_108 | V_109 , V_105 ,
& V_110 , V_103 -> F_47 ) ) {
F_9 ( V_27 ,
L_44 ,
V_36 -> V_106 , V_103 -> V_106 ) ;
return;
}
}
}
}
static void F_53 ( struct V_35 * V_36 )
{
F_54 ( V_36 -> V_106 , V_96 ) ;
}
short F_55 ( struct V_35 * V_36 , int V_111 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_112 = F_41 ( & V_7 -> V_82 [ V_111 ] ) ;
return ( V_112 < V_113 ) ;
}
static void F_56 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
F_57 ( & V_7 -> V_114 ) ;
}
void F_58 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_1 V_115 ;
F_29 ( V_36 , V_116 , & V_115 ) ;
V_115 &= ~ V_117 ;
if ( V_7 -> V_12 -> V_118 == V_119 ) {
if ( V_7 -> V_12 -> V_120 == V_121 )
V_115 |= ( V_122 << V_123 ) ;
else if ( V_7 -> V_12 -> V_120 == V_124 )
V_115 |= ( V_125 << V_123 ) ;
else if ( V_7 -> V_12 -> V_120 == V_126 )
V_115 |= ( V_127 << V_123 ) ;
} else {
V_115 |= ( V_128 << V_123 ) ;
}
F_27 ( V_36 , V_116 , V_115 ) ;
}
void F_59 ( struct V_35 * V_36 , short V_129 )
{
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
F_9 ( V_130 , L_45 , V_28 , V_129 ) ;
V_7 -> V_131 = V_129 ;
if ( V_7 -> V_132 )
V_7 -> V_132 ( V_36 , V_7 -> V_131 ) ;
F_60 ( 10 ) ;
}
static T_2 F_61 ( struct V_133 * V_134 )
{
return ( sizeof( V_135 ) + V_134 -> V_136
+ V_134 -> V_137 ) ;
}
static int F_62 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
while ( F_63 ( & V_7 -> V_144 ) < V_145 ) {
V_141 = F_64 ( V_146 , V_47 ) ;
if ( ! V_141 )
break;
V_139 = F_65 ( 0 , V_47 ) ;
if ( ! V_139 ) {
F_66 ( V_141 ) ;
break;
}
F_67 ( V_139 , V_7 -> V_45 ,
F_68 ( V_7 -> V_45 , 3 ) ,
F_69 ( V_141 ) ,
V_146 , V_147 , V_141 ) ;
V_143 = (struct V_142 * ) V_141 -> V_148 ;
V_143 -> V_138 = V_139 ;
V_143 -> V_36 = V_36 ;
V_143 -> V_149 = 3 ;
F_70 ( & V_7 -> V_144 , V_141 ) ;
F_71 ( V_139 , V_47 ) ;
}
while ( F_63 ( & V_7 -> V_144 ) < V_145 + 3 ) {
V_141 = F_64 ( V_146 , V_47 ) ;
if ( ! V_141 )
break;
V_139 = F_65 ( 0 , V_47 ) ;
if ( ! V_139 ) {
F_66 ( V_141 ) ;
break;
}
F_67 ( V_139 , V_7 -> V_45 ,
F_68 ( V_7 -> V_45 , 9 ) ,
F_69 ( V_141 ) ,
V_146 , V_147 , V_141 ) ;
V_143 = (struct V_142 * ) V_141 -> V_148 ;
V_143 -> V_138 = V_139 ;
V_143 -> V_36 = V_36 ;
V_143 -> V_149 = 9 ;
F_70 ( & V_7 -> V_144 , V_141 ) ;
F_71 ( V_139 , V_47 ) ;
}
return 0 ;
}
void F_72 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
T_2 V_150 ;
F_17 ( V_36 , V_151 , & V_150 ) ;
V_150 = V_150 & ~ V_152 ;
V_150 = V_150 | V_153 ;
V_150 = V_150 | V_154 ;
V_150 = V_150 | V_155 ;
V_150 = V_150 | V_156 ;
if ( V_36 -> V_157 & V_158 )
F_73 ( L_46 ) ;
if ( V_7 -> V_12 -> V_120 == V_159 ||
V_36 -> V_157 & V_158 ) {
V_150 = V_150 | V_160 ;
} else {
V_150 = V_150 | V_161 ;
V_150 = V_150 | V_162 ;
}
if ( V_7 -> V_12 -> V_120 == V_159 ) {
V_150 = V_150 | V_163 ;
V_150 = V_150 | V_164 ;
}
if ( V_7 -> V_165 == 1 && V_7 -> V_12 -> V_120 == V_159 )
V_150 = V_150 | V_166 ;
V_150 = V_150 & ~ V_167 ;
V_150 = V_150 | ( V_168 << V_169 ) ;
V_150 = V_150 & ~ V_170 ;
V_150 = V_150 | ( ( T_2 ) 7 << V_171 ) ;
V_150 = V_150 | V_172 ;
F_14 ( V_36 , V_151 , V_150 ) ;
}
void F_74 ( struct V_35 * V_36 )
{
F_62 ( V_36 ) ;
}
void F_75 ( struct V_35 * V_36 )
{
}
void F_76 ( struct V_35 * V_36 )
{
T_1 V_173 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
F_29 ( V_36 , V_174 , & V_173 ) ;
F_27 ( V_36 , V_174 , V_173 & ~ ( V_175 | V_176 ) ) ;
F_32 ( V_36 ) ;
F_60 ( 10 ) ;
while ( ( V_141 = F_77 ( & V_7 -> V_144 ) ) ) {
V_143 = (struct V_142 * ) V_141 -> V_148 ;
if ( ! V_143 -> V_138 )
continue;
F_78 ( V_143 -> V_138 ) ;
F_66 ( V_141 ) ;
}
if ( F_63 ( & V_7 -> V_177 ) )
F_79 ( V_36 , L_47 ) ;
F_80 ( & V_7 -> V_177 ) ;
}
inline T_3 F_81 ( int V_178 )
{
switch ( V_178 ) {
case 10 :
return 0 ;
case 20 :
return 1 ;
case 55 :
return 2 ;
case 110 :
return 3 ;
case 60 :
return 4 ;
case 90 :
return 5 ;
case 120 :
return 6 ;
case 180 :
return 7 ;
case 240 :
return 8 ;
case 360 :
return 9 ;
case 480 :
return 10 ;
case 540 :
return 11 ;
default:
return 3 ;
}
}
inline T_3 F_82 ( short V_178 )
{
if ( V_178 > 11 )
return 0 ;
return V_179 [ V_178 ] ;
}
static void V_147 ( struct V_138 * V_138 )
{
struct V_140 * V_141 = (struct V_140 * ) V_138 -> V_180 ;
struct V_142 * V_143 = (struct V_142 * ) V_141 -> V_148 ;
struct V_35 * V_36 = V_143 -> V_36 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_149 = V_143 -> V_149 ;
int V_181 ;
if ( ! V_7 -> V_182 )
return;
if ( F_83 ( V_138 -> V_43 ) ) {
V_143 -> V_138 = NULL ;
V_7 -> V_67 . V_93 ++ ;
V_7 -> V_12 -> V_67 . V_183 ++ ;
F_84 ( V_138 ) ;
return;
}
F_85 ( V_141 , & V_7 -> V_144 ) ;
F_86 ( V_141 , V_138 -> V_184 ) ;
F_70 ( & V_7 -> V_177 , V_141 ) ;
F_87 ( & V_7 -> V_185 ) ;
V_141 = F_88 ( V_146 ) ;
if ( F_83 ( ! V_141 ) ) {
F_84 ( V_138 ) ;
F_24 ( V_36 , L_48 , V_28 ) ;
return;
}
F_67 ( V_138 , V_7 -> V_45 ,
F_68 ( V_7 -> V_45 , V_149 ) ,
F_69 ( V_141 ) ,
V_146 , V_147 , V_141 ) ;
V_143 = (struct V_142 * ) V_141 -> V_148 ;
V_143 -> V_138 = V_138 ;
V_143 -> V_36 = V_36 ;
V_143 -> V_149 = V_149 ;
V_138 -> V_186 = F_69 ( V_141 ) ;
V_138 -> V_180 = V_141 ;
F_70 ( & V_7 -> V_144 , V_141 ) ;
V_181 = F_71 ( V_138 , V_187 ) ;
if ( V_181 && V_181 != V_188 )
F_24 ( V_36 ,
L_49 ,
V_181 , V_138 -> V_43 ) ;
}
static T_2 F_89 ( struct V_35 * V_36 ,
struct V_133 * V_134 )
{
T_2 V_43 ;
V_43 = F_90 ( V_36 , V_134 ) ;
if ( V_43 )
F_73 ( L_50 ) ;
return V_43 ;
}
static void F_91 ( struct V_35 * V_36 )
{
}
static void F_92 ( struct V_35 * V_36 )
{
}
static void F_93 ( struct V_140 * V_141 , struct V_35 * V_36 ,
int V_178 )
{
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
int V_189 ;
unsigned long V_157 ;
T_4 * V_190 = ( T_4 * ) ( V_141 -> V_148 + V_191 ) ;
T_1 V_111 = V_190 -> V_111 ;
F_94 ( V_111 != V_192 ) ;
F_95 ( & V_7 -> V_193 , V_157 ) ;
* (struct V_35 * * ) ( V_141 -> V_148 ) = V_36 ;
V_190 -> V_194 = 1 ;
F_96 ( V_141 , V_7 -> V_12 -> V_195 ) ;
V_189 = F_97 ( V_36 , V_141 ) ;
F_98 ( & V_7 -> V_193 , V_157 ) ;
}
static int F_99 ( struct V_140 * V_141 , struct V_35 * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
int V_189 ;
unsigned long V_157 ;
T_4 * V_190 = ( T_4 * ) ( V_141 -> V_148 + V_191 ) ;
T_1 V_111 = V_190 -> V_111 ;
F_95 ( & V_7 -> V_193 , V_157 ) ;
memcpy ( ( unsigned char * ) ( V_141 -> V_148 ) , & V_36 , sizeof( V_36 ) ) ;
if ( V_111 == V_192 ) {
F_96 ( V_141 , V_196 ) ;
F_100 ( V_36 , V_141 ) ;
V_189 = 1 ;
} else {
F_96 ( V_141 , V_7 -> V_12 -> V_195 ) ;
V_189 = F_97 ( V_36 , V_141 ) ;
}
F_98 ( & V_7 -> V_193 , V_157 ) ;
return V_189 ;
}
static void F_101 ( struct V_138 * V_197 )
{
struct V_140 * V_141 = (struct V_140 * ) V_197 -> V_180 ;
struct V_35 * V_36 ;
struct V_6 * V_7 = NULL ;
T_4 * V_190 ;
T_1 V_111 ;
if ( ! V_141 )
return;
V_36 = * (struct V_35 * * ) ( V_141 -> V_148 ) ;
V_190 = ( T_4 * ) ( V_141 -> V_148 + V_191 ) ;
V_111 = V_190 -> V_111 ;
V_7 = F_19 ( V_36 ) ;
if ( V_190 -> V_111 != V_192 ) {
if ( V_197 -> V_43 == 0 ) {
F_102 ( V_36 ) ;
V_7 -> V_67 . V_198 ++ ;
V_7 -> V_12 -> V_199 . V_200 ++ ;
V_7 -> V_67 . V_201 +=
( V_141 -> V_202 - V_7 -> V_12 -> V_195 ) ;
} else {
V_7 -> V_12 -> V_67 . V_203 ++ ;
}
}
F_103 ( V_141 ) ;
F_84 ( V_197 ) ;
F_104 ( & V_7 -> V_82 [ V_111 ] ) ;
if ( V_111 != V_204 ) {
if ( ( F_63 ( & V_7 -> V_12 -> V_205 [ V_111 ] ) != 0 ) &&
( ! ( V_7 -> V_12 -> V_206 ) ) ) {
V_141 = F_105 ( & ( V_7 -> V_12 -> V_205 [ V_111 ] ) ) ;
if ( V_141 )
V_7 -> V_12 -> V_207 ( V_141 ,
V_36 ) ;
return;
}
}
}
static void F_106 ( struct V_35 * V_36 , T_3 * V_208 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
struct V_58 * V_209 ;
T_1 V_1 = 0 , V_210 = 0 ;
V_209 = & V_7 -> V_12 -> V_211 ;
for ( V_1 = 0 ; V_1 < V_209 -> V_212 ; V_1 ++ ) {
V_210 = V_209 -> V_213 [ V_1 ] & 0x7f ;
switch ( V_210 ) {
case V_214 :
* V_208 |= V_215 ;
break;
case V_216 :
* V_208 |= V_217 ;
break;
case V_218 :
* V_208 |= V_219 ;
break;
case V_220 :
* V_208 |= V_221 ;
break;
case V_222 :
* V_208 |= V_223 ;
break;
case V_224 :
* V_208 |= V_225 ;
break;
case V_226 :
* V_208 |= V_227 ;
break;
case V_228 :
* V_208 |= V_229 ;
break;
case V_230 :
* V_208 |= V_231 ;
break;
case V_232 :
* V_208 |= V_233 ;
break;
case V_234 :
* V_208 |= V_235 ;
break;
case V_236 :
* V_208 |= V_237 ;
break;
}
}
for ( V_1 = 0 ; V_1 < V_209 -> V_238 ; V_1 ++ ) {
V_210 = V_209 -> V_239 [ V_1 ] & 0x7f ;
switch ( V_210 ) {
case V_214 :
* V_208 |= V_215 ;
break;
case V_216 :
* V_208 |= V_217 ;
break;
case V_218 :
* V_208 |= V_219 ;
break;
case V_220 :
* V_208 |= V_221 ;
break;
case V_222 :
* V_208 |= V_223 ;
break;
case V_224 :
* V_208 |= V_225 ;
break;
case V_226 :
* V_208 |= V_227 ;
break;
case V_228 :
* V_208 |= V_229 ;
break;
case V_230 :
* V_208 |= V_231 ;
break;
case V_232 :
* V_208 |= V_233 ;
break;
case V_234 :
* V_208 |= V_235 ;
break;
case V_236 :
* V_208 |= V_237 ;
break;
}
}
}
static void F_107 ( struct V_35 * V_36 , T_3 V_240 )
{
T_2 V_241 = 0 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
struct V_58 * V_209 = & V_7 -> V_12 -> V_211 ;
V_7 -> V_242 = V_240 & V_243 ;
V_241 = V_7 -> V_210 ;
if ( V_7 -> V_242 )
V_241 |= V_244 ;
F_14 ( V_36 , V_245 , V_241 ) ;
if ( V_209 -> V_246 & ( V_247 | V_248 ) ) {
T_1 V_249 = 0 ;
if ( ( V_240 & V_250 ) &&
( ! V_7 -> V_12 -> V_251 -> V_252 ) )
V_249 = V_253 ;
else
V_249 = V_254 ;
V_7 -> V_249 = V_249 ;
F_27 ( V_36 , V_255 , V_249 ) ;
}
}
static void F_108 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
struct V_58 * V_209 ;
T_3 V_256 = 0 , V_257 = 6 , V_258 = 0xf ;
T_3 V_208 = 0 ;
V_209 = & V_7 -> V_12 -> V_211 ;
F_106 ( V_36 , & V_208 ) ;
V_7 -> V_210 = V_208 & 0x15f ;
F_14 ( V_36 , V_259 , ( ( T_2 * ) V_209 -> V_260 ) [ 0 ] ) ;
F_28 ( V_36 , V_259 + 4 , ( ( T_3 * ) V_209 -> V_260 ) [ 2 ] ) ;
F_58 ( V_36 ) ;
if ( V_7 -> V_12 -> V_120 == V_124 ) {
F_28 ( V_36 , V_261 , 2 ) ;
F_28 ( V_36 , V_262 , 1023 ) ;
F_28 ( V_36 , V_263 , V_209 -> V_264 ) ;
F_28 ( V_36 , V_265 , 1 ) ;
F_27 ( V_36 , V_266 , 100 ) ;
V_256 |= ( V_257 << V_267 ) ;
V_256 |= V_258 << V_268 ;
F_28 ( V_36 , V_269 , V_256 ) ;
}
}
void F_109 ( struct V_35 * V_36 , T_3 V_270 )
{
}
inline T_1 F_110 ( T_3 V_178 )
{
if ( ( ( V_178 <= 110 ) && ( V_178 != 60 ) && ( V_178 != 90 ) ) || ( V_178 == 220 ) )
return 1 ;
else
return 0 ;
}
short F_100 ( struct V_35 * V_36 , struct V_140 * V_141 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_43 ;
struct V_138 * V_197 ;
unsigned int V_271 ;
T_5 * V_272 = ( T_5 * ) V_141 -> V_40 ;
T_4 * V_190 = ( T_4 * ) ( V_141 -> V_148 + V_191 ) ;
T_1 V_111 = V_190 -> V_111 ;
F_111 ( & V_7 -> V_82 [ V_111 ] ) ;
V_197 = F_65 ( 0 , V_187 ) ;
if ( ! V_197 ) {
F_112 ( V_141 ) ;
return - V_48 ;
}
memset ( V_272 , 0 , V_196 ) ;
V_272 -> V_273 = 1 ;
V_272 -> V_274 = 1 ;
V_272 -> V_275 = V_190 -> V_276 ;
V_272 -> V_277 = V_190 -> V_278 ;
V_272 -> V_279 = 1 ;
V_272 -> V_280 = V_190 -> V_281 ;
V_271 = 0x04 ;
F_67 ( V_197 , V_7 -> V_45 ,
F_113 ( V_7 -> V_45 , V_271 ) ,
V_141 -> V_40 , V_141 -> V_202 , F_101 , V_141 ) ;
V_43 = F_71 ( V_197 , V_187 ) ;
if ( ! V_43 )
return 0 ;
F_114 ( L_51 , V_43 ) ;
return - 1 ;
}
static T_1 F_115 ( T_1 V_282 )
{
T_1 V_283 = 0x0 ;
switch ( V_282 ) {
case V_284 :
V_283 = V_285 ;
break;
case V_286 :
V_283 = V_287 ;
break;
case V_288 :
V_283 = V_289 ;
break;
case V_290 :
V_283 = V_291 ;
break;
case V_292 :
V_283 = V_293 ;
break;
case V_204 :
V_283 = V_294 ;
break;
case V_192 :
V_283 = V_295 ;
break;
case V_296 :
V_283 = V_297 ;
break;
default:
F_9 ( V_27 ,
L_52 ,
V_282 ) ;
break;
}
return V_283 ;
}
static T_1 F_116 ( T_1 V_178 )
{
T_1 V_189 = V_298 ;
switch ( V_178 ) {
case V_214 :
V_189 = V_298 ;
break;
case V_216 :
V_189 = V_299 ;
break;
case V_218 :
V_189 = V_300 ;
break;
case V_220 :
V_189 = V_301 ;
break;
case V_222 :
V_189 = V_302 ;
break;
case V_224 :
V_189 = V_303 ;
break;
case V_226 :
V_189 = V_304 ;
break;
case V_228 :
V_189 = V_305 ;
break;
case V_230 :
V_189 = V_306 ;
break;
case V_232 :
V_189 = V_307 ;
break;
case V_234 :
V_189 = V_308 ;
break;
case V_236 :
V_189 = V_309 ;
break;
case V_310 :
V_189 = V_311 ;
break;
case V_312 :
V_189 = V_313 ;
break;
case V_314 :
V_189 = V_315 ;
break;
case V_316 :
V_189 = V_317 ;
break;
case V_318 :
V_189 = V_319 ;
break;
case V_320 :
V_189 = V_321 ;
break;
case V_322 :
V_189 = V_323 ;
break;
case V_324 :
V_189 = V_325 ;
break;
case V_326 :
V_189 = V_327 ;
break;
case V_328 :
V_189 = V_329 ;
break;
case V_330 :
V_189 = V_331 ;
break;
case V_332 :
V_189 = V_333 ;
break;
case V_334 :
V_189 = V_335 ;
break;
case V_336 :
V_189 = V_337 ;
break;
case V_338 :
V_189 = V_339 ;
break;
case V_340 :
V_189 = V_341 ;
break;
case ( 0x80 | 0x20 ) :
V_189 = V_342 ;
break;
default:
break;
}
return V_189 ;
}
static T_1 F_117 ( T_1 V_343 , T_1 V_344 , T_4 * V_190 )
{
T_1 V_345 ;
V_345 = ( V_343 == 1 ) ?
( ( V_190 -> V_346 ) ? 1 : 0 ) :
( ( V_190 -> V_347 ) ? 1 : 0 ) ;
if ( V_343 == 1 && V_344 != V_341 )
V_345 = 0 ;
return V_345 ;
}
static void F_118 ( struct V_138 * V_197 )
{
}
short F_97 ( struct V_35 * V_36 , struct V_140 * V_141 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_4 * V_190 = ( T_4 * ) ( V_141 -> V_148 + V_191 ) ;
T_6 * V_348 = ( T_6 * ) V_141 -> V_40 ;
T_7 * V_349 =
( T_7 * ) ( V_141 -> V_40 + V_196 ) ;
struct V_44 * V_45 = V_7 -> V_45 ;
int V_350 ;
int V_43 ;
struct V_138 * V_197 = NULL , * V_351 = NULL ;
unsigned int V_271 ;
V_350 = F_41 ( & V_7 -> V_82 [ V_190 -> V_111 ] ) ;
if ( V_350 > V_113 ) {
F_119 ( V_36 , L_53 ) ;
F_103 ( V_141 ) ;
return - 1 ;
}
V_197 = F_65 ( 0 , V_187 ) ;
if ( ! V_197 ) {
F_103 ( V_141 ) ;
return - V_48 ;
}
memset ( V_349 , 0 , sizeof( T_7 ) ) ;
V_349 -> V_343 = ( V_190 -> V_352 & 0x80 ) ? 1 : 0 ;
V_349 -> V_344 = F_116 ( V_190 -> V_352 ) ;
V_349 -> V_353 = V_190 -> V_194 ;
V_349 -> Short = F_117 ( V_349 -> V_343 , V_349 -> V_344 ,
V_190 ) ;
if ( V_190 -> V_354 ) {
V_349 -> V_355 = 1 ;
V_349 -> V_356 = V_190 -> V_357 ;
V_349 -> V_358 = V_190 -> V_359 & 0x07 ;
} else {
V_349 -> V_355 = 0 ;
V_349 -> V_356 = 0 ;
V_349 -> V_358 = 0 ;
}
V_349 -> V_360 = ( V_190 -> V_361 ) ? 1 : 0 ;
V_349 -> V_362 = ( V_190 -> V_363 ) ? 1 : 0 ;
V_349 -> V_364 = ( V_190 -> V_365 ) ? 1 : 0 ;
V_349 -> V_366 = ( V_190 -> V_367 & 0x80 ) ? 1 : 0 ;
V_349 -> V_368 = F_116 ( ( T_1 ) V_190 -> V_367 ) ;
V_349 -> V_369 = ( V_349 -> V_366 == 0 ) ? ( V_190 -> V_370 ) : 0 ;
V_349 -> V_371 = ( V_349 -> V_366 == 1 ) ? ( ( V_190 -> V_372 ) ? 1 : 0 ) : 0 ;
V_349 -> V_373 = ( V_349 -> V_366 == 0 ) ? ( V_190 -> V_374 ? 1 : 0 ) :
( V_190 -> V_375 ? 1 : 0 ) ;
if ( V_7 -> V_376 == V_377 ) {
if ( V_190 -> V_378 ) {
V_349 -> V_379 = 1 ;
V_349 -> V_380 = 0 ;
} else {
V_349 -> V_379 = 0 ;
V_349 -> V_380 = V_7 -> V_381 ;
}
} else {
V_349 -> V_379 = 0 ;
V_349 -> V_380 = 0 ;
}
memset ( V_348 , 0 , sizeof( T_6 ) ) ;
V_348 -> V_280 = 0 ;
V_348 -> V_275 = 1 ;
V_348 -> V_382 = sizeof( T_7 ) + 8 ;
V_348 -> V_383 = ( V_141 -> V_202 - V_384 ) & 0xffff ;
V_348 -> V_385 = 0 ;
V_348 -> V_386 = V_190 -> V_387 ;
V_348 -> V_388 = 1 ;
V_348 -> V_389 = 0x0 ;
if ( V_190 -> V_390 ) {
switch ( V_7 -> V_12 -> V_391 ) {
case V_392 :
case V_393 :
V_348 -> V_389 = 0x1 ;
V_348 -> V_388 = 0 ;
break;
case V_394 :
V_348 -> V_389 = 0x2 ;
V_348 -> V_388 = 0 ;
break;
case V_395 :
V_348 -> V_389 = 0x3 ;
V_348 -> V_388 = 0 ;
break;
case V_396 :
V_348 -> V_389 = 0x0 ;
V_348 -> V_388 = 1 ;
break;
}
}
V_348 -> V_283 = F_115 ( V_190 -> V_111 ) ;
V_348 -> V_397 = sizeof( T_7 ) ;
V_348 -> V_398 = V_190 -> V_399 ;
V_348 -> V_400 = V_190 -> V_401 ;
V_348 -> V_273 = 1 ;
V_348 -> V_274 = 1 ;
V_348 -> V_279 = 1 ;
V_348 -> V_277 = ( T_2 ) ( V_141 -> V_202 - V_196 ) ;
V_271 = 0x5 ;
F_67 ( V_197 , V_45 ,
F_113 ( V_45 , V_271 ) , V_141 -> V_40 ,
V_141 -> V_202 , F_101 , V_141 ) ;
V_43 = F_71 ( V_197 , V_187 ) ;
if ( ! V_43 ) {
bool V_402 = false ;
T_1 V_403 = 0 ;
if ( V_45 -> V_404 == V_405 ) {
if ( V_141 -> V_202 > 0 && V_141 -> V_202 % 512 == 0 )
V_402 = true ;
} else {
if ( V_141 -> V_202 > 0 && V_141 -> V_202 % 64 == 0 )
V_402 = true ;
}
if ( V_402 ) {
V_351 = F_65 ( 0 , V_187 ) ;
if ( ! V_351 ) {
F_9 ( V_27 ,
L_54 ) ;
return - V_48 ;
}
F_67 ( V_351 , V_45 ,
F_113 ( V_45 , V_271 ) ,
& V_403 , 0 , F_118 , V_36 ) ;
V_43 = F_71 ( V_351 , V_187 ) ;
if ( V_43 ) {
F_9 ( V_27 ,
L_55 ,
F_41 ( & V_7 -> V_82 [ V_190 -> V_111 ] ) ,
V_43 ) ;
return - 1 ;
}
}
F_102 ( V_36 ) ;
F_111 ( & V_7 -> V_82 [ V_190 -> V_111 ] ) ;
return 0 ;
}
F_9 ( V_27 , L_56 ,
F_41 ( & V_7 -> V_82 [ V_190 -> V_111 ] ) ,
V_43 ) ;
return - 1 ;
}
static short F_120 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
V_7 -> V_406 = F_121 ( sizeof( struct V_138 * ) * ( V_145 + 1 ) ,
V_47 ) ;
if ( ! V_7 -> V_406 )
return - V_48 ;
#ifndef F_122
for ( V_1 = 0 ; V_1 < ( V_145 + 1 ) ; V_1 ++ ) {
V_7 -> V_406 [ V_1 ] = F_65 ( 0 , V_47 ) ;
V_7 -> V_406 [ V_1 ] -> V_186 =
F_121 ( V_146 , V_47 ) ;
V_7 -> V_406 [ V_1 ] -> V_407 = V_146 ;
}
#endif
#ifdef F_123
{
long V_408 = 0 ;
void * V_409 , * V_410 ;
V_7 -> V_406 [ 16 ] = F_65 ( 0 , V_47 ) ;
V_7 -> V_409 = F_121 ( 16 , V_47 ) ;
V_409 = V_7 -> V_409 ;
V_408 = ( ( long ) V_409 ) & 3 ;
if ( V_408 ) {
V_410 = V_409 + 4 - V_408 ;
V_7 -> V_406 [ 16 ] -> V_407 = 16 - 4 + V_408 ;
} else {
V_410 = V_409 ;
V_7 -> V_406 [ 16 ] -> V_407 = 16 ;
}
V_7 -> V_406 [ 16 ] -> V_186 = V_410 ;
}
#endif
memset ( V_7 -> V_406 , 0 , sizeof( struct V_138 * ) * V_145 ) ;
V_7 -> V_411 = F_124 ( V_145 , sizeof( struct V_140 * ) ,
V_47 ) ;
if ( ! V_7 -> V_411 ) {
F_23 ( V_7 -> V_406 ) ;
V_7 -> V_411 = NULL ;
V_7 -> V_406 = NULL ;
F_114 ( L_57 ) ;
return - V_48 ;
}
F_119 ( V_36 , L_58 ) ;
return 0 ;
}
static void F_125 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
if ( V_7 -> V_406 ) {
for ( V_1 = 0 ; V_1 < ( V_145 + 1 ) ; V_1 ++ ) {
F_78 ( V_7 -> V_406 [ V_1 ] ) ;
F_84 ( V_7 -> V_406 [ V_1 ] ) ;
}
F_23 ( V_7 -> V_406 ) ;
V_7 -> V_406 = NULL ;
}
F_23 ( V_7 -> V_409 ) ;
V_7 -> V_409 = NULL ;
F_23 ( V_7 -> V_411 ) ;
V_7 -> V_411 = NULL ;
}
void F_125 ( struct V_35 * V_36 )
{
int V_1 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
#ifndef F_122
if ( V_7 -> V_406 ) {
for ( V_1 = 0 ; V_1 < ( V_145 + 1 ) ; V_1 ++ ) {
F_78 ( V_7 -> V_406 [ V_1 ] ) ;
F_23 ( V_7 -> V_406 [ V_1 ] -> V_186 ) ;
F_84 ( V_7 -> V_406 [ V_1 ] ) ;
}
F_23 ( V_7 -> V_406 ) ;
V_7 -> V_406 = NULL ;
}
#else
F_23 ( V_7 -> V_406 ) ;
V_7 -> V_406 = NULL ;
F_23 ( V_7 -> V_409 ) ;
V_7 -> V_409 = NULL ;
F_23 ( V_7 -> V_411 ) ;
V_7 -> V_411 = 0 ;
#endif
}
static void F_126 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_118 == V_119 ) {
F_108 ( V_36 ) ;
F_127 ( V_36 ) ;
if ( V_392 == V_11 -> V_391 ||
V_393 == V_11 -> V_391 )
F_128 ( V_36 ) ;
}
if ( V_11 -> V_120 == V_121 || V_11 -> V_120 == V_124 ) {
T_2 V_412 = 0 ;
F_17 ( V_36 , V_151 , & V_412 ) ;
if ( V_7 -> V_12 -> V_118 == V_119 )
V_7 -> V_413 = V_412 |= V_162 ;
else
V_7 -> V_413 = V_412 &= ~ V_162 ;
F_14 ( V_36 , V_151 , V_412 ) ;
}
}
static void F_129 ( struct V_414 * V_415 )
{
struct V_6 * V_7 = F_130 ( V_415 , struct V_6 ,
V_416 . V_415 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_209 = & V_11 -> V_211 ;
if ( V_11 -> V_251 -> V_417 )
F_131 ( V_11 , V_209 ) ;
V_11 -> V_251 -> V_252 =
V_209 -> V_418 . V_419 ;
F_107 ( V_36 , V_209 -> V_420 ) ;
}
static void F_132 ( struct V_414 * V_415 )
{
struct V_6 * V_7 = F_130 ( V_415 , struct V_6 ,
V_421 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_422 * V_423 =
& V_7 -> V_12 -> V_211 . V_424 . V_425 ;
T_1 V_246 = V_7 -> V_12 -> V_211 . V_246 ;
T_2 V_426 ;
T_2 V_427 ;
T_2 V_428 ;
T_2 V_429 ;
T_2 V_430 ;
int V_1 ;
F_133 ( & V_7 -> V_431 ) ;
if ( V_7 -> V_12 -> V_118 != V_119 )
goto V_432;
F_9 ( V_433 ,
L_59 ) ;
for ( V_1 = 0 ; V_1 < V_434 ; V_1 ++ ) {
V_426 = V_423 -> V_435 [ V_1 ] * ( ( V_246 & ( V_247 | V_248 ) ) ? 9 : 20 ) + V_436 ;
V_426 <<= V_437 ;
V_428 = ( T_2 ) F_134 ( V_423 -> V_438 [ V_1 ] ) ;
V_428 <<= V_439 ;
V_429 = ( T_2 ) F_134 ( V_423 -> V_429 [ V_1 ] ) ;
V_429 <<= V_440 ;
V_430 = ( T_2 ) F_134 ( V_423 -> V_430 [ V_1 ] ) ;
V_430 <<= V_441 ;
V_427 = V_428 | V_429 | V_430 | V_426 ;
F_14 ( V_36 , V_442 [ V_1 ] , V_427 ) ;
}
V_432:
F_135 ( & V_7 -> V_431 ) ;
}
static int F_136 ( struct V_6 * V_7 ,
int V_443 ,
struct V_58 * V_444 )
{
int V_189 = 0 ;
T_2 V_445 = sizeof( struct V_422 ) ;
if ( V_7 -> V_12 -> V_118 != V_119 )
return V_189 ;
if ( V_7 -> V_12 -> V_120 != V_121 )
return V_189 ;
if ( V_444 -> V_157 & V_446 ) {
if ( V_443 &&
( V_444 -> V_157 & V_447 ) )
V_444 -> V_424 . V_448 = V_444 -> V_424 . V_449 ;
if ( ( V_444 -> V_424 . V_448 == 1 ) && ( V_443 == 1 ) &&
( V_444 -> V_157 & V_447 ) &&
( V_444 -> V_424 . V_450 !=
V_444 -> V_424 . V_451 ) ) {
V_444 -> V_424 . V_450 =
V_444 -> V_424 . V_451 ;
F_57 ( & V_7 -> V_421 ) ;
F_9 ( V_433 ,
L_60 ) ;
}
} else {
memcpy ( & V_7 -> V_12 -> V_211 . V_424 . V_425 ,
& V_452 , V_445 ) ;
if ( ( V_444 -> V_424 . V_448 == 1 ) && ( V_443 == 1 ) ) {
F_57 ( & V_7 -> V_421 ) ;
F_9 ( V_433 ,
L_61 ) ;
}
V_444 -> V_424 . V_448 = 0 ;
V_444 -> V_424 . V_449 = 0 ;
}
return 0 ;
}
static int F_137 ( struct V_35 * V_36 ,
struct V_453 * V_454 ,
struct V_58 * V_444 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
F_136 ( V_7 , 1 , V_444 ) ;
F_138 ( & V_7 -> V_416 , 0 ) ;
return 0 ;
}
static int F_139 ( struct V_6 * V_7 ,
struct V_58 * V_444 )
{
unsigned long V_157 ;
T_2 V_445 = sizeof( struct V_422 ) ;
int V_455 = 0 ;
if ( ! V_7 || ! V_444 )
return 0 ;
if ( V_7 -> V_12 -> V_118 != V_119 )
return 0 ;
if ( V_7 -> V_12 -> V_120 != V_121 )
return 0 ;
F_95 ( & V_7 -> V_12 -> V_456 , V_157 ) ;
if ( V_444 -> V_157 & V_447 ) {
memcpy ( & V_7 -> V_12 -> V_211 . V_424 . V_425 ,
& V_444 -> V_424 . V_425 ,
sizeof( struct V_422 ) ) ;
V_7 -> V_12 -> V_211 . V_424 . V_448 = 1 ;
V_455 = 1 ;
V_7 -> V_12 -> V_211 . V_424 . V_450 =
V_7 -> V_12 -> V_211 . V_424 . V_451 ;
V_7 -> V_12 -> V_211 . V_424 . V_451 =
V_444 -> V_424 . V_451 ;
} else {
memcpy ( & V_7 -> V_12 -> V_211 . V_424 . V_425 ,
& V_452 , V_445 ) ;
V_7 -> V_12 -> V_211 . V_424 . V_448 = 0 ;
V_7 -> V_12 -> V_211 . V_424 . V_449 = 0 ;
V_455 = 1 ;
}
F_98 ( & V_7 -> V_12 -> V_456 , V_157 ) ;
F_9 ( V_433 , L_62 , V_28 ,
V_444 -> V_157 ,
V_7 -> V_12 -> V_211 . V_424 . V_448 ) ;
if ( V_455 == 1 )
F_57 ( & V_7 -> V_421 ) ;
return 0 ;
}
static int F_140 (
struct V_35 * V_36 ,
struct V_457 * V_458 ,
struct V_58 * V_444 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
F_139 ( V_7 , V_444 ) ;
return 0 ;
}
static void F_127 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_1 * V_459 = V_11 -> V_460 ;
T_2 V_461 = 0 ;
T_1 V_462 = 0 ;
F_106 ( V_36 , ( T_3 * ) ( & V_461 ) ) ;
V_461 |= ( * ( T_3 * ) ( V_459 ) ) << 12 ;
switch ( V_11 -> V_246 ) {
case V_463 :
V_461 &= 0x00000FF0 ;
break;
case V_464 :
V_461 &= 0x0000000F ;
break;
case V_247 :
V_461 &= 0x00000FF7 ;
break;
case V_248 :
case V_465 :
if ( V_11 -> V_251 -> V_466 == 0 ) {
V_461 &= 0x0007F007 ;
} else {
if ( V_7 -> V_467 == V_468 )
V_461 &= 0x000FF007 ;
else
V_461 &= 0x0F81F007 ;
}
break;
default:
break;
}
V_461 &= 0x0FFFFFFF ;
if ( V_11 -> V_251 -> V_469 && V_11 -> V_251 -> V_470 )
V_461 |= 0x80000000 ;
else if ( ! V_11 -> V_251 -> V_469 &&
V_11 -> V_251 -> V_471 )
V_461 |= 0x80000000 ;
F_14 ( V_36 , V_472 + V_462 * 4 , V_461 ) ;
F_27 ( V_36 , V_473 , 1 ) ;
}
static bool F_141 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_58 * V_444 = & V_11 -> V_211 ;
int V_61 = V_11 -> V_61 ;
struct V_474 * V_475 ;
int V_476 ;
V_475 = V_11 -> V_475 [ V_11 -> V_477 ] ;
V_476 = ( V_444 -> V_420 & V_478 ) ||
( V_11 -> V_479 && V_475 && V_475 -> V_480 &&
( 0 == strcmp ( V_475 -> V_480 -> V_106 , L_63 ) ) ) ;
if ( V_476 && ( V_61 == 0 ) ) {
return false ;
} else if ( ( V_61 != 0 ) ) {
if ( ( ( V_11 -> V_481 [ 0 ] == 0xdd ) && ( ! memcmp ( & ( V_11 -> V_481 [ 14 ] ) , V_482 , 4 ) ) ) || ( ( V_11 -> V_481 [ 0 ] == 0x30 ) && ( ! memcmp ( & V_11 -> V_481 [ 10 ] , V_483 , 4 ) ) ) )
return true ;
else
return false ;
} else {
return true ;
}
return true ;
}
static bool F_142 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
return V_7 -> V_12 -> V_484 ;
}
static void F_143 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 -> V_246 == V_485 ||
V_11 -> V_246 == V_486 )
memcpy ( V_11 -> V_487 ,
V_11 -> V_488 , 16 ) ;
else
memset ( V_11 -> V_487 , 0 , 16 ) ;
}
static T_1 F_144 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_1 V_189 = 0 ;
switch ( V_7 -> V_24 ) {
case V_25 :
case V_26 :
case V_489 :
V_189 = V_485 | V_490 | V_491 ;
break;
case V_492 :
V_189 = V_493 | V_486 ;
break;
default:
V_189 = V_491 ;
break;
}
return V_189 ;
}
static void F_145 ( struct V_35 * V_36 , T_1 V_494 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_1 V_495 = F_144 ( V_36 ) ;
if ( V_494 == V_496 ||
( V_494 & V_495 ) == 0 ) {
if ( V_495 & V_485 ) {
V_494 = V_485 ;
} else if ( V_495 & V_486 ) {
V_494 = V_486 ;
} else if ( ( V_495 & V_493 ) ) {
V_494 = V_493 ;
} else if ( ( V_495 & V_490 ) ) {
V_494 = V_490 ;
} else if ( ( V_495 & V_491 ) ) {
V_494 = V_491 ;
} else {
F_9 ( V_27 ,
L_64 ,
V_28 , V_495 ) ;
V_494 = V_491 ;
}
}
#ifdef F_146
F_147 (
V_497 , V_498 -> V_499 ,
& V_497 -> V_500 . V_501 . V_502 ) ;
#endif
V_7 -> V_12 -> V_246 = V_494 ;
if ( V_494 == V_485 ||
V_494 == V_486 )
V_7 -> V_12 -> V_251 -> V_503 = 1 ;
else
V_7 -> V_12 -> V_251 -> V_503 = 0 ;
F_9 ( V_95 , L_65 , V_494 ) ;
F_143 ( V_7 ) ;
}
static void F_148 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_1 V_1 ;
V_7 -> V_504 = V_505 ;
V_7 -> V_131 = 1 ;
V_7 -> V_12 -> V_246 = V_496 ;
V_7 -> V_12 -> V_120 = V_121 ;
V_7 -> V_12 -> V_506 = 0 ;
V_7 -> V_507 = V_508 ;
V_7 -> V_509 = V_510 ;
V_7 -> V_12 -> V_511 = V_512 ;
V_7 -> V_12 -> V_178 = 110 ;
V_7 -> V_12 -> V_513 = 1 ;
V_7 -> V_514 = ( V_36 -> V_157 & V_158 ) ? 1 : 0 ;
V_7 -> V_515 = 6 ;
V_7 -> V_516 = 1 ;
V_7 -> V_517 = V_518 ;
V_7 -> V_519 = false ;
V_7 -> V_520 = false ;
V_7 -> V_521 = false ;
V_7 -> V_12 -> V_522 = 0 ;
V_7 -> V_12 -> V_211 . V_264 =
V_523 ;
V_7 -> V_12 -> V_524 = V_525 |
V_526 | V_527 |
V_528 | V_529 |
V_530 ;
V_7 -> V_12 -> V_531 = 1 ;
V_7 -> V_12 -> V_532 =
V_533 | V_534 ;
V_7 -> V_12 -> V_479 = 1 ;
V_7 -> V_12 -> V_535 = 1 ;
V_7 -> V_12 -> V_536 = NULL ;
V_7 -> V_12 -> V_537 = NULL ;
V_7 -> V_12 -> V_207 = F_99 ;
V_7 -> V_12 -> V_538 = F_59 ;
V_7 -> V_12 -> V_539 = F_126 ;
V_7 -> V_12 -> V_540 = F_93 ;
V_7 -> V_12 -> V_541 = F_91 ;
V_7 -> V_12 -> V_542 = F_92 ;
V_7 -> V_12 -> V_543 = 0 ;
V_7 -> V_12 -> V_544 = V_545 ;
V_7 -> V_12 -> F_55 = F_55 ;
V_7 -> V_12 -> V_195 = V_384 ;
V_7 -> V_12 -> V_546 = 1 ;
V_7 -> V_12 -> V_547 = V_548 ;
V_7 -> V_12 -> V_549 = F_140 ;
V_7 -> V_12 -> V_550 = F_137 ;
V_7 -> V_12 -> V_551 = F_141 ;
V_7 -> V_12 -> V_552 =
F_142 ;
V_7 -> V_12 -> V_553 = F_145 ;
V_7 -> V_12 -> V_554 = V_555 ;
V_7 -> V_556 = V_557 ;
#ifdef F_146
if ( V_558 -> V_559 ) {
V_498 -> V_560 = 7 ;
V_498 -> V_561 = 7 ;
}
#endif
V_7 -> V_560 = 0x30 ;
V_7 -> V_561 = 0x30 ;
V_7 -> V_562 = 7 ;
V_7 -> V_563 = 0 ;
V_7 -> V_564 =
( V_565 << V_566 ) |
( V_7 -> V_560 << V_567 ) |
( V_7 -> V_561 << V_568 ) |
( false ? V_569 : 0 ) ;
#ifdef F_146
if ( V_558 -> V_559 )
V_498 -> V_413 =
V_498 -> V_570 |
V_153 | V_154 |
V_571 |
V_155 | V_156 | V_161 |
V_163 | V_166 |
( ( T_2 ) 7 << V_171 ) |
( V_498 -> V_562 << V_572 ) |
( V_498 -> V_562 == 7 ? V_573 : 0 ) ;
else
#endif
V_7 -> V_413 =
V_153 | V_154 |
V_571 |
V_155 | V_156 | V_161 |
( ( T_2 ) 7 << V_171 ) |
( V_7 -> V_562 << V_169 ) |
( V_7 -> V_562 == 7 ? V_172 : 0 ) ;
V_7 -> V_574 = 0 ;
V_7 -> V_575 = F_20 ( sizeof( V_576 ) , V_47 ) ;
F_149 ( & V_7 -> V_144 ) ;
F_149 ( & V_7 -> V_177 ) ;
for ( V_1 = 0 ; V_1 < V_577 ; V_1 ++ )
F_149 ( & V_7 -> V_12 -> V_205 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_577 ; V_1 ++ )
F_149 ( & V_7 -> V_12 -> V_578 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_577 ; V_1 ++ )
F_149 ( & V_7 -> V_12 -> V_579 [ V_1 ] ) ;
V_7 -> V_132 = V_580 ;
}
static void F_150 ( struct V_6 * V_7 )
{
F_151 ( & V_7 -> V_193 ) ;
F_151 ( & V_7 -> V_581 ) ;
F_152 ( & V_7 -> V_582 ) ;
F_152 ( & V_7 -> V_431 ) ;
}
static void F_153 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
F_154 ( & V_7 -> V_114 , V_583 ) ;
F_155 ( & V_7 -> V_584 ,
V_585 ) ;
F_155 ( & V_7 -> V_586 ,
V_587 ) ;
F_155 ( & V_7 -> V_588 ,
V_589 ) ;
F_155 ( & V_7 -> V_416 ,
F_129 ) ;
F_155 ( & V_7 -> V_590 ,
V_591 ) ;
F_154 ( & V_7 -> V_421 , F_132 ) ;
F_156 ( & V_7 -> V_185 ,
( void (*) ( unsigned long ) ) V_592 ,
( unsigned long ) V_7 ) ;
}
static void F_157 ( struct V_35 * V_36 )
{
T_3 V_593 = 0 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
F_9 ( V_594 , L_66 , V_28 ) ;
F_31 ( V_36 , V_595 , & V_593 ) ;
F_9 ( V_594 ,
L_67 , V_595 , V_593 ) ;
V_7 -> V_596 =
( V_593 & V_597 ) ? V_598 : V_599 ;
F_9 ( V_594 ,
L_68 , V_28 , V_7 -> V_596 ) ;
}
static inline T_3 F_158 ( T_3 * V_40 )
{
T_3 V_241 = * V_40 ;
* V_40 = ( V_241 >> 8 ) | ( V_241 << 8 ) ;
return * V_40 ;
}
static int F_159 ( struct V_35 * V_36 )
{
T_3 V_600 = 0 ;
T_1 V_601 [ 6 ] = { 0x00 , 0xe0 , 0x4c , 0x00 , 0x00 , 0x02 } ;
T_1 V_602 = false ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_3 V_603 = 0 ;
int V_1 ;
int V_189 ;
F_9 ( V_594 , L_66 , V_28 ) ;
V_189 = F_160 ( V_36 , 0 ) ;
if ( V_189 < 0 )
return V_189 ;
V_600 = ( T_3 ) V_189 ;
F_9 ( V_594 , L_69 , V_600 ) ;
if ( V_600 != V_604 )
F_9 ( V_27 ,
L_70 ,
V_600 , V_604 ) ;
else
V_602 = true ;
if ( V_602 ) {
V_603 = F_160 ( V_36 , V_605 >> 1 ) ;
V_189 = F_160 ( V_36 , V_605 >> 1 ) ;
if ( V_189 < 0 )
return V_189 ;
V_603 = ( T_3 ) V_189 ;
V_7 -> V_606 = F_158 ( & V_603 ) ;
V_189 = F_160 ( V_36 , V_607 >> 1 ) ;
if ( V_189 < 0 )
return V_189 ;
V_7 -> V_608 = ( T_3 ) V_189 ;
V_189 = F_160 ( V_36 , V_609 >> 1 ) ;
if ( V_189 < 0 )
return V_189 ;
V_603 = ( T_3 ) V_189 ;
V_7 -> V_610 = ( V_603 & 0xff00 ) >> 8 ;
V_7 -> V_611 = true ;
V_189 = F_160 ( V_36 , ( V_612 >> 1 ) ) >> 8 ;
if ( V_189 < 0 )
return V_189 ;
V_7 -> V_613 = ( T_3 ) V_189 ;
} else {
V_7 -> V_606 = 0 ;
V_7 -> V_608 = 0 ;
V_7 -> V_614 = V_615 ;
V_7 -> V_610 = 0 ;
V_7 -> V_613 = 0 ;
}
F_9 ( V_594 ,
L_71 ,
V_7 -> V_606 , V_7 -> V_608 , V_7 -> V_613 ,
V_7 -> V_610 ) ;
V_7 -> V_29 = V_7 -> V_610 ;
if ( V_602 ) {
int V_1 ;
for ( V_1 = 0 ; V_1 < 6 ; V_1 += 2 ) {
V_189 = F_160 ( V_36 , ( T_3 ) ( ( V_616 + V_1 ) >> 1 ) ) ;
if ( V_189 < 0 )
return V_189 ;
* ( T_3 * ) ( & V_36 -> V_617 [ V_1 ] ) = ( T_3 ) V_189 ;
}
} else {
memcpy ( V_36 -> V_617 , V_601 , 6 ) ;
}
F_9 ( V_594 , L_72 , V_36 -> V_617 ) ;
V_7 -> V_467 = V_618 ;
V_7 -> V_24 = V_26 ;
if ( V_7 -> V_614 == ( T_1 ) V_619 ) {
if ( V_602 ) {
V_189 = F_160 ( V_36 , ( V_620 >> 1 ) ) ;
if ( V_189 < 0 )
return V_189 ;
V_7 -> V_621 = ( ( T_3 ) V_189 & 0xff00 ) >> 8 ;
} else
V_7 -> V_621 = V_622 ;
F_9 ( V_594 , L_73 , V_7 -> V_621 ) ;
if ( V_602 ) {
V_189 = F_160 ( V_36 , ( V_623 >> 1 ) ) ;
if ( V_189 < 0 )
return V_189 ;
V_7 -> V_624 = ( T_1 ) ( ( T_3 ) V_189 & 0x00ff ) ;
} else
V_7 -> V_624 = V_625 ;
F_9 ( V_594 , L_74 , V_7 -> V_624 ) ;
V_7 -> V_626 = V_7 -> V_624 * 100 ;
if ( V_602 ) {
V_189 = F_160 ( V_36 , ( V_627 >> 1 ) ) ;
if ( V_189 < 0 )
return V_189 ;
V_7 -> V_628 = ( ( T_3 ) V_189 & 0x0f00 ) >> 8 ;
} else
V_7 -> V_628 = V_629 ;
F_9 ( V_594 , L_75 , V_7 -> V_628 ) ;
if ( V_602 ) {
V_189 = F_160 ( V_36 , ( V_630 >> 1 ) ) ;
if ( V_189 < 0 )
return V_189 ;
V_7 -> V_631 = ( T_3 ) V_189 & 0x0f ;
} else
V_7 -> V_631 = V_632 ;
F_9 ( V_594 , L_76 , V_7 -> V_631 ) ;
if ( V_602 ) {
V_189 = F_160 ( V_36 , ( V_633 >> 1 ) ) ;
if ( V_189 < 0 )
return V_189 ;
V_7 -> V_634 = ( ( T_3 ) V_189 & 0xff00 ) >> 8 ;
} else
V_7 -> V_634 = 1 ;
F_9 ( V_594 , L_77 , V_7 -> V_634 ) ;
if ( V_7 -> V_634 == 0 ) {
int V_1 ;
if ( V_602 ) {
V_189 = F_160 ( V_36 , ( V_635 >> 1 ) ) ;
if ( V_189 < 0 )
return V_189 ;
V_7 -> V_636 = ( ( T_3 ) V_189 & 0xff ) >> 8 ;
} else
V_7 -> V_636 = 0x10 ;
F_9 ( V_594 , L_78 , V_7 -> V_636 ) ;
for ( V_1 = 0 ; V_1 < 3 ; V_1 ++ ) {
if ( V_602 ) {
V_189 = F_160 ( V_36 , ( V_637 + V_1 ) >> 1 ) ;
if ( V_189 < 0 )
return V_189 ;
if ( ( ( V_637 + V_1 ) % 2 ) == 0 )
V_603 = ( T_3 ) V_189 & 0x00ff ;
else
V_603 = ( ( T_3 ) V_189 & 0xff00 ) >> 8 ;
} else {
V_603 = 0x10 ;
}
V_7 -> V_638 [ V_1 ] = ( T_1 ) V_603 ;
F_9 ( V_594 , L_79 , V_1 , V_7 -> V_636 ) ;
}
} else if ( V_7 -> V_634 == 1 ) {
if ( V_602 ) {
V_189 = F_160 ( V_36 , V_639 >> 1 ) ;
if ( V_189 < 0 )
return V_189 ;
V_603 = ( ( T_3 ) V_189 & 0xff00 ) >> 8 ;
} else {
V_603 = 0x10 ;
}
V_7 -> V_640 [ 0 ] = ( T_1 ) V_603 ;
if ( V_602 ) {
V_189 = F_160 ( V_36 , ( V_639 + 2 ) >> 1 ) ;
if ( V_189 < 0 )
return V_189 ;
V_603 = ( T_3 ) V_189 ;
} else
V_603 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_640 [ 1 ] ) ) = V_603 ;
if ( V_602 )
V_603 = F_160 ( V_36 ,
V_641 >> 1 ) ;
else
V_603 = 0x1010 ;
* ( ( T_3 * ) ( & V_7 -> V_638 [ 0 ] ) ) = V_603 ;
if ( V_602 )
V_603 = F_160 ( V_36 , ( V_641 + 2 ) >> 1 ) ;
else
V_603 = 0x10 ;
V_7 -> V_638 [ 2 ] = ( T_1 ) V_603 ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ ) {
if ( V_1 <= 3 )
V_7 -> V_642 [ V_1 ] = V_7 -> V_638 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_642 [ V_1 ] = V_7 -> V_638 [ 1 ] ;
else
V_7 -> V_642 [ V_1 ] = V_7 -> V_638 [ 2 ] ;
}
for ( V_1 = 0 ; V_1 < 14 ; V_1 ++ ) {
if ( V_7 -> V_634 == 0 ) {
if ( V_1 <= 3 )
V_7 -> V_643 [ V_1 ] = V_7 -> V_638 [ 0 ] + ( V_7 -> V_636 - V_7 -> V_638 [ 1 ] ) ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_643 [ V_1 ] = V_7 -> V_636 ;
else
V_7 -> V_643 [ V_1 ] = V_7 -> V_638 [ 2 ] + ( V_7 -> V_636 - V_7 -> V_638 [ 1 ] ) ;
} else if ( V_7 -> V_634 == 1 ) {
if ( V_1 <= 3 )
V_7 -> V_643 [ V_1 ] = V_7 -> V_640 [ 0 ] ;
else if ( V_1 >= 4 && V_1 <= 9 )
V_7 -> V_643 [ V_1 ] = V_7 -> V_640 [ 1 ] ;
else
V_7 -> V_643 [ V_1 ] = V_7 -> V_640 [ 2 ] ;
}
}
V_7 -> V_644 = V_7 -> V_628 ;
V_7 -> V_645 [ 0 ] = ( V_7 -> V_621 & 0xf ) ;
V_7 -> V_645 [ 1 ] =
( V_7 -> V_621 & 0xf0 ) >> 4 ;
V_7 -> V_646 = V_7 -> V_631 ;
V_7 -> V_647 [ 0 ] = V_7 -> V_624 ;
}
switch ( V_7 -> V_613 ) {
case V_648 :
V_7 -> V_649 = V_650 ;
break;
case V_651 :
V_7 -> V_649 = V_652 ;
break;
default:
V_7 -> V_649 = V_653 ;
break;
}
switch ( V_7 -> V_649 ) {
case V_650 :
V_7 -> V_654 = V_655 ;
break;
case V_652 :
V_7 -> V_654 = V_656 ;
break;
default:
V_7 -> V_654 = V_657 ;
break;
}
if ( V_7 -> V_467 == V_468 )
F_9 ( V_594 , L_80 ) ;
else
F_9 ( V_594 , L_81 ) ;
F_161 ( V_36 ) ;
F_9 ( V_594 , L_82 , V_28 ) ;
return 0 ;
}
static short F_162 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
if ( V_7 -> V_29 > V_33 ) {
F_24 ( V_36 ,
L_83 ) ;
V_7 -> V_29 = 0 ;
}
F_9 ( V_95 , L_84 , V_7 -> V_29 ) ;
F_7 ( V_7 -> V_29 , V_7 ) ;
return 0 ;
}
static short F_163 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_181 ;
memset ( & ( V_7 -> V_67 ) , 0 , sizeof( struct V_658 ) ) ;
memset ( V_7 -> V_659 , 0 , 9 ) ;
#ifdef F_164
{
int V_1 = 0 ;
T_1 V_660 [] = { 3 , 2 , 1 , 0 , 4 , 8 , 7 , 6 , 5 } ;
memcpy ( V_7 -> V_659 , V_660 , 9 ) ;
}
#else
{
T_1 V_660 [] = { 3 , 2 , 1 , 0 , 4 , 4 , 0 , 4 , 4 } ;
memcpy ( V_7 -> V_659 , V_660 , 9 ) ;
}
#endif
F_148 ( V_36 ) ;
F_150 ( V_7 ) ;
F_153 ( V_36 ) ;
F_157 ( V_36 ) ;
V_181 = F_159 ( V_36 ) ;
if ( V_181 ) {
F_73 ( L_85 ) ;
F_23 ( V_7 -> V_575 ) ;
V_7 -> V_575 = NULL ;
F_165 ( V_36 ) ;
return V_181 ;
}
F_162 ( V_36 ) ;
F_166 ( V_36 ) ;
F_167 ( & V_7 -> V_661 , V_662 ,
( unsigned long ) V_36 ) ;
if ( F_120 ( V_36 ) != 0 ) {
F_73 ( L_86 ) ;
return - V_48 ;
}
return 0 ;
}
static void F_168 ( struct V_35 * V_36 )
{
T_2 V_663 = 0 , V_664 = 0 ;
T_1 V_665 = 0 , V_666 = 0 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_2 V_461 = 0 ;
switch ( V_7 -> V_12 -> V_246 ) {
case V_491 :
V_665 = V_667 ;
V_663 = V_668 ;
V_664 = V_668 ;
break;
case V_493 :
V_665 = V_669 | V_667 ;
V_663 = V_670 ;
V_664 = V_670 ;
break;
case V_490 :
V_665 = V_667 ;
V_663 = V_668 | V_670 ;
V_664 = V_668 | V_670 ;
break;
case V_496 :
#ifdef F_146
if ( V_558 -> V_559 ) {
V_665 = V_667 ;
V_663 = V_668 | V_670 ;
V_664 = V_668 | V_670 ;
} else
#endif
{
V_665 = V_667 ;
V_663 = V_668 | V_670 |
V_671 | V_672 ;
V_664 = V_668 | V_670 ;
}
break;
case V_485 :
V_665 = V_667 ;
V_663 = V_668 | V_670 |
V_671 | V_672 ;
V_664 = V_668 | V_670 ;
break;
case V_486 :
V_665 = V_669 ;
V_663 = V_670 | V_671 |
V_672 ;
V_664 = V_670 ;
break;
}
F_27 ( V_36 , V_673 , V_665 ) ;
V_461 = V_663 ;
if ( V_7 -> V_467 == V_468 )
V_461 &= ~ ( V_672 ) ;
F_14 ( V_36 , V_472 , V_461 ) ;
F_27 ( V_36 , V_473 , 1 ) ;
F_29 ( V_36 , 0x313 , & V_666 ) ;
V_664 = ( ( V_666 ) << 24 ) | ( V_664 & 0x00ffffff ) ;
F_14 ( V_36 , V_245 , V_664 ) ;
F_28 ( V_36 , V_674 ,
V_7 -> V_560 << V_675 |
V_7 -> V_561 << V_676 ) ;
}
static bool F_169 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_2 V_677 = 0 ;
bool V_678 = true ;
T_1 V_679 = 0x0 ;
T_1 V_241 ;
F_9 ( V_95 , L_87 , V_28 ) ;
V_7 -> V_680 = V_681 ;
F_18 ( V_36 , 0x5f , 0x80 ) ;
F_60 ( 50 ) ;
F_18 ( V_36 , 0x5f , 0xf0 ) ;
F_18 ( V_36 , 0x5d , 0x00 ) ;
F_18 ( V_36 , 0x5e , 0x80 ) ;
F_27 ( V_36 , 0x17 , 0x37 ) ;
F_60 ( 10 ) ;
V_7 -> V_575 -> V_682 = V_683 ;
F_17 ( V_36 , V_684 , & V_677 ) ;
if ( V_7 -> V_575 -> V_682 == V_683 )
V_677 |= V_685 ;
else if ( V_7 -> V_575 -> V_682 == V_686 )
V_677 |= V_687 ;
else
F_9 ( V_27 ,
L_88 ,
V_28 , V_7 -> V_575 -> V_682 ) ;
F_14 ( V_36 , V_684 , V_677 ) ;
F_170 ( V_36 ) ;
V_7 -> V_688 = V_689 ;
F_17 ( V_36 , V_684 , & V_677 ) ;
if ( V_7 -> V_688 == V_689 )
V_677 = ( V_677 & V_690 ) |
V_691 ;
else if ( V_7 -> V_688 == V_692 )
V_677 |= V_693 ;
else
F_9 ( V_27 ,
L_89 ,
V_28 , V_7 -> V_688 ) ;
F_14 ( V_36 , V_684 , V_677 ) ;
F_171 ( 500 ) ;
F_25 ( V_36 , 0x5f , & V_241 ) ;
F_18 ( V_36 , 0x5f , V_241 | 0x20 ) ;
F_168 ( V_36 ) ;
F_27 ( V_36 , V_174 , V_176 | V_175 ) ;
F_14 ( V_36 , V_694 , ( ( T_2 * ) V_36 -> V_617 ) [ 0 ] ) ;
F_28 ( V_36 , V_695 , ( ( T_3 * ) ( V_36 -> V_617 + 4 ) ) [ 0 ] ) ;
F_14 ( V_36 , V_151 , V_7 -> V_413 ) ;
F_14 ( V_36 , V_696 ,
V_697 << V_698 |
V_699 << V_700 |
V_701 << V_702 |
V_703 << V_704 ) ;
F_14 ( V_36 , V_705 ,
V_706 << V_707 |
V_708 << V_709 ) ;
F_14 ( V_36 , V_710 ,
V_711 |
V_712 << V_713 ) ;
F_14 ( V_36 , V_472 + 4 * 7 , ( V_670 | V_668 ) ) ;
F_27 ( V_36 , V_714 , 0x30 ) ;
if ( V_7 -> V_517 == V_518 )
F_145 ( V_36 , V_7 -> V_12 -> V_246 ) ;
if ( V_7 -> V_517 == V_518 ) {
F_12 ( V_36 ) ;
V_679 |= V_715 ;
V_679 |= V_716 ;
V_679 |= V_717 ;
F_27 ( V_36 , V_718 , V_679 ) ;
}
F_28 ( V_36 , V_261 , 2 ) ;
F_28 ( V_36 , V_263 , 100 ) ;
#define F_172 0x005e4332
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_434 ; V_1 ++ )
F_14 ( V_36 , V_442 [ V_1 ] , F_172 ) ;
}
F_173 ( V_36 ) ;
if ( V_7 -> V_614 == ( T_1 ) V_619 ) {
F_174 ( V_36 ) ;
F_175 ( V_36 , V_7 -> V_131 ) ;
}
V_678 = F_176 ( V_36 ) ;
if ( ! V_678 ) {
F_9 ( V_27 , L_90 ,
V_28 ) ;
return V_678 ;
}
F_9 ( V_95 , L_91 , V_28 ) ;
#ifdef F_146
if ( V_558 -> V_517 == V_518 ) {
if ( V_719 -> V_720 ) {
F_9 ( ( V_95 | V_721 ) , V_722 ,
( L_92 ) ) ;
F_177 ( V_558 , V_723 , V_724 ) ;
for ( V_725 = 0 ; V_725 < V_498 -> V_726 ; V_725 ++ )
F_178 ( V_558 ,
( V_727 ) V_725 ,
0x4 , 0xC00 , 0x0 ) ;
} else if ( V_719 -> V_728 > V_729 ) {
F_9 ( ( V_95 | V_721 ) , V_722 ,
( L_93 ,
V_719 -> V_728 ) ) ;
F_177 ( V_558 ,
V_723 ,
V_719 -> V_728 ) ;
} else {
V_498 -> V_730 = V_731 ;
V_719 -> V_728 = 0 ;
F_9 ( ( V_95 | V_721 ) , V_722 ,
( L_94 ) ) ;
}
} else {
if ( V_498 -> V_730 == V_723 ) {
F_177 ( V_558 ,
V_723 ,
V_719 -> V_728 ) ;
for ( V_725 = 0 ; V_725 < V_498 -> V_726 ; V_725 ++ )
F_178 ( V_558 ,
( V_727 ) V_725 ,
0x4 , 0xC00 , 0x0 ) ;
}
}
#endif
if ( V_7 -> V_517 == V_518 ) {
F_179 ( V_36 ) ;
F_9 ( V_95 , L_95 , V_28 ) ;
}
if ( V_7 -> V_12 -> V_522 )
V_7 -> V_680 = V_732 ;
else
V_7 -> V_680 = V_681 ;
F_180 ( V_36 ) ;
F_181 ( V_36 , V_733 , V_734 , 0x1 ) ;
F_181 ( V_36 , V_733 , V_735 , 0x1 ) ;
if ( V_7 -> V_517 == V_518 ) {
T_1 V_736 ;
F_29 ( V_36 , 0x301 , & V_736 ) ;
if ( V_736 == 0x03 ) {
V_7 -> V_737 = true ;
F_9 ( V_738 , L_96 ) ;
} else {
V_7 -> V_737 = false ;
F_9 ( V_738 , L_97 ) ;
}
F_182 ( V_36 ) ;
if ( V_7 -> V_737 ) {
T_2 V_1 , V_739 ;
T_2 V_740 = F_183 ( V_36 ,
V_741 ,
V_742 ) ;
for ( V_1 = 0 ; V_1 < V_743 ; V_1 ++ ) {
if ( V_740 == V_7 -> V_744 [ V_1 ] . V_745 ) {
V_7 -> V_746 = ( T_1 ) V_1 ;
V_7 -> V_747 =
( T_1 ) V_1 ;
V_7 -> V_748 =
V_7 -> V_746 ;
break;
}
}
V_739 = F_183 ( V_36 ,
V_749 ,
V_750 ) ;
for ( V_1 = 0 ; V_1 < V_751 ; V_1 ++ ) {
if ( V_739 == V_7 -> V_752 [ V_1 ] . V_753 [ 0 ] ) {
V_7 -> V_754 = ( T_1 ) V_1 ;
break;
}
}
V_7 -> V_755 = 0 ;
V_7 -> V_756 = 0 ;
V_7 -> V_757 =
V_7 -> V_754 ;
}
}
F_27 ( V_36 , 0x87 , 0x0 ) ;
return V_678 ;
}
static struct V_758 * F_184 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
return & V_7 -> V_12 -> V_67 ;
}
static bool F_185 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_3 V_759 ;
bool V_760 = false ;
F_30 ( V_36 , 0x128 , & V_759 ) ;
F_9 ( V_761 ,
L_98 , V_28 ,
V_759 , V_7 -> V_762 ) ;
if ( V_7 -> V_762 == V_759 )
V_760 = true ;
V_7 -> V_762 = V_759 ;
return V_760 ;
}
static T_8 F_186 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_1 V_282 ;
bool V_763 = false ;
for ( V_282 = 0 ; V_282 <= V_204 ; V_282 ++ ) {
if ( V_282 == V_192 )
continue;
if ( ( F_63 ( & V_7 -> V_12 -> V_205 [ V_282 ] ) == 0 ) && ( F_63 ( & V_7 -> V_12 -> V_578 [ V_282 ] ) == 0 ) )
continue;
V_763 = true ;
}
if ( V_763 ) {
if ( F_185 ( V_36 ) ) {
F_9 ( V_761 ,
L_99 ) ;
return V_764 ;
}
}
return V_518 ;
}
static bool F_187 ( struct V_35 * V_36 )
{
T_3 V_765 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
bool V_760 = false ;
static T_1 V_766 ;
F_30 ( V_36 , 0x130 , & V_765 ) ;
F_9 ( V_761 ,
L_100 , V_28 ,
V_765 , V_7 -> V_767 ) ;
V_766 ++ ;
if ( V_7 -> V_768 >= ( V_769 + 5 ) ) {
V_766 = 0 ;
} else if ( V_7 -> V_768 < ( V_769 + 5 ) &&
( ( V_7 -> V_376 != V_770 && V_7 -> V_768 >= V_771 ) ||
( V_7 -> V_376 == V_770 && V_7 -> V_768 >= V_772 ) ) ) {
if ( V_766 < 2 )
return V_760 ;
V_766 = 0 ;
} else if ( ( ( V_7 -> V_376 != V_770 && V_7 -> V_768 < V_771 ) ||
( V_7 -> V_376 == V_770 && V_7 -> V_768 < V_772 ) ) &&
V_7 -> V_768 >= V_773 ) {
if ( V_766 < 4 )
return V_760 ;
V_766 = 0 ;
} else {
if ( V_766 < 8 )
return V_760 ;
V_766 = 0 ;
}
if ( V_7 -> V_767 == V_765 )
V_760 = true ;
V_7 -> V_767 = V_765 ;
return V_760 ;
}
static T_8 F_188 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
bool V_774 = false ;
if ( V_7 -> V_516 > 1 )
V_774 = true ;
if ( V_774 ) {
if ( F_187 ( V_36 ) ) {
F_9 ( V_761 , L_101 ) ;
return V_764 ;
}
}
return V_518 ;
}
static T_8 F_189 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_8 V_775 = V_518 ;
T_8 V_776 = V_518 ;
T_9 V_777 ;
V_777 = V_7 -> V_12 -> V_730 ;
V_775 = F_186 ( V_36 ) ;
if ( V_777 != V_723 ||
( V_7 -> V_12 -> V_120 != V_124 ) ) {
V_776 = F_188 ( V_36 ) ;
}
if ( V_775 == V_778 ||
V_776 == V_778 ) {
return V_778 ;
} else if ( V_775 == V_764 ||
V_776 == V_764 ) {
F_9 ( V_761 , L_102 , V_28 ) ;
return V_764 ;
} else {
return V_518 ;
}
}
static void F_190 ( struct V_35 * V_36 )
{
T_1 V_779 = 0 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_1 * V_780 = V_7 -> V_12 -> V_211 . V_260 ;
static T_1 V_781 [ 4 ] [ 6 ] = {
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
static T_1 V_782 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
F_9 ( V_783 , L_103 ) ;
if ( ( V_7 -> V_12 -> V_391 == V_392 ) ||
( V_7 -> V_12 -> V_391 == V_393 ) ) {
for ( V_779 = 0 ; V_779 < 4 ; V_779 ++ ) {
V_780 = V_781 [ V_779 ] ;
F_191 ( V_36 , V_779 , V_779 ,
V_7 -> V_12 -> V_391 ,
V_780 , 0 , NULL ) ;
}
} else if ( V_7 -> V_12 -> V_391 == V_394 ) {
if ( V_7 -> V_12 -> V_120 == V_124 )
F_191 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_391 ,
( T_1 * ) V_36 -> V_617 , 0 , NULL ) ;
else
F_191 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_391 ,
V_780 , 0 , NULL ) ;
} else if ( V_7 -> V_12 -> V_391 == V_395 ) {
if ( V_7 -> V_12 -> V_120 == V_124 )
F_191 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_391 ,
( T_1 * ) V_36 -> V_617 , 0 , NULL ) ;
else
F_191 ( V_36 , 4 , 0 , V_7 -> V_12 -> V_391 ,
V_780 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_784 == V_394 ) {
V_780 = V_782 ;
for ( V_779 = 1 ; V_779 < 4 ; V_779 ++ ) {
F_191 ( V_36 , V_779 , V_779 ,
V_7 -> V_12 -> V_784 ,
V_780 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_120 == V_124 )
F_191 ( V_36 , 0 , 0 , V_7 -> V_12 -> V_784 ,
V_781 [ 0 ] , 0 , NULL ) ;
} else if ( V_7 -> V_12 -> V_784 == V_395 ) {
V_780 = V_782 ;
for ( V_779 = 1 ; V_779 < 4 ; V_779 ++ ) {
F_191 ( V_36 , V_779 , V_779 ,
V_7 -> V_12 -> V_784 ,
V_780 , 0 , NULL ) ;
}
if ( V_7 -> V_12 -> V_120 == V_124 )
F_191 ( V_36 , 0 , 0 , V_7 -> V_12 -> V_784 ,
V_781 [ 0 ] , 0 , NULL ) ;
}
}
static void F_192 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
T_1 V_785 = 0 ;
int V_786 = 0 ;
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_7 -> V_517 == V_518 ) {
V_787:
F_9 ( V_761 , L_104 ) ;
V_7 -> V_517 = V_764 ;
F_133 ( & V_7 -> V_582 ) ;
if ( V_7 -> V_182 == 0 ) {
F_9 ( V_27 ,
L_105 ,
V_28 ) ;
F_135 ( & V_7 -> V_582 ) ;
return;
}
V_7 -> V_182 = 0 ;
F_9 ( V_761 ,
L_106 ,
V_28 ) ;
F_76 ( V_36 ) ;
F_193 ( V_7 ) ;
F_194 ( V_36 ) ;
F_195 ( & V_7 -> V_661 ) ;
V_11 -> V_788 = 1 ;
if ( V_11 -> V_118 == V_119 ) {
F_133 ( & V_11 -> V_582 ) ;
F_119 ( V_36 , L_107 ) ;
F_196 ( V_7 -> V_12 ) ;
F_195 ( & V_11 -> V_789 ) ;
F_197 ( & V_11 -> V_790 ) ;
F_198 ( V_11 ) ;
F_199 ( V_36 ) ;
F_135 ( & V_11 -> V_582 ) ;
} else {
F_119 ( V_36 , L_108 ) ;
F_200 ( V_7 -> V_12 ) ;
}
F_135 ( & V_7 -> V_582 ) ;
F_9 ( V_761 ,
L_109 ,
V_28 ) ;
F_9 ( V_761 ,
L_110 ,
V_28 ) ;
V_786 = F_201 ( V_36 ) ;
F_9 ( V_761 ,
L_111 ,
V_28 ) ;
if ( V_786 == - V_791 ) {
if ( V_785 < 3 ) {
V_785 ++ ;
goto V_787;
} else {
F_9 ( V_27 ,
L_112 ,
V_28 ) ;
}
}
V_11 -> V_792 = 1 ;
F_128 ( V_36 ) ;
if ( V_11 -> V_118 == V_119 &&
V_11 -> V_120 == V_121 ) {
V_11 -> V_538 ( V_11 -> V_36 ,
V_11 -> V_211 . V_793 ) ;
F_202 ( V_11 -> V_794 , & V_11 -> V_795 ) ;
} else if ( V_11 -> V_118 == V_119 &&
V_11 -> V_120 == V_124 ) {
V_11 -> V_538 ( V_11 -> V_36 ,
V_11 -> V_211 . V_793 ) ;
V_11 -> V_539 ( V_11 -> V_36 ) ;
F_203 ( V_11 ) ;
if ( V_11 -> V_542 )
V_11 -> V_542 ( V_11 -> V_36 ) ;
F_204 ( V_11 -> V_36 ) ;
}
F_190 ( V_36 ) ;
V_7 -> V_517 = V_518 ;
V_7 -> V_796 ++ ;
V_7 -> V_519 = false ;
V_7 -> V_797 = false ;
F_27 ( V_36 , V_473 , 1 ) ;
F_9 ( V_761 ,
L_113 ,
V_7 -> V_796 ) ;
}
}
static void F_205 ( struct V_6 * V_7 , T_2 * V_798 ,
T_2 * V_799 )
{
T_3 V_800 ;
T_1 V_1 ;
* V_798 = 0 ;
* V_799 = 0 ;
V_800 = ( V_7 -> V_12 -> V_199 . V_800 ++ ) %
( V_7 -> V_12 -> V_199 . V_801 ) ;
V_7 -> V_12 -> V_199 . V_802 [ V_800 ] =
V_7 -> V_12 -> V_199 . V_803 ;
V_7 -> V_12 -> V_199 . V_804 [ V_800 ] =
V_7 -> V_12 -> V_199 . V_805 ;
for ( V_1 = 0 ; V_1 < V_7 -> V_12 -> V_199 . V_801 ; V_1 ++ ) {
* V_798 += V_7 -> V_12 -> V_199 . V_802 [ V_1 ] ;
* V_799 += V_7 -> V_12 -> V_199 . V_804 [ V_1 ] ;
}
}
static void V_585 ( struct V_414 * V_415 )
{
struct V_806 * V_807 = F_206 ( V_415 ) ;
struct V_6 * V_7 = F_130 ( V_807 ,
struct V_6 , V_584 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_8 V_808 = V_518 ;
static T_1 V_809 ;
bool V_810 = false ;
T_2 V_798 = 0 ;
T_2 V_799 = 0 ;
if ( ! V_7 -> V_182 )
return;
F_207 ( V_36 ) ;
if ( V_11 -> V_118 == V_119 ) {
if ( V_11 -> V_199 . V_811 > 666 ||
V_11 -> V_199 . V_200 > 666 ) {
V_810 = true ;
}
V_11 -> V_199 . V_811 = 0 ;
V_11 -> V_199 . V_200 = 0 ;
V_11 -> V_199 . V_810 = V_810 ;
}
if ( V_7 -> V_12 -> V_118 == V_119 &&
V_7 -> V_12 -> V_120 == V_121 ) {
F_205 ( V_7 , & V_798 , & V_799 ) ;
if ( ( V_798 + V_799 ) == 0 ) {
#ifdef F_208
if ( V_777 == V_723 )
F_9 ( V_27 , L_114 , V_28 ) ;
#endif
F_119 ( V_36 ,
L_115 ,
V_28 ) ;
V_7 -> V_12 -> V_118 = V_812 ;
F_209 ( V_7 -> V_12 ) ;
F_210 ( V_7 -> V_12 ,
V_7 -> V_12 -> V_211 . V_260 ) ;
V_7 -> V_12 -> V_539 ( V_36 ) ;
F_202 ( V_7 -> V_12 -> V_794 ,
& V_7 -> V_12 -> V_813 ) ;
}
}
V_7 -> V_12 -> V_199 . V_803 = 0 ;
V_7 -> V_12 -> V_199 . V_805 = 0 ;
if ( V_809 ++ >= 3 ) {
V_808 = F_189 ( V_36 ) ;
V_809 = 3 ;
}
if ( ( V_7 -> V_521 ) || ( V_7 -> V_517 == V_518 &&
( V_7 -> V_519 ||
( ! V_7 -> V_520 && V_808 == V_764 ) ) ) ) {
F_9 ( V_761 ,
L_116 ,
V_28 , V_7 -> V_521 , V_7 -> V_517 ,
V_7 -> V_519 ,
V_7 -> V_520 , V_808 ) ;
F_192 ( V_36 ) ;
}
V_7 -> V_521 = false ;
V_7 -> V_519 = false ;
V_7 -> V_797 = false ;
F_9 ( V_814 , L_117 ) ;
}
static void V_662 ( unsigned long V_40 )
{
struct V_6 * V_7 = F_19 ( (struct V_35 * ) V_40 ) ;
F_138 ( & V_7 -> V_584 , 0 ) ;
F_211 ( & V_7 -> V_661 ,
V_815 + F_212 ( V_816 ) ) ;
}
static int F_201 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_678 = 0 ;
V_7 -> V_182 = 1 ;
V_7 -> V_12 -> V_506 = 1 ;
F_9 ( V_95 , L_118 ) ;
V_678 = F_169 ( V_36 ) ;
if ( ! V_678 ) {
F_9 ( V_27 , L_119 ,
V_28 ) ;
V_7 -> V_182 = V_7 -> V_12 -> V_506 = 0 ;
return - V_791 ;
}
F_9 ( V_95 , L_120 ) ;
F_74 ( V_36 ) ;
if ( V_7 -> V_12 -> V_118 != V_119 )
F_213 ( V_7 -> V_12 ) ;
F_214 ( V_7 -> V_12 ) ;
V_662 ( ( unsigned long ) V_36 ) ;
if ( ! F_40 ( V_36 ) )
F_215 ( V_36 ) ;
else
F_216 ( V_36 ) ;
return 0 ;
}
static int F_217 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_189 ;
F_133 ( & V_7 -> V_582 ) ;
V_189 = F_218 ( V_36 ) ;
F_135 ( & V_7 -> V_582 ) ;
return V_189 ;
}
int F_218 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
if ( V_7 -> V_182 == 1 )
return - 1 ;
return F_201 ( V_36 ) ;
}
static int F_219 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_189 ;
F_133 ( & V_7 -> V_582 ) ;
V_189 = F_220 ( V_36 ) ;
F_135 ( & V_7 -> V_582 ) ;
return V_189 ;
}
int F_220 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_1 ;
if ( V_7 -> V_182 == 0 )
return - 1 ;
V_7 -> V_182 = 0 ;
V_7 -> V_12 -> V_506 = 0 ;
F_9 ( V_817 , L_121 , V_28 ) ;
if ( ! F_40 ( V_36 ) )
F_221 ( V_36 ) ;
F_76 ( V_36 ) ;
for ( V_1 = 0 ; V_1 < V_577 ; V_1 ++ )
F_80 ( & V_7 -> V_12 -> V_205 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_577 ; V_1 ++ )
F_80 ( & V_7 -> V_12 -> V_578 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < V_577 ; V_1 ++ )
F_80 ( & V_7 -> V_12 -> V_579 [ V_1 ] ) ;
F_193 ( V_7 ) ;
F_194 ( V_36 ) ;
F_195 ( & V_7 -> V_661 ) ;
F_200 ( V_7 -> V_12 ) ;
memset ( & V_7 -> V_12 -> V_211 , 0 ,
F_222 ( struct V_58 , V_818 ) ) ;
F_9 ( V_817 , L_122 , V_28 ) ;
return 0 ;
}
void F_223 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
int V_786 = 0 ;
if ( V_7 -> V_182 == 0 )
return;
V_7 -> V_182 = 0 ;
F_193 ( V_7 ) ;
F_195 ( & V_7 -> V_661 ) ;
F_200 ( V_7 -> V_12 ) ;
F_76 ( V_36 ) ;
V_786 = F_201 ( V_36 ) ;
}
static void V_583 ( struct V_414 * V_415 )
{
struct V_6 * V_7 = F_130 ( V_415 , struct V_6 ,
V_114 ) ;
struct V_35 * V_36 = V_7 -> V_12 -> V_36 ;
F_133 ( & V_7 -> V_582 ) ;
F_223 ( V_36 ) ;
F_135 ( & V_7 -> V_582 ) ;
}
static void F_224 ( struct V_35 * V_36 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
short V_514 ;
V_514 = ( V_36 -> V_157 & V_158 ) ? 1 : 0 ;
if ( V_514 != V_7 -> V_514 )
V_7 -> V_514 = V_514 ;
}
static int F_225 ( struct V_35 * V_36 , void * V_819 )
{
struct V_6 * V_7 = F_19 ( V_36 ) ;
struct V_820 * V_39 = V_819 ;
F_133 ( & V_7 -> V_582 ) ;
F_226 ( V_36 -> V_617 , V_39 -> V_821 ) ;
F_57 ( & V_7 -> V_114 ) ;
F_135 ( & V_7 -> V_582 ) ;
return 0 ;
}
static int F_227 ( struct V_35 * V_36 , struct V_822 * V_823 , int V_173 )
{
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_824 * V_825 = (struct V_824 * ) V_823 ;
int V_189 = - 1 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_2 V_826 [ 4 ] ;
T_1 V_827 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_828 * V_829 = & V_825 -> V_830 . V_40 ;
struct V_831 * V_832 = NULL ;
F_133 ( & V_7 -> V_582 ) ;
if ( V_829 -> V_833 < sizeof( struct V_831 ) || ! V_829 -> V_834 ) {
V_189 = - V_835 ;
goto V_836;
}
V_832 = F_228 ( V_829 -> V_834 , V_829 -> V_833 ) ;
if ( F_229 ( V_832 ) ) {
V_189 = F_230 ( V_832 ) ;
goto V_836;
}
switch ( V_173 ) {
case V_837 :
if ( V_832 -> V_173 == V_838 ) {
if ( V_832 -> V_830 . V_475 . V_839 ) {
if ( strcmp ( V_832 -> V_830 . V_475 . V_840 , L_123 ) == 0 ) {
V_11 -> V_391 = V_395 ;
} else if ( strcmp ( V_832 -> V_830 . V_475 . V_840 , L_124 ) == 0 ) {
V_11 -> V_391 = V_394 ;
} else if ( strcmp ( V_832 -> V_830 . V_475 . V_840 , L_63 ) == 0 ) {
if ( V_832 -> V_830 . V_475 . V_841 == 13 )
V_11 -> V_391 = V_393 ;
else if ( V_832 -> V_830 . V_475 . V_841 == 5 )
V_11 -> V_391 = V_392 ;
} else {
V_11 -> V_391 = V_396 ;
}
if ( V_11 -> V_391 ) {
memcpy ( ( T_1 * ) V_826 , V_832 -> V_830 . V_475 . V_826 , 16 ) ;
F_128 ( V_36 ) ;
F_191 ( V_36 , 4 , V_832 -> V_830 . V_475 . V_842 ,
V_11 -> V_391 ,
( T_1 * ) V_11 -> V_843 ,
0 , V_826 ) ;
if ( V_11 -> V_844 != 2 )
F_191 ( V_36 , V_832 -> V_830 . V_475 . V_842 ,
V_832 -> V_830 . V_475 . V_842 ,
V_11 -> V_391 ,
( T_1 * ) V_11 -> V_843 ,
0 , V_826 ) ;
}
} else {
memcpy ( ( T_1 * ) V_826 , V_832 -> V_830 . V_475 . V_826 , 16 ) ;
if ( strcmp ( V_832 -> V_830 . V_475 . V_840 , L_123 ) == 0 ) {
V_11 -> V_784 = V_395 ;
} else if ( strcmp ( V_832 -> V_830 . V_475 . V_840 , L_124 ) == 0 ) {
V_11 -> V_784 = V_394 ;
} else if ( strcmp ( V_832 -> V_830 . V_475 . V_840 , L_63 ) == 0 ) {
if ( V_832 -> V_830 . V_475 . V_841 == 13 )
V_11 -> V_784 = V_393 ;
else if ( V_832 -> V_830 . V_475 . V_841 == 5 )
V_11 -> V_784 = V_392 ;
} else {
V_11 -> V_784 = V_396 ;
}
if ( V_11 -> V_784 ) {
F_191 ( V_36 , V_832 -> V_830 . V_475 . V_842 ,
V_832 -> V_830 . V_475 . V_842 ,
V_11 -> V_784 ,
V_827 ,
0 ,
V_826 ) ;
}
}
}
V_189 = F_231 ( V_7 -> V_12 ,
& V_825 -> V_830 . V_40 ) ;
break;
default:
V_189 = - V_845 ;
break;
}
F_23 ( V_832 ) ;
V_832 = NULL ;
V_836:
F_135 ( & V_7 -> V_582 ) ;
return V_189 ;
}
static T_1 F_232 ( bool V_846 , T_1 V_178 )
{
T_1 V_847 = 0xff ;
if ( ! V_846 ) {
switch ( V_178 ) {
case V_298 :
V_847 = V_214 ;
break;
case V_299 :
V_847 = V_216 ;
break;
case V_300 :
V_847 = V_218 ;
break;
case V_301 :
V_847 = V_220 ;
break;
case V_302 :
V_847 = V_222 ;
break;
case V_303 :
V_847 = V_224 ;
break;
case V_304 :
V_847 = V_226 ;
break;
case V_305 :
V_847 = V_228 ;
break;
case V_306 :
V_847 = V_230 ;
break;
case V_307 :
V_847 = V_232 ;
break;
case V_308 :
V_847 = V_234 ;
break;
case V_309 :
V_847 = V_236 ;
break;
default:
V_847 = 0xff ;
F_9 ( V_848 ,
L_125 ,
V_178 , V_846 ) ;
break;
}
} else {
switch ( V_178 ) {
case V_311 :
V_847 = V_310 ;
break;
case V_313 :
V_847 = V_312 ;
break;
case V_315 :
V_847 = V_314 ;
break;
case V_317 :
V_847 = V_316 ;
break;
case V_319 :
V_847 = V_318 ;
break;
case V_321 :
V_847 = V_320 ;
break;
case V_323 :
V_847 = V_322 ;
break;
case V_325 :
V_847 = V_324 ;
break;
case V_327 :
V_847 = V_326 ;
break;
case V_329 :
V_847 = V_328 ;
break;
case V_331 :
V_847 = V_330 ;
break;
case V_333 :
V_847 = V_332 ;
break;
case V_335 :
V_847 = V_334 ;
break;
case V_337 :
V_847 = V_336 ;
break;
case V_339 :
V_847 = V_338 ;
break;
case V_341 :
V_847 = V_340 ;
break;
case V_342 :
V_847 = 0x80 | 0x20 ;
break;
default:
V_847 = 0xff ;
F_9 ( V_848 ,
L_125 ,
V_178 , V_846 ) ;
break;
}
}
return V_847 ;
}
static void F_233 ( struct V_35 * V_36 ,
struct V_133 * V_67 )
{
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
if ( V_67 -> V_849 && ! V_67 -> V_850 ) {
V_67 -> V_851 [ 0 ] = V_7 -> V_852 ;
V_67 -> V_851 [ 1 ] = V_7 -> V_853 ;
} else {
V_7 -> V_852 = V_67 -> V_851 [ 0 ] ;
V_7 -> V_853 = V_67 -> V_851 [ 1 ] ;
}
}
static long F_234 ( T_1 V_854 )
{
long V_855 ;
V_855 = ( long ) ( ( V_854 + 1 ) >> 1 ) ;
V_855 -= 95 ;
return V_855 ;
}
static void F_235 ( struct V_6 * V_7 , T_1 * V_856 ,
struct V_133 * V_857 ,
struct V_133 * V_858 )
{
bool V_859 = false ;
T_1 V_860 ;
T_2 V_861 , V_862 ;
static T_2 V_863 , V_864 ;
static T_2 V_865 , V_866 ;
static T_2 V_867 , V_868 ;
static T_2 V_869 ;
static T_2 V_870 ;
static T_2 V_871 ;
struct V_872 * V_873 ;
T_3 V_874 ;
unsigned int V_875 , V_876 ;
V_873 = (struct V_872 * ) V_856 ;
V_874 = F_134 ( V_873 -> V_877 ) ;
V_875 = F_236 ( V_874 ) ;
V_876 = F_237 ( V_874 ) ;
V_858 -> V_878 = V_876 ;
if ( ! V_857 -> V_849 ) {
V_859 = true ;
}
if ( V_864 ++ >= V_879 ) {
V_864 = V_879 ;
V_867 = V_7 -> V_67 . V_880 [ V_863 ] ;
V_7 -> V_67 . V_881 -= V_867 ;
}
V_7 -> V_67 . V_881 += V_857 -> V_882 ;
V_7 -> V_67 . V_880 [ V_863 ++ ] =
V_857 -> V_882 ;
if ( V_863 >= V_879 )
V_863 = 0 ;
V_862 = V_7 -> V_67 . V_881 / V_864 ;
V_7 -> V_67 . V_883 = F_234 ( ( T_1 ) V_862 ) ;
V_858 -> V_884 = V_7 -> V_67 . V_883 ;
if ( ! V_857 -> V_885 ) {
if ( ! V_857 -> V_886 )
return;
}
if ( ! V_859 )
return;
V_7 -> V_67 . V_887 ++ ;
if ( ! V_857 -> V_888 &&
( V_857 -> V_889 || V_857 -> V_886 ) ) {
for ( V_860 = V_890 ; V_860 < V_7 -> V_726 ; V_860 ++ ) {
if ( ! F_238 (
V_7 -> V_12 -> V_36 , V_860 ) )
continue;
if ( V_7 -> V_67 . V_891 [ V_860 ] == 0 )
V_7 -> V_67 . V_891 [ V_860 ] =
V_857 -> V_892 [ V_860 ] ;
if ( V_857 -> V_892 [ V_860 ] > V_7 -> V_67 . V_891 [ V_860 ] ) {
V_7 -> V_67 . V_891 [ V_860 ] =
( ( V_7 -> V_67 . V_891 [ V_860 ] * ( V_893 - 1 ) ) +
( V_857 -> V_892 [ V_860 ] ) ) / ( V_893 ) ;
V_7 -> V_67 . V_891 [ V_860 ] = V_7 -> V_67 . V_891 [ V_860 ] + 1 ;
} else {
V_7 -> V_67 . V_891 [ V_860 ] =
( ( V_7 -> V_67 . V_891 [ V_860 ] * ( V_893 - 1 ) ) +
( V_857 -> V_892 [ V_860 ] ) ) / ( V_893 ) ;
}
F_9 ( V_894 ,
L_126 ,
V_7 -> V_67 . V_891 [ V_860 ] ) ;
}
}
F_9 ( V_895 , L_127 ,
V_857 -> V_888 ? L_128 : L_129 ,
V_857 -> V_896 ) ;
if ( V_857 -> V_897 ) {
if ( V_870 ++ >= V_898 ) {
V_870 = V_898 ;
V_871 = V_7 -> V_67 . V_899 [ V_869 ] ;
V_7 -> V_67 . V_900 -= V_871 ;
}
V_7 -> V_67 . V_900 += V_857 -> V_896 ;
V_7 -> V_67 . V_899 [ V_869 ] = V_857 -> V_896 ;
V_869 ++ ;
if ( V_869 >= V_898 )
V_869 = 0 ;
V_857 -> V_896 = V_7 -> V_67 . V_900 / V_870 ;
if ( V_857 -> V_896 >= 3 )
V_857 -> V_896 -= 3 ;
}
F_9 ( V_895 , L_127 ,
V_857 -> V_888 ? L_128 : L_129 ,
V_857 -> V_896 ) ;
if ( V_857 -> V_889 ||
V_857 -> V_897 ||
V_857 -> V_886 ) {
if ( V_7 -> V_768 < 0 )
V_7 -> V_768 =
V_857 -> V_896 ;
if ( V_857 -> V_896 > ( T_2 ) V_7 -> V_768 ) {
V_7 -> V_768 =
( ( ( V_7 -> V_768 ) * ( V_893 - 1 ) ) +
( V_857 -> V_896 ) ) / ( V_893 ) ;
V_7 -> V_768 = V_7 -> V_768 + 1 ;
} else {
V_7 -> V_768 =
( ( ( V_7 -> V_768 ) * ( V_893 - 1 ) ) +
( V_857 -> V_896 ) ) / ( V_893 ) ;
}
}
if ( V_857 -> V_901 ) {
if ( V_857 -> V_889 ||
V_857 -> V_897 ||
V_857 -> V_886 ) {
if ( V_866 ++ >= V_879 ) {
V_866 = V_879 ;
V_868 = V_7 -> V_67 . V_902 [ V_865 ] ;
V_7 -> V_67 . V_903 -= V_868 ;
}
V_7 -> V_67 . V_903 +=
V_857 -> V_901 ;
V_7 -> V_67 . V_902 [ V_865 ++ ] =
V_857 -> V_901 ;
if ( V_865 >= V_879 )
V_865 = 0 ;
V_862 = V_7 -> V_67 . V_903 /
V_866 ;
V_7 -> V_67 . V_904 = V_862 ;
V_7 -> V_67 . V_905 = V_862 ;
}
if ( V_857 -> V_889 ||
V_857 -> V_897 ||
V_857 -> V_886 ) {
for ( V_861 = 0 ; V_861 < 2 ; V_861 ++ ) {
if ( V_857 -> V_906 [ V_861 ] != - 1 ) {
if ( V_7 -> V_67 . V_907 [ V_861 ] == 0 )
V_7 -> V_67 . V_907 [ V_861 ] = V_857 -> V_906 [ V_861 ] ;
V_7 -> V_67 . V_907 [ V_861 ] =
( ( V_7 -> V_67 . V_907 [ V_861 ] * ( V_893 - 1 ) ) +
( V_857 -> V_906 [ V_861 ] * 1 ) ) / ( V_893 ) ;
}
}
}
}
}
static T_1 F_239 ( char V_908 )
{
if ( ( V_908 <= - 100 ) || ( V_908 >= 20 ) )
return 0 ;
else if ( V_908 >= 0 )
return 100 ;
else
return 100 + V_908 ;
}
static T_1 F_240 ( char V_909 )
{
char V_910 ;
V_910 = V_909 ;
if ( V_910 >= 0 )
V_910 = 0 ;
if ( V_910 <= - 33 )
V_910 = - 33 ;
V_910 = 0 - V_910 ;
V_910 *= 3 ;
if ( V_910 == 99 )
V_910 = 100 ;
return V_910 ;
}
static long F_241 ( long V_911 )
{
long V_912 ;
if ( V_911 >= 61 && V_911 <= 100 )
V_912 = 90 + ( ( V_911 - 60 ) / 4 ) ;
else if ( V_911 >= 41 && V_911 <= 60 )
V_912 = 78 + ( ( V_911 - 40 ) / 2 ) ;
else if ( V_911 >= 31 && V_911 <= 40 )
V_912 = 66 + ( V_911 - 30 ) ;
else if ( V_911 >= 21 && V_911 <= 30 )
V_912 = 54 + ( V_911 - 20 ) ;
else if ( V_911 >= 5 && V_911 <= 20 )
V_912 = 42 + ( ( ( V_911 - 5 ) * 2 ) / 3 ) ;
else if ( V_911 == 4 )
V_912 = 36 ;
else if ( V_911 == 3 )
V_912 = 27 ;
else if ( V_911 == 2 )
V_912 = 18 ;
else if ( V_911 == 1 )
V_912 = 9 ;
else
V_912 = V_911 ;
return V_912 ;
}
static inline bool F_242 ( struct V_913 * V_914 )
{
if ( V_914 -> V_915 )
return false ;
switch ( V_914 -> V_916 ) {
case V_298 :
case V_299 :
case V_300 :
case V_301 :
return true ;
default:
return false ;
}
}
static void F_243 ( struct V_6 * V_7 ,
struct V_133 * V_134 ,
V_913 * V_914 ,
struct V_133 * V_917 ,
bool V_918 ,
bool V_919 ,
bool V_897 ,
bool V_886 )
{
T_10 * V_920 ;
T_11 * V_921 ;
T_12 * V_922 ;
T_1 * V_923 ;
T_1 V_1 , V_924 , V_925 , V_926 , V_927 ;
char V_928 [ 4 ] , V_929 = 0 ;
char V_930 , V_931 ;
T_1 V_932 , V_933 ;
T_2 V_934 , V_935 = 0 ;
T_1 V_936 = 0 ;
T_1 V_937 = 0 ;
T_1 V_938 ;
V_7 -> V_67 . V_939 ++ ;
V_936 = F_242 ( V_914 ) ;
memset ( V_917 , 0 , sizeof( struct V_133 ) ) ;
V_134 -> V_885 =
V_917 -> V_885 = V_918 ;
V_134 -> V_889 = V_917 -> V_889 = V_919 ;
V_134 -> V_888 = V_917 -> V_888 = V_936 ;
V_134 -> V_897 = V_917 -> V_897 = V_897 ;
V_134 -> V_886 = V_917 -> V_886 = V_886 ;
V_923 = ( T_1 * ) V_914 ;
V_923 += sizeof( V_913 ) ;
V_921 = ( T_11 * ) V_923 ;
V_920 = ( T_10 * ) V_923 ;
V_134 -> V_906 [ 0 ] = - 1 ;
V_134 -> V_906 [ 1 ] = - 1 ;
V_917 -> V_906 [ 0 ] = - 1 ;
V_917 -> V_906 [ 1 ] = - 1 ;
if ( V_936 ) {
T_1 V_940 ;
V_7 -> V_67 . V_941 ++ ;
if ( ! V_7 -> V_942 ) {
V_940 = V_921 -> V_943 & 0xc0 ;
V_940 >>= 6 ;
switch ( V_940 ) {
case 0x3 :
V_929 = - 35 - ( V_921 -> V_943 & 0x3e ) ;
break;
case 0x2 :
V_929 = - 23 - ( V_921 -> V_943 & 0x3e ) ;
break;
case 0x1 :
V_929 = - 11 - ( V_921 -> V_943 & 0x3e ) ;
break;
case 0x0 :
V_929 = 6 - ( V_921 -> V_943 & 0x3e ) ;
break;
}
} else {
V_940 = V_921 -> V_943 & 0x60 ;
V_940 >>= 5 ;
switch ( V_940 ) {
case 0x3 :
V_929 = - 35 - ( ( V_921 -> V_943 & 0x1f ) << 1 ) ;
break;
case 0x2 :
V_929 = - 23 - ( ( V_921 -> V_943 & 0x1f ) << 1 ) ;
break;
case 0x1 :
V_929 = - 11 - ( ( V_921 -> V_943 & 0x1f ) << 1 ) ;
break;
case 0x0 :
V_929 = 6 - ( ( V_921 -> V_943 & 0x1f ) << 1 ) ;
break;
}
}
V_933 = F_239 ( V_929 ) ;
V_134 -> V_896 = V_917 -> V_896 = V_933 ;
V_134 -> V_944 = V_933 ;
if ( V_134 -> V_896 > 40 ) {
V_938 = 100 ;
} else {
V_938 = V_921 -> V_945 ;
if ( V_921 -> V_945 > 64 )
V_938 = 0 ;
else if ( V_921 -> V_945 < 20 )
V_938 = 100 ;
else
V_938 = ( ( 64 - V_938 ) * 100 ) / 44 ;
}
V_134 -> V_901 = V_917 -> V_901 = V_938 ;
V_134 -> V_906 [ 0 ] =
V_917 -> V_906 [ 0 ] = V_938 ;
V_134 -> V_906 [ 1 ] =
V_917 -> V_906 [ 1 ] = - 1 ;
} else {
V_7 -> V_67 . V_946 ++ ;
for ( V_1 = V_890 ; V_1 < V_7 -> V_726 ; V_1 ++ ) {
if ( V_7 -> V_947 [ V_1 ] )
V_937 ++ ;
else
continue;
if ( ! F_238 (
V_7 -> V_12 -> V_36 , V_1 ) )
continue;
V_928 [ V_1 ] =
( ( V_920 -> V_948 [ V_1 ] & 0x3F ) * 2 ) - 106 ;
V_925 = V_920 -> V_949 [ V_1 ] ;
V_930 = ( char ) ( V_925 ) ;
V_930 /= 2 ;
V_7 -> V_67 . V_950 [ V_1 ] = ( long ) V_930 ;
V_934 = F_239 ( V_928 [ V_1 ] ) ;
V_935 += V_934 ;
V_134 -> V_892 [ V_1 ] = ( T_1 ) V_934 ;
V_917 -> V_892 [ V_1 ] = ( T_1 ) V_934 ;
}
V_929 = ( ( ( V_920 -> V_933 ) >> 1 ) & 0x7f ) - 106 ;
V_933 = F_239 ( V_929 ) ;
V_134 -> V_896 = V_917 -> V_896 = V_933 ;
V_134 -> V_951 = V_917 -> V_951 = V_929 ;
if ( V_914 -> V_915 && V_914 -> V_916 >= V_327 &&
V_914 -> V_916 <= V_341 )
V_924 = 2 ;
else
V_924 = 1 ;
for ( V_1 = 0 ; V_1 < V_924 ; V_1 ++ ) {
V_926 = V_920 -> V_952 [ V_1 ] ;
V_931 = ( char ) ( V_926 ) ;
V_931 /= 2 ;
V_932 = F_240 ( V_931 ) ;
if ( V_1 == 0 )
V_134 -> V_901 =
V_917 -> V_901 =
( T_1 ) ( V_932 & 0xff ) ;
V_134 -> V_906 [ V_1 ] =
V_917 -> V_906 [ V_1 ] =
( T_1 ) ( V_932 & 0xff ) ;
}
V_927 = V_920 -> V_927 ;
V_922 = ( T_12 * )
& V_927 ;
if ( V_914 -> V_953 )
V_7 -> V_67 . V_954 [ 1 + V_922 -> V_955 ] ++ ;
else
V_7 -> V_67 . V_954 [ 0 ] ++ ;
}
if ( V_936 ) {
V_134 -> V_882 =
V_917 -> V_882 =
( T_1 ) ( F_241 ( ( long ) V_933 ) ) ;
} else {
if ( V_937 != 0 ) {
V_134 -> V_882 =
V_917 -> V_882 =
( T_1 ) ( F_241 ( ( long ) ( V_935 /= V_937 ) ) ) ;
}
}
}
static void F_244 (
struct V_133 * V_956 ,
struct V_133 * V_957 )
{
V_957 -> V_849 = V_956 -> V_849 ;
V_957 -> V_850 = V_956 -> V_850 ;
V_957 -> V_878 = V_956 -> V_878 ;
}
static void F_245 ( struct V_140 * V_141 ,
struct V_133 * V_134 ,
V_913 * V_914 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 -> V_148 ;
struct V_35 * V_36 = V_143 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
bool V_918 , V_919 ;
bool V_897 = false , V_886 = false ;
static struct V_133 V_958 ;
struct V_872 * V_873 ;
T_3 V_959 , type ;
T_1 * V_960 ;
T_1 * V_961 ;
V_960 = ( T_1 * ) V_141 -> V_40 ;
V_873 = (struct V_872 * ) V_960 ;
V_959 = F_134 ( V_873 -> V_962 ) ;
type = F_246 ( V_959 ) ;
V_961 = V_873 -> V_963 ;
V_918 = ( V_964 != type ) &&
( F_247 ( V_7 -> V_12 -> V_211 . V_260 , ( V_959 & V_965 ) ? V_873 -> V_963 : ( V_959 & V_966 ) ? V_873 -> V_967 : V_873 -> V_968 ) )
&& ( ! V_134 -> V_969 ) && ( ! V_134 -> V_970 ) && ( ! V_134 -> V_971 ) ;
V_919 = V_918 &
( F_247 ( V_961 , V_7 -> V_12 -> V_36 -> V_617 ) ) ;
if ( F_248 ( V_959 ) == V_972 )
V_897 = true ;
if ( F_248 ( V_959 ) == V_973 ) {
if ( ( F_247 ( V_961 , V_36 -> V_617 ) ) )
V_886 = true ;
}
if ( V_918 )
V_7 -> V_67 . V_974 ++ ;
if ( V_919 )
V_7 -> V_67 . V_975 ++ ;
F_235 ( V_7 , V_960 , & V_958 , V_134 ) ;
F_243 ( V_7 , V_134 , V_914 , & V_958 ,
V_918 , V_919 ,
V_897 , V_886 ) ;
F_244 ( V_134 , & V_958 ) ;
}
static void
F_249 ( struct V_35 * V_36 ,
struct V_133 * V_67 )
{
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
T_2 V_976 = 1 ;
T_2 V_977 ;
T_2 V_978 ;
if ( V_67 -> V_970 )
V_976 = 2 ;
else if ( V_67 -> V_971 )
V_976 = 3 ;
if ( V_67 -> V_979 )
V_978 = 1 ;
else
V_978 = 0 ;
switch ( V_67 -> V_178 ) {
case V_214 :
V_977 = 0 ;
break;
case V_216 :
V_977 = 1 ;
break;
case V_218 :
V_977 = 2 ;
break;
case V_220 :
V_977 = 3 ;
break;
case V_222 :
V_977 = 4 ;
break;
case V_224 :
V_977 = 5 ;
break;
case V_226 :
V_977 = 6 ;
break;
case V_228 :
V_977 = 7 ;
break;
case V_230 :
V_977 = 8 ;
break;
case V_232 :
V_977 = 9 ;
break;
case V_234 :
V_977 = 10 ;
break;
case V_236 :
V_977 = 11 ;
break;
case V_310 :
V_977 = 12 ;
break;
case V_312 :
V_977 = 13 ;
break;
case V_314 :
V_977 = 14 ;
break;
case V_316 :
V_977 = 15 ;
break;
case V_318 :
V_977 = 16 ;
break;
case V_320 :
V_977 = 17 ;
break;
case V_322 :
V_977 = 18 ;
break;
case V_324 :
V_977 = 19 ;
break;
case V_326 :
V_977 = 20 ;
break;
case V_328 :
V_977 = 21 ;
break;
case V_330 :
V_977 = 22 ;
break;
case V_332 :
V_977 = 23 ;
break;
case V_334 :
V_977 = 24 ;
break;
case V_336 :
V_977 = 25 ;
break;
case V_338 :
V_977 = 26 ;
break;
case V_340 :
V_977 = 27 ;
break;
default:
V_977 = 28 ;
break;
}
V_7 -> V_67 . V_980 [ V_978 ] [ V_977 ] ++ ;
V_7 -> V_67 . V_981 [ 0 ] [ V_977 ] ++ ;
V_7 -> V_67 . V_981 [ V_976 ] [ V_977 ] ++ ;
}
static void F_250 ( struct V_140 * V_141 ,
struct V_133 * V_67 ,
bool V_982 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 -> V_148 ;
struct V_35 * V_36 = V_143 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
V_913 * V_983 = NULL ;
V_135 * V_984 = ( V_135 * ) V_141 -> V_40 ;
V_67 -> V_985 = V_984 -> V_985 ;
V_67 -> V_136 = V_984 -> V_136 ;
V_67 -> V_137 = 0 ;
V_67 -> V_971 = V_984 -> V_986 ;
V_67 -> V_970 = V_984 -> V_987 ;
V_67 -> V_969 = V_67 -> V_970 | V_67 -> V_971 ;
V_67 -> V_988 = ! V_984 -> V_989 ;
if ( ( V_7 -> V_12 -> V_251 -> V_417 ) &&
( V_7 -> V_12 -> V_391 == V_395 ) )
V_67 -> V_969 = false ;
else
V_67 -> V_969 = V_67 -> V_970 | V_67 -> V_971 ;
if ( V_67 -> V_985 < 24 || V_67 -> V_985 > V_990 )
V_67 -> V_969 |= 1 ;
if ( V_67 -> V_136 != 0 ) {
V_983 = ( V_913 * ) (
V_141 -> V_40
+ sizeof( V_135 )
+ V_67 -> V_137
) ;
if ( ! V_67 -> V_969 ) {
T_1 V_847 ;
V_847 = F_232 ( V_983 -> V_915 ,
V_983 -> V_916 ) ;
if ( V_847 == 0xff ) {
V_67 -> V_969 = 1 ;
V_67 -> V_178 = V_214 ;
} else {
V_67 -> V_178 = V_847 ;
}
} else {
V_67 -> V_178 = 0x02 ;
}
V_67 -> V_979 = V_983 -> V_991 ;
F_249 ( V_36 , V_67 ) ;
V_67 -> V_849 = ( V_983 -> V_992 == 1 ) ;
V_67 -> V_850 = ( V_983 -> V_992 == 1 ) &&
( V_983 -> V_993 == 1 ) ;
V_67 -> V_994 = V_983 -> V_995 ;
F_233 ( V_36 , V_67 ) ;
if ( V_983 -> V_993 == 1 || V_983 -> V_992 == 1 )
F_9 ( V_895 ,
L_130 ,
V_983 -> V_993 , V_983 -> V_992 ) ;
}
F_251 ( V_141 , sizeof( V_135 ) ) ;
if ( ( V_67 -> V_137 + V_67 -> V_136 ) > 0 ) {
V_67 -> V_996 = 1 ;
F_251 ( V_141 , V_67 -> V_137 + V_67 -> V_136 ) ;
}
if ( V_983 ) {
V_67 -> V_997 = V_983 -> V_953 ;
F_245 ( V_141 , V_67 , V_983 ) ;
}
}
static void F_252 ( struct V_140 * V_141 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 -> V_148 ;
struct V_35 * V_36 = V_143 -> V_36 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_133 V_67 = {
. signal = 0 ,
. V_998 = 0x100 - 98 ,
. V_178 = 0 ,
. V_999 = V_1000 ,
} ;
T_2 V_1001 = 0 ;
struct V_1002 * V_1003 = NULL ;
bool V_1004 = false ;
if ( ( V_141 -> V_202 >= ( 20 + sizeof( V_135 ) ) ) && ( V_141 -> V_202 < V_146 ) ) {
F_250 ( V_141 , & V_67 , false ) ;
F_253 ( V_141 , V_141 -> V_202 - 4 ) ;
V_1001 = V_141 -> V_202 ;
V_1003 = (struct V_1002 * ) V_141 -> V_40 ;
V_1004 = false ;
if ( F_254 ( V_1003 -> V_963 ) ) {
} else if ( F_255 ( V_1003 -> V_963 ) ) {
} else {
V_1004 = true ;
}
if ( ! F_256 ( V_7 -> V_12 , V_141 , & V_67 ) ) {
F_103 ( V_141 ) ;
} else {
V_7 -> V_67 . V_92 ++ ;
if ( V_1004 )
V_7 -> V_67 . V_1005 += V_1001 ;
}
} else {
V_7 -> V_67 . V_94 ++ ;
F_119 ( V_36 , L_131 , V_141 -> V_202 ) ;
F_103 ( V_141 ) ;
}
}
static void F_257 (
struct V_35 * V_36 ,
struct V_133 * V_134 )
{
T_1 * V_1006 ;
T_3 V_1007 = 0 ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
V_134 -> V_1008 += F_61 ( V_134 ) ;
V_1006 = V_134 -> V_1008 ;
V_1007 = V_134 -> V_1009 ;
#ifdef F_208
if ( ! V_558 -> V_559 )
F_258 ( V_558 , V_1010 ) ;
#endif
#ifdef F_259
T_9 V_1011 ;
V_558 -> V_1012 . V_1013 ( V_558 , V_1014 ,
( T_1 * ) ( & V_1011 ) ) ;
if ( V_1011 == V_723 )
return;
#endif
V_7 -> V_67 . V_1015 ++ ;
#ifdef F_208
F_260 ( V_558 , V_1010 ) ;
#endif
if ( F_89 ( V_36 , V_134 ) )
return;
#ifdef F_261
F_262 () ;
#endif
}
static void F_263 ( struct V_140 * V_141 ,
struct V_133 * V_67 )
{
V_135 * V_984 = ( V_135 * ) V_141 -> V_40 ;
V_67 -> V_1008 = ( T_1 * ) V_141 -> V_40 ;
V_67 -> V_985 = V_984 -> V_985 ;
V_67 -> V_136 = 0 ;
V_67 -> V_137 = 0 ;
V_67 -> V_1009 = V_67 -> V_985 - V_1016 ;
V_67 -> V_1017 = V_67 -> V_1009 ;
V_67 -> V_1018 = 0 ;
V_67 -> V_1019 = 1 ;
}
static void F_264 ( struct V_140 * V_141 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 -> V_148 ;
struct V_35 * V_36 = V_143 -> V_36 ;
struct V_133 V_67 = {
. signal = 0 ,
. V_998 = 0x100 - 98 ,
. V_178 = 0 ,
. V_999 = V_1000 ,
} ;
if ( ( V_141 -> V_202 >= ( 20 + sizeof( V_135 ) ) ) && ( V_141 -> V_202 < V_146 ) ) {
F_263 ( V_141 , & V_67 ) ;
F_257 ( V_36 , & V_67 ) ;
F_103 ( V_141 ) ;
}
}
static void V_592 ( struct V_6 * V_7 )
{
struct V_140 * V_141 ;
struct V_142 * V_143 ;
while ( NULL != ( V_141 = F_105 ( & V_7 -> V_177 ) ) ) {
V_143 = (struct V_142 * ) V_141 -> V_148 ;
switch ( V_143 -> V_149 ) {
case 3 :
V_7 -> V_516 -- ;
F_252 ( V_141 ) ;
break;
case 9 :
F_9 ( V_848 , L_132 ,
V_143 -> V_149 ) ;
F_264 ( V_141 ) ;
break;
default:
F_9 ( V_27 , L_133 ,
V_143 -> V_149 ) ;
F_112 ( V_141 ) ;
break;
}
}
}
static int F_265 ( struct V_1020 * V_1021 ,
const struct V_1022 * V_1023 )
{
struct V_35 * V_36 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_44 * V_45 = F_266 ( V_1021 ) ;
int V_189 ;
F_9 ( V_95 , L_134 ) ;
V_36 = F_267 ( sizeof( struct V_6 ) ) ;
if ( ! V_36 )
return - V_48 ;
F_268 ( V_1021 , V_36 ) ;
F_269 ( V_36 , & V_1021 -> V_36 ) ;
V_7 = F_19 ( V_36 ) ;
V_7 -> V_12 = F_270 ( V_36 ) ;
V_7 -> V_45 = V_45 ;
V_36 -> V_1024 = & V_1025 ;
V_36 -> V_1026 =
(struct V_1027 * ) & V_1028 ;
V_36 -> type = V_1029 ;
V_36 -> V_1030 = V_51 * 3 ;
if ( F_271 ( V_36 , V_1031 ) < 0 ) {
F_9 ( V_95 ,
L_135 ) ;
V_1031 = L_136 ;
F_271 ( V_36 , V_1031 ) ;
}
F_9 ( V_95 , L_137 ) ;
if ( F_163 ( V_36 ) != 0 ) {
F_9 ( V_27 , L_138 ) ;
V_189 = - V_1032 ;
goto V_1033;
}
F_199 ( V_36 ) ;
F_221 ( V_36 ) ;
V_189 = F_272 ( V_36 ) ;
if ( V_189 )
goto V_1034;
F_9 ( V_95 , L_139 , V_36 -> V_106 ) ;
F_50 ( V_36 ) ;
F_9 ( V_95 , L_140 ) ;
return 0 ;
V_1034:
F_220 ( V_36 ) ;
F_23 ( V_7 -> V_575 ) ;
V_7 -> V_575 = NULL ;
F_125 ( V_36 ) ;
F_60 ( 10 ) ;
V_1033:
F_165 ( V_36 ) ;
F_9 ( V_27 , L_141 ) ;
return V_189 ;
}
static void F_193 ( struct V_6 * V_7 )
{
F_273 ( & V_7 -> V_114 ) ;
F_197 ( & V_7 -> V_584 ) ;
F_197 ( & V_7 -> V_416 ) ;
F_273 ( & V_7 -> V_421 ) ;
}
static void F_274 ( struct V_1020 * V_1021 )
{
struct V_35 * V_36 = F_275 ( V_1021 ) ;
struct V_6 * V_7 = F_19 ( V_36 ) ;
if ( V_36 ) {
F_276 ( V_36 ) ;
F_9 ( V_817 ,
L_142 ) ;
F_53 ( V_36 ) ;
F_220 ( V_36 ) ;
F_23 ( V_7 -> V_575 ) ;
V_7 -> V_575 = NULL ;
F_125 ( V_36 ) ;
F_60 ( 10 ) ;
}
F_165 ( V_36 ) ;
F_9 ( V_817 , L_143 ) ;
}
static int T_13 F_277 ( void )
{
int V_189 ;
#ifdef F_278
V_189 = F_279 () ;
if ( V_189 ) {
F_280 ( L_144 , V_189 ) ;
return V_189 ;
}
#endif
V_189 = F_281 () ;
if ( V_189 ) {
F_280 ( L_145 , V_189 ) ;
return V_189 ;
}
V_189 = F_282 () ;
if ( V_189 ) {
F_280 ( L_146 , V_189 ) ;
return V_189 ;
}
V_189 = F_283 () ;
if ( V_189 ) {
F_280 ( L_147 , V_189 ) ;
return V_189 ;
}
V_189 = F_284 () ;
if ( V_189 ) {
F_280 ( L_148 , V_189 ) ;
return V_189 ;
}
F_285 ( L_149 ) ;
F_285 ( L_150 ) ;
F_9 ( V_95 , L_151 ) ;
F_9 ( V_95 , L_152 , V_1035 ) ;
F_43 () ;
return F_286 ( & V_1036 ) ;
}
static void T_14 F_287 ( void )
{
F_288 ( & V_1036 ) ;
F_9 ( V_817 , L_153 ) ;
}
void F_128 ( struct V_35 * V_36 )
{
T_1 V_679 = 0x0 ;
struct V_6 * V_7 = (struct V_6 * ) F_19 ( V_36 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
V_679 = V_715 | V_716 ;
if ( ( ( V_392 == V_11 -> V_391 ) || ( V_393 == V_11 -> V_391 ) ) && ( V_7 -> V_12 -> V_844 != 2 ) ) {
V_679 |= V_1037 ;
V_679 |= V_1038 ;
} else if ( ( V_11 -> V_120 == V_124 ) && ( V_11 -> V_391 & ( V_395 | V_394 ) ) ) {
V_679 |= V_1037 ;
V_679 |= V_1038 ;
}
V_11 -> V_1039 = 1 ;
if ( ( V_11 -> V_251 -> V_1040 & V_1041 ) || ! V_1042 ) {
V_11 -> V_1039 = 0 ;
V_679 &= ~ V_716 ;
}
F_9 ( V_783 , L_154 ,
V_28 , V_11 -> V_1039 , V_11 -> V_391 ,
V_679 ) ;
F_27 ( V_36 , V_718 , V_679 ) ;
}
void F_191 ( struct V_35 * V_36 , T_1 V_1043 , T_1 V_1044 , T_3 V_1045 ,
T_1 * V_780 , T_1 V_1046 , T_2 * V_1047 )
{
T_2 V_1048 = 0 ;
T_2 V_1049 = 0 ;
T_3 V_1050 = 0 ;
T_1 V_1 ;
if ( V_1043 >= V_1051 )
F_9 ( V_27 , L_155 ) ;
F_9 ( V_783 ,
L_156 ,
V_36 , V_1043 , V_1044 , V_1045 , V_780 ) ;
if ( V_1046 )
V_1050 |= F_13 ( 15 ) | ( V_1045 << 2 ) ;
else
V_1050 |= F_13 ( 15 ) | ( V_1045 << 2 ) | V_1044 ;
for ( V_1 = 0 ; V_1 < V_1052 ; V_1 ++ ) {
V_1048 = V_1 + V_1052 * V_1043 ;
V_1048 |= F_13 ( 31 ) | F_13 ( 16 ) ;
if ( V_1 == 0 ) {
V_1049 = ( T_2 ) ( * ( V_780 + 0 ) ) << 16 |
( T_2 ) ( * ( V_780 + 1 ) ) << 24 |
( T_2 ) V_1050 ;
F_14 ( V_36 , V_41 , V_1049 ) ;
F_14 ( V_36 , V_38 , V_1048 ) ;
} else if ( V_1 == 1 ) {
V_1049 = ( T_2 ) ( * ( V_780 + 2 ) ) |
( T_2 ) ( * ( V_780 + 3 ) ) << 8 |
( T_2 ) ( * ( V_780 + 4 ) ) << 16 |
( T_2 ) ( * ( V_780 + 5 ) ) << 24 ;
F_14 ( V_36 , V_41 , V_1049 ) ;
F_14 ( V_36 , V_38 , V_1048 ) ;
} else {
if ( V_1047 ) {
F_14 ( V_36 , V_41 , ( T_2 ) ( * ( V_1047 + V_1 - 2 ) ) ) ;
F_14 ( V_36 , V_38 , V_1048 ) ;
}
}
}
}
