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
int F_22 ( unsigned V_15 , int V_16 ,
unsigned long * V_17 , unsigned long * V_18 )
{
int V_19 , V_20 , V_21 ;
switch ( V_15 ) {
case V_22 :
V_19 = F_23 ( 7 ) ;
V_20 = F_23 ( 1 ) ;
V_21 = F_23 ( 3 ) ;
break;
case V_23 :
V_19 = F_23 ( 1 ) ;
V_20 = F_23 ( 7 ) ;
V_21 = F_23 ( 3 ) ;
break;
default:
V_19 = F_23 ( 3 ) ;
V_20 = F_23 ( 1 ) ;
V_21 = F_23 ( 7 ) ;
break;
}
if ( V_17 && V_18 && ! * V_17 && ! * V_18 )
* V_17 = * V_18 = 500 ;
F_24 ( & V_24 ) ;
switch ( V_16 ) {
case V_25 :
case V_26 :
if ( ! F_13 ( V_20 ) &&
! F_13 ( V_21 ) )
F_20 ( V_27 , 0 ) ;
F_20 ( V_19 , 0 ) ;
if ( F_25 ( V_15 ) )
F_20 ( V_15 , V_16 ) ;
break;
case V_28 :
if ( F_25 ( V_15 ) )
F_20 ( V_15 , 0 ) ;
F_20 ( V_27 , 1 ) ;
F_20 ( V_19 , 1 ) ;
break;
}
F_26 ( & V_24 ) ;
return 0 ;
}
static void F_27 ( unsigned char V_29 , unsigned short V_30 )
{
switch ( V_29 ) {
case V_31 :
F_20 ( V_32 , 0 ) ;
break;
case V_33 :
case V_34 :
F_20 ( V_32 , 1 ) ;
break;
default:
break;
}
}
static int F_28 ( struct V_11 * V_12 )
{
F_10 ( F_29 ( 0 ) , L_3 ) ;
F_17 ( F_29 ( 0 ) , 0 ) ;
F_30 ( F_29 ( 0 ) , V_35 ) ;
F_31 ( F_29 ( 0 ) , V_36 ) ;
F_20 ( V_37 , 1 ) ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 , int V_38 )
{
if ( ! V_38 ) {
F_17 ( F_29 ( 0 ) , 1 ) ;
F_20 ( V_37 , 0 ) ;
} else {
F_17 ( F_29 ( 0 ) , 0 ) ;
F_30 ( F_29 ( 0 ) , V_35 ) ;
F_31 ( F_29 ( 0 ) , V_36 ) ;
F_20 ( V_37 , 1 ) ;
}
return V_38 ;
}
static void F_33 ( struct V_11 * V_12 )
{
F_17 ( F_29 ( 0 ) , 1 ) ;
F_20 ( V_37 , 0 ) ;
}
static void F_34 ( struct V_39 * V_40 ,
unsigned int V_41 )
{
int V_9 , V_42 = 100 ;
if ( ! V_41 ) {
F_20 ( F_35 ( 0 ) , 0 ) ;
do {
V_9 = F_13 ( F_35 ( 6 ) ) ;
} while ( V_9 && V_42 -- );
F_20 ( V_43 , 0 ) ;
F_20 ( V_44 , 0 ) ;
F_20 ( V_45 , 0 ) ;
F_17 ( F_35 ( 1 ) , 0 ) ;
F_17 ( F_35 ( 4 ) , 0 ) ;
F_20 ( V_46 , 0 ) ;
F_20 ( V_47 , 0 ) ;
F_20 ( F_35 ( 5 ) , 0 ) ;
} else {
F_20 ( V_47 , 1 ) ;
F_20 ( V_46 , 1 ) ;
F_36 ( F_35 ( 1 ) ) ;
F_36 ( F_35 ( 4 ) ) ;
F_37 ( 10 ) ;
F_31 ( F_35 ( 1 ) , F_38 ( 2 ) ) ;
F_31 ( F_35 ( 4 ) , F_38 ( 2 ) ) ;
F_20 ( F_35 ( 5 ) , 1 ) ;
F_20 ( F_35 ( 0 ) , 1 ) ;
F_20 ( V_44 , 1 ) ;
F_20 ( V_43 , 1 ) ;
F_20 ( V_45 , 1 ) ;
}
}
static void T_1 F_39 ( void )
{
F_40 ( V_48 , F_41 ( V_48 ) ) ;
F_42 ( 0 ) ;
F_43 ( V_49 , F_41 ( V_49 ) ) ;
F_44 ( V_50 , V_51 ) ;
#ifdef F_45
memcpy ( F_46 ( V_52 ) , V_53 , 1024 ) ;
#endif
F_47 () ;
F_1 ( 0 , 0 ) ;
F_48 ( F_49 ( & V_54 ) ) ;
}
static void T_1 F_50 ( void )
{
F_51 ( 0x30003000 , 0x1000 ) ;
F_51 ( 0x30081000 , 0x1000 ) ;
}
static void T_1 F_52 ( void )
{
T_2 V_55 ;
F_53 ( & V_56 ) ;
F_54 ( & V_57 ) ;
F_55 ( & V_58 ) ;
F_56 ( & V_59 ) ;
F_57 ( NULL ) ;
F_58 ( V_60 |
V_61 |
V_62 , 0x0 ) ;
V_55 = ( 0x78 << V_63 )
| ( 0x02 << V_64 )
| ( 0x03 << V_65 ) ;
F_59 ( V_55 , V_66 ) ;
F_10 ( F_35 ( 0 ) , L_4 ) ;
F_10 ( F_35 ( 1 ) , L_4 ) ;
F_10 ( F_35 ( 4 ) , L_4 ) ;
F_10 ( F_35 ( 5 ) , L_4 ) ;
F_10 ( F_35 ( 6 ) , L_4 ) ;
F_10 ( V_47 , L_4 ) ;
F_10 ( V_46 , L_4 ) ;
F_10 ( V_43 , L_4 ) ;
F_10 ( V_44 , L_4 ) ;
F_10 ( V_45 , L_4 ) ;
F_10 ( V_37 , L_4 ) ;
F_17 ( F_35 ( 0 ) , 0 ) ;
F_17 ( F_35 ( 1 ) , 0 ) ;
F_17 ( F_35 ( 4 ) , 0 ) ;
F_17 ( F_35 ( 5 ) , 0 ) ;
F_36 ( F_35 ( 6 ) ) ;
F_17 ( V_47 , 0 ) ;
F_17 ( V_46 , 0 ) ;
F_17 ( V_43 , 0 ) ;
F_17 ( V_44 , 0 ) ;
F_17 ( V_45 , 0 ) ;
F_17 ( V_37 , 0 ) ;
F_10 ( V_32 , L_5 ) ;
F_17 ( V_32 , 0 ) ;
F_60 ( V_67 , F_41 ( V_67 ) ) ;
F_10 ( F_23 ( 1 ) , L_6 ) ;
F_10 ( F_23 ( 3 ) , L_7 ) ;
F_10 ( F_23 ( 7 ) , L_8 ) ;
F_10 ( V_27 , L_9 ) ;
F_17 ( F_23 ( 1 ) , 0 ) ;
F_17 ( F_23 ( 3 ) , 0 ) ;
F_17 ( F_23 ( 7 ) , 0 ) ;
F_17 ( V_27 , 0 ) ;
F_61 ( 0 , V_68 ,
F_41 ( V_68 ) ) ;
}
