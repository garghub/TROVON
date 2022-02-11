const char * F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return L_1 ;
case V_5 :
return L_2 ;
case V_6 :
return L_3 ;
case V_7 :
return L_4 ;
case V_8 :
return L_5 ;
case V_9 :
return L_6 ;
default:
return L_7 ;
}
}
static void F_2 ( struct V_10 * V_10 )
{
F_3 ( L_8 ) ;
F_4 ( V_10 ) ;
F_5 ( V_10 ) ;
}
static int F_6 ( struct V_10 * V_10 ,
struct V_11 * V_12 ,
T_1 V_13 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = F_7 ( V_10 ) ;
F_3 ( L_8 ) ;
if ( V_12 == V_17 -> V_19 ) {
V_2 -> V_20 = V_13 ;
return 0 ;
}
return - V_21 ;
}
static void F_8 ( struct V_10 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = F_7 ( V_10 ) ;
struct V_11 * V_22 ;
V_22 = V_17 -> V_19 ;
if ( ! V_22 ) {
V_22 = F_9 ( V_15 , 0 , L_9 , 1 ,
V_23 ) ;
if ( ! V_22 )
return;
V_17 -> V_19 = V_22 ;
}
F_10 ( & V_10 -> V_24 , V_22 , V_2 -> V_20 ) ;
}
void F_11 ( struct V_1 * V_2 ,
enum V_25 type )
{
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < F_12 ( V_27 ) ; V_26 ++ )
if ( V_27 [ V_26 ] == V_2 -> V_3 )
break;
V_2 -> V_20 = V_26 + 1 ;
if ( type == V_28 )
F_8 ( & V_2 -> V_10 ) ;
F_3 ( L_10 ,
V_2 -> V_10 . V_24 . V_29 ,
F_1 ( V_2 ) , V_2 -> V_20 ) ;
}
