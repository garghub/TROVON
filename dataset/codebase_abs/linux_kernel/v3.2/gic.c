static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static inline void T_1 * F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_6 ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_7 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_2 V_8 = 1 << ( F_4 ( V_2 ) % 32 ) ;
F_6 ( & V_9 ) ;
F_7 ( V_8 , F_1 ( V_2 ) + V_10 + ( F_4 ( V_2 ) / 32 ) * 4 ) ;
if ( V_11 . V_12 )
V_11 . V_12 ( V_2 ) ;
F_8 ( & V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_2 V_8 = 1 << ( F_4 ( V_2 ) % 32 ) ;
F_6 ( & V_9 ) ;
if ( V_11 . V_13 )
V_11 . V_13 ( V_2 ) ;
F_7 ( V_8 , F_1 ( V_2 ) + V_14 + ( F_4 ( V_2 ) / 32 ) * 4 ) ;
F_8 ( & V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_11 . V_15 ) {
F_6 ( & V_9 ) ;
V_11 . V_15 ( V_2 ) ;
F_8 ( & V_9 ) ;
}
F_7 ( F_4 ( V_2 ) , F_3 ( V_2 ) + V_16 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int type )
{
void T_1 * V_17 = F_1 ( V_2 ) ;
unsigned int V_18 = F_4 ( V_2 ) ;
T_2 V_19 = 1 << ( V_18 % 32 ) ;
T_2 V_20 = ( V_18 / 32 ) * 4 ;
T_2 V_21 = 0x2 << ( ( V_18 % 16 ) * 2 ) ;
T_2 V_22 = ( V_18 / 16 ) * 4 ;
bool V_23 = false ;
T_2 V_24 ;
if ( V_18 < 16 )
return - V_25 ;
if ( type != V_26 && type != V_27 )
return - V_25 ;
F_6 ( & V_9 ) ;
if ( V_11 . V_28 )
V_11 . V_28 ( V_2 , type ) ;
V_24 = F_12 ( V_17 + V_29 + V_22 ) ;
if ( type == V_26 )
V_24 &= ~ V_21 ;
else if ( type == V_27 )
V_24 |= V_21 ;
if ( F_12 ( V_17 + V_14 + V_20 ) & V_19 ) {
F_7 ( V_19 , V_17 + V_10 + V_20 ) ;
V_23 = true ;
}
F_7 ( V_24 , V_17 + V_29 + V_22 ) ;
if ( V_23 )
F_7 ( V_19 , V_17 + V_14 + V_20 ) ;
F_8 ( & V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
if ( V_11 . V_30 )
return V_11 . V_30 ( V_2 ) ;
return - V_31 ;
}
static int F_14 ( struct V_1 * V_2 , const struct V_32 * V_33 ,
bool V_34 )
{
void T_1 * V_35 = F_1 ( V_2 ) + V_36 + ( F_4 ( V_2 ) & ~ 3 ) ;
unsigned int V_37 = ( F_4 ( V_2 ) % 4 ) * 8 ;
unsigned int V_38 = F_15 ( V_33 , V_39 ) ;
T_2 V_24 , V_8 , V_40 ;
if ( V_38 >= 8 || V_38 >= V_41 )
return - V_25 ;
V_8 = 0xff << V_37 ;
V_40 = 1 << ( F_16 ( V_38 ) + V_37 ) ;
F_6 ( & V_9 ) ;
V_24 = F_12 ( V_35 ) & ~ V_8 ;
F_7 ( V_24 | V_40 , V_35 ) ;
F_8 ( & V_9 ) ;
return V_42 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_43 )
{
int V_44 = - V_31 ;
if ( V_11 . V_45 )
V_44 = V_11 . V_45 ( V_2 , V_43 ) ;
return V_44 ;
}
static void F_18 ( unsigned int V_46 , struct V_47 * V_48 )
{
struct V_3 * V_49 = F_19 ( V_46 ) ;
struct V_50 * V_51 = F_20 ( V_46 ) ;
unsigned int V_52 , F_4 ;
unsigned long V_53 ;
F_21 ( V_51 , V_48 ) ;
F_6 ( & V_9 ) ;
V_53 = F_12 ( V_49 -> V_6 + V_54 ) ;
F_8 ( & V_9 ) ;
F_4 = ( V_53 & 0x3ff ) ;
if ( F_4 == 1023 )
goto V_55;
V_52 = F_22 ( & V_49 -> V_56 , F_4 ) ;
if ( F_23 ( F_4 < 32 || F_4 > 1020 || V_52 >= V_57 ) )
F_24 ( V_52 , V_48 ) ;
else
F_25 ( V_52 ) ;
V_55:
F_26 ( V_51 , V_48 ) ;
}
void T_3 F_27 ( unsigned int V_58 , unsigned int V_46 )
{
if ( V_58 >= V_59 )
F_28 () ;
if ( F_29 ( V_46 , & V_4 [ V_58 ] ) != 0 )
F_28 () ;
F_30 ( V_46 , F_18 ) ;
}
static void T_3 F_31 ( struct V_3 * V_60 )
{
unsigned int V_61 , V_46 ;
T_2 V_32 ;
unsigned int V_62 = V_60 -> V_62 ;
struct V_63 * V_56 = & V_60 -> V_56 ;
void T_1 * V_17 = V_60 -> V_5 ;
T_2 V_38 = 0 ;
#ifdef F_32
V_38 = F_16 ( F_33 () ) ;
#endif
V_32 = 1 << V_38 ;
V_32 |= V_32 << 8 ;
V_32 |= V_32 << 16 ;
F_7 ( 0 , V_17 + V_64 ) ;
for ( V_61 = 32 ; V_61 < V_62 ; V_61 += 16 )
F_7 ( 0 , V_17 + V_29 + V_61 * 4 / 16 ) ;
for ( V_61 = 32 ; V_61 < V_62 ; V_61 += 4 )
F_7 ( V_32 , V_17 + V_36 + V_61 * 4 / 4 ) ;
for ( V_61 = 32 ; V_61 < V_62 ; V_61 += 4 )
F_7 ( 0xa0a0a0a0 , V_17 + V_65 + V_61 * 4 / 4 ) ;
for ( V_61 = 32 ; V_61 < V_62 ; V_61 += 32 )
F_7 ( 0xffffffff , V_17 + V_10 + V_61 * 4 / 32 ) ;
F_34 (domain, i, irq) {
if ( V_61 < 32 ) {
F_35 ( V_46 ) ;
F_36 ( V_46 , & V_66 ,
V_67 ) ;
F_37 ( V_46 , V_68 | V_69 ) ;
} else {
F_36 ( V_46 , & V_66 ,
V_70 ) ;
F_37 ( V_46 , V_68 | V_71 ) ;
}
F_38 ( V_46 , V_60 ) ;
}
F_7 ( 1 , V_17 + V_64 ) ;
}
static void T_4 F_39 ( struct V_3 * V_60 )
{
void T_1 * V_5 = V_60 -> V_5 ;
void T_1 * V_17 = V_60 -> V_6 ;
int V_61 ;
F_7 ( 0xffff0000 , V_5 + V_10 ) ;
F_7 ( 0x0000ffff , V_5 + V_14 ) ;
for ( V_61 = 0 ; V_61 < 32 ; V_61 += 4 )
F_7 ( 0xa0a0a0a0 , V_5 + V_65 + V_61 * 4 / 4 ) ;
F_7 ( 0xf0 , V_17 + V_72 ) ;
F_7 ( 1 , V_17 + V_73 ) ;
}
static void F_40 ( unsigned int V_58 )
{
unsigned int V_62 ;
void T_1 * V_5 ;
int V_61 ;
if ( V_58 >= V_59 )
F_28 () ;
V_62 = V_4 [ V_58 ] . V_62 ;
V_5 = V_4 [ V_58 ] . V_5 ;
if ( ! V_5 )
return;
for ( V_61 = 0 ; V_61 < F_41 ( V_62 , 16 ) ; V_61 ++ )
V_4 [ V_58 ] . V_74 [ V_61 ] =
F_12 ( V_5 + V_29 + V_61 * 4 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( V_62 , 4 ) ; V_61 ++ )
V_4 [ V_58 ] . V_75 [ V_61 ] =
F_12 ( V_5 + V_36 + V_61 * 4 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( V_62 , 32 ) ; V_61 ++ )
V_4 [ V_58 ] . V_76 [ V_61 ] =
F_12 ( V_5 + V_14 + V_61 * 4 ) ;
}
static void F_42 ( unsigned int V_58 )
{
unsigned int V_62 ;
unsigned int V_61 ;
void T_1 * V_5 ;
if ( V_58 >= V_59 )
F_28 () ;
V_62 = V_4 [ V_58 ] . V_62 ;
V_5 = V_4 [ V_58 ] . V_5 ;
if ( ! V_5 )
return;
F_7 ( 0 , V_5 + V_64 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( V_62 , 16 ) ; V_61 ++ )
F_7 ( V_4 [ V_58 ] . V_74 [ V_61 ] ,
V_5 + V_29 + V_61 * 4 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( V_62 , 4 ) ; V_61 ++ )
F_7 ( 0xa0a0a0a0 ,
V_5 + V_65 + V_61 * 4 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( V_62 , 4 ) ; V_61 ++ )
F_7 ( V_4 [ V_58 ] . V_75 [ V_61 ] ,
V_5 + V_36 + V_61 * 4 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( V_62 , 32 ) ; V_61 ++ )
F_7 ( V_4 [ V_58 ] . V_76 [ V_61 ] ,
V_5 + V_14 + V_61 * 4 ) ;
F_7 ( 1 , V_5 + V_64 ) ;
}
static void F_43 ( unsigned int V_58 )
{
int V_61 ;
T_2 * V_77 ;
void T_1 * V_5 ;
void T_1 * V_6 ;
if ( V_58 >= V_59 )
F_28 () ;
V_5 = V_4 [ V_58 ] . V_5 ;
V_6 = V_4 [ V_58 ] . V_6 ;
if ( ! V_5 || ! V_6 )
return;
V_77 = F_44 ( V_4 [ V_58 ] . V_78 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( 32 , 32 ) ; V_61 ++ )
V_77 [ V_61 ] = F_12 ( V_5 + V_14 + V_61 * 4 ) ;
V_77 = F_44 ( V_4 [ V_58 ] . V_79 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( 32 , 16 ) ; V_61 ++ )
V_77 [ V_61 ] = F_12 ( V_5 + V_29 + V_61 * 4 ) ;
}
static void F_45 ( unsigned int V_58 )
{
int V_61 ;
T_2 * V_77 ;
void T_1 * V_5 ;
void T_1 * V_6 ;
if ( V_58 >= V_59 )
F_28 () ;
V_5 = V_4 [ V_58 ] . V_5 ;
V_6 = V_4 [ V_58 ] . V_6 ;
if ( ! V_5 || ! V_6 )
return;
V_77 = F_44 ( V_4 [ V_58 ] . V_78 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( 32 , 32 ) ; V_61 ++ )
F_7 ( V_77 [ V_61 ] , V_5 + V_14 + V_61 * 4 ) ;
V_77 = F_44 ( V_4 [ V_58 ] . V_79 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( 32 , 16 ) ; V_61 ++ )
F_7 ( V_77 [ V_61 ] , V_5 + V_29 + V_61 * 4 ) ;
for ( V_61 = 0 ; V_61 < F_41 ( 32 , 4 ) ; V_61 ++ )
F_7 ( 0xa0a0a0a0 , V_5 + V_65 + V_61 * 4 ) ;
F_7 ( 0xf0 , V_6 + V_72 ) ;
F_7 ( 1 , V_6 + V_73 ) ;
}
static int F_46 ( struct V_80 * V_81 , unsigned long V_82 , void * V_83 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ ) {
switch ( V_82 ) {
case V_84 :
F_43 ( V_61 ) ;
break;
case V_85 :
case V_86 :
F_45 ( V_61 ) ;
break;
case V_87 :
F_40 ( V_61 ) ;
break;
case V_88 :
case V_89 :
F_42 ( V_61 ) ;
break;
}
}
return V_90 ;
}
static void T_3 F_47 ( struct V_3 * V_60 )
{
V_60 -> V_78 = F_48 ( F_41 ( 32 , 32 ) * 4 ,
sizeof( T_2 ) ) ;
F_49 ( ! V_60 -> V_78 ) ;
V_60 -> V_79 = F_48 ( F_41 ( 32 , 16 ) * 4 ,
sizeof( T_2 ) ) ;
F_49 ( ! V_60 -> V_79 ) ;
if ( V_60 == & V_4 [ 0 ] )
F_50 ( & V_91 ) ;
}
static void T_3 F_47 ( struct V_3 * V_60 )
{
}
static int F_51 ( struct V_63 * V_2 ,
struct V_92 * V_93 ,
const T_2 * V_94 , unsigned int V_95 ,
unsigned long * V_96 , unsigned int * V_97 )
{
if ( V_2 -> V_98 != V_93 )
return - V_25 ;
if ( V_95 < 3 )
return - V_25 ;
* V_96 = V_94 [ 1 ] + 16 ;
if ( ! V_94 [ 0 ] )
* V_96 += 16 ;
* V_97 = V_94 [ 2 ] & V_99 ;
return 0 ;
}
void T_3 F_52 ( unsigned int V_58 , int V_100 ,
void T_1 * V_5 , void T_1 * V_6 )
{
struct V_3 * V_60 ;
struct V_63 * V_56 ;
int V_62 ;
F_49 ( V_58 >= V_59 ) ;
V_60 = & V_4 [ V_58 ] ;
V_56 = & V_60 -> V_56 ;
V_60 -> V_5 = V_5 ;
V_60 -> V_6 = V_6 ;
V_56 -> V_101 = 32 ;
if ( V_58 == 0 ) {
V_102 = V_6 ;
if ( ( V_100 & 31 ) > 0 ) {
V_56 -> V_101 = 16 ;
if ( V_100 != - 1 )
V_100 = ( V_100 & ~ 31 ) + 16 ;
}
}
V_62 = F_12 ( V_5 + V_103 ) & 0x1f ;
V_62 = ( V_62 + 1 ) * 32 ;
if ( V_62 > 1020 )
V_62 = 1020 ;
V_60 -> V_62 = V_62 ;
V_56 -> V_104 = V_62 - V_56 -> V_101 ;
V_56 -> V_105 = F_53 ( V_100 , 16 , V_56 -> V_104 ,
F_54 () ) ;
if ( F_55 ( V_56 -> V_105 ) ) {
F_56 ( 1 , L_1 ,
V_100 ) ;
V_56 -> V_105 = V_100 ;
}
V_56 -> V_106 = V_60 ;
V_56 -> V_107 = & V_108 ;
F_57 ( V_56 ) ;
V_66 . V_109 |= V_11 . V_109 ;
F_31 ( V_60 ) ;
F_39 ( V_60 ) ;
F_47 ( V_60 ) ;
}
void T_4 F_58 ( unsigned int V_58 )
{
F_49 ( V_58 >= V_59 ) ;
F_39 ( & V_4 [ V_58 ] ) ;
}
void F_59 ( const struct V_32 * V_8 , unsigned int V_46 )
{
int V_38 ;
unsigned long V_110 = 0 ;
F_60 (cpu, mask)
V_110 |= 1 << F_16 ( V_38 ) ;
F_61 () ;
F_7 ( V_110 << 16 | V_46 , V_4 [ 0 ] . V_5 + V_111 ) ;
}
int T_3 F_62 ( struct V_92 * V_112 , struct V_92 * V_113 )
{
void T_1 * V_6 ;
void T_1 * V_5 ;
int V_46 ;
struct V_63 * V_56 = & V_4 [ V_114 ] . V_56 ;
if ( F_63 ( ! V_112 ) )
return - V_115 ;
V_5 = F_64 ( V_112 , 0 ) ;
F_56 ( ! V_5 , L_2 ) ;
V_6 = F_64 ( V_112 , 1 ) ;
F_56 ( ! V_6 , L_3 ) ;
V_56 -> V_98 = F_65 ( V_112 ) ;
F_52 ( V_114 , - 1 , V_5 , V_6 ) ;
if ( V_113 ) {
V_46 = F_66 ( V_112 , 0 ) ;
F_27 ( V_114 , V_46 ) ;
}
V_114 ++ ;
return 0 ;
}
