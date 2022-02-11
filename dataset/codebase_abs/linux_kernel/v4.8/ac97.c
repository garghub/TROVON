static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
V_4 = F_2 ( V_5 . V_6 + V_7 ) & 0x7 ;
if ( V_4 == V_8 )
return;
F_3 ( & V_5 . V_9 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 = V_11 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
V_3 |= V_12 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 |= V_13 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! F_6 ( & V_5 . V_9 , V_14 ) )
F_7 ( L_1 ) ;
}
static unsigned short F_8 ( struct V_1 * V_2 ,
unsigned short V_15 )
{
T_1 V_3 , V_16 ;
T_1 V_4 , V_17 , V_18 ;
F_9 ( & V_5 . V_19 ) ;
F_1 ( V_2 ) ;
F_3 ( & V_5 . V_9 ) ;
V_16 = F_2 ( V_5 . V_6 + V_20 ) ;
V_16 = V_21 | F_10 ( V_15 ) ;
F_4 ( V_16 , V_5 . V_6 + V_20 ) ;
F_11 ( 50 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 |= V_13 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! F_6 ( & V_5 . V_9 , V_14 ) )
F_7 ( L_2 ) ;
V_4 = F_2 ( V_5 . V_6 + V_22 ) ;
V_17 = ( V_4 >> 16 ) & 0x7f ;
V_18 = ( V_4 & 0xffff ) ;
if ( V_17 != V_15 )
F_7 ( L_3 ,
V_15 , V_17 ) ;
F_12 ( & V_5 . V_19 ) ;
return ( unsigned short ) V_18 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned short V_15 ,
unsigned short V_23 )
{
T_1 V_3 , V_16 ;
F_9 ( & V_5 . V_19 ) ;
F_1 ( V_2 ) ;
F_3 ( & V_5 . V_9 ) ;
V_16 = F_2 ( V_5 . V_6 + V_20 ) ;
V_16 = F_10 ( V_15 ) | F_14 ( V_23 ) ;
F_4 ( V_16 , V_5 . V_6 + V_20 ) ;
F_11 ( 50 ) ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 |= V_13 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
if ( ! F_6 ( & V_5 . V_9 , V_14 ) )
F_7 ( L_4 ) ;
V_16 = F_2 ( V_5 . V_6 + V_20 ) ;
V_16 |= V_21 ;
F_4 ( V_16 , V_5 . V_6 + V_20 ) ;
F_12 ( & V_5 . V_19 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( L_5 ) ;
F_4 ( V_24 ,
V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
F_4 ( 0 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_5 . V_6 + V_7 ) & 0x7 ;
if ( V_4 == V_8 )
return;
F_16 ( L_6 ) ;
F_4 ( V_25 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
F_4 ( 0 , V_5 . V_6 + V_10 ) ;
F_5 ( 1 ) ;
F_1 ( V_2 ) ;
}
static T_2 F_18 ( int V_26 , void * V_27 )
{
T_1 V_3 , V_28 ;
V_28 = F_2 ( V_5 . V_6 + V_7 ) ;
if ( V_28 & V_29 ) {
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 &= ~ V_13 ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
F_19 ( & V_5 . V_9 ) ;
}
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 |= ( 1 << 30 ) ;
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
return V_30 ;
}
static int F_20 ( struct V_31 * V_32 , int V_33 ,
struct V_34 * V_35 )
{
T_1 V_3 ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
if ( V_32 -> V_36 == V_37 )
V_3 &= ~ V_38 ;
else
V_3 &= ~ V_39 ;
switch ( V_33 ) {
case V_40 :
case V_41 :
case V_42 :
if ( V_32 -> V_36 == V_37 )
V_3 |= V_43 ;
else
V_3 |= V_44 ;
break;
case V_45 :
case V_46 :
case V_47 :
break;
}
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
return 0 ;
}
static int F_21 ( struct V_31 * V_32 ,
int V_33 , struct V_34 * V_35 )
{
T_1 V_3 ;
V_3 = F_2 ( V_5 . V_6 + V_10 ) ;
V_3 &= ~ V_48 ;
switch ( V_33 ) {
case V_40 :
case V_41 :
case V_42 :
V_3 |= V_49 ;
break;
case V_45 :
case V_46 :
case V_47 :
break;
}
F_4 ( V_3 , V_5 . V_6 + V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_34 * V_35 )
{
F_23 ( V_35 , & V_50 , & V_51 ) ;
return 0 ;
}
static int F_24 ( struct V_34 * V_35 )
{
F_23 ( V_35 , NULL , & V_52 ) ;
return 0 ;
}
static int F_25 ( struct V_53 * V_54 )
{
struct V_55 * V_56 , * V_57 ;
struct V_58 * V_59 ;
int V_60 ;
V_59 = V_54 -> V_61 . V_62 ;
if ( ! V_59 || ! V_59 -> V_63 ) {
F_26 ( & V_54 -> V_61 , L_7 ) ;
return - V_64 ;
}
V_57 = F_27 ( V_54 , V_65 , 0 ) ;
if ( ! V_57 ) {
F_26 ( & V_54 -> V_61 , L_8 ) ;
return - V_66 ;
}
V_56 = F_27 ( V_54 , V_67 , 0 ) ;
V_5 . V_6 = F_28 ( & V_54 -> V_61 , V_56 ) ;
if ( F_29 ( V_5 . V_6 ) )
return F_30 ( V_5 . V_6 ) ;
V_50 . V_68 = V_59 -> V_69 ;
V_50 . V_70 = V_56 -> V_71 + V_72 ;
V_51 . V_68 = V_59 -> V_73 ;
V_51 . V_70 = V_56 -> V_71 + V_72 ;
V_52 . V_68 = V_59 -> V_74 ;
V_52 . V_70 = V_56 -> V_71 + V_75 ;
F_31 ( & V_5 . V_9 ) ;
F_32 ( & V_5 . V_19 ) ;
V_5 . V_76 = F_33 ( & V_54 -> V_61 , L_9 ) ;
if ( F_29 ( V_5 . V_76 ) ) {
F_26 ( & V_54 -> V_61 , L_10 ) ;
V_60 = - V_77 ;
goto V_78;
}
F_34 ( V_5 . V_76 ) ;
if ( V_59 -> V_63 ( V_54 ) ) {
F_26 ( & V_54 -> V_61 , L_11 ) ;
V_60 = - V_64 ;
goto V_79;
}
V_60 = F_35 ( V_57 -> V_71 , F_18 ,
0 , L_12 , NULL ) ;
if ( V_60 < 0 ) {
F_26 ( & V_54 -> V_61 , L_13 ) ;
goto V_80;
}
V_60 = F_36 ( & V_81 ) ;
if ( V_60 != 0 ) {
F_26 ( & V_54 -> V_61 , L_14 , V_60 ) ;
goto V_80;
}
V_60 = F_37 ( & V_54 -> V_61 , & V_82 ,
V_83 , F_38 ( V_83 ) ) ;
if ( V_60 )
goto V_84;
V_60 = F_39 ( & V_54 -> V_61 ,
V_59 -> V_85 ,
NULL , NULL ) ;
if ( V_60 ) {
F_26 ( & V_54 -> V_61 , L_15 , V_60 ) ;
goto V_84;
}
return 0 ;
V_84:
F_40 ( V_57 -> V_71 , NULL ) ;
V_80:
V_79:
F_41 ( V_5 . V_76 ) ;
V_78:
F_36 ( NULL ) ;
return V_60 ;
}
static int F_42 ( struct V_53 * V_54 )
{
struct V_55 * V_57 ;
V_57 = F_27 ( V_54 , V_65 , 0 ) ;
if ( V_57 )
F_40 ( V_57 -> V_71 , NULL ) ;
F_41 ( V_5 . V_76 ) ;
F_36 ( NULL ) ;
return 0 ;
}
