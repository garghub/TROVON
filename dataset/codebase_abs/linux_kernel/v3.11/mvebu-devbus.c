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
V_12 . V_16 /= 8 ;
V_7 = F_1 ( V_1 , V_3 , L_6 ,
& V_12 . V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
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
V_7 = F_2 ( V_3 , L_12 ,
& V_14 . V_23 ) ;
if ( V_7 < 0 ) {
F_3 ( V_1 -> V_8 ,
L_13 ,
V_3 -> V_9 ) ;
return V_7 ;
}
V_7 = F_1 ( V_1 , V_3 , L_14 ,
& V_14 . V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_15 ,
& V_14 . V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_1 , V_3 , L_16 ,
& V_14 . V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
V_15 = V_12 . V_16 << V_27 |
V_12 . V_17 << V_28 |
V_12 . V_22 << V_29 |
V_12 . V_20 << V_30 |
V_12 . V_21 << V_31 |
V_12 . V_19 << V_32 |
V_12 . V_18 ;
F_4 ( V_1 -> V_8 , L_17 ,
V_1 -> V_33 + V_34 ,
V_15 ) ;
F_6 ( V_15 , V_1 -> V_33 + V_34 ) ;
V_15 = V_14 . V_23 << V_35 |
V_14 . V_25 << V_36 |
V_14 . V_26 << V_37 |
V_14 . V_24 ;
F_4 ( V_1 -> V_8 , L_18 ,
V_1 -> V_33 + V_38 ,
V_15 ) ;
F_6 ( V_15 , V_1 -> V_33 + V_38 ) ;
return 0 ;
}
static int F_7 ( struct V_39 * V_40 )
{
struct V_41 * V_8 = & V_40 -> V_8 ;
struct V_2 * V_3 = V_40 -> V_8 . V_42 ;
struct V_2 * V_43 ;
struct V_1 * V_1 ;
struct V_44 * V_45 ;
struct V_46 * V_46 ;
unsigned long V_47 ;
const T_2 * V_48 ;
int V_7 , V_49 ;
int V_50 , V_51 , V_52 ;
int V_53 , V_54 ;
T_1 V_33 , V_55 ;
V_1 = F_8 ( & V_40 -> V_8 , sizeof( struct V_1 ) , V_56 ) ;
if ( ! V_1 )
return - V_57 ;
V_1 -> V_8 = V_8 ;
V_45 = F_9 ( V_40 , V_58 , 0 ) ;
V_1 -> V_33 = F_10 ( & V_40 -> V_8 , V_45 ) ;
if ( F_11 ( V_1 -> V_33 ) )
return F_12 ( V_1 -> V_33 ) ;
V_46 = F_13 ( & V_40 -> V_8 , NULL ) ;
if ( F_11 ( V_46 ) )
return F_12 ( V_46 ) ;
F_14 ( V_46 ) ;
V_47 = F_15 ( V_46 ) / 1000 ;
V_1 -> V_10 = 1000000000 / V_47 ;
V_7 = F_5 ( V_1 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_49 = ( ( ( unsigned long ) V_1 -> V_33 ) % 0x400 ) / 8 ;
V_43 = F_16 ( V_3 ) ;
if ( ! V_43 )
return - V_59 ;
V_51 = F_17 ( V_43 ) ;
F_18 ( V_43 ) ;
V_50 = F_17 ( V_3 ) ;
V_52 = F_19 ( V_3 ) ;
V_54 = ( V_51 + V_50 + V_52 ) * sizeof( T_2 ) ;
V_48 = F_20 ( V_3 , L_19 , & V_53 ) ;
if ( V_48 == NULL || V_53 != V_54 )
return - V_59 ;
V_33 = F_21 ( V_3 , V_48 + V_50 ) ;
if ( V_33 == V_60 )
return - V_59 ;
V_55 = F_22 ( V_48 + V_50 + V_51 , V_52 ) ;
V_7 = F_23 ( V_61 [ V_49 ] , V_33 , V_55 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_24 ( V_3 , NULL , NULL , V_8 ) ;
if ( V_7 < 0 ) {
F_25 ( V_33 , V_55 ) ;
return V_7 ;
}
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_62 ) ;
}
