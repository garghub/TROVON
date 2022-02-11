static inline T_1 F_1 ( void T_2 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_1 ) ;
return V_2 >> 28 ;
}
static int F_3 ( struct V_3 * V_4 ,
T_3 V_5 ,
void T_2 * V_6 )
{
return 0 ;
}
static int F_4 ( struct V_3 * V_4 ,
T_3 V_5 ,
void T_2 * V_6 )
{
struct V_7 T_2 * V_8 =
(struct V_7 T_2 * ) V_6 ;
struct V_9 * V_10 ;
T_4 V_11 ;
T_4 V_12 ;
int V_13 ;
T_5 V_14 ;
T_5 V_15 ;
V_10 = F_5 ( V_4 ) ;
if ( ! V_10 )
return - V_16 ;
V_14 = F_2 ( & V_8 -> V_14 ) ;
V_15 = F_2 ( & V_8 -> V_15 ) ;
V_11 = F_2 ( & V_8 -> V_11 ) ;
V_12 = F_2 ( & V_8 -> V_12 ) ;
V_10 -> V_17 = F_6 ( V_14 ) ;
V_10 -> V_18 = F_7 ( V_14 ) ;
V_10 -> V_19 = F_8 ( V_14 ) ;
V_10 -> V_20 = F_9 ( V_15 ) ;
V_10 -> V_21 = F_10 ( V_15 ) ;
V_10 -> V_22 = F_11 ( V_15 ) ;
F_12 ( L_1 , V_10 -> V_17 ) ;
V_10 -> V_23 . V_24 = F_13 ( V_14 ) ;
V_10 -> V_23 . V_25 = F_13 ( V_14 ) ;
V_10 -> V_23 . V_26 = V_27 ;
V_10 -> V_28 . V_24 = V_5 + V_11 ;
V_10 -> V_28 . V_25 = V_10 -> V_28 . V_24 + V_12 - 1 ;
V_10 -> V_28 . V_26 = V_29 ;
V_10 -> V_30 = false ;
V_13 = F_14 ( V_4 , V_10 ) ;
if ( V_13 < 0 )
goto V_31;
return 0 ;
V_31:
F_15 ( V_10 ) ;
return V_13 ;
}
int F_16 ( struct V_3 * V_4 , T_3 V_5 ,
void T_2 * V_6 )
{
char T_2 * V_1 = V_6 ;
struct V_32 * V_33 ;
T_1 V_2 ;
int V_34 = 0 ;
int V_13 = 0 ;
T_4 V_35 ;
V_35 = sizeof( struct V_32 ) ;
V_33 = F_17 ( V_35 , V_36 ) ;
if ( ! V_33 )
return - V_16 ;
F_18 ( V_33 , V_1 , V_35 ) ;
V_33 -> V_37 = F_19 ( V_33 -> V_37 ) ;
if ( V_33 -> V_37 != V_38 ) {
F_20 ( L_2 ,
V_33 -> V_37 ) ;
F_21 ( V_33 ) ;
return - V_39 ;
}
V_1 += V_35 ;
V_4 -> V_40 = V_33 -> V_40 ;
V_4 -> V_41 = V_33 -> V_41 ;
V_4 -> V_42 = V_33 -> V_42 ;
snprintf ( V_4 -> V_43 , V_44 + 1 , L_3 ,
V_33 -> V_45 ) ;
F_22 (dtype, p) {
switch ( V_2 ) {
case V_46 :
V_13 = F_4 ( V_4 , V_5 , V_1 ) ;
if ( V_13 < 0 )
goto V_47;
V_1 += sizeof( struct V_7 ) ;
break;
case V_48 :
F_3 ( V_4 , V_5 , V_1 ) ;
V_1 += sizeof( struct V_49 ) ;
break;
case V_50 :
break;
default:
F_20 ( L_4 ,
V_2 ) ;
F_21 ( V_33 ) ;
return - V_51 ;
}
V_34 ++ ;
}
if ( V_34 == 0 )
V_34 = - V_51 ;
F_21 ( V_33 ) ;
return V_34 ;
V_47:
F_21 ( V_33 ) ;
return V_13 ;
}
