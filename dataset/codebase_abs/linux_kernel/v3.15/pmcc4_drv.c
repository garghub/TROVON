void
F_1 ( int V_1 )
{
if ( V_1 > V_2 )
{
unsigned int V_3 = V_1 - ( V_2 + 1 ) ;
( void ) F_2 ( ( V_4 * ) V_5 , V_3 ) ;
} else
{
if ( V_6 != V_1 )
{
F_3 ( L_1 , V_6 , V_1 ) ;
V_6 = V_1 ;
} else
F_3 ( L_2 , V_6 ) ;
}
}
T_1 *
F_4 ( int V_3 )
{
V_4 * V_7 ;
T_1 * V_8 ;
int V_9 , V_10 ;
for ( V_7 = V_11 ; V_7 ; V_7 = V_7 -> V_12 )
for ( V_9 = 0 ; V_9 < V_7 -> V_13 ; V_9 ++ )
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )
{
V_8 = V_7 -> V_15 [ V_9 ] . V_16 [ V_10 ] ;
if ( V_8 ) {
if ( ( V_8 -> V_17 != V_18 ) &&
( V_8 -> V_3 == V_3 ) )
return V_8 ;
}
}
return NULL ;
}
V_4 * T_2
F_5 ( void * V_19 )
{
V_4 * V_7 ;
#ifdef F_6
F_7 ( L_3 ,
( unsigned int ) sizeof ( V_4 ) ) ;
#endif
V_7 = ( V_4 * ) F_8 ( sizeof ( V_4 ) ) ;
if ( V_7 )
{
V_7 -> V_20 = V_19 ;
V_7 -> V_17 = V_21 ;
V_7 -> V_12 = V_11 ;
V_11 = V_7 ;
V_7 -> V_22 = V_7 -> V_12 ? V_7 -> V_12 -> V_22 + 1 : 0 ;
} else
F_7 ( L_4 ,
( unsigned int ) sizeof ( V_4 ) ) ;
if ( ! V_5 )
V_5 = V_7 ;
return V_7 ;
}
void
F_9 ( V_4 * V_7 )
{
#ifndef F_10
struct V_23 * V_24 ;
volatile T_3 V_25 ;
T_3 V_26 , V_27 ;
T_4 V_9 ;
V_27 = 0 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_13 ; V_9 ++ )
{
V_26 = 0x12f & ( V_7 -> V_28 [ V_9 ] ) ;
V_24 = V_7 -> V_15 [ V_9 ] . V_29 ;
V_25 = F_11 ( ( T_3 * ) & V_24 -> V_30 ) & V_31 ;
if ( V_25 & V_32 )
{
if ( ! ( ( ( V_26 >> 3 ) & V_33 ) ^ ( V_25 & V_33 ) ) )
{
if ( V_25 & V_33 )
F_7 ( L_5 ,
V_7 -> V_34 , V_9 ) ;
else
F_7 ( L_6 ,
V_7 -> V_34 , V_9 ) ;
} else if ( V_25 & V_33 )
F_7 ( L_7 ,
V_7 -> V_34 , V_9 ) ;
else
{
F_7 ( L_8 ,
V_7 -> V_34 , V_9 ) ;
V_26 |= 0x20 ;
}
V_26 |= 0x10 ;
}
V_26 &= 0x137 ;
if ( V_25 & V_33 )
V_26 |= 0x08 ;
else
{
V_26 |= 0x40 ;
if ( F_12 ( V_7 -> V_15 [ V_9 ] . V_35 . V_36 ) )
{
V_25 = F_11 ( ( T_3 * ) & V_24 -> V_37 ) ;
if ( V_25 & 0x1f )
{
if ( V_25 & 0x10 )
F_7 ( L_9 ,
V_7 -> V_34 , V_9 ) ;
if ( V_25 & 0x08 )
F_7 ( L_10 ,
V_7 -> V_34 , V_9 ) ;
if ( V_25 & 0x04 )
F_7 ( L_11 ,
V_7 -> V_34 , V_9 ) ;
if ( V_25 & 0x02 )
F_7 ( L_12 ,
V_7 -> V_34 , V_9 ) ;
if ( V_25 & 0x01 )
F_7 ( L_13 ,
V_7 -> V_34 , V_9 ) ;
}
V_25 = F_11 ( ( T_3 * ) & V_24 -> V_38 ) ;
if ( V_25 & 0x3 )
{
if ( V_25 & V_39 )
F_7 ( L_14 ,
V_7 -> V_34 , V_9 ) ;
if ( V_25 & V_40 )
F_7 ( L_15 ,
V_7 -> V_34 , V_9 ) ;
}
V_25 = F_11 ( ( T_3 * ) & V_24 -> V_41 ) & 0xcc ;
V_25 = ( V_25 >> 2 ) ;
if ( V_25 & 0x30 )
{
if ( V_25 & 0x20 )
V_25 |= 0x40 ;
if ( V_25 & 0x10 )
V_25 |= 0x100 ;
V_25 &= ~ 0x30 ;
}
if ( V_25 != ( V_26 & V_42 ) )
{
V_26 |= 0x10 ;
if ( ( V_26 & V_43 ) && ! ( V_25 & V_43 ) )
{
V_26 &= ~ V_43 ;
F_7 ( L_16 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ! ( V_26 & V_43 ) && ( V_25 & V_43 ) )
{
V_26 |= V_43 ;
F_7 ( L_17 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ( V_26 & V_44 ) && ! ( V_25 & V_44 ) )
{
V_26 &= ~ V_44 ;
F_7 ( L_18 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ! ( V_26 & V_44 ) && ( V_25 & V_44 ) )
{
V_26 |= V_44 ;
F_7 ( L_19 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ( V_26 & V_45 ) && ! ( V_25 & V_45 ) )
{
V_26 &= ~ V_45 ;
F_7 ( L_20 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ! ( V_26 & V_45 ) && ( V_25 & V_45 ) )
{
V_26 |= V_45 ;
F_7 ( L_21 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ( V_26 & V_46 ) && ! ( V_25 & V_46 ) )
{
V_26 &= ~ V_46 ;
F_7 ( L_22 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ! ( V_26 & V_46 ) && ( V_25 & V_46 ) )
{
V_26 |= V_46 ;
F_7 ( L_23 ,
V_7 -> V_34 , V_9 ) ;
}
}
} else
{
V_25 = F_11 ( ( T_3 * ) & V_24 -> V_47 ) ;
V_25 &= V_48 ;
if ( V_25 != ( V_26 & V_48 ) )
{
V_26 |= 0x10 ;
if ( ( V_26 & V_43 ) && ! ( V_25 & V_43 ) )
{
V_26 &= ~ V_43 ;
F_7 ( L_24 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ! ( V_26 & V_43 ) && ( V_25 & V_43 ) )
{
V_26 |= V_43 ;
F_7 ( L_25 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ( V_26 & V_44 ) && ! ( V_25 & V_44 ) )
{
V_26 &= ~ V_44 ;
F_7 ( L_26 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ! ( V_26 & V_44 ) && ( V_25 & V_44 ) )
{
V_26 |= V_44 ;
F_7 ( L_27 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ( V_26 & V_46 ) && ! ( V_25 & V_46 ) )
{
V_26 &= ~ V_46 ;
F_7 ( L_28 ,
V_7 -> V_34 , V_9 ) ;
} else if ( ! ( V_26 & V_46 ) && ( V_25 & V_46 ) )
{
V_26 |= V_46 ;
F_7 ( L_29 ,
V_7 -> V_34 , V_9 ) ;
}
}
}
}
if ( V_26 & V_48 )
V_26 |= 0x80 ;
if ( V_26 & 0x10 )
V_27 |= 0x100 ;
V_27 |= ( ( V_26 & 0xc0 ) >> ( 6 - ( V_9 * 2 ) ) ) ;
V_7 -> V_28 [ V_9 ] &= 0xfffff000 ;
V_7 -> V_28 [ V_9 ] |= ( V_26 ) ;
if ( F_13 ( V_7 -> V_15 [ V_9 ] . V_35 . V_36 ) )
{
V_25 = F_11 ( ( T_3 * ) & V_24 -> V_49 ) ;
V_25 &= 0x3 ;
if ( V_25 & 0x2 )
{
V_26 = F_14 ( V_7 , V_9 , V_50 ) ;
if ( V_26 != V_51 )
F_14 ( V_7 , V_9 , V_51 ) ;
}
if ( V_25 & 0x1 )
{
V_26 = F_14 ( V_7 , V_9 , V_50 ) ;
if ( V_26 != V_52 )
F_14 ( V_7 , V_9 , V_52 ) ;
}
}
if ( F_15 ( V_7 -> V_15 [ V_9 ] . V_35 . V_36 ) )
{
V_25 = F_11 ( ( T_3 * ) & V_24 -> V_53 ) & 0x3f ;
if ( V_25 == 0x07 )
F_14 ( V_7 , V_9 , V_51 ) ;
if ( V_25 == 0x0a )
F_14 ( V_7 , V_9 , V_54 ) ;
if ( ( V_25 == 0x1c ) || ( V_25 == 0x19 ) || ( V_25 == 0x12 ) )
F_14 ( V_7 , V_9 , V_52 ) ;
if ( V_6 >= V_2 )
if ( V_25 != 0x3f )
F_7 ( L_30 ,
V_7 -> V_34 , V_25 , V_9 ) ;
}
}
if ( V_27 & 0x100 )
F_16 ( ( T_3 * ) & V_7 -> V_55 -> V_56 , V_27 & 0xff ) ;
#endif
}
static void
F_17 ( V_4 * V_7 )
{
if ( V_57 != V_58 )
{
if ( V_6 >= V_59 )
F_3 ( L_31 , V_57 ) ;
return;
}
V_7 -> V_60 ++ ;
F_9 ( V_7 ) ;
V_7 -> V_61 = 0 ;
}
void
F_18 ( void )
{
V_4 * V_7 , * V_12 ;
T_5 * V_62 ;
int V_9 , V_63 ;
V_7 = V_11 ;
while ( V_7 )
{
V_12 = V_7 -> V_12 ;
F_16 ( ( T_3 * ) & V_7 -> V_55 -> V_56 , V_64 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_13 ; V_9 ++ )
{
V_62 = & V_7 -> V_15 [ V_9 ] ;
F_19 ( V_62 ) ;
for ( V_63 = 0 ; V_63 < V_14 ; V_63 ++ )
{
if ( V_62 -> V_16 [ V_63 ] )
F_20 ( V_62 -> V_16 [ V_63 ] ) ;
}
F_20 ( V_62 -> V_65 ) ;
}
F_20 ( V_7 -> V_66 ) ;
F_20 ( V_7 ) ;
V_7 = V_12 ;
}
}
int
F_21 ( V_4 * V_7 )
{
struct V_23 * V_24 ;
int V_9 , V_67 ;
T_3 V_68 , V_69 ;
V_68 = V_52 ;
V_67 = 0 ;
for ( V_9 = 0 ; V_9 < V_70 ; V_9 ++ )
{
V_24 = V_7 -> V_15 [ V_9 ] . V_29 ;
F_16 ( ( T_3 * ) & V_24 -> V_71 , V_68 ) ;
V_69 = F_11 ( ( T_3 * ) & V_24 -> V_71 ) & V_72 ;
if ( V_68 == V_69 )
V_67 |= 1 << V_9 ;
}
return V_67 ;
}
T_6 T_2
F_22 ( V_4 * V_7 , T_7 * V_73 , T_7 * V_74 )
{
T_5 * V_62 ;
T_1 * V_8 ;
static T_3 V_75 = 0 ;
int V_9 , V_63 ;
V_7 -> V_17 = V_21 ;
V_7 -> V_22 = V_75 ++ ;
V_7 -> V_76 . V_77 = 0 ;
F_23 ( & V_7 -> V_78 , 0 ) ;
V_7 -> V_79 = (struct V_80 * ) V_73 ;
V_7 -> V_81 = ( T_3 * ) ( V_74 + V_82 ) ;
V_7 -> V_55 = ( V_83 * ) ( ( T_3 * ) ( V_74 + V_84 ) ) ;
#ifdef F_10
F_16 ( ( T_3 * ) & V_7 -> V_79 -> V_85 , V_86 ) ;
#else
F_16 ( ( T_3 * ) & V_7 -> V_79 -> V_85 , V_86 | V_87 ) ;
#endif
{
int V_88 ;
for ( V_9 = 0 ; V_9 < V_70 ; V_9 ++ )
{
V_62 = & V_7 -> V_15 [ V_9 ] ;
V_62 -> V_29 = (struct V_23 * ) ( ( T_3 * ) ( V_74 + F_24 ( V_9 ) ) ) ;
V_62 -> V_79 = (struct V_80 * ) ( ( T_7 * ) V_7 -> V_79 + ( V_9 * 0x800 ) ) ;
V_62 -> V_9 = V_9 ;
V_62 -> V_35 . V_9 = V_9 ;
V_62 -> V_89 = 0 ;
#ifdef F_6
F_3 ( L_32 , V_9 , V_62 -> V_29 ) ;
#endif
}
V_88 = F_21 ( V_7 ) ;
switch ( V_88 )
{
case 0x1 :
V_7 -> V_13 = 1 ;
break;
case 0x3 :
V_7 -> V_13 = 2 ;
break;
#if 0
case 0x7:
ci->max_port = 3;
break;
#endif
case 0xf :
V_7 -> V_13 = 4 ;
break;
default:
V_7 -> V_13 = 0 ;
F_7 ( L_33 ,
V_7 -> V_34 , V_88 ) ;
return V_90 ;
}
#ifdef F_6
F_3 ( L_34 ,
V_7 -> V_34 , V_88 , V_7 -> V_13 ) ;
#endif
}
for ( V_9 = 0 ; V_9 < V_7 -> V_13 ; V_9 ++ )
{
V_62 = & V_7 -> V_15 [ V_9 ] ;
V_62 -> V_91 = V_7 ;
V_62 -> V_92 = 0xffffffff ;
V_62 -> V_35 . V_36 = V_93 ;
V_62 -> V_35 . V_94 = ( V_95 | V_96 ) ;
F_25 ( & V_62 -> V_97 , V_98 ) ;
F_25 ( & V_62 -> V_99 , V_100 ) ;
for ( V_63 = 0 ; V_63 < 32 ; V_63 ++ )
{
V_62 -> V_101 [ V_63 ] = - 1 ;
V_62 -> V_102 [ V_63 ] = 0 ;
}
for ( V_63 = 0 ; V_63 < V_14 ; V_63 ++ )
{
V_8 = F_8 ( sizeof ( T_1 ) ) ;
if ( V_8 )
{
V_62 -> V_16 [ V_63 ] = V_8 ;
V_8 -> V_17 = V_18 ;
V_8 -> V_91 = V_62 ;
V_8 -> V_10 = ( - 1 ) ;
V_8 -> V_3 = ( - 1 ) ;
V_8 -> V_35 . V_103 = V_7 -> V_22 ;
V_8 -> V_35 . V_15 = V_9 ;
V_8 -> V_35 . V_3 = ( - 1 ) ;
V_8 -> V_35 . V_104 = 0 ;
} else
{
F_7 ( L_35 ,
V_9 , V_63 , ( unsigned int ) sizeof ( T_1 ) ) ;
break;
}
}
}
{
F_16 ( ( T_3 * ) & V_7 -> V_55 -> V_56 ,
V_105 | V_106 ) ;
F_26 ( 750000 , L_36 ) ;
F_16 ( ( T_3 * ) & V_7 -> V_55 -> V_56 , V_64 ) ;
}
F_27 ( & V_7 -> V_107 , ( void ( * ) ( void * ) ) F_17 , V_7 , V_108 ) ;
return V_109 ;
}
T_6 T_2
F_28 ( V_4 * V_7 )
{
T_6 V_110 ;
V_110 = F_29 ( V_7 ) ;
if ( V_110 != V_109 )
return V_110 ;
#if 0
ci->p.framing_type = FRAMING_CBP;
ci->p.h110enable = 1;
#if 0
ci->p.hypersize = 0;
#else
hyperdummy = 0;
#endif
ci->p.clock = 0;
c4_card_set_params (ci, &ci->p);
#endif
F_30 ( & V_7 -> V_107 ) ;
return V_109 ;
}
int
F_14 ( V_4 * V_7 , int V_9 , T_4 V_111 )
{
struct V_23 * V_24 ;
volatile T_3 V_112 ;
V_24 = V_7 -> V_15 [ V_9 ] . V_29 ;
V_112 = F_11 ( ( T_3 * ) & V_24 -> V_71 ) & V_72 ;
if ( V_111 & V_50 )
return V_112 ;
if ( V_112 != V_111 )
{
switch ( V_111 )
{
case V_51 :
F_16 ( ( T_3 * ) & V_24 -> V_113 , 0x05 ) ;
break;
case V_52 :
F_16 ( ( T_3 * ) & V_24 -> V_113 , 0x00 ) ;
break;
}
F_16 ( ( T_3 * ) & V_24 -> V_71 , V_111 ) ;
if ( V_6 >= V_114 )
F_3 ( L_37 ,
V_7 -> V_34 , V_111 , V_112 , V_9 ) ;
V_112 = F_11 ( ( T_3 * ) & V_24 -> V_71 ) & V_72 ;
if ( V_112 != V_111 )
{
if ( V_6 >= V_115 )
F_3 ( L_38 ,
V_7 -> V_34 , V_9 ) ;
}
} else
{
if ( V_6 >= V_114 )
F_3 ( L_39 ,
V_7 -> V_34 , V_112 ) ;
}
return 0 ;
}
T_6
F_31 ( V_4 * V_7 , struct V_116 * V_117 )
{
struct V_23 * V_24 ;
volatile T_3 V_118 ;
if ( V_117 -> V_9 >= V_7 -> V_13 )
return - V_119 ;
V_24 = V_7 -> V_15 [ V_117 -> V_9 ] . V_29 ;
V_118 = F_11 ( ( T_3 * ) V_24 + V_117 -> V_36 ) & 0xff ;
if ( V_117 -> V_94 )
{
if ( V_117 -> V_120 == V_118 )
F_3 ( L_40 ,
V_7 -> V_34 , V_117 -> V_9 ) ;
V_117 -> V_94 = ( T_4 ) V_118 ;
F_16 ( ( T_3 * ) V_24 + V_117 -> V_36 ,
V_117 -> V_120 ) ;
V_118 = F_11 ( ( T_3 * ) V_24 + V_117 -> V_36 ) & 0xff ;
}
V_117 -> V_120 = ( T_4 ) V_118 ;
return 0 ;
}
T_6
F_32 ( V_4 * V_7 , struct V_116 * V_117 )
{
volatile T_3 * V_121 ;
volatile T_3 V_118 ;
int V_122 = V_117 -> V_36 ;
V_121 = ( T_3 * ) V_7 -> V_55 + V_122 ;
V_118 = F_11 ( ( T_3 * ) V_121 ) & 0xff ;
if ( V_117 -> V_94 )
{
V_117 -> V_94 = ( T_4 ) V_118 ;
F_16 ( ( T_3 * ) V_121 , V_117 -> V_120 ) ;
V_118 = F_11 ( ( T_3 * ) V_121 ) & 0xff ;
}
V_117 -> V_120 = ( T_4 ) V_118 ;
return 0 ;
}
T_6
F_33 ( V_4 * V_7 , struct V_123 * V_124 )
{
T_5 * V_62 ;
volatile T_3 * V_125 ;
T_3 * V_126 = NULL ;
int V_127 = V_124 -> V_127 % 0x800 ;
int V_9 , V_128 = 0 ;
volatile T_3 V_118 ;
V_9 = ( V_124 -> V_127 % 0x6000 ) / 0x800 ;
if ( V_9 >= V_7 -> V_13 )
return - V_119 ;
V_62 = & V_7 -> V_15 [ V_9 ] ;
if ( V_124 -> V_127 >= 0x6000 )
V_127 += 0x6000 ;
V_125 = ( T_3 * ) ( ( V_129 ) V_62 -> V_79 + V_127 ) ;
V_126 = ( T_3 * ) ( ( V_129 ) V_62 -> V_130 + V_127 ) ;
if ( V_124 -> V_127 < 0x6000 )
{
if ( V_127 >= 0x200 && V_127 < 0x380 )
V_128 = 1 ;
if ( V_127 >= 0x10 && V_127 < 0x200 )
V_128 = 1 ;
}
if ( V_128 )
{
V_118 = * V_126 ;
} else
{
V_118 = F_11 ( ( T_3 * ) V_125 ) ;
}
if ( V_124 -> V_131 & 0x80 )
{
if ( V_124 -> V_25 == V_118 )
F_3 ( L_41 ,
V_7 -> V_34 , ( V_124 -> V_131 & 0x7 ) ) ;
if ( V_128 )
* V_126 = V_124 -> V_25 ;
F_16 ( ( T_3 * ) V_125 , V_124 -> V_25 ) ;
}
V_124 -> V_25 = V_118 ;
return 0 ;
}
T_6
F_34 ( V_4 * V_7 , int V_9 )
{
if ( V_9 >= V_7 -> V_13 )
return - V_119 ;
F_35 ( & V_7 -> V_132 , L_42 ) ;
F_9 ( V_7 ) ;
V_7 -> V_15 [ V_9 ] . V_35 . V_120 = ( T_4 ) V_7 -> V_28 [ V_9 ] ;
V_7 -> V_28 [ V_9 ] &= 0xdf ;
F_36 ( & V_7 -> V_132 ) ;
return 0 ;
}
T_6
F_37 ( V_4 * V_7 , int V_9 )
{
T_5 * V_62 ;
struct V_116 * V_117 ;
int V_133 ;
T_4 V_134 ;
int V_135 ;
if ( V_9 >= V_7 -> V_13 )
return - V_119 ;
V_62 = & V_7 -> V_15 [ V_9 ] ;
V_117 = & V_7 -> V_15 [ V_9 ] . V_35 ;
V_133 = F_12 ( V_117 -> V_36 ) ;
if ( V_6 >= V_136 )
{
F_3 ( L_43 ,
V_7 -> V_34 ,
V_9 , V_133 , V_62 -> V_89 ) ;
}
if ( V_62 -> V_89 )
return - V_137 ;
{
T_6 V_110 ;
V_110 = F_38 ( V_62 ) ;
if ( V_110 )
return V_110 ;
}
F_39 ( V_7 , V_62 -> V_29 , V_117 -> V_36 , 1 , V_117 -> V_94 ) ;
V_134 = F_11 ( ( T_3 * ) & V_7 -> V_55 -> V_138 ) & V_139 ;
if ( V_133 )
V_134 |= 1 << V_9 ;
else
V_134 &= 0xf ^ ( 1 << V_9 ) ;
F_16 ( ( T_3 * ) & V_7 -> V_55 -> V_138 , V_134 ) ;
F_16 ( ( T_3 * ) & V_7 -> V_55 -> V_140 , V_141 ) ;
F_16 ( ( T_3 * ) & V_62 -> V_79 -> V_142 , F_40 ( V_62 -> V_130 ) ) ;
V_62 -> V_130 -> V_143 =
F_41 ( V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 |
( V_150 << V_151 ) ) ;
V_62 -> V_130 -> V_152 =
F_41 ( ( V_133 ? 1 : 0 ) |
V_153 |
V_154 |
V_155 ) ;
V_62 -> V_130 -> V_156 = F_41 ( V_157 | ( V_157 << 16 ) ) ;
for ( V_135 = 0 ; V_135 < 32 ; V_135 ++ )
{
if ( ( ( V_135 == 0 ) && V_133 ) ||
( ( V_135 == 16 ) && ( ( V_117 -> V_36 == V_158 ) || ( V_117 -> V_36 == V_159 ) ) )
|| ( ( V_135 > 23 ) && ( ! V_133 ) ) )
{
V_62 -> V_102 [ V_135 ] = 0xff ;
} else
{
V_62 -> V_102 [ V_135 ] = 0x00 ;
}
}
for ( V_135 = 0 ; V_135 < V_14 ; V_135 ++ )
{
V_62 -> V_130 -> V_160 [ V_135 ] = 0 ;
V_62 -> V_130 -> V_161 [ V_135 ] = 0 ;
}
F_42 () ;
F_43 ( V_62 , V_162 | V_163 ) ;
F_43 ( V_62 , V_162 | V_164 ) ;
F_44 ( V_62 ) ;
V_62 -> V_165 = 1 ;
V_62 -> V_35 = * V_117 ;
return 0 ;
}
T_6
F_45 ( V_4 * V_7 , int V_9 , int V_3 , void * V_166 )
{
T_5 * V_62 ;
T_1 * V_8 ;
int V_10 ;
if ( F_4 ( V_3 ) )
return - V_167 ;
if ( V_9 >= V_7 -> V_13 )
return - V_119 ;
V_62 = & ( V_7 -> V_15 [ V_9 ] ) ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )
{
V_8 = V_62 -> V_16 [ V_10 ] ;
if ( V_8 && V_8 -> V_17 == V_18 )
break;
}
if ( V_10 == V_14 )
return - V_168 ;
V_8 -> V_91 = V_62 ;
V_8 -> V_17 = V_169 ;
V_8 -> V_166 = V_166 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_35 . V_3 = V_3 ;
#if 1
V_8 -> V_35 . V_103 = V_7 -> V_22 ;
V_8 -> V_35 . V_15 = V_9 ;
#endif
V_8 -> V_35 . V_170 = V_171 ;
V_8 -> V_35 . V_172 = V_173 ;
V_8 -> V_35 . V_174 = 2 ;
F_46 ( & V_8 -> V_175 ) ;
F_46 ( & V_8 -> V_176 ) ;
{
T_6 V_110 ;
V_110 = F_47 ( V_62 , V_8 ) ;
if ( V_110 )
return V_110 ;
}
if ( ! V_7 -> V_177 )
{
V_7 -> V_177 = V_7 -> V_178 = V_166 ;
V_7 -> V_179 = V_7 -> V_180 = V_3 ;
} else
{
V_7 -> V_178 = V_166 ;
if ( V_7 -> V_180 < V_3 )
V_7 -> V_180 = V_3 ;
}
return 0 ;
}
T_6
F_48 ( int V_3 )
{
T_1 * V_8 ;
V_8 = F_4 ( V_3 ) ;
if ( ! V_8 )
return - V_181 ;
if ( V_8 -> V_17 == V_182 )
F_49 ( ( V_4 * ) 0 , V_3 ) ;
V_8 -> V_17 = V_18 ;
V_8 -> V_10 = ( - 1 ) ;
V_8 -> V_3 = ( - 1 ) ;
V_8 -> V_35 . V_3 = ( - 1 ) ;
return 0 ;
}
T_6
F_50 ( int V_3 )
{
T_1 * V_8 ;
V_8 = F_4 ( V_3 ) ;
if ( ! V_8 )
return - V_181 ;
memset ( & V_8 -> V_183 , 0 , sizeof ( struct V_184 ) ) ;
return 0 ;
}
T_6
F_51 ( int V_3 , struct V_185 * V_35 )
{
T_1 * V_8 ;
int V_135 , V_186 = 0 ;
V_8 = F_4 ( V_3 ) ;
if ( ! V_8 )
return - V_181 ;
#if 1
if ( V_8 -> V_35 . V_103 != V_35 -> V_103 ||
V_8 -> V_35 . V_15 != V_35 -> V_15 ||
V_8 -> V_35 . V_3 != V_35 -> V_3 )
return - V_187 ;
#endif
if ( ! ( V_8 -> V_91 -> V_165 ) )
{
return - V_188 ;
}
if ( V_8 -> V_35 . V_189 != V_35 -> V_189 || V_8 -> V_35 . V_170 != V_35 -> V_170 ||
V_8 -> V_35 . V_190 != V_35 -> V_190 || V_8 -> V_35 . V_191 != V_35 -> V_191 ||
V_8 -> V_192 < V_8 -> V_193 )
V_186 = 1 ;
for ( V_135 = 0 ; V_135 < 32 ; V_135 ++ )
if ( V_8 -> V_35 . V_194 [ V_135 ] != V_35 -> V_194 [ V_135 ] )
V_186 = 1 ;
V_8 -> V_35 = * V_35 ;
if ( V_186 && ( V_8 -> V_17 == V_182 ) )
{
T_6 V_110 ;
V_110 = F_49 ( ( V_4 * ) 0 , V_3 ) ;
if ( V_110 )
return V_110 ;
V_110 = F_52 ( V_8 -> V_91 -> V_91 , V_3 ) ;
if ( V_110 )
return V_110 ;
F_53 ( V_8 -> V_166 ) ;
}
return 0 ;
}
T_6
F_54 ( int V_3 , struct V_185 * V_35 )
{
T_1 * V_8 ;
V_8 = F_4 ( V_3 ) ;
if ( ! V_8 )
return - V_181 ;
* V_35 = V_8 -> V_35 ;
return 0 ;
}
T_6
F_55 ( int V_3 , struct V_184 * V_35 )
{
T_1 * V_8 ;
V_8 = F_4 ( V_3 ) ;
if ( ! V_8 )
return - V_181 ;
* V_35 = V_8 -> V_183 ;
V_35 -> V_195 = F_56 ( & V_8 -> V_195 ) ;
return 0 ;
}
static int
F_57 ( T_5 * V_62 , int V_16 , int * V_196 )
{
int V_135 , V_197 = 0 , V_198 = 0 , V_199 = 0 , V_200 = 0 ;
for ( V_135 = 0 ; V_135 < 32 ; V_135 ++ )
{
if ( V_62 -> V_101 [ V_135 ] != - 1 )
{
V_197 = 0 ;
V_198 = V_135 + 1 ;
continue;
}
++ V_197 ;
if ( V_197 > V_199 )
{
V_199 = V_197 ;
V_200 = V_198 ;
}
if ( V_199 == * V_196 )
break;
}
if ( V_199 != * V_196 )
{
if ( V_6 >= V_114 )
F_3 ( L_44 ,
V_62 -> V_91 -> V_34 , * V_196 , V_199 ) ;
* V_196 = V_199 ;
}
if ( V_6 >= V_2 )
F_3 ( L_45 ,
V_62 -> V_91 -> V_34 , V_199 , V_198 , V_16 , V_62 -> V_35 . V_9 ) ;
for ( V_135 = V_200 ; V_135 < ( V_200 + V_199 ) ; V_135 ++ )
V_62 -> V_101 [ V_135 ] = V_16 ;
return V_198 ;
}
void
F_58 ( T_5 * V_62 , int V_16 )
{
int V_135 ;
if ( V_6 >= V_2 )
F_3 ( L_46 ,
V_62 -> V_91 -> V_34 , V_16 , V_62 -> V_35 . V_9 ) ;
for ( V_135 = 0 ; V_135 < 32 ; V_135 ++ )
if ( V_62 -> V_101 [ V_135 ] == V_16 )
V_62 -> V_101 [ V_135 ] = - 1 ;
}
T_6
F_52 ( V_4 * V_7 , int V_3 )
{
T_5 * V_62 ;
T_1 * V_8 ;
struct V_201 * V_202 ;
struct V_203 * V_204 ;
int V_205 , V_206 , V_207 , V_208 ;
int V_209 , V_135 , V_63 , V_10 ;
T_3 V_210 ;
V_8 = F_4 ( V_3 ) ;
if ( ! V_8 )
return - V_181 ;
if ( V_8 -> V_17 == V_182 )
{
if ( V_6 >= V_59 )
F_3 ( L_47 ,
V_7 -> V_34 ) ;
return 0 ;
}
V_62 = V_8 -> V_91 ;
V_10 = V_8 -> V_10 ;
V_205 = 0 ;
for ( V_135 = 0 ; V_135 < 32 ; V_135 ++ )
{
if ( V_8 -> V_35 . V_194 [ V_135 ] & V_62 -> V_102 [ V_135 ] )
{
if ( 1 || V_6 >= V_114 )
{
F_3 ( L_48 ,
V_7 -> V_34 , V_3 , V_135 ) ;
F_3 ( L_49 ,
V_8 -> V_35 . V_194 [ V_135 ] , V_62 -> V_102 [ V_135 ] ) ;
}
return - V_187 ;
}
for ( V_63 = 0 ; V_63 < 8 ; V_63 ++ )
if ( V_8 -> V_35 . V_194 [ V_135 ] & ( 1 << V_63 ) )
V_205 ++ ;
}
V_206 = V_205 / 8 ? V_205 / 8 : 1 ;
if ( ! V_206 )
{
F_3 ( L_50 ,
V_7 -> V_34 , V_3 ) ;
return - V_211 ;
}
V_209 = F_57 ( V_62 , V_10 , & V_206 ) ;
V_8 -> V_17 = V_182 ;
F_59 ( V_62 ) ;
V_8 -> V_183 . V_195 = 0 ;
{
T_3 V_212 ;
V_212 = F_60 ( V_8 -> V_35 . V_170 ) << V_213 ;
if ( ( V_8 -> V_35 . V_170 == V_214 ) ||
( V_8 -> V_35 . V_170 == V_215 ) )
{
V_212 |= V_216 ;
}
V_212 |= 2 << V_217 ;
V_212 |= V_8 -> V_35 . V_191 ;
V_212 |= V_209 << V_218 ;
if ( V_8 -> V_35 . V_170 == V_215 )
V_212 |= ( V_206 ) << V_219 ;
else
V_212 |= ( V_206 - 1 ) << V_219 ;
if ( V_8 -> V_35 . V_190 & V_220 )
V_212 |= V_221 ;
V_62 -> V_130 -> V_222 [ V_10 ] = F_61 ( V_212 ) ;
if ( V_8 -> V_35 . V_190 & V_223 )
V_212 |= V_221 ;
else
V_212 &= ~ V_221 ;
V_62 -> V_130 -> V_224 [ V_10 ] = F_61 ( V_212 ) ;
F_42 () ;
}
F_43 ( V_62 , V_225 | V_163 | V_10 ) ;
F_43 ( V_62 , V_225 | V_164 | V_10 ) ;
if ( V_8 -> V_35 . V_170 == V_215 )
{
if ( V_226 == V_227 )
V_226 = V_228 ;
if ( V_229 == V_230 )
V_229 = V_231 ;
}
V_208 = V_226 + ( V_205 / 4 ) ;
V_207 = V_229 + ( V_205 / 4 ) ;
#if 0
if (cxt1e1_log_level >= LOG_MONITOR)
pr_info("%s: mode %x rxnum %d (rxused %d def %d) txnum %d (txused %d def %d)\n",
ci->devname, ch->p.chan_mode,
rxnum, max_rxdesc_used, max_rxdesc_default,
txnum, max_txdesc_used, max_txdesc_default);
#endif
V_8 -> V_232 = V_208 ;
V_8 -> V_193 = V_207 ;
V_8 -> V_233 = 0 ;
V_8 -> V_234 = F_8 ( sizeof ( struct V_203 ) * V_208 ) ;
V_8 -> V_235 = F_8 ( sizeof ( struct V_203 ) * V_207 ) ;
if ( V_8 -> V_35 . V_170 == V_215 )
V_210 = F_41 ( V_157 | V_236 ) ;
else
V_210 = F_41 ( V_157 ) ;
for ( V_135 = 0 , V_204 = V_8 -> V_234 ; V_135 < V_208 ; V_135 ++ , V_204 ++ )
{
if ( V_135 == ( V_208 - 1 ) )
{
V_204 -> V_237 = & V_8 -> V_234 [ 0 ] ;
} else
{
V_204 -> V_237 = & V_8 -> V_234 [ V_135 + 1 ] ;
}
V_204 -> V_12 = F_61 ( F_40 ( V_204 -> V_237 ) ) ;
V_202 = F_62 ( V_157 ) ;
if ( ! V_202 ) {
if ( V_6 >= V_59 )
F_3 (
L_51 ,
V_7 -> V_34 , V_3 , V_157 ) ;
goto V_238;
}
V_204 -> V_239 = V_202 ;
V_204 -> V_118 = F_61 ( F_40 ( F_63 ( V_202 ) ) ) ;
V_204 -> V_189 = V_210 | V_240 ;
}
for ( V_135 = 0 , V_204 = V_8 -> V_235 ; V_135 < V_207 ; V_135 ++ , V_204 ++ )
{
V_204 -> V_189 = V_241 ;
V_204 -> V_239 = NULL ;
V_204 -> V_118 = 0 ;
if ( V_135 == ( V_207 - 1 ) )
{
V_204 -> V_237 = & V_8 -> V_235 [ 0 ] ;
} else
{
V_204 -> V_237 = & V_8 -> V_235 [ V_135 + 1 ] ;
}
V_204 -> V_12 = F_61 ( F_40 ( V_204 -> V_237 ) ) ;
}
V_8 -> V_242 = V_8 -> V_243 = & V_8 -> V_235 [ 0 ] ;
V_8 -> V_192 = V_207 ;
V_8 -> V_244 = 0 ;
V_8 -> V_245 = 0 ;
V_210 = F_61 ( F_40 ( & V_8 -> V_235 [ 0 ] ) ) ;
V_62 -> V_130 -> V_246 [ V_10 ] = V_210 ;
V_62 -> V_130 -> V_210 [ V_10 ] = V_210 ;
V_210 = F_61 ( F_40 ( & V_8 -> V_234 [ 0 ] ) ) ;
V_62 -> V_130 -> V_247 [ V_10 ] = V_210 ;
V_62 -> V_130 -> V_248 [ V_10 ] = V_210 ;
F_42 () ;
if ( V_8 -> V_35 . V_189 & V_249 )
{
#ifdef F_64
F_3 ( L_52 , V_8 -> V_3 ) ;
#endif
V_8 -> V_250 = 0 ;
F_43 ( V_62 , V_251 | V_163 | V_10 ) ;
}
if ( V_8 -> V_35 . V_189 & V_252 )
{
#ifdef F_64
F_3 ( L_53 , V_8 -> V_3 ) ;
#endif
V_8 -> V_253 = V_254 ;
}
V_8 -> V_189 = V_8 -> V_35 . V_189 ;
V_62 -> V_89 ++ ;
return 0 ;
V_238:
while ( V_135 > 0 )
{
V_135 -- ;
F_65 ( V_8 -> V_234 [ V_135 ] . V_239 ) ;
}
F_20 ( V_8 -> V_235 ) ;
V_8 -> V_235 = NULL ;
V_8 -> V_193 = 0 ;
F_20 ( V_8 -> V_234 ) ;
V_8 -> V_234 = NULL ;
V_8 -> V_232 = 0 ;
V_8 -> V_17 = V_169 ;
return - V_211 ;
}
void
F_66 ( V_4 * V_7 )
{
F_67 ( & V_7 -> V_107 ) ;
F_35 ( & V_7 -> V_132 , L_54 ) ;
F_36 ( & V_7 -> V_132 ) ;
}
void
F_68 ( V_4 * V_7 , struct V_255 * V_256 , T_4 * V_257 )
{
char * V_258 ;
T_3 V_259 = 0 ;
int V_135 ;
V_256 -> V_22 = V_7 -> V_22 ;
V_256 -> V_260 = V_7 -> V_260 ;
V_256 -> V_261 = V_7 -> V_262 ;
V_256 -> V_263 = V_14 * V_7 -> V_13 ;
V_256 -> V_264 = V_7 -> V_13 ;
V_256 -> V_265 = V_266 ;
if ( V_7 -> V_177 )
{
{
struct V_267 * V_268 ;
V_268 = (struct V_267 * ) V_7 -> V_177 ;
V_258 = ( char * ) V_268 -> V_269 ;
}
strncpy ( V_256 -> V_270 , V_258 , V_271 - 1 ) ;
} else
strcpy ( V_256 -> V_270 , L_55 ) ;
if ( V_7 -> V_178 )
{
{
struct V_267 * V_268 ;
V_268 = (struct V_267 * ) V_7 -> V_178 ;
V_258 = ( char * ) V_268 -> V_269 ;
}
strncpy ( V_256 -> V_272 , V_258 , V_271 - 1 ) ;
} else
strcpy ( V_256 -> V_272 , L_55 ) ;
if ( V_257 )
{
for ( V_135 = 0 ; V_135 < 3 ; V_135 ++ )
{
V_256 -> V_273 [ V_135 ] = * V_257 ++ ;
}
for (; V_135 < 6 ; V_135 ++ )
{
V_256 -> V_273 [ V_135 ] = * V_257 ;
V_259 = ( V_259 << 8 ) | * V_257 ++ ;
}
} else
{
for ( V_135 = 0 ; V_135 < 6 ; V_135 ++ )
V_256 -> V_273 [ V_135 ] = 0 ;
}
V_256 -> V_274 = V_259 ;
}
T_6
F_69 ( V_4 * V_7 , struct V_275 * V_276 )
{
struct V_267 * V_268 ;
char * V_258 ;
V_268 = F_70 ( V_276 -> V_3 ) ;
if ( ! V_268 )
return - V_181 ;
V_258 = V_268 -> V_269 ;
strncpy ( V_276 -> V_277 , V_258 , V_271 - 1 ) ;
V_276 -> V_277 [ V_271 - 1 ] = '\0' ;
return 0 ;
}
void
F_71 ( int V_278 , int V_279 , void * V_280 )
{
if ( V_278 < V_281 )
V_282 [ V_278 ] [ V_279 ] = V_280 ;
}
T_8
F_72 ( void * V_283 )
{
V_4 * V_7 = ( V_4 * ) V_283 ;
volatile T_3 V_284 ;
int V_285 = 0 ;
int V_22 ;
V_22 = V_7 -> V_22 ;
V_284 = F_11 ( ( T_3 * ) & V_7 -> V_55 -> V_286 ) ;
if ( V_284 & V_287 )
{
V_285 = 0x1 ;
if ( V_282 [ V_22 ] [ 0 ] != NULL )
(* V_282 [ V_22 ] [ 0 ]) () ;
}
if ( V_284 & V_288 )
{
V_285 |= 0x2 ;
if ( V_282 [ V_22 ] [ 1 ] != NULL )
(* V_282 [ V_22 ] [ 1 ]) () ;
}
if ( V_284 & V_289 )
{
V_285 |= 0x4 ;
if ( V_282 [ V_22 ] [ 2 ] != NULL )
(* V_282 [ V_22 ] [ 2 ]) () ;
}
if ( V_284 & V_290 )
{
V_285 |= 0x8 ;
if ( V_282 [ V_22 ] [ 3 ] != NULL )
(* V_282 [ V_22 ] [ 3 ]) () ;
}
#if 0
pci_write_32 ((u_int32_t *) &ci->reg->glcd, GCD_MAGIC | MUSYCC_GCD_INTB_DISABLE);
#endif
return F_73 ( V_285 ) ;
}
unsigned long
F_74 ( int V_278 , int V_279 )
{
V_4 * V_7 ;
unsigned long V_291 = 0 ;
V_7 = V_11 ;
while ( V_7 )
{
if ( V_7 -> V_22 == V_278 )
{
if ( V_279 < V_7 -> V_13 )
V_291 = ( ( unsigned long ) V_7 -> V_15 [ V_279 ] . V_29 ) ;
break;
}
V_7 = V_7 -> V_12 ;
}
return V_291 ;
}
