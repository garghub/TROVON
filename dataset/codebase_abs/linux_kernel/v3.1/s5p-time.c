static void F_1 ( enum V_1 V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_4 ) ;
switch ( V_2 ) {
case V_5 :
V_3 &= ~ V_6 ;
break;
case V_7 :
V_3 &= ~ V_8 ;
break;
case V_9 :
V_3 &= ~ V_10 ;
break;
case V_11 :
V_3 &= ~ V_12 ;
break;
case V_13 :
V_3 &= ~ V_14 ;
break;
default:
F_3 ( V_15 L_1 , V_2 ) ;
break;
}
F_4 ( V_3 , V_4 ) ;
}
static void F_5 ( enum V_1 V_2 , unsigned long V_16 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_4 ) ;
V_16 -- ;
switch ( V_2 ) {
case V_5 :
V_3 &= ~ ( 0x0f << 0 ) ;
V_3 |= V_17 ;
break;
case V_7 :
V_3 &= ~ ( 0x0f << 8 ) ;
V_3 |= V_18 ;
break;
case V_9 :
V_3 &= ~ ( 0x0f << 12 ) ;
V_3 |= V_19 ;
break;
case V_11 :
V_3 &= ~ ( 0x0f << 16 ) ;
V_3 |= V_20 ;
break;
case V_13 :
V_3 &= ~ ( 0x07 << 20 ) ;
V_3 |= V_21 ;
break;
default:
F_3 ( V_15 L_1 , V_2 ) ;
break;
}
F_4 ( V_16 , F_6 ( V_2 ) ) ;
F_4 ( V_16 , F_7 ( V_2 ) ) ;
F_4 ( V_3 , V_4 ) ;
}
static void F_8 ( enum V_1 V_2 , bool V_22 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_4 ) ;
switch ( V_2 ) {
case V_5 :
V_3 |= V_6 ;
V_3 &= ~ V_17 ;
if ( V_22 )
V_3 |= V_23 ;
else
V_3 &= ~ V_23 ;
break;
case V_7 :
V_3 |= V_8 ;
V_3 &= ~ V_18 ;
if ( V_22 )
V_3 |= V_24 ;
else
V_3 &= ~ V_24 ;
break;
case V_9 :
V_3 |= V_10 ;
V_3 &= ~ V_19 ;
if ( V_22 )
V_3 |= V_25 ;
else
V_3 &= ~ V_25 ;
break;
case V_11 :
V_3 |= V_12 ;
V_3 &= ~ V_20 ;
if ( V_22 )
V_3 |= V_26 ;
else
V_3 &= ~ V_26 ;
break;
case V_13 :
V_3 |= V_14 ;
V_3 &= ~ V_21 ;
if ( V_22 )
V_3 |= V_27 ;
else
V_3 &= ~ V_27 ;
break;
default:
F_3 ( V_15 L_1 , V_2 ) ;
break;
}
F_4 ( V_3 , V_4 ) ;
}
static int F_9 ( unsigned long V_28 ,
struct V_29 * V_30 )
{
F_5 ( V_31 . V_32 , V_28 ) ;
F_8 ( V_31 . V_32 , V_33 ) ;
return 0 ;
}
static void F_10 ( enum V_34 V_2 ,
struct V_29 * V_30 )
{
F_1 ( V_31 . V_32 ) ;
switch ( V_2 ) {
case V_35 :
F_5 ( V_31 . V_32 , V_36 ) ;
F_8 ( V_31 . V_32 , V_37 ) ;
break;
case V_38 :
break;
case V_39 :
case V_40 :
break;
case V_41 :
F_11 () ;
break;
}
}
static void F_11 ( void )
{
F_5 ( V_31 . V_32 , V_36 ) ;
F_8 ( V_31 . V_32 , V_37 ) ;
F_5 ( V_31 . V_42 , V_43 ) ;
F_8 ( V_31 . V_42 , V_37 ) ;
}
void T_1 F_12 ( enum V_1 V_44 ,
enum V_1 V_45 )
{
V_46 [ V_44 ] . V_47 . V_48 = & V_49 ;
V_46 [ V_45 ] . V_47 . V_48 = & V_49 ;
V_31 . V_32 = V_44 ;
V_31 . V_42 = V_45 ;
}
static T_2 F_13 ( int V_50 , void * V_51 )
{
struct V_29 * V_30 = V_51 ;
V_30 -> V_52 ( V_30 ) ;
return V_53 ;
}
static void T_1 F_14 ( void )
{
unsigned long V_54 ;
unsigned long V_55 ;
unsigned int V_56 ;
struct V_57 * V_58 ;
V_54 = F_15 ( V_59 ) ;
V_58 = F_16 ( V_60 ) ;
F_17 ( V_58 , V_54 / 2 ) ;
F_17 ( V_60 , V_54 / 2 ) ;
F_18 ( V_61 , V_60 ) ;
V_55 = F_15 ( V_61 ) ;
V_36 = V_55 / V_62 ;
F_19 ( & V_63 ,
V_55 , V_64 ) ;
V_63 . V_65 =
F_20 ( - 1 , & V_63 ) ;
V_63 . V_66 =
F_20 ( 1 , & V_63 ) ;
V_63 . V_67 = F_21 ( 0 ) ;
F_22 ( & V_63 ) ;
V_56 = V_31 . V_32 + V_68 ;
F_23 ( V_56 , & V_69 ) ;
}
static void T_3 * F_24 ( void )
{
unsigned long V_70 = 0 ;
switch ( V_31 . V_42 ) {
case V_5 :
case V_7 :
case V_9 :
case V_11 :
V_70 = ( V_31 . V_42 * 0x0c ) + 0x14 ;
break;
case V_13 :
V_70 = 0x40 ;
break;
default:
F_3 ( V_15 L_1 , V_31 . V_42 ) ;
return NULL ;
}
return F_25 ( V_70 ) ;
}
unsigned long long T_4 F_26 ( void )
{
void T_3 * V_71 = F_24 () ;
if ( ! V_71 )
return 0 ;
return F_27 ( & V_72 , ~ F_2 ( V_71 ) , ( V_73 ) ~ 0 ) ;
}
static void T_4 F_28 ( void )
{
void T_3 * V_71 = F_24 () ;
if ( ! V_71 )
return;
F_29 ( & V_72 , ~ F_2 ( V_71 ) , ( V_73 ) ~ 0 ) ;
}
static void T_1 F_30 ( void )
{
unsigned long V_54 ;
unsigned long V_55 ;
V_54 = F_15 ( V_59 ) ;
F_17 ( V_74 , V_54 / 2 ) ;
F_18 ( V_75 , V_74 ) ;
V_55 = F_15 ( V_75 ) ;
F_5 ( V_31 . V_42 , V_43 ) ;
F_8 ( V_31 . V_42 , V_37 ) ;
F_31 ( & V_72 , F_28 , 32 , V_55 ) ;
if ( F_32 ( F_24 () , L_2 ,
V_55 , 250 , 32 , V_76 ) )
F_33 ( L_3 ) ;
}
static void T_1 F_34 ( void )
{
unsigned long V_32 = V_31 . V_32 ;
unsigned long V_42 = V_31 . V_42 ;
char V_77 [ 15 ] ;
V_59 = F_35 ( NULL , L_4 ) ;
if ( F_36 ( V_59 ) )
F_33 ( L_5 ) ;
F_37 ( V_59 ) ;
sprintf ( V_77 , L_6 , V_32 ) ;
V_46 [ V_32 ] . V_78 = V_32 ;
V_46 [ V_32 ] . V_47 . V_79 = V_77 ;
V_61 = F_35 ( & V_46 [ V_32 ] . V_47 , L_7 ) ;
if ( F_36 ( V_61 ) )
F_33 ( L_8 ) ;
V_60 = F_35 ( & V_46 [ V_32 ] . V_47 , L_9 ) ;
if ( F_36 ( V_60 ) )
F_33 ( L_10 ) ;
F_37 ( V_61 ) ;
sprintf ( V_77 , L_6 , V_42 ) ;
V_46 [ V_42 ] . V_78 = V_42 ;
V_46 [ V_42 ] . V_47 . V_79 = V_77 ;
V_75 = F_35 ( & V_46 [ V_42 ] . V_47 , L_7 ) ;
if ( F_36 ( V_75 ) )
F_33 ( L_11 ) ;
V_74 = F_35 ( & V_46 [ V_42 ] . V_47 , L_9 ) ;
if ( F_36 ( V_74 ) )
F_33 ( L_12 ) ;
F_37 ( V_75 ) ;
}
static void T_1 F_38 ( void )
{
F_34 () ;
F_14 () ;
F_30 () ;
}
