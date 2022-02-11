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
static int F_7 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_29 . V_30 ;
int V_31 ;
V_31 = F_8 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( F_9 ( V_28 -> V_32 , L_1 ) )
F_2 ( V_33 , V_34 ) ;
return V_31 ;
}
static int F_10 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_11 ( & V_36 -> V_28 ) ;
const struct V_17 * V_18 ;
struct V_39 * V_40 ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
void T_1 * V_43 ;
int V_44 , V_45 ;
enum V_46 V_47 ;
struct V_48 * V_49 ;
if ( F_12 () )
return - V_50 ;
F_13 ( L_2 ) ;
V_44 = F_14 ( V_36 , 0 ) ;
if ( V_44 <= 0 ) {
F_15 ( & V_36 -> V_28 ,
L_3 ,
F_16 ( & V_36 -> V_28 ) ) ;
V_45 = - V_50 ;
goto V_45;
}
V_45 = F_17 ( & V_36 -> V_28 , F_18 ( 32 ) ) ;
if ( V_45 )
goto V_45;
V_40 = F_19 ( V_36 , V_51 , 0 ) ;
V_43 = F_20 ( & V_36 -> V_28 , V_40 ) ;
if ( F_21 ( V_43 ) ) {
V_45 = F_22 ( V_43 ) ;
goto V_45;
}
V_2 = F_23 ( & V_52 ,
& V_36 -> V_28 , F_16 ( & V_36 -> V_28 ) ) ;
if ( ! V_2 ) {
V_45 = - V_53 ;
goto V_45;
}
V_2 -> V_54 = V_40 -> V_55 ;
V_2 -> V_56 = F_24 ( V_40 ) ;
V_2 -> V_43 = V_43 ;
V_42 = F_25 ( V_2 ) ;
V_42 -> V_57 = V_2 -> V_43 + 0x100 ;
V_2 -> V_58 = 1 ;
V_49 = F_26 ( V_2 ) ;
V_49 -> V_59 = F_27 ( & V_36 -> V_28 , NULL ) ;
if ( ! F_21 ( V_49 -> V_59 ) )
F_28 ( V_49 -> V_59 ) ;
V_49 -> V_60 = F_29 ( & V_36 -> V_28 , L_4 ) ;
if ( F_21 ( V_49 -> V_60 ) ) {
V_45 = F_22 ( V_49 -> V_60 ) ;
if ( V_45 != - V_61 )
goto V_62;
} else {
V_45 = F_30 ( V_49 -> V_60 ) ;
if ( V_45 )
goto V_63;
V_45 = F_31 ( V_49 -> V_60 ) ;
if ( V_45 )
goto V_64;
}
V_18 = F_32 () ;
if ( V_18 )
F_4 ( V_2 , V_18 ) ;
if ( V_36 -> V_28 . V_32 )
V_47 = V_65 ;
else
V_47 = V_38 -> V_47 ;
switch ( V_47 ) {
case V_65 :
break;
case V_66 :
F_1 ( V_2 ) ;
break;
case V_67 :
case V_68 :
default:
F_33 ( & V_36 -> V_28 , L_5 ) ;
}
V_45 = F_34 ( V_2 , V_44 , V_69 ) ;
if ( V_45 )
goto V_70;
F_35 ( V_2 -> V_29 . V_30 ) ;
return 0 ;
V_70:
if ( ! F_21 ( V_49 -> V_60 ) )
F_36 ( V_49 -> V_60 ) ;
V_64:
if ( ! F_21 ( V_49 -> V_60 ) )
F_37 ( V_49 -> V_60 ) ;
V_63:
V_62:
if ( ! F_21 ( V_49 -> V_59 ) )
F_38 ( V_49 -> V_59 ) ;
F_39 ( V_2 ) ;
V_45:
F_15 ( & V_36 -> V_28 , L_6 ,
F_16 ( & V_36 -> V_28 ) , V_45 ) ;
return V_45 ;
}
static int F_40 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_41 ( V_36 ) ;
struct V_48 * V_49 = F_26 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( ! F_21 ( V_49 -> V_60 ) ) {
F_36 ( V_49 -> V_60 ) ;
F_37 ( V_49 -> V_60 ) ;
}
if ( ! F_21 ( V_49 -> V_59 ) )
F_38 ( V_49 -> V_59 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int T_2 F_43 ( void )
{
if ( F_12 () )
return - V_50 ;
F_44 ( L_7 V_71 L_8 , V_72 ) ;
F_45 ( & V_52 , & V_73 ) ;
return F_46 ( & V_74 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_74 ) ;
}
