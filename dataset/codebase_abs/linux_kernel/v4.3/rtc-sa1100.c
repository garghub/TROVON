static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_7 ;
unsigned long V_8 = 0 ;
F_3 ( & V_4 -> V_9 ) ;
V_7 = F_4 ( V_4 -> V_7 ) ;
F_5 ( 0 , V_4 -> V_7 ) ;
if ( V_7 & ( V_10 | V_11 ) ) {
F_5 ( ( V_12 | V_13 ) & ( V_7 >> 2 ) , V_4 -> V_7 ) ;
} else {
F_5 ( V_12 | V_13 , V_4 -> V_7 ) ;
}
if ( V_7 & V_12 )
V_7 &= ~ V_10 ;
F_5 ( V_7 & ( V_10 | V_11 ) , V_4 -> V_7 ) ;
if ( V_7 & V_12 )
V_8 |= V_14 | V_15 ;
if ( V_7 & V_13 )
V_8 |= V_16 | V_15 ;
F_6 ( V_6 , 1 , V_8 ) ;
F_7 ( & V_4 -> V_9 ) ;
return V_17 ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_20 ;
V_20 = F_9 ( V_4 -> V_21 , F_1 , 0 , L_1 , V_19 ) ;
if ( V_20 ) {
F_10 ( V_19 , L_2 , V_4 -> V_21 ) ;
goto V_22;
}
V_20 = F_9 ( V_4 -> V_23 , F_1 , 0 , L_3 , V_19 ) ;
if ( V_20 ) {
F_10 ( V_19 , L_2 , V_4 -> V_23 ) ;
goto V_24;
}
V_6 -> V_25 = V_26 ;
F_11 ( V_6 , NULL , V_26 ) ;
return 0 ;
V_24:
F_12 ( V_4 -> V_21 , V_19 ) ;
V_22:
F_13 ( V_4 -> V_27 ) ;
return V_20 ;
}
static void F_14 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
F_15 ( & V_4 -> V_9 ) ;
F_5 ( 0 , V_4 -> V_7 ) ;
F_16 ( & V_4 -> V_9 ) ;
F_12 ( V_4 -> V_23 , V_19 ) ;
F_12 ( V_4 -> V_21 , V_19 ) ;
}
static int F_17 ( struct V_18 * V_19 , unsigned int V_28 )
{
T_2 V_7 ;
struct V_3 * V_4 = F_2 ( V_19 ) ;
F_15 ( & V_4 -> V_9 ) ;
V_7 = F_4 ( V_4 -> V_7 ) ;
if ( V_28 )
V_7 |= V_10 ;
else
V_7 &= ~ V_10 ;
F_5 ( V_7 , V_4 -> V_7 ) ;
F_16 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 , struct V_29 * V_30 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
F_19 ( F_4 ( V_4 -> V_31 ) , V_30 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , struct V_29 * V_30 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
unsigned long time ;
int V_20 ;
V_20 = F_21 ( V_30 , & time ) ;
if ( V_20 == 0 )
F_5 ( time , V_4 -> V_31 ) ;
return V_20 ;
}
static int F_22 ( struct V_18 * V_19 , struct V_32 * V_33 )
{
T_2 V_7 ;
struct V_3 * V_4 = F_2 ( V_19 ) ;
V_7 = F_4 ( V_4 -> V_7 ) ;
V_33 -> V_28 = ( V_7 & V_10 ) ? 1 : 0 ;
V_33 -> V_34 = ( V_7 & V_12 ) ? 1 : 0 ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 , struct V_32 * V_33 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
unsigned long time ;
int V_20 ;
F_15 ( & V_4 -> V_9 ) ;
V_20 = F_21 ( & V_33 -> time , & time ) ;
if ( V_20 != 0 )
goto V_35;
F_5 ( F_4 ( V_4 -> V_7 ) &
( V_11 | V_10 | V_12 ) , V_4 -> V_7 ) ;
F_5 ( time , V_4 -> V_36 ) ;
if ( V_33 -> V_28 )
F_5 ( F_4 ( V_4 -> V_7 ) | V_10 , V_4 -> V_7 ) ;
else
F_5 ( F_4 ( V_4 -> V_7 ) & ~ V_10 , V_4 -> V_7 ) ;
V_35:
F_16 ( & V_4 -> V_9 ) ;
return V_20 ;
}
static int F_24 ( struct V_18 * V_19 , struct V_37 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
F_25 ( V_38 , L_4 , F_4 ( V_4 -> V_39 ) ) ;
F_25 ( V_38 , L_5 , F_4 ( V_4 -> V_7 ) ) ;
return 0 ;
}
int F_26 ( struct V_40 * V_41 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_20 ;
F_27 ( & V_4 -> V_9 ) ;
V_4 -> V_27 = F_28 ( & V_41 -> V_19 , NULL ) ;
if ( F_29 ( V_4 -> V_27 ) ) {
F_10 ( & V_41 -> V_19 , L_6 ) ;
return F_30 ( V_4 -> V_27 ) ;
}
V_20 = F_31 ( V_4 -> V_27 ) ;
if ( V_20 )
return V_20 ;
if ( F_4 ( V_4 -> V_39 ) == 0 ) {
F_5 ( V_42 + ( V_43 << 16 ) , V_4 -> V_39 ) ;
F_32 ( & V_41 -> V_19 , L_7
L_8 ) ;
F_5 ( 0 , V_4 -> V_31 ) ;
}
V_6 = F_33 ( & V_41 -> V_19 , V_41 -> V_44 , & V_45 ,
V_46 ) ;
if ( F_29 ( V_6 ) ) {
F_13 ( V_4 -> V_27 ) ;
return F_30 ( V_6 ) ;
}
V_4 -> V_6 = V_6 ;
F_5 ( V_12 | V_13 , V_4 -> V_7 ) ;
return 0 ;
}
static int F_34 ( struct V_40 * V_41 )
{
struct V_3 * V_4 ;
struct V_47 * V_48 ;
void T_3 * V_49 ;
int V_21 , V_23 ;
V_21 = F_35 ( V_41 , L_1 ) ;
V_23 = F_35 ( V_41 , L_9 ) ;
if ( V_21 < 0 || V_23 < 0 )
return - V_50 ;
V_4 = F_36 ( & V_41 -> V_19 , sizeof( struct V_3 ) , V_51 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_21 = V_21 ;
V_4 -> V_23 = V_23 ;
V_48 = F_37 ( V_41 , V_53 , 0 ) ;
V_49 = F_38 ( & V_41 -> V_19 , V_48 ) ;
if ( F_29 ( V_49 ) )
return F_30 ( V_49 ) ;
if ( F_39 ( V_54 ) ||
F_40 ( V_41 -> V_19 . V_55 , L_10 ) ) {
V_4 -> V_31 = V_49 + 0x04 ;
V_4 -> V_7 = V_49 + 0x10 ;
V_4 -> V_36 = V_49 + 0x00 ;
V_4 -> V_39 = V_49 + 0x08 ;
} else {
V_4 -> V_31 = V_49 + 0x0 ;
V_4 -> V_7 = V_49 + 0x8 ;
V_4 -> V_36 = V_49 + 0x4 ;
V_4 -> V_39 = V_49 + 0xc ;
}
F_41 ( V_41 , V_4 ) ;
F_42 ( & V_41 -> V_19 , 1 ) ;
return F_26 ( V_41 , V_4 ) ;
}
static int F_43 ( struct V_40 * V_41 )
{
struct V_3 * V_4 = F_44 ( V_41 ) ;
if ( V_4 )
F_13 ( V_4 -> V_27 ) ;
return 0 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
if ( F_46 ( V_19 ) )
F_47 ( V_4 -> V_23 ) ;
return 0 ;
}
static int F_48 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_19 ) ;
if ( F_46 ( V_19 ) )
F_49 ( V_4 -> V_23 ) ;
return 0 ;
}
