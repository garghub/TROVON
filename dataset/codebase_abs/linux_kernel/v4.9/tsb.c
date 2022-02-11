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
void F_8 ( struct V_18 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
unsigned long V_3 , V_25 , V_26 ;
F_9 ( & V_24 -> V_27 . V_28 , V_26 ) ;
if ( ! V_19 -> V_29 ) {
V_25 = ( unsigned long ) V_24 -> V_27 . V_30 [ V_31 ] . V_9 ;
V_3 = V_24 -> V_27 . V_30 [ V_31 ] . V_32 ;
if ( V_33 == V_34 || V_33 == V_35 )
V_25 = F_10 ( V_25 ) ;
F_7 ( V_19 , V_15 , V_25 , V_3 ) ;
}
#if F_11 ( V_36 ) || F_11 ( V_37 )
if ( V_19 -> V_29 && V_24 -> V_27 . V_30 [ V_38 ] . V_9 ) {
V_25 = ( unsigned long ) V_24 -> V_27 . V_30 [ V_38 ] . V_9 ;
V_3 = V_24 -> V_27 . V_30 [ V_38 ] . V_32 ;
if ( V_33 == V_34 || V_33 == V_35 )
V_25 = F_10 ( V_25 ) ;
F_7 ( V_19 , V_39 , V_25 , V_3 ) ;
}
#endif
F_12 ( & V_24 -> V_27 . V_28 , V_26 ) ;
}
void F_13 ( struct V_23 * V_24 , unsigned long V_1 , bool V_29 )
{
unsigned long V_3 , V_25 , V_26 ;
F_9 ( & V_24 -> V_27 . V_28 , V_26 ) ;
if ( ! V_29 ) {
V_25 = ( unsigned long ) V_24 -> V_27 . V_30 [ V_31 ] . V_9 ;
V_3 = V_24 -> V_27 . V_30 [ V_31 ] . V_32 ;
if ( V_33 == V_34 || V_33 == V_35 )
V_25 = F_10 ( V_25 ) ;
F_5 ( V_25 , V_1 , V_15 , V_3 ) ;
}
#if F_11 ( V_36 ) || F_11 ( V_37 )
if ( V_29 && V_24 -> V_27 . V_30 [ V_38 ] . V_9 ) {
V_25 = ( unsigned long ) V_24 -> V_27 . V_30 [ V_38 ] . V_9 ;
V_3 = V_24 -> V_27 . V_30 [ V_38 ] . V_32 ;
if ( V_33 == V_34 || V_33 == V_35 )
V_25 = F_10 ( V_25 ) ;
F_5 ( V_25 , V_1 , V_39 , V_3 ) ;
}
#endif
F_12 ( & V_24 -> V_27 . V_28 , V_26 ) ;
}
static void F_14 ( struct V_23 * V_24 , unsigned long V_40 , unsigned long V_41 )
{
unsigned long V_42 , V_25 , V_43 ;
unsigned long V_44 , V_45 ;
V_24 -> V_27 . V_30 [ V_40 ] . V_32 =
V_41 / sizeof( struct V_9 ) ;
switch ( V_40 ) {
case V_31 :
V_25 = V_46 ;
break;
#if F_11 ( V_36 ) || F_11 ( V_37 )
case V_38 :
V_25 = V_47 ;
break;
#endif
default:
F_15 () ;
}
V_45 = F_16 ( V_48 ) ;
V_43 = F_10 ( V_24 -> V_27 . V_30 [ V_40 ] . V_9 ) ;
F_17 ( V_43 & ( V_41 - 1UL ) ) ;
switch ( V_41 ) {
case 8192 << 0 :
V_42 = 0x0UL ;
#ifdef F_18
V_25 += ( V_43 & 8192 ) ;
#endif
V_44 = 8192 ;
break;
case 8192 << 1 :
V_42 = 0x1UL ;
V_44 = 64 * 1024 ;
break;
case 8192 << 2 :
V_42 = 0x2UL ;
V_44 = 64 * 1024 ;
break;
case 8192 << 3 :
V_42 = 0x3UL ;
V_44 = 64 * 1024 ;
break;
case 8192 << 4 :
V_42 = 0x4UL ;
V_44 = 512 * 1024 ;
break;
case 8192 << 5 :
V_42 = 0x5UL ;
V_44 = 512 * 1024 ;
break;
case 8192 << 6 :
V_42 = 0x6UL ;
V_44 = 512 * 1024 ;
break;
case 8192 << 7 :
V_42 = 0x7UL ;
V_44 = 4 * 1024 * 1024 ;
break;
default:
F_19 ( V_49 L_1 ,
V_50 -> V_51 , V_50 -> V_52 , V_41 ) ;
F_20 ( V_53 ) ;
}
V_45 |= F_21 ( V_44 ) ;
if ( V_33 == V_34 || V_33 == V_35 ) {
V_42 |= V_43 ;
V_24 -> V_27 . V_30 [ V_40 ] . V_54 = V_42 ;
V_24 -> V_27 . V_30 [ V_40 ] . V_55 = 0 ;
V_24 -> V_27 . V_30 [ V_40 ] . V_56 = 0 ;
} else {
V_42 |= V_25 ;
V_42 |= ( V_43 & ( V_44 - 1UL ) ) ;
V_45 |= ( V_43 & ~ ( V_44 - 1UL ) ) ;
V_24 -> V_27 . V_30 [ V_40 ] . V_54 = V_42 ;
V_24 -> V_27 . V_30 [ V_40 ] . V_55 = V_25 ;
V_24 -> V_27 . V_30 [ V_40 ] . V_56 = V_45 ;
}
if ( V_33 == V_35 ) {
struct V_57 * V_58 = & V_24 -> V_27 . V_59 [ V_40 ] ;
switch ( V_40 ) {
case V_31 :
V_58 -> V_60 = V_61 ;
break;
#if F_11 ( V_36 ) || F_11 ( V_37 )
case V_38 :
V_58 -> V_60 = V_62 ;
break;
#endif
default:
F_15 () ;
}
V_58 -> V_63 = 1 ;
V_58 -> V_64 = V_41 / 16 ;
V_58 -> V_65 = 0 ;
switch ( V_40 ) {
case V_31 :
V_58 -> V_66 = V_67 ;
break;
#if F_11 ( V_36 ) || F_11 ( V_37 )
case V_38 :
V_58 -> V_66 = V_68 ;
break;
#endif
default:
F_15 () ;
}
V_58 -> V_69 = V_43 ;
V_58 -> V_70 = 0 ;
}
}
void T_1 F_22 ( void )
{
unsigned long V_20 ;
V_71 = F_23 ( L_2 ,
V_16 , V_16 ,
0 ,
V_72 ) ;
if ( ! V_71 ) {
F_24 ( L_3 ) ;
F_25 () ;
}
for ( V_20 = 0 ; V_20 < F_26 ( V_73 ) ; V_20 ++ ) {
unsigned long V_74 = 8192 << V_20 ;
const char * V_75 = V_73 [ V_20 ] ;
V_76 [ V_20 ] = F_23 ( V_75 ,
V_74 , V_74 ,
0 , NULL ) ;
if ( ! V_76 [ V_20 ] ) {
F_24 ( L_4 , V_75 ) ;
F_25 () ;
}
}
}
static unsigned long F_27 ( unsigned long V_77 )
{
unsigned long V_78 = ( V_77 / sizeof( struct V_9 ) ) ;
if ( V_79 < 0 )
return V_78 - ( V_78 >> - V_79 ) ;
else
return V_78 + ( V_78 >> V_79 ) ;
}
void F_28 ( struct V_23 * V_24 , unsigned long V_80 , unsigned long V_81 )
{
unsigned long V_82 = 1 * 1024 * 1024 ;
unsigned long V_77 , V_83 , V_26 ;
struct V_9 * V_84 , * V_85 ;
unsigned long V_86 , V_87 ;
unsigned long V_88 ;
T_2 V_89 ;
if ( V_82 > ( V_16 << V_90 ) )
V_82 = ( V_16 << V_90 ) ;
V_86 = 0 ;
for ( V_77 = 8192 ; V_77 < V_82 ; V_77 <<= 1UL ) {
V_88 = F_27 ( V_77 ) ;
if ( V_88 > V_81 )
break;
V_86 ++ ;
}
if ( V_77 == V_82 )
V_88 = ~ 0UL ;
V_91:
V_89 = V_92 ;
if ( V_77 > ( V_16 * 2 ) )
V_89 |= V_93 | V_94 ;
V_85 = F_29 ( V_76 [ V_86 ] ,
V_89 , F_30 () ) ;
if ( F_31 ( ! V_85 ) ) {
if ( V_24 -> V_27 . V_30 [ V_80 ] . V_9 == NULL &&
V_86 > 0 ) {
V_86 = 0 ;
V_77 = 8192 ;
V_88 = ~ 0UL ;
goto V_91;
}
if ( V_24 -> V_27 . V_30 [ V_80 ] . V_9 != NULL )
V_24 -> V_27 . V_30 [ V_80 ] . V_95 = ~ 0UL ;
return;
}
F_32 ( V_85 , V_77 ) ;
F_9 ( & V_24 -> V_27 . V_28 , V_26 ) ;
V_84 = V_24 -> V_27 . V_30 [ V_80 ] . V_9 ;
V_87 =
( V_24 -> V_27 . V_30 [ V_80 ] . V_54 & 0x7UL ) ;
V_83 = ( V_24 -> V_27 . V_30 [ V_80 ] . V_32 *
sizeof( struct V_9 ) ) ;
if ( F_31 ( V_84 &&
( V_81 < V_24 -> V_27 . V_30 [ V_80 ] . V_95 ) ) ) {
F_12 ( & V_24 -> V_27 . V_28 , V_26 ) ;
F_33 ( V_76 [ V_86 ] , V_85 ) ;
return;
}
V_24 -> V_27 . V_30 [ V_80 ] . V_95 = V_88 ;
if ( V_84 ) {
extern void V_96 ( unsigned long V_97 ,
unsigned long V_98 ,
unsigned long V_99 ,
unsigned long V_100 ) ;
unsigned long V_97 = ( unsigned long ) V_84 ;
unsigned long V_99 = ( unsigned long ) V_85 ;
if ( V_33 == V_34 || V_33 == V_35 ) {
V_97 = F_10 ( V_97 ) ;
V_99 = F_10 ( V_99 ) ;
}
V_96 ( V_97 , V_83 , V_99 , V_77 ) ;
}
V_24 -> V_27 . V_30 [ V_80 ] . V_9 = V_85 ;
F_14 ( V_24 , V_80 , V_77 ) ;
F_12 ( & V_24 -> V_27 . V_28 , V_26 ) ;
if ( V_84 ) {
F_34 ( V_24 ) ;
F_35 () ;
F_36 ( V_24 ) ;
F_37 () ;
F_33 ( V_76 [ V_87 ] , V_84 ) ;
}
}
int F_38 ( struct V_101 * V_102 , struct V_23 * V_24 )
{
unsigned long V_103 = F_39 ( V_24 ) ;
#if F_11 ( V_36 ) || F_11 ( V_37 )
unsigned long V_104 ;
unsigned long V_105 ;
#endif
unsigned int V_20 ;
F_40 ( & V_24 -> V_27 . V_28 ) ;
V_24 -> V_27 . V_106 = 0UL ;
#if F_11 ( V_36 ) || F_11 ( V_37 )
V_104 = V_24 -> V_27 . V_107 ;
V_105 = V_24 -> V_27 . V_108 ;
V_24 -> V_27 . V_107 = 0 ;
V_24 -> V_27 . V_108 = 0 ;
V_103 -= V_105 * ( V_109 / V_16 ) ;
#endif
for ( V_20 = 0 ; V_20 < V_110 ; V_20 ++ )
V_24 -> V_27 . V_30 [ V_20 ] . V_9 = NULL ;
F_28 ( V_24 , V_31 , V_103 ) ;
#if F_11 ( V_36 ) || F_11 ( V_37 )
if ( F_31 ( V_104 + V_105 ) )
F_28 ( V_24 , V_38 ,
( V_104 + V_105 ) *
V_111 ) ;
#endif
if ( F_31 ( ! V_24 -> V_27 . V_30 [ V_31 ] . V_9 ) )
return - V_112 ;
return 0 ;
}
static void F_41 ( struct V_113 * V_114 )
{
unsigned long V_115 ;
if ( ! V_114 -> V_9 )
return;
V_115 = V_114 -> V_54 & 0x7UL ;
F_33 ( V_76 [ V_115 ] , V_114 -> V_9 ) ;
V_114 -> V_9 = NULL ;
V_114 -> V_54 = 0UL ;
}
void F_42 ( struct V_23 * V_24 )
{
unsigned long V_26 , V_20 ;
for ( V_20 = 0 ; V_20 < V_110 ; V_20 ++ )
F_41 ( & V_24 -> V_27 . V_30 [ V_20 ] ) ;
F_9 ( & V_116 , V_26 ) ;
if ( F_43 ( V_24 -> V_27 ) ) {
unsigned long V_117 = F_44 ( V_24 -> V_27 ) ;
V_118 [ V_117 >> 6 ] &= ~ ( 1UL << ( V_117 & 63 ) ) ;
}
F_12 ( & V_116 , V_26 ) ;
}
