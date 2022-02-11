static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
const char * V_8 = V_2 -> V_9 ;
T_2 V_10 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_11 ) ;
if ( ! V_5 )
return;
V_7 = F_2 ( sizeof( struct V_6 ) , V_11 ) ;
if ( ! V_7 ) {
F_3 ( V_5 ) ;
return;
}
if ( F_4 ( V_2 , L_1 , & V_10 ) )
return;
V_7 -> V_12 = F_5 ( V_2 , 0 ) ;
V_7 -> V_13 = V_14 ;
V_7 -> V_15 = & V_16 ;
V_5 -> V_17 = V_10 ;
V_3 = F_6 ( NULL , V_8 ,
NULL , 0 ,
NULL , NULL ,
& V_5 -> V_18 , & V_19 ,
& V_7 -> V_18 , & V_20 ,
V_21 ) ;
if ( ! F_7 ( V_3 ) ) {
F_8 ( V_2 , V_22 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
}
}
static void F_10 ( T_2 * V_23 , T_2 V_24 ,
T_3 * V_25 , T_3 * V_26 , T_3 * V_27 , T_3 * V_28 )
{
T_3 div ;
div = * V_23 / 6000000 ;
* V_23 = 6000000 * div ;
if ( V_25 == NULL )
return;
* V_27 = 0 ;
if ( * V_23 >= 768000000 || * V_23 == 42000000 || * V_23 == 54000000 )
* V_26 = 1 ;
else
* V_26 = 0 ;
if ( div < 10 )
* V_28 = 3 ;
else if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_28 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_28 = 1 ;
else
* V_28 = 0 ;
div <<= * V_28 ;
div /= ( * V_26 + 1 ) ;
* V_25 = div / 4 ;
}
static void F_11 ( T_2 * V_23 , T_2 V_24 ,
T_3 * V_25 , T_3 * V_26 , T_3 * V_27 , T_3 * V_28 )
{
T_2 V_29 = * V_23 / 1000000 ;
T_2 V_30 = V_24 / 1000000 ;
T_2 V_31 = F_12 ( V_29 , 6 ) ;
T_2 V_32 = F_12 ( V_29 , 16 ) ;
if ( V_31 > V_32 )
V_29 = V_31 ;
else
V_29 = V_32 ;
* V_23 = V_29 * 1000000 ;
if ( V_25 == NULL )
return;
if ( ! ( V_29 % 32 ) )
* V_26 = 3 ;
else if ( ! ( V_29 % 9 ) )
* V_26 = 2 ;
else if ( ! ( V_29 % 8 ) )
* V_26 = 1 ;
else
* V_26 = 0 ;
if ( ( V_29 % 6 ) == 2 || ( V_29 % 6 ) == 4 )
* V_27 = 2 ;
else if ( ( V_29 / 6 ) & 1 )
* V_27 = 3 ;
else
* V_27 = 1 ;
* V_25 = V_29 * ( * V_27 + 1 ) / ( ( * V_26 + 1 ) * V_30 ) - 1 ;
if ( ( * V_25 + 1 ) > 31 && ( * V_27 + 1 ) > 1 ) {
* V_25 = ( * V_25 + 1 ) / 2 - 1 ;
* V_27 = ( * V_27 + 1 ) / 2 - 1 ;
}
}
static void F_13 ( T_2 * V_23 , T_2 V_24 ,
T_3 * V_25 , T_3 * V_26 , T_3 * V_27 , T_3 * V_28 )
{
T_3 V_33 , V_34 ;
if ( V_24 < * V_23 )
* V_23 = V_24 ;
V_24 = ( V_24 + ( * V_23 - 1 ) ) / * V_23 ;
if ( V_24 > 32 )
return;
if ( V_24 <= 4 )
V_34 = 0 ;
else if ( V_24 <= 8 )
V_34 = 1 ;
else if ( V_24 <= 16 )
V_34 = 2 ;
else
V_34 = 3 ;
V_33 = ( V_24 >> V_34 ) - 1 ;
* V_23 = ( V_24 >> V_34 ) / ( V_33 + 1 ) ;
if ( V_25 == NULL )
return;
* V_27 = V_33 ;
* V_28 = V_34 ;
}
static void T_1 F_14 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_37 ;
void * V_12 ;
V_12 = F_5 ( V_2 , 0 ) ;
V_37 = F_15 ( V_2 , 0 ) ;
V_3 = F_16 ( NULL , V_8 , V_37 , 0 , V_12 ,
V_36 -> V_38 , V_36 -> V_39 , & V_16 ) ;
if ( ! F_7 ( V_3 ) ) {
F_8 ( V_2 , V_22 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_17 ( struct V_1 * V_2 ,
struct V_40 * V_36 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_41 [ 5 ] ;
void * V_12 ;
int V_42 = 0 ;
V_12 = F_5 ( V_2 , 0 ) ;
while ( V_42 < 5 && ( V_41 [ V_42 ] = F_15 ( V_2 , V_42 ) ) != NULL )
V_42 ++ ;
V_3 = F_18 ( NULL , V_8 , V_41 , V_42 ,
V_43 , V_12 ,
V_36 -> V_44 , V_45 ,
0 , & V_16 ) ;
if ( V_3 ) {
F_8 ( V_2 , V_22 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_19 ( struct V_1 * V_2 ,
struct V_46 * V_36 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_47 ;
void * V_12 ;
V_12 = F_5 ( V_2 , 0 ) ;
V_47 = F_15 ( V_2 , 0 ) ;
V_3 = F_20 ( NULL , V_8 , V_47 , 0 ,
V_12 , V_36 -> V_44 , V_36 -> V_48 ,
V_36 -> pow ? V_49 : 0 ,
& V_16 ) ;
if ( V_3 ) {
F_8 ( V_2 , V_22 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_21 ( struct V_1 * V_2 ,
struct V_50 * V_36 )
{
struct V_51 * V_52 ;
const char * V_47 ;
const char * V_8 ;
void * V_12 ;
int V_53 ;
int V_42 = 0 ;
int V_54 = 0 ;
int V_55 ;
V_12 = F_5 ( V_2 , 0 ) ;
V_47 = F_15 ( V_2 , 0 ) ;
V_53 = F_22 ( V_36 -> V_56 , V_57 ) ;
V_52 = F_23 ( sizeof( struct V_51 ) , V_11 ) ;
if ( ! V_52 )
return;
V_52 -> V_58 = F_2 ( ( V_53 + 1 ) * sizeof( struct V_3 * ) , V_11 ) ;
if ( ! V_52 -> V_58 ) {
F_3 ( V_52 ) ;
return;
}
F_24 (i, data->mask, SUNXI_GATES_MAX_SIZE) {
F_25 ( V_2 , L_2 ,
V_54 , & V_8 ) ;
V_55 = ! strcmp ( L_3 , V_8 ) ? V_59 : 0 ;
V_52 -> V_58 [ V_42 ] = F_26 ( NULL , V_8 ,
V_47 , V_55 ,
V_12 + 4 * ( V_42 / 32 ) , V_42 % 32 ,
0 , & V_16 ) ;
F_27 ( F_7 ( V_52 -> V_58 [ V_42 ] ) ) ;
V_54 ++ ;
}
V_52 -> V_60 = V_42 ;
F_8 ( V_2 , V_61 , V_52 ) ;
}
static void T_1 F_28 ( const struct V_62 * V_63 ,
void * V_64 )
{
struct V_1 * V_65 ;
const struct V_46 * V_36 ;
const struct V_62 * V_66 ;
void (* F_29)( struct V_1 * , const void * ) = V_64 ;
F_30 (np, clk_match) {
V_66 = F_31 ( V_63 , V_65 ) ;
V_36 = V_66 -> V_36 ;
F_29 ( V_65 , V_36 ) ;
}
}
void T_1 F_32 ( void )
{
F_33 ( NULL ) ;
F_28 ( V_67 , F_14 ) ;
F_28 ( V_68 , F_19 ) ;
F_28 ( V_69 , F_17 ) ;
F_28 ( V_70 , F_21 ) ;
}
