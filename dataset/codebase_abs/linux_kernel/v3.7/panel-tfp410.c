static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
if ( V_2 -> V_7 == V_8 )
return 0 ;
F_3 ( V_2 , & V_2 -> V_9 . V_10 ) ;
F_4 ( V_2 , V_2 -> V_11 . V_12 . V_13 ) ;
V_6 = F_5 ( V_2 ) ;
if ( V_6 )
goto V_14;
if ( F_6 ( V_4 -> V_15 ) )
F_7 ( V_4 -> V_15 , 1 ) ;
return 0 ;
V_14:
return V_6 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_7 != V_8 )
return;
if ( F_6 ( V_4 -> V_15 ) )
F_7 ( V_4 -> V_15 , 0 ) ;
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_6 ;
int V_16 ;
V_4 = F_11 ( & V_2 -> V_5 , sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_2 -> V_9 . V_10 = V_19 ;
V_4 -> V_2 = V_2 ;
F_12 ( & V_4 -> V_20 ) ;
if ( V_2 -> V_21 ) {
struct V_22 * V_23 = V_2 -> V_21 ;
V_4 -> V_15 = V_23 -> V_24 ;
V_16 = V_23 -> V_16 ;
} else {
V_4 -> V_15 = - 1 ;
V_16 = - 1 ;
}
if ( F_6 ( V_4 -> V_15 ) ) {
V_6 = F_13 ( & V_2 -> V_5 , V_4 -> V_15 ,
V_25 , L_1 ) ;
if ( V_6 ) {
F_14 ( & V_2 -> V_5 , L_2 ,
V_4 -> V_15 ) ;
return V_6 ;
}
}
if ( V_16 != - 1 ) {
struct V_26 * V_27 ;
V_27 = F_15 ( V_16 ) ;
if ( ! V_27 ) {
F_14 ( & V_2 -> V_5 , L_3 ,
V_16 ) ;
return - V_28 ;
}
V_4 -> V_26 = V_27 ;
}
F_16 ( & V_2 -> V_5 , V_4 ) ;
return 0 ;
}
static void T_1 F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_18 ( & V_4 -> V_20 ) ;
if ( V_4 -> V_26 )
F_19 ( V_4 -> V_26 ) ;
F_16 ( & V_2 -> V_5 , NULL ) ;
F_20 ( & V_4 -> V_20 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_18 ( & V_4 -> V_20 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == 0 )
V_2 -> V_7 = V_8 ;
F_20 ( & V_4 -> V_20 ) ;
return V_6 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_18 ( & V_4 -> V_20 ) ;
F_8 ( V_2 ) ;
V_2 -> V_7 = V_29 ;
F_20 ( & V_4 -> V_20 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_18 ( & V_4 -> V_20 ) ;
F_8 ( V_2 ) ;
V_2 -> V_7 = V_30 ;
F_20 ( & V_4 -> V_20 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_18 ( & V_4 -> V_20 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == 0 )
V_2 -> V_7 = V_8 ;
F_20 ( & V_4 -> V_20 ) ;
return V_6 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_31 * V_10 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_18 ( & V_4 -> V_20 ) ;
F_3 ( V_2 , V_10 ) ;
V_2 -> V_9 . V_10 = * V_10 ;
F_20 ( & V_4 -> V_20 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_31 * V_10 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_18 ( & V_4 -> V_20 ) ;
* V_10 = V_2 -> V_9 . V_10 ;
F_20 ( & V_4 -> V_20 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_31 * V_10 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_18 ( & V_4 -> V_20 ) ;
V_6 = F_28 ( V_2 , V_10 ) ;
F_20 ( & V_4 -> V_20 ) ;
return V_6 ;
}
static int F_29 ( struct V_26 * V_27 ,
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
V_6 = F_30 ( V_27 , V_37 , 2 ) ;
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
F_18 ( & V_4 -> V_20 ) ;
if ( ! V_4 -> V_26 ) {
V_6 = - V_48 ;
goto V_49;
}
V_46 = F_32 ( V_50 , V_41 ) ;
V_6 = F_29 ( V_4 -> V_26 , V_45 , V_46 , 0 ) ;
if ( V_6 )
goto V_49;
V_47 = V_46 ;
if ( V_41 > V_50 && V_45 [ 0x7e ] > 0 ) {
V_46 = F_32 ( V_50 , V_41 - V_50 ) ;
V_6 = F_29 ( V_4 -> V_26 , V_45 + V_50 ,
V_46 , V_50 ) ;
if ( V_6 )
goto V_49;
V_47 += V_46 ;
}
F_20 ( & V_4 -> V_20 ) ;
return V_47 ;
V_49:
F_20 ( & V_4 -> V_20 ) ;
return V_6 ;
}
static bool F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
unsigned char V_51 ;
int V_6 ;
F_18 ( & V_4 -> V_20 ) ;
if ( ! V_4 -> V_26 )
goto V_51;
V_6 = F_29 ( V_4 -> V_26 , & V_51 , 1 , 0 ) ;
F_20 ( & V_4 -> V_20 ) ;
return V_6 == 0 ;
V_51:
F_20 ( & V_4 -> V_20 ) ;
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
