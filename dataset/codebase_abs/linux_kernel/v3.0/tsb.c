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
static void F_4 ( struct V_16 * V_17 , unsigned long V_2 ,
unsigned long V_12 , unsigned long V_3 )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_19 ; V_18 ++ ) {
unsigned long V_7 = V_17 -> V_20 [ V_18 ] ;
unsigned long V_4 , V_13 , V_9 ;
V_7 &= ~ 0x1UL ;
V_9 = F_1 ( V_7 , V_2 , V_3 ) ;
V_13 = V_12 + ( V_9 * sizeof( struct V_12 ) ) ;
V_4 = ( V_7 >> 22UL ) ;
F_5 ( V_13 , V_4 ) ;
}
}
void F_6 ( struct V_16 * V_17 )
{
struct V_21 * V_22 = V_17 -> V_22 ;
unsigned long V_3 , V_23 , V_24 ;
F_7 ( & V_22 -> V_25 . V_26 , V_24 ) ;
V_23 = ( unsigned long ) V_22 -> V_25 . V_27 [ V_28 ] . V_12 ;
V_3 = V_22 -> V_25 . V_27 [ V_28 ] . V_29 ;
if ( V_30 == V_31 || V_30 == V_32 )
V_23 = F_8 ( V_23 ) ;
F_4 ( V_17 , V_10 , V_23 , V_3 ) ;
#ifdef F_9
if ( V_22 -> V_25 . V_27 [ V_33 ] . V_12 ) {
V_23 = ( unsigned long ) V_22 -> V_25 . V_27 [ V_33 ] . V_12 ;
V_3 = V_22 -> V_25 . V_27 [ V_33 ] . V_29 ;
if ( V_30 == V_31 || V_30 == V_32 )
V_23 = F_8 ( V_23 ) ;
F_4 ( V_17 , V_34 , V_23 , V_3 ) ;
}
#endif
F_10 ( & V_22 -> V_25 . V_26 , V_24 ) ;
}
static void F_11 ( struct V_21 * V_22 , unsigned long V_35 , unsigned long V_36 )
{
unsigned long V_37 , V_23 , V_38 ;
unsigned long V_39 , V_40 ;
V_22 -> V_25 . V_27 [ V_35 ] . V_29 =
V_36 / sizeof( struct V_12 ) ;
V_23 = V_41 ;
V_40 = F_12 ( V_42 ) ;
V_38 = F_8 ( V_22 -> V_25 . V_27 [ V_35 ] . V_12 ) ;
F_13 ( V_38 & ( V_36 - 1UL ) ) ;
switch ( V_36 ) {
case 8192 << 0 :
V_37 = 0x0UL ;
#ifdef F_14
V_23 += ( V_38 & 8192 ) ;
#endif
V_39 = 8192 ;
break;
case 8192 << 1 :
V_37 = 0x1UL ;
V_39 = 64 * 1024 ;
break;
case 8192 << 2 :
V_37 = 0x2UL ;
V_39 = 64 * 1024 ;
break;
case 8192 << 3 :
V_37 = 0x3UL ;
V_39 = 64 * 1024 ;
break;
case 8192 << 4 :
V_37 = 0x4UL ;
V_39 = 512 * 1024 ;
break;
case 8192 << 5 :
V_37 = 0x5UL ;
V_39 = 512 * 1024 ;
break;
case 8192 << 6 :
V_37 = 0x6UL ;
V_39 = 512 * 1024 ;
break;
case 8192 << 7 :
V_37 = 0x7UL ;
V_39 = 4 * 1024 * 1024 ;
break;
default:
F_15 ( V_43 L_1 ,
V_44 -> V_45 , V_44 -> V_46 , V_36 ) ;
F_16 ( V_47 ) ;
}
V_40 |= F_17 ( V_39 ) ;
if ( V_30 == V_31 || V_30 == V_32 ) {
V_37 |= V_38 ;
V_22 -> V_25 . V_27 [ V_35 ] . V_48 = V_37 ;
V_22 -> V_25 . V_27 [ V_35 ] . V_49 = 0 ;
V_22 -> V_25 . V_27 [ V_35 ] . V_50 = 0 ;
} else {
V_37 |= V_23 ;
V_37 |= ( V_38 & ( V_39 - 1UL ) ) ;
V_40 |= ( V_38 & ~ ( V_39 - 1UL ) ) ;
V_22 -> V_25 . V_27 [ V_35 ] . V_48 = V_37 ;
V_22 -> V_25 . V_27 [ V_35 ] . V_49 = V_23 ;
V_22 -> V_25 . V_27 [ V_35 ] . V_50 = V_40 ;
}
if ( V_30 == V_32 ) {
struct V_51 * V_52 = & V_22 -> V_25 . V_53 [ V_35 ] ;
switch ( V_35 ) {
case V_28 :
V_52 -> V_54 = V_55 ;
break;
#ifdef F_9
case V_33 :
V_52 -> V_54 = V_56 ;
break;
#endif
default:
F_18 () ;
}
V_52 -> V_57 = 1 ;
V_52 -> V_58 = V_36 / 16 ;
V_52 -> V_59 = 0 ;
switch ( V_35 ) {
case V_28 :
V_52 -> V_60 = V_61 ;
break;
#ifdef F_9
case V_33 :
V_52 -> V_60 = V_62 ;
break;
#endif
default:
F_18 () ;
}
V_52 -> V_63 = V_38 ;
V_52 -> V_64 = 0 ;
}
}
void T_1 F_19 ( void )
{
unsigned long V_18 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
unsigned long V_65 = 8192 << V_18 ;
const char * V_66 = V_67 [ V_18 ] ;
V_68 [ V_18 ] = F_20 ( V_66 ,
V_65 , V_65 ,
0 , NULL ) ;
if ( ! V_68 [ V_18 ] ) {
F_21 ( L_2 , V_66 ) ;
F_22 () ;
}
}
}
static unsigned long F_23 ( unsigned long V_69 )
{
unsigned long V_70 = ( V_69 / sizeof( struct V_12 ) ) ;
if ( V_71 < 0 )
return V_70 - ( V_70 >> - V_71 ) ;
else
return V_70 + ( V_70 >> V_71 ) ;
}
void F_24 ( struct V_21 * V_22 , unsigned long V_72 , unsigned long V_73 )
{
unsigned long V_74 = 1 * 1024 * 1024 ;
unsigned long V_69 , V_75 , V_24 ;
struct V_12 * V_76 , * V_77 ;
unsigned long V_78 , V_79 ;
unsigned long V_80 ;
T_2 V_81 ;
if ( V_74 > ( V_8 << V_82 ) )
V_74 = ( V_8 << V_82 ) ;
V_78 = 0 ;
for ( V_69 = 8192 ; V_69 < V_74 ; V_69 <<= 1UL ) {
V_80 = F_23 ( V_69 ) ;
if ( V_80 > V_73 )
break;
V_78 ++ ;
}
if ( V_69 == V_74 )
V_80 = ~ 0UL ;
V_83:
V_81 = V_84 ;
if ( V_69 > ( V_8 * 2 ) )
V_81 = V_85 | V_86 ;
V_77 = F_25 ( V_68 [ V_78 ] ,
V_81 , F_26 () ) ;
if ( F_27 ( ! V_77 ) ) {
if ( V_22 -> V_25 . V_27 [ V_72 ] . V_12 == NULL &&
V_78 > 0 ) {
V_78 = 0 ;
V_69 = 8192 ;
V_80 = ~ 0UL ;
goto V_83;
}
if ( V_22 -> V_25 . V_27 [ V_72 ] . V_12 != NULL )
V_22 -> V_25 . V_27 [ V_72 ] . V_87 = ~ 0UL ;
return;
}
F_28 ( V_77 , V_69 ) ;
F_7 ( & V_22 -> V_25 . V_26 , V_24 ) ;
V_76 = V_22 -> V_25 . V_27 [ V_72 ] . V_12 ;
V_79 =
( V_22 -> V_25 . V_27 [ V_72 ] . V_48 & 0x7UL ) ;
V_75 = ( V_22 -> V_25 . V_27 [ V_72 ] . V_29 *
sizeof( struct V_12 ) ) ;
if ( F_27 ( V_76 &&
( V_73 < V_22 -> V_25 . V_27 [ V_72 ] . V_87 ) ) ) {
F_10 ( & V_22 -> V_25 . V_26 , V_24 ) ;
F_29 ( V_68 [ V_78 ] , V_77 ) ;
return;
}
V_22 -> V_25 . V_27 [ V_72 ] . V_87 = V_80 ;
if ( V_76 ) {
extern void V_88 ( unsigned long V_89 ,
unsigned long V_90 ,
unsigned long V_91 ,
unsigned long V_92 ) ;
unsigned long V_89 = ( unsigned long ) V_76 ;
unsigned long V_91 = ( unsigned long ) V_77 ;
if ( V_30 == V_31 || V_30 == V_32 ) {
V_89 = F_8 ( V_89 ) ;
V_91 = F_8 ( V_91 ) ;
}
V_88 ( V_89 , V_75 , V_91 , V_69 ) ;
}
V_22 -> V_25 . V_27 [ V_72 ] . V_12 = V_77 ;
F_11 ( V_22 , V_72 , V_69 ) ;
F_10 ( & V_22 -> V_25 . V_26 , V_24 ) ;
if ( V_76 ) {
F_30 ( V_22 ) ;
F_31 () ;
F_32 ( V_22 ) ;
F_33 () ;
F_29 ( V_68 [ V_79 ] , V_76 ) ;
}
}
int F_34 ( struct V_93 * V_94 , struct V_21 * V_22 )
{
#ifdef F_9
unsigned long V_95 ;
#endif
unsigned int V_18 ;
F_35 ( & V_22 -> V_25 . V_26 ) ;
V_22 -> V_25 . V_96 = 0UL ;
#ifdef F_9
V_95 = V_22 -> V_25 . V_95 ;
V_22 -> V_25 . V_95 = 0 ;
#endif
for ( V_18 = 0 ; V_18 < V_97 ; V_18 ++ )
V_22 -> V_25 . V_27 [ V_18 ] . V_12 = NULL ;
F_24 ( V_22 , V_28 , F_36 ( V_22 ) ) ;
#ifdef F_9
if ( F_27 ( V_95 ) )
F_24 ( V_22 , V_33 , V_95 ) ;
#endif
if ( F_27 ( ! V_22 -> V_25 . V_27 [ V_28 ] . V_12 ) )
return - V_98 ;
return 0 ;
}
static void F_37 ( struct V_99 * V_100 )
{
unsigned long V_101 ;
if ( ! V_100 -> V_12 )
return;
V_101 = V_100 -> V_48 & 0x7UL ;
F_29 ( V_68 [ V_101 ] , V_100 -> V_12 ) ;
V_100 -> V_12 = NULL ;
V_100 -> V_48 = 0UL ;
}
void F_38 ( struct V_21 * V_22 )
{
unsigned long V_24 , V_18 ;
for ( V_18 = 0 ; V_18 < V_97 ; V_18 ++ )
F_37 ( & V_22 -> V_25 . V_27 [ V_18 ] ) ;
F_7 ( & V_102 , V_24 ) ;
if ( F_39 ( V_22 -> V_25 ) ) {
unsigned long V_103 = F_40 ( V_22 -> V_25 ) ;
V_104 [ V_103 >> 6 ] &= ~ ( 1UL << ( V_103 & 63 ) ) ;
}
F_10 ( & V_102 , V_24 ) ;
}
