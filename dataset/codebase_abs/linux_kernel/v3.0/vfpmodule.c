static void F_1 ( struct V_1 * V_2 )
{
union V_3 * V_4 = & V_2 -> V_5 ;
unsigned int V_6 ;
memset ( V_4 , 0 , sizeof( union V_3 ) ) ;
V_4 -> V_7 . V_8 = V_9 ;
V_4 -> V_7 . V_10 = V_11 ;
V_6 = F_2 () ;
if ( V_12 [ V_6 ] == V_4 )
V_12 [ V_6 ] = NULL ;
F_3 ( V_13 , F_4 ( V_13 ) & ~ V_9 ) ;
F_5 () ;
}
static void F_6 ( struct V_1 * V_2 )
{
union V_3 * V_4 = & V_2 -> V_5 ;
unsigned int V_6 = F_2 () ;
if ( V_12 [ V_6 ] == V_4 )
V_12 [ V_6 ] = NULL ;
F_5 () ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_1 * V_14 = F_8 () ;
F_9 ( V_14 ) ;
V_2 -> V_5 = V_14 -> V_5 ;
}
static int F_10 ( struct V_15 * V_16 , unsigned long V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
T_1 V_8 ;
#ifdef F_11
unsigned int V_6 ;
#endif
switch ( V_17 ) {
case V_19 :
V_8 = F_4 ( V_13 ) ;
#ifdef F_11
V_6 = V_2 -> V_6 ;
if ( ( V_8 & V_9 ) && V_12 [ V_6 ] ) {
F_12 ( V_12 [ V_6 ] , V_8 ) ;
V_12 [ V_6 ] -> V_7 . V_6 = V_6 ;
}
if ( V_2 -> V_5 . V_7 . V_6 != V_6 )
V_12 [ V_6 ] = NULL ;
#endif
F_3 ( V_13 , V_8 & ~ V_9 ) ;
break;
case V_20 :
F_1 ( V_2 ) ;
break;
case V_21 :
F_6 ( V_2 ) ;
break;
case V_22 :
F_7 ( V_2 ) ;
break;
}
return V_23 ;
}
static void F_13 ( unsigned int V_24 , struct V_25 * V_26 )
{
T_2 V_27 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_28 = V_29 ;
V_27 . V_30 = V_24 ;
V_27 . V_31 = ( void V_32 * ) ( F_14 ( V_26 ) - 4 ) ;
V_33 -> V_2 . V_34 = 0 ;
V_33 -> V_2 . V_35 = 6 ;
F_15 ( V_29 , & V_27 , V_33 ) ;
}
static void F_16 ( char * V_36 , T_1 V_37 )
{
int V_38 ;
F_17 ( V_39 L_1 , V_36 ) ;
F_17 ( V_39 L_2 ,
F_4 ( V_13 ) , F_4 ( V_40 ) , V_37 ) ;
for ( V_38 = 0 ; V_38 < 32 ; V_38 += 2 )
F_17 ( V_39 L_3 ,
V_38 , F_18 ( V_38 ) , V_38 + 1 , F_18 ( V_38 + 1 ) ) ;
}
static void F_19 ( T_1 V_41 , T_1 V_37 , T_1 V_10 , struct V_25 * V_26 )
{
int V_30 = 0 ;
F_20 ( L_4 , V_41 ) ;
if ( V_41 == V_42 ) {
F_16 ( L_5 , V_37 ) ;
F_13 ( 0 , V_26 ) ;
return;
}
if ( V_41 & ( V_43 | V_44 | V_45 | V_46 ) )
V_10 &= ~ ( V_43 | V_44 | V_45 | V_46 ) ;
V_10 |= V_41 ;
F_3 ( V_40 , V_10 ) ;
#define RAISE ( T_3 , T_4 , T_5 ) \
if (exceptions & stat && fpscr & en) \
si_code = sig;
RAISE ( V_47 , V_48 , V_49 ) ;
RAISE ( V_50 , V_51 , V_52 ) ;
RAISE ( V_53 , V_54 , V_55 ) ;
RAISE ( V_56 , V_57 , V_58 ) ;
RAISE ( V_59 , V_60 , V_61 ) ;
if ( V_30 )
F_13 ( V_30 , V_26 ) ;
}
static T_1 F_21 ( T_1 V_37 , T_1 V_10 , struct V_25 * V_26 )
{
T_1 V_41 = V_42 ;
F_20 ( L_6 , V_37 , V_10 ) ;
if ( F_22 ( V_37 ) ) {
if ( ! F_23 ( V_37 ) ) {
if ( F_24 ( V_37 ) ) {
V_41 = F_25 ( V_37 , V_10 ) ;
} else {
V_41 = F_26 ( V_37 , V_10 ) ;
}
} else {
}
} else {
}
return V_41 & ~ V_62 ;
}
void F_27 ( T_1 V_63 , T_1 V_8 , struct V_25 * V_26 )
{
T_1 V_10 , V_64 , V_65 , V_41 ;
F_20 ( L_7 , V_63 , V_8 ) ;
F_3 ( V_13 , V_8 & ~ ( V_66 | V_67 | V_68 | V_69 | V_70 ) ) ;
V_65 = F_4 ( V_71 ) ;
V_64 = V_10 = F_4 ( V_40 ) ;
if ( ( V_65 & V_72 ) == ( 1 << V_73 )
&& ( V_10 & V_51 ) ) {
goto V_74;
}
if ( V_8 & V_66 ) {
#ifndef F_28
V_63 = F_4 ( V_75 ) ;
V_26 -> V_76 -= 4 ;
#endif
} else if ( ! ( V_8 & V_67 ) ) {
F_19 ( V_42 , V_63 , V_10 , V_26 ) ;
goto exit;
}
if ( V_8 & ( V_66 | V_69 ) ) {
T_1 V_77 ;
V_77 = V_8 + ( 1 << V_78 ) ;
V_10 &= ~ V_79 ;
V_10 |= ( V_77 & V_80 ) << ( V_81 - V_78 ) ;
}
V_41 = F_21 ( V_63 , V_10 , V_26 ) ;
if ( V_41 )
F_19 ( V_41 , V_63 , V_64 , V_26 ) ;
if ( V_8 ^ ( V_66 | V_68 ) )
goto exit;
F_29 () ;
V_63 = F_4 ( V_82 ) ;
V_74:
V_41 = F_21 ( V_63 , V_64 , V_26 ) ;
if ( V_41 )
F_19 ( V_41 , V_63 , V_64 , V_26 ) ;
exit:
F_30 () ;
}
static void F_31 ( void * V_83 )
{
T_1 V_84 = F_32 () ;
F_33 ( V_84 | F_34 ( 10 ) | F_34 ( 11 ) ) ;
}
static int F_35 ( void )
{
struct V_1 * V_85 = F_8 () ;
T_1 V_8 = F_4 ( V_13 ) ;
if ( V_8 & V_9 ) {
F_17 ( V_86 L_8 , V_87 ) ;
F_12 ( & V_85 -> V_5 , V_8 ) ;
F_3 ( V_13 , F_4 ( V_13 ) & ~ V_9 ) ;
}
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
return 0 ;
}
static void F_36 ( void )
{
F_31 ( NULL ) ;
F_3 ( V_13 , F_4 ( V_13 ) & ~ V_9 ) ;
}
static void F_37 ( void )
{
F_38 ( & V_88 ) ;
}
static inline void F_37 ( void ) { }
void F_9 ( struct V_1 * V_2 )
{
unsigned int V_6 = F_2 () ;
if ( V_12 [ V_6 ] == & V_2 -> V_5 ) {
T_1 V_8 = F_4 ( V_13 ) ;
F_3 ( V_13 , V_8 | V_9 ) ;
F_12 ( & V_2 -> V_5 , V_8 | V_9 ) ;
F_3 ( V_13 , V_8 ) ;
}
F_5 () ;
}
void F_39 ( struct V_1 * V_2 )
{
unsigned int V_6 = F_2 () ;
if ( V_12 [ V_6 ] == & V_2 -> V_5 ) {
T_1 V_8 = F_4 ( V_13 ) ;
F_3 ( V_13 , V_8 & ~ V_9 ) ;
V_12 [ V_6 ] = NULL ;
}
#ifdef F_11
V_2 -> V_5 . V_7 . V_6 = V_89 ;
#endif
F_5 () ;
}
static int F_40 ( struct V_15 * V_90 , unsigned long V_91 ,
void * V_92 )
{
if ( V_91 == V_93 || V_91 == V_94 ) {
unsigned int V_6 = ( long ) V_92 ;
V_12 [ V_6 ] = NULL ;
} else if ( V_91 == V_95 || V_91 == V_96 )
F_31 ( NULL ) ;
return V_97 ;
}
static int T_6 F_41 ( void )
{
unsigned int V_98 ;
unsigned int V_99 = F_42 () ;
if ( V_99 >= V_100 )
F_31 ( NULL ) ;
V_101 = V_102 ;
F_29 () ;
V_98 = F_4 ( V_71 ) ;
F_29 () ;
V_101 = V_103 ;
F_17 ( V_104 L_9 ) ;
if ( V_105 )
F_17 ( L_10 ) ;
else if ( V_98 & V_106 ) {
F_17 ( L_11 ) ;
} else {
F_43 ( F_40 , 0 ) ;
F_44 ( F_31 , NULL , 1 ) ;
V_105 = ( V_98 & V_72 ) >> V_73 ;
F_17 ( L_12 ,
( V_98 & V_107 ) >> V_108 ,
( V_98 & V_72 ) >> V_73 ,
( V_98 & V_109 ) >> V_110 ,
( V_98 & V_111 ) >> V_112 ,
( V_98 & V_113 ) >> V_114 ) ;
V_101 = V_115 ;
F_45 ( & V_116 ) ;
F_37 () ;
V_117 |= V_118 ;
#ifdef F_46
if ( V_105 >= 2 ) {
V_117 |= V_119 ;
if ( ( ( F_4 ( V_120 ) & V_121 ) ) == 1 )
V_117 |= V_122 ;
}
#endif
#ifdef F_47
if ( ( F_48 () & 0x000f0000 ) == 0x000f0000 ) {
if ( ( F_4 ( V_123 ) & 0x000fff00 ) == 0x00011100 )
V_117 |= V_124 ;
}
#endif
}
return 0 ;
}
