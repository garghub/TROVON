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
if ( F_58 ( ! V_9 || V_9 > V_92 || V_64 > V_30 ||
! F_59 ( V_64 ) ) ) {
F_60 ( true , L_1 ,
V_9 , V_64 ) ;
return NULL ;
}
if ( ! V_45 )
F_61 ( & V_60 ) ;
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
F_62 (chunk, &pcpu_slot[slot], list) {
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
V_14 = F_63 () ;
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
F_64 (chunk, rs, re, page_start, page_end) {
F_65 ( V_14 -> V_97 ) ;
V_91 = F_66 ( V_14 , V_26 , V_27 ) ;
F_40 ( & V_48 , V_59 ) ;
if ( V_91 ) {
F_45 ( V_14 , V_34 , & V_89 ) ;
V_88 = L_6 ;
goto V_93;
}
F_50 ( V_14 , V_26 , V_27 ) ;
F_41 ( & V_48 , V_59 ) ;
}
F_67 ( & V_60 ) ;
}
if ( V_14 != V_42 ) {
F_40 ( & V_48 , V_59 ) ;
V_84 -= V_89 ;
F_41 ( & V_48 , V_59 ) ;
}
if ( V_84 < V_98 )
F_1 () ;
F_68 (cpu)
memset ( ( void * ) F_13 ( V_14 , V_20 , 0 ) + V_34 , 0 , V_9 ) ;
V_32 = F_69 ( V_14 -> V_6 + V_34 ) ;
F_70 ( V_32 , V_9 , V_86 ) ;
return V_32 ;
V_93:
F_41 ( & V_48 , V_59 ) ;
V_94:
if ( ! V_45 && V_87 ) {
F_71 ( L_7 ,
V_9 , V_64 , V_45 , V_88 ) ;
F_72 () ;
if ( ! -- V_87 )
F_73 ( L_8 ) ;
}
if ( V_45 ) {
V_99 = true ;
F_1 () ;
} else {
F_67 ( & V_60 ) ;
}
return NULL ;
}
void T_3 * F_74 ( T_2 V_9 , T_2 V_64 , T_4 V_86 )
{
return F_57 ( V_9 , V_64 , false , V_86 ) ;
}
void T_3 * F_75 ( T_2 V_9 , T_2 V_64 )
{
return F_57 ( V_9 , V_64 , false , V_31 ) ;
}
void T_3 * F_76 ( T_2 V_9 , T_2 V_64 )
{
return F_57 ( V_9 , V_64 , true , V_31 ) ;
}
static void F_77 ( struct V_100 * V_101 )
{
F_78 ( V_79 ) ;
struct V_102 * V_103 = & V_44 [ V_12 - 1 ] ;
struct V_13 * V_14 , * V_38 ;
int V_90 , V_104 , V_91 ;
F_61 ( & V_60 ) ;
F_79 ( & V_48 ) ;
F_80 (chunk, next, free_head, list) {
F_65 ( V_14 -> V_97 ) ;
if ( V_14 == F_81 ( V_103 , struct V_13 , V_43 ) )
continue;
F_82 ( & V_14 -> V_51 ) ;
F_33 ( & V_14 -> V_43 , & V_79 ) ;
}
F_83 ( & V_48 ) ;
F_80 (chunk, next, &to_free, list) {
int V_26 , V_27 ;
F_84 (chunk, rs, re, 0 , pcpu_unit_pages) {
F_85 ( V_14 , V_26 , V_27 ) ;
F_79 ( & V_48 ) ;
F_52 ( V_14 , V_26 , V_27 ) ;
F_83 ( & V_48 ) ;
}
F_86 ( V_14 ) ;
}
do {
int V_47 = 0 ;
F_79 ( & V_48 ) ;
V_14 = F_87 ( & V_52 ,
struct V_13 , V_51 ) ;
if ( V_14 ) {
F_82 ( & V_14 -> V_51 ) ;
V_47 = F_35 ( V_14 , false ) ;
}
F_83 ( & V_48 ) ;
if ( V_47 )
F_39 ( V_14 , V_47 ) ;
} while ( V_14 );
V_105:
if ( V_99 ) {
V_104 = V_106 ;
V_99 = false ;
} else {
V_104 = F_88 ( V_106 -
V_84 ,
0 , V_106 ) ;
}
for ( V_90 = F_8 ( V_30 ) ; V_90 < V_12 ; V_90 ++ ) {
int V_107 = 0 , V_26 , V_27 ;
if ( ! V_104 )
break;
F_79 ( & V_48 ) ;
F_62 (chunk, &pcpu_slot[slot], list) {
V_107 = V_23 - V_14 -> V_83 ;
if ( V_107 )
break;
}
F_83 ( & V_48 ) ;
if ( ! V_107 )
continue;
F_64 (chunk, rs, re, 0 , pcpu_unit_pages) {
int V_82 = F_89 ( V_27 - V_26 , V_104 ) ;
V_91 = F_66 ( V_14 , V_26 , V_26 + V_82 ) ;
if ( ! V_91 ) {
V_104 -= V_82 ;
F_79 ( & V_48 ) ;
F_50 ( V_14 , V_26 , V_26 + V_82 ) ;
F_83 ( & V_48 ) ;
} else {
V_104 = 0 ;
}
if ( ! V_104 )
break;
}
}
if ( V_104 ) {
V_14 = F_63 () ;
if ( V_14 ) {
F_79 ( & V_48 ) ;
F_32 ( V_14 , - 1 ) ;
F_83 ( & V_48 ) ;
goto V_105;
}
}
F_67 ( & V_60 ) ;
}
void F_90 ( void T_3 * V_32 )
{
void * V_3 ;
struct V_13 * V_14 ;
unsigned long V_59 ;
int V_34 , V_89 ;
if ( ! V_32 )
return;
F_91 ( V_32 ) ;
V_3 = F_92 ( V_32 ) ;
F_40 ( & V_48 , V_59 ) ;
V_14 = F_54 ( V_3 ) ;
V_34 = V_3 - V_14 -> V_6 ;
F_45 ( V_14 , V_34 , & V_89 ) ;
if ( V_14 != V_42 )
V_84 += V_89 ;
if ( V_14 -> V_15 == V_7 ) {
struct V_13 * V_108 ;
F_62 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_108 != V_14 ) {
F_1 () ;
break;
}
}
F_41 ( & V_48 , V_59 ) ;
}
bool F_93 ( unsigned long V_3 , unsigned long * V_109 )
{
#ifdef F_94
const T_2 V_110 = V_111 - V_112 ;
void T_3 * V_113 = F_69 ( V_114 ) ;
unsigned int V_20 ;
F_68 (cpu) {
void * V_115 = F_95 ( V_113 , V_20 ) ;
void * V_116 = ( void * ) V_3 ;
if ( V_116 >= V_115 && V_116 < V_115 + V_110 ) {
if ( V_109 ) {
* V_109 = ( unsigned long ) ( V_116 - V_115 ) ;
* V_109 += ( unsigned long )
F_95 ( V_113 , F_96 () ) ;
}
return true ;
}
}
#endif
return false ;
}
bool F_97 ( unsigned long V_3 )
{
return F_93 ( V_3 , NULL ) ;
}
T_5 F_98 ( void * V_3 )
{
void T_3 * V_113 = F_69 ( V_114 ) ;
bool V_117 = false ;
unsigned long V_118 , V_119 ;
unsigned int V_20 ;
V_118 = F_13 ( V_5 , V_120 , 0 ) ;
V_119 = F_13 ( V_5 , V_121 ,
V_23 ) ;
if ( ( unsigned long ) V_3 >= V_118 &&
( unsigned long ) V_3 < V_119 ) {
F_68 (cpu) {
void * V_115 = F_95 ( V_113 , V_20 ) ;
if ( V_3 >= V_115 && V_3 < V_115 + V_7 ) {
V_117 = true ;
break;
}
}
}
if ( V_117 ) {
if ( ! F_99 ( V_3 ) )
return F_100 ( V_3 ) ;
else
return F_101 ( F_102 ( V_3 ) ) +
F_103 ( V_3 ) ;
} else
return F_101 ( F_56 ( V_3 ) ) +
F_103 ( V_3 ) ;
}
struct V_122 * T_6 F_104 ( int V_123 ,
int V_124 )
{
struct V_122 * V_125 ;
T_2 V_126 , V_127 ;
void * V_32 ;
int V_128 ;
V_126 = F_43 ( sizeof( * V_125 ) + V_123 * sizeof( V_125 -> V_129 [ 0 ] ) ,
F_105 ( V_125 -> V_129 [ 0 ] . V_130 [ 0 ] ) ) ;
V_127 = V_126 + V_124 * sizeof( V_125 -> V_129 [ 0 ] . V_130 [ 0 ] ) ;
V_32 = F_106 ( F_107 ( V_127 ) , 0 ) ;
if ( ! V_32 )
return NULL ;
V_125 = V_32 ;
V_32 += V_126 ;
V_125 -> V_129 [ 0 ] . V_130 = V_32 ;
for ( V_128 = 0 ; V_128 < V_124 ; V_128 ++ )
V_125 -> V_129 [ 0 ] . V_130 [ V_128 ] = V_131 ;
V_125 -> V_123 = V_123 ;
V_125 -> V_132 = F_107 ( V_127 ) ;
return V_125 ;
}
void T_6 F_108 ( struct V_122 * V_125 )
{
F_109 ( F_100 ( V_125 ) , V_125 -> V_132 ) ;
}
static void F_110 ( const char * V_133 ,
const struct V_122 * V_125 )
{
int V_134 = 1 , V_135 = 1 , V_136 ;
char V_137 [] = L_9 ;
int V_138 = 0 , V_139 = 0 ;
int V_140 , V_141 ;
int V_142 , V_143 ;
V_141 = V_125 -> V_123 ;
while ( V_141 /= 10 )
V_134 ++ ;
V_141 = F_111 () ;
while ( V_141 /= 10 )
V_135 ++ ;
V_137 [ F_112 ( int , V_135 , sizeof( V_137 ) - 1 ) ] = '\0' ;
V_142 = V_125 -> V_144 / V_125 -> V_145 ;
V_136 = V_142 * ( V_135 + 1 ) + V_134 + 3 ;
V_143 = F_113 ( F_7 ( 60 / V_136 , 1 ) ) ;
F_114 ( L_10 ,
V_133 , V_125 -> V_110 , V_125 -> V_146 , V_125 -> V_147 ,
V_125 -> V_145 , V_125 -> V_144 / V_125 -> V_148 , V_125 -> V_148 ) ;
for ( V_140 = 0 ; V_140 < V_125 -> V_123 ; V_140 ++ ) {
const struct V_149 * V_150 = & V_125 -> V_129 [ V_140 ] ;
int V_128 = 0 , V_151 = 0 ;
F_46 ( V_150 -> V_124 % V_142 ) ;
for ( V_139 += V_150 -> V_124 / V_142 ;
V_138 < V_139 ; V_138 ++ ) {
if ( ! ( V_138 % V_143 ) ) {
F_115 ( L_11 ) ;
F_114 ( L_12 , V_133 ) ;
}
F_115 ( L_13 , V_134 , V_140 ) ;
for ( V_151 += V_142 ; V_128 < V_151 ; V_128 ++ )
if ( V_150 -> V_130 [ V_128 ] != V_131 )
F_115 ( L_14 ,
V_135 , V_150 -> V_130 [ V_128 ] ) ;
else
F_115 ( L_15 , V_137 ) ;
}
}
F_115 ( L_11 ) ;
}
int T_6 F_116 ( const struct V_122 * V_125 ,
void * V_6 )
{
static int V_152 [ V_153 ] V_154 ;
static int V_155 [ V_153 ] V_154 ;
T_2 V_147 = V_125 -> V_147 ;
T_2 V_156 = V_125 -> V_110 + V_125 -> V_146 + V_147 ;
struct V_13 * V_157 , * V_158 = NULL ;
unsigned long * V_159 ;
T_2 * V_160 ;
unsigned long * V_161 ;
unsigned int V_20 ;
int * V_162 ;
int V_140 , V_128 , V_33 ;
#define F_117 ( T_7 ) do { \
if (unlikely(cond)) { \
pr_emerg("failed to initialize, %s\n", #cond); \
pr_emerg("cpu_possible_mask=%*pb\n", \
cpumask_pr_args(cpu_possible_mask)); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_117 ( V_125 -> V_123 <= 0 ) ;
#ifdef F_94
F_117 ( ! V_125 -> V_110 ) ;
F_117 ( F_103 ( V_112 ) ) ;
#endif
F_117 ( ! V_6 ) ;
F_117 ( F_103 ( V_6 ) ) ;
F_117 ( V_125 -> V_145 < V_156 ) ;
F_117 ( F_103 ( V_125 -> V_145 ) ) ;
F_117 ( V_125 -> V_145 < V_92 ) ;
F_117 ( V_125 -> V_147 < V_163 ) ;
F_117 ( F_118 ( V_125 ) < 0 ) ;
V_159 = F_119 ( V_125 -> V_123 *
sizeof( V_159 [ 0 ] ) , 0 ) ;
V_160 = F_119 ( V_125 -> V_123 *
sizeof( V_160 [ 0 ] ) , 0 ) ;
V_162 = F_119 ( V_164 * sizeof( V_162 [ 0 ] ) , 0 ) ;
V_161 = F_119 ( V_164 * sizeof( V_161 [ 0 ] ) , 0 ) ;
for ( V_20 = 0 ; V_20 < V_164 ; V_20 ++ )
V_162 [ V_20 ] = V_165 ;
V_120 = V_131 ;
V_121 = V_131 ;
for ( V_140 = 0 , V_128 = 0 ; V_140 < V_125 -> V_123 ; V_140 ++ , V_128 += V_33 ) {
const struct V_149 * V_150 = & V_125 -> V_129 [ V_140 ] ;
V_159 [ V_140 ] = V_150 -> V_166 ;
V_160 [ V_140 ] = V_150 -> V_124 * V_125 -> V_145 ;
for ( V_33 = 0 ; V_33 < V_150 -> V_124 ; V_33 ++ ) {
V_20 = V_150 -> V_130 [ V_33 ] ;
if ( V_20 == V_131 )
continue;
F_117 ( V_20 >= V_164 ) ;
F_117 ( ! F_120 ( V_20 ) ) ;
F_117 ( V_162 [ V_20 ] != V_165 ) ;
V_162 [ V_20 ] = V_128 + V_33 ;
V_161 [ V_20 ] = V_150 -> V_166 + V_33 * V_125 -> V_145 ;
if ( V_120 == V_131 ||
V_161 [ V_20 ] < V_161 [ V_120 ] )
V_120 = V_20 ;
if ( V_121 == V_131 ||
V_161 [ V_20 ] > V_161 [ V_121 ] )
V_121 = V_20 ;
}
}
V_167 = V_128 ;
F_68 (cpu)
F_117 ( V_162 [ V_20 ] == V_165 ) ;
#undef F_117
F_110 ( V_168 , V_125 ) ;
V_169 = V_125 -> V_123 ;
V_170 = V_159 ;
V_171 = V_160 ;
V_22 = V_162 ;
V_24 = V_161 ;
V_23 = V_125 -> V_145 >> V_25 ;
V_7 = V_23 << V_25 ;
V_172 = V_125 -> V_148 ;
V_81 = sizeof( struct V_13 ) +
F_121 ( V_23 ) * sizeof( unsigned long ) ;
V_12 = F_5 ( V_7 ) + 2 ;
V_44 = F_119 (
V_12 * sizeof( V_44 [ 0 ] ) , 0 ) ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ )
F_48 ( & V_44 [ V_33 ] ) ;
V_157 = F_119 ( V_81 , 0 ) ;
F_48 ( & V_157 -> V_43 ) ;
F_48 ( & V_157 -> V_51 ) ;
V_157 -> V_6 = V_6 ;
V_157 -> V_35 = V_152 ;
V_157 -> V_49 = F_122 ( V_152 ) ;
V_157 -> V_97 = true ;
F_123 ( V_157 -> V_29 , V_23 ) ;
V_157 -> V_83 = V_23 ;
if ( V_125 -> V_146 ) {
V_157 -> V_15 = V_125 -> V_146 ;
V_42 = V_157 ;
V_8 = V_125 -> V_110 + V_125 -> V_146 ;
} else {
V_157 -> V_15 = V_147 ;
V_147 = 0 ;
}
V_157 -> V_16 = V_157 -> V_15 ;
V_157 -> V_35 [ 0 ] = 1 ;
V_157 -> V_35 [ 1 ] = V_125 -> V_110 ;
V_157 -> V_37 = 1 ;
if ( V_157 -> V_15 )
V_157 -> V_35 [ ++ V_157 -> V_37 ] = V_125 -> V_110 + V_157 -> V_15 ;
V_157 -> V_35 [ V_157 -> V_37 ] |= 1 ;
if ( V_147 ) {
V_158 = F_119 ( V_81 , 0 ) ;
F_48 ( & V_158 -> V_43 ) ;
F_48 ( & V_158 -> V_51 ) ;
V_158 -> V_6 = V_6 ;
V_158 -> V_35 = V_155 ;
V_158 -> V_49 = F_122 ( V_155 ) ;
V_158 -> V_97 = true ;
F_123 ( V_158 -> V_29 , V_23 ) ;
V_158 -> V_83 = V_23 ;
V_158 -> V_16 = V_158 -> V_15 = V_147 ;
V_158 -> V_35 [ 0 ] = 1 ;
V_158 -> V_35 [ 1 ] = V_8 ;
V_158 -> V_35 [ 2 ] = ( V_8 + V_158 -> V_15 ) | 1 ;
V_158 -> V_37 = 2 ;
}
V_5 = V_158 ? : V_157 ;
V_84 +=
F_25 ( V_5 , 1 ) ;
F_32 ( V_5 , - 1 ) ;
V_114 = V_6 ;
return 0 ;
}
static int T_6 F_124 ( char * V_173 )
{
if ( ! V_173 )
return - V_174 ;
if ( 0 )
;
#ifdef F_125
else if ( ! strcmp ( V_173 , L_16 ) )
V_175 = V_176 ;
#endif
#ifdef F_126
else if ( ! strcmp ( V_173 , L_17 ) )
V_175 = V_177 ;
#endif
else
F_71 ( L_18 , V_173 ) ;
return 0 ;
}
static struct V_122 * T_6 F_127 (
T_2 V_146 , T_2 V_147 ,
T_2 V_148 ,
T_8 V_178 )
{
static int V_179 [ V_131 ] V_154 ;
static int V_180 [ V_131 ] V_154 ;
const T_2 V_110 = V_111 - V_112 ;
int V_123 = 1 , V_124 = 0 ;
T_2 V_156 , V_181 , V_144 ;
int V_142 , V_182 , V_183 ( V_184 ) ;
int V_185 , V_140 , V_128 ;
unsigned int V_20 , V_186 ;
struct V_122 * V_125 ;
unsigned int * V_130 ;
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
V_156 = F_107 ( V_110 + V_146 +
F_29 ( T_2 , V_147 , V_163 ) ) ;
V_147 = V_156 - V_110 - V_146 ;
V_181 = F_29 ( T_2 , V_156 , V_92 ) ;
V_144 = F_128 ( V_181 , V_148 ) ;
V_142 = V_144 / V_181 ;
while ( V_144 % V_142 || ( F_103 ( V_144 / V_142 ) ) )
V_142 -- ;
V_182 = V_142 ;
F_68 (cpu) {
V_140 = 0 ;
V_187:
F_68 (tcpu) {
if ( V_20 == V_186 )
break;
if ( V_179 [ V_186 ] == V_140 && V_178 &&
( V_178 ( V_20 , V_186 ) > V_188 ||
V_178 ( V_186 , V_20 ) > V_188 ) ) {
V_140 ++ ;
V_123 = F_7 ( V_123 , V_140 + 1 ) ;
goto V_187;
}
}
V_179 [ V_20 ] = V_140 ;
V_180 [ V_140 ] ++ ;
}
V_185 = V_189 ;
for ( V_142 = V_182 ; V_142 ; V_142 -- ) {
int V_190 = 0 , V_191 = 0 ;
if ( V_144 % V_142 || ( F_103 ( V_144 / V_142 ) ) )
continue;
for ( V_140 = 0 ; V_140 < V_123 ; V_140 ++ ) {
int V_192 = F_129 ( V_180 [ V_140 ] , V_142 ) ;
V_190 += V_192 ;
V_191 += V_192 * V_142 - V_180 [ V_140 ] ;
}
if ( V_191 > F_111 () / 3 )
continue;
if ( V_190 > V_185 )
break;
V_185 = V_190 ;
V_184 = V_142 ;
}
V_142 = V_184 ;
for ( V_140 = 0 ; V_140 < V_123 ; V_140 ++ )
V_124 += F_128 ( V_180 [ V_140 ] , V_142 ) ;
V_125 = F_104 ( V_123 , V_124 ) ;
if ( ! V_125 )
return F_130 ( - V_61 ) ;
V_130 = V_125 -> V_129 [ 0 ] . V_130 ;
for ( V_140 = 0 ; V_140 < V_123 ; V_140 ++ ) {
V_125 -> V_129 [ V_140 ] . V_130 = V_130 ;
V_130 += F_128 ( V_180 [ V_140 ] , V_142 ) ;
}
V_125 -> V_110 = V_110 ;
V_125 -> V_146 = V_146 ;
V_125 -> V_147 = V_147 ;
V_125 -> V_145 = V_144 / V_142 ;
V_125 -> V_148 = V_148 ;
V_125 -> V_144 = V_144 ;
for ( V_140 = 0 , V_128 = 0 ; V_180 [ V_140 ] ; V_140 ++ ) {
struct V_149 * V_150 = & V_125 -> V_129 [ V_140 ] ;
V_150 -> V_166 = V_128 * V_125 -> V_145 ;
F_68 (cpu)
if ( V_179 [ V_20 ] == V_140 )
V_150 -> V_130 [ V_150 -> V_124 ++ ] = V_20 ;
V_150 -> V_124 = F_128 ( V_150 -> V_124 , V_142 ) ;
V_128 += V_150 -> V_124 ;
}
F_46 ( V_128 != V_124 ) ;
return V_125 ;
}
int T_6 F_131 ( T_2 V_146 , T_2 V_147 ,
T_2 V_148 ,
T_8 V_178 ,
T_9 V_193 ,
T_10 V_194 )
{
void * V_113 = ( void * ) V_195 ;
void * * V_196 = NULL ;
struct V_122 * V_125 ;
T_2 V_156 , V_197 ;
unsigned long V_198 ;
int V_140 , V_33 , V_199 , V_200 ;
V_125 = F_127 ( V_146 , V_147 , V_148 ,
V_178 ) ;
if ( F_132 ( V_125 ) )
return F_133 ( V_125 ) ;
V_156 = V_125 -> V_110 + V_125 -> V_146 + V_125 -> V_147 ;
V_197 = F_107 ( V_125 -> V_123 * sizeof( void * ) ) ;
V_196 = F_106 ( V_197 , 0 ) ;
if ( ! V_196 ) {
V_200 = - V_61 ;
goto V_201;
}
V_199 = 0 ;
for ( V_140 = 0 ; V_140 < V_125 -> V_123 ; V_140 ++ ) {
struct V_149 * V_150 = & V_125 -> V_129 [ V_140 ] ;
unsigned int V_20 = V_131 ;
void * V_32 ;
for ( V_33 = 0 ; V_33 < V_150 -> V_124 && V_20 == V_131 ; V_33 ++ )
V_20 = V_150 -> V_130 [ V_33 ] ;
F_46 ( V_20 == V_131 ) ;
V_32 = V_193 ( V_20 , V_150 -> V_124 * V_125 -> V_145 , V_148 ) ;
if ( ! V_32 ) {
V_200 = - V_61 ;
goto V_202;
}
F_134 ( V_32 ) ;
V_196 [ V_140 ] = V_32 ;
V_113 = F_89 ( V_32 , V_113 ) ;
if ( V_32 > V_196 [ V_199 ] )
V_199 = V_140 ;
}
V_198 = V_196 [ V_199 ] - V_113 ;
V_198 += V_125 -> V_145 * V_125 -> V_129 [ V_199 ] . V_124 ;
if ( V_198 > V_203 * 3 / 4 ) {
F_71 ( L_19 ,
V_198 , V_203 ) ;
#ifdef F_126
V_200 = - V_174 ;
goto V_202;
#endif
}
for ( V_140 = 0 ; V_140 < V_125 -> V_123 ; V_140 ++ ) {
struct V_149 * V_150 = & V_125 -> V_129 [ V_140 ] ;
void * V_32 = V_196 [ V_140 ] ;
for ( V_33 = 0 ; V_33 < V_150 -> V_124 ; V_33 ++ , V_32 += V_125 -> V_145 ) {
if ( V_150 -> V_130 [ V_33 ] == V_131 ) {
V_194 ( V_32 , V_125 -> V_145 ) ;
continue;
}
memcpy ( V_32 , V_204 , V_125 -> V_110 ) ;
V_194 ( V_32 + V_156 , V_125 -> V_145 - V_156 ) ;
}
}
for ( V_140 = 0 ; V_140 < V_125 -> V_123 ; V_140 ++ ) {
V_125 -> V_129 [ V_140 ] . V_166 = V_196 [ V_140 ] - V_113 ;
}
F_73 ( L_20 ,
F_30 ( V_156 ) , V_113 , V_125 -> V_110 , V_125 -> V_146 ,
V_125 -> V_147 , V_125 -> V_145 ) ;
V_200 = F_116 ( V_125 , V_113 ) ;
goto V_201;
V_202:
for ( V_140 = 0 ; V_140 < V_125 -> V_123 ; V_140 ++ )
if ( V_196 [ V_140 ] )
V_194 ( V_196 [ V_140 ] ,
V_125 -> V_129 [ V_140 ] . V_124 * V_125 -> V_145 ) ;
V_201:
F_108 ( V_125 ) ;
if ( V_196 )
F_109 ( F_100 ( V_196 ) , V_197 ) ;
return V_200 ;
}
int T_6 F_135 ( T_2 V_146 ,
T_9 V_193 ,
T_10 V_194 ,
T_11 V_205 )
{
static struct V_206 V_207 ;
struct V_122 * V_125 ;
char V_208 [ 16 ] ;
int V_209 ;
T_2 V_210 ;
struct V_17 * * V_211 ;
int V_128 , V_33 , V_78 , V_200 ;
int V_142 ;
int V_212 ;
snprintf ( V_208 , sizeof( V_208 ) , L_21 , V_30 >> 10 ) ;
V_125 = F_127 ( V_146 , 0 , V_30 , NULL ) ;
if ( F_132 ( V_125 ) )
return F_133 ( V_125 ) ;
F_46 ( V_125 -> V_123 != 1 ) ;
V_142 = V_125 -> V_144 / V_125 -> V_145 ;
V_212 = F_128 ( F_111 () , V_142 ) ;
if ( F_58 ( F_65 ( V_125 -> V_129 [ 0 ] . V_124 != V_212 ) ) ) {
F_108 ( V_125 ) ;
return - V_174 ;
}
V_209 = V_125 -> V_145 >> V_25 ;
V_210 = F_107 ( V_209 * F_111 () *
sizeof( V_211 [ 0 ] ) ) ;
V_211 = F_119 ( V_210 , 0 ) ;
V_78 = 0 ;
for ( V_128 = 0 ; V_128 < F_111 () ; V_128 ++ ) {
unsigned int V_20 = V_125 -> V_129 [ 0 ] . V_130 [ V_128 ] ;
for ( V_33 = 0 ; V_33 < V_209 ; V_33 ++ ) {
void * V_32 ;
V_32 = V_193 ( V_20 , V_30 , V_30 ) ;
if ( ! V_32 ) {
F_71 ( L_22 ,
V_208 , V_20 ) ;
goto V_213;
}
F_134 ( V_32 ) ;
V_211 [ V_78 ++ ] = F_136 ( V_32 ) ;
}
}
V_207 . V_59 = V_214 ;
V_207 . V_9 = F_111 () * V_125 -> V_145 ;
F_137 ( & V_207 , V_30 ) ;
for ( V_128 = 0 ; V_128 < F_111 () ; V_128 ++ ) {
unsigned long V_215 =
( unsigned long ) V_207 . V_3 + V_128 * V_125 -> V_145 ;
for ( V_33 = 0 ; V_33 < V_209 ; V_33 ++ )
V_205 ( V_215 + ( V_33 << V_25 ) ) ;
V_200 = F_138 ( V_215 , & V_211 [ V_128 * V_209 ] ,
V_209 ) ;
if ( V_200 < 0 )
F_139 ( L_23 , V_200 ) ;
memcpy ( ( void * ) V_215 , V_204 , V_125 -> V_110 ) ;
}
F_73 ( L_24 ,
V_209 , V_208 , V_207 . V_3 , V_125 -> V_110 ,
V_125 -> V_146 , V_125 -> V_147 ) ;
V_200 = F_116 ( V_125 , V_207 . V_3 ) ;
goto V_216;
V_213:
while ( -- V_78 >= 0 )
V_194 ( F_140 ( V_211 [ V_78 ] ) , V_30 ) ;
V_200 = - V_61 ;
V_216:
F_109 ( F_100 ( V_211 ) , V_210 ) ;
F_108 ( V_125 ) ;
return V_200 ;
}
static void * T_6 F_141 ( unsigned int V_20 , T_2 V_9 ,
T_2 V_64 )
{
return F_142 (
V_9 , V_64 , F_100 ( V_217 ) ) ;
}
static void T_6 F_143 ( void * V_32 , T_2 V_9 )
{
F_109 ( F_100 ( V_32 ) , V_9 ) ;
}
void T_6 F_144 ( void )
{
unsigned long V_218 ;
unsigned int V_20 ;
int V_200 ;
V_200 = F_131 ( V_219 ,
V_220 , V_30 , NULL ,
F_141 , F_143 ) ;
if ( V_200 < 0 )
F_139 ( L_25 ) ;
V_218 = ( unsigned long ) V_114 - ( unsigned long ) V_112 ;
F_68 (cpu)
V_221 [ V_20 ] = V_218 + V_24 [ V_20 ] ;
}
void T_6 F_144 ( void )
{
const T_2 V_145 =
F_145 ( F_29 ( T_2 , V_92 ,
V_220 ) ) ;
struct V_122 * V_125 ;
void * V_222 ;
V_125 = F_104 ( 1 , 1 ) ;
V_222 = F_142 ( V_145 ,
V_30 ,
F_100 ( V_217 ) ) ;
if ( ! V_125 || ! V_222 )
F_139 ( L_26 ) ;
F_134 ( V_222 ) ;
V_125 -> V_147 = V_145 ;
V_125 -> V_145 = V_145 ;
V_125 -> V_148 = V_145 ;
V_125 -> V_144 = V_145 ;
V_125 -> V_129 [ 0 ] . V_124 = 1 ;
V_125 -> V_129 [ 0 ] . V_130 [ 0 ] = 0 ;
if ( F_116 ( V_125 , V_222 ) < 0 )
F_139 ( L_25 ) ;
}
void T_6 F_146 ( void )
{
struct V_13 * V_223 [] =
{ V_5 , V_42 , NULL } ;
struct V_13 * V_14 ;
unsigned long V_59 ;
int V_33 ;
for ( V_33 = 0 ; ( V_14 = V_223 [ V_33 ] ) ; V_33 ++ ) {
int * V_35 ;
const T_2 V_9 = V_153 * sizeof( V_35 [ 0 ] ) ;
F_147 ( V_9 > V_30 ) ;
V_35 = F_18 ( V_9 ) ;
F_46 ( ! V_35 ) ;
F_40 ( & V_48 , V_59 ) ;
memcpy ( V_35 , V_14 -> V_35 , V_9 ) ;
V_14 -> V_35 = V_35 ;
F_41 ( & V_48 , V_59 ) ;
}
}
static int T_6 F_148 ( void )
{
V_1 = true ;
return 0 ;
}
