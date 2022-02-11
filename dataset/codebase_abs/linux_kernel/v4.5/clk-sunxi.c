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
static int F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_1 * V_11 , * V_16 = NULL ;
int V_17 , V_18 ;
unsigned long V_3 , V_19 = 0 , V_20 , V_21 = 0 ;
V_18 = F_11 ( V_2 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_11 = F_12 ( V_2 , V_17 ) ;
if ( ! V_11 )
continue;
if ( F_13 ( V_2 ) & V_22 )
V_3 = F_14 ( V_11 , V_15 -> V_6 ) ;
else
V_3 = F_15 ( V_11 ) ;
V_20 = F_7 ( V_15 -> V_6 , NULL , NULL , V_17 ,
V_3 ) ;
if ( V_20 <= V_15 -> V_6 && V_20 > V_21 ) {
V_16 = V_11 ;
V_19 = V_3 ;
V_21 = V_20 ;
}
}
if ( ! V_16 )
return - V_23 ;
V_15 -> V_24 = V_16 ;
V_15 -> V_25 = V_19 ;
V_15 -> V_6 = V_21 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_26 ;
T_2 div , V_27 , V_11 ;
T_1 V_7 ;
F_17 ( & V_28 , V_26 ) ;
V_7 = F_3 ( V_5 -> V_7 ) ;
V_11 = F_4 ( V_7 ) ;
F_7 ( V_6 , & div , & V_27 , V_11 , V_3 ) ;
V_7 = F_18 ( V_7 , div ) ;
V_7 = F_19 ( V_7 , V_27 ) ;
F_20 ( V_7 , V_5 -> V_7 ) ;
F_21 ( & V_28 , V_26 ) ;
return 0 ;
}
static void T_3 F_22 ( struct V_29 * V_30 )
{
struct V_31 * V_31 ;
struct V_4 * V_5 ;
struct V_32 * V_33 ;
const char * V_34 = V_30 -> V_35 ;
const char * V_36 [ V_37 ] ;
void T_4 * V_7 ;
int V_17 ;
V_7 = F_23 ( V_30 , 0 , F_24 ( V_30 ) ) ;
if ( F_25 ( V_7 ) )
return;
V_17 = F_26 ( V_30 , V_36 , V_37 ) ;
F_27 ( V_30 , L_1 , & V_34 ) ;
V_5 = F_28 ( sizeof( struct V_4 ) , V_38 ) ;
if ( ! V_5 )
return;
V_33 = F_28 ( sizeof( struct V_32 ) , V_38 ) ;
if ( ! V_33 ) {
F_29 ( V_5 ) ;
return;
}
V_33 -> V_7 = V_7 ;
V_33 -> V_39 = V_40 ;
V_33 -> V_41 = V_42 ;
V_33 -> V_43 = & V_28 ;
V_5 -> V_7 = V_7 ;
V_31 = F_30 ( NULL , V_34 , V_36 , V_17 ,
& V_33 -> V_2 , & V_44 ,
& V_5 -> V_2 , & V_45 ,
NULL , NULL , 0 ) ;
if ( ! F_25 ( V_31 ) ) {
F_31 ( V_30 , V_46 , V_31 ) ;
F_32 ( V_31 , V_34 , NULL ) ;
}
}
static void F_33 ( T_1 * V_47 , T_1 V_3 ,
T_2 * V_48 , T_2 * V_49 , T_2 * V_50 , T_2 * V_51 )
{
T_2 div ;
div = * V_47 / 6000000 ;
* V_47 = 6000000 * div ;
if ( V_48 == NULL )
return;
* V_50 = 0 ;
if ( * V_47 >= 768000000 || * V_47 == 42000000 || * V_47 == 54000000 )
* V_49 = 1 ;
else
* V_49 = 0 ;
if ( div < 10 )
* V_51 = 3 ;
else if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_51 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_51 = 1 ;
else
* V_51 = 0 ;
div <<= * V_51 ;
div /= ( * V_49 + 1 ) ;
* V_48 = div / 4 ;
}
static void F_34 ( T_1 * V_47 , T_1 V_3 ,
T_2 * V_48 , T_2 * V_49 , T_2 * V_50 , T_2 * V_51 )
{
T_1 V_52 = * V_47 / 1000000 ;
T_1 V_53 = V_3 / 1000000 ;
T_1 V_54 = F_35 ( V_52 , 6 ) ;
T_1 V_55 = F_35 ( V_52 , 16 ) ;
if ( V_54 > V_55 )
V_52 = V_54 ;
else
V_52 = V_55 ;
* V_47 = V_52 * 1000000 ;
if ( V_48 == NULL )
return;
if ( ! ( V_52 % 32 ) )
* V_49 = 3 ;
else if ( ! ( V_52 % 9 ) )
* V_49 = 2 ;
else if ( ! ( V_52 % 8 ) )
* V_49 = 1 ;
else
* V_49 = 0 ;
if ( ( V_52 % 6 ) == 2 || ( V_52 % 6 ) == 4 )
* V_50 = 2 ;
else if ( ( V_52 / 6 ) & 1 )
* V_50 = 3 ;
else
* V_50 = 1 ;
* V_48 = V_52 * ( * V_50 + 1 ) / ( ( * V_49 + 1 ) * V_53 ) - 1 ;
if ( ( * V_48 + 1 ) > 31 && ( * V_50 + 1 ) > 1 ) {
* V_48 = ( * V_48 + 1 ) / 2 - 1 ;
* V_50 = ( * V_50 + 1 ) / 2 - 1 ;
}
}
static void F_36 ( T_1 * V_47 , T_1 V_3 ,
T_2 * V_48 , T_2 * V_49 , T_2 * V_50 , T_2 * V_51 )
{
T_2 div ;
div = * V_47 / 6000000 ;
* V_47 = 6000000 * div ;
if ( V_48 == NULL )
return;
* V_50 = 0 ;
if ( * V_47 >= 768000000 || * V_47 == 42000000 || * V_47 == 54000000 )
* V_49 = 1 ;
else
* V_49 = 0 ;
if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_51 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_51 = 1 ;
else
* V_51 = 0 ;
div <<= * V_51 ;
div /= ( * V_49 + 1 ) ;
* V_48 = div / 4 - 1 ;
}
static void F_37 ( T_1 * V_47 , T_1 V_3 ,
T_2 * V_48 , T_2 * V_49 , T_2 * V_50 , T_2 * V_51 )
{
T_2 div ;
div = * V_47 / V_3 ;
* V_47 = V_3 * div ;
if ( V_48 == NULL )
return;
if ( div < 31 )
* V_49 = 0 ;
else if ( div / 2 < 31 )
* V_49 = 1 ;
else if ( div / 3 < 31 )
* V_49 = 2 ;
else
* V_49 = 3 ;
* V_48 = F_8 ( div , ( * V_49 + 1 ) ) ;
}
static void F_38 ( T_1 * V_47 , T_1 V_3 ,
T_2 * V_48 , T_2 * V_49 , T_2 * V_50 , T_2 * V_51 )
{
T_2 div ;
div = * V_47 / V_3 ;
* V_47 = V_3 * div ;
if ( V_48 == NULL )
return;
* V_49 = div / 32 ;
if ( * V_49 > 3 )
* V_49 = 3 ;
* V_48 = F_8 ( div , ( * V_49 + 1 ) ) - 1 ;
}
static void F_39 ( T_1 * V_47 , T_1 V_3 ,
T_2 * V_48 , T_2 * V_49 , T_2 * V_50 , T_2 * V_51 )
{
T_1 div ;
if ( V_3 < * V_47 )
* V_47 = V_3 ;
if ( * V_47 < 8000 )
* V_47 = 8000 ;
if ( * V_47 > 300000000 )
* V_47 = 300000000 ;
div = F_40 ( F_8 ( V_3 , * V_47 ) ) ;
if ( div > 3 )
div = 3 ;
* V_47 = V_3 >> div ;
if ( V_51 == NULL )
return;
* V_51 = div ;
}
static void F_41 ( T_1 * V_47 , T_1 V_3 ,
T_2 * V_48 , T_2 * V_49 , T_2 * V_50 , T_2 * V_51 )
{
T_2 V_13 , V_12 ;
if ( V_3 < * V_47 )
* V_47 = V_3 ;
V_3 = F_8 ( V_3 , * V_47 ) ;
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
* V_47 = ( V_3 >> V_12 ) / ( V_13 + 1 ) ;
if ( V_48 == NULL )
return;
* V_50 = V_13 ;
* V_51 = V_12 ;
}
static void F_42 ( T_1 * V_47 , T_1 V_3 ,
T_2 * V_48 , T_2 * V_49 , T_2 * V_50 , T_2 * V_51 )
{
T_2 div , V_13 , V_12 ;
if ( * V_47 > V_3 )
* V_47 = V_3 ;
div = F_8 ( V_3 , * V_47 ) ;
if ( div < 32 )
V_12 = 0 ;
else if ( div / 2 < 32 )
V_12 = 1 ;
else if ( div / 4 < 32 )
V_12 = 2 ;
else
V_12 = 3 ;
V_13 = F_8 ( div , 1 << V_12 ) ;
* V_47 = ( V_3 >> V_12 ) / V_13 ;
if ( V_48 == NULL )
return;
* V_50 = V_13 - 1 ;
* V_51 = V_12 ;
}
static struct V_31 * T_3 F_43 ( struct V_29 * V_30 ,
const struct V_56 * V_57 )
{
void T_4 * V_7 ;
V_7 = F_44 ( V_30 , 0 ) ;
if ( ! V_7 ) {
F_45 ( L_2 ,
V_30 -> V_35 ) ;
return NULL ;
}
return F_46 ( V_30 , V_57 , & V_28 , V_7 ) ;
}
static void T_3 F_47 ( struct V_29 * V_30 ,
struct V_58 * V_57 )
{
struct V_31 * V_31 ;
const char * V_34 = V_30 -> V_35 ;
const char * V_36 [ V_59 ] ;
void T_4 * V_7 ;
int V_17 ;
V_7 = F_44 ( V_30 , 0 ) ;
V_17 = F_26 ( V_30 , V_36 , V_59 ) ;
F_27 ( V_30 , L_1 , & V_34 ) ;
V_31 = F_48 ( NULL , V_34 , V_36 , V_17 ,
V_22 , V_7 ,
V_57 -> V_39 , V_60 ,
0 , & V_28 ) ;
if ( V_31 ) {
F_31 ( V_30 , V_46 , V_31 ) ;
F_32 ( V_31 , V_34 , NULL ) ;
}
}
static void T_3 F_49 ( struct V_29 * V_30 ,
struct V_61 * V_57 )
{
struct V_31 * V_31 ;
const char * V_34 = V_30 -> V_35 ;
const char * V_62 ;
void T_4 * V_7 ;
V_7 = F_44 ( V_30 , 0 ) ;
V_62 = F_50 ( V_30 , 0 ) ;
F_27 ( V_30 , L_1 , & V_34 ) ;
V_31 = F_51 ( NULL , V_34 , V_62 , 0 ,
V_7 , V_57 -> V_39 , V_57 -> V_63 ,
V_57 -> pow ? V_64 : 0 ,
V_57 -> V_65 , & V_28 ) ;
if ( V_31 ) {
F_31 ( V_30 , V_46 , V_31 ) ;
F_32 ( V_31 , V_34 , NULL ) ;
}
}
static void T_3 F_52 ( struct V_29 * V_30 ,
struct V_66 * V_57 )
{
struct V_67 * V_68 ;
const char * V_11 ;
const char * V_34 ;
struct V_31 * * V_69 , * V_70 ;
struct V_1 * V_71 , * V_72 ;
const struct V_73 * V_74 ;
struct V_75 * V_76 = NULL ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
void T_4 * V_7 ;
int V_81 = V_82 , V_17 = 0 ;
int V_26 , V_83 ;
if ( V_57 -> V_81 )
V_81 = V_57 -> V_81 ;
V_70 = F_43 ( V_30 , V_57 -> V_84 ) ;
V_11 = F_53 ( V_70 ) ;
V_7 = F_44 ( V_30 , 0 ) ;
V_68 = F_54 ( sizeof( struct V_67 ) , V_38 ) ;
if ( ! V_68 )
return;
V_69 = F_55 ( V_81 , sizeof( * V_69 ) , V_38 ) ;
if ( ! V_69 )
goto V_85;
V_68 -> V_69 = V_69 ;
V_83 = ! strcmp ( L_3 , V_11 ) ? 0 : V_22 ;
for ( V_17 = 0 ; V_17 < V_81 ; V_17 ++ ) {
if ( F_56 ( V_30 , L_1 ,
V_17 , & V_34 ) != 0 )
break;
if ( V_57 -> div [ V_17 ] . V_86 ) {
V_68 -> V_69 [ V_17 ] = V_70 ;
continue;
}
V_71 = NULL ;
V_72 = NULL ;
V_74 = NULL ;
if ( V_57 -> div [ V_17 ] . V_76 ) {
V_76 = F_28 ( sizeof( * V_76 ) , V_38 ) ;
if ( ! V_76 )
goto V_87;
V_76 -> V_7 = V_7 ;
V_76 -> V_88 = V_57 -> div [ V_17 ] . V_76 ;
V_76 -> V_43 = & V_28 ;
V_71 = & V_76 -> V_2 ;
}
if ( V_57 -> div [ V_17 ] . V_89 ) {
V_78 = F_28 ( sizeof( * V_78 ) , V_38 ) ;
if ( ! V_78 )
goto V_90;
V_78 -> V_91 = 1 ;
V_78 -> div = V_57 -> div [ V_17 ] . V_89 ;
V_72 = & V_78 -> V_2 ;
V_74 = & V_92 ;
} else {
V_80 = F_28 ( sizeof( * V_80 ) , V_38 ) ;
if ( ! V_80 )
goto V_90;
V_26 = V_57 -> div [ V_17 ] . pow ? V_64 : 0 ;
V_80 -> V_7 = V_7 ;
V_80 -> V_39 = V_57 -> div [ V_17 ] . V_39 ;
V_80 -> V_63 = V_93 ;
V_80 -> V_26 = V_26 ;
V_80 -> V_43 = & V_28 ;
V_80 -> V_65 = V_57 -> div [ V_17 ] . V_65 ;
V_72 = & V_80 -> V_2 ;
V_74 = & V_94 ;
}
V_69 [ V_17 ] = F_30 ( NULL , V_34 , & V_11 , 1 ,
NULL , NULL ,
V_72 , V_74 ,
V_71 , & V_95 ,
V_83 ) ;
F_57 ( F_25 ( V_68 -> V_69 [ V_17 ] ) ) ;
F_32 ( V_69 [ V_17 ] , V_34 , NULL ) ;
}
V_68 -> V_96 = V_17 ;
F_31 ( V_30 , V_97 , V_68 ) ;
return;
V_90:
F_29 ( V_76 ) ;
V_87:
F_29 ( V_69 ) ;
V_85:
F_29 ( V_68 ) ;
}
static void T_3 F_58 ( const struct V_98 * V_99 ,
void * V_100 )
{
struct V_29 * V_101 ;
const struct V_61 * V_57 ;
const struct V_98 * V_102 ;
void (* F_59)( struct V_29 * , const void * ) = V_100 ;
F_60 (np, clk_match, &match) {
V_57 = V_102 -> V_57 ;
F_59 ( V_101 , V_57 ) ;
}
}
static void T_3 F_61 ( const char * V_103 [] , int V_104 )
{
unsigned int V_17 ;
F_58 ( V_105 , F_52 ) ;
F_58 ( V_106 , F_43 ) ;
F_58 ( V_107 , F_49 ) ;
F_58 ( V_108 , F_47 ) ;
for ( V_17 = 0 ; V_17 < V_104 ; V_17 ++ ) {
struct V_31 * V_31 = F_62 ( NULL , V_103 [ V_17 ] ) ;
if ( ! F_25 ( V_31 ) )
F_63 ( V_31 ) ;
}
}
static void T_3 F_64 ( struct V_29 * V_30 )
{
F_61 ( V_109 ,
F_65 ( V_109 ) ) ;
}
static void T_3 F_66 ( struct V_29 * V_30 )
{
F_61 ( V_110 ,
F_65 ( V_110 ) ) ;
}
static void T_3 F_67 ( struct V_29 * V_30 )
{
F_61 ( V_111 ,
F_65 ( V_111 ) ) ;
}
static void T_3 F_68 ( struct V_29 * V_30 )
{
F_61 ( NULL , 0 ) ;
}
