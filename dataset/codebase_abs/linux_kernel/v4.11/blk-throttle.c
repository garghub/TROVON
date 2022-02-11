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
if ( F_65 ( V_7 , V_27 ) && ! ( V_7 -> V_11 . V_83 [ V_27 ] ) )
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
if ( ! F_77 ( V_18 , V_84 ) )
F_78 ( V_18 , V_84 ) ;
}
static void F_79 ( struct V_18 * V_18 , struct V_14 * V_15 ,
struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
bool V_27 = F_71 ( V_18 ) ;
if ( ! V_15 )
V_15 = & V_7 -> V_30 [ V_27 ] ;
if ( ! V_9 -> V_83 [ V_27 ] )
V_7 -> V_52 |= V_85 ;
F_12 ( V_18 , V_15 , & V_9 -> V_20 [ V_27 ] ) ;
V_9 -> V_83 [ V_27 ] ++ ;
F_51 ( V_7 ) ;
}
static void F_80 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned long V_86 = - 1 , V_87 = - 1 , V_88 = - 1 , V_46 ;
struct V_18 * V_18 ;
V_18 = F_17 ( & V_9 -> V_20 [ V_28 ] ) ;
if ( V_18 )
F_74 ( V_7 , V_18 , & V_86 ) ;
V_18 = F_17 ( & V_9 -> V_20 [ V_29 ] ) ;
if ( V_18 )
F_74 ( V_7 , V_18 , & V_87 ) ;
V_88 = F_81 ( V_86 , V_87 ) ;
V_46 = V_55 + V_88 ;
F_53 ( V_7 ) ;
V_7 -> V_46 = V_46 ;
F_51 ( V_7 ) ;
V_7 -> V_52 &= ~ V_85 ;
}
static void F_82 ( struct V_1 * V_89 ,
struct V_1 * V_38 , bool V_27 )
{
if ( F_65 ( V_38 , V_27 ) ) {
F_59 ( V_38 , V_27 ,
V_89 -> V_60 [ V_27 ] ) ;
}
}
static void F_83 ( struct V_1 * V_7 , bool V_27 )
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
F_79 ( V_18 , & V_7 -> V_31 [ V_27 ] , V_38 ) ;
F_82 ( V_7 , V_38 , V_27 ) ;
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
static int F_84 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
unsigned int V_90 = 0 , V_91 = 0 ;
unsigned int V_92 = V_93 * 3 / 4 ;
unsigned int V_94 = V_93 - V_92 ;
struct V_18 * V_18 ;
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_28 ] ) ) &&
F_74 ( V_7 , V_18 , NULL ) ) {
F_83 ( V_7 , F_71 ( V_18 ) ) ;
V_90 ++ ;
if ( V_90 >= V_92 )
break;
}
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_29 ] ) ) &&
F_74 ( V_7 , V_18 , NULL ) ) {
F_83 ( V_7 , F_71 ( V_18 ) ) ;
V_91 ++ ;
if ( V_91 >= V_94 )
break;
}
return V_90 + V_91 ;
}
static int F_85 ( struct V_8 * V_10 )
{
unsigned int V_95 = 0 ;
while ( 1 ) {
struct V_1 * V_7 = F_39 ( V_10 ) ;
struct V_8 * V_9 = & V_7 -> V_11 ;
if ( ! V_7 )
break;
if ( F_47 ( V_55 , V_7 -> V_46 ) )
break;
F_53 ( V_7 ) ;
V_95 += F_84 ( V_7 ) ;
if ( V_9 -> V_83 [ 0 ] || V_9 -> V_83 [ 1 ] )
F_80 ( V_7 ) ;
if ( V_95 >= V_96 )
break;
}
return V_95 ;
}
static void V_25 ( unsigned long V_97 )
{
struct V_8 * V_9 = ( void * ) V_97 ;
struct V_1 * V_7 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_9 ) ;
struct V_98 * V_35 = V_13 -> V_99 ;
struct V_8 * V_10 ;
bool V_100 ;
int V_101 ;
F_86 ( V_35 -> V_102 ) ;
V_103:
V_10 = V_9 -> V_10 ;
V_100 = false ;
while ( true ) {
F_56 ( V_9 , L_6 ,
V_9 -> V_83 [ V_28 ] + V_9 -> V_83 [ V_29 ] ,
V_9 -> V_83 [ V_28 ] , V_9 -> V_83 [ V_29 ] ) ;
V_101 = F_85 ( V_9 ) ;
if ( V_101 ) {
F_56 ( V_9 , L_7 , V_101 ) ;
V_100 = true ;
}
if ( F_57 ( V_9 , false ) )
break;
F_87 ( V_35 -> V_102 ) ;
F_88 () ;
F_86 ( V_35 -> V_102 ) ;
}
if ( ! V_100 )
goto V_104;
if ( V_10 ) {
if ( V_7 -> V_52 & V_85 ) {
F_80 ( V_7 ) ;
if ( ! F_57 ( V_10 , false ) ) {
V_9 = V_10 ;
V_7 = F_7 ( V_9 ) ;
goto V_103;
}
}
} else {
F_89 ( V_105 , & V_13 -> V_106 ) ;
}
V_104:
F_87 ( V_35 -> V_102 ) ;
}
static void F_90 ( struct V_107 * V_108 )
{
struct V_12 * V_13 = F_2 ( V_108 , struct V_12 ,
V_106 ) ;
struct V_8 * V_109 = & V_13 -> V_11 ;
struct V_98 * V_35 = V_13 -> V_99 ;
struct V_110 V_111 ;
struct V_18 * V_18 ;
struct V_112 V_113 ;
int V_27 ;
F_11 ( & V_111 ) ;
F_86 ( V_35 -> V_102 ) ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ )
while ( ( V_18 = F_21 ( & V_109 -> V_20 [ V_27 ] , NULL ) ) )
F_13 ( & V_111 , V_18 ) ;
F_87 ( V_35 -> V_102 ) ;
if ( ! F_23 ( & V_111 ) ) {
F_91 ( & V_113 ) ;
while( ( V_18 = F_22 ( & V_111 ) ) )
F_92 ( V_18 ) ;
F_93 ( & V_113 ) ;
}
}
static T_2 F_94 ( struct V_114 * V_115 , struct V_2 * V_3 ,
int V_116 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_2 V_117 = * ( T_2 * ) ( ( void * ) V_7 + V_116 ) ;
if ( V_117 == - 1 )
return 0 ;
return F_95 ( V_115 , V_3 , V_117 ) ;
}
static T_2 F_96 ( struct V_114 * V_115 , struct V_2 * V_3 ,
int V_116 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_117 = * ( unsigned int * ) ( ( void * ) V_7 + V_116 ) ;
if ( V_117 == - 1 )
return 0 ;
return F_95 ( V_115 , V_3 , V_117 ) ;
}
static int F_97 ( struct V_114 * V_115 , void * V_117 )
{
F_98 ( V_115 , F_99 ( F_100 ( V_115 ) ) , F_94 ,
& V_6 , F_101 ( V_115 ) -> V_118 , false ) ;
return 0 ;
}
static int F_102 ( struct V_114 * V_115 , void * V_117 )
{
F_98 ( V_115 , F_99 ( F_100 ( V_115 ) ) , F_96 ,
& V_6 , F_101 ( V_115 ) -> V_118 , false ) ;
return 0 ;
}
static void F_103 ( struct V_1 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_119 * V_120 ;
struct V_4 * V_5 ;
F_56 ( & V_7 -> V_11 ,
L_8 ,
V_7 -> V_33 [ V_28 ] , V_7 -> V_33 [ V_29 ] ,
V_7 -> V_34 [ V_28 ] , V_7 -> V_34 [ V_29 ] ) ;
F_104 (blkg, pos_css, tg_to_blkg(tg))
F_34 ( F_3 ( V_5 ) ) ;
F_61 ( V_7 , 0 ) ;
F_61 ( V_7 , 1 ) ;
if ( V_7 -> V_52 & V_53 ) {
F_80 ( V_7 ) ;
F_57 ( V_9 -> V_10 , true ) ;
}
}
static T_3 F_105 ( struct V_121 * V_122 ,
char * V_123 , T_4 V_124 , T_5 V_116 , bool V_125 )
{
struct V_126 * V_126 = F_99 ( F_106 ( V_122 ) ) ;
struct V_127 V_128 ;
struct V_1 * V_7 ;
int V_101 ;
T_2 V_117 ;
V_101 = F_107 ( V_126 , & V_6 , V_123 , & V_128 ) ;
if ( V_101 )
return V_101 ;
V_101 = - V_129 ;
if ( sscanf ( V_128 . V_130 , L_9 , & V_117 ) != 1 )
goto V_131;
if ( ! V_117 )
V_117 = - 1 ;
V_7 = F_3 ( V_128 . V_5 ) ;
if ( V_125 )
* ( T_2 * ) ( ( void * ) V_7 + F_108 ( V_122 ) -> V_118 ) = V_117 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + F_108 ( V_122 ) -> V_118 ) = V_117 ;
F_103 ( V_7 ) ;
V_101 = 0 ;
V_131:
F_109 ( & V_128 ) ;
return V_101 ? : V_124 ;
}
static T_3 F_110 ( struct V_121 * V_122 ,
char * V_123 , T_4 V_124 , T_5 V_116 )
{
return F_105 ( V_122 , V_123 , V_124 , V_116 , true ) ;
}
static T_3 F_111 ( struct V_121 * V_122 ,
char * V_123 , T_4 V_124 , T_5 V_116 )
{
return F_105 ( V_122 , V_123 , V_124 , V_116 , false ) ;
}
static T_2 F_112 ( struct V_114 * V_115 , struct V_2 * V_3 ,
int V_116 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
const char * V_132 = F_113 ( V_3 -> V_5 ) ;
char V_133 [ 4 ] [ 21 ] = { L_10 , L_10 , L_10 , L_10 } ;
if ( ! V_132 )
return 0 ;
if ( V_7 -> V_33 [ V_28 ] == - 1 && V_7 -> V_33 [ V_29 ] == - 1 &&
V_7 -> V_34 [ V_28 ] == - 1 && V_7 -> V_34 [ V_29 ] == - 1 )
return 0 ;
if ( V_7 -> V_33 [ V_28 ] != - 1 )
snprintf ( V_133 [ 0 ] , sizeof( V_133 [ 0 ] ) , L_9 , V_7 -> V_33 [ V_28 ] ) ;
if ( V_7 -> V_33 [ V_29 ] != - 1 )
snprintf ( V_133 [ 1 ] , sizeof( V_133 [ 1 ] ) , L_9 , V_7 -> V_33 [ V_29 ] ) ;
if ( V_7 -> V_34 [ V_28 ] != - 1 )
snprintf ( V_133 [ 2 ] , sizeof( V_133 [ 2 ] ) , L_11 , V_7 -> V_34 [ V_28 ] ) ;
if ( V_7 -> V_34 [ V_29 ] != - 1 )
snprintf ( V_133 [ 3 ] , sizeof( V_133 [ 3 ] ) , L_11 , V_7 -> V_34 [ V_29 ] ) ;
F_114 ( V_115 , L_12 ,
V_132 , V_133 [ 0 ] , V_133 [ 1 ] , V_133 [ 2 ] , V_133 [ 3 ] ) ;
return 0 ;
}
static int F_115 ( struct V_114 * V_115 , void * V_117 )
{
F_98 ( V_115 , F_99 ( F_100 ( V_115 ) ) , F_112 ,
& V_6 , F_101 ( V_115 ) -> V_118 , false ) ;
return 0 ;
}
static T_3 F_116 ( struct V_121 * V_122 ,
char * V_123 , T_4 V_124 , T_5 V_116 )
{
struct V_126 * V_126 = F_99 ( F_106 ( V_122 ) ) ;
struct V_127 V_128 ;
struct V_1 * V_7 ;
T_2 V_117 [ 4 ] ;
int V_101 ;
V_101 = F_107 ( V_126 , & V_6 , V_123 , & V_128 ) ;
if ( V_101 )
return V_101 ;
V_7 = F_3 ( V_128 . V_5 ) ;
V_117 [ 0 ] = V_7 -> V_33 [ V_28 ] ;
V_117 [ 1 ] = V_7 -> V_33 [ V_29 ] ;
V_117 [ 2 ] = V_7 -> V_34 [ V_28 ] ;
V_117 [ 3 ] = V_7 -> V_34 [ V_29 ] ;
while ( true ) {
char V_134 [ 27 ] ;
char * V_135 ;
T_2 V_136 = - 1 ;
int V_137 ;
if ( sscanf ( V_128 . V_130 , L_13 , V_134 , & V_137 ) != 1 )
break;
if ( V_134 [ 0 ] == '\0' )
break;
V_128 . V_130 += V_137 ;
V_101 = - V_129 ;
V_135 = V_134 ;
F_117 ( & V_135 , L_14 ) ;
if ( ! V_135 || ( sscanf ( V_135 , L_9 , & V_136 ) != 1 && strcmp ( V_135 , L_10 ) ) )
goto V_131;
V_101 = - V_138 ;
if ( ! V_136 )
goto V_131;
V_101 = - V_129 ;
if ( ! strcmp ( V_134 , L_15 ) )
V_117 [ 0 ] = V_136 ;
else if ( ! strcmp ( V_134 , L_16 ) )
V_117 [ 1 ] = V_136 ;
else if ( ! strcmp ( V_134 , L_17 ) )
V_117 [ 2 ] = F_118 ( T_2 , V_136 , V_75 ) ;
else if ( ! strcmp ( V_134 , L_18 ) )
V_117 [ 3 ] = F_118 ( T_2 , V_136 , V_75 ) ;
else
goto V_131;
}
V_7 -> V_33 [ V_28 ] = V_117 [ 0 ] ;
V_7 -> V_33 [ V_29 ] = V_117 [ 1 ] ;
V_7 -> V_34 [ V_28 ] = V_117 [ 2 ] ;
V_7 -> V_34 [ V_29 ] = V_117 [ 3 ] ;
F_103 ( V_7 ) ;
V_101 = 0 ;
V_131:
F_109 ( & V_128 ) ;
return V_101 ? : V_124 ;
}
static void F_119 ( struct V_98 * V_35 )
{
struct V_12 * V_13 = V_35 -> V_13 ;
F_120 ( & V_13 -> V_106 ) ;
}
bool F_121 ( struct V_98 * V_35 , struct V_4 * V_5 ,
struct V_18 * V_18 )
{
struct V_14 * V_15 = NULL ;
struct V_1 * V_7 = F_3 ( V_5 ? : V_35 -> V_139 ) ;
struct V_8 * V_9 ;
bool V_27 = F_71 ( V_18 ) ;
bool V_140 = false ;
F_20 ( ! F_122 () ) ;
if ( F_77 ( V_18 , V_84 ) || ! V_7 -> V_39 [ V_27 ] )
goto V_141;
F_86 ( V_35 -> V_102 ) ;
if ( F_123 ( F_124 ( V_35 ) ) )
goto V_104;
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
goto V_104;
}
F_56 ( V_9 , L_19 ,
V_27 == V_28 ? 'R' : 'W' ,
V_7 -> V_58 [ V_27 ] , V_18 -> V_78 . V_79 , V_7 -> V_33 [ V_27 ] ,
V_7 -> V_59 [ V_27 ] , V_7 -> V_34 [ V_27 ] ,
V_9 -> V_83 [ V_28 ] , V_9 -> V_83 [ V_29 ] ) ;
F_125 ( V_18 ) ;
V_7 -> V_13 -> V_83 [ V_27 ] ++ ;
F_79 ( V_18 , V_15 , V_7 ) ;
V_140 = true ;
if ( V_7 -> V_52 & V_85 ) {
F_80 ( V_7 ) ;
F_57 ( V_7 -> V_11 . V_10 , true ) ;
}
V_104:
F_87 ( V_35 -> V_102 ) ;
V_141:
if ( ! V_140 )
F_126 ( V_18 , V_84 ) ;
return V_140 ;
}
static void F_127 ( struct V_8 * V_10 )
{
struct V_1 * V_7 ;
while ( ( V_7 = F_39 ( V_10 ) ) ) {
struct V_8 * V_9 = & V_7 -> V_11 ;
struct V_18 * V_18 ;
F_53 ( V_7 ) ;
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_28 ] ) ) )
F_83 ( V_7 , F_71 ( V_18 ) ) ;
while ( ( V_18 = F_17 ( & V_9 -> V_20 [ V_29 ] ) ) )
F_83 ( V_7 , F_71 ( V_18 ) ) ;
}
}
void F_128 ( struct V_98 * V_35 )
__releases( V_35 -> V_102 ) __acquires( V_35 -> V_102 )
{
struct V_12 * V_13 = V_35 -> V_13 ;
struct V_4 * V_5 ;
struct V_119 * V_120 ;
struct V_18 * V_18 ;
int V_27 ;
F_129 ( V_35 ) ;
F_130 () ;
F_131 (blkg, pos_css, td->queue->root_blkg)
F_127 ( & F_3 ( V_5 ) -> V_11 ) ;
F_127 ( & V_13 -> V_11 ) ;
F_132 () ;
F_87 ( V_35 -> V_102 ) ;
for ( V_27 = V_28 ; V_27 <= V_29 ; V_27 ++ )
while ( ( V_18 = F_21 ( & V_13 -> V_11 . V_20 [ V_27 ] ,
NULL ) ) )
F_92 ( V_18 ) ;
F_86 ( V_35 -> V_102 ) ;
}
int F_133 ( struct V_98 * V_35 )
{
struct V_12 * V_13 ;
int V_101 ;
V_13 = F_30 ( sizeof( * V_13 ) , V_142 , V_35 -> V_16 ) ;
if ( ! V_13 )
return - V_143 ;
F_134 ( & V_13 -> V_106 , F_90 ) ;
F_27 ( & V_13 -> V_11 ) ;
V_35 -> V_13 = V_13 ;
V_13 -> V_99 = V_35 ;
V_101 = F_135 ( V_35 , & V_6 ) ;
if ( V_101 )
F_38 ( V_13 ) ;
return V_101 ;
}
void F_136 ( struct V_98 * V_35 )
{
F_68 ( ! V_35 -> V_13 ) ;
F_119 ( V_35 ) ;
F_137 ( V_35 , & V_6 ) ;
F_38 ( V_35 -> V_13 ) ;
}
static int T_6 F_138 ( void )
{
V_105 = F_139 ( L_20 , V_144 , 0 ) ;
if ( ! V_105 )
F_140 ( L_21 ) ;
return F_141 ( & V_6 ) ;
}
