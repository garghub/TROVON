static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
unsigned V_8 ;
const char * V_9 ;
static const struct V_10 V_11 [] = {
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
} else if ( F_5 ( V_16 , & V_4 -> V_14 ) ) {
V_6 -> error = L_7 ;
return - V_15 ;
}
continue;
}
if ( ! strcasecmp ( V_9 , L_8 ) ) {
if ( F_4 ( V_16 , & V_4 -> V_14 ) ) {
V_6 -> error = L_9 ;
return - V_15 ;
} else if ( F_5 ( V_13 , & V_4 -> V_14 ) ) {
V_6 -> error = L_10 ;
return - V_15 ;
}
continue;
}
if ( ! strcasecmp ( V_9 , L_11 ) ) {
if ( ! V_8 ) {
V_6 -> error = L_12 ;
return - V_15 ;
}
V_7 = F_6 ( V_11 + 1 , V_2 , & V_4 -> V_17 , & V_6 -> error ) ;
if ( V_7 )
return V_7 ;
V_8 -- ;
V_9 = F_3 ( V_2 ) ;
if ( ! strcasecmp ( V_9 , L_13 ) )
V_4 -> V_18 = V_19 ;
else if ( ! strcasecmp ( V_9 , L_14 ) )
V_4 -> V_18 = V_20 ;
else {
V_6 -> error = L_15 ;
return - V_15 ;
}
V_8 -- ;
V_7 = F_6 ( V_11 + 2 , V_2 , & V_4 -> V_21 , & V_6 -> error ) ;
if ( V_7 )
return V_7 ;
V_8 -- ;
V_7 = F_6 ( V_11 + 3 , V_2 , & V_4 -> V_22 , & V_6 -> error ) ;
if ( V_7 )
return V_7 ;
V_8 -- ;
continue;
}
V_6 -> error = L_16 ;
return - V_15 ;
}
if ( F_5 ( V_13 , & V_4 -> V_14 ) && ( V_4 -> V_18 == V_19 ) ) {
V_6 -> error = L_17 ;
return - V_15 ;
} else if ( F_5 ( V_16 , & V_4 -> V_14 ) && ( V_4 -> V_18 == V_19 ) ) {
V_6 -> error = L_18 ;
return - V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , unsigned int V_8 , char * * V_23 )
{
static const struct V_10 V_11 [] = {
{ 0 , V_12 , L_19 } ,
{ 0 , V_12 , L_20 } ,
} ;
int V_7 ;
struct V_3 * V_4 ;
unsigned long long V_24 ;
struct V_1 V_2 ;
const char * V_25 ;
char V_26 ;
V_2 . V_8 = V_8 ;
V_2 . V_23 = V_23 ;
if ( V_8 < 4 ) {
V_6 -> error = L_21 ;
return - V_15 ;
}
V_4 = F_8 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 ) {
V_6 -> error = L_22 ;
return - V_28 ;
}
V_4 -> V_29 = V_30 ;
V_25 = F_3 ( & V_2 ) ;
V_7 = - V_15 ;
if ( sscanf ( F_3 ( & V_2 ) , L_23 , & V_24 , & V_26 ) != 1 ) {
V_6 -> error = L_24 ;
goto V_31;
}
V_4 -> V_32 = V_24 ;
V_7 = F_6 ( V_11 , & V_2 , & V_4 -> V_33 , & V_6 -> error ) ;
if ( V_7 )
goto V_31;
V_7 = F_6 ( V_11 , & V_2 , & V_4 -> V_34 , & V_6 -> error ) ;
if ( V_7 )
goto V_31;
if ( ! ( V_4 -> V_33 + V_4 -> V_34 ) ) {
V_6 -> error = L_25 ;
V_7 = - V_15 ;
goto V_31;
}
if ( V_4 -> V_33 + V_4 -> V_34 < V_4 -> V_33 ) {
V_6 -> error = L_26 ;
V_7 = - V_15 ;
goto V_31;
}
V_7 = F_1 ( & V_2 , V_4 , V_6 ) ;
if ( V_7 )
goto V_31;
V_7 = F_9 ( V_6 , V_25 , F_10 ( V_6 -> V_35 ) , & V_4 -> V_36 ) ;
if ( V_7 ) {
V_6 -> error = L_27 ;
goto V_31;
}
V_6 -> V_37 = 1 ;
V_6 -> V_38 = 1 ;
V_6 -> V_39 = sizeof( struct V_40 ) ;
V_6 -> V_41 = V_4 ;
return 0 ;
V_31:
F_11 ( V_4 ) ;
return V_7 ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_41 ;
F_13 ( V_6 , V_4 -> V_36 ) ;
F_11 ( V_4 ) ;
}
static T_1 F_14 ( struct V_5 * V_6 , T_1 V_42 )
{
struct V_3 * V_4 = V_6 -> V_41 ;
return V_4 -> V_32 + F_15 ( V_6 , V_42 ) ;
}
static void F_16 ( struct V_5 * V_6 , struct V_43 * V_43 )
{
struct V_3 * V_4 = V_6 -> V_41 ;
F_17 ( V_43 , V_4 -> V_36 -> V_44 ) ;
if ( F_18 ( V_43 ) || F_19 ( V_43 ) == V_45 )
V_43 -> V_46 . V_42 =
F_14 ( V_6 , V_43 -> V_46 . V_42 ) ;
}
static void F_20 ( struct V_43 * V_43 , struct V_3 * V_4 )
{
unsigned V_47 = F_21 ( V_43 ) ;
char * V_48 = F_22 ( V_43 ) ;
if ( V_48 && V_47 >= V_4 -> V_17 ) {
V_48 [ V_4 -> V_17 - 1 ] = V_4 -> V_21 ;
F_23 ( L_28
L_29 ,
V_43 , V_4 -> V_21 , V_4 -> V_17 ,
( F_24 ( V_43 ) == V_19 ) ? 'w' : 'r' , V_43 -> V_49 ,
( unsigned long long ) V_43 -> V_46 . V_42 , V_47 ) ;
}
}
static int F_25 ( struct V_5 * V_6 , struct V_43 * V_43 )
{
struct V_3 * V_4 = V_6 -> V_41 ;
unsigned V_50 ;
struct V_40 * V_51 = F_26 ( V_43 , sizeof( struct V_40 ) ) ;
V_51 -> V_52 = false ;
if ( F_19 ( V_43 ) == V_45 )
goto V_53;
if ( F_19 ( V_43 ) == V_54 )
goto V_53;
V_50 = ( V_30 - V_4 -> V_29 ) / V_55 ;
if ( V_50 % ( V_4 -> V_33 + V_4 -> V_34 ) >= V_4 -> V_33 ) {
V_51 -> V_52 = true ;
if ( F_24 ( V_43 ) == V_20 ) {
if ( ! V_4 -> V_17 && ! F_5 ( V_13 , & V_4 -> V_14 ) &&
! F_5 ( V_16 , & V_4 -> V_14 ) )
return V_56 ;
goto V_53;
}
if ( F_5 ( V_13 , & V_4 -> V_14 ) ) {
F_27 ( V_43 ) ;
return V_57 ;
}
else if ( F_5 ( V_16 , & V_4 -> V_14 ) ) {
F_28 ( V_43 ) ;
return V_57 ;
}
if ( V_4 -> V_17 && ( V_4 -> V_18 == V_19 ) ) {
if ( F_29 ( V_43 , V_4 ) )
F_20 ( V_43 , V_4 ) ;
goto V_53;
}
return V_56 ;
}
V_53:
F_16 ( V_6 , V_43 ) ;
return V_58 ;
}
static int F_30 ( struct V_5 * V_6 , struct V_43 * V_43 ,
T_2 * error )
{
struct V_3 * V_4 = V_6 -> V_41 ;
struct V_40 * V_51 = F_26 ( V_43 , sizeof( struct V_40 ) ) ;
if ( F_19 ( V_43 ) == V_45 )
return V_59 ;
if ( F_19 ( V_43 ) == V_54 ) {
F_31 ( V_6 , V_43 , V_4 -> V_32 ) ;
return V_59 ;
}
if ( ! * error && V_51 -> V_52 && ( F_24 ( V_43 ) == V_20 ) ) {
if ( V_4 -> V_17 && ( V_4 -> V_18 == V_20 ) &&
F_29 ( V_43 , V_4 ) ) {
F_20 ( V_43 , V_4 ) ;
} else if ( ! F_5 ( V_13 , & V_4 -> V_14 ) &&
! F_5 ( V_16 , & V_4 -> V_14 ) ) {
* error = V_60 ;
}
}
return V_59 ;
}
static void F_32 ( struct V_5 * V_6 , T_3 type ,
unsigned V_61 , char * V_62 , unsigned V_63 )
{
unsigned V_64 = 0 ;
struct V_3 * V_4 = V_6 -> V_41 ;
unsigned V_65 , V_66 ;
switch ( type ) {
case V_67 :
V_62 [ 0 ] = '\0' ;
break;
case V_68 :
F_33 ( L_30 , V_4 -> V_36 -> V_69 ,
( unsigned long long ) V_4 -> V_32 , V_4 -> V_33 ,
V_4 -> V_34 ) ;
V_65 = F_5 ( V_13 , & V_4 -> V_14 ) ;
V_66 = F_5 ( V_16 , & V_4 -> V_14 ) ;
F_33 ( L_31 , V_65 + V_66 + ( V_4 -> V_17 > 0 ) * 5 ) ;
if ( V_65 )
F_33 ( L_32 ) ;
else if ( V_66 )
F_33 ( L_33 ) ;
if ( V_4 -> V_17 )
F_33 ( L_34 ,
V_4 -> V_17 ,
( V_4 -> V_18 == V_19 ) ? 'w' : 'r' ,
V_4 -> V_21 , V_4 -> V_22 ) ;
break;
}
}
static int F_34 ( struct V_5 * V_6 ,
struct V_70 * * V_44 , T_4 * V_71 )
{
struct V_3 * V_4 = V_6 -> V_41 ;
* V_44 = V_4 -> V_36 -> V_44 ;
if ( V_4 -> V_32 ||
V_6 -> V_72 != F_35 ( ( * V_44 ) -> V_73 ) >> V_74 )
return 1 ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 , T_5 V_75 , void * V_48 )
{
struct V_3 * V_4 = V_6 -> V_41 ;
return V_75 ( V_6 , V_4 -> V_36 , V_4 -> V_32 , V_6 -> V_72 , V_48 ) ;
}
static int T_6 F_37 ( void )
{
int V_7 = F_38 ( & V_76 ) ;
if ( V_7 < 0 )
F_39 ( L_35 , V_7 ) ;
return V_7 ;
}
static void T_7 F_40 ( void )
{
F_41 ( & V_76 ) ;
}
