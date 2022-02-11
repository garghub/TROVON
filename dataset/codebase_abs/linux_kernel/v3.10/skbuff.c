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
#ifdef F_18
V_7 -> V_34 = ~ 0U ;
#endif
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
#ifdef F_18
V_7 -> V_34 = ~ 0U ;
V_7 -> V_44 = ~ 0U ;
#endif
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
#ifdef F_18
V_7 -> V_34 = ~ 0U ;
V_7 -> V_44 = ~ 0U ;
#endif
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
static void F_50 ( struct V_6 * * V_82 )
{
F_51 ( * V_82 ) ;
* V_82 = NULL ;
}
static inline void F_52 ( struct V_6 * V_7 )
{
F_50 ( & F_28 ( V_7 ) -> V_83 ) ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_6 * V_84 ;
F_54 (skb, list)
F_55 ( V_84 ) ;
}
static void F_56 ( struct V_6 * V_7 )
{
if ( V_7 -> V_56 )
F_2 ( F_46 ( V_7 -> V_12 ) ) ;
else
F_57 ( V_7 -> V_12 ) ;
}
static void F_58 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_85 ||
! F_59 ( V_7 -> V_86 ? ( 1 << V_87 ) + 1 : 1 ,
& F_28 ( V_7 ) -> V_45 ) ) {
if ( F_28 ( V_7 ) -> V_88 ) {
int V_79 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ )
F_60 ( V_7 , V_79 ) ;
}
if ( F_28 ( V_7 ) -> V_89 & V_90 ) {
struct V_91 * V_92 ;
V_92 = F_28 ( V_7 ) -> V_46 ;
if ( V_92 -> V_93 )
V_92 -> V_93 ( V_92 , true ) ;
}
if ( F_61 ( V_7 ) )
F_52 ( V_7 ) ;
F_56 ( V_7 ) ;
}
}
static void F_62 ( struct V_6 * V_7 )
{
struct V_6 * V_94 ;
T_4 * V_48 ;
switch ( V_7 -> V_51 ) {
case V_53 :
F_31 ( V_30 , V_7 ) ;
break;
case V_52 :
V_48 = ( T_4 * ) ( V_7 + 2 ) ;
if ( F_63 ( V_48 ) )
F_31 ( V_40 , V_7 ) ;
break;
case V_95 :
V_48 = ( T_4 * ) ( V_7 + 1 ) ;
V_94 = V_7 - 1 ;
V_7 -> V_51 = V_53 ;
if ( F_63 ( V_48 ) )
F_31 ( V_40 , V_94 ) ;
break;
}
}
static void F_64 ( struct V_6 * V_7 )
{
F_65 ( V_7 ) ;
#ifdef F_66
F_67 ( V_7 -> V_96 ) ;
#endif
if ( V_7 -> V_97 ) {
F_68 ( F_69 () ) ;
V_7 -> V_97 ( V_7 ) ;
}
#if F_70 ( V_98 )
F_71 ( V_7 -> V_99 ) ;
#endif
#ifdef F_72
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
F_64 ( V_7 ) ;
if ( F_39 ( V_7 -> V_12 ) )
F_58 ( V_7 ) ;
}
void F_79 ( struct V_6 * V_7 )
{
F_78 ( V_7 ) ;
F_62 ( V_7 ) ;
}
void F_80 ( struct V_6 * V_7 )
{
if ( F_37 ( ! V_7 ) )
return;
if ( F_39 ( F_40 ( & V_7 -> V_33 ) == 1 ) )
F_81 () ;
else if ( F_39 ( ! F_63 ( & V_7 -> V_33 ) ) )
return;
F_82 ( V_7 , F_83 ( 0 ) ) ;
F_79 ( V_7 ) ;
}
void F_51 ( struct V_6 * V_104 )
{
while ( V_104 ) {
struct V_6 * V_105 = V_104 -> V_105 ;
F_80 ( V_104 ) ;
V_104 = V_105 ;
}
}
void F_84 ( struct V_6 * V_7 )
{
if ( F_28 ( V_7 ) -> V_89 & V_90 ) {
struct V_91 * V_92 ;
V_92 = F_28 ( V_7 ) -> V_46 ;
if ( V_92 -> V_93 )
V_92 -> V_93 ( V_92 , false ) ;
F_28 ( V_7 ) -> V_89 &= ~ V_90 ;
}
}
void F_85 ( struct V_6 * V_7 )
{
if ( F_37 ( ! V_7 ) )
return;
if ( F_39 ( F_40 ( & V_7 -> V_33 ) == 1 ) )
F_81 () ;
else if ( F_39 ( ! F_63 ( & V_7 -> V_33 ) ) )
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
F_88 ( V_106 , V_107 ) ;
V_106 -> V_113 = V_107 -> V_113 ;
V_106 -> V_114 = V_107 -> V_114 ;
V_106 -> V_115 = V_107 -> V_115 ;
V_106 -> V_116 = V_107 -> V_116 ;
V_106 -> V_117 = V_107 -> V_117 ;
#ifdef F_66
V_106 -> V_96 = F_89 ( V_107 -> V_96 ) ;
#endif
memcpy ( V_106 -> V_118 , V_107 -> V_118 , sizeof( V_107 -> V_118 ) ) ;
V_106 -> V_119 = V_107 -> V_119 ;
V_106 -> V_120 = V_107 -> V_120 ;
V_106 -> V_121 = V_107 -> V_121 ;
V_106 -> V_122 = V_107 -> V_122 ;
F_90 ( V_106 , V_107 ) ;
V_106 -> V_123 = V_107 -> V_123 ;
#if F_70 ( V_124 )
V_106 -> V_125 = V_107 -> V_125 ;
#endif
V_106 -> V_23 = V_107 -> V_23 ;
V_106 -> V_126 = V_107 -> V_126 ;
V_106 -> V_127 = V_107 -> V_127 ;
V_106 -> V_128 = V_107 -> V_128 ;
F_91 ( V_106 , V_107 ) ;
#if F_70 ( V_129 )
V_106 -> V_130 = V_107 -> V_130 ;
#endif
#ifdef F_76
V_106 -> V_102 = V_107 -> V_102 ;
#ifdef F_77
V_106 -> V_103 = V_107 -> V_103 ;
#endif
#endif
V_106 -> V_131 = V_107 -> V_131 ;
V_106 -> V_132 = V_107 -> V_132 ;
F_92 ( V_106 , V_107 ) ;
}
static struct V_6 * F_93 ( struct V_6 * V_133 , struct V_6 * V_7 )
{
#define F_94 ( T_5 ) n->x = skb->x
V_133 -> V_105 = V_133 -> V_134 = NULL ;
V_133 -> V_135 = NULL ;
F_87 ( V_133 , V_7 ) ;
F_94 ( V_11 ) ;
F_94 ( V_81 ) ;
F_94 ( V_136 ) ;
V_133 -> V_137 = V_7 -> V_86 ? F_95 ( V_7 ) : V_7 -> V_137 ;
V_133 -> V_85 = 1 ;
V_133 -> V_86 = 0 ;
V_133 -> V_97 = NULL ;
F_94 ( V_14 ) ;
F_94 ( V_15 ) ;
F_94 ( V_12 ) ;
F_94 ( V_56 ) ;
F_94 ( V_13 ) ;
F_94 ( V_32 ) ;
F_17 ( & V_133 -> V_33 , 1 ) ;
F_96 ( & ( F_28 ( V_7 ) -> V_45 ) ) ;
V_7 -> V_85 = 1 ;
return V_133 ;
#undef F_94
}
struct V_6 * F_97 ( struct V_6 * V_138 , struct V_6 * V_139 )
{
F_78 ( V_138 ) ;
return F_93 ( V_138 , V_139 ) ;
}
int F_98 ( struct V_6 * V_7 , T_2 V_29 )
{
int V_79 ;
int V_140 = F_28 ( V_7 ) -> V_88 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_91 * V_92 = F_28 ( V_7 ) -> V_46 ;
for ( V_79 = 0 ; V_79 < V_140 ; V_79 ++ ) {
T_3 * V_141 ;
T_6 * V_142 = & F_28 ( V_7 ) -> V_143 [ V_79 ] ;
V_5 = F_99 ( V_29 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_105 = (struct V_5 * ) V_12 -> V_144 ;
F_2 ( V_12 ) ;
V_12 = V_105 ;
}
return - V_145 ;
}
V_141 = F_100 ( F_101 ( V_142 ) ) ;
memcpy ( F_42 ( V_5 ) ,
V_141 + V_142 -> V_146 , F_102 ( V_142 ) ) ;
F_103 ( V_141 ) ;
V_5 -> V_144 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_79 = 0 ; V_79 < V_140 ; V_79 ++ )
F_60 ( V_7 , V_79 ) ;
V_92 -> V_93 ( V_92 , false ) ;
for ( V_79 = V_140 - 1 ; V_79 >= 0 ; V_79 -- ) {
F_104 ( V_7 , V_79 , V_12 , 0 ,
F_28 ( V_7 ) -> V_143 [ V_79 ] . V_19 ) ;
V_12 = (struct V_5 * ) V_12 -> V_144 ;
}
F_28 ( V_7 ) -> V_89 &= ~ V_90 ;
return 0 ;
}
struct V_6 * F_105 ( struct V_6 * V_7 , T_2 V_29 )
{
struct V_6 * V_133 ;
if ( F_106 ( V_7 , V_29 ) )
return NULL ;
V_133 = V_7 + 1 ;
if ( V_7 -> V_51 == V_52 &&
V_133 -> V_51 == V_53 ) {
T_4 * V_48 = ( T_4 * ) ( V_133 + 1 ) ;
V_133 -> V_51 = V_95 ;
F_96 ( V_48 ) ;
} else {
if ( F_107 ( V_7 ) )
V_29 |= V_42 ;
V_133 = F_33 ( V_30 , V_29 ) ;
if ( ! V_133 )
return NULL ;
F_30 ( V_133 , V_49 ) ;
F_30 ( V_133 , V_50 ) ;
V_133 -> V_51 = V_53 ;
}
return F_93 ( V_133 , V_7 ) ;
}
static void F_108 ( struct V_6 * V_7 , int V_80 )
{
V_7 -> V_44 += V_80 ;
V_7 -> V_109 += V_80 ;
if ( F_109 ( V_7 ) )
V_7 -> V_34 += V_80 ;
V_7 -> V_110 += V_80 ;
V_7 -> V_111 += V_80 ;
V_7 -> V_112 += V_80 ;
}
static void F_110 ( struct V_6 * V_106 , const struct V_6 * V_107 )
{
#ifndef F_18
unsigned long V_71 = V_106 -> V_13 - V_107 -> V_13 ;
#endif
F_87 ( V_106 , V_107 ) ;
#ifndef F_18
F_108 ( V_106 , V_71 ) ;
#endif
F_28 ( V_106 ) -> V_147 = F_28 ( V_107 ) -> V_147 ;
F_28 ( V_106 ) -> V_148 = F_28 ( V_107 ) -> V_148 ;
F_28 ( V_106 ) -> V_149 = F_28 ( V_107 ) -> V_149 ;
}
static inline int F_111 ( const struct V_6 * V_7 )
{
if ( F_107 ( V_7 ) )
return V_41 ;
return 0 ;
}
struct V_6 * F_112 ( const struct V_6 * V_7 , T_2 V_29 )
{
int V_150 = F_95 ( V_7 ) ;
unsigned int V_19 = F_113 ( V_7 ) + V_7 -> V_81 ;
struct V_6 * V_133 = F_19 ( V_19 , V_29 ,
F_111 ( V_7 ) , V_78 ) ;
if ( ! V_133 )
return NULL ;
F_47 ( V_133 , V_150 ) ;
F_114 ( V_133 , V_7 -> V_11 ) ;
if ( F_115 ( V_7 , - V_150 , V_133 -> V_12 , V_150 + V_7 -> V_11 ) )
F_8 () ;
F_110 ( V_133 , V_7 ) ;
return V_133 ;
}
struct V_6 * F_116 ( struct V_6 * V_7 , int V_151 , T_2 V_29 )
{
unsigned int V_19 = F_117 ( V_7 ) + V_151 ;
struct V_6 * V_133 = F_19 ( V_19 , V_29 ,
F_111 ( V_7 ) , V_78 ) ;
if ( ! V_133 )
goto V_28;
F_47 ( V_133 , V_151 ) ;
F_114 ( V_133 , F_117 ( V_7 ) ) ;
F_118 ( V_7 , V_133 -> V_13 , V_133 -> V_11 ) ;
V_133 -> V_32 += V_7 -> V_81 ;
V_133 -> V_81 = V_7 -> V_81 ;
V_133 -> V_11 = V_7 -> V_11 ;
if ( F_28 ( V_7 ) -> V_88 ) {
int V_79 ;
if ( F_106 ( V_7 , V_29 ) ) {
F_80 ( V_133 ) ;
V_133 = NULL ;
goto V_28;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
F_28 ( V_133 ) -> V_143 [ V_79 ] = F_28 ( V_7 ) -> V_143 [ V_79 ] ;
F_119 ( V_7 , V_79 ) ;
}
F_28 ( V_133 ) -> V_88 = V_79 ;
}
if ( F_61 ( V_7 ) ) {
F_28 ( V_133 ) -> V_83 = F_28 ( V_7 ) -> V_83 ;
F_53 ( V_133 ) ;
}
F_110 ( V_133 , V_7 ) ;
V_28:
return V_133 ;
}
int F_120 ( struct V_6 * V_7 , int V_152 , int V_153 ,
T_2 V_29 )
{
int V_79 ;
T_3 * V_13 ;
int V_19 = V_152 + F_113 ( V_7 ) + V_153 ;
long V_80 ;
F_121 ( V_152 < 0 ) ;
if ( F_122 ( V_7 ) )
F_8 () ;
V_19 = F_22 ( V_19 ) ;
if ( F_107 ( V_7 ) )
V_29 |= V_42 ;
V_13 = F_23 ( V_19 + F_22 ( sizeof( struct V_37 ) ) ,
V_29 , V_78 , NULL ) ;
if ( ! V_13 )
goto V_43;
V_19 = F_24 ( F_25 ( V_13 ) ) ;
memcpy ( V_13 + V_152 , V_7 -> V_12 , F_123 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_37 * ) ( V_13 + V_19 ) ,
F_28 ( V_7 ) ,
F_16 ( struct V_37 , V_143 [ F_28 ( V_7 ) -> V_88 ] ) ) ;
if ( F_124 ( V_7 ) ) {
if ( F_106 ( V_7 , V_29 ) )
goto V_154;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ )
F_119 ( V_7 , V_79 ) ;
if ( F_61 ( V_7 ) )
F_53 ( V_7 ) ;
F_58 ( V_7 ) ;
} else {
F_56 ( V_7 ) ;
}
V_80 = ( V_13 + V_152 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_56 = 0 ;
V_7 -> V_13 += V_80 ;
#ifdef F_18
V_7 -> V_15 = V_19 ;
V_80 = V_152 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_19 ;
#endif
V_7 -> V_14 += V_80 ;
F_108 ( V_7 , V_80 ) ;
if ( V_7 -> V_122 == V_155 )
V_7 -> V_156 += V_152 ;
V_7 -> V_85 = 0 ;
V_7 -> V_137 = 0 ;
V_7 -> V_86 = 0 ;
F_17 ( & F_28 ( V_7 ) -> V_45 , 1 ) ;
return 0 ;
V_154:
F_57 ( V_13 ) ;
V_43:
return - V_145 ;
}
struct V_6 * F_125 ( struct V_6 * V_7 , unsigned int V_151 )
{
struct V_6 * V_157 ;
int V_158 = V_151 - F_95 ( V_7 ) ;
if ( V_158 <= 0 )
V_157 = F_126 ( V_7 , V_55 ) ;
else {
V_157 = F_105 ( V_7 , V_55 ) ;
if ( V_157 && F_120 ( V_157 , F_22 ( V_158 ) , 0 ,
V_55 ) ) {
F_80 ( V_157 ) ;
V_157 = NULL ;
}
}
return V_157 ;
}
struct V_6 * F_127 ( const struct V_6 * V_7 ,
int V_159 , int V_160 ,
T_2 V_29 )
{
struct V_6 * V_133 = F_19 ( V_159 + V_7 -> V_11 + V_160 ,
V_29 , F_111 ( V_7 ) ,
V_78 ) ;
int V_161 = F_95 ( V_7 ) ;
int V_162 , V_163 ;
int V_80 ;
if ( ! V_133 )
return NULL ;
F_47 ( V_133 , V_159 ) ;
F_114 ( V_133 , V_7 -> V_11 ) ;
V_162 = V_161 ;
V_163 = 0 ;
if ( V_159 <= V_162 )
V_162 = V_159 ;
else
V_163 = V_159 - V_162 ;
if ( F_115 ( V_7 , - V_162 , V_133 -> V_12 + V_163 ,
V_7 -> V_11 + V_162 ) )
F_8 () ;
F_110 ( V_133 , V_7 ) ;
V_80 = V_159 - V_161 ;
if ( V_133 -> V_122 == V_155 )
V_133 -> V_156 += V_80 ;
#ifdef F_18
F_108 ( V_133 , V_80 ) ;
#endif
return V_133 ;
}
int F_128 ( struct V_6 * V_7 , int V_164 )
{
int V_165 ;
int V_153 ;
if ( ! F_124 ( V_7 ) && F_129 ( V_7 ) >= V_164 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_164 ) ;
return 0 ;
}
V_153 = V_7 -> V_81 + V_164 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_39 ( F_124 ( V_7 ) || V_153 > 0 ) ) {
V_165 = F_120 ( V_7 , 0 , V_153 , V_55 ) ;
if ( F_37 ( V_165 ) )
goto V_166;
}
V_165 = F_130 ( V_7 ) ;
if ( F_37 ( V_165 ) )
goto V_166;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_164 ) ;
return 0 ;
V_166:
F_80 ( V_7 ) ;
return V_165 ;
}
unsigned char * F_114 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_167 = F_123 ( V_7 ) ;
F_131 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_37 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_9 ( V_7 , V_11 , F_83 ( 0 ) ) ;
return V_167 ;
}
unsigned char * F_132 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_37 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_10 ( V_7 , V_11 , F_83 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_133 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_134 ( V_7 , V_11 ) ;
}
void F_135 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_136 ( V_7 , V_11 ) ;
}
int F_137 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_168 ;
struct V_6 * V_61 ;
int V_71 = F_117 ( V_7 ) ;
int V_169 = F_28 ( V_7 ) -> V_88 ;
int V_79 ;
int V_165 ;
if ( F_124 ( V_7 ) &&
F_37 ( ( V_165 = F_120 ( V_7 , 0 , 0 , V_55 ) ) ) )
return V_165 ;
V_79 = 0 ;
if ( V_71 >= V_11 )
goto V_170;
for (; V_79 < V_169 ; V_79 ++ ) {
int V_15 = V_71 + F_102 ( & F_28 ( V_7 ) -> V_143 [ V_79 ] ) ;
if ( V_15 < V_11 ) {
V_71 = V_15 ;
continue;
}
F_138 ( & F_28 ( V_7 ) -> V_143 [ V_79 ++ ] , V_11 - V_71 ) ;
V_170:
F_28 ( V_7 ) -> V_88 = V_79 ;
for (; V_79 < V_169 ; V_79 ++ )
F_60 ( V_7 , V_79 ) ;
if ( F_61 ( V_7 ) )
F_52 ( V_7 ) ;
goto V_171;
}
for ( V_168 = & F_28 ( V_7 ) -> V_83 ; ( V_61 = * V_168 ) ;
V_168 = & V_61 -> V_105 ) {
int V_15 = V_71 + V_61 -> V_11 ;
if ( F_122 ( V_61 ) ) {
struct V_6 * V_172 ;
V_172 = F_105 ( V_61 , V_55 ) ;
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
F_37 ( ( V_165 = F_139 ( V_61 , V_11 - V_71 ) ) ) )
return V_165 ;
if ( V_61 -> V_105 )
F_50 ( & V_61 -> V_105 ) ;
break;
}
V_171:
if ( V_11 > F_117 ( V_7 ) ) {
V_7 -> V_81 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_81 = 0 ;
F_140 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_141 ( struct V_6 * V_7 , int V_158 )
{
int V_79 , V_173 , V_174 = ( V_7 -> V_14 + V_158 ) - V_7 -> V_15 ;
if ( V_174 > 0 || F_124 ( V_7 ) ) {
if ( F_120 ( V_7 , 0 , V_174 > 0 ? V_174 + 128 : 0 ,
V_55 ) )
return NULL ;
}
if ( F_115 ( V_7 , F_117 ( V_7 ) , F_123 ( V_7 ) , V_158 ) )
F_8 () ;
if ( ! F_61 ( V_7 ) )
goto V_175;
V_174 = V_158 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_19 = F_102 ( & F_28 ( V_7 ) -> V_143 [ V_79 ] ) ;
if ( V_19 >= V_174 )
goto V_175;
V_174 -= V_19 ;
}
if ( V_174 ) {
struct V_6 * V_84 = F_28 ( V_7 ) -> V_83 ;
struct V_6 * V_176 = NULL ;
struct V_6 * V_177 = NULL ;
do {
F_121 ( ! V_84 ) ;
if ( V_84 -> V_11 <= V_174 ) {
V_174 -= V_84 -> V_11 ;
V_84 = V_84 -> V_105 ;
V_177 = V_84 ;
} else {
if ( F_122 ( V_84 ) ) {
V_176 = F_105 ( V_84 , V_55 ) ;
if ( ! V_176 )
return NULL ;
V_177 = V_84 -> V_105 ;
V_84 = V_176 ;
} else {
V_177 = V_84 ;
}
if ( ! F_142 ( V_84 , V_174 ) ) {
F_80 ( V_176 ) ;
return NULL ;
}
break;
}
} while ( V_174 );
while ( ( V_84 = F_28 ( V_7 ) -> V_83 ) != V_177 ) {
F_28 ( V_7 ) -> V_83 = V_84 -> V_105 ;
F_80 ( V_84 ) ;
}
if ( V_176 ) {
V_176 -> V_105 = V_84 ;
F_28 ( V_7 ) -> V_83 = V_176 ;
}
}
V_175:
V_174 = V_158 ;
V_173 = 0 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_19 = F_102 ( & F_28 ( V_7 ) -> V_143 [ V_79 ] ) ;
if ( V_19 <= V_174 ) {
F_60 ( V_7 , V_79 ) ;
V_174 -= V_19 ;
} else {
F_28 ( V_7 ) -> V_143 [ V_173 ] = F_28 ( V_7 ) -> V_143 [ V_79 ] ;
if ( V_174 ) {
F_28 ( V_7 ) -> V_143 [ V_173 ] . V_146 += V_174 ;
F_143 ( & F_28 ( V_7 ) -> V_143 [ V_173 ] , V_174 ) ;
V_174 = 0 ;
}
V_173 ++ ;
}
}
F_28 ( V_7 ) -> V_88 = V_173 ;
V_7 -> V_14 += V_158 ;
V_7 -> V_81 -= V_158 ;
return F_123 ( V_7 ) ;
}
int F_115 ( const struct V_6 * V_7 , int V_71 , void * V_178 , int V_11 )
{
int V_179 = F_117 ( V_7 ) ;
struct V_6 * V_180 ;
int V_79 , V_181 ;
if ( V_71 > ( int ) V_7 -> V_11 - V_11 )
goto V_182;
if ( ( V_181 = V_179 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
F_144 ( V_7 , V_71 , V_178 , V_181 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_178 += V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_15 ;
T_6 * V_142 = & F_28 ( V_7 ) -> V_143 [ V_79 ] ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_102 ( V_142 ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_3 * V_141 ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_141 = F_100 ( F_101 ( V_142 ) ) ;
memcpy ( V_178 ,
V_141 + V_142 -> V_146 + V_71 - V_179 ,
V_181 ) ;
F_103 ( V_141 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_178 += V_181 ;
}
V_179 = V_15 ;
}
F_54 (skb, frag_iter) {
int V_15 ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
if ( F_115 ( V_180 , V_71 - V_179 , V_178 , V_181 ) )
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
static void F_145 ( struct V_184 * V_185 , unsigned int V_79 )
{
F_2 ( V_185 -> V_186 [ V_79 ] ) ;
}
static struct V_5 * F_146 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_71 ,
struct V_187 * V_135 )
{
struct V_188 * V_189 = F_147 ( V_135 ) ;
if ( ! F_148 ( V_135 , V_189 ) )
return NULL ;
* V_11 = F_149 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_42 ( V_189 -> V_5 ) + V_189 -> V_71 ,
F_42 ( V_5 ) + * V_71 , * V_11 ) ;
* V_71 = V_189 -> V_71 ;
V_189 -> V_71 += * V_11 ;
return V_189 -> V_5 ;
}
static bool F_150 ( const struct V_184 * V_185 ,
struct V_5 * V_5 ,
unsigned int V_71 )
{
return V_185 -> V_190 &&
V_185 -> V_186 [ V_185 -> V_190 - 1 ] == V_5 &&
( V_185 -> V_191 [ V_185 -> V_190 - 1 ] . V_71 +
V_185 -> V_191 [ V_185 -> V_190 - 1 ] . V_11 == V_71 ) ;
}
static bool F_151 ( struct V_184 * V_185 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_71 ,
bool V_192 ,
struct V_187 * V_135 )
{
if ( F_37 ( V_185 -> V_190 == V_193 ) )
return true ;
if ( V_192 ) {
V_5 = F_146 ( V_5 , V_11 , & V_71 , V_135 ) ;
if ( ! V_5 )
return true ;
}
if ( F_150 ( V_185 , V_5 , V_71 ) ) {
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
static bool F_152 ( struct V_5 * V_5 , unsigned int V_194 ,
unsigned int V_195 , unsigned int * V_80 ,
unsigned int * V_11 ,
struct V_184 * V_185 , bool V_192 ,
struct V_187 * V_135 ,
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
unsigned int V_196 = F_153 ( * V_11 , V_195 ) ;
if ( F_151 ( V_185 , V_2 , V_5 , & V_196 , V_194 ,
V_192 , V_135 ) )
return true ;
V_194 += V_196 ;
V_195 -= V_196 ;
* V_11 -= V_196 ;
} while ( * V_11 && V_195 );
return false ;
}
static bool F_154 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_71 , unsigned int * V_11 ,
struct V_184 * V_185 , struct V_187 * V_135 )
{
int V_197 ;
if ( F_152 ( F_155 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_66 - 1 ) ,
F_117 ( V_7 ) ,
V_71 , V_11 , V_185 ,
F_156 ( V_7 ) ,
V_135 , V_2 ) )
return true ;
for ( V_197 = 0 ; V_197 < F_28 ( V_7 ) -> V_88 ; V_197 ++ ) {
const T_6 * V_142 = & F_28 ( V_7 ) -> V_143 [ V_197 ] ;
if ( F_152 ( F_101 ( V_142 ) ,
V_142 -> V_146 , F_102 ( V_142 ) ,
V_71 , V_11 , V_185 , false , V_135 , V_2 ) )
return true ;
}
return false ;
}
int F_157 ( struct V_6 * V_7 , unsigned int V_71 ,
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
. V_203 = F_145 ,
} ;
struct V_6 * V_180 ;
struct V_187 * V_135 = V_7 -> V_135 ;
int V_204 = 0 ;
if ( F_154 ( V_7 , V_2 , & V_71 , & V_198 , & V_185 , V_135 ) )
goto V_171;
else if ( ! V_198 )
goto V_171;
F_54 (skb, frag_iter) {
if ( ! V_198 )
break;
if ( F_154 ( V_180 , V_2 , & V_71 , & V_198 , & V_185 , V_135 ) )
break;
}
V_171:
if ( V_185 . V_190 ) {
F_158 ( V_135 ) ;
V_204 = F_159 ( V_2 , & V_185 ) ;
F_160 ( V_135 ) ;
}
return V_204 ;
}
int F_161 ( struct V_6 * V_7 , int V_71 , const void * V_205 , int V_11 )
{
int V_179 = F_117 ( V_7 ) ;
struct V_6 * V_180 ;
int V_79 , V_181 ;
if ( V_71 > ( int ) V_7 -> V_11 - V_11 )
goto V_182;
if ( ( V_181 = V_179 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
F_162 ( V_7 , V_71 , V_205 , V_181 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_205 += V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
T_6 * V_61 = & F_28 ( V_7 ) -> V_143 [ V_79 ] ;
int V_15 ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_102 ( V_61 ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_3 * V_141 ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_141 = F_100 ( F_101 ( V_61 ) ) ;
memcpy ( V_141 + V_61 -> V_146 + V_71 - V_179 ,
V_205 , V_181 ) ;
F_103 ( V_141 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return 0 ;
V_71 += V_181 ;
V_205 += V_181 ;
}
V_179 = V_15 ;
}
F_54 (skb, frag_iter) {
int V_15 ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
if ( F_161 ( V_180 , V_71 - V_179 ,
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
T_7 F_163 ( const struct V_6 * V_7 , int V_71 ,
int V_11 , T_7 V_119 )
{
int V_179 = F_117 ( V_7 ) ;
int V_79 , V_181 = V_179 - V_71 ;
struct V_6 * V_180 ;
int V_206 = 0 ;
if ( V_181 > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
V_119 = F_164 ( V_7 -> V_13 + V_71 , V_181 , V_119 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_119 ;
V_71 += V_181 ;
V_206 = V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_15 ;
T_6 * V_61 = & F_28 ( V_7 ) -> V_143 [ V_79 ] ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_102 ( V_61 ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_7 V_207 ;
T_3 * V_141 ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_141 = F_100 ( F_101 ( V_61 ) ) ;
V_207 = F_164 ( V_141 + V_61 -> V_146 +
V_71 - V_179 , V_181 , 0 ) ;
F_103 ( V_141 ) ;
V_119 = F_165 ( V_119 , V_207 , V_206 ) ;
if ( ! ( V_11 -= V_181 ) )
return V_119 ;
V_71 += V_181 ;
V_206 += V_181 ;
}
V_179 = V_15 ;
}
F_54 (skb, frag_iter) {
int V_15 ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_7 V_207 ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_207 = F_163 ( V_180 , V_71 - V_179 ,
V_181 , 0 ) ;
V_119 = F_165 ( V_119 , V_207 , V_206 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_119 ;
V_71 += V_181 ;
V_206 += V_181 ;
}
V_179 = V_15 ;
}
F_121 ( V_11 ) ;
return V_119 ;
}
T_7 F_166 ( const struct V_6 * V_7 , int V_71 ,
T_3 * V_178 , int V_11 , T_7 V_119 )
{
int V_179 = F_117 ( V_7 ) ;
int V_79 , V_181 = V_179 - V_71 ;
struct V_6 * V_180 ;
int V_206 = 0 ;
if ( V_181 > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
V_119 = F_167 ( V_7 -> V_13 + V_71 , V_178 ,
V_181 , V_119 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_119 ;
V_71 += V_181 ;
V_178 += V_181 ;
V_206 = V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_15 ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_102 ( & F_28 ( V_7 ) -> V_143 [ V_79 ] ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_7 V_207 ;
T_3 * V_141 ;
T_6 * V_61 = & F_28 ( V_7 ) -> V_143 [ V_79 ] ;
if ( V_181 > V_11 )
V_181 = V_11 ;
V_141 = F_100 ( F_101 ( V_61 ) ) ;
V_207 = F_167 ( V_141 +
V_61 -> V_146 +
V_71 - V_179 , V_178 ,
V_181 , 0 ) ;
F_103 ( V_141 ) ;
V_119 = F_165 ( V_119 , V_207 , V_206 ) ;
if ( ! ( V_11 -= V_181 ) )
return V_119 ;
V_71 += V_181 ;
V_178 += V_181 ;
V_206 += V_181 ;
}
V_179 = V_15 ;
}
F_54 (skb, frag_iter) {
T_7 V_207 ;
int V_15 ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
V_207 = F_166 ( V_180 ,
V_71 - V_179 ,
V_178 , V_181 , 0 ) ;
V_119 = F_165 ( V_119 , V_207 , V_206 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_119 ;
V_71 += V_181 ;
V_178 += V_181 ;
V_206 += V_181 ;
}
V_179 = V_15 ;
}
F_121 ( V_11 ) ;
return V_119 ;
}
void F_168 ( const struct V_6 * V_7 , T_3 * V_178 )
{
T_7 V_119 ;
long V_208 ;
if ( V_7 -> V_122 == V_155 )
V_208 = F_169 ( V_7 ) ;
else
V_208 = F_117 ( V_7 ) ;
F_121 ( V_208 > F_117 ( V_7 ) ) ;
F_118 ( V_7 , V_178 , V_208 ) ;
V_119 = 0 ;
if ( V_208 != V_7 -> V_11 )
V_119 = F_166 ( V_7 , V_208 , V_178 + V_208 ,
V_7 -> V_11 - V_208 , 0 ) ;
if ( V_7 -> V_122 == V_155 ) {
long V_209 = V_208 + V_7 -> V_210 ;
* ( ( V_211 * ) ( V_178 + V_209 ) ) = F_170 ( V_119 ) ;
}
}
struct V_6 * F_171 ( struct V_212 * V_84 )
{
unsigned long V_20 ;
struct V_6 * V_213 ;
F_172 ( & V_84 -> V_214 , V_20 ) ;
V_213 = F_173 ( V_84 ) ;
F_174 ( & V_84 -> V_214 , V_20 ) ;
return V_213 ;
}
struct V_6 * F_175 ( struct V_212 * V_84 )
{
unsigned long V_20 ;
struct V_6 * V_213 ;
F_172 ( & V_84 -> V_214 , V_20 ) ;
V_213 = F_176 ( V_84 ) ;
F_174 ( & V_84 -> V_214 , V_20 ) ;
return V_213 ;
}
void F_177 ( struct V_212 * V_84 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_171 ( V_84 ) ) != NULL )
F_80 ( V_7 ) ;
}
void F_178 ( struct V_212 * V_84 , struct V_6 * V_215 )
{
unsigned long V_20 ;
F_172 ( & V_84 -> V_214 , V_20 ) ;
F_179 ( V_84 , V_215 ) ;
F_174 ( & V_84 -> V_214 , V_20 ) ;
}
void F_180 ( struct V_212 * V_84 , struct V_6 * V_215 )
{
unsigned long V_20 ;
F_172 ( & V_84 -> V_214 , V_20 ) ;
F_181 ( V_84 , V_215 ) ;
F_174 ( & V_84 -> V_214 , V_20 ) ;
}
void F_182 ( struct V_6 * V_7 , struct V_212 * V_84 )
{
unsigned long V_20 ;
F_172 ( & V_84 -> V_214 , V_20 ) ;
F_183 ( V_7 , V_84 ) ;
F_174 ( & V_84 -> V_214 , V_20 ) ;
}
void F_184 ( struct V_6 * V_107 , struct V_6 * V_215 , struct V_212 * V_84 )
{
unsigned long V_20 ;
F_172 ( & V_84 -> V_214 , V_20 ) ;
F_185 ( V_84 , V_107 , V_215 ) ;
F_174 ( & V_84 -> V_214 , V_20 ) ;
}
void F_186 ( struct V_6 * V_107 , struct V_6 * V_215 , struct V_212 * V_84 )
{
unsigned long V_20 ;
F_172 ( & V_84 -> V_214 , V_20 ) ;
F_187 ( V_215 , V_107 -> V_134 , V_107 , V_84 ) ;
F_174 ( & V_84 -> V_214 , V_20 ) ;
}
static inline void F_188 ( struct V_6 * V_7 ,
struct V_6 * V_216 ,
const T_8 V_11 , const int V_206 )
{
int V_79 ;
F_144 ( V_7 , V_11 , F_114 ( V_216 , V_206 - V_11 ) ,
V_206 - V_11 ) ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ )
F_28 ( V_216 ) -> V_143 [ V_79 ] = F_28 ( V_7 ) -> V_143 [ V_79 ] ;
F_28 ( V_216 ) -> V_88 = F_28 ( V_7 ) -> V_88 ;
F_28 ( V_7 ) -> V_88 = 0 ;
V_216 -> V_81 = V_7 -> V_81 ;
V_216 -> V_11 += V_216 -> V_81 ;
V_7 -> V_81 = 0 ;
V_7 -> V_11 = V_11 ;
F_140 ( V_7 , V_11 ) ;
}
static inline void F_189 ( struct V_6 * V_7 ,
struct V_6 * V_216 ,
const T_8 V_11 , int V_206 )
{
int V_79 , V_173 = 0 ;
const int V_169 = F_28 ( V_7 ) -> V_88 ;
F_28 ( V_7 ) -> V_88 = 0 ;
V_216 -> V_11 = V_216 -> V_81 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_81 = V_11 - V_206 ;
for ( V_79 = 0 ; V_79 < V_169 ; V_79 ++ ) {
int V_19 = F_102 ( & F_28 ( V_7 ) -> V_143 [ V_79 ] ) ;
if ( V_206 + V_19 > V_11 ) {
F_28 ( V_216 ) -> V_143 [ V_173 ] = F_28 ( V_7 ) -> V_143 [ V_79 ] ;
if ( V_206 < V_11 ) {
F_119 ( V_7 , V_79 ) ;
F_28 ( V_216 ) -> V_143 [ 0 ] . V_146 += V_11 - V_206 ;
F_143 ( & F_28 ( V_216 ) -> V_143 [ 0 ] , V_11 - V_206 ) ;
F_138 ( & F_28 ( V_7 ) -> V_143 [ V_79 ] , V_11 - V_206 ) ;
F_28 ( V_7 ) -> V_88 ++ ;
}
V_173 ++ ;
} else
F_28 ( V_7 ) -> V_88 ++ ;
V_206 += V_19 ;
}
F_28 ( V_216 ) -> V_88 = V_173 ;
}
void F_190 ( struct V_6 * V_7 , struct V_6 * V_216 , const T_8 V_11 )
{
int V_206 = F_117 ( V_7 ) ;
F_28 ( V_216 ) -> V_89 = F_28 ( V_7 ) -> V_89 & V_217 ;
if ( V_11 < V_206 )
F_188 ( V_7 , V_216 , V_11 , V_206 ) ;
else
F_189 ( V_7 , V_216 , V_11 , V_206 ) ;
}
static int F_191 ( struct V_6 * V_7 )
{
return F_124 ( V_7 ) && F_120 ( V_7 , 0 , 0 , V_55 ) ;
}
int F_192 ( struct V_6 * V_218 , struct V_6 * V_7 , int V_219 )
{
int V_205 , V_178 , V_220 , V_221 ;
struct V_222 * V_223 , * V_224 ;
F_121 ( V_219 > V_7 -> V_11 ) ;
F_121 ( F_117 ( V_7 ) ) ;
V_221 = V_219 ;
V_205 = 0 ;
V_178 = F_28 ( V_218 ) -> V_88 ;
V_223 = & F_28 ( V_7 ) -> V_143 [ V_205 ] ;
if ( ! V_178 ||
! F_193 ( V_218 , V_178 , F_101 ( V_223 ) ,
V_223 -> V_146 ) ) {
V_220 = - 1 ;
} else {
V_220 = V_178 - 1 ;
V_221 -= F_102 ( V_223 ) ;
if ( V_221 < 0 ) {
if ( F_191 ( V_7 ) ||
F_191 ( V_218 ) )
return 0 ;
V_223 = & F_28 ( V_7 ) -> V_143 [ V_205 ] ;
V_224 = & F_28 ( V_218 ) -> V_143 [ V_220 ] ;
F_194 ( V_224 , V_219 ) ;
F_143 ( V_223 , V_219 ) ;
V_223 -> V_146 += V_219 ;
goto V_225;
}
V_205 ++ ;
}
if ( ( V_219 == V_7 -> V_11 ) &&
( F_28 ( V_7 ) -> V_88 - V_205 ) > ( V_193 - V_178 ) )
return 0 ;
if ( F_191 ( V_7 ) || F_191 ( V_218 ) )
return 0 ;
while ( ( V_221 > 0 ) && ( V_205 < F_28 ( V_7 ) -> V_88 ) ) {
if ( V_178 == V_193 )
return 0 ;
V_223 = & F_28 ( V_7 ) -> V_143 [ V_205 ] ;
V_224 = & F_28 ( V_218 ) -> V_143 [ V_178 ] ;
if ( V_221 >= F_102 ( V_223 ) ) {
* V_224 = * V_223 ;
V_221 -= F_102 ( V_223 ) ;
V_205 ++ ;
V_178 ++ ;
} else {
F_195 ( V_223 ) ;
V_224 -> V_5 = V_223 -> V_5 ;
V_224 -> V_146 = V_223 -> V_146 ;
F_138 ( V_224 , V_221 ) ;
V_223 -> V_146 += V_221 ;
F_143 ( V_223 , V_221 ) ;
V_221 = 0 ;
V_178 ++ ;
break;
}
}
F_28 ( V_218 ) -> V_88 = V_178 ;
if ( V_220 >= 0 ) {
V_223 = & F_28 ( V_7 ) -> V_143 [ 0 ] ;
V_224 = & F_28 ( V_218 ) -> V_143 [ V_220 ] ;
F_194 ( V_224 , F_102 ( V_223 ) ) ;
F_196 ( V_223 ) ;
}
V_178 = 0 ;
while ( V_205 < F_28 ( V_7 ) -> V_88 )
F_28 ( V_7 ) -> V_143 [ V_178 ++ ] = F_28 ( V_7 ) -> V_143 [ V_205 ++ ] ;
F_28 ( V_7 ) -> V_88 = V_178 ;
F_121 ( V_221 > 0 && ! F_28 ( V_7 ) -> V_88 ) ;
V_225:
V_218 -> V_122 = V_155 ;
V_7 -> V_122 = V_155 ;
V_7 -> V_11 -= V_219 ;
V_7 -> V_81 -= V_219 ;
V_7 -> V_32 -= V_219 ;
V_218 -> V_11 += V_219 ;
V_218 -> V_81 += V_219 ;
V_218 -> V_32 += V_219 ;
return V_219 ;
}
void F_197 ( struct V_6 * V_7 , unsigned int V_205 ,
unsigned int V_178 , struct V_226 * V_227 )
{
V_227 -> V_228 = V_205 ;
V_227 -> V_229 = V_178 ;
V_227 -> V_230 = V_227 -> V_231 = V_7 ;
V_227 -> V_232 = V_227 -> V_233 = 0 ;
V_227 -> V_234 = NULL ;
}
unsigned int F_198 ( unsigned int V_235 , const T_3 * * V_13 ,
struct V_226 * V_227 )
{
unsigned int V_236 , V_237 = V_235 + V_227 -> V_228 ;
T_6 * V_61 ;
if ( F_37 ( V_237 >= V_227 -> V_229 ) )
return 0 ;
V_238:
V_236 = F_117 ( V_227 -> V_231 ) + V_227 -> V_233 ;
if ( V_237 < V_236 && ! V_227 -> V_234 ) {
* V_13 = V_227 -> V_231 -> V_13 + ( V_237 - V_227 -> V_233 ) ;
return V_236 - V_237 ;
}
if ( V_227 -> V_232 == 0 && ! V_227 -> V_234 )
V_227 -> V_233 += F_117 ( V_227 -> V_231 ) ;
while ( V_227 -> V_232 < F_28 ( V_227 -> V_231 ) -> V_88 ) {
V_61 = & F_28 ( V_227 -> V_231 ) -> V_143 [ V_227 -> V_232 ] ;
V_236 = F_102 ( V_61 ) + V_227 -> V_233 ;
if ( V_237 < V_236 ) {
if ( ! V_227 -> V_234 )
V_227 -> V_234 = F_100 ( F_101 ( V_61 ) ) ;
* V_13 = ( T_3 * ) V_227 -> V_234 + V_61 -> V_146 +
( V_237 - V_227 -> V_233 ) ;
return V_236 - V_237 ;
}
if ( V_227 -> V_234 ) {
F_103 ( V_227 -> V_234 ) ;
V_227 -> V_234 = NULL ;
}
V_227 -> V_232 ++ ;
V_227 -> V_233 += F_102 ( V_61 ) ;
}
if ( V_227 -> V_234 ) {
F_103 ( V_227 -> V_234 ) ;
V_227 -> V_234 = NULL ;
}
if ( V_227 -> V_230 == V_227 -> V_231 && F_61 ( V_227 -> V_230 ) ) {
V_227 -> V_231 = F_28 ( V_227 -> V_230 ) -> V_83 ;
V_227 -> V_232 = 0 ;
goto V_238;
} else if ( V_227 -> V_231 -> V_105 ) {
V_227 -> V_231 = V_227 -> V_231 -> V_105 ;
V_227 -> V_232 = 0 ;
goto V_238;
}
return 0 ;
}
void F_199 ( struct V_226 * V_227 )
{
if ( V_227 -> V_234 )
F_103 ( V_227 -> V_234 ) ;
}
static unsigned int F_200 ( unsigned int V_71 , const T_3 * * V_239 ,
struct V_240 * V_241 ,
struct V_242 * V_243 )
{
return F_198 ( V_71 , V_239 , F_201 ( V_243 ) ) ;
}
static void F_202 ( struct V_240 * V_241 , struct V_242 * V_243 )
{
F_199 ( F_201 ( V_243 ) ) ;
}
unsigned int F_203 ( struct V_6 * V_7 , unsigned int V_205 ,
unsigned int V_178 , struct V_240 * V_244 ,
struct V_242 * V_243 )
{
unsigned int V_204 ;
V_244 -> V_245 = F_200 ;
V_244 -> V_246 = F_202 ;
F_197 ( V_7 , V_205 , V_178 , F_201 ( V_243 ) ) ;
V_204 = F_204 ( V_244 , V_243 ) ;
return ( V_204 <= V_178 - V_205 ? V_204 : V_247 ) ;
}
int F_205 ( struct V_187 * V_135 , struct V_6 * V_7 ,
int (* F_206)( void * V_205 , char * V_178 , int V_71 ,
int V_11 , int V_248 , struct V_6 * V_7 ) ,
void * V_205 , int V_74 )
{
int V_249 = F_28 ( V_7 ) -> V_88 ;
int V_181 ;
int V_71 = 0 ;
int V_204 ;
struct V_188 * V_189 = & V_250 -> V_251 ;
do {
if ( V_249 >= V_193 )
return - V_252 ;
if ( ! F_148 ( V_135 , V_189 ) )
return - V_145 ;
V_181 = F_149 ( int , V_74 , V_189 -> V_19 - V_189 -> V_71 ) ;
V_204 = F_206 ( V_205 , F_42 ( V_189 -> V_5 ) + V_189 -> V_71 ,
V_71 , V_181 , 0 , V_7 ) ;
if ( V_204 < 0 )
return - V_183 ;
F_49 ( V_7 , V_249 , V_189 -> V_5 , V_189 -> V_71 ,
V_181 ) ;
V_249 ++ ;
V_189 -> V_71 += V_181 ;
F_4 ( V_189 -> V_5 ) ;
V_7 -> V_32 += V_181 ;
F_207 ( V_181 , & V_135 -> V_253 ) ;
V_7 -> V_11 += V_181 ;
V_7 -> V_81 += V_181 ;
V_71 += V_181 ;
V_74 -= V_181 ;
} while ( V_74 > 0 );
return 0 ;
}
unsigned char * F_208 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_121 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_121 ( V_7 -> V_11 < V_7 -> V_81 ) ;
F_209 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_210 ( struct V_6 * V_7 , T_9 V_254 )
{
struct V_6 * V_104 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_255 = F_28 ( V_7 ) -> V_83 ;
unsigned int V_256 = F_28 ( V_7 ) -> V_147 ;
unsigned int V_257 = V_7 -> V_13 - F_211 ( V_7 ) ;
unsigned int V_71 = V_257 ;
unsigned int V_258 = F_212 ( V_7 ) ;
unsigned int V_151 ;
unsigned int V_11 ;
T_10 V_259 ;
bool V_119 ;
int V_260 = ! ! ( V_254 & V_261 ) ;
int V_169 = F_28 ( V_7 ) -> V_88 ;
int V_165 = - V_145 ;
int V_79 = 0 ;
int V_206 ;
V_259 = F_213 ( V_7 ) ;
if ( F_37 ( ! V_259 ) )
return F_214 ( - V_262 ) ;
V_119 = ! ! F_215 ( V_254 , V_259 ) ;
F_216 ( V_7 , V_257 ) ;
V_151 = F_95 ( V_7 ) ;
V_206 = F_117 ( V_7 ) ;
do {
struct V_6 * V_263 ;
T_6 * V_61 ;
int V_264 ;
int V_19 ;
V_11 = V_7 -> V_11 - V_71 ;
if ( V_11 > V_256 )
V_11 = V_256 ;
V_264 = F_117 ( V_7 ) - V_71 ;
if ( V_264 < 0 )
V_264 = 0 ;
if ( V_264 > V_11 || ! V_260 )
V_264 = V_11 ;
if ( ! V_264 && V_79 >= V_169 ) {
F_121 ( V_255 -> V_11 != V_11 ) ;
V_206 += V_11 ;
V_263 = F_105 ( V_255 , V_55 ) ;
V_255 = V_255 -> V_105 ;
if ( F_37 ( ! V_263 ) )
goto V_165;
V_264 = F_113 ( V_263 ) ;
if ( F_217 ( V_263 , V_257 + V_151 ) ) {
F_80 ( V_263 ) ;
goto V_165;
}
V_263 -> V_32 += F_113 ( V_263 ) - V_264 ;
F_64 ( V_263 ) ;
F_216 ( V_263 , V_257 ) ;
} else {
V_263 = F_19 ( V_264 + V_257 + V_151 ,
V_55 , F_111 ( V_7 ) ,
V_78 ) ;
if ( F_37 ( ! V_263 ) )
goto V_165;
F_47 ( V_263 , V_151 ) ;
F_218 ( V_263 , V_257 ) ;
}
if ( V_104 )
V_14 -> V_105 = V_263 ;
else
V_104 = V_263 ;
V_14 = V_263 ;
F_87 ( V_263 , V_7 ) ;
V_263 -> V_136 = V_7 -> V_136 ;
if ( V_263 -> V_122 == V_155 )
V_263 -> V_156 += F_95 ( V_263 ) - V_151 ;
F_219 ( V_263 ) ;
F_220 ( V_263 , V_7 -> V_136 ) ;
V_263 -> V_44 = ( V_263 -> V_109 +
F_221 ( V_7 ) ) ;
F_144 ( V_7 , - V_258 ,
V_263 -> V_13 - V_258 ,
V_257 + V_258 ) ;
if ( V_255 != F_28 ( V_7 ) -> V_83 )
continue;
if ( ! V_260 ) {
V_263 -> V_122 = V_265 ;
V_263 -> V_119 = F_166 ( V_7 , V_71 ,
F_114 ( V_263 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_61 = F_28 ( V_263 ) -> V_143 ;
F_144 ( V_7 , V_71 ,
F_114 ( V_263 , V_264 ) , V_264 ) ;
F_28 ( V_263 ) -> V_89 = F_28 ( V_7 ) -> V_89 & V_217 ;
while ( V_206 < V_71 + V_11 && V_79 < V_169 ) {
* V_61 = F_28 ( V_7 ) -> V_143 [ V_79 ] ;
F_195 ( V_61 ) ;
V_19 = F_102 ( V_61 ) ;
if ( V_206 < V_71 ) {
V_61 -> V_146 += V_71 - V_206 ;
F_143 ( V_61 , V_71 - V_206 ) ;
}
F_28 ( V_263 ) -> V_88 ++ ;
if ( V_206 + V_19 <= V_71 + V_11 ) {
V_79 ++ ;
V_206 += V_19 ;
} else {
F_143 ( V_61 , V_206 + V_19 - ( V_71 + V_11 ) ) ;
goto V_266;
}
V_61 ++ ;
}
if ( V_206 < V_71 + V_11 ) {
struct V_6 * V_267 = V_255 ;
F_121 ( V_206 + V_255 -> V_11 != V_71 + V_11 ) ;
V_206 += V_255 -> V_11 ;
V_255 = V_255 -> V_105 ;
if ( V_267 -> V_105 ) {
V_267 = F_105 ( V_267 , V_55 ) ;
if ( ! V_267 )
goto V_165;
} else
F_55 ( V_267 ) ;
F_222 ( V_263 ) ;
F_28 ( V_263 ) -> V_83 = V_267 ;
}
V_266:
V_263 -> V_81 = V_11 - V_264 ;
V_263 -> V_11 += V_263 -> V_81 ;
V_263 -> V_32 += V_263 -> V_81 ;
if ( ! V_119 ) {
V_263 -> V_119 = F_163 ( V_263 , V_257 ,
V_263 -> V_11 - V_257 , 0 ) ;
V_263 -> V_122 = V_265 ;
}
} while ( ( V_71 += V_11 ) < V_7 -> V_11 );
return V_104 ;
V_165:
while ( ( V_7 = V_104 ) ) {
V_104 = V_7 -> V_105 ;
F_80 ( V_7 ) ;
}
return F_214 ( V_165 ) ;
}
int F_223 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_268 = * V_12 ;
struct V_6 * V_263 ;
struct V_37 * V_269 = F_28 ( V_7 ) ;
struct V_37 * V_270 = F_28 ( V_268 ) ;
unsigned int V_151 ;
unsigned int V_11 = F_224 ( V_7 ) ;
unsigned int V_71 = F_225 ( V_7 ) ;
unsigned int V_271 = F_117 ( V_7 ) ;
unsigned int V_272 ;
if ( V_268 -> V_11 + V_11 >= 65536 )
return - V_273 ;
if ( V_270 -> V_83 )
goto V_220;
else if ( V_271 <= V_71 ) {
T_6 * V_61 ;
T_6 * V_274 ;
int V_79 = V_269 -> V_88 ;
int V_88 = V_270 -> V_88 + V_79 ;
V_71 -= V_271 ;
if ( V_88 > V_193 )
return - V_273 ;
V_270 -> V_88 = V_88 ;
V_269 -> V_88 = 0 ;
V_61 = V_270 -> V_143 + V_88 ;
V_274 = V_269 -> V_143 + V_79 ;
do {
* -- V_61 = * -- V_274 ;
} while ( -- V_79 );
V_61 -> V_146 += V_71 ;
F_143 ( V_61 , V_71 ) ;
V_272 = V_7 -> V_32 -
F_26 ( F_113 ( V_7 ) ) ;
V_7 -> V_32 -= V_7 -> V_81 ;
V_7 -> V_11 -= V_7 -> V_81 ;
V_7 -> V_81 = 0 ;
F_226 ( V_7 ) -> free = V_275 ;
goto V_171;
} else if ( V_7 -> V_56 ) {
int V_88 = V_270 -> V_88 ;
T_6 * V_61 = V_270 -> V_143 + V_88 ;
struct V_5 * V_5 = F_46 ( V_7 -> V_12 ) ;
unsigned int V_276 = V_271 - V_71 ;
unsigned int V_277 ;
if ( V_88 + 1 + V_269 -> V_88 > V_193 )
return - V_273 ;
V_277 = V_7 -> V_13 -
( unsigned char * ) F_42 ( V_5 ) +
V_71 ;
V_270 -> V_88 = V_88 + 1 + V_269 -> V_88 ;
V_61 -> V_5 . V_268 = V_5 ;
V_61 -> V_146 = V_277 ;
F_138 ( V_61 , V_276 ) ;
memcpy ( V_61 + 1 , V_269 -> V_143 , sizeof( * V_61 ) * V_269 -> V_88 ) ;
V_272 = V_7 -> V_32 - F_22 ( sizeof( struct V_6 ) ) ;
F_226 ( V_7 ) -> free = V_278 ;
goto V_171;
} else if ( F_224 ( V_268 ) != V_270 -> V_147 )
return - V_273 ;
V_151 = F_95 ( V_268 ) ;
V_263 = F_227 ( V_151 + F_225 ( V_268 ) , V_55 ) ;
if ( F_37 ( ! V_263 ) )
return - V_145 ;
F_87 ( V_263 , V_268 ) ;
V_263 -> V_136 = V_268 -> V_136 ;
F_47 ( V_263 , V_151 ) ;
F_218 ( V_263 , F_225 ( V_268 ) ) ;
F_228 ( V_263 , F_211 ( V_268 ) - V_268 -> V_13 ) ;
F_220 ( V_263 , F_229 ( V_268 ) ) ;
F_230 ( V_263 , F_231 ( V_268 ) ) ;
F_232 ( V_268 , F_225 ( V_268 ) ) ;
memcpy ( F_211 ( V_263 ) , F_211 ( V_268 ) ,
V_268 -> V_13 - F_211 ( V_268 ) ) ;
F_28 ( V_263 ) -> V_83 = V_268 ;
F_28 ( V_263 ) -> V_147 = V_270 -> V_147 ;
V_270 -> V_147 = 0 ;
F_233 ( V_268 ) ;
F_226 ( V_263 ) -> V_279 = V_268 ;
V_263 -> V_81 += V_268 -> V_11 ;
V_263 -> V_32 += V_268 -> V_32 ;
V_263 -> V_11 += V_268 -> V_11 ;
* V_12 = V_263 ;
V_263 -> V_105 = V_268 -> V_105 ;
V_268 -> V_105 = NULL ;
V_268 = V_263 ;
V_220:
V_272 = V_7 -> V_32 ;
if ( V_71 > V_271 ) {
unsigned int V_174 = V_71 - V_271 ;
V_269 -> V_143 [ 0 ] . V_146 += V_174 ;
F_143 ( & V_269 -> V_143 [ 0 ] , V_174 ) ;
V_7 -> V_81 -= V_174 ;
V_7 -> V_11 -= V_174 ;
V_71 = V_271 ;
}
F_232 ( V_7 , V_71 ) ;
F_226 ( V_268 ) -> V_279 -> V_105 = V_7 ;
F_226 ( V_268 ) -> V_279 = V_7 ;
F_233 ( V_7 ) ;
V_171:
F_226 ( V_268 ) -> V_280 ++ ;
V_268 -> V_81 += V_11 ;
V_268 -> V_32 += V_272 ;
V_268 -> V_11 += V_11 ;
F_226 ( V_7 ) -> V_281 = 1 ;
return 0 ;
}
void T_11 F_234 ( void )
{
V_30 = F_235 ( L_3 ,
sizeof( struct V_6 ) ,
0 ,
V_282 | V_283 ,
NULL ) ;
V_40 = F_235 ( L_4 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_4 ) ,
0 ,
V_282 | V_283 ,
NULL ) ;
}
static int
F_236 ( struct V_6 * V_7 , struct V_284 * V_260 , int V_71 , int V_11 )
{
int V_179 = F_117 ( V_7 ) ;
int V_79 , V_181 = V_179 - V_71 ;
struct V_6 * V_180 ;
int V_285 = 0 ;
if ( V_181 > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
F_237 ( V_260 , V_7 -> V_13 + V_71 , V_181 ) ;
V_285 ++ ;
if ( ( V_11 -= V_181 ) == 0 )
return V_285 ;
V_71 += V_181 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_15 ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + F_102 ( & F_28 ( V_7 ) -> V_143 [ V_79 ] ) ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
T_6 * V_61 = & F_28 ( V_7 ) -> V_143 [ V_79 ] ;
if ( V_181 > V_11 )
V_181 = V_11 ;
F_238 ( & V_260 [ V_285 ] , F_101 ( V_61 ) , V_181 ,
V_61 -> V_146 + V_71 - V_179 ) ;
V_285 ++ ;
if ( ! ( V_11 -= V_181 ) )
return V_285 ;
V_71 += V_181 ;
}
V_179 = V_15 ;
}
F_54 (skb, frag_iter) {
int V_15 ;
F_68 ( V_179 > V_71 + V_11 ) ;
V_15 = V_179 + V_180 -> V_11 ;
if ( ( V_181 = V_15 - V_71 ) > 0 ) {
if ( V_181 > V_11 )
V_181 = V_11 ;
V_285 += F_236 ( V_180 , V_260 + V_285 , V_71 - V_179 ,
V_181 ) ;
if ( ( V_11 -= V_181 ) == 0 )
return V_285 ;
V_71 += V_181 ;
}
V_179 = V_15 ;
}
F_121 ( V_11 ) ;
return V_285 ;
}
int F_239 ( struct V_6 * V_7 , struct V_284 * V_260 , int V_71 , int V_11 )
{
int V_286 = F_236 ( V_7 , V_260 , V_71 , V_11 ) ;
F_240 ( & V_260 [ V_286 - 1 ] ) ;
return V_286 ;
}
int F_241 ( struct V_6 * V_7 , int V_287 , struct V_6 * * V_288 )
{
int V_289 ;
int V_285 ;
struct V_6 * V_216 , * * V_290 ;
if ( ( F_124 ( V_7 ) || F_28 ( V_7 ) -> V_88 ) &&
F_141 ( V_7 , F_242 ( V_7 ) - F_117 ( V_7 ) ) == NULL )
return - V_145 ;
if ( ! F_61 ( V_7 ) ) {
if ( F_129 ( V_7 ) < V_287 &&
F_120 ( V_7 , 0 , V_287 - F_129 ( V_7 ) + 128 , V_55 ) )
return - V_145 ;
* V_288 = V_7 ;
return 1 ;
}
V_285 = 1 ;
V_290 = & F_28 ( V_7 ) -> V_83 ;
V_289 = 0 ;
while ( ( V_216 = * V_290 ) != NULL ) {
int V_153 = 0 ;
if ( F_122 ( V_216 ) )
V_289 = 1 ;
if ( V_216 -> V_105 == NULL && V_287 ) {
if ( F_28 ( V_216 ) -> V_88 ||
F_61 ( V_216 ) ||
F_129 ( V_216 ) < V_287 )
V_153 = V_287 + 128 ;
}
if ( V_289 ||
F_124 ( V_216 ) ||
V_153 ||
F_28 ( V_216 ) -> V_88 ||
F_61 ( V_216 ) ) {
struct V_6 * V_157 ;
if ( V_153 == 0 )
V_157 = F_112 ( V_216 , V_55 ) ;
else
V_157 = F_127 ( V_216 ,
F_95 ( V_216 ) ,
V_153 ,
V_55 ) ;
if ( F_37 ( V_157 == NULL ) )
return - V_145 ;
if ( V_216 -> V_135 )
F_243 ( V_157 , V_216 -> V_135 ) ;
V_157 -> V_105 = V_216 -> V_105 ;
* V_290 = V_157 ;
F_80 ( V_216 ) ;
V_216 = V_157 ;
}
V_285 ++ ;
* V_288 = V_216 ;
V_290 = & V_216 -> V_105 ;
}
return V_285 ;
}
static void F_244 ( struct V_6 * V_7 )
{
struct V_187 * V_135 = V_7 -> V_135 ;
F_245 ( V_7 -> V_32 , & V_135 -> V_291 ) ;
}
int F_246 ( struct V_187 * V_135 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_40 ( & V_135 -> V_291 ) + V_7 -> V_32 >=
( unsigned int ) V_135 -> V_292 )
return - V_145 ;
F_247 ( V_7 ) ;
V_7 -> V_135 = V_135 ;
V_7 -> V_97 = F_244 ;
F_207 ( V_7 -> V_32 , & V_135 -> V_291 ) ;
F_248 ( V_7 ) ;
F_180 ( & V_135 -> V_293 , V_7 ) ;
if ( ! F_249 ( V_135 , V_294 ) )
V_135 -> V_295 ( V_135 , V_11 ) ;
return 0 ;
}
void F_250 ( struct V_6 * V_296 ,
struct V_297 * V_298 )
{
struct V_187 * V_135 = V_296 -> V_135 ;
struct V_299 * V_300 ;
struct V_6 * V_7 ;
int V_165 ;
if ( ! V_135 )
return;
if ( V_298 ) {
* F_251 ( V_296 ) =
* V_298 ;
} else {
V_296 -> V_108 = F_252 () ;
}
V_7 = F_105 ( V_296 , V_55 ) ;
if ( ! V_7 )
return;
V_300 = F_253 ( V_7 ) ;
memset ( V_300 , 0 , sizeof( * V_300 ) ) ;
V_300 -> V_301 . V_302 = V_303 ;
V_300 -> V_301 . V_304 = V_305 ;
V_165 = F_246 ( V_135 , V_7 ) ;
if ( V_165 )
F_80 ( V_7 ) ;
}
void F_254 ( struct V_6 * V_7 , bool V_306 )
{
struct V_187 * V_135 = V_7 -> V_135 ;
struct V_299 * V_300 ;
int V_165 ;
V_7 -> V_307 = 1 ;
V_7 -> V_308 = V_306 ;
V_300 = F_253 ( V_7 ) ;
memset ( V_300 , 0 , sizeof( * V_300 ) ) ;
V_300 -> V_301 . V_302 = V_303 ;
V_300 -> V_301 . V_304 = V_309 ;
V_165 = F_246 ( V_135 , V_7 ) ;
if ( V_165 )
F_80 ( V_7 ) ;
}
bool F_255 ( struct V_6 * V_7 , T_12 V_179 , T_12 V_80 )
{
if ( F_37 ( V_179 > F_117 ( V_7 ) ) ||
F_37 ( ( int ) V_179 + V_80 > F_117 ( V_7 ) - 2 ) ) {
F_256 ( L_5 ,
V_179 , V_80 , F_117 ( V_7 ) ) ;
return false ;
}
V_7 -> V_122 = V_155 ;
V_7 -> V_156 = F_95 ( V_7 ) + V_179 ;
V_7 -> V_210 = V_80 ;
F_230 ( V_7 , V_179 ) ;
return true ;
}
void F_257 ( const struct V_6 * V_7 )
{
F_256 ( L_6 ,
V_7 -> V_16 -> V_17 ) ;
}
void F_258 ( struct V_6 * V_7 , bool V_310 )
{
if ( V_310 ) {
F_64 ( V_7 ) ;
F_31 ( V_30 , V_7 ) ;
} else {
F_79 ( V_7 ) ;
}
}
bool F_259 ( struct V_6 * V_178 , struct V_6 * V_205 ,
bool * V_311 , int * V_272 )
{
int V_79 , V_158 , V_11 = V_205 -> V_11 ;
* V_311 = false ;
if ( F_124 ( V_178 ) )
return false ;
if ( V_11 <= F_129 ( V_178 ) ) {
F_121 ( F_115 ( V_205 , 0 , F_114 ( V_178 , V_11 ) , V_11 ) ) ;
* V_272 = 0 ;
return true ;
}
if ( F_61 ( V_178 ) || F_61 ( V_205 ) )
return false ;
if ( F_117 ( V_205 ) != 0 ) {
struct V_5 * V_5 ;
unsigned int V_71 ;
if ( F_28 ( V_178 ) -> V_88 +
F_28 ( V_205 ) -> V_88 >= V_193 )
return false ;
if ( F_156 ( V_205 ) )
return false ;
V_158 = V_205 -> V_32 - F_22 ( sizeof( struct V_6 ) ) ;
V_5 = F_46 ( V_205 -> V_12 ) ;
V_71 = V_205 -> V_13 - ( unsigned char * ) F_42 ( V_5 ) ;
F_49 ( V_178 , F_28 ( V_178 ) -> V_88 ,
V_5 , V_71 , F_117 ( V_205 ) ) ;
* V_311 = true ;
} else {
if ( F_28 ( V_178 ) -> V_88 +
F_28 ( V_205 ) -> V_88 > V_193 )
return false ;
V_158 = V_205 -> V_32 - F_26 ( F_113 ( V_205 ) ) ;
}
F_260 ( V_158 < V_11 ) ;
memcpy ( F_28 ( V_178 ) -> V_143 + F_28 ( V_178 ) -> V_88 ,
F_28 ( V_205 ) -> V_143 ,
F_28 ( V_205 ) -> V_88 * sizeof( T_6 ) ) ;
F_28 ( V_178 ) -> V_88 += F_28 ( V_205 ) -> V_88 ;
if ( ! F_124 ( V_205 ) )
F_28 ( V_205 ) -> V_88 = 0 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_205 ) -> V_88 ; V_79 ++ )
F_119 ( V_205 , V_79 ) ;
V_178 -> V_32 += V_158 ;
V_178 -> V_11 += V_11 ;
V_178 -> V_81 += V_11 ;
* V_272 = V_158 ;
return true ;
}
