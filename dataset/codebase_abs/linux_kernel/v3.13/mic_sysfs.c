void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 -> V_4 -> V_5 , L_1 ,
V_6 [ V_2 -> V_3 ] ,
V_6 [ V_3 ] ) ;
V_2 -> V_3 = V_3 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
F_2 ( V_2 -> V_4 -> V_5 , L_2 ,
V_8 [ V_2 -> V_7 ] ,
V_8 [ V_7 ] ) ;
V_2 -> V_7 = V_7 ;
F_4 ( V_2 -> V_9 ) ;
}
static T_2
F_5 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
static const char V_15 [] = L_3 ;
static const char V_16 [] = L_4 ;
const char * V_17 = NULL ;
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 )
return - V_18 ;
switch ( V_2 -> V_19 ) {
case V_20 :
V_17 = V_15 ;
break;
default:
V_17 = V_16 ;
break;
}
return F_7 ( V_14 , V_21 , L_5 , V_17 ) ;
}
static T_2
F_8 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
char * string = L_6 ;
if ( ! V_2 )
return - V_18 ;
switch ( V_2 -> V_22 ) {
case V_23 :
string = L_7 ;
break;
case V_24 :
string = L_8 ;
break;
case V_25 :
string = L_9 ;
break;
case V_26 :
string = L_10 ;
break;
default:
break;
}
return F_7 ( V_14 , V_21 , L_5 , string ) ;
}
static T_2
F_9 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 || V_2 -> V_7 >= V_27 )
return - V_18 ;
return F_7 ( V_14 , V_21 , L_5 ,
V_8 [ V_2 -> V_7 ] ) ;
}
static T_2
F_10 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_3 V_28 )
{
int V_29 = 0 ;
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 )
return - V_18 ;
if ( F_11 ( V_14 , L_11 ) ) {
V_29 = F_12 ( V_2 , V_14 ) ;
if ( V_29 ) {
F_13 ( V_2 -> V_4 -> V_5 ,
L_12 , V_29 ) ;
V_28 = V_29 ;
}
goto V_30;
}
if ( F_11 ( V_14 , L_13 ) ) {
F_14 ( & V_2 -> V_31 ) ;
goto V_30;
}
if ( F_11 ( V_14 , L_14 ) ) {
F_15 ( V_2 ) ;
goto V_30;
}
if ( F_11 ( V_14 , L_15 ) ) {
F_16 ( V_2 ) ;
goto V_30;
}
V_28 = - V_18 ;
V_30:
return V_28 ;
}
static T_2 F_17 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 || V_2 -> V_3 >= V_32 )
return - V_18 ;
return F_7 ( V_14 , V_21 , L_5 ,
V_6 [ V_2 -> V_3 ] ) ;
}
static T_2
F_18 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
char * V_33 ;
if ( ! V_2 )
return - V_18 ;
V_33 = V_2 -> V_33 ;
if ( V_33 )
return F_7 ( V_14 , V_21 , L_5 , V_33 ) ;
return 0 ;
}
static T_2
F_19 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_3 V_28 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 )
return - V_18 ;
F_20 ( & V_2 -> V_34 ) ;
F_21 ( V_2 -> V_33 ) ;
V_2 -> V_33 = F_22 ( V_28 + 1 , V_35 ) ;
if ( ! V_2 -> V_33 ) {
V_28 = - V_36 ;
goto V_37;
}
strncpy ( V_2 -> V_33 , V_14 , V_28 ) ;
if ( V_2 -> V_33 [ V_28 - 1 ] == '\n' )
V_2 -> V_33 [ V_28 - 1 ] = '\0' ;
else
V_2 -> V_33 [ V_28 ] = '\0' ;
V_37:
F_23 ( & V_2 -> V_34 ) ;
return V_28 ;
}
static T_2
F_24 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
char * V_38 ;
if ( ! V_2 )
return - V_18 ;
V_38 = V_2 -> V_38 ;
if ( V_38 )
return F_7 ( V_14 , V_21 , L_5 , V_38 ) ;
return 0 ;
}
static T_2
F_25 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_3 V_28 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 )
return - V_18 ;
F_20 ( & V_2 -> V_34 ) ;
F_21 ( V_2 -> V_38 ) ;
V_2 -> V_38 = F_22 ( V_28 + 1 , V_35 ) ;
if ( ! V_2 -> V_38 ) {
V_28 = - V_36 ;
goto V_37;
}
strncpy ( V_2 -> V_38 , V_14 , V_28 ) ;
if ( V_2 -> V_38 [ V_28 - 1 ] == '\n' )
V_2 -> V_38 [ V_28 - 1 ] = '\0' ;
else
V_2 -> V_38 [ V_28 ] = '\0' ;
V_37:
F_23 ( & V_2 -> V_34 ) ;
return V_28 ;
}
static T_2
F_26 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
char * V_39 ;
if ( ! V_2 )
return - V_18 ;
V_39 = V_2 -> V_39 ;
if ( V_39 )
return F_7 ( V_14 , V_21 , L_5 , V_39 ) ;
return 0 ;
}
static T_2
F_27 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_3 V_28 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 )
return - V_18 ;
F_20 ( & V_2 -> V_34 ) ;
F_21 ( V_2 -> V_39 ) ;
V_2 -> V_39 = F_22 ( V_28 + 1 , V_35 ) ;
if ( ! V_2 -> V_39 ) {
V_28 = - V_36 ;
goto V_37;
}
strncpy ( V_2 -> V_39 , V_14 , V_28 ) ;
if ( V_2 -> V_39 [ V_28 - 1 ] == '\n' )
V_2 -> V_39 [ V_28 - 1 ] = '\0' ;
else
V_2 -> V_39 [ V_28 ] = '\0' ;
V_37:
F_23 ( & V_2 -> V_34 ) ;
return V_28 ;
}
static T_2
F_28 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
char * V_40 ;
if ( ! V_2 )
return - V_18 ;
V_40 = V_2 -> V_40 ;
if ( V_40 )
return F_7 ( V_14 , V_21 , L_5 , V_40 ) ;
return 0 ;
}
static T_2
F_29 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_3 V_28 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 )
return - V_18 ;
if ( ! F_11 ( V_14 , L_16 ) && ! F_11 ( V_14 , L_17 ) )
return - V_18 ;
F_20 ( & V_2 -> V_34 ) ;
F_21 ( V_2 -> V_40 ) ;
V_2 -> V_40 = F_22 ( V_28 + 1 , V_35 ) ;
if ( ! V_2 -> V_40 ) {
V_28 = - V_36 ;
goto V_37;
}
strncpy ( V_2 -> V_40 , V_14 , V_28 ) ;
if ( V_2 -> V_40 [ V_28 - 1 ] == '\n' )
V_2 -> V_40 [ V_28 - 1 ] = '\0' ;
else
V_2 -> V_40 [ V_28 ] = '\0' ;
V_37:
F_23 ( & V_2 -> V_34 ) ;
return V_28 ;
}
static T_2
F_30 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 )
return - V_18 ;
return F_7 ( V_14 , V_21 , L_18 , V_2 -> V_41 ) ;
}
static T_2
F_31 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_3 V_28 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
int V_42 ;
unsigned long V_43 ;
if ( ! V_2 )
return - V_18 ;
V_42 = F_32 ( V_14 , 16 , & V_43 ) ;
if ( V_42 )
goto exit;
V_2 -> V_41 = ( void * ) V_43 ;
V_42 = V_28 ;
exit:
return V_42 ;
}
static T_2
F_33 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
if ( ! V_2 )
return - V_18 ;
return F_7 ( V_14 , V_21 , L_18 , V_2 -> V_44 ) ;
}
static T_2
F_34 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_3 V_28 )
{
struct V_1 * V_2 = F_6 ( V_11 -> V_5 ) ;
int V_42 ;
unsigned long V_43 ;
if ( ! V_2 )
return - V_18 ;
V_42 = F_32 ( V_14 , 16 , & V_43 ) ;
if ( V_42 )
goto exit;
V_2 -> V_44 = ( int * ) V_43 ;
V_42 = V_28 ;
exit:
return V_42 ;
}
void F_35 ( struct V_1 * V_2 )
{
V_2 -> V_45 = V_46 ;
}
