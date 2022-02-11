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
V_13 = F_14 ( V_18 + sizeof( struct V_24 ) ,
V_19 , V_21 ) ;
if ( ! V_13 )
goto V_30;
F_12 ( V_13 + V_18 ) ;
memset ( V_7 , 0 , F_15 ( struct V_6 , V_14 ) ) ;
V_7 -> V_31 = V_18 + sizeof( struct V_6 ) ;
F_16 ( & V_7 -> V_32 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_13 = V_13 ;
F_17 ( V_7 ) ;
V_7 -> V_15 = V_7 -> V_14 + V_18 ;
#ifdef F_18
V_7 -> V_33 = ~ 0U ;
#endif
V_25 = F_19 ( V_7 ) ;
memset ( V_25 , 0 , F_15 ( struct V_24 , V_34 ) ) ;
F_16 ( & V_25 -> V_34 , 1 ) ;
F_20 ( V_25 -> V_35 ) ;
if ( V_20 ) {
struct V_6 * V_36 = V_7 + 1 ;
T_3 * V_37 = ( T_3 * ) ( V_36 + 1 ) ;
F_21 ( V_36 , V_38 ) ;
F_21 ( V_36 , V_39 ) ;
V_7 -> V_20 = V_40 ;
F_16 ( V_37 , 1 ) ;
V_36 -> V_20 = V_41 ;
}
V_29:
return V_7 ;
V_30:
F_22 ( V_23 , V_7 ) ;
V_7 = NULL ;
goto V_29;
}
struct V_6 * F_23 ( struct V_42 * V_16 ,
unsigned int V_43 , T_1 V_19 )
{
struct V_6 * V_7 ;
V_7 = F_10 ( V_43 + V_44 , V_19 , 0 , V_45 ) ;
if ( F_24 ( V_7 ) ) {
F_25 ( V_7 , V_44 ) ;
V_7 -> V_16 = V_16 ;
}
return V_7 ;
}
void F_26 ( struct V_6 * V_7 , int V_46 , struct V_5 * V_5 , int V_47 ,
int V_18 )
{
F_27 ( V_7 , V_46 , V_5 , V_47 , V_18 ) ;
V_7 -> V_11 += V_18 ;
V_7 -> V_48 += V_18 ;
V_7 -> V_31 += V_18 ;
}
struct V_6 * F_28 ( unsigned int V_43 )
{
return F_29 ( V_43 , V_49 ) ;
}
static void F_30 ( struct V_6 * * V_50 )
{
struct V_6 * V_51 = * V_50 ;
* V_50 = NULL ;
do {
struct V_6 * V_52 = V_51 ;
V_51 = V_51 -> V_53 ;
F_31 ( V_52 ) ;
} while ( V_51 );
}
static inline void F_32 ( struct V_6 * V_7 )
{
F_30 ( & F_19 ( V_7 ) -> V_54 ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_6 * V_51 ;
F_34 (skb, list)
F_35 ( V_51 ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_55 ||
! F_37 ( V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ,
& F_19 ( V_7 ) -> V_34 ) ) {
if ( F_19 ( V_7 ) -> V_58 ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ )
F_2 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
}
if ( F_19 ( V_7 ) -> V_60 & V_61 ) {
struct V_62 * V_63 ;
V_63 = F_19 ( V_7 ) -> V_35 ;
if ( V_63 -> V_64 )
V_63 -> V_64 ( V_63 ) ;
}
if ( F_38 ( V_7 ) )
F_32 ( V_7 ) ;
F_39 ( V_7 -> V_12 ) ;
}
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_6 * V_65 ;
T_3 * V_37 ;
switch ( V_7 -> V_20 ) {
case V_41 :
F_22 ( V_27 , V_7 ) ;
break;
case V_40 :
V_37 = ( T_3 * ) ( V_7 + 2 ) ;
if ( F_41 ( V_37 ) )
F_22 ( V_26 , V_7 ) ;
break;
case V_66 :
V_37 = ( T_3 * ) ( V_7 + 1 ) ;
V_65 = V_7 - 1 ;
V_7 -> V_20 = V_41 ;
if ( F_41 ( V_37 ) )
F_22 ( V_26 , V_65 ) ;
break;
}
}
static void F_42 ( struct V_6 * V_7 )
{
F_43 ( V_7 ) ;
#ifdef F_44
F_45 ( V_7 -> V_67 ) ;
#endif
if ( V_7 -> V_68 ) {
F_46 ( F_47 () ) ;
V_7 -> V_68 ( V_7 ) ;
}
#if F_48 ( V_69 ) || F_48 ( V_70 )
F_49 ( V_7 -> V_71 ) ;
#endif
#ifdef F_50
F_51 ( V_7 -> V_72 ) ;
#endif
#ifdef F_52
F_53 ( V_7 -> V_73 ) ;
#endif
#ifdef F_54
V_7 -> V_74 = 0 ;
#ifdef F_55
V_7 -> V_75 = 0 ;
#endif
#endif
}
static void F_56 ( struct V_6 * V_7 )
{
F_42 ( V_7 ) ;
F_36 ( V_7 ) ;
}
void F_57 ( struct V_6 * V_7 )
{
F_56 ( V_7 ) ;
F_40 ( V_7 ) ;
}
void F_31 ( struct V_6 * V_7 )
{
if ( F_58 ( ! V_7 ) )
return;
if ( F_24 ( F_59 ( & V_7 -> V_32 ) == 1 ) )
F_60 () ;
else if ( F_24 ( ! F_41 ( & V_7 -> V_32 ) ) )
return;
F_61 ( V_7 , F_62 ( 0 ) ) ;
F_57 ( V_7 ) ;
}
void F_63 ( struct V_6 * V_7 )
{
if ( F_58 ( ! V_7 ) )
return;
if ( F_24 ( F_59 ( & V_7 -> V_32 ) == 1 ) )
F_60 () ;
else if ( F_24 ( ! F_41 ( & V_7 -> V_32 ) ) )
return;
F_64 ( V_7 ) ;
F_57 ( V_7 ) ;
}
bool F_65 ( struct V_6 * V_7 , int V_76 )
{
struct V_24 * V_25 ;
if ( F_66 () )
return false ;
if ( F_19 ( V_7 ) -> V_60 & V_61 )
return false ;
if ( F_67 ( V_7 ) || V_7 -> V_20 != V_41 )
return false ;
V_76 = F_13 ( V_76 + V_44 ) ;
if ( F_68 ( V_7 ) - V_7 -> V_12 < V_76 )
return false ;
if ( F_69 ( V_7 ) || F_70 ( V_7 ) )
return false ;
F_42 ( V_7 ) ;
V_25 = F_19 ( V_7 ) ;
memset ( V_25 , 0 , F_15 ( struct V_24 , V_34 ) ) ;
F_16 ( & V_25 -> V_34 , 1 ) ;
memset ( V_7 , 0 , F_15 ( struct V_6 , V_14 ) ) ;
V_7 -> V_13 = V_7 -> V_12 + V_44 ;
F_17 ( V_7 ) ;
return true ;
}
static void F_71 ( struct V_6 * V_77 , const struct V_6 * V_78 )
{
V_77 -> V_79 = V_78 -> V_79 ;
V_77 -> V_16 = V_78 -> V_16 ;
V_77 -> V_80 = V_78 -> V_80 ;
V_77 -> V_81 = V_78 -> V_81 ;
V_77 -> V_33 = V_78 -> V_33 ;
F_72 ( V_77 , V_78 ) ;
V_77 -> V_82 = V_78 -> V_82 ;
#ifdef F_44
V_77 -> V_67 = F_73 ( V_78 -> V_67 ) ;
#endif
memcpy ( V_77 -> V_83 , V_78 -> V_83 , sizeof( V_78 -> V_83 ) ) ;
V_77 -> V_84 = V_78 -> V_84 ;
V_77 -> V_85 = V_78 -> V_85 ;
V_77 -> V_86 = V_78 -> V_86 ;
V_77 -> V_87 = V_78 -> V_87 ;
F_74 ( V_77 , V_78 ) ;
V_77 -> V_88 = V_78 -> V_88 ;
#if F_48 ( V_89 ) || F_48 ( V_90 )
V_77 -> V_91 = V_78 -> V_91 ;
#endif
V_77 -> V_92 = V_78 -> V_92 ;
V_77 -> V_93 = V_78 -> V_93 ;
V_77 -> V_94 = V_78 -> V_94 ;
F_75 ( V_77 , V_78 ) ;
#if F_48 ( V_95 ) || \
F_48 ( V_96 )
V_77 -> V_97 = V_78 -> V_97 ;
#endif
#ifdef F_54
V_77 -> V_74 = V_78 -> V_74 ;
#ifdef F_55
V_77 -> V_75 = V_78 -> V_75 ;
#endif
#endif
V_77 -> V_98 = V_78 -> V_98 ;
F_76 ( V_77 , V_78 ) ;
}
static struct V_6 * F_77 ( struct V_6 * V_99 , struct V_6 * V_7 )
{
#define F_78 ( T_4 ) n->x = skb->x
V_99 -> V_53 = V_99 -> V_100 = NULL ;
V_99 -> V_101 = NULL ;
F_71 ( V_99 , V_7 ) ;
F_78 ( V_11 ) ;
F_78 ( V_48 ) ;
F_78 ( V_102 ) ;
V_99 -> V_103 = V_7 -> V_56 ? F_79 ( V_7 ) : V_7 -> V_103 ;
V_99 -> V_55 = 1 ;
V_99 -> V_56 = 0 ;
V_99 -> V_68 = NULL ;
F_78 ( V_14 ) ;
F_78 ( V_15 ) ;
F_78 ( V_12 ) ;
F_78 ( V_13 ) ;
F_78 ( V_31 ) ;
F_16 ( & V_99 -> V_32 , 1 ) ;
F_80 ( & ( F_19 ( V_7 ) -> V_34 ) ) ;
V_7 -> V_55 = 1 ;
return V_99 ;
#undef F_78
}
struct V_6 * F_81 ( struct V_6 * V_104 , struct V_6 * V_105 )
{
F_56 ( V_104 ) ;
return F_77 ( V_104 , V_105 ) ;
}
int F_82 ( struct V_6 * V_7 , T_1 V_19 )
{
int V_46 ;
int V_106 = F_19 ( V_7 ) -> V_58 ;
struct V_5 * V_5 , * V_12 = NULL ;
struct V_62 * V_63 = F_19 ( V_7 ) -> V_35 ;
for ( V_46 = 0 ; V_46 < V_106 ; V_46 ++ ) {
T_2 * V_107 ;
T_5 * V_108 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
V_5 = F_83 ( V_49 ) ;
if ( ! V_5 ) {
while ( V_12 ) {
struct V_5 * V_53 = (struct V_5 * ) V_12 -> V_109 ;
F_2 ( V_12 ) ;
V_12 = V_53 ;
}
return - V_110 ;
}
V_107 = F_84 ( & F_19 ( V_7 ) -> V_59 [ V_46 ] ) ;
memcpy ( F_85 ( V_5 ) ,
V_107 + V_108 -> V_111 , V_108 -> V_18 ) ;
F_86 ( V_107 ) ;
V_5 -> V_109 = ( unsigned long ) V_12 ;
V_12 = V_5 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ )
F_2 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
V_63 -> V_64 ( V_63 ) ;
for ( V_46 = F_19 ( V_7 ) -> V_58 ; V_46 > 0 ; V_46 -- ) {
F_19 ( V_7 ) -> V_59 [ V_46 - 1 ] . V_111 = 0 ;
F_19 ( V_7 ) -> V_59 [ V_46 - 1 ] . V_5 = V_12 ;
V_12 = (struct V_5 * ) V_12 -> V_109 ;
}
F_19 ( V_7 ) -> V_60 &= ~ V_61 ;
return 0 ;
}
struct V_6 * F_87 ( struct V_6 * V_7 , T_1 V_19 )
{
struct V_6 * V_99 ;
if ( F_19 ( V_7 ) -> V_60 & V_61 ) {
if ( F_82 ( V_7 , V_19 ) )
return NULL ;
}
V_99 = V_7 + 1 ;
if ( V_7 -> V_20 == V_40 &&
V_99 -> V_20 == V_41 ) {
T_3 * V_37 = ( T_3 * ) ( V_99 + 1 ) ;
V_99 -> V_20 = V_66 ;
F_80 ( V_37 ) ;
} else {
V_99 = F_88 ( V_27 , V_19 ) ;
if ( ! V_99 )
return NULL ;
F_21 ( V_99 , V_38 ) ;
F_21 ( V_99 , V_39 ) ;
V_99 -> V_20 = V_41 ;
}
return F_77 ( V_99 , V_7 ) ;
}
static void F_89 ( struct V_6 * V_77 , const struct V_6 * V_78 )
{
#ifndef F_18
unsigned long V_112 = V_77 -> V_13 - V_78 -> V_13 ;
#endif
F_71 ( V_77 , V_78 ) ;
#ifndef F_18
V_77 -> V_80 += V_112 ;
V_77 -> V_81 += V_112 ;
if ( F_90 ( V_77 ) )
V_77 -> V_33 += V_112 ;
#endif
F_19 ( V_77 ) -> V_113 = F_19 ( V_78 ) -> V_113 ;
F_19 ( V_77 ) -> V_114 = F_19 ( V_78 ) -> V_114 ;
F_19 ( V_77 ) -> V_115 = F_19 ( V_78 ) -> V_115 ;
}
struct V_6 * F_91 ( const struct V_6 * V_7 , T_1 V_19 )
{
int V_116 = F_79 ( V_7 ) ;
unsigned int V_18 = ( F_68 ( V_7 ) - V_7 -> V_12 ) + V_7 -> V_48 ;
struct V_6 * V_99 = F_92 ( V_18 , V_19 ) ;
if ( ! V_99 )
return NULL ;
F_25 ( V_99 , V_116 ) ;
F_93 ( V_99 , V_7 -> V_11 ) ;
if ( F_94 ( V_7 , - V_116 , V_99 -> V_12 , V_116 + V_7 -> V_11 ) )
F_8 () ;
F_89 ( V_99 , V_7 ) ;
return V_99 ;
}
struct V_6 * F_95 ( struct V_6 * V_7 , T_1 V_19 )
{
unsigned int V_18 = F_68 ( V_7 ) - V_7 -> V_12 ;
struct V_6 * V_99 = F_92 ( V_18 , V_19 ) ;
if ( ! V_99 )
goto V_29;
F_25 ( V_99 , F_79 ( V_7 ) ) ;
F_93 ( V_99 , F_96 ( V_7 ) ) ;
F_97 ( V_7 , V_99 -> V_13 , V_99 -> V_11 ) ;
V_99 -> V_31 += V_7 -> V_48 ;
V_99 -> V_48 = V_7 -> V_48 ;
V_99 -> V_11 = V_7 -> V_11 ;
if ( F_19 ( V_7 ) -> V_58 ) {
int V_46 ;
if ( F_19 ( V_7 ) -> V_60 & V_61 ) {
if ( F_82 ( V_7 , V_19 ) ) {
F_31 ( V_99 ) ;
V_99 = NULL ;
goto V_29;
}
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
F_19 ( V_99 ) -> V_59 [ V_46 ] = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
F_4 ( F_19 ( V_99 ) -> V_59 [ V_46 ] . V_5 ) ;
}
F_19 ( V_99 ) -> V_58 = V_46 ;
}
if ( F_38 ( V_7 ) ) {
F_19 ( V_99 ) -> V_54 = F_19 ( V_7 ) -> V_54 ;
F_33 ( V_99 ) ;
}
F_89 ( V_99 , V_7 ) ;
V_29:
return V_99 ;
}
int F_98 ( struct V_6 * V_7 , int V_117 , int V_118 ,
T_1 V_19 )
{
int V_46 ;
T_2 * V_13 ;
int V_18 = V_117 + ( F_68 ( V_7 ) - V_7 -> V_12 ) + V_118 ;
long V_47 ;
bool V_119 ;
F_99 ( V_117 < 0 ) ;
if ( F_69 ( V_7 ) )
F_8 () ;
V_18 = F_13 ( V_18 ) ;
if ( ! V_7 -> V_55 )
V_119 = true ;
else {
int V_120 = V_7 -> V_56 ? ( 1 << V_57 ) + 1 : 1 ;
V_119 = F_59 ( & F_19 ( V_7 ) -> V_34 ) == V_120 ;
}
if ( V_119 &&
V_18 + sizeof( struct V_24 ) <= F_100 ( V_7 -> V_12 ) ) {
memmove ( V_7 -> V_12 + V_18 , F_19 ( V_7 ) ,
F_15 ( struct V_24 ,
V_59 [ F_19 ( V_7 ) -> V_58 ] ) ) ;
memmove ( V_7 -> V_12 + V_117 , V_7 -> V_12 ,
F_101 ( V_7 ) - V_7 -> V_12 ) ;
V_47 = V_117 ;
goto V_121;
}
V_13 = F_102 ( V_18 + sizeof( struct V_24 ) , V_19 ) ;
if ( ! V_13 )
goto V_30;
memcpy ( V_13 + V_117 , V_7 -> V_12 , F_101 ( V_7 ) - V_7 -> V_12 ) ;
memcpy ( (struct V_24 * ) ( V_13 + V_18 ) ,
F_19 ( V_7 ) ,
F_15 ( struct V_24 , V_59 [ F_19 ( V_7 ) -> V_58 ] ) ) ;
if ( V_119 ) {
F_39 ( V_7 -> V_12 ) ;
} else {
if ( F_19 ( V_7 ) -> V_60 & V_61 ) {
if ( F_82 ( V_7 , V_19 ) )
goto V_122;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ )
F_4 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
if ( F_38 ( V_7 ) )
F_33 ( V_7 ) ;
F_36 ( V_7 ) ;
}
V_47 = ( V_13 + V_117 ) - V_7 -> V_12 ;
V_7 -> V_12 = V_13 ;
V_121:
V_7 -> V_13 += V_47 ;
#ifdef F_18
V_7 -> V_15 = V_18 ;
V_47 = V_117 ;
#else
V_7 -> V_15 = V_7 -> V_12 + V_18 ;
#endif
V_7 -> V_14 += V_47 ;
V_7 -> V_80 += V_47 ;
V_7 -> V_81 += V_47 ;
if ( F_90 ( V_7 ) )
V_7 -> V_33 += V_47 ;
if ( V_7 -> V_87 == V_123 )
V_7 -> V_124 += V_117 ;
V_7 -> V_55 = 0 ;
V_7 -> V_103 = 0 ;
V_7 -> V_56 = 0 ;
F_16 ( & F_19 ( V_7 ) -> V_34 , 1 ) ;
return 0 ;
V_122:
F_39 ( V_13 ) ;
V_30:
return - V_110 ;
}
struct V_6 * F_103 ( struct V_6 * V_7 , unsigned int V_125 )
{
struct V_6 * V_126 ;
int V_120 = V_125 - F_79 ( V_7 ) ;
if ( V_120 <= 0 )
V_126 = F_95 ( V_7 , V_49 ) ;
else {
V_126 = F_87 ( V_7 , V_49 ) ;
if ( V_126 && F_98 ( V_126 , F_13 ( V_120 ) , 0 ,
V_49 ) ) {
F_31 ( V_126 ) ;
V_126 = NULL ;
}
}
return V_126 ;
}
struct V_6 * F_104 ( const struct V_6 * V_7 ,
int V_127 , int V_128 ,
T_1 V_19 )
{
struct V_6 * V_99 = F_92 ( V_127 + V_7 -> V_11 + V_128 ,
V_19 ) ;
int V_129 = F_79 ( V_7 ) ;
int V_130 , V_131 ;
int V_47 ;
if ( ! V_99 )
return NULL ;
F_25 ( V_99 , V_127 ) ;
F_93 ( V_99 , V_7 -> V_11 ) ;
V_130 = V_129 ;
V_131 = 0 ;
if ( V_127 <= V_130 )
V_130 = V_127 ;
else
V_131 = V_127 - V_130 ;
if ( F_94 ( V_7 , - V_130 , V_99 -> V_12 + V_131 ,
V_7 -> V_11 + V_130 ) )
F_8 () ;
F_89 ( V_99 , V_7 ) ;
V_47 = V_127 - V_129 ;
if ( V_99 -> V_87 == V_123 )
V_99 -> V_124 += V_47 ;
#ifdef F_18
V_99 -> V_80 += V_47 ;
V_99 -> V_81 += V_47 ;
if ( F_90 ( V_7 ) )
V_99 -> V_33 += V_47 ;
#endif
return V_99 ;
}
int F_105 ( struct V_6 * V_7 , int V_132 )
{
int V_133 ;
int V_118 ;
if ( ! F_70 ( V_7 ) && F_106 ( V_7 ) >= V_132 ) {
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_132 ) ;
return 0 ;
}
V_118 = V_7 -> V_48 + V_132 - ( V_7 -> V_15 - V_7 -> V_14 ) ;
if ( F_24 ( F_70 ( V_7 ) || V_118 > 0 ) ) {
V_133 = F_98 ( V_7 , 0 , V_118 , V_49 ) ;
if ( F_58 ( V_133 ) )
goto V_134;
}
V_133 = F_107 ( V_7 ) ;
if ( F_58 ( V_133 ) )
goto V_134;
memset ( V_7 -> V_13 + V_7 -> V_11 , 0 , V_132 ) ;
return 0 ;
V_134:
F_31 ( V_7 ) ;
return V_133 ;
}
unsigned char * F_93 ( struct V_6 * V_7 , unsigned int V_11 )
{
unsigned char * V_135 = F_101 ( V_7 ) ;
F_108 ( V_7 ) ;
V_7 -> V_14 += V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_58 ( V_7 -> V_14 > V_7 -> V_15 ) )
F_6 ( V_7 , V_11 , F_62 ( 0 ) ) ;
return V_135 ;
}
unsigned char * F_109 ( struct V_6 * V_7 , unsigned int V_11 )
{
V_7 -> V_13 -= V_11 ;
V_7 -> V_11 += V_11 ;
if ( F_58 ( V_7 -> V_13 < V_7 -> V_12 ) )
F_9 ( V_7 , V_11 , F_62 ( 0 ) ) ;
return V_7 -> V_13 ;
}
unsigned char * F_110 ( struct V_6 * V_7 , unsigned int V_11 )
{
return F_111 ( V_7 , V_11 ) ;
}
void F_112 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( V_7 -> V_11 > V_11 )
F_113 ( V_7 , V_11 ) ;
}
int F_114 ( struct V_6 * V_7 , unsigned int V_11 )
{
struct V_6 * * V_136 ;
struct V_6 * V_137 ;
int V_112 = F_96 ( V_7 ) ;
int V_138 = F_19 ( V_7 ) -> V_58 ;
int V_46 ;
int V_133 ;
if ( F_70 ( V_7 ) &&
F_58 ( ( V_133 = F_98 ( V_7 , 0 , 0 , V_49 ) ) ) )
return V_133 ;
V_46 = 0 ;
if ( V_112 >= V_11 )
goto V_139;
for (; V_46 < V_138 ; V_46 ++ ) {
int V_15 = V_112 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( V_15 < V_11 ) {
V_112 = V_15 ;
continue;
}
F_19 ( V_7 ) -> V_59 [ V_46 ++ ] . V_18 = V_11 - V_112 ;
V_139:
F_19 ( V_7 ) -> V_58 = V_46 ;
for (; V_46 < V_138 ; V_46 ++ )
F_2 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
if ( F_38 ( V_7 ) )
F_32 ( V_7 ) ;
goto V_140;
}
for ( V_136 = & F_19 ( V_7 ) -> V_54 ; ( V_137 = * V_136 ) ;
V_136 = & V_137 -> V_53 ) {
int V_15 = V_112 + V_137 -> V_11 ;
if ( F_69 ( V_137 ) ) {
struct V_6 * V_141 ;
V_141 = F_87 ( V_137 , V_49 ) ;
if ( F_58 ( ! V_141 ) )
return - V_110 ;
V_141 -> V_53 = V_137 -> V_53 ;
F_31 ( V_137 ) ;
V_137 = V_141 ;
* V_136 = V_137 ;
}
if ( V_15 < V_11 ) {
V_112 = V_15 ;
continue;
}
if ( V_15 > V_11 &&
F_58 ( ( V_133 = F_115 ( V_137 , V_11 - V_112 ) ) ) )
return V_133 ;
if ( V_137 -> V_53 )
F_30 ( & V_137 -> V_53 ) ;
break;
}
V_140:
if ( V_11 > F_96 ( V_7 ) ) {
V_7 -> V_48 -= V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
} else {
V_7 -> V_11 = V_11 ;
V_7 -> V_48 = 0 ;
F_116 ( V_7 , V_11 ) ;
}
return 0 ;
}
unsigned char * F_117 ( struct V_6 * V_7 , int V_120 )
{
int V_46 , V_142 , V_143 = ( V_7 -> V_14 + V_120 ) - V_7 -> V_15 ;
if ( V_143 > 0 || F_70 ( V_7 ) ) {
if ( F_98 ( V_7 , 0 , V_143 > 0 ? V_143 + 128 : 0 ,
V_49 ) )
return NULL ;
}
if ( F_94 ( V_7 , F_96 ( V_7 ) , F_101 ( V_7 ) , V_120 ) )
F_8 () ;
if ( ! F_38 ( V_7 ) )
goto V_144;
V_143 = V_120 ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
if ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 >= V_143 )
goto V_144;
V_143 -= F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
}
if ( V_143 ) {
struct V_6 * V_51 = F_19 ( V_7 ) -> V_54 ;
struct V_6 * V_145 = NULL ;
struct V_6 * V_146 = NULL ;
do {
F_99 ( ! V_51 ) ;
if ( V_51 -> V_11 <= V_143 ) {
V_143 -= V_51 -> V_11 ;
V_51 = V_51 -> V_53 ;
V_146 = V_51 ;
} else {
if ( F_69 ( V_51 ) ) {
V_145 = F_87 ( V_51 , V_49 ) ;
if ( ! V_145 )
return NULL ;
V_146 = V_51 -> V_53 ;
V_51 = V_145 ;
} else {
V_146 = V_51 ;
}
if ( ! F_118 ( V_51 , V_143 ) ) {
F_31 ( V_145 ) ;
return NULL ;
}
break;
}
} while ( V_143 );
while ( ( V_51 = F_19 ( V_7 ) -> V_54 ) != V_146 ) {
F_19 ( V_7 ) -> V_54 = V_51 -> V_53 ;
F_31 ( V_51 ) ;
}
if ( V_145 ) {
V_145 -> V_53 = V_51 ;
F_19 ( V_7 ) -> V_54 = V_145 ;
}
}
V_144:
V_143 = V_120 ;
V_142 = 0 ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
if ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 <= V_143 ) {
F_2 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
V_143 -= F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
} else {
F_19 ( V_7 ) -> V_59 [ V_142 ] = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_143 ) {
F_19 ( V_7 ) -> V_59 [ V_142 ] . V_111 += V_143 ;
F_19 ( V_7 ) -> V_59 [ V_142 ] . V_18 -= V_143 ;
V_143 = 0 ;
}
V_142 ++ ;
}
}
F_19 ( V_7 ) -> V_58 = V_142 ;
V_7 -> V_14 += V_120 ;
V_7 -> V_48 -= V_120 ;
return F_101 ( V_7 ) ;
}
int F_94 ( const struct V_6 * V_7 , int V_112 , void * V_147 , int V_11 )
{
int V_148 = F_96 ( V_7 ) ;
struct V_6 * V_149 ;
int V_46 , V_150 ;
if ( V_112 > ( int ) V_7 -> V_11 - V_11 )
goto V_151;
if ( ( V_150 = V_148 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
F_119 ( V_7 , V_112 , V_147 , V_150 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_147 += V_150 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_2 * V_107 ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_107 = F_84 ( & F_19 ( V_7 ) -> V_59 [ V_46 ] ) ;
memcpy ( V_147 ,
V_107 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_111 +
V_112 - V_148 , V_150 ) ;
F_86 ( V_107 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_147 += V_150 ;
}
V_148 = V_15 ;
}
F_34 (skb, frag_iter) {
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
if ( F_94 ( V_149 , V_112 - V_148 , V_147 , V_150 ) )
goto V_151;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_147 += V_150 ;
}
V_148 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_151:
return - V_152 ;
}
static void F_120 ( struct V_153 * V_154 , unsigned int V_46 )
{
F_2 ( V_154 -> V_155 [ V_46 ] ) ;
}
static inline struct V_5 * F_121 ( struct V_5 * V_5 , unsigned int * V_11 ,
unsigned int * V_112 ,
struct V_6 * V_7 , struct V_156 * V_101 )
{
struct V_5 * V_157 = V_101 -> V_158 ;
unsigned int V_47 ;
if ( ! V_157 ) {
V_159:
V_157 = V_101 -> V_158 = F_122 ( V_101 -> V_160 , 0 ) ;
if ( ! V_157 )
return NULL ;
V_47 = V_101 -> V_161 = 0 ;
} else {
unsigned int V_162 ;
V_47 = V_101 -> V_161 ;
V_162 = V_163 - V_47 ;
if ( V_162 < 64 && V_162 < * V_11 ) {
F_2 ( V_157 ) ;
goto V_159;
}
* V_11 = F_123 (unsigned int, *len, mlen) ;
}
memcpy ( F_85 ( V_157 ) + V_47 , F_85 ( V_5 ) + * V_112 , * V_11 ) ;
V_101 -> V_161 += * V_11 ;
* V_112 = V_47 ;
F_4 ( V_157 ) ;
return V_157 ;
}
static inline int F_124 ( struct V_153 * V_154 ,
struct V_1 * V_2 , struct V_5 * V_5 ,
unsigned int * V_11 , unsigned int V_112 ,
struct V_6 * V_7 , int V_164 ,
struct V_156 * V_101 )
{
if ( F_58 ( V_154 -> V_165 == V_2 -> V_166 ) )
return 1 ;
if ( V_164 ) {
V_5 = F_121 ( V_5 , V_11 , & V_112 , V_7 , V_101 ) ;
if ( ! V_5 )
return 1 ;
} else
F_4 ( V_5 ) ;
V_154 -> V_155 [ V_154 -> V_165 ] = V_5 ;
V_154 -> V_167 [ V_154 -> V_165 ] . V_11 = * V_11 ;
V_154 -> V_167 [ V_154 -> V_165 ] . V_112 = V_112 ;
V_154 -> V_165 ++ ;
return 0 ;
}
static inline void F_125 ( struct V_5 * * V_5 , unsigned int * V_168 ,
unsigned int * V_169 , unsigned int V_47 )
{
unsigned long V_99 ;
* V_168 += V_47 ;
V_99 = * V_168 / V_163 ;
if ( V_99 )
* V_5 = F_126 ( * V_5 , V_99 ) ;
* V_168 = * V_168 % V_163 ;
* V_169 -= V_47 ;
}
static inline int F_127 ( struct V_5 * V_5 , unsigned int V_168 ,
unsigned int V_169 , unsigned int * V_47 ,
unsigned int * V_11 , struct V_6 * V_7 ,
struct V_153 * V_154 , int V_164 ,
struct V_156 * V_101 ,
struct V_1 * V_2 )
{
if ( ! * V_11 )
return 1 ;
if ( * V_47 >= V_169 ) {
* V_47 -= V_169 ;
return 0 ;
}
if ( * V_47 ) {
F_125 ( & V_5 , & V_168 , & V_169 , * V_47 ) ;
* V_47 = 0 ;
}
do {
unsigned int V_170 = F_128 ( * V_11 , V_169 ) ;
V_170 = F_123 (unsigned int, flen, PAGE_SIZE - poff) ;
if ( F_124 ( V_154 , V_2 , V_5 , & V_170 , V_168 , V_7 , V_164 , V_101 ) )
return 1 ;
F_125 ( & V_5 , & V_168 , & V_169 , V_170 ) ;
* V_11 -= V_170 ;
} while ( * V_11 && V_169 );
return 0 ;
}
static int F_129 ( struct V_6 * V_7 , struct V_1 * V_2 ,
unsigned int * V_112 , unsigned int * V_11 ,
struct V_153 * V_154 , struct V_156 * V_101 )
{
int V_171 ;
if ( F_127 ( F_130 ( V_7 -> V_13 ) ,
( unsigned long ) V_7 -> V_13 & ( V_163 - 1 ) ,
F_96 ( V_7 ) ,
V_112 , V_11 , V_7 , V_154 , 1 , V_101 , V_2 ) )
return 1 ;
for ( V_171 = 0 ; V_171 < F_19 ( V_7 ) -> V_58 ; V_171 ++ ) {
const T_5 * V_108 = & F_19 ( V_7 ) -> V_59 [ V_171 ] ;
if ( F_127 ( V_108 -> V_5 , V_108 -> V_111 , V_108 -> V_18 ,
V_112 , V_11 , V_7 , V_154 , 0 , V_101 , V_2 ) )
return 1 ;
}
return 0 ;
}
int F_131 ( struct V_6 * V_7 , unsigned int V_112 ,
struct V_1 * V_2 , unsigned int V_172 ,
unsigned int V_173 )
{
struct V_174 V_167 [ V_175 ] ;
struct V_5 * V_155 [ V_175 ] ;
struct V_153 V_154 = {
. V_155 = V_155 ,
. V_167 = V_167 ,
. V_173 = V_173 ,
. V_176 = & V_177 ,
. V_178 = F_120 ,
} ;
struct V_6 * V_149 ;
struct V_156 * V_101 = V_7 -> V_101 ;
int V_179 = 0 ;
if ( F_132 ( V_2 , & V_154 ) )
return - V_110 ;
if ( F_129 ( V_7 , V_2 , & V_112 , & V_172 , & V_154 , V_101 ) )
goto V_140;
else if ( ! V_172 )
goto V_140;
F_34 (skb, frag_iter) {
if ( ! V_172 )
break;
if ( F_129 ( V_149 , V_2 , & V_112 , & V_172 , & V_154 , V_101 ) )
break;
}
V_140:
if ( V_154 . V_165 ) {
F_133 ( V_101 ) ;
V_179 = F_134 ( V_2 , & V_154 ) ;
F_135 ( V_101 ) ;
}
F_136 ( V_2 , & V_154 ) ;
return V_179 ;
}
int F_137 ( struct V_6 * V_7 , int V_112 , const void * V_180 , int V_11 )
{
int V_148 = F_96 ( V_7 ) ;
struct V_6 * V_149 ;
int V_46 , V_150 ;
if ( V_112 > ( int ) V_7 -> V_11 - V_11 )
goto V_151;
if ( ( V_150 = V_148 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
F_138 ( V_7 , V_112 , V_180 , V_150 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_180 += V_150 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
T_5 * V_137 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_137 -> V_18 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_2 * V_107 ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_107 = F_84 ( V_137 ) ;
memcpy ( V_107 + V_137 -> V_111 + V_112 - V_148 ,
V_180 , V_150 ) ;
F_86 ( V_107 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_180 += V_150 ;
}
V_148 = V_15 ;
}
F_34 (skb, frag_iter) {
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
if ( F_137 ( V_149 , V_112 - V_148 ,
V_180 , V_150 ) )
goto V_151;
if ( ( V_11 -= V_150 ) == 0 )
return 0 ;
V_112 += V_150 ;
V_180 += V_150 ;
}
V_148 = V_15 ;
}
if ( ! V_11 )
return 0 ;
V_151:
return - V_152 ;
}
T_6 F_139 ( const struct V_6 * V_7 , int V_112 ,
int V_11 , T_6 V_84 )
{
int V_148 = F_96 ( V_7 ) ;
int V_46 , V_150 = V_148 - V_112 ;
struct V_6 * V_149 ;
int V_181 = 0 ;
if ( V_150 > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
V_84 = F_140 ( V_7 -> V_13 + V_112 , V_150 , V_84 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_84 ;
V_112 += V_150 ;
V_181 = V_150 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_6 V_182 ;
T_2 * V_107 ;
T_5 * V_137 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_107 = F_84 ( V_137 ) ;
V_182 = F_140 ( V_107 + V_137 -> V_111 +
V_112 - V_148 , V_150 , 0 ) ;
F_86 ( V_107 ) ;
V_84 = F_141 ( V_84 , V_182 , V_181 ) ;
if ( ! ( V_11 -= V_150 ) )
return V_84 ;
V_112 += V_150 ;
V_181 += V_150 ;
}
V_148 = V_15 ;
}
F_34 (skb, frag_iter) {
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_6 V_182 ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_182 = F_139 ( V_149 , V_112 - V_148 ,
V_150 , 0 ) ;
V_84 = F_141 ( V_84 , V_182 , V_181 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_84 ;
V_112 += V_150 ;
V_181 += V_150 ;
}
V_148 = V_15 ;
}
F_99 ( V_11 ) ;
return V_84 ;
}
T_6 F_142 ( const struct V_6 * V_7 , int V_112 ,
T_2 * V_147 , int V_11 , T_6 V_84 )
{
int V_148 = F_96 ( V_7 ) ;
int V_46 , V_150 = V_148 - V_112 ;
struct V_6 * V_149 ;
int V_181 = 0 ;
if ( V_150 > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
V_84 = F_143 ( V_7 -> V_13 + V_112 , V_147 ,
V_150 , V_84 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_84 ;
V_112 += V_150 ;
V_147 += V_150 ;
V_181 = V_150 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_6 V_182 ;
T_2 * V_107 ;
T_5 * V_137 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_150 > V_11 )
V_150 = V_11 ;
V_107 = F_84 ( V_137 ) ;
V_182 = F_143 ( V_107 +
V_137 -> V_111 +
V_112 - V_148 , V_147 ,
V_150 , 0 ) ;
F_86 ( V_107 ) ;
V_84 = F_141 ( V_84 , V_182 , V_181 ) ;
if ( ! ( V_11 -= V_150 ) )
return V_84 ;
V_112 += V_150 ;
V_147 += V_150 ;
V_181 += V_150 ;
}
V_148 = V_15 ;
}
F_34 (skb, frag_iter) {
T_6 V_182 ;
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
V_182 = F_142 ( V_149 ,
V_112 - V_148 ,
V_147 , V_150 , 0 ) ;
V_84 = F_141 ( V_84 , V_182 , V_181 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_84 ;
V_112 += V_150 ;
V_147 += V_150 ;
V_181 += V_150 ;
}
V_148 = V_15 ;
}
F_99 ( V_11 ) ;
return V_84 ;
}
void F_144 ( const struct V_6 * V_7 , T_2 * V_147 )
{
T_6 V_84 ;
long V_183 ;
if ( V_7 -> V_87 == V_123 )
V_183 = F_145 ( V_7 ) ;
else
V_183 = F_96 ( V_7 ) ;
F_99 ( V_183 > F_96 ( V_7 ) ) ;
F_97 ( V_7 , V_147 , V_183 ) ;
V_84 = 0 ;
if ( V_183 != V_7 -> V_11 )
V_84 = F_142 ( V_7 , V_183 , V_147 + V_183 ,
V_7 -> V_11 - V_183 , 0 ) ;
if ( V_7 -> V_87 == V_123 ) {
long V_184 = V_183 + V_7 -> V_185 ;
* ( ( V_186 * ) ( V_147 + V_184 ) ) = F_146 ( V_84 ) ;
}
}
struct V_6 * F_147 ( struct V_187 * V_51 )
{
unsigned long V_173 ;
struct V_6 * V_188 ;
F_148 ( & V_51 -> V_189 , V_173 ) ;
V_188 = F_149 ( V_51 ) ;
F_150 ( & V_51 -> V_189 , V_173 ) ;
return V_188 ;
}
struct V_6 * F_151 ( struct V_187 * V_51 )
{
unsigned long V_173 ;
struct V_6 * V_188 ;
F_148 ( & V_51 -> V_189 , V_173 ) ;
V_188 = F_152 ( V_51 ) ;
F_150 ( & V_51 -> V_189 , V_173 ) ;
return V_188 ;
}
void F_153 ( struct V_187 * V_51 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_147 ( V_51 ) ) != NULL )
F_31 ( V_7 ) ;
}
void F_154 ( struct V_187 * V_51 , struct V_6 * V_190 )
{
unsigned long V_173 ;
F_148 ( & V_51 -> V_189 , V_173 ) ;
F_155 ( V_51 , V_190 ) ;
F_150 ( & V_51 -> V_189 , V_173 ) ;
}
void F_156 ( struct V_187 * V_51 , struct V_6 * V_190 )
{
unsigned long V_173 ;
F_148 ( & V_51 -> V_189 , V_173 ) ;
F_157 ( V_51 , V_190 ) ;
F_150 ( & V_51 -> V_189 , V_173 ) ;
}
void F_158 ( struct V_6 * V_7 , struct V_187 * V_51 )
{
unsigned long V_173 ;
F_148 ( & V_51 -> V_189 , V_173 ) ;
F_159 ( V_7 , V_51 ) ;
F_150 ( & V_51 -> V_189 , V_173 ) ;
}
void F_160 ( struct V_6 * V_78 , struct V_6 * V_190 , struct V_187 * V_51 )
{
unsigned long V_173 ;
F_148 ( & V_51 -> V_189 , V_173 ) ;
F_161 ( V_51 , V_78 , V_190 ) ;
F_150 ( & V_51 -> V_189 , V_173 ) ;
}
void F_162 ( struct V_6 * V_78 , struct V_6 * V_190 , struct V_187 * V_51 )
{
unsigned long V_173 ;
F_148 ( & V_51 -> V_189 , V_173 ) ;
F_163 ( V_190 , V_78 -> V_100 , V_78 , V_51 ) ;
F_150 ( & V_51 -> V_189 , V_173 ) ;
}
static inline void F_164 ( struct V_6 * V_7 ,
struct V_6 * V_191 ,
const T_7 V_11 , const int V_181 )
{
int V_46 ;
F_119 ( V_7 , V_11 , F_93 ( V_191 , V_181 - V_11 ) ,
V_181 - V_11 ) ;
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ )
F_19 ( V_191 ) -> V_59 [ V_46 ] = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
F_19 ( V_191 ) -> V_58 = F_19 ( V_7 ) -> V_58 ;
F_19 ( V_7 ) -> V_58 = 0 ;
V_191 -> V_48 = V_7 -> V_48 ;
V_191 -> V_11 += V_191 -> V_48 ;
V_7 -> V_48 = 0 ;
V_7 -> V_11 = V_11 ;
F_116 ( V_7 , V_11 ) ;
}
static inline void F_165 ( struct V_6 * V_7 ,
struct V_6 * V_191 ,
const T_7 V_11 , int V_181 )
{
int V_46 , V_142 = 0 ;
const int V_138 = F_19 ( V_7 ) -> V_58 ;
F_19 ( V_7 ) -> V_58 = 0 ;
V_191 -> V_11 = V_191 -> V_48 = V_7 -> V_11 - V_11 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_48 = V_11 - V_181 ;
for ( V_46 = 0 ; V_46 < V_138 ; V_46 ++ ) {
int V_18 = F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( V_181 + V_18 > V_11 ) {
F_19 ( V_191 ) -> V_59 [ V_142 ] = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_181 < V_11 ) {
F_4 ( F_19 ( V_7 ) -> V_59 [ V_46 ] . V_5 ) ;
F_19 ( V_191 ) -> V_59 [ 0 ] . V_111 += V_11 - V_181 ;
F_19 ( V_191 ) -> V_59 [ 0 ] . V_18 -= V_11 - V_181 ;
F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 = V_11 - V_181 ;
F_19 ( V_7 ) -> V_58 ++ ;
}
V_142 ++ ;
} else
F_19 ( V_7 ) -> V_58 ++ ;
V_181 += V_18 ;
}
F_19 ( V_191 ) -> V_58 = V_142 ;
}
void F_166 ( struct V_6 * V_7 , struct V_6 * V_191 , const T_7 V_11 )
{
int V_181 = F_96 ( V_7 ) ;
if ( V_11 < V_181 )
F_164 ( V_7 , V_191 , V_11 , V_181 ) ;
else
F_165 ( V_7 , V_191 , V_11 , V_181 ) ;
}
static int F_167 ( struct V_6 * V_7 )
{
return F_70 ( V_7 ) && F_98 ( V_7 , 0 , 0 , V_49 ) ;
}
int F_168 ( struct V_6 * V_192 , struct V_6 * V_7 , int V_193 )
{
int V_180 , V_147 , V_194 , V_195 ;
struct V_196 * V_197 , * V_198 ;
F_99 ( V_193 > V_7 -> V_11 ) ;
F_99 ( F_96 ( V_7 ) ) ;
V_195 = V_193 ;
V_180 = 0 ;
V_147 = F_19 ( V_192 ) -> V_58 ;
V_197 = & F_19 ( V_7 ) -> V_59 [ V_180 ] ;
if ( ! V_147 ||
! F_169 ( V_192 , V_147 , V_197 -> V_5 , V_197 -> V_111 ) ) {
V_194 = - 1 ;
} else {
V_194 = V_147 - 1 ;
V_195 -= V_197 -> V_18 ;
if ( V_195 < 0 ) {
if ( F_167 ( V_7 ) ||
F_167 ( V_192 ) )
return 0 ;
V_197 = & F_19 ( V_7 ) -> V_59 [ V_180 ] ;
V_198 = & F_19 ( V_192 ) -> V_59 [ V_194 ] ;
V_198 -> V_18 += V_193 ;
V_197 -> V_18 -= V_193 ;
V_197 -> V_111 += V_193 ;
goto V_199;
}
V_180 ++ ;
}
if ( ( V_193 == V_7 -> V_11 ) &&
( F_19 ( V_7 ) -> V_58 - V_180 ) > ( V_200 - V_147 ) )
return 0 ;
if ( F_167 ( V_7 ) || F_167 ( V_192 ) )
return 0 ;
while ( ( V_195 > 0 ) && ( V_180 < F_19 ( V_7 ) -> V_58 ) ) {
if ( V_147 == V_200 )
return 0 ;
V_197 = & F_19 ( V_7 ) -> V_59 [ V_180 ] ;
V_198 = & F_19 ( V_192 ) -> V_59 [ V_147 ] ;
if ( V_195 >= V_197 -> V_18 ) {
* V_198 = * V_197 ;
V_195 -= V_197 -> V_18 ;
V_180 ++ ;
V_147 ++ ;
} else {
F_4 ( V_197 -> V_5 ) ;
V_198 -> V_5 = V_197 -> V_5 ;
V_198 -> V_111 = V_197 -> V_111 ;
V_198 -> V_18 = V_195 ;
V_197 -> V_111 += V_195 ;
V_197 -> V_18 -= V_195 ;
V_195 = 0 ;
V_147 ++ ;
break;
}
}
F_19 ( V_192 ) -> V_58 = V_147 ;
if ( V_194 >= 0 ) {
V_197 = & F_19 ( V_7 ) -> V_59 [ 0 ] ;
V_198 = & F_19 ( V_192 ) -> V_59 [ V_194 ] ;
V_198 -> V_18 += V_197 -> V_18 ;
F_2 ( V_197 -> V_5 ) ;
}
V_147 = 0 ;
while ( V_180 < F_19 ( V_7 ) -> V_58 )
F_19 ( V_7 ) -> V_59 [ V_147 ++ ] = F_19 ( V_7 ) -> V_59 [ V_180 ++ ] ;
F_19 ( V_7 ) -> V_58 = V_147 ;
F_99 ( V_195 > 0 && ! F_19 ( V_7 ) -> V_58 ) ;
V_199:
V_192 -> V_87 = V_123 ;
V_7 -> V_87 = V_123 ;
V_7 -> V_11 -= V_193 ;
V_7 -> V_48 -= V_193 ;
V_7 -> V_31 -= V_193 ;
V_192 -> V_11 += V_193 ;
V_192 -> V_48 += V_193 ;
V_192 -> V_31 += V_193 ;
return V_193 ;
}
void F_170 ( struct V_6 * V_7 , unsigned int V_180 ,
unsigned int V_147 , struct V_201 * V_202 )
{
V_202 -> V_203 = V_180 ;
V_202 -> V_204 = V_147 ;
V_202 -> V_205 = V_202 -> V_206 = V_7 ;
V_202 -> V_207 = V_202 -> V_208 = 0 ;
V_202 -> V_209 = NULL ;
}
unsigned int F_171 ( unsigned int V_210 , const T_2 * * V_13 ,
struct V_201 * V_202 )
{
unsigned int V_211 , V_212 = V_210 + V_202 -> V_203 ;
T_5 * V_137 ;
if ( F_58 ( V_212 >= V_202 -> V_204 ) )
return 0 ;
V_213:
V_211 = F_96 ( V_202 -> V_206 ) + V_202 -> V_208 ;
if ( V_212 < V_211 && ! V_202 -> V_209 ) {
* V_13 = V_202 -> V_206 -> V_13 + ( V_212 - V_202 -> V_208 ) ;
return V_211 - V_212 ;
}
if ( V_202 -> V_207 == 0 && ! V_202 -> V_209 )
V_202 -> V_208 += F_96 ( V_202 -> V_206 ) ;
while ( V_202 -> V_207 < F_19 ( V_202 -> V_206 ) -> V_58 ) {
V_137 = & F_19 ( V_202 -> V_206 ) -> V_59 [ V_202 -> V_207 ] ;
V_211 = V_137 -> V_18 + V_202 -> V_208 ;
if ( V_212 < V_211 ) {
if ( ! V_202 -> V_209 )
V_202 -> V_209 = F_84 ( V_137 ) ;
* V_13 = ( T_2 * ) V_202 -> V_209 + V_137 -> V_111 +
( V_212 - V_202 -> V_208 ) ;
return V_211 - V_212 ;
}
if ( V_202 -> V_209 ) {
F_86 ( V_202 -> V_209 ) ;
V_202 -> V_209 = NULL ;
}
V_202 -> V_207 ++ ;
V_202 -> V_208 += V_137 -> V_18 ;
}
if ( V_202 -> V_209 ) {
F_86 ( V_202 -> V_209 ) ;
V_202 -> V_209 = NULL ;
}
if ( V_202 -> V_205 == V_202 -> V_206 && F_38 ( V_202 -> V_205 ) ) {
V_202 -> V_206 = F_19 ( V_202 -> V_205 ) -> V_54 ;
V_202 -> V_207 = 0 ;
goto V_213;
} else if ( V_202 -> V_206 -> V_53 ) {
V_202 -> V_206 = V_202 -> V_206 -> V_53 ;
V_202 -> V_207 = 0 ;
goto V_213;
}
return 0 ;
}
void F_172 ( struct V_201 * V_202 )
{
if ( V_202 -> V_209 )
F_86 ( V_202 -> V_209 ) ;
}
static unsigned int F_173 ( unsigned int V_112 , const T_2 * * V_214 ,
struct V_215 * V_216 ,
struct V_217 * V_218 )
{
return F_171 ( V_112 , V_214 , F_174 ( V_218 ) ) ;
}
static void F_175 ( struct V_215 * V_216 , struct V_217 * V_218 )
{
F_172 ( F_174 ( V_218 ) ) ;
}
unsigned int F_176 ( struct V_6 * V_7 , unsigned int V_180 ,
unsigned int V_147 , struct V_215 * V_219 ,
struct V_217 * V_218 )
{
unsigned int V_179 ;
V_219 -> V_220 = F_173 ;
V_219 -> V_221 = F_175 ;
F_170 ( V_7 , V_180 , V_147 , F_174 ( V_218 ) ) ;
V_179 = F_177 ( V_219 , V_218 ) ;
return ( V_179 <= V_147 - V_180 ? V_179 : V_222 ) ;
}
int F_178 ( struct V_156 * V_101 , struct V_6 * V_7 ,
int (* F_179)( void * V_180 , char * V_147 , int V_112 ,
int V_11 , int V_223 , struct V_6 * V_7 ) ,
void * V_180 , int V_43 )
{
int V_224 = 0 ;
T_5 * V_137 = NULL ;
struct V_5 * V_5 = NULL ;
int V_150 , V_225 ;
int V_112 = 0 ;
int V_179 ;
do {
V_224 = F_19 ( V_7 ) -> V_58 ;
if ( V_224 >= V_200 )
return - V_152 ;
V_5 = F_122 ( V_101 -> V_160 , 0 ) ;
if ( V_5 == NULL )
return - V_110 ;
F_27 ( V_7 , V_224 , V_5 , 0 , 0 ) ;
V_7 -> V_31 += V_163 ;
F_180 ( V_163 , & V_101 -> V_226 ) ;
V_224 = F_19 ( V_7 ) -> V_58 ;
V_137 = & F_19 ( V_7 ) -> V_59 [ V_224 - 1 ] ;
V_225 = V_163 - V_137 -> V_111 ;
V_150 = ( V_43 > V_225 ) ? V_225 : V_43 ;
V_179 = F_179 ( V_180 , ( F_85 ( V_137 -> V_5 ) +
V_137 -> V_111 + V_137 -> V_18 ) ,
V_112 , V_150 , 0 , V_7 ) ;
if ( V_179 < 0 )
return - V_152 ;
V_137 -> V_18 += V_150 ;
V_7 -> V_11 += V_150 ;
V_7 -> V_48 += V_150 ;
V_112 += V_150 ;
V_43 -= V_150 ;
} while ( V_43 > 0 );
return 0 ;
}
unsigned char * F_181 ( struct V_6 * V_7 , unsigned int V_11 )
{
F_99 ( V_11 > V_7 -> V_11 ) ;
V_7 -> V_11 -= V_11 ;
F_99 ( V_7 -> V_11 < V_7 -> V_48 ) ;
F_182 ( V_7 , V_7 -> V_13 , V_11 ) ;
return V_7 -> V_13 += V_11 ;
}
struct V_6 * F_183 ( struct V_6 * V_7 , T_7 V_227 )
{
struct V_6 * V_228 = NULL ;
struct V_6 * V_14 = NULL ;
struct V_6 * V_229 = F_19 ( V_7 ) -> V_54 ;
unsigned int V_230 = F_19 ( V_7 ) -> V_113 ;
unsigned int V_231 = V_7 -> V_13 - F_184 ( V_7 ) ;
unsigned int V_112 = V_231 ;
unsigned int V_125 ;
unsigned int V_11 ;
int V_232 = ! ! ( V_227 & V_233 ) ;
int V_138 = F_19 ( V_7 ) -> V_58 ;
int V_133 = - V_110 ;
int V_46 = 0 ;
int V_181 ;
F_185 ( V_7 , V_231 ) ;
V_125 = F_79 ( V_7 ) ;
V_181 = F_96 ( V_7 ) ;
do {
struct V_6 * V_234 ;
T_5 * V_137 ;
int V_235 ;
int V_18 ;
V_11 = V_7 -> V_11 - V_112 ;
if ( V_11 > V_230 )
V_11 = V_230 ;
V_235 = F_96 ( V_7 ) - V_112 ;
if ( V_235 < 0 )
V_235 = 0 ;
if ( V_235 > V_11 || ! V_232 )
V_235 = V_11 ;
if ( ! V_235 && V_46 >= V_138 ) {
F_99 ( V_229 -> V_11 != V_11 ) ;
V_181 += V_11 ;
V_234 = F_87 ( V_229 , V_49 ) ;
V_229 = V_229 -> V_53 ;
if ( F_58 ( ! V_234 ) )
goto V_133;
V_235 = F_68 ( V_234 ) - V_234 -> V_12 ;
if ( F_186 ( V_234 , V_231 + V_125 ) ) {
F_31 ( V_234 ) ;
goto V_133;
}
V_234 -> V_31 += F_68 ( V_234 ) - V_234 -> V_12 -
V_235 ;
F_42 ( V_234 ) ;
F_185 ( V_234 , V_231 ) ;
} else {
V_234 = F_92 ( V_235 + V_231 + V_125 ,
V_49 ) ;
if ( F_58 ( ! V_234 ) )
goto V_133;
F_25 ( V_234 , V_125 ) ;
F_187 ( V_234 , V_231 ) ;
}
if ( V_228 )
V_14 -> V_53 = V_234 ;
else
V_228 = V_234 ;
V_14 = V_234 ;
F_71 ( V_234 , V_7 ) ;
V_234 -> V_102 = V_7 -> V_102 ;
if ( V_234 -> V_87 == V_123 )
V_234 -> V_124 += F_79 ( V_234 ) - V_125 ;
F_188 ( V_234 ) ;
F_189 ( V_234 , V_7 -> V_102 ) ;
V_234 -> V_80 = ( V_234 -> V_81 +
F_190 ( V_7 ) ) ;
F_97 ( V_7 , V_234 -> V_13 , V_231 ) ;
if ( V_229 != F_19 ( V_7 ) -> V_54 )
continue;
if ( ! V_232 ) {
V_234 -> V_87 = V_236 ;
V_234 -> V_84 = F_142 ( V_7 , V_112 ,
F_93 ( V_234 , V_11 ) ,
V_11 , 0 ) ;
continue;
}
V_137 = F_19 ( V_234 ) -> V_59 ;
F_119 ( V_7 , V_112 ,
F_93 ( V_234 , V_235 ) , V_235 ) ;
while ( V_181 < V_112 + V_11 && V_46 < V_138 ) {
* V_137 = F_19 ( V_7 ) -> V_59 [ V_46 ] ;
F_4 ( V_137 -> V_5 ) ;
V_18 = V_137 -> V_18 ;
if ( V_181 < V_112 ) {
V_137 -> V_111 += V_112 - V_181 ;
V_137 -> V_18 -= V_112 - V_181 ;
}
F_19 ( V_234 ) -> V_58 ++ ;
if ( V_181 + V_18 <= V_112 + V_11 ) {
V_46 ++ ;
V_181 += V_18 ;
} else {
V_137 -> V_18 -= V_181 + V_18 - ( V_112 + V_11 ) ;
goto V_237;
}
V_137 ++ ;
}
if ( V_181 < V_112 + V_11 ) {
struct V_6 * V_238 = V_229 ;
F_99 ( V_181 + V_229 -> V_11 != V_112 + V_11 ) ;
V_181 += V_229 -> V_11 ;
V_229 = V_229 -> V_53 ;
if ( V_238 -> V_53 ) {
V_238 = F_87 ( V_238 , V_49 ) ;
if ( ! V_238 )
goto V_133;
} else
F_35 ( V_238 ) ;
F_191 ( V_234 ) ;
F_19 ( V_234 ) -> V_54 = V_238 ;
}
V_237:
V_234 -> V_48 = V_11 - V_235 ;
V_234 -> V_11 += V_234 -> V_48 ;
V_234 -> V_31 += V_234 -> V_48 ;
} while ( ( V_112 += V_11 ) < V_7 -> V_11 );
return V_228 ;
V_133:
while ( ( V_7 = V_228 ) ) {
V_228 = V_7 -> V_53 ;
F_31 ( V_7 ) ;
}
return F_192 ( V_133 ) ;
}
int F_193 ( struct V_6 * * V_12 , struct V_6 * V_7 )
{
struct V_6 * V_157 = * V_12 ;
struct V_6 * V_234 ;
struct V_24 * V_239 = F_19 ( V_7 ) ;
struct V_24 * V_240 = F_19 ( V_157 ) ;
unsigned int V_125 ;
unsigned int V_11 = F_194 ( V_7 ) ;
unsigned int V_112 = F_195 ( V_7 ) ;
unsigned int V_241 = F_96 ( V_7 ) ;
if ( V_157 -> V_11 + V_11 >= 65536 )
return - V_242 ;
if ( V_240 -> V_54 )
goto V_194;
else if ( V_241 <= V_112 ) {
T_5 * V_137 ;
T_5 * V_243 ;
int V_46 = V_239 -> V_58 ;
int V_58 = V_240 -> V_58 + V_46 ;
V_112 -= V_241 ;
if ( V_58 > V_200 )
return - V_242 ;
V_240 -> V_58 = V_58 ;
V_239 -> V_58 = 0 ;
V_137 = V_240 -> V_59 + V_58 ;
V_243 = V_239 -> V_59 + V_46 ;
do {
* -- V_137 = * -- V_243 ;
} while ( -- V_46 );
V_137 -> V_111 += V_112 ;
V_137 -> V_18 -= V_112 ;
V_7 -> V_31 -= V_7 -> V_48 ;
V_7 -> V_11 -= V_7 -> V_48 ;
V_7 -> V_48 = 0 ;
F_196 ( V_7 ) -> free = 1 ;
goto V_140;
} else if ( F_194 ( V_157 ) != V_240 -> V_113 )
return - V_242 ;
V_125 = F_79 ( V_157 ) ;
V_234 = F_92 ( V_125 + F_195 ( V_157 ) , V_49 ) ;
if ( F_58 ( ! V_234 ) )
return - V_110 ;
F_71 ( V_234 , V_157 ) ;
V_234 -> V_102 = V_157 -> V_102 ;
F_25 ( V_234 , V_125 ) ;
F_187 ( V_234 , F_195 ( V_157 ) ) ;
F_197 ( V_234 , F_184 ( V_157 ) - V_157 -> V_13 ) ;
F_189 ( V_234 , F_198 ( V_157 ) ) ;
F_199 ( V_234 , F_200 ( V_157 ) ) ;
F_201 ( V_157 , F_195 ( V_157 ) ) ;
memcpy ( F_184 ( V_234 ) , F_184 ( V_157 ) ,
V_157 -> V_13 - F_184 ( V_157 ) ) ;
* F_196 ( V_234 ) = * F_196 ( V_157 ) ;
F_19 ( V_234 ) -> V_54 = V_157 ;
F_19 ( V_234 ) -> V_113 = V_240 -> V_113 ;
V_240 -> V_113 = 0 ;
F_202 ( V_157 ) ;
V_234 -> V_100 = V_157 ;
V_234 -> V_48 += V_157 -> V_11 ;
V_234 -> V_31 += V_157 -> V_11 ;
V_234 -> V_11 += V_157 -> V_11 ;
* V_12 = V_234 ;
V_234 -> V_53 = V_157 -> V_53 ;
V_157 -> V_53 = NULL ;
V_157 = V_234 ;
V_194:
if ( V_112 > V_241 ) {
unsigned int V_143 = V_112 - V_241 ;
V_239 -> V_59 [ 0 ] . V_111 += V_143 ;
V_239 -> V_59 [ 0 ] . V_18 -= V_143 ;
V_7 -> V_48 -= V_143 ;
V_7 -> V_11 -= V_143 ;
V_112 = V_241 ;
}
F_201 ( V_7 , V_112 ) ;
V_157 -> V_100 -> V_53 = V_7 ;
V_157 -> V_100 = V_7 ;
F_202 ( V_7 ) ;
V_140:
F_196 ( V_157 ) -> V_244 ++ ;
V_157 -> V_48 += V_11 ;
V_157 -> V_31 += V_11 ;
V_157 -> V_11 += V_11 ;
F_196 ( V_7 ) -> V_245 = 1 ;
return 0 ;
}
void T_8 F_203 ( void )
{
V_27 = F_204 ( L_5 ,
sizeof( struct V_6 ) ,
0 ,
V_246 | V_247 ,
NULL ) ;
V_26 = F_204 ( L_6 ,
( 2 * sizeof( struct V_6 ) ) +
sizeof( T_3 ) ,
0 ,
V_246 | V_247 ,
NULL ) ;
}
static int
F_205 ( struct V_6 * V_7 , struct V_248 * V_232 , int V_112 , int V_11 )
{
int V_148 = F_96 ( V_7 ) ;
int V_46 , V_150 = V_148 - V_112 ;
struct V_6 * V_149 ;
int V_249 = 0 ;
if ( V_150 > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
F_206 ( V_232 , V_7 -> V_13 + V_112 , V_150 ) ;
V_249 ++ ;
if ( ( V_11 -= V_150 ) == 0 )
return V_249 ;
V_112 += V_150 ;
}
for ( V_46 = 0 ; V_46 < F_19 ( V_7 ) -> V_58 ; V_46 ++ ) {
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + F_19 ( V_7 ) -> V_59 [ V_46 ] . V_18 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
T_5 * V_137 = & F_19 ( V_7 ) -> V_59 [ V_46 ] ;
if ( V_150 > V_11 )
V_150 = V_11 ;
F_207 ( & V_232 [ V_249 ] , V_137 -> V_5 , V_150 ,
V_137 -> V_111 + V_112 - V_148 ) ;
V_249 ++ ;
if ( ! ( V_11 -= V_150 ) )
return V_249 ;
V_112 += V_150 ;
}
V_148 = V_15 ;
}
F_34 (skb, frag_iter) {
int V_15 ;
F_46 ( V_148 > V_112 + V_11 ) ;
V_15 = V_148 + V_149 -> V_11 ;
if ( ( V_150 = V_15 - V_112 ) > 0 ) {
if ( V_150 > V_11 )
V_150 = V_11 ;
V_249 += F_205 ( V_149 , V_232 + V_249 , V_112 - V_148 ,
V_150 ) ;
if ( ( V_11 -= V_150 ) == 0 )
return V_249 ;
V_112 += V_150 ;
}
V_148 = V_15 ;
}
F_99 ( V_11 ) ;
return V_249 ;
}
int F_208 ( struct V_6 * V_7 , struct V_248 * V_232 , int V_112 , int V_11 )
{
int V_250 = F_205 ( V_7 , V_232 , V_112 , V_11 ) ;
F_209 ( & V_232 [ V_250 - 1 ] ) ;
return V_250 ;
}
int F_210 ( struct V_6 * V_7 , int V_251 , struct V_6 * * V_252 )
{
int V_253 ;
int V_249 ;
struct V_6 * V_191 , * * V_254 ;
if ( ( F_70 ( V_7 ) || F_19 ( V_7 ) -> V_58 ) &&
F_117 ( V_7 , F_211 ( V_7 ) - F_96 ( V_7 ) ) == NULL )
return - V_110 ;
if ( ! F_38 ( V_7 ) ) {
if ( F_106 ( V_7 ) < V_251 &&
F_98 ( V_7 , 0 , V_251 - F_106 ( V_7 ) + 128 , V_49 ) )
return - V_110 ;
* V_252 = V_7 ;
return 1 ;
}
V_249 = 1 ;
V_254 = & F_19 ( V_7 ) -> V_54 ;
V_253 = 0 ;
while ( ( V_191 = * V_254 ) != NULL ) {
int V_118 = 0 ;
if ( F_69 ( V_191 ) )
V_253 = 1 ;
if ( V_191 -> V_53 == NULL && V_251 ) {
if ( F_19 ( V_191 ) -> V_58 ||
F_38 ( V_191 ) ||
F_106 ( V_191 ) < V_251 )
V_118 = V_251 + 128 ;
}
if ( V_253 ||
F_70 ( V_191 ) ||
V_118 ||
F_19 ( V_191 ) -> V_58 ||
F_38 ( V_191 ) ) {
struct V_6 * V_126 ;
if ( V_118 == 0 )
V_126 = F_91 ( V_191 , V_49 ) ;
else
V_126 = F_104 ( V_191 ,
F_79 ( V_191 ) ,
V_118 ,
V_49 ) ;
if ( F_58 ( V_126 == NULL ) )
return - V_110 ;
if ( V_191 -> V_101 )
F_212 ( V_126 , V_191 -> V_101 ) ;
V_126 -> V_53 = V_191 -> V_53 ;
* V_254 = V_126 ;
F_31 ( V_191 ) ;
V_191 = V_126 ;
}
V_249 ++ ;
* V_252 = V_191 ;
V_254 = & V_191 -> V_53 ;
}
return V_249 ;
}
static void F_213 ( struct V_6 * V_7 )
{
struct V_156 * V_101 = V_7 -> V_101 ;
F_214 ( V_7 -> V_31 , & V_101 -> V_255 ) ;
}
int F_215 ( struct V_156 * V_101 , struct V_6 * V_7 )
{
if ( F_59 ( & V_101 -> V_255 ) + V_7 -> V_31 >=
( unsigned ) V_101 -> V_256 )
return - V_110 ;
F_216 ( V_7 ) ;
V_7 -> V_101 = V_101 ;
V_7 -> V_68 = F_213 ;
F_180 ( V_7 -> V_31 , & V_101 -> V_255 ) ;
F_217 ( V_7 ) ;
F_156 ( & V_101 -> V_257 , V_7 ) ;
if ( ! F_218 ( V_101 , V_258 ) )
V_101 -> V_259 ( V_101 , V_7 -> V_11 ) ;
return 0 ;
}
void F_219 ( struct V_6 * V_260 ,
struct V_261 * V_262 )
{
struct V_156 * V_101 = V_260 -> V_101 ;
struct V_263 * V_264 ;
struct V_6 * V_7 ;
int V_133 ;
if ( ! V_101 )
return;
V_7 = F_87 ( V_260 , V_49 ) ;
if ( ! V_7 )
return;
if ( V_262 ) {
* F_220 ( V_7 ) =
* V_262 ;
} else {
V_7 -> V_79 = F_221 () ;
}
V_264 = F_222 ( V_7 ) ;
memset ( V_264 , 0 , sizeof( * V_264 ) ) ;
V_264 -> V_265 . V_266 = V_267 ;
V_264 -> V_265 . V_268 = V_269 ;
V_133 = F_215 ( V_101 , V_7 ) ;
if ( V_133 )
F_31 ( V_7 ) ;
}
bool F_223 ( struct V_6 * V_7 , T_9 V_148 , T_9 V_47 )
{
if ( F_58 ( V_148 > F_96 ( V_7 ) ) ||
F_58 ( ( int ) V_148 + V_47 > F_96 ( V_7 ) - 2 ) ) {
if ( F_224 () )
F_7 ( V_270
L_7 ,
V_148 , V_47 , F_96 ( V_7 ) ) ;
return false ;
}
V_7 -> V_87 = V_123 ;
V_7 -> V_124 = F_79 ( V_7 ) + V_148 ;
V_7 -> V_185 = V_47 ;
return true ;
}
void F_225 ( const struct V_6 * V_7 )
{
if ( F_224 () )
F_226 ( L_8
L_9 , V_7 -> V_16 -> V_17 ) ;
}
