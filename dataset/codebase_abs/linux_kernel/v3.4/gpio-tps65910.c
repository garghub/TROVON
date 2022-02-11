static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
T_1 V_6 ;
V_4 -> V_7 ( V_4 , V_8 + V_3 , 1 , & V_6 ) ;
if ( V_6 & V_9 )
return 1 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 ,
int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
if ( V_10 )
F_4 ( V_4 , V_8 + V_3 ,
V_11 ) ;
else
F_5 ( V_4 , V_8 + V_3 ,
V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 ,
int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
F_3 ( V_2 , V_3 , V_10 ) ;
return F_4 ( V_4 , V_8 + V_3 ,
V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
return F_5 ( V_4 , V_8 + V_3 ,
V_12 ) ;
}
void F_8 ( struct V_4 * V_4 , int V_13 )
{
int V_14 ;
struct V_15 * V_16 ;
if ( ! V_13 )
return;
V_4 -> V_5 . V_17 = V_18 ;
V_4 -> V_5 . V_19 = V_4 -> V_20 -> V_21 ;
V_4 -> V_5 . V_22 = V_4 -> V_22 ;
V_4 -> V_5 . V_23 = V_13 ;
switch( F_9 ( V_4 ) ) {
case V_24 :
V_4 -> V_5 . V_25 = V_26 ;
break;
case V_27 :
V_4 -> V_5 . V_25 = V_28 ;
break;
default:
return;
}
V_4 -> V_5 . V_29 = 1 ;
V_4 -> V_5 . V_30 = F_7 ;
V_4 -> V_5 . V_31 = F_6 ;
V_4 -> V_5 . V_32 = F_3 ;
V_4 -> V_5 . V_33 = F_1 ;
V_16 = F_10 ( V_4 -> V_22 ) ;
if ( V_16 ) {
int V_34 ;
for ( V_34 = 0 ; V_34 < V_4 -> V_5 . V_25 ; ++ V_34 ) {
if ( V_16 -> V_35 [ V_34 ] ) {
V_14 = F_4 ( V_4 ,
V_8 + V_34 , V_36 ) ;
if ( V_14 < 0 )
F_11 ( V_4 -> V_22 ,
L_1 ) ;
}
}
}
V_14 = F_12 ( & V_4 -> V_5 ) ;
if ( V_14 )
F_11 ( V_4 -> V_22 , L_2 , V_14 ) ;
}
