char * F_1 ( T_1 * V_1 )
{
switch ( V_1 -> V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
default:
return L_6 ;
}
}
static T_2 F_2 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
T_1 * V_1 = F_3 ( V_9 ) ;
return sprintf ( V_12 , L_7 , F_1 ( V_1 ) ) ;
}
static T_2 F_4 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
T_1 * V_1 = F_3 ( V_9 ) ;
return sprintf ( V_12 , L_7 , V_1 -> V_13 ) ;
}
static T_2 F_5 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
T_1 * V_1 = F_3 ( V_9 ) ;
return sprintf ( V_12 , L_8 , F_1 ( V_1 ) ) ;
}
static T_2 F_6 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
T_1 * V_1 = F_3 ( V_9 ) ;
return sprintf ( V_12 , L_7 , ( char * ) & V_1 -> V_14 [ V_15 ] ) ;
}
static T_2 F_7 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
T_1 * V_1 = F_3 ( V_9 ) ;
return sprintf ( V_12 , L_7 , ( char * ) & V_1 -> V_14 [ V_16 ] ) ;
}
static T_2 F_8 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
T_1 * V_1 = F_3 ( V_9 ) ;
return sprintf ( V_12 , L_7 , ( char * ) & V_1 -> V_14 [ V_17 ] ) ;
}
static T_2 F_9 ( struct V_8 * V_18 ,
struct V_10 * V_11 ,
const char * V_12 , T_3 V_19 )
{
T_4 * V_20 = F_10 ( V_18 ) ;
if ( strncmp ( V_12 , L_9 , V_19 ) )
return - V_21 ;
F_11 ( V_20 ) ;
return V_19 ;
}
static T_2 F_12 ( struct V_8 * V_18 ,
struct V_10 * V_11 ,
const char * V_12 , T_3 V_19 )
{
T_4 * V_20 = F_10 ( V_18 ) ;
if ( strncmp ( V_12 , L_9 , V_19 ) )
return - V_21 ;
F_11 ( V_20 ) ;
F_13 ( V_20 ) ;
return V_19 ;
}
int F_14 ( T_4 * V_20 )
{
int V_22 , V_23 ( V_24 ) ;
for ( V_22 = 0 ; V_25 [ V_22 ] ; V_22 ++ ) {
V_24 = F_15 ( V_20 -> V_18 , V_25 [ V_22 ] ) ;
if ( V_24 )
break;
}
return V_24 ;
}
