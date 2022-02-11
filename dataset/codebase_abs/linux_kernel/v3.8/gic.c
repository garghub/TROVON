static void T_1 * F_1 ( union V_1 * V_2 )
{
return * F_2 ( V_2 -> V_3 ) ;
}
static void T_1 * F_3 ( union V_1 * V_2 )
{
return V_2 -> V_4 ;
}
static inline void T_1 * F_4 ( struct V_5 * V_6 )
{
return V_6 -> V_7 ( & V_6 -> V_8 ) ;
}
static inline void T_1 * F_5 ( struct V_5 * V_6 )
{
return V_6 -> V_7 ( & V_6 -> V_9 ) ;
}
static inline void T_1 * F_6 ( struct V_10 * V_11 )
{
struct V_5 * V_12 = F_7 ( V_11 ) ;
return F_4 ( V_12 ) ;
}
static inline void T_1 * F_8 ( struct V_10 * V_11 )
{
struct V_5 * V_12 = F_7 ( V_11 ) ;
return F_5 ( V_12 ) ;
}
static inline unsigned int F_9 ( struct V_10 * V_11 )
{
return V_11 -> V_13 ;
}
static void F_10 ( struct V_10 * V_11 )
{
T_2 V_14 = 1 << ( F_9 ( V_11 ) % 32 ) ;
F_11 ( & V_15 ) ;
F_12 ( V_14 , F_6 ( V_11 ) + V_16 + ( F_9 ( V_11 ) / 32 ) * 4 ) ;
if ( V_17 . V_18 )
V_17 . V_18 ( V_11 ) ;
F_13 ( & V_15 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
T_2 V_14 = 1 << ( F_9 ( V_11 ) % 32 ) ;
F_11 ( & V_15 ) ;
if ( V_17 . V_19 )
V_17 . V_19 ( V_11 ) ;
F_12 ( V_14 , F_6 ( V_11 ) + V_20 + ( F_9 ( V_11 ) / 32 ) * 4 ) ;
F_13 ( & V_15 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
if ( V_17 . V_21 ) {
F_11 ( & V_15 ) ;
V_17 . V_21 ( V_11 ) ;
F_13 ( & V_15 ) ;
}
F_12 ( F_9 ( V_11 ) , F_8 ( V_11 ) + V_22 ) ;
}
static int F_16 ( struct V_10 * V_11 , unsigned int type )
{
void T_1 * V_2 = F_6 ( V_11 ) ;
unsigned int V_23 = F_9 ( V_11 ) ;
T_2 V_24 = 1 << ( V_23 % 32 ) ;
T_2 V_25 = ( V_23 / 32 ) * 4 ;
T_2 V_26 = 0x2 << ( ( V_23 % 16 ) * 2 ) ;
T_2 V_27 = ( V_23 / 16 ) * 4 ;
bool V_28 = false ;
T_2 V_29 ;
if ( V_23 < 16 )
return - V_30 ;
if ( type != V_31 && type != V_32 )
return - V_30 ;
F_11 ( & V_15 ) ;
if ( V_17 . V_33 )
V_17 . V_33 ( V_11 , type ) ;
V_29 = F_17 ( V_2 + V_34 + V_27 ) ;
if ( type == V_31 )
V_29 &= ~ V_26 ;
else if ( type == V_32 )
V_29 |= V_26 ;
if ( F_17 ( V_2 + V_20 + V_25 ) & V_24 ) {
F_12 ( V_24 , V_2 + V_16 + V_25 ) ;
V_28 = true ;
}
F_12 ( V_29 , V_2 + V_34 + V_27 ) ;
if ( V_28 )
F_12 ( V_24 , V_2 + V_20 + V_25 ) ;
F_13 ( & V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
if ( V_17 . V_35 )
return V_17 . V_35 ( V_11 ) ;
return - V_36 ;
}
static int F_19 ( struct V_10 * V_11 , const struct V_37 * V_38 ,
bool V_39 )
{
void T_1 * V_40 = F_6 ( V_11 ) + V_41 + ( F_9 ( V_11 ) & ~ 3 ) ;
unsigned int V_42 = ( F_9 ( V_11 ) % 4 ) * 8 ;
unsigned int V_43 = F_20 ( V_38 , V_44 ) ;
T_2 V_29 , V_14 , V_45 ;
if ( V_43 >= V_46 || V_43 >= V_47 )
return - V_30 ;
V_14 = 0xff << V_42 ;
V_45 = V_48 [ V_43 ] << V_42 ;
F_11 ( & V_15 ) ;
V_29 = F_17 ( V_40 ) & ~ V_14 ;
F_12 ( V_29 | V_45 , V_40 ) ;
F_13 ( & V_15 ) ;
return V_49 ;
}
static int F_21 ( struct V_10 * V_11 , unsigned int V_50 )
{
int V_51 = - V_36 ;
if ( V_17 . V_52 )
V_51 = V_17 . V_52 ( V_11 , V_50 ) ;
return V_51 ;
}
T_3 void T_4 F_22 ( struct V_53 * V_54 )
{
T_2 V_55 , V_56 ;
struct V_5 * V_57 = & V_12 [ 0 ] ;
void T_1 * V_9 = F_5 ( V_57 ) ;
do {
V_55 = F_17 ( V_9 + V_58 ) ;
V_56 = V_55 & ~ 0x1c00 ;
if ( F_23 ( V_56 > 15 && V_56 < 1021 ) ) {
V_56 = F_24 ( V_57 -> V_59 , V_56 ) ;
F_25 ( V_56 , V_54 ) ;
continue;
}
if ( V_56 < 16 ) {
F_12 ( V_55 , V_9 + V_22 ) ;
#ifdef F_26
F_27 ( V_56 , V_54 ) ;
#endif
continue;
}
break;
} while ( 1 );
}
static void F_28 ( unsigned int V_60 , struct V_61 * V_62 )
{
struct V_5 * V_63 = F_29 ( V_60 ) ;
struct V_64 * V_65 = F_30 ( V_60 ) ;
unsigned int V_66 , F_9 ;
unsigned long V_67 ;
F_31 ( V_65 , V_62 ) ;
F_11 ( & V_15 ) ;
V_67 = F_17 ( F_5 ( V_63 ) + V_58 ) ;
F_13 ( & V_15 ) ;
F_9 = ( V_67 & 0x3ff ) ;
if ( F_9 == 1023 )
goto V_68;
V_66 = F_24 ( V_63 -> V_59 , F_9 ) ;
if ( F_32 ( F_9 < 32 || F_9 > 1020 ) )
F_33 ( V_66 , V_62 ) ;
else
F_34 ( V_66 ) ;
V_68:
F_35 ( V_65 , V_62 ) ;
}
void T_5 F_36 ( unsigned int V_69 , unsigned int V_60 )
{
if ( V_69 >= V_70 )
F_37 () ;
if ( F_38 ( V_60 , & V_12 [ V_69 ] ) != 0 )
F_37 () ;
F_39 ( V_60 , F_28 ) ;
}
static T_6 F_40 ( struct V_5 * V_57 )
{
void T_1 * V_2 = F_4 ( V_57 ) ;
T_2 V_14 , V_71 ;
for ( V_71 = V_14 = 0 ; V_71 < 32 ; V_71 += 4 ) {
V_14 = F_17 ( V_2 + V_41 + V_71 ) ;
V_14 |= V_14 >> 16 ;
V_14 |= V_14 >> 8 ;
if ( V_14 )
break;
}
if ( ! V_14 )
F_41 ( L_1 ) ;
return V_14 ;
}
static void T_5 F_42 ( struct V_5 * V_57 )
{
unsigned int V_71 ;
T_2 V_37 ;
unsigned int V_72 = V_57 -> V_72 ;
void T_1 * V_2 = F_4 ( V_57 ) ;
F_12 ( 0 , V_2 + V_73 ) ;
for ( V_71 = 32 ; V_71 < V_72 ; V_71 += 16 )
F_12 ( 0 , V_2 + V_34 + V_71 * 4 / 16 ) ;
V_37 = F_40 ( V_57 ) ;
V_37 |= V_37 << 8 ;
V_37 |= V_37 << 16 ;
for ( V_71 = 32 ; V_71 < V_72 ; V_71 += 4 )
F_12 ( V_37 , V_2 + V_41 + V_71 * 4 / 4 ) ;
for ( V_71 = 32 ; V_71 < V_72 ; V_71 += 4 )
F_12 ( 0xa0a0a0a0 , V_2 + V_74 + V_71 * 4 / 4 ) ;
for ( V_71 = 32 ; V_71 < V_72 ; V_71 += 32 )
F_12 ( 0xffffffff , V_2 + V_16 + V_71 * 4 / 32 ) ;
F_12 ( 1 , V_2 + V_73 ) ;
}
static void T_7 F_43 ( struct V_5 * V_57 )
{
void T_1 * V_8 = F_4 ( V_57 ) ;
void T_1 * V_2 = F_5 ( V_57 ) ;
unsigned int V_75 , V_43 = F_44 () ;
int V_71 ;
F_45 ( V_43 >= V_46 ) ;
V_75 = F_40 ( V_57 ) ;
V_48 [ V_43 ] = V_75 ;
for ( V_71 = 0 ; V_71 < V_46 ; V_71 ++ )
if ( V_71 != V_43 )
V_48 [ V_71 ] &= ~ V_75 ;
F_12 ( 0xffff0000 , V_8 + V_16 ) ;
F_12 ( 0x0000ffff , V_8 + V_20 ) ;
for ( V_71 = 0 ; V_71 < 32 ; V_71 += 4 )
F_12 ( 0xa0a0a0a0 , V_8 + V_74 + V_71 * 4 / 4 ) ;
F_12 ( 0xf0 , V_2 + V_76 ) ;
F_12 ( 1 , V_2 + V_77 ) ;
}
static void F_46 ( unsigned int V_69 )
{
unsigned int V_72 ;
void T_1 * V_8 ;
int V_71 ;
if ( V_69 >= V_70 )
F_37 () ;
V_72 = V_12 [ V_69 ] . V_72 ;
V_8 = F_4 ( & V_12 [ V_69 ] ) ;
if ( ! V_8 )
return;
for ( V_71 = 0 ; V_71 < F_47 ( V_72 , 16 ) ; V_71 ++ )
V_12 [ V_69 ] . V_78 [ V_71 ] =
F_17 ( V_8 + V_34 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( V_72 , 4 ) ; V_71 ++ )
V_12 [ V_69 ] . V_79 [ V_71 ] =
F_17 ( V_8 + V_41 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( V_72 , 32 ) ; V_71 ++ )
V_12 [ V_69 ] . V_80 [ V_71 ] =
F_17 ( V_8 + V_20 + V_71 * 4 ) ;
}
static void F_48 ( unsigned int V_69 )
{
unsigned int V_72 ;
unsigned int V_71 ;
void T_1 * V_8 ;
if ( V_69 >= V_70 )
F_37 () ;
V_72 = V_12 [ V_69 ] . V_72 ;
V_8 = F_4 ( & V_12 [ V_69 ] ) ;
if ( ! V_8 )
return;
F_12 ( 0 , V_8 + V_73 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( V_72 , 16 ) ; V_71 ++ )
F_12 ( V_12 [ V_69 ] . V_78 [ V_71 ] ,
V_8 + V_34 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( V_72 , 4 ) ; V_71 ++ )
F_12 ( 0xa0a0a0a0 ,
V_8 + V_74 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( V_72 , 4 ) ; V_71 ++ )
F_12 ( V_12 [ V_69 ] . V_79 [ V_71 ] ,
V_8 + V_41 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( V_72 , 32 ) ; V_71 ++ )
F_12 ( V_12 [ V_69 ] . V_80 [ V_71 ] ,
V_8 + V_20 + V_71 * 4 ) ;
F_12 ( 1 , V_8 + V_73 ) ;
}
static void F_49 ( unsigned int V_69 )
{
int V_71 ;
T_2 * V_81 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_69 >= V_70 )
F_37 () ;
V_8 = F_4 ( & V_12 [ V_69 ] ) ;
V_9 = F_5 ( & V_12 [ V_69 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_81 = F_2 ( V_12 [ V_69 ] . V_82 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( 32 , 32 ) ; V_71 ++ )
V_81 [ V_71 ] = F_17 ( V_8 + V_20 + V_71 * 4 ) ;
V_81 = F_2 ( V_12 [ V_69 ] . V_83 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( 32 , 16 ) ; V_71 ++ )
V_81 [ V_71 ] = F_17 ( V_8 + V_34 + V_71 * 4 ) ;
}
static void F_50 ( unsigned int V_69 )
{
int V_71 ;
T_2 * V_81 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_69 >= V_70 )
F_37 () ;
V_8 = F_4 ( & V_12 [ V_69 ] ) ;
V_9 = F_5 ( & V_12 [ V_69 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_81 = F_2 ( V_12 [ V_69 ] . V_82 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( 32 , 32 ) ; V_71 ++ )
F_12 ( V_81 [ V_71 ] , V_8 + V_20 + V_71 * 4 ) ;
V_81 = F_2 ( V_12 [ V_69 ] . V_83 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( 32 , 16 ) ; V_71 ++ )
F_12 ( V_81 [ V_71 ] , V_8 + V_34 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_47 ( 32 , 4 ) ; V_71 ++ )
F_12 ( 0xa0a0a0a0 , V_8 + V_74 + V_71 * 4 ) ;
F_12 ( 0xf0 , V_9 + V_76 ) ;
F_12 ( 1 , V_9 + V_77 ) ;
}
static int F_51 ( struct V_84 * V_85 , unsigned long V_86 , void * V_87 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
#ifdef F_52
if ( ! V_12 [ V_71 ] . V_7 )
continue;
#endif
switch ( V_86 ) {
case V_88 :
F_49 ( V_71 ) ;
break;
case V_89 :
case V_90 :
F_50 ( V_71 ) ;
break;
case V_91 :
F_46 ( V_71 ) ;
break;
case V_92 :
case V_93 :
F_48 ( V_71 ) ;
break;
}
}
return V_94 ;
}
static void T_5 F_53 ( struct V_5 * V_57 )
{
V_57 -> V_82 = F_54 ( F_47 ( 32 , 32 ) * 4 ,
sizeof( T_2 ) ) ;
F_45 ( ! V_57 -> V_82 ) ;
V_57 -> V_83 = F_54 ( F_47 ( 32 , 16 ) * 4 ,
sizeof( T_2 ) ) ;
F_45 ( ! V_57 -> V_83 ) ;
if ( V_57 == & V_12 [ 0 ] )
F_55 ( & V_95 ) ;
}
static void T_5 F_53 ( struct V_5 * V_57 )
{
}
static int F_56 ( struct V_96 * V_11 , unsigned int V_60 ,
T_8 V_97 )
{
if ( V_97 < 32 ) {
F_57 ( V_60 ) ;
F_58 ( V_60 , & V_98 ,
V_99 ) ;
F_59 ( V_60 , V_100 | V_101 ) ;
} else {
F_58 ( V_60 , & V_98 ,
V_102 ) ;
F_59 ( V_60 , V_100 | V_103 ) ;
}
F_60 ( V_60 , V_11 -> V_104 ) ;
return 0 ;
}
static int F_61 ( struct V_96 * V_11 ,
struct V_105 * V_106 ,
const T_2 * V_107 , unsigned int V_108 ,
unsigned long * V_109 , unsigned int * V_110 )
{
if ( V_11 -> V_111 != V_106 )
return - V_30 ;
if ( V_108 < 3 )
return - V_30 ;
* V_109 = V_107 [ 1 ] + 16 ;
if ( ! V_107 [ 0 ] )
* V_109 += 16 ;
* V_110 = V_107 [ 2 ] & V_112 ;
return 0 ;
}
void T_5 F_62 ( unsigned int V_69 , int V_113 ,
void T_1 * V_8 , void T_1 * V_9 ,
T_2 V_114 , struct V_105 * V_115 )
{
T_8 V_116 ;
struct V_5 * V_57 ;
int V_72 , V_117 , V_71 ;
F_45 ( V_69 >= V_70 ) ;
V_57 = & V_12 [ V_69 ] ;
#ifdef F_52
if ( V_114 ) {
unsigned int V_43 ;
V_57 -> V_8 . V_3 = F_63 (void __iomem *) ;
V_57 -> V_9 . V_3 = F_63 (void __iomem *) ;
if ( F_64 ( ! V_57 -> V_8 . V_3 ||
! V_57 -> V_9 . V_3 ) ) {
F_65 ( V_57 -> V_8 . V_3 ) ;
F_65 ( V_57 -> V_9 . V_3 ) ;
return;
}
F_66 (cpu) {
unsigned long V_118 = V_114 * F_67 ( V_43 ) ;
* F_68 ( V_57 -> V_8 . V_3 , V_43 ) = V_8 + V_118 ;
* F_68 ( V_57 -> V_9 . V_3 , V_43 ) = V_9 + V_118 ;
}
F_69 ( V_57 , F_1 ) ;
} else
#endif
{
F_70 ( V_114 ,
L_2 ,
V_114 ) ;
V_57 -> V_8 . V_4 = V_8 ;
V_57 -> V_9 . V_4 = V_9 ;
F_69 ( V_57 , F_3 ) ;
}
for ( V_71 = 0 ; V_71 < V_46 ; V_71 ++ )
V_48 [ V_71 ] = 0xff ;
if ( V_69 == 0 && ( V_113 & 31 ) > 0 ) {
V_116 = 16 ;
if ( V_113 != - 1 )
V_113 = ( V_113 & ~ 31 ) + 16 ;
} else {
V_116 = 32 ;
}
V_72 = F_17 ( F_4 ( V_57 ) + V_119 ) & 0x1f ;
V_72 = ( V_72 + 1 ) * 32 ;
if ( V_72 > 1020 )
V_72 = 1020 ;
V_57 -> V_72 = V_72 ;
V_72 -= V_116 ;
V_117 = F_71 ( V_113 , 16 , V_72 , F_72 () ) ;
if ( F_73 ( V_117 ) ) {
F_70 ( 1 , L_3 ,
V_113 ) ;
V_117 = V_113 ;
}
V_57 -> V_59 = F_74 ( V_115 , V_72 , V_117 ,
V_116 , & V_120 , V_57 ) ;
if ( F_64 ( ! V_57 -> V_59 ) )
return;
V_98 . V_121 |= V_17 . V_121 ;
F_42 ( V_57 ) ;
F_43 ( V_57 ) ;
F_53 ( V_57 ) ;
}
void T_7 F_75 ( unsigned int V_69 )
{
F_45 ( V_69 >= V_70 ) ;
F_43 ( & V_12 [ V_69 ] ) ;
}
void F_76 ( const struct V_37 * V_14 , unsigned int V_60 )
{
int V_43 ;
unsigned long V_122 = 0 ;
F_77 (cpu, mask)
V_122 |= V_48 [ V_43 ] ;
F_78 () ;
F_12 ( V_122 << 16 | V_60 , F_4 ( & V_12 [ 0 ] ) + V_123 ) ;
}
int T_5 F_79 ( struct V_105 * V_115 , struct V_105 * V_124 )
{
void T_1 * V_9 ;
void T_1 * V_8 ;
T_2 V_114 ;
int V_60 ;
if ( F_64 ( ! V_115 ) )
return - V_125 ;
V_8 = F_80 ( V_115 , 0 ) ;
F_70 ( ! V_8 , L_4 ) ;
V_9 = F_80 ( V_115 , 1 ) ;
F_70 ( ! V_9 , L_5 ) ;
if ( F_81 ( V_115 , L_6 , & V_114 ) )
V_114 = 0 ;
F_62 ( V_126 , - 1 , V_8 , V_9 , V_114 , V_115 ) ;
if ( V_124 ) {
V_60 = F_82 ( V_115 , 0 ) ;
F_36 ( V_126 , V_60 ) ;
}
V_126 ++ ;
return 0 ;
}
