static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_4 -> V_5 )
F_2 ( V_4 -> V_5 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_8 )
{
if ( V_8 ) {
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_5 = V_4 -> V_5 ;
if ( V_5 && V_5 -> V_7 == V_7 ) {
V_5 -> V_7 = F_5 ( V_7 ) -> V_10 ;
F_6 ( V_5 -> V_7 ) ;
F_7 ( V_7 ) ;
}
}
}
static T_1 unsigned int F_8 ( T_2 V_11 , T_2 V_2 )
{
T_3 V_12 = ( T_3 V_13 ) ( V_11 ^ V_2 ) ;
V_12 ^= ( V_12 >> 3 ) ;
V_12 ^= ( V_12 >> 5 ) ;
V_12 ^= ( V_12 >> 10 ) ;
return V_14 & ( unsigned int ) V_12 ;
}
static void F_9 ( unsigned long V_15 )
{
int V_16 ;
struct V_3 * V_4 ;
struct V_3 T_4 * * V_17 ;
unsigned long V_18 = V_19 ;
unsigned long V_20 = 120 * V_21 ;
for ( V_16 = 0 ; V_16 <= V_14 ; V_16 ++ ) {
V_17 = & V_22 [ V_16 ] . V_23 ;
F_10 ( & V_22 [ V_16 ] . V_24 ) ;
while ( ( V_4 = F_11 ( * V_17 ,
F_12 ( & V_22 [ V_16 ] . V_24 ) ) ) != NULL ) {
if ( F_13 ( & V_4 -> V_2 . V_25 ) > 1 ||
( V_18 - V_4 -> V_2 . V_26 ) < V_20 ) {
V_17 = & V_4 -> V_2 . V_27 ;
continue;
}
* V_17 = V_4 -> V_2 . V_27 ;
V_4 -> V_2 . V_27 = NULL ;
F_14 ( & V_4 -> V_2 ) ;
F_15 ( & V_4 -> V_2 ) ;
}
F_16 ( & V_22 [ V_16 ] . V_24 ) ;
if ( ( V_19 - V_18 ) > 0 )
break;
}
F_17 ( & V_28 , V_18 + V_29 * V_21 ) ;
}
static int F_18 ( struct V_30 * V_31 )
{
struct V_3 * V_4 ;
struct V_3 T_4 * * V_17 ;
int V_16 ;
unsigned long V_18 = V_19 ;
unsigned long V_20 = 10 * V_21 ;
for ( V_16 = 0 ; V_16 <= V_14 ; V_16 ++ ) {
F_19 ( & V_22 [ V_16 ] . V_24 ) ;
V_17 = & V_22 [ V_16 ] . V_23 ;
while ( ( V_4 = F_11 ( * V_17 ,
F_12 ( & V_22 [ V_16 ] . V_24 ) ) ) != NULL ) {
if ( F_13 ( & V_4 -> V_2 . V_25 ) > 1 ||
( V_18 - V_4 -> V_2 . V_26 ) < V_20 ) {
V_17 = & V_4 -> V_2 . V_27 ;
continue;
}
* V_17 = V_4 -> V_2 . V_27 ;
V_4 -> V_2 . V_27 = NULL ;
F_14 ( & V_4 -> V_2 ) ;
F_15 ( & V_4 -> V_2 ) ;
break;
}
F_20 ( & V_22 [ V_16 ] . V_24 ) ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_34 * V_35 , T_5 V_36 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_5 = V_4 -> V_5 ;
T_5 V_37 = 230 ;
struct V_38 * V_39 ;
V_39 = V_5 ? F_22 ( V_5 -> V_7 -> V_40 ) : NULL ;
if ( V_39 && V_39 -> V_41 == 0 )
V_37 -= 6 ;
else
V_37 -= 21 ;
if ( F_23 ( V_2 , V_42 ) > V_36 && V_36 >= V_37 ) {
if ( ! ( F_24 ( V_2 , V_42 ) ) ) {
F_25 ( V_2 , V_42 , V_36 ) ;
F_26 ( V_2 , V_43 ) ;
}
if ( ! ( F_24 ( V_2 , V_44 ) ) ) {
T_5 V_45 = V_36 - V_46 ;
T_5 V_47 = F_27 ( V_2 , V_44 ) ;
if ( ! V_47 || V_47 > V_45 )
F_25 ( V_2 , V_44 , V_45 ) ;
}
}
}
static void F_28 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_34 * V_35 )
{
}
static struct V_1 * F_29 ( struct V_1 * V_2 , T_6 V_48 )
{
return NULL ;
}
static struct V_1 * F_30 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
return NULL ;
}
static void F_31 ( struct V_34 * V_35 )
{
}
static inline int F_32 ( struct V_49 * V_50 , struct V_49 * V_51 )
{
return ( ( V_50 -> V_52 ^ V_51 -> V_52 ) |
( V_50 -> V_53 ^ V_51 -> V_53 ) |
( V_50 -> V_54 ^ V_51 -> V_54 ) |
( V_50 -> V_55 ^ V_51 -> V_55 ) |
( V_50 -> V_56 ^ V_51 -> V_56 ) |
( V_50 -> V_57 ^ V_51 -> V_57 ) ) == 0 ;
}
static int F_33 ( struct V_3 * V_4 , unsigned int V_58 , struct V_3 * * V_59 )
{
struct V_3 * V_60 ;
struct V_3 T_4 * * V_61 ;
unsigned long V_18 = V_19 ;
V_61 = & V_22 [ V_58 ] . V_23 ;
F_19 ( & V_22 [ V_58 ] . V_24 ) ;
while ( ( V_60 = F_11 ( * V_61 ,
F_12 ( & V_22 [ V_58 ] . V_24 ) ) ) != NULL ) {
if ( F_32 ( & V_60 -> V_62 , & V_4 -> V_62 ) ) {
* V_61 = V_60 -> V_2 . V_27 ;
F_34 ( V_60 -> V_2 . V_27 ,
V_22 [ V_58 ] . V_23 ) ;
F_34 ( V_22 [ V_58 ] . V_23 , V_60 ) ;
F_35 ( & V_60 -> V_2 , V_18 ) ;
F_20 ( & V_22 [ V_58 ] . V_24 ) ;
F_36 ( & V_4 -> V_2 ) ;
* V_59 = V_60 ;
return 0 ;
}
V_61 = & V_60 -> V_2 . V_27 ;
}
F_34 ( V_4 -> V_2 . V_27 , V_22 [ V_58 ] . V_23 ) ;
F_34 ( V_22 [ V_58 ] . V_23 , V_4 ) ;
F_35 ( & V_4 -> V_2 , V_18 ) ;
F_20 ( & V_22 [ V_58 ] . V_24 ) ;
* V_59 = V_4 ;
return 0 ;
}
static void F_37 ( unsigned long V_15 )
{
int V_16 ;
struct V_3 * V_4 , * V_63 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ ) {
F_19 ( & V_22 [ V_16 ] . V_24 ) ;
if ( ( V_4 = F_38 ( (struct V_3 * * ) & V_22 [ V_16 ] . V_23 , NULL ) ) == NULL )
goto V_64;
for(; V_4 ; V_4 = V_63 ) {
V_63 = F_22 ( V_4 -> V_2 . V_27 ) ;
F_39 ( V_4 -> V_2 . V_27 , NULL ) ;
F_14 ( & V_4 -> V_2 ) ;
F_15 ( & V_4 -> V_2 ) ;
}
V_64:
F_20 ( & V_22 [ V_16 ] . V_24 ) ;
}
}
void F_40 ( int V_65 )
{
unsigned long V_18 = V_19 ;
int V_66 = ! F_41 () ;
if ( V_65 < 0 )
V_65 = V_67 ;
F_19 ( & V_68 ) ;
if ( F_42 ( & V_69 ) && V_65 > 0 && V_70 ) {
long V_71 = ( long ) ( V_70 - V_18 ) ;
if ( V_66 && V_71 < V_72 - V_67 )
V_71 = 0 ;
if ( V_65 > V_71 )
V_65 = V_71 ;
}
if ( V_65 <= 0 ) {
F_20 ( & V_68 ) ;
F_37 ( 0 ) ;
return;
}
if ( V_70 == 0 )
V_70 = V_18 + V_72 ;
V_69 . V_73 = V_18 + V_65 ;
F_43 ( & V_69 ) ;
F_20 ( & V_68 ) ;
}
static int F_44 ( struct V_34 * V_35 )
{
struct V_74 * V_75 ;
unsigned char * V_76 ;
T_2 * V_11 ;
T_2 * V_2 ;
F_45 ( V_35 , V_35 -> V_77 - F_46 ( V_35 ) ) ;
if ( ( V_35 = F_47 ( V_35 , V_78 ) ) == NULL )
return V_79 ;
V_75 = F_48 ( V_35 ) ;
V_76 = V_35 -> V_77 + 2 ;
* V_76 ++ = ( V_75 -> V_80 & ~ V_81 ) | V_82 ;
V_2 = ( T_2 * ) V_76 ;
V_76 += 2 ;
V_11 = ( T_2 * ) V_76 ;
V_76 += 2 ;
* V_76 = 0 ;
F_49 ( * V_11 , * V_2 ) ;
V_35 -> V_83 = V_84 ;
F_50 ( V_35 , NULL , NULL ) ;
return V_85 ;
}
static int F_51 ( struct V_34 * V_35 )
{
struct V_74 * V_75 ;
unsigned char * V_76 ;
unsigned char * V_86 , * V_87 ;
unsigned char V_12 [ V_88 ] ;
F_45 ( V_35 , V_35 -> V_77 - F_46 ( V_35 ) ) ;
if ( ( V_35 = F_47 ( V_35 , V_78 ) ) == NULL )
return V_79 ;
V_75 = F_48 ( V_35 ) ;
V_76 = V_35 -> V_77 + 2 ;
if ( * V_76 & V_89 ) {
char V_90 = ( * V_76 & ~ V_89 ) ;
V_76 += V_90 ;
}
* V_76 ++ = ( V_75 -> V_80 & ~ V_81 ) | V_82 ;
V_76 += 2 ;
V_87 = V_76 ;
V_76 += 8 ;
V_86 = V_76 ;
V_76 += 6 ;
* V_76 = 0 ;
memcpy ( V_12 , V_86 , V_88 ) ;
memcpy ( V_86 , V_87 , V_88 ) ;
memcpy ( V_87 , V_12 , V_88 ) ;
V_35 -> V_83 = V_84 ;
F_50 ( V_35 , V_87 , V_86 ) ;
return V_85 ;
}
static int F_52 ( struct V_91 * V_91 , struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_74 * V_75 ;
int V_92 ;
if ( ( V_92 = F_53 ( V_35 ) ) == 0 )
return F_54 ( V_35 ) ;
V_75 = F_48 ( V_35 ) ;
if ( V_93 & 4 ) {
char * V_94 = V_35 -> V_7 ? V_35 -> V_7 -> V_95 : L_1 ;
F_55 ( V_96
L_2 ,
( int ) V_75 -> V_80 , V_94 , V_35 -> V_97 ,
F_56 ( V_75 -> V_11 ) , F_56 ( V_75 -> V_2 ) ,
V_92 , V_35 -> V_83 ) ;
}
if ( ( V_35 -> V_83 == V_98 ) && ( V_75 -> V_80 & V_81 ) ) {
switch ( V_75 -> V_80 & V_99 ) {
case V_100 :
return F_44 ( V_35 ) ;
case V_101 :
return F_51 ( V_35 ) ;
}
}
F_57 ( V_35 ) ;
return V_79 ;
}
static int F_58 ( struct V_34 * V_35 )
{
struct V_74 * V_75 = F_48 ( V_35 ) ;
unsigned char * V_76 = V_35 -> V_77 ;
if ( ! F_59 ( V_35 , 21 ) )
goto V_102;
F_60 ( V_35 , 20 ) ;
F_61 ( V_35 ) ;
V_76 += 2 ;
V_75 -> V_2 = F_62 ( V_76 ) ;
if ( memcmp ( V_76 , V_103 , 4 ) != 0 )
goto V_102;
V_76 += 6 ;
V_76 += 2 ;
V_75 -> V_11 = F_62 ( V_76 ) ;
if ( memcmp ( V_76 , V_103 , 4 ) != 0 )
goto V_102;
V_76 += 6 ;
V_76 ++ ;
V_75 -> V_104 = * V_76 ++ ;
return F_63 ( V_105 , V_106 ,
& V_107 , NULL , V_35 , V_35 -> V_7 , NULL ,
F_52 ) ;
V_102:
F_57 ( V_35 ) ;
return V_79 ;
}
static int F_64 ( struct V_34 * V_35 )
{
struct V_74 * V_75 = F_48 ( V_35 ) ;
unsigned char * V_76 = V_35 -> V_77 ;
if ( ! F_59 ( V_35 , 6 ) )
goto V_102;
F_60 ( V_35 , 5 ) ;
F_61 ( V_35 ) ;
V_75 -> V_2 = * ( T_2 * ) V_76 ;
V_76 += 2 ;
V_75 -> V_11 = * ( T_2 * ) V_76 ;
V_76 += 2 ;
V_75 -> V_104 = * V_76 & 0x3f ;
return F_63 ( V_105 , V_106 ,
& V_107 , NULL , V_35 , V_35 -> V_7 , NULL ,
F_52 ) ;
V_102:
F_57 ( V_35 ) ;
return V_79 ;
}
static int F_65 ( struct V_91 * V_91 , struct V_32 * V_33 , struct V_34 * V_35 )
{
F_57 ( V_35 ) ;
return V_85 ;
}
static int F_66 ( struct V_91 * V_91 , struct V_32 * V_33 , struct V_34 * V_35 )
{
F_67 ( V_35 ) ;
F_68 ( V_35 ) ;
return V_85 ;
}
int F_69 ( struct V_34 * V_35 , struct V_6 * V_7 , struct V_108 * V_109 , struct V_6 * V_110 )
{
struct V_74 * V_75 ;
unsigned char V_111 = 0 ;
T_3 V_97 = F_56 ( * ( T_2 * ) V_35 -> V_77 ) ;
struct V_38 * V_39 = F_70 ( V_7 -> V_40 ) ;
unsigned char V_90 = 0 ;
if ( ! F_71 ( F_5 ( V_7 ) , & V_107 ) )
goto V_112;
if ( V_39 == NULL )
goto V_112;
if ( ( V_35 = F_72 ( V_35 , V_78 ) ) == NULL )
goto V_113;
if ( ! F_59 ( V_35 , 3 ) )
goto V_112;
F_60 ( V_35 , 2 ) ;
if ( V_97 > V_35 -> V_97 )
goto V_112;
F_73 ( V_35 , V_97 ) ;
V_111 = * V_35 -> V_77 ;
V_75 = F_48 ( V_35 ) ;
V_75 -> V_114 = V_19 ;
V_75 -> V_115 = V_7 -> V_116 ;
if ( V_111 & V_89 ) {
V_90 = V_111 & ~ V_89 ;
if ( ! F_59 ( V_35 , V_90 + 1 ) )
goto V_112;
F_60 ( V_35 , V_90 ) ;
V_111 = * V_35 -> V_77 ;
}
F_74 ( V_35 ) ;
if ( V_111 & V_117 )
goto V_112;
V_75 -> V_80 = V_111 ;
if ( V_93 & 1 )
F_55 ( V_96
L_3 ,
( int ) V_111 , ( V_7 ) ? V_7 -> V_95 : L_1 , V_97 , V_35 -> V_97 ,
V_90 ) ;
if ( V_111 & V_118 ) {
if ( F_75 ( F_76 ( V_35 ) ) )
goto V_112;
switch ( V_111 & V_119 ) {
case V_120 :
F_77 ( V_35 ) ;
break;
case V_121 :
F_78 ( V_35 ) ;
break;
}
if ( V_39 -> V_122 . V_123 != V_124 )
goto V_112;
switch ( V_111 & V_119 ) {
case V_125 :
return F_63 ( V_105 , V_126 ,
& V_107 , NULL , V_35 , V_35 -> V_7 , NULL ,
F_66 ) ;
case V_127 :
case V_128 :
return F_63 ( V_105 , V_129 ,
& V_107 , NULL , V_35 , V_35 -> V_7 , NULL ,
F_65 ) ;
case V_130 :
return F_63 ( V_105 , V_126 ,
& V_107 , NULL , V_35 , V_35 -> V_7 , NULL ,
V_131 ) ;
case V_132 :
return F_63 ( V_105 , V_126 ,
& V_107 , NULL , V_35 , V_35 -> V_7 , NULL ,
V_133 ) ;
}
} else {
if ( V_39 -> V_122 . V_123 != V_124 )
goto V_112;
F_60 ( V_35 , 1 ) ;
switch ( V_111 & V_99 ) {
case V_101 :
return F_58 ( V_35 ) ;
case V_100 :
return F_64 ( V_35 ) ;
}
}
V_112:
F_57 ( V_35 ) ;
V_113:
return V_79 ;
}
static int F_79 ( struct V_91 * V_91 , struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_1 * V_2 = F_80 ( V_35 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_74 * V_75 = F_48 ( V_35 ) ;
int V_92 = - V_134 ;
if ( V_4 -> V_5 == NULL )
goto error;
V_35 -> V_7 = V_7 ;
V_75 -> V_11 = V_4 -> V_135 ;
V_75 -> V_2 = V_4 -> V_136 ;
V_75 -> V_80 &= ~ V_81 ;
V_75 -> V_80 |= V_137 ;
V_75 -> V_104 = 0 ;
return F_63 ( V_105 , V_138 ,
& V_107 , V_33 , V_35 , NULL , V_7 ,
V_139 ) ;
error:
F_81 ( L_4 ) ;
F_57 ( V_35 ) ;
return V_92 ;
}
static int F_82 ( struct V_34 * V_35 )
{
struct V_74 * V_75 = F_48 ( V_35 ) ;
struct V_1 * V_2 = F_80 ( V_35 ) ;
struct V_38 * V_140 = F_70 ( V_2 -> V_7 -> V_40 ) ;
struct V_3 * V_4 ;
int V_141 ;
struct V_6 * V_7 = V_35 -> V_7 ;
if ( V_35 -> V_83 != V_98 )
goto V_142;
V_4 = (struct V_3 * ) F_80 ( V_35 ) ;
V_141 = V_140 -> V_41 ? 21 : 6 ;
if ( F_83 ( V_35 , F_84 ( V_4 -> V_2 . V_7 ) + V_141 ) )
goto V_142;
if ( ++ V_75 -> V_104 > 30 )
goto V_142;
V_35 -> V_7 = V_4 -> V_2 . V_7 ;
V_75 -> V_80 &= ~ V_137 ;
if ( V_4 -> V_80 & V_143 )
V_75 -> V_80 |= V_137 ;
return F_63 ( V_105 , V_144 ,
& V_107 , NULL , V_35 , V_7 , V_35 -> V_7 ,
V_139 ) ;
V_142:
F_57 ( V_35 ) ;
return V_79 ;
}
static int F_85 ( struct V_91 * V_91 , struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_74 * V_75 = F_48 ( V_35 ) ;
F_81 ( L_5 ,
F_56 ( V_75 -> V_11 ) , F_56 ( V_75 -> V_2 ) ) ;
F_57 ( V_35 ) ;
return V_79 ;
}
static int F_86 ( struct V_34 * V_35 )
{
struct V_74 * V_75 = F_48 ( V_35 ) ;
F_81 ( L_5 ,
F_56 ( V_75 -> V_11 ) , F_56 ( V_75 -> V_2 ) ) ;
F_57 ( V_35 ) ;
return V_79 ;
}
static unsigned int F_87 ( const struct V_1 * V_2 )
{
return F_88 ( V_2 -> V_7 , F_89 ( V_2 ) ) ;
}
static unsigned int F_90 ( const struct V_1 * V_2 )
{
unsigned int V_36 = F_27 ( V_2 , V_42 ) ;
return V_36 ? : V_2 -> V_7 -> V_36 ;
}
static struct V_9 * F_91 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const void * V_52 )
{
return F_92 ( & V_145 , V_52 , V_2 -> V_7 ) ;
}
static int F_93 ( struct V_3 * V_4 , struct V_146 * V_147 )
{
struct V_148 * V_149 = V_147 -> V_149 ;
struct V_6 * V_7 = V_4 -> V_2 . V_7 ;
unsigned int V_150 ;
struct V_9 * V_5 ;
if ( V_149 ) {
if ( F_94 ( * V_147 ) &&
F_95 ( * V_147 ) . V_151 == V_152 )
V_4 -> V_153 = F_94 ( * V_147 ) ;
F_96 ( & V_4 -> V_2 , V_149 -> V_154 , true ) ;
}
V_4 -> V_155 = V_147 -> type ;
if ( V_7 != NULL && V_4 -> V_5 == NULL ) {
V_5 = F_92 ( & V_145 , & V_4 -> V_153 , V_7 ) ;
if ( F_97 ( V_5 ) )
return F_98 ( V_5 ) ;
V_4 -> V_5 = V_5 ;
}
if ( F_23 ( & V_4 -> V_2 , V_42 ) > V_4 -> V_2 . V_7 -> V_36 )
F_25 ( & V_4 -> V_2 , V_42 , V_4 -> V_2 . V_7 -> V_36 ) ;
V_150 = F_27 ( & V_4 -> V_2 , V_44 ) ;
if ( V_150 ) {
unsigned int V_45 = F_88 ( V_7 , F_89 ( & V_4 -> V_2 ) ) ;
if ( V_150 > V_45 )
F_25 ( & V_4 -> V_2 , V_44 , V_45 ) ;
}
return 0 ;
}
static inline int F_99 ( T_2 V_156 , T_2 V_157 )
{
T_3 V_12 = F_56 ( V_156 ) ^ F_56 ( V_157 ) ;
int V_158 = 16 ;
while( V_12 ) {
V_12 >>= 1 ;
V_158 -- ;
}
return V_158 ;
}
static T_2 F_100 ( const struct V_6 * V_7 , T_2 V_52 , int V_159 )
{
T_2 V_53 = 0 ;
struct V_38 * V_140 ;
struct V_160 * V_161 ;
int V_162 = 0 ;
int V_163 ;
F_101 () ;
V_140 = F_70 ( V_7 -> V_40 ) ;
for ( V_161 = F_70 ( V_140 -> V_164 ) ;
V_161 != NULL ;
V_161 = F_70 ( V_161 -> V_165 ) ) {
if ( V_161 -> V_166 > V_159 )
continue;
if ( ! V_52 ) {
V_53 = V_161 -> V_167 ;
break;
}
V_163 = F_99 ( V_52 , V_161 -> V_167 ) ;
if ( V_163 > V_162 )
V_53 = V_161 -> V_167 ;
if ( V_162 == 0 )
V_53 = V_161 -> V_167 ;
}
F_102 () ;
return V_53 ;
}
static inline T_2 F_103 ( struct V_146 * V_147 )
{
return F_100 ( F_104 ( * V_147 ) , F_94 ( * V_147 ) , V_147 -> V_159 ) ;
}
static inline T_2 F_105 ( T_2 V_52 , struct V_146 * V_147 )
{
T_2 V_168 = F_106 ( V_147 -> V_169 ) ;
return ( V_52 & ~ V_168 ) | V_147 -> V_149 -> V_170 -> V_171 ;
}
static int F_107 ( struct V_1 * * V_172 , const struct V_49 * V_173 , int V_174 )
{
struct V_49 V_62 = {
. V_52 = V_173 -> V_52 ,
. V_53 = V_173 -> V_53 ,
. V_55 = V_175 ,
. V_54 = V_173 -> V_54 ,
. V_57 = V_176 ,
. V_56 = V_173 -> V_56 ,
} ;
struct V_3 * V_4 = NULL ;
struct V_6 * V_177 = NULL , * V_7 ;
struct V_9 * V_178 = NULL ;
unsigned int V_58 ;
unsigned int V_111 = 0 ;
struct V_146 V_147 = { . V_149 = NULL , . type = V_179 } ;
int V_92 ;
int V_180 = 0 ;
T_2 V_181 = 0 ;
if ( V_93 & 16 )
F_55 ( V_96
L_6
L_7 , F_56 ( V_173 -> V_52 ) ,
F_56 ( V_173 -> V_53 ) ,
V_173 -> V_54 , V_176 ,
V_173 -> V_56 ) ;
if ( V_173 -> V_56 ) {
V_177 = F_108 ( & V_107 , V_173 -> V_56 ) ;
V_92 = - V_182 ;
if ( V_177 && V_177 -> V_40 == NULL ) {
F_7 ( V_177 ) ;
V_177 = NULL ;
}
if ( V_177 == NULL )
goto V_113;
}
if ( V_173 -> V_53 ) {
V_92 = - V_183 ;
if ( V_177 ) {
if ( F_109 ( V_177 , V_173 -> V_53 ) )
goto V_184;
F_7 ( V_177 ) ;
goto V_113;
}
F_101 () ;
F_110 (&init_net, dev) {
if ( ! V_7 -> V_40 )
continue;
if ( ! F_109 ( V_7 , V_173 -> V_53 ) )
continue;
if ( ( V_7 -> V_111 & V_185 ) &&
V_173 -> V_52 &&
! F_109 ( V_7 , V_173 -> V_52 ) )
continue;
V_177 = V_7 ;
break;
}
F_102 () ;
if ( V_177 == NULL )
goto V_113;
F_6 ( V_177 ) ;
V_184:
;
}
if ( ! V_62 . V_52 ) {
V_62 . V_52 = V_62 . V_53 ;
if ( V_177 )
F_7 ( V_177 ) ;
V_92 = - V_134 ;
V_177 = V_107 . V_10 ;
if ( ! V_177 -> V_40 )
goto V_113;
V_92 = - V_183 ;
F_6 ( V_177 ) ;
if ( ! V_62 . V_52 ) {
V_62 . V_52 =
V_62 . V_53 = F_100 ( V_177 , 0 ,
V_186 ) ;
if ( ! V_62 . V_52 )
goto V_113;
}
V_62 . V_56 = V_176 ;
V_147 . type = V_187 ;
goto V_188;
}
if ( V_93 & 16 )
F_55 ( V_96
L_8
L_9 ,
F_56 ( V_62 . V_52 ) , F_56 ( V_62 . V_53 ) ,
V_62 . V_56 , V_174 ) ;
V_92 = - V_189 ;
if ( V_174 || ( V_92 = F_111 ( & V_62 , & V_147 ) ) != 0 ) {
struct V_38 * V_140 ;
if ( V_92 != - V_189 )
goto V_113;
if ( ! V_174 ) {
V_178 = F_112 ( & V_145 , & V_107 , & V_62 . V_52 ) ;
if ( V_178 ) {
if ( ( V_173 -> V_56 &&
( V_178 -> V_7 -> V_116 != V_173 -> V_56 ) ) ||
( V_173 -> V_53 &&
( ! F_109 ( V_178 -> V_7 ,
V_173 -> V_53 ) ) ) ) {
F_2 ( V_178 ) ;
V_178 = NULL ;
} else {
if ( V_177 )
F_7 ( V_177 ) ;
if ( F_109 ( V_178 -> V_7 , V_62 . V_52 ) ) {
V_177 = V_107 . V_10 ;
V_147 . type = V_187 ;
} else {
V_177 = V_178 -> V_7 ;
}
F_6 ( V_177 ) ;
goto V_190;
}
}
}
if ( V_177 == NULL )
V_177 = F_113 () ;
V_92 = - V_182 ;
if ( V_177 == NULL )
goto V_113;
V_140 = F_22 ( V_177 -> V_40 ) ;
if ( ! V_140 )
goto V_191;
if ( F_109 ( V_177 , V_62 . V_52 ) ) {
F_7 ( V_177 ) ;
V_177 = V_107 . V_10 ;
F_6 ( V_177 ) ;
V_147 . type = V_187 ;
goto V_190;
}
V_178 = F_114 ( V_140 -> V_192 ) ;
F_115 ( V_178 && V_178 -> V_7 != V_177 ) ;
V_190:
if ( V_178 )
V_181 = ( (struct V_193 * ) V_178 ) -> V_194 ;
if ( V_181 == 0 )
V_181 = V_62 . V_52 ;
if ( V_62 . V_53 == 0 ) {
V_62 . V_53 = F_100 ( V_177 , V_181 ,
V_147 . type == V_187 ?
V_186 :
V_152 ) ;
if ( V_62 . V_53 == 0 && V_147 . type != V_187 )
goto V_195;
}
V_62 . V_56 = V_177 -> V_116 ;
goto V_188;
}
V_180 = 1 ;
if ( V_147 . type == V_196 )
goto V_191;
if ( V_147 . type == V_187 ) {
if ( ! V_62 . V_53 )
V_62 . V_53 = V_62 . V_52 ;
if ( V_177 )
F_7 ( V_177 ) ;
V_177 = V_107 . V_10 ;
F_6 ( V_177 ) ;
if ( ! V_177 -> V_40 )
goto V_191;
V_62 . V_56 = V_177 -> V_116 ;
if ( V_147 . V_149 )
F_116 ( V_147 . V_149 ) ;
V_147 . V_149 = NULL ;
goto V_188;
}
if ( V_147 . V_149 -> V_197 > 1 && V_62 . V_56 == 0 )
F_117 ( & V_62 , & V_147 ) ;
if ( ! V_62 . V_53 )
V_62 . V_53 = F_118 ( V_147 ) ;
if ( V_177 )
F_7 ( V_177 ) ;
V_177 = F_104 ( V_147 ) ;
F_6 ( V_177 ) ;
V_62 . V_56 = V_177 -> V_116 ;
V_181 = F_94 ( V_147 ) ;
V_188:
if ( V_177 -> V_111 & V_185 )
V_111 |= V_198 ;
V_4 = F_119 ( & V_199 , V_177 , 0 , V_200 , V_201 ) ;
if ( V_4 == NULL )
goto V_202;
memset ( & V_4 -> V_62 , 0 , sizeof( V_4 -> V_62 ) ) ;
V_4 -> V_62 . V_53 = V_173 -> V_53 ;
V_4 -> V_62 . V_52 = V_173 -> V_52 ;
V_4 -> V_62 . V_56 = V_173 -> V_56 ;
V_4 -> V_62 . V_57 = 0 ;
V_4 -> V_62 . V_54 = V_173 -> V_54 ;
V_4 -> V_135 = V_62 . V_53 ;
V_4 -> V_136 = V_62 . V_52 ;
V_4 -> V_153 = V_181 ? V_181 : V_62 . V_52 ;
V_4 -> V_203 = V_62 . V_53 ;
V_4 -> V_204 = V_62 . V_52 ;
V_4 -> V_205 = V_62 . V_53 ;
V_4 -> V_5 = V_178 ;
V_178 = NULL ;
V_4 -> V_2 . V_26 = V_19 ;
V_4 -> V_2 . V_206 = F_79 ;
V_4 -> V_2 . V_207 = F_86 ;
V_4 -> V_80 = V_111 ;
if ( V_111 & V_198 )
V_4 -> V_2 . V_207 = V_208 ;
V_92 = F_93 ( V_4 , & V_147 ) ;
if ( V_92 )
goto V_209;
V_58 = F_8 ( V_4 -> V_62 . V_53 , V_4 -> V_62 . V_52 ) ;
F_33 ( V_4 , V_58 , (struct V_3 * * ) V_172 ) ;
V_210:
if ( V_178 )
F_2 ( V_178 ) ;
if ( V_180 )
F_120 ( & V_147 ) ;
if ( V_177 )
F_7 ( V_177 ) ;
V_113:
return V_92 ;
V_195:
V_92 = - V_183 ;
goto V_210;
V_191:
V_92 = - V_134 ;
goto V_210;
V_202:
V_92 = - V_211 ;
goto V_210;
V_209:
F_36 ( & V_4 -> V_2 ) ;
goto V_202;
}
static int F_121 ( struct V_1 * * V_172 , const struct V_49 * V_212 , int V_111 )
{
unsigned int V_58 = F_8 ( V_212 -> V_53 , V_212 -> V_52 ) ;
struct V_3 * V_4 = NULL ;
if ( ! ( V_111 & V_213 ) ) {
F_122 () ;
for ( V_4 = F_123 ( V_22 [ V_58 ] . V_23 ) ; V_4 ;
V_4 = F_123 ( V_4 -> V_2 . V_27 ) ) {
if ( ( V_212 -> V_52 == V_4 -> V_62 . V_52 ) &&
( V_212 -> V_53 == V_4 -> V_62 . V_53 ) &&
( V_212 -> V_54 == V_4 -> V_62 . V_54 ) &&
F_124 ( V_4 ) &&
( V_4 -> V_62 . V_56 == V_212 -> V_56 ) ) {
F_35 ( & V_4 -> V_2 , V_19 ) ;
F_125 () ;
* V_172 = & V_4 -> V_2 ;
return 0 ;
}
}
F_125 () ;
}
return F_107 ( V_172 , V_212 , V_111 ) ;
}
static int F_126 ( struct V_1 * * V_172 , struct V_49 * V_212 , int V_111 )
{
int V_92 ;
V_92 = F_121 ( V_172 , V_212 , V_111 ) ;
if ( V_92 == 0 && V_212 -> V_214 ) {
* V_172 = F_127 ( & V_107 , * V_172 ,
F_128 ( V_212 ) , NULL , 0 ) ;
if ( F_97 ( * V_172 ) ) {
V_92 = F_98 ( * V_172 ) ;
* V_172 = NULL ;
}
}
return V_92 ;
}
int F_129 ( struct V_1 T_4 * * V_172 , struct V_49 * V_215 , struct V_32 * V_33 , int V_111 )
{
int V_92 ;
V_92 = F_121 ( V_172 , V_215 , V_111 & V_213 ) ;
if ( V_92 == 0 && V_215 -> V_214 ) {
* V_172 = F_127 ( & V_107 , * V_172 ,
F_128 ( V_215 ) , V_33 , 0 ) ;
if ( F_97 ( * V_172 ) ) {
V_92 = F_98 ( * V_172 ) ;
* V_172 = NULL ;
}
}
return V_92 ;
}
static int F_130 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = NULL ;
struct V_74 * V_75 = F_48 ( V_35 ) ;
struct V_6 * V_216 = V_35 -> V_7 ;
struct V_6 * V_217 = NULL ;
struct V_38 * V_140 ;
struct V_9 * V_178 = NULL ;
unsigned int V_58 ;
int V_111 = 0 ;
T_2 V_181 = 0 ;
T_2 V_218 = 0 ;
struct V_49 V_62 = {
. V_52 = V_75 -> V_2 ,
. V_53 = V_75 -> V_11 ,
. V_55 = V_175 ,
. V_54 = V_35 -> V_219 ,
. V_57 = V_35 -> V_7 -> V_116 ,
} ;
struct V_146 V_147 = { . V_149 = NULL , . type = V_220 } ;
int V_92 = - V_134 ;
int V_180 = 0 ;
F_6 ( V_216 ) ;
if ( ( V_140 = F_70 ( V_216 -> V_40 ) ) == NULL )
goto V_113;
if ( V_62 . V_53 == 0 )
goto V_113;
V_92 = - V_221 ;
if ( F_109 ( V_216 , V_75 -> V_11 ) )
goto V_113;
V_92 = F_111 ( & V_62 , & V_147 ) ;
if ( V_92 ) {
if ( V_92 != - V_189 )
goto V_113;
if ( ! F_109 ( V_216 , V_75 -> V_2 ) )
goto V_191;
V_147 . type = V_187 ;
} else {
T_2 V_222 = V_62 . V_53 ;
V_180 = 1 ;
V_217 = F_104 ( V_147 ) ;
if ( V_217 == NULL ) {
F_131 ( L_10 ) ;
goto V_191;
}
F_6 ( V_217 ) ;
if ( V_147 . V_223 )
V_222 = V_62 . V_53 ;
V_181 = F_94 ( V_147 ) ;
if ( V_147 . type == V_196 ) {
V_62 . V_52 = F_105 ( V_62 . V_52 , & V_147 ) ;
F_120 ( & V_147 ) ;
V_180 = 0 ;
if ( F_111 ( & V_62 , & V_147 ) )
goto V_191;
V_180 = 1 ;
if ( V_147 . type != V_179 )
goto V_191;
V_111 |= V_224 ;
V_181 = V_62 . V_52 ;
}
V_62 . V_53 = V_222 ;
}
switch( V_147 . type ) {
case V_179 :
if ( V_140 -> V_122 . V_225 == 0 )
goto V_191;
if ( V_147 . V_149 -> V_197 > 1 && V_62 . V_56 == 0 )
F_117 ( & V_62 , & V_147 ) ;
if ( V_217 == V_216 && ! ( V_111 & V_226 ) )
V_111 |= V_143 ;
V_218 = F_118 ( V_147 ) ;
case V_227 :
case V_220 :
break;
case V_187 :
V_111 |= V_198 ;
V_62 . V_53 = V_75 -> V_2 ;
V_62 . V_52 = V_75 -> V_11 ;
if ( V_181 )
goto V_188;
if ( V_75 -> V_80 & V_137 ) {
V_181 = V_75 -> V_11 ;
goto V_188;
}
V_178 = F_114 ( V_140 -> V_192 ) ;
if ( V_178 ) {
V_181 = ( (struct V_193 * ) V_178 ) -> V_194 ;
goto V_188;
}
V_181 = V_75 -> V_11 ;
goto V_188;
default:
goto V_191;
}
V_188:
V_4 = F_119 ( & V_199 , V_217 , 1 , V_200 , V_201 ) ;
if ( V_4 == NULL )
goto V_202;
memset ( & V_4 -> V_62 , 0 , sizeof( V_4 -> V_62 ) ) ;
V_4 -> V_135 = V_62 . V_53 ;
V_4 -> V_136 = V_62 . V_52 ;
V_4 -> V_153 = V_62 . V_52 ;
if ( V_181 )
V_4 -> V_153 = V_181 ;
V_4 -> V_203 = V_218 ? V_218 : V_4 -> V_135 ;
V_4 -> V_204 = V_62 . V_52 ;
V_4 -> V_205 = V_62 . V_53 ;
V_4 -> V_62 . V_53 = V_75 -> V_11 ;
V_4 -> V_62 . V_52 = V_75 -> V_2 ;
V_4 -> V_62 . V_56 = 0 ;
V_4 -> V_62 . V_57 = V_216 -> V_116 ;
V_4 -> V_62 . V_54 = V_62 . V_54 ;
V_4 -> V_5 = V_178 ;
V_4 -> V_2 . V_26 = V_19 ;
V_4 -> V_2 . V_206 = F_85 ;
switch ( V_147 . type ) {
case V_179 :
V_4 -> V_2 . V_207 = F_82 ;
break;
case V_187 :
V_4 -> V_2 . V_206 = F_79 ;
V_4 -> V_2 . V_207 = V_208 ;
V_4 -> V_2 . V_7 = V_216 ;
V_111 |= V_198 ;
break;
default:
case V_220 :
case V_227 :
V_4 -> V_2 . V_207 = V_228 ;
}
V_4 -> V_80 = V_111 ;
V_92 = F_93 ( V_4 , & V_147 ) ;
if ( V_92 )
goto V_209;
V_58 = F_8 ( V_4 -> V_62 . V_53 , V_4 -> V_62 . V_52 ) ;
F_33 ( V_4 , V_58 , & V_4 ) ;
F_132 ( V_35 , & V_4 -> V_2 ) ;
V_210:
if ( V_178 )
F_2 ( V_178 ) ;
if ( V_180 )
F_120 ( & V_147 ) ;
F_7 ( V_216 ) ;
if ( V_217 )
F_7 ( V_217 ) ;
V_113:
return V_92 ;
V_191:
V_92 = - V_134 ;
goto V_210;
V_202:
V_92 = - V_211 ;
goto V_210;
V_209:
F_36 ( & V_4 -> V_2 ) ;
goto V_210;
}
static int F_53 ( struct V_34 * V_35 )
{
struct V_3 * V_4 ;
struct V_74 * V_75 = F_48 ( V_35 ) ;
unsigned int V_58 = F_8 ( V_75 -> V_11 , V_75 -> V_2 ) ;
if ( F_80 ( V_35 ) )
return 0 ;
F_101 () ;
for( V_4 = F_70 ( V_22 [ V_58 ] . V_23 ) ; V_4 != NULL ;
V_4 = F_70 ( V_4 -> V_2 . V_27 ) ) {
if ( ( V_4 -> V_62 . V_53 == V_75 -> V_11 ) &&
( V_4 -> V_62 . V_52 == V_75 -> V_2 ) &&
( V_4 -> V_62 . V_56 == 0 ) &&
( V_4 -> V_62 . V_54 == V_35 -> V_219 ) &&
( V_4 -> V_62 . V_57 == V_75 -> V_115 ) ) {
F_35 ( & V_4 -> V_2 , V_19 ) ;
F_102 () ;
F_132 ( V_35 , (struct V_1 * ) V_4 ) ;
return 0 ;
}
}
F_102 () ;
return F_130 ( V_35 ) ;
}
static int F_133 ( struct V_34 * V_35 , T_5 V_229 , T_5 V_230 ,
int V_231 , int V_232 , unsigned int V_111 )
{
struct V_3 * V_4 = (struct V_3 * ) F_80 ( V_35 ) ;
struct V_233 * V_223 ;
struct V_234 * V_235 ;
long V_73 ;
V_235 = F_134 ( V_35 , V_229 , V_230 , V_231 , sizeof( * V_223 ) , V_111 ) ;
if ( ! V_235 )
return - V_236 ;
V_223 = F_135 ( V_235 ) ;
V_223 -> V_237 = V_238 ;
V_223 -> V_239 = 16 ;
V_223 -> V_240 = 0 ;
V_223 -> V_241 = 0 ;
V_223 -> V_242 = V_243 ;
V_223 -> V_244 = V_4 -> V_155 ;
V_223 -> V_245 = ( V_4 -> V_80 & ~ 0xFFFF ) | V_246 ;
V_223 -> V_247 = V_175 ;
V_223 -> V_248 = V_249 ;
if ( V_4 -> V_80 & V_250 )
V_223 -> V_245 |= V_251 ;
if ( F_136 ( V_35 , V_252 , V_243 ) < 0 ||
F_137 ( V_35 , V_253 , V_4 -> V_136 ) < 0 )
goto V_254;
if ( V_4 -> V_62 . V_53 ) {
V_223 -> V_240 = 16 ;
if ( F_137 ( V_35 , V_255 , V_4 -> V_62 . V_53 ) < 0 )
goto V_254;
}
if ( V_4 -> V_2 . V_7 &&
F_136 ( V_35 , V_256 , V_4 -> V_2 . V_7 -> V_116 ) < 0 )
goto V_254;
if ( F_137 ( V_35 , V_257 , V_4 -> V_203 ) < 0 )
goto V_254;
if ( V_4 -> V_136 != V_4 -> V_153 &&
F_137 ( V_35 , V_258 , V_4 -> V_153 ) < 0 )
goto V_254;
if ( F_138 ( V_35 , F_139 ( & V_4 -> V_2 ) ) < 0 )
goto V_254;
V_73 = V_4 -> V_2 . V_73 ? V_4 -> V_2 . V_73 - V_19 : 0 ;
if ( F_140 ( V_35 , & V_4 -> V_2 , 0 , V_73 ,
V_4 -> V_2 . error ) < 0 )
goto V_254;
if ( F_141 ( V_4 ) &&
F_136 ( V_35 , V_259 , V_4 -> V_62 . V_57 ) < 0 )
goto V_254;
F_142 ( V_35 , V_235 ) ;
return 0 ;
V_254:
F_143 ( V_35 , V_235 ) ;
return - V_236 ;
}
static int F_144 ( struct V_34 * V_260 , struct V_234 * V_235 ,
struct V_261 * V_262 )
{
struct V_91 * V_91 = F_145 ( V_260 -> V_33 ) ;
struct V_233 * V_263 = F_135 ( V_235 ) ;
struct V_3 * V_4 = NULL ;
struct V_74 * V_75 ;
int V_92 ;
struct V_34 * V_35 ;
struct V_49 V_62 ;
struct V_264 * V_265 [ V_266 + 1 ] ;
if ( ! F_71 ( V_91 , & V_107 ) )
return - V_134 ;
V_92 = F_146 ( V_235 , sizeof( * V_263 ) , V_265 , V_266 , V_267 ,
V_262 ) ;
if ( V_92 < 0 )
return V_92 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_214 = V_268 ;
V_35 = F_147 ( V_269 , V_270 ) ;
if ( V_35 == NULL )
return - V_211 ;
F_148 ( V_35 ) ;
V_75 = F_48 ( V_35 ) ;
if ( V_265 [ V_255 ] )
V_62 . V_53 = F_149 ( V_265 [ V_255 ] ) ;
if ( V_265 [ V_253 ] )
V_62 . V_52 = F_149 ( V_265 [ V_253 ] ) ;
if ( V_265 [ V_259 ] )
V_62 . V_57 = F_150 ( V_265 [ V_259 ] ) ;
if ( V_62 . V_57 ) {
struct V_6 * V_7 ;
V_7 = F_151 ( & V_107 , V_62 . V_57 ) ;
if ( ! V_7 || ! V_7 -> V_40 ) {
F_57 ( V_35 ) ;
return - V_182 ;
}
V_35 -> V_271 = F_152 ( V_272 ) ;
V_35 -> V_7 = V_7 ;
V_75 -> V_11 = V_62 . V_53 ;
V_75 -> V_2 = V_62 . V_52 ;
F_153 () ;
V_92 = F_53 ( V_35 ) ;
F_154 () ;
memset ( V_75 , 0 , sizeof( struct V_74 ) ) ;
V_4 = (struct V_3 * ) F_80 ( V_35 ) ;
if ( ! V_92 && - V_4 -> V_2 . error )
V_92 = V_4 -> V_2 . error ;
} else {
if ( V_265 [ V_256 ] )
V_62 . V_56 = F_150 ( V_265 [ V_256 ] ) ;
V_92 = F_126 ( (struct V_1 * * ) & V_4 , & V_62 , 0 ) ;
}
V_35 -> V_7 = NULL ;
if ( V_92 )
goto V_273;
F_132 ( V_35 , & V_4 -> V_2 ) ;
if ( V_263 -> V_245 & V_251 )
V_4 -> V_80 |= V_250 ;
V_92 = F_133 ( V_35 , F_155 ( V_260 ) . V_229 , V_235 -> V_274 , V_275 , 0 , 0 ) ;
if ( V_92 < 0 ) {
V_92 = - V_236 ;
goto V_273;
}
return F_156 ( V_35 , & V_107 , F_155 ( V_260 ) . V_229 ) ;
V_273:
F_57 ( V_35 ) ;
return V_92 ;
}
int F_157 ( struct V_34 * V_35 , struct V_276 * V_75 )
{
struct V_91 * V_91 = F_145 ( V_35 -> V_33 ) ;
struct V_3 * V_4 ;
int V_277 , V_278 ;
int V_279 , V_280 ;
struct V_233 * V_263 ;
if ( ! F_71 ( V_91 , & V_107 ) )
return 0 ;
if ( F_158 ( V_75 -> V_235 ) < sizeof( struct V_233 ) )
return - V_134 ;
V_263 = F_135 ( V_75 -> V_235 ) ;
if ( ! ( V_263 -> V_245 & V_246 ) )
return 0 ;
V_278 = V_75 -> args [ 0 ] ;
V_280 = V_279 = V_75 -> args [ 1 ] ;
for( V_277 = 0 ; V_277 <= V_14 ; V_277 ++ ) {
if ( V_277 < V_278 )
continue;
if ( V_277 > V_278 )
V_280 = 0 ;
F_122 () ;
for( V_4 = F_123 ( V_22 [ V_277 ] . V_23 ) , V_279 = 0 ;
V_4 ;
V_4 = F_123 ( V_4 -> V_2 . V_27 ) , V_279 ++ ) {
if ( V_279 < V_280 )
continue;
F_132 ( V_35 , F_159 ( & V_4 -> V_2 ) ) ;
if ( F_133 ( V_35 , F_155 ( V_75 -> V_35 ) . V_229 ,
V_75 -> V_235 -> V_274 , V_275 ,
1 , V_281 ) < 0 ) {
F_160 ( V_35 ) ;
F_125 () ;
goto V_210;
}
F_160 ( V_35 ) ;
}
F_125 () ;
}
V_210:
V_75 -> args [ 0 ] = V_277 ;
V_75 -> args [ 1 ] = V_279 ;
return V_35 -> V_97 ;
}
static struct V_3 * F_161 ( struct V_282 * V_230 )
{
struct V_3 * V_4 = NULL ;
struct V_283 * V_284 = V_230 -> V_285 ;
for( V_284 -> V_286 = V_14 ; V_284 -> V_286 >= 0 ; -- V_284 -> V_286 ) {
F_122 () ;
V_4 = F_123 ( V_22 [ V_284 -> V_286 ] . V_23 ) ;
if ( V_4 )
break;
F_125 () ;
}
return V_4 ;
}
static struct V_3 * F_162 ( struct V_282 * V_230 , struct V_3 * V_4 )
{
struct V_283 * V_284 = V_230 -> V_285 ;
V_4 = F_123 ( V_4 -> V_2 . V_27 ) ;
while ( ! V_4 ) {
F_125 () ;
if ( -- V_284 -> V_286 < 0 )
break;
F_122 () ;
V_4 = F_123 ( V_22 [ V_284 -> V_286 ] . V_23 ) ;
}
return V_4 ;
}
static void * F_163 ( struct V_282 * V_230 , T_7 * V_287 )
{
struct V_3 * V_4 = F_161 ( V_230 ) ;
if ( V_4 ) {
while( * V_287 && ( V_4 = F_162 ( V_230 , V_4 ) ) )
-- * V_287 ;
}
return * V_287 ? NULL : V_4 ;
}
static void * F_164 ( struct V_282 * V_230 , void * V_288 , T_7 * V_287 )
{
struct V_3 * V_4 = F_162 ( V_230 , V_288 ) ;
++ * V_287 ;
return V_4 ;
}
static void F_165 ( struct V_282 * V_230 , void * V_288 )
{
if ( V_288 )
F_125 () ;
}
static int F_166 ( struct V_282 * V_230 , void * V_288 )
{
struct V_3 * V_4 = V_288 ;
char V_289 [ V_290 ] , V_291 [ V_290 ] ;
F_167 ( V_230 , L_11 ,
V_4 -> V_2 . V_7 ? V_4 -> V_2 . V_7 -> V_95 : L_12 ,
F_168 ( F_56 ( V_4 -> V_136 ) , V_289 ) ,
F_168 ( F_56 ( V_4 -> V_135 ) , V_291 ) ,
F_13 ( & V_4 -> V_2 . V_25 ) ,
V_4 -> V_2 . V_292 , 0 ) ;
return 0 ;
}
static int F_169 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_170 ( V_294 , & V_295 ,
sizeof( struct V_283 ) ) ;
}
void T_8 F_171 ( void )
{
int V_16 , V_296 , V_297 ;
V_199 . V_298 =
F_172 ( L_13 , sizeof( struct V_3 ) , 0 ,
V_299 | V_300 , NULL ) ;
F_173 ( & V_199 ) ;
F_174 ( & V_28 , F_9 , 0 ) ;
V_28 . V_73 = V_19 + V_29 * V_21 ;
F_43 ( & V_28 ) ;
V_296 = V_301 >> ( 26 - V_302 ) ;
for( V_297 = 0 ; ( 1UL << V_297 ) < V_296 ; V_297 ++ )
;
while( V_297 && ( ( ( ( 1UL << V_297 ) * V_303 ) /
sizeof( struct V_304 ) ) >= 2048 ) )
V_297 -- ;
do {
V_14 = ( 1UL << V_297 ) * V_303 /
sizeof( struct V_304 ) ;
while( V_14 & ( V_14 - 1 ) )
V_14 -- ;
V_22 = (struct V_304 * )
F_175 ( V_78 , V_297 ) ;
} while ( V_22 == NULL && -- V_297 > 0 );
if ( ! V_22 )
F_176 ( L_14 ) ;
F_55 ( V_305
L_15 ,
V_14 ,
( long ) ( V_14 * sizeof( struct V_304 ) ) / 1024 ) ;
V_14 -- ;
for( V_16 = 0 ; V_16 <= V_14 ; V_16 ++ ) {
F_177 ( & V_22 [ V_16 ] . V_24 ) ;
V_22 [ V_16 ] . V_23 = NULL ;
}
V_199 . V_306 = ( V_14 + 1 ) ;
F_178 ( L_16 , V_307 , V_107 . V_308 ,
& V_309 ) ;
#ifdef F_179
F_180 ( V_310 , V_311 , F_144 ,
V_312 , NULL ) ;
#else
F_180 ( V_310 , V_311 , F_144 ,
F_157 , NULL ) ;
#endif
}
void T_9 F_181 ( void )
{
F_42 ( & V_28 ) ;
F_37 ( 0 ) ;
F_182 ( L_16 , V_107 . V_308 ) ;
F_183 ( & V_199 ) ;
}
