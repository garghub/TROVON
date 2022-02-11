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
static int F_18 ( struct V_24 * V_35 , unsigned V_38 )
{
unsigned long V_39 ;
struct V_20 * V_40 ;
struct V_20 * * V_41 ;
unsigned V_36 = 0 ,
V_42 = V_38 ;
if ( V_18 < V_38 )
V_42 = V_18 ;
V_41 = F_19 ( V_42 * sizeof( struct V_20 * ) ,
V_43 ) ;
if ( ! V_41 ) {
F_5 ( L_6 ) ;
return 0 ;
}
V_44:
F_20 ( & V_35 -> V_45 , V_39 ) ;
F_21 (p, &pool->list, lru) {
if ( V_36 >= V_42 )
break;
V_41 [ V_36 ++ ] = V_40 ;
if ( V_36 >= V_18 ) {
F_22 ( V_40 -> V_46 . V_47 , & V_35 -> V_48 ) ;
F_17 ( V_35 , V_36 ) ;
F_23 ( & V_35 -> V_45 , V_39 ) ;
F_15 ( V_41 , V_36 ) ;
if ( F_24 ( V_38 != V_49 ) )
V_38 -= V_36 ;
if ( V_18 >= V_38 )
V_42 = V_38 ;
else
V_42 = V_18 ;
V_36 = 0 ;
if ( V_38 )
goto V_44;
goto V_50;
}
}
if ( V_36 ) {
F_22 ( & V_40 -> V_46 , & V_35 -> V_48 ) ;
F_17 ( V_35 , V_36 ) ;
V_38 -= V_36 ;
}
F_23 ( & V_35 -> V_45 , V_39 ) ;
if ( V_36 )
F_15 ( V_41 , V_36 ) ;
V_50:
F_3 ( V_41 ) ;
return V_38 ;
}
static unsigned long
F_25 ( struct V_51 * V_52 , struct V_53 * V_54 )
{
static T_3 V_55 = F_26 ( 0 ) ;
unsigned V_23 ;
unsigned V_56 = F_27 ( 1 , & V_55 ) ;
struct V_24 * V_35 ;
int V_57 = V_54 -> V_58 ;
unsigned long V_59 = 0 ;
V_56 = V_56 % V_60 ;
for ( V_23 = 0 ; V_23 < V_60 ; ++ V_23 ) {
unsigned V_38 = V_57 ;
if ( V_57 == 0 )
break;
V_35 = & V_32 -> V_33 [ ( V_23 + V_56 ) % V_60 ] ;
V_57 = F_18 ( V_35 , V_38 ) ;
V_59 += V_38 - V_57 ;
}
return V_59 ;
}
static unsigned long
F_28 ( struct V_51 * V_52 , struct V_53 * V_54 )
{
unsigned V_23 ;
unsigned long V_61 = 0 ;
for ( V_23 = 0 ; V_23 < V_60 ; ++ V_23 )
V_61 += V_32 -> V_33 [ V_23 ] . V_34 ;
return V_61 ;
}
static void F_29 ( struct V_3 * V_62 )
{
V_62 -> V_63 . V_64 = F_28 ;
V_62 -> V_63 . V_65 = F_25 ;
V_62 -> V_63 . V_66 = 1 ;
F_30 ( & V_62 -> V_63 ) ;
}
static void F_31 ( struct V_3 * V_62 )
{
F_32 ( & V_62 -> V_63 ) ;
}
static int F_33 ( struct V_20 * * V_21 ,
enum V_26 V_27 , unsigned V_67 )
{
int V_68 = 0 ;
switch ( V_27 ) {
case V_69 :
V_68 = F_13 ( V_21 , V_67 ) ;
if ( V_68 )
F_5 ( L_7 , V_67 ) ;
break;
case V_30 :
V_68 = F_11 ( V_21 , V_67 ) ;
if ( V_68 )
F_5 ( L_8 , V_67 ) ;
break;
default:
break;
}
return V_68 ;
}
static void F_34 ( struct V_70 * V_21 ,
int V_71 , enum V_26 V_27 ,
struct V_20 * * V_72 , unsigned V_67 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_67 ; ++ V_23 ) {
F_35 ( & V_72 [ V_23 ] -> V_46 ) ;
F_16 ( V_72 [ V_23 ] ) ;
}
}
static int F_36 ( struct V_70 * V_21 , T_4 V_73 ,
int V_71 , enum V_26 V_27 , unsigned V_61 )
{
struct V_20 * * V_74 ;
struct V_20 * V_40 ;
int V_68 = 0 ;
unsigned V_23 , V_67 ;
unsigned V_75 = F_37 ( V_61 ,
( unsigned ) ( V_11 / sizeof( struct V_20 * ) ) ) ;
V_74 = F_19 ( V_75 * sizeof( struct V_20 * ) , V_43 ) ;
if ( ! V_74 ) {
F_5 ( L_9 ) ;
return - V_76 ;
}
for ( V_23 = 0 , V_67 = 0 ; V_23 < V_61 ; ++ V_23 ) {
V_40 = F_38 ( V_73 ) ;
if ( ! V_40 ) {
F_5 ( L_10 , V_23 ) ;
if ( V_67 ) {
V_68 = F_33 ( V_74 ,
V_27 , V_67 ) ;
if ( V_68 )
F_34 ( V_21 ,
V_71 , V_27 ,
V_74 , V_67 ) ;
}
V_68 = - V_76 ;
goto V_50;
}
#ifdef F_39
if ( ! F_40 ( V_40 ) )
#endif
{
V_74 [ V_67 ++ ] = V_40 ;
if ( V_67 == V_75 ) {
V_68 = F_33 ( V_74 ,
V_27 , V_67 ) ;
if ( V_68 ) {
F_34 ( V_21 ,
V_71 , V_27 ,
V_74 , V_67 ) ;
goto V_50;
}
V_67 = 0 ;
}
}
F_41 ( & V_40 -> V_46 , V_21 ) ;
}
if ( V_67 ) {
V_68 = F_33 ( V_74 , V_27 , V_67 ) ;
if ( V_68 )
F_34 ( V_21 ,
V_71 , V_27 ,
V_74 , V_67 ) ;
}
V_50:
F_3 ( V_74 ) ;
return V_68 ;
}
static void F_42 ( struct V_24 * V_35 ,
int V_71 , enum V_26 V_27 , unsigned V_61 ,
unsigned long * V_39 )
{
struct V_20 * V_40 ;
int V_68 ;
unsigned V_67 = 0 ;
if ( V_35 -> V_77 )
return;
V_35 -> V_77 = true ;
if ( V_61 < V_32 -> V_13 . V_16
&& V_61 > V_35 -> V_34 ) {
struct V_70 V_78 ;
unsigned V_19 = V_32 -> V_13 . V_19 ;
F_23 ( & V_35 -> V_45 , * V_39 ) ;
F_43 ( & V_78 ) ;
V_68 = F_36 ( & V_78 , V_35 -> V_73 , V_71 ,
V_27 , V_19 ) ;
F_20 ( & V_35 -> V_45 , * V_39 ) ;
if ( ! V_68 ) {
F_44 ( & V_78 , & V_35 -> V_48 ) ;
++ V_35 -> V_79 ;
V_35 -> V_34 += V_19 ;
} else {
F_5 ( L_11 , V_35 ) ;
F_45 (p, &pool->list, lru) {
++ V_67 ;
}
F_44 ( & V_78 , & V_35 -> V_48 ) ;
V_35 -> V_34 += V_67 ;
}
}
V_35 -> V_77 = false ;
}
static unsigned F_46 ( struct V_24 * V_35 ,
struct V_70 * V_21 ,
int V_71 ,
enum V_26 V_27 ,
unsigned V_61 )
{
unsigned long V_39 ;
struct V_70 * V_40 ;
unsigned V_23 ;
F_20 ( & V_35 -> V_45 , V_39 ) ;
F_42 ( V_35 , V_71 , V_27 , V_61 , & V_39 ) ;
if ( V_61 >= V_35 -> V_34 ) {
F_47 ( & V_35 -> V_48 , V_21 ) ;
V_61 -= V_35 -> V_34 ;
V_35 -> V_34 = 0 ;
goto V_50;
}
if ( V_61 <= V_35 -> V_34 / 2 ) {
V_23 = 0 ;
F_48 (p, &pool->list) {
if ( ++ V_23 == V_61 )
break;
}
} else {
V_23 = V_35 -> V_34 + 1 ;
F_49 (p, &pool->list) {
if ( -- V_23 == V_61 )
break;
}
}
F_50 ( V_21 , & V_35 -> V_48 , V_40 ) ;
V_35 -> V_34 -= V_61 ;
V_61 = 0 ;
V_50:
F_23 ( & V_35 -> V_45 , V_39 ) ;
return V_61 ;
}
static void F_51 ( struct V_20 * * V_21 , unsigned V_34 , int V_25 ,
enum V_26 V_27 )
{
unsigned long V_39 ;
struct V_24 * V_35 = F_14 ( V_25 , V_27 ) ;
unsigned V_23 ;
if ( V_35 == NULL ) {
for ( V_23 = 0 ; V_23 < V_34 ; V_23 ++ ) {
if ( V_21 [ V_23 ] ) {
if ( F_52 ( V_21 [ V_23 ] ) != 1 )
F_5 ( L_12 ) ;
F_16 ( V_21 [ V_23 ] ) ;
V_21 [ V_23 ] = NULL ;
}
}
return;
}
F_20 ( & V_35 -> V_45 , V_39 ) ;
for ( V_23 = 0 ; V_23 < V_34 ; V_23 ++ ) {
if ( V_21 [ V_23 ] ) {
if ( F_52 ( V_21 [ V_23 ] ) != 1 )
F_5 ( L_12 ) ;
F_53 ( & V_21 [ V_23 ] -> V_46 , & V_35 -> V_48 ) ;
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
F_23 ( & V_35 -> V_45 , V_39 ) ;
if ( V_34 )
F_18 ( V_35 , V_34 ) ;
}
static int F_54 ( struct V_20 * * V_21 , unsigned V_34 , int V_25 ,
enum V_26 V_27 )
{
struct V_24 * V_35 = F_14 ( V_25 , V_27 ) ;
struct V_70 V_80 ;
struct V_20 * V_40 = NULL ;
T_4 V_73 = V_81 ;
unsigned V_61 ;
int V_68 ;
if ( V_25 & V_82 )
V_73 |= V_83 ;
if ( V_35 == NULL ) {
if ( V_25 & V_31 )
V_73 |= V_84 ;
else
V_73 |= V_85 ;
for ( V_68 = 0 ; V_68 < V_34 ; ++ V_68 ) {
V_40 = F_38 ( V_73 ) ;
if ( ! V_40 ) {
F_5 ( L_13 ) ;
return - V_76 ;
}
V_21 [ V_68 ] = V_40 ;
}
return 0 ;
}
V_73 |= V_35 -> V_73 ;
F_43 ( & V_80 ) ;
V_34 = F_46 ( V_35 , & V_80 , V_25 , V_27 , V_34 ) ;
V_61 = 0 ;
F_45 (p, &plist, lru) {
V_21 [ V_61 ++ ] = V_40 ;
}
if ( V_25 & V_82 ) {
F_45 (p, &plist, lru) {
if ( F_40 ( V_40 ) )
F_55 ( V_40 ) ;
else
F_56 ( F_57 ( V_40 ) ) ;
}
}
if ( V_34 > 0 ) {
F_43 ( & V_80 ) ;
V_68 = F_36 ( & V_80 , V_73 , V_25 , V_27 , V_34 ) ;
F_45 (p, &plist, lru) {
V_21 [ V_61 ++ ] = V_40 ;
}
if ( V_68 ) {
F_5 ( L_14 ) ;
F_51 ( V_21 , V_61 , V_25 , V_27 ) ;
return V_68 ;
}
}
return 0 ;
}
static void F_58 ( struct V_24 * V_35 , int V_25 ,
char * V_86 )
{
F_59 ( & V_35 -> V_45 ) ;
V_35 -> V_77 = false ;
F_43 ( & V_35 -> V_48 ) ;
V_35 -> V_34 = V_35 -> V_37 = 0 ;
V_35 -> V_73 = V_25 ;
V_35 -> V_86 = V_86 ;
}
int F_60 ( struct V_87 * V_88 , unsigned V_89 )
{
int V_90 ;
F_61 ( V_32 ) ;
F_62 ( L_15 ) ;
V_32 = F_63 ( sizeof( * V_32 ) , V_43 ) ;
F_58 ( & V_32 -> V_91 , V_85 , L_16 ) ;
F_58 ( & V_32 -> V_92 , V_85 , L_17 ) ;
F_58 ( & V_32 -> V_93 ,
V_81 | V_84 , L_18 ) ;
F_58 ( & V_32 -> V_94 ,
V_81 | V_84 , L_19 ) ;
V_32 -> V_13 . V_14 = V_89 ;
V_32 -> V_13 . V_16 = V_95 ;
V_32 -> V_13 . V_19 = V_18 ;
V_90 = F_64 ( & V_32 -> V_2 , & V_96 ,
& V_88 -> V_2 , L_20 ) ;
if ( F_65 ( V_90 != 0 ) ) {
F_66 ( & V_32 -> V_2 ) ;
V_32 = NULL ;
return V_90 ;
}
F_29 ( V_32 ) ;
return 0 ;
}
void F_67 ( void )
{
int V_23 ;
F_62 ( L_21 ) ;
F_31 ( V_32 ) ;
for ( V_23 = 0 ; V_23 < V_60 ; ++ V_23 )
F_18 ( & V_32 -> V_33 [ V_23 ] , V_49 ) ;
F_66 ( & V_32 -> V_2 ) ;
V_32 = NULL ;
}
int F_68 ( struct V_97 * V_98 )
{
struct V_87 * V_99 = V_98 -> V_88 -> V_99 ;
unsigned V_23 ;
int V_90 ;
if ( V_98 -> V_100 != V_101 )
return 0 ;
for ( V_23 = 0 ; V_23 < V_98 -> V_102 ; ++ V_23 ) {
V_90 = F_54 ( & V_98 -> V_21 [ V_23 ] , 1 ,
V_98 -> V_103 ,
V_98 -> V_104 ) ;
if ( V_90 != 0 ) {
F_69 ( V_98 ) ;
return - V_76 ;
}
V_90 = F_70 ( V_99 , V_98 -> V_21 [ V_23 ] ,
false , false ) ;
if ( F_65 ( V_90 != 0 ) ) {
F_69 ( V_98 ) ;
return - V_76 ;
}
}
if ( F_65 ( V_98 -> V_103 & V_105 ) ) {
V_90 = F_71 ( V_98 ) ;
if ( F_65 ( V_90 != 0 ) ) {
F_69 ( V_98 ) ;
return V_90 ;
}
}
V_98 -> V_100 = V_106 ;
return 0 ;
}
void F_69 ( struct V_97 * V_98 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_98 -> V_102 ; ++ V_23 ) {
if ( V_98 -> V_21 [ V_23 ] ) {
F_72 ( V_98 -> V_88 -> V_99 ,
V_98 -> V_21 [ V_23 ] ) ;
F_51 ( & V_98 -> V_21 [ V_23 ] , 1 ,
V_98 -> V_103 ,
V_98 -> V_104 ) ;
}
}
V_98 -> V_100 = V_101 ;
}
int F_73 ( struct V_107 * V_4 , void * V_108 )
{
struct V_24 * V_40 ;
unsigned V_23 ;
char * V_109 [] = { L_20 , L_22 , L_23 , L_24 } ;
if ( ! V_32 ) {
F_74 ( V_4 , L_25 ) ;
return 0 ;
}
F_74 ( V_4 , L_26 ,
V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] , V_109 [ 3 ] ) ;
for ( V_23 = 0 ; V_23 < V_60 ; ++ V_23 ) {
V_40 = & V_32 -> V_33 [ V_23 ] ;
F_74 ( V_4 , L_27 ,
V_40 -> V_86 , V_40 -> V_79 ,
V_40 -> V_37 , V_40 -> V_34 ) ;
}
return 0 ;
}
