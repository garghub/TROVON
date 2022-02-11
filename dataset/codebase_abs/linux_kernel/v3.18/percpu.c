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
static void F_23 ( void * V_32 , T_2 V_9 )
{
if ( V_9 <= V_30 )
F_24 ( V_32 ) ;
else
F_25 ( V_32 ) ;
}
static int F_26 ( struct V_13 * V_14 , int V_33 )
{
int V_34 = V_14 -> V_35 [ V_33 ] & ~ 1 ;
int V_28 = V_14 -> V_35 [ V_33 + 1 ] & ~ 1 ;
if ( ! F_27 ( V_34 ) && V_33 > 0 ) {
int V_36 = V_14 -> V_35 [ V_33 - 1 ] ;
if ( ! ( V_36 & 1 ) && V_36 <= F_28 ( V_34 , V_30 ) )
V_34 = F_28 ( V_34 , V_30 ) ;
}
if ( ! F_27 ( V_28 ) && V_33 + 1 < V_14 -> V_37 ) {
int V_38 = V_14 -> V_35 [ V_33 + 1 ] ;
int V_39 = V_14 -> V_35 [ V_33 + 2 ] & ~ 1 ;
if ( ! ( V_38 & 1 ) && V_39 >= F_29 ( V_28 , V_30 ) )
V_28 = F_29 ( V_28 , V_30 ) ;
}
return F_30 ( int , F_31 ( V_28 ) - F_32 ( V_34 ) , 0 ) ;
}
static void F_33 ( struct V_13 * V_14 , int V_40 )
{
int V_41 = F_9 ( V_14 ) ;
if ( V_14 != V_42 && V_40 != V_41 ) {
if ( V_40 < V_41 )
F_34 ( & V_14 -> V_43 , & V_44 [ V_41 ] ) ;
else
F_35 ( & V_14 -> V_43 , & V_44 [ V_41 ] ) ;
}
}
static int F_36 ( struct V_13 * V_14 , bool V_45 )
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
static int F_37 ( struct V_13 * V_14 , int V_47 )
{
int * V_53 = NULL , * V_54 = NULL ;
T_2 V_55 = 0 , V_56 = V_47 * sizeof( V_54 [ 0 ] ) ;
unsigned long V_57 ;
V_54 = F_18 ( V_56 ) ;
if ( ! V_54 )
return - V_58 ;
F_38 ( & V_59 , V_57 ) ;
if ( V_47 <= V_14 -> V_48 )
goto V_60;
V_55 = V_14 -> V_48 * sizeof( V_14 -> V_35 [ 0 ] ) ;
V_53 = V_14 -> V_35 ;
memcpy ( V_54 , V_53 , V_55 ) ;
V_14 -> V_48 = V_47 ;
V_14 -> V_35 = V_54 ;
V_54 = NULL ;
V_60:
F_39 ( & V_59 , V_57 ) ;
F_23 ( V_53 , V_55 ) ;
F_23 ( V_54 , V_56 ) ;
return 0 ;
}
static void F_40 ( struct V_61 * V_62 )
{
struct V_13 * V_14 = F_41 ( V_62 , struct V_13 ,
V_50 ) ;
int V_47 ;
F_42 ( & V_59 ) ;
V_47 = F_36 ( V_14 , false ) ;
F_43 ( & V_59 ) ;
if ( V_47 )
F_37 ( V_14 , V_47 ) ;
}
static int F_44 ( struct V_13 * V_14 , int V_34 , int V_63 ,
int V_9 , int V_64 , bool V_65 )
{
int V_66 = V_34 ;
while ( true ) {
int V_67 = F_45 ( V_66 , V_64 ) - V_34 ;
int V_68 , V_69 , V_26 , V_27 ;
if ( V_63 < V_67 + V_9 )
return - 1 ;
if ( ! V_65 )
return V_67 ;
V_68 = F_31 ( V_67 + V_34 ) ;
V_69 = F_32 ( V_67 + V_34 + V_9 ) ;
V_26 = V_68 ;
F_14 ( V_14 , & V_26 , & V_27 , F_32 ( V_34 + V_63 ) ) ;
if ( V_26 >= V_69 )
return V_67 ;
V_66 = V_27 * V_30 ;
}
}
static int F_46 ( struct V_13 * V_14 , int V_9 , int V_64 ,
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
V_67 = F_44 ( V_14 , V_34 , V_63 , V_9 , V_64 ,
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
* V_70 = F_26 ( V_14 , V_33 ) ;
F_33 ( V_14 , V_40 ) ;
return V_34 ;
}
V_14 -> V_16 = V_71 ;
F_33 ( V_14 , V_40 ) ;
return - 1 ;
}
static void F_47 ( struct V_13 * V_14 , int V_77 ,
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
F_48 ( V_34 != V_77 ) ;
if ( V_33 < V_14 -> V_74 )
V_14 -> V_74 = V_33 ;
V_73 = V_14 -> V_35 + V_33 ;
* V_73 = V_34 &= ~ 1 ;
V_14 -> V_15 += ( V_73 [ 1 ] & ~ 1 ) - V_34 ;
* V_70 = F_26 ( V_14 , V_33 ) ;
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
F_33 ( V_14 , V_40 ) ;
}
static struct V_13 * F_49 ( void )
{
struct V_13 * V_14 ;
V_14 = F_18 ( V_81 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_35 = F_18 ( V_52 *
sizeof( V_14 -> V_35 [ 0 ] ) ) ;
if ( ! V_14 -> V_35 ) {
F_23 ( V_14 , V_81 ) ;
return NULL ;
}
V_14 -> V_48 = V_52 ;
V_14 -> V_35 [ 0 ] = 0 ;
V_14 -> V_35 [ 1 ] = V_7 | 1 ;
V_14 -> V_37 = 1 ;
F_50 ( & V_14 -> V_43 ) ;
F_51 ( & V_14 -> V_50 , F_40 ) ;
V_14 -> V_15 = V_7 ;
V_14 -> V_16 = V_7 ;
return V_14 ;
}
static void F_52 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return;
F_23 ( V_14 -> V_35 , V_14 -> V_48 * sizeof( V_14 -> V_35 [ 0 ] ) ) ;
F_23 ( V_14 , V_81 ) ;
}
static void F_53 ( struct V_13 * V_14 ,
int V_68 , int V_69 )
{
int V_82 = V_69 - V_68 ;
F_54 ( & V_59 ) ;
F_55 ( V_14 -> V_29 , V_68 , V_82 ) ;
V_14 -> V_83 += V_82 ;
V_84 += V_82 ;
}
static void F_56 ( struct V_13 * V_14 ,
int V_68 , int V_69 )
{
int V_82 = V_69 - V_68 ;
F_54 ( & V_59 ) ;
F_57 ( V_14 -> V_29 , V_68 , V_82 ) ;
V_14 -> V_83 -= V_82 ;
V_84 -= V_82 ;
}
static struct V_13 * F_58 ( void * V_3 )
{
if ( F_3 ( V_3 ) ) {
if ( F_4 ( V_3 ) )
return V_42 ;
return V_5 ;
}
V_3 += V_24 [ F_59 () ] ;
return F_11 ( F_60 ( V_3 ) ) ;
}
static void T_3 * F_61 ( T_2 V_9 , T_2 V_64 , bool V_85 ,
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
if ( F_62 ( V_64 < 2 ) )
V_64 = 2 ;
V_9 = F_45 ( V_9 , 2 ) ;
if ( F_62 ( ! V_9 || V_9 > V_92 || V_64 > V_30 ) ) {
F_63 ( true , L_1
L_2 , V_9 , V_64 ) ;
return NULL ;
}
F_38 ( & V_59 , V_57 ) ;
if ( V_85 && V_42 ) {
V_14 = V_42 ;
if ( V_9 > V_14 -> V_16 ) {
V_88 = L_3 ;
goto V_93;
}
while ( ( V_47 = F_36 ( V_14 , V_45 ) ) ) {
F_39 ( & V_59 , V_57 ) ;
if ( V_45 ||
F_37 ( V_14 , V_47 ) < 0 ) {
V_88 = L_4 ;
goto V_94;
}
F_38 ( & V_59 , V_57 ) ;
}
V_34 = F_46 ( V_14 , V_9 , V_64 , V_45 ,
& V_89 ) ;
if ( V_34 >= 0 )
goto V_95;
V_88 = L_3 ;
goto V_93;
}
V_96:
for ( V_90 = F_8 ( V_9 ) ; V_90 < V_12 ; V_90 ++ ) {
F_64 (chunk, &pcpu_slot[slot], list) {
if ( V_9 > V_14 -> V_16 )
continue;
V_47 = F_36 ( V_14 , V_45 ) ;
if ( V_47 ) {
if ( V_45 )
continue;
F_39 ( & V_59 , V_57 ) ;
if ( F_37 ( V_14 ,
V_47 ) < 0 ) {
V_88 = L_5 ;
goto V_94;
}
F_38 ( & V_59 , V_57 ) ;
goto V_96;
}
V_34 = F_46 ( V_14 , V_9 , V_64 , V_45 ,
& V_89 ) ;
if ( V_34 >= 0 )
goto V_95;
}
}
F_39 ( & V_59 , V_57 ) ;
if ( V_45 )
goto V_94;
F_65 ( & V_97 ) ;
if ( F_66 ( & V_44 [ V_12 - 1 ] ) ) {
V_14 = F_67 () ;
if ( ! V_14 ) {
F_68 ( & V_97 ) ;
V_88 = L_6 ;
goto V_94;
}
F_38 ( & V_59 , V_57 ) ;
F_33 ( V_14 , - 1 ) ;
} else {
F_38 ( & V_59 , V_57 ) ;
}
F_68 ( & V_97 ) ;
goto V_96;
V_95:
F_39 ( & V_59 , V_57 ) ;
if ( ! V_45 ) {
int V_68 , V_69 , V_26 , V_27 ;
F_65 ( & V_97 ) ;
V_68 = F_31 ( V_34 ) ;
V_69 = F_32 ( V_34 + V_9 ) ;
F_69 (chunk, rs, re, page_start, page_end) {
F_70 ( V_14 -> V_98 ) ;
V_91 = F_71 ( V_14 , V_26 , V_27 ) ;
F_38 ( & V_59 , V_57 ) ;
if ( V_91 ) {
F_68 ( & V_97 ) ;
F_47 ( V_14 , V_34 , & V_89 ) ;
V_88 = L_7 ;
goto V_93;
}
F_53 ( V_14 , V_26 , V_27 ) ;
F_39 ( & V_59 , V_57 ) ;
}
F_68 ( & V_97 ) ;
}
if ( V_14 != V_42 )
V_84 -= V_89 ;
if ( V_84 < V_99 )
F_1 () ;
F_72 (cpu)
memset ( ( void * ) F_13 ( V_14 , V_20 , 0 ) + V_34 , 0 , V_9 ) ;
V_32 = F_73 ( V_14 -> V_6 + V_34 ) ;
F_74 ( V_32 , V_9 ) ;
return V_32 ;
V_93:
F_39 ( & V_59 , V_57 ) ;
V_94:
if ( ! V_45 && V_87 ) {
F_75 ( L_8 ,
V_9 , V_64 , V_45 , V_88 ) ;
F_76 () ;
if ( ! -- V_87 )
F_77 ( L_9 ) ;
}
if ( V_45 ) {
V_100 = true ;
F_1 () ;
}
return NULL ;
}
void T_3 * F_78 ( T_2 V_9 , T_2 V_64 , T_4 V_86 )
{
return F_61 ( V_9 , V_64 , false , V_86 ) ;
}
void T_3 * F_79 ( T_2 V_9 , T_2 V_64 )
{
return F_61 ( V_9 , V_64 , false , V_31 ) ;
}
void T_3 * F_80 ( T_2 V_9 , T_2 V_64 )
{
return F_61 ( V_9 , V_64 , true , V_31 ) ;
}
static void F_81 ( struct V_61 * V_62 )
{
F_82 ( V_79 ) ;
struct V_101 * V_102 = & V_44 [ V_12 - 1 ] ;
struct V_13 * V_14 , * V_38 ;
int V_90 , V_103 , V_91 ;
F_65 ( & V_97 ) ;
F_42 ( & V_59 ) ;
F_83 (chunk, next, free_head, list) {
F_70 ( V_14 -> V_98 ) ;
if ( V_14 == F_84 ( V_102 , struct V_13 , V_43 ) )
continue;
F_34 ( & V_14 -> V_43 , & V_79 ) ;
}
F_43 ( & V_59 ) ;
F_83 (chunk, next, &to_free, list) {
int V_26 , V_27 ;
F_85 (chunk, rs, re, 0 , pcpu_unit_pages) {
F_86 ( V_14 , V_26 , V_27 ) ;
F_42 ( & V_59 ) ;
F_56 ( V_14 , V_26 , V_27 ) ;
F_43 ( & V_59 ) ;
}
F_87 ( V_14 ) ;
}
V_104:
if ( V_100 ) {
V_103 = V_105 ;
V_100 = false ;
} else {
V_103 = F_88 ( V_105 -
V_84 ,
0 , V_105 ) ;
}
for ( V_90 = F_8 ( V_30 ) ; V_90 < V_12 ; V_90 ++ ) {
int V_106 = 0 , V_26 , V_27 ;
if ( ! V_103 )
break;
F_42 ( & V_59 ) ;
F_64 (chunk, &pcpu_slot[slot], list) {
V_106 = V_23 - V_14 -> V_83 ;
if ( V_106 )
break;
}
F_43 ( & V_59 ) ;
if ( ! V_106 )
continue;
F_69 (chunk, rs, re, 0 , pcpu_unit_pages) {
int V_82 = F_89 ( V_27 - V_26 , V_103 ) ;
V_91 = F_71 ( V_14 , V_26 , V_26 + V_82 ) ;
if ( ! V_91 ) {
V_103 -= V_82 ;
F_42 ( & V_59 ) ;
F_53 ( V_14 , V_26 , V_26 + V_82 ) ;
F_43 ( & V_59 ) ;
} else {
V_103 = 0 ;
}
if ( ! V_103 )
break;
}
}
if ( V_103 ) {
V_14 = F_67 () ;
if ( V_14 ) {
F_42 ( & V_59 ) ;
F_33 ( V_14 , - 1 ) ;
F_43 ( & V_59 ) ;
goto V_104;
}
}
F_68 ( & V_97 ) ;
}
void F_90 ( void T_3 * V_32 )
{
void * V_3 ;
struct V_13 * V_14 ;
unsigned long V_57 ;
int V_34 , V_89 ;
if ( ! V_32 )
return;
F_91 ( V_32 ) ;
V_3 = F_92 ( V_32 ) ;
F_38 ( & V_59 , V_57 ) ;
V_14 = F_58 ( V_3 ) ;
V_34 = V_3 - V_14 -> V_6 ;
F_47 ( V_14 , V_34 , & V_89 ) ;
if ( V_14 != V_42 )
V_84 += V_89 ;
if ( V_14 -> V_15 == V_7 ) {
struct V_13 * V_107 ;
F_64 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_107 != V_14 ) {
F_1 () ;
break;
}
}
F_39 ( & V_59 , V_57 ) ;
}
bool F_93 ( unsigned long V_3 )
{
#ifdef F_94
const T_2 V_108 = V_109 - V_110 ;
void T_3 * V_111 = F_73 ( V_112 ) ;
unsigned int V_20 ;
F_72 (cpu) {
void * V_113 = F_95 ( V_111 , V_20 ) ;
if ( ( void * ) V_3 >= V_113 && ( void * ) V_3 < V_113 + V_108 )
return true ;
}
#endif
return false ;
}
T_5 F_96 ( void * V_3 )
{
void T_3 * V_111 = F_73 ( V_112 ) ;
bool V_114 = false ;
unsigned long V_115 , V_116 ;
unsigned int V_20 ;
V_115 = F_13 ( V_5 , V_117 , 0 ) ;
V_116 = F_13 ( V_5 , V_118 ,
V_23 ) ;
if ( ( unsigned long ) V_3 >= V_115 &&
( unsigned long ) V_3 < V_116 ) {
F_72 (cpu) {
void * V_113 = F_95 ( V_111 , V_20 ) ;
if ( V_3 >= V_113 && V_3 < V_113 + V_7 ) {
V_114 = true ;
break;
}
}
}
if ( V_114 ) {
if ( ! F_97 ( V_3 ) )
return F_98 ( V_3 ) ;
else
return F_99 ( F_100 ( V_3 ) ) +
F_101 ( V_3 ) ;
} else
return F_99 ( F_60 ( V_3 ) ) +
F_101 ( V_3 ) ;
}
struct V_119 * T_6 F_102 ( int V_120 ,
int V_121 )
{
struct V_119 * V_122 ;
T_2 V_123 , V_124 ;
void * V_32 ;
int V_125 ;
V_123 = F_45 ( sizeof( * V_122 ) + V_120 * sizeof( V_122 -> V_126 [ 0 ] ) ,
F_103 ( V_122 -> V_126 [ 0 ] . V_127 [ 0 ] ) ) ;
V_124 = V_123 + V_121 * sizeof( V_122 -> V_126 [ 0 ] . V_127 [ 0 ] ) ;
V_32 = F_104 ( F_105 ( V_124 ) , 0 ) ;
if ( ! V_32 )
return NULL ;
V_122 = V_32 ;
V_32 += V_123 ;
V_122 -> V_126 [ 0 ] . V_127 = V_32 ;
for ( V_125 = 0 ; V_125 < V_121 ; V_125 ++ )
V_122 -> V_126 [ 0 ] . V_127 [ V_125 ] = V_128 ;
V_122 -> V_120 = V_120 ;
V_122 -> V_129 = F_105 ( V_124 ) ;
return V_122 ;
}
void T_6 F_106 ( struct V_119 * V_122 )
{
F_107 ( F_98 ( V_122 ) , V_122 -> V_129 ) ;
}
static void F_108 ( const char * V_130 ,
const struct V_119 * V_122 )
{
int V_131 = 1 , V_132 = 1 , V_133 ;
char V_134 [] = L_10 ;
int V_135 = 0 , V_136 = 0 ;
int V_137 , V_138 ;
int V_139 , V_140 ;
V_138 = V_122 -> V_120 ;
while ( V_138 /= 10 )
V_131 ++ ;
V_138 = F_109 () ;
while ( V_138 /= 10 )
V_132 ++ ;
V_134 [ F_110 ( int , V_132 , sizeof( V_134 ) - 1 ) ] = '\0' ;
V_139 = V_122 -> V_141 / V_122 -> V_142 ;
V_133 = V_139 * ( V_132 + 1 ) + V_131 + 3 ;
V_140 = F_111 ( F_7 ( 60 / V_133 , 1 ) ) ;
F_112 ( L_11 ,
V_130 , V_122 -> V_108 , V_122 -> V_143 , V_122 -> V_144 ,
V_122 -> V_142 , V_122 -> V_141 / V_122 -> V_145 , V_122 -> V_145 ) ;
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ ) {
const struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
int V_125 = 0 , V_148 = 0 ;
F_48 ( V_147 -> V_121 % V_139 ) ;
for ( V_136 += V_147 -> V_121 / V_139 ;
V_135 < V_136 ; V_135 ++ ) {
if ( ! ( V_135 % V_140 ) ) {
F_112 ( V_149 L_12 ) ;
F_112 ( L_13 , V_130 ) ;
}
F_112 ( V_149 L_14 , V_131 , V_137 ) ;
for ( V_148 += V_139 ; V_125 < V_148 ; V_125 ++ )
if ( V_147 -> V_127 [ V_125 ] != V_128 )
F_112 ( V_149 L_15 , V_132 ,
V_147 -> V_127 [ V_125 ] ) ;
else
F_112 ( V_149 L_16 , V_134 ) ;
}
}
F_112 ( V_149 L_12 ) ;
}
int T_6 F_113 ( const struct V_119 * V_122 ,
void * V_6 )
{
static char V_150 [ 4096 ] V_151 ;
static int V_152 [ V_153 ] V_151 ;
static int V_154 [ V_153 ] V_151 ;
T_2 V_144 = V_122 -> V_144 ;
T_2 V_155 = V_122 -> V_108 + V_122 -> V_143 + V_144 ;
struct V_13 * V_156 , * V_157 = NULL ;
unsigned long * V_158 ;
T_2 * V_159 ;
unsigned long * V_160 ;
unsigned int V_20 ;
int * V_161 ;
int V_137 , V_125 , V_33 ;
F_114 ( V_150 , sizeof( V_150 ) , V_162 ) ;
#define F_115 ( T_7 ) do { \
if (unlikely(cond)) { \
pr_emerg("PERCPU: failed to initialize, %s", #cond); \
pr_emerg("PERCPU: cpu_possible_mask=%s\n", cpus_buf); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_115 ( V_122 -> V_120 <= 0 ) ;
#ifdef F_94
F_115 ( ! V_122 -> V_108 ) ;
F_115 ( ( unsigned long ) V_110 & ~ V_163 ) ;
#endif
F_115 ( ! V_6 ) ;
F_115 ( ( unsigned long ) V_6 & ~ V_163 ) ;
F_115 ( V_122 -> V_142 < V_155 ) ;
F_115 ( V_122 -> V_142 & ~ V_163 ) ;
F_115 ( V_122 -> V_142 < V_92 ) ;
F_115 ( V_122 -> V_144 < V_164 ) ;
F_115 ( F_116 ( V_122 ) < 0 ) ;
V_158 = F_117 ( V_122 -> V_120 *
sizeof( V_158 [ 0 ] ) , 0 ) ;
V_159 = F_117 ( V_122 -> V_120 *
sizeof( V_159 [ 0 ] ) , 0 ) ;
V_161 = F_117 ( V_165 * sizeof( V_161 [ 0 ] ) , 0 ) ;
V_160 = F_117 ( V_165 * sizeof( V_160 [ 0 ] ) , 0 ) ;
for ( V_20 = 0 ; V_20 < V_165 ; V_20 ++ )
V_161 [ V_20 ] = V_166 ;
V_117 = V_128 ;
V_118 = V_128 ;
for ( V_137 = 0 , V_125 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ , V_125 += V_33 ) {
const struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
V_158 [ V_137 ] = V_147 -> V_167 ;
V_159 [ V_137 ] = V_147 -> V_121 * V_122 -> V_142 ;
for ( V_33 = 0 ; V_33 < V_147 -> V_121 ; V_33 ++ ) {
V_20 = V_147 -> V_127 [ V_33 ] ;
if ( V_20 == V_128 )
continue;
F_115 ( V_20 > V_165 ) ;
F_115 ( ! F_118 ( V_20 ) ) ;
F_115 ( V_161 [ V_20 ] != V_166 ) ;
V_161 [ V_20 ] = V_125 + V_33 ;
V_160 [ V_20 ] = V_147 -> V_167 + V_33 * V_122 -> V_142 ;
if ( V_117 == V_128 ||
V_160 [ V_20 ] < V_160 [ V_117 ] )
V_117 = V_20 ;
if ( V_118 == V_128 ||
V_160 [ V_20 ] > V_160 [ V_118 ] )
V_118 = V_20 ;
}
}
V_168 = V_125 ;
F_72 (cpu)
F_115 ( V_161 [ V_20 ] == V_166 ) ;
#undef F_115
F_108 ( V_169 , V_122 ) ;
V_170 = V_122 -> V_120 ;
V_171 = V_158 ;
V_172 = V_159 ;
V_22 = V_161 ;
V_24 = V_160 ;
V_23 = V_122 -> V_142 >> V_25 ;
V_7 = V_23 << V_25 ;
V_173 = V_122 -> V_145 ;
V_81 = sizeof( struct V_13 ) +
F_119 ( V_23 ) * sizeof( unsigned long ) ;
V_12 = F_5 ( V_7 ) + 2 ;
V_44 = F_117 (
V_12 * sizeof( V_44 [ 0 ] ) , 0 ) ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ )
F_50 ( & V_44 [ V_33 ] ) ;
V_156 = F_117 ( V_81 , 0 ) ;
F_50 ( & V_156 -> V_43 ) ;
F_51 ( & V_156 -> V_50 , F_40 ) ;
V_156 -> V_6 = V_6 ;
V_156 -> V_35 = V_152 ;
V_156 -> V_48 = F_120 ( V_152 ) ;
V_156 -> V_98 = true ;
F_121 ( V_156 -> V_29 , V_23 ) ;
V_156 -> V_83 = V_23 ;
if ( V_122 -> V_143 ) {
V_156 -> V_15 = V_122 -> V_143 ;
V_42 = V_156 ;
V_8 = V_122 -> V_108 + V_122 -> V_143 ;
} else {
V_156 -> V_15 = V_144 ;
V_144 = 0 ;
}
V_156 -> V_16 = V_156 -> V_15 ;
V_156 -> V_35 [ 0 ] = 1 ;
V_156 -> V_35 [ 1 ] = V_122 -> V_108 ;
V_156 -> V_37 = 1 ;
if ( V_156 -> V_15 )
V_156 -> V_35 [ ++ V_156 -> V_37 ] = 1 | ( V_122 -> V_108 + V_156 -> V_15 ) ;
else
V_156 -> V_35 [ 1 ] |= 1 ;
if ( V_144 ) {
V_157 = F_117 ( V_81 , 0 ) ;
F_50 ( & V_157 -> V_43 ) ;
F_51 ( & V_157 -> V_50 , F_40 ) ;
V_157 -> V_6 = V_6 ;
V_157 -> V_35 = V_154 ;
V_157 -> V_48 = F_120 ( V_154 ) ;
V_157 -> V_98 = true ;
F_121 ( V_157 -> V_29 , V_23 ) ;
V_157 -> V_83 = V_23 ;
V_157 -> V_16 = V_157 -> V_15 = V_144 ;
V_157 -> V_35 [ 0 ] = 1 ;
V_157 -> V_35 [ 1 ] = V_8 ;
V_157 -> V_35 [ 2 ] = ( V_8 + V_157 -> V_15 ) | 1 ;
V_157 -> V_37 = 2 ;
}
V_5 = V_157 ? : V_156 ;
V_84 +=
F_26 ( V_5 , 1 ) ;
F_33 ( V_5 , - 1 ) ;
V_112 = V_6 ;
return 0 ;
}
static int T_6 F_122 ( char * V_174 )
{
if ( ! V_174 )
return - V_175 ;
if ( 0 )
;
#ifdef F_123
else if ( ! strcmp ( V_174 , L_17 ) )
V_176 = V_177 ;
#endif
#ifdef F_124
else if ( ! strcmp ( V_174 , L_18 ) )
V_176 = V_178 ;
#endif
else
F_75 ( L_19 , V_174 ) ;
return 0 ;
}
static struct V_119 * T_6 F_125 (
T_2 V_143 , T_2 V_144 ,
T_2 V_145 ,
T_8 V_179 )
{
static int V_180 [ V_128 ] V_151 ;
static int V_181 [ V_128 ] V_151 ;
const T_2 V_108 = V_109 - V_110 ;
int V_120 = 1 , V_121 = 0 ;
T_2 V_155 , V_182 , V_141 ;
int V_139 , V_183 , V_184 ( V_185 ) ;
int V_186 , V_137 , V_125 ;
unsigned int V_20 , V_187 ;
struct V_119 * V_122 ;
unsigned int * V_127 ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
V_155 = F_105 ( V_108 + V_143 +
F_30 ( T_2 , V_144 , V_164 ) ) ;
V_144 = V_155 - V_108 - V_143 ;
V_182 = F_30 ( T_2 , V_155 , V_92 ) ;
V_141 = F_126 ( V_182 , V_145 ) ;
V_139 = V_141 / V_182 ;
while ( V_141 % V_139 || ( ( V_141 / V_139 ) & ~ V_163 ) )
V_139 -- ;
V_183 = V_139 ;
F_72 (cpu) {
V_137 = 0 ;
V_188:
F_72 (tcpu) {
if ( V_20 == V_187 )
break;
if ( V_180 [ V_187 ] == V_137 && V_179 &&
( V_179 ( V_20 , V_187 ) > V_189 ||
V_179 ( V_187 , V_20 ) > V_189 ) ) {
V_137 ++ ;
V_120 = F_7 ( V_120 , V_137 + 1 ) ;
goto V_188;
}
}
V_180 [ V_20 ] = V_137 ;
V_181 [ V_137 ] ++ ;
}
V_186 = V_190 ;
for ( V_139 = V_183 ; V_139 ; V_139 -- ) {
int V_191 = 0 , V_192 = 0 ;
if ( V_141 % V_139 || ( ( V_141 / V_139 ) & ~ V_163 ) )
continue;
for ( V_137 = 0 ; V_137 < V_120 ; V_137 ++ ) {
int V_193 = F_127 ( V_181 [ V_137 ] , V_139 ) ;
V_191 += V_193 ;
V_192 += V_193 * V_139 - V_181 [ V_137 ] ;
}
if ( V_192 > F_109 () / 3 )
continue;
if ( V_191 > V_186 )
break;
V_186 = V_191 ;
V_185 = V_139 ;
}
V_139 = V_185 ;
for ( V_137 = 0 ; V_137 < V_120 ; V_137 ++ )
V_121 += F_126 ( V_181 [ V_137 ] , V_139 ) ;
V_122 = F_102 ( V_120 , V_121 ) ;
if ( ! V_122 )
return F_128 ( - V_58 ) ;
V_127 = V_122 -> V_126 [ 0 ] . V_127 ;
for ( V_137 = 0 ; V_137 < V_120 ; V_137 ++ ) {
V_122 -> V_126 [ V_137 ] . V_127 = V_127 ;
V_127 += F_126 ( V_181 [ V_137 ] , V_139 ) ;
}
V_122 -> V_108 = V_108 ;
V_122 -> V_143 = V_143 ;
V_122 -> V_144 = V_144 ;
V_122 -> V_142 = V_141 / V_139 ;
V_122 -> V_145 = V_145 ;
V_122 -> V_141 = V_141 ;
for ( V_137 = 0 , V_125 = 0 ; V_181 [ V_137 ] ; V_137 ++ ) {
struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
V_147 -> V_167 = V_125 * V_122 -> V_142 ;
F_72 (cpu)
if ( V_180 [ V_20 ] == V_137 )
V_147 -> V_127 [ V_147 -> V_121 ++ ] = V_20 ;
V_147 -> V_121 = F_126 ( V_147 -> V_121 , V_139 ) ;
V_125 += V_147 -> V_121 ;
}
F_48 ( V_125 != V_121 ) ;
return V_122 ;
}
int T_6 F_129 ( T_2 V_143 , T_2 V_144 ,
T_2 V_145 ,
T_8 V_179 ,
T_9 V_194 ,
T_10 V_195 )
{
void * V_111 = ( void * ) V_196 ;
void * * V_197 = NULL ;
struct V_119 * V_122 ;
T_2 V_155 , V_198 , V_199 ;
int V_137 , V_33 , V_200 ;
V_122 = F_125 ( V_143 , V_144 , V_145 ,
V_179 ) ;
if ( F_130 ( V_122 ) )
return F_131 ( V_122 ) ;
V_155 = V_122 -> V_108 + V_122 -> V_143 + V_122 -> V_144 ;
V_198 = F_105 ( V_122 -> V_120 * sizeof( void * ) ) ;
V_197 = F_104 ( V_198 , 0 ) ;
if ( ! V_197 ) {
V_200 = - V_58 ;
goto V_201;
}
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ ) {
struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
unsigned int V_20 = V_128 ;
void * V_32 ;
for ( V_33 = 0 ; V_33 < V_147 -> V_121 && V_20 == V_128 ; V_33 ++ )
V_20 = V_147 -> V_127 [ V_33 ] ;
F_48 ( V_20 == V_128 ) ;
V_32 = V_194 ( V_20 , V_147 -> V_121 * V_122 -> V_142 , V_145 ) ;
if ( ! V_32 ) {
V_200 = - V_58 ;
goto V_202;
}
F_132 ( V_32 ) ;
V_197 [ V_137 ] = V_32 ;
V_111 = F_89 ( V_32 , V_111 ) ;
}
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ ) {
struct V_146 * V_147 = & V_122 -> V_126 [ V_137 ] ;
void * V_32 = V_197 [ V_137 ] ;
for ( V_33 = 0 ; V_33 < V_147 -> V_121 ; V_33 ++ , V_32 += V_122 -> V_142 ) {
if ( V_147 -> V_127 [ V_33 ] == V_128 ) {
V_195 ( V_32 , V_122 -> V_142 ) ;
continue;
}
memcpy ( V_32 , V_203 , V_122 -> V_108 ) ;
V_195 ( V_32 + V_155 , V_122 -> V_142 - V_155 ) ;
}
}
V_199 = 0 ;
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ ) {
V_122 -> V_126 [ V_137 ] . V_167 = V_197 [ V_137 ] - V_111 ;
V_199 = F_30 ( T_2 , V_199 ,
V_122 -> V_126 [ V_137 ] . V_167 ) ;
}
V_199 += V_122 -> V_142 ;
if ( V_199 > V_204 * 3 / 4 ) {
F_75 ( L_20
L_21 , V_199 ,
V_204 ) ;
#ifdef F_124
V_200 = - V_175 ;
goto V_201;
#endif
}
F_77 ( L_22 ,
F_31 ( V_155 ) , V_111 , V_122 -> V_108 , V_122 -> V_143 ,
V_122 -> V_144 , V_122 -> V_142 ) ;
V_200 = F_113 ( V_122 , V_111 ) ;
goto V_201;
V_202:
for ( V_137 = 0 ; V_137 < V_122 -> V_120 ; V_137 ++ )
if ( V_197 [ V_137 ] )
V_195 ( V_197 [ V_137 ] ,
V_122 -> V_126 [ V_137 ] . V_121 * V_122 -> V_142 ) ;
V_201:
F_106 ( V_122 ) ;
if ( V_197 )
F_107 ( F_98 ( V_197 ) , V_198 ) ;
return V_200 ;
}
int T_6 F_133 ( T_2 V_143 ,
T_9 V_194 ,
T_10 V_195 ,
T_11 V_205 )
{
static struct V_206 V_207 ;
struct V_119 * V_122 ;
char V_208 [ 16 ] ;
int V_209 ;
T_2 V_210 ;
struct V_17 * * V_211 ;
int V_125 , V_33 , V_78 , V_200 ;
snprintf ( V_208 , sizeof( V_208 ) , L_23 , V_30 >> 10 ) ;
V_122 = F_125 ( V_143 , 0 , V_30 , NULL ) ;
if ( F_130 ( V_122 ) )
return F_131 ( V_122 ) ;
F_48 ( V_122 -> V_120 != 1 ) ;
F_48 ( V_122 -> V_126 [ 0 ] . V_121 != F_109 () ) ;
V_209 = V_122 -> V_142 >> V_25 ;
V_210 = F_105 ( V_209 * F_109 () *
sizeof( V_211 [ 0 ] ) ) ;
V_211 = F_117 ( V_210 , 0 ) ;
V_78 = 0 ;
for ( V_125 = 0 ; V_125 < F_109 () ; V_125 ++ )
for ( V_33 = 0 ; V_33 < V_209 ; V_33 ++ ) {
unsigned int V_20 = V_122 -> V_126 [ 0 ] . V_127 [ V_125 ] ;
void * V_32 ;
V_32 = V_194 ( V_20 , V_30 , V_30 ) ;
if ( ! V_32 ) {
F_75 ( L_24
L_25 , V_208 , V_20 ) ;
goto V_212;
}
F_132 ( V_32 ) ;
V_211 [ V_78 ++ ] = F_134 ( V_32 ) ;
}
V_207 . V_57 = V_213 ;
V_207 . V_9 = F_109 () * V_122 -> V_142 ;
F_135 ( & V_207 , V_30 ) ;
for ( V_125 = 0 ; V_125 < F_109 () ; V_125 ++ ) {
unsigned long V_214 =
( unsigned long ) V_207 . V_3 + V_125 * V_122 -> V_142 ;
for ( V_33 = 0 ; V_33 < V_209 ; V_33 ++ )
V_205 ( V_214 + ( V_33 << V_25 ) ) ;
V_200 = F_136 ( V_214 , & V_211 [ V_125 * V_209 ] ,
V_209 ) ;
if ( V_200 < 0 )
F_137 ( L_26 , V_200 ) ;
memcpy ( ( void * ) V_214 , V_203 , V_122 -> V_108 ) ;
}
F_77 ( L_27 ,
V_209 , V_208 , V_207 . V_3 , V_122 -> V_108 ,
V_122 -> V_143 , V_122 -> V_144 ) ;
V_200 = F_113 ( V_122 , V_207 . V_3 ) ;
goto V_215;
V_212:
while ( -- V_78 >= 0 )
V_195 ( F_138 ( V_211 [ V_78 ] ) , V_30 ) ;
V_200 = - V_58 ;
V_215:
F_107 ( F_98 ( V_211 ) , V_210 ) ;
F_106 ( V_122 ) ;
return V_200 ;
}
static void * T_6 F_139 ( unsigned int V_20 , T_2 V_9 ,
T_2 V_64 )
{
return F_140 (
V_9 , V_64 , F_98 ( V_216 ) ) ;
}
static void T_6 F_141 ( void * V_32 , T_2 V_9 )
{
F_107 ( F_98 ( V_32 ) , V_9 ) ;
}
void T_6 F_142 ( void )
{
unsigned long V_217 ;
unsigned int V_20 ;
int V_200 ;
V_200 = F_129 ( V_218 ,
V_219 , V_30 , NULL ,
F_139 , F_141 ) ;
if ( V_200 < 0 )
F_137 ( L_28 ) ;
V_217 = ( unsigned long ) V_112 - ( unsigned long ) V_110 ;
F_72 (cpu)
V_220 [ V_20 ] = V_217 + V_24 [ V_20 ] ;
}
void T_6 F_142 ( void )
{
const T_2 V_142 =
F_143 ( F_30 ( T_2 , V_92 ,
V_219 ) ) ;
struct V_119 * V_122 ;
void * V_221 ;
V_122 = F_102 ( 1 , 1 ) ;
V_221 = F_140 ( V_142 ,
V_30 ,
F_98 ( V_216 ) ) ;
if ( ! V_122 || ! V_221 )
F_137 ( L_29 ) ;
F_132 ( V_221 ) ;
V_122 -> V_144 = V_142 ;
V_122 -> V_142 = V_142 ;
V_122 -> V_145 = V_142 ;
V_122 -> V_141 = V_142 ;
V_122 -> V_126 [ 0 ] . V_121 = 1 ;
V_122 -> V_126 [ 0 ] . V_127 [ 0 ] = 0 ;
if ( F_113 ( V_122 , V_221 ) < 0 )
F_137 ( L_28 ) ;
}
void T_6 F_144 ( void )
{
struct V_13 * V_222 [] =
{ V_5 , V_42 , NULL } ;
struct V_13 * V_14 ;
unsigned long V_57 ;
int V_33 ;
for ( V_33 = 0 ; ( V_14 = V_222 [ V_33 ] ) ; V_33 ++ ) {
int * V_35 ;
const T_2 V_9 = V_153 * sizeof( V_35 [ 0 ] ) ;
F_145 ( V_9 > V_30 ) ;
V_35 = F_18 ( V_9 ) ;
F_48 ( ! V_35 ) ;
F_38 ( & V_59 , V_57 ) ;
memcpy ( V_35 , V_14 -> V_35 , V_9 ) ;
V_14 -> V_35 = V_35 ;
F_39 ( & V_59 , V_57 ) ;
}
}
static int T_6 F_146 ( void )
{
V_1 = true ;
return 0 ;
}
