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
if ( V_3 ) {
F_7 ( V_2 , V_22 , V_3 ) ;
F_8 ( V_3 , V_8 , NULL ) ;
}
}
static void F_9 ( T_2 * V_23 , T_2 V_24 ,
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
static void F_10 ( T_2 * V_23 , T_2 V_24 ,
T_3 * V_25 , T_3 * V_26 , T_3 * V_27 , T_3 * V_28 )
{
T_3 V_29 , V_30 ;
if ( V_24 < * V_23 )
* V_23 = V_24 ;
V_24 = ( V_24 + ( * V_23 - 1 ) ) / * V_23 ;
if ( V_24 > 32 )
return;
if ( V_24 <= 4 )
V_30 = 0 ;
else if ( V_24 <= 8 )
V_30 = 1 ;
else if ( V_24 <= 16 )
V_30 = 2 ;
else
V_30 = 3 ;
V_29 = ( V_24 >> V_30 ) - 1 ;
* V_23 = ( V_24 >> V_30 ) / ( V_29 + 1 ) ;
if ( V_25 == NULL )
return;
* V_27 = V_29 ;
* V_28 = V_30 ;
}
static void T_1 F_11 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_33 ;
void * V_12 ;
V_12 = F_5 ( V_2 , 0 ) ;
V_33 = F_12 ( V_2 , 0 ) ;
V_3 = F_13 ( NULL , V_8 , V_33 , 0 , V_12 ,
V_32 -> V_34 , V_32 -> V_35 , & V_16 ) ;
if ( V_3 ) {
F_7 ( V_2 , V_22 , V_3 ) ;
F_8 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_14 ( struct V_1 * V_2 ,
struct V_36 * V_32 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_37 [ 5 ] ;
void * V_12 ;
int V_38 = 0 ;
V_12 = F_5 ( V_2 , 0 ) ;
while ( V_38 < 5 && ( V_37 [ V_38 ] = F_12 ( V_2 , V_38 ) ) != NULL )
V_38 ++ ;
V_3 = F_15 ( NULL , V_8 , V_37 , V_38 , 0 , V_12 ,
V_32 -> V_39 , V_40 ,
0 , & V_16 ) ;
if ( V_3 ) {
F_7 ( V_2 , V_22 , V_3 ) ;
F_8 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_16 ( struct V_1 * V_2 ,
struct V_41 * V_32 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_42 ;
void * V_12 ;
V_12 = F_5 ( V_2 , 0 ) ;
V_42 = F_12 ( V_2 , 0 ) ;
V_3 = F_17 ( NULL , V_8 , V_42 , 0 ,
V_12 , V_32 -> V_39 , V_43 ,
V_32 -> pow ? V_44 : 0 ,
& V_16 ) ;
if ( V_3 ) {
F_7 ( V_2 , V_22 , V_3 ) ;
F_8 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_18 ( struct V_1 * V_2 ,
struct V_45 * V_32 )
{
struct V_46 * V_47 ;
const char * V_42 ;
const char * V_8 ;
void * V_12 ;
int V_48 ;
int V_38 = 0 ;
int V_49 = 0 ;
int V_50 ;
V_12 = F_5 ( V_2 , 0 ) ;
V_42 = F_12 ( V_2 , 0 ) ;
V_48 = F_19 ( V_32 -> V_51 , V_52 ) ;
V_47 = F_20 ( sizeof( struct V_46 ) , V_11 ) ;
if ( ! V_47 )
return;
V_47 -> V_53 = F_2 ( ( V_48 + 1 ) * sizeof( struct V_3 * ) , V_11 ) ;
if ( ! V_47 -> V_53 ) {
F_3 ( V_47 ) ;
return;
}
F_21 (i, data->mask, SUNXI_GATES_MAX_SIZE) {
F_22 ( V_2 , L_2 ,
V_49 , & V_8 ) ;
V_50 = ! strcmp ( L_3 , V_8 ) ? V_54 : 0 ;
V_47 -> V_53 [ V_38 ] = F_23 ( NULL , V_8 ,
V_42 , V_50 ,
V_12 + 4 * ( V_38 / 32 ) , V_38 % 32 ,
0 , & V_16 ) ;
F_24 ( F_25 ( V_47 -> V_53 [ V_38 ] ) ) ;
V_49 ++ ;
}
V_47 -> V_55 = V_38 ;
F_7 ( V_2 , V_56 , V_47 ) ;
}
static void T_1 F_26 ( const struct V_57 * V_58 ,
void * V_59 )
{
struct V_1 * V_60 ;
const struct V_41 * V_32 ;
const struct V_57 * V_61 ;
void (* F_27)( struct V_1 * , const void * ) = V_59 ;
F_28 (np, clk_match) {
V_61 = F_29 ( V_58 , V_60 ) ;
V_32 = V_61 -> V_32 ;
F_27 ( V_60 , V_32 ) ;
}
}
void T_1 F_30 ( void )
{
F_31 ( V_58 ) ;
F_26 ( V_62 , F_11 ) ;
F_26 ( V_63 , F_16 ) ;
F_26 ( V_64 , F_14 ) ;
F_26 ( V_65 , F_18 ) ;
}
