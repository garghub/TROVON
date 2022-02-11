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
static int F_10 ( struct V_22 * V_23 , T_1 V_24 )
{
int V_25 ;
switch ( V_23 -> V_26 ) {
case 0x80860054 :
case 0x80862804 :
case 0x80862882 :
V_25 = 3 ;
break;
default:
V_25 = 4 ;
break;
}
if ( F_5 ( V_24 <= V_25 || V_24 > V_25 + 3 ) )
return - 1 ;
return V_24 - V_25 ;
}
int F_11 ( struct V_22 * V_23 , T_1 V_27 , int V_28 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_29 ;
if ( ! V_5 || ! V_5 -> V_7 || ! V_5 -> V_7 -> V_30 )
return - V_8 ;
V_29 = F_10 ( V_23 , V_27 ) ;
if ( V_29 < 0 )
return - V_31 ;
return V_5 -> V_7 -> V_30 ( V_5 -> V_10 , V_29 , V_28 ) ;
}
int F_12 ( struct V_22 * V_23 , T_1 V_27 ,
bool * V_32 , char * V_33 , int V_34 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_29 ;
if ( ! V_5 || ! V_5 -> V_7 || ! V_5 -> V_7 -> V_35 )
return - V_8 ;
V_29 = F_10 ( V_23 , V_27 ) ;
if ( V_29 < 0 )
return - V_31 ;
return V_5 -> V_7 -> V_35 ( V_5 -> V_10 , V_29 , V_32 ,
V_33 , V_34 ) ;
}
static int F_13 ( struct V_36 * V_10 )
{
struct V_4 * V_5 = V_37 ;
int V_38 ;
V_38 = F_14 ( V_10 , V_5 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( F_5 ( ! ( V_5 -> V_10 && V_5 -> V_7 && V_5 -> V_7 -> V_12 &&
V_5 -> V_7 -> V_13 && V_5 -> V_7 -> V_19 ) ) ) {
V_38 = - V_31 ;
goto V_39;
}
if ( ! F_15 ( V_5 -> V_7 -> V_40 ) ) {
V_38 = - V_8 ;
goto V_39;
}
return 0 ;
V_39:
F_16 ( V_10 , V_5 ) ;
return V_38 ;
}
static void F_17 ( struct V_36 * V_10 )
{
struct V_4 * V_5 = V_37 ;
F_18 ( V_5 -> V_7 -> V_40 ) ;
F_16 ( V_10 , V_5 ) ;
F_5 ( V_5 -> V_7 || V_5 -> V_10 ) ;
}
static int F_19 ( struct V_36 * V_10 , void * V_41 )
{
return ! strcmp ( V_10 -> V_42 -> V_43 , L_6 ) ;
}
int F_20 ( const struct V_44 * V_45 )
{
if ( F_5 ( ! V_37 ) )
return - V_8 ;
V_37 -> V_46 = V_45 ;
return 0 ;
}
static bool F_21 ( void )
{
static struct V_47 V_48 [] = {
{ F_22 ( V_49 , V_50 ) ,
. V_51 = V_52 << 16 ,
. V_53 = 0xff << 16 } ,
{}
} ;
return F_23 ( V_48 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = NULL ;
struct V_36 * V_10 = V_2 -> V_10 ;
struct V_4 * V_5 ;
int V_38 ;
if ( F_5 ( V_37 ) )
return - V_56 ;
if ( ! F_21 () )
return - V_8 ;
V_5 = F_25 ( sizeof( * V_5 ) , V_57 ) ;
if ( ! V_5 )
return - V_58 ;
V_2 -> V_6 = V_5 ;
V_37 = V_5 ;
F_26 ( V_10 , & V_55 , F_19 , V_2 ) ;
V_38 = F_27 ( V_10 , & V_59 ,
V_55 ) ;
if ( V_38 < 0 )
goto V_60;
F_28 ( L_6 ) ;
if ( ! V_5 -> V_7 ) {
V_38 = - V_8 ;
goto V_61;
}
F_3 ( V_10 , L_7 ) ;
return 0 ;
V_61:
F_29 ( V_10 , & V_59 ) ;
V_60:
F_30 ( V_5 ) ;
V_2 -> V_6 = NULL ;
V_37 = NULL ;
F_31 ( V_10 , L_8 , V_38 ) ;
return V_38 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_36 * V_10 = V_2 -> V_10 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return 0 ;
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_11 > 0 && V_5 -> V_7 )
V_5 -> V_7 -> V_13 ( V_5 -> V_10 ) ;
F_29 ( V_10 , & V_59 ) ;
F_30 ( V_5 ) ;
V_2 -> V_6 = NULL ;
V_37 = NULL ;
return 0 ;
}
