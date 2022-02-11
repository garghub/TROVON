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
static int F_30 ( struct V_7 * V_8 , unsigned V_55 , struct V_7 * * V_56 )
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
struct V_29 * V_132 ;
int V_88 = - V_133 ;
if ( ( V_132 = F_19 ( V_2 ) ) == NULL )
goto error;
V_45 -> V_34 = V_34 ;
V_72 -> V_3 = V_8 -> V_134 ;
V_72 -> V_2 = V_8 -> V_135 ;
V_72 -> V_77 &= ~ V_78 ;
V_72 -> V_77 |= V_136 ;
V_72 -> V_100 = 0 ;
return F_60 ( V_101 , V_137 , V_45 , NULL , V_34 ,
F_77 ) ;
error:
if ( F_80 () )
F_52 ( V_92 L_4 ) ;
F_54 ( V_45 ) ;
return V_88 ;
}
static int F_81 ( struct V_44 * V_45 )
{
struct V_71 * V_72 = F_45 ( V_45 ) ;
struct V_1 * V_2 = F_78 ( V_45 ) ;
struct V_32 * V_138 = F_67 ( V_2 -> V_34 -> V_35 ) ;
struct V_7 * V_8 ;
int V_139 ;
#ifdef F_82
struct V_103 * V_34 = V_45 -> V_34 ;
#endif
if ( V_45 -> V_80 != V_94 )
goto V_140;
V_8 = (struct V_7 * ) F_78 ( V_45 ) ;
V_139 = V_138 -> V_36 ? 21 : 6 ;
if ( F_83 ( V_45 , F_84 ( V_8 -> V_2 . V_34 ) + V_139 ) )
goto V_140;
if ( ++ V_72 -> V_100 > 30 )
goto V_140;
V_45 -> V_34 = V_8 -> V_2 . V_34 ;
V_72 -> V_77 &= ~ V_136 ;
if ( V_8 -> V_77 & V_141 )
V_72 -> V_77 |= V_136 ;
return F_60 ( V_101 , V_142 , V_45 , V_34 , V_45 -> V_34 ,
F_77 ) ;
V_140:
F_54 ( V_45 ) ;
return V_76 ;
}
static int F_85 ( struct V_44 * V_45 )
{
if ( F_80 () ) {
struct V_71 * V_72 = F_45 ( V_45 ) ;
F_52 ( V_92 L_5 ,
F_53 ( V_72 -> V_3 ) , F_53 ( V_72 -> V_2 ) ) ;
}
F_54 ( V_45 ) ;
return V_76 ;
}
static unsigned int F_86 ( const struct V_1 * V_2 )
{
return F_87 ( V_2 -> V_34 , F_88 ( V_2 ) ) ;
}
static unsigned int F_89 ( const struct V_1 * V_2 )
{
return V_2 -> V_34 -> V_28 ;
}
static struct V_29 * F_90 ( const struct V_1 * V_2 , const void * V_49 )
{
return F_91 ( & V_143 , V_49 , V_2 -> V_34 ) ;
}
static int F_92 ( struct V_7 * V_8 , struct V_144 * V_145 )
{
struct V_146 * V_147 = V_145 -> V_147 ;
struct V_103 * V_34 = V_8 -> V_2 . V_34 ;
unsigned int V_148 ;
struct V_29 * V_30 ;
if ( V_147 ) {
if ( F_93 ( * V_145 ) &&
F_94 ( * V_145 ) . V_149 == V_150 )
V_8 -> V_151 = F_93 ( * V_145 ) ;
F_95 ( & V_8 -> V_2 , V_147 -> V_152 , true ) ;
}
V_8 -> V_153 = V_145 -> type ;
if ( V_34 != NULL && F_19 ( & V_8 -> V_2 ) == NULL ) {
V_30 = F_91 ( & V_143 , & V_8 -> V_151 , V_34 ) ;
if ( F_96 ( V_30 ) )
return F_97 ( V_30 ) ;
F_98 ( & V_8 -> V_2 , V_30 ) ;
}
if ( F_21 ( & V_8 -> V_2 , V_37 ) > V_8 -> V_2 . V_34 -> V_28 )
F_23 ( & V_8 -> V_2 , V_37 , V_8 -> V_2 . V_34 -> V_28 ) ;
V_148 = F_25 ( & V_8 -> V_2 , V_39 ) ;
if ( V_148 ) {
unsigned int V_40 = F_87 ( V_34 , F_88 ( & V_8 -> V_2 ) ) ;
if ( V_148 > V_40 )
F_23 ( & V_8 -> V_2 , V_39 , V_40 ) ;
}
return 0 ;
}
static inline int F_99 ( T_2 V_154 , T_2 V_155 )
{
T_3 V_4 = F_53 ( V_154 ) ^ F_53 ( V_155 ) ;
int V_156 = 16 ;
while( V_4 ) {
V_4 >>= 1 ;
V_156 -- ;
}
return V_156 ;
}
static T_2 F_100 ( const struct V_103 * V_34 , T_2 V_49 , int V_157 )
{
T_2 V_50 = 0 ;
struct V_32 * V_138 ;
struct V_158 * V_159 ;
int V_160 = 0 ;
int V_161 ;
F_101 () ;
V_138 = F_67 ( V_34 -> V_35 ) ;
for ( V_159 = F_67 ( V_138 -> V_162 ) ;
V_159 != NULL ;
V_159 = F_67 ( V_159 -> V_163 ) ) {
if ( V_159 -> V_164 > V_157 )
continue;
if ( ! V_49 ) {
V_50 = V_159 -> V_165 ;
break;
}
V_161 = F_99 ( V_49 , V_159 -> V_165 ) ;
if ( V_161 > V_160 )
V_50 = V_159 -> V_165 ;
if ( V_160 == 0 )
V_50 = V_159 -> V_165 ;
}
F_102 () ;
return V_50 ;
}
static inline T_2 F_103 ( struct V_144 * V_145 )
{
return F_100 ( F_104 ( * V_145 ) , F_93 ( * V_145 ) , V_145 -> V_157 ) ;
}
static inline T_2 F_105 ( T_2 V_49 , struct V_144 * V_145 )
{
T_2 V_166 = F_106 ( V_145 -> V_167 ) ;
return ( V_49 & ~ V_166 ) | V_145 -> V_147 -> V_168 -> V_169 ;
}
static int F_107 ( struct V_1 * * V_170 , const struct V_46 * V_171 , int V_172 )
{
struct V_46 V_59 = {
. V_49 = V_171 -> V_49 ,
. V_50 = V_171 -> V_50 ,
. V_52 = V_173 ,
. V_51 = V_171 -> V_51 ,
. V_54 = V_108 . V_174 -> V_113 ,
. V_53 = V_171 -> V_53 ,
} ;
struct V_7 * V_8 = NULL ;
struct V_103 * V_175 = NULL , * V_34 ;
struct V_29 * V_132 = NULL ;
unsigned V_55 ;
unsigned V_107 = 0 ;
struct V_144 V_145 = { . V_147 = NULL , . type = V_176 } ;
int V_88 ;
int V_177 = 0 ;
T_2 V_178 = 0 ;
if ( V_89 & 16 )
F_52 ( V_92
L_6
L_7 , F_53 ( V_171 -> V_49 ) ,
F_53 ( V_171 -> V_50 ) ,
V_171 -> V_51 , V_108 . V_174 -> V_113 ,
V_171 -> V_53 ) ;
if ( V_171 -> V_53 ) {
V_175 = F_108 ( & V_108 , V_171 -> V_53 ) ;
V_88 = - V_179 ;
if ( V_175 && V_175 -> V_35 == NULL ) {
F_109 ( V_175 ) ;
V_175 = NULL ;
}
if ( V_175 == NULL )
goto V_110;
}
if ( V_171 -> V_50 ) {
V_88 = - V_180 ;
if ( V_175 ) {
if ( F_110 ( V_175 , V_171 -> V_50 ) )
goto V_181;
F_109 ( V_175 ) ;
goto V_110;
}
F_101 () ;
F_111 (&init_net, dev) {
if ( ! V_34 -> V_35 )
continue;
if ( ! F_110 ( V_34 , V_171 -> V_50 ) )
continue;
if ( ( V_34 -> V_107 & V_182 ) &&
V_171 -> V_49 &&
! F_110 ( V_34 , V_171 -> V_49 ) )
continue;
V_175 = V_34 ;
break;
}
F_102 () ;
if ( V_175 == NULL )
goto V_110;
F_112 ( V_175 ) ;
V_181:
;
}
if ( ! V_59 . V_49 ) {
V_59 . V_49 = V_59 . V_50 ;
V_88 = - V_180 ;
if ( V_175 )
F_109 ( V_175 ) ;
V_175 = V_108 . V_174 ;
F_112 ( V_175 ) ;
if ( ! V_59 . V_49 ) {
V_59 . V_49 =
V_59 . V_50 = F_100 ( V_175 , 0 ,
V_183 ) ;
if ( ! V_59 . V_49 )
goto V_110;
}
V_59 . V_53 = V_108 . V_174 -> V_113 ;
V_145 . type = V_184 ;
goto V_185;
}
if ( V_89 & 16 )
F_52 ( V_92
L_8
L_9 ,
F_53 ( V_59 . V_49 ) , F_53 ( V_59 . V_50 ) ,
V_59 . V_53 , V_172 ) ;
V_88 = - V_186 ;
if ( V_172 || ( V_88 = F_113 ( & V_59 , & V_145 ) ) != 0 ) {
struct V_32 * V_138 ;
if ( V_88 != - V_186 )
goto V_110;
if ( ! V_172 ) {
V_132 = F_114 ( & V_143 , & V_108 , & V_59 . V_49 ) ;
if ( V_132 ) {
if ( ( V_171 -> V_53 &&
( V_132 -> V_34 -> V_113 != V_171 -> V_53 ) ) ||
( V_171 -> V_50 &&
( ! F_110 ( V_132 -> V_34 ,
V_171 -> V_50 ) ) ) ) {
F_115 ( V_132 ) ;
V_132 = NULL ;
} else {
if ( V_175 )
F_109 ( V_175 ) ;
if ( F_110 ( V_132 -> V_34 , V_59 . V_49 ) ) {
V_175 = V_108 . V_174 ;
V_145 . type = V_184 ;
} else {
V_175 = V_132 -> V_34 ;
}
F_112 ( V_175 ) ;
goto V_187;
}
}
}
if ( V_175 == NULL )
V_175 = F_116 () ;
V_88 = - V_179 ;
if ( V_175 == NULL )
goto V_110;
V_138 = F_20 ( V_175 -> V_35 ) ;
if ( F_110 ( V_175 , V_59 . V_49 ) ) {
F_109 ( V_175 ) ;
V_175 = V_108 . V_174 ;
F_112 ( V_175 ) ;
V_145 . type = V_184 ;
goto V_187;
}
V_132 = F_117 ( V_138 -> V_188 ) ;
F_118 ( V_132 && V_132 -> V_34 != V_175 ) ;
V_187:
if ( V_132 )
V_178 = ( (struct V_189 * ) V_132 ) -> V_190 ;
if ( V_178 == 0 )
V_178 = V_59 . V_49 ;
if ( V_59 . V_50 == 0 ) {
V_59 . V_50 = F_100 ( V_175 , V_178 ,
V_145 . type == V_184 ?
V_183 :
V_150 ) ;
if ( V_59 . V_50 == 0 && V_145 . type != V_184 )
goto V_191;
}
V_59 . V_53 = V_175 -> V_113 ;
goto V_185;
}
V_177 = 1 ;
if ( V_145 . type == V_192 )
goto V_193;
if ( V_145 . type == V_184 ) {
if ( ! V_59 . V_50 )
V_59 . V_50 = V_59 . V_49 ;
if ( V_175 )
F_109 ( V_175 ) ;
V_175 = V_108 . V_174 ;
F_112 ( V_175 ) ;
V_59 . V_53 = V_175 -> V_113 ;
if ( V_145 . V_147 )
F_119 ( V_145 . V_147 ) ;
V_145 . V_147 = NULL ;
goto V_185;
}
if ( V_145 . V_147 -> V_194 > 1 && V_59 . V_53 == 0 )
F_120 ( & V_59 , & V_145 ) ;
if ( ! V_59 . V_50 )
V_59 . V_50 = F_121 ( V_145 ) ;
if ( V_175 )
F_109 ( V_175 ) ;
V_175 = F_104 ( V_145 ) ;
F_112 ( V_175 ) ;
V_59 . V_53 = V_175 -> V_113 ;
V_178 = F_93 ( V_145 ) ;
V_185:
if ( V_175 -> V_107 & V_182 )
V_107 |= V_195 ;
V_8 = F_122 ( & V_196 , V_175 , 1 , 0 , V_197 ) ;
if ( V_8 == NULL )
goto V_198;
memset ( & V_8 -> V_59 , 0 , sizeof( V_8 -> V_59 ) ) ;
V_8 -> V_59 . V_50 = V_171 -> V_50 ;
V_8 -> V_59 . V_49 = V_171 -> V_49 ;
V_8 -> V_59 . V_53 = V_171 -> V_53 ;
V_8 -> V_59 . V_54 = 0 ;
V_8 -> V_59 . V_51 = V_171 -> V_51 ;
V_8 -> V_134 = V_59 . V_50 ;
V_8 -> V_135 = V_59 . V_49 ;
V_8 -> V_151 = V_178 ? V_178 : V_59 . V_49 ;
V_8 -> V_199 = V_59 . V_50 ;
V_8 -> V_200 = V_59 . V_49 ;
V_8 -> V_201 = V_59 . V_50 ;
F_98 ( & V_8 -> V_2 , V_132 ) ;
V_132 = NULL ;
V_8 -> V_2 . V_22 = V_15 ;
V_8 -> V_2 . V_131 = F_79 ;
V_8 -> V_2 . V_202 = F_85 ;
V_8 -> V_77 = V_107 ;
if ( V_107 & V_195 )
V_8 -> V_2 . V_202 = V_203 ;
V_88 = F_92 ( V_8 , & V_145 ) ;
if ( V_88 )
goto V_204;
V_55 = F_3 ( V_8 -> V_59 . V_50 , V_8 -> V_59 . V_49 ) ;
F_30 ( V_8 , V_55 , (struct V_7 * * ) V_170 ) ;
V_205:
if ( V_132 )
F_115 ( V_132 ) ;
if ( V_177 )
F_123 ( & V_145 ) ;
if ( V_175 )
F_109 ( V_175 ) ;
V_110:
return V_88 ;
V_191:
V_88 = - V_180 ;
goto V_205;
V_193:
V_88 = - V_133 ;
goto V_205;
V_198:
V_88 = - V_206 ;
goto V_205;
V_204:
F_36 ( & V_8 -> V_2 ) ;
goto V_198;
}
static int F_124 ( struct V_1 * * V_170 , const struct V_46 * V_207 , int V_107 )
{
unsigned V_55 = F_3 ( V_207 -> V_50 , V_207 -> V_49 ) ;
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
* V_170 = & V_8 -> V_2 ;
return 0 ;
}
}
F_128 () ;
}
return F_107 ( V_170 , V_207 , V_107 ) ;
}
static int F_129 ( struct V_1 * * V_170 , struct V_46 * V_207 , int V_107 )
{
int V_88 ;
V_88 = F_124 ( V_170 , V_207 , V_107 ) ;
if ( V_88 == 0 && V_207 -> V_209 ) {
* V_170 = F_130 ( & V_108 , * V_170 ,
F_131 ( V_207 ) , NULL , 0 ) ;
if ( F_96 ( * V_170 ) ) {
V_88 = F_97 ( * V_170 ) ;
* V_170 = NULL ;
}
}
return V_88 ;
}
int F_132 ( struct V_1 * * V_170 , struct V_46 * V_210 , struct V_211 * V_212 , int V_107 )
{
int V_88 ;
V_88 = F_124 ( V_170 , V_210 , V_107 & V_208 ) ;
if ( V_88 == 0 && V_210 -> V_209 ) {
if ( ! ( V_107 & V_213 ) )
V_210 -> V_214 |= V_215 ;
* V_170 = F_130 ( & V_108 , * V_170 ,
F_131 ( V_210 ) , V_212 , 0 ) ;
if ( F_96 ( * V_170 ) ) {
V_88 = F_97 ( * V_170 ) ;
* V_170 = NULL ;
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
struct V_32 * V_138 ;
struct V_29 * V_132 = NULL ;
unsigned V_55 ;
int V_107 = 0 ;
T_2 V_178 = 0 ;
T_2 V_218 = 0 ;
struct V_46 V_59 = {
. V_49 = V_72 -> V_2 ,
. V_50 = V_72 -> V_3 ,
. V_52 = V_173 ,
. V_51 = V_45 -> V_219 ,
. V_54 = V_45 -> V_34 -> V_113 ,
} ;
struct V_144 V_145 = { . V_147 = NULL , . type = V_220 } ;
int V_88 = - V_133 ;
int V_177 = 0 ;
F_112 ( V_216 ) ;
if ( ( V_138 = F_67 ( V_216 -> V_35 ) ) == NULL )
goto V_110;
if ( V_59 . V_50 == 0 )
goto V_110;
V_88 = - V_221 ;
if ( F_110 ( V_216 , V_72 -> V_3 ) )
goto V_110;
V_88 = F_113 ( & V_59 , & V_145 ) ;
if ( V_88 ) {
if ( V_88 != - V_186 )
goto V_110;
if ( ! F_110 ( V_216 , V_72 -> V_2 ) )
goto V_193;
V_145 . type = V_184 ;
} else {
T_2 V_222 = V_59 . V_50 ;
V_177 = 1 ;
V_217 = F_104 ( V_145 ) ;
if ( V_217 == NULL ) {
if ( F_80 () )
F_52 ( V_223 L_10
L_11 ) ;
goto V_193;
}
F_112 ( V_217 ) ;
if ( V_145 . V_224 )
V_222 = V_59 . V_50 ;
V_178 = F_93 ( V_145 ) ;
if ( V_145 . type == V_192 ) {
V_59 . V_49 = F_105 ( V_59 . V_49 , & V_145 ) ;
F_123 ( & V_145 ) ;
V_177 = 0 ;
if ( F_113 ( & V_59 , & V_145 ) )
goto V_193;
V_177 = 1 ;
if ( V_145 . type != V_176 )
goto V_193;
V_107 |= V_225 ;
V_178 = V_59 . V_49 ;
}
V_59 . V_50 = V_222 ;
}
switch( V_145 . type ) {
case V_176 :
if ( V_138 -> V_119 . V_226 == 0 )
goto V_193;
if ( V_145 . V_147 -> V_194 > 1 && V_59 . V_53 == 0 )
F_120 ( & V_59 , & V_145 ) ;
if ( V_217 == V_216 && ! ( V_107 & V_227 ) )
V_107 |= V_141 ;
V_218 = F_121 ( V_145 ) ;
case V_228 :
case V_220 :
break;
case V_184 :
V_107 |= V_195 ;
V_59 . V_50 = V_72 -> V_2 ;
V_59 . V_49 = V_72 -> V_3 ;
if ( V_178 )
goto V_185;
if ( V_72 -> V_77 & V_136 ) {
V_178 = V_72 -> V_3 ;
V_107 |= V_229 ;
goto V_185;
}
V_132 = F_117 ( V_138 -> V_188 ) ;
if ( V_132 ) {
V_178 = ( (struct V_189 * ) V_132 ) -> V_190 ;
goto V_185;
}
V_178 = V_72 -> V_3 ;
V_107 |= V_229 ;
goto V_185;
default:
goto V_193;
}
V_185:
V_8 = F_122 ( & V_196 , V_217 , 0 , 0 , V_197 ) ;
if ( V_8 == NULL )
goto V_198;
memset ( & V_8 -> V_59 , 0 , sizeof( V_8 -> V_59 ) ) ;
V_8 -> V_134 = V_59 . V_50 ;
V_8 -> V_135 = V_59 . V_49 ;
V_8 -> V_151 = V_59 . V_49 ;
if ( V_178 )
V_8 -> V_151 = V_178 ;
V_8 -> V_199 = V_218 ? V_218 : V_8 -> V_134 ;
V_8 -> V_200 = V_59 . V_49 ;
V_8 -> V_201 = V_59 . V_50 ;
V_8 -> V_59 . V_50 = V_72 -> V_3 ;
V_8 -> V_59 . V_49 = V_72 -> V_2 ;
V_8 -> V_59 . V_53 = 0 ;
V_8 -> V_59 . V_54 = V_216 -> V_113 ;
V_8 -> V_59 . V_51 = V_59 . V_51 ;
F_98 ( & V_8 -> V_2 , V_132 ) ;
V_8 -> V_2 . V_22 = V_15 ;
V_8 -> V_2 . V_131 = F_85 ;
switch ( V_145 . type ) {
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
case V_228 :
V_8 -> V_2 . V_202 = V_230 ;
}
V_8 -> V_77 = V_107 ;
V_88 = F_92 ( V_8 , & V_145 ) ;
if ( V_88 )
goto V_204;
V_55 = F_3 ( V_8 -> V_59 . V_50 , V_8 -> V_59 . V_49 ) ;
F_30 ( V_8 , V_55 , & V_8 ) ;
F_134 ( V_45 , & V_8 -> V_2 ) ;
V_205:
if ( V_132 )
F_115 ( V_132 ) ;
if ( V_177 )
F_123 ( & V_145 ) ;
F_109 ( V_216 ) ;
if ( V_217 )
F_109 ( V_217 ) ;
V_110:
return V_88 ;
V_193:
V_88 = - V_133 ;
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
unsigned V_55 = F_3 ( V_72 -> V_3 , V_72 -> V_2 ) ;
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
F_134 ( V_45 , (struct V_1 * ) V_8 ) ;
return 0 ;
}
}
F_102 () ;
return F_133 ( V_45 ) ;
}
static int F_135 ( struct V_44 * V_45 , T_5 V_231 , T_5 V_232 ,
int V_233 , int V_234 , unsigned int V_107 )
{
struct V_7 * V_8 = (struct V_7 * ) F_78 ( V_45 ) ;
struct V_235 * V_224 ;
struct V_236 * V_237 ;
unsigned char * V_238 = F_136 ( V_45 ) ;
long V_70 ;
V_237 = F_137 ( V_45 , V_231 , V_232 , V_233 , sizeof( * V_224 ) , V_107 ) ;
V_224 = F_138 ( V_237 ) ;
V_224 -> V_239 = V_240 ;
V_224 -> V_241 = 16 ;
V_224 -> V_242 = 0 ;
V_224 -> V_243 = 0 ;
V_224 -> V_244 = V_245 ;
F_139 ( V_45 , V_246 , V_245 ) ;
V_224 -> V_247 = V_8 -> V_153 ;
V_224 -> V_248 = ( V_8 -> V_77 & ~ 0xFFFF ) | V_249 ;
V_224 -> V_250 = V_173 ;
V_224 -> V_251 = V_252 ;
if ( V_8 -> V_77 & V_253 )
V_224 -> V_248 |= V_254 ;
F_140 ( V_45 , V_255 , 2 , & V_8 -> V_135 ) ;
if ( V_8 -> V_59 . V_50 ) {
V_224 -> V_242 = 16 ;
F_140 ( V_45 , V_256 , 2 , & V_8 -> V_59 . V_50 ) ;
}
if ( V_8 -> V_2 . V_34 )
F_140 ( V_45 , V_257 , sizeof( int ) , & V_8 -> V_2 . V_34 -> V_113 ) ;
F_140 ( V_45 , V_258 , 2 , & V_8 -> V_199 ) ;
if ( V_8 -> V_135 != V_8 -> V_151 )
F_140 ( V_45 , V_259 , 2 , & V_8 -> V_151 ) ;
if ( F_141 ( V_45 , F_142 ( & V_8 -> V_2 ) ) < 0 )
goto V_260;
V_70 = V_8 -> V_2 . V_70 ? V_8 -> V_2 . V_70 - V_15 : 0 ;
if ( F_143 ( V_45 , & V_8 -> V_2 , 0 , 0 , 0 , V_70 ,
V_8 -> V_2 . error ) < 0 )
goto V_260;
if ( F_144 ( V_8 ) )
F_140 ( V_45 , V_261 , sizeof( int ) , & V_8 -> V_59 . V_54 ) ;
V_237 -> V_262 = F_136 ( V_45 ) - V_238 ;
return V_45 -> V_93 ;
V_263:
V_260:
F_145 ( V_45 , V_238 ) ;
return - 1 ;
}
static int F_146 ( struct V_44 * V_264 , struct V_236 * V_237 , void * V_265 )
{
struct V_266 * V_266 = F_147 ( V_264 -> V_212 ) ;
struct V_267 * * V_268 = V_265 ;
struct V_235 * V_269 = F_138 ( V_237 ) ;
struct V_7 * V_8 = NULL ;
struct V_71 * V_72 ;
int V_88 ;
struct V_44 * V_45 ;
struct V_46 V_59 ;
if ( ! F_68 ( V_266 , & V_108 ) )
return - V_133 ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_209 = V_270 ;
V_45 = F_148 ( V_271 , V_272 ) ;
if ( V_45 == NULL )
return - V_206 ;
F_149 ( V_45 ) ;
V_72 = F_45 ( V_45 ) ;
if ( V_268 [ V_256 - 1 ] )
memcpy ( & V_59 . V_50 , F_150 ( V_268 [ V_256 - 1 ] ) , 2 ) ;
if ( V_268 [ V_255 - 1 ] )
memcpy ( & V_59 . V_49 , F_150 ( V_268 [ V_255 - 1 ] ) , 2 ) ;
if ( V_268 [ V_261 - 1 ] )
memcpy ( & V_59 . V_54 , F_150 ( V_268 [ V_261 - 1 ] ) , sizeof( int ) ) ;
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
V_45 -> V_273 = F_151 ( V_274 ) ;
V_45 -> V_34 = V_34 ;
V_72 -> V_3 = V_59 . V_50 ;
V_72 -> V_2 = V_59 . V_49 ;
F_152 () ;
V_88 = F_50 ( V_45 ) ;
F_153 () ;
memset ( V_72 , 0 , sizeof( struct V_71 ) ) ;
V_8 = (struct V_7 * ) F_78 ( V_45 ) ;
if ( ! V_88 && - V_8 -> V_2 . error )
V_88 = V_8 -> V_2 . error ;
} else {
int V_275 = 0 ;
if ( V_268 [ V_257 - 1 ] )
memcpy ( & V_275 , F_150 ( V_268 [ V_257 - 1 ] ) , sizeof( int ) ) ;
V_59 . V_53 = V_275 ;
V_88 = F_129 ( (struct V_1 * * ) & V_8 , & V_59 , 0 ) ;
}
if ( V_45 -> V_34 )
F_109 ( V_45 -> V_34 ) ;
V_45 -> V_34 = NULL ;
if ( V_88 )
goto V_276;
F_134 ( V_45 , & V_8 -> V_2 ) ;
if ( V_269 -> V_248 & V_254 )
V_8 -> V_77 |= V_253 ;
V_88 = F_135 ( V_45 , F_154 ( V_264 ) . V_231 , V_237 -> V_277 , V_278 , 0 , 0 ) ;
if ( V_88 == 0 )
goto V_276;
if ( V_88 < 0 ) {
V_88 = - V_279 ;
goto V_276;
}
return F_155 ( V_45 , & V_108 , F_154 ( V_264 ) . V_231 ) ;
V_276:
F_54 ( V_45 ) ;
return V_88 ;
}
int F_156 ( struct V_44 * V_45 , struct V_280 * V_72 )
{
struct V_266 * V_266 = F_147 ( V_45 -> V_212 ) ;
struct V_7 * V_8 ;
int V_281 , V_282 ;
int V_283 , V_284 ;
if ( ! F_68 ( V_266 , & V_108 ) )
return 0 ;
if ( F_157 ( V_72 -> V_237 , 0 ) < sizeof( struct V_235 ) )
return - V_133 ;
if ( ! ( ( (struct V_235 * ) F_138 ( V_72 -> V_237 ) ) -> V_248 & V_249 ) )
return 0 ;
V_282 = V_72 -> args [ 0 ] ;
V_284 = V_283 = V_72 -> args [ 1 ] ;
for( V_281 = 0 ; V_281 <= V_6 ; V_281 ++ ) {
if ( V_281 < V_282 )
continue;
if ( V_281 > V_282 )
V_284 = 0 ;
F_125 () ;
for( V_8 = F_126 ( V_18 [ V_281 ] . V_19 ) , V_283 = 0 ;
V_8 ;
V_8 = F_126 ( V_8 -> V_2 . V_23 ) , V_283 ++ ) {
if ( V_283 < V_284 )
continue;
F_134 ( V_45 , F_158 ( & V_8 -> V_2 ) ) ;
if ( F_135 ( V_45 , F_154 ( V_72 -> V_45 ) . V_231 ,
V_72 -> V_237 -> V_277 , V_278 ,
1 , V_285 ) <= 0 ) {
F_159 ( V_45 ) ;
F_128 () ;
goto V_205;
}
F_159 ( V_45 ) ;
}
F_128 () ;
}
V_205:
V_72 -> args [ 0 ] = V_281 ;
V_72 -> args [ 1 ] = V_283 ;
return V_45 -> V_93 ;
}
static struct V_7 * F_160 ( struct V_286 * V_232 )
{
struct V_7 * V_8 = NULL ;
struct V_287 * V_288 = V_232 -> V_289 ;
for( V_288 -> V_290 = V_6 ; V_288 -> V_290 >= 0 ; -- V_288 -> V_290 ) {
F_125 () ;
V_8 = F_126 ( V_18 [ V_288 -> V_290 ] . V_19 ) ;
if ( V_8 )
break;
F_128 () ;
}
return V_8 ;
}
static struct V_7 * F_161 ( struct V_286 * V_232 , struct V_7 * V_8 )
{
struct V_287 * V_288 = V_232 -> V_289 ;
V_8 = F_126 ( V_8 -> V_2 . V_23 ) ;
while ( ! V_8 ) {
F_128 () ;
if ( -- V_288 -> V_290 < 0 )
break;
F_125 () ;
V_8 = F_126 ( V_18 [ V_288 -> V_290 ] . V_19 ) ;
}
return V_8 ;
}
static void * F_162 ( struct V_286 * V_232 , T_7 * V_291 )
{
struct V_7 * V_8 = F_160 ( V_232 ) ;
if ( V_8 ) {
while( * V_291 && ( V_8 = F_161 ( V_232 , V_8 ) ) )
-- * V_291 ;
}
return * V_291 ? NULL : V_8 ;
}
static void * F_163 ( struct V_286 * V_232 , void * V_292 , T_7 * V_291 )
{
struct V_7 * V_8 = F_161 ( V_232 , V_292 ) ;
++ * V_291 ;
return V_8 ;
}
static void F_164 ( struct V_286 * V_232 , void * V_292 )
{
if ( V_292 )
F_128 () ;
}
static int F_165 ( struct V_286 * V_232 , void * V_292 )
{
struct V_7 * V_8 = V_292 ;
char V_293 [ V_294 ] , V_295 [ V_294 ] ;
F_166 ( V_232 , L_12 ,
V_8 -> V_2 . V_34 ? V_8 -> V_2 . V_34 -> V_91 : L_13 ,
F_167 ( F_53 ( V_8 -> V_135 ) , V_293 ) ,
F_167 ( F_53 ( V_8 -> V_134 ) , V_295 ) ,
F_12 ( & V_8 -> V_2 . V_21 ) ,
V_8 -> V_2 . V_296 ,
( int ) F_21 ( & V_8 -> V_2 , V_297 ) ) ;
return 0 ;
}
static int F_168 ( struct V_298 * V_298 , struct V_299 * V_299 )
{
return F_169 ( V_299 , & V_300 ,
sizeof( struct V_287 ) ) ;
}
void T_8 F_170 ( void )
{
int V_12 , V_301 , V_302 ;
V_196 . V_303 =
F_171 ( L_14 , sizeof( struct V_7 ) , 0 ,
V_304 | V_305 , NULL ) ;
F_172 ( & V_196 ) ;
F_173 ( & V_24 , F_8 , 0 ) ;
V_24 . V_70 = V_15 + V_25 * V_17 ;
F_40 ( & V_24 ) ;
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
F_174 ( V_75 , V_302 ) ;
} while ( V_18 == NULL && -- V_302 > 0 );
if ( ! V_18 )
F_175 ( L_15 ) ;
F_52 ( V_310
L_16 ,
V_6 ,
( long ) ( V_6 * sizeof( struct V_309 ) ) / 1024 ) ;
V_6 -- ;
for( V_12 = 0 ; V_12 <= V_6 ; V_12 ++ ) {
F_176 ( & V_18 [ V_12 ] . V_20 ) ;
V_18 [ V_12 ] . V_19 = NULL ;
}
V_196 . V_311 = ( V_6 + 1 ) ;
F_177 ( & V_108 , L_17 , V_312 , & V_313 ) ;
#ifdef F_178
F_179 ( V_314 , V_315 , F_146 ,
V_316 , NULL ) ;
#else
F_179 ( V_314 , V_315 , F_146 ,
F_156 , NULL ) ;
#endif
}
void T_9 F_180 ( void )
{
F_39 ( & V_24 ) ;
F_33 ( 0 ) ;
F_181 ( & V_108 , L_17 ) ;
F_182 ( & V_196 ) ;
}
