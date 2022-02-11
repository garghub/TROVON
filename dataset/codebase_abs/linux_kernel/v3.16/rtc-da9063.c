static void F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = V_1 [ V_5 ] & V_6 ;
V_3 -> V_7 = V_1 [ V_8 ] & V_9 ;
V_3 -> V_10 = V_1 [ V_11 ] & V_12 ;
V_3 -> V_13 = V_1 [ V_14 ] & V_15 ;
V_3 -> V_16 = F_2 ( V_1 [ V_17 ] &
V_18 ) ;
V_3 -> V_19 = F_3 ( V_1 [ V_20 ] &
V_21 ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 * V_1 )
{
V_1 [ V_5 ] &= ~ V_6 ;
V_1 [ V_5 ] |= V_3 -> V_4 & V_6 ;
V_1 [ V_8 ] &= ~ V_9 ;
V_1 [ V_8 ] |= V_3 -> V_7 & V_9 ;
V_1 [ V_11 ] &= ~ V_12 ;
V_1 [ V_11 ] |= V_3 -> V_10 & V_12 ;
V_1 [ V_14 ] &= ~ V_15 ;
V_1 [ V_14 ] |= V_3 -> V_13 & V_15 ;
V_1 [ V_17 ] &= ~ V_18 ;
V_1 [ V_17 ] |= F_5 ( V_3 -> V_16 ) &
V_18 ;
V_1 [ V_20 ] &= ~ V_21 ;
V_1 [ V_20 ] |= F_6 ( V_3 -> V_19 ) &
V_21 ;
}
static int F_7 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_8 ( V_23 ) ;
return F_9 ( V_25 -> V_26 -> V_27 , V_28 ,
V_29 , 0 ) ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_8 ( V_23 ) ;
return F_9 ( V_25 -> V_26 -> V_27 , V_28 ,
V_29 , V_29 ) ;
}
static int F_11 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
struct V_24 * V_25 = F_8 ( V_23 ) ;
unsigned long V_30 ;
unsigned long V_31 ;
T_1 V_1 [ V_32 ] ;
int V_33 ;
V_33 = F_12 ( V_25 -> V_26 -> V_27 , V_34 ,
V_1 , V_32 ) ;
if ( V_33 < 0 ) {
F_13 ( V_23 , L_1 , V_33 ) ;
return V_33 ;
}
if ( ! ( V_1 [ V_5 ] & V_35 ) ) {
F_14 ( V_23 , L_2 ) ;
return - V_36 ;
}
F_1 ( V_1 , V_3 ) ;
F_15 ( V_3 , & V_30 ) ;
F_15 ( & V_25 -> V_37 , & V_31 ) ;
if ( V_25 -> V_38 == true && V_31 - V_30 == 1 )
memcpy ( V_3 , & V_25 -> V_37 , sizeof( struct V_2 ) ) ;
else
V_25 -> V_38 = false ;
return F_16 ( V_3 ) ;
}
static int F_17 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
struct V_24 * V_25 = F_8 ( V_23 ) ;
T_1 V_1 [ V_32 ] ;
int V_33 ;
F_4 ( V_3 , V_1 ) ;
V_33 = F_18 ( V_25 -> V_26 -> V_27 , V_34 ,
V_1 , V_32 ) ;
if ( V_33 < 0 )
F_13 ( V_23 , L_3 , V_33 ) ;
return V_33 ;
}
static int F_19 ( struct V_22 * V_23 , struct V_39 * V_40 )
{
struct V_24 * V_25 = F_8 ( V_23 ) ;
T_1 V_1 [ V_32 ] ;
int V_33 ;
unsigned int V_41 ;
V_33 = F_12 ( V_25 -> V_26 -> V_27 , V_42 ,
& V_1 [ V_5 ] , V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
F_1 ( V_1 , & V_40 -> time ) ;
V_40 -> V_43 = ! ! ( V_1 [ V_20 ] & V_29 ) ;
V_33 = F_20 ( V_25 -> V_26 -> V_27 , V_44 , & V_41 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_41 & ( V_45 ) )
V_40 -> V_46 = 1 ;
else
V_40 -> V_46 = 0 ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 , struct V_39 * V_40 )
{
struct V_24 * V_25 = F_8 ( V_23 ) ;
T_1 V_1 [ V_32 ] ;
int V_33 ;
F_4 ( & V_40 -> time , V_1 ) ;
V_33 = F_7 ( V_23 ) ;
if ( V_33 < 0 ) {
F_13 ( V_23 , L_4 , V_33 ) ;
return V_33 ;
}
V_33 = F_18 ( V_25 -> V_26 -> V_27 , V_42 ,
V_1 , V_32 ) ;
if ( V_33 < 0 ) {
F_13 ( V_23 , L_5 , V_33 ) ;
return V_33 ;
}
V_25 -> V_37 = V_40 -> time ;
if ( V_40 -> V_43 ) {
V_33 = F_10 ( V_23 ) ;
if ( V_33 < 0 ) {
F_13 ( V_23 , L_6 , V_33 ) ;
return V_33 ;
}
}
return V_33 ;
}
static int F_22 ( struct V_22 * V_23 , unsigned int V_43 )
{
if ( V_43 )
return F_10 ( V_23 ) ;
else
return F_7 ( V_23 ) ;
}
static T_2 F_23 ( int V_47 , void * V_1 )
{
struct V_24 * V_25 = V_1 ;
F_9 ( V_25 -> V_26 -> V_27 , V_28 ,
V_29 , 0 ) ;
V_25 -> V_38 = true ;
F_24 ( V_25 -> V_48 , 1 , V_49 | V_50 ) ;
return V_51 ;
}
static int F_25 ( struct V_52 * V_53 )
{
struct V_54 * V_54 = F_8 ( V_53 -> V_23 . V_55 ) ;
struct V_24 * V_25 ;
int V_56 ;
T_1 V_1 [ V_32 ] ;
int V_33 ;
V_33 = F_9 ( V_54 -> V_27 , V_57 ,
V_58 , V_58 ) ;
if ( V_33 < 0 ) {
F_13 ( & V_53 -> V_23 , L_7 ) ;
goto V_59;
}
V_33 = F_9 ( V_54 -> V_27 , V_60 ,
V_61 , V_61 ) ;
if ( V_33 < 0 ) {
F_13 ( & V_53 -> V_23 , L_8 ) ;
goto V_59;
}
V_33 = F_9 ( V_54 -> V_27 , V_42 ,
V_62 | V_63 ,
0 ) ;
if ( V_33 < 0 ) {
F_13 ( & V_53 -> V_23 , L_9 ) ;
goto V_59;
}
V_33 = F_9 ( V_54 -> V_27 , V_42 ,
V_63 ,
V_63 ) ;
if ( V_33 < 0 ) {
F_13 ( & V_53 -> V_23 , L_9 ) ;
goto V_59;
}
V_33 = F_9 ( V_54 -> V_27 , V_28 ,
V_64 , 0 ) ;
if ( V_33 < 0 ) {
F_13 ( & V_53 -> V_23 , L_10 ) ;
goto V_59;
}
V_33 = F_12 ( V_54 -> V_27 , V_42 ,
V_1 , V_32 ) ;
if ( V_33 < 0 ) {
F_13 ( & V_53 -> V_23 , L_11 ,
V_33 ) ;
goto V_59;
}
V_25 = F_26 ( & V_53 -> V_23 , sizeof( * V_25 ) , V_65 ) ;
if ( ! V_25 )
return - V_66 ;
F_27 ( V_53 , V_25 ) ;
V_56 = F_28 ( V_53 , L_12 ) ;
V_33 = F_29 ( & V_53 -> V_23 , V_56 , NULL ,
F_23 ,
V_67 | V_68 ,
L_12 , V_25 ) ;
if ( V_33 ) {
F_13 ( & V_53 -> V_23 , L_13 ,
V_56 , V_33 ) ;
goto V_59;
}
V_25 -> V_26 = V_54 ;
V_25 -> V_48 = F_30 ( & V_53 -> V_23 , V_69 ,
& V_70 , V_71 ) ;
if ( F_31 ( V_25 -> V_48 ) )
return F_32 ( V_25 -> V_48 ) ;
F_1 ( V_1 , & V_25 -> V_37 ) ;
V_25 -> V_38 = false ;
V_59:
return V_33 ;
}
