static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned int V_5 ;
unsigned int V_6 ;
unsigned int V_7 = V_8 ;
unsigned long V_9 ;
unsigned long V_10 ;
F_3 ( V_4 -> V_11 ,
V_4 -> V_12 + V_13 ,
F_4 ( V_14 ,
V_15 ,
V_16 ) ) ;
F_3 ( V_4 -> V_11 ,
V_4 -> V_12 + V_13 ,
F_4 ( V_17 ,
V_18 ,
V_19 ) ) ;
if ( V_2 == V_14 )
return 0 ;
V_9 = F_5 ( V_4 -> V_20 ) ;
if ( V_9 != 0 ) {
unsigned long V_21 ;
unsigned long V_22 ;
switch ( V_9 ) {
case 1 ... 74999999 :
V_21 = 50000000 ;
V_7 = V_23 ;
break;
case 75000000 ... 124999999 :
V_21 = 100000000 ;
V_7 = V_24 ;
break;
case 125000000 ... 174999999 :
V_21 = 150000000 ;
V_7 = V_25 ;
break;
default:
V_21 = 200000000 ;
break;
} ;
V_22 = ( V_9 > V_21 ) ?
V_9 - V_21 : V_21 - V_9 ;
if ( ( V_9 > 50000000 && V_22 > 15000000 ) || ( V_9 > 200000000 ) )
F_6 ( & V_1 -> V_26 , L_1 , V_9 ) ;
}
F_7 ( 3 ) ;
F_3 ( V_4 -> V_11 ,
V_4 -> V_12 + V_13 ,
F_4 ( V_27 ,
V_15 ,
V_16 ) ) ;
F_7 ( 5 ) ;
F_8 ( V_4 -> V_11 ,
V_4 -> V_12 + V_28 ,
& V_5 ) ;
V_5 = ( V_5 >> V_29 ) & V_30 ;
if ( V_5 != V_31 ) {
F_9 ( L_2 ) ;
return - V_32 ;
}
F_3 ( V_4 -> V_11 ,
V_4 -> V_12 + V_33 ,
F_4 ( V_7 , V_34 ,
V_35 ) ) ;
F_3 ( V_4 -> V_11 ,
V_4 -> V_12 + V_13 ,
F_4 ( V_36 ,
V_18 ,
V_19 ) ) ;
if ( V_9 == 0 )
return 0 ;
V_10 = V_37 + F_10 ( 50 ) ;
do {
F_7 ( 1 ) ;
F_8 ( V_4 -> V_11 ,
V_4 -> V_12 + V_28 ,
& V_6 ) ;
V_6 = ( V_6 >> V_38 ) & V_39 ;
if ( V_6 == V_40 )
break;
} while ( ! F_11 ( V_37 , V_10 ) );
if ( V_6 != V_40 ) {
F_9 ( L_3 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
int V_41 = 0 ;
V_4 -> V_20 = F_13 ( & V_1 -> V_26 , L_4 ) ;
if ( F_14 ( V_4 -> V_20 ) ) {
F_15 ( & V_1 -> V_26 , L_5 , V_41 ) ;
V_4 -> V_20 = NULL ;
}
return V_41 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
F_17 ( V_4 -> V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , V_14 ) ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
F_3 ( V_4 -> V_11 ,
V_4 -> V_12 + V_13 ,
F_4 ( V_42 ,
V_43 ,
V_44 ) ) ;
F_3 ( V_4 -> V_11 ,
V_4 -> V_12 + V_33 ,
F_4 ( V_45 ,
V_46 ,
V_47 ) ) ;
F_3 ( V_4 -> V_11 ,
V_4 -> V_12 + V_33 ,
F_4 ( 4 ,
V_48 ,
V_49 ) ) ;
return F_1 ( V_1 , V_27 ) ;
}
static int F_20 ( struct V_50 * V_51 )
{
struct V_52 * V_26 = & V_51 -> V_26 ;
struct V_3 * V_4 ;
struct V_1 * V_53 ;
struct V_54 * V_54 ;
struct V_55 * V_56 ;
unsigned int V_12 ;
if ( ! V_26 -> V_57 || ! V_26 -> V_57 -> V_58 )
return - V_59 ;
V_56 = F_21 ( V_26 -> V_57 -> V_58 ) ;
if ( F_14 ( V_56 ) ) {
F_22 ( V_26 , L_6 ) ;
return F_23 ( V_56 ) ;
}
V_4 = F_24 ( V_26 , sizeof( * V_4 ) , V_60 ) ;
if ( ! V_4 )
return - V_61 ;
if ( F_25 ( V_26 -> V_58 , L_7 , & V_12 ) ) {
F_22 ( V_26 , L_8 ,
V_26 -> V_58 -> V_62 ) ;
return - V_63 ;
}
V_4 -> V_12 = V_12 ;
V_4 -> V_11 = V_56 ;
V_53 = F_26 ( V_26 , V_26 -> V_58 , & V_64 ) ;
if ( F_14 ( V_53 ) ) {
F_22 ( V_26 , L_9 ) ;
return F_23 ( V_53 ) ;
}
F_27 ( V_53 , V_4 ) ;
V_54 = F_28 ( V_26 , V_65 ) ;
return F_29 ( V_54 ) ;
}
