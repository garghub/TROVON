static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
if ( V_2 -> V_7 == V_8 )
return 0 ;
V_6 = F_3 ( V_2 ) ;
if ( V_6 )
goto V_9;
if ( F_4 ( V_4 -> V_10 ) )
F_5 ( V_4 -> V_10 , 1 ) ;
return 0 ;
V_9:
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_7 != V_8 )
return;
if ( F_4 ( V_4 -> V_10 ) )
F_5 ( V_4 -> V_10 , 0 ) ;
F_7 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_6 ;
int V_11 ;
V_4 = F_9 ( & V_2 -> V_5 , sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_2 -> V_14 . V_15 = V_16 ;
V_2 -> V_14 . V_17 = V_18 ;
V_4 -> V_2 = V_2 ;
F_10 ( & V_4 -> V_19 ) ;
if ( V_2 -> V_20 ) {
struct V_21 * V_22 = V_2 -> V_20 ;
V_4 -> V_10 = V_22 -> V_23 ;
V_11 = V_22 -> V_11 ;
} else {
V_4 -> V_10 = - 1 ;
V_11 = - 1 ;
}
if ( F_4 ( V_4 -> V_10 ) ) {
V_6 = F_11 ( V_4 -> V_10 , V_24 ,
L_1 ) ;
if ( V_6 ) {
F_12 ( & V_2 -> V_5 , L_2 ,
V_4 -> V_10 ) ;
return V_6 ;
}
}
if ( V_11 != - 1 ) {
struct V_25 * V_26 ;
V_26 = F_13 ( V_11 ) ;
if ( ! V_26 ) {
F_12 ( & V_2 -> V_5 , L_3 ,
V_11 ) ;
V_6 = - V_27 ;
goto V_28;
}
V_4 -> V_25 = V_26 ;
}
F_14 ( & V_2 -> V_5 , V_4 ) ;
return 0 ;
V_28:
if ( F_4 ( V_4 -> V_10 ) )
F_15 ( V_4 -> V_10 ) ;
return V_6 ;
}
static void T_1 F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_19 ) ;
if ( V_4 -> V_25 )
F_18 ( V_4 -> V_25 ) ;
if ( F_4 ( V_4 -> V_10 ) )
F_15 ( V_4 -> V_10 ) ;
F_14 ( & V_2 -> V_5 , NULL ) ;
F_19 ( & V_4 -> V_19 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_17 ( & V_4 -> V_19 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == 0 )
V_2 -> V_7 = V_8 ;
F_19 ( & V_4 -> V_19 ) ;
return V_6 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_19 ) ;
F_6 ( V_2 ) ;
V_2 -> V_7 = V_29 ;
F_19 ( & V_4 -> V_19 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_19 ) ;
F_6 ( V_2 ) ;
V_2 -> V_7 = V_30 ;
F_19 ( & V_4 -> V_19 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_17 ( & V_4 -> V_19 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == 0 )
V_2 -> V_7 = V_8 ;
F_19 ( & V_4 -> V_19 ) ;
return V_6 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_31 * V_15 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_19 ) ;
F_25 ( V_2 , V_15 ) ;
F_19 ( & V_4 -> V_19 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_31 * V_15 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_19 ) ;
* V_15 = V_2 -> V_14 . V_15 ;
F_19 ( & V_4 -> V_19 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_31 * V_15 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_17 ( & V_4 -> V_19 ) ;
V_6 = F_28 ( V_2 , V_15 ) ;
F_19 ( & V_4 -> V_19 ) ;
return V_6 ;
}
static int F_29 ( struct V_25 * V_26 ,
unsigned char * V_32 , T_2 V_33 , T_3 V_34 )
{
int V_6 , V_35 ;
for ( V_35 = 3 ; V_35 > 0 ; V_35 -- ) {
struct V_36 V_37 [] = {
{
. V_38 = V_39 ,
. V_40 = 0 ,
. V_41 = 1 ,
. V_32 = & V_34 ,
} , {
. V_38 = V_39 ,
. V_40 = V_42 ,
. V_41 = V_33 ,
. V_32 = V_32 ,
}
} ;
V_6 = F_30 ( V_26 , V_37 , 2 ) ;
if ( V_6 == 2 )
return 0 ;
if ( V_6 != - V_43 )
break;
}
return V_6 < 0 ? V_6 : - V_44 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_3 * V_45 , int V_41 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 , V_46 , V_47 ;
F_17 ( & V_4 -> V_19 ) ;
if ( ! V_4 -> V_25 ) {
V_6 = - V_48 ;
goto V_49;
}
V_46 = F_32 ( V_50 , V_41 ) ;
V_6 = F_29 ( V_4 -> V_25 , V_45 , V_46 , 0 ) ;
if ( V_6 )
goto V_49;
V_47 = V_46 ;
if ( V_41 > V_50 && V_45 [ 0x7e ] > 0 ) {
V_46 = F_32 ( V_50 , V_41 - V_50 ) ;
V_6 = F_29 ( V_4 -> V_25 , V_45 + V_50 ,
V_46 , V_50 ) ;
if ( V_6 )
goto V_49;
V_47 += V_46 ;
}
F_19 ( & V_4 -> V_19 ) ;
return V_47 ;
V_49:
F_19 ( & V_4 -> V_19 ) ;
return V_6 ;
}
static bool F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
unsigned char V_51 ;
int V_6 ;
F_17 ( & V_4 -> V_19 ) ;
if ( ! V_4 -> V_25 )
goto V_51;
V_6 = F_29 ( V_4 -> V_25 , & V_51 , 1 , 0 ) ;
F_19 ( & V_4 -> V_19 ) ;
return V_6 == 0 ;
V_51:
F_19 ( & V_4 -> V_19 ) ;
return true ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_52 ) ;
}
static void T_1 F_36 ( void )
{
F_37 ( & V_52 ) ;
}
