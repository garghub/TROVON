T_1 void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
unsigned long * V_9 = ( unsigned long * ) V_2 ;
unsigned long V_10 , * V_11 , * V_12 , V_13 , V_14 , V_15 ;
T_2 V_16 ;
T_3 V_17 ;
T_4 V_18 , V_19 , V_20 , V_21 ;
T_5 * V_22 , V_23 , V_24 ;
void * V_25 ;
unsigned V_26 , V_27 , V_28 , V_29 ;
if ( F_2 ( V_2 ) )
goto V_30;
V_15 = ( unsigned long ) V_2 + sizeof( * V_2 ) ;
F_3 ( L_1 , V_2 -> V_22 , V_15 ) ;
if ( V_2 -> V_31 & V_32 )
asm volatile("or %0,epsw" : : "i"(EPSW_IE));
V_16 = F_4 () ;
F_5 ( V_33 ) ;
V_6 = F_6 ( V_2 -> V_22 ) ;
V_22 = ( V_34 * ) V_2 -> V_22 ;
if ( F_7 ( V_23 , V_22 ) != 0 )
goto V_35;
V_18 = V_23 ;
V_19 = 8 ;
for ( V_8 = V_36 ; V_8 -> V_37 [ 0 ] ; V_8 ++ ) {
V_27 = F_8 ( V_8 -> V_18 | V_8 -> V_38 ) ;
if ( V_27 <= 0 || V_27 > 31 )
continue;
V_27 = ( V_27 + 8 ) & ~ 7 ;
V_39:
if ( V_27 == V_19 ) {
if ( ( V_18 & V_8 -> V_38 ) == V_8 -> V_18 )
goto V_40;
} else if ( V_27 > V_19 ) {
V_20 = V_8 -> V_18 >> ( V_27 - V_19 ) ;
V_21 = V_8 -> V_38 >> ( V_27 - V_19 ) ;
if ( ( V_18 & V_21 ) != V_20 )
continue;
V_22 ++ ;
if ( F_7 ( V_23 , V_22 ) != 0 )
goto V_35;
V_18 = V_18 << 8 | V_23 ;
V_19 += 8 ;
goto V_39;
} else {
continue;
}
}
F_9 ( V_41 L_2 ,
V_2 -> V_22 , V_18 ) ;
V_42:
F_5 ( V_16 ) ;
if ( F_10 ( L_3 , V_2 , V_4 ) )
return;
V_30:
V_17 . V_43 = V_44 ;
V_17 . V_45 = 0 ;
V_17 . V_46 = V_47 ;
V_17 . V_48 = ( void * ) V_2 -> V_22 ;
F_11 ( V_44 , & V_17 , V_49 ) ;
return;
V_35:
F_9 ( V_41
L_4 ,
V_22 ) ;
goto V_42;
V_50:
F_9 ( V_41
L_5 ,
V_2 -> V_22 , V_18 ) ;
goto V_42;
V_51:
F_9 ( V_41
L_6 ,
V_2 -> V_22 , V_18 ) ;
goto V_42;
V_52:
F_9 ( V_41
L_7 ,
V_2 -> V_22 , V_18 , V_8 -> V_37 ) ;
goto V_42;
V_53:
F_5 ( V_16 ) ;
if ( V_6 ) {
V_2 -> V_22 = V_6 -> V_6 ;
return;
}
if ( F_10 ( L_8 , V_2 , V_4 ) )
return;
V_17 . V_43 = V_54 ;
V_17 . V_45 = 0 ;
V_17 . V_46 = 0 ;
V_17 . V_48 = ( void * ) V_2 -> V_22 ;
F_11 ( V_54 , & V_17 , V_49 ) ;
return;
V_40:
F_3 ( L_9 ,
V_2 -> V_22 , V_18 , V_8 -> V_18 , V_8 -> V_55 [ 0 ] , V_8 -> V_55 [ 1 ] ) ;
V_26 = V_56 [ V_8 -> V_57 ] . V_58 ;
F_12 ( V_26 > V_19 ) ;
if ( V_26 < V_19 ) {
V_26 = V_19 - V_26 ;
V_18 >>= V_26 ;
V_22 -= V_26 >> 3 ;
}
V_13 = 0 ;
V_28 = V_56 [ V_8 -> V_57 ] . V_28 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 += 8 ) {
V_22 ++ ;
if ( F_7 ( V_23 , V_22 ) != 0 )
goto V_35;
V_13 |= V_23 << V_29 ;
F_3 ( L_10 , V_22 , V_29 , V_23 ) ;
}
F_3 ( L_11 , V_13 ) ;
F_5 ( V_59 ) ;
if ( V_6 )
F_5 ( V_16 ) ;
V_26 = ( V_8 -> V_55 [ 0 ] ^ V_8 -> V_55 [ 1 ] ) & 0x80000000 ;
if ( ! V_26 ) {
F_9 ( V_41
L_12 ,
V_2 -> V_22 , V_18 ) ;
goto V_42;
}
if ( V_8 -> V_37 [ 3 ] == 0 ||
V_8 -> V_37 [ 4 ] == 'l' )
V_14 = V_24 = 4 ;
else if ( V_8 -> V_37 [ 3 ] == 'h' )
V_14 = V_24 = 2 ;
else
goto V_52;
if ( V_8 -> V_55 [ 0 ] & 0x80000000 ) {
if ( ! F_13 ( V_9 , V_15 ,
V_8 -> V_55 [ 0 ] , V_18 , V_13 ,
& V_25 , & V_12 , & V_14 ) )
goto V_50;
if ( ! F_14 ( V_9 , V_8 -> V_55 [ 1 ] , V_18 , V_13 ,
& V_11 ) )
goto V_51;
F_3 ( L_13 , V_24 , V_25 ) ;
if ( F_15 ( & V_10 , ( void * ) V_25 , V_24 ) != 0 )
goto V_53;
if ( V_8 -> V_55 [ 0 ] & 0x1000000 ) {
F_3 ( L_14 , V_14 ) ;
* V_12 += V_14 ;
}
* V_11 = V_10 ;
F_3 ( L_15 , V_10 ) ;
} else {
if ( ! F_14 ( V_9 , V_8 -> V_55 [ 0 ] , V_18 , V_13 ,
& V_11 ) )
goto V_51;
if ( ! F_13 ( V_9 , V_15 ,
V_8 -> V_55 [ 1 ] , V_18 , V_13 ,
& V_25 , & V_12 , & V_14 ) )
goto V_50;
V_10 = * V_11 ;
F_3 ( L_16 , V_24 , V_10 , V_25 ) ;
if ( F_16 ( ( void * ) V_25 , & V_10 , V_24 ) != 0 )
goto V_53;
if ( V_8 -> V_55 [ 1 ] & 0x1000000 )
* V_12 += V_14 ;
}
V_26 = V_56 [ V_8 -> V_57 ] . V_58 + V_56 [ V_8 -> V_57 ] . V_28 ;
V_2 -> V_22 += V_26 >> 3 ;
if ( V_8 -> V_57 == V_60 )
F_17 ( V_2 , V_18 ) ;
F_5 ( V_16 ) ;
}
static int F_13 ( unsigned long * V_9 , unsigned long V_15 ,
unsigned V_55 , unsigned V_18 ,
unsigned long V_13 ,
void * * V_61 , unsigned long * * V_62 ,
unsigned long * V_63 )
{
unsigned long * V_12 = NULL , V_25 = 0 , V_26 ;
if ( ! ( V_55 & 0x1000000 ) ) {
F_3 ( L_17 ) ;
* V_63 = 0 ;
V_63 = NULL ;
}
V_55 &= 0x00ffffff ;
do {
switch ( V_55 & 0xff ) {
case V_64 :
V_12 = & V_9 [ V_65 [ V_18 & 0x03 ] ] ;
V_25 += * V_12 ;
break;
case V_66 :
V_12 = & V_9 [ V_65 [ V_18 >> 2 & 0x03 ] ] ;
V_25 += * V_12 ;
break;
case V_67 :
V_12 = & V_9 [ V_65 [ V_18 >> 4 & 0x03 ] ] ;
V_25 += * V_12 ;
break;
case V_68 :
V_12 = & V_9 [ V_69 [ V_18 & 0x03 ] ] ;
V_25 += * V_12 ;
break;
case V_70 :
V_12 = & V_9 [ V_69 [ V_18 >> 2 & 0x03 ] ] ;
V_25 += * V_12 ;
break;
case V_71 :
V_12 = & V_9 [ V_69 [ V_18 >> 4 & 0x03 ] ] ;
V_25 += * V_12 ;
break;
case V_72 :
V_12 = & V_9 [ V_73 [ V_18 & 0x0f ] ] ;
V_25 += * V_12 ;
break;
case V_74 :
V_12 = & V_9 [ V_73 [ V_18 >> 2 & 0x0f ] ] ;
V_25 += * V_12 ;
break;
case V_75 :
V_12 = & V_9 [ V_73 [ V_18 >> 4 & 0x0f ] ] ;
V_25 += * V_12 ;
break;
case V_76 :
V_12 = & V_9 [ V_73 [ V_18 >> 8 & 0x0f ] ] ;
V_25 += * V_12 ;
break;
case V_77 :
V_12 = & V_9 [ V_73 [ V_18 >> 12 & 0x0f ] ] ;
V_25 += * V_12 ;
break;
case V_78 :
V_12 = & V_9 [ V_73 [ V_13 & 0x0f ] ] ;
V_25 += * V_12 ;
break;
case V_79 :
V_12 = & V_9 [ V_73 [ V_13 >> 4 & 0x0f ] ] ;
V_25 += * V_12 ;
break;
case V_80 :
V_25 += V_15 ;
break;
case V_81 :
case V_82 :
V_13 = ( long ) ( V_83 ) ( V_13 & 0xff ) ;
goto V_84;
case V_85 :
V_13 = ( long ) ( V_86 ) ( V_13 & 0xffff ) ;
goto V_84;
case V_87 :
V_26 = V_13 << 8 ;
asm("asr 8,%0" : "=r"(tmp) : "0"(tmp) : "cc");
V_13 = ( long ) V_26 ;
goto V_84;
case V_88 :
V_26 = V_18 >> 4 & 0x0f ;
V_26 <<= 28 ;
asm("asr 28,%0" : "=r"(tmp) : "0"(tmp) : "cc");
V_13 = ( long ) V_26 ;
goto V_84;
case V_89 :
V_13 &= 0x000000ff ;
goto V_84;
case V_90 :
V_13 &= 0x0000ffff ;
goto V_84;
case V_91 :
V_13 &= 0x00ffffff ;
goto V_84;
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_84:
F_3 ( L_18 , V_63 ? L_19 : L_20 , V_13 ) ;
if ( ! V_63 )
V_25 += V_13 ;
else
* V_63 = V_13 ;
break;
default:
F_18 () ;
return 0 ;
}
} while ( ( V_55 >>= 8 ) );
* V_61 = ( void * ) V_25 ;
* V_62 = V_12 ;
return 1 ;
}
static int F_14 ( unsigned long * V_9 , unsigned V_55 ,
unsigned V_18 , unsigned long V_13 ,
unsigned long * * V_96 )
{
V_55 &= 0x7fffffff ;
if ( V_55 & 0xffffff00 )
return 0 ;
switch ( V_55 & 0xff ) {
case V_64 :
* V_96 = & V_9 [ V_65 [ V_18 & 0x03 ] ] ;
break;
case V_66 :
* V_96 = & V_9 [ V_65 [ V_18 >> 2 & 0x03 ] ] ;
break;
case V_67 :
* V_96 = & V_9 [ V_65 [ V_18 >> 4 & 0x03 ] ] ;
break;
case V_68 :
* V_96 = & V_9 [ V_69 [ V_18 & 0x03 ] ] ;
break;
case V_70 :
* V_96 = & V_9 [ V_69 [ V_18 >> 2 & 0x03 ] ] ;
break;
case V_71 :
* V_96 = & V_9 [ V_69 [ V_18 >> 4 & 0x03 ] ] ;
break;
case V_72 :
* V_96 = & V_9 [ V_73 [ V_18 & 0x0f ] ] ;
break;
case V_74 :
* V_96 = & V_9 [ V_73 [ V_18 >> 2 & 0x0f ] ] ;
break;
case V_75 :
* V_96 = & V_9 [ V_73 [ V_18 >> 4 & 0x0f ] ] ;
break;
case V_76 :
* V_96 = & V_9 [ V_73 [ V_18 >> 8 & 0x0f ] ] ;
break;
case V_77 :
* V_96 = & V_9 [ V_73 [ V_18 >> 12 & 0x0f ] ] ;
break;
case V_78 :
* V_96 = & V_9 [ V_73 [ V_13 & 0x0f ] ] ;
break;
case V_79 :
* V_96 = & V_9 [ V_73 [ V_13 >> 4 & 0x0f ] ] ;
break;
case V_80 :
* V_96 = & V_9 [ V_97 >> 2 ] ;
break;
default:
F_18 () ;
return 0 ;
}
return 1 ;
}
static void F_17 ( struct V_1 * V_2 , T_4 V_18 )
{
unsigned long V_31 = V_2 -> V_31 ;
unsigned long V_98 ;
F_3 ( L_21 , V_18 , V_31 & 0xf ) ;
V_98 = ( ( V_31 >> 3 ) ^ V_31 >> 1 ) & 1 ;
switch ( V_18 & 0xf ) {
case 0x0 :
if ( V_98 )
goto V_99;
return;
case 0x1 :
if ( ! ( ( V_31 & V_100 ) | V_98 ) )
goto V_99;
return;
case 0x2 :
if ( ! V_98 )
goto V_99;
return;
case 0x3 :
if ( ( V_31 & V_100 ) | V_98 )
goto V_99;
return;
case 0x4 :
if ( V_31 & V_101 )
goto V_99;
return;
case 0x5 :
if ( ! ( V_31 & ( V_101 | V_100 ) ) )
goto V_99;
return;
case 0x6 :
if ( ! ( V_31 & V_101 ) )
goto V_99;
return;
case 0x7 :
if ( V_31 & ( V_101 | V_100 ) )
goto V_99;
return;
case 0x8 :
if ( V_31 & V_100 )
goto V_99;
return;
case 0x9 :
if ( ! ( V_31 & V_100 ) )
goto V_99;
return;
case 0xa :
goto V_99;
default:
F_18 () ;
}
V_99:
F_3 ( L_22 , V_2 -> V_102 ) ;
V_2 -> V_22 = V_2 -> V_102 - 4 ;
}
static int T_6 F_19 ( void )
{
register void * T_7 V_103 ( L_23 ) ;
register T_8 T_9 V_103 ( L_24 ) ;
void * V_104 = V_105 , * V_106 ;
T_8 V_26 , V_107 , V_108 ;
F_9 ( V_109 L_25 , V_104 ) ;
V_104 ++ ;
F_9 ( V_109 L_26 ) ;
V_106 = V_104 + 256 ;
asm volatile("mov (%0),%1" : "+a"(q), "=d"(x));
F_20 ( V_106 , == , V_104 + 256 ) ;
F_20 ( V_108 , == , 0x44332211 ) ;
F_9 ( V_109 L_27 ) ;
V_106 = V_104 ;
asm volatile("mov (256,%0),%1" : "+a"(q), "=d"(x));
F_20 ( V_106 , == , V_104 ) ;
F_20 ( V_108 , == , 0x44332211 ) ;
F_9 ( V_109 L_28 ) ;
V_26 = 256 ;
V_106 = V_104 ;
asm volatile("mov (%2,%0),%1" : "+a"(q), "=d"(x), "+d"(tmp));
F_20 ( V_106 , == , V_104 ) ;
F_20 ( V_108 , == , 0x44332211 ) ;
F_20 ( V_26 , == , 256 ) ;
F_9 ( V_109 L_29 ) ;
T_7 = V_104 ;
asm volatile("mov (256,%0),%1" : "+r"(r), "=r"(y));
F_20 ( T_7 , == , V_104 ) ;
F_20 ( T_9 , == , 0x44332211 ) ;
F_9 ( V_109 L_30 ) ;
T_7 = V_104 + 256 ;
asm volatile("mov (%0+),%1" : "+r"(r), "=r"(y));
F_20 ( T_7 , == , V_104 + 256 + 4 ) ;
F_20 ( T_9 , == , 0x44332211 ) ;
F_9 ( V_109 L_31 ) ;
T_7 = V_104 + 256 ;
asm volatile("mov (%0+,8),%1" : "+r"(r), "=r"(y));
F_20 ( T_7 , == , V_104 + 256 + 8 ) ;
F_20 ( T_9 , == , 0x44332211 ) ;
F_9 ( V_109 L_32 ) ;
asm volatile(
"add -16,sp \n"
"mov +0x11,%0 \n"
"movbu %0,(7,sp) \n"
"mov +0x22,%0 \n"
"movbu %0,(8,sp) \n"
"mov +0x33,%0 \n"
"movbu %0,(9,sp) \n"
"mov +0x44,%0 \n"
"movbu %0,(10,sp) \n"
"mov (7,sp),%1 \n"
"add +16,sp \n"
: "+a"(q), "=d"(x));
F_20 ( V_108 , == , 0x44332211 ) ;
F_9 ( V_109 L_33 ) ;
asm volatile(
"add -264,sp \n"
"mov +0x11,%0 \n"
"movbu %0,(259,sp) \n"
"mov +0x22,%0 \n"
"movbu %0,(260,sp) \n"
"mov +0x33,%0 \n"
"movbu %0,(261,sp) \n"
"mov +0x55,%0 \n"
"movbu %0,(262,sp) \n"
"mov (259,sp),%1 \n"
"add +264,sp \n"
: "+d"(tmp), "=d"(x));
F_20 ( V_108 , == , 0x55332211 ) ;
F_9 ( V_109 L_34 ) ;
asm volatile(
"add -264,sp \n"
"mov +0x11,%0 \n"
"movbu %0,(260,sp) \n"
"mov +0x22,%0 \n"
"movbu %0,(261,sp) \n"
"mov +0x33,%0 \n"
"movbu %0,(262,sp) \n"
"mov +0x55,%0 \n"
"movbu %0,(263,sp) \n"
"mov (260,sp),%1 \n"
"add +264,sp \n"
: "+d"(tmp), "=d"(x));
F_20 ( V_108 , == , 0x55332211 ) ;
F_9 ( V_109 L_35 ) ;
V_26 = 1 ;
V_107 = 2 ;
V_106 = V_104 + 256 ;
asm volatile(
"setlb \n"
"mov %2,%3 \n"
"mov %1,%2 \n"
"cmp +0,%1 \n"
"mov_lne (%0+,4),%1"
: "+r"(q), "+d"(tmp), "+d"(tmp2), "=d"(x)
:
: "cc");
F_20 ( V_106 , == , V_104 + 256 + 12 ) ;
F_20 ( V_108 , == , 0x44332211 ) ;
F_9 ( V_109 L_36 ) ;
V_26 = 1 ;
V_107 = 2 ;
V_106 = V_104 + 256 ;
asm volatile(
"setlb \n"
"mov %1,%3 \n"
"mov (%0+),%1 \n"
"cmp +0,%1 \n"
"lne "
: "+a"(q), "+d"(tmp), "+d"(tmp2), "=d"(x)
:
: "cc");
F_20 ( V_106 , == , V_104 + 256 + 8 ) ;
F_20 ( V_108 , == , 0x44332211 ) ;
F_9 ( V_109 L_37 ) ;
return 0 ;
}
