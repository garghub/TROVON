static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return ( unsigned int ) F_2 ( F_3 ( V_2 , V_3 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
F_5 ( ( unsigned int ) V_4 , F_3 ( V_2 , V_3 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned long V_5 ;
unsigned int V_6 ;
V_5 = V_7 + F_7 ( 250 ) ;
for (; ; ) {
V_6 = F_1 ( V_2 , V_3 ) ;
if ( ! ( V_6 & 0x8000 ) )
return 0 ;
if ( ! F_8 ( V_5 , V_7 ) )
break;
F_9 ( 1 ) ;
}
F_4 ( V_2 , V_3 , V_6 & ~ 0x8000 ) ;
F_10 ( L_1 ) ;
return - V_8 ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
unsigned long V_9 , V_10 ;
V_9 = F_1 ( V_2 , V_11 ) ;
V_5 = V_7 + F_7 ( 250 ) ;
for (; ; ) {
V_10 = F_1 ( V_2 , V_11 ) ;
if ( V_10 != V_9 )
return 0 ;
if ( ! F_8 ( V_5 , V_7 ) )
break;
F_9 ( 1 ) ;
}
F_12 ( V_12 L_2 ) ;
return - V_8 ;
}
static void F_13 ( struct V_1 * V_2 , int V_13 ,
unsigned short V_14 ,
unsigned short V_4 )
{
unsigned int V_15 ;
unsigned int V_3 ;
if ( V_14 >= 0x80 ) {
F_12 ( V_12 L_3 , V_14 ) ;
return;
}
V_3 = V_2 -> V_16 . V_17 . V_18 ;
if ( F_6 ( V_2 , V_3 ) < 0 )
return;
if ( F_11 ( V_2 ) < 0 )
return;
V_15 = ( unsigned int ) ( V_14 & 0xff ) ;
V_15 |= 0x8000 | ( V_4 << 16 ) ;
if ( V_13 )
V_15 |= 0x0080 ;
if ( V_2 -> V_19 == V_20 )
V_15 |= 0x0100 ;
F_4 ( V_2 , V_3 , V_15 ) ;
return ;
}
static unsigned short F_14 ( struct V_1 * V_2 ,
int V_13 ,
unsigned short V_14 )
{
unsigned int V_15 ;
unsigned int V_3 ;
if ( V_14 >= 0x80 ) {
F_12 ( V_12 L_4 , V_14 ) ;
return ~ 0 ;
}
V_3 = V_2 -> V_16 . V_17 . V_21 ;
if ( F_6 ( V_2 , V_3 ) < 0 )
return ~ 0 ;
if ( F_11 ( V_2 ) < 0 )
return ~ 0 ;
V_15 = ( unsigned int ) ( V_14 & 0xff ) ;
V_15 |= 0x8000 ;
if ( V_13 )
V_15 |= 0x0080 ;
F_4 ( V_2 , V_3 , V_15 ) ;
if ( F_11 ( V_2 ) < 0 )
return ~ 0 ;
if ( F_6 ( V_2 , V_3 ) < 0 )
return ~ 0 ;
return ( F_1 ( V_2 , V_3 ) & 0xffff0000 ) >> 16 ;
}
static void F_15 ( struct V_22 * V_23 ,
unsigned short V_14 ,
unsigned short V_4 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_16 ( L_5 , V_14 , V_4 ) ;
if ( V_14 == V_25 ) {
F_5 ( ( V_4 << V_26 ) | V_27 ,
F_3 ( V_2 , V_28 ) ) ;
return;
}
F_13 ( V_2 , V_23 -> V_29 , V_14 , V_4 ) ;
return ;
}
static unsigned short F_17 ( struct V_22 * V_23 ,
unsigned short V_14 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_16 ( L_6 , V_14 ) ;
return F_14 ( V_2 , V_23 -> V_29 , V_14 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_30 * V_30 ;
unsigned short V_31 , V_32 ;
unsigned int V_15 ;
V_30 = V_2 -> V_33 ;
if ( V_30 ) {
F_19 ( V_30 , 0x7c , & V_15 ) ;
F_20 ( V_30 , 0x7c , V_15 | 0x08000000 ) ;
F_21 ( 5 ) ;
F_19 ( V_30 , 0x7c , & V_15 ) ;
F_20 ( V_30 , 0x7c , V_15 & 0xf7ffffff ) ;
F_21 ( 5 ) ;
}
V_30 = V_2 -> V_34 ;
F_19 ( V_30 , 0x44 , & V_15 ) ;
F_20 ( V_30 , 0x44 , V_15 | 0x000c0000 ) ;
F_22 ( 500 ) ;
F_19 ( V_30 , 0x44 , & V_15 ) ;
F_20 ( V_30 , 0x44 , V_15 & 0xfffbffff ) ;
F_21 ( 5 ) ;
V_31 = 200 ;
while( V_31 -- ) {
V_32 = F_14 ( V_2 , 0 , V_35 ) ;
if ( ( V_32 & 0x000f ) == 0x000f )
return 0 ;
F_21 ( 5 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
unsigned long V_15 ;
V_15 = F_2 ( F_3 ( V_2 , V_37 ) ) ;
V_15 |= 1 << ( V_36 & 0x0000001f ) ;
F_5 ( V_15 , F_3 ( V_2 , V_37 ) ) ;
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
unsigned long V_15 ;
V_15 = F_2 ( F_3 ( V_2 , V_37 ) ) ;
V_15 &= ~ ( 1 << ( V_36 & 0x0000001f ) ) ;
F_5 ( V_15 , F_3 ( V_2 , V_37 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_38 ;
V_38 = F_2 ( F_3 ( V_2 , V_39 ) ) ;
V_38 |= V_40 ;
V_38 |= V_41 ;
F_5 ( V_38 , F_3 ( V_2 , V_39 ) ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned int V_38 ;
V_38 = F_2 ( F_3 ( V_2 , V_39 ) ) ;
V_38 &= ~ V_40 ;
V_38 &= ~ V_41 ;
F_5 ( V_38 , F_3 ( V_2 , V_39 ) ) ;
}
static void F_27 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
unsigned int V_42 ;
struct V_43 * V_44 = & ( V_2 -> V_16 ) ;
F_16 ( L_7 , V_36 ) ;
V_42 = 1 << ( V_36 & 0x1f ) ;
V_44 -> V_45 . V_46 = F_2 ( F_3 ( V_2 , V_44 -> V_17 . V_46 ) ) ;
V_44 -> V_45 . V_46 &= ~ V_42 ;
F_5 ( V_44 -> V_45 . V_46 , F_3 ( V_2 , V_44 -> V_17 . V_46 ) ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_36 )
{
unsigned int V_47 = V_36 & 0x1f ;
if ( V_2 -> V_48 . V_49 >= V_50 ) {
F_12 ( V_12
L_8 ) ;
return - 1 ;
}
if ( ! ( V_2 -> V_48 . V_51 & ( 1 << V_47 ) ) ) {
V_2 -> V_48 . V_51 |= 1 << V_47 ;
V_2 -> V_48 . V_49 ++ ;
F_16 ( L_9 , V_47 ) ;
return V_47 ;
}
return - 1 ;
}
static int F_29 ( struct V_1 * V_2 , int V_52 )
{
int V_47 ;
int V_53 = - 1 ;
F_16 ( L_10 , V_52 ? L_11 : L_12 ) ;
if ( V_52 ) {
if ( V_2 -> V_54 &&
( F_2 ( F_3 ( V_2 , V_37 ) ) &
V_55 ) )
V_47 = V_56 ;
else
V_47 = V_57 ;
V_53 = F_28 ( V_2 , V_47 ) ;
if ( V_53 >= 0 )
return V_53 ;
else {
F_12 ( V_12 L_13
L_14 ) ;
return - 1 ;
}
}
if ( V_2 -> V_54 &&
( F_2 ( F_3 ( V_2 , V_37 ) ) &
V_58 ) ) {
V_47 = V_59 ;
V_53 = F_28 ( V_2 , V_47 ) ;
if ( V_53 >= 0 )
return V_53 ;
else
F_12 ( V_12 L_13
L_15 ) ;
}
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_53 = F_28 ( V_2 , V_47 ) ;
if ( V_53 >= 0 )
return V_53 ;
}
F_12 ( V_12 L_16 ) ;
return - 1 ;
}
static void F_30 ( struct V_1 * V_2 , int V_36 )
{
unsigned int V_47 = V_36 & 0x0000001f ;
F_16 ( L_17 , V_36 ) ;
if ( V_36 < 0 || V_36 >= V_50 )
return;
if ( ! ( V_2 -> V_48 . V_51 & ( 1 << V_47 ) ) ) {
F_12 ( V_12 L_18
L_19 , V_36 ) ;
return;
} else {
V_2 -> V_48 . V_51 &= ~ ( 1 << V_47 ) ;
V_2 -> V_48 . V_49 -- ;
}
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_36 )
{
unsigned int V_42 = 1 << ( V_36 & 0x1f ) ;
F_16 ( L_20 , V_36 ) ;
F_5 ( V_42 , F_3 ( V_2 , V_2 -> V_16 . V_17 . V_60 ) ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_61 )
{
unsigned long V_62 , V_63 ;
V_62 = F_2 ( F_3 ( V_2 , V_11 ) ) ;
V_63 = F_2 ( F_3 ( V_2 , V_11 ) ) ;
while ( V_63 < V_62 + V_61 ) {
if ( F_11 ( V_2 ) < 0 )
break;
V_63 = F_2 ( F_3 ( V_2 , V_11 ) ) ;
F_33 () ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_64 ;
T_1 V_65 = 0 ;
T_2 V_66 , V_67 = 0 , V_68 ;
V_66 = F_35 ( F_3 ( V_2 , V_69 + 1 ) ) ;
V_66 |= 0x1F ;
F_36 ( V_66 , F_3 ( V_2 , V_69 + 1 ) ) ;
while ( ( V_67 < 0x0b || V_67 > 0x0e ) && V_67 != 0x12 && V_65 <= 50000 ) {
V_65 ++ ;
F_32 ( V_2 , 6 ) ;
V_66 = F_35 ( F_3 ( V_2 , V_69 + 1 ) ) ;
V_67 = V_66 & 0x1F ;
}
if ( V_65 > 50000 ) {
F_12 ( V_12 L_21 ) ;
return;
}
for ( V_65 = 0 ; V_65 <= 50000 ; V_65 ++ ) {
F_32 ( V_2 , 6 ) ;
V_66 = F_35 ( F_3 ( V_2 , V_69 + 1 ) ) ;
V_68 = V_66 & 0x1F ;
if ( V_68 != V_67 )
V_67 = V_68 ;
else
break;
}
if ( V_65 > 50000 ) {
F_12 ( V_12 L_21 ) ;
return;
}
if ( V_68 >= 0x0b && V_68 <= 0x0e ) {
V_64 = F_37 ( F_3 ( V_2 , V_69 + 2 ) ) ;
V_64 &= 0xe0f0 ;
V_64 |= ( 0x09 << 8 ) | 0x05 ;
F_38 ( V_64 , F_3 ( V_2 , V_69 + 2 ) ) ;
V_66 = F_35 ( F_3 ( V_2 , V_70 + 3 ) ) & 0xf0 ;
F_36 ( V_66 | 0x02 , F_3 ( V_2 , V_70 + 3 ) ) ;
} else if ( V_68 == 0x12 ) {
V_64 = F_37 ( F_3 ( V_2 , V_69 + 2 ) ) ;
V_64 &= 0xe0f0 ;
V_64 |= ( 0x0e << 8 ) | 0x08 ;
F_38 ( V_64 , F_3 ( V_2 , V_69 + 2 ) ) ;
V_66 = F_35 ( F_3 ( V_2 , V_70 + 3 ) ) & 0xf0 ;
F_36 ( V_66 | 0x03 , F_3 ( V_2 , V_70 + 3 ) ) ;
}
}
static unsigned int F_39 ( struct V_1 * V_2 )
{
T_3 V_71 ;
T_2 V_66 ;
V_66 = F_35 ( F_3 ( V_2 , V_69 ) ) ;
V_66 &= 0x7f ;
V_66 |= 0x40 ;
F_36 ( V_66 , F_3 ( V_2 , V_69 ) ) ;
F_34 ( V_2 ) ;
V_66 = F_35 ( F_3 ( V_2 , V_70 + 3 ) ) ;
V_66 &= 0x0f ;
switch ( V_66 ) {
case 0 : V_71 = 44100 ; break;
case 1 : V_71 = 48000 ; break;
case 2 : V_71 = 32000 ; break;
default: V_71 = 0 ; break;
}
return V_71 ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
V_15 = F_2 ( F_3 ( V_2 , V_37 ) ) ;
V_15 |= V_55 ;
F_5 ( V_15 , F_3 ( V_2 , V_37 ) ) ;
V_15 = F_35 ( F_3 ( V_2 , V_69 ) ) ;
V_15 |= 0x02 ;
F_36 ( V_15 , F_3 ( V_2 , V_69 ) ) ;
F_23 ( V_2 , V_56 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
V_15 = F_2 ( F_3 ( V_2 , V_37 ) ) ;
V_15 &= ~ V_55 ;
F_5 ( V_15 , F_3 ( V_2 , V_37 ) ) ;
F_24 ( V_2 , V_56 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_72 )
{
unsigned char V_73 ;
unsigned int V_71 ;
switch ( V_72 ) {
case 32000 : V_71 = 0x300 ; break;
case 48000 : V_71 = 0x200 ; break;
default: V_71 = 0 ; break;
}
V_73 = F_35 ( F_3 ( V_2 , V_69 ) ) ;
V_73 &= ( unsigned char ) ( ~ ( 1 << 6 ) ) ;
V_73 |= 0x80 ;
F_36 ( V_73 , F_3 ( V_2 , V_69 ) ) ;
F_36 ( V_71 | 0x20 , F_3 ( V_2 , V_70 + 2 ) ) ;
V_73 &= ~ 0x80 ;
F_36 ( V_73 , F_3 ( V_2 , V_69 ) ) ;
F_38 ( V_72 | 0x10 , F_3 ( V_2 , V_70 + 2 ) ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned short V_74 ;
unsigned char V_73 ;
struct V_30 * V_30 ;
V_30 = V_2 -> V_33 ;
if ( V_30 == NULL )
return;
F_44 ( V_30 , 0x61 , & V_73 ) ;
V_73 |= 0x40 ;
F_45 ( V_30 , 0x61 , V_73 ) ;
F_44 ( V_30 , 0x7d , & V_73 ) ;
V_73 |= 0x01 ;
F_45 ( V_30 , 0x7d , V_73 ) ;
F_44 ( V_30 , 0x7e , & V_73 ) ;
V_73 &= ( ~ 0x20 ) ;
V_73 |= 0x10 ;
F_45 ( V_30 , 0x7e , V_73 ) ;
V_73 = F_35 ( F_3 ( V_2 , V_75 ) ) ;
F_36 ( V_73 | V_76 , F_3 ( V_2 , V_75 ) ) ;
V_73 = F_35 ( F_3 ( V_2 , V_69 ) ) ;
F_36 ( V_73 & V_77 , F_3 ( V_2 , V_69 ) ) ;
V_74 = F_37 ( F_3 ( V_2 , V_37 ) ) ;
V_74 |= V_78 ;
F_38 ( V_74 , F_3 ( V_2 , V_37 ) ) ;
F_24 ( V_2 , V_59 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
unsigned short V_74 ;
V_74 = F_37 ( F_3 ( V_2 , V_37 ) ) ;
V_74 &= ~ V_78 ;
F_38 ( V_74 , F_3 ( V_2 , V_37 ) ) ;
F_23 ( V_2 , V_59 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned short V_74 ;
V_74 = F_37 ( F_3 ( V_2 , V_37 ) ) ;
V_74 |= V_78 ;
F_38 ( V_74 , F_3 ( V_2 , V_37 ) ) ;
F_23 ( V_2 , V_59 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned char V_73 ;
V_73 = F_35 ( F_3 ( V_2 , V_75 ) ) ;
F_36 ( V_73 & ~ V_76 , F_3 ( V_2 , V_75 ) ) ;
F_47 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 , int V_36 )
{
struct V_79 * V_80 ;
struct V_43 * V_44 ;
unsigned int V_81 , V_42 ;
#ifdef F_50
unsigned int V_82 , V_83 ;
#endif
V_44 = & ( V_2 -> V_16 ) ;
V_81 = V_44 -> V_45 . V_84 ;
V_42 = 1U << ( V_36 & 0x1f ) ;
if ( ! ( V_81 & V_42 ) )
return;
V_80 = & V_2 -> V_48 . V_85 [ V_36 ] ;
F_22 ( 100 ) ;
F_51 ( & V_2 -> V_86 ) ;
if ( V_80 -> V_87 && V_80 -> V_88 ) {
#ifdef F_50
F_36 ( ( T_2 ) ( V_80 -> V_89 ) , F_3 ( V_2 , V_39 ) ) ;
V_82 = F_37 ( F_3 ( V_2 , V_90 + 2 ) ) ;
V_83 = ( F_2 ( F_3 ( V_2 , V_91 ) ) & V_42 ) == V_42 ;
#endif
if ( V_80 -> V_92 ) {
F_16 ( L_22 ,
( T_1 ) V_82 , V_83 ) ;
F_52 ( & V_2 -> V_86 ) ;
F_53 ( V_80 -> V_88 ) ;
F_51 ( & V_2 -> V_86 ) ;
} else {
F_31 ( V_2 , V_36 ) ;
F_27 ( V_2 , V_36 ) ;
}
} else if ( V_2 -> V_48 . V_85 [ V_36 ] . V_48 ) {
} else if ( V_2 -> V_48 . V_85 [ V_36 ] . V_93 ) {
} else {
F_31 ( V_2 , V_36 ) ;
F_27 ( V_2 , V_36 ) ;
}
F_52 ( & V_2 -> V_86 ) ;
F_5 ( V_42 , F_3 ( V_2 , V_44 -> V_17 . V_84 ) ) ;
V_44 -> V_45 . V_84 = V_81 & ( ~ V_42 ) ;
}
static T_4 F_54 ( int V_94 , void * V_95 )
{
struct V_1 * V_2 = V_95 ;
int V_36 ;
unsigned int V_96 ;
struct V_43 * V_44 ;
if ( V_2 == NULL || ! V_2 -> V_97 )
return V_98 ;
V_96 = F_2 ( F_3 ( V_2 , V_99 ) ) ;
if ( ! V_96 )
return V_98 ;
V_44 = & ( V_2 -> V_16 ) ;
if ( V_96 & V_100 ) {
V_44 -> V_45 . V_84 = F_2 ( F_3 ( V_2 , V_44 -> V_17 . V_84 ) ) ;
for ( V_36 = 0 ; V_36 < V_50 ; V_36 ++ )
F_49 ( V_2 , V_36 ) ;
}
F_5 ( ( V_101 | V_102 | V_103 ) ,
F_3 ( V_2 , V_99 ) ) ;
return V_104 ;
}
static struct V_79 * F_55 ( struct V_1 * V_2 ,
int type , int V_52 , int V_36 )
{
struct V_79 * V_80 ;
int V_47 ;
F_16 ( L_23 , type , V_52 ) ;
F_56 ( & V_2 -> V_105 ) ;
if ( type == V_106 ) {
V_47 = V_36 > 0 ? F_28 ( V_2 , V_36 ) :
F_29 ( V_2 , V_52 ) ;
if ( V_47 < 0 ) {
F_12 ( V_12 L_24 ) ;
F_57 ( & V_2 -> V_105 ) ;
return NULL ;
}
V_80 = & ( V_2 -> V_48 . V_85 [ V_47 ] ) ;
V_80 -> V_2 = V_2 ;
V_80 -> V_107 = 1 ;
V_80 -> V_87 = 1 ;
V_80 -> V_108 = V_52 ;
F_57 ( & V_2 -> V_105 ) ;
return V_80 ;
}
F_57 ( & V_2 -> V_105 ) ;
return NULL ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
void (* F_59)( void * );
void * V_24 ;
F_16 ( L_25 , V_80 -> V_89 ) ;
if ( ! V_80 -> V_107 )
return;
F_60 ( V_2 , V_80 -> V_89 , V_80 -> V_89 ) ;
F_56 ( & V_2 -> V_105 ) ;
F_59 = V_80 -> F_59 ;
V_24 = V_80 -> V_24 ;
V_80 -> F_59 = NULL ;
V_80 -> V_24 = NULL ;
if ( V_80 -> V_87 )
F_30 ( V_2 , V_80 -> V_89 ) ;
V_80 -> V_107 = V_80 -> V_87 = V_80 -> V_48 = 0 ;
V_80 -> V_88 = NULL ;
F_57 ( & V_2 -> V_105 ) ;
if ( F_59 )
F_59 ( V_24 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
unsigned int V_109 ,
unsigned int V_110 )
{
unsigned int V_111 ;
for ( V_111 = V_109 ; V_111 <= V_110 ; V_111 ++ ) {
F_31 ( V_2 , V_111 ) ;
F_27 ( V_2 , V_111 ) ;
}
}
static void F_61 ( struct V_1 * V_2 ,
unsigned int V_112 ,
unsigned int V_113 ,
unsigned int V_114 ,
unsigned int V_115 ,
unsigned int V_116 ,
unsigned int V_117 ,
unsigned int V_118 ,
unsigned int V_119 ,
unsigned int V_120 ,
unsigned int V_121 ,
unsigned int V_122 )
{
unsigned int V_123 [ 4 ] ;
F_36 ( ( unsigned char ) ( V_112 & 0x001f ) , F_3 ( V_2 , V_39 ) ) ;
V_123 [ 0 ] = ( V_114 << 16 ) | ( V_117 & 0x0000ffff ) ;
V_123 [ 1 ] = V_113 ;
V_123 [ 2 ] = ( V_115 << 16 ) | ( V_116 & 0x0ffff ) ;
V_123 [ 3 ] = ( V_118 << 31 ) |
( ( V_119 & 0x0000007f ) << 24 ) |
( ( V_120 & 0x000000ff ) << 16 ) |
( ( V_121 & 0x0000000f ) << 12 ) |
( V_122 & 0x00000fff ) ;
F_36 ( V_112 , F_3 ( V_2 , V_39 ) ) ;
F_5 ( V_123 [ 0 ] , F_3 ( V_2 , V_90 ) ) ;
F_5 ( V_123 [ 1 ] , F_3 ( V_2 , V_124 ) ) ;
F_5 ( V_123 [ 2 ] , F_3 ( V_2 , V_125 ) ) ;
F_5 ( V_123 [ 3 ] , F_3 ( V_2 , V_126 ) ) ;
F_5 ( 0x30000000 , F_3 ( V_2 , V_127 ) ) ;
F_5 ( 0x30000000 , F_3 ( V_2 , V_128 ) ) ;
}
static unsigned int F_62 ( unsigned int V_72 , int V_52 )
{
unsigned int V_129 ;
if ( V_72 < 4000 )
V_72 = 4000 ;
if ( V_72 > 48000 )
V_72 = 48000 ;
if ( V_52 ) {
if ( V_72 == 44100 )
V_129 = 0x116a ;
else if ( V_72 == 8000 )
V_129 = 0x6000 ;
else if ( V_72 == 48000 )
V_129 = 0x1000 ;
else
V_129 = ( ( 48000 << 12 ) / V_72 ) & 0x0000ffff ;
} else {
if ( V_72 == 44100 )
V_129 = 0xeb3 ;
else if ( V_72 == 8000 )
V_129 = 0x2ab ;
else if ( V_72 == 48000 )
V_129 = 0x1000 ;
else
V_129 = ( ( ( V_72 << 12 ) + V_72 ) / 48000 ) & 0x0000ffff ;
}
return V_129 ;
}
static unsigned int F_63 ( struct V_130 * V_88 )
{
unsigned int V_121 ;
struct V_131 * V_132 = V_88 -> V_132 ;
V_121 = 0x00000001 ;
if ( F_64 ( V_132 -> V_133 ) == 16 )
V_121 |= 0x00000008 ;
if ( ! F_65 ( V_132 -> V_133 ) )
V_121 |= 0x00000002 ;
if ( V_132 -> V_134 > 1 )
V_121 |= 0x00000004 ;
return V_121 ;
}
static int F_66 ( struct V_130 * V_88 ,
int V_135 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_130 * V_136 ;
unsigned int V_137 , V_138 , V_139 ;
struct V_79 * V_80 , * V_140 ;
unsigned int V_4 ;
int V_141 ;
switch ( V_135 ) {
case V_142 :
case V_143 :
V_141 = 1 ;
break;
case V_144 :
case V_145 :
V_141 = 0 ;
break;
default:
return - V_146 ;
}
V_137 = V_138 = V_139 = 0 ;
F_68 (s, substream) {
if ( (struct V_1 * ) F_67 ( V_136 ) == V_2 ) {
V_80 = V_136 -> V_132 -> V_24 ;
V_140 = V_80 -> V_147 ;
V_137 |= 1 << ( V_80 -> V_89 & 0x1f ) ;
if ( V_140 == NULL )
V_138 |= 1 << ( V_80 -> V_89 & 0x1f ) ;
else {
V_138 |= 1 << ( V_140 -> V_89 & 0x1f ) ;
V_137 |= 1 << ( V_140 -> V_89 & 0x1f ) ;
}
if ( V_141 ) {
V_80 -> V_92 = 1 ;
if ( V_140 != NULL )
V_140 -> V_92 = 1 ;
} else {
V_80 -> V_92 = 0 ;
if ( V_140 != NULL )
V_140 -> V_92 = 0 ;
}
F_69 ( V_136 , V_88 ) ;
if ( V_80 -> V_108 )
V_139 = 1 ;
}
}
F_51 ( & V_2 -> V_86 ) ;
if ( ! V_141 )
F_5 ( V_137 , F_3 ( V_2 , V_148 ) ) ;
V_4 = F_2 ( F_3 ( V_2 , V_149 ) ) ;
if ( V_141 )
V_4 |= V_138 ;
else
V_4 &= ~ V_138 ;
F_5 ( V_4 , F_3 ( V_2 , V_149 ) ) ;
if ( V_141 )
F_5 ( V_137 , F_3 ( V_2 , V_150 ) ) ;
F_16 ( L_26 , V_137 , V_138 ) ;
F_52 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_70 ( struct V_130 * V_88 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_131 * V_132 = V_88 -> V_132 ;
struct V_79 * V_80 = V_132 -> V_24 ;
struct V_79 * V_140 = V_80 -> V_147 ;
int V_153 ;
V_153 = F_71 ( V_88 ,
F_72 ( V_152 ) ) ;
if ( V_153 < 0 )
return V_153 ;
if ( F_73 ( V_152 ) / 2 !=
F_74 ( V_152 ) ) {
if ( ! V_140 ) {
V_140 = F_55 ( V_2 ,
V_106 ,
0 , - 1 ) ;
if ( ! V_140 )
return - V_154 ;
V_80 -> V_147 = V_140 ;
V_140 -> V_88 = V_88 ;
}
} else {
if ( V_140 ) {
F_58 ( V_2 , V_140 ) ;
V_80 -> V_147 = V_140 = NULL ;
}
}
return 0 ;
}
static int F_75 ( struct V_130 * V_88 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_131 * V_132 = V_88 -> V_132 ;
struct V_79 * V_80 = V_132 -> V_24 ;
struct V_79 * V_140 = V_80 ? V_80 -> V_147 : NULL ;
F_76 ( V_88 ) ;
if ( V_140 ) {
F_58 ( V_2 , V_140 ) ;
V_80 -> V_147 = NULL ;
}
return 0 ;
}
static int F_77 ( struct V_130 * V_88 ,
struct V_151 * V_152 )
{
return F_71 ( V_88 ,
F_72 ( V_152 ) ) ;
}
static int F_78 ( struct V_130 * V_88 )
{
return F_76 ( V_88 ) ;
}
static int F_79 ( struct V_130 * V_88 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_131 * V_132 = V_88 -> V_132 ;
struct V_79 * V_80 = V_132 -> V_24 ;
struct V_79 * V_140 = V_80 -> V_147 ;
unsigned int V_113 ;
unsigned int V_155 ;
unsigned int V_115 ;
unsigned int V_121 ;
unsigned int V_118 ;
unsigned int V_119 ;
unsigned int V_120 ;
unsigned int V_122 ;
F_16 ( L_27 ) ;
F_56 ( & V_2 -> V_86 ) ;
V_155 = F_62 ( V_132 -> V_72 , 0 ) ;
if ( V_80 -> V_89 == V_56 ||
V_80 -> V_89 == V_57 )
F_24 ( V_2 , V_80 -> V_89 ) ;
else if ( V_2 -> V_54 &&
( F_2 ( F_3 ( V_2 , V_37 ) ) &
V_58 )
&& V_80 -> V_89 == V_59 ) {
F_42 ( V_2 , V_132 -> V_72 ) ;
V_155 = 0x1000 ;
}
V_113 = V_132 -> V_156 ;
V_80 -> V_65 = V_132 -> V_157 ;
V_80 -> V_158 = V_132 -> V_159 ;
F_16 ( L_28 ,
V_80 -> V_158 , V_80 -> V_65 ) ;
V_115 = V_80 -> V_158 - 1 ;
V_121 = F_63 ( V_88 ) ;
V_118 = 1 ;
V_119 = 0 ;
V_120 = 0 ;
V_122 = 0 ;
F_16 ( L_29 ) ;
F_16 ( L_30 ,
V_80 -> V_89 , V_132 -> V_72 , V_155 , V_118 , V_119 , V_121 ) ;
F_61 ( V_2 ,
V_80 -> V_89 ,
V_113 ,
0 ,
V_115 ,
V_155 ,
0 ,
V_118 ,
V_119 ,
V_120 ,
V_121 ,
V_122 ) ;
if ( V_140 ) {
V_140 -> V_65 = V_80 -> V_65 ;
V_140 -> V_158 = V_80 -> V_65 << 1 ;
V_115 = V_140 -> V_158 - 1 ;
F_61 ( V_2 ,
V_140 -> V_89 ,
V_113 ,
0 ,
V_115 ,
V_155 ,
0 ,
V_118 ,
0x7f ,
0x3ff ,
V_121 ,
V_122 ) ;
}
F_57 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_80 ( struct V_130 * V_88 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_131 * V_132 = V_88 -> V_132 ;
struct V_79 * V_80 = V_132 -> V_24 ;
unsigned int V_113 ;
unsigned int V_155 ;
unsigned int V_115 ;
unsigned int V_121 ;
unsigned int V_118 ;
unsigned int V_119 ;
unsigned int V_120 ;
unsigned int V_122 ;
T_2 V_160 ;
F_56 ( & V_2 -> V_86 ) ;
F_16 ( L_31 ) ;
F_23 ( V_2 , V_80 -> V_89 ) ;
V_155 = ( V_80 -> V_89 == V_161 ||
V_80 -> V_89 == V_162 ) ?
0x1000 : F_62 ( V_132 -> V_72 , V_80 -> V_108 ) ;
if ( V_80 -> V_89 == V_56 ) {
unsigned int V_72 ;
F_57 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_19 != V_20 )
return - 1 ;
V_72 = F_39 ( V_2 ) ;
if ( V_72 == 0 ) {
F_12 ( V_163 L_32
L_33 ) ;
V_72 = 48000 ;
}
F_56 ( & V_2 -> V_86 ) ;
V_160 = F_35 ( F_3 ( V_2 , V_69 ) ) ;
if ( V_160 & 0x10 ) {
F_36 ( V_160 , F_3 ( V_2 , V_69 ) ) ;
F_81 ( V_163 L_34 ) ;
}
if ( V_72 != 48000 )
V_155 = ( ( V_72 << 12 ) / V_132 -> V_72 ) & 0x00ffff ;
}
V_80 -> V_158 = V_132 -> V_159 ;
V_80 -> V_65 = V_132 -> V_157 ;
V_113 = V_132 -> V_156 ;
V_115 = V_80 -> V_158 - 1 ;
V_121 = F_63 ( V_88 ) ;
V_118 = 0 ;
V_119 = 0x00 ;
V_120 = 0x00 ;
V_122 = 0 ;
F_61 ( V_2 ,
V_80 -> V_89 ,
V_113 ,
0 ,
V_115 ,
V_155 ,
0 ,
V_118 ,
V_119 ,
V_120 ,
V_121 ,
V_122 ) ;
F_57 ( & V_2 -> V_86 ) ;
return 0 ;
}
static T_5
F_82 ( struct V_130 * V_88 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_131 * V_132 = V_88 -> V_132 ;
struct V_79 * V_80 = V_132 -> V_24 ;
unsigned int V_164 ;
F_51 ( & V_2 -> V_86 ) ;
if ( ! V_80 -> V_92 ) {
F_52 ( & V_2 -> V_86 ) ;
return 0 ;
}
F_36 ( V_80 -> V_89 , F_3 ( V_2 , V_39 ) ) ;
V_164 = F_37 ( F_3 ( V_2 , V_90 + 2 ) ) ;
F_52 ( & V_2 -> V_86 ) ;
F_16 ( L_35 , V_164 ) ;
return V_164 ;
}
static T_5 F_83 ( struct V_130 * V_88 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_131 * V_132 = V_88 -> V_132 ;
struct V_79 * V_80 = V_132 -> V_24 ;
unsigned int V_164 ;
F_51 ( & V_2 -> V_86 ) ;
if ( ! V_80 -> V_92 ) {
F_52 ( & V_2 -> V_86 ) ;
return 0 ;
}
F_36 ( V_80 -> V_89 , F_3 ( V_2 , V_39 ) ) ;
V_164 = F_37 ( F_3 ( V_2 , V_90 + 2 ) ) ;
F_52 ( & V_2 -> V_86 ) ;
return V_164 ;
}
static void F_84 ( struct V_131 * V_132 )
{
struct V_79 * V_80 = V_132 -> V_24 ;
struct V_1 * V_2 ;
if ( V_80 ) {
V_2 = V_80 -> V_2 ;
F_58 ( V_80 -> V_2 , V_80 ) ;
}
}
static int F_85 ( struct V_130 * V_88 , int V_52 ,
int V_36 , struct V_165 * V_166 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_131 * V_132 = V_88 -> V_132 ;
struct V_79 * V_80 ;
V_80 = F_55 ( V_2 , V_106 , V_52 ,
V_36 ) ;
if ( ! V_80 )
return - V_167 ;
V_80 -> V_88 = V_88 ;
V_132 -> V_24 = V_80 ;
V_132 -> F_59 = F_84 ;
V_132 -> V_168 = * V_166 ;
F_86 ( V_88 ) ;
F_87 ( V_132 , V_169 ,
0 , 64 * 1024 ) ;
return 0 ;
}
static int F_88 ( struct V_130 * V_88 )
{
return F_85 ( V_88 , 0 , - 1 , & V_170 ) ;
}
static int F_89 ( struct V_130 * V_88 )
{
return F_85 ( V_88 , 1 , - 1 , & V_171 ) ;
}
static int F_90 ( struct V_130 * V_88 )
{
return 0 ;
}
static int F_91 ( struct V_130 * V_88 )
{
struct V_1 * V_2 = F_67 ( V_88 ) ;
struct V_79 * V_80 = V_88 -> V_132 -> V_24 ;
F_24 ( V_2 , V_80 -> V_89 ) ;
return 0 ;
}
static int F_92 ( struct V_130 * V_88 ,
struct V_151 * V_152 )
{
struct V_1 * V_172 = F_67 ( V_88 ) ;
unsigned int V_173 = V_172 -> V_174 - 1 ;
F_93 ( V_172 -> V_23 [ V_173 ] , V_175 ,
F_94 ( V_152 ) ) ;
F_93 ( V_172 -> V_23 [ V_173 ] , V_176 , 0 ) ;
return F_77 ( V_88 , V_152 ) ;
}
static int F_95 ( struct V_130 * V_88 , int V_52 ,
int V_36 )
{
static unsigned int V_177 [] = { 8000 , 9600 , 12000 , 16000 } ;
static struct V_178 V_179 = {
. V_65 = F_96 ( V_177 ) ,
. V_180 = V_177 ,
. V_42 = 0 ,
} ;
int V_153 = F_85 ( V_88 , V_52 , V_36 , & V_181 ) ;
if ( V_153 )
return V_153 ;
return V_178 ( V_88 -> V_132 , 0 ,
V_182 , & V_179 ) ;
}
static int F_97 ( struct V_130 * V_88 )
{
return F_95 ( V_88 , 0 , V_162 ) ;
}
static int F_98 ( struct V_130 * V_88 )
{
return F_95 ( V_88 , 1 , V_161 ) ;
}
static void F_99 ( struct V_183 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_24 ;
V_2 -> V_87 [ V_87 -> V_184 ] = NULL ;
}
static int F_100 ( struct V_1 * V_2 , int V_184 ,
struct V_185 * V_186 )
{
struct V_183 * V_87 ;
int V_153 ;
V_153 = F_101 ( V_2 -> V_187 , V_186 -> V_188 , V_184 ,
V_186 -> V_189 , V_186 -> V_190 , & V_87 ) ;
if ( V_153 < 0 ) {
F_12 ( V_12 L_36 ) ;
return V_153 ;
}
V_87 -> V_24 = V_2 ;
V_87 -> F_59 = F_99 ;
if ( V_186 -> V_191 )
F_102 ( V_87 , V_192 ,
V_186 -> V_191 ) ;
if ( V_186 -> V_193 )
F_102 ( V_87 , V_194 ,
V_186 -> V_193 ) ;
F_103 ( V_87 , V_195 ,
F_104 ( V_2 -> V_34 ) ,
64 * 1024 , 128 * 1024 ) ;
V_87 -> V_196 = 0 ;
V_87 -> V_197 = V_186 -> V_198 ;
V_87 -> V_199 = V_200 ;
strcpy ( V_87 -> V_188 , V_186 -> V_188 ) ;
V_2 -> V_87 [ 0 ] = V_87 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_111 , V_153 ;
for ( V_111 = 0 ; V_111 < V_2 -> V_174 && V_111 < F_96 ( V_201 ) ; V_111 ++ ) {
V_153 = F_100 ( V_2 , V_111 , & V_201 [ V_111 ] ) ;
if ( V_153 < 0 )
return V_153 ;
}
return 0 ;
}
static int F_106 ( struct V_202 * V_203 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = V_203 -> V_24 ;
unsigned int V_206 ;
V_206 = V_205 -> V_207 . integer . V_207 [ 0 ] ? 1 : 0 ;
F_56 ( & V_2 -> V_86 ) ;
switch ( V_203 -> V_208 ) {
case 0 :
V_206 = ( V_2 -> V_209 & 0x02 ) ? 1 : 0 ;
break;
case 1 :
V_206 = ( ( V_2 -> V_209 & 0x02 ) &&
( V_2 -> V_209 & 0x04 ) ) ? 1 : 0 ;
break;
case 2 :
V_206 = ( V_2 -> V_209 & 0x01 ) ? 1 : 0 ;
break;
default:
break;
}
V_205 -> V_207 . integer . V_207 [ 0 ] = V_206 ;
F_57 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_107 ( struct V_202 * V_203 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = V_203 -> V_24 ;
unsigned int V_210 = 0 , V_206 = 0 ;
V_206 = V_205 -> V_207 . integer . V_207 [ 0 ] ? 1 : 0 ;
F_56 ( & V_2 -> V_86 ) ;
switch ( V_203 -> V_208 ) {
case 0 :
V_210 = ( V_2 -> V_209 & 0x02 ) ? 1 : 0 ;
V_210 = V_210 ^ V_206 ;
if ( V_210 ) {
if ( V_206 ) {
V_2 -> V_209 |= 0x02 ;
F_43 ( V_2 ) ;
} else {
V_2 -> V_209 &= ~ ( 0x02 ) ;
V_2 -> V_209 &= ~ ( 0x04 ) ;
F_48 ( V_2 ) ;
}
}
break;
case 1 :
V_210 = ( V_2 -> V_209 & 0x04 ) ? 1 : 0 ;
V_210 = V_210 ^ V_206 ;
if ( V_210 && ( V_2 -> V_209 & 0x02 ) ) {
if ( V_206 ) {
V_2 -> V_209 |= 0x04 ;
F_46 ( V_2 ) ;
} else {
V_2 -> V_209 &= ~ ( 0x04 ) ;
F_47 ( V_2 ) ;
}
}
break;
case 2 :
V_210 = ( V_2 -> V_209 & 0x01 ) ? 1 : 0 ;
V_210 = V_210 ^ V_206 ;
if ( V_210 ) {
if ( V_206 ) {
V_2 -> V_209 |= 0x01 ;
F_40 ( V_2 ) ;
} else {
V_2 -> V_209 &= ~ ( 0x01 ) ;
F_41 ( V_2 ) ;
}
}
break;
default:
break;
}
F_57 ( & V_2 -> V_86 ) ;
return V_210 ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_211 V_23 ;
unsigned int V_47 ;
int V_111 , V_153 ;
static struct V_212 V_213 = {
. V_214 = F_15 ,
. V_215 = F_17 ,
} ;
V_153 = F_109 ( V_2 -> V_187 , 0 , & V_213 , V_2 , & V_2 -> V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_24 = V_2 ;
for ( V_111 = 0 ; V_111 < V_2 -> V_174 ; V_111 ++ ) {
V_23 . V_29 = V_111 ;
V_153 = F_110 ( V_2 -> V_216 , & V_23 , & V_2 -> V_23 [ V_111 ] ) ;
if ( V_153 < 0 ) {
F_12 ( V_12
L_37 , V_111 ) ;
if ( V_111 == 0 )
return V_153 ;
V_2 -> V_174 = 1 ;
break;
}
}
if ( V_2 -> V_54 ) {
for ( V_47 = 0 ; V_47 < F_96 ( V_217 ) ; V_47 ++ ) {
V_153 = F_111 ( V_2 -> V_187 ,
F_112 ( & V_217 [ V_47 ] , V_2 ) ) ;
if ( V_153 < 0 )
return V_153 ;
}
}
return 0 ;
}
static int F_113 ( struct V_184 * V_218 )
{
struct V_30 * V_34 = F_114 ( V_218 ) ;
struct V_219 * V_187 = F_115 ( V_218 ) ;
struct V_1 * V_172 = V_187 -> V_24 ;
struct V_220 * V_221 ;
int V_111 , V_222 ;
V_221 = V_172 -> V_223 ;
if ( ! V_221 )
return 0 ;
F_116 ( V_187 , V_224 ) ;
for ( V_111 = 0 ; V_111 < V_172 -> V_174 ; V_111 ++ ) {
F_117 ( V_172 -> V_87 [ V_111 ] ) ;
F_118 ( V_172 -> V_23 [ V_111 ] ) ;
}
F_56 ( & V_172 -> V_86 ) ;
V_221 -> V_17 [ V_99 >> 2 ] = F_2 ( F_3 ( V_172 , V_99 ) ) ;
V_221 -> V_17 [ V_148 >> 2 ] = F_2 ( F_3 ( V_172 , V_148 ) ) ;
F_5 ( 0 , F_3 ( V_172 , V_99 ) ) ;
for ( V_111 = 0 ; V_111 < V_225 ; V_111 ++ ) {
if ( ( V_111 * 4 == V_99 ) || ( V_111 * 4 == V_148 ) )
continue;
V_221 -> V_17 [ V_111 ] = F_2 ( F_3 ( V_172 , V_111 * 4 ) ) ;
}
for ( V_111 = 0 ; V_111 < V_50 ; V_111 ++ ) {
F_36 ( V_111 , F_3 ( V_172 , V_39 ) ) ;
for ( V_222 = 0 ; V_222 < V_226 ; V_222 ++ )
V_221 -> V_227 [ V_111 ] [ V_222 ] = F_2 ( F_3 ( V_172 , V_222 * 4 + 0xe0 ) ) ;
}
F_5 ( 0xffffffff , F_3 ( V_172 , V_148 ) ) ;
F_57 ( & V_172 -> V_86 ) ;
F_119 ( V_34 ) ;
F_120 ( V_34 ) ;
F_121 ( V_34 , V_228 ) ;
return 0 ;
}
static int F_122 ( struct V_184 * V_218 )
{
struct V_30 * V_34 = F_114 ( V_218 ) ;
struct V_219 * V_187 = F_115 ( V_218 ) ;
struct V_1 * V_172 = V_187 -> V_24 ;
struct V_220 * V_221 ;
int V_111 , V_222 ;
V_221 = V_172 -> V_223 ;
if ( ! V_221 )
return 0 ;
F_121 ( V_34 , V_229 ) ;
F_123 ( V_34 ) ;
if ( F_124 ( V_34 ) < 0 ) {
F_81 ( V_12 L_38
L_39 ) ;
F_125 ( V_187 ) ;
return - V_8 ;
}
F_126 ( V_34 ) ;
F_56 ( & V_172 -> V_86 ) ;
for ( V_111 = 0 ; V_111 < V_50 ; V_111 ++ ) {
F_36 ( V_111 , F_3 ( V_172 , V_39 ) ) ;
for ( V_222 = 0 ; V_222 < V_226 ; V_222 ++ )
F_5 ( V_221 -> V_227 [ V_111 ] [ V_222 ] , F_3 ( V_172 , V_222 * 4 + 0xe0 ) ) ;
}
for ( V_111 = 0 ; V_111 < V_225 ; V_111 ++ ) {
if ( ( V_111 * 4 == V_99 ) || ( V_111 * 4 == V_148 ) ||
( V_111 * 4 == V_150 ) )
continue;
F_5 ( V_221 -> V_17 [ V_111 ] , F_3 ( V_172 , V_111 * 4 ) ) ;
}
F_5 ( V_221 -> V_17 [ V_150 >> 2 ] , F_3 ( V_172 , V_150 ) ) ;
F_5 ( V_221 -> V_17 [ V_99 >> 2 ] , F_3 ( V_172 , V_99 ) ) ;
F_57 ( & V_172 -> V_86 ) ;
for ( V_111 = 0 ; V_111 < V_172 -> V_174 ; V_111 ++ )
F_127 ( V_172 -> V_23 [ V_111 ] ) ;
F_116 ( V_187 , V_230 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
if ( V_2 -> V_97 )
F_26 ( V_2 ) ;
if ( V_2 -> V_94 >= 0 )
F_129 ( V_2 -> V_94 , V_2 ) ;
if ( V_2 -> V_3 )
F_130 ( V_2 -> V_34 ) ;
F_119 ( V_2 -> V_34 ) ;
#ifdef F_131
F_132 ( V_2 -> V_223 ) ;
#endif
F_133 ( V_2 -> V_33 ) ;
F_133 ( V_2 -> V_231 ) ;
F_132 ( V_2 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
unsigned int V_232 ;
unsigned char V_82 ;
struct V_30 * V_30 ;
F_16 ( L_40 ) ;
if ( F_18 ( V_2 ) ) {
F_12 ( V_12 L_41 ) ;
return - 1 ;
}
if ( V_2 -> V_19 == V_20 ) {
V_30 = V_2 -> V_33 ;
F_44 ( V_30 , 0x59 , & V_82 ) ;
V_82 |= 0x80 ;
F_45 ( V_30 , 0x59 , V_82 ) ;
V_30 = V_2 -> V_231 ;
F_44 ( V_30 , 0xb8 , & V_82 ) ;
V_82 |= 0x20 ;
F_45 ( V_30 , 0xB8 , V_82 ) ;
}
F_19 ( V_2 -> V_34 , 0x44 , & V_232 ) ;
V_232 &= 0xff00ff00 ;
V_232 |= 0x000800aa ;
F_20 ( V_2 -> V_34 , 0x44 , V_232 ) ;
F_5 ( 0x80000001 , F_3 ( V_2 , V_37 ) ) ;
F_5 ( 0x00000000 , F_3 ( V_2 , V_149 ) ) ;
F_5 ( 0xffffffff , F_3 ( V_2 , V_233 ) ) ;
F_5 ( 0x00000000 , F_3 ( V_2 , V_234 ) ) ;
F_36 ( 0x10 , F_3 ( V_2 , V_235 ) ) ;
V_2 -> V_236 = F_14 ( V_2 , 0 , V_237 ) ;
V_2 -> V_238 = F_14 ( V_2 , 0 ,
V_239 ) ;
if ( V_2 -> V_54 ) {
F_43 ( V_2 ) ;
V_2 -> V_209 = 0x00000002 ;
}
V_2 -> V_174 = 1 ;
if ( F_2 ( F_3 ( V_2 , V_75 ) ) & V_240 ) {
V_2 -> V_174 ++ ;
F_5 ( F_2 ( F_3 ( V_2 , V_75 ) ) |
( V_241 | V_242 |
V_243 ) ,
F_3 ( V_2 , V_75 ) ) ;
}
F_16 ( L_42 ) ;
return 0 ;
}
static void F_135 ( struct V_244 * V_245 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = V_245 -> V_24 ;
int V_111 ;
for ( V_111 = 0 ; V_111 < 256 ; V_111 += 4 )
F_136 ( V_247 , L_43 , V_111 , F_2 ( F_3 ( V_2 , V_111 ) ) ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_244 * V_245 ;
if ( ! F_138 ( V_2 -> V_187 , L_44 , & V_245 ) )
F_139 ( V_245 , V_2 , F_135 ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
int V_153 ;
F_16 ( L_45 ) ;
V_153 = F_141 ( V_2 -> V_34 , L_46 ) ;
if ( V_153 < 0 )
return V_153 ;
V_2 -> V_3 = F_142 ( V_2 -> V_34 , 0 ) ;
if ( F_143 ( V_2 -> V_34 -> V_94 , F_54 ,
V_248 , V_249 , V_2 ) ) {
F_12 ( V_12 L_47 ) ;
return - V_250 ;
}
V_2 -> V_94 = V_2 -> V_34 -> V_94 ;
F_16 ( L_48 ) ;
return 0 ;
}
static int F_144 ( struct V_251 * V_184 )
{
struct V_1 * V_2 = V_184 -> V_252 ;
F_128 ( V_2 ) ;
return 0 ;
}
static int F_145 ( struct V_219 * V_187 ,
struct V_30 * V_34 ,
int V_253 ,
int V_54 ,
struct V_1 * * V_254 )
{
struct V_1 * V_2 ;
int V_111 , V_153 ;
unsigned short V_255 ;
static struct V_256 V_213 = {
. V_257 = F_144 ,
} ;
* V_254 = NULL ;
F_16 ( L_49 ) ;
V_153 = F_124 ( V_34 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( F_146 ( V_34 , F_147 ( 31 ) ) < 0 ||
F_148 ( V_34 , F_147 ( 31 ) ) < 0 ) {
F_12 ( V_12 L_50
L_51 ) ;
F_119 ( V_34 ) ;
return - V_258 ;
}
V_2 = F_149 ( sizeof( * V_2 ) , V_259 ) ;
if ( ! V_2 ) {
F_119 ( V_34 ) ;
return - V_154 ;
}
F_150 ( & V_2 -> V_86 ) ;
F_150 ( & V_2 -> V_105 ) ;
V_2 -> V_187 = V_187 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_94 = - 1 ;
V_2 -> V_19 = V_34 -> V_19 ;
V_2 -> V_54 = V_54 ;
if ( V_253 < 1 )
V_253 = 1 ;
if ( V_253 > 32 )
V_253 = 32 ;
F_126 ( V_34 ) ;
F_151 ( V_34 , V_260 , & V_255 ) ;
if ( ( V_255 & V_261 ) != V_261 ) {
V_255 |= V_261 ;
F_152 ( V_34 , V_260 , V_255 ) ;
}
F_126 ( V_34 ) ;
if ( F_140 ( V_2 ) ) {
F_128 ( V_2 ) ;
return - V_250 ;
}
F_153 ( V_34 -> V_94 ) ;
V_2 -> V_48 . V_51 = 0 ;
V_2 -> V_48 . V_49 = 0 ;
V_2 -> V_209 = 0 ;
V_2 -> V_48 . V_262 = 0 ;
if ( V_2 -> V_19 == V_20 )
V_2 -> V_16 . V_17 . V_21 = V_263 ;
else
V_2 -> V_16 . V_17 . V_21 = V_264 ;
V_2 -> V_16 . V_17 . V_18 = V_263 ;
V_2 -> V_16 . V_17 . V_265 = V_150 ;
V_2 -> V_16 . V_17 . V_60 = V_148 ;
V_2 -> V_16 . V_17 . V_84 = V_233 ;
V_2 -> V_16 . V_17 . V_46 = V_149 ;
V_2 -> V_16 . V_45 . V_265 = 0x00 ;
V_2 -> V_16 . V_45 . V_60 = 0x00 ;
V_2 -> V_16 . V_45 . V_84 = 0x00 ;
V_2 -> V_16 . V_45 . V_46 = 0x00 ;
V_2 -> V_33 = F_154 ( 0x10b9 , 0x1533 , NULL ) ;
if ( ! V_2 -> V_33 ) {
F_12 ( V_12 L_52 ) ;
F_128 ( V_2 ) ;
return - V_266 ;
}
V_2 -> V_231 = F_154 ( 0x10b9 , 0x7101 , NULL ) ;
if ( ! V_2 -> V_231 && V_2 -> V_19 == V_20 ) {
F_12 ( V_12 L_53 ) ;
F_128 ( V_2 ) ;
return - V_266 ;
}
F_16 ( L_54 ) ;
V_153 = F_155 ( V_187 , V_267 , V_2 , & V_213 ) ;
if ( V_153 < 0 ) {
F_128 ( V_2 ) ;
return V_153 ;
}
F_156 ( V_187 , & V_34 -> V_218 ) ;
for ( V_111 = 0 ; V_111 < V_50 ; V_111 ++ )
V_2 -> V_48 . V_85 [ V_111 ] . V_89 = V_111 ;
V_153 = F_134 ( V_2 ) ;
if ( V_153 < 0 ) {
F_12 ( V_12 L_55 ) ;
return V_153 ;
}
#ifdef F_131
V_2 -> V_223 = F_157 ( sizeof( * V_2 -> V_223 ) , V_259 ) ;
if ( ! V_2 -> V_223 )
F_12 ( V_163 L_56 ) ;
#endif
F_25 ( V_2 ) ;
V_2 -> V_97 = 1 ;
* V_254 = V_2 ;
F_16 ( L_57 ) ;
return 0 ;
}
static int F_158 ( struct V_30 * V_34 ,
const struct V_268 * V_269 )
{
struct V_219 * V_187 ;
struct V_1 * V_2 ;
int V_153 ;
F_16 ( L_58 ) ;
V_153 = F_159 ( V_270 , V_271 , V_272 , 0 , & V_187 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_145 ( V_187 , V_34 , V_273 , V_274 , & V_2 ) ;
if ( V_153 < 0 )
goto error;
V_187 -> V_24 = V_2 ;
F_16 ( L_59 ) ;
V_153 = F_108 ( V_2 ) ;
if ( V_153 < 0 )
goto error;
F_16 ( L_60 ) ;
V_153 = F_105 ( V_2 ) ;
if ( V_153 < 0 )
goto error;
F_137 ( V_2 ) ;
strcpy ( V_187 -> V_275 , L_61 ) ;
strcpy ( V_187 -> V_276 , L_46 ) ;
sprintf ( V_187 -> V_277 , L_62 ,
V_187 -> V_276 , V_2 -> V_3 , V_2 -> V_94 ) ;
F_16 ( L_63 ) ;
V_153 = F_160 ( V_187 ) ;
if ( V_153 < 0 )
goto error;
F_161 ( V_34 , V_187 ) ;
return 0 ;
error:
F_162 ( V_187 ) ;
return V_153 ;
}
static void F_163 ( struct V_30 * V_34 )
{
F_162 ( F_164 ( V_34 ) ) ;
}
