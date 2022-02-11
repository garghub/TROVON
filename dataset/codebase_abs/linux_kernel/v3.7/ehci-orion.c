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
static int F_4 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
int V_15 ;
V_15 = F_6 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_7 ( V_14 , 0 ) ;
return V_15 ;
}
static void T_1
F_8 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
F_2 ( F_9 ( V_18 ) , 0 ) ;
F_2 ( F_10 ( V_18 ) , 0 ) ;
}
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
const struct V_20 * V_21 = V_17 -> V_21 + V_18 ;
F_2 ( F_9 ( V_18 ) , ( ( V_21 -> V_22 - 1 ) & 0xffff0000 ) |
( V_21 -> V_23 << 8 ) |
( V_17 -> V_24 << 4 ) | 1 ) ;
F_2 ( F_10 ( V_18 ) , V_21 -> V_25 ) ;
}
}
static int T_1 F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 . V_31 ;
const struct V_16 * V_17 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_34 * V_34 ;
void T_2 * V_35 ;
int V_36 , V_37 ;
if ( F_12 () )
return - V_38 ;
F_13 ( L_1 ) ;
V_36 = F_14 ( V_27 , 0 ) ;
if ( V_36 <= 0 ) {
F_15 ( & V_27 -> V_30 ,
L_2 ,
F_16 ( & V_27 -> V_30 ) ) ;
V_37 = - V_38 ;
goto V_39;
}
V_33 = F_17 ( V_27 , V_40 , 0 ) ;
if ( ! V_33 ) {
F_15 ( & V_27 -> V_30 ,
L_3 ,
F_16 ( & V_27 -> V_30 ) ) ;
V_37 = - V_38 ;
goto V_39;
}
if ( ! F_18 ( V_33 -> V_41 , F_19 ( V_33 ) ,
V_42 . V_43 ) ) {
F_20 ( & V_27 -> V_30 , L_4 ) ;
V_37 = - V_44 ;
goto V_39;
}
V_35 = F_21 ( V_33 -> V_41 , F_19 ( V_33 ) ) ;
if ( V_35 == NULL ) {
F_20 ( & V_27 -> V_30 , L_5 ) ;
V_37 = - V_45 ;
goto V_46;
}
V_34 = F_22 ( & V_27 -> V_30 , NULL ) ;
if ( ! F_23 ( V_34 ) ) {
F_24 ( V_34 ) ;
F_25 ( V_34 ) ;
}
V_2 = F_26 ( & V_42 ,
& V_27 -> V_30 , F_16 ( & V_27 -> V_30 ) ) ;
if ( ! V_2 ) {
V_37 = - V_47 ;
goto V_48;
}
V_2 -> V_49 = V_33 -> V_41 ;
V_2 -> V_50 = F_19 ( V_33 ) ;
V_2 -> V_35 = V_35 ;
V_14 = F_5 ( V_2 ) ;
V_14 -> V_51 = V_2 -> V_35 + 0x100 ;
V_2 -> V_52 = 1 ;
V_17 = F_27 () ;
if ( V_17 )
F_8 ( V_2 , V_17 ) ;
switch ( V_29 -> V_53 ) {
case V_54 :
break;
case V_55 :
F_1 ( V_2 ) ;
break;
case V_56 :
case V_57 :
default:
F_28 ( V_58 L_6 ) ;
}
V_37 = F_29 ( V_2 , V_36 , V_59 ) ;
if ( V_37 )
goto V_60;
return 0 ;
V_60:
F_30 ( V_2 ) ;
V_48:
if ( ! F_23 ( V_34 ) ) {
F_31 ( V_34 ) ;
F_25 ( V_34 ) ;
}
F_32 ( V_35 ) ;
V_46:
F_33 ( V_33 -> V_41 , F_19 ( V_33 ) ) ;
V_39:
F_15 ( & V_27 -> V_30 , L_7 ,
F_16 ( & V_27 -> V_30 ) , V_37 ) ;
return V_37 ;
}
static int T_3 F_34 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_35 ( V_27 ) ;
struct V_34 * V_34 ;
F_36 ( V_2 ) ;
F_32 ( V_2 -> V_35 ) ;
F_33 ( V_2 -> V_49 , V_2 -> V_50 ) ;
F_30 ( V_2 ) ;
V_34 = F_22 ( & V_27 -> V_30 , NULL ) ;
if ( ! F_23 ( V_34 ) ) {
F_31 ( V_34 ) ;
F_25 ( V_34 ) ;
}
return 0 ;
}
