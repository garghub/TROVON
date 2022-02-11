static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( F_3 ( V_2 ) )
return 0 ;
V_6 = V_5 -> V_7 . V_8 -> V_9 ( V_5 , V_2 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_3 ( V_2 ) )
return;
V_5 -> V_7 . V_8 -> V_10 ( V_5 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( ! F_3 ( V_2 ) )
return - V_11 ;
if ( F_6 ( V_2 ) )
return 0 ;
V_5 -> V_7 . V_8 -> V_12 ( V_5 , & V_4 -> V_13 ) ;
V_6 = V_5 -> V_7 . V_8 -> V_14 ( V_5 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_15 = V_16 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_6 ( V_2 ) )
return;
V_5 -> V_7 . V_8 -> V_17 ( V_5 ) ;
V_2 -> V_15 = V_18 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_19 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_4 -> V_13 = * V_13 ;
V_2 -> V_20 . V_13 = * V_13 ;
V_5 -> V_7 . V_8 -> V_12 ( V_5 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_19 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_13 = V_4 -> V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_19 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_7 . V_8 -> V_21 ( V_5 , V_13 ) ;
}
static int F_11 ( struct V_22 * V_23 ,
unsigned char * V_24 , T_1 V_25 , T_2 V_26 )
{
int V_6 , V_27 ;
for ( V_27 = 3 ; V_27 > 0 ; V_27 -- ) {
struct V_28 V_29 [] = {
{
. V_30 = V_31 ,
. V_32 = 0 ,
. V_33 = 1 ,
. V_24 = & V_26 ,
} , {
. V_30 = V_31 ,
. V_32 = V_34 ,
. V_33 = V_25 ,
. V_24 = V_24 ,
}
} ;
V_6 = F_12 ( V_23 , V_29 , 2 ) ;
if ( V_6 == 2 )
return 0 ;
if ( V_6 != - V_35 )
break;
}
return V_6 < 0 ? V_6 : - V_36 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_2 * V_37 , int V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 , V_38 , V_39 ;
if ( ! V_4 -> V_22 )
return - V_11 ;
V_38 = F_14 ( V_40 , V_33 ) ;
V_6 = F_11 ( V_4 -> V_22 , V_37 , V_38 , 0 ) ;
if ( V_6 )
return V_6 ;
V_39 = V_38 ;
if ( V_33 > V_40 && V_37 [ 0x7e ] > 0 ) {
V_38 = F_14 ( V_40 , V_33 - V_40 ) ;
V_6 = F_11 ( V_4 -> V_22 , V_37 + V_40 ,
V_38 , V_40 ) ;
if ( V_6 )
return V_6 ;
V_39 += V_38 ;
}
return V_39 ;
}
static bool F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char V_41 ;
int V_6 ;
if ( ! V_4 -> V_22 )
return true ;
V_6 = F_11 ( V_4 -> V_22 , & V_41 , 1 , 0 ) ;
return V_6 == 0 ;
}
static int F_16 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_17 ( V_43 ) ;
struct V_44 * V_45 ;
struct V_1 * V_5 , * V_2 ;
int V_46 ;
V_45 = F_18 ( & V_43 -> V_47 ) ;
V_46 = V_45 -> V_46 ;
if ( V_46 != - 1 ) {
struct V_22 * V_23 ;
V_23 = F_19 ( V_46 ) ;
if ( ! V_23 ) {
F_20 ( & V_43 -> V_47 ,
L_1 ,
V_46 ) ;
return - V_48 ;
}
V_4 -> V_22 = V_23 ;
}
V_5 = F_21 ( V_45 -> V_49 ) ;
if ( V_5 == NULL ) {
F_20 ( & V_43 -> V_47 , L_2 ) ;
return - V_11 ;
}
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_50 = V_45 -> V_50 ;
return 0 ;
}
static int F_22 ( struct V_42 * V_43 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
V_4 = F_23 ( & V_43 -> V_47 , sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return - V_52 ;
F_24 ( V_43 , V_4 ) ;
if ( F_18 ( & V_43 -> V_47 ) ) {
V_6 = F_16 ( V_43 ) ;
if ( V_6 )
return V_6 ;
} else {
return - V_11 ;
}
V_4 -> V_13 = V_53 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_54 = & V_55 ;
V_2 -> V_47 = & V_43 -> V_47 ;
V_2 -> type = V_56 ;
V_2 -> V_57 = V_58 ;
V_2 -> V_20 . V_13 = V_53 ;
V_6 = F_25 ( V_2 ) ;
if ( V_6 ) {
F_20 ( & V_43 -> V_47 , L_3 ) ;
goto V_59;
}
return 0 ;
V_59:
F_26 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_3 F_27 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_17 ( V_43 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_28 ( & V_4 -> V_2 ) ;
F_7 ( V_2 ) ;
F_4 ( V_2 ) ;
F_26 ( V_5 ) ;
if ( V_4 -> V_22 )
F_29 ( V_4 -> V_22 ) ;
return 0 ;
}
