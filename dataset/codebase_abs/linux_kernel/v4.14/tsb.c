static inline unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
V_1 >>= V_2 ;
return V_1 & ( V_3 - 1 ) ;
}
static inline int F_2 ( unsigned long V_4 , unsigned long V_1 )
{
return ( V_4 == ( V_1 >> 22 ) ) ;
}
static void F_3 ( unsigned long V_5 , unsigned long V_6 )
{
unsigned long V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_9 * V_10 = & V_11 [ V_7 ] ;
unsigned long V_12 = V_7 << 13 ;
V_12 |= ( V_10 -> V_4 << 22 ) ;
if ( V_12 >= V_5 && V_12 < V_6 )
V_10 -> V_4 = ( 1UL << V_13 ) ;
}
}
void F_4 ( unsigned long V_5 , unsigned long V_6 )
{
unsigned long V_14 ;
if ( ( V_6 - V_5 ) >> V_15 >= 2 * V_8 )
return F_3 ( V_5 , V_6 ) ;
for ( V_14 = V_5 ; V_14 < V_6 ; V_14 += V_16 ) {
unsigned long V_17 = F_1 ( V_14 , V_15 ,
V_8 ) ;
struct V_9 * V_10 = & V_11 [ V_17 ] ;
if ( F_2 ( V_10 -> V_4 , V_14 ) )
V_10 -> V_4 = ( 1UL << V_13 ) ;
}
}
static void F_5 ( unsigned long V_9 , unsigned long V_14 ,
unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 , V_10 , V_17 ;
V_14 &= ~ 0x1UL ;
V_17 = F_1 ( V_14 , V_2 , V_3 ) ;
V_10 = V_9 + ( V_17 * sizeof( struct V_9 ) ) ;
V_4 = ( V_14 >> 22UL ) ;
F_6 ( V_10 , V_4 ) ;
}
static void F_7 ( struct V_18 * V_19 , unsigned long V_2 ,
unsigned long V_9 , unsigned long V_3 )
{
unsigned long V_20 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_21 ; V_20 ++ )
F_5 ( V_9 , V_19 -> V_22 [ V_20 ] , V_2 , V_3 ) ;
}
static void F_8 ( unsigned long V_9 , unsigned long V_14 ,
unsigned long V_2 ,
unsigned long V_3 ,
unsigned int V_23 )
{
unsigned int V_24 ;
unsigned int V_20 ;
V_24 = 1 << ( V_23 - V_2 ) ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ )
F_5 ( V_9 , V_14 + ( V_20 << V_2 ) , V_2 ,
V_3 ) ;
}
static void F_9 ( struct V_18 * V_19 , unsigned long V_2 ,
unsigned long V_9 , unsigned long V_3 ,
unsigned int V_23 )
{
unsigned long V_20 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_21 ; V_20 ++ )
F_8 ( V_9 , V_19 -> V_22 [ V_20 ] , V_2 ,
V_3 , V_23 ) ;
}
void F_10 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = V_19 -> V_26 ;
unsigned long V_3 , V_27 , V_28 ;
F_11 ( & V_26 -> V_29 . V_30 , V_28 ) ;
if ( V_19 -> V_23 < V_31 ) {
V_27 = ( unsigned long ) V_26 -> V_29 . V_32 [ V_33 ] . V_9 ;
V_3 = V_26 -> V_29 . V_32 [ V_33 ] . V_34 ;
if ( V_35 == V_36 || V_35 == V_37 )
V_27 = F_12 ( V_27 ) ;
if ( V_19 -> V_23 == V_15 )
F_7 ( V_19 , V_15 , V_27 , V_3 ) ;
#if F_13 ( V_38 )
else
F_9 ( V_19 , V_15 , V_27 , V_3 ,
V_19 -> V_23 ) ;
#endif
}
#if F_13 ( V_38 ) || F_13 ( V_39 )
else if ( V_26 -> V_29 . V_32 [ V_40 ] . V_9 ) {
V_27 = ( unsigned long ) V_26 -> V_29 . V_32 [ V_40 ] . V_9 ;
V_3 = V_26 -> V_29 . V_32 [ V_40 ] . V_34 ;
if ( V_35 == V_36 || V_35 == V_37 )
V_27 = F_12 ( V_27 ) ;
F_9 ( V_19 , V_31 , V_27 , V_3 ,
V_19 -> V_23 ) ;
}
#endif
F_14 ( & V_26 -> V_29 . V_30 , V_28 ) ;
}
void F_15 ( struct V_25 * V_26 , unsigned long V_1 ,
unsigned int V_23 )
{
unsigned long V_3 , V_27 , V_28 ;
F_11 ( & V_26 -> V_29 . V_30 , V_28 ) ;
if ( V_23 < V_31 ) {
V_27 = ( unsigned long ) V_26 -> V_29 . V_32 [ V_33 ] . V_9 ;
V_3 = V_26 -> V_29 . V_32 [ V_33 ] . V_34 ;
if ( V_35 == V_36 || V_35 == V_37 )
V_27 = F_12 ( V_27 ) ;
if ( V_23 == V_15 )
F_5 ( V_27 , V_1 , V_15 ,
V_3 ) ;
#if F_13 ( V_38 )
else
F_8 ( V_27 , V_1 , V_15 ,
V_3 , V_23 ) ;
#endif
}
#if F_13 ( V_38 ) || F_13 ( V_39 )
else if ( V_26 -> V_29 . V_32 [ V_40 ] . V_9 ) {
V_27 = ( unsigned long ) V_26 -> V_29 . V_32 [ V_40 ] . V_9 ;
V_3 = V_26 -> V_29 . V_32 [ V_40 ] . V_34 ;
if ( V_35 == V_36 || V_35 == V_37 )
V_27 = F_12 ( V_27 ) ;
F_8 ( V_27 , V_1 , V_31 ,
V_3 , V_23 ) ;
}
#endif
F_14 ( & V_26 -> V_29 . V_30 , V_28 ) ;
}
static void F_16 ( struct V_25 * V_26 , unsigned long V_41 , unsigned long V_42 )
{
unsigned long V_43 , V_27 , V_44 ;
unsigned long V_45 , V_46 ;
V_26 -> V_29 . V_32 [ V_41 ] . V_34 =
V_42 / sizeof( struct V_9 ) ;
switch ( V_41 ) {
case V_33 :
V_27 = V_47 ;
break;
#if F_13 ( V_38 ) || F_13 ( V_39 )
case V_40 :
V_27 = V_48 ;
break;
#endif
default:
F_17 () ;
}
V_46 = F_18 ( V_49 ) ;
V_44 = F_12 ( V_26 -> V_29 . V_32 [ V_41 ] . V_9 ) ;
F_19 ( V_44 & ( V_42 - 1UL ) ) ;
switch ( V_42 ) {
case 8192 << 0 :
V_43 = 0x0UL ;
#ifdef F_20
V_27 += ( V_44 & 8192 ) ;
#endif
V_45 = 8192 ;
break;
case 8192 << 1 :
V_43 = 0x1UL ;
V_45 = 64 * 1024 ;
break;
case 8192 << 2 :
V_43 = 0x2UL ;
V_45 = 64 * 1024 ;
break;
case 8192 << 3 :
V_43 = 0x3UL ;
V_45 = 64 * 1024 ;
break;
case 8192 << 4 :
V_43 = 0x4UL ;
V_45 = 512 * 1024 ;
break;
case 8192 << 5 :
V_43 = 0x5UL ;
V_45 = 512 * 1024 ;
break;
case 8192 << 6 :
V_43 = 0x6UL ;
V_45 = 512 * 1024 ;
break;
case 8192 << 7 :
V_43 = 0x7UL ;
V_45 = 4 * 1024 * 1024 ;
break;
default:
F_21 ( V_50 L_1 ,
V_51 -> V_52 , V_51 -> V_53 , V_42 ) ;
F_22 ( V_54 ) ;
}
V_46 |= F_23 ( V_45 ) ;
if ( V_35 == V_36 || V_35 == V_37 ) {
V_43 |= V_44 ;
V_26 -> V_29 . V_32 [ V_41 ] . V_55 = V_43 ;
V_26 -> V_29 . V_32 [ V_41 ] . V_56 = 0 ;
V_26 -> V_29 . V_32 [ V_41 ] . V_57 = 0 ;
} else {
V_43 |= V_27 ;
V_43 |= ( V_44 & ( V_45 - 1UL ) ) ;
V_46 |= ( V_44 & ~ ( V_45 - 1UL ) ) ;
V_26 -> V_29 . V_32 [ V_41 ] . V_55 = V_43 ;
V_26 -> V_29 . V_32 [ V_41 ] . V_56 = V_27 ;
V_26 -> V_29 . V_32 [ V_41 ] . V_57 = V_46 ;
}
if ( V_35 == V_37 ) {
struct V_58 * V_59 = & V_26 -> V_29 . V_60 [ V_41 ] ;
switch ( V_41 ) {
case V_33 :
V_59 -> V_61 = V_62 ;
break;
#if F_13 ( V_38 ) || F_13 ( V_39 )
case V_40 :
V_59 -> V_61 = V_63 ;
break;
#endif
default:
F_17 () ;
}
V_59 -> V_64 = 1 ;
V_59 -> V_65 = V_42 / 16 ;
V_59 -> V_66 = 0 ;
switch ( V_41 ) {
case V_33 :
V_59 -> V_67 = V_68 ;
break;
#if F_13 ( V_38 ) || F_13 ( V_39 )
case V_40 :
V_59 -> V_67 = V_69 ;
break;
#endif
default:
F_17 () ;
}
V_59 -> V_70 = V_44 ;
V_59 -> V_71 = 0 ;
}
}
void T_1 F_24 ( void )
{
unsigned long V_20 ;
V_72 = F_25 ( L_2 ,
V_16 , V_16 ,
0 ,
V_73 ) ;
if ( ! V_72 ) {
F_26 ( L_3 ) ;
F_27 () ;
}
for ( V_20 = 0 ; V_20 < F_28 ( V_74 ) ; V_20 ++ ) {
unsigned long V_75 = 8192 << V_20 ;
const char * V_76 = V_74 [ V_20 ] ;
V_77 [ V_20 ] = F_25 ( V_76 ,
V_75 , V_75 ,
0 , NULL ) ;
if ( ! V_77 [ V_20 ] ) {
F_26 ( L_4 , V_76 ) ;
F_27 () ;
}
}
}
static unsigned long F_29 ( unsigned long V_78 )
{
unsigned long V_79 = ( V_78 / sizeof( struct V_9 ) ) ;
if ( V_80 < 0 )
return V_79 - ( V_79 >> - V_80 ) ;
else
return V_79 + ( V_79 >> V_80 ) ;
}
void F_30 ( struct V_25 * V_26 , unsigned long V_81 , unsigned long V_82 )
{
unsigned long V_83 = 1 * 1024 * 1024 ;
unsigned long V_78 , V_84 , V_28 ;
struct V_9 * V_85 , * V_86 ;
unsigned long V_87 , V_88 ;
unsigned long V_89 ;
T_2 V_90 ;
if ( V_83 > ( V_16 << V_91 ) )
V_83 = ( V_16 << V_91 ) ;
V_87 = 0 ;
for ( V_78 = 8192 ; V_78 < V_83 ; V_78 <<= 1UL ) {
V_89 = F_29 ( V_78 ) ;
if ( V_89 > V_82 )
break;
V_87 ++ ;
}
if ( V_78 == V_83 )
V_89 = ~ 0UL ;
V_92:
V_90 = V_93 ;
if ( V_78 > ( V_16 * 2 ) )
V_90 |= V_94 | V_95 ;
V_86 = F_31 ( V_77 [ V_87 ] ,
V_90 , F_32 () ) ;
if ( F_33 ( ! V_86 ) ) {
if ( V_26 -> V_29 . V_32 [ V_81 ] . V_9 == NULL &&
V_87 > 0 ) {
V_87 = 0 ;
V_78 = 8192 ;
V_89 = ~ 0UL ;
goto V_92;
}
if ( V_26 -> V_29 . V_32 [ V_81 ] . V_9 != NULL )
V_26 -> V_29 . V_32 [ V_81 ] . V_96 = ~ 0UL ;
return;
}
F_34 ( V_86 , V_78 ) ;
F_11 ( & V_26 -> V_29 . V_30 , V_28 ) ;
V_85 = V_26 -> V_29 . V_32 [ V_81 ] . V_9 ;
V_88 =
( V_26 -> V_29 . V_32 [ V_81 ] . V_55 & 0x7UL ) ;
V_84 = ( V_26 -> V_29 . V_32 [ V_81 ] . V_34 *
sizeof( struct V_9 ) ) ;
if ( F_33 ( V_85 &&
( V_82 < V_26 -> V_29 . V_32 [ V_81 ] . V_96 ) ) ) {
F_14 ( & V_26 -> V_29 . V_30 , V_28 ) ;
F_35 ( V_77 [ V_87 ] , V_86 ) ;
return;
}
V_26 -> V_29 . V_32 [ V_81 ] . V_96 = V_89 ;
if ( V_85 ) {
extern void V_97 ( unsigned long V_98 ,
unsigned long V_99 ,
unsigned long V_100 ,
unsigned long V_101 ,
unsigned long V_102 ) ;
unsigned long V_98 = ( unsigned long ) V_85 ;
unsigned long V_100 = ( unsigned long ) V_86 ;
if ( V_35 == V_36 || V_35 == V_37 ) {
V_98 = F_12 ( V_98 ) ;
V_100 = F_12 ( V_100 ) ;
}
V_97 ( V_98 , V_84 , V_100 , V_78 ,
V_81 == V_33 ?
V_15 : V_31 ) ;
}
V_26 -> V_29 . V_32 [ V_81 ] . V_9 = V_86 ;
F_16 ( V_26 , V_81 , V_78 ) ;
F_14 ( & V_26 -> V_29 . V_30 , V_28 ) ;
if ( V_85 ) {
F_36 ( V_26 ) ;
F_37 () ;
F_38 ( V_26 ) ;
F_39 () ;
F_35 ( V_77 [ V_88 ] , V_85 ) ;
}
}
int F_40 ( struct V_103 * V_104 , struct V_25 * V_26 )
{
unsigned long V_105 = F_41 ( V_26 ) ;
#if F_13 ( V_38 ) || F_13 ( V_39 )
unsigned long V_106 ;
unsigned long V_107 ;
#endif
unsigned int V_20 ;
F_42 ( & V_26 -> V_29 . V_30 ) ;
V_26 -> V_29 . V_108 = 0UL ;
#if F_13 ( V_38 ) || F_13 ( V_39 )
V_106 = V_26 -> V_29 . V_109 ;
V_107 = V_26 -> V_29 . V_110 ;
V_26 -> V_29 . V_109 = 0 ;
V_26 -> V_29 . V_110 = 0 ;
V_105 -= V_107 * ( V_111 / V_16 ) ;
#endif
for ( V_20 = 0 ; V_20 < V_112 ; V_20 ++ )
V_26 -> V_29 . V_32 [ V_20 ] . V_9 = NULL ;
F_30 ( V_26 , V_33 , V_105 ) ;
#if F_13 ( V_38 ) || F_13 ( V_39 )
if ( F_33 ( V_106 + V_107 ) )
F_30 ( V_26 , V_40 ,
( V_106 + V_107 ) *
V_113 ) ;
#endif
if ( F_33 ( ! V_26 -> V_29 . V_32 [ V_33 ] . V_9 ) )
return - V_114 ;
return 0 ;
}
static void F_43 ( struct V_115 * V_116 )
{
unsigned long V_117 ;
if ( ! V_116 -> V_9 )
return;
V_117 = V_116 -> V_55 & 0x7UL ;
F_35 ( V_77 [ V_117 ] , V_116 -> V_9 ) ;
V_116 -> V_9 = NULL ;
V_116 -> V_55 = 0UL ;
}
void F_44 ( struct V_25 * V_26 )
{
unsigned long V_28 , V_20 ;
for ( V_20 = 0 ; V_20 < V_112 ; V_20 ++ )
F_43 ( & V_26 -> V_29 . V_32 [ V_20 ] ) ;
F_11 ( & V_118 , V_28 ) ;
if ( F_45 ( V_26 -> V_29 ) ) {
unsigned long V_119 = F_46 ( V_26 -> V_29 ) ;
V_120 [ V_119 >> 6 ] &= ~ ( 1UL << ( V_119 & 63 ) ) ;
}
F_14 ( & V_118 , V_28 ) ;
}
