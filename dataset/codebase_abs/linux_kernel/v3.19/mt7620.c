static T_1 T_2
F_1 ( T_2 V_1 , T_2 V_2 , T_2 div )
{
T_3 V_3 ;
V_3 = V_1 ;
V_3 *= V_2 ;
F_2 ( V_3 , div ) ;
return V_3 ;
}
static T_1 unsigned long
F_3 ( void )
{
T_2 V_4 ;
V_4 = F_4 ( V_5 ) ;
if ( V_4 & V_6 )
return F_5 ( 40 ) ;
return F_5 ( 20 ) ;
}
static T_1 unsigned long
F_6 ( unsigned long V_7 )
{
T_2 V_4 ;
V_4 = F_4 ( V_8 ) ;
if ( V_4 & V_9 )
return V_7 ;
return F_5 ( 40 ) ;
}
static T_1 unsigned long
F_7 ( unsigned long V_7 )
{
T_2 V_4 ;
T_2 V_2 ;
T_2 div ;
V_4 = F_4 ( V_10 ) ;
if ( V_4 & V_11 )
return V_7 ;
if ( ( V_4 & V_12 ) == 0 )
return F_5 ( 600 ) ;
V_2 = ( V_4 >> V_13 ) &
V_14 ;
V_2 += 24 ;
if ( V_4 & V_15 )
V_2 *= 2 ;
div = ( V_4 >> V_16 ) &
V_17 ;
F_8 ( div >= F_9 ( V_18 ) ) ;
return F_1 ( V_7 , V_2 , V_18 [ div ] ) ;
}
static T_1 unsigned long
F_10 ( unsigned long V_7 , unsigned long V_19 )
{
T_2 V_4 ;
V_4 = F_4 ( V_20 ) ;
if ( V_4 & V_21 )
return V_7 ;
if ( V_4 & V_22 )
return F_5 ( 480 ) ;
return V_19 ;
}
static T_1 unsigned long
F_11 ( unsigned long V_23 )
{
T_2 V_4 ;
T_2 V_2 ;
T_2 div ;
V_4 = F_4 ( V_24 ) ;
V_2 = V_4 & V_25 ;
div = ( V_4 >> V_26 ) &
V_27 ;
return F_1 ( V_23 , V_2 , div ) ;
}
static T_1 unsigned long
F_12 ( unsigned long V_23 )
{
if ( V_28 == V_29 )
return V_23 / 4 ;
return V_23 / 3 ;
}
static T_1 unsigned long
F_13 ( unsigned long V_30 )
{
T_2 V_4 ;
T_2 V_31 ;
T_2 div ;
V_4 = F_4 ( V_24 ) ;
V_31 = ( V_4 >> V_32 ) &
V_33 ;
if ( F_8 ( V_31 >= F_9 ( V_34 ) ) )
return V_30 ;
div = V_34 [ V_31 ] ;
if ( F_14 ( ! div , L_1 , V_31 ) )
return V_30 ;
return V_30 / div ;
}
void T_1 F_15 ( void )
{
unsigned long V_7 ;
unsigned long V_19 ;
unsigned long V_23 ;
unsigned long V_30 ;
unsigned long V_35 ;
unsigned long V_36 ;
unsigned long V_37 ;
V_7 = F_3 () ;
#define F_16 ( T_4 ) label ":%lu.%03luMHz "
#define F_17 ( T_5 ) ((x) / 1000000)
#define F_18 ( T_5 ) (((x) / 1000) % 1000)
if ( V_38 == V_39 ) {
if ( V_7 == F_5 ( 40 ) )
V_30 = F_5 ( 580 ) ;
else
V_30 = F_5 ( 575 ) ;
V_36 = V_35 = V_30 / 3 ;
V_37 = F_5 ( 40 ) ;
F_19 ( L_2 , V_37 ) ;
F_19 ( L_3 , V_37 ) ;
} else {
V_19 = F_7 ( V_7 ) ;
V_23 = F_10 ( V_7 , V_19 ) ;
V_30 = F_11 ( V_23 ) ;
V_36 = F_12 ( V_23 ) ;
V_35 = F_13 ( V_30 ) ;
V_37 = F_6 ( V_7 ) ;
F_20 ( F_16 ( L_4 ) F_16 ( L_5 ) F_16 ( L_6 ) ,
F_17 ( V_7 ) , F_18 ( V_7 ) ,
F_17 ( V_19 ) , F_18 ( V_19 ) ,
F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
F_19 ( L_7 , V_37 ) ;
}
F_20 ( F_16 ( L_8 ) F_16 ( L_9 ) F_16 ( L_10 ) F_16 ( L_11 ) ,
F_17 ( V_30 ) , F_18 ( V_30 ) ,
F_17 ( V_36 ) , F_18 ( V_36 ) ,
F_17 ( V_35 ) , F_18 ( V_35 ) ,
F_17 ( V_37 ) , F_18 ( V_37 ) ) ;
#undef F_18
#undef F_17
#undef F_16
F_19 ( L_12 , V_30 ) ;
F_19 ( L_13 , V_37 ) ;
F_19 ( L_14 , V_37 ) ;
F_19 ( L_15 , V_35 ) ;
F_19 ( L_16 , V_37 ) ;
F_19 ( L_17 , V_7 ) ;
}
void T_1 F_21 ( void )
{
V_40 = F_22 ( L_18 ) ;
V_41 = F_22 ( L_19 ) ;
if ( ! V_40 || ! V_41 )
F_23 ( L_20 ) ;
}
static T_1 void
F_24 ( struct V_42 * V_43 )
{
switch ( V_28 ) {
case V_29 :
F_25 ( L_21 ) ;
V_43 -> V_44 = V_45 ;
V_43 -> V_46 = V_47 ;
break;
case V_48 :
F_25 ( L_22 ) ;
V_43 -> V_44 = V_49 ;
V_43 -> V_46 = V_50 ;
break;
case V_51 :
F_25 ( L_23 ) ;
V_43 -> V_44 = V_52 ;
V_43 -> V_46 = V_53 ;
break;
default:
F_26 () ;
}
}
static T_1 void
F_27 ( struct V_42 * V_43 )
{
switch ( V_28 ) {
case V_54 :
F_25 ( L_22 ) ;
V_43 -> V_44 = V_49 ;
V_43 -> V_46 = V_50 ;
break;
case V_55 :
F_25 ( L_23 ) ;
V_43 -> V_44 = V_52 ;
V_43 -> V_46 = V_53 ;
break;
default:
F_26 () ;
}
}
void F_28 ( struct V_42 * V_43 )
{
void T_6 * V_56 = ( void T_6 * ) F_29 ( V_57 ) ;
unsigned char * V_58 = NULL ;
T_2 V_59 ;
T_2 V_60 ;
T_2 V_61 ;
T_2 V_62 ;
T_2 V_63 ;
T_2 V_64 ;
T_2 V_65 ;
V_59 = F_30 ( V_56 + V_66 ) ;
V_60 = F_30 ( V_56 + V_67 ) ;
V_61 = F_30 ( V_56 + V_68 ) ;
V_65 = ( V_61 >> V_69 ) & V_70 ;
if ( V_59 == V_71 && V_60 == V_72 ) {
if ( V_65 ) {
V_38 = V_73 ;
V_58 = L_24 ;
V_43 -> V_74 = L_25 ;
} else {
V_38 = V_75 ;
V_58 = L_26 ;
V_43 -> V_74 = L_27 ;
#ifdef F_31
F_23 ( L_28 ) ;
#endif
}
} else if ( V_59 == V_71 && V_60 == V_76 ) {
V_38 = V_39 ;
V_58 = L_29 ;
V_43 -> V_74 = L_30 ;
} else {
F_23 ( L_31 , V_59 , V_60 ) ;
}
snprintf ( V_43 -> V_77 , V_78 ,
L_32 ,
V_58 ,
( V_61 >> V_79 ) & V_80 ,
( V_61 & V_81 ) ) ;
V_62 = F_30 ( V_56 + V_5 ) ;
V_28 = ( V_62 >> V_82 ) & V_83 ;
V_43 -> V_84 = V_85 ;
if ( V_38 == V_39 )
F_27 ( V_43 ) ;
else
F_24 ( V_43 ) ;
V_63 = F_30 ( V_56 + V_86 ) ;
V_64 = F_30 ( V_56 + V_87 ) ;
F_25 ( L_33 ,
( V_63 & V_88 ) ? ( L_34 ) : ( L_35 ) ) ;
F_25 ( L_36 ,
( V_64 & V_89 ) ? ( L_34 ) : ( L_35 ) ) ;
if ( V_38 == V_39 )
V_90 = V_91 ;
else
V_90 = V_92 ;
}
