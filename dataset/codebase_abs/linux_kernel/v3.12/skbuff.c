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
V_106 -> V_113 = V_107 -> V_113 ;
F_88 ( V_106 , V_107 ) ;
V_106 -> V_114 = V_107 -> V_114 ;
V_106 -> V_115 = V_107 -> V_115 ;
V_106 -> V_116 = V_107 -> V_116 ;
V_106 -> V_117 = V_107 -> V_117 ;
V_106 -> V_118 = V_107 -> V_118 ;
#ifdef F_66
V_106 -> V_96 = F_89 ( V_107 -> V_96 ) ;
#endif
memcpy ( V_106 -> V_119 , V_107 -> V_119 , sizeof( V_107 -> V_119 ) ) ;
V_106 -> V_120 = V_107 -> V_120 ;
V_106 -> V_121 = V_107 -> V_121 ;
V_106 -> V_122 = V_107 -> V_122 ;
V_106 -> V_123 = V_107 -> V_123 ;
F_90 ( V_106 , V_107 ) ;
V_106 -> V_124 = V_107 -> V_124 ;
#if F_70 ( V_125 )
V_106 -> V_126 = V_107 -> V_126 ;
#endif
V_106 -> V_23 = V_107 -> V_23 ;
V_106 -> V_127 = V_107 -> V_127 ;
V_106 -> V_128 = V_107 -> V_128 ;
V_106 -> V_129 = V_107 -> V_129 ;
F_91 ( V_106 , V_107 ) ;
#if F_70 ( V_130 )
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
#define F_95 ( T_5 ) n->x = skb->x
V_135 -> V_105 = V_135 -> V_136 = NULL ;
V_135 -> V_137 = NULL ;
F_87 ( V_135 , V_7 ) ;
F_95 ( V_11 ) ;
F_95 ( V_81 ) ;
F_95 ( V_138 ) ;
V_135 -> V_139 = V_7 -> V_86 ? F_96 ( V_7 ) : V_7 -> V_139 ;
V_135 -> V_85 = 1 ;
V_135 -> V_86 = 0 ;
V_135 -> V_97 = NULL ;
F_95 ( V_14 ) ;
F_95 ( V_15 ) ;
F_95 ( V_12 ) ;
F_95 ( V_56 ) ;
F_95 ( V_13 ) ;
F_95 ( V_32 ) ;
F_17 ( & V_135 -> V_33 , 1 ) ;
F_97 ( & ( F_28 ( V_7 ) -> V_45 ) ) ;
V_7 -> V_85 = 1 ;
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
int V_142 = F_28 ( V_7 ) -> V_88 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_91 * V_92 = F_28 ( V_7 ) -> V_46 ;
for ( V_79 = 0 ; V_79 < V_142 ; V_79 ++ ) {
T_3 * V_143 ;
T_6 * V_144 = & F_28 ( V_7 ) -> V_145 [ V_79 ] ;
V_5 = F_100 ( V_29 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_105 = (struct V_5 * ) F_101 ( V_12 ) ;
F_2 ( V_12 ) ;
V_12 = V_105 ;
}
return - V_146 ;
}
V_143 = F_102 ( F_103 ( V_144 ) ) ;
memcpy ( F_42 ( V_5 ) ,
V_143 + V_144 -> V_147 , F_104 ( V_144 ) ) ;
F_105 ( V_143 ) ;
F_106 ( V_5 , ( unsigned long ) V_12 ) ;
V_12 = V_5 ;
}
for ( V_79 = 0 ; V_79 < V_142 ; V_79 ++ )
F_60 ( V_7 , V_79 ) ;
V_92 -> V_93 ( V_92 , false ) ;
for ( V_79 = V_142 - 1 ; V_79 >= 0 ; V_79 -- ) {
F_107 ( V_7 , V_79 , V_12 , 0 ,
F_28 ( V_7 ) -> V_145 [ V_79 ] . V_19 ) ;
V_12 = (struct V_5 * ) F_101 ( V_12 ) ;
}
F_28 ( V_7 ) -> V_89 &= ~ V_90 ;
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
V_135 -> V_51 = V_95 ;
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
F_28 ( V_106 ) -> V_148 = F_28 ( V_107 ) -> V_148 ;
F_28 ( V_106 ) -> V_149 = F_28 ( V_107 ) -> V_149 ;
F_28 ( V_106 ) -> V_150 = F_28 ( V_107 ) -> V_150 ;
}
static inline int F_114 ( const struct V_6 * V_7 )
{
if ( F_110 ( V_7 ) )
return V_41 ;
return 0 ;
}
struct V_6 * F_115 ( const struct V_6 * V_7 , T_2 V_29 )
{
int V_151 = F_96 ( V_7 ) ;
unsigned int V_19 = F_116 ( V_7 ) + V_7 -> V_81 ;
struct V_6 * V_135 = F_19 ( V_19 , V_29 ,
F_114 ( V_7 ) , V_78 ) ;
if ( ! V_135 )
return NULL ;
F_47 ( V_135 , V_151 ) ;
F_117 ( V_135 , V_7 -> V_11 ) ;
if ( F_118 ( V_7 , - V_151 , V_135 -> V_12 , V_151 + V_7 -> V_11 ) )
F_8 () ;
F_113 ( V_135 , V_7 ) ;
return V_135 ;
}
struct V_6 * F_119 ( struct V_6 * V_7 , int V_152 , T_2 V_29 )
{
unsigned int V_19 = F_120 ( V_7 ) + V_152 ;
struct V_6 * V_135 = F_19 ( V_19 , V_29 ,
F_114 ( V_7 ) , V_78 ) ;
if ( ! V_135 )
goto V_28;
F_47 ( V_135 , V_152 ) ;
F_117 ( V_135 , F_120 ( V_7 ) ) ;
F_121 ( V_7 , V_135 -> V_13 , V_135 -> V_11 ) ;
V_135 -> V_32 += V_7 -> V_81 ;
V_135 -> V_81 = V_7 -> V_81 ;
V_135 -> V_11 = V_7 -> V_11 ;
if ( F_28 ( V_7 ) -> V_88 ) {
int V_79 ;
if ( F_109 ( V_7 , V_29 ) ) {
F_80 ( V_135 ) ;
V_135 = NULL ;
goto V_28;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
F_28 ( V_135 ) -> V_145 [ V_79 ] = F_28 ( V_7 ) -> V_145 [ V_79 ] ;
F_122 ( V_7 , V_79 ) ;
}
F_28 ( V_135 ) -> V_88 = V_79 ;
}
if ( F_61 ( V_7 ) ) {
F_28 ( V_135 ) -> V_83 = F_28 ( V_7 ) -> V_83 ;
F_53 ( V_135 ) ;
}
F_113 ( V_135 , V_7 ) ;
V_28:
return V_135 ;
}
int F_123 ( struct V_6 * V_7 , int V_153 , int V_154 ,
T_2 V_29 )
{
int V_79 ;
T_3 * V_13 ;
int V_19 = V_153 + F_116 ( V_7 ) + V_154 ;
long V_80 ;
F_124 ( V_153 < 0 ) ;
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
memcpy ( V_13 + V_153 , V_7 -> V_12 , F_126 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_37 * ) ( V_13 + V_19 ) ,
F_28 ( V_7 ) ,
F_16 ( struct V_37 , V_145 [ F_28 ( V_7 ) -> V_88 ] ) ) ;
if ( F_127 ( V_7 ) ) {
if ( F_109 ( V_7 , V_29 ) )
goto V_155;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ )
F_122 ( V_7 , V_79 ) ;
if ( F_61 ( V_7 ) )
F_53 ( V_7 ) ;
F_58 ( V_7 ) ;
} else {
F_56 ( V_7 ) ;
}
V_80 = ( V_13 + V_153 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_56 = 0 ;
V_7 -> V_13 += V_80 ;
#ifdef F_128
V_7 -> V_15 = V_19 ;
V_80 = V_153 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_19 ;
#endif
V_7 -> V_14 += V_80 ;
F_111 ( V_7 , V_153 ) ;
if ( V_7 -> V_123 == V_156 )
V_7 -> V_157 += V_153 ;
V_7 -> V_85 = 0 ;
V_7 -> V_139 = 0 ;
V_7 -> V_86 = 0 ;
F_17 ( & F_28 ( V_7 ) -> V_45 , 1 ) ;
return 0 ;
V_155:
F_57 ( V_13 ) ;
V_43:
return - V_146 ;
}
struct V_6 * F_129 ( struct V_6 * V_7 , unsigned int V_152 )
{
struct V_6 * V_158 ;
int V_159 = V_152 - F_96 ( V_7 ) ;
if ( V_159 <= 0 )
V_158 = F_130 ( V_7 , V_55 ) ;
else {
V_158 = F_108 ( V_7 , V_55 ) ;
if ( V_158 && F_123 ( V_158 , F_22 ( V_159 ) , 0 ,
V_55 ) ) {
F_80 ( V_158 ) ;
V_158 = NULL ;
}
}
return V_158 ;
}
struct V_6 * F_131 ( const struct V_6 * V_7 ,
int V_160 , int V_161 ,
T_2 V_29 )
{
struct V_6 * V_135 = F_19 ( V_160 + V_7 -> V_11 + V_161 ,
V_29 , F_114 ( V_7 ) ,
V_78 ) ;
int V_162 = F_96 ( V_7 ) ;
int V_163 , V_164 ;
int V_80 ;
if ( ! V_135 )
return NULL ;
F_47 ( V_135 , V_160 ) ;
F_117 ( V_135 , V_7 -> V_11 ) ;
V_163 = V_162 ;
V_164 = 0 ;
if ( V_160 <= V_163 )
V_163 = V_160 ;
else
V_164 = V_160 - V_163 ;
if ( F_118 ( V_7 , - V_163 , V_135 -> V_12 + V_164 ,
V_7 -> V_11 + V_163 ) )
F_8 () ;
F_113 ( V_135 , V_7 ) ;
V_80 = V_160 - V_162 ;
if ( V_135 -> V_123 == V_156 )
V_135 -> V_157 += V_80 ;
F_111 ( V_135 , V_80 ) ;
return V_135 ;
}
int F_132 ( struct V_6 * V_7 , int V_165 )
{
int V_166 ;
int V_154 ;
if ( ! F_127 ( V_7 ) && F_133 ( V_7 ) >= V_165 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_165 ) ;
return 0 ;
}
V_154 = V_7 -> V_81 + V_165 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_39 ( F_127 ( V_7 ) || V_154 > 0 ) ) {
V_166 = F_123 ( V_7 , 0 , V_154 , V_55 ) ;
if ( F_37 ( V_166 ) )
goto V_167;
}
V_166 = F_134 ( V_7 ) ;
if ( F_37 ( V_166 ) )
goto V_167;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_165 ) ;
return 0 ;
V_167:
F_80 ( V_7 ) ;
return V_166 ;
}
unsigned char * F_117 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_168 = F_126 ( V_7 ) ;
F_135 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_37 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_9 ( V_7 , V_11 , F_83 ( 0 ) ) ;
return V_168 ;
}
unsigned char * F_136 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_37 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_10 ( V_7 , V_11 , F_83 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_137 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_138 ( V_7 , V_11 ) ;
}
void F_139 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_140 ( V_7 , V_11 ) ;
}
int F_141 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_169 ;
struct V_6 * V_61 ;
int V_71 = F_120 ( V_7 ) ;
int V_170 = F_28 ( V_7 ) -> V_88 ;
int V_79 ;
int V_166 ;
if ( F_127 ( V_7 ) &&
F_37 ( ( V_166 = F_123 ( V_7 , 0 , 0 , V_55 ) ) ) )
return V_166 ;
V_79 = 0 ;
if ( V_71 >= V_11 )
goto V_171;
for (; V_79 < V_170 ; V_79 ++ ) {
int V_15 = V_71 + F_104 ( & F_28 ( V_7 ) -> V_145 [ V_79 ] ) ;
if ( V_15 < V_11 ) {
V_71 = V_15 ;
continue;
}
F_142 ( & F_28 ( V_7 ) -> V_145 [ V_79 ++ ] , V_11 - V_71 ) ;
V_171:
F_28 ( V_7 ) -> V_88 = V_79 ;
for (; V_79 < V_170 ; V_79 ++ )
F_60 ( V_7 , V_79 ) ;
if ( F_61 ( V_7 ) )
F_52 ( V_7 ) ;
goto V_172;
}
for ( V_169 = & F_28 ( V_7 ) -> V_83 ; ( V_61 = * V_169 ) ;
V_169 = & V_61 -> V_105 ) {
int V_15 = V_71 + V_61 -> V_11 ;
if ( F_125 ( V_61 ) ) {
struct V_6 * V_173 ;
V_173 = F_108 ( V_61 , V_55 ) ;
if ( F_37 ( ! V_173 ) )
return - V_146 ;
V_173 -> V_105 = V_61 -> V_105 ;
F_85 ( V_61 ) ;
V_61 = V_173 ;
* V_169 = V_61 ;
}
if ( V_15 < V_11 ) {
V_71 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_37 ( ( V_166 = F_143 ( V_61 , V_11 - V_71 ) ) ) )
return V_166 ;
if ( V_61 -> V_105 )
F_50 ( & V_61 -> V_105 ) ;
break;
}
V_172:
if ( V_11 > F_120 ( V_7 ) ) {
V_7 -> V_81 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_81 = 0 ;
F_144 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_145 ( struct V_6 * V_7 , int V_159 )
{
int V_79 , V_174 , V_175 = ( V_7 -> V_14 + V_159 ) - V_7 -> V_15 ;
if ( V_175 > 0 || F_127 ( V_7 ) ) {
if ( F_123 ( V_7 , 0 , V_175 > 0 ? V_175 + 128 : 0 ,
V_55 ) )
return NULL ;
}
if ( F_118 ( V_7 , F_120 ( V_7 ) , F_126 ( V_7 ) , V_159 ) )
F_8 () ;
if ( ! F_61 ( V_7 ) )
goto V_176;
V_175 = V_159 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_19 = F_104 ( & F_28 ( V_7 ) -> V_145 [ V_79 ] ) ;
if ( V_19 >= V_175 )
goto V_176;
V_175 -= V_19 ;
}
if ( V_175 ) {
struct V_6 * V_84 = F_28 ( V_7 ) -> V_83 ;
struct V_6 * V_177 = NULL ;
struct V_6 * V_178 = NULL ;
do {
F_124 ( ! V_84 ) ;
if ( V_84 -> V_11 <= V_175 ) {
V_175 -= V_84 -> V_11 ;
V_84 = V_84 -> V_105 ;
V_178 = V_84 ;
} else {
if ( F_125 ( V_84 ) ) {
V_177 = F_108 ( V_84 , V_55 ) ;
if ( ! V_177 )
return NULL ;
V_178 = V_84 -> V_105 ;
V_84 = V_177 ;
} else {
V_178 = V_84 ;
}
if ( ! F_146 ( V_84 , V_175 ) ) {
F_80 ( V_177 ) ;
return NULL ;
}
break;
}
} while ( V_175 );
while ( ( V_84 = F_28 ( V_7 ) -> V_83 ) != V_178 ) {
F_28 ( V_7 ) -> V_83 = V_84 -> V_105 ;
F_80 ( V_84 ) ;
}
if ( V_177 ) {
V_177 -> V_105 = V_84 ;
F_28 ( V_7 ) -> V_83 = V_177 ;
}
}
V_176:
V_175 = V_159 ;
V_174 = 0 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_19 = F_104 ( & F_28 ( V_7 ) -> V_145 [ V_79 ] ) ;
if ( V_19 <= V_175 ) {
F_60 ( V_7 , V_79 ) ;
V_175 -= V_19 ;
} else {
F_28 ( V_7 ) -> V_145 [ V_174 ] = F_28 ( V_7 ) -> V_145 [ V_79 ] ;
if ( V_175 ) {
F_28 ( V_7 ) -> V_145 [ V_174 ] . V_147 += V_175 ;
F_147 ( & F_28 ( V_7 ) -> V_145 [ V_174 ] , V_175 ) ;
V_175 = 0 ;
}
V_174 ++ ;
}
}
F_28 ( V_7 ) -> V_88 = V_174 ;
V_7 -> V_14 += V_159 ;
V_7 -> V_81 -= V_159 ;
return F_126 ( V_7 ) ;
}
int F_118 ( const struct V_6 * V_7 , int V_71 , void * V_179 , int V_11 )
{
int V_180 = F_120 ( V_7 ) ;
struct V_6 * V_181 ;
int V_79 , V_182 ;
if ( V_71 > ( int ) V_7 -> V_11 - V_11 )
goto V_183;
if ( ( V_182 = V_180 - V_71 ) > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
F_148 ( V_7 , V_71 , V_179 , V_182 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return 0 ;
V_71 += V_182 ;
V_179 += V_182 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_15 ;
T_6 * V_144 = & F_28 ( V_7 ) -> V_145 [ V_79 ] ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + F_104 ( V_144 ) ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
T_3 * V_143 ;
if ( V_182 > V_11 )
V_182 = V_11 ;
V_143 = F_102 ( F_103 ( V_144 ) ) ;
memcpy ( V_179 ,
V_143 + V_144 -> V_147 + V_71 - V_180 ,
V_182 ) ;
F_105 ( V_143 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return 0 ;
V_71 += V_182 ;
V_179 += V_182 ;
}
V_180 = V_15 ;
}
F_54 (skb, frag_iter) {
int V_15 ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + V_181 -> V_11 ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
if ( F_118 ( V_181 , V_71 - V_180 , V_179 , V_182 ) )
goto V_183;
if ( ( V_11 -= V_182 ) == 0 )
return 0 ;
V_71 += V_182 ;
V_179 += V_182 ;
}
V_180 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_183:
return - V_184 ;
}
static void F_149 ( struct V_185 * V_186 , unsigned int V_79 )
{
F_2 ( V_186 -> V_187 [ V_79 ] ) ;
}
static struct V_5 * F_150 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_71 ,
struct V_188 * V_137 )
{
struct V_189 * V_190 = F_151 ( V_137 ) ;
if ( ! F_152 ( V_137 , V_190 ) )
return NULL ;
* V_11 = F_153 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_42 ( V_190 -> V_5 ) + V_190 -> V_71 ,
F_42 ( V_5 ) + * V_71 , * V_11 ) ;
* V_71 = V_190 -> V_71 ;
V_190 -> V_71 += * V_11 ;
return V_190 -> V_5 ;
}
static bool F_154 ( const struct V_185 * V_186 ,
struct V_5 * V_5 ,
unsigned int V_71 )
{
return V_186 -> V_191 &&
V_186 -> V_187 [ V_186 -> V_191 - 1 ] == V_5 &&
( V_186 -> V_192 [ V_186 -> V_191 - 1 ] . V_71 +
V_186 -> V_192 [ V_186 -> V_191 - 1 ] . V_11 == V_71 ) ;
}
static bool F_155 ( struct V_185 * V_186 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_71 ,
bool V_193 ,
struct V_188 * V_137 )
{
if ( F_37 ( V_186 -> V_191 == V_194 ) )
return true ;
if ( V_193 ) {
V_5 = F_150 ( V_5 , V_11 , & V_71 , V_137 ) ;
if ( ! V_5 )
return true ;
}
if ( F_154 ( V_186 , V_5 , V_71 ) ) {
V_186 -> V_192 [ V_186 -> V_191 - 1 ] . V_11 += * V_11 ;
return false ;
}
F_4 ( V_5 ) ;
V_186 -> V_187 [ V_186 -> V_191 ] = V_5 ;
V_186 -> V_192 [ V_186 -> V_191 ] . V_11 = * V_11 ;
V_186 -> V_192 [ V_186 -> V_191 ] . V_71 = V_71 ;
V_186 -> V_191 ++ ;
return false ;
}
static bool F_156 ( struct V_5 * V_5 , unsigned int V_195 ,
unsigned int V_196 , unsigned int * V_80 ,
unsigned int * V_11 ,
struct V_185 * V_186 , bool V_193 ,
struct V_188 * V_137 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return true ;
if ( * V_80 >= V_196 ) {
* V_80 -= V_196 ;
return false ;
}
V_195 += * V_80 ;
V_196 -= * V_80 ;
* V_80 = 0 ;
do {
unsigned int V_197 = F_157 ( * V_11 , V_196 ) ;
if ( F_155 ( V_186 , V_2 , V_5 , & V_197 , V_195 ,
V_193 , V_137 ) )
return true ;
V_195 += V_197 ;
V_196 -= V_197 ;
* V_11 -= V_197 ;
} while ( * V_11 && V_196 );
return false ;
}
static bool F_158 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_71 , unsigned int * V_11 ,
struct V_185 * V_186 , struct V_188 * V_137 )
{
int V_198 ;
if ( F_156 ( F_159 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_66 - 1 ) ,
F_120 ( V_7 ) ,
V_71 , V_11 , V_186 ,
F_160 ( V_7 ) ,
V_137 , V_2 ) )
return true ;
for ( V_198 = 0 ; V_198 < F_28 ( V_7 ) -> V_88 ; V_198 ++ ) {
const T_6 * V_144 = & F_28 ( V_7 ) -> V_145 [ V_198 ] ;
if ( F_156 ( F_103 ( V_144 ) ,
V_144 -> V_147 , F_104 ( V_144 ) ,
V_71 , V_11 , V_186 , false , V_137 , V_2 ) )
return true ;
}
return false ;
}
int F_161 ( struct V_6 * V_7 , unsigned int V_71 ,
struct V_1 * V_2 , unsigned int V_199 ,
unsigned int V_20 )
{
struct V_200 V_192 [ V_194 ] ;
struct V_5 * V_187 [ V_194 ] ;
struct V_185 V_186 = {
. V_187 = V_187 ,
. V_192 = V_192 ,
. V_201 = V_194 ,
. V_20 = V_20 ,
. V_202 = & V_203 ,
. V_204 = F_149 ,
} ;
struct V_6 * V_181 ;
struct V_188 * V_137 = V_7 -> V_137 ;
int V_205 = 0 ;
if ( F_158 ( V_7 , V_2 , & V_71 , & V_199 , & V_186 , V_137 ) )
goto V_172;
else if ( ! V_199 )
goto V_172;
F_54 (skb, frag_iter) {
if ( ! V_199 )
break;
if ( F_158 ( V_181 , V_2 , & V_71 , & V_199 , & V_186 , V_137 ) )
break;
}
V_172:
if ( V_186 . V_191 ) {
F_162 ( V_137 ) ;
V_205 = F_163 ( V_2 , & V_186 ) ;
F_164 ( V_137 ) ;
}
return V_205 ;
}
int F_165 ( struct V_6 * V_7 , int V_71 , const void * V_206 , int V_11 )
{
int V_180 = F_120 ( V_7 ) ;
struct V_6 * V_181 ;
int V_79 , V_182 ;
if ( V_71 > ( int ) V_7 -> V_11 - V_11 )
goto V_183;
if ( ( V_182 = V_180 - V_71 ) > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
F_166 ( V_7 , V_71 , V_206 , V_182 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return 0 ;
V_71 += V_182 ;
V_206 += V_182 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
T_6 * V_61 = & F_28 ( V_7 ) -> V_145 [ V_79 ] ;
int V_15 ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + F_104 ( V_61 ) ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
T_3 * V_143 ;
if ( V_182 > V_11 )
V_182 = V_11 ;
V_143 = F_102 ( F_103 ( V_61 ) ) ;
memcpy ( V_143 + V_61 -> V_147 + V_71 - V_180 ,
V_206 , V_182 ) ;
F_105 ( V_143 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return 0 ;
V_71 += V_182 ;
V_206 += V_182 ;
}
V_180 = V_15 ;
}
F_54 (skb, frag_iter) {
int V_15 ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + V_181 -> V_11 ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
if ( F_165 ( V_181 , V_71 - V_180 ,
V_206 , V_182 ) )
goto V_183;
if ( ( V_11 -= V_182 ) == 0 )
return 0 ;
V_71 += V_182 ;
V_206 += V_182 ;
}
V_180 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_183:
return - V_184 ;
}
T_7 F_167 ( const struct V_6 * V_7 , int V_71 ,
int V_11 , T_7 V_120 )
{
int V_180 = F_120 ( V_7 ) ;
int V_79 , V_182 = V_180 - V_71 ;
struct V_6 * V_181 ;
int V_207 = 0 ;
if ( V_182 > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
V_120 = F_168 ( V_7 -> V_13 + V_71 , V_182 , V_120 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return V_120 ;
V_71 += V_182 ;
V_207 = V_182 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_15 ;
T_6 * V_61 = & F_28 ( V_7 ) -> V_145 [ V_79 ] ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + F_104 ( V_61 ) ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
T_7 V_208 ;
T_3 * V_143 ;
if ( V_182 > V_11 )
V_182 = V_11 ;
V_143 = F_102 ( F_103 ( V_61 ) ) ;
V_208 = F_168 ( V_143 + V_61 -> V_147 +
V_71 - V_180 , V_182 , 0 ) ;
F_105 ( V_143 ) ;
V_120 = F_169 ( V_120 , V_208 , V_207 ) ;
if ( ! ( V_11 -= V_182 ) )
return V_120 ;
V_71 += V_182 ;
V_207 += V_182 ;
}
V_180 = V_15 ;
}
F_54 (skb, frag_iter) {
int V_15 ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + V_181 -> V_11 ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
T_7 V_208 ;
if ( V_182 > V_11 )
V_182 = V_11 ;
V_208 = F_167 ( V_181 , V_71 - V_180 ,
V_182 , 0 ) ;
V_120 = F_169 ( V_120 , V_208 , V_207 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return V_120 ;
V_71 += V_182 ;
V_207 += V_182 ;
}
V_180 = V_15 ;
}
F_124 ( V_11 ) ;
return V_120 ;
}
T_7 F_170 ( const struct V_6 * V_7 , int V_71 ,
T_3 * V_179 , int V_11 , T_7 V_120 )
{
int V_180 = F_120 ( V_7 ) ;
int V_79 , V_182 = V_180 - V_71 ;
struct V_6 * V_181 ;
int V_207 = 0 ;
if ( V_182 > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
V_120 = F_171 ( V_7 -> V_13 + V_71 , V_179 ,
V_182 , V_120 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return V_120 ;
V_71 += V_182 ;
V_179 += V_182 ;
V_207 = V_182 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_15 ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + F_104 ( & F_28 ( V_7 ) -> V_145 [ V_79 ] ) ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
T_7 V_208 ;
T_3 * V_143 ;
T_6 * V_61 = & F_28 ( V_7 ) -> V_145 [ V_79 ] ;
if ( V_182 > V_11 )
V_182 = V_11 ;
V_143 = F_102 ( F_103 ( V_61 ) ) ;
V_208 = F_171 ( V_143 +
V_61 -> V_147 +
V_71 - V_180 , V_179 ,
V_182 , 0 ) ;
F_105 ( V_143 ) ;
V_120 = F_169 ( V_120 , V_208 , V_207 ) ;
if ( ! ( V_11 -= V_182 ) )
return V_120 ;
V_71 += V_182 ;
V_179 += V_182 ;
V_207 += V_182 ;
}
V_180 = V_15 ;
}
F_54 (skb, frag_iter) {
T_7 V_208 ;
int V_15 ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + V_181 -> V_11 ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
V_208 = F_170 ( V_181 ,
V_71 - V_180 ,
V_179 , V_182 , 0 ) ;
V_120 = F_169 ( V_120 , V_208 , V_207 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return V_120 ;
V_71 += V_182 ;
V_179 += V_182 ;
V_207 += V_182 ;
}
V_180 = V_15 ;
}
F_124 ( V_11 ) ;
return V_120 ;
}
void F_172 ( const struct V_6 * V_7 , T_3 * V_179 )
{
T_7 V_120 ;
long V_209 ;
if ( V_7 -> V_123 == V_156 )
V_209 = F_173 ( V_7 ) ;
else
V_209 = F_120 ( V_7 ) ;
F_124 ( V_209 > F_120 ( V_7 ) ) ;
F_121 ( V_7 , V_179 , V_209 ) ;
V_120 = 0 ;
if ( V_209 != V_7 -> V_11 )
V_120 = F_170 ( V_7 , V_209 , V_179 + V_209 ,
V_7 -> V_11 - V_209 , 0 ) ;
if ( V_7 -> V_123 == V_156 ) {
long V_210 = V_209 + V_7 -> V_211 ;
* ( ( V_212 * ) ( V_179 + V_210 ) ) = F_174 ( V_120 ) ;
}
}
struct V_6 * F_175 ( struct V_213 * V_84 )
{
unsigned long V_20 ;
struct V_6 * V_214 ;
F_176 ( & V_84 -> V_215 , V_20 ) ;
V_214 = F_177 ( V_84 ) ;
F_178 ( & V_84 -> V_215 , V_20 ) ;
return V_214 ;
}
struct V_6 * F_179 ( struct V_213 * V_84 )
{
unsigned long V_20 ;
struct V_6 * V_214 ;
F_176 ( & V_84 -> V_215 , V_20 ) ;
V_214 = F_180 ( V_84 ) ;
F_178 ( & V_84 -> V_215 , V_20 ) ;
return V_214 ;
}
void F_181 ( struct V_213 * V_84 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_175 ( V_84 ) ) != NULL )
F_80 ( V_7 ) ;
}
void F_182 ( struct V_213 * V_84 , struct V_6 * V_216 )
{
unsigned long V_20 ;
F_176 ( & V_84 -> V_215 , V_20 ) ;
F_183 ( V_84 , V_216 ) ;
F_178 ( & V_84 -> V_215 , V_20 ) ;
}
void F_184 ( struct V_213 * V_84 , struct V_6 * V_216 )
{
unsigned long V_20 ;
F_176 ( & V_84 -> V_215 , V_20 ) ;
F_185 ( V_84 , V_216 ) ;
F_178 ( & V_84 -> V_215 , V_20 ) ;
}
void F_186 ( struct V_6 * V_7 , struct V_213 * V_84 )
{
unsigned long V_20 ;
F_176 ( & V_84 -> V_215 , V_20 ) ;
F_187 ( V_7 , V_84 ) ;
F_178 ( & V_84 -> V_215 , V_20 ) ;
}
void F_188 ( struct V_6 * V_107 , struct V_6 * V_216 , struct V_213 * V_84 )
{
unsigned long V_20 ;
F_176 ( & V_84 -> V_215 , V_20 ) ;
F_189 ( V_84 , V_107 , V_216 ) ;
F_178 ( & V_84 -> V_215 , V_20 ) ;
}
void F_190 ( struct V_6 * V_107 , struct V_6 * V_216 , struct V_213 * V_84 )
{
unsigned long V_20 ;
F_176 ( & V_84 -> V_215 , V_20 ) ;
F_191 ( V_216 , V_107 -> V_136 , V_107 , V_84 ) ;
F_178 ( & V_84 -> V_215 , V_20 ) ;
}
static inline void F_192 ( struct V_6 * V_7 ,
struct V_6 * V_217 ,
const T_8 V_11 , const int V_207 )
{
int V_79 ;
F_148 ( V_7 , V_11 , F_117 ( V_217 , V_207 - V_11 ) ,
V_207 - V_11 ) ;
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ )
F_28 ( V_217 ) -> V_145 [ V_79 ] = F_28 ( V_7 ) -> V_145 [ V_79 ] ;
F_28 ( V_217 ) -> V_88 = F_28 ( V_7 ) -> V_88 ;
F_28 ( V_7 ) -> V_88 = 0 ;
V_217 -> V_81 = V_7 -> V_81 ;
V_217 -> V_11 += V_217 -> V_81 ;
V_7 -> V_81 = 0 ;
V_7 -> V_11 = V_11 ;
F_144 ( V_7 , V_11 ) ;
}
static inline void F_193 ( struct V_6 * V_7 ,
struct V_6 * V_217 ,
const T_8 V_11 , int V_207 )
{
int V_79 , V_174 = 0 ;
const int V_170 = F_28 ( V_7 ) -> V_88 ;
F_28 ( V_7 ) -> V_88 = 0 ;
V_217 -> V_11 = V_217 -> V_81 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_81 = V_11 - V_207 ;
for ( V_79 = 0 ; V_79 < V_170 ; V_79 ++ ) {
int V_19 = F_104 ( & F_28 ( V_7 ) -> V_145 [ V_79 ] ) ;
if ( V_207 + V_19 > V_11 ) {
F_28 ( V_217 ) -> V_145 [ V_174 ] = F_28 ( V_7 ) -> V_145 [ V_79 ] ;
if ( V_207 < V_11 ) {
F_122 ( V_7 , V_79 ) ;
F_28 ( V_217 ) -> V_145 [ 0 ] . V_147 += V_11 - V_207 ;
F_147 ( & F_28 ( V_217 ) -> V_145 [ 0 ] , V_11 - V_207 ) ;
F_142 ( & F_28 ( V_7 ) -> V_145 [ V_79 ] , V_11 - V_207 ) ;
F_28 ( V_7 ) -> V_88 ++ ;
}
V_174 ++ ;
} else
F_28 ( V_7 ) -> V_88 ++ ;
V_207 += V_19 ;
}
F_28 ( V_217 ) -> V_88 = V_174 ;
}
void F_194 ( struct V_6 * V_7 , struct V_6 * V_217 , const T_8 V_11 )
{
int V_207 = F_120 ( V_7 ) ;
F_28 ( V_217 ) -> V_89 = F_28 ( V_7 ) -> V_89 & V_218 ;
if ( V_11 < V_207 )
F_192 ( V_7 , V_217 , V_11 , V_207 ) ;
else
F_193 ( V_7 , V_217 , V_11 , V_207 ) ;
}
static int F_195 ( struct V_6 * V_7 )
{
return F_127 ( V_7 ) && F_123 ( V_7 , 0 , 0 , V_55 ) ;
}
int F_196 ( struct V_6 * V_219 , struct V_6 * V_7 , int V_220 )
{
int V_206 , V_179 , V_221 , V_222 ;
struct V_223 * V_224 , * V_225 ;
F_124 ( V_220 > V_7 -> V_11 ) ;
F_124 ( F_120 ( V_7 ) ) ;
V_222 = V_220 ;
V_206 = 0 ;
V_179 = F_28 ( V_219 ) -> V_88 ;
V_224 = & F_28 ( V_7 ) -> V_145 [ V_206 ] ;
if ( ! V_179 ||
! F_197 ( V_219 , V_179 , F_103 ( V_224 ) ,
V_224 -> V_147 ) ) {
V_221 = - 1 ;
} else {
V_221 = V_179 - 1 ;
V_222 -= F_104 ( V_224 ) ;
if ( V_222 < 0 ) {
if ( F_195 ( V_7 ) ||
F_195 ( V_219 ) )
return 0 ;
V_224 = & F_28 ( V_7 ) -> V_145 [ V_206 ] ;
V_225 = & F_28 ( V_219 ) -> V_145 [ V_221 ] ;
F_198 ( V_225 , V_220 ) ;
F_147 ( V_224 , V_220 ) ;
V_224 -> V_147 += V_220 ;
goto V_226;
}
V_206 ++ ;
}
if ( ( V_220 == V_7 -> V_11 ) &&
( F_28 ( V_7 ) -> V_88 - V_206 ) > ( V_194 - V_179 ) )
return 0 ;
if ( F_195 ( V_7 ) || F_195 ( V_219 ) )
return 0 ;
while ( ( V_222 > 0 ) && ( V_206 < F_28 ( V_7 ) -> V_88 ) ) {
if ( V_179 == V_194 )
return 0 ;
V_224 = & F_28 ( V_7 ) -> V_145 [ V_206 ] ;
V_225 = & F_28 ( V_219 ) -> V_145 [ V_179 ] ;
if ( V_222 >= F_104 ( V_224 ) ) {
* V_225 = * V_224 ;
V_222 -= F_104 ( V_224 ) ;
V_206 ++ ;
V_179 ++ ;
} else {
F_199 ( V_224 ) ;
V_225 -> V_5 = V_224 -> V_5 ;
V_225 -> V_147 = V_224 -> V_147 ;
F_142 ( V_225 , V_222 ) ;
V_224 -> V_147 += V_222 ;
F_147 ( V_224 , V_222 ) ;
V_222 = 0 ;
V_179 ++ ;
break;
}
}
F_28 ( V_219 ) -> V_88 = V_179 ;
if ( V_221 >= 0 ) {
V_224 = & F_28 ( V_7 ) -> V_145 [ 0 ] ;
V_225 = & F_28 ( V_219 ) -> V_145 [ V_221 ] ;
F_198 ( V_225 , F_104 ( V_224 ) ) ;
F_200 ( V_224 ) ;
}
V_179 = 0 ;
while ( V_206 < F_28 ( V_7 ) -> V_88 )
F_28 ( V_7 ) -> V_145 [ V_179 ++ ] = F_28 ( V_7 ) -> V_145 [ V_206 ++ ] ;
F_28 ( V_7 ) -> V_88 = V_179 ;
F_124 ( V_222 > 0 && ! F_28 ( V_7 ) -> V_88 ) ;
V_226:
V_219 -> V_123 = V_156 ;
V_7 -> V_123 = V_156 ;
V_7 -> V_11 -= V_220 ;
V_7 -> V_81 -= V_220 ;
V_7 -> V_32 -= V_220 ;
V_219 -> V_11 += V_220 ;
V_219 -> V_81 += V_220 ;
V_219 -> V_32 += V_220 ;
return V_220 ;
}
void F_201 ( struct V_6 * V_7 , unsigned int V_206 ,
unsigned int V_179 , struct V_227 * V_228 )
{
V_228 -> V_229 = V_206 ;
V_228 -> V_230 = V_179 ;
V_228 -> V_231 = V_228 -> V_232 = V_7 ;
V_228 -> V_233 = V_228 -> V_234 = 0 ;
V_228 -> V_235 = NULL ;
}
unsigned int F_202 ( unsigned int V_236 , const T_3 * * V_13 ,
struct V_227 * V_228 )
{
unsigned int V_237 , V_238 = V_236 + V_228 -> V_229 ;
T_6 * V_61 ;
if ( F_37 ( V_238 >= V_228 -> V_230 ) ) {
if ( V_228 -> V_235 ) {
F_105 ( V_228 -> V_235 ) ;
V_228 -> V_235 = NULL ;
}
return 0 ;
}
V_239:
V_237 = F_120 ( V_228 -> V_232 ) + V_228 -> V_234 ;
if ( V_238 < V_237 && ! V_228 -> V_235 ) {
* V_13 = V_228 -> V_232 -> V_13 + ( V_238 - V_228 -> V_234 ) ;
return V_237 - V_238 ;
}
if ( V_228 -> V_233 == 0 && ! V_228 -> V_235 )
V_228 -> V_234 += F_120 ( V_228 -> V_232 ) ;
while ( V_228 -> V_233 < F_28 ( V_228 -> V_232 ) -> V_88 ) {
V_61 = & F_28 ( V_228 -> V_232 ) -> V_145 [ V_228 -> V_233 ] ;
V_237 = F_104 ( V_61 ) + V_228 -> V_234 ;
if ( V_238 < V_237 ) {
if ( ! V_228 -> V_235 )
V_228 -> V_235 = F_102 ( F_103 ( V_61 ) ) ;
* V_13 = ( T_3 * ) V_228 -> V_235 + V_61 -> V_147 +
( V_238 - V_228 -> V_234 ) ;
return V_237 - V_238 ;
}
if ( V_228 -> V_235 ) {
F_105 ( V_228 -> V_235 ) ;
V_228 -> V_235 = NULL ;
}
V_228 -> V_233 ++ ;
V_228 -> V_234 += F_104 ( V_61 ) ;
}
if ( V_228 -> V_235 ) {
F_105 ( V_228 -> V_235 ) ;
V_228 -> V_235 = NULL ;
}
if ( V_228 -> V_231 == V_228 -> V_232 && F_61 ( V_228 -> V_231 ) ) {
V_228 -> V_232 = F_28 ( V_228 -> V_231 ) -> V_83 ;
V_228 -> V_233 = 0 ;
goto V_239;
} else if ( V_228 -> V_232 -> V_105 ) {
V_228 -> V_232 = V_228 -> V_232 -> V_105 ;
V_228 -> V_233 = 0 ;
goto V_239;
}
return 0 ;
}
void F_203 ( struct V_227 * V_228 )
{
if ( V_228 -> V_235 )
F_105 ( V_228 -> V_235 ) ;
}
static unsigned int F_204 ( unsigned int V_71 , const T_3 * * V_240 ,
struct V_241 * V_242 ,
struct V_243 * V_244 )
{
return F_202 ( V_71 , V_240 , F_205 ( V_244 ) ) ;
}
static void F_206 ( struct V_241 * V_242 , struct V_243 * V_244 )
{
F_203 ( F_205 ( V_244 ) ) ;
}
unsigned int F_207 ( struct V_6 * V_7 , unsigned int V_206 ,
unsigned int V_179 , struct V_241 * V_245 ,
struct V_243 * V_244 )
{
unsigned int V_205 ;
V_245 -> V_246 = F_204 ;
V_245 -> V_247 = F_206 ;
F_201 ( V_7 , V_206 , V_179 , F_205 ( V_244 ) ) ;
V_205 = F_208 ( V_245 , V_244 ) ;
return ( V_205 <= V_179 - V_206 ? V_205 : V_248 ) ;
}
int F_209 ( struct V_188 * V_137 , struct V_6 * V_7 ,
int (* F_210)( void * V_206 , char * V_179 , int V_71 ,
int V_11 , int V_249 , struct V_6 * V_7 ) ,
void * V_206 , int V_74 )
{
int V_250 = F_28 ( V_7 ) -> V_88 ;
int V_182 ;
int V_71 = 0 ;
int V_205 ;
struct V_189 * V_190 = & V_251 -> V_252 ;
do {
if ( V_250 >= V_194 )
return - V_253 ;
if ( ! F_152 ( V_137 , V_190 ) )
return - V_146 ;
V_182 = F_153 ( int , V_74 , V_190 -> V_19 - V_190 -> V_71 ) ;
V_205 = F_210 ( V_206 , F_42 ( V_190 -> V_5 ) + V_190 -> V_71 ,
V_71 , V_182 , 0 , V_7 ) ;
if ( V_205 < 0 )
return - V_184 ;
F_49 ( V_7 , V_250 , V_190 -> V_5 , V_190 -> V_71 ,
V_182 ) ;
V_250 ++ ;
V_190 -> V_71 += V_182 ;
F_4 ( V_190 -> V_5 ) ;
V_7 -> V_32 += V_182 ;
F_211 ( V_182 , & V_137 -> V_254 ) ;
V_7 -> V_11 += V_182 ;
V_7 -> V_81 += V_182 ;
V_71 += V_182 ;
V_74 -= V_182 ;
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
struct V_6 * F_214 ( struct V_6 * V_7 , T_9 V_255 )
{
struct V_6 * V_104 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_256 = F_28 ( V_7 ) -> V_83 ;
unsigned int V_257 = F_28 ( V_7 ) -> V_148 ;
unsigned int V_258 = V_7 -> V_13 - F_215 ( V_7 ) ;
unsigned int V_71 = V_258 ;
unsigned int V_259 = F_216 ( V_7 ) ;
unsigned int V_152 ;
unsigned int V_11 ;
T_10 V_260 ;
bool V_120 ;
int V_261 = ! ! ( V_255 & V_262 ) ;
int V_170 = F_28 ( V_7 ) -> V_88 ;
int V_166 = - V_146 ;
int V_79 = 0 ;
int V_207 ;
V_260 = F_217 ( V_7 ) ;
if ( F_37 ( ! V_260 ) )
return F_218 ( - V_263 ) ;
V_120 = ! ! F_219 ( V_255 , V_260 ) ;
F_220 ( V_7 , V_258 ) ;
V_152 = F_96 ( V_7 ) ;
V_207 = F_120 ( V_7 ) ;
do {
struct V_6 * V_264 ;
T_6 * V_61 ;
int V_265 ;
int V_19 ;
V_11 = V_7 -> V_11 - V_71 ;
if ( V_11 > V_257 )
V_11 = V_257 ;
V_265 = F_120 ( V_7 ) - V_71 ;
if ( V_265 < 0 )
V_265 = 0 ;
if ( V_265 > V_11 || ! V_261 )
V_265 = V_11 ;
if ( ! V_265 && V_79 >= V_170 ) {
F_124 ( V_256 -> V_11 != V_11 ) ;
V_207 += V_11 ;
V_264 = F_108 ( V_256 , V_55 ) ;
V_256 = V_256 -> V_105 ;
if ( F_37 ( ! V_264 ) )
goto V_166;
V_265 = F_116 ( V_264 ) ;
if ( F_221 ( V_264 , V_258 + V_152 ) ) {
F_80 ( V_264 ) ;
goto V_166;
}
V_264 -> V_32 += F_116 ( V_264 ) - V_265 ;
F_64 ( V_264 ) ;
F_220 ( V_264 , V_258 ) ;
} else {
V_264 = F_19 ( V_265 + V_258 + V_152 ,
V_55 , F_114 ( V_7 ) ,
V_78 ) ;
if ( F_37 ( ! V_264 ) )
goto V_166;
F_47 ( V_264 , V_152 ) ;
F_222 ( V_264 , V_258 ) ;
}
if ( V_104 )
V_14 -> V_105 = V_264 ;
else
V_104 = V_264 ;
V_14 = V_264 ;
F_87 ( V_264 , V_7 ) ;
V_264 -> V_138 = V_7 -> V_138 ;
if ( V_264 -> V_123 == V_156 )
V_264 -> V_157 += F_96 ( V_264 ) - V_152 ;
F_223 ( V_264 ) ;
F_224 ( V_264 , V_7 -> V_138 ) ;
V_264 -> V_44 = ( V_264 -> V_109 +
F_225 ( V_7 ) ) ;
F_148 ( V_7 , - V_259 ,
V_264 -> V_13 - V_259 ,
V_258 + V_259 ) ;
if ( V_256 != F_28 ( V_7 ) -> V_83 )
goto V_266;
if ( ! V_261 ) {
V_264 -> V_123 = V_267 ;
V_264 -> V_120 = F_170 ( V_7 , V_71 ,
F_117 ( V_264 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_61 = F_28 ( V_264 ) -> V_145 ;
F_148 ( V_7 , V_71 ,
F_117 ( V_264 , V_265 ) , V_265 ) ;
F_28 ( V_264 ) -> V_89 = F_28 ( V_7 ) -> V_89 & V_218 ;
while ( V_207 < V_71 + V_11 && V_79 < V_170 ) {
* V_61 = F_28 ( V_7 ) -> V_145 [ V_79 ] ;
F_199 ( V_61 ) ;
V_19 = F_104 ( V_61 ) ;
if ( V_207 < V_71 ) {
V_61 -> V_147 += V_71 - V_207 ;
F_147 ( V_61 , V_71 - V_207 ) ;
}
F_28 ( V_264 ) -> V_88 ++ ;
if ( V_207 + V_19 <= V_71 + V_11 ) {
V_79 ++ ;
V_207 += V_19 ;
} else {
F_147 ( V_61 , V_207 + V_19 - ( V_71 + V_11 ) ) ;
goto V_268;
}
V_61 ++ ;
}
if ( V_207 < V_71 + V_11 ) {
struct V_6 * V_269 = V_256 ;
F_124 ( V_207 + V_256 -> V_11 != V_71 + V_11 ) ;
V_207 += V_256 -> V_11 ;
V_256 = V_256 -> V_105 ;
if ( V_269 -> V_105 ) {
V_269 = F_108 ( V_269 , V_55 ) ;
if ( ! V_269 )
goto V_166;
} else
F_55 ( V_269 ) ;
F_226 ( V_264 ) ;
F_28 ( V_264 ) -> V_83 = V_269 ;
}
V_268:
V_264 -> V_81 = V_11 - V_265 ;
V_264 -> V_11 += V_264 -> V_81 ;
V_264 -> V_32 += V_264 -> V_81 ;
V_266:
if ( ! V_120 ) {
V_264 -> V_120 = F_167 ( V_264 , V_258 ,
V_264 -> V_11 - V_258 , 0 ) ;
V_264 -> V_123 = V_267 ;
}
} while ( ( V_71 += V_11 ) < V_7 -> V_11 );
return V_104 ;
V_166:
while ( ( V_7 = V_104 ) ) {
V_104 = V_7 -> V_105 ;
F_80 ( V_7 ) ;
}
return F_218 ( V_166 ) ;
}
int F_227 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_270 = * V_12 ;
struct V_6 * V_264 ;
struct V_37 * V_271 = F_28 ( V_7 ) ;
struct V_37 * V_272 = F_28 ( V_270 ) ;
unsigned int V_152 ;
unsigned int V_11 = F_228 ( V_7 ) ;
unsigned int V_71 = F_229 ( V_7 ) ;
unsigned int V_273 = F_120 ( V_7 ) ;
unsigned int V_274 ;
if ( V_270 -> V_11 + V_11 >= 65536 )
return - V_275 ;
if ( V_272 -> V_83 )
goto V_221;
else if ( V_273 <= V_71 ) {
T_6 * V_61 ;
T_6 * V_276 ;
int V_79 = V_271 -> V_88 ;
int V_88 = V_272 -> V_88 + V_79 ;
V_71 -= V_273 ;
if ( V_88 > V_194 )
return - V_275 ;
V_272 -> V_88 = V_88 ;
V_271 -> V_88 = 0 ;
V_61 = V_272 -> V_145 + V_88 ;
V_276 = V_271 -> V_145 + V_79 ;
do {
* -- V_61 = * -- V_276 ;
} while ( -- V_79 );
V_61 -> V_147 += V_71 ;
F_147 ( V_61 , V_71 ) ;
V_274 = V_7 -> V_32 -
F_26 ( F_116 ( V_7 ) ) ;
V_7 -> V_32 -= V_7 -> V_81 ;
V_7 -> V_11 -= V_7 -> V_81 ;
V_7 -> V_81 = 0 ;
F_230 ( V_7 ) -> free = V_277 ;
goto V_172;
} else if ( V_7 -> V_56 ) {
int V_88 = V_272 -> V_88 ;
T_6 * V_61 = V_272 -> V_145 + V_88 ;
struct V_5 * V_5 = F_46 ( V_7 -> V_12 ) ;
unsigned int V_278 = V_273 - V_71 ;
unsigned int V_279 ;
if ( V_88 + 1 + V_271 -> V_88 > V_194 )
return - V_275 ;
V_279 = V_7 -> V_13 -
( unsigned char * ) F_42 ( V_5 ) +
V_71 ;
V_272 -> V_88 = V_88 + 1 + V_271 -> V_88 ;
V_61 -> V_5 . V_270 = V_5 ;
V_61 -> V_147 = V_279 ;
F_142 ( V_61 , V_278 ) ;
memcpy ( V_61 + 1 , V_271 -> V_145 , sizeof( * V_61 ) * V_271 -> V_88 ) ;
V_274 = V_7 -> V_32 - F_22 ( sizeof( struct V_6 ) ) ;
F_230 ( V_7 ) -> free = V_280 ;
goto V_172;
} else if ( F_228 ( V_270 ) != V_272 -> V_148 )
return - V_275 ;
V_152 = F_96 ( V_270 ) ;
V_264 = F_231 ( V_152 + F_229 ( V_270 ) , V_55 ) ;
if ( F_37 ( ! V_264 ) )
return - V_146 ;
F_87 ( V_264 , V_270 ) ;
V_264 -> V_138 = V_270 -> V_138 ;
F_47 ( V_264 , V_152 ) ;
F_222 ( V_264 , F_229 ( V_270 ) ) ;
F_232 ( V_264 , F_215 ( V_270 ) - V_270 -> V_13 ) ;
F_224 ( V_264 , F_233 ( V_270 ) ) ;
F_234 ( V_264 , F_235 ( V_270 ) ) ;
F_236 ( V_270 , F_229 ( V_270 ) ) ;
memcpy ( F_215 ( V_264 ) , F_215 ( V_270 ) ,
V_270 -> V_13 - F_215 ( V_270 ) ) ;
F_28 ( V_264 ) -> V_83 = V_270 ;
F_28 ( V_264 ) -> V_148 = V_272 -> V_148 ;
V_272 -> V_148 = 0 ;
F_237 ( V_270 ) ;
F_230 ( V_264 ) -> V_281 = V_270 ;
V_264 -> V_81 += V_270 -> V_11 ;
V_264 -> V_32 += V_270 -> V_32 ;
V_264 -> V_11 += V_270 -> V_11 ;
* V_12 = V_264 ;
V_264 -> V_105 = V_270 -> V_105 ;
V_270 -> V_105 = NULL ;
V_270 = V_264 ;
V_221:
V_274 = V_7 -> V_32 ;
if ( V_71 > V_273 ) {
unsigned int V_175 = V_71 - V_273 ;
V_271 -> V_145 [ 0 ] . V_147 += V_175 ;
F_147 ( & V_271 -> V_145 [ 0 ] , V_175 ) ;
V_7 -> V_81 -= V_175 ;
V_7 -> V_11 -= V_175 ;
V_71 = V_273 ;
}
F_236 ( V_7 , V_71 ) ;
F_230 ( V_270 ) -> V_281 -> V_105 = V_7 ;
F_230 ( V_270 ) -> V_281 = V_7 ;
F_237 ( V_7 ) ;
V_172:
F_230 ( V_270 ) -> V_282 ++ ;
V_270 -> V_81 += V_11 ;
V_270 -> V_32 += V_274 ;
V_270 -> V_11 += V_11 ;
F_230 ( V_7 ) -> V_283 = 1 ;
return 0 ;
}
void T_11 F_238 ( void )
{
V_30 = F_239 ( L_3 ,
sizeof( struct V_6 ) ,
0 ,
V_284 | V_285 ,
NULL ) ;
V_40 = F_239 ( L_4 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_4 ) ,
0 ,
V_284 | V_285 ,
NULL ) ;
}
static int
F_240 ( struct V_6 * V_7 , struct V_286 * V_261 , int V_71 , int V_11 )
{
int V_180 = F_120 ( V_7 ) ;
int V_79 , V_182 = V_180 - V_71 ;
struct V_6 * V_181 ;
int V_287 = 0 ;
if ( V_182 > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
F_241 ( V_261 , V_7 -> V_13 + V_71 , V_182 ) ;
V_287 ++ ;
if ( ( V_11 -= V_182 ) == 0 )
return V_287 ;
V_71 += V_182 ;
}
for ( V_79 = 0 ; V_79 < F_28 ( V_7 ) -> V_88 ; V_79 ++ ) {
int V_15 ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + F_104 ( & F_28 ( V_7 ) -> V_145 [ V_79 ] ) ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
T_6 * V_61 = & F_28 ( V_7 ) -> V_145 [ V_79 ] ;
if ( V_182 > V_11 )
V_182 = V_11 ;
F_242 ( & V_261 [ V_287 ] , F_103 ( V_61 ) , V_182 ,
V_61 -> V_147 + V_71 - V_180 ) ;
V_287 ++ ;
if ( ! ( V_11 -= V_182 ) )
return V_287 ;
V_71 += V_182 ;
}
V_180 = V_15 ;
}
F_54 (skb, frag_iter) {
int V_15 ;
F_68 ( V_180 > V_71 + V_11 ) ;
V_15 = V_180 + V_181 -> V_11 ;
if ( ( V_182 = V_15 - V_71 ) > 0 ) {
if ( V_182 > V_11 )
V_182 = V_11 ;
V_287 += F_240 ( V_181 , V_261 + V_287 , V_71 - V_180 ,
V_182 ) ;
if ( ( V_11 -= V_182 ) == 0 )
return V_287 ;
V_71 += V_182 ;
}
V_180 = V_15 ;
}
F_124 ( V_11 ) ;
return V_287 ;
}
int F_243 ( struct V_6 * V_7 , struct V_286 * V_261 , int V_71 , int V_11 )
{
int V_288 = F_240 ( V_7 , V_261 , V_71 , V_11 ) ;
F_244 ( & V_261 [ V_288 - 1 ] ) ;
return V_288 ;
}
int F_245 ( struct V_6 * V_7 , int V_289 , struct V_6 * * V_290 )
{
int V_291 ;
int V_287 ;
struct V_6 * V_217 , * * V_292 ;
if ( ( F_127 ( V_7 ) || F_28 ( V_7 ) -> V_88 ) &&
F_145 ( V_7 , F_246 ( V_7 ) - F_120 ( V_7 ) ) == NULL )
return - V_146 ;
if ( ! F_61 ( V_7 ) ) {
if ( F_133 ( V_7 ) < V_289 &&
F_123 ( V_7 , 0 , V_289 - F_133 ( V_7 ) + 128 , V_55 ) )
return - V_146 ;
* V_290 = V_7 ;
return 1 ;
}
V_287 = 1 ;
V_292 = & F_28 ( V_7 ) -> V_83 ;
V_291 = 0 ;
while ( ( V_217 = * V_292 ) != NULL ) {
int V_154 = 0 ;
if ( F_125 ( V_217 ) )
V_291 = 1 ;
if ( V_217 -> V_105 == NULL && V_289 ) {
if ( F_28 ( V_217 ) -> V_88 ||
F_61 ( V_217 ) ||
F_133 ( V_217 ) < V_289 )
V_154 = V_289 + 128 ;
}
if ( V_291 ||
F_127 ( V_217 ) ||
V_154 ||
F_28 ( V_217 ) -> V_88 ||
F_61 ( V_217 ) ) {
struct V_6 * V_158 ;
if ( V_154 == 0 )
V_158 = F_115 ( V_217 , V_55 ) ;
else
V_158 = F_131 ( V_217 ,
F_96 ( V_217 ) ,
V_154 ,
V_55 ) ;
if ( F_37 ( V_158 == NULL ) )
return - V_146 ;
if ( V_217 -> V_137 )
F_247 ( V_158 , V_217 -> V_137 ) ;
V_158 -> V_105 = V_217 -> V_105 ;
* V_292 = V_158 ;
F_80 ( V_217 ) ;
V_217 = V_158 ;
}
V_287 ++ ;
* V_290 = V_217 ;
V_292 = & V_217 -> V_105 ;
}
return V_287 ;
}
static void F_248 ( struct V_6 * V_7 )
{
struct V_188 * V_137 = V_7 -> V_137 ;
F_249 ( V_7 -> V_32 , & V_137 -> V_293 ) ;
}
int F_250 ( struct V_188 * V_137 , struct V_6 * V_7 )
{
int V_11 = V_7 -> V_11 ;
if ( F_40 ( & V_137 -> V_293 ) + V_7 -> V_32 >=
( unsigned int ) V_137 -> V_294 )
return - V_146 ;
F_251 ( V_7 ) ;
V_7 -> V_137 = V_137 ;
V_7 -> V_97 = F_248 ;
F_211 ( V_7 -> V_32 , & V_137 -> V_293 ) ;
F_252 ( V_7 ) ;
F_184 ( & V_137 -> V_295 , V_7 ) ;
if ( ! F_253 ( V_137 , V_296 ) )
V_137 -> V_297 ( V_137 , V_11 ) ;
return 0 ;
}
void F_254 ( struct V_6 * V_298 ,
struct V_299 * V_300 )
{
struct V_188 * V_137 = V_298 -> V_137 ;
struct V_301 * V_302 ;
struct V_6 * V_7 ;
int V_166 ;
if ( ! V_137 )
return;
if ( V_300 ) {
* F_255 ( V_298 ) =
* V_300 ;
} else {
V_298 -> V_108 = F_256 () ;
}
V_7 = F_108 ( V_298 , V_55 ) ;
if ( ! V_7 )
return;
V_302 = F_257 ( V_7 ) ;
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
V_302 -> V_303 . V_304 = V_305 ;
V_302 -> V_303 . V_306 = V_307 ;
V_166 = F_250 ( V_137 , V_7 ) ;
if ( V_166 )
F_80 ( V_7 ) ;
}
void F_258 ( struct V_6 * V_7 , bool V_308 )
{
struct V_188 * V_137 = V_7 -> V_137 ;
struct V_301 * V_302 ;
int V_166 ;
V_7 -> V_309 = 1 ;
V_7 -> V_310 = V_308 ;
V_302 = F_257 ( V_7 ) ;
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
V_302 -> V_303 . V_304 = V_305 ;
V_302 -> V_303 . V_306 = V_311 ;
V_166 = F_250 ( V_137 , V_7 ) ;
if ( V_166 )
F_80 ( V_7 ) ;
}
bool F_259 ( struct V_6 * V_7 , T_12 V_180 , T_12 V_80 )
{
if ( F_37 ( V_180 > F_120 ( V_7 ) ) ||
F_37 ( ( int ) V_180 + V_80 > F_120 ( V_7 ) - 2 ) ) {
F_260 ( L_5 ,
V_180 , V_80 , F_120 ( V_7 ) ) ;
return false ;
}
V_7 -> V_123 = V_156 ;
V_7 -> V_157 = F_96 ( V_7 ) + V_180 ;
V_7 -> V_211 = V_80 ;
F_234 ( V_7 , V_180 ) ;
return true ;
}
void F_261 ( const struct V_6 * V_7 )
{
F_260 ( L_6 ,
V_7 -> V_16 -> V_17 ) ;
}
void F_262 ( struct V_6 * V_7 , bool V_312 )
{
if ( V_312 ) {
F_64 ( V_7 ) ;
F_31 ( V_30 , V_7 ) ;
} else {
F_79 ( V_7 ) ;
}
}
bool F_263 ( struct V_6 * V_179 , struct V_6 * V_206 ,
bool * V_313 , int * V_274 )
{
int V_79 , V_159 , V_11 = V_206 -> V_11 ;
* V_313 = false ;
if ( F_127 ( V_179 ) )
return false ;
if ( V_11 <= F_133 ( V_179 ) ) {
F_124 ( F_118 ( V_206 , 0 , F_117 ( V_179 , V_11 ) , V_11 ) ) ;
* V_274 = 0 ;
return true ;
}
if ( F_61 ( V_179 ) || F_61 ( V_206 ) )
return false ;
if ( F_120 ( V_206 ) != 0 ) {
struct V_5 * V_5 ;
unsigned int V_71 ;
if ( F_28 ( V_179 ) -> V_88 +
F_28 ( V_206 ) -> V_88 >= V_194 )
return false ;
if ( F_160 ( V_206 ) )
return false ;
V_159 = V_206 -> V_32 - F_22 ( sizeof( struct V_6 ) ) ;
V_5 = F_46 ( V_206 -> V_12 ) ;
V_71 = V_206 -> V_13 - ( unsigned char * ) F_42 ( V_5 ) ;
F_49 ( V_179 , F_28 ( V_179 ) -> V_88 ,
V_5 , V_71 , F_120 ( V_206 ) ) ;
* V_313 = true ;
} else {
if ( F_28 ( V_179 ) -> V_88 +
F_28 ( V_206 ) -> V_88 > V_194 )
return false ;
V_159 = V_206 -> V_32 - F_26 ( F_116 ( V_206 ) ) ;
}
F_264 ( V_159 < V_11 ) ;
memcpy ( F_28 ( V_179 ) -> V_145 + F_28 ( V_179 ) -> V_88 ,
F_28 ( V_206 ) -> V_145 ,
F_28 ( V_206 ) -> V_88 * sizeof( T_6 ) ) ;
F_28 ( V_179 ) -> V_88 += F_28 ( V_206 ) -> V_88 ;
if ( ! F_127 ( V_206 ) )
F_28 ( V_206 ) -> V_88 = 0 ;
for ( V_79 = 0 ; V_79 < F_28 ( V_206 ) -> V_88 ; V_79 ++ )
F_122 ( V_206 , V_79 ) ;
V_179 -> V_32 += V_159 ;
V_179 -> V_11 += V_11 ;
V_179 -> V_81 += V_11 ;
* V_274 = V_159 ;
return true ;
}
void F_265 ( struct V_6 * V_7 , bool V_314 )
{
if ( V_314 )
F_251 ( V_7 ) ;
V_7 -> V_108 . V_315 = 0 ;
V_7 -> V_122 = V_316 ;
V_7 -> V_129 = 0 ;
F_65 ( V_7 ) ;
V_7 -> V_128 = 0 ;
F_266 ( V_7 ) ;
F_267 ( V_7 ) ;
F_268 ( V_7 ) ;
}
