static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * args )
{
struct V_6 V_7 ;
struct V_6 V_8 ;
struct V_9 * V_10 = & V_2 -> V_11 ;
T_1 V_12 = V_10 -> V_13 ;
struct V_14 * V_15 = & V_10 -> V_16 [ V_12 ] ;
int V_17 ;
int V_18 , V_19 ;
unsigned long V_20 , V_21 ;
int V_22 , V_23 , V_24 ;
V_20 = V_25 + V_26 [ V_12 ] ;
V_21 = V_20 + V_27 ;
V_22 = V_23 = V_15 -> V_28 + V_15 -> V_29 ;
if ( V_15 -> V_30 )
V_20 += 720 * 16 ;
if ( V_22 & 15 )
V_22 = ( V_22 + 16 ) & ~ 15 ;
if ( V_23 & 31 )
V_23 = ( V_23 + 32 ) & ~ 31 ;
V_24 = 720 * V_22 ;
if ( V_4 -> V_31 || V_4 -> V_32 ) {
F_2
( L_1 ,
V_4 -> V_31 , V_4 -> V_32 ) ;
return - V_33 ;
}
F_3 ( & V_7 , ( unsigned long ) args -> V_34 , 720 * V_22 ) ;
F_3 ( & V_8 , ( unsigned long ) args -> V_35 , 360 * V_23 ) ;
F_4 ( & V_36 -> V_37 -> V_38 ) ;
V_18 = F_5 ( V_36 , V_36 -> V_37 , V_7 . V_39 , V_7 . V_32 , 0 , 1 , & V_4 -> V_40 [ 0 ] , NULL ) ;
V_19 = 0 ;
if ( V_18 == V_7 . V_32 ) {
V_19 = F_5 ( V_36 , V_36 -> V_37 ,
V_8 . V_39 , V_8 . V_32 , 0 , 1 ,
& V_4 -> V_40 [ V_18 ] , NULL ) ;
}
F_6 ( & V_36 -> V_37 -> V_38 ) ;
if ( V_18 != V_7 . V_32 || V_19 != V_8 . V_32 ) {
int V_41 = - V_42 ;
if ( V_18 == V_7 . V_32 ) {
F_2
( L_2
L_3 , V_19 , V_8 . V_32 ) ;
if ( V_19 >= 0 ) {
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
F_7 ( V_4 -> V_40 [ V_18 + V_17 ] ) ;
V_41 = - V_42 ;
} else {
V_41 = V_19 ;
}
} else {
F_2
( L_4
L_3 , V_18 , V_7 . V_32 ) ;
}
if ( V_18 >= 0 ) {
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_7 ( V_4 -> V_40 [ V_17 ] ) ;
} else {
V_41 = V_18 ;
}
return V_41 ;
}
V_4 -> V_32 = V_18 + V_19 ;
if ( F_8 ( V_4 , & V_8 , F_8 ( V_4 , & V_7 , 0 ) ) < 0 ) {
F_2 ( L_5 ) ;
for ( V_17 = 0 ; V_17 < V_4 -> V_32 ; V_17 ++ ) {
F_7 ( V_4 -> V_40 [ V_17 ] ) ;
}
V_4 -> V_32 = 0 ;
return - V_43 ;
}
V_4 -> V_31 = F_9 ( V_2 -> V_44 , V_4 -> V_45 , V_4 -> V_32 , V_46 ) ;
F_10 ( V_4 , V_20 , V_21 , V_24 ) ;
if ( V_15 -> V_30 && V_10 -> V_47 ) {
V_4 -> V_48 [ V_4 -> V_31 ] . V_49 = F_11 ( 720 * 16 ) ;
V_4 -> V_48 [ V_4 -> V_31 ] . V_50 = F_11 ( V_10 -> V_47 ) ;
V_4 -> V_48 [ V_4 -> V_31 ] . V_51 = F_11 ( V_25 + V_26 [ V_12 ] ) ;
V_4 -> V_31 ++ ;
}
V_4 -> V_48 [ V_4 -> V_31 - 1 ] . V_49 |= F_11 ( 0x80000000 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_17 , V_52 , V_53 ;
for ( V_17 = 0 , V_52 = 16 , V_53 = 4 ; V_17 < 16 ; V_17 ++ , V_52 += 24 , V_53 += 12 ) {
if ( ( F_14 ( V_54 + V_52 ) != V_17 << 16 ) ||
( F_14 ( V_55 + V_53 ) != V_17 << 16 ) ) {
F_15 ( L_6 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , int V_56 , int V_57 , int V_58 )
{
T_2 V_17 , line ;
if ( V_56 > - 1 ) {
if ( V_56 > 4 )
V_56 = 4 ;
V_17 = V_54 + ( V_56 * 384 ) ;
for ( line = 0 ; line < 16 ; line ++ ) {
F_17 ( F_14 ( V_17 ) , 0x02804 ) ;
F_17 ( F_14 ( V_17 ) , 0x0281c ) ;
V_17 += 4 ;
F_17 ( F_14 ( V_17 ) , 0x02808 ) ;
F_17 ( F_14 ( V_17 ) , 0x02820 ) ;
V_17 += 4 ;
F_17 ( F_14 ( V_17 ) , 0x0280c ) ;
F_17 ( F_14 ( V_17 ) , 0x02824 ) ;
V_17 += 4 ;
F_17 ( F_14 ( V_17 ) , 0x02810 ) ;
F_17 ( F_14 ( V_17 ) , 0x02828 ) ;
V_17 += 4 ;
F_17 ( F_14 ( V_17 ) , 0x02814 ) ;
F_17 ( F_14 ( V_17 ) , 0x0282c ) ;
V_17 += 8 ;
F_17 ( 0 , 0x02818 ) ;
F_17 ( 0 , 0x02830 ) ;
}
F_18 ( L_7 , V_56 ) ;
}
if ( V_57 > - 1 ) {
if ( V_57 > 4 )
V_57 = 4 ;
V_17 = V_55 + ( V_57 * 192 ) ;
for ( line = 0 ; line < 16 ; line ++ ) {
F_17 ( F_14 ( V_17 ) , 0x02900 ) ;
V_17 += 4 ;
F_17 ( F_14 ( V_17 ) , 0x02904 ) ;
V_17 += 8 ;
F_17 ( 0 , 0x02908 ) ;
}
F_18 ( L_8 , V_57 ) ;
}
if ( V_58 > - 1 ) {
if ( V_58 > 4 )
V_58 = 4 ;
V_17 = V_55 + ( V_58 * 192 ) ;
for ( line = 0 ; line < 16 ; line ++ ) {
F_17 ( F_14 ( V_17 ) , 0x0290c ) ;
V_17 += 4 ;
F_17 ( F_14 ( V_17 ) , 0x02910 ) ;
V_17 += 8 ;
F_17 ( 0 , 0x02914 ) ;
}
F_18 ( L_9 , V_58 ) ;
}
}
static void F_19 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
T_2 V_59 , V_60 , V_61 ;
T_2 V_62 , V_63 , V_64 ;
T_2 V_65 , V_66 , V_67 ;
T_2 V_68 , V_69 , V_70 ;
int V_71 ;
int V_56 ;
T_2 V_72 ;
F_2
( L_10 ,
V_15 -> V_73 , V_15 -> V_74 , V_15 -> V_75 , V_15 -> V_76 , V_15 -> V_77 ) ;
V_71 = V_15 -> V_74 + V_15 -> V_76 ;
V_59 = V_15 -> V_75 ;
V_60 = V_59 ;
V_67 = V_15 -> V_77 ;
V_68 = 0 ;
if ( V_15 -> V_78 == 720 ) {
if ( ( V_15 -> V_79 - V_15 -> V_80 > - 1 ) && ( V_15 -> V_79 - V_15 -> V_80 <= 40 ) && ( V_15 -> V_75 >= 680 ) )
V_68 = 10 - ( V_15 -> V_79 - V_15 -> V_80 ) / 4 ;
else if ( ( V_15 -> V_79 - V_15 -> V_80 < 0 ) && ( V_15 -> V_79 - V_15 -> V_80 >= - 20 ) && ( V_15 -> V_75 >= 660 ) )
V_68 = ( 10 + ( V_15 -> V_79 - V_15 -> V_80 ) / 2 ) ;
if ( V_15 -> V_75 >= V_15 -> V_74 )
V_68 = V_68 << 16 | V_68 ;
else
V_68 = ( ( V_68 & ~ 1 ) << 15 ) | ( V_68 & ~ 1 ) ;
}
if ( V_15 -> V_75 < V_15 -> V_74 )
V_68 = 0x000d000e - V_68 ;
else
V_68 = 0x0012000e - V_68 ;
V_70 = ( V_15 -> V_76 * ( ( V_15 -> V_75 << 21 ) / V_15 -> V_74 ) ) >> 19 ;
if ( V_15 -> V_75 >= V_15 -> V_74 ) {
V_71 &= ~ 1 ;
V_72 = ( V_15 -> V_74 * 0x00200000 ) / ( V_15 -> V_75 ) ;
if ( V_72 * V_15 -> V_75 != V_15 -> V_74 * 0x00200000 )
V_72 ++ ;
V_59 = ( V_59 << 16 ) | V_71 ;
V_60 = ( V_60 << 16 ) | V_71 ;
V_61 = V_72 >> 2 ;
V_62 = V_72 >> 2 ;
V_63 = V_72 ;
V_64 = V_72 >> 1 ;
V_65 = V_72 >> 1 ;
if ( V_15 -> V_75 > V_15 -> V_74 )
V_69 = ( ( V_15 -> V_75 - V_15 -> V_74 ) << 16 ) / ( V_15 -> V_74 << 14 ) ;
else
V_69 = 0 ;
V_68 += ( ( ( V_70 << 14 ) & 0xFFFF0000 ) | V_70 >> 2 ) + ( V_69 << 17 | V_69 ) ;
V_66 = 0 ;
} else if ( V_15 -> V_75 < V_15 -> V_74 / 2 ) {
V_72 = ( V_15 -> V_74 * 0x00080000 ) / V_15 -> V_75 ;
if ( V_72 * V_15 -> V_75 != V_15 -> V_74 * 0x00080000 )
V_72 ++ ;
V_59 = ( V_59 << 16 ) | V_71 ;
V_60 = ( V_60 << 16 ) | V_71 ;
V_61 = V_72 >> 2 ;
V_62 = V_72 >> 1 ;
V_63 = V_72 ;
V_64 = V_72 >> 1 ;
V_65 = V_72 >> 1 ;
V_68 += ( ( V_70 << 15 ) & 0xFFFF0000 ) | V_70 ;
V_68 += ( 5 - ( ( ( V_15 -> V_74 + V_15 -> V_74 / 2 ) - 1 ) / V_15 -> V_75 ) ) << 16 ;
V_66 = 0x00000012 ;
} else {
V_72 = ( V_15 -> V_74 * 0x00100000 ) / V_15 -> V_75 ;
if ( V_72 * V_15 -> V_75 != V_15 -> V_74 * 0x00100000 )
V_72 ++ ;
V_59 = ( V_59 << 16 ) | V_71 ;
V_60 = ( V_60 << 16 ) | V_71 ;
V_61 = V_72 >> 2 ;
V_62 = V_72 >> 1 ;
V_63 = V_72 ;
V_64 = V_72 >> 1 ;
V_65 = V_72 >> 1 ;
V_68 += ( ( V_70 << 14 ) & 0xFFFF0000 ) | V_70 >> 1 ;
V_68 += ( 5 - ( ( ( V_15 -> V_74 * 3 ) - 1 ) / V_15 -> V_75 ) ) << 16 ;
V_66 = 0x00000001 ;
}
if ( V_15 -> V_74 == V_15 -> V_75 ) {
V_56 = 0 ;
} else {
V_56 = ( ( V_15 -> V_74 << 16 ) / V_15 -> V_75 ) >> 15 ;
V_56 = ( V_56 >> 1 ) + ( V_56 & 1 ) ;
V_56 += ! V_56 ;
}
F_17 ( V_59 , 0x02834 ) ;
F_17 ( V_60 , 0x02838 ) ;
F_18 ( L_11 ,
V_10 -> V_59 , V_59 , V_10 -> V_60 , V_60 ) ;
F_17 ( V_61 , 0x0283c ) ;
F_17 ( V_62 , 0x02844 ) ;
F_18 ( L_12 ,
V_10 -> V_61 , V_61 , V_10 -> V_62 , V_62 ) ;
F_17 ( 0x00080514 , 0x02840 ) ;
F_17 ( 0x00100514 , 0x02848 ) ;
F_18 ( L_13 ,
V_10 -> V_81 , 0x00080514 , V_10 -> V_82 , 0x00100514 ) ;
F_17 ( V_63 , 0x02854 ) ;
F_18 ( L_14 ,
V_10 -> V_63 , V_63 ) ;
F_17 ( V_64 , 0x0285c ) ;
F_17 ( V_65 , 0x02864 ) ;
F_18 ( L_15 ,
V_10 -> V_64 , V_64 , V_10 -> V_65 , V_65 ) ;
F_17 ( V_66 , 0x02874 ) ;
F_18 ( L_16 ,
V_10 -> V_66 , V_66 ) ;
F_17 ( V_68 , 0x02870 ) ;
F_18 ( L_17 ,
V_10 -> V_68 , V_68 ) ;
F_17 ( V_67 , 0x02890 ) ;
F_18 ( L_18 ,
V_10 -> V_67 , V_67 ) ;
if ( V_56 != V_10 -> V_56 ) {
F_16 ( V_2 , V_56 , - 1 , - 1 ) ;
V_10 -> V_56 = V_56 ;
}
}
static void F_20 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
T_2 V_83 ;
T_2 V_84 , V_85 , V_86 , V_87 ;
T_2 V_88 , V_89 , V_90 ;
T_2 V_91 , V_92 , V_93 ;
T_2 V_94 , V_95 , V_96 , V_97 ;
T_2 V_98 , V_99 , V_100 , V_101 ;
T_2 V_102 ;
T_2 V_103 , V_104 ;
T_2 V_105 , V_106 ;
T_2 V_107 , V_108 ;
int V_57 , V_58 ;
F_2
( L_19 ,
V_15 -> V_109 , V_15 -> V_28 , V_15 -> V_110 , V_15 -> V_29 , V_15 -> V_111 ) ;
F_18 ( L_20 ,
V_15 -> V_112 ? L_21 : L_22 ) ;
F_18 ( L_23 ,
V_15 -> V_113 ? L_21 : L_22 ) ;
F_2 ( L_24 ,
V_15 -> V_114 ? L_21 : L_22 ) ;
if ( V_15 -> V_29 < 8 ) {
V_106 = V_15 -> V_29 ;
V_105 = 0 ;
} else {
V_106 = 8 ;
V_105 = V_15 -> V_29 - 8 ;
}
V_104 = V_106 ;
V_103 = V_105 ;
if ( V_15 -> V_30 )
V_104 += 16 ;
if ( V_15 -> V_112 )
V_84 = ( V_15 -> V_110 << 16 ) | ( V_15 -> V_28 + V_104 ) ;
else
V_84 = ( V_15 -> V_110 << 16 ) | ( ( V_15 -> V_28 + V_104 ) << 1 ) ;
if ( V_15 -> V_113 )
V_85 = ( V_15 -> V_110 << 16 ) | ( ( V_15 -> V_28 + V_106 ) >> 1 ) ;
else
V_85 = ( V_15 -> V_110 << 16 ) | ( V_15 -> V_28 + V_106 ) ;
V_107 = ( V_104 * ( ( V_15 -> V_110 << 16 ) / V_15 -> V_28 ) ) >> 14 ;
V_108 = ( V_106 * ( ( V_15 -> V_110 << 16 ) / V_15 -> V_28 ) ) >> 14 ;
if ( V_15 -> V_110 / 2 >= V_15 -> V_28 && ! V_15 -> V_112 ) {
V_83 = ( V_15 -> V_28 * 0x00400000 ) / V_15 -> V_110 ;
if ( ( V_15 -> V_28 * 0x00400000 ) - ( V_83 * V_15 -> V_110 ) >= V_15 -> V_110 / 2 )
V_83 ++ ;
V_86 = V_83 >> 2 ;
V_87 = V_83 >> 3 ;
V_88 = V_83 ;
V_91 = V_83 >> 1 ;
V_107 >>= 3 ;
V_108 >>= 3 ;
V_101 = 0x00000000 ;
} else if ( V_15 -> V_110 >= V_15 -> V_28 ) {
V_83 = ( V_15 -> V_28 * 0x00400000 ) / V_15 -> V_110 ;
V_83 = ( V_83 >> 1 ) + ( V_83 & 1 ) ;
V_86 = V_83 >> 2 ;
V_87 = V_83 >> 2 ;
V_88 = V_83 ;
V_91 = V_83 >> 1 ;
V_101 = 0x00000000 ;
if ( V_15 -> V_112 ) {
V_107 >>= 3 ;
} else {
V_101 ++ ;
V_107 >>= 2 ;
}
if ( V_15 -> V_113 )
V_87 >>= 1 ;
V_108 >>= 3 ;
} else if ( V_15 -> V_110 >= V_15 -> V_28 / 2 ) {
V_83 = ( V_15 -> V_28 * 0x00200000 ) / V_15 -> V_110 ;
V_83 = ( V_83 >> 1 ) + ( V_83 & 1 ) ;
V_86 = V_83 >> 2 ;
V_87 = V_83 >> 2 ;
V_88 = V_83 ;
V_91 = V_83 ;
V_101 = 0x00000101 ;
if ( V_15 -> V_112 ) {
V_107 >>= 2 ;
} else {
V_101 ++ ;
V_107 >>= 1 ;
}
if ( V_15 -> V_113 )
V_87 >>= 1 ;
V_108 >>= 2 ;
} else {
V_83 = ( V_15 -> V_28 * 0x00100000 ) / V_15 -> V_110 ;
V_83 = ( V_83 >> 1 ) + ( V_83 & 1 ) ;
V_86 = V_83 >> 2 ;
V_87 = V_83 >> 2 ;
V_88 = V_83 ;
V_91 = V_83 ;
V_107 >>= 1 ;
V_108 >>= 2 ;
V_101 = 0x00000102 ;
}
if ( V_15 -> V_28 == V_15 -> V_110 ) {
V_89 = 0x00020000 ;
V_90 = 0x00100000 ;
V_92 = 0x00040000 ;
V_93 = 0x000b0000 ;
} else {
V_89 = 0x00000FF0 ;
V_90 = 0x00000FF0 ;
V_92 = 0x00000FF0 ;
V_93 = 0x00000FF0 ;
}
V_94 = 0x00010000 + V_103 ;
if ( V_15 -> V_112 )
V_94 += 0x00010000 ;
V_95 = V_94 + 1 ;
V_96 = 0x00010000 + ( V_103 >> 1 ) ;
if ( V_15 -> V_113 )
V_96 += 0x00010000 ;
V_97 = V_96 + 1 ;
if ( V_10 -> V_115 == 480 )
V_102 = 0x011e0017 ;
else
V_102 = 0x01500017 ;
if ( V_15 -> V_111 < 0 )
V_102 = ( V_102 - ( ( V_15 -> V_111 & ~ 1 ) << 15 ) ) - ( V_15 -> V_111 >> 1 ) ;
else
V_102 = ( V_102 + ( ( V_15 -> V_111 & ~ 1 ) << 15 ) ) + ( V_15 -> V_111 >> 1 ) ;
V_98 = ( ( V_104 + V_15 -> V_28 + V_103 ) - 1 ) |
( ( ( V_106 + V_15 -> V_28 + V_105 - 1 ) & ~ 1 ) << 15 ) ;
if ( V_15 -> V_28 == V_15 -> V_110 ) {
V_99 = 1 ;
} else {
V_99 = 2 + ( ( V_15 -> V_110 << 1 ) / V_15 -> V_28 ) ;
V_99 = ( V_99 >> 1 ) + ( V_99 & 1 ) ;
}
V_100 = ( V_99 << 16 ) + V_99 + ( V_99 >> 1 ) ;
V_99 = ( V_99 << 16 ) + V_99 + ( V_99 * 46 / 94 ) ;
V_99 = 0x00010001 + ( ( V_99 & 0x0000FFFF ) - ( V_99 >> 16 ) ) ;
V_100 = 0x00010001 + ( ( V_100 & 0x0000FFFF ) - ( V_100 >> 16 ) ) ;
if ( ( V_99 != 0x00010001 ) && ( V_15 -> V_110 / 2 <= V_15 -> V_28 ) )
V_99 = ( V_99 & 0xFFFF0000 ) + ( ( V_99 & 0x0000FFFF ) / 2 ) ;
if ( ! V_15 -> V_112 )
V_99 -= 0x00010001 ;
if ( ! V_15 -> V_113 )
V_100 -= 0x00010001 ;
V_99 += ( ( V_107 << 16 ) | V_107 ) ;
V_100 += ( ( V_108 << 16 ) | V_108 ) ;
if ( V_15 -> V_28 == V_15 -> V_110 ) {
V_57 = 0 ;
V_58 = 1 ;
} else {
V_57 = ( ( V_15 -> V_28 << 16 ) / V_15 -> V_110 ) >> 15 ;
V_57 = ( V_57 >> 1 ) + ( V_57 & 1 ) ;
V_57 += ! V_57 ;
V_58 = V_57 ;
}
F_17 ( V_89 , 0x02934 ) ;
F_17 ( V_90 , 0x0293c ) ;
F_18 ( L_25 ,
V_10 -> V_89 , V_89 , V_10 -> V_90 , V_90 ) ;
F_17 ( V_92 , 0x02944 ) ;
F_17 ( V_93 , 0x0294c ) ;
F_18 ( L_26 ,
V_10 -> V_92 , V_92 , V_10 -> V_93 , V_93 ) ;
F_17 ( V_88 , 0x02938 ) ;
F_17 ( V_88 , 0x02930 ) ;
F_18 ( L_27 ,
V_10 -> V_88 , V_88 , V_10 -> V_116 , V_88 ) ;
F_17 ( V_87 , 0x02928 ) ;
F_17 ( V_87 + 0x514 , 0x0292C ) ;
F_18 ( L_28 ,
V_10 -> V_87 , V_87 , V_10 -> V_117 , V_87 + 0x514 ) ;
F_17 ( V_86 , 0x02920 ) ;
F_17 ( V_86 + 0x514 , 0x02924 ) ;
F_18 ( L_29 ,
V_10 -> V_86 , V_86 , V_10 -> V_118 , V_86 + 0x514 ) ;
F_17 ( V_84 , 0x02918 ) ;
F_17 ( V_85 , 0x0291C ) ;
F_18 ( L_30 ,
V_10 -> V_84 , V_84 , V_10 -> V_85 , V_85 ) ;
F_17 ( V_101 , 0x0296c ) ;
F_18 ( L_31 ,
V_10 -> V_101 , V_101 ) ;
F_17 ( V_91 , 0x02948 ) ;
F_17 ( V_91 , 0x02940 ) ;
F_18 ( L_32 ,
V_10 -> V_91 , V_91 , V_10 -> V_119 , V_91 ) ;
F_17 ( V_94 , 0x02950 ) ;
F_17 ( V_95 , 0x02954 ) ;
F_18 ( L_33 ,
V_10 -> V_94 , V_94 , V_10 -> V_95 , V_95 ) ;
F_17 ( V_96 , 0x02958 ) ;
F_17 ( V_97 , 0x0295C ) ;
F_18 ( L_34 ,
V_10 -> V_96 , V_96 , V_10 -> V_97 , V_97 ) ;
F_17 ( V_98 , 0x02960 ) ;
F_18 ( L_35 ,
V_10 -> V_98 , V_98 ) ;
F_17 ( V_99 , 0x02964 ) ;
F_17 ( V_100 , 0x02968 ) ;
F_18 ( L_36 ,
V_10 -> V_99 , V_99 , V_10 -> V_100 , V_100 ) ;
F_17 ( V_102 , 0x0289c ) ;
F_18 ( L_37 ,
V_10 -> V_102 , V_102 ) ;
if ( V_57 != V_10 -> V_57 ) {
F_16 ( V_2 , - 1 , V_57 , - 1 ) ;
V_10 -> V_57 = V_57 ;
}
if ( V_58 != V_10 -> V_58 ) {
F_16 ( V_2 , - 1 , - 1 , V_58 ) ;
V_10 -> V_58 = V_58 ;
}
}
static T_2 F_21 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_14 * V_120 = & V_2 -> V_11 . V_121 ;
int V_122 ;
T_2 V_123 ;
T_2 V_124 = 0 ;
if ( V_15 -> V_76 < 0 )
V_15 -> V_76 = 0 ;
if ( V_15 -> V_29 < 0 )
V_15 -> V_29 = 0 ;
if ( ( V_122 = V_15 -> V_74 - 4 * V_15 -> V_75 ) > 0 ) {
V_15 -> V_76 += V_122 / 2 ;
V_15 -> V_74 = ( V_15 -> V_74 - V_122 ) & ~ 3 ;
V_15 -> V_75 = V_15 -> V_74 / 4 ;
V_15 -> V_75 += V_15 -> V_75 & 1 ;
}
if ( V_15 -> V_28 / V_15 -> V_110 >= 2 ) {
V_15 -> V_112 = 1 ;
if ( ( V_122 = V_15 -> V_28 - 4 * V_15 -> V_110 ) > 0 ) {
V_15 -> V_29 += V_122 / 2 ;
V_15 -> V_28 = ( V_15 -> V_28 - V_122 ) & ~ 3 ;
V_15 -> V_110 = V_15 -> V_28 / 4 ;
V_15 -> V_110 += V_15 -> V_110 & 1 ;
}
}
if ( ( int ) V_15 -> V_75 <= 2 || ( int ) V_15 -> V_110 <= 2 ||
( int ) V_15 -> V_74 <= 2 || ( int ) V_15 -> V_28 <= 2 ) {
return V_125 ;
}
V_123 = ( V_15 -> V_28 << 16 ) / V_15 -> V_110 ;
if ( ( V_122 = V_15 -> V_126 - V_15 -> V_111 ) > 0 ) {
V_15 -> V_29 += ( V_123 * V_122 ) >> 16 ;
V_15 -> V_28 -= ( V_123 * V_122 ) >> 16 ;
V_15 -> V_110 -= V_122 ;
V_15 -> V_111 = 0 ;
} else {
V_15 -> V_111 -= V_15 -> V_126 ;
}
if ( ( V_122 = V_15 -> V_110 + V_15 -> V_111 - V_15 -> V_127 ) > 0 ) {
V_15 -> V_110 -= V_122 ;
V_15 -> V_28 -= ( V_123 * V_122 ) >> 16 ;
}
V_123 = ( V_15 -> V_74 << 16 ) / V_15 -> V_75 ;
if ( ( V_122 = V_15 -> V_80 - V_15 -> V_77 ) > 0 ) {
V_15 -> V_76 += ( V_123 * V_122 ) >> 16 ;
V_15 -> V_74 -= ( V_123 * V_122 ) >> 16 ;
V_15 -> V_75 -= V_122 ;
V_15 -> V_77 = 0 ;
} else {
V_15 -> V_77 -= V_15 -> V_80 ;
}
if ( ( V_122 = V_15 -> V_75 + V_15 -> V_77 - V_15 -> V_78 ) > 0 ) {
V_15 -> V_75 -= V_122 ;
V_15 -> V_74 -= ( V_123 * V_122 ) >> 16 ;
}
if ( V_2 -> V_11 . V_128 ) {
V_15 -> V_77 += V_2 -> V_11 . V_129 ;
V_15 -> V_111 += V_2 -> V_11 . V_130 ;
}
V_15 -> V_75 &= ~ 1 ;
V_15 -> V_77 &= ~ 1 ;
V_15 -> V_74 += V_15 -> V_76 & 1 ;
V_15 -> V_76 &= ~ 1 ;
V_15 -> V_74 &= ~ 1 ;
V_15 -> V_75 &= ~ 1 ;
V_15 -> V_110 &= ~ 1 ;
V_15 -> V_111 &= ~ 1 ;
V_15 -> V_28 += V_15 -> V_29 & 1 ;
V_15 -> V_29 &= ~ 1 ;
V_15 -> V_28 &= ~ 1 ;
V_15 -> V_110 &= ~ 1 ;
if ( V_15 -> V_75 < V_15 -> V_74 / 4 ) {
V_15 -> V_74 &= ~ 3 ;
V_15 -> V_75 = V_15 -> V_74 / 4 ;
V_15 -> V_75 += V_15 -> V_75 & 1 ;
}
if ( V_15 -> V_110 < V_15 -> V_28 / 4 ) {
V_15 -> V_28 &= ~ 3 ;
V_15 -> V_110 = V_15 -> V_28 / 4 ;
V_15 -> V_110 += V_15 -> V_110 & 1 ;
}
if ( ( int ) V_15 -> V_75 <= 2 || ( int ) V_15 -> V_110 <= 2 ||
( int ) V_15 -> V_74 <= 2 || ( int ) V_15 -> V_28 <= 2 ) {
return V_125 ;
}
if ( ( V_120 -> V_75 != V_15 -> V_75 ) || ( V_120 -> V_74 != V_15 -> V_74 ) ||
( V_120 -> V_77 != V_15 -> V_77 ) || ( V_120 -> V_76 != V_15 -> V_76 ) ||
( V_120 -> V_80 != V_15 -> V_80 ) || ( V_120 -> V_78 != V_15 -> V_78 ) ) {
V_124 |= V_131 ;
}
if ( ( V_120 -> V_28 != V_15 -> V_28 ) || ( V_120 -> V_110 != V_15 -> V_110 ) ||
( V_120 -> V_111 != V_15 -> V_111 ) || ( V_120 -> V_29 != V_15 -> V_29 ) ||
( V_120 -> V_126 != V_15 -> V_126 ) || ( V_120 -> V_127 != V_15 -> V_127 ) ||
( V_120 -> V_132 != V_15 -> V_132 ) ||
( V_120 -> V_112 != V_15 -> V_112 ) ||
( V_120 -> V_113 != V_15 -> V_113 ) ) {
V_124 |= V_133 ;
}
return V_124 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
struct V_14 V_15 ;
int V_12 = V_10 -> V_134 ;
T_2 V_124 ;
F_18 ( L_38 , V_12 ) ;
V_15 = V_10 -> V_16 [ V_12 ] ;
if ( V_10 -> V_128 ) {
V_15 . V_80 = V_10 -> V_135 ;
V_15 . V_126 = V_10 -> V_136 ;
V_15 . V_78 = V_10 -> V_137 ;
V_15 . V_127 = V_10 -> V_138 ;
} else {
V_15 . V_80 = 0 ;
V_15 . V_126 = 0 ;
V_15 . V_78 = 720 ;
V_15 . V_127 = V_10 -> V_115 ;
}
if ( ! ( V_124 = F_21 ( V_2 , & V_15 ) ) )
return;
if ( V_124 & V_125 ) {
F_17 ( 0x01008080 , 0x2898 ) ;
} else if ( V_124 ) {
F_17 ( 0x00108080 , 0x2898 ) ;
if ( V_124 & V_131 )
F_19 ( V_2 , & V_15 ) ;
if ( V_124 & V_133 )
F_20 ( V_2 , & V_15 ) ;
}
V_10 -> V_121 = V_15 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
F_18 ( L_39 ) ;
V_10 -> V_59 = F_24 ( 0x02834 ) ;
V_10 -> V_60 = F_24 ( 0x02838 ) ;
V_10 -> V_61 = F_24 ( 0x0283c ) ;
V_10 -> V_81 = F_24 ( 0x02840 ) ;
V_10 -> V_62 = F_24 ( 0x02844 ) ;
V_10 -> V_82 = F_24 ( 0x02848 ) ;
V_10 -> V_63 = F_24 ( 0x02854 ) ;
V_10 -> V_64 = F_24 ( 0x0285c ) ;
V_10 -> V_65 = F_24 ( 0x02864 ) ;
V_10 -> V_68 = F_24 ( 0x02870 ) ;
V_10 -> V_66 = F_24 ( 0x02874 ) ;
V_10 -> V_139 = F_24 ( 0x02898 ) ;
V_10 -> V_67 = F_24 ( 0x02890 ) ;
V_10 -> V_102 = F_24 ( 0x0289c ) ;
V_10 -> V_84 = F_24 ( 0x02918 ) ;
V_10 -> V_85 = F_24 ( 0x0291c ) ;
V_10 -> V_86 = F_24 ( 0x02920 ) ;
V_10 -> V_118 = F_24 ( 0x02924 ) ;
V_10 -> V_87 = F_24 ( 0x02928 ) ;
V_10 -> V_117 = F_24 ( 0x0292c ) ;
V_10 -> V_88 = F_24 ( 0x02930 ) ;
V_10 -> V_89 = F_24 ( 0x02934 ) ;
V_10 -> V_116 = F_24 ( 0x02938 ) ;
V_10 -> V_90 = F_24 ( 0x0293c ) ;
V_10 -> V_91 = F_24 ( 0x02940 ) ;
V_10 -> V_92 = F_24 ( 0x02944 ) ;
V_10 -> V_119 = F_24 ( 0x02948 ) ;
V_10 -> V_93 = F_24 ( 0x0294c ) ;
V_10 -> V_94 = F_24 ( 0x02950 ) ;
V_10 -> V_95 = F_24 ( 0x02954 ) ;
V_10 -> V_96 = F_24 ( 0x02958 ) ;
V_10 -> V_97 = F_24 ( 0x0295c ) ;
V_10 -> V_98 = F_24 ( 0x02960 ) ;
V_10 -> V_99 = F_24 ( 0x02964 ) ;
V_10 -> V_100 = F_24 ( 0x02968 ) ;
V_10 -> V_101 = F_24 ( 0x0296c ) ;
V_10 -> V_140 = F_24 ( 0x02970 ) ;
V_10 -> V_57 = - 1 ;
V_10 -> V_58 = - 1 ;
V_10 -> V_56 = - 1 ;
V_10 -> V_129 = F_24 ( 0x02a04 ) & 0x00000FFF ;
V_10 -> V_130 = ( F_24 ( 0x02a04 ) >> 16 ) & 0x00000FFF ;
if ( F_24 ( 0x2878 ) & 4 )
V_10 -> V_115 = 576 ;
else
V_10 -> V_115 = 480 ;
if ( ! V_2 -> V_141 ) {
V_10 -> V_137 = 720 - V_10 -> V_129 ;
V_10 -> V_138 = V_10 -> V_115 - V_10 -> V_130 ;
} else {
if ( ! V_10 -> V_137 )
V_10 -> V_137 = 720 - V_10 -> V_129 ;
if ( ! V_10 -> V_138 ) {
V_10 -> V_138 = V_10 -> V_115 - V_10 -> V_130 ;
} else if ( V_10 -> V_138 + V_10 -> V_130 > V_10 -> V_115 ) {
F_2 ( L_40 ,
V_10 -> V_138 + V_10 -> V_130 ,
V_10 -> V_115 ) ;
V_10 -> V_138 = V_10 -> V_115 - V_10 -> V_130 ;
}
}
V_10 -> V_142 = F_25 ( 720 * 16 , V_143 | V_144 ) ;
if ( V_10 -> V_142 ) {
V_10 -> V_47 = F_26 ( V_2 -> V_44 , V_10 -> V_142 , 720 * 16 , V_46 ) ;
} else {
V_10 -> V_47 = 0 ;
F_2 ( L_41 ) ;
}
F_27 ( 0x01 , V_145 ) ;
F_28 ( V_146 , & V_2 -> V_147 ) ;
F_29 ( & V_10 -> V_148 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
int V_149 , V_150 ;
struct V_9 * V_10 = & V_2 -> V_11 ;
if ( F_31 ( & V_10 -> V_148 ) == - 1 )
F_23 ( V_2 ) ;
V_149 = F_31 ( & V_10 -> V_151 ) ;
V_150 = F_31 ( & V_10 -> V_148 ) ;
if ( V_150 > V_149 )
V_150 -= V_152 ;
if ( V_149 - V_150 >= V_10 -> V_153 )
V_149 = ( T_1 ) ( V_149 - 1 ) % V_152 ;
else
V_10 -> V_16 [ V_149 ] . V_154 = 0 ;
V_10 -> V_13 = V_149 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_5 * args )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
T_1 V_12 = V_10 -> V_13 ;
T_1 V_155 = ( T_1 ) ( V_12 - 1 ) % V_152 ;
struct V_14 * V_156 = & V_10 -> V_16 [ V_12 ] ;
struct V_14 * V_120 = & V_10 -> V_16 [ V_155 ] ;
int V_157 = V_10 -> V_157 ;
int V_154 = V_156 -> V_154 ;
V_156 -> V_76 = args -> V_50 . V_158 ;
V_156 -> V_29 = args -> V_50 . V_159 ;
V_156 -> V_74 = args -> V_50 . V_160 ;
V_156 -> V_28 = args -> V_50 . V_161 ;
V_156 -> V_77 = args -> V_51 . V_158 ;
V_156 -> V_111 = args -> V_51 . V_159 ;
V_156 -> V_75 = args -> V_51 . V_160 ;
V_156 -> V_110 = args -> V_51 . V_161 ;
V_156 -> V_79 = args -> V_51 . V_158 ;
V_156 -> V_73 = args -> V_162 ;
V_156 -> V_109 = args -> V_163 ;
V_156 -> V_30 = ( V_156 -> V_109 + V_156 -> V_76 < 512 - 16 ) ? 1 : 0 ;
V_156 -> V_154 = 0 ;
V_156 -> V_112 = 0 ;
V_156 -> V_113 = 0 ;
V_156 -> V_164 = 0 ;
V_156 -> V_165 = 0 ;
V_156 -> V_132 = V_10 -> V_132 & V_166 ;
if ( V_157 < 0 )
V_157 = V_10 -> V_115 - 1 ;
switch ( V_156 -> V_132 ) {
case V_167 :
V_156 -> V_114 = 0 ;
if ( V_156 -> V_109 < 512 || ( V_156 -> V_109 > 576 && V_156 -> V_109 < 1021 ) )
V_156 -> V_112 = 0 ;
else
V_156 -> V_112 = 1 ;
if ( V_156 -> V_109 < 1021 && ( V_156 -> V_110 >= V_156 -> V_28 / 2 ) )
V_156 -> V_113 = 0 ;
else
V_156 -> V_113 = 1 ;
break;
case V_168 :
if ( V_156 -> V_109 <= V_157 || V_156 -> V_109 > 576 || V_156 -> V_73 > 720 ) {
V_156 -> V_114 = 0 ;
if ( ( V_156 -> V_109 < 512 ) ||
( V_156 -> V_109 > 576 && V_156 -> V_109 < 1021 ) ||
( V_156 -> V_73 > 720 && V_156 -> V_109 < 1021 ) )
V_156 -> V_112 = 0 ;
else
V_156 -> V_112 = 1 ;
if ( V_156 -> V_109 < 1021 && ( V_156 -> V_110 >= V_156 -> V_28 / 2 ) )
V_156 -> V_113 = 0 ;
else
V_156 -> V_113 = 1 ;
} else {
V_156 -> V_114 = 1 ;
V_156 -> V_112 = 1 ;
V_156 -> V_113 = 1 ;
}
break;
case V_169 :
default:
V_156 -> V_114 = 1 ;
V_156 -> V_112 = 1 ;
V_156 -> V_113 = 1 ;
break;
}
if ( memcmp ( & V_10 -> V_170 , V_156 , sizeof( * V_156 ) ) ) {
V_10 -> V_170 = * V_156 ;
V_156 -> V_154 = 1 ;
F_18 ( L_42 , V_12 ) ;
}
V_156 -> V_154 |= V_154 ;
V_156 -> V_165 = V_10 -> V_171 ;
V_156 -> V_164 = V_156 -> V_165 != V_120 -> V_165 ;
}
void F_33 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_11 . V_151 ,
( V_2 -> V_11 . V_13 + 1 ) % V_152 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_5 * args )
{
F_35 ( V_172 ) ;
int V_41 = 0 ;
int V_173 = 0 ;
F_36 ( & V_2 -> V_174 . V_175 ) ;
if ( ( V_41 = F_1 ( V_2 , & V_2 -> V_174 , args ) ) != 0 ) {
F_37 ( & V_2 -> V_174 . V_175 ) ;
return V_41 ;
}
F_38 ( V_2 ) ;
F_39 ( & V_2 -> V_176 , & V_172 , V_177 ) ;
while ( F_40 ( V_178 , & V_2 -> V_147 ) ||
F_40 ( V_179 , & V_2 -> V_147 ) ) {
V_173 = F_41 ( V_36 ) ;
if ( V_173 && F_42 ( V_178 , & V_2 -> V_147 ) )
break;
V_173 = 0 ;
F_43 () ;
}
F_44 ( & V_2 -> V_176 , & V_172 ) ;
F_45 ( V_2 ) ;
if ( V_173 ) {
F_46 ( L_43 ) ;
F_37 ( & V_2 -> V_174 . V_175 ) ;
return - V_180 ;
}
F_33 ( V_2 ) ;
F_37 ( & V_2 -> V_174 . V_175 ) ;
return V_41 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
struct V_5 V_181 ;
F_30 ( V_2 ) ;
V_181 . V_34 = NULL ;
V_181 . V_35 = NULL ;
V_181 . V_50 . V_158 = 0 ;
V_181 . V_50 . V_159 = 0 ;
V_181 . V_50 . V_160 = V_10 -> V_182 ;
V_181 . V_50 . V_161 = V_10 -> V_183 ;
V_181 . V_51 = V_10 -> V_184 ;
V_181 . V_162 = V_10 -> V_182 ;
V_181 . V_163 = V_10 -> V_183 ;
F_32 ( V_2 , & V_181 ) ;
if ( ! V_2 -> V_185 )
V_2 -> V_185 = V_26 [ V_10 -> V_13 ] ;
}
int F_48 ( struct V_1 * V_2 , void T_3 * V_50 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
struct V_5 V_181 ;
F_47 ( V_2 ) ;
V_181 . V_34 = V_50 ;
V_181 . V_35 = V_50 + 720 * ( ( V_10 -> V_183 + 31 ) & ~ 31 ) ;
return F_34 ( V_2 , & V_181 ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_5 * args )
{
F_30 ( V_2 ) ;
F_32 ( V_2 , args ) ;
return F_34 ( V_2 , args ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 ;
int V_56 , V_57 , V_58 ;
F_18 ( L_44 ) ;
F_51 ( & V_2 -> V_186 ) ;
V_10 -> V_187 = 0 ;
F_29 ( & V_10 -> V_148 , - 1 ) ;
F_29 ( & V_10 -> V_151 , 0 ) ;
F_17 ( V_10 -> V_139 | 0x01000000 , 0x2898 ) ;
F_17 ( V_10 -> V_59 , 0x02834 ) ;
F_17 ( V_10 -> V_60 , 0x02838 ) ;
F_17 ( V_10 -> V_61 , 0x0283c ) ;
F_17 ( V_10 -> V_81 , 0x02840 ) ;
F_17 ( V_10 -> V_62 , 0x02844 ) ;
F_17 ( V_10 -> V_82 , 0x02848 ) ;
F_17 ( V_10 -> V_63 , 0x02854 ) ;
F_17 ( V_10 -> V_64 , 0x0285c ) ;
F_17 ( V_10 -> V_65 , 0x02864 ) ;
F_17 ( V_10 -> V_68 , 0x02870 ) ;
F_17 ( V_10 -> V_66 , 0x02874 ) ;
F_17 ( V_10 -> V_67 , 0x02890 ) ;
F_17 ( V_10 -> V_102 , 0x0289c ) ;
F_17 ( V_10 -> V_84 , 0x02918 ) ;
F_17 ( V_10 -> V_85 , 0x0291c ) ;
F_17 ( V_10 -> V_86 , 0x02920 ) ;
F_17 ( V_10 -> V_118 , 0x02924 ) ;
F_17 ( V_10 -> V_87 , 0x02928 ) ;
F_17 ( V_10 -> V_117 , 0x0292c ) ;
F_17 ( V_10 -> V_88 , 0x02930 ) ;
F_17 ( V_10 -> V_89 , 0x02934 ) ;
F_17 ( V_10 -> V_116 , 0x02938 ) ;
F_17 ( V_10 -> V_90 , 0x0293c ) ;
F_17 ( V_10 -> V_91 , 0x02940 ) ;
F_17 ( V_10 -> V_92 , 0x02944 ) ;
F_17 ( V_10 -> V_119 , 0x02948 ) ;
F_17 ( V_10 -> V_93 , 0x0294c ) ;
F_17 ( V_10 -> V_94 , 0x02950 ) ;
F_17 ( V_10 -> V_95 , 0x02954 ) ;
F_17 ( V_10 -> V_96 , 0x02958 ) ;
F_17 ( V_10 -> V_97 , 0x0295c ) ;
F_17 ( V_10 -> V_98 , 0x02960 ) ;
F_17 ( V_10 -> V_99 , 0x02964 ) ;
F_17 ( V_10 -> V_100 , 0x02968 ) ;
F_17 ( V_10 -> V_101 , 0x0296c ) ;
F_17 ( V_10 -> V_140 , 0x02970 ) ;
if ( ( V_10 -> V_59 & 0x0000FFFF ) == ( V_10 -> V_59 >> 16 ) ) {
V_56 = 0 ;
} else {
V_56 = ( ( V_10 -> V_59 << 16 ) / ( V_10 -> V_59 >> 16 ) ) >> 15 ;
V_56 = ( V_56 >> 1 ) + ( V_56 & 1 ) ;
V_56 += ! V_56 ;
}
if ( ( V_10 -> V_84 & 0x0000FFFF ) == ( V_10 -> V_84 >> 16 ) ) {
V_57 = 0 ;
V_58 = 1 ;
} else {
V_57 = ( ( V_10 -> V_84 << 16 ) / ( V_10 -> V_84 >> 16 ) ) >> 15 ;
V_57 = ( V_57 >> 1 ) + ( V_57 & 1 ) ;
V_57 += ! V_57 ;
V_58 = V_57 ;
}
F_16 ( V_2 , V_56 , V_57 , V_58 ) ;
F_17 ( 0 , 0x02814 ) ;
F_17 ( 0 , 0x0282c ) ;
F_17 ( 0 , 0x02904 ) ;
F_17 ( 0 , 0x02910 ) ;
if ( V_10 -> V_142 ) {
F_52 ( V_10 -> V_142 ) ;
V_10 -> V_142 = NULL ;
F_53 ( V_2 -> V_44 , V_10 -> V_47 , 720 * 16 , V_46 ) ;
}
V_10 -> V_121 . V_74 = 0 ;
V_10 -> V_121 . V_28 = 0 ;
V_10 -> V_170 . V_74 = 0 ;
V_10 -> V_170 . V_28 = 0 ;
F_54 ( V_146 , & V_2 -> V_147 ) ;
}
