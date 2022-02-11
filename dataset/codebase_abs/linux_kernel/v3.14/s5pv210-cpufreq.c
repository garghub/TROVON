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
static int F_5 ( struct V_14 * V_15 , unsigned int V_16 )
{
unsigned long V_6 ;
unsigned int V_17 ;
unsigned int V_18 = 0 ;
unsigned int V_19 = 0 ;
unsigned int V_20 , V_21 ;
int V_22 , V_23 ;
int V_24 = 0 ;
F_6 ( & V_25 ) ;
if ( V_26 ) {
#ifdef F_7
F_8 ( L_2
L_3 , __FILE__ , __LINE__ , V_27 ) ;
#endif
V_24 = - V_28 ;
goto exit;
}
V_20 = V_15 -> V_29 ;
V_21 = V_30 [ V_16 ] . V_31 ;
if ( F_9 ( V_15 , V_30 ,
V_20 , V_32 ,
& V_17 ) ) {
V_24 = - V_28 ;
goto exit;
}
V_22 = V_33 [ V_16 ] . V_22 ;
V_23 = V_33 [ V_16 ] . V_23 ;
if ( V_21 > V_20 ) {
V_24 = F_10 ( V_34 ,
V_22 , V_35 ) ;
if ( V_24 )
goto exit;
V_24 = F_10 ( V_36 ,
V_23 , V_37 ) ;
if ( V_24 )
goto exit;
}
if ( ( V_16 == V_38 ) || ( V_17 == V_38 ) )
V_18 = 1 ;
if ( ( V_16 == V_39 ) || ( V_17 == V_39 ) )
V_19 = 1 ;
if ( V_19 ) {
if ( V_18 )
F_1 ( V_9 , 83000 ) ;
else
F_1 ( V_9 , 100000 ) ;
F_1 ( V_7 , 83000 ) ;
}
if ( V_18 ) {
V_6 = F_11 ( V_40 ) ;
V_6 &= ~ ( V_41 | V_42 ) ;
V_6 |= ( 3 << V_43 ) |
( 3 << V_44 ) ;
F_4 ( V_6 , V_40 ) ;
do {
V_6 = F_11 ( V_45 ) ;
} while ( V_6 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_6 = F_11 ( V_46 ) ;
V_6 &= ~ ( V_47 | V_48 ) ;
V_6 |= ( 1 << V_49 ) |
( 1 << V_50 ) ;
F_4 ( V_6 , V_46 ) ;
do {
V_6 = F_11 ( V_51 ) ;
} while ( V_6 & ( ( 1 << 7 ) | ( 1 << 3 ) ) );
if ( ! V_19 )
F_1 ( V_9 , 133000 ) ;
V_6 = F_11 ( V_52 ) ;
V_6 &= ~ ( V_53 ) ;
V_6 |= ( 0x1 << V_54 ) ;
F_4 ( V_6 , V_52 ) ;
do {
V_6 = F_11 ( V_55 ) ;
} while ( V_6 & ( 0x1 << 18 ) );
}
V_6 = F_11 ( V_56 ) ;
V_6 &= ~ ( V_57 | V_58 |
V_59 | V_60 |
V_61 | V_62 |
V_63 | V_64 ) ;
V_6 |= ( ( V_65 [ V_16 ] [ 0 ] << V_66 ) |
( V_65 [ V_16 ] [ 1 ] << V_67 ) |
( V_65 [ V_16 ] [ 2 ] << V_68 ) |
( V_65 [ V_16 ] [ 3 ] << V_69 ) |
( V_65 [ V_16 ] [ 4 ] << V_70 ) |
( V_65 [ V_16 ] [ 5 ] << V_71 ) |
( V_65 [ V_16 ] [ 6 ] << V_72 ) |
( V_65 [ V_16 ] [ 7 ] << V_73 ) ) ;
F_4 ( V_6 , V_56 ) ;
do {
V_6 = F_11 ( V_45 ) ;
} while ( V_6 & 0xff );
V_6 = F_11 ( V_74 ) ;
V_6 &= ~ 0x3 ;
if ( V_16 >= V_75 )
V_6 |= 0x3 ;
else
V_6 |= 0x1 ;
F_4 ( V_6 , V_74 ) ;
if ( V_18 ) {
F_4 ( 0x2cf , V_76 ) ;
if ( V_16 == V_38 )
F_4 ( V_77 , V_78 ) ;
else
F_4 ( V_79 , V_78 ) ;
do {
V_6 = F_11 ( V_78 ) ;
} while ( ! ( V_6 & ( 0x1 << 29 ) ) );
V_6 = F_11 ( V_46 ) ;
V_6 &= ~ ( V_47 | V_48 ) ;
V_6 |= ( 0 << V_49 ) |
( 0 << V_50 ) ;
F_4 ( V_6 , V_46 ) ;
do {
V_6 = F_11 ( V_51 ) ;
} while ( V_6 & ( ( 1 << 7 ) | ( 1 << 3 ) ) );
V_6 = F_11 ( V_40 ) ;
V_6 &= ~ ( V_41 | V_42 ) ;
V_6 |= ( V_65 [ V_16 ] [ 10 ] << V_43 ) |
( V_65 [ V_16 ] [ 9 ] << V_44 ) ;
F_4 ( V_6 , V_40 ) ;
do {
V_6 = F_11 ( V_45 ) ;
} while ( V_6 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_6 = F_11 ( V_52 ) ;
V_6 &= ~ ( V_53 ) ;
V_6 |= ( 0x0 << V_54 ) ;
F_4 ( V_6 , V_52 ) ;
do {
V_6 = F_11 ( V_55 ) ;
} while ( V_6 & ( 0x1 << 18 ) );
if ( ! V_19 )
F_1 ( V_9 , 200000 ) ;
}
if ( V_19 ) {
V_6 = F_11 ( V_80 ) ;
V_6 &= ~ V_81 ;
V_6 |= ( V_65 [ V_16 ] [ 8 ] << V_82 ) ;
F_4 ( V_6 , V_80 ) ;
do {
V_6 = F_11 ( V_83 ) ;
} while ( V_6 & ( 1 << 15 ) );
if ( V_16 != V_39 ) {
F_1 ( V_7 , 166000 ) ;
F_1 ( V_9 , 200000 ) ;
} else {
F_1 ( V_7 , 83000 ) ;
F_1 ( V_9 , 100000 ) ;
}
}
if ( V_21 < V_20 ) {
F_10 ( V_36 ,
V_23 , V_37 ) ;
F_10 ( V_34 ,
V_22 , V_35 ) ;
}
F_2 ( V_84 L_4 , V_16 ) ;
exit:
F_12 ( & V_25 ) ;
return V_24 ;
}
static int F_13 ( struct V_14 * V_15 )
{
return 0 ;
}
static int F_14 ( struct V_14 * V_15 )
{
return 0 ;
}
static int F_15 ( void T_1 * V_85 )
{
unsigned long V_86 ;
V_86 = F_11 ( V_85 + 0x4 ) ;
V_86 = ( V_86 & ( 0xf << 8 ) ) ;
return V_86 >> 8 ;
}
static int T_2 F_16 ( struct V_14 * V_15 )
{
unsigned long V_87 ;
int V_24 ;
V_15 -> V_88 = F_17 ( NULL , L_5 ) ;
if ( F_18 ( V_15 -> V_88 ) )
return F_19 ( V_15 -> V_88 ) ;
V_89 = F_17 ( NULL , L_6 ) ;
if ( F_18 ( V_89 ) ) {
V_24 = F_19 ( V_89 ) ;
goto V_90;
}
V_91 = F_17 ( NULL , L_7 ) ;
if ( F_18 ( V_91 ) ) {
V_24 = F_19 ( V_91 ) ;
goto V_92;
}
if ( V_15 -> V_93 != 0 ) {
V_24 = - V_28 ;
goto V_92;
}
V_87 = F_15 ( V_8 ) ;
if ( ( V_87 != V_94 ) && ( V_87 != V_95 ) ) {
F_2 ( V_11 L_8 ) ;
V_24 = - V_28 ;
goto V_92;
}
V_12 [ 0 ] . V_13 = ( F_11 ( V_8 + 0x30 ) * 1000 ) ;
V_12 [ 0 ] . V_3 = F_20 ( V_89 ) ;
V_12 [ 1 ] . V_13 = ( F_11 ( V_10 + 0x30 ) * 1000 ) ;
V_12 [ 1 ] . V_3 = F_20 ( V_91 ) ;
return F_21 ( V_15 , V_30 , 40000 ) ;
V_92:
F_22 ( V_89 ) ;
V_90:
F_22 ( V_15 -> V_88 ) ;
return V_24 ;
}
static int F_23 ( struct V_96 * V_97 ,
unsigned long V_98 , void * V_99 )
{
int V_24 ;
switch ( V_98 ) {
case V_100 :
V_24 = F_24 ( F_25 ( 0 ) , V_101 , 0 ) ;
if ( V_24 < 0 )
return V_102 ;
V_26 = true ;
return V_103 ;
case V_104 :
case V_105 :
V_26 = false ;
F_24 ( F_25 ( 0 ) , V_101 , 0 ) ;
return V_103 ;
}
return V_106 ;
}
static int F_26 ( struct V_96 * V_97 ,
unsigned long V_98 , void * V_99 )
{
int V_24 ;
V_24 = F_24 ( F_25 ( 0 ) , V_101 , 0 ) ;
if ( V_24 < 0 )
return V_102 ;
V_26 = true ;
return V_106 ;
}
static int T_2 F_27 ( void )
{
V_34 = F_28 ( NULL , L_9 ) ;
if ( F_18 ( V_34 ) ) {
F_8 ( L_10 ) ;
return F_19 ( V_34 ) ;
}
V_36 = F_28 ( NULL , L_11 ) ;
if ( F_18 ( V_36 ) ) {
F_8 ( L_12 ) ;
F_29 ( V_34 ) ;
return F_19 ( V_36 ) ;
}
F_30 ( & V_107 ) ;
F_31 ( & V_108 ) ;
return F_32 ( & V_109 ) ;
}
