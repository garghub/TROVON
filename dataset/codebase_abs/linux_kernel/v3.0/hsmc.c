void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
int V_6 ;
unsigned long V_7 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_7 = ( F_2 ( V_18 -> V_19 ) / 10000 ) << 16 ;
V_7 /= 100000 ;
#define F_3 ( T_1 ) ((((x) * mul) + 65535) >> 16)
if ( V_4 -> V_8 > 0 )
V_2 -> V_8 = F_3 ( V_4 -> V_8 ) ;
if ( V_4 -> V_9 > 0 )
V_2 -> V_9 = F_3 ( V_4 -> V_9 ) ;
if ( V_4 -> V_10 > 0 )
V_2 -> V_10 = F_3 ( V_4 -> V_10 ) ;
if ( V_4 -> V_11 > 0 )
V_2 -> V_11 = F_3 ( V_4 -> V_11 ) ;
if ( V_4 -> V_12 > 0 )
V_2 -> V_12 = F_3 ( V_4 -> V_12 ) ;
if ( V_4 -> V_13 > 0 )
V_2 -> V_13 = F_3 ( V_4 -> V_13 ) ;
if ( V_4 -> V_14 > 0 )
V_2 -> V_14 = F_3 ( V_4 -> V_14 ) ;
if ( V_4 -> V_15 > 0 )
V_2 -> V_15 = F_3 ( V_4 -> V_15 ) ;
if ( V_4 -> V_16 > 0 )
V_2 -> V_16 = F_3 ( V_4 -> V_16 ) ;
if ( V_4 -> V_17 > 0 )
V_2 -> V_17 = F_3 ( V_4 -> V_17 ) ;
if ( V_4 -> V_20 > 0 )
V_5 = F_3 ( V_4 -> V_20 ) ;
else
V_5 = 1 ;
V_6 = V_2 -> V_8 + V_2 -> V_12 + V_5 ;
if ( V_2 -> V_16 < V_6 )
V_2 -> V_16 = V_6 ;
if ( V_4 -> V_21 > 0 )
V_5 = F_3 ( V_4 -> V_21 ) ;
else
V_5 = 1 ;
V_6 = V_2 -> V_9 + V_2 -> V_13 + V_5 ;
if ( V_2 -> V_16 < V_6 )
V_2 -> V_16 = V_6 ;
if ( V_4 -> V_22 > 0 )
V_5 = F_3 ( V_4 -> V_22 ) ;
else
V_5 = 1 ;
V_6 = V_2 -> V_10 + V_2 -> V_14 + V_5 ;
if ( V_2 -> V_17 < V_6 )
V_2 -> V_17 = V_6 ;
if ( V_4 -> V_23 > 0 )
V_5 = F_3 ( V_4 -> V_23 ) ;
else
V_5 = 1 ;
V_6 = V_2 -> V_11 + V_2 -> V_15 + V_5 ;
if ( V_2 -> V_17 < V_6 )
V_2 -> V_17 = V_6 ;
}
int F_4 ( int V_24 , const struct V_1 * V_2 )
{
unsigned long V_25 ;
T_2 V_26 , V_27 , V_6 , V_28 ;
if ( ! V_18 )
return - V_29 ;
if ( V_24 >= V_30 )
return - V_31 ;
V_26 = ( F_5 ( V_32 , V_2 -> V_11 )
| F_5 ( V_33 , V_2 -> V_10 )
| F_5 ( V_34 , V_2 -> V_9 )
| F_5 ( V_35 , V_2 -> V_8 ) ) ;
V_27 = ( F_5 ( V_36 , V_2 -> V_15 )
| F_5 ( V_37 , V_2 -> V_14 )
| F_5 ( V_38 , V_2 -> V_13 )
| F_5 ( V_39 , V_2 -> V_12 ) ) ;
V_6 = ( F_5 ( V_40 , V_2 -> V_17 )
| F_5 ( V_41 , V_2 -> V_16 ) ) ;
switch ( V_2 -> V_42 ) {
case 1 :
V_28 = F_5 ( V_43 , V_44 ) ;
break;
case 2 :
V_28 = F_5 ( V_43 , V_45 ) ;
break;
case 4 :
V_28 = F_5 ( V_43 , V_46 ) ;
break;
default:
return - V_31 ;
}
switch ( V_2 -> V_47 ) {
case 0 :
V_28 |= F_5 ( V_48 , V_49 ) ;
break;
case 1 :
V_28 |= F_5 ( V_48 , V_50 ) ;
break;
case 2 :
V_28 |= F_5 ( V_48 , V_51 ) ;
break;
case 3 :
V_28 |= F_5 ( V_48 , V_52 ) ;
break;
default:
return - V_31 ;
}
if ( V_2 -> V_53 ) {
V_28 |= F_5 ( V_54 , V_2 -> V_53 ) ;
}
if ( V_2 -> V_55 )
V_28 |= F_6 ( V_56 ) ;
if ( V_2 -> V_57 )
V_28 |= F_6 ( V_58 ) ;
if ( V_2 -> V_59 )
V_28 |= F_6 ( V_60 ) ;
if ( V_2 -> V_61 )
V_28 |= F_6 ( V_62 ) ;
F_7 ( L_1 ,
V_24 , V_26 , V_27 , V_6 , V_28 ) ;
V_25 = V_24 * 0x10 ;
F_8 ( V_18 , V_63 + V_25 , V_26 ) ;
F_8 ( V_18 , V_64 + V_25 , V_27 ) ;
F_8 ( V_18 , V_65 + V_25 , V_6 ) ;
F_8 ( V_18 , V_66 + V_25 , V_28 ) ;
F_9 ( V_18 , V_66 ) ;
return 0 ;
}
static int F_10 ( struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_71 * V_72 , * V_19 ;
int V_73 ;
if ( V_18 )
return - V_74 ;
V_70 = F_11 ( V_68 , V_75 , 0 ) ;
if ( ! V_70 )
return - V_76 ;
V_72 = F_12 ( & V_68 -> V_77 , L_2 ) ;
if ( F_13 ( V_72 ) )
return F_14 ( V_72 ) ;
V_19 = F_12 ( & V_68 -> V_77 , L_3 ) ;
if ( F_13 ( V_19 ) ) {
V_73 = F_14 ( V_19 ) ;
goto V_78;
}
V_73 = - V_79 ;
V_18 = F_15 ( sizeof( struct V_18 ) , V_80 ) ;
if ( ! V_18 )
goto V_81;
F_16 ( V_72 ) ;
F_16 ( V_19 ) ;
V_18 -> V_72 = V_72 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_70 = F_17 ( V_70 -> V_82 , V_70 -> V_83 - V_70 -> V_82 + 1 ) ;
if ( ! V_18 -> V_70 )
goto V_84;
F_18 ( & V_68 -> V_77 , L_4 ,
( unsigned long ) V_70 -> V_82 ) ;
F_19 ( V_68 , V_18 ) ;
return 0 ;
V_84:
F_20 ( V_19 ) ;
F_20 ( V_72 ) ;
F_21 ( V_18 ) ;
V_81:
F_22 ( V_19 ) ;
V_78:
F_22 ( V_72 ) ;
V_18 = NULL ;
return V_73 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_85 ) ;
}
