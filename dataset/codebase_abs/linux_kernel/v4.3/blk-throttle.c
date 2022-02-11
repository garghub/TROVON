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
static struct V_1 * F_7 ( struct V_8 * V_9 )
{
if ( V_9 && V_9 -> V_10 )
return F_2 ( V_9 , struct V_1 , V_11 ) ;
else
return NULL ;
}
static struct V_12 * F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_7 = F_7 ( V_9 ) ;
if ( V_7 )
return V_7 -> V_13 ;
else
return F_2 ( V_9 , struct V_12 , V_11 ) ;
}
static void F_9 ( struct V_14 * V_15 , struct V_1 * V_7 )
{
F_10 ( & V_15 -> V_16 ) ;
F_11 ( & V_15 -> V_17 ) ;
V_15 -> V_7 = V_7 ;
}
static void F_12 ( struct V_18 * V_18 , struct V_14 * V_15 ,
struct V_19 * V_20 )
{
F_13 ( & V_15 -> V_17 , V_18 ) ;
if ( F_14 ( & V_15 -> V_16 ) ) {
F_15 ( & V_15 -> V_16 , V_20 ) ;
F_16 ( F_5 ( V_15 -> V_7 ) ) ;
}
}
static struct V_18 * F_17 ( struct V_19 * V_20 )
{
struct V_14 * V_15 = F_18 ( V_20 , struct V_14 , V_16 ) ;
struct V_18 * V_18 ;
if ( F_14 ( V_20 ) )
return NULL ;
V_18 = F_19 ( & V_15 -> V_17 ) ;
F_20 ( ! V_18 ) ;
return V_18 ;
}
static struct V_18 * F_21 ( struct V_19 * V_20 ,
struct V_1 * * V_21 )
{
struct V_14 * V_15 = F_18 ( V_20 , struct V_14 , V_16 ) ;
struct V_18 * V_18 ;
if ( F_14 ( V_20 ) )
return NULL ;
V_18 = F_22 ( & V_15 -> V_17 ) ;
F_20 ( ! V_18 ) ;
if ( F_23 ( & V_15 -> V_17 ) ) {
F_24 ( & V_15 -> V_16 ) ;
if ( V_21 )
* V_21 = V_15 -> V_7 ;
else
F_25 ( F_5 ( V_15 -> V_7 ) ) ;
} else {
F_26 ( & V_15 -> V_16 , V_20 ) ;
}
return V_18 ;
}
static void F_27 ( struct V_8 * V_9 )
{
F_10 ( & V_9 -> V_20 [ 0 ] ) ;
F_10 ( & V_9 -> V_20 [ 1 ] ) ;
V_9 -> V_22 = V_23 ;
F_28 ( & V_9 -> V_24 , V_25 ,
( unsigned long ) V_9 ) ;
}
static struct V_2 * F_29 ( T_1 V_26 , int V_16 )
{
struct V_1 * V_7 ;
int V_27 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_26 , V_16 ) ;
if ( ! V_7 )
return NULL ;
F_27 ( & V_7 -> V_11 ) ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ ) {
F_9 ( & V_7 -> V_30 [ V_27 ] , V_7 ) ;
F_9 ( & V_7 -> V_31 [ V_27 ] , V_7 ) ;
}
F_31 ( & V_7 -> V_32 ) ;
V_7 -> V_33 [ V_28 ] = - 1 ;
V_7 -> V_33 [ V_29 ] = - 1 ;
V_7 -> V_34 [ V_28 ] = - 1 ;
V_7 -> V_34 [ V_29 ] = - 1 ;
return & V_7 -> V_3 ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_5 ( V_7 ) ;
struct V_12 * V_13 = V_5 -> V_35 -> V_13 ;
struct V_8 * V_9 = & V_7 -> V_11 ;
V_9 -> V_10 = & V_13 -> V_11 ;
if ( F_33 ( V_5 -> V_36 -> V_37 . V_38 ) && V_5 -> V_39 )
V_9 -> V_10 = & F_3 ( V_5 -> V_39 ) -> V_11 ;
V_7 -> V_13 = V_13 ;
}
static void F_34 ( struct V_1 * V_7 )
{
struct V_1 * V_40 = F_7 ( V_7 -> V_11 . V_10 ) ;
int V_27 ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ )
V_7 -> V_41 [ V_27 ] = ( V_40 && V_40 -> V_41 [ V_27 ] ) ||
( V_7 -> V_33 [ V_27 ] != - 1 || V_7 -> V_34 [ V_27 ] != - 1 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
F_34 ( F_1 ( V_3 ) ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_37 ( & V_7 -> V_11 . V_24 ) ;
F_38 ( V_7 ) ;
}
static struct V_1 *
F_39 ( struct V_8 * V_10 )
{
if ( ! V_10 -> V_42 )
return NULL ;
if ( ! V_10 -> V_43 )
V_10 -> V_43 = F_40 ( & V_10 -> V_22 ) ;
if ( V_10 -> V_43 )
return F_41 ( V_10 -> V_43 ) ;
return NULL ;
}
static void F_42 ( struct V_32 * V_44 , struct V_45 * V_46 )
{
F_43 ( V_44 , V_46 ) ;
F_31 ( V_44 ) ;
}
static void F_44 ( struct V_32 * V_44 ,
struct V_8 * V_10 )
{
if ( V_10 -> V_43 == V_44 )
V_10 -> V_43 = NULL ;
F_42 ( V_44 , & V_10 -> V_22 ) ;
-- V_10 -> V_42 ;
}
static void F_45 ( struct V_8 * V_10 )
{
struct V_1 * V_7 ;
V_7 = F_39 ( V_10 ) ;
if ( ! V_7 )
return;
V_10 -> V_47 = V_7 -> V_48 ;
}
static void F_46 ( struct V_1 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_11 . V_10 ;
struct V_32 * * V_16 = & V_10 -> V_22 . V_32 ;
struct V_32 * V_39 = NULL ;
struct V_1 * V_49 ;
unsigned long V_50 = V_7 -> V_48 ;
int V_51 = 1 ;
while ( * V_16 != NULL ) {
V_39 = * V_16 ;
V_49 = F_41 ( V_39 ) ;
if ( F_47 ( V_50 , V_49 -> V_48 ) )
V_16 = & V_39 -> V_52 ;
else {
V_16 = & V_39 -> V_53 ;
V_51 = 0 ;
}
}
if ( V_51 )
V_10 -> V_43 = & V_7 -> V_32 ;
F_48 ( & V_7 -> V_32 , V_39 , V_16 ) ;
F_49 ( & V_7 -> V_32 , & V_10 -> V_22 ) ;
}
static void F_50 ( struct V_1 * V_7 )
{
F_46 ( V_7 ) ;
V_7 -> V_54 |= V_55 ;
V_7 -> V_11 . V_10 -> V_42 ++ ;
}
static void F_51 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_54 & V_55 ) )
F_50 ( V_7 ) ;
}
static void F_52 ( struct V_1 * V_7 )
{
F_44 ( & V_7 -> V_32 , V_7 -> V_11 . V_10 ) ;
V_7 -> V_54 &= ~ V_55 ;
}
static void F_53 ( struct V_1 * V_7 )
{
if ( V_7 -> V_54 & V_55 )
F_52 ( V_7 ) ;
}
static void F_54 ( struct V_8 * V_9 ,
unsigned long V_56 )
{
F_55 ( & V_9 -> V_24 , V_56 ) ;
F_56 ( V_9 , L_1 ,
V_56 - V_57 , V_57 ) ;
}
static bool F_57 ( struct V_8 * V_9 ,
bool V_58 )
{
if ( ! V_9 -> V_42 )
return true ;
F_45 ( V_9 ) ;
if ( V_58 || F_58 ( V_9 -> V_47 , V_57 ) ) {
F_54 ( V_9 , V_9 -> V_47 ) ;
return true ;
}
return false ;
}
static inline void F_59 ( struct V_1 * V_7 ,
bool V_27 , unsigned long V_59 )
{
V_7 -> V_60 [ V_27 ] = 0 ;
V_7 -> V_61 [ V_27 ] = 0 ;
if ( F_60 ( V_59 , V_7 -> V_62 [ V_27 ] ) )
V_7 -> V_62 [ V_27 ] = V_59 ;
V_7 -> V_63 [ V_27 ] = V_57 + V_64 ;
F_56 ( & V_7 -> V_11 ,
L_2 ,
V_27 == V_28 ? 'R' : 'W' , V_7 -> V_62 [ V_27 ] ,
V_7 -> V_63 [ V_27 ] , V_57 ) ;
}
static inline void F_61 ( struct V_1 * V_7 , bool V_27 )
{
V_7 -> V_60 [ V_27 ] = 0 ;
V_7 -> V_61 [ V_27 ] = 0 ;
V_7 -> V_62 [ V_27 ] = V_57 ;
V_7 -> V_63 [ V_27 ] = V_57 + V_64 ;
F_56 ( & V_7 -> V_11 ,
L_3 ,
V_27 == V_28 ? 'R' : 'W' , V_7 -> V_62 [ V_27 ] ,
V_7 -> V_63 [ V_27 ] , V_57 ) ;
}
static inline void F_62 ( struct V_1 * V_7 , bool V_27 ,
unsigned long V_65 )
{
V_7 -> V_63 [ V_27 ] = F_63 ( V_65 , V_64 ) ;
}
static inline void F_64 ( struct V_1 * V_7 , bool V_27 ,
unsigned long V_65 )
{
V_7 -> V_63 [ V_27 ] = F_63 ( V_65 , V_64 ) ;
F_56 ( & V_7 -> V_11 ,
L_4 ,
V_27 == V_28 ? 'R' : 'W' , V_7 -> V_62 [ V_27 ] ,
V_7 -> V_63 [ V_27 ] , V_57 ) ;
}
static bool F_65 ( struct V_1 * V_7 , bool V_27 )
{
if ( F_66 ( V_57 , V_7 -> V_62 [ V_27 ] , V_7 -> V_63 [ V_27 ] ) )
return false ;
return 1 ;
}
static inline void F_67 ( struct V_1 * V_7 , bool V_27 )
{
unsigned long V_66 , V_67 , V_68 ;
T_2 V_69 , V_70 ;
F_68 ( F_47 ( V_7 -> V_63 [ V_27 ] , V_7 -> V_62 [ V_27 ] ) ) ;
if ( F_65 ( V_7 , V_27 ) )
return;
F_62 ( V_7 , V_27 , V_57 + V_64 ) ;
V_67 = V_57 - V_7 -> V_62 [ V_27 ] ;
V_66 = V_67 / V_64 ;
if ( ! V_66 )
return;
V_70 = V_7 -> V_33 [ V_27 ] * V_64 * V_66 ;
F_69 ( V_70 , V_71 ) ;
V_69 = V_70 ;
V_68 = ( V_7 -> V_34 [ V_27 ] * V_64 * V_66 ) / V_71 ;
if ( ! V_69 && ! V_68 )
return;
if ( V_7 -> V_60 [ V_27 ] >= V_69 )
V_7 -> V_60 [ V_27 ] -= V_69 ;
else
V_7 -> V_60 [ V_27 ] = 0 ;
if ( V_7 -> V_61 [ V_27 ] >= V_68 )
V_7 -> V_61 [ V_27 ] -= V_68 ;
else
V_7 -> V_61 [ V_27 ] = 0 ;
V_7 -> V_62 [ V_27 ] += V_66 * V_64 ;
F_56 ( & V_7 -> V_11 ,
L_5 ,
V_27 == V_28 ? 'R' : 'W' , V_66 , V_69 , V_68 ,
V_7 -> V_62 [ V_27 ] , V_7 -> V_63 [ V_27 ] , V_57 ) ;
}
static bool F_70 ( struct V_1 * V_7 , struct V_18 * V_18 ,
unsigned long * V_72 )
{
bool V_27 = F_71 ( V_18 ) ;
unsigned int V_73 ;
unsigned long V_74 , V_75 , V_76 ;
T_2 V_70 ;
V_74 = V_76 = V_57 - V_7 -> V_62 [ V_27 ] ;
if ( ! V_74 )
V_76 = V_64 ;
V_76 = F_63 ( V_76 , V_64 ) ;
V_70 = ( T_2 ) V_7 -> V_34 [ V_27 ] * V_76 ;
F_69 ( V_70 , V_71 ) ;
if ( V_70 > V_77 )
V_73 = V_77 ;
else
V_73 = V_70 ;
if ( V_7 -> V_61 [ V_27 ] + 1 <= V_73 ) {
if ( V_72 )
* V_72 = 0 ;
return true ;
}
V_75 = ( ( V_7 -> V_61 [ V_27 ] + 1 ) * V_71 ) / V_7 -> V_34 [ V_27 ] + 1 ;
if ( V_75 > V_74 )
V_75 = V_75 - V_74 ;
else
V_75 = 1 ;
if ( V_72 )
* V_72 = V_75 ;
return 0 ;
}
static bool F_72 ( struct V_1 * V_7 , struct V_18 * V_18 ,
unsigned long * V_72 )
{
bool V_27 = F_71 ( V_18 ) ;
T_2 V_78 , V_79 , V_70 ;
unsigned long V_74 , V_75 , V_76 ;
V_74 = V_76 = V_57 - V_7 -> V_62 [ V_27 ] ;
if ( ! V_74 )
V_76 = V_64 ;
V_76 = F_63 ( V_76 , V_64 ) ;
V_70 = V_7 -> V_33 [ V_27 ] * V_76 ;
F_69 ( V_70 , V_71 ) ;
V_78 = V_70 ;
if ( V_7 -> V_60 [ V_27 ] + V_18 -> V_80 . V_81 <= V_78 ) {
if ( V_72 )
* V_72 = 0 ;
return true ;
}
V_79 = V_7 -> V_60 [ V_27 ] + V_18 -> V_80 . V_81 - V_78 ;
V_75 = F_73 ( V_79 * V_71 , V_7 -> V_33 [ V_27 ] ) ;
if ( ! V_75 )
V_75 = 1 ;
V_75 = V_75 + ( V_76 - V_74 ) ;
if ( V_72 )
* V_72 = V_75 ;
return 0 ;
}
static bool F_74 ( struct V_1 * V_7 , struct V_18 * V_18 ,
unsigned long * V_72 )
{
bool V_27 = F_71 ( V_18 ) ;
unsigned long V_82 = 0 , V_83 = 0 , V_84 = 0 ;
F_68 ( V_7 -> V_11 . V_85 [ V_27 ] &&
V_18 != F_17 ( & V_7 -> V_11 . V_20 [ V_27 ] ) ) ;
if ( V_7 -> V_33 [ V_27 ] == - 1 && V_7 -> V_34 [ V_27 ] == - 1 ) {
if ( V_72 )
* V_72 = 0 ;
return true ;
}
if ( F_65 ( V_7 , V_27 ) )
F_61 ( V_7 , V_27 ) ;
else {
if ( F_47 ( V_7 -> V_63 [ V_27 ] , V_57 + V_64 ) )
F_64 ( V_7 , V_27 , V_57 + V_64 ) ;
}
if ( F_72 ( V_7 , V_18 , & V_82 ) &&
F_70 ( V_7 , V_18 , & V_83 ) ) {
if ( V_72 )
* V_72 = 0 ;
return 1 ;
}
V_84 = F_75 ( V_82 , V_83 ) ;
if ( V_72 )
* V_72 = V_84 ;
if ( F_47 ( V_7 -> V_63 [ V_27 ] , V_57 + V_84 ) )
F_64 ( V_7 , V_27 , V_57 + V_84 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_7 , struct V_18 * V_18 )
{
bool V_27 = F_71 ( V_18 ) ;
V_7 -> V_60 [ V_27 ] += V_18 -> V_80 . V_81 ;
V_7 -> V_61 [ V_27 ] ++ ;
if ( ! ( V_18 -> V_86 & V_87 ) )
V_18 -> V_86 |= V_87 ;
}
static void F_77 ( struct V_18 * V_18 , struct V_14 * V_15 ,
struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
bool V_27 = F_71 ( V_18 ) ;
if ( ! V_15 )
V_15 = & V_7 -> V_30 [ V_27 ] ;
if ( ! V_9 -> V_85 [ V_27 ] )
V_7 -> V_54 |= V_88 ;
F_12 ( V_18 , V_15 , & V_9 -> V_20 [ V_27 ] ) ;
V_9 -> V_85 [ V_27 ] ++ ;
F_51 ( V_7 ) ;
}
static void F_78 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned long V_89 = - 1 , V_90 = - 1 , V_91 = - 1 , V_48 ;
struct V_18 * V_18 ;
if ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_28 ] ) ) )
F_74 ( V_7 , V_18 , & V_89 ) ;
if ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_29 ] ) ) )
F_74 ( V_7 , V_18 , & V_90 ) ;
V_91 = F_79 ( V_89 , V_90 ) ;
V_48 = V_57 + V_91 ;
F_53 ( V_7 ) ;
V_7 -> V_48 = V_48 ;
F_51 ( V_7 ) ;
V_7 -> V_54 &= ~ V_88 ;
}
static void F_80 ( struct V_1 * V_92 ,
struct V_1 * V_40 , bool V_27 )
{
if ( F_65 ( V_40 , V_27 ) ) {
F_59 ( V_40 , V_27 ,
V_92 -> V_62 [ V_27 ] ) ;
}
}
static void F_81 ( struct V_1 * V_7 , bool V_27 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_8 * V_10 = V_9 -> V_10 ;
struct V_1 * V_40 = F_7 ( V_10 ) ;
struct V_1 * V_21 = NULL ;
struct V_18 * V_18 ;
V_18 = F_21 ( & V_9 -> V_20 [ V_27 ] , & V_21 ) ;
V_9 -> V_85 [ V_27 ] -- ;
F_76 ( V_7 , V_18 ) ;
if ( V_40 ) {
F_77 ( V_18 , & V_7 -> V_31 [ V_27 ] , V_40 ) ;
F_80 ( V_7 , V_40 , V_27 ) ;
} else {
F_12 ( V_18 , & V_7 -> V_31 [ V_27 ] ,
& V_10 -> V_20 [ V_27 ] ) ;
F_68 ( V_7 -> V_13 -> V_85 [ V_27 ] <= 0 ) ;
V_7 -> V_13 -> V_85 [ V_27 ] -- ;
}
F_67 ( V_7 , V_27 ) ;
if ( V_21 )
F_25 ( F_5 ( V_21 ) ) ;
}
static int F_82 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned int V_93 = 0 , V_94 = 0 ;
unsigned int V_95 = V_96 * 3 / 4 ;
unsigned int V_97 = V_96 - V_95 ;
struct V_18 * V_18 ;
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_28 ] ) ) &&
F_74 ( V_7 , V_18 , NULL ) ) {
F_81 ( V_7 , F_71 ( V_18 ) ) ;
V_93 ++ ;
if ( V_93 >= V_95 )
break;
}
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_29 ] ) ) &&
F_74 ( V_7 , V_18 , NULL ) ) {
F_81 ( V_7 , F_71 ( V_18 ) ) ;
V_94 ++ ;
if ( V_94 >= V_97 )
break;
}
return V_93 + V_94 ;
}
static int F_83 ( struct V_8 * V_10 )
{
unsigned int V_98 = 0 ;
while ( 1 ) {
struct V_1 * V_7 = F_39 ( V_10 ) ;
struct V_8 * V_9 = & V_7 -> V_11 ;
if ( ! V_7 )
break;
if ( F_47 ( V_57 , V_7 -> V_48 ) )
break;
F_53 ( V_7 ) ;
V_98 += F_82 ( V_7 ) ;
if ( V_9 -> V_85 [ 0 ] || V_9 -> V_85 [ 1 ] )
F_78 ( V_7 ) ;
if ( V_98 >= V_99 )
break;
}
return V_98 ;
}
static void V_25 ( unsigned long V_100 )
{
struct V_8 * V_9 = ( void * ) V_100 ;
struct V_1 * V_7 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_9 ) ;
struct V_101 * V_35 = V_13 -> V_102 ;
struct V_8 * V_10 ;
bool V_103 ;
int V_104 ;
F_84 ( V_35 -> V_105 ) ;
V_106:
V_10 = V_9 -> V_10 ;
V_103 = false ;
while ( true ) {
F_56 ( V_9 , L_6 ,
V_9 -> V_85 [ V_28 ] + V_9 -> V_85 [ V_29 ] ,
V_9 -> V_85 [ V_28 ] , V_9 -> V_85 [ V_29 ] ) ;
V_104 = F_83 ( V_9 ) ;
if ( V_104 ) {
F_56 ( V_9 , L_7 , V_104 ) ;
V_103 = true ;
}
if ( F_57 ( V_9 , false ) )
break;
F_85 ( V_35 -> V_105 ) ;
F_86 () ;
F_84 ( V_35 -> V_105 ) ;
}
if ( ! V_103 )
goto V_107;
if ( V_10 ) {
if ( V_7 -> V_54 & V_88 ) {
F_78 ( V_7 ) ;
if ( ! F_57 ( V_10 , false ) ) {
V_9 = V_10 ;
V_7 = F_7 ( V_9 ) ;
goto V_106;
}
}
} else {
F_87 ( V_108 , & V_13 -> V_109 ) ;
}
V_107:
F_85 ( V_35 -> V_105 ) ;
}
static void F_88 ( struct V_110 * V_111 )
{
struct V_12 * V_13 = F_2 ( V_111 , struct V_12 ,
V_109 ) ;
struct V_8 * V_112 = & V_13 -> V_11 ;
struct V_101 * V_35 = V_13 -> V_102 ;
struct V_113 V_114 ;
struct V_18 * V_18 ;
struct V_115 V_116 ;
int V_27 ;
F_11 ( & V_114 ) ;
F_84 ( V_35 -> V_105 ) ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ )
while ( ( V_18 = F_21 ( & V_112 -> V_20 [ V_27 ] , NULL ) ) )
F_13 ( & V_114 , V_18 ) ;
F_85 ( V_35 -> V_105 ) ;
if ( ! F_23 ( & V_114 ) ) {
F_89 ( & V_116 ) ;
while( ( V_18 = F_22 ( & V_114 ) ) )
F_90 ( V_18 ) ;
F_91 ( & V_116 ) ;
}
}
static T_2 F_92 ( struct V_117 * V_118 , struct V_2 * V_3 ,
int V_119 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_2 V_120 = * ( T_2 * ) ( ( void * ) V_7 + V_119 ) ;
if ( V_120 == - 1 )
return 0 ;
return F_93 ( V_118 , V_3 , V_120 ) ;
}
static T_2 F_94 ( struct V_117 * V_118 , struct V_2 * V_3 ,
int V_119 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_120 = * ( unsigned int * ) ( ( void * ) V_7 + V_119 ) ;
if ( V_120 == - 1 )
return 0 ;
return F_93 ( V_118 , V_3 , V_120 ) ;
}
static int F_95 ( struct V_117 * V_118 , void * V_120 )
{
F_96 ( V_118 , F_97 ( F_98 ( V_118 ) ) , F_92 ,
& V_6 , F_99 ( V_118 ) -> V_121 , false ) ;
return 0 ;
}
static int F_100 ( struct V_117 * V_118 , void * V_120 )
{
F_96 ( V_118 , F_97 ( F_98 ( V_118 ) ) , F_94 ,
& V_6 , F_99 ( V_118 ) -> V_121 , false ) ;
return 0 ;
}
static void F_101 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_122 * V_123 ;
struct V_4 * V_5 ;
F_56 ( & V_7 -> V_11 ,
L_8 ,
V_7 -> V_33 [ V_28 ] , V_7 -> V_33 [ V_29 ] ,
V_7 -> V_34 [ V_28 ] , V_7 -> V_34 [ V_29 ] ) ;
F_102 (blkg, pos_css, tg_to_blkg(tg))
F_34 ( F_3 ( V_5 ) ) ;
F_61 ( V_7 , 0 ) ;
F_61 ( V_7 , 1 ) ;
if ( V_7 -> V_54 & V_55 ) {
F_78 ( V_7 ) ;
F_57 ( V_9 -> V_10 , true ) ;
}
}
static T_3 F_103 ( struct V_124 * V_125 ,
char * V_126 , T_4 V_127 , T_5 V_119 , bool V_128 )
{
struct V_36 * V_36 = F_97 ( F_104 ( V_125 ) ) ;
struct V_129 V_130 ;
struct V_1 * V_7 ;
int V_104 ;
T_2 V_120 ;
V_104 = F_105 ( V_36 , & V_6 , V_126 , & V_130 ) ;
if ( V_104 )
return V_104 ;
V_104 = - V_131 ;
if ( sscanf ( V_130 . V_132 , L_9 , & V_120 ) != 1 )
goto V_133;
if ( ! V_120 )
V_120 = - 1 ;
V_7 = F_3 ( V_130 . V_5 ) ;
if ( V_128 )
* ( T_2 * ) ( ( void * ) V_7 + F_106 ( V_125 ) -> V_121 ) = V_120 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + F_106 ( V_125 ) -> V_121 ) = V_120 ;
F_101 ( V_7 ) ;
V_104 = 0 ;
V_133:
F_107 ( & V_130 ) ;
return V_104 ? : V_127 ;
}
static T_3 F_108 ( struct V_124 * V_125 ,
char * V_126 , T_4 V_127 , T_5 V_119 )
{
return F_103 ( V_125 , V_126 , V_127 , V_119 , true ) ;
}
static T_3 F_109 ( struct V_124 * V_125 ,
char * V_126 , T_4 V_127 , T_5 V_119 )
{
return F_103 ( V_125 , V_126 , V_127 , V_119 , false ) ;
}
static T_2 F_110 ( struct V_117 * V_118 , struct V_2 * V_3 ,
int V_119 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
const char * V_134 = F_111 ( V_3 -> V_5 ) ;
char V_135 [ 4 ] [ 21 ] = { L_10 , L_10 , L_10 , L_10 } ;
if ( ! V_134 )
return 0 ;
if ( V_7 -> V_33 [ V_28 ] == - 1 && V_7 -> V_33 [ V_29 ] == - 1 &&
V_7 -> V_34 [ V_28 ] == - 1 && V_7 -> V_34 [ V_29 ] == - 1 )
return 0 ;
if ( V_7 -> V_33 [ V_28 ] != - 1 )
snprintf ( V_135 [ 0 ] , sizeof( V_135 [ 0 ] ) , L_9 , V_7 -> V_33 [ V_28 ] ) ;
if ( V_7 -> V_33 [ V_29 ] != - 1 )
snprintf ( V_135 [ 1 ] , sizeof( V_135 [ 1 ] ) , L_9 , V_7 -> V_33 [ V_29 ] ) ;
if ( V_7 -> V_34 [ V_28 ] != - 1 )
snprintf ( V_135 [ 2 ] , sizeof( V_135 [ 2 ] ) , L_11 , V_7 -> V_34 [ V_28 ] ) ;
if ( V_7 -> V_34 [ V_29 ] != - 1 )
snprintf ( V_135 [ 3 ] , sizeof( V_135 [ 3 ] ) , L_11 , V_7 -> V_34 [ V_29 ] ) ;
F_112 ( V_118 , L_12 ,
V_134 , V_135 [ 0 ] , V_135 [ 1 ] , V_135 [ 2 ] , V_135 [ 3 ] ) ;
return 0 ;
}
static int F_113 ( struct V_117 * V_118 , void * V_120 )
{
F_96 ( V_118 , F_97 ( F_98 ( V_118 ) ) , F_110 ,
& V_6 , F_99 ( V_118 ) -> V_121 , false ) ;
return 0 ;
}
static T_3 F_114 ( struct V_124 * V_125 ,
char * V_126 , T_4 V_127 , T_5 V_119 )
{
struct V_36 * V_36 = F_97 ( F_104 ( V_125 ) ) ;
struct V_129 V_130 ;
struct V_1 * V_7 ;
T_2 V_120 [ 4 ] ;
int V_104 ;
V_104 = F_105 ( V_36 , & V_6 , V_126 , & V_130 ) ;
if ( V_104 )
return V_104 ;
V_7 = F_3 ( V_130 . V_5 ) ;
V_120 [ 0 ] = V_7 -> V_33 [ V_28 ] ;
V_120 [ 1 ] = V_7 -> V_33 [ V_29 ] ;
V_120 [ 2 ] = V_7 -> V_34 [ V_28 ] ;
V_120 [ 3 ] = V_7 -> V_34 [ V_29 ] ;
while ( true ) {
char V_136 [ 27 ] ;
char * V_137 ;
T_2 V_138 = - 1 ;
int V_139 ;
if ( sscanf ( V_130 . V_132 , L_13 , V_136 , & V_139 ) != 1 )
break;
if ( V_136 [ 0 ] == '\0' )
break;
V_130 . V_132 += V_139 ;
V_104 = - V_131 ;
V_137 = V_136 ;
F_115 ( & V_137 , L_14 ) ;
if ( ! V_137 || ( sscanf ( V_137 , L_9 , & V_138 ) != 1 && strcmp ( V_137 , L_10 ) ) )
goto V_133;
V_104 = - V_140 ;
if ( ! V_138 )
goto V_133;
V_104 = - V_131 ;
if ( ! strcmp ( V_136 , L_15 ) )
V_120 [ 0 ] = V_138 ;
else if ( ! strcmp ( V_136 , L_16 ) )
V_120 [ 1 ] = V_138 ;
else if ( ! strcmp ( V_136 , L_17 ) )
V_120 [ 2 ] = F_116 ( T_2 , V_138 , V_77 ) ;
else if ( ! strcmp ( V_136 , L_18 ) )
V_120 [ 3 ] = F_116 ( T_2 , V_138 , V_77 ) ;
else
goto V_133;
}
V_7 -> V_33 [ V_28 ] = V_120 [ 0 ] ;
V_7 -> V_33 [ V_29 ] = V_120 [ 1 ] ;
V_7 -> V_34 [ V_28 ] = V_120 [ 2 ] ;
V_7 -> V_34 [ V_29 ] = V_120 [ 3 ] ;
F_101 ( V_7 ) ;
V_104 = 0 ;
V_133:
F_107 ( & V_130 ) ;
return V_104 ? : V_127 ;
}
static void F_117 ( struct V_101 * V_35 )
{
struct V_12 * V_13 = V_35 -> V_13 ;
F_118 ( & V_13 -> V_109 ) ;
}
bool F_119 ( struct V_101 * V_35 , struct V_4 * V_5 ,
struct V_18 * V_18 )
{
struct V_14 * V_15 = NULL ;
struct V_1 * V_7 = F_3 ( V_5 ? : V_35 -> V_141 ) ;
struct V_8 * V_9 ;
bool V_27 = F_71 ( V_18 ) ;
bool V_142 = false ;
F_20 ( ! F_120 () ) ;
if ( ( V_18 -> V_86 & V_87 ) || ! V_7 -> V_41 [ V_27 ] )
goto V_143;
F_84 ( V_35 -> V_105 ) ;
if ( F_121 ( F_122 ( V_35 ) ) )
goto V_107;
V_9 = & V_7 -> V_11 ;
while ( true ) {
if ( V_9 -> V_85 [ V_27 ] )
break;
if ( ! F_74 ( V_7 , V_18 , NULL ) )
break;
F_76 ( V_7 , V_18 ) ;
F_67 ( V_7 , V_27 ) ;
V_15 = & V_7 -> V_31 [ V_27 ] ;
V_9 = V_9 -> V_10 ;
V_7 = F_7 ( V_9 ) ;
if ( ! V_7 )
goto V_107;
}
F_56 ( V_9 , L_19 ,
V_27 == V_28 ? 'R' : 'W' ,
V_7 -> V_60 [ V_27 ] , V_18 -> V_80 . V_81 , V_7 -> V_33 [ V_27 ] ,
V_7 -> V_61 [ V_27 ] , V_7 -> V_34 [ V_27 ] ,
V_9 -> V_85 [ V_28 ] , V_9 -> V_85 [ V_29 ] ) ;
F_123 ( V_18 ) ;
V_7 -> V_13 -> V_85 [ V_27 ] ++ ;
F_77 ( V_18 , V_15 , V_7 ) ;
V_142 = true ;
if ( V_7 -> V_54 & V_88 ) {
F_78 ( V_7 ) ;
F_57 ( V_7 -> V_11 . V_10 , true ) ;
}
V_107:
F_85 ( V_35 -> V_105 ) ;
V_143:
if ( ! V_142 )
V_18 -> V_86 &= ~ V_87 ;
return V_142 ;
}
static void F_124 ( struct V_8 * V_10 )
{
struct V_1 * V_7 ;
while ( ( V_7 = F_39 ( V_10 ) ) ) {
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_18 * V_18 ;
F_53 ( V_7 ) ;
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_28 ] ) ) )
F_81 ( V_7 , F_71 ( V_18 ) ) ;
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_29 ] ) ) )
F_81 ( V_7 , F_71 ( V_18 ) ) ;
}
}
void F_125 ( struct V_101 * V_35 )
__releases( V_35 -> V_105 ) __acquires( V_35 -> V_105 )
{
struct V_12 * V_13 = V_35 -> V_13 ;
struct V_4 * V_5 ;
struct V_122 * V_123 ;
struct V_18 * V_18 ;
int V_27 ;
F_126 ( V_35 ) ;
F_127 () ;
F_128 (blkg, pos_css, td->queue->root_blkg)
F_124 ( & F_3 ( V_5 ) -> V_11 ) ;
F_124 ( & V_13 -> V_11 ) ;
F_129 () ;
F_85 ( V_35 -> V_105 ) ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ )
while ( ( V_18 = F_21 ( & V_13 -> V_11 . V_20 [ V_27 ] ,
NULL ) ) )
F_90 ( V_18 ) ;
F_84 ( V_35 -> V_105 ) ;
}
int F_130 ( struct V_101 * V_35 )
{
struct V_12 * V_13 ;
int V_104 ;
V_13 = F_30 ( sizeof( * V_13 ) , V_144 , V_35 -> V_16 ) ;
if ( ! V_13 )
return - V_145 ;
F_131 ( & V_13 -> V_109 , F_88 ) ;
F_27 ( & V_13 -> V_11 ) ;
V_35 -> V_13 = V_13 ;
V_13 -> V_102 = V_35 ;
V_104 = F_132 ( V_35 , & V_6 ) ;
if ( V_104 )
F_38 ( V_13 ) ;
return V_104 ;
}
void F_133 ( struct V_101 * V_35 )
{
F_68 ( ! V_35 -> V_13 ) ;
F_117 ( V_35 ) ;
F_134 ( V_35 , & V_6 ) ;
F_38 ( V_35 -> V_13 ) ;
}
static int T_6 F_135 ( void )
{
V_108 = F_136 ( L_20 , V_146 , 0 ) ;
if ( ! V_108 )
F_137 ( L_21 ) ;
return F_138 ( & V_6 ) ;
}
