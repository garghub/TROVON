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
struct V_42 * V_43 ;
V_43 = F_25 ( V_2 , struct V_42 , V_44 ) ;
F_26 ( & V_43 -> V_45 , V_46 ) ;
V_2 -> V_47 = V_48 ;
F_12 ( & V_43 -> V_49 , 1 ) ;
V_43 -> V_45 . V_47 = V_50 ;
V_43 -> V_45 . V_18 = V_18 ;
}
V_23:
return V_2 ;
V_38:
F_27 ( V_31 , V_2 ) ;
V_2 = NULL ;
goto V_23;
}
struct V_1 * F_28 ( void * V_8 , unsigned int V_51 )
{
struct V_32 * V_33 ;
struct V_1 * V_2 ;
unsigned int V_14 = V_51 ? : F_20 ( V_8 ) ;
V_2 = F_29 ( V_25 , V_52 ) ;
if ( ! V_2 )
return NULL ;
V_14 -= F_17 ( sizeof( struct V_32 ) ) ;
memset ( V_2 , 0 , F_11 ( struct V_1 , V_9 ) ) ;
V_2 -> V_27 = F_21 ( V_14 ) ;
V_2 -> V_53 = V_51 != 0 ;
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
static struct V_54 * F_30 ( struct V_55 * V_56 ,
T_2 V_24 )
{
const unsigned int V_57 = V_58 ;
struct V_54 * V_54 = NULL ;
T_2 V_59 = V_24 ;
if ( V_57 ) {
V_24 |= V_60 | V_22 | V_61 ;
V_54 = F_31 ( V_62 , V_24 , V_57 ) ;
V_56 -> V_63 . V_14 = V_64 << ( V_54 ? V_57 : 0 ) ;
}
if ( F_32 ( ! V_54 ) )
V_54 = F_31 ( V_62 , V_59 , 0 ) ;
V_56 -> V_63 . V_54 = V_54 ;
return V_54 ;
}
static void * F_33 ( struct V_55 T_4 * V_31 ,
unsigned int V_65 , T_2 V_24 )
{
struct V_55 * V_56 = F_34 ( V_31 ) ;
struct V_54 * V_54 = V_56 -> V_63 . V_54 ;
unsigned int V_14 ;
int V_66 ;
if ( F_32 ( ! V_54 ) ) {
V_67:
V_54 = F_30 ( V_56 , V_24 ) ;
if ( ! V_54 )
return NULL ;
V_14 = V_58 ? V_56 -> V_63 . V_14 : V_64 ;
F_35 ( V_14 - 1 , & V_54 -> V_68 ) ;
V_56 -> V_69 = V_14 ;
V_56 -> V_63 . V_66 = V_14 ;
}
V_66 = V_56 -> V_63 . V_66 - V_65 ;
if ( F_32 ( V_66 < 0 ) ) {
if ( ! F_36 ( V_56 -> V_69 , & V_54 -> V_68 ) )
goto V_67;
V_14 = V_58 ? V_56 -> V_63 . V_14 : V_64 ;
F_12 ( & V_54 -> V_68 , V_14 ) ;
V_56 -> V_69 = V_14 ;
V_66 = V_14 - V_65 ;
}
V_56 -> V_69 -- ;
V_56 -> V_63 . V_66 = V_66 ;
return F_37 ( V_54 ) + V_66 ;
}
static void * F_38 ( unsigned int V_65 , T_2 V_24 )
{
unsigned long V_15 ;
void * V_8 ;
F_39 ( V_15 ) ;
V_8 = F_33 ( & V_55 , V_65 , V_24 ) ;
F_40 ( V_15 ) ;
return V_8 ;
}
void * F_41 ( unsigned int V_65 )
{
return F_38 ( V_65 , V_52 | V_70 ) ;
}
static void * F_42 ( unsigned int V_65 , T_2 V_24 )
{
return F_33 ( & V_71 , V_65 , V_24 ) ;
}
void * F_43 ( unsigned int V_65 )
{
return F_42 ( V_65 , V_52 | V_70 ) ;
}
static struct V_1 * F_44 ( unsigned int V_72 , T_2 V_24 ,
int V_15 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_65 = F_17 ( V_72 ) +
F_17 ( sizeof( struct V_32 ) ) ;
if ( V_65 <= V_64 && ! ( V_24 & ( V_73 | V_74 ) ) ) {
void * V_8 ;
if ( F_15 () )
V_24 |= V_37 ;
V_8 = ( V_15 & V_75 ) ?
F_42 ( V_65 , V_24 ) :
F_38 ( V_65 , V_24 ) ;
if ( F_45 ( V_8 ) ) {
V_2 = F_28 ( V_8 , V_65 ) ;
if ( F_32 ( ! V_2 ) )
F_46 ( F_47 ( V_8 ) ) ;
}
} else {
V_2 = F_14 ( V_72 , V_24 ,
V_36 , V_62 ) ;
}
return V_2 ;
}
struct V_1 * F_48 ( struct V_76 * V_11 ,
unsigned int V_72 , T_2 V_24 )
{
struct V_1 * V_2 ;
V_72 += V_77 ;
V_2 = F_44 ( V_72 , V_24 , 0 ) ;
if ( F_45 ( V_2 ) ) {
F_49 ( V_2 , V_77 ) ;
V_2 -> V_11 = V_11 ;
}
return V_2 ;
}
struct V_1 * F_50 ( struct V_78 * V_79 ,
unsigned int V_72 , T_2 V_24 )
{
struct V_1 * V_2 ;
V_72 += V_77 + V_80 ;
V_2 = F_44 ( V_72 , V_24 , V_75 ) ;
if ( F_45 ( V_2 ) ) {
F_49 ( V_2 , V_77 + V_80 ) ;
V_2 -> V_11 = V_79 -> V_11 ;
}
return V_2 ;
}
void F_51 ( struct V_1 * V_2 , int V_81 , struct V_54 * V_54 , int V_82 ,
int V_14 , unsigned int V_27 )
{
F_52 ( V_2 , V_81 , V_54 , V_82 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_83 += V_14 ;
V_2 -> V_27 += V_27 ;
}
void F_53 ( struct V_1 * V_2 , int V_81 , int V_14 ,
unsigned int V_27 )
{
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_54 ( V_63 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_83 += V_14 ;
V_2 -> V_27 += V_27 ;
}
static void F_55 ( struct V_1 * * V_85 )
{
F_56 ( * V_85 ) ;
* V_85 = NULL ;
}
static inline void F_57 ( struct V_1 * V_2 )
{
F_55 ( & F_23 ( V_2 ) -> V_86 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_1 * V_87 ;
F_59 (skb, list)
F_60 ( V_87 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 )
F_46 ( F_47 ( V_2 -> V_7 ) ) ;
else
F_62 ( V_2 -> V_7 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_23 ( V_2 ) ;
int V_81 ;
if ( V_2 -> V_88 &&
F_64 ( V_2 -> V_89 ? ( 1 << V_90 ) + 1 : 1 ,
& V_33 -> V_40 ) )
return;
for ( V_81 = 0 ; V_81 < V_33 -> V_91 ; V_81 ++ )
F_65 ( & V_33 -> V_84 [ V_81 ] ) ;
if ( V_33 -> V_92 & V_93 ) {
struct V_94 * V_95 ;
V_95 = V_33 -> V_41 ;
if ( V_95 -> V_96 )
V_95 -> V_96 ( V_95 , true ) ;
}
if ( V_33 -> V_86 )
F_56 ( V_33 -> V_86 ) ;
F_61 ( V_2 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
switch ( V_2 -> V_47 ) {
case V_97 :
F_27 ( V_25 , V_2 ) ;
return;
case V_48 :
V_43 = F_25 ( V_2 , struct V_42 , V_44 ) ;
if ( F_67 ( & V_43 -> V_49 ) == 1 )
goto V_98;
break;
default:
V_43 = F_25 ( V_2 , struct V_42 , V_45 ) ;
break;
}
if ( ! F_68 ( & V_43 -> V_49 ) )
return;
V_98:
F_27 ( V_35 , V_43 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_70 ( V_2 ) ;
#ifdef F_71
F_72 ( V_2 -> V_99 ) ;
#endif
if ( V_2 -> V_100 ) {
F_73 ( F_74 () ) ;
V_2 -> V_100 ( V_2 ) ;
}
#if F_75 ( V_101 )
F_76 ( V_2 -> V_102 ) ;
#endif
#if F_75 ( V_103 )
F_77 ( V_2 -> V_104 ) ;
#endif
#ifdef F_78
V_2 -> V_105 = 0 ;
#ifdef F_79
V_2 -> V_106 = 0 ;
#endif
#endif
}
static void F_80 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
if ( F_45 ( V_2 -> V_7 ) )
F_63 ( V_2 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
F_80 ( V_2 ) ;
F_66 ( V_2 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 ) )
return;
if ( F_45 ( F_67 ( & V_2 -> V_28 ) == 1 ) )
F_83 () ;
else if ( F_45 ( ! F_68 ( & V_2 -> V_28 ) ) )
return;
F_84 ( V_2 , F_85 ( 0 ) ) ;
F_81 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_107 )
{
while ( V_107 ) {
struct V_1 * V_108 = V_107 -> V_108 ;
F_82 ( V_107 ) ;
V_107 = V_108 ;
}
}
void F_86 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) -> V_92 & V_93 ) {
struct V_94 * V_95 ;
V_95 = F_23 ( V_2 ) -> V_41 ;
if ( V_95 -> V_96 )
V_95 -> V_96 ( V_95 , false ) ;
F_23 ( V_2 ) -> V_92 &= ~ V_93 ;
}
}
void F_87 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 ) )
return;
if ( F_45 ( F_67 ( & V_2 -> V_28 ) == 1 ) )
F_83 () ;
else if ( F_45 ( ! F_68 ( & V_2 -> V_28 ) ) )
return;
F_88 ( V_2 ) ;
F_81 ( V_2 ) ;
}
static struct V_1 * F_89 ( struct V_1 * V_109 , struct V_1 * V_2 )
{
#define F_90 ( T_6 ) n->x = skb->x
V_109 -> V_108 = V_109 -> V_110 = NULL ;
V_109 -> V_111 = NULL ;
F_91 ( V_109 , V_2 ) ;
F_90 ( V_6 ) ;
F_90 ( V_83 ) ;
F_90 ( V_112 ) ;
V_109 -> V_113 = V_2 -> V_89 ? F_92 ( V_2 ) : V_2 -> V_113 ;
V_109 -> V_88 = 1 ;
V_109 -> V_89 = 0 ;
V_109 -> V_100 = NULL ;
F_90 ( V_9 ) ;
F_90 ( V_10 ) ;
F_90 ( V_7 ) ;
F_90 ( V_53 ) ;
F_90 ( V_8 ) ;
F_90 ( V_27 ) ;
F_12 ( & V_109 -> V_28 , 1 ) ;
F_93 ( & ( F_23 ( V_2 ) -> V_40 ) ) ;
V_2 -> V_88 = 1 ;
return V_109 ;
#undef F_90
}
struct V_1 * F_94 ( struct V_1 * V_114 , struct V_1 * V_115 )
{
F_80 ( V_114 ) ;
return F_89 ( V_114 , V_115 ) ;
}
int F_95 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_81 ;
int V_116 = F_23 ( V_2 ) -> V_91 ;
struct V_54 * V_54 , * V_7 = NULL ;
struct V_94 * V_95 = F_23 ( V_2 ) -> V_41 ;
for ( V_81 = 0 ; V_81 < V_116 ; V_81 ++ ) {
T_3 * V_117 ;
T_5 * V_118 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
V_54 = F_96 ( V_24 ) ;
if ( ! V_54 ) {
while ( V_7 ) {
struct V_54 * V_108 = (struct V_54 * ) F_97 ( V_7 ) ;
F_46 ( V_7 ) ;
V_7 = V_108 ;
}
return - V_119 ;
}
V_117 = F_98 ( F_99 ( V_118 ) ) ;
memcpy ( F_37 ( V_54 ) ,
V_117 + V_118 -> V_120 , F_100 ( V_118 ) ) ;
F_101 ( V_117 ) ;
F_102 ( V_54 , ( unsigned long ) V_7 ) ;
V_7 = V_54 ;
}
for ( V_81 = 0 ; V_81 < V_116 ; V_81 ++ )
F_103 ( V_2 , V_81 ) ;
V_95 -> V_96 ( V_95 , false ) ;
for ( V_81 = V_116 - 1 ; V_81 >= 0 ; V_81 -- ) {
F_104 ( V_2 , V_81 , V_7 , 0 ,
F_23 ( V_2 ) -> V_84 [ V_81 ] . V_14 ) ;
V_7 = (struct V_54 * ) F_97 ( V_7 ) ;
}
F_23 ( V_2 ) -> V_92 &= ~ V_93 ;
return 0 ;
}
struct V_1 * F_105 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_42 * V_43 = F_25 ( V_2 ,
struct V_42 ,
V_44 ) ;
struct V_1 * V_109 ;
if ( F_106 ( V_2 , V_24 ) )
return NULL ;
if ( V_2 -> V_47 == V_48 &&
F_67 ( & V_43 -> V_49 ) == 1 ) {
V_109 = & V_43 -> V_45 ;
F_12 ( & V_43 -> V_49 , 2 ) ;
} else {
if ( F_107 ( V_2 ) )
V_24 |= V_37 ;
V_109 = F_29 ( V_25 , V_24 ) ;
if ( ! V_109 )
return NULL ;
F_26 ( V_109 , V_46 ) ;
V_109 -> V_47 = V_97 ;
}
return F_89 ( V_109 , V_2 ) ;
}
static void F_108 ( struct V_1 * V_2 , int V_82 )
{
if ( V_2 -> V_121 == V_122 )
V_2 -> V_123 += V_82 ;
V_2 -> V_39 += V_82 ;
V_2 -> V_124 += V_82 ;
if ( F_109 ( V_2 ) )
V_2 -> V_29 += V_82 ;
V_2 -> V_125 += V_82 ;
V_2 -> V_126 += V_82 ;
V_2 -> V_127 += V_82 ;
}
static void F_110 ( struct V_1 * V_128 , const struct V_1 * V_129 )
{
F_91 ( V_128 , V_129 ) ;
F_23 ( V_128 ) -> V_130 = F_23 ( V_129 ) -> V_130 ;
F_23 ( V_128 ) -> V_131 = F_23 ( V_129 ) -> V_131 ;
F_23 ( V_128 ) -> V_132 = F_23 ( V_129 ) -> V_132 ;
}
static inline int F_111 ( const struct V_1 * V_2 )
{
if ( F_107 ( V_2 ) )
return V_36 ;
return 0 ;
}
struct V_1 * F_112 ( const struct V_1 * V_2 , T_2 V_24 )
{
int V_133 = F_92 ( V_2 ) ;
unsigned int V_14 = F_113 ( V_2 ) + V_2 -> V_83 ;
struct V_1 * V_109 = F_14 ( V_14 , V_24 ,
F_111 ( V_2 ) , V_62 ) ;
if ( ! V_109 )
return NULL ;
F_49 ( V_109 , V_133 ) ;
F_114 ( V_109 , V_2 -> V_6 ) ;
if ( F_115 ( V_2 , - V_133 , V_109 -> V_7 , V_133 + V_2 -> V_6 ) )
F_3 () ;
F_110 ( V_109 , V_2 ) ;
return V_109 ;
}
struct V_1 * F_116 ( struct V_1 * V_2 , int V_134 ,
T_2 V_24 , bool V_47 )
{
unsigned int V_14 = F_117 ( V_2 ) + V_134 ;
int V_15 = F_111 ( V_2 ) | ( V_47 ? V_34 : 0 ) ;
struct V_1 * V_109 = F_14 ( V_14 , V_24 , V_15 , V_62 ) ;
if ( ! V_109 )
goto V_23;
F_49 ( V_109 , V_134 ) ;
F_114 ( V_109 , F_117 ( V_2 ) ) ;
F_118 ( V_2 , V_109 -> V_8 , V_109 -> V_6 ) ;
V_109 -> V_27 += V_2 -> V_83 ;
V_109 -> V_83 = V_2 -> V_83 ;
V_109 -> V_6 = V_2 -> V_6 ;
if ( F_23 ( V_2 ) -> V_91 ) {
int V_81 ;
if ( F_106 ( V_2 , V_24 ) ) {
F_82 ( V_109 ) ;
V_109 = NULL ;
goto V_23;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
F_23 ( V_109 ) -> V_84 [ V_81 ] = F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_119 ( V_2 , V_81 ) ;
}
F_23 ( V_109 ) -> V_91 = V_81 ;
}
if ( F_120 ( V_2 ) ) {
F_23 ( V_109 ) -> V_86 = F_23 ( V_2 ) -> V_86 ;
F_58 ( V_109 ) ;
}
F_110 ( V_109 , V_2 ) ;
V_23:
return V_109 ;
}
int F_121 ( struct V_1 * V_2 , int V_135 , int V_136 ,
T_2 V_24 )
{
int V_81 ;
T_3 * V_8 ;
int V_14 = V_135 + F_113 ( V_2 ) + V_136 ;
long V_82 ;
F_122 ( V_135 < 0 ) ;
if ( F_123 ( V_2 ) )
F_3 () ;
V_14 = F_17 ( V_14 ) ;
if ( F_107 ( V_2 ) )
V_24 |= V_37 ;
V_8 = F_18 ( V_14 + F_17 ( sizeof( struct V_32 ) ) ,
V_24 , V_62 , NULL ) ;
if ( ! V_8 )
goto V_38;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
memcpy ( V_8 + V_135 , V_2 -> V_7 , F_124 ( V_2 ) - V_2 -> V_7 ) ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) ,
F_11 ( struct V_32 , V_84 [ F_23 ( V_2 ) -> V_91 ] ) ) ;
if ( F_125 ( V_2 ) ) {
if ( F_106 ( V_2 , V_24 ) )
goto V_137;
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ )
F_119 ( V_2 , V_81 ) ;
if ( F_120 ( V_2 ) )
F_58 ( V_2 ) ;
F_63 ( V_2 ) ;
} else {
F_61 ( V_2 ) ;
}
V_82 = ( V_8 + V_135 ) - V_2 -> V_7 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_53 = 0 ;
V_2 -> V_8 += V_82 ;
#ifdef F_126
V_2 -> V_10 = V_14 ;
V_82 = V_135 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
V_2 -> V_9 += V_82 ;
F_108 ( V_2 , V_135 ) ;
V_2 -> V_88 = 0 ;
V_2 -> V_113 = 0 ;
V_2 -> V_89 = 0 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
V_137:
F_62 ( V_8 ) ;
V_38:
return - V_119 ;
}
struct V_1 * F_127 ( struct V_1 * V_2 , unsigned int V_134 )
{
struct V_1 * V_45 ;
int V_138 = V_134 - F_92 ( V_2 ) ;
if ( V_138 <= 0 )
V_45 = F_128 ( V_2 , V_52 ) ;
else {
V_45 = F_105 ( V_2 , V_52 ) ;
if ( V_45 && F_121 ( V_45 , F_17 ( V_138 ) , 0 ,
V_52 ) ) {
F_82 ( V_45 ) ;
V_45 = NULL ;
}
}
return V_45 ;
}
struct V_1 * F_129 ( const struct V_1 * V_2 ,
int V_139 , int V_140 ,
T_2 V_24 )
{
struct V_1 * V_109 = F_14 ( V_139 + V_2 -> V_6 + V_140 ,
V_24 , F_111 ( V_2 ) ,
V_62 ) ;
int V_141 = F_92 ( V_2 ) ;
int V_142 , V_143 ;
if ( ! V_109 )
return NULL ;
F_49 ( V_109 , V_139 ) ;
F_114 ( V_109 , V_2 -> V_6 ) ;
V_142 = V_141 ;
V_143 = 0 ;
if ( V_139 <= V_142 )
V_142 = V_139 ;
else
V_143 = V_139 - V_142 ;
if ( F_115 ( V_2 , - V_142 , V_109 -> V_7 + V_143 ,
V_2 -> V_6 + V_142 ) )
F_3 () ;
F_110 ( V_109 , V_2 ) ;
F_108 ( V_109 , V_139 - V_141 ) ;
return V_109 ;
}
int F_130 ( struct V_1 * V_2 , int V_144 )
{
int V_145 ;
int V_136 ;
if ( ! F_125 ( V_2 ) && F_131 ( V_2 ) >= V_144 ) {
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_144 ) ;
return 0 ;
}
V_136 = V_2 -> V_83 + V_144 - ( V_2 -> V_10 - V_2 -> V_9 ) ;
if ( F_45 ( F_125 ( V_2 ) || V_136 > 0 ) ) {
V_145 = F_121 ( V_2 , 0 , V_136 , V_52 ) ;
if ( F_32 ( V_145 ) )
goto V_146;
}
V_145 = F_132 ( V_2 ) ;
if ( F_32 ( V_145 ) )
goto V_146;
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_144 ) ;
return 0 ;
V_146:
F_82 ( V_2 ) ;
return V_145 ;
}
unsigned char * F_133 ( struct V_1 * V_2 , struct V_1 * V_9 , int V_6 )
{
if ( V_9 != V_2 ) {
V_2 -> V_83 += V_6 ;
V_2 -> V_6 += V_6 ;
}
return F_114 ( V_9 , V_6 ) ;
}
unsigned char * F_114 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned char * V_147 = F_124 ( V_2 ) ;
F_134 ( V_2 ) ;
V_2 -> V_9 += V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_32 ( V_2 -> V_9 > V_2 -> V_10 ) )
F_4 ( V_2 , V_6 , F_85 ( 0 ) ) ;
return V_147 ;
}
unsigned char * F_135 ( struct V_1 * V_2 , unsigned int V_6 )
{
V_2 -> V_8 -= V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_32 ( V_2 -> V_8 < V_2 -> V_7 ) )
F_5 ( V_2 , V_6 , F_85 ( 0 ) ) ;
return V_2 -> V_8 ;
}
unsigned char * F_136 ( struct V_1 * V_2 , unsigned int V_6 )
{
return F_137 ( V_2 , V_6 ) ;
}
void F_138 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_2 -> V_6 > V_6 )
F_139 ( V_2 , V_6 ) ;
}
int F_140 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_1 * * V_148 ;
struct V_1 * V_63 ;
int V_66 = F_117 ( V_2 ) ;
int V_149 = F_23 ( V_2 ) -> V_91 ;
int V_81 ;
int V_145 ;
if ( F_125 ( V_2 ) &&
F_32 ( ( V_145 = F_121 ( V_2 , 0 , 0 , V_52 ) ) ) )
return V_145 ;
V_81 = 0 ;
if ( V_66 >= V_6 )
goto V_150;
for (; V_81 < V_149 ; V_81 ++ ) {
int V_10 = V_66 + F_100 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( V_10 < V_6 ) {
V_66 = V_10 ;
continue;
}
F_141 ( & F_23 ( V_2 ) -> V_84 [ V_81 ++ ] , V_6 - V_66 ) ;
V_150:
F_23 ( V_2 ) -> V_91 = V_81 ;
for (; V_81 < V_149 ; V_81 ++ )
F_103 ( V_2 , V_81 ) ;
if ( F_120 ( V_2 ) )
F_57 ( V_2 ) ;
goto V_151;
}
for ( V_148 = & F_23 ( V_2 ) -> V_86 ; ( V_63 = * V_148 ) ;
V_148 = & V_63 -> V_108 ) {
int V_10 = V_66 + V_63 -> V_6 ;
if ( F_123 ( V_63 ) ) {
struct V_1 * V_152 ;
V_152 = F_105 ( V_63 , V_52 ) ;
if ( F_32 ( ! V_152 ) )
return - V_119 ;
V_152 -> V_108 = V_63 -> V_108 ;
F_87 ( V_63 ) ;
V_63 = V_152 ;
* V_148 = V_63 ;
}
if ( V_10 < V_6 ) {
V_66 = V_10 ;
continue;
}
if ( V_10 > V_6 &&
F_32 ( ( V_145 = F_142 ( V_63 , V_6 - V_66 ) ) ) )
return V_145 ;
if ( V_63 -> V_108 )
F_55 ( & V_63 -> V_108 ) ;
break;
}
V_151:
if ( V_6 > F_117 ( V_2 ) ) {
V_2 -> V_83 -= V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
} else {
V_2 -> V_6 = V_6 ;
V_2 -> V_83 = 0 ;
F_143 ( V_2 , V_6 ) ;
}
return 0 ;
}
unsigned char * F_144 ( struct V_1 * V_2 , int V_138 )
{
int V_81 , V_153 , V_154 = ( V_2 -> V_9 + V_138 ) - V_2 -> V_10 ;
if ( V_154 > 0 || F_125 ( V_2 ) ) {
if ( F_121 ( V_2 , 0 , V_154 > 0 ? V_154 + 128 : 0 ,
V_52 ) )
return NULL ;
}
if ( F_115 ( V_2 , F_117 ( V_2 ) , F_124 ( V_2 ) , V_138 ) )
F_3 () ;
if ( ! F_120 ( V_2 ) )
goto V_155;
V_154 = V_138 ;
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_14 = F_100 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( V_14 >= V_154 )
goto V_155;
V_154 -= V_14 ;
}
if ( V_154 ) {
struct V_1 * V_87 = F_23 ( V_2 ) -> V_86 ;
struct V_1 * V_156 = NULL ;
struct V_1 * V_157 = NULL ;
do {
F_122 ( ! V_87 ) ;
if ( V_87 -> V_6 <= V_154 ) {
V_154 -= V_87 -> V_6 ;
V_87 = V_87 -> V_108 ;
V_157 = V_87 ;
} else {
if ( F_123 ( V_87 ) ) {
V_156 = F_105 ( V_87 , V_52 ) ;
if ( ! V_156 )
return NULL ;
V_157 = V_87 -> V_108 ;
V_87 = V_156 ;
} else {
V_157 = V_87 ;
}
if ( ! F_145 ( V_87 , V_154 ) ) {
F_82 ( V_156 ) ;
return NULL ;
}
break;
}
} while ( V_154 );
while ( ( V_87 = F_23 ( V_2 ) -> V_86 ) != V_157 ) {
F_23 ( V_2 ) -> V_86 = V_87 -> V_108 ;
F_82 ( V_87 ) ;
}
if ( V_156 ) {
V_156 -> V_108 = V_87 ;
F_23 ( V_2 ) -> V_86 = V_156 ;
}
}
V_155:
V_154 = V_138 ;
V_153 = 0 ;
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_14 = F_100 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( V_14 <= V_154 ) {
F_103 ( V_2 , V_81 ) ;
V_154 -= V_14 ;
} else {
F_23 ( V_2 ) -> V_84 [ V_153 ] = F_23 ( V_2 ) -> V_84 [ V_81 ] ;
if ( V_154 ) {
F_23 ( V_2 ) -> V_84 [ V_153 ] . V_120 += V_154 ;
F_146 ( & F_23 ( V_2 ) -> V_84 [ V_153 ] , V_154 ) ;
V_154 = 0 ;
}
V_153 ++ ;
}
}
F_23 ( V_2 ) -> V_91 = V_153 ;
V_2 -> V_9 += V_138 ;
V_2 -> V_83 -= V_138 ;
return F_124 ( V_2 ) ;
}
int F_115 ( const struct V_1 * V_2 , int V_66 , void * V_158 , int V_6 )
{
int V_159 = F_117 ( V_2 ) ;
struct V_1 * V_160 ;
int V_81 , V_161 ;
if ( V_66 > ( int ) V_2 -> V_6 - V_6 )
goto V_162;
if ( ( V_161 = V_159 - V_66 ) > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
F_147 ( V_2 , V_66 , V_158 , V_161 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return 0 ;
V_66 += V_161 ;
V_158 += V_161 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_10 ;
T_5 * V_118 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + F_100 ( V_118 ) ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
T_3 * V_117 ;
if ( V_161 > V_6 )
V_161 = V_6 ;
V_117 = F_98 ( F_99 ( V_118 ) ) ;
memcpy ( V_158 ,
V_117 + V_118 -> V_120 + V_66 - V_159 ,
V_161 ) ;
F_101 ( V_117 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return 0 ;
V_66 += V_161 ;
V_158 += V_161 ;
}
V_159 = V_10 ;
}
F_59 (skb, frag_iter) {
int V_10 ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + V_160 -> V_6 ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
if ( F_115 ( V_160 , V_66 - V_159 , V_158 , V_161 ) )
goto V_162;
if ( ( V_6 -= V_161 ) == 0 )
return 0 ;
V_66 += V_161 ;
V_158 += V_161 ;
}
V_159 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_162:
return - V_163 ;
}
static void F_148 ( struct V_164 * V_165 , unsigned int V_81 )
{
F_46 ( V_165 -> V_166 [ V_81 ] ) ;
}
static struct V_54 * F_149 ( struct V_54 * V_54 , unsigned int * V_6 ,
unsigned int * V_66 ,
struct V_167 * V_111 )
{
struct V_168 * V_169 = F_150 ( V_111 ) ;
if ( ! F_151 ( V_111 , V_169 ) )
return NULL ;
* V_6 = F_152 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_37 ( V_169 -> V_54 ) + V_169 -> V_66 ,
F_37 ( V_54 ) + * V_66 , * V_6 ) ;
* V_66 = V_169 -> V_66 ;
V_169 -> V_66 += * V_6 ;
return V_169 -> V_54 ;
}
static bool F_153 ( const struct V_164 * V_165 ,
struct V_54 * V_54 ,
unsigned int V_66 )
{
return V_165 -> V_170 &&
V_165 -> V_166 [ V_165 -> V_170 - 1 ] == V_54 &&
( V_165 -> V_171 [ V_165 -> V_170 - 1 ] . V_66 +
V_165 -> V_171 [ V_165 -> V_170 - 1 ] . V_6 == V_66 ) ;
}
static bool F_154 ( struct V_164 * V_165 ,
struct V_172 * V_173 , struct V_54 * V_54 ,
unsigned int * V_6 , unsigned int V_66 ,
bool V_174 ,
struct V_167 * V_111 )
{
if ( F_32 ( V_165 -> V_170 == V_175 ) )
return true ;
if ( V_174 ) {
V_54 = F_149 ( V_54 , V_6 , & V_66 , V_111 ) ;
if ( ! V_54 )
return true ;
}
if ( F_153 ( V_165 , V_54 , V_66 ) ) {
V_165 -> V_171 [ V_165 -> V_170 - 1 ] . V_6 += * V_6 ;
return false ;
}
F_155 ( V_54 ) ;
V_165 -> V_166 [ V_165 -> V_170 ] = V_54 ;
V_165 -> V_171 [ V_165 -> V_170 ] . V_6 = * V_6 ;
V_165 -> V_171 [ V_165 -> V_170 ] . V_66 = V_66 ;
V_165 -> V_170 ++ ;
return false ;
}
static bool F_156 ( struct V_54 * V_54 , unsigned int V_176 ,
unsigned int V_177 , unsigned int * V_82 ,
unsigned int * V_6 ,
struct V_164 * V_165 , bool V_174 ,
struct V_167 * V_111 ,
struct V_172 * V_173 )
{
if ( ! * V_6 )
return true ;
if ( * V_82 >= V_177 ) {
* V_82 -= V_177 ;
return false ;
}
V_176 += * V_82 ;
V_177 -= * V_82 ;
* V_82 = 0 ;
do {
unsigned int V_178 = F_157 ( * V_6 , V_177 ) ;
if ( F_154 ( V_165 , V_173 , V_54 , & V_178 , V_176 ,
V_174 , V_111 ) )
return true ;
V_176 += V_178 ;
V_177 -= V_178 ;
* V_6 -= V_178 ;
} while ( * V_6 && V_177 );
return false ;
}
static bool F_158 ( struct V_1 * V_2 , struct V_172 * V_173 ,
unsigned int * V_66 , unsigned int * V_6 ,
struct V_164 * V_165 , struct V_167 * V_111 )
{
int V_179 ;
if ( F_156 ( F_159 ( V_2 -> V_8 ) ,
( unsigned long ) V_2 -> V_8 & ( V_64 - 1 ) ,
F_117 ( V_2 ) ,
V_66 , V_6 , V_165 ,
F_160 ( V_2 ) ,
V_111 , V_173 ) )
return true ;
for ( V_179 = 0 ; V_179 < F_23 ( V_2 ) -> V_91 ; V_179 ++ ) {
const T_5 * V_118 = & F_23 ( V_2 ) -> V_84 [ V_179 ] ;
if ( F_156 ( F_99 ( V_118 ) ,
V_118 -> V_120 , F_100 ( V_118 ) ,
V_66 , V_6 , V_165 , false , V_111 , V_173 ) )
return true ;
}
return false ;
}
int F_161 ( struct V_1 * V_2 , unsigned int V_66 ,
struct V_172 * V_173 , unsigned int V_180 ,
unsigned int V_15 )
{
struct V_181 V_171 [ V_175 ] ;
struct V_54 * V_166 [ V_175 ] ;
struct V_164 V_165 = {
. V_166 = V_166 ,
. V_171 = V_171 ,
. V_182 = V_175 ,
. V_15 = V_15 ,
. V_183 = & V_184 ,
. V_185 = F_148 ,
} ;
struct V_1 * V_160 ;
struct V_167 * V_111 = V_2 -> V_111 ;
int V_186 = 0 ;
if ( F_158 ( V_2 , V_173 , & V_66 , & V_180 , & V_165 , V_111 ) )
goto V_151;
else if ( ! V_180 )
goto V_151;
F_59 (skb, frag_iter) {
if ( ! V_180 )
break;
if ( F_158 ( V_160 , V_173 , & V_66 , & V_180 , & V_165 , V_111 ) )
break;
}
V_151:
if ( V_165 . V_170 ) {
F_162 ( V_111 ) ;
V_186 = F_163 ( V_173 , & V_165 ) ;
F_164 ( V_111 ) ;
}
return V_186 ;
}
int F_165 ( struct V_1 * V_2 , int V_66 , const void * V_187 , int V_6 )
{
int V_159 = F_117 ( V_2 ) ;
struct V_1 * V_160 ;
int V_81 , V_161 ;
if ( V_66 > ( int ) V_2 -> V_6 - V_6 )
goto V_162;
if ( ( V_161 = V_159 - V_66 ) > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
F_166 ( V_2 , V_66 , V_187 , V_161 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return 0 ;
V_66 += V_161 ;
V_187 += V_161 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
int V_10 ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + F_100 ( V_63 ) ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
T_3 * V_117 ;
if ( V_161 > V_6 )
V_161 = V_6 ;
V_117 = F_98 ( F_99 ( V_63 ) ) ;
memcpy ( V_117 + V_63 -> V_120 + V_66 - V_159 ,
V_187 , V_161 ) ;
F_101 ( V_117 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return 0 ;
V_66 += V_161 ;
V_187 += V_161 ;
}
V_159 = V_10 ;
}
F_59 (skb, frag_iter) {
int V_10 ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + V_160 -> V_6 ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
if ( F_165 ( V_160 , V_66 - V_159 ,
V_187 , V_161 ) )
goto V_162;
if ( ( V_6 -= V_161 ) == 0 )
return 0 ;
V_66 += V_161 ;
V_187 += V_161 ;
}
V_159 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_162:
return - V_163 ;
}
T_7 F_167 ( const struct V_1 * V_2 , int V_66 , int V_6 ,
T_7 V_188 , const struct V_189 * V_183 )
{
int V_159 = F_117 ( V_2 ) ;
int V_81 , V_161 = V_159 - V_66 ;
struct V_1 * V_160 ;
int V_190 = 0 ;
if ( V_161 > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
V_188 = V_183 -> V_191 ( V_2 -> V_8 + V_66 , V_161 , V_188 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return V_188 ;
V_66 += V_161 ;
V_190 = V_161 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_10 ;
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + F_100 ( V_63 ) ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
T_7 V_192 ;
T_3 * V_117 ;
if ( V_161 > V_6 )
V_161 = V_6 ;
V_117 = F_98 ( F_99 ( V_63 ) ) ;
V_192 = V_183 -> V_191 ( V_117 + V_63 -> V_120 +
V_66 - V_159 , V_161 , 0 ) ;
F_101 ( V_117 ) ;
V_188 = V_183 -> V_193 ( V_188 , V_192 , V_190 , V_161 ) ;
if ( ! ( V_6 -= V_161 ) )
return V_188 ;
V_66 += V_161 ;
V_190 += V_161 ;
}
V_159 = V_10 ;
}
F_59 (skb, frag_iter) {
int V_10 ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + V_160 -> V_6 ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
T_7 V_192 ;
if ( V_161 > V_6 )
V_161 = V_6 ;
V_192 = F_167 ( V_160 , V_66 - V_159 ,
V_161 , 0 , V_183 ) ;
V_188 = V_183 -> V_193 ( V_188 , V_192 , V_190 , V_161 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return V_188 ;
V_66 += V_161 ;
V_190 += V_161 ;
}
V_159 = V_10 ;
}
F_122 ( V_6 ) ;
return V_188 ;
}
T_7 F_168 ( const struct V_1 * V_2 , int V_66 ,
int V_6 , T_7 V_188 )
{
const struct V_189 V_183 = {
. V_191 = V_194 ,
. V_193 = V_195 ,
} ;
return F_167 ( V_2 , V_66 , V_6 , V_188 , & V_183 ) ;
}
T_7 F_169 ( const struct V_1 * V_2 , int V_66 ,
T_3 * V_158 , int V_6 , T_7 V_188 )
{
int V_159 = F_117 ( V_2 ) ;
int V_81 , V_161 = V_159 - V_66 ;
struct V_1 * V_160 ;
int V_190 = 0 ;
if ( V_161 > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
V_188 = F_170 ( V_2 -> V_8 + V_66 , V_158 ,
V_161 , V_188 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return V_188 ;
V_66 += V_161 ;
V_158 += V_161 ;
V_190 = V_161 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_10 ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + F_100 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
T_7 V_192 ;
T_3 * V_117 ;
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
if ( V_161 > V_6 )
V_161 = V_6 ;
V_117 = F_98 ( F_99 ( V_63 ) ) ;
V_192 = F_170 ( V_117 +
V_63 -> V_120 +
V_66 - V_159 , V_158 ,
V_161 , 0 ) ;
F_101 ( V_117 ) ;
V_188 = F_171 ( V_188 , V_192 , V_190 ) ;
if ( ! ( V_6 -= V_161 ) )
return V_188 ;
V_66 += V_161 ;
V_158 += V_161 ;
V_190 += V_161 ;
}
V_159 = V_10 ;
}
F_59 (skb, frag_iter) {
T_7 V_192 ;
int V_10 ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + V_160 -> V_6 ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
V_192 = F_169 ( V_160 ,
V_66 - V_159 ,
V_158 , V_161 , 0 ) ;
V_188 = F_171 ( V_188 , V_192 , V_190 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return V_188 ;
V_66 += V_161 ;
V_158 += V_161 ;
V_190 += V_161 ;
}
V_159 = V_10 ;
}
F_122 ( V_6 ) ;
return V_188 ;
}
unsigned int
F_172 ( const struct V_1 * V_187 )
{
unsigned int V_196 = 0 ;
if ( ! V_187 -> V_53 ||
F_117 ( V_187 ) < V_197 ||
F_23 ( V_187 ) -> V_91 >= V_175 )
V_196 = F_117 ( V_187 ) ;
if ( F_120 ( V_187 ) )
V_196 = V_187 -> V_6 ;
return V_196 ;
}
int
F_173 ( struct V_1 * V_158 , struct V_1 * V_187 , int V_6 , int V_196 )
{
int V_81 , V_198 = 0 ;
int V_177 = 0 ;
int V_186 ;
struct V_54 * V_54 ;
unsigned int V_66 ;
F_122 ( ! V_187 -> V_53 && ! V_196 ) ;
if ( V_6 <= F_131 ( V_158 ) )
return F_115 ( V_187 , 0 , F_114 ( V_158 , V_6 ) , V_6 ) ;
if ( V_196 ) {
V_186 = F_115 ( V_187 , 0 , F_114 ( V_158 , V_196 ) , V_196 ) ;
if ( F_32 ( V_186 ) )
return V_186 ;
V_6 -= V_196 ;
} else {
V_177 = F_152 ( int , F_117 ( V_187 ) , V_6 ) ;
if ( V_177 ) {
V_54 = F_47 ( V_187 -> V_7 ) ;
V_66 = V_187 -> V_8 - ( unsigned char * ) F_37 ( V_54 ) ;
F_104 ( V_158 , 0 , V_54 , V_66 , V_177 ) ;
F_155 ( V_54 ) ;
V_198 = 1 ;
V_6 -= V_177 ;
}
}
V_158 -> V_27 += V_6 + V_177 ;
V_158 -> V_6 += V_6 + V_177 ;
V_158 -> V_83 += V_6 + V_177 ;
if ( F_32 ( F_106 ( V_187 , V_52 ) ) ) {
F_86 ( V_187 ) ;
return - V_119 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_187 ) -> V_91 ; V_81 ++ ) {
if ( ! V_6 )
break;
F_23 ( V_158 ) -> V_84 [ V_198 ] = F_23 ( V_187 ) -> V_84 [ V_81 ] ;
F_23 ( V_158 ) -> V_84 [ V_198 ] . V_14 = F_152 ( int , F_23 ( V_158 ) -> V_84 [ V_198 ] . V_14 , V_6 ) ;
V_6 -= F_23 ( V_158 ) -> V_84 [ V_198 ] . V_14 ;
F_119 ( V_158 , V_198 ) ;
V_198 ++ ;
}
F_23 ( V_158 ) -> V_91 = V_198 ;
return 0 ;
}
void F_174 ( const struct V_1 * V_2 , T_3 * V_158 )
{
T_7 V_188 ;
long V_199 ;
if ( V_2 -> V_121 == V_122 )
V_199 = F_175 ( V_2 ) ;
else
V_199 = F_117 ( V_2 ) ;
F_122 ( V_199 > F_117 ( V_2 ) ) ;
F_118 ( V_2 , V_158 , V_199 ) ;
V_188 = 0 ;
if ( V_199 != V_2 -> V_6 )
V_188 = F_169 ( V_2 , V_199 , V_158 + V_199 ,
V_2 -> V_6 - V_199 , 0 ) ;
if ( V_2 -> V_121 == V_122 ) {
long V_200 = V_199 + V_2 -> V_201 ;
* ( ( V_202 * ) ( V_158 + V_200 ) ) = F_176 ( V_188 ) ;
}
}
struct V_1 * F_177 ( struct V_203 * V_87 )
{
unsigned long V_15 ;
struct V_1 * V_204 ;
F_178 ( & V_87 -> V_205 , V_15 ) ;
V_204 = F_179 ( V_87 ) ;
F_180 ( & V_87 -> V_205 , V_15 ) ;
return V_204 ;
}
struct V_1 * F_181 ( struct V_203 * V_87 )
{
unsigned long V_15 ;
struct V_1 * V_204 ;
F_178 ( & V_87 -> V_205 , V_15 ) ;
V_204 = F_182 ( V_87 ) ;
F_180 ( & V_87 -> V_205 , V_15 ) ;
return V_204 ;
}
void F_183 ( struct V_203 * V_87 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_177 ( V_87 ) ) != NULL )
F_82 ( V_2 ) ;
}
void F_184 ( struct V_203 * V_87 , struct V_1 * V_206 )
{
unsigned long V_15 ;
F_178 ( & V_87 -> V_205 , V_15 ) ;
F_185 ( V_87 , V_206 ) ;
F_180 ( & V_87 -> V_205 , V_15 ) ;
}
void F_186 ( struct V_203 * V_87 , struct V_1 * V_206 )
{
unsigned long V_15 ;
F_178 ( & V_87 -> V_205 , V_15 ) ;
F_187 ( V_87 , V_206 ) ;
F_180 ( & V_87 -> V_205 , V_15 ) ;
}
void F_188 ( struct V_1 * V_2 , struct V_203 * V_87 )
{
unsigned long V_15 ;
F_178 ( & V_87 -> V_205 , V_15 ) ;
F_189 ( V_2 , V_87 ) ;
F_180 ( & V_87 -> V_205 , V_15 ) ;
}
void F_190 ( struct V_1 * V_129 , struct V_1 * V_206 , struct V_203 * V_87 )
{
unsigned long V_15 ;
F_178 ( & V_87 -> V_205 , V_15 ) ;
F_191 ( V_87 , V_129 , V_206 ) ;
F_180 ( & V_87 -> V_205 , V_15 ) ;
}
void F_192 ( struct V_1 * V_129 , struct V_1 * V_206 , struct V_203 * V_87 )
{
unsigned long V_15 ;
F_178 ( & V_87 -> V_205 , V_15 ) ;
F_193 ( V_206 , V_129 -> V_110 , V_129 , V_87 ) ;
F_180 ( & V_87 -> V_205 , V_15 ) ;
}
static inline void F_194 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_8 V_6 , const int V_190 )
{
int V_81 ;
F_147 ( V_2 , V_6 , F_114 ( V_44 , V_190 - V_6 ) ,
V_190 - V_6 ) ;
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ )
F_23 ( V_44 ) -> V_84 [ V_81 ] = F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_23 ( V_44 ) -> V_91 = F_23 ( V_2 ) -> V_91 ;
F_23 ( V_2 ) -> V_91 = 0 ;
V_44 -> V_83 = V_2 -> V_83 ;
V_44 -> V_6 += V_44 -> V_83 ;
V_2 -> V_83 = 0 ;
V_2 -> V_6 = V_6 ;
F_143 ( V_2 , V_6 ) ;
}
static inline void F_195 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_8 V_6 , int V_190 )
{
int V_81 , V_153 = 0 ;
const int V_149 = F_23 ( V_2 ) -> V_91 ;
F_23 ( V_2 ) -> V_91 = 0 ;
V_44 -> V_6 = V_44 -> V_83 = V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_83 = V_6 - V_190 ;
for ( V_81 = 0 ; V_81 < V_149 ; V_81 ++ ) {
int V_14 = F_100 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( V_190 + V_14 > V_6 ) {
F_23 ( V_44 ) -> V_84 [ V_153 ] = F_23 ( V_2 ) -> V_84 [ V_81 ] ;
if ( V_190 < V_6 ) {
F_119 ( V_2 , V_81 ) ;
F_23 ( V_44 ) -> V_84 [ 0 ] . V_120 += V_6 - V_190 ;
F_146 ( & F_23 ( V_44 ) -> V_84 [ 0 ] , V_6 - V_190 ) ;
F_141 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] , V_6 - V_190 ) ;
F_23 ( V_2 ) -> V_91 ++ ;
}
V_153 ++ ;
} else
F_23 ( V_2 ) -> V_91 ++ ;
V_190 += V_14 ;
}
F_23 ( V_44 ) -> V_91 = V_153 ;
}
void F_196 ( struct V_1 * V_2 , struct V_1 * V_44 , const T_8 V_6 )
{
int V_190 = F_117 ( V_2 ) ;
F_23 ( V_44 ) -> V_92 = F_23 ( V_2 ) -> V_92 & V_207 ;
if ( V_6 < V_190 )
F_194 ( V_2 , V_44 , V_6 , V_190 ) ;
else
F_195 ( V_2 , V_44 , V_6 , V_190 ) ;
}
static int F_197 ( struct V_1 * V_2 )
{
return F_125 ( V_2 ) && F_121 ( V_2 , 0 , 0 , V_52 ) ;
}
int F_198 ( struct V_1 * V_208 , struct V_1 * V_2 , int V_209 )
{
int V_187 , V_158 , V_210 , V_211 ;
struct V_212 * V_213 , * V_214 ;
F_122 ( V_209 > V_2 -> V_6 ) ;
F_122 ( F_117 ( V_2 ) ) ;
V_211 = V_209 ;
V_187 = 0 ;
V_158 = F_23 ( V_208 ) -> V_91 ;
V_213 = & F_23 ( V_2 ) -> V_84 [ V_187 ] ;
if ( ! V_158 ||
! F_199 ( V_208 , V_158 , F_99 ( V_213 ) ,
V_213 -> V_120 ) ) {
V_210 = - 1 ;
} else {
V_210 = V_158 - 1 ;
V_211 -= F_100 ( V_213 ) ;
if ( V_211 < 0 ) {
if ( F_197 ( V_2 ) ||
F_197 ( V_208 ) )
return 0 ;
V_213 = & F_23 ( V_2 ) -> V_84 [ V_187 ] ;
V_214 = & F_23 ( V_208 ) -> V_84 [ V_210 ] ;
F_54 ( V_214 , V_209 ) ;
F_146 ( V_213 , V_209 ) ;
V_213 -> V_120 += V_209 ;
goto V_215;
}
V_187 ++ ;
}
if ( ( V_209 == V_2 -> V_6 ) &&
( F_23 ( V_2 ) -> V_91 - V_187 ) > ( V_175 - V_158 ) )
return 0 ;
if ( F_197 ( V_2 ) || F_197 ( V_208 ) )
return 0 ;
while ( ( V_211 > 0 ) && ( V_187 < F_23 ( V_2 ) -> V_91 ) ) {
if ( V_158 == V_175 )
return 0 ;
V_213 = & F_23 ( V_2 ) -> V_84 [ V_187 ] ;
V_214 = & F_23 ( V_208 ) -> V_84 [ V_158 ] ;
if ( V_211 >= F_100 ( V_213 ) ) {
* V_214 = * V_213 ;
V_211 -= F_100 ( V_213 ) ;
V_187 ++ ;
V_158 ++ ;
} else {
F_200 ( V_213 ) ;
V_214 -> V_54 = V_213 -> V_54 ;
V_214 -> V_120 = V_213 -> V_120 ;
F_141 ( V_214 , V_211 ) ;
V_213 -> V_120 += V_211 ;
F_146 ( V_213 , V_211 ) ;
V_211 = 0 ;
V_158 ++ ;
break;
}
}
F_23 ( V_208 ) -> V_91 = V_158 ;
if ( V_210 >= 0 ) {
V_213 = & F_23 ( V_2 ) -> V_84 [ 0 ] ;
V_214 = & F_23 ( V_208 ) -> V_84 [ V_210 ] ;
F_54 ( V_214 , F_100 ( V_213 ) ) ;
F_65 ( V_213 ) ;
}
V_158 = 0 ;
while ( V_187 < F_23 ( V_2 ) -> V_91 )
F_23 ( V_2 ) -> V_84 [ V_158 ++ ] = F_23 ( V_2 ) -> V_84 [ V_187 ++ ] ;
F_23 ( V_2 ) -> V_91 = V_158 ;
F_122 ( V_211 > 0 && ! F_23 ( V_2 ) -> V_91 ) ;
V_215:
V_208 -> V_121 = V_122 ;
V_2 -> V_121 = V_122 ;
V_2 -> V_6 -= V_209 ;
V_2 -> V_83 -= V_209 ;
V_2 -> V_27 -= V_209 ;
V_208 -> V_6 += V_209 ;
V_208 -> V_83 += V_209 ;
V_208 -> V_27 += V_209 ;
return V_209 ;
}
void F_201 ( struct V_1 * V_2 , unsigned int V_187 ,
unsigned int V_158 , struct V_216 * V_217 )
{
V_217 -> V_218 = V_187 ;
V_217 -> V_219 = V_158 ;
V_217 -> V_220 = V_217 -> V_221 = V_2 ;
V_217 -> V_222 = V_217 -> V_223 = 0 ;
V_217 -> V_224 = NULL ;
}
unsigned int F_202 ( unsigned int V_225 , const T_3 * * V_8 ,
struct V_216 * V_217 )
{
unsigned int V_226 , V_227 = V_225 + V_217 -> V_218 ;
T_5 * V_63 ;
if ( F_32 ( V_227 >= V_217 -> V_219 ) ) {
if ( V_217 -> V_224 ) {
F_101 ( V_217 -> V_224 ) ;
V_217 -> V_224 = NULL ;
}
return 0 ;
}
V_228:
V_226 = F_117 ( V_217 -> V_221 ) + V_217 -> V_223 ;
if ( V_227 < V_226 && ! V_217 -> V_224 ) {
* V_8 = V_217 -> V_221 -> V_8 + ( V_227 - V_217 -> V_223 ) ;
return V_226 - V_227 ;
}
if ( V_217 -> V_222 == 0 && ! V_217 -> V_224 )
V_217 -> V_223 += F_117 ( V_217 -> V_221 ) ;
while ( V_217 -> V_222 < F_23 ( V_217 -> V_221 ) -> V_91 ) {
V_63 = & F_23 ( V_217 -> V_221 ) -> V_84 [ V_217 -> V_222 ] ;
V_226 = F_100 ( V_63 ) + V_217 -> V_223 ;
if ( V_227 < V_226 ) {
if ( ! V_217 -> V_224 )
V_217 -> V_224 = F_98 ( F_99 ( V_63 ) ) ;
* V_8 = ( T_3 * ) V_217 -> V_224 + V_63 -> V_120 +
( V_227 - V_217 -> V_223 ) ;
return V_226 - V_227 ;
}
if ( V_217 -> V_224 ) {
F_101 ( V_217 -> V_224 ) ;
V_217 -> V_224 = NULL ;
}
V_217 -> V_222 ++ ;
V_217 -> V_223 += F_100 ( V_63 ) ;
}
if ( V_217 -> V_224 ) {
F_101 ( V_217 -> V_224 ) ;
V_217 -> V_224 = NULL ;
}
if ( V_217 -> V_220 == V_217 -> V_221 && F_120 ( V_217 -> V_220 ) ) {
V_217 -> V_221 = F_23 ( V_217 -> V_220 ) -> V_86 ;
V_217 -> V_222 = 0 ;
goto V_228;
} else if ( V_217 -> V_221 -> V_108 ) {
V_217 -> V_221 = V_217 -> V_221 -> V_108 ;
V_217 -> V_222 = 0 ;
goto V_228;
}
return 0 ;
}
void F_203 ( struct V_216 * V_217 )
{
if ( V_217 -> V_224 )
F_101 ( V_217 -> V_224 ) ;
}
static unsigned int F_204 ( unsigned int V_66 , const T_3 * * V_229 ,
struct V_230 * V_231 ,
struct V_232 * V_233 )
{
return F_202 ( V_66 , V_229 , F_205 ( V_233 ) ) ;
}
static void F_206 ( struct V_230 * V_231 , struct V_232 * V_233 )
{
F_203 ( F_205 ( V_233 ) ) ;
}
unsigned int F_207 ( struct V_1 * V_2 , unsigned int V_187 ,
unsigned int V_158 , struct V_230 * V_234 ,
struct V_232 * V_233 )
{
unsigned int V_186 ;
V_234 -> V_235 = F_204 ;
V_234 -> V_236 = F_206 ;
F_201 ( V_2 , V_187 , V_158 , F_205 ( V_233 ) ) ;
V_186 = F_208 ( V_234 , V_233 ) ;
return ( V_186 <= V_158 - V_187 ? V_186 : V_237 ) ;
}
int F_209 ( struct V_167 * V_111 , struct V_1 * V_2 ,
int (* F_210)( void * V_187 , char * V_158 , int V_66 ,
int V_6 , int V_238 , struct V_1 * V_2 ) ,
void * V_187 , int V_72 )
{
int V_239 = F_23 ( V_2 ) -> V_91 ;
int V_161 ;
int V_66 = 0 ;
int V_186 ;
struct V_168 * V_169 = & V_240 -> V_241 ;
do {
if ( V_239 >= V_175 )
return - V_242 ;
if ( ! F_151 ( V_111 , V_169 ) )
return - V_119 ;
V_161 = F_152 ( int , V_72 , V_169 -> V_14 - V_169 -> V_66 ) ;
V_186 = F_210 ( V_187 , F_37 ( V_169 -> V_54 ) + V_169 -> V_66 ,
V_66 , V_161 , 0 , V_2 ) ;
if ( V_186 < 0 )
return - V_163 ;
F_52 ( V_2 , V_239 , V_169 -> V_54 , V_169 -> V_66 ,
V_161 ) ;
V_239 ++ ;
V_169 -> V_66 += V_161 ;
F_155 ( V_169 -> V_54 ) ;
V_2 -> V_27 += V_161 ;
F_35 ( V_161 , & V_111 -> V_243 ) ;
V_2 -> V_6 += V_161 ;
V_2 -> V_83 += V_161 ;
V_66 += V_161 ;
V_72 -= V_161 ;
} while ( V_72 > 0 );
return 0 ;
}
unsigned char * F_211 ( struct V_1 * V_2 , unsigned int V_6 )
{
F_122 ( V_6 > V_2 -> V_6 ) ;
V_2 -> V_6 -= V_6 ;
F_122 ( V_2 -> V_6 < V_2 -> V_83 ) ;
F_212 ( V_2 , V_2 -> V_8 , V_6 ) ;
return V_2 -> V_8 += V_6 ;
}
struct V_1 * F_213 ( struct V_1 * V_244 ,
T_9 V_245 )
{
struct V_1 * V_107 = NULL ;
struct V_1 * V_9 = NULL ;
struct V_1 * V_246 = F_23 ( V_244 ) -> V_86 ;
T_5 * V_63 = F_23 ( V_244 ) -> V_84 ;
unsigned int V_247 = F_23 ( V_244 ) -> V_130 ;
unsigned int V_248 = V_244 -> V_8 - F_214 ( V_244 ) ;
struct V_1 * V_249 = V_244 ;
unsigned int V_66 = V_248 ;
unsigned int V_250 = F_215 ( V_244 ) ;
unsigned int V_134 ;
unsigned int V_6 ;
T_10 V_251 ;
bool V_188 ;
int V_252 = ! ! ( V_245 & V_253 ) ;
int V_149 = F_23 ( V_244 ) -> V_91 ;
int V_145 = - V_119 ;
int V_81 = 0 ;
int V_190 ;
int V_254 ;
F_216 ( V_244 , V_248 ) ;
V_251 = F_217 ( V_244 , & V_254 ) ;
if ( F_32 ( ! V_251 ) )
return F_218 ( - V_255 ) ;
V_188 = ! V_244 -> V_256 &&
! ! F_219 ( V_245 , V_251 ) ;
V_134 = F_92 ( V_244 ) ;
V_190 = F_117 ( V_244 ) ;
do {
struct V_1 * V_257 ;
T_5 * V_258 ;
int V_259 ;
int V_14 ;
V_6 = V_244 -> V_6 - V_66 ;
if ( V_6 > V_247 )
V_6 = V_247 ;
V_259 = F_117 ( V_244 ) - V_66 ;
if ( V_259 < 0 )
V_259 = 0 ;
if ( V_259 > V_6 || ! V_252 )
V_259 = V_6 ;
if ( ! V_259 && V_81 >= V_149 && F_117 ( V_246 ) &&
( F_117 ( V_246 ) == V_6 || V_252 ) ) {
F_122 ( F_117 ( V_246 ) > V_6 ) ;
V_81 = 0 ;
V_149 = F_23 ( V_246 ) -> V_91 ;
V_63 = F_23 ( V_246 ) -> V_84 ;
V_249 = V_246 ;
V_190 += F_117 ( V_246 ) ;
while ( V_190 < V_66 + V_6 ) {
F_122 ( V_81 >= V_149 ) ;
V_14 = F_100 ( V_63 ) ;
if ( V_190 + V_14 > V_66 + V_6 )
break;
V_81 ++ ;
V_190 += V_14 ;
V_63 ++ ;
}
V_257 = F_105 ( V_246 , V_52 ) ;
V_246 = V_246 -> V_108 ;
if ( F_32 ( ! V_257 ) )
goto V_145;
if ( F_32 ( F_142 ( V_257 , V_6 ) ) ) {
F_82 ( V_257 ) ;
goto V_145;
}
V_259 = F_113 ( V_257 ) ;
if ( F_220 ( V_257 , V_248 + V_134 ) ) {
F_82 ( V_257 ) ;
goto V_145;
}
V_257 -> V_27 += F_113 ( V_257 ) - V_259 ;
F_69 ( V_257 ) ;
F_216 ( V_257 , V_248 ) ;
} else {
V_257 = F_14 ( V_259 + V_248 + V_134 ,
V_52 , F_111 ( V_244 ) ,
V_62 ) ;
if ( F_32 ( ! V_257 ) )
goto V_145;
F_49 ( V_257 , V_134 ) ;
F_221 ( V_257 , V_248 ) ;
}
if ( V_107 )
V_9 -> V_108 = V_257 ;
else
V_107 = V_257 ;
V_9 = V_257 ;
F_91 ( V_257 , V_244 ) ;
F_108 ( V_257 , F_92 ( V_257 ) - V_134 ) ;
F_222 ( V_257 ) ;
F_147 ( V_244 , - V_250 ,
V_257 -> V_8 - V_250 ,
V_248 + V_250 ) ;
if ( V_257 -> V_6 == V_6 + V_248 )
goto V_260;
if ( ! V_252 && ! V_257 -> V_261 ) {
V_257 -> V_121 = V_262 ;
V_257 -> V_188 = F_169 ( V_244 , V_66 ,
F_114 ( V_257 , V_6 ) ,
V_6 , 0 ) ;
F_223 ( V_257 ) -> V_123 =
F_92 ( V_257 ) + V_248 ;
continue;
}
V_258 = F_23 ( V_257 ) -> V_84 ;
F_147 ( V_244 , V_66 ,
F_114 ( V_257 , V_259 ) , V_259 ) ;
F_23 ( V_257 ) -> V_92 = F_23 ( V_244 ) -> V_92 &
V_207 ;
while ( V_190 < V_66 + V_6 ) {
if ( V_81 >= V_149 ) {
F_122 ( F_117 ( V_246 ) ) ;
V_81 = 0 ;
V_149 = F_23 ( V_246 ) -> V_91 ;
V_63 = F_23 ( V_246 ) -> V_84 ;
V_249 = V_246 ;
F_122 ( ! V_149 ) ;
V_246 = V_246 -> V_108 ;
}
if ( F_32 ( F_23 ( V_257 ) -> V_91 >=
V_175 ) ) {
F_224 (
L_3 ,
V_190 , V_247 ) ;
goto V_145;
}
if ( F_32 ( F_106 ( V_249 , V_52 ) ) )
goto V_145;
* V_258 = * V_63 ;
F_200 ( V_258 ) ;
V_14 = F_100 ( V_258 ) ;
if ( V_190 < V_66 ) {
V_258 -> V_120 += V_66 - V_190 ;
F_146 ( V_258 , V_66 - V_190 ) ;
}
F_23 ( V_257 ) -> V_91 ++ ;
if ( V_190 + V_14 <= V_66 + V_6 ) {
V_81 ++ ;
V_63 ++ ;
V_190 += V_14 ;
} else {
F_146 ( V_258 , V_190 + V_14 - ( V_66 + V_6 ) ) ;
goto V_263;
}
V_258 ++ ;
}
V_263:
V_257 -> V_83 = V_6 - V_259 ;
V_257 -> V_6 += V_257 -> V_83 ;
V_257 -> V_27 += V_257 -> V_83 ;
V_260:
if ( ! V_188 && ! V_257 -> V_261 ) {
V_257 -> V_188 = F_168 ( V_257 , V_248 ,
V_257 -> V_6 - V_248 , 0 ) ;
V_257 -> V_121 = V_262 ;
F_223 ( V_257 ) -> V_123 =
F_92 ( V_257 ) + V_248 ;
}
} while ( ( V_66 += V_6 ) < V_244 -> V_6 );
V_107 -> V_110 = V_9 ;
if ( V_244 -> V_100 == V_264 ) {
F_225 ( V_9 -> V_27 , V_244 -> V_27 ) ;
F_225 ( V_9 -> V_100 , V_244 -> V_100 ) ;
F_225 ( V_9 -> V_111 , V_244 -> V_111 ) ;
}
return V_107 ;
V_145:
F_56 ( V_107 ) ;
return F_218 ( V_145 ) ;
}
int F_226 ( struct V_1 * * V_7 , struct V_1 * V_2 )
{
struct V_32 * V_265 , * V_266 = F_23 ( V_2 ) ;
unsigned int V_66 = F_227 ( V_2 ) ;
unsigned int V_267 = F_117 ( V_2 ) ;
struct V_1 * V_257 , * V_268 , * V_269 = * V_7 ;
unsigned int V_6 = F_228 ( V_2 ) ;
unsigned int V_270 ;
unsigned int V_134 ;
if ( F_32 ( V_269 -> V_6 + V_6 >= 65536 ) )
return - V_271 ;
V_268 = F_229 ( V_269 ) -> V_272 ;
V_265 = F_23 ( V_268 ) ;
if ( V_267 <= V_66 ) {
T_5 * V_63 ;
T_5 * V_273 ;
int V_81 = V_266 -> V_91 ;
int V_91 = V_265 -> V_91 + V_81 ;
if ( V_91 > V_175 )
goto V_210;
V_66 -= V_267 ;
V_265 -> V_91 = V_91 ;
V_266 -> V_91 = 0 ;
V_63 = V_265 -> V_84 + V_91 ;
V_273 = V_266 -> V_84 + V_81 ;
do {
* -- V_63 = * -- V_273 ;
} while ( -- V_81 );
V_63 -> V_120 += V_66 ;
F_146 ( V_63 , V_66 ) ;
V_270 = V_2 -> V_27 -
F_21 ( F_113 ( V_2 ) ) ;
V_2 -> V_27 -= V_2 -> V_83 ;
V_2 -> V_6 -= V_2 -> V_83 ;
V_2 -> V_83 = 0 ;
F_229 ( V_2 ) -> free = V_274 ;
goto V_151;
} else if ( V_2 -> V_53 ) {
int V_91 = V_265 -> V_91 ;
T_5 * V_63 = V_265 -> V_84 + V_91 ;
struct V_54 * V_54 = F_47 ( V_2 -> V_7 ) ;
unsigned int V_275 = V_267 - V_66 ;
unsigned int V_276 ;
if ( V_91 + 1 + V_266 -> V_91 > V_175 )
goto V_210;
V_276 = V_2 -> V_8 -
( unsigned char * ) F_37 ( V_54 ) +
V_66 ;
V_265 -> V_91 = V_91 + 1 + V_266 -> V_91 ;
V_63 -> V_54 . V_269 = V_54 ;
V_63 -> V_120 = V_276 ;
F_141 ( V_63 , V_275 ) ;
memcpy ( V_63 + 1 , V_266 -> V_84 , sizeof( * V_63 ) * V_266 -> V_91 ) ;
V_270 = V_2 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
F_229 ( V_2 ) -> free = V_277 ;
goto V_151;
}
V_265 = F_23 ( V_269 ) ;
if ( V_265 -> V_86 )
goto V_210;
if ( F_228 ( V_269 ) != V_265 -> V_130 )
return - V_271 ;
V_134 = F_92 ( V_269 ) ;
V_257 = F_230 ( V_134 + F_227 ( V_269 ) , V_52 ) ;
if ( F_32 ( ! V_257 ) )
return - V_119 ;
F_91 ( V_257 , V_269 ) ;
V_257 -> V_112 = V_269 -> V_112 ;
F_49 ( V_257 , V_134 ) ;
F_221 ( V_257 , F_227 ( V_269 ) ) ;
F_231 ( V_257 , F_214 ( V_269 ) - V_269 -> V_8 ) ;
F_232 ( V_257 , F_233 ( V_269 ) ) ;
F_234 ( V_257 , F_235 ( V_269 ) ) ;
F_236 ( V_269 , F_227 ( V_269 ) ) ;
memcpy ( F_214 ( V_257 ) , F_214 ( V_269 ) ,
V_269 -> V_8 - F_214 ( V_269 ) ) ;
F_23 ( V_257 ) -> V_86 = V_269 ;
F_23 ( V_257 ) -> V_130 = V_265 -> V_130 ;
V_265 -> V_130 = 0 ;
F_237 ( V_269 ) ;
F_229 ( V_257 ) -> V_272 = V_269 ;
V_257 -> V_83 += V_269 -> V_6 ;
V_257 -> V_27 += V_269 -> V_27 ;
V_257 -> V_6 += V_269 -> V_6 ;
* V_7 = V_257 ;
V_257 -> V_108 = V_269 -> V_108 ;
V_269 -> V_108 = NULL ;
V_269 = V_257 ;
V_210:
V_270 = V_2 -> V_27 ;
if ( V_66 > V_267 ) {
unsigned int V_154 = V_66 - V_267 ;
V_266 -> V_84 [ 0 ] . V_120 += V_154 ;
F_146 ( & V_266 -> V_84 [ 0 ] , V_154 ) ;
V_2 -> V_83 -= V_154 ;
V_2 -> V_6 -= V_154 ;
V_66 = V_267 ;
}
F_236 ( V_2 , V_66 ) ;
if ( F_229 ( V_269 ) -> V_272 == V_269 )
F_23 ( V_269 ) -> V_86 = V_2 ;
else
F_229 ( V_269 ) -> V_272 -> V_108 = V_2 ;
F_229 ( V_269 ) -> V_272 = V_2 ;
F_237 ( V_2 ) ;
V_268 = V_269 ;
V_151:
F_229 ( V_269 ) -> V_278 ++ ;
V_269 -> V_83 += V_6 ;
V_269 -> V_27 += V_270 ;
V_269 -> V_6 += V_6 ;
if ( V_268 != V_269 ) {
V_268 -> V_83 += V_6 ;
V_268 -> V_27 += V_270 ;
V_268 -> V_6 += V_6 ;
}
F_229 ( V_2 ) -> V_279 = 1 ;
return 0 ;
}
void T_11 F_238 ( void )
{
V_25 = F_239 ( L_4 ,
sizeof( struct V_1 ) ,
0 ,
V_280 | V_281 ,
NULL ) ;
V_35 = F_239 ( L_5 ,
sizeof( struct V_42 ) ,
0 ,
V_280 | V_281 ,
NULL ) ;
}
static int
F_240 ( struct V_1 * V_2 , struct V_282 * V_252 , int V_66 , int V_6 )
{
int V_159 = F_117 ( V_2 ) ;
int V_81 , V_161 = V_159 - V_66 ;
struct V_1 * V_160 ;
int V_283 = 0 ;
if ( V_161 > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
F_241 ( V_252 , V_2 -> V_8 + V_66 , V_161 ) ;
V_283 ++ ;
if ( ( V_6 -= V_161 ) == 0 )
return V_283 ;
V_66 += V_161 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_10 ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + F_100 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
if ( V_161 > V_6 )
V_161 = V_6 ;
F_242 ( & V_252 [ V_283 ] , F_99 ( V_63 ) , V_161 ,
V_63 -> V_120 + V_66 - V_159 ) ;
V_283 ++ ;
if ( ! ( V_6 -= V_161 ) )
return V_283 ;
V_66 += V_161 ;
}
V_159 = V_10 ;
}
F_59 (skb, frag_iter) {
int V_10 ;
F_73 ( V_159 > V_66 + V_6 ) ;
V_10 = V_159 + V_160 -> V_6 ;
if ( ( V_161 = V_10 - V_66 ) > 0 ) {
if ( V_161 > V_6 )
V_161 = V_6 ;
V_283 += F_240 ( V_160 , V_252 + V_283 , V_66 - V_159 ,
V_161 ) ;
if ( ( V_6 -= V_161 ) == 0 )
return V_283 ;
V_66 += V_161 ;
}
V_159 = V_10 ;
}
F_122 ( V_6 ) ;
return V_283 ;
}
int F_243 ( struct V_1 * V_2 , struct V_282 * V_252 ,
int V_66 , int V_6 )
{
return F_240 ( V_2 , V_252 , V_66 , V_6 ) ;
}
int F_244 ( struct V_1 * V_2 , struct V_282 * V_252 , int V_66 , int V_6 )
{
int V_284 = F_240 ( V_2 , V_252 , V_66 , V_6 ) ;
F_245 ( & V_252 [ V_284 - 1 ] ) ;
return V_284 ;
}
int F_246 ( struct V_1 * V_2 , int V_285 , struct V_1 * * V_286 )
{
int V_287 ;
int V_283 ;
struct V_1 * V_44 , * * V_288 ;
if ( ( F_125 ( V_2 ) || F_23 ( V_2 ) -> V_91 ) &&
F_144 ( V_2 , F_247 ( V_2 ) - F_117 ( V_2 ) ) == NULL )
return - V_119 ;
if ( ! F_120 ( V_2 ) ) {
if ( F_131 ( V_2 ) < V_285 &&
F_121 ( V_2 , 0 , V_285 - F_131 ( V_2 ) + 128 , V_52 ) )
return - V_119 ;
* V_286 = V_2 ;
return 1 ;
}
V_283 = 1 ;
V_288 = & F_23 ( V_2 ) -> V_86 ;
V_287 = 0 ;
while ( ( V_44 = * V_288 ) != NULL ) {
int V_136 = 0 ;
if ( F_123 ( V_44 ) )
V_287 = 1 ;
if ( V_44 -> V_108 == NULL && V_285 ) {
if ( F_23 ( V_44 ) -> V_91 ||
F_120 ( V_44 ) ||
F_131 ( V_44 ) < V_285 )
V_136 = V_285 + 128 ;
}
if ( V_287 ||
F_125 ( V_44 ) ||
V_136 ||
F_23 ( V_44 ) -> V_91 ||
F_120 ( V_44 ) ) {
struct V_1 * V_45 ;
if ( V_136 == 0 )
V_45 = F_112 ( V_44 , V_52 ) ;
else
V_45 = F_129 ( V_44 ,
F_92 ( V_44 ) ,
V_136 ,
V_52 ) ;
if ( F_32 ( V_45 == NULL ) )
return - V_119 ;
if ( V_44 -> V_111 )
F_248 ( V_45 , V_44 -> V_111 ) ;
V_45 -> V_108 = V_44 -> V_108 ;
* V_288 = V_45 ;
F_82 ( V_44 ) ;
V_44 = V_45 ;
}
V_283 ++ ;
* V_286 = V_44 ;
V_288 = & V_44 -> V_108 ;
}
return V_283 ;
}
static void F_249 ( struct V_1 * V_2 )
{
struct V_167 * V_111 = V_2 -> V_111 ;
F_250 ( V_2 -> V_27 , & V_111 -> V_289 ) ;
}
int F_251 ( struct V_167 * V_111 , struct V_1 * V_2 )
{
if ( F_67 ( & V_111 -> V_289 ) + V_2 -> V_27 >=
( unsigned int ) V_111 -> V_290 )
return - V_119 ;
F_252 ( V_2 ) ;
V_2 -> V_111 = V_111 ;
V_2 -> V_100 = F_249 ;
F_35 ( V_2 -> V_27 , & V_111 -> V_289 ) ;
F_253 ( V_2 ) ;
F_186 ( & V_111 -> V_291 , V_2 ) ;
if ( ! F_254 ( V_111 , V_292 ) )
V_111 -> V_293 ( V_111 ) ;
return 0 ;
}
struct V_1 * F_255 ( struct V_167 * V_111 )
{
struct V_203 * V_294 = & V_111 -> V_291 ;
struct V_1 * V_2 , * V_295 ;
int V_145 = 0 ;
F_256 ( & V_294 -> V_205 ) ;
V_2 = F_179 ( V_294 ) ;
if ( V_2 && ( V_295 = F_257 ( V_294 ) ) )
V_145 = F_258 ( V_295 ) -> V_296 . V_297 ;
F_259 ( & V_294 -> V_205 ) ;
V_111 -> V_298 = V_145 ;
if ( V_145 )
V_111 -> V_299 ( V_111 ) ;
return V_2 ;
}
struct V_1 * F_260 ( struct V_1 * V_2 )
{
struct V_167 * V_111 = V_2 -> V_111 ;
struct V_1 * V_156 ;
if ( ! V_111 || ! F_261 ( & V_111 -> V_300 ) )
return NULL ;
V_156 = F_105 ( V_2 , V_52 ) ;
if ( ! V_156 ) {
F_262 ( V_111 ) ;
return NULL ;
}
V_156 -> V_111 = V_111 ;
V_156 -> V_100 = V_301 ;
return V_156 ;
}
static void F_263 ( struct V_1 * V_2 ,
struct V_167 * V_111 ,
int V_302 )
{
struct V_303 * V_304 ;
int V_145 ;
V_304 = F_258 ( V_2 ) ;
memset ( V_304 , 0 , sizeof( * V_304 ) ) ;
V_304 -> V_296 . V_297 = V_305 ;
V_304 -> V_296 . V_306 = V_307 ;
V_304 -> V_296 . V_308 = V_302 ;
if ( V_111 -> V_309 & V_310 ) {
V_304 -> V_296 . V_311 = F_23 ( V_2 ) -> V_312 ;
if ( V_111 -> V_313 == V_314 )
V_304 -> V_296 . V_311 -= V_111 -> V_315 ;
}
V_145 = F_251 ( V_111 , V_2 ) ;
if ( V_145 )
F_82 ( V_2 ) ;
}
void F_264 ( struct V_1 * V_2 ,
struct V_316 * V_317 )
{
struct V_167 * V_111 = V_2 -> V_111 ;
F_265 ( V_111 ) ;
* F_266 ( V_2 ) = * V_317 ;
F_263 ( V_2 , V_111 , V_318 ) ;
F_262 ( V_111 ) ;
}
void F_267 ( struct V_1 * V_319 ,
struct V_316 * V_317 ,
struct V_167 * V_111 , int V_302 )
{
struct V_1 * V_2 ;
if ( ! V_111 )
return;
if ( V_317 )
* F_266 ( V_319 ) = * V_317 ;
else
V_319 -> V_320 = F_268 () ;
V_2 = F_105 ( V_319 , V_52 ) ;
if ( ! V_2 )
return;
F_263 ( V_2 , V_111 , V_302 ) ;
}
void F_269 ( struct V_1 * V_319 ,
struct V_316 * V_317 )
{
return F_267 ( V_319 , V_317 , V_319 -> V_111 ,
V_318 ) ;
}
void F_270 ( struct V_1 * V_2 , bool V_321 )
{
struct V_167 * V_111 = V_2 -> V_111 ;
struct V_303 * V_304 ;
int V_145 ;
V_2 -> V_322 = 1 ;
V_2 -> V_323 = V_321 ;
V_304 = F_258 ( V_2 ) ;
memset ( V_304 , 0 , sizeof( * V_304 ) ) ;
V_304 -> V_296 . V_297 = V_305 ;
V_304 -> V_296 . V_306 = V_324 ;
F_265 ( V_111 ) ;
V_145 = F_251 ( V_111 , V_2 ) ;
if ( V_145 )
F_82 ( V_2 ) ;
F_262 ( V_111 ) ;
}
bool F_271 ( struct V_1 * V_2 , T_12 V_159 , T_12 V_82 )
{
if ( F_32 ( V_159 > F_117 ( V_2 ) ) ||
F_32 ( ( int ) V_159 + V_82 > F_117 ( V_2 ) - 2 ) ) {
F_224 ( L_6 ,
V_159 , V_82 , F_117 ( V_2 ) ) ;
return false ;
}
V_2 -> V_121 = V_122 ;
V_2 -> V_123 = F_92 ( V_2 ) + V_159 ;
V_2 -> V_201 = V_82 ;
F_234 ( V_2 , V_159 ) ;
return true ;
}
static int F_272 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_325 )
{
if ( F_117 ( V_2 ) >= V_6 )
return 0 ;
if ( V_325 > V_2 -> V_6 )
V_325 = V_2 -> V_6 ;
if ( F_144 ( V_2 , V_325 - F_117 ( V_2 ) ) == NULL )
return - V_119 ;
if ( F_117 ( V_2 ) < V_6 )
return - V_326 ;
return 0 ;
}
static int F_273 ( struct V_1 * V_2 , bool V_327 )
{
unsigned int V_82 ;
bool V_328 ;
V_202 * V_188 ;
int V_145 ;
V_328 = false ;
V_145 = F_272 ( V_2 ,
sizeof( struct V_329 ) ,
V_330 ) ;
if ( V_145 < 0 )
goto V_23;
if ( F_274 ( V_2 ) -> V_331 & F_275 ( V_332 | V_333 ) )
V_328 = true ;
V_82 = F_276 ( V_2 ) ;
V_145 = - V_326 ;
if ( V_328 )
goto V_23;
V_188 = F_277 ( V_2 , F_274 ( V_2 ) -> V_334 , V_82 ) ;
if ( F_278 ( V_188 ) )
return F_279 ( V_188 ) ;
if ( V_327 )
* V_188 = ~ F_280 ( F_274 ( V_2 ) -> V_335 ,
F_274 ( V_2 ) -> V_336 ,
V_2 -> V_6 - V_82 ,
F_274 ( V_2 ) -> V_334 , 0 ) ;
V_145 = 0 ;
V_23:
return V_145 ;
}
static int F_281 ( struct V_1 * V_2 , bool V_327 )
{
int V_145 ;
T_3 V_337 ;
unsigned int V_82 ;
unsigned int V_6 ;
bool V_328 ;
bool V_151 ;
V_202 * V_188 ;
V_328 = false ;
V_151 = false ;
V_82 = sizeof( struct V_338 ) ;
V_145 = F_272 ( V_2 , V_82 , V_339 ) ;
if ( V_145 < 0 )
goto V_23;
V_337 = F_282 ( V_2 ) -> V_337 ;
V_6 = sizeof( struct V_338 ) + F_283 ( F_282 ( V_2 ) -> V_340 ) ;
while ( V_82 <= V_6 && ! V_151 ) {
switch ( V_337 ) {
case V_341 :
case V_342 :
case V_343 : {
struct V_344 * V_345 ;
V_145 = F_272 ( V_2 ,
V_82 +
sizeof( struct V_344 ) ,
V_339 ) ;
if ( V_145 < 0 )
goto V_23;
V_345 = F_284 ( struct V_344 , V_2 , V_82 ) ;
V_337 = V_345 -> V_337 ;
V_82 += F_285 ( V_345 ) ;
break;
}
case V_346 : {
struct V_347 * V_345 ;
V_145 = F_272 ( V_2 ,
V_82 +
sizeof( struct V_347 ) ,
V_339 ) ;
if ( V_145 < 0 )
goto V_23;
V_345 = F_284 ( struct V_347 , V_2 , V_82 ) ;
V_337 = V_345 -> V_337 ;
V_82 += F_286 ( V_345 ) ;
break;
}
case V_348 : {
struct V_349 * V_345 ;
V_145 = F_272 ( V_2 ,
V_82 +
sizeof( struct V_349 ) ,
V_339 ) ;
if ( V_145 < 0 )
goto V_23;
V_345 = F_284 ( struct V_349 , V_2 , V_82 ) ;
if ( V_345 -> V_331 & F_275 ( V_350 | V_351 ) )
V_328 = true ;
V_337 = V_345 -> V_337 ;
V_82 += sizeof( struct V_349 ) ;
break;
}
default:
V_151 = true ;
break;
}
}
V_145 = - V_326 ;
if ( ! V_151 || V_328 )
goto V_23;
V_188 = F_277 ( V_2 , V_337 , V_82 ) ;
if ( F_278 ( V_188 ) )
return F_279 ( V_188 ) ;
if ( V_327 )
* V_188 = ~ F_287 ( & F_282 ( V_2 ) -> V_335 ,
& F_282 ( V_2 ) -> V_336 ,
V_2 -> V_6 - V_82 , V_337 , 0 ) ;
V_145 = 0 ;
V_23:
return V_145 ;
}
int F_288 ( struct V_1 * V_2 , bool V_327 )
{
int V_145 ;
switch ( V_2 -> V_334 ) {
case F_275 ( V_352 ) :
V_145 = F_273 ( V_2 , V_327 ) ;
break;
case F_275 ( V_353 ) :
V_145 = F_281 ( V_2 , V_327 ) ;
break;
default:
V_145 = - V_326 ;
break;
}
return V_145 ;
}
void F_289 ( const struct V_1 * V_2 )
{
F_224 ( L_7 ,
V_2 -> V_11 -> V_12 ) ;
}
void F_290 ( struct V_1 * V_2 , bool V_354 )
{
if ( V_354 ) {
F_69 ( V_2 ) ;
F_27 ( V_25 , V_2 ) ;
} else {
F_81 ( V_2 ) ;
}
}
bool F_291 ( struct V_1 * V_158 , struct V_1 * V_187 ,
bool * V_355 , int * V_270 )
{
int V_81 , V_138 , V_6 = V_187 -> V_6 ;
* V_355 = false ;
if ( F_125 ( V_158 ) )
return false ;
if ( V_6 <= F_131 ( V_158 ) ) {
if ( V_6 )
F_122 ( F_115 ( V_187 , 0 , F_114 ( V_158 , V_6 ) , V_6 ) ) ;
* V_270 = 0 ;
return true ;
}
if ( F_120 ( V_158 ) || F_120 ( V_187 ) )
return false ;
if ( F_117 ( V_187 ) != 0 ) {
struct V_54 * V_54 ;
unsigned int V_66 ;
if ( F_23 ( V_158 ) -> V_91 +
F_23 ( V_187 ) -> V_91 >= V_175 )
return false ;
if ( F_160 ( V_187 ) )
return false ;
V_138 = V_187 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
V_54 = F_47 ( V_187 -> V_7 ) ;
V_66 = V_187 -> V_8 - ( unsigned char * ) F_37 ( V_54 ) ;
F_52 ( V_158 , F_23 ( V_158 ) -> V_91 ,
V_54 , V_66 , F_117 ( V_187 ) ) ;
* V_355 = true ;
} else {
if ( F_23 ( V_158 ) -> V_91 +
F_23 ( V_187 ) -> V_91 > V_175 )
return false ;
V_138 = V_187 -> V_27 - F_21 ( F_113 ( V_187 ) ) ;
}
F_292 ( V_138 < V_6 ) ;
memcpy ( F_23 ( V_158 ) -> V_84 + F_23 ( V_158 ) -> V_91 ,
F_23 ( V_187 ) -> V_84 ,
F_23 ( V_187 ) -> V_91 * sizeof( T_5 ) ) ;
F_23 ( V_158 ) -> V_91 += F_23 ( V_187 ) -> V_91 ;
if ( ! F_125 ( V_187 ) )
F_23 ( V_187 ) -> V_91 = 0 ;
for ( V_81 = 0 ; V_81 < F_23 ( V_187 ) -> V_91 ; V_81 ++ )
F_119 ( V_187 , V_81 ) ;
V_158 -> V_27 += V_138 ;
V_158 -> V_6 += V_6 ;
V_158 -> V_83 += V_6 ;
* V_270 = V_138 ;
return true ;
}
void F_293 ( struct V_1 * V_2 , bool V_356 )
{
if ( V_356 )
F_252 ( V_2 ) ;
V_2 -> V_320 . V_357 = 0 ;
V_2 -> V_358 = V_359 ;
V_2 -> V_360 = 0 ;
V_2 -> V_361 = 0 ;
F_70 ( V_2 ) ;
V_2 -> V_362 = 0 ;
F_294 ( V_2 ) ;
F_295 ( V_2 ) ;
F_296 ( V_2 ) ;
F_297 ( V_2 ) ;
}
unsigned int F_298 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_23 ( V_2 ) ;
unsigned int V_363 = 0 ;
if ( V_2 -> V_364 ) {
V_363 = F_299 ( V_2 ) -
F_300 ( V_2 ) ;
if ( F_45 ( V_33 -> V_132 & ( V_365 | V_366 ) ) )
V_363 += F_301 ( V_2 ) ;
} else if ( F_45 ( V_33 -> V_132 & ( V_365 | V_366 ) ) ) {
V_363 = F_302 ( V_2 ) ;
}
return V_363 + V_33 -> V_130 ;
}
static struct V_1 * F_303 ( struct V_1 * V_2 )
{
if ( F_304 ( V_2 , F_92 ( V_2 ) ) < 0 ) {
F_82 ( V_2 ) ;
return NULL ;
}
memmove ( V_2 -> V_8 - V_367 , V_2 -> V_8 - V_368 , 2 * V_369 ) ;
V_2 -> V_29 += V_370 ;
return V_2 ;
}
struct V_1 * F_305 ( struct V_1 * V_2 )
{
struct V_371 * V_372 ;
T_12 V_373 ;
if ( F_32 ( F_306 ( V_2 ) ) ) {
return V_2 ;
}
V_2 = F_307 ( V_2 , V_52 ) ;
if ( F_32 ( ! V_2 ) )
goto V_374;
if ( F_32 ( ! F_308 ( V_2 , V_370 ) ) )
goto V_374;
V_372 = (struct V_371 * ) V_2 -> V_8 ;
V_373 = F_283 ( V_372 -> V_375 ) ;
F_309 ( V_2 , V_2 -> V_334 , V_373 ) ;
F_211 ( V_2 , V_370 ) ;
F_310 ( V_2 , V_372 ) ;
V_2 = F_303 ( V_2 ) ;
if ( F_32 ( ! V_2 ) )
goto V_374;
F_311 ( V_2 ) ;
F_312 ( V_2 ) ;
F_222 ( V_2 ) ;
return V_2 ;
V_374:
F_82 ( V_2 ) ;
return NULL ;
}
int F_313 ( struct V_1 * V_2 , int V_376 )
{
if ( ! F_308 ( V_2 , V_376 ) )
return - V_119 ;
if ( ! F_125 ( V_2 ) || F_314 ( V_2 , V_376 ) )
return 0 ;
return F_121 ( V_2 , 0 , 0 , V_52 ) ;
}
static int F_315 ( struct V_1 * V_2 , T_12 * V_373 )
{
struct V_371 * V_372 ;
unsigned int V_66 = V_2 -> V_8 - F_214 ( V_2 ) ;
int V_145 ;
F_216 ( V_2 , V_66 ) ;
V_145 = F_313 ( V_2 , V_368 ) ;
if ( F_32 ( V_145 ) )
goto V_377;
F_212 ( V_2 , V_2 -> V_8 + ( 2 * V_369 ) , V_370 ) ;
V_372 = (struct V_371 * ) ( V_2 -> V_8 + V_367 ) ;
* V_373 = F_283 ( V_372 -> V_375 ) ;
memmove ( V_2 -> V_8 + V_370 , V_2 -> V_8 , 2 * V_369 ) ;
F_236 ( V_2 , V_370 ) ;
F_310 ( V_2 , V_372 ) ;
V_2 -> V_29 += V_370 ;
if ( F_233 ( V_2 ) < V_367 )
F_232 ( V_2 , V_367 ) ;
F_222 ( V_2 ) ;
V_377:
F_236 ( V_2 , V_66 ) ;
return V_145 ;
}
int F_316 ( struct V_1 * V_2 )
{
T_12 V_373 ;
T_10 V_378 ;
int V_145 ;
if ( F_45 ( F_306 ( V_2 ) ) ) {
V_2 -> V_373 = 0 ;
} else {
if ( F_32 ( ( V_2 -> V_334 != F_275 ( V_379 ) &&
V_2 -> V_334 != F_275 ( V_380 ) ) ||
V_2 -> V_6 < V_368 ) )
return 0 ;
V_145 = F_315 ( V_2 , & V_373 ) ;
if ( V_145 )
return V_145 ;
}
if ( F_45 ( ( V_2 -> V_334 != F_275 ( V_379 ) &&
V_2 -> V_334 != F_275 ( V_380 ) ) ||
V_2 -> V_6 < V_368 ) )
return 0 ;
V_378 = V_2 -> V_334 ;
V_145 = F_315 ( V_2 , & V_373 ) ;
if ( F_32 ( V_145 ) )
return V_145 ;
F_309 ( V_2 , V_378 , V_373 ) ;
return 0 ;
}
int F_317 ( struct V_1 * V_2 , T_10 V_378 , T_12 V_373 )
{
if ( F_306 ( V_2 ) ) {
unsigned int V_66 = V_2 -> V_8 - F_214 ( V_2 ) ;
int V_145 ;
F_216 ( V_2 , V_66 ) ;
V_145 = F_318 ( V_2 , V_2 -> V_378 ,
F_319 ( V_2 ) ) ;
if ( V_145 )
return V_145 ;
V_2 -> V_334 = V_2 -> V_378 ;
V_2 -> V_112 += V_370 ;
F_236 ( V_2 , V_66 ) ;
if ( V_2 -> V_121 == V_381 )
V_2 -> V_188 = F_320 ( V_2 -> V_188 , F_321 ( V_2 -> V_8
+ ( 2 * V_369 ) , V_370 , 0 ) ) ;
}
F_309 ( V_2 , V_378 , V_373 ) ;
return 0 ;
}
struct V_1 * F_322 ( unsigned long V_382 ,
unsigned long V_83 ,
int V_383 ,
int * V_384 ,
T_2 V_24 )
{
int V_385 = ( V_83 + ( V_64 - 1 ) ) >> V_386 ;
unsigned long V_387 ;
struct V_1 * V_2 ;
struct V_54 * V_54 ;
T_2 V_388 ;
int V_81 ;
* V_384 = - V_242 ;
if ( V_385 > V_175 )
return NULL ;
V_388 = V_24 ;
if ( V_388 & V_73 )
V_388 |= V_389 ;
* V_384 = - V_390 ;
V_2 = F_230 ( V_382 , V_388 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_27 += V_385 << V_386 ;
for ( V_81 = 0 ; V_385 > 0 ; V_81 ++ ) {
int V_57 = V_383 ;
while ( V_57 ) {
if ( V_385 >= 1 << V_57 ) {
V_54 = F_323 ( V_24 |
V_60 |
V_22 |
V_61 ,
V_57 ) ;
if ( V_54 )
goto V_391;
V_57 = 1 ;
V_383 = 0 ;
}
V_57 -- ;
}
V_54 = F_96 ( V_24 ) ;
if ( ! V_54 )
goto V_392;
V_391:
V_387 = F_152 (unsigned long, data_len,
PAGE_SIZE << order) ;
F_52 ( V_2 , V_81 , V_54 , 0 , V_387 ) ;
V_83 -= V_387 ;
V_385 -= 1 << V_57 ;
}
return V_2 ;
V_392:
F_82 ( V_2 ) ;
return NULL ;
}
