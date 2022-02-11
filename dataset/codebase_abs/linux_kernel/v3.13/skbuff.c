static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( V_4 -> V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 1 ;
}
static void F_6 ( struct V_6 * V_7 , unsigned int V_8 , void * V_9 ,
const char V_10 [] )
{
F_7 ( L_1 ,
V_10 , V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_2 ) ;
F_8 () ;
}
static void F_9 ( struct V_6 * V_7 , unsigned int V_8 , void * V_9 )
{
F_6 ( V_7 , V_8 , V_9 , V_18 ) ;
}
static void F_10 ( struct V_6 * V_7 , unsigned int V_8 , void * V_9 )
{
F_6 ( V_7 , V_8 , V_9 , V_18 ) ;
}
static void * F_11 ( T_1 V_19 , T_2 V_20 , int V_21 ,
unsigned long V_22 , bool * V_23 )
{
void * V_24 ;
bool V_25 = false ;
V_24 = F_12 ( V_19 ,
V_20 | V_26 | V_27 ,
V_21 ) ;
if ( V_24 || ! ( F_13 ( V_20 ) ) )
goto V_28;
V_25 = true ;
V_24 = F_12 ( V_19 , V_20 , V_21 ) ;
V_28:
if ( V_23 )
* V_23 = V_25 ;
return V_24 ;
}
struct V_6 * F_14 ( T_2 V_29 , int V_21 )
{
struct V_6 * V_7 ;
V_7 = F_15 ( V_30 ,
V_29 & ~ V_31 , V_21 ) ;
if ( ! V_7 )
goto V_28;
memset ( V_7 , 0 , F_16 ( struct V_6 , V_14 ) ) ;
V_7 -> V_12 = NULL ;
V_7 -> V_32 = sizeof( struct V_6 ) ;
F_17 ( & V_7 -> V_33 , 1 ) ;
V_7 -> V_34 = ( F_18 ( V_7 -> V_34 ) ) ~ 0U ;
V_28:
return V_7 ;
}
struct V_6 * F_19 ( unsigned int V_19 , T_2 V_29 ,
int V_20 , int V_21 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_6 * V_7 ;
T_3 * V_13 ;
bool V_23 ;
V_36 = ( V_20 & V_39 )
? V_40 : V_30 ;
if ( F_20 () && ( V_20 & V_41 ) )
V_29 |= V_42 ;
V_7 = F_15 ( V_36 , V_29 & ~ V_31 , V_21 ) ;
if ( ! V_7 )
goto V_28;
F_21 ( V_7 ) ;
V_19 = F_22 ( V_19 ) ;
V_19 += F_22 ( sizeof( struct V_37 ) ) ;
V_13 = F_23 ( V_19 , V_29 , V_21 , & V_23 ) ;
if ( ! V_13 )
goto V_43;
V_19 = F_24 ( F_25 ( V_13 ) ) ;
F_21 ( V_13 + V_19 ) ;
memset ( V_7 , 0 , F_16 ( struct V_6 , V_14 ) ) ;
V_7 -> V_32 = F_26 ( V_19 ) ;
V_7 -> V_23 = V_23 ;
F_17 ( & V_7 -> V_33 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_27 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_19 ;
V_7 -> V_34 = ( F_18 ( V_7 -> V_34 ) ) ~ 0U ;
V_7 -> V_44 = ( F_18 ( V_7 -> V_44 ) ) ~ 0U ;
V_38 = F_28 ( V_7 ) ;
memset ( V_38 , 0 , F_16 ( struct V_37 , V_45 ) ) ;
F_17 ( & V_38 -> V_45 , 1 ) ;
F_29 ( V_38 -> V_46 ) ;
if ( V_20 & V_39 ) {
struct V_6 * V_47 = V_7 + 1 ;
T_4 * V_48 = ( T_4 * ) ( V_47 + 1 ) ;
F_30 ( V_47 , V_49 ) ;
F_30 ( V_47 , V_50 ) ;
V_7 -> V_51 = V_52 ;
F_17 ( V_48 , 1 ) ;
V_47 -> V_51 = V_53 ;
V_47 -> V_23 = V_23 ;
}
V_28:
return V_7 ;
V_43:
F_31 ( V_36 , V_7 ) ;
V_7 = NULL ;
goto V_28;
}
struct V_6 * F_32 ( void * V_13 , unsigned int V_54 )
{
struct V_37 * V_38 ;
struct V_6 * V_7 ;
unsigned int V_19 = V_54 ? : F_25 ( V_13 ) ;
V_7 = F_33 ( V_30 , V_55 ) ;
if ( ! V_7 )
return NULL ;
V_19 -= F_22 ( sizeof( struct V_37 ) ) ;
memset ( V_7 , 0 , F_16 ( struct V_6 , V_14 ) ) ;
V_7 -> V_32 = F_26 ( V_19 ) ;
V_7 -> V_56 = V_54 != 0 ;
F_17 ( & V_7 -> V_33 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_27 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_19 ;
V_7 -> V_34 = ( F_18 ( V_7 -> V_34 ) ) ~ 0U ;
V_7 -> V_44 = ( F_18 ( V_7 -> V_44 ) ) ~ 0U ;
V_38 = F_28 ( V_7 ) ;
memset ( V_38 , 0 , F_16 ( struct V_37 , V_45 ) ) ;
F_17 ( & V_38 -> V_45 , 1 ) ;
F_29 ( V_38 -> V_46 ) ;
return V_7 ;
}
static void * F_34 ( unsigned int V_57 , T_2 V_29 )
{
struct V_58 * V_59 ;
void * V_13 = NULL ;
int V_60 ;
unsigned long V_20 ;
F_35 ( V_20 ) ;
V_59 = & F_36 ( V_58 ) ;
if ( F_37 ( ! V_59 -> V_61 . V_5 ) ) {
V_62:
for ( V_60 = V_63 ; ; ) {
T_2 V_64 = V_29 ;
if ( V_60 )
V_64 |= V_65 | V_27 ;
V_59 -> V_61 . V_5 = F_38 ( V_64 , V_60 ) ;
if ( F_39 ( V_59 -> V_61 . V_5 ) )
break;
if ( -- V_60 < 0 )
goto V_15;
}
V_59 -> V_61 . V_19 = V_66 << V_60 ;
V_67:
F_17 ( & V_59 -> V_61 . V_5 -> V_68 , V_69 ) ;
V_59 -> V_70 = V_69 ;
V_59 -> V_61 . V_71 = 0 ;
}
if ( V_59 -> V_61 . V_71 + V_57 > V_59 -> V_61 . V_19 ) {
if ( ( F_40 ( & V_59 -> V_61 . V_5 -> V_68 ) == V_59 -> V_70 ) ||
F_41 ( V_59 -> V_70 , & V_59 -> V_61 . V_5 -> V_68 ) )
goto V_67;
goto V_62;
}
V_13 = F_42 ( V_59 -> V_61 . V_5 ) + V_59 -> V_61 . V_71 ;
V_59 -> V_61 . V_71 += V_57 ;
V_59 -> V_70 -- ;
V_15:
F_43 ( V_20 ) ;
return V_13 ;
}
void * F_44 ( unsigned int V_57 )
{
return F_34 ( V_57 , V_55 | V_72 ) ;
}
struct V_6 * F_45 ( struct V_73 * V_16 ,
unsigned int V_74 , T_2 V_29 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_57 = F_22 ( V_74 + V_75 ) +
F_22 ( sizeof( struct V_37 ) ) ;
if ( V_57 <= V_66 && ! ( V_29 & ( V_76 | V_77 ) ) ) {
void * V_13 ;
if ( F_20 () )
V_29 |= V_42 ;
V_13 = F_34 ( V_57 , V_29 ) ;
if ( F_39 ( V_13 ) ) {
V_7 = F_32 ( V_13 , V_57 ) ;
if ( F_37 ( ! V_7 ) )
F_2 ( F_46 ( V_13 ) ) ;
}
} else {
V_7 = F_19 ( V_74 + V_75 , V_29 ,
V_41 , V_78 ) ;
}
if ( F_39 ( V_7 ) ) {
F_47 ( V_7 , V_75 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_48 ( struct V_6 * V_7 , int V_79 , struct V_5 * V_5 , int V_80 ,
int V_19 , unsigned int V_32 )
{
F_49 ( V_7 , V_79 , V_5 , V_80 , V_19 ) ;
V_7 -> V_11 += V_19 ;
V_7 -> V_81 += V_19 ;
V_7 -> V_32 += V_32 ;
}
void F_50 ( struct V_6 * V_7 , int V_79 , int V_19 ,
unsigned int V_32 )
{
T_5 * V_61 = & F_28 ( V_7 ) -> V_82 [ V_79 ] ;
F_51 ( V_61 , V_19 ) ;
V_7 -> V_11 += V_19 ;
V_7 -> V_81 += V_19 ;
V_7 -> V_32 += V_32 ;
}
static void F_52 ( struct V_6 * * V_83 )
{
F_53 ( * V_83 ) ;
* V_83 = NULL ;
}
static inline void F_54 ( struct V_6 * V_7 )
{
F_52 ( & F_28 ( V_7 ) -> V_84 ) ;
}
static void F_55 ( struct V_6 * V_7 )
{
struct V_6 * V_85 ;
F_56 (skb, list)
F_57 ( V_85 ) ;
}
static void F_58 ( struct V_6 * V_7 )
{
if ( V_7 -> V_56 )
F_2 ( F_46 ( V_7 -> V_12 ) ) ;
else
F_59 ( V_7 -> V_12 ) ;
}
static void F_60 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_86 ||
! F_61 ( V_7 -> V_87 ? ( 1 << V_88 ) + 1 : 1 ,
& F_28 ( V_7 ) -> V_45 ) ) {
if ( F_28 ( V_7 ) -> V_89 ) {
int V_79 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ )
F_62 ( V_7 , V_79 ) ;
}
if ( F_28 ( V_7 ) -> V_90 & V_91 ) {
struct V_92 * V_93 ;
V_93 = F_28 ( V_7 ) -> V_46 ;
if ( V_93 -> V_94 )
V_93 -> V_94 ( V_93 , true ) ;
}
if ( F_63 ( V_7 ) )
F_54 ( V_7 ) ;
F_58 ( V_7 ) ;
}
}
static void F_64 ( struct V_6 * V_7 )
{
struct V_6 * V_95 ;
T_4 * V_48 ;
switch ( V_7 -> V_51 ) {
case V_53 :
F_31 ( V_30 , V_7 ) ;
break;
case V_52 :
V_48 = ( T_4 * ) ( V_7 + 2 ) ;
if ( F_65 ( V_48 ) )
F_31 ( V_40 , V_7 ) ;
break;
case V_96 :
V_48 = ( T_4 * ) ( V_7 + 1 ) ;
V_95 = V_7 - 1 ;
V_7 -> V_51 = V_53 ;
if ( F_65 ( V_48 ) )
F_31 ( V_40 , V_95 ) ;
break;
}
}
static void F_66 ( struct V_6 * V_7 )
{
F_67 ( V_7 ) ;
#ifdef F_68
F_69 ( V_7 -> V_97 ) ;
#endif
if ( V_7 -> V_98 ) {
F_70 ( F_71 () ) ;
V_7 -> V_98 ( V_7 ) ;
}
#if F_72 ( V_99 )
F_73 ( V_7 -> V_100 ) ;
#endif
#ifdef F_74
F_75 ( V_7 -> V_101 ) ;
#endif
#ifdef F_76
V_7 -> V_102 = 0 ;
#ifdef F_77
V_7 -> V_103 = 0 ;
#endif
#endif
}
static void F_78 ( struct V_6 * V_7 )
{
F_66 ( V_7 ) ;
if ( F_39 ( V_7 -> V_12 ) )
F_60 ( V_7 ) ;
}
void F_79 ( struct V_6 * V_7 )
{
F_78 ( V_7 ) ;
F_64 ( V_7 ) ;
}
void F_80 ( struct V_6 * V_7 )
{
if ( F_37 ( ! V_7 ) )
return;
if ( F_39 ( F_40 ( & V_7 -> V_33 ) == 1 ) )
F_81 () ;
else if ( F_39 ( ! F_65 ( & V_7 -> V_33 ) ) )
return;
F_82 ( V_7 , F_83 ( 0 ) ) ;
F_79 ( V_7 ) ;
}
void F_53 ( struct V_6 * V_104 )
{
while ( V_104 ) {
struct V_6 * V_105 = V_104 -> V_105 ;
F_80 ( V_104 ) ;
V_104 = V_105 ;
}
}
void F_84 ( struct V_6 * V_7 )
{
if ( F_28 ( V_7 ) -> V_90 & V_91 ) {
struct V_92 * V_93 ;
V_93 = F_28 ( V_7 ) -> V_46 ;
if ( V_93 -> V_94 )
V_93 -> V_94 ( V_93 , false ) ;
F_28 ( V_7 ) -> V_90 &= ~ V_91 ;
}
}
void F_85 ( struct V_6 * V_7 )
{
if ( F_37 ( ! V_7 ) )
return;
if ( F_39 ( F_40 ( & V_7 -> V_33 ) == 1 ) )
F_81 () ;
else if ( F_39 ( ! F_65 ( & V_7 -> V_33 ) ) )
return;
F_86 ( V_7 ) ;
F_79 ( V_7 ) ;
}
static void F_87 ( struct V_6 * V_106 , const struct V_6 * V_107 )
{
V_106 -> V_108 = V_107 -> V_108 ;
V_106 -> V_16 = V_107 -> V_16 ;
V_106 -> V_44 = V_107 -> V_44 ;
V_106 -> V_109 = V_107 -> V_109 ;
V_106 -> V_34 = V_107 -> V_34 ;
V_106 -> V_110 = V_107 -> V_110 ;
V_106 -> V_111 = V_107 -> V_111 ;
V_106 -> V_112 = V_107 -> V_112 ;
V_106 -> V_113 = V_107 -> V_113 ;
F_88 ( V_106 , V_107 ) ;
V_106 -> V_114 = V_107 -> V_114 ;
V_106 -> V_115 = V_107 -> V_115 ;
V_106 -> V_116 = V_107 -> V_116 ;
V_106 -> V_117 = V_107 -> V_117 ;
V_106 -> V_118 = V_107 -> V_118 ;
#ifdef F_68
V_106 -> V_97 = F_89 ( V_107 -> V_97 ) ;
#endif
memcpy ( V_106 -> V_119 , V_107 -> V_119 , sizeof( V_107 -> V_119 ) ) ;
V_106 -> V_120 = V_107 -> V_120 ;
V_106 -> V_121 = V_107 -> V_121 ;
V_106 -> V_122 = V_107 -> V_122 ;
V_106 -> V_123 = V_107 -> V_123 ;
F_90 ( V_106 , V_107 ) ;
V_106 -> V_124 = V_107 -> V_124 ;
#if F_72 ( V_125 )
V_106 -> V_126 = V_107 -> V_126 ;
#endif
V_106 -> V_23 = V_107 -> V_23 ;
V_106 -> V_127 = V_107 -> V_127 ;
V_106 -> V_128 = V_107 -> V_128 ;
V_106 -> V_129 = V_107 -> V_129 ;
F_91 ( V_106 , V_107 ) ;
#if F_72 ( V_130 )
V_106 -> V_131 = V_107 -> V_131 ;
#endif
#ifdef F_76
V_106 -> V_102 = V_107 -> V_102 ;
#ifdef F_77
V_106 -> V_103 = V_107 -> V_103 ;
#endif
#endif
V_106 -> V_132 = V_107 -> V_132 ;
V_106 -> V_133 = V_107 -> V_133 ;
F_92 ( V_106 , V_107 ) ;
#ifdef F_93
V_106 -> V_134 = V_107 -> V_134 ;
#endif
}
static struct V_6 * F_94 ( struct V_6 * V_135 , struct V_6 * V_7 )
{
#define F_95 ( T_6 ) n->x = skb->x
V_135 -> V_105 = V_135 -> V_136 = NULL ;
V_135 -> V_137 = NULL ;
F_87 ( V_135 , V_7 ) ;
F_95 ( V_11 ) ;
F_95 ( V_81 ) ;
F_95 ( V_138 ) ;
V_135 -> V_139 = V_7 -> V_87 ? F_96 ( V_7 ) : V_7 -> V_139 ;
V_135 -> V_86 = 1 ;
V_135 -> V_87 = 0 ;
V_135 -> V_98 = NULL ;
F_95 ( V_14 ) ;
F_95 ( V_15 ) ;
F_95 ( V_12 ) ;
F_95 ( V_56 ) ;
F_95 ( V_13 ) ;
F_95 ( V_32 ) ;
F_17 ( & V_135 -> V_33 , 1 ) ;
F_97 ( & ( F_28 ( V_7 ) -> V_45 ) ) ;
V_7 -> V_86 = 1 ;
return V_135 ;
#undef F_95
}
struct V_6 * F_98 ( struct V_6 * V_140 , struct V_6 * V_141 )
{
F_78 ( V_140 ) ;
return F_94 ( V_140 , V_141 ) ;
}
int F_99 ( struct V_6 * V_7 , T_2 V_29 )
{
int V_79 ;
int V_142 = F_28 ( V_7 ) -> V_89 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_92 * V_93 = F_28 ( V_7 ) -> V_46 ;
for ( V_79 = 0 ; V_79 < V_142 ; V_79 ++ ) {
T_3 * V_143 ;
T_5 * V_144 = & F_28 ( V_7 ) -> V_82 [ V_79 ] ;
V_5 = F_100 ( V_29 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_105 = (struct V_5 * ) F_101 ( V_12 ) ;
F_2 ( V_12 ) ;
V_12 = V_105 ;
}
return - V_145 ;
}
V_143 = F_102 ( F_103 ( V_144 ) ) ;
memcpy ( F_42 ( V_5 ) ,
V_143 + V_144 -> V_146 , F_104 ( V_144 ) ) ;
F_105 ( V_143 ) ;
F_106 ( V_5 , ( unsigned long ) V_12 ) ;
V_12 = V_5 ;
}
for ( V_79 = 0 ; V_79 < V_142 ; V_79 ++ )
F_62 ( V_7 , V_79 ) ;
V_93 -> V_94 ( V_93 , false ) ;
for ( V_79 = V_142 - 1 ; V_79 >= 0 ; V_79 -- ) {
F_107 ( V_7 , V_79 , V_12 , 0 ,
F_28 ( V_7 ) -> V_82 [ V_79 ] . V_19 ) ;
V_12 = (struct V_5 * ) F_101 ( V_12 ) ;
}
F_28 ( V_7 ) -> V_90 &= ~ V_91 ;
return 0 ;
}
struct V_6 * F_108 ( struct V_6 * V_7 , T_2 V_29 )
{
struct V_6 * V_135 ;
if ( F_109 ( V_7 , V_29 ) )
return NULL ;
V_135 = V_7 + 1 ;
if ( V_7 -> V_51 == V_52 &&
V_135 -> V_51 == V_53 ) {
T_4 * V_48 = ( T_4 * ) ( V_135 + 1 ) ;
V_135 -> V_51 = V_96 ;
F_97 ( V_48 ) ;
} else {
if ( F_110 ( V_7 ) )
V_29 |= V_42 ;
V_135 = F_33 ( V_30 , V_29 ) ;
if ( ! V_135 )
return NULL ;
F_30 ( V_135 , V_49 ) ;
F_30 ( V_135 , V_50 ) ;
V_135 -> V_51 = V_53 ;
}
return F_94 ( V_135 , V_7 ) ;
}
static void F_111 ( struct V_6 * V_7 , int V_80 )
{
if ( V_7 -> V_123 == V_147 )
V_7 -> V_148 += V_80 ;
V_7 -> V_44 += V_80 ;
V_7 -> V_109 += V_80 ;
if ( F_112 ( V_7 ) )
V_7 -> V_34 += V_80 ;
V_7 -> V_111 += V_80 ;
V_7 -> V_112 += V_80 ;
V_7 -> V_113 += V_80 ;
}
static void F_113 ( struct V_6 * V_106 , const struct V_6 * V_107 )
{
F_87 ( V_106 , V_107 ) ;
F_28 ( V_106 ) -> V_149 = F_28 ( V_107 ) -> V_149 ;
F_28 ( V_106 ) -> V_150 = F_28 ( V_107 ) -> V_150 ;
F_28 ( V_106 ) -> V_151 = F_28 ( V_107 ) -> V_151 ;
}
static inline int F_114 ( const struct V_6 * V_7 )
{
if ( F_110 ( V_7 ) )
return V_41 ;
return 0 ;
}
struct V_6 * F_115 ( const struct V_6 * V_7 , T_2 V_29 )
{
int V_152 = F_96 ( V_7 ) ;
unsigned int V_19 = F_116 ( V_7 ) + V_7 -> V_81 ;
struct V_6 * V_135 = F_19 ( V_19 , V_29 ,
F_114 ( V_7 ) , V_78 ) ;
if ( ! V_135 )
return NULL ;
F_47 ( V_135 , V_152 ) ;
F_117 ( V_135 , V_7 -> V_11 ) ;
if ( F_118 ( V_7 , - V_152 , V_135 -> V_12 , V_152 + V_7 -> V_11 ) )
F_8 () ;
F_113 ( V_135 , V_7 ) ;
return V_135 ;
}
struct V_6 * F_119 ( struct V_6 * V_7 , int V_153 , T_2 V_29 )
{
unsigned int V_19 = F_120 ( V_7 ) + V_153 ;
struct V_6 * V_135 = F_19 ( V_19 , V_29 ,
F_114 ( V_7 ) , V_78 ) ;
if ( ! V_135 )
goto V_28;
F_47 ( V_135 , V_153 ) ;
F_117 ( V_135 , F_120 ( V_7 ) ) ;
F_121 ( V_7 , V_135 -> V_13 , V_135 -> V_11 ) ;
V_135 -> V_32 += V_7 -> V_81 ;
V_135 -> V_81 = V_7 -> V_81 ;
V_135 -> V_11 = V_7 -> V_11 ;
if ( F_28 ( V_7 ) -> V_89 ) {
int V_79 ;
if ( F_109 ( V_7 , V_29 ) ) {
F_80 ( V_135 ) ;
V_135 = NULL ;
goto V_28;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ ) {
F_28 ( V_135 ) -> V_82 [ V_79 ] = F_28 ( V_7 ) -> V_82 [ V_79 ] ;
F_122 ( V_7 , V_79 ) ;
}
F_28 ( V_135 ) -> V_89 = V_79 ;
}
if ( F_63 ( V_7 ) ) {
F_28 ( V_135 ) -> V_84 = F_28 ( V_7 ) -> V_84 ;
F_55 ( V_135 ) ;
}
F_113 ( V_135 , V_7 ) ;
V_28:
return V_135 ;
}
int F_123 ( struct V_6 * V_7 , int V_154 , int V_155 ,
T_2 V_29 )
{
int V_79 ;
T_3 * V_13 ;
int V_19 = V_154 + F_116 ( V_7 ) + V_155 ;
long V_80 ;
F_124 ( V_154 < 0 ) ;
if ( F_125 ( V_7 ) )
F_8 () ;
V_19 = F_22 ( V_19 ) ;
if ( F_110 ( V_7 ) )
V_29 |= V_42 ;
V_13 = F_23 ( V_19 + F_22 ( sizeof( struct V_37 ) ) ,
V_29 , V_78 , NULL ) ;
if ( ! V_13 )
goto V_43;
V_19 = F_24 ( F_25 ( V_13 ) ) ;
memcpy ( V_13 + V_154 , V_7 -> V_12 , F_126 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_37 * ) ( V_13 + V_19 ) ,
F_28 ( V_7 ) ,
F_16 ( struct V_37 , V_82 [ F_28 ( V_7 ) -> V_89 ] ) ) ;
if ( F_127 ( V_7 ) ) {
if ( F_109 ( V_7 , V_29 ) )
goto V_156;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ )
F_122 ( V_7 , V_79 ) ;
if ( F_63 ( V_7 ) )
F_55 ( V_7 ) ;
F_60 ( V_7 ) ;
} else {
F_58 ( V_7 ) ;
}
V_80 = ( V_13 + V_154 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_56 = 0 ;
V_7 -> V_13 += V_80 ;
#ifdef F_128
V_7 -> V_15 = V_19 ;
V_80 = V_154 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_19 ;
#endif
V_7 -> V_14 += V_80 ;
F_111 ( V_7 , V_154 ) ;
V_7 -> V_86 = 0 ;
V_7 -> V_139 = 0 ;
V_7 -> V_87 = 0 ;
F_17 ( & F_28 ( V_7 ) -> V_45 , 1 ) ;
return 0 ;
V_156:
F_59 ( V_13 ) ;
V_43:
return - V_145 ;
}
struct V_6 * F_129 ( struct V_6 * V_7 , unsigned int V_153 )
{
struct V_6 * V_157 ;
int V_158 = V_153 - F_96 ( V_7 ) ;
if ( V_158 <= 0 )
V_157 = F_130 ( V_7 , V_55 ) ;
else {
V_157 = F_108 ( V_7 , V_55 ) ;
if ( V_157 && F_123 ( V_157 , F_22 ( V_158 ) , 0 ,
V_55 ) ) {
F_80 ( V_157 ) ;
V_157 = NULL ;
}
}
return V_157 ;
}
struct V_6 * F_131 ( const struct V_6 * V_7 ,
int V_159 , int V_160 ,
T_2 V_29 )
{
struct V_6 * V_135 = F_19 ( V_159 + V_7 -> V_11 + V_160 ,
V_29 , F_114 ( V_7 ) ,
V_78 ) ;
int V_161 = F_96 ( V_7 ) ;
int V_162 , V_163 ;
if ( ! V_135 )
return NULL ;
F_47 ( V_135 , V_159 ) ;
F_117 ( V_135 , V_7 -> V_11 ) ;
V_162 = V_161 ;
V_163 = 0 ;
if ( V_159 <= V_162 )
V_162 = V_159 ;
else
V_163 = V_159 - V_162 ;
if ( F_118 ( V_7 , - V_162 , V_135 -> V_12 + V_163 ,
V_7 -> V_11 + V_162 ) )
F_8 () ;
F_113 ( V_135 , V_7 ) ;
F_111 ( V_135 , V_159 - V_161 ) ;
return V_135 ;
}
int F_132 ( struct V_6 * V_7 , int V_164 )
{
int V_165 ;
int V_155 ;
if ( ! F_127 ( V_7 ) && F_133 ( V_7 ) >= V_164 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_164 ) ;
return 0 ;
}
V_155 = V_7 -> V_81 + V_164 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_39 ( F_127 ( V_7 ) || V_155 > 0 ) ) {
V_165 = F_123 ( V_7 , 0 , V_155 , V_55 ) ;
if ( F_37 ( V_165 ) )
goto V_166;
}
V_165 = F_134 ( V_7 ) ;
if ( F_37 ( V_165 ) )
goto V_166;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_164 ) ;
return 0 ;
V_166:
F_80 ( V_7 ) ;
return V_165 ;
}
unsigned char * F_135 ( struct V_6 * V_7 , struct V_6 * V_14 , int V_11 )
{
if ( V_14 != V_7 ) {
V_7 -> V_81 += V_11 ;
V_7 -> V_11 += V_11 ;
}
return F_117 ( V_14 , V_11 ) ;
}
unsigned char * F_117 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_167 = F_126 ( V_7 ) ;
F_136 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_37 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_9 ( V_7 , V_11 , F_83 ( 0 ) ) ;
return V_167 ;
}
unsigned char * F_137 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_37 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_10 ( V_7 , V_11 , F_83 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_138 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_139 ( V_7 , V_11 ) ;
}
void F_140 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_141 ( V_7 , V_11 ) ;
}
int F_142 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_168 ;
struct V_6 * V_61 ;
int V_71 = F_120 ( V_7 ) ;
int V_169 = F_28 ( V_7 ) -> V_89 ;
int V_79 ;
int V_165 ;
if ( F_127 ( V_7 ) &&
F_37 ( ( V_165 = F_123 ( V_7 , 0 , 0 , V_55 ) ) ) )
return V_165 ;
V_79 = 0 ;
if ( V_71 >= V_11 )
goto V_170;
for (; V_79 < V_169 ; V_79 ++ ) {
int V_15 = V_71 + F_104 ( & F_28 ( V_7 ) -> V_82 [ V_79 ] ) ;
if ( V_15 < V_11 ) {
V_71 = V_15 ;
continue;
}
F_143 ( & F_28 ( V_7 ) -> V_82 [ V_79 ++ ] , V_11 - V_71 ) ;
V_170:
F_28 ( V_7 ) -> V_89 = V_79 ;
for (; V_79 < V_169 ; V_79 ++ )
F_62 ( V_7 , V_79 ) ;
if ( F_63 ( V_7 ) )
F_54 ( V_7 ) ;
goto V_171;
}
for ( V_168 = & F_28 ( V_7 ) -> V_84 ; ( V_61 = * V_168 ) ;
V_168 = & V_61 -> V_105 ) {
int V_15 = V_71 + V_61 -> V_11 ;
if ( F_125 ( V_61 ) ) {
struct V_6 * V_172 ;
V_172 = F_108 ( V_61 , V_55 ) ;
if ( F_37 ( ! V_172 ) )
return - V_145 ;
V_172 -> V_105 = V_61 -> V_105 ;
F_85 ( V_61 ) ;
V_61 = V_172 ;
* V_168 = V_61 ;
}
if ( V_15 < V_11 ) {
V_71 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_37 ( ( V_165 = F_144 ( V_61 , V_11 - V_71 ) ) ) )
return V_165 ;
if ( V_61 -> V_105 )
F_52 ( & V_61 -> V_105 ) ;
break;
}
V_171:
if ( V_11 > F_120 ( V_7 ) ) {
V_7 -> V_81 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_81 = 0 ;
F_145 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_146 ( struct V_6 * V_7 , int V_158 )
{
int V_79 , V_173 , V_174 = ( V_7 -> V_14 + V_158 ) - V_7 -> V_15 ;
if ( V_174 > 0 || F_127 ( V_7 ) ) {
if ( F_123 ( V_7 , 0 , V_174 > 0 ? V_174 + 128 : 0 ,
V_55 ) )
return NULL ;
}
if ( F_118 ( V_7 , F_120 ( V_7 ) , F_126 ( V_7 ) , V_158 ) )
F_8 () ;
if ( ! F_63 ( V_7 ) )
goto V_175;
V_174 = V_158 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ ) {
int V_19 = F_104 ( & F_28 ( V_7 ) -> V_82 [ V_79 ] ) ;
if ( V_19 >= V_174 )
goto V_175;
V_174 -= V_19 ;
}
if ( V_174 ) {
struct V_6 * V_85 = F_28 ( V_7 ) -> V_84 ;
struct V_6 * V_176 = NULL ;
struct V_6 * V_177 = NULL ;
do {
F_124 ( ! V_85 ) ;
if ( V_85 -> V_11 <= V_174 ) {
V_174 -= V_85 -> V_11 ;
V_85 = V_85 -> V_105 ;
V_177 = V_85 ;
} else {
if ( F_125 ( V_85 ) ) {
V_176 = F_108 ( V_85 , V_55 ) ;
if ( ! V_176 )
return NULL ;
V_177 = V_85 -> V_105 ;
V_85 = V_176 ;
} else {
V_177 = V_85 ;
}
if ( ! F_147 ( V_85 , V_174 ) ) {
F_80 ( V_176 ) ;
return NULL ;
}
break;
}
} while ( V_174 );
while ( ( V_85 = F_28 ( V_7 ) -> V_84 ) != V_177 ) {
F_28 ( V_7 ) -> V_84 = V_85 -> V_105 ;
F_80 ( V_85 ) ;
}
if ( V_176 ) {
V_176 -> V_105 = V_85 ;
F_28 ( V_7 ) -> V_84 = V_176 ;
}
}
V_175:
V_174 = V_158 ;
V_173 = 0 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ ) {
int V_19 = F_104 ( & F_28 ( V_7 ) -> V_82 [ V_79 ] ) ;
if ( V_19 <= V_174 ) {
F_62 ( V_7 , V_79 ) ;
V_174 -= V_19 ;
} else {
F_28 ( V_7 ) -> V_82 [ V_173 ] = F_28 ( V_7 ) -> V_82 [ V_79 ] ;
if ( V_174 ) {
F_28 ( V_7 ) -> V_82 [ V_173 ] . V_146 += V_174 ;
F_148 ( & F_28 ( V_7 ) -> V_82 [ V_173 ] , V_174 ) ;
V_174 = 0 ;
}
V_173 ++ ;
}
}
F_28 ( V_7 ) -> V_89 = V_173 ;
V_7 -> V_14 += V_158 ;
V_7 -> V_81 -= V_158 ;
return F_126 ( V_7 ) ;
}
int F_118 ( const struct V_6 * V_7 , int V_71 , void * V_178 , int V_11 )
{
int V_179 = F_120 ( V_7 ) ;
struct V_6 * V_180 ;
int V_79 , V_181 ;
if ( V_71 > ( int ) V_7 -> V_11 - V_11 )
goto V_182;
if ( ( V_181 = V_179 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
F_149 ( V_7 , V_71 , V_178 , V_181 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_178 += V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ ) {
int V_15 ;
T_5 * V_144 = & F_28 ( V_7 ) -> V_82 [ V_79 ] ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_104 ( V_144 ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_3 * V_143 ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_143 = F_102 ( F_103 ( V_144 ) ) ;
memcpy ( V_178 ,
V_143 + V_144 -> V_146 + V_71 - V_179 ,
V_181 ) ;
F_105 ( V_143 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_178 += V_181 ;
}
V_179 = V_15 ;
}
F_56 (skb, frag_iter) {
int V_15 ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
if ( F_118 ( V_180 , V_71 - V_179 , V_178 , V_181 ) )
goto V_182;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_178 += V_181 ;
}
V_179 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_182:
return - V_183 ;
}
static void F_150 ( struct V_184 * V_185 , unsigned int V_79 )
{
F_2 ( V_185 -> V_186 [ V_79 ] ) ;
}
static struct V_5 * F_151 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_71 ,
struct V_187 * V_137 )
{
struct V_188 * V_189 = F_152 ( V_137 ) ;
if ( ! F_153 ( V_137 , V_189 ) )
return NULL ;
* V_11 = F_154 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_42 ( V_189 -> V_5 ) + V_189 -> V_71 ,
F_42 ( V_5 ) + * V_71 , * V_11 ) ;
* V_71 = V_189 -> V_71 ;
V_189 -> V_71 += * V_11 ;
return V_189 -> V_5 ;
}
static bool F_155 ( const struct V_184 * V_185 ,
struct V_5 * V_5 ,
unsigned int V_71 )
{
return V_185 -> V_190 &&
V_185 -> V_186 [ V_185 -> V_190 - 1 ] == V_5 &&
( V_185 -> V_191 [ V_185 -> V_190 - 1 ] . V_71 +
V_185 -> V_191 [ V_185 -> V_190 - 1 ] . V_11 == V_71 ) ;
}
static bool F_156 ( struct V_184 * V_185 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_71 ,
bool V_192 ,
struct V_187 * V_137 )
{
if ( F_37 ( V_185 -> V_190 == V_193 ) )
return true ;
if ( V_192 ) {
V_5 = F_151 ( V_5 , V_11 , & V_71 , V_137 ) ;
if ( ! V_5 )
return true ;
}
if ( F_155 ( V_185 , V_5 , V_71 ) ) {
V_185 -> V_191 [ V_185 -> V_190 - 1 ] . V_11 += * V_11 ;
return false ;
}
F_4 ( V_5 ) ;
V_185 -> V_186 [ V_185 -> V_190 ] = V_5 ;
V_185 -> V_191 [ V_185 -> V_190 ] . V_11 = * V_11 ;
V_185 -> V_191 [ V_185 -> V_190 ] . V_71 = V_71 ;
V_185 -> V_190 ++ ;
return false ;
}
static bool F_157 ( struct V_5 * V_5 , unsigned int V_194 ,
unsigned int V_195 , unsigned int * V_80 ,
unsigned int * V_11 ,
struct V_184 * V_185 , bool V_192 ,
struct V_187 * V_137 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return true ;
if ( * V_80 >= V_195 ) {
* V_80 -= V_195 ;
return false ;
}
V_194 += * V_80 ;
V_195 -= * V_80 ;
* V_80 = 0 ;
do {
unsigned int V_196 = F_158 ( * V_11 , V_195 ) ;
if ( F_156 ( V_185 , V_2 , V_5 , & V_196 , V_194 ,
V_192 , V_137 ) )
return true ;
V_194 += V_196 ;
V_195 -= V_196 ;
* V_11 -= V_196 ;
} while ( * V_11 && V_195 );
return false ;
}
static bool F_159 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_71 , unsigned int * V_11 ,
struct V_184 * V_185 , struct V_187 * V_137 )
{
int V_197 ;
if ( F_157 ( F_160 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_66 - 1 ) ,
F_120 ( V_7 ) ,
V_71 , V_11 , V_185 ,
F_161 ( V_7 ) ,
V_137 , V_2 ) )
return true ;
for ( V_197 = 0 ; V_197 < F_28 ( V_7 ) -> V_89 ; V_197 ++ ) {
const T_5 * V_144 = & F_28 ( V_7 ) -> V_82 [ V_197 ] ;
if ( F_157 ( F_103 ( V_144 ) ,
V_144 -> V_146 , F_104 ( V_144 ) ,
V_71 , V_11 , V_185 , false , V_137 , V_2 ) )
return true ;
}
return false ;
}
int F_162 ( struct V_6 * V_7 , unsigned int V_71 ,
struct V_1 * V_2 , unsigned int V_198 ,
unsigned int V_20 )
{
struct V_199 V_191 [ V_193 ] ;
struct V_5 * V_186 [ V_193 ] ;
struct V_184 V_185 = {
. V_186 = V_186 ,
. V_191 = V_191 ,
. V_200 = V_193 ,
. V_20 = V_20 ,
. V_201 = & V_202 ,
. V_203 = F_150 ,
} ;
struct V_6 * V_180 ;
struct V_187 * V_137 = V_7 -> V_137 ;
int V_204 = 0 ;
if ( F_159 ( V_7 , V_2 , & V_71 , & V_198 , & V_185 , V_137 ) )
goto V_171;
else if ( ! V_198 )
goto V_171;
F_56 (skb, frag_iter) {
if ( ! V_198 )
break;
if ( F_159 ( V_180 , V_2 , & V_71 , & V_198 , & V_185 , V_137 ) )
break;
}
V_171:
if ( V_185 . V_190 ) {
F_163 ( V_137 ) ;
V_204 = F_164 ( V_2 , & V_185 ) ;
F_165 ( V_137 ) ;
}
return V_204 ;
}
int F_166 ( struct V_6 * V_7 , int V_71 , const void * V_205 , int V_11 )
{
int V_179 = F_120 ( V_7 ) ;
struct V_6 * V_180 ;
int V_79 , V_181 ;
if ( V_71 > ( int ) V_7 -> V_11 - V_11 )
goto V_182;
if ( ( V_181 = V_179 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
F_167 ( V_7 , V_71 , V_205 , V_181 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_205 += V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ ) {
T_5 * V_61 = & F_28 ( V_7 ) -> V_82 [ V_79 ] ;
int V_15 ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_104 ( V_61 ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_3 * V_143 ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_143 = F_102 ( F_103 ( V_61 ) ) ;
memcpy ( V_143 + V_61 -> V_146 + V_71 - V_179 ,
V_205 , V_181 ) ;
F_105 ( V_143 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_205 += V_181 ;
}
V_179 = V_15 ;
}
F_56 (skb, frag_iter) {
int V_15 ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
if ( F_166 ( V_180 , V_71 - V_179 ,
V_205 , V_181 ) )
goto V_182;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_205 += V_181 ;
}
V_179 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_182:
return - V_183 ;
}
T_7 F_168 ( const struct V_6 * V_7 , int V_71 , int V_11 ,
T_7 V_120 , const struct V_206 * V_201 )
{
int V_179 = F_120 ( V_7 ) ;
int V_79 , V_181 = V_179 - V_71 ;
struct V_6 * V_180 ;
int V_207 = 0 ;
if ( V_181 > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
V_120 = V_201 -> V_208 ( V_7 -> V_13 + V_71 , V_181 , V_120 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_120 ;
V_71 += V_181 ;
V_207 = V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ ) {
int V_15 ;
T_5 * V_61 = & F_28 ( V_7 ) -> V_82 [ V_79 ] ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_104 ( V_61 ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_7 V_209 ;
T_3 * V_143 ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_143 = F_102 ( F_103 ( V_61 ) ) ;
V_209 = V_201 -> V_208 ( V_143 + V_61 -> V_146 +
V_71 - V_179 , V_181 , 0 ) ;
F_105 ( V_143 ) ;
V_120 = V_201 -> V_210 ( V_120 , V_209 , V_207 , V_181 ) ;
if ( ! ( V_11 -= V_181 ) )
return V_120 ;
V_71 += V_181 ;
V_207 += V_181 ;
}
V_179 = V_15 ;
}
F_56 (skb, frag_iter) {
int V_15 ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_7 V_209 ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_209 = F_168 ( V_180 , V_71 - V_179 ,
V_181 , 0 , V_201 ) ;
V_120 = V_201 -> V_210 ( V_120 , V_209 , V_207 , V_181 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_120 ;
V_71 += V_181 ;
V_207 += V_181 ;
}
V_179 = V_15 ;
}
F_124 ( V_11 ) ;
return V_120 ;
}
T_7 F_169 ( const struct V_6 * V_7 , int V_71 ,
int V_11 , T_7 V_120 )
{
const struct V_206 V_201 = {
. V_208 = V_211 ,
. V_210 = V_212 ,
} ;
return F_168 ( V_7 , V_71 , V_11 , V_120 , & V_201 ) ;
}
T_7 F_170 ( const struct V_6 * V_7 , int V_71 ,
T_3 * V_178 , int V_11 , T_7 V_120 )
{
int V_179 = F_120 ( V_7 ) ;
int V_79 , V_181 = V_179 - V_71 ;
struct V_6 * V_180 ;
int V_207 = 0 ;
if ( V_181 > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
V_120 = F_171 ( V_7 -> V_13 + V_71 , V_178 ,
V_181 , V_120 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_120 ;
V_71 += V_181 ;
V_178 += V_181 ;
V_207 = V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ ) {
int V_15 ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_104 ( & F_28 ( V_7 ) -> V_82 [ V_79 ] ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_7 V_209 ;
T_3 * V_143 ;
T_5 * V_61 = & F_28 ( V_7 ) -> V_82 [ V_79 ] ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_143 = F_102 ( F_103 ( V_61 ) ) ;
V_209 = F_171 ( V_143 +
V_61 -> V_146 +
V_71 - V_179 , V_178 ,
V_181 , 0 ) ;
F_105 ( V_143 ) ;
V_120 = F_172 ( V_120 , V_209 , V_207 ) ;
if ( ! ( V_11 -= V_181 ) )
return V_120 ;
V_71 += V_181 ;
V_178 += V_181 ;
V_207 += V_181 ;
}
V_179 = V_15 ;
}
F_56 (skb, frag_iter) {
T_7 V_209 ;
int V_15 ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
V_209 = F_170 ( V_180 ,
V_71 - V_179 ,
V_178 , V_181 , 0 ) ;
V_120 = F_172 ( V_120 , V_209 , V_207 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_120 ;
V_71 += V_181 ;
V_178 += V_181 ;
V_207 += V_181 ;
}
V_179 = V_15 ;
}
F_124 ( V_11 ) ;
return V_120 ;
}
void F_173 ( const struct V_6 * V_7 , T_3 * V_178 )
{
T_7 V_120 ;
long V_213 ;
if ( V_7 -> V_123 == V_147 )
V_213 = F_174 ( V_7 ) ;
else
V_213 = F_120 ( V_7 ) ;
F_124 ( V_213 > F_120 ( V_7 ) ) ;
F_121 ( V_7 , V_178 , V_213 ) ;
V_120 = 0 ;
if ( V_213 != V_7 -> V_11 )
V_120 = F_170 ( V_7 , V_213 , V_178 + V_213 ,
V_7 -> V_11 - V_213 , 0 ) ;
if ( V_7 -> V_123 == V_147 ) {
long V_214 = V_213 + V_7 -> V_215 ;
* ( ( V_216 * ) ( V_178 + V_214 ) ) = F_175 ( V_120 ) ;
}
}
struct V_6 * F_176 ( struct V_217 * V_85 )
{
unsigned long V_20 ;
struct V_6 * V_218 ;
F_177 ( & V_85 -> V_219 , V_20 ) ;
V_218 = F_178 ( V_85 ) ;
F_179 ( & V_85 -> V_219 , V_20 ) ;
return V_218 ;
}
struct V_6 * F_180 ( struct V_217 * V_85 )
{
unsigned long V_20 ;
struct V_6 * V_218 ;
F_177 ( & V_85 -> V_219 , V_20 ) ;
V_218 = F_181 ( V_85 ) ;
F_179 ( & V_85 -> V_219 , V_20 ) ;
return V_218 ;
}
void F_182 ( struct V_217 * V_85 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_176 ( V_85 ) ) != NULL )
F_80 ( V_7 ) ;
}
void F_183 ( struct V_217 * V_85 , struct V_6 * V_220 )
{
unsigned long V_20 ;
F_177 ( & V_85 -> V_219 , V_20 ) ;
F_184 ( V_85 , V_220 ) ;
F_179 ( & V_85 -> V_219 , V_20 ) ;
}
void F_185 ( struct V_217 * V_85 , struct V_6 * V_220 )
{
unsigned long V_20 ;
F_177 ( & V_85 -> V_219 , V_20 ) ;
F_186 ( V_85 , V_220 ) ;
F_179 ( & V_85 -> V_219 , V_20 ) ;
}
void F_187 ( struct V_6 * V_7 , struct V_217 * V_85 )
{
unsigned long V_20 ;
F_177 ( & V_85 -> V_219 , V_20 ) ;
F_188 ( V_7 , V_85 ) ;
F_179 ( & V_85 -> V_219 , V_20 ) ;
}
void F_189 ( struct V_6 * V_107 , struct V_6 * V_220 , struct V_217 * V_85 )
{
unsigned long V_20 ;
F_177 ( & V_85 -> V_219 , V_20 ) ;
F_190 ( V_85 , V_107 , V_220 ) ;
F_179 ( & V_85 -> V_219 , V_20 ) ;
}
void F_191 ( struct V_6 * V_107 , struct V_6 * V_220 , struct V_217 * V_85 )
{
unsigned long V_20 ;
F_177 ( & V_85 -> V_219 , V_20 ) ;
F_192 ( V_220 , V_107 -> V_136 , V_107 , V_85 ) ;
F_179 ( & V_85 -> V_219 , V_20 ) ;
}
static inline void F_193 ( struct V_6 * V_7 ,
struct V_6 * V_221 ,
const T_8 V_11 , const int V_207 )
{
int V_79 ;
F_149 ( V_7 , V_11 , F_117 ( V_221 , V_207 - V_11 ) ,
V_207 - V_11 ) ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ )
F_28 ( V_221 ) -> V_82 [ V_79 ] = F_28 ( V_7 ) -> V_82 [ V_79 ] ;
F_28 ( V_221 ) -> V_89 = F_28 ( V_7 ) -> V_89 ;
F_28 ( V_7 ) -> V_89 = 0 ;
V_221 -> V_81 = V_7 -> V_81 ;
V_221 -> V_11 += V_221 -> V_81 ;
V_7 -> V_81 = 0 ;
V_7 -> V_11 = V_11 ;
F_145 ( V_7 , V_11 ) ;
}
static inline void F_194 ( struct V_6 * V_7 ,
struct V_6 * V_221 ,
const T_8 V_11 , int V_207 )
{
int V_79 , V_173 = 0 ;
const int V_169 = F_28 ( V_7 ) -> V_89 ;
F_28 ( V_7 ) -> V_89 = 0 ;
V_221 -> V_11 = V_221 -> V_81 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_81 = V_11 - V_207 ;
for ( V_79 = 0 ; V_79 < V_169 ; V_79 ++ ) {
int V_19 = F_104 ( & F_28 ( V_7 ) -> V_82 [ V_79 ] ) ;
if ( V_207 + V_19 > V_11 ) {
F_28 ( V_221 ) -> V_82 [ V_173 ] = F_28 ( V_7 ) -> V_82 [ V_79 ] ;
if ( V_207 < V_11 ) {
F_122 ( V_7 , V_79 ) ;
F_28 ( V_221 ) -> V_82 [ 0 ] . V_146 += V_11 - V_207 ;
F_148 ( & F_28 ( V_221 ) -> V_82 [ 0 ] , V_11 - V_207 ) ;
F_143 ( & F_28 ( V_7 ) -> V_82 [ V_79 ] , V_11 - V_207 ) ;
F_28 ( V_7 ) -> V_89 ++ ;
}
V_173 ++ ;
} else
F_28 ( V_7 ) -> V_89 ++ ;
V_207 += V_19 ;
}
F_28 ( V_221 ) -> V_89 = V_173 ;
}
void F_195 ( struct V_6 * V_7 , struct V_6 * V_221 , const T_8 V_11 )
{
int V_207 = F_120 ( V_7 ) ;
F_28 ( V_221 ) -> V_90 = F_28 ( V_7 ) -> V_90 & V_222 ;
if ( V_11 < V_207 )
F_193 ( V_7 , V_221 , V_11 , V_207 ) ;
else
F_194 ( V_7 , V_221 , V_11 , V_207 ) ;
}
static int F_196 ( struct V_6 * V_7 )
{
return F_127 ( V_7 ) && F_123 ( V_7 , 0 , 0 , V_55 ) ;
}
int F_197 ( struct V_6 * V_223 , struct V_6 * V_7 , int V_224 )
{
int V_205 , V_178 , V_225 , V_226 ;
struct V_227 * V_228 , * V_229 ;
F_124 ( V_224 > V_7 -> V_11 ) ;
F_124 ( F_120 ( V_7 ) ) ;
V_226 = V_224 ;
V_205 = 0 ;
V_178 = F_28 ( V_223 ) -> V_89 ;
V_228 = & F_28 ( V_7 ) -> V_82 [ V_205 ] ;
if ( ! V_178 ||
! F_198 ( V_223 , V_178 , F_103 ( V_228 ) ,
V_228 -> V_146 ) ) {
V_225 = - 1 ;
} else {
V_225 = V_178 - 1 ;
V_226 -= F_104 ( V_228 ) ;
if ( V_226 < 0 ) {
if ( F_196 ( V_7 ) ||
F_196 ( V_223 ) )
return 0 ;
V_228 = & F_28 ( V_7 ) -> V_82 [ V_205 ] ;
V_229 = & F_28 ( V_223 ) -> V_82 [ V_225 ] ;
F_51 ( V_229 , V_224 ) ;
F_148 ( V_228 , V_224 ) ;
V_228 -> V_146 += V_224 ;
goto V_230;
}
V_205 ++ ;
}
if ( ( V_224 == V_7 -> V_11 ) &&
( F_28 ( V_7 ) -> V_89 - V_205 ) > ( V_193 - V_178 ) )
return 0 ;
if ( F_196 ( V_7 ) || F_196 ( V_223 ) )
return 0 ;
while ( ( V_226 > 0 ) && ( V_205 < F_28 ( V_7 ) -> V_89 ) ) {
if ( V_178 == V_193 )
return 0 ;
V_228 = & F_28 ( V_7 ) -> V_82 [ V_205 ] ;
V_229 = & F_28 ( V_223 ) -> V_82 [ V_178 ] ;
if ( V_226 >= F_104 ( V_228 ) ) {
* V_229 = * V_228 ;
V_226 -= F_104 ( V_228 ) ;
V_205 ++ ;
V_178 ++ ;
} else {
F_199 ( V_228 ) ;
V_229 -> V_5 = V_228 -> V_5 ;
V_229 -> V_146 = V_228 -> V_146 ;
F_143 ( V_229 , V_226 ) ;
V_228 -> V_146 += V_226 ;
F_148 ( V_228 , V_226 ) ;
V_226 = 0 ;
V_178 ++ ;
break;
}
}
F_28 ( V_223 ) -> V_89 = V_178 ;
if ( V_225 >= 0 ) {
V_228 = & F_28 ( V_7 ) -> V_82 [ 0 ] ;
V_229 = & F_28 ( V_223 ) -> V_82 [ V_225 ] ;
F_51 ( V_229 , F_104 ( V_228 ) ) ;
F_200 ( V_228 ) ;
}
V_178 = 0 ;
while ( V_205 < F_28 ( V_7 ) -> V_89 )
F_28 ( V_7 ) -> V_82 [ V_178 ++ ] = F_28 ( V_7 ) -> V_82 [ V_205 ++ ] ;
F_28 ( V_7 ) -> V_89 = V_178 ;
F_124 ( V_226 > 0 && ! F_28 ( V_7 ) -> V_89 ) ;
V_230:
V_223 -> V_123 = V_147 ;
V_7 -> V_123 = V_147 ;
V_7 -> V_11 -= V_224 ;
V_7 -> V_81 -= V_224 ;
V_7 -> V_32 -= V_224 ;
V_223 -> V_11 += V_224 ;
V_223 -> V_81 += V_224 ;
V_223 -> V_32 += V_224 ;
return V_224 ;
}
void F_201 ( struct V_6 * V_7 , unsigned int V_205 ,
unsigned int V_178 , struct V_231 * V_232 )
{
V_232 -> V_233 = V_205 ;
V_232 -> V_234 = V_178 ;
V_232 -> V_235 = V_232 -> V_236 = V_7 ;
V_232 -> V_237 = V_232 -> V_238 = 0 ;
V_232 -> V_239 = NULL ;
}
unsigned int F_202 ( unsigned int V_240 , const T_3 * * V_13 ,
struct V_231 * V_232 )
{
unsigned int V_241 , V_242 = V_240 + V_232 -> V_233 ;
T_5 * V_61 ;
if ( F_37 ( V_242 >= V_232 -> V_234 ) ) {
if ( V_232 -> V_239 ) {
F_105 ( V_232 -> V_239 ) ;
V_232 -> V_239 = NULL ;
}
return 0 ;
}
V_243:
V_241 = F_120 ( V_232 -> V_236 ) + V_232 -> V_238 ;
if ( V_242 < V_241 && ! V_232 -> V_239 ) {
* V_13 = V_232 -> V_236 -> V_13 + ( V_242 - V_232 -> V_238 ) ;
return V_241 - V_242 ;
}
if ( V_232 -> V_237 == 0 && ! V_232 -> V_239 )
V_232 -> V_238 += F_120 ( V_232 -> V_236 ) ;
while ( V_232 -> V_237 < F_28 ( V_232 -> V_236 ) -> V_89 ) {
V_61 = & F_28 ( V_232 -> V_236 ) -> V_82 [ V_232 -> V_237 ] ;
V_241 = F_104 ( V_61 ) + V_232 -> V_238 ;
if ( V_242 < V_241 ) {
if ( ! V_232 -> V_239 )
V_232 -> V_239 = F_102 ( F_103 ( V_61 ) ) ;
* V_13 = ( T_3 * ) V_232 -> V_239 + V_61 -> V_146 +
( V_242 - V_232 -> V_238 ) ;
return V_241 - V_242 ;
}
if ( V_232 -> V_239 ) {
F_105 ( V_232 -> V_239 ) ;
V_232 -> V_239 = NULL ;
}
V_232 -> V_237 ++ ;
V_232 -> V_238 += F_104 ( V_61 ) ;
}
if ( V_232 -> V_239 ) {
F_105 ( V_232 -> V_239 ) ;
V_232 -> V_239 = NULL ;
}
if ( V_232 -> V_235 == V_232 -> V_236 && F_63 ( V_232 -> V_235 ) ) {
V_232 -> V_236 = F_28 ( V_232 -> V_235 ) -> V_84 ;
V_232 -> V_237 = 0 ;
goto V_243;
} else if ( V_232 -> V_236 -> V_105 ) {
V_232 -> V_236 = V_232 -> V_236 -> V_105 ;
V_232 -> V_237 = 0 ;
goto V_243;
}
return 0 ;
}
void F_203 ( struct V_231 * V_232 )
{
if ( V_232 -> V_239 )
F_105 ( V_232 -> V_239 ) ;
}
static unsigned int F_204 ( unsigned int V_71 , const T_3 * * V_244 ,
struct V_245 * V_246 ,
struct V_247 * V_248 )
{
return F_202 ( V_71 , V_244 , F_205 ( V_248 ) ) ;
}
static void F_206 ( struct V_245 * V_246 , struct V_247 * V_248 )
{
F_203 ( F_205 ( V_248 ) ) ;
}
unsigned int F_207 ( struct V_6 * V_7 , unsigned int V_205 ,
unsigned int V_178 , struct V_245 * V_249 ,
struct V_247 * V_248 )
{
unsigned int V_204 ;
V_249 -> V_250 = F_204 ;
V_249 -> V_251 = F_206 ;
F_201 ( V_7 , V_205 , V_178 , F_205 ( V_248 ) ) ;
V_204 = F_208 ( V_249 , V_248 ) ;
return ( V_204 <= V_178 - V_205 ? V_204 : V_252 ) ;
}
int F_209 ( struct V_187 * V_137 , struct V_6 * V_7 ,
int (* F_210)( void * V_205 , char * V_178 , int V_71 ,
int V_11 , int V_253 , struct V_6 * V_7 ) ,
void * V_205 , int V_74 )
{
int V_254 = F_28 ( V_7 ) -> V_89 ;
int V_181 ;
int V_71 = 0 ;
int V_204 ;
struct V_188 * V_189 = & V_255 -> V_256 ;
do {
if ( V_254 >= V_193 )
return - V_257 ;
if ( ! F_153 ( V_137 , V_189 ) )
return - V_145 ;
V_181 = F_154 ( int , V_74 , V_189 -> V_19 - V_189 -> V_71 ) ;
V_204 = F_210 ( V_205 , F_42 ( V_189 -> V_5 ) + V_189 -> V_71 ,
V_71 , V_181 , 0 , V_7 ) ;
if ( V_204 < 0 )
return - V_183 ;
F_49 ( V_7 , V_254 , V_189 -> V_5 , V_189 -> V_71 ,
V_181 ) ;
V_254 ++ ;
V_189 -> V_71 += V_181 ;
F_4 ( V_189 -> V_5 ) ;
V_7 -> V_32 += V_181 ;
F_211 ( V_181 , & V_137 -> V_258 ) ;
V_7 -> V_11 += V_181 ;
V_7 -> V_81 += V_181 ;
V_71 += V_181 ;
V_74 -= V_181 ;
} while ( V_74 > 0 );
return 0 ;
}
unsigned char * F_212 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_124 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_124 ( V_7 -> V_11 < V_7 -> V_81 ) ;
F_213 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_214 ( struct V_6 * V_7 , T_9 V_259 )
{
struct V_6 * V_104 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_260 = F_28 ( V_7 ) -> V_84 ;
T_5 * V_261 = F_28 ( V_7 ) -> V_82 ;
unsigned int V_262 = F_28 ( V_7 ) -> V_149 ;
unsigned int V_263 = V_7 -> V_13 - F_215 ( V_7 ) ;
unsigned int V_71 = V_263 ;
unsigned int V_264 = F_216 ( V_7 ) ;
unsigned int V_153 ;
unsigned int V_11 ;
T_10 V_265 ;
bool V_120 ;
int V_266 = ! ! ( V_259 & V_267 ) ;
int V_169 = F_28 ( V_7 ) -> V_89 ;
int V_165 = - V_145 ;
int V_79 = 0 ;
int V_207 ;
V_265 = F_217 ( V_7 ) ;
if ( F_37 ( ! V_265 ) )
return F_218 ( - V_268 ) ;
V_120 = ! ! F_219 ( V_259 , V_265 ) ;
F_220 ( V_7 , V_263 ) ;
V_153 = F_96 ( V_7 ) ;
V_207 = F_120 ( V_7 ) ;
do {
struct V_6 * V_269 ;
T_5 * V_61 ;
int V_270 ;
int V_19 ;
V_11 = V_7 -> V_11 - V_71 ;
if ( V_11 > V_262 )
V_11 = V_262 ;
V_270 = F_120 ( V_7 ) - V_71 ;
if ( V_270 < 0 )
V_270 = 0 ;
if ( V_270 > V_11 || ! V_266 )
V_270 = V_11 ;
if ( ! V_270 && V_79 >= V_169 && F_120 ( V_260 ) &&
( F_120 ( V_260 ) == V_11 || V_266 ) ) {
F_124 ( F_120 ( V_260 ) > V_11 ) ;
V_79 = 0 ;
V_169 = F_28 ( V_260 ) -> V_89 ;
V_261 = F_28 ( V_260 ) -> V_82 ;
V_207 += F_120 ( V_260 ) ;
while ( V_207 < V_71 + V_11 ) {
F_124 ( V_79 >= V_169 ) ;
V_19 = F_104 ( V_261 ) ;
if ( V_207 + V_19 > V_71 + V_11 )
break;
V_79 ++ ;
V_207 += V_19 ;
V_261 ++ ;
}
V_269 = F_108 ( V_260 , V_55 ) ;
V_260 = V_260 -> V_105 ;
if ( F_37 ( ! V_269 ) )
goto V_165;
if ( F_37 ( F_144 ( V_269 , V_11 ) ) ) {
F_80 ( V_269 ) ;
goto V_165;
}
V_270 = F_116 ( V_269 ) ;
if ( F_221 ( V_269 , V_263 + V_153 ) ) {
F_80 ( V_269 ) ;
goto V_165;
}
V_269 -> V_32 += F_116 ( V_269 ) - V_270 ;
F_66 ( V_269 ) ;
F_220 ( V_269 , V_263 ) ;
} else {
V_269 = F_19 ( V_270 + V_263 + V_153 ,
V_55 , F_114 ( V_7 ) ,
V_78 ) ;
if ( F_37 ( ! V_269 ) )
goto V_165;
F_47 ( V_269 , V_153 ) ;
F_222 ( V_269 , V_263 ) ;
}
if ( V_104 )
V_14 -> V_105 = V_269 ;
else
V_104 = V_269 ;
V_14 = V_269 ;
F_87 ( V_269 , V_7 ) ;
V_269 -> V_138 = V_7 -> V_138 ;
F_111 ( V_269 , F_96 ( V_269 ) - V_153 ) ;
F_149 ( V_7 , - V_264 ,
V_269 -> V_13 - V_264 ,
V_263 + V_264 ) ;
if ( V_269 -> V_11 == V_11 + V_263 )
goto V_271;
if ( ! V_266 ) {
V_269 -> V_123 = V_272 ;
V_269 -> V_120 = F_170 ( V_7 , V_71 ,
F_117 ( V_269 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_61 = F_28 ( V_269 ) -> V_82 ;
F_149 ( V_7 , V_71 ,
F_117 ( V_269 , V_270 ) , V_270 ) ;
F_28 ( V_269 ) -> V_90 = F_28 ( V_7 ) -> V_90 & V_222 ;
while ( V_207 < V_71 + V_11 ) {
if ( V_79 >= V_169 ) {
F_124 ( F_120 ( V_260 ) ) ;
V_79 = 0 ;
V_169 = F_28 ( V_260 ) -> V_89 ;
V_261 = F_28 ( V_260 ) -> V_82 ;
F_124 ( ! V_169 ) ;
V_260 = V_260 -> V_105 ;
}
if ( F_37 ( F_28 ( V_269 ) -> V_89 >=
V_193 ) ) {
F_223 (
L_3 ,
V_207 , V_262 ) ;
goto V_165;
}
* V_61 = * V_261 ;
F_199 ( V_61 ) ;
V_19 = F_104 ( V_61 ) ;
if ( V_207 < V_71 ) {
V_61 -> V_146 += V_71 - V_207 ;
F_148 ( V_61 , V_71 - V_207 ) ;
}
F_28 ( V_269 ) -> V_89 ++ ;
if ( V_207 + V_19 <= V_71 + V_11 ) {
V_79 ++ ;
V_261 ++ ;
V_207 += V_19 ;
} else {
F_148 ( V_61 , V_207 + V_19 - ( V_71 + V_11 ) ) ;
goto V_273;
}
V_61 ++ ;
}
V_273:
V_269 -> V_81 = V_11 - V_270 ;
V_269 -> V_11 += V_269 -> V_81 ;
V_269 -> V_32 += V_269 -> V_81 ;
V_271:
if ( ! V_120 ) {
V_269 -> V_120 = F_169 ( V_269 , V_263 ,
V_269 -> V_11 - V_263 , 0 ) ;
V_269 -> V_123 = V_272 ;
}
} while ( ( V_71 += V_11 ) < V_7 -> V_11 );
return V_104 ;
V_165:
while ( ( V_7 = V_104 ) ) {
V_104 = V_7 -> V_105 ;
F_80 ( V_7 ) ;
}
return F_218 ( V_165 ) ;
}
int F_224 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_37 * V_274 , * V_275 = F_28 ( V_7 ) ;
unsigned int V_71 = F_225 ( V_7 ) ;
unsigned int V_276 = F_120 ( V_7 ) ;
struct V_6 * V_269 , * V_277 , * V_278 = * V_12 ;
unsigned int V_11 = F_226 ( V_7 ) ;
unsigned int V_279 ;
unsigned int V_153 ;
if ( F_37 ( V_278 -> V_11 + V_11 >= 65536 ) )
return - V_280 ;
V_277 = F_227 ( V_278 ) -> V_281 ? : V_278 ;
V_274 = F_28 ( V_277 ) ;
if ( V_276 <= V_71 ) {
T_5 * V_61 ;
T_5 * V_282 ;
int V_79 = V_275 -> V_89 ;
int V_89 = V_274 -> V_89 + V_79 ;
if ( V_89 > V_193 )
goto V_225;
V_71 -= V_276 ;
V_274 -> V_89 = V_89 ;
V_275 -> V_89 = 0 ;
V_61 = V_274 -> V_82 + V_89 ;
V_282 = V_275 -> V_82 + V_79 ;
do {
* -- V_61 = * -- V_282 ;
} while ( -- V_79 );
V_61 -> V_146 += V_71 ;
F_148 ( V_61 , V_71 ) ;
V_279 = V_7 -> V_32 -
F_26 ( F_116 ( V_7 ) ) ;
V_7 -> V_32 -= V_7 -> V_81 ;
V_7 -> V_11 -= V_7 -> V_81 ;
V_7 -> V_81 = 0 ;
F_227 ( V_7 ) -> free = V_283 ;
goto V_171;
} else if ( V_7 -> V_56 ) {
int V_89 = V_274 -> V_89 ;
T_5 * V_61 = V_274 -> V_82 + V_89 ;
struct V_5 * V_5 = F_46 ( V_7 -> V_12 ) ;
unsigned int V_284 = V_276 - V_71 ;
unsigned int V_285 ;
if ( V_89 + 1 + V_275 -> V_89 > V_193 )
goto V_225;
V_285 = V_7 -> V_13 -
( unsigned char * ) F_42 ( V_5 ) +
V_71 ;
V_274 -> V_89 = V_89 + 1 + V_275 -> V_89 ;
V_61 -> V_5 . V_278 = V_5 ;
V_61 -> V_146 = V_285 ;
F_143 ( V_61 , V_284 ) ;
memcpy ( V_61 + 1 , V_275 -> V_82 , sizeof( * V_61 ) * V_275 -> V_89 ) ;
V_279 = V_7 -> V_32 - F_22 ( sizeof( struct V_6 ) ) ;
F_227 ( V_7 ) -> free = V_286 ;
goto V_171;
}
if ( V_274 -> V_84 )
goto V_225;
if ( F_226 ( V_278 ) != V_274 -> V_149 )
return - V_280 ;
V_153 = F_96 ( V_278 ) ;
V_269 = F_228 ( V_153 + F_225 ( V_278 ) , V_55 ) ;
if ( F_37 ( ! V_269 ) )
return - V_145 ;
F_87 ( V_269 , V_278 ) ;
V_269 -> V_138 = V_278 -> V_138 ;
F_47 ( V_269 , V_153 ) ;
F_222 ( V_269 , F_225 ( V_278 ) ) ;
F_229 ( V_269 , F_215 ( V_278 ) - V_278 -> V_13 ) ;
F_230 ( V_269 , F_231 ( V_278 ) ) ;
F_232 ( V_269 , F_233 ( V_278 ) ) ;
F_234 ( V_278 , F_225 ( V_278 ) ) ;
memcpy ( F_215 ( V_269 ) , F_215 ( V_278 ) ,
V_278 -> V_13 - F_215 ( V_278 ) ) ;
F_28 ( V_269 ) -> V_84 = V_278 ;
F_28 ( V_269 ) -> V_149 = V_274 -> V_149 ;
V_274 -> V_149 = 0 ;
F_235 ( V_278 ) ;
F_227 ( V_269 ) -> V_281 = V_278 ;
V_269 -> V_81 += V_278 -> V_11 ;
V_269 -> V_32 += V_278 -> V_32 ;
V_269 -> V_11 += V_278 -> V_11 ;
* V_12 = V_269 ;
V_269 -> V_105 = V_278 -> V_105 ;
V_278 -> V_105 = NULL ;
V_278 = V_269 ;
V_225:
V_279 = V_7 -> V_32 ;
if ( V_71 > V_276 ) {
unsigned int V_174 = V_71 - V_276 ;
V_275 -> V_82 [ 0 ] . V_146 += V_174 ;
F_148 ( & V_275 -> V_82 [ 0 ] , V_174 ) ;
V_7 -> V_81 -= V_174 ;
V_7 -> V_11 -= V_174 ;
V_71 = V_276 ;
}
F_234 ( V_7 , V_71 ) ;
if ( ! F_227 ( V_278 ) -> V_281 )
F_28 ( V_278 ) -> V_84 = V_7 ;
else
F_227 ( V_278 ) -> V_281 -> V_105 = V_7 ;
F_227 ( V_278 ) -> V_281 = V_7 ;
F_235 ( V_7 ) ;
V_277 = V_278 ;
V_171:
F_227 ( V_278 ) -> V_287 ++ ;
V_278 -> V_81 += V_11 ;
V_278 -> V_32 += V_279 ;
V_278 -> V_11 += V_11 ;
if ( V_277 != V_278 ) {
V_277 -> V_81 += V_11 ;
V_277 -> V_32 += V_279 ;
V_277 -> V_11 += V_11 ;
}
F_227 ( V_7 ) -> V_288 = 1 ;
return 0 ;
}
void T_11 F_236 ( void )
{
V_30 = F_237 ( L_4 ,
sizeof( struct V_6 ) ,
0 ,
V_289 | V_290 ,
NULL ) ;
V_40 = F_237 ( L_5 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_4 ) ,
0 ,
V_289 | V_290 ,
NULL ) ;
}
static int
F_238 ( struct V_6 * V_7 , struct V_291 * V_266 , int V_71 , int V_11 )
{
int V_179 = F_120 ( V_7 ) ;
int V_79 , V_181 = V_179 - V_71 ;
struct V_6 * V_180 ;
int V_292 = 0 ;
if ( V_181 > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
F_239 ( V_266 , V_7 -> V_13 + V_71 , V_181 ) ;
V_292 ++ ;
if ( ( V_11 -= V_181 ) == 0 )
return V_292 ;
V_71 += V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_89 ; V_79 ++ ) {
int V_15 ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_104 ( & F_28 ( V_7 ) -> V_82 [ V_79 ] ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_5 * V_61 = & F_28 ( V_7 ) -> V_82 [ V_79 ] ;
if ( V_181 > V_11 )
V_181 = V_11 ;
F_240 ( & V_266 [ V_292 ] , F_103 ( V_61 ) , V_181 ,
V_61 -> V_146 + V_71 - V_179 ) ;
V_292 ++ ;
if ( ! ( V_11 -= V_181 ) )
return V_292 ;
V_71 += V_181 ;
}
V_179 = V_15 ;
}
F_56 (skb, frag_iter) {
int V_15 ;
F_70 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
V_292 += F_238 ( V_180 , V_266 + V_292 , V_71 - V_179 ,
V_181 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_292 ;
V_71 += V_181 ;
}
V_179 = V_15 ;
}
F_124 ( V_11 ) ;
return V_292 ;
}
int F_241 ( struct V_6 * V_7 , struct V_291 * V_266 , int V_71 , int V_11 )
{
int V_293 = F_238 ( V_7 , V_266 , V_71 , V_11 ) ;
F_242 ( & V_266 [ V_293 - 1 ] ) ;
return V_293 ;
}
int F_243 ( struct V_6 * V_7 , int V_294 , struct V_6 * * V_295 )
{
int V_296 ;
int V_292 ;
struct V_6 * V_221 , * * V_297 ;
if ( ( F_127 ( V_7 ) || F_28 ( V_7 ) -> V_89 ) &&
F_146 ( V_7 , F_244 ( V_7 ) - F_120 ( V_7 ) ) == NULL )
return - V_145 ;
if ( ! F_63 ( V_7 ) ) {
if ( F_133 ( V_7 ) < V_294 &&
F_123 ( V_7 , 0 , V_294 - F_133 ( V_7 ) + 128 , V_55 ) )
return - V_145 ;
* V_295 = V_7 ;
return 1 ;
}
V_292 = 1 ;
V_297 = & F_28 ( V_7 ) -> V_84 ;
V_296 = 0 ;
while ( ( V_221 = * V_297 ) != NULL ) {
int V_155 = 0 ;
if ( F_125 ( V_221 ) )
V_296 = 1 ;
if ( V_221 -> V_105 == NULL && V_294 ) {
if ( F_28 ( V_221 ) -> V_89 ||
F_63 ( V_221 ) ||
F_133 ( V_221 ) < V_294 )
V_155 = V_294 + 128 ;
}
if ( V_296 ||
F_127 ( V_221 ) ||
V_155 ||
F_28 ( V_221 ) -> V_89 ||
F_63 ( V_221 ) ) {
struct V_6 * V_157 ;
if ( V_155 == 0 )
V_157 = F_115 ( V_221 , V_55 ) ;
else
V_157 = F_131 ( V_221 ,
F_96 ( V_221 ) ,
V_155 ,
V_55 ) ;
if ( F_37 ( V_157 == NULL ) )
return - V_145 ;
if ( V_221 -> V_137 )
F_245 ( V_157 , V_221 -> V_137 ) ;
V_157 -> V_105 = V_221 -> V_105 ;
* V_297 = V_157 ;
F_80 ( V_221 ) ;
V_221 = V_157 ;
}
V_292 ++ ;
* V_295 = V_221 ;
V_297 = & V_221 -> V_105 ;
}
return V_292 ;
}
static void F_246 ( struct V_6 * V_7 )
{
struct V_187 * V_137 = V_7 -> V_137 ;
F_247 ( V_7 -> V_32 , & V_137 -> V_298 ) ;
}
int F_248 ( struct V_187 * V_137 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_40 ( & V_137 -> V_298 ) + V_7 -> V_32 >=
( unsigned int ) V_137 -> V_299 )
return - V_145 ;
F_249 ( V_7 ) ;
V_7 -> V_137 = V_137 ;
V_7 -> V_98 = F_246 ;
F_211 ( V_7 -> V_32 , & V_137 -> V_298 ) ;
F_250 ( V_7 ) ;
F_185 ( & V_137 -> V_300 , V_7 ) ;
if ( ! F_251 ( V_137 , V_301 ) )
V_137 -> V_302 ( V_137 , V_11 ) ;
return 0 ;
}
void F_252 ( struct V_6 * V_303 ,
struct V_304 * V_305 )
{
struct V_187 * V_137 = V_303 -> V_137 ;
struct V_306 * V_307 ;
struct V_6 * V_7 ;
int V_165 ;
if ( ! V_137 )
return;
if ( V_305 ) {
* F_253 ( V_303 ) =
* V_305 ;
} else {
V_303 -> V_108 = F_254 () ;
}
V_7 = F_108 ( V_303 , V_55 ) ;
if ( ! V_7 )
return;
V_307 = F_255 ( V_7 ) ;
memset ( V_307 , 0 , sizeof( * V_307 ) ) ;
V_307 -> V_308 . V_309 = V_310 ;
V_307 -> V_308 . V_311 = V_312 ;
V_165 = F_248 ( V_137 , V_7 ) ;
if ( V_165 )
F_80 ( V_7 ) ;
}
void F_256 ( struct V_6 * V_7 , bool V_313 )
{
struct V_187 * V_137 = V_7 -> V_137 ;
struct V_306 * V_307 ;
int V_165 ;
V_7 -> V_314 = 1 ;
V_7 -> V_315 = V_313 ;
V_307 = F_255 ( V_7 ) ;
memset ( V_307 , 0 , sizeof( * V_307 ) ) ;
V_307 -> V_308 . V_309 = V_310 ;
V_307 -> V_308 . V_311 = V_316 ;
V_165 = F_248 ( V_137 , V_7 ) ;
if ( V_165 )
F_80 ( V_7 ) ;
}
bool F_257 ( struct V_6 * V_7 , T_12 V_179 , T_12 V_80 )
{
if ( F_37 ( V_179 > F_120 ( V_7 ) ) ||
F_37 ( ( int ) V_179 + V_80 > F_120 ( V_7 ) - 2 ) ) {
F_223 ( L_6 ,
V_179 , V_80 , F_120 ( V_7 ) ) ;
return false ;
}
V_7 -> V_123 = V_147 ;
V_7 -> V_148 = F_96 ( V_7 ) + V_179 ;
V_7 -> V_215 = V_80 ;
F_232 ( V_7 , V_179 ) ;
return true ;
}
void F_258 ( const struct V_6 * V_7 )
{
F_223 ( L_7 ,
V_7 -> V_16 -> V_17 ) ;
}
void F_259 ( struct V_6 * V_7 , bool V_317 )
{
if ( V_317 ) {
F_66 ( V_7 ) ;
F_31 ( V_30 , V_7 ) ;
} else {
F_79 ( V_7 ) ;
}
}
bool F_260 ( struct V_6 * V_178 , struct V_6 * V_205 ,
bool * V_318 , int * V_279 )
{
int V_79 , V_158 , V_11 = V_205 -> V_11 ;
* V_318 = false ;
if ( F_127 ( V_178 ) )
return false ;
if ( V_11 <= F_133 ( V_178 ) ) {
F_124 ( F_118 ( V_205 , 0 , F_117 ( V_178 , V_11 ) , V_11 ) ) ;
* V_279 = 0 ;
return true ;
}
if ( F_63 ( V_178 ) || F_63 ( V_205 ) )
return false ;
if ( F_120 ( V_205 ) != 0 ) {
struct V_5 * V_5 ;
unsigned int V_71 ;
if ( F_28 ( V_178 ) -> V_89 +
F_28 ( V_205 ) -> V_89 >= V_193 )
return false ;
if ( F_161 ( V_205 ) )
return false ;
V_158 = V_205 -> V_32 - F_22 ( sizeof( struct V_6 ) ) ;
V_5 = F_46 ( V_205 -> V_12 ) ;
V_71 = V_205 -> V_13 - ( unsigned char * ) F_42 ( V_5 ) ;
F_49 ( V_178 , F_28 ( V_178 ) -> V_89 ,
V_5 , V_71 , F_120 ( V_205 ) ) ;
* V_318 = true ;
} else {
if ( F_28 ( V_178 ) -> V_89 +
F_28 ( V_205 ) -> V_89 > V_193 )
return false ;
V_158 = V_205 -> V_32 - F_26 ( F_116 ( V_205 ) ) ;
}
F_261 ( V_158 < V_11 ) ;
memcpy ( F_28 ( V_178 ) -> V_82 + F_28 ( V_178 ) -> V_89 ,
F_28 ( V_205 ) -> V_82 ,
F_28 ( V_205 ) -> V_89 * sizeof( T_5 ) ) ;
F_28 ( V_178 ) -> V_89 += F_28 ( V_205 ) -> V_89 ;
if ( ! F_127 ( V_205 ) )
F_28 ( V_205 ) -> V_89 = 0 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_205 ) -> V_89 ; V_79 ++ )
F_122 ( V_205 , V_79 ) ;
V_178 -> V_32 += V_158 ;
V_178 -> V_11 += V_11 ;
V_178 -> V_81 += V_11 ;
* V_279 = V_158 ;
return true ;
}
void F_262 ( struct V_6 * V_7 , bool V_319 )
{
if ( V_319 )
F_249 ( V_7 ) ;
V_7 -> V_108 . V_320 = 0 ;
V_7 -> V_122 = V_321 ;
V_7 -> V_129 = 0 ;
V_7 -> V_121 = 0 ;
F_67 ( V_7 ) ;
V_7 -> V_128 = 0 ;
F_263 ( V_7 ) ;
F_264 ( V_7 ) ;
F_265 ( V_7 ) ;
}
