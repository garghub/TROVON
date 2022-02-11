static void F_1 ( void )
{
if ( V_1 )
F_2 ( & V_2 ) ;
}
static bool F_3 ( void * V_3 )
{
void * V_4 = V_5 -> V_6 ;
return V_3 >= V_4 && V_3 < V_4 + V_7 ;
}
static bool F_4 ( void * V_3 )
{
void * V_4 = V_5 -> V_6 ;
return V_3 >= V_4 &&
V_3 < V_4 + V_8 ;
}
static int F_5 ( int V_9 )
{
int V_10 = F_6 ( V_9 ) ;
return F_7 ( V_10 - V_11 + 2 , 1 ) ;
}
static int F_8 ( int V_9 )
{
if ( V_9 == V_7 )
return V_12 - 1 ;
return F_5 ( V_9 ) ;
}
static int F_9 ( const struct V_13 * V_14 )
{
if ( V_14 -> V_15 < sizeof( int ) || V_14 -> V_16 < sizeof( int ) )
return 0 ;
return F_8 ( V_14 -> V_15 ) ;
}
static void F_10 ( struct V_17 * V_17 , struct V_13 * V_18 )
{
V_17 -> V_19 = ( unsigned long ) V_18 ;
}
static struct V_13 * F_11 ( struct V_17 * V_17 )
{
return (struct V_13 * ) V_17 -> V_19 ;
}
static int T_1 F_12 ( unsigned int V_20 , int V_21 )
{
return V_22 [ V_20 ] * V_23 + V_21 ;
}
static unsigned long F_13 ( struct V_13 * V_14 ,
unsigned int V_20 , int V_21 )
{
return ( unsigned long ) V_14 -> V_6 + V_24 [ V_20 ] +
( V_21 << V_25 ) ;
}
static void T_1 F_14 ( struct V_13 * V_14 ,
int * V_26 , int * V_27 , int V_28 )
{
* V_26 = F_15 ( V_14 -> V_29 , V_28 , * V_26 ) ;
* V_27 = F_16 ( V_14 -> V_29 , V_28 , * V_26 + 1 ) ;
}
static void T_1 F_17 ( struct V_13 * V_14 ,
int * V_26 , int * V_27 , int V_28 )
{
* V_26 = F_16 ( V_14 -> V_29 , V_28 , * V_26 ) ;
* V_27 = F_15 ( V_14 -> V_29 , V_28 , * V_26 + 1 ) ;
}
static void * F_18 ( T_2 V_9 )
{
if ( F_19 ( ! F_20 () ) )
return NULL ;
if ( V_9 <= V_30 )
return F_21 ( V_9 , V_31 ) ;
else
return F_22 ( V_9 ) ;
}
static void F_23 ( void * V_32 )
{
F_24 ( V_32 ) ;
}
static int F_25 ( struct V_13 * V_14 , int V_33 )
{
int V_34 = V_14 -> V_35 [ V_33 ] & ~ 1 ;
int V_28 = V_14 -> V_35 [ V_33 + 1 ] & ~ 1 ;
if ( ! F_26 ( V_34 ) && V_33 > 0 ) {
int V_36 = V_14 -> V_35 [ V_33 - 1 ] ;
if ( ! ( V_36 & 1 ) && V_36 <= F_27 ( V_34 , V_30 ) )
V_34 = F_27 ( V_34 , V_30 ) ;
}
if ( ! F_26 ( V_28 ) && V_33 + 1 < V_14 -> V_37 ) {
int V_38 = V_14 -> V_35 [ V_33 + 1 ] ;
int V_39 = V_14 -> V_35 [ V_33 + 2 ] & ~ 1 ;
if ( ! ( V_38 & 1 ) && V_39 >= F_28 ( V_28 , V_30 ) )
V_28 = F_28 ( V_28 , V_30 ) ;
}
return F_29 ( int , F_30 ( V_28 ) - F_31 ( V_34 ) , 0 ) ;
}
static void F_32 ( struct V_13 * V_14 , int V_40 )
{
int V_41 = F_9 ( V_14 ) ;
if ( V_14 != V_42 && V_40 != V_41 ) {
if ( V_40 < V_41 )
F_33 ( & V_14 -> V_43 , & V_44 [ V_41 ] ) ;
else
F_34 ( & V_14 -> V_43 , & V_44 [ V_41 ] ) ;
}
}
static int F_35 ( struct V_13 * V_14 , bool V_45 )
{
int V_46 , V_47 ;
F_36 ( & V_48 ) ;
if ( V_45 ) {
V_46 = 3 ;
if ( V_14 -> V_49 <
V_14 -> V_37 + V_50 ) {
if ( F_37 ( & V_14 -> V_51 ) ) {
F_38 ( & V_14 -> V_51 ,
& V_52 ) ;
F_1 () ;
}
}
} else {
V_46 = V_53 ;
}
if ( V_14 -> V_49 >= V_14 -> V_37 + V_46 )
return 0 ;
V_47 = V_54 ;
while ( V_47 < V_14 -> V_37 + V_46 )
V_47 *= 2 ;
return V_47 ;
}
static int F_39 ( struct V_13 * V_14 , int V_47 )
{
int * V_55 = NULL , * V_56 = NULL ;
T_2 V_57 = 0 , V_58 = V_47 * sizeof( V_56 [ 0 ] ) ;
unsigned long V_59 ;
F_36 ( & V_60 ) ;
V_56 = F_18 ( V_58 ) ;
if ( ! V_56 )
return - V_61 ;
F_40 ( & V_48 , V_59 ) ;
if ( V_47 <= V_14 -> V_49 )
goto V_62;
V_57 = V_14 -> V_49 * sizeof( V_14 -> V_35 [ 0 ] ) ;
V_55 = V_14 -> V_35 ;
memcpy ( V_56 , V_55 , V_57 ) ;
V_14 -> V_49 = V_47 ;
V_14 -> V_35 = V_56 ;
V_56 = NULL ;
V_62:
F_41 ( & V_48 , V_59 ) ;
F_23 ( V_55 ) ;
F_23 ( V_56 ) ;
return 0 ;
}
static int F_42 ( struct V_13 * V_14 , int V_34 , int V_63 ,
int V_9 , int V_64 , bool V_65 )
{
int V_66 = V_34 ;
while ( true ) {
int V_67 = F_43 ( V_66 , V_64 ) - V_34 ;
int V_68 , V_69 , V_26 , V_27 ;
if ( V_63 < V_67 + V_9 )
return - 1 ;
if ( ! V_65 )
return V_67 ;
V_68 = F_30 ( V_67 + V_34 ) ;
V_69 = F_31 ( V_67 + V_34 + V_9 ) ;
V_26 = V_68 ;
F_14 ( V_14 , & V_26 , & V_27 , F_31 ( V_34 + V_63 ) ) ;
if ( V_26 >= V_69 )
return V_67 ;
V_66 = V_27 * V_30 ;
}
}
static int F_44 ( struct V_13 * V_14 , int V_9 , int V_64 ,
bool V_65 , int * V_70 )
{
int V_40 = F_9 ( V_14 ) ;
int V_71 = 0 ;
int V_33 , V_34 ;
bool V_72 = false ;
int * V_73 ;
for ( V_33 = V_14 -> V_74 , V_73 = V_14 -> V_35 + V_33 ; V_33 < V_14 -> V_37 ; V_33 ++ , V_73 ++ ) {
int V_67 , V_75 ;
int V_63 ;
V_34 = * V_73 ;
if ( V_34 & 1 )
continue;
V_63 = ( V_73 [ 1 ] & ~ 1 ) - V_34 ;
V_67 = F_42 ( V_14 , V_34 , V_63 , V_9 , V_64 ,
V_65 ) ;
if ( V_67 < 0 ) {
if ( ! V_72 ) {
V_14 -> V_74 = V_33 ;
V_72 = true ;
}
V_71 = F_7 ( V_63 , V_71 ) ;
continue;
}
if ( V_67 && ( V_67 < sizeof( int ) || ! ( V_73 [ - 1 ] & 1 ) ) ) {
* V_73 = V_34 += V_67 ;
if ( V_73 [ - 1 ] & 1 )
V_14 -> V_15 -= V_67 ;
else
V_71 = F_7 ( * V_73 - V_73 [ - 1 ] , V_71 ) ;
V_63 -= V_67 ;
V_67 = 0 ;
}
V_75 = V_63 - V_67 - V_9 ;
if ( V_75 < sizeof( int ) ) {
V_75 = 0 ;
V_9 = V_63 - V_67 ;
}
if ( V_67 || V_75 ) {
int V_76 = ! ! V_67 + ! ! V_75 ;
memmove ( V_73 + V_76 + 1 , V_73 + 1 ,
sizeof( V_14 -> V_35 [ 0 ] ) * ( V_14 -> V_37 - V_33 ) ) ;
V_14 -> V_37 += V_76 ;
if ( V_67 ) {
if ( ! V_72 ) {
V_14 -> V_74 = V_33 ;
V_72 = true ;
}
* ++ V_73 = V_34 += V_67 ;
++ V_33 ;
V_71 = F_7 ( V_67 , V_71 ) ;
}
if ( V_75 ) {
V_73 [ 1 ] = V_34 + V_9 ;
V_71 = F_7 ( V_75 , V_71 ) ;
}
}
if ( ! V_72 )
V_14 -> V_74 = V_33 + 1 ;
if ( V_33 + 1 == V_14 -> V_37 )
V_14 -> V_16 = V_71 ;
else
V_14 -> V_16 = F_7 ( V_14 -> V_16 ,
V_71 ) ;
V_14 -> V_15 -= V_9 ;
* V_73 |= 1 ;
* V_70 = F_25 ( V_14 , V_33 ) ;
F_32 ( V_14 , V_40 ) ;
return V_34 ;
}
V_14 -> V_16 = V_71 ;
F_32 ( V_14 , V_40 ) ;
return - 1 ;
}
static void F_45 ( struct V_13 * V_14 , int V_77 ,
int * V_70 )
{
int V_40 = F_9 ( V_14 ) ;
int V_34 = 0 ;
unsigned V_33 , V_78 ;
int V_79 = 0 ;
int * V_73 ;
V_77 |= 1 ;
V_33 = 0 ;
V_78 = V_14 -> V_37 ;
while ( V_33 != V_78 ) {
unsigned V_80 = ( V_33 + V_78 ) / 2 ;
V_34 = V_14 -> V_35 [ V_80 ] ;
if ( V_34 < V_77 )
V_33 = V_80 + 1 ;
else if ( V_34 > V_77 )
V_78 = V_80 ;
else
V_33 = V_78 = V_80 ;
}
F_46 ( V_34 != V_77 ) ;
if ( V_33 < V_14 -> V_74 )
V_14 -> V_74 = V_33 ;
V_73 = V_14 -> V_35 + V_33 ;
* V_73 = V_34 &= ~ 1 ;
V_14 -> V_15 += ( V_73 [ 1 ] & ~ 1 ) - V_34 ;
* V_70 = F_25 ( V_14 , V_33 ) ;
if ( ! ( V_73 [ 1 ] & 1 ) )
V_79 ++ ;
if ( V_33 > 0 && ! ( V_73 [ - 1 ] & 1 ) ) {
V_79 ++ ;
V_33 -- ;
V_73 -- ;
}
if ( V_79 ) {
V_14 -> V_37 -= V_79 ;
memmove ( V_73 + 1 , V_73 + 1 + V_79 ,
( V_14 -> V_37 - V_33 ) * sizeof( V_14 -> V_35 [ 0 ] ) ) ;
}
V_14 -> V_16 = F_7 ( V_14 -> V_35 [ V_33 + 1 ] - V_14 -> V_35 [ V_33 ] - 1 , V_14 -> V_16 ) ;
F_32 ( V_14 , V_40 ) ;
}
static struct V_13 * F_47 ( void )
{
struct V_13 * V_14 ;
V_14 = F_18 ( V_81 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_35 = F_18 ( V_54 *
sizeof( V_14 -> V_35 [ 0 ] ) ) ;
if ( ! V_14 -> V_35 ) {
F_23 ( V_14 ) ;
return NULL ;
}
V_14 -> V_49 = V_54 ;
V_14 -> V_35 [ 0 ] = 0 ;
V_14 -> V_35 [ 1 ] = V_7 | 1 ;
V_14 -> V_37 = 1 ;
F_48 ( & V_14 -> V_43 ) ;
F_48 ( & V_14 -> V_51 ) ;
V_14 -> V_15 = V_7 ;
V_14 -> V_16 = V_7 ;
return V_14 ;
}
static void F_49 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return;
F_23 ( V_14 -> V_35 ) ;
F_23 ( V_14 ) ;
}
static void F_50 ( struct V_13 * V_14 ,
int V_68 , int V_69 )
{
int V_82 = V_69 - V_68 ;
F_36 ( & V_48 ) ;
F_51 ( V_14 -> V_29 , V_68 , V_82 ) ;
V_14 -> V_83 += V_82 ;
V_84 += V_82 ;
}
static void F_52 ( struct V_13 * V_14 ,
int V_68 , int V_69 )
{
int V_82 = V_69 - V_68 ;
F_36 ( & V_48 ) ;
F_53 ( V_14 -> V_29 , V_68 , V_82 ) ;
V_14 -> V_83 -= V_82 ;
V_84 -= V_82 ;
}
static struct V_13 * F_54 ( void * V_3 )
{
if ( F_3 ( V_3 ) ) {
if ( F_4 ( V_3 ) )
return V_42 ;
return V_5 ;
}
V_3 += V_24 [ F_55 () ] ;
return F_11 ( F_56 ( V_3 ) ) ;
}
static void T_3 * F_57 ( T_2 V_9 , T_2 V_64 , bool V_85 ,
T_4 V_86 )
{
static int V_87 = 10 ;
struct V_13 * V_14 ;
const char * V_88 ;
bool V_45 = ( V_86 & V_31 ) != V_31 ;
int V_89 = 0 ;
int V_90 , V_34 , V_47 , V_20 , V_91 ;
unsigned long V_59 ;
void T_3 * V_32 ;
if ( F_58 ( V_64 < 2 ) )
V_64 = 2 ;
V_9 = F_43 ( V_9 , 2 ) ;
if ( F_58 ( ! V_9 || V_9 > V_92 || V_64 > V_30 ) ) {
F_59 ( true , L_1 ,
V_9 , V_64 ) ;
return NULL ;
}
if ( ! V_45 )
F_60 ( & V_60 ) ;
F_40 ( & V_48 , V_59 ) ;
if ( V_85 && V_42 ) {
V_14 = V_42 ;
if ( V_9 > V_14 -> V_16 ) {
V_88 = L_2 ;
goto V_93;
}
while ( ( V_47 = F_35 ( V_14 , V_45 ) ) ) {
F_41 ( & V_48 , V_59 ) ;
if ( V_45 ||
F_39 ( V_14 , V_47 ) < 0 ) {
V_88 = L_3 ;
goto V_94;
}
F_40 ( & V_48 , V_59 ) ;
}
V_34 = F_44 ( V_14 , V_9 , V_64 , V_45 ,
& V_89 ) ;
if ( V_34 >= 0 )
goto V_95;
V_88 = L_2 ;
goto V_93;
}
V_96:
for ( V_90 = F_8 ( V_9 ) ; V_90 < V_12 ; V_90 ++ ) {
F_61 (chunk, &pcpu_slot[slot], list) {
if ( V_9 > V_14 -> V_16 )
continue;
V_47 = F_35 ( V_14 , V_45 ) ;
if ( V_47 ) {
if ( V_45 )
continue;
F_41 ( & V_48 , V_59 ) ;
if ( F_39 ( V_14 ,
V_47 ) < 0 ) {
V_88 = L_4 ;
goto V_94;
}
F_40 ( & V_48 , V_59 ) ;
goto V_96;
}
V_34 = F_44 ( V_14 , V_9 , V_64 , V_45 ,
& V_89 ) ;
if ( V_34 >= 0 )
goto V_95;
}
}
F_41 ( & V_48 , V_59 ) ;
if ( V_45 )
goto V_94;
if ( F_37 ( & V_44 [ V_12 - 1 ] ) ) {
V_14 = F_62 () ;
if ( ! V_14 ) {
V_88 = L_5 ;
goto V_94;
}
F_40 ( & V_48 , V_59 ) ;
F_32 ( V_14 , - 1 ) ;
} else {
F_40 ( & V_48 , V_59 ) ;
}
goto V_96;
V_95:
F_41 ( & V_48 , V_59 ) ;
if ( ! V_45 ) {
int V_68 , V_69 , V_26 , V_27 ;
V_68 = F_30 ( V_34 ) ;
V_69 = F_31 ( V_34 + V_9 ) ;
F_63 (chunk, rs, re, page_start, page_end) {
F_64 ( V_14 -> V_97 ) ;
V_91 = F_65 ( V_14 , V_26 , V_27 ) ;
F_40 ( & V_48 , V_59 ) ;
if ( V_91 ) {
F_45 ( V_14 , V_34 , & V_89 ) ;
V_88 = L_6 ;
goto V_93;
}
F_50 ( V_14 , V_26 , V_27 ) ;
F_41 ( & V_48 , V_59 ) ;
}
F_66 ( & V_60 ) ;
}
if ( V_14 != V_42 )
V_84 -= V_89 ;
if ( V_84 < V_98 )
F_1 () ;
F_67 (cpu)
memset ( ( void * ) F_13 ( V_14 , V_20 , 0 ) + V_34 , 0 , V_9 ) ;
V_32 = F_68 ( V_14 -> V_6 + V_34 ) ;
F_69 ( V_32 , V_9 , V_86 ) ;
return V_32 ;
V_93:
F_41 ( & V_48 , V_59 ) ;
V_94:
if ( ! V_45 && V_87 ) {
F_70 ( L_7 ,
V_9 , V_64 , V_45 , V_88 ) ;
F_71 () ;
if ( ! -- V_87 )
F_72 ( L_8 ) ;
}
if ( V_45 ) {
V_99 = true ;
F_1 () ;
} else {
F_66 ( & V_60 ) ;
}
return NULL ;
}
void T_3 * F_73 ( T_2 V_9 , T_2 V_64 , T_4 V_86 )
{
return F_57 ( V_9 , V_64 , false , V_86 ) ;
}
void T_3 * F_74 ( T_2 V_9 , T_2 V_64 )
{
return F_57 ( V_9 , V_64 , false , V_31 ) ;
}
void T_3 * F_75 ( T_2 V_9 , T_2 V_64 )
{
return F_57 ( V_9 , V_64 , true , V_31 ) ;
}
static void F_76 ( struct V_100 * V_101 )
{
F_77 ( V_79 ) ;
struct V_102 * V_103 = & V_44 [ V_12 - 1 ] ;
struct V_13 * V_14 , * V_38 ;
int V_90 , V_104 , V_91 ;
F_60 ( & V_60 ) ;
F_78 ( & V_48 ) ;
F_79 (chunk, next, free_head, list) {
F_64 ( V_14 -> V_97 ) ;
if ( V_14 == F_80 ( V_103 , struct V_13 , V_43 ) )
continue;
F_81 ( & V_14 -> V_51 ) ;
F_33 ( & V_14 -> V_43 , & V_79 ) ;
}
F_82 ( & V_48 ) ;
F_79 (chunk, next, &to_free, list) {
int V_26 , V_27 ;
F_83 (chunk, rs, re, 0 , pcpu_unit_pages) {
F_84 ( V_14 , V_26 , V_27 ) ;
F_78 ( & V_48 ) ;
F_52 ( V_14 , V_26 , V_27 ) ;
F_82 ( & V_48 ) ;
}
F_85 ( V_14 ) ;
}
do {
int V_47 = 0 ;
F_78 ( & V_48 ) ;
V_14 = F_86 ( & V_52 ,
struct V_13 , V_51 ) ;
if ( V_14 ) {
F_81 ( & V_14 -> V_51 ) ;
V_47 = F_35 ( V_14 , false ) ;
}
F_82 ( & V_48 ) ;
if ( V_47 )
F_39 ( V_14 , V_47 ) ;
} while ( V_14 );
V_105:
if ( V_99 ) {
V_104 = V_106 ;
V_99 = false ;
} else {
V_104 = F_87 ( V_106 -
V_84 ,
0 , V_106 ) ;
}
for ( V_90 = F_8 ( V_30 ) ; V_90 < V_12 ; V_90 ++ ) {
int V_107 = 0 , V_26 , V_27 ;
if ( ! V_104 )
break;
F_78 ( & V_48 ) ;
F_61 (chunk, &pcpu_slot[slot], list) {
V_107 = V_23 - V_14 -> V_83 ;
if ( V_107 )
break;
}
F_82 ( & V_48 ) ;
if ( ! V_107 )
continue;
F_63 (chunk, rs, re, 0 , pcpu_unit_pages) {
int V_82 = F_88 ( V_27 - V_26 , V_104 ) ;
V_91 = F_65 ( V_14 , V_26 , V_26 + V_82 ) ;
if ( ! V_91 ) {
V_104 -= V_82 ;
F_78 ( & V_48 ) ;
F_50 ( V_14 , V_26 , V_26 + V_82 ) ;
F_82 ( & V_48 ) ;
} else {
V_104 = 0 ;
}
if ( ! V_104 )
break;
}
}
if ( V_104 ) {
V_14 = F_62 () ;
if ( V_14 ) {
F_78 ( & V_48 ) ;
F_32 ( V_14 , - 1 ) ;
F_82 ( & V_48 ) ;
goto V_105;
}
}
F_66 ( & V_60 ) ;
}
void F_89 ( void T_3 * V_32 )
{
void * V_3 ;
struct V_13 * V_14 ;
unsigned long V_59 ;
int V_34 , V_89 ;
if ( ! V_32 )
return;
F_90 ( V_32 ) ;
V_3 = F_91 ( V_32 ) ;
F_40 ( & V_48 , V_59 ) ;
V_14 = F_54 ( V_3 ) ;
V_34 = V_3 - V_14 -> V_6 ;
F_45 ( V_14 , V_34 , & V_89 ) ;
if ( V_14 != V_42 )
V_84 += V_89 ;
if ( V_14 -> V_15 == V_7 ) {
struct V_13 * V_108 ;
F_61 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_108 != V_14 ) {
F_1 () ;
break;
}
}
F_41 ( & V_48 , V_59 ) ;
}
bool F_92 ( unsigned long V_3 )
{
#ifdef F_93
const T_2 V_109 = V_110 - V_111 ;
void T_3 * V_112 = F_68 ( V_113 ) ;
unsigned int V_20 ;
F_67 (cpu) {
void * V_114 = F_94 ( V_112 , V_20 ) ;
if ( ( void * ) V_3 >= V_114 && ( void * ) V_3 < V_114 + V_109 )
return true ;
}
#endif
return false ;
}
T_5 F_95 ( void * V_3 )
{
void T_3 * V_112 = F_68 ( V_113 ) ;
bool V_115 = false ;
unsigned long V_116 , V_117 ;
unsigned int V_20 ;
V_116 = F_13 ( V_5 , V_118 , 0 ) ;
V_117 = F_13 ( V_5 , V_119 ,
V_23 ) ;
if ( ( unsigned long ) V_3 >= V_116 &&
( unsigned long ) V_3 < V_117 ) {
F_67 (cpu) {
void * V_114 = F_94 ( V_112 , V_20 ) ;
if ( V_3 >= V_114 && V_3 < V_114 + V_7 ) {
V_115 = true ;
break;
}
}
}
if ( V_115 ) {
if ( ! F_96 ( V_3 ) )
return F_97 ( V_3 ) ;
else
return F_98 ( F_99 ( V_3 ) ) +
F_100 ( V_3 ) ;
} else
return F_98 ( F_56 ( V_3 ) ) +
F_100 ( V_3 ) ;
}
struct V_120 * T_6 F_101 ( int V_121 ,
int V_122 )
{
struct V_120 * V_123 ;
T_2 V_124 , V_125 ;
void * V_32 ;
int V_126 ;
V_124 = F_43 ( sizeof( * V_123 ) + V_121 * sizeof( V_123 -> V_127 [ 0 ] ) ,
F_102 ( V_123 -> V_127 [ 0 ] . V_128 [ 0 ] ) ) ;
V_125 = V_124 + V_122 * sizeof( V_123 -> V_127 [ 0 ] . V_128 [ 0 ] ) ;
V_32 = F_103 ( F_104 ( V_125 ) , 0 ) ;
if ( ! V_32 )
return NULL ;
V_123 = V_32 ;
V_32 += V_124 ;
V_123 -> V_127 [ 0 ] . V_128 = V_32 ;
for ( V_126 = 0 ; V_126 < V_122 ; V_126 ++ )
V_123 -> V_127 [ 0 ] . V_128 [ V_126 ] = V_129 ;
V_123 -> V_121 = V_121 ;
V_123 -> V_130 = F_104 ( V_125 ) ;
return V_123 ;
}
void T_6 F_105 ( struct V_120 * V_123 )
{
F_106 ( F_97 ( V_123 ) , V_123 -> V_130 ) ;
}
static void F_107 ( const char * V_131 ,
const struct V_120 * V_123 )
{
int V_132 = 1 , V_133 = 1 , V_134 ;
char V_135 [] = L_9 ;
int V_136 = 0 , V_137 = 0 ;
int V_138 , V_139 ;
int V_140 , V_141 ;
V_139 = V_123 -> V_121 ;
while ( V_139 /= 10 )
V_132 ++ ;
V_139 = F_108 () ;
while ( V_139 /= 10 )
V_133 ++ ;
V_135 [ F_109 ( int , V_133 , sizeof( V_135 ) - 1 ) ] = '\0' ;
V_140 = V_123 -> V_142 / V_123 -> V_143 ;
V_134 = V_140 * ( V_133 + 1 ) + V_132 + 3 ;
V_141 = F_110 ( F_7 ( 60 / V_134 , 1 ) ) ;
F_111 ( L_10 ,
V_131 , V_123 -> V_109 , V_123 -> V_144 , V_123 -> V_145 ,
V_123 -> V_143 , V_123 -> V_142 / V_123 -> V_146 , V_123 -> V_146 ) ;
for ( V_138 = 0 ; V_138 < V_123 -> V_121 ; V_138 ++ ) {
const struct V_147 * V_148 = & V_123 -> V_127 [ V_138 ] ;
int V_126 = 0 , V_149 = 0 ;
F_46 ( V_148 -> V_122 % V_140 ) ;
for ( V_137 += V_148 -> V_122 / V_140 ;
V_136 < V_137 ; V_136 ++ ) {
if ( ! ( V_136 % V_141 ) ) {
F_112 ( L_11 ) ;
F_111 ( L_12 , V_131 ) ;
}
F_112 ( L_13 , V_132 , V_138 ) ;
for ( V_149 += V_140 ; V_126 < V_149 ; V_126 ++ )
if ( V_148 -> V_128 [ V_126 ] != V_129 )
F_112 ( L_14 ,
V_133 , V_148 -> V_128 [ V_126 ] ) ;
else
F_112 ( L_15 , V_135 ) ;
}
}
F_112 ( L_11 ) ;
}
int T_6 F_113 ( const struct V_120 * V_123 ,
void * V_6 )
{
static int V_150 [ V_151 ] V_152 ;
static int V_153 [ V_151 ] V_152 ;
T_2 V_145 = V_123 -> V_145 ;
T_2 V_154 = V_123 -> V_109 + V_123 -> V_144 + V_145 ;
struct V_13 * V_155 , * V_156 = NULL ;
unsigned long * V_157 ;
T_2 * V_158 ;
unsigned long * V_159 ;
unsigned int V_20 ;
int * V_160 ;
int V_138 , V_126 , V_33 ;
#define F_114 ( T_7 ) do { \
if (unlikely(cond)) { \
pr_emerg("failed to initialize, %s\n", #cond); \
pr_emerg("cpu_possible_mask=%*pb\n", \
cpumask_pr_args(cpu_possible_mask)); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_114 ( V_123 -> V_121 <= 0 ) ;
#ifdef F_93
F_114 ( ! V_123 -> V_109 ) ;
F_114 ( F_100 ( V_111 ) ) ;
#endif
F_114 ( ! V_6 ) ;
F_114 ( F_100 ( V_6 ) ) ;
F_114 ( V_123 -> V_143 < V_154 ) ;
F_114 ( F_100 ( V_123 -> V_143 ) ) ;
F_114 ( V_123 -> V_143 < V_92 ) ;
F_114 ( V_123 -> V_145 < V_161 ) ;
F_114 ( F_115 ( V_123 ) < 0 ) ;
V_157 = F_116 ( V_123 -> V_121 *
sizeof( V_157 [ 0 ] ) , 0 ) ;
V_158 = F_116 ( V_123 -> V_121 *
sizeof( V_158 [ 0 ] ) , 0 ) ;
V_160 = F_116 ( V_162 * sizeof( V_160 [ 0 ] ) , 0 ) ;
V_159 = F_116 ( V_162 * sizeof( V_159 [ 0 ] ) , 0 ) ;
for ( V_20 = 0 ; V_20 < V_162 ; V_20 ++ )
V_160 [ V_20 ] = V_163 ;
V_118 = V_129 ;
V_119 = V_129 ;
for ( V_138 = 0 , V_126 = 0 ; V_138 < V_123 -> V_121 ; V_138 ++ , V_126 += V_33 ) {
const struct V_147 * V_148 = & V_123 -> V_127 [ V_138 ] ;
V_157 [ V_138 ] = V_148 -> V_164 ;
V_158 [ V_138 ] = V_148 -> V_122 * V_123 -> V_143 ;
for ( V_33 = 0 ; V_33 < V_148 -> V_122 ; V_33 ++ ) {
V_20 = V_148 -> V_128 [ V_33 ] ;
if ( V_20 == V_129 )
continue;
F_114 ( V_20 >= V_162 ) ;
F_114 ( ! F_117 ( V_20 ) ) ;
F_114 ( V_160 [ V_20 ] != V_163 ) ;
V_160 [ V_20 ] = V_126 + V_33 ;
V_159 [ V_20 ] = V_148 -> V_164 + V_33 * V_123 -> V_143 ;
if ( V_118 == V_129 ||
V_159 [ V_20 ] < V_159 [ V_118 ] )
V_118 = V_20 ;
if ( V_119 == V_129 ||
V_159 [ V_20 ] > V_159 [ V_119 ] )
V_119 = V_20 ;
}
}
V_165 = V_126 ;
F_67 (cpu)
F_114 ( V_160 [ V_20 ] == V_163 ) ;
#undef F_114
F_107 ( V_166 , V_123 ) ;
V_167 = V_123 -> V_121 ;
V_168 = V_157 ;
V_169 = V_158 ;
V_22 = V_160 ;
V_24 = V_159 ;
V_23 = V_123 -> V_143 >> V_25 ;
V_7 = V_23 << V_25 ;
V_170 = V_123 -> V_146 ;
V_81 = sizeof( struct V_13 ) +
F_118 ( V_23 ) * sizeof( unsigned long ) ;
V_12 = F_5 ( V_7 ) + 2 ;
V_44 = F_116 (
V_12 * sizeof( V_44 [ 0 ] ) , 0 ) ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ )
F_48 ( & V_44 [ V_33 ] ) ;
V_155 = F_116 ( V_81 , 0 ) ;
F_48 ( & V_155 -> V_43 ) ;
F_48 ( & V_155 -> V_51 ) ;
V_155 -> V_6 = V_6 ;
V_155 -> V_35 = V_150 ;
V_155 -> V_49 = F_119 ( V_150 ) ;
V_155 -> V_97 = true ;
F_120 ( V_155 -> V_29 , V_23 ) ;
V_155 -> V_83 = V_23 ;
if ( V_123 -> V_144 ) {
V_155 -> V_15 = V_123 -> V_144 ;
V_42 = V_155 ;
V_8 = V_123 -> V_109 + V_123 -> V_144 ;
} else {
V_155 -> V_15 = V_145 ;
V_145 = 0 ;
}
V_155 -> V_16 = V_155 -> V_15 ;
V_155 -> V_35 [ 0 ] = 1 ;
V_155 -> V_35 [ 1 ] = V_123 -> V_109 ;
V_155 -> V_37 = 1 ;
if ( V_155 -> V_15 )
V_155 -> V_35 [ ++ V_155 -> V_37 ] = V_123 -> V_109 + V_155 -> V_15 ;
V_155 -> V_35 [ V_155 -> V_37 ] |= 1 ;
if ( V_145 ) {
V_156 = F_116 ( V_81 , 0 ) ;
F_48 ( & V_156 -> V_43 ) ;
F_48 ( & V_156 -> V_51 ) ;
V_156 -> V_6 = V_6 ;
V_156 -> V_35 = V_153 ;
V_156 -> V_49 = F_119 ( V_153 ) ;
V_156 -> V_97 = true ;
F_120 ( V_156 -> V_29 , V_23 ) ;
V_156 -> V_83 = V_23 ;
V_156 -> V_16 = V_156 -> V_15 = V_145 ;
V_156 -> V_35 [ 0 ] = 1 ;
V_156 -> V_35 [ 1 ] = V_8 ;
V_156 -> V_35 [ 2 ] = ( V_8 + V_156 -> V_15 ) | 1 ;
V_156 -> V_37 = 2 ;
}
V_5 = V_156 ? : V_155 ;
V_84 +=
F_25 ( V_5 , 1 ) ;
F_32 ( V_5 , - 1 ) ;
V_113 = V_6 ;
return 0 ;
}
static int T_6 F_121 ( char * V_171 )
{
if ( ! V_171 )
return - V_172 ;
if ( 0 )
;
#ifdef F_122
else if ( ! strcmp ( V_171 , L_16 ) )
V_173 = V_174 ;
#endif
#ifdef F_123
else if ( ! strcmp ( V_171 , L_17 ) )
V_173 = V_175 ;
#endif
else
F_70 ( L_18 , V_171 ) ;
return 0 ;
}
static struct V_120 * T_6 F_124 (
T_2 V_144 , T_2 V_145 ,
T_2 V_146 ,
T_8 V_176 )
{
static int V_177 [ V_129 ] V_152 ;
static int V_178 [ V_129 ] V_152 ;
const T_2 V_109 = V_110 - V_111 ;
int V_121 = 1 , V_122 = 0 ;
T_2 V_154 , V_179 , V_142 ;
int V_140 , V_180 , V_181 ( V_182 ) ;
int V_183 , V_138 , V_126 ;
unsigned int V_20 , V_184 ;
struct V_120 * V_123 ;
unsigned int * V_128 ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
memset ( V_178 , 0 , sizeof( V_178 ) ) ;
V_154 = F_104 ( V_109 + V_144 +
F_29 ( T_2 , V_145 , V_161 ) ) ;
V_145 = V_154 - V_109 - V_144 ;
V_179 = F_29 ( T_2 , V_154 , V_92 ) ;
V_142 = F_125 ( V_179 , V_146 ) ;
V_140 = V_142 / V_179 ;
while ( V_142 % V_140 || ( F_100 ( V_142 / V_140 ) ) )
V_140 -- ;
V_180 = V_140 ;
F_67 (cpu) {
V_138 = 0 ;
V_185:
F_67 (tcpu) {
if ( V_20 == V_184 )
break;
if ( V_177 [ V_184 ] == V_138 && V_176 &&
( V_176 ( V_20 , V_184 ) > V_186 ||
V_176 ( V_184 , V_20 ) > V_186 ) ) {
V_138 ++ ;
V_121 = F_7 ( V_121 , V_138 + 1 ) ;
goto V_185;
}
}
V_177 [ V_20 ] = V_138 ;
V_178 [ V_138 ] ++ ;
}
V_183 = V_187 ;
for ( V_140 = V_180 ; V_140 ; V_140 -- ) {
int V_188 = 0 , V_189 = 0 ;
if ( V_142 % V_140 || ( F_100 ( V_142 / V_140 ) ) )
continue;
for ( V_138 = 0 ; V_138 < V_121 ; V_138 ++ ) {
int V_190 = F_126 ( V_178 [ V_138 ] , V_140 ) ;
V_188 += V_190 ;
V_189 += V_190 * V_140 - V_178 [ V_138 ] ;
}
if ( V_189 > F_108 () / 3 )
continue;
if ( V_188 > V_183 )
break;
V_183 = V_188 ;
V_182 = V_140 ;
}
V_140 = V_182 ;
for ( V_138 = 0 ; V_138 < V_121 ; V_138 ++ )
V_122 += F_125 ( V_178 [ V_138 ] , V_140 ) ;
V_123 = F_101 ( V_121 , V_122 ) ;
if ( ! V_123 )
return F_127 ( - V_61 ) ;
V_128 = V_123 -> V_127 [ 0 ] . V_128 ;
for ( V_138 = 0 ; V_138 < V_121 ; V_138 ++ ) {
V_123 -> V_127 [ V_138 ] . V_128 = V_128 ;
V_128 += F_125 ( V_178 [ V_138 ] , V_140 ) ;
}
V_123 -> V_109 = V_109 ;
V_123 -> V_144 = V_144 ;
V_123 -> V_145 = V_145 ;
V_123 -> V_143 = V_142 / V_140 ;
V_123 -> V_146 = V_146 ;
V_123 -> V_142 = V_142 ;
for ( V_138 = 0 , V_126 = 0 ; V_178 [ V_138 ] ; V_138 ++ ) {
struct V_147 * V_148 = & V_123 -> V_127 [ V_138 ] ;
V_148 -> V_164 = V_126 * V_123 -> V_143 ;
F_67 (cpu)
if ( V_177 [ V_20 ] == V_138 )
V_148 -> V_128 [ V_148 -> V_122 ++ ] = V_20 ;
V_148 -> V_122 = F_125 ( V_148 -> V_122 , V_140 ) ;
V_126 += V_148 -> V_122 ;
}
F_46 ( V_126 != V_122 ) ;
return V_123 ;
}
int T_6 F_128 ( T_2 V_144 , T_2 V_145 ,
T_2 V_146 ,
T_8 V_176 ,
T_9 V_191 ,
T_10 V_192 )
{
void * V_112 = ( void * ) V_193 ;
void * * V_194 = NULL ;
struct V_120 * V_123 ;
T_2 V_154 , V_195 ;
unsigned long V_196 ;
int V_138 , V_33 , V_197 , V_198 ;
V_123 = F_124 ( V_144 , V_145 , V_146 ,
V_176 ) ;
if ( F_129 ( V_123 ) )
return F_130 ( V_123 ) ;
V_154 = V_123 -> V_109 + V_123 -> V_144 + V_123 -> V_145 ;
V_195 = F_104 ( V_123 -> V_121 * sizeof( void * ) ) ;
V_194 = F_103 ( V_195 , 0 ) ;
if ( ! V_194 ) {
V_198 = - V_61 ;
goto V_199;
}
V_197 = 0 ;
for ( V_138 = 0 ; V_138 < V_123 -> V_121 ; V_138 ++ ) {
struct V_147 * V_148 = & V_123 -> V_127 [ V_138 ] ;
unsigned int V_20 = V_129 ;
void * V_32 ;
for ( V_33 = 0 ; V_33 < V_148 -> V_122 && V_20 == V_129 ; V_33 ++ )
V_20 = V_148 -> V_128 [ V_33 ] ;
F_46 ( V_20 == V_129 ) ;
V_32 = V_191 ( V_20 , V_148 -> V_122 * V_123 -> V_143 , V_146 ) ;
if ( ! V_32 ) {
V_198 = - V_61 ;
goto V_200;
}
F_131 ( V_32 ) ;
V_194 [ V_138 ] = V_32 ;
V_112 = F_88 ( V_32 , V_112 ) ;
if ( V_32 > V_194 [ V_197 ] )
V_197 = V_138 ;
}
V_196 = V_194 [ V_197 ] - V_112 ;
V_196 += V_123 -> V_143 * V_123 -> V_127 [ V_197 ] . V_122 ;
if ( V_196 > V_201 * 3 / 4 ) {
F_70 ( L_19 ,
V_196 , V_201 ) ;
#ifdef F_123
V_198 = - V_172 ;
goto V_200;
#endif
}
for ( V_138 = 0 ; V_138 < V_123 -> V_121 ; V_138 ++ ) {
struct V_147 * V_148 = & V_123 -> V_127 [ V_138 ] ;
void * V_32 = V_194 [ V_138 ] ;
for ( V_33 = 0 ; V_33 < V_148 -> V_122 ; V_33 ++ , V_32 += V_123 -> V_143 ) {
if ( V_148 -> V_128 [ V_33 ] == V_129 ) {
V_192 ( V_32 , V_123 -> V_143 ) ;
continue;
}
memcpy ( V_32 , V_202 , V_123 -> V_109 ) ;
V_192 ( V_32 + V_154 , V_123 -> V_143 - V_154 ) ;
}
}
for ( V_138 = 0 ; V_138 < V_123 -> V_121 ; V_138 ++ ) {
V_123 -> V_127 [ V_138 ] . V_164 = V_194 [ V_138 ] - V_112 ;
}
F_72 ( L_20 ,
F_30 ( V_154 ) , V_112 , V_123 -> V_109 , V_123 -> V_144 ,
V_123 -> V_145 , V_123 -> V_143 ) ;
V_198 = F_113 ( V_123 , V_112 ) ;
goto V_199;
V_200:
for ( V_138 = 0 ; V_138 < V_123 -> V_121 ; V_138 ++ )
if ( V_194 [ V_138 ] )
V_192 ( V_194 [ V_138 ] ,
V_123 -> V_127 [ V_138 ] . V_122 * V_123 -> V_143 ) ;
V_199:
F_105 ( V_123 ) ;
if ( V_194 )
F_106 ( F_97 ( V_194 ) , V_195 ) ;
return V_198 ;
}
int T_6 F_132 ( T_2 V_144 ,
T_9 V_191 ,
T_10 V_192 ,
T_11 V_203 )
{
static struct V_204 V_205 ;
struct V_120 * V_123 ;
char V_206 [ 16 ] ;
int V_207 ;
T_2 V_208 ;
struct V_17 * * V_209 ;
int V_126 , V_33 , V_78 , V_198 ;
snprintf ( V_206 , sizeof( V_206 ) , L_21 , V_30 >> 10 ) ;
V_123 = F_124 ( V_144 , 0 , V_30 , NULL ) ;
if ( F_129 ( V_123 ) )
return F_130 ( V_123 ) ;
F_46 ( V_123 -> V_121 != 1 ) ;
F_46 ( V_123 -> V_127 [ 0 ] . V_122 != F_108 () ) ;
V_207 = V_123 -> V_143 >> V_25 ;
V_208 = F_104 ( V_207 * F_108 () *
sizeof( V_209 [ 0 ] ) ) ;
V_209 = F_116 ( V_208 , 0 ) ;
V_78 = 0 ;
for ( V_126 = 0 ; V_126 < F_108 () ; V_126 ++ )
for ( V_33 = 0 ; V_33 < V_207 ; V_33 ++ ) {
unsigned int V_20 = V_123 -> V_127 [ 0 ] . V_128 [ V_126 ] ;
void * V_32 ;
V_32 = V_191 ( V_20 , V_30 , V_30 ) ;
if ( ! V_32 ) {
F_70 ( L_22 ,
V_206 , V_20 ) ;
goto V_210;
}
F_131 ( V_32 ) ;
V_209 [ V_78 ++ ] = F_133 ( V_32 ) ;
}
V_205 . V_59 = V_211 ;
V_205 . V_9 = F_108 () * V_123 -> V_143 ;
F_134 ( & V_205 , V_30 ) ;
for ( V_126 = 0 ; V_126 < F_108 () ; V_126 ++ ) {
unsigned long V_212 =
( unsigned long ) V_205 . V_3 + V_126 * V_123 -> V_143 ;
for ( V_33 = 0 ; V_33 < V_207 ; V_33 ++ )
V_203 ( V_212 + ( V_33 << V_25 ) ) ;
V_198 = F_135 ( V_212 , & V_209 [ V_126 * V_207 ] ,
V_207 ) ;
if ( V_198 < 0 )
F_136 ( L_23 , V_198 ) ;
memcpy ( ( void * ) V_212 , V_202 , V_123 -> V_109 ) ;
}
F_72 ( L_24 ,
V_207 , V_206 , V_205 . V_3 , V_123 -> V_109 ,
V_123 -> V_144 , V_123 -> V_145 ) ;
V_198 = F_113 ( V_123 , V_205 . V_3 ) ;
goto V_213;
V_210:
while ( -- V_78 >= 0 )
V_192 ( F_137 ( V_209 [ V_78 ] ) , V_30 ) ;
V_198 = - V_61 ;
V_213:
F_106 ( F_97 ( V_209 ) , V_208 ) ;
F_105 ( V_123 ) ;
return V_198 ;
}
static void * T_6 F_138 ( unsigned int V_20 , T_2 V_9 ,
T_2 V_64 )
{
return F_139 (
V_9 , V_64 , F_97 ( V_214 ) ) ;
}
static void T_6 F_140 ( void * V_32 , T_2 V_9 )
{
F_106 ( F_97 ( V_32 ) , V_9 ) ;
}
void T_6 F_141 ( void )
{
unsigned long V_215 ;
unsigned int V_20 ;
int V_198 ;
V_198 = F_128 ( V_216 ,
V_217 , V_30 , NULL ,
F_138 , F_140 ) ;
if ( V_198 < 0 )
F_136 ( L_25 ) ;
V_215 = ( unsigned long ) V_113 - ( unsigned long ) V_111 ;
F_67 (cpu)
V_218 [ V_20 ] = V_215 + V_24 [ V_20 ] ;
}
void T_6 F_141 ( void )
{
const T_2 V_143 =
F_142 ( F_29 ( T_2 , V_92 ,
V_217 ) ) ;
struct V_120 * V_123 ;
void * V_219 ;
V_123 = F_101 ( 1 , 1 ) ;
V_219 = F_139 ( V_143 ,
V_30 ,
F_97 ( V_214 ) ) ;
if ( ! V_123 || ! V_219 )
F_136 ( L_26 ) ;
F_131 ( V_219 ) ;
V_123 -> V_145 = V_143 ;
V_123 -> V_143 = V_143 ;
V_123 -> V_146 = V_143 ;
V_123 -> V_142 = V_143 ;
V_123 -> V_127 [ 0 ] . V_122 = 1 ;
V_123 -> V_127 [ 0 ] . V_128 [ 0 ] = 0 ;
if ( F_113 ( V_123 , V_219 ) < 0 )
F_136 ( L_25 ) ;
}
void T_6 F_143 ( void )
{
struct V_13 * V_220 [] =
{ V_5 , V_42 , NULL } ;
struct V_13 * V_14 ;
unsigned long V_59 ;
int V_33 ;
for ( V_33 = 0 ; ( V_14 = V_220 [ V_33 ] ) ; V_33 ++ ) {
int * V_35 ;
const T_2 V_9 = V_151 * sizeof( V_35 [ 0 ] ) ;
F_144 ( V_9 > V_30 ) ;
V_35 = F_18 ( V_9 ) ;
F_46 ( ! V_35 ) ;
F_40 ( & V_48 , V_59 ) ;
memcpy ( V_35 , V_14 -> V_35 , V_9 ) ;
V_14 -> V_35 = V_35 ;
F_41 ( & V_48 , V_59 ) ;
}
}
static int T_6 F_145 ( void )
{
V_1 = true ;
return 0 ;
}
