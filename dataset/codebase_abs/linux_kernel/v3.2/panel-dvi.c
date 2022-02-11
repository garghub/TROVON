static inline struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( V_3 -> V_7 == V_8 )
return 0 ;
V_6 = F_3 ( V_3 ) ;
if ( V_6 )
goto V_9;
if ( V_5 -> V_10 ) {
V_6 = V_5 -> V_10 ( V_3 ) ;
if ( V_6 )
goto V_11;
}
return 0 ;
V_11:
F_4 ( V_3 ) ;
V_9:
return V_6 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_3 -> V_7 != V_8 )
return;
if ( V_5 -> V_12 )
V_5 -> V_12 ( V_3 ) ;
F_4 ( V_3 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_13 * V_14 ;
V_14 = F_7 ( sizeof( * V_14 ) , V_15 ) ;
if ( ! V_14 )
return - V_16 ;
V_3 -> V_17 . V_18 = V_19 ;
V_3 -> V_17 . V_20 = V_21 ;
V_14 -> V_3 = V_3 ;
F_8 ( & V_14 -> V_22 ) ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
return 0 ;
}
static void T_1 F_10 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
F_12 ( & V_14 -> V_22 ) ;
F_9 ( & V_3 -> V_23 , NULL ) ;
F_13 ( & V_14 -> V_22 ) ;
F_14 ( V_14 ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
int V_6 ;
F_12 ( & V_14 -> V_22 ) ;
V_6 = F_2 ( V_3 ) ;
if ( V_6 == 0 )
V_3 -> V_7 = V_8 ;
F_13 ( & V_14 -> V_22 ) ;
return V_6 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
F_12 ( & V_14 -> V_22 ) ;
F_5 ( V_3 ) ;
V_3 -> V_7 = V_24 ;
F_13 ( & V_14 -> V_22 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
F_12 ( & V_14 -> V_22 ) ;
F_5 ( V_3 ) ;
V_3 -> V_7 = V_25 ;
F_13 ( & V_14 -> V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
int V_6 ;
F_12 ( & V_14 -> V_22 ) ;
V_6 = F_2 ( V_3 ) ;
if ( V_6 == 0 )
V_3 -> V_7 = V_8 ;
F_13 ( & V_14 -> V_22 ) ;
return V_6 ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_26 * V_18 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
F_12 ( & V_14 -> V_22 ) ;
F_20 ( V_3 , V_18 ) ;
F_13 ( & V_14 -> V_22 ) ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_26 * V_18 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
F_12 ( & V_14 -> V_22 ) ;
* V_18 = V_3 -> V_17 . V_18 ;
F_13 ( & V_14 -> V_22 ) ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_26 * V_18 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
int V_6 ;
F_12 ( & V_14 -> V_22 ) ;
V_6 = F_23 ( V_3 , V_18 ) ;
F_13 ( & V_14 -> V_22 ) ;
return V_6 ;
}
static int F_24 ( struct V_27 * V_28 ,
unsigned char * V_29 , T_2 V_30 , T_3 V_31 )
{
int V_6 , V_32 ;
for ( V_32 = 3 ; V_32 > 0 ; V_32 -- ) {
struct V_33 V_34 [] = {
{
. V_35 = V_36 ,
. V_37 = 0 ,
. V_38 = 1 ,
. V_29 = & V_31 ,
} , {
. V_35 = V_36 ,
. V_37 = V_39 ,
. V_38 = V_30 ,
. V_29 = V_29 ,
}
} ;
V_6 = F_25 ( V_28 , V_34 , 2 ) ;
if ( V_6 == 2 )
return 0 ;
if ( V_6 != - V_40 )
break;
}
return V_6 < 0 ? V_6 : - V_41 ;
}
static int F_26 ( struct V_2 * V_3 ,
T_3 * V_42 , int V_38 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_27 * V_28 ;
int V_6 , V_43 , V_44 ;
F_12 ( & V_14 -> V_22 ) ;
if ( V_5 -> V_45 == 0 ) {
V_6 = - V_46 ;
goto V_47;
}
V_28 = F_27 ( V_5 -> V_45 ) ;
if ( ! V_28 ) {
F_28 ( & V_3 -> V_23 , L_1 ,
V_5 -> V_45 ) ;
V_6 = - V_48 ;
goto V_47;
}
V_43 = F_29 ( V_49 , V_38 ) ;
V_6 = F_24 ( V_28 , V_42 , V_43 , 0 ) ;
if ( V_6 )
goto V_47;
V_44 = V_43 ;
if ( V_38 > V_49 && V_42 [ 0x7e ] > 0 ) {
V_43 = F_29 ( V_49 , V_38 - V_49 ) ;
V_6 = F_24 ( V_28 , V_42 + V_49 ,
V_43 , V_49 ) ;
if ( V_6 )
goto V_47;
V_44 += V_43 ;
}
F_13 ( & V_14 -> V_22 ) ;
return V_44 ;
V_47:
F_13 ( & V_14 -> V_22 ) ;
return V_6 ;
}
static bool F_30 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_11 ( & V_3 -> V_23 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_27 * V_28 ;
unsigned char V_50 ;
int V_6 ;
F_12 ( & V_14 -> V_22 ) ;
if ( V_5 -> V_45 == 0 )
goto V_50;
V_28 = F_27 ( V_5 -> V_45 ) ;
if ( ! V_28 )
goto V_50;
V_6 = F_24 ( V_28 , & V_50 , 1 , 0 ) ;
F_13 ( & V_14 -> V_22 ) ;
return V_6 == 0 ;
V_50:
F_13 ( & V_14 -> V_22 ) ;
return true ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_51 ) ;
}
static void T_1 F_33 ( void )
{
F_34 ( & V_51 ) ;
}
