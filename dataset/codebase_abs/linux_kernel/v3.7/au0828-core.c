T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_4 = 0 ;
F_2 ( V_2 , V_5 , 0 , V_3 , & V_4 , 1 ) ;
F_3 ( 8 , L_1 , V_6 , V_3 , V_4 ) ;
return V_4 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_7 )
{
F_3 ( 8 , L_2 , V_6 , V_3 , V_7 ) ;
return F_5 ( V_2 , V_8 , V_7 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 )
{
int V_12 = - V_13 ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_7 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_15 | V_16 |
V_17 ,
V_10 , V_11 , NULL , 0 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( V_18 L_3 ,
V_6 , V_12 ) ;
}
}
return V_12 ;
}
static int F_2 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 , unsigned char * V_19 , T_2 V_20 )
{
int V_12 = - V_13 ;
F_10 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_11 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_22 | V_16 | V_17 ,
V_10 , V_11 ,
V_2 -> V_23 , V_20 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( V_18 L_4 ,
V_6 , V_12 ) ;
}
memcpy ( V_19 , V_2 -> V_23 , V_20 ) ;
}
F_12 ( & V_2 -> V_21 ) ;
return V_12 ;
}
static void F_13 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_14 ( V_25 ) ;
F_3 ( 1 , L_5 , V_6 ) ;
F_15 ( V_2 ) ;
if ( F_16 ( 0 ) . type != V_26 )
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( & V_2 -> V_27 ) ;
F_20 ( V_25 , NULL ) ;
F_10 ( & V_2 -> V_21 ) ;
V_2 -> V_14 = NULL ;
F_12 ( & V_2 -> V_21 ) ;
F_21 ( V_2 ) ;
}
static int F_22 ( struct V_24 * V_25 ,
const struct V_28 * V_29 )
{
int V_30 , V_31 ;
struct V_1 * V_2 ;
struct V_32 * V_14 = F_23 ( V_25 ) ;
V_30 = V_25 -> V_33 -> V_34 . V_35 ;
if ( V_30 != 0 )
return - V_13 ;
F_3 ( 1 , L_6 , V_6 ,
F_24 ( V_14 -> V_36 . V_37 ) ,
F_24 ( V_14 -> V_36 . V_38 ) ,
V_30 ) ;
if ( V_14 -> V_39 != V_40 && V_41 == 0 ) {
F_9 ( V_18 L_7 ) ;
F_9 ( V_18 L_8
L_9 ) ;
return - V_13 ;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_42 ) ;
if ( V_2 == NULL ) {
F_9 ( V_18 L_10 , V_6 ) ;
return - V_43 ;
}
F_26 ( & V_2 -> V_44 ) ;
F_10 ( & V_2 -> V_44 ) ;
F_26 ( & V_2 -> V_21 ) ;
F_26 ( & V_2 -> V_45 . V_44 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_46 = V_29 -> V_47 ;
V_31 = F_27 ( & V_25 -> V_2 , & V_2 -> V_27 ) ;
if ( V_31 ) {
F_9 ( V_18 L_11 ,
V_6 ) ;
F_12 ( & V_2 -> V_44 ) ;
F_21 ( V_2 ) ;
return - V_48 ;
}
F_28 ( V_2 , V_49 , 1 << 4 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
if ( F_16 ( 0 ) . type != V_26 )
F_32 ( V_2 , V_25 ) ;
F_33 ( V_2 ) ;
F_20 ( V_25 , V_2 ) ;
F_9 ( V_50 L_12 ,
V_2 -> V_51 . V_52 == NULL ? L_13 : V_2 -> V_51 . V_52 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
int V_53 ;
if ( V_54 & 1 )
F_9 ( V_50 L_14 , V_6 ) ;
if ( V_54 & 2 )
F_9 ( V_50 L_15 , V_6 ) ;
if ( V_54 & 4 )
F_9 ( V_50 L_16 , V_6 ) ;
if ( V_54 & 8 )
F_9 ( V_50 L_17 ,
V_6 ) ;
F_9 ( V_50 L_18 ) ;
V_53 = F_35 ( & V_55 ) ;
if ( V_53 )
F_9 ( V_18 L_19 , V_53 ) ;
return V_53 ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_55 ) ;
}
