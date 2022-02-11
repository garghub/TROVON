static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
const char * V_8 = V_2 -> V_9 ;
T_2 V_10 ;
if ( F_2 ( V_2 , L_1 , & V_10 ) )
return;
V_5 = F_3 ( sizeof( struct V_4 ) , V_11 ) ;
if ( ! V_5 )
return;
V_7 = F_3 ( sizeof( struct V_6 ) , V_11 ) ;
if ( ! V_7 )
goto V_12;
V_7 -> V_13 = F_4 ( V_2 , 0 ) ;
V_7 -> V_14 = V_15 ;
V_7 -> V_16 = & V_17 ;
V_5 -> V_18 = V_10 ;
V_3 = F_5 ( NULL , V_8 ,
NULL , 0 ,
NULL , NULL ,
& V_5 -> V_19 , & V_20 ,
& V_7 -> V_19 , & V_21 ,
V_22 ) ;
if ( F_6 ( V_3 ) )
goto V_23;
F_7 ( V_2 , V_24 , V_3 ) ;
F_8 ( V_3 , V_8 , NULL ) ;
return;
V_23:
F_9 ( V_7 ) ;
V_12:
F_9 ( V_5 ) ;
}
static void F_10 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div ;
div = * V_25 / 6000000 ;
* V_25 = 6000000 * div ;
if ( V_27 == NULL )
return;
* V_29 = 0 ;
if ( * V_25 >= 768000000 || * V_25 == 42000000 || * V_25 == 54000000 )
* V_28 = 1 ;
else
* V_28 = 0 ;
if ( div < 10 )
* V_30 = 3 ;
else if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_30 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_30 = 1 ;
else
* V_30 = 0 ;
div <<= * V_30 ;
div /= ( * V_28 + 1 ) ;
* V_27 = div / 4 ;
}
static void F_11 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_2 V_31 = * V_25 / 1000000 ;
T_2 V_32 = V_26 / 1000000 ;
T_2 V_33 = F_12 ( V_31 , 6 ) ;
T_2 V_34 = F_12 ( V_31 , 16 ) ;
if ( V_33 > V_34 )
V_31 = V_33 ;
else
V_31 = V_34 ;
* V_25 = V_31 * 1000000 ;
if ( V_27 == NULL )
return;
if ( ! ( V_31 % 32 ) )
* V_28 = 3 ;
else if ( ! ( V_31 % 9 ) )
* V_28 = 2 ;
else if ( ! ( V_31 % 8 ) )
* V_28 = 1 ;
else
* V_28 = 0 ;
if ( ( V_31 % 6 ) == 2 || ( V_31 % 6 ) == 4 )
* V_29 = 2 ;
else if ( ( V_31 / 6 ) & 1 )
* V_29 = 3 ;
else
* V_29 = 1 ;
* V_27 = V_31 * ( * V_29 + 1 ) / ( ( * V_28 + 1 ) * V_32 ) - 1 ;
if ( ( * V_27 + 1 ) > 31 && ( * V_29 + 1 ) > 1 ) {
* V_27 = ( * V_27 + 1 ) / 2 - 1 ;
* V_29 = ( * V_29 + 1 ) / 2 - 1 ;
}
}
static void F_13 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div ;
div = * V_25 / V_26 ;
* V_25 = V_26 * div ;
if ( V_27 == NULL )
return;
if ( div < 31 )
* V_28 = 0 ;
else if ( div / 2 < 31 )
* V_28 = 1 ;
else if ( div / 3 < 31 )
* V_28 = 2 ;
else
* V_28 = 3 ;
* V_27 = F_14 ( div , ( * V_28 + 1 ) ) ;
}
static void F_15 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 V_35 , V_36 ;
if ( V_26 < * V_25 )
* V_25 = V_26 ;
V_26 = ( V_26 + ( * V_25 - 1 ) ) / * V_25 ;
if ( V_26 > 32 )
return;
if ( V_26 <= 4 )
V_36 = 0 ;
else if ( V_26 <= 8 )
V_36 = 1 ;
else if ( V_26 <= 16 )
V_36 = 2 ;
else
V_36 = 3 ;
V_35 = ( V_26 >> V_36 ) - 1 ;
* V_25 = ( V_26 >> V_36 ) / ( V_35 + 1 ) ;
if ( V_27 == NULL )
return;
* V_29 = V_35 ;
* V_30 = V_36 ;
}
static void F_16 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div , V_35 , V_36 ;
if ( * V_25 > V_26 )
* V_25 = V_26 ;
div = V_26 / * V_25 ;
if ( div < 16 )
V_36 = 0 ;
else if ( div / 2 < 16 )
V_36 = 1 ;
else if ( div / 4 < 16 )
V_36 = 2 ;
else
V_36 = 3 ;
V_35 = F_14 ( div , 1 << V_36 ) ;
* V_25 = ( V_26 >> V_36 ) / V_35 ;
if ( V_27 == NULL )
return;
* V_29 = V_35 - 1 ;
* V_30 = V_36 ;
}
static void F_17 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div , V_35 , V_36 ;
if ( * V_25 > V_26 )
* V_25 = V_26 ;
div = V_26 / * V_25 ;
if ( div < 32 )
V_36 = 0 ;
else if ( div / 2 < 32 )
V_36 = 1 ;
else if ( div / 4 < 32 )
V_36 = 2 ;
else
V_36 = 3 ;
V_35 = F_14 ( div , 1 << V_36 ) ;
* V_25 = ( V_26 >> V_36 ) / V_35 ;
if ( V_27 == NULL )
return;
* V_29 = V_35 - 1 ;
* V_30 = V_36 ;
}
static struct V_3 * T_1 F_18 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
struct V_3 * V_3 ;
struct V_39 * V_40 ;
struct V_6 * V_7 = NULL ;
struct V_41 * V_42 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_43 * V_45 = NULL ;
const char * V_8 = V_2 -> V_9 ;
const char * V_46 [ V_47 ] ;
void * V_13 ;
int V_48 = 0 ;
V_13 = F_4 ( V_2 , 0 ) ;
while ( V_48 < V_47 &&
( V_46 [ V_48 ] = F_19 ( V_2 , V_48 ) ) != NULL )
V_48 ++ ;
if ( ! strcmp ( L_2 , V_8 ) ) {
F_20 ( V_2 , L_3 ,
0 , & V_8 ) ;
}
V_40 = F_3 ( sizeof( struct V_39 ) , V_11 ) ;
if ( ! V_40 )
return NULL ;
if ( V_38 -> V_49 ) {
V_7 = F_3 ( sizeof( struct V_6 ) , V_11 ) ;
if ( ! V_7 ) {
F_9 ( V_40 ) ;
return NULL ;
}
V_7 -> V_13 = V_13 ;
V_7 -> V_14 = V_38 -> V_49 ;
V_7 -> V_16 = & V_17 ;
V_44 = & V_7 -> V_19 ;
}
if ( V_38 -> V_42 ) {
V_42 = F_3 ( sizeof( struct V_41 ) , V_11 ) ;
if ( ! V_42 ) {
F_9 ( V_40 ) ;
F_9 ( V_7 ) ;
return NULL ;
}
V_42 -> V_13 = V_13 ;
V_42 -> V_50 = V_38 -> V_42 ;
V_42 -> V_51 = V_52 ;
V_42 -> V_16 = & V_17 ;
V_45 = & V_42 -> V_19 ;
}
V_40 -> V_13 = V_13 ;
V_40 -> V_53 = V_38 -> V_54 ;
V_40 -> V_55 = V_38 -> V_56 ;
V_40 -> V_16 = & V_17 ;
V_3 = F_5 ( NULL , V_8 ,
V_46 , V_48 ,
V_45 , & V_57 ,
& V_40 -> V_19 , & V_58 ,
V_44 , & V_21 , 0 ) ;
if ( ! F_6 ( V_3 ) ) {
F_7 ( V_2 , V_24 , V_3 ) ;
F_8 ( V_3 , V_8 , NULL ) ;
}
return V_3 ;
}
static void T_1 F_21 ( struct V_1 * V_2 ,
struct V_59 * V_38 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_46 [ V_47 ] ;
void * V_13 ;
int V_48 = 0 ;
V_13 = F_4 ( V_2 , 0 ) ;
while ( V_48 < V_47 &&
( V_46 [ V_48 ] = F_19 ( V_2 , V_48 ) ) != NULL )
V_48 ++ ;
V_3 = F_22 ( NULL , V_8 , V_46 , V_48 ,
V_60 , V_13 ,
V_38 -> V_50 , V_61 ,
0 , & V_17 ) ;
if ( V_3 ) {
F_7 ( V_2 , V_24 , V_3 ) ;
F_8 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_23 ( struct V_1 * V_2 ,
struct V_62 * V_38 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_63 ;
void * V_13 ;
V_13 = F_4 ( V_2 , 0 ) ;
V_63 = F_19 ( V_2 , 0 ) ;
V_3 = F_24 ( NULL , V_8 , V_63 , 0 ,
V_13 , V_38 -> V_50 , V_38 -> V_64 ,
V_38 -> pow ? V_65 : 0 ,
& V_17 ) ;
if ( V_3 ) {
F_7 ( V_2 , V_24 , V_3 ) ;
F_8 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_25 ( struct V_1 * V_2 ,
struct V_66 * V_38 )
{
struct V_67 * V_68 ;
const char * V_63 ;
const char * V_8 ;
void * V_13 ;
int V_69 ;
int V_48 = 0 ;
int V_70 = 0 ;
int V_71 ;
V_13 = F_4 ( V_2 , 0 ) ;
V_63 = F_19 ( V_2 , 0 ) ;
V_69 = F_26 ( V_38 -> V_51 , V_72 ) ;
V_68 = F_27 ( sizeof( struct V_67 ) , V_11 ) ;
if ( ! V_68 )
return;
V_68 -> V_73 = F_3 ( ( V_69 + 1 ) * sizeof( struct V_3 * ) , V_11 ) ;
if ( ! V_68 -> V_73 ) {
F_9 ( V_68 ) ;
return;
}
F_28 (i, data->mask, SUNXI_GATES_MAX_SIZE) {
F_20 ( V_2 , L_3 ,
V_70 , & V_8 ) ;
V_71 = ! strcmp ( L_4 , V_8 ) ? V_74 : 0 ;
V_68 -> V_73 [ V_48 ] = F_29 ( NULL , V_8 ,
V_63 , V_71 ,
V_13 + 4 * ( V_48 / 32 ) , V_48 % 32 ,
0 , & V_17 ) ;
F_30 ( F_6 ( V_68 -> V_73 [ V_48 ] ) ) ;
V_70 ++ ;
}
V_68 -> V_75 = V_48 ;
F_7 ( V_2 , V_76 , V_68 ) ;
}
static void T_1 F_31 ( struct V_1 * V_2 ,
struct V_77 * V_38 )
{
struct V_67 * V_68 ;
const char * V_78 = V_2 -> V_9 ;
const char * V_8 ;
struct V_3 * * V_73 , * V_79 ;
struct V_43 * V_44 , * V_80 ;
const struct V_81 * V_82 ;
struct V_6 * V_7 = NULL ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
void * V_13 ;
int V_48 = 0 ;
int V_87 , V_88 ;
V_79 = F_18 ( V_2 , V_38 -> V_40 ) ;
V_13 = F_4 ( V_2 , 0 ) ;
V_68 = F_27 ( sizeof( struct V_67 ) , V_11 ) ;
if ( ! V_68 )
return;
V_73 = F_3 ( ( V_89 + 1 ) * sizeof( * V_73 ) , V_11 ) ;
if ( ! V_73 )
goto V_90;
V_68 -> V_73 = V_73 ;
V_88 = ! strcmp ( L_5 , V_78 ) ? 0 : V_91 ;
for ( V_48 = 0 ; V_48 < V_89 ; V_48 ++ ) {
if ( F_20 ( V_2 , L_3 ,
V_48 , & V_8 ) != 0 )
break;
V_44 = NULL ;
V_80 = NULL ;
V_82 = NULL ;
if ( V_38 -> div [ V_48 ] . V_7 ) {
V_7 = F_3 ( sizeof( * V_7 ) , V_11 ) ;
if ( ! V_7 )
goto V_92;
V_7 -> V_13 = V_13 ;
V_7 -> V_14 = V_38 -> div [ V_48 ] . V_7 ;
V_7 -> V_16 = & V_17 ;
V_44 = & V_7 -> V_19 ;
}
if ( V_38 -> div [ V_48 ] . V_5 ) {
V_84 = F_3 ( sizeof( * V_84 ) , V_11 ) ;
if ( ! V_84 )
goto V_93;
V_84 -> V_94 = 1 ;
V_84 -> div = V_38 -> div [ V_48 ] . V_5 ;
V_80 = & V_84 -> V_19 ;
V_82 = & V_95 ;
} else {
V_86 = F_3 ( sizeof( * V_86 ) , V_11 ) ;
if ( ! V_86 )
goto V_93;
V_87 = V_38 -> div [ V_48 ] . pow ? V_65 : 0 ;
V_86 -> V_13 = V_13 ;
V_86 -> V_50 = V_38 -> div [ V_48 ] . V_50 ;
V_86 -> V_64 = V_96 ;
V_86 -> V_87 = V_87 ;
V_86 -> V_16 = & V_17 ;
V_86 -> V_54 = V_38 -> div [ V_48 ] . V_54 ;
V_80 = & V_86 -> V_19 ;
V_82 = & V_97 ;
}
V_73 [ V_48 ] = F_5 ( NULL , V_8 , & V_78 , 1 ,
NULL , NULL ,
V_80 , V_82 ,
V_44 , & V_21 ,
V_88 ) ;
F_30 ( F_6 ( V_68 -> V_73 [ V_48 ] ) ) ;
F_8 ( V_73 [ V_48 ] , V_8 , NULL ) ;
}
V_73 [ V_48 ++ ] = V_79 ;
V_68 -> V_75 = V_48 ;
F_7 ( V_2 , V_76 , V_68 ) ;
return;
V_93:
F_9 ( V_7 ) ;
V_92:
F_9 ( V_73 ) ;
V_90:
F_9 ( V_68 ) ;
}
static void T_1 F_32 ( const struct V_98 * V_99 ,
void * V_100 )
{
struct V_1 * V_101 ;
const struct V_62 * V_38 ;
const struct V_98 * V_102 ;
void (* F_33)( struct V_1 * , const void * ) = V_100 ;
F_34 (np, clk_match) {
V_102 = F_35 ( V_99 , V_101 ) ;
V_38 = V_102 -> V_38 ;
F_33 ( V_101 , V_38 ) ;
}
}
static void T_1 F_36 ( void )
{
struct V_3 * V_3 ;
V_3 = F_37 ( NULL , L_6 ) ;
if ( ! F_6 ( V_3 ) ) {
F_38 ( V_3 ) ;
F_39 ( V_3 ) ;
}
V_3 = F_37 ( NULL , L_7 ) ;
if ( ! F_6 ( V_3 ) ) {
F_38 ( V_3 ) ;
F_39 ( V_3 ) ;
}
}
static void T_1 F_40 ( void )
{
F_32 ( V_103 , F_18 ) ;
F_32 ( V_104 , F_23 ) ;
F_32 ( V_105 , F_31 ) ;
F_32 ( V_106 , F_21 ) ;
F_32 ( V_107 , F_25 ) ;
F_36 () ;
}
