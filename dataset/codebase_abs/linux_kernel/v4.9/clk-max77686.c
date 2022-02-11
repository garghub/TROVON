static struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_4 ( V_4 -> V_5 , V_4 -> V_6 -> V_7 ,
V_4 -> V_6 -> V_8 ,
V_4 -> V_6 -> V_8 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_4 -> V_5 , V_4 -> V_6 -> V_7 ,
V_4 -> V_6 -> V_8 ,
~ V_4 -> V_6 -> V_8 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_9 ;
T_1 V_10 ;
V_9 = F_7 ( V_4 -> V_5 , V_4 -> V_6 -> V_7 , & V_10 ) ;
if ( V_9 < 0 )
return - V_11 ;
return V_10 & V_4 -> V_6 -> V_8 ;
}
static unsigned long F_8 ( struct V_2 * V_3 ,
unsigned long V_12 )
{
return 32768 ;
}
static struct V_2 *
F_9 ( struct V_13 * V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
unsigned int V_18 = V_14 -> args [ 0 ] ;
if ( V_18 >= V_17 -> V_19 ) {
F_10 ( L_1 , V_20 , V_18 ) ;
return F_11 ( - V_11 ) ;
}
return & V_17 -> V_21 [ V_18 ] . V_3 ;
}
static int F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_24 * V_26 = V_25 -> V_26 ;
const struct V_27 * V_28 = F_13 ( V_23 ) ;
struct V_16 * V_17 ;
const struct V_29 * V_30 ;
struct V_5 * V_5 ;
int V_31 , V_9 , V_19 ;
V_17 = F_14 ( V_25 , sizeof( * V_17 ) , V_32 ) ;
if ( ! V_17 )
return - V_33 ;
V_5 = F_15 ( V_26 , NULL ) ;
if ( ! V_5 ) {
F_16 ( V_25 , L_2 ) ;
return - V_34 ;
}
V_17 -> V_35 = V_28 -> V_36 ;
switch ( V_17 -> V_35 ) {
case V_37 :
V_19 = V_38 ;
V_30 = V_39 ;
break;
case V_40 :
V_19 = V_41 ;
V_30 = V_42 ;
break;
case V_43 :
V_19 = V_44 ;
V_30 = V_45 ;
break;
default:
F_16 ( V_25 , L_3 ) ;
return - V_11 ;
}
V_17 -> V_19 = V_19 ;
V_17 -> V_21 = F_17 ( V_25 , V_19 ,
sizeof( * V_17 -> V_21 ) ,
V_32 ) ;
if ( ! V_17 -> V_21 )
return - V_33 ;
for ( V_31 = 0 ; V_31 < V_19 ; V_31 ++ ) {
struct V_1 * V_21 ;
const char * V_46 ;
V_21 = & V_17 -> V_21 [ V_31 ] ;
V_21 -> V_5 = V_5 ;
V_21 -> V_6 = & V_30 [ V_31 ] ;
V_21 -> V_47 . V_48 = V_30 [ V_31 ] . V_48 ;
V_21 -> V_47 . V_49 = & V_50 ;
if ( V_26 -> V_51 &&
! F_18 ( V_26 -> V_51 ,
L_4 ,
V_31 , & V_46 ) )
V_21 -> V_47 . V_52 = V_46 ;
else
V_21 -> V_47 . V_52 = V_30 [ V_31 ] . V_52 ;
V_21 -> V_3 . V_53 = & V_21 -> V_47 ;
V_9 = F_19 ( V_25 , & V_21 -> V_3 ) ;
if ( V_9 ) {
F_16 ( V_25 , L_5 , V_9 ) ;
return V_9 ;
}
V_9 = F_20 ( & V_21 -> V_3 ,
V_21 -> V_47 . V_52 , NULL ) ;
if ( V_9 < 0 ) {
F_16 ( V_25 , L_6 , V_9 ) ;
return V_9 ;
}
}
if ( V_26 -> V_51 ) {
V_9 = F_21 ( V_26 -> V_51 , F_9 ,
V_17 ) ;
if ( V_9 < 0 ) {
F_16 ( V_25 , L_7 ,
V_9 ) ;
return V_9 ;
}
}
if ( V_17 -> V_35 == V_40 ) {
V_9 = F_4 ( V_5 , V_54 ,
1 << V_55 ,
1 << V_55 ) ;
if ( V_9 < 0 ) {
F_16 ( V_25 , L_8 , V_9 ) ;
goto V_56;
}
}
return 0 ;
V_56:
if ( V_26 -> V_51 )
F_22 ( V_26 -> V_51 ) ;
return V_9 ;
}
static int F_23 ( struct V_22 * V_23 )
{
struct V_24 * V_26 = V_23 -> V_25 . V_26 ;
if ( V_26 -> V_51 )
F_22 ( V_26 -> V_51 ) ;
return 0 ;
}
