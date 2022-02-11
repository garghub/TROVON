static int F_1 ( void )
{
struct V_1 * V_1 = V_2 ;
if ( ! ( F_2 ( V_1 -> V_3 + V_4 ) & V_5 ) )
return - V_6 ;
return 0 ;
}
static unsigned short F_3 ( struct V_7 * V_8 ,
unsigned short V_9 )
{
struct V_1 * V_1 = V_2 ;
unsigned long V_10 = 0x10000 , V_11 ;
F_4 ( & V_12 ) ;
V_11 = F_1 () ;
if ( V_11 ) {
F_5 ( V_1 -> V_13 , L_1 ) ;
goto V_14;
}
F_6 ( V_1 -> V_3 + V_15 , V_16 | V_9 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_17 ) ;
V_11 |= ( V_18 | V_19 ) ;
F_6 ( V_1 -> V_3 + V_17 , V_11 ) ;
F_7 ( 100 ) ;
while ( ! ( F_2 ( V_1 -> V_3 + V_20 ) & V_21 )
&& V_10 -- )
F_8 ( 1 ) ;
if ( ! V_10 ) {
F_5 ( V_1 -> V_13 , L_2 ) ;
V_11 = - V_6 ;
goto V_14;
}
V_11 = F_2 ( V_1 -> V_3 + V_17 ) ;
V_11 &= ~ V_19 ;
F_6 ( V_1 -> V_3 + V_17 , V_11 ) ;
if ( F_2 ( V_1 -> V_3 + V_22 ) >> 2 != V_9 ) {
F_5 ( V_1 -> V_13 ,
L_3 ) ;
}
F_7 ( 100 ) ;
V_11 = ( F_2 ( V_1 -> V_3 + V_23 ) & 0xFFFF ) ;
V_14:
F_9 ( & V_12 ) ;
return V_11 ;
}
static void F_10 ( struct V_7 * V_8 , unsigned short V_9 ,
unsigned short V_11 )
{
struct V_1 * V_1 = V_2 ;
unsigned long V_24 , V_10 = 0x10000 ;
F_4 ( & V_12 ) ;
V_24 = F_1 () ;
if ( V_24 )
F_5 ( V_1 -> V_13 , L_1 ) ;
F_6 ( V_1 -> V_3 + V_15 , V_9 ) ;
F_6 ( V_1 -> V_3 + V_25 , V_11 ) ;
V_24 = F_2 ( V_1 -> V_3 + V_17 ) ;
V_24 |= V_19 | V_26 | V_18 ;
F_6 ( V_1 -> V_3 + V_17 , V_24 ) ;
F_7 ( 100 ) ;
while ( ( F_2 ( V_1 -> V_3 + V_20 ) & V_27 )
&& V_10 -- )
F_8 ( 1 ) ;
if ( ! V_10 )
F_5 ( V_1 -> V_13 , L_4 ) ;
V_24 = F_2 ( V_1 -> V_3 + V_17 ) ;
V_24 &= ~ ( V_19 | V_26 ) ;
F_6 ( V_1 -> V_3 + V_17 , V_24 ) ;
F_9 ( & V_12 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = V_2 ;
unsigned long V_11 ;
F_4 ( & V_12 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_20 ) ;
V_11 |= V_28 ;
F_6 ( V_1 -> V_3 + V_20 , V_11 ) ;
F_7 ( 100 ) ;
V_11 = F_1 () ;
if ( V_11 )
F_5 ( V_1 -> V_13 , L_1 ) ;
F_9 ( & V_12 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = V_2 ;
unsigned long V_11 ;
F_4 ( & V_12 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_29 ) ;
V_11 |= V_30 ;
F_6 ( V_1 -> V_3 + V_29 , V_11 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_29 ) ;
V_11 &= ( ~ V_30 ) ;
F_6 ( V_1 -> V_3 + V_29 , V_11 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_29 ) ;
V_11 |= V_31 ;
F_6 ( V_1 -> V_3 + V_29 , V_11 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_29 ) ;
V_11 &= ~ V_31 ;
F_6 ( V_1 -> V_3 + V_29 , V_11 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_20 ) ;
V_11 |= V_32 ;
F_6 ( V_1 -> V_3 + V_20 , V_11 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_20 ) ;
V_11 &= ( ~ V_32 ) ;
F_6 ( V_1 -> V_3 + V_20 , V_11 ) ;
F_7 ( 100 ) ;
F_9 ( & V_12 ) ;
}
static int F_13 ( struct V_33 * V_34 ,
int V_35 , struct V_36 * V_37 )
{
struct V_1 * V_1 = V_2 ;
int V_38 ;
unsigned long V_11 , V_24 ;
V_38 = 0 ;
switch ( V_35 ) {
case V_39 :
case V_40 :
V_11 = F_2 ( V_1 -> V_3 + V_29 ) ;
if ( V_34 -> V_41 == V_42 ) {
V_24 = F_2 ( V_1 -> V_3 + V_17 ) ;
V_24 |= ( V_43 | V_44 | V_18 ) ;
F_6 ( V_1 -> V_3 + V_17 , V_24 ) ;
V_24 = F_2 ( V_1 -> V_3 + V_45 ) ;
V_24 |= ( V_46 | V_47 ) ;
F_6 ( V_1 -> V_3 + V_45 , V_24 ) ;
V_11 |= V_48 ;
} else {
V_24 = F_2 ( V_1 -> V_3 + V_49 ) ;
V_24 |= ( V_50 | V_51 ) ;
F_6 ( V_1 -> V_3 + V_49 , V_24 ) ;
V_11 |= V_52 ;
}
F_6 ( V_1 -> V_3 + V_29 , V_11 ) ;
break;
case V_53 :
case V_54 :
V_11 = F_2 ( V_1 -> V_3 + V_29 ) ;
if ( V_34 -> V_41 == V_42 ) {
V_24 = F_2 ( V_1 -> V_3 + V_17 ) ;
V_24 &= ~ ( V_43 | V_44 ) ;
F_6 ( V_1 -> V_3 + V_17 , V_24 ) ;
F_6 ( V_1 -> V_3 + V_45 , V_55 ) ;
V_11 &= ~ V_48 ;
} else {
F_6 ( V_1 -> V_3 + V_49 , V_55 ) ;
V_11 &= ~ V_52 ;
}
F_6 ( V_1 -> V_3 + V_29 , V_11 ) ;
break;
default:
V_38 = - V_56 ;
}
return V_38 ;
}
static int F_14 ( struct V_36 * V_37 )
{
struct V_1 * V_1 = V_2 ;
unsigned long V_11 ;
F_4 ( & V_12 ) ;
F_15 ( V_1 -> V_57 ) ;
V_11 = F_2 ( V_1 -> V_3 + V_58 ) ;
V_11 |= ( V_59 | V_60 ) ;
F_6 ( V_1 -> V_3 + V_58 , V_11 ) ;
F_9 ( & V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_36 * V_37 )
{
struct V_1 * V_1 = V_2 ;
F_17 ( V_1 -> V_57 ) ;
return 0 ;
}
static int T_1 F_18 ( struct V_61 * V_62 )
{
struct V_1 * V_1 ;
int V_38 ;
if ( V_2 )
return - V_63 ;
V_1 = F_19 ( sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_1 )
return - V_65 ;
F_20 ( & V_1 -> V_66 ) ;
V_1 -> V_67 = F_21 ( V_62 , V_68 , 0 ) ;
if ( ! V_1 -> V_67 ) {
V_38 = - V_69 ;
goto V_70;
}
if ( ! F_22 ( V_1 -> V_67 -> V_71 ,
F_23 ( V_1 -> V_67 ) , V_62 -> V_72 ) ) {
V_38 = - V_63 ;
goto V_70;
}
V_1 -> V_3 = F_24 ( V_1 -> V_67 -> V_71 ,
F_23 ( V_1 -> V_67 ) ) ;
if ( ! V_1 -> V_3 ) {
V_38 = - V_65 ;
goto V_73;
}
V_1 -> V_57 = F_25 ( & V_62 -> V_13 , NULL ) ;
if ( F_26 ( V_1 -> V_57 ) ) {
V_38 = F_27 ( V_1 -> V_57 ) ;
goto V_74;
}
V_1 -> V_75 = F_28 ( V_62 , 0 ) ;
if ( ! V_1 -> V_75 ) {
V_38 = - V_63 ;
goto V_76;
}
V_2 = V_1 ;
V_38 = F_29 ( & V_62 -> V_13 , & V_77 ) ;
if ( V_38 )
goto V_76;
F_30 ( V_1 -> V_13 , L_5 ) ;
return 0 ;
V_76:
F_31 ( V_1 -> V_57 ) ;
V_74:
F_32 ( V_1 -> V_3 ) ;
V_73:
F_33 ( V_1 -> V_67 -> V_71 ,
F_23 ( V_1 -> V_67 ) ) ;
V_70:
F_34 ( V_1 ) ;
return V_38 ;
}
static int T_2 F_35 ( struct V_61 * V_62 )
{
F_36 ( & V_62 -> V_13 ) ;
F_31 ( V_2 -> V_57 ) ;
F_32 ( V_2 -> V_3 ) ;
F_33 ( V_2 -> V_67 -> V_71 ,
F_23 ( V_2 -> V_67 ) ) ;
F_34 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_78 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_78 ) ;
}
