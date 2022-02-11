static void F_1 ( struct V_1 * V_2 , unsigned int V_3 , void * V_4 ,
const char V_5 [] )
{
F_2 ( L_1 ,
V_5 , V_4 , V_2 -> V_6 , V_3 , V_2 -> V_7 , V_2 -> V_8 ,
( unsigned long ) V_2 -> V_9 , ( unsigned long ) V_2 -> V_10 ,
V_2 -> V_11 ? V_2 -> V_11 -> V_12 : L_2 ) ;
F_3 () ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_3 , void * V_4 )
{
F_1 ( V_2 , V_3 , V_4 , V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 , void * V_4 )
{
F_1 ( V_2 , V_3 , V_4 , V_13 ) ;
}
static void * F_6 ( T_1 V_14 , T_2 V_15 , int V_16 ,
unsigned long V_17 , bool * V_18 )
{
void * V_19 ;
bool V_20 = false ;
V_19 = F_7 ( V_14 ,
V_15 | V_21 | V_22 ,
V_16 ) ;
if ( V_19 || ! ( F_8 ( V_15 ) ) )
goto V_23;
V_20 = true ;
V_19 = F_7 ( V_14 , V_15 , V_16 ) ;
V_23:
if ( V_18 )
* V_18 = V_20 ;
return V_19 ;
}
struct V_1 * F_9 ( T_2 V_24 , int V_16 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( V_25 ,
V_24 & ~ V_26 , V_16 ) ;
if ( ! V_2 )
goto V_23;
memset ( V_2 , 0 , F_11 ( struct V_1 , V_9 ) ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_27 = sizeof( struct V_1 ) ;
F_12 ( & V_2 -> V_28 , 1 ) ;
V_2 -> V_29 = ( F_13 ( V_2 -> V_29 ) ) ~ 0U ;
V_23:
return V_2 ;
}
struct V_1 * F_14 ( unsigned int V_14 , T_2 V_24 ,
int V_15 , int V_16 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
T_3 * V_8 ;
bool V_18 ;
V_31 = ( V_15 & V_34 )
? V_35 : V_25 ;
if ( F_15 () && ( V_15 & V_36 ) )
V_24 |= V_37 ;
V_2 = F_10 ( V_31 , V_24 & ~ V_26 , V_16 ) ;
if ( ! V_2 )
goto V_23;
F_16 ( V_2 ) ;
V_14 = F_17 ( V_14 ) ;
V_14 += F_17 ( sizeof( struct V_32 ) ) ;
V_8 = F_18 ( V_14 , V_24 , V_16 , & V_18 ) ;
if ( ! V_8 )
goto V_38;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
F_16 ( V_8 + V_14 ) ;
memset ( V_2 , 0 , F_11 ( struct V_1 , V_9 ) ) ;
V_2 -> V_27 = F_21 ( V_14 ) ;
V_2 -> V_18 = V_18 ;
F_12 ( & V_2 -> V_28 , 1 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_8 = V_8 ;
F_22 ( V_2 ) ;
V_2 -> V_10 = V_2 -> V_9 + V_14 ;
V_2 -> V_29 = ( F_13 ( V_2 -> V_29 ) ) ~ 0U ;
V_2 -> V_39 = ( F_13 ( V_2 -> V_39 ) ) ~ 0U ;
V_33 = F_23 ( V_2 ) ;
memset ( V_33 , 0 , F_11 ( struct V_32 , V_40 ) ) ;
F_12 ( & V_33 -> V_40 , 1 ) ;
F_24 ( V_33 -> V_41 ) ;
if ( V_15 & V_34 ) {
struct V_1 * V_42 = V_2 + 1 ;
T_4 * V_43 = ( T_4 * ) ( V_42 + 1 ) ;
F_25 ( V_42 , V_44 ) ;
F_25 ( V_42 , V_45 ) ;
V_2 -> V_46 = V_47 ;
F_12 ( V_43 , 1 ) ;
V_42 -> V_46 = V_48 ;
V_42 -> V_18 = V_18 ;
}
V_23:
return V_2 ;
V_38:
F_26 ( V_31 , V_2 ) ;
V_2 = NULL ;
goto V_23;
}
struct V_1 * F_27 ( void * V_8 , unsigned int V_49 )
{
struct V_32 * V_33 ;
struct V_1 * V_2 ;
unsigned int V_14 = V_49 ? : F_20 ( V_8 ) ;
V_2 = F_28 ( V_25 , V_50 ) ;
if ( ! V_2 )
return NULL ;
V_14 -= F_17 ( sizeof( struct V_32 ) ) ;
memset ( V_2 , 0 , F_11 ( struct V_1 , V_9 ) ) ;
V_2 -> V_27 = F_21 ( V_14 ) ;
V_2 -> V_51 = V_49 != 0 ;
F_12 ( & V_2 -> V_28 , 1 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_8 = V_8 ;
F_22 ( V_2 ) ;
V_2 -> V_10 = V_2 -> V_9 + V_14 ;
V_2 -> V_29 = ( F_13 ( V_2 -> V_29 ) ) ~ 0U ;
V_2 -> V_39 = ( F_13 ( V_2 -> V_39 ) ) ~ 0U ;
V_33 = F_23 ( V_2 ) ;
memset ( V_33 , 0 , F_11 ( struct V_32 , V_40 ) ) ;
F_12 ( & V_33 -> V_40 , 1 ) ;
F_24 ( V_33 -> V_41 ) ;
return V_2 ;
}
static void * F_29 ( unsigned int V_52 , T_2 V_24 )
{
struct V_53 * V_54 ;
void * V_8 = NULL ;
int V_55 ;
unsigned long V_15 ;
F_30 ( V_15 ) ;
V_54 = & F_31 ( V_53 ) ;
if ( F_32 ( ! V_54 -> V_56 . V_57 ) ) {
V_58:
for ( V_55 = V_59 ; ; ) {
T_2 V_60 = V_24 ;
if ( V_55 )
V_60 |= V_61 | V_22 ;
V_54 -> V_56 . V_57 = F_33 ( V_60 , V_55 ) ;
if ( F_34 ( V_54 -> V_56 . V_57 ) )
break;
if ( -- V_55 < 0 )
goto V_10;
}
V_54 -> V_56 . V_14 = V_62 << V_55 ;
V_63:
F_12 ( & V_54 -> V_56 . V_57 -> V_64 , V_65 ) ;
V_54 -> V_66 = V_65 ;
V_54 -> V_56 . V_67 = 0 ;
}
if ( V_54 -> V_56 . V_67 + V_52 > V_54 -> V_56 . V_14 ) {
if ( ( F_35 ( & V_54 -> V_56 . V_57 -> V_64 ) == V_54 -> V_66 ) ||
F_36 ( V_54 -> V_66 , & V_54 -> V_56 . V_57 -> V_64 ) )
goto V_63;
goto V_58;
}
V_8 = F_37 ( V_54 -> V_56 . V_57 ) + V_54 -> V_56 . V_67 ;
V_54 -> V_56 . V_67 += V_52 ;
V_54 -> V_66 -- ;
V_10:
F_38 ( V_15 ) ;
return V_8 ;
}
void * F_39 ( unsigned int V_52 )
{
return F_29 ( V_52 , V_50 | V_68 ) ;
}
struct V_1 * F_40 ( struct V_69 * V_11 ,
unsigned int V_70 , T_2 V_24 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_52 = F_17 ( V_70 + V_71 ) +
F_17 ( sizeof( struct V_32 ) ) ;
if ( V_52 <= V_62 && ! ( V_24 & ( V_72 | V_73 ) ) ) {
void * V_8 ;
if ( F_15 () )
V_24 |= V_37 ;
V_8 = F_29 ( V_52 , V_24 ) ;
if ( F_34 ( V_8 ) ) {
V_2 = F_27 ( V_8 , V_52 ) ;
if ( F_32 ( ! V_2 ) )
F_41 ( F_42 ( V_8 ) ) ;
}
} else {
V_2 = F_14 ( V_70 + V_71 , V_24 ,
V_36 , V_74 ) ;
}
if ( F_34 ( V_2 ) ) {
F_43 ( V_2 , V_71 ) ;
V_2 -> V_11 = V_11 ;
}
return V_2 ;
}
void F_44 ( struct V_1 * V_2 , int V_75 , struct V_57 * V_57 , int V_76 ,
int V_14 , unsigned int V_27 )
{
F_45 ( V_2 , V_75 , V_57 , V_76 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_77 += V_14 ;
V_2 -> V_27 += V_27 ;
}
void F_46 ( struct V_1 * V_2 , int V_75 , int V_14 ,
unsigned int V_27 )
{
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_47 ( V_56 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_77 += V_14 ;
V_2 -> V_27 += V_27 ;
}
static void F_48 ( struct V_1 * * V_79 )
{
F_49 ( * V_79 ) ;
* V_79 = NULL ;
}
static inline void F_50 ( struct V_1 * V_2 )
{
F_48 ( & F_23 ( V_2 ) -> V_80 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_1 * V_81 ;
F_52 (skb, list)
F_53 ( V_81 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 )
F_41 ( F_42 ( V_2 -> V_7 ) ) ;
else
F_55 ( V_2 -> V_7 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_82 ||
! F_57 ( V_2 -> V_83 ? ( 1 << V_84 ) + 1 : 1 ,
& F_23 ( V_2 ) -> V_40 ) ) {
if ( F_23 ( V_2 ) -> V_85 ) {
int V_75 ;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ )
F_58 ( V_2 , V_75 ) ;
}
if ( F_23 ( V_2 ) -> V_86 & V_87 ) {
struct V_88 * V_89 ;
V_89 = F_23 ( V_2 ) -> V_41 ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 , true ) ;
}
if ( F_59 ( V_2 ) )
F_50 ( V_2 ) ;
F_54 ( V_2 ) ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_1 * V_91 ;
T_4 * V_43 ;
switch ( V_2 -> V_46 ) {
case V_48 :
F_26 ( V_25 , V_2 ) ;
break;
case V_47 :
V_43 = ( T_4 * ) ( V_2 + 2 ) ;
if ( F_61 ( V_43 ) )
F_26 ( V_35 , V_2 ) ;
break;
case V_92 :
V_43 = ( T_4 * ) ( V_2 + 1 ) ;
V_91 = V_2 - 1 ;
V_2 -> V_46 = V_48 ;
if ( F_61 ( V_43 ) )
F_26 ( V_35 , V_91 ) ;
break;
}
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
#ifdef F_64
F_65 ( V_2 -> V_93 ) ;
#endif
if ( V_2 -> V_94 ) {
F_66 ( F_67 () ) ;
V_2 -> V_94 ( V_2 ) ;
}
#if F_68 ( V_95 )
F_69 ( V_2 -> V_96 ) ;
#endif
#ifdef F_70
F_71 ( V_2 -> V_97 ) ;
#endif
#ifdef F_72
V_2 -> V_98 = 0 ;
#ifdef F_73
V_2 -> V_99 = 0 ;
#endif
#endif
}
static void F_74 ( struct V_1 * V_2 )
{
F_62 ( V_2 ) ;
if ( F_34 ( V_2 -> V_7 ) )
F_56 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_74 ( V_2 ) ;
F_60 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 ) )
return;
if ( F_34 ( F_35 ( & V_2 -> V_28 ) == 1 ) )
F_77 () ;
else if ( F_34 ( ! F_61 ( & V_2 -> V_28 ) ) )
return;
F_78 ( V_2 , F_79 ( 0 ) ) ;
F_75 ( V_2 ) ;
}
void F_49 ( struct V_1 * V_100 )
{
while ( V_100 ) {
struct V_1 * V_101 = V_100 -> V_101 ;
F_76 ( V_100 ) ;
V_100 = V_101 ;
}
}
void F_80 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) -> V_86 & V_87 ) {
struct V_88 * V_89 ;
V_89 = F_23 ( V_2 ) -> V_41 ;
if ( V_89 -> V_90 )
V_89 -> V_90 ( V_89 , false ) ;
F_23 ( V_2 ) -> V_86 &= ~ V_87 ;
}
}
void F_81 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 ) )
return;
if ( F_34 ( F_35 ( & V_2 -> V_28 ) == 1 ) )
F_77 () ;
else if ( F_34 ( ! F_61 ( & V_2 -> V_28 ) ) )
return;
F_82 ( V_2 ) ;
F_75 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_102 , const struct V_1 * V_103 )
{
V_102 -> V_104 = V_103 -> V_104 ;
V_102 -> V_11 = V_103 -> V_11 ;
V_102 -> V_39 = V_103 -> V_39 ;
V_102 -> V_105 = V_103 -> V_105 ;
V_102 -> V_29 = V_103 -> V_29 ;
V_102 -> V_106 = V_103 -> V_106 ;
V_102 -> V_107 = V_103 -> V_107 ;
V_102 -> V_108 = V_103 -> V_108 ;
V_102 -> V_109 = V_103 -> V_109 ;
F_84 ( V_102 , V_103 ) ;
F_85 ( V_102 , V_103 ) ;
V_102 -> V_110 = V_103 -> V_110 ;
V_102 -> V_111 = V_103 -> V_111 ;
V_102 -> V_112 = V_103 -> V_112 ;
V_102 -> V_113 = V_103 -> V_113 ;
V_102 -> V_114 = V_103 -> V_114 ;
V_102 -> V_115 = V_103 -> V_115 ;
#ifdef F_64
V_102 -> V_93 = F_86 ( V_103 -> V_93 ) ;
#endif
memcpy ( V_102 -> V_116 , V_103 -> V_116 , sizeof( V_103 -> V_116 ) ) ;
V_102 -> V_117 = V_103 -> V_117 ;
V_102 -> V_118 = V_103 -> V_118 ;
V_102 -> V_119 = V_103 -> V_119 ;
V_102 -> V_120 = V_103 -> V_120 ;
F_87 ( V_102 , V_103 ) ;
V_102 -> V_121 = V_103 -> V_121 ;
#if F_68 ( V_122 )
V_102 -> V_123 = V_103 -> V_123 ;
#endif
V_102 -> V_18 = V_103 -> V_18 ;
V_102 -> V_124 = V_103 -> V_124 ;
V_102 -> V_125 = V_103 -> V_125 ;
V_102 -> V_126 = V_103 -> V_126 ;
F_88 ( V_102 , V_103 ) ;
#ifdef F_72
V_102 -> V_98 = V_103 -> V_98 ;
#ifdef F_73
V_102 -> V_99 = V_103 -> V_99 ;
#endif
#endif
V_102 -> V_127 = V_103 -> V_127 ;
V_102 -> V_128 = V_103 -> V_128 ;
F_89 ( V_102 , V_103 ) ;
#ifdef F_90
V_102 -> V_129 = V_103 -> V_129 ;
#endif
}
static struct V_1 * F_91 ( struct V_1 * V_130 , struct V_1 * V_2 )
{
#define F_92 ( T_6 ) n->x = skb->x
V_130 -> V_101 = V_130 -> V_131 = NULL ;
V_130 -> V_132 = NULL ;
F_83 ( V_130 , V_2 ) ;
F_92 ( V_6 ) ;
F_92 ( V_77 ) ;
F_92 ( V_133 ) ;
V_130 -> V_134 = V_2 -> V_83 ? F_93 ( V_2 ) : V_2 -> V_134 ;
V_130 -> V_82 = 1 ;
V_130 -> V_83 = 0 ;
V_130 -> V_94 = NULL ;
F_92 ( V_9 ) ;
F_92 ( V_10 ) ;
F_92 ( V_7 ) ;
F_92 ( V_51 ) ;
F_92 ( V_8 ) ;
F_92 ( V_27 ) ;
F_12 ( & V_130 -> V_28 , 1 ) ;
F_94 ( & ( F_23 ( V_2 ) -> V_40 ) ) ;
V_2 -> V_82 = 1 ;
return V_130 ;
#undef F_92
}
struct V_1 * F_95 ( struct V_1 * V_135 , struct V_1 * V_136 )
{
F_74 ( V_135 ) ;
return F_91 ( V_135 , V_136 ) ;
}
int F_96 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_75 ;
int V_137 = F_23 ( V_2 ) -> V_85 ;
struct V_57 * V_57 , * V_7 = NULL ;
struct V_88 * V_89 = F_23 ( V_2 ) -> V_41 ;
for ( V_75 = 0 ; V_75 < V_137 ; V_75 ++ ) {
T_3 * V_138 ;
T_5 * V_139 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
V_57 = F_97 ( V_24 ) ;
if ( ! V_57 ) {
while ( V_7 ) {
struct V_57 * V_101 = (struct V_57 * ) F_98 ( V_7 ) ;
F_41 ( V_7 ) ;
V_7 = V_101 ;
}
return - V_140 ;
}
V_138 = F_99 ( F_100 ( V_139 ) ) ;
memcpy ( F_37 ( V_57 ) ,
V_138 + V_139 -> V_141 , F_101 ( V_139 ) ) ;
F_102 ( V_138 ) ;
F_103 ( V_57 , ( unsigned long ) V_7 ) ;
V_7 = V_57 ;
}
for ( V_75 = 0 ; V_75 < V_137 ; V_75 ++ )
F_58 ( V_2 , V_75 ) ;
V_89 -> V_90 ( V_89 , false ) ;
for ( V_75 = V_137 - 1 ; V_75 >= 0 ; V_75 -- ) {
F_104 ( V_2 , V_75 , V_7 , 0 ,
F_23 ( V_2 ) -> V_78 [ V_75 ] . V_14 ) ;
V_7 = (struct V_57 * ) F_98 ( V_7 ) ;
}
F_23 ( V_2 ) -> V_86 &= ~ V_87 ;
return 0 ;
}
struct V_1 * F_105 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_1 * V_130 ;
if ( F_106 ( V_2 , V_24 ) )
return NULL ;
V_130 = V_2 + 1 ;
if ( V_2 -> V_46 == V_47 &&
V_130 -> V_46 == V_48 ) {
T_4 * V_43 = ( T_4 * ) ( V_130 + 1 ) ;
V_130 -> V_46 = V_92 ;
F_94 ( V_43 ) ;
} else {
if ( F_107 ( V_2 ) )
V_24 |= V_37 ;
V_130 = F_28 ( V_25 , V_24 ) ;
if ( ! V_130 )
return NULL ;
F_25 ( V_130 , V_44 ) ;
F_25 ( V_130 , V_45 ) ;
V_130 -> V_46 = V_48 ;
}
return F_91 ( V_130 , V_2 ) ;
}
static void F_108 ( struct V_1 * V_2 , int V_76 )
{
if ( V_2 -> V_120 == V_142 )
V_2 -> V_143 += V_76 ;
V_2 -> V_39 += V_76 ;
V_2 -> V_105 += V_76 ;
if ( F_109 ( V_2 ) )
V_2 -> V_29 += V_76 ;
V_2 -> V_107 += V_76 ;
V_2 -> V_108 += V_76 ;
V_2 -> V_109 += V_76 ;
}
static void F_110 ( struct V_1 * V_102 , const struct V_1 * V_103 )
{
F_83 ( V_102 , V_103 ) ;
F_23 ( V_102 ) -> V_144 = F_23 ( V_103 ) -> V_144 ;
F_23 ( V_102 ) -> V_145 = F_23 ( V_103 ) -> V_145 ;
F_23 ( V_102 ) -> V_146 = F_23 ( V_103 ) -> V_146 ;
}
static inline int F_111 ( const struct V_1 * V_2 )
{
if ( F_107 ( V_2 ) )
return V_36 ;
return 0 ;
}
struct V_1 * F_112 ( const struct V_1 * V_2 , T_2 V_24 )
{
int V_147 = F_93 ( V_2 ) ;
unsigned int V_14 = F_113 ( V_2 ) + V_2 -> V_77 ;
struct V_1 * V_130 = F_14 ( V_14 , V_24 ,
F_111 ( V_2 ) , V_74 ) ;
if ( ! V_130 )
return NULL ;
F_43 ( V_130 , V_147 ) ;
F_114 ( V_130 , V_2 -> V_6 ) ;
if ( F_115 ( V_2 , - V_147 , V_130 -> V_7 , V_147 + V_2 -> V_6 ) )
F_3 () ;
F_110 ( V_130 , V_2 ) ;
return V_130 ;
}
struct V_1 * F_116 ( struct V_1 * V_2 , int V_148 ,
T_2 V_24 , bool V_46 )
{
unsigned int V_14 = F_117 ( V_2 ) + V_148 ;
int V_15 = F_111 ( V_2 ) | ( V_46 ? V_34 : 0 ) ;
struct V_1 * V_130 = F_14 ( V_14 , V_24 , V_15 , V_74 ) ;
if ( ! V_130 )
goto V_23;
F_43 ( V_130 , V_148 ) ;
F_114 ( V_130 , F_117 ( V_2 ) ) ;
F_118 ( V_2 , V_130 -> V_8 , V_130 -> V_6 ) ;
V_130 -> V_27 += V_2 -> V_77 ;
V_130 -> V_77 = V_2 -> V_77 ;
V_130 -> V_6 = V_2 -> V_6 ;
if ( F_23 ( V_2 ) -> V_85 ) {
int V_75 ;
if ( F_106 ( V_2 , V_24 ) ) {
F_76 ( V_130 ) ;
V_130 = NULL ;
goto V_23;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
F_23 ( V_130 ) -> V_78 [ V_75 ] = F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_119 ( V_2 , V_75 ) ;
}
F_23 ( V_130 ) -> V_85 = V_75 ;
}
if ( F_59 ( V_2 ) ) {
F_23 ( V_130 ) -> V_80 = F_23 ( V_2 ) -> V_80 ;
F_51 ( V_130 ) ;
}
F_110 ( V_130 , V_2 ) ;
V_23:
return V_130 ;
}
int F_120 ( struct V_1 * V_2 , int V_149 , int V_150 ,
T_2 V_24 )
{
int V_75 ;
T_3 * V_8 ;
int V_14 = V_149 + F_113 ( V_2 ) + V_150 ;
long V_76 ;
F_121 ( V_149 < 0 ) ;
if ( F_122 ( V_2 ) )
F_3 () ;
V_14 = F_17 ( V_14 ) ;
if ( F_107 ( V_2 ) )
V_24 |= V_37 ;
V_8 = F_18 ( V_14 + F_17 ( sizeof( struct V_32 ) ) ,
V_24 , V_74 , NULL ) ;
if ( ! V_8 )
goto V_38;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
memcpy ( V_8 + V_149 , V_2 -> V_7 , F_123 ( V_2 ) - V_2 -> V_7 ) ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) ,
F_11 ( struct V_32 , V_78 [ F_23 ( V_2 ) -> V_85 ] ) ) ;
if ( F_124 ( V_2 ) ) {
if ( F_106 ( V_2 , V_24 ) )
goto V_151;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ )
F_119 ( V_2 , V_75 ) ;
if ( F_59 ( V_2 ) )
F_51 ( V_2 ) ;
F_56 ( V_2 ) ;
} else {
F_54 ( V_2 ) ;
}
V_76 = ( V_8 + V_149 ) - V_2 -> V_7 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_51 = 0 ;
V_2 -> V_8 += V_76 ;
#ifdef F_125
V_2 -> V_10 = V_14 ;
V_76 = V_149 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
V_2 -> V_9 += V_76 ;
F_108 ( V_2 , V_149 ) ;
V_2 -> V_82 = 0 ;
V_2 -> V_134 = 0 ;
V_2 -> V_83 = 0 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
V_151:
F_55 ( V_8 ) ;
V_38:
return - V_140 ;
}
struct V_1 * F_126 ( struct V_1 * V_2 , unsigned int V_148 )
{
struct V_1 * V_152 ;
int V_153 = V_148 - F_93 ( V_2 ) ;
if ( V_153 <= 0 )
V_152 = F_127 ( V_2 , V_50 ) ;
else {
V_152 = F_105 ( V_2 , V_50 ) ;
if ( V_152 && F_120 ( V_152 , F_17 ( V_153 ) , 0 ,
V_50 ) ) {
F_76 ( V_152 ) ;
V_152 = NULL ;
}
}
return V_152 ;
}
struct V_1 * F_128 ( const struct V_1 * V_2 ,
int V_154 , int V_155 ,
T_2 V_24 )
{
struct V_1 * V_130 = F_14 ( V_154 + V_2 -> V_6 + V_155 ,
V_24 , F_111 ( V_2 ) ,
V_74 ) ;
int V_156 = F_93 ( V_2 ) ;
int V_157 , V_158 ;
if ( ! V_130 )
return NULL ;
F_43 ( V_130 , V_154 ) ;
F_114 ( V_130 , V_2 -> V_6 ) ;
V_157 = V_156 ;
V_158 = 0 ;
if ( V_154 <= V_157 )
V_157 = V_154 ;
else
V_158 = V_154 - V_157 ;
if ( F_115 ( V_2 , - V_157 , V_130 -> V_7 + V_158 ,
V_2 -> V_6 + V_157 ) )
F_3 () ;
F_110 ( V_130 , V_2 ) ;
F_108 ( V_130 , V_154 - V_156 ) ;
return V_130 ;
}
int F_129 ( struct V_1 * V_2 , int V_159 )
{
int V_160 ;
int V_150 ;
if ( ! F_124 ( V_2 ) && F_130 ( V_2 ) >= V_159 ) {
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_159 ) ;
return 0 ;
}
V_150 = V_2 -> V_77 + V_159 - ( V_2 -> V_10 - V_2 -> V_9 ) ;
if ( F_34 ( F_124 ( V_2 ) || V_150 > 0 ) ) {
V_160 = F_120 ( V_2 , 0 , V_150 , V_50 ) ;
if ( F_32 ( V_160 ) )
goto V_161;
}
V_160 = F_131 ( V_2 ) ;
if ( F_32 ( V_160 ) )
goto V_161;
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_159 ) ;
return 0 ;
V_161:
F_76 ( V_2 ) ;
return V_160 ;
}
unsigned char * F_132 ( struct V_1 * V_2 , struct V_1 * V_9 , int V_6 )
{
if ( V_9 != V_2 ) {
V_2 -> V_77 += V_6 ;
V_2 -> V_6 += V_6 ;
}
return F_114 ( V_9 , V_6 ) ;
}
unsigned char * F_114 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned char * V_162 = F_123 ( V_2 ) ;
F_133 ( V_2 ) ;
V_2 -> V_9 += V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_32 ( V_2 -> V_9 > V_2 -> V_10 ) )
F_4 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_162 ;
}
unsigned char * F_134 ( struct V_1 * V_2 , unsigned int V_6 )
{
V_2 -> V_8 -= V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_32 ( V_2 -> V_8 < V_2 -> V_7 ) )
F_5 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_2 -> V_8 ;
}
unsigned char * F_135 ( struct V_1 * V_2 , unsigned int V_6 )
{
return F_136 ( V_2 , V_6 ) ;
}
void F_137 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_2 -> V_6 > V_6 )
F_138 ( V_2 , V_6 ) ;
}
int F_139 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_1 * * V_163 ;
struct V_1 * V_56 ;
int V_67 = F_117 ( V_2 ) ;
int V_164 = F_23 ( V_2 ) -> V_85 ;
int V_75 ;
int V_160 ;
if ( F_124 ( V_2 ) &&
F_32 ( ( V_160 = F_120 ( V_2 , 0 , 0 , V_50 ) ) ) )
return V_160 ;
V_75 = 0 ;
if ( V_67 >= V_6 )
goto V_165;
for (; V_75 < V_164 ; V_75 ++ ) {
int V_10 = V_67 + F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( V_10 < V_6 ) {
V_67 = V_10 ;
continue;
}
F_140 ( & F_23 ( V_2 ) -> V_78 [ V_75 ++ ] , V_6 - V_67 ) ;
V_165:
F_23 ( V_2 ) -> V_85 = V_75 ;
for (; V_75 < V_164 ; V_75 ++ )
F_58 ( V_2 , V_75 ) ;
if ( F_59 ( V_2 ) )
F_50 ( V_2 ) ;
goto V_166;
}
for ( V_163 = & F_23 ( V_2 ) -> V_80 ; ( V_56 = * V_163 ) ;
V_163 = & V_56 -> V_101 ) {
int V_10 = V_67 + V_56 -> V_6 ;
if ( F_122 ( V_56 ) ) {
struct V_1 * V_167 ;
V_167 = F_105 ( V_56 , V_50 ) ;
if ( F_32 ( ! V_167 ) )
return - V_140 ;
V_167 -> V_101 = V_56 -> V_101 ;
F_81 ( V_56 ) ;
V_56 = V_167 ;
* V_163 = V_56 ;
}
if ( V_10 < V_6 ) {
V_67 = V_10 ;
continue;
}
if ( V_10 > V_6 &&
F_32 ( ( V_160 = F_141 ( V_56 , V_6 - V_67 ) ) ) )
return V_160 ;
if ( V_56 -> V_101 )
F_48 ( & V_56 -> V_101 ) ;
break;
}
V_166:
if ( V_6 > F_117 ( V_2 ) ) {
V_2 -> V_77 -= V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
} else {
V_2 -> V_6 = V_6 ;
V_2 -> V_77 = 0 ;
F_142 ( V_2 , V_6 ) ;
}
return 0 ;
}
unsigned char * F_143 ( struct V_1 * V_2 , int V_153 )
{
int V_75 , V_168 , V_169 = ( V_2 -> V_9 + V_153 ) - V_2 -> V_10 ;
if ( V_169 > 0 || F_124 ( V_2 ) ) {
if ( F_120 ( V_2 , 0 , V_169 > 0 ? V_169 + 128 : 0 ,
V_50 ) )
return NULL ;
}
if ( F_115 ( V_2 , F_117 ( V_2 ) , F_123 ( V_2 ) , V_153 ) )
F_3 () ;
if ( ! F_59 ( V_2 ) )
goto V_170;
V_169 = V_153 ;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_14 = F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( V_14 >= V_169 )
goto V_170;
V_169 -= V_14 ;
}
if ( V_169 ) {
struct V_1 * V_81 = F_23 ( V_2 ) -> V_80 ;
struct V_1 * V_171 = NULL ;
struct V_1 * V_172 = NULL ;
do {
F_121 ( ! V_81 ) ;
if ( V_81 -> V_6 <= V_169 ) {
V_169 -= V_81 -> V_6 ;
V_81 = V_81 -> V_101 ;
V_172 = V_81 ;
} else {
if ( F_122 ( V_81 ) ) {
V_171 = F_105 ( V_81 , V_50 ) ;
if ( ! V_171 )
return NULL ;
V_172 = V_81 -> V_101 ;
V_81 = V_171 ;
} else {
V_172 = V_81 ;
}
if ( ! F_144 ( V_81 , V_169 ) ) {
F_76 ( V_171 ) ;
return NULL ;
}
break;
}
} while ( V_169 );
while ( ( V_81 = F_23 ( V_2 ) -> V_80 ) != V_172 ) {
F_23 ( V_2 ) -> V_80 = V_81 -> V_101 ;
F_76 ( V_81 ) ;
}
if ( V_171 ) {
V_171 -> V_101 = V_81 ;
F_23 ( V_2 ) -> V_80 = V_171 ;
}
}
V_170:
V_169 = V_153 ;
V_168 = 0 ;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_14 = F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( V_14 <= V_169 ) {
F_58 ( V_2 , V_75 ) ;
V_169 -= V_14 ;
} else {
F_23 ( V_2 ) -> V_78 [ V_168 ] = F_23 ( V_2 ) -> V_78 [ V_75 ] ;
if ( V_169 ) {
F_23 ( V_2 ) -> V_78 [ V_168 ] . V_141 += V_169 ;
F_145 ( & F_23 ( V_2 ) -> V_78 [ V_168 ] , V_169 ) ;
V_169 = 0 ;
}
V_168 ++ ;
}
}
F_23 ( V_2 ) -> V_85 = V_168 ;
V_2 -> V_9 += V_153 ;
V_2 -> V_77 -= V_153 ;
return F_123 ( V_2 ) ;
}
int F_115 ( const struct V_1 * V_2 , int V_67 , void * V_173 , int V_6 )
{
int V_174 = F_117 ( V_2 ) ;
struct V_1 * V_175 ;
int V_75 , V_176 ;
if ( V_67 > ( int ) V_2 -> V_6 - V_6 )
goto V_177;
if ( ( V_176 = V_174 - V_67 ) > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
F_146 ( V_2 , V_67 , V_173 , V_176 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return 0 ;
V_67 += V_176 ;
V_173 += V_176 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_10 ;
T_5 * V_139 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + F_101 ( V_139 ) ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
T_3 * V_138 ;
if ( V_176 > V_6 )
V_176 = V_6 ;
V_138 = F_99 ( F_100 ( V_139 ) ) ;
memcpy ( V_173 ,
V_138 + V_139 -> V_141 + V_67 - V_174 ,
V_176 ) ;
F_102 ( V_138 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return 0 ;
V_67 += V_176 ;
V_173 += V_176 ;
}
V_174 = V_10 ;
}
F_52 (skb, frag_iter) {
int V_10 ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + V_175 -> V_6 ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
if ( F_115 ( V_175 , V_67 - V_174 , V_173 , V_176 ) )
goto V_177;
if ( ( V_6 -= V_176 ) == 0 )
return 0 ;
V_67 += V_176 ;
V_173 += V_176 ;
}
V_174 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_177:
return - V_178 ;
}
static void F_147 ( struct V_179 * V_180 , unsigned int V_75 )
{
F_41 ( V_180 -> V_181 [ V_75 ] ) ;
}
static struct V_57 * F_148 ( struct V_57 * V_57 , unsigned int * V_6 ,
unsigned int * V_67 ,
struct V_182 * V_132 )
{
struct V_183 * V_184 = F_149 ( V_132 ) ;
if ( ! F_150 ( V_132 , V_184 ) )
return NULL ;
* V_6 = F_151 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_37 ( V_184 -> V_57 ) + V_184 -> V_67 ,
F_37 ( V_57 ) + * V_67 , * V_6 ) ;
* V_67 = V_184 -> V_67 ;
V_184 -> V_67 += * V_6 ;
return V_184 -> V_57 ;
}
static bool F_152 ( const struct V_179 * V_180 ,
struct V_57 * V_57 ,
unsigned int V_67 )
{
return V_180 -> V_185 &&
V_180 -> V_181 [ V_180 -> V_185 - 1 ] == V_57 &&
( V_180 -> V_186 [ V_180 -> V_185 - 1 ] . V_67 +
V_180 -> V_186 [ V_180 -> V_185 - 1 ] . V_6 == V_67 ) ;
}
static bool F_153 ( struct V_179 * V_180 ,
struct V_187 * V_188 , struct V_57 * V_57 ,
unsigned int * V_6 , unsigned int V_67 ,
bool V_189 ,
struct V_182 * V_132 )
{
if ( F_32 ( V_180 -> V_185 == V_190 ) )
return true ;
if ( V_189 ) {
V_57 = F_148 ( V_57 , V_6 , & V_67 , V_132 ) ;
if ( ! V_57 )
return true ;
}
if ( F_152 ( V_180 , V_57 , V_67 ) ) {
V_180 -> V_186 [ V_180 -> V_185 - 1 ] . V_6 += * V_6 ;
return false ;
}
F_154 ( V_57 ) ;
V_180 -> V_181 [ V_180 -> V_185 ] = V_57 ;
V_180 -> V_186 [ V_180 -> V_185 ] . V_6 = * V_6 ;
V_180 -> V_186 [ V_180 -> V_185 ] . V_67 = V_67 ;
V_180 -> V_185 ++ ;
return false ;
}
static bool F_155 ( struct V_57 * V_57 , unsigned int V_191 ,
unsigned int V_192 , unsigned int * V_76 ,
unsigned int * V_6 ,
struct V_179 * V_180 , bool V_189 ,
struct V_182 * V_132 ,
struct V_187 * V_188 )
{
if ( ! * V_6 )
return true ;
if ( * V_76 >= V_192 ) {
* V_76 -= V_192 ;
return false ;
}
V_191 += * V_76 ;
V_192 -= * V_76 ;
* V_76 = 0 ;
do {
unsigned int V_193 = F_156 ( * V_6 , V_192 ) ;
if ( F_153 ( V_180 , V_188 , V_57 , & V_193 , V_191 ,
V_189 , V_132 ) )
return true ;
V_191 += V_193 ;
V_192 -= V_193 ;
* V_6 -= V_193 ;
} while ( * V_6 && V_192 );
return false ;
}
static bool F_157 ( struct V_1 * V_2 , struct V_187 * V_188 ,
unsigned int * V_67 , unsigned int * V_6 ,
struct V_179 * V_180 , struct V_182 * V_132 )
{
int V_194 ;
if ( F_155 ( F_158 ( V_2 -> V_8 ) ,
( unsigned long ) V_2 -> V_8 & ( V_62 - 1 ) ,
F_117 ( V_2 ) ,
V_67 , V_6 , V_180 ,
F_159 ( V_2 ) ,
V_132 , V_188 ) )
return true ;
for ( V_194 = 0 ; V_194 < F_23 ( V_2 ) -> V_85 ; V_194 ++ ) {
const T_5 * V_139 = & F_23 ( V_2 ) -> V_78 [ V_194 ] ;
if ( F_155 ( F_100 ( V_139 ) ,
V_139 -> V_141 , F_101 ( V_139 ) ,
V_67 , V_6 , V_180 , false , V_132 , V_188 ) )
return true ;
}
return false ;
}
int F_160 ( struct V_1 * V_2 , unsigned int V_67 ,
struct V_187 * V_188 , unsigned int V_195 ,
unsigned int V_15 )
{
struct V_196 V_186 [ V_190 ] ;
struct V_57 * V_181 [ V_190 ] ;
struct V_179 V_180 = {
. V_181 = V_181 ,
. V_186 = V_186 ,
. V_197 = V_190 ,
. V_15 = V_15 ,
. V_198 = & V_199 ,
. V_200 = F_147 ,
} ;
struct V_1 * V_175 ;
struct V_182 * V_132 = V_2 -> V_132 ;
int V_201 = 0 ;
if ( F_157 ( V_2 , V_188 , & V_67 , & V_195 , & V_180 , V_132 ) )
goto V_166;
else if ( ! V_195 )
goto V_166;
F_52 (skb, frag_iter) {
if ( ! V_195 )
break;
if ( F_157 ( V_175 , V_188 , & V_67 , & V_195 , & V_180 , V_132 ) )
break;
}
V_166:
if ( V_180 . V_185 ) {
F_161 ( V_132 ) ;
V_201 = F_162 ( V_188 , & V_180 ) ;
F_163 ( V_132 ) ;
}
return V_201 ;
}
int F_164 ( struct V_1 * V_2 , int V_67 , const void * V_202 , int V_6 )
{
int V_174 = F_117 ( V_2 ) ;
struct V_1 * V_175 ;
int V_75 , V_176 ;
if ( V_67 > ( int ) V_2 -> V_6 - V_6 )
goto V_177;
if ( ( V_176 = V_174 - V_67 ) > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
F_165 ( V_2 , V_67 , V_202 , V_176 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return 0 ;
V_67 += V_176 ;
V_202 += V_176 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
int V_10 ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + F_101 ( V_56 ) ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
T_3 * V_138 ;
if ( V_176 > V_6 )
V_176 = V_6 ;
V_138 = F_99 ( F_100 ( V_56 ) ) ;
memcpy ( V_138 + V_56 -> V_141 + V_67 - V_174 ,
V_202 , V_176 ) ;
F_102 ( V_138 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return 0 ;
V_67 += V_176 ;
V_202 += V_176 ;
}
V_174 = V_10 ;
}
F_52 (skb, frag_iter) {
int V_10 ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + V_175 -> V_6 ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
if ( F_164 ( V_175 , V_67 - V_174 ,
V_202 , V_176 ) )
goto V_177;
if ( ( V_6 -= V_176 ) == 0 )
return 0 ;
V_67 += V_176 ;
V_202 += V_176 ;
}
V_174 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_177:
return - V_178 ;
}
T_7 F_166 ( const struct V_1 * V_2 , int V_67 , int V_6 ,
T_7 V_117 , const struct V_203 * V_198 )
{
int V_174 = F_117 ( V_2 ) ;
int V_75 , V_176 = V_174 - V_67 ;
struct V_1 * V_175 ;
int V_204 = 0 ;
if ( V_176 > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
V_117 = V_198 -> V_205 ( V_2 -> V_8 + V_67 , V_176 , V_117 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return V_117 ;
V_67 += V_176 ;
V_204 = V_176 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_10 ;
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + F_101 ( V_56 ) ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
T_7 V_206 ;
T_3 * V_138 ;
if ( V_176 > V_6 )
V_176 = V_6 ;
V_138 = F_99 ( F_100 ( V_56 ) ) ;
V_206 = V_198 -> V_205 ( V_138 + V_56 -> V_141 +
V_67 - V_174 , V_176 , 0 ) ;
F_102 ( V_138 ) ;
V_117 = V_198 -> V_207 ( V_117 , V_206 , V_204 , V_176 ) ;
if ( ! ( V_6 -= V_176 ) )
return V_117 ;
V_67 += V_176 ;
V_204 += V_176 ;
}
V_174 = V_10 ;
}
F_52 (skb, frag_iter) {
int V_10 ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + V_175 -> V_6 ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
T_7 V_206 ;
if ( V_176 > V_6 )
V_176 = V_6 ;
V_206 = F_166 ( V_175 , V_67 - V_174 ,
V_176 , 0 , V_198 ) ;
V_117 = V_198 -> V_207 ( V_117 , V_206 , V_204 , V_176 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return V_117 ;
V_67 += V_176 ;
V_204 += V_176 ;
}
V_174 = V_10 ;
}
F_121 ( V_6 ) ;
return V_117 ;
}
T_7 F_167 ( const struct V_1 * V_2 , int V_67 ,
int V_6 , T_7 V_117 )
{
const struct V_203 V_198 = {
. V_205 = V_208 ,
. V_207 = V_209 ,
} ;
return F_166 ( V_2 , V_67 , V_6 , V_117 , & V_198 ) ;
}
T_7 F_168 ( const struct V_1 * V_2 , int V_67 ,
T_3 * V_173 , int V_6 , T_7 V_117 )
{
int V_174 = F_117 ( V_2 ) ;
int V_75 , V_176 = V_174 - V_67 ;
struct V_1 * V_175 ;
int V_204 = 0 ;
if ( V_176 > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
V_117 = F_169 ( V_2 -> V_8 + V_67 , V_173 ,
V_176 , V_117 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return V_117 ;
V_67 += V_176 ;
V_173 += V_176 ;
V_204 = V_176 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_10 ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
T_7 V_206 ;
T_3 * V_138 ;
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
if ( V_176 > V_6 )
V_176 = V_6 ;
V_138 = F_99 ( F_100 ( V_56 ) ) ;
V_206 = F_169 ( V_138 +
V_56 -> V_141 +
V_67 - V_174 , V_173 ,
V_176 , 0 ) ;
F_102 ( V_138 ) ;
V_117 = F_170 ( V_117 , V_206 , V_204 ) ;
if ( ! ( V_6 -= V_176 ) )
return V_117 ;
V_67 += V_176 ;
V_173 += V_176 ;
V_204 += V_176 ;
}
V_174 = V_10 ;
}
F_52 (skb, frag_iter) {
T_7 V_206 ;
int V_10 ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + V_175 -> V_6 ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
V_206 = F_168 ( V_175 ,
V_67 - V_174 ,
V_173 , V_176 , 0 ) ;
V_117 = F_170 ( V_117 , V_206 , V_204 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return V_117 ;
V_67 += V_176 ;
V_173 += V_176 ;
V_204 += V_176 ;
}
V_174 = V_10 ;
}
F_121 ( V_6 ) ;
return V_117 ;
}
unsigned int
F_171 ( const struct V_1 * V_202 )
{
unsigned int V_210 = 0 ;
if ( ! V_202 -> V_51 ||
F_117 ( V_202 ) < V_211 ||
F_23 ( V_202 ) -> V_85 >= V_190 )
V_210 = F_117 ( V_202 ) ;
if ( F_59 ( V_202 ) )
V_210 = V_202 -> V_6 ;
return V_210 ;
}
int
F_172 ( struct V_1 * V_173 , struct V_1 * V_202 , int V_6 , int V_210 )
{
int V_75 , V_212 = 0 ;
int V_192 = 0 ;
int V_201 ;
struct V_57 * V_57 ;
unsigned int V_67 ;
F_121 ( ! V_202 -> V_51 && ! V_210 ) ;
if ( V_6 <= F_130 ( V_173 ) )
return F_115 ( V_202 , 0 , F_114 ( V_173 , V_6 ) , V_6 ) ;
if ( V_210 ) {
V_201 = F_115 ( V_202 , 0 , F_114 ( V_173 , V_210 ) , V_210 ) ;
if ( F_32 ( V_201 ) )
return V_201 ;
V_6 -= V_210 ;
} else {
V_192 = F_151 ( int , F_117 ( V_202 ) , V_6 ) ;
if ( V_192 ) {
V_57 = F_42 ( V_202 -> V_7 ) ;
V_67 = V_202 -> V_8 - ( unsigned char * ) F_37 ( V_57 ) ;
F_104 ( V_173 , 0 , V_57 , V_67 , V_192 ) ;
F_154 ( V_57 ) ;
V_212 = 1 ;
V_6 -= V_192 ;
}
}
V_173 -> V_27 += V_6 + V_192 ;
V_173 -> V_6 += V_6 + V_192 ;
V_173 -> V_77 += V_6 + V_192 ;
if ( F_32 ( F_106 ( V_202 , V_50 ) ) ) {
F_80 ( V_202 ) ;
return - V_140 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_202 ) -> V_85 ; V_75 ++ ) {
if ( ! V_6 )
break;
F_23 ( V_173 ) -> V_78 [ V_212 ] = F_23 ( V_202 ) -> V_78 [ V_75 ] ;
F_23 ( V_173 ) -> V_78 [ V_212 ] . V_14 = F_151 ( int , F_23 ( V_173 ) -> V_78 [ V_212 ] . V_14 , V_6 ) ;
V_6 -= F_23 ( V_173 ) -> V_78 [ V_212 ] . V_14 ;
F_119 ( V_173 , V_212 ) ;
V_212 ++ ;
}
F_23 ( V_173 ) -> V_85 = V_212 ;
return 0 ;
}
void F_173 ( const struct V_1 * V_2 , T_3 * V_173 )
{
T_7 V_117 ;
long V_213 ;
if ( V_2 -> V_120 == V_142 )
V_213 = F_174 ( V_2 ) ;
else
V_213 = F_117 ( V_2 ) ;
F_121 ( V_213 > F_117 ( V_2 ) ) ;
F_118 ( V_2 , V_173 , V_213 ) ;
V_117 = 0 ;
if ( V_213 != V_2 -> V_6 )
V_117 = F_168 ( V_2 , V_213 , V_173 + V_213 ,
V_2 -> V_6 - V_213 , 0 ) ;
if ( V_2 -> V_120 == V_142 ) {
long V_214 = V_213 + V_2 -> V_215 ;
* ( ( V_216 * ) ( V_173 + V_214 ) ) = F_175 ( V_117 ) ;
}
}
struct V_1 * F_176 ( struct V_217 * V_81 )
{
unsigned long V_15 ;
struct V_1 * V_218 ;
F_177 ( & V_81 -> V_219 , V_15 ) ;
V_218 = F_178 ( V_81 ) ;
F_179 ( & V_81 -> V_219 , V_15 ) ;
return V_218 ;
}
struct V_1 * F_180 ( struct V_217 * V_81 )
{
unsigned long V_15 ;
struct V_1 * V_218 ;
F_177 ( & V_81 -> V_219 , V_15 ) ;
V_218 = F_181 ( V_81 ) ;
F_179 ( & V_81 -> V_219 , V_15 ) ;
return V_218 ;
}
void F_182 ( struct V_217 * V_81 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_176 ( V_81 ) ) != NULL )
F_76 ( V_2 ) ;
}
void F_183 ( struct V_217 * V_81 , struct V_1 * V_220 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_219 , V_15 ) ;
F_184 ( V_81 , V_220 ) ;
F_179 ( & V_81 -> V_219 , V_15 ) ;
}
void F_185 ( struct V_217 * V_81 , struct V_1 * V_220 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_219 , V_15 ) ;
F_186 ( V_81 , V_220 ) ;
F_179 ( & V_81 -> V_219 , V_15 ) ;
}
void F_187 ( struct V_1 * V_2 , struct V_217 * V_81 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_219 , V_15 ) ;
F_188 ( V_2 , V_81 ) ;
F_179 ( & V_81 -> V_219 , V_15 ) ;
}
void F_189 ( struct V_1 * V_103 , struct V_1 * V_220 , struct V_217 * V_81 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_219 , V_15 ) ;
F_190 ( V_81 , V_103 , V_220 ) ;
F_179 ( & V_81 -> V_219 , V_15 ) ;
}
void F_191 ( struct V_1 * V_103 , struct V_1 * V_220 , struct V_217 * V_81 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_219 , V_15 ) ;
F_192 ( V_220 , V_103 -> V_131 , V_103 , V_81 ) ;
F_179 ( & V_81 -> V_219 , V_15 ) ;
}
static inline void F_193 ( struct V_1 * V_2 ,
struct V_1 * V_221 ,
const T_8 V_6 , const int V_204 )
{
int V_75 ;
F_146 ( V_2 , V_6 , F_114 ( V_221 , V_204 - V_6 ) ,
V_204 - V_6 ) ;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ )
F_23 ( V_221 ) -> V_78 [ V_75 ] = F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_23 ( V_221 ) -> V_85 = F_23 ( V_2 ) -> V_85 ;
F_23 ( V_2 ) -> V_85 = 0 ;
V_221 -> V_77 = V_2 -> V_77 ;
V_221 -> V_6 += V_221 -> V_77 ;
V_2 -> V_77 = 0 ;
V_2 -> V_6 = V_6 ;
F_142 ( V_2 , V_6 ) ;
}
static inline void F_194 ( struct V_1 * V_2 ,
struct V_1 * V_221 ,
const T_8 V_6 , int V_204 )
{
int V_75 , V_168 = 0 ;
const int V_164 = F_23 ( V_2 ) -> V_85 ;
F_23 ( V_2 ) -> V_85 = 0 ;
V_221 -> V_6 = V_221 -> V_77 = V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_77 = V_6 - V_204 ;
for ( V_75 = 0 ; V_75 < V_164 ; V_75 ++ ) {
int V_14 = F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( V_204 + V_14 > V_6 ) {
F_23 ( V_221 ) -> V_78 [ V_168 ] = F_23 ( V_2 ) -> V_78 [ V_75 ] ;
if ( V_204 < V_6 ) {
F_119 ( V_2 , V_75 ) ;
F_23 ( V_221 ) -> V_78 [ 0 ] . V_141 += V_6 - V_204 ;
F_145 ( & F_23 ( V_221 ) -> V_78 [ 0 ] , V_6 - V_204 ) ;
F_140 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] , V_6 - V_204 ) ;
F_23 ( V_2 ) -> V_85 ++ ;
}
V_168 ++ ;
} else
F_23 ( V_2 ) -> V_85 ++ ;
V_204 += V_14 ;
}
F_23 ( V_221 ) -> V_85 = V_168 ;
}
void F_195 ( struct V_1 * V_2 , struct V_1 * V_221 , const T_8 V_6 )
{
int V_204 = F_117 ( V_2 ) ;
F_23 ( V_221 ) -> V_86 = F_23 ( V_2 ) -> V_86 & V_222 ;
if ( V_6 < V_204 )
F_193 ( V_2 , V_221 , V_6 , V_204 ) ;
else
F_194 ( V_2 , V_221 , V_6 , V_204 ) ;
}
static int F_196 ( struct V_1 * V_2 )
{
return F_124 ( V_2 ) && F_120 ( V_2 , 0 , 0 , V_50 ) ;
}
int F_197 ( struct V_1 * V_223 , struct V_1 * V_2 , int V_224 )
{
int V_202 , V_173 , V_225 , V_226 ;
struct V_227 * V_228 , * V_229 ;
F_121 ( V_224 > V_2 -> V_6 ) ;
F_121 ( F_117 ( V_2 ) ) ;
V_226 = V_224 ;
V_202 = 0 ;
V_173 = F_23 ( V_223 ) -> V_85 ;
V_228 = & F_23 ( V_2 ) -> V_78 [ V_202 ] ;
if ( ! V_173 ||
! F_198 ( V_223 , V_173 , F_100 ( V_228 ) ,
V_228 -> V_141 ) ) {
V_225 = - 1 ;
} else {
V_225 = V_173 - 1 ;
V_226 -= F_101 ( V_228 ) ;
if ( V_226 < 0 ) {
if ( F_196 ( V_2 ) ||
F_196 ( V_223 ) )
return 0 ;
V_228 = & F_23 ( V_2 ) -> V_78 [ V_202 ] ;
V_229 = & F_23 ( V_223 ) -> V_78 [ V_225 ] ;
F_47 ( V_229 , V_224 ) ;
F_145 ( V_228 , V_224 ) ;
V_228 -> V_141 += V_224 ;
goto V_230;
}
V_202 ++ ;
}
if ( ( V_224 == V_2 -> V_6 ) &&
( F_23 ( V_2 ) -> V_85 - V_202 ) > ( V_190 - V_173 ) )
return 0 ;
if ( F_196 ( V_2 ) || F_196 ( V_223 ) )
return 0 ;
while ( ( V_226 > 0 ) && ( V_202 < F_23 ( V_2 ) -> V_85 ) ) {
if ( V_173 == V_190 )
return 0 ;
V_228 = & F_23 ( V_2 ) -> V_78 [ V_202 ] ;
V_229 = & F_23 ( V_223 ) -> V_78 [ V_173 ] ;
if ( V_226 >= F_101 ( V_228 ) ) {
* V_229 = * V_228 ;
V_226 -= F_101 ( V_228 ) ;
V_202 ++ ;
V_173 ++ ;
} else {
F_199 ( V_228 ) ;
V_229 -> V_57 = V_228 -> V_57 ;
V_229 -> V_141 = V_228 -> V_141 ;
F_140 ( V_229 , V_226 ) ;
V_228 -> V_141 += V_226 ;
F_145 ( V_228 , V_226 ) ;
V_226 = 0 ;
V_173 ++ ;
break;
}
}
F_23 ( V_223 ) -> V_85 = V_173 ;
if ( V_225 >= 0 ) {
V_228 = & F_23 ( V_2 ) -> V_78 [ 0 ] ;
V_229 = & F_23 ( V_223 ) -> V_78 [ V_225 ] ;
F_47 ( V_229 , F_101 ( V_228 ) ) ;
F_200 ( V_228 ) ;
}
V_173 = 0 ;
while ( V_202 < F_23 ( V_2 ) -> V_85 )
F_23 ( V_2 ) -> V_78 [ V_173 ++ ] = F_23 ( V_2 ) -> V_78 [ V_202 ++ ] ;
F_23 ( V_2 ) -> V_85 = V_173 ;
F_121 ( V_226 > 0 && ! F_23 ( V_2 ) -> V_85 ) ;
V_230:
V_223 -> V_120 = V_142 ;
V_2 -> V_120 = V_142 ;
V_2 -> V_6 -= V_224 ;
V_2 -> V_77 -= V_224 ;
V_2 -> V_27 -= V_224 ;
V_223 -> V_6 += V_224 ;
V_223 -> V_77 += V_224 ;
V_223 -> V_27 += V_224 ;
return V_224 ;
}
void F_201 ( struct V_1 * V_2 , unsigned int V_202 ,
unsigned int V_173 , struct V_231 * V_232 )
{
V_232 -> V_233 = V_202 ;
V_232 -> V_234 = V_173 ;
V_232 -> V_235 = V_232 -> V_236 = V_2 ;
V_232 -> V_237 = V_232 -> V_238 = 0 ;
V_232 -> V_239 = NULL ;
}
unsigned int F_202 ( unsigned int V_240 , const T_3 * * V_8 ,
struct V_231 * V_232 )
{
unsigned int V_241 , V_242 = V_240 + V_232 -> V_233 ;
T_5 * V_56 ;
if ( F_32 ( V_242 >= V_232 -> V_234 ) ) {
if ( V_232 -> V_239 ) {
F_102 ( V_232 -> V_239 ) ;
V_232 -> V_239 = NULL ;
}
return 0 ;
}
V_243:
V_241 = F_117 ( V_232 -> V_236 ) + V_232 -> V_238 ;
if ( V_242 < V_241 && ! V_232 -> V_239 ) {
* V_8 = V_232 -> V_236 -> V_8 + ( V_242 - V_232 -> V_238 ) ;
return V_241 - V_242 ;
}
if ( V_232 -> V_237 == 0 && ! V_232 -> V_239 )
V_232 -> V_238 += F_117 ( V_232 -> V_236 ) ;
while ( V_232 -> V_237 < F_23 ( V_232 -> V_236 ) -> V_85 ) {
V_56 = & F_23 ( V_232 -> V_236 ) -> V_78 [ V_232 -> V_237 ] ;
V_241 = F_101 ( V_56 ) + V_232 -> V_238 ;
if ( V_242 < V_241 ) {
if ( ! V_232 -> V_239 )
V_232 -> V_239 = F_99 ( F_100 ( V_56 ) ) ;
* V_8 = ( T_3 * ) V_232 -> V_239 + V_56 -> V_141 +
( V_242 - V_232 -> V_238 ) ;
return V_241 - V_242 ;
}
if ( V_232 -> V_239 ) {
F_102 ( V_232 -> V_239 ) ;
V_232 -> V_239 = NULL ;
}
V_232 -> V_237 ++ ;
V_232 -> V_238 += F_101 ( V_56 ) ;
}
if ( V_232 -> V_239 ) {
F_102 ( V_232 -> V_239 ) ;
V_232 -> V_239 = NULL ;
}
if ( V_232 -> V_235 == V_232 -> V_236 && F_59 ( V_232 -> V_235 ) ) {
V_232 -> V_236 = F_23 ( V_232 -> V_235 ) -> V_80 ;
V_232 -> V_237 = 0 ;
goto V_243;
} else if ( V_232 -> V_236 -> V_101 ) {
V_232 -> V_236 = V_232 -> V_236 -> V_101 ;
V_232 -> V_237 = 0 ;
goto V_243;
}
return 0 ;
}
void F_203 ( struct V_231 * V_232 )
{
if ( V_232 -> V_239 )
F_102 ( V_232 -> V_239 ) ;
}
static unsigned int F_204 ( unsigned int V_67 , const T_3 * * V_244 ,
struct V_245 * V_246 ,
struct V_247 * V_248 )
{
return F_202 ( V_67 , V_244 , F_205 ( V_248 ) ) ;
}
static void F_206 ( struct V_245 * V_246 , struct V_247 * V_248 )
{
F_203 ( F_205 ( V_248 ) ) ;
}
unsigned int F_207 ( struct V_1 * V_2 , unsigned int V_202 ,
unsigned int V_173 , struct V_245 * V_249 ,
struct V_247 * V_248 )
{
unsigned int V_201 ;
V_249 -> V_250 = F_204 ;
V_249 -> V_251 = F_206 ;
F_201 ( V_2 , V_202 , V_173 , F_205 ( V_248 ) ) ;
V_201 = F_208 ( V_249 , V_248 ) ;
return ( V_201 <= V_173 - V_202 ? V_201 : V_252 ) ;
}
int F_209 ( struct V_182 * V_132 , struct V_1 * V_2 ,
int (* F_210)( void * V_202 , char * V_173 , int V_67 ,
int V_6 , int V_253 , struct V_1 * V_2 ) ,
void * V_202 , int V_70 )
{
int V_254 = F_23 ( V_2 ) -> V_85 ;
int V_176 ;
int V_67 = 0 ;
int V_201 ;
struct V_183 * V_184 = & V_255 -> V_256 ;
do {
if ( V_254 >= V_190 )
return - V_257 ;
if ( ! F_150 ( V_132 , V_184 ) )
return - V_140 ;
V_176 = F_151 ( int , V_70 , V_184 -> V_14 - V_184 -> V_67 ) ;
V_201 = F_210 ( V_202 , F_37 ( V_184 -> V_57 ) + V_184 -> V_67 ,
V_67 , V_176 , 0 , V_2 ) ;
if ( V_201 < 0 )
return - V_178 ;
F_45 ( V_2 , V_254 , V_184 -> V_57 , V_184 -> V_67 ,
V_176 ) ;
V_254 ++ ;
V_184 -> V_67 += V_176 ;
F_154 ( V_184 -> V_57 ) ;
V_2 -> V_27 += V_176 ;
F_211 ( V_176 , & V_132 -> V_258 ) ;
V_2 -> V_6 += V_176 ;
V_2 -> V_77 += V_176 ;
V_67 += V_176 ;
V_70 -= V_176 ;
} while ( V_70 > 0 );
return 0 ;
}
unsigned char * F_212 ( struct V_1 * V_2 , unsigned int V_6 )
{
F_121 ( V_6 > V_2 -> V_6 ) ;
V_2 -> V_6 -= V_6 ;
F_121 ( V_2 -> V_6 < V_2 -> V_77 ) ;
F_213 ( V_2 , V_2 -> V_8 , V_6 ) ;
return V_2 -> V_8 += V_6 ;
}
struct V_1 * F_214 ( struct V_1 * V_259 ,
T_9 V_260 )
{
struct V_1 * V_100 = NULL ;
struct V_1 * V_9 = NULL ;
struct V_1 * V_261 = F_23 ( V_259 ) -> V_80 ;
T_5 * V_56 = F_23 ( V_259 ) -> V_78 ;
unsigned int V_262 = F_23 ( V_259 ) -> V_144 ;
unsigned int V_263 = V_259 -> V_8 - F_215 ( V_259 ) ;
struct V_1 * V_264 = V_259 ;
unsigned int V_67 = V_263 ;
unsigned int V_265 = F_216 ( V_259 ) ;
unsigned int V_148 ;
unsigned int V_6 ;
T_10 V_266 ;
bool V_117 ;
int V_267 = ! ! ( V_260 & V_268 ) ;
int V_164 = F_23 ( V_259 ) -> V_85 ;
int V_160 = - V_140 ;
int V_75 = 0 ;
int V_204 ;
int V_269 ;
F_217 ( V_259 , V_263 ) ;
V_266 = F_218 ( V_259 , & V_269 ) ;
if ( F_32 ( ! V_266 ) )
return F_219 ( - V_270 ) ;
V_117 = ! V_259 -> V_113 &&
! ! F_220 ( V_260 , V_266 ) ;
V_148 = F_93 ( V_259 ) ;
V_204 = F_117 ( V_259 ) ;
do {
struct V_1 * V_271 ;
T_5 * V_272 ;
int V_273 ;
int V_14 ;
V_6 = V_259 -> V_6 - V_67 ;
if ( V_6 > V_262 )
V_6 = V_262 ;
V_273 = F_117 ( V_259 ) - V_67 ;
if ( V_273 < 0 )
V_273 = 0 ;
if ( V_273 > V_6 || ! V_267 )
V_273 = V_6 ;
if ( ! V_273 && V_75 >= V_164 && F_117 ( V_261 ) &&
( F_117 ( V_261 ) == V_6 || V_267 ) ) {
F_121 ( F_117 ( V_261 ) > V_6 ) ;
V_75 = 0 ;
V_164 = F_23 ( V_261 ) -> V_85 ;
V_56 = F_23 ( V_261 ) -> V_78 ;
V_264 = V_261 ;
V_204 += F_117 ( V_261 ) ;
while ( V_204 < V_67 + V_6 ) {
F_121 ( V_75 >= V_164 ) ;
V_14 = F_101 ( V_56 ) ;
if ( V_204 + V_14 > V_67 + V_6 )
break;
V_75 ++ ;
V_204 += V_14 ;
V_56 ++ ;
}
V_271 = F_105 ( V_261 , V_50 ) ;
V_261 = V_261 -> V_101 ;
if ( F_32 ( ! V_271 ) )
goto V_160;
if ( F_32 ( F_141 ( V_271 , V_6 ) ) ) {
F_76 ( V_271 ) ;
goto V_160;
}
V_273 = F_113 ( V_271 ) ;
if ( F_221 ( V_271 , V_263 + V_148 ) ) {
F_76 ( V_271 ) ;
goto V_160;
}
V_271 -> V_27 += F_113 ( V_271 ) - V_273 ;
F_62 ( V_271 ) ;
F_217 ( V_271 , V_263 ) ;
} else {
V_271 = F_14 ( V_273 + V_263 + V_148 ,
V_50 , F_111 ( V_259 ) ,
V_74 ) ;
if ( F_32 ( ! V_271 ) )
goto V_160;
F_43 ( V_271 , V_148 ) ;
F_222 ( V_271 , V_263 ) ;
}
if ( V_100 )
V_9 -> V_101 = V_271 ;
else
V_100 = V_271 ;
V_9 = V_271 ;
F_83 ( V_271 , V_259 ) ;
V_271 -> V_133 = V_259 -> V_133 ;
F_108 ( V_271 , F_93 ( V_271 ) - V_148 ) ;
F_146 ( V_259 , - V_265 ,
V_271 -> V_8 - V_265 ,
V_263 + V_265 ) ;
if ( V_271 -> V_6 == V_6 + V_263 )
goto V_274;
if ( ! V_267 ) {
V_271 -> V_120 = V_275 ;
V_271 -> V_117 = F_168 ( V_259 , V_67 ,
F_114 ( V_271 , V_6 ) ,
V_6 , 0 ) ;
F_223 ( V_271 ) -> V_143 =
F_93 ( V_271 ) + V_263 ;
continue;
}
V_272 = F_23 ( V_271 ) -> V_78 ;
F_146 ( V_259 , V_67 ,
F_114 ( V_271 , V_273 ) , V_273 ) ;
F_23 ( V_271 ) -> V_86 = F_23 ( V_259 ) -> V_86 &
V_222 ;
while ( V_204 < V_67 + V_6 ) {
if ( V_75 >= V_164 ) {
F_121 ( F_117 ( V_261 ) ) ;
V_75 = 0 ;
V_164 = F_23 ( V_261 ) -> V_85 ;
V_56 = F_23 ( V_261 ) -> V_78 ;
V_264 = V_261 ;
F_121 ( ! V_164 ) ;
V_261 = V_261 -> V_101 ;
}
if ( F_32 ( F_23 ( V_271 ) -> V_85 >=
V_190 ) ) {
F_224 (
L_3 ,
V_204 , V_262 ) ;
goto V_160;
}
if ( F_32 ( F_106 ( V_264 , V_50 ) ) )
goto V_160;
* V_272 = * V_56 ;
F_199 ( V_272 ) ;
V_14 = F_101 ( V_272 ) ;
if ( V_204 < V_67 ) {
V_272 -> V_141 += V_67 - V_204 ;
F_145 ( V_272 , V_67 - V_204 ) ;
}
F_23 ( V_271 ) -> V_85 ++ ;
if ( V_204 + V_14 <= V_67 + V_6 ) {
V_75 ++ ;
V_56 ++ ;
V_204 += V_14 ;
} else {
F_145 ( V_272 , V_204 + V_14 - ( V_67 + V_6 ) ) ;
goto V_276;
}
V_272 ++ ;
}
V_276:
V_271 -> V_77 = V_6 - V_273 ;
V_271 -> V_6 += V_271 -> V_77 ;
V_271 -> V_27 += V_271 -> V_77 ;
V_274:
if ( ! V_117 ) {
V_271 -> V_117 = F_167 ( V_271 , V_263 ,
V_271 -> V_6 - V_263 , 0 ) ;
V_271 -> V_120 = V_275 ;
F_223 ( V_271 ) -> V_143 =
F_93 ( V_271 ) + V_263 ;
}
} while ( ( V_67 += V_6 ) < V_259 -> V_6 );
return V_100 ;
V_160:
F_49 ( V_100 ) ;
return F_219 ( V_160 ) ;
}
int F_225 ( struct V_1 * * V_7 , struct V_1 * V_2 )
{
struct V_32 * V_277 , * V_278 = F_23 ( V_2 ) ;
unsigned int V_67 = F_226 ( V_2 ) ;
unsigned int V_279 = F_117 ( V_2 ) ;
struct V_1 * V_271 , * V_280 , * V_281 = * V_7 ;
unsigned int V_6 = F_227 ( V_2 ) ;
unsigned int V_282 ;
unsigned int V_148 ;
if ( F_32 ( V_281 -> V_6 + V_6 >= 65536 ) )
return - V_283 ;
V_280 = F_228 ( V_281 ) -> V_284 ;
V_277 = F_23 ( V_280 ) ;
if ( V_279 <= V_67 ) {
T_5 * V_56 ;
T_5 * V_285 ;
int V_75 = V_278 -> V_85 ;
int V_85 = V_277 -> V_85 + V_75 ;
if ( V_85 > V_190 )
goto V_225;
V_67 -= V_279 ;
V_277 -> V_85 = V_85 ;
V_278 -> V_85 = 0 ;
V_56 = V_277 -> V_78 + V_85 ;
V_285 = V_278 -> V_78 + V_75 ;
do {
* -- V_56 = * -- V_285 ;
} while ( -- V_75 );
V_56 -> V_141 += V_67 ;
F_145 ( V_56 , V_67 ) ;
V_282 = V_2 -> V_27 -
F_21 ( F_113 ( V_2 ) ) ;
V_2 -> V_27 -= V_2 -> V_77 ;
V_2 -> V_6 -= V_2 -> V_77 ;
V_2 -> V_77 = 0 ;
F_228 ( V_2 ) -> free = V_286 ;
goto V_166;
} else if ( V_2 -> V_51 ) {
int V_85 = V_277 -> V_85 ;
T_5 * V_56 = V_277 -> V_78 + V_85 ;
struct V_57 * V_57 = F_42 ( V_2 -> V_7 ) ;
unsigned int V_287 = V_279 - V_67 ;
unsigned int V_288 ;
if ( V_85 + 1 + V_278 -> V_85 > V_190 )
goto V_225;
V_288 = V_2 -> V_8 -
( unsigned char * ) F_37 ( V_57 ) +
V_67 ;
V_277 -> V_85 = V_85 + 1 + V_278 -> V_85 ;
V_56 -> V_57 . V_281 = V_57 ;
V_56 -> V_141 = V_288 ;
F_140 ( V_56 , V_287 ) ;
memcpy ( V_56 + 1 , V_278 -> V_78 , sizeof( * V_56 ) * V_278 -> V_85 ) ;
V_282 = V_2 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
F_228 ( V_2 ) -> free = V_289 ;
goto V_166;
}
if ( V_277 -> V_80 )
goto V_225;
if ( F_227 ( V_281 ) != V_277 -> V_144 )
return - V_283 ;
V_148 = F_93 ( V_281 ) ;
V_271 = F_229 ( V_148 + F_226 ( V_281 ) , V_50 ) ;
if ( F_32 ( ! V_271 ) )
return - V_140 ;
F_83 ( V_271 , V_281 ) ;
V_271 -> V_133 = V_281 -> V_133 ;
F_43 ( V_271 , V_148 ) ;
F_222 ( V_271 , F_226 ( V_281 ) ) ;
F_230 ( V_271 , F_215 ( V_281 ) - V_281 -> V_8 ) ;
F_231 ( V_271 , F_232 ( V_281 ) ) ;
F_233 ( V_271 , F_234 ( V_281 ) ) ;
F_235 ( V_281 , F_226 ( V_281 ) ) ;
memcpy ( F_215 ( V_271 ) , F_215 ( V_281 ) ,
V_281 -> V_8 - F_215 ( V_281 ) ) ;
F_23 ( V_271 ) -> V_80 = V_281 ;
F_23 ( V_271 ) -> V_144 = V_277 -> V_144 ;
V_277 -> V_144 = 0 ;
F_236 ( V_281 ) ;
F_228 ( V_271 ) -> V_284 = V_281 ;
V_271 -> V_77 += V_281 -> V_6 ;
V_271 -> V_27 += V_281 -> V_27 ;
V_271 -> V_6 += V_281 -> V_6 ;
* V_7 = V_271 ;
V_271 -> V_101 = V_281 -> V_101 ;
V_281 -> V_101 = NULL ;
V_281 = V_271 ;
V_225:
V_282 = V_2 -> V_27 ;
if ( V_67 > V_279 ) {
unsigned int V_169 = V_67 - V_279 ;
V_278 -> V_78 [ 0 ] . V_141 += V_169 ;
F_145 ( & V_278 -> V_78 [ 0 ] , V_169 ) ;
V_2 -> V_77 -= V_169 ;
V_2 -> V_6 -= V_169 ;
V_67 = V_279 ;
}
F_235 ( V_2 , V_67 ) ;
if ( F_228 ( V_281 ) -> V_284 == V_281 )
F_23 ( V_281 ) -> V_80 = V_2 ;
else
F_228 ( V_281 ) -> V_284 -> V_101 = V_2 ;
F_228 ( V_281 ) -> V_284 = V_2 ;
F_236 ( V_2 ) ;
V_280 = V_281 ;
V_166:
F_228 ( V_281 ) -> V_290 ++ ;
V_281 -> V_77 += V_6 ;
V_281 -> V_27 += V_282 ;
V_281 -> V_6 += V_6 ;
if ( V_280 != V_281 ) {
V_280 -> V_77 += V_6 ;
V_280 -> V_27 += V_282 ;
V_280 -> V_6 += V_6 ;
}
F_228 ( V_2 ) -> V_291 = 1 ;
return 0 ;
}
void T_11 F_237 ( void )
{
V_25 = F_238 ( L_4 ,
sizeof( struct V_1 ) ,
0 ,
V_292 | V_293 ,
NULL ) ;
V_35 = F_238 ( L_5 ,
( 2 * sizeof( struct V_1 ) ) +
sizeof( T_4 ) ,
0 ,
V_292 | V_293 ,
NULL ) ;
}
static int
F_239 ( struct V_1 * V_2 , struct V_294 * V_267 , int V_67 , int V_6 )
{
int V_174 = F_117 ( V_2 ) ;
int V_75 , V_176 = V_174 - V_67 ;
struct V_1 * V_175 ;
int V_295 = 0 ;
if ( V_176 > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
F_240 ( V_267 , V_2 -> V_8 + V_67 , V_176 ) ;
V_295 ++ ;
if ( ( V_6 -= V_176 ) == 0 )
return V_295 ;
V_67 += V_176 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_10 ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
if ( V_176 > V_6 )
V_176 = V_6 ;
F_241 ( & V_267 [ V_295 ] , F_100 ( V_56 ) , V_176 ,
V_56 -> V_141 + V_67 - V_174 ) ;
V_295 ++ ;
if ( ! ( V_6 -= V_176 ) )
return V_295 ;
V_67 += V_176 ;
}
V_174 = V_10 ;
}
F_52 (skb, frag_iter) {
int V_10 ;
F_66 ( V_174 > V_67 + V_6 ) ;
V_10 = V_174 + V_175 -> V_6 ;
if ( ( V_176 = V_10 - V_67 ) > 0 ) {
if ( V_176 > V_6 )
V_176 = V_6 ;
V_295 += F_239 ( V_175 , V_267 + V_295 , V_67 - V_174 ,
V_176 ) ;
if ( ( V_6 -= V_176 ) == 0 )
return V_295 ;
V_67 += V_176 ;
}
V_174 = V_10 ;
}
F_121 ( V_6 ) ;
return V_295 ;
}
int F_242 ( struct V_1 * V_2 , struct V_294 * V_267 ,
int V_67 , int V_6 )
{
return F_239 ( V_2 , V_267 , V_67 , V_6 ) ;
}
int F_243 ( struct V_1 * V_2 , struct V_294 * V_267 , int V_67 , int V_6 )
{
int V_296 = F_239 ( V_2 , V_267 , V_67 , V_6 ) ;
F_244 ( & V_267 [ V_296 - 1 ] ) ;
return V_296 ;
}
int F_245 ( struct V_1 * V_2 , int V_297 , struct V_1 * * V_298 )
{
int V_299 ;
int V_295 ;
struct V_1 * V_221 , * * V_300 ;
if ( ( F_124 ( V_2 ) || F_23 ( V_2 ) -> V_85 ) &&
F_143 ( V_2 , F_246 ( V_2 ) - F_117 ( V_2 ) ) == NULL )
return - V_140 ;
if ( ! F_59 ( V_2 ) ) {
if ( F_130 ( V_2 ) < V_297 &&
F_120 ( V_2 , 0 , V_297 - F_130 ( V_2 ) + 128 , V_50 ) )
return - V_140 ;
* V_298 = V_2 ;
return 1 ;
}
V_295 = 1 ;
V_300 = & F_23 ( V_2 ) -> V_80 ;
V_299 = 0 ;
while ( ( V_221 = * V_300 ) != NULL ) {
int V_150 = 0 ;
if ( F_122 ( V_221 ) )
V_299 = 1 ;
if ( V_221 -> V_101 == NULL && V_297 ) {
if ( F_23 ( V_221 ) -> V_85 ||
F_59 ( V_221 ) ||
F_130 ( V_221 ) < V_297 )
V_150 = V_297 + 128 ;
}
if ( V_299 ||
F_124 ( V_221 ) ||
V_150 ||
F_23 ( V_221 ) -> V_85 ||
F_59 ( V_221 ) ) {
struct V_1 * V_152 ;
if ( V_150 == 0 )
V_152 = F_112 ( V_221 , V_50 ) ;
else
V_152 = F_128 ( V_221 ,
F_93 ( V_221 ) ,
V_150 ,
V_50 ) ;
if ( F_32 ( V_152 == NULL ) )
return - V_140 ;
if ( V_221 -> V_132 )
F_247 ( V_152 , V_221 -> V_132 ) ;
V_152 -> V_101 = V_221 -> V_101 ;
* V_300 = V_152 ;
F_76 ( V_221 ) ;
V_221 = V_152 ;
}
V_295 ++ ;
* V_298 = V_221 ;
V_300 = & V_221 -> V_101 ;
}
return V_295 ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_182 * V_132 = V_2 -> V_132 ;
F_249 ( V_2 -> V_27 , & V_132 -> V_301 ) ;
}
int F_250 ( struct V_182 * V_132 , struct V_1 * V_2 )
{
if ( F_35 ( & V_132 -> V_301 ) + V_2 -> V_27 >=
( unsigned int ) V_132 -> V_302 )
return - V_140 ;
F_251 ( V_2 ) ;
V_2 -> V_132 = V_132 ;
V_2 -> V_94 = F_248 ;
F_211 ( V_2 -> V_27 , & V_132 -> V_301 ) ;
F_252 ( V_2 ) ;
F_185 ( & V_132 -> V_303 , V_2 ) ;
if ( ! F_253 ( V_132 , V_304 ) )
V_132 -> V_305 ( V_132 ) ;
return 0 ;
}
void F_254 ( struct V_1 * V_306 ,
struct V_307 * V_308 )
{
struct V_182 * V_132 = V_306 -> V_132 ;
struct V_309 * V_310 ;
struct V_1 * V_2 ;
int V_160 ;
if ( ! V_132 )
return;
if ( V_308 ) {
* F_255 ( V_306 ) =
* V_308 ;
} else {
V_306 -> V_104 = F_256 () ;
}
V_2 = F_105 ( V_306 , V_50 ) ;
if ( ! V_2 )
return;
V_310 = F_257 ( V_2 ) ;
memset ( V_310 , 0 , sizeof( * V_310 ) ) ;
V_310 -> V_311 . V_312 = V_313 ;
V_310 -> V_311 . V_314 = V_315 ;
V_160 = F_250 ( V_132 , V_2 ) ;
if ( V_160 )
F_76 ( V_2 ) ;
}
void F_258 ( struct V_1 * V_2 , bool V_316 )
{
struct V_182 * V_132 = V_2 -> V_132 ;
struct V_309 * V_310 ;
int V_160 ;
V_2 -> V_317 = 1 ;
V_2 -> V_318 = V_316 ;
V_310 = F_257 ( V_2 ) ;
memset ( V_310 , 0 , sizeof( * V_310 ) ) ;
V_310 -> V_311 . V_312 = V_313 ;
V_310 -> V_311 . V_314 = V_319 ;
V_160 = F_250 ( V_132 , V_2 ) ;
if ( V_160 )
F_76 ( V_2 ) ;
}
bool F_259 ( struct V_1 * V_2 , T_12 V_174 , T_12 V_76 )
{
if ( F_32 ( V_174 > F_117 ( V_2 ) ) ||
F_32 ( ( int ) V_174 + V_76 > F_117 ( V_2 ) - 2 ) ) {
F_224 ( L_6 ,
V_174 , V_76 , F_117 ( V_2 ) ) ;
return false ;
}
V_2 -> V_120 = V_142 ;
V_2 -> V_143 = F_93 ( V_2 ) + V_174 ;
V_2 -> V_215 = V_76 ;
F_233 ( V_2 , V_174 ) ;
return true ;
}
static int F_260 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_320 )
{
if ( F_117 ( V_2 ) >= V_6 )
return 0 ;
if ( V_320 > V_2 -> V_6 )
V_320 = V_2 -> V_6 ;
if ( F_143 ( V_2 , V_320 - F_117 ( V_2 ) ) == NULL )
return - V_140 ;
if ( F_117 ( V_2 ) < V_6 )
return - V_321 ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 , bool V_322 )
{
unsigned int V_76 ;
bool V_323 ;
V_216 * V_117 ;
int V_160 ;
V_323 = false ;
V_160 = F_260 ( V_2 ,
sizeof( struct V_324 ) ,
V_325 ) ;
if ( V_160 < 0 )
goto V_23;
if ( F_262 ( V_2 ) -> V_326 & F_263 ( V_327 | V_328 ) )
V_323 = true ;
V_76 = F_264 ( V_2 ) ;
V_160 = - V_321 ;
if ( V_323 )
goto V_23;
V_117 = F_265 ( V_2 , F_262 ( V_2 ) -> V_124 , V_76 ) ;
if ( F_266 ( V_117 ) )
return F_267 ( V_117 ) ;
if ( V_322 )
* V_117 = ~ F_268 ( F_262 ( V_2 ) -> V_329 ,
F_262 ( V_2 ) -> V_330 ,
V_2 -> V_6 - V_76 ,
F_262 ( V_2 ) -> V_124 , 0 ) ;
V_160 = 0 ;
V_23:
return V_160 ;
}
static int F_269 ( struct V_1 * V_2 , bool V_322 )
{
int V_160 ;
T_3 V_331 ;
unsigned int V_76 ;
unsigned int V_6 ;
bool V_323 ;
bool V_166 ;
V_216 * V_117 ;
V_323 = false ;
V_166 = false ;
V_76 = sizeof( struct V_332 ) ;
V_160 = F_260 ( V_2 , V_76 , V_333 ) ;
if ( V_160 < 0 )
goto V_23;
V_331 = F_270 ( V_2 ) -> V_331 ;
V_6 = sizeof( struct V_332 ) + F_271 ( F_270 ( V_2 ) -> V_334 ) ;
while ( V_76 <= V_6 && ! V_166 ) {
switch ( V_331 ) {
case V_335 :
case V_336 :
case V_337 : {
struct V_338 * V_339 ;
V_160 = F_260 ( V_2 ,
V_76 +
sizeof( struct V_338 ) ,
V_333 ) ;
if ( V_160 < 0 )
goto V_23;
V_339 = F_272 ( struct V_338 , V_2 , V_76 ) ;
V_331 = V_339 -> V_331 ;
V_76 += F_273 ( V_339 ) ;
break;
}
case V_340 : {
struct V_341 * V_339 ;
V_160 = F_260 ( V_2 ,
V_76 +
sizeof( struct V_341 ) ,
V_333 ) ;
if ( V_160 < 0 )
goto V_23;
V_339 = F_272 ( struct V_341 , V_2 , V_76 ) ;
V_331 = V_339 -> V_331 ;
V_76 += F_274 ( V_339 ) ;
break;
}
case V_342 : {
struct V_343 * V_339 ;
V_160 = F_260 ( V_2 ,
V_76 +
sizeof( struct V_343 ) ,
V_333 ) ;
if ( V_160 < 0 )
goto V_23;
V_339 = F_272 ( struct V_343 , V_2 , V_76 ) ;
if ( V_339 -> V_326 & F_263 ( V_344 | V_345 ) )
V_323 = true ;
V_331 = V_339 -> V_331 ;
V_76 += sizeof( struct V_343 ) ;
break;
}
default:
V_166 = true ;
break;
}
}
V_160 = - V_321 ;
if ( ! V_166 || V_323 )
goto V_23;
V_117 = F_265 ( V_2 , V_331 , V_76 ) ;
if ( F_266 ( V_117 ) )
return F_267 ( V_117 ) ;
if ( V_322 )
* V_117 = ~ F_275 ( & F_270 ( V_2 ) -> V_329 ,
& F_270 ( V_2 ) -> V_330 ,
V_2 -> V_6 - V_76 , V_331 , 0 ) ;
V_160 = 0 ;
V_23:
return V_160 ;
}
int F_276 ( struct V_1 * V_2 , bool V_322 )
{
int V_160 ;
switch ( V_2 -> V_124 ) {
case F_263 ( V_346 ) :
V_160 = F_261 ( V_2 , V_322 ) ;
break;
case F_263 ( V_347 ) :
V_160 = F_269 ( V_2 , V_322 ) ;
break;
default:
V_160 = - V_321 ;
break;
}
return V_160 ;
}
void F_277 ( const struct V_1 * V_2 )
{
F_224 ( L_7 ,
V_2 -> V_11 -> V_12 ) ;
}
void F_278 ( struct V_1 * V_2 , bool V_348 )
{
if ( V_348 ) {
F_62 ( V_2 ) ;
F_26 ( V_25 , V_2 ) ;
} else {
F_75 ( V_2 ) ;
}
}
bool F_279 ( struct V_1 * V_173 , struct V_1 * V_202 ,
bool * V_349 , int * V_282 )
{
int V_75 , V_153 , V_6 = V_202 -> V_6 ;
* V_349 = false ;
if ( F_124 ( V_173 ) )
return false ;
if ( V_6 <= F_130 ( V_173 ) ) {
F_121 ( F_115 ( V_202 , 0 , F_114 ( V_173 , V_6 ) , V_6 ) ) ;
* V_282 = 0 ;
return true ;
}
if ( F_59 ( V_173 ) || F_59 ( V_202 ) )
return false ;
if ( F_117 ( V_202 ) != 0 ) {
struct V_57 * V_57 ;
unsigned int V_67 ;
if ( F_23 ( V_173 ) -> V_85 +
F_23 ( V_202 ) -> V_85 >= V_190 )
return false ;
if ( F_159 ( V_202 ) )
return false ;
V_153 = V_202 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
V_57 = F_42 ( V_202 -> V_7 ) ;
V_67 = V_202 -> V_8 - ( unsigned char * ) F_37 ( V_57 ) ;
F_45 ( V_173 , F_23 ( V_173 ) -> V_85 ,
V_57 , V_67 , F_117 ( V_202 ) ) ;
* V_349 = true ;
} else {
if ( F_23 ( V_173 ) -> V_85 +
F_23 ( V_202 ) -> V_85 > V_190 )
return false ;
V_153 = V_202 -> V_27 - F_21 ( F_113 ( V_202 ) ) ;
}
F_280 ( V_153 < V_6 ) ;
memcpy ( F_23 ( V_173 ) -> V_78 + F_23 ( V_173 ) -> V_85 ,
F_23 ( V_202 ) -> V_78 ,
F_23 ( V_202 ) -> V_85 * sizeof( T_5 ) ) ;
F_23 ( V_173 ) -> V_85 += F_23 ( V_202 ) -> V_85 ;
if ( ! F_124 ( V_202 ) )
F_23 ( V_202 ) -> V_85 = 0 ;
for ( V_75 = 0 ; V_75 < F_23 ( V_202 ) -> V_85 ; V_75 ++ )
F_119 ( V_202 , V_75 ) ;
V_173 -> V_27 += V_153 ;
V_173 -> V_6 += V_6 ;
V_173 -> V_77 += V_6 ;
* V_282 = V_153 ;
return true ;
}
void F_281 ( struct V_1 * V_2 , bool V_350 )
{
if ( V_350 )
F_251 ( V_2 ) ;
V_2 -> V_104 . V_351 = 0 ;
V_2 -> V_119 = V_352 ;
V_2 -> V_126 = 0 ;
V_2 -> V_118 = 0 ;
F_63 ( V_2 ) ;
V_2 -> V_125 = 0 ;
F_282 ( V_2 ) ;
F_283 ( V_2 ) ;
F_284 ( V_2 ) ;
}
unsigned int F_285 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_23 ( V_2 ) ;
if ( F_34 ( V_33 -> V_146 & ( V_353 | V_354 ) ) )
return F_286 ( V_2 ) + V_33 -> V_144 ;
return V_33 -> V_144 ;
}
