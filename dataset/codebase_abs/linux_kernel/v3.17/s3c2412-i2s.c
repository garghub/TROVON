static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 , V_4 ) ;
F_3 ( V_2 , & V_5 ,
& V_6 ) ;
V_3 = F_4 ( V_2 , & V_7 , V_8 ) ;
if ( V_3 )
return V_3 ;
V_7 . V_9 = & V_6 ;
V_7 . V_10 = & V_5 ;
V_7 . V_11 = F_5 ( V_2 -> V_12 , L_2 ) ;
if ( F_6 ( V_7 . V_11 ) ) {
F_7 ( L_3 ) ;
return F_8 ( V_7 . V_11 ) ;
}
F_9 ( V_7 . V_11 , F_10 ( NULL , L_4 ) ) ;
F_11 ( V_7 . V_11 ) ;
V_7 . V_11 = V_7 . V_13 ;
F_12 ( F_13 ( 0 ) , 5 , F_14 ( 2 ) ,
V_14 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_16 ( V_7 . V_11 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 )
{
struct V_20 * V_21 = F_18 ( V_19 ) ;
T_1 V_22 ;
F_2 ( L_1 , V_4 ) ;
V_22 = F_19 ( V_21 -> V_23 + V_24 ) ;
F_2 ( L_5 , V_4 , V_22 ) ;
switch ( F_20 ( V_18 ) ) {
case 8 :
V_22 |= V_25 ;
break;
case 16 :
V_22 &= ~ V_25 ;
break;
}
F_21 ( V_22 , V_21 -> V_23 + V_24 ) ;
F_2 ( L_6 , V_4 , V_22 ) ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 )
{
int V_3 = 0 ;
struct V_28 * V_29 ;
V_29 = F_23 ( V_27 , V_30 , 0 ) ;
V_7 . V_23 = F_24 ( & V_27 -> V_12 , V_29 ) ;
if ( F_6 ( V_7 . V_23 ) )
return F_8 ( V_7 . V_23 ) ;
V_5 . V_31 = V_29 -> V_32 + V_33 ;
V_6 . V_31 = V_29 -> V_32 + V_34 ;
V_3 = F_25 ( & V_27 -> V_12 , - 1 ,
& V_35 ,
& V_36 ) ;
if ( V_3 ) {
F_7 ( L_7 ) ;
return V_3 ;
}
V_3 = F_26 ( & V_27 -> V_12 ) ;
if ( V_3 )
F_7 ( L_8 , V_3 ) ;
return V_3 ;
}
