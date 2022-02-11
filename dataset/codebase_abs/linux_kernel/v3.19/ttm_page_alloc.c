static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_5 * V_6 , const char * V_7 , T_2 V_8 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
int V_9 ;
unsigned V_10 ;
V_9 = sscanf ( V_7 , L_1 , & V_10 ) ;
if ( V_9 == 0 )
return V_8 ;
V_10 = V_10 / ( V_11 >> 10 ) ;
if ( V_6 == & V_12 )
V_4 -> V_13 . V_14 = V_10 ;
else if ( V_6 == & V_15 )
V_4 -> V_13 . V_16 = V_10 ;
else if ( V_6 == & V_17 ) {
if ( V_10 > V_18 * 8 ) {
F_5 ( L_2 ,
V_18 * ( V_11 >> 7 ) ,
V_18 * ( V_11 >> 10 ) ) ;
return V_8 ;
} else if ( V_10 > V_18 ) {
F_6 ( L_3 ,
V_18 * ( V_11 >> 10 ) ) ;
}
V_4 -> V_13 . V_19 = V_10 ;
}
return V_8 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
unsigned V_10 = 0 ;
if ( V_6 == & V_12 )
V_10 = V_4 -> V_13 . V_14 ;
else if ( V_6 == & V_15 )
V_10 = V_4 -> V_13 . V_16 ;
else if ( V_6 == & V_17 )
V_10 = V_4 -> V_13 . V_19 ;
V_10 = V_10 * ( V_11 >> 10 ) ;
return snprintf ( V_7 , V_11 , L_4 , V_10 ) ;
}
static int F_8 ( struct V_20 * * V_21 , int V_22 )
{
#ifdef F_9
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
F_10 ( V_21 [ V_23 ] ) ;
#endif
return 0 ;
}
static int F_11 ( struct V_20 * * V_21 , int V_22 )
{
#ifdef F_9
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
F_12 ( V_21 [ V_23 ] ) ;
#endif
return 0 ;
}
static int F_13 ( struct V_20 * * V_21 , int V_22 )
{
#ifdef F_9
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
F_12 ( V_21 [ V_23 ] ) ;
#endif
return 0 ;
}
static struct V_24 * F_14 ( int V_25 ,
enum V_26 V_27 )
{
int V_28 ;
if ( V_27 == V_29 )
return NULL ;
if ( V_27 == V_30 )
V_28 = 0x0 ;
else
V_28 = 0x1 ;
if ( V_25 & V_31 )
V_28 |= 0x2 ;
return & V_32 -> V_33 [ V_28 ] ;
}
static void F_15 ( struct V_20 * V_21 [] , unsigned V_34 )
{
unsigned V_23 ;
if ( F_8 ( V_21 , V_34 ) )
F_5 ( L_5 , V_34 ) ;
for ( V_23 = 0 ; V_23 < V_34 ; ++ V_23 )
F_16 ( V_21 [ V_23 ] ) ;
}
static void F_17 ( struct V_24 * V_35 ,
unsigned V_36 )
{
V_35 -> V_34 -= V_36 ;
V_35 -> V_37 += V_36 ;
}
static int F_18 ( struct V_24 * V_35 , unsigned V_38 ,
bool V_39 )
{
static struct V_20 * V_40 [ V_18 ] ;
unsigned long V_41 ;
struct V_20 * V_42 ;
struct V_20 * * V_43 ;
unsigned V_36 = 0 ,
V_44 = V_38 ;
if ( V_18 < V_38 )
V_44 = V_18 ;
if ( V_39 )
V_43 = V_40 ;
else
V_43 = F_19 ( V_44 * sizeof( struct V_20 * ) ,
V_45 ) ;
if ( ! V_43 ) {
F_5 ( L_6 ) ;
return 0 ;
}
V_46:
F_20 ( & V_35 -> V_47 , V_41 ) ;
F_21 (p, &pool->list, lru) {
if ( V_36 >= V_44 )
break;
V_43 [ V_36 ++ ] = V_42 ;
if ( V_36 >= V_18 ) {
F_22 ( V_42 -> V_48 . V_49 , & V_35 -> V_50 ) ;
F_17 ( V_35 , V_36 ) ;
F_23 ( & V_35 -> V_47 , V_41 ) ;
F_15 ( V_43 , V_36 ) ;
if ( F_24 ( V_38 != V_51 ) )
V_38 -= V_36 ;
if ( V_18 >= V_38 )
V_44 = V_38 ;
else
V_44 = V_18 ;
V_36 = 0 ;
if ( V_38 )
goto V_46;
goto V_52;
}
}
if ( V_36 ) {
F_22 ( & V_42 -> V_48 , & V_35 -> V_50 ) ;
F_17 ( V_35 , V_36 ) ;
V_38 -= V_36 ;
}
F_23 ( & V_35 -> V_47 , V_41 ) ;
if ( V_36 )
F_15 ( V_43 , V_36 ) ;
V_52:
if ( V_43 != V_40 )
F_3 ( V_43 ) ;
return V_38 ;
}
static unsigned long
F_25 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
static F_26 ( V_47 ) ;
static unsigned V_57 ;
unsigned V_23 ;
unsigned V_58 ;
struct V_24 * V_35 ;
int V_59 = V_56 -> V_60 ;
unsigned long V_61 = 0 ;
if ( ! F_27 ( & V_47 ) )
return V_62 ;
V_58 = ++ V_57 % V_63 ;
for ( V_23 = 0 ; V_23 < V_63 ; ++ V_23 ) {
unsigned V_38 = V_59 ;
if ( V_59 == 0 )
break;
V_35 = & V_32 -> V_33 [ ( V_23 + V_58 ) % V_63 ] ;
V_59 = F_18 ( V_35 , V_38 , true ) ;
V_61 += V_38 - V_59 ;
}
F_28 ( & V_47 ) ;
return V_61 ;
}
static unsigned long
F_29 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
unsigned V_23 ;
unsigned long V_64 = 0 ;
for ( V_23 = 0 ; V_23 < V_63 ; ++ V_23 )
V_64 += V_32 -> V_33 [ V_23 ] . V_34 ;
return V_64 ;
}
static void F_30 ( struct V_3 * V_65 )
{
V_65 -> V_66 . V_67 = F_29 ;
V_65 -> V_66 . V_68 = F_25 ;
V_65 -> V_66 . V_69 = 1 ;
F_31 ( & V_65 -> V_66 ) ;
}
static void F_32 ( struct V_3 * V_65 )
{
F_33 ( & V_65 -> V_66 ) ;
}
static int F_34 ( struct V_20 * * V_21 ,
enum V_26 V_27 , unsigned V_70 )
{
int V_71 = 0 ;
switch ( V_27 ) {
case V_72 :
V_71 = F_13 ( V_21 , V_70 ) ;
if ( V_71 )
F_5 ( L_7 , V_70 ) ;
break;
case V_30 :
V_71 = F_11 ( V_21 , V_70 ) ;
if ( V_71 )
F_5 ( L_8 , V_70 ) ;
break;
default:
break;
}
return V_71 ;
}
static void F_35 ( struct V_73 * V_21 ,
int V_74 , enum V_26 V_27 ,
struct V_20 * * V_75 , unsigned V_70 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_70 ; ++ V_23 ) {
F_36 ( & V_75 [ V_23 ] -> V_48 ) ;
F_16 ( V_75 [ V_23 ] ) ;
}
}
static int F_37 ( struct V_73 * V_21 , T_3 V_76 ,
int V_74 , enum V_26 V_27 , unsigned V_64 )
{
struct V_20 * * V_77 ;
struct V_20 * V_42 ;
int V_71 = 0 ;
unsigned V_23 , V_70 ;
unsigned V_78 = F_38 ( V_64 ,
( unsigned ) ( V_11 / sizeof( struct V_20 * ) ) ) ;
V_77 = F_19 ( V_78 * sizeof( struct V_20 * ) , V_45 ) ;
if ( ! V_77 ) {
F_5 ( L_9 ) ;
return - V_79 ;
}
for ( V_23 = 0 , V_70 = 0 ; V_23 < V_64 ; ++ V_23 ) {
V_42 = F_39 ( V_76 ) ;
if ( ! V_42 ) {
F_5 ( L_10 , V_23 ) ;
if ( V_70 ) {
V_71 = F_34 ( V_77 ,
V_27 , V_70 ) ;
if ( V_71 )
F_35 ( V_21 ,
V_74 , V_27 ,
V_77 , V_70 ) ;
}
V_71 = - V_79 ;
goto V_52;
}
#ifdef F_40
if ( ! F_41 ( V_42 ) )
#endif
{
V_77 [ V_70 ++ ] = V_42 ;
if ( V_70 == V_78 ) {
V_71 = F_34 ( V_77 ,
V_27 , V_70 ) ;
if ( V_71 ) {
F_35 ( V_21 ,
V_74 , V_27 ,
V_77 , V_70 ) ;
goto V_52;
}
V_70 = 0 ;
}
}
F_42 ( & V_42 -> V_48 , V_21 ) ;
}
if ( V_70 ) {
V_71 = F_34 ( V_77 , V_27 , V_70 ) ;
if ( V_71 )
F_35 ( V_21 ,
V_74 , V_27 ,
V_77 , V_70 ) ;
}
V_52:
F_3 ( V_77 ) ;
return V_71 ;
}
static void F_43 ( struct V_24 * V_35 ,
int V_74 , enum V_26 V_27 , unsigned V_64 ,
unsigned long * V_41 )
{
struct V_20 * V_42 ;
int V_71 ;
unsigned V_70 = 0 ;
if ( V_35 -> V_80 )
return;
V_35 -> V_80 = true ;
if ( V_64 < V_32 -> V_13 . V_16
&& V_64 > V_35 -> V_34 ) {
struct V_73 V_81 ;
unsigned V_19 = V_32 -> V_13 . V_19 ;
F_23 ( & V_35 -> V_47 , * V_41 ) ;
F_44 ( & V_81 ) ;
V_71 = F_37 ( & V_81 , V_35 -> V_76 , V_74 ,
V_27 , V_19 ) ;
F_20 ( & V_35 -> V_47 , * V_41 ) ;
if ( ! V_71 ) {
F_45 ( & V_81 , & V_35 -> V_50 ) ;
++ V_35 -> V_82 ;
V_35 -> V_34 += V_19 ;
} else {
F_5 ( L_11 , V_35 ) ;
F_46 (p, &pool->list, lru) {
++ V_70 ;
}
F_45 ( & V_81 , & V_35 -> V_50 ) ;
V_35 -> V_34 += V_70 ;
}
}
V_35 -> V_80 = false ;
}
static unsigned F_47 ( struct V_24 * V_35 ,
struct V_73 * V_21 ,
int V_74 ,
enum V_26 V_27 ,
unsigned V_64 )
{
unsigned long V_41 ;
struct V_73 * V_42 ;
unsigned V_23 ;
F_20 ( & V_35 -> V_47 , V_41 ) ;
F_43 ( V_35 , V_74 , V_27 , V_64 , & V_41 ) ;
if ( V_64 >= V_35 -> V_34 ) {
F_48 ( & V_35 -> V_50 , V_21 ) ;
V_64 -= V_35 -> V_34 ;
V_35 -> V_34 = 0 ;
goto V_52;
}
if ( V_64 <= V_35 -> V_34 / 2 ) {
V_23 = 0 ;
F_49 (p, &pool->list) {
if ( ++ V_23 == V_64 )
break;
}
} else {
V_23 = V_35 -> V_34 + 1 ;
F_50 (p, &pool->list) {
if ( -- V_23 == V_64 )
break;
}
}
F_51 ( V_21 , & V_35 -> V_50 , V_42 ) ;
V_35 -> V_34 -= V_64 ;
V_64 = 0 ;
V_52:
F_23 ( & V_35 -> V_47 , V_41 ) ;
return V_64 ;
}
static void F_52 ( struct V_20 * * V_21 , unsigned V_34 , int V_25 ,
enum V_26 V_27 )
{
unsigned long V_41 ;
struct V_24 * V_35 = F_14 ( V_25 , V_27 ) ;
unsigned V_23 ;
if ( V_35 == NULL ) {
for ( V_23 = 0 ; V_23 < V_34 ; V_23 ++ ) {
if ( V_21 [ V_23 ] ) {
if ( F_53 ( V_21 [ V_23 ] ) != 1 )
F_5 ( L_12 ) ;
F_16 ( V_21 [ V_23 ] ) ;
V_21 [ V_23 ] = NULL ;
}
}
return;
}
F_20 ( & V_35 -> V_47 , V_41 ) ;
for ( V_23 = 0 ; V_23 < V_34 ; V_23 ++ ) {
if ( V_21 [ V_23 ] ) {
if ( F_53 ( V_21 [ V_23 ] ) != 1 )
F_5 ( L_12 ) ;
F_54 ( & V_21 [ V_23 ] -> V_48 , & V_35 -> V_50 ) ;
V_21 [ V_23 ] = NULL ;
V_35 -> V_34 ++ ;
}
}
V_34 = 0 ;
if ( V_35 -> V_34 > V_32 -> V_13 . V_14 ) {
V_34 = V_35 -> V_34 - V_32 -> V_13 . V_14 ;
if ( V_34 < V_18 )
V_34 = V_18 ;
}
F_23 ( & V_35 -> V_47 , V_41 ) ;
if ( V_34 )
F_18 ( V_35 , V_34 , false ) ;
}
static int F_55 ( struct V_20 * * V_21 , unsigned V_34 , int V_25 ,
enum V_26 V_27 )
{
struct V_24 * V_35 = F_14 ( V_25 , V_27 ) ;
struct V_73 V_83 ;
struct V_20 * V_42 = NULL ;
T_3 V_76 = V_84 ;
unsigned V_64 ;
int V_71 ;
if ( V_25 & V_85 )
V_76 |= V_86 ;
if ( V_35 == NULL ) {
if ( V_25 & V_31 )
V_76 |= V_87 ;
else
V_76 |= V_88 ;
for ( V_71 = 0 ; V_71 < V_34 ; ++ V_71 ) {
V_42 = F_39 ( V_76 ) ;
if ( ! V_42 ) {
F_5 ( L_13 ) ;
return - V_79 ;
}
V_21 [ V_71 ] = V_42 ;
}
return 0 ;
}
V_76 |= V_35 -> V_76 ;
F_44 ( & V_83 ) ;
V_34 = F_47 ( V_35 , & V_83 , V_25 , V_27 , V_34 ) ;
V_64 = 0 ;
F_46 (p, &plist, lru) {
V_21 [ V_64 ++ ] = V_42 ;
}
if ( V_25 & V_85 ) {
F_46 (p, &plist, lru) {
if ( F_41 ( V_42 ) )
F_56 ( V_42 ) ;
else
F_57 ( F_58 ( V_42 ) ) ;
}
}
if ( V_34 > 0 ) {
F_44 ( & V_83 ) ;
V_71 = F_37 ( & V_83 , V_76 , V_25 , V_27 , V_34 ) ;
F_46 (p, &plist, lru) {
V_21 [ V_64 ++ ] = V_42 ;
}
if ( V_71 ) {
F_5 ( L_14 ) ;
F_52 ( V_21 , V_64 , V_25 , V_27 ) ;
return V_71 ;
}
}
return 0 ;
}
static void F_59 ( struct V_24 * V_35 , T_3 V_25 ,
char * V_89 )
{
F_60 ( & V_35 -> V_47 ) ;
V_35 -> V_80 = false ;
F_44 ( & V_35 -> V_50 ) ;
V_35 -> V_34 = V_35 -> V_37 = 0 ;
V_35 -> V_76 = V_25 ;
V_35 -> V_89 = V_89 ;
}
int F_61 ( struct V_90 * V_91 , unsigned V_92 )
{
int V_93 ;
F_62 ( V_32 ) ;
F_63 ( L_15 ) ;
V_32 = F_64 ( sizeof( * V_32 ) , V_45 ) ;
F_59 ( & V_32 -> V_94 , V_88 , L_16 ) ;
F_59 ( & V_32 -> V_95 , V_88 , L_17 ) ;
F_59 ( & V_32 -> V_96 ,
V_84 | V_87 , L_18 ) ;
F_59 ( & V_32 -> V_97 ,
V_84 | V_87 , L_19 ) ;
V_32 -> V_13 . V_14 = V_92 ;
V_32 -> V_13 . V_16 = V_98 ;
V_32 -> V_13 . V_19 = V_18 ;
V_93 = F_65 ( & V_32 -> V_2 , & V_99 ,
& V_91 -> V_2 , L_20 ) ;
if ( F_66 ( V_93 != 0 ) ) {
F_67 ( & V_32 -> V_2 ) ;
V_32 = NULL ;
return V_93 ;
}
F_30 ( V_32 ) ;
return 0 ;
}
void F_68 ( void )
{
int V_23 ;
F_63 ( L_21 ) ;
F_32 ( V_32 ) ;
for ( V_23 = 0 ; V_23 < V_63 ; ++ V_23 )
F_18 ( & V_32 -> V_33 [ V_23 ] , V_51 , true ) ;
F_67 ( & V_32 -> V_2 ) ;
V_32 = NULL ;
}
int F_69 ( struct V_100 * V_101 )
{
struct V_90 * V_102 = V_101 -> V_91 -> V_102 ;
unsigned V_23 ;
int V_93 ;
if ( V_101 -> V_103 != V_104 )
return 0 ;
for ( V_23 = 0 ; V_23 < V_101 -> V_105 ; ++ V_23 ) {
V_93 = F_55 ( & V_101 -> V_21 [ V_23 ] , 1 ,
V_101 -> V_106 ,
V_101 -> V_107 ) ;
if ( V_93 != 0 ) {
F_70 ( V_101 ) ;
return - V_79 ;
}
V_93 = F_71 ( V_102 , V_101 -> V_21 [ V_23 ] ,
false , false ) ;
if ( F_66 ( V_93 != 0 ) ) {
F_70 ( V_101 ) ;
return - V_79 ;
}
}
if ( F_66 ( V_101 -> V_106 & V_108 ) ) {
V_93 = F_72 ( V_101 ) ;
if ( F_66 ( V_93 != 0 ) ) {
F_70 ( V_101 ) ;
return V_93 ;
}
}
V_101 -> V_103 = V_109 ;
return 0 ;
}
void F_70 ( struct V_100 * V_101 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_101 -> V_105 ; ++ V_23 ) {
if ( V_101 -> V_21 [ V_23 ] ) {
F_73 ( V_101 -> V_91 -> V_102 ,
V_101 -> V_21 [ V_23 ] ) ;
F_52 ( & V_101 -> V_21 [ V_23 ] , 1 ,
V_101 -> V_106 ,
V_101 -> V_107 ) ;
}
}
V_101 -> V_103 = V_104 ;
}
int F_74 ( struct V_110 * V_4 , void * V_111 )
{
struct V_24 * V_42 ;
unsigned V_23 ;
char * V_112 [] = { L_20 , L_22 , L_23 , L_24 } ;
if ( ! V_32 ) {
F_75 ( V_4 , L_25 ) ;
return 0 ;
}
F_75 ( V_4 , L_26 ,
V_112 [ 0 ] , V_112 [ 1 ] , V_112 [ 2 ] , V_112 [ 3 ] ) ;
for ( V_23 = 0 ; V_23 < V_63 ; ++ V_23 ) {
V_42 = & V_32 -> V_33 [ V_23 ] ;
F_75 ( V_4 , L_27 ,
V_42 -> V_89 , V_42 -> V_82 ,
V_42 -> V_37 , V_42 -> V_34 ) ;
}
return 0 ;
}
