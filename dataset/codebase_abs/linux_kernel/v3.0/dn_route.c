static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static T_1 unsigned F_3 ( T_2 V_3 , T_2 V_2 )
{
T_3 V_4 = ( T_3 V_5 ) ( V_3 ^ V_2 ) ;
V_4 ^= ( V_4 >> 3 ) ;
V_4 ^= ( V_4 >> 5 ) ;
V_4 ^= ( V_4 >> 10 ) ;
return V_6 & ( unsigned ) V_4 ;
}
static inline void F_4 ( struct V_7 * V_8 )
{
F_5 ( & V_8 -> V_2 . V_9 , V_10 ) ;
}
static inline void F_6 ( struct V_7 * V_8 )
{
F_7 ( & V_8 -> V_2 ) ;
F_5 ( & V_8 -> V_2 . V_9 , V_10 ) ;
}
static void F_8 ( unsigned long V_11 )
{
int V_12 ;
struct V_7 * V_8 ;
struct V_7 T_4 * * V_13 ;
unsigned long V_14 = V_15 ;
unsigned long V_16 = 120 * V_17 ;
for ( V_12 = 0 ; V_12 <= V_6 ; V_12 ++ ) {
V_13 = & V_18 [ V_12 ] . V_19 ;
F_9 ( & V_18 [ V_12 ] . V_20 ) ;
while ( ( V_8 = F_10 ( * V_13 ,
F_11 ( & V_18 [ V_12 ] . V_20 ) ) ) != NULL ) {
if ( F_12 ( & V_8 -> V_2 . V_21 ) ||
( V_14 - V_8 -> V_2 . V_22 ) < V_16 ) {
V_13 = & V_8 -> V_2 . V_23 ;
continue;
}
* V_13 = V_8 -> V_2 . V_23 ;
V_8 -> V_2 . V_23 = NULL ;
F_4 ( V_8 ) ;
}
F_13 ( & V_18 [ V_12 ] . V_20 ) ;
if ( ( V_15 - V_14 ) > 0 )
break;
}
F_14 ( & V_24 , V_14 + V_25 * V_17 ) ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_7 * V_8 ;
struct V_7 T_4 * * V_13 ;
int V_12 ;
unsigned long V_14 = V_15 ;
unsigned long V_16 = 10 * V_17 ;
for ( V_12 = 0 ; V_12 <= V_6 ; V_12 ++ ) {
F_16 ( & V_18 [ V_12 ] . V_20 ) ;
V_13 = & V_18 [ V_12 ] . V_19 ;
while ( ( V_8 = F_10 ( * V_13 ,
F_11 ( & V_18 [ V_12 ] . V_20 ) ) ) != NULL ) {
if ( F_12 ( & V_8 -> V_2 . V_21 ) ||
( V_14 - V_8 -> V_2 . V_22 ) < V_16 ) {
V_13 = & V_8 -> V_2 . V_23 ;
continue;
}
* V_13 = V_8 -> V_2 . V_23 ;
V_8 -> V_2 . V_23 = NULL ;
F_6 ( V_8 ) ;
break;
}
F_17 ( & V_18 [ V_12 ] . V_20 ) ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , T_5 V_28 )
{
T_5 V_29 = 230 ;
struct V_30 * V_31 = V_2 -> V_32 ?
F_19 ( V_2 -> V_32 -> V_33 -> V_34 ) : NULL ;
if ( V_31 && V_31 -> V_35 == 0 )
V_29 -= 6 ;
else
V_29 -= 21 ;
if ( F_20 ( V_2 , V_36 ) > V_28 && V_28 >= V_29 ) {
if ( ! ( F_21 ( V_2 , V_36 ) ) ) {
F_22 ( V_2 , V_36 , V_28 ) ;
F_23 ( V_2 , V_37 ) ;
}
if ( ! ( F_21 ( V_2 , V_38 ) ) ) {
T_5 V_39 = V_28 - V_40 ;
T_5 V_41 = F_24 ( V_2 , V_38 ) ;
if ( ! V_41 || V_41 > V_39 )
F_22 ( V_2 , V_38 , V_39 ) ;
}
}
}
static struct V_1 * F_25 ( struct V_1 * V_2 , T_6 V_42 )
{
return NULL ;
}
static struct V_1 * F_26 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
return NULL ;
}
static void F_27 ( struct V_43 * V_44 )
{
}
static inline int F_28 ( struct V_45 * V_46 , struct V_45 * V_47 )
{
return ( ( V_46 -> V_48 ^ V_47 -> V_48 ) |
( V_46 -> V_49 ^ V_47 -> V_49 ) |
( V_46 -> V_50 ^ V_47 -> V_50 ) |
( V_46 -> V_51 ^ V_47 -> V_51 ) |
( V_46 -> V_52 ^ V_47 -> V_52 ) |
( V_46 -> V_53 ^ V_47 -> V_53 ) ) == 0 ;
}
static int F_29 ( struct V_7 * V_8 , unsigned V_54 , struct V_7 * * V_55 )
{
struct V_7 * V_56 ;
struct V_7 T_4 * * V_57 ;
unsigned long V_14 = V_15 ;
V_57 = & V_18 [ V_54 ] . V_19 ;
F_16 ( & V_18 [ V_54 ] . V_20 ) ;
while ( ( V_56 = F_10 ( * V_57 ,
F_11 ( & V_18 [ V_54 ] . V_20 ) ) ) != NULL ) {
if ( F_28 ( & V_56 -> V_58 , & V_8 -> V_58 ) ) {
* V_57 = V_56 -> V_2 . V_23 ;
F_30 ( V_56 -> V_2 . V_23 ,
V_18 [ V_54 ] . V_19 ) ;
F_30 ( V_18 [ V_54 ] . V_19 , V_56 ) ;
F_31 ( & V_56 -> V_2 , V_14 ) ;
F_17 ( & V_18 [ V_54 ] . V_20 ) ;
F_6 ( V_8 ) ;
* V_55 = V_56 ;
return 0 ;
}
V_57 = & V_56 -> V_2 . V_23 ;
}
F_30 ( V_8 -> V_2 . V_23 , V_18 [ V_54 ] . V_19 ) ;
F_30 ( V_18 [ V_54 ] . V_19 , V_8 ) ;
F_31 ( & V_8 -> V_2 , V_14 ) ;
F_17 ( & V_18 [ V_54 ] . V_20 ) ;
* V_55 = V_8 ;
return 0 ;
}
static void F_32 ( unsigned long V_11 )
{
int V_12 ;
struct V_7 * V_8 , * V_59 ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
F_16 ( & V_18 [ V_12 ] . V_20 ) ;
if ( ( V_8 = F_33 ( (struct V_7 * * ) & V_18 [ V_12 ] . V_19 , NULL ) ) == NULL )
goto V_60;
for(; V_8 ; V_8 = V_59 ) {
V_59 = F_19 ( V_8 -> V_2 . V_23 ) ;
F_34 ( V_8 -> V_2 . V_23 , NULL ) ;
F_35 ( (struct V_1 * ) V_8 ) ;
}
V_60:
F_17 ( & V_18 [ V_12 ] . V_20 ) ;
}
}
void F_36 ( int V_61 )
{
unsigned long V_14 = V_15 ;
int V_62 = ! F_37 () ;
if ( V_61 < 0 )
V_61 = V_63 ;
F_16 ( & V_64 ) ;
if ( F_38 ( & V_65 ) && V_61 > 0 && V_66 ) {
long V_67 = ( long ) ( V_66 - V_14 ) ;
if ( V_62 && V_67 < V_68 - V_63 )
V_67 = 0 ;
if ( V_61 > V_67 )
V_61 = V_67 ;
}
if ( V_61 <= 0 ) {
F_17 ( & V_64 ) ;
F_32 ( 0 ) ;
return;
}
if ( V_66 == 0 )
V_66 = V_14 + V_68 ;
V_65 . V_69 = V_14 + V_61 ;
F_39 ( & V_65 ) ;
F_17 ( & V_64 ) ;
}
static int F_40 ( struct V_43 * V_44 )
{
struct V_70 * V_71 ;
unsigned char * V_72 ;
T_2 * V_3 ;
T_2 * V_2 ;
F_41 ( V_44 , V_44 -> V_73 - F_42 ( V_44 ) ) ;
if ( ( V_44 = F_43 ( V_44 , V_74 ) ) == NULL )
return V_75 ;
V_71 = F_44 ( V_44 ) ;
V_72 = V_44 -> V_73 + 2 ;
* V_72 ++ = ( V_71 -> V_76 & ~ V_77 ) | V_78 ;
V_2 = ( T_2 * ) V_72 ;
V_72 += 2 ;
V_3 = ( T_2 * ) V_72 ;
V_72 += 2 ;
* V_72 = 0 ;
F_45 ( * V_3 , * V_2 ) ;
V_44 -> V_79 = V_80 ;
F_46 ( V_44 , NULL , NULL ) ;
return V_81 ;
}
static int F_47 ( struct V_43 * V_44 )
{
struct V_70 * V_71 ;
unsigned char * V_72 ;
unsigned char * V_82 , * V_83 ;
unsigned char V_4 [ V_84 ] ;
F_41 ( V_44 , V_44 -> V_73 - F_42 ( V_44 ) ) ;
if ( ( V_44 = F_43 ( V_44 , V_74 ) ) == NULL )
return V_75 ;
V_71 = F_44 ( V_44 ) ;
V_72 = V_44 -> V_73 + 2 ;
if ( * V_72 & V_85 ) {
char V_86 = ( * V_72 & ~ V_85 ) ;
V_72 += V_86 ;
}
* V_72 ++ = ( V_71 -> V_76 & ~ V_77 ) | V_78 ;
V_72 += 2 ;
V_83 = V_72 ;
V_72 += 8 ;
V_82 = V_72 ;
V_72 += 6 ;
* V_72 = 0 ;
memcpy ( V_4 , V_82 , V_84 ) ;
memcpy ( V_82 , V_83 , V_84 ) ;
memcpy ( V_83 , V_4 , V_84 ) ;
V_44 -> V_79 = V_80 ;
F_46 ( V_44 , V_83 , V_82 ) ;
return V_81 ;
}
static int F_48 ( struct V_43 * V_44 )
{
struct V_70 * V_71 ;
int V_87 ;
if ( ( V_87 = F_49 ( V_44 ) ) == 0 )
return F_50 ( V_44 ) ;
V_71 = F_44 ( V_44 ) ;
if ( V_88 & 4 ) {
char * V_89 = V_44 -> V_33 ? V_44 -> V_33 -> V_90 : L_1 ;
F_51 ( V_91
L_2 ,
( int ) V_71 -> V_76 , V_89 , V_44 -> V_92 ,
F_52 ( V_71 -> V_3 ) , F_52 ( V_71 -> V_2 ) ,
V_87 , V_44 -> V_79 ) ;
}
if ( ( V_44 -> V_79 == V_93 ) && ( V_71 -> V_76 & V_77 ) ) {
switch( V_71 -> V_76 & V_94 ) {
case V_95 :
return F_40 ( V_44 ) ;
case V_96 :
return F_47 ( V_44 ) ;
}
}
F_53 ( V_44 ) ;
return V_75 ;
}
static int F_54 ( struct V_43 * V_44 )
{
struct V_70 * V_71 = F_44 ( V_44 ) ;
unsigned char * V_72 = V_44 -> V_73 ;
if ( ! F_55 ( V_44 , 21 ) )
goto V_97;
F_56 ( V_44 , 20 ) ;
F_57 ( V_44 ) ;
V_72 += 2 ;
V_71 -> V_2 = F_58 ( V_72 ) ;
if ( memcmp ( V_72 , V_98 , 4 ) != 0 )
goto V_97;
V_72 += 6 ;
V_72 += 2 ;
V_71 -> V_3 = F_58 ( V_72 ) ;
if ( memcmp ( V_72 , V_98 , 4 ) != 0 )
goto V_97;
V_72 += 6 ;
V_72 ++ ;
V_71 -> V_99 = * V_72 ++ ;
return F_59 ( V_100 , V_101 , V_44 , V_44 -> V_33 , NULL ,
F_48 ) ;
V_97:
F_53 ( V_44 ) ;
return V_75 ;
}
static int F_60 ( struct V_43 * V_44 )
{
struct V_70 * V_71 = F_44 ( V_44 ) ;
unsigned char * V_72 = V_44 -> V_73 ;
if ( ! F_55 ( V_44 , 6 ) )
goto V_97;
F_56 ( V_44 , 5 ) ;
F_57 ( V_44 ) ;
V_71 -> V_2 = * ( T_2 * ) V_72 ;
V_72 += 2 ;
V_71 -> V_3 = * ( T_2 * ) V_72 ;
V_72 += 2 ;
V_71 -> V_99 = * V_72 & 0x3f ;
return F_59 ( V_100 , V_101 , V_44 , V_44 -> V_33 , NULL ,
F_48 ) ;
V_97:
F_53 ( V_44 ) ;
return V_75 ;
}
static int F_61 ( struct V_43 * V_44 )
{
F_53 ( V_44 ) ;
return V_81 ;
}
static int F_62 ( struct V_43 * V_44 )
{
F_63 ( V_44 ) ;
F_64 ( V_44 ) ;
return V_81 ;
}
int F_65 ( struct V_43 * V_44 , struct V_102 * V_33 , struct V_103 * V_104 , struct V_102 * V_105 )
{
struct V_70 * V_71 ;
unsigned char V_106 = 0 ;
T_3 V_92 = F_52 ( * ( T_2 * ) V_44 -> V_73 ) ;
struct V_30 * V_31 = F_66 ( V_33 -> V_34 ) ;
unsigned char V_86 = 0 ;
if ( ! F_67 ( F_68 ( V_33 ) , & V_107 ) )
goto V_108;
if ( V_31 == NULL )
goto V_108;
if ( ( V_44 = F_69 ( V_44 , V_74 ) ) == NULL )
goto V_109;
if ( ! F_55 ( V_44 , 3 ) )
goto V_108;
F_56 ( V_44 , 2 ) ;
if ( V_92 > V_44 -> V_92 )
goto V_108;
F_70 ( V_44 , V_92 ) ;
V_106 = * V_44 -> V_73 ;
V_71 = F_44 ( V_44 ) ;
V_71 -> V_110 = V_15 ;
V_71 -> V_111 = V_33 -> V_112 ;
if ( V_106 & V_85 ) {
V_86 = V_106 & ~ V_85 ;
if ( ! F_55 ( V_44 , V_86 + 1 ) )
goto V_108;
F_56 ( V_44 , V_86 ) ;
V_106 = * V_44 -> V_73 ;
}
F_71 ( V_44 ) ;
if ( V_106 & V_113 )
goto V_108;
V_71 -> V_76 = V_106 ;
if ( V_88 & 1 )
F_51 ( V_91
L_3 ,
( int ) V_106 , ( V_33 ) ? V_33 -> V_90 : L_1 , V_92 , V_44 -> V_92 ,
V_86 ) ;
if ( V_106 & V_114 ) {
if ( F_72 ( F_73 ( V_44 ) ) )
goto V_108;
switch( V_106 & V_115 ) {
case V_116 :
F_74 ( V_44 ) ;
break;
case V_117 :
F_75 ( V_44 ) ;
break;
}
if ( V_31 -> V_118 . V_119 != V_120 )
goto V_108;
switch( V_106 & V_115 ) {
case V_121 :
return F_59 ( V_100 , V_122 ,
V_44 , V_44 -> V_33 , NULL ,
F_62 ) ;
case V_123 :
case V_124 :
return F_59 ( V_100 , V_125 ,
V_44 , V_44 -> V_33 , NULL ,
F_61 ) ;
case V_126 :
return F_59 ( V_100 , V_122 ,
V_44 , V_44 -> V_33 , NULL ,
V_127 ) ;
case V_128 :
return F_59 ( V_100 , V_122 ,
V_44 , V_44 -> V_33 , NULL ,
V_129 ) ;
}
} else {
if ( V_31 -> V_118 . V_119 != V_120 )
goto V_108;
F_56 ( V_44 , 1 ) ;
switch( V_106 & V_94 ) {
case V_96 :
return F_54 ( V_44 ) ;
case V_95 :
return F_60 ( V_44 ) ;
}
}
V_108:
F_53 ( V_44 ) ;
V_109:
return V_75 ;
}
static int F_76 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_77 ( V_44 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_102 * V_33 = V_2 -> V_33 ;
struct V_70 * V_71 = F_44 ( V_44 ) ;
struct V_32 * V_130 ;
int V_87 = - V_131 ;
if ( ( V_130 = V_2 -> V_32 ) == NULL )
goto error;
V_44 -> V_33 = V_33 ;
V_71 -> V_3 = V_8 -> V_132 ;
V_71 -> V_2 = V_8 -> V_133 ;
V_71 -> V_76 &= ~ V_77 ;
V_71 -> V_76 |= V_134 ;
V_71 -> V_99 = 0 ;
return F_59 ( V_100 , V_135 , V_44 , NULL , V_33 ,
V_130 -> V_136 ) ;
error:
if ( F_78 () )
F_51 ( V_91 L_4 ) ;
F_53 ( V_44 ) ;
return V_87 ;
}
static int F_79 ( struct V_43 * V_44 )
{
struct V_70 * V_71 = F_44 ( V_44 ) ;
struct V_1 * V_2 = F_77 ( V_44 ) ;
struct V_30 * V_137 = F_66 ( V_2 -> V_33 -> V_34 ) ;
struct V_7 * V_8 ;
struct V_32 * V_130 = V_2 -> V_32 ;
int V_138 ;
#ifdef F_80
struct V_102 * V_33 = V_44 -> V_33 ;
#endif
if ( V_44 -> V_79 != V_93 )
goto V_139;
V_8 = (struct V_7 * ) F_77 ( V_44 ) ;
V_138 = V_137 -> V_35 ? 21 : 6 ;
if ( F_81 ( V_44 , F_82 ( V_8 -> V_2 . V_33 ) + V_138 ) )
goto V_139;
if ( ++ V_71 -> V_99 > 30 )
goto V_139;
V_44 -> V_33 = V_8 -> V_2 . V_33 ;
V_71 -> V_76 &= ~ V_134 ;
if ( V_8 -> V_76 & V_140 )
V_71 -> V_76 |= V_134 ;
return F_59 ( V_100 , V_141 , V_44 , V_33 , V_44 -> V_33 ,
V_130 -> V_136 ) ;
V_139:
F_53 ( V_44 ) ;
return V_75 ;
}
static int F_83 ( struct V_43 * V_44 )
{
if ( F_78 () ) {
struct V_70 * V_71 = F_44 ( V_44 ) ;
F_51 ( V_91 L_5 ,
F_52 ( V_71 -> V_3 ) , F_52 ( V_71 -> V_2 ) ) ;
}
F_53 ( V_44 ) ;
return V_75 ;
}
static unsigned int F_84 ( const struct V_1 * V_2 )
{
return F_85 ( V_2 -> V_33 , F_86 ( V_2 ) ) ;
}
static unsigned int F_87 ( const struct V_1 * V_2 )
{
return V_2 -> V_33 -> V_28 ;
}
static int F_88 ( struct V_7 * V_8 , struct V_142 * V_143 )
{
struct V_144 * V_145 = V_143 -> V_145 ;
struct V_102 * V_33 = V_8 -> V_2 . V_33 ;
unsigned int V_146 ;
struct V_32 * V_147 ;
if ( V_145 ) {
if ( F_89 ( * V_143 ) &&
F_90 ( * V_143 ) . V_148 == V_149 )
V_8 -> V_150 = F_89 ( * V_143 ) ;
F_91 ( & V_8 -> V_2 , V_145 -> V_151 , true ) ;
}
V_8 -> V_152 = V_143 -> type ;
if ( V_33 != NULL && V_8 -> V_2 . V_32 == NULL ) {
V_147 = F_92 ( & V_153 , & V_8 -> V_150 , V_33 ) ;
if ( F_93 ( V_147 ) )
return F_94 ( V_147 ) ;
V_8 -> V_2 . V_32 = V_147 ;
}
if ( F_20 ( & V_8 -> V_2 , V_36 ) > V_8 -> V_2 . V_33 -> V_28 )
F_22 ( & V_8 -> V_2 , V_36 , V_8 -> V_2 . V_33 -> V_28 ) ;
V_146 = F_24 ( & V_8 -> V_2 , V_38 ) ;
if ( V_146 ) {
unsigned int V_39 = F_85 ( V_33 , F_86 ( & V_8 -> V_2 ) ) ;
if ( V_146 > V_39 )
F_22 ( & V_8 -> V_2 , V_38 , V_39 ) ;
}
return 0 ;
}
static inline int F_95 ( T_2 V_154 , T_2 V_155 )
{
T_3 V_4 = F_52 ( V_154 ) ^ F_52 ( V_155 ) ;
int V_156 = 16 ;
while( V_4 ) {
V_4 >>= 1 ;
V_156 -- ;
}
return V_156 ;
}
static T_2 F_96 ( const struct V_102 * V_33 , T_2 V_48 , int V_157 )
{
T_2 V_49 = 0 ;
struct V_30 * V_137 ;
struct V_158 * V_159 ;
int V_160 = 0 ;
int V_161 ;
F_97 () ;
V_137 = F_66 ( V_33 -> V_34 ) ;
for ( V_159 = F_66 ( V_137 -> V_162 ) ;
V_159 != NULL ;
V_159 = F_66 ( V_159 -> V_163 ) ) {
if ( V_159 -> V_164 > V_157 )
continue;
if ( ! V_48 ) {
V_49 = V_159 -> V_165 ;
break;
}
V_161 = F_95 ( V_48 , V_159 -> V_165 ) ;
if ( V_161 > V_160 )
V_49 = V_159 -> V_165 ;
if ( V_160 == 0 )
V_49 = V_159 -> V_165 ;
}
F_98 () ;
return V_49 ;
}
static inline T_2 F_99 ( struct V_142 * V_143 )
{
return F_96 ( F_100 ( * V_143 ) , F_89 ( * V_143 ) , V_143 -> V_157 ) ;
}
static inline T_2 F_101 ( T_2 V_48 , struct V_142 * V_143 )
{
T_2 V_166 = F_102 ( V_143 -> V_167 ) ;
return ( V_48 & ~ V_166 ) | V_143 -> V_145 -> V_168 -> V_169 ;
}
static int F_103 ( struct V_1 * * V_170 , const struct V_45 * V_171 , int V_172 )
{
struct V_45 V_58 = {
. V_48 = V_171 -> V_48 ,
. V_49 = V_171 -> V_49 ,
. V_51 = V_173 ,
. V_50 = V_171 -> V_50 ,
. V_53 = V_107 . V_174 -> V_112 ,
. V_52 = V_171 -> V_52 ,
} ;
struct V_7 * V_8 = NULL ;
struct V_102 * V_175 = NULL , * V_33 ;
struct V_32 * V_130 = NULL ;
unsigned V_54 ;
unsigned V_106 = 0 ;
struct V_142 V_143 = { . V_145 = NULL , . type = V_176 } ;
int V_87 ;
int V_177 = 0 ;
T_2 V_178 = 0 ;
if ( V_88 & 16 )
F_51 ( V_91
L_6
L_7 , F_52 ( V_171 -> V_48 ) ,
F_52 ( V_171 -> V_49 ) ,
V_171 -> V_50 , V_107 . V_174 -> V_112 ,
V_171 -> V_52 ) ;
if ( V_171 -> V_52 ) {
V_175 = F_104 ( & V_107 , V_171 -> V_52 ) ;
V_87 = - V_179 ;
if ( V_175 && V_175 -> V_34 == NULL ) {
F_105 ( V_175 ) ;
V_175 = NULL ;
}
if ( V_175 == NULL )
goto V_109;
}
if ( V_171 -> V_49 ) {
V_87 = - V_180 ;
if ( V_175 ) {
if ( F_106 ( V_175 , V_171 -> V_49 ) )
goto V_181;
F_105 ( V_175 ) ;
goto V_109;
}
F_97 () ;
F_107 (&init_net, dev) {
if ( ! V_33 -> V_34 )
continue;
if ( ! F_106 ( V_33 , V_171 -> V_49 ) )
continue;
if ( ( V_33 -> V_106 & V_182 ) &&
V_171 -> V_48 &&
! F_106 ( V_33 , V_171 -> V_48 ) )
continue;
V_175 = V_33 ;
break;
}
F_98 () ;
if ( V_175 == NULL )
goto V_109;
F_108 ( V_175 ) ;
V_181:
;
}
if ( ! V_58 . V_48 ) {
V_58 . V_48 = V_58 . V_49 ;
V_87 = - V_180 ;
if ( V_175 )
F_105 ( V_175 ) ;
V_175 = V_107 . V_174 ;
F_108 ( V_175 ) ;
if ( ! V_58 . V_48 ) {
V_58 . V_48 =
V_58 . V_49 = F_96 ( V_175 , 0 ,
V_183 ) ;
if ( ! V_58 . V_48 )
goto V_109;
}
V_58 . V_52 = V_107 . V_174 -> V_112 ;
V_143 . type = V_184 ;
goto V_185;
}
if ( V_88 & 16 )
F_51 ( V_91
L_8
L_9 ,
F_52 ( V_58 . V_48 ) , F_52 ( V_58 . V_49 ) ,
V_58 . V_52 , V_172 ) ;
V_87 = - V_186 ;
if ( V_172 || ( V_87 = F_109 ( & V_58 , & V_143 ) ) != 0 ) {
struct V_30 * V_137 ;
if ( V_87 != - V_186 )
goto V_109;
if ( ! V_172 ) {
V_130 = F_110 ( & V_153 , & V_107 , & V_58 . V_48 ) ;
if ( V_130 ) {
if ( ( V_171 -> V_52 &&
( V_130 -> V_33 -> V_112 != V_171 -> V_52 ) ) ||
( V_171 -> V_49 &&
( ! F_106 ( V_130 -> V_33 ,
V_171 -> V_49 ) ) ) ) {
F_111 ( V_130 ) ;
V_130 = NULL ;
} else {
if ( V_175 )
F_105 ( V_175 ) ;
if ( F_106 ( V_130 -> V_33 , V_58 . V_48 ) ) {
V_175 = V_107 . V_174 ;
V_143 . type = V_184 ;
} else {
V_175 = V_130 -> V_33 ;
}
F_108 ( V_175 ) ;
goto V_187;
}
}
}
if ( V_175 == NULL )
V_175 = F_112 () ;
V_87 = - V_179 ;
if ( V_175 == NULL )
goto V_109;
V_137 = F_19 ( V_175 -> V_34 ) ;
if ( F_106 ( V_175 , V_58 . V_48 ) ) {
F_105 ( V_175 ) ;
V_175 = V_107 . V_174 ;
F_108 ( V_175 ) ;
V_143 . type = V_184 ;
goto V_187;
}
V_130 = F_113 ( V_137 -> V_188 ) ;
F_114 ( V_130 && V_130 -> V_33 != V_175 ) ;
V_187:
if ( V_130 )
V_178 = ( (struct V_189 * ) V_130 ) -> V_190 ;
if ( V_178 == 0 )
V_178 = V_58 . V_48 ;
if ( V_58 . V_49 == 0 ) {
V_58 . V_49 = F_96 ( V_175 , V_178 ,
V_143 . type == V_184 ?
V_183 :
V_149 ) ;
if ( V_58 . V_49 == 0 && V_143 . type != V_184 )
goto V_191;
}
V_58 . V_52 = V_175 -> V_112 ;
goto V_185;
}
V_177 = 1 ;
if ( V_143 . type == V_192 )
goto V_193;
if ( V_143 . type == V_184 ) {
if ( ! V_58 . V_49 )
V_58 . V_49 = V_58 . V_48 ;
if ( V_175 )
F_105 ( V_175 ) ;
V_175 = V_107 . V_174 ;
F_108 ( V_175 ) ;
V_58 . V_52 = V_175 -> V_112 ;
if ( V_143 . V_145 )
F_115 ( V_143 . V_145 ) ;
V_143 . V_145 = NULL ;
goto V_185;
}
if ( V_143 . V_145 -> V_194 > 1 && V_58 . V_52 == 0 )
F_116 ( & V_58 , & V_143 ) ;
if ( ! V_58 . V_49 )
V_58 . V_49 = F_117 ( V_143 ) ;
if ( V_175 )
F_105 ( V_175 ) ;
V_175 = F_100 ( V_143 ) ;
F_108 ( V_175 ) ;
V_58 . V_52 = V_175 -> V_112 ;
V_178 = F_89 ( V_143 ) ;
V_185:
if ( V_175 -> V_106 & V_182 )
V_106 |= V_195 ;
V_8 = F_118 ( & V_196 , V_175 , 1 , 0 , V_197 ) ;
if ( V_8 == NULL )
goto V_198;
memset ( & V_8 -> V_58 , 0 , sizeof( V_8 -> V_58 ) ) ;
V_8 -> V_58 . V_49 = V_171 -> V_49 ;
V_8 -> V_58 . V_48 = V_171 -> V_48 ;
V_8 -> V_58 . V_52 = V_171 -> V_52 ;
V_8 -> V_58 . V_53 = 0 ;
V_8 -> V_58 . V_50 = V_171 -> V_50 ;
V_8 -> V_132 = V_58 . V_49 ;
V_8 -> V_133 = V_58 . V_48 ;
V_8 -> V_150 = V_178 ? V_178 : V_58 . V_48 ;
V_8 -> V_199 = V_58 . V_49 ;
V_8 -> V_200 = V_58 . V_48 ;
V_8 -> V_201 = V_58 . V_49 ;
V_8 -> V_2 . V_32 = V_130 ;
V_130 = NULL ;
V_8 -> V_2 . V_22 = V_15 ;
V_8 -> V_2 . V_136 = F_76 ;
V_8 -> V_2 . V_202 = F_83 ;
V_8 -> V_76 = V_106 ;
if ( V_106 & V_195 )
V_8 -> V_2 . V_202 = V_203 ;
V_87 = F_88 ( V_8 , & V_143 ) ;
if ( V_87 )
goto V_204;
V_54 = F_3 ( V_8 -> V_58 . V_49 , V_8 -> V_58 . V_48 ) ;
F_29 ( V_8 , V_54 , (struct V_7 * * ) V_170 ) ;
V_205:
if ( V_130 )
F_111 ( V_130 ) ;
if ( V_177 )
F_119 ( & V_143 ) ;
if ( V_175 )
F_105 ( V_175 ) ;
V_109:
return V_87 ;
V_191:
V_87 = - V_180 ;
goto V_205;
V_193:
V_87 = - V_131 ;
goto V_205;
V_198:
V_87 = - V_206 ;
goto V_205;
V_204:
F_35 ( & V_8 -> V_2 ) ;
goto V_198;
}
static int F_120 ( struct V_1 * * V_170 , const struct V_45 * V_207 , int V_106 )
{
unsigned V_54 = F_3 ( V_207 -> V_49 , V_207 -> V_48 ) ;
struct V_7 * V_8 = NULL ;
if ( ! ( V_106 & V_208 ) ) {
F_121 () ;
for ( V_8 = F_122 ( V_18 [ V_54 ] . V_19 ) ; V_8 ;
V_8 = F_122 ( V_8 -> V_2 . V_23 ) ) {
if ( ( V_207 -> V_48 == V_8 -> V_58 . V_48 ) &&
( V_207 -> V_49 == V_8 -> V_58 . V_49 ) &&
( V_207 -> V_50 == V_8 -> V_58 . V_50 ) &&
F_123 ( V_8 ) &&
( V_8 -> V_58 . V_52 == V_207 -> V_52 ) ) {
F_31 ( & V_8 -> V_2 , V_15 ) ;
F_124 () ;
* V_170 = & V_8 -> V_2 ;
return 0 ;
}
}
F_124 () ;
}
return F_103 ( V_170 , V_207 , V_106 ) ;
}
static int F_125 ( struct V_1 * * V_170 , struct V_45 * V_207 , int V_106 )
{
int V_87 ;
V_87 = F_120 ( V_170 , V_207 , V_106 ) ;
if ( V_87 == 0 && V_207 -> V_209 ) {
* V_170 = F_126 ( & V_107 , * V_170 ,
F_127 ( V_207 ) , NULL , 0 ) ;
if ( F_93 ( * V_170 ) ) {
V_87 = F_94 ( * V_170 ) ;
* V_170 = NULL ;
}
}
return V_87 ;
}
int F_128 ( struct V_1 * * V_170 , struct V_45 * V_210 , struct V_211 * V_212 , int V_106 )
{
int V_87 ;
V_87 = F_120 ( V_170 , V_210 , V_106 & V_208 ) ;
if ( V_87 == 0 && V_210 -> V_209 ) {
if ( ! ( V_106 & V_213 ) )
V_210 -> V_214 |= V_215 ;
* V_170 = F_126 ( & V_107 , * V_170 ,
F_127 ( V_210 ) , V_212 , 0 ) ;
if ( F_93 ( * V_170 ) ) {
V_87 = F_94 ( * V_170 ) ;
* V_170 = NULL ;
}
}
return V_87 ;
}
static int F_129 ( struct V_43 * V_44 )
{
struct V_7 * V_8 = NULL ;
struct V_70 * V_71 = F_44 ( V_44 ) ;
struct V_102 * V_216 = V_44 -> V_33 ;
struct V_102 * V_217 = NULL ;
struct V_30 * V_137 ;
struct V_32 * V_130 = NULL ;
unsigned V_54 ;
int V_106 = 0 ;
T_2 V_178 = 0 ;
T_2 V_218 = 0 ;
struct V_45 V_58 = {
. V_48 = V_71 -> V_2 ,
. V_49 = V_71 -> V_3 ,
. V_51 = V_173 ,
. V_50 = V_44 -> V_219 ,
. V_53 = V_44 -> V_33 -> V_112 ,
} ;
struct V_142 V_143 = { . V_145 = NULL , . type = V_220 } ;
int V_87 = - V_131 ;
int V_177 = 0 ;
F_108 ( V_216 ) ;
if ( ( V_137 = F_66 ( V_216 -> V_34 ) ) == NULL )
goto V_109;
if ( V_58 . V_49 == 0 )
goto V_109;
V_87 = - V_221 ;
if ( F_106 ( V_216 , V_71 -> V_3 ) )
goto V_109;
V_87 = F_109 ( & V_58 , & V_143 ) ;
if ( V_87 ) {
if ( V_87 != - V_186 )
goto V_109;
if ( ! F_106 ( V_216 , V_71 -> V_2 ) )
goto V_193;
V_143 . type = V_184 ;
} else {
T_2 V_222 = V_58 . V_49 ;
V_177 = 1 ;
V_217 = F_100 ( V_143 ) ;
if ( V_217 == NULL ) {
if ( F_78 () )
F_51 ( V_223 L_10
L_11 ) ;
goto V_193;
}
F_108 ( V_217 ) ;
if ( V_143 . V_224 )
V_222 = V_58 . V_49 ;
V_178 = F_89 ( V_143 ) ;
if ( V_143 . type == V_192 ) {
V_58 . V_48 = F_101 ( V_58 . V_48 , & V_143 ) ;
F_119 ( & V_143 ) ;
V_177 = 0 ;
if ( F_109 ( & V_58 , & V_143 ) )
goto V_193;
V_177 = 1 ;
if ( V_143 . type != V_176 )
goto V_193;
V_106 |= V_225 ;
V_178 = V_58 . V_48 ;
}
V_58 . V_49 = V_222 ;
}
switch( V_143 . type ) {
case V_176 :
if ( V_137 -> V_118 . V_226 == 0 )
goto V_193;
if ( V_143 . V_145 -> V_194 > 1 && V_58 . V_52 == 0 )
F_116 ( & V_58 , & V_143 ) ;
if ( V_217 == V_216 && ! ( V_106 & V_227 ) )
V_106 |= V_140 ;
V_218 = F_117 ( V_143 ) ;
case V_228 :
case V_220 :
break;
case V_184 :
V_106 |= V_195 ;
V_58 . V_49 = V_71 -> V_2 ;
V_58 . V_48 = V_71 -> V_3 ;
if ( V_178 )
goto V_185;
if ( V_71 -> V_76 & V_134 ) {
V_178 = V_71 -> V_3 ;
V_106 |= V_229 ;
goto V_185;
}
V_130 = F_113 ( V_137 -> V_188 ) ;
if ( V_130 ) {
V_178 = ( (struct V_189 * ) V_130 ) -> V_190 ;
goto V_185;
}
V_178 = V_71 -> V_3 ;
V_106 |= V_229 ;
goto V_185;
default:
goto V_193;
}
V_185:
V_8 = F_118 ( & V_196 , V_217 , 0 , 0 , V_197 ) ;
if ( V_8 == NULL )
goto V_198;
memset ( & V_8 -> V_58 , 0 , sizeof( V_8 -> V_58 ) ) ;
V_8 -> V_132 = V_58 . V_49 ;
V_8 -> V_133 = V_58 . V_48 ;
V_8 -> V_150 = V_58 . V_48 ;
if ( V_178 )
V_8 -> V_150 = V_178 ;
V_8 -> V_199 = V_218 ? V_218 : V_8 -> V_132 ;
V_8 -> V_200 = V_58 . V_48 ;
V_8 -> V_201 = V_58 . V_49 ;
V_8 -> V_58 . V_49 = V_71 -> V_3 ;
V_8 -> V_58 . V_48 = V_71 -> V_2 ;
V_8 -> V_58 . V_52 = 0 ;
V_8 -> V_58 . V_53 = V_216 -> V_112 ;
V_8 -> V_58 . V_50 = V_58 . V_50 ;
V_8 -> V_2 . V_32 = V_130 ;
V_8 -> V_2 . V_22 = V_15 ;
V_8 -> V_2 . V_136 = F_83 ;
switch( V_143 . type ) {
case V_176 :
V_8 -> V_2 . V_202 = F_79 ;
break;
case V_184 :
V_8 -> V_2 . V_136 = F_76 ;
V_8 -> V_2 . V_202 = V_203 ;
V_8 -> V_2 . V_33 = V_216 ;
V_106 |= V_195 ;
break;
default:
case V_220 :
case V_228 :
V_8 -> V_2 . V_202 = V_230 ;
}
V_8 -> V_76 = V_106 ;
V_87 = F_88 ( V_8 , & V_143 ) ;
if ( V_87 )
goto V_204;
V_54 = F_3 ( V_8 -> V_58 . V_49 , V_8 -> V_58 . V_48 ) ;
F_29 ( V_8 , V_54 , & V_8 ) ;
F_130 ( V_44 , & V_8 -> V_2 ) ;
V_205:
if ( V_130 )
F_111 ( V_130 ) ;
if ( V_177 )
F_119 ( & V_143 ) ;
F_105 ( V_216 ) ;
if ( V_217 )
F_105 ( V_217 ) ;
V_109:
return V_87 ;
V_193:
V_87 = - V_131 ;
goto V_205;
V_198:
V_87 = - V_206 ;
goto V_205;
V_204:
F_35 ( & V_8 -> V_2 ) ;
goto V_205;
}
static int F_49 ( struct V_43 * V_44 )
{
struct V_7 * V_8 ;
struct V_70 * V_71 = F_44 ( V_44 ) ;
unsigned V_54 = F_3 ( V_71 -> V_3 , V_71 -> V_2 ) ;
if ( F_77 ( V_44 ) )
return 0 ;
F_97 () ;
for( V_8 = F_66 ( V_18 [ V_54 ] . V_19 ) ; V_8 != NULL ;
V_8 = F_66 ( V_8 -> V_2 . V_23 ) ) {
if ( ( V_8 -> V_58 . V_49 == V_71 -> V_3 ) &&
( V_8 -> V_58 . V_48 == V_71 -> V_2 ) &&
( V_8 -> V_58 . V_52 == 0 ) &&
( V_8 -> V_58 . V_50 == V_44 -> V_219 ) &&
( V_8 -> V_58 . V_53 == V_71 -> V_111 ) ) {
F_31 ( & V_8 -> V_2 , V_15 ) ;
F_98 () ;
F_130 ( V_44 , (struct V_1 * ) V_8 ) ;
return 0 ;
}
}
F_98 () ;
return F_129 ( V_44 ) ;
}
static int F_131 ( struct V_43 * V_44 , T_5 V_231 , T_5 V_232 ,
int V_233 , int V_234 , unsigned int V_106 )
{
struct V_7 * V_8 = (struct V_7 * ) F_77 ( V_44 ) ;
struct V_235 * V_224 ;
struct V_236 * V_237 ;
unsigned char * V_238 = F_132 ( V_44 ) ;
long V_69 ;
V_237 = F_133 ( V_44 , V_231 , V_232 , V_233 , sizeof( * V_224 ) , V_106 ) ;
V_224 = F_134 ( V_237 ) ;
V_224 -> V_239 = V_240 ;
V_224 -> V_241 = 16 ;
V_224 -> V_242 = 0 ;
V_224 -> V_243 = 0 ;
V_224 -> V_244 = V_245 ;
F_135 ( V_44 , V_246 , V_245 ) ;
V_224 -> V_247 = V_8 -> V_152 ;
V_224 -> V_248 = ( V_8 -> V_76 & ~ 0xFFFF ) | V_249 ;
V_224 -> V_250 = V_173 ;
V_224 -> V_251 = V_252 ;
if ( V_8 -> V_76 & V_253 )
V_224 -> V_248 |= V_254 ;
F_136 ( V_44 , V_255 , 2 , & V_8 -> V_133 ) ;
if ( V_8 -> V_58 . V_49 ) {
V_224 -> V_242 = 16 ;
F_136 ( V_44 , V_256 , 2 , & V_8 -> V_58 . V_49 ) ;
}
if ( V_8 -> V_2 . V_33 )
F_136 ( V_44 , V_257 , sizeof( int ) , & V_8 -> V_2 . V_33 -> V_112 ) ;
F_136 ( V_44 , V_258 , 2 , & V_8 -> V_199 ) ;
if ( V_8 -> V_133 != V_8 -> V_150 )
F_136 ( V_44 , V_259 , 2 , & V_8 -> V_150 ) ;
if ( F_137 ( V_44 , F_138 ( & V_8 -> V_2 ) ) < 0 )
goto V_260;
V_69 = V_8 -> V_2 . V_69 ? V_8 -> V_2 . V_69 - V_15 : 0 ;
if ( F_139 ( V_44 , & V_8 -> V_2 , 0 , 0 , 0 , V_69 ,
V_8 -> V_2 . error ) < 0 )
goto V_260;
if ( F_140 ( V_8 ) )
F_136 ( V_44 , V_261 , sizeof( int ) , & V_8 -> V_58 . V_53 ) ;
V_237 -> V_262 = F_132 ( V_44 ) - V_238 ;
return V_44 -> V_92 ;
V_263:
V_260:
F_141 ( V_44 , V_238 ) ;
return - 1 ;
}
static int F_142 ( struct V_43 * V_264 , struct V_236 * V_237 , void * V_265 )
{
struct V_266 * V_266 = F_143 ( V_264 -> V_212 ) ;
struct V_267 * * V_268 = V_265 ;
struct V_235 * V_269 = F_134 ( V_237 ) ;
struct V_7 * V_8 = NULL ;
struct V_70 * V_71 ;
int V_87 ;
struct V_43 * V_44 ;
struct V_45 V_58 ;
if ( ! F_67 ( V_266 , & V_107 ) )
return - V_131 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_209 = V_270 ;
V_44 = F_144 ( V_271 , V_272 ) ;
if ( V_44 == NULL )
return - V_206 ;
F_145 ( V_44 ) ;
V_71 = F_44 ( V_44 ) ;
if ( V_268 [ V_256 - 1 ] )
memcpy ( & V_58 . V_49 , F_146 ( V_268 [ V_256 - 1 ] ) , 2 ) ;
if ( V_268 [ V_255 - 1 ] )
memcpy ( & V_58 . V_48 , F_146 ( V_268 [ V_255 - 1 ] ) , 2 ) ;
if ( V_268 [ V_261 - 1 ] )
memcpy ( & V_58 . V_53 , F_146 ( V_268 [ V_261 - 1 ] ) , sizeof( int ) ) ;
if ( V_58 . V_53 ) {
struct V_102 * V_33 ;
if ( ( V_33 = F_104 ( & V_107 , V_58 . V_53 ) ) == NULL ) {
F_53 ( V_44 ) ;
return - V_179 ;
}
if ( ! V_33 -> V_34 ) {
F_105 ( V_33 ) ;
F_53 ( V_44 ) ;
return - V_179 ;
}
V_44 -> V_273 = F_147 ( V_274 ) ;
V_44 -> V_33 = V_33 ;
V_71 -> V_3 = V_58 . V_49 ;
V_71 -> V_2 = V_58 . V_48 ;
F_148 () ;
V_87 = F_49 ( V_44 ) ;
F_149 () ;
memset ( V_71 , 0 , sizeof( struct V_70 ) ) ;
V_8 = (struct V_7 * ) F_77 ( V_44 ) ;
if ( ! V_87 && - V_8 -> V_2 . error )
V_87 = V_8 -> V_2 . error ;
} else {
int V_275 = 0 ;
if ( V_268 [ V_257 - 1 ] )
memcpy ( & V_275 , F_146 ( V_268 [ V_257 - 1 ] ) , sizeof( int ) ) ;
V_58 . V_52 = V_275 ;
V_87 = F_125 ( (struct V_1 * * ) & V_8 , & V_58 , 0 ) ;
}
if ( V_44 -> V_33 )
F_105 ( V_44 -> V_33 ) ;
V_44 -> V_33 = NULL ;
if ( V_87 )
goto V_276;
F_130 ( V_44 , & V_8 -> V_2 ) ;
if ( V_269 -> V_248 & V_254 )
V_8 -> V_76 |= V_253 ;
V_87 = F_131 ( V_44 , F_150 ( V_264 ) . V_231 , V_237 -> V_277 , V_278 , 0 , 0 ) ;
if ( V_87 == 0 )
goto V_276;
if ( V_87 < 0 ) {
V_87 = - V_279 ;
goto V_276;
}
return F_151 ( V_44 , & V_107 , F_150 ( V_264 ) . V_231 ) ;
V_276:
F_53 ( V_44 ) ;
return V_87 ;
}
int F_152 ( struct V_43 * V_44 , struct V_280 * V_71 )
{
struct V_266 * V_266 = F_143 ( V_44 -> V_212 ) ;
struct V_7 * V_8 ;
int V_281 , V_282 ;
int V_283 , V_284 ;
if ( ! F_67 ( V_266 , & V_107 ) )
return 0 ;
if ( F_153 ( V_71 -> V_237 , 0 ) < sizeof( struct V_235 ) )
return - V_131 ;
if ( ! ( ( (struct V_235 * ) F_134 ( V_71 -> V_237 ) ) -> V_248 & V_249 ) )
return 0 ;
V_282 = V_71 -> args [ 0 ] ;
V_284 = V_283 = V_71 -> args [ 1 ] ;
for( V_281 = 0 ; V_281 <= V_6 ; V_281 ++ ) {
if ( V_281 < V_282 )
continue;
if ( V_281 > V_282 )
V_284 = 0 ;
F_121 () ;
for( V_8 = F_122 ( V_18 [ V_281 ] . V_19 ) , V_283 = 0 ;
V_8 ;
V_8 = F_122 ( V_8 -> V_2 . V_23 ) , V_283 ++ ) {
if ( V_283 < V_284 )
continue;
F_130 ( V_44 , F_154 ( & V_8 -> V_2 ) ) ;
if ( F_131 ( V_44 , F_150 ( V_71 -> V_44 ) . V_231 ,
V_71 -> V_237 -> V_277 , V_278 ,
1 , V_285 ) <= 0 ) {
F_155 ( V_44 ) ;
F_124 () ;
goto V_205;
}
F_155 ( V_44 ) ;
}
F_124 () ;
}
V_205:
V_71 -> args [ 0 ] = V_281 ;
V_71 -> args [ 1 ] = V_283 ;
return V_44 -> V_92 ;
}
static struct V_7 * F_156 ( struct V_286 * V_232 )
{
struct V_7 * V_8 = NULL ;
struct V_287 * V_288 = V_232 -> V_289 ;
for( V_288 -> V_290 = V_6 ; V_288 -> V_290 >= 0 ; -- V_288 -> V_290 ) {
F_121 () ;
V_8 = F_122 ( V_18 [ V_288 -> V_290 ] . V_19 ) ;
if ( V_8 )
break;
F_124 () ;
}
return V_8 ;
}
static struct V_7 * F_157 ( struct V_286 * V_232 , struct V_7 * V_8 )
{
struct V_287 * V_288 = V_232 -> V_289 ;
V_8 = F_122 ( V_8 -> V_2 . V_23 ) ;
while ( ! V_8 ) {
F_124 () ;
if ( -- V_288 -> V_290 < 0 )
break;
F_121 () ;
V_8 = F_122 ( V_18 [ V_288 -> V_290 ] . V_19 ) ;
}
return V_8 ;
}
static void * F_158 ( struct V_286 * V_232 , T_7 * V_291 )
{
struct V_7 * V_8 = F_156 ( V_232 ) ;
if ( V_8 ) {
while( * V_291 && ( V_8 = F_157 ( V_232 , V_8 ) ) )
-- * V_291 ;
}
return * V_291 ? NULL : V_8 ;
}
static void * F_159 ( struct V_286 * V_232 , void * V_292 , T_7 * V_291 )
{
struct V_7 * V_8 = F_157 ( V_232 , V_292 ) ;
++ * V_291 ;
return V_8 ;
}
static void F_160 ( struct V_286 * V_232 , void * V_292 )
{
if ( V_292 )
F_124 () ;
}
static int F_161 ( struct V_286 * V_232 , void * V_292 )
{
struct V_7 * V_8 = V_292 ;
char V_293 [ V_294 ] , V_295 [ V_294 ] ;
F_162 ( V_232 , L_12 ,
V_8 -> V_2 . V_33 ? V_8 -> V_2 . V_33 -> V_90 : L_13 ,
F_163 ( F_52 ( V_8 -> V_133 ) , V_293 ) ,
F_163 ( F_52 ( V_8 -> V_132 ) , V_295 ) ,
F_12 ( & V_8 -> V_2 . V_21 ) ,
V_8 -> V_2 . V_296 ,
( int ) F_20 ( & V_8 -> V_2 , V_297 ) ) ;
return 0 ;
}
static int F_164 ( struct V_298 * V_298 , struct V_299 * V_299 )
{
return F_165 ( V_299 , & V_300 ,
sizeof( struct V_287 ) ) ;
}
void T_8 F_166 ( void )
{
int V_12 , V_301 , V_302 ;
V_196 . V_303 =
F_167 ( L_14 , sizeof( struct V_7 ) , 0 ,
V_304 | V_305 , NULL ) ;
F_168 ( & V_196 ) ;
F_169 ( & V_24 , F_8 , 0 ) ;
V_24 . V_69 = V_15 + V_25 * V_17 ;
F_39 ( & V_24 ) ;
V_301 = V_306 >> ( 26 - V_307 ) ;
for( V_302 = 0 ; ( 1UL << V_302 ) < V_301 ; V_302 ++ )
;
while( V_302 && ( ( ( ( 1UL << V_302 ) * V_308 ) /
sizeof( struct V_309 ) ) >= 2048 ) )
V_302 -- ;
do {
V_6 = ( 1UL << V_302 ) * V_308 /
sizeof( struct V_309 ) ;
while( V_6 & ( V_6 - 1 ) )
V_6 -- ;
V_18 = (struct V_309 * )
F_170 ( V_74 , V_302 ) ;
} while ( V_18 == NULL && -- V_302 > 0 );
if ( ! V_18 )
F_171 ( L_15 ) ;
F_51 ( V_310
L_16 ,
V_6 ,
( long ) ( V_6 * sizeof( struct V_309 ) ) / 1024 ) ;
V_6 -- ;
for( V_12 = 0 ; V_12 <= V_6 ; V_12 ++ ) {
F_172 ( & V_18 [ V_12 ] . V_20 ) ;
V_18 [ V_12 ] . V_19 = NULL ;
}
V_196 . V_311 = ( V_6 + 1 ) ;
F_173 ( & V_107 , L_17 , V_312 , & V_313 ) ;
#ifdef F_174
F_175 ( V_314 , V_315 , F_142 , V_316 ) ;
#else
F_175 ( V_314 , V_315 , F_142 ,
F_152 ) ;
#endif
}
void T_9 F_176 ( void )
{
F_38 ( & V_24 ) ;
F_32 ( 0 ) ;
F_177 ( & V_107 , L_17 ) ;
F_178 ( & V_196 ) ;
}
