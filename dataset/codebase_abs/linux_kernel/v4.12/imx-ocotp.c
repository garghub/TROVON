static int F_1 ( void T_1 * V_1 , T_2 V_2 )
{
int V_3 ;
T_2 V_4 , V_5 ;
V_5 = V_6 | V_7 | V_2 ;
for ( V_3 = 10000 ; V_3 >= 0 ; V_3 -- ) {
V_4 = F_2 ( V_1 + V_8 ) ;
if ( ! ( V_4 & V_5 ) )
break;
F_3 () ;
}
if ( V_3 < 0 ) {
if ( V_4 & V_7 )
return - V_9 ;
return - V_10 ;
}
return 0 ;
}
static void F_4 ( void T_1 * V_1 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + V_8 ) ;
if ( ! ( V_4 & V_7 ) )
return;
F_5 ( V_7 , V_1 + V_11 ) ;
}
static int F_6 ( void * V_12 , unsigned int V_13 ,
void * V_14 , T_3 V_15 )
{
struct V_16 * V_17 = V_12 ;
unsigned int V_3 ;
T_2 * V_18 = V_14 ;
int V_19 , V_20 ;
T_2 V_21 ;
V_21 = V_13 >> 2 ;
V_3 = V_15 >> 2 ;
if ( V_3 > ( V_17 -> V_22 - V_21 ) )
V_3 = V_17 -> V_22 - V_21 ;
F_7 ( & V_23 ) ;
V_20 = F_8 ( V_17 -> V_24 ) ;
if ( V_20 < 0 ) {
F_9 ( & V_23 ) ;
F_10 ( V_17 -> V_25 , L_1 ) ;
return V_20 ;
}
V_20 = F_1 ( V_17 -> V_1 , 0 ) ;
if ( V_20 < 0 ) {
F_10 ( V_17 -> V_25 , L_2 ) ;
goto V_26;
}
for ( V_19 = V_21 ; V_19 < ( V_21 + V_3 ) ; V_19 ++ ) {
* V_18 ++ = F_2 ( V_17 -> V_1 + V_27 +
V_19 * V_28 ) ;
if ( * ( V_18 - 1 ) == V_29 )
F_4 ( V_17 -> V_1 ) ;
}
V_20 = 0 ;
V_26:
F_11 ( V_17 -> V_24 ) ;
F_9 ( & V_23 ) ;
return V_20 ;
}
static int F_12 ( void * V_12 , unsigned int V_13 , void * V_14 ,
T_3 V_15 )
{
struct V_16 * V_17 = V_12 ;
T_2 * V_18 = V_14 ;
int V_20 ;
unsigned long V_30 = 0 ;
unsigned long V_31 , V_32 , V_33 ;
T_2 V_34 = 0 ;
T_2 V_35 ;
T_4 V_36 ;
if ( ( V_15 != V_17 -> V_37 -> V_38 ) ||
( V_13 % V_17 -> V_37 -> V_38 ) )
return - V_39 ;
F_7 ( & V_23 ) ;
V_20 = F_8 ( V_17 -> V_24 ) ;
if ( V_20 < 0 ) {
F_9 ( & V_23 ) ;
F_10 ( V_17 -> V_25 , L_1 ) ;
return V_20 ;
}
V_30 = F_13 ( V_17 -> V_24 ) ;
V_32 = V_30 / ( 1000000000 / V_40 ) - 1 ;
V_33 = V_30 / ( 1000000000 / 10000 ) + 2 * ( V_40 + 1 ) - 1 ;
V_31 = V_30 / ( 1000000000 / 40 ) + 2 * ( V_40 + 1 ) - 1 ;
V_34 = V_33 & 0x00000FFF ;
V_34 |= ( V_32 << 12 ) & 0x0000F000 ;
V_34 |= ( V_31 << 16 ) & 0x003F0000 ;
F_5 ( V_34 , V_17 -> V_1 + V_41 ) ;
V_20 = F_1 ( V_17 -> V_1 , 0 ) ;
if ( V_20 < 0 ) {
F_10 ( V_17 -> V_25 , L_3 ) ;
goto V_42;
}
V_36 = V_13 / 4 ;
V_35 = F_2 ( V_17 -> V_1 + V_8 ) ;
V_35 &= ~ V_43 ;
V_35 |= V_36 & V_43 ;
V_35 |= V_44 ;
F_5 ( V_35 , V_17 -> V_1 + V_8 ) ;
F_5 ( * V_18 , V_17 -> V_1 + V_45 ) ;
V_20 = F_1 ( V_17 -> V_1 , 0 ) ;
if ( V_20 < 0 ) {
if ( V_20 == - V_9 ) {
F_10 ( V_17 -> V_25 , L_4 ) ;
F_4 ( V_17 -> V_1 ) ;
} else {
F_10 ( V_17 -> V_25 , L_5 ) ;
}
goto V_42;
}
F_14 ( 2 ) ;
F_5 ( V_46 ,
V_17 -> V_1 + V_47 ) ;
V_20 = F_1 ( V_17 -> V_1 ,
V_46 ) ;
if ( V_20 < 0 ) {
F_10 ( V_17 -> V_25 , L_6 ) ;
goto V_42;
}
V_42:
F_11 ( V_17 -> V_24 ) ;
F_9 ( & V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
return V_15 ;
}
static int F_15 ( struct V_48 * V_49 )
{
const struct V_50 * V_51 ;
struct V_52 * V_25 = & V_49 -> V_25 ;
struct V_53 * V_54 ;
struct V_16 * V_17 ;
struct V_55 * V_56 ;
V_17 = F_16 ( V_25 , sizeof( * V_17 ) , V_57 ) ;
if ( ! V_17 )
return - V_58 ;
V_17 -> V_25 = V_25 ;
V_54 = F_17 ( V_49 , V_59 , 0 ) ;
V_17 -> V_1 = F_18 ( V_25 , V_54 ) ;
if ( F_19 ( V_17 -> V_1 ) )
return F_20 ( V_17 -> V_1 ) ;
V_17 -> V_24 = F_21 ( V_25 , NULL ) ;
if ( F_19 ( V_17 -> V_24 ) )
return F_20 ( V_17 -> V_24 ) ;
V_51 = F_22 ( V_60 , V_25 ) ;
V_17 -> V_22 = ( unsigned long ) V_51 -> V_61 ;
V_62 . V_63 = 4 * V_17 -> V_22 ;
V_62 . V_25 = V_25 ;
V_62 . V_17 = V_17 ;
V_17 -> V_37 = & V_62 ;
V_56 = F_23 ( & V_62 ) ;
if ( F_19 ( V_56 ) )
return F_20 ( V_56 ) ;
F_24 ( V_49 , V_56 ) ;
return 0 ;
}
static int F_25 ( struct V_48 * V_49 )
{
struct V_55 * V_56 = F_26 ( V_49 ) ;
return F_27 ( V_56 ) ;
}
