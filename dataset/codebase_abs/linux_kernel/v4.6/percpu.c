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
if ( V_45 ) {
V_46 = 3 ;
if ( V_14 -> V_48 <
V_14 -> V_37 + V_49 &&
V_1 )
F_2 ( & V_14 -> V_50 ) ;
} else {
V_46 = V_51 ;
}
if ( V_14 -> V_48 >= V_14 -> V_37 + V_46 )
return 0 ;
V_47 = V_52 ;
while ( V_47 < V_14 -> V_37 + V_46 )
V_47 *= 2 ;
return V_47 ;
}
static int F_36 ( struct V_13 * V_14 , int V_47 )
{
int * V_53 = NULL , * V_54 = NULL ;
T_2 V_55 = 0 , V_56 = V_47 * sizeof( V_54 [ 0 ] ) ;
unsigned long V_57 ;
V_54 = F_18 ( V_56 ) ;
if ( ! V_54 )
return - V_58 ;
F_37 ( & V_59 , V_57 ) ;
if ( V_47 <= V_14 -> V_48 )
goto V_60;
V_55 = V_14 -> V_48 * sizeof( V_14 -> V_35 [ 0 ] ) ;
V_53 = V_14 -> V_35 ;
memcpy ( V_54 , V_53 , V_55 ) ;
V_14 -> V_48 = V_47 ;
V_14 -> V_35 = V_54 ;
V_54 = NULL ;
V_60:
F_38 ( & V_59 , V_57 ) ;
F_23 ( V_53 ) ;
F_23 ( V_54 ) ;
return 0 ;
}
static void F_39 ( struct V_61 * V_62 )
{
struct V_13 * V_14 = F_40 ( V_62 , struct V_13 ,
V_50 ) ;
int V_47 ;
F_41 ( & V_59 ) ;
V_47 = F_35 ( V_14 , false ) ;
F_42 ( & V_59 ) ;
if ( V_47 )
F_36 ( V_14 , V_47 ) ;
}
static int F_43 ( struct V_13 * V_14 , int V_34 , int V_63 ,
int V_9 , int V_64 , bool V_65 )
{
int V_66 = V_34 ;
while ( true ) {
int V_67 = F_44 ( V_66 , V_64 ) - V_34 ;
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
static int F_45 ( struct V_13 * V_14 , int V_9 , int V_64 ,
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
V_67 = F_43 ( V_14 , V_34 , V_63 , V_9 , V_64 ,
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
static void F_46 ( struct V_13 * V_14 , int V_77 ,
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
F_47 ( V_34 != V_77 ) ;
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
static struct V_13 * F_48 ( void )
{
struct V_13 * V_14 ;
V_14 = F_18 ( V_81 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_35 = F_18 ( V_52 *
sizeof( V_14 -> V_35 [ 0 ] ) ) ;
if ( ! V_14 -> V_35 ) {
F_23 ( V_14 ) ;
return NULL ;
}
V_14 -> V_48 = V_52 ;
V_14 -> V_35 [ 0 ] = 0 ;
V_14 -> V_35 [ 1 ] = V_7 | 1 ;
V_14 -> V_37 = 1 ;
F_49 ( & V_14 -> V_43 ) ;
F_50 ( & V_14 -> V_50 , F_39 ) ;
V_14 -> V_15 = V_7 ;
V_14 -> V_16 = V_7 ;
return V_14 ;
}
static void F_51 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return;
F_23 ( V_14 -> V_35 ) ;
F_23 ( V_14 ) ;
}
static void F_52 ( struct V_13 * V_14 ,
int V_68 , int V_69 )
{
int V_82 = V_69 - V_68 ;
F_53 ( & V_59 ) ;
F_54 ( V_14 -> V_29 , V_68 , V_82 ) ;
V_14 -> V_83 += V_82 ;
V_84 += V_82 ;
}
static void F_55 ( struct V_13 * V_14 ,
int V_68 , int V_69 )
{
int V_82 = V_69 - V_68 ;
F_53 ( & V_59 ) ;
F_56 ( V_14 -> V_29 , V_68 , V_82 ) ;
V_14 -> V_83 -= V_82 ;
V_84 -= V_82 ;
}
static struct V_13 * F_57 ( void * V_3 )
{
if ( F_3 ( V_3 ) ) {
if ( F_4 ( V_3 ) )
return V_42 ;
return V_5 ;
}
V_3 += V_24 [ F_58 () ] ;
return F_11 ( F_59 ( V_3 ) ) ;
}
static void T_3 * F_60 ( T_2 V_9 , T_2 V_64 , bool V_85 ,
T_4 V_86 )
{
static int V_87 = 10 ;
struct V_13 * V_14 ;
const char * V_88 ;
bool V_45 = ( V_86 & V_31 ) != V_31 ;
int V_89 = 0 ;
int V_90 , V_34 , V_47 , V_20 , V_91 ;
unsigned long V_57 ;
void T_3 * V_32 ;
if ( F_61 ( V_64 < 2 ) )
V_64 = 2 ;
V_9 = F_44 ( V_9 , 2 ) ;
if ( F_61 ( ! V_9 || V_9 > V_92 || V_64 > V_30 ) ) {
F_62 ( true , L_1 ,
V_9 , V_64 ) ;
return NULL ;
}
F_37 ( & V_59 , V_57 ) ;
if ( V_85 && V_42 ) {
V_14 = V_42 ;
if ( V_9 > V_14 -> V_16 ) {
V_88 = L_2 ;
goto V_93;
}
while ( ( V_47 = F_35 ( V_14 , V_45 ) ) ) {
F_38 ( & V_59 , V_57 ) ;
if ( V_45 ||
F_36 ( V_14 , V_47 ) < 0 ) {
V_88 = L_3 ;
goto V_94;
}
F_37 ( & V_59 , V_57 ) ;
}
V_34 = F_45 ( V_14 , V_9 , V_64 , V_45 ,
& V_89 ) ;
if ( V_34 >= 0 )
goto V_95;
V_88 = L_2 ;
goto V_93;
}
V_96:
for ( V_90 = F_8 ( V_9 ) ; V_90 < V_12 ; V_90 ++ ) {
F_63 (chunk, &pcpu_slot[slot], list) {
if ( V_9 > V_14 -> V_16 )
continue;
V_47 = F_35 ( V_14 , V_45 ) ;
if ( V_47 ) {
if ( V_45 )
continue;
F_38 ( & V_59 , V_57 ) ;
if ( F_36 ( V_14 ,
V_47 ) < 0 ) {
V_88 = L_4 ;
goto V_94;
}
F_37 ( & V_59 , V_57 ) ;
goto V_96;
}
V_34 = F_45 ( V_14 , V_9 , V_64 , V_45 ,
& V_89 ) ;
if ( V_34 >= 0 )
goto V_95;
}
}
F_38 ( & V_59 , V_57 ) ;
if ( V_45 )
goto V_94;
F_64 ( & V_97 ) ;
if ( F_65 ( & V_44 [ V_12 - 1 ] ) ) {
V_14 = F_66 () ;
if ( ! V_14 ) {
F_67 ( & V_97 ) ;
V_88 = L_5 ;
goto V_94;
}
F_37 ( & V_59 , V_57 ) ;
F_32 ( V_14 , - 1 ) ;
} else {
F_37 ( & V_59 , V_57 ) ;
}
F_67 ( & V_97 ) ;
goto V_96;
V_95:
F_38 ( & V_59 , V_57 ) ;
if ( ! V_45 ) {
int V_68 , V_69 , V_26 , V_27 ;
F_64 ( & V_97 ) ;
V_68 = F_30 ( V_34 ) ;
V_69 = F_31 ( V_34 + V_9 ) ;
F_68 (chunk, rs, re, page_start, page_end) {
F_69 ( V_14 -> V_98 ) ;
V_91 = F_70 ( V_14 , V_26 , V_27 ) ;
F_37 ( & V_59 , V_57 ) ;
if ( V_91 ) {
F_67 ( & V_97 ) ;
F_46 ( V_14 , V_34 , & V_89 ) ;
V_88 = L_6 ;
goto V_93;
}
F_52 ( V_14 , V_26 , V_27 ) ;
F_38 ( & V_59 , V_57 ) ;
}
F_67 ( & V_97 ) ;
}
if ( V_14 != V_42 )
V_84 -= V_89 ;
if ( V_84 < V_99 )
F_1 () ;
F_71 (cpu)
memset ( ( void * ) F_13 ( V_14 , V_20 , 0 ) + V_34 , 0 , V_9 ) ;
V_32 = F_72 ( V_14 -> V_6 + V_34 ) ;
F_73 ( V_32 , V_9 , V_86 ) ;
return V_32 ;
V_93:
F_38 ( & V_59 , V_57 ) ;
V_94:
if ( ! V_45 && V_87 ) {
F_74 ( L_7 ,
V_9 , V_64 , V_45 , V_88 ) ;
F_75 () ;
if ( ! -- V_87 )
F_76 ( L_8 ) ;
}
if ( V_45 ) {
V_100 = true ;
F_1 () ;
}
return NULL ;
}
void T_3 * F_77 ( T_2 V_9 , T_2 V_64 , T_4 V_86 )
{
return F_60 ( V_9 , V_64 , false , V_86 ) ;
}
void T_3 * F_78 ( T_2 V_9 , T_2 V_64 )
{
return F_60 ( V_9 , V_64 , false , V_31 ) ;
}
void T_3 * F_79 ( T_2 V_9 , T_2 V_64 )
{
return F_60 ( V_9 , V_64 , true , V_31 ) ;
}
static void F_80 ( struct V_61 * V_62 )
{
F_81 ( V_79 ) ;
struct V_101 * V_102 = & V_44 [ V_12 - 1 ] ;
struct V_13 * V_14 , * V_38 ;
int V_90 , V_103 , V_91 ;
F_64 ( & V_97 ) ;
F_41 ( & V_59 ) ;
F_82 (chunk, next, free_head, list) {
F_69 ( V_14 -> V_98 ) ;
if ( V_14 == F_83 ( V_102 , struct V_13 , V_43 ) )
continue;
F_33 ( & V_14 -> V_43 , & V_79 ) ;
}
F_42 ( & V_59 ) ;
F_82 (chunk, next, &to_free, list) {
int V_26 , V_27 ;
F_84 (chunk, rs, re, 0 , pcpu_unit_pages) {
F_85 ( V_14 , V_26 , V_27 ) ;
F_41 ( & V_59 ) ;
F_55 ( V_14 , V_26 , V_27 ) ;
F_42 ( & V_59 ) ;
}
F_86 ( V_14 ) ;
}
V_104:
if ( V_100 ) {
V_103 = V_105 ;
V_100 = false ;
} else {
V_103 = F_87 ( V_105 -
V_84 ,
0 , V_105 ) ;
}
for ( V_90 = F_8 ( V_30 ) ; V_90 < V_12 ; V_90 ++ ) {
int V_106 = 0 , V_26 , V_27 ;
if ( ! V_103 )
break;
F_41 ( & V_59 ) ;
F_63 (chunk, &pcpu_slot[slot], list) {
V_106 = V_23 - V_14 -> V_83 ;
if ( V_106 )
break;
}
F_42 ( & V_59 ) ;
if ( ! V_106 )
continue;
F_68 (chunk, rs, re, 0 , pcpu_unit_pages) {
int V_82 = F_88 ( V_27 - V_26 , V_103 ) ;
V_91 = F_70 ( V_14 , V_26 , V_26 + V_82 ) ;
if ( ! V_91 ) {
V_103 -= V_82 ;
F_41 ( & V_59 ) ;
F_52 ( V_14 , V_26 , V_26 + V_82 ) ;
F_42 ( & V_59 ) ;
} else {
V_103 = 0 ;
}
if ( ! V_103 )
break;
}
}
if ( V_103 ) {
V_14 = F_66 () ;
if ( V_14 ) {
F_41 ( & V_59 ) ;
F_32 ( V_14 , - 1 ) ;
F_42 ( & V_59 ) ;
goto V_104;
}
}
F_67 ( & V_97 ) ;
}
void F_89 ( void T_3 * V_32 )
{
void * V_3 ;
struct V_13 * V_14 ;
unsigned long V_57 ;
int V_34 , V_89 ;
if ( ! V_32 )
return;
F_90 ( V_32 ) ;
V_3 = F_91 ( V_32 ) ;
F_37 ( & V_59 , V_57 ) ;
V_14 = F_57 ( V_3 ) ;
V_34 = V_3 - V_14 -> V_6 ;
F_46 ( V_14 , V_34 , & V_89 ) ;
if ( V_14 != V_42 )
V_84 += V_89 ;
if ( V_14 -> V_15 == V_7 ) {
struct V_13 * V_107 ;
F_63 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_107 != V_14 ) {
F_1 () ;
break;
}
}
F_38 ( & V_59 , V_57 ) ;
}
bool F_92 ( unsigned long V_3 )
{
#ifdef F_93
const T_2 V_108 = V_109 - V_110 ;
void T_3 * V_111 = F_72 ( V_112 ) ;
unsigned int V_20 ;
F_71 (cpu) {
void * V_113 = F_94 ( V_111 , V_20 ) ;
if ( ( void * ) V_3 >= V_113 && ( void * ) V_3 < V_113 + V_108 )
return true ;
}
#endif
return false ;
}
T_5 F_95 ( void * V_3 )
{
void T_3 * V_111 = F_72 ( V_112 ) ;
bool V_114 = false ;
unsigned long V_115 , V_116 ;
unsigned int V_20 ;
V_115 = F_13 ( V_5 , V_117 , 0 ) ;
V_116 = F_13 ( V_5 , V_118 ,
V_23 ) ;
if ( ( unsigned long ) V_3 >= V_115 &&
( unsigned long ) V_3 < V_116 ) {
F_71 (cpu) {
void * V_113 = F_94 ( V_111 , V_20 ) ;
if ( V_3 >= V_113 && V_3 < V_113 + V_7 ) {
V_114 = true ;
break;
}
}
}
if ( V_114 ) {
if ( ! F_96 ( V_3 ) )
return F_97 ( V_3 ) ;
else
return F_98 ( F_99 ( V_3 ) ) +
F_100 ( V_3 ) ;
} else
return F_98 ( F_59 ( V_3 ) ) +
F_100 ( V_3 ) ;
}
struct V_119 * T_6 F_101 ( int V_120 ,
int V_121 )
{
struct V_119 * V_122 ;
T_2 V_123 , V_124 ;
void * V_32 ;
int V_125 ;
V_123 = F_44 ( sizeof( * V_122 ) + V_120 * sizeof( V_122 -> V_126 [ 0 ] ) ,
F_102 ( V_122 -> V_126 [ 0 ] . V_127 [ 0 ] ) ) ;
V_124 = V_123 + V_121 * sizeof( V_122 -> V_126 [ 0 ] . V_127 [ 0 ] ) ;
V_32 = F_103 ( F_104 ( V_124 ) , 0 ) ;
if ( ! V_32 )
return NULL ;
V_122 = V_32 ;
V_32 += V_123 ;
V_122 -> V_126 [ 0 ] . V_127 = V_32 ;
for ( V_125 = 0 ; V_125 < V_121 ; V_125 ++ )
V_122 -> V_126 [ 0 ] . V_127 [ V_125 ] = V_128 ;
V_122 -> V_120 = V_120 ;
V_122 -> V_129 = F_104 ( V_124 ) ;
return V_122 ;
}
void T_6 F_105 ( struct V_119 * V_122 )
{
F_106 ( F_97 ( V_122 ) , V_122 -> V_129 ) ;
}
static void F_107 ( const char * V_130 ,
const struct V_119 * V_122 )
{
int V_131 = 1 , V_132 = 1 , V_133 ;
char V_134 [] = L_9 ;
int V_135 = 0 , V_136 = 0 ;
int V_137 , V_138 ;
int V_139 , V_140 ;
V_138 = V_122 -> V_120 ;
while ( V_138 /= 10 )
V_131 ++ ;
V_138 = F_108 () ;
while ( V_138 /= 10 )
V_132 ++ ;
V_134 [ F_109 ( int , V_132 , sizeof( V_134 ) - 1 ) ] = '\0' ;
V_139 = V_122 -> V_141 / V_122 -> V_142 ;
V_133 = V_139 * ( V_132 + 1 ) + V_131 + 3 ;
V_140 = F_110 ( F_7 ( 60 / V_133 , 1 ) ) ;
F_111 ( L_10 ,
V_130 , V_122 -> V_108 , V_122 -> V_143 , V_122 -> V_144 ,
V_122 -> V_142 , V_122 -> V_141 / V_122 -> V_145 , V_122 -> V_145 ) ;
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ ) {
const struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
int V_125 = 0 , V_148 = 0 ;
F_47 ( V_147 -> V_121 % V_139 ) ;
for ( V_136 += V_147 -> V_121 / V_139 ;
V_135 < V_136 ; V_135 ++ ) {
if ( ! ( V_135 % V_140 ) ) {
F_112 ( L_11 ) ;
F_111 ( L_12 , V_130 ) ;
}
F_112 ( L_13 , V_131 , V_137 ) ;
for ( V_148 += V_139 ; V_125 < V_148 ; V_125 ++ )
if ( V_147 -> V_127 [ V_125 ] != V_128 )
F_112 ( L_14 ,
V_132 , V_147 -> V_127 [ V_125 ] ) ;
else
F_112 ( L_15 , V_134 ) ;
}
}
F_112 ( L_11 ) ;
}
int T_6 F_113 ( const struct V_119 * V_122 ,
void * V_6 )
{
static int V_149 [ V_150 ] V_151 ;
static int V_152 [ V_150 ] V_151 ;
T_2 V_144 = V_122 -> V_144 ;
T_2 V_153 = V_122 -> V_108 + V_122 -> V_143 + V_144 ;
struct V_13 * V_154 , * V_155 = NULL ;
unsigned long * V_156 ;
T_2 * V_157 ;
unsigned long * V_158 ;
unsigned int V_20 ;
int * V_159 ;
int V_137 , V_125 , V_33 ;
#define F_114 ( T_7 ) do { \
if (unlikely(cond)) { \
pr_emerg("failed to initialize, %s\n", #cond); \
pr_emerg("cpu_possible_mask=%*pb\n", \
cpumask_pr_args(cpu_possible_mask)); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_114 ( V_122 -> V_120 <= 0 ) ;
#ifdef F_93
F_114 ( ! V_122 -> V_108 ) ;
F_114 ( F_100 ( V_110 ) ) ;
#endif
F_114 ( ! V_6 ) ;
F_114 ( F_100 ( V_6 ) ) ;
F_114 ( V_122 -> V_142 < V_153 ) ;
F_114 ( F_100 ( V_122 -> V_142 ) ) ;
F_114 ( V_122 -> V_142 < V_92 ) ;
F_114 ( V_122 -> V_144 < V_160 ) ;
F_114 ( F_115 ( V_122 ) < 0 ) ;
V_156 = F_116 ( V_122 -> V_120 *
sizeof( V_156 [ 0 ] ) , 0 ) ;
V_157 = F_116 ( V_122 -> V_120 *
sizeof( V_157 [ 0 ] ) , 0 ) ;
V_159 = F_116 ( V_161 * sizeof( V_159 [ 0 ] ) , 0 ) ;
V_158 = F_116 ( V_161 * sizeof( V_158 [ 0 ] ) , 0 ) ;
for ( V_20 = 0 ; V_20 < V_161 ; V_20 ++ )
V_159 [ V_20 ] = V_162 ;
V_117 = V_128 ;
V_118 = V_128 ;
for ( V_137 = 0 , V_125 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ , V_125 += V_33 ) {
const struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
V_156 [ V_137 ] = V_147 -> V_163 ;
V_157 [ V_137 ] = V_147 -> V_121 * V_122 -> V_142 ;
for ( V_33 = 0 ; V_33 < V_147 -> V_121 ; V_33 ++ ) {
V_20 = V_147 -> V_127 [ V_33 ] ;
if ( V_20 == V_128 )
continue;
F_114 ( V_20 >= V_161 ) ;
F_114 ( ! F_117 ( V_20 ) ) ;
F_114 ( V_159 [ V_20 ] != V_162 ) ;
V_159 [ V_20 ] = V_125 + V_33 ;
V_158 [ V_20 ] = V_147 -> V_163 + V_33 * V_122 -> V_142 ;
if ( V_117 == V_128 ||
V_158 [ V_20 ] < V_158 [ V_117 ] )
V_117 = V_20 ;
if ( V_118 == V_128 ||
V_158 [ V_20 ] > V_158 [ V_118 ] )
V_118 = V_20 ;
}
}
V_164 = V_125 ;
F_71 (cpu)
F_114 ( V_159 [ V_20 ] == V_162 ) ;
#undef F_114
F_107 ( V_165 , V_122 ) ;
V_166 = V_122 -> V_120 ;
V_167 = V_156 ;
V_168 = V_157 ;
V_22 = V_159 ;
V_24 = V_158 ;
V_23 = V_122 -> V_142 >> V_25 ;
V_7 = V_23 << V_25 ;
V_169 = V_122 -> V_145 ;
V_81 = sizeof( struct V_13 ) +
F_118 ( V_23 ) * sizeof( unsigned long ) ;
V_12 = F_5 ( V_7 ) + 2 ;
V_44 = F_116 (
V_12 * sizeof( V_44 [ 0 ] ) , 0 ) ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ )
F_49 ( & V_44 [ V_33 ] ) ;
V_154 = F_116 ( V_81 , 0 ) ;
F_49 ( & V_154 -> V_43 ) ;
F_50 ( & V_154 -> V_50 , F_39 ) ;
V_154 -> V_6 = V_6 ;
V_154 -> V_35 = V_149 ;
V_154 -> V_48 = F_119 ( V_149 ) ;
V_154 -> V_98 = true ;
F_120 ( V_154 -> V_29 , V_23 ) ;
V_154 -> V_83 = V_23 ;
if ( V_122 -> V_143 ) {
V_154 -> V_15 = V_122 -> V_143 ;
V_42 = V_154 ;
V_8 = V_122 -> V_108 + V_122 -> V_143 ;
} else {
V_154 -> V_15 = V_144 ;
V_144 = 0 ;
}
V_154 -> V_16 = V_154 -> V_15 ;
V_154 -> V_35 [ 0 ] = 1 ;
V_154 -> V_35 [ 1 ] = V_122 -> V_108 ;
V_154 -> V_37 = 1 ;
if ( V_154 -> V_15 )
V_154 -> V_35 [ ++ V_154 -> V_37 ] = V_122 -> V_108 + V_154 -> V_15 ;
V_154 -> V_35 [ V_154 -> V_37 ] |= 1 ;
if ( V_144 ) {
V_155 = F_116 ( V_81 , 0 ) ;
F_49 ( & V_155 -> V_43 ) ;
F_50 ( & V_155 -> V_50 , F_39 ) ;
V_155 -> V_6 = V_6 ;
V_155 -> V_35 = V_152 ;
V_155 -> V_48 = F_119 ( V_152 ) ;
V_155 -> V_98 = true ;
F_120 ( V_155 -> V_29 , V_23 ) ;
V_155 -> V_83 = V_23 ;
V_155 -> V_16 = V_155 -> V_15 = V_144 ;
V_155 -> V_35 [ 0 ] = 1 ;
V_155 -> V_35 [ 1 ] = V_8 ;
V_155 -> V_35 [ 2 ] = ( V_8 + V_155 -> V_15 ) | 1 ;
V_155 -> V_37 = 2 ;
}
V_5 = V_155 ? : V_154 ;
V_84 +=
F_25 ( V_5 , 1 ) ;
F_32 ( V_5 , - 1 ) ;
V_112 = V_6 ;
return 0 ;
}
static int T_6 F_121 ( char * V_170 )
{
if ( ! V_170 )
return - V_171 ;
if ( 0 )
;
#ifdef F_122
else if ( ! strcmp ( V_170 , L_16 ) )
V_172 = V_173 ;
#endif
#ifdef F_123
else if ( ! strcmp ( V_170 , L_17 ) )
V_172 = V_174 ;
#endif
else
F_74 ( L_18 , V_170 ) ;
return 0 ;
}
static struct V_119 * T_6 F_124 (
T_2 V_143 , T_2 V_144 ,
T_2 V_145 ,
T_8 V_175 )
{
static int V_176 [ V_128 ] V_151 ;
static int V_177 [ V_128 ] V_151 ;
const T_2 V_108 = V_109 - V_110 ;
int V_120 = 1 , V_121 = 0 ;
T_2 V_153 , V_178 , V_141 ;
int V_139 , V_179 , V_180 ( V_181 ) ;
int V_182 , V_137 , V_125 ;
unsigned int V_20 , V_183 ;
struct V_119 * V_122 ;
unsigned int * V_127 ;
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
V_153 = F_104 ( V_108 + V_143 +
F_29 ( T_2 , V_144 , V_160 ) ) ;
V_144 = V_153 - V_108 - V_143 ;
V_178 = F_29 ( T_2 , V_153 , V_92 ) ;
V_141 = F_125 ( V_178 , V_145 ) ;
V_139 = V_141 / V_178 ;
while ( V_141 % V_139 || ( F_100 ( V_141 / V_139 ) ) )
V_139 -- ;
V_179 = V_139 ;
F_71 (cpu) {
V_137 = 0 ;
V_184:
F_71 (tcpu) {
if ( V_20 == V_183 )
break;
if ( V_176 [ V_183 ] == V_137 && V_175 &&
( V_175 ( V_20 , V_183 ) > V_185 ||
V_175 ( V_183 , V_20 ) > V_185 ) ) {
V_137 ++ ;
V_120 = F_7 ( V_120 , V_137 + 1 ) ;
goto V_184;
}
}
V_176 [ V_20 ] = V_137 ;
V_177 [ V_137 ] ++ ;
}
V_182 = V_186 ;
for ( V_139 = V_179 ; V_139 ; V_139 -- ) {
int V_187 = 0 , V_188 = 0 ;
if ( V_141 % V_139 || ( F_100 ( V_141 / V_139 ) ) )
continue;
for ( V_137 = 0 ; V_137 < V_120 ; V_137 ++ ) {
int V_189 = F_126 ( V_177 [ V_137 ] , V_139 ) ;
V_187 += V_189 ;
V_188 += V_189 * V_139 - V_177 [ V_137 ] ;
}
if ( V_188 > F_108 () / 3 )
continue;
if ( V_187 > V_182 )
break;
V_182 = V_187 ;
V_181 = V_139 ;
}
V_139 = V_181 ;
for ( V_137 = 0 ; V_137 < V_120 ; V_137 ++ )
V_121 += F_125 ( V_177 [ V_137 ] , V_139 ) ;
V_122 = F_101 ( V_120 , V_121 ) ;
if ( ! V_122 )
return F_127 ( - V_58 ) ;
V_127 = V_122 -> V_126 [ 0 ] . V_127 ;
for ( V_137 = 0 ; V_137 < V_120 ; V_137 ++ ) {
V_122 -> V_126 [ V_137 ] . V_127 = V_127 ;
V_127 += F_125 ( V_177 [ V_137 ] , V_139 ) ;
}
V_122 -> V_108 = V_108 ;
V_122 -> V_143 = V_143 ;
V_122 -> V_144 = V_144 ;
V_122 -> V_142 = V_141 / V_139 ;
V_122 -> V_145 = V_145 ;
V_122 -> V_141 = V_141 ;
for ( V_137 = 0 , V_125 = 0 ; V_177 [ V_137 ] ; V_137 ++ ) {
struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
V_147 -> V_163 = V_125 * V_122 -> V_142 ;
F_71 (cpu)
if ( V_176 [ V_20 ] == V_137 )
V_147 -> V_127 [ V_147 -> V_121 ++ ] = V_20 ;
V_147 -> V_121 = F_125 ( V_147 -> V_121 , V_139 ) ;
V_125 += V_147 -> V_121 ;
}
F_47 ( V_125 != V_121 ) ;
return V_122 ;
}
int T_6 F_128 ( T_2 V_143 , T_2 V_144 ,
T_2 V_145 ,
T_8 V_175 ,
T_9 V_190 ,
T_10 V_191 )
{
void * V_111 = ( void * ) V_192 ;
void * * V_193 = NULL ;
struct V_119 * V_122 ;
T_2 V_153 , V_194 , V_195 ;
int V_137 , V_33 , V_196 ;
V_122 = F_124 ( V_143 , V_144 , V_145 ,
V_175 ) ;
if ( F_129 ( V_122 ) )
return F_130 ( V_122 ) ;
V_153 = V_122 -> V_108 + V_122 -> V_143 + V_122 -> V_144 ;
V_194 = F_104 ( V_122 -> V_120 * sizeof( void * ) ) ;
V_193 = F_103 ( V_194 , 0 ) ;
if ( ! V_193 ) {
V_196 = - V_58 ;
goto V_197;
}
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ ) {
struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
unsigned int V_20 = V_128 ;
void * V_32 ;
for ( V_33 = 0 ; V_33 < V_147 -> V_121 && V_20 == V_128 ; V_33 ++ )
V_20 = V_147 -> V_127 [ V_33 ] ;
F_47 ( V_20 == V_128 ) ;
V_32 = V_190 ( V_20 , V_147 -> V_121 * V_122 -> V_142 , V_145 ) ;
if ( ! V_32 ) {
V_196 = - V_58 ;
goto V_198;
}
F_131 ( V_32 ) ;
V_193 [ V_137 ] = V_32 ;
V_111 = F_88 ( V_32 , V_111 ) ;
}
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ ) {
struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
void * V_32 = V_193 [ V_137 ] ;
for ( V_33 = 0 ; V_33 < V_147 -> V_121 ; V_33 ++ , V_32 += V_122 -> V_142 ) {
if ( V_147 -> V_127 [ V_33 ] == V_128 ) {
V_191 ( V_32 , V_122 -> V_142 ) ;
continue;
}
memcpy ( V_32 , V_199 , V_122 -> V_108 ) ;
V_191 ( V_32 + V_153 , V_122 -> V_142 - V_153 ) ;
}
}
V_195 = 0 ;
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ ) {
V_122 -> V_126 [ V_137 ] . V_163 = V_193 [ V_137 ] - V_111 ;
V_195 = F_29 ( T_2 , V_195 ,
V_122 -> V_126 [ V_137 ] . V_163 ) ;
}
V_195 += V_122 -> V_142 ;
if ( V_195 > V_200 * 3 / 4 ) {
F_74 ( L_19 ,
V_195 , V_200 ) ;
#ifdef F_123
V_196 = - V_171 ;
goto V_197;
#endif
}
F_76 ( L_20 ,
F_30 ( V_153 ) , V_111 , V_122 -> V_108 , V_122 -> V_143 ,
V_122 -> V_144 , V_122 -> V_142 ) ;
V_196 = F_113 ( V_122 , V_111 ) ;
goto V_197;
V_198:
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ )
if ( V_193 [ V_137 ] )
V_191 ( V_193 [ V_137 ] ,
V_122 -> V_126 [ V_137 ] . V_121 * V_122 -> V_142 ) ;
V_197:
F_105 ( V_122 ) ;
if ( V_193 )
F_106 ( F_97 ( V_193 ) , V_194 ) ;
return V_196 ;
}
int T_6 F_132 ( T_2 V_143 ,
T_9 V_190 ,
T_10 V_191 ,
T_11 V_201 )
{
static struct V_202 V_203 ;
struct V_119 * V_122 ;
char V_204 [ 16 ] ;
int V_205 ;
T_2 V_206 ;
struct V_17 * * V_207 ;
int V_125 , V_33 , V_78 , V_196 ;
snprintf ( V_204 , sizeof( V_204 ) , L_21 , V_30 >> 10 ) ;
V_122 = F_124 ( V_143 , 0 , V_30 , NULL ) ;
if ( F_129 ( V_122 ) )
return F_130 ( V_122 ) ;
F_47 ( V_122 -> V_120 != 1 ) ;
F_47 ( V_122 -> V_126 [ 0 ] . V_121 != F_108 () ) ;
V_205 = V_122 -> V_142 >> V_25 ;
V_206 = F_104 ( V_205 * F_108 () *
sizeof( V_207 [ 0 ] ) ) ;
V_207 = F_116 ( V_206 , 0 ) ;
V_78 = 0 ;
for ( V_125 = 0 ; V_125 < F_108 () ; V_125 ++ )
for ( V_33 = 0 ; V_33 < V_205 ; V_33 ++ ) {
unsigned int V_20 = V_122 -> V_126 [ 0 ] . V_127 [ V_125 ] ;
void * V_32 ;
V_32 = V_190 ( V_20 , V_30 , V_30 ) ;
if ( ! V_32 ) {
F_74 ( L_22 ,
V_204 , V_20 ) ;
goto V_208;
}
F_131 ( V_32 ) ;
V_207 [ V_78 ++ ] = F_133 ( V_32 ) ;
}
V_203 . V_57 = V_209 ;
V_203 . V_9 = F_108 () * V_122 -> V_142 ;
F_134 ( & V_203 , V_30 ) ;
for ( V_125 = 0 ; V_125 < F_108 () ; V_125 ++ ) {
unsigned long V_210 =
( unsigned long ) V_203 . V_3 + V_125 * V_122 -> V_142 ;
for ( V_33 = 0 ; V_33 < V_205 ; V_33 ++ )
V_201 ( V_210 + ( V_33 << V_25 ) ) ;
V_196 = F_135 ( V_210 , & V_207 [ V_125 * V_205 ] ,
V_205 ) ;
if ( V_196 < 0 )
F_136 ( L_23 , V_196 ) ;
memcpy ( ( void * ) V_210 , V_199 , V_122 -> V_108 ) ;
}
F_76 ( L_24 ,
V_205 , V_204 , V_203 . V_3 , V_122 -> V_108 ,
V_122 -> V_143 , V_122 -> V_144 ) ;
V_196 = F_113 ( V_122 , V_203 . V_3 ) ;
goto V_211;
V_208:
while ( -- V_78 >= 0 )
V_191 ( F_137 ( V_207 [ V_78 ] ) , V_30 ) ;
V_196 = - V_58 ;
V_211:
F_106 ( F_97 ( V_207 ) , V_206 ) ;
F_105 ( V_122 ) ;
return V_196 ;
}
static void * T_6 F_138 ( unsigned int V_20 , T_2 V_9 ,
T_2 V_64 )
{
return F_139 (
V_9 , V_64 , F_97 ( V_212 ) ) ;
}
static void T_6 F_140 ( void * V_32 , T_2 V_9 )
{
F_106 ( F_97 ( V_32 ) , V_9 ) ;
}
void T_6 F_141 ( void )
{
unsigned long V_213 ;
unsigned int V_20 ;
int V_196 ;
V_196 = F_128 ( V_214 ,
V_215 , V_30 , NULL ,
F_138 , F_140 ) ;
if ( V_196 < 0 )
F_136 ( L_25 ) ;
V_213 = ( unsigned long ) V_112 - ( unsigned long ) V_110 ;
F_71 (cpu)
V_216 [ V_20 ] = V_213 + V_24 [ V_20 ] ;
}
void T_6 F_141 ( void )
{
const T_2 V_142 =
F_142 ( F_29 ( T_2 , V_92 ,
V_215 ) ) ;
struct V_119 * V_122 ;
void * V_217 ;
V_122 = F_101 ( 1 , 1 ) ;
V_217 = F_139 ( V_142 ,
V_30 ,
F_97 ( V_212 ) ) ;
if ( ! V_122 || ! V_217 )
F_136 ( L_26 ) ;
F_131 ( V_217 ) ;
V_122 -> V_144 = V_142 ;
V_122 -> V_142 = V_142 ;
V_122 -> V_145 = V_142 ;
V_122 -> V_141 = V_142 ;
V_122 -> V_126 [ 0 ] . V_121 = 1 ;
V_122 -> V_126 [ 0 ] . V_127 [ 0 ] = 0 ;
if ( F_113 ( V_122 , V_217 ) < 0 )
F_136 ( L_25 ) ;
}
void T_6 F_143 ( void )
{
struct V_13 * V_218 [] =
{ V_5 , V_42 , NULL } ;
struct V_13 * V_14 ;
unsigned long V_57 ;
int V_33 ;
for ( V_33 = 0 ; ( V_14 = V_218 [ V_33 ] ) ; V_33 ++ ) {
int * V_35 ;
const T_2 V_9 = V_150 * sizeof( V_35 [ 0 ] ) ;
F_144 ( V_9 > V_30 ) ;
V_35 = F_18 ( V_9 ) ;
F_47 ( ! V_35 ) ;
F_37 ( & V_59 , V_57 ) ;
memcpy ( V_35 , V_14 -> V_35 , V_9 ) ;
V_14 -> V_35 = V_35 ;
F_38 ( & V_59 , V_57 ) ;
}
}
static int T_6 F_145 ( void )
{
V_1 = true ;
return 0 ;
}
