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
F_10 ( V_2 -> V_8 -> V_9 , L_1 ) ;
return - V_10 ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
unsigned long V_11 , V_12 ;
V_11 = F_1 ( V_2 , V_13 ) ;
V_5 = V_7 + F_7 ( 250 ) ;
for (; ; ) {
V_12 = F_1 ( V_2 , V_13 ) ;
if ( V_12 != V_11 )
return 0 ;
if ( ! F_8 ( V_5 , V_7 ) )
break;
F_9 ( 1 ) ;
}
F_12 ( V_2 -> V_8 -> V_9 , L_2 ) ;
return - V_10 ;
}
static void F_13 ( struct V_1 * V_2 , int V_14 ,
unsigned short V_15 ,
unsigned short V_4 )
{
unsigned int V_16 ;
unsigned int V_3 ;
if ( V_15 >= 0x80 ) {
F_12 ( V_2 -> V_8 -> V_9 ,
L_3 , V_15 ) ;
return;
}
V_3 = V_2 -> V_17 . V_18 . V_19 ;
if ( F_6 ( V_2 , V_3 ) < 0 )
return;
if ( F_11 ( V_2 ) < 0 )
return;
V_16 = ( unsigned int ) ( V_15 & 0xff ) ;
V_16 |= 0x8000 | ( V_4 << 16 ) ;
if ( V_14 )
V_16 |= 0x0080 ;
if ( V_2 -> V_20 == V_21 )
V_16 |= 0x0100 ;
F_4 ( V_2 , V_3 , V_16 ) ;
return ;
}
static unsigned short F_14 ( struct V_1 * V_2 ,
int V_14 ,
unsigned short V_15 )
{
unsigned int V_16 ;
unsigned int V_3 ;
if ( V_15 >= 0x80 ) {
F_12 ( V_2 -> V_8 -> V_9 ,
L_4 , V_15 ) ;
return ~ 0 ;
}
V_3 = V_2 -> V_17 . V_18 . V_22 ;
if ( F_6 ( V_2 , V_3 ) < 0 )
return ~ 0 ;
if ( F_11 ( V_2 ) < 0 )
return ~ 0 ;
V_16 = ( unsigned int ) ( V_15 & 0xff ) ;
V_16 |= 0x8000 ;
if ( V_14 )
V_16 |= 0x0080 ;
F_4 ( V_2 , V_3 , V_16 ) ;
if ( F_11 ( V_2 ) < 0 )
return ~ 0 ;
if ( F_6 ( V_2 , V_3 ) < 0 )
return ~ 0 ;
return ( F_1 ( V_2 , V_3 ) & 0xffff0000 ) >> 16 ;
}
static void F_15 ( struct V_23 * V_24 ,
unsigned short V_15 ,
unsigned short V_4 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
F_10 ( V_2 -> V_8 -> V_9 , L_5 , V_15 , V_4 ) ;
if ( V_15 == V_26 ) {
F_5 ( ( V_4 << V_27 ) | V_28 ,
F_3 ( V_2 , V_29 ) ) ;
return;
}
F_13 ( V_2 , V_24 -> V_30 , V_15 , V_4 ) ;
return ;
}
static unsigned short F_16 ( struct V_23 * V_24 ,
unsigned short V_15 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
F_10 ( V_2 -> V_8 -> V_9 , L_6 , V_15 ) ;
return F_14 ( V_2 , V_24 -> V_30 , V_15 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_31 * V_31 ;
unsigned short V_32 , V_33 ;
unsigned int V_16 ;
V_31 = V_2 -> V_34 ;
if ( V_31 ) {
F_18 ( V_31 , 0x7c , & V_16 ) ;
F_19 ( V_31 , 0x7c , V_16 | 0x08000000 ) ;
F_20 ( 5 ) ;
F_18 ( V_31 , 0x7c , & V_16 ) ;
F_19 ( V_31 , 0x7c , V_16 & 0xf7ffffff ) ;
F_20 ( 5 ) ;
}
V_31 = V_2 -> V_35 ;
F_18 ( V_31 , 0x44 , & V_16 ) ;
F_19 ( V_31 , 0x44 , V_16 | 0x000c0000 ) ;
F_21 ( 500 ) ;
F_18 ( V_31 , 0x44 , & V_16 ) ;
F_19 ( V_31 , 0x44 , V_16 & 0xfffbffff ) ;
F_20 ( 5 ) ;
V_32 = 200 ;
while( V_32 -- ) {
V_33 = F_14 ( V_2 , 0 , V_36 ) ;
if ( ( V_33 & 0x000f ) == 0x000f )
return 0 ;
F_20 ( 5 ) ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned int V_37 )
{
unsigned long V_16 ;
V_16 = F_2 ( F_3 ( V_2 , V_38 ) ) ;
V_16 |= 1 << ( V_37 & 0x0000001f ) ;
F_5 ( V_16 , F_3 ( V_2 , V_38 ) ) ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_37 )
{
unsigned long V_16 ;
V_16 = F_2 ( F_3 ( V_2 , V_38 ) ) ;
V_16 &= ~ ( 1 << ( V_37 & 0x0000001f ) ) ;
F_5 ( V_16 , F_3 ( V_2 , V_38 ) ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned int V_39 ;
V_39 = F_2 ( F_3 ( V_2 , V_40 ) ) ;
V_39 |= V_41 ;
V_39 |= V_42 ;
F_5 ( V_39 , F_3 ( V_2 , V_40 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_39 ;
V_39 = F_2 ( F_3 ( V_2 , V_40 ) ) ;
V_39 &= ~ V_41 ;
V_39 &= ~ V_42 ;
F_5 ( V_39 , F_3 ( V_2 , V_40 ) ) ;
}
static void F_26 ( struct V_1 * V_2 ,
unsigned int V_37 )
{
unsigned int V_43 ;
struct V_44 * V_45 = & ( V_2 -> V_17 ) ;
F_10 ( V_2 -> V_8 -> V_9 , L_7 , V_37 ) ;
V_43 = 1 << ( V_37 & 0x1f ) ;
V_45 -> V_46 . V_47 = F_2 ( F_3 ( V_2 , V_45 -> V_18 . V_47 ) ) ;
V_45 -> V_46 . V_47 &= ~ V_43 ;
F_5 ( V_45 -> V_46 . V_47 , F_3 ( V_2 , V_45 -> V_18 . V_47 ) ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_37 )
{
unsigned int V_48 = V_37 & 0x1f ;
if ( V_2 -> V_49 . V_50 >= V_51 ) {
F_12 ( V_2 -> V_8 -> V_9 ,
L_8 ) ;
return - 1 ;
}
if ( ! ( V_2 -> V_49 . V_52 & ( 1 << V_48 ) ) ) {
V_2 -> V_49 . V_52 |= 1 << V_48 ;
V_2 -> V_49 . V_50 ++ ;
F_10 ( V_2 -> V_8 -> V_9 , L_9 , V_48 ) ;
return V_48 ;
}
return - 1 ;
}
static int F_28 ( struct V_1 * V_2 , int V_53 )
{
int V_48 ;
int V_54 = - 1 ;
F_10 ( V_2 -> V_8 -> V_9 ,
L_10 , V_53 ? L_11 : L_12 ) ;
if ( V_53 ) {
if ( V_2 -> V_55 &&
( F_2 ( F_3 ( V_2 , V_38 ) ) &
V_56 ) )
V_48 = V_57 ;
else
V_48 = V_58 ;
V_54 = F_27 ( V_2 , V_48 ) ;
if ( V_54 >= 0 )
return V_54 ;
else {
F_12 ( V_2 -> V_8 -> V_9 ,
L_13 ) ;
return - 1 ;
}
}
if ( V_2 -> V_55 &&
( F_2 ( F_3 ( V_2 , V_38 ) ) &
V_59 ) ) {
V_48 = V_60 ;
V_54 = F_27 ( V_2 , V_48 ) ;
if ( V_54 >= 0 )
return V_54 ;
else
F_12 ( V_2 -> V_8 -> V_9 ,
L_14 ) ;
}
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ ) {
V_54 = F_27 ( V_2 , V_48 ) ;
if ( V_54 >= 0 )
return V_54 ;
}
F_12 ( V_2 -> V_8 -> V_9 , L_15 ) ;
return - 1 ;
}
static void F_29 ( struct V_1 * V_2 , int V_37 )
{
unsigned int V_48 = V_37 & 0x0000001f ;
F_10 ( V_2 -> V_8 -> V_9 , L_16 , V_37 ) ;
if ( V_37 < 0 || V_37 >= V_51 )
return;
if ( ! ( V_2 -> V_49 . V_52 & ( 1 << V_48 ) ) ) {
F_12 ( V_2 -> V_8 -> V_9 ,
L_17 ,
V_37 ) ;
return;
} else {
V_2 -> V_49 . V_52 &= ~ ( 1 << V_48 ) ;
V_2 -> V_49 . V_50 -- ;
}
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_37 )
{
unsigned int V_43 = 1 << ( V_37 & 0x1f ) ;
F_10 ( V_2 -> V_8 -> V_9 , L_18 , V_37 ) ;
F_5 ( V_43 , F_3 ( V_2 , V_2 -> V_17 . V_18 . V_61 ) ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_62 )
{
unsigned long V_63 , V_64 ;
V_63 = F_2 ( F_3 ( V_2 , V_13 ) ) ;
V_64 = F_2 ( F_3 ( V_2 , V_13 ) ) ;
while ( V_64 < V_63 + V_62 ) {
if ( F_11 ( V_2 ) < 0 )
break;
V_64 = F_2 ( F_3 ( V_2 , V_13 ) ) ;
F_32 () ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_65 ;
T_1 V_66 = 0 ;
T_2 V_67 , V_68 = 0 , V_69 ;
V_67 = F_34 ( F_3 ( V_2 , V_70 + 1 ) ) ;
V_67 |= 0x1F ;
F_35 ( V_67 , F_3 ( V_2 , V_70 + 1 ) ) ;
while ( ( V_68 < 0x0b || V_68 > 0x0e ) && V_68 != 0x12 && V_66 <= 50000 ) {
V_66 ++ ;
F_31 ( V_2 , 6 ) ;
V_67 = F_34 ( F_3 ( V_2 , V_70 + 1 ) ) ;
V_68 = V_67 & 0x1F ;
}
if ( V_66 > 50000 ) {
F_12 ( V_2 -> V_8 -> V_9 , L_19 ) ;
return;
}
for ( V_66 = 0 ; V_66 <= 50000 ; V_66 ++ ) {
F_31 ( V_2 , 6 ) ;
V_67 = F_34 ( F_3 ( V_2 , V_70 + 1 ) ) ;
V_69 = V_67 & 0x1F ;
if ( V_69 != V_68 )
V_68 = V_69 ;
else
break;
}
if ( V_66 > 50000 ) {
F_12 ( V_2 -> V_8 -> V_9 , L_19 ) ;
return;
}
if ( V_69 >= 0x0b && V_69 <= 0x0e ) {
V_65 = F_36 ( F_3 ( V_2 , V_70 + 2 ) ) ;
V_65 &= 0xe0f0 ;
V_65 |= ( 0x09 << 8 ) | 0x05 ;
F_37 ( V_65 , F_3 ( V_2 , V_70 + 2 ) ) ;
V_67 = F_34 ( F_3 ( V_2 , V_71 + 3 ) ) & 0xf0 ;
F_35 ( V_67 | 0x02 , F_3 ( V_2 , V_71 + 3 ) ) ;
} else if ( V_69 == 0x12 ) {
V_65 = F_36 ( F_3 ( V_2 , V_70 + 2 ) ) ;
V_65 &= 0xe0f0 ;
V_65 |= ( 0x0e << 8 ) | 0x08 ;
F_37 ( V_65 , F_3 ( V_2 , V_70 + 2 ) ) ;
V_67 = F_34 ( F_3 ( V_2 , V_71 + 3 ) ) & 0xf0 ;
F_35 ( V_67 | 0x03 , F_3 ( V_2 , V_71 + 3 ) ) ;
}
}
static unsigned int F_38 ( struct V_1 * V_2 )
{
T_3 V_72 ;
T_2 V_67 ;
V_67 = F_34 ( F_3 ( V_2 , V_70 ) ) ;
V_67 &= 0x7f ;
V_67 |= 0x40 ;
F_35 ( V_67 , F_3 ( V_2 , V_70 ) ) ;
F_33 ( V_2 ) ;
V_67 = F_34 ( F_3 ( V_2 , V_71 + 3 ) ) ;
V_67 &= 0x0f ;
switch ( V_67 ) {
case 0 : V_72 = 44100 ; break;
case 1 : V_72 = 48000 ; break;
case 2 : V_72 = 32000 ; break;
default: V_72 = 0 ; break;
}
return V_72 ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned int V_16 ;
V_16 = F_2 ( F_3 ( V_2 , V_38 ) ) ;
V_16 |= V_56 ;
F_5 ( V_16 , F_3 ( V_2 , V_38 ) ) ;
V_16 = F_34 ( F_3 ( V_2 , V_70 ) ) ;
V_16 |= 0x02 ;
F_35 ( V_16 , F_3 ( V_2 , V_70 ) ) ;
F_22 ( V_2 , V_57 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_16 ;
V_16 = F_2 ( F_3 ( V_2 , V_38 ) ) ;
V_16 &= ~ V_56 ;
F_5 ( V_16 , F_3 ( V_2 , V_38 ) ) ;
F_23 ( V_2 , V_57 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_73 )
{
unsigned char V_74 ;
unsigned int V_72 ;
switch ( V_73 ) {
case 32000 : V_72 = 0x300 ; break;
case 48000 : V_72 = 0x200 ; break;
default: V_72 = 0 ; break;
}
V_74 = F_34 ( F_3 ( V_2 , V_70 ) ) ;
V_74 &= ( unsigned char ) ( ~ ( 1 << 6 ) ) ;
V_74 |= 0x80 ;
F_35 ( V_74 , F_3 ( V_2 , V_70 ) ) ;
F_35 ( V_72 | 0x20 , F_3 ( V_2 , V_71 + 2 ) ) ;
V_74 &= ~ 0x80 ;
F_35 ( V_74 , F_3 ( V_2 , V_70 ) ) ;
F_37 ( V_73 | 0x10 , F_3 ( V_2 , V_71 + 2 ) ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned short V_75 ;
unsigned char V_74 ;
struct V_31 * V_31 ;
V_31 = V_2 -> V_34 ;
if ( V_31 == NULL )
return;
F_43 ( V_31 , 0x61 , & V_74 ) ;
V_74 |= 0x40 ;
F_44 ( V_31 , 0x61 , V_74 ) ;
F_43 ( V_31 , 0x7d , & V_74 ) ;
V_74 |= 0x01 ;
F_44 ( V_31 , 0x7d , V_74 ) ;
F_43 ( V_31 , 0x7e , & V_74 ) ;
V_74 &= ( ~ 0x20 ) ;
V_74 |= 0x10 ;
F_44 ( V_31 , 0x7e , V_74 ) ;
V_74 = F_34 ( F_3 ( V_2 , V_76 ) ) ;
F_35 ( V_74 | V_77 , F_3 ( V_2 , V_76 ) ) ;
V_74 = F_34 ( F_3 ( V_2 , V_70 ) ) ;
F_35 ( V_74 & V_78 , F_3 ( V_2 , V_70 ) ) ;
V_75 = F_36 ( F_3 ( V_2 , V_38 ) ) ;
V_75 |= V_79 ;
F_37 ( V_75 , F_3 ( V_2 , V_38 ) ) ;
F_23 ( V_2 , V_60 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned short V_75 ;
V_75 = F_36 ( F_3 ( V_2 , V_38 ) ) ;
V_75 &= ~ V_79 ;
F_37 ( V_75 , F_3 ( V_2 , V_38 ) ) ;
F_22 ( V_2 , V_60 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
unsigned short V_75 ;
V_75 = F_36 ( F_3 ( V_2 , V_38 ) ) ;
V_75 |= V_79 ;
F_37 ( V_75 , F_3 ( V_2 , V_38 ) ) ;
F_22 ( V_2 , V_60 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned char V_74 ;
V_74 = F_34 ( F_3 ( V_2 , V_76 ) ) ;
F_35 ( V_74 & ~ V_77 , F_3 ( V_2 , V_76 ) ) ;
F_46 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_37 )
{
struct V_80 * V_81 ;
struct V_44 * V_45 ;
unsigned int V_82 , V_43 ;
V_45 = & ( V_2 -> V_17 ) ;
V_82 = V_45 -> V_46 . V_83 ;
V_43 = 1U << ( V_37 & 0x1f ) ;
if ( ! ( V_82 & V_43 ) )
return;
V_81 = & V_2 -> V_49 . V_84 [ V_37 ] ;
F_21 ( 100 ) ;
F_49 ( & V_2 -> V_85 ) ;
if ( V_81 -> V_86 && V_81 -> V_87 ) {
if ( V_81 -> V_88 ) {
F_10 ( V_2 -> V_8 -> V_9 ,
L_20 ,
F_36 ( F_3 ( V_2 , V_89 + 2 ) ) ,
( F_2 ( F_3 ( V_2 , V_90 ) ) & V_43 ) == V_43 ) ;
F_50 ( & V_2 -> V_85 ) ;
F_51 ( V_81 -> V_87 ) ;
F_49 ( & V_2 -> V_85 ) ;
} else {
F_30 ( V_2 , V_37 ) ;
F_26 ( V_2 , V_37 ) ;
}
} else if ( V_2 -> V_49 . V_84 [ V_37 ] . V_49 ) {
} else if ( V_2 -> V_49 . V_84 [ V_37 ] . V_91 ) {
} else {
F_30 ( V_2 , V_37 ) ;
F_26 ( V_2 , V_37 ) ;
}
F_50 ( & V_2 -> V_85 ) ;
F_5 ( V_43 , F_3 ( V_2 , V_45 -> V_18 . V_83 ) ) ;
V_45 -> V_46 . V_83 = V_82 & ( ~ V_43 ) ;
}
static T_4 F_52 ( int V_92 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
int V_37 ;
unsigned int V_94 ;
struct V_44 * V_45 ;
if ( V_2 == NULL || ! V_2 -> V_95 )
return V_96 ;
V_94 = F_2 ( F_3 ( V_2 , V_97 ) ) ;
if ( ! V_94 )
return V_96 ;
V_45 = & ( V_2 -> V_17 ) ;
if ( V_94 & V_98 ) {
V_45 -> V_46 . V_83 = F_2 ( F_3 ( V_2 , V_45 -> V_18 . V_83 ) ) ;
for ( V_37 = 0 ; V_37 < V_51 ; V_37 ++ )
F_48 ( V_2 , V_37 ) ;
}
F_5 ( ( V_99 | V_100 | V_101 ) ,
F_3 ( V_2 , V_97 ) ) ;
return V_102 ;
}
static struct V_80 * F_53 ( struct V_1 * V_2 ,
int type , int V_53 , int V_37 )
{
struct V_80 * V_81 ;
int V_48 ;
F_10 ( V_2 -> V_8 -> V_9 , L_21 , type , V_53 ) ;
F_54 ( & V_2 -> V_103 ) ;
if ( type == V_104 ) {
V_48 = V_37 > 0 ? F_27 ( V_2 , V_37 ) :
F_28 ( V_2 , V_53 ) ;
if ( V_48 < 0 ) {
F_12 ( V_2 -> V_8 -> V_9 , L_22 ) ;
F_55 ( & V_2 -> V_103 ) ;
return NULL ;
}
V_81 = & ( V_2 -> V_49 . V_84 [ V_48 ] ) ;
V_81 -> V_2 = V_2 ;
V_81 -> V_105 = 1 ;
V_81 -> V_86 = 1 ;
V_81 -> V_106 = V_53 ;
F_55 ( & V_2 -> V_103 ) ;
return V_81 ;
}
F_55 ( & V_2 -> V_103 ) ;
return NULL ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
void (* F_57)( void * );
void * V_25 ;
F_10 ( V_2 -> V_8 -> V_9 , L_23 , V_81 -> V_107 ) ;
if ( ! V_81 -> V_105 )
return;
F_58 ( V_2 , V_81 -> V_107 , V_81 -> V_107 ) ;
F_54 ( & V_2 -> V_103 ) ;
F_57 = V_81 -> F_57 ;
V_25 = V_81 -> V_25 ;
V_81 -> F_57 = NULL ;
V_81 -> V_25 = NULL ;
if ( V_81 -> V_86 )
F_29 ( V_2 , V_81 -> V_107 ) ;
V_81 -> V_105 = V_81 -> V_86 = V_81 -> V_49 = 0 ;
V_81 -> V_87 = NULL ;
F_55 ( & V_2 -> V_103 ) ;
if ( F_57 )
F_57 ( V_25 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
unsigned int V_108 ,
unsigned int V_109 )
{
unsigned int V_110 ;
for ( V_110 = V_108 ; V_110 <= V_109 ; V_110 ++ ) {
F_30 ( V_2 , V_110 ) ;
F_26 ( V_2 , V_110 ) ;
}
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_111 ,
unsigned int V_112 ,
unsigned int V_113 ,
unsigned int V_114 ,
unsigned int V_115 ,
unsigned int V_116 ,
unsigned int V_117 ,
unsigned int V_118 ,
unsigned int V_119 ,
unsigned int V_120 ,
unsigned int V_121 )
{
unsigned int V_122 [ 4 ] ;
F_35 ( ( unsigned char ) ( V_111 & 0x001f ) , F_3 ( V_2 , V_40 ) ) ;
V_122 [ 0 ] = ( V_113 << 16 ) | ( V_116 & 0x0000ffff ) ;
V_122 [ 1 ] = V_112 ;
V_122 [ 2 ] = ( V_114 << 16 ) | ( V_115 & 0x0ffff ) ;
V_122 [ 3 ] = ( V_117 << 31 ) |
( ( V_118 & 0x0000007f ) << 24 ) |
( ( V_119 & 0x000000ff ) << 16 ) |
( ( V_120 & 0x0000000f ) << 12 ) |
( V_121 & 0x00000fff ) ;
F_35 ( V_111 , F_3 ( V_2 , V_40 ) ) ;
F_5 ( V_122 [ 0 ] , F_3 ( V_2 , V_89 ) ) ;
F_5 ( V_122 [ 1 ] , F_3 ( V_2 , V_123 ) ) ;
F_5 ( V_122 [ 2 ] , F_3 ( V_2 , V_124 ) ) ;
F_5 ( V_122 [ 3 ] , F_3 ( V_2 , V_125 ) ) ;
F_5 ( 0x30000000 , F_3 ( V_2 , V_126 ) ) ;
F_5 ( 0x30000000 , F_3 ( V_2 , V_127 ) ) ;
}
static unsigned int F_60 ( unsigned int V_73 , int V_53 )
{
unsigned int V_128 ;
if ( V_73 < 4000 )
V_73 = 4000 ;
if ( V_73 > 48000 )
V_73 = 48000 ;
if ( V_53 ) {
if ( V_73 == 44100 )
V_128 = 0x116a ;
else if ( V_73 == 8000 )
V_128 = 0x6000 ;
else if ( V_73 == 48000 )
V_128 = 0x1000 ;
else
V_128 = ( ( 48000 << 12 ) / V_73 ) & 0x0000ffff ;
} else {
if ( V_73 == 44100 )
V_128 = 0xeb3 ;
else if ( V_73 == 8000 )
V_128 = 0x2ab ;
else if ( V_73 == 48000 )
V_128 = 0x1000 ;
else
V_128 = ( ( ( V_73 << 12 ) + V_73 ) / 48000 ) & 0x0000ffff ;
}
return V_128 ;
}
static unsigned int F_61 ( struct V_129 * V_87 )
{
unsigned int V_120 ;
struct V_130 * V_131 = V_87 -> V_131 ;
V_120 = 0x00000001 ;
if ( F_62 ( V_131 -> V_132 ) == 16 )
V_120 |= 0x00000008 ;
if ( ! F_63 ( V_131 -> V_132 ) )
V_120 |= 0x00000002 ;
if ( V_131 -> V_133 > 1 )
V_120 |= 0x00000004 ;
return V_120 ;
}
static int F_64 ( struct V_129 * V_87 ,
int V_134 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_129 * V_135 ;
unsigned int V_136 , V_137 , V_138 ;
struct V_80 * V_81 , * V_139 ;
unsigned int V_4 ;
int V_140 ;
switch ( V_134 ) {
case V_141 :
case V_142 :
V_140 = 1 ;
break;
case V_143 :
case V_144 :
V_140 = 0 ;
break;
default:
return - V_145 ;
}
V_136 = V_137 = V_138 = 0 ;
F_66 (s, substream) {
if ( (struct V_1 * ) F_65 ( V_135 ) == V_2 ) {
V_81 = V_135 -> V_131 -> V_25 ;
V_139 = V_81 -> V_146 ;
V_136 |= 1 << ( V_81 -> V_107 & 0x1f ) ;
if ( V_139 == NULL )
V_137 |= 1 << ( V_81 -> V_107 & 0x1f ) ;
else {
V_137 |= 1 << ( V_139 -> V_107 & 0x1f ) ;
V_136 |= 1 << ( V_139 -> V_107 & 0x1f ) ;
}
if ( V_140 ) {
V_81 -> V_88 = 1 ;
if ( V_139 != NULL )
V_139 -> V_88 = 1 ;
} else {
V_81 -> V_88 = 0 ;
if ( V_139 != NULL )
V_139 -> V_88 = 0 ;
}
F_67 ( V_135 , V_87 ) ;
if ( V_81 -> V_106 )
V_138 = 1 ;
}
}
F_49 ( & V_2 -> V_85 ) ;
if ( ! V_140 )
F_5 ( V_136 , F_3 ( V_2 , V_147 ) ) ;
V_4 = F_2 ( F_3 ( V_2 , V_148 ) ) ;
if ( V_140 )
V_4 |= V_137 ;
else
V_4 &= ~ V_137 ;
F_5 ( V_4 , F_3 ( V_2 , V_148 ) ) ;
if ( V_140 )
F_5 ( V_136 , F_3 ( V_2 , V_149 ) ) ;
F_10 ( V_2 -> V_8 -> V_9 , L_24 , V_136 , V_137 ) ;
F_50 ( & V_2 -> V_85 ) ;
return 0 ;
}
static int F_68 ( struct V_129 * V_87 ,
struct V_150 * V_151 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_130 * V_131 = V_87 -> V_131 ;
struct V_80 * V_81 = V_131 -> V_25 ;
struct V_80 * V_139 = V_81 -> V_146 ;
int V_152 ;
V_152 = F_69 ( V_87 ,
F_70 ( V_151 ) ) ;
if ( V_152 < 0 )
return V_152 ;
if ( F_71 ( V_151 ) / 2 !=
F_72 ( V_151 ) ) {
if ( ! V_139 ) {
V_139 = F_53 ( V_2 ,
V_104 ,
0 , - 1 ) ;
if ( ! V_139 )
return - V_153 ;
V_81 -> V_146 = V_139 ;
V_139 -> V_87 = V_87 ;
}
} else {
if ( V_139 ) {
F_56 ( V_2 , V_139 ) ;
V_81 -> V_146 = V_139 = NULL ;
}
}
return 0 ;
}
static int F_73 ( struct V_129 * V_87 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_130 * V_131 = V_87 -> V_131 ;
struct V_80 * V_81 = V_131 -> V_25 ;
struct V_80 * V_139 = V_81 ? V_81 -> V_146 : NULL ;
F_74 ( V_87 ) ;
if ( V_139 ) {
F_56 ( V_2 , V_139 ) ;
V_81 -> V_146 = NULL ;
}
return 0 ;
}
static int F_75 ( struct V_129 * V_87 ,
struct V_150 * V_151 )
{
return F_69 ( V_87 ,
F_70 ( V_151 ) ) ;
}
static int F_76 ( struct V_129 * V_87 )
{
return F_74 ( V_87 ) ;
}
static int F_77 ( struct V_129 * V_87 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_130 * V_131 = V_87 -> V_131 ;
struct V_80 * V_81 = V_131 -> V_25 ;
struct V_80 * V_139 = V_81 -> V_146 ;
unsigned int V_112 ;
unsigned int V_154 ;
unsigned int V_114 ;
unsigned int V_120 ;
unsigned int V_117 ;
unsigned int V_118 ;
unsigned int V_119 ;
unsigned int V_121 ;
F_10 ( V_2 -> V_8 -> V_9 , L_25 ) ;
F_54 ( & V_2 -> V_85 ) ;
V_154 = F_60 ( V_131 -> V_73 , 0 ) ;
if ( V_81 -> V_107 == V_57 ||
V_81 -> V_107 == V_58 )
F_23 ( V_2 , V_81 -> V_107 ) ;
else if ( V_2 -> V_55 &&
( F_2 ( F_3 ( V_2 , V_38 ) ) &
V_59 )
&& V_81 -> V_107 == V_60 ) {
F_41 ( V_2 , V_131 -> V_73 ) ;
V_154 = 0x1000 ;
}
V_112 = V_131 -> V_155 ;
V_81 -> V_66 = V_131 -> V_156 ;
V_81 -> V_157 = V_131 -> V_158 ;
F_10 ( V_2 -> V_8 -> V_9 , L_26 ,
V_81 -> V_157 , V_81 -> V_66 ) ;
V_114 = V_81 -> V_157 - 1 ;
V_120 = F_61 ( V_87 ) ;
V_117 = 1 ;
V_118 = 0 ;
V_119 = 0 ;
V_121 = 0 ;
F_10 ( V_2 -> V_8 -> V_9 , L_27 ) ;
F_10 ( V_2 -> V_8 -> V_9 ,
L_28 ,
V_81 -> V_107 , V_131 -> V_73 , V_154 , V_117 , V_118 , V_120 ) ;
F_59 ( V_2 ,
V_81 -> V_107 ,
V_112 ,
0 ,
V_114 ,
V_154 ,
0 ,
V_117 ,
V_118 ,
V_119 ,
V_120 ,
V_121 ) ;
if ( V_139 ) {
V_139 -> V_66 = V_81 -> V_66 ;
V_139 -> V_157 = V_81 -> V_66 << 1 ;
V_114 = V_139 -> V_157 - 1 ;
F_59 ( V_2 ,
V_139 -> V_107 ,
V_112 ,
0 ,
V_114 ,
V_154 ,
0 ,
V_117 ,
0x7f ,
0x3ff ,
V_120 ,
V_121 ) ;
}
F_55 ( & V_2 -> V_85 ) ;
return 0 ;
}
static int F_78 ( struct V_129 * V_87 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_130 * V_131 = V_87 -> V_131 ;
struct V_80 * V_81 = V_131 -> V_25 ;
unsigned int V_112 ;
unsigned int V_154 ;
unsigned int V_114 ;
unsigned int V_120 ;
unsigned int V_117 ;
unsigned int V_118 ;
unsigned int V_119 ;
unsigned int V_121 ;
T_2 V_159 ;
F_54 ( & V_2 -> V_85 ) ;
F_10 ( V_2 -> V_8 -> V_9 , L_29 ) ;
F_22 ( V_2 , V_81 -> V_107 ) ;
V_154 = ( V_81 -> V_107 == V_160 ||
V_81 -> V_107 == V_161 ) ?
0x1000 : F_60 ( V_131 -> V_73 , V_81 -> V_106 ) ;
if ( V_81 -> V_107 == V_57 ) {
unsigned int V_73 ;
F_55 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_20 != V_21 )
return - 1 ;
V_73 = F_38 ( V_2 ) ;
if ( V_73 == 0 ) {
F_79 ( V_2 -> V_8 -> V_9 ,
L_30 ) ;
V_73 = 48000 ;
}
F_54 ( & V_2 -> V_85 ) ;
V_159 = F_34 ( F_3 ( V_2 , V_70 ) ) ;
if ( V_159 & 0x10 ) {
F_35 ( V_159 , F_3 ( V_2 , V_70 ) ) ;
F_79 ( V_2 -> V_8 -> V_9 ,
L_31 ) ;
}
if ( V_73 != 48000 )
V_154 = ( ( V_73 << 12 ) / V_131 -> V_73 ) & 0x00ffff ;
}
V_81 -> V_157 = V_131 -> V_158 ;
V_81 -> V_66 = V_131 -> V_156 ;
V_112 = V_131 -> V_155 ;
V_114 = V_81 -> V_157 - 1 ;
V_120 = F_61 ( V_87 ) ;
V_117 = 0 ;
V_118 = 0x00 ;
V_119 = 0x00 ;
V_121 = 0 ;
F_59 ( V_2 ,
V_81 -> V_107 ,
V_112 ,
0 ,
V_114 ,
V_154 ,
0 ,
V_117 ,
V_118 ,
V_119 ,
V_120 ,
V_121 ) ;
F_55 ( & V_2 -> V_85 ) ;
return 0 ;
}
static T_5
F_80 ( struct V_129 * V_87 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_130 * V_131 = V_87 -> V_131 ;
struct V_80 * V_81 = V_131 -> V_25 ;
unsigned int V_162 ;
F_49 ( & V_2 -> V_85 ) ;
if ( ! V_81 -> V_88 ) {
F_50 ( & V_2 -> V_85 ) ;
return 0 ;
}
F_35 ( V_81 -> V_107 , F_3 ( V_2 , V_40 ) ) ;
V_162 = F_36 ( F_3 ( V_2 , V_89 + 2 ) ) ;
F_50 ( & V_2 -> V_85 ) ;
F_10 ( V_2 -> V_8 -> V_9 , L_32 , V_162 ) ;
return V_162 ;
}
static T_5 F_81 ( struct V_129 * V_87 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_130 * V_131 = V_87 -> V_131 ;
struct V_80 * V_81 = V_131 -> V_25 ;
unsigned int V_162 ;
F_49 ( & V_2 -> V_85 ) ;
if ( ! V_81 -> V_88 ) {
F_50 ( & V_2 -> V_85 ) ;
return 0 ;
}
F_35 ( V_81 -> V_107 , F_3 ( V_2 , V_40 ) ) ;
V_162 = F_36 ( F_3 ( V_2 , V_89 + 2 ) ) ;
F_50 ( & V_2 -> V_85 ) ;
return V_162 ;
}
static void F_82 ( struct V_130 * V_131 )
{
struct V_80 * V_81 = V_131 -> V_25 ;
struct V_1 * V_2 ;
if ( V_81 ) {
V_2 = V_81 -> V_2 ;
F_56 ( V_81 -> V_2 , V_81 ) ;
}
}
static int F_83 ( struct V_129 * V_87 , int V_53 ,
int V_37 , struct V_163 * V_164 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_130 * V_131 = V_87 -> V_131 ;
struct V_80 * V_81 ;
V_81 = F_53 ( V_2 , V_104 , V_53 ,
V_37 ) ;
if ( ! V_81 )
return - V_165 ;
V_81 -> V_87 = V_87 ;
V_131 -> V_25 = V_81 ;
V_131 -> F_57 = F_82 ;
V_131 -> V_166 = * V_164 ;
F_84 ( V_87 ) ;
F_85 ( V_131 , V_167 ,
0 , 64 * 1024 ) ;
return 0 ;
}
static int F_86 ( struct V_129 * V_87 )
{
return F_83 ( V_87 , 0 , - 1 , & V_168 ) ;
}
static int F_87 ( struct V_129 * V_87 )
{
return F_83 ( V_87 , 1 , - 1 , & V_169 ) ;
}
static int F_88 ( struct V_129 * V_87 )
{
return 0 ;
}
static int F_89 ( struct V_129 * V_87 )
{
struct V_1 * V_2 = F_65 ( V_87 ) ;
struct V_80 * V_81 = V_87 -> V_131 -> V_25 ;
F_23 ( V_2 , V_81 -> V_107 ) ;
return 0 ;
}
static int F_90 ( struct V_129 * V_87 ,
struct V_150 * V_151 )
{
struct V_1 * V_170 = F_65 ( V_87 ) ;
unsigned int V_171 = V_170 -> V_172 - 1 ;
F_91 ( V_170 -> V_24 [ V_171 ] , V_173 ,
F_92 ( V_151 ) ) ;
F_91 ( V_170 -> V_24 [ V_171 ] , V_174 , 0 ) ;
return F_75 ( V_87 , V_151 ) ;
}
static int F_93 ( struct V_129 * V_87 , int V_53 ,
int V_37 )
{
static unsigned int V_175 [] = { 8000 , 9600 , 12000 , 16000 } ;
static struct V_176 V_177 = {
. V_66 = F_94 ( V_175 ) ,
. V_178 = V_175 ,
. V_43 = 0 ,
} ;
int V_152 = F_83 ( V_87 , V_53 , V_37 , & V_179 ) ;
if ( V_152 )
return V_152 ;
return V_176 ( V_87 -> V_131 , 0 ,
V_180 , & V_177 ) ;
}
static int F_95 ( struct V_129 * V_87 )
{
return F_93 ( V_87 , 0 , V_161 ) ;
}
static int F_96 ( struct V_129 * V_87 )
{
return F_93 ( V_87 , 1 , V_160 ) ;
}
static void F_97 ( struct V_181 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_25 ;
V_2 -> V_86 [ V_86 -> V_182 ] = NULL ;
}
static int F_98 ( struct V_1 * V_2 , int V_182 ,
struct V_183 * V_184 )
{
struct V_181 * V_86 ;
int V_152 ;
V_152 = F_99 ( V_2 -> V_8 , V_184 -> V_185 , V_182 ,
V_184 -> V_186 , V_184 -> V_187 , & V_86 ) ;
if ( V_152 < 0 ) {
F_12 ( V_2 -> V_8 -> V_9 ,
L_33 ) ;
return V_152 ;
}
V_86 -> V_25 = V_2 ;
V_86 -> F_57 = F_97 ;
if ( V_184 -> V_188 )
F_100 ( V_86 , V_189 ,
V_184 -> V_188 ) ;
if ( V_184 -> V_190 )
F_100 ( V_86 , V_191 ,
V_184 -> V_190 ) ;
F_101 ( V_86 , V_192 ,
F_102 ( V_2 -> V_35 ) ,
64 * 1024 , 128 * 1024 ) ;
V_86 -> V_193 = 0 ;
V_86 -> V_194 = V_184 -> V_195 ;
V_86 -> V_196 = V_197 ;
strcpy ( V_86 -> V_185 , V_184 -> V_185 ) ;
V_2 -> V_86 [ 0 ] = V_86 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_110 , V_152 ;
for ( V_110 = 0 ; V_110 < V_2 -> V_172 && V_110 < F_94 ( V_198 ) ; V_110 ++ ) {
V_152 = F_98 ( V_2 , V_110 , & V_198 [ V_110 ] ) ;
if ( V_152 < 0 )
return V_152 ;
}
return 0 ;
}
static int F_104 ( struct V_199 * V_200 ,
struct V_201 * V_202 )
{
struct V_1 * V_2 = V_200 -> V_25 ;
unsigned int V_203 ;
V_203 = V_202 -> V_204 . integer . V_204 [ 0 ] ? 1 : 0 ;
F_54 ( & V_2 -> V_85 ) ;
switch ( V_200 -> V_205 ) {
case 0 :
V_203 = ( V_2 -> V_206 & 0x02 ) ? 1 : 0 ;
break;
case 1 :
V_203 = ( ( V_2 -> V_206 & 0x02 ) &&
( V_2 -> V_206 & 0x04 ) ) ? 1 : 0 ;
break;
case 2 :
V_203 = ( V_2 -> V_206 & 0x01 ) ? 1 : 0 ;
break;
default:
break;
}
V_202 -> V_204 . integer . V_204 [ 0 ] = V_203 ;
F_55 ( & V_2 -> V_85 ) ;
return 0 ;
}
static int F_105 ( struct V_199 * V_200 ,
struct V_201 * V_202 )
{
struct V_1 * V_2 = V_200 -> V_25 ;
unsigned int V_207 = 0 , V_203 = 0 ;
V_203 = V_202 -> V_204 . integer . V_204 [ 0 ] ? 1 : 0 ;
F_54 ( & V_2 -> V_85 ) ;
switch ( V_200 -> V_205 ) {
case 0 :
V_207 = ( V_2 -> V_206 & 0x02 ) ? 1 : 0 ;
V_207 = V_207 ^ V_203 ;
if ( V_207 ) {
if ( V_203 ) {
V_2 -> V_206 |= 0x02 ;
F_42 ( V_2 ) ;
} else {
V_2 -> V_206 &= ~ ( 0x02 ) ;
V_2 -> V_206 &= ~ ( 0x04 ) ;
F_47 ( V_2 ) ;
}
}
break;
case 1 :
V_207 = ( V_2 -> V_206 & 0x04 ) ? 1 : 0 ;
V_207 = V_207 ^ V_203 ;
if ( V_207 && ( V_2 -> V_206 & 0x02 ) ) {
if ( V_203 ) {
V_2 -> V_206 |= 0x04 ;
F_45 ( V_2 ) ;
} else {
V_2 -> V_206 &= ~ ( 0x04 ) ;
F_46 ( V_2 ) ;
}
}
break;
case 2 :
V_207 = ( V_2 -> V_206 & 0x01 ) ? 1 : 0 ;
V_207 = V_207 ^ V_203 ;
if ( V_207 ) {
if ( V_203 ) {
V_2 -> V_206 |= 0x01 ;
F_39 ( V_2 ) ;
} else {
V_2 -> V_206 &= ~ ( 0x01 ) ;
F_40 ( V_2 ) ;
}
}
break;
default:
break;
}
F_55 ( & V_2 -> V_85 ) ;
return V_207 ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_208 V_24 ;
unsigned int V_48 ;
int V_110 , V_152 ;
static struct V_209 V_210 = {
. V_211 = F_15 ,
. V_212 = F_16 ,
} ;
V_152 = F_107 ( V_2 -> V_8 , 0 , & V_210 , V_2 , & V_2 -> V_213 ) ;
if ( V_152 < 0 )
return V_152 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_25 = V_2 ;
for ( V_110 = 0 ; V_110 < V_2 -> V_172 ; V_110 ++ ) {
V_24 . V_30 = V_110 ;
V_152 = F_108 ( V_2 -> V_213 , & V_24 , & V_2 -> V_24 [ V_110 ] ) ;
if ( V_152 < 0 ) {
F_12 ( V_2 -> V_8 -> V_9 ,
L_34 , V_110 ) ;
if ( V_110 == 0 )
return V_152 ;
V_2 -> V_172 = 1 ;
break;
}
}
if ( V_2 -> V_55 ) {
for ( V_48 = 0 ; V_48 < F_94 ( V_214 ) ; V_48 ++ ) {
V_152 = F_109 ( V_2 -> V_8 ,
F_110 ( & V_214 [ V_48 ] , V_2 ) ) ;
if ( V_152 < 0 )
return V_152 ;
}
}
return 0 ;
}
static int F_111 ( struct V_182 * V_9 )
{
struct V_31 * V_35 = F_112 ( V_9 ) ;
struct V_215 * V_8 = F_113 ( V_9 ) ;
struct V_1 * V_170 = V_8 -> V_25 ;
struct V_216 * V_217 ;
int V_110 , V_218 ;
V_217 = V_170 -> V_219 ;
if ( ! V_217 )
return 0 ;
F_114 ( V_8 , V_220 ) ;
for ( V_110 = 0 ; V_110 < V_170 -> V_172 ; V_110 ++ ) {
F_115 ( V_170 -> V_86 [ V_110 ] ) ;
F_116 ( V_170 -> V_24 [ V_110 ] ) ;
}
F_54 ( & V_170 -> V_85 ) ;
V_217 -> V_18 [ V_97 >> 2 ] = F_2 ( F_3 ( V_170 , V_97 ) ) ;
V_217 -> V_18 [ V_147 >> 2 ] = F_2 ( F_3 ( V_170 , V_147 ) ) ;
F_5 ( 0 , F_3 ( V_170 , V_97 ) ) ;
for ( V_110 = 0 ; V_110 < V_221 ; V_110 ++ ) {
if ( ( V_110 * 4 == V_97 ) || ( V_110 * 4 == V_147 ) )
continue;
V_217 -> V_18 [ V_110 ] = F_2 ( F_3 ( V_170 , V_110 * 4 ) ) ;
}
for ( V_110 = 0 ; V_110 < V_51 ; V_110 ++ ) {
F_35 ( V_110 , F_3 ( V_170 , V_40 ) ) ;
for ( V_218 = 0 ; V_218 < V_222 ; V_218 ++ )
V_217 -> V_223 [ V_110 ] [ V_218 ] = F_2 ( F_3 ( V_170 , V_218 * 4 + 0xe0 ) ) ;
}
F_5 ( 0xffffffff , F_3 ( V_170 , V_147 ) ) ;
F_55 ( & V_170 -> V_85 ) ;
F_117 ( V_35 ) ;
F_118 ( V_35 ) ;
F_119 ( V_35 , V_224 ) ;
return 0 ;
}
static int F_120 ( struct V_182 * V_9 )
{
struct V_31 * V_35 = F_112 ( V_9 ) ;
struct V_215 * V_8 = F_113 ( V_9 ) ;
struct V_1 * V_170 = V_8 -> V_25 ;
struct V_216 * V_217 ;
int V_110 , V_218 ;
V_217 = V_170 -> V_219 ;
if ( ! V_217 )
return 0 ;
F_119 ( V_35 , V_225 ) ;
F_121 ( V_35 ) ;
if ( F_122 ( V_35 ) < 0 ) {
F_12 ( V_9 , L_35 ) ;
F_123 ( V_8 ) ;
return - V_10 ;
}
F_124 ( V_35 ) ;
F_54 ( & V_170 -> V_85 ) ;
for ( V_110 = 0 ; V_110 < V_51 ; V_110 ++ ) {
F_35 ( V_110 , F_3 ( V_170 , V_40 ) ) ;
for ( V_218 = 0 ; V_218 < V_222 ; V_218 ++ )
F_5 ( V_217 -> V_223 [ V_110 ] [ V_218 ] , F_3 ( V_170 , V_218 * 4 + 0xe0 ) ) ;
}
for ( V_110 = 0 ; V_110 < V_221 ; V_110 ++ ) {
if ( ( V_110 * 4 == V_97 ) || ( V_110 * 4 == V_147 ) ||
( V_110 * 4 == V_149 ) )
continue;
F_5 ( V_217 -> V_18 [ V_110 ] , F_3 ( V_170 , V_110 * 4 ) ) ;
}
F_5 ( V_217 -> V_18 [ V_149 >> 2 ] , F_3 ( V_170 , V_149 ) ) ;
F_5 ( V_217 -> V_18 [ V_97 >> 2 ] , F_3 ( V_170 , V_97 ) ) ;
F_55 ( & V_170 -> V_85 ) ;
for ( V_110 = 0 ; V_110 < V_170 -> V_172 ; V_110 ++ )
F_125 ( V_170 -> V_24 [ V_110 ] ) ;
F_114 ( V_8 , V_226 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 )
{
if ( V_2 -> V_95 )
F_25 ( V_2 ) ;
if ( V_2 -> V_92 >= 0 )
F_127 ( V_2 -> V_92 , V_2 ) ;
if ( V_2 -> V_3 )
F_128 ( V_2 -> V_35 ) ;
F_117 ( V_2 -> V_35 ) ;
#ifdef F_129
F_130 ( V_2 -> V_219 ) ;
#endif
F_131 ( V_2 -> V_34 ) ;
F_131 ( V_2 -> V_227 ) ;
F_130 ( V_2 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
unsigned int V_228 ;
unsigned char V_229 ;
struct V_31 * V_31 ;
F_10 ( V_2 -> V_8 -> V_9 , L_36 ) ;
if ( F_17 ( V_2 ) ) {
F_12 ( V_2 -> V_8 -> V_9 , L_37 ) ;
return - 1 ;
}
if ( V_2 -> V_20 == V_21 ) {
V_31 = V_2 -> V_34 ;
F_43 ( V_31 , 0x59 , & V_229 ) ;
V_229 |= 0x80 ;
F_44 ( V_31 , 0x59 , V_229 ) ;
V_31 = V_2 -> V_227 ;
F_43 ( V_31 , 0xb8 , & V_229 ) ;
V_229 |= 0x20 ;
F_44 ( V_31 , 0xB8 , V_229 ) ;
}
F_18 ( V_2 -> V_35 , 0x44 , & V_228 ) ;
V_228 &= 0xff00ff00 ;
V_228 |= 0x000800aa ;
F_19 ( V_2 -> V_35 , 0x44 , V_228 ) ;
F_5 ( 0x80000001 , F_3 ( V_2 , V_38 ) ) ;
F_5 ( 0x00000000 , F_3 ( V_2 , V_148 ) ) ;
F_5 ( 0xffffffff , F_3 ( V_2 , V_230 ) ) ;
F_5 ( 0x00000000 , F_3 ( V_2 , V_231 ) ) ;
F_35 ( 0x10 , F_3 ( V_2 , V_232 ) ) ;
V_2 -> V_233 = F_14 ( V_2 , 0 , V_234 ) ;
V_2 -> V_235 = F_14 ( V_2 , 0 ,
V_236 ) ;
if ( V_2 -> V_55 ) {
F_42 ( V_2 ) ;
V_2 -> V_206 = 0x00000002 ;
}
V_2 -> V_172 = 1 ;
if ( F_2 ( F_3 ( V_2 , V_76 ) ) & V_237 ) {
V_2 -> V_172 ++ ;
F_5 ( F_2 ( F_3 ( V_2 , V_76 ) ) |
( V_238 | V_239 |
V_240 ) ,
F_3 ( V_2 , V_76 ) ) ;
}
F_10 ( V_2 -> V_8 -> V_9 , L_38 ) ;
return 0 ;
}
static void F_133 ( struct V_241 * V_242 ,
struct V_243 * V_244 )
{
struct V_1 * V_2 = V_242 -> V_25 ;
int V_110 ;
for ( V_110 = 0 ; V_110 < 256 ; V_110 += 4 )
F_134 ( V_244 , L_39 , V_110 , F_2 ( F_3 ( V_2 , V_110 ) ) ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_241 * V_242 ;
if ( ! F_136 ( V_2 -> V_8 , L_40 , & V_242 ) )
F_137 ( V_242 , V_2 , F_133 ) ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_152 ;
F_10 ( V_2 -> V_8 -> V_9 , L_41 ) ;
V_152 = F_139 ( V_2 -> V_35 , L_42 ) ;
if ( V_152 < 0 )
return V_152 ;
V_2 -> V_3 = F_140 ( V_2 -> V_35 , 0 ) ;
if ( F_141 ( V_2 -> V_35 -> V_92 , F_52 ,
V_245 , V_246 , V_2 ) ) {
F_12 ( V_2 -> V_8 -> V_9 , L_43 ) ;
return - V_247 ;
}
V_2 -> V_92 = V_2 -> V_35 -> V_92 ;
F_10 ( V_2 -> V_8 -> V_9 , L_44 ) ;
return 0 ;
}
static int F_142 ( struct V_248 * V_182 )
{
struct V_1 * V_2 = V_182 -> V_249 ;
F_126 ( V_2 ) ;
return 0 ;
}
static int F_143 ( struct V_215 * V_8 ,
struct V_31 * V_35 ,
int V_250 ,
int V_55 ,
struct V_1 * * V_251 )
{
struct V_1 * V_2 ;
int V_110 , V_152 ;
unsigned short V_252 ;
static struct V_253 V_210 = {
. V_254 = F_142 ,
} ;
* V_251 = NULL ;
F_10 ( V_8 -> V_9 , L_45 ) ;
V_152 = F_122 ( V_35 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( F_144 ( V_35 , F_145 ( 31 ) ) < 0 ||
F_146 ( V_35 , F_145 ( 31 ) ) < 0 ) {
F_12 ( V_8 -> V_9 ,
L_46 ) ;
F_117 ( V_35 ) ;
return - V_255 ;
}
V_2 = F_147 ( sizeof( * V_2 ) , V_256 ) ;
if ( ! V_2 ) {
F_117 ( V_35 ) ;
return - V_153 ;
}
F_148 ( & V_2 -> V_85 ) ;
F_148 ( & V_2 -> V_103 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_92 = - 1 ;
V_2 -> V_20 = V_35 -> V_20 ;
V_2 -> V_55 = V_55 ;
if ( V_250 < 1 )
V_250 = 1 ;
if ( V_250 > 32 )
V_250 = 32 ;
F_124 ( V_35 ) ;
F_149 ( V_35 , V_257 , & V_252 ) ;
if ( ( V_252 & V_258 ) != V_258 ) {
V_252 |= V_258 ;
F_150 ( V_35 , V_257 , V_252 ) ;
}
F_124 ( V_35 ) ;
if ( F_138 ( V_2 ) ) {
F_126 ( V_2 ) ;
return - V_247 ;
}
F_151 ( V_35 -> V_92 ) ;
V_2 -> V_49 . V_52 = 0 ;
V_2 -> V_49 . V_50 = 0 ;
V_2 -> V_206 = 0 ;
V_2 -> V_49 . V_259 = 0 ;
if ( V_2 -> V_20 == V_21 )
V_2 -> V_17 . V_18 . V_22 = V_260 ;
else
V_2 -> V_17 . V_18 . V_22 = V_261 ;
V_2 -> V_17 . V_18 . V_19 = V_260 ;
V_2 -> V_17 . V_18 . V_262 = V_149 ;
V_2 -> V_17 . V_18 . V_61 = V_147 ;
V_2 -> V_17 . V_18 . V_83 = V_230 ;
V_2 -> V_17 . V_18 . V_47 = V_148 ;
V_2 -> V_17 . V_46 . V_262 = 0x00 ;
V_2 -> V_17 . V_46 . V_61 = 0x00 ;
V_2 -> V_17 . V_46 . V_83 = 0x00 ;
V_2 -> V_17 . V_46 . V_47 = 0x00 ;
V_2 -> V_34 = F_152 ( 0x10b9 , 0x1533 , NULL ) ;
if ( ! V_2 -> V_34 ) {
F_12 ( V_8 -> V_9 , L_47 ) ;
F_126 ( V_2 ) ;
return - V_263 ;
}
V_2 -> V_227 = F_152 ( 0x10b9 , 0x7101 , NULL ) ;
if ( ! V_2 -> V_227 && V_2 -> V_20 == V_21 ) {
F_12 ( V_8 -> V_9 , L_48 ) ;
F_126 ( V_2 ) ;
return - V_263 ;
}
F_10 ( V_8 -> V_9 , L_49 ) ;
V_152 = F_153 ( V_8 , V_264 , V_2 , & V_210 ) ;
if ( V_152 < 0 ) {
F_126 ( V_2 ) ;
return V_152 ;
}
for ( V_110 = 0 ; V_110 < V_51 ; V_110 ++ )
V_2 -> V_49 . V_84 [ V_110 ] . V_107 = V_110 ;
V_152 = F_132 ( V_2 ) ;
if ( V_152 < 0 ) {
F_12 ( V_8 -> V_9 , L_50 ) ;
return V_152 ;
}
#ifdef F_129
V_2 -> V_219 = F_154 ( sizeof( * V_2 -> V_219 ) , V_256 ) ;
if ( ! V_2 -> V_219 )
F_79 ( V_8 -> V_9 , L_51 ) ;
#endif
F_24 ( V_2 ) ;
V_2 -> V_95 = 1 ;
* V_251 = V_2 ;
F_10 ( V_8 -> V_9 , L_52 ) ;
return 0 ;
}
static int F_155 ( struct V_31 * V_35 ,
const struct V_265 * V_266 )
{
struct V_215 * V_8 ;
struct V_1 * V_2 ;
int V_152 ;
F_10 ( & V_35 -> V_9 , L_53 ) ;
V_152 = F_156 ( & V_35 -> V_9 , V_267 , V_268 , V_269 , 0 , & V_8 ) ;
if ( V_152 < 0 )
return V_152 ;
V_152 = F_143 ( V_8 , V_35 , V_270 , V_271 , & V_2 ) ;
if ( V_152 < 0 )
goto error;
V_8 -> V_25 = V_2 ;
F_10 ( & V_35 -> V_9 , L_54 ) ;
V_152 = F_106 ( V_2 ) ;
if ( V_152 < 0 )
goto error;
F_10 ( & V_35 -> V_9 , L_55 ) ;
V_152 = F_103 ( V_2 ) ;
if ( V_152 < 0 )
goto error;
F_135 ( V_2 ) ;
strcpy ( V_8 -> V_272 , L_56 ) ;
strcpy ( V_8 -> V_273 , L_42 ) ;
sprintf ( V_8 -> V_274 , L_57 ,
V_8 -> V_273 , V_2 -> V_3 , V_2 -> V_92 ) ;
F_10 ( & V_35 -> V_9 , L_58 ) ;
V_152 = F_157 ( V_8 ) ;
if ( V_152 < 0 )
goto error;
F_158 ( V_35 , V_8 ) ;
return 0 ;
error:
F_159 ( V_8 ) ;
return V_152 ;
}
static void F_160 ( struct V_31 * V_35 )
{
F_159 ( F_161 ( V_35 ) ) ;
}
