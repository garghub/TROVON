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
static void F_19 ( T_6 V_38 , int V_44 , T_6 V_17 ,
unsigned int V_18 )
{
T_3 * V_12 = & V_13 [ V_45 ] ;
V_12 -> V_18 = V_18 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_38 = V_38 ;
#ifdef F_3
V_12 -> V_9 = V_25 ;
#else
V_12 -> V_9 = 0 ;
#endif
if ( F_18 ( V_45 ) )
V_12 -> V_9 |= V_46 ;
if ( V_12 -> V_38 > 0 ) {
F_20 ( V_12 -> V_38 , 0x20 , L_5 ) ;
}
F_12 ( V_47 L_6 , V_48 [ V_45 ] . V_49 ) ;
F_12 ( L_7 , V_12 -> V_38 ) ;
V_12 -> V_13 . V_50 |= ( V_51 | V_52 ) ;
V_12 -> V_13 . V_53 = V_54 ;
V_12 -> V_13 . V_55 = V_18 ;
V_12 -> V_13 . V_56 = 0 ;
V_12 -> V_13 . V_57 = 2 + V_45 ;
F_21 ( V_44 , V_58 , 0 , L_5 , V_58 ) ;
V_45 ++ ;
return;
}
static T_7 V_58 ( int V_44 , void * V_59 )
{
int V_60 , V_61 , V_62 ;
T_8 V_63 , V_64 ;
int V_65 = 0 ;
F_22 ( L_8 , V_44 ) ;
for ( V_61 = 0 ; V_61 < 20 ; V_61 ++ ) {
V_64 = 0 ;
for ( V_60 = 0 ; V_60 < V_45 ; V_60 ++ ) {
if ( ( V_13 [ V_60 ] . V_66 != V_44 ) &&
( V_13 [ V_60 ] . V_13 . V_57 != V_44 ) )
continue;
V_65 = 1 ;
V_62 = F_11 ( V_60 , V_34 ) ;
V_62 >>= 16 ;
F_22 ( L_9 ,
V_60 , V_62 ) ;
if ( ! V_62 )
continue;
V_63 = ( V_62 ) ? V_67 : 0 ;
V_63 |= ( F_11 ( V_60 , V_24 ) & V_68 ) ? V_69 : 0 ;
F_22 ( L_10 , V_63 ) ;
if ( V_63 )
F_23 ( & V_13 [ V_60 ] . V_13 , V_63 ) ;
V_64 |= V_63 ;
V_64 = 0 ;
}
if ( ! V_64 ) break;
}
if ( V_61 == 20 )
F_12 ( V_70 L_11 ) ;
F_22 ( L_12 ) ;
return F_24 ( V_65 ) ;
}
static void F_25 ( T_2 V_39 )
{
V_58 ( 0 , NULL ) ;
F_26 ( & V_71 ) ;
V_71 . V_72 = V_73 + V_74 ;
F_27 ( & V_71 ) ;
}
static int F_28 ( T_4 V_1 , T_8 * V_75 )
{
T_8 V_76 ;
V_76 = F_11 ( V_1 , V_34 ) ;
* V_75 = ( ( V_76 & V_42 ) && ( V_76 & V_43 ) )
? V_67 : 0 ;
V_76 = F_11 ( V_1 , V_24 ) ;
#if 0
*value |= (status & PCCR_PCEN) ? SS_READY : 0;
#else
* V_75 |= V_69 ;
#endif
V_76 = F_11 ( V_1 , V_77 ) ;
* V_75 |= ( V_76 & V_78 ) ? V_79 : 0 ;
F_22 ( L_13 , V_1 , * V_75 ) ;
return 0 ;
}
static int F_29 ( T_4 V_1 , T_9 * V_80 )
{
T_2 V_37 = 0 ;
F_22 ( L_14
L_15 , V_1 , V_80 -> V_9 ,
V_80 -> V_81 , V_80 -> V_82 , V_80 -> V_83 , V_80 -> V_84 ) ;
if ( V_80 -> V_81 ) {
if ( V_80 -> V_81 == 50 ) {
V_37 |= V_78 ;
} else {
return - V_85 ;
}
}
if ( V_80 -> V_9 & V_86 ) {
F_22 ( L_16 ) ;
V_37 |= V_87 ;
}
if ( V_80 -> V_9 & V_88 ) {
F_22 ( L_17 ) ;
} else {
V_37 |= V_89 ;
}
F_5 ( V_1 , V_77 , V_37 ) ;
if( V_80 -> V_9 & V_90 ) {
F_22 ( L_18 ) ;
}
if ( V_80 -> V_9 & V_91 ) {
F_22 ( L_19 ) ;
}
if ( V_80 -> V_84 & V_67 )
F_22 ( L_20 ) ;
if ( V_80 -> V_9 & V_90 ) {
if ( V_80 -> V_84 & V_92 )
F_22 ( L_21 ) ;
} else {
if ( V_80 -> V_84 & V_93 )
F_22 ( L_22 ) ;
if ( V_80 -> V_84 & V_94 )
F_22 ( L_23 ) ;
if ( V_80 -> V_84 & V_69 )
F_22 ( L_24 ) ;
}
F_22 ( L_25 ) ;
return 0 ;
}
static int F_30 ( T_4 V_1 , struct V_95 * V_96 )
{
T_10 V_97 ;
F_22 ( L_26
L_27 , V_1 , V_96 -> V_97 , V_96 -> V_9 ,
V_96 -> V_98 , ( unsigned long long ) V_96 -> V_99 ,
( unsigned long long ) V_96 -> V_100 ) ;
V_97 = V_96 -> V_97 ;
return 0 ;
}
static int F_31 ( T_4 V_1 , struct V_101 * V_102 )
{
T_10 V_97 = V_102 -> V_97 ;
T_2 V_103 ;
T_2 V_8 ;
T_3 * V_12 = & V_13 [ V_1 ] ;
#ifdef F_3
#if 0
pcc_as_t last = t->current_space;
#endif
#endif
F_22 ( L_28
L_29 , V_1 , V_97 , V_102 -> V_9 ,
V_102 -> V_98 , ( unsigned long long ) V_102 -> V_104 ,
V_102 -> V_105 ) ;
if ( ( V_97 > V_106 ) || ( V_102 -> V_105 > 0x3ffffff ) ) {
return - V_85 ;
}
if ( ( V_102 -> V_9 & V_107 ) == 0 ) {
V_12 -> V_20 = V_108 ;
return 0 ;
}
F_5 ( V_1 , V_24 , 0 ) ;
if ( V_102 -> V_9 & V_109 ) {
V_103 = V_110 | V_26 ;
V_12 -> V_20 = V_111 ;
} else {
V_103 = 0 ;
V_12 -> V_20 = V_112 ;
}
F_5 ( V_1 , V_27 , V_103 ) ;
V_8 = V_12 -> V_17 + ( V_102 -> V_105 & V_113 ) ;
F_5 ( V_1 , V_29 , V_8 ) ;
V_102 -> V_104 = V_8 + V_102 -> V_105 ;
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
static int F_32 ( struct V_114 * V_115 , T_8 * V_75 )
{
unsigned int V_1 = F_33 ( V_115 , struct V_116 , V_13 ) -> V_117 ;
if ( V_13 [ V_1 ] . V_9 & V_46 ) {
* V_75 = 0 ;
return - V_85 ;
}
F_34 ( F_28 ( V_1 , V_75 ) ) ;
}
static int F_35 ( struct V_114 * V_115 , T_9 * V_80 )
{
unsigned int V_1 = F_33 ( V_115 , struct V_116 , V_13 ) -> V_117 ;
if ( V_13 [ V_1 ] . V_9 & V_46 )
return - V_85 ;
F_34 ( F_29 ( V_1 , V_80 ) ) ;
}
static int F_36 ( struct V_114 * V_115 , struct V_95 * V_96 )
{
unsigned int V_1 = F_33 ( V_115 , struct V_116 , V_13 ) -> V_117 ;
if ( V_13 [ V_1 ] . V_9 & V_46 )
return - V_85 ;
F_34 ( F_30 ( V_1 , V_96 ) ) ;
}
static int F_37 ( struct V_114 * V_115 , struct V_101 * V_102 )
{
unsigned int V_1 = F_33 ( V_115 , struct V_116 , V_13 ) -> V_117 ;
if ( V_13 [ V_1 ] . V_9 & V_46 )
return - V_85 ;
F_34 ( F_31 ( V_1 , V_102 ) ) ;
}
static int F_38 ( struct V_114 * V_115 )
{
F_22 ( L_30 ) ;
return 0 ;
}
static int T_5 F_39 ( void )
{
int V_60 , V_118 ;
V_118 = F_40 ( & V_119 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_41 ( & V_120 ) ;
if ( V_118 ) {
F_42 ( & V_119 ) ;
return V_118 ;
}
F_12 ( V_47 L_31 ) ;
V_45 = 0 ;
F_19 ( V_121 , V_122 , V_123 , 0x1000 ) ;
#ifdef F_43
F_19 ( V_124 , V_125 , V_126 , 0x2000 ) ;
#endif
if ( V_45 == 0 ) {
F_12 ( L_32 ) ;
F_44 ( & V_120 ) ;
F_42 ( & V_119 ) ;
return - V_127 ;
}
for ( V_60 = 0 ; V_60 < V_45 ; V_60 ++ ) {
V_13 [ V_60 ] . V_13 . V_59 . V_128 = & V_120 . V_59 ;
V_13 [ V_60 ] . V_13 . V_129 = & V_130 ;
V_13 [ V_60 ] . V_13 . V_131 = & V_132 ;
V_13 [ V_60 ] . V_13 . V_133 = V_134 ;
V_13 [ V_60 ] . V_117 = V_60 ;
V_118 = F_45 ( & V_13 [ V_60 ] . V_13 ) ;
if ( ! V_118 )
V_13 [ V_60 ] . V_9 |= V_135 ;
#if 0
class_device_create_file(&socket[i].socket.dev,
&class_device_attr_info);
class_device_create_file(&socket[i].socket.dev,
&class_device_attr_exca);
#endif
}
if ( V_74 != 0 ) {
V_71 . V_136 = F_25 ;
V_71 . V_39 = 0 ;
F_26 ( & V_71 ) ;
V_71 . V_72 = V_73 + V_74 ;
F_27 ( & V_71 ) ;
}
return 0 ;
}
static void T_11 F_46 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_45 ; V_60 ++ )
if ( V_13 [ V_60 ] . V_9 & V_135 )
F_47 ( & V_13 [ V_60 ] . V_13 ) ;
F_44 ( & V_120 ) ;
if ( V_74 != 0 )
F_48 ( & V_71 ) ;
F_42 ( & V_119 ) ;
}
