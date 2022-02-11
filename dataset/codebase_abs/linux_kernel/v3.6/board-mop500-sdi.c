static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_4 -> V_5 ) {
case V_6 :
case V_7 :
F_2 ( V_8 , 0 ) ;
F_2 ( V_9 , 1 ) ;
break;
case V_10 :
F_2 ( V_8 , 0 ) ;
F_2 ( V_9 , 0 ) ;
break;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_11 )
{
int V_12 ;
V_12 = F_4 ( V_9 , L_1 ) ;
if ( ! V_12 )
V_12 = F_4 ( V_8 ,
L_2 ) ;
if ( V_12 ) {
F_5 ( L_3 ) ;
return;
}
F_2 ( V_8 , 0 ) ;
F_2 ( V_9 , 1 ) ;
F_6 ( V_11 , & V_13 , V_14 ) ;
}
void F_7 ( struct V_1 * V_11 )
{
V_13 . V_15 = V_16 ;
V_9 = V_17 ;
V_8 = V_18 ;
F_3 ( V_11 ) ;
}
void T_1 F_8 ( struct V_1 * V_11 )
{
F_9 ( V_11 , & V_19 , V_14 ) ;
F_10 ( V_11 , & V_20 , V_14 ) ;
}
void T_1 F_11 ( struct V_1 * V_11 )
{
V_13 . V_21 &= ~ V_22 ;
F_10 ( V_11 , & V_20 , V_14 ) ;
V_13 . V_15 = V_23 ;
V_13 . V_24 = true ;
V_9 = V_25 ;
V_8 = V_26 ;
F_3 ( V_11 ) ;
}
void T_1 F_12 ( struct V_1 * V_11 )
{
F_9 ( V_11 , & V_19 , V_14 ) ;
F_10 ( V_11 , & V_20 , V_14 ) ;
V_13 . V_15 = V_27 ;
V_9 = V_28 ;
V_8 = V_29 ;
F_3 ( V_11 ) ;
F_13 ( V_11 , & V_30 , V_14 ) ;
}
