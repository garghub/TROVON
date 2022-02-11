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
struct V_1 * F_30 ( void * V_8 , unsigned int V_51 )
{
struct V_1 * V_2 = F_28 ( V_8 , V_51 ) ;
if ( V_2 && V_51 ) {
V_2 -> V_53 = 1 ;
if ( F_31 ( F_32 ( V_8 ) ) )
V_2 -> V_18 = 1 ;
}
return V_2 ;
}
static void * F_33 ( unsigned int V_54 , T_2 V_24 )
{
struct V_55 * V_56 ;
unsigned long V_15 ;
void * V_8 ;
F_34 ( V_15 ) ;
V_56 = F_35 ( & V_57 ) ;
V_8 = F_36 ( V_56 , V_54 , V_24 ) ;
F_37 ( V_15 ) ;
return V_8 ;
}
void * F_38 ( unsigned int V_54 )
{
return F_33 ( V_54 , V_52 | V_58 ) ;
}
static void * F_39 ( unsigned int V_54 , T_2 V_24 )
{
struct V_59 * V_56 = F_35 ( & V_59 ) ;
return F_36 ( & V_56 -> V_60 , V_54 , V_24 ) ;
}
void * F_40 ( unsigned int V_54 )
{
return F_39 ( V_54 , V_52 | V_58 ) ;
}
struct V_1 * F_41 ( struct V_61 * V_11 , unsigned int V_6 ,
T_2 V_24 )
{
struct V_55 * V_56 ;
unsigned long V_15 ;
struct V_1 * V_2 ;
bool V_18 ;
void * V_8 ;
V_6 += V_62 ;
if ( ( V_6 > F_19 ( V_63 ) ) ||
( V_24 & ( V_64 | V_65 ) ) ) {
V_2 = F_14 ( V_6 , V_24 , V_36 , V_66 ) ;
if ( ! V_2 )
goto V_67;
goto V_68;
}
V_6 += F_17 ( sizeof( struct V_32 ) ) ;
V_6 = F_17 ( V_6 ) ;
if ( F_15 () )
V_24 |= V_37 ;
F_34 ( V_15 ) ;
V_56 = F_35 ( & V_57 ) ;
V_8 = F_36 ( V_56 , V_6 , V_24 ) ;
V_18 = V_56 -> V_18 ;
F_37 ( V_15 ) ;
if ( F_42 ( ! V_8 ) )
return NULL ;
V_2 = F_28 ( V_8 , V_6 ) ;
if ( F_42 ( ! V_2 ) ) {
F_43 ( V_8 ) ;
return NULL ;
}
if ( V_18 )
V_2 -> V_18 = 1 ;
V_2 -> V_53 = 1 ;
V_68:
F_44 ( V_2 , V_62 ) ;
V_2 -> V_11 = V_11 ;
V_67:
return V_2 ;
}
struct V_1 * F_45 ( struct V_69 * V_70 , unsigned int V_6 ,
T_2 V_24 )
{
struct V_59 * V_56 = F_35 ( & V_59 ) ;
struct V_1 * V_2 ;
void * V_8 ;
V_6 += V_62 + V_71 ;
if ( ( V_6 > F_19 ( V_63 ) ) ||
( V_24 & ( V_64 | V_65 ) ) ) {
V_2 = F_14 ( V_6 , V_24 , V_36 , V_66 ) ;
if ( ! V_2 )
goto V_67;
goto V_68;
}
V_6 += F_17 ( sizeof( struct V_32 ) ) ;
V_6 = F_17 ( V_6 ) ;
if ( F_15 () )
V_24 |= V_37 ;
V_8 = F_36 ( & V_56 -> V_60 , V_6 , V_24 ) ;
if ( F_42 ( ! V_8 ) )
return NULL ;
V_2 = F_28 ( V_8 , V_6 ) ;
if ( F_42 ( ! V_2 ) ) {
F_43 ( V_8 ) ;
return NULL ;
}
if ( V_56 -> V_60 . V_18 )
V_2 -> V_18 = 1 ;
V_2 -> V_53 = 1 ;
V_68:
F_44 ( V_2 , V_62 + V_71 ) ;
V_2 -> V_11 = V_70 -> V_11 ;
V_67:
return V_2 ;
}
void F_46 ( struct V_1 * V_2 , int V_72 , struct V_60 * V_60 , int V_73 ,
int V_14 , unsigned int V_27 )
{
F_47 ( V_2 , V_72 , V_60 , V_73 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_74 += V_14 ;
V_2 -> V_27 += V_27 ;
}
void F_48 ( struct V_1 * V_2 , int V_72 , int V_14 ,
unsigned int V_27 )
{
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_72 ] ;
F_49 ( V_75 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_74 += V_14 ;
V_2 -> V_27 += V_27 ;
}
static void F_50 ( struct V_1 * * V_77 )
{
F_51 ( * V_77 ) ;
* V_77 = NULL ;
}
static inline void F_52 ( struct V_1 * V_2 )
{
F_50 ( & F_23 ( V_2 ) -> V_78 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_1 * V_79 ;
F_54 (skb, list)
F_55 ( V_79 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned char * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_53 )
F_43 ( V_7 ) ;
else
F_57 ( V_7 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_23 ( V_2 ) ;
int V_72 ;
if ( V_2 -> V_80 &&
F_59 ( V_2 -> V_81 ? ( 1 << V_82 ) + 1 : 1 ,
& V_33 -> V_40 ) )
return;
for ( V_72 = 0 ; V_72 < V_33 -> V_83 ; V_72 ++ )
F_60 ( & V_33 -> V_76 [ V_72 ] ) ;
if ( V_33 -> V_84 & V_85 ) {
struct V_86 * V_87 ;
V_87 = V_33 -> V_41 ;
if ( V_87 -> V_88 )
V_87 -> V_88 ( V_87 , true ) ;
}
if ( V_33 -> V_78 )
F_51 ( V_33 -> V_78 ) ;
F_56 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
switch ( V_2 -> V_47 ) {
case V_89 :
F_27 ( V_25 , V_2 ) ;
return;
case V_48 :
V_43 = F_25 ( V_2 , struct V_42 , V_44 ) ;
if ( F_62 ( & V_43 -> V_49 ) == 1 )
goto V_90;
break;
default:
V_43 = F_25 ( V_2 , struct V_42 , V_45 ) ;
break;
}
if ( ! F_63 ( & V_43 -> V_49 ) )
return;
V_90:
F_27 ( V_35 , V_43 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 ) ;
#ifdef F_66
F_67 ( V_2 -> V_91 ) ;
#endif
if ( V_2 -> V_92 ) {
F_68 ( F_69 () ) ;
V_2 -> V_92 ( V_2 ) ;
}
#if F_70 ( V_93 )
F_71 ( V_2 -> V_94 ) ;
#endif
#if F_70 ( V_95 )
F_72 ( V_2 -> V_96 ) ;
#endif
}
static void F_73 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
if ( F_74 ( V_2 -> V_7 ) )
F_58 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
F_61 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( F_42 ( ! V_2 ) )
return;
if ( F_74 ( F_62 ( & V_2 -> V_28 ) == 1 ) )
F_77 () ;
else if ( F_74 ( ! F_63 ( & V_2 -> V_28 ) ) )
return;
F_78 ( V_2 , F_79 ( 0 ) ) ;
F_75 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_97 )
{
while ( V_97 ) {
struct V_1 * V_98 = V_97 -> V_98 ;
F_76 ( V_97 ) ;
V_97 = V_98 ;
}
}
void F_80 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) -> V_84 & V_85 ) {
struct V_86 * V_87 ;
V_87 = F_23 ( V_2 ) -> V_41 ;
if ( V_87 -> V_88 )
V_87 -> V_88 ( V_87 , false ) ;
F_23 ( V_2 ) -> V_84 &= ~ V_85 ;
}
}
void F_81 ( struct V_1 * V_2 )
{
if ( F_42 ( ! V_2 ) )
return;
if ( F_74 ( F_62 ( & V_2 -> V_28 ) == 1 ) )
F_77 () ;
else if ( F_74 ( ! F_63 ( & V_2 -> V_28 ) ) )
return;
F_82 ( V_2 ) ;
F_75 ( V_2 ) ;
}
void F_83 ( void )
{
struct V_59 * V_56 = F_35 ( & V_59 ) ;
if ( V_56 -> V_99 ) {
F_84 ( V_25 , V_56 -> V_99 ,
V_56 -> V_100 ) ;
V_56 -> V_99 = 0 ;
}
}
static inline void F_85 ( struct V_1 * V_2 )
{
struct V_59 * V_56 = F_35 ( & V_59 ) ;
F_73 ( V_2 ) ;
V_56 -> V_100 [ V_56 -> V_99 ++ ] = V_2 ;
#ifdef F_86
F_16 ( V_2 ) ;
#endif
if ( F_42 ( V_56 -> V_99 == V_101 ) ) {
F_84 ( V_25 , V_101 ,
V_56 -> V_100 ) ;
V_56 -> V_99 = 0 ;
}
}
void F_87 ( struct V_1 * V_2 )
{
F_85 ( V_2 ) ;
}
void F_88 ( struct V_1 * V_2 , int V_102 )
{
if ( F_42 ( ! V_2 ) )
return;
if ( F_42 ( ! V_102 ) ) {
F_89 ( V_2 ) ;
return;
}
if ( F_74 ( F_62 ( & V_2 -> V_28 ) == 1 ) )
F_77 () ;
else if ( F_74 ( ! F_63 ( & V_2 -> V_28 ) ) )
return;
F_82 ( V_2 ) ;
if ( V_2 -> V_47 != V_89 ) {
F_75 ( V_2 ) ;
return;
}
F_85 ( V_2 ) ;
}
static struct V_1 * F_90 ( struct V_1 * V_103 , struct V_1 * V_2 )
{
#define F_91 ( T_5 ) n->x = skb->x
V_103 -> V_98 = V_103 -> V_104 = NULL ;
V_103 -> V_105 = NULL ;
F_92 ( V_103 , V_2 ) ;
F_91 ( V_6 ) ;
F_91 ( V_74 ) ;
F_91 ( V_106 ) ;
V_103 -> V_107 = V_2 -> V_81 ? F_93 ( V_2 ) : V_2 -> V_107 ;
V_103 -> V_80 = 1 ;
V_103 -> V_81 = 0 ;
V_103 -> V_92 = NULL ;
F_91 ( V_9 ) ;
F_91 ( V_10 ) ;
F_91 ( V_7 ) ;
F_91 ( V_53 ) ;
F_91 ( V_8 ) ;
F_91 ( V_27 ) ;
F_12 ( & V_103 -> V_28 , 1 ) ;
F_94 ( & ( F_23 ( V_2 ) -> V_40 ) ) ;
V_2 -> V_80 = 1 ;
return V_103 ;
#undef F_91
}
struct V_1 * F_95 ( struct V_1 * V_108 , struct V_1 * V_109 )
{
F_73 ( V_108 ) ;
return F_90 ( V_108 , V_109 ) ;
}
int F_96 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_72 ;
int V_110 = F_23 ( V_2 ) -> V_83 ;
struct V_60 * V_60 , * V_7 = NULL ;
struct V_86 * V_87 = F_23 ( V_2 ) -> V_41 ;
for ( V_72 = 0 ; V_72 < V_110 ; V_72 ++ ) {
T_3 * V_111 ;
T_4 * V_112 = & F_23 ( V_2 ) -> V_76 [ V_72 ] ;
V_60 = F_97 ( V_24 ) ;
if ( ! V_60 ) {
while ( V_7 ) {
struct V_60 * V_98 = (struct V_60 * ) F_98 ( V_7 ) ;
F_99 ( V_7 ) ;
V_7 = V_98 ;
}
return - V_113 ;
}
V_111 = F_100 ( F_101 ( V_112 ) ) ;
memcpy ( F_102 ( V_60 ) ,
V_111 + V_112 -> V_114 , F_103 ( V_112 ) ) ;
F_104 ( V_111 ) ;
F_105 ( V_60 , ( unsigned long ) V_7 ) ;
V_7 = V_60 ;
}
for ( V_72 = 0 ; V_72 < V_110 ; V_72 ++ )
F_106 ( V_2 , V_72 ) ;
V_87 -> V_88 ( V_87 , false ) ;
for ( V_72 = V_110 - 1 ; V_72 >= 0 ; V_72 -- ) {
F_107 ( V_2 , V_72 , V_7 , 0 ,
F_23 ( V_2 ) -> V_76 [ V_72 ] . V_14 ) ;
V_7 = (struct V_60 * ) F_98 ( V_7 ) ;
}
F_23 ( V_2 ) -> V_84 &= ~ V_85 ;
return 0 ;
}
struct V_1 * F_108 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_42 * V_43 = F_25 ( V_2 ,
struct V_42 ,
V_44 ) ;
struct V_1 * V_103 ;
if ( F_109 ( V_2 , V_24 ) )
return NULL ;
if ( V_2 -> V_47 == V_48 &&
F_62 ( & V_43 -> V_49 ) == 1 ) {
V_103 = & V_43 -> V_45 ;
F_12 ( & V_43 -> V_49 , 2 ) ;
} else {
if ( F_110 ( V_2 ) )
V_24 |= V_37 ;
V_103 = F_29 ( V_25 , V_24 ) ;
if ( ! V_103 )
return NULL ;
F_26 ( V_103 , V_46 ) ;
V_103 -> V_47 = V_89 ;
}
return F_90 ( V_103 , V_2 ) ;
}
static void F_111 ( struct V_1 * V_2 , int V_73 )
{
if ( V_2 -> V_115 == V_116 )
V_2 -> V_117 += V_73 ;
V_2 -> V_39 += V_73 ;
V_2 -> V_118 += V_73 ;
if ( F_112 ( V_2 ) )
V_2 -> V_29 += V_73 ;
V_2 -> V_119 += V_73 ;
V_2 -> V_120 += V_73 ;
V_2 -> V_121 += V_73 ;
}
static void F_113 ( struct V_1 * V_122 , const struct V_1 * V_123 )
{
F_92 ( V_122 , V_123 ) ;
F_23 ( V_122 ) -> V_124 = F_23 ( V_123 ) -> V_124 ;
F_23 ( V_122 ) -> V_125 = F_23 ( V_123 ) -> V_125 ;
F_23 ( V_122 ) -> V_126 = F_23 ( V_123 ) -> V_126 ;
}
static inline int F_114 ( const struct V_1 * V_2 )
{
if ( F_110 ( V_2 ) )
return V_36 ;
return 0 ;
}
struct V_1 * F_115 ( const struct V_1 * V_2 , T_2 V_24 )
{
int V_127 = F_93 ( V_2 ) ;
unsigned int V_14 = F_116 ( V_2 ) + V_2 -> V_74 ;
struct V_1 * V_103 = F_14 ( V_14 , V_24 ,
F_114 ( V_2 ) , V_66 ) ;
if ( ! V_103 )
return NULL ;
F_44 ( V_103 , V_127 ) ;
F_117 ( V_103 , V_2 -> V_6 ) ;
if ( F_118 ( V_2 , - V_127 , V_103 -> V_7 , V_127 + V_2 -> V_6 ) )
F_3 () ;
F_113 ( V_103 , V_2 ) ;
return V_103 ;
}
struct V_1 * F_119 ( struct V_1 * V_2 , int V_128 ,
T_2 V_24 , bool V_47 )
{
unsigned int V_14 = F_120 ( V_2 ) + V_128 ;
int V_15 = F_114 ( V_2 ) | ( V_47 ? V_34 : 0 ) ;
struct V_1 * V_103 = F_14 ( V_14 , V_24 , V_15 , V_66 ) ;
if ( ! V_103 )
goto V_23;
F_44 ( V_103 , V_128 ) ;
F_117 ( V_103 , F_120 ( V_2 ) ) ;
F_121 ( V_2 , V_103 -> V_8 , V_103 -> V_6 ) ;
V_103 -> V_27 += V_2 -> V_74 ;
V_103 -> V_74 = V_2 -> V_74 ;
V_103 -> V_6 = V_2 -> V_6 ;
if ( F_23 ( V_2 ) -> V_83 ) {
int V_72 ;
if ( F_109 ( V_2 , V_24 ) ) {
F_76 ( V_103 ) ;
V_103 = NULL ;
goto V_23;
}
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ ) {
F_23 ( V_103 ) -> V_76 [ V_72 ] = F_23 ( V_2 ) -> V_76 [ V_72 ] ;
F_122 ( V_2 , V_72 ) ;
}
F_23 ( V_103 ) -> V_83 = V_72 ;
}
if ( F_123 ( V_2 ) ) {
F_23 ( V_103 ) -> V_78 = F_23 ( V_2 ) -> V_78 ;
F_53 ( V_103 ) ;
}
F_113 ( V_103 , V_2 ) ;
V_23:
return V_103 ;
}
int F_124 ( struct V_1 * V_2 , int V_129 , int V_130 ,
T_2 V_24 )
{
int V_72 ;
T_3 * V_8 ;
int V_14 = V_129 + F_116 ( V_2 ) + V_130 ;
long V_73 ;
F_125 ( V_129 < 0 ) ;
if ( F_126 ( V_2 ) )
F_3 () ;
V_14 = F_17 ( V_14 ) ;
if ( F_110 ( V_2 ) )
V_24 |= V_37 ;
V_8 = F_18 ( V_14 + F_17 ( sizeof( struct V_32 ) ) ,
V_24 , V_66 , NULL ) ;
if ( ! V_8 )
goto V_38;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
memcpy ( V_8 + V_129 , V_2 -> V_7 , F_127 ( V_2 ) - V_2 -> V_7 ) ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) ,
F_11 ( struct V_32 , V_76 [ F_23 ( V_2 ) -> V_83 ] ) ) ;
if ( F_128 ( V_2 ) ) {
if ( F_109 ( V_2 , V_24 ) )
goto V_131;
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ )
F_122 ( V_2 , V_72 ) ;
if ( F_123 ( V_2 ) )
F_53 ( V_2 ) ;
F_58 ( V_2 ) ;
} else {
F_56 ( V_2 ) ;
}
V_73 = ( V_8 + V_129 ) - V_2 -> V_7 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_53 = 0 ;
V_2 -> V_8 += V_73 ;
#ifdef F_129
V_2 -> V_10 = V_14 ;
V_73 = V_129 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
V_2 -> V_9 += V_73 ;
F_111 ( V_2 , V_129 ) ;
V_2 -> V_80 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_81 = 0 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
V_131:
F_57 ( V_8 ) ;
V_38:
return - V_113 ;
}
struct V_1 * F_130 ( struct V_1 * V_2 , unsigned int V_128 )
{
struct V_1 * V_45 ;
int V_132 = V_128 - F_93 ( V_2 ) ;
if ( V_132 <= 0 )
V_45 = F_131 ( V_2 , V_52 ) ;
else {
V_45 = F_108 ( V_2 , V_52 ) ;
if ( V_45 && F_124 ( V_45 , F_17 ( V_132 ) , 0 ,
V_52 ) ) {
F_76 ( V_45 ) ;
V_45 = NULL ;
}
}
return V_45 ;
}
struct V_1 * F_132 ( const struct V_1 * V_2 ,
int V_133 , int V_134 ,
T_2 V_24 )
{
struct V_1 * V_103 = F_14 ( V_133 + V_2 -> V_6 + V_134 ,
V_24 , F_114 ( V_2 ) ,
V_66 ) ;
int V_135 = F_93 ( V_2 ) ;
int V_136 , V_137 ;
if ( ! V_103 )
return NULL ;
F_44 ( V_103 , V_133 ) ;
F_117 ( V_103 , V_2 -> V_6 ) ;
V_136 = V_135 ;
V_137 = 0 ;
if ( V_133 <= V_136 )
V_136 = V_133 ;
else
V_137 = V_133 - V_136 ;
if ( F_118 ( V_2 , - V_136 , V_103 -> V_7 + V_137 ,
V_2 -> V_6 + V_136 ) )
F_3 () ;
F_113 ( V_103 , V_2 ) ;
F_111 ( V_103 , V_133 - V_135 ) ;
return V_103 ;
}
int F_133 ( struct V_1 * V_2 , int V_138 )
{
int V_139 ;
int V_130 ;
if ( ! F_128 ( V_2 ) && F_134 ( V_2 ) >= V_138 ) {
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_138 ) ;
return 0 ;
}
V_130 = V_2 -> V_74 + V_138 - ( V_2 -> V_10 - V_2 -> V_9 ) ;
if ( F_74 ( F_128 ( V_2 ) || V_130 > 0 ) ) {
V_139 = F_124 ( V_2 , 0 , V_130 , V_52 ) ;
if ( F_42 ( V_139 ) )
goto V_140;
}
V_139 = F_135 ( V_2 ) ;
if ( F_42 ( V_139 ) )
goto V_140;
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_138 ) ;
return 0 ;
V_140:
F_76 ( V_2 ) ;
return V_139 ;
}
unsigned char * F_136 ( struct V_1 * V_2 , struct V_1 * V_9 , int V_6 )
{
if ( V_9 != V_2 ) {
V_2 -> V_74 += V_6 ;
V_2 -> V_6 += V_6 ;
}
return F_117 ( V_9 , V_6 ) ;
}
unsigned char * F_117 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned char * V_141 = F_127 ( V_2 ) ;
F_137 ( V_2 ) ;
V_2 -> V_9 += V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_42 ( V_2 -> V_9 > V_2 -> V_10 ) )
F_4 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_141 ;
}
unsigned char * F_138 ( struct V_1 * V_2 , unsigned int V_6 )
{
V_2 -> V_8 -= V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_42 ( V_2 -> V_8 < V_2 -> V_7 ) )
F_5 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_2 -> V_8 ;
}
unsigned char * F_139 ( struct V_1 * V_2 , unsigned int V_6 )
{
return F_140 ( V_2 , V_6 ) ;
}
void F_141 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_2 -> V_6 > V_6 )
F_142 ( V_2 , V_6 ) ;
}
int F_143 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_1 * * V_142 ;
struct V_1 * V_75 ;
int V_143 = F_120 ( V_2 ) ;
int V_144 = F_23 ( V_2 ) -> V_83 ;
int V_72 ;
int V_139 ;
if ( F_128 ( V_2 ) &&
F_42 ( ( V_139 = F_124 ( V_2 , 0 , 0 , V_52 ) ) ) )
return V_139 ;
V_72 = 0 ;
if ( V_143 >= V_6 )
goto V_145;
for (; V_72 < V_144 ; V_72 ++ ) {
int V_10 = V_143 + F_103 ( & F_23 ( V_2 ) -> V_76 [ V_72 ] ) ;
if ( V_10 < V_6 ) {
V_143 = V_10 ;
continue;
}
F_144 ( & F_23 ( V_2 ) -> V_76 [ V_72 ++ ] , V_6 - V_143 ) ;
V_145:
F_23 ( V_2 ) -> V_83 = V_72 ;
for (; V_72 < V_144 ; V_72 ++ )
F_106 ( V_2 , V_72 ) ;
if ( F_123 ( V_2 ) )
F_52 ( V_2 ) ;
goto V_146;
}
for ( V_142 = & F_23 ( V_2 ) -> V_78 ; ( V_75 = * V_142 ) ;
V_142 = & V_75 -> V_98 ) {
int V_10 = V_143 + V_75 -> V_6 ;
if ( F_126 ( V_75 ) ) {
struct V_1 * V_147 ;
V_147 = F_108 ( V_75 , V_52 ) ;
if ( F_42 ( ! V_147 ) )
return - V_113 ;
V_147 -> V_98 = V_75 -> V_98 ;
F_81 ( V_75 ) ;
V_75 = V_147 ;
* V_142 = V_75 ;
}
if ( V_10 < V_6 ) {
V_143 = V_10 ;
continue;
}
if ( V_10 > V_6 &&
F_42 ( ( V_139 = F_145 ( V_75 , V_6 - V_143 ) ) ) )
return V_139 ;
if ( V_75 -> V_98 )
F_50 ( & V_75 -> V_98 ) ;
break;
}
V_146:
if ( V_6 > F_120 ( V_2 ) ) {
V_2 -> V_74 -= V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
} else {
V_2 -> V_6 = V_6 ;
V_2 -> V_74 = 0 ;
F_146 ( V_2 , V_6 ) ;
}
return 0 ;
}
unsigned char * F_147 ( struct V_1 * V_2 , int V_132 )
{
int V_72 , V_148 , V_149 = ( V_2 -> V_9 + V_132 ) - V_2 -> V_10 ;
if ( V_149 > 0 || F_128 ( V_2 ) ) {
if ( F_124 ( V_2 , 0 , V_149 > 0 ? V_149 + 128 : 0 ,
V_52 ) )
return NULL ;
}
if ( F_118 ( V_2 , F_120 ( V_2 ) , F_127 ( V_2 ) , V_132 ) )
F_3 () ;
if ( ! F_123 ( V_2 ) )
goto V_150;
V_149 = V_132 ;
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ ) {
int V_14 = F_103 ( & F_23 ( V_2 ) -> V_76 [ V_72 ] ) ;
if ( V_14 >= V_149 )
goto V_150;
V_149 -= V_14 ;
}
if ( V_149 ) {
struct V_1 * V_79 = F_23 ( V_2 ) -> V_78 ;
struct V_1 * V_151 = NULL ;
struct V_1 * V_152 = NULL ;
do {
F_125 ( ! V_79 ) ;
if ( V_79 -> V_6 <= V_149 ) {
V_149 -= V_79 -> V_6 ;
V_79 = V_79 -> V_98 ;
V_152 = V_79 ;
} else {
if ( F_126 ( V_79 ) ) {
V_151 = F_108 ( V_79 , V_52 ) ;
if ( ! V_151 )
return NULL ;
V_152 = V_79 -> V_98 ;
V_79 = V_151 ;
} else {
V_152 = V_79 ;
}
if ( ! F_148 ( V_79 , V_149 ) ) {
F_76 ( V_151 ) ;
return NULL ;
}
break;
}
} while ( V_149 );
while ( ( V_79 = F_23 ( V_2 ) -> V_78 ) != V_152 ) {
F_23 ( V_2 ) -> V_78 = V_79 -> V_98 ;
F_76 ( V_79 ) ;
}
if ( V_151 ) {
V_151 -> V_98 = V_79 ;
F_23 ( V_2 ) -> V_78 = V_151 ;
}
}
V_150:
V_149 = V_132 ;
V_148 = 0 ;
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ ) {
int V_14 = F_103 ( & F_23 ( V_2 ) -> V_76 [ V_72 ] ) ;
if ( V_14 <= V_149 ) {
F_106 ( V_2 , V_72 ) ;
V_149 -= V_14 ;
} else {
F_23 ( V_2 ) -> V_76 [ V_148 ] = F_23 ( V_2 ) -> V_76 [ V_72 ] ;
if ( V_149 ) {
F_23 ( V_2 ) -> V_76 [ V_148 ] . V_114 += V_149 ;
F_149 ( & F_23 ( V_2 ) -> V_76 [ V_148 ] , V_149 ) ;
V_149 = 0 ;
}
V_148 ++ ;
}
}
F_23 ( V_2 ) -> V_83 = V_148 ;
V_2 -> V_9 += V_132 ;
V_2 -> V_74 -= V_132 ;
return F_127 ( V_2 ) ;
}
int F_118 ( const struct V_1 * V_2 , int V_143 , void * V_153 , int V_6 )
{
int V_154 = F_120 ( V_2 ) ;
struct V_1 * V_155 ;
int V_72 , V_156 ;
if ( V_143 > ( int ) V_2 -> V_6 - V_6 )
goto V_157;
if ( ( V_156 = V_154 - V_143 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
F_150 ( V_2 , V_143 , V_153 , V_156 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_143 += V_156 ;
V_153 += V_156 ;
}
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ ) {
int V_10 ;
T_4 * V_112 = & F_23 ( V_2 ) -> V_76 [ V_72 ] ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + F_103 ( V_112 ) ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
T_3 * V_111 ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_111 = F_100 ( F_101 ( V_112 ) ) ;
memcpy ( V_153 ,
V_111 + V_112 -> V_114 + V_143 - V_154 ,
V_156 ) ;
F_104 ( V_111 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_143 += V_156 ;
V_153 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
if ( F_118 ( V_155 , V_143 - V_154 , V_153 , V_156 ) )
goto V_157;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_143 += V_156 ;
V_153 += V_156 ;
}
V_154 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_157:
return - V_158 ;
}
static void F_151 ( struct V_159 * V_160 , unsigned int V_72 )
{
F_99 ( V_160 -> V_161 [ V_72 ] ) ;
}
static struct V_60 * F_152 ( struct V_60 * V_60 , unsigned int * V_6 ,
unsigned int * V_143 ,
struct V_162 * V_105 )
{
struct V_163 * V_164 = F_153 ( V_105 ) ;
if ( ! F_154 ( V_105 , V_164 ) )
return NULL ;
* V_6 = F_155 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_102 ( V_164 -> V_60 ) + V_164 -> V_143 ,
F_102 ( V_60 ) + * V_143 , * V_6 ) ;
* V_143 = V_164 -> V_143 ;
V_164 -> V_143 += * V_6 ;
return V_164 -> V_60 ;
}
static bool F_156 ( const struct V_159 * V_160 ,
struct V_60 * V_60 ,
unsigned int V_143 )
{
return V_160 -> V_165 &&
V_160 -> V_161 [ V_160 -> V_165 - 1 ] == V_60 &&
( V_160 -> V_166 [ V_160 -> V_165 - 1 ] . V_143 +
V_160 -> V_166 [ V_160 -> V_165 - 1 ] . V_6 == V_143 ) ;
}
static bool F_157 ( struct V_159 * V_160 ,
struct V_167 * V_168 , struct V_60 * V_60 ,
unsigned int * V_6 , unsigned int V_143 ,
bool V_169 ,
struct V_162 * V_105 )
{
if ( F_42 ( V_160 -> V_165 == V_170 ) )
return true ;
if ( V_169 ) {
V_60 = F_152 ( V_60 , V_6 , & V_143 , V_105 ) ;
if ( ! V_60 )
return true ;
}
if ( F_156 ( V_160 , V_60 , V_143 ) ) {
V_160 -> V_166 [ V_160 -> V_165 - 1 ] . V_6 += * V_6 ;
return false ;
}
F_158 ( V_60 ) ;
V_160 -> V_161 [ V_160 -> V_165 ] = V_60 ;
V_160 -> V_166 [ V_160 -> V_165 ] . V_6 = * V_6 ;
V_160 -> V_166 [ V_160 -> V_165 ] . V_143 = V_143 ;
V_160 -> V_165 ++ ;
return false ;
}
static bool F_159 ( struct V_60 * V_60 , unsigned int V_171 ,
unsigned int V_172 , unsigned int * V_73 ,
unsigned int * V_6 ,
struct V_159 * V_160 , bool V_169 ,
struct V_162 * V_105 ,
struct V_167 * V_168 )
{
if ( ! * V_6 )
return true ;
if ( * V_73 >= V_172 ) {
* V_73 -= V_172 ;
return false ;
}
V_171 += * V_73 ;
V_172 -= * V_73 ;
* V_73 = 0 ;
do {
unsigned int V_173 = F_160 ( * V_6 , V_172 ) ;
if ( F_157 ( V_160 , V_168 , V_60 , & V_173 , V_171 ,
V_169 , V_105 ) )
return true ;
V_171 += V_173 ;
V_172 -= V_173 ;
* V_6 -= V_173 ;
} while ( * V_6 && V_172 );
return false ;
}
static bool F_161 ( struct V_1 * V_2 , struct V_167 * V_168 ,
unsigned int * V_143 , unsigned int * V_6 ,
struct V_159 * V_160 , struct V_162 * V_105 )
{
int V_174 ;
struct V_1 * V_175 ;
if ( F_159 ( F_162 ( V_2 -> V_8 ) ,
( unsigned long ) V_2 -> V_8 & ( V_63 - 1 ) ,
F_120 ( V_2 ) ,
V_143 , V_6 , V_160 ,
F_163 ( V_2 ) ,
V_105 , V_168 ) )
return true ;
for ( V_174 = 0 ; V_174 < F_23 ( V_2 ) -> V_83 ; V_174 ++ ) {
const T_4 * V_112 = & F_23 ( V_2 ) -> V_76 [ V_174 ] ;
if ( F_159 ( F_101 ( V_112 ) ,
V_112 -> V_114 , F_103 ( V_112 ) ,
V_143 , V_6 , V_160 , false , V_105 , V_168 ) )
return true ;
}
F_54 (skb, iter) {
if ( * V_143 >= V_175 -> V_6 ) {
* V_143 -= V_175 -> V_6 ;
continue;
}
if ( F_161 ( V_175 , V_168 , V_143 , V_6 , V_160 , V_105 ) )
return true ;
}
return false ;
}
T_6 F_164 ( struct V_162 * V_105 ,
struct V_167 * V_168 ,
struct V_159 * V_160 )
{
int V_176 ;
F_165 ( V_105 ) ;
V_176 = F_166 ( V_168 , V_160 ) ;
F_167 ( V_105 ) ;
return V_176 ;
}
int F_168 ( struct V_1 * V_2 , struct V_162 * V_105 , unsigned int V_143 ,
struct V_167 * V_168 , unsigned int V_177 ,
unsigned int V_15 ,
T_6 (* F_169)( struct V_162 * ,
struct V_167 * ,
struct V_159 * ) )
{
struct V_178 V_166 [ V_170 ] ;
struct V_60 * V_161 [ V_170 ] ;
struct V_159 V_160 = {
. V_161 = V_161 ,
. V_166 = V_166 ,
. V_179 = V_170 ,
. V_15 = V_15 ,
. V_180 = & V_181 ,
. V_182 = F_151 ,
} ;
int V_176 = 0 ;
F_161 ( V_2 , V_168 , & V_143 , & V_177 , & V_160 , V_105 ) ;
if ( V_160 . V_165 )
V_176 = F_169 ( V_105 , V_168 , & V_160 ) ;
return V_176 ;
}
int F_170 ( struct V_1 * V_2 , int V_143 , const void * V_183 , int V_6 )
{
int V_154 = F_120 ( V_2 ) ;
struct V_1 * V_155 ;
int V_72 , V_156 ;
if ( V_143 > ( int ) V_2 -> V_6 - V_6 )
goto V_157;
if ( ( V_156 = V_154 - V_143 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
F_171 ( V_2 , V_143 , V_183 , V_156 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_143 += V_156 ;
V_183 += V_156 ;
}
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ ) {
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_72 ] ;
int V_10 ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + F_103 ( V_75 ) ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
T_3 * V_111 ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_111 = F_100 ( F_101 ( V_75 ) ) ;
memcpy ( V_111 + V_75 -> V_114 + V_143 - V_154 ,
V_183 , V_156 ) ;
F_104 ( V_111 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_143 += V_156 ;
V_183 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
if ( F_170 ( V_155 , V_143 - V_154 ,
V_183 , V_156 ) )
goto V_157;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_143 += V_156 ;
V_183 += V_156 ;
}
V_154 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_157:
return - V_158 ;
}
T_7 F_172 ( const struct V_1 * V_2 , int V_143 , int V_6 ,
T_7 V_184 , const struct V_185 * V_180 )
{
int V_154 = F_120 ( V_2 ) ;
int V_72 , V_156 = V_154 - V_143 ;
struct V_1 * V_155 ;
int V_186 = 0 ;
if ( V_156 > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
V_184 = V_180 -> V_187 ( V_2 -> V_8 + V_143 , V_156 , V_184 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_184 ;
V_143 += V_156 ;
V_186 = V_156 ;
}
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ ) {
int V_10 ;
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_72 ] ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + F_103 ( V_75 ) ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
T_7 V_188 ;
T_3 * V_111 ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_111 = F_100 ( F_101 ( V_75 ) ) ;
V_188 = V_180 -> V_187 ( V_111 + V_75 -> V_114 +
V_143 - V_154 , V_156 , 0 ) ;
F_104 ( V_111 ) ;
V_184 = V_180 -> V_189 ( V_184 , V_188 , V_186 , V_156 ) ;
if ( ! ( V_6 -= V_156 ) )
return V_184 ;
V_143 += V_156 ;
V_186 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
T_7 V_188 ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_188 = F_172 ( V_155 , V_143 - V_154 ,
V_156 , 0 , V_180 ) ;
V_184 = V_180 -> V_189 ( V_184 , V_188 , V_186 , V_156 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_184 ;
V_143 += V_156 ;
V_186 += V_156 ;
}
V_154 = V_10 ;
}
F_125 ( V_6 ) ;
return V_184 ;
}
T_7 F_173 ( const struct V_1 * V_2 , int V_143 ,
int V_6 , T_7 V_184 )
{
const struct V_185 V_180 = {
. V_187 = V_190 ,
. V_189 = V_191 ,
} ;
return F_172 ( V_2 , V_143 , V_6 , V_184 , & V_180 ) ;
}
T_7 F_174 ( const struct V_1 * V_2 , int V_143 ,
T_3 * V_153 , int V_6 , T_7 V_184 )
{
int V_154 = F_120 ( V_2 ) ;
int V_72 , V_156 = V_154 - V_143 ;
struct V_1 * V_155 ;
int V_186 = 0 ;
if ( V_156 > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
V_184 = F_175 ( V_2 -> V_8 + V_143 , V_153 ,
V_156 , V_184 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_184 ;
V_143 += V_156 ;
V_153 += V_156 ;
V_186 = V_156 ;
}
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ ) {
int V_10 ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + F_103 ( & F_23 ( V_2 ) -> V_76 [ V_72 ] ) ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
T_7 V_188 ;
T_3 * V_111 ;
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_72 ] ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_111 = F_100 ( F_101 ( V_75 ) ) ;
V_188 = F_175 ( V_111 +
V_75 -> V_114 +
V_143 - V_154 , V_153 ,
V_156 , 0 ) ;
F_104 ( V_111 ) ;
V_184 = F_176 ( V_184 , V_188 , V_186 ) ;
if ( ! ( V_6 -= V_156 ) )
return V_184 ;
V_143 += V_156 ;
V_153 += V_156 ;
V_186 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
T_7 V_188 ;
int V_10 ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
V_188 = F_174 ( V_155 ,
V_143 - V_154 ,
V_153 , V_156 , 0 ) ;
V_184 = F_176 ( V_184 , V_188 , V_186 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_184 ;
V_143 += V_156 ;
V_153 += V_156 ;
V_186 += V_156 ;
}
V_154 = V_10 ;
}
F_125 ( V_6 ) ;
return V_184 ;
}
unsigned int
F_177 ( const struct V_1 * V_183 )
{
unsigned int V_192 = 0 ;
if ( ! V_183 -> V_53 ||
F_120 ( V_183 ) < V_193 ||
F_23 ( V_183 ) -> V_83 >= V_170 )
V_192 = F_120 ( V_183 ) ;
if ( F_123 ( V_183 ) )
V_192 = V_183 -> V_6 ;
return V_192 ;
}
int
F_178 ( struct V_1 * V_153 , struct V_1 * V_183 , int V_6 , int V_192 )
{
int V_72 , V_194 = 0 ;
int V_172 = 0 ;
int V_176 ;
struct V_60 * V_60 ;
unsigned int V_143 ;
F_125 ( ! V_183 -> V_53 && ! V_192 ) ;
if ( V_6 <= F_134 ( V_153 ) )
return F_118 ( V_183 , 0 , F_117 ( V_153 , V_6 ) , V_6 ) ;
if ( V_192 ) {
V_176 = F_118 ( V_183 , 0 , F_117 ( V_153 , V_192 ) , V_192 ) ;
if ( F_42 ( V_176 ) )
return V_176 ;
V_6 -= V_192 ;
} else {
V_172 = F_155 ( int , F_120 ( V_183 ) , V_6 ) ;
if ( V_172 ) {
V_60 = F_32 ( V_183 -> V_7 ) ;
V_143 = V_183 -> V_8 - ( unsigned char * ) F_102 ( V_60 ) ;
F_107 ( V_153 , 0 , V_60 , V_143 , V_172 ) ;
F_158 ( V_60 ) ;
V_194 = 1 ;
V_6 -= V_172 ;
}
}
V_153 -> V_27 += V_6 + V_172 ;
V_153 -> V_6 += V_6 + V_172 ;
V_153 -> V_74 += V_6 + V_172 ;
if ( F_42 ( F_109 ( V_183 , V_52 ) ) ) {
F_80 ( V_183 ) ;
return - V_113 ;
}
for ( V_72 = 0 ; V_72 < F_23 ( V_183 ) -> V_83 ; V_72 ++ ) {
if ( ! V_6 )
break;
F_23 ( V_153 ) -> V_76 [ V_194 ] = F_23 ( V_183 ) -> V_76 [ V_72 ] ;
F_23 ( V_153 ) -> V_76 [ V_194 ] . V_14 = F_155 ( int , F_23 ( V_153 ) -> V_76 [ V_194 ] . V_14 , V_6 ) ;
V_6 -= F_23 ( V_153 ) -> V_76 [ V_194 ] . V_14 ;
F_122 ( V_153 , V_194 ) ;
V_194 ++ ;
}
F_23 ( V_153 ) -> V_83 = V_194 ;
return 0 ;
}
void F_179 ( const struct V_1 * V_2 , T_3 * V_153 )
{
T_7 V_184 ;
long V_195 ;
if ( V_2 -> V_115 == V_116 )
V_195 = F_180 ( V_2 ) ;
else
V_195 = F_120 ( V_2 ) ;
F_125 ( V_195 > F_120 ( V_2 ) ) ;
F_121 ( V_2 , V_153 , V_195 ) ;
V_184 = 0 ;
if ( V_195 != V_2 -> V_6 )
V_184 = F_174 ( V_2 , V_195 , V_153 + V_195 ,
V_2 -> V_6 - V_195 , 0 ) ;
if ( V_2 -> V_115 == V_116 ) {
long V_196 = V_195 + V_2 -> V_197 ;
* ( ( V_198 * ) ( V_153 + V_196 ) ) = F_181 ( V_184 ) ;
}
}
struct V_1 * F_182 ( struct V_199 * V_79 )
{
unsigned long V_15 ;
struct V_1 * V_200 ;
F_183 ( & V_79 -> V_201 , V_15 ) ;
V_200 = F_184 ( V_79 ) ;
F_185 ( & V_79 -> V_201 , V_15 ) ;
return V_200 ;
}
struct V_1 * F_186 ( struct V_199 * V_79 )
{
unsigned long V_15 ;
struct V_1 * V_200 ;
F_183 ( & V_79 -> V_201 , V_15 ) ;
V_200 = F_187 ( V_79 ) ;
F_185 ( & V_79 -> V_201 , V_15 ) ;
return V_200 ;
}
void F_188 ( struct V_199 * V_79 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_182 ( V_79 ) ) != NULL )
F_76 ( V_2 ) ;
}
void F_189 ( struct V_199 * V_79 , struct V_1 * V_202 )
{
unsigned long V_15 ;
F_183 ( & V_79 -> V_201 , V_15 ) ;
F_190 ( V_79 , V_202 ) ;
F_185 ( & V_79 -> V_201 , V_15 ) ;
}
void F_191 ( struct V_199 * V_79 , struct V_1 * V_202 )
{
unsigned long V_15 ;
F_183 ( & V_79 -> V_201 , V_15 ) ;
F_192 ( V_79 , V_202 ) ;
F_185 ( & V_79 -> V_201 , V_15 ) ;
}
void F_193 ( struct V_1 * V_2 , struct V_199 * V_79 )
{
unsigned long V_15 ;
F_183 ( & V_79 -> V_201 , V_15 ) ;
F_194 ( V_2 , V_79 ) ;
F_185 ( & V_79 -> V_201 , V_15 ) ;
}
void F_195 ( struct V_1 * V_123 , struct V_1 * V_202 , struct V_199 * V_79 )
{
unsigned long V_15 ;
F_183 ( & V_79 -> V_201 , V_15 ) ;
F_196 ( V_79 , V_123 , V_202 ) ;
F_185 ( & V_79 -> V_201 , V_15 ) ;
}
void F_197 ( struct V_1 * V_123 , struct V_1 * V_202 , struct V_199 * V_79 )
{
unsigned long V_15 ;
F_183 ( & V_79 -> V_201 , V_15 ) ;
F_198 ( V_202 , V_123 -> V_104 , V_123 , V_79 ) ;
F_185 ( & V_79 -> V_201 , V_15 ) ;
}
static inline void F_199 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_8 V_6 , const int V_186 )
{
int V_72 ;
F_150 ( V_2 , V_6 , F_117 ( V_44 , V_186 - V_6 ) ,
V_186 - V_6 ) ;
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ )
F_23 ( V_44 ) -> V_76 [ V_72 ] = F_23 ( V_2 ) -> V_76 [ V_72 ] ;
F_23 ( V_44 ) -> V_83 = F_23 ( V_2 ) -> V_83 ;
F_23 ( V_2 ) -> V_83 = 0 ;
V_44 -> V_74 = V_2 -> V_74 ;
V_44 -> V_6 += V_44 -> V_74 ;
V_2 -> V_74 = 0 ;
V_2 -> V_6 = V_6 ;
F_146 ( V_2 , V_6 ) ;
}
static inline void F_200 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_8 V_6 , int V_186 )
{
int V_72 , V_148 = 0 ;
const int V_144 = F_23 ( V_2 ) -> V_83 ;
F_23 ( V_2 ) -> V_83 = 0 ;
V_44 -> V_6 = V_44 -> V_74 = V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_74 = V_6 - V_186 ;
for ( V_72 = 0 ; V_72 < V_144 ; V_72 ++ ) {
int V_14 = F_103 ( & F_23 ( V_2 ) -> V_76 [ V_72 ] ) ;
if ( V_186 + V_14 > V_6 ) {
F_23 ( V_44 ) -> V_76 [ V_148 ] = F_23 ( V_2 ) -> V_76 [ V_72 ] ;
if ( V_186 < V_6 ) {
F_122 ( V_2 , V_72 ) ;
F_23 ( V_44 ) -> V_76 [ 0 ] . V_114 += V_6 - V_186 ;
F_149 ( & F_23 ( V_44 ) -> V_76 [ 0 ] , V_6 - V_186 ) ;
F_144 ( & F_23 ( V_2 ) -> V_76 [ V_72 ] , V_6 - V_186 ) ;
F_23 ( V_2 ) -> V_83 ++ ;
}
V_148 ++ ;
} else
F_23 ( V_2 ) -> V_83 ++ ;
V_186 += V_14 ;
}
F_23 ( V_44 ) -> V_83 = V_148 ;
}
void F_201 ( struct V_1 * V_2 , struct V_1 * V_44 , const T_8 V_6 )
{
int V_186 = F_120 ( V_2 ) ;
F_23 ( V_44 ) -> V_84 = F_23 ( V_2 ) -> V_84 & V_203 ;
if ( V_6 < V_186 )
F_199 ( V_2 , V_44 , V_6 , V_186 ) ;
else
F_200 ( V_2 , V_44 , V_6 , V_186 ) ;
}
static int F_202 ( struct V_1 * V_2 )
{
return F_128 ( V_2 ) && F_124 ( V_2 , 0 , 0 , V_52 ) ;
}
int F_203 ( struct V_1 * V_204 , struct V_1 * V_2 , int V_205 )
{
int V_183 , V_153 , V_206 , V_207 ;
struct V_208 * V_209 , * V_210 ;
F_125 ( V_205 > V_2 -> V_6 ) ;
F_125 ( F_120 ( V_2 ) ) ;
V_207 = V_205 ;
V_183 = 0 ;
V_153 = F_23 ( V_204 ) -> V_83 ;
V_209 = & F_23 ( V_2 ) -> V_76 [ V_183 ] ;
if ( ! V_153 ||
! F_204 ( V_204 , V_153 , F_101 ( V_209 ) ,
V_209 -> V_114 ) ) {
V_206 = - 1 ;
} else {
V_206 = V_153 - 1 ;
V_207 -= F_103 ( V_209 ) ;
if ( V_207 < 0 ) {
if ( F_202 ( V_2 ) ||
F_202 ( V_204 ) )
return 0 ;
V_209 = & F_23 ( V_2 ) -> V_76 [ V_183 ] ;
V_210 = & F_23 ( V_204 ) -> V_76 [ V_206 ] ;
F_49 ( V_210 , V_205 ) ;
F_149 ( V_209 , V_205 ) ;
V_209 -> V_114 += V_205 ;
goto V_211;
}
V_183 ++ ;
}
if ( ( V_205 == V_2 -> V_6 ) &&
( F_23 ( V_2 ) -> V_83 - V_183 ) > ( V_170 - V_153 ) )
return 0 ;
if ( F_202 ( V_2 ) || F_202 ( V_204 ) )
return 0 ;
while ( ( V_207 > 0 ) && ( V_183 < F_23 ( V_2 ) -> V_83 ) ) {
if ( V_153 == V_170 )
return 0 ;
V_209 = & F_23 ( V_2 ) -> V_76 [ V_183 ] ;
V_210 = & F_23 ( V_204 ) -> V_76 [ V_153 ] ;
if ( V_207 >= F_103 ( V_209 ) ) {
* V_210 = * V_209 ;
V_207 -= F_103 ( V_209 ) ;
V_183 ++ ;
V_153 ++ ;
} else {
F_205 ( V_209 ) ;
V_210 -> V_60 = V_209 -> V_60 ;
V_210 -> V_114 = V_209 -> V_114 ;
F_144 ( V_210 , V_207 ) ;
V_209 -> V_114 += V_207 ;
F_149 ( V_209 , V_207 ) ;
V_207 = 0 ;
V_153 ++ ;
break;
}
}
F_23 ( V_204 ) -> V_83 = V_153 ;
if ( V_206 >= 0 ) {
V_209 = & F_23 ( V_2 ) -> V_76 [ 0 ] ;
V_210 = & F_23 ( V_204 ) -> V_76 [ V_206 ] ;
F_49 ( V_210 , F_103 ( V_209 ) ) ;
F_60 ( V_209 ) ;
}
V_153 = 0 ;
while ( V_183 < F_23 ( V_2 ) -> V_83 )
F_23 ( V_2 ) -> V_76 [ V_153 ++ ] = F_23 ( V_2 ) -> V_76 [ V_183 ++ ] ;
F_23 ( V_2 ) -> V_83 = V_153 ;
F_125 ( V_207 > 0 && ! F_23 ( V_2 ) -> V_83 ) ;
V_211:
V_204 -> V_115 = V_116 ;
V_2 -> V_115 = V_116 ;
V_2 -> V_6 -= V_205 ;
V_2 -> V_74 -= V_205 ;
V_2 -> V_27 -= V_205 ;
V_204 -> V_6 += V_205 ;
V_204 -> V_74 += V_205 ;
V_204 -> V_27 += V_205 ;
return V_205 ;
}
void F_206 ( struct V_1 * V_2 , unsigned int V_183 ,
unsigned int V_153 , struct V_212 * V_213 )
{
V_213 -> V_214 = V_183 ;
V_213 -> V_215 = V_153 ;
V_213 -> V_216 = V_213 -> V_217 = V_2 ;
V_213 -> V_218 = V_213 -> V_219 = 0 ;
V_213 -> V_220 = NULL ;
}
unsigned int F_207 ( unsigned int V_221 , const T_3 * * V_8 ,
struct V_212 * V_213 )
{
unsigned int V_222 , V_223 = V_221 + V_213 -> V_214 ;
T_4 * V_75 ;
if ( F_42 ( V_223 >= V_213 -> V_215 ) ) {
if ( V_213 -> V_220 ) {
F_104 ( V_213 -> V_220 ) ;
V_213 -> V_220 = NULL ;
}
return 0 ;
}
V_224:
V_222 = F_120 ( V_213 -> V_217 ) + V_213 -> V_219 ;
if ( V_223 < V_222 && ! V_213 -> V_220 ) {
* V_8 = V_213 -> V_217 -> V_8 + ( V_223 - V_213 -> V_219 ) ;
return V_222 - V_223 ;
}
if ( V_213 -> V_218 == 0 && ! V_213 -> V_220 )
V_213 -> V_219 += F_120 ( V_213 -> V_217 ) ;
while ( V_213 -> V_218 < F_23 ( V_213 -> V_217 ) -> V_83 ) {
V_75 = & F_23 ( V_213 -> V_217 ) -> V_76 [ V_213 -> V_218 ] ;
V_222 = F_103 ( V_75 ) + V_213 -> V_219 ;
if ( V_223 < V_222 ) {
if ( ! V_213 -> V_220 )
V_213 -> V_220 = F_100 ( F_101 ( V_75 ) ) ;
* V_8 = ( T_3 * ) V_213 -> V_220 + V_75 -> V_114 +
( V_223 - V_213 -> V_219 ) ;
return V_222 - V_223 ;
}
if ( V_213 -> V_220 ) {
F_104 ( V_213 -> V_220 ) ;
V_213 -> V_220 = NULL ;
}
V_213 -> V_218 ++ ;
V_213 -> V_219 += F_103 ( V_75 ) ;
}
if ( V_213 -> V_220 ) {
F_104 ( V_213 -> V_220 ) ;
V_213 -> V_220 = NULL ;
}
if ( V_213 -> V_216 == V_213 -> V_217 && F_123 ( V_213 -> V_216 ) ) {
V_213 -> V_217 = F_23 ( V_213 -> V_216 ) -> V_78 ;
V_213 -> V_218 = 0 ;
goto V_224;
} else if ( V_213 -> V_217 -> V_98 ) {
V_213 -> V_217 = V_213 -> V_217 -> V_98 ;
V_213 -> V_218 = 0 ;
goto V_224;
}
return 0 ;
}
void F_208 ( struct V_212 * V_213 )
{
if ( V_213 -> V_220 )
F_104 ( V_213 -> V_220 ) ;
}
static unsigned int F_209 ( unsigned int V_143 , const T_3 * * V_225 ,
struct V_226 * V_227 ,
struct V_228 * V_229 )
{
return F_207 ( V_143 , V_225 , F_210 ( V_229 ) ) ;
}
static void F_211 ( struct V_226 * V_227 , struct V_228 * V_229 )
{
F_208 ( F_210 ( V_229 ) ) ;
}
unsigned int F_212 ( struct V_1 * V_2 , unsigned int V_183 ,
unsigned int V_153 , struct V_226 * V_230 )
{
struct V_228 V_229 ;
unsigned int V_176 ;
V_230 -> V_231 = F_209 ;
V_230 -> V_232 = F_211 ;
F_206 ( V_2 , V_183 , V_153 , F_210 ( & V_229 ) ) ;
V_176 = F_213 ( V_230 , & V_229 ) ;
return ( V_176 <= V_153 - V_183 ? V_176 : V_233 ) ;
}
int F_214 ( struct V_162 * V_105 , struct V_1 * V_2 ,
int (* F_215)( void * V_183 , char * V_153 , int V_143 ,
int V_6 , int V_234 , struct V_1 * V_2 ) ,
void * V_183 , int V_235 )
{
int V_236 = F_23 ( V_2 ) -> V_83 ;
int V_156 ;
int V_143 = 0 ;
int V_176 ;
struct V_163 * V_164 = & V_237 -> V_238 ;
do {
if ( V_236 >= V_170 )
return - V_239 ;
if ( ! F_154 ( V_105 , V_164 ) )
return - V_113 ;
V_156 = F_155 ( int , V_235 , V_164 -> V_14 - V_164 -> V_143 ) ;
V_176 = F_215 ( V_183 , F_102 ( V_164 -> V_60 ) + V_164 -> V_143 ,
V_143 , V_156 , 0 , V_2 ) ;
if ( V_176 < 0 )
return - V_158 ;
F_47 ( V_2 , V_236 , V_164 -> V_60 , V_164 -> V_143 ,
V_156 ) ;
V_236 ++ ;
V_164 -> V_143 += V_156 ;
F_158 ( V_164 -> V_60 ) ;
V_2 -> V_27 += V_156 ;
F_216 ( V_156 , & V_105 -> V_240 ) ;
V_2 -> V_6 += V_156 ;
V_2 -> V_74 += V_156 ;
V_143 += V_156 ;
V_235 -= V_156 ;
} while ( V_235 > 0 );
return 0 ;
}
int F_217 ( struct V_1 * V_2 , struct V_60 * V_60 ,
int V_143 , T_1 V_14 )
{
int V_72 = F_23 ( V_2 ) -> V_83 ;
if ( F_204 ( V_2 , V_72 , V_60 , V_143 ) ) {
F_49 ( & F_23 ( V_2 ) -> V_76 [ V_72 - 1 ] , V_14 ) ;
} else if ( V_72 < V_170 ) {
F_158 ( V_60 ) ;
F_47 ( V_2 , V_72 , V_60 , V_143 , V_14 ) ;
} else {
return - V_239 ;
}
return 0 ;
}
unsigned char * F_218 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned char * V_8 = V_2 -> V_8 ;
F_125 ( V_6 > V_2 -> V_6 ) ;
F_219 ( V_2 , V_6 ) ;
F_220 ( V_2 , V_8 , V_6 ) ;
return V_2 -> V_8 ;
}
struct V_1 * F_221 ( struct V_1 * V_241 ,
T_9 V_242 )
{
struct V_1 * V_97 = NULL ;
struct V_1 * V_9 = NULL ;
struct V_1 * V_243 = F_23 ( V_241 ) -> V_78 ;
T_4 * V_75 = F_23 ( V_241 ) -> V_76 ;
unsigned int V_244 = F_23 ( V_241 ) -> V_124 ;
unsigned int V_245 = V_241 -> V_8 - F_222 ( V_241 ) ;
struct V_1 * V_246 = V_241 ;
unsigned int V_143 = V_245 ;
unsigned int V_247 = F_223 ( V_241 ) ;
unsigned int V_248 = 0 ;
unsigned int V_128 ;
unsigned int V_6 = V_241 -> V_6 ;
T_10 V_249 ;
bool V_184 , V_250 ;
int V_144 = F_23 ( V_241 ) -> V_83 ;
int V_139 = - V_113 ;
int V_72 = 0 ;
int V_186 ;
int V_251 ;
F_224 ( V_241 , V_245 ) ;
V_249 = F_225 ( V_241 , & V_251 ) ;
if ( F_42 ( ! V_249 ) )
return F_226 ( - V_252 ) ;
V_250 = ! ! ( V_242 & V_253 ) ;
V_184 = ! ! F_227 ( V_242 , V_249 ) ;
if ( V_250 && V_184 && ( V_242 & V_254 ) ) {
V_248 = V_6 / V_244 ;
if ( V_248 > 1 )
V_244 *= V_248 ;
else
V_248 = 0 ;
}
V_128 = F_93 ( V_241 ) ;
V_186 = F_120 ( V_241 ) ;
do {
struct V_1 * V_255 ;
T_4 * V_256 ;
int V_257 ;
int V_14 ;
V_6 = V_241 -> V_6 - V_143 ;
if ( V_6 > V_244 )
V_6 = V_244 ;
V_257 = F_120 ( V_241 ) - V_143 ;
if ( V_257 < 0 )
V_257 = 0 ;
if ( V_257 > V_6 || ! V_250 )
V_257 = V_6 ;
if ( ! V_257 && V_72 >= V_144 && F_120 ( V_243 ) &&
( F_120 ( V_243 ) == V_6 || V_250 ) ) {
F_125 ( F_120 ( V_243 ) > V_6 ) ;
V_72 = 0 ;
V_144 = F_23 ( V_243 ) -> V_83 ;
V_75 = F_23 ( V_243 ) -> V_76 ;
V_246 = V_243 ;
V_186 += F_120 ( V_243 ) ;
while ( V_186 < V_143 + V_6 ) {
F_125 ( V_72 >= V_144 ) ;
V_14 = F_103 ( V_75 ) ;
if ( V_186 + V_14 > V_143 + V_6 )
break;
V_72 ++ ;
V_186 += V_14 ;
V_75 ++ ;
}
V_255 = F_108 ( V_243 , V_52 ) ;
V_243 = V_243 -> V_98 ;
if ( F_42 ( ! V_255 ) )
goto V_139;
if ( F_42 ( F_145 ( V_255 , V_6 ) ) ) {
F_76 ( V_255 ) ;
goto V_139;
}
V_257 = F_116 ( V_255 ) ;
if ( F_228 ( V_255 , V_245 + V_128 ) ) {
F_76 ( V_255 ) ;
goto V_139;
}
V_255 -> V_27 += F_116 ( V_255 ) - V_257 ;
F_64 ( V_255 ) ;
F_224 ( V_255 , V_245 ) ;
} else {
V_255 = F_14 ( V_257 + V_245 + V_128 ,
V_52 , F_114 ( V_241 ) ,
V_66 ) ;
if ( F_42 ( ! V_255 ) )
goto V_139;
F_44 ( V_255 , V_128 ) ;
F_229 ( V_255 , V_245 ) ;
}
if ( V_97 )
V_9 -> V_98 = V_255 ;
else
V_97 = V_255 ;
V_9 = V_255 ;
F_92 ( V_255 , V_241 ) ;
F_111 ( V_255 , F_93 ( V_255 ) - V_128 ) ;
F_230 ( V_255 ) ;
F_150 ( V_241 , - V_247 ,
V_255 -> V_8 - V_247 ,
V_245 + V_247 ) ;
if ( V_255 -> V_6 == V_6 + V_245 )
goto V_258;
if ( ! V_250 ) {
if ( ! V_255 -> V_259 )
V_255 -> V_115 = V_260 ;
F_231 ( V_255 ) -> V_184 =
F_174 ( V_241 , V_143 ,
F_117 ( V_255 , V_6 ) ,
V_6 , 0 ) ;
F_231 ( V_255 ) -> V_117 =
F_93 ( V_255 ) + V_245 ;
continue;
}
V_256 = F_23 ( V_255 ) -> V_76 ;
F_150 ( V_241 , V_143 ,
F_117 ( V_255 , V_257 ) , V_257 ) ;
F_23 ( V_255 ) -> V_84 = F_23 ( V_241 ) -> V_84 &
V_203 ;
while ( V_186 < V_143 + V_6 ) {
if ( V_72 >= V_144 ) {
F_125 ( F_120 ( V_243 ) ) ;
V_72 = 0 ;
V_144 = F_23 ( V_243 ) -> V_83 ;
V_75 = F_23 ( V_243 ) -> V_76 ;
V_246 = V_243 ;
F_125 ( ! V_144 ) ;
V_243 = V_243 -> V_98 ;
}
if ( F_42 ( F_23 ( V_255 ) -> V_83 >=
V_170 ) ) {
F_232 (
L_3 ,
V_186 , V_244 ) ;
goto V_139;
}
if ( F_42 ( F_109 ( V_246 , V_52 ) ) )
goto V_139;
* V_256 = * V_75 ;
F_205 ( V_256 ) ;
V_14 = F_103 ( V_256 ) ;
if ( V_186 < V_143 ) {
V_256 -> V_114 += V_143 - V_186 ;
F_149 ( V_256 , V_143 - V_186 ) ;
}
F_23 ( V_255 ) -> V_83 ++ ;
if ( V_186 + V_14 <= V_143 + V_6 ) {
V_72 ++ ;
V_75 ++ ;
V_186 += V_14 ;
} else {
F_149 ( V_256 , V_186 + V_14 - ( V_143 + V_6 ) ) ;
goto V_261;
}
V_256 ++ ;
}
V_261:
V_255 -> V_74 = V_6 - V_257 ;
V_255 -> V_6 += V_255 -> V_74 ;
V_255 -> V_27 += V_255 -> V_74 ;
V_258:
if ( ! V_184 ) {
if ( F_233 ( V_255 ) ) {
V_139 = F_234 ( V_255 ) ;
if ( V_139 )
goto V_139;
}
if ( ! V_255 -> V_259 )
V_255 -> V_115 = V_260 ;
F_231 ( V_255 ) -> V_184 =
F_173 ( V_255 , V_245 ,
V_255 -> V_6 - V_245 , 0 ) ;
F_231 ( V_255 ) -> V_117 =
F_93 ( V_255 ) + V_245 ;
}
} while ( ( V_143 += V_6 ) < V_241 -> V_6 );
V_97 -> V_104 = V_9 ;
if ( V_248 ) {
int type = F_23 ( V_241 ) -> V_126 ;
type |= V_262 ;
type &= ~ V_263 ;
F_23 ( V_97 ) -> V_124 = F_23 ( V_241 ) -> V_124 ;
F_23 ( V_97 ) -> V_125 = V_248 ;
F_23 ( V_97 ) -> V_126 = type ;
F_231 ( V_97 ) -> V_264 = F_93 ( V_97 ) + V_245 ;
}
if ( V_241 -> V_92 == V_265 ) {
F_235 ( V_9 -> V_27 , V_241 -> V_27 ) ;
F_235 ( V_9 -> V_92 , V_241 -> V_92 ) ;
F_235 ( V_9 -> V_105 , V_241 -> V_105 ) ;
}
return V_97 ;
V_139:
F_51 ( V_97 ) ;
return F_226 ( V_139 ) ;
}
int F_236 ( struct V_1 * * V_7 , struct V_1 * V_2 )
{
struct V_32 * V_266 , * V_267 = F_23 ( V_2 ) ;
unsigned int V_143 = F_237 ( V_2 ) ;
unsigned int V_268 = F_120 ( V_2 ) ;
unsigned int V_6 = F_238 ( V_2 ) ;
struct V_1 * V_269 , * V_270 = * V_7 ;
unsigned int V_271 ;
if ( F_42 ( V_270 -> V_6 + V_6 >= 65536 ) )
return - V_272 ;
V_269 = F_239 ( V_270 ) -> V_273 ;
V_266 = F_23 ( V_269 ) ;
if ( V_268 <= V_143 ) {
T_4 * V_75 ;
T_4 * V_274 ;
int V_72 = V_267 -> V_83 ;
int V_83 = V_266 -> V_83 + V_72 ;
if ( V_83 > V_170 )
goto V_206;
V_143 -= V_268 ;
V_266 -> V_83 = V_83 ;
V_267 -> V_83 = 0 ;
V_75 = V_266 -> V_76 + V_83 ;
V_274 = V_267 -> V_76 + V_72 ;
do {
* -- V_75 = * -- V_274 ;
} while ( -- V_72 );
V_75 -> V_114 += V_143 ;
F_149 ( V_75 , V_143 ) ;
V_271 = V_2 -> V_27 -
F_21 ( F_116 ( V_2 ) ) ;
V_2 -> V_27 -= V_2 -> V_74 ;
V_2 -> V_6 -= V_2 -> V_74 ;
V_2 -> V_74 = 0 ;
F_239 ( V_2 ) -> free = V_275 ;
goto V_146;
} else if ( V_2 -> V_53 ) {
int V_83 = V_266 -> V_83 ;
T_4 * V_75 = V_266 -> V_76 + V_83 ;
struct V_60 * V_60 = F_32 ( V_2 -> V_7 ) ;
unsigned int V_276 = V_268 - V_143 ;
unsigned int V_277 ;
if ( V_83 + 1 + V_267 -> V_83 > V_170 )
goto V_206;
V_277 = V_2 -> V_8 -
( unsigned char * ) F_102 ( V_60 ) +
V_143 ;
V_266 -> V_83 = V_83 + 1 + V_267 -> V_83 ;
V_75 -> V_60 . V_270 = V_60 ;
V_75 -> V_114 = V_277 ;
F_144 ( V_75 , V_276 ) ;
memcpy ( V_75 + 1 , V_267 -> V_76 , sizeof( * V_75 ) * V_267 -> V_83 ) ;
V_271 = V_2 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
F_239 ( V_2 ) -> free = V_278 ;
goto V_146;
}
V_206:
V_271 = V_2 -> V_27 ;
if ( V_143 > V_268 ) {
unsigned int V_149 = V_143 - V_268 ;
V_267 -> V_76 [ 0 ] . V_114 += V_149 ;
F_149 ( & V_267 -> V_76 [ 0 ] , V_149 ) ;
V_2 -> V_74 -= V_149 ;
V_2 -> V_6 -= V_149 ;
V_143 = V_268 ;
}
F_219 ( V_2 , V_143 ) ;
if ( F_239 ( V_270 ) -> V_273 == V_270 )
F_23 ( V_270 ) -> V_78 = V_2 ;
else
F_239 ( V_270 ) -> V_273 -> V_98 = V_2 ;
F_239 ( V_270 ) -> V_273 = V_2 ;
F_240 ( V_2 ) ;
V_269 = V_270 ;
V_146:
F_239 ( V_270 ) -> V_279 ++ ;
V_270 -> V_74 += V_6 ;
V_270 -> V_27 += V_271 ;
V_270 -> V_6 += V_6 ;
if ( V_269 != V_270 ) {
V_269 -> V_74 += V_6 ;
V_269 -> V_27 += V_271 ;
V_269 -> V_6 += V_6 ;
}
F_239 ( V_2 ) -> V_280 = 1 ;
return 0 ;
}
void T_11 F_241 ( void )
{
V_25 = F_242 ( L_4 ,
sizeof( struct V_1 ) ,
0 ,
V_281 | V_282 ,
NULL ) ;
V_35 = F_242 ( L_5 ,
sizeof( struct V_42 ) ,
0 ,
V_281 | V_282 ,
NULL ) ;
}
static int
F_243 ( struct V_1 * V_2 , struct V_283 * V_250 , int V_143 , int V_6 )
{
int V_154 = F_120 ( V_2 ) ;
int V_72 , V_156 = V_154 - V_143 ;
struct V_1 * V_155 ;
int V_284 = 0 ;
if ( V_156 > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
F_244 ( V_250 , V_2 -> V_8 + V_143 , V_156 ) ;
V_284 ++ ;
if ( ( V_6 -= V_156 ) == 0 )
return V_284 ;
V_143 += V_156 ;
}
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ ) {
int V_10 ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + F_103 ( & F_23 ( V_2 ) -> V_76 [ V_72 ] ) ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_72 ] ;
if ( V_156 > V_6 )
V_156 = V_6 ;
F_245 ( & V_250 [ V_284 ] , F_101 ( V_75 ) , V_156 ,
V_75 -> V_114 + V_143 - V_154 ) ;
V_284 ++ ;
if ( ! ( V_6 -= V_156 ) )
return V_284 ;
V_143 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_68 ( V_154 > V_143 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_143 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
V_284 += F_243 ( V_155 , V_250 + V_284 , V_143 - V_154 ,
V_156 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_284 ;
V_143 += V_156 ;
}
V_154 = V_10 ;
}
F_125 ( V_6 ) ;
return V_284 ;
}
int F_246 ( struct V_1 * V_2 , struct V_283 * V_250 ,
int V_143 , int V_6 )
{
return F_243 ( V_2 , V_250 , V_143 , V_6 ) ;
}
int F_247 ( struct V_1 * V_2 , struct V_283 * V_250 , int V_143 , int V_6 )
{
int V_285 = F_243 ( V_2 , V_250 , V_143 , V_6 ) ;
F_248 ( & V_250 [ V_285 - 1 ] ) ;
return V_285 ;
}
int F_249 ( struct V_1 * V_2 , int V_286 , struct V_1 * * V_287 )
{
int V_288 ;
int V_284 ;
struct V_1 * V_44 , * * V_289 ;
if ( ( F_128 ( V_2 ) || F_23 ( V_2 ) -> V_83 ) &&
F_147 ( V_2 , F_250 ( V_2 ) - F_120 ( V_2 ) ) == NULL )
return - V_113 ;
if ( ! F_123 ( V_2 ) ) {
if ( F_134 ( V_2 ) < V_286 &&
F_124 ( V_2 , 0 , V_286 - F_134 ( V_2 ) + 128 , V_52 ) )
return - V_113 ;
* V_287 = V_2 ;
return 1 ;
}
V_284 = 1 ;
V_289 = & F_23 ( V_2 ) -> V_78 ;
V_288 = 0 ;
while ( ( V_44 = * V_289 ) != NULL ) {
int V_130 = 0 ;
if ( F_126 ( V_44 ) )
V_288 = 1 ;
if ( V_44 -> V_98 == NULL && V_286 ) {
if ( F_23 ( V_44 ) -> V_83 ||
F_123 ( V_44 ) ||
F_134 ( V_44 ) < V_286 )
V_130 = V_286 + 128 ;
}
if ( V_288 ||
F_128 ( V_44 ) ||
V_130 ||
F_23 ( V_44 ) -> V_83 ||
F_123 ( V_44 ) ) {
struct V_1 * V_45 ;
if ( V_130 == 0 )
V_45 = F_115 ( V_44 , V_52 ) ;
else
V_45 = F_132 ( V_44 ,
F_93 ( V_44 ) ,
V_130 ,
V_52 ) ;
if ( F_42 ( V_45 == NULL ) )
return - V_113 ;
if ( V_44 -> V_105 )
F_251 ( V_45 , V_44 -> V_105 ) ;
V_45 -> V_98 = V_44 -> V_98 ;
* V_289 = V_45 ;
F_76 ( V_44 ) ;
V_44 = V_45 ;
}
V_284 ++ ;
* V_287 = V_44 ;
V_289 = & V_44 -> V_98 ;
}
return V_284 ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_162 * V_105 = V_2 -> V_105 ;
F_253 ( V_2 -> V_27 , & V_105 -> V_290 ) ;
}
int F_254 ( struct V_162 * V_105 , struct V_1 * V_2 )
{
if ( F_62 ( & V_105 -> V_290 ) + V_2 -> V_27 >=
( unsigned int ) V_105 -> V_291 )
return - V_113 ;
F_255 ( V_2 ) ;
V_2 -> V_105 = V_105 ;
V_2 -> V_92 = F_252 ;
F_216 ( V_2 -> V_27 , & V_105 -> V_290 ) ;
F_256 ( V_2 ) ;
F_191 ( & V_105 -> V_292 , V_2 ) ;
if ( ! F_257 ( V_105 , V_293 ) )
V_105 -> V_294 ( V_105 ) ;
return 0 ;
}
struct V_1 * F_258 ( struct V_162 * V_105 )
{
struct V_199 * V_295 = & V_105 -> V_292 ;
struct V_1 * V_2 , * V_296 ;
unsigned long V_15 ;
int V_139 = 0 ;
F_183 ( & V_295 -> V_201 , V_15 ) ;
V_2 = F_184 ( V_295 ) ;
if ( V_2 && ( V_296 = F_259 ( V_295 ) ) )
V_139 = F_260 ( V_296 ) -> V_297 . V_298 ;
F_185 ( & V_295 -> V_201 , V_15 ) ;
V_105 -> V_299 = V_139 ;
if ( V_139 )
V_105 -> V_300 ( V_105 ) ;
return V_2 ;
}
struct V_1 * F_261 ( struct V_1 * V_2 )
{
struct V_162 * V_105 = V_2 -> V_105 ;
struct V_1 * V_151 ;
if ( ! V_105 || ! F_262 ( & V_105 -> V_301 ) )
return NULL ;
V_151 = F_108 ( V_2 , V_52 ) ;
if ( ! V_151 ) {
F_263 ( V_105 ) ;
return NULL ;
}
V_151 -> V_105 = V_105 ;
V_151 -> V_92 = V_302 ;
return V_151 ;
}
static void F_264 ( struct V_1 * V_2 ,
struct V_162 * V_105 ,
int V_303 )
{
struct V_304 * V_305 ;
int V_139 ;
V_305 = F_260 ( V_2 ) ;
memset ( V_305 , 0 , sizeof( * V_305 ) ) ;
V_305 -> V_297 . V_298 = V_306 ;
V_305 -> V_297 . V_307 = V_308 ;
V_305 -> V_297 . V_309 = V_303 ;
if ( V_105 -> V_310 & V_311 ) {
V_305 -> V_297 . V_312 = F_23 ( V_2 ) -> V_313 ;
if ( V_105 -> V_314 == V_315 &&
V_105 -> V_316 == V_317 )
V_305 -> V_297 . V_312 -= V_105 -> V_318 ;
}
V_139 = F_254 ( V_105 , V_2 ) ;
if ( V_139 )
F_76 ( V_2 ) ;
}
static bool F_265 ( struct V_162 * V_105 , bool V_319 )
{
bool V_176 ;
if ( F_74 ( V_320 || V_319 ) )
return true ;
F_266 ( & V_105 -> V_321 ) ;
V_176 = V_105 -> V_322 && V_105 -> V_322 -> V_323 &&
F_267 ( V_105 -> V_322 -> V_323 , & V_324 , V_325 ) ;
F_268 ( & V_105 -> V_321 ) ;
return V_176 ;
}
void F_269 ( struct V_1 * V_2 ,
struct V_326 * V_327 )
{
struct V_162 * V_105 = V_2 -> V_105 ;
if ( ! F_265 ( V_105 , false ) )
return;
F_270 ( V_105 ) ;
* F_271 ( V_2 ) = * V_327 ;
F_264 ( V_2 , V_105 , V_328 ) ;
F_263 ( V_105 ) ;
}
void F_272 ( struct V_1 * V_329 ,
struct V_326 * V_327 ,
struct V_162 * V_105 , int V_303 )
{
struct V_1 * V_2 ;
bool V_319 ;
if ( ! V_105 )
return;
V_319 = V_105 -> V_310 & V_330 ;
if ( ! F_265 ( V_105 , V_319 ) )
return;
if ( V_319 )
V_2 = F_273 ( 0 , V_52 ) ;
else
V_2 = F_108 ( V_329 , V_52 ) ;
if ( ! V_2 )
return;
if ( V_319 ) {
F_23 ( V_2 ) -> V_84 = F_23 ( V_329 ) -> V_84 ;
F_23 ( V_2 ) -> V_313 = F_23 ( V_329 ) -> V_313 ;
}
if ( V_327 )
* F_271 ( V_2 ) = * V_327 ;
else
V_2 -> V_331 = F_274 () ;
F_264 ( V_2 , V_105 , V_303 ) ;
}
void F_275 ( struct V_1 * V_329 ,
struct V_326 * V_327 )
{
return F_272 ( V_329 , V_327 , V_329 -> V_105 ,
V_328 ) ;
}
void F_276 ( struct V_1 * V_2 , bool V_332 )
{
struct V_162 * V_105 = V_2 -> V_105 ;
struct V_304 * V_305 ;
int V_139 ;
V_2 -> V_333 = 1 ;
V_2 -> V_334 = V_332 ;
V_305 = F_260 ( V_2 ) ;
memset ( V_305 , 0 , sizeof( * V_305 ) ) ;
V_305 -> V_297 . V_298 = V_306 ;
V_305 -> V_297 . V_307 = V_335 ;
F_270 ( V_105 ) ;
V_139 = F_254 ( V_105 , V_2 ) ;
if ( V_139 )
F_76 ( V_2 ) ;
F_263 ( V_105 ) ;
}
bool F_277 ( struct V_1 * V_2 , T_12 V_154 , T_12 V_73 )
{
if ( F_42 ( V_154 > F_120 ( V_2 ) ) ||
F_42 ( ( int ) V_154 + V_73 > F_120 ( V_2 ) - 2 ) ) {
F_232 ( L_6 ,
V_154 , V_73 , F_120 ( V_2 ) ) ;
return false ;
}
V_2 -> V_115 = V_116 ;
V_2 -> V_117 = F_93 ( V_2 ) + V_154 ;
V_2 -> V_197 = V_73 ;
F_278 ( V_2 , V_154 ) ;
return true ;
}
static int F_279 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_336 )
{
if ( F_120 ( V_2 ) >= V_6 )
return 0 ;
if ( V_336 > V_2 -> V_6 )
V_336 = V_2 -> V_6 ;
if ( F_147 ( V_2 , V_336 - F_120 ( V_2 ) ) == NULL )
return - V_113 ;
if ( F_120 ( V_2 ) < V_6 )
return - V_337 ;
return 0 ;
}
static int F_280 ( struct V_1 * V_2 , bool V_338 )
{
unsigned int V_73 ;
bool V_339 ;
V_198 * V_184 ;
int V_139 ;
V_339 = false ;
V_139 = F_279 ( V_2 ,
sizeof( struct V_340 ) ,
V_341 ) ;
if ( V_139 < 0 )
goto V_23;
if ( F_281 ( V_2 ) -> V_342 & F_282 ( V_343 | V_344 ) )
V_339 = true ;
V_73 = F_283 ( V_2 ) ;
V_139 = - V_337 ;
if ( V_339 )
goto V_23;
V_184 = F_284 ( V_2 , F_281 ( V_2 ) -> V_345 , V_73 ) ;
if ( F_285 ( V_184 ) )
return F_286 ( V_184 ) ;
if ( V_338 )
* V_184 = ~ F_287 ( F_281 ( V_2 ) -> V_346 ,
F_281 ( V_2 ) -> V_347 ,
V_2 -> V_6 - V_73 ,
F_281 ( V_2 ) -> V_345 , 0 ) ;
V_139 = 0 ;
V_23:
return V_139 ;
}
static int F_288 ( struct V_1 * V_2 , bool V_338 )
{
int V_139 ;
T_3 V_348 ;
unsigned int V_73 ;
unsigned int V_6 ;
bool V_339 ;
bool V_146 ;
V_198 * V_184 ;
V_339 = false ;
V_146 = false ;
V_73 = sizeof( struct V_349 ) ;
V_139 = F_279 ( V_2 , V_73 , V_350 ) ;
if ( V_139 < 0 )
goto V_23;
V_348 = F_289 ( V_2 ) -> V_348 ;
V_6 = sizeof( struct V_349 ) + F_290 ( F_289 ( V_2 ) -> V_351 ) ;
while ( V_73 <= V_6 && ! V_146 ) {
switch ( V_348 ) {
case V_352 :
case V_353 :
case V_354 : {
struct V_355 * V_356 ;
V_139 = F_279 ( V_2 ,
V_73 +
sizeof( struct V_355 ) ,
V_350 ) ;
if ( V_139 < 0 )
goto V_23;
V_356 = F_291 ( struct V_355 , V_2 , V_73 ) ;
V_348 = V_356 -> V_348 ;
V_73 += F_292 ( V_356 ) ;
break;
}
case V_357 : {
struct V_358 * V_356 ;
V_139 = F_279 ( V_2 ,
V_73 +
sizeof( struct V_358 ) ,
V_350 ) ;
if ( V_139 < 0 )
goto V_23;
V_356 = F_291 ( struct V_358 , V_2 , V_73 ) ;
V_348 = V_356 -> V_348 ;
V_73 += F_293 ( V_356 ) ;
break;
}
case V_359 : {
struct V_360 * V_356 ;
V_139 = F_279 ( V_2 ,
V_73 +
sizeof( struct V_360 ) ,
V_350 ) ;
if ( V_139 < 0 )
goto V_23;
V_356 = F_291 ( struct V_360 , V_2 , V_73 ) ;
if ( V_356 -> V_342 & F_282 ( V_361 | V_362 ) )
V_339 = true ;
V_348 = V_356 -> V_348 ;
V_73 += sizeof( struct V_360 ) ;
break;
}
default:
V_146 = true ;
break;
}
}
V_139 = - V_337 ;
if ( ! V_146 || V_339 )
goto V_23;
V_184 = F_284 ( V_2 , V_348 , V_73 ) ;
if ( F_285 ( V_184 ) )
return F_286 ( V_184 ) ;
if ( V_338 )
* V_184 = ~ F_294 ( & F_289 ( V_2 ) -> V_346 ,
& F_289 ( V_2 ) -> V_347 ,
V_2 -> V_6 - V_73 , V_348 , 0 ) ;
V_139 = 0 ;
V_23:
return V_139 ;
}
int F_295 ( struct V_1 * V_2 , bool V_338 )
{
int V_139 ;
switch ( V_2 -> V_345 ) {
case F_282 ( V_363 ) :
V_139 = F_280 ( V_2 , V_338 ) ;
break;
case F_282 ( V_364 ) :
V_139 = F_288 ( V_2 , V_338 ) ;
break;
default:
V_139 = - V_337 ;
break;
}
return V_139 ;
}
static struct V_1 * F_296 ( struct V_1 * V_2 ,
unsigned int V_365 )
{
struct V_1 * V_366 ;
unsigned int V_6 = F_297 ( V_2 ) + V_365 ;
int V_176 ;
if ( V_2 -> V_6 < V_6 )
return NULL ;
else if ( V_2 -> V_6 == V_6 )
return V_2 ;
V_366 = F_108 ( V_2 , V_52 ) ;
if ( ! V_366 )
return NULL ;
V_176 = F_298 ( V_366 , V_6 ) ;
if ( V_176 ) {
F_76 ( V_366 ) ;
return NULL ;
}
return V_366 ;
}
struct V_1 * F_299 ( struct V_1 * V_2 ,
unsigned int V_365 ,
V_198 (* F_300)( struct V_1 * V_2 ) )
{
struct V_1 * V_366 ;
unsigned int V_143 = F_297 ( V_2 ) ;
V_198 V_176 ;
V_366 = F_296 ( V_2 , V_365 ) ;
if ( ! V_366 )
goto V_139;
if ( ! F_301 ( V_366 , V_143 ) )
goto V_139;
F_218 ( V_366 , V_143 ) ;
V_176 = F_300 ( V_366 ) ;
F_302 ( V_366 , V_143 ) ;
if ( V_176 )
goto V_139;
return V_366 ;
V_139:
if ( V_366 && V_366 != V_2 )
F_76 ( V_366 ) ;
return NULL ;
}
void F_303 ( const struct V_1 * V_2 )
{
F_232 ( L_7 ,
V_2 -> V_11 -> V_12 ) ;
}
void F_304 ( struct V_1 * V_2 , bool V_367 )
{
if ( V_367 ) {
F_64 ( V_2 ) ;
F_27 ( V_25 , V_2 ) ;
} else {
F_75 ( V_2 ) ;
}
}
bool F_305 ( struct V_1 * V_153 , struct V_1 * V_183 ,
bool * V_368 , int * V_271 )
{
int V_72 , V_132 , V_6 = V_183 -> V_6 ;
* V_368 = false ;
if ( F_128 ( V_153 ) )
return false ;
if ( V_6 <= F_134 ( V_153 ) ) {
if ( V_6 )
F_125 ( F_118 ( V_183 , 0 , F_117 ( V_153 , V_6 ) , V_6 ) ) ;
* V_271 = 0 ;
return true ;
}
if ( F_123 ( V_153 ) || F_123 ( V_183 ) )
return false ;
if ( F_120 ( V_183 ) != 0 ) {
struct V_60 * V_60 ;
unsigned int V_143 ;
if ( F_23 ( V_153 ) -> V_83 +
F_23 ( V_183 ) -> V_83 >= V_170 )
return false ;
if ( F_163 ( V_183 ) )
return false ;
V_132 = V_183 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
V_60 = F_32 ( V_183 -> V_7 ) ;
V_143 = V_183 -> V_8 - ( unsigned char * ) F_102 ( V_60 ) ;
F_47 ( V_153 , F_23 ( V_153 ) -> V_83 ,
V_60 , V_143 , F_120 ( V_183 ) ) ;
* V_368 = true ;
} else {
if ( F_23 ( V_153 ) -> V_83 +
F_23 ( V_183 ) -> V_83 > V_170 )
return false ;
V_132 = V_183 -> V_27 - F_21 ( F_116 ( V_183 ) ) ;
}
F_306 ( V_132 < V_6 ) ;
memcpy ( F_23 ( V_153 ) -> V_76 + F_23 ( V_153 ) -> V_83 ,
F_23 ( V_183 ) -> V_76 ,
F_23 ( V_183 ) -> V_83 * sizeof( T_4 ) ) ;
F_23 ( V_153 ) -> V_83 += F_23 ( V_183 ) -> V_83 ;
if ( ! F_128 ( V_183 ) )
F_23 ( V_183 ) -> V_83 = 0 ;
for ( V_72 = 0 ; V_72 < F_23 ( V_183 ) -> V_83 ; V_72 ++ )
F_122 ( V_183 , V_72 ) ;
V_153 -> V_27 += V_132 ;
V_153 -> V_6 += V_6 ;
V_153 -> V_74 += V_6 ;
* V_271 = V_132 ;
return true ;
}
void F_307 ( struct V_1 * V_2 , bool V_369 )
{
V_2 -> V_331 . V_370 = 0 ;
V_2 -> V_371 = V_372 ;
V_2 -> V_373 = 0 ;
V_2 -> V_374 = 0 ;
F_65 ( V_2 ) ;
F_308 ( V_2 ) ;
F_309 ( V_2 ) ;
F_310 ( V_2 ) ;
if ( ! V_369 )
return;
F_255 ( V_2 ) ;
V_2 -> V_375 = 0 ;
}
unsigned int F_311 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_23 ( V_2 ) ;
unsigned int V_376 = 0 ;
if ( V_2 -> V_377 ) {
V_376 = F_312 ( V_2 ) -
F_313 ( V_2 ) ;
if ( F_74 ( V_33 -> V_126 & ( V_378 | V_379 ) ) )
V_376 += F_314 ( V_2 ) ;
} else if ( F_74 ( V_33 -> V_126 & ( V_378 | V_379 ) ) ) {
V_376 = F_315 ( V_2 ) ;
}
return V_376 + V_33 -> V_124 ;
}
static struct V_1 * F_316 ( struct V_1 * V_2 )
{
if ( F_317 ( V_2 , F_93 ( V_2 ) ) < 0 ) {
F_76 ( V_2 ) ;
return NULL ;
}
memmove ( V_2 -> V_8 - V_380 , V_2 -> V_8 - V_2 -> V_106 - V_381 ,
2 * V_382 ) ;
V_2 -> V_29 += V_381 ;
return V_2 ;
}
struct V_1 * F_318 ( struct V_1 * V_2 )
{
struct V_383 * V_384 ;
T_12 V_385 ;
if ( F_42 ( F_319 ( V_2 ) ) ) {
return V_2 ;
}
V_2 = F_320 ( V_2 , V_52 ) ;
if ( F_42 ( ! V_2 ) )
goto V_386;
if ( F_42 ( ! F_301 ( V_2 , V_381 ) ) )
goto V_386;
V_384 = (struct V_383 * ) V_2 -> V_8 ;
V_385 = F_290 ( V_384 -> V_387 ) ;
F_321 ( V_2 , V_2 -> V_345 , V_385 ) ;
F_218 ( V_2 , V_381 ) ;
F_322 ( V_2 , V_384 ) ;
V_2 = F_316 ( V_2 ) ;
if ( F_42 ( ! V_2 ) )
goto V_386;
F_323 ( V_2 ) ;
F_324 ( V_2 ) ;
F_230 ( V_2 ) ;
return V_2 ;
V_386:
F_76 ( V_2 ) ;
return NULL ;
}
int F_325 ( struct V_1 * V_2 , int V_388 )
{
if ( ! F_301 ( V_2 , V_388 ) )
return - V_113 ;
if ( ! F_128 ( V_2 ) || F_326 ( V_2 , V_388 ) )
return 0 ;
return F_124 ( V_2 , 0 , 0 , V_52 ) ;
}
static int F_327 ( struct V_1 * V_2 , T_12 * V_385 )
{
struct V_383 * V_384 ;
unsigned int V_143 = V_2 -> V_8 - F_222 ( V_2 ) ;
int V_139 ;
F_224 ( V_2 , V_143 ) ;
V_139 = F_325 ( V_2 , V_389 ) ;
if ( F_42 ( V_139 ) )
goto V_390;
F_220 ( V_2 , V_2 -> V_8 + ( 2 * V_382 ) , V_381 ) ;
V_384 = (struct V_383 * ) ( V_2 -> V_8 + V_380 ) ;
* V_385 = F_290 ( V_384 -> V_387 ) ;
memmove ( V_2 -> V_8 + V_381 , V_2 -> V_8 , 2 * V_382 ) ;
F_219 ( V_2 , V_381 ) ;
F_322 ( V_2 , V_384 ) ;
V_2 -> V_29 += V_381 ;
if ( F_328 ( V_2 ) < V_380 )
F_329 ( V_2 , V_380 ) ;
F_230 ( V_2 ) ;
V_390:
F_219 ( V_2 , V_143 ) ;
return V_139 ;
}
int F_330 ( struct V_1 * V_2 )
{
T_12 V_385 ;
T_10 V_391 ;
int V_139 ;
if ( F_74 ( F_319 ( V_2 ) ) ) {
V_2 -> V_385 = 0 ;
} else {
if ( F_42 ( ( V_2 -> V_345 != F_282 ( V_392 ) &&
V_2 -> V_345 != F_282 ( V_393 ) ) ||
V_2 -> V_6 < V_389 ) )
return 0 ;
V_139 = F_327 ( V_2 , & V_385 ) ;
if ( V_139 )
return V_139 ;
}
if ( F_74 ( ( V_2 -> V_345 != F_282 ( V_392 ) &&
V_2 -> V_345 != F_282 ( V_393 ) ) ||
V_2 -> V_6 < V_389 ) )
return 0 ;
V_391 = V_2 -> V_345 ;
V_139 = F_327 ( V_2 , & V_385 ) ;
if ( F_42 ( V_139 ) )
return V_139 ;
F_321 ( V_2 , V_391 , V_385 ) ;
return 0 ;
}
int F_331 ( struct V_1 * V_2 , T_10 V_391 , T_12 V_385 )
{
if ( F_319 ( V_2 ) ) {
unsigned int V_143 = V_2 -> V_8 - F_222 ( V_2 ) ;
int V_139 ;
F_224 ( V_2 , V_143 ) ;
V_139 = F_332 ( V_2 , V_2 -> V_391 ,
F_333 ( V_2 ) ) ;
if ( V_139 ) {
F_219 ( V_2 , V_143 ) ;
return V_139 ;
}
V_2 -> V_345 = V_2 -> V_391 ;
V_2 -> V_106 += V_381 ;
F_334 ( V_2 , V_2 -> V_8 + ( 2 * V_382 ) , V_381 ) ;
F_219 ( V_2 , V_143 ) ;
}
F_321 ( V_2 , V_391 , V_385 ) ;
return 0 ;
}
struct V_1 * F_335 ( unsigned long V_394 ,
unsigned long V_74 ,
int V_395 ,
int * V_396 ,
T_2 V_24 )
{
int V_397 = ( V_74 + ( V_63 - 1 ) ) >> V_398 ;
unsigned long V_399 ;
struct V_1 * V_2 ;
struct V_60 * V_60 ;
T_2 V_400 ;
int V_72 ;
* V_396 = - V_239 ;
if ( V_397 > V_170 )
return NULL ;
V_400 = V_24 ;
if ( V_400 & V_64 )
V_400 |= V_401 ;
* V_396 = - V_402 ;
V_2 = F_273 ( V_394 , V_400 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_27 += V_397 << V_398 ;
for ( V_72 = 0 ; V_397 > 0 ; V_72 ++ ) {
int V_403 = V_395 ;
while ( V_403 ) {
if ( V_397 >= 1 << V_403 ) {
V_60 = F_336 ( ( V_24 & ~ V_64 ) |
V_404 |
V_22 |
V_405 ,
V_403 ) ;
if ( V_60 )
goto V_406;
V_403 = 1 ;
V_395 = 0 ;
}
V_403 -- ;
}
V_60 = F_97 ( V_24 ) ;
if ( ! V_60 )
goto V_407;
V_406:
V_399 = F_155 (unsigned long, data_len,
PAGE_SIZE << order) ;
F_47 ( V_2 , V_72 , V_60 , 0 , V_399 ) ;
V_74 -= V_399 ;
V_397 -= 1 << V_403 ;
}
return V_2 ;
V_407:
F_76 ( V_2 ) ;
return NULL ;
}
static int F_337 ( struct V_1 * V_2 , const T_8 V_73 ,
const int V_268 , T_2 V_24 )
{
int V_72 ;
int V_14 = F_116 ( V_2 ) ;
int V_408 = V_268 - V_73 ;
T_3 * V_8 ;
V_14 = F_17 ( V_14 ) ;
if ( F_110 ( V_2 ) )
V_24 |= V_37 ;
V_8 = F_18 ( V_14 +
F_17 ( sizeof( struct V_32 ) ) ,
V_24 , V_66 , NULL ) ;
if ( ! V_8 )
return - V_113 ;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
F_150 ( V_2 , V_73 , V_8 , V_408 ) ;
V_2 -> V_6 -= V_73 ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) ,
F_11 ( struct V_32 ,
V_76 [ F_23 ( V_2 ) -> V_83 ] ) ) ;
if ( F_128 ( V_2 ) ) {
if ( F_109 ( V_2 , V_24 ) ) {
F_57 ( V_8 ) ;
return - V_113 ;
}
for ( V_72 = 0 ; V_72 < F_23 ( V_2 ) -> V_83 ; V_72 ++ )
F_122 ( V_2 , V_72 ) ;
if ( F_123 ( V_2 ) )
F_53 ( V_2 ) ;
F_58 ( V_2 ) ;
} else {
F_56 ( V_2 ) ;
}
V_2 -> V_7 = V_8 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_53 = 0 ;
#ifdef F_129
V_2 -> V_10 = V_14 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
F_146 ( V_2 , F_120 ( V_2 ) ) ;
F_111 ( V_2 , 0 ) ;
V_2 -> V_80 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_81 = 0 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
}
static int F_338 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_149 ,
T_2 V_24 )
{
struct V_1 * V_79 = V_33 -> V_78 ;
struct V_1 * V_151 = NULL ;
struct V_1 * V_152 = NULL ;
do {
if ( ! V_79 ) {
F_339 ( L_8 , V_149 ) ;
return - V_158 ;
}
if ( V_79 -> V_6 <= V_149 ) {
V_149 -= V_79 -> V_6 ;
V_79 = V_79 -> V_98 ;
V_152 = V_79 ;
} else {
if ( F_126 ( V_79 ) ) {
V_151 = F_108 ( V_79 , V_24 ) ;
if ( ! V_151 )
return - V_113 ;
V_152 = V_79 -> V_98 ;
V_79 = V_151 ;
} else {
V_152 = V_79 ;
}
if ( F_340 ( V_79 , V_149 , V_24 ) < 0 ) {
F_76 ( V_151 ) ;
return - V_113 ;
}
break;
}
} while ( V_149 );
while ( ( V_79 = V_33 -> V_78 ) != V_152 ) {
V_33 -> V_78 = V_79 -> V_98 ;
F_76 ( V_79 ) ;
}
if ( V_151 ) {
V_151 -> V_98 = V_79 ;
V_33 -> V_78 = V_151 ;
}
return 0 ;
}
static int F_341 ( struct V_1 * V_2 , const T_8 V_73 ,
int V_186 , T_2 V_24 )
{
int V_72 , V_148 = 0 ;
int V_14 = F_116 ( V_2 ) ;
T_3 * V_8 ;
const int V_144 = F_23 ( V_2 ) -> V_83 ;
struct V_32 * V_33 ;
V_14 = F_17 ( V_14 ) ;
if ( F_110 ( V_2 ) )
V_24 |= V_37 ;
V_8 = F_18 ( V_14 +
F_17 ( sizeof( struct V_32 ) ) ,
V_24 , V_66 , NULL ) ;
if ( ! V_8 )
return - V_113 ;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) , F_11 ( struct V_32 ,
V_76 [ F_23 ( V_2 ) -> V_83 ] ) ) ;
if ( F_109 ( V_2 , V_24 ) ) {
F_57 ( V_8 ) ;
return - V_113 ;
}
V_33 = (struct V_32 * ) ( V_8 + V_14 ) ;
for ( V_72 = 0 ; V_72 < V_144 ; V_72 ++ ) {
int V_409 = F_103 ( & F_23 ( V_2 ) -> V_76 [ V_72 ] ) ;
if ( V_186 + V_409 > V_73 ) {
V_33 -> V_76 [ V_148 ] = F_23 ( V_2 ) -> V_76 [ V_72 ] ;
if ( V_186 < V_73 ) {
V_33 -> V_76 [ 0 ] . V_114 += V_73 - V_186 ;
F_149 ( & V_33 -> V_76 [ 0 ] , V_73 - V_186 ) ;
}
F_122 ( V_2 , V_72 ) ;
V_148 ++ ;
}
V_186 += V_409 ;
}
V_33 -> V_83 = V_148 ;
if ( F_123 ( V_2 ) )
F_53 ( V_2 ) ;
if ( V_148 == 0 ) {
F_338 ( V_2 , V_33 , V_73 - V_186 , V_24 ) ;
}
F_58 ( V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_53 = 0 ;
V_2 -> V_8 = V_8 ;
#ifdef F_129
V_2 -> V_10 = V_14 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
F_22 ( V_2 ) ;
F_111 ( V_2 , 0 ) ;
V_2 -> V_80 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_81 = 0 ;
V_2 -> V_6 -= V_73 ;
V_2 -> V_74 = V_2 -> V_6 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
}
static int F_340 ( struct V_1 * V_2 , const T_8 V_6 , T_2 V_410 )
{
int V_268 = F_120 ( V_2 ) ;
if ( V_6 < V_268 )
return F_337 ( V_2 , V_6 , V_268 , V_410 ) ;
else
return F_341 ( V_2 , V_6 , V_268 , V_410 ) ;
}
struct V_1 * F_342 ( struct V_1 * V_2 , int V_73 ,
int V_411 , T_2 V_410 )
{
struct V_1 * V_151 = F_108 ( V_2 , V_410 ) ;
if ( ! V_151 )
return NULL ;
if ( F_340 ( V_151 , V_73 , V_410 ) < 0 ||
F_145 ( V_151 , V_411 ) ) {
F_76 ( V_151 ) ;
return NULL ;
}
return V_151 ;
}
