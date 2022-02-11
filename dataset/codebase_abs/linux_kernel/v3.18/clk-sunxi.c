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
void F_10 ( struct V_13 * V_13 , T_2 V_14 , T_2 V_15 )
{
#define F_11 ( T_3 ) container_of(_hw, struct clk_composite, hw)
#define F_12 ( T_3 ) container_of(_hw, struct clk_factors, hw)
struct V_16 * V_17 = F_13 ( V_13 ) ;
struct V_18 * V_19 = F_11 ( V_17 ) ;
struct V_16 * V_20 = V_19 -> V_20 ;
struct V_21 * V_22 = F_12 ( V_20 ) ;
unsigned long V_23 = 0 ;
T_1 V_24 ;
if ( V_22 -> V_25 )
F_14 ( V_22 -> V_25 , V_23 ) ;
V_24 = F_15 ( V_22 -> V_24 ) ;
V_24 &= ~ ( 0x7 << 20 ) ;
V_24 |= ( ( V_14 & 0x7 ) << 20 ) ;
V_24 &= ~ ( 0x7 << 8 ) ;
V_24 |= ( ( V_15 & 0x7 ) << 8 ) ;
F_16 ( V_24 , V_22 -> V_24 ) ;
if ( V_22 -> V_25 )
F_17 ( V_22 -> V_25 , V_23 ) ;
}
static struct V_13 * T_4 F_18 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
return F_19 ( V_27 , V_29 , & V_30 ) ;
}
static void T_4 F_20 ( struct V_26 * V_27 ,
struct V_31 * V_29 )
{
struct V_13 * V_13 ;
const char * V_32 = V_27 -> V_33 ;
const char * V_34 [ V_35 ] ;
void T_5 * V_24 ;
int V_36 = 0 ;
V_24 = F_21 ( V_27 , 0 ) ;
while ( V_36 < V_35 &&
( V_34 [ V_36 ] = F_22 ( V_27 , V_36 ) ) != NULL )
V_36 ++ ;
F_23 ( V_27 , L_1 , & V_32 ) ;
V_13 = F_24 ( NULL , V_32 , V_34 , V_36 ,
V_37 , V_24 ,
V_29 -> V_38 , V_39 ,
0 , & V_30 ) ;
if ( V_13 ) {
F_25 ( V_27 , V_40 , V_13 ) ;
F_26 ( V_13 , V_32 , NULL ) ;
}
}
static void T_4 F_27 ( struct V_26 * V_27 ,
struct V_41 * V_29 )
{
struct V_13 * V_13 ;
const char * V_32 = V_27 -> V_33 ;
const char * V_42 ;
void T_5 * V_24 ;
V_24 = F_21 ( V_27 , 0 ) ;
V_42 = F_22 ( V_27 , 0 ) ;
F_23 ( V_27 , L_1 , & V_32 ) ;
V_13 = F_28 ( NULL , V_32 , V_42 , 0 ,
V_24 , V_29 -> V_38 , V_29 -> V_43 ,
V_29 -> pow ? V_44 : 0 ,
V_29 -> V_45 , & V_30 ) ;
if ( V_13 ) {
F_25 ( V_27 , V_40 , V_13 ) ;
F_26 ( V_13 , V_32 , NULL ) ;
}
}
static int F_29 ( struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_49 * V_29 = F_30 ( V_47 ,
struct V_49 ,
V_47 ) ;
unsigned long V_23 ;
T_1 V_24 ;
F_14 ( V_29 -> V_25 , V_23 ) ;
V_24 = F_15 ( V_29 -> V_24 ) ;
F_16 ( V_24 & ~ F_31 ( V_48 ) , V_29 -> V_24 ) ;
F_17 ( V_29 -> V_25 , V_23 ) ;
return 0 ;
}
static int F_32 ( struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_49 * V_29 = F_30 ( V_47 ,
struct V_49 ,
V_47 ) ;
unsigned long V_23 ;
T_1 V_24 ;
F_14 ( V_29 -> V_25 , V_23 ) ;
V_24 = F_15 ( V_29 -> V_24 ) ;
F_16 ( V_24 | F_31 ( V_48 ) , V_29 -> V_24 ) ;
F_17 ( V_29 -> V_25 , V_23 ) ;
return 0 ;
}
static void T_4 F_33 ( struct V_26 * V_27 ,
struct V_50 * V_29 )
{
struct V_51 * V_52 ;
struct V_49 * V_53 ;
const char * V_42 ;
const char * V_32 ;
void T_5 * V_24 ;
int V_54 ;
int V_36 = 0 ;
int V_55 = 0 ;
V_24 = F_21 ( V_27 , 0 ) ;
V_42 = F_22 ( V_27 , 0 ) ;
V_54 = F_34 ( V_29 -> V_56 , V_57 ) ;
V_52 = F_35 ( sizeof( struct V_51 ) , V_58 ) ;
if ( ! V_52 )
return;
V_52 -> V_59 = F_36 ( ( V_54 + 1 ) * sizeof( struct V_13 * ) , V_58 ) ;
if ( ! V_52 -> V_59 ) {
F_37 ( V_52 ) ;
return;
}
F_38 (i, data->mask, SUNXI_GATES_MAX_SIZE) {
F_39 ( V_27 , L_1 ,
V_55 , & V_32 ) ;
V_52 -> V_59 [ V_36 ] = F_40 ( NULL , V_32 ,
V_42 , 0 ,
V_24 + 4 * ( V_36 / 32 ) , V_36 % 32 ,
0 , & V_30 ) ;
F_41 ( F_42 ( V_52 -> V_59 [ V_36 ] ) ) ;
F_26 ( V_52 -> V_59 [ V_36 ] , V_32 , NULL ) ;
V_55 ++ ;
}
V_52 -> V_60 = V_36 ;
F_25 ( V_27 , V_61 , V_52 ) ;
if ( V_29 -> V_62 == 0 )
return;
V_53 = F_36 ( sizeof( * V_53 ) , V_58 ) ;
if ( ! V_53 )
return;
V_53 -> V_24 = V_24 ;
V_53 -> V_25 = & V_30 ;
V_53 -> V_47 . V_63 = F_43 ( V_29 -> V_62 ) + 1 ;
V_53 -> V_47 . V_64 = & V_65 ;
V_53 -> V_47 . V_66 = V_27 ;
F_44 ( & V_53 -> V_47 ) ;
}
static void T_4 F_45 ( struct V_26 * V_27 ,
struct V_67 * V_29 )
{
struct V_51 * V_52 ;
const char * V_68 ;
const char * V_32 ;
struct V_13 * * V_59 , * V_69 ;
struct V_16 * V_70 , * V_20 ;
const struct V_71 * V_72 ;
struct V_73 * V_74 = NULL ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
void T_5 * V_24 ;
int V_36 = 0 ;
int V_23 , V_79 ;
V_69 = F_18 ( V_27 , V_29 -> V_22 ) ;
V_68 = F_46 ( V_69 ) ;
V_24 = F_21 ( V_27 , 0 ) ;
V_52 = F_35 ( sizeof( struct V_51 ) , V_58 ) ;
if ( ! V_52 )
return;
V_59 = F_36 ( ( V_80 + 1 ) * sizeof( * V_59 ) , V_58 ) ;
if ( ! V_59 )
goto V_81;
V_52 -> V_59 = V_59 ;
V_79 = ! strcmp ( L_2 , V_68 ) ? 0 : V_82 ;
for ( V_36 = 0 ; V_36 < V_80 ; V_36 ++ ) {
if ( F_39 ( V_27 , L_1 ,
V_36 , & V_32 ) != 0 )
break;
V_70 = NULL ;
V_20 = NULL ;
V_72 = NULL ;
if ( V_29 -> div [ V_36 ] . V_74 ) {
V_74 = F_36 ( sizeof( * V_74 ) , V_58 ) ;
if ( ! V_74 )
goto V_83;
V_74 -> V_24 = V_24 ;
V_74 -> V_84 = V_29 -> div [ V_36 ] . V_74 ;
V_74 -> V_25 = & V_30 ;
V_70 = & V_74 -> V_17 ;
}
if ( V_29 -> div [ V_36 ] . V_85 ) {
V_76 = F_36 ( sizeof( * V_76 ) , V_58 ) ;
if ( ! V_76 )
goto V_86;
V_76 -> V_87 = 1 ;
V_76 -> div = V_29 -> div [ V_36 ] . V_85 ;
V_20 = & V_76 -> V_17 ;
V_72 = & V_88 ;
} else {
V_78 = F_36 ( sizeof( * V_78 ) , V_58 ) ;
if ( ! V_78 )
goto V_86;
V_23 = V_29 -> div [ V_36 ] . pow ? V_44 : 0 ;
V_78 -> V_24 = V_24 ;
V_78 -> V_38 = V_29 -> div [ V_36 ] . V_38 ;
V_78 -> V_43 = V_89 ;
V_78 -> V_23 = V_23 ;
V_78 -> V_25 = & V_30 ;
V_78 -> V_45 = V_29 -> div [ V_36 ] . V_45 ;
V_20 = & V_78 -> V_17 ;
V_72 = & V_90 ;
}
V_59 [ V_36 ] = F_47 ( NULL , V_32 , & V_68 , 1 ,
NULL , NULL ,
V_20 , V_72 ,
V_70 , & V_91 ,
V_79 ) ;
F_41 ( F_42 ( V_52 -> V_59 [ V_36 ] ) ) ;
F_26 ( V_59 [ V_36 ] , V_32 , NULL ) ;
}
V_59 [ V_36 ++ ] = V_69 ;
V_52 -> V_60 = V_36 ;
F_25 ( V_27 , V_61 , V_52 ) ;
return;
V_86:
F_37 ( V_74 ) ;
V_83:
F_37 ( V_59 ) ;
V_81:
F_37 ( V_52 ) ;
}
static void T_4 F_48 ( const struct V_92 * V_93 ,
void * V_94 )
{
struct V_26 * V_95 ;
const struct V_41 * V_29 ;
const struct V_92 * V_96 ;
void (* F_49)( struct V_26 * , const void * ) = V_94 ;
F_50 (np, clk_match, &match) {
V_29 = V_96 -> V_29 ;
F_49 ( V_95 , V_29 ) ;
}
}
static void T_4 F_51 ( const char * V_97 [] , int V_98 )
{
unsigned int V_36 ;
F_48 ( V_99 , F_18 ) ;
F_48 ( V_100 , F_27 ) ;
F_48 ( V_101 , F_45 ) ;
F_48 ( V_102 , F_20 ) ;
F_48 ( V_103 , F_33 ) ;
for ( V_36 = 0 ; V_36 < V_98 ; V_36 ++ ) {
struct V_13 * V_13 = F_52 ( NULL , V_97 [ V_36 ] ) ;
if ( ! F_42 ( V_13 ) )
F_53 ( V_13 ) ;
}
}
static void T_4 F_54 ( struct V_26 * V_27 )
{
F_51 ( V_104 ,
F_55 ( V_104 ) ) ;
}
static void T_4 F_56 ( struct V_26 * V_27 )
{
F_51 ( V_105 ,
F_55 ( V_105 ) ) ;
}
static void T_4 F_57 ( struct V_26 * V_27 )
{
F_51 ( V_106 ,
F_55 ( V_106 ) ) ;
}
