static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
unsigned V_8 ;
const char * V_9 ;
static struct V_10 V_11 [] = {
{ 0 , 6 , L_1 } ,
{ 1 , V_12 , L_2 } ,
{ 0 , 255 , L_3 } ,
{ 0 , V_12 , L_4 } ,
} ;
if ( ! V_2 -> V_8 )
return 0 ;
V_7 = F_2 ( V_11 , V_2 , & V_8 , & V_6 -> error ) ;
if ( V_7 )
return V_7 ;
while ( V_8 ) {
V_9 = F_3 ( V_2 ) ;
V_8 -- ;
if ( ! strcasecmp ( V_9 , L_5 ) ) {
if ( F_4 ( V_13 , & V_4 -> V_14 ) ) {
V_6 -> error = L_6 ;
return - V_15 ;
}
continue;
}
if ( ! strcasecmp ( V_9 , L_7 ) ) {
if ( ! V_8 ) {
V_6 -> error = L_8 ;
return - V_15 ;
}
V_7 = F_5 ( V_11 + 1 , V_2 , & V_4 -> V_16 , & V_6 -> error ) ;
if ( V_7 )
return V_7 ;
V_8 -- ;
V_9 = F_3 ( V_2 ) ;
if ( ! strcasecmp ( V_9 , L_9 ) )
V_4 -> V_17 = V_18 ;
else if ( ! strcasecmp ( V_9 , L_10 ) )
V_4 -> V_17 = V_19 ;
else {
V_6 -> error = L_11 ;
return - V_15 ;
}
V_8 -- ;
V_7 = F_5 ( V_11 + 2 , V_2 , & V_4 -> V_20 , & V_6 -> error ) ;
if ( V_7 )
return V_7 ;
V_8 -- ;
V_7 = F_5 ( V_11 + 3 , V_2 , & V_4 -> V_21 , & V_6 -> error ) ;
if ( V_7 )
return V_7 ;
V_8 -- ;
continue;
}
V_6 -> error = L_12 ;
return - V_15 ;
}
if ( F_6 ( V_13 , & V_4 -> V_14 ) && ( V_4 -> V_17 == V_18 ) ) {
V_6 -> error = L_13 ;
return - V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , unsigned int V_8 , char * * V_22 )
{
static struct V_10 V_11 [] = {
{ 0 , V_12 , L_14 } ,
{ 0 , V_12 , L_15 } ,
} ;
int V_7 ;
struct V_3 * V_4 ;
unsigned long long V_23 ;
struct V_1 V_2 ;
const char * V_24 ;
char V_25 ;
V_2 . V_8 = V_8 ;
V_2 . V_22 = V_22 ;
if ( V_8 < 4 ) {
V_6 -> error = L_16 ;
return - V_15 ;
}
V_4 = F_8 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 ) {
V_6 -> error = L_17 ;
return - V_27 ;
}
V_4 -> V_28 = V_29 ;
V_24 = F_3 ( & V_2 ) ;
if ( sscanf ( F_3 ( & V_2 ) , L_18 , & V_23 , & V_25 ) != 1 ) {
V_6 -> error = L_19 ;
goto V_30;
}
V_4 -> V_31 = V_23 ;
V_7 = F_5 ( V_11 , & V_2 , & V_4 -> V_32 , & V_6 -> error ) ;
if ( V_7 )
goto V_30;
V_7 = F_5 ( V_11 , & V_2 , & V_4 -> V_33 , & V_6 -> error ) ;
if ( V_7 )
goto V_30;
if ( ! ( V_4 -> V_32 + V_4 -> V_33 ) ) {
V_6 -> error = L_20 ;
goto V_30;
}
if ( V_4 -> V_32 + V_4 -> V_33 < V_4 -> V_32 ) {
V_6 -> error = L_21 ;
goto V_30;
}
V_7 = F_1 ( & V_2 , V_4 , V_6 ) ;
if ( V_7 )
goto V_30;
if ( F_9 ( V_6 , V_24 , F_10 ( V_6 -> V_34 ) , & V_4 -> V_35 ) ) {
V_6 -> error = L_22 ;
goto V_30;
}
V_6 -> V_36 = 1 ;
V_6 -> V_37 = 1 ;
V_6 -> V_38 = sizeof( struct V_39 ) ;
V_6 -> V_40 = V_4 ;
return 0 ;
V_30:
F_11 ( V_4 ) ;
return - V_15 ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_40 ;
F_13 ( V_6 , V_4 -> V_35 ) ;
F_11 ( V_4 ) ;
}
static T_1 F_14 ( struct V_5 * V_6 , T_1 V_41 )
{
struct V_3 * V_4 = V_6 -> V_40 ;
return V_4 -> V_31 + F_15 ( V_6 , V_41 ) ;
}
static void F_16 ( struct V_5 * V_6 , struct V_42 * V_42 )
{
struct V_3 * V_4 = V_6 -> V_40 ;
V_42 -> V_43 = V_4 -> V_35 -> V_44 ;
if ( F_17 ( V_42 ) )
V_42 -> V_45 . V_41 =
F_14 ( V_6 , V_42 -> V_45 . V_41 ) ;
}
static void F_18 ( struct V_42 * V_42 , struct V_3 * V_4 )
{
unsigned V_46 = F_19 ( V_42 ) ;
char * V_47 = F_20 ( V_42 ) ;
if ( V_47 && V_46 >= V_4 -> V_16 ) {
V_47 [ V_4 -> V_16 - 1 ] = V_4 -> V_20 ;
F_21 ( L_23
L_24 ,
V_42 , V_4 -> V_20 , V_4 -> V_16 ,
( F_22 ( V_42 ) == V_18 ) ? 'w' : 'r' , V_42 -> V_48 ,
( unsigned long long ) V_42 -> V_45 . V_41 , V_46 ) ;
}
}
static int F_23 ( struct V_5 * V_6 , struct V_42 * V_42 )
{
struct V_3 * V_4 = V_6 -> V_40 ;
unsigned V_49 ;
struct V_39 * V_50 = F_24 ( V_42 , sizeof( struct V_39 ) ) ;
V_50 -> V_51 = false ;
V_49 = ( V_29 - V_4 -> V_28 ) / V_52 ;
if ( V_49 % ( V_4 -> V_32 + V_4 -> V_33 ) >= V_4 -> V_32 ) {
V_50 -> V_51 = true ;
if ( F_22 ( V_42 ) == V_19 )
goto V_53;
if ( F_6 ( V_13 , & V_4 -> V_14 ) ) {
F_25 ( V_42 , 0 ) ;
return V_54 ;
}
if ( V_4 -> V_16 && ( V_4 -> V_17 == V_18 ) ) {
if ( F_26 ( V_42 , V_4 ) )
F_18 ( V_42 , V_4 ) ;
goto V_53;
}
return - V_55 ;
}
V_53:
F_16 ( V_6 , V_42 ) ;
return V_56 ;
}
static int F_27 ( struct V_5 * V_6 , struct V_42 * V_42 , int error )
{
struct V_3 * V_4 = V_6 -> V_40 ;
struct V_39 * V_50 = F_24 ( V_42 , sizeof( struct V_39 ) ) ;
if ( V_4 -> V_16 && ! error && V_50 -> V_51 &&
( F_22 ( V_42 ) == V_19 ) && ( V_4 -> V_17 == V_19 ) &&
F_26 ( V_42 , V_4 ) )
F_18 ( V_42 , V_4 ) ;
return error ;
}
static void F_28 ( struct V_5 * V_6 , T_2 type ,
unsigned V_57 , char * V_58 , unsigned V_59 )
{
unsigned V_60 = 0 ;
struct V_3 * V_4 = V_6 -> V_40 ;
unsigned V_61 ;
switch ( type ) {
case V_62 :
V_58 [ 0 ] = '\0' ;
break;
case V_63 :
F_29 ( L_25 , V_4 -> V_35 -> V_64 ,
( unsigned long long ) V_4 -> V_31 , V_4 -> V_32 ,
V_4 -> V_33 ) ;
V_61 = F_6 ( V_13 , & V_4 -> V_14 ) ;
F_29 ( L_26 , V_61 + ( V_4 -> V_16 > 0 ) * 5 ) ;
if ( V_61 )
F_29 ( L_27 ) ;
if ( V_4 -> V_16 )
F_29 ( L_28 ,
V_4 -> V_16 ,
( V_4 -> V_17 == V_18 ) ? 'w' : 'r' ,
V_4 -> V_20 , V_4 -> V_21 ) ;
break;
}
}
static int F_30 ( struct V_5 * V_6 , unsigned int V_65 , unsigned long V_66 )
{
struct V_3 * V_4 = V_6 -> V_40 ;
struct V_67 * V_35 = V_4 -> V_35 ;
int V_7 = 0 ;
if ( V_4 -> V_31 ||
V_6 -> V_68 != F_31 ( V_35 -> V_44 -> V_69 ) >> V_70 )
V_7 = F_32 ( NULL , V_65 ) ;
return V_7 ? : F_33 ( V_35 -> V_44 , V_35 -> V_71 , V_65 , V_66 ) ;
}
static int F_34 ( struct V_5 * V_6 , struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
struct V_3 * V_4 = V_6 -> V_40 ;
struct V_77 * V_78 = F_35 ( V_4 -> V_35 -> V_44 ) ;
if ( ! V_78 -> V_79 )
return V_76 ;
V_73 -> V_43 = V_4 -> V_35 -> V_44 ;
V_73 -> V_41 = F_14 ( V_6 , V_73 -> V_41 ) ;
return F_36 ( V_76 , V_78 -> V_79 ( V_78 , V_73 , V_75 ) ) ;
}
static int F_37 ( struct V_5 * V_6 , T_3 V_80 , void * V_47 )
{
struct V_3 * V_4 = V_6 -> V_40 ;
return V_80 ( V_6 , V_4 -> V_35 , V_4 -> V_31 , V_6 -> V_68 , V_47 ) ;
}
static int T_4 F_38 ( void )
{
int V_7 = F_39 ( & V_81 ) ;
if ( V_7 < 0 )
F_40 ( L_29 , V_7 ) ;
return V_7 ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_81 ) ;
}
