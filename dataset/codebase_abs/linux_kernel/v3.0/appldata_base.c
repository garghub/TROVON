static void F_1 ( unsigned long V_1 )
{
if ( F_2 ( & V_2 ) ) {
F_3 ( & V_2 , F_4 () ) ;
F_5 ( V_3 , (struct V_4 * ) V_1 ) ;
}
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_7 () ;
F_8 ( & V_10 ) ;
F_9 (lh, &appldata_ops_list) {
V_9 = F_10 ( V_7 , struct V_8 , V_11 ) ;
if ( V_9 -> V_12 == 1 ) {
V_9 -> V_13 ( V_9 -> V_1 ) ;
}
}
F_11 ( & V_10 ) ;
F_12 () ;
}
int F_13 ( char V_14 , T_1 V_15 , unsigned long V_16 ,
T_1 V_17 , char * V_18 )
{
struct V_19 V_20 = {
. V_21 = { 0xD3 , 0xC9 , 0xD5 , 0xE4 ,
0xE7 , 0xD2 , 0xD9 } ,
. V_22 = 0xD5D3 ,
. V_23 = 0xF2F6 ,
. V_24 = 0xF0F1 ,
} ;
V_20 . V_14 = V_14 ;
V_20 . V_18 = ( V_18 [ 0 ] ) << 8 | V_18 [ 1 ] ;
return F_14 ( & V_20 , V_15 , ( void * ) V_16 , V_17 ) ;
}
static void F_15 ( void * V_25 ) {
struct {
struct V_26 * V_27 ;
T_2 V_28 ;
} * args = V_25 ;
F_16 ( args -> V_27 , args -> V_28 ) ;
}
static void
F_17 ( int V_29 )
{
T_2 V_30 ;
int V_31 ;
switch ( V_29 ) {
case V_32 :
if ( V_33 )
break;
V_30 = ( T_2 ) ( V_34 * 1000 /
F_4 () ) * V_35 ;
F_18 (i) {
F_19 ( V_36 , V_31 ) . V_28 = V_30 ;
F_20 ( V_31 , V_37 ,
& F_19 ( V_36 , V_31 ) ,
1 ) ;
}
V_33 = 1 ;
break;
case V_38 :
F_18 (i)
F_21 ( & F_19 ( V_36 , V_31 ) ) ;
if ( ! V_33 )
break;
V_33 = 0 ;
F_3 ( & V_2 , F_4 () ) ;
break;
case V_39 :
V_30 = ( T_2 ) ( V_34 * 1000 /
F_4 () ) * V_35 ;
if ( ! V_33 )
break;
F_18 (i) {
struct {
struct V_26 * V_27 ;
T_2 V_28 ;
} args ;
args . V_27 = & F_19 ( V_36 , V_31 ) ;
args . V_28 = V_30 ;
F_20 ( V_31 , F_15 ,
& args , 1 ) ;
}
}
}
static int
F_22 ( T_3 * V_40 , int V_41 ,
void T_4 * V_16 , T_5 * V_42 , T_6 * V_43 )
{
int V_44 ;
char V_45 [ 2 ] ;
if ( ! * V_42 || * V_43 ) {
* V_42 = 0 ;
return 0 ;
}
if ( ! V_41 ) {
V_44 = sprintf ( V_45 , V_33 ? L_1 : L_2 ) ;
if ( V_44 > * V_42 )
V_44 = * V_42 ;
if ( F_23 ( V_16 , V_45 , V_44 ) )
return - V_46 ;
goto V_47;
}
V_44 = * V_42 ;
if ( F_24 ( V_45 , V_16 , V_44 > sizeof( V_45 ) ? sizeof( V_45 ) : V_44 ) )
return - V_46 ;
F_7 () ;
F_25 ( & V_48 ) ;
if ( V_45 [ 0 ] == '1' )
F_17 ( V_32 ) ;
else if ( V_45 [ 0 ] == '0' )
F_17 ( V_38 ) ;
F_26 ( & V_48 ) ;
F_12 () ;
V_47:
* V_42 = V_44 ;
* V_43 += V_44 ;
return 0 ;
}
static int
F_27 ( T_3 * V_40 , int V_41 ,
void T_4 * V_16 , T_5 * V_42 , T_6 * V_43 )
{
int V_44 , V_49 ;
char V_45 [ 16 ] ;
if ( ! * V_42 || * V_43 ) {
* V_42 = 0 ;
return 0 ;
}
if ( ! V_41 ) {
V_44 = sprintf ( V_45 , L_3 , V_34 ) ;
if ( V_44 > * V_42 )
V_44 = * V_42 ;
if ( F_23 ( V_16 , V_45 , V_44 ) )
return - V_46 ;
goto V_47;
}
V_44 = * V_42 ;
if ( F_24 ( V_45 , V_16 , V_44 > sizeof( V_45 ) ? sizeof( V_45 ) : V_44 ) ) {
return - V_46 ;
}
V_49 = 0 ;
sscanf ( V_45 , L_4 , & V_49 ) ;
if ( V_49 <= 0 )
return - V_50 ;
F_7 () ;
F_25 ( & V_48 ) ;
V_34 = V_49 ;
F_17 ( V_39 ) ;
F_26 ( & V_48 ) ;
F_12 () ;
V_47:
* V_42 = V_44 ;
* V_43 += V_44 ;
return 0 ;
}
static int
F_28 ( T_3 * V_40 , int V_41 ,
void T_4 * V_16 , T_5 * V_42 , T_6 * V_43 )
{
struct V_8 * V_9 = NULL , * V_51 ;
int V_52 , V_44 , V_53 ;
char V_45 [ 2 ] ;
struct V_6 * V_7 ;
V_53 = 0 ;
F_8 ( & V_10 ) ;
F_9 (lh, &appldata_ops_list) {
V_51 = F_10 ( V_7 , struct V_8 , V_11 ) ;
if ( & V_51 -> T_3 [ 2 ] == V_40 ) {
V_53 = 1 ;
}
}
if ( ! V_53 ) {
F_11 ( & V_10 ) ;
return - V_54 ;
}
V_9 = V_40 -> V_1 ;
if ( ! F_29 ( V_9 -> V_55 ) ) {
F_11 ( & V_10 ) ;
return - V_54 ;
}
F_11 ( & V_10 ) ;
if ( ! * V_42 || * V_43 ) {
* V_42 = 0 ;
F_30 ( V_9 -> V_55 ) ;
return 0 ;
}
if ( ! V_41 ) {
V_44 = sprintf ( V_45 , V_9 -> V_12 ? L_1 : L_2 ) ;
if ( V_44 > * V_42 )
V_44 = * V_42 ;
if ( F_23 ( V_16 , V_45 , V_44 ) ) {
F_30 ( V_9 -> V_55 ) ;
return - V_46 ;
}
goto V_47;
}
V_44 = * V_42 ;
if ( F_24 ( V_45 , V_16 ,
V_44 > sizeof( V_45 ) ? sizeof( V_45 ) : V_44 ) ) {
F_30 ( V_9 -> V_55 ) ;
return - V_46 ;
}
F_8 ( & V_10 ) ;
if ( ( V_45 [ 0 ] == '1' ) && ( V_9 -> V_12 == 0 ) ) {
if ( ! F_29 ( V_9 -> V_55 ) ) {
F_11 ( & V_10 ) ;
F_30 ( V_9 -> V_55 ) ;
return - V_54 ;
}
V_9 -> V_13 ( V_9 -> V_1 ) ;
V_52 = F_13 ( V_9 -> V_14 ,
V_56 ,
( unsigned long ) V_9 -> V_1 , V_9 -> V_57 ,
V_9 -> V_18 ) ;
if ( V_52 != 0 ) {
F_31 ( L_5
L_6 , V_9 -> V_58 , V_52 ) ;
F_30 ( V_9 -> V_55 ) ;
} else
V_9 -> V_12 = 1 ;
} else if ( ( V_45 [ 0 ] == '0' ) && ( V_9 -> V_12 == 1 ) ) {
V_9 -> V_12 = 0 ;
V_52 = F_13 ( V_9 -> V_14 , V_59 ,
( unsigned long ) V_9 -> V_1 , V_9 -> V_57 ,
V_9 -> V_18 ) ;
if ( V_52 != 0 )
F_31 ( L_7
L_6 , V_9 -> V_58 , V_52 ) ;
F_30 ( V_9 -> V_55 ) ;
}
F_11 ( & V_10 ) ;
V_47:
* V_42 = V_44 ;
* V_43 += V_44 ;
F_30 ( V_9 -> V_55 ) ;
return 0 ;
}
int F_32 ( struct V_8 * V_9 )
{
if ( V_9 -> V_57 > V_60 )
return - V_50 ;
V_9 -> T_3 = F_33 ( 4 * sizeof( struct T_3 ) , V_61 ) ;
if ( ! V_9 -> T_3 )
return - V_62 ;
F_8 ( & V_10 ) ;
F_34 ( & V_9 -> V_11 , & V_63 ) ;
F_11 ( & V_10 ) ;
V_9 -> T_3 [ 0 ] . V_64 = V_65 ;
V_9 -> T_3 [ 0 ] . V_66 = 0 ;
V_9 -> T_3 [ 0 ] . V_67 = V_68 | V_69 ;
V_9 -> T_3 [ 0 ] . V_70 = & V_9 -> T_3 [ 2 ] ;
V_9 -> T_3 [ 2 ] . V_64 = V_9 -> V_58 ;
V_9 -> T_3 [ 2 ] . V_67 = V_68 | V_71 ;
V_9 -> T_3 [ 2 ] . V_72 = F_28 ;
V_9 -> T_3 [ 2 ] . V_1 = V_9 ;
V_9 -> V_73 = F_35 ( V_9 -> T_3 ) ;
if ( ! V_9 -> V_73 )
goto V_47;
return 0 ;
V_47:
F_8 ( & V_10 ) ;
F_36 ( & V_9 -> V_11 ) ;
F_11 ( & V_10 ) ;
F_37 ( V_9 -> T_3 ) ;
return - V_62 ;
}
void F_38 ( struct V_8 * V_9 )
{
F_8 ( & V_10 ) ;
F_36 ( & V_9 -> V_11 ) ;
F_11 ( & V_10 ) ;
F_39 ( V_9 -> V_73 ) ;
F_37 ( V_9 -> T_3 ) ;
}
static int F_40 ( struct V_74 * V_75 )
{
struct V_8 * V_9 ;
int V_52 ;
struct V_6 * V_7 ;
F_7 () ;
F_25 ( & V_48 ) ;
if ( V_33 ) {
F_17 ( V_38 ) ;
V_76 = 1 ;
}
F_26 ( & V_48 ) ;
F_12 () ;
F_8 ( & V_10 ) ;
F_9 (lh, &appldata_ops_list) {
V_9 = F_10 ( V_7 , struct V_8 , V_11 ) ;
if ( V_9 -> V_12 == 1 ) {
V_52 = F_13 ( V_9 -> V_14 , V_59 ,
( unsigned long ) V_9 -> V_1 , V_9 -> V_57 ,
V_9 -> V_18 ) ;
if ( V_52 != 0 )
F_31 ( L_7
L_6 , V_9 -> V_58 , V_52 ) ;
}
}
F_11 ( & V_10 ) ;
return 0 ;
}
static int F_41 ( struct V_74 * V_75 )
{
struct V_8 * V_9 ;
int V_52 ;
struct V_6 * V_7 ;
F_7 () ;
F_25 ( & V_48 ) ;
if ( V_76 ) {
F_17 ( V_32 ) ;
V_76 = 0 ;
}
F_26 ( & V_48 ) ;
F_12 () ;
F_8 ( & V_10 ) ;
F_9 (lh, &appldata_ops_list) {
V_9 = F_10 ( V_7 , struct V_8 , V_11 ) ;
if ( V_9 -> V_12 == 1 ) {
V_9 -> V_13 ( V_9 -> V_1 ) ;
V_52 = F_13 ( V_9 -> V_14 ,
V_56 ,
( unsigned long ) V_9 -> V_1 , V_9 -> V_57 ,
V_9 -> V_18 ) ;
if ( V_52 != 0 ) {
F_31 ( L_5
L_6 , V_9 -> V_58 , V_52 ) ;
}
}
}
F_11 ( & V_10 ) ;
return 0 ;
}
static int F_42 ( struct V_74 * V_75 )
{
return F_41 ( V_75 ) ;
}
static void T_7 F_43 ( int V_77 )
{
F_44 ( & F_19 ( V_36 , V_77 ) ) ;
F_19 ( V_36 , V_77 ) . V_15 = F_1 ;
F_19 ( V_36 , V_77 ) . V_1 = ( unsigned long )
& V_78 ;
F_45 ( & V_2 ) ;
F_25 ( & V_48 ) ;
F_17 ( V_39 ) ;
F_26 ( & V_48 ) ;
}
static void T_7 F_46 ( int V_77 )
{
F_21 ( & F_19 ( V_36 , V_77 ) ) ;
if ( F_2 ( & V_2 ) ) {
F_3 ( & V_2 , F_4 () ) ;
F_5 ( V_3 , & V_78 ) ;
}
F_25 ( & V_48 ) ;
F_17 ( V_39 ) ;
F_26 ( & V_48 ) ;
}
static int T_7 F_47 ( struct V_79 * V_80 ,
unsigned long V_81 ,
void * V_82 )
{
switch ( V_81 ) {
case V_83 :
case V_84 :
F_43 ( ( long ) V_82 ) ;
break;
case V_85 :
case V_86 :
F_46 ( ( long ) V_82 ) ;
break;
default:
break;
}
return V_87 ;
}
static int T_8 F_48 ( void )
{
int V_31 , V_52 ;
V_52 = F_49 ( & V_88 ) ;
if ( V_52 )
return V_52 ;
V_89 = F_50 ( L_8 , - 1 , NULL ,
0 ) ;
if ( F_51 ( V_89 ) ) {
V_52 = F_52 ( V_89 ) ;
goto V_90;
}
V_3 = F_53 ( L_8 ) ;
if ( ! V_3 ) {
V_52 = - V_62 ;
goto V_91;
}
F_7 () ;
F_18 (i)
F_43 ( V_31 ) ;
F_12 () ;
F_54 ( & V_92 ) ;
V_93 = F_35 ( V_94 ) ;
return 0 ;
V_91:
F_55 ( V_89 ) ;
V_90:
F_56 ( & V_88 ) ;
return V_52 ;
}
