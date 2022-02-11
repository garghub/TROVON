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
V_2 . V_8 = V_8 ;
V_2 . V_22 = V_22 ;
if ( V_8 < 4 ) {
V_6 -> error = L_16 ;
return - V_15 ;
}
V_4 = F_8 ( sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 ) {
V_6 -> error = L_17 ;
return - V_26 ;
}
V_4 -> V_27 = V_28 ;
V_24 = F_3 ( & V_2 ) ;
if ( sscanf ( F_3 ( & V_2 ) , L_18 , & V_23 ) != 1 ) {
V_6 -> error = L_19 ;
goto V_29;
}
V_4 -> V_30 = V_23 ;
V_7 = F_5 ( V_11 , & V_2 , & V_4 -> V_31 , & V_6 -> error ) ;
if ( V_7 )
goto V_29;
V_7 = F_5 ( V_11 , & V_2 , & V_4 -> V_32 , & V_6 -> error ) ;
if ( V_7 )
goto V_29;
if ( ! ( V_4 -> V_31 + V_4 -> V_32 ) ) {
V_6 -> error = L_20 ;
goto V_29;
}
if ( V_4 -> V_31 + V_4 -> V_32 < V_4 -> V_31 ) {
V_6 -> error = L_21 ;
goto V_29;
}
V_7 = F_1 ( & V_2 , V_4 , V_6 ) ;
if ( V_7 )
goto V_29;
if ( F_9 ( V_6 , V_24 , F_10 ( V_6 -> V_33 ) , & V_4 -> V_34 ) ) {
V_6 -> error = L_22 ;
goto V_29;
}
V_6 -> V_35 = 1 ;
V_6 -> V_36 = 1 ;
V_6 -> V_37 = V_4 ;
return 0 ;
V_29:
F_11 ( V_4 ) ;
return - V_15 ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_37 ;
F_13 ( V_6 , V_4 -> V_34 ) ;
F_11 ( V_4 ) ;
}
static T_1 F_14 ( struct V_5 * V_6 , T_1 V_38 )
{
struct V_3 * V_4 = V_6 -> V_37 ;
return V_4 -> V_30 + F_15 ( V_6 , V_38 ) ;
}
static void F_16 ( struct V_5 * V_6 , struct V_39 * V_39 )
{
struct V_3 * V_4 = V_6 -> V_37 ;
V_39 -> V_40 = V_4 -> V_34 -> V_41 ;
if ( F_17 ( V_39 ) )
V_39 -> V_38 = F_14 ( V_6 , V_39 -> V_38 ) ;
}
static void F_18 ( struct V_39 * V_39 , struct V_3 * V_4 )
{
unsigned V_42 = F_19 ( V_39 ) ;
char * V_43 = F_20 ( V_39 ) ;
if ( V_43 && V_42 >= V_4 -> V_16 ) {
V_43 [ V_4 -> V_16 - 1 ] = V_4 -> V_20 ;
F_21 ( L_23
L_24 ,
V_39 , V_4 -> V_20 , V_4 -> V_16 ,
( F_22 ( V_39 ) == V_18 ) ? 'w' : 'r' ,
V_39 -> V_44 , ( unsigned long long ) V_39 -> V_38 , V_42 ) ;
}
}
static int F_23 ( struct V_5 * V_6 , struct V_39 * V_39 ,
union V_45 * V_46 )
{
struct V_3 * V_4 = V_6 -> V_37 ;
unsigned V_47 ;
V_47 = ( V_28 - V_4 -> V_27 ) / V_48 ;
if ( V_47 % ( V_4 -> V_31 + V_4 -> V_32 ) >= V_4 -> V_31 ) {
V_46 -> V_49 = 1 ;
if ( F_22 ( V_39 ) == V_19 )
goto V_50;
if ( F_6 ( V_13 , & V_4 -> V_14 ) ) {
F_24 ( V_39 , 0 ) ;
return V_51 ;
}
if ( V_4 -> V_16 && ( V_4 -> V_17 == V_18 ) ) {
if ( F_25 ( V_39 , V_4 ) )
F_18 ( V_39 , V_4 ) ;
goto V_50;
}
return - V_52 ;
}
V_50:
F_16 ( V_6 , V_39 ) ;
return V_53 ;
}
static int F_26 ( struct V_5 * V_6 , struct V_39 * V_39 ,
int error , union V_45 * V_46 )
{
struct V_3 * V_4 = V_6 -> V_37 ;
unsigned V_54 = V_46 -> V_49 ;
if ( V_4 -> V_16 && ! error && V_54 &&
( F_22 ( V_39 ) == V_19 ) && ( V_4 -> V_17 == V_19 ) &&
F_25 ( V_39 , V_4 ) )
F_18 ( V_39 , V_4 ) ;
return error ;
}
static int F_27 ( struct V_5 * V_6 , T_2 type ,
char * V_55 , unsigned int V_56 )
{
unsigned V_57 = 0 ;
struct V_3 * V_4 = V_6 -> V_37 ;
unsigned V_58 ;
switch ( type ) {
case V_59 :
V_55 [ 0 ] = '\0' ;
break;
case V_60 :
F_28 ( L_25 , V_4 -> V_34 -> V_61 ,
( unsigned long long ) V_4 -> V_30 , V_4 -> V_31 ,
V_4 -> V_32 ) ;
V_58 = F_6 ( V_13 , & V_4 -> V_14 ) ;
F_28 ( L_26 , V_58 + ( V_4 -> V_16 > 0 ) * 5 ) ;
if ( V_58 )
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
static int F_29 ( struct V_5 * V_6 , unsigned int V_62 , unsigned long V_63 )
{
struct V_3 * V_4 = V_6 -> V_37 ;
struct V_64 * V_34 = V_4 -> V_34 ;
int V_7 = 0 ;
if ( V_4 -> V_30 ||
V_6 -> V_65 != F_30 ( V_34 -> V_41 -> V_66 ) >> V_67 )
V_7 = F_31 ( NULL , V_62 ) ;
return V_7 ? : F_32 ( V_34 -> V_41 , V_34 -> V_68 , V_62 , V_63 ) ;
}
static int F_33 ( struct V_5 * V_6 , struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
struct V_3 * V_4 = V_6 -> V_37 ;
struct V_74 * V_75 = F_34 ( V_4 -> V_34 -> V_41 ) ;
if ( ! V_75 -> V_76 )
return V_73 ;
V_70 -> V_40 = V_4 -> V_34 -> V_41 ;
V_70 -> V_38 = F_14 ( V_6 , V_70 -> V_38 ) ;
return F_35 ( V_73 , V_75 -> V_76 ( V_75 , V_70 , V_72 ) ) ;
}
static int F_36 ( struct V_5 * V_6 , T_3 V_77 , void * V_43 )
{
struct V_3 * V_4 = V_6 -> V_37 ;
return V_77 ( V_6 , V_4 -> V_34 , V_4 -> V_30 , V_6 -> V_65 , V_43 ) ;
}
static int T_4 F_37 ( void )
{
int V_7 = F_38 ( & V_78 ) ;
if ( V_7 < 0 )
F_39 ( L_29 , V_7 ) ;
return V_7 ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_78 ) ;
}
