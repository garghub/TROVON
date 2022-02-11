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
V_4 -> V_2 = V_2 ;
F_10 ( & V_4 -> V_17 ) ;
if ( V_2 -> V_18 ) {
struct V_19 * V_20 = V_2 -> V_18 ;
V_4 -> V_10 = V_20 -> V_21 ;
V_11 = V_20 -> V_11 ;
} else {
V_4 -> V_10 = - 1 ;
V_11 = - 1 ;
}
if ( F_4 ( V_4 -> V_10 ) ) {
V_6 = F_11 ( V_4 -> V_10 , V_22 ,
L_1 ) ;
if ( V_6 ) {
F_12 ( & V_2 -> V_5 , L_2 ,
V_4 -> V_10 ) ;
return V_6 ;
}
}
if ( V_11 != - 1 ) {
struct V_23 * V_24 ;
V_24 = F_13 ( V_11 ) ;
if ( ! V_24 ) {
F_12 ( & V_2 -> V_5 , L_3 ,
V_11 ) ;
V_6 = - V_25 ;
goto V_26;
}
V_4 -> V_23 = V_24 ;
}
F_14 ( & V_2 -> V_5 , V_4 ) ;
return 0 ;
V_26:
if ( F_4 ( V_4 -> V_10 ) )
F_15 ( V_4 -> V_10 ) ;
return V_6 ;
}
static void T_1 F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_23 )
F_18 ( V_4 -> V_23 ) ;
if ( F_4 ( V_4 -> V_10 ) )
F_15 ( V_4 -> V_10 ) ;
F_14 ( & V_2 -> V_5 , NULL ) ;
F_19 ( & V_4 -> V_17 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_17 ( & V_4 -> V_17 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == 0 )
V_2 -> V_7 = V_8 ;
F_19 ( & V_4 -> V_17 ) ;
return V_6 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_17 ) ;
F_6 ( V_2 ) ;
V_2 -> V_7 = V_27 ;
F_19 ( & V_4 -> V_17 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_17 ) ;
F_6 ( V_2 ) ;
V_2 -> V_7 = V_28 ;
F_19 ( & V_4 -> V_17 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_17 ( & V_4 -> V_17 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == 0 )
V_2 -> V_7 = V_8 ;
F_19 ( & V_4 -> V_17 ) ;
return V_6 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_29 * V_15 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_17 ) ;
F_25 ( V_2 , V_15 ) ;
F_19 ( & V_4 -> V_17 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_29 * V_15 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( & V_4 -> V_17 ) ;
* V_15 = V_2 -> V_14 . V_15 ;
F_19 ( & V_4 -> V_17 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_29 * V_15 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
F_17 ( & V_4 -> V_17 ) ;
V_6 = F_28 ( V_2 , V_15 ) ;
F_19 ( & V_4 -> V_17 ) ;
return V_6 ;
}
static int F_29 ( struct V_23 * V_24 ,
unsigned char * V_30 , T_2 V_31 , T_3 V_32 )
{
int V_6 , V_33 ;
for ( V_33 = 3 ; V_33 > 0 ; V_33 -- ) {
struct V_34 V_35 [] = {
{
. V_36 = V_37 ,
. V_38 = 0 ,
. V_39 = 1 ,
. V_30 = & V_32 ,
} , {
. V_36 = V_37 ,
. V_38 = V_40 ,
. V_39 = V_31 ,
. V_30 = V_30 ,
}
} ;
V_6 = F_30 ( V_24 , V_35 , 2 ) ;
if ( V_6 == 2 )
return 0 ;
if ( V_6 != - V_41 )
break;
}
return V_6 < 0 ? V_6 : - V_42 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_3 * V_43 , int V_39 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 , V_44 , V_45 ;
F_17 ( & V_4 -> V_17 ) ;
if ( ! V_4 -> V_23 ) {
V_6 = - V_46 ;
goto V_47;
}
V_44 = F_32 ( V_48 , V_39 ) ;
V_6 = F_29 ( V_4 -> V_23 , V_43 , V_44 , 0 ) ;
if ( V_6 )
goto V_47;
V_45 = V_44 ;
if ( V_39 > V_48 && V_43 [ 0x7e ] > 0 ) {
V_44 = F_32 ( V_48 , V_39 - V_48 ) ;
V_6 = F_29 ( V_4 -> V_23 , V_43 + V_48 ,
V_44 , V_48 ) ;
if ( V_6 )
goto V_47;
V_45 += V_44 ;
}
F_19 ( & V_4 -> V_17 ) ;
return V_45 ;
V_47:
F_19 ( & V_4 -> V_17 ) ;
return V_6 ;
}
static bool F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
unsigned char V_49 ;
int V_6 ;
F_17 ( & V_4 -> V_17 ) ;
if ( ! V_4 -> V_23 )
goto V_49;
V_6 = F_29 ( V_4 -> V_23 , & V_49 , 1 , 0 ) ;
F_19 ( & V_4 -> V_17 ) ;
return V_6 == 0 ;
V_49:
F_19 ( & V_4 -> V_17 ) ;
return true ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_50 ) ;
}
static void T_1 F_36 ( void )
{
F_37 ( & V_50 ) ;
}
