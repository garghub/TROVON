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
unsigned long V_19 ;
F_33 ( V_19 ) ;
V_57 = & F_34 ( V_56 ) ;
if ( F_35 ( ! V_57 -> V_5 ) ) {
V_58:
V_57 -> V_5 = F_36 ( V_28 ) ;
if ( F_35 ( ! V_57 -> V_5 ) )
goto V_15;
V_59:
F_23 ( & V_57 -> V_5 -> V_60 , V_61 ) ;
V_57 -> V_62 = V_61 ;
V_57 -> V_63 = 0 ;
}
if ( V_57 -> V_63 + V_55 > V_64 ) {
if ( ( F_37 ( & V_57 -> V_5 -> V_60 ) == V_57 -> V_62 ) ||
F_38 ( V_57 -> V_62 , & V_57 -> V_5 -> V_60 ) )
goto V_59;
goto V_58;
}
V_13 = F_39 ( V_57 -> V_5 ) + V_57 -> V_63 ;
V_57 -> V_63 += V_55 ;
V_57 -> V_62 -- ;
V_15:
F_40 ( V_19 ) ;
return V_13 ;
}
void * F_41 ( unsigned int V_55 )
{
return F_32 ( V_55 , V_53 | V_65 ) ;
}
struct V_6 * F_42 ( struct V_66 * V_16 ,
unsigned int V_67 , T_2 V_28 )
{
struct V_6 * V_7 = NULL ;
unsigned int V_55 = F_17 ( V_67 + V_68 ) +
F_17 ( sizeof( struct V_31 ) ) ;
if ( V_55 <= V_64 && ! ( V_28 & ( V_69 | V_70 ) ) ) {
void * V_13 ;
if ( F_14 () )
V_28 |= V_37 ;
V_13 = F_32 ( V_55 , V_28 ) ;
if ( F_43 ( V_13 ) ) {
V_7 = F_30 ( V_13 , V_55 ) ;
if ( F_35 ( ! V_7 ) )
F_2 ( F_44 ( V_13 ) ) ;
}
} else {
V_7 = F_13 ( V_67 + V_68 , V_28 ,
V_36 , V_71 ) ;
}
if ( F_43 ( V_7 ) ) {
F_45 ( V_7 , V_68 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_46 ( struct V_6 * V_7 , int V_72 , struct V_5 * V_5 , int V_73 ,
int V_18 , unsigned int V_40 )
{
F_47 ( V_7 , V_72 , V_5 , V_73 , V_18 ) ;
V_7 -> V_11 += V_18 ;
V_7 -> V_74 += V_18 ;
V_7 -> V_40 += V_40 ;
}
static void F_48 ( struct V_6 * * V_75 )
{
struct V_6 * V_76 = * V_75 ;
* V_75 = NULL ;
do {
struct V_6 * V_77 = V_76 ;
V_76 = V_76 -> V_78 ;
F_49 ( V_77 ) ;
} while ( V_76 );
}
static inline void F_50 ( struct V_6 * V_7 )
{
F_48 ( & F_26 ( V_7 ) -> V_79 ) ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_6 * V_76 ;
F_52 (skb, list)
F_53 ( V_76 ) ;
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
if ( ! V_7 -> V_80 ||
! F_57 ( V_7 -> V_81 ? ( 1 << V_82 ) + 1 : 1 ,
& F_26 ( V_7 ) -> V_43 ) ) {
if ( F_26 ( V_7 ) -> V_83 ) {
int V_72 ;
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ )
F_58 ( V_7 , V_72 ) ;
}
if ( F_26 ( V_7 ) -> V_84 & V_85 ) {
struct V_86 * V_87 ;
V_87 = F_26 ( V_7 ) -> V_44 ;
if ( V_87 -> V_88 )
V_87 -> V_88 ( V_87 ) ;
}
if ( F_59 ( V_7 ) )
F_50 ( V_7 ) ;
F_54 ( V_7 ) ;
}
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_6 * V_89 ;
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
case V_90 :
V_46 = ( T_4 * ) ( V_7 + 1 ) ;
V_89 = V_7 - 1 ;
V_7 -> V_49 = V_51 ;
if ( F_61 ( V_46 ) )
F_29 ( V_34 , V_89 ) ;
break;
}
}
static void F_62 ( struct V_6 * V_7 )
{
F_63 ( V_7 ) ;
#ifdef F_64
F_65 ( V_7 -> V_91 ) ;
#endif
if ( V_7 -> V_92 ) {
F_66 ( F_67 () ) ;
V_7 -> V_92 ( V_7 ) ;
}
#if F_68 ( V_93 )
F_69 ( V_7 -> V_94 ) ;
#endif
#ifdef F_70
F_71 ( V_7 -> V_95 ) ;
#endif
#ifdef F_72
F_73 ( V_7 -> V_96 ) ;
#endif
#ifdef F_74
V_7 -> V_97 = 0 ;
#ifdef F_75
V_7 -> V_98 = 0 ;
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
if ( F_43 ( F_37 ( & V_7 -> V_41 ) == 1 ) )
F_78 () ;
else if ( F_43 ( ! F_61 ( & V_7 -> V_41 ) ) )
return;
F_79 ( V_7 , F_80 ( 0 ) ) ;
F_77 ( V_7 ) ;
}
void F_81 ( struct V_6 * V_7 )
{
if ( F_35 ( ! V_7 ) )
return;
if ( F_43 ( F_37 ( & V_7 -> V_41 ) == 1 ) )
F_78 () ;
else if ( F_43 ( ! F_61 ( & V_7 -> V_41 ) ) )
return;
F_82 ( V_7 ) ;
F_77 ( V_7 ) ;
}
void F_83 ( struct V_6 * V_7 )
{
struct V_31 * V_32 ;
F_62 ( V_7 ) ;
V_32 = F_26 ( V_7 ) ;
memset ( V_32 , 0 , F_21 ( struct V_31 , V_43 ) ) ;
F_23 ( & V_32 -> V_43 , 1 ) ;
memset ( V_7 , 0 , F_21 ( struct V_6 , V_14 ) ) ;
V_7 -> V_13 = V_7 -> V_12 + V_68 ;
F_24 ( V_7 ) ;
}
bool F_84 ( struct V_6 * V_7 , int V_99 )
{
if ( ! F_85 ( V_7 , V_99 ) )
return false ;
F_83 ( V_7 ) ;
return true ;
}
static void F_86 ( struct V_6 * V_100 , const struct V_6 * V_101 )
{
V_100 -> V_102 = V_101 -> V_102 ;
V_100 -> V_16 = V_101 -> V_16 ;
V_100 -> V_103 = V_101 -> V_103 ;
V_100 -> V_104 = V_101 -> V_104 ;
V_100 -> V_42 = V_101 -> V_42 ;
F_87 ( V_100 , V_101 ) ;
V_100 -> V_105 = V_101 -> V_105 ;
V_100 -> V_106 = V_101 -> V_106 ;
V_100 -> V_107 = V_101 -> V_107 ;
V_100 -> V_108 = V_101 -> V_108 ;
#ifdef F_64
V_100 -> V_91 = F_88 ( V_101 -> V_91 ) ;
#endif
memcpy ( V_100 -> V_109 , V_101 -> V_109 , sizeof( V_101 -> V_109 ) ) ;
V_100 -> V_110 = V_101 -> V_110 ;
V_100 -> V_111 = V_101 -> V_111 ;
V_100 -> V_112 = V_101 -> V_112 ;
V_100 -> V_113 = V_101 -> V_113 ;
F_89 ( V_100 , V_101 ) ;
V_100 -> V_114 = V_101 -> V_114 ;
#if F_68 ( V_115 )
V_100 -> V_116 = V_101 -> V_116 ;
#endif
V_100 -> V_22 = V_101 -> V_22 ;
V_100 -> V_117 = V_101 -> V_117 ;
V_100 -> V_118 = V_101 -> V_118 ;
V_100 -> V_119 = V_101 -> V_119 ;
F_90 ( V_100 , V_101 ) ;
#if F_68 ( V_120 )
V_100 -> V_121 = V_101 -> V_121 ;
#endif
#ifdef F_74
V_100 -> V_97 = V_101 -> V_97 ;
#ifdef F_75
V_100 -> V_98 = V_101 -> V_98 ;
#endif
#endif
V_100 -> V_122 = V_101 -> V_122 ;
F_91 ( V_100 , V_101 ) ;
}
static struct V_6 * F_92 ( struct V_6 * V_123 , struct V_6 * V_7 )
{
#define F_93 ( T_5 ) n->x = skb->x
V_123 -> V_78 = V_123 -> V_124 = NULL ;
V_123 -> V_125 = NULL ;
F_86 ( V_123 , V_7 ) ;
F_93 ( V_11 ) ;
F_93 ( V_74 ) ;
F_93 ( V_126 ) ;
V_123 -> V_127 = V_7 -> V_81 ? F_94 ( V_7 ) : V_7 -> V_127 ;
V_123 -> V_80 = 1 ;
V_123 -> V_81 = 0 ;
V_123 -> V_92 = NULL ;
F_93 ( V_14 ) ;
F_93 ( V_15 ) ;
F_93 ( V_12 ) ;
F_93 ( V_54 ) ;
F_93 ( V_13 ) ;
F_93 ( V_40 ) ;
F_23 ( & V_123 -> V_41 , 1 ) ;
F_95 ( & ( F_26 ( V_7 ) -> V_43 ) ) ;
V_7 -> V_80 = 1 ;
return V_123 ;
#undef F_93
}
struct V_6 * F_96 ( struct V_6 * V_128 , struct V_6 * V_129 )
{
F_76 ( V_128 ) ;
return F_92 ( V_128 , V_129 ) ;
}
int F_97 ( struct V_6 * V_7 , T_2 V_28 )
{
int V_72 ;
int V_130 = F_26 ( V_7 ) -> V_83 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_86 * V_87 = F_26 ( V_7 ) -> V_44 ;
for ( V_72 = 0 ; V_72 < V_130 ; V_72 ++ ) {
T_3 * V_131 ;
T_6 * V_132 = & F_26 ( V_7 ) -> V_133 [ V_72 ] ;
V_5 = F_36 ( V_28 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_78 = (struct V_5 * ) V_12 -> V_134 ;
F_2 ( V_12 ) ;
V_12 = V_78 ;
}
return - V_135 ;
}
V_131 = F_98 ( F_99 ( V_132 ) ) ;
memcpy ( F_39 ( V_5 ) ,
V_131 + V_132 -> V_136 , F_100 ( V_132 ) ) ;
F_101 ( V_131 ) ;
V_5 -> V_134 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_72 = 0 ; V_72 < V_130 ; V_72 ++ )
F_58 ( V_7 , V_72 ) ;
V_87 -> V_88 ( V_87 ) ;
for ( V_72 = V_130 - 1 ; V_72 >= 0 ; V_72 -- ) {
F_102 ( V_7 , V_72 , V_12 , 0 ,
F_26 ( V_7 ) -> V_133 [ V_72 ] . V_18 ) ;
V_12 = (struct V_5 * ) V_12 -> V_134 ;
}
F_26 ( V_7 ) -> V_84 &= ~ V_85 ;
return 0 ;
}
struct V_6 * F_103 ( struct V_6 * V_7 , T_2 V_28 )
{
struct V_6 * V_123 ;
if ( F_104 ( V_7 , V_28 ) )
return NULL ;
V_123 = V_7 + 1 ;
if ( V_7 -> V_49 == V_50 &&
V_123 -> V_49 == V_51 ) {
T_4 * V_46 = ( T_4 * ) ( V_123 + 1 ) ;
V_123 -> V_49 = V_90 ;
F_95 ( V_46 ) ;
} else {
if ( F_105 ( V_7 ) )
V_28 |= V_37 ;
V_123 = F_31 ( V_35 , V_28 ) ;
if ( ! V_123 )
return NULL ;
F_28 ( V_123 , V_47 ) ;
F_28 ( V_123 , V_48 ) ;
V_123 -> V_49 = V_51 ;
}
return F_92 ( V_123 , V_7 ) ;
}
static void F_106 ( struct V_6 * V_100 , const struct V_6 * V_101 )
{
#ifndef F_25
unsigned long V_63 = V_100 -> V_13 - V_101 -> V_13 ;
#endif
F_86 ( V_100 , V_101 ) ;
#ifndef F_25
V_100 -> V_103 += V_63 ;
V_100 -> V_104 += V_63 ;
if ( F_107 ( V_100 ) )
V_100 -> V_42 += V_63 ;
#endif
F_26 ( V_100 ) -> V_137 = F_26 ( V_101 ) -> V_137 ;
F_26 ( V_100 ) -> V_138 = F_26 ( V_101 ) -> V_138 ;
F_26 ( V_100 ) -> V_139 = F_26 ( V_101 ) -> V_139 ;
}
static inline int F_108 ( const struct V_6 * V_7 )
{
if ( F_105 ( V_7 ) )
return V_36 ;
return 0 ;
}
struct V_6 * F_109 ( const struct V_6 * V_7 , T_2 V_28 )
{
int V_140 = F_94 ( V_7 ) ;
unsigned int V_18 = F_110 ( V_7 ) + V_7 -> V_74 ;
struct V_6 * V_123 = F_13 ( V_18 , V_28 ,
F_108 ( V_7 ) , V_71 ) ;
if ( ! V_123 )
return NULL ;
F_45 ( V_123 , V_140 ) ;
F_111 ( V_123 , V_7 -> V_11 ) ;
if ( F_112 ( V_7 , - V_140 , V_123 -> V_12 , V_140 + V_7 -> V_11 ) )
F_8 () ;
F_106 ( V_123 , V_7 ) ;
return V_123 ;
}
struct V_6 * F_113 ( struct V_6 * V_7 , int V_141 , T_2 V_28 )
{
unsigned int V_18 = F_114 ( V_7 ) + V_141 ;
struct V_6 * V_123 = F_13 ( V_18 , V_28 ,
F_108 ( V_7 ) , V_71 ) ;
if ( ! V_123 )
goto V_27;
F_45 ( V_123 , V_141 ) ;
F_111 ( V_123 , F_114 ( V_7 ) ) ;
F_115 ( V_7 , V_123 -> V_13 , V_123 -> V_11 ) ;
V_123 -> V_40 += V_7 -> V_74 ;
V_123 -> V_74 = V_7 -> V_74 ;
V_123 -> V_11 = V_7 -> V_11 ;
if ( F_26 ( V_7 ) -> V_83 ) {
int V_72 ;
if ( F_104 ( V_7 , V_28 ) ) {
F_49 ( V_123 ) ;
V_123 = NULL ;
goto V_27;
}
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ ) {
F_26 ( V_123 ) -> V_133 [ V_72 ] = F_26 ( V_7 ) -> V_133 [ V_72 ] ;
F_116 ( V_7 , V_72 ) ;
}
F_26 ( V_123 ) -> V_83 = V_72 ;
}
if ( F_59 ( V_7 ) ) {
F_26 ( V_123 ) -> V_79 = F_26 ( V_7 ) -> V_79 ;
F_51 ( V_123 ) ;
}
F_106 ( V_123 , V_7 ) ;
V_27:
return V_123 ;
}
int F_117 ( struct V_6 * V_7 , int V_142 , int V_143 ,
T_2 V_28 )
{
int V_72 ;
T_3 * V_13 ;
int V_18 = V_142 + F_110 ( V_7 ) + V_143 ;
long V_73 ;
F_118 ( V_142 < 0 ) ;
if ( F_119 ( V_7 ) )
F_8 () ;
V_18 = F_17 ( V_18 ) ;
if ( F_105 ( V_7 ) )
V_28 |= V_37 ;
V_13 = F_18 ( V_18 + F_17 ( sizeof( struct V_31 ) ) ,
V_28 , V_71 , NULL ) ;
if ( ! V_13 )
goto V_39;
V_18 = F_19 ( F_20 ( V_13 ) ) ;
memcpy ( V_13 + V_142 , V_7 -> V_12 , F_120 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_31 * ) ( V_13 + V_18 ) ,
F_26 ( V_7 ) ,
F_21 ( struct V_31 , V_133 [ F_26 ( V_7 ) -> V_83 ] ) ) ;
if ( F_121 ( V_7 ) ) {
if ( F_104 ( V_7 , V_28 ) )
goto V_144;
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ )
F_116 ( V_7 , V_72 ) ;
if ( F_59 ( V_7 ) )
F_51 ( V_7 ) ;
F_56 ( V_7 ) ;
} else {
F_54 ( V_7 ) ;
}
V_73 = ( V_13 + V_142 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_54 = 0 ;
V_7 -> V_13 += V_73 ;
#ifdef F_25
V_7 -> V_15 = V_18 ;
V_73 = V_142 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_73 ;
V_7 -> V_103 += V_73 ;
V_7 -> V_104 += V_73 ;
if ( F_107 ( V_7 ) )
V_7 -> V_42 += V_73 ;
if ( V_7 -> V_113 == V_145 )
V_7 -> V_146 += V_142 ;
V_7 -> V_80 = 0 ;
V_7 -> V_127 = 0 ;
V_7 -> V_81 = 0 ;
F_23 ( & F_26 ( V_7 ) -> V_43 , 1 ) ;
return 0 ;
V_144:
F_55 ( V_13 ) ;
V_39:
return - V_135 ;
}
struct V_6 * F_122 ( struct V_6 * V_7 , unsigned int V_141 )
{
struct V_6 * V_147 ;
int V_148 = V_141 - F_94 ( V_7 ) ;
if ( V_148 <= 0 )
V_147 = F_123 ( V_7 , V_53 ) ;
else {
V_147 = F_103 ( V_7 , V_53 ) ;
if ( V_147 && F_117 ( V_147 , F_17 ( V_148 ) , 0 ,
V_53 ) ) {
F_49 ( V_147 ) ;
V_147 = NULL ;
}
}
return V_147 ;
}
struct V_6 * F_124 ( const struct V_6 * V_7 ,
int V_149 , int V_150 ,
T_2 V_28 )
{
struct V_6 * V_123 = F_13 ( V_149 + V_7 -> V_11 + V_150 ,
V_28 , F_108 ( V_7 ) ,
V_71 ) ;
int V_151 = F_94 ( V_7 ) ;
int V_152 , V_153 ;
int V_73 ;
if ( ! V_123 )
return NULL ;
F_45 ( V_123 , V_149 ) ;
F_111 ( V_123 , V_7 -> V_11 ) ;
V_152 = V_151 ;
V_153 = 0 ;
if ( V_149 <= V_152 )
V_152 = V_149 ;
else
V_153 = V_149 - V_152 ;
if ( F_112 ( V_7 , - V_152 , V_123 -> V_12 + V_153 ,
V_7 -> V_11 + V_152 ) )
F_8 () ;
F_106 ( V_123 , V_7 ) ;
V_73 = V_149 - V_151 ;
if ( V_123 -> V_113 == V_145 )
V_123 -> V_146 += V_73 ;
#ifdef F_25
V_123 -> V_103 += V_73 ;
V_123 -> V_104 += V_73 ;
if ( F_107 ( V_7 ) )
V_123 -> V_42 += V_73 ;
#endif
return V_123 ;
}
int F_125 ( struct V_6 * V_7 , int V_154 )
{
int V_155 ;
int V_143 ;
if ( ! F_121 ( V_7 ) && F_126 ( V_7 ) >= V_154 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_154 ) ;
return 0 ;
}
V_143 = V_7 -> V_74 + V_154 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_43 ( F_121 ( V_7 ) || V_143 > 0 ) ) {
V_155 = F_117 ( V_7 , 0 , V_143 , V_53 ) ;
if ( F_35 ( V_155 ) )
goto V_156;
}
V_155 = F_127 ( V_7 ) ;
if ( F_35 ( V_155 ) )
goto V_156;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_154 ) ;
return 0 ;
V_156:
F_49 ( V_7 ) ;
return V_155 ;
}
unsigned char * F_111 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_157 = F_120 ( V_7 ) ;
F_128 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_35 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_80 ( 0 ) ) ;
return V_157 ;
}
unsigned char * F_129 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_35 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_80 ( 0 ) ) ;
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
struct V_6 * * V_158 ;
struct V_6 * V_159 ;
int V_63 = F_114 ( V_7 ) ;
int V_160 = F_26 ( V_7 ) -> V_83 ;
int V_72 ;
int V_155 ;
if ( F_121 ( V_7 ) &&
F_35 ( ( V_155 = F_117 ( V_7 , 0 , 0 , V_53 ) ) ) )
return V_155 ;
V_72 = 0 ;
if ( V_63 >= V_11 )
goto V_161;
for (; V_72 < V_160 ; V_72 ++ ) {
int V_15 = V_63 + F_100 ( & F_26 ( V_7 ) -> V_133 [ V_72 ] ) ;
if ( V_15 < V_11 ) {
V_63 = V_15 ;
continue;
}
F_135 ( & F_26 ( V_7 ) -> V_133 [ V_72 ++ ] , V_11 - V_63 ) ;
V_161:
F_26 ( V_7 ) -> V_83 = V_72 ;
for (; V_72 < V_160 ; V_72 ++ )
F_58 ( V_7 , V_72 ) ;
if ( F_59 ( V_7 ) )
F_50 ( V_7 ) ;
goto V_162;
}
for ( V_158 = & F_26 ( V_7 ) -> V_79 ; ( V_159 = * V_158 ) ;
V_158 = & V_159 -> V_78 ) {
int V_15 = V_63 + V_159 -> V_11 ;
if ( F_119 ( V_159 ) ) {
struct V_6 * V_163 ;
V_163 = F_103 ( V_159 , V_53 ) ;
if ( F_35 ( ! V_163 ) )
return - V_135 ;
V_163 -> V_78 = V_159 -> V_78 ;
F_81 ( V_159 ) ;
V_159 = V_163 ;
* V_158 = V_159 ;
}
if ( V_15 < V_11 ) {
V_63 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_35 ( ( V_155 = F_136 ( V_159 , V_11 - V_63 ) ) ) )
return V_155 ;
if ( V_159 -> V_78 )
F_48 ( & V_159 -> V_78 ) ;
break;
}
V_162:
if ( V_11 > F_114 ( V_7 ) ) {
V_7 -> V_74 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_74 = 0 ;
F_137 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_138 ( struct V_6 * V_7 , int V_148 )
{
int V_72 , V_164 , V_165 = ( V_7 -> V_14 + V_148 ) - V_7 -> V_15 ;
if ( V_165 > 0 || F_121 ( V_7 ) ) {
if ( F_117 ( V_7 , 0 , V_165 > 0 ? V_165 + 128 : 0 ,
V_53 ) )
return NULL ;
}
if ( F_112 ( V_7 , F_114 ( V_7 ) , F_120 ( V_7 ) , V_148 ) )
F_8 () ;
if ( ! F_59 ( V_7 ) )
goto V_166;
V_165 = V_148 ;
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ ) {
int V_18 = F_100 ( & F_26 ( V_7 ) -> V_133 [ V_72 ] ) ;
if ( V_18 >= V_165 )
goto V_166;
V_165 -= V_18 ;
}
if ( V_165 ) {
struct V_6 * V_76 = F_26 ( V_7 ) -> V_79 ;
struct V_6 * V_167 = NULL ;
struct V_6 * V_168 = NULL ;
do {
F_118 ( ! V_76 ) ;
if ( V_76 -> V_11 <= V_165 ) {
V_165 -= V_76 -> V_11 ;
V_76 = V_76 -> V_78 ;
V_168 = V_76 ;
} else {
if ( F_119 ( V_76 ) ) {
V_167 = F_103 ( V_76 , V_53 ) ;
if ( ! V_167 )
return NULL ;
V_168 = V_76 -> V_78 ;
V_76 = V_167 ;
} else {
V_168 = V_76 ;
}
if ( ! F_139 ( V_76 , V_165 ) ) {
F_49 ( V_167 ) ;
return NULL ;
}
break;
}
} while ( V_165 );
while ( ( V_76 = F_26 ( V_7 ) -> V_79 ) != V_168 ) {
F_26 ( V_7 ) -> V_79 = V_76 -> V_78 ;
F_49 ( V_76 ) ;
}
if ( V_167 ) {
V_167 -> V_78 = V_76 ;
F_26 ( V_7 ) -> V_79 = V_167 ;
}
}
V_166:
V_165 = V_148 ;
V_164 = 0 ;
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ ) {
int V_18 = F_100 ( & F_26 ( V_7 ) -> V_133 [ V_72 ] ) ;
if ( V_18 <= V_165 ) {
F_58 ( V_7 , V_72 ) ;
V_165 -= V_18 ;
} else {
F_26 ( V_7 ) -> V_133 [ V_164 ] = F_26 ( V_7 ) -> V_133 [ V_72 ] ;
if ( V_165 ) {
F_26 ( V_7 ) -> V_133 [ V_164 ] . V_136 += V_165 ;
F_140 ( & F_26 ( V_7 ) -> V_133 [ V_164 ] , V_165 ) ;
V_165 = 0 ;
}
V_164 ++ ;
}
}
F_26 ( V_7 ) -> V_83 = V_164 ;
V_7 -> V_14 += V_148 ;
V_7 -> V_74 -= V_148 ;
return F_120 ( V_7 ) ;
}
int F_112 ( const struct V_6 * V_7 , int V_63 , void * V_169 , int V_11 )
{
int V_170 = F_114 ( V_7 ) ;
struct V_6 * V_171 ;
int V_72 , V_172 ;
if ( V_63 > ( int ) V_7 -> V_11 - V_11 )
goto V_173;
if ( ( V_172 = V_170 - V_63 ) > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
F_141 ( V_7 , V_63 , V_169 , V_172 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return 0 ;
V_63 += V_172 ;
V_169 += V_172 ;
}
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ ) {
int V_15 ;
T_6 * V_132 = & F_26 ( V_7 ) -> V_133 [ V_72 ] ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + F_100 ( V_132 ) ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
T_3 * V_131 ;
if ( V_172 > V_11 )
V_172 = V_11 ;
V_131 = F_98 ( F_99 ( V_132 ) ) ;
memcpy ( V_169 ,
V_131 + V_132 -> V_136 + V_63 - V_170 ,
V_172 ) ;
F_101 ( V_131 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return 0 ;
V_63 += V_172 ;
V_169 += V_172 ;
}
V_170 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + V_171 -> V_11 ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
if ( F_112 ( V_171 , V_63 - V_170 , V_169 , V_172 ) )
goto V_173;
if ( ( V_11 -= V_172 ) == 0 )
return 0 ;
V_63 += V_172 ;
V_169 += V_172 ;
}
V_170 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_173:
return - V_174 ;
}
static void F_142 ( struct V_175 * V_176 , unsigned int V_72 )
{
F_2 ( V_176 -> V_177 [ V_72 ] ) ;
}
static struct V_5 * F_143 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_63 ,
struct V_6 * V_7 , struct V_178 * V_125 )
{
struct V_5 * V_179 = V_125 -> V_180 ;
unsigned int V_73 ;
if ( ! V_179 ) {
V_181:
V_179 = V_125 -> V_180 = F_144 ( V_125 -> V_182 , 0 ) ;
if ( ! V_179 )
return NULL ;
V_73 = V_125 -> V_183 = 0 ;
} else {
unsigned int V_184 ;
if ( F_145 ( V_179 ) == 1 )
V_125 -> V_183 = 0 ;
V_73 = V_125 -> V_183 ;
V_184 = V_64 - V_73 ;
if ( V_184 < 64 && V_184 < * V_11 ) {
F_2 ( V_179 ) ;
goto V_181;
}
* V_11 = F_146 (unsigned int, *len, mlen) ;
}
memcpy ( F_39 ( V_179 ) + V_73 , F_39 ( V_5 ) + * V_63 , * V_11 ) ;
V_125 -> V_183 += * V_11 ;
* V_63 = V_73 ;
return V_179 ;
}
static bool F_147 ( const struct V_175 * V_176 ,
struct V_5 * V_5 ,
unsigned int V_63 )
{
return V_176 -> V_185 &&
V_176 -> V_177 [ V_176 -> V_185 - 1 ] == V_5 &&
( V_176 -> V_186 [ V_176 -> V_185 - 1 ] . V_63 +
V_176 -> V_186 [ V_176 -> V_185 - 1 ] . V_11 == V_63 ) ;
}
static bool F_148 ( struct V_175 * V_176 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_63 ,
struct V_6 * V_7 , bool V_187 ,
struct V_178 * V_125 )
{
if ( F_35 ( V_176 -> V_185 == V_188 ) )
return true ;
if ( V_187 ) {
V_5 = F_143 ( V_5 , V_11 , & V_63 , V_7 , V_125 ) ;
if ( ! V_5 )
return true ;
}
if ( F_147 ( V_176 , V_5 , V_63 ) ) {
V_176 -> V_186 [ V_176 -> V_185 - 1 ] . V_11 += * V_11 ;
return false ;
}
F_4 ( V_5 ) ;
V_176 -> V_177 [ V_176 -> V_185 ] = V_5 ;
V_176 -> V_186 [ V_176 -> V_185 ] . V_11 = * V_11 ;
V_176 -> V_186 [ V_176 -> V_185 ] . V_63 = V_63 ;
V_176 -> V_185 ++ ;
return false ;
}
static inline void F_149 ( struct V_5 * * V_5 , unsigned int * V_189 ,
unsigned int * V_190 , unsigned int V_73 )
{
unsigned long V_123 ;
* V_189 += V_73 ;
V_123 = * V_189 / V_64 ;
if ( V_123 )
* V_5 = F_150 ( * V_5 , V_123 ) ;
* V_189 = * V_189 % V_64 ;
* V_190 -= V_73 ;
}
static bool F_151 ( struct V_5 * V_5 , unsigned int V_189 ,
unsigned int V_190 , unsigned int * V_73 ,
unsigned int * V_11 , struct V_6 * V_7 ,
struct V_175 * V_176 , bool V_187 ,
struct V_178 * V_125 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return true ;
if ( * V_73 >= V_190 ) {
* V_73 -= V_190 ;
return false ;
}
if ( * V_73 ) {
F_149 ( & V_5 , & V_189 , & V_190 , * V_73 ) ;
* V_73 = 0 ;
}
do {
unsigned int V_191 = F_152 ( * V_11 , V_190 ) ;
V_191 = F_146 (unsigned int, flen, PAGE_SIZE - poff) ;
if ( F_148 ( V_176 , V_2 , V_5 , & V_191 , V_189 , V_7 , V_187 , V_125 ) )
return true ;
F_149 ( & V_5 , & V_189 , & V_190 , V_191 ) ;
* V_11 -= V_191 ;
} while ( * V_11 && V_190 );
return false ;
}
static bool F_153 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_63 , unsigned int * V_11 ,
struct V_175 * V_176 , struct V_178 * V_125 )
{
int V_192 ;
if ( F_151 ( F_154 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_64 - 1 ) ,
F_114 ( V_7 ) ,
V_63 , V_11 , V_7 , V_176 ,
F_155 ( V_7 ) ,
V_125 , V_2 ) )
return true ;
for ( V_192 = 0 ; V_192 < F_26 ( V_7 ) -> V_83 ; V_192 ++ ) {
const T_6 * V_132 = & F_26 ( V_7 ) -> V_133 [ V_192 ] ;
if ( F_151 ( F_99 ( V_132 ) ,
V_132 -> V_136 , F_100 ( V_132 ) ,
V_63 , V_11 , V_7 , V_176 , false , V_125 , V_2 ) )
return true ;
}
return false ;
}
int F_156 ( struct V_6 * V_7 , unsigned int V_63 ,
struct V_1 * V_2 , unsigned int V_193 ,
unsigned int V_19 )
{
struct V_194 V_186 [ V_188 ] ;
struct V_5 * V_177 [ V_188 ] ;
struct V_175 V_176 = {
. V_177 = V_177 ,
. V_186 = V_186 ,
. V_195 = V_188 ,
. V_19 = V_19 ,
. V_196 = & V_197 ,
. V_198 = F_142 ,
} ;
struct V_6 * V_171 ;
struct V_178 * V_125 = V_7 -> V_125 ;
int V_199 = 0 ;
if ( F_153 ( V_7 , V_2 , & V_63 , & V_193 , & V_176 , V_125 ) )
goto V_162;
else if ( ! V_193 )
goto V_162;
F_52 (skb, frag_iter) {
if ( ! V_193 )
break;
if ( F_153 ( V_171 , V_2 , & V_63 , & V_193 , & V_176 , V_125 ) )
break;
}
V_162:
if ( V_176 . V_185 ) {
F_157 ( V_125 ) ;
V_199 = F_158 ( V_2 , & V_176 ) ;
F_159 ( V_125 ) ;
}
return V_199 ;
}
int F_160 ( struct V_6 * V_7 , int V_63 , const void * V_200 , int V_11 )
{
int V_170 = F_114 ( V_7 ) ;
struct V_6 * V_171 ;
int V_72 , V_172 ;
if ( V_63 > ( int ) V_7 -> V_11 - V_11 )
goto V_173;
if ( ( V_172 = V_170 - V_63 ) > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
F_161 ( V_7 , V_63 , V_200 , V_172 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return 0 ;
V_63 += V_172 ;
V_200 += V_172 ;
}
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ ) {
T_6 * V_159 = & F_26 ( V_7 ) -> V_133 [ V_72 ] ;
int V_15 ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + F_100 ( V_159 ) ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
T_3 * V_131 ;
if ( V_172 > V_11 )
V_172 = V_11 ;
V_131 = F_98 ( F_99 ( V_159 ) ) ;
memcpy ( V_131 + V_159 -> V_136 + V_63 - V_170 ,
V_200 , V_172 ) ;
F_101 ( V_131 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return 0 ;
V_63 += V_172 ;
V_200 += V_172 ;
}
V_170 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + V_171 -> V_11 ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
if ( F_160 ( V_171 , V_63 - V_170 ,
V_200 , V_172 ) )
goto V_173;
if ( ( V_11 -= V_172 ) == 0 )
return 0 ;
V_63 += V_172 ;
V_200 += V_172 ;
}
V_170 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_173:
return - V_174 ;
}
T_7 F_162 ( const struct V_6 * V_7 , int V_63 ,
int V_11 , T_7 V_110 )
{
int V_170 = F_114 ( V_7 ) ;
int V_72 , V_172 = V_170 - V_63 ;
struct V_6 * V_171 ;
int V_201 = 0 ;
if ( V_172 > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
V_110 = F_163 ( V_7 -> V_13 + V_63 , V_172 , V_110 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return V_110 ;
V_63 += V_172 ;
V_201 = V_172 ;
}
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ ) {
int V_15 ;
T_6 * V_159 = & F_26 ( V_7 ) -> V_133 [ V_72 ] ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + F_100 ( V_159 ) ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
T_7 V_202 ;
T_3 * V_131 ;
if ( V_172 > V_11 )
V_172 = V_11 ;
V_131 = F_98 ( F_99 ( V_159 ) ) ;
V_202 = F_163 ( V_131 + V_159 -> V_136 +
V_63 - V_170 , V_172 , 0 ) ;
F_101 ( V_131 ) ;
V_110 = F_164 ( V_110 , V_202 , V_201 ) ;
if ( ! ( V_11 -= V_172 ) )
return V_110 ;
V_63 += V_172 ;
V_201 += V_172 ;
}
V_170 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + V_171 -> V_11 ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
T_7 V_202 ;
if ( V_172 > V_11 )
V_172 = V_11 ;
V_202 = F_162 ( V_171 , V_63 - V_170 ,
V_172 , 0 ) ;
V_110 = F_164 ( V_110 , V_202 , V_201 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return V_110 ;
V_63 += V_172 ;
V_201 += V_172 ;
}
V_170 = V_15 ;
}
F_118 ( V_11 ) ;
return V_110 ;
}
T_7 F_165 ( const struct V_6 * V_7 , int V_63 ,
T_3 * V_169 , int V_11 , T_7 V_110 )
{
int V_170 = F_114 ( V_7 ) ;
int V_72 , V_172 = V_170 - V_63 ;
struct V_6 * V_171 ;
int V_201 = 0 ;
if ( V_172 > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
V_110 = F_166 ( V_7 -> V_13 + V_63 , V_169 ,
V_172 , V_110 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return V_110 ;
V_63 += V_172 ;
V_169 += V_172 ;
V_201 = V_172 ;
}
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ ) {
int V_15 ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + F_100 ( & F_26 ( V_7 ) -> V_133 [ V_72 ] ) ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
T_7 V_202 ;
T_3 * V_131 ;
T_6 * V_159 = & F_26 ( V_7 ) -> V_133 [ V_72 ] ;
if ( V_172 > V_11 )
V_172 = V_11 ;
V_131 = F_98 ( F_99 ( V_159 ) ) ;
V_202 = F_166 ( V_131 +
V_159 -> V_136 +
V_63 - V_170 , V_169 ,
V_172 , 0 ) ;
F_101 ( V_131 ) ;
V_110 = F_164 ( V_110 , V_202 , V_201 ) ;
if ( ! ( V_11 -= V_172 ) )
return V_110 ;
V_63 += V_172 ;
V_169 += V_172 ;
V_201 += V_172 ;
}
V_170 = V_15 ;
}
F_52 (skb, frag_iter) {
T_7 V_202 ;
int V_15 ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + V_171 -> V_11 ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
V_202 = F_165 ( V_171 ,
V_63 - V_170 ,
V_169 , V_172 , 0 ) ;
V_110 = F_164 ( V_110 , V_202 , V_201 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return V_110 ;
V_63 += V_172 ;
V_169 += V_172 ;
V_201 += V_172 ;
}
V_170 = V_15 ;
}
F_118 ( V_11 ) ;
return V_110 ;
}
void F_167 ( const struct V_6 * V_7 , T_3 * V_169 )
{
T_7 V_110 ;
long V_203 ;
if ( V_7 -> V_113 == V_145 )
V_203 = F_168 ( V_7 ) ;
else
V_203 = F_114 ( V_7 ) ;
F_118 ( V_203 > F_114 ( V_7 ) ) ;
F_115 ( V_7 , V_169 , V_203 ) ;
V_110 = 0 ;
if ( V_203 != V_7 -> V_11 )
V_110 = F_165 ( V_7 , V_203 , V_169 + V_203 ,
V_7 -> V_11 - V_203 , 0 ) ;
if ( V_7 -> V_113 == V_145 ) {
long V_204 = V_203 + V_7 -> V_205 ;
* ( ( V_206 * ) ( V_169 + V_204 ) ) = F_169 ( V_110 ) ;
}
}
struct V_6 * F_170 ( struct V_207 * V_76 )
{
unsigned long V_19 ;
struct V_6 * V_208 ;
F_171 ( & V_76 -> V_209 , V_19 ) ;
V_208 = F_172 ( V_76 ) ;
F_173 ( & V_76 -> V_209 , V_19 ) ;
return V_208 ;
}
struct V_6 * F_174 ( struct V_207 * V_76 )
{
unsigned long V_19 ;
struct V_6 * V_208 ;
F_171 ( & V_76 -> V_209 , V_19 ) ;
V_208 = F_175 ( V_76 ) ;
F_173 ( & V_76 -> V_209 , V_19 ) ;
return V_208 ;
}
void F_176 ( struct V_207 * V_76 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_170 ( V_76 ) ) != NULL )
F_49 ( V_7 ) ;
}
void F_177 ( struct V_207 * V_76 , struct V_6 * V_210 )
{
unsigned long V_19 ;
F_171 ( & V_76 -> V_209 , V_19 ) ;
F_178 ( V_76 , V_210 ) ;
F_173 ( & V_76 -> V_209 , V_19 ) ;
}
void F_179 ( struct V_207 * V_76 , struct V_6 * V_210 )
{
unsigned long V_19 ;
F_171 ( & V_76 -> V_209 , V_19 ) ;
F_180 ( V_76 , V_210 ) ;
F_173 ( & V_76 -> V_209 , V_19 ) ;
}
void F_181 ( struct V_6 * V_7 , struct V_207 * V_76 )
{
unsigned long V_19 ;
F_171 ( & V_76 -> V_209 , V_19 ) ;
F_182 ( V_7 , V_76 ) ;
F_173 ( & V_76 -> V_209 , V_19 ) ;
}
void F_183 ( struct V_6 * V_101 , struct V_6 * V_210 , struct V_207 * V_76 )
{
unsigned long V_19 ;
F_171 ( & V_76 -> V_209 , V_19 ) ;
F_184 ( V_76 , V_101 , V_210 ) ;
F_173 ( & V_76 -> V_209 , V_19 ) ;
}
void F_185 ( struct V_6 * V_101 , struct V_6 * V_210 , struct V_207 * V_76 )
{
unsigned long V_19 ;
F_171 ( & V_76 -> V_209 , V_19 ) ;
F_186 ( V_210 , V_101 -> V_124 , V_101 , V_76 ) ;
F_173 ( & V_76 -> V_209 , V_19 ) ;
}
static inline void F_187 ( struct V_6 * V_7 ,
struct V_6 * V_211 ,
const T_8 V_11 , const int V_201 )
{
int V_72 ;
F_141 ( V_7 , V_11 , F_111 ( V_211 , V_201 - V_11 ) ,
V_201 - V_11 ) ;
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ )
F_26 ( V_211 ) -> V_133 [ V_72 ] = F_26 ( V_7 ) -> V_133 [ V_72 ] ;
F_26 ( V_211 ) -> V_83 = F_26 ( V_7 ) -> V_83 ;
F_26 ( V_7 ) -> V_83 = 0 ;
V_211 -> V_74 = V_7 -> V_74 ;
V_211 -> V_11 += V_211 -> V_74 ;
V_7 -> V_74 = 0 ;
V_7 -> V_11 = V_11 ;
F_137 ( V_7 , V_11 ) ;
}
static inline void F_188 ( struct V_6 * V_7 ,
struct V_6 * V_211 ,
const T_8 V_11 , int V_201 )
{
int V_72 , V_164 = 0 ;
const int V_160 = F_26 ( V_7 ) -> V_83 ;
F_26 ( V_7 ) -> V_83 = 0 ;
V_211 -> V_11 = V_211 -> V_74 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_74 = V_11 - V_201 ;
for ( V_72 = 0 ; V_72 < V_160 ; V_72 ++ ) {
int V_18 = F_100 ( & F_26 ( V_7 ) -> V_133 [ V_72 ] ) ;
if ( V_201 + V_18 > V_11 ) {
F_26 ( V_211 ) -> V_133 [ V_164 ] = F_26 ( V_7 ) -> V_133 [ V_72 ] ;
if ( V_201 < V_11 ) {
F_116 ( V_7 , V_72 ) ;
F_26 ( V_211 ) -> V_133 [ 0 ] . V_136 += V_11 - V_201 ;
F_140 ( & F_26 ( V_211 ) -> V_133 [ 0 ] , V_11 - V_201 ) ;
F_135 ( & F_26 ( V_7 ) -> V_133 [ V_72 ] , V_11 - V_201 ) ;
F_26 ( V_7 ) -> V_83 ++ ;
}
V_164 ++ ;
} else
F_26 ( V_7 ) -> V_83 ++ ;
V_201 += V_18 ;
}
F_26 ( V_211 ) -> V_83 = V_164 ;
}
void F_189 ( struct V_6 * V_7 , struct V_6 * V_211 , const T_8 V_11 )
{
int V_201 = F_114 ( V_7 ) ;
if ( V_11 < V_201 )
F_187 ( V_7 , V_211 , V_11 , V_201 ) ;
else
F_188 ( V_7 , V_211 , V_11 , V_201 ) ;
}
static int F_190 ( struct V_6 * V_7 )
{
return F_121 ( V_7 ) && F_117 ( V_7 , 0 , 0 , V_53 ) ;
}
int F_191 ( struct V_6 * V_212 , struct V_6 * V_7 , int V_213 )
{
int V_200 , V_169 , V_214 , V_215 ;
struct V_216 * V_217 , * V_218 ;
F_118 ( V_213 > V_7 -> V_11 ) ;
F_118 ( F_114 ( V_7 ) ) ;
V_215 = V_213 ;
V_200 = 0 ;
V_169 = F_26 ( V_212 ) -> V_83 ;
V_217 = & F_26 ( V_7 ) -> V_133 [ V_200 ] ;
if ( ! V_169 ||
! F_192 ( V_212 , V_169 , F_99 ( V_217 ) ,
V_217 -> V_136 ) ) {
V_214 = - 1 ;
} else {
V_214 = V_169 - 1 ;
V_215 -= F_100 ( V_217 ) ;
if ( V_215 < 0 ) {
if ( F_190 ( V_7 ) ||
F_190 ( V_212 ) )
return 0 ;
V_217 = & F_26 ( V_7 ) -> V_133 [ V_200 ] ;
V_218 = & F_26 ( V_212 ) -> V_133 [ V_214 ] ;
F_193 ( V_218 , V_213 ) ;
F_140 ( V_217 , V_213 ) ;
V_217 -> V_136 += V_213 ;
goto V_219;
}
V_200 ++ ;
}
if ( ( V_213 == V_7 -> V_11 ) &&
( F_26 ( V_7 ) -> V_83 - V_200 ) > ( V_188 - V_169 ) )
return 0 ;
if ( F_190 ( V_7 ) || F_190 ( V_212 ) )
return 0 ;
while ( ( V_215 > 0 ) && ( V_200 < F_26 ( V_7 ) -> V_83 ) ) {
if ( V_169 == V_188 )
return 0 ;
V_217 = & F_26 ( V_7 ) -> V_133 [ V_200 ] ;
V_218 = & F_26 ( V_212 ) -> V_133 [ V_169 ] ;
if ( V_215 >= F_100 ( V_217 ) ) {
* V_218 = * V_217 ;
V_215 -= F_100 ( V_217 ) ;
V_200 ++ ;
V_169 ++ ;
} else {
F_194 ( V_217 ) ;
V_218 -> V_5 = V_217 -> V_5 ;
V_218 -> V_136 = V_217 -> V_136 ;
F_135 ( V_218 , V_215 ) ;
V_217 -> V_136 += V_215 ;
F_140 ( V_217 , V_215 ) ;
V_215 = 0 ;
V_169 ++ ;
break;
}
}
F_26 ( V_212 ) -> V_83 = V_169 ;
if ( V_214 >= 0 ) {
V_217 = & F_26 ( V_7 ) -> V_133 [ 0 ] ;
V_218 = & F_26 ( V_212 ) -> V_133 [ V_214 ] ;
F_193 ( V_218 , F_100 ( V_217 ) ) ;
F_195 ( V_217 ) ;
}
V_169 = 0 ;
while ( V_200 < F_26 ( V_7 ) -> V_83 )
F_26 ( V_7 ) -> V_133 [ V_169 ++ ] = F_26 ( V_7 ) -> V_133 [ V_200 ++ ] ;
F_26 ( V_7 ) -> V_83 = V_169 ;
F_118 ( V_215 > 0 && ! F_26 ( V_7 ) -> V_83 ) ;
V_219:
V_212 -> V_113 = V_145 ;
V_7 -> V_113 = V_145 ;
V_7 -> V_11 -= V_213 ;
V_7 -> V_74 -= V_213 ;
V_7 -> V_40 -= V_213 ;
V_212 -> V_11 += V_213 ;
V_212 -> V_74 += V_213 ;
V_212 -> V_40 += V_213 ;
return V_213 ;
}
void F_196 ( struct V_6 * V_7 , unsigned int V_200 ,
unsigned int V_169 , struct V_220 * V_221 )
{
V_221 -> V_222 = V_200 ;
V_221 -> V_223 = V_169 ;
V_221 -> V_224 = V_221 -> V_225 = V_7 ;
V_221 -> V_226 = V_221 -> V_227 = 0 ;
V_221 -> V_228 = NULL ;
}
unsigned int F_197 ( unsigned int V_229 , const T_3 * * V_13 ,
struct V_220 * V_221 )
{
unsigned int V_230 , V_231 = V_229 + V_221 -> V_222 ;
T_6 * V_159 ;
if ( F_35 ( V_231 >= V_221 -> V_223 ) )
return 0 ;
V_232:
V_230 = F_114 ( V_221 -> V_225 ) + V_221 -> V_227 ;
if ( V_231 < V_230 && ! V_221 -> V_228 ) {
* V_13 = V_221 -> V_225 -> V_13 + ( V_231 - V_221 -> V_227 ) ;
return V_230 - V_231 ;
}
if ( V_221 -> V_226 == 0 && ! V_221 -> V_228 )
V_221 -> V_227 += F_114 ( V_221 -> V_225 ) ;
while ( V_221 -> V_226 < F_26 ( V_221 -> V_225 ) -> V_83 ) {
V_159 = & F_26 ( V_221 -> V_225 ) -> V_133 [ V_221 -> V_226 ] ;
V_230 = F_100 ( V_159 ) + V_221 -> V_227 ;
if ( V_231 < V_230 ) {
if ( ! V_221 -> V_228 )
V_221 -> V_228 = F_98 ( F_99 ( V_159 ) ) ;
* V_13 = ( T_3 * ) V_221 -> V_228 + V_159 -> V_136 +
( V_231 - V_221 -> V_227 ) ;
return V_230 - V_231 ;
}
if ( V_221 -> V_228 ) {
F_101 ( V_221 -> V_228 ) ;
V_221 -> V_228 = NULL ;
}
V_221 -> V_226 ++ ;
V_221 -> V_227 += F_100 ( V_159 ) ;
}
if ( V_221 -> V_228 ) {
F_101 ( V_221 -> V_228 ) ;
V_221 -> V_228 = NULL ;
}
if ( V_221 -> V_224 == V_221 -> V_225 && F_59 ( V_221 -> V_224 ) ) {
V_221 -> V_225 = F_26 ( V_221 -> V_224 ) -> V_79 ;
V_221 -> V_226 = 0 ;
goto V_232;
} else if ( V_221 -> V_225 -> V_78 ) {
V_221 -> V_225 = V_221 -> V_225 -> V_78 ;
V_221 -> V_226 = 0 ;
goto V_232;
}
return 0 ;
}
void F_198 ( struct V_220 * V_221 )
{
if ( V_221 -> V_228 )
F_101 ( V_221 -> V_228 ) ;
}
static unsigned int F_199 ( unsigned int V_63 , const T_3 * * V_233 ,
struct V_234 * V_235 ,
struct V_236 * V_237 )
{
return F_197 ( V_63 , V_233 , F_200 ( V_237 ) ) ;
}
static void F_201 ( struct V_234 * V_235 , struct V_236 * V_237 )
{
F_198 ( F_200 ( V_237 ) ) ;
}
unsigned int F_202 ( struct V_6 * V_7 , unsigned int V_200 ,
unsigned int V_169 , struct V_234 * V_238 ,
struct V_236 * V_237 )
{
unsigned int V_199 ;
V_238 -> V_239 = F_199 ;
V_238 -> V_240 = F_201 ;
F_196 ( V_7 , V_200 , V_169 , F_200 ( V_237 ) ) ;
V_199 = F_203 ( V_238 , V_237 ) ;
return ( V_199 <= V_169 - V_200 ? V_199 : V_241 ) ;
}
int F_204 ( struct V_178 * V_125 , struct V_6 * V_7 ,
int (* F_205)( void * V_200 , char * V_169 , int V_63 ,
int V_11 , int V_242 , struct V_6 * V_7 ) ,
void * V_200 , int V_67 )
{
int V_243 = 0 ;
T_6 * V_159 = NULL ;
struct V_5 * V_5 = NULL ;
int V_172 , V_244 ;
int V_63 = 0 ;
int V_199 ;
do {
V_243 = F_26 ( V_7 ) -> V_83 ;
if ( V_243 >= V_188 )
return - V_174 ;
V_5 = F_144 ( V_125 -> V_182 , 0 ) ;
if ( V_5 == NULL )
return - V_135 ;
F_47 ( V_7 , V_243 , V_5 , 0 , 0 ) ;
V_7 -> V_40 += V_64 ;
F_206 ( V_64 , & V_125 -> V_245 ) ;
V_243 = F_26 ( V_7 ) -> V_83 ;
V_159 = & F_26 ( V_7 ) -> V_133 [ V_243 - 1 ] ;
V_244 = V_64 - V_159 -> V_136 ;
V_172 = ( V_67 > V_244 ) ? V_244 : V_67 ;
V_199 = F_205 ( V_200 , F_207 ( V_159 ) + F_100 ( V_159 ) ,
V_63 , V_172 , 0 , V_7 ) ;
if ( V_199 < 0 )
return - V_174 ;
F_193 ( V_159 , V_172 ) ;
V_7 -> V_11 += V_172 ;
V_7 -> V_74 += V_172 ;
V_63 += V_172 ;
V_67 -= V_172 ;
} while ( V_67 > 0 );
return 0 ;
}
unsigned char * F_208 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_118 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_118 ( V_7 -> V_11 < V_7 -> V_74 ) ;
F_209 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_210 ( struct V_6 * V_7 , T_9 V_246 )
{
struct V_6 * V_247 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_248 = F_26 ( V_7 ) -> V_79 ;
unsigned int V_249 = F_26 ( V_7 ) -> V_137 ;
unsigned int V_250 = V_7 -> V_13 - F_211 ( V_7 ) ;
unsigned int V_63 = V_250 ;
unsigned int V_141 ;
unsigned int V_11 ;
int V_251 = ! ! ( V_246 & V_252 ) ;
int V_160 = F_26 ( V_7 ) -> V_83 ;
int V_155 = - V_135 ;
int V_72 = 0 ;
int V_201 ;
F_212 ( V_7 , V_250 ) ;
V_141 = F_94 ( V_7 ) ;
V_201 = F_114 ( V_7 ) ;
do {
struct V_6 * V_253 ;
T_6 * V_159 ;
int V_254 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_63 ;
if ( V_11 > V_249 )
V_11 = V_249 ;
V_254 = F_114 ( V_7 ) - V_63 ;
if ( V_254 < 0 )
V_254 = 0 ;
if ( V_254 > V_11 || ! V_251 )
V_254 = V_11 ;
if ( ! V_254 && V_72 >= V_160 ) {
F_118 ( V_248 -> V_11 != V_11 ) ;
V_201 += V_11 ;
V_253 = F_103 ( V_248 , V_53 ) ;
V_248 = V_248 -> V_78 ;
if ( F_35 ( ! V_253 ) )
goto V_155;
V_254 = F_110 ( V_253 ) ;
if ( F_213 ( V_253 , V_250 + V_141 ) ) {
F_49 ( V_253 ) ;
goto V_155;
}
V_253 -> V_40 += F_110 ( V_253 ) - V_254 ;
F_62 ( V_253 ) ;
F_212 ( V_253 , V_250 ) ;
} else {
V_253 = F_13 ( V_254 + V_250 + V_141 ,
V_53 , F_108 ( V_7 ) ,
V_71 ) ;
if ( F_35 ( ! V_253 ) )
goto V_155;
F_45 ( V_253 , V_141 ) ;
F_214 ( V_253 , V_250 ) ;
}
if ( V_247 )
V_14 -> V_78 = V_253 ;
else
V_247 = V_253 ;
V_14 = V_253 ;
F_86 ( V_253 , V_7 ) ;
V_253 -> V_126 = V_7 -> V_126 ;
if ( V_253 -> V_113 == V_145 )
V_253 -> V_146 += F_94 ( V_253 ) - V_141 ;
F_215 ( V_253 ) ;
F_216 ( V_253 , V_7 -> V_126 ) ;
V_253 -> V_103 = ( V_253 -> V_104 +
F_217 ( V_7 ) ) ;
F_115 ( V_7 , V_253 -> V_13 , V_250 ) ;
if ( V_248 != F_26 ( V_7 ) -> V_79 )
continue;
if ( ! V_251 ) {
V_253 -> V_113 = V_255 ;
V_253 -> V_110 = F_165 ( V_7 , V_63 ,
F_111 ( V_253 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_159 = F_26 ( V_253 ) -> V_133 ;
F_141 ( V_7 , V_63 ,
F_111 ( V_253 , V_254 ) , V_254 ) ;
while ( V_201 < V_63 + V_11 && V_72 < V_160 ) {
* V_159 = F_26 ( V_7 ) -> V_133 [ V_72 ] ;
F_194 ( V_159 ) ;
V_18 = F_100 ( V_159 ) ;
if ( V_201 < V_63 ) {
V_159 -> V_136 += V_63 - V_201 ;
F_140 ( V_159 , V_63 - V_201 ) ;
}
F_26 ( V_253 ) -> V_83 ++ ;
if ( V_201 + V_18 <= V_63 + V_11 ) {
V_72 ++ ;
V_201 += V_18 ;
} else {
F_140 ( V_159 , V_201 + V_18 - ( V_63 + V_11 ) ) ;
goto V_256;
}
V_159 ++ ;
}
if ( V_201 < V_63 + V_11 ) {
struct V_6 * V_257 = V_248 ;
F_118 ( V_201 + V_248 -> V_11 != V_63 + V_11 ) ;
V_201 += V_248 -> V_11 ;
V_248 = V_248 -> V_78 ;
if ( V_257 -> V_78 ) {
V_257 = F_103 ( V_257 , V_53 ) ;
if ( ! V_257 )
goto V_155;
} else
F_53 ( V_257 ) ;
F_218 ( V_253 ) ;
F_26 ( V_253 ) -> V_79 = V_257 ;
}
V_256:
V_253 -> V_74 = V_11 - V_254 ;
V_253 -> V_11 += V_253 -> V_74 ;
V_253 -> V_40 += V_253 -> V_74 ;
} while ( ( V_63 += V_11 ) < V_7 -> V_11 );
return V_247 ;
V_155:
while ( ( V_7 = V_247 ) ) {
V_247 = V_7 -> V_78 ;
F_49 ( V_7 ) ;
}
return F_219 ( V_155 ) ;
}
int F_220 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_179 = * V_12 ;
struct V_6 * V_253 ;
struct V_31 * V_258 = F_26 ( V_7 ) ;
struct V_31 * V_259 = F_26 ( V_179 ) ;
unsigned int V_141 ;
unsigned int V_11 = F_221 ( V_7 ) ;
unsigned int V_63 = F_222 ( V_7 ) ;
unsigned int V_260 = F_114 ( V_7 ) ;
unsigned int V_261 ;
if ( V_179 -> V_11 + V_11 >= 65536 )
return - V_262 ;
if ( V_259 -> V_79 )
goto V_214;
else if ( V_260 <= V_63 ) {
T_6 * V_159 ;
T_6 * V_263 ;
int V_72 = V_258 -> V_83 ;
int V_83 = V_259 -> V_83 + V_72 ;
V_63 -= V_260 ;
if ( V_83 > V_188 )
return - V_262 ;
V_259 -> V_83 = V_83 ;
V_258 -> V_83 = 0 ;
V_159 = V_259 -> V_133 + V_83 ;
V_263 = V_258 -> V_133 + V_72 ;
do {
* -- V_159 = * -- V_263 ;
} while ( -- V_72 );
V_159 -> V_136 += V_63 ;
F_140 ( V_159 , V_63 ) ;
V_261 = V_7 -> V_40 -
F_22 ( F_110 ( V_7 ) ) ;
V_7 -> V_40 -= V_7 -> V_74 ;
V_7 -> V_11 -= V_7 -> V_74 ;
V_7 -> V_74 = 0 ;
F_223 ( V_7 ) -> free = V_264 ;
goto V_162;
} else if ( V_7 -> V_54 ) {
int V_83 = V_259 -> V_83 ;
T_6 * V_159 = V_259 -> V_133 + V_83 ;
struct V_5 * V_5 = F_44 ( V_7 -> V_12 ) ;
unsigned int V_265 = V_260 - V_63 ;
unsigned int V_266 ;
if ( V_83 + 1 + V_258 -> V_83 > V_188 )
return - V_262 ;
V_266 = V_7 -> V_13 -
( unsigned char * ) F_39 ( V_5 ) +
V_63 ;
V_259 -> V_83 = V_83 + 1 + V_258 -> V_83 ;
V_159 -> V_5 . V_179 = V_5 ;
V_159 -> V_136 = V_266 ;
F_135 ( V_159 , V_265 ) ;
memcpy ( V_159 + 1 , V_258 -> V_133 , sizeof( * V_159 ) * V_258 -> V_83 ) ;
V_261 = V_7 -> V_40 - F_17 ( sizeof( struct V_6 ) ) ;
F_223 ( V_7 ) -> free = V_267 ;
goto V_162;
} else if ( F_221 ( V_179 ) != V_259 -> V_137 )
return - V_262 ;
V_141 = F_94 ( V_179 ) ;
V_253 = F_224 ( V_141 + F_222 ( V_179 ) , V_53 ) ;
if ( F_35 ( ! V_253 ) )
return - V_135 ;
F_86 ( V_253 , V_179 ) ;
V_253 -> V_126 = V_179 -> V_126 ;
F_45 ( V_253 , V_141 ) ;
F_214 ( V_253 , F_222 ( V_179 ) ) ;
F_225 ( V_253 , F_211 ( V_179 ) - V_179 -> V_13 ) ;
F_216 ( V_253 , F_226 ( V_179 ) ) ;
F_227 ( V_253 , F_228 ( V_179 ) ) ;
F_229 ( V_179 , F_222 ( V_179 ) ) ;
memcpy ( F_211 ( V_253 ) , F_211 ( V_179 ) ,
V_179 -> V_13 - F_211 ( V_179 ) ) ;
* F_223 ( V_253 ) = * F_223 ( V_179 ) ;
F_26 ( V_253 ) -> V_79 = V_179 ;
F_26 ( V_253 ) -> V_137 = V_259 -> V_137 ;
V_259 -> V_137 = 0 ;
F_230 ( V_179 ) ;
V_253 -> V_124 = V_179 ;
V_253 -> V_74 += V_179 -> V_11 ;
V_253 -> V_40 += V_179 -> V_40 ;
V_253 -> V_11 += V_179 -> V_11 ;
* V_12 = V_253 ;
V_253 -> V_78 = V_179 -> V_78 ;
V_179 -> V_78 = NULL ;
V_179 = V_253 ;
V_214:
V_261 = V_7 -> V_40 ;
if ( V_63 > V_260 ) {
unsigned int V_165 = V_63 - V_260 ;
V_258 -> V_133 [ 0 ] . V_136 += V_165 ;
F_140 ( & V_258 -> V_133 [ 0 ] , V_165 ) ;
V_7 -> V_74 -= V_165 ;
V_7 -> V_11 -= V_165 ;
V_63 = V_260 ;
}
F_229 ( V_7 , V_63 ) ;
V_179 -> V_124 -> V_78 = V_7 ;
V_179 -> V_124 = V_7 ;
F_230 ( V_7 ) ;
V_162:
F_223 ( V_179 ) -> V_268 ++ ;
V_179 -> V_74 += V_11 ;
V_179 -> V_40 += V_261 ;
V_179 -> V_11 += V_11 ;
F_223 ( V_7 ) -> V_269 = 1 ;
return 0 ;
}
void T_10 F_231 ( void )
{
V_35 = F_232 ( L_3 ,
sizeof( struct V_6 ) ,
0 ,
V_270 | V_271 ,
NULL ) ;
V_34 = F_232 ( L_4 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_4 ) ,
0 ,
V_270 | V_271 ,
NULL ) ;
}
static int
F_233 ( struct V_6 * V_7 , struct V_272 * V_251 , int V_63 , int V_11 )
{
int V_170 = F_114 ( V_7 ) ;
int V_72 , V_172 = V_170 - V_63 ;
struct V_6 * V_171 ;
int V_273 = 0 ;
if ( V_172 > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
F_234 ( V_251 , V_7 -> V_13 + V_63 , V_172 ) ;
V_273 ++ ;
if ( ( V_11 -= V_172 ) == 0 )
return V_273 ;
V_63 += V_172 ;
}
for ( V_72 = 0 ; V_72 < F_26 ( V_7 ) -> V_83 ; V_72 ++ ) {
int V_15 ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + F_100 ( & F_26 ( V_7 ) -> V_133 [ V_72 ] ) ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
T_6 * V_159 = & F_26 ( V_7 ) -> V_133 [ V_72 ] ;
if ( V_172 > V_11 )
V_172 = V_11 ;
F_235 ( & V_251 [ V_273 ] , F_99 ( V_159 ) , V_172 ,
V_159 -> V_136 + V_63 - V_170 ) ;
V_273 ++ ;
if ( ! ( V_11 -= V_172 ) )
return V_273 ;
V_63 += V_172 ;
}
V_170 = V_15 ;
}
F_52 (skb, frag_iter) {
int V_15 ;
F_66 ( V_170 > V_63 + V_11 ) ;
V_15 = V_170 + V_171 -> V_11 ;
if ( ( V_172 = V_15 - V_63 ) > 0 ) {
if ( V_172 > V_11 )
V_172 = V_11 ;
V_273 += F_233 ( V_171 , V_251 + V_273 , V_63 - V_170 ,
V_172 ) ;
if ( ( V_11 -= V_172 ) == 0 )
return V_273 ;
V_63 += V_172 ;
}
V_170 = V_15 ;
}
F_118 ( V_11 ) ;
return V_273 ;
}
int F_236 ( struct V_6 * V_7 , struct V_272 * V_251 , int V_63 , int V_11 )
{
int V_274 = F_233 ( V_7 , V_251 , V_63 , V_11 ) ;
F_237 ( & V_251 [ V_274 - 1 ] ) ;
return V_274 ;
}
int F_238 ( struct V_6 * V_7 , int V_275 , struct V_6 * * V_276 )
{
int V_277 ;
int V_273 ;
struct V_6 * V_211 , * * V_278 ;
if ( ( F_121 ( V_7 ) || F_26 ( V_7 ) -> V_83 ) &&
F_138 ( V_7 , F_239 ( V_7 ) - F_114 ( V_7 ) ) == NULL )
return - V_135 ;
if ( ! F_59 ( V_7 ) ) {
if ( F_126 ( V_7 ) < V_275 &&
F_117 ( V_7 , 0 , V_275 - F_126 ( V_7 ) + 128 , V_53 ) )
return - V_135 ;
* V_276 = V_7 ;
return 1 ;
}
V_273 = 1 ;
V_278 = & F_26 ( V_7 ) -> V_79 ;
V_277 = 0 ;
while ( ( V_211 = * V_278 ) != NULL ) {
int V_143 = 0 ;
if ( F_119 ( V_211 ) )
V_277 = 1 ;
if ( V_211 -> V_78 == NULL && V_275 ) {
if ( F_26 ( V_211 ) -> V_83 ||
F_59 ( V_211 ) ||
F_126 ( V_211 ) < V_275 )
V_143 = V_275 + 128 ;
}
if ( V_277 ||
F_121 ( V_211 ) ||
V_143 ||
F_26 ( V_211 ) -> V_83 ||
F_59 ( V_211 ) ) {
struct V_6 * V_147 ;
if ( V_143 == 0 )
V_147 = F_109 ( V_211 , V_53 ) ;
else
V_147 = F_124 ( V_211 ,
F_94 ( V_211 ) ,
V_143 ,
V_53 ) ;
if ( F_35 ( V_147 == NULL ) )
return - V_135 ;
if ( V_211 -> V_125 )
F_240 ( V_147 , V_211 -> V_125 ) ;
V_147 -> V_78 = V_211 -> V_78 ;
* V_278 = V_147 ;
F_49 ( V_211 ) ;
V_211 = V_147 ;
}
V_273 ++ ;
* V_276 = V_211 ;
V_278 = & V_211 -> V_78 ;
}
return V_273 ;
}
static void F_241 ( struct V_6 * V_7 )
{
struct V_178 * V_125 = V_7 -> V_125 ;
F_242 ( V_7 -> V_40 , & V_125 -> V_279 ) ;
}
int F_243 ( struct V_178 * V_125 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_37 ( & V_125 -> V_279 ) + V_7 -> V_40 >=
( unsigned int ) V_125 -> V_280 )
return - V_135 ;
F_244 ( V_7 ) ;
V_7 -> V_125 = V_125 ;
V_7 -> V_92 = F_241 ;
F_206 ( V_7 -> V_40 , & V_125 -> V_279 ) ;
F_245 ( V_7 ) ;
F_179 ( & V_125 -> V_281 , V_7 ) ;
if ( ! F_246 ( V_125 , V_282 ) )
V_125 -> V_283 ( V_125 , V_11 ) ;
return 0 ;
}
void F_247 ( struct V_6 * V_284 ,
struct V_285 * V_286 )
{
struct V_178 * V_125 = V_284 -> V_125 ;
struct V_287 * V_288 ;
struct V_6 * V_7 ;
int V_155 ;
if ( ! V_125 )
return;
V_7 = F_103 ( V_284 , V_53 ) ;
if ( ! V_7 )
return;
if ( V_286 ) {
* F_248 ( V_7 ) =
* V_286 ;
} else {
V_7 -> V_102 = F_249 () ;
}
V_288 = F_250 ( V_7 ) ;
memset ( V_288 , 0 , sizeof( * V_288 ) ) ;
V_288 -> V_289 . V_290 = V_291 ;
V_288 -> V_289 . V_292 = V_293 ;
V_155 = F_243 ( V_125 , V_7 ) ;
if ( V_155 )
F_49 ( V_7 ) ;
}
void F_251 ( struct V_6 * V_7 , bool V_294 )
{
struct V_178 * V_125 = V_7 -> V_125 ;
struct V_287 * V_288 ;
int V_155 ;
V_7 -> V_295 = 1 ;
V_7 -> V_296 = V_294 ;
V_288 = F_250 ( V_7 ) ;
memset ( V_288 , 0 , sizeof( * V_288 ) ) ;
V_288 -> V_289 . V_290 = V_291 ;
V_288 -> V_289 . V_292 = V_297 ;
V_155 = F_243 ( V_125 , V_7 ) ;
if ( V_155 )
F_49 ( V_7 ) ;
}
bool F_252 ( struct V_6 * V_7 , T_11 V_170 , T_11 V_73 )
{
if ( F_35 ( V_170 > F_114 ( V_7 ) ) ||
F_35 ( ( int ) V_170 + V_73 > F_114 ( V_7 ) - 2 ) ) {
F_253 ( L_5 ,
V_170 , V_73 , F_114 ( V_7 ) ) ;
return false ;
}
V_7 -> V_113 = V_145 ;
V_7 -> V_146 = F_94 ( V_7 ) + V_170 ;
V_7 -> V_205 = V_73 ;
return true ;
}
void F_254 ( const struct V_6 * V_7 )
{
F_253 ( L_6 ,
V_7 -> V_16 -> V_17 ) ;
}
void F_255 ( struct V_6 * V_7 , bool V_298 )
{
if ( V_298 )
F_29 ( V_35 , V_7 ) ;
else
F_77 ( V_7 ) ;
}
bool F_256 ( struct V_6 * V_169 , struct V_6 * V_200 ,
bool * V_299 , int * V_261 )
{
int V_72 , V_148 , V_11 = V_200 -> V_11 ;
* V_299 = false ;
if ( F_121 ( V_169 ) )
return false ;
if ( V_11 <= F_126 ( V_169 ) ) {
F_118 ( F_112 ( V_200 , 0 , F_111 ( V_169 , V_11 ) , V_11 ) ) ;
* V_261 = 0 ;
return true ;
}
if ( F_59 ( V_169 ) || F_59 ( V_200 ) )
return false ;
if ( F_114 ( V_200 ) != 0 ) {
struct V_5 * V_5 ;
unsigned int V_63 ;
if ( F_26 ( V_169 ) -> V_83 +
F_26 ( V_200 ) -> V_83 >= V_188 )
return false ;
if ( F_155 ( V_200 ) )
return false ;
V_148 = V_200 -> V_40 - F_17 ( sizeof( struct V_6 ) ) ;
V_5 = F_44 ( V_200 -> V_12 ) ;
V_63 = V_200 -> V_13 - ( unsigned char * ) F_39 ( V_5 ) ;
F_47 ( V_169 , F_26 ( V_169 ) -> V_83 ,
V_5 , V_63 , F_114 ( V_200 ) ) ;
* V_299 = true ;
} else {
if ( F_26 ( V_169 ) -> V_83 +
F_26 ( V_200 ) -> V_83 > V_188 )
return false ;
V_148 = V_200 -> V_40 -
F_22 ( F_257 ( V_200 ) - V_200 -> V_12 ) ;
}
F_258 ( V_148 < V_11 ) ;
memcpy ( F_26 ( V_169 ) -> V_133 + F_26 ( V_169 ) -> V_83 ,
F_26 ( V_200 ) -> V_133 ,
F_26 ( V_200 ) -> V_83 * sizeof( T_6 ) ) ;
F_26 ( V_169 ) -> V_83 += F_26 ( V_200 ) -> V_83 ;
if ( ! F_121 ( V_200 ) )
F_26 ( V_200 ) -> V_83 = 0 ;
for ( V_72 = 0 ; V_72 < F_26 ( V_200 ) -> V_83 ; V_72 ++ )
F_116 ( V_200 , V_72 ) ;
V_169 -> V_40 += V_148 ;
V_169 -> V_11 += V_11 ;
V_169 -> V_74 += V_11 ;
* V_261 = V_148 ;
return true ;
}
