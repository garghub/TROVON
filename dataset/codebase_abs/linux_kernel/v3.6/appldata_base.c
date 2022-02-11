static void F_1 ( unsigned long V_1 )
{
F_2 ( V_2 , (struct V_3 * ) V_1 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_4 ( & V_9 ) ;
F_5 (lh, &appldata_ops_list) {
V_8 = F_6 ( V_6 , struct V_7 , V_10 ) ;
if ( V_8 -> V_11 == 1 ) {
V_8 -> V_12 ( V_8 -> V_1 ) ;
}
}
F_7 ( & V_9 ) ;
}
int F_8 ( char V_13 , T_1 V_14 , unsigned long V_15 ,
T_1 V_16 , char * V_17 )
{
struct V_18 V_19 = {
. V_20 = { 0xD3 , 0xC9 , 0xD5 , 0xE4 ,
0xE7 , 0xD2 , 0xD9 } ,
. V_21 = 0xD5D3 ,
. V_22 = 0xF2F6 ,
. V_23 = 0xF0F1 ,
} ;
V_19 . V_13 = V_13 ;
V_19 . V_17 = ( V_17 [ 0 ] ) << 8 | V_17 [ 1 ] ;
return F_9 ( & V_19 , V_14 , ( void * ) V_15 , V_16 ) ;
}
static void F_10 ( int V_24 )
{
T_2 V_25 = ( T_2 ) V_26 * 1000 * V_27 ;
switch ( V_24 ) {
case V_28 :
if ( V_29 )
break;
V_30 . V_31 = V_25 ;
F_11 ( & V_30 ) ;
V_29 = 1 ;
break;
case V_32 :
F_12 ( & V_30 ) ;
if ( ! V_29 )
break;
V_29 = 0 ;
break;
case V_33 :
if ( ! V_29 )
break;
F_13 ( & V_30 , V_25 ) ;
}
}
static int
F_14 ( T_3 * V_34 , int V_35 ,
void T_4 * V_15 , T_5 * V_36 , T_6 * V_37 )
{
int V_38 ;
char V_39 [ 2 ] ;
if ( ! * V_36 || * V_37 ) {
* V_36 = 0 ;
return 0 ;
}
if ( ! V_35 ) {
V_38 = sprintf ( V_39 , V_29 ? L_1 : L_2 ) ;
if ( V_38 > * V_36 )
V_38 = * V_36 ;
if ( F_15 ( V_15 , V_39 , V_38 ) )
return - V_40 ;
goto V_41;
}
V_38 = * V_36 ;
if ( F_16 ( V_39 , V_15 , V_38 > sizeof( V_39 ) ? sizeof( V_39 ) : V_38 ) )
return - V_40 ;
F_17 ( & V_42 ) ;
if ( V_39 [ 0 ] == '1' )
F_10 ( V_28 ) ;
else if ( V_39 [ 0 ] == '0' )
F_10 ( V_32 ) ;
F_18 ( & V_42 ) ;
V_41:
* V_36 = V_38 ;
* V_37 += V_38 ;
return 0 ;
}
static int
F_19 ( T_3 * V_34 , int V_35 ,
void T_4 * V_15 , T_5 * V_36 , T_6 * V_37 )
{
int V_38 , V_43 ;
char V_39 [ 16 ] ;
if ( ! * V_36 || * V_37 ) {
* V_36 = 0 ;
return 0 ;
}
if ( ! V_35 ) {
V_38 = sprintf ( V_39 , L_3 , V_26 ) ;
if ( V_38 > * V_36 )
V_38 = * V_36 ;
if ( F_15 ( V_15 , V_39 , V_38 ) )
return - V_40 ;
goto V_41;
}
V_38 = * V_36 ;
if ( F_16 ( V_39 , V_15 , V_38 > sizeof( V_39 ) ? sizeof( V_39 ) : V_38 ) )
return - V_40 ;
V_43 = 0 ;
sscanf ( V_39 , L_4 , & V_43 ) ;
if ( V_43 <= 0 )
return - V_44 ;
F_17 ( & V_42 ) ;
V_26 = V_43 ;
F_10 ( V_33 ) ;
F_18 ( & V_42 ) ;
V_41:
* V_36 = V_38 ;
* V_37 += V_38 ;
return 0 ;
}
static int
F_20 ( T_3 * V_34 , int V_35 ,
void T_4 * V_15 , T_5 * V_36 , T_6 * V_37 )
{
struct V_7 * V_8 = NULL , * V_45 ;
int V_46 , V_38 , V_47 ;
char V_39 [ 2 ] ;
struct V_5 * V_6 ;
V_47 = 0 ;
F_4 ( & V_9 ) ;
F_5 (lh, &appldata_ops_list) {
V_45 = F_6 ( V_6 , struct V_7 , V_10 ) ;
if ( & V_45 -> T_3 [ 2 ] == V_34 ) {
V_47 = 1 ;
}
}
if ( ! V_47 ) {
F_7 ( & V_9 ) ;
return - V_48 ;
}
V_8 = V_34 -> V_1 ;
if ( ! F_21 ( V_8 -> V_49 ) ) {
F_7 ( & V_9 ) ;
return - V_48 ;
}
F_7 ( & V_9 ) ;
if ( ! * V_36 || * V_37 ) {
* V_36 = 0 ;
F_22 ( V_8 -> V_49 ) ;
return 0 ;
}
if ( ! V_35 ) {
V_38 = sprintf ( V_39 , V_8 -> V_11 ? L_1 : L_2 ) ;
if ( V_38 > * V_36 )
V_38 = * V_36 ;
if ( F_15 ( V_15 , V_39 , V_38 ) ) {
F_22 ( V_8 -> V_49 ) ;
return - V_40 ;
}
goto V_41;
}
V_38 = * V_36 ;
if ( F_16 ( V_39 , V_15 ,
V_38 > sizeof( V_39 ) ? sizeof( V_39 ) : V_38 ) ) {
F_22 ( V_8 -> V_49 ) ;
return - V_40 ;
}
F_4 ( & V_9 ) ;
if ( ( V_39 [ 0 ] == '1' ) && ( V_8 -> V_11 == 0 ) ) {
if ( ! F_21 ( V_8 -> V_49 ) ) {
F_7 ( & V_9 ) ;
F_22 ( V_8 -> V_49 ) ;
return - V_48 ;
}
V_8 -> V_12 ( V_8 -> V_1 ) ;
V_46 = F_8 ( V_8 -> V_13 ,
V_50 ,
( unsigned long ) V_8 -> V_1 , V_8 -> V_51 ,
V_8 -> V_17 ) ;
if ( V_46 != 0 ) {
F_23 ( L_5
L_6 , V_8 -> V_52 , V_46 ) ;
F_22 ( V_8 -> V_49 ) ;
} else
V_8 -> V_11 = 1 ;
} else if ( ( V_39 [ 0 ] == '0' ) && ( V_8 -> V_11 == 1 ) ) {
V_8 -> V_11 = 0 ;
V_46 = F_8 ( V_8 -> V_13 , V_53 ,
( unsigned long ) V_8 -> V_1 , V_8 -> V_51 ,
V_8 -> V_17 ) ;
if ( V_46 != 0 )
F_23 ( L_7
L_6 , V_8 -> V_52 , V_46 ) ;
F_22 ( V_8 -> V_49 ) ;
}
F_7 ( & V_9 ) ;
V_41:
* V_36 = V_38 ;
* V_37 += V_38 ;
F_22 ( V_8 -> V_49 ) ;
return 0 ;
}
int F_24 ( struct V_7 * V_8 )
{
if ( V_8 -> V_51 > V_54 )
return - V_44 ;
V_8 -> T_3 = F_25 ( 4 * sizeof( struct T_3 ) , V_55 ) ;
if ( ! V_8 -> T_3 )
return - V_56 ;
F_4 ( & V_9 ) ;
F_26 ( & V_8 -> V_10 , & V_57 ) ;
F_7 ( & V_9 ) ;
V_8 -> T_3 [ 0 ] . V_58 = V_59 ;
V_8 -> T_3 [ 0 ] . V_60 = 0 ;
V_8 -> T_3 [ 0 ] . V_61 = V_62 | V_63 ;
V_8 -> T_3 [ 0 ] . V_64 = & V_8 -> T_3 [ 2 ] ;
V_8 -> T_3 [ 2 ] . V_58 = V_8 -> V_52 ;
V_8 -> T_3 [ 2 ] . V_61 = V_62 | V_65 ;
V_8 -> T_3 [ 2 ] . V_66 = F_20 ;
V_8 -> T_3 [ 2 ] . V_1 = V_8 ;
V_8 -> V_67 = F_27 ( V_8 -> T_3 ) ;
if ( ! V_8 -> V_67 )
goto V_41;
return 0 ;
V_41:
F_4 ( & V_9 ) ;
F_28 ( & V_8 -> V_10 ) ;
F_7 ( & V_9 ) ;
F_29 ( V_8 -> T_3 ) ;
return - V_56 ;
}
void F_30 ( struct V_7 * V_8 )
{
F_4 ( & V_9 ) ;
F_28 ( & V_8 -> V_10 ) ;
F_7 ( & V_9 ) ;
F_31 ( V_8 -> V_67 ) ;
F_29 ( V_8 -> T_3 ) ;
}
static int F_32 ( struct V_68 * V_69 )
{
struct V_7 * V_8 ;
int V_46 ;
struct V_5 * V_6 ;
F_17 ( & V_42 ) ;
if ( V_29 ) {
F_10 ( V_32 ) ;
V_70 = 1 ;
}
F_18 ( & V_42 ) ;
F_4 ( & V_9 ) ;
F_5 (lh, &appldata_ops_list) {
V_8 = F_6 ( V_6 , struct V_7 , V_10 ) ;
if ( V_8 -> V_11 == 1 ) {
V_46 = F_8 ( V_8 -> V_13 , V_53 ,
( unsigned long ) V_8 -> V_1 , V_8 -> V_51 ,
V_8 -> V_17 ) ;
if ( V_46 != 0 )
F_23 ( L_7
L_6 , V_8 -> V_52 , V_46 ) ;
}
}
F_7 ( & V_9 ) ;
return 0 ;
}
static int F_33 ( struct V_68 * V_69 )
{
struct V_7 * V_8 ;
int V_46 ;
struct V_5 * V_6 ;
F_17 ( & V_42 ) ;
if ( V_70 ) {
F_10 ( V_28 ) ;
V_70 = 0 ;
}
F_18 ( & V_42 ) ;
F_4 ( & V_9 ) ;
F_5 (lh, &appldata_ops_list) {
V_8 = F_6 ( V_6 , struct V_7 , V_10 ) ;
if ( V_8 -> V_11 == 1 ) {
V_8 -> V_12 ( V_8 -> V_1 ) ;
V_46 = F_8 ( V_8 -> V_13 ,
V_50 ,
( unsigned long ) V_8 -> V_1 , V_8 -> V_51 ,
V_8 -> V_17 ) ;
if ( V_46 != 0 ) {
F_23 ( L_5
L_6 , V_8 -> V_52 , V_46 ) ;
}
}
}
F_7 ( & V_9 ) ;
return 0 ;
}
static int F_34 ( struct V_68 * V_69 )
{
return F_33 ( V_69 ) ;
}
static int T_7 F_35 ( void )
{
int V_46 ;
V_30 . V_14 = F_1 ;
V_30 . V_1 = ( unsigned long ) & V_71 ;
V_46 = F_36 ( & V_72 ) ;
if ( V_46 )
return V_46 ;
V_73 = F_37 ( L_8 , - 1 , NULL ,
0 ) ;
if ( F_38 ( V_73 ) ) {
V_46 = F_39 ( V_73 ) ;
goto V_74;
}
V_2 = F_40 ( L_8 ) ;
if ( ! V_2 ) {
V_46 = - V_56 ;
goto V_75;
}
V_76 = F_27 ( V_77 ) ;
return 0 ;
V_75:
F_41 ( V_73 ) ;
V_74:
F_42 ( & V_72 ) ;
return V_46 ;
}
