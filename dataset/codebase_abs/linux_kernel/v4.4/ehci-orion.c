static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
F_2 ( V_5 , F_3 ( V_5 ) | V_6 ) ;
while ( F_3 ( V_5 ) & V_6 ) ;
F_2 ( V_7 , ( F_3 ( V_7 ) & ~ 0x7f00 ) | 0xc00 ) ;
F_2 ( V_8 , ( F_3 ( V_8 ) & ~ 0xc0 ) | 0x40 ) ;
F_2 ( V_9 , ( F_3 ( V_9 ) & ~ 0x78 ) | 0x202040 ) ;
F_2 ( V_10 , ( F_3 ( V_10 ) & ~ 0xc2003f0 ) | 0xc0000010 ) ;
F_2 ( V_11 , ( F_3 ( V_11 ) & ~ 0x80003 ) | 0x32 ) ;
F_2 ( V_12 , F_3 ( V_12 ) & ~ 0x8000 ) ;
F_2 ( V_5 , F_3 ( V_5 ) & ~ V_13 ) ;
F_2 ( V_5 , F_3 ( V_5 ) | V_6 ) ;
while ( F_3 ( V_5 ) & V_6 ) ;
F_2 ( V_14 , V_15 | V_16 ) ;
}
static void
F_4 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_2 ( F_5 ( V_19 ) , 0 ) ;
F_2 ( F_6 ( V_19 ) , 0 ) ;
}
for ( V_19 = 0 ; V_19 < V_18 -> V_20 ; V_19 ++ ) {
const struct V_21 * V_22 = V_18 -> V_22 + V_19 ;
F_2 ( F_5 ( V_19 ) , ( ( V_22 -> V_23 - 1 ) & 0xffff0000 ) |
( V_22 -> V_24 << 8 ) |
( V_18 -> V_25 << 4 ) | 1 ) ;
F_2 ( F_6 ( V_19 ) , V_22 -> V_26 ) ;
}
}
static int F_7 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_8 ( & V_28 -> V_31 ) ;
const struct V_17 * V_18 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
void T_1 * V_36 ;
int V_37 , V_38 ;
enum V_39 V_40 ;
struct V_41 * V_42 ;
if ( F_9 () )
return - V_43 ;
F_10 ( L_1 ) ;
V_37 = F_11 ( V_28 , 0 ) ;
if ( V_37 <= 0 ) {
F_12 ( & V_28 -> V_31 ,
L_2 ,
F_13 ( & V_28 -> V_31 ) ) ;
V_38 = - V_43 ;
goto V_38;
}
V_38 = F_14 ( & V_28 -> V_31 , F_15 ( 32 ) ) ;
if ( V_38 )
goto V_38;
V_33 = F_16 ( V_28 , V_44 , 0 ) ;
V_36 = F_17 ( & V_28 -> V_31 , V_33 ) ;
if ( F_18 ( V_36 ) ) {
V_38 = F_19 ( V_36 ) ;
goto V_38;
}
V_2 = F_20 ( & V_45 ,
& V_28 -> V_31 , F_13 ( & V_28 -> V_31 ) ) ;
if ( ! V_2 ) {
V_38 = - V_46 ;
goto V_38;
}
V_2 -> V_47 = V_33 -> V_48 ;
V_2 -> V_49 = F_21 ( V_33 ) ;
V_2 -> V_36 = V_36 ;
V_35 = F_22 ( V_2 ) ;
V_35 -> V_50 = V_2 -> V_36 + 0x100 ;
V_2 -> V_51 = 1 ;
V_42 = F_23 ( V_2 ) ;
V_42 -> V_52 = F_24 ( & V_28 -> V_31 , NULL ) ;
if ( ! F_18 ( V_42 -> V_52 ) )
F_25 ( V_42 -> V_52 ) ;
V_42 -> V_53 = F_26 ( & V_28 -> V_31 , L_3 ) ;
if ( F_18 ( V_42 -> V_53 ) ) {
V_38 = F_19 ( V_42 -> V_53 ) ;
if ( V_38 != - V_54 )
goto V_55;
} else {
V_38 = F_27 ( V_42 -> V_53 ) ;
if ( V_38 )
goto V_56;
V_38 = F_28 ( V_42 -> V_53 ) ;
if ( V_38 )
goto V_57;
}
V_18 = F_29 () ;
if ( V_18 )
F_4 ( V_2 , V_18 ) ;
if ( V_28 -> V_31 . V_58 )
V_40 = V_59 ;
else
V_40 = V_30 -> V_40 ;
switch ( V_40 ) {
case V_59 :
break;
case V_60 :
F_1 ( V_2 ) ;
break;
case V_61 :
case V_62 :
default:
F_30 ( & V_28 -> V_31 , L_4 ) ;
}
V_38 = F_31 ( V_2 , V_37 , V_63 ) ;
if ( V_38 )
goto V_64;
F_32 ( V_2 -> V_65 . V_66 ) ;
return 0 ;
V_64:
if ( ! F_18 ( V_42 -> V_53 ) )
F_33 ( V_42 -> V_53 ) ;
V_57:
if ( ! F_18 ( V_42 -> V_53 ) )
F_34 ( V_42 -> V_53 ) ;
V_56:
V_55:
if ( ! F_18 ( V_42 -> V_52 ) )
F_35 ( V_42 -> V_52 ) ;
F_36 ( V_2 ) ;
V_38:
F_12 ( & V_28 -> V_31 , L_5 ,
F_13 ( & V_28 -> V_31 ) , V_38 ) ;
return V_38 ;
}
static int F_37 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_38 ( V_28 ) ;
struct V_41 * V_42 = F_23 ( V_2 ) ;
F_39 ( V_2 ) ;
if ( ! F_18 ( V_42 -> V_53 ) ) {
F_33 ( V_42 -> V_53 ) ;
F_34 ( V_42 -> V_53 ) ;
}
if ( ! F_18 ( V_42 -> V_52 ) )
F_35 ( V_42 -> V_52 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
if ( F_9 () )
return - V_43 ;
F_41 ( L_6 V_67 L_7 , V_68 ) ;
F_42 ( & V_45 , & V_69 ) ;
return F_43 ( & V_70 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_70 ) ;
}
