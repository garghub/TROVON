static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_2 () ;
if ( V_2 -> V_5 -> V_6 ) {
return 0 ;
}
F_3 ( 1 ) ;
}
F_4 ( V_2 -> V_7 -> V_8 , L_1 ) ;
return - V_9 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 )
{
int V_3 ;
F_6 () ;
for ( V_3 = 0 ; V_3 < V_11 ; V_3 ++ ) {
if ( ! ( F_7 ( V_2 , V_12 ) &
V_13 ) ) {
F_8 ( V_2 , V_12 , V_10 ) ;
return 0 ;
}
F_3 ( 1 ) ;
}
F_9 ( ( V_14 L_2 ) ) ;
return - V_9 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_15 )
{
T_1 V_16 , V_3 ;
for ( V_3 = 0 ; V_3 < 10000000 ; V_3 ++ ) {
V_16 = F_7 ( V_2 , V_17 ) ;
if ( ( V_16 & V_18 ) != 0 ) {
F_8 ( V_2 , V_19 , V_15 ) ;
F_6 () ;
return 0 ;
}
F_3 ( 1 ) ;
F_11 () ;
}
V_2 -> V_20 = TRUE ;
F_9 ( ( V_14 L_3 ) ) ;
return - V_21 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_15 )
{
T_1 V_16 , V_3 ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
V_16 = F_7 ( V_2 , V_17 ) ;
if ( ( V_16 & V_23 ) != 0 ) {
* V_15 = F_7 ( V_2 , V_19 ) ;
return 0 ;
}
F_3 ( 1 ) ;
F_11 () ;
}
V_2 -> V_20 = TRUE ;
F_13 ( ( V_14 L_4 ) ) ;
return - V_21 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_24 [ 6 ] ;
for ( V_3 = 0 ; V_3 < 5 ; V_3 ++ ) {
if ( F_12 ( V_2 , & V_24 [ V_3 ] ) ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_5 ) ;
return - V_21 ;
}
}
F_13 ( ( L_6 ,
V_24 [ 0 ] , V_24 [ 1 ] , V_24 [ 2 ] , V_24 [ 3 ] , V_24 [ 4 ] ) ) ;
return 0 ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
V_2 -> V_25 = TRUE ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_26 , short V_27 )
{
const struct V_28 * V_29 ;
int V_30 ;
T_1 V_3 , V_31 ;
T_2 * V_32 ;
V_30 = F_17 ( & V_29 , V_2 , V_27 ) ;
if ( V_30 < 0 ) {
F_18 ( V_2 -> V_7 -> V_8 , L_7 ) ;
return V_30 ;
}
V_32 = ( T_2 * ) V_29 -> V_15 ;
V_31 = V_29 -> V_31 ;
if ( F_10 ( V_2 , V_26 ) < 0 )
goto V_33;
if ( F_10 ( V_2 , V_31 ) < 0 )
goto V_33;
for ( V_3 = 0 ; V_3 < V_31 ; V_3 ++ ) {
if ( F_10 ( V_2 , V_32 [ V_3 ] ) < 0 )
goto V_33;
}
F_13 ( ( L_8 ) ) ;
F_19 ( V_29 ) ;
return 0 ;
V_33:
F_13 ( ( L_9 ) ) ;
F_19 ( V_29 ) ;
return - V_21 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_34 ;
int V_35 , V_36 , V_3 ;
T_3 * V_32 ;
T_1 V_16 ;
const struct V_28 * V_29 ;
if ( V_2 -> V_37 != V_38 )
return 0 ;
V_16 = F_7 ( V_2 , V_17 ) ;
if ( V_16 & V_39 ) {
F_13 ( ( L_10 ,
V_16 ) ) ;
return 0 ;
}
V_3 = F_17 ( & V_29 , V_2 , V_40 ) ;
if ( V_3 < 0 ) {
F_18 ( V_2 -> V_7 -> V_8 , L_7 ) ;
return V_3 ;
}
F_8 ( V_2 , V_41 ,
F_7 ( V_2 , V_41 ) | 0x900 ) ;
V_32 = ( T_3 * ) V_29 -> V_15 ;
V_35 = V_32 [ 0 ] ;
V_35 += 3 ;
V_36 = V_32 [ V_35 ++ ] ;
V_34 = ( ( T_1 ) V_32 [ V_35 ] << 16 ) + V_32 [ V_35 + 1 ] ;
V_35 += 2 ;
if ( F_10 ( V_2 , V_36 ) ) {
F_13 ( ( L_11 ) ) ;
goto V_42;
}
if ( F_10 ( V_2 , V_34 ) ) {
F_13 ( ( L_12 ) ) ;
goto V_42;
}
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ ) {
T_1 V_15 ;
V_15 = ( ( T_1 ) V_32 [ V_35 ] << 16 ) + V_32 [ V_35 + 1 ] ;
if ( F_10 ( V_2 , V_15 ) ) {
F_13 ( ( L_13 ) ) ;
goto V_42;
}
V_35 += 2 ;
}
for ( V_3 = 0 ; V_3 < 200 ; V_3 ++ ) {
F_3 ( 50 ) ;
V_16 = F_7 ( V_2 , V_17 ) ;
if ( V_16 & V_39 )
break;
}
if ( V_3 == 200 ) {
F_13 ( ( L_14 ) ) ;
goto V_42;
}
F_13 ( ( L_15 ) ) ;
F_19 ( V_29 ) ;
return 0 ;
V_42:
F_19 ( V_29 ) ;
return - V_21 ;
}
static int F_21 ( struct V_1 * V_2 , T_3 * V_32 )
{
T_1 V_34 , V_15 ;
int V_35 , V_36 , V_3 ;
if ( V_2 -> V_43 == V_32 ) {
F_13 ( ( L_16 ) ) ;
return 0 ;
}
V_2 -> V_20 = TRUE ;
V_2 -> V_43 = NULL ;
V_2 -> V_25 = FALSE ;
F_13 ( ( L_17 ) ) ;
#ifdef F_22
if ( ( V_3 = F_20 ( V_2 ) ) < 0 )
return V_3 ;
#endif
if ( F_5 ( V_2 , V_44 ) < 0 ) {
F_13 ( ( L_18 ) ) ;
return - V_21 ;
}
F_3 ( 10 ) ;
for ( V_3 = 0 ; V_3 < 1000 ; V_3 ++ ) {
if ( F_7 ( V_2 , V_17 ) &
V_45 )
break;
F_3 ( 10 ) ;
}
if ( V_3 == 1000 ) {
F_13 ( ( L_19 ) ) ;
return - V_21 ;
}
F_8 ( V_2 , V_41 ,
F_7 ( V_2 , V_41 ) | 0x900 ) ;
V_35 = V_32 [ 0 ] ;
for (; ; ) {
int V_46 , V_47 ;
V_35 ++ ;
V_46 = V_32 [ V_35 ] ;
if ( V_46 == 4 )
break;
V_35 ++ ;
V_47 = V_32 [ V_35 ++ ] ;
V_36 = V_32 [ V_35 ++ ] ;
if ( V_36 == 0 )
break;
V_34 = ( ( T_1 ) V_32 [ V_35 ] << 16 ) + V_32 [ V_35 + 1 ] ;
V_35 += 2 ;
if ( F_10 ( V_2 , V_36 ) < 0 ) {
F_13 ( ( L_20 ) ) ;
return - V_21 ;
}
if ( F_10 ( V_2 , V_34 ) < 0 ) {
F_13 ( ( L_21 ) ) ;
return - V_21 ;
}
if ( F_10 ( V_2 , V_47 ) < 0 ) {
F_13 ( ( L_22 ) ) ;
return - V_21 ;
}
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ , V_35 += 2 ) {
V_15 = ( ( T_1 ) V_32 [ V_35 ] << 16 ) + V_32 [ V_35 + 1 ] ;
if ( F_10 ( V_2 , V_15 ) < 0 ) {
F_13 ( ( L_23 ) ) ;
return - V_21 ;
}
}
}
if ( F_10 ( V_2 , 0 ) < 0 ) {
F_13 ( ( L_24 ) ) ;
return - V_21 ;
}
F_3 ( 10 ) ;
for ( V_3 = 0 ; V_3 < 5000 ; V_3 ++ ) {
if ( F_7 ( V_2 , V_17 ) &
V_48 ) {
F_8 ( V_2 , V_41 ,
F_7 ( V_2 , V_41 ) & ~ 0x1b00 ) ;
if ( F_10 ( V_2 , V_49 ) < 0 ) {
F_13 ( ( L_25 ) ) ;
return - V_21 ;
}
if ( F_10 ( V_2 , V_2 -> V_50 ) < 0 ) {
F_13 ( ( L_26 ) ) ;
return - V_21 ;
}
if ( F_14 ( V_2 ) < 0 ) {
F_13 ( ( L_27 ) ) ;
return - V_21 ;
}
V_2 -> V_43 = V_32 ;
V_2 -> V_20 = FALSE ;
F_13 ( ( L_28 ) ) ;
return 0 ;
}
F_3 ( 100 ) ;
}
F_13 ( ( L_29 ) ) ;
return - V_21 ;
}
static int F_23 ( struct V_1 * V_2 )
{
const struct V_28 * V_29 ;
int V_51 , V_30 ;
if ( F_24 ( ! V_2 -> V_5 ) )
return - V_52 ;
if ( V_2 -> V_43 ) {
if ( ( V_51 = F_15 ( V_2 ) ) >= 0 )
return V_51 ;
V_2 -> V_43 = NULL ;
}
V_30 = F_17 ( & V_29 , V_2 , V_2 -> V_53 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_21 ( V_2 , ( T_3 * ) V_29 -> V_15 ) ;
F_19 ( V_29 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ( V_51 = F_25 ( V_2 ) ) < 0 )
return V_51 ;
return V_51 ;
}
static int F_26 ( struct V_1 * V_2 , T_3 V_35 , char V_54 )
{
if ( F_24 ( V_35 >= F_27 ( V_2 ) + F_28 ( V_2 ) ) )
return - V_55 ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_56 [ V_35 ] = V_54 ;
if ( V_54 )
V_2 -> V_5 -> V_57 |= F_29 ( 1 << V_35 ) ;
else
V_2 -> V_5 -> V_57 &= ~ F_29 ( 1 << V_35 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , T_3 V_58 , T_4 V_59 )
{
if ( F_24 ( V_58 >= F_27 ( V_2 ) ) )
return - V_55 ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_60 [ V_58 ] = V_59 ;
V_2 -> V_5 -> V_61 [ V_58 ] = V_59 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , T_3 V_62 , T_3 V_63 ,
T_4 V_59 )
{
if ( F_24 ( V_62 >= F_27 ( V_2 ) ||
V_63 >= F_28 ( V_2 ) ) )
return - V_55 ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_64 [ V_62 ] [ V_63 ] = V_59 ;
V_2 -> V_5 -> V_65 [ F_32 ( V_2 , V_62 , V_63 ) ] = V_59 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return - V_21 ;
F_34 ( V_2 ) ;
return F_5 ( V_2 , V_66 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return - V_21 ;
F_34 ( V_2 ) ;
return F_5 ( V_2 , V_67 ) ;
}
static void F_36 ( struct V_1 * V_2 , char V_68 )
{
if ( V_68 && ! V_2 -> V_69 ) {
F_5 ( V_2 , V_70 ) ;
V_2 -> V_69 = 1 ;
} else if ( ! V_68 && V_2 -> V_69 ) {
F_5 ( V_2 , V_71 ) ;
V_2 -> V_69 = 0 ;
memset ( ( T_4 * ) V_2 -> V_5 -> V_72 , V_73 ,
V_74 ) ;
memset ( ( T_4 * ) V_2 -> V_5 -> V_75 , V_73 ,
V_74 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , long * V_76 )
{
int V_3 , V_77 , V_78 ;
V_77 = 0 ;
V_78 = 0 ;
for ( V_3 = 0 ; V_3 < F_27 ( V_2 ) ; V_3 ++ , V_77 ++ ) {
V_76 [ V_78 ++ ] = V_2 -> V_5 -> V_72 [ V_77 ] ;
V_76 [ V_78 ++ ] = V_2 -> V_5 -> V_75 [ V_77 ] ;
}
for (; V_78 < 32 ; V_78 ++ )
V_76 [ V_78 ] = 0 ;
#ifdef F_38
V_77 = V_79 ;
#endif
for ( V_3 = 0 ; V_3 < F_28 ( V_2 ) ; V_3 ++ , V_77 ++ ) {
V_76 [ V_78 ++ ] = V_2 -> V_5 -> V_72 [ V_77 ] ;
V_76 [ V_78 ++ ] = V_2 -> V_5 -> V_75 [ V_77 ] ;
}
for (; V_78 < 64 ; V_78 ++ )
V_76 [ V_78 ] = 0 ;
#ifdef F_39
for ( V_3 = 0 ; V_3 < F_40 ( V_2 ) ; V_3 ++ , V_77 ++ ) {
V_76 [ V_78 ++ ] = V_2 -> V_5 -> V_72 [ V_77 ] ;
V_76 [ V_78 ++ ] = V_2 -> V_5 -> V_75 [ V_77 ] ;
}
#endif
for (; V_78 < 96 ; V_78 ++ )
V_76 [ V_78 ] = 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_3 , V_80 , V_30 ;
F_13 ( ( L_30 ) ) ;
if ( ( V_30 = F_15 ( V_2 ) ) < 0 )
return V_30 ;
V_2 -> V_5 -> V_81 = V_82 ;
V_2 -> V_5 -> V_83 = V_84 ;
V_2 -> V_5 -> V_6 = 0xffffffff ;
for ( V_3 = 0 ; V_3 < F_27 ( V_2 ) ; V_3 ++ ) {
V_30 = F_30 ( V_2 , V_3 , V_2 -> V_60 [ V_3 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
#ifdef F_39
for ( V_3 = 0 ; V_3 < F_40 ( V_2 ) ; V_3 ++ )
for ( V_80 = 0 ; V_80 < F_27 ( V_2 ) ; V_80 ++ ) {
V_30 = F_42 ( V_2 , V_80 , V_3 ,
V_2 -> V_85 [ V_80 ] [ V_3 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( F_43 ( V_2 ) < 0 )
return - V_21 ;
#endif
#ifdef F_44
for ( V_80 = 0 ; V_80 < F_27 ( V_2 ) ; V_80 ++ )
for ( V_3 = 0 ; V_3 < F_28 ( V_2 ) ; V_3 ++ ) {
V_30 = F_31 ( V_2 , V_80 , V_3 ,
V_2 -> V_64 [ V_80 ] [ V_3 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
#endif
#ifdef F_45
for ( V_3 = 0 ; V_3 < F_28 ( V_2 ) ; V_3 ++ ) {
V_30 = F_46 ( V_2 , V_3 , V_2 -> V_86 [ V_3 ] ) ;
if ( V_30 < 0 )
return V_30 ;
}
#endif
V_30 = F_33 ( V_2 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_35 ( V_2 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_47 ( V_2 , V_2 -> V_87 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_2 -> V_69 ) {
V_30 = F_5 ( V_2 , V_70 ) ;
if ( V_30 < 0 )
return V_30 ;
}
#ifdef F_48
if ( F_49 ( V_2 , V_2 -> V_88 ) < 0 )
return - V_21 ;
#endif
#ifdef F_50
if ( F_51 ( V_2 , V_2 -> V_89 ) < 0 )
return - V_21 ;
#endif
#ifdef F_52
if ( F_53 ( V_2 , V_2 -> V_90 ) < 0 )
return - V_21 ;
#endif
#ifdef F_54
if ( F_55 ( V_2 , V_2 -> V_91 ) < 0 )
return - V_21 ;
#endif
#ifdef F_56
if ( F_57 ( V_2 , V_2 -> V_92 ) < 0 )
return - V_21 ;
#endif
if ( F_1 ( V_2 ) < 0 )
return - V_21 ;
F_34 ( V_2 ) ;
if ( F_5 ( V_2 , V_93 ) < 0 )
return - V_21 ;
F_13 ( ( L_31 ) ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 , T_3 V_94 ,
const struct V_95 * V_96 )
{
T_3 V_97 ;
V_97 = V_98 ;
if ( V_96 -> V_99 > 2 ) {
switch ( V_96 -> V_100 ) {
case 16 :
V_97 = V_101 ;
break;
case 24 :
V_97 = V_102 ;
break;
case 32 :
V_97 = V_103 ;
break;
}
V_97 |= V_96 -> V_99 ;
} else if ( V_96 -> V_104 ) {
switch ( V_96 -> V_99 ) {
case 1 :
V_97 = V_105 ;
break;
#ifdef F_59
case 2 :
V_97 = V_106 ;
break;
#endif
}
} else if ( V_96 -> V_99 == 1 &&
V_96 -> V_100 == 32 && ! V_96 -> V_107 ) {
V_97 = V_108 ;
} else {
switch ( V_96 -> V_100 ) {
case 8 :
if ( V_96 -> V_99 == 2 )
V_97 = V_109 ;
else
V_97 = V_110 ;
break;
default:
case 16 :
if ( V_96 -> V_99 == 2 )
V_97 = V_98 ;
else
V_97 = V_111 ;
break;
case 24 :
if ( V_96 -> V_99 == 2 )
V_97 = V_112 ;
else
V_97 = V_113 ;
break;
case 32 :
if ( V_96 -> V_99 == 2 )
V_97 = V_114 ;
else
V_97 = V_115 ;
break;
}
}
F_9 ( ( L_32 , V_94 , V_97 ) ) ;
V_2 -> V_5 -> V_116 [ V_94 ] = F_60 ( V_97 ) ;
}
static int F_61 ( struct V_1 * V_2 , T_1 V_117 ,
T_1 V_118 )
{
F_9 ( ( L_33 , V_117 ) ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_5 -> V_119 |= F_29 ( V_117 ) ;
if ( V_2 -> V_5 -> V_119 ) {
F_34 ( V_2 ) ;
F_5 ( V_2 , V_120 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_121 |= V_117 ;
V_2 -> V_5 -> V_119 = 0 ;
return 0 ;
}
F_9 ( ( L_34 ) ) ;
return - V_55 ;
}
static int F_62 ( struct V_1 * V_2 , T_1 V_117 )
{
F_9 ( ( L_35 , V_117 ) ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_5 -> V_122 |= F_29 ( V_117 ) ;
V_2 -> V_5 -> V_123 = 0 ;
if ( V_2 -> V_5 -> V_122 ) {
F_34 ( V_2 ) ;
F_5 ( V_2 , V_124 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_121 &= ~ V_117 ;
V_2 -> V_5 -> V_122 = 0 ;
V_2 -> V_5 -> V_123 = 0 ;
return 0 ;
}
F_9 ( ( L_36 ) ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , T_1 V_117 )
{
F_9 ( ( L_37 , V_117 ) ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_5 -> V_122 |= F_29 ( V_117 ) ;
V_2 -> V_5 -> V_123 |= F_29 ( V_117 ) ;
if ( V_2 -> V_5 -> V_123 ) {
F_34 ( V_2 ) ;
F_5 ( V_2 , V_124 ) ;
if ( F_1 ( V_2 ) )
return - V_21 ;
V_2 -> V_121 &= ~ V_117 ;
V_2 -> V_5 -> V_122 = 0 ;
V_2 -> V_5 -> V_123 = 0 ;
return 0 ;
}
F_9 ( ( L_38 ) ) ;
return 0 ;
}
static inline int F_64 ( struct V_1 * V_2 , T_3 V_94 )
{
return ( V_2 -> V_125 & ( 1 << V_94 ) ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
F_9 ( ( L_39 , V_2 -> V_125 ) ) ;
F_63 ( V_2 , V_2 -> V_121 ) ;
F_36 ( V_2 , FALSE ) ;
#ifdef F_66
F_67 ( V_2 , FALSE ) ;
#endif
if ( V_2 -> V_43 ) {
V_2 -> V_43 = NULL ;
return F_5 ( V_2 , V_126 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
if ( F_69 ( struct V_5 , V_127 ) != 0xbe0 ) {
F_13 ( ( L_40 ) ) ;
return - V_52 ;
}
V_2 -> V_128 = V_129 ;
V_2 -> V_20 = TRUE ;
V_2 -> V_43 = NULL ;
V_2 -> V_25 = FALSE ;
memset ( V_2 -> V_5 , 0 , sizeof( struct V_5 ) ) ;
V_2 -> V_5 -> V_130 =
F_29 ( sizeof( struct V_5 ) ) ;
V_2 -> V_5 -> V_6 = 0xffffffff ;
V_2 -> V_5 -> V_131 =
F_29 ( V_132 ) ;
V_2 -> V_5 -> V_87 = F_29 ( 44100 ) ;
memset ( V_2 -> V_5 -> V_65 , V_73 , V_133 ) ;
memset ( V_2 -> V_5 -> V_134 , V_73 , V_135 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
F_13 ( ( L_41 ) ) ;
memset ( V_2 -> V_60 , V_73 , sizeof( V_2 -> V_60 ) ) ;
memset ( V_2 -> V_86 , V_73 , sizeof( V_2 -> V_86 ) ) ;
memset ( V_2 -> V_64 , V_73 , sizeof( V_2 -> V_64 ) ) ;
memset ( V_2 -> V_85 , V_73 , sizeof( V_2 -> V_85 ) ) ;
V_2 -> V_91 = V_136 ;
V_2 -> V_92 = V_137 ;
V_2 -> V_87 = 44100 ;
return F_41 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_138 ;
if ( F_7 ( V_2 , V_17 ) & V_139 ) {
V_138 = 0 ;
#ifdef F_66
if ( V_2 -> V_5 -> V_140 [ 0 ] )
V_138 = F_72 ( V_2 ) ;
#endif
V_2 -> V_5 -> V_140 [ 0 ] = 0 ;
F_5 ( V_2 , V_141 ) ;
return V_138 ;
}
return - 1 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_142 * V_143 ,
int V_94 , int V_99 )
{
int V_3 ;
T_1 V_117 ;
char V_144 ;
F_9 ( ( L_42 , V_94 , V_99 ) ) ;
if ( V_2 -> V_20 )
return - V_21 ;
V_144 = 1 ;
for ( V_117 = V_3 = 0 ; V_3 < V_99 ; V_3 ++ )
V_117 |= 1 << ( V_94 + V_3 ) ;
if ( V_2 -> V_125 & V_117 ) {
F_9 ( ( L_43 ) ) ;
return - V_145 ;
}
V_2 -> V_5 -> V_146 [ V_94 ] = 0 ;
V_2 -> V_125 |= V_117 ;
if ( V_144 )
V_2 -> V_147 |= V_117 ;
V_143 -> V_35 = V_94 ;
V_143 -> V_99 = V_99 ;
V_143 -> V_148 = V_149 ;
V_143 -> V_150 = & V_2 -> V_5 -> V_146 [ V_94 ] ;
* V_143 -> V_150 = 0 ;
F_9 ( ( L_44 ) ) ;
return V_94 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
T_1 V_117 ;
int V_3 ;
F_9 ( ( L_45 , V_143 -> V_35 ) ) ;
if ( F_24 ( ! F_64 ( V_2 , V_143 -> V_35 ) ) )
return - V_55 ;
if ( F_24 ( V_143 -> V_148 != V_149 ) )
return - V_55 ;
for ( V_117 = V_3 = 0 ; V_3 < V_143 -> V_99 ; V_3 ++ )
V_117 |= 1 << ( V_143 -> V_35 + V_3 ) ;
V_2 -> V_125 &= ~ V_117 ;
V_2 -> V_147 &= ~ V_117 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
V_143 -> V_151 = 0 ;
memset ( V_143 -> V_152 . V_153 , 0 , V_154 ) ;
V_2 -> V_5 -> V_155 [ V_143 -> V_35 ] . V_156 =
F_29 ( V_143 -> V_152 . V_156 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_142 * V_143 ,
T_5 V_34 , T_6 V_157 )
{
int V_158 = V_143 -> V_151 ;
struct V_159 * V_160 = (struct V_159 * ) V_143 -> V_152 . V_153 ;
if ( V_158 < V_161 - 1 ) {
V_160 [ V_158 ] . V_156 = F_29 ( V_34 ) ;
V_160 [ V_158 ] . V_31 = F_29 ( V_157 ) ;
V_143 -> V_151 ++ ;
} else {
F_9 ( ( L_46 ) ) ;
return - V_162 ;
}
return 0 ;
}
static inline int F_77 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
return F_76 ( V_2 , V_143 , 0 , 0 ) ;
}
static inline int F_78 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
return F_76 ( V_2 , V_143 , V_143 -> V_152 . V_156 , 0 ) ;
}
