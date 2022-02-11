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
struct V_32 * V_32 ;
void T_1 * V_33 ;
int V_34 , V_35 ;
enum V_36 V_37 ;
if ( F_9 () )
return - V_38 ;
F_10 ( L_1 ) ;
if ( V_24 -> V_27 . V_39 )
V_34 = F_11 ( V_24 -> V_27 . V_39 , 0 ) ;
else
V_34 = F_12 ( V_24 , 0 ) ;
if ( V_34 <= 0 ) {
F_13 ( & V_24 -> V_27 ,
L_2 ,
F_14 ( & V_24 -> V_27 ) ) ;
V_35 = - V_38 ;
goto V_40;
}
V_29 = F_15 ( V_24 , V_41 , 0 ) ;
if ( ! V_29 ) {
F_13 ( & V_24 -> V_27 ,
L_3 ,
F_14 ( & V_24 -> V_27 ) ) ;
V_35 = - V_38 ;
goto V_40;
}
V_35 = F_16 ( & V_24 -> V_27 , F_17 ( 32 ) ) ;
if ( V_35 )
goto V_40;
if ( ! F_18 ( V_29 -> V_42 , F_19 ( V_29 ) ,
V_43 . V_44 ) ) {
F_20 ( & V_24 -> V_27 , L_4 ) ;
V_35 = - V_45 ;
goto V_40;
}
V_33 = F_21 ( V_29 -> V_42 , F_19 ( V_29 ) ) ;
if ( V_33 == NULL ) {
F_20 ( & V_24 -> V_27 , L_5 ) ;
V_35 = - V_46 ;
goto V_47;
}
V_32 = F_22 ( & V_24 -> V_27 , NULL ) ;
if ( ! F_23 ( V_32 ) ) {
F_24 ( V_32 ) ;
F_25 ( V_32 ) ;
}
V_2 = F_26 ( & V_43 ,
& V_24 -> V_27 , F_14 ( & V_24 -> V_27 ) ) ;
if ( ! V_2 ) {
V_35 = - V_48 ;
goto V_49;
}
V_2 -> V_50 = V_29 -> V_42 ;
V_2 -> V_51 = F_19 ( V_29 ) ;
V_2 -> V_33 = V_33 ;
V_31 = F_27 ( V_2 ) ;
V_31 -> V_52 = V_2 -> V_33 + 0x100 ;
V_2 -> V_53 = 1 ;
V_14 = F_28 () ;
if ( V_14 )
F_4 ( V_2 , V_14 ) ;
if ( V_24 -> V_27 . V_39 )
V_37 = V_54 ;
else
V_37 = V_26 -> V_37 ;
switch ( V_37 ) {
case V_54 :
break;
case V_55 :
F_1 ( V_2 ) ;
break;
case V_56 :
case V_57 :
default:
F_29 ( V_58 L_6 ) ;
}
V_35 = F_30 ( V_2 , V_34 , V_59 ) ;
if ( V_35 )
goto V_60;
return 0 ;
V_60:
F_31 ( V_2 ) ;
V_49:
if ( ! F_23 ( V_32 ) ) {
F_32 ( V_32 ) ;
F_25 ( V_32 ) ;
}
F_33 ( V_33 ) ;
V_47:
F_34 ( V_29 -> V_42 , F_19 ( V_29 ) ) ;
V_40:
F_13 ( & V_24 -> V_27 , L_7 ,
F_14 ( & V_24 -> V_27 ) , V_35 ) ;
return V_35 ;
}
static int F_35 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_36 ( V_24 ) ;
struct V_32 * V_32 ;
F_37 ( V_2 ) ;
F_33 ( V_2 -> V_33 ) ;
F_34 ( V_2 -> V_50 , V_2 -> V_51 ) ;
F_31 ( V_2 ) ;
V_32 = F_22 ( & V_24 -> V_27 , NULL ) ;
if ( ! F_23 ( V_32 ) ) {
F_32 ( V_32 ) ;
F_25 ( V_32 ) ;
}
return 0 ;
}
static int T_2 F_38 ( void )
{
if ( F_9 () )
return - V_38 ;
F_39 ( L_8 V_61 L_9 , V_62 ) ;
F_40 ( & V_43 , NULL ) ;
return F_41 ( & V_63 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_63 ) ;
}
