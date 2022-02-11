static int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const char * V_4 ,
T_1 * V_5 )
{
T_1 V_6 ;
int V_7 ;
V_7 = F_2 ( V_3 , V_4 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 , L_1 ,
V_4 , V_3 -> V_9 ) ;
return V_7 ;
}
* V_5 = ( V_6 + V_1 -> V_10 - 1 ) / V_1 -> V_10 ;
F_4 ( V_1 -> V_8 , L_2 ,
V_4 , V_6 , * V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_11 V_12 ;
struct V_13 V_14 ;
T_1 V_15 ;
int V_7 ;
F_4 ( V_1 -> V_8 , L_3 ,
V_1 -> V_10 ) ;
V_7 = F_2 ( V_3 , L_4 , & V_12 . V_16 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 ,
L_5 ,
V_3 -> V_9 ) ;
return V_7 ;
}
if ( V_12 . V_16 == 8 )
V_12 . V_16 = 0 ;
else if ( V_12 . V_16 == 16 )
V_12 . V_16 = 1 ;
else {
F_3 ( V_1 -> V_8 , L_6 , V_12 . V_16 ) ;
return - V_17 ;
}
V_7 = F_1 ( V_1 , V_3 , L_7 ,
& V_12 . V_18 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_8 ,
& V_12 . V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_9 ,
& V_12 . V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_10 ,
& V_12 . V_21 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_11 ,
& V_12 . V_22 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_12 ,
& V_12 . V_23 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_3 , L_13 ,
& V_14 . V_24 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 ,
L_14 ,
V_3 -> V_9 ) ;
return V_7 ;
}
V_7 = F_1 ( V_1 , V_3 , L_15 ,
& V_14 . V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_16 ,
& V_14 . V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_17 ,
& V_14 . V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_15 = V_12 . V_16 << V_28 |
V_12 . V_18 << V_29 |
V_12 . V_23 << V_30 |
V_12 . V_21 << V_31 |
V_12 . V_22 << V_32 |
V_12 . V_20 << V_33 |
V_12 . V_19 ;
F_4 ( V_1 -> V_8 , L_18 ,
V_1 -> V_34 + V_35 ,
V_15 ) ;
F_6 ( V_15 , V_1 -> V_34 + V_35 ) ;
V_15 = V_14 . V_24 << V_36 |
V_14 . V_26 << V_37 |
V_14 . V_27 << V_38 |
V_14 . V_25 ;
F_4 ( V_1 -> V_8 , L_19 ,
V_1 -> V_34 + V_39 ,
V_15 ) ;
F_6 ( V_15 , V_1 -> V_34 + V_39 ) ;
return 0 ;
}
static int F_7 ( struct V_40 * V_41 )
{
struct V_42 * V_8 = & V_41 -> V_8 ;
struct V_2 * V_3 = V_41 -> V_8 . V_43 ;
struct V_1 * V_1 ;
struct V_44 * V_45 ;
struct V_46 * V_46 ;
unsigned long V_47 ;
int V_7 ;
V_1 = F_8 ( & V_41 -> V_8 , sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_1 )
return - V_49 ;
V_1 -> V_8 = V_8 ;
V_45 = F_9 ( V_41 , V_50 , 0 ) ;
V_1 -> V_34 = F_10 ( & V_41 -> V_8 , V_45 ) ;
if ( F_11 ( V_1 -> V_34 ) )
return F_12 ( V_1 -> V_34 ) ;
V_46 = F_13 ( & V_41 -> V_8 , NULL ) ;
if ( F_11 ( V_46 ) )
return F_12 ( V_46 ) ;
F_14 ( V_46 ) ;
V_47 = F_15 ( V_46 ) / 1000 ;
V_1 -> V_10 = 1000000000 / V_47 ;
V_7 = F_5 ( V_1 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_16 ( V_3 , NULL , NULL , V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_51 ) ;
}
