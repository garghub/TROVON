static int F_1 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_4 )
{
if ( V_2 -> V_5 == NULL &&
V_3 >= F_2 ( V_6 , 0 ) )
return - 1 ;
V_7 -> V_8 =
( ( V_2 -> V_9 & 0xff ) << 0x10 ) |
( ( V_3 & 0xff ) << 0x08 ) |
( V_4 & 0xfc ) | ( V_2 -> V_5 ? 1 : 0 ) ;
V_7 -> V_10 |= V_11 ;
V_7 -> V_12 &= ~ V_11 ;
return 0 ;
}
static inline int F_3 ( void )
{
if ( V_7 -> V_10 & V_11 ) {
V_7 -> V_10 |= V_11 ;
V_7 -> V_12 |= V_11 ;
F_4 () ;
return V_13 ;
}
return V_14 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_15 , T_1 * V_16 )
{
if ( F_1 ( V_2 , V_3 , V_4 ) ) {
* V_16 = 0xffffffff ;
return V_13 ;
}
switch ( V_15 ) {
case 1 :
* V_16 = * ( volatile V_17 * ) ( ( unsigned long ) & V_7 -> V_18 | ( V_4 & 3 ) ) ;
break;
case 2 :
* V_16 = F_6 ( * ( volatile V_19 * ) ( ( unsigned long ) & V_7 -> V_18 | ( V_4 & 3 ) ) ) ;
break;
case 4 :
* V_16 = F_7 ( V_7 -> V_18 ) ;
break;
}
return F_3 () ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_15 , T_1 V_16 )
{
if ( F_1 ( V_2 , V_3 , V_4 ) )
return V_13 ;
switch ( V_15 ) {
case 1 :
* ( volatile V_17 * ) ( ( unsigned long ) & V_7 -> V_18 | ( V_4 & 3 ) ) = V_16 ;
break;
case 2 :
* ( volatile V_19 * ) ( ( unsigned long ) & V_7 -> V_18 | ( V_4 & 2 ) ) =
F_9 ( V_16 ) ;
break;
case 4 :
V_7 -> V_18 = F_10 ( V_16 ) ;
}
return F_3 () ;
}
void T_2 F_11 ( struct V_20 * V_21 ,
unsigned long V_22 , int V_23 )
{
unsigned long V_24 ;
unsigned long V_25 =
V_21 -> V_26 -> V_27 + V_28 - V_29 ;
unsigned long V_30 =
V_21 -> V_26 -> V_31 - V_21 -> V_26 -> V_27 ;
unsigned long V_32 =
V_21 -> V_26 -> V_27 - V_21 -> V_33 ;
unsigned long V_34 =
V_21 -> V_35 -> V_27 ;
unsigned long V_36 =
V_21 -> V_35 -> V_31 - V_21 -> V_35 -> V_27 ;
unsigned long V_37 =
V_21 -> V_35 -> V_27 - V_21 -> V_38 ;
F_12 ( V_39 L_1 ,
V_7 -> V_40 , V_7 -> V_41 ,
V_7 -> V_42 ,
V_23 ? L_2 : L_3 ) ;
V_21 -> V_43 = & V_44 ;
F_13 ( V_24 ) ;
V_7 -> V_45 = V_46 ;
#ifdef F_14
V_7 -> V_45 |= V_47 |
V_48 |
V_49 | V_50 ;
#endif
V_7 -> V_51 = ~ ( V_30 - 1 ) ;
V_7 -> V_52 = V_25 ;
V_7 -> V_53 = V_32 ;
V_7 -> V_54 = ~ ( V_36 - 1 ) ;
V_7 -> V_55 = V_34 ;
V_7 -> V_56 = V_37 ;
V_7 -> V_57 = 0xffffffff ;
V_7 -> V_58 = 0 ;
V_7 -> V_59 = 0 ;
V_7 -> V_60 = ~ ( V_22 - 1 ) ;
V_7 -> V_61 = 0 ;
V_7 -> V_62 = 0 ;
V_7 -> V_45 |= V_63 | V_64 ;
V_7 -> V_65 = V_66 ;
V_7 -> V_67 = V_66 ;
V_7 -> V_10 = V_68 ;
V_7 -> V_12 = V_68 ;
V_7 -> V_69 = V_70 ;
V_7 -> V_71 = V_72 | V_73 ;
if ( ! V_23 )
V_7 -> V_74 = V_75 ;
V_7 -> V_76 = V_77 |
V_78 |
V_79 |
V_80 | V_81 ;
F_15 ( V_24 ) ;
}
static T_3 F_16 ( int V_82 , void * V_83 )
{
struct V_84 * V_85 = F_17 () ;
if ( V_86 != V_87 ) {
F_12 ( V_88 L_4 ,
V_85 -> V_89 ) ;
F_12 ( V_88 L_5 ,
V_7 -> V_10 , V_7 -> V_65 ) ;
}
if ( V_86 != V_90 ) {
V_7 -> V_10 |= V_68 ;
V_7 -> V_91 = V_92 ;
V_7 -> V_93 = V_94 ;
V_7 -> V_65 = V_66 ;
return V_95 ;
}
F_18 () ;
F_19 ( L_6 ) ;
}
void T_2 F_20 ( void )
{
if ( F_21 ( V_96 + V_70 ,
F_16 ,
V_97 , L_7 ,
( void * ) V_98 ) )
F_12 ( V_88 L_8 ) ;
}
