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
case 20000000 :
return V_21 ;
case 26000000 :
return V_22 ;
case 38400000 :
return V_23 ;
default:
return V_24 ;
}
}
static void F_8 ( struct V_4 * V_5 )
{
T_1 V_6 ;
unsigned long V_7 ;
F_4 ( V_5 -> V_10 , V_25 , V_26 ) ;
V_7 = V_27 + F_9 ( 20 ) ;
do {
V_6 = F_3 ( V_5 -> V_10 , V_13 ) ;
if ( V_6 & V_28 )
break;
} while ( ! F_10 ( F_11 ( V_27 , V_7 ) ) );
}
static int F_12 ( struct V_4 * V_5 )
{
T_1 V_6 ;
unsigned long V_17 ;
enum V_16 V_29 ;
V_17 = F_13 ( V_5 -> V_30 ) ;
V_29 = F_7 ( V_17 ) ;
if ( V_29 == V_24 ) {
F_14 ( L_1 , V_17 ) ;
return - V_31 ;
}
V_6 = F_3 ( V_5 -> V_10 , V_32 ) ;
V_6 &= ~ V_33 ;
V_6 |= V_34 [ V_29 ] . V_35 << V_36 ;
F_4 ( V_5 -> V_10 , V_32 , V_6 ) ;
V_6 = F_3 ( V_5 -> V_10 , V_11 ) ;
V_6 &= ~ V_37 ;
V_6 |= V_34 [ V_29 ] . V_38 << V_39 ;
F_4 ( V_5 -> V_10 , V_11 , V_6 ) ;
V_6 = F_3 ( V_5 -> V_10 , V_32 ) ;
V_6 &= ~ V_40 ;
V_6 |= V_34 [ V_29 ] . V_41 << V_42 ;
F_4 ( V_5 -> V_10 , V_32 , V_6 ) ;
V_6 = F_3 ( V_5 -> V_10 , V_43 ) ;
V_6 &= ~ V_44 ;
V_6 |= V_34 [ V_29 ] . V_45 << V_46 ;
F_4 ( V_5 -> V_10 , V_43 , V_6 ) ;
V_6 = F_3 ( V_5 -> V_10 , V_47 ) ;
V_6 &= ~ V_48 ;
V_6 |= V_34 [ V_29 ] . V_49 << V_50 ;
F_4 ( V_5 -> V_10 , V_47 , V_6 ) ;
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
static int F_16 ( struct V_51 * V_52 )
{
struct V_4 * V_5 ;
struct V_53 * V_54 ;
V_5 = F_17 ( & V_52 -> V_55 , sizeof( * V_5 ) , V_56 ) ;
if ( ! V_5 ) {
F_18 ( & V_52 -> V_55 , L_2 ) ;
return - V_57 ;
}
V_54 = F_19 ( V_52 , V_58 , L_3 ) ;
V_5 -> V_10 = F_20 ( & V_52 -> V_55 , V_54 ) ;
if ( F_21 ( V_5 -> V_10 ) )
return F_22 ( V_5 -> V_10 ) ;
V_5 -> V_55 = & V_52 -> V_55 ;
V_5 -> V_5 . V_55 = V_5 -> V_55 ;
V_5 -> V_5 . V_59 = L_4 ;
V_5 -> V_5 . V_60 = F_15 ;
V_5 -> V_5 . V_61 = F_1 ;
V_5 -> V_5 . type = V_62 ;
V_5 -> V_9 = 1 ;
V_5 -> V_63 = F_23 ( V_5 -> V_55 , L_5 ) ;
if ( F_21 ( V_5 -> V_63 ) ) {
F_18 ( & V_52 -> V_55 , L_6 ) ;
return F_22 ( V_5 -> V_63 ) ;
}
F_24 ( V_5 -> V_63 ) ;
V_5 -> V_64 = F_23 ( V_5 -> V_55 , L_7 ) ;
if ( F_21 ( V_5 -> V_64 ) ) {
F_18 ( & V_52 -> V_55 , L_8 ) ;
return F_22 ( V_5 -> V_64 ) ;
}
F_24 ( V_5 -> V_64 ) ;
V_5 -> V_30 = F_23 ( V_5 -> V_55 , L_9 ) ;
if ( F_21 ( V_5 -> V_30 ) ) {
F_14 ( L_10 , V_65 ) ;
return - V_31 ;
}
V_5 -> V_15 = F_25 () ;
if ( F_21 ( V_5 -> V_15 ) ) {
F_26 ( & V_52 -> V_55 , L_11 ) ;
return - V_66 ;
}
F_6 ( V_5 -> V_15 , 0 ) ;
F_27 ( & V_5 -> V_5 ) ;
F_28 ( V_52 , V_5 ) ;
F_29 ( V_5 -> V_55 ) ;
F_30 ( & V_52 -> V_55 ) ;
return 0 ;
}
static int F_31 ( struct V_51 * V_52 )
{
struct V_4 * V_5 = F_32 ( V_52 ) ;
F_33 ( V_5 -> V_63 ) ;
F_33 ( V_5 -> V_64 ) ;
F_34 ( & V_5 -> V_5 ) ;
if ( ! F_35 ( & V_52 -> V_55 ) )
F_36 ( & V_52 -> V_55 ) ;
F_37 ( & V_52 -> V_55 ) ;
return 0 ;
}
static int F_38 ( struct V_67 * V_55 )
{
struct V_51 * V_52 = F_39 ( V_55 ) ;
struct V_4 * V_5 = F_32 ( V_52 ) ;
F_40 ( V_5 -> V_63 ) ;
F_40 ( V_5 -> V_64 ) ;
return 0 ;
}
static int F_41 ( struct V_67 * V_55 )
{
T_1 V_68 = 0 ;
struct V_51 * V_52 = F_39 ( V_55 ) ;
struct V_4 * V_5 = F_32 ( V_52 ) ;
V_68 = F_42 ( V_5 -> V_64 ) ;
if ( V_68 ) {
F_18 ( V_5 -> V_55 , L_12 , V_68 ) ;
goto V_69;
}
V_68 = F_42 ( V_5 -> V_63 ) ;
if ( V_68 ) {
F_18 ( V_5 -> V_55 , L_13 , V_68 ) ;
goto V_70;
}
return 0 ;
V_70:
F_40 ( V_5 -> V_64 ) ;
V_69:
return V_68 ;
}
