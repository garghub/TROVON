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
V_6 -> V_38 = V_4 ;
return 0 ;
V_30:
F_11 ( V_4 ) ;
return - V_15 ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_38 ;
F_13 ( V_6 , V_4 -> V_35 ) ;
F_11 ( V_4 ) ;
}
static T_1 F_14 ( struct V_5 * V_6 , T_1 V_39 )
{
struct V_3 * V_4 = V_6 -> V_38 ;
return V_4 -> V_31 + F_15 ( V_6 , V_39 ) ;
}
static void F_16 ( struct V_5 * V_6 , struct V_40 * V_40 )
{
struct V_3 * V_4 = V_6 -> V_38 ;
V_40 -> V_41 = V_4 -> V_35 -> V_42 ;
if ( F_17 ( V_40 ) )
V_40 -> V_39 = F_14 ( V_6 , V_40 -> V_39 ) ;
}
static void F_18 ( struct V_40 * V_40 , struct V_3 * V_4 )
{
unsigned V_43 = F_19 ( V_40 ) ;
char * V_44 = F_20 ( V_40 ) ;
if ( V_44 && V_43 >= V_4 -> V_16 ) {
V_44 [ V_4 -> V_16 - 1 ] = V_4 -> V_20 ;
F_21 ( L_23
L_24 ,
V_40 , V_4 -> V_20 , V_4 -> V_16 ,
( F_22 ( V_40 ) == V_18 ) ? 'w' : 'r' ,
V_40 -> V_45 , ( unsigned long long ) V_40 -> V_39 , V_43 ) ;
}
}
static int F_23 ( struct V_5 * V_6 , struct V_40 * V_40 ,
union V_46 * V_47 )
{
struct V_3 * V_4 = V_6 -> V_38 ;
unsigned V_48 ;
V_48 = ( V_29 - V_4 -> V_28 ) / V_49 ;
if ( V_48 % ( V_4 -> V_32 + V_4 -> V_33 ) >= V_4 -> V_32 ) {
V_47 -> V_50 = 1 ;
if ( F_22 ( V_40 ) == V_19 )
goto V_51;
if ( F_6 ( V_13 , & V_4 -> V_14 ) ) {
F_24 ( V_40 , 0 ) ;
return V_52 ;
}
if ( V_4 -> V_16 && ( V_4 -> V_17 == V_18 ) ) {
if ( F_25 ( V_40 , V_4 ) )
F_18 ( V_40 , V_4 ) ;
goto V_51;
}
return - V_53 ;
}
V_51:
F_16 ( V_6 , V_40 ) ;
return V_54 ;
}
static int F_26 ( struct V_5 * V_6 , struct V_40 * V_40 ,
int error , union V_46 * V_47 )
{
struct V_3 * V_4 = V_6 -> V_38 ;
unsigned V_55 = V_47 -> V_50 ;
if ( V_4 -> V_16 && ! error && V_55 &&
( F_22 ( V_40 ) == V_19 ) && ( V_4 -> V_17 == V_19 ) &&
F_25 ( V_40 , V_4 ) )
F_18 ( V_40 , V_4 ) ;
return error ;
}
static int F_27 ( struct V_5 * V_6 , T_2 type ,
unsigned V_56 , char * V_57 , unsigned V_58 )
{
unsigned V_59 = 0 ;
struct V_3 * V_4 = V_6 -> V_38 ;
unsigned V_60 ;
switch ( type ) {
case V_61 :
V_57 [ 0 ] = '\0' ;
break;
case V_62 :
F_28 ( L_25 , V_4 -> V_35 -> V_63 ,
( unsigned long long ) V_4 -> V_31 , V_4 -> V_32 ,
V_4 -> V_33 ) ;
V_60 = F_6 ( V_13 , & V_4 -> V_14 ) ;
F_28 ( L_26 , V_60 + ( V_4 -> V_16 > 0 ) * 5 ) ;
if ( V_60 )
F_28 ( L_27 ) ;
if ( V_4 -> V_16 )
F_28 ( L_28 ,
V_4 -> V_16 ,
( V_4 -> V_17 == V_18 ) ? 'w' : 'r' ,
V_4 -> V_20 , V_4 -> V_21 ) ;
break;
}
return 0 ;
}
static int F_29 ( struct V_5 * V_6 , unsigned int V_64 , unsigned long V_65 )
{
struct V_3 * V_4 = V_6 -> V_38 ;
struct V_66 * V_35 = V_4 -> V_35 ;
int V_7 = 0 ;
if ( V_4 -> V_31 ||
V_6 -> V_67 != F_30 ( V_35 -> V_42 -> V_68 ) >> V_69 )
V_7 = F_31 ( NULL , V_64 ) ;
return V_7 ? : F_32 ( V_35 -> V_42 , V_35 -> V_70 , V_64 , V_65 ) ;
}
static int F_33 ( struct V_5 * V_6 , struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_3 * V_4 = V_6 -> V_38 ;
struct V_76 * V_77 = F_34 ( V_4 -> V_35 -> V_42 ) ;
if ( ! V_77 -> V_78 )
return V_75 ;
V_72 -> V_41 = V_4 -> V_35 -> V_42 ;
V_72 -> V_39 = F_14 ( V_6 , V_72 -> V_39 ) ;
return F_35 ( V_75 , V_77 -> V_78 ( V_77 , V_72 , V_74 ) ) ;
}
static int F_36 ( struct V_5 * V_6 , T_3 V_79 , void * V_44 )
{
struct V_3 * V_4 = V_6 -> V_38 ;
return V_79 ( V_6 , V_4 -> V_35 , V_4 -> V_31 , V_6 -> V_67 , V_44 ) ;
}
static int T_4 F_37 ( void )
{
int V_7 = F_38 ( & V_80 ) ;
if ( V_7 < 0 )
F_39 ( L_29 , V_7 ) ;
return V_7 ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_80 ) ;
}
