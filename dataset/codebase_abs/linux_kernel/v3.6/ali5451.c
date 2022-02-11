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
F_21 ( 5000 ) ;
F_19 ( V_30 , 0x7c , & V_15 ) ;
F_20 ( V_30 , 0x7c , V_15 & 0xf7ffffff ) ;
F_21 ( 5000 ) ;
}
V_30 = V_2 -> V_34 ;
F_19 ( V_30 , 0x44 , & V_15 ) ;
F_20 ( V_30 , 0x44 , V_15 | 0x000c0000 ) ;
F_21 ( 500 ) ;
F_19 ( V_30 , 0x44 , & V_15 ) ;
F_20 ( V_30 , 0x44 , V_15 & 0xfffbffff ) ;
F_21 ( 5000 ) ;
V_31 = 200 ;
while( V_31 -- ) {
V_32 = F_14 ( V_2 , 0 , V_35 ) ;
if ( ( V_32 & 0x000f ) == 0x000f )
return 0 ;
F_21 ( 5000 ) ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
unsigned long V_15 ;
V_15 = F_2 ( F_3 ( V_2 , V_37 ) ) ;
V_15 |= 1 << ( V_36 & 0x0000001f ) ;
F_5 ( V_15 , F_3 ( V_2 , V_37 ) ) ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
unsigned long V_15 ;
V_15 = F_2 ( F_3 ( V_2 , V_37 ) ) ;
V_15 &= ~ ( 1 << ( V_36 & 0x0000001f ) ) ;
F_5 ( V_15 , F_3 ( V_2 , V_37 ) ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned int V_38 ;
V_38 = F_2 ( F_3 ( V_2 , V_39 ) ) ;
V_38 |= V_40 ;
V_38 |= V_41 ;
F_5 ( V_38 , F_3 ( V_2 , V_39 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_38 ;
V_38 = F_2 ( F_3 ( V_2 , V_39 ) ) ;
V_38 &= ~ V_40 ;
V_38 &= ~ V_41 ;
F_5 ( V_38 , F_3 ( V_2 , V_39 ) ) ;
}
static void F_26 ( struct V_1 * V_2 ,
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
static int F_27 ( struct V_1 * V_2 , int V_36 )
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
static int F_28 ( struct V_1 * V_2 , int V_52 )
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
V_53 = F_27 ( V_2 , V_47 ) ;
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
V_53 = F_27 ( V_2 , V_47 ) ;
if ( V_53 >= 0 )
return V_53 ;
else
F_12 ( V_12 L_13
L_15 ) ;
}
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_53 = F_27 ( V_2 , V_47 ) ;
if ( V_53 >= 0 )
return V_53 ;
}
F_12 ( V_12 L_16 ) ;
return - 1 ;
}
static void F_29 ( struct V_1 * V_2 , int V_36 )
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
static void F_30 ( struct V_1 * V_2 , unsigned int V_36 )
{
unsigned int V_42 = 1 << ( V_36 & 0x1f ) ;
F_16 ( L_20 , V_36 ) ;
F_5 ( V_42 , F_3 ( V_2 , V_2 -> V_16 . V_17 . V_60 ) ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_61 )
{
unsigned long V_62 , V_63 ;
V_62 = F_2 ( F_3 ( V_2 , V_11 ) ) ;
V_63 = F_2 ( F_3 ( V_2 , V_11 ) ) ;
while ( V_63 < V_62 + V_61 ) {
if ( F_11 ( V_2 ) < 0 )
break;
V_63 = F_2 ( F_3 ( V_2 , V_11 ) ) ;
F_32 () ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_64 ;
T_1 V_65 = 0 ;
T_2 V_66 , V_67 = 0 , V_68 ;
V_66 = F_34 ( F_3 ( V_2 , V_69 + 1 ) ) ;
V_66 |= 0x1F ;
F_35 ( V_66 , F_3 ( V_2 , V_69 + 1 ) ) ;
while ( ( V_67 < 0x0b || V_67 > 0x0e ) && V_67 != 0x12 && V_65 <= 50000 ) {
V_65 ++ ;
F_31 ( V_2 , 6 ) ;
V_66 = F_34 ( F_3 ( V_2 , V_69 + 1 ) ) ;
V_67 = V_66 & 0x1F ;
}
if ( V_65 > 50000 ) {
F_12 ( V_12 L_21 ) ;
return;
}
for ( V_65 = 0 ; V_65 <= 50000 ; V_65 ++ ) {
F_31 ( V_2 , 6 ) ;
V_66 = F_34 ( F_3 ( V_2 , V_69 + 1 ) ) ;
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
V_64 = F_36 ( F_3 ( V_2 , V_69 + 2 ) ) ;
V_64 &= 0xe0f0 ;
V_64 |= ( 0x09 << 8 ) | 0x05 ;
F_37 ( V_64 , F_3 ( V_2 , V_69 + 2 ) ) ;
V_66 = F_34 ( F_3 ( V_2 , V_70 + 3 ) ) & 0xf0 ;
F_35 ( V_66 | 0x02 , F_3 ( V_2 , V_70 + 3 ) ) ;
} else if ( V_68 == 0x12 ) {
V_64 = F_36 ( F_3 ( V_2 , V_69 + 2 ) ) ;
V_64 &= 0xe0f0 ;
V_64 |= ( 0x0e << 8 ) | 0x08 ;
F_37 ( V_64 , F_3 ( V_2 , V_69 + 2 ) ) ;
V_66 = F_34 ( F_3 ( V_2 , V_70 + 3 ) ) & 0xf0 ;
F_35 ( V_66 | 0x03 , F_3 ( V_2 , V_70 + 3 ) ) ;
}
}
static unsigned int F_38 ( struct V_1 * V_2 )
{
T_3 V_71 ;
T_2 V_66 ;
V_66 = F_34 ( F_3 ( V_2 , V_69 ) ) ;
V_66 &= 0x7f ;
V_66 |= 0x40 ;
F_35 ( V_66 , F_3 ( V_2 , V_69 ) ) ;
F_33 ( V_2 ) ;
V_66 = F_34 ( F_3 ( V_2 , V_70 + 3 ) ) ;
V_66 &= 0x0f ;
switch ( V_66 ) {
case 0 : V_71 = 44100 ; break;
case 1 : V_71 = 48000 ; break;
case 2 : V_71 = 32000 ; break;
default: V_71 = 0 ; break;
}
return V_71 ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
V_15 = F_2 ( F_3 ( V_2 , V_37 ) ) ;
V_15 |= V_55 ;
F_5 ( V_15 , F_3 ( V_2 , V_37 ) ) ;
V_15 = F_34 ( F_3 ( V_2 , V_69 ) ) ;
V_15 |= 0x02 ;
F_35 ( V_15 , F_3 ( V_2 , V_69 ) ) ;
F_22 ( V_2 , V_56 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
V_15 = F_2 ( F_3 ( V_2 , V_37 ) ) ;
V_15 &= ~ V_55 ;
F_5 ( V_15 , F_3 ( V_2 , V_37 ) ) ;
F_23 ( V_2 , V_56 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_72 )
{
unsigned char V_73 ;
unsigned int V_71 ;
switch ( V_72 ) {
case 32000 : V_71 = 0x300 ; break;
case 48000 : V_71 = 0x200 ; break;
default: V_71 = 0 ; break;
}
V_73 = F_34 ( F_3 ( V_2 , V_69 ) ) ;
V_73 &= ( unsigned char ) ( ~ ( 1 << 6 ) ) ;
V_73 |= 0x80 ;
F_35 ( V_73 , F_3 ( V_2 , V_69 ) ) ;
F_35 ( V_71 | 0x20 , F_3 ( V_2 , V_70 + 2 ) ) ;
V_73 &= ~ 0x80 ;
F_35 ( V_73 , F_3 ( V_2 , V_69 ) ) ;
F_37 ( V_72 | 0x10 , F_3 ( V_2 , V_70 + 2 ) ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned short V_74 ;
unsigned char V_73 ;
struct V_30 * V_30 ;
V_30 = V_2 -> V_33 ;
if ( V_30 == NULL )
return;
F_43 ( V_30 , 0x61 , & V_73 ) ;
V_73 |= 0x40 ;
F_44 ( V_30 , 0x61 , V_73 ) ;
F_43 ( V_30 , 0x7d , & V_73 ) ;
V_73 |= 0x01 ;
F_44 ( V_30 , 0x7d , V_73 ) ;
F_43 ( V_30 , 0x7e , & V_73 ) ;
V_73 &= ( ~ 0x20 ) ;
V_73 |= 0x10 ;
F_44 ( V_30 , 0x7e , V_73 ) ;
V_73 = F_34 ( F_3 ( V_2 , V_75 ) ) ;
F_35 ( V_73 | V_76 , F_3 ( V_2 , V_75 ) ) ;
V_73 = F_34 ( F_3 ( V_2 , V_69 ) ) ;
F_35 ( V_73 & V_77 , F_3 ( V_2 , V_69 ) ) ;
V_74 = F_36 ( F_3 ( V_2 , V_37 ) ) ;
V_74 |= V_78 ;
F_37 ( V_74 , F_3 ( V_2 , V_37 ) ) ;
F_23 ( V_2 , V_59 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned short V_74 ;
V_74 = F_36 ( F_3 ( V_2 , V_37 ) ) ;
V_74 &= ~ V_78 ;
F_37 ( V_74 , F_3 ( V_2 , V_37 ) ) ;
F_22 ( V_2 , V_59 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
unsigned short V_74 ;
V_74 = F_36 ( F_3 ( V_2 , V_37 ) ) ;
V_74 |= V_78 ;
F_37 ( V_74 , F_3 ( V_2 , V_37 ) ) ;
F_22 ( V_2 , V_59 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned char V_73 ;
V_73 = F_34 ( F_3 ( V_2 , V_75 ) ) ;
F_35 ( V_73 & ~ V_76 , F_3 ( V_2 , V_75 ) ) ;
F_46 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_36 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_43 * V_44 ;
unsigned int V_83 , V_42 ;
#ifdef F_49
unsigned int V_84 , V_85 ;
#endif
V_44 = & ( V_2 -> V_16 ) ;
V_83 = V_44 -> V_45 . V_86 ;
V_42 = 1U << ( V_36 & 0x1f ) ;
if ( ! ( V_83 & V_42 ) )
return;
V_80 = & V_2 -> V_48 . V_87 [ V_36 ] ;
V_82 = V_80 -> V_88 -> V_82 ;
F_21 ( 100 ) ;
F_50 ( & V_2 -> V_89 ) ;
if ( V_80 -> V_90 && V_80 -> V_88 ) {
#ifdef F_49
F_35 ( ( T_2 ) ( V_80 -> V_91 ) , F_3 ( V_2 , V_39 ) ) ;
V_84 = F_36 ( F_3 ( V_2 , V_92 + 2 ) ) ;
V_85 = ( F_2 ( F_3 ( V_2 , V_93 ) ) & V_42 ) == V_42 ;
#endif
if ( V_80 -> V_94 ) {
F_16 ( L_22 ,
( T_1 ) V_84 , V_85 ) ;
F_51 ( & V_2 -> V_89 ) ;
F_52 ( V_80 -> V_88 ) ;
F_50 ( & V_2 -> V_89 ) ;
} else {
F_30 ( V_2 , V_36 ) ;
F_26 ( V_2 , V_36 ) ;
}
} else if ( V_2 -> V_48 . V_87 [ V_36 ] . V_48 ) {
} else if ( V_2 -> V_48 . V_87 [ V_36 ] . V_95 ) {
} else {
F_30 ( V_2 , V_36 ) ;
F_26 ( V_2 , V_36 ) ;
}
F_51 ( & V_2 -> V_89 ) ;
F_5 ( V_42 , F_3 ( V_2 , V_44 -> V_17 . V_86 ) ) ;
V_44 -> V_45 . V_86 = V_83 & ( ~ V_42 ) ;
}
static T_4 F_53 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
int V_36 ;
unsigned int V_98 ;
struct V_43 * V_44 ;
if ( V_2 == NULL || ! V_2 -> V_99 )
return V_100 ;
V_98 = F_2 ( F_3 ( V_2 , V_101 ) ) ;
if ( ! V_98 )
return V_100 ;
V_44 = & ( V_2 -> V_16 ) ;
if ( V_98 & V_102 ) {
V_44 -> V_45 . V_86 = F_2 ( F_3 ( V_2 , V_44 -> V_17 . V_86 ) ) ;
for ( V_36 = 0 ; V_36 < V_50 ; V_36 ++ )
F_48 ( V_2 , V_36 ) ;
}
F_5 ( ( V_103 | V_104 | V_105 ) ,
F_3 ( V_2 , V_101 ) ) ;
return V_106 ;
}
static struct V_79 * F_54 ( struct V_1 * V_2 ,
int type , int V_52 , int V_36 )
{
struct V_79 * V_80 ;
int V_47 ;
F_16 ( L_23 , type , V_52 ) ;
F_55 ( & V_2 -> V_107 ) ;
if ( type == V_108 ) {
V_47 = V_36 > 0 ? F_27 ( V_2 , V_36 ) :
F_28 ( V_2 , V_52 ) ;
if ( V_47 < 0 ) {
F_12 ( V_12 L_24 ) ;
F_56 ( & V_2 -> V_107 ) ;
return NULL ;
}
V_80 = & ( V_2 -> V_48 . V_87 [ V_47 ] ) ;
V_80 -> V_2 = V_2 ;
V_80 -> V_109 = 1 ;
V_80 -> V_90 = 1 ;
V_80 -> V_110 = V_52 ;
F_56 ( & V_2 -> V_107 ) ;
return V_80 ;
}
F_56 ( & V_2 -> V_107 ) ;
return NULL ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
void (* F_58)( void * );
void * V_24 ;
F_16 ( L_25 , V_80 -> V_91 ) ;
if ( ! V_80 -> V_109 )
return;
F_59 ( V_2 , V_80 -> V_91 , V_80 -> V_91 ) ;
F_55 ( & V_2 -> V_107 ) ;
F_58 = V_80 -> F_58 ;
V_24 = V_80 -> V_24 ;
V_80 -> F_58 = NULL ;
V_80 -> V_24 = NULL ;
if ( V_80 -> V_90 )
F_29 ( V_2 , V_80 -> V_91 ) ;
V_80 -> V_109 = V_80 -> V_90 = V_80 -> V_48 = 0 ;
V_80 -> V_88 = NULL ;
F_56 ( & V_2 -> V_107 ) ;
if ( F_58 )
F_58 ( V_24 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_111 ,
unsigned int V_112 )
{
unsigned int V_113 ;
for ( V_113 = V_111 ; V_113 <= V_112 ; V_113 ++ ) {
F_30 ( V_2 , V_113 ) ;
F_26 ( V_2 , V_113 ) ;
}
}
static void F_60 ( struct V_1 * V_2 ,
unsigned int V_114 ,
unsigned int V_115 ,
unsigned int V_116 ,
unsigned int V_117 ,
unsigned int V_118 ,
unsigned int V_119 ,
unsigned int V_120 ,
unsigned int V_121 ,
unsigned int V_122 ,
unsigned int V_123 ,
unsigned int V_124 )
{
unsigned int V_125 [ 4 ] ;
F_35 ( ( unsigned char ) ( V_114 & 0x001f ) , F_3 ( V_2 , V_39 ) ) ;
V_125 [ 0 ] = ( V_116 << 16 ) | ( V_119 & 0x0000ffff ) ;
V_125 [ 1 ] = V_115 ;
V_125 [ 2 ] = ( V_117 << 16 ) | ( V_118 & 0x0ffff ) ;
V_125 [ 3 ] = ( V_120 << 31 ) |
( ( V_121 & 0x0000007f ) << 24 ) |
( ( V_122 & 0x000000ff ) << 16 ) |
( ( V_123 & 0x0000000f ) << 12 ) |
( V_124 & 0x00000fff ) ;
F_35 ( V_114 , F_3 ( V_2 , V_39 ) ) ;
F_5 ( V_125 [ 0 ] , F_3 ( V_2 , V_92 ) ) ;
F_5 ( V_125 [ 1 ] , F_3 ( V_2 , V_126 ) ) ;
F_5 ( V_125 [ 2 ] , F_3 ( V_2 , V_127 ) ) ;
F_5 ( V_125 [ 3 ] , F_3 ( V_2 , V_128 ) ) ;
F_5 ( 0x30000000 , F_3 ( V_2 , V_129 ) ) ;
F_5 ( 0x30000000 , F_3 ( V_2 , V_130 ) ) ;
}
static unsigned int F_61 ( unsigned int V_72 , int V_52 )
{
unsigned int V_131 ;
if ( V_72 < 4000 )
V_72 = 4000 ;
if ( V_72 > 48000 )
V_72 = 48000 ;
if ( V_52 ) {
if ( V_72 == 44100 )
V_131 = 0x116a ;
else if ( V_72 == 8000 )
V_131 = 0x6000 ;
else if ( V_72 == 48000 )
V_131 = 0x1000 ;
else
V_131 = ( ( 48000 << 12 ) / V_72 ) & 0x0000ffff ;
} else {
if ( V_72 == 44100 )
V_131 = 0xeb3 ;
else if ( V_72 == 8000 )
V_131 = 0x2ab ;
else if ( V_72 == 48000 )
V_131 = 0x1000 ;
else
V_131 = ( ( ( V_72 << 12 ) + V_72 ) / 48000 ) & 0x0000ffff ;
}
return V_131 ;
}
static unsigned int F_62 ( struct V_132 * V_88 )
{
unsigned int V_123 ;
struct V_81 * V_82 = V_88 -> V_82 ;
V_123 = 0x00000001 ;
if ( F_63 ( V_82 -> V_133 ) == 16 )
V_123 |= 0x00000008 ;
if ( ! F_64 ( V_82 -> V_133 ) )
V_123 |= 0x00000002 ;
if ( V_82 -> V_134 > 1 )
V_123 |= 0x00000004 ;
return V_123 ;
}
static int F_65 ( struct V_132 * V_88 ,
int V_135 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_132 * V_136 ;
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
F_67 (s, substream) {
if ( (struct V_1 * ) F_66 ( V_136 ) == V_2 ) {
V_80 = V_136 -> V_82 -> V_24 ;
V_140 = V_80 -> V_147 ;
V_137 |= 1 << ( V_80 -> V_91 & 0x1f ) ;
if ( V_140 == NULL )
V_138 |= 1 << ( V_80 -> V_91 & 0x1f ) ;
else {
V_138 |= 1 << ( V_140 -> V_91 & 0x1f ) ;
V_137 |= 1 << ( V_140 -> V_91 & 0x1f ) ;
}
if ( V_141 ) {
V_80 -> V_94 = 1 ;
if ( V_140 != NULL )
V_140 -> V_94 = 1 ;
} else {
V_80 -> V_94 = 0 ;
if ( V_140 != NULL )
V_140 -> V_94 = 0 ;
}
F_68 ( V_136 , V_88 ) ;
if ( V_80 -> V_110 )
V_139 = 1 ;
}
}
F_50 ( & V_2 -> V_89 ) ;
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
F_51 ( & V_2 -> V_89 ) ;
return 0 ;
}
static int F_69 ( struct V_132 * V_88 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_81 * V_82 = V_88 -> V_82 ;
struct V_79 * V_80 = V_82 -> V_24 ;
struct V_79 * V_140 = V_80 -> V_147 ;
int V_153 ;
V_153 = F_70 ( V_88 ,
F_71 ( V_152 ) ) ;
if ( V_153 < 0 )
return V_153 ;
if ( F_72 ( V_152 ) / 2 !=
F_73 ( V_152 ) ) {
if ( ! V_140 ) {
V_140 = F_54 ( V_2 ,
V_108 ,
0 , - 1 ) ;
if ( ! V_140 )
return - V_154 ;
V_80 -> V_147 = V_140 ;
V_140 -> V_88 = V_88 ;
}
} else {
if ( V_140 ) {
F_57 ( V_2 , V_140 ) ;
V_80 -> V_147 = V_140 = NULL ;
}
}
return 0 ;
}
static int F_74 ( struct V_132 * V_88 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_81 * V_82 = V_88 -> V_82 ;
struct V_79 * V_80 = V_82 -> V_24 ;
struct V_79 * V_140 = V_80 ? V_80 -> V_147 : NULL ;
F_75 ( V_88 ) ;
if ( V_140 ) {
F_57 ( V_2 , V_140 ) ;
V_80 -> V_147 = NULL ;
}
return 0 ;
}
static int F_76 ( struct V_132 * V_88 ,
struct V_151 * V_152 )
{
return F_70 ( V_88 ,
F_71 ( V_152 ) ) ;
}
static int F_77 ( struct V_132 * V_88 )
{
return F_75 ( V_88 ) ;
}
static int F_78 ( struct V_132 * V_88 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_81 * V_82 = V_88 -> V_82 ;
struct V_79 * V_80 = V_82 -> V_24 ;
struct V_79 * V_140 = V_80 -> V_147 ;
unsigned int V_115 ;
unsigned int V_155 ;
unsigned int V_117 ;
unsigned int V_123 ;
unsigned int V_120 ;
unsigned int V_121 ;
unsigned int V_122 ;
unsigned int V_124 ;
F_16 ( L_27 ) ;
F_55 ( & V_2 -> V_89 ) ;
V_155 = F_61 ( V_82 -> V_72 , 0 ) ;
if ( V_80 -> V_91 == V_56 ||
V_80 -> V_91 == V_57 )
F_23 ( V_2 , V_80 -> V_91 ) ;
else if ( V_2 -> V_54 &&
( F_2 ( F_3 ( V_2 , V_37 ) ) &
V_58 )
&& V_80 -> V_91 == V_59 ) {
F_41 ( V_2 , V_82 -> V_72 ) ;
V_155 = 0x1000 ;
}
V_115 = V_82 -> V_156 ;
V_80 -> V_65 = V_82 -> V_157 ;
V_80 -> V_158 = V_82 -> V_159 ;
F_16 ( L_28 ,
V_80 -> V_158 , V_80 -> V_65 ) ;
V_117 = V_80 -> V_158 - 1 ;
V_123 = F_62 ( V_88 ) ;
V_120 = 1 ;
V_121 = 0 ;
V_122 = 0 ;
V_124 = 0 ;
F_16 ( L_29 ) ;
F_16 ( L_30 ,
V_80 -> V_91 , V_82 -> V_72 , V_155 , V_120 , V_121 , V_123 ) ;
F_60 ( V_2 ,
V_80 -> V_91 ,
V_115 ,
0 ,
V_117 ,
V_155 ,
0 ,
V_120 ,
V_121 ,
V_122 ,
V_123 ,
V_124 ) ;
if ( V_140 ) {
V_140 -> V_65 = V_80 -> V_65 ;
V_140 -> V_158 = V_80 -> V_65 << 1 ;
V_117 = V_140 -> V_158 - 1 ;
F_60 ( V_2 ,
V_140 -> V_91 ,
V_115 ,
0 ,
V_117 ,
V_155 ,
0 ,
V_120 ,
0x7f ,
0x3ff ,
V_123 ,
V_124 ) ;
}
F_56 ( & V_2 -> V_89 ) ;
return 0 ;
}
static int F_79 ( struct V_132 * V_88 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_81 * V_82 = V_88 -> V_82 ;
struct V_79 * V_80 = V_82 -> V_24 ;
unsigned int V_115 ;
unsigned int V_155 ;
unsigned int V_117 ;
unsigned int V_123 ;
unsigned int V_120 ;
unsigned int V_121 ;
unsigned int V_122 ;
unsigned int V_124 ;
T_2 V_160 ;
F_55 ( & V_2 -> V_89 ) ;
F_16 ( L_31 ) ;
F_22 ( V_2 , V_80 -> V_91 ) ;
V_155 = ( V_80 -> V_91 == V_161 ||
V_80 -> V_91 == V_162 ) ?
0x1000 : F_61 ( V_82 -> V_72 , V_80 -> V_110 ) ;
if ( V_80 -> V_91 == V_56 ) {
unsigned int V_72 ;
F_56 ( & V_2 -> V_89 ) ;
if ( V_2 -> V_19 != V_20 )
return - 1 ;
V_72 = F_38 ( V_2 ) ;
if ( V_72 == 0 ) {
F_12 ( V_163 L_32
L_33 ) ;
V_72 = 48000 ;
}
F_55 ( & V_2 -> V_89 ) ;
V_160 = F_34 ( F_3 ( V_2 , V_69 ) ) ;
if ( V_160 & 0x10 ) {
F_35 ( V_160 , F_3 ( V_2 , V_69 ) ) ;
F_80 ( V_163 L_34 ) ;
}
if ( V_72 != 48000 )
V_155 = ( ( V_72 << 12 ) / V_82 -> V_72 ) & 0x00ffff ;
}
V_80 -> V_158 = V_82 -> V_159 ;
V_80 -> V_65 = V_82 -> V_157 ;
V_115 = V_82 -> V_156 ;
V_117 = V_80 -> V_158 - 1 ;
V_123 = F_62 ( V_88 ) ;
V_120 = 0 ;
V_121 = 0x00 ;
V_122 = 0x00 ;
V_124 = 0 ;
F_60 ( V_2 ,
V_80 -> V_91 ,
V_115 ,
0 ,
V_117 ,
V_155 ,
0 ,
V_120 ,
V_121 ,
V_122 ,
V_123 ,
V_124 ) ;
F_56 ( & V_2 -> V_89 ) ;
return 0 ;
}
static T_5
F_81 ( struct V_132 * V_88 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_81 * V_82 = V_88 -> V_82 ;
struct V_79 * V_80 = V_82 -> V_24 ;
unsigned int V_164 ;
F_50 ( & V_2 -> V_89 ) ;
if ( ! V_80 -> V_94 ) {
F_51 ( & V_2 -> V_89 ) ;
return 0 ;
}
F_35 ( V_80 -> V_91 , F_3 ( V_2 , V_39 ) ) ;
V_164 = F_36 ( F_3 ( V_2 , V_92 + 2 ) ) ;
F_51 ( & V_2 -> V_89 ) ;
F_16 ( L_35 , V_164 ) ;
return V_164 ;
}
static T_5 F_82 ( struct V_132 * V_88 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_81 * V_82 = V_88 -> V_82 ;
struct V_79 * V_80 = V_82 -> V_24 ;
unsigned int V_164 ;
F_50 ( & V_2 -> V_89 ) ;
if ( ! V_80 -> V_94 ) {
F_56 ( & V_2 -> V_89 ) ;
return 0 ;
}
F_35 ( V_80 -> V_91 , F_3 ( V_2 , V_39 ) ) ;
V_164 = F_36 ( F_3 ( V_2 , V_92 + 2 ) ) ;
F_51 ( & V_2 -> V_89 ) ;
return V_164 ;
}
static void F_83 ( struct V_81 * V_82 )
{
struct V_79 * V_80 = V_82 -> V_24 ;
struct V_1 * V_2 ;
if ( V_80 ) {
V_2 = V_80 -> V_2 ;
F_57 ( V_80 -> V_2 , V_80 ) ;
}
}
static int F_84 ( struct V_132 * V_88 , int V_52 ,
int V_36 , struct V_165 * V_166 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_81 * V_82 = V_88 -> V_82 ;
struct V_79 * V_80 ;
V_80 = F_54 ( V_2 , V_108 , V_52 ,
V_36 ) ;
if ( ! V_80 )
return - V_167 ;
V_80 -> V_88 = V_88 ;
V_82 -> V_24 = V_80 ;
V_82 -> F_58 = F_83 ;
V_82 -> V_168 = * V_166 ;
F_85 ( V_88 ) ;
F_86 ( V_82 , V_169 ,
0 , 64 * 1024 ) ;
return 0 ;
}
static int F_87 ( struct V_132 * V_88 )
{
return F_84 ( V_88 , 0 , - 1 , & V_170 ) ;
}
static int F_88 ( struct V_132 * V_88 )
{
return F_84 ( V_88 , 1 , - 1 , & V_171 ) ;
}
static int F_89 ( struct V_132 * V_88 )
{
return 0 ;
}
static int F_90 ( struct V_132 * V_88 )
{
struct V_1 * V_2 = F_66 ( V_88 ) ;
struct V_79 * V_80 = V_88 -> V_82 -> V_24 ;
F_23 ( V_2 , V_80 -> V_91 ) ;
return 0 ;
}
static int F_91 ( struct V_132 * V_88 ,
struct V_151 * V_152 )
{
struct V_1 * V_172 = F_66 ( V_88 ) ;
unsigned int V_173 = V_172 -> V_174 - 1 ;
F_92 ( V_172 -> V_23 [ V_173 ] , V_175 ,
F_93 ( V_152 ) ) ;
F_92 ( V_172 -> V_23 [ V_173 ] , V_176 , 0 ) ;
return F_76 ( V_88 , V_152 ) ;
}
static int F_94 ( struct V_132 * V_88 , int V_52 ,
int V_36 )
{
static unsigned int V_177 [] = { 8000 , 9600 , 12000 , 16000 } ;
static struct V_178 V_179 = {
. V_65 = F_95 ( V_177 ) ,
. V_180 = V_177 ,
. V_42 = 0 ,
} ;
int V_153 = F_84 ( V_88 , V_52 , V_36 , & V_181 ) ;
if ( V_153 )
return V_153 ;
return V_178 ( V_88 -> V_82 , 0 ,
V_182 , & V_179 ) ;
}
static int F_96 ( struct V_132 * V_88 )
{
return F_94 ( V_88 , 0 , V_162 ) ;
}
static int F_97 ( struct V_132 * V_88 )
{
return F_94 ( V_88 , 1 , V_161 ) ;
}
static void F_98 ( struct V_183 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_24 ;
V_2 -> V_90 [ V_90 -> V_184 ] = NULL ;
}
static int T_6 F_99 ( struct V_1 * V_2 , int V_184 ,
struct V_185 * V_186 )
{
struct V_183 * V_90 ;
int V_153 ;
V_153 = F_100 ( V_2 -> V_187 , V_186 -> V_188 , V_184 ,
V_186 -> V_189 , V_186 -> V_190 , & V_90 ) ;
if ( V_153 < 0 ) {
F_12 ( V_12 L_36 ) ;
return V_153 ;
}
V_90 -> V_24 = V_2 ;
V_90 -> F_58 = F_98 ;
if ( V_186 -> V_191 )
F_101 ( V_90 , V_192 ,
V_186 -> V_191 ) ;
if ( V_186 -> V_193 )
F_101 ( V_90 , V_194 ,
V_186 -> V_193 ) ;
F_102 ( V_90 , V_195 ,
F_103 ( V_2 -> V_34 ) ,
64 * 1024 , 128 * 1024 ) ;
V_90 -> V_196 = 0 ;
V_90 -> V_197 = V_186 -> V_198 ;
V_90 -> V_199 = V_200 ;
strcpy ( V_90 -> V_188 , V_186 -> V_188 ) ;
V_2 -> V_90 [ 0 ] = V_90 ;
return 0 ;
}
static int T_6 F_104 ( struct V_1 * V_2 )
{
int V_113 , V_153 ;
for ( V_113 = 0 ; V_113 < V_2 -> V_174 && V_113 < F_95 ( V_201 ) ; V_113 ++ ) {
V_153 = F_99 ( V_2 , V_113 , & V_201 [ V_113 ] ) ;
if ( V_153 < 0 )
return V_153 ;
}
return 0 ;
}
static int F_105 ( struct V_202 * V_203 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = V_203 -> V_24 ;
unsigned int V_206 ;
V_206 = V_205 -> V_207 . integer . V_207 [ 0 ] ? 1 : 0 ;
F_55 ( & V_2 -> V_89 ) ;
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
F_56 ( & V_2 -> V_89 ) ;
return 0 ;
}
static int F_106 ( struct V_202 * V_203 ,
struct V_204 * V_205 )
{
struct V_1 * V_2 = V_203 -> V_24 ;
unsigned int V_210 = 0 , V_206 = 0 ;
V_206 = V_205 -> V_207 . integer . V_207 [ 0 ] ? 1 : 0 ;
F_55 ( & V_2 -> V_89 ) ;
switch ( V_203 -> V_208 ) {
case 0 :
V_210 = ( V_2 -> V_209 & 0x02 ) ? 1 : 0 ;
V_210 = V_210 ^ V_206 ;
if ( V_210 ) {
if ( V_206 ) {
V_2 -> V_209 |= 0x02 ;
F_42 ( V_2 ) ;
} else {
V_2 -> V_209 &= ~ ( 0x02 ) ;
V_2 -> V_209 &= ~ ( 0x04 ) ;
F_47 ( V_2 ) ;
}
}
break;
case 1 :
V_210 = ( V_2 -> V_209 & 0x04 ) ? 1 : 0 ;
V_210 = V_210 ^ V_206 ;
if ( V_210 && ( V_2 -> V_209 & 0x02 ) ) {
if ( V_206 ) {
V_2 -> V_209 |= 0x04 ;
F_45 ( V_2 ) ;
} else {
V_2 -> V_209 &= ~ ( 0x04 ) ;
F_46 ( V_2 ) ;
}
}
break;
case 2 :
V_210 = ( V_2 -> V_209 & 0x01 ) ? 1 : 0 ;
V_210 = V_210 ^ V_206 ;
if ( V_210 ) {
if ( V_206 ) {
V_2 -> V_209 |= 0x01 ;
F_39 ( V_2 ) ;
} else {
V_2 -> V_209 &= ~ ( 0x01 ) ;
F_40 ( V_2 ) ;
}
}
break;
default:
break;
}
F_56 ( & V_2 -> V_89 ) ;
return V_210 ;
}
static int T_6 F_107 ( struct V_1 * V_2 )
{
struct V_211 V_23 ;
unsigned int V_47 ;
int V_113 , V_153 ;
static struct V_212 V_213 = {
. V_214 = F_15 ,
. V_215 = F_17 ,
} ;
V_153 = F_108 ( V_2 -> V_187 , 0 , & V_213 , V_2 , & V_2 -> V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_24 = V_2 ;
for ( V_113 = 0 ; V_113 < V_2 -> V_174 ; V_113 ++ ) {
V_23 . V_29 = V_113 ;
V_153 = F_109 ( V_2 -> V_216 , & V_23 , & V_2 -> V_23 [ V_113 ] ) ;
if ( V_153 < 0 ) {
F_12 ( V_12
L_37 , V_113 ) ;
if ( V_113 == 0 )
return V_153 ;
V_2 -> V_174 = 1 ;
break;
}
}
if ( V_2 -> V_54 ) {
for ( V_47 = 0 ; V_47 < F_95 ( V_217 ) ; V_47 ++ ) {
V_153 = F_110 ( V_2 -> V_187 ,
F_111 ( & V_217 [ V_47 ] , V_2 ) ) ;
if ( V_153 < 0 )
return V_153 ;
}
}
return 0 ;
}
static int F_112 ( struct V_184 * V_218 )
{
struct V_30 * V_34 = F_113 ( V_218 ) ;
struct V_219 * V_187 = F_114 ( V_218 ) ;
struct V_1 * V_172 = V_187 -> V_24 ;
struct V_220 * V_221 ;
int V_113 , V_222 ;
V_221 = V_172 -> V_223 ;
if ( ! V_221 )
return 0 ;
F_115 ( V_187 , V_224 ) ;
for ( V_113 = 0 ; V_113 < V_172 -> V_174 ; V_113 ++ ) {
F_116 ( V_172 -> V_90 [ V_113 ] ) ;
F_117 ( V_172 -> V_23 [ V_113 ] ) ;
}
F_55 ( & V_172 -> V_89 ) ;
V_221 -> V_17 [ V_101 >> 2 ] = F_2 ( F_3 ( V_172 , V_101 ) ) ;
V_221 -> V_17 [ V_148 >> 2 ] = F_2 ( F_3 ( V_172 , V_148 ) ) ;
F_5 ( 0 , F_3 ( V_172 , V_101 ) ) ;
for ( V_113 = 0 ; V_113 < V_225 ; V_113 ++ ) {
if ( ( V_113 * 4 == V_101 ) || ( V_113 * 4 == V_148 ) )
continue;
V_221 -> V_17 [ V_113 ] = F_2 ( F_3 ( V_172 , V_113 * 4 ) ) ;
}
for ( V_113 = 0 ; V_113 < V_50 ; V_113 ++ ) {
F_35 ( V_113 , F_3 ( V_172 , V_39 ) ) ;
for ( V_222 = 0 ; V_222 < V_226 ; V_222 ++ )
V_221 -> V_227 [ V_113 ] [ V_222 ] = F_2 ( F_3 ( V_172 , V_222 * 4 + 0xe0 ) ) ;
}
F_5 ( 0xffffffff , F_3 ( V_172 , V_148 ) ) ;
F_56 ( & V_172 -> V_89 ) ;
F_118 ( V_34 ) ;
F_119 ( V_34 ) ;
F_120 ( V_34 , V_228 ) ;
return 0 ;
}
static int F_121 ( struct V_184 * V_218 )
{
struct V_30 * V_34 = F_113 ( V_218 ) ;
struct V_219 * V_187 = F_114 ( V_218 ) ;
struct V_1 * V_172 = V_187 -> V_24 ;
struct V_220 * V_221 ;
int V_113 , V_222 ;
V_221 = V_172 -> V_223 ;
if ( ! V_221 )
return 0 ;
F_120 ( V_34 , V_229 ) ;
F_122 ( V_34 ) ;
if ( F_123 ( V_34 ) < 0 ) {
F_80 ( V_12 L_38
L_39 ) ;
F_124 ( V_187 ) ;
return - V_8 ;
}
F_125 ( V_34 ) ;
F_55 ( & V_172 -> V_89 ) ;
for ( V_113 = 0 ; V_113 < V_50 ; V_113 ++ ) {
F_35 ( V_113 , F_3 ( V_172 , V_39 ) ) ;
for ( V_222 = 0 ; V_222 < V_226 ; V_222 ++ )
F_5 ( V_221 -> V_227 [ V_113 ] [ V_222 ] , F_3 ( V_172 , V_222 * 4 + 0xe0 ) ) ;
}
for ( V_113 = 0 ; V_113 < V_225 ; V_113 ++ ) {
if ( ( V_113 * 4 == V_101 ) || ( V_113 * 4 == V_148 ) ||
( V_113 * 4 == V_150 ) )
continue;
F_5 ( V_221 -> V_17 [ V_113 ] , F_3 ( V_172 , V_113 * 4 ) ) ;
}
F_5 ( V_221 -> V_17 [ V_150 >> 2 ] , F_3 ( V_172 , V_150 ) ) ;
F_5 ( V_221 -> V_17 [ V_101 >> 2 ] , F_3 ( V_172 , V_101 ) ) ;
F_56 ( & V_172 -> V_89 ) ;
for ( V_113 = 0 ; V_113 < V_172 -> V_174 ; V_113 ++ )
F_126 ( V_172 -> V_23 [ V_113 ] ) ;
F_115 ( V_187 , V_230 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
if ( V_2 -> V_99 )
F_25 ( V_2 ) ;
if ( V_2 -> V_96 >= 0 )
F_128 ( V_2 -> V_96 , V_2 ) ;
if ( V_2 -> V_3 )
F_129 ( V_2 -> V_34 ) ;
F_118 ( V_2 -> V_34 ) ;
#ifdef F_130
F_131 ( V_2 -> V_223 ) ;
#endif
F_132 ( V_2 -> V_33 ) ;
F_132 ( V_2 -> V_231 ) ;
F_131 ( V_2 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 )
{
unsigned int V_232 ;
unsigned char V_84 ;
struct V_30 * V_30 ;
F_16 ( L_40 ) ;
if ( F_18 ( V_2 ) ) {
F_12 ( V_12 L_41 ) ;
return - 1 ;
}
if ( V_2 -> V_19 == V_20 ) {
V_30 = V_2 -> V_33 ;
F_43 ( V_30 , 0x59 , & V_84 ) ;
V_84 |= 0x80 ;
F_44 ( V_30 , 0x59 , V_84 ) ;
V_30 = V_2 -> V_231 ;
F_43 ( V_30 , 0xb8 , & V_84 ) ;
V_84 |= 0x20 ;
F_44 ( V_30 , 0xB8 , V_84 ) ;
}
F_19 ( V_2 -> V_34 , 0x44 , & V_232 ) ;
V_232 &= 0xff00ff00 ;
V_232 |= 0x000800aa ;
F_20 ( V_2 -> V_34 , 0x44 , V_232 ) ;
F_5 ( 0x80000001 , F_3 ( V_2 , V_37 ) ) ;
F_5 ( 0x00000000 , F_3 ( V_2 , V_149 ) ) ;
F_5 ( 0xffffffff , F_3 ( V_2 , V_233 ) ) ;
F_5 ( 0x00000000 , F_3 ( V_2 , V_234 ) ) ;
F_35 ( 0x10 , F_3 ( V_2 , V_235 ) ) ;
V_2 -> V_236 = F_14 ( V_2 , 0 , V_237 ) ;
V_2 -> V_238 = F_14 ( V_2 , 0 ,
V_239 ) ;
if ( V_2 -> V_54 ) {
F_42 ( V_2 ) ;
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
static void F_134 ( struct V_244 * V_245 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = V_245 -> V_24 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < 256 ; V_113 += 4 )
F_135 ( V_247 , L_43 , V_113 , F_2 ( F_3 ( V_2 , V_113 ) ) ) ;
}
static void T_6 F_136 ( struct V_1 * V_2 )
{
struct V_244 * V_245 ;
if ( ! F_137 ( V_2 -> V_187 , L_44 , & V_245 ) )
F_138 ( V_245 , V_2 , F_134 ) ;
}
static int T_6 F_139 ( struct V_1 * V_2 )
{
int V_153 ;
F_16 ( L_45 ) ;
V_153 = F_140 ( V_2 -> V_34 , L_46 ) ;
if ( V_153 < 0 )
return V_153 ;
V_2 -> V_3 = F_141 ( V_2 -> V_34 , 0 ) ;
if ( F_142 ( V_2 -> V_34 -> V_96 , F_53 ,
V_248 , V_249 , V_2 ) ) {
F_12 ( V_12 L_47 ) ;
return - V_250 ;
}
V_2 -> V_96 = V_2 -> V_34 -> V_96 ;
F_16 ( L_48 ) ;
return 0 ;
}
static int F_143 ( struct V_251 * V_184 )
{
struct V_1 * V_2 = V_184 -> V_252 ;
F_127 ( V_2 ) ;
return 0 ;
}
static int T_6 F_144 ( struct V_219 * V_187 ,
struct V_30 * V_34 ,
int V_253 ,
int V_54 ,
struct V_1 * * V_254 )
{
struct V_1 * V_2 ;
int V_113 , V_153 ;
unsigned short V_255 ;
static struct V_256 V_213 = {
. V_257 = F_143 ,
} ;
* V_254 = NULL ;
F_16 ( L_49 ) ;
V_153 = F_123 ( V_34 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( F_145 ( V_34 , F_146 ( 31 ) ) < 0 ||
F_147 ( V_34 , F_146 ( 31 ) ) < 0 ) {
F_12 ( V_12 L_50
L_51 ) ;
F_118 ( V_34 ) ;
return - V_258 ;
}
V_2 = F_148 ( sizeof( * V_2 ) , V_259 ) ;
if ( ! V_2 ) {
F_118 ( V_34 ) ;
return - V_154 ;
}
F_149 ( & V_2 -> V_89 ) ;
F_149 ( & V_2 -> V_107 ) ;
V_2 -> V_187 = V_187 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_96 = - 1 ;
V_2 -> V_19 = V_34 -> V_19 ;
V_2 -> V_54 = V_54 ;
if ( V_253 < 1 )
V_253 = 1 ;
if ( V_253 > 32 )
V_253 = 32 ;
F_125 ( V_34 ) ;
F_150 ( V_34 , V_260 , & V_255 ) ;
if ( ( V_255 & V_261 ) != V_261 ) {
V_255 |= V_261 ;
F_151 ( V_34 , V_260 , V_255 ) ;
}
F_125 ( V_34 ) ;
if ( F_139 ( V_2 ) ) {
F_127 ( V_2 ) ;
return - V_250 ;
}
F_152 ( V_34 -> V_96 ) ;
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
V_2 -> V_16 . V_17 . V_86 = V_233 ;
V_2 -> V_16 . V_17 . V_46 = V_149 ;
V_2 -> V_16 . V_45 . V_265 = 0x00 ;
V_2 -> V_16 . V_45 . V_60 = 0x00 ;
V_2 -> V_16 . V_45 . V_86 = 0x00 ;
V_2 -> V_16 . V_45 . V_46 = 0x00 ;
V_2 -> V_33 = F_153 ( 0x10b9 , 0x1533 , NULL ) ;
if ( ! V_2 -> V_33 ) {
F_12 ( V_12 L_52 ) ;
F_127 ( V_2 ) ;
return - V_266 ;
}
V_2 -> V_231 = F_153 ( 0x10b9 , 0x7101 , NULL ) ;
if ( ! V_2 -> V_231 && V_2 -> V_19 == V_20 ) {
F_12 ( V_12 L_53 ) ;
F_127 ( V_2 ) ;
return - V_266 ;
}
F_16 ( L_54 ) ;
V_153 = F_154 ( V_187 , V_267 , V_2 , & V_213 ) ;
if ( V_153 < 0 ) {
F_127 ( V_2 ) ;
return V_153 ;
}
F_155 ( V_187 , & V_34 -> V_218 ) ;
for ( V_113 = 0 ; V_113 < V_50 ; V_113 ++ )
V_2 -> V_48 . V_87 [ V_113 ] . V_91 = V_113 ;
V_153 = F_133 ( V_2 ) ;
if ( V_153 < 0 ) {
F_12 ( V_12 L_55 ) ;
return V_153 ;
}
#ifdef F_130
V_2 -> V_223 = F_156 ( sizeof( * V_2 -> V_223 ) , V_259 ) ;
if ( ! V_2 -> V_223 )
F_12 ( V_163 L_56 ) ;
#endif
F_24 ( V_2 ) ;
V_2 -> V_99 = 1 ;
* V_254 = V_2 ;
F_16 ( L_57 ) ;
return 0 ;
}
static int T_6 F_157 ( struct V_30 * V_34 ,
const struct V_268 * V_269 )
{
struct V_219 * V_187 ;
struct V_1 * V_2 ;
int V_153 ;
F_16 ( L_58 ) ;
V_153 = F_158 ( V_270 , V_271 , V_272 , 0 , & V_187 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_144 ( V_187 , V_34 , V_273 , V_274 , & V_2 ) ;
if ( V_153 < 0 )
goto error;
V_187 -> V_24 = V_2 ;
F_16 ( L_59 ) ;
V_153 = F_107 ( V_2 ) ;
if ( V_153 < 0 )
goto error;
F_16 ( L_60 ) ;
V_153 = F_104 ( V_2 ) ;
if ( V_153 < 0 )
goto error;
F_136 ( V_2 ) ;
strcpy ( V_187 -> V_275 , L_61 ) ;
strcpy ( V_187 -> V_276 , L_46 ) ;
sprintf ( V_187 -> V_277 , L_62 ,
V_187 -> V_276 , V_2 -> V_3 , V_2 -> V_96 ) ;
F_16 ( L_63 ) ;
V_153 = F_159 ( V_187 ) ;
if ( V_153 < 0 )
goto error;
F_160 ( V_34 , V_187 ) ;
return 0 ;
error:
F_161 ( V_187 ) ;
return V_153 ;
}
static void T_7 F_162 ( struct V_30 * V_34 )
{
F_161 ( F_163 ( V_34 ) ) ;
F_160 ( V_34 , NULL ) ;
}
