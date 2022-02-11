static inline int F_1 ( void )
{
return V_1 == V_2 ||
V_1 == V_3 ;
}
static T_1 T_2
F_2 ( T_2 V_4 , T_2 V_5 , T_2 div )
{
T_3 V_6 ;
V_6 = V_4 ;
V_6 *= V_5 ;
F_3 ( V_6 , div ) ;
return V_6 ;
}
static T_1 unsigned long
F_4 ( void )
{
T_2 V_7 ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 & V_9 )
return F_6 ( 40 ) ;
return F_6 ( 20 ) ;
}
static T_1 unsigned long
F_7 ( unsigned long V_10 )
{
T_2 V_7 ;
V_7 = F_5 ( V_11 ) ;
if ( V_7 & V_12 )
return V_10 ;
return F_6 ( 40 ) ;
}
static T_1 unsigned long
F_8 ( unsigned long V_10 )
{
T_2 V_7 ;
T_2 V_5 ;
T_2 div ;
V_7 = F_5 ( V_13 ) ;
if ( V_7 & V_14 )
return V_10 ;
if ( ( V_7 & V_15 ) == 0 )
return F_6 ( 600 ) ;
V_5 = ( V_7 >> V_16 ) &
V_17 ;
V_5 += 24 ;
if ( V_7 & V_18 )
V_5 *= 2 ;
div = ( V_7 >> V_19 ) &
V_20 ;
F_9 ( div >= F_10 ( V_21 ) ) ;
return F_2 ( V_10 , V_5 , V_21 [ div ] ) ;
}
static T_1 unsigned long
F_11 ( unsigned long V_10 , unsigned long V_22 )
{
T_2 V_7 ;
V_7 = F_5 ( V_23 ) ;
if ( V_7 & V_24 )
return V_10 ;
if ( V_7 & V_25 )
return F_6 ( 480 ) ;
return V_22 ;
}
static T_1 unsigned long
F_12 ( unsigned long V_26 )
{
T_2 V_7 ;
T_2 V_5 ;
T_2 div ;
V_7 = F_5 ( V_27 ) ;
V_5 = V_7 & V_28 ;
div = ( V_7 >> V_29 ) &
V_30 ;
return F_2 ( V_26 , V_5 , div ) ;
}
static T_1 unsigned long
F_13 ( unsigned long V_26 )
{
if ( V_31 == V_32 )
return V_26 / 4 ;
return V_26 / 3 ;
}
static T_1 unsigned long
F_14 ( unsigned long V_33 )
{
T_2 V_7 ;
T_2 V_34 ;
T_2 div ;
V_7 = F_5 ( V_27 ) ;
V_34 = ( V_7 >> V_35 ) &
V_36 ;
if ( F_9 ( V_34 >= F_10 ( V_37 ) ) )
return V_33 ;
div = V_37 [ V_34 ] ;
if ( F_15 ( ! div , L_1 , V_34 ) )
return V_33 ;
return V_33 / div ;
}
void T_1 F_16 ( void )
{
unsigned long V_10 ;
unsigned long V_22 ;
unsigned long V_26 ;
unsigned long V_33 ;
unsigned long V_38 ;
unsigned long V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
V_10 = F_4 () ;
#define F_17 ( T_4 ) label ":%lu.%03luMHz "
#define F_18 ( T_5 ) ((x) / 1000000)
#define F_19 ( T_5 ) (((x) / 1000) % 1000)
if ( F_1 () ) {
if ( V_10 == F_6 ( 40 ) )
V_33 = F_6 ( 580 ) ;
else
V_33 = F_6 ( 575 ) ;
V_39 = V_38 = V_33 / 3 ;
V_40 = F_6 ( 40 ) ;
V_41 = F_6 ( 480 ) ;
F_20 ( L_2 , V_40 ) ;
F_20 ( L_3 , V_40 ) ;
} else {
V_22 = F_8 ( V_10 ) ;
V_26 = F_11 ( V_10 , V_22 ) ;
V_33 = F_12 ( V_26 ) ;
V_39 = F_13 ( V_26 ) ;
V_38 = F_14 ( V_33 ) ;
V_40 = F_7 ( V_10 ) ;
V_41 = V_40 ;
F_21 ( F_17 ( L_4 ) F_17 ( L_5 ) F_17 ( L_6 ) ,
F_18 ( V_10 ) , F_19 ( V_10 ) ,
F_18 ( V_22 ) , F_19 ( V_22 ) ,
F_18 ( V_26 ) , F_19 ( V_26 ) ) ;
F_20 ( L_7 , V_40 ) ;
}
F_21 ( F_17 ( L_8 ) F_17 ( L_9 ) F_17 ( L_10 ) F_17 ( L_11 ) ,
F_18 ( V_33 ) , F_19 ( V_33 ) ,
F_18 ( V_39 ) , F_19 ( V_39 ) ,
F_18 ( V_38 ) , F_19 ( V_38 ) ,
F_18 ( V_40 ) , F_19 ( V_40 ) ) ;
#undef F_19
#undef F_18
#undef F_17
F_20 ( L_12 , V_33 ) ;
F_20 ( L_13 , V_40 ) ;
F_20 ( L_14 , V_40 ) ;
F_20 ( L_15 , V_40 ) ;
F_20 ( L_16 , V_41 ) ;
F_20 ( L_17 , V_38 ) ;
F_20 ( L_18 , V_38 ) ;
F_20 ( L_19 , V_40 ) ;
F_20 ( L_20 , V_40 ) ;
F_20 ( L_21 , V_40 ) ;
F_20 ( L_22 , V_10 ) ;
if ( F_22 ( V_42 ) && ! F_1 () ) {
T_2 V_43 = F_5 ( V_27 ) ;
V_43 &= ~ ( V_44 | V_45 ) ;
V_43 |= V_46 | V_47 ;
F_23 ( V_43 , V_27 ) ;
}
}
void T_1 F_24 ( void )
{
V_48 = F_25 ( L_23 ) ;
V_49 = F_25 ( L_24 ) ;
if ( ! V_48 || ! V_49 )
F_26 ( L_25 ) ;
}
static T_1 void
F_27 ( struct V_50 * V_51 )
{
switch ( V_31 ) {
case V_32 :
F_28 ( L_26 ) ;
V_51 -> V_52 = V_53 ;
V_51 -> V_54 = V_55 ;
break;
case V_56 :
F_28 ( L_27 ) ;
V_51 -> V_52 = V_57 ;
V_51 -> V_54 = V_58 ;
break;
case V_59 :
F_28 ( L_28 ) ;
V_51 -> V_52 = V_60 ;
V_51 -> V_54 = V_61 ;
break;
default:
F_29 () ;
}
}
static T_1 void
F_30 ( struct V_50 * V_51 )
{
switch ( V_31 ) {
case V_62 :
F_28 ( L_27 ) ;
V_51 -> V_52 = V_57 ;
V_51 -> V_54 = V_58 ;
break;
case V_63 :
F_28 ( L_28 ) ;
V_51 -> V_52 = V_60 ;
V_51 -> V_54 = V_61 ;
break;
default:
F_29 () ;
}
}
void F_31 ( struct V_50 * V_51 )
{
void T_6 * V_64 = ( void T_6 * ) F_32 ( V_65 ) ;
unsigned char * V_66 = NULL ;
T_2 V_67 ;
T_2 V_68 ;
T_2 V_69 ;
T_2 V_70 ;
T_2 V_71 ;
T_2 V_72 ;
T_2 V_73 ;
V_67 = F_33 ( V_64 + V_74 ) ;
V_68 = F_33 ( V_64 + V_75 ) ;
V_69 = F_33 ( V_64 + V_76 ) ;
V_73 = ( V_69 >> V_77 ) & V_78 ;
if ( V_67 == V_79 && V_68 == V_80 ) {
if ( V_73 ) {
V_1 = V_81 ;
V_66 = L_29 ;
V_51 -> V_82 = L_30 ;
} else {
V_1 = V_83 ;
V_66 = L_31 ;
V_51 -> V_82 = L_32 ;
}
} else if ( V_67 == V_79 && V_68 == V_84 ) {
T_2 V_85 = F_33 ( V_64 + V_86 ) ;
if ( V_85 & V_87 ) {
V_1 = V_3 ;
V_66 = L_33 ;
} else {
V_1 = V_2 ;
V_66 = L_34 ;
}
V_51 -> V_82 = L_35 ;
} else {
F_26 ( L_36 , V_67 , V_68 ) ;
}
snprintf ( V_51 -> V_88 , V_89 ,
L_37 ,
V_66 ,
( V_69 >> V_90 ) & V_91 ,
( V_69 & V_92 ) ) ;
V_70 = F_33 ( V_64 + V_8 ) ;
if ( F_1 () ) {
V_31 = V_70 & V_93 ;
} else {
V_31 = ( V_70 >> V_94 ) &
V_95 ;
if ( V_31 == V_96 )
V_31 = V_32 ;
}
V_51 -> V_97 = V_98 ;
if ( F_1 () )
F_30 ( V_51 ) ;
else
F_27 ( V_51 ) ;
V_71 = F_33 ( V_64 + V_99 ) ;
V_72 = F_33 ( V_64 + V_100 ) ;
F_28 ( L_38 ,
( V_71 & V_101 ) ? ( L_39 ) : ( L_40 ) ) ;
F_28 ( L_41 ,
( V_72 & V_102 ) ? ( L_39 ) : ( L_40 ) ) ;
if ( F_1 () )
V_103 = V_104 ;
else
V_103 = V_105 ;
}
