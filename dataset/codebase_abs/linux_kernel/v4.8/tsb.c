static inline unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
V_1 >>= V_2 ;
return V_1 & ( V_3 - 1 ) ;
}
static inline int F_2 ( unsigned long V_4 , unsigned long V_1 )
{
return ( V_4 == ( V_1 >> 22 ) ) ;
}
void F_3 ( unsigned long V_5 , unsigned long V_6 )
{
unsigned long V_7 ;
for ( V_7 = V_5 ; V_7 < V_6 ; V_7 += V_8 ) {
unsigned long V_9 = F_1 ( V_7 , V_10 ,
V_11 ) ;
struct V_12 * V_13 = & V_14 [ V_9 ] ;
if ( F_2 ( V_13 -> V_4 , V_7 ) )
V_13 -> V_4 = ( 1UL << V_15 ) ;
}
}
static void F_4 ( unsigned long V_12 , unsigned long V_7 ,
unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 , V_13 , V_9 ;
V_7 &= ~ 0x1UL ;
V_9 = F_1 ( V_7 , V_2 , V_3 ) ;
V_13 = V_12 + ( V_9 * sizeof( struct V_12 ) ) ;
V_4 = ( V_7 >> 22UL ) ;
F_5 ( V_13 , V_4 ) ;
}
static void F_6 ( struct V_16 * V_17 , unsigned long V_2 ,
unsigned long V_12 , unsigned long V_3 )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ )
F_4 ( V_12 , V_17 -> V_20 [ V_18 ] , V_2 , V_3 ) ;
}
void F_7 ( struct V_16 * V_17 )
{
struct V_21 * V_22 = V_17 -> V_22 ;
unsigned long V_3 , V_23 , V_24 ;
F_8 ( & V_22 -> V_25 . V_26 , V_24 ) ;
if ( ! V_17 -> V_27 ) {
V_23 = ( unsigned long ) V_22 -> V_25 . V_28 [ V_29 ] . V_12 ;
V_3 = V_22 -> V_25 . V_28 [ V_29 ] . V_30 ;
if ( V_31 == V_32 || V_31 == V_33 )
V_23 = F_9 ( V_23 ) ;
F_6 ( V_17 , V_10 , V_23 , V_3 ) ;
}
#if F_10 ( V_34 ) || F_10 ( V_35 )
if ( V_17 -> V_27 && V_22 -> V_25 . V_28 [ V_36 ] . V_12 ) {
V_23 = ( unsigned long ) V_22 -> V_25 . V_28 [ V_36 ] . V_12 ;
V_3 = V_22 -> V_25 . V_28 [ V_36 ] . V_30 ;
if ( V_31 == V_32 || V_31 == V_33 )
V_23 = F_9 ( V_23 ) ;
F_6 ( V_17 , V_37 , V_23 , V_3 ) ;
}
#endif
F_11 ( & V_22 -> V_25 . V_26 , V_24 ) ;
}
void F_12 ( struct V_21 * V_22 , unsigned long V_1 , bool V_27 )
{
unsigned long V_3 , V_23 , V_24 ;
F_8 ( & V_22 -> V_25 . V_26 , V_24 ) ;
if ( ! V_27 ) {
V_23 = ( unsigned long ) V_22 -> V_25 . V_28 [ V_29 ] . V_12 ;
V_3 = V_22 -> V_25 . V_28 [ V_29 ] . V_30 ;
if ( V_31 == V_32 || V_31 == V_33 )
V_23 = F_9 ( V_23 ) ;
F_4 ( V_23 , V_1 , V_10 , V_3 ) ;
}
#if F_10 ( V_34 ) || F_10 ( V_35 )
if ( V_27 && V_22 -> V_25 . V_28 [ V_36 ] . V_12 ) {
V_23 = ( unsigned long ) V_22 -> V_25 . V_28 [ V_36 ] . V_12 ;
V_3 = V_22 -> V_25 . V_28 [ V_36 ] . V_30 ;
if ( V_31 == V_32 || V_31 == V_33 )
V_23 = F_9 ( V_23 ) ;
F_4 ( V_23 , V_1 , V_37 , V_3 ) ;
}
#endif
F_11 ( & V_22 -> V_25 . V_26 , V_24 ) ;
}
static void F_13 ( struct V_21 * V_22 , unsigned long V_38 , unsigned long V_39 )
{
unsigned long V_40 , V_23 , V_41 ;
unsigned long V_42 , V_43 ;
V_22 -> V_25 . V_28 [ V_38 ] . V_30 =
V_39 / sizeof( struct V_12 ) ;
switch ( V_38 ) {
case V_29 :
V_23 = V_44 ;
break;
#if F_10 ( V_34 ) || F_10 ( V_35 )
case V_36 :
V_23 = V_45 ;
break;
#endif
default:
F_14 () ;
}
V_43 = F_15 ( V_46 ) ;
V_41 = F_9 ( V_22 -> V_25 . V_28 [ V_38 ] . V_12 ) ;
F_16 ( V_41 & ( V_39 - 1UL ) ) ;
switch ( V_39 ) {
case 8192 << 0 :
V_40 = 0x0UL ;
#ifdef F_17
V_23 += ( V_41 & 8192 ) ;
#endif
V_42 = 8192 ;
break;
case 8192 << 1 :
V_40 = 0x1UL ;
V_42 = 64 * 1024 ;
break;
case 8192 << 2 :
V_40 = 0x2UL ;
V_42 = 64 * 1024 ;
break;
case 8192 << 3 :
V_40 = 0x3UL ;
V_42 = 64 * 1024 ;
break;
case 8192 << 4 :
V_40 = 0x4UL ;
V_42 = 512 * 1024 ;
break;
case 8192 << 5 :
V_40 = 0x5UL ;
V_42 = 512 * 1024 ;
break;
case 8192 << 6 :
V_40 = 0x6UL ;
V_42 = 512 * 1024 ;
break;
case 8192 << 7 :
V_40 = 0x7UL ;
V_42 = 4 * 1024 * 1024 ;
break;
default:
F_18 ( V_47 L_1 ,
V_48 -> V_49 , V_48 -> V_50 , V_39 ) ;
F_19 ( V_51 ) ;
}
V_43 |= F_20 ( V_42 ) ;
if ( V_31 == V_32 || V_31 == V_33 ) {
V_40 |= V_41 ;
V_22 -> V_25 . V_28 [ V_38 ] . V_52 = V_40 ;
V_22 -> V_25 . V_28 [ V_38 ] . V_53 = 0 ;
V_22 -> V_25 . V_28 [ V_38 ] . V_54 = 0 ;
} else {
V_40 |= V_23 ;
V_40 |= ( V_41 & ( V_42 - 1UL ) ) ;
V_43 |= ( V_41 & ~ ( V_42 - 1UL ) ) ;
V_22 -> V_25 . V_28 [ V_38 ] . V_52 = V_40 ;
V_22 -> V_25 . V_28 [ V_38 ] . V_53 = V_23 ;
V_22 -> V_25 . V_28 [ V_38 ] . V_54 = V_43 ;
}
if ( V_31 == V_33 ) {
struct V_55 * V_56 = & V_22 -> V_25 . V_57 [ V_38 ] ;
switch ( V_38 ) {
case V_29 :
V_56 -> V_58 = V_59 ;
break;
#if F_10 ( V_34 ) || F_10 ( V_35 )
case V_36 :
V_56 -> V_58 = V_60 ;
break;
#endif
default:
F_14 () ;
}
V_56 -> V_61 = 1 ;
V_56 -> V_62 = V_39 / 16 ;
V_56 -> V_63 = 0 ;
switch ( V_38 ) {
case V_29 :
V_56 -> V_64 = V_65 ;
break;
#if F_10 ( V_34 ) || F_10 ( V_35 )
case V_36 :
V_56 -> V_64 = V_66 ;
break;
#endif
default:
F_14 () ;
}
V_56 -> V_67 = V_41 ;
V_56 -> V_68 = 0 ;
}
}
void T_1 F_21 ( void )
{
unsigned long V_18 ;
V_69 = F_22 ( L_2 ,
V_8 , V_8 ,
0 ,
V_70 ) ;
if ( ! V_69 ) {
F_23 ( L_3 ) ;
F_24 () ;
}
for ( V_18 = 0 ; V_18 < F_25 ( V_71 ) ; V_18 ++ ) {
unsigned long V_72 = 8192 << V_18 ;
const char * V_73 = V_71 [ V_18 ] ;
V_74 [ V_18 ] = F_22 ( V_73 ,
V_72 , V_72 ,
0 , NULL ) ;
if ( ! V_74 [ V_18 ] ) {
F_23 ( L_4 , V_73 ) ;
F_24 () ;
}
}
}
static unsigned long F_26 ( unsigned long V_75 )
{
unsigned long V_76 = ( V_75 / sizeof( struct V_12 ) ) ;
if ( V_77 < 0 )
return V_76 - ( V_76 >> - V_77 ) ;
else
return V_76 + ( V_76 >> V_77 ) ;
}
void F_27 ( struct V_21 * V_22 , unsigned long V_78 , unsigned long V_79 )
{
unsigned long V_80 = 1 * 1024 * 1024 ;
unsigned long V_75 , V_81 , V_24 ;
struct V_12 * V_82 , * V_83 ;
unsigned long V_84 , V_85 ;
unsigned long V_86 ;
T_2 V_87 ;
if ( V_80 > ( V_8 << V_88 ) )
V_80 = ( V_8 << V_88 ) ;
V_84 = 0 ;
for ( V_75 = 8192 ; V_75 < V_80 ; V_75 <<= 1UL ) {
V_86 = F_26 ( V_75 ) ;
if ( V_86 > V_79 )
break;
V_84 ++ ;
}
if ( V_75 == V_80 )
V_86 = ~ 0UL ;
V_89:
V_87 = V_90 ;
if ( V_75 > ( V_8 * 2 ) )
V_87 |= V_91 | V_92 ;
V_83 = F_28 ( V_74 [ V_84 ] ,
V_87 , F_29 () ) ;
if ( F_30 ( ! V_83 ) ) {
if ( V_22 -> V_25 . V_28 [ V_78 ] . V_12 == NULL &&
V_84 > 0 ) {
V_84 = 0 ;
V_75 = 8192 ;
V_86 = ~ 0UL ;
goto V_89;
}
if ( V_22 -> V_25 . V_28 [ V_78 ] . V_12 != NULL )
V_22 -> V_25 . V_28 [ V_78 ] . V_93 = ~ 0UL ;
return;
}
F_31 ( V_83 , V_75 ) ;
F_8 ( & V_22 -> V_25 . V_26 , V_24 ) ;
V_82 = V_22 -> V_25 . V_28 [ V_78 ] . V_12 ;
V_85 =
( V_22 -> V_25 . V_28 [ V_78 ] . V_52 & 0x7UL ) ;
V_81 = ( V_22 -> V_25 . V_28 [ V_78 ] . V_30 *
sizeof( struct V_12 ) ) ;
if ( F_30 ( V_82 &&
( V_79 < V_22 -> V_25 . V_28 [ V_78 ] . V_93 ) ) ) {
F_11 ( & V_22 -> V_25 . V_26 , V_24 ) ;
F_32 ( V_74 [ V_84 ] , V_83 ) ;
return;
}
V_22 -> V_25 . V_28 [ V_78 ] . V_93 = V_86 ;
if ( V_82 ) {
extern void V_94 ( unsigned long V_95 ,
unsigned long V_96 ,
unsigned long V_97 ,
unsigned long V_98 ) ;
unsigned long V_95 = ( unsigned long ) V_82 ;
unsigned long V_97 = ( unsigned long ) V_83 ;
if ( V_31 == V_32 || V_31 == V_33 ) {
V_95 = F_9 ( V_95 ) ;
V_97 = F_9 ( V_97 ) ;
}
V_94 ( V_95 , V_81 , V_97 , V_75 ) ;
}
V_22 -> V_25 . V_28 [ V_78 ] . V_12 = V_83 ;
F_13 ( V_22 , V_78 , V_75 ) ;
F_11 ( & V_22 -> V_25 . V_26 , V_24 ) ;
if ( V_82 ) {
F_33 ( V_22 ) ;
F_34 () ;
F_35 ( V_22 ) ;
F_36 () ;
F_32 ( V_74 [ V_85 ] , V_82 ) ;
}
}
int F_37 ( struct V_99 * V_100 , struct V_21 * V_22 )
{
unsigned long V_101 = F_38 ( V_22 ) ;
#if F_10 ( V_34 ) || F_10 ( V_35 )
unsigned long V_102 ;
unsigned long V_103 ;
#endif
unsigned int V_18 ;
F_39 ( & V_22 -> V_25 . V_26 ) ;
V_22 -> V_25 . V_104 = 0UL ;
#if F_10 ( V_34 ) || F_10 ( V_35 )
V_102 = V_22 -> V_25 . V_105 ;
V_103 = V_22 -> V_25 . V_106 ;
V_22 -> V_25 . V_105 = 0 ;
V_22 -> V_25 . V_106 = 0 ;
V_101 -= V_103 * ( V_107 / V_8 ) ;
#endif
for ( V_18 = 0 ; V_18 < V_108 ; V_18 ++ )
V_22 -> V_25 . V_28 [ V_18 ] . V_12 = NULL ;
F_27 ( V_22 , V_29 , V_101 ) ;
#if F_10 ( V_34 ) || F_10 ( V_35 )
if ( F_30 ( V_102 + V_103 ) )
F_27 ( V_22 , V_36 ,
( V_102 + V_103 ) *
V_109 ) ;
#endif
if ( F_30 ( ! V_22 -> V_25 . V_28 [ V_29 ] . V_12 ) )
return - V_110 ;
return 0 ;
}
static void F_40 ( struct V_111 * V_112 )
{
unsigned long V_113 ;
if ( ! V_112 -> V_12 )
return;
V_113 = V_112 -> V_52 & 0x7UL ;
F_32 ( V_74 [ V_113 ] , V_112 -> V_12 ) ;
V_112 -> V_12 = NULL ;
V_112 -> V_52 = 0UL ;
}
void F_41 ( struct V_21 * V_22 )
{
unsigned long V_24 , V_18 ;
for ( V_18 = 0 ; V_18 < V_108 ; V_18 ++ )
F_40 ( & V_22 -> V_25 . V_28 [ V_18 ] ) ;
F_8 ( & V_114 , V_24 ) ;
if ( F_42 ( V_22 -> V_25 ) ) {
unsigned long V_115 = F_43 ( V_22 -> V_25 ) ;
V_116 [ V_115 >> 6 ] &= ~ ( 1UL << ( V_115 & 63 ) ) ;
}
F_11 ( & V_114 , V_24 ) ;
}
