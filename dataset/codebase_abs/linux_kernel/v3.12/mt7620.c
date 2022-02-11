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
V_19 = F_7 ( V_7 ) ;
V_23 = F_10 ( V_7 , V_19 ) ;
V_30 = F_11 ( V_23 ) ;
V_36 = F_12 ( V_23 ) ;
V_35 = F_13 ( V_30 ) ;
V_37 = F_6 ( V_7 ) ;
#define F_16 ( T_4 ) label ":%lu.%03luMHz "
#define F_17 ( T_5 ) ((x) / 1000000)
#define F_18 ( T_5 ) (((x) / 1000) % 1000)
F_19 ( F_16 ( L_2 ) F_16 ( L_3 ) F_16 ( L_4 ) ,
F_17 ( V_7 ) , F_18 ( V_7 ) ,
F_17 ( V_19 ) , F_18 ( V_19 ) ,
F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
F_19 ( F_16 ( L_5 ) F_16 ( L_6 ) F_16 ( L_7 ) F_16 ( L_8 ) ,
F_17 ( V_30 ) , F_18 ( V_30 ) ,
F_17 ( V_36 ) , F_18 ( V_36 ) ,
F_17 ( V_35 ) , F_18 ( V_35 ) ,
F_17 ( V_37 ) , F_18 ( V_37 ) ) ;
#undef F_18
#undef F_17
#undef F_16
F_20 ( L_9 , V_30 ) ;
F_20 ( L_10 , V_37 ) ;
F_20 ( L_11 , V_37 ) ;
F_20 ( L_12 , V_37 ) ;
F_20 ( L_13 , V_35 ) ;
F_20 ( L_14 , V_37 ) ;
}
void T_1 F_21 ( void )
{
V_38 = F_22 ( L_15 ) ;
V_39 = F_22 ( L_16 ) ;
if ( ! V_38 || ! V_39 )
F_23 ( L_17 ) ;
}
void F_24 ( struct V_40 * V_41 )
{
void T_6 * V_42 = ( void T_6 * ) F_25 ( V_43 ) ;
unsigned char * V_44 = NULL ;
T_2 V_45 ;
T_2 V_46 ;
T_2 V_47 ;
T_2 V_48 ;
V_45 = F_26 ( V_42 + V_49 ) ;
V_46 = F_26 ( V_42 + V_50 ) ;
if ( V_45 == V_51 && V_46 == V_52 ) {
V_44 = L_18 ;
V_41 -> V_53 = L_19 ;
} else if ( V_45 == V_54 && V_46 == V_55 ) {
V_44 = L_20 ;
V_41 -> V_53 = L_21 ;
} else {
F_23 ( L_22 , V_45 , V_46 ) ;
}
V_47 = F_26 ( V_42 + V_56 ) ;
snprintf ( V_41 -> V_57 , V_58 ,
L_23 ,
V_44 ,
( V_47 >> V_59 ) & V_60 ,
( V_47 & V_61 ) ) ;
V_48 = F_26 ( V_42 + V_5 ) ;
V_28 = ( V_48 >> V_62 ) & V_63 ;
switch ( V_28 ) {
case V_29 :
F_27 ( L_24 ) ;
V_41 -> V_64 = V_65 ;
V_41 -> V_66 = V_67 ;
break;
case V_68 :
F_27 ( L_25 ) ;
V_41 -> V_64 = V_69 ;
V_41 -> V_66 = V_70 ;
break;
case V_71 :
F_27 ( L_26 ) ;
V_41 -> V_64 = V_72 ;
V_41 -> V_66 = V_73 ;
break;
default:
F_28 () ;
}
V_41 -> V_74 = V_75 ;
}
