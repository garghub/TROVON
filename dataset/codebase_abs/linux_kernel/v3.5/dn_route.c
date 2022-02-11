static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static T_1 unsigned int F_3 ( T_2 V_3 , T_2 V_2 )
{
T_3 V_4 = ( T_3 V_5 ) ( V_3 ^ V_2 ) ;
V_4 ^= ( V_4 >> 3 ) ;
V_4 ^= ( V_4 >> 5 ) ;
V_4 ^= ( V_4 >> 10 ) ;
return V_6 & ( unsigned int ) V_4 ;
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
struct V_29 * V_30 = F_19 ( V_2 ) ;
T_5 V_31 = 230 ;
struct V_32 * V_33 ;
V_33 = V_30 ? F_20 ( V_30 -> V_34 -> V_35 ) : NULL ;
if ( V_33 && V_33 -> V_36 == 0 )
V_31 -= 6 ;
else
V_31 -= 21 ;
if ( F_21 ( V_2 , V_37 ) > V_28 && V_28 >= V_31 ) {
if ( ! ( F_22 ( V_2 , V_37 ) ) ) {
F_23 ( V_2 , V_37 , V_28 ) ;
F_24 ( V_2 , V_38 ) ;
}
if ( ! ( F_22 ( V_2 , V_39 ) ) ) {
T_5 V_40 = V_28 - V_41 ;
T_5 V_42 = F_25 ( V_2 , V_39 ) ;
if ( ! V_42 || V_42 > V_40 )
F_23 ( V_2 , V_39 , V_40 ) ;
}
}
}
static struct V_1 * F_26 ( struct V_1 * V_2 , T_6 V_43 )
{
return NULL ;
}
static struct V_1 * F_27 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
return NULL ;
}
static void F_28 ( struct V_44 * V_45 )
{
}
static inline int F_29 ( struct V_46 * V_47 , struct V_46 * V_48 )
{
return ( ( V_47 -> V_49 ^ V_48 -> V_49 ) |
( V_47 -> V_50 ^ V_48 -> V_50 ) |
( V_47 -> V_51 ^ V_48 -> V_51 ) |
( V_47 -> V_52 ^ V_48 -> V_52 ) |
( V_47 -> V_53 ^ V_48 -> V_53 ) |
( V_47 -> V_54 ^ V_48 -> V_54 ) ) == 0 ;
}
static int F_30 ( struct V_7 * V_8 , unsigned int V_55 , struct V_7 * * V_56 )
{
struct V_7 * V_57 ;
struct V_7 T_4 * * V_58 ;
unsigned long V_14 = V_15 ;
V_58 = & V_18 [ V_55 ] . V_19 ;
F_16 ( & V_18 [ V_55 ] . V_20 ) ;
while ( ( V_57 = F_10 ( * V_58 ,
F_11 ( & V_18 [ V_55 ] . V_20 ) ) ) != NULL ) {
if ( F_29 ( & V_57 -> V_59 , & V_8 -> V_59 ) ) {
* V_58 = V_57 -> V_2 . V_23 ;
F_31 ( V_57 -> V_2 . V_23 ,
V_18 [ V_55 ] . V_19 ) ;
F_31 ( V_18 [ V_55 ] . V_19 , V_57 ) ;
F_32 ( & V_57 -> V_2 , V_14 ) ;
F_17 ( & V_18 [ V_55 ] . V_20 ) ;
F_6 ( V_8 ) ;
* V_56 = V_57 ;
return 0 ;
}
V_58 = & V_57 -> V_2 . V_23 ;
}
F_31 ( V_8 -> V_2 . V_23 , V_18 [ V_55 ] . V_19 ) ;
F_31 ( V_18 [ V_55 ] . V_19 , V_8 ) ;
F_32 ( & V_8 -> V_2 , V_14 ) ;
F_17 ( & V_18 [ V_55 ] . V_20 ) ;
* V_56 = V_8 ;
return 0 ;
}
static void F_33 ( unsigned long V_11 )
{
int V_12 ;
struct V_7 * V_8 , * V_60 ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
F_16 ( & V_18 [ V_12 ] . V_20 ) ;
if ( ( V_8 = F_34 ( (struct V_7 * * ) & V_18 [ V_12 ] . V_19 , NULL ) ) == NULL )
goto V_61;
for(; V_8 ; V_8 = V_60 ) {
V_60 = F_20 ( V_8 -> V_2 . V_23 ) ;
F_35 ( V_8 -> V_2 . V_23 , NULL ) ;
F_36 ( (struct V_1 * ) V_8 ) ;
}
V_61:
F_17 ( & V_18 [ V_12 ] . V_20 ) ;
}
}
void F_37 ( int V_62 )
{
unsigned long V_14 = V_15 ;
int V_63 = ! F_38 () ;
if ( V_62 < 0 )
V_62 = V_64 ;
F_16 ( & V_65 ) ;
if ( F_39 ( & V_66 ) && V_62 > 0 && V_67 ) {
long V_68 = ( long ) ( V_67 - V_14 ) ;
if ( V_63 && V_68 < V_69 - V_64 )
V_68 = 0 ;
if ( V_62 > V_68 )
V_62 = V_68 ;
}
if ( V_62 <= 0 ) {
F_17 ( & V_65 ) ;
F_33 ( 0 ) ;
return;
}
if ( V_67 == 0 )
V_67 = V_14 + V_69 ;
V_66 . V_70 = V_14 + V_62 ;
F_40 ( & V_66 ) ;
F_17 ( & V_65 ) ;
}
static int F_41 ( struct V_44 * V_45 )
{
struct V_71 * V_72 ;
unsigned char * V_73 ;
T_2 * V_3 ;
T_2 * V_2 ;
F_42 ( V_45 , V_45 -> V_74 - F_43 ( V_45 ) ) ;
if ( ( V_45 = F_44 ( V_45 , V_75 ) ) == NULL )
return V_76 ;
V_72 = F_45 ( V_45 ) ;
V_73 = V_45 -> V_74 + 2 ;
* V_73 ++ = ( V_72 -> V_77 & ~ V_78 ) | V_79 ;
V_2 = ( T_2 * ) V_73 ;
V_73 += 2 ;
V_3 = ( T_2 * ) V_73 ;
V_73 += 2 ;
* V_73 = 0 ;
F_46 ( * V_3 , * V_2 ) ;
V_45 -> V_80 = V_81 ;
F_47 ( V_45 , NULL , NULL ) ;
return V_82 ;
}
static int F_48 ( struct V_44 * V_45 )
{
struct V_71 * V_72 ;
unsigned char * V_73 ;
unsigned char * V_83 , * V_84 ;
unsigned char V_4 [ V_85 ] ;
F_42 ( V_45 , V_45 -> V_74 - F_43 ( V_45 ) ) ;
if ( ( V_45 = F_44 ( V_45 , V_75 ) ) == NULL )
return V_76 ;
V_72 = F_45 ( V_45 ) ;
V_73 = V_45 -> V_74 + 2 ;
if ( * V_73 & V_86 ) {
char V_87 = ( * V_73 & ~ V_86 ) ;
V_73 += V_87 ;
}
* V_73 ++ = ( V_72 -> V_77 & ~ V_78 ) | V_79 ;
V_73 += 2 ;
V_84 = V_73 ;
V_73 += 8 ;
V_83 = V_73 ;
V_73 += 6 ;
* V_73 = 0 ;
memcpy ( V_4 , V_83 , V_85 ) ;
memcpy ( V_83 , V_84 , V_85 ) ;
memcpy ( V_84 , V_4 , V_85 ) ;
V_45 -> V_80 = V_81 ;
F_47 ( V_45 , V_84 , V_83 ) ;
return V_82 ;
}
static int F_49 ( struct V_44 * V_45 )
{
struct V_71 * V_72 ;
int V_88 ;
if ( ( V_88 = F_50 ( V_45 ) ) == 0 )
return F_51 ( V_45 ) ;
V_72 = F_45 ( V_45 ) ;
if ( V_89 & 4 ) {
char * V_90 = V_45 -> V_34 ? V_45 -> V_34 -> V_91 : L_1 ;
F_52 ( V_92
L_2 ,
( int ) V_72 -> V_77 , V_90 , V_45 -> V_93 ,
F_53 ( V_72 -> V_3 ) , F_53 ( V_72 -> V_2 ) ,
V_88 , V_45 -> V_80 ) ;
}
if ( ( V_45 -> V_80 == V_94 ) && ( V_72 -> V_77 & V_78 ) ) {
switch ( V_72 -> V_77 & V_95 ) {
case V_96 :
return F_41 ( V_45 ) ;
case V_97 :
return F_48 ( V_45 ) ;
}
}
F_54 ( V_45 ) ;
return V_76 ;
}
static int F_55 ( struct V_44 * V_45 )
{
struct V_71 * V_72 = F_45 ( V_45 ) ;
unsigned char * V_73 = V_45 -> V_74 ;
if ( ! F_56 ( V_45 , 21 ) )
goto V_98;
F_57 ( V_45 , 20 ) ;
F_58 ( V_45 ) ;
V_73 += 2 ;
V_72 -> V_2 = F_59 ( V_73 ) ;
if ( memcmp ( V_73 , V_99 , 4 ) != 0 )
goto V_98;
V_73 += 6 ;
V_73 += 2 ;
V_72 -> V_3 = F_59 ( V_73 ) ;
if ( memcmp ( V_73 , V_99 , 4 ) != 0 )
goto V_98;
V_73 += 6 ;
V_73 ++ ;
V_72 -> V_100 = * V_73 ++ ;
return F_60 ( V_101 , V_102 , V_45 , V_45 -> V_34 , NULL ,
F_49 ) ;
V_98:
F_54 ( V_45 ) ;
return V_76 ;
}
static int F_61 ( struct V_44 * V_45 )
{
struct V_71 * V_72 = F_45 ( V_45 ) ;
unsigned char * V_73 = V_45 -> V_74 ;
if ( ! F_56 ( V_45 , 6 ) )
goto V_98;
F_57 ( V_45 , 5 ) ;
F_58 ( V_45 ) ;
V_72 -> V_2 = * ( T_2 * ) V_73 ;
V_73 += 2 ;
V_72 -> V_3 = * ( T_2 * ) V_73 ;
V_73 += 2 ;
V_72 -> V_100 = * V_73 & 0x3f ;
return F_60 ( V_101 , V_102 , V_45 , V_45 -> V_34 , NULL ,
F_49 ) ;
V_98:
F_54 ( V_45 ) ;
return V_76 ;
}
static int F_62 ( struct V_44 * V_45 )
{
F_54 ( V_45 ) ;
return V_82 ;
}
static int F_63 ( struct V_44 * V_45 )
{
F_64 ( V_45 ) ;
F_65 ( V_45 ) ;
return V_82 ;
}
int F_66 ( struct V_44 * V_45 , struct V_103 * V_34 , struct V_104 * V_105 , struct V_103 * V_106 )
{
struct V_71 * V_72 ;
unsigned char V_107 = 0 ;
T_3 V_93 = F_53 ( * ( T_2 * ) V_45 -> V_74 ) ;
struct V_32 * V_33 = F_67 ( V_34 -> V_35 ) ;
unsigned char V_87 = 0 ;
if ( ! F_68 ( F_69 ( V_34 ) , & V_108 ) )
goto V_109;
if ( V_33 == NULL )
goto V_109;
if ( ( V_45 = F_70 ( V_45 , V_75 ) ) == NULL )
goto V_110;
if ( ! F_56 ( V_45 , 3 ) )
goto V_109;
F_57 ( V_45 , 2 ) ;
if ( V_93 > V_45 -> V_93 )
goto V_109;
F_71 ( V_45 , V_93 ) ;
V_107 = * V_45 -> V_74 ;
V_72 = F_45 ( V_45 ) ;
V_72 -> V_111 = V_15 ;
V_72 -> V_112 = V_34 -> V_113 ;
if ( V_107 & V_86 ) {
V_87 = V_107 & ~ V_86 ;
if ( ! F_56 ( V_45 , V_87 + 1 ) )
goto V_109;
F_57 ( V_45 , V_87 ) ;
V_107 = * V_45 -> V_74 ;
}
F_72 ( V_45 ) ;
if ( V_107 & V_114 )
goto V_109;
V_72 -> V_77 = V_107 ;
if ( V_89 & 1 )
F_52 ( V_92
L_3 ,
( int ) V_107 , ( V_34 ) ? V_34 -> V_91 : L_1 , V_93 , V_45 -> V_93 ,
V_87 ) ;
if ( V_107 & V_115 ) {
if ( F_73 ( F_74 ( V_45 ) ) )
goto V_109;
switch ( V_107 & V_116 ) {
case V_117 :
F_75 ( V_45 ) ;
break;
case V_118 :
F_76 ( V_45 ) ;
break;
}
if ( V_33 -> V_119 . V_120 != V_121 )
goto V_109;
switch ( V_107 & V_116 ) {
case V_122 :
return F_60 ( V_101 , V_123 ,
V_45 , V_45 -> V_34 , NULL ,
F_63 ) ;
case V_124 :
case V_125 :
return F_60 ( V_101 , V_126 ,
V_45 , V_45 -> V_34 , NULL ,
F_62 ) ;
case V_127 :
return F_60 ( V_101 , V_123 ,
V_45 , V_45 -> V_34 , NULL ,
V_128 ) ;
case V_129 :
return F_60 ( V_101 , V_123 ,
V_45 , V_45 -> V_34 , NULL ,
V_130 ) ;
}
} else {
if ( V_33 -> V_119 . V_120 != V_121 )
goto V_109;
F_57 ( V_45 , 1 ) ;
switch ( V_107 & V_95 ) {
case V_97 :
return F_55 ( V_45 ) ;
case V_96 :
return F_61 ( V_45 ) ;
}
}
V_109:
F_54 ( V_45 ) ;
V_110:
return V_76 ;
}
static int F_77 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_78 ( V_45 ) ;
struct V_29 * V_30 = F_19 ( V_2 ) ;
return V_30 -> V_131 ( V_30 , V_45 ) ;
}
static int F_79 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_78 ( V_45 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_2 ;
struct V_103 * V_34 = V_2 -> V_34 ;
struct V_71 * V_72 = F_45 ( V_45 ) ;
int V_88 = - V_132 ;
if ( F_19 ( V_2 ) == NULL )
goto error;
V_45 -> V_34 = V_34 ;
V_72 -> V_3 = V_8 -> V_133 ;
V_72 -> V_2 = V_8 -> V_134 ;
V_72 -> V_77 &= ~ V_78 ;
V_72 -> V_77 |= V_135 ;
V_72 -> V_100 = 0 ;
return F_60 ( V_101 , V_136 , V_45 , NULL , V_34 ,
F_77 ) ;
error:
F_80 ( L_4 ) ;
F_54 ( V_45 ) ;
return V_88 ;
}
static int F_81 ( struct V_44 * V_45 )
{
struct V_71 * V_72 = F_45 ( V_45 ) ;
struct V_1 * V_2 = F_78 ( V_45 ) ;
struct V_32 * V_137 = F_67 ( V_2 -> V_34 -> V_35 ) ;
struct V_7 * V_8 ;
int V_138 ;
#ifdef F_82
struct V_103 * V_34 = V_45 -> V_34 ;
#endif
if ( V_45 -> V_80 != V_94 )
goto V_139;
V_8 = (struct V_7 * ) F_78 ( V_45 ) ;
V_138 = V_137 -> V_36 ? 21 : 6 ;
if ( F_83 ( V_45 , F_84 ( V_8 -> V_2 . V_34 ) + V_138 ) )
goto V_139;
if ( ++ V_72 -> V_100 > 30 )
goto V_139;
V_45 -> V_34 = V_8 -> V_2 . V_34 ;
V_72 -> V_77 &= ~ V_135 ;
if ( V_8 -> V_77 & V_140 )
V_72 -> V_77 |= V_135 ;
return F_60 ( V_101 , V_141 , V_45 , V_34 , V_45 -> V_34 ,
F_77 ) ;
V_139:
F_54 ( V_45 ) ;
return V_76 ;
}
static int F_85 ( struct V_44 * V_45 )
{
struct V_71 * V_72 = F_45 ( V_45 ) ;
F_80 ( L_5 ,
F_53 ( V_72 -> V_3 ) , F_53 ( V_72 -> V_2 ) ) ;
F_54 ( V_45 ) ;
return V_76 ;
}
static unsigned int F_86 ( const struct V_1 * V_2 )
{
return F_87 ( V_2 -> V_34 , F_88 ( V_2 ) ) ;
}
static unsigned int F_89 ( const struct V_1 * V_2 )
{
unsigned int V_28 = F_25 ( V_2 , V_37 ) ;
return V_28 ? : V_2 -> V_34 -> V_28 ;
}
static struct V_29 * F_90 ( const struct V_1 * V_2 , const void * V_49 )
{
return F_91 ( & V_142 , V_49 , V_2 -> V_34 ) ;
}
static int F_92 ( struct V_7 * V_8 , struct V_143 * V_144 )
{
struct V_145 * V_146 = V_144 -> V_146 ;
struct V_103 * V_34 = V_8 -> V_2 . V_34 ;
unsigned int V_147 ;
struct V_29 * V_30 ;
if ( V_146 ) {
if ( F_93 ( * V_144 ) &&
F_94 ( * V_144 ) . V_148 == V_149 )
V_8 -> V_150 = F_93 ( * V_144 ) ;
F_95 ( & V_8 -> V_2 , V_146 -> V_151 , true ) ;
}
V_8 -> V_152 = V_144 -> type ;
if ( V_34 != NULL && F_19 ( & V_8 -> V_2 ) == NULL ) {
V_30 = F_91 ( & V_142 , & V_8 -> V_150 , V_34 ) ;
if ( F_96 ( V_30 ) )
return F_97 ( V_30 ) ;
F_98 ( & V_8 -> V_2 , V_30 ) ;
}
if ( F_21 ( & V_8 -> V_2 , V_37 ) > V_8 -> V_2 . V_34 -> V_28 )
F_23 ( & V_8 -> V_2 , V_37 , V_8 -> V_2 . V_34 -> V_28 ) ;
V_147 = F_25 ( & V_8 -> V_2 , V_39 ) ;
if ( V_147 ) {
unsigned int V_40 = F_87 ( V_34 , F_88 ( & V_8 -> V_2 ) ) ;
if ( V_147 > V_40 )
F_23 ( & V_8 -> V_2 , V_39 , V_40 ) ;
}
return 0 ;
}
static inline int F_99 ( T_2 V_153 , T_2 V_154 )
{
T_3 V_4 = F_53 ( V_153 ) ^ F_53 ( V_154 ) ;
int V_155 = 16 ;
while( V_4 ) {
V_4 >>= 1 ;
V_155 -- ;
}
return V_155 ;
}
static T_2 F_100 ( const struct V_103 * V_34 , T_2 V_49 , int V_156 )
{
T_2 V_50 = 0 ;
struct V_32 * V_137 ;
struct V_157 * V_158 ;
int V_159 = 0 ;
int V_160 ;
F_101 () ;
V_137 = F_67 ( V_34 -> V_35 ) ;
for ( V_158 = F_67 ( V_137 -> V_161 ) ;
V_158 != NULL ;
V_158 = F_67 ( V_158 -> V_162 ) ) {
if ( V_158 -> V_163 > V_156 )
continue;
if ( ! V_49 ) {
V_50 = V_158 -> V_164 ;
break;
}
V_160 = F_99 ( V_49 , V_158 -> V_164 ) ;
if ( V_160 > V_159 )
V_50 = V_158 -> V_164 ;
if ( V_159 == 0 )
V_50 = V_158 -> V_164 ;
}
F_102 () ;
return V_50 ;
}
static inline T_2 F_103 ( struct V_143 * V_144 )
{
return F_100 ( F_104 ( * V_144 ) , F_93 ( * V_144 ) , V_144 -> V_156 ) ;
}
static inline T_2 F_105 ( T_2 V_49 , struct V_143 * V_144 )
{
T_2 V_165 = F_106 ( V_144 -> V_166 ) ;
return ( V_49 & ~ V_165 ) | V_144 -> V_146 -> V_167 -> V_168 ;
}
static int F_107 ( struct V_1 * * V_169 , const struct V_46 * V_170 , int V_171 )
{
struct V_46 V_59 = {
. V_49 = V_170 -> V_49 ,
. V_50 = V_170 -> V_50 ,
. V_52 = V_172 ,
. V_51 = V_170 -> V_51 ,
. V_54 = V_108 . V_173 -> V_113 ,
. V_53 = V_170 -> V_53 ,
} ;
struct V_7 * V_8 = NULL ;
struct V_103 * V_174 = NULL , * V_34 ;
struct V_29 * V_175 = NULL ;
unsigned int V_55 ;
unsigned int V_107 = 0 ;
struct V_143 V_144 = { . V_146 = NULL , . type = V_176 } ;
int V_88 ;
int V_177 = 0 ;
T_2 V_178 = 0 ;
if ( V_89 & 16 )
F_52 ( V_92
L_6
L_7 , F_53 ( V_170 -> V_49 ) ,
F_53 ( V_170 -> V_50 ) ,
V_170 -> V_51 , V_108 . V_173 -> V_113 ,
V_170 -> V_53 ) ;
if ( V_170 -> V_53 ) {
V_174 = F_108 ( & V_108 , V_170 -> V_53 ) ;
V_88 = - V_179 ;
if ( V_174 && V_174 -> V_35 == NULL ) {
F_109 ( V_174 ) ;
V_174 = NULL ;
}
if ( V_174 == NULL )
goto V_110;
}
if ( V_170 -> V_50 ) {
V_88 = - V_180 ;
if ( V_174 ) {
if ( F_110 ( V_174 , V_170 -> V_50 ) )
goto V_181;
F_109 ( V_174 ) ;
goto V_110;
}
F_101 () ;
F_111 (&init_net, dev) {
if ( ! V_34 -> V_35 )
continue;
if ( ! F_110 ( V_34 , V_170 -> V_50 ) )
continue;
if ( ( V_34 -> V_107 & V_182 ) &&
V_170 -> V_49 &&
! F_110 ( V_34 , V_170 -> V_49 ) )
continue;
V_174 = V_34 ;
break;
}
F_102 () ;
if ( V_174 == NULL )
goto V_110;
F_112 ( V_174 ) ;
V_181:
;
}
if ( ! V_59 . V_49 ) {
V_59 . V_49 = V_59 . V_50 ;
V_88 = - V_180 ;
if ( V_174 )
F_109 ( V_174 ) ;
V_174 = V_108 . V_173 ;
F_112 ( V_174 ) ;
if ( ! V_59 . V_49 ) {
V_59 . V_49 =
V_59 . V_50 = F_100 ( V_174 , 0 ,
V_183 ) ;
if ( ! V_59 . V_49 )
goto V_110;
}
V_59 . V_53 = V_108 . V_173 -> V_113 ;
V_144 . type = V_184 ;
goto V_185;
}
if ( V_89 & 16 )
F_52 ( V_92
L_8
L_9 ,
F_53 ( V_59 . V_49 ) , F_53 ( V_59 . V_50 ) ,
V_59 . V_53 , V_171 ) ;
V_88 = - V_186 ;
if ( V_171 || ( V_88 = F_113 ( & V_59 , & V_144 ) ) != 0 ) {
struct V_32 * V_137 ;
if ( V_88 != - V_186 )
goto V_110;
if ( ! V_171 ) {
V_175 = F_114 ( & V_142 , & V_108 , & V_59 . V_49 ) ;
if ( V_175 ) {
if ( ( V_170 -> V_53 &&
( V_175 -> V_34 -> V_113 != V_170 -> V_53 ) ) ||
( V_170 -> V_50 &&
( ! F_110 ( V_175 -> V_34 ,
V_170 -> V_50 ) ) ) ) {
F_115 ( V_175 ) ;
V_175 = NULL ;
} else {
if ( V_174 )
F_109 ( V_174 ) ;
if ( F_110 ( V_175 -> V_34 , V_59 . V_49 ) ) {
V_174 = V_108 . V_173 ;
V_144 . type = V_184 ;
} else {
V_174 = V_175 -> V_34 ;
}
F_112 ( V_174 ) ;
goto V_187;
}
}
}
if ( V_174 == NULL )
V_174 = F_116 () ;
V_88 = - V_179 ;
if ( V_174 == NULL )
goto V_110;
V_137 = F_20 ( V_174 -> V_35 ) ;
if ( F_110 ( V_174 , V_59 . V_49 ) ) {
F_109 ( V_174 ) ;
V_174 = V_108 . V_173 ;
F_112 ( V_174 ) ;
V_144 . type = V_184 ;
goto V_187;
}
V_175 = F_117 ( V_137 -> V_188 ) ;
F_118 ( V_175 && V_175 -> V_34 != V_174 ) ;
V_187:
if ( V_175 )
V_178 = ( (struct V_189 * ) V_175 ) -> V_190 ;
if ( V_178 == 0 )
V_178 = V_59 . V_49 ;
if ( V_59 . V_50 == 0 ) {
V_59 . V_50 = F_100 ( V_174 , V_178 ,
V_144 . type == V_184 ?
V_183 :
V_149 ) ;
if ( V_59 . V_50 == 0 && V_144 . type != V_184 )
goto V_191;
}
V_59 . V_53 = V_174 -> V_113 ;
goto V_185;
}
V_177 = 1 ;
if ( V_144 . type == V_192 )
goto V_193;
if ( V_144 . type == V_184 ) {
if ( ! V_59 . V_50 )
V_59 . V_50 = V_59 . V_49 ;
if ( V_174 )
F_109 ( V_174 ) ;
V_174 = V_108 . V_173 ;
F_112 ( V_174 ) ;
V_59 . V_53 = V_174 -> V_113 ;
if ( V_144 . V_146 )
F_119 ( V_144 . V_146 ) ;
V_144 . V_146 = NULL ;
goto V_185;
}
if ( V_144 . V_146 -> V_194 > 1 && V_59 . V_53 == 0 )
F_120 ( & V_59 , & V_144 ) ;
if ( ! V_59 . V_50 )
V_59 . V_50 = F_121 ( V_144 ) ;
if ( V_174 )
F_109 ( V_174 ) ;
V_174 = F_104 ( V_144 ) ;
F_112 ( V_174 ) ;
V_59 . V_53 = V_174 -> V_113 ;
V_178 = F_93 ( V_144 ) ;
V_185:
if ( V_174 -> V_107 & V_182 )
V_107 |= V_195 ;
V_8 = F_122 ( & V_196 , V_174 , 1 , 0 , V_197 ) ;
if ( V_8 == NULL )
goto V_198;
memset ( & V_8 -> V_59 , 0 , sizeof( V_8 -> V_59 ) ) ;
V_8 -> V_59 . V_50 = V_170 -> V_50 ;
V_8 -> V_59 . V_49 = V_170 -> V_49 ;
V_8 -> V_59 . V_53 = V_170 -> V_53 ;
V_8 -> V_59 . V_54 = 0 ;
V_8 -> V_59 . V_51 = V_170 -> V_51 ;
V_8 -> V_133 = V_59 . V_50 ;
V_8 -> V_134 = V_59 . V_49 ;
V_8 -> V_150 = V_178 ? V_178 : V_59 . V_49 ;
V_8 -> V_199 = V_59 . V_50 ;
V_8 -> V_200 = V_59 . V_49 ;
V_8 -> V_201 = V_59 . V_50 ;
F_98 ( & V_8 -> V_2 , V_175 ) ;
V_175 = NULL ;
V_8 -> V_2 . V_22 = V_15 ;
V_8 -> V_2 . V_131 = F_79 ;
V_8 -> V_2 . V_202 = F_85 ;
V_8 -> V_77 = V_107 ;
if ( V_107 & V_195 )
V_8 -> V_2 . V_202 = V_203 ;
V_88 = F_92 ( V_8 , & V_144 ) ;
if ( V_88 )
goto V_204;
V_55 = F_3 ( V_8 -> V_59 . V_50 , V_8 -> V_59 . V_49 ) ;
F_30 ( V_8 , V_55 , (struct V_7 * * ) V_169 ) ;
V_205:
if ( V_175 )
F_115 ( V_175 ) ;
if ( V_177 )
F_123 ( & V_144 ) ;
if ( V_174 )
F_109 ( V_174 ) ;
V_110:
return V_88 ;
V_191:
V_88 = - V_180 ;
goto V_205;
V_193:
V_88 = - V_132 ;
goto V_205;
V_198:
V_88 = - V_206 ;
goto V_205;
V_204:
F_36 ( & V_8 -> V_2 ) ;
goto V_198;
}
static int F_124 ( struct V_1 * * V_169 , const struct V_46 * V_207 , int V_107 )
{
unsigned int V_55 = F_3 ( V_207 -> V_50 , V_207 -> V_49 ) ;
struct V_7 * V_8 = NULL ;
if ( ! ( V_107 & V_208 ) ) {
F_125 () ;
for ( V_8 = F_126 ( V_18 [ V_55 ] . V_19 ) ; V_8 ;
V_8 = F_126 ( V_8 -> V_2 . V_23 ) ) {
if ( ( V_207 -> V_49 == V_8 -> V_59 . V_49 ) &&
( V_207 -> V_50 == V_8 -> V_59 . V_50 ) &&
( V_207 -> V_51 == V_8 -> V_59 . V_51 ) &&
F_127 ( V_8 ) &&
( V_8 -> V_59 . V_53 == V_207 -> V_53 ) ) {
F_32 ( & V_8 -> V_2 , V_15 ) ;
F_128 () ;
* V_169 = & V_8 -> V_2 ;
return 0 ;
}
}
F_128 () ;
}
return F_107 ( V_169 , V_207 , V_107 ) ;
}
static int F_129 ( struct V_1 * * V_169 , struct V_46 * V_207 , int V_107 )
{
int V_88 ;
V_88 = F_124 ( V_169 , V_207 , V_107 ) ;
if ( V_88 == 0 && V_207 -> V_209 ) {
* V_169 = F_130 ( & V_108 , * V_169 ,
F_131 ( V_207 ) , NULL , 0 ) ;
if ( F_96 ( * V_169 ) ) {
V_88 = F_97 ( * V_169 ) ;
* V_169 = NULL ;
}
}
return V_88 ;
}
int F_132 ( struct V_1 * * V_169 , struct V_46 * V_210 , struct V_211 * V_212 , int V_107 )
{
int V_88 ;
V_88 = F_124 ( V_169 , V_210 , V_107 & V_208 ) ;
if ( V_88 == 0 && V_210 -> V_209 ) {
if ( ! ( V_107 & V_213 ) )
V_210 -> V_214 |= V_215 ;
* V_169 = F_130 ( & V_108 , * V_169 ,
F_131 ( V_210 ) , V_212 , 0 ) ;
if ( F_96 ( * V_169 ) ) {
V_88 = F_97 ( * V_169 ) ;
* V_169 = NULL ;
}
}
return V_88 ;
}
static int F_133 ( struct V_44 * V_45 )
{
struct V_7 * V_8 = NULL ;
struct V_71 * V_72 = F_45 ( V_45 ) ;
struct V_103 * V_216 = V_45 -> V_34 ;
struct V_103 * V_217 = NULL ;
struct V_32 * V_137 ;
struct V_29 * V_175 = NULL ;
unsigned int V_55 ;
int V_107 = 0 ;
T_2 V_178 = 0 ;
T_2 V_218 = 0 ;
struct V_46 V_59 = {
. V_49 = V_72 -> V_2 ,
. V_50 = V_72 -> V_3 ,
. V_52 = V_172 ,
. V_51 = V_45 -> V_219 ,
. V_54 = V_45 -> V_34 -> V_113 ,
} ;
struct V_143 V_144 = { . V_146 = NULL , . type = V_220 } ;
int V_88 = - V_132 ;
int V_177 = 0 ;
F_112 ( V_216 ) ;
if ( ( V_137 = F_67 ( V_216 -> V_35 ) ) == NULL )
goto V_110;
if ( V_59 . V_50 == 0 )
goto V_110;
V_88 = - V_221 ;
if ( F_110 ( V_216 , V_72 -> V_3 ) )
goto V_110;
V_88 = F_113 ( & V_59 , & V_144 ) ;
if ( V_88 ) {
if ( V_88 != - V_186 )
goto V_110;
if ( ! F_110 ( V_216 , V_72 -> V_2 ) )
goto V_193;
V_144 . type = V_184 ;
} else {
T_2 V_222 = V_59 . V_50 ;
V_177 = 1 ;
V_217 = F_104 ( V_144 ) ;
if ( V_217 == NULL ) {
F_134 ( L_10 ) ;
goto V_193;
}
F_112 ( V_217 ) ;
if ( V_144 . V_223 )
V_222 = V_59 . V_50 ;
V_178 = F_93 ( V_144 ) ;
if ( V_144 . type == V_192 ) {
V_59 . V_49 = F_105 ( V_59 . V_49 , & V_144 ) ;
F_123 ( & V_144 ) ;
V_177 = 0 ;
if ( F_113 ( & V_59 , & V_144 ) )
goto V_193;
V_177 = 1 ;
if ( V_144 . type != V_176 )
goto V_193;
V_107 |= V_224 ;
V_178 = V_59 . V_49 ;
}
V_59 . V_50 = V_222 ;
}
switch( V_144 . type ) {
case V_176 :
if ( V_137 -> V_119 . V_225 == 0 )
goto V_193;
if ( V_144 . V_146 -> V_194 > 1 && V_59 . V_53 == 0 )
F_120 ( & V_59 , & V_144 ) ;
if ( V_217 == V_216 && ! ( V_107 & V_226 ) )
V_107 |= V_140 ;
V_218 = F_121 ( V_144 ) ;
case V_227 :
case V_220 :
break;
case V_184 :
V_107 |= V_195 ;
V_59 . V_50 = V_72 -> V_2 ;
V_59 . V_49 = V_72 -> V_3 ;
if ( V_178 )
goto V_185;
if ( V_72 -> V_77 & V_135 ) {
V_178 = V_72 -> V_3 ;
V_107 |= V_228 ;
goto V_185;
}
V_175 = F_117 ( V_137 -> V_188 ) ;
if ( V_175 ) {
V_178 = ( (struct V_189 * ) V_175 ) -> V_190 ;
goto V_185;
}
V_178 = V_72 -> V_3 ;
V_107 |= V_228 ;
goto V_185;
default:
goto V_193;
}
V_185:
V_8 = F_122 ( & V_196 , V_217 , 0 , 0 , V_197 ) ;
if ( V_8 == NULL )
goto V_198;
memset ( & V_8 -> V_59 , 0 , sizeof( V_8 -> V_59 ) ) ;
V_8 -> V_133 = V_59 . V_50 ;
V_8 -> V_134 = V_59 . V_49 ;
V_8 -> V_150 = V_59 . V_49 ;
if ( V_178 )
V_8 -> V_150 = V_178 ;
V_8 -> V_199 = V_218 ? V_218 : V_8 -> V_133 ;
V_8 -> V_200 = V_59 . V_49 ;
V_8 -> V_201 = V_59 . V_50 ;
V_8 -> V_59 . V_50 = V_72 -> V_3 ;
V_8 -> V_59 . V_49 = V_72 -> V_2 ;
V_8 -> V_59 . V_53 = 0 ;
V_8 -> V_59 . V_54 = V_216 -> V_113 ;
V_8 -> V_59 . V_51 = V_59 . V_51 ;
F_98 ( & V_8 -> V_2 , V_175 ) ;
V_8 -> V_2 . V_22 = V_15 ;
V_8 -> V_2 . V_131 = F_85 ;
switch ( V_144 . type ) {
case V_176 :
V_8 -> V_2 . V_202 = F_81 ;
break;
case V_184 :
V_8 -> V_2 . V_131 = F_79 ;
V_8 -> V_2 . V_202 = V_203 ;
V_8 -> V_2 . V_34 = V_216 ;
V_107 |= V_195 ;
break;
default:
case V_220 :
case V_227 :
V_8 -> V_2 . V_202 = V_229 ;
}
V_8 -> V_77 = V_107 ;
V_88 = F_92 ( V_8 , & V_144 ) ;
if ( V_88 )
goto V_204;
V_55 = F_3 ( V_8 -> V_59 . V_50 , V_8 -> V_59 . V_49 ) ;
F_30 ( V_8 , V_55 , & V_8 ) ;
F_135 ( V_45 , & V_8 -> V_2 ) ;
V_205:
if ( V_175 )
F_115 ( V_175 ) ;
if ( V_177 )
F_123 ( & V_144 ) ;
F_109 ( V_216 ) ;
if ( V_217 )
F_109 ( V_217 ) ;
V_110:
return V_88 ;
V_193:
V_88 = - V_132 ;
goto V_205;
V_198:
V_88 = - V_206 ;
goto V_205;
V_204:
F_36 ( & V_8 -> V_2 ) ;
goto V_205;
}
static int F_50 ( struct V_44 * V_45 )
{
struct V_7 * V_8 ;
struct V_71 * V_72 = F_45 ( V_45 ) ;
unsigned int V_55 = F_3 ( V_72 -> V_3 , V_72 -> V_2 ) ;
if ( F_78 ( V_45 ) )
return 0 ;
F_101 () ;
for( V_8 = F_67 ( V_18 [ V_55 ] . V_19 ) ; V_8 != NULL ;
V_8 = F_67 ( V_8 -> V_2 . V_23 ) ) {
if ( ( V_8 -> V_59 . V_50 == V_72 -> V_3 ) &&
( V_8 -> V_59 . V_49 == V_72 -> V_2 ) &&
( V_8 -> V_59 . V_53 == 0 ) &&
( V_8 -> V_59 . V_51 == V_45 -> V_219 ) &&
( V_8 -> V_59 . V_54 == V_72 -> V_112 ) ) {
F_32 ( & V_8 -> V_2 , V_15 ) ;
F_102 () ;
F_135 ( V_45 , (struct V_1 * ) V_8 ) ;
return 0 ;
}
}
F_102 () ;
return F_133 ( V_45 ) ;
}
static int F_136 ( struct V_44 * V_45 , T_5 V_230 , T_5 V_231 ,
int V_232 , int V_233 , unsigned int V_107 )
{
struct V_7 * V_8 = (struct V_7 * ) F_78 ( V_45 ) ;
struct V_234 * V_223 ;
struct V_235 * V_236 ;
unsigned char * V_237 = F_137 ( V_45 ) ;
long V_70 ;
V_236 = F_138 ( V_45 , V_230 , V_231 , V_232 , sizeof( * V_223 ) , V_107 ) ;
V_223 = F_139 ( V_236 ) ;
V_223 -> V_238 = V_239 ;
V_223 -> V_240 = 16 ;
V_223 -> V_241 = 0 ;
V_223 -> V_242 = 0 ;
V_223 -> V_243 = V_244 ;
F_140 ( V_45 , V_245 , V_244 ) ;
V_223 -> V_246 = V_8 -> V_152 ;
V_223 -> V_247 = ( V_8 -> V_77 & ~ 0xFFFF ) | V_248 ;
V_223 -> V_249 = V_172 ;
V_223 -> V_250 = V_251 ;
if ( V_8 -> V_77 & V_252 )
V_223 -> V_247 |= V_253 ;
F_141 ( V_45 , V_254 , 2 , & V_8 -> V_134 ) ;
if ( V_8 -> V_59 . V_50 ) {
V_223 -> V_241 = 16 ;
F_141 ( V_45 , V_255 , 2 , & V_8 -> V_59 . V_50 ) ;
}
if ( V_8 -> V_2 . V_34 )
F_141 ( V_45 , V_256 , sizeof( int ) , & V_8 -> V_2 . V_34 -> V_113 ) ;
F_141 ( V_45 , V_257 , 2 , & V_8 -> V_199 ) ;
if ( V_8 -> V_134 != V_8 -> V_150 )
F_141 ( V_45 , V_258 , 2 , & V_8 -> V_150 ) ;
if ( F_142 ( V_45 , F_143 ( & V_8 -> V_2 ) ) < 0 )
goto V_259;
V_70 = V_8 -> V_2 . V_70 ? V_8 -> V_2 . V_70 - V_15 : 0 ;
if ( F_144 ( V_45 , & V_8 -> V_2 , 0 , 0 , 0 , V_70 ,
V_8 -> V_2 . error ) < 0 )
goto V_259;
if ( F_145 ( V_8 ) )
F_141 ( V_45 , V_260 , sizeof( int ) , & V_8 -> V_59 . V_54 ) ;
V_236 -> V_261 = F_137 ( V_45 ) - V_237 ;
return V_45 -> V_93 ;
V_262:
V_259:
F_146 ( V_45 , V_237 ) ;
return - 1 ;
}
static int F_147 ( struct V_44 * V_263 , struct V_235 * V_236 , void * V_264 )
{
struct V_265 * V_265 = F_148 ( V_263 -> V_212 ) ;
struct V_266 * * V_267 = V_264 ;
struct V_234 * V_268 = F_139 ( V_236 ) ;
struct V_7 * V_8 = NULL ;
struct V_71 * V_72 ;
int V_88 ;
struct V_44 * V_45 ;
struct V_46 V_59 ;
if ( ! F_68 ( V_265 , & V_108 ) )
return - V_132 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_209 = V_269 ;
V_45 = F_149 ( V_270 , V_271 ) ;
if ( V_45 == NULL )
return - V_206 ;
F_150 ( V_45 ) ;
V_72 = F_45 ( V_45 ) ;
if ( V_267 [ V_255 - 1 ] )
memcpy ( & V_59 . V_50 , F_151 ( V_267 [ V_255 - 1 ] ) , 2 ) ;
if ( V_267 [ V_254 - 1 ] )
memcpy ( & V_59 . V_49 , F_151 ( V_267 [ V_254 - 1 ] ) , 2 ) ;
if ( V_267 [ V_260 - 1 ] )
memcpy ( & V_59 . V_54 , F_151 ( V_267 [ V_260 - 1 ] ) , sizeof( int ) ) ;
if ( V_59 . V_54 ) {
struct V_103 * V_34 ;
if ( ( V_34 = F_108 ( & V_108 , V_59 . V_54 ) ) == NULL ) {
F_54 ( V_45 ) ;
return - V_179 ;
}
if ( ! V_34 -> V_35 ) {
F_109 ( V_34 ) ;
F_54 ( V_45 ) ;
return - V_179 ;
}
V_45 -> V_272 = F_152 ( V_273 ) ;
V_45 -> V_34 = V_34 ;
V_72 -> V_3 = V_59 . V_50 ;
V_72 -> V_2 = V_59 . V_49 ;
F_153 () ;
V_88 = F_50 ( V_45 ) ;
F_154 () ;
memset ( V_72 , 0 , sizeof( struct V_71 ) ) ;
V_8 = (struct V_7 * ) F_78 ( V_45 ) ;
if ( ! V_88 && - V_8 -> V_2 . error )
V_88 = V_8 -> V_2 . error ;
} else {
int V_274 = 0 ;
if ( V_267 [ V_256 - 1 ] )
memcpy ( & V_274 , F_151 ( V_267 [ V_256 - 1 ] ) , sizeof( int ) ) ;
V_59 . V_53 = V_274 ;
V_88 = F_129 ( (struct V_1 * * ) & V_8 , & V_59 , 0 ) ;
}
if ( V_45 -> V_34 )
F_109 ( V_45 -> V_34 ) ;
V_45 -> V_34 = NULL ;
if ( V_88 )
goto V_275;
F_135 ( V_45 , & V_8 -> V_2 ) ;
if ( V_268 -> V_247 & V_253 )
V_8 -> V_77 |= V_252 ;
V_88 = F_136 ( V_45 , F_155 ( V_263 ) . V_230 , V_236 -> V_276 , V_277 , 0 , 0 ) ;
if ( V_88 == 0 )
goto V_275;
if ( V_88 < 0 ) {
V_88 = - V_278 ;
goto V_275;
}
return F_156 ( V_45 , & V_108 , F_155 ( V_263 ) . V_230 ) ;
V_275:
F_54 ( V_45 ) ;
return V_88 ;
}
int F_157 ( struct V_44 * V_45 , struct V_279 * V_72 )
{
struct V_265 * V_265 = F_148 ( V_45 -> V_212 ) ;
struct V_7 * V_8 ;
int V_280 , V_281 ;
int V_282 , V_283 ;
if ( ! F_68 ( V_265 , & V_108 ) )
return 0 ;
if ( F_158 ( V_72 -> V_236 , 0 ) < sizeof( struct V_234 ) )
return - V_132 ;
if ( ! ( ( (struct V_234 * ) F_139 ( V_72 -> V_236 ) ) -> V_247 & V_248 ) )
return 0 ;
V_281 = V_72 -> args [ 0 ] ;
V_283 = V_282 = V_72 -> args [ 1 ] ;
for( V_280 = 0 ; V_280 <= V_6 ; V_280 ++ ) {
if ( V_280 < V_281 )
continue;
if ( V_280 > V_281 )
V_283 = 0 ;
F_125 () ;
for( V_8 = F_126 ( V_18 [ V_280 ] . V_19 ) , V_282 = 0 ;
V_8 ;
V_8 = F_126 ( V_8 -> V_2 . V_23 ) , V_282 ++ ) {
if ( V_282 < V_283 )
continue;
F_135 ( V_45 , F_159 ( & V_8 -> V_2 ) ) ;
if ( F_136 ( V_45 , F_155 ( V_72 -> V_45 ) . V_230 ,
V_72 -> V_236 -> V_276 , V_277 ,
1 , V_284 ) <= 0 ) {
F_160 ( V_45 ) ;
F_128 () ;
goto V_205;
}
F_160 ( V_45 ) ;
}
F_128 () ;
}
V_205:
V_72 -> args [ 0 ] = V_280 ;
V_72 -> args [ 1 ] = V_282 ;
return V_45 -> V_93 ;
}
static struct V_7 * F_161 ( struct V_285 * V_231 )
{
struct V_7 * V_8 = NULL ;
struct V_286 * V_287 = V_231 -> V_288 ;
for( V_287 -> V_289 = V_6 ; V_287 -> V_289 >= 0 ; -- V_287 -> V_289 ) {
F_125 () ;
V_8 = F_126 ( V_18 [ V_287 -> V_289 ] . V_19 ) ;
if ( V_8 )
break;
F_128 () ;
}
return V_8 ;
}
static struct V_7 * F_162 ( struct V_285 * V_231 , struct V_7 * V_8 )
{
struct V_286 * V_287 = V_231 -> V_288 ;
V_8 = F_126 ( V_8 -> V_2 . V_23 ) ;
while ( ! V_8 ) {
F_128 () ;
if ( -- V_287 -> V_289 < 0 )
break;
F_125 () ;
V_8 = F_126 ( V_18 [ V_287 -> V_289 ] . V_19 ) ;
}
return V_8 ;
}
static void * F_163 ( struct V_285 * V_231 , T_7 * V_290 )
{
struct V_7 * V_8 = F_161 ( V_231 ) ;
if ( V_8 ) {
while( * V_290 && ( V_8 = F_162 ( V_231 , V_8 ) ) )
-- * V_290 ;
}
return * V_290 ? NULL : V_8 ;
}
static void * F_164 ( struct V_285 * V_231 , void * V_291 , T_7 * V_290 )
{
struct V_7 * V_8 = F_162 ( V_231 , V_291 ) ;
++ * V_290 ;
return V_8 ;
}
static void F_165 ( struct V_285 * V_231 , void * V_291 )
{
if ( V_291 )
F_128 () ;
}
static int F_166 ( struct V_285 * V_231 , void * V_291 )
{
struct V_7 * V_8 = V_291 ;
char V_292 [ V_293 ] , V_294 [ V_293 ] ;
F_167 ( V_231 , L_11 ,
V_8 -> V_2 . V_34 ? V_8 -> V_2 . V_34 -> V_91 : L_12 ,
F_168 ( F_53 ( V_8 -> V_134 ) , V_292 ) ,
F_168 ( F_53 ( V_8 -> V_133 ) , V_294 ) ,
F_12 ( & V_8 -> V_2 . V_21 ) ,
V_8 -> V_2 . V_295 ,
( int ) F_21 ( & V_8 -> V_2 , V_296 ) ) ;
return 0 ;
}
static int F_169 ( struct V_297 * V_297 , struct V_298 * V_298 )
{
return F_170 ( V_298 , & V_299 ,
sizeof( struct V_286 ) ) ;
}
void T_8 F_171 ( void )
{
int V_12 , V_300 , V_301 ;
V_196 . V_302 =
F_172 ( L_13 , sizeof( struct V_7 ) , 0 ,
V_303 | V_304 , NULL ) ;
F_173 ( & V_196 ) ;
F_174 ( & V_24 , F_8 , 0 ) ;
V_24 . V_70 = V_15 + V_25 * V_17 ;
F_40 ( & V_24 ) ;
V_300 = V_305 >> ( 26 - V_306 ) ;
for( V_301 = 0 ; ( 1UL << V_301 ) < V_300 ; V_301 ++ )
;
while( V_301 && ( ( ( ( 1UL << V_301 ) * V_307 ) /
sizeof( struct V_308 ) ) >= 2048 ) )
V_301 -- ;
do {
V_6 = ( 1UL << V_301 ) * V_307 /
sizeof( struct V_308 ) ;
while( V_6 & ( V_6 - 1 ) )
V_6 -- ;
V_18 = (struct V_308 * )
F_175 ( V_75 , V_301 ) ;
} while ( V_18 == NULL && -- V_301 > 0 );
if ( ! V_18 )
F_176 ( L_14 ) ;
F_52 ( V_309
L_15 ,
V_6 ,
( long ) ( V_6 * sizeof( struct V_308 ) ) / 1024 ) ;
V_6 -- ;
for( V_12 = 0 ; V_12 <= V_6 ; V_12 ++ ) {
F_177 ( & V_18 [ V_12 ] . V_20 ) ;
V_18 [ V_12 ] . V_19 = NULL ;
}
V_196 . V_310 = ( V_6 + 1 ) ;
F_178 ( & V_108 , L_16 , V_311 , & V_312 ) ;
#ifdef F_179
F_180 ( V_313 , V_314 , F_147 ,
V_315 , NULL ) ;
#else
F_180 ( V_313 , V_314 , F_147 ,
F_157 , NULL ) ;
#endif
}
void T_9 F_181 ( void )
{
F_39 ( & V_24 ) ;
F_33 ( 0 ) ;
F_182 ( & V_108 , L_16 ) ;
F_183 ( & V_196 ) ;
}
