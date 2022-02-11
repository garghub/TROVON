static void F_1 ( struct V_1 * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
if ( V_2 ) {
F_2 ( V_4 , V_6 ,
F_3 ( V_1 -> V_7 + 0x0c ) ) ;
F_2 ( V_4 , V_8 ,
F_3 ( V_1 -> V_7 + 0x10 ) ) ;
}
F_4 ( V_4 , V_9 , V_2 ) ;
F_5 ( V_4 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
F_7 ( V_11 , V_1 -> V_7 + 0x04 ) ;
V_10 = F_3 ( V_1 -> V_7 ) ;
V_10 &= ~ ( V_12 | V_13 | V_14 ) ;
V_10 |= V_15 | V_16 | V_17 ;
F_7 ( V_10 , V_1 -> V_7 ) ;
V_1 -> V_18 = V_19 ;
}
static void F_8 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
F_7 ( V_20 , V_1 -> V_7 + 0x04 ) ;
V_10 = F_3 ( V_1 -> V_7 ) ;
V_10 &= ~ ( V_12 | V_21 | V_14 ) ;
V_10 |= V_15 | V_16 | V_17 ;
F_7 ( V_10 , V_1 -> V_7 ) ;
V_1 -> V_18 = V_22 ;
}
static void F_9 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
V_10 = F_3 ( V_1 -> V_7 ) ;
V_10 &= ~ ( V_21 | V_16 | V_15 | V_17 ) ;
V_10 |= V_12 | V_14 ;
F_7 ( V_10 , V_1 -> V_7 ) ;
V_1 -> V_18 = V_23 ;
}
static T_1 F_10 ( int V_24 , void * V_25 )
{
struct V_1 * V_1 = V_25 ;
unsigned long V_26 ;
F_11 ( & V_1 -> V_27 , V_26 ) ;
switch ( V_1 -> V_18 ) {
case V_23 :
F_12 ( & V_1 -> V_28 ) ;
F_6 ( V_1 ) ;
break;
case V_19 :
F_8 ( V_1 ) ;
break;
case V_22 :
F_1 ( V_1 , true ) ;
F_9 ( V_1 ) ;
F_13 ( & V_1 -> V_28 , V_29 + F_14 ( 100 ) ) ;
break;
case V_30 :
break;
}
F_15 ( & V_1 -> V_27 , V_26 ) ;
return V_31 ;
}
static void F_16 ( unsigned long V_32 )
{
struct V_1 * V_1 = (struct V_1 * ) V_32 ;
unsigned long V_26 ;
F_11 ( & V_1 -> V_27 , V_26 ) ;
if ( V_1 -> V_18 == V_23 &&
! ( F_3 ( V_1 -> V_7 + 0x04 ) & V_33 ) ) {
F_1 ( V_1 , false ) ;
}
F_15 ( & V_1 -> V_27 , V_26 ) ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_18 ( V_4 ) ;
unsigned long V_34 ;
F_19 ( V_1 -> V_35 ) ;
F_7 ( V_36 , V_1 -> V_7 ) ;
F_20 ( 1 ) ;
F_7 ( V_37 , V_1 -> V_7 ) ;
F_20 ( 1 ) ;
V_34 = F_3 ( V_1 -> V_7 + 0x04 ) ;
F_7 ( V_34 & V_38 , V_1 -> V_7 + 0x04 ) ;
F_7 ( V_39 , V_1 -> V_7 + 0x08 ) ;
V_1 -> V_18 = V_23 ;
F_21 () ;
V_34 = F_3 ( V_1 -> V_7 ) ;
V_34 |= V_12 | V_40 | V_41 | V_14 ;
F_7 ( V_34 , V_1 -> V_7 ) ;
return 0 ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_18 ( V_4 ) ;
unsigned long V_34 ;
F_23 ( & V_1 -> V_27 ) ;
V_1 -> V_18 = V_30 ;
V_34 = F_3 ( V_1 -> V_7 ) ;
V_34 &= ~ ( V_12 | V_40 | V_41 | V_14 | V_16 ) ;
F_7 ( V_34 , V_1 -> V_7 ) ;
F_24 ( & V_1 -> V_27 ) ;
F_25 ( & V_1 -> V_28 ) ;
F_26 ( V_1 -> V_35 ) ;
}
static int F_27 ( struct V_42 * V_43 )
{
struct V_1 * V_1 ;
struct V_3 * V_3 ;
struct V_44 * V_45 ;
int V_46 ;
V_1 = F_28 ( sizeof( struct V_1 ) , V_47 ) ;
V_3 = F_29 () ;
if ( ! V_1 || ! V_3 ) {
V_46 = - V_48 ;
goto V_49;
}
V_1 -> V_5 = V_3 ;
V_1 -> V_18 = V_30 ;
F_30 ( & V_1 -> V_27 ) ;
F_31 ( & V_1 -> V_28 , F_16 ,
( unsigned long ) V_1 ) ;
V_45 = F_32 ( V_43 , V_50 , 0 ) ;
if ( ! V_45 ) {
V_46 = - V_51 ;
goto V_49;
}
if ( ! F_33 ( V_45 -> V_52 , F_34 ( V_45 ) ,
V_43 -> V_53 ) ) {
V_46 = - V_54 ;
goto V_49;
}
V_1 -> V_7 = F_35 ( V_45 -> V_52 , F_34 ( V_45 ) ) ;
if ( ! V_1 -> V_7 ) {
V_46 = - V_48 ;
goto V_55;
}
V_1 -> V_35 = F_36 ( & V_43 -> V_4 , NULL ) ;
if ( F_37 ( V_1 -> V_35 ) ) {
V_46 = F_38 ( V_1 -> V_35 ) ;
goto V_56;
}
V_3 -> V_53 = L_1 ;
V_3 -> V_57 = L_2 ;
V_3 -> V_58 . V_59 = V_60 ;
V_3 -> V_58 . V_61 = 0x0005 ;
V_3 -> V_58 . V_62 = 0x0001 ;
V_3 -> V_58 . V_63 = 0x0100 ;
V_3 -> V_4 . V_64 = & V_43 -> V_4 ;
V_3 -> V_65 = F_17 ;
V_3 -> V_66 = F_22 ;
V_3 -> V_67 [ 0 ] = F_39 ( V_68 ) | F_39 ( V_69 ) ;
V_3 -> V_70 [ F_40 ( V_9 ) ] = F_39 ( V_9 ) ;
F_41 ( V_3 , V_6 , 0 , 0x400 , 0 , 0 ) ;
F_41 ( V_3 , V_8 , 0 , 0x400 , 0 , 0 ) ;
F_42 ( V_3 , V_1 ) ;
V_1 -> V_71 = F_43 ( V_43 , 0 ) ;
if ( F_44 ( V_1 -> V_71 , F_10 ,
0 , L_3 , V_1 ) ) {
V_46 = - V_54 ;
goto V_72;
}
V_46 = F_45 ( V_1 -> V_5 ) ;
if ( V_46 )
goto V_73;
F_46 ( V_43 , V_1 ) ;
return 0 ;
V_73: F_47 ( V_1 -> V_71 , V_1 ) ;
V_72: F_48 ( V_1 -> V_35 ) ;
V_56: F_49 ( V_1 -> V_7 ) ;
V_55: F_50 ( V_45 -> V_52 , F_34 ( V_45 ) ) ;
V_49: F_51 ( V_3 ) ;
F_52 ( V_1 ) ;
return V_46 ;
}
static int F_53 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = F_54 ( V_43 ) ;
struct V_44 * V_45 ;
F_47 ( V_1 -> V_71 , V_1 ) ;
F_25 ( & V_1 -> V_28 ) ;
F_49 ( V_1 -> V_7 ) ;
F_48 ( V_1 -> V_35 ) ;
V_45 = F_32 ( V_43 , V_50 , 0 ) ;
F_50 ( V_45 -> V_52 , F_34 ( V_45 ) ) ;
F_55 ( V_1 -> V_5 ) ;
F_52 ( V_1 ) ;
F_46 ( V_43 , NULL ) ;
return 0 ;
}
