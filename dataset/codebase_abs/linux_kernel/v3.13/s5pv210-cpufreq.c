static void F_1 ( enum V_1 V_2 , unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
void T_1 * V_6 = NULL ;
if ( V_2 == V_7 ) {
V_6 = ( V_8 + 0x30 ) ;
} else if ( V_2 == V_9 ) {
V_6 = ( V_10 + 0x30 ) ;
} else {
F_2 ( V_11 L_1 ) ;
return;
}
V_4 = V_12 [ V_2 ] . V_3 ;
F_3 ( V_4 , V_3 ) ;
V_5 = V_12 [ V_2 ] . V_13 ;
F_3 ( V_5 , V_4 ) ;
F_4 ( V_5 , V_6 ) ;
}
static unsigned int F_5 ( unsigned int V_14 )
{
if ( V_14 )
return 0 ;
return F_6 ( V_15 ) / 1000 ;
}
static int F_7 ( struct V_16 * V_17 , unsigned int V_18 )
{
unsigned long V_6 ;
unsigned int V_19 ;
unsigned int V_20 = 0 ;
unsigned int V_21 = 0 ;
unsigned int V_22 , V_23 ;
int V_24 , V_25 ;
int V_26 = 0 ;
F_8 ( & V_27 ) ;
if ( V_28 ) {
#ifdef F_9
F_10 ( L_2
L_3 , __FILE__ , __LINE__ , V_29 ) ;
#endif
V_26 = - V_30 ;
goto exit;
}
V_22 = F_5 ( 0 ) ;
V_23 = V_31 [ V_18 ] . V_32 ;
if ( F_11 ( V_17 , V_31 ,
V_22 , V_33 ,
& V_19 ) ) {
V_26 = - V_30 ;
goto exit;
}
V_24 = V_34 [ V_18 ] . V_24 ;
V_25 = V_34 [ V_18 ] . V_25 ;
if ( V_23 > V_22 ) {
V_26 = F_12 ( V_35 ,
V_24 , V_36 ) ;
if ( V_26 )
goto exit;
V_26 = F_12 ( V_37 ,
V_25 , V_38 ) ;
if ( V_26 )
goto exit;
}
if ( ( V_18 == V_39 ) || ( V_19 == V_39 ) )
V_20 = 1 ;
if ( ( V_18 == V_40 ) || ( V_19 == V_40 ) )
V_21 = 1 ;
if ( V_21 ) {
if ( V_20 )
F_1 ( V_9 , 83000 ) ;
else
F_1 ( V_9 , 100000 ) ;
F_1 ( V_7 , 83000 ) ;
}
if ( V_20 ) {
V_6 = F_13 ( V_41 ) ;
V_6 &= ~ ( V_42 | V_43 ) ;
V_6 |= ( 3 << V_44 ) |
( 3 << V_45 ) ;
F_4 ( V_6 , V_41 ) ;
do {
V_6 = F_13 ( V_46 ) ;
} while ( V_6 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_6 = F_13 ( V_47 ) ;
V_6 &= ~ ( V_48 | V_49 ) ;
V_6 |= ( 1 << V_50 ) |
( 1 << V_51 ) ;
F_4 ( V_6 , V_47 ) ;
do {
V_6 = F_13 ( V_52 ) ;
} while ( V_6 & ( ( 1 << 7 ) | ( 1 << 3 ) ) );
if ( ! V_21 )
F_1 ( V_9 , 133000 ) ;
V_6 = F_13 ( V_53 ) ;
V_6 &= ~ ( V_54 ) ;
V_6 |= ( 0x1 << V_55 ) ;
F_4 ( V_6 , V_53 ) ;
do {
V_6 = F_13 ( V_56 ) ;
} while ( V_6 & ( 0x1 << 18 ) );
}
V_6 = F_13 ( V_57 ) ;
V_6 &= ~ ( V_58 | V_59 |
V_60 | V_61 |
V_62 | V_63 |
V_64 | V_65 ) ;
V_6 |= ( ( V_66 [ V_18 ] [ 0 ] << V_67 ) |
( V_66 [ V_18 ] [ 1 ] << V_68 ) |
( V_66 [ V_18 ] [ 2 ] << V_69 ) |
( V_66 [ V_18 ] [ 3 ] << V_70 ) |
( V_66 [ V_18 ] [ 4 ] << V_71 ) |
( V_66 [ V_18 ] [ 5 ] << V_72 ) |
( V_66 [ V_18 ] [ 6 ] << V_73 ) |
( V_66 [ V_18 ] [ 7 ] << V_74 ) ) ;
F_4 ( V_6 , V_57 ) ;
do {
V_6 = F_13 ( V_46 ) ;
} while ( V_6 & 0xff );
V_6 = F_13 ( V_75 ) ;
V_6 &= ~ 0x3 ;
if ( V_18 >= V_76 )
V_6 |= 0x3 ;
else
V_6 |= 0x1 ;
F_4 ( V_6 , V_75 ) ;
if ( V_20 ) {
F_4 ( 0x2cf , V_77 ) ;
if ( V_18 == V_39 )
F_4 ( V_78 , V_79 ) ;
else
F_4 ( V_80 , V_79 ) ;
do {
V_6 = F_13 ( V_79 ) ;
} while ( ! ( V_6 & ( 0x1 << 29 ) ) );
V_6 = F_13 ( V_47 ) ;
V_6 &= ~ ( V_48 | V_49 ) ;
V_6 |= ( 0 << V_50 ) |
( 0 << V_51 ) ;
F_4 ( V_6 , V_47 ) ;
do {
V_6 = F_13 ( V_52 ) ;
} while ( V_6 & ( ( 1 << 7 ) | ( 1 << 3 ) ) );
V_6 = F_13 ( V_41 ) ;
V_6 &= ~ ( V_42 | V_43 ) ;
V_6 |= ( V_66 [ V_18 ] [ 10 ] << V_44 ) |
( V_66 [ V_18 ] [ 9 ] << V_45 ) ;
F_4 ( V_6 , V_41 ) ;
do {
V_6 = F_13 ( V_46 ) ;
} while ( V_6 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_6 = F_13 ( V_53 ) ;
V_6 &= ~ ( V_54 ) ;
V_6 |= ( 0x0 << V_55 ) ;
F_4 ( V_6 , V_53 ) ;
do {
V_6 = F_13 ( V_56 ) ;
} while ( V_6 & ( 0x1 << 18 ) );
if ( ! V_21 )
F_1 ( V_9 , 200000 ) ;
}
if ( V_21 ) {
V_6 = F_13 ( V_81 ) ;
V_6 &= ~ V_82 ;
V_6 |= ( V_66 [ V_18 ] [ 8 ] << V_83 ) ;
F_4 ( V_6 , V_81 ) ;
do {
V_6 = F_13 ( V_84 ) ;
} while ( V_6 & ( 1 << 15 ) );
if ( V_18 != V_40 ) {
F_1 ( V_7 , 166000 ) ;
F_1 ( V_9 , 200000 ) ;
} else {
F_1 ( V_7 , 83000 ) ;
F_1 ( V_9 , 100000 ) ;
}
}
if ( V_23 < V_22 ) {
F_12 ( V_37 ,
V_25 , V_38 ) ;
F_12 ( V_35 ,
V_24 , V_36 ) ;
}
F_2 ( V_85 L_4 , V_18 ) ;
exit:
F_14 ( & V_27 ) ;
return V_26 ;
}
static int F_15 ( struct V_16 * V_17 )
{
return 0 ;
}
static int F_16 ( struct V_16 * V_17 )
{
return 0 ;
}
static int F_17 ( void T_1 * V_86 )
{
unsigned long V_87 ;
V_87 = F_13 ( V_86 + 0x4 ) ;
V_87 = ( V_87 & ( 0xf << 8 ) ) ;
return V_87 >> 8 ;
}
static int T_2 F_18 ( struct V_16 * V_17 )
{
unsigned long V_88 ;
int V_26 ;
V_15 = F_19 ( NULL , L_5 ) ;
if ( F_20 ( V_15 ) )
return F_21 ( V_15 ) ;
V_89 = F_19 ( NULL , L_6 ) ;
if ( F_20 ( V_89 ) ) {
V_26 = F_21 ( V_89 ) ;
goto V_90;
}
V_91 = F_19 ( NULL , L_7 ) ;
if ( F_20 ( V_91 ) ) {
V_26 = F_21 ( V_91 ) ;
goto V_92;
}
if ( V_17 -> V_14 != 0 ) {
V_26 = - V_30 ;
goto V_92;
}
V_88 = F_17 ( V_8 ) ;
if ( ( V_88 != V_93 ) && ( V_88 != V_94 ) ) {
F_2 ( V_11 L_8 ) ;
V_26 = - V_30 ;
goto V_92;
}
V_12 [ 0 ] . V_13 = ( F_13 ( V_8 + 0x30 ) * 1000 ) ;
V_12 [ 0 ] . V_3 = F_6 ( V_89 ) ;
V_12 [ 1 ] . V_13 = ( F_13 ( V_10 + 0x30 ) * 1000 ) ;
V_12 [ 1 ] . V_3 = F_6 ( V_91 ) ;
return F_22 ( V_17 , V_31 , 40000 ) ;
V_92:
F_23 ( V_89 ) ;
V_90:
F_23 ( V_15 ) ;
return V_26 ;
}
static int F_24 ( struct V_95 * V_96 ,
unsigned long V_97 , void * V_98 )
{
int V_26 ;
switch ( V_97 ) {
case V_99 :
V_26 = F_25 ( F_26 ( 0 ) , V_100 , 0 ) ;
if ( V_26 < 0 )
return V_101 ;
V_28 = true ;
return V_102 ;
case V_103 :
case V_104 :
V_28 = false ;
F_25 ( F_26 ( 0 ) , V_100 , 0 ) ;
return V_102 ;
}
return V_105 ;
}
static int F_27 ( struct V_95 * V_96 ,
unsigned long V_97 , void * V_98 )
{
int V_26 ;
V_26 = F_25 ( F_26 ( 0 ) , V_100 , 0 ) ;
if ( V_26 < 0 )
return V_101 ;
V_28 = true ;
return V_105 ;
}
static int T_2 F_28 ( void )
{
V_35 = F_29 ( NULL , L_9 ) ;
if ( F_20 ( V_35 ) ) {
F_10 ( L_10 ) ;
return F_21 ( V_35 ) ;
}
V_37 = F_29 ( NULL , L_11 ) ;
if ( F_20 ( V_37 ) ) {
F_10 ( L_12 ) ;
F_30 ( V_35 ) ;
return F_21 ( V_37 ) ;
}
F_31 ( & V_106 ) ;
F_32 ( & V_107 ) ;
return F_33 ( & V_108 ) ;
}
