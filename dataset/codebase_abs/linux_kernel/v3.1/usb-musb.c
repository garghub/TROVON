static void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
F_2 ( L_1 , V_5 ) ;
F_2 ( L_2 , V_5 ) ;
break;
case V_6 :
F_2 ( L_3 ,
V_7 ) ;
F_2 ( L_4 ,
V_7 ) ;
F_2 ( L_5 ,
V_7 ) ;
F_2 ( L_6 ,
V_7 ) ;
F_2 ( L_7 ,
V_7 ) ;
F_2 ( L_8 ,
V_7 ) ;
F_2 ( L_9 ,
V_7 ) ;
F_2 ( L_10 ,
V_7 ) ;
F_2 ( L_11 ,
V_7 ) ;
F_2 ( L_12 ,
V_7 ) ;
F_2 ( L_13 ,
V_7 ) ;
F_2 ( L_14 ,
V_7 ) ;
break;
default:
break;
}
}
void T_1 F_3 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 = - 1 ;
const char * V_18 , * V_19 ;
struct V_1 * V_2 ;
if ( V_8 )
V_2 = V_8 ;
else
V_2 = & V_20 ;
V_21 . clock = L_15 ;
V_21 . V_2 = V_2 ;
V_21 . V_22 = V_2 -> V_22 >> 1 ;
V_21 . V_23 = V_2 -> V_23 ;
V_21 . V_24 = V_2 -> V_24 ;
if ( F_4 () || F_5 () ) {
V_18 = L_16 ;
V_19 = L_17 ;
} else {
V_18 = L_18 ;
V_19 = L_19 ;
}
V_10 = F_6 ( V_18 ) ;
if ( ! V_10 ) {
F_7 ( L_20 , V_18 ) ;
return;
}
V_12 = F_8 ( V_19 , V_17 , V_10 , & V_21 ,
sizeof( V_21 ) , V_25 ,
F_9 ( V_25 ) , false ) ;
if ( F_10 ( V_12 ) ) {
F_7 ( L_21 ,
V_19 , V_18 ) ;
return;
}
V_14 = & V_12 -> V_14 ;
V_16 = & V_14 -> V_16 ;
F_11 ( V_16 ) ;
V_16 -> V_26 = & V_27 ;
V_16 -> V_28 = V_27 ;
F_12 ( V_16 ) ;
if ( F_13 () )
F_14 ( V_16 ) ;
}
