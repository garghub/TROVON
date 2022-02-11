static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 , & V_6 ) ) ;
}
static inline struct V_4 * F_5 ( struct V_1 * V_7 )
{
return F_6 ( & V_7 -> V_3 ) ;
}
static inline struct V_1 * F_7 ( struct V_8 * V_9 )
{
return F_3 ( V_9 -> V_10 -> V_11 ) ;
}
static struct V_1 * F_8 ( struct V_12 * V_13 )
{
if ( V_13 && V_13 -> V_14 )
return F_2 ( V_13 , struct V_1 , V_15 ) ;
else
return NULL ;
}
static struct V_8 * F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_7 = F_8 ( V_13 ) ;
if ( V_7 )
return V_7 -> V_9 ;
else
return F_2 ( V_13 , struct V_8 , V_15 ) ;
}
static void F_10 ( struct V_16 * V_17 )
{
static struct V_18 * V_19 ;
struct V_20 * V_21 = F_11 ( V_17 ) ;
bool V_22 = false ;
V_23:
if ( ! V_19 ) {
V_19 = F_12 ( struct V_18 ) ;
if ( ! V_19 ) {
F_13 ( V_21 , F_14 ( 10 ) ) ;
return;
}
}
F_15 ( & V_24 ) ;
if ( ! F_16 ( & V_25 ) ) {
struct V_1 * V_7 = F_17 ( & V_25 ,
struct V_1 ,
V_26 ) ;
F_18 ( V_7 -> V_19 , V_19 ) ;
F_19 ( & V_7 -> V_26 ) ;
}
V_22 = F_16 ( & V_25 ) ;
F_20 ( & V_24 ) ;
if ( ! V_22 )
goto V_23;
}
static void F_21 ( struct V_27 * V_28 , struct V_1 * V_7 )
{
F_22 ( & V_28 -> V_29 ) ;
F_23 ( & V_28 -> V_30 ) ;
V_28 -> V_7 = V_7 ;
}
static void F_24 ( struct V_31 * V_31 , struct V_27 * V_28 ,
struct V_32 * V_33 )
{
F_25 ( & V_28 -> V_30 , V_31 ) ;
if ( F_16 ( & V_28 -> V_29 ) ) {
F_26 ( & V_28 -> V_29 , V_33 ) ;
F_27 ( F_5 ( V_28 -> V_7 ) ) ;
}
}
static struct V_31 * F_28 ( struct V_32 * V_33 )
{
struct V_27 * V_28 = F_17 ( V_33 , struct V_27 , V_29 ) ;
struct V_31 * V_31 ;
if ( F_16 ( V_33 ) )
return NULL ;
V_31 = F_29 ( & V_28 -> V_30 ) ;
F_30 ( ! V_31 ) ;
return V_31 ;
}
static struct V_31 * F_31 ( struct V_32 * V_33 ,
struct V_1 * * V_34 )
{
struct V_27 * V_28 = F_17 ( V_33 , struct V_27 , V_29 ) ;
struct V_31 * V_31 ;
if ( F_16 ( V_33 ) )
return NULL ;
V_31 = F_32 ( & V_28 -> V_30 ) ;
F_30 ( ! V_31 ) ;
if ( F_33 ( & V_28 -> V_30 ) ) {
F_19 ( & V_28 -> V_29 ) ;
if ( V_34 )
* V_34 = V_28 -> V_7 ;
else
F_34 ( F_5 ( V_28 -> V_7 ) ) ;
} else {
F_35 ( & V_28 -> V_29 , V_33 ) ;
}
return V_31 ;
}
static void F_36 ( struct V_12 * V_13 ,
struct V_12 * V_14 )
{
F_22 ( & V_13 -> V_33 [ 0 ] ) ;
F_22 ( & V_13 -> V_33 [ 1 ] ) ;
V_13 -> V_35 = V_36 ;
V_13 -> V_14 = V_14 ;
F_37 ( & V_13 -> V_37 , V_38 ,
( unsigned long ) V_13 ) ;
}
static void F_38 ( struct V_12 * V_13 )
{
F_39 ( & V_13 -> V_37 ) ;
}
static void F_40 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = V_5 -> V_39 -> V_9 ;
struct V_12 * V_14 ;
unsigned long V_40 ;
int V_41 ;
V_14 = & V_9 -> V_15 ;
if ( F_41 ( V_5 -> V_42 -> V_43 . V_44 ) && V_5 -> V_45 )
V_14 = & F_3 ( V_5 -> V_45 ) -> V_15 ;
F_36 ( & V_7 -> V_15 , V_14 ) ;
for ( V_41 = V_46 ; V_41 <= V_47 ; V_41 ++ ) {
F_21 ( & V_7 -> V_48 [ V_41 ] , V_7 ) ;
F_21 ( & V_7 -> V_49 [ V_41 ] , V_7 ) ;
}
F_42 ( & V_7 -> V_50 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_51 [ V_46 ] = - 1 ;
V_7 -> V_51 [ V_47 ] = - 1 ;
V_7 -> V_52 [ V_46 ] = - 1 ;
V_7 -> V_52 [ V_47 ] = - 1 ;
F_43 ( & V_24 , V_40 ) ;
F_44 ( & V_7 -> V_26 , & V_25 ) ;
F_13 ( & V_53 , 0 ) ;
F_45 ( & V_24 , V_40 ) ;
}
static void F_46 ( struct V_1 * V_7 )
{
struct V_1 * V_54 = F_8 ( V_7 -> V_15 . V_14 ) ;
int V_41 ;
for ( V_41 = V_46 ; V_41 <= V_47 ; V_41 ++ )
V_7 -> V_55 [ V_41 ] = ( V_54 && V_54 -> V_55 [ V_41 ] ) ||
( V_7 -> V_51 [ V_41 ] != - 1 || V_7 -> V_52 [ V_41 ] != - 1 ) ;
}
static void F_47 ( struct V_4 * V_5 )
{
F_46 ( F_3 ( V_5 ) ) ;
}
static void F_48 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
unsigned long V_40 ;
F_43 ( & V_24 , V_40 ) ;
F_19 ( & V_7 -> V_26 ) ;
F_45 ( & V_24 , V_40 ) ;
F_49 ( V_7 -> V_19 ) ;
F_38 ( & V_7 -> V_15 ) ;
}
static void F_50 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
int V_56 ;
if ( V_7 -> V_19 == NULL )
return;
F_51 (cpu) {
struct V_18 * V_57 = F_52 ( V_7 -> V_19 , V_56 ) ;
F_53 ( & V_57 -> V_58 ) ;
F_53 ( & V_57 -> V_59 ) ;
}
}
static struct V_1 * F_54 ( struct V_8 * V_9 ,
struct V_42 * V_42 )
{
if ( V_42 == & V_60 )
return F_7 ( V_9 ) ;
return F_3 ( F_55 ( V_42 , V_9 -> V_10 ) ) ;
}
static struct V_1 * F_56 ( struct V_8 * V_9 ,
struct V_42 * V_42 )
{
struct V_61 * V_39 = V_9 -> V_10 ;
struct V_1 * V_7 = NULL ;
if ( V_42 == & V_60 ) {
V_7 = F_7 ( V_9 ) ;
} else {
struct V_4 * V_5 ;
V_5 = F_57 ( V_42 , V_39 ) ;
if ( ! F_58 ( V_5 ) )
V_7 = F_3 ( V_5 ) ;
else if ( ! F_59 ( V_39 ) )
V_7 = F_7 ( V_9 ) ;
}
return V_7 ;
}
static struct V_1 *
F_60 ( struct V_12 * V_14 )
{
if ( ! V_14 -> V_62 )
return NULL ;
if ( ! V_14 -> V_63 )
V_14 -> V_63 = F_61 ( & V_14 -> V_35 ) ;
if ( V_14 -> V_63 )
return F_62 ( V_14 -> V_63 ) ;
return NULL ;
}
static void F_63 ( struct V_50 * V_64 , struct V_65 * V_66 )
{
F_64 ( V_64 , V_66 ) ;
F_42 ( V_64 ) ;
}
static void F_65 ( struct V_50 * V_64 ,
struct V_12 * V_14 )
{
if ( V_14 -> V_63 == V_64 )
V_14 -> V_63 = NULL ;
F_63 ( V_64 , & V_14 -> V_35 ) ;
-- V_14 -> V_62 ;
}
static void F_66 ( struct V_12 * V_14 )
{
struct V_1 * V_7 ;
V_7 = F_60 ( V_14 ) ;
if ( ! V_7 )
return;
V_14 -> V_67 = V_7 -> V_68 ;
}
static void F_67 ( struct V_1 * V_7 )
{
struct V_12 * V_14 = V_7 -> V_15 . V_14 ;
struct V_50 * * V_29 = & V_14 -> V_35 . V_50 ;
struct V_50 * V_45 = NULL ;
struct V_1 * V_69 ;
unsigned long V_70 = V_7 -> V_68 ;
int V_71 = 1 ;
while ( * V_29 != NULL ) {
V_45 = * V_29 ;
V_69 = F_62 ( V_45 ) ;
if ( F_68 ( V_70 , V_69 -> V_68 ) )
V_29 = & V_45 -> V_72 ;
else {
V_29 = & V_45 -> V_73 ;
V_71 = 0 ;
}
}
if ( V_71 )
V_14 -> V_63 = & V_7 -> V_50 ;
F_69 ( & V_7 -> V_50 , V_45 , V_29 ) ;
F_70 ( & V_7 -> V_50 , & V_14 -> V_35 ) ;
}
static void F_71 ( struct V_1 * V_7 )
{
F_67 ( V_7 ) ;
V_7 -> V_40 |= V_74 ;
V_7 -> V_15 . V_14 -> V_62 ++ ;
}
static void F_72 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_40 & V_74 ) )
F_71 ( V_7 ) ;
}
static void F_73 ( struct V_1 * V_7 )
{
F_65 ( & V_7 -> V_50 , V_7 -> V_15 . V_14 ) ;
V_7 -> V_40 &= ~ V_74 ;
}
static void F_74 ( struct V_1 * V_7 )
{
if ( V_7 -> V_40 & V_74 )
F_73 ( V_7 ) ;
}
static void F_75 ( struct V_12 * V_13 ,
unsigned long V_75 )
{
F_76 ( & V_13 -> V_37 , V_75 ) ;
F_77 ( V_13 , L_1 ,
V_75 - V_76 , V_76 ) ;
}
static bool F_78 ( struct V_12 * V_13 ,
bool V_77 )
{
if ( ! V_13 -> V_62 )
return true ;
F_66 ( V_13 ) ;
if ( V_77 || F_79 ( V_13 -> V_67 , V_76 ) ) {
F_75 ( V_13 , V_13 -> V_67 ) ;
return true ;
}
return false ;
}
static inline void F_80 ( struct V_1 * V_7 ,
bool V_41 , unsigned long V_78 )
{
V_7 -> V_79 [ V_41 ] = 0 ;
V_7 -> V_80 [ V_41 ] = 0 ;
if ( F_81 ( V_78 , V_7 -> V_81 [ V_41 ] ) )
V_7 -> V_81 [ V_41 ] = V_78 ;
V_7 -> V_82 [ V_41 ] = V_76 + V_83 ;
F_77 ( & V_7 -> V_15 ,
L_2 ,
V_41 == V_46 ? 'R' : 'W' , V_7 -> V_81 [ V_41 ] ,
V_7 -> V_82 [ V_41 ] , V_76 ) ;
}
static inline void F_82 ( struct V_1 * V_7 , bool V_41 )
{
V_7 -> V_79 [ V_41 ] = 0 ;
V_7 -> V_80 [ V_41 ] = 0 ;
V_7 -> V_81 [ V_41 ] = V_76 ;
V_7 -> V_82 [ V_41 ] = V_76 + V_83 ;
F_77 ( & V_7 -> V_15 ,
L_3 ,
V_41 == V_46 ? 'R' : 'W' , V_7 -> V_81 [ V_41 ] ,
V_7 -> V_82 [ V_41 ] , V_76 ) ;
}
static inline void F_83 ( struct V_1 * V_7 , bool V_41 ,
unsigned long V_84 )
{
V_7 -> V_82 [ V_41 ] = F_84 ( V_84 , V_83 ) ;
}
static inline void F_85 ( struct V_1 * V_7 , bool V_41 ,
unsigned long V_84 )
{
V_7 -> V_82 [ V_41 ] = F_84 ( V_84 , V_83 ) ;
F_77 ( & V_7 -> V_15 ,
L_4 ,
V_41 == V_46 ? 'R' : 'W' , V_7 -> V_81 [ V_41 ] ,
V_7 -> V_82 [ V_41 ] , V_76 ) ;
}
static bool F_86 ( struct V_1 * V_7 , bool V_41 )
{
if ( F_87 ( V_76 , V_7 -> V_81 [ V_41 ] , V_7 -> V_82 [ V_41 ] ) )
return 0 ;
return 1 ;
}
static inline void F_88 ( struct V_1 * V_7 , bool V_41 )
{
unsigned long V_85 , V_86 , V_87 ;
T_1 V_88 , V_89 ;
F_89 ( F_68 ( V_7 -> V_82 [ V_41 ] , V_7 -> V_81 [ V_41 ] ) ) ;
if ( F_86 ( V_7 , V_41 ) )
return;
F_83 ( V_7 , V_41 , V_76 + V_83 ) ;
V_86 = V_76 - V_7 -> V_81 [ V_41 ] ;
V_85 = V_86 / V_83 ;
if ( ! V_85 )
return;
V_89 = V_7 -> V_51 [ V_41 ] * V_83 * V_85 ;
F_90 ( V_89 , V_90 ) ;
V_88 = V_89 ;
V_87 = ( V_7 -> V_52 [ V_41 ] * V_83 * V_85 ) / V_90 ;
if ( ! V_88 && ! V_87 )
return;
if ( V_7 -> V_79 [ V_41 ] >= V_88 )
V_7 -> V_79 [ V_41 ] -= V_88 ;
else
V_7 -> V_79 [ V_41 ] = 0 ;
if ( V_7 -> V_80 [ V_41 ] >= V_87 )
V_7 -> V_80 [ V_41 ] -= V_87 ;
else
V_7 -> V_80 [ V_41 ] = 0 ;
V_7 -> V_81 [ V_41 ] += V_85 * V_83 ;
F_77 ( & V_7 -> V_15 ,
L_5 ,
V_41 == V_46 ? 'R' : 'W' , V_85 , V_88 , V_87 ,
V_7 -> V_81 [ V_41 ] , V_7 -> V_82 [ V_41 ] , V_76 ) ;
}
static bool F_91 ( struct V_1 * V_7 , struct V_31 * V_31 ,
unsigned long * V_91 )
{
bool V_41 = F_92 ( V_31 ) ;
unsigned int V_92 ;
unsigned long V_93 , V_94 , V_95 ;
T_1 V_89 ;
V_93 = V_95 = V_76 - V_7 -> V_81 [ V_41 ] ;
if ( ! V_93 )
V_95 = V_83 ;
V_95 = F_84 ( V_95 , V_83 ) ;
V_89 = ( T_1 ) V_7 -> V_52 [ V_41 ] * V_95 ;
F_90 ( V_89 , V_90 ) ;
if ( V_89 > V_96 )
V_92 = V_96 ;
else
V_92 = V_89 ;
if ( V_7 -> V_80 [ V_41 ] + 1 <= V_92 ) {
if ( V_91 )
* V_91 = 0 ;
return 1 ;
}
V_94 = ( ( V_7 -> V_80 [ V_41 ] + 1 ) * V_90 ) / V_7 -> V_52 [ V_41 ] + 1 ;
if ( V_94 > V_93 )
V_94 = V_94 - V_93 ;
else
V_94 = 1 ;
if ( V_91 )
* V_91 = V_94 ;
return 0 ;
}
static bool F_93 ( struct V_1 * V_7 , struct V_31 * V_31 ,
unsigned long * V_91 )
{
bool V_41 = F_92 ( V_31 ) ;
T_1 V_97 , V_98 , V_89 ;
unsigned long V_93 , V_94 , V_95 ;
V_93 = V_95 = V_76 - V_7 -> V_81 [ V_41 ] ;
if ( ! V_93 )
V_95 = V_83 ;
V_95 = F_84 ( V_95 , V_83 ) ;
V_89 = V_7 -> V_51 [ V_41 ] * V_95 ;
F_90 ( V_89 , V_90 ) ;
V_97 = V_89 ;
if ( V_7 -> V_79 [ V_41 ] + V_31 -> V_99 <= V_97 ) {
if ( V_91 )
* V_91 = 0 ;
return 1 ;
}
V_98 = V_7 -> V_79 [ V_41 ] + V_31 -> V_99 - V_97 ;
V_94 = F_94 ( V_98 * V_90 , V_7 -> V_51 [ V_41 ] ) ;
if ( ! V_94 )
V_94 = 1 ;
V_94 = V_94 + ( V_95 - V_93 ) ;
if ( V_91 )
* V_91 = V_94 ;
return 0 ;
}
static bool F_95 ( struct V_1 * V_7 , struct V_31 * V_31 ,
unsigned long * V_91 )
{
bool V_41 = F_92 ( V_31 ) ;
unsigned long V_100 = 0 , V_101 = 0 , V_102 = 0 ;
F_89 ( V_7 -> V_15 . V_103 [ V_41 ] &&
V_31 != F_28 ( & V_7 -> V_15 . V_33 [ V_41 ] ) ) ;
if ( V_7 -> V_51 [ V_41 ] == - 1 && V_7 -> V_52 [ V_41 ] == - 1 ) {
if ( V_91 )
* V_91 = 0 ;
return 1 ;
}
if ( F_86 ( V_7 , V_41 ) )
F_82 ( V_7 , V_41 ) ;
else {
if ( F_68 ( V_7 -> V_82 [ V_41 ] , V_76 + V_83 ) )
F_85 ( V_7 , V_41 , V_76 + V_83 ) ;
}
if ( F_93 ( V_7 , V_31 , & V_100 ) &&
F_91 ( V_7 , V_31 , & V_101 ) ) {
if ( V_91 )
* V_91 = 0 ;
return 1 ;
}
V_102 = F_96 ( V_100 , V_101 ) ;
if ( V_91 )
* V_91 = V_102 ;
if ( F_68 ( V_7 -> V_82 [ V_41 ] , V_76 + V_102 ) )
F_85 ( V_7 , V_41 , V_76 + V_102 ) ;
return 0 ;
}
static void F_97 ( struct V_4 * V_5 , T_1 V_104 ,
int V_41 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct V_18 * V_19 ;
unsigned long V_40 ;
if ( V_7 -> V_19 == NULL )
return;
F_98 ( V_40 ) ;
V_19 = F_99 ( V_7 -> V_19 ) ;
F_100 ( & V_19 -> V_59 , V_41 , 1 ) ;
F_100 ( & V_19 -> V_58 , V_41 , V_104 ) ;
F_101 ( V_40 ) ;
}
static void F_102 ( struct V_1 * V_7 , struct V_31 * V_31 )
{
bool V_41 = F_92 ( V_31 ) ;
V_7 -> V_79 [ V_41 ] += V_31 -> V_99 ;
V_7 -> V_80 [ V_41 ] ++ ;
if ( ! ( V_31 -> V_105 & V_106 ) ) {
V_31 -> V_105 |= V_106 ;
F_97 ( F_5 ( V_7 ) , V_31 -> V_99 ,
V_31 -> V_105 ) ;
}
}
static void F_103 ( struct V_31 * V_31 , struct V_27 * V_28 ,
struct V_1 * V_7 )
{
struct V_12 * V_13 = & V_7 -> V_15 ;
bool V_41 = F_92 ( V_31 ) ;
if ( ! V_28 )
V_28 = & V_7 -> V_48 [ V_41 ] ;
if ( ! V_13 -> V_103 [ V_41 ] )
V_7 -> V_40 |= V_107 ;
F_24 ( V_31 , V_28 , & V_13 -> V_33 [ V_41 ] ) ;
V_13 -> V_103 [ V_41 ] ++ ;
F_72 ( V_7 ) ;
}
static void F_104 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = & V_7 -> V_15 ;
unsigned long V_108 = - 1 , V_109 = - 1 , V_110 = - 1 , V_68 ;
struct V_31 * V_31 ;
if ( ( V_31 = F_28 ( & V_13 -> V_33 [ V_46 ] ) ) )
F_95 ( V_7 , V_31 , & V_108 ) ;
if ( ( V_31 = F_28 ( & V_13 -> V_33 [ V_47 ] ) ) )
F_95 ( V_7 , V_31 , & V_109 ) ;
V_110 = F_105 ( V_108 , V_109 ) ;
V_68 = V_76 + V_110 ;
F_74 ( V_7 ) ;
V_7 -> V_68 = V_68 ;
F_72 ( V_7 ) ;
V_7 -> V_40 &= ~ V_107 ;
}
static void F_106 ( struct V_1 * V_111 ,
struct V_1 * V_54 , bool V_41 )
{
if ( F_86 ( V_54 , V_41 ) ) {
F_80 ( V_54 , V_41 ,
V_111 -> V_81 [ V_41 ] ) ;
}
}
static void F_107 ( struct V_1 * V_7 , bool V_41 )
{
struct V_12 * V_13 = & V_7 -> V_15 ;
struct V_12 * V_14 = V_13 -> V_14 ;
struct V_1 * V_54 = F_8 ( V_14 ) ;
struct V_1 * V_34 = NULL ;
struct V_31 * V_31 ;
V_31 = F_31 ( & V_13 -> V_33 [ V_41 ] , & V_34 ) ;
V_13 -> V_103 [ V_41 ] -- ;
F_102 ( V_7 , V_31 ) ;
if ( V_54 ) {
F_103 ( V_31 , & V_7 -> V_49 [ V_41 ] , V_54 ) ;
F_106 ( V_7 , V_54 , V_41 ) ;
} else {
F_24 ( V_31 , & V_7 -> V_49 [ V_41 ] ,
& V_14 -> V_33 [ V_41 ] ) ;
F_89 ( V_7 -> V_9 -> V_103 [ V_41 ] <= 0 ) ;
V_7 -> V_9 -> V_103 [ V_41 ] -- ;
}
F_88 ( V_7 , V_41 ) ;
if ( V_34 )
F_34 ( F_5 ( V_34 ) ) ;
}
static int F_108 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = & V_7 -> V_15 ;
unsigned int V_112 = 0 , V_113 = 0 ;
unsigned int V_114 = V_115 * 3 / 4 ;
unsigned int V_116 = V_115 - V_114 ;
struct V_31 * V_31 ;
while ( ( V_31 = F_28 ( & V_13 -> V_33 [ V_46 ] ) ) &&
F_95 ( V_7 , V_31 , NULL ) ) {
F_107 ( V_7 , F_92 ( V_31 ) ) ;
V_112 ++ ;
if ( V_112 >= V_114 )
break;
}
while ( ( V_31 = F_28 ( & V_13 -> V_33 [ V_47 ] ) ) &&
F_95 ( V_7 , V_31 , NULL ) ) {
F_107 ( V_7 , F_92 ( V_31 ) ) ;
V_113 ++ ;
if ( V_113 >= V_116 )
break;
}
return V_112 + V_113 ;
}
static int F_109 ( struct V_12 * V_14 )
{
unsigned int V_117 = 0 ;
while ( 1 ) {
struct V_1 * V_7 = F_60 ( V_14 ) ;
struct V_12 * V_13 = & V_7 -> V_15 ;
if ( ! V_7 )
break;
if ( F_68 ( V_76 , V_7 -> V_68 ) )
break;
F_74 ( V_7 ) ;
V_117 += F_108 ( V_7 ) ;
if ( V_13 -> V_103 [ 0 ] || V_13 -> V_103 [ 1 ] )
F_104 ( V_7 ) ;
if ( V_117 >= V_118 )
break;
}
return V_117 ;
}
static void V_38 ( unsigned long V_119 )
{
struct V_12 * V_13 = ( void * ) V_119 ;
struct V_1 * V_7 = F_8 ( V_13 ) ;
struct V_8 * V_9 = F_9 ( V_13 ) ;
struct V_61 * V_39 = V_9 -> V_10 ;
struct V_12 * V_14 ;
bool V_120 ;
int V_121 ;
F_15 ( V_39 -> V_122 ) ;
V_123:
V_14 = V_13 -> V_14 ;
V_120 = false ;
while ( true ) {
F_77 ( V_13 , L_6 ,
V_13 -> V_103 [ V_46 ] + V_13 -> V_103 [ V_47 ] ,
V_13 -> V_103 [ V_46 ] , V_13 -> V_103 [ V_47 ] ) ;
V_121 = F_109 ( V_13 ) ;
if ( V_121 ) {
F_77 ( V_13 , L_7 , V_121 ) ;
V_120 = true ;
}
if ( F_78 ( V_13 , false ) )
break;
F_20 ( V_39 -> V_122 ) ;
F_110 () ;
F_15 ( V_39 -> V_122 ) ;
}
if ( ! V_120 )
goto V_124;
if ( V_14 ) {
if ( V_7 -> V_40 & V_107 ) {
F_104 ( V_7 ) ;
if ( ! F_78 ( V_14 , false ) ) {
V_13 = V_14 ;
V_7 = F_8 ( V_13 ) ;
goto V_123;
}
}
} else {
F_111 ( V_125 , & V_9 -> V_126 ) ;
}
V_124:
F_20 ( V_39 -> V_122 ) ;
}
void F_112 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = F_2 ( V_17 , struct V_8 ,
V_126 ) ;
struct V_12 * V_127 = & V_9 -> V_15 ;
struct V_61 * V_39 = V_9 -> V_10 ;
struct V_128 V_129 ;
struct V_31 * V_31 ;
struct V_130 V_131 ;
int V_41 ;
F_23 ( & V_129 ) ;
F_15 ( V_39 -> V_122 ) ;
for ( V_41 = V_46 ; V_41 <= V_47 ; V_41 ++ )
while ( ( V_31 = F_31 ( & V_127 -> V_33 [ V_41 ] , NULL ) ) )
F_25 ( & V_129 , V_31 ) ;
F_20 ( V_39 -> V_122 ) ;
if ( ! F_33 ( & V_129 ) ) {
F_113 ( & V_131 ) ;
while( ( V_31 = F_32 ( & V_129 ) ) )
F_114 ( V_31 ) ;
F_115 ( & V_131 ) ;
}
}
static T_1 F_116 ( struct V_132 * V_133 ,
struct V_2 * V_3 , int V_134 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_135 V_136 = { } , V_89 ;
int V_137 , V_56 ;
F_51 (cpu) {
struct V_18 * V_57 = F_52 ( V_7 -> V_19 , V_56 ) ;
V_89 = F_117 ( ( void * ) V_57 + V_134 ) ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ )
V_136 . V_139 [ V_137 ] += V_89 . V_139 [ V_137 ] ;
}
return F_118 ( V_133 , V_3 , & V_136 ) ;
}
static int F_119 ( struct V_140 * V_43 ,
struct V_141 * V_142 , struct V_132 * V_133 )
{
struct V_42 * V_42 = F_120 ( V_43 ) ;
F_121 ( V_133 , V_42 , F_116 , & V_6 ,
V_142 -> V_143 , true ) ;
return 0 ;
}
static T_1 F_122 ( struct V_132 * V_133 , struct V_2 * V_3 ,
int V_134 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_144 = * ( T_1 * ) ( ( void * ) V_7 + V_134 ) ;
if ( V_144 == - 1 )
return 0 ;
return F_123 ( V_133 , V_3 , V_144 ) ;
}
static T_1 F_124 ( struct V_132 * V_133 , struct V_2 * V_3 ,
int V_134 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_144 = * ( unsigned int * ) ( ( void * ) V_7 + V_134 ) ;
if ( V_144 == - 1 )
return 0 ;
return F_123 ( V_133 , V_3 , V_144 ) ;
}
static int F_125 ( struct V_140 * V_43 ,
struct V_141 * V_142 , struct V_132 * V_133 )
{
F_121 ( V_133 , F_120 ( V_43 ) , F_122 ,
& V_6 , V_142 -> V_143 , false ) ;
return 0 ;
}
static int F_126 ( struct V_140 * V_43 ,
struct V_141 * V_142 , struct V_132 * V_133 )
{
F_121 ( V_133 , F_120 ( V_43 ) , F_124 ,
& V_6 , V_142 -> V_143 , false ) ;
return 0 ;
}
static int F_127 ( struct V_140 * V_43 , struct V_141 * V_142 ,
const char * V_145 , bool V_146 )
{
struct V_42 * V_42 = F_120 ( V_43 ) ;
struct V_147 V_148 ;
struct V_1 * V_7 ;
struct V_12 * V_13 ;
struct V_4 * V_5 ;
struct V_140 * V_149 ;
int V_121 ;
V_121 = F_128 ( V_42 , & V_6 , V_145 , & V_148 ) ;
if ( V_121 )
return V_121 ;
V_7 = F_3 ( V_148 . V_5 ) ;
V_13 = & V_7 -> V_15 ;
if ( ! V_148 . V_144 )
V_148 . V_144 = - 1 ;
if ( V_146 )
* ( T_1 * ) ( ( void * ) V_7 + V_142 -> V_143 ) = V_148 . V_144 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + V_142 -> V_143 ) = V_148 . V_144 ;
F_77 ( & V_7 -> V_15 ,
L_8 ,
V_7 -> V_51 [ V_46 ] , V_7 -> V_51 [ V_47 ] ,
V_7 -> V_52 [ V_46 ] , V_7 -> V_52 [ V_47 ] ) ;
F_129 (blkg, pos_css, ctx.blkg)
F_46 ( F_3 ( V_5 ) ) ;
F_82 ( V_7 , 0 ) ;
F_82 ( V_7 , 1 ) ;
if ( V_7 -> V_40 & V_74 ) {
F_104 ( V_7 ) ;
F_78 ( V_13 -> V_14 , true ) ;
}
F_130 ( & V_148 ) ;
return 0 ;
}
static int F_131 ( struct V_140 * V_43 , struct V_141 * V_142 ,
const char * V_145 )
{
return F_127 ( V_43 , V_142 , V_145 , true ) ;
}
static int F_132 ( struct V_140 * V_43 , struct V_141 * V_142 ,
const char * V_145 )
{
return F_127 ( V_43 , V_142 , V_145 , false ) ;
}
static void F_133 ( struct V_61 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_9 ;
F_134 ( & V_9 -> V_126 ) ;
}
bool F_135 ( struct V_61 * V_39 , struct V_31 * V_31 )
{
struct V_8 * V_9 = V_39 -> V_9 ;
struct V_27 * V_28 = NULL ;
struct V_1 * V_7 ;
struct V_12 * V_13 ;
bool V_41 = F_92 ( V_31 ) ;
struct V_42 * V_42 ;
bool V_150 = false ;
if ( V_31 -> V_105 & V_106 )
goto V_151;
F_136 () ;
V_42 = F_137 ( V_31 ) ;
V_7 = F_54 ( V_9 , V_42 ) ;
if ( V_7 ) {
if ( ! V_7 -> V_55 [ V_41 ] ) {
F_97 ( F_5 ( V_7 ) ,
V_31 -> V_99 , V_31 -> V_105 ) ;
goto V_152;
}
}
F_15 ( V_39 -> V_122 ) ;
V_7 = F_56 ( V_9 , V_42 ) ;
if ( F_138 ( ! V_7 ) )
goto V_124;
V_13 = & V_7 -> V_15 ;
while ( true ) {
if ( V_13 -> V_103 [ V_41 ] )
break;
if ( ! F_95 ( V_7 , V_31 , NULL ) )
break;
F_102 ( V_7 , V_31 ) ;
F_88 ( V_7 , V_41 ) ;
V_28 = & V_7 -> V_49 [ V_41 ] ;
V_13 = V_13 -> V_14 ;
V_7 = F_8 ( V_13 ) ;
if ( ! V_7 )
goto V_124;
}
F_77 ( V_13 , L_9 ,
V_41 == V_46 ? 'R' : 'W' ,
V_7 -> V_79 [ V_41 ] , V_31 -> V_99 , V_7 -> V_51 [ V_41 ] ,
V_7 -> V_80 [ V_41 ] , V_7 -> V_52 [ V_41 ] ,
V_13 -> V_103 [ V_46 ] , V_13 -> V_103 [ V_47 ] ) ;
F_139 ( V_31 ) ;
V_7 -> V_9 -> V_103 [ V_41 ] ++ ;
F_103 ( V_31 , V_28 , V_7 ) ;
V_150 = true ;
if ( V_7 -> V_40 & V_107 ) {
F_104 ( V_7 ) ;
F_78 ( V_7 -> V_15 . V_14 , true ) ;
}
V_124:
F_20 ( V_39 -> V_122 ) ;
V_152:
F_140 () ;
V_151:
if ( ! V_150 )
V_31 -> V_105 &= ~ V_106 ;
return V_150 ;
}
static void F_141 ( struct V_12 * V_14 )
{
struct V_1 * V_7 ;
while ( ( V_7 = F_60 ( V_14 ) ) ) {
struct V_12 * V_13 = & V_7 -> V_15 ;
struct V_31 * V_31 ;
F_74 ( V_7 ) ;
while ( ( V_31 = F_28 ( & V_13 -> V_33 [ V_46 ] ) ) )
F_107 ( V_7 , F_92 ( V_31 ) ) ;
while ( ( V_31 = F_28 ( & V_13 -> V_33 [ V_47 ] ) ) )
F_107 ( V_7 , F_92 ( V_31 ) ) ;
}
}
void F_142 ( struct V_61 * V_39 )
__releases( V_39 -> V_122 ) __acquires( V_39 -> V_122 )
{
struct V_8 * V_9 = V_39 -> V_9 ;
struct V_4 * V_5 ;
struct V_140 * V_149 ;
struct V_31 * V_31 ;
int V_41 ;
F_143 ( V_39 ) ;
F_136 () ;
F_144 (blkg, pos_css, td->queue->root_blkg)
F_141 ( & F_3 ( V_5 ) -> V_15 ) ;
F_141 ( & V_9 -> V_15 ) ;
F_140 () ;
F_20 ( V_39 -> V_122 ) ;
for ( V_41 = V_46 ; V_41 <= V_47 ; V_41 ++ )
while ( ( V_31 = F_31 ( & V_9 -> V_15 . V_33 [ V_41 ] ,
NULL ) ) )
F_114 ( V_31 ) ;
F_15 ( V_39 -> V_122 ) ;
}
int F_145 ( struct V_61 * V_39 )
{
struct V_8 * V_9 ;
int V_121 ;
V_9 = F_146 ( sizeof( * V_9 ) , V_153 , V_39 -> V_29 ) ;
if ( ! V_9 )
return - V_154 ;
F_147 ( & V_9 -> V_126 , F_112 ) ;
F_36 ( & V_9 -> V_15 , NULL ) ;
V_39 -> V_9 = V_9 ;
V_9 -> V_10 = V_39 ;
V_121 = F_148 ( V_39 , & V_6 ) ;
if ( V_121 )
F_149 ( V_9 ) ;
return V_121 ;
}
void F_150 ( struct V_61 * V_39 )
{
F_89 ( ! V_39 -> V_9 ) ;
F_133 ( V_39 ) ;
F_151 ( V_39 , & V_6 ) ;
F_149 ( V_39 -> V_9 ) ;
}
static int T_2 F_152 ( void )
{
V_125 = F_153 ( L_10 , V_155 , 0 ) ;
if ( ! V_125 )
F_154 ( L_11 ) ;
return F_155 ( & V_6 ) ;
}
