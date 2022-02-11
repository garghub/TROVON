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
V_2 -> V_16 = 1 ;
V_15 = F_6 ( V_14 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_7 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_8 ( V_14 ) ;
F_9 ( V_14 , 0 ) ;
return V_15 ;
}
static void T_1
F_10 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_2 ( F_11 ( V_19 ) , 0 ) ;
F_2 ( F_12 ( V_19 ) , 0 ) ;
}
for ( V_19 = 0 ; V_19 < V_18 -> V_20 ; V_19 ++ ) {
const struct V_21 * V_22 = V_18 -> V_22 + V_19 ;
F_2 ( F_11 ( V_19 ) , ( ( V_22 -> V_23 - 1 ) & 0xffff0000 ) |
( V_22 -> V_24 << 8 ) |
( V_18 -> V_25 << 4 ) | 1 ) ;
F_2 ( F_12 ( V_19 ) , V_22 -> V_26 ) ;
}
}
static int T_2 F_13 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 . V_32 ;
const struct V_17 * V_18 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
void T_3 * V_35 ;
int V_36 , V_37 ;
if ( F_14 () )
return - V_38 ;
F_15 ( L_1 ) ;
V_36 = F_16 ( V_28 , 0 ) ;
if ( V_36 <= 0 ) {
F_17 ( & V_28 -> V_31 ,
L_2 ,
F_18 ( & V_28 -> V_31 ) ) ;
V_37 = - V_38 ;
goto V_39;
}
V_34 = F_19 ( V_28 , V_40 , 0 ) ;
if ( ! V_34 ) {
F_17 ( & V_28 -> V_31 ,
L_3 ,
F_18 ( & V_28 -> V_31 ) ) ;
V_37 = - V_38 ;
goto V_39;
}
if ( ! F_20 ( V_34 -> V_41 , F_21 ( V_34 ) ,
V_42 . V_43 ) ) {
F_22 ( & V_28 -> V_31 , L_4 ) ;
V_37 = - V_44 ;
goto V_39;
}
V_35 = F_23 ( V_34 -> V_41 , F_21 ( V_34 ) ) ;
if ( V_35 == NULL ) {
F_22 ( & V_28 -> V_31 , L_5 ) ;
V_37 = - V_45 ;
goto V_46;
}
V_2 = F_24 ( & V_42 ,
& V_28 -> V_31 , F_18 ( & V_28 -> V_31 ) ) ;
if ( ! V_2 ) {
V_37 = - V_47 ;
goto V_48;
}
V_2 -> V_49 = V_34 -> V_41 ;
V_2 -> V_50 = F_21 ( V_34 ) ;
V_2 -> V_35 = V_35 ;
V_14 = F_5 ( V_2 ) ;
V_14 -> V_51 = V_2 -> V_35 + 0x100 ;
V_14 -> V_35 = V_2 -> V_35 + 0x100 +
F_25 ( V_14 , F_26 ( V_14 , & V_14 -> V_51 -> V_52 ) ) ;
V_14 -> V_53 = F_26 ( V_14 , & V_14 -> V_51 -> V_53 ) ;
V_2 -> V_16 = 1 ;
V_14 -> V_54 = 0x20 ;
V_18 = F_27 () ;
if ( V_18 )
F_10 ( V_2 , V_18 ) ;
switch ( V_30 -> V_55 ) {
case V_56 :
break;
case V_57 :
F_1 ( V_2 ) ;
break;
case V_58 :
case V_59 :
default:
F_28 ( V_60 L_6 ) ;
}
V_37 = F_29 ( V_2 , V_36 , V_61 ) ;
if ( V_37 )
goto V_62;
return 0 ;
V_62:
F_30 ( V_2 ) ;
V_48:
F_31 ( V_35 ) ;
V_46:
F_32 ( V_34 -> V_41 , F_21 ( V_34 ) ) ;
V_39:
F_17 ( & V_28 -> V_31 , L_7 ,
F_18 ( & V_28 -> V_31 ) , V_37 ) ;
return V_37 ;
}
static int T_4 F_33 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_34 ( V_28 ) ;
F_35 ( V_2 ) ;
F_31 ( V_2 -> V_35 ) ;
F_32 ( V_2 -> V_49 , V_2 -> V_50 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
