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
struct V_6 * F_14 ( unsigned int V_19 , T_2 V_29 ,
int V_20 , int V_21 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_6 * V_7 ;
T_3 * V_13 ;
bool V_23 ;
V_31 = ( V_20 & V_34 )
? V_35 : V_36 ;
if ( F_15 () && ( V_20 & V_37 ) )
V_29 |= V_38 ;
V_7 = F_16 ( V_31 , V_29 & ~ V_39 , V_21 ) ;
if ( ! V_7 )
goto V_28;
F_17 ( V_7 ) ;
V_19 = F_18 ( V_19 ) ;
V_19 += F_18 ( sizeof( struct V_32 ) ) ;
V_13 = F_19 ( V_19 , V_29 , V_21 , & V_23 ) ;
if ( ! V_13 )
goto V_40;
V_19 = F_20 ( F_21 ( V_13 ) ) ;
F_17 ( V_13 + V_19 ) ;
memset ( V_7 , 0 , F_22 ( struct V_6 , V_14 ) ) ;
V_7 -> V_41 = F_23 ( V_19 ) ;
V_7 -> V_23 = V_23 ;
F_24 ( & V_7 -> V_42 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_25 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_19 ;
#ifdef F_26
V_7 -> V_43 = ~ 0U ;
V_7 -> V_44 = ~ 0U ;
#endif
V_33 = F_27 ( V_7 ) ;
memset ( V_33 , 0 , F_22 ( struct V_32 , V_45 ) ) ;
F_24 ( & V_33 -> V_45 , 1 ) ;
F_28 ( V_33 -> V_46 ) ;
if ( V_20 & V_34 ) {
struct V_6 * V_47 = V_7 + 1 ;
T_4 * V_48 = ( T_4 * ) ( V_47 + 1 ) ;
F_29 ( V_47 , V_49 ) ;
F_29 ( V_47 , V_50 ) ;
V_7 -> V_51 = V_52 ;
F_24 ( V_48 , 1 ) ;
V_47 -> V_51 = V_53 ;
V_47 -> V_23 = V_23 ;
}
V_28:
return V_7 ;
V_40:
F_30 ( V_31 , V_7 ) ;
V_7 = NULL ;
goto V_28;
}
struct V_6 * F_31 ( void * V_13 , unsigned int V_54 )
{
struct V_32 * V_33 ;
struct V_6 * V_7 ;
unsigned int V_19 = V_54 ? : F_21 ( V_13 ) ;
V_7 = F_32 ( V_36 , V_55 ) ;
if ( ! V_7 )
return NULL ;
V_19 -= F_18 ( sizeof( struct V_32 ) ) ;
memset ( V_7 , 0 , F_22 ( struct V_6 , V_14 ) ) ;
V_7 -> V_41 = F_23 ( V_19 ) ;
V_7 -> V_56 = V_54 != 0 ;
F_24 ( & V_7 -> V_42 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_25 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_19 ;
#ifdef F_26
V_7 -> V_43 = ~ 0U ;
V_7 -> V_44 = ~ 0U ;
#endif
V_33 = F_27 ( V_7 ) ;
memset ( V_33 , 0 , F_22 ( struct V_32 , V_45 ) ) ;
F_24 ( & V_33 -> V_45 , 1 ) ;
F_28 ( V_33 -> V_46 ) ;
return V_7 ;
}
static void * F_33 ( unsigned int V_57 , T_2 V_29 )
{
struct V_58 * V_59 ;
void * V_13 = NULL ;
int V_60 ;
unsigned long V_20 ;
F_34 ( V_20 ) ;
V_59 = & F_35 ( V_58 ) ;
if ( F_36 ( ! V_59 -> V_61 . V_5 ) ) {
V_62:
for ( V_60 = V_63 ; ; ) {
T_2 V_64 = V_29 ;
if ( V_60 )
V_64 |= V_65 | V_27 ;
V_59 -> V_61 . V_5 = F_37 ( V_64 , V_60 ) ;
if ( F_38 ( V_59 -> V_61 . V_5 ) )
break;
if ( -- V_60 < 0 )
goto V_15;
}
V_59 -> V_61 . V_19 = V_66 << V_60 ;
V_67:
F_24 ( & V_59 -> V_61 . V_5 -> V_68 , V_69 ) ;
V_59 -> V_70 = V_69 ;
V_59 -> V_61 . V_71 = 0 ;
}
if ( V_59 -> V_61 . V_71 + V_57 > V_59 -> V_61 . V_19 ) {
if ( ( F_39 ( & V_59 -> V_61 . V_5 -> V_68 ) == V_59 -> V_70 ) ||
F_40 ( V_59 -> V_70 , & V_59 -> V_61 . V_5 -> V_68 ) )
goto V_67;
goto V_62;
}
V_13 = F_41 ( V_59 -> V_61 . V_5 ) + V_59 -> V_61 . V_71 ;
V_59 -> V_61 . V_71 += V_57 ;
V_59 -> V_70 -- ;
V_15:
F_42 ( V_20 ) ;
return V_13 ;
}
void * F_43 ( unsigned int V_57 )
{
return F_33 ( V_57 , V_55 | V_72 ) ;
}
struct V_6 * F_44 ( struct V_73 * V_16 ,
unsigned int V_74 , T_2 V_29 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_57 = F_18 ( V_74 + V_75 ) +
F_18 ( sizeof( struct V_32 ) ) ;
if ( V_57 <= V_66 && ! ( V_29 & ( V_76 | V_77 ) ) ) {
void * V_13 ;
if ( F_15 () )
V_29 |= V_38 ;
V_13 = F_33 ( V_57 , V_29 ) ;
if ( F_38 ( V_13 ) ) {
V_7 = F_31 ( V_13 , V_57 ) ;
if ( F_36 ( ! V_7 ) )
F_2 ( F_45 ( V_13 ) ) ;
}
} else {
V_7 = F_14 ( V_74 + V_75 , V_29 ,
V_37 , V_78 ) ;
}
if ( F_38 ( V_7 ) ) {
F_46 ( V_7 , V_75 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_47 ( struct V_6 * V_7 , int V_79 , struct V_5 * V_5 , int V_80 ,
int V_19 , unsigned int V_41 )
{
F_48 ( V_7 , V_79 , V_5 , V_80 , V_19 ) ;
V_7 -> V_11 += V_19 ;
V_7 -> V_81 += V_19 ;
V_7 -> V_41 += V_41 ;
}
static void F_49 ( struct V_6 * * V_82 )
{
struct V_6 * V_83 = * V_82 ;
* V_82 = NULL ;
do {
struct V_6 * V_84 = V_83 ;
V_83 = V_83 -> V_85 ;
F_50 ( V_84 ) ;
} while ( V_83 );
}
static inline void F_51 ( struct V_6 * V_7 )
{
F_49 ( & F_27 ( V_7 ) -> V_86 ) ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_6 * V_83 ;
F_53 (skb, list)
F_54 ( V_83 ) ;
}
static void F_55 ( struct V_6 * V_7 )
{
if ( V_7 -> V_56 )
F_2 ( F_45 ( V_7 -> V_12 ) ) ;
else
F_56 ( V_7 -> V_12 ) ;
}
static void F_57 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_87 ||
! F_58 ( V_7 -> V_88 ? ( 1 << V_89 ) + 1 : 1 ,
& F_27 ( V_7 ) -> V_45 ) ) {
if ( F_27 ( V_7 ) -> V_90 ) {
int V_79 ;
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ )
F_59 ( V_7 , V_79 ) ;
}
if ( F_27 ( V_7 ) -> V_91 & V_92 ) {
struct V_93 * V_94 ;
V_94 = F_27 ( V_7 ) -> V_46 ;
if ( V_94 -> V_95 )
V_94 -> V_95 ( V_94 , true ) ;
}
if ( F_60 ( V_7 ) )
F_51 ( V_7 ) ;
F_55 ( V_7 ) ;
}
}
static void F_61 ( struct V_6 * V_7 )
{
struct V_6 * V_96 ;
T_4 * V_48 ;
switch ( V_7 -> V_51 ) {
case V_53 :
F_30 ( V_36 , V_7 ) ;
break;
case V_52 :
V_48 = ( T_4 * ) ( V_7 + 2 ) ;
if ( F_62 ( V_48 ) )
F_30 ( V_35 , V_7 ) ;
break;
case V_97 :
V_48 = ( T_4 * ) ( V_7 + 1 ) ;
V_96 = V_7 - 1 ;
V_7 -> V_51 = V_53 ;
if ( F_62 ( V_48 ) )
F_30 ( V_35 , V_96 ) ;
break;
}
}
static void F_63 ( struct V_6 * V_7 )
{
F_64 ( V_7 ) ;
#ifdef F_65
F_66 ( V_7 -> V_98 ) ;
#endif
if ( V_7 -> V_99 ) {
F_67 ( F_68 () ) ;
V_7 -> V_99 ( V_7 ) ;
}
#if F_69 ( V_100 )
F_70 ( V_7 -> V_101 ) ;
#endif
#ifdef F_71
F_72 ( V_7 -> V_102 ) ;
#endif
#ifdef F_73
F_74 ( V_7 -> V_103 ) ;
#endif
#ifdef F_75
V_7 -> V_104 = 0 ;
#ifdef F_76
V_7 -> V_105 = 0 ;
#endif
#endif
}
static void F_77 ( struct V_6 * V_7 )
{
F_63 ( V_7 ) ;
F_57 ( V_7 ) ;
}
void F_78 ( struct V_6 * V_7 )
{
F_77 ( V_7 ) ;
F_61 ( V_7 ) ;
}
void F_50 ( struct V_6 * V_7 )
{
if ( F_36 ( ! V_7 ) )
return;
if ( F_38 ( F_39 ( & V_7 -> V_42 ) == 1 ) )
F_79 () ;
else if ( F_38 ( ! F_62 ( & V_7 -> V_42 ) ) )
return;
F_80 ( V_7 , F_81 ( 0 ) ) ;
F_78 ( V_7 ) ;
}
void F_82 ( struct V_6 * V_7 )
{
if ( F_27 ( V_7 ) -> V_91 & V_92 ) {
struct V_93 * V_94 ;
V_94 = F_27 ( V_7 ) -> V_46 ;
if ( V_94 -> V_95 )
V_94 -> V_95 ( V_94 , false ) ;
F_27 ( V_7 ) -> V_91 &= ~ V_92 ;
}
}
void F_83 ( struct V_6 * V_7 )
{
if ( F_36 ( ! V_7 ) )
return;
if ( F_38 ( F_39 ( & V_7 -> V_42 ) == 1 ) )
F_79 () ;
else if ( F_38 ( ! F_62 ( & V_7 -> V_42 ) ) )
return;
F_84 ( V_7 ) ;
F_78 ( V_7 ) ;
}
static void F_85 ( struct V_6 * V_106 , const struct V_6 * V_107 )
{
V_106 -> V_108 = V_107 -> V_108 ;
V_106 -> V_16 = V_107 -> V_16 ;
V_106 -> V_44 = V_107 -> V_44 ;
V_106 -> V_109 = V_107 -> V_109 ;
V_106 -> V_43 = V_107 -> V_43 ;
V_106 -> V_110 = V_107 -> V_110 ;
V_106 -> V_111 = V_107 -> V_111 ;
F_86 ( V_106 , V_107 ) ;
V_106 -> V_112 = V_107 -> V_112 ;
V_106 -> V_113 = V_107 -> V_113 ;
V_106 -> V_114 = V_107 -> V_114 ;
V_106 -> V_115 = V_107 -> V_115 ;
V_106 -> V_116 = V_107 -> V_116 ;
#ifdef F_65
V_106 -> V_98 = F_87 ( V_107 -> V_98 ) ;
#endif
memcpy ( V_106 -> V_117 , V_107 -> V_117 , sizeof( V_107 -> V_117 ) ) ;
V_106 -> V_118 = V_107 -> V_118 ;
V_106 -> V_119 = V_107 -> V_119 ;
V_106 -> V_120 = V_107 -> V_120 ;
V_106 -> V_121 = V_107 -> V_121 ;
F_88 ( V_106 , V_107 ) ;
V_106 -> V_122 = V_107 -> V_122 ;
#if F_69 ( V_123 )
V_106 -> V_124 = V_107 -> V_124 ;
#endif
V_106 -> V_23 = V_107 -> V_23 ;
V_106 -> V_125 = V_107 -> V_125 ;
V_106 -> V_126 = V_107 -> V_126 ;
V_106 -> V_127 = V_107 -> V_127 ;
F_89 ( V_106 , V_107 ) ;
#if F_69 ( V_128 )
V_106 -> V_129 = V_107 -> V_129 ;
#endif
#ifdef F_75
V_106 -> V_104 = V_107 -> V_104 ;
#ifdef F_76
V_106 -> V_105 = V_107 -> V_105 ;
#endif
#endif
V_106 -> V_130 = V_107 -> V_130 ;
F_90 ( V_106 , V_107 ) ;
}
static struct V_6 * F_91 ( struct V_6 * V_131 , struct V_6 * V_7 )
{
#define F_92 ( T_5 ) n->x = skb->x
V_131 -> V_85 = V_131 -> V_132 = NULL ;
V_131 -> V_133 = NULL ;
F_85 ( V_131 , V_7 ) ;
F_92 ( V_11 ) ;
F_92 ( V_81 ) ;
F_92 ( V_134 ) ;
V_131 -> V_135 = V_7 -> V_88 ? F_93 ( V_7 ) : V_7 -> V_135 ;
V_131 -> V_87 = 1 ;
V_131 -> V_88 = 0 ;
V_131 -> V_99 = NULL ;
F_92 ( V_14 ) ;
F_92 ( V_15 ) ;
F_92 ( V_12 ) ;
F_92 ( V_56 ) ;
F_92 ( V_13 ) ;
F_92 ( V_41 ) ;
F_24 ( & V_131 -> V_42 , 1 ) ;
F_94 ( & ( F_27 ( V_7 ) -> V_45 ) ) ;
V_7 -> V_87 = 1 ;
return V_131 ;
#undef F_92
}
struct V_6 * F_95 ( struct V_6 * V_136 , struct V_6 * V_137 )
{
F_77 ( V_136 ) ;
return F_91 ( V_136 , V_137 ) ;
}
int F_96 ( struct V_6 * V_7 , T_2 V_29 )
{
int V_79 ;
int V_138 = F_27 ( V_7 ) -> V_90 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_93 * V_94 = F_27 ( V_7 ) -> V_46 ;
for ( V_79 = 0 ; V_79 < V_138 ; V_79 ++ ) {
T_3 * V_139 ;
T_6 * V_140 = & F_27 ( V_7 ) -> V_141 [ V_79 ] ;
V_5 = F_97 ( V_29 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_85 = (struct V_5 * ) V_12 -> V_142 ;
F_2 ( V_12 ) ;
V_12 = V_85 ;
}
return - V_143 ;
}
V_139 = F_98 ( F_99 ( V_140 ) ) ;
memcpy ( F_41 ( V_5 ) ,
V_139 + V_140 -> V_144 , F_100 ( V_140 ) ) ;
F_101 ( V_139 ) ;
V_5 -> V_142 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_79 = 0 ; V_79 < V_138 ; V_79 ++ )
F_59 ( V_7 , V_79 ) ;
V_94 -> V_95 ( V_94 , false ) ;
for ( V_79 = V_138 - 1 ; V_79 >= 0 ; V_79 -- ) {
F_102 ( V_7 , V_79 , V_12 , 0 ,
F_27 ( V_7 ) -> V_141 [ V_79 ] . V_19 ) ;
V_12 = (struct V_5 * ) V_12 -> V_142 ;
}
F_27 ( V_7 ) -> V_91 &= ~ V_92 ;
return 0 ;
}
struct V_6 * F_103 ( struct V_6 * V_7 , T_2 V_29 )
{
struct V_6 * V_131 ;
if ( F_104 ( V_7 , V_29 ) )
return NULL ;
V_131 = V_7 + 1 ;
if ( V_7 -> V_51 == V_52 &&
V_131 -> V_51 == V_53 ) {
T_4 * V_48 = ( T_4 * ) ( V_131 + 1 ) ;
V_131 -> V_51 = V_97 ;
F_94 ( V_48 ) ;
} else {
if ( F_105 ( V_7 ) )
V_29 |= V_38 ;
V_131 = F_32 ( V_36 , V_29 ) ;
if ( ! V_131 )
return NULL ;
F_29 ( V_131 , V_49 ) ;
F_29 ( V_131 , V_50 ) ;
V_131 -> V_51 = V_53 ;
}
return F_91 ( V_131 , V_7 ) ;
}
static void F_106 ( struct V_6 * V_106 , const struct V_6 * V_107 )
{
#ifndef F_26
unsigned long V_71 = V_106 -> V_13 - V_107 -> V_13 ;
#endif
F_85 ( V_106 , V_107 ) ;
#ifndef F_26
V_106 -> V_44 += V_71 ;
V_106 -> V_109 += V_71 ;
if ( F_107 ( V_106 ) )
V_106 -> V_43 += V_71 ;
V_106 -> V_110 += V_71 ;
V_106 -> V_111 += V_71 ;
#endif
F_27 ( V_106 ) -> V_145 = F_27 ( V_107 ) -> V_145 ;
F_27 ( V_106 ) -> V_146 = F_27 ( V_107 ) -> V_146 ;
F_27 ( V_106 ) -> V_147 = F_27 ( V_107 ) -> V_147 ;
}
static inline int F_108 ( const struct V_6 * V_7 )
{
if ( F_105 ( V_7 ) )
return V_37 ;
return 0 ;
}
struct V_6 * F_109 ( const struct V_6 * V_7 , T_2 V_29 )
{
int V_148 = F_93 ( V_7 ) ;
unsigned int V_19 = F_110 ( V_7 ) + V_7 -> V_81 ;
struct V_6 * V_131 = F_14 ( V_19 , V_29 ,
F_108 ( V_7 ) , V_78 ) ;
if ( ! V_131 )
return NULL ;
F_46 ( V_131 , V_148 ) ;
F_111 ( V_131 , V_7 -> V_11 ) ;
if ( F_112 ( V_7 , - V_148 , V_131 -> V_12 , V_148 + V_7 -> V_11 ) )
F_8 () ;
F_106 ( V_131 , V_7 ) ;
return V_131 ;
}
struct V_6 * F_113 ( struct V_6 * V_7 , int V_149 , T_2 V_29 )
{
unsigned int V_19 = F_114 ( V_7 ) + V_149 ;
struct V_6 * V_131 = F_14 ( V_19 , V_29 ,
F_108 ( V_7 ) , V_78 ) ;
if ( ! V_131 )
goto V_28;
F_46 ( V_131 , V_149 ) ;
F_111 ( V_131 , F_114 ( V_7 ) ) ;
F_115 ( V_7 , V_131 -> V_13 , V_131 -> V_11 ) ;
V_131 -> V_41 += V_7 -> V_81 ;
V_131 -> V_81 = V_7 -> V_81 ;
V_131 -> V_11 = V_7 -> V_11 ;
if ( F_27 ( V_7 ) -> V_90 ) {
int V_79 ;
if ( F_104 ( V_7 , V_29 ) ) {
F_50 ( V_131 ) ;
V_131 = NULL ;
goto V_28;
}
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ ) {
F_27 ( V_131 ) -> V_141 [ V_79 ] = F_27 ( V_7 ) -> V_141 [ V_79 ] ;
F_116 ( V_7 , V_79 ) ;
}
F_27 ( V_131 ) -> V_90 = V_79 ;
}
if ( F_60 ( V_7 ) ) {
F_27 ( V_131 ) -> V_86 = F_27 ( V_7 ) -> V_86 ;
F_52 ( V_131 ) ;
}
F_106 ( V_131 , V_7 ) ;
V_28:
return V_131 ;
}
int F_117 ( struct V_6 * V_7 , int V_150 , int V_151 ,
T_2 V_29 )
{
int V_79 ;
T_3 * V_13 ;
int V_19 = V_150 + F_110 ( V_7 ) + V_151 ;
long V_80 ;
F_118 ( V_150 < 0 ) ;
if ( F_119 ( V_7 ) )
F_8 () ;
V_19 = F_18 ( V_19 ) ;
if ( F_105 ( V_7 ) )
V_29 |= V_38 ;
V_13 = F_19 ( V_19 + F_18 ( sizeof( struct V_32 ) ) ,
V_29 , V_78 , NULL ) ;
if ( ! V_13 )
goto V_40;
V_19 = F_20 ( F_21 ( V_13 ) ) ;
memcpy ( V_13 + V_150 , V_7 -> V_12 , F_120 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_32 * ) ( V_13 + V_19 ) ,
F_27 ( V_7 ) ,
F_22 ( struct V_32 , V_141 [ F_27 ( V_7 ) -> V_90 ] ) ) ;
if ( F_121 ( V_7 ) ) {
if ( F_104 ( V_7 , V_29 ) )
goto V_152;
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ )
F_116 ( V_7 , V_79 ) ;
if ( F_60 ( V_7 ) )
F_52 ( V_7 ) ;
F_57 ( V_7 ) ;
} else {
F_55 ( V_7 ) ;
}
V_80 = ( V_13 + V_150 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_56 = 0 ;
V_7 -> V_13 += V_80 ;
#ifdef F_26
V_7 -> V_15 = V_19 ;
V_80 = V_150 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_19 ;
#endif
V_7 -> V_14 += V_80 ;
V_7 -> V_44 += V_80 ;
V_7 -> V_109 += V_80 ;
if ( F_107 ( V_7 ) )
V_7 -> V_43 += V_80 ;
V_7 -> V_110 += V_80 ;
V_7 -> V_111 += V_80 ;
if ( V_7 -> V_121 == V_153 )
V_7 -> V_154 += V_150 ;
V_7 -> V_87 = 0 ;
V_7 -> V_135 = 0 ;
V_7 -> V_88 = 0 ;
F_24 ( & F_27 ( V_7 ) -> V_45 , 1 ) ;
return 0 ;
V_152:
F_56 ( V_13 ) ;
V_40:
return - V_143 ;
}
struct V_6 * F_122 ( struct V_6 * V_7 , unsigned int V_149 )
{
struct V_6 * V_155 ;
int V_156 = V_149 - F_93 ( V_7 ) ;
if ( V_156 <= 0 )
V_155 = F_123 ( V_7 , V_55 ) ;
else {
V_155 = F_103 ( V_7 , V_55 ) ;
if ( V_155 && F_117 ( V_155 , F_18 ( V_156 ) , 0 ,
V_55 ) ) {
F_50 ( V_155 ) ;
V_155 = NULL ;
}
}
return V_155 ;
}
struct V_6 * F_124 ( const struct V_6 * V_7 ,
int V_157 , int V_158 ,
T_2 V_29 )
{
struct V_6 * V_131 = F_14 ( V_157 + V_7 -> V_11 + V_158 ,
V_29 , F_108 ( V_7 ) ,
V_78 ) ;
int V_159 = F_93 ( V_7 ) ;
int V_160 , V_161 ;
int V_80 ;
if ( ! V_131 )
return NULL ;
F_46 ( V_131 , V_157 ) ;
F_111 ( V_131 , V_7 -> V_11 ) ;
V_160 = V_159 ;
V_161 = 0 ;
if ( V_157 <= V_160 )
V_160 = V_157 ;
else
V_161 = V_157 - V_160 ;
if ( F_112 ( V_7 , - V_160 , V_131 -> V_12 + V_161 ,
V_7 -> V_11 + V_160 ) )
F_8 () ;
F_106 ( V_131 , V_7 ) ;
V_80 = V_157 - V_159 ;
if ( V_131 -> V_121 == V_153 )
V_131 -> V_154 += V_80 ;
#ifdef F_26
V_131 -> V_44 += V_80 ;
V_131 -> V_109 += V_80 ;
if ( F_107 ( V_7 ) )
V_131 -> V_43 += V_80 ;
V_131 -> V_110 += V_80 ;
V_131 -> V_111 += V_80 ;
#endif
return V_131 ;
}
int F_125 ( struct V_6 * V_7 , int V_162 )
{
int V_163 ;
int V_151 ;
if ( ! F_121 ( V_7 ) && F_126 ( V_7 ) >= V_162 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_162 ) ;
return 0 ;
}
V_151 = V_7 -> V_81 + V_162 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_38 ( F_121 ( V_7 ) || V_151 > 0 ) ) {
V_163 = F_117 ( V_7 , 0 , V_151 , V_55 ) ;
if ( F_36 ( V_163 ) )
goto V_164;
}
V_163 = F_127 ( V_7 ) ;
if ( F_36 ( V_163 ) )
goto V_164;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_162 ) ;
return 0 ;
V_164:
F_50 ( V_7 ) ;
return V_163 ;
}
unsigned char * F_111 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_165 = F_120 ( V_7 ) ;
F_128 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_36 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_9 ( V_7 , V_11 , F_81 ( 0 ) ) ;
return V_165 ;
}
unsigned char * F_129 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_36 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_10 ( V_7 , V_11 , F_81 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_130 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_131 ( V_7 , V_11 ) ;
}
void F_132 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_133 ( V_7 , V_11 ) ;
}
int F_134 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_166 ;
struct V_6 * V_61 ;
int V_71 = F_114 ( V_7 ) ;
int V_167 = F_27 ( V_7 ) -> V_90 ;
int V_79 ;
int V_163 ;
if ( F_121 ( V_7 ) &&
F_36 ( ( V_163 = F_117 ( V_7 , 0 , 0 , V_55 ) ) ) )
return V_163 ;
V_79 = 0 ;
if ( V_71 >= V_11 )
goto V_168;
for (; V_79 < V_167 ; V_79 ++ ) {
int V_15 = V_71 + F_100 ( & F_27 ( V_7 ) -> V_141 [ V_79 ] ) ;
if ( V_15 < V_11 ) {
V_71 = V_15 ;
continue;
}
F_135 ( & F_27 ( V_7 ) -> V_141 [ V_79 ++ ] , V_11 - V_71 ) ;
V_168:
F_27 ( V_7 ) -> V_90 = V_79 ;
for (; V_79 < V_167 ; V_79 ++ )
F_59 ( V_7 , V_79 ) ;
if ( F_60 ( V_7 ) )
F_51 ( V_7 ) ;
goto V_169;
}
for ( V_166 = & F_27 ( V_7 ) -> V_86 ; ( V_61 = * V_166 ) ;
V_166 = & V_61 -> V_85 ) {
int V_15 = V_71 + V_61 -> V_11 ;
if ( F_119 ( V_61 ) ) {
struct V_6 * V_170 ;
V_170 = F_103 ( V_61 , V_55 ) ;
if ( F_36 ( ! V_170 ) )
return - V_143 ;
V_170 -> V_85 = V_61 -> V_85 ;
F_83 ( V_61 ) ;
V_61 = V_170 ;
* V_166 = V_61 ;
}
if ( V_15 < V_11 ) {
V_71 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_36 ( ( V_163 = F_136 ( V_61 , V_11 - V_71 ) ) ) )
return V_163 ;
if ( V_61 -> V_85 )
F_49 ( & V_61 -> V_85 ) ;
break;
}
V_169:
if ( V_11 > F_114 ( V_7 ) ) {
V_7 -> V_81 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_81 = 0 ;
F_137 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_138 ( struct V_6 * V_7 , int V_156 )
{
int V_79 , V_171 , V_172 = ( V_7 -> V_14 + V_156 ) - V_7 -> V_15 ;
if ( V_172 > 0 || F_121 ( V_7 ) ) {
if ( F_117 ( V_7 , 0 , V_172 > 0 ? V_172 + 128 : 0 ,
V_55 ) )
return NULL ;
}
if ( F_112 ( V_7 , F_114 ( V_7 ) , F_120 ( V_7 ) , V_156 ) )
F_8 () ;
if ( ! F_60 ( V_7 ) )
goto V_173;
V_172 = V_156 ;
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ ) {
int V_19 = F_100 ( & F_27 ( V_7 ) -> V_141 [ V_79 ] ) ;
if ( V_19 >= V_172 )
goto V_173;
V_172 -= V_19 ;
}
if ( V_172 ) {
struct V_6 * V_83 = F_27 ( V_7 ) -> V_86 ;
struct V_6 * V_174 = NULL ;
struct V_6 * V_175 = NULL ;
do {
F_118 ( ! V_83 ) ;
if ( V_83 -> V_11 <= V_172 ) {
V_172 -= V_83 -> V_11 ;
V_83 = V_83 -> V_85 ;
V_175 = V_83 ;
} else {
if ( F_119 ( V_83 ) ) {
V_174 = F_103 ( V_83 , V_55 ) ;
if ( ! V_174 )
return NULL ;
V_175 = V_83 -> V_85 ;
V_83 = V_174 ;
} else {
V_175 = V_83 ;
}
if ( ! F_139 ( V_83 , V_172 ) ) {
F_50 ( V_174 ) ;
return NULL ;
}
break;
}
} while ( V_172 );
while ( ( V_83 = F_27 ( V_7 ) -> V_86 ) != V_175 ) {
F_27 ( V_7 ) -> V_86 = V_83 -> V_85 ;
F_50 ( V_83 ) ;
}
if ( V_174 ) {
V_174 -> V_85 = V_83 ;
F_27 ( V_7 ) -> V_86 = V_174 ;
}
}
V_173:
V_172 = V_156 ;
V_171 = 0 ;
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ ) {
int V_19 = F_100 ( & F_27 ( V_7 ) -> V_141 [ V_79 ] ) ;
if ( V_19 <= V_172 ) {
F_59 ( V_7 , V_79 ) ;
V_172 -= V_19 ;
} else {
F_27 ( V_7 ) -> V_141 [ V_171 ] = F_27 ( V_7 ) -> V_141 [ V_79 ] ;
if ( V_172 ) {
F_27 ( V_7 ) -> V_141 [ V_171 ] . V_144 += V_172 ;
F_140 ( & F_27 ( V_7 ) -> V_141 [ V_171 ] , V_172 ) ;
V_172 = 0 ;
}
V_171 ++ ;
}
}
F_27 ( V_7 ) -> V_90 = V_171 ;
V_7 -> V_14 += V_156 ;
V_7 -> V_81 -= V_156 ;
return F_120 ( V_7 ) ;
}
int F_112 ( const struct V_6 * V_7 , int V_71 , void * V_176 , int V_11 )
{
int V_177 = F_114 ( V_7 ) ;
struct V_6 * V_178 ;
int V_79 , V_179 ;
if ( V_71 > ( int ) V_7 -> V_11 - V_11 )
goto V_180;
if ( ( V_179 = V_177 - V_71 ) > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
F_141 ( V_7 , V_71 , V_176 , V_179 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return 0 ;
V_71 += V_179 ;
V_176 += V_179 ;
}
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ ) {
int V_15 ;
T_6 * V_140 = & F_27 ( V_7 ) -> V_141 [ V_79 ] ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + F_100 ( V_140 ) ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
T_3 * V_139 ;
if ( V_179 > V_11 )
V_179 = V_11 ;
V_139 = F_98 ( F_99 ( V_140 ) ) ;
memcpy ( V_176 ,
V_139 + V_140 -> V_144 + V_71 - V_177 ,
V_179 ) ;
F_101 ( V_139 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return 0 ;
V_71 += V_179 ;
V_176 += V_179 ;
}
V_177 = V_15 ;
}
F_53 (skb, frag_iter) {
int V_15 ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + V_178 -> V_11 ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
if ( F_112 ( V_178 , V_71 - V_177 , V_176 , V_179 ) )
goto V_180;
if ( ( V_11 -= V_179 ) == 0 )
return 0 ;
V_71 += V_179 ;
V_176 += V_179 ;
}
V_177 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_180:
return - V_181 ;
}
static void F_142 ( struct V_182 * V_183 , unsigned int V_79 )
{
F_2 ( V_183 -> V_184 [ V_79 ] ) ;
}
static struct V_5 * F_143 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_71 ,
struct V_185 * V_133 )
{
struct V_186 * V_187 = F_144 ( V_133 ) ;
if ( ! F_145 ( V_133 , V_187 ) )
return NULL ;
* V_11 = F_146 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_41 ( V_187 -> V_5 ) + V_187 -> V_71 ,
F_41 ( V_5 ) + * V_71 , * V_11 ) ;
* V_71 = V_187 -> V_71 ;
V_187 -> V_71 += * V_11 ;
return V_187 -> V_5 ;
}
static bool F_147 ( const struct V_182 * V_183 ,
struct V_5 * V_5 ,
unsigned int V_71 )
{
return V_183 -> V_188 &&
V_183 -> V_184 [ V_183 -> V_188 - 1 ] == V_5 &&
( V_183 -> V_189 [ V_183 -> V_188 - 1 ] . V_71 +
V_183 -> V_189 [ V_183 -> V_188 - 1 ] . V_11 == V_71 ) ;
}
static bool F_148 ( struct V_182 * V_183 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_71 ,
bool V_190 ,
struct V_185 * V_133 )
{
if ( F_36 ( V_183 -> V_188 == V_191 ) )
return true ;
if ( V_190 ) {
V_5 = F_143 ( V_5 , V_11 , & V_71 , V_133 ) ;
if ( ! V_5 )
return true ;
}
if ( F_147 ( V_183 , V_5 , V_71 ) ) {
V_183 -> V_189 [ V_183 -> V_188 - 1 ] . V_11 += * V_11 ;
return false ;
}
F_4 ( V_5 ) ;
V_183 -> V_184 [ V_183 -> V_188 ] = V_5 ;
V_183 -> V_189 [ V_183 -> V_188 ] . V_11 = * V_11 ;
V_183 -> V_189 [ V_183 -> V_188 ] . V_71 = V_71 ;
V_183 -> V_188 ++ ;
return false ;
}
static bool F_149 ( struct V_5 * V_5 , unsigned int V_192 ,
unsigned int V_193 , unsigned int * V_80 ,
unsigned int * V_11 ,
struct V_182 * V_183 , bool V_190 ,
struct V_185 * V_133 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return true ;
if ( * V_80 >= V_193 ) {
* V_80 -= V_193 ;
return false ;
}
V_192 += * V_80 ;
V_193 -= * V_80 ;
* V_80 = 0 ;
do {
unsigned int V_194 = F_150 ( * V_11 , V_193 ) ;
if ( F_148 ( V_183 , V_2 , V_5 , & V_194 , V_192 ,
V_190 , V_133 ) )
return true ;
V_192 += V_194 ;
V_193 -= V_194 ;
* V_11 -= V_194 ;
} while ( * V_11 && V_193 );
return false ;
}
static bool F_151 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_71 , unsigned int * V_11 ,
struct V_182 * V_183 , struct V_185 * V_133 )
{
int V_195 ;
if ( F_149 ( F_152 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_66 - 1 ) ,
F_114 ( V_7 ) ,
V_71 , V_11 , V_183 ,
F_153 ( V_7 ) ,
V_133 , V_2 ) )
return true ;
for ( V_195 = 0 ; V_195 < F_27 ( V_7 ) -> V_90 ; V_195 ++ ) {
const T_6 * V_140 = & F_27 ( V_7 ) -> V_141 [ V_195 ] ;
if ( F_149 ( F_99 ( V_140 ) ,
V_140 -> V_144 , F_100 ( V_140 ) ,
V_71 , V_11 , V_183 , false , V_133 , V_2 ) )
return true ;
}
return false ;
}
int F_154 ( struct V_6 * V_7 , unsigned int V_71 ,
struct V_1 * V_2 , unsigned int V_196 ,
unsigned int V_20 )
{
struct V_197 V_189 [ V_191 ] ;
struct V_5 * V_184 [ V_191 ] ;
struct V_182 V_183 = {
. V_184 = V_184 ,
. V_189 = V_189 ,
. V_198 = V_191 ,
. V_20 = V_20 ,
. V_199 = & V_200 ,
. V_201 = F_142 ,
} ;
struct V_6 * V_178 ;
struct V_185 * V_133 = V_7 -> V_133 ;
int V_202 = 0 ;
if ( F_151 ( V_7 , V_2 , & V_71 , & V_196 , & V_183 , V_133 ) )
goto V_169;
else if ( ! V_196 )
goto V_169;
F_53 (skb, frag_iter) {
if ( ! V_196 )
break;
if ( F_151 ( V_178 , V_2 , & V_71 , & V_196 , & V_183 , V_133 ) )
break;
}
V_169:
if ( V_183 . V_188 ) {
F_155 ( V_133 ) ;
V_202 = F_156 ( V_2 , & V_183 ) ;
F_157 ( V_133 ) ;
}
return V_202 ;
}
int F_158 ( struct V_6 * V_7 , int V_71 , const void * V_203 , int V_11 )
{
int V_177 = F_114 ( V_7 ) ;
struct V_6 * V_178 ;
int V_79 , V_179 ;
if ( V_71 > ( int ) V_7 -> V_11 - V_11 )
goto V_180;
if ( ( V_179 = V_177 - V_71 ) > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
F_159 ( V_7 , V_71 , V_203 , V_179 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return 0 ;
V_71 += V_179 ;
V_203 += V_179 ;
}
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ ) {
T_6 * V_61 = & F_27 ( V_7 ) -> V_141 [ V_79 ] ;
int V_15 ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + F_100 ( V_61 ) ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
T_3 * V_139 ;
if ( V_179 > V_11 )
V_179 = V_11 ;
V_139 = F_98 ( F_99 ( V_61 ) ) ;
memcpy ( V_139 + V_61 -> V_144 + V_71 - V_177 ,
V_203 , V_179 ) ;
F_101 ( V_139 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return 0 ;
V_71 += V_179 ;
V_203 += V_179 ;
}
V_177 = V_15 ;
}
F_53 (skb, frag_iter) {
int V_15 ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + V_178 -> V_11 ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
if ( F_158 ( V_178 , V_71 - V_177 ,
V_203 , V_179 ) )
goto V_180;
if ( ( V_11 -= V_179 ) == 0 )
return 0 ;
V_71 += V_179 ;
V_203 += V_179 ;
}
V_177 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_180:
return - V_181 ;
}
T_7 F_160 ( const struct V_6 * V_7 , int V_71 ,
int V_11 , T_7 V_118 )
{
int V_177 = F_114 ( V_7 ) ;
int V_79 , V_179 = V_177 - V_71 ;
struct V_6 * V_178 ;
int V_204 = 0 ;
if ( V_179 > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
V_118 = F_161 ( V_7 -> V_13 + V_71 , V_179 , V_118 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return V_118 ;
V_71 += V_179 ;
V_204 = V_179 ;
}
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ ) {
int V_15 ;
T_6 * V_61 = & F_27 ( V_7 ) -> V_141 [ V_79 ] ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + F_100 ( V_61 ) ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
T_7 V_205 ;
T_3 * V_139 ;
if ( V_179 > V_11 )
V_179 = V_11 ;
V_139 = F_98 ( F_99 ( V_61 ) ) ;
V_205 = F_161 ( V_139 + V_61 -> V_144 +
V_71 - V_177 , V_179 , 0 ) ;
F_101 ( V_139 ) ;
V_118 = F_162 ( V_118 , V_205 , V_204 ) ;
if ( ! ( V_11 -= V_179 ) )
return V_118 ;
V_71 += V_179 ;
V_204 += V_179 ;
}
V_177 = V_15 ;
}
F_53 (skb, frag_iter) {
int V_15 ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + V_178 -> V_11 ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
T_7 V_205 ;
if ( V_179 > V_11 )
V_179 = V_11 ;
V_205 = F_160 ( V_178 , V_71 - V_177 ,
V_179 , 0 ) ;
V_118 = F_162 ( V_118 , V_205 , V_204 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return V_118 ;
V_71 += V_179 ;
V_204 += V_179 ;
}
V_177 = V_15 ;
}
F_118 ( V_11 ) ;
return V_118 ;
}
T_7 F_163 ( const struct V_6 * V_7 , int V_71 ,
T_3 * V_176 , int V_11 , T_7 V_118 )
{
int V_177 = F_114 ( V_7 ) ;
int V_79 , V_179 = V_177 - V_71 ;
struct V_6 * V_178 ;
int V_204 = 0 ;
if ( V_179 > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
V_118 = F_164 ( V_7 -> V_13 + V_71 , V_176 ,
V_179 , V_118 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return V_118 ;
V_71 += V_179 ;
V_176 += V_179 ;
V_204 = V_179 ;
}
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ ) {
int V_15 ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + F_100 ( & F_27 ( V_7 ) -> V_141 [ V_79 ] ) ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
T_7 V_205 ;
T_3 * V_139 ;
T_6 * V_61 = & F_27 ( V_7 ) -> V_141 [ V_79 ] ;
if ( V_179 > V_11 )
V_179 = V_11 ;
V_139 = F_98 ( F_99 ( V_61 ) ) ;
V_205 = F_164 ( V_139 +
V_61 -> V_144 +
V_71 - V_177 , V_176 ,
V_179 , 0 ) ;
F_101 ( V_139 ) ;
V_118 = F_162 ( V_118 , V_205 , V_204 ) ;
if ( ! ( V_11 -= V_179 ) )
return V_118 ;
V_71 += V_179 ;
V_176 += V_179 ;
V_204 += V_179 ;
}
V_177 = V_15 ;
}
F_53 (skb, frag_iter) {
T_7 V_205 ;
int V_15 ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + V_178 -> V_11 ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
V_205 = F_163 ( V_178 ,
V_71 - V_177 ,
V_176 , V_179 , 0 ) ;
V_118 = F_162 ( V_118 , V_205 , V_204 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return V_118 ;
V_71 += V_179 ;
V_176 += V_179 ;
V_204 += V_179 ;
}
V_177 = V_15 ;
}
F_118 ( V_11 ) ;
return V_118 ;
}
void F_165 ( const struct V_6 * V_7 , T_3 * V_176 )
{
T_7 V_118 ;
long V_206 ;
if ( V_7 -> V_121 == V_153 )
V_206 = F_166 ( V_7 ) ;
else
V_206 = F_114 ( V_7 ) ;
F_118 ( V_206 > F_114 ( V_7 ) ) ;
F_115 ( V_7 , V_176 , V_206 ) ;
V_118 = 0 ;
if ( V_206 != V_7 -> V_11 )
V_118 = F_163 ( V_7 , V_206 , V_176 + V_206 ,
V_7 -> V_11 - V_206 , 0 ) ;
if ( V_7 -> V_121 == V_153 ) {
long V_207 = V_206 + V_7 -> V_208 ;
* ( ( V_209 * ) ( V_176 + V_207 ) ) = F_167 ( V_118 ) ;
}
}
struct V_6 * F_168 ( struct V_210 * V_83 )
{
unsigned long V_20 ;
struct V_6 * V_211 ;
F_169 ( & V_83 -> V_212 , V_20 ) ;
V_211 = F_170 ( V_83 ) ;
F_171 ( & V_83 -> V_212 , V_20 ) ;
return V_211 ;
}
struct V_6 * F_172 ( struct V_210 * V_83 )
{
unsigned long V_20 ;
struct V_6 * V_211 ;
F_169 ( & V_83 -> V_212 , V_20 ) ;
V_211 = F_173 ( V_83 ) ;
F_171 ( & V_83 -> V_212 , V_20 ) ;
return V_211 ;
}
void F_174 ( struct V_210 * V_83 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_168 ( V_83 ) ) != NULL )
F_50 ( V_7 ) ;
}
void F_175 ( struct V_210 * V_83 , struct V_6 * V_213 )
{
unsigned long V_20 ;
F_169 ( & V_83 -> V_212 , V_20 ) ;
F_176 ( V_83 , V_213 ) ;
F_171 ( & V_83 -> V_212 , V_20 ) ;
}
void F_177 ( struct V_210 * V_83 , struct V_6 * V_213 )
{
unsigned long V_20 ;
F_169 ( & V_83 -> V_212 , V_20 ) ;
F_178 ( V_83 , V_213 ) ;
F_171 ( & V_83 -> V_212 , V_20 ) ;
}
void F_179 ( struct V_6 * V_7 , struct V_210 * V_83 )
{
unsigned long V_20 ;
F_169 ( & V_83 -> V_212 , V_20 ) ;
F_180 ( V_7 , V_83 ) ;
F_171 ( & V_83 -> V_212 , V_20 ) ;
}
void F_181 ( struct V_6 * V_107 , struct V_6 * V_213 , struct V_210 * V_83 )
{
unsigned long V_20 ;
F_169 ( & V_83 -> V_212 , V_20 ) ;
F_182 ( V_83 , V_107 , V_213 ) ;
F_171 ( & V_83 -> V_212 , V_20 ) ;
}
void F_183 ( struct V_6 * V_107 , struct V_6 * V_213 , struct V_210 * V_83 )
{
unsigned long V_20 ;
F_169 ( & V_83 -> V_212 , V_20 ) ;
F_184 ( V_213 , V_107 -> V_132 , V_107 , V_83 ) ;
F_171 ( & V_83 -> V_212 , V_20 ) ;
}
static inline void F_185 ( struct V_6 * V_7 ,
struct V_6 * V_214 ,
const T_8 V_11 , const int V_204 )
{
int V_79 ;
F_141 ( V_7 , V_11 , F_111 ( V_214 , V_204 - V_11 ) ,
V_204 - V_11 ) ;
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ )
F_27 ( V_214 ) -> V_141 [ V_79 ] = F_27 ( V_7 ) -> V_141 [ V_79 ] ;
F_27 ( V_214 ) -> V_90 = F_27 ( V_7 ) -> V_90 ;
F_27 ( V_7 ) -> V_90 = 0 ;
V_214 -> V_81 = V_7 -> V_81 ;
V_214 -> V_11 += V_214 -> V_81 ;
V_7 -> V_81 = 0 ;
V_7 -> V_11 = V_11 ;
F_137 ( V_7 , V_11 ) ;
}
static inline void F_186 ( struct V_6 * V_7 ,
struct V_6 * V_214 ,
const T_8 V_11 , int V_204 )
{
int V_79 , V_171 = 0 ;
const int V_167 = F_27 ( V_7 ) -> V_90 ;
F_27 ( V_7 ) -> V_90 = 0 ;
V_214 -> V_11 = V_214 -> V_81 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_81 = V_11 - V_204 ;
for ( V_79 = 0 ; V_79 < V_167 ; V_79 ++ ) {
int V_19 = F_100 ( & F_27 ( V_7 ) -> V_141 [ V_79 ] ) ;
if ( V_204 + V_19 > V_11 ) {
F_27 ( V_214 ) -> V_141 [ V_171 ] = F_27 ( V_7 ) -> V_141 [ V_79 ] ;
if ( V_204 < V_11 ) {
F_116 ( V_7 , V_79 ) ;
F_27 ( V_214 ) -> V_141 [ 0 ] . V_144 += V_11 - V_204 ;
F_140 ( & F_27 ( V_214 ) -> V_141 [ 0 ] , V_11 - V_204 ) ;
F_135 ( & F_27 ( V_7 ) -> V_141 [ V_79 ] , V_11 - V_204 ) ;
F_27 ( V_7 ) -> V_90 ++ ;
}
V_171 ++ ;
} else
F_27 ( V_7 ) -> V_90 ++ ;
V_204 += V_19 ;
}
F_27 ( V_214 ) -> V_90 = V_171 ;
}
void F_187 ( struct V_6 * V_7 , struct V_6 * V_214 , const T_8 V_11 )
{
int V_204 = F_114 ( V_7 ) ;
F_27 ( V_214 ) -> V_91 = F_27 ( V_7 ) -> V_91 & V_215 ;
if ( V_11 < V_204 )
F_185 ( V_7 , V_214 , V_11 , V_204 ) ;
else
F_186 ( V_7 , V_214 , V_11 , V_204 ) ;
}
static int F_188 ( struct V_6 * V_7 )
{
return F_121 ( V_7 ) && F_117 ( V_7 , 0 , 0 , V_55 ) ;
}
int F_189 ( struct V_6 * V_216 , struct V_6 * V_7 , int V_217 )
{
int V_203 , V_176 , V_218 , V_219 ;
struct V_220 * V_221 , * V_222 ;
F_118 ( V_217 > V_7 -> V_11 ) ;
F_118 ( F_114 ( V_7 ) ) ;
V_219 = V_217 ;
V_203 = 0 ;
V_176 = F_27 ( V_216 ) -> V_90 ;
V_221 = & F_27 ( V_7 ) -> V_141 [ V_203 ] ;
if ( ! V_176 ||
! F_190 ( V_216 , V_176 , F_99 ( V_221 ) ,
V_221 -> V_144 ) ) {
V_218 = - 1 ;
} else {
V_218 = V_176 - 1 ;
V_219 -= F_100 ( V_221 ) ;
if ( V_219 < 0 ) {
if ( F_188 ( V_7 ) ||
F_188 ( V_216 ) )
return 0 ;
V_221 = & F_27 ( V_7 ) -> V_141 [ V_203 ] ;
V_222 = & F_27 ( V_216 ) -> V_141 [ V_218 ] ;
F_191 ( V_222 , V_217 ) ;
F_140 ( V_221 , V_217 ) ;
V_221 -> V_144 += V_217 ;
goto V_223;
}
V_203 ++ ;
}
if ( ( V_217 == V_7 -> V_11 ) &&
( F_27 ( V_7 ) -> V_90 - V_203 ) > ( V_191 - V_176 ) )
return 0 ;
if ( F_188 ( V_7 ) || F_188 ( V_216 ) )
return 0 ;
while ( ( V_219 > 0 ) && ( V_203 < F_27 ( V_7 ) -> V_90 ) ) {
if ( V_176 == V_191 )
return 0 ;
V_221 = & F_27 ( V_7 ) -> V_141 [ V_203 ] ;
V_222 = & F_27 ( V_216 ) -> V_141 [ V_176 ] ;
if ( V_219 >= F_100 ( V_221 ) ) {
* V_222 = * V_221 ;
V_219 -= F_100 ( V_221 ) ;
V_203 ++ ;
V_176 ++ ;
} else {
F_192 ( V_221 ) ;
V_222 -> V_5 = V_221 -> V_5 ;
V_222 -> V_144 = V_221 -> V_144 ;
F_135 ( V_222 , V_219 ) ;
V_221 -> V_144 += V_219 ;
F_140 ( V_221 , V_219 ) ;
V_219 = 0 ;
V_176 ++ ;
break;
}
}
F_27 ( V_216 ) -> V_90 = V_176 ;
if ( V_218 >= 0 ) {
V_221 = & F_27 ( V_7 ) -> V_141 [ 0 ] ;
V_222 = & F_27 ( V_216 ) -> V_141 [ V_218 ] ;
F_191 ( V_222 , F_100 ( V_221 ) ) ;
F_193 ( V_221 ) ;
}
V_176 = 0 ;
while ( V_203 < F_27 ( V_7 ) -> V_90 )
F_27 ( V_7 ) -> V_141 [ V_176 ++ ] = F_27 ( V_7 ) -> V_141 [ V_203 ++ ] ;
F_27 ( V_7 ) -> V_90 = V_176 ;
F_118 ( V_219 > 0 && ! F_27 ( V_7 ) -> V_90 ) ;
V_223:
V_216 -> V_121 = V_153 ;
V_7 -> V_121 = V_153 ;
V_7 -> V_11 -= V_217 ;
V_7 -> V_81 -= V_217 ;
V_7 -> V_41 -= V_217 ;
V_216 -> V_11 += V_217 ;
V_216 -> V_81 += V_217 ;
V_216 -> V_41 += V_217 ;
return V_217 ;
}
void F_194 ( struct V_6 * V_7 , unsigned int V_203 ,
unsigned int V_176 , struct V_224 * V_225 )
{
V_225 -> V_226 = V_203 ;
V_225 -> V_227 = V_176 ;
V_225 -> V_228 = V_225 -> V_229 = V_7 ;
V_225 -> V_230 = V_225 -> V_231 = 0 ;
V_225 -> V_232 = NULL ;
}
unsigned int F_195 ( unsigned int V_233 , const T_3 * * V_13 ,
struct V_224 * V_225 )
{
unsigned int V_234 , V_235 = V_233 + V_225 -> V_226 ;
T_6 * V_61 ;
if ( F_36 ( V_235 >= V_225 -> V_227 ) )
return 0 ;
V_236:
V_234 = F_114 ( V_225 -> V_229 ) + V_225 -> V_231 ;
if ( V_235 < V_234 && ! V_225 -> V_232 ) {
* V_13 = V_225 -> V_229 -> V_13 + ( V_235 - V_225 -> V_231 ) ;
return V_234 - V_235 ;
}
if ( V_225 -> V_230 == 0 && ! V_225 -> V_232 )
V_225 -> V_231 += F_114 ( V_225 -> V_229 ) ;
while ( V_225 -> V_230 < F_27 ( V_225 -> V_229 ) -> V_90 ) {
V_61 = & F_27 ( V_225 -> V_229 ) -> V_141 [ V_225 -> V_230 ] ;
V_234 = F_100 ( V_61 ) + V_225 -> V_231 ;
if ( V_235 < V_234 ) {
if ( ! V_225 -> V_232 )
V_225 -> V_232 = F_98 ( F_99 ( V_61 ) ) ;
* V_13 = ( T_3 * ) V_225 -> V_232 + V_61 -> V_144 +
( V_235 - V_225 -> V_231 ) ;
return V_234 - V_235 ;
}
if ( V_225 -> V_232 ) {
F_101 ( V_225 -> V_232 ) ;
V_225 -> V_232 = NULL ;
}
V_225 -> V_230 ++ ;
V_225 -> V_231 += F_100 ( V_61 ) ;
}
if ( V_225 -> V_232 ) {
F_101 ( V_225 -> V_232 ) ;
V_225 -> V_232 = NULL ;
}
if ( V_225 -> V_228 == V_225 -> V_229 && F_60 ( V_225 -> V_228 ) ) {
V_225 -> V_229 = F_27 ( V_225 -> V_228 ) -> V_86 ;
V_225 -> V_230 = 0 ;
goto V_236;
} else if ( V_225 -> V_229 -> V_85 ) {
V_225 -> V_229 = V_225 -> V_229 -> V_85 ;
V_225 -> V_230 = 0 ;
goto V_236;
}
return 0 ;
}
void F_196 ( struct V_224 * V_225 )
{
if ( V_225 -> V_232 )
F_101 ( V_225 -> V_232 ) ;
}
static unsigned int F_197 ( unsigned int V_71 , const T_3 * * V_237 ,
struct V_238 * V_239 ,
struct V_240 * V_241 )
{
return F_195 ( V_71 , V_237 , F_198 ( V_241 ) ) ;
}
static void F_199 ( struct V_238 * V_239 , struct V_240 * V_241 )
{
F_196 ( F_198 ( V_241 ) ) ;
}
unsigned int F_200 ( struct V_6 * V_7 , unsigned int V_203 ,
unsigned int V_176 , struct V_238 * V_242 ,
struct V_240 * V_241 )
{
unsigned int V_202 ;
V_242 -> V_243 = F_197 ;
V_242 -> V_244 = F_199 ;
F_194 ( V_7 , V_203 , V_176 , F_198 ( V_241 ) ) ;
V_202 = F_201 ( V_242 , V_241 ) ;
return ( V_202 <= V_176 - V_203 ? V_202 : V_245 ) ;
}
int F_202 ( struct V_185 * V_133 , struct V_6 * V_7 ,
int (* F_203)( void * V_203 , char * V_176 , int V_71 ,
int V_11 , int V_246 , struct V_6 * V_7 ) ,
void * V_203 , int V_74 )
{
int V_247 = F_27 ( V_7 ) -> V_90 ;
int V_179 ;
int V_71 = 0 ;
int V_202 ;
struct V_186 * V_187 = & V_248 -> V_249 ;
do {
if ( V_247 >= V_191 )
return - V_250 ;
if ( ! F_145 ( V_133 , V_187 ) )
return - V_143 ;
V_179 = F_146 ( int , V_74 , V_187 -> V_19 - V_187 -> V_71 ) ;
V_202 = F_203 ( V_203 , F_41 ( V_187 -> V_5 ) + V_187 -> V_71 ,
V_71 , V_179 , 0 , V_7 ) ;
if ( V_202 < 0 )
return - V_181 ;
F_48 ( V_7 , V_247 , V_187 -> V_5 , V_187 -> V_71 ,
V_179 ) ;
V_247 ++ ;
V_187 -> V_71 += V_179 ;
F_4 ( V_187 -> V_5 ) ;
V_7 -> V_41 += V_179 ;
F_204 ( V_179 , & V_133 -> V_251 ) ;
V_7 -> V_11 += V_179 ;
V_7 -> V_81 += V_179 ;
V_71 += V_179 ;
V_74 -= V_179 ;
} while ( V_74 > 0 );
return 0 ;
}
unsigned char * F_205 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_118 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_118 ( V_7 -> V_11 < V_7 -> V_81 ) ;
F_206 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_207 ( struct V_6 * V_7 , T_9 V_252 )
{
struct V_6 * V_253 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_254 = F_27 ( V_7 ) -> V_86 ;
unsigned int V_255 = F_27 ( V_7 ) -> V_145 ;
unsigned int V_256 = V_7 -> V_13 - F_208 ( V_7 ) ;
unsigned int V_71 = V_256 ;
unsigned int V_257 = F_209 ( V_7 ) ;
unsigned int V_149 ;
unsigned int V_11 ;
int V_258 = ! ! ( V_252 & V_259 ) ;
int V_167 = F_27 ( V_7 ) -> V_90 ;
int V_163 = - V_143 ;
int V_79 = 0 ;
int V_204 ;
F_210 ( V_7 , V_256 ) ;
V_149 = F_93 ( V_7 ) ;
V_204 = F_114 ( V_7 ) ;
do {
struct V_6 * V_260 ;
T_6 * V_61 ;
int V_261 ;
int V_19 ;
V_11 = V_7 -> V_11 - V_71 ;
if ( V_11 > V_255 )
V_11 = V_255 ;
V_261 = F_114 ( V_7 ) - V_71 ;
if ( V_261 < 0 )
V_261 = 0 ;
if ( V_261 > V_11 || ! V_258 )
V_261 = V_11 ;
if ( ! V_261 && V_79 >= V_167 ) {
F_118 ( V_254 -> V_11 != V_11 ) ;
V_204 += V_11 ;
V_260 = F_103 ( V_254 , V_55 ) ;
V_254 = V_254 -> V_85 ;
if ( F_36 ( ! V_260 ) )
goto V_163;
V_261 = F_110 ( V_260 ) ;
if ( F_211 ( V_260 , V_256 + V_149 ) ) {
F_50 ( V_260 ) ;
goto V_163;
}
V_260 -> V_41 += F_110 ( V_260 ) - V_261 ;
F_63 ( V_260 ) ;
F_210 ( V_260 , V_256 ) ;
} else {
V_260 = F_14 ( V_261 + V_256 + V_149 ,
V_55 , F_108 ( V_7 ) ,
V_78 ) ;
if ( F_36 ( ! V_260 ) )
goto V_163;
F_46 ( V_260 , V_149 ) ;
F_212 ( V_260 , V_256 ) ;
}
if ( V_253 )
V_14 -> V_85 = V_260 ;
else
V_253 = V_260 ;
V_14 = V_260 ;
F_85 ( V_260 , V_7 ) ;
V_260 -> V_134 = V_7 -> V_134 ;
if ( V_260 -> V_121 == V_153 )
V_260 -> V_154 += F_93 ( V_260 ) - V_149 ;
F_213 ( V_260 ) ;
F_214 ( V_260 , V_7 -> V_134 ) ;
V_260 -> V_44 = ( V_260 -> V_109 +
F_215 ( V_7 ) ) ;
F_141 ( V_7 , - V_257 ,
V_260 -> V_13 - V_257 ,
V_256 + V_257 ) ;
if ( V_254 != F_27 ( V_7 ) -> V_86 )
continue;
if ( ! V_258 ) {
V_260 -> V_121 = V_262 ;
V_260 -> V_118 = F_163 ( V_7 , V_71 ,
F_111 ( V_260 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_61 = F_27 ( V_260 ) -> V_141 ;
F_141 ( V_7 , V_71 ,
F_111 ( V_260 , V_261 ) , V_261 ) ;
F_27 ( V_260 ) -> V_91 = F_27 ( V_7 ) -> V_91 & V_215 ;
while ( V_204 < V_71 + V_11 && V_79 < V_167 ) {
* V_61 = F_27 ( V_7 ) -> V_141 [ V_79 ] ;
F_192 ( V_61 ) ;
V_19 = F_100 ( V_61 ) ;
if ( V_204 < V_71 ) {
V_61 -> V_144 += V_71 - V_204 ;
F_140 ( V_61 , V_71 - V_204 ) ;
}
F_27 ( V_260 ) -> V_90 ++ ;
if ( V_204 + V_19 <= V_71 + V_11 ) {
V_79 ++ ;
V_204 += V_19 ;
} else {
F_140 ( V_61 , V_204 + V_19 - ( V_71 + V_11 ) ) ;
goto V_263;
}
V_61 ++ ;
}
if ( V_204 < V_71 + V_11 ) {
struct V_6 * V_264 = V_254 ;
F_118 ( V_204 + V_254 -> V_11 != V_71 + V_11 ) ;
V_204 += V_254 -> V_11 ;
V_254 = V_254 -> V_85 ;
if ( V_264 -> V_85 ) {
V_264 = F_103 ( V_264 , V_55 ) ;
if ( ! V_264 )
goto V_163;
} else
F_54 ( V_264 ) ;
F_216 ( V_260 ) ;
F_27 ( V_260 ) -> V_86 = V_264 ;
}
V_263:
V_260 -> V_81 = V_11 - V_261 ;
V_260 -> V_11 += V_260 -> V_81 ;
V_260 -> V_41 += V_260 -> V_81 ;
} while ( ( V_71 += V_11 ) < V_7 -> V_11 );
return V_253 ;
V_163:
while ( ( V_7 = V_253 ) ) {
V_253 = V_7 -> V_85 ;
F_50 ( V_7 ) ;
}
return F_217 ( V_163 ) ;
}
int F_218 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_265 = * V_12 ;
struct V_6 * V_260 ;
struct V_32 * V_266 = F_27 ( V_7 ) ;
struct V_32 * V_267 = F_27 ( V_265 ) ;
unsigned int V_149 ;
unsigned int V_11 = F_219 ( V_7 ) ;
unsigned int V_71 = F_220 ( V_7 ) ;
unsigned int V_268 = F_114 ( V_7 ) ;
unsigned int V_269 ;
if ( V_265 -> V_11 + V_11 >= 65536 )
return - V_270 ;
if ( V_267 -> V_86 )
goto V_218;
else if ( V_268 <= V_71 ) {
T_6 * V_61 ;
T_6 * V_271 ;
int V_79 = V_266 -> V_90 ;
int V_90 = V_267 -> V_90 + V_79 ;
V_71 -= V_268 ;
if ( V_90 > V_191 )
return - V_270 ;
V_267 -> V_90 = V_90 ;
V_266 -> V_90 = 0 ;
V_61 = V_267 -> V_141 + V_90 ;
V_271 = V_266 -> V_141 + V_79 ;
do {
* -- V_61 = * -- V_271 ;
} while ( -- V_79 );
V_61 -> V_144 += V_71 ;
F_140 ( V_61 , V_71 ) ;
V_269 = V_7 -> V_41 -
F_23 ( F_110 ( V_7 ) ) ;
V_7 -> V_41 -= V_7 -> V_81 ;
V_7 -> V_11 -= V_7 -> V_81 ;
V_7 -> V_81 = 0 ;
F_221 ( V_7 ) -> free = V_272 ;
goto V_169;
} else if ( V_7 -> V_56 ) {
int V_90 = V_267 -> V_90 ;
T_6 * V_61 = V_267 -> V_141 + V_90 ;
struct V_5 * V_5 = F_45 ( V_7 -> V_12 ) ;
unsigned int V_273 = V_268 - V_71 ;
unsigned int V_274 ;
if ( V_90 + 1 + V_266 -> V_90 > V_191 )
return - V_270 ;
V_274 = V_7 -> V_13 -
( unsigned char * ) F_41 ( V_5 ) +
V_71 ;
V_267 -> V_90 = V_90 + 1 + V_266 -> V_90 ;
V_61 -> V_5 . V_265 = V_5 ;
V_61 -> V_144 = V_274 ;
F_135 ( V_61 , V_273 ) ;
memcpy ( V_61 + 1 , V_266 -> V_141 , sizeof( * V_61 ) * V_266 -> V_90 ) ;
V_269 = V_7 -> V_41 - F_18 ( sizeof( struct V_6 ) ) ;
F_221 ( V_7 ) -> free = V_275 ;
goto V_169;
} else if ( F_219 ( V_265 ) != V_267 -> V_145 )
return - V_270 ;
V_149 = F_93 ( V_265 ) ;
V_260 = F_222 ( V_149 + F_220 ( V_265 ) , V_55 ) ;
if ( F_36 ( ! V_260 ) )
return - V_143 ;
F_85 ( V_260 , V_265 ) ;
V_260 -> V_134 = V_265 -> V_134 ;
F_46 ( V_260 , V_149 ) ;
F_212 ( V_260 , F_220 ( V_265 ) ) ;
F_223 ( V_260 , F_208 ( V_265 ) - V_265 -> V_13 ) ;
F_214 ( V_260 , F_224 ( V_265 ) ) ;
F_225 ( V_260 , F_226 ( V_265 ) ) ;
F_227 ( V_265 , F_220 ( V_265 ) ) ;
memcpy ( F_208 ( V_260 ) , F_208 ( V_265 ) ,
V_265 -> V_13 - F_208 ( V_265 ) ) ;
F_27 ( V_260 ) -> V_86 = V_265 ;
F_27 ( V_260 ) -> V_145 = V_267 -> V_145 ;
V_267 -> V_145 = 0 ;
F_228 ( V_265 ) ;
F_221 ( V_260 ) -> V_276 = V_265 ;
V_260 -> V_81 += V_265 -> V_11 ;
V_260 -> V_41 += V_265 -> V_41 ;
V_260 -> V_11 += V_265 -> V_11 ;
* V_12 = V_260 ;
V_260 -> V_85 = V_265 -> V_85 ;
V_265 -> V_85 = NULL ;
V_265 = V_260 ;
V_218:
V_269 = V_7 -> V_41 ;
if ( V_71 > V_268 ) {
unsigned int V_172 = V_71 - V_268 ;
V_266 -> V_141 [ 0 ] . V_144 += V_172 ;
F_140 ( & V_266 -> V_141 [ 0 ] , V_172 ) ;
V_7 -> V_81 -= V_172 ;
V_7 -> V_11 -= V_172 ;
V_71 = V_268 ;
}
F_227 ( V_7 , V_71 ) ;
F_221 ( V_265 ) -> V_276 -> V_85 = V_7 ;
F_221 ( V_265 ) -> V_276 = V_7 ;
F_228 ( V_7 ) ;
V_169:
F_221 ( V_265 ) -> V_277 ++ ;
V_265 -> V_81 += V_11 ;
V_265 -> V_41 += V_269 ;
V_265 -> V_11 += V_11 ;
F_221 ( V_7 ) -> V_278 = 1 ;
return 0 ;
}
void T_10 F_229 ( void )
{
V_36 = F_230 ( L_3 ,
sizeof( struct V_6 ) ,
0 ,
V_279 | V_280 ,
NULL ) ;
V_35 = F_230 ( L_4 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_4 ) ,
0 ,
V_279 | V_280 ,
NULL ) ;
}
static int
F_231 ( struct V_6 * V_7 , struct V_281 * V_258 , int V_71 , int V_11 )
{
int V_177 = F_114 ( V_7 ) ;
int V_79 , V_179 = V_177 - V_71 ;
struct V_6 * V_178 ;
int V_282 = 0 ;
if ( V_179 > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
F_232 ( V_258 , V_7 -> V_13 + V_71 , V_179 ) ;
V_282 ++ ;
if ( ( V_11 -= V_179 ) == 0 )
return V_282 ;
V_71 += V_179 ;
}
for ( V_79 = 0 ; V_79 < F_27 ( V_7 ) -> V_90 ; V_79 ++ ) {
int V_15 ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + F_100 ( & F_27 ( V_7 ) -> V_141 [ V_79 ] ) ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
T_6 * V_61 = & F_27 ( V_7 ) -> V_141 [ V_79 ] ;
if ( V_179 > V_11 )
V_179 = V_11 ;
F_233 ( & V_258 [ V_282 ] , F_99 ( V_61 ) , V_179 ,
V_61 -> V_144 + V_71 - V_177 ) ;
V_282 ++ ;
if ( ! ( V_11 -= V_179 ) )
return V_282 ;
V_71 += V_179 ;
}
V_177 = V_15 ;
}
F_53 (skb, frag_iter) {
int V_15 ;
F_67 ( V_177 > V_71 + V_11 ) ;
V_15 = V_177 + V_178 -> V_11 ;
if ( ( V_179 = V_15 - V_71 ) > 0 ) {
if ( V_179 > V_11 )
V_179 = V_11 ;
V_282 += F_231 ( V_178 , V_258 + V_282 , V_71 - V_177 ,
V_179 ) ;
if ( ( V_11 -= V_179 ) == 0 )
return V_282 ;
V_71 += V_179 ;
}
V_177 = V_15 ;
}
F_118 ( V_11 ) ;
return V_282 ;
}
int F_234 ( struct V_6 * V_7 , struct V_281 * V_258 , int V_71 , int V_11 )
{
int V_283 = F_231 ( V_7 , V_258 , V_71 , V_11 ) ;
F_235 ( & V_258 [ V_283 - 1 ] ) ;
return V_283 ;
}
int F_236 ( struct V_6 * V_7 , int V_284 , struct V_6 * * V_285 )
{
int V_286 ;
int V_282 ;
struct V_6 * V_214 , * * V_287 ;
if ( ( F_121 ( V_7 ) || F_27 ( V_7 ) -> V_90 ) &&
F_138 ( V_7 , F_237 ( V_7 ) - F_114 ( V_7 ) ) == NULL )
return - V_143 ;
if ( ! F_60 ( V_7 ) ) {
if ( F_126 ( V_7 ) < V_284 &&
F_117 ( V_7 , 0 , V_284 - F_126 ( V_7 ) + 128 , V_55 ) )
return - V_143 ;
* V_285 = V_7 ;
return 1 ;
}
V_282 = 1 ;
V_287 = & F_27 ( V_7 ) -> V_86 ;
V_286 = 0 ;
while ( ( V_214 = * V_287 ) != NULL ) {
int V_151 = 0 ;
if ( F_119 ( V_214 ) )
V_286 = 1 ;
if ( V_214 -> V_85 == NULL && V_284 ) {
if ( F_27 ( V_214 ) -> V_90 ||
F_60 ( V_214 ) ||
F_126 ( V_214 ) < V_284 )
V_151 = V_284 + 128 ;
}
if ( V_286 ||
F_121 ( V_214 ) ||
V_151 ||
F_27 ( V_214 ) -> V_90 ||
F_60 ( V_214 ) ) {
struct V_6 * V_155 ;
if ( V_151 == 0 )
V_155 = F_109 ( V_214 , V_55 ) ;
else
V_155 = F_124 ( V_214 ,
F_93 ( V_214 ) ,
V_151 ,
V_55 ) ;
if ( F_36 ( V_155 == NULL ) )
return - V_143 ;
if ( V_214 -> V_133 )
F_238 ( V_155 , V_214 -> V_133 ) ;
V_155 -> V_85 = V_214 -> V_85 ;
* V_287 = V_155 ;
F_50 ( V_214 ) ;
V_214 = V_155 ;
}
V_282 ++ ;
* V_285 = V_214 ;
V_287 = & V_214 -> V_85 ;
}
return V_282 ;
}
static void F_239 ( struct V_6 * V_7 )
{
struct V_185 * V_133 = V_7 -> V_133 ;
F_240 ( V_7 -> V_41 , & V_133 -> V_288 ) ;
}
int F_241 ( struct V_185 * V_133 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_39 ( & V_133 -> V_288 ) + V_7 -> V_41 >=
( unsigned int ) V_133 -> V_289 )
return - V_143 ;
F_242 ( V_7 ) ;
V_7 -> V_133 = V_133 ;
V_7 -> V_99 = F_239 ;
F_204 ( V_7 -> V_41 , & V_133 -> V_288 ) ;
F_243 ( V_7 ) ;
F_177 ( & V_133 -> V_290 , V_7 ) ;
if ( ! F_244 ( V_133 , V_291 ) )
V_133 -> V_292 ( V_133 , V_11 ) ;
return 0 ;
}
void F_245 ( struct V_6 * V_293 ,
struct V_294 * V_295 )
{
struct V_185 * V_133 = V_293 -> V_133 ;
struct V_296 * V_297 ;
struct V_6 * V_7 ;
int V_163 ;
if ( ! V_133 )
return;
V_7 = F_103 ( V_293 , V_55 ) ;
if ( ! V_7 )
return;
if ( V_295 ) {
* F_246 ( V_7 ) =
* V_295 ;
} else {
V_7 -> V_108 = F_247 () ;
}
V_297 = F_248 ( V_7 ) ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_298 . V_299 = V_300 ;
V_297 -> V_298 . V_301 = V_302 ;
V_163 = F_241 ( V_133 , V_7 ) ;
if ( V_163 )
F_50 ( V_7 ) ;
}
void F_249 ( struct V_6 * V_7 , bool V_303 )
{
struct V_185 * V_133 = V_7 -> V_133 ;
struct V_296 * V_297 ;
int V_163 ;
V_7 -> V_304 = 1 ;
V_7 -> V_305 = V_303 ;
V_297 = F_248 ( V_7 ) ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_298 . V_299 = V_300 ;
V_297 -> V_298 . V_301 = V_306 ;
V_163 = F_241 ( V_133 , V_7 ) ;
if ( V_163 )
F_50 ( V_7 ) ;
}
bool F_250 ( struct V_6 * V_7 , T_11 V_177 , T_11 V_80 )
{
if ( F_36 ( V_177 > F_114 ( V_7 ) ) ||
F_36 ( ( int ) V_177 + V_80 > F_114 ( V_7 ) - 2 ) ) {
F_251 ( L_5 ,
V_177 , V_80 , F_114 ( V_7 ) ) ;
return false ;
}
V_7 -> V_121 = V_153 ;
V_7 -> V_154 = F_93 ( V_7 ) + V_177 ;
V_7 -> V_208 = V_80 ;
return true ;
}
void F_252 ( const struct V_6 * V_7 )
{
F_251 ( L_6 ,
V_7 -> V_16 -> V_17 ) ;
}
void F_253 ( struct V_6 * V_7 , bool V_307 )
{
if ( V_307 ) {
F_63 ( V_7 ) ;
F_30 ( V_36 , V_7 ) ;
} else {
F_78 ( V_7 ) ;
}
}
bool F_254 ( struct V_6 * V_176 , struct V_6 * V_203 ,
bool * V_308 , int * V_269 )
{
int V_79 , V_156 , V_11 = V_203 -> V_11 ;
* V_308 = false ;
if ( F_121 ( V_176 ) )
return false ;
if ( V_11 <= F_126 ( V_176 ) ) {
F_118 ( F_112 ( V_203 , 0 , F_111 ( V_176 , V_11 ) , V_11 ) ) ;
* V_269 = 0 ;
return true ;
}
if ( F_60 ( V_176 ) || F_60 ( V_203 ) )
return false ;
if ( F_114 ( V_203 ) != 0 ) {
struct V_5 * V_5 ;
unsigned int V_71 ;
if ( F_27 ( V_176 ) -> V_90 +
F_27 ( V_203 ) -> V_90 >= V_191 )
return false ;
if ( F_153 ( V_203 ) )
return false ;
V_156 = V_203 -> V_41 - F_18 ( sizeof( struct V_6 ) ) ;
V_5 = F_45 ( V_203 -> V_12 ) ;
V_71 = V_203 -> V_13 - ( unsigned char * ) F_41 ( V_5 ) ;
F_48 ( V_176 , F_27 ( V_176 ) -> V_90 ,
V_5 , V_71 , F_114 ( V_203 ) ) ;
* V_308 = true ;
} else {
if ( F_27 ( V_176 ) -> V_90 +
F_27 ( V_203 ) -> V_90 > V_191 )
return false ;
V_156 = V_203 -> V_41 - F_23 ( F_110 ( V_203 ) ) ;
}
F_255 ( V_156 < V_11 ) ;
memcpy ( F_27 ( V_176 ) -> V_141 + F_27 ( V_176 ) -> V_90 ,
F_27 ( V_203 ) -> V_141 ,
F_27 ( V_203 ) -> V_90 * sizeof( T_6 ) ) ;
F_27 ( V_176 ) -> V_90 += F_27 ( V_203 ) -> V_90 ;
if ( ! F_121 ( V_203 ) )
F_27 ( V_203 ) -> V_90 = 0 ;
for ( V_79 = 0 ; V_79 < F_27 ( V_203 ) -> V_90 ; V_79 ++ )
F_116 ( V_203 , V_79 ) ;
V_176 -> V_41 += V_156 ;
V_176 -> V_11 += V_11 ;
V_176 -> V_81 += V_11 ;
* V_269 = V_156 ;
return true ;
}
