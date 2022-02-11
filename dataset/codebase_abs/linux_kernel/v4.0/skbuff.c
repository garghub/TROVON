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
}
static void F_78 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
if ( F_45 ( V_2 -> V_7 ) )
F_63 ( V_2 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_66 ( V_2 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 ) )
return;
if ( F_45 ( F_67 ( & V_2 -> V_28 ) == 1 ) )
F_81 () ;
else if ( F_45 ( ! F_68 ( & V_2 -> V_28 ) ) )
return;
F_82 ( V_2 , F_83 ( 0 ) ) ;
F_79 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_105 )
{
while ( V_105 ) {
struct V_1 * V_106 = V_105 -> V_106 ;
F_80 ( V_105 ) ;
V_105 = V_106 ;
}
}
void F_84 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) -> V_92 & V_93 ) {
struct V_94 * V_95 ;
V_95 = F_23 ( V_2 ) -> V_41 ;
if ( V_95 -> V_96 )
V_95 -> V_96 ( V_95 , false ) ;
F_23 ( V_2 ) -> V_92 &= ~ V_93 ;
}
}
void F_85 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 ) )
return;
if ( F_45 ( F_67 ( & V_2 -> V_28 ) == 1 ) )
F_81 () ;
else if ( F_45 ( ! F_68 ( & V_2 -> V_28 ) ) )
return;
F_86 ( V_2 ) ;
F_79 ( V_2 ) ;
}
static struct V_1 * F_87 ( struct V_1 * V_107 , struct V_1 * V_2 )
{
#define F_88 ( T_6 ) n->x = skb->x
V_107 -> V_106 = V_107 -> V_108 = NULL ;
V_107 -> V_109 = NULL ;
F_89 ( V_107 , V_2 ) ;
F_88 ( V_6 ) ;
F_88 ( V_83 ) ;
F_88 ( V_110 ) ;
V_107 -> V_111 = V_2 -> V_89 ? F_90 ( V_2 ) : V_2 -> V_111 ;
V_107 -> V_88 = 1 ;
V_107 -> V_89 = 0 ;
V_107 -> V_100 = NULL ;
F_88 ( V_9 ) ;
F_88 ( V_10 ) ;
F_88 ( V_7 ) ;
F_88 ( V_53 ) ;
F_88 ( V_8 ) ;
F_88 ( V_27 ) ;
F_12 ( & V_107 -> V_28 , 1 ) ;
F_91 ( & ( F_23 ( V_2 ) -> V_40 ) ) ;
V_2 -> V_88 = 1 ;
return V_107 ;
#undef F_88
}
struct V_1 * F_92 ( struct V_1 * V_112 , struct V_1 * V_113 )
{
F_78 ( V_112 ) ;
return F_87 ( V_112 , V_113 ) ;
}
int F_93 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_81 ;
int V_114 = F_23 ( V_2 ) -> V_91 ;
struct V_54 * V_54 , * V_7 = NULL ;
struct V_94 * V_95 = F_23 ( V_2 ) -> V_41 ;
for ( V_81 = 0 ; V_81 < V_114 ; V_81 ++ ) {
T_3 * V_115 ;
T_5 * V_116 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
V_54 = F_94 ( V_24 ) ;
if ( ! V_54 ) {
while ( V_7 ) {
struct V_54 * V_106 = (struct V_54 * ) F_95 ( V_7 ) ;
F_46 ( V_7 ) ;
V_7 = V_106 ;
}
return - V_117 ;
}
V_115 = F_96 ( F_97 ( V_116 ) ) ;
memcpy ( F_37 ( V_54 ) ,
V_115 + V_116 -> V_118 , F_98 ( V_116 ) ) ;
F_99 ( V_115 ) ;
F_100 ( V_54 , ( unsigned long ) V_7 ) ;
V_7 = V_54 ;
}
for ( V_81 = 0 ; V_81 < V_114 ; V_81 ++ )
F_101 ( V_2 , V_81 ) ;
V_95 -> V_96 ( V_95 , false ) ;
for ( V_81 = V_114 - 1 ; V_81 >= 0 ; V_81 -- ) {
F_102 ( V_2 , V_81 , V_7 , 0 ,
F_23 ( V_2 ) -> V_84 [ V_81 ] . V_14 ) ;
V_7 = (struct V_54 * ) F_95 ( V_7 ) ;
}
F_23 ( V_2 ) -> V_92 &= ~ V_93 ;
return 0 ;
}
struct V_1 * F_103 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_42 * V_43 = F_25 ( V_2 ,
struct V_42 ,
V_44 ) ;
struct V_1 * V_107 ;
if ( F_104 ( V_2 , V_24 ) )
return NULL ;
if ( V_2 -> V_47 == V_48 &&
F_67 ( & V_43 -> V_49 ) == 1 ) {
V_107 = & V_43 -> V_45 ;
F_12 ( & V_43 -> V_49 , 2 ) ;
} else {
if ( F_105 ( V_2 ) )
V_24 |= V_37 ;
V_107 = F_29 ( V_25 , V_24 ) ;
if ( ! V_107 )
return NULL ;
F_26 ( V_107 , V_46 ) ;
V_107 -> V_47 = V_97 ;
}
return F_87 ( V_107 , V_2 ) ;
}
static void F_106 ( struct V_1 * V_2 , int V_82 )
{
if ( V_2 -> V_119 == V_120 )
V_2 -> V_121 += V_82 ;
V_2 -> V_39 += V_82 ;
V_2 -> V_122 += V_82 ;
if ( F_107 ( V_2 ) )
V_2 -> V_29 += V_82 ;
V_2 -> V_123 += V_82 ;
V_2 -> V_124 += V_82 ;
V_2 -> V_125 += V_82 ;
}
static void F_108 ( struct V_1 * V_126 , const struct V_1 * V_127 )
{
F_89 ( V_126 , V_127 ) ;
F_23 ( V_126 ) -> V_128 = F_23 ( V_127 ) -> V_128 ;
F_23 ( V_126 ) -> V_129 = F_23 ( V_127 ) -> V_129 ;
F_23 ( V_126 ) -> V_130 = F_23 ( V_127 ) -> V_130 ;
}
static inline int F_109 ( const struct V_1 * V_2 )
{
if ( F_105 ( V_2 ) )
return V_36 ;
return 0 ;
}
struct V_1 * F_110 ( const struct V_1 * V_2 , T_2 V_24 )
{
int V_131 = F_90 ( V_2 ) ;
unsigned int V_14 = F_111 ( V_2 ) + V_2 -> V_83 ;
struct V_1 * V_107 = F_14 ( V_14 , V_24 ,
F_109 ( V_2 ) , V_62 ) ;
if ( ! V_107 )
return NULL ;
F_49 ( V_107 , V_131 ) ;
F_112 ( V_107 , V_2 -> V_6 ) ;
if ( F_113 ( V_2 , - V_131 , V_107 -> V_7 , V_131 + V_2 -> V_6 ) )
F_3 () ;
F_108 ( V_107 , V_2 ) ;
return V_107 ;
}
struct V_1 * F_114 ( struct V_1 * V_2 , int V_132 ,
T_2 V_24 , bool V_47 )
{
unsigned int V_14 = F_115 ( V_2 ) + V_132 ;
int V_15 = F_109 ( V_2 ) | ( V_47 ? V_34 : 0 ) ;
struct V_1 * V_107 = F_14 ( V_14 , V_24 , V_15 , V_62 ) ;
if ( ! V_107 )
goto V_23;
F_49 ( V_107 , V_132 ) ;
F_112 ( V_107 , F_115 ( V_2 ) ) ;
F_116 ( V_2 , V_107 -> V_8 , V_107 -> V_6 ) ;
V_107 -> V_27 += V_2 -> V_83 ;
V_107 -> V_83 = V_2 -> V_83 ;
V_107 -> V_6 = V_2 -> V_6 ;
if ( F_23 ( V_2 ) -> V_91 ) {
int V_81 ;
if ( F_104 ( V_2 , V_24 ) ) {
F_80 ( V_107 ) ;
V_107 = NULL ;
goto V_23;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
F_23 ( V_107 ) -> V_84 [ V_81 ] = F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_117 ( V_2 , V_81 ) ;
}
F_23 ( V_107 ) -> V_91 = V_81 ;
}
if ( F_118 ( V_2 ) ) {
F_23 ( V_107 ) -> V_86 = F_23 ( V_2 ) -> V_86 ;
F_58 ( V_107 ) ;
}
F_108 ( V_107 , V_2 ) ;
V_23:
return V_107 ;
}
int F_119 ( struct V_1 * V_2 , int V_133 , int V_134 ,
T_2 V_24 )
{
int V_81 ;
T_3 * V_8 ;
int V_14 = V_133 + F_111 ( V_2 ) + V_134 ;
long V_82 ;
F_120 ( V_133 < 0 ) ;
if ( F_121 ( V_2 ) )
F_3 () ;
V_14 = F_17 ( V_14 ) ;
if ( F_105 ( V_2 ) )
V_24 |= V_37 ;
V_8 = F_18 ( V_14 + F_17 ( sizeof( struct V_32 ) ) ,
V_24 , V_62 , NULL ) ;
if ( ! V_8 )
goto V_38;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
memcpy ( V_8 + V_133 , V_2 -> V_7 , F_122 ( V_2 ) - V_2 -> V_7 ) ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) ,
F_11 ( struct V_32 , V_84 [ F_23 ( V_2 ) -> V_91 ] ) ) ;
if ( F_123 ( V_2 ) ) {
if ( F_104 ( V_2 , V_24 ) )
goto V_135;
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ )
F_117 ( V_2 , V_81 ) ;
if ( F_118 ( V_2 ) )
F_58 ( V_2 ) ;
F_63 ( V_2 ) ;
} else {
F_61 ( V_2 ) ;
}
V_82 = ( V_8 + V_133 ) - V_2 -> V_7 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_53 = 0 ;
V_2 -> V_8 += V_82 ;
#ifdef F_124
V_2 -> V_10 = V_14 ;
V_82 = V_133 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
V_2 -> V_9 += V_82 ;
F_106 ( V_2 , V_133 ) ;
V_2 -> V_88 = 0 ;
V_2 -> V_111 = 0 ;
V_2 -> V_89 = 0 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
V_135:
F_62 ( V_8 ) ;
V_38:
return - V_117 ;
}
struct V_1 * F_125 ( struct V_1 * V_2 , unsigned int V_132 )
{
struct V_1 * V_45 ;
int V_136 = V_132 - F_90 ( V_2 ) ;
if ( V_136 <= 0 )
V_45 = F_126 ( V_2 , V_52 ) ;
else {
V_45 = F_103 ( V_2 , V_52 ) ;
if ( V_45 && F_119 ( V_45 , F_17 ( V_136 ) , 0 ,
V_52 ) ) {
F_80 ( V_45 ) ;
V_45 = NULL ;
}
}
return V_45 ;
}
struct V_1 * F_127 ( const struct V_1 * V_2 ,
int V_137 , int V_138 ,
T_2 V_24 )
{
struct V_1 * V_107 = F_14 ( V_137 + V_2 -> V_6 + V_138 ,
V_24 , F_109 ( V_2 ) ,
V_62 ) ;
int V_139 = F_90 ( V_2 ) ;
int V_140 , V_141 ;
if ( ! V_107 )
return NULL ;
F_49 ( V_107 , V_137 ) ;
F_112 ( V_107 , V_2 -> V_6 ) ;
V_140 = V_139 ;
V_141 = 0 ;
if ( V_137 <= V_140 )
V_140 = V_137 ;
else
V_141 = V_137 - V_140 ;
if ( F_113 ( V_2 , - V_140 , V_107 -> V_7 + V_141 ,
V_2 -> V_6 + V_140 ) )
F_3 () ;
F_108 ( V_107 , V_2 ) ;
F_106 ( V_107 , V_137 - V_139 ) ;
return V_107 ;
}
int F_128 ( struct V_1 * V_2 , int V_142 )
{
int V_143 ;
int V_134 ;
if ( ! F_123 ( V_2 ) && F_129 ( V_2 ) >= V_142 ) {
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_142 ) ;
return 0 ;
}
V_134 = V_2 -> V_83 + V_142 - ( V_2 -> V_10 - V_2 -> V_9 ) ;
if ( F_45 ( F_123 ( V_2 ) || V_134 > 0 ) ) {
V_143 = F_119 ( V_2 , 0 , V_134 , V_52 ) ;
if ( F_32 ( V_143 ) )
goto V_144;
}
V_143 = F_130 ( V_2 ) ;
if ( F_32 ( V_143 ) )
goto V_144;
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_142 ) ;
return 0 ;
V_144:
F_80 ( V_2 ) ;
return V_143 ;
}
unsigned char * F_131 ( struct V_1 * V_2 , struct V_1 * V_9 , int V_6 )
{
if ( V_9 != V_2 ) {
V_2 -> V_83 += V_6 ;
V_2 -> V_6 += V_6 ;
}
return F_112 ( V_9 , V_6 ) ;
}
unsigned char * F_112 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned char * V_145 = F_122 ( V_2 ) ;
F_132 ( V_2 ) ;
V_2 -> V_9 += V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_32 ( V_2 -> V_9 > V_2 -> V_10 ) )
F_4 ( V_2 , V_6 , F_83 ( 0 ) ) ;
return V_145 ;
}
unsigned char * F_133 ( struct V_1 * V_2 , unsigned int V_6 )
{
V_2 -> V_8 -= V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_32 ( V_2 -> V_8 < V_2 -> V_7 ) )
F_5 ( V_2 , V_6 , F_83 ( 0 ) ) ;
return V_2 -> V_8 ;
}
unsigned char * F_134 ( struct V_1 * V_2 , unsigned int V_6 )
{
return F_135 ( V_2 , V_6 ) ;
}
void F_136 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_2 -> V_6 > V_6 )
F_137 ( V_2 , V_6 ) ;
}
int F_138 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_1 * * V_146 ;
struct V_1 * V_63 ;
int V_66 = F_115 ( V_2 ) ;
int V_147 = F_23 ( V_2 ) -> V_91 ;
int V_81 ;
int V_143 ;
if ( F_123 ( V_2 ) &&
F_32 ( ( V_143 = F_119 ( V_2 , 0 , 0 , V_52 ) ) ) )
return V_143 ;
V_81 = 0 ;
if ( V_66 >= V_6 )
goto V_148;
for (; V_81 < V_147 ; V_81 ++ ) {
int V_10 = V_66 + F_98 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( V_10 < V_6 ) {
V_66 = V_10 ;
continue;
}
F_139 ( & F_23 ( V_2 ) -> V_84 [ V_81 ++ ] , V_6 - V_66 ) ;
V_148:
F_23 ( V_2 ) -> V_91 = V_81 ;
for (; V_81 < V_147 ; V_81 ++ )
F_101 ( V_2 , V_81 ) ;
if ( F_118 ( V_2 ) )
F_57 ( V_2 ) ;
goto V_149;
}
for ( V_146 = & F_23 ( V_2 ) -> V_86 ; ( V_63 = * V_146 ) ;
V_146 = & V_63 -> V_106 ) {
int V_10 = V_66 + V_63 -> V_6 ;
if ( F_121 ( V_63 ) ) {
struct V_1 * V_150 ;
V_150 = F_103 ( V_63 , V_52 ) ;
if ( F_32 ( ! V_150 ) )
return - V_117 ;
V_150 -> V_106 = V_63 -> V_106 ;
F_85 ( V_63 ) ;
V_63 = V_150 ;
* V_146 = V_63 ;
}
if ( V_10 < V_6 ) {
V_66 = V_10 ;
continue;
}
if ( V_10 > V_6 &&
F_32 ( ( V_143 = F_140 ( V_63 , V_6 - V_66 ) ) ) )
return V_143 ;
if ( V_63 -> V_106 )
F_55 ( & V_63 -> V_106 ) ;
break;
}
V_149:
if ( V_6 > F_115 ( V_2 ) ) {
V_2 -> V_83 -= V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
} else {
V_2 -> V_6 = V_6 ;
V_2 -> V_83 = 0 ;
F_141 ( V_2 , V_6 ) ;
}
return 0 ;
}
unsigned char * F_142 ( struct V_1 * V_2 , int V_136 )
{
int V_81 , V_151 , V_152 = ( V_2 -> V_9 + V_136 ) - V_2 -> V_10 ;
if ( V_152 > 0 || F_123 ( V_2 ) ) {
if ( F_119 ( V_2 , 0 , V_152 > 0 ? V_152 + 128 : 0 ,
V_52 ) )
return NULL ;
}
if ( F_113 ( V_2 , F_115 ( V_2 ) , F_122 ( V_2 ) , V_136 ) )
F_3 () ;
if ( ! F_118 ( V_2 ) )
goto V_153;
V_152 = V_136 ;
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_14 = F_98 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( V_14 >= V_152 )
goto V_153;
V_152 -= V_14 ;
}
if ( V_152 ) {
struct V_1 * V_87 = F_23 ( V_2 ) -> V_86 ;
struct V_1 * V_154 = NULL ;
struct V_1 * V_155 = NULL ;
do {
F_120 ( ! V_87 ) ;
if ( V_87 -> V_6 <= V_152 ) {
V_152 -= V_87 -> V_6 ;
V_87 = V_87 -> V_106 ;
V_155 = V_87 ;
} else {
if ( F_121 ( V_87 ) ) {
V_154 = F_103 ( V_87 , V_52 ) ;
if ( ! V_154 )
return NULL ;
V_155 = V_87 -> V_106 ;
V_87 = V_154 ;
} else {
V_155 = V_87 ;
}
if ( ! F_143 ( V_87 , V_152 ) ) {
F_80 ( V_154 ) ;
return NULL ;
}
break;
}
} while ( V_152 );
while ( ( V_87 = F_23 ( V_2 ) -> V_86 ) != V_155 ) {
F_23 ( V_2 ) -> V_86 = V_87 -> V_106 ;
F_80 ( V_87 ) ;
}
if ( V_154 ) {
V_154 -> V_106 = V_87 ;
F_23 ( V_2 ) -> V_86 = V_154 ;
}
}
V_153:
V_152 = V_136 ;
V_151 = 0 ;
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_14 = F_98 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( V_14 <= V_152 ) {
F_101 ( V_2 , V_81 ) ;
V_152 -= V_14 ;
} else {
F_23 ( V_2 ) -> V_84 [ V_151 ] = F_23 ( V_2 ) -> V_84 [ V_81 ] ;
if ( V_152 ) {
F_23 ( V_2 ) -> V_84 [ V_151 ] . V_118 += V_152 ;
F_144 ( & F_23 ( V_2 ) -> V_84 [ V_151 ] , V_152 ) ;
V_152 = 0 ;
}
V_151 ++ ;
}
}
F_23 ( V_2 ) -> V_91 = V_151 ;
V_2 -> V_9 += V_136 ;
V_2 -> V_83 -= V_136 ;
return F_122 ( V_2 ) ;
}
int F_113 ( const struct V_1 * V_2 , int V_66 , void * V_156 , int V_6 )
{
int V_157 = F_115 ( V_2 ) ;
struct V_1 * V_158 ;
int V_81 , V_159 ;
if ( V_66 > ( int ) V_2 -> V_6 - V_6 )
goto V_160;
if ( ( V_159 = V_157 - V_66 ) > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
F_145 ( V_2 , V_66 , V_156 , V_159 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return 0 ;
V_66 += V_159 ;
V_156 += V_159 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_10 ;
T_5 * V_116 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + F_98 ( V_116 ) ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
T_3 * V_115 ;
if ( V_159 > V_6 )
V_159 = V_6 ;
V_115 = F_96 ( F_97 ( V_116 ) ) ;
memcpy ( V_156 ,
V_115 + V_116 -> V_118 + V_66 - V_157 ,
V_159 ) ;
F_99 ( V_115 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return 0 ;
V_66 += V_159 ;
V_156 += V_159 ;
}
V_157 = V_10 ;
}
F_59 (skb, frag_iter) {
int V_10 ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + V_158 -> V_6 ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
if ( F_113 ( V_158 , V_66 - V_157 , V_156 , V_159 ) )
goto V_160;
if ( ( V_6 -= V_159 ) == 0 )
return 0 ;
V_66 += V_159 ;
V_156 += V_159 ;
}
V_157 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_160:
return - V_161 ;
}
static void F_146 ( struct V_162 * V_163 , unsigned int V_81 )
{
F_46 ( V_163 -> V_164 [ V_81 ] ) ;
}
static struct V_54 * F_147 ( struct V_54 * V_54 , unsigned int * V_6 ,
unsigned int * V_66 ,
struct V_165 * V_109 )
{
struct V_166 * V_167 = F_148 ( V_109 ) ;
if ( ! F_149 ( V_109 , V_167 ) )
return NULL ;
* V_6 = F_150 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_37 ( V_167 -> V_54 ) + V_167 -> V_66 ,
F_37 ( V_54 ) + * V_66 , * V_6 ) ;
* V_66 = V_167 -> V_66 ;
V_167 -> V_66 += * V_6 ;
return V_167 -> V_54 ;
}
static bool F_151 ( const struct V_162 * V_163 ,
struct V_54 * V_54 ,
unsigned int V_66 )
{
return V_163 -> V_168 &&
V_163 -> V_164 [ V_163 -> V_168 - 1 ] == V_54 &&
( V_163 -> V_169 [ V_163 -> V_168 - 1 ] . V_66 +
V_163 -> V_169 [ V_163 -> V_168 - 1 ] . V_6 == V_66 ) ;
}
static bool F_152 ( struct V_162 * V_163 ,
struct V_170 * V_171 , struct V_54 * V_54 ,
unsigned int * V_6 , unsigned int V_66 ,
bool V_172 ,
struct V_165 * V_109 )
{
if ( F_32 ( V_163 -> V_168 == V_173 ) )
return true ;
if ( V_172 ) {
V_54 = F_147 ( V_54 , V_6 , & V_66 , V_109 ) ;
if ( ! V_54 )
return true ;
}
if ( F_151 ( V_163 , V_54 , V_66 ) ) {
V_163 -> V_169 [ V_163 -> V_168 - 1 ] . V_6 += * V_6 ;
return false ;
}
F_153 ( V_54 ) ;
V_163 -> V_164 [ V_163 -> V_168 ] = V_54 ;
V_163 -> V_169 [ V_163 -> V_168 ] . V_6 = * V_6 ;
V_163 -> V_169 [ V_163 -> V_168 ] . V_66 = V_66 ;
V_163 -> V_168 ++ ;
return false ;
}
static bool F_154 ( struct V_54 * V_54 , unsigned int V_174 ,
unsigned int V_175 , unsigned int * V_82 ,
unsigned int * V_6 ,
struct V_162 * V_163 , bool V_172 ,
struct V_165 * V_109 ,
struct V_170 * V_171 )
{
if ( ! * V_6 )
return true ;
if ( * V_82 >= V_175 ) {
* V_82 -= V_175 ;
return false ;
}
V_174 += * V_82 ;
V_175 -= * V_82 ;
* V_82 = 0 ;
do {
unsigned int V_176 = F_155 ( * V_6 , V_175 ) ;
if ( F_152 ( V_163 , V_171 , V_54 , & V_176 , V_174 ,
V_172 , V_109 ) )
return true ;
V_174 += V_176 ;
V_175 -= V_176 ;
* V_6 -= V_176 ;
} while ( * V_6 && V_175 );
return false ;
}
static bool F_156 ( struct V_1 * V_2 , struct V_170 * V_171 ,
unsigned int * V_66 , unsigned int * V_6 ,
struct V_162 * V_163 , struct V_165 * V_109 )
{
int V_177 ;
if ( F_154 ( F_157 ( V_2 -> V_8 ) ,
( unsigned long ) V_2 -> V_8 & ( V_64 - 1 ) ,
F_115 ( V_2 ) ,
V_66 , V_6 , V_163 ,
F_158 ( V_2 ) ,
V_109 , V_171 ) )
return true ;
for ( V_177 = 0 ; V_177 < F_23 ( V_2 ) -> V_91 ; V_177 ++ ) {
const T_5 * V_116 = & F_23 ( V_2 ) -> V_84 [ V_177 ] ;
if ( F_154 ( F_97 ( V_116 ) ,
V_116 -> V_118 , F_98 ( V_116 ) ,
V_66 , V_6 , V_163 , false , V_109 , V_171 ) )
return true ;
}
return false ;
}
int F_159 ( struct V_1 * V_2 , unsigned int V_66 ,
struct V_170 * V_171 , unsigned int V_178 ,
unsigned int V_15 )
{
struct V_179 V_169 [ V_173 ] ;
struct V_54 * V_164 [ V_173 ] ;
struct V_162 V_163 = {
. V_164 = V_164 ,
. V_169 = V_169 ,
. V_180 = V_173 ,
. V_15 = V_15 ,
. V_181 = & V_182 ,
. V_183 = F_146 ,
} ;
struct V_1 * V_158 ;
struct V_165 * V_109 = V_2 -> V_109 ;
int V_184 = 0 ;
if ( F_156 ( V_2 , V_171 , & V_66 , & V_178 , & V_163 , V_109 ) )
goto V_149;
else if ( ! V_178 )
goto V_149;
F_59 (skb, frag_iter) {
if ( ! V_178 )
break;
if ( F_156 ( V_158 , V_171 , & V_66 , & V_178 , & V_163 , V_109 ) )
break;
}
V_149:
if ( V_163 . V_168 ) {
F_160 ( V_109 ) ;
V_184 = F_161 ( V_171 , & V_163 ) ;
F_162 ( V_109 ) ;
}
return V_184 ;
}
int F_163 ( struct V_1 * V_2 , int V_66 , const void * V_185 , int V_6 )
{
int V_157 = F_115 ( V_2 ) ;
struct V_1 * V_158 ;
int V_81 , V_159 ;
if ( V_66 > ( int ) V_2 -> V_6 - V_6 )
goto V_160;
if ( ( V_159 = V_157 - V_66 ) > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
F_164 ( V_2 , V_66 , V_185 , V_159 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return 0 ;
V_66 += V_159 ;
V_185 += V_159 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
int V_10 ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + F_98 ( V_63 ) ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
T_3 * V_115 ;
if ( V_159 > V_6 )
V_159 = V_6 ;
V_115 = F_96 ( F_97 ( V_63 ) ) ;
memcpy ( V_115 + V_63 -> V_118 + V_66 - V_157 ,
V_185 , V_159 ) ;
F_99 ( V_115 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return 0 ;
V_66 += V_159 ;
V_185 += V_159 ;
}
V_157 = V_10 ;
}
F_59 (skb, frag_iter) {
int V_10 ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + V_158 -> V_6 ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
if ( F_163 ( V_158 , V_66 - V_157 ,
V_185 , V_159 ) )
goto V_160;
if ( ( V_6 -= V_159 ) == 0 )
return 0 ;
V_66 += V_159 ;
V_185 += V_159 ;
}
V_157 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_160:
return - V_161 ;
}
T_7 F_165 ( const struct V_1 * V_2 , int V_66 , int V_6 ,
T_7 V_186 , const struct V_187 * V_181 )
{
int V_157 = F_115 ( V_2 ) ;
int V_81 , V_159 = V_157 - V_66 ;
struct V_1 * V_158 ;
int V_188 = 0 ;
if ( V_159 > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
V_186 = V_181 -> V_189 ( V_2 -> V_8 + V_66 , V_159 , V_186 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return V_186 ;
V_66 += V_159 ;
V_188 = V_159 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_10 ;
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + F_98 ( V_63 ) ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
T_7 V_190 ;
T_3 * V_115 ;
if ( V_159 > V_6 )
V_159 = V_6 ;
V_115 = F_96 ( F_97 ( V_63 ) ) ;
V_190 = V_181 -> V_189 ( V_115 + V_63 -> V_118 +
V_66 - V_157 , V_159 , 0 ) ;
F_99 ( V_115 ) ;
V_186 = V_181 -> V_191 ( V_186 , V_190 , V_188 , V_159 ) ;
if ( ! ( V_6 -= V_159 ) )
return V_186 ;
V_66 += V_159 ;
V_188 += V_159 ;
}
V_157 = V_10 ;
}
F_59 (skb, frag_iter) {
int V_10 ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + V_158 -> V_6 ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
T_7 V_190 ;
if ( V_159 > V_6 )
V_159 = V_6 ;
V_190 = F_165 ( V_158 , V_66 - V_157 ,
V_159 , 0 , V_181 ) ;
V_186 = V_181 -> V_191 ( V_186 , V_190 , V_188 , V_159 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return V_186 ;
V_66 += V_159 ;
V_188 += V_159 ;
}
V_157 = V_10 ;
}
F_120 ( V_6 ) ;
return V_186 ;
}
T_7 F_166 ( const struct V_1 * V_2 , int V_66 ,
int V_6 , T_7 V_186 )
{
const struct V_187 V_181 = {
. V_189 = V_192 ,
. V_191 = V_193 ,
} ;
return F_165 ( V_2 , V_66 , V_6 , V_186 , & V_181 ) ;
}
T_7 F_167 ( const struct V_1 * V_2 , int V_66 ,
T_3 * V_156 , int V_6 , T_7 V_186 )
{
int V_157 = F_115 ( V_2 ) ;
int V_81 , V_159 = V_157 - V_66 ;
struct V_1 * V_158 ;
int V_188 = 0 ;
if ( V_159 > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
V_186 = F_168 ( V_2 -> V_8 + V_66 , V_156 ,
V_159 , V_186 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return V_186 ;
V_66 += V_159 ;
V_156 += V_159 ;
V_188 = V_159 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_10 ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + F_98 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
T_7 V_190 ;
T_3 * V_115 ;
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
if ( V_159 > V_6 )
V_159 = V_6 ;
V_115 = F_96 ( F_97 ( V_63 ) ) ;
V_190 = F_168 ( V_115 +
V_63 -> V_118 +
V_66 - V_157 , V_156 ,
V_159 , 0 ) ;
F_99 ( V_115 ) ;
V_186 = F_169 ( V_186 , V_190 , V_188 ) ;
if ( ! ( V_6 -= V_159 ) )
return V_186 ;
V_66 += V_159 ;
V_156 += V_159 ;
V_188 += V_159 ;
}
V_157 = V_10 ;
}
F_59 (skb, frag_iter) {
T_7 V_190 ;
int V_10 ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + V_158 -> V_6 ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
V_190 = F_167 ( V_158 ,
V_66 - V_157 ,
V_156 , V_159 , 0 ) ;
V_186 = F_169 ( V_186 , V_190 , V_188 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return V_186 ;
V_66 += V_159 ;
V_156 += V_159 ;
V_188 += V_159 ;
}
V_157 = V_10 ;
}
F_120 ( V_6 ) ;
return V_186 ;
}
unsigned int
F_170 ( const struct V_1 * V_185 )
{
unsigned int V_194 = 0 ;
if ( ! V_185 -> V_53 ||
F_115 ( V_185 ) < V_195 ||
F_23 ( V_185 ) -> V_91 >= V_173 )
V_194 = F_115 ( V_185 ) ;
if ( F_118 ( V_185 ) )
V_194 = V_185 -> V_6 ;
return V_194 ;
}
int
F_171 ( struct V_1 * V_156 , struct V_1 * V_185 , int V_6 , int V_194 )
{
int V_81 , V_196 = 0 ;
int V_175 = 0 ;
int V_184 ;
struct V_54 * V_54 ;
unsigned int V_66 ;
F_120 ( ! V_185 -> V_53 && ! V_194 ) ;
if ( V_6 <= F_129 ( V_156 ) )
return F_113 ( V_185 , 0 , F_112 ( V_156 , V_6 ) , V_6 ) ;
if ( V_194 ) {
V_184 = F_113 ( V_185 , 0 , F_112 ( V_156 , V_194 ) , V_194 ) ;
if ( F_32 ( V_184 ) )
return V_184 ;
V_6 -= V_194 ;
} else {
V_175 = F_150 ( int , F_115 ( V_185 ) , V_6 ) ;
if ( V_175 ) {
V_54 = F_47 ( V_185 -> V_7 ) ;
V_66 = V_185 -> V_8 - ( unsigned char * ) F_37 ( V_54 ) ;
F_102 ( V_156 , 0 , V_54 , V_66 , V_175 ) ;
F_153 ( V_54 ) ;
V_196 = 1 ;
V_6 -= V_175 ;
}
}
V_156 -> V_27 += V_6 + V_175 ;
V_156 -> V_6 += V_6 + V_175 ;
V_156 -> V_83 += V_6 + V_175 ;
if ( F_32 ( F_104 ( V_185 , V_52 ) ) ) {
F_84 ( V_185 ) ;
return - V_117 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_185 ) -> V_91 ; V_81 ++ ) {
if ( ! V_6 )
break;
F_23 ( V_156 ) -> V_84 [ V_196 ] = F_23 ( V_185 ) -> V_84 [ V_81 ] ;
F_23 ( V_156 ) -> V_84 [ V_196 ] . V_14 = F_150 ( int , F_23 ( V_156 ) -> V_84 [ V_196 ] . V_14 , V_6 ) ;
V_6 -= F_23 ( V_156 ) -> V_84 [ V_196 ] . V_14 ;
F_117 ( V_156 , V_196 ) ;
V_196 ++ ;
}
F_23 ( V_156 ) -> V_91 = V_196 ;
return 0 ;
}
void F_172 ( const struct V_1 * V_2 , T_3 * V_156 )
{
T_7 V_186 ;
long V_197 ;
if ( V_2 -> V_119 == V_120 )
V_197 = F_173 ( V_2 ) ;
else
V_197 = F_115 ( V_2 ) ;
F_120 ( V_197 > F_115 ( V_2 ) ) ;
F_116 ( V_2 , V_156 , V_197 ) ;
V_186 = 0 ;
if ( V_197 != V_2 -> V_6 )
V_186 = F_167 ( V_2 , V_197 , V_156 + V_197 ,
V_2 -> V_6 - V_197 , 0 ) ;
if ( V_2 -> V_119 == V_120 ) {
long V_198 = V_197 + V_2 -> V_199 ;
* ( ( V_200 * ) ( V_156 + V_198 ) ) = F_174 ( V_186 ) ;
}
}
struct V_1 * F_175 ( struct V_201 * V_87 )
{
unsigned long V_15 ;
struct V_1 * V_202 ;
F_176 ( & V_87 -> V_203 , V_15 ) ;
V_202 = F_177 ( V_87 ) ;
F_178 ( & V_87 -> V_203 , V_15 ) ;
return V_202 ;
}
struct V_1 * F_179 ( struct V_201 * V_87 )
{
unsigned long V_15 ;
struct V_1 * V_202 ;
F_176 ( & V_87 -> V_203 , V_15 ) ;
V_202 = F_180 ( V_87 ) ;
F_178 ( & V_87 -> V_203 , V_15 ) ;
return V_202 ;
}
void F_181 ( struct V_201 * V_87 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_175 ( V_87 ) ) != NULL )
F_80 ( V_2 ) ;
}
void F_182 ( struct V_201 * V_87 , struct V_1 * V_204 )
{
unsigned long V_15 ;
F_176 ( & V_87 -> V_203 , V_15 ) ;
F_183 ( V_87 , V_204 ) ;
F_178 ( & V_87 -> V_203 , V_15 ) ;
}
void F_184 ( struct V_201 * V_87 , struct V_1 * V_204 )
{
unsigned long V_15 ;
F_176 ( & V_87 -> V_203 , V_15 ) ;
F_185 ( V_87 , V_204 ) ;
F_178 ( & V_87 -> V_203 , V_15 ) ;
}
void F_186 ( struct V_1 * V_2 , struct V_201 * V_87 )
{
unsigned long V_15 ;
F_176 ( & V_87 -> V_203 , V_15 ) ;
F_187 ( V_2 , V_87 ) ;
F_178 ( & V_87 -> V_203 , V_15 ) ;
}
void F_188 ( struct V_1 * V_127 , struct V_1 * V_204 , struct V_201 * V_87 )
{
unsigned long V_15 ;
F_176 ( & V_87 -> V_203 , V_15 ) ;
F_189 ( V_87 , V_127 , V_204 ) ;
F_178 ( & V_87 -> V_203 , V_15 ) ;
}
void F_190 ( struct V_1 * V_127 , struct V_1 * V_204 , struct V_201 * V_87 )
{
unsigned long V_15 ;
F_176 ( & V_87 -> V_203 , V_15 ) ;
F_191 ( V_204 , V_127 -> V_108 , V_127 , V_87 ) ;
F_178 ( & V_87 -> V_203 , V_15 ) ;
}
static inline void F_192 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_8 V_6 , const int V_188 )
{
int V_81 ;
F_145 ( V_2 , V_6 , F_112 ( V_44 , V_188 - V_6 ) ,
V_188 - V_6 ) ;
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ )
F_23 ( V_44 ) -> V_84 [ V_81 ] = F_23 ( V_2 ) -> V_84 [ V_81 ] ;
F_23 ( V_44 ) -> V_91 = F_23 ( V_2 ) -> V_91 ;
F_23 ( V_2 ) -> V_91 = 0 ;
V_44 -> V_83 = V_2 -> V_83 ;
V_44 -> V_6 += V_44 -> V_83 ;
V_2 -> V_83 = 0 ;
V_2 -> V_6 = V_6 ;
F_141 ( V_2 , V_6 ) ;
}
static inline void F_193 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_8 V_6 , int V_188 )
{
int V_81 , V_151 = 0 ;
const int V_147 = F_23 ( V_2 ) -> V_91 ;
F_23 ( V_2 ) -> V_91 = 0 ;
V_44 -> V_6 = V_44 -> V_83 = V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_83 = V_6 - V_188 ;
for ( V_81 = 0 ; V_81 < V_147 ; V_81 ++ ) {
int V_14 = F_98 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( V_188 + V_14 > V_6 ) {
F_23 ( V_44 ) -> V_84 [ V_151 ] = F_23 ( V_2 ) -> V_84 [ V_81 ] ;
if ( V_188 < V_6 ) {
F_117 ( V_2 , V_81 ) ;
F_23 ( V_44 ) -> V_84 [ 0 ] . V_118 += V_6 - V_188 ;
F_144 ( & F_23 ( V_44 ) -> V_84 [ 0 ] , V_6 - V_188 ) ;
F_139 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] , V_6 - V_188 ) ;
F_23 ( V_2 ) -> V_91 ++ ;
}
V_151 ++ ;
} else
F_23 ( V_2 ) -> V_91 ++ ;
V_188 += V_14 ;
}
F_23 ( V_44 ) -> V_91 = V_151 ;
}
void F_194 ( struct V_1 * V_2 , struct V_1 * V_44 , const T_8 V_6 )
{
int V_188 = F_115 ( V_2 ) ;
F_23 ( V_44 ) -> V_92 = F_23 ( V_2 ) -> V_92 & V_205 ;
if ( V_6 < V_188 )
F_192 ( V_2 , V_44 , V_6 , V_188 ) ;
else
F_193 ( V_2 , V_44 , V_6 , V_188 ) ;
}
static int F_195 ( struct V_1 * V_2 )
{
return F_123 ( V_2 ) && F_119 ( V_2 , 0 , 0 , V_52 ) ;
}
int F_196 ( struct V_1 * V_206 , struct V_1 * V_2 , int V_207 )
{
int V_185 , V_156 , V_208 , V_209 ;
struct V_210 * V_211 , * V_212 ;
F_120 ( V_207 > V_2 -> V_6 ) ;
F_120 ( F_115 ( V_2 ) ) ;
V_209 = V_207 ;
V_185 = 0 ;
V_156 = F_23 ( V_206 ) -> V_91 ;
V_211 = & F_23 ( V_2 ) -> V_84 [ V_185 ] ;
if ( ! V_156 ||
! F_197 ( V_206 , V_156 , F_97 ( V_211 ) ,
V_211 -> V_118 ) ) {
V_208 = - 1 ;
} else {
V_208 = V_156 - 1 ;
V_209 -= F_98 ( V_211 ) ;
if ( V_209 < 0 ) {
if ( F_195 ( V_2 ) ||
F_195 ( V_206 ) )
return 0 ;
V_211 = & F_23 ( V_2 ) -> V_84 [ V_185 ] ;
V_212 = & F_23 ( V_206 ) -> V_84 [ V_208 ] ;
F_54 ( V_212 , V_207 ) ;
F_144 ( V_211 , V_207 ) ;
V_211 -> V_118 += V_207 ;
goto V_213;
}
V_185 ++ ;
}
if ( ( V_207 == V_2 -> V_6 ) &&
( F_23 ( V_2 ) -> V_91 - V_185 ) > ( V_173 - V_156 ) )
return 0 ;
if ( F_195 ( V_2 ) || F_195 ( V_206 ) )
return 0 ;
while ( ( V_209 > 0 ) && ( V_185 < F_23 ( V_2 ) -> V_91 ) ) {
if ( V_156 == V_173 )
return 0 ;
V_211 = & F_23 ( V_2 ) -> V_84 [ V_185 ] ;
V_212 = & F_23 ( V_206 ) -> V_84 [ V_156 ] ;
if ( V_209 >= F_98 ( V_211 ) ) {
* V_212 = * V_211 ;
V_209 -= F_98 ( V_211 ) ;
V_185 ++ ;
V_156 ++ ;
} else {
F_198 ( V_211 ) ;
V_212 -> V_54 = V_211 -> V_54 ;
V_212 -> V_118 = V_211 -> V_118 ;
F_139 ( V_212 , V_209 ) ;
V_211 -> V_118 += V_209 ;
F_144 ( V_211 , V_209 ) ;
V_209 = 0 ;
V_156 ++ ;
break;
}
}
F_23 ( V_206 ) -> V_91 = V_156 ;
if ( V_208 >= 0 ) {
V_211 = & F_23 ( V_2 ) -> V_84 [ 0 ] ;
V_212 = & F_23 ( V_206 ) -> V_84 [ V_208 ] ;
F_54 ( V_212 , F_98 ( V_211 ) ) ;
F_65 ( V_211 ) ;
}
V_156 = 0 ;
while ( V_185 < F_23 ( V_2 ) -> V_91 )
F_23 ( V_2 ) -> V_84 [ V_156 ++ ] = F_23 ( V_2 ) -> V_84 [ V_185 ++ ] ;
F_23 ( V_2 ) -> V_91 = V_156 ;
F_120 ( V_209 > 0 && ! F_23 ( V_2 ) -> V_91 ) ;
V_213:
V_206 -> V_119 = V_120 ;
V_2 -> V_119 = V_120 ;
V_2 -> V_6 -= V_207 ;
V_2 -> V_83 -= V_207 ;
V_2 -> V_27 -= V_207 ;
V_206 -> V_6 += V_207 ;
V_206 -> V_83 += V_207 ;
V_206 -> V_27 += V_207 ;
return V_207 ;
}
void F_199 ( struct V_1 * V_2 , unsigned int V_185 ,
unsigned int V_156 , struct V_214 * V_215 )
{
V_215 -> V_216 = V_185 ;
V_215 -> V_217 = V_156 ;
V_215 -> V_218 = V_215 -> V_219 = V_2 ;
V_215 -> V_220 = V_215 -> V_221 = 0 ;
V_215 -> V_222 = NULL ;
}
unsigned int F_200 ( unsigned int V_223 , const T_3 * * V_8 ,
struct V_214 * V_215 )
{
unsigned int V_224 , V_225 = V_223 + V_215 -> V_216 ;
T_5 * V_63 ;
if ( F_32 ( V_225 >= V_215 -> V_217 ) ) {
if ( V_215 -> V_222 ) {
F_99 ( V_215 -> V_222 ) ;
V_215 -> V_222 = NULL ;
}
return 0 ;
}
V_226:
V_224 = F_115 ( V_215 -> V_219 ) + V_215 -> V_221 ;
if ( V_225 < V_224 && ! V_215 -> V_222 ) {
* V_8 = V_215 -> V_219 -> V_8 + ( V_225 - V_215 -> V_221 ) ;
return V_224 - V_225 ;
}
if ( V_215 -> V_220 == 0 && ! V_215 -> V_222 )
V_215 -> V_221 += F_115 ( V_215 -> V_219 ) ;
while ( V_215 -> V_220 < F_23 ( V_215 -> V_219 ) -> V_91 ) {
V_63 = & F_23 ( V_215 -> V_219 ) -> V_84 [ V_215 -> V_220 ] ;
V_224 = F_98 ( V_63 ) + V_215 -> V_221 ;
if ( V_225 < V_224 ) {
if ( ! V_215 -> V_222 )
V_215 -> V_222 = F_96 ( F_97 ( V_63 ) ) ;
* V_8 = ( T_3 * ) V_215 -> V_222 + V_63 -> V_118 +
( V_225 - V_215 -> V_221 ) ;
return V_224 - V_225 ;
}
if ( V_215 -> V_222 ) {
F_99 ( V_215 -> V_222 ) ;
V_215 -> V_222 = NULL ;
}
V_215 -> V_220 ++ ;
V_215 -> V_221 += F_98 ( V_63 ) ;
}
if ( V_215 -> V_222 ) {
F_99 ( V_215 -> V_222 ) ;
V_215 -> V_222 = NULL ;
}
if ( V_215 -> V_218 == V_215 -> V_219 && F_118 ( V_215 -> V_218 ) ) {
V_215 -> V_219 = F_23 ( V_215 -> V_218 ) -> V_86 ;
V_215 -> V_220 = 0 ;
goto V_226;
} else if ( V_215 -> V_219 -> V_106 ) {
V_215 -> V_219 = V_215 -> V_219 -> V_106 ;
V_215 -> V_220 = 0 ;
goto V_226;
}
return 0 ;
}
void F_201 ( struct V_214 * V_215 )
{
if ( V_215 -> V_222 )
F_99 ( V_215 -> V_222 ) ;
}
static unsigned int F_202 ( unsigned int V_66 , const T_3 * * V_227 ,
struct V_228 * V_229 ,
struct V_230 * V_231 )
{
return F_200 ( V_66 , V_227 , F_203 ( V_231 ) ) ;
}
static void F_204 ( struct V_228 * V_229 , struct V_230 * V_231 )
{
F_201 ( F_203 ( V_231 ) ) ;
}
unsigned int F_205 ( struct V_1 * V_2 , unsigned int V_185 ,
unsigned int V_156 , struct V_228 * V_232 ,
struct V_230 * V_231 )
{
unsigned int V_184 ;
V_232 -> V_233 = F_202 ;
V_232 -> V_234 = F_204 ;
F_199 ( V_2 , V_185 , V_156 , F_203 ( V_231 ) ) ;
V_184 = F_206 ( V_232 , V_231 ) ;
return ( V_184 <= V_156 - V_185 ? V_184 : V_235 ) ;
}
int F_207 ( struct V_165 * V_109 , struct V_1 * V_2 ,
int (* F_208)( void * V_185 , char * V_156 , int V_66 ,
int V_6 , int V_236 , struct V_1 * V_2 ) ,
void * V_185 , int V_72 )
{
int V_237 = F_23 ( V_2 ) -> V_91 ;
int V_159 ;
int V_66 = 0 ;
int V_184 ;
struct V_166 * V_167 = & V_238 -> V_239 ;
do {
if ( V_237 >= V_173 )
return - V_240 ;
if ( ! F_149 ( V_109 , V_167 ) )
return - V_117 ;
V_159 = F_150 ( int , V_72 , V_167 -> V_14 - V_167 -> V_66 ) ;
V_184 = F_208 ( V_185 , F_37 ( V_167 -> V_54 ) + V_167 -> V_66 ,
V_66 , V_159 , 0 , V_2 ) ;
if ( V_184 < 0 )
return - V_161 ;
F_52 ( V_2 , V_237 , V_167 -> V_54 , V_167 -> V_66 ,
V_159 ) ;
V_237 ++ ;
V_167 -> V_66 += V_159 ;
F_153 ( V_167 -> V_54 ) ;
V_2 -> V_27 += V_159 ;
F_35 ( V_159 , & V_109 -> V_241 ) ;
V_2 -> V_6 += V_159 ;
V_2 -> V_83 += V_159 ;
V_66 += V_159 ;
V_72 -= V_159 ;
} while ( V_72 > 0 );
return 0 ;
}
unsigned char * F_209 ( struct V_1 * V_2 , unsigned int V_6 )
{
F_120 ( V_6 > V_2 -> V_6 ) ;
V_2 -> V_6 -= V_6 ;
F_120 ( V_2 -> V_6 < V_2 -> V_83 ) ;
F_210 ( V_2 , V_2 -> V_8 , V_6 ) ;
return V_2 -> V_8 += V_6 ;
}
struct V_1 * F_211 ( struct V_1 * V_242 ,
T_9 V_243 )
{
struct V_1 * V_105 = NULL ;
struct V_1 * V_9 = NULL ;
struct V_1 * V_244 = F_23 ( V_242 ) -> V_86 ;
T_5 * V_63 = F_23 ( V_242 ) -> V_84 ;
unsigned int V_245 = F_23 ( V_242 ) -> V_128 ;
unsigned int V_246 = V_242 -> V_8 - F_212 ( V_242 ) ;
struct V_1 * V_247 = V_242 ;
unsigned int V_66 = V_246 ;
unsigned int V_248 = F_213 ( V_242 ) ;
unsigned int V_132 ;
unsigned int V_6 ;
T_10 V_249 ;
bool V_186 ;
int V_250 = ! ! ( V_243 & V_251 ) ;
int V_147 = F_23 ( V_242 ) -> V_91 ;
int V_143 = - V_117 ;
int V_81 = 0 ;
int V_188 ;
int V_252 ;
F_214 ( V_242 , V_246 ) ;
V_249 = F_215 ( V_242 , & V_252 ) ;
if ( F_32 ( ! V_249 ) )
return F_216 ( - V_253 ) ;
V_186 = ! V_242 -> V_254 &&
! ! F_217 ( V_243 , V_249 ) ;
V_132 = F_90 ( V_242 ) ;
V_188 = F_115 ( V_242 ) ;
do {
struct V_1 * V_255 ;
T_5 * V_256 ;
int V_257 ;
int V_14 ;
V_6 = V_242 -> V_6 - V_66 ;
if ( V_6 > V_245 )
V_6 = V_245 ;
V_257 = F_115 ( V_242 ) - V_66 ;
if ( V_257 < 0 )
V_257 = 0 ;
if ( V_257 > V_6 || ! V_250 )
V_257 = V_6 ;
if ( ! V_257 && V_81 >= V_147 && F_115 ( V_244 ) &&
( F_115 ( V_244 ) == V_6 || V_250 ) ) {
F_120 ( F_115 ( V_244 ) > V_6 ) ;
V_81 = 0 ;
V_147 = F_23 ( V_244 ) -> V_91 ;
V_63 = F_23 ( V_244 ) -> V_84 ;
V_247 = V_244 ;
V_188 += F_115 ( V_244 ) ;
while ( V_188 < V_66 + V_6 ) {
F_120 ( V_81 >= V_147 ) ;
V_14 = F_98 ( V_63 ) ;
if ( V_188 + V_14 > V_66 + V_6 )
break;
V_81 ++ ;
V_188 += V_14 ;
V_63 ++ ;
}
V_255 = F_103 ( V_244 , V_52 ) ;
V_244 = V_244 -> V_106 ;
if ( F_32 ( ! V_255 ) )
goto V_143;
if ( F_32 ( F_140 ( V_255 , V_6 ) ) ) {
F_80 ( V_255 ) ;
goto V_143;
}
V_257 = F_111 ( V_255 ) ;
if ( F_218 ( V_255 , V_246 + V_132 ) ) {
F_80 ( V_255 ) ;
goto V_143;
}
V_255 -> V_27 += F_111 ( V_255 ) - V_257 ;
F_69 ( V_255 ) ;
F_214 ( V_255 , V_246 ) ;
} else {
V_255 = F_14 ( V_257 + V_246 + V_132 ,
V_52 , F_109 ( V_242 ) ,
V_62 ) ;
if ( F_32 ( ! V_255 ) )
goto V_143;
F_49 ( V_255 , V_132 ) ;
F_219 ( V_255 , V_246 ) ;
}
if ( V_105 )
V_9 -> V_106 = V_255 ;
else
V_105 = V_255 ;
V_9 = V_255 ;
F_89 ( V_255 , V_242 ) ;
F_106 ( V_255 , F_90 ( V_255 ) - V_132 ) ;
F_220 ( V_255 ) ;
F_145 ( V_242 , - V_248 ,
V_255 -> V_8 - V_248 ,
V_246 + V_248 ) ;
if ( V_255 -> V_6 == V_6 + V_246 )
goto V_258;
if ( ! V_250 && ! V_255 -> V_259 ) {
V_255 -> V_119 = V_260 ;
V_255 -> V_186 = F_167 ( V_242 , V_66 ,
F_112 ( V_255 , V_6 ) ,
V_6 , 0 ) ;
F_221 ( V_255 ) -> V_121 =
F_90 ( V_255 ) + V_246 ;
continue;
}
V_256 = F_23 ( V_255 ) -> V_84 ;
F_145 ( V_242 , V_66 ,
F_112 ( V_255 , V_257 ) , V_257 ) ;
F_23 ( V_255 ) -> V_92 = F_23 ( V_242 ) -> V_92 &
V_205 ;
while ( V_188 < V_66 + V_6 ) {
if ( V_81 >= V_147 ) {
F_120 ( F_115 ( V_244 ) ) ;
V_81 = 0 ;
V_147 = F_23 ( V_244 ) -> V_91 ;
V_63 = F_23 ( V_244 ) -> V_84 ;
V_247 = V_244 ;
F_120 ( ! V_147 ) ;
V_244 = V_244 -> V_106 ;
}
if ( F_32 ( F_23 ( V_255 ) -> V_91 >=
V_173 ) ) {
F_222 (
L_3 ,
V_188 , V_245 ) ;
goto V_143;
}
if ( F_32 ( F_104 ( V_247 , V_52 ) ) )
goto V_143;
* V_256 = * V_63 ;
F_198 ( V_256 ) ;
V_14 = F_98 ( V_256 ) ;
if ( V_188 < V_66 ) {
V_256 -> V_118 += V_66 - V_188 ;
F_144 ( V_256 , V_66 - V_188 ) ;
}
F_23 ( V_255 ) -> V_91 ++ ;
if ( V_188 + V_14 <= V_66 + V_6 ) {
V_81 ++ ;
V_63 ++ ;
V_188 += V_14 ;
} else {
F_144 ( V_256 , V_188 + V_14 - ( V_66 + V_6 ) ) ;
goto V_261;
}
V_256 ++ ;
}
V_261:
V_255 -> V_83 = V_6 - V_257 ;
V_255 -> V_6 += V_255 -> V_83 ;
V_255 -> V_27 += V_255 -> V_83 ;
V_258:
if ( ! V_186 && ! V_255 -> V_259 ) {
V_255 -> V_186 = F_166 ( V_255 , V_246 ,
V_255 -> V_6 - V_246 , 0 ) ;
V_255 -> V_119 = V_260 ;
F_221 ( V_255 ) -> V_121 =
F_90 ( V_255 ) + V_246 ;
}
} while ( ( V_66 += V_6 ) < V_242 -> V_6 );
V_105 -> V_108 = V_9 ;
if ( V_242 -> V_100 == V_262 ) {
F_223 ( V_9 -> V_27 , V_242 -> V_27 ) ;
F_223 ( V_9 -> V_100 , V_242 -> V_100 ) ;
F_223 ( V_9 -> V_109 , V_242 -> V_109 ) ;
}
return V_105 ;
V_143:
F_56 ( V_105 ) ;
return F_216 ( V_143 ) ;
}
int F_224 ( struct V_1 * * V_7 , struct V_1 * V_2 )
{
struct V_32 * V_263 , * V_264 = F_23 ( V_2 ) ;
unsigned int V_66 = F_225 ( V_2 ) ;
unsigned int V_265 = F_115 ( V_2 ) ;
struct V_1 * V_255 , * V_266 , * V_267 = * V_7 ;
unsigned int V_6 = F_226 ( V_2 ) ;
unsigned int V_268 ;
unsigned int V_132 ;
if ( F_32 ( V_267 -> V_6 + V_6 >= 65536 ) )
return - V_269 ;
V_266 = F_227 ( V_267 ) -> V_270 ;
V_263 = F_23 ( V_266 ) ;
if ( V_265 <= V_66 ) {
T_5 * V_63 ;
T_5 * V_271 ;
int V_81 = V_264 -> V_91 ;
int V_91 = V_263 -> V_91 + V_81 ;
if ( V_91 > V_173 )
goto V_208;
V_66 -= V_265 ;
V_263 -> V_91 = V_91 ;
V_264 -> V_91 = 0 ;
V_63 = V_263 -> V_84 + V_91 ;
V_271 = V_264 -> V_84 + V_81 ;
do {
* -- V_63 = * -- V_271 ;
} while ( -- V_81 );
V_63 -> V_118 += V_66 ;
F_144 ( V_63 , V_66 ) ;
V_268 = V_2 -> V_27 -
F_21 ( F_111 ( V_2 ) ) ;
V_2 -> V_27 -= V_2 -> V_83 ;
V_2 -> V_6 -= V_2 -> V_83 ;
V_2 -> V_83 = 0 ;
F_227 ( V_2 ) -> free = V_272 ;
goto V_149;
} else if ( V_2 -> V_53 ) {
int V_91 = V_263 -> V_91 ;
T_5 * V_63 = V_263 -> V_84 + V_91 ;
struct V_54 * V_54 = F_47 ( V_2 -> V_7 ) ;
unsigned int V_273 = V_265 - V_66 ;
unsigned int V_274 ;
if ( V_91 + 1 + V_264 -> V_91 > V_173 )
goto V_208;
V_274 = V_2 -> V_8 -
( unsigned char * ) F_37 ( V_54 ) +
V_66 ;
V_263 -> V_91 = V_91 + 1 + V_264 -> V_91 ;
V_63 -> V_54 . V_267 = V_54 ;
V_63 -> V_118 = V_274 ;
F_139 ( V_63 , V_273 ) ;
memcpy ( V_63 + 1 , V_264 -> V_84 , sizeof( * V_63 ) * V_264 -> V_91 ) ;
V_268 = V_2 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
F_227 ( V_2 ) -> free = V_275 ;
goto V_149;
}
V_263 = F_23 ( V_267 ) ;
if ( V_263 -> V_86 )
goto V_208;
if ( F_226 ( V_267 ) != V_263 -> V_128 )
return - V_269 ;
V_132 = F_90 ( V_267 ) ;
V_255 = F_228 ( V_132 + F_225 ( V_267 ) , V_52 ) ;
if ( F_32 ( ! V_255 ) )
return - V_117 ;
F_89 ( V_255 , V_267 ) ;
V_255 -> V_110 = V_267 -> V_110 ;
F_49 ( V_255 , V_132 ) ;
F_219 ( V_255 , F_225 ( V_267 ) ) ;
F_229 ( V_255 , F_212 ( V_267 ) - V_267 -> V_8 ) ;
F_230 ( V_255 , F_231 ( V_267 ) ) ;
F_232 ( V_255 , F_233 ( V_267 ) ) ;
F_234 ( V_267 , F_225 ( V_267 ) ) ;
memcpy ( F_212 ( V_255 ) , F_212 ( V_267 ) ,
V_267 -> V_8 - F_212 ( V_267 ) ) ;
F_23 ( V_255 ) -> V_86 = V_267 ;
F_23 ( V_255 ) -> V_128 = V_263 -> V_128 ;
V_263 -> V_128 = 0 ;
F_235 ( V_267 ) ;
F_227 ( V_255 ) -> V_270 = V_267 ;
V_255 -> V_83 += V_267 -> V_6 ;
V_255 -> V_27 += V_267 -> V_27 ;
V_255 -> V_6 += V_267 -> V_6 ;
* V_7 = V_255 ;
V_255 -> V_106 = V_267 -> V_106 ;
V_267 -> V_106 = NULL ;
V_267 = V_255 ;
V_208:
V_268 = V_2 -> V_27 ;
if ( V_66 > V_265 ) {
unsigned int V_152 = V_66 - V_265 ;
V_264 -> V_84 [ 0 ] . V_118 += V_152 ;
F_144 ( & V_264 -> V_84 [ 0 ] , V_152 ) ;
V_2 -> V_83 -= V_152 ;
V_2 -> V_6 -= V_152 ;
V_66 = V_265 ;
}
F_234 ( V_2 , V_66 ) ;
if ( F_227 ( V_267 ) -> V_270 == V_267 )
F_23 ( V_267 ) -> V_86 = V_2 ;
else
F_227 ( V_267 ) -> V_270 -> V_106 = V_2 ;
F_227 ( V_267 ) -> V_270 = V_2 ;
F_235 ( V_2 ) ;
V_266 = V_267 ;
V_149:
F_227 ( V_267 ) -> V_276 ++ ;
V_267 -> V_83 += V_6 ;
V_267 -> V_27 += V_268 ;
V_267 -> V_6 += V_6 ;
if ( V_266 != V_267 ) {
V_266 -> V_83 += V_6 ;
V_266 -> V_27 += V_268 ;
V_266 -> V_6 += V_6 ;
}
F_227 ( V_2 ) -> V_277 = 1 ;
return 0 ;
}
void T_11 F_236 ( void )
{
V_25 = F_237 ( L_4 ,
sizeof( struct V_1 ) ,
0 ,
V_278 | V_279 ,
NULL ) ;
V_35 = F_237 ( L_5 ,
sizeof( struct V_42 ) ,
0 ,
V_278 | V_279 ,
NULL ) ;
}
static int
F_238 ( struct V_1 * V_2 , struct V_280 * V_250 , int V_66 , int V_6 )
{
int V_157 = F_115 ( V_2 ) ;
int V_81 , V_159 = V_157 - V_66 ;
struct V_1 * V_158 ;
int V_281 = 0 ;
if ( V_159 > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
F_239 ( V_250 , V_2 -> V_8 + V_66 , V_159 ) ;
V_281 ++ ;
if ( ( V_6 -= V_159 ) == 0 )
return V_281 ;
V_66 += V_159 ;
}
for ( V_81 = 0 ; V_81 < F_23 ( V_2 ) -> V_91 ; V_81 ++ ) {
int V_10 ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + F_98 ( & F_23 ( V_2 ) -> V_84 [ V_81 ] ) ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
T_5 * V_63 = & F_23 ( V_2 ) -> V_84 [ V_81 ] ;
if ( V_159 > V_6 )
V_159 = V_6 ;
F_240 ( & V_250 [ V_281 ] , F_97 ( V_63 ) , V_159 ,
V_63 -> V_118 + V_66 - V_157 ) ;
V_281 ++ ;
if ( ! ( V_6 -= V_159 ) )
return V_281 ;
V_66 += V_159 ;
}
V_157 = V_10 ;
}
F_59 (skb, frag_iter) {
int V_10 ;
F_73 ( V_157 > V_66 + V_6 ) ;
V_10 = V_157 + V_158 -> V_6 ;
if ( ( V_159 = V_10 - V_66 ) > 0 ) {
if ( V_159 > V_6 )
V_159 = V_6 ;
V_281 += F_238 ( V_158 , V_250 + V_281 , V_66 - V_157 ,
V_159 ) ;
if ( ( V_6 -= V_159 ) == 0 )
return V_281 ;
V_66 += V_159 ;
}
V_157 = V_10 ;
}
F_120 ( V_6 ) ;
return V_281 ;
}
int F_241 ( struct V_1 * V_2 , struct V_280 * V_250 ,
int V_66 , int V_6 )
{
return F_238 ( V_2 , V_250 , V_66 , V_6 ) ;
}
int F_242 ( struct V_1 * V_2 , struct V_280 * V_250 , int V_66 , int V_6 )
{
int V_282 = F_238 ( V_2 , V_250 , V_66 , V_6 ) ;
F_243 ( & V_250 [ V_282 - 1 ] ) ;
return V_282 ;
}
int F_244 ( struct V_1 * V_2 , int V_283 , struct V_1 * * V_284 )
{
int V_285 ;
int V_281 ;
struct V_1 * V_44 , * * V_286 ;
if ( ( F_123 ( V_2 ) || F_23 ( V_2 ) -> V_91 ) &&
F_142 ( V_2 , F_245 ( V_2 ) - F_115 ( V_2 ) ) == NULL )
return - V_117 ;
if ( ! F_118 ( V_2 ) ) {
if ( F_129 ( V_2 ) < V_283 &&
F_119 ( V_2 , 0 , V_283 - F_129 ( V_2 ) + 128 , V_52 ) )
return - V_117 ;
* V_284 = V_2 ;
return 1 ;
}
V_281 = 1 ;
V_286 = & F_23 ( V_2 ) -> V_86 ;
V_285 = 0 ;
while ( ( V_44 = * V_286 ) != NULL ) {
int V_134 = 0 ;
if ( F_121 ( V_44 ) )
V_285 = 1 ;
if ( V_44 -> V_106 == NULL && V_283 ) {
if ( F_23 ( V_44 ) -> V_91 ||
F_118 ( V_44 ) ||
F_129 ( V_44 ) < V_283 )
V_134 = V_283 + 128 ;
}
if ( V_285 ||
F_123 ( V_44 ) ||
V_134 ||
F_23 ( V_44 ) -> V_91 ||
F_118 ( V_44 ) ) {
struct V_1 * V_45 ;
if ( V_134 == 0 )
V_45 = F_110 ( V_44 , V_52 ) ;
else
V_45 = F_127 ( V_44 ,
F_90 ( V_44 ) ,
V_134 ,
V_52 ) ;
if ( F_32 ( V_45 == NULL ) )
return - V_117 ;
if ( V_44 -> V_109 )
F_246 ( V_45 , V_44 -> V_109 ) ;
V_45 -> V_106 = V_44 -> V_106 ;
* V_286 = V_45 ;
F_80 ( V_44 ) ;
V_44 = V_45 ;
}
V_281 ++ ;
* V_284 = V_44 ;
V_286 = & V_44 -> V_106 ;
}
return V_281 ;
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_165 * V_109 = V_2 -> V_109 ;
F_248 ( V_2 -> V_27 , & V_109 -> V_287 ) ;
}
int F_249 ( struct V_165 * V_109 , struct V_1 * V_2 )
{
if ( F_67 ( & V_109 -> V_287 ) + V_2 -> V_27 >=
( unsigned int ) V_109 -> V_288 )
return - V_117 ;
F_250 ( V_2 ) ;
V_2 -> V_109 = V_109 ;
V_2 -> V_100 = F_247 ;
F_35 ( V_2 -> V_27 , & V_109 -> V_287 ) ;
F_251 ( V_2 ) ;
F_184 ( & V_109 -> V_289 , V_2 ) ;
if ( ! F_252 ( V_109 , V_290 ) )
V_109 -> V_291 ( V_109 ) ;
return 0 ;
}
struct V_1 * F_253 ( struct V_165 * V_109 )
{
struct V_201 * V_292 = & V_109 -> V_289 ;
struct V_1 * V_2 , * V_293 ;
unsigned long V_15 ;
int V_143 = 0 ;
F_176 ( & V_292 -> V_203 , V_15 ) ;
V_2 = F_177 ( V_292 ) ;
if ( V_2 && ( V_293 = F_254 ( V_292 ) ) )
V_143 = F_255 ( V_293 ) -> V_294 . V_295 ;
F_178 ( & V_292 -> V_203 , V_15 ) ;
V_109 -> V_296 = V_143 ;
if ( V_143 )
V_109 -> V_297 ( V_109 ) ;
return V_2 ;
}
struct V_1 * F_256 ( struct V_1 * V_2 )
{
struct V_165 * V_109 = V_2 -> V_109 ;
struct V_1 * V_154 ;
if ( ! V_109 || ! F_257 ( & V_109 -> V_298 ) )
return NULL ;
V_154 = F_103 ( V_2 , V_52 ) ;
if ( ! V_154 ) {
F_258 ( V_109 ) ;
return NULL ;
}
V_154 -> V_109 = V_109 ;
V_154 -> V_100 = V_299 ;
return V_154 ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_165 * V_109 ,
int V_300 )
{
struct V_301 * V_302 ;
int V_143 ;
V_302 = F_255 ( V_2 ) ;
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
V_302 -> V_294 . V_295 = V_303 ;
V_302 -> V_294 . V_304 = V_305 ;
V_302 -> V_294 . V_306 = V_300 ;
if ( V_109 -> V_307 & V_308 ) {
V_302 -> V_294 . V_309 = F_23 ( V_2 ) -> V_310 ;
if ( V_109 -> V_311 == V_312 )
V_302 -> V_294 . V_309 -= V_109 -> V_313 ;
}
V_143 = F_249 ( V_109 , V_2 ) ;
if ( V_143 )
F_80 ( V_2 ) ;
}
static bool F_260 ( struct V_165 * V_109 , bool V_314 )
{
bool V_184 ;
if ( F_45 ( V_315 || V_314 ) )
return true ;
F_261 ( & V_109 -> V_316 ) ;
V_184 = V_109 -> V_317 && V_109 -> V_317 -> V_318 &&
F_262 ( V_109 -> V_317 -> V_318 , & V_319 , V_320 ) ;
F_263 ( & V_109 -> V_316 ) ;
return V_184 ;
}
void F_264 ( struct V_1 * V_2 ,
struct V_321 * V_322 )
{
struct V_165 * V_109 = V_2 -> V_109 ;
if ( ! F_260 ( V_109 , false ) )
return;
F_265 ( V_109 ) ;
* F_266 ( V_2 ) = * V_322 ;
F_259 ( V_2 , V_109 , V_323 ) ;
F_258 ( V_109 ) ;
}
void F_267 ( struct V_1 * V_324 ,
struct V_321 * V_322 ,
struct V_165 * V_109 , int V_300 )
{
struct V_1 * V_2 ;
bool V_314 ;
if ( ! V_109 )
return;
V_314 = V_109 -> V_307 & V_325 ;
if ( ! F_260 ( V_109 , V_314 ) )
return;
if ( V_314 )
V_2 = F_228 ( 0 , V_52 ) ;
else
V_2 = F_103 ( V_324 , V_52 ) ;
if ( ! V_2 )
return;
if ( V_314 ) {
F_23 ( V_2 ) -> V_92 = F_23 ( V_324 ) -> V_92 ;
F_23 ( V_2 ) -> V_310 = F_23 ( V_324 ) -> V_310 ;
}
if ( V_322 )
* F_266 ( V_2 ) = * V_322 ;
else
V_2 -> V_326 = F_268 () ;
F_259 ( V_2 , V_109 , V_300 ) ;
}
void F_269 ( struct V_1 * V_324 ,
struct V_321 * V_322 )
{
return F_267 ( V_324 , V_322 , V_324 -> V_109 ,
V_323 ) ;
}
void F_270 ( struct V_1 * V_2 , bool V_327 )
{
struct V_165 * V_109 = V_2 -> V_109 ;
struct V_301 * V_302 ;
int V_143 ;
V_2 -> V_328 = 1 ;
V_2 -> V_329 = V_327 ;
V_302 = F_255 ( V_2 ) ;
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
V_302 -> V_294 . V_295 = V_303 ;
V_302 -> V_294 . V_304 = V_330 ;
F_265 ( V_109 ) ;
V_143 = F_249 ( V_109 , V_2 ) ;
if ( V_143 )
F_80 ( V_2 ) ;
F_258 ( V_109 ) ;
}
bool F_271 ( struct V_1 * V_2 , T_12 V_157 , T_12 V_82 )
{
if ( F_32 ( V_157 > F_115 ( V_2 ) ) ||
F_32 ( ( int ) V_157 + V_82 > F_115 ( V_2 ) - 2 ) ) {
F_222 ( L_6 ,
V_157 , V_82 , F_115 ( V_2 ) ) ;
return false ;
}
V_2 -> V_119 = V_120 ;
V_2 -> V_121 = F_90 ( V_2 ) + V_157 ;
V_2 -> V_199 = V_82 ;
F_232 ( V_2 , V_157 ) ;
return true ;
}
static int F_272 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_331 )
{
if ( F_115 ( V_2 ) >= V_6 )
return 0 ;
if ( V_331 > V_2 -> V_6 )
V_331 = V_2 -> V_6 ;
if ( F_142 ( V_2 , V_331 - F_115 ( V_2 ) ) == NULL )
return - V_117 ;
if ( F_115 ( V_2 ) < V_6 )
return - V_332 ;
return 0 ;
}
static int F_273 ( struct V_1 * V_2 , bool V_333 )
{
unsigned int V_82 ;
bool V_334 ;
V_200 * V_186 ;
int V_143 ;
V_334 = false ;
V_143 = F_272 ( V_2 ,
sizeof( struct V_335 ) ,
V_336 ) ;
if ( V_143 < 0 )
goto V_23;
if ( F_274 ( V_2 ) -> V_337 & F_275 ( V_338 | V_339 ) )
V_334 = true ;
V_82 = F_276 ( V_2 ) ;
V_143 = - V_332 ;
if ( V_334 )
goto V_23;
V_186 = F_277 ( V_2 , F_274 ( V_2 ) -> V_340 , V_82 ) ;
if ( F_278 ( V_186 ) )
return F_279 ( V_186 ) ;
if ( V_333 )
* V_186 = ~ F_280 ( F_274 ( V_2 ) -> V_341 ,
F_274 ( V_2 ) -> V_342 ,
V_2 -> V_6 - V_82 ,
F_274 ( V_2 ) -> V_340 , 0 ) ;
V_143 = 0 ;
V_23:
return V_143 ;
}
static int F_281 ( struct V_1 * V_2 , bool V_333 )
{
int V_143 ;
T_3 V_343 ;
unsigned int V_82 ;
unsigned int V_6 ;
bool V_334 ;
bool V_149 ;
V_200 * V_186 ;
V_334 = false ;
V_149 = false ;
V_82 = sizeof( struct V_344 ) ;
V_143 = F_272 ( V_2 , V_82 , V_345 ) ;
if ( V_143 < 0 )
goto V_23;
V_343 = F_282 ( V_2 ) -> V_343 ;
V_6 = sizeof( struct V_344 ) + F_283 ( F_282 ( V_2 ) -> V_346 ) ;
while ( V_82 <= V_6 && ! V_149 ) {
switch ( V_343 ) {
case V_347 :
case V_348 :
case V_349 : {
struct V_350 * V_351 ;
V_143 = F_272 ( V_2 ,
V_82 +
sizeof( struct V_350 ) ,
V_345 ) ;
if ( V_143 < 0 )
goto V_23;
V_351 = F_284 ( struct V_350 , V_2 , V_82 ) ;
V_343 = V_351 -> V_343 ;
V_82 += F_285 ( V_351 ) ;
break;
}
case V_352 : {
struct V_353 * V_351 ;
V_143 = F_272 ( V_2 ,
V_82 +
sizeof( struct V_353 ) ,
V_345 ) ;
if ( V_143 < 0 )
goto V_23;
V_351 = F_284 ( struct V_353 , V_2 , V_82 ) ;
V_343 = V_351 -> V_343 ;
V_82 += F_286 ( V_351 ) ;
break;
}
case V_354 : {
struct V_355 * V_351 ;
V_143 = F_272 ( V_2 ,
V_82 +
sizeof( struct V_355 ) ,
V_345 ) ;
if ( V_143 < 0 )
goto V_23;
V_351 = F_284 ( struct V_355 , V_2 , V_82 ) ;
if ( V_351 -> V_337 & F_275 ( V_356 | V_357 ) )
V_334 = true ;
V_343 = V_351 -> V_343 ;
V_82 += sizeof( struct V_355 ) ;
break;
}
default:
V_149 = true ;
break;
}
}
V_143 = - V_332 ;
if ( ! V_149 || V_334 )
goto V_23;
V_186 = F_277 ( V_2 , V_343 , V_82 ) ;
if ( F_278 ( V_186 ) )
return F_279 ( V_186 ) ;
if ( V_333 )
* V_186 = ~ F_287 ( & F_282 ( V_2 ) -> V_341 ,
& F_282 ( V_2 ) -> V_342 ,
V_2 -> V_6 - V_82 , V_343 , 0 ) ;
V_143 = 0 ;
V_23:
return V_143 ;
}
int F_288 ( struct V_1 * V_2 , bool V_333 )
{
int V_143 ;
switch ( V_2 -> V_340 ) {
case F_275 ( V_358 ) :
V_143 = F_273 ( V_2 , V_333 ) ;
break;
case F_275 ( V_359 ) :
V_143 = F_281 ( V_2 , V_333 ) ;
break;
default:
V_143 = - V_332 ;
break;
}
return V_143 ;
}
void F_289 ( const struct V_1 * V_2 )
{
F_222 ( L_7 ,
V_2 -> V_11 -> V_12 ) ;
}
void F_290 ( struct V_1 * V_2 , bool V_360 )
{
if ( V_360 ) {
F_69 ( V_2 ) ;
F_27 ( V_25 , V_2 ) ;
} else {
F_79 ( V_2 ) ;
}
}
bool F_291 ( struct V_1 * V_156 , struct V_1 * V_185 ,
bool * V_361 , int * V_268 )
{
int V_81 , V_136 , V_6 = V_185 -> V_6 ;
* V_361 = false ;
if ( F_123 ( V_156 ) )
return false ;
if ( V_6 <= F_129 ( V_156 ) ) {
if ( V_6 )
F_120 ( F_113 ( V_185 , 0 , F_112 ( V_156 , V_6 ) , V_6 ) ) ;
* V_268 = 0 ;
return true ;
}
if ( F_118 ( V_156 ) || F_118 ( V_185 ) )
return false ;
if ( F_115 ( V_185 ) != 0 ) {
struct V_54 * V_54 ;
unsigned int V_66 ;
if ( F_23 ( V_156 ) -> V_91 +
F_23 ( V_185 ) -> V_91 >= V_173 )
return false ;
if ( F_158 ( V_185 ) )
return false ;
V_136 = V_185 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
V_54 = F_47 ( V_185 -> V_7 ) ;
V_66 = V_185 -> V_8 - ( unsigned char * ) F_37 ( V_54 ) ;
F_52 ( V_156 , F_23 ( V_156 ) -> V_91 ,
V_54 , V_66 , F_115 ( V_185 ) ) ;
* V_361 = true ;
} else {
if ( F_23 ( V_156 ) -> V_91 +
F_23 ( V_185 ) -> V_91 > V_173 )
return false ;
V_136 = V_185 -> V_27 - F_21 ( F_111 ( V_185 ) ) ;
}
F_292 ( V_136 < V_6 ) ;
memcpy ( F_23 ( V_156 ) -> V_84 + F_23 ( V_156 ) -> V_91 ,
F_23 ( V_185 ) -> V_84 ,
F_23 ( V_185 ) -> V_91 * sizeof( T_5 ) ) ;
F_23 ( V_156 ) -> V_91 += F_23 ( V_185 ) -> V_91 ;
if ( ! F_123 ( V_185 ) )
F_23 ( V_185 ) -> V_91 = 0 ;
for ( V_81 = 0 ; V_81 < F_23 ( V_185 ) -> V_91 ; V_81 ++ )
F_117 ( V_185 , V_81 ) ;
V_156 -> V_27 += V_136 ;
V_156 -> V_6 += V_6 ;
V_156 -> V_83 += V_6 ;
* V_268 = V_136 ;
return true ;
}
void F_293 ( struct V_1 * V_2 , bool V_362 )
{
if ( V_362 )
F_250 ( V_2 ) ;
V_2 -> V_326 . V_363 = 0 ;
V_2 -> V_364 = V_365 ;
V_2 -> V_366 = 0 ;
V_2 -> V_367 = 0 ;
F_70 ( V_2 ) ;
V_2 -> V_368 = 0 ;
F_294 ( V_2 ) ;
F_295 ( V_2 ) ;
F_296 ( V_2 ) ;
F_297 ( V_2 ) ;
F_298 ( V_2 ) ;
}
unsigned int F_299 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_23 ( V_2 ) ;
unsigned int V_369 = 0 ;
if ( V_2 -> V_370 ) {
V_369 = F_300 ( V_2 ) -
F_301 ( V_2 ) ;
if ( F_45 ( V_33 -> V_130 & ( V_371 | V_372 ) ) )
V_369 += F_302 ( V_2 ) ;
} else if ( F_45 ( V_33 -> V_130 & ( V_371 | V_372 ) ) ) {
V_369 = F_303 ( V_2 ) ;
}
return V_369 + V_33 -> V_128 ;
}
static struct V_1 * F_304 ( struct V_1 * V_2 )
{
if ( F_305 ( V_2 , F_90 ( V_2 ) ) < 0 ) {
F_80 ( V_2 ) ;
return NULL ;
}
memmove ( V_2 -> V_8 - V_373 , V_2 -> V_8 - V_374 , 2 * V_375 ) ;
V_2 -> V_29 += V_376 ;
return V_2 ;
}
struct V_1 * F_306 ( struct V_1 * V_2 )
{
struct V_377 * V_378 ;
T_12 V_379 ;
if ( F_32 ( F_307 ( V_2 ) ) ) {
return V_2 ;
}
V_2 = F_308 ( V_2 , V_52 ) ;
if ( F_32 ( ! V_2 ) )
goto V_380;
if ( F_32 ( ! F_309 ( V_2 , V_376 ) ) )
goto V_380;
V_378 = (struct V_377 * ) V_2 -> V_8 ;
V_379 = F_283 ( V_378 -> V_381 ) ;
F_310 ( V_2 , V_2 -> V_340 , V_379 ) ;
F_209 ( V_2 , V_376 ) ;
F_311 ( V_2 , V_378 ) ;
V_2 = F_304 ( V_2 ) ;
if ( F_32 ( ! V_2 ) )
goto V_380;
F_312 ( V_2 ) ;
F_313 ( V_2 ) ;
F_220 ( V_2 ) ;
return V_2 ;
V_380:
F_80 ( V_2 ) ;
return NULL ;
}
int F_314 ( struct V_1 * V_2 , int V_382 )
{
if ( ! F_309 ( V_2 , V_382 ) )
return - V_117 ;
if ( ! F_123 ( V_2 ) || F_315 ( V_2 , V_382 ) )
return 0 ;
return F_119 ( V_2 , 0 , 0 , V_52 ) ;
}
static int F_316 ( struct V_1 * V_2 , T_12 * V_379 )
{
struct V_377 * V_378 ;
unsigned int V_66 = V_2 -> V_8 - F_212 ( V_2 ) ;
int V_143 ;
F_214 ( V_2 , V_66 ) ;
V_143 = F_314 ( V_2 , V_374 ) ;
if ( F_32 ( V_143 ) )
goto V_383;
F_210 ( V_2 , V_2 -> V_8 + ( 2 * V_375 ) , V_376 ) ;
V_378 = (struct V_377 * ) ( V_2 -> V_8 + V_373 ) ;
* V_379 = F_283 ( V_378 -> V_381 ) ;
memmove ( V_2 -> V_8 + V_376 , V_2 -> V_8 , 2 * V_375 ) ;
F_234 ( V_2 , V_376 ) ;
F_311 ( V_2 , V_378 ) ;
V_2 -> V_29 += V_376 ;
if ( F_231 ( V_2 ) < V_373 )
F_230 ( V_2 , V_373 ) ;
F_220 ( V_2 ) ;
V_383:
F_234 ( V_2 , V_66 ) ;
return V_143 ;
}
int F_317 ( struct V_1 * V_2 )
{
T_12 V_379 ;
T_10 V_384 ;
int V_143 ;
if ( F_45 ( F_307 ( V_2 ) ) ) {
V_2 -> V_379 = 0 ;
} else {
if ( F_32 ( ( V_2 -> V_340 != F_275 ( V_385 ) &&
V_2 -> V_340 != F_275 ( V_386 ) ) ||
V_2 -> V_6 < V_374 ) )
return 0 ;
V_143 = F_316 ( V_2 , & V_379 ) ;
if ( V_143 )
return V_143 ;
}
if ( F_45 ( ( V_2 -> V_340 != F_275 ( V_385 ) &&
V_2 -> V_340 != F_275 ( V_386 ) ) ||
V_2 -> V_6 < V_374 ) )
return 0 ;
V_384 = V_2 -> V_340 ;
V_143 = F_316 ( V_2 , & V_379 ) ;
if ( F_32 ( V_143 ) )
return V_143 ;
F_310 ( V_2 , V_384 , V_379 ) ;
return 0 ;
}
int F_318 ( struct V_1 * V_2 , T_10 V_384 , T_12 V_379 )
{
if ( F_307 ( V_2 ) ) {
unsigned int V_66 = V_2 -> V_8 - F_212 ( V_2 ) ;
int V_143 ;
F_214 ( V_2 , V_66 ) ;
V_143 = F_319 ( V_2 , V_2 -> V_384 ,
F_320 ( V_2 ) ) ;
if ( V_143 )
return V_143 ;
V_2 -> V_340 = V_2 -> V_384 ;
V_2 -> V_110 += V_376 ;
F_234 ( V_2 , V_66 ) ;
if ( V_2 -> V_119 == V_387 )
V_2 -> V_186 = F_321 ( V_2 -> V_186 , F_322 ( V_2 -> V_8
+ ( 2 * V_375 ) , V_376 , 0 ) ) ;
}
F_310 ( V_2 , V_384 , V_379 ) ;
return 0 ;
}
struct V_1 * F_323 ( unsigned long V_388 ,
unsigned long V_83 ,
int V_389 ,
int * V_390 ,
T_2 V_24 )
{
int V_391 = ( V_83 + ( V_64 - 1 ) ) >> V_392 ;
unsigned long V_393 ;
struct V_1 * V_2 ;
struct V_54 * V_54 ;
T_2 V_394 ;
int V_81 ;
* V_390 = - V_240 ;
if ( V_391 > V_173 )
return NULL ;
V_394 = V_24 ;
if ( V_394 & V_73 )
V_394 |= V_395 ;
* V_390 = - V_396 ;
V_2 = F_228 ( V_388 , V_394 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_27 += V_391 << V_392 ;
for ( V_81 = 0 ; V_391 > 0 ; V_81 ++ ) {
int V_57 = V_389 ;
while ( V_57 ) {
if ( V_391 >= 1 << V_57 ) {
V_54 = F_324 ( V_24 |
V_60 |
V_22 |
V_61 ,
V_57 ) ;
if ( V_54 )
goto V_397;
V_57 = 1 ;
V_389 = 0 ;
}
V_57 -- ;
}
V_54 = F_94 ( V_24 ) ;
if ( ! V_54 )
goto V_398;
V_397:
V_393 = F_150 (unsigned long, data_len,
PAGE_SIZE << order) ;
F_52 ( V_2 , V_81 , V_54 , 0 , V_393 ) ;
V_83 -= V_393 ;
V_391 -= 1 << V_57 ;
}
return V_2 ;
V_398:
F_80 ( V_2 ) ;
return NULL ;
}
