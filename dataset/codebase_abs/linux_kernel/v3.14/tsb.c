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
V_23 = ( unsigned long ) V_22 -> V_25 . V_27 [ V_28 ] . V_12 ;
V_3 = V_22 -> V_25 . V_27 [ V_28 ] . V_29 ;
if ( V_30 == V_31 || V_30 == V_32 )
V_23 = F_9 ( V_23 ) ;
F_6 ( V_17 , V_10 , V_23 , V_3 ) ;
#if F_10 ( V_33 ) || F_10 ( V_34 )
if ( V_22 -> V_25 . V_27 [ V_35 ] . V_12 ) {
V_23 = ( unsigned long ) V_22 -> V_25 . V_27 [ V_35 ] . V_12 ;
V_3 = V_22 -> V_25 . V_27 [ V_35 ] . V_29 ;
if ( V_30 == V_31 || V_30 == V_32 )
V_23 = F_9 ( V_23 ) ;
F_6 ( V_17 , V_36 , V_23 , V_3 ) ;
}
#endif
F_11 ( & V_22 -> V_25 . V_26 , V_24 ) ;
}
void F_12 ( struct V_21 * V_22 , unsigned long V_1 )
{
unsigned long V_3 , V_23 , V_24 ;
F_8 ( & V_22 -> V_25 . V_26 , V_24 ) ;
V_23 = ( unsigned long ) V_22 -> V_25 . V_27 [ V_28 ] . V_12 ;
V_3 = V_22 -> V_25 . V_27 [ V_28 ] . V_29 ;
if ( V_30 == V_31 || V_30 == V_32 )
V_23 = F_9 ( V_23 ) ;
F_4 ( V_23 , V_1 , V_10 , V_3 ) ;
#if F_10 ( V_33 ) || F_10 ( V_34 )
if ( V_22 -> V_25 . V_27 [ V_35 ] . V_12 ) {
V_23 = ( unsigned long ) V_22 -> V_25 . V_27 [ V_35 ] . V_12 ;
V_3 = V_22 -> V_25 . V_27 [ V_35 ] . V_29 ;
if ( V_30 == V_31 || V_30 == V_32 )
V_23 = F_9 ( V_23 ) ;
F_4 ( V_23 , V_1 , V_36 , V_3 ) ;
}
#endif
F_11 ( & V_22 -> V_25 . V_26 , V_24 ) ;
}
static void F_13 ( struct V_21 * V_22 , unsigned long V_37 , unsigned long V_38 )
{
unsigned long V_39 , V_23 , V_40 ;
unsigned long V_41 , V_42 ;
V_22 -> V_25 . V_27 [ V_37 ] . V_29 =
V_38 / sizeof( struct V_12 ) ;
V_23 = V_43 ;
V_42 = F_14 ( V_44 ) ;
V_40 = F_9 ( V_22 -> V_25 . V_27 [ V_37 ] . V_12 ) ;
F_15 ( V_40 & ( V_38 - 1UL ) ) ;
switch ( V_38 ) {
case 8192 << 0 :
V_39 = 0x0UL ;
#ifdef F_16
V_23 += ( V_40 & 8192 ) ;
#endif
V_41 = 8192 ;
break;
case 8192 << 1 :
V_39 = 0x1UL ;
V_41 = 64 * 1024 ;
break;
case 8192 << 2 :
V_39 = 0x2UL ;
V_41 = 64 * 1024 ;
break;
case 8192 << 3 :
V_39 = 0x3UL ;
V_41 = 64 * 1024 ;
break;
case 8192 << 4 :
V_39 = 0x4UL ;
V_41 = 512 * 1024 ;
break;
case 8192 << 5 :
V_39 = 0x5UL ;
V_41 = 512 * 1024 ;
break;
case 8192 << 6 :
V_39 = 0x6UL ;
V_41 = 512 * 1024 ;
break;
case 8192 << 7 :
V_39 = 0x7UL ;
V_41 = 4 * 1024 * 1024 ;
break;
default:
F_17 ( V_45 L_1 ,
V_46 -> V_47 , V_46 -> V_48 , V_38 ) ;
F_18 ( V_49 ) ;
}
V_42 |= F_19 ( V_41 ) ;
if ( V_30 == V_31 || V_30 == V_32 ) {
V_39 |= V_40 ;
V_22 -> V_25 . V_27 [ V_37 ] . V_50 = V_39 ;
V_22 -> V_25 . V_27 [ V_37 ] . V_51 = 0 ;
V_22 -> V_25 . V_27 [ V_37 ] . V_52 = 0 ;
} else {
V_39 |= V_23 ;
V_39 |= ( V_40 & ( V_41 - 1UL ) ) ;
V_42 |= ( V_40 & ~ ( V_41 - 1UL ) ) ;
V_22 -> V_25 . V_27 [ V_37 ] . V_50 = V_39 ;
V_22 -> V_25 . V_27 [ V_37 ] . V_51 = V_23 ;
V_22 -> V_25 . V_27 [ V_37 ] . V_52 = V_42 ;
}
if ( V_30 == V_32 ) {
struct V_53 * V_54 = & V_22 -> V_25 . V_55 [ V_37 ] ;
switch ( V_37 ) {
case V_28 :
V_54 -> V_56 = V_57 ;
break;
#if F_10 ( V_33 ) || F_10 ( V_34 )
case V_35 :
V_54 -> V_56 = V_58 ;
break;
#endif
default:
F_20 () ;
}
V_54 -> V_59 = 1 ;
V_54 -> V_60 = V_38 / 16 ;
V_54 -> V_61 = 0 ;
switch ( V_37 ) {
case V_28 :
V_54 -> V_62 = V_63 ;
break;
#if F_10 ( V_33 ) || F_10 ( V_34 )
case V_35 :
V_54 -> V_62 = V_64 ;
break;
#endif
default:
F_20 () ;
}
V_54 -> V_65 = V_40 ;
V_54 -> V_66 = 0 ;
}
}
void T_1 F_21 ( void )
{
unsigned long V_18 ;
V_67 = F_22 ( L_2 ,
V_8 , V_8 ,
0 ,
V_68 ) ;
if ( ! V_67 ) {
F_23 ( L_3 ) ;
F_24 () ;
}
for ( V_18 = 0 ; V_18 < F_25 ( V_69 ) ; V_18 ++ ) {
unsigned long V_70 = 8192 << V_18 ;
const char * V_71 = V_69 [ V_18 ] ;
V_72 [ V_18 ] = F_22 ( V_71 ,
V_70 , V_70 ,
0 , NULL ) ;
if ( ! V_72 [ V_18 ] ) {
F_23 ( L_4 , V_71 ) ;
F_24 () ;
}
}
}
static unsigned long F_26 ( unsigned long V_73 )
{
unsigned long V_74 = ( V_73 / sizeof( struct V_12 ) ) ;
if ( V_75 < 0 )
return V_74 - ( V_74 >> - V_75 ) ;
else
return V_74 + ( V_74 >> V_75 ) ;
}
void F_27 ( struct V_21 * V_22 , unsigned long V_76 , unsigned long V_77 )
{
unsigned long V_78 = 1 * 1024 * 1024 ;
unsigned long V_73 , V_79 , V_24 ;
struct V_12 * V_80 , * V_81 ;
unsigned long V_82 , V_83 ;
unsigned long V_84 ;
T_2 V_85 ;
if ( V_78 > ( V_8 << V_86 ) )
V_78 = ( V_8 << V_86 ) ;
V_82 = 0 ;
for ( V_73 = 8192 ; V_73 < V_78 ; V_73 <<= 1UL ) {
V_84 = F_26 ( V_73 ) ;
if ( V_84 > V_77 )
break;
V_82 ++ ;
}
if ( V_73 == V_78 )
V_84 = ~ 0UL ;
V_87:
V_85 = V_88 ;
if ( V_73 > ( V_8 * 2 ) )
V_85 |= V_89 | V_90 ;
V_81 = F_28 ( V_72 [ V_82 ] ,
V_85 , F_29 () ) ;
if ( F_30 ( ! V_81 ) ) {
if ( V_22 -> V_25 . V_27 [ V_76 ] . V_12 == NULL &&
V_82 > 0 ) {
V_82 = 0 ;
V_73 = 8192 ;
V_84 = ~ 0UL ;
goto V_87;
}
if ( V_22 -> V_25 . V_27 [ V_76 ] . V_12 != NULL )
V_22 -> V_25 . V_27 [ V_76 ] . V_91 = ~ 0UL ;
return;
}
F_31 ( V_81 , V_73 ) ;
F_8 ( & V_22 -> V_25 . V_26 , V_24 ) ;
V_80 = V_22 -> V_25 . V_27 [ V_76 ] . V_12 ;
V_83 =
( V_22 -> V_25 . V_27 [ V_76 ] . V_50 & 0x7UL ) ;
V_79 = ( V_22 -> V_25 . V_27 [ V_76 ] . V_29 *
sizeof( struct V_12 ) ) ;
if ( F_30 ( V_80 &&
( V_77 < V_22 -> V_25 . V_27 [ V_76 ] . V_91 ) ) ) {
F_11 ( & V_22 -> V_25 . V_26 , V_24 ) ;
F_32 ( V_72 [ V_82 ] , V_81 ) ;
return;
}
V_22 -> V_25 . V_27 [ V_76 ] . V_91 = V_84 ;
if ( V_80 ) {
extern void V_92 ( unsigned long V_93 ,
unsigned long V_94 ,
unsigned long V_95 ,
unsigned long V_96 ) ;
unsigned long V_93 = ( unsigned long ) V_80 ;
unsigned long V_95 = ( unsigned long ) V_81 ;
if ( V_30 == V_31 || V_30 == V_32 ) {
V_93 = F_9 ( V_93 ) ;
V_95 = F_9 ( V_95 ) ;
}
V_92 ( V_93 , V_79 , V_95 , V_73 ) ;
}
V_22 -> V_25 . V_27 [ V_76 ] . V_12 = V_81 ;
F_13 ( V_22 , V_76 , V_73 ) ;
F_11 ( & V_22 -> V_25 . V_26 , V_24 ) ;
if ( V_80 ) {
F_33 ( V_22 ) ;
F_34 () ;
F_35 ( V_22 ) ;
F_36 () ;
F_32 ( V_72 [ V_83 ] , V_80 ) ;
}
}
int F_37 ( struct V_97 * V_98 , struct V_21 * V_22 )
{
#if F_10 ( V_33 ) || F_10 ( V_34 )
unsigned long V_99 ;
#endif
unsigned int V_18 ;
F_38 ( & V_22 -> V_25 . V_26 ) ;
V_22 -> V_25 . V_100 = 0UL ;
#if F_10 ( V_33 ) || F_10 ( V_34 )
V_99 = V_22 -> V_25 . V_99 ;
V_22 -> V_25 . V_99 = 0 ;
#endif
for ( V_18 = 0 ; V_18 < V_101 ; V_18 ++ )
V_22 -> V_25 . V_27 [ V_18 ] . V_12 = NULL ;
F_27 ( V_22 , V_28 , F_39 ( V_22 ) ) ;
#if F_10 ( V_33 ) || F_10 ( V_34 )
if ( F_30 ( V_99 ) )
F_27 ( V_22 , V_35 , V_99 ) ;
#endif
if ( F_30 ( ! V_22 -> V_25 . V_27 [ V_28 ] . V_12 ) )
return - V_102 ;
return 0 ;
}
static void F_40 ( struct V_103 * V_104 )
{
unsigned long V_105 ;
if ( ! V_104 -> V_12 )
return;
V_105 = V_104 -> V_50 & 0x7UL ;
F_32 ( V_72 [ V_105 ] , V_104 -> V_12 ) ;
V_104 -> V_12 = NULL ;
V_104 -> V_50 = 0UL ;
}
void F_41 ( struct V_21 * V_22 )
{
unsigned long V_24 , V_18 ;
for ( V_18 = 0 ; V_18 < V_101 ; V_18 ++ )
F_40 ( & V_22 -> V_25 . V_27 [ V_18 ] ) ;
F_8 ( & V_106 , V_24 ) ;
if ( F_42 ( V_22 -> V_25 ) ) {
unsigned long V_107 = F_43 ( V_22 -> V_25 ) ;
V_108 [ V_107 >> 6 ] &= ~ ( 1UL << ( V_107 & 63 ) ) ;
}
F_11 ( & V_106 , V_24 ) ;
}
