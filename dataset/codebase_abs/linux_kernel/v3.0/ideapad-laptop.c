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
static int F_14 ( void * V_16 , bool V_30 )
{
unsigned long V_31 = ( unsigned long ) V_16 ;
return F_11 ( V_27 , V_31 , ! V_30 ) ;
}
static void F_15 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_16 ( & V_33 -> V_23 ) ;
unsigned long V_36 ;
int V_37 ;
if ( F_7 ( V_27 , 0x23 , & V_36 ) )
return;
V_36 = ! V_36 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_35 -> V_39 [ V_37 ] )
F_17 ( V_35 -> V_39 [ V_37 ] , V_36 ) ;
}
static int T_5 F_18 ( struct V_32 * V_33 ,
int V_23 )
{
struct V_34 * V_35 = F_16 ( & V_33 -> V_23 ) ;
int V_7 ;
unsigned long V_40 ;
if ( V_41 &&
( V_42 [ V_23 ] . type == V_43 ) ) {
F_11 ( V_27 ,
V_42 [ V_23 ] . V_31 , 1 ) ;
return 0 ;
}
V_35 -> V_39 [ V_23 ] = F_19 ( V_42 [ V_23 ] . V_44 , & V_33 -> V_23 ,
V_42 [ V_23 ] . type , & V_45 ,
( void * ) ( long ) V_23 ) ;
if ( ! V_35 -> V_39 [ V_23 ] )
return - V_46 ;
if ( F_7 ( V_27 , V_42 [ V_23 ] . V_31 - 1 ,
& V_40 ) ) {
F_20 ( V_35 -> V_39 [ V_23 ] , 0 ) ;
} else {
V_40 = ! V_40 ;
F_20 ( V_35 -> V_39 [ V_23 ] , V_40 ) ;
}
V_7 = F_21 ( V_35 -> V_39 [ V_23 ] ) ;
if ( V_7 ) {
F_22 ( V_35 -> V_39 [ V_23 ] ) ;
return V_7 ;
}
return 0 ;
}
static void T_6 F_23 ( struct V_32 * V_33 ,
int V_23 )
{
struct V_34 * V_35 = F_16 ( & V_33 -> V_23 ) ;
if ( ! V_35 -> V_39 [ V_23 ] )
return;
F_24 ( V_35 -> V_39 [ V_23 ] ) ;
F_22 ( V_35 -> V_39 [ V_23 ] ) ;
}
static int T_5 F_25 ( struct V_34 * V_35 )
{
int V_5 ;
V_35 -> V_47 = F_26 ( L_8 , - 1 ) ;
if ( ! V_35 -> V_47 )
return - V_46 ;
F_27 ( V_35 -> V_47 , V_35 ) ;
V_5 = F_28 ( V_35 -> V_47 ) ;
if ( V_5 )
goto V_48;
V_5 = F_29 ( & V_35 -> V_47 -> V_23 . V_49 ,
& V_50 ) ;
if ( V_5 )
goto V_51;
return 0 ;
V_51:
F_30 ( V_35 -> V_47 ) ;
V_48:
F_31 ( V_35 -> V_47 ) ;
return V_5 ;
}
static void F_32 ( struct V_34 * V_35 )
{
F_33 ( & V_35 -> V_47 -> V_23 . V_49 ,
& V_50 ) ;
F_34 ( V_35 -> V_47 ) ;
}
static int T_5 F_35 ( struct V_34 * V_35 )
{
struct V_52 * V_53 ;
int error ;
V_53 = F_36 () ;
if ( ! V_53 ) {
F_37 ( L_9 ) ;
return - V_46 ;
}
V_53 -> V_44 = L_10 ;
V_53 -> V_54 = L_11 ;
V_53 -> V_55 . V_56 = V_57 ;
V_53 -> V_23 . V_58 = & V_35 -> V_47 -> V_23 ;
error = F_38 ( V_53 , V_59 , NULL ) ;
if ( error ) {
F_10 ( L_12 ) ;
goto V_60;
}
error = F_39 ( V_53 ) ;
if ( error ) {
F_10 ( L_13 ) ;
goto V_61;
}
V_35 -> V_53 = V_53 ;
return 0 ;
V_61:
F_40 ( V_53 ) ;
V_60:
F_41 ( V_53 ) ;
return error ;
}
static void T_6 F_42 ( struct V_34 * V_35 )
{
F_40 ( V_35 -> V_53 ) ;
F_43 ( V_35 -> V_53 ) ;
V_35 -> V_53 = NULL ;
}
static void F_44 ( struct V_34 * V_35 ,
unsigned long V_62 )
{
F_45 ( V_35 -> V_53 , V_62 , 1 , true ) ;
}
static int T_5 F_46 ( struct V_32 * V_33 )
{
int V_7 , V_37 , V_63 ;
struct V_34 * V_35 ;
if ( F_1 ( V_33 -> V_1 , L_14 , & V_63 ) )
return - V_64 ;
V_35 = F_47 ( sizeof( * V_35 ) , V_65 ) ;
if ( ! V_35 )
return - V_46 ;
F_48 ( & V_33 -> V_23 , V_35 ) ;
V_27 = V_33 -> V_1 ;
V_7 = F_25 ( V_35 ) ;
if ( V_7 )
goto V_66;
V_7 = F_35 ( V_35 ) ;
if ( V_7 )
goto V_67;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( F_49 ( V_42 [ V_37 ] . V_68 , ( unsigned long * ) & V_63 ) )
F_18 ( V_33 , V_37 ) ;
else
V_35 -> V_39 [ V_37 ] = NULL ;
}
F_15 ( V_33 ) ;
return 0 ;
V_67:
F_32 ( V_35 ) ;
V_66:
F_50 ( V_35 ) ;
return V_7 ;
}
static int T_6 F_51 ( struct V_32 * V_33 , int type )
{
struct V_34 * V_35 = F_16 ( & V_33 -> V_23 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
F_23 ( V_33 , V_37 ) ;
F_42 ( V_35 ) ;
F_32 ( V_35 ) ;
F_48 ( & V_33 -> V_23 , NULL ) ;
F_50 ( V_35 ) ;
return 0 ;
}
static void F_52 ( struct V_32 * V_33 , T_7 V_69 )
{
struct V_34 * V_35 = F_16 ( & V_33 -> V_23 ) ;
T_1 V_1 = V_33 -> V_1 ;
unsigned long V_70 , V_71 , V_72 ;
if ( F_7 ( V_1 , 0x10 , & V_70 ) )
return;
if ( F_7 ( V_1 , 0x1A , & V_71 ) )
return;
V_70 = ( V_71 << 8 ) | V_70 ;
for ( V_72 = 0 ; V_72 < 16 ; V_72 ++ ) {
if ( F_49 ( V_72 , & V_70 ) ) {
if ( V_72 == 9 )
F_15 ( V_33 ) ;
else if ( V_72 == 4 )
F_7 ( V_1 , 0x12 , & V_71 ) ;
else
F_44 ( V_35 , V_72 ) ;
}
}
}
static int T_8 F_53 ( void )
{
return F_54 ( & V_73 ) ;
}
static void T_9 F_55 ( void )
{
F_56 ( & V_73 ) ;
}
