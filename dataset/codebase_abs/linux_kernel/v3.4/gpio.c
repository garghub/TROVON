static unsigned int F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
unsigned int V_3 = 0 ;
struct V_4 * V_5 = V_1 -> V_6 ;
unsigned long V_7 ;
unsigned long V_8 ;
F_2 ( & V_9 , V_8 ) ;
F_3 ( V_1 , & V_5 -> V_10 , V_2 ) ;
if ( V_5 -> V_11 == V_12 ) {
unsigned long V_13 ;
V_7 = * V_14 ;
V_13 = ~ V_7 & V_5 -> V_15 & 0xFF ;
V_13 = ( V_13 << V_16 ) ;
V_17 |= V_13 ;
* V_18 = V_13 ;
} else if ( V_5 -> V_11 == V_19 )
V_7 = * V_20 ;
else if ( V_5 -> V_11 == V_21 )
V_7 = * V_22 ;
else {
V_3 = 0 ;
goto V_23;
}
if ( ( V_7 & V_5 -> V_15 ) ||
( ~ V_7 & V_5 -> V_24 ) ) {
V_3 = V_25 | V_26 ;
}
V_23:
F_4 ( & V_9 , V_8 ) ;
F_5 ( F_6 ( L_1 , V_3 ) ) ;
return V_3 ;
}
int F_7 ( void )
{
struct V_4 * V_5 ;
unsigned long V_7 = 0 ;
int V_27 = 0 ;
unsigned long V_8 ;
F_2 ( & V_9 , V_8 ) ;
V_5 = V_28 ;
while ( V_5 ) {
if ( F_8 ( V_5 ) )
V_7 = * V_5 -> V_29 ;
else if ( V_5 -> V_11 == V_21 )
V_7 = * V_22 ;
if ( ( V_7 & V_5 -> V_15 ) ||
( ~ V_7 & V_5 -> V_24 ) ) {
F_5 ( F_6 ( L_2 , V_5 -> V_11 ) ) ;
F_9 ( & V_5 -> V_10 ) ;
V_27 = 1 ;
}
V_5 = V_5 -> V_30 ;
}
F_4 ( & V_9 , V_8 ) ;
return V_27 ;
}
static T_2
F_10 ( int V_31 , void * V_32 )
{
if ( V_33 ) {
F_7 () ;
return V_34 ;
}
return V_35 ;
}
static T_2
F_11 ( int V_31 , void * V_32 )
{
unsigned long V_13 ;
unsigned long V_8 ;
F_2 ( & V_9 , V_8 ) ;
V_13 = ( * V_36 ) ;
V_13 &= V_17 ;
* V_37 = V_13 ;
V_17 &= ~ V_13 ;
F_4 ( & V_9 , V_8 ) ;
if ( V_33 )
return F_12 ( F_7 () ) ;
return V_35 ;
}
static void F_13 ( struct V_4 * V_5 ,
unsigned char V_7 , int V_38 )
{
* V_5 -> V_29 = * V_5 -> V_39 &= ~ ( V_5 -> V_40 ) ;
if ( V_7 & 1 << V_38 )
* V_5 -> V_29 = * V_5 -> V_39 |= V_5 -> V_41 ;
else
* V_5 -> V_29 = * V_5 -> V_39 &= ~ ( V_5 -> V_41 ) ;
* V_5 -> V_29 = * V_5 -> V_39 |= V_5 -> V_40 ;
}
static void F_14 ( struct V_4 * V_5 , unsigned char V_7 )
{
int V_42 ;
if ( V_5 -> V_43 )
for ( V_42 = 7 ; V_42 >= 0 ; V_42 -- )
F_13 ( V_5 , V_7 , V_42 ) ;
else
for ( V_42 = 0 ; V_42 <= 7 ; V_42 ++ )
F_13 ( V_5 , V_7 , V_42 ) ;
}
static T_3 F_15 ( struct V_1 * V_1 , const char T_4 * V_44 ,
T_5 V_45 , T_6 * V_46 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
unsigned long V_8 ;
T_3 V_47 = V_45 ;
if ( V_5 -> V_11 != V_12 && V_5 -> V_11 != V_19 )
return - V_48 ;
if ( ! F_16 ( V_49 , V_44 , V_45 ) )
return - V_48 ;
F_2 ( & V_9 , V_8 ) ;
if ( V_5 -> V_40 == 0 || V_5 -> V_41 == 0 ) {
V_47 = - V_50 ;
goto V_23;
}
F_17 ( F_6 ( V_51 L_3
L_4 ,
V_45 , V_5 -> V_41 , V_5 -> V_40 , V_5 -> V_43 ) ) ;
while ( V_45 -- )
F_14 ( V_5 , * V_44 ++ ) ;
V_23:
F_4 ( & V_9 , V_8 ) ;
return V_47 ;
}
static int
F_18 ( struct V_52 * V_52 , struct V_1 * V_53 )
{
struct V_4 * V_5 ;
int V_54 = F_19 ( V_52 ) ;
unsigned long V_8 ;
if ( V_54 > V_55 )
return - V_56 ;
V_5 = F_20 ( sizeof( struct V_4 ) , V_57 ) ;
if ( ! V_5 )
return - V_58 ;
V_5 -> V_11 = V_54 ;
if ( F_8 ( V_5 ) ) {
V_5 -> V_29 = V_59 [ V_54 ] ;
V_5 -> V_39 = V_60 [ V_54 ] ;
V_5 -> V_61 = V_61 [ V_54 ] ;
V_5 -> V_62 = V_62 [ V_54 ] ;
V_5 -> V_63 = V_63 [ V_54 ] ;
V_5 -> V_64 = V_64 [ V_54 ] ;
} else {
V_5 -> V_29 = NULL ;
V_5 -> V_39 = NULL ;
V_5 -> V_61 = NULL ;
V_5 -> V_62 = NULL ;
V_5 -> V_63 = 0 ;
V_5 -> V_64 = 0 ;
}
V_5 -> V_15 = 0 ;
V_5 -> V_24 = 0 ;
V_5 -> V_40 = 0 ;
V_5 -> V_41 = 0 ;
F_21 ( & V_5 -> V_10 ) ;
V_53 -> V_6 = V_5 ;
F_2 ( & V_9 , V_8 ) ;
V_5 -> V_30 = V_28 ;
V_28 = V_5 ;
F_4 ( & V_9 , V_8 ) ;
return 0 ;
}
static int
F_22 ( struct V_52 * V_52 , struct V_1 * V_53 )
{
struct V_4 * V_54 ;
struct V_4 * V_65 ;
unsigned long V_8 ;
F_2 ( & V_9 , V_8 ) ;
V_54 = V_28 ;
V_65 = V_53 -> V_6 ;
if ( V_54 == V_65 ) {
V_28 = V_65 -> V_30 ;
} else {
while ( V_54 -> V_30 != V_65 )
V_54 = V_54 -> V_30 ;
V_54 -> V_30 = V_65 -> V_30 ;
}
F_23 ( V_65 ) ;
V_54 = V_28 ;
while ( V_54 ) {
if ( V_54 -> V_15 | V_54 -> V_24 ) {
V_33 = 1 ;
goto V_23;
}
V_54 = V_54 -> V_30 ;
}
V_33 = 0 ;
V_23:
F_4 ( & V_9 , V_8 ) ;
return 0 ;
}
unsigned long inline F_24 ( struct V_4 * V_5 , unsigned long V_66 )
{
if ( F_8 ( V_5 ) ) {
* V_5 -> V_61 = * V_5 -> V_62 &=
~ ( ( unsigned char ) V_66 & V_5 -> V_63 ) ;
return ~ ( * V_5 -> V_62 ) & 0xFF ;
}
if ( V_5 -> V_11 != V_21 )
return 0 ;
if ( ( ( V_66 & V_67 ) != V_66 ) &&
( V_66 & V_68 ) ) {
V_66 &= V_68 ;
if ( V_66 & ( 1 << 0 ) ) {
V_69 &= ~ F_25 ( V_70 , V_71 ) ;
V_67 |= ( 1 << 0 ) ;
V_72 &= ~ ( 1 << 0 ) ;
}
if ( ( V_66 & 0x0000FF00 ) == 0x0000FF00 ) {
V_69 &= ~ F_25 ( V_70 , V_73 ) ;
V_67 |= 0x0000FF00 ;
V_72 &= ~ 0x0000FF00 ;
}
if ( ( V_66 & 0x00FF0000 ) == 0x00FF0000 ) {
V_69 &= ~ F_25 ( V_70 , V_74 ) ;
V_67 |= 0x00FF0000 ;
V_72 &= ~ 0x00FF0000 ;
}
if ( V_66 & ( 1 << 24 ) ) {
V_69 &= ~ F_25 ( V_70 , V_75 ) ;
V_67 |= ( 1 << 24 ) ;
V_72 &= ~ ( 1 << 24 ) ;
}
F_17 ( F_6 ( V_51 L_5
L_6
L_7
L_8 ,
( unsigned long ) V_69 ,
V_67 , V_72 ) ) ;
* V_70 = V_69 ;
}
return V_67 ;
}
unsigned long inline F_26 ( struct V_4 * V_5 , unsigned long V_66 )
{
if ( F_8 ( V_5 ) ) {
* V_5 -> V_61 = * V_5 -> V_62 |=
( ( unsigned char ) V_66 & V_5 -> V_63 ) ;
return * V_5 -> V_62 ;
}
if ( V_5 -> V_11 != V_21 )
return 0 ;
if ( ( ( V_66 & V_72 ) != V_66 ) &&
( V_66 & V_68 ) ) {
if ( V_66 & ( 1 << 0 ) ) {
V_69 |= F_25 ( V_70 , V_71 ) ;
V_72 |= ( 1 << 0 ) ;
V_67 &= ~ ( 1 << 0 ) ;
}
if ( ( V_66 & 0x0000FF00 ) == 0x0000FF00 ) {
V_69 |= F_25 ( V_70 , V_73 ) ;
V_72 |= 0x0000FF00 ;
V_67 &= ~ 0x0000FF00 ;
}
if ( ( V_66 & 0x00FF0000 ) == 0x00FF0000 ) {
V_69 |= F_25 ( V_70 , V_74 ) ;
V_72 |= 0x00FF0000 ;
V_67 &= ~ 0x00FF0000 ;
}
if ( V_66 & ( 1 << 24 ) ) {
V_69 |= F_25 ( V_70 , V_75 ) ;
V_72 |= ( 1 << 24 ) ;
V_67 &= ~ ( 1 << 24 ) ;
}
F_17 ( F_6 ( V_76 L_9
L_6
L_7
L_8 ,
( unsigned long ) V_69 ,
V_67 , V_72 ) ) ;
* V_70 = V_69 ;
}
return V_72 & 0x7FFFFFFF ;
}
static long F_27 ( struct V_1 * V_1 , unsigned int V_77 , unsigned long V_66 )
{
unsigned long V_8 ;
unsigned long V_78 ;
int V_27 = 0 ;
struct V_4 * V_5 = V_1 -> V_6 ;
if ( F_28 ( V_77 ) != V_79 )
return - V_56 ;
switch ( F_29 ( V_77 ) ) {
case V_80 :
F_2 ( & V_9 , V_8 ) ;
if ( F_8 ( V_5 ) ) {
V_27 = * V_5 -> V_29 ;
} else if ( V_5 -> V_11 == V_21 ) {
V_27 = ( * V_22 ) & 0x7FFFFFFF ;
}
F_4 ( & V_9 , V_8 ) ;
break;
case V_81 :
F_2 ( & V_9 , V_8 ) ;
if ( F_8 ( V_5 ) ) {
* V_5 -> V_29 = * V_5 -> V_39 |=
( ( unsigned char ) V_66 & V_5 -> V_64 ) ;
} else if ( V_5 -> V_11 == V_21 ) {
* V_22 = V_82 |= ( V_66 & V_72 ) ;
}
F_4 ( & V_9 , V_8 ) ;
break;
case V_83 :
F_2 ( & V_9 , V_8 ) ;
if ( F_8 ( V_5 ) ) {
* V_5 -> V_29 = * V_5 -> V_39 &=
~ ( ( unsigned char ) V_66 & V_5 -> V_64 ) ;
} else if ( V_5 -> V_11 == V_21 ) {
* V_22 = V_82 &= ~ ( ( unsigned long ) V_66 & V_72 ) ;
}
F_4 ( & V_9 , V_8 ) ;
break;
case V_84 :
F_2 ( & V_9 , V_8 ) ;
V_5 -> V_15 |= V_66 ;
V_33 = 1 ;
F_4 ( & V_9 , V_8 ) ;
break;
case V_85 :
F_2 ( & V_9 , V_8 ) ;
V_5 -> V_24 |= V_66 ;
V_33 = 1 ;
F_4 ( & V_9 , V_8 ) ;
break;
case V_86 :
F_2 ( & V_9 , V_8 ) ;
V_5 -> V_15 &= ~ V_66 ;
V_5 -> V_24 &= ~ V_66 ;
{
struct V_4 * V_54 = V_28 ;
int V_87 ;
V_54 = V_28 ;
V_87 = 0 ;
while ( V_54 ) {
if ( V_54 -> V_15 | V_54 -> V_24 ) {
V_87 = 1 ;
break;
}
V_54 = V_54 -> V_30 ;
}
V_33 = V_87 ;
}
F_4 ( & V_9 , V_8 ) ;
break;
case V_88 :
F_2 ( & V_9 , V_8 ) ;
if ( F_8 ( V_5 ) ) {
V_27 = * V_5 -> V_62 ;
} else if ( V_5 -> V_11 == V_21 ) {
V_27 = ( V_89 | V_72 ) & 0x7FFFFFFF ;
}
F_4 ( & V_9 , V_8 ) ;
break;
case V_90 :
F_2 ( & V_9 , V_8 ) ;
V_27 = F_24 ( V_5 , V_66 ) & 0x7FFFFFFF ;
F_4 ( & V_9 , V_8 ) ;
break;
case V_91 :
F_2 ( & V_9 , V_8 ) ;
V_27 = F_26 ( V_5 , V_66 ) & 0x7FFFFFFF ;
F_4 ( & V_9 , V_8 ) ;
break;
case V_92 :
F_2 ( & V_9 , V_8 ) ;
F_30 () ;
F_4 ( & V_9 , V_8 ) ;
break;
case V_93 :
F_2 ( & V_9 , V_8 ) ;
#if F_31 ( V_94 )
V_27 = ( * V_22 & ( 1 << V_95 ) ) ;
#else
V_27 = 0 ;
#endif
F_4 ( & V_9 , V_8 ) ;
break;
case V_96 :
F_2 ( & V_9 , V_8 ) ;
V_5 -> V_40 = V_66 & 0xFF ;
V_5 -> V_41 = ( V_66 >> 8 ) & 0xFF ;
V_5 -> V_43 = ( V_66 >> 16 ) & 0x01 ;
if ( ! ( ( V_5 -> V_40 & V_5 -> V_64 ) &&
( V_5 -> V_41 & V_5 -> V_64 ) &&
( V_5 -> V_40 & * V_5 -> V_62 ) &&
( V_5 -> V_41 & * V_5 -> V_62 ) ) )
{
V_5 -> V_40 = 0 ;
V_5 -> V_41 = 0 ;
V_27 = - V_50 ;
}
F_4 ( & V_9 , V_8 ) ;
break;
case V_97 :
F_2 ( & V_9 , V_8 ) ;
if ( F_8 ( V_5 ) ) {
V_78 = * V_5 -> V_29 ;
} else if ( V_5 -> V_11 == V_21 ) {
V_78 = * V_22 ;
}
F_4 ( & V_9 , V_8 ) ;
if ( F_32 ( ( void T_4 * ) V_66 , & V_78 , sizeof( V_78 ) ) )
V_27 = - V_48 ;
break;
case V_98 :
F_2 ( & V_9 , V_8 ) ;
if ( F_8 ( V_5 ) ) {
V_78 = * V_5 -> V_39 ;
} else if ( V_5 -> V_11 == V_21 ) {
V_78 = V_82 ;
}
F_4 ( & V_9 , V_8 ) ;
if ( F_32 ( ( void T_4 * ) V_66 , & V_78 , sizeof( V_78 ) ) )
V_27 = - V_48 ;
break;
case V_99 :
if ( F_33 ( & V_78 , ( void T_4 * ) V_66 , sizeof( V_78 ) ) )
{
V_27 = - V_48 ;
break;
}
F_2 ( & V_9 , V_8 ) ;
V_78 = F_24 ( V_5 , V_78 ) ;
F_4 ( & V_9 , V_8 ) ;
if ( F_32 ( ( void T_4 * ) V_66 , & V_78 , sizeof( V_78 ) ) )
V_27 = - V_48 ;
break;
case V_100 :
if ( F_33 ( & V_78 , ( void T_4 * ) V_66 , sizeof( V_78 ) ) ) {
V_27 = - V_48 ;
break;
}
F_2 ( & V_9 , V_8 ) ;
V_78 = F_26 ( V_5 , V_78 ) ;
F_4 ( & V_9 , V_8 ) ;
if ( F_32 ( ( void T_4 * ) V_66 , & V_78 , sizeof( V_78 ) ) )
V_27 = - V_48 ;
break;
default:
F_2 ( & V_9 , V_8 ) ;
if ( V_5 -> V_11 == V_101 )
V_27 = F_34 ( V_77 , V_66 ) ;
else
V_27 = - V_56 ;
F_4 ( & V_9 , V_8 ) ;
}
return V_27 ;
}
static int
F_34 ( unsigned int V_77 , unsigned long V_66 )
{
unsigned char V_102 ;
unsigned char V_103 ;
switch ( F_29 ( V_77 ) ) {
case V_104 :
V_102 = ( ( unsigned char ) V_66 ) & 1 ;
V_103 = ( ( ( unsigned char ) V_66 ) >> 1 ) & 1 ;
F_35 ( V_102 ) ;
F_36 ( V_103 ) ;
break;
case V_105 :
F_37 ( V_66 ) ;
break;
case V_106 :
F_38 ( V_66 ) ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static void F_39 ( const unsigned int V_107 ,
const unsigned int V_108 ,
const unsigned char V_109 ,
const unsigned char V_110 )
{
unsigned long int V_8 ;
F_17 ( F_6 ( V_51 L_10 ) ) ;
F_17 ( F_6 ( V_51 L_11
L_12 ,
V_107 , V_108 ,
V_109 , V_110 ) ) ;
F_2 ( & V_9 , V_8 ) ;
V_67 = V_107 ;
V_72 = V_108 ;
if ( V_69 & F_40 ( V_70 , V_71 , V_23 ) )
V_89 |= ( 1 << 0 ) ;
if ( V_69 & F_40 ( V_70 , V_73 , V_23 ) )
V_89 |= 0x0000FF00 ;
if ( V_69 & F_40 ( V_70 , V_74 , V_23 ) )
V_89 |= 0x00FF0000 ;
if ( V_69 & F_40 ( V_70 , V_75 , V_23 ) )
V_89 |= ( 1 << 24 ) ;
V_68 = V_111 ;
V_68 &= V_72 ;
V_68 &= V_67 ;
V_72 &= ~ V_68 ;
V_72 |= V_89 ;
V_67 &= ~ V_68 ;
V_67 |= ( ~ V_89 & V_68 ) ;
F_4 ( & V_9 , V_8 ) ;
F_6 ( V_76 L_13
L_14 ,
V_67 , V_72 , ( unsigned long ) * V_22 ) ;
F_6 ( V_76 L_15 ,
V_89 , V_68 ) ;
}
static int T_7 F_41 ( void )
{
int V_112 ;
#if F_31 ( V_113 )
int V_42 ;
#endif
V_112 = F_42 ( V_114 , V_115 , & V_116 ) ;
if ( V_112 < 0 ) {
F_6 ( V_117 L_16 ) ;
return V_112 ;
}
#if F_31 ( V_113 ) || F_31 ( V_118 ) || F_31 ( V_119 )
F_43 ( 0 ) ;
F_44 ( 0 ) ;
F_45 ( 0 ) ;
F_46 ( 0 ) ;
#if F_31 ( V_113 )
for ( V_42 = 0 ; V_42 < 32 ; V_42 ++ )
F_37 ( V_42 ) ;
#endif
#endif
if ( F_47 ( F_39 ) ) {
F_6 ( V_120 L_17
L_18 ) ;
}
F_6 ( V_76 L_19
L_20 ) ;
V_112 = F_48 ( V_121 , F_10 ,
V_122 | V_123 , L_21 , V_115 ) ;
if ( V_112 ) {
F_6 ( V_124 L_22 ) ;
return V_112 ;
}
V_112 = F_48 ( V_125 , F_11 ,
V_122 | V_123 , L_23 , V_115 ) ;
if ( V_112 )
F_6 ( V_124 L_24 ) ;
return V_112 ;
}
