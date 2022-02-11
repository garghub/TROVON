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
struct V_55 * V_56 = F_35 ( & V_59 ) ;
return F_36 ( V_56 , V_54 , V_24 ) ;
}
void * F_40 ( unsigned int V_54 )
{
return F_39 ( V_54 , V_52 | V_58 ) ;
}
struct V_1 * F_41 ( struct V_60 * V_11 , unsigned int V_6 ,
T_2 V_24 )
{
struct V_55 * V_56 ;
unsigned long V_15 ;
struct V_1 * V_2 ;
bool V_18 ;
void * V_8 ;
V_6 += V_61 ;
if ( ( V_6 > F_19 ( V_62 ) ) ||
( V_24 & ( V_63 | V_64 ) ) ) {
V_2 = F_14 ( V_6 , V_24 , V_36 , V_65 ) ;
if ( ! V_2 )
goto V_66;
goto V_67;
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
V_67:
F_44 ( V_2 , V_61 ) ;
V_2 -> V_11 = V_11 ;
V_66:
return V_2 ;
}
struct V_1 * F_45 ( struct V_68 * V_69 , unsigned int V_6 ,
T_2 V_24 )
{
struct V_55 * V_56 = F_35 ( & V_59 ) ;
struct V_1 * V_2 ;
void * V_8 ;
V_6 += V_61 + V_70 ;
if ( ( V_6 > F_19 ( V_62 ) ) ||
( V_24 & ( V_63 | V_64 ) ) ) {
V_2 = F_14 ( V_6 , V_24 , V_36 , V_65 ) ;
if ( ! V_2 )
goto V_66;
goto V_67;
}
V_6 += F_17 ( sizeof( struct V_32 ) ) ;
V_6 = F_17 ( V_6 ) ;
if ( F_15 () )
V_24 |= V_37 ;
V_8 = F_36 ( V_56 , V_6 , V_24 ) ;
if ( F_42 ( ! V_8 ) )
return NULL ;
V_2 = F_28 ( V_8 , V_6 ) ;
if ( F_42 ( ! V_2 ) ) {
F_43 ( V_8 ) ;
return NULL ;
}
if ( V_56 -> V_18 )
V_2 -> V_18 = 1 ;
V_2 -> V_53 = 1 ;
V_67:
F_44 ( V_2 , V_61 + V_70 ) ;
V_2 -> V_11 = V_69 -> V_11 ;
V_66:
return V_2 ;
}
void F_46 ( struct V_1 * V_2 , int V_71 , struct V_72 * V_72 , int V_73 ,
int V_14 , unsigned int V_27 )
{
F_47 ( V_2 , V_71 , V_72 , V_73 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_74 += V_14 ;
V_2 -> V_27 += V_27 ;
}
void F_48 ( struct V_1 * V_2 , int V_71 , int V_14 ,
unsigned int V_27 )
{
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_71 ] ;
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
int V_71 ;
if ( V_2 -> V_80 &&
F_59 ( V_2 -> V_81 ? ( 1 << V_82 ) + 1 : 1 ,
& V_33 -> V_40 ) )
return;
for ( V_71 = 0 ; V_71 < V_33 -> V_83 ; V_71 ++ )
F_60 ( & V_33 -> V_76 [ V_71 ] ) ;
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
static struct V_1 * F_83 ( struct V_1 * V_99 , struct V_1 * V_2 )
{
#define F_84 ( T_5 ) n->x = skb->x
V_99 -> V_98 = V_99 -> V_100 = NULL ;
V_99 -> V_101 = NULL ;
F_85 ( V_99 , V_2 ) ;
F_84 ( V_6 ) ;
F_84 ( V_74 ) ;
F_84 ( V_102 ) ;
V_99 -> V_103 = V_2 -> V_81 ? F_86 ( V_2 ) : V_2 -> V_103 ;
V_99 -> V_80 = 1 ;
V_99 -> V_81 = 0 ;
V_99 -> V_92 = NULL ;
F_84 ( V_9 ) ;
F_84 ( V_10 ) ;
F_84 ( V_7 ) ;
F_84 ( V_53 ) ;
F_84 ( V_8 ) ;
F_84 ( V_27 ) ;
F_12 ( & V_99 -> V_28 , 1 ) ;
F_87 ( & ( F_23 ( V_2 ) -> V_40 ) ) ;
V_2 -> V_80 = 1 ;
return V_99 ;
#undef F_84
}
struct V_1 * F_88 ( struct V_1 * V_104 , struct V_1 * V_105 )
{
F_73 ( V_104 ) ;
return F_83 ( V_104 , V_105 ) ;
}
int F_89 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_71 ;
int V_106 = F_23 ( V_2 ) -> V_83 ;
struct V_72 * V_72 , * V_7 = NULL ;
struct V_86 * V_87 = F_23 ( V_2 ) -> V_41 ;
for ( V_71 = 0 ; V_71 < V_106 ; V_71 ++ ) {
T_3 * V_107 ;
T_4 * V_108 = & F_23 ( V_2 ) -> V_76 [ V_71 ] ;
V_72 = F_90 ( V_24 ) ;
if ( ! V_72 ) {
while ( V_7 ) {
struct V_72 * V_98 = (struct V_72 * ) F_91 ( V_7 ) ;
F_92 ( V_7 ) ;
V_7 = V_98 ;
}
return - V_109 ;
}
V_107 = F_93 ( F_94 ( V_108 ) ) ;
memcpy ( F_95 ( V_72 ) ,
V_107 + V_108 -> V_110 , F_96 ( V_108 ) ) ;
F_97 ( V_107 ) ;
F_98 ( V_72 , ( unsigned long ) V_7 ) ;
V_7 = V_72 ;
}
for ( V_71 = 0 ; V_71 < V_106 ; V_71 ++ )
F_99 ( V_2 , V_71 ) ;
V_87 -> V_88 ( V_87 , false ) ;
for ( V_71 = V_106 - 1 ; V_71 >= 0 ; V_71 -- ) {
F_100 ( V_2 , V_71 , V_7 , 0 ,
F_23 ( V_2 ) -> V_76 [ V_71 ] . V_14 ) ;
V_7 = (struct V_72 * ) F_91 ( V_7 ) ;
}
F_23 ( V_2 ) -> V_84 &= ~ V_85 ;
return 0 ;
}
struct V_1 * F_101 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_42 * V_43 = F_25 ( V_2 ,
struct V_42 ,
V_44 ) ;
struct V_1 * V_99 ;
if ( F_102 ( V_2 , V_24 ) )
return NULL ;
if ( V_2 -> V_47 == V_48 &&
F_62 ( & V_43 -> V_49 ) == 1 ) {
V_99 = & V_43 -> V_45 ;
F_12 ( & V_43 -> V_49 , 2 ) ;
} else {
if ( F_103 ( V_2 ) )
V_24 |= V_37 ;
V_99 = F_29 ( V_25 , V_24 ) ;
if ( ! V_99 )
return NULL ;
F_26 ( V_99 , V_46 ) ;
V_99 -> V_47 = V_89 ;
}
return F_83 ( V_99 , V_2 ) ;
}
static void F_104 ( struct V_1 * V_2 , int V_73 )
{
if ( V_2 -> V_111 == V_112 )
V_2 -> V_113 += V_73 ;
V_2 -> V_39 += V_73 ;
V_2 -> V_114 += V_73 ;
if ( F_105 ( V_2 ) )
V_2 -> V_29 += V_73 ;
V_2 -> V_115 += V_73 ;
V_2 -> V_116 += V_73 ;
V_2 -> V_117 += V_73 ;
}
static void F_106 ( struct V_1 * V_118 , const struct V_1 * V_119 )
{
F_85 ( V_118 , V_119 ) ;
F_23 ( V_118 ) -> V_120 = F_23 ( V_119 ) -> V_120 ;
F_23 ( V_118 ) -> V_121 = F_23 ( V_119 ) -> V_121 ;
F_23 ( V_118 ) -> V_122 = F_23 ( V_119 ) -> V_122 ;
}
static inline int F_107 ( const struct V_1 * V_2 )
{
if ( F_103 ( V_2 ) )
return V_36 ;
return 0 ;
}
struct V_1 * F_108 ( const struct V_1 * V_2 , T_2 V_24 )
{
int V_123 = F_86 ( V_2 ) ;
unsigned int V_14 = F_109 ( V_2 ) + V_2 -> V_74 ;
struct V_1 * V_99 = F_14 ( V_14 , V_24 ,
F_107 ( V_2 ) , V_65 ) ;
if ( ! V_99 )
return NULL ;
F_44 ( V_99 , V_123 ) ;
F_110 ( V_99 , V_2 -> V_6 ) ;
if ( F_111 ( V_2 , - V_123 , V_99 -> V_7 , V_123 + V_2 -> V_6 ) )
F_3 () ;
F_106 ( V_99 , V_2 ) ;
return V_99 ;
}
struct V_1 * F_112 ( struct V_1 * V_2 , int V_124 ,
T_2 V_24 , bool V_47 )
{
unsigned int V_14 = F_113 ( V_2 ) + V_124 ;
int V_15 = F_107 ( V_2 ) | ( V_47 ? V_34 : 0 ) ;
struct V_1 * V_99 = F_14 ( V_14 , V_24 , V_15 , V_65 ) ;
if ( ! V_99 )
goto V_23;
F_44 ( V_99 , V_124 ) ;
F_110 ( V_99 , F_113 ( V_2 ) ) ;
F_114 ( V_2 , V_99 -> V_8 , V_99 -> V_6 ) ;
V_99 -> V_27 += V_2 -> V_74 ;
V_99 -> V_74 = V_2 -> V_74 ;
V_99 -> V_6 = V_2 -> V_6 ;
if ( F_23 ( V_2 ) -> V_83 ) {
int V_71 ;
if ( F_102 ( V_2 , V_24 ) ) {
F_76 ( V_99 ) ;
V_99 = NULL ;
goto V_23;
}
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ ) {
F_23 ( V_99 ) -> V_76 [ V_71 ] = F_23 ( V_2 ) -> V_76 [ V_71 ] ;
F_115 ( V_2 , V_71 ) ;
}
F_23 ( V_99 ) -> V_83 = V_71 ;
}
if ( F_116 ( V_2 ) ) {
F_23 ( V_99 ) -> V_78 = F_23 ( V_2 ) -> V_78 ;
F_53 ( V_99 ) ;
}
F_106 ( V_99 , V_2 ) ;
V_23:
return V_99 ;
}
int F_117 ( struct V_1 * V_2 , int V_125 , int V_126 ,
T_2 V_24 )
{
int V_71 ;
T_3 * V_8 ;
int V_14 = V_125 + F_109 ( V_2 ) + V_126 ;
long V_73 ;
F_118 ( V_125 < 0 ) ;
if ( F_119 ( V_2 ) )
F_3 () ;
V_14 = F_17 ( V_14 ) ;
if ( F_103 ( V_2 ) )
V_24 |= V_37 ;
V_8 = F_18 ( V_14 + F_17 ( sizeof( struct V_32 ) ) ,
V_24 , V_65 , NULL ) ;
if ( ! V_8 )
goto V_38;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
memcpy ( V_8 + V_125 , V_2 -> V_7 , F_120 ( V_2 ) - V_2 -> V_7 ) ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) ,
F_11 ( struct V_32 , V_76 [ F_23 ( V_2 ) -> V_83 ] ) ) ;
if ( F_121 ( V_2 ) ) {
if ( F_102 ( V_2 , V_24 ) )
goto V_127;
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ )
F_115 ( V_2 , V_71 ) ;
if ( F_116 ( V_2 ) )
F_53 ( V_2 ) ;
F_58 ( V_2 ) ;
} else {
F_56 ( V_2 ) ;
}
V_73 = ( V_8 + V_125 ) - V_2 -> V_7 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_53 = 0 ;
V_2 -> V_8 += V_73 ;
#ifdef F_122
V_2 -> V_10 = V_14 ;
V_73 = V_125 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
V_2 -> V_9 += V_73 ;
F_104 ( V_2 , V_125 ) ;
V_2 -> V_80 = 0 ;
V_2 -> V_103 = 0 ;
V_2 -> V_81 = 0 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
V_127:
F_57 ( V_8 ) ;
V_38:
return - V_109 ;
}
struct V_1 * F_123 ( struct V_1 * V_2 , unsigned int V_124 )
{
struct V_1 * V_45 ;
int V_128 = V_124 - F_86 ( V_2 ) ;
if ( V_128 <= 0 )
V_45 = F_124 ( V_2 , V_52 ) ;
else {
V_45 = F_101 ( V_2 , V_52 ) ;
if ( V_45 && F_117 ( V_45 , F_17 ( V_128 ) , 0 ,
V_52 ) ) {
F_76 ( V_45 ) ;
V_45 = NULL ;
}
}
return V_45 ;
}
struct V_1 * F_125 ( const struct V_1 * V_2 ,
int V_129 , int V_130 ,
T_2 V_24 )
{
struct V_1 * V_99 = F_14 ( V_129 + V_2 -> V_6 + V_130 ,
V_24 , F_107 ( V_2 ) ,
V_65 ) ;
int V_131 = F_86 ( V_2 ) ;
int V_132 , V_133 ;
if ( ! V_99 )
return NULL ;
F_44 ( V_99 , V_129 ) ;
F_110 ( V_99 , V_2 -> V_6 ) ;
V_132 = V_131 ;
V_133 = 0 ;
if ( V_129 <= V_132 )
V_132 = V_129 ;
else
V_133 = V_129 - V_132 ;
if ( F_111 ( V_2 , - V_132 , V_99 -> V_7 + V_133 ,
V_2 -> V_6 + V_132 ) )
F_3 () ;
F_106 ( V_99 , V_2 ) ;
F_104 ( V_99 , V_129 - V_131 ) ;
return V_99 ;
}
int F_126 ( struct V_1 * V_2 , int V_134 )
{
int V_135 ;
int V_126 ;
if ( ! F_121 ( V_2 ) && F_127 ( V_2 ) >= V_134 ) {
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_134 ) ;
return 0 ;
}
V_126 = V_2 -> V_74 + V_134 - ( V_2 -> V_10 - V_2 -> V_9 ) ;
if ( F_74 ( F_121 ( V_2 ) || V_126 > 0 ) ) {
V_135 = F_117 ( V_2 , 0 , V_126 , V_52 ) ;
if ( F_42 ( V_135 ) )
goto V_136;
}
V_135 = F_128 ( V_2 ) ;
if ( F_42 ( V_135 ) )
goto V_136;
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_134 ) ;
return 0 ;
V_136:
F_76 ( V_2 ) ;
return V_135 ;
}
unsigned char * F_129 ( struct V_1 * V_2 , struct V_1 * V_9 , int V_6 )
{
if ( V_9 != V_2 ) {
V_2 -> V_74 += V_6 ;
V_2 -> V_6 += V_6 ;
}
return F_110 ( V_9 , V_6 ) ;
}
unsigned char * F_110 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned char * V_137 = F_120 ( V_2 ) ;
F_130 ( V_2 ) ;
V_2 -> V_9 += V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_42 ( V_2 -> V_9 > V_2 -> V_10 ) )
F_4 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_137 ;
}
unsigned char * F_131 ( struct V_1 * V_2 , unsigned int V_6 )
{
V_2 -> V_8 -= V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_42 ( V_2 -> V_8 < V_2 -> V_7 ) )
F_5 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_2 -> V_8 ;
}
unsigned char * F_132 ( struct V_1 * V_2 , unsigned int V_6 )
{
return F_133 ( V_2 , V_6 ) ;
}
void F_134 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_2 -> V_6 > V_6 )
F_135 ( V_2 , V_6 ) ;
}
int F_136 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_1 * * V_138 ;
struct V_1 * V_75 ;
int V_139 = F_113 ( V_2 ) ;
int V_140 = F_23 ( V_2 ) -> V_83 ;
int V_71 ;
int V_135 ;
if ( F_121 ( V_2 ) &&
F_42 ( ( V_135 = F_117 ( V_2 , 0 , 0 , V_52 ) ) ) )
return V_135 ;
V_71 = 0 ;
if ( V_139 >= V_6 )
goto V_141;
for (; V_71 < V_140 ; V_71 ++ ) {
int V_10 = V_139 + F_96 ( & F_23 ( V_2 ) -> V_76 [ V_71 ] ) ;
if ( V_10 < V_6 ) {
V_139 = V_10 ;
continue;
}
F_137 ( & F_23 ( V_2 ) -> V_76 [ V_71 ++ ] , V_6 - V_139 ) ;
V_141:
F_23 ( V_2 ) -> V_83 = V_71 ;
for (; V_71 < V_140 ; V_71 ++ )
F_99 ( V_2 , V_71 ) ;
if ( F_116 ( V_2 ) )
F_52 ( V_2 ) ;
goto V_142;
}
for ( V_138 = & F_23 ( V_2 ) -> V_78 ; ( V_75 = * V_138 ) ;
V_138 = & V_75 -> V_98 ) {
int V_10 = V_139 + V_75 -> V_6 ;
if ( F_119 ( V_75 ) ) {
struct V_1 * V_143 ;
V_143 = F_101 ( V_75 , V_52 ) ;
if ( F_42 ( ! V_143 ) )
return - V_109 ;
V_143 -> V_98 = V_75 -> V_98 ;
F_81 ( V_75 ) ;
V_75 = V_143 ;
* V_138 = V_75 ;
}
if ( V_10 < V_6 ) {
V_139 = V_10 ;
continue;
}
if ( V_10 > V_6 &&
F_42 ( ( V_135 = F_138 ( V_75 , V_6 - V_139 ) ) ) )
return V_135 ;
if ( V_75 -> V_98 )
F_50 ( & V_75 -> V_98 ) ;
break;
}
V_142:
if ( V_6 > F_113 ( V_2 ) ) {
V_2 -> V_74 -= V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
} else {
V_2 -> V_6 = V_6 ;
V_2 -> V_74 = 0 ;
F_139 ( V_2 , V_6 ) ;
}
return 0 ;
}
unsigned char * F_140 ( struct V_1 * V_2 , int V_128 )
{
int V_71 , V_144 , V_145 = ( V_2 -> V_9 + V_128 ) - V_2 -> V_10 ;
if ( V_145 > 0 || F_121 ( V_2 ) ) {
if ( F_117 ( V_2 , 0 , V_145 > 0 ? V_145 + 128 : 0 ,
V_52 ) )
return NULL ;
}
if ( F_111 ( V_2 , F_113 ( V_2 ) , F_120 ( V_2 ) , V_128 ) )
F_3 () ;
if ( ! F_116 ( V_2 ) )
goto V_146;
V_145 = V_128 ;
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ ) {
int V_14 = F_96 ( & F_23 ( V_2 ) -> V_76 [ V_71 ] ) ;
if ( V_14 >= V_145 )
goto V_146;
V_145 -= V_14 ;
}
if ( V_145 ) {
struct V_1 * V_79 = F_23 ( V_2 ) -> V_78 ;
struct V_1 * V_147 = NULL ;
struct V_1 * V_148 = NULL ;
do {
F_118 ( ! V_79 ) ;
if ( V_79 -> V_6 <= V_145 ) {
V_145 -= V_79 -> V_6 ;
V_79 = V_79 -> V_98 ;
V_148 = V_79 ;
} else {
if ( F_119 ( V_79 ) ) {
V_147 = F_101 ( V_79 , V_52 ) ;
if ( ! V_147 )
return NULL ;
V_148 = V_79 -> V_98 ;
V_79 = V_147 ;
} else {
V_148 = V_79 ;
}
if ( ! F_141 ( V_79 , V_145 ) ) {
F_76 ( V_147 ) ;
return NULL ;
}
break;
}
} while ( V_145 );
while ( ( V_79 = F_23 ( V_2 ) -> V_78 ) != V_148 ) {
F_23 ( V_2 ) -> V_78 = V_79 -> V_98 ;
F_76 ( V_79 ) ;
}
if ( V_147 ) {
V_147 -> V_98 = V_79 ;
F_23 ( V_2 ) -> V_78 = V_147 ;
}
}
V_146:
V_145 = V_128 ;
V_144 = 0 ;
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ ) {
int V_14 = F_96 ( & F_23 ( V_2 ) -> V_76 [ V_71 ] ) ;
if ( V_14 <= V_145 ) {
F_99 ( V_2 , V_71 ) ;
V_145 -= V_14 ;
} else {
F_23 ( V_2 ) -> V_76 [ V_144 ] = F_23 ( V_2 ) -> V_76 [ V_71 ] ;
if ( V_145 ) {
F_23 ( V_2 ) -> V_76 [ V_144 ] . V_110 += V_145 ;
F_142 ( & F_23 ( V_2 ) -> V_76 [ V_144 ] , V_145 ) ;
V_145 = 0 ;
}
V_144 ++ ;
}
}
F_23 ( V_2 ) -> V_83 = V_144 ;
V_2 -> V_9 += V_128 ;
V_2 -> V_74 -= V_128 ;
return F_120 ( V_2 ) ;
}
int F_111 ( const struct V_1 * V_2 , int V_139 , void * V_149 , int V_6 )
{
int V_150 = F_113 ( V_2 ) ;
struct V_1 * V_151 ;
int V_71 , V_152 ;
if ( V_139 > ( int ) V_2 -> V_6 - V_6 )
goto V_153;
if ( ( V_152 = V_150 - V_139 ) > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
F_143 ( V_2 , V_139 , V_149 , V_152 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return 0 ;
V_139 += V_152 ;
V_149 += V_152 ;
}
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ ) {
int V_10 ;
T_4 * V_108 = & F_23 ( V_2 ) -> V_76 [ V_71 ] ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + F_96 ( V_108 ) ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
T_3 * V_107 ;
if ( V_152 > V_6 )
V_152 = V_6 ;
V_107 = F_93 ( F_94 ( V_108 ) ) ;
memcpy ( V_149 ,
V_107 + V_108 -> V_110 + V_139 - V_150 ,
V_152 ) ;
F_97 ( V_107 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return 0 ;
V_139 += V_152 ;
V_149 += V_152 ;
}
V_150 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + V_151 -> V_6 ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
if ( F_111 ( V_151 , V_139 - V_150 , V_149 , V_152 ) )
goto V_153;
if ( ( V_6 -= V_152 ) == 0 )
return 0 ;
V_139 += V_152 ;
V_149 += V_152 ;
}
V_150 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_153:
return - V_154 ;
}
static void F_144 ( struct V_155 * V_156 , unsigned int V_71 )
{
F_92 ( V_156 -> V_157 [ V_71 ] ) ;
}
static struct V_72 * F_145 ( struct V_72 * V_72 , unsigned int * V_6 ,
unsigned int * V_139 ,
struct V_158 * V_101 )
{
struct V_159 * V_160 = F_146 ( V_101 ) ;
if ( ! F_147 ( V_101 , V_160 ) )
return NULL ;
* V_6 = F_148 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_95 ( V_160 -> V_72 ) + V_160 -> V_139 ,
F_95 ( V_72 ) + * V_139 , * V_6 ) ;
* V_139 = V_160 -> V_139 ;
V_160 -> V_139 += * V_6 ;
return V_160 -> V_72 ;
}
static bool F_149 ( const struct V_155 * V_156 ,
struct V_72 * V_72 ,
unsigned int V_139 )
{
return V_156 -> V_161 &&
V_156 -> V_157 [ V_156 -> V_161 - 1 ] == V_72 &&
( V_156 -> V_162 [ V_156 -> V_161 - 1 ] . V_139 +
V_156 -> V_162 [ V_156 -> V_161 - 1 ] . V_6 == V_139 ) ;
}
static bool F_150 ( struct V_155 * V_156 ,
struct V_163 * V_164 , struct V_72 * V_72 ,
unsigned int * V_6 , unsigned int V_139 ,
bool V_165 ,
struct V_158 * V_101 )
{
if ( F_42 ( V_156 -> V_161 == V_166 ) )
return true ;
if ( V_165 ) {
V_72 = F_145 ( V_72 , V_6 , & V_139 , V_101 ) ;
if ( ! V_72 )
return true ;
}
if ( F_149 ( V_156 , V_72 , V_139 ) ) {
V_156 -> V_162 [ V_156 -> V_161 - 1 ] . V_6 += * V_6 ;
return false ;
}
F_151 ( V_72 ) ;
V_156 -> V_157 [ V_156 -> V_161 ] = V_72 ;
V_156 -> V_162 [ V_156 -> V_161 ] . V_6 = * V_6 ;
V_156 -> V_162 [ V_156 -> V_161 ] . V_139 = V_139 ;
V_156 -> V_161 ++ ;
return false ;
}
static bool F_152 ( struct V_72 * V_72 , unsigned int V_167 ,
unsigned int V_168 , unsigned int * V_73 ,
unsigned int * V_6 ,
struct V_155 * V_156 , bool V_165 ,
struct V_158 * V_101 ,
struct V_163 * V_164 )
{
if ( ! * V_6 )
return true ;
if ( * V_73 >= V_168 ) {
* V_73 -= V_168 ;
return false ;
}
V_167 += * V_73 ;
V_168 -= * V_73 ;
* V_73 = 0 ;
do {
unsigned int V_169 = F_153 ( * V_6 , V_168 ) ;
if ( F_150 ( V_156 , V_164 , V_72 , & V_169 , V_167 ,
V_165 , V_101 ) )
return true ;
V_167 += V_169 ;
V_168 -= V_169 ;
* V_6 -= V_169 ;
} while ( * V_6 && V_168 );
return false ;
}
static bool F_154 ( struct V_1 * V_2 , struct V_163 * V_164 ,
unsigned int * V_139 , unsigned int * V_6 ,
struct V_155 * V_156 , struct V_158 * V_101 )
{
int V_170 ;
if ( F_152 ( F_155 ( V_2 -> V_8 ) ,
( unsigned long ) V_2 -> V_8 & ( V_62 - 1 ) ,
F_113 ( V_2 ) ,
V_139 , V_6 , V_156 ,
F_156 ( V_2 ) ,
V_101 , V_164 ) )
return true ;
for ( V_170 = 0 ; V_170 < F_23 ( V_2 ) -> V_83 ; V_170 ++ ) {
const T_4 * V_108 = & F_23 ( V_2 ) -> V_76 [ V_170 ] ;
if ( F_152 ( F_94 ( V_108 ) ,
V_108 -> V_110 , F_96 ( V_108 ) ,
V_139 , V_6 , V_156 , false , V_101 , V_164 ) )
return true ;
}
return false ;
}
T_6 F_157 ( struct V_158 * V_101 ,
struct V_163 * V_164 ,
struct V_155 * V_156 )
{
int V_171 ;
F_158 ( V_101 ) ;
V_171 = F_159 ( V_164 , V_156 ) ;
F_160 ( V_101 ) ;
return V_171 ;
}
int F_161 ( struct V_1 * V_2 , struct V_158 * V_101 , unsigned int V_139 ,
struct V_163 * V_164 , unsigned int V_172 ,
unsigned int V_15 ,
T_6 (* F_162)( struct V_158 * ,
struct V_163 * ,
struct V_155 * ) )
{
struct V_173 V_162 [ V_166 ] ;
struct V_72 * V_157 [ V_166 ] ;
struct V_155 V_156 = {
. V_157 = V_157 ,
. V_162 = V_162 ,
. V_174 = V_166 ,
. V_15 = V_15 ,
. V_175 = & V_176 ,
. V_177 = F_144 ,
} ;
struct V_1 * V_151 ;
int V_171 = 0 ;
if ( F_154 ( V_2 , V_164 , & V_139 , & V_172 , & V_156 , V_101 ) )
goto V_142;
else if ( ! V_172 )
goto V_142;
F_54 (skb, frag_iter) {
if ( ! V_172 )
break;
if ( F_154 ( V_151 , V_164 , & V_139 , & V_172 , & V_156 , V_101 ) )
break;
}
V_142:
if ( V_156 . V_161 )
V_171 = F_162 ( V_101 , V_164 , & V_156 ) ;
return V_171 ;
}
int F_163 ( struct V_1 * V_2 , int V_139 , const void * V_178 , int V_6 )
{
int V_150 = F_113 ( V_2 ) ;
struct V_1 * V_151 ;
int V_71 , V_152 ;
if ( V_139 > ( int ) V_2 -> V_6 - V_6 )
goto V_153;
if ( ( V_152 = V_150 - V_139 ) > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
F_164 ( V_2 , V_139 , V_178 , V_152 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return 0 ;
V_139 += V_152 ;
V_178 += V_152 ;
}
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ ) {
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_71 ] ;
int V_10 ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + F_96 ( V_75 ) ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
T_3 * V_107 ;
if ( V_152 > V_6 )
V_152 = V_6 ;
V_107 = F_93 ( F_94 ( V_75 ) ) ;
memcpy ( V_107 + V_75 -> V_110 + V_139 - V_150 ,
V_178 , V_152 ) ;
F_97 ( V_107 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return 0 ;
V_139 += V_152 ;
V_178 += V_152 ;
}
V_150 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + V_151 -> V_6 ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
if ( F_163 ( V_151 , V_139 - V_150 ,
V_178 , V_152 ) )
goto V_153;
if ( ( V_6 -= V_152 ) == 0 )
return 0 ;
V_139 += V_152 ;
V_178 += V_152 ;
}
V_150 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_153:
return - V_154 ;
}
T_7 F_165 ( const struct V_1 * V_2 , int V_139 , int V_6 ,
T_7 V_179 , const struct V_180 * V_175 )
{
int V_150 = F_113 ( V_2 ) ;
int V_71 , V_152 = V_150 - V_139 ;
struct V_1 * V_151 ;
int V_181 = 0 ;
if ( V_152 > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
V_179 = V_175 -> V_182 ( V_2 -> V_8 + V_139 , V_152 , V_179 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return V_179 ;
V_139 += V_152 ;
V_181 = V_152 ;
}
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ ) {
int V_10 ;
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_71 ] ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + F_96 ( V_75 ) ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
T_7 V_183 ;
T_3 * V_107 ;
if ( V_152 > V_6 )
V_152 = V_6 ;
V_107 = F_93 ( F_94 ( V_75 ) ) ;
V_183 = V_175 -> V_182 ( V_107 + V_75 -> V_110 +
V_139 - V_150 , V_152 , 0 ) ;
F_97 ( V_107 ) ;
V_179 = V_175 -> V_184 ( V_179 , V_183 , V_181 , V_152 ) ;
if ( ! ( V_6 -= V_152 ) )
return V_179 ;
V_139 += V_152 ;
V_181 += V_152 ;
}
V_150 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + V_151 -> V_6 ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
T_7 V_183 ;
if ( V_152 > V_6 )
V_152 = V_6 ;
V_183 = F_165 ( V_151 , V_139 - V_150 ,
V_152 , 0 , V_175 ) ;
V_179 = V_175 -> V_184 ( V_179 , V_183 , V_181 , V_152 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return V_179 ;
V_139 += V_152 ;
V_181 += V_152 ;
}
V_150 = V_10 ;
}
F_118 ( V_6 ) ;
return V_179 ;
}
T_7 F_166 ( const struct V_1 * V_2 , int V_139 ,
int V_6 , T_7 V_179 )
{
const struct V_180 V_175 = {
. V_182 = V_185 ,
. V_184 = V_186 ,
} ;
return F_165 ( V_2 , V_139 , V_6 , V_179 , & V_175 ) ;
}
T_7 F_167 ( const struct V_1 * V_2 , int V_139 ,
T_3 * V_149 , int V_6 , T_7 V_179 )
{
int V_150 = F_113 ( V_2 ) ;
int V_71 , V_152 = V_150 - V_139 ;
struct V_1 * V_151 ;
int V_181 = 0 ;
if ( V_152 > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
V_179 = F_168 ( V_2 -> V_8 + V_139 , V_149 ,
V_152 , V_179 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return V_179 ;
V_139 += V_152 ;
V_149 += V_152 ;
V_181 = V_152 ;
}
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ ) {
int V_10 ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + F_96 ( & F_23 ( V_2 ) -> V_76 [ V_71 ] ) ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
T_7 V_183 ;
T_3 * V_107 ;
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_71 ] ;
if ( V_152 > V_6 )
V_152 = V_6 ;
V_107 = F_93 ( F_94 ( V_75 ) ) ;
V_183 = F_168 ( V_107 +
V_75 -> V_110 +
V_139 - V_150 , V_149 ,
V_152 , 0 ) ;
F_97 ( V_107 ) ;
V_179 = F_169 ( V_179 , V_183 , V_181 ) ;
if ( ! ( V_6 -= V_152 ) )
return V_179 ;
V_139 += V_152 ;
V_149 += V_152 ;
V_181 += V_152 ;
}
V_150 = V_10 ;
}
F_54 (skb, frag_iter) {
T_7 V_183 ;
int V_10 ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + V_151 -> V_6 ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
V_183 = F_167 ( V_151 ,
V_139 - V_150 ,
V_149 , V_152 , 0 ) ;
V_179 = F_169 ( V_179 , V_183 , V_181 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return V_179 ;
V_139 += V_152 ;
V_149 += V_152 ;
V_181 += V_152 ;
}
V_150 = V_10 ;
}
F_118 ( V_6 ) ;
return V_179 ;
}
unsigned int
F_170 ( const struct V_1 * V_178 )
{
unsigned int V_187 = 0 ;
if ( ! V_178 -> V_53 ||
F_113 ( V_178 ) < V_188 ||
F_23 ( V_178 ) -> V_83 >= V_166 )
V_187 = F_113 ( V_178 ) ;
if ( F_116 ( V_178 ) )
V_187 = V_178 -> V_6 ;
return V_187 ;
}
int
F_171 ( struct V_1 * V_149 , struct V_1 * V_178 , int V_6 , int V_187 )
{
int V_71 , V_189 = 0 ;
int V_168 = 0 ;
int V_171 ;
struct V_72 * V_72 ;
unsigned int V_139 ;
F_118 ( ! V_178 -> V_53 && ! V_187 ) ;
if ( V_6 <= F_127 ( V_149 ) )
return F_111 ( V_178 , 0 , F_110 ( V_149 , V_6 ) , V_6 ) ;
if ( V_187 ) {
V_171 = F_111 ( V_178 , 0 , F_110 ( V_149 , V_187 ) , V_187 ) ;
if ( F_42 ( V_171 ) )
return V_171 ;
V_6 -= V_187 ;
} else {
V_168 = F_148 ( int , F_113 ( V_178 ) , V_6 ) ;
if ( V_168 ) {
V_72 = F_32 ( V_178 -> V_7 ) ;
V_139 = V_178 -> V_8 - ( unsigned char * ) F_95 ( V_72 ) ;
F_100 ( V_149 , 0 , V_72 , V_139 , V_168 ) ;
F_151 ( V_72 ) ;
V_189 = 1 ;
V_6 -= V_168 ;
}
}
V_149 -> V_27 += V_6 + V_168 ;
V_149 -> V_6 += V_6 + V_168 ;
V_149 -> V_74 += V_6 + V_168 ;
if ( F_42 ( F_102 ( V_178 , V_52 ) ) ) {
F_80 ( V_178 ) ;
return - V_109 ;
}
for ( V_71 = 0 ; V_71 < F_23 ( V_178 ) -> V_83 ; V_71 ++ ) {
if ( ! V_6 )
break;
F_23 ( V_149 ) -> V_76 [ V_189 ] = F_23 ( V_178 ) -> V_76 [ V_71 ] ;
F_23 ( V_149 ) -> V_76 [ V_189 ] . V_14 = F_148 ( int , F_23 ( V_149 ) -> V_76 [ V_189 ] . V_14 , V_6 ) ;
V_6 -= F_23 ( V_149 ) -> V_76 [ V_189 ] . V_14 ;
F_115 ( V_149 , V_189 ) ;
V_189 ++ ;
}
F_23 ( V_149 ) -> V_83 = V_189 ;
return 0 ;
}
void F_172 ( const struct V_1 * V_2 , T_3 * V_149 )
{
T_7 V_179 ;
long V_190 ;
if ( V_2 -> V_111 == V_112 )
V_190 = F_173 ( V_2 ) ;
else
V_190 = F_113 ( V_2 ) ;
F_118 ( V_190 > F_113 ( V_2 ) ) ;
F_114 ( V_2 , V_149 , V_190 ) ;
V_179 = 0 ;
if ( V_190 != V_2 -> V_6 )
V_179 = F_167 ( V_2 , V_190 , V_149 + V_190 ,
V_2 -> V_6 - V_190 , 0 ) ;
if ( V_2 -> V_111 == V_112 ) {
long V_191 = V_190 + V_2 -> V_192 ;
* ( ( V_193 * ) ( V_149 + V_191 ) ) = F_174 ( V_179 ) ;
}
}
struct V_1 * F_175 ( struct V_194 * V_79 )
{
unsigned long V_15 ;
struct V_1 * V_195 ;
F_176 ( & V_79 -> V_196 , V_15 ) ;
V_195 = F_177 ( V_79 ) ;
F_178 ( & V_79 -> V_196 , V_15 ) ;
return V_195 ;
}
struct V_1 * F_179 ( struct V_194 * V_79 )
{
unsigned long V_15 ;
struct V_1 * V_195 ;
F_176 ( & V_79 -> V_196 , V_15 ) ;
V_195 = F_180 ( V_79 ) ;
F_178 ( & V_79 -> V_196 , V_15 ) ;
return V_195 ;
}
void F_181 ( struct V_194 * V_79 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_175 ( V_79 ) ) != NULL )
F_76 ( V_2 ) ;
}
void F_182 ( struct V_194 * V_79 , struct V_1 * V_197 )
{
unsigned long V_15 ;
F_176 ( & V_79 -> V_196 , V_15 ) ;
F_183 ( V_79 , V_197 ) ;
F_178 ( & V_79 -> V_196 , V_15 ) ;
}
void F_184 ( struct V_194 * V_79 , struct V_1 * V_197 )
{
unsigned long V_15 ;
F_176 ( & V_79 -> V_196 , V_15 ) ;
F_185 ( V_79 , V_197 ) ;
F_178 ( & V_79 -> V_196 , V_15 ) ;
}
void F_186 ( struct V_1 * V_2 , struct V_194 * V_79 )
{
unsigned long V_15 ;
F_176 ( & V_79 -> V_196 , V_15 ) ;
F_187 ( V_2 , V_79 ) ;
F_178 ( & V_79 -> V_196 , V_15 ) ;
}
void F_188 ( struct V_1 * V_119 , struct V_1 * V_197 , struct V_194 * V_79 )
{
unsigned long V_15 ;
F_176 ( & V_79 -> V_196 , V_15 ) ;
F_189 ( V_79 , V_119 , V_197 ) ;
F_178 ( & V_79 -> V_196 , V_15 ) ;
}
void F_190 ( struct V_1 * V_119 , struct V_1 * V_197 , struct V_194 * V_79 )
{
unsigned long V_15 ;
F_176 ( & V_79 -> V_196 , V_15 ) ;
F_191 ( V_197 , V_119 -> V_100 , V_119 , V_79 ) ;
F_178 ( & V_79 -> V_196 , V_15 ) ;
}
static inline void F_192 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_8 V_6 , const int V_181 )
{
int V_71 ;
F_143 ( V_2 , V_6 , F_110 ( V_44 , V_181 - V_6 ) ,
V_181 - V_6 ) ;
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ )
F_23 ( V_44 ) -> V_76 [ V_71 ] = F_23 ( V_2 ) -> V_76 [ V_71 ] ;
F_23 ( V_44 ) -> V_83 = F_23 ( V_2 ) -> V_83 ;
F_23 ( V_2 ) -> V_83 = 0 ;
V_44 -> V_74 = V_2 -> V_74 ;
V_44 -> V_6 += V_44 -> V_74 ;
V_2 -> V_74 = 0 ;
V_2 -> V_6 = V_6 ;
F_139 ( V_2 , V_6 ) ;
}
static inline void F_193 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_8 V_6 , int V_181 )
{
int V_71 , V_144 = 0 ;
const int V_140 = F_23 ( V_2 ) -> V_83 ;
F_23 ( V_2 ) -> V_83 = 0 ;
V_44 -> V_6 = V_44 -> V_74 = V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_74 = V_6 - V_181 ;
for ( V_71 = 0 ; V_71 < V_140 ; V_71 ++ ) {
int V_14 = F_96 ( & F_23 ( V_2 ) -> V_76 [ V_71 ] ) ;
if ( V_181 + V_14 > V_6 ) {
F_23 ( V_44 ) -> V_76 [ V_144 ] = F_23 ( V_2 ) -> V_76 [ V_71 ] ;
if ( V_181 < V_6 ) {
F_115 ( V_2 , V_71 ) ;
F_23 ( V_44 ) -> V_76 [ 0 ] . V_110 += V_6 - V_181 ;
F_142 ( & F_23 ( V_44 ) -> V_76 [ 0 ] , V_6 - V_181 ) ;
F_137 ( & F_23 ( V_2 ) -> V_76 [ V_71 ] , V_6 - V_181 ) ;
F_23 ( V_2 ) -> V_83 ++ ;
}
V_144 ++ ;
} else
F_23 ( V_2 ) -> V_83 ++ ;
V_181 += V_14 ;
}
F_23 ( V_44 ) -> V_83 = V_144 ;
}
void F_194 ( struct V_1 * V_2 , struct V_1 * V_44 , const T_8 V_6 )
{
int V_181 = F_113 ( V_2 ) ;
F_23 ( V_44 ) -> V_84 = F_23 ( V_2 ) -> V_84 & V_198 ;
if ( V_6 < V_181 )
F_192 ( V_2 , V_44 , V_6 , V_181 ) ;
else
F_193 ( V_2 , V_44 , V_6 , V_181 ) ;
}
static int F_195 ( struct V_1 * V_2 )
{
return F_121 ( V_2 ) && F_117 ( V_2 , 0 , 0 , V_52 ) ;
}
int F_196 ( struct V_1 * V_199 , struct V_1 * V_2 , int V_200 )
{
int V_178 , V_149 , V_201 , V_202 ;
struct V_203 * V_204 , * V_205 ;
F_118 ( V_200 > V_2 -> V_6 ) ;
F_118 ( F_113 ( V_2 ) ) ;
V_202 = V_200 ;
V_178 = 0 ;
V_149 = F_23 ( V_199 ) -> V_83 ;
V_204 = & F_23 ( V_2 ) -> V_76 [ V_178 ] ;
if ( ! V_149 ||
! F_197 ( V_199 , V_149 , F_94 ( V_204 ) ,
V_204 -> V_110 ) ) {
V_201 = - 1 ;
} else {
V_201 = V_149 - 1 ;
V_202 -= F_96 ( V_204 ) ;
if ( V_202 < 0 ) {
if ( F_195 ( V_2 ) ||
F_195 ( V_199 ) )
return 0 ;
V_204 = & F_23 ( V_2 ) -> V_76 [ V_178 ] ;
V_205 = & F_23 ( V_199 ) -> V_76 [ V_201 ] ;
F_49 ( V_205 , V_200 ) ;
F_142 ( V_204 , V_200 ) ;
V_204 -> V_110 += V_200 ;
goto V_206;
}
V_178 ++ ;
}
if ( ( V_200 == V_2 -> V_6 ) &&
( F_23 ( V_2 ) -> V_83 - V_178 ) > ( V_166 - V_149 ) )
return 0 ;
if ( F_195 ( V_2 ) || F_195 ( V_199 ) )
return 0 ;
while ( ( V_202 > 0 ) && ( V_178 < F_23 ( V_2 ) -> V_83 ) ) {
if ( V_149 == V_166 )
return 0 ;
V_204 = & F_23 ( V_2 ) -> V_76 [ V_178 ] ;
V_205 = & F_23 ( V_199 ) -> V_76 [ V_149 ] ;
if ( V_202 >= F_96 ( V_204 ) ) {
* V_205 = * V_204 ;
V_202 -= F_96 ( V_204 ) ;
V_178 ++ ;
V_149 ++ ;
} else {
F_198 ( V_204 ) ;
V_205 -> V_72 = V_204 -> V_72 ;
V_205 -> V_110 = V_204 -> V_110 ;
F_137 ( V_205 , V_202 ) ;
V_204 -> V_110 += V_202 ;
F_142 ( V_204 , V_202 ) ;
V_202 = 0 ;
V_149 ++ ;
break;
}
}
F_23 ( V_199 ) -> V_83 = V_149 ;
if ( V_201 >= 0 ) {
V_204 = & F_23 ( V_2 ) -> V_76 [ 0 ] ;
V_205 = & F_23 ( V_199 ) -> V_76 [ V_201 ] ;
F_49 ( V_205 , F_96 ( V_204 ) ) ;
F_60 ( V_204 ) ;
}
V_149 = 0 ;
while ( V_178 < F_23 ( V_2 ) -> V_83 )
F_23 ( V_2 ) -> V_76 [ V_149 ++ ] = F_23 ( V_2 ) -> V_76 [ V_178 ++ ] ;
F_23 ( V_2 ) -> V_83 = V_149 ;
F_118 ( V_202 > 0 && ! F_23 ( V_2 ) -> V_83 ) ;
V_206:
V_199 -> V_111 = V_112 ;
V_2 -> V_111 = V_112 ;
V_2 -> V_6 -= V_200 ;
V_2 -> V_74 -= V_200 ;
V_2 -> V_27 -= V_200 ;
V_199 -> V_6 += V_200 ;
V_199 -> V_74 += V_200 ;
V_199 -> V_27 += V_200 ;
return V_200 ;
}
void F_199 ( struct V_1 * V_2 , unsigned int V_178 ,
unsigned int V_149 , struct V_207 * V_208 )
{
V_208 -> V_209 = V_178 ;
V_208 -> V_210 = V_149 ;
V_208 -> V_211 = V_208 -> V_212 = V_2 ;
V_208 -> V_213 = V_208 -> V_214 = 0 ;
V_208 -> V_215 = NULL ;
}
unsigned int F_200 ( unsigned int V_216 , const T_3 * * V_8 ,
struct V_207 * V_208 )
{
unsigned int V_217 , V_218 = V_216 + V_208 -> V_209 ;
T_4 * V_75 ;
if ( F_42 ( V_218 >= V_208 -> V_210 ) ) {
if ( V_208 -> V_215 ) {
F_97 ( V_208 -> V_215 ) ;
V_208 -> V_215 = NULL ;
}
return 0 ;
}
V_219:
V_217 = F_113 ( V_208 -> V_212 ) + V_208 -> V_214 ;
if ( V_218 < V_217 && ! V_208 -> V_215 ) {
* V_8 = V_208 -> V_212 -> V_8 + ( V_218 - V_208 -> V_214 ) ;
return V_217 - V_218 ;
}
if ( V_208 -> V_213 == 0 && ! V_208 -> V_215 )
V_208 -> V_214 += F_113 ( V_208 -> V_212 ) ;
while ( V_208 -> V_213 < F_23 ( V_208 -> V_212 ) -> V_83 ) {
V_75 = & F_23 ( V_208 -> V_212 ) -> V_76 [ V_208 -> V_213 ] ;
V_217 = F_96 ( V_75 ) + V_208 -> V_214 ;
if ( V_218 < V_217 ) {
if ( ! V_208 -> V_215 )
V_208 -> V_215 = F_93 ( F_94 ( V_75 ) ) ;
* V_8 = ( T_3 * ) V_208 -> V_215 + V_75 -> V_110 +
( V_218 - V_208 -> V_214 ) ;
return V_217 - V_218 ;
}
if ( V_208 -> V_215 ) {
F_97 ( V_208 -> V_215 ) ;
V_208 -> V_215 = NULL ;
}
V_208 -> V_213 ++ ;
V_208 -> V_214 += F_96 ( V_75 ) ;
}
if ( V_208 -> V_215 ) {
F_97 ( V_208 -> V_215 ) ;
V_208 -> V_215 = NULL ;
}
if ( V_208 -> V_211 == V_208 -> V_212 && F_116 ( V_208 -> V_211 ) ) {
V_208 -> V_212 = F_23 ( V_208 -> V_211 ) -> V_78 ;
V_208 -> V_213 = 0 ;
goto V_219;
} else if ( V_208 -> V_212 -> V_98 ) {
V_208 -> V_212 = V_208 -> V_212 -> V_98 ;
V_208 -> V_213 = 0 ;
goto V_219;
}
return 0 ;
}
void F_201 ( struct V_207 * V_208 )
{
if ( V_208 -> V_215 )
F_97 ( V_208 -> V_215 ) ;
}
static unsigned int F_202 ( unsigned int V_139 , const T_3 * * V_220 ,
struct V_221 * V_222 ,
struct V_223 * V_224 )
{
return F_200 ( V_139 , V_220 , F_203 ( V_224 ) ) ;
}
static void F_204 ( struct V_221 * V_222 , struct V_223 * V_224 )
{
F_201 ( F_203 ( V_224 ) ) ;
}
unsigned int F_205 ( struct V_1 * V_2 , unsigned int V_178 ,
unsigned int V_149 , struct V_221 * V_225 )
{
struct V_223 V_224 ;
unsigned int V_171 ;
V_225 -> V_226 = F_202 ;
V_225 -> V_227 = F_204 ;
F_199 ( V_2 , V_178 , V_149 , F_203 ( & V_224 ) ) ;
V_171 = F_206 ( V_225 , & V_224 ) ;
return ( V_171 <= V_149 - V_178 ? V_171 : V_228 ) ;
}
int F_207 ( struct V_158 * V_101 , struct V_1 * V_2 ,
int (* F_208)( void * V_178 , char * V_149 , int V_139 ,
int V_6 , int V_229 , struct V_1 * V_2 ) ,
void * V_178 , int V_230 )
{
int V_231 = F_23 ( V_2 ) -> V_83 ;
int V_152 ;
int V_139 = 0 ;
int V_171 ;
struct V_159 * V_160 = & V_232 -> V_233 ;
do {
if ( V_231 >= V_166 )
return - V_234 ;
if ( ! F_147 ( V_101 , V_160 ) )
return - V_109 ;
V_152 = F_148 ( int , V_230 , V_160 -> V_14 - V_160 -> V_139 ) ;
V_171 = F_208 ( V_178 , F_95 ( V_160 -> V_72 ) + V_160 -> V_139 ,
V_139 , V_152 , 0 , V_2 ) ;
if ( V_171 < 0 )
return - V_154 ;
F_47 ( V_2 , V_231 , V_160 -> V_72 , V_160 -> V_139 ,
V_152 ) ;
V_231 ++ ;
V_160 -> V_139 += V_152 ;
F_151 ( V_160 -> V_72 ) ;
V_2 -> V_27 += V_152 ;
F_209 ( V_152 , & V_101 -> V_235 ) ;
V_2 -> V_6 += V_152 ;
V_2 -> V_74 += V_152 ;
V_139 += V_152 ;
V_230 -= V_152 ;
} while ( V_230 > 0 );
return 0 ;
}
int F_210 ( struct V_1 * V_2 , struct V_72 * V_72 ,
int V_139 , T_1 V_14 )
{
int V_71 = F_23 ( V_2 ) -> V_83 ;
if ( F_197 ( V_2 , V_71 , V_72 , V_139 ) ) {
F_49 ( & F_23 ( V_2 ) -> V_76 [ V_71 - 1 ] , V_14 ) ;
} else if ( V_71 < V_166 ) {
F_151 ( V_72 ) ;
F_47 ( V_2 , V_71 , V_72 , V_139 , V_14 ) ;
} else {
return - V_234 ;
}
return 0 ;
}
unsigned char * F_211 ( struct V_1 * V_2 , unsigned int V_6 )
{
F_118 ( V_6 > V_2 -> V_6 ) ;
V_2 -> V_6 -= V_6 ;
F_118 ( V_2 -> V_6 < V_2 -> V_74 ) ;
F_212 ( V_2 , V_2 -> V_8 , V_6 ) ;
return V_2 -> V_8 += V_6 ;
}
struct V_1 * F_213 ( struct V_1 * V_236 ,
T_9 V_237 )
{
struct V_1 * V_97 = NULL ;
struct V_1 * V_9 = NULL ;
struct V_1 * V_238 = F_23 ( V_236 ) -> V_78 ;
T_4 * V_75 = F_23 ( V_236 ) -> V_76 ;
unsigned int V_239 = F_23 ( V_236 ) -> V_120 ;
unsigned int V_240 = V_236 -> V_8 - F_214 ( V_236 ) ;
struct V_1 * V_241 = V_236 ;
unsigned int V_139 = V_240 ;
unsigned int V_242 = F_215 ( V_236 ) ;
unsigned int V_124 ;
unsigned int V_6 ;
T_10 V_243 ;
bool V_179 ;
int V_244 = ! ! ( V_237 & V_245 ) ;
int V_140 = F_23 ( V_236 ) -> V_83 ;
int V_135 = - V_109 ;
int V_71 = 0 ;
int V_181 ;
int V_246 ;
F_216 ( V_236 , V_240 ) ;
V_243 = F_217 ( V_236 , & V_246 ) ;
if ( F_42 ( ! V_243 ) )
return F_218 ( - V_247 ) ;
V_179 = ! V_236 -> V_248 &&
! ! F_219 ( V_237 , V_243 ) ;
V_124 = F_86 ( V_236 ) ;
V_181 = F_113 ( V_236 ) ;
do {
struct V_1 * V_249 ;
T_4 * V_250 ;
int V_251 ;
int V_14 ;
V_6 = V_236 -> V_6 - V_139 ;
if ( V_6 > V_239 )
V_6 = V_239 ;
V_251 = F_113 ( V_236 ) - V_139 ;
if ( V_251 < 0 )
V_251 = 0 ;
if ( V_251 > V_6 || ! V_244 )
V_251 = V_6 ;
if ( ! V_251 && V_71 >= V_140 && F_113 ( V_238 ) &&
( F_113 ( V_238 ) == V_6 || V_244 ) ) {
F_118 ( F_113 ( V_238 ) > V_6 ) ;
V_71 = 0 ;
V_140 = F_23 ( V_238 ) -> V_83 ;
V_75 = F_23 ( V_238 ) -> V_76 ;
V_241 = V_238 ;
V_181 += F_113 ( V_238 ) ;
while ( V_181 < V_139 + V_6 ) {
F_118 ( V_71 >= V_140 ) ;
V_14 = F_96 ( V_75 ) ;
if ( V_181 + V_14 > V_139 + V_6 )
break;
V_71 ++ ;
V_181 += V_14 ;
V_75 ++ ;
}
V_249 = F_101 ( V_238 , V_52 ) ;
V_238 = V_238 -> V_98 ;
if ( F_42 ( ! V_249 ) )
goto V_135;
if ( F_42 ( F_138 ( V_249 , V_6 ) ) ) {
F_76 ( V_249 ) ;
goto V_135;
}
V_251 = F_109 ( V_249 ) ;
if ( F_220 ( V_249 , V_240 + V_124 ) ) {
F_76 ( V_249 ) ;
goto V_135;
}
V_249 -> V_27 += F_109 ( V_249 ) - V_251 ;
F_64 ( V_249 ) ;
F_216 ( V_249 , V_240 ) ;
} else {
V_249 = F_14 ( V_251 + V_240 + V_124 ,
V_52 , F_107 ( V_236 ) ,
V_65 ) ;
if ( F_42 ( ! V_249 ) )
goto V_135;
F_44 ( V_249 , V_124 ) ;
F_221 ( V_249 , V_240 ) ;
}
if ( V_97 )
V_9 -> V_98 = V_249 ;
else
V_97 = V_249 ;
V_9 = V_249 ;
F_85 ( V_249 , V_236 ) ;
F_104 ( V_249 , F_86 ( V_249 ) - V_124 ) ;
F_222 ( V_249 ) ;
F_143 ( V_236 , - V_242 ,
V_249 -> V_8 - V_242 ,
V_240 + V_242 ) ;
if ( V_249 -> V_6 == V_6 + V_240 )
goto V_252;
if ( ! V_244 && ! V_249 -> V_253 ) {
V_249 -> V_111 = V_254 ;
V_249 -> V_179 = F_167 ( V_236 , V_139 ,
F_110 ( V_249 , V_6 ) ,
V_6 , 0 ) ;
F_223 ( V_249 ) -> V_113 =
F_86 ( V_249 ) + V_240 ;
continue;
}
V_250 = F_23 ( V_249 ) -> V_76 ;
F_143 ( V_236 , V_139 ,
F_110 ( V_249 , V_251 ) , V_251 ) ;
F_23 ( V_249 ) -> V_84 = F_23 ( V_236 ) -> V_84 &
V_198 ;
while ( V_181 < V_139 + V_6 ) {
if ( V_71 >= V_140 ) {
F_118 ( F_113 ( V_238 ) ) ;
V_71 = 0 ;
V_140 = F_23 ( V_238 ) -> V_83 ;
V_75 = F_23 ( V_238 ) -> V_76 ;
V_241 = V_238 ;
F_118 ( ! V_140 ) ;
V_238 = V_238 -> V_98 ;
}
if ( F_42 ( F_23 ( V_249 ) -> V_83 >=
V_166 ) ) {
F_224 (
L_3 ,
V_181 , V_239 ) ;
goto V_135;
}
if ( F_42 ( F_102 ( V_241 , V_52 ) ) )
goto V_135;
* V_250 = * V_75 ;
F_198 ( V_250 ) ;
V_14 = F_96 ( V_250 ) ;
if ( V_181 < V_139 ) {
V_250 -> V_110 += V_139 - V_181 ;
F_142 ( V_250 , V_139 - V_181 ) ;
}
F_23 ( V_249 ) -> V_83 ++ ;
if ( V_181 + V_14 <= V_139 + V_6 ) {
V_71 ++ ;
V_75 ++ ;
V_181 += V_14 ;
} else {
F_142 ( V_250 , V_181 + V_14 - ( V_139 + V_6 ) ) ;
goto V_255;
}
V_250 ++ ;
}
V_255:
V_249 -> V_74 = V_6 - V_251 ;
V_249 -> V_6 += V_249 -> V_74 ;
V_249 -> V_27 += V_249 -> V_74 ;
V_252:
if ( ! V_179 && ! V_249 -> V_253 ) {
V_249 -> V_179 = F_166 ( V_249 , V_240 ,
V_249 -> V_6 - V_240 , 0 ) ;
V_249 -> V_111 = V_254 ;
F_223 ( V_249 ) -> V_113 =
F_86 ( V_249 ) + V_240 ;
}
} while ( ( V_139 += V_6 ) < V_236 -> V_6 );
V_97 -> V_100 = V_9 ;
if ( V_236 -> V_92 == V_256 ) {
F_225 ( V_9 -> V_27 , V_236 -> V_27 ) ;
F_225 ( V_9 -> V_92 , V_236 -> V_92 ) ;
F_225 ( V_9 -> V_101 , V_236 -> V_101 ) ;
}
return V_97 ;
V_135:
F_51 ( V_97 ) ;
return F_218 ( V_135 ) ;
}
int F_226 ( struct V_1 * * V_7 , struct V_1 * V_2 )
{
struct V_32 * V_257 , * V_258 = F_23 ( V_2 ) ;
unsigned int V_139 = F_227 ( V_2 ) ;
unsigned int V_259 = F_113 ( V_2 ) ;
unsigned int V_6 = F_228 ( V_2 ) ;
struct V_1 * V_260 , * V_261 = * V_7 ;
unsigned int V_262 ;
if ( F_42 ( V_261 -> V_6 + V_6 >= 65536 ) )
return - V_263 ;
V_260 = F_229 ( V_261 ) -> V_264 ;
V_257 = F_23 ( V_260 ) ;
if ( V_259 <= V_139 ) {
T_4 * V_75 ;
T_4 * V_265 ;
int V_71 = V_258 -> V_83 ;
int V_83 = V_257 -> V_83 + V_71 ;
if ( V_83 > V_166 )
goto V_201;
V_139 -= V_259 ;
V_257 -> V_83 = V_83 ;
V_258 -> V_83 = 0 ;
V_75 = V_257 -> V_76 + V_83 ;
V_265 = V_258 -> V_76 + V_71 ;
do {
* -- V_75 = * -- V_265 ;
} while ( -- V_71 );
V_75 -> V_110 += V_139 ;
F_142 ( V_75 , V_139 ) ;
V_262 = V_2 -> V_27 -
F_21 ( F_109 ( V_2 ) ) ;
V_2 -> V_27 -= V_2 -> V_74 ;
V_2 -> V_6 -= V_2 -> V_74 ;
V_2 -> V_74 = 0 ;
F_229 ( V_2 ) -> free = V_266 ;
goto V_142;
} else if ( V_2 -> V_53 ) {
int V_83 = V_257 -> V_83 ;
T_4 * V_75 = V_257 -> V_76 + V_83 ;
struct V_72 * V_72 = F_32 ( V_2 -> V_7 ) ;
unsigned int V_267 = V_259 - V_139 ;
unsigned int V_268 ;
if ( V_83 + 1 + V_258 -> V_83 > V_166 )
goto V_201;
V_268 = V_2 -> V_8 -
( unsigned char * ) F_95 ( V_72 ) +
V_139 ;
V_257 -> V_83 = V_83 + 1 + V_258 -> V_83 ;
V_75 -> V_72 . V_261 = V_72 ;
V_75 -> V_110 = V_268 ;
F_137 ( V_75 , V_267 ) ;
memcpy ( V_75 + 1 , V_258 -> V_76 , sizeof( * V_75 ) * V_258 -> V_83 ) ;
V_262 = V_2 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
F_229 ( V_2 ) -> free = V_269 ;
goto V_142;
}
V_201:
V_262 = V_2 -> V_27 ;
if ( V_139 > V_259 ) {
unsigned int V_145 = V_139 - V_259 ;
V_258 -> V_76 [ 0 ] . V_110 += V_145 ;
F_142 ( & V_258 -> V_76 [ 0 ] , V_145 ) ;
V_2 -> V_74 -= V_145 ;
V_2 -> V_6 -= V_145 ;
V_139 = V_259 ;
}
F_230 ( V_2 , V_139 ) ;
if ( F_229 ( V_261 ) -> V_264 == V_261 )
F_23 ( V_261 ) -> V_78 = V_2 ;
else
F_229 ( V_261 ) -> V_264 -> V_98 = V_2 ;
F_229 ( V_261 ) -> V_264 = V_2 ;
F_231 ( V_2 ) ;
V_260 = V_261 ;
V_142:
F_229 ( V_261 ) -> V_270 ++ ;
V_261 -> V_74 += V_6 ;
V_261 -> V_27 += V_262 ;
V_261 -> V_6 += V_6 ;
if ( V_260 != V_261 ) {
V_260 -> V_74 += V_6 ;
V_260 -> V_27 += V_262 ;
V_260 -> V_6 += V_6 ;
}
F_229 ( V_2 ) -> V_271 = 1 ;
return 0 ;
}
void T_11 F_232 ( void )
{
V_25 = F_233 ( L_4 ,
sizeof( struct V_1 ) ,
0 ,
V_272 | V_273 ,
NULL ) ;
V_35 = F_233 ( L_5 ,
sizeof( struct V_42 ) ,
0 ,
V_272 | V_273 ,
NULL ) ;
}
static int
F_234 ( struct V_1 * V_2 , struct V_274 * V_244 , int V_139 , int V_6 )
{
int V_150 = F_113 ( V_2 ) ;
int V_71 , V_152 = V_150 - V_139 ;
struct V_1 * V_151 ;
int V_275 = 0 ;
if ( V_152 > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
F_235 ( V_244 , V_2 -> V_8 + V_139 , V_152 ) ;
V_275 ++ ;
if ( ( V_6 -= V_152 ) == 0 )
return V_275 ;
V_139 += V_152 ;
}
for ( V_71 = 0 ; V_71 < F_23 ( V_2 ) -> V_83 ; V_71 ++ ) {
int V_10 ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + F_96 ( & F_23 ( V_2 ) -> V_76 [ V_71 ] ) ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
T_4 * V_75 = & F_23 ( V_2 ) -> V_76 [ V_71 ] ;
if ( V_152 > V_6 )
V_152 = V_6 ;
F_236 ( & V_244 [ V_275 ] , F_94 ( V_75 ) , V_152 ,
V_75 -> V_110 + V_139 - V_150 ) ;
V_275 ++ ;
if ( ! ( V_6 -= V_152 ) )
return V_275 ;
V_139 += V_152 ;
}
V_150 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_68 ( V_150 > V_139 + V_6 ) ;
V_10 = V_150 + V_151 -> V_6 ;
if ( ( V_152 = V_10 - V_139 ) > 0 ) {
if ( V_152 > V_6 )
V_152 = V_6 ;
V_275 += F_234 ( V_151 , V_244 + V_275 , V_139 - V_150 ,
V_152 ) ;
if ( ( V_6 -= V_152 ) == 0 )
return V_275 ;
V_139 += V_152 ;
}
V_150 = V_10 ;
}
F_118 ( V_6 ) ;
return V_275 ;
}
int F_237 ( struct V_1 * V_2 , struct V_274 * V_244 ,
int V_139 , int V_6 )
{
return F_234 ( V_2 , V_244 , V_139 , V_6 ) ;
}
int F_238 ( struct V_1 * V_2 , struct V_274 * V_244 , int V_139 , int V_6 )
{
int V_276 = F_234 ( V_2 , V_244 , V_139 , V_6 ) ;
F_239 ( & V_244 [ V_276 - 1 ] ) ;
return V_276 ;
}
int F_240 ( struct V_1 * V_2 , int V_277 , struct V_1 * * V_278 )
{
int V_279 ;
int V_275 ;
struct V_1 * V_44 , * * V_280 ;
if ( ( F_121 ( V_2 ) || F_23 ( V_2 ) -> V_83 ) &&
F_140 ( V_2 , F_241 ( V_2 ) - F_113 ( V_2 ) ) == NULL )
return - V_109 ;
if ( ! F_116 ( V_2 ) ) {
if ( F_127 ( V_2 ) < V_277 &&
F_117 ( V_2 , 0 , V_277 - F_127 ( V_2 ) + 128 , V_52 ) )
return - V_109 ;
* V_278 = V_2 ;
return 1 ;
}
V_275 = 1 ;
V_280 = & F_23 ( V_2 ) -> V_78 ;
V_279 = 0 ;
while ( ( V_44 = * V_280 ) != NULL ) {
int V_126 = 0 ;
if ( F_119 ( V_44 ) )
V_279 = 1 ;
if ( V_44 -> V_98 == NULL && V_277 ) {
if ( F_23 ( V_44 ) -> V_83 ||
F_116 ( V_44 ) ||
F_127 ( V_44 ) < V_277 )
V_126 = V_277 + 128 ;
}
if ( V_279 ||
F_121 ( V_44 ) ||
V_126 ||
F_23 ( V_44 ) -> V_83 ||
F_116 ( V_44 ) ) {
struct V_1 * V_45 ;
if ( V_126 == 0 )
V_45 = F_108 ( V_44 , V_52 ) ;
else
V_45 = F_125 ( V_44 ,
F_86 ( V_44 ) ,
V_126 ,
V_52 ) ;
if ( F_42 ( V_45 == NULL ) )
return - V_109 ;
if ( V_44 -> V_101 )
F_242 ( V_45 , V_44 -> V_101 ) ;
V_45 -> V_98 = V_44 -> V_98 ;
* V_280 = V_45 ;
F_76 ( V_44 ) ;
V_44 = V_45 ;
}
V_275 ++ ;
* V_278 = V_44 ;
V_280 = & V_44 -> V_98 ;
}
return V_275 ;
}
static void F_243 ( struct V_1 * V_2 )
{
struct V_158 * V_101 = V_2 -> V_101 ;
F_244 ( V_2 -> V_27 , & V_101 -> V_281 ) ;
}
int F_245 ( struct V_158 * V_101 , struct V_1 * V_2 )
{
if ( F_62 ( & V_101 -> V_281 ) + V_2 -> V_27 >=
( unsigned int ) V_101 -> V_282 )
return - V_109 ;
F_246 ( V_2 ) ;
V_2 -> V_101 = V_101 ;
V_2 -> V_92 = F_243 ;
F_209 ( V_2 -> V_27 , & V_101 -> V_281 ) ;
F_247 ( V_2 ) ;
F_184 ( & V_101 -> V_283 , V_2 ) ;
if ( ! F_248 ( V_101 , V_284 ) )
V_101 -> V_285 ( V_101 ) ;
return 0 ;
}
struct V_1 * F_249 ( struct V_158 * V_101 )
{
struct V_194 * V_286 = & V_101 -> V_283 ;
struct V_1 * V_2 , * V_287 ;
unsigned long V_15 ;
int V_135 = 0 ;
F_176 ( & V_286 -> V_196 , V_15 ) ;
V_2 = F_177 ( V_286 ) ;
if ( V_2 && ( V_287 = F_250 ( V_286 ) ) )
V_135 = F_251 ( V_287 ) -> V_288 . V_289 ;
F_178 ( & V_286 -> V_196 , V_15 ) ;
V_101 -> V_290 = V_135 ;
if ( V_135 )
V_101 -> V_291 ( V_101 ) ;
return V_2 ;
}
struct V_1 * F_252 ( struct V_1 * V_2 )
{
struct V_158 * V_101 = V_2 -> V_101 ;
struct V_1 * V_147 ;
if ( ! V_101 || ! F_253 ( & V_101 -> V_292 ) )
return NULL ;
V_147 = F_101 ( V_2 , V_52 ) ;
if ( ! V_147 ) {
F_254 ( V_101 ) ;
return NULL ;
}
V_147 -> V_101 = V_101 ;
V_147 -> V_92 = V_293 ;
return V_147 ;
}
static void F_255 ( struct V_1 * V_2 ,
struct V_158 * V_101 ,
int V_294 )
{
struct V_295 * V_296 ;
int V_135 ;
V_296 = F_251 ( V_2 ) ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_288 . V_289 = V_297 ;
V_296 -> V_288 . V_298 = V_299 ;
V_296 -> V_288 . V_300 = V_294 ;
if ( V_101 -> V_301 & V_302 ) {
V_296 -> V_288 . V_303 = F_23 ( V_2 ) -> V_304 ;
if ( V_101 -> V_305 == V_306 )
V_296 -> V_288 . V_303 -= V_101 -> V_307 ;
}
V_135 = F_245 ( V_101 , V_2 ) ;
if ( V_135 )
F_76 ( V_2 ) ;
}
static bool F_256 ( struct V_158 * V_101 , bool V_308 )
{
bool V_171 ;
if ( F_74 ( V_309 || V_308 ) )
return true ;
F_257 ( & V_101 -> V_310 ) ;
V_171 = V_101 -> V_311 && V_101 -> V_311 -> V_312 &&
F_258 ( V_101 -> V_311 -> V_312 , & V_313 , V_314 ) ;
F_259 ( & V_101 -> V_310 ) ;
return V_171 ;
}
void F_260 ( struct V_1 * V_2 ,
struct V_315 * V_316 )
{
struct V_158 * V_101 = V_2 -> V_101 ;
if ( ! F_256 ( V_101 , false ) )
return;
F_261 ( V_101 ) ;
* F_262 ( V_2 ) = * V_316 ;
F_255 ( V_2 , V_101 , V_317 ) ;
F_254 ( V_101 ) ;
}
void F_263 ( struct V_1 * V_318 ,
struct V_315 * V_316 ,
struct V_158 * V_101 , int V_294 )
{
struct V_1 * V_2 ;
bool V_308 ;
if ( ! V_101 )
return;
V_308 = V_101 -> V_301 & V_319 ;
if ( ! F_256 ( V_101 , V_308 ) )
return;
if ( V_308 )
V_2 = F_264 ( 0 , V_52 ) ;
else
V_2 = F_101 ( V_318 , V_52 ) ;
if ( ! V_2 )
return;
if ( V_308 ) {
F_23 ( V_2 ) -> V_84 = F_23 ( V_318 ) -> V_84 ;
F_23 ( V_2 ) -> V_304 = F_23 ( V_318 ) -> V_304 ;
}
if ( V_316 )
* F_262 ( V_2 ) = * V_316 ;
else
V_2 -> V_320 = F_265 () ;
F_255 ( V_2 , V_101 , V_294 ) ;
}
void F_266 ( struct V_1 * V_318 ,
struct V_315 * V_316 )
{
return F_263 ( V_318 , V_316 , V_318 -> V_101 ,
V_317 ) ;
}
void F_267 ( struct V_1 * V_2 , bool V_321 )
{
struct V_158 * V_101 = V_2 -> V_101 ;
struct V_295 * V_296 ;
int V_135 ;
V_2 -> V_322 = 1 ;
V_2 -> V_323 = V_321 ;
V_296 = F_251 ( V_2 ) ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_296 -> V_288 . V_289 = V_297 ;
V_296 -> V_288 . V_298 = V_324 ;
F_261 ( V_101 ) ;
V_135 = F_245 ( V_101 , V_2 ) ;
if ( V_135 )
F_76 ( V_2 ) ;
F_254 ( V_101 ) ;
}
bool F_268 ( struct V_1 * V_2 , T_12 V_150 , T_12 V_73 )
{
if ( F_42 ( V_150 > F_113 ( V_2 ) ) ||
F_42 ( ( int ) V_150 + V_73 > F_113 ( V_2 ) - 2 ) ) {
F_224 ( L_6 ,
V_150 , V_73 , F_113 ( V_2 ) ) ;
return false ;
}
V_2 -> V_111 = V_112 ;
V_2 -> V_113 = F_86 ( V_2 ) + V_150 ;
V_2 -> V_192 = V_73 ;
F_269 ( V_2 , V_150 ) ;
return true ;
}
static int F_270 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_325 )
{
if ( F_113 ( V_2 ) >= V_6 )
return 0 ;
if ( V_325 > V_2 -> V_6 )
V_325 = V_2 -> V_6 ;
if ( F_140 ( V_2 , V_325 - F_113 ( V_2 ) ) == NULL )
return - V_109 ;
if ( F_113 ( V_2 ) < V_6 )
return - V_326 ;
return 0 ;
}
static int F_271 ( struct V_1 * V_2 , bool V_327 )
{
unsigned int V_73 ;
bool V_328 ;
V_193 * V_179 ;
int V_135 ;
V_328 = false ;
V_135 = F_270 ( V_2 ,
sizeof( struct V_329 ) ,
V_330 ) ;
if ( V_135 < 0 )
goto V_23;
if ( F_272 ( V_2 ) -> V_331 & F_273 ( V_332 | V_333 ) )
V_328 = true ;
V_73 = F_274 ( V_2 ) ;
V_135 = - V_326 ;
if ( V_328 )
goto V_23;
V_179 = F_275 ( V_2 , F_272 ( V_2 ) -> V_334 , V_73 ) ;
if ( F_276 ( V_179 ) )
return F_277 ( V_179 ) ;
if ( V_327 )
* V_179 = ~ F_278 ( F_272 ( V_2 ) -> V_335 ,
F_272 ( V_2 ) -> V_336 ,
V_2 -> V_6 - V_73 ,
F_272 ( V_2 ) -> V_334 , 0 ) ;
V_135 = 0 ;
V_23:
return V_135 ;
}
static int F_279 ( struct V_1 * V_2 , bool V_327 )
{
int V_135 ;
T_3 V_337 ;
unsigned int V_73 ;
unsigned int V_6 ;
bool V_328 ;
bool V_142 ;
V_193 * V_179 ;
V_328 = false ;
V_142 = false ;
V_73 = sizeof( struct V_338 ) ;
V_135 = F_270 ( V_2 , V_73 , V_339 ) ;
if ( V_135 < 0 )
goto V_23;
V_337 = F_280 ( V_2 ) -> V_337 ;
V_6 = sizeof( struct V_338 ) + F_281 ( F_280 ( V_2 ) -> V_340 ) ;
while ( V_73 <= V_6 && ! V_142 ) {
switch ( V_337 ) {
case V_341 :
case V_342 :
case V_343 : {
struct V_344 * V_345 ;
V_135 = F_270 ( V_2 ,
V_73 +
sizeof( struct V_344 ) ,
V_339 ) ;
if ( V_135 < 0 )
goto V_23;
V_345 = F_282 ( struct V_344 , V_2 , V_73 ) ;
V_337 = V_345 -> V_337 ;
V_73 += F_283 ( V_345 ) ;
break;
}
case V_346 : {
struct V_347 * V_345 ;
V_135 = F_270 ( V_2 ,
V_73 +
sizeof( struct V_347 ) ,
V_339 ) ;
if ( V_135 < 0 )
goto V_23;
V_345 = F_282 ( struct V_347 , V_2 , V_73 ) ;
V_337 = V_345 -> V_337 ;
V_73 += F_284 ( V_345 ) ;
break;
}
case V_348 : {
struct V_349 * V_345 ;
V_135 = F_270 ( V_2 ,
V_73 +
sizeof( struct V_349 ) ,
V_339 ) ;
if ( V_135 < 0 )
goto V_23;
V_345 = F_282 ( struct V_349 , V_2 , V_73 ) ;
if ( V_345 -> V_331 & F_273 ( V_350 | V_351 ) )
V_328 = true ;
V_337 = V_345 -> V_337 ;
V_73 += sizeof( struct V_349 ) ;
break;
}
default:
V_142 = true ;
break;
}
}
V_135 = - V_326 ;
if ( ! V_142 || V_328 )
goto V_23;
V_179 = F_275 ( V_2 , V_337 , V_73 ) ;
if ( F_276 ( V_179 ) )
return F_277 ( V_179 ) ;
if ( V_327 )
* V_179 = ~ F_285 ( & F_280 ( V_2 ) -> V_335 ,
& F_280 ( V_2 ) -> V_336 ,
V_2 -> V_6 - V_73 , V_337 , 0 ) ;
V_135 = 0 ;
V_23:
return V_135 ;
}
int F_286 ( struct V_1 * V_2 , bool V_327 )
{
int V_135 ;
switch ( V_2 -> V_334 ) {
case F_273 ( V_352 ) :
V_135 = F_271 ( V_2 , V_327 ) ;
break;
case F_273 ( V_353 ) :
V_135 = F_279 ( V_2 , V_327 ) ;
break;
default:
V_135 = - V_326 ;
break;
}
return V_135 ;
}
static struct V_1 * F_287 ( struct V_1 * V_2 ,
unsigned int V_354 )
{
struct V_1 * V_355 ;
unsigned int V_6 = F_288 ( V_2 ) + V_354 ;
int V_171 ;
if ( V_2 -> V_6 < V_6 )
return NULL ;
else if ( V_2 -> V_6 == V_6 )
return V_2 ;
V_355 = F_101 ( V_2 , V_52 ) ;
if ( ! V_355 )
return NULL ;
V_171 = F_289 ( V_355 , V_6 ) ;
if ( V_171 ) {
F_76 ( V_355 ) ;
return NULL ;
}
return V_355 ;
}
struct V_1 * F_290 ( struct V_1 * V_2 ,
unsigned int V_354 ,
V_193 (* F_291)( struct V_1 * V_2 ) )
{
struct V_1 * V_355 ;
unsigned int V_139 = F_288 ( V_2 ) ;
V_193 V_171 ;
V_355 = F_287 ( V_2 , V_354 ) ;
if ( ! V_355 )
goto V_135;
if ( ! F_292 ( V_355 , V_139 ) )
goto V_135;
F_230 ( V_355 , V_139 ) ;
V_171 = F_291 ( V_355 ) ;
F_216 ( V_355 , V_139 ) ;
if ( V_171 )
goto V_135;
return V_355 ;
V_135:
if ( V_355 && V_355 != V_2 )
F_76 ( V_355 ) ;
return NULL ;
}
void F_293 ( const struct V_1 * V_2 )
{
F_224 ( L_7 ,
V_2 -> V_11 -> V_12 ) ;
}
void F_294 ( struct V_1 * V_2 , bool V_356 )
{
if ( V_356 ) {
F_64 ( V_2 ) ;
F_27 ( V_25 , V_2 ) ;
} else {
F_75 ( V_2 ) ;
}
}
bool F_295 ( struct V_1 * V_149 , struct V_1 * V_178 ,
bool * V_357 , int * V_262 )
{
int V_71 , V_128 , V_6 = V_178 -> V_6 ;
* V_357 = false ;
if ( F_121 ( V_149 ) )
return false ;
if ( V_6 <= F_127 ( V_149 ) ) {
if ( V_6 )
F_118 ( F_111 ( V_178 , 0 , F_110 ( V_149 , V_6 ) , V_6 ) ) ;
* V_262 = 0 ;
return true ;
}
if ( F_116 ( V_149 ) || F_116 ( V_178 ) )
return false ;
if ( F_113 ( V_178 ) != 0 ) {
struct V_72 * V_72 ;
unsigned int V_139 ;
if ( F_23 ( V_149 ) -> V_83 +
F_23 ( V_178 ) -> V_83 >= V_166 )
return false ;
if ( F_156 ( V_178 ) )
return false ;
V_128 = V_178 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
V_72 = F_32 ( V_178 -> V_7 ) ;
V_139 = V_178 -> V_8 - ( unsigned char * ) F_95 ( V_72 ) ;
F_47 ( V_149 , F_23 ( V_149 ) -> V_83 ,
V_72 , V_139 , F_113 ( V_178 ) ) ;
* V_357 = true ;
} else {
if ( F_23 ( V_149 ) -> V_83 +
F_23 ( V_178 ) -> V_83 > V_166 )
return false ;
V_128 = V_178 -> V_27 - F_21 ( F_109 ( V_178 ) ) ;
}
F_296 ( V_128 < V_6 ) ;
memcpy ( F_23 ( V_149 ) -> V_76 + F_23 ( V_149 ) -> V_83 ,
F_23 ( V_178 ) -> V_76 ,
F_23 ( V_178 ) -> V_83 * sizeof( T_4 ) ) ;
F_23 ( V_149 ) -> V_83 += F_23 ( V_178 ) -> V_83 ;
if ( ! F_121 ( V_178 ) )
F_23 ( V_178 ) -> V_83 = 0 ;
for ( V_71 = 0 ; V_71 < F_23 ( V_178 ) -> V_83 ; V_71 ++ )
F_115 ( V_178 , V_71 ) ;
V_149 -> V_27 += V_128 ;
V_149 -> V_6 += V_6 ;
V_149 -> V_74 += V_6 ;
* V_262 = V_128 ;
return true ;
}
void F_297 ( struct V_1 * V_2 , bool V_358 )
{
V_2 -> V_320 . V_359 = 0 ;
V_2 -> V_360 = V_361 ;
V_2 -> V_362 = 0 ;
V_2 -> V_363 = 0 ;
F_65 ( V_2 ) ;
F_298 ( V_2 ) ;
F_299 ( V_2 ) ;
F_300 ( V_2 ) ;
F_301 ( V_2 ) ;
if ( ! V_358 )
return;
F_246 ( V_2 ) ;
V_2 -> V_364 = 0 ;
}
unsigned int F_302 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_23 ( V_2 ) ;
unsigned int V_365 = 0 ;
if ( V_2 -> V_366 ) {
V_365 = F_303 ( V_2 ) -
F_304 ( V_2 ) ;
if ( F_74 ( V_33 -> V_122 & ( V_367 | V_368 ) ) )
V_365 += F_305 ( V_2 ) ;
} else if ( F_74 ( V_33 -> V_122 & ( V_367 | V_368 ) ) ) {
V_365 = F_306 ( V_2 ) ;
}
return V_365 + V_33 -> V_120 ;
}
static struct V_1 * F_307 ( struct V_1 * V_2 )
{
if ( F_308 ( V_2 , F_86 ( V_2 ) ) < 0 ) {
F_76 ( V_2 ) ;
return NULL ;
}
memmove ( V_2 -> V_8 - V_369 , V_2 -> V_8 - V_370 , 2 * V_371 ) ;
V_2 -> V_29 += V_372 ;
return V_2 ;
}
struct V_1 * F_309 ( struct V_1 * V_2 )
{
struct V_373 * V_374 ;
T_12 V_375 ;
if ( F_42 ( F_310 ( V_2 ) ) ) {
return V_2 ;
}
V_2 = F_311 ( V_2 , V_52 ) ;
if ( F_42 ( ! V_2 ) )
goto V_376;
if ( F_42 ( ! F_292 ( V_2 , V_372 ) ) )
goto V_376;
V_374 = (struct V_373 * ) V_2 -> V_8 ;
V_375 = F_281 ( V_374 -> V_377 ) ;
F_312 ( V_2 , V_2 -> V_334 , V_375 ) ;
F_211 ( V_2 , V_372 ) ;
F_313 ( V_2 , V_374 ) ;
V_2 = F_307 ( V_2 ) ;
if ( F_42 ( ! V_2 ) )
goto V_376;
F_314 ( V_2 ) ;
F_315 ( V_2 ) ;
F_222 ( V_2 ) ;
return V_2 ;
V_376:
F_76 ( V_2 ) ;
return NULL ;
}
int F_316 ( struct V_1 * V_2 , int V_378 )
{
if ( ! F_292 ( V_2 , V_378 ) )
return - V_109 ;
if ( ! F_121 ( V_2 ) || F_317 ( V_2 , V_378 ) )
return 0 ;
return F_117 ( V_2 , 0 , 0 , V_52 ) ;
}
static int F_318 ( struct V_1 * V_2 , T_12 * V_375 )
{
struct V_373 * V_374 ;
unsigned int V_139 = V_2 -> V_8 - F_214 ( V_2 ) ;
int V_135 ;
F_216 ( V_2 , V_139 ) ;
V_135 = F_316 ( V_2 , V_370 ) ;
if ( F_42 ( V_135 ) )
goto V_379;
F_212 ( V_2 , V_2 -> V_8 + ( 2 * V_371 ) , V_372 ) ;
V_374 = (struct V_373 * ) ( V_2 -> V_8 + V_369 ) ;
* V_375 = F_281 ( V_374 -> V_377 ) ;
memmove ( V_2 -> V_8 + V_372 , V_2 -> V_8 , 2 * V_371 ) ;
F_230 ( V_2 , V_372 ) ;
F_313 ( V_2 , V_374 ) ;
V_2 -> V_29 += V_372 ;
if ( F_319 ( V_2 ) < V_369 )
F_320 ( V_2 , V_369 ) ;
F_222 ( V_2 ) ;
V_379:
F_230 ( V_2 , V_139 ) ;
return V_135 ;
}
int F_321 ( struct V_1 * V_2 )
{
T_12 V_375 ;
T_10 V_380 ;
int V_135 ;
if ( F_74 ( F_310 ( V_2 ) ) ) {
V_2 -> V_375 = 0 ;
} else {
if ( F_42 ( ( V_2 -> V_334 != F_273 ( V_381 ) &&
V_2 -> V_334 != F_273 ( V_382 ) ) ||
V_2 -> V_6 < V_370 ) )
return 0 ;
V_135 = F_318 ( V_2 , & V_375 ) ;
if ( V_135 )
return V_135 ;
}
if ( F_74 ( ( V_2 -> V_334 != F_273 ( V_381 ) &&
V_2 -> V_334 != F_273 ( V_382 ) ) ||
V_2 -> V_6 < V_370 ) )
return 0 ;
V_380 = V_2 -> V_334 ;
V_135 = F_318 ( V_2 , & V_375 ) ;
if ( F_42 ( V_135 ) )
return V_135 ;
F_312 ( V_2 , V_380 , V_375 ) ;
return 0 ;
}
int F_322 ( struct V_1 * V_2 , T_10 V_380 , T_12 V_375 )
{
if ( F_310 ( V_2 ) ) {
unsigned int V_139 = V_2 -> V_8 - F_214 ( V_2 ) ;
int V_135 ;
F_216 ( V_2 , V_139 ) ;
V_135 = F_323 ( V_2 , V_2 -> V_380 ,
F_324 ( V_2 ) ) ;
if ( V_135 )
return V_135 ;
V_2 -> V_334 = V_2 -> V_380 ;
V_2 -> V_102 += V_372 ;
F_230 ( V_2 , V_139 ) ;
if ( V_2 -> V_111 == V_383 )
V_2 -> V_179 = F_325 ( V_2 -> V_179 , F_326 ( V_2 -> V_8
+ ( 2 * V_371 ) , V_372 , 0 ) ) ;
}
F_312 ( V_2 , V_380 , V_375 ) ;
return 0 ;
}
struct V_1 * F_327 ( unsigned long V_384 ,
unsigned long V_74 ,
int V_385 ,
int * V_386 ,
T_2 V_24 )
{
int V_387 = ( V_74 + ( V_62 - 1 ) ) >> V_388 ;
unsigned long V_389 ;
struct V_1 * V_2 ;
struct V_72 * V_72 ;
T_2 V_390 ;
int V_71 ;
* V_386 = - V_234 ;
if ( V_387 > V_166 )
return NULL ;
V_390 = V_24 ;
if ( V_390 & V_63 )
V_390 |= V_391 ;
* V_386 = - V_392 ;
V_2 = F_264 ( V_384 , V_390 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_27 += V_387 << V_388 ;
for ( V_71 = 0 ; V_387 > 0 ; V_71 ++ ) {
int V_393 = V_385 ;
while ( V_393 ) {
if ( V_387 >= 1 << V_393 ) {
V_72 = F_328 ( ( V_24 & ~ V_63 ) |
V_394 |
V_22 |
V_395 ,
V_393 ) ;
if ( V_72 )
goto V_396;
V_393 = 1 ;
V_385 = 0 ;
}
V_393 -- ;
}
V_72 = F_90 ( V_24 ) ;
if ( ! V_72 )
goto V_397;
V_396:
V_389 = F_148 (unsigned long, data_len,
PAGE_SIZE << order) ;
F_47 ( V_2 , V_71 , V_72 , 0 , V_389 ) ;
V_74 -= V_389 ;
V_387 -= 1 << V_393 ;
}
return V_2 ;
V_397:
F_76 ( V_2 ) ;
return NULL ;
}
