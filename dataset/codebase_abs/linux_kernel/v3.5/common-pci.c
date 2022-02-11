static void F_1 ( T_1 V_1 , T_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
* V_5 = V_1 ;
* V_2 = * V_6 ;
F_3 ( & V_4 , V_3 ) ;
}
static void F_4 ( T_1 V_1 , T_1 V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
* V_5 = V_7 | V_1 ;
* V_8 = V_2 ;
F_3 ( & V_4 , V_3 ) ;
}
static inline int F_5 ( void )
{
unsigned long V_9 = * V_10 ;
if ( V_9 & V_11 ) {
* V_10 = V_11 ;
F_6 ( L_1 , V_12 ) ;
return 1 ;
}
return 0 ;
}
int F_7 ( T_1 V_13 , T_1 V_14 , T_1 * V_2 )
{
unsigned long V_3 ;
int V_15 = 0 ;
int V_16 ;
F_2 ( & V_4 , V_3 ) ;
* V_17 = V_13 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
* V_18 = V_14 ;
* V_2 = * V_19 ;
* V_2 = * V_19 ;
}
if( F_5 () )
V_15 = 1 ;
F_3 ( & V_4 , V_3 ) ;
return V_15 ;
}
int F_8 ( T_1 V_13 , T_1 V_14 , T_1 * V_2 )
{
unsigned long V_3 ;
int V_15 = 0 ;
F_2 ( & V_4 , V_3 ) ;
* V_17 = V_13 ;
* V_18 = V_14 ;
* V_2 = * V_19 ;
if( F_5 () )
V_15 = 1 ;
F_3 ( & V_4 , V_3 ) ;
return V_15 ;
}
int F_9 ( T_1 V_13 , T_1 V_14 , T_1 V_2 )
{
unsigned long V_3 ;
int V_15 = 0 ;
F_2 ( & V_4 , V_3 ) ;
* V_17 = V_13 ;
* V_18 = V_14 ;
* V_20 = V_2 ;
if( F_5 () )
V_15 = 1 ;
F_3 ( & V_4 , V_3 ) ;
return V_15 ;
}
static T_1 F_10 ( T_2 V_21 , T_3 V_22 , int V_23 )
{
T_1 V_13 ;
if ( ! V_21 ) {
V_13 = F_11 ( 32 - F_12 ( V_22 ) ) | ( ( F_13 ( V_22 ) ) << 8 ) |
( V_23 & ~ 3 ) ;
} else {
V_13 = ( V_21 << 16 ) | ( ( F_12 ( V_22 ) ) << 11 ) |
( ( F_13 ( V_22 ) ) << 8 ) | ( V_23 & ~ 3 ) | 1 ;
}
return V_13 ;
}
static T_1 F_14 ( T_1 V_24 , int V_25 )
{
if ( V_25 == 1 )
return ( 0xf & ~ F_11 ( V_24 ) ) << V_26 ;
if ( V_25 == 2 )
return ( 0xf & ~ ( F_11 ( V_24 ) | F_11 ( V_24 + 1 ) ) ) << V_26 ;
if ( V_25 == 4 )
return 0 ;
return 0xffffffff ;
}
static int F_15 ( int V_23 , int V_25 , T_1 * V_27 )
{
T_1 V_24 , V_2 ;
F_6 ( L_2 , V_23 , V_25 ) ;
V_24 = V_23 % 4 ;
F_1 ( V_23 & ~ 3 , & V_2 ) ;
* V_27 = ( V_2 >> ( 8 * V_24 ) ) & V_28 [ V_25 ] ;
F_6 ( L_3 , * V_27 ) ;
return V_29 ;
}
static int F_16 ( int V_23 , int V_25 , T_1 V_27 )
{
T_1 V_24 , V_30 , V_2 ;
F_6 ( L_4 , V_27 , V_23 , V_25 ) ;
V_24 = V_23 % 4 ;
V_30 = F_14 ( V_24 , V_25 ) ;
if ( V_30 == 0xffffffff )
return V_31 ;
V_2 = V_27 << ( 8 * V_24 ) ;
F_4 ( ( V_23 & ~ 3 ) | V_30 , V_2 ) ;
return V_29 ;
}
static T_1 F_17 ( T_1 V_24 , int V_25 )
{
if ( V_25 == 1 )
return ( 0xf & ~ F_11 ( V_24 ) ) << 4 ;
if ( V_25 == 2 )
return ( 0xf & ~ ( F_11 ( V_24 ) | F_11 ( V_24 + 1 ) ) ) << 4 ;
if ( V_25 == 4 )
return 0 ;
return 0xffffffff ;
}
static int F_18 ( struct V_32 * V_33 , unsigned int V_22 , int V_23 , int V_25 , T_1 * V_27 )
{
T_1 V_24 , V_30 , V_13 , V_2 ;
T_2 V_21 = V_33 -> V_34 ;
F_6 ( L_5 , V_23 , V_25 ,
V_21 , F_12 ( V_22 ) , F_13 ( V_22 ) ) ;
* V_27 = 0xffffffff ;
V_24 = V_23 % 4 ;
V_30 = F_17 ( V_24 , V_25 ) ;
if ( V_30 == 0xffffffff )
return V_31 ;
V_13 = F_10 ( V_21 , V_22 , V_23 ) ;
if ( F_19 ( V_13 , V_30 | V_35 , & V_2 ) )
return V_36 ;
* V_27 = ( V_2 >> ( 8 * V_24 ) ) & V_28 [ V_25 ] ;
F_6 ( L_6 , * V_27 ) ;
return V_29 ;
}
static int F_20 ( struct V_32 * V_33 , unsigned int V_22 , int V_23 , int V_25 , T_1 V_27 )
{
T_1 V_24 , V_30 , V_13 , V_2 ;
T_2 V_21 = V_33 -> V_34 ;
F_6 ( L_7 , V_27 , V_23 ,
V_25 , V_21 , F_12 ( V_22 ) , F_13 ( V_22 ) ) ;
V_24 = V_23 % 4 ;
V_30 = F_17 ( V_24 , V_25 ) ;
if ( V_30 == 0xffffffff )
return V_31 ;
V_13 = F_10 ( V_21 , V_22 , V_23 ) ;
V_2 = V_27 << ( 8 * V_24 ) ;
if ( F_9 ( V_13 , V_30 | V_37 , V_2 ) )
return V_36 ;
return V_29 ;
}
static int F_21 ( unsigned long V_13 , unsigned int V_38 , struct V_39 * V_40 )
{
T_1 V_9 , V_41 ;
V_9 = * V_10 ;
F_15 ( V_42 , 2 , & V_41 ) ;
F_6 ( L_8
L_9 , V_13 , V_9 , V_41 ) ;
* V_10 = V_11 ;
V_41 |= V_43 ;
F_16 ( V_42 , 2 , V_41 ) ;
if ( V_38 & ( 1 << 10 ) )
V_40 -> V_44 += 4 ;
return 0 ;
}
static int F_22 ( struct V_45 * V_46 , T_4 V_47 , T_5 V_25 )
{
return ( V_47 + V_25 ) >= V_48 ;
}
static int F_23 ( struct V_45 * V_46 )
{
if( V_46 -> V_33 == & V_49 ) {
* V_46 -> V_50 = V_48 - 1 ;
V_46 -> V_51 = V_48 - 1 ;
F_24 ( V_46 , 2048 , 4096 , F_22 ) ;
}
return 0 ;
}
static int F_25 ( struct V_45 * V_46 )
{
if( V_46 -> V_33 == & V_49 ) {
F_26 ( V_46 ) ;
}
return 0 ;
}
void T_6 F_27 ( void )
{
unsigned long V_52 = F_28 () ;
#ifdef F_29
V_53 = 0x10000000 ;
#else
V_53 = 0x48000000 ;
#endif
if ( ! ( V_52 & 0xf ) && F_30 () ) {
F_31 ( L_10
L_11 ) ;
F_19 = F_7 ;
} else
F_19 = F_8 ;
F_32 ( 16 + 6 , F_21 , V_54 , 0 ,
L_12 ) ;
F_6 ( L_13 ) ;
* V_55 = 0x48494A4B ;
* V_56 = ( V_57 & 0xFF000000 ) +
( ( V_57 & 0xFF000000 ) >> 8 ) +
( ( V_57 & 0xFF000000 ) >> 16 ) +
( ( V_57 & 0xFF000000 ) >> 24 ) +
0x00010203 ;
if ( * V_58 & V_59 ) {
F_31 ( L_14 ) ;
F_6 ( L_15 ) ;
F_16 ( V_60 , 4 , V_57 ) ;
F_16 ( V_61 , 4 , V_57 + V_62 ) ;
F_16 ( V_63 , 4 , V_57 + V_64 ) ;
F_16 ( V_65 , 4 ,
V_57 + V_64 + V_62 ) ;
F_16 ( V_66 , 4 , V_57 + V_48 ) ;
F_16 ( V_67 , 4 , 0xfffffc01 ) ;
} else {
F_31 ( L_16 ) ;
}
F_31 ( L_17 ,
#ifndef F_29
L_18
#else
L_19
#endif
) ;
F_6 ( L_20 ) ;
* V_10 = V_68 | V_11 | V_69 | V_70 ;
#ifdef F_33
* V_58 = V_71 | V_72 | V_73 | V_74 ;
#else
* V_58 = V_71 | V_72 ;
#endif
F_6 ( L_21 ) ;
}
int F_34 ( int V_75 , struct V_76 * V_77 )
{
struct V_78 * V_79 ;
if ( V_75 >= 1 )
return 0 ;
V_79 = F_35 ( sizeof( * V_79 ) * 2 , V_80 ) ;
if ( V_79 == NULL ) {
F_36 ( L_22 ) ;
}
F_16 ( V_81 , 2 , V_82 | V_83 ) ;
V_79 [ 0 ] . V_84 = L_23 ;
V_79 [ 0 ] . V_85 = 0x00000000 ;
V_79 [ 0 ] . V_86 = 0x0000ffff ;
V_79 [ 0 ] . V_3 = V_87 ;
V_79 [ 1 ] . V_84 = L_24 ;
V_79 [ 1 ] . V_85 = V_88 ;
V_79 [ 1 ] . V_86 = V_89 ;
V_79 [ 1 ] . V_3 = V_90 ;
F_37 ( & V_91 , & V_79 [ 0 ] ) ;
F_37 ( & V_92 , & V_79 [ 1 ] ) ;
F_38 ( & V_77 -> V_93 , & V_79 [ 0 ] , V_77 -> V_94 ) ;
F_38 ( & V_77 -> V_93 , & V_79 [ 1 ] , V_77 -> V_95 ) ;
V_96 = F_23 ;
V_97 = F_25 ;
return 1 ;
}
int F_39 ( struct V_45 * V_46 , T_7 V_98 )
{
if ( V_98 >= V_48 - 1 )
return 0 ;
return - V_99 ;
}
