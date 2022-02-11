static void F_1 ( struct V_1 * V_1 , T_1 V_2 , unsigned long V_3 )
{
F_2 ( V_2 , V_1 -> V_4 + ( V_3 * 4UL ) ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , unsigned long V_3 )
{
return F_4 ( V_1 -> V_4 + ( V_3 * 4UL ) ) ;
}
static T_2 F_5 ( struct V_1 * V_1 , void * V_5 ,
T_3 V_6 , int V_7 )
{
return F_6 ( V_1 -> V_8 , V_5 , V_6 , V_7 ) ;
}
static int F_7 ( struct V_1 * V_1 , struct V_9 * V_10 ,
int V_11 , int V_7 )
{
return F_8 ( V_1 -> V_8 , V_10 , V_11 , V_7 ) ;
}
static void F_9 ( struct V_1 * V_1 , T_2 V_12 ,
T_3 V_6 , int V_7 )
{
F_10 ( V_1 -> V_8 , V_12 , V_6 , V_7 ) ;
}
static void F_11 ( struct V_1 * V_1 , struct V_9 * V_10 ,
int V_11 , int V_7 )
{
F_12 ( V_1 -> V_8 , V_10 , V_11 , V_7 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
if ( F_14 ( V_13 ) & ( V_14 | V_15 ) )
return 1 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_1 )
{
T_4 V_2 ;
V_2 = F_14 ( V_13 ) ;
F_16 ( V_2 | V_16 , V_13 ) ;
F_16 ( V_2 & ~ V_16 , V_13 ) ;
V_2 = F_14 ( V_13 ) ;
F_16 ( V_2 | V_17 , V_13 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
T_4 V_18 ;
int V_19 ;
V_18 = F_14 ( V_13 ) ;
if ( ! ( V_18 & V_20 ) )
return;
F_16 ( V_18 | V_21 , V_13 ) ;
V_19 = 1000 ;
while ( F_14 ( V_13 ) & V_20 ) {
if ( -- V_19 == 0 ) {
F_18 (KERN_ALERT PFX L_1 ,
esp->host->unique_id) ;
break;
}
F_19 ( 1 ) ;
}
}
static void F_20 ( struct V_1 * V_1 )
{
T_4 V_2 ;
int V_19 ;
V_19 = 1000 ;
while ( ( V_2 = F_14 ( V_13 ) ) & V_22 ) {
if ( -- V_19 == 0 ) {
F_18 (KERN_ALERT PFX L_2
L_3 , esp->host->unique_id) ;
break;
}
F_19 ( 1 ) ;
}
V_2 &= ~ ( V_23 | V_24 | V_25 ) ;
V_2 |= V_26 ;
F_16 ( V_2 , V_13 ) ;
V_2 &= ~ V_26 ;
F_16 ( V_2 , V_13 ) ;
}
static void F_21 ( struct V_1 * V_1 , T_4 V_12 , T_4 V_27 ,
T_4 V_28 , int V_29 , T_1 V_30 )
{
T_4 V_18 ;
F_22 ( ! ( V_30 & V_31 ) ) ;
F_1 ( V_1 , ( V_27 >> 0 ) & 0xff , V_32 ) ;
F_1 ( V_1 , ( V_27 >> 8 ) & 0xff , V_33 ) ;
V_18 = F_14 ( V_13 ) ;
V_18 |= V_23 ;
if ( V_29 )
V_18 |= V_24 ;
else
V_18 &= ~ V_24 ;
F_16 ( V_18 , V_13 ) ;
F_16 ( V_12 , V_34 ) ;
F_23 ( V_1 , V_30 ) ;
}
static int F_24 ( struct V_1 * V_1 )
{
T_4 V_18 = F_14 ( V_13 ) ;
if ( V_18 & V_15 )
return 1 ;
return 0 ;
}
static int F_25 ( struct V_35 * V_8 )
{
struct V_36 * V_37 = & V_38 ;
struct V_39 * V_40 ;
struct V_1 * V_1 ;
struct V_41 * V_42 ;
int V_43 = - V_44 ;
V_40 = F_26 ( V_37 , sizeof( struct V_1 ) ) ;
if ( ! V_40 )
goto V_45;
V_40 -> V_46 = 8 ;
V_1 = F_27 ( V_40 ) ;
V_1 -> V_40 = V_40 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_47 = & V_48 ;
V_42 = F_28 ( V_8 , V_49 , 0 ) ;
if ( ! V_42 || ! V_42 -> V_50 )
goto V_51;
V_1 -> V_4 = F_29 ( V_42 -> V_50 , 0x20 ) ;
if ( ! V_1 -> V_4 )
goto V_52;
V_42 = F_28 ( V_8 , V_49 , 1 ) ;
if ( ! V_42 || ! V_42 -> V_50 )
goto V_52;
V_1 -> V_53 = F_29 ( V_42 -> V_50 , 0x10 ) ;
V_1 -> V_54 = F_30 ( V_1 -> V_8 , 16 ,
& V_1 -> V_55 ,
V_56 ) ;
if ( ! V_1 -> V_54 )
goto V_57;
V_40 -> V_58 = F_31 ( V_8 , 0 ) ;
V_43 = F_32 ( V_40 -> V_58 , V_59 , V_60 ,
L_4 , V_1 ) ;
if ( V_43 < 0 )
goto V_61;
V_1 -> V_62 = 7 ;
V_1 -> V_40 -> V_63 = V_1 -> V_62 ;
V_1 -> V_64 = ( 1 << V_1 -> V_62 ) ;
V_1 -> V_65 = 20000000 ;
F_33 ( & V_8 -> V_8 , V_1 ) ;
V_43 = F_34 ( V_1 , & V_8 -> V_8 ) ;
if ( V_43 )
goto V_66;
return 0 ;
V_66:
F_35 ( V_40 -> V_58 , V_1 ) ;
V_61:
F_36 ( V_1 -> V_8 , 16 ,
V_1 -> V_54 ,
V_1 -> V_55 ) ;
V_57:
F_37 ( V_1 -> V_53 ) ;
V_52:
F_37 ( V_1 -> V_4 ) ;
V_51:
F_38 ( V_40 ) ;
V_45:
return V_43 ;
}
static int F_39 ( struct V_35 * V_8 )
{
struct V_1 * V_1 = F_40 ( & V_8 -> V_8 ) ;
unsigned int V_58 = V_1 -> V_40 -> V_58 ;
T_4 V_2 ;
F_41 ( V_1 ) ;
V_2 = F_14 ( V_13 ) ;
F_16 ( V_2 & ~ V_17 , V_13 ) ;
F_35 ( V_58 , V_1 ) ;
F_36 ( V_1 -> V_8 , 16 ,
V_1 -> V_54 ,
V_1 -> V_55 ) ;
F_38 ( V_1 -> V_40 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_67 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_67 ) ;
}
