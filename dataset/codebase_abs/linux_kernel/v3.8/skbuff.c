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
static void F_6 ( struct V_6 * V_7 , int V_8 , void * V_9 )
{
F_7 ( L_1 ,
V_10 , V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_2 ) ;
F_8 () ;
}
static void F_9 ( struct V_6 * V_7 , int V_8 , void * V_9 )
{
F_7 ( L_1 ,
V_10 , V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_2 ) ;
F_8 () ;
}
void * F_10 ( T_1 V_18 , T_2 V_19 , int V_20 , unsigned long V_21 ,
bool * V_22 )
{
void * V_23 ;
bool V_24 = false ;
V_23 = F_11 ( V_18 ,
V_19 | V_25 | V_26 ,
V_20 ) ;
if ( V_23 || ! ( F_12 ( V_19 ) ) )
goto V_27;
V_24 = true ;
V_23 = F_11 ( V_18 , V_19 , V_20 ) ;
V_27:
if ( V_22 )
* V_22 = V_24 ;
return V_23 ;
}
struct V_6 * F_13 ( unsigned int V_18 , T_2 V_28 ,
int V_19 , int V_20 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_6 * V_7 ;
T_3 * V_13 ;
bool V_22 ;
V_30 = ( V_19 & V_33 )
? V_34 : V_35 ;
if ( F_14 () && ( V_19 & V_36 ) )
V_28 |= V_37 ;
V_7 = F_15 ( V_30 , V_28 & ~ V_38 , V_20 ) ;
if ( ! V_7 )
goto V_27;
F_16 ( V_7 ) ;
V_18 = F_17 ( V_18 ) ;
V_18 += F_17 ( sizeof( struct V_31 ) ) ;
V_13 = F_18 ( V_18 , V_28 , V_20 , & V_22 ) ;
if ( ! V_13 )
goto V_39;
V_18 = F_19 ( F_20 ( V_13 ) ) ;
F_16 ( V_13 + V_18 ) ;
memset ( V_7 , 0 , F_21 ( struct V_6 , V_14 ) ) ;
V_7 -> V_40 = F_22 ( V_18 ) ;
V_7 -> V_22 = V_22 ;
F_23 ( & V_7 -> V_41 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_24 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_18 ;
#ifdef F_25
V_7 -> V_42 = ~ 0U ;
#endif
V_32 = F_26 ( V_7 ) ;
memset ( V_32 , 0 , F_21 ( struct V_31 , V_43 ) ) ;
F_23 ( & V_32 -> V_43 , 1 ) ;
F_27 ( V_32 -> V_44 ) ;
if ( V_19 & V_33 ) {
struct V_6 * V_45 = V_7 + 1 ;
T_4 * V_46 = ( T_4 * ) ( V_45 + 1 ) ;
F_28 ( V_45 , V_47 ) ;
F_28 ( V_45 , V_48 ) ;
V_7 -> V_49 = V_50 ;
F_23 ( V_46 , 1 ) ;
V_45 -> V_49 = V_51 ;
V_45 -> V_22 = V_22 ;
}
V_27:
return V_7 ;
V_39:
F_29 ( V_30 , V_7 ) ;
V_7 = NULL ;
goto V_27;
}
struct V_6 * F_30 ( void * V_13 , unsigned int V_52 )
{
struct V_31 * V_32 ;
struct V_6 * V_7 ;
unsigned int V_18 = V_52 ? : F_20 ( V_13 ) ;
V_7 = F_31 ( V_35 , V_53 ) ;
if ( ! V_7 )
return NULL ;
V_18 -= F_17 ( sizeof( struct V_31 ) ) ;
memset ( V_7 , 0 , F_21 ( struct V_6 , V_14 ) ) ;
V_7 -> V_40 = F_22 ( V_18 ) ;
V_7 -> V_54 = V_52 != 0 ;
F_23 ( & V_7 -> V_41 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_24 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_18 ;
#ifdef F_25
V_7 -> V_42 = ~ 0U ;
#endif
V_32 = F_26 ( V_7 ) ;
memset ( V_32 , 0 , F_21 ( struct V_31 , V_43 ) ) ;
F_23 ( & V_32 -> V_43 , 1 ) ;
F_27 ( V_32 -> V_44 ) ;
return V_7 ;
}
static void * F_32 ( unsigned int V_55 , T_2 V_28 )
{
struct V_56 * V_57 ;
void * V_13 = NULL ;
int V_58 ;
unsigned long V_19 ;
F_33 ( V_19 ) ;
V_57 = & F_34 ( V_56 ) ;
if ( F_35 ( ! V_57 -> V_59 . V_5 ) ) {
V_60:
for ( V_58 = V_61 ; ; ) {
T_2 V_62 = V_28 ;
if ( V_58 )
V_62 |= V_63 | V_26 ;
V_57 -> V_59 . V_5 = F_36 ( V_62 , V_58 ) ;
if ( F_37 ( V_57 -> V_59 . V_5 ) )
break;
if ( -- V_58 < 0 )
goto V_15;
}
V_57 -> V_59 . V_18 = V_64 << V_58 ;
V_65:
F_23 ( & V_57 -> V_59 . V_5 -> V_66 , V_67 ) ;
V_57 -> V_68 = V_67 ;
V_57 -> V_59 . V_69 = 0 ;
}
if ( V_57 -> V_59 . V_69 + V_55 > V_57 -> V_59 . V_18 ) {
if ( ( F_38 ( & V_57 -> V_59 . V_5 -> V_66 ) == V_57 -> V_68 ) ||
F_39 ( V_57 -> V_68 , & V_57 -> V_59 . V_5 -> V_66 ) )
goto V_65;
goto V_60;
}
V_13 = F_40 ( V_57 -> V_59 . V_5 ) + V_57 -> V_59 . V_69 ;
V_57 -> V_59 . V_69 += V_55 ;
V_57 -> V_68 -- ;
V_15:
F_41 ( V_19 ) ;
return V_13 ;
}
void * F_42 ( unsigned int V_55 )
{
return F_32 ( V_55 , V_53 | V_70 ) ;
}
struct V_6 * F_43 ( struct V_71 * V_16 ,
unsigned int V_72 , T_2 V_28 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_55 = F_17 ( V_72 + V_73 ) +
F_17 ( sizeof( struct V_31 ) ) ;
if ( V_55 <= V_64 && ! ( V_28 & ( V_74 | V_75 ) ) ) {
void * V_13 ;
if ( F_14 () )
V_28 |= V_37 ;
V_13 = F_32 ( V_55 , V_28 ) ;
if ( F_37 ( V_13 ) ) {
V_7 = F_30 ( V_13 , V_55 ) ;
if ( F_35 ( ! V_7 ) )
F_2 ( F_44 ( V_13 ) ) ;
}
} else {
V_7 = F_13 ( V_72 + V_73 , V_28 ,
V_36 , V_76 ) ;
}
if ( F_37 ( V_7 ) ) {
F_45 ( V_7 , V_73 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_46 ( struct V_6 * V_7 , int V_77 , struct V_5 * V_5 , int V_78 ,
int V_18 , unsigned int V_40 )
{
F_47 ( V_7 , V_77 , V_5 , V_78 , V_18 ) ;
V_7 -> V_11 += V_18 ;
V_7 -> V_79 += V_18 ;
V_7 -> V_40 += V_40 ;
}
static void F_48 ( struct V_6 * * V_80 )
{
struct V_6 * V_81 = * V_80 ;
* V_80 = NULL ;
do {
struct V_6 * V_82 = V_81 ;
V_81 = V_81 -> V_83 ;
F_49 ( V_82 ) ;
} while ( V_81 );
}
static inline void F_50 ( struct V_6 * V_7 )
{
F_48 ( & F_26 ( V_7 ) -> V_84 ) ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_6 * V_81 ;
F_52 (skb, list)
F_53 ( V_81 ) ;
}
static void F_54 ( struct V_6 * V_7 )
{
if ( V_7 -> V_54 )
F_2 ( F_44 ( V_7 -> V_12 ) ) ;
else
F_55 ( V_7 -> V_12 ) ;
}
static void F_56 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_85 ||
! F_57 ( V_7 -> V_86 ? ( 1 << V_87 ) + 1 : 1 ,
& F_26 ( V_7 ) -> V_43 ) ) {
if ( F_26 ( V_7 ) -> V_88 ) {
int V_77 ;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ )
F_58 ( V_7 , V_77 ) ;
}
if ( F_26 ( V_7 ) -> V_89 & V_90 ) {
struct V_91 * V_92 ;
V_92 = F_26 ( V_7 ) -> V_44 ;
if ( V_92 -> V_93 )
V_92 -> V_93 ( V_92 , true ) ;
}
if ( F_59 ( V_7 ) )
F_50 ( V_7 ) ;
F_54 ( V_7 ) ;
}
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_6 * V_94 ;
T_4 * V_46 ;
switch ( V_7 -> V_49 ) {
case V_51 :
F_29 ( V_35 , V_7 ) ;
break;
case V_50 :
V_46 = ( T_4 * ) ( V_7 + 2 ) ;
if ( F_61 ( V_46 ) )
F_29 ( V_34 , V_7 ) ;
break;
case V_95 :
V_46 = ( T_4 * ) ( V_7 + 1 ) ;
V_94 = V_7 - 1 ;
V_7 -> V_49 = V_51 ;
if ( F_61 ( V_46 ) )
F_29 ( V_34 , V_94 ) ;
break;
}
}
static void F_62 ( struct V_6 * V_7 )
{
F_63 ( V_7 ) ;
#ifdef F_64
F_65 ( V_7 -> V_96 ) ;
#endif
if ( V_7 -> V_97 ) {
F_66 ( F_67 () ) ;
V_7 -> V_97 ( V_7 ) ;
}
#if F_68 ( V_98 )
F_69 ( V_7 -> V_99 ) ;
#endif
#ifdef F_70
F_71 ( V_7 -> V_100 ) ;
#endif
#ifdef F_72
F_73 ( V_7 -> V_101 ) ;
#endif
#ifdef F_74
V_7 -> V_102 = 0 ;
#ifdef F_75
V_7 -> V_103 = 0 ;
#endif
#endif
}
static void F_76 ( struct V_6 * V_7 )
{
F_62 ( V_7 ) ;
F_56 ( V_7 ) ;
}
void F_77 ( struct V_6 * V_7 )
{
F_76 ( V_7 ) ;
F_60 ( V_7 ) ;
}
void F_49 ( struct V_6 * V_7 )
{
if ( F_35 ( ! V_7 ) )
return;
if ( F_37 ( F_38 ( & V_7 -> V_41 ) == 1 ) )
F_78 () ;
else if ( F_37 ( ! F_61 ( & V_7 -> V_41 ) ) )
return;
F_79 ( V_7 , F_80 ( 0 ) ) ;
F_77 ( V_7 ) ;
}
void F_81 ( struct V_6 * V_7 )
{
if ( F_26 ( V_7 ) -> V_89 & V_90 ) {
struct V_91 * V_92 ;
V_92 = F_26 ( V_7 ) -> V_44 ;
if ( V_92 -> V_93 )
V_92 -> V_93 ( V_92 , false ) ;
F_26 ( V_7 ) -> V_89 &= ~ V_90 ;
}
}
void F_82 ( struct V_6 * V_7 )
{
if ( F_35 ( ! V_7 ) )
return;
if ( F_37 ( F_38 ( & V_7 -> V_41 ) == 1 ) )
F_78 () ;
else if ( F_37 ( ! F_61 ( & V_7 -> V_41 ) ) )
return;
F_83 ( V_7 ) ;
F_77 ( V_7 ) ;
}
static void F_84 ( struct V_6 * V_104 , const struct V_6 * V_105 )
{
V_104 -> V_106 = V_105 -> V_106 ;
V_104 -> V_16 = V_105 -> V_16 ;
V_104 -> V_107 = V_105 -> V_107 ;
V_104 -> V_108 = V_105 -> V_108 ;
V_104 -> V_42 = V_105 -> V_42 ;
V_104 -> V_109 = V_105 -> V_109 ;
V_104 -> V_110 = V_105 -> V_110 ;
F_85 ( V_104 , V_105 ) ;
V_104 -> V_111 = V_105 -> V_111 ;
V_104 -> V_112 = V_105 -> V_112 ;
V_104 -> V_113 = V_105 -> V_113 ;
V_104 -> V_114 = V_105 -> V_114 ;
V_104 -> V_115 = V_105 -> V_115 ;
#ifdef F_64
V_104 -> V_96 = F_86 ( V_105 -> V_96 ) ;
#endif
memcpy ( V_104 -> V_116 , V_105 -> V_116 , sizeof( V_105 -> V_116 ) ) ;
V_104 -> V_117 = V_105 -> V_117 ;
V_104 -> V_118 = V_105 -> V_118 ;
V_104 -> V_119 = V_105 -> V_119 ;
V_104 -> V_120 = V_105 -> V_120 ;
F_87 ( V_104 , V_105 ) ;
V_104 -> V_121 = V_105 -> V_121 ;
#if F_68 ( V_122 )
V_104 -> V_123 = V_105 -> V_123 ;
#endif
V_104 -> V_22 = V_105 -> V_22 ;
V_104 -> V_124 = V_105 -> V_124 ;
V_104 -> V_125 = V_105 -> V_125 ;
V_104 -> V_126 = V_105 -> V_126 ;
F_88 ( V_104 , V_105 ) ;
#if F_68 ( V_127 )
V_104 -> V_128 = V_105 -> V_128 ;
#endif
#ifdef F_74
V_104 -> V_102 = V_105 -> V_102 ;
#ifdef F_75
V_104 -> V_103 = V_105 -> V_103 ;
#endif
#endif
V_104 -> V_129 = V_105 -> V_129 ;
F_89 ( V_104 , V_105 ) ;
}
static struct V_6 * F_90 ( struct V_6 * V_130 , struct V_6 * V_7 )
{
#define F_91 ( T_5 ) n->x = skb->x
V_130 -> V_83 = V_130 -> V_131 = NULL ;
V_130 -> V_132 = NULL ;
F_84 ( V_130 , V_7 ) ;
F_91 ( V_11 ) ;
F_91 ( V_79 ) ;
F_91 ( V_133 ) ;
V_130 -> V_134 = V_7 -> V_86 ? F_92 ( V_7 ) : V_7 -> V_134 ;
V_130 -> V_85 = 1 ;
V_130 -> V_86 = 0 ;
V_130 -> V_97 = NULL ;
F_91 ( V_14 ) ;
F_91 ( V_15 ) ;
F_91 ( V_12 ) ;
F_91 ( V_54 ) ;
F_91 ( V_13 ) ;
F_91 ( V_40 ) ;
F_23 ( & V_130 -> V_41 , 1 ) ;
F_93 ( & ( F_26 ( V_7 ) -> V_43 ) ) ;
V_7 -> V_85 = 1 ;
return V_130 ;
#undef F_91
}
struct V_6 * F_94 ( struct V_6 * V_135 , struct V_6 * V_136 )
{
F_76 ( V_135 ) ;
return F_90 ( V_135 , V_136 ) ;
}
int F_95 ( struct V_6 * V_7 , T_2 V_28 )
{
int V_77 ;
int V_137 = F_26 ( V_7 ) -> V_88 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_91 * V_92 = F_26 ( V_7 ) -> V_44 ;
for ( V_77 = 0 ; V_77 < V_137 ; V_77 ++ ) {
T_3 * V_138 ;
T_6 * V_139 = & F_26 ( V_7 ) -> V_140 [ V_77 ] ;
V_5 = F_96 ( V_28 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_83 = (struct V_5 * ) V_12 -> V_141 ;
F_2 ( V_12 ) ;
V_12 = V_83 ;
}
return - V_142 ;
}
V_138 = F_97 ( F_98 ( V_139 ) ) ;
memcpy ( F_40 ( V_5 ) ,
V_138 + V_139 -> V_143 , F_99 ( V_139 ) ) ;
F_100 ( V_138 ) ;
V_5 -> V_141 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_77 = 0 ; V_77 < V_137 ; V_77 ++ )
F_58 ( V_7 , V_77 ) ;
V_92 -> V_93 ( V_92 , false ) ;
for ( V_77 = V_137 - 1 ; V_77 >= 0 ; V_77 -- ) {
F_101 ( V_7 , V_77 , V_12 , 0 ,
F_26 ( V_7 ) -> V_140 [ V_77 ] . V_18 ) ;
V_12 = (struct V_5 * ) V_12 -> V_141 ;
}
F_26 ( V_7 ) -> V_89 &= ~ V_90 ;
return 0 ;
}
struct V_6 * F_102 ( struct V_6 * V_7 , T_2 V_28 )
{
struct V_6 * V_130 ;
if ( F_103 ( V_7 , V_28 ) )
return NULL ;
V_130 = V_7 + 1 ;
if ( V_7 -> V_49 == V_50 &&
V_130 -> V_49 == V_51 ) {
T_4 * V_46 = ( T_4 * ) ( V_130 + 1 ) ;
V_130 -> V_49 = V_95 ;
F_93 ( V_46 ) ;
} else {
if ( F_104 ( V_7 ) )
V_28 |= V_37 ;
V_130 = F_31 ( V_35 , V_28 ) ;
if ( ! V_130 )
return NULL ;
F_28 ( V_130 , V_47 ) ;
F_28 ( V_130 , V_48 ) ;
V_130 -> V_49 = V_51 ;
}
return F_90 ( V_130 , V_7 ) ;
}
static void F_105 ( struct V_6 * V_104 , const struct V_6 * V_105 )
{
#ifndef F_25
unsigned long V_69 = V_104 -> V_13 - V_105 -> V_13 ;
#endif
F_84 ( V_104 , V_105 ) ;
#ifndef F_25
V_104 -> V_107 += V_69 ;
V_104 -> V_108 += V_69 ;
if ( F_106 ( V_104 ) )
V_104 -> V_42 += V_69 ;
V_104 -> V_109 += V_69 ;
V_104 -> V_110 += V_69 ;
#endif
F_26 ( V_104 ) -> V_144 = F_26 ( V_105 ) -> V_144 ;
F_26 ( V_104 ) -> V_145 = F_26 ( V_105 ) -> V_145 ;
F_26 ( V_104 ) -> V_146 = F_26 ( V_105 ) -> V_146 ;
}
static inline int F_107 ( const struct V_6 * V_7 )
{
if ( F_104 ( V_7 ) )
return V_36 ;
return 0 ;
}
struct V_6 * F_108 ( const struct V_6 * V_7 , T_2 V_28 )
{
int V_147 = F_92 ( V_7 ) ;
unsigned int V_18 = F_109 ( V_7 ) + V_7 -> V_79 ;
struct V_6 * V_130 = F_13 ( V_18 , V_28 ,
F_107 ( V_7 ) , V_76 ) ;
if ( ! V_130 )
return NULL ;
F_45 ( V_130 , V_147 ) ;
F_110 ( V_130 , V_7 -> V_11 ) ;
if ( F_111 ( V_7 , - V_147 , V_130 -> V_12 , V_147 + V_7 -> V_11 ) )
F_8 () ;
F_105 ( V_130 , V_7 ) ;
return V_130 ;
}
struct V_6 * F_112 ( struct V_6 * V_7 , int V_148 , T_2 V_28 )
{
unsigned int V_18 = F_113 ( V_7 ) + V_148 ;
struct V_6 * V_130 = F_13 ( V_18 , V_28 ,
F_107 ( V_7 ) , V_76 ) ;
if ( ! V_130 )
goto V_27;
F_45 ( V_130 , V_148 ) ;
F_110 ( V_130 , F_113 ( V_7 ) ) ;
F_114 ( V_7 , V_130 -> V_13 , V_130 -> V_11 ) ;
V_130 -> V_40 += V_7 -> V_79 ;
V_130 -> V_79 = V_7 -> V_79 ;
V_130 -> V_11 = V_7 -> V_11 ;
if ( F_26 ( V_7 ) -> V_88 ) {
int V_77 ;
if ( F_103 ( V_7 , V_28 ) ) {
F_49 ( V_130 ) ;
V_130 = NULL ;
goto V_27;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
F_26 ( V_130 ) -> V_140 [ V_77 ] = F_26 ( V_7 ) -> V_140 [ V_77 ] ;
F_115 ( V_7 , V_77 ) ;
}
F_26 ( V_130 ) -> V_88 = V_77 ;
}
if ( F_59 ( V_7 ) ) {
F_26 ( V_130 ) -> V_84 = F_26 ( V_7 ) -> V_84 ;
F_51 ( V_130 ) ;
}
F_105 ( V_130 , V_7 ) ;
V_27:
return V_130 ;
}
int F_116 ( struct V_6 * V_7 , int V_149 , int V_150 ,
T_2 V_28 )
{
int V_77 ;
T_3 * V_13 ;
int V_18 = V_149 + F_109 ( V_7 ) + V_150 ;
long V_78 ;
F_117 ( V_149 < 0 ) ;
if ( F_118 ( V_7 ) )
F_8 () ;
V_18 = F_17 ( V_18 ) ;
if ( F_104 ( V_7 ) )
V_28 |= V_37 ;
V_13 = F_18 ( V_18 + F_17 ( sizeof( struct V_31 ) ) ,
V_28 , V_76 , NULL ) ;
if ( ! V_13 )
goto V_39;
V_18 = F_19 ( F_20 ( V_13 ) ) ;
memcpy ( V_13 + V_149 , V_7 -> V_12 , F_119 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_31 * ) ( V_13 + V_18 ) ,
F_26 ( V_7 ) ,
F_21 ( struct V_31 , V_140 [ F_26 ( V_7 ) -> V_88 ] ) ) ;
if ( F_120 ( V_7 ) ) {
if ( F_103 ( V_7 , V_28 ) )
goto V_151;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ )
F_115 ( V_7 , V_77 ) ;
if ( F_59 ( V_7 ) )
F_51 ( V_7 ) ;
F_56 ( V_7 ) ;
} else {
F_54 ( V_7 ) ;
}
V_78 = ( V_13 + V_149 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_54 = 0 ;
V_7 -> V_13 += V_78 ;
#ifdef F_25
V_7 -> V_15 = V_18 ;
V_78 = V_149 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_78 ;
V_7 -> V_107 += V_78 ;
V_7 -> V_108 += V_78 ;
if ( F_106 ( V_7 ) )
V_7 -> V_42 += V_78 ;
V_7 -> V_109 += V_78 ;
V_7 -> V_110 += V_78 ;
if ( V_7 -> V_120 == V_152 )
V_7 -> V_153 += V_149 ;
V_7 -> V_85 = 0 ;
V_7 -> V_134 = 0 ;
V_7 -> V_86 = 0 ;
F_23 ( & F_26 ( V_7 ) -> V_43 , 1 ) ;
return 0 ;
V_151:
F_55 ( V_13 ) ;
V_39:
return - V_142 ;
}
struct V_6 * F_121 ( struct V_6 * V_7 , unsigned int V_148 )
{
struct V_6 * V_154 ;
int V_155 = V_148 - F_92 ( V_7 ) ;
if ( V_155 <= 0 )
V_154 = F_122 ( V_7 , V_53 ) ;
else {
V_154 = F_102 ( V_7 , V_53 ) ;
if ( V_154 && F_116 ( V_154 , F_17 ( V_155 ) , 0 ,
V_53 ) ) {
F_49 ( V_154 ) ;
V_154 = NULL ;
}
}
return V_154 ;
}
struct V_6 * F_123 ( const struct V_6 * V_7 ,
int V_156 , int V_157 ,
T_2 V_28 )
{
struct V_6 * V_130 = F_13 ( V_156 + V_7 -> V_11 + V_157 ,
V_28 , F_107 ( V_7 ) ,
V_76 ) ;
int V_158 = F_92 ( V_7 ) ;
int V_159 , V_160 ;
int V_78 ;
if ( ! V_130 )
return NULL ;
F_45 ( V_130 , V_156 ) ;
F_110 ( V_130 , V_7 -> V_11 ) ;
V_159 = V_158 ;
V_160 = 0 ;
if ( V_156 <= V_159 )
V_159 = V_156 ;
else
V_160 = V_156 - V_159 ;
if ( F_111 ( V_7 , - V_159 , V_130 -> V_12 + V_160 ,
V_7 -> V_11 + V_159 ) )
F_8 () ;
F_105 ( V_130 , V_7 ) ;
V_78 = V_156 - V_158 ;
if ( V_130 -> V_120 == V_152 )
V_130 -> V_153 += V_78 ;
#ifdef F_25
V_130 -> V_107 += V_78 ;
V_130 -> V_108 += V_78 ;
if ( F_106 ( V_7 ) )
V_130 -> V_42 += V_78 ;
V_130 -> V_109 += V_78 ;
V_130 -> V_110 += V_78 ;
#endif
return V_130 ;
}
int F_124 ( struct V_6 * V_7 , int V_161 )
{
int V_162 ;
int V_150 ;
if ( ! F_120 ( V_7 ) && F_125 ( V_7 ) >= V_161 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_161 ) ;
return 0 ;
}
V_150 = V_7 -> V_79 + V_161 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_37 ( F_120 ( V_7 ) || V_150 > 0 ) ) {
V_162 = F_116 ( V_7 , 0 , V_150 , V_53 ) ;
if ( F_35 ( V_162 ) )
goto V_163;
}
V_162 = F_126 ( V_7 ) ;
if ( F_35 ( V_162 ) )
goto V_163;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_161 ) ;
return 0 ;
V_163:
F_49 ( V_7 ) ;
return V_162 ;
}
unsigned char * F_110 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_164 = F_119 ( V_7 ) ;
F_127 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_35 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_80 ( 0 ) ) ;
return V_164 ;
}
unsigned char * F_128 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_35 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_80 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_129 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_130 ( V_7 , V_11 ) ;
}
void F_131 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_132 ( V_7 , V_11 ) ;
}
int F_133 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_165 ;
struct V_6 * V_59 ;
int V_69 = F_113 ( V_7 ) ;
int V_166 = F_26 ( V_7 ) -> V_88 ;
int V_77 ;
int V_162 ;
if ( F_120 ( V_7 ) &&
F_35 ( ( V_162 = F_116 ( V_7 , 0 , 0 , V_53 ) ) ) )
return V_162 ;
V_77 = 0 ;
if ( V_69 >= V_11 )
goto V_167;
for (; V_77 < V_166 ; V_77 ++ ) {
int V_15 = V_69 + F_99 ( & F_26 ( V_7 ) -> V_140 [ V_77 ] ) ;
if ( V_15 < V_11 ) {
V_69 = V_15 ;
continue;
}
F_134 ( & F_26 ( V_7 ) -> V_140 [ V_77 ++ ] , V_11 - V_69 ) ;
V_167:
F_26 ( V_7 ) -> V_88 = V_77 ;
for (; V_77 < V_166 ; V_77 ++ )
F_58 ( V_7 , V_77 ) ;
if ( F_59 ( V_7 ) )
F_50 ( V_7 ) ;
goto V_168;
}
for ( V_165 = & F_26 ( V_7 ) -> V_84 ; ( V_59 = * V_165 ) ;
V_165 = & V_59 -> V_83 ) {
int V_15 = V_69 + V_59 -> V_11 ;
if ( F_118 ( V_59 ) ) {
struct V_6 * V_169 ;
V_169 = F_102 ( V_59 , V_53 ) ;
if ( F_35 ( ! V_169 ) )
return - V_142 ;
V_169 -> V_83 = V_59 -> V_83 ;
F_82 ( V_59 ) ;
V_59 = V_169 ;
* V_165 = V_59 ;
}
if ( V_15 < V_11 ) {
V_69 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_35 ( ( V_162 = F_135 ( V_59 , V_11 - V_69 ) ) ) )
return V_162 ;
if ( V_59 -> V_83 )
F_48 ( & V_59 -> V_83 ) ;
break;
}
V_168:
if ( V_11 > F_113 ( V_7 ) ) {
V_7 -> V_79 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_79 = 0 ;
F_136 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_137 ( struct V_6 * V_7 , int V_155 )
{
int V_77 , V_170 , V_171 = ( V_7 -> V_14 + V_155 ) - V_7 -> V_15 ;
if ( V_171 > 0 || F_120 ( V_7 ) ) {
if ( F_116 ( V_7 , 0 , V_171 > 0 ? V_171 + 128 : 0 ,
V_53 ) )
return NULL ;
}
if ( F_111 ( V_7 , F_113 ( V_7 ) , F_119 ( V_7 ) , V_155 ) )
F_8 () ;
if ( ! F_59 ( V_7 ) )
goto V_172;
V_171 = V_155 ;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_18 = F_99 ( & F_26 ( V_7 ) -> V_140 [ V_77 ] ) ;
if ( V_18 >= V_171 )
goto V_172;
V_171 -= V_18 ;
}
if ( V_171 ) {
struct V_6 * V_81 = F_26 ( V_7 ) -> V_84 ;
struct V_6 * V_173 = NULL ;
struct V_6 * V_174 = NULL ;
do {
F_117 ( ! V_81 ) ;
if ( V_81 -> V_11 <= V_171 ) {
V_171 -= V_81 -> V_11 ;
V_81 = V_81 -> V_83 ;
V_174 = V_81 ;
} else {
if ( F_118 ( V_81 ) ) {
V_173 = F_102 ( V_81 , V_53 ) ;
if ( ! V_173 )
return NULL ;
V_174 = V_81 -> V_83 ;
V_81 = V_173 ;
} else {
V_174 = V_81 ;
}
if ( ! F_138 ( V_81 , V_171 ) ) {
F_49 ( V_173 ) ;
return NULL ;
}
break;
}
} while ( V_171 );
while ( ( V_81 = F_26 ( V_7 ) -> V_84 ) != V_174 ) {
F_26 ( V_7 ) -> V_84 = V_81 -> V_83 ;
F_49 ( V_81 ) ;
}
if ( V_173 ) {
V_173 -> V_83 = V_81 ;
F_26 ( V_7 ) -> V_84 = V_173 ;
}
}
V_172:
V_171 = V_155 ;
V_170 = 0 ;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_18 = F_99 ( & F_26 ( V_7 ) -> V_140 [ V_77 ] ) ;
if ( V_18 <= V_171 ) {
F_58 ( V_7 , V_77 ) ;
V_171 -= V_18 ;
} else {
F_26 ( V_7 ) -> V_140 [ V_170 ] = F_26 ( V_7 ) -> V_140 [ V_77 ] ;
if ( V_171 ) {
F_26 ( V_7 ) -> V_140 [ V_170 ] . V_143 += V_171 ;
F_139 ( & F_26 ( V_7 ) -> V_140 [ V_170 ] , V_171 ) ;
V_171 = 0 ;
}
V_170 ++ ;
}
}
F_26 ( V_7 ) -> V_88 = V_170 ;
V_7 -> V_14 += V_155 ;
V_7 -> V_79 -= V_155 ;
return F_119 ( V_7 ) ;
}
int F_111 ( const struct V_6 * V_7 , int V_69 , void * V_175 , int V_11 )
{
int V_176 = F_113 ( V_7 ) ;
struct V_6 * V_177 ;
int V_77 , V_178 ;
if ( V_69 > ( int ) V_7 -> V_11 - V_11 )
goto V_179;
if ( ( V_178 = V_176 - V_69 ) > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
F_140 ( V_7 , V_69 , V_175 , V_178 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return 0 ;
V_69 += V_178 ;
V_175 += V_178 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_15 ;
T_6 * V_139 = & F_26 ( V_7 ) -> V_140 [ V_77 ] ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + F_99 ( V_139 ) ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
T_3 * V_138 ;
if ( V_178 > V_11 )
V_178 = V_11 ;
V_138 = F_97 ( F_98 ( V_139 ) ) ;
memcpy ( V_175 ,
V_138 + V_139 -> V_143 + V_69 - V_176 ,
V_178 ) ;
F_100 ( V_138 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return 0 ;
V_69 += V_178 ;
V_175 += V_178 ;
}
V_176 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + V_177 -> V_11 ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
if ( F_111 ( V_177 , V_69 - V_176 , V_175 , V_178 ) )
goto V_179;
if ( ( V_11 -= V_178 ) == 0 )
return 0 ;
V_69 += V_178 ;
V_175 += V_178 ;
}
V_176 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_179:
return - V_180 ;
}
static void F_141 ( struct V_181 * V_182 , unsigned int V_77 )
{
F_2 ( V_182 -> V_183 [ V_77 ] ) ;
}
static struct V_5 * F_142 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_69 ,
struct V_184 * V_132 )
{
struct V_185 * V_186 = F_143 ( V_132 ) ;
if ( ! F_144 ( V_132 , V_186 ) )
return NULL ;
* V_11 = F_145 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_40 ( V_186 -> V_5 ) + V_186 -> V_69 ,
F_40 ( V_5 ) + * V_69 , * V_11 ) ;
* V_69 = V_186 -> V_69 ;
V_186 -> V_69 += * V_11 ;
return V_186 -> V_5 ;
}
static bool F_146 ( const struct V_181 * V_182 ,
struct V_5 * V_5 ,
unsigned int V_69 )
{
return V_182 -> V_187 &&
V_182 -> V_183 [ V_182 -> V_187 - 1 ] == V_5 &&
( V_182 -> V_188 [ V_182 -> V_187 - 1 ] . V_69 +
V_182 -> V_188 [ V_182 -> V_187 - 1 ] . V_11 == V_69 ) ;
}
static bool F_147 ( struct V_181 * V_182 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_69 ,
bool V_189 ,
struct V_184 * V_132 )
{
if ( F_35 ( V_182 -> V_187 == V_190 ) )
return true ;
if ( V_189 ) {
V_5 = F_142 ( V_5 , V_11 , & V_69 , V_132 ) ;
if ( ! V_5 )
return true ;
}
if ( F_146 ( V_182 , V_5 , V_69 ) ) {
V_182 -> V_188 [ V_182 -> V_187 - 1 ] . V_11 += * V_11 ;
return false ;
}
F_4 ( V_5 ) ;
V_182 -> V_183 [ V_182 -> V_187 ] = V_5 ;
V_182 -> V_188 [ V_182 -> V_187 ] . V_11 = * V_11 ;
V_182 -> V_188 [ V_182 -> V_187 ] . V_69 = V_69 ;
V_182 -> V_187 ++ ;
return false ;
}
static bool F_148 ( struct V_5 * V_5 , unsigned int V_191 ,
unsigned int V_192 , unsigned int * V_78 ,
unsigned int * V_11 ,
struct V_181 * V_182 , bool V_189 ,
struct V_184 * V_132 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return true ;
if ( * V_78 >= V_192 ) {
* V_78 -= V_192 ;
return false ;
}
V_191 += * V_78 ;
V_192 -= * V_78 ;
* V_78 = 0 ;
do {
unsigned int V_193 = F_149 ( * V_11 , V_192 ) ;
if ( F_147 ( V_182 , V_2 , V_5 , & V_193 , V_191 ,
V_189 , V_132 ) )
return true ;
V_191 += V_193 ;
V_192 -= V_193 ;
* V_11 -= V_193 ;
} while ( * V_11 && V_192 );
return false ;
}
static bool F_150 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_69 , unsigned int * V_11 ,
struct V_181 * V_182 , struct V_184 * V_132 )
{
int V_194 ;
if ( F_148 ( F_151 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_64 - 1 ) ,
F_113 ( V_7 ) ,
V_69 , V_11 , V_182 ,
F_152 ( V_7 ) ,
V_132 , V_2 ) )
return true ;
for ( V_194 = 0 ; V_194 < F_26 ( V_7 ) -> V_88 ; V_194 ++ ) {
const T_6 * V_139 = & F_26 ( V_7 ) -> V_140 [ V_194 ] ;
if ( F_148 ( F_98 ( V_139 ) ,
V_139 -> V_143 , F_99 ( V_139 ) ,
V_69 , V_11 , V_182 , false , V_132 , V_2 ) )
return true ;
}
return false ;
}
int F_153 ( struct V_6 * V_7 , unsigned int V_69 ,
struct V_1 * V_2 , unsigned int V_195 ,
unsigned int V_19 )
{
struct V_196 V_188 [ V_190 ] ;
struct V_5 * V_183 [ V_190 ] ;
struct V_181 V_182 = {
. V_183 = V_183 ,
. V_188 = V_188 ,
. V_197 = V_190 ,
. V_19 = V_19 ,
. V_198 = & V_199 ,
. V_200 = F_141 ,
} ;
struct V_6 * V_177 ;
struct V_184 * V_132 = V_7 -> V_132 ;
int V_201 = 0 ;
if ( F_150 ( V_7 , V_2 , & V_69 , & V_195 , & V_182 , V_132 ) )
goto V_168;
else if ( ! V_195 )
goto V_168;
F_52 (skb, frag_iter) {
if ( ! V_195 )
break;
if ( F_150 ( V_177 , V_2 , & V_69 , & V_195 , & V_182 , V_132 ) )
break;
}
V_168:
if ( V_182 . V_187 ) {
F_154 ( V_132 ) ;
V_201 = F_155 ( V_2 , & V_182 ) ;
F_156 ( V_132 ) ;
}
return V_201 ;
}
int F_157 ( struct V_6 * V_7 , int V_69 , const void * V_202 , int V_11 )
{
int V_176 = F_113 ( V_7 ) ;
struct V_6 * V_177 ;
int V_77 , V_178 ;
if ( V_69 > ( int ) V_7 -> V_11 - V_11 )
goto V_179;
if ( ( V_178 = V_176 - V_69 ) > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
F_158 ( V_7 , V_69 , V_202 , V_178 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return 0 ;
V_69 += V_178 ;
V_202 += V_178 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
T_6 * V_59 = & F_26 ( V_7 ) -> V_140 [ V_77 ] ;
int V_15 ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + F_99 ( V_59 ) ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
T_3 * V_138 ;
if ( V_178 > V_11 )
V_178 = V_11 ;
V_138 = F_97 ( F_98 ( V_59 ) ) ;
memcpy ( V_138 + V_59 -> V_143 + V_69 - V_176 ,
V_202 , V_178 ) ;
F_100 ( V_138 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return 0 ;
V_69 += V_178 ;
V_202 += V_178 ;
}
V_176 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + V_177 -> V_11 ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
if ( F_157 ( V_177 , V_69 - V_176 ,
V_202 , V_178 ) )
goto V_179;
if ( ( V_11 -= V_178 ) == 0 )
return 0 ;
V_69 += V_178 ;
V_202 += V_178 ;
}
V_176 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_179:
return - V_180 ;
}
T_7 F_159 ( const struct V_6 * V_7 , int V_69 ,
int V_11 , T_7 V_117 )
{
int V_176 = F_113 ( V_7 ) ;
int V_77 , V_178 = V_176 - V_69 ;
struct V_6 * V_177 ;
int V_203 = 0 ;
if ( V_178 > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
V_117 = F_160 ( V_7 -> V_13 + V_69 , V_178 , V_117 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return V_117 ;
V_69 += V_178 ;
V_203 = V_178 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_15 ;
T_6 * V_59 = & F_26 ( V_7 ) -> V_140 [ V_77 ] ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + F_99 ( V_59 ) ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
T_7 V_204 ;
T_3 * V_138 ;
if ( V_178 > V_11 )
V_178 = V_11 ;
V_138 = F_97 ( F_98 ( V_59 ) ) ;
V_204 = F_160 ( V_138 + V_59 -> V_143 +
V_69 - V_176 , V_178 , 0 ) ;
F_100 ( V_138 ) ;
V_117 = F_161 ( V_117 , V_204 , V_203 ) ;
if ( ! ( V_11 -= V_178 ) )
return V_117 ;
V_69 += V_178 ;
V_203 += V_178 ;
}
V_176 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + V_177 -> V_11 ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
T_7 V_204 ;
if ( V_178 > V_11 )
V_178 = V_11 ;
V_204 = F_159 ( V_177 , V_69 - V_176 ,
V_178 , 0 ) ;
V_117 = F_161 ( V_117 , V_204 , V_203 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return V_117 ;
V_69 += V_178 ;
V_203 += V_178 ;
}
V_176 = V_15 ;
}
F_117 ( V_11 ) ;
return V_117 ;
}
T_7 F_162 ( const struct V_6 * V_7 , int V_69 ,
T_3 * V_175 , int V_11 , T_7 V_117 )
{
int V_176 = F_113 ( V_7 ) ;
int V_77 , V_178 = V_176 - V_69 ;
struct V_6 * V_177 ;
int V_203 = 0 ;
if ( V_178 > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
V_117 = F_163 ( V_7 -> V_13 + V_69 , V_175 ,
V_178 , V_117 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return V_117 ;
V_69 += V_178 ;
V_175 += V_178 ;
V_203 = V_178 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_15 ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + F_99 ( & F_26 ( V_7 ) -> V_140 [ V_77 ] ) ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
T_7 V_204 ;
T_3 * V_138 ;
T_6 * V_59 = & F_26 ( V_7 ) -> V_140 [ V_77 ] ;
if ( V_178 > V_11 )
V_178 = V_11 ;
V_138 = F_97 ( F_98 ( V_59 ) ) ;
V_204 = F_163 ( V_138 +
V_59 -> V_143 +
V_69 - V_176 , V_175 ,
V_178 , 0 ) ;
F_100 ( V_138 ) ;
V_117 = F_161 ( V_117 , V_204 , V_203 ) ;
if ( ! ( V_11 -= V_178 ) )
return V_117 ;
V_69 += V_178 ;
V_175 += V_178 ;
V_203 += V_178 ;
}
V_176 = V_15 ;
}
F_52 (skb, frag_iter) {
T_7 V_204 ;
int V_15 ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + V_177 -> V_11 ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
V_204 = F_162 ( V_177 ,
V_69 - V_176 ,
V_175 , V_178 , 0 ) ;
V_117 = F_161 ( V_117 , V_204 , V_203 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return V_117 ;
V_69 += V_178 ;
V_175 += V_178 ;
V_203 += V_178 ;
}
V_176 = V_15 ;
}
F_117 ( V_11 ) ;
return V_117 ;
}
void F_164 ( const struct V_6 * V_7 , T_3 * V_175 )
{
T_7 V_117 ;
long V_205 ;
if ( V_7 -> V_120 == V_152 )
V_205 = F_165 ( V_7 ) ;
else
V_205 = F_113 ( V_7 ) ;
F_117 ( V_205 > F_113 ( V_7 ) ) ;
F_114 ( V_7 , V_175 , V_205 ) ;
V_117 = 0 ;
if ( V_205 != V_7 -> V_11 )
V_117 = F_162 ( V_7 , V_205 , V_175 + V_205 ,
V_7 -> V_11 - V_205 , 0 ) ;
if ( V_7 -> V_120 == V_152 ) {
long V_206 = V_205 + V_7 -> V_207 ;
* ( ( V_208 * ) ( V_175 + V_206 ) ) = F_166 ( V_117 ) ;
}
}
struct V_6 * F_167 ( struct V_209 * V_81 )
{
unsigned long V_19 ;
struct V_6 * V_210 ;
F_168 ( & V_81 -> V_211 , V_19 ) ;
V_210 = F_169 ( V_81 ) ;
F_170 ( & V_81 -> V_211 , V_19 ) ;
return V_210 ;
}
struct V_6 * F_171 ( struct V_209 * V_81 )
{
unsigned long V_19 ;
struct V_6 * V_210 ;
F_168 ( & V_81 -> V_211 , V_19 ) ;
V_210 = F_172 ( V_81 ) ;
F_170 ( & V_81 -> V_211 , V_19 ) ;
return V_210 ;
}
void F_173 ( struct V_209 * V_81 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_167 ( V_81 ) ) != NULL )
F_49 ( V_7 ) ;
}
void F_174 ( struct V_209 * V_81 , struct V_6 * V_212 )
{
unsigned long V_19 ;
F_168 ( & V_81 -> V_211 , V_19 ) ;
F_175 ( V_81 , V_212 ) ;
F_170 ( & V_81 -> V_211 , V_19 ) ;
}
void F_176 ( struct V_209 * V_81 , struct V_6 * V_212 )
{
unsigned long V_19 ;
F_168 ( & V_81 -> V_211 , V_19 ) ;
F_177 ( V_81 , V_212 ) ;
F_170 ( & V_81 -> V_211 , V_19 ) ;
}
void F_178 ( struct V_6 * V_7 , struct V_209 * V_81 )
{
unsigned long V_19 ;
F_168 ( & V_81 -> V_211 , V_19 ) ;
F_179 ( V_7 , V_81 ) ;
F_170 ( & V_81 -> V_211 , V_19 ) ;
}
void F_180 ( struct V_6 * V_105 , struct V_6 * V_212 , struct V_209 * V_81 )
{
unsigned long V_19 ;
F_168 ( & V_81 -> V_211 , V_19 ) ;
F_181 ( V_81 , V_105 , V_212 ) ;
F_170 ( & V_81 -> V_211 , V_19 ) ;
}
void F_182 ( struct V_6 * V_105 , struct V_6 * V_212 , struct V_209 * V_81 )
{
unsigned long V_19 ;
F_168 ( & V_81 -> V_211 , V_19 ) ;
F_183 ( V_212 , V_105 -> V_131 , V_105 , V_81 ) ;
F_170 ( & V_81 -> V_211 , V_19 ) ;
}
static inline void F_184 ( struct V_6 * V_7 ,
struct V_6 * V_213 ,
const T_8 V_11 , const int V_203 )
{
int V_77 ;
F_140 ( V_7 , V_11 , F_110 ( V_213 , V_203 - V_11 ) ,
V_203 - V_11 ) ;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ )
F_26 ( V_213 ) -> V_140 [ V_77 ] = F_26 ( V_7 ) -> V_140 [ V_77 ] ;
F_26 ( V_213 ) -> V_88 = F_26 ( V_7 ) -> V_88 ;
F_26 ( V_7 ) -> V_88 = 0 ;
V_213 -> V_79 = V_7 -> V_79 ;
V_213 -> V_11 += V_213 -> V_79 ;
V_7 -> V_79 = 0 ;
V_7 -> V_11 = V_11 ;
F_136 ( V_7 , V_11 ) ;
}
static inline void F_185 ( struct V_6 * V_7 ,
struct V_6 * V_213 ,
const T_8 V_11 , int V_203 )
{
int V_77 , V_170 = 0 ;
const int V_166 = F_26 ( V_7 ) -> V_88 ;
F_26 ( V_7 ) -> V_88 = 0 ;
V_213 -> V_11 = V_213 -> V_79 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_79 = V_11 - V_203 ;
for ( V_77 = 0 ; V_77 < V_166 ; V_77 ++ ) {
int V_18 = F_99 ( & F_26 ( V_7 ) -> V_140 [ V_77 ] ) ;
if ( V_203 + V_18 > V_11 ) {
F_26 ( V_213 ) -> V_140 [ V_170 ] = F_26 ( V_7 ) -> V_140 [ V_77 ] ;
if ( V_203 < V_11 ) {
F_115 ( V_7 , V_77 ) ;
F_26 ( V_213 ) -> V_140 [ 0 ] . V_143 += V_11 - V_203 ;
F_139 ( & F_26 ( V_213 ) -> V_140 [ 0 ] , V_11 - V_203 ) ;
F_134 ( & F_26 ( V_7 ) -> V_140 [ V_77 ] , V_11 - V_203 ) ;
F_26 ( V_7 ) -> V_88 ++ ;
}
V_170 ++ ;
} else
F_26 ( V_7 ) -> V_88 ++ ;
V_203 += V_18 ;
}
F_26 ( V_213 ) -> V_88 = V_170 ;
}
void F_186 ( struct V_6 * V_7 , struct V_6 * V_213 , const T_8 V_11 )
{
int V_203 = F_113 ( V_7 ) ;
if ( V_11 < V_203 )
F_184 ( V_7 , V_213 , V_11 , V_203 ) ;
else
F_185 ( V_7 , V_213 , V_11 , V_203 ) ;
}
static int F_187 ( struct V_6 * V_7 )
{
return F_120 ( V_7 ) && F_116 ( V_7 , 0 , 0 , V_53 ) ;
}
int F_188 ( struct V_6 * V_214 , struct V_6 * V_7 , int V_215 )
{
int V_202 , V_175 , V_216 , V_217 ;
struct V_218 * V_219 , * V_220 ;
F_117 ( V_215 > V_7 -> V_11 ) ;
F_117 ( F_113 ( V_7 ) ) ;
V_217 = V_215 ;
V_202 = 0 ;
V_175 = F_26 ( V_214 ) -> V_88 ;
V_219 = & F_26 ( V_7 ) -> V_140 [ V_202 ] ;
if ( ! V_175 ||
! F_189 ( V_214 , V_175 , F_98 ( V_219 ) ,
V_219 -> V_143 ) ) {
V_216 = - 1 ;
} else {
V_216 = V_175 - 1 ;
V_217 -= F_99 ( V_219 ) ;
if ( V_217 < 0 ) {
if ( F_187 ( V_7 ) ||
F_187 ( V_214 ) )
return 0 ;
V_219 = & F_26 ( V_7 ) -> V_140 [ V_202 ] ;
V_220 = & F_26 ( V_214 ) -> V_140 [ V_216 ] ;
F_190 ( V_220 , V_215 ) ;
F_139 ( V_219 , V_215 ) ;
V_219 -> V_143 += V_215 ;
goto V_221;
}
V_202 ++ ;
}
if ( ( V_215 == V_7 -> V_11 ) &&
( F_26 ( V_7 ) -> V_88 - V_202 ) > ( V_190 - V_175 ) )
return 0 ;
if ( F_187 ( V_7 ) || F_187 ( V_214 ) )
return 0 ;
while ( ( V_217 > 0 ) && ( V_202 < F_26 ( V_7 ) -> V_88 ) ) {
if ( V_175 == V_190 )
return 0 ;
V_219 = & F_26 ( V_7 ) -> V_140 [ V_202 ] ;
V_220 = & F_26 ( V_214 ) -> V_140 [ V_175 ] ;
if ( V_217 >= F_99 ( V_219 ) ) {
* V_220 = * V_219 ;
V_217 -= F_99 ( V_219 ) ;
V_202 ++ ;
V_175 ++ ;
} else {
F_191 ( V_219 ) ;
V_220 -> V_5 = V_219 -> V_5 ;
V_220 -> V_143 = V_219 -> V_143 ;
F_134 ( V_220 , V_217 ) ;
V_219 -> V_143 += V_217 ;
F_139 ( V_219 , V_217 ) ;
V_217 = 0 ;
V_175 ++ ;
break;
}
}
F_26 ( V_214 ) -> V_88 = V_175 ;
if ( V_216 >= 0 ) {
V_219 = & F_26 ( V_7 ) -> V_140 [ 0 ] ;
V_220 = & F_26 ( V_214 ) -> V_140 [ V_216 ] ;
F_190 ( V_220 , F_99 ( V_219 ) ) ;
F_192 ( V_219 ) ;
}
V_175 = 0 ;
while ( V_202 < F_26 ( V_7 ) -> V_88 )
F_26 ( V_7 ) -> V_140 [ V_175 ++ ] = F_26 ( V_7 ) -> V_140 [ V_202 ++ ] ;
F_26 ( V_7 ) -> V_88 = V_175 ;
F_117 ( V_217 > 0 && ! F_26 ( V_7 ) -> V_88 ) ;
V_221:
V_214 -> V_120 = V_152 ;
V_7 -> V_120 = V_152 ;
V_7 -> V_11 -= V_215 ;
V_7 -> V_79 -= V_215 ;
V_7 -> V_40 -= V_215 ;
V_214 -> V_11 += V_215 ;
V_214 -> V_79 += V_215 ;
V_214 -> V_40 += V_215 ;
return V_215 ;
}
void F_193 ( struct V_6 * V_7 , unsigned int V_202 ,
unsigned int V_175 , struct V_222 * V_223 )
{
V_223 -> V_224 = V_202 ;
V_223 -> V_225 = V_175 ;
V_223 -> V_226 = V_223 -> V_227 = V_7 ;
V_223 -> V_228 = V_223 -> V_229 = 0 ;
V_223 -> V_230 = NULL ;
}
unsigned int F_194 ( unsigned int V_231 , const T_3 * * V_13 ,
struct V_222 * V_223 )
{
unsigned int V_232 , V_233 = V_231 + V_223 -> V_224 ;
T_6 * V_59 ;
if ( F_35 ( V_233 >= V_223 -> V_225 ) )
return 0 ;
V_234:
V_232 = F_113 ( V_223 -> V_227 ) + V_223 -> V_229 ;
if ( V_233 < V_232 && ! V_223 -> V_230 ) {
* V_13 = V_223 -> V_227 -> V_13 + ( V_233 - V_223 -> V_229 ) ;
return V_232 - V_233 ;
}
if ( V_223 -> V_228 == 0 && ! V_223 -> V_230 )
V_223 -> V_229 += F_113 ( V_223 -> V_227 ) ;
while ( V_223 -> V_228 < F_26 ( V_223 -> V_227 ) -> V_88 ) {
V_59 = & F_26 ( V_223 -> V_227 ) -> V_140 [ V_223 -> V_228 ] ;
V_232 = F_99 ( V_59 ) + V_223 -> V_229 ;
if ( V_233 < V_232 ) {
if ( ! V_223 -> V_230 )
V_223 -> V_230 = F_97 ( F_98 ( V_59 ) ) ;
* V_13 = ( T_3 * ) V_223 -> V_230 + V_59 -> V_143 +
( V_233 - V_223 -> V_229 ) ;
return V_232 - V_233 ;
}
if ( V_223 -> V_230 ) {
F_100 ( V_223 -> V_230 ) ;
V_223 -> V_230 = NULL ;
}
V_223 -> V_228 ++ ;
V_223 -> V_229 += F_99 ( V_59 ) ;
}
if ( V_223 -> V_230 ) {
F_100 ( V_223 -> V_230 ) ;
V_223 -> V_230 = NULL ;
}
if ( V_223 -> V_226 == V_223 -> V_227 && F_59 ( V_223 -> V_226 ) ) {
V_223 -> V_227 = F_26 ( V_223 -> V_226 ) -> V_84 ;
V_223 -> V_228 = 0 ;
goto V_234;
} else if ( V_223 -> V_227 -> V_83 ) {
V_223 -> V_227 = V_223 -> V_227 -> V_83 ;
V_223 -> V_228 = 0 ;
goto V_234;
}
return 0 ;
}
void F_195 ( struct V_222 * V_223 )
{
if ( V_223 -> V_230 )
F_100 ( V_223 -> V_230 ) ;
}
static unsigned int F_196 ( unsigned int V_69 , const T_3 * * V_235 ,
struct V_236 * V_237 ,
struct V_238 * V_239 )
{
return F_194 ( V_69 , V_235 , F_197 ( V_239 ) ) ;
}
static void F_198 ( struct V_236 * V_237 , struct V_238 * V_239 )
{
F_195 ( F_197 ( V_239 ) ) ;
}
unsigned int F_199 ( struct V_6 * V_7 , unsigned int V_202 ,
unsigned int V_175 , struct V_236 * V_240 ,
struct V_238 * V_239 )
{
unsigned int V_201 ;
V_240 -> V_241 = F_196 ;
V_240 -> V_242 = F_198 ;
F_193 ( V_7 , V_202 , V_175 , F_197 ( V_239 ) ) ;
V_201 = F_200 ( V_240 , V_239 ) ;
return ( V_201 <= V_175 - V_202 ? V_201 : V_243 ) ;
}
int F_201 ( struct V_184 * V_132 , struct V_6 * V_7 ,
int (* F_202)( void * V_202 , char * V_175 , int V_69 ,
int V_11 , int V_244 , struct V_6 * V_7 ) ,
void * V_202 , int V_72 )
{
int V_245 = 0 ;
T_6 * V_59 = NULL ;
struct V_5 * V_5 = NULL ;
int V_178 , V_246 ;
int V_69 = 0 ;
int V_201 ;
do {
V_245 = F_26 ( V_7 ) -> V_88 ;
if ( V_245 >= V_190 )
return - V_180 ;
V_5 = F_36 ( V_132 -> V_247 , 0 ) ;
if ( V_5 == NULL )
return - V_142 ;
F_47 ( V_7 , V_245 , V_5 , 0 , 0 ) ;
V_7 -> V_40 += V_64 ;
F_203 ( V_64 , & V_132 -> V_248 ) ;
V_245 = F_26 ( V_7 ) -> V_88 ;
V_59 = & F_26 ( V_7 ) -> V_140 [ V_245 - 1 ] ;
V_246 = V_64 - V_59 -> V_143 ;
V_178 = ( V_72 > V_246 ) ? V_246 : V_72 ;
V_201 = F_202 ( V_202 , F_204 ( V_59 ) + F_99 ( V_59 ) ,
V_69 , V_178 , 0 , V_7 ) ;
if ( V_201 < 0 )
return - V_180 ;
F_190 ( V_59 , V_178 ) ;
V_7 -> V_11 += V_178 ;
V_7 -> V_79 += V_178 ;
V_69 += V_178 ;
V_72 -= V_178 ;
} while ( V_72 > 0 );
return 0 ;
}
unsigned char * F_205 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_117 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_117 ( V_7 -> V_11 < V_7 -> V_79 ) ;
F_206 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_207 ( struct V_6 * V_7 , T_9 V_249 )
{
struct V_6 * V_250 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_251 = F_26 ( V_7 ) -> V_84 ;
unsigned int V_252 = F_26 ( V_7 ) -> V_144 ;
unsigned int V_253 = V_7 -> V_13 - F_208 ( V_7 ) ;
unsigned int V_69 = V_253 ;
unsigned int V_148 ;
unsigned int V_11 ;
int V_254 = ! ! ( V_249 & V_255 ) ;
int V_166 = F_26 ( V_7 ) -> V_88 ;
int V_162 = - V_142 ;
int V_77 = 0 ;
int V_203 ;
F_209 ( V_7 , V_253 ) ;
V_148 = F_92 ( V_7 ) ;
V_203 = F_113 ( V_7 ) ;
do {
struct V_6 * V_256 ;
T_6 * V_59 ;
int V_257 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_69 ;
if ( V_11 > V_252 )
V_11 = V_252 ;
V_257 = F_113 ( V_7 ) - V_69 ;
if ( V_257 < 0 )
V_257 = 0 ;
if ( V_257 > V_11 || ! V_254 )
V_257 = V_11 ;
if ( ! V_257 && V_77 >= V_166 ) {
F_117 ( V_251 -> V_11 != V_11 ) ;
V_203 += V_11 ;
V_256 = F_102 ( V_251 , V_53 ) ;
V_251 = V_251 -> V_83 ;
if ( F_35 ( ! V_256 ) )
goto V_162;
V_257 = F_109 ( V_256 ) ;
if ( F_210 ( V_256 , V_253 + V_148 ) ) {
F_49 ( V_256 ) ;
goto V_162;
}
V_256 -> V_40 += F_109 ( V_256 ) - V_257 ;
F_62 ( V_256 ) ;
F_209 ( V_256 , V_253 ) ;
} else {
V_256 = F_13 ( V_257 + V_253 + V_148 ,
V_53 , F_107 ( V_7 ) ,
V_76 ) ;
if ( F_35 ( ! V_256 ) )
goto V_162;
F_45 ( V_256 , V_148 ) ;
F_211 ( V_256 , V_253 ) ;
}
if ( V_250 )
V_14 -> V_83 = V_256 ;
else
V_250 = V_256 ;
V_14 = V_256 ;
F_84 ( V_256 , V_7 ) ;
V_256 -> V_133 = V_7 -> V_133 ;
if ( V_256 -> V_120 == V_152 )
V_256 -> V_153 += F_92 ( V_256 ) - V_148 ;
F_212 ( V_256 ) ;
F_213 ( V_256 , V_7 -> V_133 ) ;
V_256 -> V_107 = ( V_256 -> V_108 +
F_214 ( V_7 ) ) ;
F_114 ( V_7 , V_256 -> V_13 , V_253 ) ;
if ( V_251 != F_26 ( V_7 ) -> V_84 )
continue;
if ( ! V_254 ) {
V_256 -> V_120 = V_258 ;
V_256 -> V_117 = F_162 ( V_7 , V_69 ,
F_110 ( V_256 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_59 = F_26 ( V_256 ) -> V_140 ;
F_140 ( V_7 , V_69 ,
F_110 ( V_256 , V_257 ) , V_257 ) ;
while ( V_203 < V_69 + V_11 && V_77 < V_166 ) {
* V_59 = F_26 ( V_7 ) -> V_140 [ V_77 ] ;
F_191 ( V_59 ) ;
V_18 = F_99 ( V_59 ) ;
if ( V_203 < V_69 ) {
V_59 -> V_143 += V_69 - V_203 ;
F_139 ( V_59 , V_69 - V_203 ) ;
}
F_26 ( V_256 ) -> V_88 ++ ;
if ( V_203 + V_18 <= V_69 + V_11 ) {
V_77 ++ ;
V_203 += V_18 ;
} else {
F_139 ( V_59 , V_203 + V_18 - ( V_69 + V_11 ) ) ;
goto V_259;
}
V_59 ++ ;
}
if ( V_203 < V_69 + V_11 ) {
struct V_6 * V_260 = V_251 ;
F_117 ( V_203 + V_251 -> V_11 != V_69 + V_11 ) ;
V_203 += V_251 -> V_11 ;
V_251 = V_251 -> V_83 ;
if ( V_260 -> V_83 ) {
V_260 = F_102 ( V_260 , V_53 ) ;
if ( ! V_260 )
goto V_162;
} else
F_53 ( V_260 ) ;
F_215 ( V_256 ) ;
F_26 ( V_256 ) -> V_84 = V_260 ;
}
V_259:
V_256 -> V_79 = V_11 - V_257 ;
V_256 -> V_11 += V_256 -> V_79 ;
V_256 -> V_40 += V_256 -> V_79 ;
} while ( ( V_69 += V_11 ) < V_7 -> V_11 );
return V_250 ;
V_162:
while ( ( V_7 = V_250 ) ) {
V_250 = V_7 -> V_83 ;
F_49 ( V_7 ) ;
}
return F_216 ( V_162 ) ;
}
int F_217 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_261 = * V_12 ;
struct V_6 * V_256 ;
struct V_31 * V_262 = F_26 ( V_7 ) ;
struct V_31 * V_263 = F_26 ( V_261 ) ;
unsigned int V_148 ;
unsigned int V_11 = F_218 ( V_7 ) ;
unsigned int V_69 = F_219 ( V_7 ) ;
unsigned int V_264 = F_113 ( V_7 ) ;
unsigned int V_265 ;
if ( V_261 -> V_11 + V_11 >= 65536 )
return - V_266 ;
if ( V_263 -> V_84 )
goto V_216;
else if ( V_264 <= V_69 ) {
T_6 * V_59 ;
T_6 * V_267 ;
int V_77 = V_262 -> V_88 ;
int V_88 = V_263 -> V_88 + V_77 ;
V_69 -= V_264 ;
if ( V_88 > V_190 )
return - V_266 ;
V_263 -> V_88 = V_88 ;
V_262 -> V_88 = 0 ;
V_59 = V_263 -> V_140 + V_88 ;
V_267 = V_262 -> V_140 + V_77 ;
do {
* -- V_59 = * -- V_267 ;
} while ( -- V_77 );
V_59 -> V_143 += V_69 ;
F_139 ( V_59 , V_69 ) ;
V_265 = V_7 -> V_40 -
F_22 ( F_109 ( V_7 ) ) ;
V_7 -> V_40 -= V_7 -> V_79 ;
V_7 -> V_11 -= V_7 -> V_79 ;
V_7 -> V_79 = 0 ;
F_220 ( V_7 ) -> free = V_268 ;
goto V_168;
} else if ( V_7 -> V_54 ) {
int V_88 = V_263 -> V_88 ;
T_6 * V_59 = V_263 -> V_140 + V_88 ;
struct V_5 * V_5 = F_44 ( V_7 -> V_12 ) ;
unsigned int V_269 = V_264 - V_69 ;
unsigned int V_270 ;
if ( V_88 + 1 + V_262 -> V_88 > V_190 )
return - V_266 ;
V_270 = V_7 -> V_13 -
( unsigned char * ) F_40 ( V_5 ) +
V_69 ;
V_263 -> V_88 = V_88 + 1 + V_262 -> V_88 ;
V_59 -> V_5 . V_261 = V_5 ;
V_59 -> V_143 = V_270 ;
F_134 ( V_59 , V_269 ) ;
memcpy ( V_59 + 1 , V_262 -> V_140 , sizeof( * V_59 ) * V_262 -> V_88 ) ;
V_265 = V_7 -> V_40 - F_17 ( sizeof( struct V_6 ) ) ;
F_220 ( V_7 ) -> free = V_271 ;
goto V_168;
} else if ( F_218 ( V_261 ) != V_263 -> V_144 )
return - V_266 ;
V_148 = F_92 ( V_261 ) ;
V_256 = F_221 ( V_148 + F_219 ( V_261 ) , V_53 ) ;
if ( F_35 ( ! V_256 ) )
return - V_142 ;
F_84 ( V_256 , V_261 ) ;
V_256 -> V_133 = V_261 -> V_133 ;
F_45 ( V_256 , V_148 ) ;
F_211 ( V_256 , F_219 ( V_261 ) ) ;
F_222 ( V_256 , F_208 ( V_261 ) - V_261 -> V_13 ) ;
F_213 ( V_256 , F_223 ( V_261 ) ) ;
F_224 ( V_256 , F_225 ( V_261 ) ) ;
F_226 ( V_261 , F_219 ( V_261 ) ) ;
memcpy ( F_208 ( V_256 ) , F_208 ( V_261 ) ,
V_261 -> V_13 - F_208 ( V_261 ) ) ;
F_26 ( V_256 ) -> V_84 = V_261 ;
F_26 ( V_256 ) -> V_144 = V_263 -> V_144 ;
V_263 -> V_144 = 0 ;
F_227 ( V_261 ) ;
F_220 ( V_256 ) -> V_272 = V_261 ;
V_256 -> V_79 += V_261 -> V_11 ;
V_256 -> V_40 += V_261 -> V_40 ;
V_256 -> V_11 += V_261 -> V_11 ;
* V_12 = V_256 ;
V_256 -> V_83 = V_261 -> V_83 ;
V_261 -> V_83 = NULL ;
V_261 = V_256 ;
V_216:
V_265 = V_7 -> V_40 ;
if ( V_69 > V_264 ) {
unsigned int V_171 = V_69 - V_264 ;
V_262 -> V_140 [ 0 ] . V_143 += V_171 ;
F_139 ( & V_262 -> V_140 [ 0 ] , V_171 ) ;
V_7 -> V_79 -= V_171 ;
V_7 -> V_11 -= V_171 ;
V_69 = V_264 ;
}
F_226 ( V_7 , V_69 ) ;
F_220 ( V_261 ) -> V_272 -> V_83 = V_7 ;
F_220 ( V_261 ) -> V_272 = V_7 ;
F_227 ( V_7 ) ;
V_168:
F_220 ( V_261 ) -> V_273 ++ ;
V_261 -> V_79 += V_11 ;
V_261 -> V_40 += V_265 ;
V_261 -> V_11 += V_11 ;
F_220 ( V_7 ) -> V_274 = 1 ;
return 0 ;
}
void T_10 F_228 ( void )
{
V_35 = F_229 ( L_3 ,
sizeof( struct V_6 ) ,
0 ,
V_275 | V_276 ,
NULL ) ;
V_34 = F_229 ( L_4 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_4 ) ,
0 ,
V_275 | V_276 ,
NULL ) ;
}
static int
F_230 ( struct V_6 * V_7 , struct V_277 * V_254 , int V_69 , int V_11 )
{
int V_176 = F_113 ( V_7 ) ;
int V_77 , V_178 = V_176 - V_69 ;
struct V_6 * V_177 ;
int V_278 = 0 ;
if ( V_178 > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
F_231 ( V_254 , V_7 -> V_13 + V_69 , V_178 ) ;
V_278 ++ ;
if ( ( V_11 -= V_178 ) == 0 )
return V_278 ;
V_69 += V_178 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_15 ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + F_99 ( & F_26 ( V_7 ) -> V_140 [ V_77 ] ) ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
T_6 * V_59 = & F_26 ( V_7 ) -> V_140 [ V_77 ] ;
if ( V_178 > V_11 )
V_178 = V_11 ;
F_232 ( & V_254 [ V_278 ] , F_98 ( V_59 ) , V_178 ,
V_59 -> V_143 + V_69 - V_176 ) ;
V_278 ++ ;
if ( ! ( V_11 -= V_178 ) )
return V_278 ;
V_69 += V_178 ;
}
V_176 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_176 > V_69 + V_11 ) ;
V_15 = V_176 + V_177 -> V_11 ;
if ( ( V_178 = V_15 - V_69 ) > 0 ) {
if ( V_178 > V_11 )
V_178 = V_11 ;
V_278 += F_230 ( V_177 , V_254 + V_278 , V_69 - V_176 ,
V_178 ) ;
if ( ( V_11 -= V_178 ) == 0 )
return V_278 ;
V_69 += V_178 ;
}
V_176 = V_15 ;
}
F_117 ( V_11 ) ;
return V_278 ;
}
int F_233 ( struct V_6 * V_7 , struct V_277 * V_254 , int V_69 , int V_11 )
{
int V_279 = F_230 ( V_7 , V_254 , V_69 , V_11 ) ;
F_234 ( & V_254 [ V_279 - 1 ] ) ;
return V_279 ;
}
int F_235 ( struct V_6 * V_7 , int V_280 , struct V_6 * * V_281 )
{
int V_282 ;
int V_278 ;
struct V_6 * V_213 , * * V_283 ;
if ( ( F_120 ( V_7 ) || F_26 ( V_7 ) -> V_88 ) &&
F_137 ( V_7 , F_236 ( V_7 ) - F_113 ( V_7 ) ) == NULL )
return - V_142 ;
if ( ! F_59 ( V_7 ) ) {
if ( F_125 ( V_7 ) < V_280 &&
F_116 ( V_7 , 0 , V_280 - F_125 ( V_7 ) + 128 , V_53 ) )
return - V_142 ;
* V_281 = V_7 ;
return 1 ;
}
V_278 = 1 ;
V_283 = & F_26 ( V_7 ) -> V_84 ;
V_282 = 0 ;
while ( ( V_213 = * V_283 ) != NULL ) {
int V_150 = 0 ;
if ( F_118 ( V_213 ) )
V_282 = 1 ;
if ( V_213 -> V_83 == NULL && V_280 ) {
if ( F_26 ( V_213 ) -> V_88 ||
F_59 ( V_213 ) ||
F_125 ( V_213 ) < V_280 )
V_150 = V_280 + 128 ;
}
if ( V_282 ||
F_120 ( V_213 ) ||
V_150 ||
F_26 ( V_213 ) -> V_88 ||
F_59 ( V_213 ) ) {
struct V_6 * V_154 ;
if ( V_150 == 0 )
V_154 = F_108 ( V_213 , V_53 ) ;
else
V_154 = F_123 ( V_213 ,
F_92 ( V_213 ) ,
V_150 ,
V_53 ) ;
if ( F_35 ( V_154 == NULL ) )
return - V_142 ;
if ( V_213 -> V_132 )
F_237 ( V_154 , V_213 -> V_132 ) ;
V_154 -> V_83 = V_213 -> V_83 ;
* V_283 = V_154 ;
F_49 ( V_213 ) ;
V_213 = V_154 ;
}
V_278 ++ ;
* V_281 = V_213 ;
V_283 = & V_213 -> V_83 ;
}
return V_278 ;
}
static void F_238 ( struct V_6 * V_7 )
{
struct V_184 * V_132 = V_7 -> V_132 ;
F_239 ( V_7 -> V_40 , & V_132 -> V_284 ) ;
}
int F_240 ( struct V_184 * V_132 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_38 ( & V_132 -> V_284 ) + V_7 -> V_40 >=
( unsigned int ) V_132 -> V_285 )
return - V_142 ;
F_241 ( V_7 ) ;
V_7 -> V_132 = V_132 ;
V_7 -> V_97 = F_238 ;
F_203 ( V_7 -> V_40 , & V_132 -> V_284 ) ;
F_242 ( V_7 ) ;
F_176 ( & V_132 -> V_286 , V_7 ) ;
if ( ! F_243 ( V_132 , V_287 ) )
V_132 -> V_288 ( V_132 , V_11 ) ;
return 0 ;
}
void F_244 ( struct V_6 * V_289 ,
struct V_290 * V_291 )
{
struct V_184 * V_132 = V_289 -> V_132 ;
struct V_292 * V_293 ;
struct V_6 * V_7 ;
int V_162 ;
if ( ! V_132 )
return;
V_7 = F_102 ( V_289 , V_53 ) ;
if ( ! V_7 )
return;
if ( V_291 ) {
* F_245 ( V_7 ) =
* V_291 ;
} else {
V_7 -> V_106 = F_246 () ;
}
V_293 = F_247 ( V_7 ) ;
memset ( V_293 , 0 , sizeof( * V_293 ) ) ;
V_293 -> V_294 . V_295 = V_296 ;
V_293 -> V_294 . V_297 = V_298 ;
V_162 = F_240 ( V_132 , V_7 ) ;
if ( V_162 )
F_49 ( V_7 ) ;
}
void F_248 ( struct V_6 * V_7 , bool V_299 )
{
struct V_184 * V_132 = V_7 -> V_132 ;
struct V_292 * V_293 ;
int V_162 ;
V_7 -> V_300 = 1 ;
V_7 -> V_301 = V_299 ;
V_293 = F_247 ( V_7 ) ;
memset ( V_293 , 0 , sizeof( * V_293 ) ) ;
V_293 -> V_294 . V_295 = V_296 ;
V_293 -> V_294 . V_297 = V_302 ;
V_162 = F_240 ( V_132 , V_7 ) ;
if ( V_162 )
F_49 ( V_7 ) ;
}
bool F_249 ( struct V_6 * V_7 , T_11 V_176 , T_11 V_78 )
{
if ( F_35 ( V_176 > F_113 ( V_7 ) ) ||
F_35 ( ( int ) V_176 + V_78 > F_113 ( V_7 ) - 2 ) ) {
F_250 ( L_5 ,
V_176 , V_78 , F_113 ( V_7 ) ) ;
return false ;
}
V_7 -> V_120 = V_152 ;
V_7 -> V_153 = F_92 ( V_7 ) + V_176 ;
V_7 -> V_207 = V_78 ;
return true ;
}
void F_251 ( const struct V_6 * V_7 )
{
F_250 ( L_6 ,
V_7 -> V_16 -> V_17 ) ;
}
void F_252 ( struct V_6 * V_7 , bool V_303 )
{
if ( V_303 ) {
F_62 ( V_7 ) ;
F_29 ( V_35 , V_7 ) ;
} else {
F_77 ( V_7 ) ;
}
}
bool F_253 ( struct V_6 * V_175 , struct V_6 * V_202 ,
bool * V_304 , int * V_265 )
{
int V_77 , V_155 , V_11 = V_202 -> V_11 ;
* V_304 = false ;
if ( F_120 ( V_175 ) )
return false ;
if ( V_11 <= F_125 ( V_175 ) ) {
F_117 ( F_111 ( V_202 , 0 , F_110 ( V_175 , V_11 ) , V_11 ) ) ;
* V_265 = 0 ;
return true ;
}
if ( F_59 ( V_175 ) || F_59 ( V_202 ) )
return false ;
if ( F_113 ( V_202 ) != 0 ) {
struct V_5 * V_5 ;
unsigned int V_69 ;
if ( F_26 ( V_175 ) -> V_88 +
F_26 ( V_202 ) -> V_88 >= V_190 )
return false ;
if ( F_152 ( V_202 ) )
return false ;
V_155 = V_202 -> V_40 - F_17 ( sizeof( struct V_6 ) ) ;
V_5 = F_44 ( V_202 -> V_12 ) ;
V_69 = V_202 -> V_13 - ( unsigned char * ) F_40 ( V_5 ) ;
F_47 ( V_175 , F_26 ( V_175 ) -> V_88 ,
V_5 , V_69 , F_113 ( V_202 ) ) ;
* V_304 = true ;
} else {
if ( F_26 ( V_175 ) -> V_88 +
F_26 ( V_202 ) -> V_88 > V_190 )
return false ;
V_155 = V_202 -> V_40 - F_22 ( F_109 ( V_202 ) ) ;
}
F_254 ( V_155 < V_11 ) ;
memcpy ( F_26 ( V_175 ) -> V_140 + F_26 ( V_175 ) -> V_88 ,
F_26 ( V_202 ) -> V_140 ,
F_26 ( V_202 ) -> V_88 * sizeof( T_6 ) ) ;
F_26 ( V_175 ) -> V_88 += F_26 ( V_202 ) -> V_88 ;
if ( ! F_120 ( V_202 ) )
F_26 ( V_202 ) -> V_88 = 0 ;
for ( V_77 = 0 ; V_77 < F_26 ( V_202 ) -> V_88 ; V_77 ++ )
F_115 ( V_202 , V_77 ) ;
V_175 -> V_40 += V_155 ;
V_175 -> V_11 += V_11 ;
V_175 -> V_79 += V_11 ;
* V_265 = V_155 ;
return true ;
}
