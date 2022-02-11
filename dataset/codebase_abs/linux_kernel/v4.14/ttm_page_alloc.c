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
#if F_9 ( V_23 )
int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
F_10 ( V_21 [ V_24 ] ) ;
#endif
return 0 ;
}
static int F_11 ( struct V_20 * * V_21 , int V_22 )
{
#if F_9 ( V_23 )
int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
F_12 ( V_21 [ V_24 ] ) ;
#endif
return 0 ;
}
static int F_13 ( struct V_20 * * V_21 , int V_22 )
{
#if F_9 ( V_23 )
int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
F_12 ( V_21 [ V_24 ] ) ;
#endif
return 0 ;
}
static struct V_25 * F_14 ( int V_26 ,
enum V_27 V_28 )
{
int V_29 ;
if ( V_28 == V_30 )
return NULL ;
if ( V_28 == V_31 )
V_29 = 0x0 ;
else
V_29 = 0x1 ;
if ( V_26 & V_32 )
V_29 |= 0x2 ;
return & V_33 -> V_34 [ V_29 ] ;
}
static void F_15 ( struct V_20 * V_21 [] , unsigned V_35 )
{
unsigned V_24 ;
if ( F_8 ( V_21 , V_35 ) )
F_5 ( L_5 , V_35 ) ;
for ( V_24 = 0 ; V_24 < V_35 ; ++ V_24 )
F_16 ( V_21 [ V_24 ] ) ;
}
static void F_17 ( struct V_25 * V_36 ,
unsigned V_37 )
{
V_36 -> V_35 -= V_37 ;
V_36 -> V_38 += V_37 ;
}
static int F_18 ( struct V_25 * V_36 , unsigned V_39 ,
bool V_40 )
{
static struct V_20 * V_41 [ V_18 ] ;
unsigned long V_42 ;
struct V_20 * V_43 ;
struct V_20 * * V_44 ;
unsigned V_37 = 0 ,
V_45 = V_39 ;
if ( V_18 < V_39 )
V_45 = V_18 ;
if ( V_40 )
V_44 = V_41 ;
else
V_44 = F_19 ( V_45 * sizeof( struct V_20 * ) ,
V_46 ) ;
if ( ! V_44 ) {
F_5 ( L_6 ) ;
return 0 ;
}
V_47:
F_20 ( & V_36 -> V_48 , V_42 ) ;
F_21 (p, &pool->list, lru) {
if ( V_37 >= V_45 )
break;
V_44 [ V_37 ++ ] = V_43 ;
if ( V_37 >= V_18 ) {
F_22 ( V_43 -> V_49 . V_50 , & V_36 -> V_51 ) ;
F_17 ( V_36 , V_37 ) ;
F_23 ( & V_36 -> V_48 , V_42 ) ;
F_15 ( V_44 , V_37 ) ;
if ( F_24 ( V_39 != V_52 ) )
V_39 -= V_37 ;
if ( V_18 >= V_39 )
V_45 = V_39 ;
else
V_45 = V_18 ;
V_37 = 0 ;
if ( V_39 )
goto V_47;
goto V_53;
}
}
if ( V_37 ) {
F_22 ( & V_43 -> V_49 , & V_36 -> V_51 ) ;
F_17 ( V_36 , V_37 ) ;
V_39 -= V_37 ;
}
F_23 ( & V_36 -> V_48 , V_42 ) ;
if ( V_37 )
F_15 ( V_44 , V_37 ) ;
V_53:
if ( V_44 != V_41 )
F_3 ( V_44 ) ;
return V_39 ;
}
static unsigned long
F_25 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
static F_26 ( V_48 ) ;
static unsigned V_58 ;
unsigned V_24 ;
unsigned V_59 ;
struct V_25 * V_36 ;
int V_60 = V_57 -> V_61 ;
unsigned long V_62 = 0 ;
if ( ! F_27 ( & V_48 ) )
return V_63 ;
V_59 = ++ V_58 % V_64 ;
for ( V_24 = 0 ; V_24 < V_64 ; ++ V_24 ) {
unsigned V_39 = V_60 ;
if ( V_60 == 0 )
break;
V_36 = & V_33 -> V_34 [ ( V_24 + V_59 ) % V_64 ] ;
V_60 = F_18 ( V_36 , V_39 , true ) ;
V_62 += V_39 - V_60 ;
}
F_28 ( & V_48 ) ;
return V_62 ;
}
static unsigned long
F_29 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
unsigned V_24 ;
unsigned long V_65 = 0 ;
for ( V_24 = 0 ; V_24 < V_64 ; ++ V_24 )
V_65 += V_33 -> V_34 [ V_24 ] . V_35 ;
return V_65 ;
}
static void F_30 ( struct V_3 * V_66 )
{
V_66 -> V_67 . V_68 = F_29 ;
V_66 -> V_67 . V_69 = F_25 ;
V_66 -> V_67 . V_70 = 1 ;
F_31 ( & V_66 -> V_67 ) ;
}
static void F_32 ( struct V_3 * V_66 )
{
F_33 ( & V_66 -> V_67 ) ;
}
static int F_34 ( struct V_20 * * V_21 ,
enum V_27 V_28 , unsigned V_71 )
{
int V_72 = 0 ;
switch ( V_28 ) {
case V_73 :
V_72 = F_13 ( V_21 , V_71 ) ;
if ( V_72 )
F_5 ( L_7 , V_71 ) ;
break;
case V_31 :
V_72 = F_11 ( V_21 , V_71 ) ;
if ( V_72 )
F_5 ( L_8 , V_71 ) ;
break;
default:
break;
}
return V_72 ;
}
static void F_35 ( struct V_74 * V_21 ,
int V_75 , enum V_27 V_28 ,
struct V_20 * * V_76 , unsigned V_71 )
{
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_71 ; ++ V_24 ) {
F_36 ( & V_76 [ V_24 ] -> V_49 ) ;
F_16 ( V_76 [ V_24 ] ) ;
}
}
static int F_37 ( struct V_74 * V_21 , T_3 V_77 ,
int V_75 , enum V_27 V_28 , unsigned V_65 )
{
struct V_20 * * V_78 ;
struct V_20 * V_43 ;
int V_72 = 0 ;
unsigned V_24 , V_71 ;
unsigned V_79 = F_38 ( V_65 ,
( unsigned ) ( V_11 / sizeof( struct V_20 * ) ) ) ;
V_78 = F_19 ( V_79 * sizeof( struct V_20 * ) , V_46 ) ;
if ( ! V_78 ) {
F_5 ( L_9 ) ;
return - V_80 ;
}
for ( V_24 = 0 , V_71 = 0 ; V_24 < V_65 ; ++ V_24 ) {
V_43 = F_39 ( V_77 ) ;
if ( ! V_43 ) {
F_5 ( L_10 , V_24 ) ;
if ( V_71 ) {
V_72 = F_34 ( V_78 ,
V_28 , V_71 ) ;
if ( V_72 )
F_35 ( V_21 ,
V_75 , V_28 ,
V_78 , V_71 ) ;
}
V_72 = - V_80 ;
goto V_53;
}
#ifdef F_40
if ( ! F_41 ( V_43 ) )
#endif
{
V_78 [ V_71 ++ ] = V_43 ;
if ( V_71 == V_79 ) {
V_72 = F_34 ( V_78 ,
V_28 , V_71 ) ;
if ( V_72 ) {
F_35 ( V_21 ,
V_75 , V_28 ,
V_78 , V_71 ) ;
goto V_53;
}
V_71 = 0 ;
}
}
F_42 ( & V_43 -> V_49 , V_21 ) ;
}
if ( V_71 ) {
V_72 = F_34 ( V_78 , V_28 , V_71 ) ;
if ( V_72 )
F_35 ( V_21 ,
V_75 , V_28 ,
V_78 , V_71 ) ;
}
V_53:
F_3 ( V_78 ) ;
return V_72 ;
}
static void F_43 ( struct V_25 * V_36 ,
int V_75 , enum V_27 V_28 , unsigned V_65 ,
unsigned long * V_42 )
{
struct V_20 * V_43 ;
int V_72 ;
unsigned V_71 = 0 ;
if ( V_36 -> V_81 )
return;
V_36 -> V_81 = true ;
if ( V_65 < V_33 -> V_13 . V_16
&& V_65 > V_36 -> V_35 ) {
struct V_74 V_82 ;
unsigned V_19 = V_33 -> V_13 . V_19 ;
F_23 ( & V_36 -> V_48 , * V_42 ) ;
F_44 ( & V_82 ) ;
V_72 = F_37 ( & V_82 , V_36 -> V_77 , V_75 ,
V_28 , V_19 ) ;
F_20 ( & V_36 -> V_48 , * V_42 ) ;
if ( ! V_72 ) {
F_45 ( & V_82 , & V_36 -> V_51 ) ;
++ V_36 -> V_83 ;
V_36 -> V_35 += V_19 ;
} else {
F_5 ( L_11 , V_36 ) ;
F_46 (p, &new_pages, lru) {
++ V_71 ;
}
F_45 ( & V_82 , & V_36 -> V_51 ) ;
V_36 -> V_35 += V_71 ;
}
}
V_36 -> V_81 = false ;
}
static unsigned F_47 ( struct V_25 * V_36 ,
struct V_74 * V_21 ,
int V_75 ,
enum V_27 V_28 ,
unsigned V_65 )
{
unsigned long V_42 ;
struct V_74 * V_43 ;
unsigned V_24 ;
F_20 ( & V_36 -> V_48 , V_42 ) ;
F_43 ( V_36 , V_75 , V_28 , V_65 , & V_42 ) ;
if ( V_65 >= V_36 -> V_35 ) {
F_48 ( & V_36 -> V_51 , V_21 ) ;
V_65 -= V_36 -> V_35 ;
V_36 -> V_35 = 0 ;
goto V_53;
}
if ( V_65 <= V_36 -> V_35 / 2 ) {
V_24 = 0 ;
F_49 (p, &pool->list) {
if ( ++ V_24 == V_65 )
break;
}
} else {
V_24 = V_36 -> V_35 + 1 ;
F_50 (p, &pool->list) {
if ( -- V_24 == V_65 )
break;
}
}
F_51 ( V_21 , & V_36 -> V_51 , V_43 ) ;
V_36 -> V_35 -= V_65 ;
V_65 = 0 ;
V_53:
F_23 ( & V_36 -> V_48 , V_42 ) ;
return V_65 ;
}
static void F_52 ( struct V_20 * * V_21 , unsigned V_35 , int V_26 ,
enum V_27 V_28 )
{
unsigned long V_42 ;
struct V_25 * V_36 = F_14 ( V_26 , V_28 ) ;
unsigned V_24 ;
if ( V_36 == NULL ) {
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ ) {
if ( V_21 [ V_24 ] ) {
if ( F_53 ( V_21 [ V_24 ] ) != 1 )
F_5 ( L_12 ) ;
F_16 ( V_21 [ V_24 ] ) ;
V_21 [ V_24 ] = NULL ;
}
}
return;
}
F_20 ( & V_36 -> V_48 , V_42 ) ;
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ ) {
if ( V_21 [ V_24 ] ) {
if ( F_53 ( V_21 [ V_24 ] ) != 1 )
F_5 ( L_12 ) ;
F_54 ( & V_21 [ V_24 ] -> V_49 , & V_36 -> V_51 ) ;
V_21 [ V_24 ] = NULL ;
V_36 -> V_35 ++ ;
}
}
V_35 = 0 ;
if ( V_36 -> V_35 > V_33 -> V_13 . V_14 ) {
V_35 = V_36 -> V_35 - V_33 -> V_13 . V_14 ;
if ( V_35 < V_18 )
V_35 = V_18 ;
}
F_23 ( & V_36 -> V_48 , V_42 ) ;
if ( V_35 )
F_18 ( V_36 , V_35 , false ) ;
}
static int F_55 ( struct V_20 * * V_21 , unsigned V_35 , int V_26 ,
enum V_27 V_28 )
{
struct V_25 * V_36 = F_14 ( V_26 , V_28 ) ;
struct V_74 V_84 ;
struct V_20 * V_43 = NULL ;
T_3 V_77 = V_85 ;
unsigned V_65 ;
int V_72 ;
if ( V_26 & V_86 )
V_77 |= V_87 ;
if ( V_36 == NULL ) {
if ( V_26 & V_32 )
V_77 |= V_88 ;
else
V_77 |= V_89 ;
for ( V_72 = 0 ; V_72 < V_35 ; ++ V_72 ) {
V_43 = F_39 ( V_77 ) ;
if ( ! V_43 ) {
F_5 ( L_13 ) ;
return - V_80 ;
}
V_21 [ V_72 ] = V_43 ;
}
return 0 ;
}
V_77 |= V_36 -> V_77 ;
F_44 ( & V_84 ) ;
V_35 = F_47 ( V_36 , & V_84 , V_26 , V_28 , V_35 ) ;
V_65 = 0 ;
F_46 (p, &plist, lru) {
V_21 [ V_65 ++ ] = V_43 ;
}
if ( V_26 & V_86 ) {
F_46 (p, &plist, lru) {
if ( F_41 ( V_43 ) )
F_56 ( V_43 ) ;
else
F_57 ( F_58 ( V_43 ) ) ;
}
}
if ( V_35 > 0 ) {
F_44 ( & V_84 ) ;
V_72 = F_37 ( & V_84 , V_77 , V_26 , V_28 , V_35 ) ;
F_46 (p, &plist, lru) {
V_21 [ V_65 ++ ] = V_43 ;
}
if ( V_72 ) {
F_5 ( L_14 ) ;
F_52 ( V_21 , V_65 , V_26 , V_28 ) ;
return V_72 ;
}
}
return 0 ;
}
static void F_59 ( struct V_25 * V_36 , T_3 V_26 ,
char * V_90 )
{
F_60 ( & V_36 -> V_48 ) ;
V_36 -> V_81 = false ;
F_44 ( & V_36 -> V_51 ) ;
V_36 -> V_35 = V_36 -> V_38 = 0 ;
V_36 -> V_77 = V_26 ;
V_36 -> V_90 = V_90 ;
}
int F_61 ( struct V_91 * V_92 , unsigned V_93 )
{
int V_94 ;
F_62 ( V_33 ) ;
F_63 ( L_15 ) ;
V_33 = F_64 ( sizeof( * V_33 ) , V_46 ) ;
F_59 ( & V_33 -> V_95 , V_89 , L_16 ) ;
F_59 ( & V_33 -> V_96 , V_89 , L_17 ) ;
F_59 ( & V_33 -> V_97 ,
V_85 | V_88 , L_18 ) ;
F_59 ( & V_33 -> V_98 ,
V_85 | V_88 , L_19 ) ;
V_33 -> V_13 . V_14 = V_93 ;
V_33 -> V_13 . V_16 = V_99 ;
V_33 -> V_13 . V_19 = V_18 ;
V_94 = F_65 ( & V_33 -> V_2 , & V_100 ,
& V_92 -> V_2 , L_20 ) ;
if ( F_66 ( V_94 != 0 ) ) {
F_67 ( & V_33 -> V_2 ) ;
V_33 = NULL ;
return V_94 ;
}
F_30 ( V_33 ) ;
return 0 ;
}
void F_68 ( void )
{
int V_24 ;
F_63 ( L_21 ) ;
F_32 ( V_33 ) ;
for ( V_24 = 0 ; V_24 < V_64 ; ++ V_24 )
F_18 ( & V_33 -> V_34 [ V_24 ] , V_52 , true ) ;
F_67 ( & V_33 -> V_2 ) ;
V_33 = NULL ;
}
int F_69 ( struct V_101 * V_102 )
{
struct V_91 * V_103 = V_102 -> V_92 -> V_103 ;
unsigned V_24 ;
int V_94 ;
if ( V_102 -> V_104 != V_105 )
return 0 ;
for ( V_24 = 0 ; V_24 < V_102 -> V_106 ; ++ V_24 ) {
V_94 = F_55 ( & V_102 -> V_21 [ V_24 ] , 1 ,
V_102 -> V_107 ,
V_102 -> V_108 ) ;
if ( V_94 != 0 ) {
F_70 ( V_102 ) ;
return - V_80 ;
}
V_94 = F_71 ( V_103 , V_102 -> V_21 [ V_24 ] ,
false , false ) ;
if ( F_66 ( V_94 != 0 ) ) {
F_70 ( V_102 ) ;
return - V_80 ;
}
}
if ( F_66 ( V_102 -> V_107 & V_109 ) ) {
V_94 = F_72 ( V_102 ) ;
if ( F_66 ( V_94 != 0 ) ) {
F_70 ( V_102 ) ;
return V_94 ;
}
}
V_102 -> V_104 = V_110 ;
return 0 ;
}
void F_70 ( struct V_101 * V_102 )
{
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_102 -> V_106 ; ++ V_24 ) {
if ( V_102 -> V_21 [ V_24 ] ) {
F_73 ( V_102 -> V_92 -> V_103 ,
V_102 -> V_21 [ V_24 ] ) ;
F_52 ( & V_102 -> V_21 [ V_24 ] , 1 ,
V_102 -> V_107 ,
V_102 -> V_108 ) ;
}
}
V_102 -> V_104 = V_105 ;
}
int F_74 ( struct V_111 * V_4 , void * V_112 )
{
struct V_25 * V_43 ;
unsigned V_24 ;
char * V_113 [] = { L_20 , L_22 , L_23 , L_24 } ;
if ( ! V_33 ) {
F_75 ( V_4 , L_25 ) ;
return 0 ;
}
F_75 ( V_4 , L_26 ,
V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] , V_113 [ 3 ] ) ;
for ( V_24 = 0 ; V_24 < V_64 ; ++ V_24 ) {
V_43 = & V_33 -> V_34 [ V_24 ] ;
F_75 ( V_4 , L_27 ,
V_43 -> V_90 , V_43 -> V_83 ,
V_43 -> V_38 , V_43 -> V_35 ) ;
}
return 0 ;
}
