static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_4 &= ~ V_1 ;
V_4 |= V_2 ;
F_3 ( V_4 , V_5 ) ;
F_4 ( V_3 ) ;
}
static inline int F_5 ( int V_6 )
{
return 1 << ( V_6 + 16 ) ;
}
static void F_6 ( struct V_7 * V_8 ,
unsigned V_6 , int V_9 )
{
int V_10 = F_5 ( V_6 ) ;
F_1 ( V_9 ? 0 : V_10 ,
V_9 ? V_10 : 0 ) ;
}
static int F_7 ( struct V_7 * V_8 ,
unsigned V_6 , int V_9 )
{
F_6 ( V_8 , V_6 , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 ,
unsigned V_6 )
{
return ( V_4 >> ( V_6 + 16 ) ) & 1 ;
}
static int F_9 ( struct V_11 * V_12 )
{
return F_10 ( F_11 ( 2 ) , L_1 ) ;
}
static int F_12 ( void )
{
return ! F_13 ( F_11 ( 2 ) ) ;
}
static void F_14 ( struct V_11 * V_12 )
{
F_15 ( F_11 ( 2 ) ) ;
}
static int F_16 ( void )
{
int V_13 ;
V_13 = F_10 ( V_14 , L_2 ) ;
if ( V_13 )
return V_13 ;
F_17 ( V_14 , 0 ) ;
return 0 ;
}
static void F_18 ( void )
{
F_15 ( V_14 ) ;
}
static void F_19 ( void )
{
F_20 ( V_14 , 1 ) ;
}
static void F_21 ( void )
{
F_20 ( V_14 , 0 ) ;
}
int F_22 ( struct V_15 * V_16 , int V_17 ,
unsigned long * V_18 , unsigned long * V_19 )
{
int V_20 , V_21 , V_22 ;
int V_23 = V_16 ? F_23 ( V_16 ) : - V_24 ;
switch ( V_23 ) {
case V_25 :
V_20 = F_24 ( 7 ) ;
V_21 = F_24 ( 1 ) ;
V_22 = F_24 ( 3 ) ;
break;
case V_26 :
V_20 = F_24 ( 1 ) ;
V_21 = F_24 ( 7 ) ;
V_22 = F_24 ( 3 ) ;
break;
default:
V_20 = F_24 ( 3 ) ;
V_21 = F_24 ( 1 ) ;
V_22 = F_24 ( 7 ) ;
break;
}
if ( V_18 && V_19 && ! * V_18 && ! * V_19 )
* V_18 = * V_19 = 500 ;
F_25 ( & V_27 ) ;
switch ( V_17 ) {
case V_28 :
case V_29 :
if ( ! F_13 ( V_21 ) &&
! F_13 ( V_22 ) )
F_20 ( V_30 , 0 ) ;
F_20 ( V_20 , 0 ) ;
if ( F_26 ( V_23 ) )
F_20 ( V_23 , V_17 ) ;
break;
case V_31 :
if ( F_26 ( V_23 ) )
F_20 ( V_23 , 0 ) ;
F_20 ( V_30 , 1 ) ;
F_20 ( V_20 , 1 ) ;
break;
}
F_27 ( & V_27 ) ;
return 0 ;
}
static void F_28 ( unsigned char V_32 , unsigned short V_33 )
{
switch ( V_32 ) {
case V_34 :
F_20 ( V_35 , 0 ) ;
break;
case V_36 :
case V_37 :
F_20 ( V_35 , 1 ) ;
break;
default:
break;
}
}
static int F_29 ( struct V_11 * V_12 )
{
F_10 ( F_30 ( 0 ) , L_3 ) ;
F_17 ( F_30 ( 0 ) , 0 ) ;
F_31 ( F_30 ( 0 ) , V_38 ) ;
F_32 ( F_30 ( 0 ) , V_39 ) ;
F_20 ( V_40 , 1 ) ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 , int V_41 )
{
if ( ! V_41 ) {
F_17 ( F_30 ( 0 ) , 1 ) ;
F_20 ( V_40 , 0 ) ;
} else {
F_17 ( F_30 ( 0 ) , 0 ) ;
F_31 ( F_30 ( 0 ) , V_38 ) ;
F_32 ( F_30 ( 0 ) , V_39 ) ;
F_20 ( V_40 , 1 ) ;
}
return V_41 ;
}
static void F_34 ( struct V_11 * V_12 )
{
F_17 ( F_30 ( 0 ) , 1 ) ;
F_20 ( V_40 , 0 ) ;
}
static void F_35 ( struct V_42 * V_43 ,
unsigned int V_44 )
{
int V_9 , V_45 = 100 ;
if ( ! V_44 ) {
F_20 ( F_36 ( 0 ) , 0 ) ;
do {
V_9 = F_13 ( F_36 ( 6 ) ) ;
} while ( V_9 && V_45 -- );
F_20 ( V_46 , 0 ) ;
F_20 ( V_47 , 0 ) ;
F_20 ( V_48 , 0 ) ;
F_17 ( F_36 ( 1 ) , 0 ) ;
F_17 ( F_36 ( 4 ) , 0 ) ;
F_20 ( V_49 , 0 ) ;
F_20 ( V_50 , 0 ) ;
F_20 ( F_36 ( 5 ) , 0 ) ;
} else {
F_20 ( V_50 , 1 ) ;
F_20 ( V_49 , 1 ) ;
F_37 ( F_36 ( 1 ) ) ;
F_37 ( F_36 ( 4 ) ) ;
F_38 ( 10 ) ;
F_32 ( F_36 ( 1 ) , F_39 ( 2 ) ) ;
F_32 ( F_36 ( 4 ) , F_39 ( 2 ) ) ;
F_20 ( F_36 ( 5 ) , 1 ) ;
F_20 ( F_36 ( 0 ) , 1 ) ;
F_20 ( V_47 , 1 ) ;
F_20 ( V_46 , 1 ) ;
F_20 ( V_48 , 1 ) ;
}
}
static void T_1 F_40 ( void )
{
F_41 ( V_51 , F_42 ( V_51 ) ) ;
F_43 ( V_52 , F_42 ( V_52 ) ) ;
F_44 ( V_53 , V_54 ) ;
#ifdef F_45
memcpy ( F_46 ( V_55 ) , V_56 , 1024 ) ;
#endif
F_47 () ;
F_1 ( 0 , 0 ) ;
F_48 ( F_49 ( & V_57 ) ) ;
}
static void T_1 F_50 ( void )
{
F_51 ( 12000000 ) ;
F_52 () ;
}
static void T_1 F_53 ( void )
{
F_54 ( 0x30003000 , 0x1000 ) ;
F_54 ( 0x30081000 , 0x1000 ) ;
}
static void T_1 F_55 ( void )
{
T_2 V_58 ;
F_56 ( & V_59 ) ;
F_57 ( & V_60 ) ;
F_58 ( & V_61 ) ;
F_59 ( & V_62 ) ;
F_60 ( NULL ) ;
F_61 ( V_63 |
V_64 |
V_65 , 0x0 ) ;
V_58 = ( 0x78 << V_66 )
| ( 0x02 << V_67 )
| ( 0x03 << V_68 ) ;
F_62 ( V_58 , V_69 ) ;
F_10 ( F_36 ( 0 ) , L_4 ) ;
F_10 ( F_36 ( 1 ) , L_4 ) ;
F_10 ( F_36 ( 4 ) , L_4 ) ;
F_10 ( F_36 ( 5 ) , L_4 ) ;
F_10 ( F_36 ( 6 ) , L_4 ) ;
F_10 ( V_50 , L_4 ) ;
F_10 ( V_49 , L_4 ) ;
F_10 ( V_46 , L_4 ) ;
F_10 ( V_47 , L_4 ) ;
F_10 ( V_48 , L_4 ) ;
F_10 ( V_40 , L_4 ) ;
F_17 ( F_36 ( 0 ) , 0 ) ;
F_17 ( F_36 ( 1 ) , 0 ) ;
F_17 ( F_36 ( 4 ) , 0 ) ;
F_17 ( F_36 ( 5 ) , 0 ) ;
F_37 ( F_36 ( 6 ) ) ;
F_17 ( V_50 , 0 ) ;
F_17 ( V_49 , 0 ) ;
F_17 ( V_46 , 0 ) ;
F_17 ( V_47 , 0 ) ;
F_17 ( V_48 , 0 ) ;
F_17 ( V_40 , 0 ) ;
F_10 ( V_35 , L_5 ) ;
F_17 ( V_35 , 0 ) ;
F_63 ( V_70 , F_42 ( V_70 ) ) ;
F_10 ( F_24 ( 1 ) , L_6 ) ;
F_10 ( F_24 ( 3 ) , L_7 ) ;
F_10 ( F_24 ( 7 ) , L_8 ) ;
F_10 ( V_30 , L_9 ) ;
F_17 ( F_24 ( 1 ) , 0 ) ;
F_17 ( F_24 ( 3 ) , 0 ) ;
F_17 ( F_24 ( 7 ) , 0 ) ;
F_17 ( V_30 , 0 ) ;
F_64 ( 0 , V_71 ,
F_42 ( V_71 ) ) ;
}
