int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_7 )
return - V_8 ;
if ( ! V_5 -> V_7 -> V_9 ) {
F_2 ( V_2 -> V_10 ,
L_1 ) ;
return 0 ;
}
F_3 ( V_2 -> V_10 , L_2 ,
V_3 ? L_3 : L_4 ) ;
V_5 -> V_7 -> V_9 ( V_5 -> V_10 , V_3 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_7 )
return - V_8 ;
F_3 ( V_2 -> V_10 , L_5 ,
V_3 ? L_3 : L_4 ) ;
if ( V_3 ) {
if ( ! V_2 -> V_11 ++ ) {
V_5 -> V_7 -> V_12 ( V_5 -> V_10 ) ;
F_1 ( V_2 , true ) ;
F_1 ( V_2 , false ) ;
}
} else {
F_5 ( ! V_2 -> V_11 ) ;
if ( ! -- V_2 -> V_11 )
V_5 -> V_7 -> V_13 ( V_5 -> V_10 ) ;
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_15 = F_7 ( V_2 -> V_10 ) ;
int V_16 ;
unsigned int V_17 , V_18 ;
if ( ! V_5 || ! V_5 -> V_7 || ! V_5 -> V_7 -> V_19 )
return;
if ( ! F_8 ( V_15 ) )
return;
V_16 = V_5 -> V_7 -> V_19 ( V_5 -> V_10 ) ;
switch ( V_16 ) {
case 337500 :
V_17 = 16 ;
V_18 = 225 ;
break;
case 450000 :
default:
V_17 = 4 ;
V_18 = 75 ;
break;
case 540000 :
V_17 = 4 ;
V_18 = 90 ;
break;
case 675000 :
V_17 = 8 ;
V_18 = 225 ;
break;
}
F_9 ( V_2 , V_20 , V_17 ) ;
F_9 ( V_2 , V_21 , V_18 ) ;
}
static int F_10 ( T_1 V_22 )
{
if ( F_5 ( V_22 < 5 || V_22 > 7 ) )
return - 1 ;
return V_22 - 4 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_23 , int V_24 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_25 ;
if ( ! V_5 || ! V_5 -> V_7 || ! V_5 -> V_7 -> V_26 )
return - V_8 ;
V_25 = F_10 ( V_23 ) ;
if ( V_25 < 0 )
return - V_27 ;
return V_5 -> V_7 -> V_26 ( V_5 -> V_10 , V_25 , V_24 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_23 ,
bool * V_28 , char * V_29 , int V_30 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_25 ;
if ( ! V_5 || ! V_5 -> V_7 || ! V_5 -> V_7 -> V_31 )
return - V_8 ;
V_25 = F_10 ( V_23 ) ;
if ( V_25 < 0 )
return - V_27 ;
return V_5 -> V_7 -> V_31 ( V_5 -> V_10 , V_25 , V_28 ,
V_29 , V_30 ) ;
}
static int F_13 ( struct V_32 * V_10 )
{
struct V_4 * V_5 = V_33 ;
int V_34 ;
V_34 = F_14 ( V_10 , V_5 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( F_5 ( ! ( V_5 -> V_10 && V_5 -> V_7 && V_5 -> V_7 -> V_12 &&
V_5 -> V_7 -> V_13 && V_5 -> V_7 -> V_19 ) ) ) {
V_34 = - V_27 ;
goto V_35;
}
if ( ! F_15 ( V_5 -> V_7 -> V_36 ) ) {
V_34 = - V_8 ;
goto V_35;
}
return 0 ;
V_35:
F_16 ( V_10 , V_5 ) ;
return V_34 ;
}
static void F_17 ( struct V_32 * V_10 )
{
struct V_4 * V_5 = V_33 ;
F_18 ( V_5 -> V_7 -> V_36 ) ;
F_16 ( V_10 , V_5 ) ;
F_5 ( V_5 -> V_7 || V_5 -> V_10 ) ;
}
static int F_19 ( struct V_32 * V_10 , void * V_37 )
{
return ! strcmp ( V_10 -> V_38 -> V_39 , L_6 ) ;
}
int F_20 ( const struct V_40 * V_41 )
{
if ( F_5 ( ! V_33 ) )
return - V_8 ;
V_33 -> V_42 = V_41 ;
return 0 ;
}
static bool F_21 ( void )
{
static struct V_43 V_44 [] = {
{ F_22 ( V_45 , V_46 ) ,
. V_47 = V_48 << 16 ,
. V_49 = 0xff << 16 } ,
{}
} ;
return F_23 ( V_44 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = NULL ;
struct V_32 * V_10 = V_2 -> V_10 ;
struct V_4 * V_5 ;
int V_34 ;
if ( ! F_21 () )
return - V_8 ;
V_5 = F_25 ( sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return - V_53 ;
V_2 -> V_6 = V_5 ;
V_33 = V_5 ;
F_26 ( V_10 , & V_51 , F_19 , V_2 ) ;
V_34 = F_27 ( V_10 , & V_54 ,
V_51 ) ;
if ( V_34 < 0 )
goto V_55;
F_28 ( L_6 ) ;
if ( ! V_5 -> V_7 ) {
V_34 = - V_8 ;
goto V_56;
}
F_3 ( V_10 , L_7 ) ;
return 0 ;
V_56:
F_29 ( V_10 , & V_54 ) ;
V_55:
F_30 ( V_5 ) ;
V_2 -> V_6 = NULL ;
F_31 ( V_10 , L_8 , V_34 ) ;
return V_34 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_32 * V_10 = V_2 -> V_10 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return 0 ;
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_11 > 0 && V_5 -> V_7 )
V_5 -> V_7 -> V_13 ( V_5 -> V_10 ) ;
F_29 ( V_10 , & V_54 ) ;
F_30 ( V_5 ) ;
V_2 -> V_6 = NULL ;
return 0 ;
}
