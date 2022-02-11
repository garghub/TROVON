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
static void * F_30 ( unsigned int V_54 , T_2 V_24 )
{
struct V_55 * V_56 ;
void * V_8 = NULL ;
int V_57 ;
unsigned long V_15 ;
F_31 ( V_15 ) ;
V_56 = F_32 ( & V_55 ) ;
if ( F_33 ( ! V_56 -> V_58 . V_59 ) ) {
V_60:
for ( V_57 = V_61 ; ; ) {
T_2 V_62 = V_24 ;
if ( V_57 )
V_62 |= V_63 | V_22 ;
V_56 -> V_58 . V_59 = F_34 ( V_62 , V_57 ) ;
if ( F_35 ( V_56 -> V_58 . V_59 ) )
break;
if ( -- V_57 < 0 )
goto V_10;
}
V_56 -> V_58 . V_14 = V_64 << V_57 ;
F_36 ( V_65 - 1 ,
& V_56 -> V_58 . V_59 -> V_66 ) ;
V_56 -> V_67 = V_65 ;
V_56 -> V_58 . V_68 = 0 ;
}
if ( V_56 -> V_58 . V_68 + V_54 > V_56 -> V_58 . V_14 ) {
if ( F_37 ( & V_56 -> V_58 . V_59 -> V_66 ) != V_56 -> V_67 ) {
if ( ! F_38 ( V_56 -> V_67 ,
& V_56 -> V_58 . V_59 -> V_66 ) )
goto V_60;
F_12 ( & V_56 -> V_58 . V_59 -> V_66 ,
V_65 ) ;
} else {
F_36 ( V_65 - V_56 -> V_67 ,
& V_56 -> V_58 . V_59 -> V_66 ) ;
}
V_56 -> V_67 = V_65 ;
V_56 -> V_58 . V_68 = 0 ;
}
V_8 = F_39 ( V_56 -> V_58 . V_59 ) + V_56 -> V_58 . V_68 ;
V_56 -> V_58 . V_68 += V_54 ;
V_56 -> V_67 -- ;
V_10:
F_40 ( V_15 ) ;
return V_8 ;
}
void * F_41 ( unsigned int V_54 )
{
return F_30 ( V_54 , V_52 | V_69 ) ;
}
struct V_1 * F_42 ( struct V_70 * V_11 ,
unsigned int V_71 , T_2 V_24 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_54 = F_17 ( V_71 + V_72 ) +
F_17 ( sizeof( struct V_32 ) ) ;
if ( V_54 <= V_64 && ! ( V_24 & ( V_73 | V_74 ) ) ) {
void * V_8 ;
if ( F_15 () )
V_24 |= V_37 ;
V_8 = F_30 ( V_54 , V_24 ) ;
if ( F_35 ( V_8 ) ) {
V_2 = F_28 ( V_8 , V_54 ) ;
if ( F_33 ( ! V_2 ) )
F_43 ( F_44 ( V_8 ) ) ;
}
} else {
V_2 = F_14 ( V_71 + V_72 , V_24 ,
V_36 , V_75 ) ;
}
if ( F_35 ( V_2 ) ) {
F_45 ( V_2 , V_72 ) ;
V_2 -> V_11 = V_11 ;
}
return V_2 ;
}
void F_46 ( struct V_1 * V_2 , int V_76 , struct V_59 * V_59 , int V_77 ,
int V_14 , unsigned int V_27 )
{
F_47 ( V_2 , V_76 , V_59 , V_77 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_78 += V_14 ;
V_2 -> V_27 += V_27 ;
}
void F_48 ( struct V_1 * V_2 , int V_76 , int V_14 ,
unsigned int V_27 )
{
T_4 * V_58 = & F_23 ( V_2 ) -> V_79 [ V_76 ] ;
F_49 ( V_58 , V_14 ) ;
V_2 -> V_6 += V_14 ;
V_2 -> V_78 += V_14 ;
V_2 -> V_27 += V_27 ;
}
static void F_50 ( struct V_1 * * V_80 )
{
F_51 ( * V_80 ) ;
* V_80 = NULL ;
}
static inline void F_52 ( struct V_1 * V_2 )
{
F_50 ( & F_23 ( V_2 ) -> V_81 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_1 * V_82 ;
F_54 (skb, list)
F_55 ( V_82 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 )
F_43 ( F_44 ( V_2 -> V_7 ) ) ;
else
F_57 ( V_2 -> V_7 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_23 ( V_2 ) ;
int V_76 ;
if ( V_2 -> V_83 &&
F_59 ( V_2 -> V_84 ? ( 1 << V_85 ) + 1 : 1 ,
& V_33 -> V_40 ) )
return;
for ( V_76 = 0 ; V_76 < V_33 -> V_86 ; V_76 ++ )
F_60 ( & V_33 -> V_79 [ V_76 ] ) ;
if ( V_33 -> V_87 & V_88 ) {
struct V_89 * V_90 ;
V_90 = V_33 -> V_41 ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 , true ) ;
}
if ( V_33 -> V_81 )
F_51 ( V_33 -> V_81 ) ;
F_56 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
switch ( V_2 -> V_47 ) {
case V_92 :
F_27 ( V_25 , V_2 ) ;
break;
case V_48 :
V_43 = F_25 ( V_2 , struct V_42 , V_44 ) ;
if ( F_62 ( & V_43 -> V_49 ) )
F_27 ( V_35 , V_43 ) ;
break;
case V_93 :
V_43 = F_25 ( V_2 , struct V_42 , V_45 ) ;
V_2 -> V_47 = V_50 ;
if ( F_62 ( & V_43 -> V_49 ) )
F_27 ( V_35 , V_43 ) ;
break;
}
}
static void F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
#ifdef F_65
F_66 ( V_2 -> V_94 ) ;
#endif
if ( V_2 -> V_95 ) {
F_67 ( F_68 () ) ;
V_2 -> V_95 ( V_2 ) ;
}
#if F_69 ( V_96 )
F_70 ( V_2 -> V_97 ) ;
#endif
#if F_69 ( V_98 )
F_71 ( V_2 -> V_99 ) ;
#endif
#ifdef F_72
V_2 -> V_100 = 0 ;
#ifdef F_73
V_2 -> V_101 = 0 ;
#endif
#endif
}
static void F_74 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
if ( F_35 ( V_2 -> V_7 ) )
F_58 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_74 ( V_2 ) ;
F_61 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( F_33 ( ! V_2 ) )
return;
if ( F_35 ( F_37 ( & V_2 -> V_28 ) == 1 ) )
F_77 () ;
else if ( F_35 ( ! F_62 ( & V_2 -> V_28 ) ) )
return;
F_78 ( V_2 , F_79 ( 0 ) ) ;
F_75 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_102 )
{
while ( V_102 ) {
struct V_1 * V_103 = V_102 -> V_103 ;
F_76 ( V_102 ) ;
V_102 = V_103 ;
}
}
void F_80 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) -> V_87 & V_88 ) {
struct V_89 * V_90 ;
V_90 = F_23 ( V_2 ) -> V_41 ;
if ( V_90 -> V_91 )
V_90 -> V_91 ( V_90 , false ) ;
F_23 ( V_2 ) -> V_87 &= ~ V_88 ;
}
}
void F_81 ( struct V_1 * V_2 )
{
if ( F_33 ( ! V_2 ) )
return;
if ( F_35 ( F_37 ( & V_2 -> V_28 ) == 1 ) )
F_77 () ;
else if ( F_35 ( ! F_62 ( & V_2 -> V_28 ) ) )
return;
F_82 ( V_2 ) ;
F_75 ( V_2 ) ;
}
static struct V_1 * F_83 ( struct V_1 * V_104 , struct V_1 * V_2 )
{
#define F_84 ( T_5 ) n->x = skb->x
V_104 -> V_103 = V_104 -> V_105 = NULL ;
V_104 -> V_106 = NULL ;
F_85 ( V_104 , V_2 ) ;
F_84 ( V_6 ) ;
F_84 ( V_78 ) ;
F_84 ( V_107 ) ;
V_104 -> V_108 = V_2 -> V_84 ? F_86 ( V_2 ) : V_2 -> V_108 ;
V_104 -> V_83 = 1 ;
V_104 -> V_84 = 0 ;
V_104 -> V_95 = NULL ;
F_84 ( V_9 ) ;
F_84 ( V_10 ) ;
F_84 ( V_7 ) ;
F_84 ( V_53 ) ;
F_84 ( V_8 ) ;
F_84 ( V_27 ) ;
F_12 ( & V_104 -> V_28 , 1 ) ;
F_87 ( & ( F_23 ( V_2 ) -> V_40 ) ) ;
V_2 -> V_83 = 1 ;
return V_104 ;
#undef F_84
}
struct V_1 * F_88 ( struct V_1 * V_109 , struct V_1 * V_110 )
{
F_74 ( V_109 ) ;
return F_83 ( V_109 , V_110 ) ;
}
int F_89 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_76 ;
int V_111 = F_23 ( V_2 ) -> V_86 ;
struct V_59 * V_59 , * V_7 = NULL ;
struct V_89 * V_90 = F_23 ( V_2 ) -> V_41 ;
for ( V_76 = 0 ; V_76 < V_111 ; V_76 ++ ) {
T_3 * V_112 ;
T_4 * V_113 = & F_23 ( V_2 ) -> V_79 [ V_76 ] ;
V_59 = F_90 ( V_24 ) ;
if ( ! V_59 ) {
while ( V_7 ) {
struct V_59 * V_103 = (struct V_59 * ) F_91 ( V_7 ) ;
F_43 ( V_7 ) ;
V_7 = V_103 ;
}
return - V_114 ;
}
V_112 = F_92 ( F_93 ( V_113 ) ) ;
memcpy ( F_39 ( V_59 ) ,
V_112 + V_113 -> V_115 , F_94 ( V_113 ) ) ;
F_95 ( V_112 ) ;
F_96 ( V_59 , ( unsigned long ) V_7 ) ;
V_7 = V_59 ;
}
for ( V_76 = 0 ; V_76 < V_111 ; V_76 ++ )
F_97 ( V_2 , V_76 ) ;
V_90 -> V_91 ( V_90 , false ) ;
for ( V_76 = V_111 - 1 ; V_76 >= 0 ; V_76 -- ) {
F_98 ( V_2 , V_76 , V_7 , 0 ,
F_23 ( V_2 ) -> V_79 [ V_76 ] . V_14 ) ;
V_7 = (struct V_59 * ) F_91 ( V_7 ) ;
}
F_23 ( V_2 ) -> V_87 &= ~ V_88 ;
return 0 ;
}
struct V_1 * F_99 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_42 * V_43 = F_25 ( V_2 ,
struct V_42 ,
V_44 ) ;
struct V_1 * V_104 = & V_43 -> V_45 ;
if ( F_100 ( V_2 , V_24 ) )
return NULL ;
if ( V_2 -> V_47 == V_48 &&
V_104 -> V_47 == V_50 ) {
V_104 -> V_47 = V_93 ;
F_87 ( & V_43 -> V_49 ) ;
} else {
if ( F_101 ( V_2 ) )
V_24 |= V_37 ;
V_104 = F_29 ( V_25 , V_24 ) ;
if ( ! V_104 )
return NULL ;
F_26 ( V_104 , V_46 ) ;
V_104 -> V_47 = V_92 ;
}
return F_83 ( V_104 , V_2 ) ;
}
static void F_102 ( struct V_1 * V_2 , int V_77 )
{
if ( V_2 -> V_116 == V_117 )
V_2 -> V_118 += V_77 ;
V_2 -> V_39 += V_77 ;
V_2 -> V_119 += V_77 ;
if ( F_103 ( V_2 ) )
V_2 -> V_29 += V_77 ;
V_2 -> V_120 += V_77 ;
V_2 -> V_121 += V_77 ;
V_2 -> V_122 += V_77 ;
}
static void F_104 ( struct V_1 * V_123 , const struct V_1 * V_124 )
{
F_85 ( V_123 , V_124 ) ;
F_23 ( V_123 ) -> V_125 = F_23 ( V_124 ) -> V_125 ;
F_23 ( V_123 ) -> V_126 = F_23 ( V_124 ) -> V_126 ;
F_23 ( V_123 ) -> V_127 = F_23 ( V_124 ) -> V_127 ;
}
static inline int F_105 ( const struct V_1 * V_2 )
{
if ( F_101 ( V_2 ) )
return V_36 ;
return 0 ;
}
struct V_1 * F_106 ( const struct V_1 * V_2 , T_2 V_24 )
{
int V_128 = F_86 ( V_2 ) ;
unsigned int V_14 = F_107 ( V_2 ) + V_2 -> V_78 ;
struct V_1 * V_104 = F_14 ( V_14 , V_24 ,
F_105 ( V_2 ) , V_75 ) ;
if ( ! V_104 )
return NULL ;
F_45 ( V_104 , V_128 ) ;
F_108 ( V_104 , V_2 -> V_6 ) ;
if ( F_109 ( V_2 , - V_128 , V_104 -> V_7 , V_128 + V_2 -> V_6 ) )
F_3 () ;
F_104 ( V_104 , V_2 ) ;
return V_104 ;
}
struct V_1 * F_110 ( struct V_1 * V_2 , int V_129 ,
T_2 V_24 , bool V_47 )
{
unsigned int V_14 = F_111 ( V_2 ) + V_129 ;
int V_15 = F_105 ( V_2 ) | ( V_47 ? V_34 : 0 ) ;
struct V_1 * V_104 = F_14 ( V_14 , V_24 , V_15 , V_75 ) ;
if ( ! V_104 )
goto V_23;
F_45 ( V_104 , V_129 ) ;
F_108 ( V_104 , F_111 ( V_2 ) ) ;
F_112 ( V_2 , V_104 -> V_8 , V_104 -> V_6 ) ;
V_104 -> V_27 += V_2 -> V_78 ;
V_104 -> V_78 = V_2 -> V_78 ;
V_104 -> V_6 = V_2 -> V_6 ;
if ( F_23 ( V_2 ) -> V_86 ) {
int V_76 ;
if ( F_100 ( V_2 , V_24 ) ) {
F_76 ( V_104 ) ;
V_104 = NULL ;
goto V_23;
}
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ ) {
F_23 ( V_104 ) -> V_79 [ V_76 ] = F_23 ( V_2 ) -> V_79 [ V_76 ] ;
F_113 ( V_2 , V_76 ) ;
}
F_23 ( V_104 ) -> V_86 = V_76 ;
}
if ( F_114 ( V_2 ) ) {
F_23 ( V_104 ) -> V_81 = F_23 ( V_2 ) -> V_81 ;
F_53 ( V_104 ) ;
}
F_104 ( V_104 , V_2 ) ;
V_23:
return V_104 ;
}
int F_115 ( struct V_1 * V_2 , int V_130 , int V_131 ,
T_2 V_24 )
{
int V_76 ;
T_3 * V_8 ;
int V_14 = V_130 + F_107 ( V_2 ) + V_131 ;
long V_77 ;
F_116 ( V_130 < 0 ) ;
if ( F_117 ( V_2 ) )
F_3 () ;
V_14 = F_17 ( V_14 ) ;
if ( F_101 ( V_2 ) )
V_24 |= V_37 ;
V_8 = F_18 ( V_14 + F_17 ( sizeof( struct V_32 ) ) ,
V_24 , V_75 , NULL ) ;
if ( ! V_8 )
goto V_38;
V_14 = F_19 ( F_20 ( V_8 ) ) ;
memcpy ( V_8 + V_130 , V_2 -> V_7 , F_118 ( V_2 ) - V_2 -> V_7 ) ;
memcpy ( (struct V_32 * ) ( V_8 + V_14 ) ,
F_23 ( V_2 ) ,
F_11 ( struct V_32 , V_79 [ F_23 ( V_2 ) -> V_86 ] ) ) ;
if ( F_119 ( V_2 ) ) {
if ( F_100 ( V_2 , V_24 ) )
goto V_132;
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ )
F_113 ( V_2 , V_76 ) ;
if ( F_114 ( V_2 ) )
F_53 ( V_2 ) ;
F_58 ( V_2 ) ;
} else {
F_56 ( V_2 ) ;
}
V_77 = ( V_8 + V_130 ) - V_2 -> V_7 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_53 = 0 ;
V_2 -> V_8 += V_77 ;
#ifdef F_120
V_2 -> V_10 = V_14 ;
V_77 = V_130 ;
#else
V_2 -> V_10 = V_2 -> V_7 + V_14 ;
#endif
V_2 -> V_9 += V_77 ;
F_102 ( V_2 , V_130 ) ;
V_2 -> V_83 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_84 = 0 ;
F_12 ( & F_23 ( V_2 ) -> V_40 , 1 ) ;
return 0 ;
V_132:
F_57 ( V_8 ) ;
V_38:
return - V_114 ;
}
struct V_1 * F_121 ( struct V_1 * V_2 , unsigned int V_129 )
{
struct V_1 * V_45 ;
int V_133 = V_129 - F_86 ( V_2 ) ;
if ( V_133 <= 0 )
V_45 = F_122 ( V_2 , V_52 ) ;
else {
V_45 = F_99 ( V_2 , V_52 ) ;
if ( V_45 && F_115 ( V_45 , F_17 ( V_133 ) , 0 ,
V_52 ) ) {
F_76 ( V_45 ) ;
V_45 = NULL ;
}
}
return V_45 ;
}
struct V_1 * F_123 ( const struct V_1 * V_2 ,
int V_134 , int V_135 ,
T_2 V_24 )
{
struct V_1 * V_104 = F_14 ( V_134 + V_2 -> V_6 + V_135 ,
V_24 , F_105 ( V_2 ) ,
V_75 ) ;
int V_136 = F_86 ( V_2 ) ;
int V_137 , V_138 ;
if ( ! V_104 )
return NULL ;
F_45 ( V_104 , V_134 ) ;
F_108 ( V_104 , V_2 -> V_6 ) ;
V_137 = V_136 ;
V_138 = 0 ;
if ( V_134 <= V_137 )
V_137 = V_134 ;
else
V_138 = V_134 - V_137 ;
if ( F_109 ( V_2 , - V_137 , V_104 -> V_7 + V_138 ,
V_2 -> V_6 + V_137 ) )
F_3 () ;
F_104 ( V_104 , V_2 ) ;
F_102 ( V_104 , V_134 - V_136 ) ;
return V_104 ;
}
int F_124 ( struct V_1 * V_2 , int V_139 )
{
int V_140 ;
int V_131 ;
if ( ! F_119 ( V_2 ) && F_125 ( V_2 ) >= V_139 ) {
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_139 ) ;
return 0 ;
}
V_131 = V_2 -> V_78 + V_139 - ( V_2 -> V_10 - V_2 -> V_9 ) ;
if ( F_35 ( F_119 ( V_2 ) || V_131 > 0 ) ) {
V_140 = F_115 ( V_2 , 0 , V_131 , V_52 ) ;
if ( F_33 ( V_140 ) )
goto V_141;
}
V_140 = F_126 ( V_2 ) ;
if ( F_33 ( V_140 ) )
goto V_141;
memset ( V_2 -> V_8 + V_2 -> V_6 , 0 , V_139 ) ;
return 0 ;
V_141:
F_76 ( V_2 ) ;
return V_140 ;
}
unsigned char * F_127 ( struct V_1 * V_2 , struct V_1 * V_9 , int V_6 )
{
if ( V_9 != V_2 ) {
V_2 -> V_78 += V_6 ;
V_2 -> V_6 += V_6 ;
}
return F_108 ( V_9 , V_6 ) ;
}
unsigned char * F_108 ( struct V_1 * V_2 , unsigned int V_6 )
{
unsigned char * V_142 = F_118 ( V_2 ) ;
F_128 ( V_2 ) ;
V_2 -> V_9 += V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_33 ( V_2 -> V_9 > V_2 -> V_10 ) )
F_4 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_142 ;
}
unsigned char * F_129 ( struct V_1 * V_2 , unsigned int V_6 )
{
V_2 -> V_8 -= V_6 ;
V_2 -> V_6 += V_6 ;
if ( F_33 ( V_2 -> V_8 < V_2 -> V_7 ) )
F_5 ( V_2 , V_6 , F_79 ( 0 ) ) ;
return V_2 -> V_8 ;
}
unsigned char * F_130 ( struct V_1 * V_2 , unsigned int V_6 )
{
return F_131 ( V_2 , V_6 ) ;
}
void F_132 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_2 -> V_6 > V_6 )
F_133 ( V_2 , V_6 ) ;
}
int F_134 ( struct V_1 * V_2 , unsigned int V_6 )
{
struct V_1 * * V_143 ;
struct V_1 * V_58 ;
int V_68 = F_111 ( V_2 ) ;
int V_144 = F_23 ( V_2 ) -> V_86 ;
int V_76 ;
int V_140 ;
if ( F_119 ( V_2 ) &&
F_33 ( ( V_140 = F_115 ( V_2 , 0 , 0 , V_52 ) ) ) )
return V_140 ;
V_76 = 0 ;
if ( V_68 >= V_6 )
goto V_145;
for (; V_76 < V_144 ; V_76 ++ ) {
int V_10 = V_68 + F_94 ( & F_23 ( V_2 ) -> V_79 [ V_76 ] ) ;
if ( V_10 < V_6 ) {
V_68 = V_10 ;
continue;
}
F_135 ( & F_23 ( V_2 ) -> V_79 [ V_76 ++ ] , V_6 - V_68 ) ;
V_145:
F_23 ( V_2 ) -> V_86 = V_76 ;
for (; V_76 < V_144 ; V_76 ++ )
F_97 ( V_2 , V_76 ) ;
if ( F_114 ( V_2 ) )
F_52 ( V_2 ) ;
goto V_146;
}
for ( V_143 = & F_23 ( V_2 ) -> V_81 ; ( V_58 = * V_143 ) ;
V_143 = & V_58 -> V_103 ) {
int V_10 = V_68 + V_58 -> V_6 ;
if ( F_117 ( V_58 ) ) {
struct V_1 * V_147 ;
V_147 = F_99 ( V_58 , V_52 ) ;
if ( F_33 ( ! V_147 ) )
return - V_114 ;
V_147 -> V_103 = V_58 -> V_103 ;
F_81 ( V_58 ) ;
V_58 = V_147 ;
* V_143 = V_58 ;
}
if ( V_10 < V_6 ) {
V_68 = V_10 ;
continue;
}
if ( V_10 > V_6 &&
F_33 ( ( V_140 = F_136 ( V_58 , V_6 - V_68 ) ) ) )
return V_140 ;
if ( V_58 -> V_103 )
F_50 ( & V_58 -> V_103 ) ;
break;
}
V_146:
if ( V_6 > F_111 ( V_2 ) ) {
V_2 -> V_78 -= V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
} else {
V_2 -> V_6 = V_6 ;
V_2 -> V_78 = 0 ;
F_137 ( V_2 , V_6 ) ;
}
return 0 ;
}
unsigned char * F_138 ( struct V_1 * V_2 , int V_133 )
{
int V_76 , V_148 , V_149 = ( V_2 -> V_9 + V_133 ) - V_2 -> V_10 ;
if ( V_149 > 0 || F_119 ( V_2 ) ) {
if ( F_115 ( V_2 , 0 , V_149 > 0 ? V_149 + 128 : 0 ,
V_52 ) )
return NULL ;
}
if ( F_109 ( V_2 , F_111 ( V_2 ) , F_118 ( V_2 ) , V_133 ) )
F_3 () ;
if ( ! F_114 ( V_2 ) )
goto V_150;
V_149 = V_133 ;
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ ) {
int V_14 = F_94 ( & F_23 ( V_2 ) -> V_79 [ V_76 ] ) ;
if ( V_14 >= V_149 )
goto V_150;
V_149 -= V_14 ;
}
if ( V_149 ) {
struct V_1 * V_82 = F_23 ( V_2 ) -> V_81 ;
struct V_1 * V_151 = NULL ;
struct V_1 * V_152 = NULL ;
do {
F_116 ( ! V_82 ) ;
if ( V_82 -> V_6 <= V_149 ) {
V_149 -= V_82 -> V_6 ;
V_82 = V_82 -> V_103 ;
V_152 = V_82 ;
} else {
if ( F_117 ( V_82 ) ) {
V_151 = F_99 ( V_82 , V_52 ) ;
if ( ! V_151 )
return NULL ;
V_152 = V_82 -> V_103 ;
V_82 = V_151 ;
} else {
V_152 = V_82 ;
}
if ( ! F_139 ( V_82 , V_149 ) ) {
F_76 ( V_151 ) ;
return NULL ;
}
break;
}
} while ( V_149 );
while ( ( V_82 = F_23 ( V_2 ) -> V_81 ) != V_152 ) {
F_23 ( V_2 ) -> V_81 = V_82 -> V_103 ;
F_76 ( V_82 ) ;
}
if ( V_151 ) {
V_151 -> V_103 = V_82 ;
F_23 ( V_2 ) -> V_81 = V_151 ;
}
}
V_150:
V_149 = V_133 ;
V_148 = 0 ;
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ ) {
int V_14 = F_94 ( & F_23 ( V_2 ) -> V_79 [ V_76 ] ) ;
if ( V_14 <= V_149 ) {
F_97 ( V_2 , V_76 ) ;
V_149 -= V_14 ;
} else {
F_23 ( V_2 ) -> V_79 [ V_148 ] = F_23 ( V_2 ) -> V_79 [ V_76 ] ;
if ( V_149 ) {
F_23 ( V_2 ) -> V_79 [ V_148 ] . V_115 += V_149 ;
F_140 ( & F_23 ( V_2 ) -> V_79 [ V_148 ] , V_149 ) ;
V_149 = 0 ;
}
V_148 ++ ;
}
}
F_23 ( V_2 ) -> V_86 = V_148 ;
V_2 -> V_9 += V_133 ;
V_2 -> V_78 -= V_133 ;
return F_118 ( V_2 ) ;
}
int F_109 ( const struct V_1 * V_2 , int V_68 , void * V_153 , int V_6 )
{
int V_154 = F_111 ( V_2 ) ;
struct V_1 * V_155 ;
int V_76 , V_156 ;
if ( V_68 > ( int ) V_2 -> V_6 - V_6 )
goto V_157;
if ( ( V_156 = V_154 - V_68 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
F_141 ( V_2 , V_68 , V_153 , V_156 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_68 += V_156 ;
V_153 += V_156 ;
}
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ ) {
int V_10 ;
T_4 * V_113 = & F_23 ( V_2 ) -> V_79 [ V_76 ] ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + F_94 ( V_113 ) ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
T_3 * V_112 ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_112 = F_92 ( F_93 ( V_113 ) ) ;
memcpy ( V_153 ,
V_112 + V_113 -> V_115 + V_68 - V_154 ,
V_156 ) ;
F_95 ( V_112 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_68 += V_156 ;
V_153 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
if ( F_109 ( V_155 , V_68 - V_154 , V_153 , V_156 ) )
goto V_157;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_68 += V_156 ;
V_153 += V_156 ;
}
V_154 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_157:
return - V_158 ;
}
static void F_142 ( struct V_159 * V_160 , unsigned int V_76 )
{
F_43 ( V_160 -> V_161 [ V_76 ] ) ;
}
static struct V_59 * F_143 ( struct V_59 * V_59 , unsigned int * V_6 ,
unsigned int * V_68 ,
struct V_162 * V_106 )
{
struct V_163 * V_164 = F_144 ( V_106 ) ;
if ( ! F_145 ( V_106 , V_164 ) )
return NULL ;
* V_6 = F_146 (unsigned int, *len, pfrag->size - pfrag->offset) ;
memcpy ( F_39 ( V_164 -> V_59 ) + V_164 -> V_68 ,
F_39 ( V_59 ) + * V_68 , * V_6 ) ;
* V_68 = V_164 -> V_68 ;
V_164 -> V_68 += * V_6 ;
return V_164 -> V_59 ;
}
static bool F_147 ( const struct V_159 * V_160 ,
struct V_59 * V_59 ,
unsigned int V_68 )
{
return V_160 -> V_165 &&
V_160 -> V_161 [ V_160 -> V_165 - 1 ] == V_59 &&
( V_160 -> V_166 [ V_160 -> V_165 - 1 ] . V_68 +
V_160 -> V_166 [ V_160 -> V_165 - 1 ] . V_6 == V_68 ) ;
}
static bool F_148 ( struct V_159 * V_160 ,
struct V_167 * V_168 , struct V_59 * V_59 ,
unsigned int * V_6 , unsigned int V_68 ,
bool V_169 ,
struct V_162 * V_106 )
{
if ( F_33 ( V_160 -> V_165 == V_170 ) )
return true ;
if ( V_169 ) {
V_59 = F_143 ( V_59 , V_6 , & V_68 , V_106 ) ;
if ( ! V_59 )
return true ;
}
if ( F_147 ( V_160 , V_59 , V_68 ) ) {
V_160 -> V_166 [ V_160 -> V_165 - 1 ] . V_6 += * V_6 ;
return false ;
}
F_149 ( V_59 ) ;
V_160 -> V_161 [ V_160 -> V_165 ] = V_59 ;
V_160 -> V_166 [ V_160 -> V_165 ] . V_6 = * V_6 ;
V_160 -> V_166 [ V_160 -> V_165 ] . V_68 = V_68 ;
V_160 -> V_165 ++ ;
return false ;
}
static bool F_150 ( struct V_59 * V_59 , unsigned int V_171 ,
unsigned int V_172 , unsigned int * V_77 ,
unsigned int * V_6 ,
struct V_159 * V_160 , bool V_169 ,
struct V_162 * V_106 ,
struct V_167 * V_168 )
{
if ( ! * V_6 )
return true ;
if ( * V_77 >= V_172 ) {
* V_77 -= V_172 ;
return false ;
}
V_171 += * V_77 ;
V_172 -= * V_77 ;
* V_77 = 0 ;
do {
unsigned int V_173 = F_151 ( * V_6 , V_172 ) ;
if ( F_148 ( V_160 , V_168 , V_59 , & V_173 , V_171 ,
V_169 , V_106 ) )
return true ;
V_171 += V_173 ;
V_172 -= V_173 ;
* V_6 -= V_173 ;
} while ( * V_6 && V_172 );
return false ;
}
static bool F_152 ( struct V_1 * V_2 , struct V_167 * V_168 ,
unsigned int * V_68 , unsigned int * V_6 ,
struct V_159 * V_160 , struct V_162 * V_106 )
{
int V_174 ;
if ( F_150 ( F_153 ( V_2 -> V_8 ) ,
( unsigned long ) V_2 -> V_8 & ( V_64 - 1 ) ,
F_111 ( V_2 ) ,
V_68 , V_6 , V_160 ,
F_154 ( V_2 ) ,
V_106 , V_168 ) )
return true ;
for ( V_174 = 0 ; V_174 < F_23 ( V_2 ) -> V_86 ; V_174 ++ ) {
const T_4 * V_113 = & F_23 ( V_2 ) -> V_79 [ V_174 ] ;
if ( F_150 ( F_93 ( V_113 ) ,
V_113 -> V_115 , F_94 ( V_113 ) ,
V_68 , V_6 , V_160 , false , V_106 , V_168 ) )
return true ;
}
return false ;
}
int F_155 ( struct V_1 * V_2 , unsigned int V_68 ,
struct V_167 * V_168 , unsigned int V_175 ,
unsigned int V_15 )
{
struct V_176 V_166 [ V_170 ] ;
struct V_59 * V_161 [ V_170 ] ;
struct V_159 V_160 = {
. V_161 = V_161 ,
. V_166 = V_166 ,
. V_177 = V_170 ,
. V_15 = V_15 ,
. V_178 = & V_179 ,
. V_180 = F_142 ,
} ;
struct V_1 * V_155 ;
struct V_162 * V_106 = V_2 -> V_106 ;
int V_181 = 0 ;
if ( F_152 ( V_2 , V_168 , & V_68 , & V_175 , & V_160 , V_106 ) )
goto V_146;
else if ( ! V_175 )
goto V_146;
F_54 (skb, frag_iter) {
if ( ! V_175 )
break;
if ( F_152 ( V_155 , V_168 , & V_68 , & V_175 , & V_160 , V_106 ) )
break;
}
V_146:
if ( V_160 . V_165 ) {
F_156 ( V_106 ) ;
V_181 = F_157 ( V_168 , & V_160 ) ;
F_158 ( V_106 ) ;
}
return V_181 ;
}
int F_159 ( struct V_1 * V_2 , int V_68 , const void * V_182 , int V_6 )
{
int V_154 = F_111 ( V_2 ) ;
struct V_1 * V_155 ;
int V_76 , V_156 ;
if ( V_68 > ( int ) V_2 -> V_6 - V_6 )
goto V_157;
if ( ( V_156 = V_154 - V_68 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
F_160 ( V_2 , V_68 , V_182 , V_156 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_68 += V_156 ;
V_182 += V_156 ;
}
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ ) {
T_4 * V_58 = & F_23 ( V_2 ) -> V_79 [ V_76 ] ;
int V_10 ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + F_94 ( V_58 ) ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
T_3 * V_112 ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_112 = F_92 ( F_93 ( V_58 ) ) ;
memcpy ( V_112 + V_58 -> V_115 + V_68 - V_154 ,
V_182 , V_156 ) ;
F_95 ( V_112 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_68 += V_156 ;
V_182 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
if ( F_159 ( V_155 , V_68 - V_154 ,
V_182 , V_156 ) )
goto V_157;
if ( ( V_6 -= V_156 ) == 0 )
return 0 ;
V_68 += V_156 ;
V_182 += V_156 ;
}
V_154 = V_10 ;
}
if ( ! V_6 )
return 0 ;
V_157:
return - V_158 ;
}
T_6 F_161 ( const struct V_1 * V_2 , int V_68 , int V_6 ,
T_6 V_183 , const struct V_184 * V_178 )
{
int V_154 = F_111 ( V_2 ) ;
int V_76 , V_156 = V_154 - V_68 ;
struct V_1 * V_155 ;
int V_185 = 0 ;
if ( V_156 > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
V_183 = V_178 -> V_186 ( V_2 -> V_8 + V_68 , V_156 , V_183 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_183 ;
V_68 += V_156 ;
V_185 = V_156 ;
}
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ ) {
int V_10 ;
T_4 * V_58 = & F_23 ( V_2 ) -> V_79 [ V_76 ] ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + F_94 ( V_58 ) ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
T_6 V_187 ;
T_3 * V_112 ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_112 = F_92 ( F_93 ( V_58 ) ) ;
V_187 = V_178 -> V_186 ( V_112 + V_58 -> V_115 +
V_68 - V_154 , V_156 , 0 ) ;
F_95 ( V_112 ) ;
V_183 = V_178 -> V_188 ( V_183 , V_187 , V_185 , V_156 ) ;
if ( ! ( V_6 -= V_156 ) )
return V_183 ;
V_68 += V_156 ;
V_185 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
T_6 V_187 ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_187 = F_161 ( V_155 , V_68 - V_154 ,
V_156 , 0 , V_178 ) ;
V_183 = V_178 -> V_188 ( V_183 , V_187 , V_185 , V_156 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_183 ;
V_68 += V_156 ;
V_185 += V_156 ;
}
V_154 = V_10 ;
}
F_116 ( V_6 ) ;
return V_183 ;
}
T_6 F_162 ( const struct V_1 * V_2 , int V_68 ,
int V_6 , T_6 V_183 )
{
const struct V_184 V_178 = {
. V_186 = V_189 ,
. V_188 = V_190 ,
} ;
return F_161 ( V_2 , V_68 , V_6 , V_183 , & V_178 ) ;
}
T_6 F_163 ( const struct V_1 * V_2 , int V_68 ,
T_3 * V_153 , int V_6 , T_6 V_183 )
{
int V_154 = F_111 ( V_2 ) ;
int V_76 , V_156 = V_154 - V_68 ;
struct V_1 * V_155 ;
int V_185 = 0 ;
if ( V_156 > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
V_183 = F_164 ( V_2 -> V_8 + V_68 , V_153 ,
V_156 , V_183 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_183 ;
V_68 += V_156 ;
V_153 += V_156 ;
V_185 = V_156 ;
}
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ ) {
int V_10 ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + F_94 ( & F_23 ( V_2 ) -> V_79 [ V_76 ] ) ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
T_6 V_187 ;
T_3 * V_112 ;
T_4 * V_58 = & F_23 ( V_2 ) -> V_79 [ V_76 ] ;
if ( V_156 > V_6 )
V_156 = V_6 ;
V_112 = F_92 ( F_93 ( V_58 ) ) ;
V_187 = F_164 ( V_112 +
V_58 -> V_115 +
V_68 - V_154 , V_153 ,
V_156 , 0 ) ;
F_95 ( V_112 ) ;
V_183 = F_165 ( V_183 , V_187 , V_185 ) ;
if ( ! ( V_6 -= V_156 ) )
return V_183 ;
V_68 += V_156 ;
V_153 += V_156 ;
V_185 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
T_6 V_187 ;
int V_10 ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
V_187 = F_163 ( V_155 ,
V_68 - V_154 ,
V_153 , V_156 , 0 ) ;
V_183 = F_165 ( V_183 , V_187 , V_185 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_183 ;
V_68 += V_156 ;
V_153 += V_156 ;
V_185 += V_156 ;
}
V_154 = V_10 ;
}
F_116 ( V_6 ) ;
return V_183 ;
}
unsigned int
F_166 ( const struct V_1 * V_182 )
{
unsigned int V_191 = 0 ;
if ( ! V_182 -> V_53 ||
F_111 ( V_182 ) < V_192 ||
F_23 ( V_182 ) -> V_86 >= V_170 )
V_191 = F_111 ( V_182 ) ;
if ( F_114 ( V_182 ) )
V_191 = V_182 -> V_6 ;
return V_191 ;
}
int
F_167 ( struct V_1 * V_153 , struct V_1 * V_182 , int V_6 , int V_191 )
{
int V_76 , V_193 = 0 ;
int V_172 = 0 ;
int V_181 ;
struct V_59 * V_59 ;
unsigned int V_68 ;
F_116 ( ! V_182 -> V_53 && ! V_191 ) ;
if ( V_6 <= F_125 ( V_153 ) )
return F_109 ( V_182 , 0 , F_108 ( V_153 , V_6 ) , V_6 ) ;
if ( V_191 ) {
V_181 = F_109 ( V_182 , 0 , F_108 ( V_153 , V_191 ) , V_191 ) ;
if ( F_33 ( V_181 ) )
return V_181 ;
V_6 -= V_191 ;
} else {
V_172 = F_146 ( int , F_111 ( V_182 ) , V_6 ) ;
if ( V_172 ) {
V_59 = F_44 ( V_182 -> V_7 ) ;
V_68 = V_182 -> V_8 - ( unsigned char * ) F_39 ( V_59 ) ;
F_98 ( V_153 , 0 , V_59 , V_68 , V_172 ) ;
F_149 ( V_59 ) ;
V_193 = 1 ;
V_6 -= V_172 ;
}
}
V_153 -> V_27 += V_6 + V_172 ;
V_153 -> V_6 += V_6 + V_172 ;
V_153 -> V_78 += V_6 + V_172 ;
if ( F_33 ( F_100 ( V_182 , V_52 ) ) ) {
F_80 ( V_182 ) ;
return - V_114 ;
}
for ( V_76 = 0 ; V_76 < F_23 ( V_182 ) -> V_86 ; V_76 ++ ) {
if ( ! V_6 )
break;
F_23 ( V_153 ) -> V_79 [ V_193 ] = F_23 ( V_182 ) -> V_79 [ V_76 ] ;
F_23 ( V_153 ) -> V_79 [ V_193 ] . V_14 = F_146 ( int , F_23 ( V_153 ) -> V_79 [ V_193 ] . V_14 , V_6 ) ;
V_6 -= F_23 ( V_153 ) -> V_79 [ V_193 ] . V_14 ;
F_113 ( V_153 , V_193 ) ;
V_193 ++ ;
}
F_23 ( V_153 ) -> V_86 = V_193 ;
return 0 ;
}
void F_168 ( const struct V_1 * V_2 , T_3 * V_153 )
{
T_6 V_183 ;
long V_194 ;
if ( V_2 -> V_116 == V_117 )
V_194 = F_169 ( V_2 ) ;
else
V_194 = F_111 ( V_2 ) ;
F_116 ( V_194 > F_111 ( V_2 ) ) ;
F_112 ( V_2 , V_153 , V_194 ) ;
V_183 = 0 ;
if ( V_194 != V_2 -> V_6 )
V_183 = F_163 ( V_2 , V_194 , V_153 + V_194 ,
V_2 -> V_6 - V_194 , 0 ) ;
if ( V_2 -> V_116 == V_117 ) {
long V_195 = V_194 + V_2 -> V_196 ;
* ( ( V_197 * ) ( V_153 + V_195 ) ) = F_170 ( V_183 ) ;
}
}
struct V_1 * F_171 ( struct V_198 * V_82 )
{
unsigned long V_15 ;
struct V_1 * V_199 ;
F_172 ( & V_82 -> V_200 , V_15 ) ;
V_199 = F_173 ( V_82 ) ;
F_174 ( & V_82 -> V_200 , V_15 ) ;
return V_199 ;
}
struct V_1 * F_175 ( struct V_198 * V_82 )
{
unsigned long V_15 ;
struct V_1 * V_199 ;
F_172 ( & V_82 -> V_200 , V_15 ) ;
V_199 = F_176 ( V_82 ) ;
F_174 ( & V_82 -> V_200 , V_15 ) ;
return V_199 ;
}
void F_177 ( struct V_198 * V_82 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_171 ( V_82 ) ) != NULL )
F_76 ( V_2 ) ;
}
void F_178 ( struct V_198 * V_82 , struct V_1 * V_201 )
{
unsigned long V_15 ;
F_172 ( & V_82 -> V_200 , V_15 ) ;
F_179 ( V_82 , V_201 ) ;
F_174 ( & V_82 -> V_200 , V_15 ) ;
}
void F_180 ( struct V_198 * V_82 , struct V_1 * V_201 )
{
unsigned long V_15 ;
F_172 ( & V_82 -> V_200 , V_15 ) ;
F_181 ( V_82 , V_201 ) ;
F_174 ( & V_82 -> V_200 , V_15 ) ;
}
void F_182 ( struct V_1 * V_2 , struct V_198 * V_82 )
{
unsigned long V_15 ;
F_172 ( & V_82 -> V_200 , V_15 ) ;
F_183 ( V_2 , V_82 ) ;
F_174 ( & V_82 -> V_200 , V_15 ) ;
}
void F_184 ( struct V_1 * V_124 , struct V_1 * V_201 , struct V_198 * V_82 )
{
unsigned long V_15 ;
F_172 ( & V_82 -> V_200 , V_15 ) ;
F_185 ( V_82 , V_124 , V_201 ) ;
F_174 ( & V_82 -> V_200 , V_15 ) ;
}
void F_186 ( struct V_1 * V_124 , struct V_1 * V_201 , struct V_198 * V_82 )
{
unsigned long V_15 ;
F_172 ( & V_82 -> V_200 , V_15 ) ;
F_187 ( V_201 , V_124 -> V_105 , V_124 , V_82 ) ;
F_174 ( & V_82 -> V_200 , V_15 ) ;
}
static inline void F_188 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_7 V_6 , const int V_185 )
{
int V_76 ;
F_141 ( V_2 , V_6 , F_108 ( V_44 , V_185 - V_6 ) ,
V_185 - V_6 ) ;
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ )
F_23 ( V_44 ) -> V_79 [ V_76 ] = F_23 ( V_2 ) -> V_79 [ V_76 ] ;
F_23 ( V_44 ) -> V_86 = F_23 ( V_2 ) -> V_86 ;
F_23 ( V_2 ) -> V_86 = 0 ;
V_44 -> V_78 = V_2 -> V_78 ;
V_44 -> V_6 += V_44 -> V_78 ;
V_2 -> V_78 = 0 ;
V_2 -> V_6 = V_6 ;
F_137 ( V_2 , V_6 ) ;
}
static inline void F_189 ( struct V_1 * V_2 ,
struct V_1 * V_44 ,
const T_7 V_6 , int V_185 )
{
int V_76 , V_148 = 0 ;
const int V_144 = F_23 ( V_2 ) -> V_86 ;
F_23 ( V_2 ) -> V_86 = 0 ;
V_44 -> V_6 = V_44 -> V_78 = V_2 -> V_6 - V_6 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_78 = V_6 - V_185 ;
for ( V_76 = 0 ; V_76 < V_144 ; V_76 ++ ) {
int V_14 = F_94 ( & F_23 ( V_2 ) -> V_79 [ V_76 ] ) ;
if ( V_185 + V_14 > V_6 ) {
F_23 ( V_44 ) -> V_79 [ V_148 ] = F_23 ( V_2 ) -> V_79 [ V_76 ] ;
if ( V_185 < V_6 ) {
F_113 ( V_2 , V_76 ) ;
F_23 ( V_44 ) -> V_79 [ 0 ] . V_115 += V_6 - V_185 ;
F_140 ( & F_23 ( V_44 ) -> V_79 [ 0 ] , V_6 - V_185 ) ;
F_135 ( & F_23 ( V_2 ) -> V_79 [ V_76 ] , V_6 - V_185 ) ;
F_23 ( V_2 ) -> V_86 ++ ;
}
V_148 ++ ;
} else
F_23 ( V_2 ) -> V_86 ++ ;
V_185 += V_14 ;
}
F_23 ( V_44 ) -> V_86 = V_148 ;
}
void F_190 ( struct V_1 * V_2 , struct V_1 * V_44 , const T_7 V_6 )
{
int V_185 = F_111 ( V_2 ) ;
F_23 ( V_44 ) -> V_87 = F_23 ( V_2 ) -> V_87 & V_202 ;
if ( V_6 < V_185 )
F_188 ( V_2 , V_44 , V_6 , V_185 ) ;
else
F_189 ( V_2 , V_44 , V_6 , V_185 ) ;
}
static int F_191 ( struct V_1 * V_2 )
{
return F_119 ( V_2 ) && F_115 ( V_2 , 0 , 0 , V_52 ) ;
}
int F_192 ( struct V_1 * V_203 , struct V_1 * V_2 , int V_204 )
{
int V_182 , V_153 , V_205 , V_206 ;
struct V_207 * V_208 , * V_209 ;
F_116 ( V_204 > V_2 -> V_6 ) ;
F_116 ( F_111 ( V_2 ) ) ;
V_206 = V_204 ;
V_182 = 0 ;
V_153 = F_23 ( V_203 ) -> V_86 ;
V_208 = & F_23 ( V_2 ) -> V_79 [ V_182 ] ;
if ( ! V_153 ||
! F_193 ( V_203 , V_153 , F_93 ( V_208 ) ,
V_208 -> V_115 ) ) {
V_205 = - 1 ;
} else {
V_205 = V_153 - 1 ;
V_206 -= F_94 ( V_208 ) ;
if ( V_206 < 0 ) {
if ( F_191 ( V_2 ) ||
F_191 ( V_203 ) )
return 0 ;
V_208 = & F_23 ( V_2 ) -> V_79 [ V_182 ] ;
V_209 = & F_23 ( V_203 ) -> V_79 [ V_205 ] ;
F_49 ( V_209 , V_204 ) ;
F_140 ( V_208 , V_204 ) ;
V_208 -> V_115 += V_204 ;
goto V_210;
}
V_182 ++ ;
}
if ( ( V_204 == V_2 -> V_6 ) &&
( F_23 ( V_2 ) -> V_86 - V_182 ) > ( V_170 - V_153 ) )
return 0 ;
if ( F_191 ( V_2 ) || F_191 ( V_203 ) )
return 0 ;
while ( ( V_206 > 0 ) && ( V_182 < F_23 ( V_2 ) -> V_86 ) ) {
if ( V_153 == V_170 )
return 0 ;
V_208 = & F_23 ( V_2 ) -> V_79 [ V_182 ] ;
V_209 = & F_23 ( V_203 ) -> V_79 [ V_153 ] ;
if ( V_206 >= F_94 ( V_208 ) ) {
* V_209 = * V_208 ;
V_206 -= F_94 ( V_208 ) ;
V_182 ++ ;
V_153 ++ ;
} else {
F_194 ( V_208 ) ;
V_209 -> V_59 = V_208 -> V_59 ;
V_209 -> V_115 = V_208 -> V_115 ;
F_135 ( V_209 , V_206 ) ;
V_208 -> V_115 += V_206 ;
F_140 ( V_208 , V_206 ) ;
V_206 = 0 ;
V_153 ++ ;
break;
}
}
F_23 ( V_203 ) -> V_86 = V_153 ;
if ( V_205 >= 0 ) {
V_208 = & F_23 ( V_2 ) -> V_79 [ 0 ] ;
V_209 = & F_23 ( V_203 ) -> V_79 [ V_205 ] ;
F_49 ( V_209 , F_94 ( V_208 ) ) ;
F_60 ( V_208 ) ;
}
V_153 = 0 ;
while ( V_182 < F_23 ( V_2 ) -> V_86 )
F_23 ( V_2 ) -> V_79 [ V_153 ++ ] = F_23 ( V_2 ) -> V_79 [ V_182 ++ ] ;
F_23 ( V_2 ) -> V_86 = V_153 ;
F_116 ( V_206 > 0 && ! F_23 ( V_2 ) -> V_86 ) ;
V_210:
V_203 -> V_116 = V_117 ;
V_2 -> V_116 = V_117 ;
V_2 -> V_6 -= V_204 ;
V_2 -> V_78 -= V_204 ;
V_2 -> V_27 -= V_204 ;
V_203 -> V_6 += V_204 ;
V_203 -> V_78 += V_204 ;
V_203 -> V_27 += V_204 ;
return V_204 ;
}
void F_195 ( struct V_1 * V_2 , unsigned int V_182 ,
unsigned int V_153 , struct V_211 * V_212 )
{
V_212 -> V_213 = V_182 ;
V_212 -> V_214 = V_153 ;
V_212 -> V_215 = V_212 -> V_216 = V_2 ;
V_212 -> V_217 = V_212 -> V_218 = 0 ;
V_212 -> V_219 = NULL ;
}
unsigned int F_196 ( unsigned int V_220 , const T_3 * * V_8 ,
struct V_211 * V_212 )
{
unsigned int V_221 , V_222 = V_220 + V_212 -> V_213 ;
T_4 * V_58 ;
if ( F_33 ( V_222 >= V_212 -> V_214 ) ) {
if ( V_212 -> V_219 ) {
F_95 ( V_212 -> V_219 ) ;
V_212 -> V_219 = NULL ;
}
return 0 ;
}
V_223:
V_221 = F_111 ( V_212 -> V_216 ) + V_212 -> V_218 ;
if ( V_222 < V_221 && ! V_212 -> V_219 ) {
* V_8 = V_212 -> V_216 -> V_8 + ( V_222 - V_212 -> V_218 ) ;
return V_221 - V_222 ;
}
if ( V_212 -> V_217 == 0 && ! V_212 -> V_219 )
V_212 -> V_218 += F_111 ( V_212 -> V_216 ) ;
while ( V_212 -> V_217 < F_23 ( V_212 -> V_216 ) -> V_86 ) {
V_58 = & F_23 ( V_212 -> V_216 ) -> V_79 [ V_212 -> V_217 ] ;
V_221 = F_94 ( V_58 ) + V_212 -> V_218 ;
if ( V_222 < V_221 ) {
if ( ! V_212 -> V_219 )
V_212 -> V_219 = F_92 ( F_93 ( V_58 ) ) ;
* V_8 = ( T_3 * ) V_212 -> V_219 + V_58 -> V_115 +
( V_222 - V_212 -> V_218 ) ;
return V_221 - V_222 ;
}
if ( V_212 -> V_219 ) {
F_95 ( V_212 -> V_219 ) ;
V_212 -> V_219 = NULL ;
}
V_212 -> V_217 ++ ;
V_212 -> V_218 += F_94 ( V_58 ) ;
}
if ( V_212 -> V_219 ) {
F_95 ( V_212 -> V_219 ) ;
V_212 -> V_219 = NULL ;
}
if ( V_212 -> V_215 == V_212 -> V_216 && F_114 ( V_212 -> V_215 ) ) {
V_212 -> V_216 = F_23 ( V_212 -> V_215 ) -> V_81 ;
V_212 -> V_217 = 0 ;
goto V_223;
} else if ( V_212 -> V_216 -> V_103 ) {
V_212 -> V_216 = V_212 -> V_216 -> V_103 ;
V_212 -> V_217 = 0 ;
goto V_223;
}
return 0 ;
}
void F_197 ( struct V_211 * V_212 )
{
if ( V_212 -> V_219 )
F_95 ( V_212 -> V_219 ) ;
}
static unsigned int F_198 ( unsigned int V_68 , const T_3 * * V_224 ,
struct V_225 * V_226 ,
struct V_227 * V_228 )
{
return F_196 ( V_68 , V_224 , F_199 ( V_228 ) ) ;
}
static void F_200 ( struct V_225 * V_226 , struct V_227 * V_228 )
{
F_197 ( F_199 ( V_228 ) ) ;
}
unsigned int F_201 ( struct V_1 * V_2 , unsigned int V_182 ,
unsigned int V_153 , struct V_225 * V_229 ,
struct V_227 * V_228 )
{
unsigned int V_181 ;
V_229 -> V_230 = F_198 ;
V_229 -> V_231 = F_200 ;
F_195 ( V_2 , V_182 , V_153 , F_199 ( V_228 ) ) ;
V_181 = F_202 ( V_229 , V_228 ) ;
return ( V_181 <= V_153 - V_182 ? V_181 : V_232 ) ;
}
int F_203 ( struct V_162 * V_106 , struct V_1 * V_2 ,
int (* F_204)( void * V_182 , char * V_153 , int V_68 ,
int V_6 , int V_233 , struct V_1 * V_2 ) ,
void * V_182 , int V_71 )
{
int V_234 = F_23 ( V_2 ) -> V_86 ;
int V_156 ;
int V_68 = 0 ;
int V_181 ;
struct V_163 * V_164 = & V_235 -> V_236 ;
do {
if ( V_234 >= V_170 )
return - V_237 ;
if ( ! F_145 ( V_106 , V_164 ) )
return - V_114 ;
V_156 = F_146 ( int , V_71 , V_164 -> V_14 - V_164 -> V_68 ) ;
V_181 = F_204 ( V_182 , F_39 ( V_164 -> V_59 ) + V_164 -> V_68 ,
V_68 , V_156 , 0 , V_2 ) ;
if ( V_181 < 0 )
return - V_158 ;
F_47 ( V_2 , V_234 , V_164 -> V_59 , V_164 -> V_68 ,
V_156 ) ;
V_234 ++ ;
V_164 -> V_68 += V_156 ;
F_149 ( V_164 -> V_59 ) ;
V_2 -> V_27 += V_156 ;
F_36 ( V_156 , & V_106 -> V_238 ) ;
V_2 -> V_6 += V_156 ;
V_2 -> V_78 += V_156 ;
V_68 += V_156 ;
V_71 -= V_156 ;
} while ( V_71 > 0 );
return 0 ;
}
unsigned char * F_205 ( struct V_1 * V_2 , unsigned int V_6 )
{
F_116 ( V_6 > V_2 -> V_6 ) ;
V_2 -> V_6 -= V_6 ;
F_116 ( V_2 -> V_6 < V_2 -> V_78 ) ;
F_206 ( V_2 , V_2 -> V_8 , V_6 ) ;
return V_2 -> V_8 += V_6 ;
}
struct V_1 * F_207 ( struct V_1 * V_239 ,
T_8 V_240 )
{
struct V_1 * V_102 = NULL ;
struct V_1 * V_9 = NULL ;
struct V_1 * V_241 = F_23 ( V_239 ) -> V_81 ;
T_4 * V_58 = F_23 ( V_239 ) -> V_79 ;
unsigned int V_242 = F_23 ( V_239 ) -> V_125 ;
unsigned int V_243 = V_239 -> V_8 - F_208 ( V_239 ) ;
struct V_1 * V_244 = V_239 ;
unsigned int V_68 = V_243 ;
unsigned int V_245 = F_209 ( V_239 ) ;
unsigned int V_129 ;
unsigned int V_6 ;
T_9 V_246 ;
bool V_183 ;
int V_247 = ! ! ( V_240 & V_248 ) ;
int V_144 = F_23 ( V_239 ) -> V_86 ;
int V_140 = - V_114 ;
int V_76 = 0 ;
int V_185 ;
int V_249 ;
F_210 ( V_239 , V_243 ) ;
V_246 = F_211 ( V_239 , & V_249 ) ;
if ( F_33 ( ! V_246 ) )
return F_212 ( - V_250 ) ;
V_183 = ! V_239 -> V_251 &&
! ! F_213 ( V_240 , V_246 ) ;
V_129 = F_86 ( V_239 ) ;
V_185 = F_111 ( V_239 ) ;
do {
struct V_1 * V_252 ;
T_4 * V_253 ;
int V_254 ;
int V_14 ;
V_6 = V_239 -> V_6 - V_68 ;
if ( V_6 > V_242 )
V_6 = V_242 ;
V_254 = F_111 ( V_239 ) - V_68 ;
if ( V_254 < 0 )
V_254 = 0 ;
if ( V_254 > V_6 || ! V_247 )
V_254 = V_6 ;
if ( ! V_254 && V_76 >= V_144 && F_111 ( V_241 ) &&
( F_111 ( V_241 ) == V_6 || V_247 ) ) {
F_116 ( F_111 ( V_241 ) > V_6 ) ;
V_76 = 0 ;
V_144 = F_23 ( V_241 ) -> V_86 ;
V_58 = F_23 ( V_241 ) -> V_79 ;
V_244 = V_241 ;
V_185 += F_111 ( V_241 ) ;
while ( V_185 < V_68 + V_6 ) {
F_116 ( V_76 >= V_144 ) ;
V_14 = F_94 ( V_58 ) ;
if ( V_185 + V_14 > V_68 + V_6 )
break;
V_76 ++ ;
V_185 += V_14 ;
V_58 ++ ;
}
V_252 = F_99 ( V_241 , V_52 ) ;
V_241 = V_241 -> V_103 ;
if ( F_33 ( ! V_252 ) )
goto V_140;
if ( F_33 ( F_136 ( V_252 , V_6 ) ) ) {
F_76 ( V_252 ) ;
goto V_140;
}
V_254 = F_107 ( V_252 ) ;
if ( F_214 ( V_252 , V_243 + V_129 ) ) {
F_76 ( V_252 ) ;
goto V_140;
}
V_252 -> V_27 += F_107 ( V_252 ) - V_254 ;
F_63 ( V_252 ) ;
F_210 ( V_252 , V_243 ) ;
} else {
V_252 = F_14 ( V_254 + V_243 + V_129 ,
V_52 , F_105 ( V_239 ) ,
V_75 ) ;
if ( F_33 ( ! V_252 ) )
goto V_140;
F_45 ( V_252 , V_129 ) ;
F_215 ( V_252 , V_243 ) ;
}
if ( V_102 )
V_9 -> V_103 = V_252 ;
else
V_102 = V_252 ;
V_9 = V_252 ;
F_85 ( V_252 , V_239 ) ;
F_102 ( V_252 , F_86 ( V_252 ) - V_129 ) ;
F_216 ( V_252 ) ;
F_141 ( V_239 , - V_245 ,
V_252 -> V_8 - V_245 ,
V_243 + V_245 ) ;
if ( V_252 -> V_6 == V_6 + V_243 )
goto V_255;
if ( ! V_247 ) {
V_252 -> V_116 = V_256 ;
V_252 -> V_183 = F_163 ( V_239 , V_68 ,
F_108 ( V_252 , V_6 ) ,
V_6 , 0 ) ;
F_217 ( V_252 ) -> V_118 =
F_86 ( V_252 ) + V_243 ;
continue;
}
V_253 = F_23 ( V_252 ) -> V_79 ;
F_141 ( V_239 , V_68 ,
F_108 ( V_252 , V_254 ) , V_254 ) ;
F_23 ( V_252 ) -> V_87 = F_23 ( V_239 ) -> V_87 &
V_202 ;
while ( V_185 < V_68 + V_6 ) {
if ( V_76 >= V_144 ) {
F_116 ( F_111 ( V_241 ) ) ;
V_76 = 0 ;
V_144 = F_23 ( V_241 ) -> V_86 ;
V_58 = F_23 ( V_241 ) -> V_79 ;
V_244 = V_241 ;
F_116 ( ! V_144 ) ;
V_241 = V_241 -> V_103 ;
}
if ( F_33 ( F_23 ( V_252 ) -> V_86 >=
V_170 ) ) {
F_218 (
L_3 ,
V_185 , V_242 ) ;
goto V_140;
}
if ( F_33 ( F_100 ( V_244 , V_52 ) ) )
goto V_140;
* V_253 = * V_58 ;
F_194 ( V_253 ) ;
V_14 = F_94 ( V_253 ) ;
if ( V_185 < V_68 ) {
V_253 -> V_115 += V_68 - V_185 ;
F_140 ( V_253 , V_68 - V_185 ) ;
}
F_23 ( V_252 ) -> V_86 ++ ;
if ( V_185 + V_14 <= V_68 + V_6 ) {
V_76 ++ ;
V_58 ++ ;
V_185 += V_14 ;
} else {
F_140 ( V_253 , V_185 + V_14 - ( V_68 + V_6 ) ) ;
goto V_257;
}
V_253 ++ ;
}
V_257:
V_252 -> V_78 = V_6 - V_254 ;
V_252 -> V_6 += V_252 -> V_78 ;
V_252 -> V_27 += V_252 -> V_78 ;
V_255:
if ( ! V_183 ) {
V_252 -> V_183 = F_162 ( V_252 , V_243 ,
V_252 -> V_6 - V_243 , 0 ) ;
V_252 -> V_116 = V_256 ;
F_217 ( V_252 ) -> V_118 =
F_86 ( V_252 ) + V_243 ;
}
} while ( ( V_68 += V_6 ) < V_239 -> V_6 );
V_102 -> V_105 = V_9 ;
return V_102 ;
V_140:
F_51 ( V_102 ) ;
return F_212 ( V_140 ) ;
}
int F_219 ( struct V_1 * * V_7 , struct V_1 * V_2 )
{
struct V_32 * V_258 , * V_259 = F_23 ( V_2 ) ;
unsigned int V_68 = F_220 ( V_2 ) ;
unsigned int V_260 = F_111 ( V_2 ) ;
struct V_1 * V_252 , * V_261 , * V_262 = * V_7 ;
unsigned int V_6 = F_221 ( V_2 ) ;
unsigned int V_263 ;
unsigned int V_129 ;
if ( F_33 ( V_262 -> V_6 + V_6 >= 65536 ) )
return - V_264 ;
V_261 = F_222 ( V_262 ) -> V_265 ;
V_258 = F_23 ( V_261 ) ;
if ( V_260 <= V_68 ) {
T_4 * V_58 ;
T_4 * V_266 ;
int V_76 = V_259 -> V_86 ;
int V_86 = V_258 -> V_86 + V_76 ;
if ( V_86 > V_170 )
goto V_205;
V_68 -= V_260 ;
V_258 -> V_86 = V_86 ;
V_259 -> V_86 = 0 ;
V_58 = V_258 -> V_79 + V_86 ;
V_266 = V_259 -> V_79 + V_76 ;
do {
* -- V_58 = * -- V_266 ;
} while ( -- V_76 );
V_58 -> V_115 += V_68 ;
F_140 ( V_58 , V_68 ) ;
V_263 = V_2 -> V_27 -
F_21 ( F_107 ( V_2 ) ) ;
V_2 -> V_27 -= V_2 -> V_78 ;
V_2 -> V_6 -= V_2 -> V_78 ;
V_2 -> V_78 = 0 ;
F_222 ( V_2 ) -> free = V_267 ;
goto V_146;
} else if ( V_2 -> V_53 ) {
int V_86 = V_258 -> V_86 ;
T_4 * V_58 = V_258 -> V_79 + V_86 ;
struct V_59 * V_59 = F_44 ( V_2 -> V_7 ) ;
unsigned int V_268 = V_260 - V_68 ;
unsigned int V_269 ;
if ( V_86 + 1 + V_259 -> V_86 > V_170 )
goto V_205;
V_269 = V_2 -> V_8 -
( unsigned char * ) F_39 ( V_59 ) +
V_68 ;
V_258 -> V_86 = V_86 + 1 + V_259 -> V_86 ;
V_58 -> V_59 . V_262 = V_59 ;
V_58 -> V_115 = V_269 ;
F_135 ( V_58 , V_268 ) ;
memcpy ( V_58 + 1 , V_259 -> V_79 , sizeof( * V_58 ) * V_259 -> V_86 ) ;
V_263 = V_2 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
F_222 ( V_2 ) -> free = V_270 ;
goto V_146;
}
V_258 = F_23 ( V_262 ) ;
if ( V_258 -> V_81 )
goto V_205;
if ( F_221 ( V_262 ) != V_258 -> V_125 )
return - V_264 ;
V_129 = F_86 ( V_262 ) ;
V_252 = F_223 ( V_129 + F_220 ( V_262 ) , V_52 ) ;
if ( F_33 ( ! V_252 ) )
return - V_114 ;
F_85 ( V_252 , V_262 ) ;
V_252 -> V_107 = V_262 -> V_107 ;
F_45 ( V_252 , V_129 ) ;
F_215 ( V_252 , F_220 ( V_262 ) ) ;
F_224 ( V_252 , F_208 ( V_262 ) - V_262 -> V_8 ) ;
F_225 ( V_252 , F_226 ( V_262 ) ) ;
F_227 ( V_252 , F_228 ( V_262 ) ) ;
F_229 ( V_262 , F_220 ( V_262 ) ) ;
memcpy ( F_208 ( V_252 ) , F_208 ( V_262 ) ,
V_262 -> V_8 - F_208 ( V_262 ) ) ;
F_23 ( V_252 ) -> V_81 = V_262 ;
F_23 ( V_252 ) -> V_125 = V_258 -> V_125 ;
V_258 -> V_125 = 0 ;
F_230 ( V_262 ) ;
F_222 ( V_252 ) -> V_265 = V_262 ;
V_252 -> V_78 += V_262 -> V_6 ;
V_252 -> V_27 += V_262 -> V_27 ;
V_252 -> V_6 += V_262 -> V_6 ;
* V_7 = V_252 ;
V_252 -> V_103 = V_262 -> V_103 ;
V_262 -> V_103 = NULL ;
V_262 = V_252 ;
V_205:
V_263 = V_2 -> V_27 ;
if ( V_68 > V_260 ) {
unsigned int V_149 = V_68 - V_260 ;
V_259 -> V_79 [ 0 ] . V_115 += V_149 ;
F_140 ( & V_259 -> V_79 [ 0 ] , V_149 ) ;
V_2 -> V_78 -= V_149 ;
V_2 -> V_6 -= V_149 ;
V_68 = V_260 ;
}
F_229 ( V_2 , V_68 ) ;
if ( F_222 ( V_262 ) -> V_265 == V_262 )
F_23 ( V_262 ) -> V_81 = V_2 ;
else
F_222 ( V_262 ) -> V_265 -> V_103 = V_2 ;
F_222 ( V_262 ) -> V_265 = V_2 ;
F_230 ( V_2 ) ;
V_261 = V_262 ;
V_146:
F_222 ( V_262 ) -> V_271 ++ ;
V_262 -> V_78 += V_6 ;
V_262 -> V_27 += V_263 ;
V_262 -> V_6 += V_6 ;
if ( V_261 != V_262 ) {
V_261 -> V_78 += V_6 ;
V_261 -> V_27 += V_263 ;
V_261 -> V_6 += V_6 ;
}
F_222 ( V_2 ) -> V_272 = 1 ;
return 0 ;
}
void T_10 F_231 ( void )
{
V_25 = F_232 ( L_4 ,
sizeof( struct V_1 ) ,
0 ,
V_273 | V_274 ,
NULL ) ;
V_35 = F_232 ( L_5 ,
sizeof( struct V_42 ) ,
0 ,
V_273 | V_274 ,
NULL ) ;
}
static int
F_233 ( struct V_1 * V_2 , struct V_275 * V_247 , int V_68 , int V_6 )
{
int V_154 = F_111 ( V_2 ) ;
int V_76 , V_156 = V_154 - V_68 ;
struct V_1 * V_155 ;
int V_276 = 0 ;
if ( V_156 > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
F_234 ( V_247 , V_2 -> V_8 + V_68 , V_156 ) ;
V_276 ++ ;
if ( ( V_6 -= V_156 ) == 0 )
return V_276 ;
V_68 += V_156 ;
}
for ( V_76 = 0 ; V_76 < F_23 ( V_2 ) -> V_86 ; V_76 ++ ) {
int V_10 ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + F_94 ( & F_23 ( V_2 ) -> V_79 [ V_76 ] ) ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
T_4 * V_58 = & F_23 ( V_2 ) -> V_79 [ V_76 ] ;
if ( V_156 > V_6 )
V_156 = V_6 ;
F_235 ( & V_247 [ V_276 ] , F_93 ( V_58 ) , V_156 ,
V_58 -> V_115 + V_68 - V_154 ) ;
V_276 ++ ;
if ( ! ( V_6 -= V_156 ) )
return V_276 ;
V_68 += V_156 ;
}
V_154 = V_10 ;
}
F_54 (skb, frag_iter) {
int V_10 ;
F_67 ( V_154 > V_68 + V_6 ) ;
V_10 = V_154 + V_155 -> V_6 ;
if ( ( V_156 = V_10 - V_68 ) > 0 ) {
if ( V_156 > V_6 )
V_156 = V_6 ;
V_276 += F_233 ( V_155 , V_247 + V_276 , V_68 - V_154 ,
V_156 ) ;
if ( ( V_6 -= V_156 ) == 0 )
return V_276 ;
V_68 += V_156 ;
}
V_154 = V_10 ;
}
F_116 ( V_6 ) ;
return V_276 ;
}
int F_236 ( struct V_1 * V_2 , struct V_275 * V_247 ,
int V_68 , int V_6 )
{
return F_233 ( V_2 , V_247 , V_68 , V_6 ) ;
}
int F_237 ( struct V_1 * V_2 , struct V_275 * V_247 , int V_68 , int V_6 )
{
int V_277 = F_233 ( V_2 , V_247 , V_68 , V_6 ) ;
F_238 ( & V_247 [ V_277 - 1 ] ) ;
return V_277 ;
}
int F_239 ( struct V_1 * V_2 , int V_278 , struct V_1 * * V_279 )
{
int V_280 ;
int V_276 ;
struct V_1 * V_44 , * * V_281 ;
if ( ( F_119 ( V_2 ) || F_23 ( V_2 ) -> V_86 ) &&
F_138 ( V_2 , F_240 ( V_2 ) - F_111 ( V_2 ) ) == NULL )
return - V_114 ;
if ( ! F_114 ( V_2 ) ) {
if ( F_125 ( V_2 ) < V_278 &&
F_115 ( V_2 , 0 , V_278 - F_125 ( V_2 ) + 128 , V_52 ) )
return - V_114 ;
* V_279 = V_2 ;
return 1 ;
}
V_276 = 1 ;
V_281 = & F_23 ( V_2 ) -> V_81 ;
V_280 = 0 ;
while ( ( V_44 = * V_281 ) != NULL ) {
int V_131 = 0 ;
if ( F_117 ( V_44 ) )
V_280 = 1 ;
if ( V_44 -> V_103 == NULL && V_278 ) {
if ( F_23 ( V_44 ) -> V_86 ||
F_114 ( V_44 ) ||
F_125 ( V_44 ) < V_278 )
V_131 = V_278 + 128 ;
}
if ( V_280 ||
F_119 ( V_44 ) ||
V_131 ||
F_23 ( V_44 ) -> V_86 ||
F_114 ( V_44 ) ) {
struct V_1 * V_45 ;
if ( V_131 == 0 )
V_45 = F_106 ( V_44 , V_52 ) ;
else
V_45 = F_123 ( V_44 ,
F_86 ( V_44 ) ,
V_131 ,
V_52 ) ;
if ( F_33 ( V_45 == NULL ) )
return - V_114 ;
if ( V_44 -> V_106 )
F_241 ( V_45 , V_44 -> V_106 ) ;
V_45 -> V_103 = V_44 -> V_103 ;
* V_281 = V_45 ;
F_76 ( V_44 ) ;
V_44 = V_45 ;
}
V_276 ++ ;
* V_279 = V_44 ;
V_281 = & V_44 -> V_103 ;
}
return V_276 ;
}
static void F_242 ( struct V_1 * V_2 )
{
struct V_162 * V_106 = V_2 -> V_106 ;
F_243 ( V_2 -> V_27 , & V_106 -> V_282 ) ;
}
int F_244 ( struct V_162 * V_106 , struct V_1 * V_2 )
{
if ( F_37 ( & V_106 -> V_282 ) + V_2 -> V_27 >=
( unsigned int ) V_106 -> V_283 )
return - V_114 ;
F_245 ( V_2 ) ;
V_2 -> V_106 = V_106 ;
V_2 -> V_95 = F_242 ;
F_36 ( V_2 -> V_27 , & V_106 -> V_282 ) ;
F_246 ( V_2 ) ;
F_180 ( & V_106 -> V_284 , V_2 ) ;
if ( ! F_247 ( V_106 , V_285 ) )
V_106 -> V_286 ( V_106 ) ;
return 0 ;
}
struct V_1 * F_248 ( struct V_162 * V_106 )
{
struct V_198 * V_287 = & V_106 -> V_284 ;
struct V_1 * V_2 , * V_288 ;
int V_140 = 0 ;
F_249 ( & V_287 -> V_200 ) ;
V_2 = F_173 ( V_287 ) ;
if ( V_2 && ( V_288 = F_250 ( V_287 ) ) )
V_140 = F_251 ( V_288 ) -> V_289 . V_290 ;
F_252 ( & V_287 -> V_200 ) ;
V_106 -> V_291 = V_140 ;
if ( V_140 )
V_106 -> V_292 ( V_106 ) ;
return V_2 ;
}
struct V_1 * F_253 ( struct V_1 * V_2 )
{
struct V_162 * V_106 = V_2 -> V_106 ;
struct V_1 * V_151 ;
if ( ! V_106 || ! F_254 ( & V_106 -> V_293 ) )
return NULL ;
V_151 = F_99 ( V_2 , V_52 ) ;
if ( ! V_151 ) {
F_255 ( V_106 ) ;
return NULL ;
}
V_151 -> V_106 = V_106 ;
V_151 -> V_95 = V_294 ;
return V_151 ;
}
static void F_256 ( struct V_1 * V_2 ,
struct V_162 * V_106 ,
int V_295 )
{
struct V_296 * V_297 ;
int V_140 ;
V_297 = F_251 ( V_2 ) ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_289 . V_290 = V_298 ;
V_297 -> V_289 . V_299 = V_300 ;
V_297 -> V_289 . V_301 = V_295 ;
if ( V_106 -> V_302 & V_303 ) {
V_297 -> V_289 . V_304 = F_23 ( V_2 ) -> V_305 ;
if ( V_106 -> V_306 == V_307 )
V_297 -> V_289 . V_304 -= V_106 -> V_308 ;
}
V_140 = F_244 ( V_106 , V_2 ) ;
if ( V_140 )
F_76 ( V_2 ) ;
}
void F_257 ( struct V_1 * V_2 ,
struct V_309 * V_310 )
{
struct V_162 * V_106 = V_2 -> V_106 ;
F_258 ( V_106 ) ;
* F_259 ( V_2 ) = * V_310 ;
F_256 ( V_2 , V_106 , V_311 ) ;
F_255 ( V_106 ) ;
}
void F_260 ( struct V_1 * V_312 ,
struct V_309 * V_310 ,
struct V_162 * V_106 , int V_295 )
{
struct V_1 * V_2 ;
if ( ! V_106 )
return;
if ( V_310 )
* F_259 ( V_312 ) = * V_310 ;
else
V_312 -> V_313 = F_261 () ;
V_2 = F_99 ( V_312 , V_52 ) ;
if ( ! V_2 )
return;
F_256 ( V_2 , V_106 , V_295 ) ;
}
void F_262 ( struct V_1 * V_312 ,
struct V_309 * V_310 )
{
return F_260 ( V_312 , V_310 , V_312 -> V_106 ,
V_311 ) ;
}
void F_263 ( struct V_1 * V_2 , bool V_314 )
{
struct V_162 * V_106 = V_2 -> V_106 ;
struct V_296 * V_297 ;
int V_140 ;
V_2 -> V_315 = 1 ;
V_2 -> V_316 = V_314 ;
V_297 = F_251 ( V_2 ) ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_289 . V_290 = V_298 ;
V_297 -> V_289 . V_299 = V_317 ;
F_258 ( V_106 ) ;
V_140 = F_244 ( V_106 , V_2 ) ;
if ( V_140 )
F_76 ( V_2 ) ;
F_255 ( V_106 ) ;
}
bool F_264 ( struct V_1 * V_2 , T_11 V_154 , T_11 V_77 )
{
if ( F_33 ( V_154 > F_111 ( V_2 ) ) ||
F_33 ( ( int ) V_154 + V_77 > F_111 ( V_2 ) - 2 ) ) {
F_218 ( L_6 ,
V_154 , V_77 , F_111 ( V_2 ) ) ;
return false ;
}
V_2 -> V_116 = V_117 ;
V_2 -> V_118 = F_86 ( V_2 ) + V_154 ;
V_2 -> V_196 = V_77 ;
F_227 ( V_2 , V_154 ) ;
return true ;
}
static int F_265 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_318 )
{
if ( F_111 ( V_2 ) >= V_6 )
return 0 ;
if ( V_318 > V_2 -> V_6 )
V_318 = V_2 -> V_6 ;
if ( F_138 ( V_2 , V_318 - F_111 ( V_2 ) ) == NULL )
return - V_114 ;
if ( F_111 ( V_2 ) < V_6 )
return - V_319 ;
return 0 ;
}
static int F_266 ( struct V_1 * V_2 , bool V_320 )
{
unsigned int V_77 ;
bool V_321 ;
V_197 * V_183 ;
int V_140 ;
V_321 = false ;
V_140 = F_265 ( V_2 ,
sizeof( struct V_322 ) ,
V_323 ) ;
if ( V_140 < 0 )
goto V_23;
if ( F_267 ( V_2 ) -> V_324 & F_268 ( V_325 | V_326 ) )
V_321 = true ;
V_77 = F_269 ( V_2 ) ;
V_140 = - V_319 ;
if ( V_321 )
goto V_23;
V_183 = F_270 ( V_2 , F_267 ( V_2 ) -> V_327 , V_77 ) ;
if ( F_271 ( V_183 ) )
return F_272 ( V_183 ) ;
if ( V_320 )
* V_183 = ~ F_273 ( F_267 ( V_2 ) -> V_328 ,
F_267 ( V_2 ) -> V_329 ,
V_2 -> V_6 - V_77 ,
F_267 ( V_2 ) -> V_327 , 0 ) ;
V_140 = 0 ;
V_23:
return V_140 ;
}
static int F_274 ( struct V_1 * V_2 , bool V_320 )
{
int V_140 ;
T_3 V_330 ;
unsigned int V_77 ;
unsigned int V_6 ;
bool V_321 ;
bool V_146 ;
V_197 * V_183 ;
V_321 = false ;
V_146 = false ;
V_77 = sizeof( struct V_331 ) ;
V_140 = F_265 ( V_2 , V_77 , V_332 ) ;
if ( V_140 < 0 )
goto V_23;
V_330 = F_275 ( V_2 ) -> V_330 ;
V_6 = sizeof( struct V_331 ) + F_276 ( F_275 ( V_2 ) -> V_333 ) ;
while ( V_77 <= V_6 && ! V_146 ) {
switch ( V_330 ) {
case V_334 :
case V_335 :
case V_336 : {
struct V_337 * V_338 ;
V_140 = F_265 ( V_2 ,
V_77 +
sizeof( struct V_337 ) ,
V_332 ) ;
if ( V_140 < 0 )
goto V_23;
V_338 = F_277 ( struct V_337 , V_2 , V_77 ) ;
V_330 = V_338 -> V_330 ;
V_77 += F_278 ( V_338 ) ;
break;
}
case V_339 : {
struct V_340 * V_338 ;
V_140 = F_265 ( V_2 ,
V_77 +
sizeof( struct V_340 ) ,
V_332 ) ;
if ( V_140 < 0 )
goto V_23;
V_338 = F_277 ( struct V_340 , V_2 , V_77 ) ;
V_330 = V_338 -> V_330 ;
V_77 += F_279 ( V_338 ) ;
break;
}
case V_341 : {
struct V_342 * V_338 ;
V_140 = F_265 ( V_2 ,
V_77 +
sizeof( struct V_342 ) ,
V_332 ) ;
if ( V_140 < 0 )
goto V_23;
V_338 = F_277 ( struct V_342 , V_2 , V_77 ) ;
if ( V_338 -> V_324 & F_268 ( V_343 | V_344 ) )
V_321 = true ;
V_330 = V_338 -> V_330 ;
V_77 += sizeof( struct V_342 ) ;
break;
}
default:
V_146 = true ;
break;
}
}
V_140 = - V_319 ;
if ( ! V_146 || V_321 )
goto V_23;
V_183 = F_270 ( V_2 , V_330 , V_77 ) ;
if ( F_271 ( V_183 ) )
return F_272 ( V_183 ) ;
if ( V_320 )
* V_183 = ~ F_280 ( & F_275 ( V_2 ) -> V_328 ,
& F_275 ( V_2 ) -> V_329 ,
V_2 -> V_6 - V_77 , V_330 , 0 ) ;
V_140 = 0 ;
V_23:
return V_140 ;
}
int F_281 ( struct V_1 * V_2 , bool V_320 )
{
int V_140 ;
switch ( V_2 -> V_327 ) {
case F_268 ( V_345 ) :
V_140 = F_266 ( V_2 , V_320 ) ;
break;
case F_268 ( V_346 ) :
V_140 = F_274 ( V_2 , V_320 ) ;
break;
default:
V_140 = - V_319 ;
break;
}
return V_140 ;
}
void F_282 ( const struct V_1 * V_2 )
{
F_218 ( L_7 ,
V_2 -> V_11 -> V_12 ) ;
}
void F_283 ( struct V_1 * V_2 , bool V_347 )
{
if ( V_347 ) {
F_63 ( V_2 ) ;
F_27 ( V_25 , V_2 ) ;
} else {
F_75 ( V_2 ) ;
}
}
bool F_284 ( struct V_1 * V_153 , struct V_1 * V_182 ,
bool * V_348 , int * V_263 )
{
int V_76 , V_133 , V_6 = V_182 -> V_6 ;
* V_348 = false ;
if ( F_119 ( V_153 ) )
return false ;
if ( V_6 <= F_125 ( V_153 ) ) {
if ( V_6 )
F_116 ( F_109 ( V_182 , 0 , F_108 ( V_153 , V_6 ) , V_6 ) ) ;
* V_263 = 0 ;
return true ;
}
if ( F_114 ( V_153 ) || F_114 ( V_182 ) )
return false ;
if ( F_111 ( V_182 ) != 0 ) {
struct V_59 * V_59 ;
unsigned int V_68 ;
if ( F_23 ( V_153 ) -> V_86 +
F_23 ( V_182 ) -> V_86 >= V_170 )
return false ;
if ( F_154 ( V_182 ) )
return false ;
V_133 = V_182 -> V_27 - F_17 ( sizeof( struct V_1 ) ) ;
V_59 = F_44 ( V_182 -> V_7 ) ;
V_68 = V_182 -> V_8 - ( unsigned char * ) F_39 ( V_59 ) ;
F_47 ( V_153 , F_23 ( V_153 ) -> V_86 ,
V_59 , V_68 , F_111 ( V_182 ) ) ;
* V_348 = true ;
} else {
if ( F_23 ( V_153 ) -> V_86 +
F_23 ( V_182 ) -> V_86 > V_170 )
return false ;
V_133 = V_182 -> V_27 - F_21 ( F_107 ( V_182 ) ) ;
}
F_285 ( V_133 < V_6 ) ;
memcpy ( F_23 ( V_153 ) -> V_79 + F_23 ( V_153 ) -> V_86 ,
F_23 ( V_182 ) -> V_79 ,
F_23 ( V_182 ) -> V_86 * sizeof( T_4 ) ) ;
F_23 ( V_153 ) -> V_86 += F_23 ( V_182 ) -> V_86 ;
if ( ! F_119 ( V_182 ) )
F_23 ( V_182 ) -> V_86 = 0 ;
for ( V_76 = 0 ; V_76 < F_23 ( V_182 ) -> V_86 ; V_76 ++ )
F_113 ( V_182 , V_76 ) ;
V_153 -> V_27 += V_133 ;
V_153 -> V_6 += V_6 ;
V_153 -> V_78 += V_6 ;
* V_263 = V_133 ;
return true ;
}
void F_286 ( struct V_1 * V_2 , bool V_349 )
{
if ( V_349 )
F_245 ( V_2 ) ;
V_2 -> V_313 . V_350 = 0 ;
V_2 -> V_351 = V_352 ;
V_2 -> V_353 = 0 ;
V_2 -> V_354 = 0 ;
F_64 ( V_2 ) ;
V_2 -> V_355 = 0 ;
F_287 ( V_2 ) ;
F_288 ( V_2 ) ;
F_289 ( V_2 ) ;
}
unsigned int F_290 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_23 ( V_2 ) ;
unsigned int V_356 = 0 ;
if ( V_2 -> V_357 ) {
V_356 = F_291 ( V_2 ) -
F_292 ( V_2 ) ;
if ( F_35 ( V_33 -> V_127 & ( V_358 | V_359 ) ) )
V_356 += F_293 ( V_2 ) ;
} else if ( F_35 ( V_33 -> V_127 & ( V_358 | V_359 ) ) ) {
V_356 = F_294 ( V_2 ) ;
}
return V_356 + V_33 -> V_125 ;
}
static struct V_1 * F_295 ( struct V_1 * V_2 )
{
if ( F_296 ( V_2 , F_86 ( V_2 ) ) < 0 ) {
F_76 ( V_2 ) ;
return NULL ;
}
memmove ( V_2 -> V_8 - V_360 , V_2 -> V_8 - V_361 , 2 * V_362 ) ;
V_2 -> V_29 += V_363 ;
return V_2 ;
}
struct V_1 * F_297 ( struct V_1 * V_2 )
{
struct V_364 * V_365 ;
T_11 V_366 ;
if ( F_33 ( F_298 ( V_2 ) ) ) {
return V_2 ;
}
V_2 = F_299 ( V_2 , V_52 ) ;
if ( F_33 ( ! V_2 ) )
goto V_367;
if ( F_33 ( ! F_300 ( V_2 , V_363 ) ) )
goto V_367;
V_365 = (struct V_364 * ) V_2 -> V_8 ;
V_366 = F_276 ( V_365 -> V_368 ) ;
F_301 ( V_2 , V_2 -> V_327 , V_366 ) ;
F_205 ( V_2 , V_363 ) ;
F_302 ( V_2 , V_365 ) ;
V_2 = F_295 ( V_2 ) ;
if ( F_33 ( ! V_2 ) )
goto V_367;
F_303 ( V_2 ) ;
F_304 ( V_2 ) ;
F_216 ( V_2 ) ;
return V_2 ;
V_367:
F_76 ( V_2 ) ;
return NULL ;
}
struct V_1 * F_305 ( unsigned long V_369 ,
unsigned long V_78 ,
int V_370 ,
int * V_371 ,
T_2 V_24 )
{
int V_372 = ( V_78 + ( V_64 - 1 ) ) >> V_373 ;
unsigned long V_374 ;
struct V_1 * V_2 ;
struct V_59 * V_59 ;
T_2 V_375 ;
int V_76 ;
* V_371 = - V_237 ;
if ( V_372 > V_170 )
return NULL ;
V_375 = V_24 ;
if ( V_375 & V_73 )
V_375 |= V_376 ;
* V_371 = - V_377 ;
V_2 = F_223 ( V_369 , V_375 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_27 += V_372 << V_373 ;
for ( V_76 = 0 ; V_372 > 0 ; V_76 ++ ) {
int V_57 = V_370 ;
while ( V_57 ) {
if ( V_372 >= 1 << V_57 ) {
V_59 = F_34 ( V_24 |
V_63 |
V_22 |
V_378 ,
V_57 ) ;
if ( V_59 )
goto V_379;
V_57 = 1 ;
V_370 = 0 ;
}
V_57 -- ;
}
V_59 = F_90 ( V_24 ) ;
if ( ! V_59 )
goto V_380;
V_379:
V_374 = F_146 (unsigned long, data_len,
PAGE_SIZE << order) ;
F_47 ( V_2 , V_76 , V_59 , 0 , V_374 ) ;
V_78 -= V_374 ;
V_372 -= 1 << V_57 ;
}
return V_2 ;
V_380:
F_76 ( V_2 ) ;
return NULL ;
}
