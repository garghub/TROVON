void
F_1 ( void * V_1 , int V_2 , int V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 , V_9 , V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 [ V_15 ] ;
unsigned long V_16 ;
struct V_17 * V_18 ;
V_18 = V_1 ;
if ( F_2 ( ! V_18 || ! V_5 ) )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_20 || ! V_7 -> V_19 . V_21 ) )
return;
V_9 = V_2 ;
V_10 = F_3 ( V_7 , V_18 , & V_2 , V_3 , V_5 , V_14 ) ;
if ( ! V_10 )
return;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
struct V_13 * V_22 = V_14 [ V_8 ] ;
if ( V_22 && V_22 -> V_23 . V_24 )
F_4 ( V_7 , V_18 , V_22 -> V_23 . V_24 ) ;
}
#if 0
terminate_note1(emu, key, chan, 0);
#endif
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
if ( V_14 [ V_8 ] == NULL )
continue;
V_12 = V_7 -> V_19 . V_20 ( V_7 , V_18 ) ;
if ( V_12 == NULL || V_12 -> V_26 < 0 )
continue;
if ( F_6 ( V_12 -> V_27 ) )
V_7 -> V_19 . V_28 ( V_12 ) ;
V_12 -> time = V_7 -> V_29 ++ ;
V_12 -> V_5 = V_5 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_2 = V_2 ;
V_12 -> V_30 = V_3 ;
V_12 -> V_31 = V_14 [ V_8 ] ;
if ( V_12 -> V_31 -> V_32 )
V_12 -> V_33 = V_12 -> V_31 -> V_32 -> V_33 ;
else
V_12 -> V_33 = NULL ;
F_7 ( V_12 ) ;
V_12 -> V_27 = V_34 ;
if ( V_7 -> V_19 . V_35 ) {
V_12 -> V_27 = V_36 ;
if ( V_7 -> V_19 . V_35 ( V_12 ) >= 0 )
V_12 -> V_27 = V_34 ;
}
}
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( V_12 -> V_27 == V_34 &&
V_12 -> V_5 == V_5 ) {
V_7 -> V_19 . V_21 ( V_12 ) ;
V_12 -> V_27 = V_39 ;
V_12 -> V_40 = V_41 ;
}
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
#ifdef F_9
if ( V_18 -> V_42 == V_43 ) {
struct V_44 * V_45 = V_5 -> V_46 ;
if ( V_45 ) {
V_45 -> V_47 [ V_48 ] = 0 ;
V_45 -> V_47 [ V_49 ] = 0 ;
}
}
#endif
}
void
F_10 ( void * V_1 , int V_2 , int V_3 , struct V_4 * V_5 )
{
int V_26 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
struct V_17 * V_18 ;
V_18 = V_1 ;
if ( F_2 ( ! V_18 || ! V_5 ) )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_50 ) )
return;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_37 ; V_26 ++ ) {
V_12 = & V_7 -> V_38 [ V_26 ] ;
if ( F_6 ( V_12 -> V_27 ) &&
V_12 -> V_5 == V_5 && V_12 -> V_9 == V_2 ) {
V_12 -> V_27 = V_51 ;
if ( V_12 -> V_40 == V_41 ) {
V_12 -> V_27 = V_52 ;
if ( ! V_7 -> V_53 ) {
V_7 -> V_54 . V_55 = V_41 + 1 ;
F_11 ( & V_7 -> V_54 ) ;
V_7 -> V_53 = 1 ;
}
} else
V_7 -> V_19 . V_50 ( V_12 ) ;
}
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void F_12 ( unsigned long V_56 )
{
struct V_6 * V_7 = (struct V_6 * ) V_56 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
int V_26 , V_57 = 0 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_37 ; V_26 ++ ) {
V_12 = & V_7 -> V_38 [ V_26 ] ;
if ( V_12 -> V_27 == V_52 ) {
if ( V_12 -> V_40 == V_41 )
V_57 ++ ;
else {
V_7 -> V_19 . V_50 ( V_12 ) ;
V_12 -> V_27 = V_51 ;
}
}
}
if ( V_57 ) {
V_7 -> V_54 . V_55 = V_41 + 1 ;
F_11 ( & V_7 -> V_54 ) ;
V_7 -> V_53 = 1 ;
} else
V_7 -> V_53 = 0 ;
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void
F_13 ( void * V_1 , int V_2 , int V_3 , struct V_4 * V_5 )
{
int V_26 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
struct V_17 * V_18 ;
V_18 = V_1 ;
if ( F_2 ( ! V_18 || ! V_5 ) )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_58 ) )
return;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_37 ; V_26 ++ ) {
V_12 = & V_7 -> V_38 [ V_26 ] ;
if ( V_12 -> V_27 == V_39 &&
V_12 -> V_5 == V_5 && V_12 -> V_9 == V_2 ) {
V_12 -> V_30 = V_3 ;
F_14 ( V_7 , V_12 , V_59 ) ;
}
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void
F_15 ( struct V_17 * V_18 , struct V_4 * V_5 , int V_58 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
int V_8 ;
unsigned long V_16 ;
if ( ! V_58 )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_58 ) )
return;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( V_12 -> V_5 == V_5 )
F_14 ( V_7 , V_12 , V_58 ) ;
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void
F_16 ( struct V_17 * V_18 , int V_58 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
int V_8 ;
unsigned long V_16 ;
if ( ! V_58 )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_58 ) )
return;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( V_12 -> V_18 == V_18 )
F_14 ( V_7 , V_12 , V_58 ) ;
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void
F_17 ( void * V_1 , int type , struct V_4 * V_5 )
{
struct V_17 * V_18 ;
V_18 = V_1 ;
if ( F_2 ( ! V_18 || ! V_5 ) )
return;
switch ( type ) {
case V_60 :
case V_61 :
F_15 ( V_18 , V_5 , V_59 ) ;
break;
case V_62 :
F_15 ( V_18 , V_5 , V_63 ) ;
break;
case V_64 :
#ifdef F_9
if ( V_5 -> V_65 [ type ] >= 64 )
F_18 ( V_18 , V_5 , V_66 , - 160 ,
V_67 ) ;
else
F_18 ( V_18 , V_5 , V_66 , 0 ,
V_68 ) ;
#endif
break;
case V_69 :
F_15 ( V_18 , V_5 , V_70 ) ;
break;
case V_71 :
case V_72 :
F_15 ( V_18 , V_5 ,
V_73 |
V_74 ) ;
break;
}
if ( V_18 -> V_75 . V_76 == V_77 ) {
F_19 ( V_18 , V_5 , type ) ;
}
}
static void
F_20 ( struct V_6 * V_7 , int V_2 , struct V_4 * V_5 , int free )
{
int V_8 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( F_6 ( V_12 -> V_27 ) && V_12 -> V_5 == V_5 &&
V_12 -> V_9 == V_2 )
F_21 ( V_7 , V_12 , free ) ;
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void
F_22 ( void * V_1 , int V_2 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_17 * V_18 ;
V_18 = V_1 ;
if ( F_2 ( ! V_18 || ! V_5 ) )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_28 ) )
return;
F_20 ( V_7 , V_2 , V_5 , 1 ) ;
}
void
F_23 ( struct V_6 * V_7 )
{
int V_8 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( F_6 ( V_12 -> V_27 ) )
F_21 ( V_7 , V_12 , 0 ) ;
if ( V_12 -> V_27 == V_36 ) {
if ( V_7 -> V_19 . V_78 )
V_7 -> V_19 . V_78 ( V_12 ) ;
if ( V_7 -> V_19 . V_79 )
V_7 -> V_19 . V_79 ( V_7 , V_8 ) ;
}
V_12 -> time = 0 ;
}
V_7 -> V_29 = 0 ;
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void
F_24 ( struct V_17 * V_18 )
{
int V_8 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
if ( F_2 ( ! V_18 ) )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_28 ) )
return;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( F_6 ( V_12 -> V_27 ) &&
V_12 -> V_18 == V_18 )
F_21 ( V_7 , V_12 , 0 ) ;
if ( V_12 -> V_27 == V_36 ) {
if ( V_7 -> V_19 . V_78 )
V_7 -> V_19 . V_78 ( V_12 ) ;
if ( V_7 -> V_19 . V_79 )
V_7 -> V_19 . V_79 ( V_7 , V_8 ) ;
}
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
static void
F_4 ( struct V_6 * V_7 , struct V_17 * V_18 , int V_80 )
{
struct V_11 * V_12 ;
int V_8 ;
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( F_6 ( V_12 -> V_27 ) && V_12 -> V_18 == V_18 &&
V_12 -> V_81 . V_24 == V_80 ) {
F_21 ( V_7 , V_12 , 0 ) ;
}
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
static void
F_21 ( struct V_6 * V_7 , struct V_11 * V_12 , int free )
{
V_7 -> V_19 . V_28 ( V_12 ) ;
V_12 -> time = V_7 -> V_29 ++ ;
V_12 -> V_5 = NULL ;
V_12 -> V_18 = NULL ;
V_12 -> V_31 = NULL ;
V_12 -> V_33 = NULL ;
V_12 -> V_27 = V_36 ;
if ( free && V_7 -> V_19 . V_78 )
V_7 -> V_19 . V_78 ( V_12 ) ;
}
static void
F_14 ( struct V_6 * V_7 , struct V_11 * V_12 , int V_58 )
{
if ( ! F_6 ( V_12 -> V_27 ) )
return;
if ( V_12 -> V_5 == NULL || V_12 -> V_18 == NULL )
return;
if ( V_58 & V_59 )
F_25 ( V_12 ) ;
if ( V_58 & V_70 )
F_26 ( V_12 ) ;
if ( V_58 & V_63 ) {
if ( ! F_27 ( V_12 ) && ( V_58 == V_63 ) )
return;
}
V_7 -> V_19 . V_58 ( V_12 , V_58 ) ;
}
static void
F_7 ( struct V_11 * V_12 )
{
struct V_82 * V_83 ;
int V_84 ;
V_12 -> V_81 = V_12 -> V_31 -> V_23 ;
#ifdef F_9
F_28 ( V_12 ) ;
#endif
V_12 -> V_85 = - 1 ;
V_12 -> V_86 = - 1 ;
V_12 -> V_87 = - 1 ;
F_25 ( V_12 ) ;
F_26 ( V_12 ) ;
F_27 ( V_12 ) ;
V_83 = & V_12 -> V_81 . V_83 ;
if ( F_29 ( V_83 -> V_88 ) >= 0x80 && V_83 -> V_89 >= 0x8000 ) {
V_83 -> V_89 = 0xbfff ;
V_84 = ( F_30 ( V_83 -> V_90 ) << 4 ) + V_12 -> V_87 ;
if ( V_84 > 0xffff )
V_84 = 0xffff ;
V_12 -> V_91 = V_83 -> V_92 + F_29 ( V_83 -> V_90 ) ;
F_31 ( V_12 -> V_91 , 0 , 255 ) ;
V_12 -> V_91 <<= 8 ;
} else {
V_12 -> V_91 = V_83 -> V_92 ;
V_12 -> V_91 <<= 8 ;
V_84 = V_12 -> V_87 ;
}
if ( V_84 != 0xffff ) {
V_12 -> V_93 = 1 << ( V_84 >> 12 ) ;
if ( V_84 & 0x800 ) V_12 -> V_93 += ( V_12 -> V_93 * 0x102e ) / 0x2710 ;
if ( V_84 & 0x400 ) V_12 -> V_93 += ( V_12 -> V_93 * 0x764 ) / 0x2710 ;
if ( V_84 & 0x200 ) V_12 -> V_93 += ( V_12 -> V_93 * 0x389 ) / 0x2710 ;
V_12 -> V_93 += ( V_12 -> V_93 >> 1 ) ;
if ( V_12 -> V_93 > 0xffff ) V_12 -> V_93 = 0xffff ;
} else
V_12 -> V_93 = 0xffff ;
if ( F_29 ( V_83 -> V_88 ) >= 0x80 ) {
V_83 -> V_88 &= ~ 0xff ;
V_83 -> V_88 |= 0x7f ;
}
V_12 -> V_94 = 0 ;
#if 0
if (LO_BYTE(parm->volatkhld) >= 0x80 && parm->voldelay >= 0x8000) {
parm->voldelay = 0xbfff;
vp->vtarget = voltarget[vp->avol % 0x10] >> (vp->avol >> 4);
}
#endif
if ( F_29 ( V_83 -> V_95 ) >= 0x80 ) {
V_83 -> V_95 &= ~ 0xff ;
V_83 -> V_95 |= 0x7f ;
}
}
static int
F_27 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
int V_96 ;
if ( V_12 -> V_81 . V_97 > 0 )
V_96 = 255 - ( int ) V_12 -> V_81 . V_97 * 2 ;
else {
V_96 = V_5 -> V_65 [ V_62 ] - 64 ;
if ( V_12 -> V_81 . V_96 >= 0 )
V_96 += V_12 -> V_81 . V_96 - 64 ;
V_96 = 127 - ( int ) V_96 * 2 ;
}
F_31 ( V_96 , 0 , 255 ) ;
if ( V_12 -> V_7 -> V_98 ) {
if ( V_96 != V_12 -> V_85 ) {
V_12 -> V_85 = V_96 ;
if ( V_96 == 0 )
V_12 -> V_99 = 0xff ;
else
V_12 -> V_99 = ( - V_96 ) & 0xff ;
return 1 ;
} else
return 0 ;
} else {
if ( V_12 -> V_85 != ( int ) V_100 [ V_96 ] ) {
V_12 -> V_85 = V_100 [ V_96 ] ;
V_12 -> V_99 = V_100 [ 255 - V_96 ] ;
return 1 ;
}
return 0 ;
}
}
static int
F_25 ( struct V_11 * V_12 )
{
int V_101 ;
int V_102 , V_103 , V_104 ;
struct V_4 * V_5 = V_12 -> V_5 ;
struct V_17 * V_18 = V_12 -> V_18 ;
V_103 = V_5 -> V_65 [ V_61 ] ;
F_32 ( V_12 -> V_30 , 127 ) ;
F_31 ( V_103 , 0 , 127 ) ;
if ( V_18 -> V_42 == V_43 ) {
V_102 = V_5 -> V_65 [ V_60 ] ;
V_101 = ( V_12 -> V_30 * V_102 * V_103 ) / ( 127 * 127 ) ;
V_101 = V_101 * V_12 -> V_81 . V_105 / 127 ;
F_31 ( V_101 , 0 , 127 ) ;
V_101 = V_106 [ V_101 ] ;
} else {
V_102 = V_5 -> V_65 [ V_60 ] * V_12 -> V_81 . V_105 / 127 ;
F_31 ( V_102 , 0 , 127 ) ;
V_101 = V_107 [ V_102 ] + V_108 [ V_12 -> V_30 ] ;
V_101 = ( V_101 * 8 ) / 3 ;
V_101 += V_12 -> V_81 . V_109 ;
V_101 += ( ( 0x100 - V_101 ) * V_110 [ V_103 ] ) / 128 ;
}
V_104 = V_18 -> V_75 . V_111 ;
F_31 ( V_104 , 0 , 127 ) ;
V_101 += V_106 [ V_104 ] ;
V_101 += V_18 -> V_112 ;
#ifdef F_9
if ( V_5 -> V_46 ) {
struct V_44 * V_45 = V_5 -> V_46 ;
V_101 += V_45 -> V_113 [ V_114 ] ;
}
#endif
F_31 ( V_101 , 0 , 255 ) ;
if ( V_12 -> V_86 == V_101 )
return 0 ;
V_12 -> V_86 = V_101 ;
if ( ! F_33 ( F_34 ( V_18 , V_5 ) )
&& F_29 ( V_12 -> V_81 . V_83 . V_95 ) < 0x7d ) {
int V_115 ;
if ( V_12 -> V_30 < 70 )
V_115 = 70 ;
else
V_115 = V_12 -> V_30 ;
V_12 -> V_116 = ( V_115 * V_12 -> V_81 . V_83 . V_92 + 0xa0 ) >> 7 ;
} else {
V_12 -> V_116 = V_12 -> V_81 . V_83 . V_92 ;
}
return 1 ;
}
static int
F_26 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
int V_117 ;
if ( V_12 -> V_81 . V_118 >= 0 ) {
V_117 = ( V_12 -> V_81 . V_118 - V_12 -> V_81 . V_119 ) * 4096 / 12 ;
} else {
V_117 = ( V_12 -> V_2 - V_12 -> V_81 . V_119 ) * 4096 / 12 ;
}
V_117 = ( V_117 * V_12 -> V_81 . V_120 ) / 100 ;
V_117 += V_12 -> V_81 . V_121 * 4096 / 1200 ;
if ( V_5 -> V_122 != 0 ) {
V_117 += V_5 -> V_122 * V_5 -> V_123 / 3072 ;
}
V_117 += V_5 -> V_124 * 4096 / ( 12 * 128 ) ;
V_117 += V_5 -> V_125 / 24 ;
#ifdef F_9
if ( V_5 -> V_46 ) {
struct V_44 * V_45 = V_5 -> V_46 ;
if ( V_45 -> V_47 [ V_126 ] )
V_117 += V_45 -> V_113 [ V_126 ] ;
}
#endif
V_117 += 0xe000 + V_12 -> V_81 . V_127 ;
V_117 += V_12 -> V_7 -> V_128 ;
F_31 ( V_117 , 0 , 0xffff ) ;
if ( V_117 == V_12 -> V_87 )
return 0 ;
V_12 -> V_87 = V_117 ;
return 1 ;
}
static int
F_34 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
int V_113 ;
switch ( V_18 -> V_75 . V_76 ) {
case V_77 :
V_113 = V_5 -> V_65 [ V_129 ] ;
if ( V_113 == 127 )
return 128 ;
return V_5 -> V_65 [ V_130 ] ;
case V_131 :
if ( V_5 -> V_132 )
return 128 ;
return V_5 -> V_65 [ V_129 ] ;
default:
if ( V_5 -> V_132 )
return 128 ;
return V_5 -> V_65 [ V_129 ] ;
}
}
static int
F_3 ( struct V_6 * V_7 , struct V_17 * V_18 ,
int * V_133 , int V_3 , struct V_4 * V_5 ,
struct V_13 * * V_14 )
{
int V_134 , V_135 , V_136 , V_137 ;
V_135 = F_34 ( V_18 , V_5 ) ;
V_134 = V_5 -> V_138 ;
if ( F_33 ( V_135 ) ) {
V_136 = V_18 -> V_139 [ V_140 ] ;
V_137 = V_135 ;
} else {
V_136 = V_134 ;
V_137 = V_18 -> V_139 [ V_141 ] ;
}
return F_35 ( V_7 -> V_142 , V_133 , V_3 , V_134 , V_135 ,
V_136 , V_137 ,
V_14 , V_15 ) ;
}
void
F_36 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
int V_8 ;
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
V_12 -> V_26 = - 1 ;
V_12 -> V_27 = V_36 ;
V_12 -> V_5 = NULL ;
V_12 -> V_18 = NULL ;
V_12 -> time = 0 ;
V_12 -> V_7 = V_7 ;
V_12 -> V_143 = V_7 -> V_143 ;
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void F_37 ( struct V_6 * V_7 , int V_144 )
{
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
if ( V_7 -> V_38 [ V_144 ] . V_27 == V_36 )
V_7 -> V_38 [ V_144 ] . V_27 = V_145 ;
else
F_38 ( V_146
L_1 ,
V_144 , V_7 -> V_38 [ V_144 ] . V_27 ) ;
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void F_39 ( struct V_6 * V_7 , int V_144 )
{
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
if ( V_7 -> V_38 [ V_144 ] . V_27 == V_145 )
V_7 -> V_38 [ V_144 ] . V_27 = V_36 ;
else
F_38 ( V_146
L_2 ,
V_144 , V_7 -> V_38 [ V_144 ] . V_27 ) ;
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
