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
F_14 ( struct V_34 * V_35 , int V_36 ,
void T_3 * V_15 , T_4 * V_37 , T_5 * V_38 )
{
unsigned int V_39 ;
char V_40 [ 2 ] ;
if ( ! * V_37 || * V_38 ) {
* V_37 = 0 ;
return 0 ;
}
if ( ! V_36 ) {
strncpy ( V_40 , V_29 ? L_1 : L_2 ,
F_15 ( V_40 ) ) ;
V_39 = F_16 ( V_40 , F_15 ( V_40 ) ) ;
if ( V_39 > * V_37 )
V_39 = * V_37 ;
if ( F_17 ( V_15 , V_40 , V_39 ) )
return - V_41 ;
goto V_42;
}
V_39 = * V_37 ;
if ( F_18 ( V_40 , V_15 , V_39 > sizeof( V_40 ) ? sizeof( V_40 ) : V_39 ) )
return - V_41 ;
F_19 ( & V_43 ) ;
if ( V_40 [ 0 ] == '1' )
F_10 ( V_28 ) ;
else if ( V_40 [ 0 ] == '0' )
F_10 ( V_32 ) ;
F_20 ( & V_43 ) ;
V_42:
* V_37 = V_39 ;
* V_38 += V_39 ;
return 0 ;
}
static int
F_21 ( struct V_34 * V_35 , int V_36 ,
void T_3 * V_15 , T_4 * V_37 , T_5 * V_38 )
{
unsigned int V_39 ;
int V_44 ;
char V_40 [ 16 ] ;
if ( ! * V_37 || * V_38 ) {
* V_37 = 0 ;
return 0 ;
}
if ( ! V_36 ) {
V_39 = sprintf ( V_40 , L_3 , V_26 ) ;
if ( V_39 > * V_37 )
V_39 = * V_37 ;
if ( F_17 ( V_15 , V_40 , V_39 ) )
return - V_41 ;
goto V_42;
}
V_39 = * V_37 ;
if ( F_18 ( V_40 , V_15 , V_39 > sizeof( V_40 ) ? sizeof( V_40 ) : V_39 ) )
return - V_41 ;
V_44 = 0 ;
sscanf ( V_40 , L_4 , & V_44 ) ;
if ( V_44 <= 0 )
return - V_45 ;
F_19 ( & V_43 ) ;
V_26 = V_44 ;
F_10 ( V_33 ) ;
F_20 ( & V_43 ) ;
V_42:
* V_37 = V_39 ;
* V_38 += V_39 ;
return 0 ;
}
static int
F_22 ( struct V_34 * V_35 , int V_36 ,
void T_3 * V_15 , T_4 * V_37 , T_5 * V_38 )
{
struct V_7 * V_8 = NULL , * V_46 ;
unsigned int V_39 ;
int V_47 , V_48 ;
char V_40 [ 2 ] ;
struct V_5 * V_6 ;
V_48 = 0 ;
F_4 ( & V_9 ) ;
F_5 (lh, &appldata_ops_list) {
V_46 = F_6 ( V_6 , struct V_7 , V_10 ) ;
if ( & V_46 -> V_34 [ 2 ] == V_35 ) {
V_48 = 1 ;
}
}
if ( ! V_48 ) {
F_7 ( & V_9 ) ;
return - V_49 ;
}
V_8 = V_35 -> V_1 ;
if ( ! F_23 ( V_8 -> V_50 ) ) {
F_7 ( & V_9 ) ;
return - V_49 ;
}
F_7 ( & V_9 ) ;
if ( ! * V_37 || * V_38 ) {
* V_37 = 0 ;
F_24 ( V_8 -> V_50 ) ;
return 0 ;
}
if ( ! V_36 ) {
strncpy ( V_40 , V_8 -> V_11 ? L_1 : L_2 , F_15 ( V_40 ) ) ;
V_39 = F_16 ( V_40 , F_15 ( V_40 ) ) ;
if ( V_39 > * V_37 )
V_39 = * V_37 ;
if ( F_17 ( V_15 , V_40 , V_39 ) ) {
F_24 ( V_8 -> V_50 ) ;
return - V_41 ;
}
goto V_42;
}
V_39 = * V_37 ;
if ( F_18 ( V_40 , V_15 ,
V_39 > sizeof( V_40 ) ? sizeof( V_40 ) : V_39 ) ) {
F_24 ( V_8 -> V_50 ) ;
return - V_41 ;
}
F_4 ( & V_9 ) ;
if ( ( V_40 [ 0 ] == '1' ) && ( V_8 -> V_11 == 0 ) ) {
if ( ! F_23 ( V_8 -> V_50 ) ) {
F_7 ( & V_9 ) ;
F_24 ( V_8 -> V_50 ) ;
return - V_49 ;
}
V_8 -> V_12 ( V_8 -> V_1 ) ;
V_47 = F_8 ( V_8 -> V_13 ,
V_51 ,
( unsigned long ) V_8 -> V_1 , V_8 -> V_52 ,
V_8 -> V_17 ) ;
if ( V_47 != 0 ) {
F_25 ( L_5
L_6 , V_8 -> V_53 , V_47 ) ;
F_24 ( V_8 -> V_50 ) ;
} else
V_8 -> V_11 = 1 ;
} else if ( ( V_40 [ 0 ] == '0' ) && ( V_8 -> V_11 == 1 ) ) {
V_8 -> V_11 = 0 ;
V_47 = F_8 ( V_8 -> V_13 , V_54 ,
( unsigned long ) V_8 -> V_1 , V_8 -> V_52 ,
V_8 -> V_17 ) ;
if ( V_47 != 0 )
F_25 ( L_7
L_6 , V_8 -> V_53 , V_47 ) ;
F_24 ( V_8 -> V_50 ) ;
}
F_7 ( & V_9 ) ;
V_42:
* V_37 = V_39 ;
* V_38 += V_39 ;
F_24 ( V_8 -> V_50 ) ;
return 0 ;
}
int F_26 ( struct V_7 * V_8 )
{
if ( V_8 -> V_52 > V_55 )
return - V_45 ;
V_8 -> V_34 = F_27 ( 4 * sizeof( struct V_34 ) , V_56 ) ;
if ( ! V_8 -> V_34 )
return - V_57 ;
F_4 ( & V_9 ) ;
F_28 ( & V_8 -> V_10 , & V_58 ) ;
F_7 ( & V_9 ) ;
V_8 -> V_34 [ 0 ] . V_59 = V_60 ;
V_8 -> V_34 [ 0 ] . V_61 = 0 ;
V_8 -> V_34 [ 0 ] . V_62 = V_63 | V_64 ;
V_8 -> V_34 [ 0 ] . V_65 = & V_8 -> V_34 [ 2 ] ;
V_8 -> V_34 [ 2 ] . V_59 = V_8 -> V_53 ;
V_8 -> V_34 [ 2 ] . V_62 = V_63 | V_66 ;
V_8 -> V_34 [ 2 ] . V_67 = F_22 ;
V_8 -> V_34 [ 2 ] . V_1 = V_8 ;
V_8 -> V_68 = F_29 ( V_8 -> V_34 ) ;
if ( ! V_8 -> V_68 )
goto V_42;
return 0 ;
V_42:
F_4 ( & V_9 ) ;
F_30 ( & V_8 -> V_10 ) ;
F_7 ( & V_9 ) ;
F_31 ( V_8 -> V_34 ) ;
return - V_57 ;
}
void F_32 ( struct V_7 * V_8 )
{
F_4 ( & V_9 ) ;
F_30 ( & V_8 -> V_10 ) ;
F_7 ( & V_9 ) ;
F_33 ( V_8 -> V_68 ) ;
F_31 ( V_8 -> V_34 ) ;
}
static int F_34 ( struct V_69 * V_70 )
{
struct V_7 * V_8 ;
int V_47 ;
struct V_5 * V_6 ;
F_19 ( & V_43 ) ;
if ( V_29 ) {
F_10 ( V_32 ) ;
V_71 = 1 ;
}
F_20 ( & V_43 ) ;
F_4 ( & V_9 ) ;
F_5 (lh, &appldata_ops_list) {
V_8 = F_6 ( V_6 , struct V_7 , V_10 ) ;
if ( V_8 -> V_11 == 1 ) {
V_47 = F_8 ( V_8 -> V_13 , V_54 ,
( unsigned long ) V_8 -> V_1 , V_8 -> V_52 ,
V_8 -> V_17 ) ;
if ( V_47 != 0 )
F_25 ( L_7
L_6 , V_8 -> V_53 , V_47 ) ;
}
}
F_7 ( & V_9 ) ;
return 0 ;
}
static int F_35 ( struct V_69 * V_70 )
{
struct V_7 * V_8 ;
int V_47 ;
struct V_5 * V_6 ;
F_19 ( & V_43 ) ;
if ( V_71 ) {
F_10 ( V_28 ) ;
V_71 = 0 ;
}
F_20 ( & V_43 ) ;
F_4 ( & V_9 ) ;
F_5 (lh, &appldata_ops_list) {
V_8 = F_6 ( V_6 , struct V_7 , V_10 ) ;
if ( V_8 -> V_11 == 1 ) {
V_8 -> V_12 ( V_8 -> V_1 ) ;
V_47 = F_8 ( V_8 -> V_13 ,
V_51 ,
( unsigned long ) V_8 -> V_1 , V_8 -> V_52 ,
V_8 -> V_17 ) ;
if ( V_47 != 0 ) {
F_25 ( L_5
L_6 , V_8 -> V_53 , V_47 ) ;
}
}
}
F_7 ( & V_9 ) ;
return 0 ;
}
static int F_36 ( struct V_69 * V_70 )
{
return F_35 ( V_70 ) ;
}
static int T_6 F_37 ( void )
{
int V_47 ;
F_38 ( & V_30 ) ;
V_30 . V_14 = F_1 ;
V_30 . V_1 = ( unsigned long ) & V_72 ;
V_47 = F_39 ( & V_73 ) ;
if ( V_47 )
return V_47 ;
V_74 = F_40 ( L_8 , - 1 , NULL ,
0 ) ;
if ( F_41 ( V_74 ) ) {
V_47 = F_42 ( V_74 ) ;
goto V_75;
}
V_2 = F_43 ( L_8 , 0 ) ;
if ( ! V_2 ) {
V_47 = - V_57 ;
goto V_76;
}
V_77 = F_29 ( V_78 ) ;
return 0 ;
V_76:
F_44 ( V_74 ) ;
V_75:
F_45 ( & V_73 ) ;
return V_47 ;
}
