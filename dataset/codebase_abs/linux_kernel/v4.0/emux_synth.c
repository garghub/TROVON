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
F_11 ( & V_7 -> V_54 , V_41 + 1 ) ;
V_7 -> V_53 = 1 ;
}
} else
V_7 -> V_19 . V_50 ( V_12 ) ;
}
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void F_12 ( unsigned long V_55 )
{
struct V_6 * V_7 = (struct V_6 * ) V_55 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
int V_26 , V_56 = 0 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_37 ; V_26 ++ ) {
V_12 = & V_7 -> V_38 [ V_26 ] ;
if ( V_12 -> V_27 == V_52 ) {
if ( V_12 -> V_40 == V_41 )
V_56 ++ ;
else {
V_7 -> V_19 . V_50 ( V_12 ) ;
V_12 -> V_27 = V_51 ;
}
}
}
if ( V_56 ) {
F_11 ( & V_7 -> V_54 , V_41 + 1 ) ;
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
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_57 ) )
return;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_37 ; V_26 ++ ) {
V_12 = & V_7 -> V_38 [ V_26 ] ;
if ( V_12 -> V_27 == V_39 &&
V_12 -> V_5 == V_5 && V_12 -> V_9 == V_2 ) {
V_12 -> V_30 = V_3 ;
F_14 ( V_7 , V_12 , V_58 ) ;
}
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void
F_15 ( struct V_17 * V_18 , struct V_4 * V_5 , int V_57 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
int V_8 ;
unsigned long V_16 ;
if ( ! V_57 )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_57 ) )
return;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( V_12 -> V_5 == V_5 )
F_14 ( V_7 , V_12 , V_57 ) ;
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void
F_16 ( struct V_17 * V_18 , int V_57 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
int V_8 ;
unsigned long V_16 ;
if ( ! V_57 )
return;
V_7 = V_18 -> V_7 ;
if ( F_2 ( ! V_7 || ! V_7 -> V_19 . V_57 ) )
return;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( V_12 -> V_18 == V_18 )
F_14 ( V_7 , V_12 , V_57 ) ;
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
case V_59 :
case V_60 :
F_15 ( V_18 , V_5 , V_58 ) ;
break;
case V_61 :
F_15 ( V_18 , V_5 , V_62 ) ;
break;
case V_63 :
#ifdef F_9
if ( V_5 -> V_64 [ type ] >= 64 )
F_18 ( V_18 , V_5 , V_65 , - 160 ,
V_66 ) ;
else
F_18 ( V_18 , V_5 , V_65 , 0 ,
V_67 ) ;
#endif
break;
case V_68 :
F_15 ( V_18 , V_5 , V_69 ) ;
break;
case V_70 :
case V_71 :
F_15 ( V_18 , V_5 ,
V_72 |
V_73 ) ;
break;
}
if ( V_18 -> V_74 . V_75 == V_76 ) {
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
if ( V_7 -> V_19 . V_77 )
V_7 -> V_19 . V_77 ( V_12 ) ;
if ( V_7 -> V_19 . V_78 )
V_7 -> V_19 . V_78 ( V_7 , V_8 ) ;
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
if ( V_7 -> V_19 . V_77 )
V_7 -> V_19 . V_77 ( V_12 ) ;
if ( V_7 -> V_19 . V_78 )
V_7 -> V_19 . V_78 ( V_7 , V_8 ) ;
}
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
static void
F_4 ( struct V_6 * V_7 , struct V_17 * V_18 , int V_79 )
{
struct V_11 * V_12 ;
int V_8 ;
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_37 ; V_8 ++ ) {
V_12 = & V_7 -> V_38 [ V_8 ] ;
if ( F_6 ( V_12 -> V_27 ) && V_12 -> V_18 == V_18 &&
V_12 -> V_80 . V_24 == V_79 ) {
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
if ( free && V_7 -> V_19 . V_77 )
V_7 -> V_19 . V_77 ( V_12 ) ;
}
static void
F_14 ( struct V_6 * V_7 , struct V_11 * V_12 , int V_57 )
{
if ( ! F_6 ( V_12 -> V_27 ) )
return;
if ( V_12 -> V_5 == NULL || V_12 -> V_18 == NULL )
return;
if ( V_57 & V_58 )
F_25 ( V_12 ) ;
if ( V_57 & V_69 )
F_26 ( V_12 ) ;
if ( V_57 & V_62 ) {
if ( ! F_27 ( V_12 ) && ( V_57 == V_62 ) )
return;
}
V_7 -> V_19 . V_57 ( V_12 , V_57 ) ;
}
static void
F_7 ( struct V_11 * V_12 )
{
struct V_81 * V_82 ;
int V_83 ;
V_12 -> V_80 = V_12 -> V_31 -> V_23 ;
#ifdef F_9
F_28 ( V_12 ) ;
#endif
V_12 -> V_84 = - 1 ;
V_12 -> V_85 = - 1 ;
V_12 -> V_86 = - 1 ;
F_25 ( V_12 ) ;
F_26 ( V_12 ) ;
F_27 ( V_12 ) ;
V_82 = & V_12 -> V_80 . V_82 ;
if ( F_29 ( V_82 -> V_87 ) >= 0x80 && V_82 -> V_88 >= 0x8000 ) {
V_82 -> V_88 = 0xbfff ;
V_83 = ( F_30 ( V_82 -> V_89 ) << 4 ) + V_12 -> V_86 ;
if ( V_83 > 0xffff )
V_83 = 0xffff ;
V_12 -> V_90 = V_82 -> V_91 + F_29 ( V_82 -> V_89 ) ;
F_31 ( V_12 -> V_90 , 0 , 255 ) ;
V_12 -> V_90 <<= 8 ;
} else {
V_12 -> V_90 = V_82 -> V_91 ;
V_12 -> V_90 <<= 8 ;
V_83 = V_12 -> V_86 ;
}
if ( V_83 != 0xffff ) {
V_12 -> V_92 = 1 << ( V_83 >> 12 ) ;
if ( V_83 & 0x800 ) V_12 -> V_92 += ( V_12 -> V_92 * 0x102e ) / 0x2710 ;
if ( V_83 & 0x400 ) V_12 -> V_92 += ( V_12 -> V_92 * 0x764 ) / 0x2710 ;
if ( V_83 & 0x200 ) V_12 -> V_92 += ( V_12 -> V_92 * 0x389 ) / 0x2710 ;
V_12 -> V_92 += ( V_12 -> V_92 >> 1 ) ;
if ( V_12 -> V_92 > 0xffff ) V_12 -> V_92 = 0xffff ;
} else
V_12 -> V_92 = 0xffff ;
if ( F_29 ( V_82 -> V_87 ) >= 0x80 ) {
V_82 -> V_87 &= ~ 0xff ;
V_82 -> V_87 |= 0x7f ;
}
V_12 -> V_93 = 0 ;
#if 0
if (LO_BYTE(parm->volatkhld) >= 0x80 && parm->voldelay >= 0x8000) {
parm->voldelay = 0xbfff;
vp->vtarget = voltarget[vp->avol % 0x10] >> (vp->avol >> 4);
}
#endif
if ( F_29 ( V_82 -> V_94 ) >= 0x80 ) {
V_82 -> V_94 &= ~ 0xff ;
V_82 -> V_94 |= 0x7f ;
}
}
static int
F_27 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
int V_95 ;
if ( V_12 -> V_80 . V_96 > 0 )
V_95 = 255 - ( int ) V_12 -> V_80 . V_96 * 2 ;
else {
V_95 = V_5 -> V_64 [ V_61 ] - 64 ;
if ( V_12 -> V_80 . V_95 >= 0 )
V_95 += V_12 -> V_80 . V_95 - 64 ;
V_95 = 127 - ( int ) V_95 * 2 ;
}
F_31 ( V_95 , 0 , 255 ) ;
if ( V_12 -> V_7 -> V_97 ) {
if ( V_95 != V_12 -> V_84 ) {
V_12 -> V_84 = V_95 ;
if ( V_95 == 0 )
V_12 -> V_98 = 0xff ;
else
V_12 -> V_98 = ( - V_95 ) & 0xff ;
return 1 ;
} else
return 0 ;
} else {
if ( V_12 -> V_84 != ( int ) V_99 [ V_95 ] ) {
V_12 -> V_84 = V_99 [ V_95 ] ;
V_12 -> V_98 = V_99 [ 255 - V_95 ] ;
return 1 ;
}
return 0 ;
}
}
static int
F_25 ( struct V_11 * V_12 )
{
int V_100 ;
int V_101 , V_102 , V_103 ;
struct V_4 * V_5 = V_12 -> V_5 ;
struct V_17 * V_18 = V_12 -> V_18 ;
V_102 = V_5 -> V_64 [ V_60 ] ;
F_32 ( V_12 -> V_30 , 127 ) ;
F_31 ( V_102 , 0 , 127 ) ;
if ( V_18 -> V_42 == V_43 ) {
V_101 = V_5 -> V_64 [ V_59 ] ;
V_100 = ( V_12 -> V_30 * V_101 * V_102 ) / ( 127 * 127 ) ;
V_100 = V_100 * V_12 -> V_80 . V_104 / 127 ;
F_31 ( V_100 , 0 , 127 ) ;
V_100 = V_105 [ V_100 ] ;
} else {
V_101 = V_5 -> V_64 [ V_59 ] * V_12 -> V_80 . V_104 / 127 ;
F_31 ( V_101 , 0 , 127 ) ;
V_100 = V_106 [ V_101 ] + V_107 [ V_12 -> V_30 ] ;
V_100 = ( V_100 * 8 ) / 3 ;
V_100 += V_12 -> V_80 . V_108 ;
V_100 += ( ( 0x100 - V_100 ) * V_109 [ V_102 ] ) / 128 ;
}
V_103 = V_18 -> V_74 . V_110 ;
F_31 ( V_103 , 0 , 127 ) ;
V_100 += V_105 [ V_103 ] ;
V_100 += V_18 -> V_111 ;
#ifdef F_9
if ( V_5 -> V_46 ) {
struct V_44 * V_45 = V_5 -> V_46 ;
V_100 += V_45 -> V_112 [ V_113 ] ;
}
#endif
F_31 ( V_100 , 0 , 255 ) ;
if ( V_12 -> V_85 == V_100 )
return 0 ;
V_12 -> V_85 = V_100 ;
if ( ! F_33 ( F_34 ( V_18 , V_5 ) )
&& F_29 ( V_12 -> V_80 . V_82 . V_94 ) < 0x7d ) {
int V_114 ;
if ( V_12 -> V_30 < 70 )
V_114 = 70 ;
else
V_114 = V_12 -> V_30 ;
V_12 -> V_115 = ( V_114 * V_12 -> V_80 . V_82 . V_91 + 0xa0 ) >> 7 ;
} else {
V_12 -> V_115 = V_12 -> V_80 . V_82 . V_91 ;
}
return 1 ;
}
static int
F_26 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
int V_116 ;
if ( V_12 -> V_80 . V_117 >= 0 ) {
V_116 = ( V_12 -> V_80 . V_117 - V_12 -> V_80 . V_118 ) * 4096 / 12 ;
} else {
V_116 = ( V_12 -> V_2 - V_12 -> V_80 . V_118 ) * 4096 / 12 ;
}
V_116 = ( V_116 * V_12 -> V_80 . V_119 ) / 100 ;
V_116 += V_12 -> V_80 . V_120 * 4096 / 1200 ;
if ( V_5 -> V_121 != 0 ) {
V_116 += V_5 -> V_121 * V_5 -> V_122 / 3072 ;
}
V_116 += V_5 -> V_123 * 4096 / ( 12 * 128 ) ;
V_116 += V_5 -> V_124 / 24 ;
#ifdef F_9
if ( V_5 -> V_46 ) {
struct V_44 * V_45 = V_5 -> V_46 ;
if ( V_45 -> V_47 [ V_125 ] )
V_116 += V_45 -> V_112 [ V_125 ] ;
}
#endif
V_116 += 0xe000 + V_12 -> V_80 . V_126 ;
V_116 += V_12 -> V_7 -> V_127 ;
F_31 ( V_116 , 0 , 0xffff ) ;
if ( V_116 == V_12 -> V_86 )
return 0 ;
V_12 -> V_86 = V_116 ;
return 1 ;
}
static int
F_34 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
int V_112 ;
switch ( V_18 -> V_74 . V_75 ) {
case V_76 :
V_112 = V_5 -> V_64 [ V_128 ] ;
if ( V_112 == 127 )
return 128 ;
return V_5 -> V_64 [ V_129 ] ;
case V_130 :
if ( V_5 -> V_131 )
return 128 ;
return V_5 -> V_64 [ V_128 ] ;
default:
if ( V_5 -> V_131 )
return 128 ;
return V_5 -> V_64 [ V_128 ] ;
}
}
static int
F_3 ( struct V_6 * V_7 , struct V_17 * V_18 ,
int * V_132 , int V_3 , struct V_4 * V_5 ,
struct V_13 * * V_14 )
{
int V_133 , V_134 , V_135 , V_136 ;
V_134 = F_34 ( V_18 , V_5 ) ;
V_133 = V_5 -> V_137 ;
if ( F_33 ( V_134 ) ) {
V_135 = V_18 -> V_138 [ V_139 ] ;
V_136 = V_134 ;
} else {
V_135 = V_133 ;
V_136 = V_18 -> V_138 [ V_140 ] ;
}
return F_35 ( V_7 -> V_141 , V_132 , V_3 , V_133 , V_134 ,
V_135 , V_136 ,
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
V_12 -> V_142 = V_7 -> V_142 ;
}
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void F_37 ( struct V_6 * V_7 , int V_143 )
{
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
if ( V_7 -> V_38 [ V_143 ] . V_27 == V_36 )
V_7 -> V_38 [ V_143 ] . V_27 = V_144 ;
else
F_38 ( V_145
L_1 ,
V_143 , V_7 -> V_38 [ V_143 ] . V_27 ) ;
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
void F_39 ( struct V_6 * V_7 , int V_143 )
{
unsigned long V_16 ;
F_5 ( & V_7 -> V_25 , V_16 ) ;
if ( V_7 -> V_38 [ V_143 ] . V_27 == V_144 )
V_7 -> V_38 [ V_143 ] . V_27 = V_36 ;
else
F_38 ( V_145
L_2 ,
V_143 , V_7 -> V_38 [ V_143 ] . V_27 ) ;
F_8 ( & V_7 -> V_25 , V_16 ) ;
}
