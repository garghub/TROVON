static inline unsigned int F_1 ( const T_1 * V_1 )
{
unsigned int V_2 , V_3 = 0 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
if ( V_1 [ V_2 ] != 0 )
V_3 ++ ;
}
return V_3 ;
}
static void F_2 ( struct V_5 * V_6 ,
unsigned int V_7 ,
const T_1 * V_1 )
{
T_2 V_8 = V_9 + V_7 * V_10 ;
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ )
F_3 ( V_6 , V_1 [ V_2 ] , V_8 + V_2 * 4 ) ;
}
static int F_4 ( struct V_5 * V_6 , unsigned int V_11 )
{
unsigned int V_12 = 1000 ;
T_2 V_13 ;
V_13 = F_5 ( V_6 , V_14 ) ;
V_13 &= ~ ( V_15 | V_16 ) ;
V_13 |= V_17 | V_11 ;
F_3 ( V_6 , V_13 , V_14 ) ;
do {
V_13 = F_5 ( V_6 , V_14 ) ;
if ( ! ( V_13 & V_17 ) )
break;
F_6 () ;
} while ( V_12 -- );
if ( ! V_12 )
return - V_18 ;
return 0 ;
}
static inline void F_7 ( struct V_5 * V_6 ,
unsigned int V_19 )
{
T_2 V_13 ;
F_8 ( V_19 >= V_6 -> V_20 ) ;
V_13 = F_5 ( V_6 , V_14 ) ;
V_13 &= ~ ( V_21 << V_22 ) ;
V_13 |= V_19 << V_22 ;
F_3 ( V_6 , V_13 , V_14 ) ;
}
static inline unsigned int F_9 ( struct V_5 * V_6 )
{
return V_6 -> V_20 - 1 ;
}
static int F_10 ( struct V_23 * V_24 , int V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_11 ( V_24 ) ;
struct V_28 * V_29 ;
const struct V_30 * V_1 ;
unsigned int V_7 , V_31 ;
unsigned int V_32 , V_33 ;
T_1 V_34 , V_35 ;
T_1 V_36 ;
T_2 V_13 ;
int V_37 ;
if ( ( V_27 -> V_38 & V_39 ) &&
( V_27 -> V_40 . V_41 || V_27 -> V_40 . V_42 [ 1 ] ) )
return - V_43 ;
if ( V_27 -> V_44 != V_45 &&
F_12 ( V_27 -> V_44 , V_6 -> V_46 . V_47 ) )
return - V_48 ;
if ( V_27 -> V_44 != V_45 &&
V_27 -> V_44 > F_9 ( V_6 ) )
return - V_43 ;
V_35 = F_13 ( V_27 -> V_40 . V_42 [ 0 ] ) ;
V_33 = V_27 -> V_49 / 8 ;
if ( V_27 -> V_49 == V_50 ||
! ( F_14 ( V_33 ) & V_24 -> V_51 ) ||
V_33 >= V_6 -> V_52 . V_53 )
return - V_43 ;
switch ( V_27 -> V_38 & ~ V_39 ) {
case V_54 :
V_34 = V_55 ;
V_29 = & V_27 -> V_56 . V_57 ;
break;
case V_58 :
V_34 = V_59 ;
V_29 = & V_27 -> V_56 . V_60 ;
break;
default:
return - V_43 ;
}
V_7 = 1 ;
V_1 = & V_61 ;
V_36 = F_1 ( V_1 -> V_62 ) ;
F_2 ( V_6 , V_7 , V_1 -> V_62 ) ;
F_3 ( V_6 , F_14 ( V_25 ) , F_15 ( 7 ) ) ;
F_3 ( V_6 , V_29 -> V_63 << 16 | V_34 << 8 | V_35 << 7 ,
F_15 ( 6 ) ) ;
F_3 ( V_6 , F_16 ( V_36 - 1 , 0 ) << 24 , F_15 ( 5 ) ) ;
F_3 ( V_6 , 0 , F_15 ( 4 ) ) ;
F_3 ( V_6 , F_17 ( V_29 -> V_64 ) >> 8 ,
F_15 ( 3 ) ) ;
V_13 = ( F_17 ( V_29 -> V_64 ) & 0xff ) << 24 |
( T_2 ) F_17 ( V_29 -> V_65 ) << 8 |
( F_13 ( V_29 -> V_66 ) & 0x0000ff00 ) >> 8 ;
F_3 ( V_6 , V_13 , F_15 ( 2 ) ) ;
V_13 = ( T_2 ) ( F_13 ( V_29 -> V_66 ) & 0xff ) << 24 |
( T_2 ) ( F_13 ( V_29 -> V_66 ) >> 16 ) << 8 |
( F_13 ( V_29 -> V_67 ) & 0x0000ff00 ) >> 8 ;
F_3 ( V_6 , V_13 , F_15 ( 1 ) ) ;
V_13 = ( T_2 ) ( F_13 ( V_29 -> V_67 ) & 0xff ) << 24 |
( T_2 ) ( F_13 ( V_29 -> V_67 ) >> 16 ) << 8 |
F_18 ( V_7 ) | V_68 ;
F_3 ( V_6 , V_13 , F_15 ( 0 ) ) ;
F_3 ( V_6 , 0xff , F_19 ( 7 ) ) ;
F_3 ( V_6 , V_1 -> V_69 , F_19 ( 6 ) ) ;
F_3 ( V_6 , F_16 ( V_36 - 1 , 0 ) << 24 , F_19 ( 5 ) ) ;
F_3 ( V_6 , 0 , F_19 ( 4 ) ) ;
F_3 ( V_6 , 0xff , F_19 ( 3 ) ) ;
F_3 ( V_6 , 0xffffffff , F_19 ( 2 ) ) ;
F_3 ( V_6 , 0xffffffff , F_19 ( 1 ) ) ;
F_3 ( V_6 , 0xffffff0f , F_19 ( 0 ) ) ;
if ( V_27 -> V_44 == V_45 )
V_31 = F_20 ( V_6 -> V_46 . V_47 ,
F_9 ( V_6 ) ) ;
else
V_31 = V_27 -> V_44 ;
F_7 ( V_6 , V_31 ) ;
V_37 = F_4 ( V_6 , V_70 | V_71 ) ;
if ( V_37 ) {
F_21 ( L_1 , V_31 ) ;
return V_37 ;
}
V_32 = V_27 -> V_49 % 8 ;
if ( V_33 >= 7 )
V_33 -= 1 ;
V_13 = V_72 | F_14 ( V_33 + V_73 ) |
V_74 | V_32 << V_75 ;
F_3 ( V_6 , V_13 , V_76 ) ;
F_3 ( V_6 , V_31 << V_77 ,
V_78 ) ;
F_3 ( V_6 , 0 , V_79 ) ;
V_37 = F_4 ( V_6 , V_70 | V_80 ) ;
if ( V_37 ) {
F_21 ( L_2 , V_31 ) ;
return V_37 ;
}
F_3 ( V_6 , V_81 , V_82 ) ;
V_37 = F_4 ( V_6 , V_70 | V_83 ) ;
if ( V_37 ) {
F_21 ( L_3 , V_31 ) ;
return V_37 ;
}
V_13 = F_5 ( V_6 , V_84 ) ;
V_13 |= F_14 ( V_25 ) ;
F_3 ( V_6 , V_13 , V_84 ) ;
F_22 ( V_31 , V_6 -> V_46 . V_47 ) ;
V_27 -> V_44 = V_31 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , int V_25 ,
T_2 V_85 )
{
int V_37 ;
T_2 V_13 ;
if ( ! F_12 ( V_85 , V_6 -> V_46 . V_47 ) || V_85 == 0 )
return - V_43 ;
F_7 ( V_6 , V_85 ) ;
V_37 = F_4 ( V_6 , V_86 | V_71 ) ;
if ( V_37 )
return V_37 ;
V_13 = F_5 ( V_6 , F_15 ( 0 ) ) ;
V_13 &= ~ V_68 ;
F_3 ( V_6 , V_13 , F_15 ( 0 ) ) ;
V_37 = F_4 ( V_6 , V_70 | V_71 ) ;
if ( V_37 )
return V_37 ;
F_24 ( V_85 , V_6 -> V_46 . V_47 ) ;
return 0 ;
}
static void F_25 ( struct V_26 * V_87 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < sizeof( V_87 -> V_88 ) ; V_2 ++ )
V_87 -> V_88 . V_89 [ V_2 ] ^= 0xff ;
V_87 -> V_40 . V_41 ^= F_26 ( ~ 0 ) ;
V_87 -> V_40 . V_90 ^= F_26 ( ~ 0 ) ;
V_87 -> V_40 . V_42 [ 0 ] ^= F_27 ( ~ 0 ) ;
V_87 -> V_40 . V_42 [ 1 ] ^= F_27 ( ~ 0 ) ;
}
static int F_28 ( struct V_5 * V_6 , int V_25 ,
struct V_91 * V_92 , bool V_93 )
{
struct V_28 * V_29 ;
unsigned int V_32 ;
T_3 V_94 ;
T_2 V_13 , V_95 ;
int V_37 ;
if ( ! V_93 ) {
F_7 ( V_6 , V_92 -> V_27 . V_44 ) ;
V_37 = F_4 ( V_6 , V_86 | V_80 ) ;
if ( V_37 )
return V_37 ;
V_13 = F_5 ( V_6 , V_76 ) ;
V_37 = F_4 ( V_6 , V_86 | V_71 ) ;
if ( V_37 )
return V_37 ;
} else {
V_13 = F_5 ( V_6 , V_76 ) ;
}
V_92 -> V_27 . V_49 = F_29 ( ( V_13 >> V_73 ) &
V_96 ) - 1 ;
if ( V_92 -> V_27 . V_49 >= 6 )
V_92 -> V_27 . V_49 ++ ;
V_92 -> V_27 . V_49 *= 8 ;
V_32 = ( V_13 >> V_75 ) & V_97 ;
V_92 -> V_27 . V_49 += V_32 ;
V_13 = F_5 ( V_6 , F_15 ( 6 ) ) ;
switch ( ( V_13 & V_98 ) >> V_99 ) {
case V_55 :
V_92 -> V_27 . V_38 = V_54 ;
V_29 = & V_92 -> V_27 . V_56 . V_57 ;
break;
case V_59 :
V_92 -> V_27 . V_38 = V_58 ;
V_29 = & V_92 -> V_27 . V_56 . V_60 ;
break;
default:
if ( V_93 )
F_5 ( V_6 , F_15 ( 7 ) ) ;
return - V_43 ;
}
V_29 -> V_63 = ( V_13 >> 16 ) & V_98 ;
V_92 -> V_27 . V_40 . V_42 [ 0 ] = F_27 ( ( V_13 >> 7 ) & 1 ) ;
V_13 = F_5 ( V_6 , F_15 ( 3 ) ) ;
V_94 = V_13 << 8 ;
V_13 = F_5 ( V_6 , F_15 ( 2 ) ) ;
V_94 |= ( V_13 >> 24 ) ;
V_29 -> V_64 = F_26 ( V_94 ) ;
V_92 -> V_27 . V_88 . V_57 . V_64 = F_26 ( ~ 0 ) ;
V_29 -> V_65 = F_26 ( ( T_3 ) ( V_13 >> 8 ) ) ;
V_92 -> V_27 . V_88 . V_57 . V_65 = F_26 ( ~ 0 ) ;
V_95 = ( V_13 & 0xff ) << 8 ;
V_13 = F_5 ( V_6 , F_15 ( 1 ) ) ;
V_95 |= ( ( V_13 >> 8 ) & 0xffff ) << 16 ;
V_95 |= ( V_13 >> 24 ) & 0xff ;
V_29 -> V_66 = F_27 ( V_95 ) ;
V_92 -> V_27 . V_88 . V_57 . V_66 = F_27 ( ~ 0 ) ;
V_95 = ( V_13 & 0xff ) << 8 ;
V_13 = F_5 ( V_6 , F_15 ( 0 ) ) ;
if ( ! ( V_13 & V_68 ) )
return - V_43 ;
V_95 |= ( V_13 >> 24 ) & 0xff ;
V_95 |= ( ( V_13 >> 8 ) & 0xffff ) << 16 ;
V_29 -> V_67 = F_27 ( V_95 ) ;
V_92 -> V_27 . V_88 . V_57 . V_67 = F_27 ( ~ 0 ) ;
V_13 = F_5 ( V_6 , F_15 ( 7 ) ) ;
if ( ! ( V_13 & 1 << V_25 ) )
return - V_43 ;
F_25 ( & V_92 -> V_27 ) ;
V_92 -> V_42 = F_9 ( V_6 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 ,
int V_25 , struct V_91 * V_92 ,
T_2 * V_100 )
{
unsigned int V_101 = 1 , V_102 = 0 ;
int V_37 ;
T_2 V_13 ;
V_13 = F_5 ( V_6 , V_14 ) ;
V_13 &= ~ ( V_21 << V_22 ) ;
V_13 |= V_101 << V_22 ;
V_13 &= ~ ( V_15 | V_16 ) ;
V_13 |= V_103 | V_71 | V_17 ;
F_3 ( V_6 , V_13 , V_14 ) ;
do {
V_13 = F_5 ( V_6 , V_14 ) ;
V_101 = V_13 >> V_22 ;
V_101 &= V_21 ;
if ( V_13 & V_104 ) {
V_37 = F_28 ( V_6 , V_25 , V_92 , true ) ;
if ( V_37 )
continue;
V_100 [ V_102 ] = V_101 ;
V_102 ++ ;
}
if ( ! ( V_13 & V_17 ) )
break;
} while ( V_101 < V_6 -> V_20 );
V_92 -> V_42 = F_9 ( V_6 ) ;
V_92 -> V_105 = V_102 ;
return 0 ;
}
int F_31 ( struct V_23 * V_24 , int V_25 ,
struct V_91 * V_92 , T_2 * V_100 )
{
struct V_5 * V_6 = F_11 ( V_24 ) ;
int V_37 = 0 ;
F_32 ( & V_6 -> V_46 . V_106 ) ;
switch ( V_92 -> V_107 ) {
case V_108 :
V_92 -> V_105 = F_33 ( V_6 -> V_46 . V_47 ,
V_6 -> V_20 ) - 1 ;
V_92 -> V_42 |= V_109 ;
break;
case V_110 :
V_37 = F_28 ( V_6 , V_25 , V_92 , false ) ;
break;
case V_111 :
V_37 = F_30 ( V_6 , V_25 , V_92 , V_100 ) ;
break;
default:
V_37 = - V_112 ;
break;
}
F_34 ( & V_6 -> V_46 . V_106 ) ;
return V_37 ;
}
int F_35 ( struct V_23 * V_24 , int V_25 ,
struct V_91 * V_92 )
{
struct V_5 * V_6 = F_11 ( V_24 ) ;
int V_37 = 0 ;
F_32 ( & V_6 -> V_46 . V_106 ) ;
switch ( V_92 -> V_107 ) {
case V_113 :
V_37 = F_10 ( V_24 , V_25 , & V_92 -> V_27 ) ;
break;
case V_114 :
V_37 = F_23 ( V_6 , V_25 , V_92 -> V_27 . V_44 ) ;
break;
default:
V_37 = - V_112 ;
break;
}
F_34 ( & V_6 -> V_46 . V_106 ) ;
return V_37 ;
}
int F_36 ( struct V_5 * V_6 )
{
unsigned int V_12 = 1000 ;
T_2 V_13 ;
V_13 = F_5 ( V_6 , V_14 ) ;
V_13 |= V_115 ;
F_3 ( V_6 , V_13 , V_14 ) ;
do {
V_13 = F_5 ( V_6 , V_14 ) ;
if ( ! ( V_13 & V_115 ) )
break;
F_6 () ;
} while ( V_12 -- );
if ( ! V_12 )
return - V_18 ;
return 0 ;
}
