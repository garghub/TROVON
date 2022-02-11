int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
int T_1 F_3 ( unsigned int V_2 , unsigned int V_3 )
{
V_4 . V_5 = V_2 > 510 ? 255 : V_2 / 2 ;
V_4 . V_3 = ( V_3 + 1 ) / 2 ;
return F_2 ( & V_6 ) ;
}
int T_1 F_4 ( struct V_7 * V_8 )
{
V_9 . V_10 . V_11 = V_8 ;
return F_2 ( & V_9 ) ;
}
int T_1 F_5 ( int V_12 )
{
int V_13 ;
V_14 . V_12 = V_12 ;
V_13 = F_6 ( & V_14 ) ;
if ( V_13 )
return V_13 ;
F_7 ( & V_15 ) ;
return 0 ;
}
static void F_8 ( struct V_16 * V_16 )
{
T_2 V_17 ;
T_2 V_18 = 500000 ;
V_17 = F_9 ( F_10 ( V_19 ) ) ;
F_11 ( V_20 ) ;
V_17 &= ~ ( V_21 | V_22 ) ;
V_17 |= V_23 ;
F_12 ( V_17 , F_10 ( V_19 ) ) ;
while ( -- V_18 ) {
V_17 = F_9 ( F_10 ( V_19 ) ) ;
if ( V_17 & V_24 )
goto V_25;
F_13 ( 1 ) ;
}
F_14 ( L_1 ) ;
V_25:
F_15 ( V_20 ) ;
}
static void F_16 ( struct V_16 * V_16 )
{
T_2 V_17 ;
V_17 = F_9 ( F_10 ( V_19 ) ) ;
V_17 |= V_22 ;
F_12 ( V_17 , F_10 ( V_19 ) ) ;
}
static int F_17 ( struct V_16 * V_16 , struct V_16 * V_26 )
{
T_2 V_17 ;
V_17 = F_9 ( F_10 ( V_19 ) ) ;
if ( V_26 == & V_14 ) {
V_17 &= ~ V_27 ;
} else if ( strcmp ( V_26 -> V_28 , L_2 ) == 0 ) {
V_17 |= V_27 ;
} else {
F_14 ( L_3 ) ;
return - V_29 ;
}
V_17 &= ~ V_30 ;
switch ( F_18 ( V_26 ) ) {
case 12000000 :
V_17 |= V_31 ;
break;
case 13000000 :
V_17 |= V_32 ;
break;
case 19200000 :
V_17 |= V_33 ;
break;
case 20000000 :
V_17 |= V_34 ;
break;
case 24000000 :
V_17 |= V_35 ;
break;
case 26000000 :
V_17 |= V_36 ;
break;
case 38400000 :
V_17 |= V_37 ;
break;
case 40000000 :
V_17 |= V_38 ;
break;
case 48000000 :
V_17 |= V_39 ;
break;
default:
F_14 ( L_4 ) ;
return - V_29 ;
}
F_12 ( V_17 , F_10 ( V_19 ) ) ;
return 0 ;
}
int T_1 F_19 ( bool V_40 )
{
struct V_16 * V_26 ;
int V_13 ;
V_20 = F_20 ( & V_6 . V_10 , L_5 ) ;
V_13 = F_21 ( V_20 ) ;
if ( V_13 )
return V_13 ;
V_26 = F_20 ( NULL , V_40 ? L_6 : L_7 ) ;
V_13 = F_21 ( V_26 ) ;
if ( V_13 ) {
F_22 ( V_20 ) ;
return V_13 ;
}
V_41 . V_26 = V_26 ;
V_13 = F_6 ( & V_41 ) ;
if ( ! V_13 )
F_7 ( & V_42 ) ;
F_22 ( V_26 ) ;
return V_13 ;
}
static int F_23 ( struct V_16 * V_16 , struct V_16 * V_26 )
{
T_2 V_17 ;
V_17 = F_9 ( F_10 ( V_19 ) ) ;
if ( V_26 == & V_41 ) {
V_17 &= ~ V_43 ;
} else if ( V_26 == & V_14 ) {
V_17 |= V_43 ;
} else {
F_14 ( L_8 ) ;
return - V_29 ;
}
F_12 ( V_17 , F_10 ( V_19 ) ) ;
return 0 ;
}
int T_1 F_24 ( bool V_40 )
{
struct V_16 * V_26 ;
int V_13 = 0 ;
if ( V_40 )
V_26 = F_20 ( NULL , L_6 ) ;
else
V_26 = F_20 ( & V_1 . V_10 , L_9 ) ;
if ( F_25 ( V_26 ) )
return F_26 ( V_26 ) ;
V_44 . V_26 = V_26 ;
V_13 = F_6 ( & V_44 ) ;
if ( ! V_13 )
F_7 ( & V_45 ) ;
F_22 ( V_26 ) ;
return V_13 ;
}
