static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 , V_6 ) ;
return V_7 ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
unsigned int V_12 ;
switch ( V_11 -> V_13 ) {
case 0 :
F_5 ( V_14 , 1 ) ;
break;
case 33 :
F_5 ( V_14 , 0 ) ;
break;
case 50 :
default:
return - V_15 ;
}
V_12 = V_11 -> V_16 ^ V_4 -> V_17 ;
if ( V_12 & V_18 ) {
if ( V_11 -> V_16 & V_18 ) {
F_5 ( V_19 , 1 ) ;
F_5 ( V_20 , 1 ) ;
} else {
F_5 ( V_19 , 0 ) ;
F_5 ( V_20 , 0 ) ;
F_6 ( 500 ) ;
}
}
V_4 -> V_17 = V_11 -> V_16 ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 ,
unsigned int * V_21 )
{
unsigned int V_22 ;
int V_23 ;
V_22 = 0 ;
if ( ! F_8 ( V_24 ) && ! F_8 ( V_25 ) )
V_22 |= V_6 ;
V_23 = ( ! ! F_8 ( V_26 ) ) | ( ( ! ! F_8 ( V_27 ) ) << 1 ) ;
switch ( V_23 ) {
case 0 :
case 1 :
case 2 :
V_22 |= V_28 ;
break;
case 3 :
default:
V_22 |= V_29 ;
}
V_22 |= F_8 ( V_14 ) ? 0 : V_30 ;
V_22 |= F_8 ( V_19 ) ? V_18 : V_31 ;
V_22 |= F_8 ( V_32 ) ? 0 : V_33 ;
V_22 |= F_8 ( V_34 ) ? 0 : V_35 ;
* V_21 = V_22 ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
F_10 ( V_24 ) ;
F_10 ( V_25 ) ;
F_10 ( V_26 ) ;
F_10 ( V_27 ) ;
F_10 ( V_32 ) ;
F_10 ( V_34 ) ;
F_11 ( V_19 , 1 ) ;
F_11 ( V_20 , 1 ) ;
F_11 ( V_14 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
V_37 -> V_38 = ( V_39 ) V_4 -> V_40 ;
V_37 -> V_41 = V_37 -> V_38 + V_42 ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_43 * V_37 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
if ( V_37 -> V_16 & V_44 )
V_37 -> V_45 = V_4 -> V_46 + V_37 -> V_47 ;
else
V_37 -> V_45 = V_4 -> V_48 + V_37 -> V_47 ;
return 0 ;
}
static int F_15 ( struct V_49 * V_50 )
{
struct V_3 * V_4 ;
struct V_51 * V_52 ;
int V_53 , V_1 ;
V_4 = F_16 ( sizeof( struct V_3 ) , V_54 ) ;
if ( ! V_4 )
return - V_55 ;
V_53 = - V_56 ;
V_52 = F_17 ( V_50 , V_57 , L_1 ) ;
if ( ! V_52 ) {
F_18 ( & V_50 -> V_58 , L_2 ) ;
goto V_59;
}
V_4 -> V_46 = V_52 -> V_38 ;
V_52 = F_17 ( V_50 , V_57 , L_3 ) ;
if ( ! V_52 ) {
F_18 ( & V_50 -> V_58 , L_4 ) ;
goto V_59;
}
V_4 -> V_48 = V_52 -> V_38 ;
V_52 = F_17 ( V_50 , V_57 , L_5 ) ;
if ( ! V_52 ) {
F_18 ( & V_50 -> V_58 , L_6 ) ;
goto V_59;
}
V_4 -> V_60 = V_52 -> V_38 ;
V_4 -> V_40 = ( void * ) ( F_19 ( V_4 -> V_60 , V_42 ) -
V_61 ) ;
if ( ! V_4 -> V_40 ) {
F_18 ( & V_50 -> V_58 , L_7 ) ;
V_53 = - V_55 ;
goto V_59;
}
V_4 -> V_5 . V_62 = & V_63 ;
V_4 -> V_5 . V_64 = V_65 ;
V_4 -> V_5 . V_66 = F_20 ( V_67 ) ;
V_4 -> V_5 . V_68 = V_69 | V_70 ;
V_4 -> V_5 . V_71 = V_72 ;
V_4 -> V_5 . V_73 = ( unsigned long ) V_4 -> V_40 ;
V_4 -> V_5 . V_58 . V_74 = & V_50 -> V_58 ;
V_4 -> V_5 . V_75 = & V_76 ;
F_21 ( V_50 , V_4 ) ;
V_1 = F_20 ( V_24 ) ;
F_22 ( V_1 , V_77 ) ;
V_53 = F_23 ( V_1 , F_1 , 0 , L_8 , V_4 ) ;
if ( V_53 ) {
F_18 ( & V_50 -> V_58 , L_9 ) ;
goto V_78;
}
V_53 = F_24 ( & V_4 -> V_5 ) ;
if ( V_53 ) {
F_18 ( & V_50 -> V_58 , L_10 ) ;
goto V_79;
}
F_25 ( V_80 L_11 ) ;
return 0 ;
V_79:
F_26 ( F_20 ( V_24 ) , V_4 ) ;
V_78:
F_27 ( ( void * ) ( V_4 -> V_40 + ( V_39 ) V_61 ) ) ;
V_59:
F_28 ( V_4 ) ;
return V_53 ;
}
static int F_29 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = F_30 ( V_50 ) ;
F_31 ( & V_4 -> V_5 ) ;
F_26 ( F_20 ( V_24 ) , V_4 ) ;
F_27 ( ( void * ) ( V_4 -> V_40 + ( V_39 ) V_61 ) ) ;
F_28 ( V_4 ) ;
return 0 ;
}
