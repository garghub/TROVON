static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
int V_7 = V_8 ;
if ( V_3 && ! V_5 -> V_9 ) {
V_6 = F_3 ( V_5 -> V_10 , V_11 ) ;
V_6 |= V_12 ;
F_4 ( V_5 -> V_10 , V_11 , V_6 ) ;
do {
V_6 = F_3 ( V_5 -> V_10 , V_13 ) ;
if ( V_6 & V_14 )
break;
F_5 ( 1 ) ;
} while ( -- V_7 );
F_6 ( V_5 -> V_15 , 0 ) ;
V_5 -> V_9 = 1 ;
} else if ( ! V_3 && V_5 -> V_9 ) {
V_5 -> V_9 = 0 ;
V_6 = F_3 ( V_5 -> V_10 , V_11 ) ;
V_6 &= ~ V_12 ;
F_4 ( V_5 -> V_10 , V_11 , V_6 ) ;
do {
V_6 = F_3 ( V_5 -> V_10 , V_13 ) ;
if ( ! ( V_6 & V_14 ) )
break;
F_5 ( 1 ) ;
} while ( -- V_7 );
}
return 0 ;
}
static inline enum V_16 F_7 ( unsigned long V_17 )
{
switch ( V_17 ) {
case 12000000 :
return V_18 ;
case 16800000 :
return V_19 ;
case 19200000 :
return V_20 ;
case 26000000 :
return V_21 ;
case 38400000 :
return V_22 ;
default:
return V_23 ;
}
}
static void F_8 ( struct V_4 * V_5 )
{
T_1 V_6 ;
unsigned long V_7 ;
F_4 ( V_5 -> V_10 , V_24 , V_25 ) ;
V_7 = V_26 + F_9 ( 20 ) ;
do {
V_6 = F_3 ( V_5 -> V_10 , V_13 ) ;
if ( V_6 & V_27 )
break;
} while ( ! F_10 ( F_11 ( V_26 , V_7 ) ) );
}
static int F_12 ( struct V_4 * V_5 )
{
T_1 V_6 ;
unsigned long V_17 ;
enum V_16 V_28 ;
V_17 = F_13 ( V_5 -> V_29 ) ;
V_28 = F_7 ( V_17 ) ;
if ( V_28 == V_23 ) {
F_14 ( L_1 , V_17 ) ;
return - V_30 ;
}
V_6 = F_3 ( V_5 -> V_10 , V_31 ) ;
V_6 &= ~ V_32 ;
V_6 |= V_33 [ V_28 ] . V_34 << V_35 ;
F_4 ( V_5 -> V_10 , V_31 , V_6 ) ;
V_6 = F_3 ( V_5 -> V_10 , V_11 ) ;
V_6 &= ~ V_36 ;
V_6 |= V_33 [ V_28 ] . V_37 << V_38 ;
F_4 ( V_5 -> V_10 , V_11 , V_6 ) ;
V_6 = F_3 ( V_5 -> V_10 , V_31 ) ;
V_6 &= ~ V_39 ;
V_6 |= V_33 [ V_28 ] . V_40 << V_41 ;
F_4 ( V_5 -> V_10 , V_31 , V_6 ) ;
V_6 = F_3 ( V_5 -> V_10 , V_42 ) ;
V_6 &= ~ V_43 ;
V_6 |= V_33 [ V_28 ] . V_44 << V_45 ;
F_4 ( V_5 -> V_10 , V_42 , V_6 ) ;
V_6 = F_3 ( V_5 -> V_10 , V_46 ) ;
V_6 &= ~ V_47 ;
V_6 |= V_33 [ V_28 ] . V_48 << V_49 ;
F_4 ( V_5 -> V_10 , V_46 , V_6 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( V_5 ) ;
F_6 ( V_5 -> V_15 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_50 * V_51 )
{
struct V_4 * V_5 ;
struct V_52 * V_53 ;
V_5 = F_17 ( & V_51 -> V_54 , sizeof( * V_5 ) , V_55 ) ;
if ( ! V_5 ) {
F_18 ( & V_51 -> V_54 , L_2 ) ;
return - V_56 ;
}
V_53 = F_19 ( V_51 , V_57 , L_3 ) ;
V_5 -> V_10 = F_20 ( & V_51 -> V_54 , V_53 ) ;
if ( F_21 ( V_5 -> V_10 ) )
return F_22 ( V_5 -> V_10 ) ;
V_5 -> V_54 = & V_51 -> V_54 ;
V_5 -> V_5 . V_54 = V_5 -> V_54 ;
V_5 -> V_5 . V_58 = L_4 ;
V_5 -> V_5 . V_59 = F_15 ;
V_5 -> V_5 . V_60 = F_1 ;
V_5 -> V_5 . type = V_61 ;
V_5 -> V_9 = 1 ;
V_5 -> V_62 = F_23 ( V_5 -> V_54 , L_5 ) ;
if ( F_21 ( V_5 -> V_62 ) ) {
F_18 ( & V_51 -> V_54 , L_6 ) ;
return F_22 ( V_5 -> V_62 ) ;
}
F_24 ( V_5 -> V_62 ) ;
V_5 -> V_63 = F_23 ( V_5 -> V_54 , L_7 ) ;
if ( F_21 ( V_5 -> V_63 ) ) {
F_18 ( & V_51 -> V_54 , L_8 ) ;
return F_22 ( V_5 -> V_63 ) ;
}
F_24 ( V_5 -> V_63 ) ;
V_5 -> V_29 = F_23 ( V_5 -> V_54 , L_9 ) ;
if ( F_21 ( V_5 -> V_29 ) ) {
F_14 ( L_10 , V_64 ) ;
return - V_30 ;
}
V_5 -> V_15 = F_25 () ;
if ( F_21 ( V_5 -> V_15 ) ) {
F_26 ( & V_51 -> V_54 , L_11 ) ;
return - V_65 ;
}
F_6 ( V_5 -> V_15 , 0 ) ;
F_27 ( & V_5 -> V_5 ) ;
F_28 ( V_51 , V_5 ) ;
F_29 ( V_5 -> V_54 ) ;
F_30 ( & V_51 -> V_54 ) ;
return 0 ;
}
static int F_31 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = F_32 ( V_51 ) ;
F_33 ( V_5 -> V_62 ) ;
F_33 ( V_5 -> V_63 ) ;
F_34 ( & V_5 -> V_5 ) ;
if ( ! F_35 ( & V_51 -> V_54 ) )
F_36 ( & V_51 -> V_54 ) ;
F_37 ( & V_51 -> V_54 ) ;
return 0 ;
}
static int F_38 ( struct V_66 * V_54 )
{
struct V_50 * V_51 = F_39 ( V_54 ) ;
struct V_4 * V_5 = F_32 ( V_51 ) ;
F_40 ( V_5 -> V_62 ) ;
F_40 ( V_5 -> V_63 ) ;
return 0 ;
}
static int F_41 ( struct V_66 * V_54 )
{
T_1 V_67 = 0 ;
struct V_50 * V_51 = F_39 ( V_54 ) ;
struct V_4 * V_5 = F_32 ( V_51 ) ;
V_67 = F_42 ( V_5 -> V_63 ) ;
if ( V_67 ) {
F_18 ( V_5 -> V_54 , L_12 , V_67 ) ;
goto V_68;
}
V_67 = F_42 ( V_5 -> V_62 ) ;
if ( V_67 ) {
F_18 ( V_5 -> V_54 , L_13 , V_67 ) ;
goto V_69;
}
return 0 ;
V_69:
F_40 ( V_5 -> V_63 ) ;
V_68:
return V_67 ;
}
