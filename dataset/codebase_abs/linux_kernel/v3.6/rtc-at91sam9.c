static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 , V_8 ;
T_1 V_9 ;
V_9 = F_3 ( V_6 ) ;
if ( V_9 == 0 )
return - V_10 ;
V_7 = F_4 ( V_6 , V_11 ) ;
V_8 = F_4 ( V_6 , V_11 ) ;
if ( V_7 != V_8 )
V_7 = F_4 ( V_6 , V_11 ) ;
F_5 ( V_9 + V_7 , V_4 ) ;
F_6 ( V_2 , L_1 , L_2 ,
1900 + V_4 -> V_12 , V_4 -> V_13 , V_4 -> V_14 ,
V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_18 ;
T_1 V_9 , V_19 , V_20 ;
unsigned long V_7 ;
F_6 ( V_2 , L_1 , L_3 ,
1900 + V_4 -> V_12 , V_4 -> V_13 , V_4 -> V_14 ,
V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_17 ) ;
V_18 = F_8 ( V_4 , & V_7 ) ;
if ( V_18 != 0 )
return V_18 ;
V_20 = F_4 ( V_6 , V_21 ) ;
F_9 ( V_6 , V_21 , V_20 & ~ ( V_22 | V_23 ) ) ;
V_9 = F_3 ( V_6 ) ;
V_7 += 1 ;
F_10 ( V_6 , V_7 ) ;
V_19 = F_4 ( V_6 , V_24 ) ;
if ( V_19 != V_25 ) {
if ( V_9 > V_7 ) {
V_19 += ( V_9 - V_7 ) ;
} else if ( ( V_19 + V_9 ) > V_7 ) {
V_19 -= ( V_7 - V_9 ) ;
} else {
V_19 = V_25 ;
V_20 &= ~ V_22 ;
}
F_9 ( V_6 , V_24 , V_19 ) ;
}
F_9 ( V_6 , V_21 , V_20 | V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = & V_28 -> time ;
T_1 V_19 = F_4 ( V_6 , V_24 ) ;
T_1 V_9 ;
V_9 = F_3 ( V_6 ) ;
if ( V_9 == 0 )
return - V_10 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( V_19 != V_25 && V_9 != 0 ) {
F_5 ( V_9 + V_19 , V_4 ) ;
F_6 ( V_2 , L_1 , L_4 ,
1900 + V_4 -> V_12 , V_4 -> V_13 , V_4 -> V_14 ,
V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_17 ) ;
if ( F_4 ( V_6 , V_21 ) & V_22 )
V_28 -> V_29 = 1 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 = & V_28 -> time ;
unsigned long V_7 ;
T_1 V_9 ;
T_1 V_20 ;
int V_18 ;
V_18 = F_8 ( V_4 , & V_7 ) ;
if ( V_18 != 0 )
return V_18 ;
V_9 = F_3 ( V_6 ) ;
if ( V_9 == 0 ) {
return - V_10 ;
}
V_20 = F_4 ( V_6 , V_21 ) ;
F_9 ( V_6 , V_21 , V_20 & ~ V_22 ) ;
if ( V_7 <= V_9 ) {
F_9 ( V_6 , V_24 , V_25 ) ;
return 0 ;
}
F_9 ( V_6 , V_24 , V_7 - V_9 ) ;
if ( V_28 -> V_29 )
F_9 ( V_6 , V_21 , V_20 | V_22 ) ;
F_6 ( V_2 , L_1 , L_5 ,
V_4 -> V_12 , V_4 -> V_13 , V_4 -> V_14 , V_4 -> V_15 ,
V_4 -> V_16 , V_4 -> V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_20 = F_4 ( V_6 , V_21 ) ;
F_6 ( V_2 , L_6 , V_29 , V_20 ) ;
if ( V_29 )
F_9 ( V_6 , V_21 , V_20 | V_22 ) ;
else
F_9 ( V_6 , V_21 , V_20 & ~ V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_20 = V_20 = F_4 ( V_6 , V_21 ) ;
F_15 ( V_31 , L_7 ,
( V_20 & V_23 ) ? L_8 : L_9 ) ;
return 0 ;
}
static T_2 F_16 ( int V_32 , void * V_33 )
{
struct V_5 * V_6 = V_33 ;
T_1 V_34 , V_20 ;
unsigned long V_35 = 0 ;
V_20 = F_4 ( V_6 , V_21 ) & ( V_22 | V_23 ) ;
V_34 = F_4 ( V_6 , V_36 ) & ( V_20 >> 16 ) ;
if ( ! V_34 )
return V_37 ;
if ( V_34 & V_38 )
V_35 |= ( V_39 | V_40 ) ;
if ( V_34 & V_41 )
V_35 |= ( V_42 | V_40 ) ;
F_17 ( V_6 -> V_43 , 1 , V_35 ) ;
F_18 ( L_10 , V_44 ,
V_35 >> 8 , V_35 & 0x000000FF ) ;
return V_45 ;
}
static int T_3 F_19 ( struct V_46 * V_47 )
{
struct V_48 * V_49 , * V_50 ;
struct V_5 * V_6 ;
int V_51 , V_32 ;
T_1 V_20 ;
V_49 = F_20 ( V_47 , V_52 , 0 ) ;
V_50 = F_20 ( V_47 , V_52 , 1 ) ;
if ( ! V_49 || ! V_50 ) {
F_21 ( & V_47 -> V_2 , L_11 ) ;
return - V_53 ;
}
V_32 = F_22 ( V_47 , 0 ) ;
if ( V_32 < 0 ) {
F_21 ( & V_47 -> V_2 , L_12 ) ;
return V_32 ;
}
V_6 = F_23 ( sizeof *V_6 , V_54 ) ;
if ( ! V_6 )
return - V_55 ;
V_6 -> V_32 = V_32 ;
if ( ! F_24 ( & V_47 -> V_2 ) )
F_25 ( & V_47 -> V_2 , 1 ) ;
F_26 ( V_47 , V_6 ) ;
V_6 -> V_56 = F_27 ( V_49 -> V_57 , F_28 ( V_49 ) ) ;
if ( ! V_6 -> V_56 ) {
F_21 ( & V_47 -> V_2 , L_13 ) ;
V_51 = - V_55 ;
goto V_58;
}
V_6 -> V_59 = F_27 ( V_50 -> V_57 , F_28 ( V_50 ) ) ;
if ( ! V_6 -> V_59 ) {
F_21 ( & V_47 -> V_2 , L_14 ) ;
V_51 = - V_55 ;
goto V_60;
}
V_20 = F_4 ( V_6 , V_21 ) ;
if ( ( V_20 & V_61 ) != V_62 ) {
V_20 = V_26 | ( V_62 & V_61 ) ;
F_10 ( V_6 , 0 ) ;
}
V_20 &= ~ ( V_22 | V_23 ) ;
F_9 ( V_6 , V_21 , V_20 ) ;
V_6 -> V_43 = F_29 ( V_47 -> V_63 , & V_47 -> V_2 ,
& V_64 , V_65 ) ;
if ( F_30 ( V_6 -> V_43 ) ) {
V_51 = F_31 ( V_6 -> V_43 ) ;
goto V_66;
}
V_51 = F_32 ( V_6 -> V_32 , F_16 , V_67 ,
F_33 ( & V_6 -> V_43 -> V_2 ) , V_6 ) ;
if ( V_51 ) {
F_6 ( & V_47 -> V_2 , L_15 , V_6 -> V_32 ) ;
F_34 ( V_6 -> V_43 ) ;
goto V_66;
}
if ( F_3 ( V_6 ) == 0 )
F_35 ( & V_47 -> V_2 , L_16 ,
F_33 ( & V_6 -> V_43 -> V_2 ) ) ;
return 0 ;
V_66:
F_36 ( V_6 -> V_59 ) ;
V_60:
F_36 ( V_6 -> V_56 ) ;
V_58:
F_26 ( V_47 , NULL ) ;
F_37 ( V_6 ) ;
return V_51 ;
}
static int T_4 F_38 ( struct V_46 * V_47 )
{
struct V_5 * V_6 = F_39 ( V_47 ) ;
T_1 V_20 = F_4 ( V_6 , V_21 ) ;
F_9 ( V_6 , V_21 , V_20 & ~ ( V_22 | V_23 ) ) ;
F_40 ( V_6 -> V_32 , V_6 ) ;
F_34 ( V_6 -> V_43 ) ;
F_36 ( V_6 -> V_59 ) ;
F_36 ( V_6 -> V_56 ) ;
F_26 ( V_47 , NULL ) ;
F_37 ( V_6 ) ;
return 0 ;
}
static void F_41 ( struct V_46 * V_47 )
{
struct V_5 * V_6 = F_39 ( V_47 ) ;
T_1 V_20 = F_4 ( V_6 , V_21 ) ;
V_6 -> V_68 = V_20 & ( V_22 | V_23 ) ;
F_9 ( V_6 , V_21 , V_20 & ~ V_6 -> V_68 ) ;
}
static int F_42 ( struct V_46 * V_47 ,
T_5 V_69 )
{
struct V_5 * V_6 = F_39 ( V_47 ) ;
T_1 V_20 = F_4 ( V_6 , V_21 ) ;
V_6 -> V_68 = V_20 & ( V_22 | V_23 ) ;
if ( V_6 -> V_68 ) {
if ( F_43 ( & V_47 -> V_2 ) && ( V_20 & V_22 ) ) {
F_44 ( V_6 -> V_32 ) ;
if ( V_20 & V_23 )
F_9 ( V_6 , V_21 , V_20 & ~ V_23 ) ;
} else
F_9 ( V_6 , V_21 , V_20 & ~ V_6 -> V_68 ) ;
}
return 0 ;
}
static int F_45 ( struct V_46 * V_47 )
{
struct V_5 * V_6 = F_39 ( V_47 ) ;
T_1 V_20 ;
if ( V_6 -> V_68 ) {
if ( F_43 ( & V_47 -> V_2 ) )
F_46 ( V_6 -> V_32 ) ;
V_20 = F_4 ( V_6 , V_21 ) ;
F_9 ( V_6 , V_21 , V_20 | V_6 -> V_68 ) ;
}
return 0 ;
}
static int T_6 F_47 ( void )
{
return F_48 ( & V_70 ) ;
}
static void T_7 F_49 ( void )
{
F_50 ( & V_70 ) ;
}
