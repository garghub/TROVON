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
unsigned long V_17 ;
if ( V_16 < 16 )
return ( ! V_16 ? 0 : V_8 -> V_18 [ V_16 ] ) ;
if ( V_8 -> V_9 & V_19 ) {
struct V_20 * V_21 ;
V_21 = (struct V_20 * ) ( V_8 -> V_18 [ V_22 ] + V_23 ) ;
V_17 = V_21 -> V_24 [ V_16 - 16 ] ;
} else if ( F_11 ( V_25 ) ) {
struct V_26 T_1 * V_27 ;
V_27 = (struct V_26 T_1 * ) ( ( unsigned long ) ( ( V_28 ) V_8 -> V_18 [ V_22 ] ) ) ;
F_12 ( V_17 , & V_27 -> V_24 [ V_16 - 16 ] ) ;
} else {
struct V_20 T_1 * V_21 ;
V_21 = (struct V_20 T_1 * ) ( V_8 -> V_18 [ V_22 ] + V_23 ) ;
F_12 ( V_17 , & V_21 -> V_24 [ V_16 - 16 ] ) ;
}
return V_17 ;
}
static unsigned long * F_13 ( unsigned int V_16 , struct V_7 * V_8 )
{
if ( V_16 < 16 )
return & V_8 -> V_18 [ V_16 ] ;
if ( V_8 -> V_9 & V_19 ) {
struct V_20 * V_21 ;
V_21 = (struct V_20 * ) ( V_8 -> V_18 [ V_22 ] + V_23 ) ;
return & V_21 -> V_24 [ V_16 - 16 ] ;
} else if ( F_11 ( V_25 ) ) {
struct V_26 * V_27 ;
V_27 = (struct V_26 * ) ( ( unsigned long ) ( ( V_28 ) V_8 -> V_18 [ V_22 ] ) ) ;
return ( unsigned long * ) & V_27 -> V_24 [ V_16 - 16 ] ;
} else {
struct V_20 * V_21 ;
V_21 = (struct V_20 * ) ( V_8 -> V_18 [ V_22 ] + V_23 ) ;
return & V_21 -> V_24 [ V_16 - 16 ] ;
}
}
unsigned long F_14 ( struct V_7 * V_8 ,
unsigned int V_2 , unsigned int V_13 )
{
unsigned int V_11 = ( V_2 >> 14 ) & 0x1f ;
unsigned int V_12 = V_2 & 0x1f ;
int V_14 = ( V_8 -> V_9 & V_19 ) != 0 ;
if ( V_2 & 0x2000 ) {
F_7 ( V_11 , 0 , V_13 , V_14 ) ;
return ( F_10 ( V_11 , V_8 ) + F_9 ( V_2 ) ) ;
} else {
F_7 ( V_11 , V_12 , V_13 , V_14 ) ;
return ( F_10 ( V_11 , V_8 ) + F_10 ( V_12 , V_8 ) ) ;
}
}
static void T_2 F_15 ( char * V_29 , struct V_7 * V_8 )
{
F_4 ( V_29 , V_8 ) ;
}
static inline int F_16 ( int V_30 , int V_31 , unsigned long * V_32 ,
struct V_7 * V_8 , int V_33 , int V_34 )
{
unsigned long V_35 = 0 ;
unsigned long * V_36 = & V_35 ;
unsigned long V_37 ;
if ( V_31 == 16 ) {
V_31 = 8 ;
V_35 = ( ( ( long ) ( V_30 ?
( unsigned ) F_10 ( V_30 , V_8 ) : 0 ) ) << 32 ) |
( unsigned ) F_10 ( V_30 + 1 , V_8 ) ;
} else if ( V_30 ) {
V_36 = F_13 ( V_30 , V_8 ) ;
}
V_37 = * V_36 ;
if ( F_17 ( V_33 != V_34 ) ) {
switch ( V_31 ) {
case 2 :
V_37 = F_18 ( V_37 ) ;
break;
case 4 :
V_37 = F_19 ( V_37 ) ;
break;
case 8 :
V_37 = F_20 ( V_37 ) ;
break;
case 16 :
default:
F_21 () ;
break;
}
}
return F_22 ( V_32 , V_31 , V_37 , V_33 ) ;
}
static inline void F_23 ( struct V_7 * V_8 )
{
V_8 -> V_38 = V_8 -> V_39 ;
V_8 -> V_39 += 4 ;
if ( F_11 ( V_25 ) ) {
V_8 -> V_38 &= 0xffffffff ;
V_8 -> V_39 &= 0xffffffff ;
}
}
static inline int F_24 ( unsigned int V_2 )
{
return ( V_2 >> 24 ) & 1 ;
}
static inline int F_25 ( unsigned int V_2 )
{
return ! F_24 ( V_2 ) ;
}
static void F_26 ( int V_40 )
{
struct V_7 * V_8 = F_27 () -> V_41 ;
unsigned int V_2 = F_27 () -> V_42 ;
const struct V_43 * V_44 ;
V_44 = F_28 ( V_8 -> V_38 ) ;
if ( ! V_44 ) {
unsigned long V_45 ;
V_45 = F_14 ( V_8 , V_2 ,
( ( V_2 >> 25 ) & 0x1f ) ) ;
if ( V_45 < V_46 ) {
F_3 ( V_47 L_3
L_4 ) ;
} else
F_3 ( V_47 L_5
L_6 ) ;
F_3 ( V_47 L_7 , V_45 ) ;
F_3 ( V_47 L_8 ,
( V_48 -> V_49 ? F_29 ( V_48 -> V_49 -> V_50 ) :
F_29 ( V_48 -> V_51 -> V_50 ) ) ) ;
F_3 ( V_47 L_9 ,
( V_48 -> V_49 ? ( unsigned long ) V_48 -> V_49 -> V_52 :
( unsigned long ) V_48 -> V_51 -> V_52 ) ) ;
F_4 ( L_10 , V_8 ) ;
}
V_8 -> V_38 = V_44 -> V_53 ;
V_8 -> V_39 = V_8 -> V_38 + 4 ;
if ( V_40 ) {
V_8 -> V_9 &= ~ V_54 ;
V_8 -> V_9 |= ( V_55 << 24UL ) ;
}
}
static void F_30 ( struct V_7 * V_8 )
{
static F_31 ( V_56 , 5 * V_57 , 5 ) ;
if ( F_32 ( & V_56 ) ) {
F_3 ( L_11 ,
V_8 -> V_38 , ( void * ) V_8 -> V_38 ) ;
}
}
T_3 void F_33 ( struct V_7 * V_8 , unsigned int V_2 )
{
enum V_1 V_58 = F_1 ( V_2 ) ;
int V_31 = F_2 ( V_8 , V_2 ) ;
int V_34 , V_33 ;
F_27 () -> V_41 = V_8 ;
F_27 () -> V_42 = V_2 ;
V_34 = V_33 = F_5 ( V_2 , V_8 ) ;
if ( V_33 == V_55 ) {
F_26 ( 0 ) ;
return;
}
F_30 ( V_8 ) ;
if ( ! F_25 ( V_2 ) || V_58 == V_5 ) {
F_3 ( L_12
L_13 , V_8 -> V_38 ) ;
F_15 ( L_14
L_15 , V_8 ) ;
F_26 ( 0 ) ;
} else {
unsigned long V_59 , * V_60 ;
int V_61 ;
V_59 = F_14 ( V_8 , V_2 ,
( ( V_2 >> 25 ) & 0x1f ) ) ;
F_34 ( V_62 , 1 , V_8 , V_59 ) ;
switch ( V_33 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_33 &= ~ 0x08 ;
break;
}
switch ( V_58 ) {
case V_4 :
V_60 = F_13 ( ( ( V_2 >> 25 ) & 0x1f ) , V_8 ) ;
V_61 = F_35 ( V_60 , V_31 ,
( unsigned long * ) V_59 ,
F_6 ( V_2 ) , V_33 ) ;
if ( F_36 ( ! V_61 ) && F_17 ( V_33 != V_34 ) ) {
unsigned long V_70 = * V_60 ;
switch ( V_31 ) {
case 2 :
V_70 = F_18 ( V_70 ) ;
break;
case 4 :
V_70 = F_19 ( V_70 ) ;
break;
case 8 :
V_70 = F_20 ( V_70 ) ;
break;
case 16 :
default:
F_21 () ;
break;
}
* V_60 = V_70 ;
}
break;
case V_6 :
V_61 = F_16 ( ( ( V_2 >> 25 ) & 0x1f ) , V_31 ,
( unsigned long * ) V_59 , V_8 ,
V_33 , V_34 ) ;
break;
default:
F_37 ( L_16 ) ;
}
if ( F_17 ( V_61 ) )
F_26 ( 1 ) ;
else
F_23 ( V_8 ) ;
}
}
int F_38 ( V_28 V_2 , struct V_7 * V_8 )
{
int V_14 = ( V_8 -> V_9 & V_19 ) != 0 ;
int V_71 , V_13 = ( ( V_2 >> 25 ) & 0x1f ) ;
T_4 V_17 ;
F_34 ( V_72 , 1 , V_8 , 0 ) ;
if ( V_2 & 0x2000 ) {
F_7 ( 0 , 0 , V_13 , V_14 ) ;
V_17 = F_9 ( V_2 ) ;
} else {
F_7 ( 0 , V_2 & 0x1f , V_13 , V_14 ) ;
V_17 = F_10 ( V_2 & 0x1f , V_8 ) ;
}
V_71 = F_39 ( V_17 ) ;
if ( V_13 < 16 ) {
if ( V_13 )
V_8 -> V_18 [ V_13 ] = V_71 ;
} else {
if ( F_11 ( V_25 ) ) {
struct V_26 T_1 * V_27 ;
V_27 = (struct V_26 T_1 * ) ( ( unsigned long ) ( ( V_28 ) V_8 -> V_18 [ V_22 ] ) ) ;
F_40 ( V_71 , & V_27 -> V_24 [ V_13 - 16 ] ) ;
} else {
struct V_20 T_1 * V_21 ;
V_21 = (struct V_20 T_1 * ) ( V_8 -> V_18 [ V_22 ] + V_23 ) ;
F_40 ( V_71 , & V_21 -> V_24 [ V_13 - 16 ] ) ;
}
}
F_23 ( V_8 ) ;
return 1 ;
}
int F_41 ( V_28 V_2 , struct V_7 * V_8 )
{
unsigned long V_59 = F_14 ( V_8 , V_2 , 0 ) ;
int V_73 = ( ( V_2 >> 25 ) & 0x1e ) | ( ( V_2 >> 20 ) & 0x20 ) ;
struct V_74 * V_75 = V_76 ;
int V_33 = F_5 ( V_2 , V_8 ) ;
int V_77 = ( V_73 < 32 ) ? V_78 : V_79 ;
F_34 ( V_72 , 1 , V_8 , 0 ) ;
F_42 () ;
F_27 () -> V_80 [ 0 ] &= ~ 0x1c000 ;
if ( V_73 & 3 ) {
F_27 () -> V_80 [ 0 ] |= ( 6 << 14 ) ;
F_43 ( V_8 ) ;
return 0 ;
}
if ( V_2 & 0x200000 ) {
T_4 V_81 = 0 , V_82 = 0 ;
if ( F_27 () -> V_83 [ 0 ] & V_77 ) {
V_81 = * ( T_4 * ) & V_75 -> V_8 [ V_73 ] ;
V_82 = * ( T_4 * ) & V_75 -> V_8 [ V_73 + 2 ] ;
}
if ( V_33 < 0x80 ) {
F_44 ( V_8 ) ;
return 1 ;
}
switch ( V_33 ) {
case V_10 :
case V_84 : break;
case V_66 :
case V_67 :
{
T_4 V_3 = F_45 ( & V_81 ) ;
V_81 = F_45 ( & V_82 ) ;
V_82 = V_3 ;
break;
}
default:
if ( V_85 == V_86 )
F_46 ( V_8 , V_59 , 0 ) ;
else
F_47 ( V_8 , 0 , V_59 ) ;
return 1 ;
}
if ( F_40 ( V_81 >> 32 , ( V_28 T_1 * ) V_59 ) ||
F_48 ( ( V_28 ) V_81 , ( V_28 T_1 * ) ( V_59 + 4 ) ) ||
F_48 ( V_82 >> 32 , ( V_28 T_1 * ) ( V_59 + 8 ) ) ||
F_48 ( ( V_28 ) V_82 , ( V_28 T_1 * ) ( V_59 + 12 ) ) ) {
if ( V_85 == V_86 )
F_46 ( V_8 , V_59 , 0 ) ;
else
F_47 ( V_8 , 0 , V_59 ) ;
return 1 ;
}
} else {
V_28 V_87 [ 4 ] V_88 ( ( F_49 ( 8 ) ) ) ;
int V_31 , V_89 ;
int V_61 ;
if ( V_33 < 0x80 ) {
F_44 ( V_8 ) ;
return 1 ;
} else if ( V_33 > V_69 ) {
if ( V_85 == V_86 )
F_46 ( V_8 , V_59 , 0 ) ;
else
F_47 ( V_8 , 0 , V_59 ) ;
return 1 ;
}
switch ( V_2 & 0x180000 ) {
case 0x000000 : V_31 = 1 ; break;
case 0x100000 : V_31 = 4 ; break;
default: V_31 = 2 ; break;
}
for ( V_89 = 0 ; V_89 < V_31 ; V_89 ++ )
V_87 [ V_89 ] = 0 ;
V_61 = F_12 ( V_87 [ 0 ] , ( V_28 T_1 * ) V_59 ) ;
if ( ! V_61 ) {
for ( V_89 = 1 ; V_89 < V_31 ; V_89 ++ )
V_61 |= F_50 ( V_87 [ V_89 ] , ( V_28 T_1 * ) ( V_59 + 4 * V_89 ) ) ;
}
if ( V_61 && ! ( V_33 & 0x2 ) ) {
if ( V_85 == V_86 )
F_46 ( V_8 , V_59 , 0 ) ;
else
F_47 ( V_8 , 0 , V_59 ) ;
return 1 ;
}
if ( V_33 & 0x8 ) {
T_4 V_3 ;
switch ( V_31 ) {
case 1 : V_87 [ 0 ] = F_51 ( V_87 + 0 ) ; break;
default: * ( T_4 * ) ( V_87 + 0 ) = F_52 ( ( T_4 * ) ( V_87 + 0 ) ) ;
break;
case 4 : V_3 = F_52 ( ( T_4 * ) ( V_87 + 0 ) ) ;
* ( T_4 * ) ( V_87 + 0 ) = F_52 ( ( T_4 * ) ( V_87 + 2 ) ) ;
* ( T_4 * ) ( V_87 + 2 ) = V_3 ;
break;
}
}
if ( ! ( F_27 () -> V_83 [ 0 ] & V_90 ) ) {
F_27 () -> V_83 [ 0 ] = V_90 ;
F_27 () -> V_91 [ 0 ] = 0 ;
}
if ( ! ( F_27 () -> V_83 [ 0 ] & V_77 ) ) {
if ( V_73 < 32 )
memset ( V_75 -> V_8 , 0 , 32 * sizeof( V_28 ) ) ;
else
memset ( V_75 -> V_8 + 32 , 0 , 32 * sizeof( V_28 ) ) ;
}
memcpy ( V_75 -> V_8 + V_73 , V_87 , V_31 * 4 ) ;
F_27 () -> V_83 [ 0 ] |= V_77 ;
}
F_23 ( V_8 ) ;
return 1 ;
}
void F_53 ( V_28 V_2 , struct V_7 * V_8 )
{
int V_13 = ( ( V_2 >> 25 ) & 0x1f ) ;
int V_14 = ( V_8 -> V_9 & V_19 ) != 0 ;
unsigned long * V_16 ;
F_34 ( V_72 , 1 , V_8 , 0 ) ;
F_7 ( 0 , 0 , V_13 , V_14 ) ;
V_16 = F_13 ( V_13 , V_8 ) ;
if ( V_14 || V_13 < 16 ) {
V_16 [ 0 ] = 0 ;
if ( ( V_2 & 0x780000 ) == 0x180000 )
V_16 [ 1 ] = 0 ;
} else if ( F_11 ( V_25 ) ) {
F_40 ( 0 , ( int T_1 * ) V_16 ) ;
if ( ( V_2 & 0x780000 ) == 0x180000 )
F_40 ( 0 , ( ( int T_1 * ) V_16 ) + 1 ) ;
} else {
F_40 ( 0 , ( unsigned long T_1 * ) V_16 ) ;
if ( ( V_2 & 0x780000 ) == 0x180000 )
F_40 ( 0 , ( unsigned long T_1 * ) V_16 + 1 ) ;
}
F_23 ( V_8 ) ;
}
void F_54 ( struct V_7 * V_8 , unsigned long V_92 , unsigned long V_93 )
{
unsigned long V_94 = V_8 -> V_38 ;
unsigned long V_9 = V_8 -> V_9 ;
V_28 V_2 ;
T_4 V_17 ;
T_5 V_73 ;
int V_77 ;
struct V_74 * V_75 = V_76 ;
if ( V_9 & V_19 )
F_4 ( L_17 , V_8 ) ;
F_34 ( V_62 , 1 , V_8 , V_92 ) ;
if ( F_11 ( V_25 ) )
V_94 = ( V_28 ) V_94 ;
if ( F_12 ( V_2 , ( V_28 T_1 * ) V_94 ) != - V_95 ) {
int V_33 = F_5 ( V_2 , V_8 ) ;
V_28 V_81 , V_82 ;
int V_61 ;
if ( ( V_33 > V_69 ) ||
( V_33 < V_10 ) )
goto V_96;
V_81 = V_82 = 0 ;
V_61 = F_12 ( V_81 , ( V_28 T_1 * ) V_92 ) ;
if ( ! V_61 )
V_61 = F_12 ( V_82 , ( V_28 T_1 * ) ( V_92 + 4 ) ) ;
if ( V_61 ) {
if ( ! ( V_33 & 0x2 ) )
goto V_96;
V_81 = V_82 = 0 ;
}
F_42 () ;
V_73 = ( ( V_2 >> 25 ) & 0x1e ) | ( ( V_2 >> 20 ) & 0x20 ) ;
V_17 = ( ( ( T_4 ) V_81 ) << 32 ) | V_82 ;
if ( V_33 & 0x8 )
V_17 = F_45 ( & V_17 ) ;
V_77 = ( V_73 < 32 ) ? V_78 : V_79 ;
if ( ! ( F_27 () -> V_83 [ 0 ] & V_90 ) ) {
F_27 () -> V_83 [ 0 ] = V_90 ;
F_27 () -> V_91 [ 0 ] = 0 ;
}
if ( ! ( F_27 () -> V_83 [ 0 ] & V_77 ) ) {
if ( V_73 < 32 )
memset ( V_75 -> V_8 , 0 , 32 * sizeof( V_28 ) ) ;
else
memset ( V_75 -> V_8 + 32 , 0 , 32 * sizeof( V_28 ) ) ;
}
* ( T_4 * ) ( V_75 -> V_8 + V_73 ) = V_17 ;
F_27 () -> V_83 [ 0 ] |= V_77 ;
} else {
V_96:
if ( V_85 == V_86 )
F_46 ( V_8 , V_92 , V_93 ) ;
else
F_47 ( V_8 , V_93 , V_92 ) ;
return;
}
F_23 ( V_8 ) ;
}
void F_55 ( struct V_7 * V_8 , unsigned long V_92 , unsigned long V_93 )
{
unsigned long V_94 = V_8 -> V_38 ;
unsigned long V_9 = V_8 -> V_9 ;
V_28 V_2 ;
T_4 V_17 ;
T_5 V_73 ;
int V_77 ;
struct V_74 * V_75 = V_76 ;
if ( V_9 & V_19 )
F_4 ( L_18 , V_8 ) ;
F_34 ( V_62 , 1 , V_8 , V_92 ) ;
if ( F_11 ( V_25 ) )
V_94 = ( V_28 ) V_94 ;
if ( F_12 ( V_2 , ( V_28 T_1 * ) V_94 ) != - V_95 ) {
int V_33 = F_5 ( V_2 , V_8 ) ;
V_73 = ( ( V_2 >> 25 ) & 0x1e ) | ( ( V_2 >> 20 ) & 0x20 ) ;
V_17 = 0 ;
V_77 = ( V_73 < 32 ) ? V_78 : V_79 ;
if ( ( V_33 > V_69 ) ||
( V_33 < V_10 ) )
goto V_96;
F_42 () ;
if ( F_27 () -> V_83 [ 0 ] & V_77 )
V_17 = * ( T_4 * ) & V_75 -> V_8 [ V_73 ] ;
switch ( V_33 ) {
case V_10 :
case V_84 : break;
case V_66 :
case V_67 :
V_17 = F_45 ( & V_17 ) ; break;
default: goto V_96;
}
if ( F_40 ( V_17 >> 32 , ( V_28 T_1 * ) V_92 ) ||
F_48 ( ( V_28 ) V_17 , ( V_28 T_1 * ) ( V_92 + 4 ) ) )
goto V_96;
} else {
V_96:
if ( V_85 == V_86 )
F_46 ( V_8 , V_92 , V_93 ) ;
else
F_47 ( V_8 , V_93 , V_92 ) ;
return;
}
F_23 ( V_8 ) ;
}
