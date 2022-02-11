static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
void * V_5 ;
F_2 ( V_4 > V_6 ) ;
if ( V_2 -> V_7 >= V_3 )
return 0 ;
while ( V_2 -> V_7 < V_4 ) {
V_5 = ( void * ) F_3 ( V_8 ) ;
if ( ! V_5 )
return - V_9 ;
V_2 -> V_10 [ V_2 -> V_7 ++ ] = V_5 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_11 )
{
while ( V_11 -> V_7 )
F_5 ( ( unsigned long ) V_11 -> V_10 [ -- V_11 -> V_7 ] ) ;
}
static void * F_6 ( struct V_1 * V_11 )
{
void * V_12 ;
F_2 ( ! V_11 || ! V_11 -> V_7 ) ;
V_12 = V_11 -> V_10 [ -- V_11 -> V_7 ] ;
return V_12 ;
}
void F_7 ( struct V_13 * V_14 )
{
F_4 ( & V_14 -> V_15 . V_16 ) ;
}
static void F_8 ( void * V_5 )
{
unsigned long * V_12 , * V_17 ;
unsigned long V_18 ;
#ifdef F_9
V_18 = ( unsigned long ) V_19 ;
#else
V_18 = ( unsigned long ) V_20 ;
#endif
V_12 = ( unsigned long * ) V_5 ;
V_17 = V_12 + V_21 ;
do {
V_12 [ 0 ] = V_18 ;
V_12 [ 1 ] = V_18 ;
V_12 [ 2 ] = V_18 ;
V_12 [ 3 ] = V_18 ;
V_12 [ 4 ] = V_18 ;
V_12 += 8 ;
V_12 [ - 3 ] = V_18 ;
V_12 [ - 2 ] = V_18 ;
V_12 [ - 1 ] = V_18 ;
} while ( V_12 != V_17 );
}
T_1 * F_10 ( void )
{
T_1 * V_22 ;
V_22 = ( T_1 * ) F_11 ( V_8 , V_23 ) ;
if ( V_22 )
F_8 ( V_22 ) ;
return V_22 ;
}
static T_2 * F_12 ( T_1 * V_24 , struct V_1 * V_2 ,
unsigned long V_25 )
{
T_3 * V_26 ;
T_4 * V_27 ;
V_24 += F_13 ( V_25 ) ;
if ( F_14 ( * V_24 ) ) {
F_15 () ;
return NULL ;
}
V_26 = F_16 ( V_24 , V_25 ) ;
if ( F_17 ( * V_26 ) ) {
T_4 * V_28 ;
if ( ! V_2 )
return NULL ;
V_28 = F_6 ( V_2 ) ;
F_18 ( ( unsigned long ) V_28 ,
( unsigned long ) V_19 ) ;
F_19 ( NULL , V_26 , V_28 ) ;
}
V_27 = F_20 ( V_26 , V_25 ) ;
if ( F_21 ( * V_27 ) ) {
T_2 * V_29 ;
if ( ! V_2 )
return NULL ;
V_29 = F_6 ( V_2 ) ;
F_22 ( V_29 ) ;
F_23 ( NULL , V_27 , V_29 ) ;
}
return F_24 ( V_27 , V_25 ) ;
}
static T_2 * F_25 ( struct V_30 * V_30 ,
struct V_1 * V_2 ,
unsigned long V_25 )
{
return F_12 ( V_30 -> V_15 . V_31 . V_24 , V_2 , V_25 ) ;
}
static bool F_26 ( T_2 * V_32 , unsigned long V_33 ,
unsigned long V_34 )
{
int V_35 = F_27 ( V_33 ) ;
int V_36 = F_27 ( V_34 ) ;
bool V_37 = ( V_35 == 0 && V_36 == V_38 - 1 ) ;
int V_39 ;
for ( V_39 = V_35 ; V_39 <= V_36 ; ++ V_39 ) {
if ( ! F_28 ( V_32 [ V_39 ] ) )
continue;
F_29 ( V_32 + V_39 , F_30 ( 0 ) ) ;
}
return V_37 ;
}
static bool F_31 ( T_4 * V_27 , unsigned long V_33 ,
unsigned long V_34 )
{
T_2 * V_32 ;
unsigned long V_17 = ~ 0ul ;
int V_35 = F_32 ( V_33 ) ;
int V_36 = F_32 ( V_34 ) ;
bool V_37 = ( V_35 == 0 && V_36 == V_40 - 1 ) ;
int V_39 ;
for ( V_39 = V_35 ; V_39 <= V_36 ; ++ V_39 , V_33 = 0 ) {
if ( ! F_33 ( V_27 [ V_39 ] ) )
continue;
V_32 = F_24 ( V_27 + V_39 , 0 ) ;
if ( V_39 == V_36 )
V_17 = V_34 ;
if ( F_26 ( V_32 , V_33 , V_17 ) ) {
F_34 ( V_27 + V_39 ) ;
F_35 ( NULL , V_32 ) ;
} else {
V_37 = false ;
}
}
return V_37 ;
}
static bool F_36 ( T_3 * V_26 , unsigned long V_33 ,
unsigned long V_34 )
{
T_4 * V_27 ;
unsigned long V_17 = ~ 0ul ;
int V_35 = F_37 ( V_33 ) ;
int V_36 = F_37 ( V_34 ) ;
bool V_37 = ( V_35 == 0 && V_36 == V_41 - 1 ) ;
int V_39 ;
for ( V_39 = V_35 ; V_39 <= V_36 ; ++ V_39 , V_33 = 0 ) {
if ( ! F_38 ( V_26 [ V_39 ] ) )
continue;
V_27 = F_20 ( V_26 + V_39 , 0 ) ;
if ( V_39 == V_36 )
V_17 = V_34 ;
if ( F_31 ( V_27 , V_33 , V_17 ) ) {
F_39 ( V_26 + V_39 ) ;
F_40 ( NULL , V_27 ) ;
} else {
V_37 = false ;
}
}
return V_37 ;
}
static bool F_41 ( T_1 * V_24 , unsigned long V_33 ,
unsigned long V_34 )
{
T_3 * V_26 ;
unsigned long V_17 = ~ 0ul ;
int V_35 = F_13 ( V_33 ) ;
int V_36 = F_13 ( V_34 ) ;
bool V_37 = ( V_35 == 0 && V_36 == V_21 - 1 ) ;
int V_39 ;
for ( V_39 = V_35 ; V_39 <= V_36 ; ++ V_39 , V_33 = 0 ) {
if ( ! F_42 ( V_24 [ V_39 ] ) )
continue;
V_26 = F_16 ( V_24 + V_39 , 0 ) ;
if ( V_39 == V_36 )
V_17 = V_34 ;
if ( F_36 ( V_26 , V_33 , V_17 ) ) {
F_43 ( V_24 + V_39 ) ;
F_44 ( NULL , V_26 ) ;
} else {
V_37 = false ;
}
}
return V_37 ;
}
bool F_45 ( struct V_30 * V_30 , T_5 V_42 , T_5 V_43 )
{
return F_41 ( V_30 -> V_15 . V_31 . V_24 ,
V_42 << V_44 ,
V_43 << V_44 ) ;
}
int F_46 ( struct V_30 * V_30 , T_5 V_42 , T_5 V_43 )
{
return F_47 ( V_30 -> V_15 . V_31 . V_24 ,
V_42 << V_44 ,
V_43 << V_44 ) ;
}
void F_48 ( struct V_30 * V_30 ,
struct V_45 * V_46 ,
T_5 V_47 , unsigned long V_48 )
{
T_5 V_49 = V_46 -> V_49 + V_47 ;
T_5 V_50 = V_49 + F_49 ( V_48 ) ;
T_5 V_17 = V_49 + F_50 ( V_48 ) ;
F_46 ( V_30 , V_50 , V_17 ) ;
}
static int F_51 ( struct V_30 * V_30 , T_5 V_42 ,
T_5 V_43 )
{
return F_52 ( V_30 -> V_15 . V_31 . V_24 ,
V_42 << V_44 ,
V_43 << V_44 ) ;
}
static int F_53 ( struct V_30 * V_30 ,
unsigned long V_50 ,
unsigned long V_17 ,
int (* F_54)( struct V_30 * V_30 , T_5 V_51 ,
T_6 V_52 ,
struct V_45 * V_53 ,
void * V_54 ) ,
void * V_54 )
{
struct V_55 * V_56 ;
struct V_45 * V_53 ;
int V_22 = 0 ;
V_56 = V_55 ( V_30 ) ;
F_55 (memslot, slots) {
unsigned long V_57 , V_58 ;
T_5 V_51 , V_52 ;
V_57 = V_4 ( V_50 , V_53 -> V_59 ) ;
V_58 = V_3 ( V_17 , V_53 -> V_59 +
( V_53 -> V_60 << V_44 ) ) ;
if ( V_57 >= V_58 )
continue;
V_51 = F_56 ( V_57 , V_53 ) ;
V_52 = F_56 ( V_58 + V_61 - 1 , V_53 ) ;
V_22 |= F_54 ( V_30 , V_51 , V_52 , V_53 , V_54 ) ;
}
return V_22 ;
}
static int F_57 ( struct V_30 * V_30 , T_5 V_51 , T_5 V_52 ,
struct V_45 * V_53 , void * V_54 )
{
F_45 ( V_30 , V_51 , V_52 ) ;
return 1 ;
}
int F_58 ( struct V_30 * V_30 , unsigned long V_62 )
{
unsigned long V_17 = V_62 + V_61 ;
F_53 ( V_30 , V_62 , V_17 , & F_57 , NULL ) ;
V_63 -> V_64 ( V_30 ) ;
return 0 ;
}
int F_59 ( struct V_30 * V_30 , unsigned long V_50 , unsigned long V_17 )
{
F_53 ( V_30 , V_50 , V_17 , & F_57 , NULL ) ;
V_63 -> V_64 ( V_30 ) ;
return 0 ;
}
static int F_60 ( struct V_30 * V_30 , T_5 V_51 , T_5 V_52 ,
struct V_45 * V_53 , void * V_54 )
{
T_6 V_65 = V_51 << V_44 ;
T_2 V_66 = * ( T_2 * ) V_54 ;
T_2 * V_67 = F_25 ( V_30 , NULL , V_65 ) ;
T_2 V_68 ;
if ( ! V_67 )
return 0 ;
V_68 = * V_67 ;
if ( V_53 -> V_69 & V_70 && ! F_61 ( V_68 ) )
V_66 = F_62 ( V_66 ) ;
else if ( V_53 -> V_69 & V_71 )
V_66 = F_63 ( V_66 ) ;
F_29 ( V_67 , V_66 ) ;
if ( ! F_28 ( V_68 ) || ! F_64 ( V_68 ) )
return 0 ;
return ! F_28 ( V_66 ) ||
! F_64 ( V_66 ) ||
F_65 ( V_68 ) != F_65 ( V_66 ) ||
( F_61 ( V_68 ) && ! F_61 ( V_66 ) ) ;
}
void F_66 ( struct V_30 * V_30 , unsigned long V_62 , T_2 V_32 )
{
unsigned long V_17 = V_62 + V_61 ;
int V_22 ;
V_22 = F_53 ( V_30 , V_62 , V_17 , & F_60 , & V_32 ) ;
if ( V_22 )
V_63 -> V_64 ( V_30 ) ;
}
static int F_67 ( struct V_30 * V_30 , T_5 V_51 , T_5 V_52 ,
struct V_45 * V_53 , void * V_54 )
{
return F_51 ( V_30 , V_51 , V_52 ) ;
}
static int F_68 ( struct V_30 * V_30 , T_5 V_51 , T_5 V_52 ,
struct V_45 * V_53 , void * V_54 )
{
T_6 V_65 = V_51 << V_44 ;
T_2 * V_67 = F_25 ( V_30 , NULL , V_65 ) ;
if ( ! V_67 )
return 0 ;
return F_64 ( * V_67 ) ;
}
int F_69 ( struct V_30 * V_30 , unsigned long V_50 , unsigned long V_17 )
{
return F_53 ( V_30 , V_50 , V_17 , F_67 , NULL ) ;
}
int F_70 ( struct V_30 * V_30 , unsigned long V_62 )
{
return F_53 ( V_30 , V_62 , V_62 , F_68 , NULL ) ;
}
static int F_71 ( struct V_13 * V_14 , unsigned long V_65 ,
bool V_72 ,
T_2 * V_73 , T_2 * V_74 )
{
struct V_30 * V_30 = V_14 -> V_30 ;
T_5 V_51 = V_65 >> V_44 ;
T_2 * V_75 ;
T_7 V_76 = 0 ;
bool V_77 = false ;
int V_22 = 0 ;
F_72 ( & V_30 -> V_78 ) ;
V_75 = F_25 ( V_30 , NULL , V_65 ) ;
if ( ! V_75 || ! F_28 ( * V_75 ) ) {
V_22 = - V_79 ;
goto V_80;
}
if ( ! F_64 ( * V_75 ) ) {
F_29 ( V_75 , F_73 ( * V_75 ) ) ;
V_76 = F_65 ( * V_75 ) ;
V_77 = true ;
}
if ( V_72 && ! F_61 ( * V_75 ) ) {
if ( ! F_74 ( * V_75 ) ) {
V_22 = - V_79 ;
goto V_80;
}
F_29 ( V_75 , F_75 ( * V_75 ) ) ;
V_76 = F_65 ( * V_75 ) ;
F_76 ( V_30 , V_51 ) ;
F_77 ( V_76 ) ;
}
if ( V_73 )
* V_73 = * V_75 ;
if ( V_74 )
* V_74 = * F_78 ( V_75 ) ;
V_80:
F_79 ( & V_30 -> V_78 ) ;
if ( V_77 )
F_80 ( V_76 ) ;
return V_22 ;
}
static int F_81 ( struct V_13 * V_14 , unsigned long V_65 ,
bool V_72 ,
T_2 * V_73 , T_2 * V_74 )
{
struct V_30 * V_30 = V_14 -> V_30 ;
struct V_1 * V_81 = & V_14 -> V_15 . V_16 ;
T_5 V_51 = V_65 >> V_44 ;
int V_82 , V_83 ;
T_7 V_76 ;
T_2 * V_75 , V_18 , V_68 ;
bool V_84 ;
unsigned long V_85 ;
unsigned long V_86 ;
V_82 = F_82 ( & V_30 -> V_87 ) ;
V_83 = F_71 ( V_14 , V_65 , V_72 , V_73 ,
V_74 ) ;
if ( ! V_83 )
goto V_80;
V_83 = F_1 ( V_81 , V_88 ,
V_6 ) ;
if ( V_83 )
goto V_80;
V_89:
V_86 = V_30 -> V_90 ;
F_83 () ;
V_76 = F_84 ( V_30 , V_51 , V_72 , & V_84 ) ;
if ( F_85 ( V_76 ) ) {
V_83 = - V_79 ;
goto V_80;
}
F_72 ( & V_30 -> V_78 ) ;
if ( F_86 ( V_30 , V_86 ) ) {
F_79 ( & V_30 -> V_78 ) ;
F_87 ( V_76 ) ;
goto V_89;
}
V_75 = F_25 ( V_30 , V_81 , V_65 ) ;
V_85 = V_91 | V_92 | V_93 ;
if ( V_84 ) {
V_85 |= V_94 ;
if ( V_72 ) {
V_85 |= V_95 ;
F_76 ( V_30 , V_51 ) ;
F_77 ( V_76 ) ;
}
}
V_18 = F_88 ( V_76 , F_89 ( V_85 ) ) ;
V_68 = * V_75 ;
F_29 ( V_75 , V_18 ) ;
V_83 = 0 ;
if ( V_73 )
* V_73 = * V_75 ;
if ( V_74 )
* V_74 = * F_78 ( V_75 ) ;
F_79 ( & V_30 -> V_78 ) ;
F_87 ( V_76 ) ;
F_80 ( V_76 ) ;
V_80:
F_90 ( & V_30 -> V_87 , V_82 ) ;
return V_83 ;
}
static T_2 * F_91 ( struct V_13 * V_14 ,
unsigned long V_25 )
{
struct V_1 * V_81 = & V_14 -> V_15 . V_16 ;
T_1 * V_96 ;
int V_22 ;
V_22 = F_1 ( V_81 , V_88 ,
V_6 ) ;
if ( V_22 )
return NULL ;
if ( F_92 ( V_14 ) )
V_96 = V_14 -> V_15 . V_97 . V_24 ;
else
V_96 = V_14 -> V_15 . V_98 . V_24 ;
return F_12 ( V_96 , V_81 , V_25 ) ;
}
void F_93 ( struct V_13 * V_14 , unsigned long V_25 ,
bool V_99 )
{
T_1 * V_96 ;
T_2 * V_75 ;
V_25 &= V_100 << 1 ;
V_96 = V_14 -> V_15 . V_97 . V_24 ;
V_75 = F_12 ( V_96 , NULL , V_25 ) ;
if ( V_75 ) {
V_75 [ 0 ] = F_88 ( 0 , F_89 ( 0 ) ) ;
V_75 [ 1 ] = F_88 ( 0 , F_89 ( 0 ) ) ;
}
if ( V_99 ) {
V_96 = V_14 -> V_15 . V_98 . V_24 ;
V_75 = F_12 ( V_96 , NULL , V_25 ) ;
if ( V_75 ) {
V_75 [ 0 ] = F_88 ( 0 , F_89 ( 0 ) ) ;
V_75 [ 1 ] = F_88 ( 0 , F_89 ( 0 ) ) ;
}
}
}
static bool F_94 ( T_2 * V_32 , unsigned long V_101 ,
unsigned long V_102 )
{
int V_35 = F_27 ( V_101 ) ;
int V_36 = F_27 ( V_102 ) ;
bool V_37 = ( V_35 == 0 && V_36 == V_38 - 1 ) ;
int V_39 ;
if ( V_37 )
return true ;
for ( V_39 = V_35 ; V_39 <= V_36 ; ++ V_39 ) {
if ( ! F_28 ( V_32 [ V_39 ] ) )
continue;
F_29 ( V_32 + V_39 , F_30 ( 0 ) ) ;
}
return false ;
}
static bool F_95 ( T_4 * V_27 , unsigned long V_101 ,
unsigned long V_102 )
{
T_2 * V_32 ;
unsigned long V_17 = ~ 0ul ;
int V_35 = F_32 ( V_101 ) ;
int V_36 = F_32 ( V_102 ) ;
bool V_37 = ( V_35 == 0 && V_36 == V_40 - 1 ) ;
int V_39 ;
for ( V_39 = V_35 ; V_39 <= V_36 ; ++ V_39 , V_101 = 0 ) {
if ( ! F_33 ( V_27 [ V_39 ] ) )
continue;
V_32 = F_24 ( V_27 + V_39 , 0 ) ;
if ( V_39 == V_36 )
V_17 = V_102 ;
if ( F_94 ( V_32 , V_101 , V_17 ) ) {
F_34 ( V_27 + V_39 ) ;
F_35 ( NULL , V_32 ) ;
} else {
V_37 = false ;
}
}
return V_37 ;
}
static bool F_96 ( T_3 * V_26 , unsigned long V_101 ,
unsigned long V_102 )
{
T_4 * V_27 ;
unsigned long V_17 = ~ 0ul ;
int V_35 = F_37 ( V_101 ) ;
int V_36 = F_37 ( V_102 ) ;
bool V_37 = ( V_35 == 0 && V_36 == V_41 - 1 ) ;
int V_39 ;
for ( V_39 = V_35 ; V_39 <= V_36 ; ++ V_39 , V_101 = 0 ) {
if ( ! F_38 ( V_26 [ V_39 ] ) )
continue;
V_27 = F_20 ( V_26 + V_39 , 0 ) ;
if ( V_39 == V_36 )
V_17 = V_102 ;
if ( F_95 ( V_27 , V_101 , V_17 ) ) {
F_39 ( V_26 + V_39 ) ;
F_40 ( NULL , V_27 ) ;
} else {
V_37 = false ;
}
}
return V_37 ;
}
static bool F_97 ( T_1 * V_24 , unsigned long V_101 ,
unsigned long V_102 )
{
T_3 * V_26 ;
unsigned long V_17 = ~ 0ul ;
int V_35 = F_13 ( V_101 ) ;
int V_36 = F_13 ( V_102 ) ;
bool V_37 = ( V_35 == 0 && V_36 == V_21 - 1 ) ;
int V_39 ;
for ( V_39 = V_35 ; V_39 <= V_36 ; ++ V_39 , V_101 = 0 ) {
if ( ! F_42 ( V_24 [ V_39 ] ) )
continue;
V_26 = F_16 ( V_24 + V_39 , 0 ) ;
if ( V_39 == V_36 )
V_17 = V_102 ;
if ( F_96 ( V_26 , V_101 , V_17 ) ) {
F_43 ( V_24 + V_39 ) ;
F_44 ( NULL , V_26 ) ;
} else {
V_37 = false ;
}
}
return V_37 ;
}
void F_98 ( T_1 * V_24 , enum V_103 V_69 )
{
if ( V_69 & V_104 ) {
if ( V_69 & V_105 )
F_97 ( V_24 , 0 , 0x7fffffff ) ;
else
F_97 ( V_24 , 0 , 0x3fffffff ) ;
} else {
F_97 ( V_24 , 0 , 0x3fffffff ) ;
if ( V_69 & V_105 )
F_97 ( V_24 , 0x60000000 , 0x7fffffff ) ;
}
}
static T_2 F_99 ( T_2 V_32 )
{
if ( ! F_61 ( V_32 ) )
V_32 = F_63 ( V_32 ) ;
return V_32 ;
}
static T_2 F_100 ( T_2 V_32 , long V_106 )
{
if ( ! ( V_106 & V_107 ) )
V_32 = F_62 ( V_32 ) ;
return F_99 ( V_32 ) ;
}
int F_101 ( unsigned long V_108 ,
struct V_13 * V_14 ,
bool V_72 )
{
int V_22 ;
V_22 = F_81 ( V_14 , V_108 , V_72 , NULL , NULL ) ;
if ( V_22 )
return V_22 ;
return F_102 ( V_14 , V_108 ) ;
}
int F_103 ( unsigned long V_108 ,
struct V_13 * V_14 ,
bool V_72 )
{
unsigned long V_65 ;
T_2 V_109 [ 2 ] , * V_110 ;
int V_111 ;
if ( F_104 ( V_108 ) != V_112 ) {
F_105 ( L_1 , V_113 , V_108 ) ;
F_106 () ;
return - 1 ;
}
V_65 = F_107 ( V_108 ) ;
V_111 = ( V_108 >> V_44 ) & 1 ;
if ( F_81 ( V_14 , V_65 , V_72 , & V_109 [ V_111 ] ,
& V_109 [ ! V_111 ] ) < 0 )
return - 1 ;
V_110 = F_91 ( V_14 , V_108 & ~ V_61 ) ;
if ( ! V_110 ) {
F_105 ( L_2 , V_108 ) ;
return - 1 ;
}
V_110 [ 0 ] = F_99 ( V_109 [ 0 ] ) ;
V_110 [ 1 ] = F_99 ( V_109 [ 1 ] ) ;
F_108 ( V_14 , V_108 , false , true ) ;
return 0 ;
}
int F_109 ( struct V_13 * V_14 ,
struct V_114 * V_115 ,
unsigned long V_116 ,
bool V_72 )
{
struct V_30 * V_30 = V_14 -> V_30 ;
long V_117 [ 2 ] ;
T_2 V_109 [ 2 ] , * F_78 , * V_110 ;
unsigned int V_111 = F_110 ( * V_115 , V_116 ) ;
bool V_118 = F_92 ( V_14 ) ;
V_117 [ 0 ] = V_115 -> V_117 [ 0 ] ;
V_117 [ 1 ] = V_115 -> V_117 [ 1 ] ;
if ( ! ( ( V_116 ^ V_119 ) & V_120 & ( V_100 << 1 ) ) )
V_117 [ F_110 ( * V_115 , V_119 ) ] = 0 ;
if ( F_81 ( V_14 , F_111 ( V_117 [ V_111 ] ) ,
V_72 , & V_109 [ V_111 ] , NULL ) < 0 )
return - 1 ;
V_109 [ ! V_111 ] = F_88 ( 0 , F_89 ( 0 ) ) ;
if ( V_117 [ ! V_111 ] & V_121 ) {
F_72 ( & V_30 -> V_78 ) ;
F_78 = F_25 ( V_30 , NULL ,
F_111 ( V_117 [ ! V_111 ] ) ) ;
if ( F_78 )
V_109 [ ! V_111 ] = * F_78 ;
F_79 ( & V_30 -> V_78 ) ;
}
V_110 = F_91 ( V_14 , V_116 & ~ V_61 ) ;
if ( ! V_110 ) {
F_105 ( L_2 , V_116 ) ;
return - 1 ;
}
V_110 [ 0 ] = F_100 ( V_109 [ 0 ] , V_117 [ 0 ] ) ;
V_110 [ 1 ] = F_100 ( V_109 [ 1 ] , V_117 [ 1 ] ) ;
F_108 ( V_14 , V_116 , ! V_118 , V_118 ) ;
F_112 ( L_3 , V_14 -> V_15 . V_122 ,
V_115 -> V_117 [ 0 ] , V_115 -> V_117 [ 1 ] ) ;
return 0 ;
}
int F_113 ( unsigned long V_108 ,
struct V_13 * V_14 )
{
T_7 V_76 ;
T_2 * V_75 ;
V_75 = F_91 ( V_14 , V_108 ) ;
if ( ! V_75 ) {
F_105 ( L_4 , V_108 ) ;
return - 1 ;
}
V_76 = F_114 ( F_115 ( V_14 -> V_15 . V_123 ) ) ;
* V_75 = F_73 ( F_75 ( F_88 ( V_76 , V_124 ) ) ) ;
F_108 ( V_14 , V_108 , false , true ) ;
return 0 ;
}
static void F_116 ( struct V_13 * V_14 )
{
if ( F_117 ( & V_14 -> V_15 . V_125 ) )
F_118 ( & V_14 -> V_15 . V_125 ) ;
}
void F_119 ( struct V_13 * V_14 , int V_126 )
{
unsigned long V_69 ;
F_112 ( L_5 , V_113 , V_14 , V_126 ) ;
F_120 ( V_69 ) ;
V_14 -> V_126 = V_126 ;
if ( V_14 -> V_15 . V_127 != V_126 ) {
F_112 ( L_6 ,
V_14 -> V_15 . V_127 , V_126 , V_14 -> V_128 ) ;
F_116 ( V_14 ) ;
}
V_63 -> V_129 ( V_14 , V_126 ) ;
F_121 ( V_69 ) ;
}
void F_122 ( struct V_13 * V_14 )
{
unsigned long V_69 ;
int V_126 ;
F_120 ( V_69 ) ;
V_126 = F_123 () ;
V_14 -> V_15 . V_127 = V_126 ;
V_14 -> V_126 = - 1 ;
V_63 -> V_130 ( V_14 , V_126 ) ;
F_121 ( V_69 ) ;
}
enum V_131 F_124 ( struct V_13 * V_14 ,
unsigned long V_116 ,
bool V_132 )
{
struct V_133 * V_134 = V_14 -> V_15 . V_134 ;
struct V_114 * V_115 ;
int V_135 ;
if ( F_104 ( V_116 ) == V_112 ) {
if ( F_103 ( V_116 , V_14 , V_132 ) < 0 )
return V_136 ;
} else if ( ( F_104 ( V_116 ) < V_112 ) ||
F_104 ( V_116 ) == V_137 ) {
V_135 = F_125 ( V_14 , ( V_116 & V_120 ) |
( F_126 ( V_134 ) & V_138 ) ) ;
if ( V_135 < 0 )
return V_139 ;
V_115 = & V_14 -> V_15 . V_140 [ V_135 ] ;
if ( ! F_127 ( * V_115 , V_116 ) )
return V_141 ;
if ( V_132 && ! F_128 ( * V_115 , V_116 ) )
return V_142 ;
if ( F_109 ( V_14 , V_115 , V_116 , V_132 ) )
return V_136 ;
} else {
return V_143 ;
}
return V_144 ;
}
int F_129 ( T_8 * V_145 , struct V_13 * V_14 , T_8 * V_80 )
{
int V_83 ;
if ( F_130 ( F_131 ( V_146 ) ,
L_7 ) )
return - V_147 ;
V_89:
F_132 ( V_14 ) ;
V_83 = F_133 ( * V_80 , V_145 ) ;
F_134 ( V_14 ) ;
if ( F_135 ( V_83 ) ) {
V_83 = F_124 ( V_14 , ( unsigned long ) V_145 ,
false ) ;
if ( F_135 ( V_83 ) ) {
F_105 ( L_8 ,
V_113 , V_145 ) ;
return - V_79 ;
}
goto V_89;
}
return 0 ;
}
