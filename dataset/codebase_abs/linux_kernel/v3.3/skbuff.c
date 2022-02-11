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
F_7 ( V_10 L_1
L_2 ,
V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_3 ) ;
F_8 () ;
}
static void F_9 ( struct V_6 * V_7 , int V_8 , void * V_9 )
{
F_7 ( V_10 L_4
L_2 ,
V_9 , V_7 -> V_11 , V_8 , V_7 -> V_12 , V_7 -> V_13 ,
( unsigned long ) V_7 -> V_14 , ( unsigned long ) V_7 -> V_15 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : L_3 ) ;
F_8 () ;
}
struct V_6 * F_10 ( unsigned int V_18 , T_1 V_19 ,
int V_20 , int V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_6 * V_7 ;
T_2 * V_13 ;
V_23 = V_20 ? V_26 : V_27 ;
V_7 = F_11 ( V_23 , V_19 & ~ V_28 , V_21 ) ;
if ( ! V_7 )
goto V_29;
F_12 ( V_7 ) ;
V_18 = F_13 ( V_18 ) ;
V_18 += F_13 ( sizeof( struct V_24 ) ) ;
V_13 = F_14 ( V_18 , V_19 , V_21 ) ;
if ( ! V_13 )
goto V_30;
V_18 = F_15 ( F_16 ( V_13 ) ) ;
F_12 ( V_13 + V_18 ) ;
memset ( V_7 , 0 , F_17 ( struct V_6 , V_14 ) ) ;
V_7 -> V_31 = F_18 ( V_18 ) ;
F_19 ( & V_7 -> V_32 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_20 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_18 ;
#ifdef F_21
V_7 -> V_33 = ~ 0U ;
#endif
V_25 = F_22 ( V_7 ) ;
memset ( V_25 , 0 , F_17 ( struct V_24 , V_34 ) ) ;
F_19 ( & V_25 -> V_34 , 1 ) ;
F_23 ( V_25 -> V_35 ) ;
if ( V_20 ) {
struct V_6 * V_36 = V_7 + 1 ;
T_3 * V_37 = ( T_3 * ) ( V_36 + 1 ) ;
F_24 ( V_36 , V_38 ) ;
F_24 ( V_36 , V_39 ) ;
V_7 -> V_20 = V_40 ;
F_19 ( V_37 , 1 ) ;
V_36 -> V_20 = V_41 ;
}
V_29:
return V_7 ;
V_30:
F_25 ( V_23 , V_7 ) ;
V_7 = NULL ;
goto V_29;
}
struct V_6 * F_26 ( void * V_13 )
{
struct V_24 * V_25 ;
struct V_6 * V_7 ;
unsigned int V_18 ;
V_7 = F_27 ( V_27 , V_42 ) ;
if ( ! V_7 )
return NULL ;
V_18 = F_16 ( V_13 ) - F_13 ( sizeof( struct V_24 ) ) ;
memset ( V_7 , 0 , F_17 ( struct V_6 , V_14 ) ) ;
V_7 -> V_31 = F_18 ( V_18 ) ;
F_19 ( & V_7 -> V_32 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_20 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_18 ;
#ifdef F_21
V_7 -> V_33 = ~ 0U ;
#endif
V_25 = F_22 ( V_7 ) ;
memset ( V_25 , 0 , F_17 ( struct V_24 , V_34 ) ) ;
F_19 ( & V_25 -> V_34 , 1 ) ;
F_23 ( V_25 -> V_35 ) ;
return V_7 ;
}
struct V_6 * F_28 ( struct V_43 * V_16 ,
unsigned int V_44 , T_1 V_19 )
{
struct V_6 * V_7 ;
V_7 = F_10 ( V_44 + V_45 , V_19 , 0 , V_46 ) ;
if ( F_29 ( V_7 ) ) {
F_30 ( V_7 , V_45 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_31 ( struct V_6 * V_7 , int V_47 , struct V_5 * V_5 , int V_48 ,
int V_18 )
{
F_32 ( V_7 , V_47 , V_5 , V_48 , V_18 ) ;
V_7 -> V_11 += V_18 ;
V_7 -> V_49 += V_18 ;
V_7 -> V_31 += V_18 ;
}
struct V_6 * F_33 ( unsigned int V_44 )
{
return F_34 ( V_44 , V_42 ) ;
}
static void F_35 ( struct V_6 * * V_50 )
{
struct V_6 * V_51 = * V_50 ;
* V_50 = NULL ;
do {
struct V_6 * V_52 = V_51 ;
V_51 = V_51 -> V_53 ;
F_36 ( V_52 ) ;
} while ( V_51 );
}
static inline void F_37 ( struct V_6 * V_7 )
{
F_35 ( & F_22 ( V_7 ) -> V_54 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_6 * V_51 ;
F_39 (skb, list)
F_40 ( V_51 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_55 ||
! F_42 ( V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ,
& F_22 ( V_7 ) -> V_34 ) ) {
if ( F_22 ( V_7 ) -> V_58 ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ )
F_43 ( V_7 , V_47 ) ;
}
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
struct V_61 * V_62 ;
V_62 = F_22 ( V_7 ) -> V_35 ;
if ( V_62 -> V_63 )
V_62 -> V_63 ( V_62 ) ;
}
if ( F_44 ( V_7 ) )
F_37 ( V_7 ) ;
F_45 ( V_7 -> V_12 ) ;
}
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_6 * V_64 ;
T_3 * V_37 ;
switch ( V_7 -> V_20 ) {
case V_41 :
F_25 ( V_27 , V_7 ) ;
break;
case V_40 :
V_37 = ( T_3 * ) ( V_7 + 2 ) ;
if ( F_47 ( V_37 ) )
F_25 ( V_26 , V_7 ) ;
break;
case V_65 :
V_37 = ( T_3 * ) ( V_7 + 1 ) ;
V_64 = V_7 - 1 ;
V_7 -> V_20 = V_41 ;
if ( F_47 ( V_37 ) )
F_25 ( V_26 , V_64 ) ;
break;
}
}
static void F_48 ( struct V_6 * V_7 )
{
F_49 ( V_7 ) ;
#ifdef F_50
F_51 ( V_7 -> V_66 ) ;
#endif
if ( V_7 -> V_67 ) {
F_52 ( F_53 () ) ;
V_7 -> V_67 ( V_7 ) ;
}
#if F_54 ( V_68 )
F_55 ( V_7 -> V_69 ) ;
#endif
#ifdef F_56
F_57 ( V_7 -> V_70 ) ;
#endif
#ifdef F_58
F_59 ( V_7 -> V_71 ) ;
#endif
#ifdef F_60
V_7 -> V_72 = 0 ;
#ifdef F_61
V_7 -> V_73 = 0 ;
#endif
#endif
}
static void F_62 ( struct V_6 * V_7 )
{
F_48 ( V_7 ) ;
F_41 ( V_7 ) ;
}
void F_63 ( struct V_6 * V_7 )
{
F_62 ( V_7 ) ;
F_46 ( V_7 ) ;
}
void F_36 ( struct V_6 * V_7 )
{
if ( F_64 ( ! V_7 ) )
return;
if ( F_29 ( F_65 ( & V_7 -> V_32 ) == 1 ) )
F_66 () ;
else if ( F_29 ( ! F_47 ( & V_7 -> V_32 ) ) )
return;
F_67 ( V_7 , F_68 ( 0 ) ) ;
F_63 ( V_7 ) ;
}
void F_69 ( struct V_6 * V_7 )
{
if ( F_64 ( ! V_7 ) )
return;
if ( F_29 ( F_65 ( & V_7 -> V_32 ) == 1 ) )
F_66 () ;
else if ( F_29 ( ! F_47 ( & V_7 -> V_32 ) ) )
return;
F_70 ( V_7 ) ;
F_63 ( V_7 ) ;
}
void F_71 ( struct V_6 * V_7 )
{
struct V_24 * V_25 ;
F_48 ( V_7 ) ;
V_25 = F_22 ( V_7 ) ;
memset ( V_25 , 0 , F_17 ( struct V_24 , V_34 ) ) ;
F_19 ( & V_25 -> V_34 , 1 ) ;
memset ( V_7 , 0 , F_17 ( struct V_6 , V_14 ) ) ;
V_7 -> V_13 = V_7 -> V_12 + V_45 ;
F_20 ( V_7 ) ;
}
bool F_72 ( struct V_6 * V_7 , int V_74 )
{
if ( ! F_73 ( V_7 , V_74 ) )
return false ;
F_71 ( V_7 ) ;
return true ;
}
static void F_74 ( struct V_6 * V_75 , const struct V_6 * V_76 )
{
V_75 -> V_77 = V_76 -> V_77 ;
V_75 -> V_16 = V_76 -> V_16 ;
V_75 -> V_78 = V_76 -> V_78 ;
V_75 -> V_79 = V_76 -> V_79 ;
V_75 -> V_33 = V_76 -> V_33 ;
F_75 ( V_75 , V_76 ) ;
V_75 -> V_80 = V_76 -> V_80 ;
V_75 -> V_81 = V_76 -> V_81 ;
V_75 -> V_82 = V_76 -> V_82 ;
#ifdef F_50
V_75 -> V_66 = F_76 ( V_76 -> V_66 ) ;
#endif
memcpy ( V_75 -> V_83 , V_76 -> V_83 , sizeof( V_76 -> V_83 ) ) ;
V_75 -> V_84 = V_76 -> V_84 ;
V_75 -> V_85 = V_76 -> V_85 ;
V_75 -> V_86 = V_76 -> V_86 ;
V_75 -> V_87 = V_76 -> V_87 ;
F_77 ( V_75 , V_76 ) ;
V_75 -> V_88 = V_76 -> V_88 ;
#if F_54 ( V_89 )
V_75 -> V_90 = V_76 -> V_90 ;
#endif
V_75 -> V_91 = V_76 -> V_91 ;
V_75 -> V_92 = V_76 -> V_92 ;
V_75 -> V_93 = V_76 -> V_93 ;
F_78 ( V_75 , V_76 ) ;
#if F_54 ( V_94 )
V_75 -> V_95 = V_76 -> V_95 ;
#endif
#ifdef F_60
V_75 -> V_72 = V_76 -> V_72 ;
#ifdef F_61
V_75 -> V_73 = V_76 -> V_73 ;
#endif
#endif
V_75 -> V_96 = V_76 -> V_96 ;
F_79 ( V_75 , V_76 ) ;
}
static struct V_6 * F_80 ( struct V_6 * V_97 , struct V_6 * V_7 )
{
#define F_81 ( T_4 ) n->x = skb->x
V_97 -> V_53 = V_97 -> V_98 = NULL ;
V_97 -> V_99 = NULL ;
F_74 ( V_97 , V_7 ) ;
F_81 ( V_11 ) ;
F_81 ( V_49 ) ;
F_81 ( V_100 ) ;
V_97 -> V_101 = V_7 -> V_56 ? F_82 ( V_7 ) : V_7 -> V_101 ;
V_97 -> V_55 = 1 ;
V_97 -> V_56 = 0 ;
V_97 -> V_67 = NULL ;
F_81 ( V_14 ) ;
F_81 ( V_15 ) ;
F_81 ( V_12 ) ;
F_81 ( V_13 ) ;
F_81 ( V_31 ) ;
F_19 ( & V_97 -> V_32 , 1 ) ;
F_83 ( & ( F_22 ( V_7 ) -> V_34 ) ) ;
V_7 -> V_55 = 1 ;
return V_97 ;
#undef F_81
}
struct V_6 * F_84 ( struct V_6 * V_102 , struct V_6 * V_103 )
{
F_62 ( V_102 ) ;
return F_80 ( V_102 , V_103 ) ;
}
int F_85 ( struct V_6 * V_7 , T_1 V_19 )
{
int V_47 ;
int V_104 = F_22 ( V_7 ) -> V_58 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_61 * V_62 = F_22 ( V_7 ) -> V_35 ;
for ( V_47 = 0 ; V_47 < V_104 ; V_47 ++ ) {
T_2 * V_105 ;
T_5 * V_106 = & F_22 ( V_7 ) -> V_107 [ V_47 ] ;
V_5 = F_86 ( V_42 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_53 = (struct V_5 * ) V_12 -> V_108 ;
F_2 ( V_12 ) ;
V_12 = V_53 ;
}
return - V_109 ;
}
V_105 = F_87 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
memcpy ( F_88 ( V_5 ) ,
V_105 + V_106 -> V_110 , F_89 ( V_106 ) ) ;
F_90 ( V_105 ) ;
V_5 -> V_108 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ )
F_43 ( V_7 , V_47 ) ;
V_62 -> V_63 ( V_62 ) ;
for ( V_47 = F_22 ( V_7 ) -> V_58 ; V_47 > 0 ; V_47 -- ) {
F_91 ( V_7 , V_47 - 1 , V_12 , 0 ,
F_22 ( V_7 ) -> V_107 [ V_47 - 1 ] . V_18 ) ;
V_12 = (struct V_5 * ) V_12 -> V_108 ;
}
F_22 ( V_7 ) -> V_59 &= ~ V_60 ;
return 0 ;
}
struct V_6 * F_92 ( struct V_6 * V_7 , T_1 V_19 )
{
struct V_6 * V_97 ;
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_85 ( V_7 , V_19 ) )
return NULL ;
}
V_97 = V_7 + 1 ;
if ( V_7 -> V_20 == V_40 &&
V_97 -> V_20 == V_41 ) {
T_3 * V_37 = ( T_3 * ) ( V_97 + 1 ) ;
V_97 -> V_20 = V_65 ;
F_83 ( V_37 ) ;
} else {
V_97 = F_27 ( V_27 , V_19 ) ;
if ( ! V_97 )
return NULL ;
F_24 ( V_97 , V_38 ) ;
F_24 ( V_97 , V_39 ) ;
V_97 -> V_20 = V_41 ;
}
return F_80 ( V_97 , V_7 ) ;
}
static void F_93 ( struct V_6 * V_75 , const struct V_6 * V_76 )
{
#ifndef F_21
unsigned long V_111 = V_75 -> V_13 - V_76 -> V_13 ;
#endif
F_74 ( V_75 , V_76 ) ;
#ifndef F_21
V_75 -> V_78 += V_111 ;
V_75 -> V_79 += V_111 ;
if ( F_94 ( V_75 ) )
V_75 -> V_33 += V_111 ;
#endif
F_22 ( V_75 ) -> V_112 = F_22 ( V_76 ) -> V_112 ;
F_22 ( V_75 ) -> V_113 = F_22 ( V_76 ) -> V_113 ;
F_22 ( V_75 ) -> V_114 = F_22 ( V_76 ) -> V_114 ;
}
struct V_6 * F_95 ( const struct V_6 * V_7 , T_1 V_19 )
{
int V_115 = F_82 ( V_7 ) ;
unsigned int V_18 = ( F_96 ( V_7 ) - V_7 -> V_12 ) + V_7 -> V_49 ;
struct V_6 * V_97 = F_97 ( V_18 , V_19 ) ;
if ( ! V_97 )
return NULL ;
F_30 ( V_97 , V_115 ) ;
F_98 ( V_97 , V_7 -> V_11 ) ;
if ( F_99 ( V_7 , - V_115 , V_97 -> V_12 , V_115 + V_7 -> V_11 ) )
F_8 () ;
F_93 ( V_97 , V_7 ) ;
return V_97 ;
}
struct V_6 * F_100 ( struct V_6 * V_7 , int V_116 , T_1 V_19 )
{
unsigned int V_18 = F_101 ( V_7 ) + V_116 ;
struct V_6 * V_97 = F_97 ( V_18 , V_19 ) ;
if ( ! V_97 )
goto V_29;
F_30 ( V_97 , V_116 ) ;
F_98 ( V_97 , F_101 ( V_7 ) ) ;
F_102 ( V_7 , V_97 -> V_13 , V_97 -> V_11 ) ;
V_97 -> V_31 += V_7 -> V_49 ;
V_97 -> V_49 = V_7 -> V_49 ;
V_97 -> V_11 = V_7 -> V_11 ;
if ( F_22 ( V_7 ) -> V_58 ) {
int V_47 ;
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_85 ( V_7 , V_19 ) ) {
F_36 ( V_97 ) ;
V_97 = NULL ;
goto V_29;
}
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
F_22 ( V_97 ) -> V_107 [ V_47 ] = F_22 ( V_7 ) -> V_107 [ V_47 ] ;
F_103 ( V_7 , V_47 ) ;
}
F_22 ( V_97 ) -> V_58 = V_47 ;
}
if ( F_44 ( V_7 ) ) {
F_22 ( V_97 ) -> V_54 = F_22 ( V_7 ) -> V_54 ;
F_38 ( V_97 ) ;
}
F_93 ( V_97 , V_7 ) ;
V_29:
return V_97 ;
}
int F_104 ( struct V_6 * V_7 , int V_117 , int V_118 ,
T_1 V_19 )
{
int V_47 ;
T_2 * V_13 ;
int V_18 = V_117 + ( F_96 ( V_7 ) - V_7 -> V_12 ) + V_118 ;
long V_48 ;
bool V_119 ;
F_105 ( V_117 < 0 ) ;
if ( F_106 ( V_7 ) )
F_8 () ;
V_18 = F_13 ( V_18 ) ;
if ( ! V_7 -> V_55 )
V_119 = true ;
else {
int V_120 = V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ;
V_119 = F_65 ( & F_22 ( V_7 ) -> V_34 ) == V_120 ;
}
if ( V_119 &&
V_18 + sizeof( struct V_24 ) <= F_16 ( V_7 -> V_12 ) ) {
memmove ( V_7 -> V_12 + V_18 , F_22 ( V_7 ) ,
F_17 ( struct V_24 ,
V_107 [ F_22 ( V_7 ) -> V_58 ] ) ) ;
memmove ( V_7 -> V_12 + V_117 , V_7 -> V_12 ,
F_107 ( V_7 ) - V_7 -> V_12 ) ;
V_48 = V_117 ;
goto V_121;
}
V_13 = F_108 ( V_18 + sizeof( struct V_24 ) , V_19 ) ;
if ( ! V_13 )
goto V_30;
memcpy ( V_13 + V_117 , V_7 -> V_12 , F_107 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_24 * ) ( V_13 + V_18 ) ,
F_22 ( V_7 ) ,
F_17 ( struct V_24 , V_107 [ F_22 ( V_7 ) -> V_58 ] ) ) ;
if ( V_119 ) {
F_45 ( V_7 -> V_12 ) ;
} else {
if ( F_22 ( V_7 ) -> V_59 & V_60 ) {
if ( F_85 ( V_7 , V_19 ) )
goto V_122;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ )
F_103 ( V_7 , V_47 ) ;
if ( F_44 ( V_7 ) )
F_38 ( V_7 ) ;
F_41 ( V_7 ) ;
}
V_48 = ( V_13 + V_117 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_121:
V_7 -> V_13 += V_48 ;
#ifdef F_21
V_7 -> V_15 = V_18 ;
V_48 = V_117 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_48 ;
V_7 -> V_78 += V_48 ;
V_7 -> V_79 += V_48 ;
if ( F_94 ( V_7 ) )
V_7 -> V_33 += V_48 ;
if ( V_7 -> V_87 == V_123 )
V_7 -> V_124 += V_117 ;
V_7 -> V_55 = 0 ;
V_7 -> V_101 = 0 ;
V_7 -> V_56 = 0 ;
F_19 ( & F_22 ( V_7 ) -> V_34 , 1 ) ;
return 0 ;
V_122:
F_45 ( V_13 ) ;
V_30:
return - V_109 ;
}
struct V_6 * F_109 ( struct V_6 * V_7 , unsigned int V_116 )
{
struct V_6 * V_125 ;
int V_120 = V_116 - F_82 ( V_7 ) ;
if ( V_120 <= 0 )
V_125 = F_110 ( V_7 , V_42 ) ;
else {
V_125 = F_92 ( V_7 , V_42 ) ;
if ( V_125 && F_104 ( V_125 , F_13 ( V_120 ) , 0 ,
V_42 ) ) {
F_36 ( V_125 ) ;
V_125 = NULL ;
}
}
return V_125 ;
}
struct V_6 * F_111 ( const struct V_6 * V_7 ,
int V_126 , int V_127 ,
T_1 V_19 )
{
struct V_6 * V_97 = F_97 ( V_126 + V_7 -> V_11 + V_127 ,
V_19 ) ;
int V_128 = F_82 ( V_7 ) ;
int V_129 , V_130 ;
int V_48 ;
if ( ! V_97 )
return NULL ;
F_30 ( V_97 , V_126 ) ;
F_98 ( V_97 , V_7 -> V_11 ) ;
V_129 = V_128 ;
V_130 = 0 ;
if ( V_126 <= V_129 )
V_129 = V_126 ;
else
V_130 = V_126 - V_129 ;
if ( F_99 ( V_7 , - V_129 , V_97 -> V_12 + V_130 ,
V_7 -> V_11 + V_129 ) )
F_8 () ;
F_93 ( V_97 , V_7 ) ;
V_48 = V_126 - V_128 ;
if ( V_97 -> V_87 == V_123 )
V_97 -> V_124 += V_48 ;
#ifdef F_21
V_97 -> V_78 += V_48 ;
V_97 -> V_79 += V_48 ;
if ( F_94 ( V_7 ) )
V_97 -> V_33 += V_48 ;
#endif
return V_97 ;
}
int F_112 ( struct V_6 * V_7 , int V_131 )
{
int V_132 ;
int V_118 ;
if ( ! F_113 ( V_7 ) && F_114 ( V_7 ) >= V_131 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_131 ) ;
return 0 ;
}
V_118 = V_7 -> V_49 + V_131 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_29 ( F_113 ( V_7 ) || V_118 > 0 ) ) {
V_132 = F_104 ( V_7 , 0 , V_118 , V_42 ) ;
if ( F_64 ( V_132 ) )
goto V_133;
}
V_132 = F_115 ( V_7 ) ;
if ( F_64 ( V_132 ) )
goto V_133;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_131 ) ;
return 0 ;
V_133:
F_36 ( V_7 ) ;
return V_132 ;
}
unsigned char * F_98 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_134 = F_107 ( V_7 ) ;
F_116 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_64 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_68 ( 0 ) ) ;
return V_134 ;
}
unsigned char * F_117 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_64 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_68 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_118 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_119 ( V_7 , V_11 ) ;
}
void F_120 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_121 ( V_7 , V_11 ) ;
}
int F_122 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_135 ;
struct V_6 * V_136 ;
int V_111 = F_101 ( V_7 ) ;
int V_137 = F_22 ( V_7 ) -> V_58 ;
int V_47 ;
int V_132 ;
if ( F_113 ( V_7 ) &&
F_64 ( ( V_132 = F_104 ( V_7 , 0 , 0 , V_42 ) ) ) )
return V_132 ;
V_47 = 0 ;
if ( V_111 >= V_11 )
goto V_138;
for (; V_47 < V_137 ; V_47 ++ ) {
int V_15 = V_111 + F_89 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
if ( V_15 < V_11 ) {
V_111 = V_15 ;
continue;
}
F_123 ( & F_22 ( V_7 ) -> V_107 [ V_47 ++ ] , V_11 - V_111 ) ;
V_138:
F_22 ( V_7 ) -> V_58 = V_47 ;
for (; V_47 < V_137 ; V_47 ++ )
F_43 ( V_7 , V_47 ) ;
if ( F_44 ( V_7 ) )
F_37 ( V_7 ) ;
goto V_139;
}
for ( V_135 = & F_22 ( V_7 ) -> V_54 ; ( V_136 = * V_135 ) ;
V_135 = & V_136 -> V_53 ) {
int V_15 = V_111 + V_136 -> V_11 ;
if ( F_106 ( V_136 ) ) {
struct V_6 * V_140 ;
V_140 = F_92 ( V_136 , V_42 ) ;
if ( F_64 ( ! V_140 ) )
return - V_109 ;
V_140 -> V_53 = V_136 -> V_53 ;
F_36 ( V_136 ) ;
V_136 = V_140 ;
* V_135 = V_136 ;
}
if ( V_15 < V_11 ) {
V_111 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_64 ( ( V_132 = F_124 ( V_136 , V_11 - V_111 ) ) ) )
return V_132 ;
if ( V_136 -> V_53 )
F_35 ( & V_136 -> V_53 ) ;
break;
}
V_139:
if ( V_11 > F_101 ( V_7 ) ) {
V_7 -> V_49 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_49 = 0 ;
F_125 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_126 ( struct V_6 * V_7 , int V_120 )
{
int V_47 , V_141 , V_142 = ( V_7 -> V_14 + V_120 ) - V_7 -> V_15 ;
if ( V_142 > 0 || F_113 ( V_7 ) ) {
if ( F_104 ( V_7 , 0 , V_142 > 0 ? V_142 + 128 : 0 ,
V_42 ) )
return NULL ;
}
if ( F_99 ( V_7 , F_101 ( V_7 ) , F_107 ( V_7 ) , V_120 ) )
F_8 () ;
if ( ! F_44 ( V_7 ) )
goto V_143;
V_142 = V_120 ;
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_18 = F_89 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
if ( V_18 >= V_142 )
goto V_143;
V_142 -= V_18 ;
}
if ( V_142 ) {
struct V_6 * V_51 = F_22 ( V_7 ) -> V_54 ;
struct V_6 * V_144 = NULL ;
struct V_6 * V_145 = NULL ;
do {
F_105 ( ! V_51 ) ;
if ( V_51 -> V_11 <= V_142 ) {
V_142 -= V_51 -> V_11 ;
V_51 = V_51 -> V_53 ;
V_145 = V_51 ;
} else {
if ( F_106 ( V_51 ) ) {
V_144 = F_92 ( V_51 , V_42 ) ;
if ( ! V_144 )
return NULL ;
V_145 = V_51 -> V_53 ;
V_51 = V_144 ;
} else {
V_145 = V_51 ;
}
if ( ! F_127 ( V_51 , V_142 ) ) {
F_36 ( V_144 ) ;
return NULL ;
}
break;
}
} while ( V_142 );
while ( ( V_51 = F_22 ( V_7 ) -> V_54 ) != V_145 ) {
F_22 ( V_7 ) -> V_54 = V_51 -> V_53 ;
F_36 ( V_51 ) ;
}
if ( V_144 ) {
V_144 -> V_53 = V_51 ;
F_22 ( V_7 ) -> V_54 = V_144 ;
}
}
V_143:
V_142 = V_120 ;
V_141 = 0 ;
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_18 = F_89 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
if ( V_18 <= V_142 ) {
F_43 ( V_7 , V_47 ) ;
V_142 -= V_18 ;
} else {
F_22 ( V_7 ) -> V_107 [ V_141 ] = F_22 ( V_7 ) -> V_107 [ V_47 ] ;
if ( V_142 ) {
F_22 ( V_7 ) -> V_107 [ V_141 ] . V_110 += V_142 ;
F_128 ( & F_22 ( V_7 ) -> V_107 [ V_141 ] , V_142 ) ;
V_142 = 0 ;
}
V_141 ++ ;
}
}
F_22 ( V_7 ) -> V_58 = V_141 ;
V_7 -> V_14 += V_120 ;
V_7 -> V_49 -= V_120 ;
return F_107 ( V_7 ) ;
}
int F_99 ( const struct V_6 * V_7 , int V_111 , void * V_146 , int V_11 )
{
int V_147 = F_101 ( V_7 ) ;
struct V_6 * V_148 ;
int V_47 , V_149 ;
if ( V_111 > ( int ) V_7 -> V_11 - V_11 )
goto V_150;
if ( ( V_149 = V_147 - V_111 ) > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
F_129 ( V_7 , V_111 , V_146 , V_149 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return 0 ;
V_111 += V_149 ;
V_146 += V_149 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + F_89 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
T_2 * V_105 ;
if ( V_149 > V_11 )
V_149 = V_11 ;
V_105 = F_87 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
memcpy ( V_146 ,
V_105 + F_22 ( V_7 ) -> V_107 [ V_47 ] . V_110 +
V_111 - V_147 , V_149 ) ;
F_90 ( V_105 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return 0 ;
V_111 += V_149 ;
V_146 += V_149 ;
}
V_147 = V_15 ;
}
F_39 (skb, frag_iter) {
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + V_148 -> V_11 ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
if ( F_99 ( V_148 , V_111 - V_147 , V_146 , V_149 ) )
goto V_150;
if ( ( V_11 -= V_149 ) == 0 )
return 0 ;
V_111 += V_149 ;
V_146 += V_149 ;
}
V_147 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_150:
return - V_151 ;
}
static void F_130 ( struct V_152 * V_153 , unsigned int V_47 )
{
F_2 ( V_153 -> V_154 [ V_47 ] ) ;
}
static inline struct V_5 * F_131 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_111 ,
struct V_6 * V_7 , struct V_155 * V_99 )
{
struct V_5 * V_156 = V_99 -> V_157 ;
unsigned int V_48 ;
if ( ! V_156 ) {
V_158:
V_156 = V_99 -> V_157 = F_132 ( V_99 -> V_159 , 0 ) ;
if ( ! V_156 )
return NULL ;
V_48 = V_99 -> V_160 = 0 ;
} else {
unsigned int V_161 ;
V_48 = V_99 -> V_160 ;
V_161 = V_162 - V_48 ;
if ( V_161 < 64 && V_161 < * V_11 ) {
F_2 ( V_156 ) ;
goto V_158;
}
* V_11 = F_133 (unsigned int, *len, mlen) ;
}
memcpy ( F_88 ( V_156 ) + V_48 , F_88 ( V_5 ) + * V_111 , * V_11 ) ;
V_99 -> V_160 += * V_11 ;
* V_111 = V_48 ;
F_4 ( V_156 ) ;
return V_156 ;
}
static inline int F_134 ( struct V_152 * V_153 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_111 ,
struct V_6 * V_7 , int V_163 ,
struct V_155 * V_99 )
{
if ( F_64 ( V_153 -> V_164 == V_2 -> V_165 ) )
return 1 ;
if ( V_163 ) {
V_5 = F_131 ( V_5 , V_11 , & V_111 , V_7 , V_99 ) ;
if ( ! V_5 )
return 1 ;
} else
F_4 ( V_5 ) ;
V_153 -> V_154 [ V_153 -> V_164 ] = V_5 ;
V_153 -> V_166 [ V_153 -> V_164 ] . V_11 = * V_11 ;
V_153 -> V_166 [ V_153 -> V_164 ] . V_111 = V_111 ;
V_153 -> V_164 ++ ;
return 0 ;
}
static inline void F_135 ( struct V_5 * * V_5 , unsigned int * V_167 ,
unsigned int * V_168 , unsigned int V_48 )
{
unsigned long V_97 ;
* V_167 += V_48 ;
V_97 = * V_167 / V_162 ;
if ( V_97 )
* V_5 = F_136 ( * V_5 , V_97 ) ;
* V_167 = * V_167 % V_162 ;
* V_168 -= V_48 ;
}
static inline int F_137 ( struct V_5 * V_5 , unsigned int V_167 ,
unsigned int V_168 , unsigned int * V_48 ,
unsigned int * V_11 , struct V_6 * V_7 ,
struct V_152 * V_153 , int V_163 ,
struct V_155 * V_99 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return 1 ;
if ( * V_48 >= V_168 ) {
* V_48 -= V_168 ;
return 0 ;
}
if ( * V_48 ) {
F_135 ( & V_5 , & V_167 , & V_168 , * V_48 ) ;
* V_48 = 0 ;
}
do {
unsigned int V_169 = F_138 ( * V_11 , V_168 ) ;
V_169 = F_133 (unsigned int, flen, PAGE_SIZE - poff) ;
if ( F_134 ( V_153 , V_2 , V_5 , & V_169 , V_167 , V_7 , V_163 , V_99 ) )
return 1 ;
F_135 ( & V_5 , & V_167 , & V_168 , V_169 ) ;
* V_11 -= V_169 ;
} while ( * V_11 && V_168 );
return 0 ;
}
static int F_139 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_111 , unsigned int * V_11 ,
struct V_152 * V_153 , struct V_155 * V_99 )
{
int V_170 ;
if ( F_137 ( F_140 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_162 - 1 ) ,
F_101 ( V_7 ) ,
V_111 , V_11 , V_7 , V_153 , 1 , V_99 , V_2 ) )
return 1 ;
for ( V_170 = 0 ; V_170 < F_22 ( V_7 ) -> V_58 ; V_170 ++ ) {
const T_5 * V_106 = & F_22 ( V_7 ) -> V_107 [ V_170 ] ;
if ( F_137 ( F_141 ( V_106 ) ,
V_106 -> V_110 , F_89 ( V_106 ) ,
V_111 , V_11 , V_7 , V_153 , 0 , V_99 , V_2 ) )
return 1 ;
}
return 0 ;
}
int F_142 ( struct V_6 * V_7 , unsigned int V_111 ,
struct V_1 * V_2 , unsigned int V_171 ,
unsigned int V_172 )
{
struct V_173 V_166 [ V_174 ] ;
struct V_5 * V_154 [ V_174 ] ;
struct V_152 V_153 = {
. V_154 = V_154 ,
. V_166 = V_166 ,
. V_172 = V_172 ,
. V_175 = & V_176 ,
. V_177 = F_130 ,
} ;
struct V_6 * V_148 ;
struct V_155 * V_99 = V_7 -> V_99 ;
int V_178 = 0 ;
if ( F_143 ( V_2 , & V_153 ) )
return - V_109 ;
if ( F_139 ( V_7 , V_2 , & V_111 , & V_171 , & V_153 , V_99 ) )
goto V_139;
else if ( ! V_171 )
goto V_139;
F_39 (skb, frag_iter) {
if ( ! V_171 )
break;
if ( F_139 ( V_148 , V_2 , & V_111 , & V_171 , & V_153 , V_99 ) )
break;
}
V_139:
if ( V_153 . V_164 ) {
F_144 ( V_99 ) ;
V_178 = F_145 ( V_2 , & V_153 ) ;
F_146 ( V_99 ) ;
}
F_147 ( V_2 , & V_153 ) ;
return V_178 ;
}
int F_148 ( struct V_6 * V_7 , int V_111 , const void * V_179 , int V_11 )
{
int V_147 = F_101 ( V_7 ) ;
struct V_6 * V_148 ;
int V_47 , V_149 ;
if ( V_111 > ( int ) V_7 -> V_11 - V_11 )
goto V_150;
if ( ( V_149 = V_147 - V_111 ) > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
F_149 ( V_7 , V_111 , V_179 , V_149 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return 0 ;
V_111 += V_149 ;
V_179 += V_149 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
T_5 * V_136 = & F_22 ( V_7 ) -> V_107 [ V_47 ] ;
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + F_89 ( V_136 ) ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
T_2 * V_105 ;
if ( V_149 > V_11 )
V_149 = V_11 ;
V_105 = F_87 ( V_136 ) ;
memcpy ( V_105 + V_136 -> V_110 + V_111 - V_147 ,
V_179 , V_149 ) ;
F_90 ( V_105 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return 0 ;
V_111 += V_149 ;
V_179 += V_149 ;
}
V_147 = V_15 ;
}
F_39 (skb, frag_iter) {
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + V_148 -> V_11 ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
if ( F_148 ( V_148 , V_111 - V_147 ,
V_179 , V_149 ) )
goto V_150;
if ( ( V_11 -= V_149 ) == 0 )
return 0 ;
V_111 += V_149 ;
V_179 += V_149 ;
}
V_147 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_150:
return - V_151 ;
}
T_6 F_150 ( const struct V_6 * V_7 , int V_111 ,
int V_11 , T_6 V_84 )
{
int V_147 = F_101 ( V_7 ) ;
int V_47 , V_149 = V_147 - V_111 ;
struct V_6 * V_148 ;
int V_180 = 0 ;
if ( V_149 > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
V_84 = F_151 ( V_7 -> V_13 + V_111 , V_149 , V_84 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return V_84 ;
V_111 += V_149 ;
V_180 = V_149 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + F_89 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
T_6 V_181 ;
T_2 * V_105 ;
T_5 * V_136 = & F_22 ( V_7 ) -> V_107 [ V_47 ] ;
if ( V_149 > V_11 )
V_149 = V_11 ;
V_105 = F_87 ( V_136 ) ;
V_181 = F_151 ( V_105 + V_136 -> V_110 +
V_111 - V_147 , V_149 , 0 ) ;
F_90 ( V_105 ) ;
V_84 = F_152 ( V_84 , V_181 , V_180 ) ;
if ( ! ( V_11 -= V_149 ) )
return V_84 ;
V_111 += V_149 ;
V_180 += V_149 ;
}
V_147 = V_15 ;
}
F_39 (skb, frag_iter) {
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + V_148 -> V_11 ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
T_6 V_181 ;
if ( V_149 > V_11 )
V_149 = V_11 ;
V_181 = F_150 ( V_148 , V_111 - V_147 ,
V_149 , 0 ) ;
V_84 = F_152 ( V_84 , V_181 , V_180 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return V_84 ;
V_111 += V_149 ;
V_180 += V_149 ;
}
V_147 = V_15 ;
}
F_105 ( V_11 ) ;
return V_84 ;
}
T_6 F_153 ( const struct V_6 * V_7 , int V_111 ,
T_2 * V_146 , int V_11 , T_6 V_84 )
{
int V_147 = F_101 ( V_7 ) ;
int V_47 , V_149 = V_147 - V_111 ;
struct V_6 * V_148 ;
int V_180 = 0 ;
if ( V_149 > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
V_84 = F_154 ( V_7 -> V_13 + V_111 , V_146 ,
V_149 , V_84 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return V_84 ;
V_111 += V_149 ;
V_146 += V_149 ;
V_180 = V_149 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + F_89 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
T_6 V_181 ;
T_2 * V_105 ;
T_5 * V_136 = & F_22 ( V_7 ) -> V_107 [ V_47 ] ;
if ( V_149 > V_11 )
V_149 = V_11 ;
V_105 = F_87 ( V_136 ) ;
V_181 = F_154 ( V_105 +
V_136 -> V_110 +
V_111 - V_147 , V_146 ,
V_149 , 0 ) ;
F_90 ( V_105 ) ;
V_84 = F_152 ( V_84 , V_181 , V_180 ) ;
if ( ! ( V_11 -= V_149 ) )
return V_84 ;
V_111 += V_149 ;
V_146 += V_149 ;
V_180 += V_149 ;
}
V_147 = V_15 ;
}
F_39 (skb, frag_iter) {
T_6 V_181 ;
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + V_148 -> V_11 ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
V_181 = F_153 ( V_148 ,
V_111 - V_147 ,
V_146 , V_149 , 0 ) ;
V_84 = F_152 ( V_84 , V_181 , V_180 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return V_84 ;
V_111 += V_149 ;
V_146 += V_149 ;
V_180 += V_149 ;
}
V_147 = V_15 ;
}
F_105 ( V_11 ) ;
return V_84 ;
}
void F_155 ( const struct V_6 * V_7 , T_2 * V_146 )
{
T_6 V_84 ;
long V_182 ;
if ( V_7 -> V_87 == V_123 )
V_182 = F_156 ( V_7 ) ;
else
V_182 = F_101 ( V_7 ) ;
F_105 ( V_182 > F_101 ( V_7 ) ) ;
F_102 ( V_7 , V_146 , V_182 ) ;
V_84 = 0 ;
if ( V_182 != V_7 -> V_11 )
V_84 = F_153 ( V_7 , V_182 , V_146 + V_182 ,
V_7 -> V_11 - V_182 , 0 ) ;
if ( V_7 -> V_87 == V_123 ) {
long V_183 = V_182 + V_7 -> V_184 ;
* ( ( V_185 * ) ( V_146 + V_183 ) ) = F_157 ( V_84 ) ;
}
}
struct V_6 * F_158 ( struct V_186 * V_51 )
{
unsigned long V_172 ;
struct V_6 * V_187 ;
F_159 ( & V_51 -> V_188 , V_172 ) ;
V_187 = F_160 ( V_51 ) ;
F_161 ( & V_51 -> V_188 , V_172 ) ;
return V_187 ;
}
struct V_6 * F_162 ( struct V_186 * V_51 )
{
unsigned long V_172 ;
struct V_6 * V_187 ;
F_159 ( & V_51 -> V_188 , V_172 ) ;
V_187 = F_163 ( V_51 ) ;
F_161 ( & V_51 -> V_188 , V_172 ) ;
return V_187 ;
}
void F_164 ( struct V_186 * V_51 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_158 ( V_51 ) ) != NULL )
F_36 ( V_7 ) ;
}
void F_165 ( struct V_186 * V_51 , struct V_6 * V_189 )
{
unsigned long V_172 ;
F_159 ( & V_51 -> V_188 , V_172 ) ;
F_166 ( V_51 , V_189 ) ;
F_161 ( & V_51 -> V_188 , V_172 ) ;
}
void F_167 ( struct V_186 * V_51 , struct V_6 * V_189 )
{
unsigned long V_172 ;
F_159 ( & V_51 -> V_188 , V_172 ) ;
F_168 ( V_51 , V_189 ) ;
F_161 ( & V_51 -> V_188 , V_172 ) ;
}
void F_169 ( struct V_6 * V_7 , struct V_186 * V_51 )
{
unsigned long V_172 ;
F_159 ( & V_51 -> V_188 , V_172 ) ;
F_170 ( V_7 , V_51 ) ;
F_161 ( & V_51 -> V_188 , V_172 ) ;
}
void F_171 ( struct V_6 * V_76 , struct V_6 * V_189 , struct V_186 * V_51 )
{
unsigned long V_172 ;
F_159 ( & V_51 -> V_188 , V_172 ) ;
F_172 ( V_51 , V_76 , V_189 ) ;
F_161 ( & V_51 -> V_188 , V_172 ) ;
}
void F_173 ( struct V_6 * V_76 , struct V_6 * V_189 , struct V_186 * V_51 )
{
unsigned long V_172 ;
F_159 ( & V_51 -> V_188 , V_172 ) ;
F_174 ( V_189 , V_76 -> V_98 , V_76 , V_51 ) ;
F_161 ( & V_51 -> V_188 , V_172 ) ;
}
static inline void F_175 ( struct V_6 * V_7 ,
struct V_6 * V_190 ,
const T_7 V_11 , const int V_180 )
{
int V_47 ;
F_129 ( V_7 , V_11 , F_98 ( V_190 , V_180 - V_11 ) ,
V_180 - V_11 ) ;
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ )
F_22 ( V_190 ) -> V_107 [ V_47 ] = F_22 ( V_7 ) -> V_107 [ V_47 ] ;
F_22 ( V_190 ) -> V_58 = F_22 ( V_7 ) -> V_58 ;
F_22 ( V_7 ) -> V_58 = 0 ;
V_190 -> V_49 = V_7 -> V_49 ;
V_190 -> V_11 += V_190 -> V_49 ;
V_7 -> V_49 = 0 ;
V_7 -> V_11 = V_11 ;
F_125 ( V_7 , V_11 ) ;
}
static inline void F_176 ( struct V_6 * V_7 ,
struct V_6 * V_190 ,
const T_7 V_11 , int V_180 )
{
int V_47 , V_141 = 0 ;
const int V_137 = F_22 ( V_7 ) -> V_58 ;
F_22 ( V_7 ) -> V_58 = 0 ;
V_190 -> V_11 = V_190 -> V_49 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_49 = V_11 - V_180 ;
for ( V_47 = 0 ; V_47 < V_137 ; V_47 ++ ) {
int V_18 = F_89 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
if ( V_180 + V_18 > V_11 ) {
F_22 ( V_190 ) -> V_107 [ V_141 ] = F_22 ( V_7 ) -> V_107 [ V_47 ] ;
if ( V_180 < V_11 ) {
F_103 ( V_7 , V_47 ) ;
F_22 ( V_190 ) -> V_107 [ 0 ] . V_110 += V_11 - V_180 ;
F_128 ( & F_22 ( V_190 ) -> V_107 [ 0 ] , V_11 - V_180 ) ;
F_123 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] , V_11 - V_180 ) ;
F_22 ( V_7 ) -> V_58 ++ ;
}
V_141 ++ ;
} else
F_22 ( V_7 ) -> V_58 ++ ;
V_180 += V_18 ;
}
F_22 ( V_190 ) -> V_58 = V_141 ;
}
void F_177 ( struct V_6 * V_7 , struct V_6 * V_190 , const T_7 V_11 )
{
int V_180 = F_101 ( V_7 ) ;
if ( V_11 < V_180 )
F_175 ( V_7 , V_190 , V_11 , V_180 ) ;
else
F_176 ( V_7 , V_190 , V_11 , V_180 ) ;
}
static int F_178 ( struct V_6 * V_7 )
{
return F_113 ( V_7 ) && F_104 ( V_7 , 0 , 0 , V_42 ) ;
}
int F_179 ( struct V_6 * V_191 , struct V_6 * V_7 , int V_192 )
{
int V_179 , V_146 , V_193 , V_194 ;
struct V_195 * V_196 , * V_197 ;
F_105 ( V_192 > V_7 -> V_11 ) ;
F_105 ( F_101 ( V_7 ) ) ;
V_194 = V_192 ;
V_179 = 0 ;
V_146 = F_22 ( V_191 ) -> V_58 ;
V_196 = & F_22 ( V_7 ) -> V_107 [ V_179 ] ;
if ( ! V_146 ||
! F_180 ( V_191 , V_146 , F_141 ( V_196 ) ,
V_196 -> V_110 ) ) {
V_193 = - 1 ;
} else {
V_193 = V_146 - 1 ;
V_194 -= F_89 ( V_196 ) ;
if ( V_194 < 0 ) {
if ( F_178 ( V_7 ) ||
F_178 ( V_191 ) )
return 0 ;
V_196 = & F_22 ( V_7 ) -> V_107 [ V_179 ] ;
V_197 = & F_22 ( V_191 ) -> V_107 [ V_193 ] ;
F_181 ( V_197 , V_192 ) ;
F_128 ( V_196 , V_192 ) ;
V_196 -> V_110 += V_192 ;
goto V_198;
}
V_179 ++ ;
}
if ( ( V_192 == V_7 -> V_11 ) &&
( F_22 ( V_7 ) -> V_58 - V_179 ) > ( V_199 - V_146 ) )
return 0 ;
if ( F_178 ( V_7 ) || F_178 ( V_191 ) )
return 0 ;
while ( ( V_194 > 0 ) && ( V_179 < F_22 ( V_7 ) -> V_58 ) ) {
if ( V_146 == V_199 )
return 0 ;
V_196 = & F_22 ( V_7 ) -> V_107 [ V_179 ] ;
V_197 = & F_22 ( V_191 ) -> V_107 [ V_146 ] ;
if ( V_194 >= F_89 ( V_196 ) ) {
* V_197 = * V_196 ;
V_194 -= F_89 ( V_196 ) ;
V_179 ++ ;
V_146 ++ ;
} else {
F_182 ( V_196 ) ;
V_197 -> V_5 = V_196 -> V_5 ;
V_197 -> V_110 = V_196 -> V_110 ;
F_123 ( V_197 , V_194 ) ;
V_196 -> V_110 += V_194 ;
F_128 ( V_196 , V_194 ) ;
V_194 = 0 ;
V_146 ++ ;
break;
}
}
F_22 ( V_191 ) -> V_58 = V_146 ;
if ( V_193 >= 0 ) {
V_196 = & F_22 ( V_7 ) -> V_107 [ 0 ] ;
V_197 = & F_22 ( V_191 ) -> V_107 [ V_193 ] ;
F_181 ( V_197 , F_89 ( V_196 ) ) ;
F_183 ( V_196 ) ;
}
V_146 = 0 ;
while ( V_179 < F_22 ( V_7 ) -> V_58 )
F_22 ( V_7 ) -> V_107 [ V_146 ++ ] = F_22 ( V_7 ) -> V_107 [ V_179 ++ ] ;
F_22 ( V_7 ) -> V_58 = V_146 ;
F_105 ( V_194 > 0 && ! F_22 ( V_7 ) -> V_58 ) ;
V_198:
V_191 -> V_87 = V_123 ;
V_7 -> V_87 = V_123 ;
V_7 -> V_11 -= V_192 ;
V_7 -> V_49 -= V_192 ;
V_7 -> V_31 -= V_192 ;
V_191 -> V_11 += V_192 ;
V_191 -> V_49 += V_192 ;
V_191 -> V_31 += V_192 ;
return V_192 ;
}
void F_184 ( struct V_6 * V_7 , unsigned int V_179 ,
unsigned int V_146 , struct V_200 * V_201 )
{
V_201 -> V_202 = V_179 ;
V_201 -> V_203 = V_146 ;
V_201 -> V_204 = V_201 -> V_205 = V_7 ;
V_201 -> V_206 = V_201 -> V_207 = 0 ;
V_201 -> V_208 = NULL ;
}
unsigned int F_185 ( unsigned int V_209 , const T_2 * * V_13 ,
struct V_200 * V_201 )
{
unsigned int V_210 , V_211 = V_209 + V_201 -> V_202 ;
T_5 * V_136 ;
if ( F_64 ( V_211 >= V_201 -> V_203 ) )
return 0 ;
V_212:
V_210 = F_101 ( V_201 -> V_205 ) + V_201 -> V_207 ;
if ( V_211 < V_210 && ! V_201 -> V_208 ) {
* V_13 = V_201 -> V_205 -> V_13 + ( V_211 - V_201 -> V_207 ) ;
return V_210 - V_211 ;
}
if ( V_201 -> V_206 == 0 && ! V_201 -> V_208 )
V_201 -> V_207 += F_101 ( V_201 -> V_205 ) ;
while ( V_201 -> V_206 < F_22 ( V_201 -> V_205 ) -> V_58 ) {
V_136 = & F_22 ( V_201 -> V_205 ) -> V_107 [ V_201 -> V_206 ] ;
V_210 = F_89 ( V_136 ) + V_201 -> V_207 ;
if ( V_211 < V_210 ) {
if ( ! V_201 -> V_208 )
V_201 -> V_208 = F_87 ( V_136 ) ;
* V_13 = ( T_2 * ) V_201 -> V_208 + V_136 -> V_110 +
( V_211 - V_201 -> V_207 ) ;
return V_210 - V_211 ;
}
if ( V_201 -> V_208 ) {
F_90 ( V_201 -> V_208 ) ;
V_201 -> V_208 = NULL ;
}
V_201 -> V_206 ++ ;
V_201 -> V_207 += F_89 ( V_136 ) ;
}
if ( V_201 -> V_208 ) {
F_90 ( V_201 -> V_208 ) ;
V_201 -> V_208 = NULL ;
}
if ( V_201 -> V_204 == V_201 -> V_205 && F_44 ( V_201 -> V_204 ) ) {
V_201 -> V_205 = F_22 ( V_201 -> V_204 ) -> V_54 ;
V_201 -> V_206 = 0 ;
goto V_212;
} else if ( V_201 -> V_205 -> V_53 ) {
V_201 -> V_205 = V_201 -> V_205 -> V_53 ;
V_201 -> V_206 = 0 ;
goto V_212;
}
return 0 ;
}
void F_186 ( struct V_200 * V_201 )
{
if ( V_201 -> V_208 )
F_90 ( V_201 -> V_208 ) ;
}
static unsigned int F_187 ( unsigned int V_111 , const T_2 * * V_213 ,
struct V_214 * V_215 ,
struct V_216 * V_217 )
{
return F_185 ( V_111 , V_213 , F_188 ( V_217 ) ) ;
}
static void F_189 ( struct V_214 * V_215 , struct V_216 * V_217 )
{
F_186 ( F_188 ( V_217 ) ) ;
}
unsigned int F_190 ( struct V_6 * V_7 , unsigned int V_179 ,
unsigned int V_146 , struct V_214 * V_218 ,
struct V_216 * V_217 )
{
unsigned int V_178 ;
V_218 -> V_219 = F_187 ;
V_218 -> V_220 = F_189 ;
F_184 ( V_7 , V_179 , V_146 , F_188 ( V_217 ) ) ;
V_178 = F_191 ( V_218 , V_217 ) ;
return ( V_178 <= V_146 - V_179 ? V_178 : V_221 ) ;
}
int F_192 ( struct V_155 * V_99 , struct V_6 * V_7 ,
int (* F_193)( void * V_179 , char * V_146 , int V_111 ,
int V_11 , int V_222 , struct V_6 * V_7 ) ,
void * V_179 , int V_44 )
{
int V_223 = 0 ;
T_5 * V_136 = NULL ;
struct V_5 * V_5 = NULL ;
int V_149 , V_224 ;
int V_111 = 0 ;
int V_178 ;
do {
V_223 = F_22 ( V_7 ) -> V_58 ;
if ( V_223 >= V_199 )
return - V_151 ;
V_5 = F_132 ( V_99 -> V_159 , 0 ) ;
if ( V_5 == NULL )
return - V_109 ;
F_32 ( V_7 , V_223 , V_5 , 0 , 0 ) ;
V_7 -> V_31 += V_162 ;
F_194 ( V_162 , & V_99 -> V_225 ) ;
V_223 = F_22 ( V_7 ) -> V_58 ;
V_136 = & F_22 ( V_7 ) -> V_107 [ V_223 - 1 ] ;
V_224 = V_162 - V_136 -> V_110 ;
V_149 = ( V_44 > V_224 ) ? V_224 : V_44 ;
V_178 = F_193 ( V_179 , F_195 ( V_136 ) + F_89 ( V_136 ) ,
V_111 , V_149 , 0 , V_7 ) ;
if ( V_178 < 0 )
return - V_151 ;
F_181 ( V_136 , V_149 ) ;
V_7 -> V_11 += V_149 ;
V_7 -> V_49 += V_149 ;
V_111 += V_149 ;
V_44 -= V_149 ;
} while ( V_44 > 0 );
return 0 ;
}
unsigned char * F_196 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_105 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_105 ( V_7 -> V_11 < V_7 -> V_49 ) ;
F_197 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_198 ( struct V_6 * V_7 , T_8 V_226 )
{
struct V_6 * V_227 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_228 = F_22 ( V_7 ) -> V_54 ;
unsigned int V_229 = F_22 ( V_7 ) -> V_112 ;
unsigned int V_230 = V_7 -> V_13 - F_199 ( V_7 ) ;
unsigned int V_111 = V_230 ;
unsigned int V_116 ;
unsigned int V_11 ;
int V_231 = ! ! ( V_226 & V_232 ) ;
int V_137 = F_22 ( V_7 ) -> V_58 ;
int V_132 = - V_109 ;
int V_47 = 0 ;
int V_180 ;
F_200 ( V_7 , V_230 ) ;
V_116 = F_82 ( V_7 ) ;
V_180 = F_101 ( V_7 ) ;
do {
struct V_6 * V_233 ;
T_5 * V_136 ;
int V_234 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_111 ;
if ( V_11 > V_229 )
V_11 = V_229 ;
V_234 = F_101 ( V_7 ) - V_111 ;
if ( V_234 < 0 )
V_234 = 0 ;
if ( V_234 > V_11 || ! V_231 )
V_234 = V_11 ;
if ( ! V_234 && V_47 >= V_137 ) {
F_105 ( V_228 -> V_11 != V_11 ) ;
V_180 += V_11 ;
V_233 = F_92 ( V_228 , V_42 ) ;
V_228 = V_228 -> V_53 ;
if ( F_64 ( ! V_233 ) )
goto V_132;
V_234 = F_96 ( V_233 ) - V_233 -> V_12 ;
if ( F_201 ( V_233 , V_230 + V_116 ) ) {
F_36 ( V_233 ) ;
goto V_132;
}
V_233 -> V_31 += F_96 ( V_233 ) - V_233 -> V_12 -
V_234 ;
F_48 ( V_233 ) ;
F_200 ( V_233 , V_230 ) ;
} else {
V_233 = F_97 ( V_234 + V_230 + V_116 ,
V_42 ) ;
if ( F_64 ( ! V_233 ) )
goto V_132;
F_30 ( V_233 , V_116 ) ;
F_202 ( V_233 , V_230 ) ;
}
if ( V_227 )
V_14 -> V_53 = V_233 ;
else
V_227 = V_233 ;
V_14 = V_233 ;
F_74 ( V_233 , V_7 ) ;
V_233 -> V_100 = V_7 -> V_100 ;
if ( V_233 -> V_87 == V_123 )
V_233 -> V_124 += F_82 ( V_233 ) - V_116 ;
F_203 ( V_233 ) ;
F_204 ( V_233 , V_7 -> V_100 ) ;
V_233 -> V_78 = ( V_233 -> V_79 +
F_205 ( V_7 ) ) ;
F_102 ( V_7 , V_233 -> V_13 , V_230 ) ;
if ( V_228 != F_22 ( V_7 ) -> V_54 )
continue;
if ( ! V_231 ) {
V_233 -> V_87 = V_235 ;
V_233 -> V_84 = F_153 ( V_7 , V_111 ,
F_98 ( V_233 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_136 = F_22 ( V_233 ) -> V_107 ;
F_129 ( V_7 , V_111 ,
F_98 ( V_233 , V_234 ) , V_234 ) ;
while ( V_180 < V_111 + V_11 && V_47 < V_137 ) {
* V_136 = F_22 ( V_7 ) -> V_107 [ V_47 ] ;
F_182 ( V_136 ) ;
V_18 = F_89 ( V_136 ) ;
if ( V_180 < V_111 ) {
V_136 -> V_110 += V_111 - V_180 ;
F_128 ( V_136 , V_111 - V_180 ) ;
}
F_22 ( V_233 ) -> V_58 ++ ;
if ( V_180 + V_18 <= V_111 + V_11 ) {
V_47 ++ ;
V_180 += V_18 ;
} else {
F_128 ( V_136 , V_180 + V_18 - ( V_111 + V_11 ) ) ;
goto V_236;
}
V_136 ++ ;
}
if ( V_180 < V_111 + V_11 ) {
struct V_6 * V_237 = V_228 ;
F_105 ( V_180 + V_228 -> V_11 != V_111 + V_11 ) ;
V_180 += V_228 -> V_11 ;
V_228 = V_228 -> V_53 ;
if ( V_237 -> V_53 ) {
V_237 = F_92 ( V_237 , V_42 ) ;
if ( ! V_237 )
goto V_132;
} else
F_40 ( V_237 ) ;
F_206 ( V_233 ) ;
F_22 ( V_233 ) -> V_54 = V_237 ;
}
V_236:
V_233 -> V_49 = V_11 - V_234 ;
V_233 -> V_11 += V_233 -> V_49 ;
V_233 -> V_31 += V_233 -> V_49 ;
} while ( ( V_111 += V_11 ) < V_7 -> V_11 );
return V_227 ;
V_132:
while ( ( V_7 = V_227 ) ) {
V_227 = V_7 -> V_53 ;
F_36 ( V_7 ) ;
}
return F_207 ( V_132 ) ;
}
int F_208 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_156 = * V_12 ;
struct V_6 * V_233 ;
struct V_24 * V_238 = F_22 ( V_7 ) ;
struct V_24 * V_239 = F_22 ( V_156 ) ;
unsigned int V_116 ;
unsigned int V_11 = F_209 ( V_7 ) ;
unsigned int V_111 = F_210 ( V_7 ) ;
unsigned int V_240 = F_101 ( V_7 ) ;
if ( V_156 -> V_11 + V_11 >= 65536 )
return - V_241 ;
if ( V_239 -> V_54 )
goto V_193;
else if ( V_240 <= V_111 ) {
T_5 * V_136 ;
T_5 * V_242 ;
int V_47 = V_238 -> V_58 ;
int V_58 = V_239 -> V_58 + V_47 ;
V_111 -= V_240 ;
if ( V_58 > V_199 )
return - V_241 ;
V_239 -> V_58 = V_58 ;
V_238 -> V_58 = 0 ;
V_136 = V_239 -> V_107 + V_58 ;
V_242 = V_238 -> V_107 + V_47 ;
do {
* -- V_136 = * -- V_242 ;
} while ( -- V_47 );
V_136 -> V_110 += V_111 ;
F_128 ( V_136 , V_111 ) ;
V_7 -> V_31 -= V_7 -> V_49 ;
V_7 -> V_11 -= V_7 -> V_49 ;
V_7 -> V_49 = 0 ;
F_211 ( V_7 ) -> free = 1 ;
goto V_139;
} else if ( F_209 ( V_156 ) != V_239 -> V_112 )
return - V_241 ;
V_116 = F_82 ( V_156 ) ;
V_233 = F_97 ( V_116 + F_210 ( V_156 ) , V_42 ) ;
if ( F_64 ( ! V_233 ) )
return - V_109 ;
F_74 ( V_233 , V_156 ) ;
V_233 -> V_100 = V_156 -> V_100 ;
F_30 ( V_233 , V_116 ) ;
F_202 ( V_233 , F_210 ( V_156 ) ) ;
F_212 ( V_233 , F_199 ( V_156 ) - V_156 -> V_13 ) ;
F_204 ( V_233 , F_213 ( V_156 ) ) ;
F_214 ( V_233 , F_215 ( V_156 ) ) ;
F_216 ( V_156 , F_210 ( V_156 ) ) ;
memcpy ( F_199 ( V_233 ) , F_199 ( V_156 ) ,
V_156 -> V_13 - F_199 ( V_156 ) ) ;
* F_211 ( V_233 ) = * F_211 ( V_156 ) ;
F_22 ( V_233 ) -> V_54 = V_156 ;
F_22 ( V_233 ) -> V_112 = V_239 -> V_112 ;
V_239 -> V_112 = 0 ;
F_217 ( V_156 ) ;
V_233 -> V_98 = V_156 ;
V_233 -> V_49 += V_156 -> V_11 ;
V_233 -> V_31 += V_156 -> V_11 ;
V_233 -> V_11 += V_156 -> V_11 ;
* V_12 = V_233 ;
V_233 -> V_53 = V_156 -> V_53 ;
V_156 -> V_53 = NULL ;
V_156 = V_233 ;
V_193:
if ( V_111 > V_240 ) {
unsigned int V_142 = V_111 - V_240 ;
V_238 -> V_107 [ 0 ] . V_110 += V_142 ;
F_128 ( & V_238 -> V_107 [ 0 ] , V_142 ) ;
V_7 -> V_49 -= V_142 ;
V_7 -> V_11 -= V_142 ;
V_111 = V_240 ;
}
F_216 ( V_7 , V_111 ) ;
V_156 -> V_98 -> V_53 = V_7 ;
V_156 -> V_98 = V_7 ;
F_217 ( V_7 ) ;
V_139:
F_211 ( V_156 ) -> V_243 ++ ;
V_156 -> V_49 += V_11 ;
V_156 -> V_31 += V_11 ;
V_156 -> V_11 += V_11 ;
F_211 ( V_7 ) -> V_244 = 1 ;
return 0 ;
}
void T_9 F_218 ( void )
{
V_27 = F_219 ( L_5 ,
sizeof( struct V_6 ) ,
0 ,
V_245 | V_246 ,
NULL ) ;
V_26 = F_219 ( L_6 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_3 ) ,
0 ,
V_245 | V_246 ,
NULL ) ;
}
static int
F_220 ( struct V_6 * V_7 , struct V_247 * V_231 , int V_111 , int V_11 )
{
int V_147 = F_101 ( V_7 ) ;
int V_47 , V_149 = V_147 - V_111 ;
struct V_6 * V_148 ;
int V_248 = 0 ;
if ( V_149 > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
F_221 ( V_231 , V_7 -> V_13 + V_111 , V_149 ) ;
V_248 ++ ;
if ( ( V_11 -= V_149 ) == 0 )
return V_248 ;
V_111 += V_149 ;
}
for ( V_47 = 0 ; V_47 < F_22 ( V_7 ) -> V_58 ; V_47 ++ ) {
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + F_89 ( & F_22 ( V_7 ) -> V_107 [ V_47 ] ) ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
T_5 * V_136 = & F_22 ( V_7 ) -> V_107 [ V_47 ] ;
if ( V_149 > V_11 )
V_149 = V_11 ;
F_222 ( & V_231 [ V_248 ] , F_141 ( V_136 ) , V_149 ,
V_136 -> V_110 + V_111 - V_147 ) ;
V_248 ++ ;
if ( ! ( V_11 -= V_149 ) )
return V_248 ;
V_111 += V_149 ;
}
V_147 = V_15 ;
}
F_39 (skb, frag_iter) {
int V_15 ;
F_52 ( V_147 > V_111 + V_11 ) ;
V_15 = V_147 + V_148 -> V_11 ;
if ( ( V_149 = V_15 - V_111 ) > 0 ) {
if ( V_149 > V_11 )
V_149 = V_11 ;
V_248 += F_220 ( V_148 , V_231 + V_248 , V_111 - V_147 ,
V_149 ) ;
if ( ( V_11 -= V_149 ) == 0 )
return V_248 ;
V_111 += V_149 ;
}
V_147 = V_15 ;
}
F_105 ( V_11 ) ;
return V_248 ;
}
int F_223 ( struct V_6 * V_7 , struct V_247 * V_231 , int V_111 , int V_11 )
{
int V_249 = F_220 ( V_7 , V_231 , V_111 , V_11 ) ;
F_224 ( & V_231 [ V_249 - 1 ] ) ;
return V_249 ;
}
int F_225 ( struct V_6 * V_7 , int V_250 , struct V_6 * * V_251 )
{
int V_252 ;
int V_248 ;
struct V_6 * V_190 , * * V_253 ;
if ( ( F_113 ( V_7 ) || F_22 ( V_7 ) -> V_58 ) &&
F_126 ( V_7 , F_226 ( V_7 ) - F_101 ( V_7 ) ) == NULL )
return - V_109 ;
if ( ! F_44 ( V_7 ) ) {
if ( F_114 ( V_7 ) < V_250 &&
F_104 ( V_7 , 0 , V_250 - F_114 ( V_7 ) + 128 , V_42 ) )
return - V_109 ;
* V_251 = V_7 ;
return 1 ;
}
V_248 = 1 ;
V_253 = & F_22 ( V_7 ) -> V_54 ;
V_252 = 0 ;
while ( ( V_190 = * V_253 ) != NULL ) {
int V_118 = 0 ;
if ( F_106 ( V_190 ) )
V_252 = 1 ;
if ( V_190 -> V_53 == NULL && V_250 ) {
if ( F_22 ( V_190 ) -> V_58 ||
F_44 ( V_190 ) ||
F_114 ( V_190 ) < V_250 )
V_118 = V_250 + 128 ;
}
if ( V_252 ||
F_113 ( V_190 ) ||
V_118 ||
F_22 ( V_190 ) -> V_58 ||
F_44 ( V_190 ) ) {
struct V_6 * V_125 ;
if ( V_118 == 0 )
V_125 = F_95 ( V_190 , V_42 ) ;
else
V_125 = F_111 ( V_190 ,
F_82 ( V_190 ) ,
V_118 ,
V_42 ) ;
if ( F_64 ( V_125 == NULL ) )
return - V_109 ;
if ( V_190 -> V_99 )
F_227 ( V_125 , V_190 -> V_99 ) ;
V_125 -> V_53 = V_190 -> V_53 ;
* V_253 = V_125 ;
F_36 ( V_190 ) ;
V_190 = V_125 ;
}
V_248 ++ ;
* V_251 = V_190 ;
V_253 = & V_190 -> V_53 ;
}
return V_248 ;
}
static void F_228 ( struct V_6 * V_7 )
{
struct V_155 * V_99 = V_7 -> V_99 ;
F_229 ( V_7 -> V_31 , & V_99 -> V_254 ) ;
}
int F_230 ( struct V_155 * V_99 , struct V_6 * V_7 )
{
if ( F_65 ( & V_99 -> V_254 ) + V_7 -> V_31 >=
( unsigned ) V_99 -> V_255 )
return - V_109 ;
F_231 ( V_7 ) ;
V_7 -> V_99 = V_99 ;
V_7 -> V_67 = F_228 ;
F_194 ( V_7 -> V_31 , & V_99 -> V_254 ) ;
F_232 ( V_7 ) ;
F_167 ( & V_99 -> V_256 , V_7 ) ;
if ( ! F_233 ( V_99 , V_257 ) )
V_99 -> V_258 ( V_99 , V_7 -> V_11 ) ;
return 0 ;
}
void F_234 ( struct V_6 * V_259 ,
struct V_260 * V_261 )
{
struct V_155 * V_99 = V_259 -> V_99 ;
struct V_262 * V_263 ;
struct V_6 * V_7 ;
int V_132 ;
if ( ! V_99 )
return;
V_7 = F_92 ( V_259 , V_42 ) ;
if ( ! V_7 )
return;
if ( V_261 ) {
* F_235 ( V_7 ) =
* V_261 ;
} else {
V_7 -> V_77 = F_236 () ;
}
V_263 = F_237 ( V_7 ) ;
memset ( V_263 , 0 , sizeof( * V_263 ) ) ;
V_263 -> V_264 . V_265 = V_266 ;
V_263 -> V_264 . V_267 = V_268 ;
V_132 = F_230 ( V_99 , V_7 ) ;
if ( V_132 )
F_36 ( V_7 ) ;
}
void F_238 ( struct V_6 * V_7 , bool V_269 )
{
struct V_155 * V_99 = V_7 -> V_99 ;
struct V_262 * V_263 ;
int V_132 ;
V_7 -> V_270 = 1 ;
V_7 -> V_271 = V_269 ;
V_263 = F_237 ( V_7 ) ;
memset ( V_263 , 0 , sizeof( * V_263 ) ) ;
V_263 -> V_264 . V_265 = V_266 ;
V_263 -> V_264 . V_267 = V_272 ;
V_132 = F_230 ( V_99 , V_7 ) ;
if ( V_132 )
F_36 ( V_7 ) ;
}
bool F_239 ( struct V_6 * V_7 , T_10 V_147 , T_10 V_48 )
{
if ( F_64 ( V_147 > F_101 ( V_7 ) ) ||
F_64 ( ( int ) V_147 + V_48 > F_101 ( V_7 ) - 2 ) ) {
if ( F_240 () )
F_7 ( V_273
L_7 ,
V_147 , V_48 , F_101 ( V_7 ) ) ;
return false ;
}
V_7 -> V_87 = V_123 ;
V_7 -> V_124 = F_82 ( V_7 ) + V_147 ;
V_7 -> V_184 = V_48 ;
return true ;
}
void F_241 ( const struct V_6 * V_7 )
{
if ( F_240 () )
F_242 ( L_8
L_9 , V_7 -> V_16 -> V_17 ) ;
}
