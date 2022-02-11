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
if ( V_43 >= 8 || V_43 >= V_46 )
return - V_30 ;
V_14 = 0xff << V_42 ;
V_45 = 1 << ( F_21 ( V_43 ) + V_42 ) ;
F_11 ( & V_15 ) ;
V_29 = F_17 ( V_40 ) & ~ V_14 ;
F_12 ( V_29 | V_45 , V_40 ) ;
F_13 ( & V_15 ) ;
return V_47 ;
}
static int F_22 ( struct V_10 * V_11 , unsigned int V_48 )
{
int V_49 = - V_36 ;
if ( V_17 . V_50 )
V_49 = V_17 . V_50 ( V_11 , V_48 ) ;
return V_49 ;
}
T_3 void T_4 F_23 ( struct V_51 * V_52 )
{
T_2 V_53 , V_54 ;
struct V_5 * V_55 = & V_12 [ 0 ] ;
void T_1 * V_9 = F_5 ( V_55 ) ;
do {
V_53 = F_17 ( V_9 + V_56 ) ;
V_54 = V_53 & ~ 0x1c00 ;
if ( F_24 ( V_54 > 15 && V_54 < 1021 ) ) {
V_54 = F_25 ( V_55 -> V_57 , V_54 ) ;
F_26 ( V_54 , V_52 ) ;
continue;
}
if ( V_54 < 16 ) {
F_12 ( V_53 , V_9 + V_22 ) ;
#ifdef F_27
F_28 ( V_54 , V_52 ) ;
#endif
continue;
}
break;
} while ( 1 );
}
static void F_29 ( unsigned int V_58 , struct V_59 * V_60 )
{
struct V_5 * V_61 = F_30 ( V_58 ) ;
struct V_62 * V_63 = F_31 ( V_58 ) ;
unsigned int V_64 , F_9 ;
unsigned long V_65 ;
F_32 ( V_63 , V_60 ) ;
F_11 ( & V_15 ) ;
V_65 = F_17 ( F_5 ( V_61 ) + V_56 ) ;
F_13 ( & V_15 ) ;
F_9 = ( V_65 & 0x3ff ) ;
if ( F_9 == 1023 )
goto V_66;
V_64 = F_25 ( V_61 -> V_57 , F_9 ) ;
if ( F_33 ( F_9 < 32 || F_9 > 1020 ) )
F_34 ( V_64 , V_60 ) ;
else
F_35 ( V_64 ) ;
V_66:
F_36 ( V_63 , V_60 ) ;
}
void T_5 F_37 ( unsigned int V_67 , unsigned int V_58 )
{
if ( V_67 >= V_68 )
F_38 () ;
if ( F_39 ( V_58 , & V_12 [ V_67 ] ) != 0 )
F_38 () ;
F_40 ( V_58 , F_29 ) ;
}
static void T_5 F_41 ( struct V_5 * V_55 )
{
unsigned int V_69 ;
T_2 V_37 ;
unsigned int V_70 = V_55 -> V_70 ;
void T_1 * V_2 = F_4 ( V_55 ) ;
T_2 V_43 = F_21 ( F_42 () ) ;
V_37 = 1 << V_43 ;
V_37 |= V_37 << 8 ;
V_37 |= V_37 << 16 ;
F_12 ( 0 , V_2 + V_71 ) ;
for ( V_69 = 32 ; V_69 < V_70 ; V_69 += 16 )
F_12 ( 0 , V_2 + V_34 + V_69 * 4 / 16 ) ;
for ( V_69 = 32 ; V_69 < V_70 ; V_69 += 4 )
F_12 ( V_37 , V_2 + V_41 + V_69 * 4 / 4 ) ;
for ( V_69 = 32 ; V_69 < V_70 ; V_69 += 4 )
F_12 ( 0xa0a0a0a0 , V_2 + V_72 + V_69 * 4 / 4 ) ;
for ( V_69 = 32 ; V_69 < V_70 ; V_69 += 32 )
F_12 ( 0xffffffff , V_2 + V_16 + V_69 * 4 / 32 ) ;
F_12 ( 1 , V_2 + V_71 ) ;
}
static void T_6 F_43 ( struct V_5 * V_55 )
{
void T_1 * V_8 = F_4 ( V_55 ) ;
void T_1 * V_2 = F_5 ( V_55 ) ;
int V_69 ;
F_12 ( 0xffff0000 , V_8 + V_16 ) ;
F_12 ( 0x0000ffff , V_8 + V_20 ) ;
for ( V_69 = 0 ; V_69 < 32 ; V_69 += 4 )
F_12 ( 0xa0a0a0a0 , V_8 + V_72 + V_69 * 4 / 4 ) ;
F_12 ( 0xf0 , V_2 + V_73 ) ;
F_12 ( 1 , V_2 + V_74 ) ;
}
static void F_44 ( unsigned int V_67 )
{
unsigned int V_70 ;
void T_1 * V_8 ;
int V_69 ;
if ( V_67 >= V_68 )
F_38 () ;
V_70 = V_12 [ V_67 ] . V_70 ;
V_8 = F_4 ( & V_12 [ V_67 ] ) ;
if ( ! V_8 )
return;
for ( V_69 = 0 ; V_69 < F_45 ( V_70 , 16 ) ; V_69 ++ )
V_12 [ V_67 ] . V_75 [ V_69 ] =
F_17 ( V_8 + V_34 + V_69 * 4 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( V_70 , 4 ) ; V_69 ++ )
V_12 [ V_67 ] . V_76 [ V_69 ] =
F_17 ( V_8 + V_41 + V_69 * 4 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( V_70 , 32 ) ; V_69 ++ )
V_12 [ V_67 ] . V_77 [ V_69 ] =
F_17 ( V_8 + V_20 + V_69 * 4 ) ;
}
static void F_46 ( unsigned int V_67 )
{
unsigned int V_70 ;
unsigned int V_69 ;
void T_1 * V_8 ;
if ( V_67 >= V_68 )
F_38 () ;
V_70 = V_12 [ V_67 ] . V_70 ;
V_8 = F_4 ( & V_12 [ V_67 ] ) ;
if ( ! V_8 )
return;
F_12 ( 0 , V_8 + V_71 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( V_70 , 16 ) ; V_69 ++ )
F_12 ( V_12 [ V_67 ] . V_75 [ V_69 ] ,
V_8 + V_34 + V_69 * 4 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( V_70 , 4 ) ; V_69 ++ )
F_12 ( 0xa0a0a0a0 ,
V_8 + V_72 + V_69 * 4 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( V_70 , 4 ) ; V_69 ++ )
F_12 ( V_12 [ V_67 ] . V_76 [ V_69 ] ,
V_8 + V_41 + V_69 * 4 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( V_70 , 32 ) ; V_69 ++ )
F_12 ( V_12 [ V_67 ] . V_77 [ V_69 ] ,
V_8 + V_20 + V_69 * 4 ) ;
F_12 ( 1 , V_8 + V_71 ) ;
}
static void F_47 ( unsigned int V_67 )
{
int V_69 ;
T_2 * V_78 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_67 >= V_68 )
F_38 () ;
V_8 = F_4 ( & V_12 [ V_67 ] ) ;
V_9 = F_5 ( & V_12 [ V_67 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_78 = F_2 ( V_12 [ V_67 ] . V_79 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( 32 , 32 ) ; V_69 ++ )
V_78 [ V_69 ] = F_17 ( V_8 + V_20 + V_69 * 4 ) ;
V_78 = F_2 ( V_12 [ V_67 ] . V_80 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( 32 , 16 ) ; V_69 ++ )
V_78 [ V_69 ] = F_17 ( V_8 + V_34 + V_69 * 4 ) ;
}
static void F_48 ( unsigned int V_67 )
{
int V_69 ;
T_2 * V_78 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_67 >= V_68 )
F_38 () ;
V_8 = F_4 ( & V_12 [ V_67 ] ) ;
V_9 = F_5 ( & V_12 [ V_67 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_78 = F_2 ( V_12 [ V_67 ] . V_79 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( 32 , 32 ) ; V_69 ++ )
F_12 ( V_78 [ V_69 ] , V_8 + V_20 + V_69 * 4 ) ;
V_78 = F_2 ( V_12 [ V_67 ] . V_80 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( 32 , 16 ) ; V_69 ++ )
F_12 ( V_78 [ V_69 ] , V_8 + V_34 + V_69 * 4 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( 32 , 4 ) ; V_69 ++ )
F_12 ( 0xa0a0a0a0 , V_8 + V_72 + V_69 * 4 ) ;
F_12 ( 0xf0 , V_9 + V_73 ) ;
F_12 ( 1 , V_9 + V_74 ) ;
}
static int F_49 ( struct V_81 * V_82 , unsigned long V_83 , void * V_84 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
#ifdef F_50
if ( ! V_12 [ V_69 ] . V_7 )
continue;
#endif
switch ( V_83 ) {
case V_85 :
F_47 ( V_69 ) ;
break;
case V_86 :
case V_87 :
F_48 ( V_69 ) ;
break;
case V_88 :
F_44 ( V_69 ) ;
break;
case V_89 :
case V_90 :
F_46 ( V_69 ) ;
break;
}
}
return V_91 ;
}
static void T_5 F_51 ( struct V_5 * V_55 )
{
V_55 -> V_79 = F_52 ( F_45 ( 32 , 32 ) * 4 ,
sizeof( T_2 ) ) ;
F_53 ( ! V_55 -> V_79 ) ;
V_55 -> V_80 = F_52 ( F_45 ( 32 , 16 ) * 4 ,
sizeof( T_2 ) ) ;
F_53 ( ! V_55 -> V_80 ) ;
if ( V_55 == & V_12 [ 0 ] )
F_54 ( & V_92 ) ;
}
static void T_5 F_51 ( struct V_5 * V_55 )
{
}
static int F_55 ( struct V_93 * V_11 , unsigned int V_58 ,
T_7 V_94 )
{
if ( V_94 < 32 ) {
F_56 ( V_58 ) ;
F_57 ( V_58 , & V_95 ,
V_96 ) ;
F_58 ( V_58 , V_97 | V_98 ) ;
} else {
F_57 ( V_58 , & V_95 ,
V_99 ) ;
F_58 ( V_58 , V_97 | V_100 ) ;
}
F_59 ( V_58 , V_11 -> V_101 ) ;
return 0 ;
}
static int F_60 ( struct V_93 * V_11 ,
struct V_102 * V_103 ,
const T_2 * V_104 , unsigned int V_105 ,
unsigned long * V_106 , unsigned int * V_107 )
{
if ( V_11 -> V_108 != V_103 )
return - V_30 ;
if ( V_105 < 3 )
return - V_30 ;
* V_106 = V_104 [ 1 ] + 16 ;
if ( ! V_104 [ 0 ] )
* V_106 += 16 ;
* V_107 = V_104 [ 2 ] & V_109 ;
return 0 ;
}
void T_5 F_61 ( unsigned int V_67 , int V_110 ,
void T_1 * V_8 , void T_1 * V_9 ,
T_2 V_111 , struct V_102 * V_112 )
{
T_7 V_113 ;
struct V_5 * V_55 ;
int V_70 , V_114 ;
F_53 ( V_67 >= V_68 ) ;
V_55 = & V_12 [ V_67 ] ;
#ifdef F_50
if ( V_111 ) {
unsigned int V_43 ;
V_55 -> V_8 . V_3 = F_62 (void __iomem *) ;
V_55 -> V_9 . V_3 = F_62 (void __iomem *) ;
if ( F_63 ( ! V_55 -> V_8 . V_3 ||
! V_55 -> V_9 . V_3 ) ) {
F_64 ( V_55 -> V_8 . V_3 ) ;
F_64 ( V_55 -> V_9 . V_3 ) ;
return;
}
F_65 (cpu) {
unsigned long V_115 = V_111 * F_21 ( V_43 ) ;
* F_66 ( V_55 -> V_8 . V_3 , V_43 ) = V_8 + V_115 ;
* F_66 ( V_55 -> V_9 . V_3 , V_43 ) = V_9 + V_115 ;
}
F_67 ( V_55 , F_1 ) ;
} else
#endif
{
F_68 ( V_111 ,
L_1 ,
V_111 ) ;
V_55 -> V_8 . V_4 = V_8 ;
V_55 -> V_9 . V_4 = V_9 ;
F_67 ( V_55 , F_3 ) ;
}
if ( V_67 == 0 && ( V_110 & 31 ) > 0 ) {
V_113 = 16 ;
if ( V_110 != - 1 )
V_110 = ( V_110 & ~ 31 ) + 16 ;
} else {
V_113 = 32 ;
}
V_70 = F_17 ( F_4 ( V_55 ) + V_116 ) & 0x1f ;
V_70 = ( V_70 + 1 ) * 32 ;
if ( V_70 > 1020 )
V_70 = 1020 ;
V_55 -> V_70 = V_70 ;
V_70 -= V_113 ;
V_114 = F_69 ( V_110 , 16 , V_70 , F_70 () ) ;
if ( F_71 ( V_114 ) ) {
F_68 ( 1 , L_2 ,
V_110 ) ;
V_114 = V_110 ;
}
V_55 -> V_57 = F_72 ( V_112 , V_70 , V_114 ,
V_113 , & V_117 , V_55 ) ;
if ( F_63 ( ! V_55 -> V_57 ) )
return;
V_95 . V_118 |= V_17 . V_118 ;
F_41 ( V_55 ) ;
F_43 ( V_55 ) ;
F_51 ( V_55 ) ;
}
void T_6 F_73 ( unsigned int V_67 )
{
F_53 ( V_67 >= V_68 ) ;
F_43 ( & V_12 [ V_67 ] ) ;
}
void F_74 ( const struct V_37 * V_14 , unsigned int V_58 )
{
int V_43 ;
unsigned long V_119 = 0 ;
F_75 (cpu, mask)
V_119 |= 1 << F_21 ( V_43 ) ;
F_76 () ;
F_12 ( V_119 << 16 | V_58 , F_4 ( & V_12 [ 0 ] ) + V_120 ) ;
}
int T_5 F_77 ( struct V_102 * V_112 , struct V_102 * V_121 )
{
void T_1 * V_9 ;
void T_1 * V_8 ;
T_2 V_111 ;
int V_58 ;
if ( F_63 ( ! V_112 ) )
return - V_122 ;
V_8 = F_78 ( V_112 , 0 ) ;
F_68 ( ! V_8 , L_3 ) ;
V_9 = F_78 ( V_112 , 1 ) ;
F_68 ( ! V_9 , L_4 ) ;
if ( F_79 ( V_112 , L_5 , & V_111 ) )
V_111 = 0 ;
F_61 ( V_123 , - 1 , V_8 , V_9 , V_111 , V_112 ) ;
if ( V_121 ) {
V_58 = F_80 ( V_112 , 0 ) ;
F_37 ( V_123 , V_58 ) ;
}
V_123 ++ ;
return 0 ;
}
