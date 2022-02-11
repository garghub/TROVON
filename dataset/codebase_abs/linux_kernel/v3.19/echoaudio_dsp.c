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
F_4 ( V_2 -> V_7 -> V_8 , L_2 ) ;
return - V_9 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_14 )
{
T_1 V_15 , V_3 ;
for ( V_3 = 0 ; V_3 < 10000000 ; V_3 ++ ) {
V_15 = F_7 ( V_2 , V_16 ) ;
if ( ( V_15 & V_17 ) != 0 ) {
F_8 ( V_2 , V_18 , V_14 ) ;
F_6 () ;
return 0 ;
}
F_3 ( 1 ) ;
F_10 () ;
}
V_2 -> V_19 = TRUE ;
F_11 ( V_2 -> V_7 -> V_8 , L_3 ) ;
return - V_20 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_14 )
{
T_1 V_15 , V_3 ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ ) {
V_15 = F_7 ( V_2 , V_16 ) ;
if ( ( V_15 & V_22 ) != 0 ) {
* V_14 = F_7 ( V_2 , V_18 ) ;
return 0 ;
}
F_3 ( 1 ) ;
F_10 () ;
}
V_2 -> V_19 = TRUE ;
F_4 ( V_2 -> V_7 -> V_8 , L_4 ) ;
return - V_20 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_23 [ 6 ] ;
for ( V_3 = 0 ; V_3 < 5 ; V_3 ++ ) {
if ( F_12 ( V_2 , & V_23 [ V_3 ] ) ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_5 ) ;
return - V_20 ;
}
}
F_11 ( V_2 -> V_7 -> V_8 ,
L_6 ,
V_23 [ 0 ] , V_23 [ 1 ] , V_23 [ 2 ] , V_23 [ 3 ] , V_23 [ 4 ] ) ;
return 0 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
V_2 -> V_24 = TRUE ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_25 , short V_26 )
{
const struct V_27 * V_28 ;
int V_29 ;
T_1 V_3 , V_30 ;
T_2 * V_31 ;
V_29 = F_16 ( & V_28 , V_2 , V_26 ) ;
if ( V_29 < 0 ) {
F_17 ( V_2 -> V_7 -> V_8 , L_7 ) ;
return V_29 ;
}
V_31 = ( T_2 * ) V_28 -> V_14 ;
V_30 = V_28 -> V_30 ;
if ( F_9 ( V_2 , V_25 ) < 0 )
goto V_32;
if ( F_9 ( V_2 , V_30 ) < 0 )
goto V_32;
for ( V_3 = 0 ; V_3 < V_30 ; V_3 ++ ) {
if ( F_9 ( V_2 , V_31 [ V_3 ] ) < 0 )
goto V_32;
}
F_18 ( V_28 , V_2 ) ;
return 0 ;
V_32:
F_4 ( V_2 -> V_7 -> V_8 , L_8 ) ;
F_18 ( V_28 , V_2 ) ;
return - V_20 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_1 V_33 ;
int V_34 , V_35 , V_3 ;
T_3 * V_31 ;
T_1 V_15 ;
const struct V_27 * V_28 ;
if ( V_2 -> V_36 != V_37 )
return 0 ;
V_15 = F_7 ( V_2 , V_16 ) ;
if ( V_15 & V_38 ) {
F_11 ( V_2 -> V_7 -> V_8 ,
L_9 ,
V_15 ) ;
return 0 ;
}
V_3 = F_16 ( & V_28 , V_2 , V_39 ) ;
if ( V_3 < 0 ) {
F_17 ( V_2 -> V_7 -> V_8 , L_7 ) ;
return V_3 ;
}
F_8 ( V_2 , V_40 ,
F_7 ( V_2 , V_40 ) | 0x900 ) ;
V_31 = ( T_3 * ) V_28 -> V_14 ;
V_34 = V_31 [ 0 ] ;
V_34 += 3 ;
V_35 = V_31 [ V_34 ++ ] ;
V_33 = ( ( T_1 ) V_31 [ V_34 ] << 16 ) + V_31 [ V_34 + 1 ] ;
V_34 += 2 ;
if ( F_9 ( V_2 , V_35 ) ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_10 ) ;
goto V_41;
}
if ( F_9 ( V_2 , V_33 ) ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_11 ) ;
goto V_41;
}
for ( V_3 = 0 ; V_3 < V_35 ; V_3 ++ ) {
T_1 V_14 ;
V_14 = ( ( T_1 ) V_31 [ V_34 ] << 16 ) + V_31 [ V_34 + 1 ] ;
if ( F_9 ( V_2 , V_14 ) ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_12 ) ;
goto V_41;
}
V_34 += 2 ;
}
for ( V_3 = 0 ; V_3 < 200 ; V_3 ++ ) {
F_3 ( 50 ) ;
V_15 = F_7 ( V_2 , V_16 ) ;
if ( V_15 & V_38 )
break;
}
if ( V_3 == 200 ) {
F_4 ( V_2 -> V_7 -> V_8 , L_13 ) ;
goto V_41;
}
F_11 ( V_2 -> V_7 -> V_8 , L_14 ) ;
F_18 ( V_28 , V_2 ) ;
return 0 ;
V_41:
F_18 ( V_28 , V_2 ) ;
return - V_20 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 * V_31 )
{
T_1 V_33 , V_14 ;
int V_34 , V_35 , V_3 ;
if ( V_2 -> V_42 == V_31 ) {
F_17 ( V_2 -> V_7 -> V_8 , L_15 ) ;
return 0 ;
}
V_2 -> V_19 = TRUE ;
V_2 -> V_42 = NULL ;
V_2 -> V_24 = FALSE ;
F_11 ( V_2 -> V_7 -> V_8 , L_16 ) ;
#ifdef F_21
if ( ( V_3 = F_19 ( V_2 ) ) < 0 )
return V_3 ;
#endif
if ( F_5 ( V_2 , V_43 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_17 ) ;
return - V_20 ;
}
F_3 ( 10 ) ;
for ( V_3 = 0 ; V_3 < 1000 ; V_3 ++ ) {
if ( F_7 ( V_2 , V_16 ) &
V_44 )
break;
F_3 ( 10 ) ;
}
if ( V_3 == 1000 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_18 ) ;
return - V_20 ;
}
F_8 ( V_2 , V_40 ,
F_7 ( V_2 , V_40 ) | 0x900 ) ;
V_34 = V_31 [ 0 ] ;
for (; ; ) {
int V_45 , V_46 ;
V_34 ++ ;
V_45 = V_31 [ V_34 ] ;
if ( V_45 == 4 )
break;
V_34 ++ ;
V_46 = V_31 [ V_34 ++ ] ;
V_35 = V_31 [ V_34 ++ ] ;
if ( V_35 == 0 )
break;
V_33 = ( ( T_1 ) V_31 [ V_34 ] << 16 ) + V_31 [ V_34 + 1 ] ;
V_34 += 2 ;
if ( F_9 ( V_2 , V_35 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_19 ) ;
return - V_20 ;
}
if ( F_9 ( V_2 , V_33 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_20 ) ;
return - V_20 ;
}
if ( F_9 ( V_2 , V_46 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_21 ) ;
return - V_20 ;
}
for ( V_3 = 0 ; V_3 < V_35 ; V_3 ++ , V_34 += 2 ) {
V_14 = ( ( T_1 ) V_31 [ V_34 ] << 16 ) + V_31 [ V_34 + 1 ] ;
if ( F_9 ( V_2 , V_14 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_22 ) ;
return - V_20 ;
}
}
}
if ( F_9 ( V_2 , 0 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_23 ) ;
return - V_20 ;
}
F_3 ( 10 ) ;
for ( V_3 = 0 ; V_3 < 5000 ; V_3 ++ ) {
if ( F_7 ( V_2 , V_16 ) &
V_47 ) {
F_8 ( V_2 , V_40 ,
F_7 ( V_2 , V_40 ) & ~ 0x1b00 ) ;
if ( F_9 ( V_2 , V_48 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_24 ) ;
return - V_20 ;
}
if ( F_9 ( V_2 , V_2 -> V_49 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_25 ) ;
return - V_20 ;
}
if ( F_13 ( V_2 ) < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_26 ) ;
return - V_20 ;
}
V_2 -> V_42 = V_31 ;
V_2 -> V_19 = FALSE ;
return 0 ;
}
F_3 ( 100 ) ;
}
F_4 ( V_2 -> V_7 -> V_8 ,
L_27 ) ;
return - V_20 ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_27 * V_28 ;
int V_50 , V_29 ;
if ( F_23 ( ! V_2 -> V_5 ) )
return - V_51 ;
if ( V_2 -> V_42 ) {
if ( ( V_50 = F_14 ( V_2 ) ) >= 0 )
return V_50 ;
V_2 -> V_42 = NULL ;
}
V_29 = F_16 ( & V_28 , V_2 , V_2 -> V_52 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_20 ( V_2 , ( T_3 * ) V_28 -> V_14 ) ;
F_18 ( V_28 , V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ( V_50 = F_24 ( V_2 ) ) < 0 )
return V_50 ;
return V_50 ;
}
static int F_25 ( struct V_1 * V_2 , T_3 V_34 , char V_53 )
{
if ( F_23 ( V_34 >= F_26 ( V_2 ) + F_27 ( V_2 ) ) )
return - V_54 ;
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_55 [ V_34 ] = V_53 ;
if ( V_53 )
V_2 -> V_5 -> V_56 |= F_28 ( 1 << V_34 ) ;
else
V_2 -> V_5 -> V_56 &= ~ F_28 ( 1 << V_34 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_3 V_57 , T_4 V_58 )
{
if ( F_23 ( V_57 >= F_26 ( V_2 ) ) )
return - V_54 ;
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_59 [ V_57 ] = V_58 ;
V_2 -> V_5 -> V_60 [ V_57 ] = V_58 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , T_3 V_61 , T_3 V_62 ,
T_4 V_58 )
{
if ( F_23 ( V_61 >= F_26 ( V_2 ) ||
V_62 >= F_27 ( V_2 ) ) )
return - V_54 ;
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_63 [ V_61 ] [ V_62 ] = V_58 ;
V_2 -> V_5 -> V_64 [ F_31 ( V_2 , V_61 , V_62 ) ] = V_58 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return - V_20 ;
F_33 ( V_2 ) ;
return F_5 ( V_2 , V_65 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return - V_20 ;
F_33 ( V_2 ) ;
return F_5 ( V_2 , V_66 ) ;
}
static void F_35 ( struct V_1 * V_2 , char V_67 )
{
if ( V_67 && ! V_2 -> V_68 ) {
F_5 ( V_2 , V_69 ) ;
V_2 -> V_68 = 1 ;
} else if ( ! V_67 && V_2 -> V_68 ) {
F_5 ( V_2 , V_70 ) ;
V_2 -> V_68 = 0 ;
memset ( ( T_4 * ) V_2 -> V_5 -> V_71 , V_72 ,
V_73 ) ;
memset ( ( T_4 * ) V_2 -> V_5 -> V_74 , V_72 ,
V_73 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , long * V_75 )
{
int V_3 , V_76 , V_77 ;
V_76 = 0 ;
V_77 = 0 ;
for ( V_3 = 0 ; V_3 < F_26 ( V_2 ) ; V_3 ++ , V_76 ++ ) {
V_75 [ V_77 ++ ] = V_2 -> V_5 -> V_71 [ V_76 ] ;
V_75 [ V_77 ++ ] = V_2 -> V_5 -> V_74 [ V_76 ] ;
}
for (; V_77 < 32 ; V_77 ++ )
V_75 [ V_77 ] = 0 ;
#ifdef F_37
V_76 = V_78 ;
#endif
for ( V_3 = 0 ; V_3 < F_27 ( V_2 ) ; V_3 ++ , V_76 ++ ) {
V_75 [ V_77 ++ ] = V_2 -> V_5 -> V_71 [ V_76 ] ;
V_75 [ V_77 ++ ] = V_2 -> V_5 -> V_74 [ V_76 ] ;
}
for (; V_77 < 64 ; V_77 ++ )
V_75 [ V_77 ] = 0 ;
#ifdef F_38
for ( V_3 = 0 ; V_3 < F_39 ( V_2 ) ; V_3 ++ , V_76 ++ ) {
V_75 [ V_77 ++ ] = V_2 -> V_5 -> V_71 [ V_76 ] ;
V_75 [ V_77 ++ ] = V_2 -> V_5 -> V_74 [ V_76 ] ;
}
#endif
for (; V_77 < 96 ; V_77 ++ )
V_75 [ V_77 ] = 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_3 , V_79 , V_29 ;
if ( ( V_29 = F_14 ( V_2 ) ) < 0 )
return V_29 ;
V_2 -> V_5 -> V_80 = V_81 ;
V_2 -> V_5 -> V_82 = V_83 ;
V_2 -> V_5 -> V_6 = 0xffffffff ;
for ( V_3 = 0 ; V_3 < F_26 ( V_2 ) ; V_3 ++ ) {
V_29 = F_29 ( V_2 , V_3 , V_2 -> V_59 [ V_3 ] ) ;
if ( V_29 < 0 )
return V_29 ;
}
#ifdef F_38
for ( V_3 = 0 ; V_3 < F_39 ( V_2 ) ; V_3 ++ )
for ( V_79 = 0 ; V_79 < F_26 ( V_2 ) ; V_79 ++ ) {
V_29 = F_41 ( V_2 , V_79 , V_3 ,
V_2 -> V_84 [ V_79 ] [ V_3 ] ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( F_42 ( V_2 ) < 0 )
return - V_20 ;
#endif
#ifdef F_43
for ( V_79 = 0 ; V_79 < F_26 ( V_2 ) ; V_79 ++ )
for ( V_3 = 0 ; V_3 < F_27 ( V_2 ) ; V_3 ++ ) {
V_29 = F_30 ( V_2 , V_79 , V_3 ,
V_2 -> V_63 [ V_79 ] [ V_3 ] ) ;
if ( V_29 < 0 )
return V_29 ;
}
#endif
#ifdef F_44
for ( V_3 = 0 ; V_3 < F_27 ( V_2 ) ; V_3 ++ ) {
V_29 = F_45 ( V_2 , V_3 , V_2 -> V_85 [ V_3 ] ) ;
if ( V_29 < 0 )
return V_29 ;
}
#endif
V_29 = F_32 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_34 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_46 ( V_2 , V_2 -> V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_2 -> V_68 ) {
V_29 = F_5 ( V_2 , V_69 ) ;
if ( V_29 < 0 )
return V_29 ;
}
#ifdef F_47
if ( F_48 ( V_2 , V_2 -> V_87 ) < 0 )
return - V_20 ;
#endif
#ifdef F_49
if ( F_50 ( V_2 , V_2 -> V_88 ) < 0 )
return - V_20 ;
#endif
#ifdef F_51
if ( F_52 ( V_2 , V_2 -> V_89 ) < 0 )
return - V_20 ;
#endif
#ifdef F_53
if ( F_54 ( V_2 , V_2 -> V_90 ) < 0 )
return - V_20 ;
#endif
#ifdef F_55
if ( F_56 ( V_2 , V_2 -> V_91 ) < 0 )
return - V_20 ;
#endif
if ( F_1 ( V_2 ) < 0 )
return - V_20 ;
F_33 ( V_2 ) ;
if ( F_5 ( V_2 , V_92 ) < 0 )
return - V_20 ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , T_3 V_93 ,
const struct V_94 * V_95 )
{
T_3 V_96 ;
V_96 = V_97 ;
if ( V_95 -> V_98 > 2 ) {
switch ( V_95 -> V_99 ) {
case 16 :
V_96 = V_100 ;
break;
case 24 :
V_96 = V_101 ;
break;
case 32 :
V_96 = V_102 ;
break;
}
V_96 |= V_95 -> V_98 ;
} else if ( V_95 -> V_103 ) {
switch ( V_95 -> V_98 ) {
case 1 :
V_96 = V_104 ;
break;
#ifdef F_58
case 2 :
V_96 = V_105 ;
break;
#endif
}
} else if ( V_95 -> V_98 == 1 &&
V_95 -> V_99 == 32 && ! V_95 -> V_106 ) {
V_96 = V_107 ;
} else {
switch ( V_95 -> V_99 ) {
case 8 :
if ( V_95 -> V_98 == 2 )
V_96 = V_108 ;
else
V_96 = V_109 ;
break;
default:
case 16 :
if ( V_95 -> V_98 == 2 )
V_96 = V_97 ;
else
V_96 = V_110 ;
break;
case 24 :
if ( V_95 -> V_98 == 2 )
V_96 = V_111 ;
else
V_96 = V_112 ;
break;
case 32 :
if ( V_95 -> V_98 == 2 )
V_96 = V_113 ;
else
V_96 = V_114 ;
break;
}
}
F_11 ( V_2 -> V_7 -> V_8 ,
L_28 , V_93 , V_96 ) ;
V_2 -> V_5 -> V_115 [ V_93 ] = F_59 ( V_96 ) ;
}
static int F_60 ( struct V_1 * V_2 , T_1 V_116 ,
T_1 V_117 )
{
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_5 -> V_118 |= F_28 ( V_116 ) ;
if ( V_2 -> V_5 -> V_118 ) {
F_33 ( V_2 ) ;
F_5 ( V_2 , V_119 ) ;
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_120 |= V_116 ;
V_2 -> V_5 -> V_118 = 0 ;
return 0 ;
}
F_4 ( V_2 -> V_7 -> V_8 , L_29 ) ;
return - V_54 ;
}
static int F_61 ( struct V_1 * V_2 , T_1 V_116 )
{
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_5 -> V_121 |= F_28 ( V_116 ) ;
V_2 -> V_5 -> V_122 = 0 ;
if ( V_2 -> V_5 -> V_121 ) {
F_33 ( V_2 ) ;
F_5 ( V_2 , V_123 ) ;
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_120 &= ~ V_116 ;
V_2 -> V_5 -> V_121 = 0 ;
V_2 -> V_5 -> V_122 = 0 ;
return 0 ;
}
F_17 ( V_2 -> V_7 -> V_8 , L_30 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , T_1 V_116 )
{
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_5 -> V_121 |= F_28 ( V_116 ) ;
V_2 -> V_5 -> V_122 |= F_28 ( V_116 ) ;
if ( V_2 -> V_5 -> V_122 ) {
F_33 ( V_2 ) ;
F_5 ( V_2 , V_123 ) ;
if ( F_1 ( V_2 ) )
return - V_20 ;
V_2 -> V_120 &= ~ V_116 ;
V_2 -> V_5 -> V_121 = 0 ;
V_2 -> V_5 -> V_122 = 0 ;
return 0 ;
}
F_17 ( V_2 -> V_7 -> V_8 , L_31 ) ;
return 0 ;
}
static inline int F_63 ( struct V_1 * V_2 , T_3 V_93 )
{
return ( V_2 -> V_124 & ( 1 << V_93 ) ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
F_62 ( V_2 , V_2 -> V_120 ) ;
F_35 ( V_2 , FALSE ) ;
#ifdef F_65
F_66 ( V_2 , FALSE ) ;
#endif
if ( V_2 -> V_42 ) {
V_2 -> V_42 = NULL ;
return F_5 ( V_2 , V_125 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
if ( F_68 ( struct V_5 , V_126 ) != 0xbe0 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_32 ) ;
return - V_51 ;
}
V_2 -> V_127 = V_128 ;
V_2 -> V_19 = TRUE ;
V_2 -> V_42 = NULL ;
V_2 -> V_24 = FALSE ;
memset ( V_2 -> V_5 , 0 , sizeof( struct V_5 ) ) ;
V_2 -> V_5 -> V_129 =
F_28 ( sizeof( struct V_5 ) ) ;
V_2 -> V_5 -> V_6 = 0xffffffff ;
V_2 -> V_5 -> V_130 =
F_28 ( V_131 ) ;
V_2 -> V_5 -> V_86 = F_28 ( 44100 ) ;
memset ( V_2 -> V_5 -> V_64 , V_72 , V_132 ) ;
memset ( V_2 -> V_5 -> V_133 , V_72 , V_134 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_59 , V_72 , sizeof( V_2 -> V_59 ) ) ;
memset ( V_2 -> V_85 , V_72 , sizeof( V_2 -> V_85 ) ) ;
memset ( V_2 -> V_63 , V_72 , sizeof( V_2 -> V_63 ) ) ;
memset ( V_2 -> V_84 , V_72 , sizeof( V_2 -> V_84 ) ) ;
V_2 -> V_90 = V_135 ;
V_2 -> V_91 = V_136 ;
V_2 -> V_86 = 44100 ;
return F_40 ( V_2 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_137 ;
if ( F_7 ( V_2 , V_16 ) & V_138 ) {
V_137 = 0 ;
#ifdef F_65
if ( V_2 -> V_5 -> V_139 [ 0 ] )
V_137 = F_71 ( V_2 ) ;
#endif
V_2 -> V_5 -> V_139 [ 0 ] = 0 ;
F_5 ( V_2 , V_140 ) ;
return V_137 ;
}
return - 1 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_141 * V_142 ,
int V_93 , int V_98 )
{
int V_3 ;
T_1 V_116 ;
char V_143 ;
F_11 ( V_2 -> V_7 -> V_8 ,
L_33 , V_93 , V_98 ) ;
if ( V_2 -> V_19 )
return - V_20 ;
V_143 = 1 ;
for ( V_116 = V_3 = 0 ; V_3 < V_98 ; V_3 ++ )
V_116 |= 1 << ( V_93 + V_3 ) ;
if ( V_2 -> V_124 & V_116 ) {
F_4 ( V_2 -> V_7 -> V_8 ,
L_34 ) ;
return - V_144 ;
}
V_2 -> V_5 -> V_145 [ V_93 ] = 0 ;
V_2 -> V_124 |= V_116 ;
if ( V_143 )
V_2 -> V_146 |= V_116 ;
V_142 -> V_34 = V_93 ;
V_142 -> V_98 = V_98 ;
V_142 -> V_147 = V_148 ;
V_142 -> V_149 = & V_2 -> V_5 -> V_145 [ V_93 ] ;
* V_142 -> V_149 = 0 ;
return V_93 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
T_1 V_116 ;
int V_3 ;
if ( F_23 ( ! F_63 ( V_2 , V_142 -> V_34 ) ) )
return - V_54 ;
if ( F_23 ( V_142 -> V_147 != V_148 ) )
return - V_54 ;
for ( V_116 = V_3 = 0 ; V_3 < V_142 -> V_98 ; V_3 ++ )
V_116 |= 1 << ( V_142 -> V_34 + V_3 ) ;
V_2 -> V_124 &= ~ V_116 ;
V_2 -> V_146 &= ~ V_116 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
V_142 -> V_150 = 0 ;
memset ( V_142 -> V_151 . V_152 , 0 , V_153 ) ;
V_2 -> V_5 -> V_154 [ V_142 -> V_34 ] . V_155 =
F_28 ( V_142 -> V_151 . V_155 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_141 * V_142 ,
T_5 V_33 , T_6 V_156 )
{
int V_157 = V_142 -> V_150 ;
struct V_158 * V_159 = (struct V_158 * ) V_142 -> V_151 . V_152 ;
if ( V_157 < V_160 - 1 ) {
V_159 [ V_157 ] . V_155 = F_28 ( V_33 ) ;
V_159 [ V_157 ] . V_30 = F_28 ( V_156 ) ;
V_142 -> V_150 ++ ;
} else {
F_4 ( V_2 -> V_7 -> V_8 , L_35 ) ;
return - V_161 ;
}
return 0 ;
}
static inline int F_76 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
return F_75 ( V_2 , V_142 , 0 , 0 ) ;
}
static inline int F_77 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
return F_75 ( V_2 , V_142 , V_142 -> V_151 . V_155 , 0 ) ;
}
