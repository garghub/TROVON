static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( F_4 ( V_7 ) == V_8 )
V_3 /= F_5 ( V_7 ) + 1 ;
V_6 = V_3 >> F_6 ( V_7 ) ;
return V_6 ;
}
static long F_7 ( unsigned long V_6 , T_2 * V_9 , T_2 * V_10 ,
T_2 V_11 , unsigned long V_3 )
{
T_2 div , V_12 , V_13 = 1 ;
if ( V_3 && V_6 > V_3 )
V_6 = V_3 ;
div = F_8 ( V_3 , V_6 ) ;
if ( V_11 == V_8 ) {
if ( div < 4 )
V_12 = 0 ;
else if ( div / 2 < 4 )
V_12 = 1 ;
else if ( div / 4 < 4 )
V_12 = 2 ;
else
V_12 = 3 ;
V_13 = F_8 ( div , 1 << V_12 ) ;
} else {
V_12 = F_9 ( div ) ;
V_12 = V_12 > 3 ? 3 : V_12 ;
}
if ( V_9 ) {
* V_9 = V_12 ;
* V_10 = V_13 - 1 ;
}
return ( V_3 / V_13 ) >> V_12 ;
}
static long F_10 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_14 ,
unsigned long V_15 ,
unsigned long * V_16 ,
struct V_1 * * V_17 )
{
struct V_18 * V_18 = V_2 -> V_18 , * V_11 , * V_19 = NULL ;
int V_20 , V_21 ;
unsigned long V_3 , V_22 = 0 , V_23 , V_24 = 0 ;
V_21 = F_11 ( V_18 ) ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_11 = F_12 ( V_18 , V_20 ) ;
if ( ! V_11 )
continue;
if ( F_13 ( V_18 ) & V_25 )
V_3 = F_14 ( V_11 , V_6 ) ;
else
V_3 = F_15 ( V_11 ) ;
V_23 = F_7 ( V_6 , NULL , NULL , V_20 ,
V_3 ) ;
if ( V_23 <= V_6 && V_23 > V_24 ) {
V_19 = V_11 ;
V_22 = V_3 ;
V_24 = V_23 ;
}
}
if ( V_19 )
* V_17 = F_16 ( V_19 ) ;
* V_16 = V_22 ;
return V_24 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_26 ;
T_2 div , V_27 , V_11 ;
T_1 V_7 ;
F_18 ( & V_28 , V_26 ) ;
V_7 = F_3 ( V_5 -> V_7 ) ;
V_11 = F_4 ( V_7 ) ;
F_7 ( V_6 , & div , & V_27 , V_11 , V_3 ) ;
V_7 = F_19 ( V_7 , div ) ;
V_7 = F_20 ( V_7 , V_27 ) ;
F_21 ( V_7 , V_5 -> V_7 ) ;
F_22 ( & V_28 , V_26 ) ;
return 0 ;
}
static void T_3 F_23 ( struct V_29 * V_30 )
{
struct V_18 * V_18 ;
struct V_4 * V_5 ;
struct V_31 * V_32 ;
const char * V_33 = V_30 -> V_34 ;
const char * V_35 [ V_36 ] ;
void T_4 * V_7 ;
int V_20 = 0 ;
V_7 = F_24 ( V_30 , 0 , F_25 ( V_30 ) ) ;
if ( F_26 ( V_7 ) )
return;
while ( V_20 < V_36 &&
( V_35 [ V_20 ] = F_27 ( V_30 , V_20 ) ) != NULL )
V_20 ++ ;
F_28 ( V_30 , L_1 , & V_33 ) ;
V_5 = F_29 ( sizeof( struct V_4 ) , V_37 ) ;
if ( ! V_5 )
return;
V_32 = F_29 ( sizeof( struct V_31 ) , V_37 ) ;
if ( ! V_32 ) {
F_30 ( V_5 ) ;
return;
}
V_32 -> V_7 = V_7 ;
V_32 -> V_38 = V_39 ;
V_32 -> V_40 = V_41 ;
V_32 -> V_42 = & V_28 ;
V_5 -> V_7 = V_7 ;
V_18 = F_31 ( NULL , V_33 , V_35 , V_20 ,
& V_32 -> V_2 , & V_43 ,
& V_5 -> V_2 , & V_44 ,
NULL , NULL , 0 ) ;
if ( ! F_26 ( V_18 ) ) {
F_32 ( V_30 , V_45 , V_18 ) ;
F_33 ( V_18 , V_33 , NULL ) ;
}
}
static void F_34 ( T_1 * V_46 , T_1 V_3 ,
T_2 * V_47 , T_2 * V_48 , T_2 * V_49 , T_2 * V_50 )
{
T_2 div ;
div = * V_46 / 6000000 ;
* V_46 = 6000000 * div ;
if ( V_47 == NULL )
return;
* V_49 = 0 ;
if ( * V_46 >= 768000000 || * V_46 == 42000000 || * V_46 == 54000000 )
* V_48 = 1 ;
else
* V_48 = 0 ;
if ( div < 10 )
* V_50 = 3 ;
else if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_50 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_50 = 1 ;
else
* V_50 = 0 ;
div <<= * V_50 ;
div /= ( * V_48 + 1 ) ;
* V_47 = div / 4 ;
}
static void F_35 ( T_1 * V_46 , T_1 V_3 ,
T_2 * V_47 , T_2 * V_48 , T_2 * V_49 , T_2 * V_50 )
{
T_1 V_51 = * V_46 / 1000000 ;
T_1 V_52 = V_3 / 1000000 ;
T_1 V_53 = F_36 ( V_51 , 6 ) ;
T_1 V_54 = F_36 ( V_51 , 16 ) ;
if ( V_53 > V_54 )
V_51 = V_53 ;
else
V_51 = V_54 ;
* V_46 = V_51 * 1000000 ;
if ( V_47 == NULL )
return;
if ( ! ( V_51 % 32 ) )
* V_48 = 3 ;
else if ( ! ( V_51 % 9 ) )
* V_48 = 2 ;
else if ( ! ( V_51 % 8 ) )
* V_48 = 1 ;
else
* V_48 = 0 ;
if ( ( V_51 % 6 ) == 2 || ( V_51 % 6 ) == 4 )
* V_49 = 2 ;
else if ( ( V_51 / 6 ) & 1 )
* V_49 = 3 ;
else
* V_49 = 1 ;
* V_47 = V_51 * ( * V_49 + 1 ) / ( ( * V_48 + 1 ) * V_52 ) - 1 ;
if ( ( * V_47 + 1 ) > 31 && ( * V_49 + 1 ) > 1 ) {
* V_47 = ( * V_47 + 1 ) / 2 - 1 ;
* V_49 = ( * V_49 + 1 ) / 2 - 1 ;
}
}
static void F_37 ( T_1 * V_46 , T_1 V_3 ,
T_2 * V_47 , T_2 * V_48 , T_2 * V_49 , T_2 * V_50 )
{
T_2 div ;
div = * V_46 / 6000000 ;
* V_46 = 6000000 * div ;
if ( V_47 == NULL )
return;
* V_49 = 0 ;
if ( * V_46 >= 768000000 || * V_46 == 42000000 || * V_46 == 54000000 )
* V_48 = 1 ;
else
* V_48 = 0 ;
if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_50 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_50 = 1 ;
else
* V_50 = 0 ;
div <<= * V_50 ;
div /= ( * V_48 + 1 ) ;
* V_47 = div / 4 - 1 ;
}
static void F_38 ( T_1 * V_46 , T_1 V_3 ,
T_2 * V_47 , T_2 * V_48 , T_2 * V_49 , T_2 * V_50 )
{
T_2 div ;
div = * V_46 / V_3 ;
* V_46 = V_3 * div ;
if ( V_47 == NULL )
return;
if ( div < 31 )
* V_48 = 0 ;
else if ( div / 2 < 31 )
* V_48 = 1 ;
else if ( div / 3 < 31 )
* V_48 = 2 ;
else
* V_48 = 3 ;
* V_47 = F_8 ( div , ( * V_48 + 1 ) ) ;
}
static void F_39 ( T_1 * V_46 , T_1 V_3 ,
T_2 * V_47 , T_2 * V_48 , T_2 * V_49 , T_2 * V_50 )
{
T_2 div ;
div = * V_46 / V_3 ;
* V_46 = V_3 * div ;
if ( V_47 == NULL )
return;
* V_48 = div / 32 ;
if ( * V_48 > 3 )
* V_48 = 3 ;
* V_47 = F_8 ( div , ( * V_48 + 1 ) ) - 1 ;
}
static void F_40 ( T_1 * V_46 , T_1 V_3 ,
T_2 * V_47 , T_2 * V_48 , T_2 * V_49 , T_2 * V_50 )
{
T_1 div ;
if ( V_3 < * V_46 )
* V_46 = V_3 ;
if ( * V_46 < 8000 )
* V_46 = 8000 ;
if ( * V_46 > 300000000 )
* V_46 = 300000000 ;
div = F_41 ( F_8 ( V_3 , * V_46 ) ) ;
if ( div > 3 )
div = 3 ;
* V_46 = V_3 >> div ;
if ( V_50 == NULL )
return;
* V_50 = div ;
}
static void F_42 ( T_1 * V_46 , T_1 V_3 ,
T_2 * V_47 , T_2 * V_48 , T_2 * V_49 , T_2 * V_50 )
{
T_2 V_13 , V_12 ;
if ( V_3 < * V_46 )
* V_46 = V_3 ;
V_3 = F_8 ( V_3 , * V_46 ) ;
if ( V_3 > 32 )
return;
if ( V_3 <= 4 )
V_12 = 0 ;
else if ( V_3 <= 8 )
V_12 = 1 ;
else if ( V_3 <= 16 )
V_12 = 2 ;
else
V_12 = 3 ;
V_13 = ( V_3 >> V_12 ) - 1 ;
* V_46 = ( V_3 >> V_12 ) / ( V_13 + 1 ) ;
if ( V_47 == NULL )
return;
* V_49 = V_13 ;
* V_50 = V_12 ;
}
static void F_43 ( T_1 * V_46 , T_1 V_3 ,
T_2 * V_47 , T_2 * V_48 , T_2 * V_49 , T_2 * V_50 )
{
T_2 div , V_13 , V_12 ;
if ( * V_46 > V_3 )
* V_46 = V_3 ;
div = F_8 ( V_3 , * V_46 ) ;
if ( div < 32 )
V_12 = 0 ;
else if ( div / 2 < 32 )
V_12 = 1 ;
else if ( div / 4 < 32 )
V_12 = 2 ;
else
V_12 = 3 ;
V_13 = F_8 ( div , 1 << V_12 ) ;
* V_46 = ( V_3 >> V_12 ) / V_13 ;
if ( V_47 == NULL )
return;
* V_49 = V_13 - 1 ;
* V_50 = V_12 ;
}
static struct V_18 * T_3 F_44 ( struct V_29 * V_30 ,
const struct V_55 * V_56 )
{
void T_4 * V_7 ;
V_7 = F_45 ( V_30 , 0 ) ;
if ( ! V_7 ) {
F_46 ( L_2 ,
V_30 -> V_34 ) ;
return NULL ;
}
return F_47 ( V_30 , V_56 , & V_28 , V_7 ) ;
}
static void T_3 F_48 ( struct V_29 * V_30 ,
struct V_57 * V_56 )
{
struct V_18 * V_18 ;
const char * V_33 = V_30 -> V_34 ;
const char * V_35 [ V_58 ] ;
void T_4 * V_7 ;
int V_20 = 0 ;
V_7 = F_45 ( V_30 , 0 ) ;
while ( V_20 < V_58 &&
( V_35 [ V_20 ] = F_27 ( V_30 , V_20 ) ) != NULL )
V_20 ++ ;
F_28 ( V_30 , L_1 , & V_33 ) ;
V_18 = F_49 ( NULL , V_33 , V_35 , V_20 ,
V_25 , V_7 ,
V_56 -> V_38 , V_59 ,
0 , & V_28 ) ;
if ( V_18 ) {
F_32 ( V_30 , V_45 , V_18 ) ;
F_33 ( V_18 , V_33 , NULL ) ;
}
}
static void T_3 F_50 ( struct V_29 * V_30 ,
struct V_60 * V_56 )
{
struct V_18 * V_18 ;
const char * V_33 = V_30 -> V_34 ;
const char * V_61 ;
void T_4 * V_7 ;
V_7 = F_45 ( V_30 , 0 ) ;
V_61 = F_27 ( V_30 , 0 ) ;
F_28 ( V_30 , L_1 , & V_33 ) ;
V_18 = F_51 ( NULL , V_33 , V_61 , 0 ,
V_7 , V_56 -> V_38 , V_56 -> V_62 ,
V_56 -> pow ? V_63 : 0 ,
V_56 -> V_64 , & V_28 ) ;
if ( V_18 ) {
F_32 ( V_30 , V_45 , V_18 ) ;
F_33 ( V_18 , V_33 , NULL ) ;
}
}
static void T_3 F_52 ( struct V_29 * V_30 ,
struct V_65 * V_56 )
{
struct V_66 * V_67 ;
const char * V_61 ;
const char * V_33 ;
void T_4 * V_7 ;
int V_68 ;
int V_20 = 0 ;
int V_69 = 0 ;
V_7 = F_45 ( V_30 , 0 ) ;
V_61 = F_27 ( V_30 , 0 ) ;
V_68 = F_53 ( V_56 -> V_40 , V_70 ) ;
V_67 = F_54 ( sizeof( struct V_66 ) , V_37 ) ;
if ( ! V_67 )
return;
V_67 -> V_71 = F_29 ( ( V_68 + 1 ) * sizeof( struct V_18 * ) , V_37 ) ;
if ( ! V_67 -> V_71 ) {
F_30 ( V_67 ) ;
return;
}
F_55 (i, data->mask, SUNXI_GATES_MAX_SIZE) {
F_56 ( V_30 , L_1 ,
V_69 , & V_33 ) ;
V_67 -> V_71 [ V_20 ] = F_57 ( NULL , V_33 ,
V_61 , 0 ,
V_7 + 4 * ( V_20 / 32 ) , V_20 % 32 ,
0 , & V_28 ) ;
F_58 ( F_26 ( V_67 -> V_71 [ V_20 ] ) ) ;
F_33 ( V_67 -> V_71 [ V_20 ] , V_33 , NULL ) ;
V_69 ++ ;
}
V_67 -> V_72 = V_20 ;
F_32 ( V_30 , V_73 , V_67 ) ;
}
static void T_3 F_59 ( struct V_29 * V_30 ,
struct V_74 * V_56 )
{
struct V_66 * V_67 ;
const char * V_11 ;
const char * V_33 ;
struct V_18 * * V_71 , * V_75 ;
struct V_1 * V_76 , * V_77 ;
const struct V_78 * V_79 ;
struct V_80 * V_81 = NULL ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
void T_4 * V_7 ;
int V_86 = V_87 , V_20 = 0 ;
int V_26 , V_88 ;
if ( V_56 -> V_86 )
V_86 = V_56 -> V_86 ;
V_75 = F_44 ( V_30 , V_56 -> V_89 ) ;
V_11 = F_60 ( V_75 ) ;
V_7 = F_45 ( V_30 , 0 ) ;
V_67 = F_54 ( sizeof( struct V_66 ) , V_37 ) ;
if ( ! V_67 )
return;
V_71 = F_61 ( V_86 , sizeof( * V_71 ) , V_37 ) ;
if ( ! V_71 )
goto V_90;
V_67 -> V_71 = V_71 ;
V_88 = ! strcmp ( L_3 , V_11 ) ? 0 : V_25 ;
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ ) {
if ( F_56 ( V_30 , L_1 ,
V_20 , & V_33 ) != 0 )
break;
if ( V_56 -> div [ V_20 ] . V_91 ) {
V_67 -> V_71 [ V_20 ] = V_75 ;
continue;
}
V_76 = NULL ;
V_77 = NULL ;
V_79 = NULL ;
if ( V_56 -> div [ V_20 ] . V_81 ) {
V_81 = F_29 ( sizeof( * V_81 ) , V_37 ) ;
if ( ! V_81 )
goto V_92;
V_81 -> V_7 = V_7 ;
V_81 -> V_93 = V_56 -> div [ V_20 ] . V_81 ;
V_81 -> V_42 = & V_28 ;
V_76 = & V_81 -> V_2 ;
}
if ( V_56 -> div [ V_20 ] . V_94 ) {
V_83 = F_29 ( sizeof( * V_83 ) , V_37 ) ;
if ( ! V_83 )
goto V_95;
V_83 -> V_96 = 1 ;
V_83 -> div = V_56 -> div [ V_20 ] . V_94 ;
V_77 = & V_83 -> V_2 ;
V_79 = & V_97 ;
} else {
V_85 = F_29 ( sizeof( * V_85 ) , V_37 ) ;
if ( ! V_85 )
goto V_95;
V_26 = V_56 -> div [ V_20 ] . pow ? V_63 : 0 ;
V_85 -> V_7 = V_7 ;
V_85 -> V_38 = V_56 -> div [ V_20 ] . V_38 ;
V_85 -> V_62 = V_98 ;
V_85 -> V_26 = V_26 ;
V_85 -> V_42 = & V_28 ;
V_85 -> V_64 = V_56 -> div [ V_20 ] . V_64 ;
V_77 = & V_85 -> V_2 ;
V_79 = & V_99 ;
}
V_71 [ V_20 ] = F_31 ( NULL , V_33 , & V_11 , 1 ,
NULL , NULL ,
V_77 , V_79 ,
V_76 , & V_100 ,
V_88 ) ;
F_58 ( F_26 ( V_67 -> V_71 [ V_20 ] ) ) ;
F_33 ( V_71 [ V_20 ] , V_33 , NULL ) ;
}
V_67 -> V_72 = V_20 ;
F_32 ( V_30 , V_73 , V_67 ) ;
return;
V_95:
F_30 ( V_81 ) ;
V_92:
F_30 ( V_71 ) ;
V_90:
F_30 ( V_67 ) ;
}
static void T_3 F_62 ( const struct V_101 * V_102 ,
void * V_103 )
{
struct V_29 * V_104 ;
const struct V_60 * V_56 ;
const struct V_101 * V_105 ;
void (* F_63)( struct V_29 * , const void * ) = V_103 ;
F_64 (np, clk_match, &match) {
V_56 = V_105 -> V_56 ;
F_63 ( V_104 , V_56 ) ;
}
}
static void T_3 F_65 ( const char * V_106 [] , int V_107 )
{
unsigned int V_20 ;
F_62 ( V_108 , F_59 ) ;
F_62 ( V_109 , F_44 ) ;
F_62 ( V_110 , F_50 ) ;
F_62 ( V_111 , F_48 ) ;
F_62 ( V_112 , F_52 ) ;
for ( V_20 = 0 ; V_20 < V_107 ; V_20 ++ ) {
struct V_18 * V_18 = F_66 ( NULL , V_106 [ V_20 ] ) ;
if ( ! F_26 ( V_18 ) )
F_67 ( V_18 ) ;
}
}
static void T_3 F_68 ( struct V_29 * V_30 )
{
F_65 ( V_113 ,
F_69 ( V_113 ) ) ;
}
static void T_3 F_70 ( struct V_29 * V_30 )
{
F_65 ( V_114 ,
F_69 ( V_114 ) ) ;
}
static void T_3 F_71 ( struct V_29 * V_30 )
{
F_65 ( V_115 ,
F_69 ( V_115 ) ) ;
}
static void T_3 F_72 ( struct V_29 * V_30 )
{
F_65 ( NULL , 0 ) ;
}
