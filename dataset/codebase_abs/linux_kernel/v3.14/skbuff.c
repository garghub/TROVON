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
#ifdef F_64
V_102 -> V_93 = F_86 ( V_103 -> V_93 ) ;
#endif
memcpy ( V_102 -> V_113 , V_103 -> V_113 , sizeof( V_103 -> V_113 ) ) ;
V_102 -> V_114 = V_103 -> V_114 ;
V_102 -> V_115 = V_103 -> V_115 ;
V_102 -> V_116 = V_103 -> V_116 ;
V_102 -> V_117 = V_103 -> V_117 ;
F_87 ( V_102 , V_103 ) ;
V_102 -> V_118 = V_103 -> V_118 ;
#if F_68 ( V_119 )
V_102 -> V_120 = V_103 -> V_120 ;
#endif
V_102 -> V_18 = V_103 -> V_18 ;
V_102 -> V_121 = V_103 -> V_121 ;
V_102 -> V_122 = V_103 -> V_122 ;
V_102 -> V_123 = V_103 -> V_123 ;
F_88 ( V_102 , V_103 ) ;
#ifdef F_72
V_102 -> V_98 = V_103 -> V_98 ;
#ifdef F_73
V_102 -> V_99 = V_103 -> V_99 ;
#endif
#endif
V_102 -> V_124 = V_103 -> V_124 ;
V_102 -> V_125 = V_103 -> V_125 ;
F_89 ( V_102 , V_103 ) ;
#ifdef F_90
V_102 -> V_126 = V_103 -> V_126 ;
#endif
}
static struct V_1 * F_91 ( struct V_1 * V_127 , struct V_1 * V_2 )
{
#define F_92 ( T_6 ) n->x = skb->x
V_127 -> V_101 = V_127 -> V_128 = NULL ;
V_127 -> V_129 = NULL ;
F_83 ( V_127 , V_2 ) ;
F_92 ( V_6 ) ;
F_92 ( V_77 ) ;
F_92 ( V_130 ) ;
V_127 -> V_131 = V_2 -> V_83 ? F_93 ( V_2 ) : V_2 -> V_131 ;
V_127 -> V_82 = 1 ;
V_127 -> V_83 = 0 ;
V_127 -> V_94 = NULL ;
F_92 ( V_9 ) ;
F_92 ( V_10 ) ;
F_92 ( V_7 ) ;
F_92 ( V_51 ) ;
F_92 ( V_8 ) ;
F_92 ( V_27 ) ;
F_12 ( & V_127 -> V_28 , 1 ) ;
F_94 ( & ( F_23 ( V_2 ) -> V_40 ) ) ;
V_2 -> V_82 = 1 ;
return V_127 ;
#undef F_92
}
struct V_1 * F_95 ( struct V_1 * V_132 , struct V_1 * V_133 )
{
F_74 ( V_132 ) ;
return F_91 ( V_132 , V_133 ) ;
}
int F_96 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_75 ;
int V_134 = F_23 ( V_2 ) -> V_85 ;
struct V_57 * V_57 , * V_7 = NULL ;
struct V_88 * V_89 = F_23 ( V_2 ) -> V_41 ;
for ( V_75 = 0 ; V_75 < V_134 ; V_75 ++ ) {
T_3 * V_135 ;
T_5 * V_136 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
V_57 = F_97 ( V_24 ) ;
if ( ! V_57 ) {
while ( V_7 ) {
struct V_57 * V_101 = (struct V_57 * ) F_98 ( V_7 ) ;
F_41 ( V_7 ) ;
V_7 = V_101 ;
}
return - V_137 ;
}
V_135 = F_99 ( F_100 ( V_136 ) ) ;
memcpy ( F_37 ( V_57 ) ,
V_135 + V_136 -> V_138 , F_101 ( V_136 ) ) ;
F_102 ( V_135 ) ;
F_103 ( V_57 , ( unsigned long ) V_7 ) ;
V_7 = V_57 ;
}
for ( V_75 = 0 ; V_75 < V_134 ; V_75 ++ )
F_58 ( V_2 , V_75 ) ;
V_89 -> V_90 ( V_89 , false ) ;
for ( V_75 = V_134 - 1 ; V_75 >= 0 ; V_75 -- ) {
F_104 ( V_2 , V_75 , V_7 , 0 ,
F_23 ( V_2 ) -> V_78 [ V_75 ] . V_14 ) ;
V_7 = (struct V_57 * ) F_98 ( V_7 ) ;
}
F_23 ( V_2 ) -> V_86 &= ~ V_87 ;
return 0 ;
}
struct V_1 * F_105 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_1 * V_127 ;
if ( F_106 ( V_2 , V_24 ) )
return NULL ;
V_127 = V_2 + 1 ;
if ( V_2 -> V_46 == V_47 &&
V_127 -> V_46 == V_48 ) {
T_4 * V_43 = ( T_4 * ) ( V_127 + 1 ) ;
V_127 -> V_46 = V_92 ;
F_94 ( V_43 ) ;
} else {
if ( F_107 ( V_2 ) )
V_24 |= V_37 ;
V_127 = F_28 ( V_25 , V_24 ) ;
if ( ! V_127 )
return NULL ;
F_25 ( V_127 , V_44 ) ;
F_25 ( V_127 , V_45 ) ;
V_127 -> V_46 = V_48 ;
}
return F_91 ( V_127 , V_2 ) ;
}
static void F_108 ( struct V_1 * V_2 , int V_76 )
{
if ( V_2 -> V_117 == V_139 )
V_2 -> V_140 += V_76 ;
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
F_23 ( V_102 ) -> V_141 = F_23 ( V_103 ) -> V_141 ;
F_23 ( V_102 ) -> V_142 = F_23 ( V_103 ) -> V_142 ;
F_23 ( V_102 ) -> V_143 = F_23 ( V_103 ) -> V_143 ;
}
static inline int F_111 ( const struct V_1 * V_2 )
{
if ( F_107 ( V_2 ) )
return V_36 ;
return 0 ;
}
struct V_1 * F_112 ( const struct V_1 * V_2 , T_2 V_24 )
{
int V_144 = F_93 ( V_2 ) ;
unsigned int V_14 = F_113 ( V_2 ) + V_2 -> V_77 ;
struct V_1 * V_127 = F_14 ( V_14 , V_24 ,
F_111 ( V_2 ) , V_74 ) ;
if ( ! V_127 )
return NULL ;
F_43 ( V_127 , V_144 ) ;
F_114 ( V_127 , V_2 -> V_6 ) ;
if ( F_115 ( V_2 , - V_144 , V_127 -> V_7 , V_144 + V_2 -> V_6 ) )
F_3 () ;
F_110 ( V_127 , V_2 ) ;
return V_127 ;
}
struct V_1 * F_116 ( struct V_1 * V_2 , int V_145 , T_2 V_24 )
{
unsigned int V_14 = F_117 ( V_2 ) + V_145 ;
struct V_1 * V_127 = F_14 ( V_14 , V_24 ,
F_111 ( V_2 ) , V_74 ) ;
if ( ! V_127 )
goto V_23;
F_43 ( V_127 , V_145 ) ;
F_114 ( V_127 , F_117 ( V_2 ) ) ;
F_118 ( V_2 , V_127 -> V_8 , V_127 -> V_6 ) ;
V_127 -> V_27 += V_2 -> V_77 ;
V_127 -> V_77 = V_2 -> V_77 ;
V_127 -> V_6 = V_2 -> V_6 ;
if ( F_23 ( V_2 ) -> V_85 ) {
int V_75 ;
if ( F_106 ( V_2 , V_24 ) ) {
F_76 ( V_127 ) ;
V_127 = NULL ;
goto V_23;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
F_23 ( V_127 ) -> V_78 [ V_75 ] = F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_119 ( V_2 , V_75 ) ;
}
F_23 ( V_127 ) -> V_85 = V_75 ;
}
if ( F_59 ( V_2 ) ) {
F_23 ( V_127 ) -> V_80 = F_23 ( V_2 ) -> V_80 ;
F_51 ( V_127 ) ;
}
F_110 ( V_127 , V_2 ) ;
V_23:
return V_127 ;
}
int F_120 ( struct V_1 * V_2 , int V_146 , int V_147 ,
T_2 V_24 )
{
int V_75 ;
T_3 * V_8 ;
int V_14 = V_146 + F_113 ( V_2 ) + V_147 ;
long V_76 ;
F_121 ( V_146 < 0 ) ;
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
memcpy ( V_8 + V_146 , V_2 -> V_7 , F_123 ( V_2 ) - V_2 -> V_7 ) ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) ,
F_11 ( struct V_32 , V_78 [ F_23 ( V_2 ) -> V_85 ] ) ) ;
if ( F_124 ( V_2 ) ) {
if ( F_106 ( V_2 , V_24 ) )
goto V_148;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ )
F_119 ( V_2 , V_75 ) ;
if ( F_59 ( V_2 ) )
F_51 ( V_2 ) ;
F_56 ( V_2 ) ;
} else {
F_54 ( V_2 ) ;
}
V_76 = ( V_8 + V_146 ) - V_2 -> V_7 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_51 = 0 ;
V_2 -> V_8 += V_76 ;
#ifdef F_125
V_2 -> V_10 = V_14 ;
V_76 = V_146 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
V_2 -> V_9 += V_76 ;
F_108 ( V_2 , V_146 ) ;
V_2 -> V_82 = 0 ;
V_2 -> V_131 = 0 ;
V_2 -> V_83 = 0 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
V_148:
F_55 ( V_8 ) ;
V_38:
return - V_137 ;
}
struct V_1 * F_126 ( struct V_1 * V_2 , unsigned int V_145 )
{
struct V_1 * V_149 ;
int V_150 = V_145 - F_93 ( V_2 ) ;
if ( V_150 <= 0 )
V_149 = F_127 ( V_2 , V_50 ) ;
else {
V_149 = F_105 ( V_2 , V_50 ) ;
if ( V_149 && F_120 ( V_149 , F_17 ( V_150 ) , 0 ,
V_50 ) ) {
F_76 ( V_149 ) ;
V_149 = NULL ;
}
}
return V_149 ;
}
struct V_1 * F_128 ( const struct V_1 * V_2 ,
int V_151 , int V_152 ,
T_2 V_24 )
{
struct V_1 * V_127 = F_14 ( V_151 + V_2 -> V_6 + V_152 ,
V_24 , F_111 ( V_2 ) ,
V_74 ) ;
int V_153 = F_93 ( V_2 ) ;
int V_154 , V_155 ;
if ( ! V_127 )
return NULL ;
F_43 ( V_127 , V_151 ) ;
F_114 ( V_127 , V_2 -> V_6 ) ;
V_154 = V_153 ;
V_155 = 0 ;
if ( V_151 <= V_154 )
V_154 = V_151 ;
else
V_155 = V_151 - V_154 ;
if ( F_115 ( V_2 , - V_154 , V_127 -> V_7 + V_155 ,
V_2 -> V_6 + V_154 ) )
F_3 () ;
F_110 ( V_127 , V_2 ) ;
F_108 ( V_127 , V_151 - V_153 ) ;
return V_127 ;
}
int F_129 ( struct V_1 * V_2 , int V_156 )
{
int V_157 ;
int V_147 ;
if ( ! F_124 ( V_2 ) && F_130 ( V_2 ) >= V_156 ) {
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_156 ) ;
return 0 ;
}
V_147 = V_2 -> V_77 + V_156 - ( V_2 -> V_10 - V_2 -> V_9 ) ;
if ( F_34 ( F_124 ( V_2 ) || V_147 > 0 ) ) {
V_157 = F_120 ( V_2 , 0 , V_147 , V_50 ) ;
if ( F_32 ( V_157 ) )
goto V_158;
}
V_157 = F_131 ( V_2 ) ;
if ( F_32 ( V_157 ) )
goto V_158;
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_156 ) ;
return 0 ;
V_158:
F_76 ( V_2 ) ;
return V_157 ;
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
unsigned char * V_159 = F_123 ( V_2 ) ;
F_133 ( V_2 ) ;
V_2 -> V_9 += V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_32 ( V_2 -> V_9 > V_2 -> V_10 ) )
F_4 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_159 ;
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
struct V_1 * * V_160 ;
struct V_1 * V_56 ;
int V_67 = F_117 ( V_2 ) ;
int V_161 = F_23 ( V_2 ) -> V_85 ;
int V_75 ;
int V_157 ;
if ( F_124 ( V_2 ) &&
F_32 ( ( V_157 = F_120 ( V_2 , 0 , 0 , V_50 ) ) ) )
return V_157 ;
V_75 = 0 ;
if ( V_67 >= V_6 )
goto V_162;
for (; V_75 < V_161 ; V_75 ++ ) {
int V_10 = V_67 + F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( V_10 < V_6 ) {
V_67 = V_10 ;
continue;
}
F_140 ( & F_23 ( V_2 ) -> V_78 [ V_75 ++ ] , V_6 - V_67 ) ;
V_162:
F_23 ( V_2 ) -> V_85 = V_75 ;
for (; V_75 < V_161 ; V_75 ++ )
F_58 ( V_2 , V_75 ) ;
if ( F_59 ( V_2 ) )
F_50 ( V_2 ) ;
goto V_163;
}
for ( V_160 = & F_23 ( V_2 ) -> V_80 ; ( V_56 = * V_160 ) ;
V_160 = & V_56 -> V_101 ) {
int V_10 = V_67 + V_56 -> V_6 ;
if ( F_122 ( V_56 ) ) {
struct V_1 * V_164 ;
V_164 = F_105 ( V_56 , V_50 ) ;
if ( F_32 ( ! V_164 ) )
return - V_137 ;
V_164 -> V_101 = V_56 -> V_101 ;
F_81 ( V_56 ) ;
V_56 = V_164 ;
* V_160 = V_56 ;
}
if ( V_10 < V_6 ) {
V_67 = V_10 ;
continue;
}
if ( V_10 > V_6 &&
F_32 ( ( V_157 = F_141 ( V_56 , V_6 - V_67 ) ) ) )
return V_157 ;
if ( V_56 -> V_101 )
F_48 ( & V_56 -> V_101 ) ;
break;
}
V_163:
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
unsigned char * F_143 ( struct V_1 * V_2 , int V_150 )
{
int V_75 , V_165 , V_166 = ( V_2 -> V_9 + V_150 ) - V_2 -> V_10 ;
if ( V_166 > 0 || F_124 ( V_2 ) ) {
if ( F_120 ( V_2 , 0 , V_166 > 0 ? V_166 + 128 : 0 ,
V_50 ) )
return NULL ;
}
if ( F_115 ( V_2 , F_117 ( V_2 ) , F_123 ( V_2 ) , V_150 ) )
F_3 () ;
if ( ! F_59 ( V_2 ) )
goto V_167;
V_166 = V_150 ;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_14 = F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( V_14 >= V_166 )
goto V_167;
V_166 -= V_14 ;
}
if ( V_166 ) {
struct V_1 * V_81 = F_23 ( V_2 ) -> V_80 ;
struct V_1 * V_168 = NULL ;
struct V_1 * V_169 = NULL ;
do {
F_121 ( ! V_81 ) ;
if ( V_81 -> V_6 <= V_166 ) {
V_166 -= V_81 -> V_6 ;
V_81 = V_81 -> V_101 ;
V_169 = V_81 ;
} else {
if ( F_122 ( V_81 ) ) {
V_168 = F_105 ( V_81 , V_50 ) ;
if ( ! V_168 )
return NULL ;
V_169 = V_81 -> V_101 ;
V_81 = V_168 ;
} else {
V_169 = V_81 ;
}
if ( ! F_144 ( V_81 , V_166 ) ) {
F_76 ( V_168 ) ;
return NULL ;
}
break;
}
} while ( V_166 );
while ( ( V_81 = F_23 ( V_2 ) -> V_80 ) != V_169 ) {
F_23 ( V_2 ) -> V_80 = V_81 -> V_101 ;
F_76 ( V_81 ) ;
}
if ( V_168 ) {
V_168 -> V_101 = V_81 ;
F_23 ( V_2 ) -> V_80 = V_168 ;
}
}
V_167:
V_166 = V_150 ;
V_165 = 0 ;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_14 = F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( V_14 <= V_166 ) {
F_58 ( V_2 , V_75 ) ;
V_166 -= V_14 ;
} else {
F_23 ( V_2 ) -> V_78 [ V_165 ] = F_23 ( V_2 ) -> V_78 [ V_75 ] ;
if ( V_166 ) {
F_23 ( V_2 ) -> V_78 [ V_165 ] . V_138 += V_166 ;
F_145 ( & F_23 ( V_2 ) -> V_78 [ V_165 ] , V_166 ) ;
V_166 = 0 ;
}
V_165 ++ ;
}
}
F_23 ( V_2 ) -> V_85 = V_165 ;
V_2 -> V_9 += V_150 ;
V_2 -> V_77 -= V_150 ;
return F_123 ( V_2 ) ;
}
int F_115 ( const struct V_1 * V_2 , int V_67 , void * V_170 , int V_6 )
{
int V_171 = F_117 ( V_2 ) ;
struct V_1 * V_172 ;
int V_75 , V_173 ;
if ( V_67 > ( int ) V_2 -> V_6 - V_6 )
goto V_174;
if ( ( V_173 = V_171 - V_67 ) > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
F_146 ( V_2 , V_67 , V_170 , V_173 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return 0 ;
V_67 += V_173 ;
V_170 += V_173 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_10 ;
T_5 * V_136 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + F_101 ( V_136 ) ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
T_3 * V_135 ;
if ( V_173 > V_6 )
V_173 = V_6 ;
V_135 = F_99 ( F_100 ( V_136 ) ) ;
memcpy ( V_170 ,
V_135 + V_136 -> V_138 + V_67 - V_171 ,
V_173 ) ;
F_102 ( V_135 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return 0 ;
V_67 += V_173 ;
V_170 += V_173 ;
}
V_171 = V_10 ;
}
F_52 (skb, frag_iter) {
int V_10 ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + V_172 -> V_6 ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
if ( F_115 ( V_172 , V_67 - V_171 , V_170 , V_173 ) )
goto V_174;
if ( ( V_6 -= V_173 ) == 0 )
return 0 ;
V_67 += V_173 ;
V_170 += V_173 ;
}
V_171 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_174:
return - V_175 ;
}
static void F_147 ( struct V_176 * V_177 , unsigned int V_75 )
{
F_41 ( V_177 -> V_178 [ V_75 ] ) ;
}
static struct V_57 * F_148 ( struct V_57 * V_57 , unsigned int * V_6 ,
unsigned int * V_67 ,
struct V_179 * V_129 )
{
struct V_180 * V_181 = F_149 ( V_129 ) ;
if ( ! F_150 ( V_129 , V_181 ) )
return NULL ;
* V_6 = F_151 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_37 ( V_181 -> V_57 ) + V_181 -> V_67 ,
F_37 ( V_57 ) + * V_67 , * V_6 ) ;
* V_67 = V_181 -> V_67 ;
V_181 -> V_67 += * V_6 ;
return V_181 -> V_57 ;
}
static bool F_152 ( const struct V_176 * V_177 ,
struct V_57 * V_57 ,
unsigned int V_67 )
{
return V_177 -> V_182 &&
V_177 -> V_178 [ V_177 -> V_182 - 1 ] == V_57 &&
( V_177 -> V_183 [ V_177 -> V_182 - 1 ] . V_67 +
V_177 -> V_183 [ V_177 -> V_182 - 1 ] . V_6 == V_67 ) ;
}
static bool F_153 ( struct V_176 * V_177 ,
struct V_184 * V_185 , struct V_57 * V_57 ,
unsigned int * V_6 , unsigned int V_67 ,
bool V_186 ,
struct V_179 * V_129 )
{
if ( F_32 ( V_177 -> V_182 == V_187 ) )
return true ;
if ( V_186 ) {
V_57 = F_148 ( V_57 , V_6 , & V_67 , V_129 ) ;
if ( ! V_57 )
return true ;
}
if ( F_152 ( V_177 , V_57 , V_67 ) ) {
V_177 -> V_183 [ V_177 -> V_182 - 1 ] . V_6 += * V_6 ;
return false ;
}
F_154 ( V_57 ) ;
V_177 -> V_178 [ V_177 -> V_182 ] = V_57 ;
V_177 -> V_183 [ V_177 -> V_182 ] . V_6 = * V_6 ;
V_177 -> V_183 [ V_177 -> V_182 ] . V_67 = V_67 ;
V_177 -> V_182 ++ ;
return false ;
}
static bool F_155 ( struct V_57 * V_57 , unsigned int V_188 ,
unsigned int V_189 , unsigned int * V_76 ,
unsigned int * V_6 ,
struct V_176 * V_177 , bool V_186 ,
struct V_179 * V_129 ,
struct V_184 * V_185 )
{
if ( ! * V_6 )
return true ;
if ( * V_76 >= V_189 ) {
* V_76 -= V_189 ;
return false ;
}
V_188 += * V_76 ;
V_189 -= * V_76 ;
* V_76 = 0 ;
do {
unsigned int V_190 = F_156 ( * V_6 , V_189 ) ;
if ( F_153 ( V_177 , V_185 , V_57 , & V_190 , V_188 ,
V_186 , V_129 ) )
return true ;
V_188 += V_190 ;
V_189 -= V_190 ;
* V_6 -= V_190 ;
} while ( * V_6 && V_189 );
return false ;
}
static bool F_157 ( struct V_1 * V_2 , struct V_184 * V_185 ,
unsigned int * V_67 , unsigned int * V_6 ,
struct V_176 * V_177 , struct V_179 * V_129 )
{
int V_191 ;
if ( F_155 ( F_158 ( V_2 -> V_8 ) ,
( unsigned long ) V_2 -> V_8 & ( V_62 - 1 ) ,
F_117 ( V_2 ) ,
V_67 , V_6 , V_177 ,
F_159 ( V_2 ) ,
V_129 , V_185 ) )
return true ;
for ( V_191 = 0 ; V_191 < F_23 ( V_2 ) -> V_85 ; V_191 ++ ) {
const T_5 * V_136 = & F_23 ( V_2 ) -> V_78 [ V_191 ] ;
if ( F_155 ( F_100 ( V_136 ) ,
V_136 -> V_138 , F_101 ( V_136 ) ,
V_67 , V_6 , V_177 , false , V_129 , V_185 ) )
return true ;
}
return false ;
}
int F_160 ( struct V_1 * V_2 , unsigned int V_67 ,
struct V_184 * V_185 , unsigned int V_192 ,
unsigned int V_15 )
{
struct V_193 V_183 [ V_187 ] ;
struct V_57 * V_178 [ V_187 ] ;
struct V_176 V_177 = {
. V_178 = V_178 ,
. V_183 = V_183 ,
. V_194 = V_187 ,
. V_15 = V_15 ,
. V_195 = & V_196 ,
. V_197 = F_147 ,
} ;
struct V_1 * V_172 ;
struct V_179 * V_129 = V_2 -> V_129 ;
int V_198 = 0 ;
if ( F_157 ( V_2 , V_185 , & V_67 , & V_192 , & V_177 , V_129 ) )
goto V_163;
else if ( ! V_192 )
goto V_163;
F_52 (skb, frag_iter) {
if ( ! V_192 )
break;
if ( F_157 ( V_172 , V_185 , & V_67 , & V_192 , & V_177 , V_129 ) )
break;
}
V_163:
if ( V_177 . V_182 ) {
F_161 ( V_129 ) ;
V_198 = F_162 ( V_185 , & V_177 ) ;
F_163 ( V_129 ) ;
}
return V_198 ;
}
int F_164 ( struct V_1 * V_2 , int V_67 , const void * V_199 , int V_6 )
{
int V_171 = F_117 ( V_2 ) ;
struct V_1 * V_172 ;
int V_75 , V_173 ;
if ( V_67 > ( int ) V_2 -> V_6 - V_6 )
goto V_174;
if ( ( V_173 = V_171 - V_67 ) > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
F_165 ( V_2 , V_67 , V_199 , V_173 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return 0 ;
V_67 += V_173 ;
V_199 += V_173 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
int V_10 ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + F_101 ( V_56 ) ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
T_3 * V_135 ;
if ( V_173 > V_6 )
V_173 = V_6 ;
V_135 = F_99 ( F_100 ( V_56 ) ) ;
memcpy ( V_135 + V_56 -> V_138 + V_67 - V_171 ,
V_199 , V_173 ) ;
F_102 ( V_135 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return 0 ;
V_67 += V_173 ;
V_199 += V_173 ;
}
V_171 = V_10 ;
}
F_52 (skb, frag_iter) {
int V_10 ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + V_172 -> V_6 ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
if ( F_164 ( V_172 , V_67 - V_171 ,
V_199 , V_173 ) )
goto V_174;
if ( ( V_6 -= V_173 ) == 0 )
return 0 ;
V_67 += V_173 ;
V_199 += V_173 ;
}
V_171 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_174:
return - V_175 ;
}
T_7 F_166 ( const struct V_1 * V_2 , int V_67 , int V_6 ,
T_7 V_114 , const struct V_200 * V_195 )
{
int V_171 = F_117 ( V_2 ) ;
int V_75 , V_173 = V_171 - V_67 ;
struct V_1 * V_172 ;
int V_201 = 0 ;
if ( V_173 > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
V_114 = V_195 -> V_202 ( V_2 -> V_8 + V_67 , V_173 , V_114 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return V_114 ;
V_67 += V_173 ;
V_201 = V_173 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_10 ;
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + F_101 ( V_56 ) ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
T_7 V_203 ;
T_3 * V_135 ;
if ( V_173 > V_6 )
V_173 = V_6 ;
V_135 = F_99 ( F_100 ( V_56 ) ) ;
V_203 = V_195 -> V_202 ( V_135 + V_56 -> V_138 +
V_67 - V_171 , V_173 , 0 ) ;
F_102 ( V_135 ) ;
V_114 = V_195 -> V_204 ( V_114 , V_203 , V_201 , V_173 ) ;
if ( ! ( V_6 -= V_173 ) )
return V_114 ;
V_67 += V_173 ;
V_201 += V_173 ;
}
V_171 = V_10 ;
}
F_52 (skb, frag_iter) {
int V_10 ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + V_172 -> V_6 ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
T_7 V_203 ;
if ( V_173 > V_6 )
V_173 = V_6 ;
V_203 = F_166 ( V_172 , V_67 - V_171 ,
V_173 , 0 , V_195 ) ;
V_114 = V_195 -> V_204 ( V_114 , V_203 , V_201 , V_173 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return V_114 ;
V_67 += V_173 ;
V_201 += V_173 ;
}
V_171 = V_10 ;
}
F_121 ( V_6 ) ;
return V_114 ;
}
T_7 F_167 ( const struct V_1 * V_2 , int V_67 ,
int V_6 , T_7 V_114 )
{
const struct V_200 V_195 = {
. V_202 = V_205 ,
. V_204 = V_206 ,
} ;
return F_166 ( V_2 , V_67 , V_6 , V_114 , & V_195 ) ;
}
T_7 F_168 ( const struct V_1 * V_2 , int V_67 ,
T_3 * V_170 , int V_6 , T_7 V_114 )
{
int V_171 = F_117 ( V_2 ) ;
int V_75 , V_173 = V_171 - V_67 ;
struct V_1 * V_172 ;
int V_201 = 0 ;
if ( V_173 > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
V_114 = F_169 ( V_2 -> V_8 + V_67 , V_170 ,
V_173 , V_114 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return V_114 ;
V_67 += V_173 ;
V_170 += V_173 ;
V_201 = V_173 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_10 ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
T_7 V_203 ;
T_3 * V_135 ;
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
if ( V_173 > V_6 )
V_173 = V_6 ;
V_135 = F_99 ( F_100 ( V_56 ) ) ;
V_203 = F_169 ( V_135 +
V_56 -> V_138 +
V_67 - V_171 , V_170 ,
V_173 , 0 ) ;
F_102 ( V_135 ) ;
V_114 = F_170 ( V_114 , V_203 , V_201 ) ;
if ( ! ( V_6 -= V_173 ) )
return V_114 ;
V_67 += V_173 ;
V_170 += V_173 ;
V_201 += V_173 ;
}
V_171 = V_10 ;
}
F_52 (skb, frag_iter) {
T_7 V_203 ;
int V_10 ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + V_172 -> V_6 ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
V_203 = F_168 ( V_172 ,
V_67 - V_171 ,
V_170 , V_173 , 0 ) ;
V_114 = F_170 ( V_114 , V_203 , V_201 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return V_114 ;
V_67 += V_173 ;
V_170 += V_173 ;
V_201 += V_173 ;
}
V_171 = V_10 ;
}
F_121 ( V_6 ) ;
return V_114 ;
}
unsigned int
F_171 ( const struct V_1 * V_199 )
{
unsigned int V_207 = 0 ;
if ( ! V_199 -> V_51 ||
F_117 ( V_199 ) < V_208 ||
F_23 ( V_199 ) -> V_85 >= V_187 )
V_207 = F_117 ( V_199 ) ;
if ( F_59 ( V_199 ) )
V_207 = V_199 -> V_6 ;
return V_207 ;
}
int
F_172 ( struct V_1 * V_170 , struct V_1 * V_199 , int V_6 , int V_207 )
{
int V_75 , V_209 = 0 ;
int V_189 = 0 ;
int V_198 ;
struct V_57 * V_57 ;
unsigned int V_67 ;
F_121 ( ! V_199 -> V_51 && ! V_207 ) ;
if ( V_6 <= F_130 ( V_170 ) )
return F_115 ( V_199 , 0 , F_114 ( V_170 , V_6 ) , V_6 ) ;
if ( V_207 ) {
V_198 = F_115 ( V_199 , 0 , F_114 ( V_170 , V_207 ) , V_207 ) ;
if ( F_32 ( V_198 ) )
return V_198 ;
V_6 -= V_207 ;
} else {
V_189 = F_151 ( int , F_117 ( V_199 ) , V_6 ) ;
if ( V_189 ) {
V_57 = F_42 ( V_199 -> V_7 ) ;
V_67 = V_199 -> V_8 - ( unsigned char * ) F_37 ( V_57 ) ;
F_104 ( V_170 , 0 , V_57 , V_67 , V_189 ) ;
F_154 ( V_57 ) ;
V_209 = 1 ;
V_6 -= V_189 ;
}
}
V_170 -> V_27 += V_6 + V_189 ;
V_170 -> V_6 += V_6 + V_189 ;
V_170 -> V_77 += V_6 + V_189 ;
if ( F_32 ( F_106 ( V_199 , V_50 ) ) ) {
F_80 ( V_199 ) ;
return - V_137 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_199 ) -> V_85 ; V_75 ++ ) {
if ( ! V_6 )
break;
F_23 ( V_170 ) -> V_78 [ V_209 ] = F_23 ( V_199 ) -> V_78 [ V_75 ] ;
F_23 ( V_170 ) -> V_78 [ V_209 ] . V_14 = F_151 ( int , F_23 ( V_170 ) -> V_78 [ V_209 ] . V_14 , V_6 ) ;
V_6 -= F_23 ( V_170 ) -> V_78 [ V_209 ] . V_14 ;
F_119 ( V_170 , V_209 ) ;
V_209 ++ ;
}
F_23 ( V_170 ) -> V_85 = V_209 ;
return 0 ;
}
void F_173 ( const struct V_1 * V_2 , T_3 * V_170 )
{
T_7 V_114 ;
long V_210 ;
if ( V_2 -> V_117 == V_139 )
V_210 = F_174 ( V_2 ) ;
else
V_210 = F_117 ( V_2 ) ;
F_121 ( V_210 > F_117 ( V_2 ) ) ;
F_118 ( V_2 , V_170 , V_210 ) ;
V_114 = 0 ;
if ( V_210 != V_2 -> V_6 )
V_114 = F_168 ( V_2 , V_210 , V_170 + V_210 ,
V_2 -> V_6 - V_210 , 0 ) ;
if ( V_2 -> V_117 == V_139 ) {
long V_211 = V_210 + V_2 -> V_212 ;
* ( ( V_213 * ) ( V_170 + V_211 ) ) = F_175 ( V_114 ) ;
}
}
struct V_1 * F_176 ( struct V_214 * V_81 )
{
unsigned long V_15 ;
struct V_1 * V_215 ;
F_177 ( & V_81 -> V_216 , V_15 ) ;
V_215 = F_178 ( V_81 ) ;
F_179 ( & V_81 -> V_216 , V_15 ) ;
return V_215 ;
}
struct V_1 * F_180 ( struct V_214 * V_81 )
{
unsigned long V_15 ;
struct V_1 * V_215 ;
F_177 ( & V_81 -> V_216 , V_15 ) ;
V_215 = F_181 ( V_81 ) ;
F_179 ( & V_81 -> V_216 , V_15 ) ;
return V_215 ;
}
void F_182 ( struct V_214 * V_81 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_176 ( V_81 ) ) != NULL )
F_76 ( V_2 ) ;
}
void F_183 ( struct V_214 * V_81 , struct V_1 * V_217 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_216 , V_15 ) ;
F_184 ( V_81 , V_217 ) ;
F_179 ( & V_81 -> V_216 , V_15 ) ;
}
void F_185 ( struct V_214 * V_81 , struct V_1 * V_217 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_216 , V_15 ) ;
F_186 ( V_81 , V_217 ) ;
F_179 ( & V_81 -> V_216 , V_15 ) ;
}
void F_187 ( struct V_1 * V_2 , struct V_214 * V_81 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_216 , V_15 ) ;
F_188 ( V_2 , V_81 ) ;
F_179 ( & V_81 -> V_216 , V_15 ) ;
}
void F_189 ( struct V_1 * V_103 , struct V_1 * V_217 , struct V_214 * V_81 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_216 , V_15 ) ;
F_190 ( V_81 , V_103 , V_217 ) ;
F_179 ( & V_81 -> V_216 , V_15 ) ;
}
void F_191 ( struct V_1 * V_103 , struct V_1 * V_217 , struct V_214 * V_81 )
{
unsigned long V_15 ;
F_177 ( & V_81 -> V_216 , V_15 ) ;
F_192 ( V_217 , V_103 -> V_128 , V_103 , V_81 ) ;
F_179 ( & V_81 -> V_216 , V_15 ) ;
}
static inline void F_193 ( struct V_1 * V_2 ,
struct V_1 * V_218 ,
const T_8 V_6 , const int V_201 )
{
int V_75 ;
F_146 ( V_2 , V_6 , F_114 ( V_218 , V_201 - V_6 ) ,
V_201 - V_6 ) ;
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ )
F_23 ( V_218 ) -> V_78 [ V_75 ] = F_23 ( V_2 ) -> V_78 [ V_75 ] ;
F_23 ( V_218 ) -> V_85 = F_23 ( V_2 ) -> V_85 ;
F_23 ( V_2 ) -> V_85 = 0 ;
V_218 -> V_77 = V_2 -> V_77 ;
V_218 -> V_6 += V_218 -> V_77 ;
V_2 -> V_77 = 0 ;
V_2 -> V_6 = V_6 ;
F_142 ( V_2 , V_6 ) ;
}
static inline void F_194 ( struct V_1 * V_2 ,
struct V_1 * V_218 ,
const T_8 V_6 , int V_201 )
{
int V_75 , V_165 = 0 ;
const int V_161 = F_23 ( V_2 ) -> V_85 ;
F_23 ( V_2 ) -> V_85 = 0 ;
V_218 -> V_6 = V_218 -> V_77 = V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_77 = V_6 - V_201 ;
for ( V_75 = 0 ; V_75 < V_161 ; V_75 ++ ) {
int V_14 = F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( V_201 + V_14 > V_6 ) {
F_23 ( V_218 ) -> V_78 [ V_165 ] = F_23 ( V_2 ) -> V_78 [ V_75 ] ;
if ( V_201 < V_6 ) {
F_119 ( V_2 , V_75 ) ;
F_23 ( V_218 ) -> V_78 [ 0 ] . V_138 += V_6 - V_201 ;
F_145 ( & F_23 ( V_218 ) -> V_78 [ 0 ] , V_6 - V_201 ) ;
F_140 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] , V_6 - V_201 ) ;
F_23 ( V_2 ) -> V_85 ++ ;
}
V_165 ++ ;
} else
F_23 ( V_2 ) -> V_85 ++ ;
V_201 += V_14 ;
}
F_23 ( V_218 ) -> V_85 = V_165 ;
}
void F_195 ( struct V_1 * V_2 , struct V_1 * V_218 , const T_8 V_6 )
{
int V_201 = F_117 ( V_2 ) ;
F_23 ( V_218 ) -> V_86 = F_23 ( V_2 ) -> V_86 & V_219 ;
if ( V_6 < V_201 )
F_193 ( V_2 , V_218 , V_6 , V_201 ) ;
else
F_194 ( V_2 , V_218 , V_6 , V_201 ) ;
}
static int F_196 ( struct V_1 * V_2 )
{
return F_124 ( V_2 ) && F_120 ( V_2 , 0 , 0 , V_50 ) ;
}
int F_197 ( struct V_1 * V_220 , struct V_1 * V_2 , int V_221 )
{
int V_199 , V_170 , V_222 , V_223 ;
struct V_224 * V_225 , * V_226 ;
F_121 ( V_221 > V_2 -> V_6 ) ;
F_121 ( F_117 ( V_2 ) ) ;
V_223 = V_221 ;
V_199 = 0 ;
V_170 = F_23 ( V_220 ) -> V_85 ;
V_225 = & F_23 ( V_2 ) -> V_78 [ V_199 ] ;
if ( ! V_170 ||
! F_198 ( V_220 , V_170 , F_100 ( V_225 ) ,
V_225 -> V_138 ) ) {
V_222 = - 1 ;
} else {
V_222 = V_170 - 1 ;
V_223 -= F_101 ( V_225 ) ;
if ( V_223 < 0 ) {
if ( F_196 ( V_2 ) ||
F_196 ( V_220 ) )
return 0 ;
V_225 = & F_23 ( V_2 ) -> V_78 [ V_199 ] ;
V_226 = & F_23 ( V_220 ) -> V_78 [ V_222 ] ;
F_47 ( V_226 , V_221 ) ;
F_145 ( V_225 , V_221 ) ;
V_225 -> V_138 += V_221 ;
goto V_227;
}
V_199 ++ ;
}
if ( ( V_221 == V_2 -> V_6 ) &&
( F_23 ( V_2 ) -> V_85 - V_199 ) > ( V_187 - V_170 ) )
return 0 ;
if ( F_196 ( V_2 ) || F_196 ( V_220 ) )
return 0 ;
while ( ( V_223 > 0 ) && ( V_199 < F_23 ( V_2 ) -> V_85 ) ) {
if ( V_170 == V_187 )
return 0 ;
V_225 = & F_23 ( V_2 ) -> V_78 [ V_199 ] ;
V_226 = & F_23 ( V_220 ) -> V_78 [ V_170 ] ;
if ( V_223 >= F_101 ( V_225 ) ) {
* V_226 = * V_225 ;
V_223 -= F_101 ( V_225 ) ;
V_199 ++ ;
V_170 ++ ;
} else {
F_199 ( V_225 ) ;
V_226 -> V_57 = V_225 -> V_57 ;
V_226 -> V_138 = V_225 -> V_138 ;
F_140 ( V_226 , V_223 ) ;
V_225 -> V_138 += V_223 ;
F_145 ( V_225 , V_223 ) ;
V_223 = 0 ;
V_170 ++ ;
break;
}
}
F_23 ( V_220 ) -> V_85 = V_170 ;
if ( V_222 >= 0 ) {
V_225 = & F_23 ( V_2 ) -> V_78 [ 0 ] ;
V_226 = & F_23 ( V_220 ) -> V_78 [ V_222 ] ;
F_47 ( V_226 , F_101 ( V_225 ) ) ;
F_200 ( V_225 ) ;
}
V_170 = 0 ;
while ( V_199 < F_23 ( V_2 ) -> V_85 )
F_23 ( V_2 ) -> V_78 [ V_170 ++ ] = F_23 ( V_2 ) -> V_78 [ V_199 ++ ] ;
F_23 ( V_2 ) -> V_85 = V_170 ;
F_121 ( V_223 > 0 && ! F_23 ( V_2 ) -> V_85 ) ;
V_227:
V_220 -> V_117 = V_139 ;
V_2 -> V_117 = V_139 ;
V_2 -> V_6 -= V_221 ;
V_2 -> V_77 -= V_221 ;
V_2 -> V_27 -= V_221 ;
V_220 -> V_6 += V_221 ;
V_220 -> V_77 += V_221 ;
V_220 -> V_27 += V_221 ;
return V_221 ;
}
void F_201 ( struct V_1 * V_2 , unsigned int V_199 ,
unsigned int V_170 , struct V_228 * V_229 )
{
V_229 -> V_230 = V_199 ;
V_229 -> V_231 = V_170 ;
V_229 -> V_232 = V_229 -> V_233 = V_2 ;
V_229 -> V_234 = V_229 -> V_235 = 0 ;
V_229 -> V_236 = NULL ;
}
unsigned int F_202 ( unsigned int V_237 , const T_3 * * V_8 ,
struct V_228 * V_229 )
{
unsigned int V_238 , V_239 = V_237 + V_229 -> V_230 ;
T_5 * V_56 ;
if ( F_32 ( V_239 >= V_229 -> V_231 ) ) {
if ( V_229 -> V_236 ) {
F_102 ( V_229 -> V_236 ) ;
V_229 -> V_236 = NULL ;
}
return 0 ;
}
V_240:
V_238 = F_117 ( V_229 -> V_233 ) + V_229 -> V_235 ;
if ( V_239 < V_238 && ! V_229 -> V_236 ) {
* V_8 = V_229 -> V_233 -> V_8 + ( V_239 - V_229 -> V_235 ) ;
return V_238 - V_239 ;
}
if ( V_229 -> V_234 == 0 && ! V_229 -> V_236 )
V_229 -> V_235 += F_117 ( V_229 -> V_233 ) ;
while ( V_229 -> V_234 < F_23 ( V_229 -> V_233 ) -> V_85 ) {
V_56 = & F_23 ( V_229 -> V_233 ) -> V_78 [ V_229 -> V_234 ] ;
V_238 = F_101 ( V_56 ) + V_229 -> V_235 ;
if ( V_239 < V_238 ) {
if ( ! V_229 -> V_236 )
V_229 -> V_236 = F_99 ( F_100 ( V_56 ) ) ;
* V_8 = ( T_3 * ) V_229 -> V_236 + V_56 -> V_138 +
( V_239 - V_229 -> V_235 ) ;
return V_238 - V_239 ;
}
if ( V_229 -> V_236 ) {
F_102 ( V_229 -> V_236 ) ;
V_229 -> V_236 = NULL ;
}
V_229 -> V_234 ++ ;
V_229 -> V_235 += F_101 ( V_56 ) ;
}
if ( V_229 -> V_236 ) {
F_102 ( V_229 -> V_236 ) ;
V_229 -> V_236 = NULL ;
}
if ( V_229 -> V_232 == V_229 -> V_233 && F_59 ( V_229 -> V_232 ) ) {
V_229 -> V_233 = F_23 ( V_229 -> V_232 ) -> V_80 ;
V_229 -> V_234 = 0 ;
goto V_240;
} else if ( V_229 -> V_233 -> V_101 ) {
V_229 -> V_233 = V_229 -> V_233 -> V_101 ;
V_229 -> V_234 = 0 ;
goto V_240;
}
return 0 ;
}
void F_203 ( struct V_228 * V_229 )
{
if ( V_229 -> V_236 )
F_102 ( V_229 -> V_236 ) ;
}
static unsigned int F_204 ( unsigned int V_67 , const T_3 * * V_241 ,
struct V_242 * V_243 ,
struct V_244 * V_245 )
{
return F_202 ( V_67 , V_241 , F_205 ( V_245 ) ) ;
}
static void F_206 ( struct V_242 * V_243 , struct V_244 * V_245 )
{
F_203 ( F_205 ( V_245 ) ) ;
}
unsigned int F_207 ( struct V_1 * V_2 , unsigned int V_199 ,
unsigned int V_170 , struct V_242 * V_246 ,
struct V_244 * V_245 )
{
unsigned int V_198 ;
V_246 -> V_247 = F_204 ;
V_246 -> V_248 = F_206 ;
F_201 ( V_2 , V_199 , V_170 , F_205 ( V_245 ) ) ;
V_198 = F_208 ( V_246 , V_245 ) ;
return ( V_198 <= V_170 - V_199 ? V_198 : V_249 ) ;
}
int F_209 ( struct V_179 * V_129 , struct V_1 * V_2 ,
int (* F_210)( void * V_199 , char * V_170 , int V_67 ,
int V_6 , int V_250 , struct V_1 * V_2 ) ,
void * V_199 , int V_70 )
{
int V_251 = F_23 ( V_2 ) -> V_85 ;
int V_173 ;
int V_67 = 0 ;
int V_198 ;
struct V_180 * V_181 = & V_252 -> V_253 ;
do {
if ( V_251 >= V_187 )
return - V_254 ;
if ( ! F_150 ( V_129 , V_181 ) )
return - V_137 ;
V_173 = F_151 ( int , V_70 , V_181 -> V_14 - V_181 -> V_67 ) ;
V_198 = F_210 ( V_199 , F_37 ( V_181 -> V_57 ) + V_181 -> V_67 ,
V_67 , V_173 , 0 , V_2 ) ;
if ( V_198 < 0 )
return - V_175 ;
F_45 ( V_2 , V_251 , V_181 -> V_57 , V_181 -> V_67 ,
V_173 ) ;
V_251 ++ ;
V_181 -> V_67 += V_173 ;
F_154 ( V_181 -> V_57 ) ;
V_2 -> V_27 += V_173 ;
F_211 ( V_173 , & V_129 -> V_255 ) ;
V_2 -> V_6 += V_173 ;
V_2 -> V_77 += V_173 ;
V_67 += V_173 ;
V_70 -= V_173 ;
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
struct V_1 * F_214 ( struct V_1 * V_256 ,
T_9 V_257 )
{
struct V_1 * V_100 = NULL ;
struct V_1 * V_9 = NULL ;
struct V_1 * V_258 = F_23 ( V_256 ) -> V_80 ;
T_5 * V_56 = F_23 ( V_256 ) -> V_78 ;
unsigned int V_259 = F_23 ( V_256 ) -> V_141 ;
unsigned int V_260 = V_256 -> V_8 - F_215 ( V_256 ) ;
struct V_1 * V_261 = V_256 ;
unsigned int V_67 = V_260 ;
unsigned int V_262 = F_216 ( V_256 ) ;
unsigned int V_145 ;
unsigned int V_6 ;
T_10 V_263 ;
bool V_114 ;
int V_264 = ! ! ( V_257 & V_265 ) ;
int V_161 = F_23 ( V_256 ) -> V_85 ;
int V_157 = - V_137 ;
int V_75 = 0 ;
int V_201 ;
int V_266 ;
V_263 = F_217 ( V_256 , & V_266 ) ;
if ( F_32 ( ! V_263 ) )
return F_218 ( - V_267 ) ;
V_114 = ! ! F_219 ( V_257 , V_263 ) ;
F_220 ( V_256 , V_260 ) ;
V_145 = F_93 ( V_256 ) ;
V_201 = F_117 ( V_256 ) ;
do {
struct V_1 * V_268 ;
T_5 * V_269 ;
int V_270 ;
int V_14 ;
V_6 = V_256 -> V_6 - V_67 ;
if ( V_6 > V_259 )
V_6 = V_259 ;
V_270 = F_117 ( V_256 ) - V_67 ;
if ( V_270 < 0 )
V_270 = 0 ;
if ( V_270 > V_6 || ! V_264 )
V_270 = V_6 ;
if ( ! V_270 && V_75 >= V_161 && F_117 ( V_258 ) &&
( F_117 ( V_258 ) == V_6 || V_264 ) ) {
F_121 ( F_117 ( V_258 ) > V_6 ) ;
V_75 = 0 ;
V_161 = F_23 ( V_258 ) -> V_85 ;
V_56 = F_23 ( V_258 ) -> V_78 ;
V_261 = V_258 ;
V_201 += F_117 ( V_258 ) ;
while ( V_201 < V_67 + V_6 ) {
F_121 ( V_75 >= V_161 ) ;
V_14 = F_101 ( V_56 ) ;
if ( V_201 + V_14 > V_67 + V_6 )
break;
V_75 ++ ;
V_201 += V_14 ;
V_56 ++ ;
}
V_268 = F_105 ( V_258 , V_50 ) ;
V_258 = V_258 -> V_101 ;
if ( F_32 ( ! V_268 ) )
goto V_157;
if ( F_32 ( F_141 ( V_268 , V_6 ) ) ) {
F_76 ( V_268 ) ;
goto V_157;
}
V_270 = F_113 ( V_268 ) ;
if ( F_221 ( V_268 , V_260 + V_145 ) ) {
F_76 ( V_268 ) ;
goto V_157;
}
V_268 -> V_27 += F_113 ( V_268 ) - V_270 ;
F_62 ( V_268 ) ;
F_220 ( V_268 , V_260 ) ;
} else {
V_268 = F_14 ( V_270 + V_260 + V_145 ,
V_50 , F_111 ( V_256 ) ,
V_74 ) ;
if ( F_32 ( ! V_268 ) )
goto V_157;
F_43 ( V_268 , V_145 ) ;
F_222 ( V_268 , V_260 ) ;
}
if ( V_100 )
V_9 -> V_101 = V_268 ;
else
V_100 = V_268 ;
V_9 = V_268 ;
F_83 ( V_268 , V_256 ) ;
V_268 -> V_130 = V_256 -> V_130 ;
F_108 ( V_268 , F_93 ( V_268 ) - V_145 ) ;
F_146 ( V_256 , - V_262 ,
V_268 -> V_8 - V_262 ,
V_260 + V_262 ) ;
if ( V_268 -> V_6 == V_6 + V_260 )
goto V_271;
if ( ! V_264 ) {
V_268 -> V_117 = V_272 ;
V_268 -> V_114 = F_168 ( V_256 , V_67 ,
F_114 ( V_268 , V_6 ) ,
V_6 , 0 ) ;
continue;
}
V_269 = F_23 ( V_268 ) -> V_78 ;
F_146 ( V_256 , V_67 ,
F_114 ( V_268 , V_270 ) , V_270 ) ;
F_23 ( V_268 ) -> V_86 = F_23 ( V_256 ) -> V_86 &
V_219 ;
while ( V_201 < V_67 + V_6 ) {
if ( V_75 >= V_161 ) {
F_121 ( F_117 ( V_258 ) ) ;
V_75 = 0 ;
V_161 = F_23 ( V_258 ) -> V_85 ;
V_56 = F_23 ( V_258 ) -> V_78 ;
V_261 = V_258 ;
F_121 ( ! V_161 ) ;
V_258 = V_258 -> V_101 ;
}
if ( F_32 ( F_23 ( V_268 ) -> V_85 >=
V_187 ) ) {
F_223 (
L_3 ,
V_201 , V_259 ) ;
goto V_157;
}
if ( F_32 ( F_106 ( V_261 , V_50 ) ) )
goto V_157;
* V_269 = * V_56 ;
F_199 ( V_269 ) ;
V_14 = F_101 ( V_269 ) ;
if ( V_201 < V_67 ) {
V_269 -> V_138 += V_67 - V_201 ;
F_145 ( V_269 , V_67 - V_201 ) ;
}
F_23 ( V_268 ) -> V_85 ++ ;
if ( V_201 + V_14 <= V_67 + V_6 ) {
V_75 ++ ;
V_56 ++ ;
V_201 += V_14 ;
} else {
F_145 ( V_269 , V_201 + V_14 - ( V_67 + V_6 ) ) ;
goto V_273;
}
V_269 ++ ;
}
V_273:
V_268 -> V_77 = V_6 - V_270 ;
V_268 -> V_6 += V_268 -> V_77 ;
V_268 -> V_27 += V_268 -> V_77 ;
V_271:
if ( ! V_114 ) {
V_268 -> V_114 = F_167 ( V_268 , V_260 ,
V_268 -> V_6 - V_260 , 0 ) ;
V_268 -> V_117 = V_272 ;
}
} while ( ( V_67 += V_6 ) < V_256 -> V_6 );
return V_100 ;
V_157:
F_49 ( V_100 ) ;
return F_218 ( V_157 ) ;
}
int F_224 ( struct V_1 * * V_7 , struct V_1 * V_2 )
{
struct V_32 * V_274 , * V_275 = F_23 ( V_2 ) ;
unsigned int V_67 = F_225 ( V_2 ) ;
unsigned int V_276 = F_117 ( V_2 ) ;
struct V_1 * V_268 , * V_277 , * V_278 = * V_7 ;
unsigned int V_6 = F_226 ( V_2 ) ;
unsigned int V_279 ;
unsigned int V_145 ;
if ( F_32 ( V_278 -> V_6 + V_6 >= 65536 ) )
return - V_280 ;
V_277 = F_227 ( V_278 ) -> V_281 ? : V_278 ;
V_274 = F_23 ( V_277 ) ;
if ( V_276 <= V_67 ) {
T_5 * V_56 ;
T_5 * V_282 ;
int V_75 = V_275 -> V_85 ;
int V_85 = V_274 -> V_85 + V_75 ;
if ( V_85 > V_187 )
goto V_222;
V_67 -= V_276 ;
V_274 -> V_85 = V_85 ;
V_275 -> V_85 = 0 ;
V_56 = V_274 -> V_78 + V_85 ;
V_282 = V_275 -> V_78 + V_75 ;
do {
* -- V_56 = * -- V_282 ;
} while ( -- V_75 );
V_56 -> V_138 += V_67 ;
F_145 ( V_56 , V_67 ) ;
V_279 = V_2 -> V_27 -
F_21 ( F_113 ( V_2 ) ) ;
V_2 -> V_27 -= V_2 -> V_77 ;
V_2 -> V_6 -= V_2 -> V_77 ;
V_2 -> V_77 = 0 ;
F_227 ( V_2 ) -> free = V_283 ;
goto V_163;
} else if ( V_2 -> V_51 ) {
int V_85 = V_274 -> V_85 ;
T_5 * V_56 = V_274 -> V_78 + V_85 ;
struct V_57 * V_57 = F_42 ( V_2 -> V_7 ) ;
unsigned int V_284 = V_276 - V_67 ;
unsigned int V_285 ;
if ( V_85 + 1 + V_275 -> V_85 > V_187 )
goto V_222;
V_285 = V_2 -> V_8 -
( unsigned char * ) F_37 ( V_57 ) +
V_67 ;
V_274 -> V_85 = V_85 + 1 + V_275 -> V_85 ;
V_56 -> V_57 . V_278 = V_57 ;
V_56 -> V_138 = V_285 ;
F_140 ( V_56 , V_284 ) ;
memcpy ( V_56 + 1 , V_275 -> V_78 , sizeof( * V_56 ) * V_275 -> V_85 ) ;
V_279 = V_2 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
F_227 ( V_2 ) -> free = V_286 ;
goto V_163;
}
if ( V_274 -> V_80 )
goto V_222;
if ( F_226 ( V_278 ) != V_274 -> V_141 )
return - V_280 ;
V_145 = F_93 ( V_278 ) ;
V_268 = F_228 ( V_145 + F_225 ( V_278 ) , V_50 ) ;
if ( F_32 ( ! V_268 ) )
return - V_137 ;
F_83 ( V_268 , V_278 ) ;
V_268 -> V_130 = V_278 -> V_130 ;
F_43 ( V_268 , V_145 ) ;
F_222 ( V_268 , F_225 ( V_278 ) ) ;
F_229 ( V_268 , F_215 ( V_278 ) - V_278 -> V_8 ) ;
F_230 ( V_268 , F_231 ( V_278 ) ) ;
F_232 ( V_268 , F_233 ( V_278 ) ) ;
F_234 ( V_278 , F_225 ( V_278 ) ) ;
memcpy ( F_215 ( V_268 ) , F_215 ( V_278 ) ,
V_278 -> V_8 - F_215 ( V_278 ) ) ;
F_23 ( V_268 ) -> V_80 = V_278 ;
F_23 ( V_268 ) -> V_141 = V_274 -> V_141 ;
V_274 -> V_141 = 0 ;
F_235 ( V_278 ) ;
F_227 ( V_268 ) -> V_281 = V_278 ;
V_268 -> V_77 += V_278 -> V_6 ;
V_268 -> V_27 += V_278 -> V_27 ;
V_268 -> V_6 += V_278 -> V_6 ;
* V_7 = V_268 ;
V_268 -> V_101 = V_278 -> V_101 ;
V_278 -> V_101 = NULL ;
V_278 = V_268 ;
V_222:
V_279 = V_2 -> V_27 ;
if ( V_67 > V_276 ) {
unsigned int V_166 = V_67 - V_276 ;
V_275 -> V_78 [ 0 ] . V_138 += V_166 ;
F_145 ( & V_275 -> V_78 [ 0 ] , V_166 ) ;
V_2 -> V_77 -= V_166 ;
V_2 -> V_6 -= V_166 ;
V_67 = V_276 ;
}
F_234 ( V_2 , V_67 ) ;
if ( ! F_227 ( V_278 ) -> V_281 )
F_23 ( V_278 ) -> V_80 = V_2 ;
else
F_227 ( V_278 ) -> V_281 -> V_101 = V_2 ;
F_227 ( V_278 ) -> V_281 = V_2 ;
F_235 ( V_2 ) ;
V_277 = V_278 ;
V_163:
F_227 ( V_278 ) -> V_287 ++ ;
V_278 -> V_77 += V_6 ;
V_278 -> V_27 += V_279 ;
V_278 -> V_6 += V_6 ;
if ( V_277 != V_278 ) {
V_277 -> V_77 += V_6 ;
V_277 -> V_27 += V_279 ;
V_277 -> V_6 += V_6 ;
}
F_227 ( V_2 ) -> V_288 = 1 ;
return 0 ;
}
void T_11 F_236 ( void )
{
V_25 = F_237 ( L_4 ,
sizeof( struct V_1 ) ,
0 ,
V_289 | V_290 ,
NULL ) ;
V_35 = F_237 ( L_5 ,
( 2 * sizeof( struct V_1 ) ) +
sizeof( T_4 ) ,
0 ,
V_289 | V_290 ,
NULL ) ;
}
static int
F_238 ( struct V_1 * V_2 , struct V_291 * V_264 , int V_67 , int V_6 )
{
int V_171 = F_117 ( V_2 ) ;
int V_75 , V_173 = V_171 - V_67 ;
struct V_1 * V_172 ;
int V_292 = 0 ;
if ( V_173 > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
F_239 ( V_264 , V_2 -> V_8 + V_67 , V_173 ) ;
V_292 ++ ;
if ( ( V_6 -= V_173 ) == 0 )
return V_292 ;
V_67 += V_173 ;
}
for ( V_75 = 0 ; V_75 < F_23 ( V_2 ) -> V_85 ; V_75 ++ ) {
int V_10 ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + F_101 ( & F_23 ( V_2 ) -> V_78 [ V_75 ] ) ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
T_5 * V_56 = & F_23 ( V_2 ) -> V_78 [ V_75 ] ;
if ( V_173 > V_6 )
V_173 = V_6 ;
F_240 ( & V_264 [ V_292 ] , F_100 ( V_56 ) , V_173 ,
V_56 -> V_138 + V_67 - V_171 ) ;
V_292 ++ ;
if ( ! ( V_6 -= V_173 ) )
return V_292 ;
V_67 += V_173 ;
}
V_171 = V_10 ;
}
F_52 (skb, frag_iter) {
int V_10 ;
F_66 ( V_171 > V_67 + V_6 ) ;
V_10 = V_171 + V_172 -> V_6 ;
if ( ( V_173 = V_10 - V_67 ) > 0 ) {
if ( V_173 > V_6 )
V_173 = V_6 ;
V_292 += F_238 ( V_172 , V_264 + V_292 , V_67 - V_171 ,
V_173 ) ;
if ( ( V_6 -= V_173 ) == 0 )
return V_292 ;
V_67 += V_173 ;
}
V_171 = V_10 ;
}
F_121 ( V_6 ) ;
return V_292 ;
}
int F_241 ( struct V_1 * V_2 , struct V_291 * V_264 , int V_67 , int V_6 )
{
int V_293 = F_238 ( V_2 , V_264 , V_67 , V_6 ) ;
F_242 ( & V_264 [ V_293 - 1 ] ) ;
return V_293 ;
}
int F_243 ( struct V_1 * V_2 , int V_294 , struct V_1 * * V_295 )
{
int V_296 ;
int V_292 ;
struct V_1 * V_218 , * * V_297 ;
if ( ( F_124 ( V_2 ) || F_23 ( V_2 ) -> V_85 ) &&
F_143 ( V_2 , F_244 ( V_2 ) - F_117 ( V_2 ) ) == NULL )
return - V_137 ;
if ( ! F_59 ( V_2 ) ) {
if ( F_130 ( V_2 ) < V_294 &&
F_120 ( V_2 , 0 , V_294 - F_130 ( V_2 ) + 128 , V_50 ) )
return - V_137 ;
* V_295 = V_2 ;
return 1 ;
}
V_292 = 1 ;
V_297 = & F_23 ( V_2 ) -> V_80 ;
V_296 = 0 ;
while ( ( V_218 = * V_297 ) != NULL ) {
int V_147 = 0 ;
if ( F_122 ( V_218 ) )
V_296 = 1 ;
if ( V_218 -> V_101 == NULL && V_294 ) {
if ( F_23 ( V_218 ) -> V_85 ||
F_59 ( V_218 ) ||
F_130 ( V_218 ) < V_294 )
V_147 = V_294 + 128 ;
}
if ( V_296 ||
F_124 ( V_218 ) ||
V_147 ||
F_23 ( V_218 ) -> V_85 ||
F_59 ( V_218 ) ) {
struct V_1 * V_149 ;
if ( V_147 == 0 )
V_149 = F_112 ( V_218 , V_50 ) ;
else
V_149 = F_128 ( V_218 ,
F_93 ( V_218 ) ,
V_147 ,
V_50 ) ;
if ( F_32 ( V_149 == NULL ) )
return - V_137 ;
if ( V_218 -> V_129 )
F_245 ( V_149 , V_218 -> V_129 ) ;
V_149 -> V_101 = V_218 -> V_101 ;
* V_297 = V_149 ;
F_76 ( V_218 ) ;
V_218 = V_149 ;
}
V_292 ++ ;
* V_295 = V_218 ;
V_297 = & V_218 -> V_101 ;
}
return V_292 ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_179 * V_129 = V_2 -> V_129 ;
F_247 ( V_2 -> V_27 , & V_129 -> V_298 ) ;
}
int F_248 ( struct V_179 * V_129 , struct V_1 * V_2 )
{
int V_6 = V_2 -> V_6 ;
if ( F_35 ( & V_129 -> V_298 ) + V_2 -> V_27 >=
( unsigned int ) V_129 -> V_299 )
return - V_137 ;
F_249 ( V_2 ) ;
V_2 -> V_129 = V_129 ;
V_2 -> V_94 = F_246 ;
F_211 ( V_2 -> V_27 , & V_129 -> V_298 ) ;
F_250 ( V_2 ) ;
F_185 ( & V_129 -> V_300 , V_2 ) ;
if ( ! F_251 ( V_129 , V_301 ) )
V_129 -> V_302 ( V_129 , V_6 ) ;
return 0 ;
}
void F_252 ( struct V_1 * V_303 ,
struct V_304 * V_305 )
{
struct V_179 * V_129 = V_303 -> V_129 ;
struct V_306 * V_307 ;
struct V_1 * V_2 ;
int V_157 ;
if ( ! V_129 )
return;
if ( V_305 ) {
* F_253 ( V_303 ) =
* V_305 ;
} else {
V_303 -> V_104 = F_254 () ;
}
V_2 = F_105 ( V_303 , V_50 ) ;
if ( ! V_2 )
return;
V_307 = F_255 ( V_2 ) ;
memset ( V_307 , 0 , sizeof( * V_307 ) ) ;
V_307 -> V_308 . V_309 = V_310 ;
V_307 -> V_308 . V_311 = V_312 ;
V_157 = F_248 ( V_129 , V_2 ) ;
if ( V_157 )
F_76 ( V_2 ) ;
}
void F_256 ( struct V_1 * V_2 , bool V_313 )
{
struct V_179 * V_129 = V_2 -> V_129 ;
struct V_306 * V_307 ;
int V_157 ;
V_2 -> V_314 = 1 ;
V_2 -> V_315 = V_313 ;
V_307 = F_255 ( V_2 ) ;
memset ( V_307 , 0 , sizeof( * V_307 ) ) ;
V_307 -> V_308 . V_309 = V_310 ;
V_307 -> V_308 . V_311 = V_316 ;
V_157 = F_248 ( V_129 , V_2 ) ;
if ( V_157 )
F_76 ( V_2 ) ;
}
bool F_257 ( struct V_1 * V_2 , T_12 V_171 , T_12 V_76 )
{
if ( F_32 ( V_171 > F_117 ( V_2 ) ) ||
F_32 ( ( int ) V_171 + V_76 > F_117 ( V_2 ) - 2 ) ) {
F_223 ( L_6 ,
V_171 , V_76 , F_117 ( V_2 ) ) ;
return false ;
}
V_2 -> V_117 = V_139 ;
V_2 -> V_140 = F_93 ( V_2 ) + V_171 ;
V_2 -> V_212 = V_76 ;
F_232 ( V_2 , V_171 ) ;
return true ;
}
static int F_258 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_317 )
{
if ( F_117 ( V_2 ) >= V_6 )
return 0 ;
if ( V_317 > V_2 -> V_6 )
V_317 = V_2 -> V_6 ;
if ( F_143 ( V_2 , V_317 - F_117 ( V_2 ) ) == NULL )
return - V_137 ;
if ( F_117 ( V_2 ) < V_6 )
return - V_318 ;
return 0 ;
}
static int F_259 ( struct V_1 * V_2 , bool V_319 )
{
unsigned int V_76 ;
bool V_320 ;
int V_157 ;
V_320 = false ;
V_157 = F_258 ( V_2 ,
sizeof( struct V_321 ) ,
V_322 ) ;
if ( V_157 < 0 )
goto V_23;
if ( F_260 ( V_2 ) -> V_323 & F_261 ( V_324 | V_325 ) )
V_320 = true ;
V_76 = F_262 ( V_2 ) ;
V_157 = - V_318 ;
if ( V_320 )
goto V_23;
switch ( F_260 ( V_2 ) -> V_121 ) {
case V_326 :
V_157 = F_258 ( V_2 ,
V_76 + sizeof( struct V_327 ) ,
V_322 ) ;
if ( V_157 < 0 )
goto V_23;
if ( ! F_257 ( V_2 , V_76 ,
F_11 ( struct V_327 , V_328 ) ) ) {
V_157 = - V_318 ;
goto V_23;
}
if ( V_319 )
F_263 ( V_2 ) -> V_328 =
~ F_264 ( F_260 ( V_2 ) -> V_329 ,
F_260 ( V_2 ) -> V_330 ,
V_2 -> V_6 - V_76 ,
V_326 , 0 ) ;
break;
case V_331 :
V_157 = F_258 ( V_2 ,
V_76 + sizeof( struct V_332 ) ,
V_322 ) ;
if ( V_157 < 0 )
goto V_23;
if ( ! F_257 ( V_2 , V_76 ,
F_11 ( struct V_332 , V_328 ) ) ) {
V_157 = - V_318 ;
goto V_23;
}
if ( V_319 )
F_265 ( V_2 ) -> V_328 =
~ F_264 ( F_260 ( V_2 ) -> V_329 ,
F_260 ( V_2 ) -> V_330 ,
V_2 -> V_6 - V_76 ,
V_331 , 0 ) ;
break;
default:
goto V_23;
}
V_157 = 0 ;
V_23:
return V_157 ;
}
static int F_266 ( struct V_1 * V_2 , bool V_319 )
{
int V_157 ;
T_3 V_333 ;
unsigned int V_76 ;
unsigned int V_6 ;
bool V_320 ;
bool V_163 ;
V_320 = false ;
V_163 = false ;
V_76 = sizeof( struct V_334 ) ;
V_157 = F_258 ( V_2 , V_76 , V_335 ) ;
if ( V_157 < 0 )
goto V_23;
V_333 = F_267 ( V_2 ) -> V_333 ;
V_6 = sizeof( struct V_334 ) + F_268 ( F_267 ( V_2 ) -> V_336 ) ;
while ( V_76 <= V_6 && ! V_163 ) {
switch ( V_333 ) {
case V_337 :
case V_338 :
case V_339 : {
struct V_340 * V_341 ;
V_157 = F_258 ( V_2 ,
V_76 +
sizeof( struct V_340 ) ,
V_335 ) ;
if ( V_157 < 0 )
goto V_23;
V_341 = F_269 ( struct V_340 , V_2 , V_76 ) ;
V_333 = V_341 -> V_333 ;
V_76 += F_270 ( V_341 ) ;
break;
}
case V_342 : {
struct V_343 * V_341 ;
V_157 = F_258 ( V_2 ,
V_76 +
sizeof( struct V_343 ) ,
V_335 ) ;
if ( V_157 < 0 )
goto V_23;
V_341 = F_269 ( struct V_343 , V_2 , V_76 ) ;
V_333 = V_341 -> V_333 ;
V_76 += F_271 ( V_341 ) ;
break;
}
case V_344 : {
struct V_345 * V_341 ;
V_157 = F_258 ( V_2 ,
V_76 +
sizeof( struct V_345 ) ,
V_335 ) ;
if ( V_157 < 0 )
goto V_23;
V_341 = F_269 ( struct V_345 , V_2 , V_76 ) ;
if ( V_341 -> V_323 & F_261 ( V_346 | V_347 ) )
V_320 = true ;
V_333 = V_341 -> V_333 ;
V_76 += sizeof( struct V_345 ) ;
break;
}
default:
V_163 = true ;
break;
}
}
V_157 = - V_318 ;
if ( ! V_163 || V_320 )
goto V_23;
switch ( V_333 ) {
case V_326 :
V_157 = F_258 ( V_2 ,
V_76 + sizeof( struct V_327 ) ,
V_335 ) ;
if ( V_157 < 0 )
goto V_23;
if ( ! F_257 ( V_2 , V_76 ,
F_11 ( struct V_327 , V_328 ) ) ) {
V_157 = - V_318 ;
goto V_23;
}
if ( V_319 )
F_263 ( V_2 ) -> V_328 =
~ F_272 ( & F_267 ( V_2 ) -> V_329 ,
& F_267 ( V_2 ) -> V_330 ,
V_2 -> V_6 - V_76 ,
V_326 , 0 ) ;
break;
case V_331 :
V_157 = F_258 ( V_2 ,
V_76 + sizeof( struct V_332 ) ,
V_335 ) ;
if ( V_157 < 0 )
goto V_23;
if ( ! F_257 ( V_2 , V_76 ,
F_11 ( struct V_332 , V_328 ) ) ) {
V_157 = - V_318 ;
goto V_23;
}
if ( V_319 )
F_265 ( V_2 ) -> V_328 =
~ F_272 ( & F_267 ( V_2 ) -> V_329 ,
& F_267 ( V_2 ) -> V_330 ,
V_2 -> V_6 - V_76 ,
V_331 , 0 ) ;
break;
default:
goto V_23;
}
V_157 = 0 ;
V_23:
return V_157 ;
}
int F_273 ( struct V_1 * V_2 , bool V_319 )
{
int V_157 ;
switch ( V_2 -> V_121 ) {
case F_261 ( V_348 ) :
V_157 = F_259 ( V_2 , V_319 ) ;
break;
case F_261 ( V_349 ) :
V_157 = F_266 ( V_2 , V_319 ) ;
break;
default:
V_157 = - V_318 ;
break;
}
return V_157 ;
}
void F_274 ( const struct V_1 * V_2 )
{
F_223 ( L_7 ,
V_2 -> V_11 -> V_12 ) ;
}
void F_275 ( struct V_1 * V_2 , bool V_350 )
{
if ( V_350 ) {
F_62 ( V_2 ) ;
F_26 ( V_25 , V_2 ) ;
} else {
F_75 ( V_2 ) ;
}
}
bool F_276 ( struct V_1 * V_170 , struct V_1 * V_199 ,
bool * V_351 , int * V_279 )
{
int V_75 , V_150 , V_6 = V_199 -> V_6 ;
* V_351 = false ;
if ( F_124 ( V_170 ) )
return false ;
if ( V_6 <= F_130 ( V_170 ) ) {
F_121 ( F_115 ( V_199 , 0 , F_114 ( V_170 , V_6 ) , V_6 ) ) ;
* V_279 = 0 ;
return true ;
}
if ( F_59 ( V_170 ) || F_59 ( V_199 ) )
return false ;
if ( F_117 ( V_199 ) != 0 ) {
struct V_57 * V_57 ;
unsigned int V_67 ;
if ( F_23 ( V_170 ) -> V_85 +
F_23 ( V_199 ) -> V_85 >= V_187 )
return false ;
if ( F_159 ( V_199 ) )
return false ;
V_150 = V_199 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
V_57 = F_42 ( V_199 -> V_7 ) ;
V_67 = V_199 -> V_8 - ( unsigned char * ) F_37 ( V_57 ) ;
F_45 ( V_170 , F_23 ( V_170 ) -> V_85 ,
V_57 , V_67 , F_117 ( V_199 ) ) ;
* V_351 = true ;
} else {
if ( F_23 ( V_170 ) -> V_85 +
F_23 ( V_199 ) -> V_85 > V_187 )
return false ;
V_150 = V_199 -> V_27 - F_21 ( F_113 ( V_199 ) ) ;
}
F_277 ( V_150 < V_6 ) ;
memcpy ( F_23 ( V_170 ) -> V_78 + F_23 ( V_170 ) -> V_85 ,
F_23 ( V_199 ) -> V_78 ,
F_23 ( V_199 ) -> V_85 * sizeof( T_5 ) ) ;
F_23 ( V_170 ) -> V_85 += F_23 ( V_199 ) -> V_85 ;
if ( ! F_124 ( V_199 ) )
F_23 ( V_199 ) -> V_85 = 0 ;
for ( V_75 = 0 ; V_75 < F_23 ( V_199 ) -> V_85 ; V_75 ++ )
F_119 ( V_199 , V_75 ) ;
V_170 -> V_27 += V_150 ;
V_170 -> V_6 += V_6 ;
V_170 -> V_77 += V_6 ;
* V_279 = V_150 ;
return true ;
}
void F_278 ( struct V_1 * V_2 , bool V_352 )
{
if ( V_352 )
F_249 ( V_2 ) ;
V_2 -> V_104 . V_353 = 0 ;
V_2 -> V_116 = V_354 ;
V_2 -> V_123 = 0 ;
V_2 -> V_115 = 0 ;
F_63 ( V_2 ) ;
V_2 -> V_122 = 0 ;
F_279 ( V_2 ) ;
F_280 ( V_2 ) ;
F_281 ( V_2 ) ;
}
unsigned int F_282 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_23 ( V_2 ) ;
unsigned int V_131 ;
if ( F_34 ( V_33 -> V_143 & ( V_355 | V_356 ) ) )
V_131 = F_283 ( V_2 ) ;
else
V_131 = sizeof( struct V_332 ) ;
return V_131 + V_33 -> V_141 ;
}
