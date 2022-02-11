static inline enum V_1 F_1 ( unsigned int V_2 )
{
unsigned long V_3 = ( V_2 >> 21 ) & 1 ;
if ( ! V_3 )
return V_4 ;
else {
switch ( ( V_2 >> 19 ) & 0xf ) {
case 15 :
return V_5 ;
default:
return V_6 ;
}
}
}
static inline int F_2 ( struct V_7 * V_8 , unsigned int V_2 )
{
unsigned int V_3 ;
V_3 = ( ( V_2 >> 19 ) & 0xf ) ;
if ( V_3 == 11 || V_3 == 14 )
return 8 ;
V_3 &= 3 ;
if ( ! V_3 )
return 4 ;
else if ( V_3 == 3 )
return 16 ;
else if ( V_3 == 2 )
return 2 ;
else {
F_3 ( L_1 , V_2 ) ;
F_4 ( L_2 , V_8 ) ;
return 0 ;
}
}
static inline int F_5 ( unsigned int V_2 , struct V_7 * V_8 )
{
if ( V_2 & 0x800000 ) {
if ( V_2 & 0x2000 )
return ( unsigned char ) ( V_8 -> V_9 >> 24 ) ;
else
return ( unsigned char ) ( V_2 >> 5 ) ;
} else
return V_10 ;
}
static inline int F_6 ( unsigned int V_2 )
{
return ( V_2 & 0x400000 ) ;
}
static inline void F_7 ( unsigned int V_11 , unsigned int V_12 ,
unsigned int V_13 , int V_14 )
{
if ( V_12 >= 16 || V_11 >= 16 || V_13 >= 16 ) {
if ( V_14 != 0 )
__asm__ __volatile__("flushw");
else
F_8 () ;
}
}
static inline long F_9 ( long V_15 )
{
return V_15 << 51 >> 51 ;
}
static unsigned long F_10 ( unsigned int V_16 , struct V_7 * V_8 )
{
unsigned long V_17 , V_18 ;
if ( V_16 < 16 )
return ( ! V_16 ? 0 : V_8 -> V_19 [ V_16 ] ) ;
V_18 = V_8 -> V_19 [ V_20 ] ;
if ( V_8 -> V_9 & V_21 ) {
struct V_22 * V_23 ;
V_23 = (struct V_22 * ) ( V_18 + V_24 ) ;
V_17 = V_23 -> V_25 [ V_16 - 16 ] ;
} else if ( ! F_11 ( V_18 ) ) {
struct V_26 T_1 * V_27 ;
V_27 = (struct V_26 T_1 * ) ( ( unsigned long ) ( ( V_28 ) V_18 ) ) ;
F_12 ( V_17 , & V_27 -> V_25 [ V_16 - 16 ] ) ;
} else {
struct V_22 T_1 * V_23 ;
V_23 = (struct V_22 T_1 * ) ( V_18 + V_24 ) ;
F_12 ( V_17 , & V_23 -> V_25 [ V_16 - 16 ] ) ;
}
return V_17 ;
}
static unsigned long * F_13 ( unsigned int V_16 , struct V_7 * V_8 )
{
unsigned long V_18 ;
if ( V_16 < 16 )
return & V_8 -> V_19 [ V_16 ] ;
V_18 = V_8 -> V_19 [ V_20 ] ;
if ( V_8 -> V_9 & V_21 ) {
struct V_22 * V_23 ;
V_23 = (struct V_22 * ) ( V_18 + V_24 ) ;
return & V_23 -> V_25 [ V_16 - 16 ] ;
} else if ( ! F_11 ( V_18 ) ) {
struct V_26 * V_27 ;
V_27 = (struct V_26 * ) ( ( unsigned long ) ( ( V_28 ) V_18 ) ) ;
return ( unsigned long * ) & V_27 -> V_25 [ V_16 - 16 ] ;
} else {
struct V_22 * V_23 ;
V_23 = (struct V_22 * ) ( V_18 + V_24 ) ;
return & V_23 -> V_25 [ V_16 - 16 ] ;
}
}
unsigned long F_14 ( struct V_7 * V_8 ,
unsigned int V_2 , unsigned int V_13 )
{
int V_14 = ( V_8 -> V_9 & V_21 ) != 0 ;
unsigned int V_11 = ( V_2 >> 14 ) & 0x1f ;
unsigned int V_12 = V_2 & 0x1f ;
unsigned long V_29 ;
if ( V_2 & 0x2000 ) {
F_7 ( V_11 , 0 , V_13 , V_14 ) ;
V_29 = ( F_10 ( V_11 , V_8 ) + F_9 ( V_2 ) ) ;
} else {
F_7 ( V_11 , V_12 , V_13 , V_14 ) ;
V_29 = ( F_10 ( V_11 , V_8 ) + F_10 ( V_12 , V_8 ) ) ;
}
if ( ! V_14 && F_15 ( V_30 ) )
V_29 &= 0xffffffff ;
return V_29 ;
}
static void T_2 F_16 ( char * V_31 , struct V_7 * V_8 )
{
F_4 ( V_31 , V_8 ) ;
}
static inline int F_17 ( int V_32 , int V_33 , unsigned long * V_34 ,
struct V_7 * V_8 , int V_35 , int V_36 )
{
unsigned long V_37 = 0 ;
unsigned long * V_38 = & V_37 ;
unsigned long V_39 ;
if ( V_33 == 16 ) {
V_33 = 8 ;
V_37 = ( ( ( long ) ( V_32 ?
( unsigned ) F_10 ( V_32 , V_8 ) : 0 ) ) << 32 ) |
( unsigned ) F_10 ( V_32 + 1 , V_8 ) ;
} else if ( V_32 ) {
V_38 = F_13 ( V_32 , V_8 ) ;
}
V_39 = * V_38 ;
if ( F_18 ( V_35 != V_36 ) ) {
switch ( V_33 ) {
case 2 :
V_39 = F_19 ( V_39 ) ;
break;
case 4 :
V_39 = F_20 ( V_39 ) ;
break;
case 8 :
V_39 = F_21 ( V_39 ) ;
break;
case 16 :
default:
F_22 () ;
break;
}
}
return F_23 ( V_34 , V_33 , V_39 , V_35 ) ;
}
static inline void F_24 ( struct V_7 * V_8 )
{
V_8 -> V_40 = V_8 -> V_41 ;
V_8 -> V_41 += 4 ;
if ( F_15 ( V_30 ) ) {
V_8 -> V_40 &= 0xffffffff ;
V_8 -> V_41 &= 0xffffffff ;
}
}
static inline int F_25 ( unsigned int V_2 )
{
return ( V_2 >> 24 ) & 1 ;
}
static inline int F_26 ( unsigned int V_2 )
{
return ! F_25 ( V_2 ) ;
}
static void F_27 ( int V_42 )
{
struct V_7 * V_8 = F_28 () -> V_43 ;
unsigned int V_2 = F_28 () -> V_44 ;
const struct V_45 * V_46 ;
V_46 = F_29 ( V_8 -> V_40 ) ;
if ( ! V_46 ) {
unsigned long V_47 ;
V_47 = F_14 ( V_8 , V_2 ,
( ( V_2 >> 25 ) & 0x1f ) ) ;
if ( V_47 < V_48 ) {
F_3 ( V_49 L_3
L_4 ) ;
} else
F_3 ( V_49 L_5
L_6 ) ;
F_3 ( V_49 L_7 , V_47 ) ;
F_3 ( V_49 L_8 ,
( V_50 -> V_51 ? F_30 ( V_50 -> V_51 -> V_52 ) :
F_30 ( V_50 -> V_53 -> V_52 ) ) ) ;
F_3 ( V_49 L_9 ,
( V_50 -> V_51 ? ( unsigned long ) V_50 -> V_51 -> V_54 :
( unsigned long ) V_50 -> V_53 -> V_54 ) ) ;
F_4 ( L_10 , V_8 ) ;
}
V_8 -> V_40 = V_46 -> V_55 ;
V_8 -> V_41 = V_8 -> V_40 + 4 ;
if ( V_42 ) {
V_8 -> V_9 &= ~ V_56 ;
V_8 -> V_9 |= ( V_57 << 24UL ) ;
}
}
static void F_31 ( struct V_7 * V_8 )
{
static F_32 ( V_58 , 5 * V_59 , 5 ) ;
if ( F_33 ( & V_58 ) ) {
F_3 ( L_11 ,
V_8 -> V_40 , ( void * ) V_8 -> V_40 ) ;
}
}
T_3 void F_34 ( struct V_7 * V_8 , unsigned int V_2 )
{
enum V_1 V_60 = F_1 ( V_2 ) ;
int V_33 = F_2 ( V_8 , V_2 ) ;
int V_36 , V_35 ;
F_28 () -> V_43 = V_8 ;
F_28 () -> V_44 = V_2 ;
V_36 = V_35 = F_5 ( V_2 , V_8 ) ;
if ( V_35 == V_57 ) {
F_27 ( 0 ) ;
return;
}
F_31 ( V_8 ) ;
if ( ! F_26 ( V_2 ) || V_60 == V_5 ) {
F_3 ( L_12
L_13 , V_8 -> V_40 ) ;
F_16 ( L_14
L_15 , V_8 ) ;
F_27 ( 0 ) ;
} else {
unsigned long V_29 , * V_61 ;
int V_62 ;
V_29 = F_14 ( V_8 , V_2 ,
( ( V_2 >> 25 ) & 0x1f ) ) ;
F_35 ( V_63 , 1 , V_8 , V_29 ) ;
switch ( V_35 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_35 &= ~ 0x08 ;
break;
}
switch ( V_60 ) {
case V_4 :
V_61 = F_13 ( ( ( V_2 >> 25 ) & 0x1f ) , V_8 ) ;
V_62 = F_36 ( V_61 , V_33 ,
( unsigned long * ) V_29 ,
F_6 ( V_2 ) , V_35 ) ;
if ( F_37 ( ! V_62 ) && F_18 ( V_35 != V_36 ) ) {
unsigned long V_71 = * V_61 ;
switch ( V_33 ) {
case 2 :
V_71 = F_19 ( V_71 ) ;
break;
case 4 :
V_71 = F_20 ( V_71 ) ;
break;
case 8 :
V_71 = F_21 ( V_71 ) ;
break;
case 16 :
default:
F_22 () ;
break;
}
* V_61 = V_71 ;
}
break;
case V_6 :
V_62 = F_17 ( ( ( V_2 >> 25 ) & 0x1f ) , V_33 ,
( unsigned long * ) V_29 , V_8 ,
V_35 , V_36 ) ;
break;
default:
F_38 ( L_16 ) ;
}
if ( F_18 ( V_62 ) )
F_27 ( 1 ) ;
else
F_24 ( V_8 ) ;
}
}
int F_39 ( V_28 V_2 , struct V_7 * V_8 )
{
int V_14 = ( V_8 -> V_9 & V_21 ) != 0 ;
int V_72 , V_13 = ( ( V_2 >> 25 ) & 0x1f ) ;
T_4 V_17 ;
F_35 ( V_73 , 1 , V_8 , 0 ) ;
if ( V_2 & 0x2000 ) {
F_7 ( 0 , 0 , V_13 , V_14 ) ;
V_17 = F_9 ( V_2 ) ;
} else {
F_7 ( 0 , V_2 & 0x1f , V_13 , V_14 ) ;
V_17 = F_10 ( V_2 & 0x1f , V_8 ) ;
}
V_72 = F_40 ( V_17 ) ;
if ( V_13 < 16 ) {
if ( V_13 )
V_8 -> V_19 [ V_13 ] = V_72 ;
} else {
unsigned long V_18 = V_8 -> V_19 [ V_20 ] ;
if ( ! F_11 ( V_18 ) ) {
struct V_26 T_1 * V_27 ;
V_27 = (struct V_26 T_1 * ) ( ( unsigned long ) ( ( V_28 ) V_18 ) ) ;
F_41 ( V_72 , & V_27 -> V_25 [ V_13 - 16 ] ) ;
} else {
struct V_22 T_1 * V_23 ;
V_23 = (struct V_22 T_1 * ) ( V_18 + V_24 ) ;
F_41 ( V_72 , & V_23 -> V_25 [ V_13 - 16 ] ) ;
}
}
F_24 ( V_8 ) ;
return 1 ;
}
int F_42 ( V_28 V_2 , struct V_7 * V_8 )
{
unsigned long V_29 = F_14 ( V_8 , V_2 , 0 ) ;
int V_74 ;
struct V_75 * V_76 = V_77 ;
int V_35 = F_5 ( V_2 , V_8 ) ;
int V_78 ;
F_35 ( V_73 , 1 , V_8 , 0 ) ;
F_43 () ;
F_28 () -> V_79 [ 0 ] &= ~ 0x1c000 ;
if ( V_2 & 0x200000 ) {
T_4 V_80 = 0 , V_81 = 0 ;
V_74 = ( ( V_2 >> 25 ) & 0x1e ) | ( ( V_2 >> 20 ) & 0x20 ) ;
V_78 = ( V_74 < 32 ) ? V_82 : V_83 ;
if ( V_74 & 3 ) {
F_28 () -> V_79 [ 0 ] |= ( 6 << 14 ) ;
F_44 ( V_8 ) ;
return 0 ;
}
if ( F_28 () -> V_84 [ 0 ] & V_78 ) {
V_80 = * ( T_4 * ) & V_76 -> V_8 [ V_74 ] ;
V_81 = * ( T_4 * ) & V_76 -> V_8 [ V_74 + 2 ] ;
}
if ( V_35 < 0x80 ) {
F_45 ( V_8 ) ;
return 1 ;
}
switch ( V_35 ) {
case V_10 :
case V_85 : break;
case V_67 :
case V_68 :
{
T_4 V_3 = F_46 ( & V_80 ) ;
V_80 = F_46 ( & V_81 ) ;
V_81 = V_3 ;
break;
}
default:
if ( V_86 == V_87 )
F_47 ( V_8 , V_29 , 0 ) ;
else
F_48 ( V_8 , 0 , V_29 ) ;
return 1 ;
}
if ( F_41 ( V_80 >> 32 , ( V_28 T_1 * ) V_29 ) ||
F_49 ( ( V_28 ) V_80 , ( V_28 T_1 * ) ( V_29 + 4 ) ) ||
F_49 ( V_81 >> 32 , ( V_28 T_1 * ) ( V_29 + 8 ) ) ||
F_49 ( ( V_28 ) V_81 , ( V_28 T_1 * ) ( V_29 + 12 ) ) ) {
if ( V_86 == V_87 )
F_47 ( V_8 , V_29 , 0 ) ;
else
F_48 ( V_8 , 0 , V_29 ) ;
return 1 ;
}
} else {
V_28 V_88 [ 4 ] V_89 ( ( F_50 ( 8 ) ) ) ;
int V_33 , V_90 ;
int V_62 ;
if ( V_35 < 0x80 ) {
F_45 ( V_8 ) ;
return 1 ;
} else if ( V_35 > V_70 ) {
if ( V_86 == V_87 )
F_47 ( V_8 , V_29 , 0 ) ;
else
F_48 ( V_8 , 0 , V_29 ) ;
return 1 ;
}
switch ( V_2 & 0x180000 ) {
case 0x000000 : V_33 = 1 ; break;
case 0x100000 : V_33 = 4 ; break;
default: V_33 = 2 ; break;
}
if ( V_33 == 1 )
V_74 = ( V_2 >> 25 ) & 0x1f ;
else
V_74 = ( ( V_2 >> 25 ) & 0x1e ) | ( ( V_2 >> 20 ) & 0x20 ) ;
V_78 = ( V_74 < 32 ) ? V_82 : V_83 ;
for ( V_90 = 0 ; V_90 < V_33 ; V_90 ++ )
V_88 [ V_90 ] = 0 ;
V_62 = F_12 ( V_88 [ 0 ] , ( V_28 T_1 * ) V_29 ) ;
if ( ! V_62 ) {
for ( V_90 = 1 ; V_90 < V_33 ; V_90 ++ )
V_62 |= F_51 ( V_88 [ V_90 ] , ( V_28 T_1 * ) ( V_29 + 4 * V_90 ) ) ;
}
if ( V_62 && ! ( V_35 & 0x2 ) ) {
if ( V_86 == V_87 )
F_47 ( V_8 , V_29 , 0 ) ;
else
F_48 ( V_8 , 0 , V_29 ) ;
return 1 ;
}
if ( V_35 & 0x8 ) {
T_4 V_3 ;
switch ( V_33 ) {
case 1 : V_88 [ 0 ] = F_52 ( V_88 + 0 ) ; break;
default: * ( T_4 * ) ( V_88 + 0 ) = F_53 ( ( T_4 * ) ( V_88 + 0 ) ) ;
break;
case 4 : V_3 = F_53 ( ( T_4 * ) ( V_88 + 0 ) ) ;
* ( T_4 * ) ( V_88 + 0 ) = F_53 ( ( T_4 * ) ( V_88 + 2 ) ) ;
* ( T_4 * ) ( V_88 + 2 ) = V_3 ;
break;
}
}
if ( ! ( F_28 () -> V_84 [ 0 ] & V_91 ) ) {
F_28 () -> V_84 [ 0 ] = V_91 ;
F_28 () -> V_92 [ 0 ] = 0 ;
}
if ( ! ( F_28 () -> V_84 [ 0 ] & V_78 ) ) {
if ( V_74 < 32 )
memset ( V_76 -> V_8 , 0 , 32 * sizeof( V_28 ) ) ;
else
memset ( V_76 -> V_8 + 32 , 0 , 32 * sizeof( V_28 ) ) ;
}
memcpy ( V_76 -> V_8 + V_74 , V_88 , V_33 * 4 ) ;
F_28 () -> V_84 [ 0 ] |= V_78 ;
}
F_24 ( V_8 ) ;
return 1 ;
}
void F_54 ( V_28 V_2 , struct V_7 * V_8 )
{
int V_13 = ( ( V_2 >> 25 ) & 0x1f ) ;
int V_14 = ( V_8 -> V_9 & V_21 ) != 0 ;
unsigned long * V_16 ;
F_35 ( V_73 , 1 , V_8 , 0 ) ;
F_7 ( 0 , 0 , V_13 , V_14 ) ;
V_16 = F_13 ( V_13 , V_8 ) ;
if ( V_14 || V_13 < 16 ) {
V_16 [ 0 ] = 0 ;
if ( ( V_2 & 0x780000 ) == 0x180000 )
V_16 [ 1 ] = 0 ;
} else if ( ! F_11 ( V_8 -> V_19 [ V_20 ] ) ) {
F_41 ( 0 , ( int T_1 * ) V_16 ) ;
if ( ( V_2 & 0x780000 ) == 0x180000 )
F_41 ( 0 , ( ( int T_1 * ) V_16 ) + 1 ) ;
} else {
F_41 ( 0 , ( unsigned long T_1 * ) V_16 ) ;
if ( ( V_2 & 0x780000 ) == 0x180000 )
F_41 ( 0 , ( unsigned long T_1 * ) V_16 + 1 ) ;
}
F_24 ( V_8 ) ;
}
void F_55 ( struct V_7 * V_8 , unsigned long V_93 , unsigned long V_94 )
{
enum V_95 V_96 = F_56 () ;
unsigned long V_97 = V_8 -> V_40 ;
unsigned long V_9 = V_8 -> V_9 ;
V_28 V_2 ;
T_4 V_17 ;
T_5 V_74 ;
int V_78 ;
struct V_75 * V_76 = V_77 ;
if ( V_9 & V_21 )
F_4 ( L_17 , V_8 ) ;
F_35 ( V_63 , 1 , V_8 , V_93 ) ;
if ( F_15 ( V_30 ) )
V_97 = ( V_28 ) V_97 ;
if ( F_12 ( V_2 , ( V_28 T_1 * ) V_97 ) != - V_98 ) {
int V_35 = F_5 ( V_2 , V_8 ) ;
V_28 V_80 , V_81 ;
int V_62 ;
if ( ( V_35 > V_70 ) ||
( V_35 < V_10 ) )
goto V_99;
V_80 = V_81 = 0 ;
V_62 = F_12 ( V_80 , ( V_28 T_1 * ) V_93 ) ;
if ( ! V_62 )
V_62 = F_12 ( V_81 , ( V_28 T_1 * ) ( V_93 + 4 ) ) ;
if ( V_62 ) {
if ( ! ( V_35 & 0x2 ) )
goto V_99;
V_80 = V_81 = 0 ;
}
F_43 () ;
V_74 = ( ( V_2 >> 25 ) & 0x1e ) | ( ( V_2 >> 20 ) & 0x20 ) ;
V_17 = ( ( ( T_4 ) V_80 ) << 32 ) | V_81 ;
if ( V_35 & 0x8 )
V_17 = F_46 ( & V_17 ) ;
V_78 = ( V_74 < 32 ) ? V_82 : V_83 ;
if ( ! ( F_28 () -> V_84 [ 0 ] & V_91 ) ) {
F_28 () -> V_84 [ 0 ] = V_91 ;
F_28 () -> V_92 [ 0 ] = 0 ;
}
if ( ! ( F_28 () -> V_84 [ 0 ] & V_78 ) ) {
if ( V_74 < 32 )
memset ( V_76 -> V_8 , 0 , 32 * sizeof( V_28 ) ) ;
else
memset ( V_76 -> V_8 + 32 , 0 , 32 * sizeof( V_28 ) ) ;
}
* ( T_4 * ) ( V_76 -> V_8 + V_74 ) = V_17 ;
F_28 () -> V_84 [ 0 ] |= V_78 ;
} else {
V_99:
if ( V_86 == V_87 )
F_47 ( V_8 , V_93 , V_94 ) ;
else
F_48 ( V_8 , V_94 , V_93 ) ;
goto V_100;
}
F_24 ( V_8 ) ;
V_100:
F_57 ( V_96 ) ;
}
void F_58 ( struct V_7 * V_8 , unsigned long V_93 , unsigned long V_94 )
{
enum V_95 V_96 = F_56 () ;
unsigned long V_97 = V_8 -> V_40 ;
unsigned long V_9 = V_8 -> V_9 ;
V_28 V_2 ;
T_4 V_17 ;
T_5 V_74 ;
int V_78 ;
struct V_75 * V_76 = V_77 ;
if ( V_9 & V_21 )
F_4 ( L_18 , V_8 ) ;
F_35 ( V_63 , 1 , V_8 , V_93 ) ;
if ( F_15 ( V_30 ) )
V_97 = ( V_28 ) V_97 ;
if ( F_12 ( V_2 , ( V_28 T_1 * ) V_97 ) != - V_98 ) {
int V_35 = F_5 ( V_2 , V_8 ) ;
V_74 = ( ( V_2 >> 25 ) & 0x1e ) | ( ( V_2 >> 20 ) & 0x20 ) ;
V_17 = 0 ;
V_78 = ( V_74 < 32 ) ? V_82 : V_83 ;
if ( ( V_35 > V_70 ) ||
( V_35 < V_10 ) )
goto V_99;
F_43 () ;
if ( F_28 () -> V_84 [ 0 ] & V_78 )
V_17 = * ( T_4 * ) & V_76 -> V_8 [ V_74 ] ;
switch ( V_35 ) {
case V_10 :
case V_85 : break;
case V_67 :
case V_68 :
V_17 = F_46 ( & V_17 ) ; break;
default: goto V_99;
}
if ( F_41 ( V_17 >> 32 , ( V_28 T_1 * ) V_93 ) ||
F_49 ( ( V_28 ) V_17 , ( V_28 T_1 * ) ( V_93 + 4 ) ) )
goto V_99;
} else {
V_99:
if ( V_86 == V_87 )
F_47 ( V_8 , V_93 , V_94 ) ;
else
F_48 ( V_8 , V_94 , V_93 ) ;
goto V_100;
}
F_24 ( V_8 ) ;
V_100:
F_57 ( V_96 ) ;
}
