void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
void T_1 * V_3 = V_4 ;
if ( V_3 ) {
unsigned long V_5 ;
unsigned V_6 ;
F_2 ( V_5 ) ;
V_6 = F_3 ( V_3 + V_7 ) ;
F_4 ( ( V_6 & ~ V_1 ) | V_2 , V_3 + V_7 ) ;
F_5 ( V_5 ) ;
} else {
F_6 ( 1 , L_1 ) ;
}
}
static void F_7 ( struct V_8 * V_9 , T_2 V_10 )
{
void T_1 * V_3 = V_4 ;
T_2 V_11 ;
if ( ! V_3 )
return;
V_11 = F_3 ( V_3 + V_12 ) ;
if ( V_9 -> V_13 == V_14 ) {
if ( V_10 & V_15 )
V_11 &= ~ V_16 ;
else
V_11 |= V_16 ;
if ( V_10 & V_17 )
V_11 &= ~ V_18 ;
else
V_11 |= V_18 ;
} else if ( V_9 -> V_13 == V_19 ) {
if ( V_10 & V_15 )
V_11 &= ~ V_20 ;
else
V_11 |= V_20 ;
if ( V_10 & V_17 )
V_11 &= ~ V_21 ;
else
V_11 |= V_21 ;
}
F_4 ( V_11 , V_3 + V_12 ) ;
}
static T_2 F_8 ( struct V_8 * V_9 )
{
void T_1 * V_3 = V_4 ;
T_2 V_22 = V_23 | V_24 | V_25 ;
T_2 V_26 ;
if ( ! V_3 )
return V_22 ;
V_26 = F_3 ( V_3 + V_27 ) ;
if ( V_9 -> V_13 == V_14 ) {
if ( V_26 & V_28 )
V_22 &= ~ V_23 ;
if ( V_26 & V_29 )
V_22 &= ~ V_24 ;
if ( V_26 & V_30 )
V_22 &= ~ V_25 ;
} else if ( V_9 -> V_13 == V_19 ) {
if ( V_26 & V_31 )
V_22 &= ~ V_23 ;
if ( V_26 & V_32 )
V_22 &= ~ V_24 ;
if ( V_26 & V_33 )
V_22 &= ~ V_25 ;
}
return V_22 ;
}
static void F_9 ( unsigned int V_34 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_10 ( V_36 ) ;
unsigned int V_39 ;
while ( 1 ) {
V_36 -> V_40 . V_41 -> V_42 ( & V_36 -> V_40 ) ;
V_39 = F_3 ( V_38 -> V_3 + V_43 ) ;
V_39 ^= V_44 | V_45 ;
if ( ( V_39 & ( V_44 | V_45 | V_46 ) ) == 0 )
break;
if ( V_39 & ( V_44 | V_45 ) ) {
V_36 -> V_40 . V_41 -> V_47 ( & V_36 -> V_40 ) ;
V_36 -> V_40 . V_41 -> V_42 ( & V_36 -> V_40 ) ;
if ( V_39 & V_44 )
F_11 ( V_38 -> V_48 + V_49 ) ;
if ( V_39 & V_45 )
F_11 ( V_38 -> V_48 + V_50 ) ;
V_36 -> V_40 . V_41 -> V_51 ( & V_36 -> V_40 ) ;
}
if ( V_39 & V_46 )
F_11 ( V_38 -> V_48 + V_52 ) ;
}
}
static void F_12 ( struct V_40 * V_34 )
{
}
static int T_3 F_13 ( struct V_53 * V_54 )
{
struct V_37 * V_38 ;
struct V_55 * V_56 , * V_57 , * V_58 ;
struct V_55 V_59 [] = {
F_14 ( 0x40000000 , V_60 ) ,
{ . V_5 = V_61 } ,
} ;
struct V_62 V_63 = {
. V_64 = & V_54 -> V_54 ,
. V_65 = L_2 ,
. V_66 = 0 ,
. V_67 = V_59 ,
. V_68 = F_15 ( V_59 ) ,
. V_69 = & V_70 ,
. V_71 = sizeof( V_70 ) ,
. V_72 = 0xffffffffUL ,
} ;
struct V_55 V_73 [] = {
F_16 ( V_74 ,
0x02000000 , L_3 ) ,
F_16 ( V_74 + 0x02000000 ,
0x02000000 , L_4 ) ,
{ . V_5 = V_61 } ,
} ;
struct V_62 V_75 = {
. V_64 = & V_54 -> V_54 ,
. V_65 = L_5 ,
. V_66 = 0 ,
. V_67 = V_73 ,
. V_68 = F_15 ( V_73 ) ,
} ;
int V_22 , V_34 ;
if ( V_4 )
return - V_76 ;
V_34 = V_22 = F_17 ( V_54 , 0 ) ;
if ( V_22 < 0 )
goto V_77;
V_56 = F_18 ( V_54 , V_78 , 0 ) ;
V_58 = F_18 ( V_54 , V_78 , 1 ) ;
V_57 = F_18 ( V_54 , V_78 , 2 ) ;
if ( ! V_56 || ! V_58 || ! V_57 ) {
V_22 = - V_79 ;
goto V_77;
}
V_38 = F_19 ( sizeof( * V_38 ) , V_80 ) ;
if ( ! V_38 ) {
V_22 = - V_81 ;
goto V_77;
}
V_38 -> V_3 = F_20 ( V_56 -> V_82 , V_83 ) ;
if ( ! V_38 -> V_3 ) {
V_22 = - V_81 ;
goto V_84;
}
if ( F_3 ( V_38 -> V_3 + V_85 ) != 0x11 ) {
F_21 ( & V_54 -> V_54 , L_6 ,
F_3 ( V_38 -> V_3 + V_85 ) ) ;
V_22 = - V_86 ;
goto V_87;
}
V_22 = F_22 ( - 1 , V_88 , V_89 , - 1 ) ;
if ( V_22 <= 0 ) {
F_23 ( & V_54 -> V_54 , L_7 ,
V_89 , V_22 ) ;
if ( V_22 == 0 )
V_22 = - V_81 ;
goto V_90;
}
V_38 -> V_48 = V_22 ;
F_24 ( V_38 -> V_48 + V_49 , & V_91 ,
V_92 ) ;
F_25 ( V_38 -> V_48 + V_49 , V_93 | V_94 ) ;
F_24 ( V_38 -> V_48 + V_50 , & V_91 ,
V_92 ) ;
F_25 ( V_38 -> V_48 + V_50 , V_93 | V_94 ) ;
F_26 ( V_38 -> V_48 + V_52 , & V_91 ) ;
F_27 ( V_34 , V_95 ) ;
F_28 ( V_34 , V_38 ) ;
F_29 ( V_34 , F_9 ) ;
#if 0
enable_irq_wake(irq);
#endif
F_30 ( & V_54 -> V_54 , L_8 ,
V_38 -> V_48 , V_38 -> V_48 + V_89 - 1 ) ;
V_4 = V_38 -> V_3 ;
F_31 ( & V_96 ) ;
F_32 () ;
F_4 ( V_97 , V_38 -> V_3 + V_7 ) ;
V_59 [ 0 ] . V_64 = V_57 ;
V_59 [ 1 ] . V_82 = V_38 -> V_48 + V_52 ;
V_59 [ 1 ] . V_98 = V_38 -> V_48 + V_52 ;
V_38 -> V_99 = F_33 ( & V_63 ) ;
V_73 [ 0 ] . V_64 = V_58 ;
V_73 [ 1 ] . V_64 = V_58 ;
V_73 [ 2 ] . V_82 = V_38 -> V_48 + V_49 ;
V_73 [ 2 ] . V_98 = V_38 -> V_48 + V_49 ;
V_38 -> V_100 = F_33 ( & V_75 ) ;
F_34 ( V_54 , V_38 ) ;
return 0 ;
V_90:
V_87:
F_35 ( V_38 -> V_3 ) ;
V_84:
F_36 ( V_38 ) ;
V_77:
return V_22 ;
}
static int T_4 F_37 ( struct V_53 * V_54 )
{
struct V_37 * V_38 = F_38 ( V_54 ) ;
int V_34 = F_17 ( V_54 , 0 ) ;
if ( ! F_39 ( V_38 -> V_99 ) )
F_40 ( V_38 -> V_99 ) ;
if ( ! F_39 ( V_38 -> V_100 ) )
F_40 ( V_38 -> V_100 ) ;
F_29 ( V_34 , NULL ) ;
F_41 ( V_38 -> V_48 , V_89 ) ;
V_4 = NULL ;
F_35 ( V_38 -> V_3 ) ;
F_36 ( V_38 ) ;
return 0 ;
}
static int F_42 ( struct V_101 * V_54 )
{
struct V_37 * V_38 = F_43 ( V_54 ) ;
V_38 -> V_102 = F_3 ( V_38 -> V_3 + V_7 ) ;
V_38 -> V_103 = F_3 ( V_38 -> V_3 + V_12 ) ;
return 0 ;
}
static int F_44 ( struct V_101 * V_54 )
{
struct V_37 * V_38 = F_43 ( V_54 ) ;
F_4 ( V_38 -> V_102 , V_38 -> V_3 + V_7 ) ;
F_4 ( V_38 -> V_103 , V_38 -> V_3 + V_12 ) ;
return 0 ;
}
static int T_5 F_45 ( void )
{
return F_46 ( & V_104 ) ;
}
