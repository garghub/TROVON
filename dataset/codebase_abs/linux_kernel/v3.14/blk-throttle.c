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
F_11 ( & V_17 -> V_18 ) ;
F_11 ( & V_17 -> V_19 ) ;
}
static void F_12 ( struct V_20 * V_21 )
{
static struct V_16 * V_22 ;
struct V_23 * V_24 = F_13 ( V_21 ) ;
bool V_25 = false ;
V_26:
if ( ! V_22 ) {
int V_27 ;
V_22 = F_14 ( struct V_16 ) ;
if ( ! V_22 ) {
F_15 ( V_24 , F_16 ( 10 ) ) ;
return;
}
F_17 (cpu)
F_10 ( F_18 ( V_22 , V_27 ) ) ;
}
F_19 ( & V_28 ) ;
if ( ! F_20 ( & V_29 ) ) {
struct V_1 * V_7 = F_21 ( & V_29 ,
struct V_1 ,
V_30 ) ;
F_22 ( V_7 -> V_22 , V_22 ) ;
F_23 ( & V_7 -> V_30 ) ;
}
V_25 = F_20 ( & V_29 ) ;
F_24 ( & V_28 ) ;
if ( ! V_25 )
goto V_26;
}
static void F_25 ( struct V_31 * V_32 , struct V_1 * V_7 )
{
F_26 ( & V_32 -> V_33 ) ;
F_27 ( & V_32 -> V_34 ) ;
V_32 -> V_7 = V_7 ;
}
static void F_28 ( struct V_35 * V_35 , struct V_31 * V_32 ,
struct V_36 * V_37 )
{
F_29 ( & V_32 -> V_34 , V_35 ) ;
if ( F_20 ( & V_32 -> V_33 ) ) {
F_30 ( & V_32 -> V_33 , V_37 ) ;
F_31 ( F_5 ( V_32 -> V_7 ) ) ;
}
}
static struct V_35 * F_32 ( struct V_36 * V_37 )
{
struct V_31 * V_32 = F_21 ( V_37 , struct V_31 , V_33 ) ;
struct V_35 * V_35 ;
if ( F_20 ( V_37 ) )
return NULL ;
V_35 = F_33 ( & V_32 -> V_34 ) ;
F_34 ( ! V_35 ) ;
return V_35 ;
}
static struct V_35 * F_35 ( struct V_36 * V_37 ,
struct V_1 * * V_38 )
{
struct V_31 * V_32 = F_21 ( V_37 , struct V_31 , V_33 ) ;
struct V_35 * V_35 ;
if ( F_20 ( V_37 ) )
return NULL ;
V_35 = F_36 ( & V_32 -> V_34 ) ;
F_34 ( ! V_35 ) ;
if ( F_37 ( & V_32 -> V_34 ) ) {
F_23 ( & V_32 -> V_33 ) ;
if ( V_38 )
* V_38 = V_32 -> V_7 ;
else
F_38 ( F_5 ( V_32 -> V_7 ) ) ;
} else {
F_39 ( & V_32 -> V_33 , V_37 ) ;
}
return V_35 ;
}
static void F_40 ( struct V_12 * V_13 ,
struct V_12 * V_14 )
{
F_26 ( & V_13 -> V_37 [ 0 ] ) ;
F_26 ( & V_13 -> V_37 [ 1 ] ) ;
V_13 -> V_39 = V_40 ;
V_13 -> V_14 = V_14 ;
F_41 ( & V_13 -> V_41 , V_42 ,
( unsigned long ) V_13 ) ;
}
static void F_42 ( struct V_12 * V_13 )
{
F_43 ( & V_13 -> V_41 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = V_5 -> V_43 -> V_9 ;
struct V_12 * V_14 ;
unsigned long V_44 ;
int V_45 ;
V_14 = & V_9 -> V_15 ;
if ( F_45 ( V_5 -> V_46 -> V_47 . V_48 ) && V_5 -> V_49 )
V_14 = & F_3 ( V_5 -> V_49 ) -> V_15 ;
F_40 ( & V_7 -> V_15 , V_14 ) ;
for ( V_45 = V_50 ; V_45 <= V_51 ; V_45 ++ ) {
F_25 ( & V_7 -> V_52 [ V_45 ] , V_7 ) ;
F_25 ( & V_7 -> V_53 [ V_45 ] , V_7 ) ;
}
F_46 ( & V_7 -> V_54 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_55 [ V_50 ] = - 1 ;
V_7 -> V_55 [ V_51 ] = - 1 ;
V_7 -> V_56 [ V_50 ] = - 1 ;
V_7 -> V_56 [ V_51 ] = - 1 ;
F_47 ( & V_28 , V_44 ) ;
F_48 ( & V_7 -> V_30 , & V_29 ) ;
F_15 ( & V_57 , 0 ) ;
F_49 ( & V_28 , V_44 ) ;
}
static void F_50 ( struct V_1 * V_7 )
{
struct V_1 * V_58 = F_8 ( V_7 -> V_15 . V_14 ) ;
int V_45 ;
for ( V_45 = V_50 ; V_45 <= V_51 ; V_45 ++ )
V_7 -> V_59 [ V_45 ] = ( V_58 && V_58 -> V_59 [ V_45 ] ) ||
( V_7 -> V_55 [ V_45 ] != - 1 || V_7 -> V_56 [ V_45 ] != - 1 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
F_50 ( F_3 ( V_5 ) ) ;
}
static void F_52 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
unsigned long V_44 ;
F_47 ( & V_28 , V_44 ) ;
F_23 ( & V_7 -> V_30 ) ;
F_49 ( & V_28 , V_44 ) ;
F_53 ( V_7 -> V_22 ) ;
F_42 ( & V_7 -> V_15 ) ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
int V_27 ;
if ( V_7 -> V_22 == NULL )
return;
F_17 (cpu) {
struct V_16 * V_60 = F_18 ( V_7 -> V_22 , V_27 ) ;
F_55 ( & V_60 -> V_18 ) ;
F_55 ( & V_60 -> V_19 ) ;
}
}
static struct V_1 * F_56 ( struct V_8 * V_9 ,
struct V_46 * V_46 )
{
if ( V_46 == & V_61 )
return F_7 ( V_9 ) ;
return F_3 ( F_57 ( V_46 , V_9 -> V_10 ) ) ;
}
static struct V_1 * F_58 ( struct V_8 * V_9 ,
struct V_46 * V_46 )
{
struct V_62 * V_43 = V_9 -> V_10 ;
struct V_1 * V_7 = NULL ;
if ( V_46 == & V_61 ) {
V_7 = F_7 ( V_9 ) ;
} else {
struct V_4 * V_5 ;
V_5 = F_59 ( V_46 , V_43 ) ;
if ( ! F_60 ( V_5 ) )
V_7 = F_3 ( V_5 ) ;
else if ( ! F_61 ( V_43 ) )
V_7 = F_7 ( V_9 ) ;
}
return V_7 ;
}
static struct V_1 *
F_62 ( struct V_12 * V_14 )
{
if ( ! V_14 -> V_63 )
return NULL ;
if ( ! V_14 -> V_64 )
V_14 -> V_64 = F_63 ( & V_14 -> V_39 ) ;
if ( V_14 -> V_64 )
return F_64 ( V_14 -> V_64 ) ;
return NULL ;
}
static void F_65 ( struct V_54 * V_65 , struct V_66 * V_67 )
{
F_66 ( V_65 , V_67 ) ;
F_46 ( V_65 ) ;
}
static void F_67 ( struct V_54 * V_65 ,
struct V_12 * V_14 )
{
if ( V_14 -> V_64 == V_65 )
V_14 -> V_64 = NULL ;
F_65 ( V_65 , & V_14 -> V_39 ) ;
-- V_14 -> V_63 ;
}
static void F_68 ( struct V_12 * V_14 )
{
struct V_1 * V_7 ;
V_7 = F_62 ( V_14 ) ;
if ( ! V_7 )
return;
V_14 -> V_68 = V_7 -> V_69 ;
}
static void F_69 ( struct V_1 * V_7 )
{
struct V_12 * V_14 = V_7 -> V_15 . V_14 ;
struct V_54 * * V_33 = & V_14 -> V_39 . V_54 ;
struct V_54 * V_49 = NULL ;
struct V_1 * V_70 ;
unsigned long V_71 = V_7 -> V_69 ;
int V_72 = 1 ;
while ( * V_33 != NULL ) {
V_49 = * V_33 ;
V_70 = F_64 ( V_49 ) ;
if ( F_70 ( V_71 , V_70 -> V_69 ) )
V_33 = & V_49 -> V_73 ;
else {
V_33 = & V_49 -> V_74 ;
V_72 = 0 ;
}
}
if ( V_72 )
V_14 -> V_64 = & V_7 -> V_54 ;
F_71 ( & V_7 -> V_54 , V_49 , V_33 ) ;
F_72 ( & V_7 -> V_54 , & V_14 -> V_39 ) ;
}
static void F_73 ( struct V_1 * V_7 )
{
F_69 ( V_7 ) ;
V_7 -> V_44 |= V_75 ;
V_7 -> V_15 . V_14 -> V_63 ++ ;
}
static void F_74 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_44 & V_75 ) )
F_73 ( V_7 ) ;
}
static void F_75 ( struct V_1 * V_7 )
{
F_67 ( & V_7 -> V_54 , V_7 -> V_15 . V_14 ) ;
V_7 -> V_44 &= ~ V_75 ;
}
static void F_76 ( struct V_1 * V_7 )
{
if ( V_7 -> V_44 & V_75 )
F_75 ( V_7 ) ;
}
static void F_77 ( struct V_12 * V_13 ,
unsigned long V_76 )
{
F_78 ( & V_13 -> V_41 , V_76 ) ;
F_79 ( V_13 , L_1 ,
V_76 - V_77 , V_77 ) ;
}
static bool F_80 ( struct V_12 * V_13 ,
bool V_78 )
{
if ( ! V_13 -> V_63 )
return true ;
F_68 ( V_13 ) ;
if ( V_78 || F_81 ( V_13 -> V_68 , V_77 ) ) {
F_77 ( V_13 , V_13 -> V_68 ) ;
return true ;
}
return false ;
}
static inline void F_82 ( struct V_1 * V_7 ,
bool V_45 , unsigned long V_79 )
{
V_7 -> V_80 [ V_45 ] = 0 ;
V_7 -> V_81 [ V_45 ] = 0 ;
if ( F_83 ( V_79 , V_7 -> V_82 [ V_45 ] ) )
V_7 -> V_82 [ V_45 ] = V_79 ;
V_7 -> V_83 [ V_45 ] = V_77 + V_84 ;
F_79 ( & V_7 -> V_15 ,
L_2 ,
V_45 == V_50 ? 'R' : 'W' , V_7 -> V_82 [ V_45 ] ,
V_7 -> V_83 [ V_45 ] , V_77 ) ;
}
static inline void F_84 ( struct V_1 * V_7 , bool V_45 )
{
V_7 -> V_80 [ V_45 ] = 0 ;
V_7 -> V_81 [ V_45 ] = 0 ;
V_7 -> V_82 [ V_45 ] = V_77 ;
V_7 -> V_83 [ V_45 ] = V_77 + V_84 ;
F_79 ( & V_7 -> V_15 ,
L_3 ,
V_45 == V_50 ? 'R' : 'W' , V_7 -> V_82 [ V_45 ] ,
V_7 -> V_83 [ V_45 ] , V_77 ) ;
}
static inline void F_85 ( struct V_1 * V_7 , bool V_45 ,
unsigned long V_85 )
{
V_7 -> V_83 [ V_45 ] = F_86 ( V_85 , V_84 ) ;
}
static inline void F_87 ( struct V_1 * V_7 , bool V_45 ,
unsigned long V_85 )
{
V_7 -> V_83 [ V_45 ] = F_86 ( V_85 , V_84 ) ;
F_79 ( & V_7 -> V_15 ,
L_4 ,
V_45 == V_50 ? 'R' : 'W' , V_7 -> V_82 [ V_45 ] ,
V_7 -> V_83 [ V_45 ] , V_77 ) ;
}
static bool F_88 ( struct V_1 * V_7 , bool V_45 )
{
if ( F_89 ( V_77 , V_7 -> V_82 [ V_45 ] , V_7 -> V_83 [ V_45 ] ) )
return 0 ;
return 1 ;
}
static inline void F_90 ( struct V_1 * V_7 , bool V_45 )
{
unsigned long V_86 , V_87 , V_88 ;
T_1 V_89 , V_90 ;
F_91 ( F_70 ( V_7 -> V_83 [ V_45 ] , V_7 -> V_82 [ V_45 ] ) ) ;
if ( F_88 ( V_7 , V_45 ) )
return;
F_85 ( V_7 , V_45 , V_77 + V_84 ) ;
V_87 = V_77 - V_7 -> V_82 [ V_45 ] ;
V_86 = V_87 / V_84 ;
if ( ! V_86 )
return;
V_90 = V_7 -> V_55 [ V_45 ] * V_84 * V_86 ;
F_92 ( V_90 , V_91 ) ;
V_89 = V_90 ;
V_88 = ( V_7 -> V_56 [ V_45 ] * V_84 * V_86 ) / V_91 ;
if ( ! V_89 && ! V_88 )
return;
if ( V_7 -> V_80 [ V_45 ] >= V_89 )
V_7 -> V_80 [ V_45 ] -= V_89 ;
else
V_7 -> V_80 [ V_45 ] = 0 ;
if ( V_7 -> V_81 [ V_45 ] >= V_88 )
V_7 -> V_81 [ V_45 ] -= V_88 ;
else
V_7 -> V_81 [ V_45 ] = 0 ;
V_7 -> V_82 [ V_45 ] += V_86 * V_84 ;
F_79 ( & V_7 -> V_15 ,
L_5 ,
V_45 == V_50 ? 'R' : 'W' , V_86 , V_89 , V_88 ,
V_7 -> V_82 [ V_45 ] , V_7 -> V_83 [ V_45 ] , V_77 ) ;
}
static bool F_93 ( struct V_1 * V_7 , struct V_35 * V_35 ,
unsigned long * V_92 )
{
bool V_45 = F_94 ( V_35 ) ;
unsigned int V_93 ;
unsigned long V_94 , V_95 , V_96 ;
T_1 V_90 ;
V_94 = V_96 = V_77 - V_7 -> V_82 [ V_45 ] ;
if ( ! V_94 )
V_96 = V_84 ;
V_96 = F_86 ( V_96 , V_84 ) ;
V_90 = ( T_1 ) V_7 -> V_56 [ V_45 ] * V_96 ;
F_92 ( V_90 , V_91 ) ;
if ( V_90 > V_97 )
V_93 = V_97 ;
else
V_93 = V_90 ;
if ( V_7 -> V_81 [ V_45 ] + 1 <= V_93 ) {
if ( V_92 )
* V_92 = 0 ;
return 1 ;
}
V_95 = ( ( V_7 -> V_81 [ V_45 ] + 1 ) * V_91 ) / V_7 -> V_56 [ V_45 ] + 1 ;
if ( V_95 > V_94 )
V_95 = V_95 - V_94 ;
else
V_95 = 1 ;
if ( V_92 )
* V_92 = V_95 ;
return 0 ;
}
static bool F_95 ( struct V_1 * V_7 , struct V_35 * V_35 ,
unsigned long * V_92 )
{
bool V_45 = F_94 ( V_35 ) ;
T_1 V_98 , V_99 , V_90 ;
unsigned long V_94 , V_95 , V_96 ;
V_94 = V_96 = V_77 - V_7 -> V_82 [ V_45 ] ;
if ( ! V_94 )
V_96 = V_84 ;
V_96 = F_86 ( V_96 , V_84 ) ;
V_90 = V_7 -> V_55 [ V_45 ] * V_96 ;
F_92 ( V_90 , V_91 ) ;
V_98 = V_90 ;
if ( V_7 -> V_80 [ V_45 ] + V_35 -> V_100 . V_101 <= V_98 ) {
if ( V_92 )
* V_92 = 0 ;
return 1 ;
}
V_99 = V_7 -> V_80 [ V_45 ] + V_35 -> V_100 . V_101 - V_98 ;
V_95 = F_96 ( V_99 * V_91 , V_7 -> V_55 [ V_45 ] ) ;
if ( ! V_95 )
V_95 = 1 ;
V_95 = V_95 + ( V_96 - V_94 ) ;
if ( V_92 )
* V_92 = V_95 ;
return 0 ;
}
static bool F_97 ( struct V_1 * V_7 , struct V_35 * V_35 ,
unsigned long * V_92 )
{
bool V_45 = F_94 ( V_35 ) ;
unsigned long V_102 = 0 , V_103 = 0 , V_104 = 0 ;
F_91 ( V_7 -> V_15 . V_105 [ V_45 ] &&
V_35 != F_32 ( & V_7 -> V_15 . V_37 [ V_45 ] ) ) ;
if ( V_7 -> V_55 [ V_45 ] == - 1 && V_7 -> V_56 [ V_45 ] == - 1 ) {
if ( V_92 )
* V_92 = 0 ;
return 1 ;
}
if ( F_88 ( V_7 , V_45 ) )
F_84 ( V_7 , V_45 ) ;
else {
if ( F_70 ( V_7 -> V_83 [ V_45 ] , V_77 + V_84 ) )
F_87 ( V_7 , V_45 , V_77 + V_84 ) ;
}
if ( F_95 ( V_7 , V_35 , & V_102 ) &&
F_93 ( V_7 , V_35 , & V_103 ) ) {
if ( V_92 )
* V_92 = 0 ;
return 1 ;
}
V_104 = F_98 ( V_102 , V_103 ) ;
if ( V_92 )
* V_92 = V_104 ;
if ( F_70 ( V_7 -> V_83 [ V_45 ] , V_77 + V_104 ) )
F_87 ( V_7 , V_45 , V_77 + V_104 ) ;
return 0 ;
}
static void F_99 ( struct V_4 * V_5 , T_1 V_106 ,
int V_45 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct V_16 * V_22 ;
unsigned long V_44 ;
if ( V_7 -> V_22 == NULL )
return;
F_100 ( V_44 ) ;
V_22 = F_101 ( V_7 -> V_22 ) ;
F_102 ( & V_22 -> V_19 , V_45 , 1 ) ;
F_102 ( & V_22 -> V_18 , V_45 , V_106 ) ;
F_103 ( V_44 ) ;
}
static void F_104 ( struct V_1 * V_7 , struct V_35 * V_35 )
{
bool V_45 = F_94 ( V_35 ) ;
V_7 -> V_80 [ V_45 ] += V_35 -> V_100 . V_101 ;
V_7 -> V_81 [ V_45 ] ++ ;
if ( ! ( V_35 -> V_107 & V_108 ) ) {
V_35 -> V_107 |= V_108 ;
F_99 ( F_5 ( V_7 ) ,
V_35 -> V_100 . V_101 , V_35 -> V_107 ) ;
}
}
static void F_105 ( struct V_35 * V_35 , struct V_31 * V_32 ,
struct V_1 * V_7 )
{
struct V_12 * V_13 = & V_7 -> V_15 ;
bool V_45 = F_94 ( V_35 ) ;
if ( ! V_32 )
V_32 = & V_7 -> V_52 [ V_45 ] ;
if ( ! V_13 -> V_105 [ V_45 ] )
V_7 -> V_44 |= V_109 ;
F_28 ( V_35 , V_32 , & V_13 -> V_37 [ V_45 ] ) ;
V_13 -> V_105 [ V_45 ] ++ ;
F_74 ( V_7 ) ;
}
static void F_106 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = & V_7 -> V_15 ;
unsigned long V_110 = - 1 , V_111 = - 1 , V_112 = - 1 , V_69 ;
struct V_35 * V_35 ;
if ( ( V_35 = F_32 ( & V_13 -> V_37 [ V_50 ] ) ) )
F_97 ( V_7 , V_35 , & V_110 ) ;
if ( ( V_35 = F_32 ( & V_13 -> V_37 [ V_51 ] ) ) )
F_97 ( V_7 , V_35 , & V_111 ) ;
V_112 = F_107 ( V_110 , V_111 ) ;
V_69 = V_77 + V_112 ;
F_76 ( V_7 ) ;
V_7 -> V_69 = V_69 ;
F_74 ( V_7 ) ;
V_7 -> V_44 &= ~ V_109 ;
}
static void F_108 ( struct V_1 * V_113 ,
struct V_1 * V_58 , bool V_45 )
{
if ( F_88 ( V_58 , V_45 ) ) {
F_82 ( V_58 , V_45 ,
V_113 -> V_82 [ V_45 ] ) ;
}
}
static void F_109 ( struct V_1 * V_7 , bool V_45 )
{
struct V_12 * V_13 = & V_7 -> V_15 ;
struct V_12 * V_14 = V_13 -> V_14 ;
struct V_1 * V_58 = F_8 ( V_14 ) ;
struct V_1 * V_38 = NULL ;
struct V_35 * V_35 ;
V_35 = F_35 ( & V_13 -> V_37 [ V_45 ] , & V_38 ) ;
V_13 -> V_105 [ V_45 ] -- ;
F_104 ( V_7 , V_35 ) ;
if ( V_58 ) {
F_105 ( V_35 , & V_7 -> V_53 [ V_45 ] , V_58 ) ;
F_108 ( V_7 , V_58 , V_45 ) ;
} else {
F_28 ( V_35 , & V_7 -> V_53 [ V_45 ] ,
& V_14 -> V_37 [ V_45 ] ) ;
F_91 ( V_7 -> V_9 -> V_105 [ V_45 ] <= 0 ) ;
V_7 -> V_9 -> V_105 [ V_45 ] -- ;
}
F_90 ( V_7 , V_45 ) ;
if ( V_38 )
F_38 ( F_5 ( V_38 ) ) ;
}
static int F_110 ( struct V_1 * V_7 )
{
struct V_12 * V_13 = & V_7 -> V_15 ;
unsigned int V_114 = 0 , V_115 = 0 ;
unsigned int V_116 = V_117 * 3 / 4 ;
unsigned int V_118 = V_117 - V_116 ;
struct V_35 * V_35 ;
while ( ( V_35 = F_32 ( & V_13 -> V_37 [ V_50 ] ) ) &&
F_97 ( V_7 , V_35 , NULL ) ) {
F_109 ( V_7 , F_94 ( V_35 ) ) ;
V_114 ++ ;
if ( V_114 >= V_116 )
break;
}
while ( ( V_35 = F_32 ( & V_13 -> V_37 [ V_51 ] ) ) &&
F_97 ( V_7 , V_35 , NULL ) ) {
F_109 ( V_7 , F_94 ( V_35 ) ) ;
V_115 ++ ;
if ( V_115 >= V_118 )
break;
}
return V_114 + V_115 ;
}
static int F_111 ( struct V_12 * V_14 )
{
unsigned int V_119 = 0 ;
while ( 1 ) {
struct V_1 * V_7 = F_62 ( V_14 ) ;
struct V_12 * V_13 = & V_7 -> V_15 ;
if ( ! V_7 )
break;
if ( F_70 ( V_77 , V_7 -> V_69 ) )
break;
F_76 ( V_7 ) ;
V_119 += F_110 ( V_7 ) ;
if ( V_13 -> V_105 [ 0 ] || V_13 -> V_105 [ 1 ] )
F_106 ( V_7 ) ;
if ( V_119 >= V_120 )
break;
}
return V_119 ;
}
static void V_42 ( unsigned long V_121 )
{
struct V_12 * V_13 = ( void * ) V_121 ;
struct V_1 * V_7 = F_8 ( V_13 ) ;
struct V_8 * V_9 = F_9 ( V_13 ) ;
struct V_62 * V_43 = V_9 -> V_10 ;
struct V_12 * V_14 ;
bool V_122 ;
int V_123 ;
F_19 ( V_43 -> V_124 ) ;
V_125:
V_14 = V_13 -> V_14 ;
V_122 = false ;
while ( true ) {
F_79 ( V_13 , L_6 ,
V_13 -> V_105 [ V_50 ] + V_13 -> V_105 [ V_51 ] ,
V_13 -> V_105 [ V_50 ] , V_13 -> V_105 [ V_51 ] ) ;
V_123 = F_111 ( V_13 ) ;
if ( V_123 ) {
F_79 ( V_13 , L_7 , V_123 ) ;
V_122 = true ;
}
if ( F_80 ( V_13 , false ) )
break;
F_24 ( V_43 -> V_124 ) ;
F_112 () ;
F_19 ( V_43 -> V_124 ) ;
}
if ( ! V_122 )
goto V_126;
if ( V_14 ) {
if ( V_7 -> V_44 & V_109 ) {
F_106 ( V_7 ) ;
if ( ! F_80 ( V_14 , false ) ) {
V_13 = V_14 ;
V_7 = F_8 ( V_13 ) ;
goto V_125;
}
}
} else {
F_113 ( V_127 , & V_9 -> V_128 ) ;
}
V_126:
F_24 ( V_43 -> V_124 ) ;
}
void F_114 ( struct V_20 * V_21 )
{
struct V_8 * V_9 = F_2 ( V_21 , struct V_8 ,
V_128 ) ;
struct V_12 * V_129 = & V_9 -> V_15 ;
struct V_62 * V_43 = V_9 -> V_10 ;
struct V_130 V_131 ;
struct V_35 * V_35 ;
struct V_132 V_133 ;
int V_45 ;
F_27 ( & V_131 ) ;
F_19 ( V_43 -> V_124 ) ;
for ( V_45 = V_50 ; V_45 <= V_51 ; V_45 ++ )
while ( ( V_35 = F_35 ( & V_129 -> V_37 [ V_45 ] , NULL ) ) )
F_29 ( & V_131 , V_35 ) ;
F_24 ( V_43 -> V_124 ) ;
if ( ! F_37 ( & V_131 ) ) {
F_115 ( & V_133 ) ;
while( ( V_35 = F_36 ( & V_131 ) ) )
F_116 ( V_35 ) ;
F_117 ( & V_133 ) ;
}
}
static T_1 F_118 ( struct V_134 * V_135 ,
struct V_2 * V_3 , int V_136 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_137 V_138 = { } , V_90 ;
int V_139 , V_27 ;
F_17 (cpu) {
struct V_16 * V_60 = F_18 ( V_7 -> V_22 , V_27 ) ;
V_90 = F_119 ( ( void * ) V_60 + V_136 ) ;
for ( V_139 = 0 ; V_139 < V_140 ; V_139 ++ )
V_138 . V_141 [ V_139 ] += V_90 . V_141 [ V_139 ] ;
}
return F_120 ( V_135 , V_3 , & V_138 ) ;
}
static int F_121 ( struct V_134 * V_135 , void * V_142 )
{
F_122 ( V_135 , F_123 ( F_124 ( V_135 ) ) , F_118 ,
& V_6 , F_125 ( V_135 ) -> V_143 , true ) ;
return 0 ;
}
static T_1 F_126 ( struct V_134 * V_135 , struct V_2 * V_3 ,
int V_136 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_142 = * ( T_1 * ) ( ( void * ) V_7 + V_136 ) ;
if ( V_142 == - 1 )
return 0 ;
return F_127 ( V_135 , V_3 , V_142 ) ;
}
static T_1 F_128 ( struct V_134 * V_135 , struct V_2 * V_3 ,
int V_136 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_142 = * ( unsigned int * ) ( ( void * ) V_7 + V_136 ) ;
if ( V_142 == - 1 )
return 0 ;
return F_127 ( V_135 , V_3 , V_142 ) ;
}
static int F_129 ( struct V_134 * V_135 , void * V_142 )
{
F_122 ( V_135 , F_123 ( F_124 ( V_135 ) ) , F_126 ,
& V_6 , F_125 ( V_135 ) -> V_143 , false ) ;
return 0 ;
}
static int F_130 ( struct V_134 * V_135 , void * V_142 )
{
F_122 ( V_135 , F_123 ( F_124 ( V_135 ) ) , F_128 ,
& V_6 , F_125 ( V_135 ) -> V_143 , false ) ;
return 0 ;
}
static int F_131 ( struct V_144 * V_47 , struct V_145 * V_146 ,
const char * V_147 , bool V_148 )
{
struct V_46 * V_46 = F_123 ( V_47 ) ;
struct V_149 V_150 ;
struct V_1 * V_7 ;
struct V_12 * V_13 ;
struct V_4 * V_5 ;
struct V_144 * V_151 ;
int V_123 ;
V_123 = F_132 ( V_46 , & V_6 , V_147 , & V_150 ) ;
if ( V_123 )
return V_123 ;
V_7 = F_3 ( V_150 . V_5 ) ;
V_13 = & V_7 -> V_15 ;
if ( ! V_150 . V_142 )
V_150 . V_142 = - 1 ;
if ( V_148 )
* ( T_1 * ) ( ( void * ) V_7 + V_146 -> V_143 ) = V_150 . V_142 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + V_146 -> V_143 ) = V_150 . V_142 ;
F_79 ( & V_7 -> V_15 ,
L_8 ,
V_7 -> V_55 [ V_50 ] , V_7 -> V_55 [ V_51 ] ,
V_7 -> V_56 [ V_50 ] , V_7 -> V_56 [ V_51 ] ) ;
F_133 (blkg, pos_css, ctx.blkg)
F_50 ( F_3 ( V_5 ) ) ;
F_84 ( V_7 , 0 ) ;
F_84 ( V_7 , 1 ) ;
if ( V_7 -> V_44 & V_75 ) {
F_106 ( V_7 ) ;
F_80 ( V_13 -> V_14 , true ) ;
}
F_134 ( & V_150 ) ;
return 0 ;
}
static int F_135 ( struct V_144 * V_47 , struct V_145 * V_146 ,
const char * V_147 )
{
return F_131 ( V_47 , V_146 , V_147 , true ) ;
}
static int F_136 ( struct V_144 * V_47 , struct V_145 * V_146 ,
const char * V_147 )
{
return F_131 ( V_47 , V_146 , V_147 , false ) ;
}
static void F_137 ( struct V_62 * V_43 )
{
struct V_8 * V_9 = V_43 -> V_9 ;
F_138 ( & V_9 -> V_128 ) ;
}
bool F_139 ( struct V_62 * V_43 , struct V_35 * V_35 )
{
struct V_8 * V_9 = V_43 -> V_9 ;
struct V_31 * V_32 = NULL ;
struct V_1 * V_7 ;
struct V_12 * V_13 ;
bool V_45 = F_94 ( V_35 ) ;
struct V_46 * V_46 ;
bool V_152 = false ;
if ( V_35 -> V_107 & V_108 )
goto V_153;
F_140 () ;
V_46 = F_141 ( V_35 ) ;
V_7 = F_56 ( V_9 , V_46 ) ;
if ( V_7 ) {
if ( ! V_7 -> V_59 [ V_45 ] ) {
F_99 ( F_5 ( V_7 ) ,
V_35 -> V_100 . V_101 , V_35 -> V_107 ) ;
goto V_154;
}
}
F_19 ( V_43 -> V_124 ) ;
V_7 = F_58 ( V_9 , V_46 ) ;
if ( F_142 ( ! V_7 ) )
goto V_126;
V_13 = & V_7 -> V_15 ;
while ( true ) {
if ( V_13 -> V_105 [ V_45 ] )
break;
if ( ! F_97 ( V_7 , V_35 , NULL ) )
break;
F_104 ( V_7 , V_35 ) ;
F_90 ( V_7 , V_45 ) ;
V_32 = & V_7 -> V_53 [ V_45 ] ;
V_13 = V_13 -> V_14 ;
V_7 = F_8 ( V_13 ) ;
if ( ! V_7 )
goto V_126;
}
F_79 ( V_13 , L_9 ,
V_45 == V_50 ? 'R' : 'W' ,
V_7 -> V_80 [ V_45 ] , V_35 -> V_100 . V_101 , V_7 -> V_55 [ V_45 ] ,
V_7 -> V_81 [ V_45 ] , V_7 -> V_56 [ V_45 ] ,
V_13 -> V_105 [ V_50 ] , V_13 -> V_105 [ V_51 ] ) ;
F_143 ( V_35 ) ;
V_7 -> V_9 -> V_105 [ V_45 ] ++ ;
F_105 ( V_35 , V_32 , V_7 ) ;
V_152 = true ;
if ( V_7 -> V_44 & V_109 ) {
F_106 ( V_7 ) ;
F_80 ( V_7 -> V_15 . V_14 , true ) ;
}
V_126:
F_24 ( V_43 -> V_124 ) ;
V_154:
F_144 () ;
V_153:
if ( ! V_152 )
V_35 -> V_107 &= ~ V_108 ;
return V_152 ;
}
static void F_145 ( struct V_12 * V_14 )
{
struct V_1 * V_7 ;
while ( ( V_7 = F_62 ( V_14 ) ) ) {
struct V_12 * V_13 = & V_7 -> V_15 ;
struct V_35 * V_35 ;
F_76 ( V_7 ) ;
while ( ( V_35 = F_32 ( & V_13 -> V_37 [ V_50 ] ) ) )
F_109 ( V_7 , F_94 ( V_35 ) ) ;
while ( ( V_35 = F_32 ( & V_13 -> V_37 [ V_51 ] ) ) )
F_109 ( V_7 , F_94 ( V_35 ) ) ;
}
}
void F_146 ( struct V_62 * V_43 )
__releases( V_43 -> V_124 ) __acquires( V_43 -> V_124 )
{
struct V_8 * V_9 = V_43 -> V_9 ;
struct V_4 * V_5 ;
struct V_144 * V_151 ;
struct V_35 * V_35 ;
int V_45 ;
F_147 ( V_43 ) ;
F_140 () ;
F_148 (blkg, pos_css, td->queue->root_blkg)
F_145 ( & F_3 ( V_5 ) -> V_15 ) ;
F_145 ( & V_9 -> V_15 ) ;
F_144 () ;
F_24 ( V_43 -> V_124 ) ;
for ( V_45 = V_50 ; V_45 <= V_51 ; V_45 ++ )
while ( ( V_35 = F_35 ( & V_9 -> V_15 . V_37 [ V_45 ] ,
NULL ) ) )
F_116 ( V_35 ) ;
F_19 ( V_43 -> V_124 ) ;
}
int F_149 ( struct V_62 * V_43 )
{
struct V_8 * V_9 ;
int V_123 ;
V_9 = F_150 ( sizeof( * V_9 ) , V_155 , V_43 -> V_33 ) ;
if ( ! V_9 )
return - V_156 ;
F_151 ( & V_9 -> V_128 , F_114 ) ;
F_40 ( & V_9 -> V_15 , NULL ) ;
V_43 -> V_9 = V_9 ;
V_9 -> V_10 = V_43 ;
V_123 = F_152 ( V_43 , & V_6 ) ;
if ( V_123 )
F_153 ( V_9 ) ;
return V_123 ;
}
void F_154 ( struct V_62 * V_43 )
{
F_91 ( ! V_43 -> V_9 ) ;
F_137 ( V_43 ) ;
F_155 ( V_43 , & V_6 ) ;
F_153 ( V_43 -> V_9 ) ;
}
static int T_2 F_156 ( void )
{
V_127 = F_157 ( L_10 , V_157 , 0 ) ;
if ( ! V_127 )
F_158 ( L_11 ) ;
return F_159 ( & V_6 ) ;
}
