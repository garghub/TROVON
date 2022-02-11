static int F_1 ( T_1 V_1 , const char * V_2 , int * V_3 )
{
T_2 V_4 ;
unsigned long long V_5 ;
V_4 = F_2 ( V_1 , ( char * ) V_2 , NULL , & V_5 ) ;
if ( F_3 ( V_4 ) ) {
* V_3 = - 1 ;
return - 1 ;
} else {
* V_3 = V_5 ;
return 0 ;
}
}
static int F_4 ( T_1 V_1 , int V_6 , int * V_7 )
{
T_2 V_4 ;
unsigned long long V_5 ;
struct V_8 V_9 ;
union V_10 V_11 ;
V_9 . V_12 = 1 ;
V_9 . V_13 = & V_11 ;
V_11 . type = V_14 ;
V_11 . integer . V_15 = V_6 ;
V_4 = F_2 ( V_1 , L_1 , & V_9 , & V_5 ) ;
if ( F_3 ( V_4 ) ) {
* V_7 = - 1 ;
return - 1 ;
} else {
* V_7 = V_5 ;
return 0 ;
}
}
static int F_5 ( T_1 V_1 , int V_6 , int V_16 )
{
struct V_8 V_9 ;
union V_10 V_11 [ 2 ] ;
T_2 V_4 ;
V_9 . V_12 = 2 ;
V_9 . V_13 = V_11 ;
V_11 [ 0 ] . type = V_14 ;
V_11 [ 0 ] . integer . V_15 = V_6 ;
V_11 [ 1 ] . type = V_14 ;
V_11 [ 1 ] . integer . V_15 = V_16 ;
V_4 = F_6 ( V_1 , L_2 , & V_9 , NULL ) ;
if ( V_4 != V_17 )
return - 1 ;
return 0 ;
}
static int F_7 ( T_1 V_1 , int V_6 , unsigned long * V_16 )
{
int V_3 ;
unsigned long int V_18 ;
if ( F_5 ( V_1 , 1 , V_6 ) )
return - 1 ;
for ( V_18 = V_19 + ( V_20 ) * V_21 / 1000 + 1 ;
F_8 ( V_19 , V_18 ) ; ) {
F_9 () ;
if ( F_4 ( V_1 , 1 , & V_3 ) )
return - 1 ;
if ( V_3 == 0 ) {
if ( F_4 ( V_1 , 0 , & V_3 ) )
return - 1 ;
* V_16 = V_3 ;
return 0 ;
}
}
F_10 ( L_3 ) ;
return - 1 ;
}
static int F_11 ( T_1 V_1 , int V_6 , unsigned long V_16 )
{
int V_3 ;
unsigned long int V_18 ;
if ( F_5 ( V_1 , 0 , V_16 ) )
return - 1 ;
if ( F_5 ( V_1 , 1 , V_6 ) )
return - 1 ;
for ( V_18 = V_19 + ( V_20 ) * V_21 / 1000 + 1 ;
F_8 ( V_19 , V_18 ) ; ) {
F_9 () ;
if ( F_4 ( V_1 , 1 , & V_3 ) )
return - 1 ;
if ( V_3 == 0 )
return 0 ;
}
F_10 ( L_4 ) ;
return - 1 ;
}
static T_3 F_12 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
unsigned long V_5 ;
if ( F_7 ( V_27 , 0x1D , & V_5 ) )
return sprintf ( V_26 , L_5 ) ;
return sprintf ( V_26 , L_6 , V_5 ) ;
}
static T_3 F_13 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_12 )
{
int V_7 , V_28 ;
if ( ! V_12 )
return 0 ;
if ( sscanf ( V_26 , L_7 , & V_28 ) != 1 )
return - V_29 ;
V_7 = F_11 ( V_27 , 0x1E , V_28 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_12 ;
}
static T_3 F_14 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
struct V_30 * V_31 = F_15 ( V_23 ) ;
return sprintf ( V_26 , L_8 , V_31 -> V_32 ) ;
}
static T_5 F_16 ( struct V_33 * V_34 ,
struct V_35 * V_25 ,
int V_36 )
{
struct V_22 * V_23 = F_17 ( V_34 , struct V_22 , V_34 ) ;
struct V_30 * V_31 = F_15 ( V_23 ) ;
bool V_37 ;
if ( V_25 == & V_38 . V_25 )
V_37 = F_18 ( V_39 , & ( V_31 -> V_32 ) ) ;
else
V_37 = true ;
return V_37 ? V_25 -> V_40 : 0 ;
}
static int F_19 ( void * V_16 , bool V_41 )
{
unsigned long V_42 = ( unsigned long ) V_16 ;
return F_11 ( V_27 , V_42 , ! V_41 ) ;
}
static void F_20 ( struct V_43 * V_44 )
{
struct V_30 * V_31 = F_15 ( & V_44 -> V_23 ) ;
unsigned long V_45 ;
int V_46 ;
if ( F_7 ( V_27 , 0x23 , & V_45 ) )
return;
V_45 = ! V_45 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
if ( V_31 -> V_48 [ V_46 ] )
F_21 ( V_31 -> V_48 [ V_46 ] , V_45 ) ;
}
static int T_6 F_22 ( struct V_43 * V_44 ,
int V_23 )
{
struct V_30 * V_31 = F_15 ( & V_44 -> V_23 ) ;
int V_7 ;
unsigned long V_49 ;
if ( V_50 &&
( V_51 [ V_23 ] . type == V_52 ) ) {
F_11 ( V_27 ,
V_51 [ V_23 ] . V_42 , 1 ) ;
return 0 ;
}
V_31 -> V_48 [ V_23 ] = F_23 ( V_51 [ V_23 ] . V_53 , & V_44 -> V_23 ,
V_51 [ V_23 ] . type , & V_54 ,
( void * ) ( long ) V_23 ) ;
if ( ! V_31 -> V_48 [ V_23 ] )
return - V_55 ;
if ( F_7 ( V_27 , V_51 [ V_23 ] . V_42 - 1 ,
& V_49 ) ) {
F_24 ( V_31 -> V_48 [ V_23 ] , 0 ) ;
} else {
V_49 = ! V_49 ;
F_24 ( V_31 -> V_48 [ V_23 ] , V_49 ) ;
}
V_7 = F_25 ( V_31 -> V_48 [ V_23 ] ) ;
if ( V_7 ) {
F_26 ( V_31 -> V_48 [ V_23 ] ) ;
return V_7 ;
}
return 0 ;
}
static void F_27 ( struct V_43 * V_44 , int V_23 )
{
struct V_30 * V_31 = F_15 ( & V_44 -> V_23 ) ;
if ( ! V_31 -> V_48 [ V_23 ] )
return;
F_28 ( V_31 -> V_48 [ V_23 ] ) ;
F_26 ( V_31 -> V_48 [ V_23 ] ) ;
}
static int T_6 F_29 ( struct V_30 * V_31 )
{
int V_5 ;
V_31 -> V_56 = F_30 ( L_9 , - 1 ) ;
if ( ! V_31 -> V_56 )
return - V_55 ;
F_31 ( V_31 -> V_56 , V_31 ) ;
V_5 = F_32 ( V_31 -> V_56 ) ;
if ( V_5 )
goto V_57;
V_5 = F_33 ( & V_31 -> V_56 -> V_23 . V_34 ,
& V_58 ) ;
if ( V_5 )
goto V_59;
return 0 ;
V_59:
F_34 ( V_31 -> V_56 ) ;
V_57:
F_35 ( V_31 -> V_56 ) ;
return V_5 ;
}
static void F_36 ( struct V_30 * V_31 )
{
F_37 ( & V_31 -> V_56 -> V_23 . V_34 ,
& V_58 ) ;
F_38 ( V_31 -> V_56 ) ;
}
static int T_6 F_39 ( struct V_30 * V_31 )
{
struct V_60 * V_61 ;
int error ;
V_61 = F_40 () ;
if ( ! V_61 ) {
F_41 ( L_10 ) ;
return - V_55 ;
}
V_61 -> V_53 = L_11 ;
V_61 -> V_62 = L_12 ;
V_61 -> V_63 . V_64 = V_65 ;
V_61 -> V_23 . V_66 = & V_31 -> V_56 -> V_23 ;
error = F_42 ( V_61 , V_67 , NULL ) ;
if ( error ) {
F_10 ( L_13 ) ;
goto V_68;
}
error = F_43 ( V_61 ) ;
if ( error ) {
F_10 ( L_14 ) ;
goto V_69;
}
V_31 -> V_61 = V_61 ;
return 0 ;
V_69:
F_44 ( V_61 ) ;
V_68:
F_45 ( V_61 ) ;
return error ;
}
static void F_46 ( struct V_30 * V_31 )
{
F_44 ( V_31 -> V_61 ) ;
F_47 ( V_31 -> V_61 ) ;
V_31 -> V_61 = NULL ;
}
static void F_48 ( struct V_30 * V_31 ,
unsigned long V_70 )
{
F_49 ( V_31 -> V_61 , V_70 , 1 , true ) ;
}
static int F_50 ( struct V_71 * V_72 )
{
unsigned long V_73 ;
if ( F_7 ( V_27 , 0x12 , & V_73 ) )
return - V_74 ;
return V_73 ;
}
static int F_51 ( struct V_71 * V_72 )
{
if ( F_11 ( V_27 , 0x13 , V_72 -> V_75 . V_76 ) )
return - V_74 ;
if ( F_11 ( V_27 , 0x33 ,
V_72 -> V_75 . V_77 == V_78 ? 0 : 1 ) )
return - V_74 ;
return 0 ;
}
static int F_52 ( struct V_30 * V_31 )
{
struct V_71 * V_72 ;
struct V_79 V_75 ;
unsigned long V_80 , V_73 , V_77 ;
if ( F_7 ( V_27 , 0x11 , & V_80 ) )
return - V_74 ;
if ( F_7 ( V_27 , 0x12 , & V_73 ) )
return - V_74 ;
if ( F_7 ( V_27 , 0x18 , & V_77 ) )
return - V_74 ;
memset ( & V_75 , 0 , sizeof( struct V_79 ) ) ;
V_75 . V_81 = V_80 ;
V_75 . type = V_82 ;
V_72 = F_53 ( L_9 ,
& V_31 -> V_56 -> V_23 ,
V_31 ,
& V_83 ,
& V_75 ) ;
if ( F_54 ( V_72 ) ) {
F_10 ( L_15 ) ;
return F_55 ( V_72 ) ;
}
V_31 -> V_72 = V_72 ;
V_72 -> V_75 . V_76 = V_73 ;
V_72 -> V_75 . V_77 = V_77 ? V_84 : V_78 ;
F_56 ( V_72 ) ;
return 0 ;
}
static void F_57 ( struct V_30 * V_31 )
{
if ( V_31 -> V_72 )
F_58 ( V_31 -> V_72 ) ;
V_31 -> V_72 = NULL ;
}
static void F_59 ( struct V_30 * V_31 )
{
unsigned long V_77 ;
struct V_71 * V_72 = V_31 -> V_72 ;
if ( F_7 ( V_27 , 0x18 , & V_77 ) )
return;
V_72 -> V_75 . V_77 = V_77 ? V_84 : V_78 ;
}
static void F_60 ( struct V_30 * V_31 )
{
unsigned long V_73 ;
if ( V_31 -> V_72 == NULL ) {
F_7 ( V_27 , 0x12 , & V_73 ) ;
return;
}
F_61 ( V_31 -> V_72 , V_85 ) ;
}
static int T_6 F_62 ( struct V_43 * V_44 )
{
int V_7 , V_46 ;
unsigned long V_32 ;
struct V_30 * V_31 ;
if ( F_1 ( V_44 -> V_1 , L_16 , ( int * ) & V_32 ) )
return - V_86 ;
V_31 = F_63 ( sizeof( * V_31 ) , V_87 ) ;
if ( ! V_31 )
return - V_55 ;
F_64 ( & V_44 -> V_23 , V_31 ) ;
V_27 = V_44 -> V_1 ;
V_31 -> V_32 = V_32 ;
V_7 = F_29 ( V_31 ) ;
if ( V_7 )
goto V_88;
V_7 = F_39 ( V_31 ) ;
if ( V_7 )
goto V_89;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
if ( F_18 ( V_51 [ V_46 ] . V_90 , & V_32 ) )
F_22 ( V_44 , V_46 ) ;
else
V_31 -> V_48 [ V_46 ] = NULL ;
}
F_20 ( V_44 ) ;
if ( ! F_65 () ) {
V_7 = F_52 ( V_31 ) ;
if ( V_7 && V_7 != - V_86 )
goto V_91;
}
return 0 ;
V_91:
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
F_27 ( V_44 , V_46 ) ;
F_46 ( V_31 ) ;
V_89:
F_36 ( V_31 ) ;
V_88:
F_66 ( V_31 ) ;
return V_7 ;
}
static int T_7 F_67 ( struct V_43 * V_44 , int type )
{
struct V_30 * V_31 = F_15 ( & V_44 -> V_23 ) ;
int V_46 ;
F_57 ( V_31 ) ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
F_27 ( V_44 , V_46 ) ;
F_46 ( V_31 ) ;
F_36 ( V_31 ) ;
F_64 ( & V_44 -> V_23 , NULL ) ;
F_66 ( V_31 ) ;
return 0 ;
}
static void F_68 ( struct V_43 * V_44 , T_8 V_92 )
{
struct V_30 * V_31 = F_15 ( & V_44 -> V_23 ) ;
T_1 V_1 = V_44 -> V_1 ;
unsigned long V_93 , V_94 , V_95 ;
if ( F_7 ( V_1 , 0x10 , & V_93 ) )
return;
if ( F_7 ( V_1 , 0x1A , & V_94 ) )
return;
V_93 = ( V_94 << 8 ) | V_93 ;
for ( V_95 = 0 ; V_95 < 16 ; V_95 ++ ) {
if ( F_18 ( V_95 , & V_93 ) ) {
switch ( V_95 ) {
case 9 :
F_20 ( V_44 ) ;
break;
case 4 :
F_60 ( V_31 ) ;
break;
case 2 :
F_59 ( V_31 ) ;
break;
default:
F_48 ( V_31 , V_95 ) ;
}
}
}
}
static int T_9 F_69 ( void )
{
return F_70 ( & V_96 ) ;
}
static void T_10 F_71 ( void )
{
F_72 ( & V_96 ) ;
}
