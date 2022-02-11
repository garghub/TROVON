void F_1 ( int V_1 , unsigned long V_2 , void * V_3 , T_1 V_4 , T_1 V_5 , int V_6 , int V_7 )
{
T_2 V_8 ;
T_2 V_9 ;
int V_10 ;
#ifdef F_2
int V_11 ;
#endif
T_3 * V_12 = & V_13 [ V_1 ] ;
#ifdef F_3
int V_14 = 0 ;
#endif
F_4 ( & V_15 , V_9 ) ;
V_10 = ( V_4 > 1 && V_7 == 0 ) ? V_16 : 0 ;
#ifdef F_2
V_11 = V_10 ;
V_10 = 0 ;
#endif
V_8 = V_12 -> V_17 + V_2 - V_12 -> V_18 + V_19 ;
if ( V_12 -> V_20 != V_21 || V_12 -> V_22 != V_10 ) {
T_2 V_23 ;
F_5 ( V_1 , V_24 , 0 ) ;
V_23 = ( V_12 -> V_9 & V_25 ) ? 0 : V_26 ;
F_5 ( V_1 , V_27 , V_28 | V_23 | V_10 ) ;
F_5 ( V_1 , V_29 , V_8 & 0x1ff00000 ) ;
F_5 ( V_1 , V_24 , 1 ) ;
#ifdef F_3
#if 0
map_changed = (t->current_space == as_attr && size == 2);
#else
V_14 = 1 ;
#endif
#endif
V_12 -> V_20 = V_21 ;
}
if ( V_4 == 1 ) {
unsigned char * V_30 = ( unsigned char * ) V_3 ;
#ifdef F_6
if ( V_14 ) {
V_31 = F_7 ( V_8 ) ;
}
#endif
if ( V_6 ) {
while ( V_5 -- ) {
F_8 ( * V_30 ++ , V_8 ) ;
}
} else {
while ( V_5 -- ) {
* V_30 ++ = F_7 ( V_8 ) ;
}
}
} else {
unsigned short * V_30 = ( unsigned short * ) V_3 ;
#ifdef F_3
if ( V_14 ) {
V_31 = F_9 ( V_8 ) ;
}
#endif
if ( V_6 ) {
while ( V_5 -- ) {
#ifdef F_2
if ( V_11 ) {
unsigned char * V_32 = ( unsigned char * ) V_30 ;
unsigned short V_33 ;
V_33 = V_32 [ 1 ] << 8 | V_32 [ 0 ] ;
F_10 ( V_33 , V_8 ) ;
V_30 ++ ;
} else
#endif
F_10 ( * V_30 ++ , V_8 ) ;
}
} else {
while ( V_5 -- ) {
#ifdef F_2
if ( V_11 ) {
unsigned char * V_32 = ( unsigned char * ) V_30 ;
unsigned short V_33 ;
V_33 = F_9 ( V_8 ) ;
V_32 [ 0 ] = V_33 & 0xff ;
V_32 [ 1 ] = ( V_33 >> 8 ) & 0xff ;
V_30 ++ ;
} else
#endif
* V_30 ++ = F_9 ( V_8 ) ;
}
}
}
#if 1
if ( ( V_8 = F_11 ( V_1 , V_34 ) ) & V_35 ) {
F_12 ( L_1 ,
V_2 , V_4 * 8 ) ;
F_5 ( V_1 , V_34 , V_8 ) ;
}
#endif
V_12 -> V_36 = V_4 ;
V_12 -> V_22 = V_10 ;
F_13 ( & V_15 , V_9 ) ;
return;
}
void F_14 ( int V_1 , unsigned long V_2 , void * V_3 , T_1 V_4 , T_1 V_5 , int V_7 ) {
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , 0 , V_7 ) ;
}
void F_15 ( int V_1 , unsigned long V_2 , void * V_3 , T_1 V_4 , T_1 V_5 , int V_7 ) {
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , 1 , V_7 ) ;
}
static unsigned int F_11 ( T_4 V_1 , unsigned int V_37 )
{
return F_16 ( V_13 [ V_1 ] . V_38 + V_37 ) ;
}
static void F_5 ( T_4 V_1 , unsigned int V_37 , unsigned int V_39 )
{
F_17 ( V_39 , V_13 [ V_1 ] . V_38 + V_37 ) ;
}
static int T_5 F_18 ( T_4 V_1 )
{
unsigned int V_40 ;
unsigned int V_41 ;
V_40 = F_11 ( V_1 , V_34 ) ;
V_41 = ( V_40 & ( V_42 | V_43 ) ) >> 16 ;
if( ! V_41 ) {
F_12 ( L_2 , V_40 , V_1 ) ;
return 0 ;
}
if( V_41 != 3 )
F_12 ( L_3 , V_40 , V_1 ) ;
else
F_12 ( L_4 , V_1 , V_40 ) ;
return 0 ;
}
static int F_19 ( T_6 V_38 , int V_44 , T_6 V_17 ,
unsigned int V_18 )
{
T_3 * V_12 = & V_13 [ V_45 ] ;
int V_46 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_38 = V_38 ;
#ifdef F_3
V_12 -> V_9 = V_25 ;
#else
V_12 -> V_9 = 0 ;
#endif
if ( F_18 ( V_45 ) )
V_12 -> V_9 |= V_47 ;
if ( V_12 -> V_38 > 0 ) {
F_20 ( V_12 -> V_38 , 0x20 , L_5 ) ;
}
F_12 ( V_48 L_6 , V_49 [ V_45 ] . V_50 ) ;
F_12 ( L_7 , V_12 -> V_38 ) ;
V_12 -> V_13 . V_51 |= ( V_52 | V_53 ) ;
V_12 -> V_13 . V_54 = V_55 ;
V_12 -> V_13 . V_56 = V_18 ;
V_12 -> V_13 . V_57 = 0 ;
V_12 -> V_13 . V_58 = 2 + V_45 ;
V_46 = F_21 ( V_44 , V_59 , 0 , L_5 , V_59 ) ;
if ( V_46 ) {
if ( V_12 -> V_38 > 0 )
F_22 ( V_12 -> V_38 , 0x20 ) ;
return V_46 ;
}
V_45 ++ ;
return 0 ;
}
static T_7 V_59 ( int V_44 , void * V_60 )
{
int V_61 , V_62 , V_63 ;
T_8 V_64 , V_65 ;
int V_66 = 0 ;
F_23 ( L_8 , V_44 ) ;
for ( V_62 = 0 ; V_62 < 20 ; V_62 ++ ) {
V_65 = 0 ;
for ( V_61 = 0 ; V_61 < V_45 ; V_61 ++ ) {
if ( ( V_13 [ V_61 ] . V_67 != V_44 ) &&
( V_13 [ V_61 ] . V_13 . V_58 != V_44 ) )
continue;
V_66 = 1 ;
V_63 = F_11 ( V_61 , V_34 ) ;
V_63 >>= 16 ;
F_23 ( L_9 ,
V_61 , V_63 ) ;
if ( ! V_63 )
continue;
V_64 = ( V_63 ) ? V_68 : 0 ;
V_64 |= ( F_11 ( V_61 , V_24 ) & V_69 ) ? V_70 : 0 ;
F_23 ( L_10 , V_64 ) ;
if ( V_64 )
F_24 ( & V_13 [ V_61 ] . V_13 , V_64 ) ;
V_65 |= V_64 ;
V_65 = 0 ;
}
if ( ! V_65 ) break;
}
if ( V_62 == 20 )
F_12 ( V_71 L_11 ) ;
F_23 ( L_12 ) ;
return F_25 ( V_66 ) ;
}
static void F_26 ( T_2 V_39 )
{
V_59 ( 0 , NULL ) ;
F_27 ( & V_72 ) ;
V_72 . V_73 = V_74 + V_75 ;
F_28 ( & V_72 ) ;
}
static int F_29 ( T_4 V_1 , T_8 * V_76 )
{
T_8 V_77 ;
V_77 = F_11 ( V_1 , V_34 ) ;
* V_76 = ( ( V_77 & V_42 ) && ( V_77 & V_43 ) )
? V_68 : 0 ;
V_77 = F_11 ( V_1 , V_24 ) ;
#if 0
*value |= (status & PCCR_PCEN) ? SS_READY : 0;
#else
* V_76 |= V_70 ;
#endif
V_77 = F_11 ( V_1 , V_78 ) ;
* V_76 |= ( V_77 & V_79 ) ? V_80 : 0 ;
F_23 ( L_13 , V_1 , * V_76 ) ;
return 0 ;
}
static int F_30 ( T_4 V_1 , T_9 * V_81 )
{
T_2 V_37 = 0 ;
F_23 ( L_14
L_15 , V_1 , V_81 -> V_9 ,
V_81 -> V_82 , V_81 -> V_83 , V_81 -> V_84 , V_81 -> V_85 ) ;
if ( V_81 -> V_82 ) {
if ( V_81 -> V_82 == 50 ) {
V_37 |= V_79 ;
} else {
return - V_86 ;
}
}
if ( V_81 -> V_9 & V_87 ) {
F_23 ( L_16 ) ;
V_37 |= V_88 ;
}
if ( V_81 -> V_9 & V_89 ) {
F_23 ( L_17 ) ;
} else {
V_37 |= V_90 ;
}
F_5 ( V_1 , V_78 , V_37 ) ;
if( V_81 -> V_9 & V_91 ) {
F_23 ( L_18 ) ;
}
if ( V_81 -> V_9 & V_92 ) {
F_23 ( L_19 ) ;
}
if ( V_81 -> V_85 & V_68 )
F_23 ( L_20 ) ;
if ( V_81 -> V_9 & V_91 ) {
if ( V_81 -> V_85 & V_93 )
F_23 ( L_21 ) ;
} else {
if ( V_81 -> V_85 & V_94 )
F_23 ( L_22 ) ;
if ( V_81 -> V_85 & V_95 )
F_23 ( L_23 ) ;
if ( V_81 -> V_85 & V_70 )
F_23 ( L_24 ) ;
}
F_23 ( L_25 ) ;
return 0 ;
}
static int F_31 ( T_4 V_1 , struct V_96 * V_97 )
{
T_10 V_98 ;
F_23 ( L_26
L_27 , V_1 , V_97 -> V_98 , V_97 -> V_9 ,
V_97 -> V_99 , ( unsigned long long ) V_97 -> V_100 ,
( unsigned long long ) V_97 -> V_101 ) ;
V_98 = V_97 -> V_98 ;
return 0 ;
}
static int F_32 ( T_4 V_1 , struct V_102 * V_103 )
{
T_10 V_98 = V_103 -> V_98 ;
T_2 V_104 ;
T_2 V_8 ;
T_3 * V_12 = & V_13 [ V_1 ] ;
#ifdef F_3
#if 0
pcc_as_t last = t->current_space;
#endif
#endif
F_23 ( L_28
L_29 , V_1 , V_98 , V_103 -> V_9 ,
V_103 -> V_99 , ( unsigned long long ) V_103 -> V_105 ,
V_103 -> V_106 ) ;
if ( ( V_98 > V_107 ) || ( V_103 -> V_106 > 0x3ffffff ) ) {
return - V_86 ;
}
if ( ( V_103 -> V_9 & V_108 ) == 0 ) {
V_12 -> V_20 = V_109 ;
return 0 ;
}
F_5 ( V_1 , V_24 , 0 ) ;
if ( V_103 -> V_9 & V_110 ) {
V_104 = V_111 | V_26 ;
V_12 -> V_20 = V_112 ;
} else {
V_104 = 0 ;
V_12 -> V_20 = V_113 ;
}
F_5 ( V_1 , V_27 , V_104 ) ;
V_8 = V_12 -> V_17 + ( V_103 -> V_106 & V_114 ) ;
F_5 ( V_1 , V_29 , V_8 ) ;
V_103 -> V_105 = V_8 + V_103 -> V_106 ;
F_5 ( V_1 , V_24 , 1 ) ;
#ifdef F_3
#if 0
if (last != as_attr) {
#else
if ( 1 ) {
#endif
V_31 = * ( T_10 * ) ( V_8 + V_19 ) ;
}
#endif
return 0 ;
}
static int F_33 ( struct V_115 * V_116 , T_8 * V_76 )
{
unsigned int V_1 = F_34 ( V_116 , struct V_117 , V_13 ) -> V_118 ;
if ( V_13 [ V_1 ] . V_9 & V_47 ) {
* V_76 = 0 ;
return - V_86 ;
}
F_35 ( F_29 ( V_1 , V_76 ) ) ;
}
static int F_36 ( struct V_115 * V_116 , T_9 * V_81 )
{
unsigned int V_1 = F_34 ( V_116 , struct V_117 , V_13 ) -> V_118 ;
if ( V_13 [ V_1 ] . V_9 & V_47 )
return - V_86 ;
F_35 ( F_30 ( V_1 , V_81 ) ) ;
}
static int F_37 ( struct V_115 * V_116 , struct V_96 * V_97 )
{
unsigned int V_1 = F_34 ( V_116 , struct V_117 , V_13 ) -> V_118 ;
if ( V_13 [ V_1 ] . V_9 & V_47 )
return - V_86 ;
F_35 ( F_31 ( V_1 , V_97 ) ) ;
}
static int F_38 ( struct V_115 * V_116 , struct V_102 * V_103 )
{
unsigned int V_1 = F_34 ( V_116 , struct V_117 , V_13 ) -> V_118 ;
if ( V_13 [ V_1 ] . V_9 & V_47 )
return - V_86 ;
F_35 ( F_32 ( V_1 , V_103 ) ) ;
}
static int F_39 ( struct V_115 * V_116 )
{
F_23 ( L_30 ) ;
return 0 ;
}
static int T_5 F_40 ( void )
{
int V_61 , V_119 ;
V_119 = F_41 ( & V_120 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_42 ( & V_121 ) ;
if ( V_119 )
goto V_122;
F_12 ( V_48 L_31 ) ;
V_45 = 0 ;
V_119 = F_19 ( V_123 , V_124 , V_125 ,
0x1000 ) ;
if ( V_119 )
goto V_126;
#ifdef F_43
V_119 = F_19 ( V_127 , V_128 , V_129 ,
0x2000 ) ;
if ( V_119 )
goto V_126;
#endif
if ( V_45 == 0 ) {
F_12 ( L_32 ) ;
V_119 = - V_130 ;
goto V_126;
}
for ( V_61 = 0 ; V_61 < V_45 ; V_61 ++ ) {
V_13 [ V_61 ] . V_13 . V_60 . V_131 = & V_121 . V_60 ;
V_13 [ V_61 ] . V_13 . V_132 = & V_133 ;
V_13 [ V_61 ] . V_13 . V_134 = & V_135 ;
V_13 [ V_61 ] . V_13 . V_136 = V_137 ;
V_13 [ V_61 ] . V_118 = V_61 ;
V_119 = F_44 ( & V_13 [ V_61 ] . V_13 ) ;
if ( ! V_119 )
V_13 [ V_61 ] . V_9 |= V_138 ;
}
if ( V_75 != 0 ) {
V_72 . V_139 = F_26 ;
V_72 . V_39 = 0 ;
F_27 ( & V_72 ) ;
V_72 . V_73 = V_74 + V_75 ;
F_28 ( & V_72 ) ;
}
return 0 ;
V_126:
F_45 ( & V_121 ) ;
V_122:
F_46 ( & V_120 ) ;
return V_119 ;
}
static void T_11 F_47 ( void )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_45 ; V_61 ++ )
if ( V_13 [ V_61 ] . V_9 & V_138 )
F_48 ( & V_13 [ V_61 ] . V_13 ) ;
F_45 ( & V_121 ) ;
if ( V_75 != 0 )
F_49 ( & V_72 ) ;
F_46 ( & V_120 ) ;
}
