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
F_36 ( & V_48 ) ;
F_46 ( V_14 ) ;
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
V_14 -> V_82 = false ;
F_49 ( & V_14 -> V_43 ) ;
F_49 ( & V_14 -> V_51 ) ;
V_14 -> V_15 = V_7 ;
V_14 -> V_16 = V_7 ;
return V_14 ;
}
static void F_50 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return;
F_23 ( V_14 -> V_35 ) ;
F_23 ( V_14 ) ;
}
static void F_51 ( struct V_13 * V_14 ,
int V_68 , int V_69 )
{
int V_83 = V_69 - V_68 ;
F_36 ( & V_48 ) ;
F_52 ( V_14 -> V_29 , V_68 , V_83 ) ;
V_14 -> V_84 += V_83 ;
V_85 += V_83 ;
}
static void F_53 ( struct V_13 * V_14 ,
int V_68 , int V_69 )
{
int V_83 = V_69 - V_68 ;
F_36 ( & V_48 ) ;
F_54 ( V_14 -> V_29 , V_68 , V_83 ) ;
V_14 -> V_84 -= V_83 ;
V_85 -= V_83 ;
}
static struct V_13 * F_55 ( void * V_3 )
{
if ( F_3 ( V_3 ) ) {
if ( F_4 ( V_3 ) )
return V_42 ;
return V_5 ;
}
V_3 += V_24 [ F_56 () ] ;
return F_11 ( F_57 ( V_3 ) ) ;
}
static void T_3 * F_58 ( T_2 V_9 , T_2 V_64 , bool V_86 ,
T_4 V_87 )
{
static int V_88 = 10 ;
struct V_13 * V_14 ;
const char * V_89 ;
bool V_45 = ( V_87 & V_31 ) != V_31 ;
int V_90 = 0 ;
int V_91 , V_34 , V_47 , V_20 , V_92 ;
unsigned long V_59 ;
void T_3 * V_32 ;
if ( F_59 ( V_64 < 2 ) )
V_64 = 2 ;
V_9 = F_43 ( V_9 , 2 ) ;
if ( F_59 ( ! V_9 || V_9 > V_93 || V_64 > V_30 ||
! F_60 ( V_64 ) ) ) {
F_61 ( true , L_1 ,
V_9 , V_64 ) ;
return NULL ;
}
if ( ! V_45 )
F_62 ( & V_60 ) ;
F_40 ( & V_48 , V_59 ) ;
if ( V_86 && V_42 ) {
V_14 = V_42 ;
if ( V_9 > V_14 -> V_16 ) {
V_89 = L_2 ;
goto V_94;
}
while ( ( V_47 = F_35 ( V_14 , V_45 ) ) ) {
F_41 ( & V_48 , V_59 ) ;
if ( V_45 ||
F_39 ( V_14 , V_47 ) < 0 ) {
V_89 = L_3 ;
goto V_95;
}
F_40 ( & V_48 , V_59 ) ;
}
V_34 = F_44 ( V_14 , V_9 , V_64 , V_45 ,
& V_90 ) ;
if ( V_34 >= 0 )
goto V_96;
V_89 = L_2 ;
goto V_94;
}
V_97:
for ( V_91 = F_8 ( V_9 ) ; V_91 < V_12 ; V_91 ++ ) {
F_63 (chunk, &pcpu_slot[slot], list) {
if ( V_9 > V_14 -> V_16 )
continue;
V_47 = F_35 ( V_14 , V_45 ) ;
if ( V_47 ) {
if ( V_45 )
continue;
F_41 ( & V_48 , V_59 ) ;
if ( F_39 ( V_14 ,
V_47 ) < 0 ) {
V_89 = L_4 ;
goto V_95;
}
F_40 ( & V_48 , V_59 ) ;
goto V_97;
}
V_34 = F_44 ( V_14 , V_9 , V_64 , V_45 ,
& V_90 ) ;
if ( V_34 >= 0 )
goto V_96;
}
}
F_41 ( & V_48 , V_59 ) ;
if ( V_45 ) {
V_89 = L_5 ;
goto V_95;
}
if ( F_37 ( & V_44 [ V_12 - 1 ] ) ) {
V_14 = F_64 () ;
if ( ! V_14 ) {
V_89 = L_6 ;
goto V_95;
}
F_40 ( & V_48 , V_59 ) ;
F_32 ( V_14 , - 1 ) ;
} else {
F_40 ( & V_48 , V_59 ) ;
}
goto V_97;
V_96:
F_65 ( V_14 , V_9 ) ;
F_41 ( & V_48 , V_59 ) ;
if ( ! V_45 ) {
int V_68 , V_69 , V_26 , V_27 ;
V_68 = F_30 ( V_34 ) ;
V_69 = F_31 ( V_34 + V_9 ) ;
F_66 (chunk, rs, re, page_start, page_end) {
F_67 ( V_14 -> V_98 ) ;
V_92 = F_68 ( V_14 , V_26 , V_27 ) ;
F_40 ( & V_48 , V_59 ) ;
if ( V_92 ) {
F_45 ( V_14 , V_34 , & V_90 ) ;
V_89 = L_7 ;
goto V_94;
}
F_51 ( V_14 , V_26 , V_27 ) ;
F_41 ( & V_48 , V_59 ) ;
}
F_69 ( & V_60 ) ;
}
if ( V_14 != V_42 ) {
F_40 ( & V_48 , V_59 ) ;
V_85 -= V_90 ;
F_41 ( & V_48 , V_59 ) ;
}
if ( V_85 < V_99 )
F_1 () ;
F_70 (cpu)
memset ( ( void * ) F_13 ( V_14 , V_20 , 0 ) + V_34 , 0 , V_9 ) ;
V_32 = F_71 ( V_14 -> V_6 + V_34 ) ;
F_72 ( V_32 , V_9 , V_87 ) ;
F_73 ( V_86 , V_45 , V_9 , V_64 ,
V_14 -> V_6 , V_34 , V_32 ) ;
return V_32 ;
V_94:
F_41 ( & V_48 , V_59 ) ;
V_95:
F_74 ( V_86 , V_45 , V_9 , V_64 ) ;
if ( ! V_45 && V_88 ) {
F_75 ( L_8 ,
V_9 , V_64 , V_45 , V_89 ) ;
F_76 () ;
if ( ! -- V_88 )
F_77 ( L_9 ) ;
}
if ( V_45 ) {
V_100 = true ;
F_1 () ;
} else {
F_69 ( & V_60 ) ;
}
return NULL ;
}
void T_3 * F_78 ( T_2 V_9 , T_2 V_64 , T_4 V_87 )
{
return F_58 ( V_9 , V_64 , false , V_87 ) ;
}
void T_3 * F_79 ( T_2 V_9 , T_2 V_64 )
{
return F_58 ( V_9 , V_64 , false , V_31 ) ;
}
void T_3 * F_80 ( T_2 V_9 , T_2 V_64 )
{
return F_58 ( V_9 , V_64 , true , V_31 ) ;
}
static void F_81 ( struct V_101 * V_102 )
{
F_82 ( V_79 ) ;
struct V_103 * V_104 = & V_44 [ V_12 - 1 ] ;
struct V_13 * V_14 , * V_38 ;
int V_91 , V_105 , V_92 ;
F_62 ( & V_60 ) ;
F_83 ( & V_48 ) ;
F_84 (chunk, next, free_head, list) {
F_67 ( V_14 -> V_98 ) ;
if ( V_14 == F_85 ( V_104 , struct V_13 , V_43 ) )
continue;
F_86 ( & V_14 -> V_51 ) ;
F_33 ( & V_14 -> V_43 , & V_79 ) ;
}
F_87 ( & V_48 ) ;
F_84 (chunk, next, &to_free, list) {
int V_26 , V_27 ;
F_88 (chunk, rs, re, 0 , pcpu_unit_pages) {
F_89 ( V_14 , V_26 , V_27 ) ;
F_83 ( & V_48 ) ;
F_53 ( V_14 , V_26 , V_27 ) ;
F_87 ( & V_48 ) ;
}
F_90 ( V_14 ) ;
}
do {
int V_47 = 0 ;
F_83 ( & V_48 ) ;
V_14 = F_91 ( & V_52 ,
struct V_13 , V_51 ) ;
if ( V_14 ) {
F_86 ( & V_14 -> V_51 ) ;
V_47 = F_35 ( V_14 , false ) ;
}
F_87 ( & V_48 ) ;
if ( V_47 )
F_39 ( V_14 , V_47 ) ;
} while ( V_14 );
V_106:
if ( V_100 ) {
V_105 = V_107 ;
V_100 = false ;
} else {
V_105 = F_92 ( V_107 -
V_85 ,
0 , V_107 ) ;
}
for ( V_91 = F_8 ( V_30 ) ; V_91 < V_12 ; V_91 ++ ) {
int V_108 = 0 , V_26 , V_27 ;
if ( ! V_105 )
break;
F_83 ( & V_48 ) ;
F_63 (chunk, &pcpu_slot[slot], list) {
V_108 = V_23 - V_14 -> V_84 ;
if ( V_108 )
break;
}
F_87 ( & V_48 ) ;
if ( ! V_108 )
continue;
F_66 (chunk, rs, re, 0 , pcpu_unit_pages) {
int V_83 = F_93 ( V_27 - V_26 , V_105 ) ;
V_92 = F_68 ( V_14 , V_26 , V_26 + V_83 ) ;
if ( ! V_92 ) {
V_105 -= V_83 ;
F_83 ( & V_48 ) ;
F_51 ( V_14 , V_26 , V_26 + V_83 ) ;
F_87 ( & V_48 ) ;
} else {
V_105 = 0 ;
}
if ( ! V_105 )
break;
}
}
if ( V_105 ) {
V_14 = F_64 () ;
if ( V_14 ) {
F_83 ( & V_48 ) ;
F_32 ( V_14 , - 1 ) ;
F_87 ( & V_48 ) ;
goto V_106;
}
}
F_69 ( & V_60 ) ;
}
void F_94 ( void T_3 * V_32 )
{
void * V_3 ;
struct V_13 * V_14 ;
unsigned long V_59 ;
int V_34 , V_90 ;
if ( ! V_32 )
return;
F_95 ( V_32 ) ;
V_3 = F_96 ( V_32 ) ;
F_40 ( & V_48 , V_59 ) ;
V_14 = F_55 ( V_3 ) ;
V_34 = V_3 - V_14 -> V_6 ;
F_45 ( V_14 , V_34 , & V_90 ) ;
if ( V_14 != V_42 )
V_85 += V_90 ;
if ( V_14 -> V_15 == V_7 ) {
struct V_13 * V_109 ;
F_63 (pos, &pcpu_slot[pcpu_nr_slots - 1], list)
if ( V_109 != V_14 ) {
F_1 () ;
break;
}
}
F_97 ( V_14 -> V_6 , V_34 , V_32 ) ;
F_41 ( & V_48 , V_59 ) ;
}
bool F_98 ( unsigned long V_3 , unsigned long * V_110 )
{
#ifdef F_99
const T_2 V_111 = V_112 - V_113 ;
void T_3 * V_114 = F_71 ( V_115 ) ;
unsigned int V_20 ;
F_70 (cpu) {
void * V_116 = F_100 ( V_114 , V_20 ) ;
void * V_117 = ( void * ) V_3 ;
if ( V_117 >= V_116 && V_117 < V_116 + V_111 ) {
if ( V_110 ) {
* V_110 = ( unsigned long ) ( V_117 - V_116 ) ;
* V_110 += ( unsigned long )
F_100 ( V_114 , F_101 () ) ;
}
return true ;
}
}
#endif
return false ;
}
bool F_102 ( unsigned long V_3 )
{
return F_98 ( V_3 , NULL ) ;
}
T_5 F_103 ( void * V_3 )
{
void T_3 * V_114 = F_71 ( V_115 ) ;
bool V_118 = false ;
unsigned long V_119 , V_120 ;
unsigned int V_20 ;
V_119 = F_13 ( V_5 , V_121 , 0 ) ;
V_120 = F_13 ( V_5 , V_122 ,
V_23 ) ;
if ( ( unsigned long ) V_3 >= V_119 &&
( unsigned long ) V_3 < V_120 ) {
F_70 (cpu) {
void * V_116 = F_100 ( V_114 , V_20 ) ;
if ( V_3 >= V_116 && V_3 < V_116 + V_7 ) {
V_118 = true ;
break;
}
}
}
if ( V_118 ) {
if ( ! F_104 ( V_3 ) )
return F_105 ( V_3 ) ;
else
return F_106 ( F_107 ( V_3 ) ) +
F_108 ( V_3 ) ;
} else
return F_106 ( F_57 ( V_3 ) ) +
F_108 ( V_3 ) ;
}
struct V_123 * T_6 F_109 ( int V_124 ,
int V_125 )
{
struct V_123 * V_126 ;
T_2 V_127 , V_128 ;
void * V_32 ;
int V_129 ;
V_127 = F_43 ( sizeof( * V_126 ) + V_124 * sizeof( V_126 -> V_130 [ 0 ] ) ,
F_110 ( V_126 -> V_130 [ 0 ] . V_131 [ 0 ] ) ) ;
V_128 = V_127 + V_125 * sizeof( V_126 -> V_130 [ 0 ] . V_131 [ 0 ] ) ;
V_32 = F_111 ( F_112 ( V_128 ) , 0 ) ;
if ( ! V_32 )
return NULL ;
V_126 = V_32 ;
V_32 += V_127 ;
V_126 -> V_130 [ 0 ] . V_131 = V_32 ;
for ( V_129 = 0 ; V_129 < V_125 ; V_129 ++ )
V_126 -> V_130 [ 0 ] . V_131 [ V_129 ] = V_132 ;
V_126 -> V_124 = V_124 ;
V_126 -> V_133 = F_112 ( V_128 ) ;
return V_126 ;
}
void T_6 F_113 ( struct V_123 * V_126 )
{
F_114 ( F_105 ( V_126 ) , V_126 -> V_133 ) ;
}
static void F_115 ( const char * V_134 ,
const struct V_123 * V_126 )
{
int V_135 = 1 , V_136 = 1 , V_137 ;
char V_138 [] = L_10 ;
int V_139 = 0 , V_140 = 0 ;
int V_141 , V_142 ;
int V_143 , V_144 ;
V_142 = V_126 -> V_124 ;
while ( V_142 /= 10 )
V_135 ++ ;
V_142 = F_116 () ;
while ( V_142 /= 10 )
V_136 ++ ;
V_138 [ F_117 ( int , V_136 , sizeof( V_138 ) - 1 ) ] = '\0' ;
V_143 = V_126 -> V_145 / V_126 -> V_146 ;
V_137 = V_143 * ( V_136 + 1 ) + V_135 + 3 ;
V_144 = F_118 ( F_7 ( 60 / V_137 , 1 ) ) ;
F_119 ( L_11 ,
V_134 , V_126 -> V_111 , V_126 -> V_147 , V_126 -> V_148 ,
V_126 -> V_146 , V_126 -> V_145 / V_126 -> V_149 , V_126 -> V_149 ) ;
for ( V_141 = 0 ; V_141 < V_126 -> V_124 ; V_141 ++ ) {
const struct V_150 * V_151 = & V_126 -> V_130 [ V_141 ] ;
int V_129 = 0 , V_152 = 0 ;
F_47 ( V_151 -> V_125 % V_143 ) ;
for ( V_140 += V_151 -> V_125 / V_143 ;
V_139 < V_140 ; V_139 ++ ) {
if ( ! ( V_139 % V_144 ) ) {
F_120 ( L_12 ) ;
F_119 ( L_13 , V_134 ) ;
}
F_120 ( L_14 , V_135 , V_141 ) ;
for ( V_152 += V_143 ; V_129 < V_152 ; V_129 ++ )
if ( V_151 -> V_131 [ V_129 ] != V_132 )
F_120 ( L_15 ,
V_136 , V_151 -> V_131 [ V_129 ] ) ;
else
F_120 ( L_16 , V_138 ) ;
}
}
F_120 ( L_12 ) ;
}
int T_6 F_121 ( const struct V_123 * V_126 ,
void * V_6 )
{
static int V_153 [ V_154 ] V_155 ;
static int V_156 [ V_154 ] V_155 ;
T_2 V_148 = V_126 -> V_148 ;
T_2 V_157 = V_126 -> V_111 + V_126 -> V_147 + V_148 ;
struct V_13 * V_158 , * V_159 = NULL ;
unsigned long * V_160 ;
T_2 * V_161 ;
unsigned long * V_162 ;
unsigned int V_20 ;
int * V_163 ;
int V_141 , V_129 , V_33 ;
#define F_122 ( T_7 ) do { \
if (unlikely(cond)) { \
pr_emerg("failed to initialize, %s\n", #cond); \
pr_emerg("cpu_possible_mask=%*pb\n", \
cpumask_pr_args(cpu_possible_mask)); \
pcpu_dump_alloc_info(KERN_EMERG, ai); \
BUG(); \
} \
} while (0)
F_122 ( V_126 -> V_124 <= 0 ) ;
#ifdef F_99
F_122 ( ! V_126 -> V_111 ) ;
F_122 ( F_108 ( V_113 ) ) ;
#endif
F_122 ( ! V_6 ) ;
F_122 ( F_108 ( V_6 ) ) ;
F_122 ( V_126 -> V_146 < V_157 ) ;
F_122 ( F_108 ( V_126 -> V_146 ) ) ;
F_122 ( V_126 -> V_146 < V_93 ) ;
F_122 ( V_126 -> V_148 < V_164 ) ;
F_122 ( F_123 ( V_126 ) < 0 ) ;
V_160 = F_124 ( V_126 -> V_124 *
sizeof( V_160 [ 0 ] ) , 0 ) ;
V_161 = F_124 ( V_126 -> V_124 *
sizeof( V_161 [ 0 ] ) , 0 ) ;
V_163 = F_124 ( V_165 * sizeof( V_163 [ 0 ] ) , 0 ) ;
V_162 = F_124 ( V_165 * sizeof( V_162 [ 0 ] ) , 0 ) ;
for ( V_20 = 0 ; V_20 < V_165 ; V_20 ++ )
V_163 [ V_20 ] = V_166 ;
V_121 = V_132 ;
V_122 = V_132 ;
for ( V_141 = 0 , V_129 = 0 ; V_141 < V_126 -> V_124 ; V_141 ++ , V_129 += V_33 ) {
const struct V_150 * V_151 = & V_126 -> V_130 [ V_141 ] ;
V_160 [ V_141 ] = V_151 -> V_167 ;
V_161 [ V_141 ] = V_151 -> V_125 * V_126 -> V_146 ;
for ( V_33 = 0 ; V_33 < V_151 -> V_125 ; V_33 ++ ) {
V_20 = V_151 -> V_131 [ V_33 ] ;
if ( V_20 == V_132 )
continue;
F_122 ( V_20 >= V_165 ) ;
F_122 ( ! F_125 ( V_20 ) ) ;
F_122 ( V_163 [ V_20 ] != V_166 ) ;
V_163 [ V_20 ] = V_129 + V_33 ;
V_162 [ V_20 ] = V_151 -> V_167 + V_33 * V_126 -> V_146 ;
if ( V_121 == V_132 ||
V_162 [ V_20 ] < V_162 [ V_121 ] )
V_121 = V_20 ;
if ( V_122 == V_132 ||
V_162 [ V_20 ] > V_162 [ V_122 ] )
V_122 = V_20 ;
}
}
V_168 = V_129 ;
F_70 (cpu)
F_122 ( V_163 [ V_20 ] == V_166 ) ;
#undef F_122
F_115 ( V_169 , V_126 ) ;
V_170 = V_126 -> V_124 ;
V_171 = V_160 ;
V_172 = V_161 ;
V_22 = V_163 ;
V_24 = V_162 ;
V_23 = V_126 -> V_146 >> V_25 ;
V_7 = V_23 << V_25 ;
V_173 = V_126 -> V_149 ;
V_81 = sizeof( struct V_13 ) +
F_126 ( V_23 ) * sizeof( unsigned long ) ;
F_127 ( V_126 ) ;
V_12 = F_5 ( V_7 ) + 2 ;
V_44 = F_124 (
V_12 * sizeof( V_44 [ 0 ] ) , 0 ) ;
for ( V_33 = 0 ; V_33 < V_12 ; V_33 ++ )
F_49 ( & V_44 [ V_33 ] ) ;
V_158 = F_124 ( V_81 , 0 ) ;
F_49 ( & V_158 -> V_43 ) ;
F_49 ( & V_158 -> V_51 ) ;
V_158 -> V_6 = V_6 ;
V_158 -> V_35 = V_153 ;
V_158 -> V_49 = F_128 ( V_153 ) ;
V_158 -> V_98 = true ;
F_129 ( V_158 -> V_29 , V_23 ) ;
V_158 -> V_84 = V_23 ;
if ( V_126 -> V_147 ) {
V_158 -> V_15 = V_126 -> V_147 ;
V_42 = V_158 ;
V_8 = V_126 -> V_111 + V_126 -> V_147 ;
} else {
V_158 -> V_15 = V_148 ;
V_148 = 0 ;
}
V_158 -> V_16 = V_158 -> V_15 ;
V_158 -> V_35 [ 0 ] = 1 ;
V_158 -> V_35 [ 1 ] = V_126 -> V_111 ;
V_158 -> V_37 = 1 ;
if ( V_158 -> V_15 )
V_158 -> V_35 [ ++ V_158 -> V_37 ] = V_126 -> V_111 + V_158 -> V_15 ;
V_158 -> V_35 [ V_158 -> V_37 ] |= 1 ;
V_158 -> V_82 = true ;
if ( V_148 ) {
V_159 = F_124 ( V_81 , 0 ) ;
F_49 ( & V_159 -> V_43 ) ;
F_49 ( & V_159 -> V_51 ) ;
V_159 -> V_6 = V_6 ;
V_159 -> V_35 = V_156 ;
V_159 -> V_49 = F_128 ( V_156 ) ;
V_159 -> V_98 = true ;
F_129 ( V_159 -> V_29 , V_23 ) ;
V_159 -> V_84 = V_23 ;
V_159 -> V_16 = V_159 -> V_15 = V_148 ;
V_159 -> V_35 [ 0 ] = 1 ;
V_159 -> V_35 [ 1 ] = V_8 ;
V_159 -> V_35 [ 2 ] = ( V_8 + V_159 -> V_15 ) | 1 ;
V_159 -> V_37 = 2 ;
V_159 -> V_82 = true ;
}
V_5 = V_159 ? : V_158 ;
V_85 +=
F_25 ( V_5 , 1 ) ;
F_32 ( V_5 , - 1 ) ;
F_130 () ;
F_131 ( V_6 ) ;
V_115 = V_6 ;
return 0 ;
}
static int T_6 F_132 ( char * V_174 )
{
if ( ! V_174 )
return - V_175 ;
if ( 0 )
;
#ifdef F_133
else if ( ! strcmp ( V_174 , L_17 ) )
V_176 = V_177 ;
#endif
#ifdef F_134
else if ( ! strcmp ( V_174 , L_18 ) )
V_176 = V_178 ;
#endif
else
F_75 ( L_19 , V_174 ) ;
return 0 ;
}
static struct V_123 * T_6 F_135 (
T_2 V_147 , T_2 V_148 ,
T_2 V_149 ,
T_8 V_179 )
{
static int V_180 [ V_132 ] V_155 ;
static int V_181 [ V_132 ] V_155 ;
const T_2 V_111 = V_112 - V_113 ;
int V_124 = 1 , V_125 = 0 ;
T_2 V_157 , V_182 , V_145 ;
int V_143 , V_183 , V_184 ( V_185 ) ;
int V_186 , V_141 , V_129 ;
unsigned int V_20 , V_187 ;
struct V_123 * V_126 ;
unsigned int * V_131 ;
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
V_157 = F_112 ( V_111 + V_147 +
F_29 ( T_2 , V_148 , V_164 ) ) ;
V_148 = V_157 - V_111 - V_147 ;
V_182 = F_29 ( T_2 , V_157 , V_93 ) ;
V_145 = F_136 ( V_182 , V_149 ) ;
V_143 = V_145 / V_182 ;
while ( V_145 % V_143 || ( F_108 ( V_145 / V_143 ) ) )
V_143 -- ;
V_183 = V_143 ;
F_70 (cpu) {
V_141 = 0 ;
V_188:
F_70 (tcpu) {
if ( V_20 == V_187 )
break;
if ( V_180 [ V_187 ] == V_141 && V_179 &&
( V_179 ( V_20 , V_187 ) > V_189 ||
V_179 ( V_187 , V_20 ) > V_189 ) ) {
V_141 ++ ;
V_124 = F_7 ( V_124 , V_141 + 1 ) ;
goto V_188;
}
}
V_180 [ V_20 ] = V_141 ;
V_181 [ V_141 ] ++ ;
}
V_186 = V_190 ;
for ( V_143 = V_183 ; V_143 ; V_143 -- ) {
int V_191 = 0 , V_192 = 0 ;
if ( V_145 % V_143 || ( F_108 ( V_145 / V_143 ) ) )
continue;
for ( V_141 = 0 ; V_141 < V_124 ; V_141 ++ ) {
int V_193 = F_137 ( V_181 [ V_141 ] , V_143 ) ;
V_191 += V_193 ;
V_192 += V_193 * V_143 - V_181 [ V_141 ] ;
}
if ( V_192 > F_116 () / 3 )
continue;
if ( V_191 > V_186 )
break;
V_186 = V_191 ;
V_185 = V_143 ;
}
V_143 = V_185 ;
for ( V_141 = 0 ; V_141 < V_124 ; V_141 ++ )
V_125 += F_136 ( V_181 [ V_141 ] , V_143 ) ;
V_126 = F_109 ( V_124 , V_125 ) ;
if ( ! V_126 )
return F_138 ( - V_61 ) ;
V_131 = V_126 -> V_130 [ 0 ] . V_131 ;
for ( V_141 = 0 ; V_141 < V_124 ; V_141 ++ ) {
V_126 -> V_130 [ V_141 ] . V_131 = V_131 ;
V_131 += F_136 ( V_181 [ V_141 ] , V_143 ) ;
}
V_126 -> V_111 = V_111 ;
V_126 -> V_147 = V_147 ;
V_126 -> V_148 = V_148 ;
V_126 -> V_146 = V_145 / V_143 ;
V_126 -> V_149 = V_149 ;
V_126 -> V_145 = V_145 ;
for ( V_141 = 0 , V_129 = 0 ; V_181 [ V_141 ] ; V_141 ++ ) {
struct V_150 * V_151 = & V_126 -> V_130 [ V_141 ] ;
V_151 -> V_167 = V_129 * V_126 -> V_146 ;
F_70 (cpu)
if ( V_180 [ V_20 ] == V_141 )
V_151 -> V_131 [ V_151 -> V_125 ++ ] = V_20 ;
V_151 -> V_125 = F_136 ( V_151 -> V_125 , V_143 ) ;
V_129 += V_151 -> V_125 ;
}
F_47 ( V_129 != V_125 ) ;
return V_126 ;
}
int T_6 F_139 ( T_2 V_147 , T_2 V_148 ,
T_2 V_149 ,
T_8 V_179 ,
T_9 V_194 ,
T_10 V_195 )
{
void * V_114 = ( void * ) V_196 ;
void * * V_197 = NULL ;
struct V_123 * V_126 ;
T_2 V_157 , V_198 ;
unsigned long V_199 ;
int V_141 , V_33 , V_200 , V_201 ;
V_126 = F_135 ( V_147 , V_148 , V_149 ,
V_179 ) ;
if ( F_140 ( V_126 ) )
return F_141 ( V_126 ) ;
V_157 = V_126 -> V_111 + V_126 -> V_147 + V_126 -> V_148 ;
V_198 = F_112 ( V_126 -> V_124 * sizeof( void * ) ) ;
V_197 = F_111 ( V_198 , 0 ) ;
if ( ! V_197 ) {
V_201 = - V_61 ;
goto V_202;
}
V_200 = 0 ;
for ( V_141 = 0 ; V_141 < V_126 -> V_124 ; V_141 ++ ) {
struct V_150 * V_151 = & V_126 -> V_130 [ V_141 ] ;
unsigned int V_20 = V_132 ;
void * V_32 ;
for ( V_33 = 0 ; V_33 < V_151 -> V_125 && V_20 == V_132 ; V_33 ++ )
V_20 = V_151 -> V_131 [ V_33 ] ;
F_47 ( V_20 == V_132 ) ;
V_32 = V_194 ( V_20 , V_151 -> V_125 * V_126 -> V_146 , V_149 ) ;
if ( ! V_32 ) {
V_201 = - V_61 ;
goto V_203;
}
F_142 ( V_32 ) ;
V_197 [ V_141 ] = V_32 ;
V_114 = F_93 ( V_32 , V_114 ) ;
if ( V_32 > V_197 [ V_200 ] )
V_200 = V_141 ;
}
V_199 = V_197 [ V_200 ] - V_114 ;
V_199 += V_126 -> V_146 * V_126 -> V_130 [ V_200 ] . V_125 ;
if ( V_199 > V_204 * 3 / 4 ) {
F_75 ( L_20 ,
V_199 , V_204 ) ;
#ifdef F_134
V_201 = - V_175 ;
goto V_203;
#endif
}
for ( V_141 = 0 ; V_141 < V_126 -> V_124 ; V_141 ++ ) {
struct V_150 * V_151 = & V_126 -> V_130 [ V_141 ] ;
void * V_32 = V_197 [ V_141 ] ;
for ( V_33 = 0 ; V_33 < V_151 -> V_125 ; V_33 ++ , V_32 += V_126 -> V_146 ) {
if ( V_151 -> V_131 [ V_33 ] == V_132 ) {
V_195 ( V_32 , V_126 -> V_146 ) ;
continue;
}
memcpy ( V_32 , V_205 , V_126 -> V_111 ) ;
V_195 ( V_32 + V_157 , V_126 -> V_146 - V_157 ) ;
}
}
for ( V_141 = 0 ; V_141 < V_126 -> V_124 ; V_141 ++ ) {
V_126 -> V_130 [ V_141 ] . V_167 = V_197 [ V_141 ] - V_114 ;
}
F_77 ( L_21 ,
F_30 ( V_157 ) , V_114 , V_126 -> V_111 , V_126 -> V_147 ,
V_126 -> V_148 , V_126 -> V_146 ) ;
V_201 = F_121 ( V_126 , V_114 ) ;
goto V_202;
V_203:
for ( V_141 = 0 ; V_141 < V_126 -> V_124 ; V_141 ++ )
if ( V_197 [ V_141 ] )
V_195 ( V_197 [ V_141 ] ,
V_126 -> V_130 [ V_141 ] . V_125 * V_126 -> V_146 ) ;
V_202:
F_113 ( V_126 ) ;
if ( V_197 )
F_114 ( F_105 ( V_197 ) , V_198 ) ;
return V_201 ;
}
int T_6 F_143 ( T_2 V_147 ,
T_9 V_194 ,
T_10 V_195 ,
T_11 V_206 )
{
static struct V_207 V_208 ;
struct V_123 * V_126 ;
char V_209 [ 16 ] ;
int V_210 ;
T_2 V_211 ;
struct V_17 * * V_212 ;
int V_129 , V_33 , V_78 , V_201 ;
int V_143 ;
int V_213 ;
snprintf ( V_209 , sizeof( V_209 ) , L_22 , V_30 >> 10 ) ;
V_126 = F_135 ( V_147 , 0 , V_30 , NULL ) ;
if ( F_140 ( V_126 ) )
return F_141 ( V_126 ) ;
F_47 ( V_126 -> V_124 != 1 ) ;
V_143 = V_126 -> V_145 / V_126 -> V_146 ;
V_213 = F_136 ( F_116 () , V_143 ) ;
if ( F_59 ( F_67 ( V_126 -> V_130 [ 0 ] . V_125 != V_213 ) ) ) {
F_113 ( V_126 ) ;
return - V_175 ;
}
V_210 = V_126 -> V_146 >> V_25 ;
V_211 = F_112 ( V_210 * F_116 () *
sizeof( V_212 [ 0 ] ) ) ;
V_212 = F_124 ( V_211 , 0 ) ;
V_78 = 0 ;
for ( V_129 = 0 ; V_129 < F_116 () ; V_129 ++ ) {
unsigned int V_20 = V_126 -> V_130 [ 0 ] . V_131 [ V_129 ] ;
for ( V_33 = 0 ; V_33 < V_210 ; V_33 ++ ) {
void * V_32 ;
V_32 = V_194 ( V_20 , V_30 , V_30 ) ;
if ( ! V_32 ) {
F_75 ( L_23 ,
V_209 , V_20 ) ;
goto V_214;
}
F_142 ( V_32 ) ;
V_212 [ V_78 ++ ] = F_144 ( V_32 ) ;
}
}
V_208 . V_59 = V_215 ;
V_208 . V_9 = F_116 () * V_126 -> V_146 ;
F_145 ( & V_208 , V_30 ) ;
for ( V_129 = 0 ; V_129 < F_116 () ; V_129 ++ ) {
unsigned long V_216 =
( unsigned long ) V_208 . V_3 + V_129 * V_126 -> V_146 ;
for ( V_33 = 0 ; V_33 < V_210 ; V_33 ++ )
V_206 ( V_216 + ( V_33 << V_25 ) ) ;
V_201 = F_146 ( V_216 , & V_212 [ V_129 * V_210 ] ,
V_210 ) ;
if ( V_201 < 0 )
F_147 ( L_24 , V_201 ) ;
memcpy ( ( void * ) V_216 , V_205 , V_126 -> V_111 ) ;
}
F_77 ( L_25 ,
V_210 , V_209 , V_208 . V_3 , V_126 -> V_111 ,
V_126 -> V_147 , V_126 -> V_148 ) ;
V_201 = F_121 ( V_126 , V_208 . V_3 ) ;
goto V_217;
V_214:
while ( -- V_78 >= 0 )
V_195 ( F_148 ( V_212 [ V_78 ] ) , V_30 ) ;
V_201 = - V_61 ;
V_217:
F_114 ( F_105 ( V_212 ) , V_211 ) ;
F_113 ( V_126 ) ;
return V_201 ;
}
static void * T_6 F_149 ( unsigned int V_20 , T_2 V_9 ,
T_2 V_64 )
{
return F_150 (
V_9 , V_64 , F_105 ( V_218 ) ) ;
}
static void T_6 F_151 ( void * V_32 , T_2 V_9 )
{
F_114 ( F_105 ( V_32 ) , V_9 ) ;
}
void T_6 F_152 ( void )
{
unsigned long V_219 ;
unsigned int V_20 ;
int V_201 ;
V_201 = F_139 ( V_220 ,
V_221 , V_30 , NULL ,
F_149 , F_151 ) ;
if ( V_201 < 0 )
F_147 ( L_26 ) ;
V_219 = ( unsigned long ) V_115 - ( unsigned long ) V_113 ;
F_70 (cpu)
V_222 [ V_20 ] = V_219 + V_24 [ V_20 ] ;
}
void T_6 F_152 ( void )
{
const T_2 V_146 =
F_153 ( F_29 ( T_2 , V_93 ,
V_221 ) ) ;
struct V_123 * V_126 ;
void * V_223 ;
V_126 = F_109 ( 1 , 1 ) ;
V_223 = F_150 ( V_146 ,
V_30 ,
F_105 ( V_218 ) ) ;
if ( ! V_126 || ! V_223 )
F_147 ( L_27 ) ;
F_142 ( V_223 ) ;
V_126 -> V_148 = V_146 ;
V_126 -> V_146 = V_146 ;
V_126 -> V_149 = V_146 ;
V_126 -> V_145 = V_146 ;
V_126 -> V_130 [ 0 ] . V_125 = 1 ;
V_126 -> V_130 [ 0 ] . V_131 [ 0 ] = 0 ;
if ( F_121 ( V_126 , V_223 ) < 0 )
F_147 ( L_26 ) ;
}
void T_6 F_154 ( void )
{
struct V_13 * V_224 [] =
{ V_5 , V_42 , NULL } ;
struct V_13 * V_14 ;
unsigned long V_59 ;
int V_33 ;
for ( V_33 = 0 ; ( V_14 = V_224 [ V_33 ] ) ; V_33 ++ ) {
int * V_35 ;
const T_2 V_9 = V_154 * sizeof( V_35 [ 0 ] ) ;
F_155 ( V_9 > V_30 ) ;
V_35 = F_18 ( V_9 ) ;
F_47 ( ! V_35 ) ;
F_40 ( & V_48 , V_59 ) ;
memcpy ( V_35 , V_14 -> V_35 , V_9 ) ;
V_14 -> V_35 = V_35 ;
F_41 ( & V_48 , V_59 ) ;
}
}
static int T_6 F_156 ( void )
{
V_1 = true ;
return 0 ;
}
