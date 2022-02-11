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
if ( F_33 ( V_36 ) && V_5 -> V_37 )
V_9 -> V_10 = & F_3 ( V_5 -> V_37 ) -> V_11 ;
V_7 -> V_13 = V_13 ;
}
static void F_34 ( struct V_1 * V_7 )
{
struct V_1 * V_38 = F_7 ( V_7 -> V_11 . V_10 ) ;
int V_27 ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ )
V_7 -> V_39 [ V_27 ] = ( V_38 && V_38 -> V_39 [ V_27 ] ) ||
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
if ( ! V_10 -> V_40 )
return NULL ;
if ( ! V_10 -> V_41 )
V_10 -> V_41 = F_40 ( & V_10 -> V_22 ) ;
if ( V_10 -> V_41 )
return F_41 ( V_10 -> V_41 ) ;
return NULL ;
}
static void F_42 ( struct V_32 * V_42 , struct V_43 * V_44 )
{
F_43 ( V_42 , V_44 ) ;
F_31 ( V_42 ) ;
}
static void F_44 ( struct V_32 * V_42 ,
struct V_8 * V_10 )
{
if ( V_10 -> V_41 == V_42 )
V_10 -> V_41 = NULL ;
F_42 ( V_42 , & V_10 -> V_22 ) ;
-- V_10 -> V_40 ;
}
static void F_45 ( struct V_8 * V_10 )
{
struct V_1 * V_7 ;
V_7 = F_39 ( V_10 ) ;
if ( ! V_7 )
return;
V_10 -> V_45 = V_7 -> V_46 ;
}
static void F_46 ( struct V_1 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_11 . V_10 ;
struct V_32 * * V_16 = & V_10 -> V_22 . V_32 ;
struct V_32 * V_37 = NULL ;
struct V_1 * V_47 ;
unsigned long V_48 = V_7 -> V_46 ;
int V_49 = 1 ;
while ( * V_16 != NULL ) {
V_37 = * V_16 ;
V_47 = F_41 ( V_37 ) ;
if ( F_47 ( V_48 , V_47 -> V_46 ) )
V_16 = & V_37 -> V_50 ;
else {
V_16 = & V_37 -> V_51 ;
V_49 = 0 ;
}
}
if ( V_49 )
V_10 -> V_41 = & V_7 -> V_32 ;
F_48 ( & V_7 -> V_32 , V_37 , V_16 ) ;
F_49 ( & V_7 -> V_32 , & V_10 -> V_22 ) ;
}
static void F_50 ( struct V_1 * V_7 )
{
F_46 ( V_7 ) ;
V_7 -> V_52 |= V_53 ;
V_7 -> V_11 . V_10 -> V_40 ++ ;
}
static void F_51 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_52 & V_53 ) )
F_50 ( V_7 ) ;
}
static void F_52 ( struct V_1 * V_7 )
{
F_44 ( & V_7 -> V_32 , V_7 -> V_11 . V_10 ) ;
V_7 -> V_52 &= ~ V_53 ;
}
static void F_53 ( struct V_1 * V_7 )
{
if ( V_7 -> V_52 & V_53 )
F_52 ( V_7 ) ;
}
static void F_54 ( struct V_8 * V_9 ,
unsigned long V_54 )
{
F_55 ( & V_9 -> V_24 , V_54 ) ;
F_56 ( V_9 , L_1 ,
V_54 - V_55 , V_55 ) ;
}
static bool F_57 ( struct V_8 * V_9 ,
bool V_56 )
{
if ( ! V_9 -> V_40 )
return true ;
F_45 ( V_9 ) ;
if ( V_56 || F_58 ( V_9 -> V_45 , V_55 ) ) {
F_54 ( V_9 , V_9 -> V_45 ) ;
return true ;
}
return false ;
}
static inline void F_59 ( struct V_1 * V_7 ,
bool V_27 , unsigned long V_57 )
{
V_7 -> V_58 [ V_27 ] = 0 ;
V_7 -> V_59 [ V_27 ] = 0 ;
if ( F_60 ( V_57 , V_7 -> V_60 [ V_27 ] ) )
V_7 -> V_60 [ V_27 ] = V_57 ;
V_7 -> V_61 [ V_27 ] = V_55 + V_62 ;
F_56 ( & V_7 -> V_11 ,
L_2 ,
V_27 == V_28 ? 'R' : 'W' , V_7 -> V_60 [ V_27 ] ,
V_7 -> V_61 [ V_27 ] , V_55 ) ;
}
static inline void F_61 ( struct V_1 * V_7 , bool V_27 )
{
V_7 -> V_58 [ V_27 ] = 0 ;
V_7 -> V_59 [ V_27 ] = 0 ;
V_7 -> V_60 [ V_27 ] = V_55 ;
V_7 -> V_61 [ V_27 ] = V_55 + V_62 ;
F_56 ( & V_7 -> V_11 ,
L_3 ,
V_27 == V_28 ? 'R' : 'W' , V_7 -> V_60 [ V_27 ] ,
V_7 -> V_61 [ V_27 ] , V_55 ) ;
}
static inline void F_62 ( struct V_1 * V_7 , bool V_27 ,
unsigned long V_63 )
{
V_7 -> V_61 [ V_27 ] = F_63 ( V_63 , V_62 ) ;
}
static inline void F_64 ( struct V_1 * V_7 , bool V_27 ,
unsigned long V_63 )
{
V_7 -> V_61 [ V_27 ] = F_63 ( V_63 , V_62 ) ;
F_56 ( & V_7 -> V_11 ,
L_4 ,
V_27 == V_28 ? 'R' : 'W' , V_7 -> V_60 [ V_27 ] ,
V_7 -> V_61 [ V_27 ] , V_55 ) ;
}
static bool F_65 ( struct V_1 * V_7 , bool V_27 )
{
if ( F_66 ( V_55 , V_7 -> V_60 [ V_27 ] , V_7 -> V_61 [ V_27 ] ) )
return false ;
return 1 ;
}
static inline void F_67 ( struct V_1 * V_7 , bool V_27 )
{
unsigned long V_64 , V_65 , V_66 ;
T_2 V_67 , V_68 ;
F_68 ( F_47 ( V_7 -> V_61 [ V_27 ] , V_7 -> V_60 [ V_27 ] ) ) ;
if ( F_65 ( V_7 , V_27 ) )
return;
F_62 ( V_7 , V_27 , V_55 + V_62 ) ;
V_65 = V_55 - V_7 -> V_60 [ V_27 ] ;
V_64 = V_65 / V_62 ;
if ( ! V_64 )
return;
V_68 = V_7 -> V_33 [ V_27 ] * V_62 * V_64 ;
F_69 ( V_68 , V_69 ) ;
V_67 = V_68 ;
V_66 = ( V_7 -> V_34 [ V_27 ] * V_62 * V_64 ) / V_69 ;
if ( ! V_67 && ! V_66 )
return;
if ( V_7 -> V_58 [ V_27 ] >= V_67 )
V_7 -> V_58 [ V_27 ] -= V_67 ;
else
V_7 -> V_58 [ V_27 ] = 0 ;
if ( V_7 -> V_59 [ V_27 ] >= V_66 )
V_7 -> V_59 [ V_27 ] -= V_66 ;
else
V_7 -> V_59 [ V_27 ] = 0 ;
V_7 -> V_60 [ V_27 ] += V_64 * V_62 ;
F_56 ( & V_7 -> V_11 ,
L_5 ,
V_27 == V_28 ? 'R' : 'W' , V_64 , V_67 , V_66 ,
V_7 -> V_60 [ V_27 ] , V_7 -> V_61 [ V_27 ] , V_55 ) ;
}
static bool F_70 ( struct V_1 * V_7 , struct V_18 * V_18 ,
unsigned long * V_70 )
{
bool V_27 = F_71 ( V_18 ) ;
unsigned int V_71 ;
unsigned long V_72 , V_73 , V_74 ;
T_2 V_68 ;
V_72 = V_74 = V_55 - V_7 -> V_60 [ V_27 ] ;
if ( ! V_72 )
V_74 = V_62 ;
V_74 = F_63 ( V_74 , V_62 ) ;
V_68 = ( T_2 ) V_7 -> V_34 [ V_27 ] * V_74 ;
F_69 ( V_68 , V_69 ) ;
if ( V_68 > V_75 )
V_71 = V_75 ;
else
V_71 = V_68 ;
if ( V_7 -> V_59 [ V_27 ] + 1 <= V_71 ) {
if ( V_70 )
* V_70 = 0 ;
return true ;
}
V_73 = ( ( V_7 -> V_59 [ V_27 ] + 1 ) * V_69 ) / V_7 -> V_34 [ V_27 ] + 1 ;
if ( V_73 > V_72 )
V_73 = V_73 - V_72 ;
else
V_73 = 1 ;
if ( V_70 )
* V_70 = V_73 ;
return 0 ;
}
static bool F_72 ( struct V_1 * V_7 , struct V_18 * V_18 ,
unsigned long * V_70 )
{
bool V_27 = F_71 ( V_18 ) ;
T_2 V_76 , V_77 , V_68 ;
unsigned long V_72 , V_73 , V_74 ;
V_72 = V_74 = V_55 - V_7 -> V_60 [ V_27 ] ;
if ( ! V_72 )
V_74 = V_62 ;
V_74 = F_63 ( V_74 , V_62 ) ;
V_68 = V_7 -> V_33 [ V_27 ] * V_74 ;
F_69 ( V_68 , V_69 ) ;
V_76 = V_68 ;
if ( V_7 -> V_58 [ V_27 ] + V_18 -> V_78 . V_79 <= V_76 ) {
if ( V_70 )
* V_70 = 0 ;
return true ;
}
V_77 = V_7 -> V_58 [ V_27 ] + V_18 -> V_78 . V_79 - V_76 ;
V_73 = F_73 ( V_77 * V_69 , V_7 -> V_33 [ V_27 ] ) ;
if ( ! V_73 )
V_73 = 1 ;
V_73 = V_73 + ( V_74 - V_72 ) ;
if ( V_70 )
* V_70 = V_73 ;
return 0 ;
}
static bool F_74 ( struct V_1 * V_7 , struct V_18 * V_18 ,
unsigned long * V_70 )
{
bool V_27 = F_71 ( V_18 ) ;
unsigned long V_80 = 0 , V_81 = 0 , V_82 = 0 ;
F_68 ( V_7 -> V_11 . V_83 [ V_27 ] &&
V_18 != F_17 ( & V_7 -> V_11 . V_20 [ V_27 ] ) ) ;
if ( V_7 -> V_33 [ V_27 ] == - 1 && V_7 -> V_34 [ V_27 ] == - 1 ) {
if ( V_70 )
* V_70 = 0 ;
return true ;
}
if ( F_65 ( V_7 , V_27 ) )
F_61 ( V_7 , V_27 ) ;
else {
if ( F_47 ( V_7 -> V_61 [ V_27 ] , V_55 + V_62 ) )
F_64 ( V_7 , V_27 , V_55 + V_62 ) ;
}
if ( F_72 ( V_7 , V_18 , & V_80 ) &&
F_70 ( V_7 , V_18 , & V_81 ) ) {
if ( V_70 )
* V_70 = 0 ;
return 1 ;
}
V_82 = F_75 ( V_80 , V_81 ) ;
if ( V_70 )
* V_70 = V_82 ;
if ( F_47 ( V_7 -> V_61 [ V_27 ] , V_55 + V_82 ) )
F_64 ( V_7 , V_27 , V_55 + V_82 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_7 , struct V_18 * V_18 )
{
bool V_27 = F_71 ( V_18 ) ;
V_7 -> V_58 [ V_27 ] += V_18 -> V_78 . V_79 ;
V_7 -> V_59 [ V_27 ] ++ ;
if ( ! ( V_18 -> V_84 & V_85 ) )
V_18 -> V_84 |= V_85 ;
}
static void F_77 ( struct V_18 * V_18 , struct V_14 * V_15 ,
struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
bool V_27 = F_71 ( V_18 ) ;
if ( ! V_15 )
V_15 = & V_7 -> V_30 [ V_27 ] ;
if ( ! V_9 -> V_83 [ V_27 ] )
V_7 -> V_52 |= V_86 ;
F_12 ( V_18 , V_15 , & V_9 -> V_20 [ V_27 ] ) ;
V_9 -> V_83 [ V_27 ] ++ ;
F_51 ( V_7 ) ;
}
static void F_78 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned long V_87 = - 1 , V_88 = - 1 , V_89 = - 1 , V_46 ;
struct V_18 * V_18 ;
if ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_28 ] ) ) )
F_74 ( V_7 , V_18 , & V_87 ) ;
if ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_29 ] ) ) )
F_74 ( V_7 , V_18 , & V_88 ) ;
V_89 = F_79 ( V_87 , V_88 ) ;
V_46 = V_55 + V_89 ;
F_53 ( V_7 ) ;
V_7 -> V_46 = V_46 ;
F_51 ( V_7 ) ;
V_7 -> V_52 &= ~ V_86 ;
}
static void F_80 ( struct V_1 * V_90 ,
struct V_1 * V_38 , bool V_27 )
{
if ( F_65 ( V_38 , V_27 ) ) {
F_59 ( V_38 , V_27 ,
V_90 -> V_60 [ V_27 ] ) ;
}
}
static void F_81 ( struct V_1 * V_7 , bool V_27 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_8 * V_10 = V_9 -> V_10 ;
struct V_1 * V_38 = F_7 ( V_10 ) ;
struct V_1 * V_21 = NULL ;
struct V_18 * V_18 ;
V_18 = F_21 ( & V_9 -> V_20 [ V_27 ] , & V_21 ) ;
V_9 -> V_83 [ V_27 ] -- ;
F_76 ( V_7 , V_18 ) ;
if ( V_38 ) {
F_77 ( V_18 , & V_7 -> V_31 [ V_27 ] , V_38 ) ;
F_80 ( V_7 , V_38 , V_27 ) ;
} else {
F_12 ( V_18 , & V_7 -> V_31 [ V_27 ] ,
& V_10 -> V_20 [ V_27 ] ) ;
F_68 ( V_7 -> V_13 -> V_83 [ V_27 ] <= 0 ) ;
V_7 -> V_13 -> V_83 [ V_27 ] -- ;
}
F_67 ( V_7 , V_27 ) ;
if ( V_21 )
F_25 ( F_5 ( V_21 ) ) ;
}
static int F_82 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned int V_91 = 0 , V_92 = 0 ;
unsigned int V_93 = V_94 * 3 / 4 ;
unsigned int V_95 = V_94 - V_93 ;
struct V_18 * V_18 ;
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_28 ] ) ) &&
F_74 ( V_7 , V_18 , NULL ) ) {
F_81 ( V_7 , F_71 ( V_18 ) ) ;
V_91 ++ ;
if ( V_91 >= V_93 )
break;
}
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_29 ] ) ) &&
F_74 ( V_7 , V_18 , NULL ) ) {
F_81 ( V_7 , F_71 ( V_18 ) ) ;
V_92 ++ ;
if ( V_92 >= V_95 )
break;
}
return V_91 + V_92 ;
}
static int F_83 ( struct V_8 * V_10 )
{
unsigned int V_96 = 0 ;
while ( 1 ) {
struct V_1 * V_7 = F_39 ( V_10 ) ;
struct V_8 * V_9 = & V_7 -> V_11 ;
if ( ! V_7 )
break;
if ( F_47 ( V_55 , V_7 -> V_46 ) )
break;
F_53 ( V_7 ) ;
V_96 += F_82 ( V_7 ) ;
if ( V_9 -> V_83 [ 0 ] || V_9 -> V_83 [ 1 ] )
F_78 ( V_7 ) ;
if ( V_96 >= V_97 )
break;
}
return V_96 ;
}
static void V_25 ( unsigned long V_98 )
{
struct V_8 * V_9 = ( void * ) V_98 ;
struct V_1 * V_7 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_9 ) ;
struct V_99 * V_35 = V_13 -> V_100 ;
struct V_8 * V_10 ;
bool V_101 ;
int V_102 ;
F_84 ( V_35 -> V_103 ) ;
V_104:
V_10 = V_9 -> V_10 ;
V_101 = false ;
while ( true ) {
F_56 ( V_9 , L_6 ,
V_9 -> V_83 [ V_28 ] + V_9 -> V_83 [ V_29 ] ,
V_9 -> V_83 [ V_28 ] , V_9 -> V_83 [ V_29 ] ) ;
V_102 = F_83 ( V_9 ) ;
if ( V_102 ) {
F_56 ( V_9 , L_7 , V_102 ) ;
V_101 = true ;
}
if ( F_57 ( V_9 , false ) )
break;
F_85 ( V_35 -> V_103 ) ;
F_86 () ;
F_84 ( V_35 -> V_103 ) ;
}
if ( ! V_101 )
goto V_105;
if ( V_10 ) {
if ( V_7 -> V_52 & V_86 ) {
F_78 ( V_7 ) ;
if ( ! F_57 ( V_10 , false ) ) {
V_9 = V_10 ;
V_7 = F_7 ( V_9 ) ;
goto V_104;
}
}
} else {
F_87 ( V_106 , & V_13 -> V_107 ) ;
}
V_105:
F_85 ( V_35 -> V_103 ) ;
}
static void F_88 ( struct V_108 * V_109 )
{
struct V_12 * V_13 = F_2 ( V_109 , struct V_12 ,
V_107 ) ;
struct V_8 * V_110 = & V_13 -> V_11 ;
struct V_99 * V_35 = V_13 -> V_100 ;
struct V_111 V_112 ;
struct V_18 * V_18 ;
struct V_113 V_114 ;
int V_27 ;
F_11 ( & V_112 ) ;
F_84 ( V_35 -> V_103 ) ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ )
while ( ( V_18 = F_21 ( & V_110 -> V_20 [ V_27 ] , NULL ) ) )
F_13 ( & V_112 , V_18 ) ;
F_85 ( V_35 -> V_103 ) ;
if ( ! F_23 ( & V_112 ) ) {
F_89 ( & V_114 ) ;
while( ( V_18 = F_22 ( & V_112 ) ) )
F_90 ( V_18 ) ;
F_91 ( & V_114 ) ;
}
}
static T_2 F_92 ( struct V_115 * V_116 , struct V_2 * V_3 ,
int V_117 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_2 V_118 = * ( T_2 * ) ( ( void * ) V_7 + V_117 ) ;
if ( V_118 == - 1 )
return 0 ;
return F_93 ( V_116 , V_3 , V_118 ) ;
}
static T_2 F_94 ( struct V_115 * V_116 , struct V_2 * V_3 ,
int V_117 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_118 = * ( unsigned int * ) ( ( void * ) V_7 + V_117 ) ;
if ( V_118 == - 1 )
return 0 ;
return F_93 ( V_116 , V_3 , V_118 ) ;
}
static int F_95 ( struct V_115 * V_116 , void * V_118 )
{
F_96 ( V_116 , F_97 ( F_98 ( V_116 ) ) , F_92 ,
& V_6 , F_99 ( V_116 ) -> V_119 , false ) ;
return 0 ;
}
static int F_100 ( struct V_115 * V_116 , void * V_118 )
{
F_96 ( V_116 , F_97 ( F_98 ( V_116 ) ) , F_94 ,
& V_6 , F_99 ( V_116 ) -> V_119 , false ) ;
return 0 ;
}
static void F_101 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_120 * V_121 ;
struct V_4 * V_5 ;
F_56 ( & V_7 -> V_11 ,
L_8 ,
V_7 -> V_33 [ V_28 ] , V_7 -> V_33 [ V_29 ] ,
V_7 -> V_34 [ V_28 ] , V_7 -> V_34 [ V_29 ] ) ;
F_102 (blkg, pos_css, tg_to_blkg(tg))
F_34 ( F_3 ( V_5 ) ) ;
F_61 ( V_7 , 0 ) ;
F_61 ( V_7 , 1 ) ;
if ( V_7 -> V_52 & V_53 ) {
F_78 ( V_7 ) ;
F_57 ( V_9 -> V_10 , true ) ;
}
}
static T_3 F_103 ( struct V_122 * V_123 ,
char * V_124 , T_4 V_125 , T_5 V_117 , bool V_126 )
{
struct V_127 * V_127 = F_97 ( F_104 ( V_123 ) ) ;
struct V_128 V_129 ;
struct V_1 * V_7 ;
int V_102 ;
T_2 V_118 ;
V_102 = F_105 ( V_127 , & V_6 , V_124 , & V_129 ) ;
if ( V_102 )
return V_102 ;
V_102 = - V_130 ;
if ( sscanf ( V_129 . V_131 , L_9 , & V_118 ) != 1 )
goto V_132;
if ( ! V_118 )
V_118 = - 1 ;
V_7 = F_3 ( V_129 . V_5 ) ;
if ( V_126 )
* ( T_2 * ) ( ( void * ) V_7 + F_106 ( V_123 ) -> V_119 ) = V_118 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + F_106 ( V_123 ) -> V_119 ) = V_118 ;
F_101 ( V_7 ) ;
V_102 = 0 ;
V_132:
F_107 ( & V_129 ) ;
return V_102 ? : V_125 ;
}
static T_3 F_108 ( struct V_122 * V_123 ,
char * V_124 , T_4 V_125 , T_5 V_117 )
{
return F_103 ( V_123 , V_124 , V_125 , V_117 , true ) ;
}
static T_3 F_109 ( struct V_122 * V_123 ,
char * V_124 , T_4 V_125 , T_5 V_117 )
{
return F_103 ( V_123 , V_124 , V_125 , V_117 , false ) ;
}
static T_2 F_110 ( struct V_115 * V_116 , struct V_2 * V_3 ,
int V_117 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
const char * V_133 = F_111 ( V_3 -> V_5 ) ;
char V_134 [ 4 ] [ 21 ] = { L_10 , L_10 , L_10 , L_10 } ;
if ( ! V_133 )
return 0 ;
if ( V_7 -> V_33 [ V_28 ] == - 1 && V_7 -> V_33 [ V_29 ] == - 1 &&
V_7 -> V_34 [ V_28 ] == - 1 && V_7 -> V_34 [ V_29 ] == - 1 )
return 0 ;
if ( V_7 -> V_33 [ V_28 ] != - 1 )
snprintf ( V_134 [ 0 ] , sizeof( V_134 [ 0 ] ) , L_9 , V_7 -> V_33 [ V_28 ] ) ;
if ( V_7 -> V_33 [ V_29 ] != - 1 )
snprintf ( V_134 [ 1 ] , sizeof( V_134 [ 1 ] ) , L_9 , V_7 -> V_33 [ V_29 ] ) ;
if ( V_7 -> V_34 [ V_28 ] != - 1 )
snprintf ( V_134 [ 2 ] , sizeof( V_134 [ 2 ] ) , L_11 , V_7 -> V_34 [ V_28 ] ) ;
if ( V_7 -> V_34 [ V_29 ] != - 1 )
snprintf ( V_134 [ 3 ] , sizeof( V_134 [ 3 ] ) , L_11 , V_7 -> V_34 [ V_29 ] ) ;
F_112 ( V_116 , L_12 ,
V_133 , V_134 [ 0 ] , V_134 [ 1 ] , V_134 [ 2 ] , V_134 [ 3 ] ) ;
return 0 ;
}
static int F_113 ( struct V_115 * V_116 , void * V_118 )
{
F_96 ( V_116 , F_97 ( F_98 ( V_116 ) ) , F_110 ,
& V_6 , F_99 ( V_116 ) -> V_119 , false ) ;
return 0 ;
}
static T_3 F_114 ( struct V_122 * V_123 ,
char * V_124 , T_4 V_125 , T_5 V_117 )
{
struct V_127 * V_127 = F_97 ( F_104 ( V_123 ) ) ;
struct V_128 V_129 ;
struct V_1 * V_7 ;
T_2 V_118 [ 4 ] ;
int V_102 ;
V_102 = F_105 ( V_127 , & V_6 , V_124 , & V_129 ) ;
if ( V_102 )
return V_102 ;
V_7 = F_3 ( V_129 . V_5 ) ;
V_118 [ 0 ] = V_7 -> V_33 [ V_28 ] ;
V_118 [ 1 ] = V_7 -> V_33 [ V_29 ] ;
V_118 [ 2 ] = V_7 -> V_34 [ V_28 ] ;
V_118 [ 3 ] = V_7 -> V_34 [ V_29 ] ;
while ( true ) {
char V_135 [ 27 ] ;
char * V_136 ;
T_2 V_137 = - 1 ;
int V_138 ;
if ( sscanf ( V_129 . V_131 , L_13 , V_135 , & V_138 ) != 1 )
break;
if ( V_135 [ 0 ] == '\0' )
break;
V_129 . V_131 += V_138 ;
V_102 = - V_130 ;
V_136 = V_135 ;
F_115 ( & V_136 , L_14 ) ;
if ( ! V_136 || ( sscanf ( V_136 , L_9 , & V_137 ) != 1 && strcmp ( V_136 , L_10 ) ) )
goto V_132;
V_102 = - V_139 ;
if ( ! V_137 )
goto V_132;
V_102 = - V_130 ;
if ( ! strcmp ( V_135 , L_15 ) )
V_118 [ 0 ] = V_137 ;
else if ( ! strcmp ( V_135 , L_16 ) )
V_118 [ 1 ] = V_137 ;
else if ( ! strcmp ( V_135 , L_17 ) )
V_118 [ 2 ] = F_116 ( T_2 , V_137 , V_75 ) ;
else if ( ! strcmp ( V_135 , L_18 ) )
V_118 [ 3 ] = F_116 ( T_2 , V_137 , V_75 ) ;
else
goto V_132;
}
V_7 -> V_33 [ V_28 ] = V_118 [ 0 ] ;
V_7 -> V_33 [ V_29 ] = V_118 [ 1 ] ;
V_7 -> V_34 [ V_28 ] = V_118 [ 2 ] ;
V_7 -> V_34 [ V_29 ] = V_118 [ 3 ] ;
F_101 ( V_7 ) ;
V_102 = 0 ;
V_132:
F_107 ( & V_129 ) ;
return V_102 ? : V_125 ;
}
static void F_117 ( struct V_99 * V_35 )
{
struct V_12 * V_13 = V_35 -> V_13 ;
F_118 ( & V_13 -> V_107 ) ;
}
bool F_119 ( struct V_99 * V_35 , struct V_4 * V_5 ,
struct V_18 * V_18 )
{
struct V_14 * V_15 = NULL ;
struct V_1 * V_7 = F_3 ( V_5 ? : V_35 -> V_140 ) ;
struct V_8 * V_9 ;
bool V_27 = F_71 ( V_18 ) ;
bool V_141 = false ;
F_20 ( ! F_120 () ) ;
if ( ( V_18 -> V_84 & V_85 ) || ! V_7 -> V_39 [ V_27 ] )
goto V_142;
F_84 ( V_35 -> V_103 ) ;
if ( F_121 ( F_122 ( V_35 ) ) )
goto V_105;
V_9 = & V_7 -> V_11 ;
while ( true ) {
if ( V_9 -> V_83 [ V_27 ] )
break;
if ( ! F_74 ( V_7 , V_18 , NULL ) )
break;
F_76 ( V_7 , V_18 ) ;
F_67 ( V_7 , V_27 ) ;
V_15 = & V_7 -> V_31 [ V_27 ] ;
V_9 = V_9 -> V_10 ;
V_7 = F_7 ( V_9 ) ;
if ( ! V_7 )
goto V_105;
}
F_56 ( V_9 , L_19 ,
V_27 == V_28 ? 'R' : 'W' ,
V_7 -> V_58 [ V_27 ] , V_18 -> V_78 . V_79 , V_7 -> V_33 [ V_27 ] ,
V_7 -> V_59 [ V_27 ] , V_7 -> V_34 [ V_27 ] ,
V_9 -> V_83 [ V_28 ] , V_9 -> V_83 [ V_29 ] ) ;
F_123 ( V_18 ) ;
V_7 -> V_13 -> V_83 [ V_27 ] ++ ;
F_77 ( V_18 , V_15 , V_7 ) ;
V_141 = true ;
if ( V_7 -> V_52 & V_86 ) {
F_78 ( V_7 ) ;
F_57 ( V_7 -> V_11 . V_10 , true ) ;
}
V_105:
F_85 ( V_35 -> V_103 ) ;
V_142:
if ( ! V_141 )
V_18 -> V_84 &= ~ V_85 ;
return V_141 ;
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
void F_125 ( struct V_99 * V_35 )
__releases( V_35 -> V_103 ) __acquires( V_35 -> V_103 )
{
struct V_12 * V_13 = V_35 -> V_13 ;
struct V_4 * V_5 ;
struct V_120 * V_121 ;
struct V_18 * V_18 ;
int V_27 ;
F_126 ( V_35 ) ;
F_127 () ;
F_128 (blkg, pos_css, td->queue->root_blkg)
F_124 ( & F_3 ( V_5 ) -> V_11 ) ;
F_124 ( & V_13 -> V_11 ) ;
F_129 () ;
F_85 ( V_35 -> V_103 ) ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ )
while ( ( V_18 = F_21 ( & V_13 -> V_11 . V_20 [ V_27 ] ,
NULL ) ) )
F_90 ( V_18 ) ;
F_84 ( V_35 -> V_103 ) ;
}
int F_130 ( struct V_99 * V_35 )
{
struct V_12 * V_13 ;
int V_102 ;
V_13 = F_30 ( sizeof( * V_13 ) , V_143 , V_35 -> V_16 ) ;
if ( ! V_13 )
return - V_144 ;
F_131 ( & V_13 -> V_107 , F_88 ) ;
F_27 ( & V_13 -> V_11 ) ;
V_35 -> V_13 = V_13 ;
V_13 -> V_100 = V_35 ;
V_102 = F_132 ( V_35 , & V_6 ) ;
if ( V_102 )
F_38 ( V_13 ) ;
return V_102 ;
}
void F_133 ( struct V_99 * V_35 )
{
F_68 ( ! V_35 -> V_13 ) ;
F_117 ( V_35 ) ;
F_134 ( V_35 , & V_6 ) ;
F_38 ( V_35 -> V_13 ) ;
}
static int T_6 F_135 ( void )
{
V_106 = F_136 ( L_20 , V_145 , 0 ) ;
if ( ! V_106 )
F_137 ( L_21 ) ;
return F_138 ( & V_6 ) ;
}
