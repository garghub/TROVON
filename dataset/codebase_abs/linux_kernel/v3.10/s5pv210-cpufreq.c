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
static int F_5 ( struct V_14 * V_15 )
{
if ( V_15 -> V_16 )
return - V_17 ;
return F_6 ( V_15 , V_18 ) ;
}
static unsigned int F_7 ( unsigned int V_16 )
{
if ( V_16 )
return 0 ;
return F_8 ( V_19 ) / 1000 ;
}
static int F_9 ( struct V_14 * V_15 ,
unsigned int V_20 ,
unsigned int V_21 )
{
unsigned long V_6 ;
unsigned int V_22 , V_23 ;
unsigned int V_24 = 0 ;
unsigned int V_25 = 0 ;
int V_26 , V_27 ;
int V_28 = 0 ;
F_10 ( & V_29 ) ;
if ( V_21 & V_30 )
V_31 = false ;
if ( V_31 ) {
#ifdef F_11
F_12 ( L_2
L_3 , __FILE__ , __LINE__ , V_32 ) ;
#endif
V_28 = - V_17 ;
goto exit;
}
if ( V_21 & V_33 )
V_31 = true ;
V_21 &= ~ ( V_30 | V_33 ) ;
V_34 . V_35 = F_7 ( 0 ) ;
if ( F_13 ( V_15 , V_18 ,
V_20 , V_21 , & V_22 ) ) {
V_28 = - V_17 ;
goto exit;
}
V_34 . V_36 = V_18 [ V_22 ] . V_37 ;
if ( V_34 . V_36 == V_34 . V_35 )
goto exit;
if ( F_13 ( V_15 , V_18 ,
V_34 . V_35 , V_21 , & V_23 ) ) {
V_28 = - V_17 ;
goto exit;
}
V_26 = V_38 [ V_22 ] . V_26 ;
V_27 = V_38 [ V_22 ] . V_27 ;
if ( V_34 . V_36 > V_34 . V_35 ) {
V_28 = F_14 ( V_39 ,
V_26 , V_40 ) ;
if ( V_28 )
goto exit;
V_28 = F_14 ( V_41 ,
V_27 , V_42 ) ;
if ( V_28 )
goto exit;
}
F_15 ( V_15 , & V_34 , V_43 ) ;
if ( ( V_22 == V_44 ) || ( V_23 == V_44 ) )
V_24 = 1 ;
if ( ( V_22 == V_45 ) || ( V_23 == V_45 ) )
V_25 = 1 ;
if ( V_25 ) {
if ( V_24 )
F_1 ( V_9 , 83000 ) ;
else
F_1 ( V_9 , 100000 ) ;
F_1 ( V_7 , 83000 ) ;
}
if ( V_24 ) {
V_6 = F_16 ( V_46 ) ;
V_6 &= ~ ( V_47 | V_48 ) ;
V_6 |= ( 3 << V_49 ) |
( 3 << V_50 ) ;
F_4 ( V_6 , V_46 ) ;
do {
V_6 = F_16 ( V_51 ) ;
} while ( V_6 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_6 = F_16 ( V_52 ) ;
V_6 &= ~ ( V_53 | V_54 ) ;
V_6 |= ( 1 << V_55 ) |
( 1 << V_56 ) ;
F_4 ( V_6 , V_52 ) ;
do {
V_6 = F_16 ( V_57 ) ;
} while ( V_6 & ( ( 1 << 7 ) | ( 1 << 3 ) ) );
if ( ! V_25 )
F_1 ( V_9 , 133000 ) ;
V_6 = F_16 ( V_58 ) ;
V_6 &= ~ ( V_59 ) ;
V_6 |= ( 0x1 << V_60 ) ;
F_4 ( V_6 , V_58 ) ;
do {
V_6 = F_16 ( V_61 ) ;
} while ( V_6 & ( 0x1 << 18 ) );
}
V_6 = F_16 ( V_62 ) ;
V_6 &= ~ ( V_63 | V_64 |
V_65 | V_66 |
V_67 | V_68 |
V_69 | V_70 ) ;
V_6 |= ( ( V_71 [ V_22 ] [ 0 ] << V_72 ) |
( V_71 [ V_22 ] [ 1 ] << V_73 ) |
( V_71 [ V_22 ] [ 2 ] << V_74 ) |
( V_71 [ V_22 ] [ 3 ] << V_75 ) |
( V_71 [ V_22 ] [ 4 ] << V_76 ) |
( V_71 [ V_22 ] [ 5 ] << V_77 ) |
( V_71 [ V_22 ] [ 6 ] << V_78 ) |
( V_71 [ V_22 ] [ 7 ] << V_79 ) ) ;
F_4 ( V_6 , V_62 ) ;
do {
V_6 = F_16 ( V_51 ) ;
} while ( V_6 & 0xff );
V_6 = F_16 ( V_80 ) ;
V_6 &= ~ 0x3 ;
if ( V_22 >= V_81 )
V_6 |= 0x3 ;
else
V_6 |= 0x1 ;
F_4 ( V_6 , V_80 ) ;
if ( V_24 ) {
F_4 ( 0x2cf , V_82 ) ;
if ( V_22 == V_44 )
F_4 ( V_83 , V_84 ) ;
else
F_4 ( V_85 , V_84 ) ;
do {
V_6 = F_16 ( V_84 ) ;
} while ( ! ( V_6 & ( 0x1 << 29 ) ) );
V_6 = F_16 ( V_52 ) ;
V_6 &= ~ ( V_53 | V_54 ) ;
V_6 |= ( 0 << V_55 ) |
( 0 << V_56 ) ;
F_4 ( V_6 , V_52 ) ;
do {
V_6 = F_16 ( V_57 ) ;
} while ( V_6 & ( ( 1 << 7 ) | ( 1 << 3 ) ) );
V_6 = F_16 ( V_46 ) ;
V_6 &= ~ ( V_47 | V_48 ) ;
V_6 |= ( V_71 [ V_22 ] [ 10 ] << V_49 ) |
( V_71 [ V_22 ] [ 9 ] << V_50 ) ;
F_4 ( V_6 , V_46 ) ;
do {
V_6 = F_16 ( V_51 ) ;
} while ( V_6 & ( ( 1 << 16 ) | ( 1 << 17 ) ) );
V_6 = F_16 ( V_58 ) ;
V_6 &= ~ ( V_59 ) ;
V_6 |= ( 0x0 << V_60 ) ;
F_4 ( V_6 , V_58 ) ;
do {
V_6 = F_16 ( V_61 ) ;
} while ( V_6 & ( 0x1 << 18 ) );
if ( ! V_25 )
F_1 ( V_9 , 200000 ) ;
}
if ( V_25 ) {
V_6 = F_16 ( V_86 ) ;
V_6 &= ~ V_87 ;
V_6 |= ( V_71 [ V_22 ] [ 8 ] << V_88 ) ;
F_4 ( V_6 , V_86 ) ;
do {
V_6 = F_16 ( V_89 ) ;
} while ( V_6 & ( 1 << 15 ) );
if ( V_22 != V_45 ) {
F_1 ( V_7 , 166000 ) ;
F_1 ( V_9 , 200000 ) ;
} else {
F_1 ( V_7 , 83000 ) ;
F_1 ( V_9 , 100000 ) ;
}
}
F_15 ( V_15 , & V_34 , V_90 ) ;
if ( V_34 . V_36 < V_34 . V_35 ) {
F_14 ( V_41 ,
V_27 , V_42 ) ;
F_14 ( V_39 ,
V_26 , V_40 ) ;
}
F_2 ( V_91 L_4 , V_22 ) ;
exit:
F_17 ( & V_29 ) ;
return V_28 ;
}
static int F_18 ( struct V_14 * V_15 )
{
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
return 0 ;
}
static int F_20 ( void T_1 * V_92 )
{
unsigned long V_93 ;
V_93 = F_16 ( V_92 + 0x4 ) ;
V_93 = ( V_93 & ( 0xf << 8 ) ) ;
return V_93 >> 8 ;
}
static int T_2 F_21 ( struct V_14 * V_15 )
{
unsigned long V_94 ;
int V_28 ;
V_19 = F_22 ( NULL , L_5 ) ;
if ( F_23 ( V_19 ) )
return F_24 ( V_19 ) ;
V_95 = F_22 ( NULL , L_6 ) ;
if ( F_23 ( V_95 ) ) {
V_28 = F_24 ( V_95 ) ;
goto V_96;
}
V_97 = F_22 ( NULL , L_7 ) ;
if ( F_23 ( V_97 ) ) {
V_28 = F_24 ( V_97 ) ;
goto V_98;
}
if ( V_15 -> V_16 != 0 ) {
V_28 = - V_17 ;
goto V_98;
}
V_94 = F_20 ( V_8 ) ;
if ( ( V_94 != V_99 ) && ( V_94 != V_100 ) ) {
F_2 ( V_11 L_8 ) ;
V_28 = - V_17 ;
goto V_98;
}
V_12 [ 0 ] . V_13 = ( F_16 ( V_8 + 0x30 ) * 1000 ) ;
V_12 [ 0 ] . V_3 = F_8 ( V_95 ) ;
V_12 [ 1 ] . V_13 = ( F_16 ( V_10 + 0x30 ) * 1000 ) ;
V_12 [ 1 ] . V_3 = F_8 ( V_97 ) ;
V_15 -> V_101 = V_15 -> V_102 = V_15 -> V_103 = F_7 ( 0 ) ;
F_25 ( V_18 , V_15 -> V_16 ) ;
V_15 -> V_104 . V_105 = 40000 ;
return F_26 ( V_15 , V_18 ) ;
V_98:
F_27 ( V_95 ) ;
V_96:
F_27 ( V_19 ) ;
return V_28 ;
}
static int F_28 ( struct V_106 * V_107 ,
unsigned long V_108 , void * V_109 )
{
int V_28 ;
switch ( V_108 ) {
case V_110 :
V_28 = F_29 ( F_30 ( 0 ) , V_111 ,
V_33 ) ;
if ( V_28 < 0 )
return V_112 ;
return V_113 ;
case V_114 :
case V_115 :
F_29 ( F_30 ( 0 ) , V_111 ,
V_30 ) ;
return V_113 ;
}
return V_116 ;
}
static int F_31 ( struct V_106 * V_107 ,
unsigned long V_108 , void * V_109 )
{
int V_28 ;
V_28 = F_29 ( F_30 ( 0 ) , V_111 ,
V_33 ) ;
if ( V_28 < 0 )
return V_112 ;
return V_116 ;
}
static int T_2 F_32 ( void )
{
V_39 = F_33 ( NULL , L_9 ) ;
if ( F_23 ( V_39 ) ) {
F_12 ( L_10 ) ;
return F_24 ( V_39 ) ;
}
V_41 = F_33 ( NULL , L_11 ) ;
if ( F_23 ( V_41 ) ) {
F_12 ( L_12 ) ;
F_34 ( V_39 ) ;
return F_24 ( V_41 ) ;
}
F_35 ( & V_117 ) ;
F_36 ( & V_118 ) ;
return F_37 ( & V_119 ) ;
}
