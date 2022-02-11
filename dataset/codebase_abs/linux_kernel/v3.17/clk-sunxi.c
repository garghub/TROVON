static void F_1 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div ;
div = * V_1 / 6000000 ;
* V_1 = 6000000 * div ;
if ( V_3 == NULL )
return;
* V_5 = 0 ;
if ( * V_1 >= 768000000 || * V_1 == 42000000 || * V_1 == 54000000 )
* V_4 = 1 ;
else
* V_4 = 0 ;
if ( div < 10 )
* V_6 = 3 ;
else if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_6 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_6 = 1 ;
else
* V_6 = 0 ;
div <<= * V_6 ;
div /= ( * V_4 + 1 ) ;
* V_3 = div / 4 ;
}
static void F_2 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_1 V_7 = * V_1 / 1000000 ;
T_1 V_8 = V_2 / 1000000 ;
T_1 V_9 = F_3 ( V_7 , 6 ) ;
T_1 V_10 = F_3 ( V_7 , 16 ) ;
if ( V_9 > V_10 )
V_7 = V_9 ;
else
V_7 = V_10 ;
* V_1 = V_7 * 1000000 ;
if ( V_3 == NULL )
return;
if ( ! ( V_7 % 32 ) )
* V_4 = 3 ;
else if ( ! ( V_7 % 9 ) )
* V_4 = 2 ;
else if ( ! ( V_7 % 8 ) )
* V_4 = 1 ;
else
* V_4 = 0 ;
if ( ( V_7 % 6 ) == 2 || ( V_7 % 6 ) == 4 )
* V_5 = 2 ;
else if ( ( V_7 / 6 ) & 1 )
* V_5 = 3 ;
else
* V_5 = 1 ;
* V_3 = V_7 * ( * V_5 + 1 ) / ( ( * V_4 + 1 ) * V_8 ) - 1 ;
if ( ( * V_3 + 1 ) > 31 && ( * V_5 + 1 ) > 1 ) {
* V_3 = ( * V_3 + 1 ) / 2 - 1 ;
* V_5 = ( * V_5 + 1 ) / 2 - 1 ;
}
}
static void F_4 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div ;
div = * V_1 / 6000000 ;
* V_1 = 6000000 * div ;
if ( V_3 == NULL )
return;
* V_5 = 0 ;
if ( * V_1 >= 768000000 || * V_1 == 42000000 || * V_1 == 54000000 )
* V_4 = 1 ;
else
* V_4 = 0 ;
if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_6 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_6 = 1 ;
else
* V_6 = 0 ;
div <<= * V_6 ;
div /= ( * V_4 + 1 ) ;
* V_3 = div / 4 - 1 ;
}
static void F_5 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div ;
div = * V_1 / V_2 ;
* V_1 = V_2 * div ;
if ( V_3 == NULL )
return;
if ( div < 31 )
* V_4 = 0 ;
else if ( div / 2 < 31 )
* V_4 = 1 ;
else if ( div / 3 < 31 )
* V_4 = 2 ;
else
* V_4 = 3 ;
* V_3 = F_6 ( div , ( * V_4 + 1 ) ) ;
}
static void F_7 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div ;
V_2 = V_2 / 2 ;
div = * V_1 / V_2 ;
* V_1 = V_2 * div ;
if ( V_3 == NULL )
return;
* V_4 = div / 32 ;
if ( * V_4 > 3 )
* V_4 = 3 ;
* V_3 = F_6 ( div , ( * V_4 + 1 ) ) ;
}
static void F_8 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 V_11 , V_12 ;
if ( V_2 < * V_1 )
* V_1 = V_2 ;
V_2 = F_6 ( V_2 , * V_1 ) ;
if ( V_2 > 32 )
return;
if ( V_2 <= 4 )
V_12 = 0 ;
else if ( V_2 <= 8 )
V_12 = 1 ;
else if ( V_2 <= 16 )
V_12 = 2 ;
else
V_12 = 3 ;
V_11 = ( V_2 >> V_12 ) - 1 ;
* V_1 = ( V_2 >> V_12 ) / ( V_11 + 1 ) ;
if ( V_3 == NULL )
return;
* V_5 = V_11 ;
* V_6 = V_12 ;
}
static void F_9 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div , V_11 , V_12 ;
if ( * V_1 > V_2 )
* V_1 = V_2 ;
div = F_6 ( V_2 , * V_1 ) ;
if ( div < 16 )
V_12 = 0 ;
else if ( div / 2 < 16 )
V_12 = 1 ;
else if ( div / 4 < 16 )
V_12 = 2 ;
else
V_12 = 3 ;
V_11 = F_6 ( div , 1 << V_12 ) ;
* V_1 = ( V_2 >> V_12 ) / V_11 ;
if ( V_3 == NULL )
return;
* V_5 = V_11 - 1 ;
* V_6 = V_12 ;
}
static void F_10 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div , V_11 , V_12 ;
if ( * V_1 > V_2 )
* V_1 = V_2 ;
div = F_6 ( V_2 , * V_1 ) ;
if ( div < 32 )
V_12 = 0 ;
else if ( div / 2 < 32 )
V_12 = 1 ;
else if ( div / 4 < 32 )
V_12 = 2 ;
else
V_12 = 3 ;
V_11 = F_6 ( div , 1 << V_12 ) ;
* V_1 = ( V_2 >> V_12 ) / V_11 ;
if ( V_3 == NULL )
return;
* V_5 = V_11 - 1 ;
* V_6 = V_12 ;
}
void F_11 ( struct V_13 * V_13 , T_2 V_14 , T_2 V_15 )
{
#define F_12 ( T_3 ) container_of(_hw, struct clk_composite, hw)
#define F_13 ( T_3 ) container_of(_hw, struct clk_factors, hw)
struct V_16 * V_17 = F_14 ( V_13 ) ;
struct V_18 * V_19 = F_12 ( V_17 ) ;
struct V_16 * V_20 = V_19 -> V_20 ;
struct V_21 * V_22 = F_13 ( V_20 ) ;
unsigned long V_23 = 0 ;
T_1 V_24 ;
if ( V_22 -> V_25 )
F_15 ( V_22 -> V_25 , V_23 ) ;
V_24 = F_16 ( V_22 -> V_24 ) ;
V_24 &= ~ ( 0x7 << 20 ) ;
V_24 |= ( ( V_14 & 0x7 ) << 20 ) ;
V_24 &= ~ ( 0x7 << 8 ) ;
V_24 |= ( ( V_15 & 0x7 ) << 8 ) ;
F_17 ( V_24 , V_22 -> V_24 ) ;
if ( V_22 -> V_25 )
F_18 ( V_22 -> V_25 , V_23 ) ;
}
static struct V_13 * T_4 F_19 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
struct V_13 * V_13 ;
struct V_21 * V_22 ;
struct V_30 * V_31 = NULL ;
struct V_32 * V_33 = NULL ;
struct V_16 * V_34 = NULL ;
struct V_16 * V_35 = NULL ;
const char * V_36 = V_27 -> V_37 ;
const char * V_38 [ V_39 ] ;
void T_5 * V_24 ;
int V_40 = 0 ;
V_24 = F_20 ( V_27 , 0 ) ;
while ( V_40 < V_39 &&
( V_38 [ V_40 ] = F_21 ( V_27 , V_40 ) ) != NULL )
V_40 ++ ;
if ( V_29 -> V_37 )
V_36 = V_29 -> V_37 ;
else
F_22 ( V_27 , L_1 , & V_36 ) ;
V_22 = F_23 ( sizeof( struct V_21 ) , V_41 ) ;
if ( ! V_22 )
return NULL ;
if ( V_29 -> V_42 ) {
V_31 = F_23 ( sizeof( struct V_30 ) , V_41 ) ;
if ( ! V_31 ) {
F_24 ( V_22 ) ;
return NULL ;
}
V_31 -> V_24 = V_24 ;
V_31 -> V_43 = V_29 -> V_42 ;
V_31 -> V_25 = & V_44 ;
V_34 = & V_31 -> V_17 ;
}
if ( V_29 -> V_33 ) {
V_33 = F_23 ( sizeof( struct V_32 ) , V_41 ) ;
if ( ! V_33 ) {
F_24 ( V_22 ) ;
F_24 ( V_31 ) ;
return NULL ;
}
V_33 -> V_24 = V_24 ;
V_33 -> V_45 = V_29 -> V_33 ;
V_33 -> V_46 = V_47 ;
V_33 -> V_25 = & V_44 ;
V_35 = & V_33 -> V_17 ;
}
V_22 -> V_24 = V_24 ;
V_22 -> V_48 = V_29 -> V_49 ;
V_22 -> V_50 = V_29 -> V_51 ;
V_22 -> V_25 = & V_44 ;
V_13 = F_25 ( NULL , V_36 ,
V_38 , V_40 ,
V_35 , & V_52 ,
& V_22 -> V_17 , & V_53 ,
V_34 , & V_54 , 0 ) ;
if ( ! F_26 ( V_13 ) ) {
F_27 ( V_27 , V_55 , V_13 ) ;
F_28 ( V_13 , V_36 , NULL ) ;
}
return V_13 ;
}
static void T_4 F_29 ( struct V_26 * V_27 ,
struct V_56 * V_29 )
{
struct V_13 * V_13 ;
const char * V_36 = V_27 -> V_37 ;
const char * V_38 [ V_39 ] ;
void T_5 * V_24 ;
int V_40 = 0 ;
V_24 = F_20 ( V_27 , 0 ) ;
while ( V_40 < V_39 &&
( V_38 [ V_40 ] = F_21 ( V_27 , V_40 ) ) != NULL )
V_40 ++ ;
F_22 ( V_27 , L_1 , & V_36 ) ;
V_13 = F_30 ( NULL , V_36 , V_38 , V_40 ,
V_57 , V_24 ,
V_29 -> V_45 , V_58 ,
0 , & V_44 ) ;
if ( V_13 ) {
F_27 ( V_27 , V_55 , V_13 ) ;
F_28 ( V_13 , V_36 , NULL ) ;
}
}
static void T_4 F_31 ( struct V_26 * V_27 ,
struct V_59 * V_29 )
{
struct V_13 * V_13 ;
const char * V_36 = V_27 -> V_37 ;
const char * V_60 ;
void T_5 * V_24 ;
V_24 = F_20 ( V_27 , 0 ) ;
V_60 = F_21 ( V_27 , 0 ) ;
F_22 ( V_27 , L_1 , & V_36 ) ;
V_13 = F_32 ( NULL , V_36 , V_60 , 0 ,
V_24 , V_29 -> V_45 , V_29 -> V_61 ,
V_29 -> pow ? V_62 : 0 ,
V_29 -> V_49 , & V_44 ) ;
if ( V_13 ) {
F_27 ( V_27 , V_55 , V_13 ) ;
F_28 ( V_13 , V_36 , NULL ) ;
}
}
static int F_33 ( struct V_63 * V_64 ,
unsigned long V_65 )
{
struct V_66 * V_29 = F_34 ( V_64 ,
struct V_66 ,
V_64 ) ;
unsigned long V_23 ;
T_1 V_24 ;
F_15 ( V_29 -> V_25 , V_23 ) ;
V_24 = F_16 ( V_29 -> V_24 ) ;
F_17 ( V_24 & ~ F_35 ( V_65 ) , V_29 -> V_24 ) ;
F_18 ( V_29 -> V_25 , V_23 ) ;
return 0 ;
}
static int F_36 ( struct V_63 * V_64 ,
unsigned long V_65 )
{
struct V_66 * V_29 = F_34 ( V_64 ,
struct V_66 ,
V_64 ) ;
unsigned long V_23 ;
T_1 V_24 ;
F_15 ( V_29 -> V_25 , V_23 ) ;
V_24 = F_16 ( V_29 -> V_24 ) ;
F_17 ( V_24 | F_35 ( V_65 ) , V_29 -> V_24 ) ;
F_18 ( V_29 -> V_25 , V_23 ) ;
return 0 ;
}
static void T_4 F_37 ( struct V_26 * V_27 ,
struct V_67 * V_29 )
{
struct V_68 * V_69 ;
struct V_66 * V_70 ;
const char * V_60 ;
const char * V_36 ;
void T_5 * V_24 ;
int V_71 ;
int V_40 = 0 ;
int V_72 = 0 ;
V_24 = F_20 ( V_27 , 0 ) ;
V_60 = F_21 ( V_27 , 0 ) ;
V_71 = F_38 ( V_29 -> V_46 , V_73 ) ;
V_69 = F_39 ( sizeof( struct V_68 ) , V_41 ) ;
if ( ! V_69 )
return;
V_69 -> V_74 = F_23 ( ( V_71 + 1 ) * sizeof( struct V_13 * ) , V_41 ) ;
if ( ! V_69 -> V_74 ) {
F_24 ( V_69 ) ;
return;
}
F_40 (i, data->mask, SUNXI_GATES_MAX_SIZE) {
F_41 ( V_27 , L_1 ,
V_72 , & V_36 ) ;
V_69 -> V_74 [ V_40 ] = F_42 ( NULL , V_36 ,
V_60 , 0 ,
V_24 + 4 * ( V_40 / 32 ) , V_40 % 32 ,
0 , & V_44 ) ;
F_43 ( F_26 ( V_69 -> V_74 [ V_40 ] ) ) ;
F_28 ( V_69 -> V_74 [ V_40 ] , V_36 , NULL ) ;
V_72 ++ ;
}
V_69 -> V_75 = V_40 ;
F_27 ( V_27 , V_76 , V_69 ) ;
if ( V_29 -> V_77 == 0 )
return;
V_70 = F_23 ( sizeof( * V_70 ) , V_41 ) ;
if ( ! V_70 )
return;
V_70 -> V_24 = V_24 ;
V_70 -> V_25 = & V_44 ;
V_70 -> V_64 . V_78 = F_44 ( V_29 -> V_77 ) + 1 ;
V_70 -> V_64 . V_79 = & V_80 ;
V_70 -> V_64 . V_81 = V_27 ;
F_45 ( & V_70 -> V_64 ) ;
}
static void T_4 F_46 ( struct V_26 * V_27 ,
struct V_82 * V_29 )
{
struct V_68 * V_69 ;
const char * V_83 ;
const char * V_36 ;
struct V_13 * * V_74 , * V_84 ;
struct V_16 * V_34 , * V_20 ;
const struct V_85 * V_86 ;
struct V_30 * V_31 = NULL ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
void T_5 * V_24 ;
int V_40 = 0 ;
int V_23 , V_91 ;
V_84 = F_19 ( V_27 , V_29 -> V_22 ) ;
V_83 = F_47 ( V_84 ) ;
V_24 = F_20 ( V_27 , 0 ) ;
V_69 = F_39 ( sizeof( struct V_68 ) , V_41 ) ;
if ( ! V_69 )
return;
V_74 = F_23 ( ( V_92 + 1 ) * sizeof( * V_74 ) , V_41 ) ;
if ( ! V_74 )
goto V_93;
V_69 -> V_74 = V_74 ;
V_91 = ! strcmp ( L_2 , V_83 ) ? 0 : V_94 ;
for ( V_40 = 0 ; V_40 < V_92 ; V_40 ++ ) {
if ( F_41 ( V_27 , L_1 ,
V_40 , & V_36 ) != 0 )
break;
V_34 = NULL ;
V_20 = NULL ;
V_86 = NULL ;
if ( V_29 -> div [ V_40 ] . V_31 ) {
V_31 = F_23 ( sizeof( * V_31 ) , V_41 ) ;
if ( ! V_31 )
goto V_95;
V_31 -> V_24 = V_24 ;
V_31 -> V_43 = V_29 -> div [ V_40 ] . V_31 ;
V_31 -> V_25 = & V_44 ;
V_34 = & V_31 -> V_17 ;
}
if ( V_29 -> div [ V_40 ] . V_96 ) {
V_88 = F_23 ( sizeof( * V_88 ) , V_41 ) ;
if ( ! V_88 )
goto V_97;
V_88 -> V_98 = 1 ;
V_88 -> div = V_29 -> div [ V_40 ] . V_96 ;
V_20 = & V_88 -> V_17 ;
V_86 = & V_99 ;
} else {
V_90 = F_23 ( sizeof( * V_90 ) , V_41 ) ;
if ( ! V_90 )
goto V_97;
V_23 = V_29 -> div [ V_40 ] . pow ? V_62 : 0 ;
V_90 -> V_24 = V_24 ;
V_90 -> V_45 = V_29 -> div [ V_40 ] . V_45 ;
V_90 -> V_61 = V_100 ;
V_90 -> V_23 = V_23 ;
V_90 -> V_25 = & V_44 ;
V_90 -> V_49 = V_29 -> div [ V_40 ] . V_49 ;
V_20 = & V_90 -> V_17 ;
V_86 = & V_101 ;
}
V_74 [ V_40 ] = F_25 ( NULL , V_36 , & V_83 , 1 ,
NULL , NULL ,
V_20 , V_86 ,
V_34 , & V_54 ,
V_91 ) ;
F_43 ( F_26 ( V_69 -> V_74 [ V_40 ] ) ) ;
F_28 ( V_74 [ V_40 ] , V_36 , NULL ) ;
}
V_74 [ V_40 ++ ] = V_84 ;
V_69 -> V_75 = V_40 ;
F_27 ( V_27 , V_76 , V_69 ) ;
return;
V_97:
F_24 ( V_31 ) ;
V_95:
F_24 ( V_74 ) ;
V_93:
F_24 ( V_69 ) ;
}
static void T_4 F_48 ( const struct V_102 * V_103 ,
void * V_104 )
{
struct V_26 * V_105 ;
const struct V_59 * V_29 ;
const struct V_102 * V_106 ;
void (* F_49)( struct V_26 * , const void * ) = V_104 ;
F_50 (np, clk_match, &match) {
V_29 = V_106 -> V_29 ;
F_49 ( V_105 , V_29 ) ;
}
}
static void T_4 F_51 ( const char * V_107 [] , int V_108 )
{
unsigned int V_40 ;
F_48 ( V_109 , F_19 ) ;
F_48 ( V_110 , F_31 ) ;
F_48 ( V_111 , F_46 ) ;
F_48 ( V_112 , F_29 ) ;
F_48 ( V_113 , F_37 ) ;
for ( V_40 = 0 ; V_40 < V_108 ; V_40 ++ ) {
struct V_13 * V_13 = F_52 ( NULL , V_107 [ V_40 ] ) ;
if ( ! F_26 ( V_13 ) )
F_53 ( V_13 ) ;
}
}
static void T_4 F_54 ( struct V_26 * V_27 )
{
F_51 ( V_114 ,
F_55 ( V_114 ) ) ;
}
static void T_4 F_56 ( struct V_26 * V_27 )
{
F_51 ( V_115 ,
F_55 ( V_115 ) ) ;
}
static void T_4 F_57 ( struct V_26 * V_27 )
{
F_51 ( V_116 ,
F_55 ( V_116 ) ) ;
}
