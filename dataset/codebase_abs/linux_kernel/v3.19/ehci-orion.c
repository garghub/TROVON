static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
F_2 ( V_5 , F_3 ( V_5 ) | 0x2 ) ;
while ( F_3 ( V_5 ) & 0x2 ) ;
F_2 ( V_6 , ( F_3 ( V_6 ) & ~ 0x7f00 ) | 0xc00 ) ;
F_2 ( V_7 , ( F_3 ( V_7 ) & ~ 0xc0 ) | 0x40 ) ;
F_2 ( V_8 , ( F_3 ( V_8 ) & ~ 0x78 ) | 0x202040 ) ;
F_2 ( V_9 , ( F_3 ( V_9 ) & ~ 0xc2003f0 ) | 0xc0000010 ) ;
F_2 ( V_10 , ( F_3 ( V_10 ) & ~ 0x80003 ) | 0x32 ) ;
F_2 ( V_11 , F_3 ( V_11 ) & ~ 0x8000 ) ;
F_2 ( V_5 , F_3 ( V_5 ) & ~ 0x1 ) ;
F_2 ( V_5 , F_3 ( V_5 ) | 0x2 ) ;
while ( F_3 ( V_5 ) & 0x2 ) ;
F_2 ( V_12 , 0x13 ) ;
}
static void
F_4 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
F_2 ( F_5 ( V_15 ) , 0 ) ;
F_2 ( F_6 ( V_15 ) , 0 ) ;
}
for ( V_15 = 0 ; V_15 < V_14 -> V_16 ; V_15 ++ ) {
const struct V_17 * V_18 = V_14 -> V_18 + V_15 ;
F_2 ( F_5 ( V_15 ) , ( ( V_18 -> V_19 - 1 ) & 0xffff0000 ) |
( V_18 -> V_20 << 8 ) |
( V_14 -> V_21 << 4 ) | 1 ) ;
F_2 ( F_6 ( V_15 ) , V_18 -> V_22 ) ;
}
}
static int F_7 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_8 ( & V_24 -> V_27 ) ;
const struct V_13 * V_14 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
void T_1 * V_32 ;
int V_33 , V_34 ;
enum V_35 V_36 ;
struct V_37 * V_38 ;
if ( F_9 () )
return - V_39 ;
F_10 ( L_1 ) ;
V_33 = F_11 ( V_24 , 0 ) ;
if ( V_33 <= 0 ) {
F_12 ( & V_24 -> V_27 ,
L_2 ,
F_13 ( & V_24 -> V_27 ) ) ;
V_34 = - V_39 ;
goto V_34;
}
V_34 = F_14 ( & V_24 -> V_27 , F_15 ( 32 ) ) ;
if ( V_34 )
goto V_34;
V_29 = F_16 ( V_24 , V_40 , 0 ) ;
V_32 = F_17 ( & V_24 -> V_27 , V_29 ) ;
if ( F_18 ( V_32 ) ) {
V_34 = F_19 ( V_32 ) ;
goto V_34;
}
V_2 = F_20 ( & V_41 ,
& V_24 -> V_27 , F_13 ( & V_24 -> V_27 ) ) ;
if ( ! V_2 ) {
V_34 = - V_42 ;
goto V_34;
}
V_2 -> V_43 = V_29 -> V_44 ;
V_2 -> V_45 = F_21 ( V_29 ) ;
V_2 -> V_32 = V_32 ;
V_31 = F_22 ( V_2 ) ;
V_31 -> V_46 = V_2 -> V_32 + 0x100 ;
V_2 -> V_47 = 1 ;
V_38 = F_23 ( V_2 ) ;
V_38 -> V_48 = F_24 ( & V_24 -> V_27 , NULL ) ;
if ( ! F_18 ( V_38 -> V_48 ) )
F_25 ( V_38 -> V_48 ) ;
V_38 -> V_49 = F_26 ( & V_24 -> V_27 , L_3 ) ;
if ( F_18 ( V_38 -> V_49 ) ) {
V_34 = F_19 ( V_38 -> V_49 ) ;
goto V_50;
} else {
V_34 = F_27 ( V_38 -> V_49 ) ;
if ( V_34 )
goto V_51;
V_34 = F_28 ( V_38 -> V_49 ) ;
if ( V_34 )
goto V_52;
}
V_14 = F_29 () ;
if ( V_14 )
F_4 ( V_2 , V_14 ) ;
if ( V_24 -> V_27 . V_53 )
V_36 = V_54 ;
else
V_36 = V_26 -> V_36 ;
switch ( V_36 ) {
case V_54 :
break;
case V_55 :
F_1 ( V_2 ) ;
break;
case V_56 :
case V_57 :
default:
F_30 ( & V_24 -> V_27 , L_4 ) ;
}
V_34 = F_31 ( V_2 , V_33 , V_58 ) ;
if ( V_34 )
goto V_59;
F_32 ( V_2 -> V_60 . V_61 ) ;
return 0 ;
V_59:
if ( ! F_18 ( V_38 -> V_49 ) )
F_33 ( V_38 -> V_49 ) ;
V_52:
if ( ! F_18 ( V_38 -> V_49 ) )
F_34 ( V_38 -> V_49 ) ;
V_51:
V_50:
if ( ! F_18 ( V_38 -> V_48 ) )
F_35 ( V_38 -> V_48 ) ;
F_36 ( V_2 ) ;
V_34:
F_12 ( & V_24 -> V_27 , L_5 ,
F_13 ( & V_24 -> V_27 ) , V_34 ) ;
return V_34 ;
}
static int F_37 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_38 ( V_24 ) ;
struct V_37 * V_38 = F_23 ( V_2 ) ;
F_39 ( V_2 ) ;
if ( ! F_18 ( V_38 -> V_49 ) ) {
F_33 ( V_38 -> V_49 ) ;
F_34 ( V_38 -> V_49 ) ;
}
if ( ! F_18 ( V_38 -> V_48 ) )
F_35 ( V_38 -> V_48 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
if ( F_9 () )
return - V_39 ;
F_41 ( L_6 V_62 L_7 , V_63 ) ;
F_42 ( & V_41 , & V_64 ) ;
return F_43 ( & V_65 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_65 ) ;
}
