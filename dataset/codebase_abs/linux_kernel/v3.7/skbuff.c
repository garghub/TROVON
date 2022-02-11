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
V_92 -> V_93 ( V_92 ) ;
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
if ( F_35 ( ! V_7 ) )
return;
if ( F_37 ( F_38 ( & V_7 -> V_41 ) == 1 ) )
F_78 () ;
else if ( F_37 ( ! F_61 ( & V_7 -> V_41 ) ) )
return;
F_82 ( V_7 ) ;
F_77 ( V_7 ) ;
}
static void F_83 ( struct V_6 * V_104 , const struct V_6 * V_105 )
{
V_104 -> V_106 = V_105 -> V_106 ;
V_104 -> V_16 = V_105 -> V_16 ;
V_104 -> V_107 = V_105 -> V_107 ;
V_104 -> V_108 = V_105 -> V_108 ;
V_104 -> V_42 = V_105 -> V_42 ;
F_84 ( V_104 , V_105 ) ;
V_104 -> V_109 = V_105 -> V_109 ;
V_104 -> V_110 = V_105 -> V_110 ;
V_104 -> V_111 = V_105 -> V_111 ;
V_104 -> V_112 = V_105 -> V_112 ;
#ifdef F_64
V_104 -> V_96 = F_85 ( V_105 -> V_96 ) ;
#endif
memcpy ( V_104 -> V_113 , V_105 -> V_113 , sizeof( V_105 -> V_113 ) ) ;
V_104 -> V_114 = V_105 -> V_114 ;
V_104 -> V_115 = V_105 -> V_115 ;
V_104 -> V_116 = V_105 -> V_116 ;
V_104 -> V_117 = V_105 -> V_117 ;
F_86 ( V_104 , V_105 ) ;
V_104 -> V_118 = V_105 -> V_118 ;
#if F_68 ( V_119 )
V_104 -> V_120 = V_105 -> V_120 ;
#endif
V_104 -> V_22 = V_105 -> V_22 ;
V_104 -> V_121 = V_105 -> V_121 ;
V_104 -> V_122 = V_105 -> V_122 ;
V_104 -> V_123 = V_105 -> V_123 ;
F_87 ( V_104 , V_105 ) ;
#if F_68 ( V_124 )
V_104 -> V_125 = V_105 -> V_125 ;
#endif
#ifdef F_74
V_104 -> V_102 = V_105 -> V_102 ;
#ifdef F_75
V_104 -> V_103 = V_105 -> V_103 ;
#endif
#endif
V_104 -> V_126 = V_105 -> V_126 ;
F_88 ( V_104 , V_105 ) ;
}
static struct V_6 * F_89 ( struct V_6 * V_127 , struct V_6 * V_7 )
{
#define F_90 ( T_5 ) n->x = skb->x
V_127 -> V_83 = V_127 -> V_128 = NULL ;
V_127 -> V_129 = NULL ;
F_83 ( V_127 , V_7 ) ;
F_90 ( V_11 ) ;
F_90 ( V_79 ) ;
F_90 ( V_130 ) ;
V_127 -> V_131 = V_7 -> V_86 ? F_91 ( V_7 ) : V_7 -> V_131 ;
V_127 -> V_85 = 1 ;
V_127 -> V_86 = 0 ;
V_127 -> V_97 = NULL ;
F_90 ( V_14 ) ;
F_90 ( V_15 ) ;
F_90 ( V_12 ) ;
F_90 ( V_54 ) ;
F_90 ( V_13 ) ;
F_90 ( V_40 ) ;
F_23 ( & V_127 -> V_41 , 1 ) ;
F_92 ( & ( F_26 ( V_7 ) -> V_43 ) ) ;
V_7 -> V_85 = 1 ;
return V_127 ;
#undef F_90
}
struct V_6 * F_93 ( struct V_6 * V_132 , struct V_6 * V_133 )
{
F_76 ( V_132 ) ;
return F_89 ( V_132 , V_133 ) ;
}
int F_94 ( struct V_6 * V_7 , T_2 V_28 )
{
int V_77 ;
int V_134 = F_26 ( V_7 ) -> V_88 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_91 * V_92 = F_26 ( V_7 ) -> V_44 ;
for ( V_77 = 0 ; V_77 < V_134 ; V_77 ++ ) {
T_3 * V_135 ;
T_6 * V_136 = & F_26 ( V_7 ) -> V_137 [ V_77 ] ;
V_5 = F_95 ( V_28 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_83 = (struct V_5 * ) V_12 -> V_138 ;
F_2 ( V_12 ) ;
V_12 = V_83 ;
}
return - V_139 ;
}
V_135 = F_96 ( F_97 ( V_136 ) ) ;
memcpy ( F_40 ( V_5 ) ,
V_135 + V_136 -> V_140 , F_98 ( V_136 ) ) ;
F_99 ( V_135 ) ;
V_5 -> V_138 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_77 = 0 ; V_77 < V_134 ; V_77 ++ )
F_58 ( V_7 , V_77 ) ;
V_92 -> V_93 ( V_92 ) ;
for ( V_77 = V_134 - 1 ; V_77 >= 0 ; V_77 -- ) {
F_100 ( V_7 , V_77 , V_12 , 0 ,
F_26 ( V_7 ) -> V_137 [ V_77 ] . V_18 ) ;
V_12 = (struct V_5 * ) V_12 -> V_138 ;
}
F_26 ( V_7 ) -> V_89 &= ~ V_90 ;
return 0 ;
}
struct V_6 * F_101 ( struct V_6 * V_7 , T_2 V_28 )
{
struct V_6 * V_127 ;
if ( F_102 ( V_7 , V_28 ) )
return NULL ;
V_127 = V_7 + 1 ;
if ( V_7 -> V_49 == V_50 &&
V_127 -> V_49 == V_51 ) {
T_4 * V_46 = ( T_4 * ) ( V_127 + 1 ) ;
V_127 -> V_49 = V_95 ;
F_92 ( V_46 ) ;
} else {
if ( F_103 ( V_7 ) )
V_28 |= V_37 ;
V_127 = F_31 ( V_35 , V_28 ) ;
if ( ! V_127 )
return NULL ;
F_28 ( V_127 , V_47 ) ;
F_28 ( V_127 , V_48 ) ;
V_127 -> V_49 = V_51 ;
}
return F_89 ( V_127 , V_7 ) ;
}
static void F_104 ( struct V_6 * V_104 , const struct V_6 * V_105 )
{
#ifndef F_25
unsigned long V_69 = V_104 -> V_13 - V_105 -> V_13 ;
#endif
F_83 ( V_104 , V_105 ) ;
#ifndef F_25
V_104 -> V_107 += V_69 ;
V_104 -> V_108 += V_69 ;
if ( F_105 ( V_104 ) )
V_104 -> V_42 += V_69 ;
#endif
F_26 ( V_104 ) -> V_141 = F_26 ( V_105 ) -> V_141 ;
F_26 ( V_104 ) -> V_142 = F_26 ( V_105 ) -> V_142 ;
F_26 ( V_104 ) -> V_143 = F_26 ( V_105 ) -> V_143 ;
}
static inline int F_106 ( const struct V_6 * V_7 )
{
if ( F_103 ( V_7 ) )
return V_36 ;
return 0 ;
}
struct V_6 * F_107 ( const struct V_6 * V_7 , T_2 V_28 )
{
int V_144 = F_91 ( V_7 ) ;
unsigned int V_18 = F_108 ( V_7 ) + V_7 -> V_79 ;
struct V_6 * V_127 = F_13 ( V_18 , V_28 ,
F_106 ( V_7 ) , V_76 ) ;
if ( ! V_127 )
return NULL ;
F_45 ( V_127 , V_144 ) ;
F_109 ( V_127 , V_7 -> V_11 ) ;
if ( F_110 ( V_7 , - V_144 , V_127 -> V_12 , V_144 + V_7 -> V_11 ) )
F_8 () ;
F_104 ( V_127 , V_7 ) ;
return V_127 ;
}
struct V_6 * F_111 ( struct V_6 * V_7 , int V_145 , T_2 V_28 )
{
unsigned int V_18 = F_112 ( V_7 ) + V_145 ;
struct V_6 * V_127 = F_13 ( V_18 , V_28 ,
F_106 ( V_7 ) , V_76 ) ;
if ( ! V_127 )
goto V_27;
F_45 ( V_127 , V_145 ) ;
F_109 ( V_127 , F_112 ( V_7 ) ) ;
F_113 ( V_7 , V_127 -> V_13 , V_127 -> V_11 ) ;
V_127 -> V_40 += V_7 -> V_79 ;
V_127 -> V_79 = V_7 -> V_79 ;
V_127 -> V_11 = V_7 -> V_11 ;
if ( F_26 ( V_7 ) -> V_88 ) {
int V_77 ;
if ( F_102 ( V_7 , V_28 ) ) {
F_49 ( V_127 ) ;
V_127 = NULL ;
goto V_27;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
F_26 ( V_127 ) -> V_137 [ V_77 ] = F_26 ( V_7 ) -> V_137 [ V_77 ] ;
F_114 ( V_7 , V_77 ) ;
}
F_26 ( V_127 ) -> V_88 = V_77 ;
}
if ( F_59 ( V_7 ) ) {
F_26 ( V_127 ) -> V_84 = F_26 ( V_7 ) -> V_84 ;
F_51 ( V_127 ) ;
}
F_104 ( V_127 , V_7 ) ;
V_27:
return V_127 ;
}
int F_115 ( struct V_6 * V_7 , int V_146 , int V_147 ,
T_2 V_28 )
{
int V_77 ;
T_3 * V_13 ;
int V_18 = V_146 + F_108 ( V_7 ) + V_147 ;
long V_78 ;
F_116 ( V_146 < 0 ) ;
if ( F_117 ( V_7 ) )
F_8 () ;
V_18 = F_17 ( V_18 ) ;
if ( F_103 ( V_7 ) )
V_28 |= V_37 ;
V_13 = F_18 ( V_18 + F_17 ( sizeof( struct V_31 ) ) ,
V_28 , V_76 , NULL ) ;
if ( ! V_13 )
goto V_39;
V_18 = F_19 ( F_20 ( V_13 ) ) ;
memcpy ( V_13 + V_146 , V_7 -> V_12 , F_118 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_31 * ) ( V_13 + V_18 ) ,
F_26 ( V_7 ) ,
F_21 ( struct V_31 , V_137 [ F_26 ( V_7 ) -> V_88 ] ) ) ;
if ( F_119 ( V_7 ) ) {
if ( F_102 ( V_7 , V_28 ) )
goto V_148;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ )
F_114 ( V_7 , V_77 ) ;
if ( F_59 ( V_7 ) )
F_51 ( V_7 ) ;
F_56 ( V_7 ) ;
} else {
F_54 ( V_7 ) ;
}
V_78 = ( V_13 + V_146 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_54 = 0 ;
V_7 -> V_13 += V_78 ;
#ifdef F_25
V_7 -> V_15 = V_18 ;
V_78 = V_146 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_78 ;
V_7 -> V_107 += V_78 ;
V_7 -> V_108 += V_78 ;
if ( F_105 ( V_7 ) )
V_7 -> V_42 += V_78 ;
if ( V_7 -> V_117 == V_149 )
V_7 -> V_150 += V_146 ;
V_7 -> V_85 = 0 ;
V_7 -> V_131 = 0 ;
V_7 -> V_86 = 0 ;
F_23 ( & F_26 ( V_7 ) -> V_43 , 1 ) ;
return 0 ;
V_148:
F_55 ( V_13 ) ;
V_39:
return - V_139 ;
}
struct V_6 * F_120 ( struct V_6 * V_7 , unsigned int V_145 )
{
struct V_6 * V_151 ;
int V_152 = V_145 - F_91 ( V_7 ) ;
if ( V_152 <= 0 )
V_151 = F_121 ( V_7 , V_53 ) ;
else {
V_151 = F_101 ( V_7 , V_53 ) ;
if ( V_151 && F_115 ( V_151 , F_17 ( V_152 ) , 0 ,
V_53 ) ) {
F_49 ( V_151 ) ;
V_151 = NULL ;
}
}
return V_151 ;
}
struct V_6 * F_122 ( const struct V_6 * V_7 ,
int V_153 , int V_154 ,
T_2 V_28 )
{
struct V_6 * V_127 = F_13 ( V_153 + V_7 -> V_11 + V_154 ,
V_28 , F_106 ( V_7 ) ,
V_76 ) ;
int V_155 = F_91 ( V_7 ) ;
int V_156 , V_157 ;
int V_78 ;
if ( ! V_127 )
return NULL ;
F_45 ( V_127 , V_153 ) ;
F_109 ( V_127 , V_7 -> V_11 ) ;
V_156 = V_155 ;
V_157 = 0 ;
if ( V_153 <= V_156 )
V_156 = V_153 ;
else
V_157 = V_153 - V_156 ;
if ( F_110 ( V_7 , - V_156 , V_127 -> V_12 + V_157 ,
V_7 -> V_11 + V_156 ) )
F_8 () ;
F_104 ( V_127 , V_7 ) ;
V_78 = V_153 - V_155 ;
if ( V_127 -> V_117 == V_149 )
V_127 -> V_150 += V_78 ;
#ifdef F_25
V_127 -> V_107 += V_78 ;
V_127 -> V_108 += V_78 ;
if ( F_105 ( V_7 ) )
V_127 -> V_42 += V_78 ;
#endif
return V_127 ;
}
int F_123 ( struct V_6 * V_7 , int V_158 )
{
int V_159 ;
int V_147 ;
if ( ! F_119 ( V_7 ) && F_124 ( V_7 ) >= V_158 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_158 ) ;
return 0 ;
}
V_147 = V_7 -> V_79 + V_158 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_37 ( F_119 ( V_7 ) || V_147 > 0 ) ) {
V_159 = F_115 ( V_7 , 0 , V_147 , V_53 ) ;
if ( F_35 ( V_159 ) )
goto V_160;
}
V_159 = F_125 ( V_7 ) ;
if ( F_35 ( V_159 ) )
goto V_160;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_158 ) ;
return 0 ;
V_160:
F_49 ( V_7 ) ;
return V_159 ;
}
unsigned char * F_109 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_161 = F_118 ( V_7 ) ;
F_126 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_35 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_80 ( 0 ) ) ;
return V_161 ;
}
unsigned char * F_127 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_35 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_80 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_128 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_129 ( V_7 , V_11 ) ;
}
void F_130 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_131 ( V_7 , V_11 ) ;
}
int F_132 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_162 ;
struct V_6 * V_59 ;
int V_69 = F_112 ( V_7 ) ;
int V_163 = F_26 ( V_7 ) -> V_88 ;
int V_77 ;
int V_159 ;
if ( F_119 ( V_7 ) &&
F_35 ( ( V_159 = F_115 ( V_7 , 0 , 0 , V_53 ) ) ) )
return V_159 ;
V_77 = 0 ;
if ( V_69 >= V_11 )
goto V_164;
for (; V_77 < V_163 ; V_77 ++ ) {
int V_15 = V_69 + F_98 ( & F_26 ( V_7 ) -> V_137 [ V_77 ] ) ;
if ( V_15 < V_11 ) {
V_69 = V_15 ;
continue;
}
F_133 ( & F_26 ( V_7 ) -> V_137 [ V_77 ++ ] , V_11 - V_69 ) ;
V_164:
F_26 ( V_7 ) -> V_88 = V_77 ;
for (; V_77 < V_163 ; V_77 ++ )
F_58 ( V_7 , V_77 ) ;
if ( F_59 ( V_7 ) )
F_50 ( V_7 ) ;
goto V_165;
}
for ( V_162 = & F_26 ( V_7 ) -> V_84 ; ( V_59 = * V_162 ) ;
V_162 = & V_59 -> V_83 ) {
int V_15 = V_69 + V_59 -> V_11 ;
if ( F_117 ( V_59 ) ) {
struct V_6 * V_166 ;
V_166 = F_101 ( V_59 , V_53 ) ;
if ( F_35 ( ! V_166 ) )
return - V_139 ;
V_166 -> V_83 = V_59 -> V_83 ;
F_81 ( V_59 ) ;
V_59 = V_166 ;
* V_162 = V_59 ;
}
if ( V_15 < V_11 ) {
V_69 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_35 ( ( V_159 = F_134 ( V_59 , V_11 - V_69 ) ) ) )
return V_159 ;
if ( V_59 -> V_83 )
F_48 ( & V_59 -> V_83 ) ;
break;
}
V_165:
if ( V_11 > F_112 ( V_7 ) ) {
V_7 -> V_79 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_79 = 0 ;
F_135 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_136 ( struct V_6 * V_7 , int V_152 )
{
int V_77 , V_167 , V_168 = ( V_7 -> V_14 + V_152 ) - V_7 -> V_15 ;
if ( V_168 > 0 || F_119 ( V_7 ) ) {
if ( F_115 ( V_7 , 0 , V_168 > 0 ? V_168 + 128 : 0 ,
V_53 ) )
return NULL ;
}
if ( F_110 ( V_7 , F_112 ( V_7 ) , F_118 ( V_7 ) , V_152 ) )
F_8 () ;
if ( ! F_59 ( V_7 ) )
goto V_169;
V_168 = V_152 ;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_18 = F_98 ( & F_26 ( V_7 ) -> V_137 [ V_77 ] ) ;
if ( V_18 >= V_168 )
goto V_169;
V_168 -= V_18 ;
}
if ( V_168 ) {
struct V_6 * V_81 = F_26 ( V_7 ) -> V_84 ;
struct V_6 * V_170 = NULL ;
struct V_6 * V_171 = NULL ;
do {
F_116 ( ! V_81 ) ;
if ( V_81 -> V_11 <= V_168 ) {
V_168 -= V_81 -> V_11 ;
V_81 = V_81 -> V_83 ;
V_171 = V_81 ;
} else {
if ( F_117 ( V_81 ) ) {
V_170 = F_101 ( V_81 , V_53 ) ;
if ( ! V_170 )
return NULL ;
V_171 = V_81 -> V_83 ;
V_81 = V_170 ;
} else {
V_171 = V_81 ;
}
if ( ! F_137 ( V_81 , V_168 ) ) {
F_49 ( V_170 ) ;
return NULL ;
}
break;
}
} while ( V_168 );
while ( ( V_81 = F_26 ( V_7 ) -> V_84 ) != V_171 ) {
F_26 ( V_7 ) -> V_84 = V_81 -> V_83 ;
F_49 ( V_81 ) ;
}
if ( V_170 ) {
V_170 -> V_83 = V_81 ;
F_26 ( V_7 ) -> V_84 = V_170 ;
}
}
V_169:
V_168 = V_152 ;
V_167 = 0 ;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_18 = F_98 ( & F_26 ( V_7 ) -> V_137 [ V_77 ] ) ;
if ( V_18 <= V_168 ) {
F_58 ( V_7 , V_77 ) ;
V_168 -= V_18 ;
} else {
F_26 ( V_7 ) -> V_137 [ V_167 ] = F_26 ( V_7 ) -> V_137 [ V_77 ] ;
if ( V_168 ) {
F_26 ( V_7 ) -> V_137 [ V_167 ] . V_140 += V_168 ;
F_138 ( & F_26 ( V_7 ) -> V_137 [ V_167 ] , V_168 ) ;
V_168 = 0 ;
}
V_167 ++ ;
}
}
F_26 ( V_7 ) -> V_88 = V_167 ;
V_7 -> V_14 += V_152 ;
V_7 -> V_79 -= V_152 ;
return F_118 ( V_7 ) ;
}
int F_110 ( const struct V_6 * V_7 , int V_69 , void * V_172 , int V_11 )
{
int V_173 = F_112 ( V_7 ) ;
struct V_6 * V_174 ;
int V_77 , V_175 ;
if ( V_69 > ( int ) V_7 -> V_11 - V_11 )
goto V_176;
if ( ( V_175 = V_173 - V_69 ) > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
F_139 ( V_7 , V_69 , V_172 , V_175 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return 0 ;
V_69 += V_175 ;
V_172 += V_175 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_15 ;
T_6 * V_136 = & F_26 ( V_7 ) -> V_137 [ V_77 ] ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + F_98 ( V_136 ) ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
T_3 * V_135 ;
if ( V_175 > V_11 )
V_175 = V_11 ;
V_135 = F_96 ( F_97 ( V_136 ) ) ;
memcpy ( V_172 ,
V_135 + V_136 -> V_140 + V_69 - V_173 ,
V_175 ) ;
F_99 ( V_135 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return 0 ;
V_69 += V_175 ;
V_172 += V_175 ;
}
V_173 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + V_174 -> V_11 ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
if ( F_110 ( V_174 , V_69 - V_173 , V_172 , V_175 ) )
goto V_176;
if ( ( V_11 -= V_175 ) == 0 )
return 0 ;
V_69 += V_175 ;
V_172 += V_175 ;
}
V_173 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_176:
return - V_177 ;
}
static void F_140 ( struct V_178 * V_179 , unsigned int V_77 )
{
F_2 ( V_179 -> V_180 [ V_77 ] ) ;
}
static struct V_5 * F_141 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_69 ,
struct V_6 * V_7 , struct V_181 * V_129 )
{
struct V_182 * V_183 = F_142 ( V_129 ) ;
if ( ! F_143 ( V_129 , V_183 ) )
return NULL ;
* V_11 = F_144 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_40 ( V_183 -> V_5 ) + V_183 -> V_69 ,
F_40 ( V_5 ) + * V_69 , * V_11 ) ;
* V_69 = V_183 -> V_69 ;
V_183 -> V_69 += * V_11 ;
return V_183 -> V_5 ;
}
static bool F_145 ( const struct V_178 * V_179 ,
struct V_5 * V_5 ,
unsigned int V_69 )
{
return V_179 -> V_184 &&
V_179 -> V_180 [ V_179 -> V_184 - 1 ] == V_5 &&
( V_179 -> V_185 [ V_179 -> V_184 - 1 ] . V_69 +
V_179 -> V_185 [ V_179 -> V_184 - 1 ] . V_11 == V_69 ) ;
}
static bool F_146 ( struct V_178 * V_179 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_69 ,
struct V_6 * V_7 , bool V_186 ,
struct V_181 * V_129 )
{
if ( F_35 ( V_179 -> V_184 == V_187 ) )
return true ;
if ( V_186 ) {
V_5 = F_141 ( V_5 , V_11 , & V_69 , V_7 , V_129 ) ;
if ( ! V_5 )
return true ;
}
if ( F_145 ( V_179 , V_5 , V_69 ) ) {
V_179 -> V_185 [ V_179 -> V_184 - 1 ] . V_11 += * V_11 ;
return false ;
}
F_4 ( V_5 ) ;
V_179 -> V_180 [ V_179 -> V_184 ] = V_5 ;
V_179 -> V_185 [ V_179 -> V_184 ] . V_11 = * V_11 ;
V_179 -> V_185 [ V_179 -> V_184 ] . V_69 = V_69 ;
V_179 -> V_184 ++ ;
return false ;
}
static inline void F_147 ( struct V_5 * * V_5 , unsigned int * V_188 ,
unsigned int * V_189 , unsigned int V_78 )
{
unsigned long V_127 ;
* V_188 += V_78 ;
V_127 = * V_188 / V_64 ;
if ( V_127 )
* V_5 = F_148 ( * V_5 , V_127 ) ;
* V_188 = * V_188 % V_64 ;
* V_189 -= V_78 ;
}
static bool F_149 ( struct V_5 * V_5 , unsigned int V_188 ,
unsigned int V_189 , unsigned int * V_78 ,
unsigned int * V_11 , struct V_6 * V_7 ,
struct V_178 * V_179 , bool V_186 ,
struct V_181 * V_129 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return true ;
if ( * V_78 >= V_189 ) {
* V_78 -= V_189 ;
return false ;
}
if ( * V_78 ) {
F_147 ( & V_5 , & V_188 , & V_189 , * V_78 ) ;
* V_78 = 0 ;
}
do {
unsigned int V_190 = F_150 ( * V_11 , V_189 ) ;
V_190 = F_144 (unsigned int, flen, PAGE_SIZE - poff) ;
if ( F_146 ( V_179 , V_2 , V_5 , & V_190 , V_188 , V_7 , V_186 , V_129 ) )
return true ;
F_147 ( & V_5 , & V_188 , & V_189 , V_190 ) ;
* V_11 -= V_190 ;
} while ( * V_11 && V_189 );
return false ;
}
static bool F_151 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_69 , unsigned int * V_11 ,
struct V_178 * V_179 , struct V_181 * V_129 )
{
int V_191 ;
if ( F_149 ( F_152 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_64 - 1 ) ,
F_112 ( V_7 ) ,
V_69 , V_11 , V_7 , V_179 ,
F_153 ( V_7 ) ,
V_129 , V_2 ) )
return true ;
for ( V_191 = 0 ; V_191 < F_26 ( V_7 ) -> V_88 ; V_191 ++ ) {
const T_6 * V_136 = & F_26 ( V_7 ) -> V_137 [ V_191 ] ;
if ( F_149 ( F_97 ( V_136 ) ,
V_136 -> V_140 , F_98 ( V_136 ) ,
V_69 , V_11 , V_7 , V_179 , false , V_129 , V_2 ) )
return true ;
}
return false ;
}
int F_154 ( struct V_6 * V_7 , unsigned int V_69 ,
struct V_1 * V_2 , unsigned int V_192 ,
unsigned int V_19 )
{
struct V_193 V_185 [ V_187 ] ;
struct V_5 * V_180 [ V_187 ] ;
struct V_178 V_179 = {
. V_180 = V_180 ,
. V_185 = V_185 ,
. V_194 = V_187 ,
. V_19 = V_19 ,
. V_195 = & V_196 ,
. V_197 = F_140 ,
} ;
struct V_6 * V_174 ;
struct V_181 * V_129 = V_7 -> V_129 ;
int V_198 = 0 ;
if ( F_151 ( V_7 , V_2 , & V_69 , & V_192 , & V_179 , V_129 ) )
goto V_165;
else if ( ! V_192 )
goto V_165;
F_52 (skb, frag_iter) {
if ( ! V_192 )
break;
if ( F_151 ( V_174 , V_2 , & V_69 , & V_192 , & V_179 , V_129 ) )
break;
}
V_165:
if ( V_179 . V_184 ) {
F_155 ( V_129 ) ;
V_198 = F_156 ( V_2 , & V_179 ) ;
F_157 ( V_129 ) ;
}
return V_198 ;
}
int F_158 ( struct V_6 * V_7 , int V_69 , const void * V_199 , int V_11 )
{
int V_173 = F_112 ( V_7 ) ;
struct V_6 * V_174 ;
int V_77 , V_175 ;
if ( V_69 > ( int ) V_7 -> V_11 - V_11 )
goto V_176;
if ( ( V_175 = V_173 - V_69 ) > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
F_159 ( V_7 , V_69 , V_199 , V_175 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return 0 ;
V_69 += V_175 ;
V_199 += V_175 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
T_6 * V_59 = & F_26 ( V_7 ) -> V_137 [ V_77 ] ;
int V_15 ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + F_98 ( V_59 ) ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
T_3 * V_135 ;
if ( V_175 > V_11 )
V_175 = V_11 ;
V_135 = F_96 ( F_97 ( V_59 ) ) ;
memcpy ( V_135 + V_59 -> V_140 + V_69 - V_173 ,
V_199 , V_175 ) ;
F_99 ( V_135 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return 0 ;
V_69 += V_175 ;
V_199 += V_175 ;
}
V_173 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + V_174 -> V_11 ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
if ( F_158 ( V_174 , V_69 - V_173 ,
V_199 , V_175 ) )
goto V_176;
if ( ( V_11 -= V_175 ) == 0 )
return 0 ;
V_69 += V_175 ;
V_199 += V_175 ;
}
V_173 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_176:
return - V_177 ;
}
T_7 F_160 ( const struct V_6 * V_7 , int V_69 ,
int V_11 , T_7 V_114 )
{
int V_173 = F_112 ( V_7 ) ;
int V_77 , V_175 = V_173 - V_69 ;
struct V_6 * V_174 ;
int V_200 = 0 ;
if ( V_175 > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
V_114 = F_161 ( V_7 -> V_13 + V_69 , V_175 , V_114 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return V_114 ;
V_69 += V_175 ;
V_200 = V_175 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_15 ;
T_6 * V_59 = & F_26 ( V_7 ) -> V_137 [ V_77 ] ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + F_98 ( V_59 ) ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
T_7 V_201 ;
T_3 * V_135 ;
if ( V_175 > V_11 )
V_175 = V_11 ;
V_135 = F_96 ( F_97 ( V_59 ) ) ;
V_201 = F_161 ( V_135 + V_59 -> V_140 +
V_69 - V_173 , V_175 , 0 ) ;
F_99 ( V_135 ) ;
V_114 = F_162 ( V_114 , V_201 , V_200 ) ;
if ( ! ( V_11 -= V_175 ) )
return V_114 ;
V_69 += V_175 ;
V_200 += V_175 ;
}
V_173 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + V_174 -> V_11 ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
T_7 V_201 ;
if ( V_175 > V_11 )
V_175 = V_11 ;
V_201 = F_160 ( V_174 , V_69 - V_173 ,
V_175 , 0 ) ;
V_114 = F_162 ( V_114 , V_201 , V_200 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return V_114 ;
V_69 += V_175 ;
V_200 += V_175 ;
}
V_173 = V_15 ;
}
F_116 ( V_11 ) ;
return V_114 ;
}
T_7 F_163 ( const struct V_6 * V_7 , int V_69 ,
T_3 * V_172 , int V_11 , T_7 V_114 )
{
int V_173 = F_112 ( V_7 ) ;
int V_77 , V_175 = V_173 - V_69 ;
struct V_6 * V_174 ;
int V_200 = 0 ;
if ( V_175 > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
V_114 = F_164 ( V_7 -> V_13 + V_69 , V_172 ,
V_175 , V_114 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return V_114 ;
V_69 += V_175 ;
V_172 += V_175 ;
V_200 = V_175 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_15 ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + F_98 ( & F_26 ( V_7 ) -> V_137 [ V_77 ] ) ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
T_7 V_201 ;
T_3 * V_135 ;
T_6 * V_59 = & F_26 ( V_7 ) -> V_137 [ V_77 ] ;
if ( V_175 > V_11 )
V_175 = V_11 ;
V_135 = F_96 ( F_97 ( V_59 ) ) ;
V_201 = F_164 ( V_135 +
V_59 -> V_140 +
V_69 - V_173 , V_172 ,
V_175 , 0 ) ;
F_99 ( V_135 ) ;
V_114 = F_162 ( V_114 , V_201 , V_200 ) ;
if ( ! ( V_11 -= V_175 ) )
return V_114 ;
V_69 += V_175 ;
V_172 += V_175 ;
V_200 += V_175 ;
}
V_173 = V_15 ;
}
F_52 (skb, frag_iter) {
T_7 V_201 ;
int V_15 ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + V_174 -> V_11 ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
V_201 = F_163 ( V_174 ,
V_69 - V_173 ,
V_172 , V_175 , 0 ) ;
V_114 = F_162 ( V_114 , V_201 , V_200 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return V_114 ;
V_69 += V_175 ;
V_172 += V_175 ;
V_200 += V_175 ;
}
V_173 = V_15 ;
}
F_116 ( V_11 ) ;
return V_114 ;
}
void F_165 ( const struct V_6 * V_7 , T_3 * V_172 )
{
T_7 V_114 ;
long V_202 ;
if ( V_7 -> V_117 == V_149 )
V_202 = F_166 ( V_7 ) ;
else
V_202 = F_112 ( V_7 ) ;
F_116 ( V_202 > F_112 ( V_7 ) ) ;
F_113 ( V_7 , V_172 , V_202 ) ;
V_114 = 0 ;
if ( V_202 != V_7 -> V_11 )
V_114 = F_163 ( V_7 , V_202 , V_172 + V_202 ,
V_7 -> V_11 - V_202 , 0 ) ;
if ( V_7 -> V_117 == V_149 ) {
long V_203 = V_202 + V_7 -> V_204 ;
* ( ( V_205 * ) ( V_172 + V_203 ) ) = F_167 ( V_114 ) ;
}
}
struct V_6 * F_168 ( struct V_206 * V_81 )
{
unsigned long V_19 ;
struct V_6 * V_207 ;
F_169 ( & V_81 -> V_208 , V_19 ) ;
V_207 = F_170 ( V_81 ) ;
F_171 ( & V_81 -> V_208 , V_19 ) ;
return V_207 ;
}
struct V_6 * F_172 ( struct V_206 * V_81 )
{
unsigned long V_19 ;
struct V_6 * V_207 ;
F_169 ( & V_81 -> V_208 , V_19 ) ;
V_207 = F_173 ( V_81 ) ;
F_171 ( & V_81 -> V_208 , V_19 ) ;
return V_207 ;
}
void F_174 ( struct V_206 * V_81 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_168 ( V_81 ) ) != NULL )
F_49 ( V_7 ) ;
}
void F_175 ( struct V_206 * V_81 , struct V_6 * V_209 )
{
unsigned long V_19 ;
F_169 ( & V_81 -> V_208 , V_19 ) ;
F_176 ( V_81 , V_209 ) ;
F_171 ( & V_81 -> V_208 , V_19 ) ;
}
void F_177 ( struct V_206 * V_81 , struct V_6 * V_209 )
{
unsigned long V_19 ;
F_169 ( & V_81 -> V_208 , V_19 ) ;
F_178 ( V_81 , V_209 ) ;
F_171 ( & V_81 -> V_208 , V_19 ) ;
}
void F_179 ( struct V_6 * V_7 , struct V_206 * V_81 )
{
unsigned long V_19 ;
F_169 ( & V_81 -> V_208 , V_19 ) ;
F_180 ( V_7 , V_81 ) ;
F_171 ( & V_81 -> V_208 , V_19 ) ;
}
void F_181 ( struct V_6 * V_105 , struct V_6 * V_209 , struct V_206 * V_81 )
{
unsigned long V_19 ;
F_169 ( & V_81 -> V_208 , V_19 ) ;
F_182 ( V_81 , V_105 , V_209 ) ;
F_171 ( & V_81 -> V_208 , V_19 ) ;
}
void F_183 ( struct V_6 * V_105 , struct V_6 * V_209 , struct V_206 * V_81 )
{
unsigned long V_19 ;
F_169 ( & V_81 -> V_208 , V_19 ) ;
F_184 ( V_209 , V_105 -> V_128 , V_105 , V_81 ) ;
F_171 ( & V_81 -> V_208 , V_19 ) ;
}
static inline void F_185 ( struct V_6 * V_7 ,
struct V_6 * V_210 ,
const T_8 V_11 , const int V_200 )
{
int V_77 ;
F_139 ( V_7 , V_11 , F_109 ( V_210 , V_200 - V_11 ) ,
V_200 - V_11 ) ;
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ )
F_26 ( V_210 ) -> V_137 [ V_77 ] = F_26 ( V_7 ) -> V_137 [ V_77 ] ;
F_26 ( V_210 ) -> V_88 = F_26 ( V_7 ) -> V_88 ;
F_26 ( V_7 ) -> V_88 = 0 ;
V_210 -> V_79 = V_7 -> V_79 ;
V_210 -> V_11 += V_210 -> V_79 ;
V_7 -> V_79 = 0 ;
V_7 -> V_11 = V_11 ;
F_135 ( V_7 , V_11 ) ;
}
static inline void F_186 ( struct V_6 * V_7 ,
struct V_6 * V_210 ,
const T_8 V_11 , int V_200 )
{
int V_77 , V_167 = 0 ;
const int V_163 = F_26 ( V_7 ) -> V_88 ;
F_26 ( V_7 ) -> V_88 = 0 ;
V_210 -> V_11 = V_210 -> V_79 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_79 = V_11 - V_200 ;
for ( V_77 = 0 ; V_77 < V_163 ; V_77 ++ ) {
int V_18 = F_98 ( & F_26 ( V_7 ) -> V_137 [ V_77 ] ) ;
if ( V_200 + V_18 > V_11 ) {
F_26 ( V_210 ) -> V_137 [ V_167 ] = F_26 ( V_7 ) -> V_137 [ V_77 ] ;
if ( V_200 < V_11 ) {
F_114 ( V_7 , V_77 ) ;
F_26 ( V_210 ) -> V_137 [ 0 ] . V_140 += V_11 - V_200 ;
F_138 ( & F_26 ( V_210 ) -> V_137 [ 0 ] , V_11 - V_200 ) ;
F_133 ( & F_26 ( V_7 ) -> V_137 [ V_77 ] , V_11 - V_200 ) ;
F_26 ( V_7 ) -> V_88 ++ ;
}
V_167 ++ ;
} else
F_26 ( V_7 ) -> V_88 ++ ;
V_200 += V_18 ;
}
F_26 ( V_210 ) -> V_88 = V_167 ;
}
void F_187 ( struct V_6 * V_7 , struct V_6 * V_210 , const T_8 V_11 )
{
int V_200 = F_112 ( V_7 ) ;
if ( V_11 < V_200 )
F_185 ( V_7 , V_210 , V_11 , V_200 ) ;
else
F_186 ( V_7 , V_210 , V_11 , V_200 ) ;
}
static int F_188 ( struct V_6 * V_7 )
{
return F_119 ( V_7 ) && F_115 ( V_7 , 0 , 0 , V_53 ) ;
}
int F_189 ( struct V_6 * V_211 , struct V_6 * V_7 , int V_212 )
{
int V_199 , V_172 , V_213 , V_214 ;
struct V_215 * V_216 , * V_217 ;
F_116 ( V_212 > V_7 -> V_11 ) ;
F_116 ( F_112 ( V_7 ) ) ;
V_214 = V_212 ;
V_199 = 0 ;
V_172 = F_26 ( V_211 ) -> V_88 ;
V_216 = & F_26 ( V_7 ) -> V_137 [ V_199 ] ;
if ( ! V_172 ||
! F_190 ( V_211 , V_172 , F_97 ( V_216 ) ,
V_216 -> V_140 ) ) {
V_213 = - 1 ;
} else {
V_213 = V_172 - 1 ;
V_214 -= F_98 ( V_216 ) ;
if ( V_214 < 0 ) {
if ( F_188 ( V_7 ) ||
F_188 ( V_211 ) )
return 0 ;
V_216 = & F_26 ( V_7 ) -> V_137 [ V_199 ] ;
V_217 = & F_26 ( V_211 ) -> V_137 [ V_213 ] ;
F_191 ( V_217 , V_212 ) ;
F_138 ( V_216 , V_212 ) ;
V_216 -> V_140 += V_212 ;
goto V_218;
}
V_199 ++ ;
}
if ( ( V_212 == V_7 -> V_11 ) &&
( F_26 ( V_7 ) -> V_88 - V_199 ) > ( V_187 - V_172 ) )
return 0 ;
if ( F_188 ( V_7 ) || F_188 ( V_211 ) )
return 0 ;
while ( ( V_214 > 0 ) && ( V_199 < F_26 ( V_7 ) -> V_88 ) ) {
if ( V_172 == V_187 )
return 0 ;
V_216 = & F_26 ( V_7 ) -> V_137 [ V_199 ] ;
V_217 = & F_26 ( V_211 ) -> V_137 [ V_172 ] ;
if ( V_214 >= F_98 ( V_216 ) ) {
* V_217 = * V_216 ;
V_214 -= F_98 ( V_216 ) ;
V_199 ++ ;
V_172 ++ ;
} else {
F_192 ( V_216 ) ;
V_217 -> V_5 = V_216 -> V_5 ;
V_217 -> V_140 = V_216 -> V_140 ;
F_133 ( V_217 , V_214 ) ;
V_216 -> V_140 += V_214 ;
F_138 ( V_216 , V_214 ) ;
V_214 = 0 ;
V_172 ++ ;
break;
}
}
F_26 ( V_211 ) -> V_88 = V_172 ;
if ( V_213 >= 0 ) {
V_216 = & F_26 ( V_7 ) -> V_137 [ 0 ] ;
V_217 = & F_26 ( V_211 ) -> V_137 [ V_213 ] ;
F_191 ( V_217 , F_98 ( V_216 ) ) ;
F_193 ( V_216 ) ;
}
V_172 = 0 ;
while ( V_199 < F_26 ( V_7 ) -> V_88 )
F_26 ( V_7 ) -> V_137 [ V_172 ++ ] = F_26 ( V_7 ) -> V_137 [ V_199 ++ ] ;
F_26 ( V_7 ) -> V_88 = V_172 ;
F_116 ( V_214 > 0 && ! F_26 ( V_7 ) -> V_88 ) ;
V_218:
V_211 -> V_117 = V_149 ;
V_7 -> V_117 = V_149 ;
V_7 -> V_11 -= V_212 ;
V_7 -> V_79 -= V_212 ;
V_7 -> V_40 -= V_212 ;
V_211 -> V_11 += V_212 ;
V_211 -> V_79 += V_212 ;
V_211 -> V_40 += V_212 ;
return V_212 ;
}
void F_194 ( struct V_6 * V_7 , unsigned int V_199 ,
unsigned int V_172 , struct V_219 * V_220 )
{
V_220 -> V_221 = V_199 ;
V_220 -> V_222 = V_172 ;
V_220 -> V_223 = V_220 -> V_224 = V_7 ;
V_220 -> V_225 = V_220 -> V_226 = 0 ;
V_220 -> V_227 = NULL ;
}
unsigned int F_195 ( unsigned int V_228 , const T_3 * * V_13 ,
struct V_219 * V_220 )
{
unsigned int V_229 , V_230 = V_228 + V_220 -> V_221 ;
T_6 * V_59 ;
if ( F_35 ( V_230 >= V_220 -> V_222 ) )
return 0 ;
V_231:
V_229 = F_112 ( V_220 -> V_224 ) + V_220 -> V_226 ;
if ( V_230 < V_229 && ! V_220 -> V_227 ) {
* V_13 = V_220 -> V_224 -> V_13 + ( V_230 - V_220 -> V_226 ) ;
return V_229 - V_230 ;
}
if ( V_220 -> V_225 == 0 && ! V_220 -> V_227 )
V_220 -> V_226 += F_112 ( V_220 -> V_224 ) ;
while ( V_220 -> V_225 < F_26 ( V_220 -> V_224 ) -> V_88 ) {
V_59 = & F_26 ( V_220 -> V_224 ) -> V_137 [ V_220 -> V_225 ] ;
V_229 = F_98 ( V_59 ) + V_220 -> V_226 ;
if ( V_230 < V_229 ) {
if ( ! V_220 -> V_227 )
V_220 -> V_227 = F_96 ( F_97 ( V_59 ) ) ;
* V_13 = ( T_3 * ) V_220 -> V_227 + V_59 -> V_140 +
( V_230 - V_220 -> V_226 ) ;
return V_229 - V_230 ;
}
if ( V_220 -> V_227 ) {
F_99 ( V_220 -> V_227 ) ;
V_220 -> V_227 = NULL ;
}
V_220 -> V_225 ++ ;
V_220 -> V_226 += F_98 ( V_59 ) ;
}
if ( V_220 -> V_227 ) {
F_99 ( V_220 -> V_227 ) ;
V_220 -> V_227 = NULL ;
}
if ( V_220 -> V_223 == V_220 -> V_224 && F_59 ( V_220 -> V_223 ) ) {
V_220 -> V_224 = F_26 ( V_220 -> V_223 ) -> V_84 ;
V_220 -> V_225 = 0 ;
goto V_231;
} else if ( V_220 -> V_224 -> V_83 ) {
V_220 -> V_224 = V_220 -> V_224 -> V_83 ;
V_220 -> V_225 = 0 ;
goto V_231;
}
return 0 ;
}
void F_196 ( struct V_219 * V_220 )
{
if ( V_220 -> V_227 )
F_99 ( V_220 -> V_227 ) ;
}
static unsigned int F_197 ( unsigned int V_69 , const T_3 * * V_232 ,
struct V_233 * V_234 ,
struct V_235 * V_236 )
{
return F_195 ( V_69 , V_232 , F_198 ( V_236 ) ) ;
}
static void F_199 ( struct V_233 * V_234 , struct V_235 * V_236 )
{
F_196 ( F_198 ( V_236 ) ) ;
}
unsigned int F_200 ( struct V_6 * V_7 , unsigned int V_199 ,
unsigned int V_172 , struct V_233 * V_237 ,
struct V_235 * V_236 )
{
unsigned int V_198 ;
V_237 -> V_238 = F_197 ;
V_237 -> V_239 = F_199 ;
F_194 ( V_7 , V_199 , V_172 , F_198 ( V_236 ) ) ;
V_198 = F_201 ( V_237 , V_236 ) ;
return ( V_198 <= V_172 - V_199 ? V_198 : V_240 ) ;
}
int F_202 ( struct V_181 * V_129 , struct V_6 * V_7 ,
int (* F_203)( void * V_199 , char * V_172 , int V_69 ,
int V_11 , int V_241 , struct V_6 * V_7 ) ,
void * V_199 , int V_72 )
{
int V_242 = 0 ;
T_6 * V_59 = NULL ;
struct V_5 * V_5 = NULL ;
int V_175 , V_243 ;
int V_69 = 0 ;
int V_198 ;
do {
V_242 = F_26 ( V_7 ) -> V_88 ;
if ( V_242 >= V_187 )
return - V_177 ;
V_5 = F_36 ( V_129 -> V_244 , 0 ) ;
if ( V_5 == NULL )
return - V_139 ;
F_47 ( V_7 , V_242 , V_5 , 0 , 0 ) ;
V_7 -> V_40 += V_64 ;
F_204 ( V_64 , & V_129 -> V_245 ) ;
V_242 = F_26 ( V_7 ) -> V_88 ;
V_59 = & F_26 ( V_7 ) -> V_137 [ V_242 - 1 ] ;
V_243 = V_64 - V_59 -> V_140 ;
V_175 = ( V_72 > V_243 ) ? V_243 : V_72 ;
V_198 = F_203 ( V_199 , F_205 ( V_59 ) + F_98 ( V_59 ) ,
V_69 , V_175 , 0 , V_7 ) ;
if ( V_198 < 0 )
return - V_177 ;
F_191 ( V_59 , V_175 ) ;
V_7 -> V_11 += V_175 ;
V_7 -> V_79 += V_175 ;
V_69 += V_175 ;
V_72 -= V_175 ;
} while ( V_72 > 0 );
return 0 ;
}
unsigned char * F_206 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_116 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_116 ( V_7 -> V_11 < V_7 -> V_79 ) ;
F_207 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_208 ( struct V_6 * V_7 , T_9 V_246 )
{
struct V_6 * V_247 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_248 = F_26 ( V_7 ) -> V_84 ;
unsigned int V_249 = F_26 ( V_7 ) -> V_141 ;
unsigned int V_250 = V_7 -> V_13 - F_209 ( V_7 ) ;
unsigned int V_69 = V_250 ;
unsigned int V_145 ;
unsigned int V_11 ;
int V_251 = ! ! ( V_246 & V_252 ) ;
int V_163 = F_26 ( V_7 ) -> V_88 ;
int V_159 = - V_139 ;
int V_77 = 0 ;
int V_200 ;
F_210 ( V_7 , V_250 ) ;
V_145 = F_91 ( V_7 ) ;
V_200 = F_112 ( V_7 ) ;
do {
struct V_6 * V_253 ;
T_6 * V_59 ;
int V_254 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_69 ;
if ( V_11 > V_249 )
V_11 = V_249 ;
V_254 = F_112 ( V_7 ) - V_69 ;
if ( V_254 < 0 )
V_254 = 0 ;
if ( V_254 > V_11 || ! V_251 )
V_254 = V_11 ;
if ( ! V_254 && V_77 >= V_163 ) {
F_116 ( V_248 -> V_11 != V_11 ) ;
V_200 += V_11 ;
V_253 = F_101 ( V_248 , V_53 ) ;
V_248 = V_248 -> V_83 ;
if ( F_35 ( ! V_253 ) )
goto V_159;
V_254 = F_108 ( V_253 ) ;
if ( F_211 ( V_253 , V_250 + V_145 ) ) {
F_49 ( V_253 ) ;
goto V_159;
}
V_253 -> V_40 += F_108 ( V_253 ) - V_254 ;
F_62 ( V_253 ) ;
F_210 ( V_253 , V_250 ) ;
} else {
V_253 = F_13 ( V_254 + V_250 + V_145 ,
V_53 , F_106 ( V_7 ) ,
V_76 ) ;
if ( F_35 ( ! V_253 ) )
goto V_159;
F_45 ( V_253 , V_145 ) ;
F_212 ( V_253 , V_250 ) ;
}
if ( V_247 )
V_14 -> V_83 = V_253 ;
else
V_247 = V_253 ;
V_14 = V_253 ;
F_83 ( V_253 , V_7 ) ;
V_253 -> V_130 = V_7 -> V_130 ;
if ( V_253 -> V_117 == V_149 )
V_253 -> V_150 += F_91 ( V_253 ) - V_145 ;
F_213 ( V_253 ) ;
F_214 ( V_253 , V_7 -> V_130 ) ;
V_253 -> V_107 = ( V_253 -> V_108 +
F_215 ( V_7 ) ) ;
F_113 ( V_7 , V_253 -> V_13 , V_250 ) ;
if ( V_248 != F_26 ( V_7 ) -> V_84 )
continue;
if ( ! V_251 ) {
V_253 -> V_117 = V_255 ;
V_253 -> V_114 = F_163 ( V_7 , V_69 ,
F_109 ( V_253 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_59 = F_26 ( V_253 ) -> V_137 ;
F_139 ( V_7 , V_69 ,
F_109 ( V_253 , V_254 ) , V_254 ) ;
while ( V_200 < V_69 + V_11 && V_77 < V_163 ) {
* V_59 = F_26 ( V_7 ) -> V_137 [ V_77 ] ;
F_192 ( V_59 ) ;
V_18 = F_98 ( V_59 ) ;
if ( V_200 < V_69 ) {
V_59 -> V_140 += V_69 - V_200 ;
F_138 ( V_59 , V_69 - V_200 ) ;
}
F_26 ( V_253 ) -> V_88 ++ ;
if ( V_200 + V_18 <= V_69 + V_11 ) {
V_77 ++ ;
V_200 += V_18 ;
} else {
F_138 ( V_59 , V_200 + V_18 - ( V_69 + V_11 ) ) ;
goto V_256;
}
V_59 ++ ;
}
if ( V_200 < V_69 + V_11 ) {
struct V_6 * V_257 = V_248 ;
F_116 ( V_200 + V_248 -> V_11 != V_69 + V_11 ) ;
V_200 += V_248 -> V_11 ;
V_248 = V_248 -> V_83 ;
if ( V_257 -> V_83 ) {
V_257 = F_101 ( V_257 , V_53 ) ;
if ( ! V_257 )
goto V_159;
} else
F_53 ( V_257 ) ;
F_216 ( V_253 ) ;
F_26 ( V_253 ) -> V_84 = V_257 ;
}
V_256:
V_253 -> V_79 = V_11 - V_254 ;
V_253 -> V_11 += V_253 -> V_79 ;
V_253 -> V_40 += V_253 -> V_79 ;
} while ( ( V_69 += V_11 ) < V_7 -> V_11 );
return V_247 ;
V_159:
while ( ( V_7 = V_247 ) ) {
V_247 = V_7 -> V_83 ;
F_49 ( V_7 ) ;
}
return F_217 ( V_159 ) ;
}
int F_218 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_258 = * V_12 ;
struct V_6 * V_253 ;
struct V_31 * V_259 = F_26 ( V_7 ) ;
struct V_31 * V_260 = F_26 ( V_258 ) ;
unsigned int V_145 ;
unsigned int V_11 = F_219 ( V_7 ) ;
unsigned int V_69 = F_220 ( V_7 ) ;
unsigned int V_261 = F_112 ( V_7 ) ;
unsigned int V_262 ;
if ( V_258 -> V_11 + V_11 >= 65536 )
return - V_263 ;
if ( V_260 -> V_84 )
goto V_213;
else if ( V_261 <= V_69 ) {
T_6 * V_59 ;
T_6 * V_264 ;
int V_77 = V_259 -> V_88 ;
int V_88 = V_260 -> V_88 + V_77 ;
V_69 -= V_261 ;
if ( V_88 > V_187 )
return - V_263 ;
V_260 -> V_88 = V_88 ;
V_259 -> V_88 = 0 ;
V_59 = V_260 -> V_137 + V_88 ;
V_264 = V_259 -> V_137 + V_77 ;
do {
* -- V_59 = * -- V_264 ;
} while ( -- V_77 );
V_59 -> V_140 += V_69 ;
F_138 ( V_59 , V_69 ) ;
V_262 = V_7 -> V_40 -
F_22 ( F_108 ( V_7 ) ) ;
V_7 -> V_40 -= V_7 -> V_79 ;
V_7 -> V_11 -= V_7 -> V_79 ;
V_7 -> V_79 = 0 ;
F_221 ( V_7 ) -> free = V_265 ;
goto V_165;
} else if ( V_7 -> V_54 ) {
int V_88 = V_260 -> V_88 ;
T_6 * V_59 = V_260 -> V_137 + V_88 ;
struct V_5 * V_5 = F_44 ( V_7 -> V_12 ) ;
unsigned int V_266 = V_261 - V_69 ;
unsigned int V_267 ;
if ( V_88 + 1 + V_259 -> V_88 > V_187 )
return - V_263 ;
V_267 = V_7 -> V_13 -
( unsigned char * ) F_40 ( V_5 ) +
V_69 ;
V_260 -> V_88 = V_88 + 1 + V_259 -> V_88 ;
V_59 -> V_5 . V_258 = V_5 ;
V_59 -> V_140 = V_267 ;
F_133 ( V_59 , V_266 ) ;
memcpy ( V_59 + 1 , V_259 -> V_137 , sizeof( * V_59 ) * V_259 -> V_88 ) ;
V_262 = V_7 -> V_40 - F_17 ( sizeof( struct V_6 ) ) ;
F_221 ( V_7 ) -> free = V_268 ;
goto V_165;
} else if ( F_219 ( V_258 ) != V_260 -> V_141 )
return - V_263 ;
V_145 = F_91 ( V_258 ) ;
V_253 = F_222 ( V_145 + F_220 ( V_258 ) , V_53 ) ;
if ( F_35 ( ! V_253 ) )
return - V_139 ;
F_83 ( V_253 , V_258 ) ;
V_253 -> V_130 = V_258 -> V_130 ;
F_45 ( V_253 , V_145 ) ;
F_212 ( V_253 , F_220 ( V_258 ) ) ;
F_223 ( V_253 , F_209 ( V_258 ) - V_258 -> V_13 ) ;
F_214 ( V_253 , F_224 ( V_258 ) ) ;
F_225 ( V_253 , F_226 ( V_258 ) ) ;
F_227 ( V_258 , F_220 ( V_258 ) ) ;
memcpy ( F_209 ( V_253 ) , F_209 ( V_258 ) ,
V_258 -> V_13 - F_209 ( V_258 ) ) ;
* F_221 ( V_253 ) = * F_221 ( V_258 ) ;
F_26 ( V_253 ) -> V_84 = V_258 ;
F_26 ( V_253 ) -> V_141 = V_260 -> V_141 ;
V_260 -> V_141 = 0 ;
F_228 ( V_258 ) ;
F_221 ( V_253 ) -> V_269 = V_258 ;
V_253 -> V_79 += V_258 -> V_11 ;
V_253 -> V_40 += V_258 -> V_40 ;
V_253 -> V_11 += V_258 -> V_11 ;
* V_12 = V_253 ;
V_253 -> V_83 = V_258 -> V_83 ;
V_258 -> V_83 = NULL ;
V_258 = V_253 ;
V_213:
V_262 = V_7 -> V_40 ;
if ( V_69 > V_261 ) {
unsigned int V_168 = V_69 - V_261 ;
V_259 -> V_137 [ 0 ] . V_140 += V_168 ;
F_138 ( & V_259 -> V_137 [ 0 ] , V_168 ) ;
V_7 -> V_79 -= V_168 ;
V_7 -> V_11 -= V_168 ;
V_69 = V_261 ;
}
F_227 ( V_7 , V_69 ) ;
F_221 ( V_258 ) -> V_269 -> V_83 = V_7 ;
F_221 ( V_258 ) -> V_269 = V_7 ;
F_228 ( V_7 ) ;
V_165:
F_221 ( V_258 ) -> V_270 ++ ;
V_258 -> V_79 += V_11 ;
V_258 -> V_40 += V_262 ;
V_258 -> V_11 += V_11 ;
F_221 ( V_7 ) -> V_271 = 1 ;
return 0 ;
}
void T_10 F_229 ( void )
{
V_35 = F_230 ( L_3 ,
sizeof( struct V_6 ) ,
0 ,
V_272 | V_273 ,
NULL ) ;
V_34 = F_230 ( L_4 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_4 ) ,
0 ,
V_272 | V_273 ,
NULL ) ;
}
static int
F_231 ( struct V_6 * V_7 , struct V_274 * V_251 , int V_69 , int V_11 )
{
int V_173 = F_112 ( V_7 ) ;
int V_77 , V_175 = V_173 - V_69 ;
struct V_6 * V_174 ;
int V_275 = 0 ;
if ( V_175 > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
F_232 ( V_251 , V_7 -> V_13 + V_69 , V_175 ) ;
V_275 ++ ;
if ( ( V_11 -= V_175 ) == 0 )
return V_275 ;
V_69 += V_175 ;
}
for ( V_77 = 0 ; V_77 < F_26 ( V_7 ) -> V_88 ; V_77 ++ ) {
int V_15 ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + F_98 ( & F_26 ( V_7 ) -> V_137 [ V_77 ] ) ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
T_6 * V_59 = & F_26 ( V_7 ) -> V_137 [ V_77 ] ;
if ( V_175 > V_11 )
V_175 = V_11 ;
F_233 ( & V_251 [ V_275 ] , F_97 ( V_59 ) , V_175 ,
V_59 -> V_140 + V_69 - V_173 ) ;
V_275 ++ ;
if ( ! ( V_11 -= V_175 ) )
return V_275 ;
V_69 += V_175 ;
}
V_173 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_173 > V_69 + V_11 ) ;
V_15 = V_173 + V_174 -> V_11 ;
if ( ( V_175 = V_15 - V_69 ) > 0 ) {
if ( V_175 > V_11 )
V_175 = V_11 ;
V_275 += F_231 ( V_174 , V_251 + V_275 , V_69 - V_173 ,
V_175 ) ;
if ( ( V_11 -= V_175 ) == 0 )
return V_275 ;
V_69 += V_175 ;
}
V_173 = V_15 ;
}
F_116 ( V_11 ) ;
return V_275 ;
}
int F_234 ( struct V_6 * V_7 , struct V_274 * V_251 , int V_69 , int V_11 )
{
int V_276 = F_231 ( V_7 , V_251 , V_69 , V_11 ) ;
F_235 ( & V_251 [ V_276 - 1 ] ) ;
return V_276 ;
}
int F_236 ( struct V_6 * V_7 , int V_277 , struct V_6 * * V_278 )
{
int V_279 ;
int V_275 ;
struct V_6 * V_210 , * * V_280 ;
if ( ( F_119 ( V_7 ) || F_26 ( V_7 ) -> V_88 ) &&
F_136 ( V_7 , F_237 ( V_7 ) - F_112 ( V_7 ) ) == NULL )
return - V_139 ;
if ( ! F_59 ( V_7 ) ) {
if ( F_124 ( V_7 ) < V_277 &&
F_115 ( V_7 , 0 , V_277 - F_124 ( V_7 ) + 128 , V_53 ) )
return - V_139 ;
* V_278 = V_7 ;
return 1 ;
}
V_275 = 1 ;
V_280 = & F_26 ( V_7 ) -> V_84 ;
V_279 = 0 ;
while ( ( V_210 = * V_280 ) != NULL ) {
int V_147 = 0 ;
if ( F_117 ( V_210 ) )
V_279 = 1 ;
if ( V_210 -> V_83 == NULL && V_277 ) {
if ( F_26 ( V_210 ) -> V_88 ||
F_59 ( V_210 ) ||
F_124 ( V_210 ) < V_277 )
V_147 = V_277 + 128 ;
}
if ( V_279 ||
F_119 ( V_210 ) ||
V_147 ||
F_26 ( V_210 ) -> V_88 ||
F_59 ( V_210 ) ) {
struct V_6 * V_151 ;
if ( V_147 == 0 )
V_151 = F_107 ( V_210 , V_53 ) ;
else
V_151 = F_122 ( V_210 ,
F_91 ( V_210 ) ,
V_147 ,
V_53 ) ;
if ( F_35 ( V_151 == NULL ) )
return - V_139 ;
if ( V_210 -> V_129 )
F_238 ( V_151 , V_210 -> V_129 ) ;
V_151 -> V_83 = V_210 -> V_83 ;
* V_280 = V_151 ;
F_49 ( V_210 ) ;
V_210 = V_151 ;
}
V_275 ++ ;
* V_278 = V_210 ;
V_280 = & V_210 -> V_83 ;
}
return V_275 ;
}
static void F_239 ( struct V_6 * V_7 )
{
struct V_181 * V_129 = V_7 -> V_129 ;
F_240 ( V_7 -> V_40 , & V_129 -> V_281 ) ;
}
int F_241 ( struct V_181 * V_129 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_38 ( & V_129 -> V_281 ) + V_7 -> V_40 >=
( unsigned int ) V_129 -> V_282 )
return - V_139 ;
F_242 ( V_7 ) ;
V_7 -> V_129 = V_129 ;
V_7 -> V_97 = F_239 ;
F_204 ( V_7 -> V_40 , & V_129 -> V_281 ) ;
F_243 ( V_7 ) ;
F_177 ( & V_129 -> V_283 , V_7 ) ;
if ( ! F_244 ( V_129 , V_284 ) )
V_129 -> V_285 ( V_129 , V_11 ) ;
return 0 ;
}
void F_245 ( struct V_6 * V_286 ,
struct V_287 * V_288 )
{
struct V_181 * V_129 = V_286 -> V_129 ;
struct V_289 * V_290 ;
struct V_6 * V_7 ;
int V_159 ;
if ( ! V_129 )
return;
V_7 = F_101 ( V_286 , V_53 ) ;
if ( ! V_7 )
return;
if ( V_288 ) {
* F_246 ( V_7 ) =
* V_288 ;
} else {
V_7 -> V_106 = F_247 () ;
}
V_290 = F_248 ( V_7 ) ;
memset ( V_290 , 0 , sizeof( * V_290 ) ) ;
V_290 -> V_291 . V_292 = V_293 ;
V_290 -> V_291 . V_294 = V_295 ;
V_159 = F_241 ( V_129 , V_7 ) ;
if ( V_159 )
F_49 ( V_7 ) ;
}
void F_249 ( struct V_6 * V_7 , bool V_296 )
{
struct V_181 * V_129 = V_7 -> V_129 ;
struct V_289 * V_290 ;
int V_159 ;
V_7 -> V_297 = 1 ;
V_7 -> V_298 = V_296 ;
V_290 = F_248 ( V_7 ) ;
memset ( V_290 , 0 , sizeof( * V_290 ) ) ;
V_290 -> V_291 . V_292 = V_293 ;
V_290 -> V_291 . V_294 = V_299 ;
V_159 = F_241 ( V_129 , V_7 ) ;
if ( V_159 )
F_49 ( V_7 ) ;
}
bool F_250 ( struct V_6 * V_7 , T_11 V_173 , T_11 V_78 )
{
if ( F_35 ( V_173 > F_112 ( V_7 ) ) ||
F_35 ( ( int ) V_173 + V_78 > F_112 ( V_7 ) - 2 ) ) {
F_251 ( L_5 ,
V_173 , V_78 , F_112 ( V_7 ) ) ;
return false ;
}
V_7 -> V_117 = V_149 ;
V_7 -> V_150 = F_91 ( V_7 ) + V_173 ;
V_7 -> V_204 = V_78 ;
return true ;
}
void F_252 ( const struct V_6 * V_7 )
{
F_251 ( L_6 ,
V_7 -> V_16 -> V_17 ) ;
}
void F_253 ( struct V_6 * V_7 , bool V_300 )
{
if ( V_300 ) {
F_62 ( V_7 ) ;
F_29 ( V_35 , V_7 ) ;
} else {
F_77 ( V_7 ) ;
}
}
bool F_254 ( struct V_6 * V_172 , struct V_6 * V_199 ,
bool * V_301 , int * V_262 )
{
int V_77 , V_152 , V_11 = V_199 -> V_11 ;
* V_301 = false ;
if ( F_119 ( V_172 ) )
return false ;
if ( V_11 <= F_124 ( V_172 ) ) {
F_116 ( F_110 ( V_199 , 0 , F_109 ( V_172 , V_11 ) , V_11 ) ) ;
* V_262 = 0 ;
return true ;
}
if ( F_59 ( V_172 ) || F_59 ( V_199 ) )
return false ;
if ( F_112 ( V_199 ) != 0 ) {
struct V_5 * V_5 ;
unsigned int V_69 ;
if ( F_26 ( V_172 ) -> V_88 +
F_26 ( V_199 ) -> V_88 >= V_187 )
return false ;
if ( F_153 ( V_199 ) )
return false ;
V_152 = V_199 -> V_40 - F_17 ( sizeof( struct V_6 ) ) ;
V_5 = F_44 ( V_199 -> V_12 ) ;
V_69 = V_199 -> V_13 - ( unsigned char * ) F_40 ( V_5 ) ;
F_47 ( V_172 , F_26 ( V_172 ) -> V_88 ,
V_5 , V_69 , F_112 ( V_199 ) ) ;
* V_301 = true ;
} else {
if ( F_26 ( V_172 ) -> V_88 +
F_26 ( V_199 ) -> V_88 > V_187 )
return false ;
V_152 = V_199 -> V_40 - F_22 ( F_108 ( V_199 ) ) ;
}
F_255 ( V_152 < V_11 ) ;
memcpy ( F_26 ( V_172 ) -> V_137 + F_26 ( V_172 ) -> V_88 ,
F_26 ( V_199 ) -> V_137 ,
F_26 ( V_199 ) -> V_88 * sizeof( T_6 ) ) ;
F_26 ( V_172 ) -> V_88 += F_26 ( V_199 ) -> V_88 ;
if ( ! F_119 ( V_199 ) )
F_26 ( V_199 ) -> V_88 = 0 ;
for ( V_77 = 0 ; V_77 < F_26 ( V_199 ) -> V_88 ; V_77 ++ )
F_114 ( V_199 , V_77 ) ;
V_172 -> V_40 += V_152 ;
V_172 -> V_11 += V_11 ;
V_172 -> V_79 += V_11 ;
* V_262 = V_152 ;
return true ;
}
