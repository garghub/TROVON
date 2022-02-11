int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 , T_1 * V_5 ,
T_2 V_6 , int V_7 )
{
int V_8 , V_9 = - V_10 ;
if ( ! V_2 || V_3 == NULL || V_4 == 0 )
return - V_11 ;
if ( V_2 -> V_12 . V_13 == 0 ) {
F_2 ( L_1 ) ;
return - V_11 ;
}
if ( ( V_9 = F_3 ( & V_2 -> V_14 ) ) )
return V_9 ;
F_4 ( L_2 ) ;
F_5 ( V_3 , V_4 , F_4 ) ;
V_9 = F_6 ( V_2 -> V_15 , F_7 ( V_2 -> V_15 ,
V_2 -> V_12 . V_13 ) , V_3 , V_4 , & V_8 ,
2000 ) ;
if ( V_9 )
F_2 ( L_3 , V_9 , V_4 , V_8 ) ;
else
V_9 = V_8 != V_4 ? - 1 : 0 ;
if ( ! V_9 && V_5 && V_6 ) {
if ( V_7 )
F_8 ( V_7 ) ;
V_9 = F_6 ( V_2 -> V_15 , F_9 ( V_2 -> V_15 ,
V_2 -> V_12 . V_16 ?
V_2 -> V_12 . V_16 :
V_2 -> V_12 . V_13 ) , V_5 , V_6 , & V_8 ,
2000 ) ;
if ( V_9 )
F_2 ( L_4 , V_9 ) ;
else {
F_4 ( L_5 ) ;
F_5 ( V_5 , V_8 , F_4 ) ;
}
}
F_10 ( & V_2 -> V_14 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 , T_1 * V_17 , T_2 V_18 )
{
return F_1 ( V_2 , V_17 , V_18 , NULL , 0 , 0 ) ;
}
static void F_12 ( struct V_19 * V_20 , T_1 * V_21 , T_3 V_22 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
if ( V_24 -> V_26 > 0 && V_24 -> V_27 & V_28 )
F_13 ( & V_24 -> V_29 , V_21 , V_22 ) ;
}
static void F_14 ( struct V_19 * V_20 , T_1 * V_21 , T_3 V_22 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
if ( V_24 -> V_26 > 0 && V_24 -> V_27 & V_28 )
F_15 ( & V_24 -> V_29 , V_21 , V_22 ) ;
}
int F_16 ( struct V_23 * V_24 )
{
V_24 -> V_20 . V_15 = V_24 -> V_30 -> V_15 ;
if ( V_24 -> V_12 . V_31 & V_32 )
V_24 -> V_20 . V_33 = F_14 ;
else
V_24 -> V_20 . V_33 = F_12 ;
V_24 -> V_20 . V_25 = V_24 ;
return F_17 ( & V_24 -> V_20 , & V_24 -> V_12 . V_20 ) ;
}
int F_18 ( struct V_23 * V_24 )
{
return F_19 ( & V_24 -> V_20 ) ;
}
