static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
T_1 V_8 = 0 ;
if ( V_2 == V_5 -> V_9 )
V_8 = V_10 << V_11 ;
else
V_8 = V_12 << V_11 ;
F_2 ( V_5 -> V_13 , L_1 , V_8 , V_3 ) ;
for ( V_7 = 0 ; V_7 < 50 ; V_7 ++ ) {
T_1 V_14 = F_3 ( V_5 -> V_15 + V_16 ) ;
if ( ( V_14 & V_17 ) < V_18 ) {
F_4 ( V_8 | V_3 ,
V_5 -> V_15 + V_19 ) ;
return 0 ;
}
F_5 ( 1 ) ;
}
F_2 ( V_5 -> V_13 , L_2 ,
F_3 ( V_5 -> V_15 + V_16 ) ) ;
return - V_20 ;
}
static T_2 F_6 ( int V_21 , void * V_22 )
{
struct V_4 * V_5 = V_22 ;
unsigned int V_23 , V_24 ;
struct V_1 * V_1 ;
V_24 = F_3 ( V_5 -> V_15 + V_25 ) ;
if ( ! ( V_24 & V_26 ) ) {
F_7 ( V_5 -> V_13 , L_3 ) ;
return V_27 ;
}
V_23 = F_3 ( V_5 -> V_15 + V_28 ) ;
F_2 ( V_5 -> V_13 , L_4 , V_23 ) ;
if ( V_23 >> V_11 == V_12 )
V_1 = V_5 -> V_29 ;
else
V_1 = V_5 -> V_9 ;
F_8 ( V_1 , V_23 & V_30 , 0 ) ;
F_4 ( V_24 | V_26 , V_5 -> V_15 + V_25 ) ;
F_4 ( V_31 , V_5 -> V_15 + V_19 ) ;
F_9 ( V_5 -> V_13 , 1000 ) ;
return V_32 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_24 ;
if ( V_5 -> V_33 ++ == 0 ) {
V_24 = F_3 ( V_5 -> V_15 + V_34 ) ;
F_4 ( V_24 & ~ V_35 , V_5 -> V_15 + V_34 ) ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_24 ;
if ( -- V_5 -> V_33 == 0 ) {
V_24 = F_3 ( V_5 -> V_15 + V_34 ) ;
F_4 ( V_24 | V_35 , V_5 -> V_15 + V_34 ) ;
}
}
static int F_12 ( struct V_36 * V_37 )
{
struct V_1 * V_38 , * V_39 ;
struct V_4 * V_5 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
unsigned long V_44 ;
int error ;
V_5 = F_13 ( & V_37 -> V_13 , sizeof( struct V_4 ) , V_45 ) ;
if ( ! V_5 )
return - V_46 ;
V_43 = V_37 -> V_13 . V_47 ;
V_41 = F_14 ( V_37 , V_48 , 0 ) ;
if ( ! V_41 )
return - V_49 ;
V_5 -> V_15 = F_15 ( & V_37 -> V_13 , V_41 ) ;
if ( F_16 ( V_5 -> V_15 ) ) {
F_17 ( & V_37 -> V_13 , L_5 ) ;
return F_18 ( V_5 -> V_15 ) ;
}
V_5 -> V_21 = F_19 ( V_37 , 0 ) ;
if ( V_5 -> V_21 < 0 )
return V_5 -> V_21 ;
V_44 = F_3 ( V_5 -> V_15 + V_16 ) ;
if ( ! ( V_44 & V_50 ) ) {
F_17 ( & V_37 -> V_13 , L_6 ) ;
return - V_51 ;
}
V_38 = F_20 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_38 )
return - V_46 ;
V_38 -> V_52 . type = V_53 ;
V_38 -> V_54 = F_1 ;
V_38 -> V_55 = F_10 ;
V_38 -> V_56 = F_11 ;
V_38 -> V_6 = V_5 ;
V_38 -> V_13 . V_57 = & V_37 -> V_13 ;
F_21 ( V_38 -> V_58 , L_7 , sizeof( V_38 -> V_58 ) ) ;
F_21 ( V_38 -> V_59 , L_8 , sizeof( V_38 -> V_59 ) ) ;
V_5 -> V_29 = V_38 ;
F_22 ( V_38 ) ;
V_39 = F_20 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_39 ) {
error = - V_46 ;
goto V_60;
}
V_39 -> V_52 . type = V_61 ;
V_39 -> V_54 = F_1 ;
V_39 -> V_55 = F_10 ;
V_39 -> V_56 = F_11 ;
V_39 -> V_6 = V_5 ;
V_39 -> V_13 . V_57 = & V_37 -> V_13 ;
F_21 ( V_39 -> V_58 , L_9 , sizeof( V_39 -> V_58 ) ) ;
F_21 ( V_39 -> V_59 , L_10 , sizeof( V_39 -> V_59 ) ) ;
V_5 -> V_9 = V_39 ;
F_22 ( V_39 ) ;
error = F_23 ( V_5 -> V_21 , F_6 , 0 , L_11 , V_5 ) ;
if ( error ) {
F_17 ( & V_37 -> V_13 , L_12 ) ;
goto V_62;
}
V_5 -> V_13 = & V_37 -> V_13 ;
F_24 ( V_5 -> V_13 , 1 ) ;
F_25 ( V_37 , V_5 ) ;
F_2 ( & V_37 -> V_13 , L_13 ) ;
return 0 ;
V_62:
F_26 ( V_39 ) ;
V_60:
F_26 ( V_38 ) ;
return error ;
}
static int F_27 ( struct V_36 * V_37 )
{
struct V_4 * V_5 = F_28 ( V_37 ) ;
F_29 ( V_5 -> V_21 , V_5 ) ;
F_26 ( V_5 -> V_29 ) ;
F_26 ( V_5 -> V_9 ) ;
return 0 ;
}
