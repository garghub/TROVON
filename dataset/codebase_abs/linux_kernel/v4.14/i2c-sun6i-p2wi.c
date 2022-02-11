static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_4 ;
V_4 = F_2 ( V_3 -> V_5 + V_6 ) ;
V_3 -> V_4 = V_4 ;
V_4 &= ( V_7 | V_8 |
V_9 ) ;
F_3 ( V_4 , V_3 -> V_5 + V_6 ) ;
F_4 ( & V_3 -> F_4 ) ;
return V_10 ;
}
static T_2 F_5 ( struct V_11 * V_12 )
{
return V_13 ;
}
static int F_6 ( struct V_11 * V_12 , T_3 V_14 ,
unsigned short V_15 , char V_16 ,
T_4 V_17 , int V_18 , union V_19 * V_20 )
{
struct V_3 * V_3 = F_7 ( V_12 ) ;
unsigned long V_21 = F_8 ( 1 ) ;
if ( V_3 -> V_22 >= 0 && V_14 != V_3 -> V_22 ) {
F_9 ( & V_12 -> V_23 , L_1 ) ;
return - V_24 ;
}
if ( ! V_20 )
return - V_24 ;
F_3 ( V_17 , V_3 -> V_5 + V_25 ) ;
if ( V_16 == V_26 )
V_21 |= V_27 ;
else
F_3 ( V_20 -> V_28 , V_3 -> V_5 + V_29 ) ;
F_3 ( V_21 , V_3 -> V_5 + V_30 ) ;
if ( F_2 ( V_3 -> V_5 + V_31 ) & V_32 ) {
F_9 ( & V_12 -> V_23 , L_2 ) ;
return - V_33 ;
}
F_10 ( & V_3 -> F_4 ) ;
F_3 ( V_7 | V_8 | V_9 ,
V_3 -> V_5 + V_34 ) ;
F_3 ( V_32 | V_35 ,
V_3 -> V_5 + V_31 ) ;
F_11 ( & V_3 -> F_4 ) ;
if ( V_3 -> V_4 & V_7 ) {
F_9 ( & V_12 -> V_23 , L_2 ) ;
return - V_33 ;
}
if ( V_3 -> V_4 & V_8 ) {
F_9 ( & V_12 -> V_23 , L_3 ) ;
return - V_36 ;
}
if ( V_16 == V_26 )
V_20 -> V_28 = F_2 ( V_3 -> V_5 + V_29 ) ;
return 0 ;
}
static int F_12 ( struct V_37 * V_38 )
{
struct V_39 * V_23 = & V_38 -> V_23 ;
struct V_40 * V_41 = V_23 -> V_42 ;
struct V_40 * V_43 ;
unsigned long V_44 ;
T_2 V_45 = 100000 ;
struct V_46 * V_47 ;
struct V_3 * V_3 ;
T_2 V_22 ;
int V_48 ;
int V_1 ;
int V_49 ;
F_13 ( V_41 , L_4 , & V_45 ) ;
if ( V_45 > V_50 ) {
F_9 ( V_23 ,
L_5 ,
V_45 ) ;
return - V_24 ;
}
if ( F_14 ( V_41 ) > 1 ) {
F_9 ( V_23 , L_6 ) ;
return - V_24 ;
}
V_3 = F_15 ( V_23 , sizeof( struct V_3 ) , V_51 ) ;
if ( ! V_3 )
return - V_52 ;
V_3 -> V_22 = - 1 ;
V_43 = F_16 ( V_41 , NULL ) ;
if ( V_43 ) {
V_49 = F_13 ( V_43 , L_7 , & V_22 ) ;
if ( V_49 ) {
F_9 ( V_23 , L_8 ,
V_43 ) ;
return - V_24 ;
}
V_3 -> V_22 = V_22 ;
}
V_47 = F_17 ( V_38 , V_53 , 0 ) ;
V_3 -> V_5 = F_18 ( V_23 , V_47 ) ;
if ( F_19 ( V_3 -> V_5 ) )
return F_20 ( V_3 -> V_5 ) ;
F_21 ( V_3 -> V_54 . V_55 , V_38 -> V_55 , sizeof( V_3 -> V_54 . V_55 ) ) ;
V_1 = F_22 ( V_38 , 0 ) ;
if ( V_1 < 0 ) {
F_9 ( V_23 , L_9 , V_1 ) ;
return V_1 ;
}
V_3 -> V_56 = F_23 ( V_23 , NULL ) ;
if ( F_19 ( V_3 -> V_56 ) ) {
V_49 = F_20 ( V_3 -> V_56 ) ;
F_9 ( V_23 , L_10 , V_49 ) ;
return V_49 ;
}
V_49 = F_24 ( V_3 -> V_56 ) ;
if ( V_49 ) {
F_9 ( V_23 , L_11 , V_49 ) ;
return V_49 ;
}
V_44 = F_25 ( V_3 -> V_56 ) ;
V_3 -> V_57 = F_26 ( V_23 , NULL ) ;
if ( F_19 ( V_3 -> V_57 ) ) {
V_49 = F_20 ( V_3 -> V_57 ) ;
F_9 ( V_23 , L_12 , V_49 ) ;
goto V_58;
}
V_49 = F_27 ( V_3 -> V_57 ) ;
if ( V_49 ) {
F_9 ( V_23 , L_13 , V_49 ) ;
goto V_58;
}
F_28 ( & V_3 -> F_4 ) ;
V_3 -> V_54 . V_23 . V_59 = V_23 ;
V_3 -> V_54 . V_60 = & V_61 ;
V_3 -> V_54 . V_62 = V_63 ;
V_3 -> V_54 . V_23 . V_42 = V_38 -> V_23 . V_42 ;
F_29 ( V_38 , V_3 ) ;
F_30 ( & V_3 -> V_54 , V_3 ) ;
V_49 = F_31 ( V_23 , V_1 , F_1 , 0 , V_38 -> V_55 , V_3 ) ;
if ( V_49 ) {
F_9 ( V_23 , L_14 ,
V_1 , V_49 ) ;
goto V_64;
}
F_3 ( V_65 , V_3 -> V_5 + V_31 ) ;
V_48 = V_44 / V_45 ;
if ( ! V_48 ) {
F_32 ( V_23 ,
L_15 ,
V_44 ) ;
V_48 = 1 ;
} else if ( V_48 > V_66 ) {
F_32 ( V_23 ,
L_16 ,
V_44 / V_66 ) ;
V_48 = V_66 ;
}
F_3 ( F_33 ( 1 ) | F_34 ( V_48 ) ,
V_3 -> V_5 + V_67 ) ;
V_49 = F_35 ( & V_3 -> V_54 ) ;
if ( ! V_49 )
return 0 ;
V_64:
F_36 ( V_3 -> V_57 ) ;
V_58:
F_37 ( V_3 -> V_56 ) ;
return V_49 ;
}
static int F_38 ( struct V_37 * V_23 )
{
struct V_3 * V_3 = F_39 ( V_23 ) ;
F_36 ( V_3 -> V_57 ) ;
F_37 ( V_3 -> V_56 ) ;
F_40 ( & V_3 -> V_54 ) ;
return 0 ;
}
