static inline void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
unsigned long V_3 = V_4 ;
V_2 -> V_5 . V_6 ++ ;
if ( F_3 ( V_3 , V_2 -> V_5 . V_7 + V_8 ) ) {
V_2 -> V_5 . V_7 = V_3 ;
V_2 -> V_5 . V_9 = V_2 -> V_5 . V_6 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_10 = V_2 -> V_5 . V_11 ;
V_2 -> V_5 . V_11 = 0 ;
}
#endif
}
static inline void F_4 ( struct V_12 * V_13 ,
unsigned char V_14 )
{
F_5 ( 0x81 , F_6 ( V_13 -> V_15 ) ) ;
F_5 ( V_14 , F_7 ( V_13 -> V_15 ) ) ;
F_5 ( 0 , F_8 ( V_13 -> V_15 ) ) ;
F_5 ( 0x01 , F_6 ( V_13 -> V_15 ) ) ;
F_5 ( 0x00 , F_9 ( V_13 -> V_15 ) ) ;
}
static inline void F_10 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
F_4 ( V_13 , 12 ) ;
F_5 ( 0x0e | ( ! ! V_2 -> V_16 . V_17 . V_18 ) , F_11 ( V_13 -> V_15 ) ) ;
if ( V_2 -> V_16 . V_19 <= 1 )
V_2 -> V_16 . V_19 = 0x10000 | F_12 ( & V_2 -> V_20 ) ;
V_2 -> V_16 . V_17 . V_18 = ! ( V_2 -> V_16 . V_17 . V_18 ^
( V_2 -> V_16 . V_19 & 1 ) ) ;
V_2 -> V_16 . V_19 >>= 1 ;
}
static inline void F_13 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
unsigned char V_21 ;
V_21 = F_14 ( F_15 ( V_13 -> V_15 ) ) & 0x10 ;
F_16 ( & V_2 -> V_20 , V_21 ) ;
V_2 -> V_16 . V_17 . V_22 = ( V_2 -> V_16 . V_17 . V_22 << 1 ) |
( V_21 != V_2 -> V_16 . V_17 . V_23 ) ;
V_2 -> V_16 . V_17 . V_23 = V_21 ;
if( V_2 -> V_16 . V_17 . V_22 & 1 ) {
if ( ! V_2 -> V_24 ) {
unsigned int V_25 , V_26 ;
V_25 = V_26 = 0 ;
V_25 += ( ( V_2 -> V_16 . V_17 . V_22 >> 1 ) & 1 ) ;
if ( ! ( V_2 -> V_16 . V_17 . V_22 & 0x7ffffffe ) )
V_25 += 2 ;
V_26 += ( ( V_2 -> V_16 . V_17 . V_22 >> 2 ) & 1 ) ;
V_26 += ( ( V_2 -> V_16 . V_17 . V_22 >> 3 ) & 1 ) ;
V_26 += ( ( V_2 -> V_16 . V_17 . V_22 >> 4 ) & 1 ) ;
V_2 -> V_16 . V_17 . V_27 += 16 * V_25 - V_26 ;
} else
V_2 -> V_16 . V_17 . V_27 -- ;
}
if( ! V_2 -> V_16 . V_17 . V_28 ) {
F_17 ( & V_2 -> V_20 , ( V_2 -> V_16 . V_17 . V_27 +
V_2 -> V_16 . V_17 . V_29 +
V_2 -> V_16 . V_17 . V_30 ) < 0 ) ;
V_2 -> V_16 . V_17 . V_30 = V_2 -> V_16 . V_17 . V_29 ;
V_2 -> V_16 . V_17 . V_29 = V_2 -> V_16 . V_17 . V_27 ;
V_2 -> V_16 . V_17 . V_27 = 2 ;
V_2 -> V_16 . V_17 . V_28 = F_18 ( V_2 ) ;
}
V_2 -> V_16 . V_17 . V_28 -- ;
if ( ! V_2 -> V_24 ) {
if ( V_2 -> V_16 . V_17 . V_31 ) {
F_4 ( V_13 , 4 ) ;
} else {
switch ( V_2 -> V_16 . V_17 . V_22 & 7 ) {
case 1 :
F_4 ( V_13 , 5 ) ;
#ifdef F_2
V_2 -> V_5 . V_11 ++ ;
#endif
break;
case 4 :
F_4 ( V_13 , 3 ) ;
#ifdef F_2
V_2 -> V_5 . V_11 -- ;
#endif
break;
default:
F_4 ( V_13 , 4 ) ;
break;
}
V_2 -> V_16 . V_19 >>= 1 ;
if ( V_2 -> V_16 . V_17 . V_23 ==
V_2 -> V_16 . V_17 . V_32 )
V_2 -> V_16 . V_19 |= 0x10000 ;
V_2 -> V_16 . V_17 . V_32 =
V_2 -> V_16 . V_17 . V_23 ;
}
if ( ++ V_2 -> V_16 . V_17 . V_31 >= 3 )
V_2 -> V_16 . V_17 . V_31 = 0 ;
if ( V_2 -> V_16 . V_17 . V_22 & 1 ) {
unsigned int V_25 , V_26 ;
V_25 = V_26 = 0 ;
V_25 += ( ( V_2 -> V_16 . V_17 . V_22 >> 1 ) & 1 ) ;
V_25 += ( ! ( V_2 -> V_16 . V_17 . V_22 & 0x7ffffffe ) )
<< 1 ;
V_26 += ( ( V_2 -> V_16 . V_17 . V_22 >> 2 ) & 1 ) ;
V_26 += ( ( V_2 -> V_16 . V_17 . V_22 >> 3 ) & 1 ) ;
V_26 += ( ( V_2 -> V_16 . V_17 . V_22 >> 4 ) & 1 ) ;
V_2 -> V_16 . V_17 . V_27 += 16 * V_25 - V_26 ;
}
} else {
if ( V_2 -> V_16 . V_17 . V_31 ) {
F_4 ( V_13 , 6 ) ;
} else {
switch ( V_2 -> V_16 . V_17 . V_22 & 3 ) {
case 1 :
F_4 ( V_13 , 7 ) ;
#ifdef F_2
V_2 -> V_5 . V_11 ++ ;
#endif
break;
case 2 :
F_4 ( V_13 , 5 ) ;
#ifdef F_2
V_2 -> V_5 . V_11 -- ;
#endif
break;
default:
F_4 ( V_13 , 6 ) ;
break;
}
V_2 -> V_16 . V_19 >>= 1 ;
if ( V_2 -> V_16 . V_17 . V_23 ==
V_2 -> V_16 . V_17 . V_32 )
V_2 -> V_16 . V_19 |= 0x10000 ;
V_2 -> V_16 . V_17 . V_32 =
V_2 -> V_16 . V_17 . V_23 ;
}
V_2 -> V_16 . V_17 . V_31 = ! V_2 -> V_16 . V_17 . V_31 ;
V_2 -> V_16 . V_17 . V_27 -= ( V_2 -> V_16 . V_17 . V_22 & 1 ) ;
}
F_5 ( 0x0d , F_11 ( V_13 -> V_15 ) ) ;
if ( V_2 -> V_16 . V_19 & 1 ) {
F_19 ( & V_2 -> V_20 , V_2 -> V_16 . V_19 >> 1 ) ;
V_2 -> V_16 . V_19 = 0x10000 ;
}
if( ! V_2 -> V_16 . V_17 . V_28 ) {
if ( V_2 -> V_24 & 1 )
F_17 ( & V_2 -> V_20 , ! ( ( F_14 ( F_15 ( V_13 -> V_15 ) ) ^ V_2 -> V_24 ) & 0x80 ) ) ;
else
F_17 ( & V_2 -> V_20 , ( V_2 -> V_16 . V_17 . V_27 +
V_2 -> V_16 . V_17 . V_29 +
V_2 -> V_16 . V_17 . V_30 ) < 0 ) ;
V_2 -> V_16 . V_17 . V_30 = V_2 -> V_16 . V_17 . V_29 ;
V_2 -> V_16 . V_17 . V_29 = V_2 -> V_16 . V_17 . V_27 ;
V_2 -> V_16 . V_17 . V_27 = 2 ;
V_2 -> V_16 . V_17 . V_28 = F_18 ( V_2 ) ;
}
V_2 -> V_16 . V_17 . V_28 -- ;
}
static T_1 F_20 ( int V_33 , void * V_34 )
{
struct V_12 * V_13 = (struct V_12 * ) V_34 ;
struct V_1 * V_2 = F_21 ( V_13 ) ;
unsigned char V_35 ;
if ( ! V_13 || ! V_2 || V_2 -> V_20 . V_36 != V_37 )
return V_38 ;
if ( ( V_35 = F_14 ( F_22 ( V_13 -> V_15 ) ) ) & 1 )
return V_38 ;
F_1 ( V_2 ) ;
do {
switch ( V_35 & 6 ) {
case 6 :
F_14 ( F_23 ( V_13 -> V_15 ) ) ;
break;
case 4 :
F_14 ( F_24 ( V_13 -> V_15 ) ) ;
break;
case 2 :
if ( F_25 ( & V_2 -> V_20 ) )
F_10 ( V_13 , V_2 ) ;
else {
F_13 ( V_13 , V_2 ) ;
V_2 -> V_16 . V_39 -- ;
}
F_5 ( 0x00 , F_9 ( V_13 -> V_15 ) ) ;
break;
default:
F_14 ( F_15 ( V_13 -> V_15 ) ) ;
break;
}
V_35 = F_14 ( F_22 ( V_13 -> V_15 ) ) ;
} while ( ! ( V_35 & 1 ) );
if ( V_2 -> V_16 . V_39 <= 0 ) {
V_2 -> V_16 . V_39 = F_26 ( V_2 ) ;
F_27 () ;
F_28 ( V_13 , & V_2 -> V_20 ) ;
}
F_27 () ;
F_29 ( V_13 , & V_2 -> V_20 ) ;
F_30 ( V_13 , & V_2 -> V_20 ) ;
F_31 () ;
return V_40 ;
}
static enum V_41 F_32 ( unsigned int V_42 )
{
unsigned char V_43 , V_44 , V_45 ;
enum V_41 V_46 ;
enum V_41 V_47 [] =
{ V_48 , V_49 , V_50 , V_51 } ;
V_43 = F_14 ( F_11 ( V_42 ) ) ;
F_5 ( V_43 | 0x10 , F_11 ( V_42 ) ) ;
V_44 = F_14 ( F_15 ( V_42 ) ) ;
F_5 ( 0x1a , F_11 ( V_42 ) ) ;
V_45 = F_14 ( F_15 ( V_42 ) ) & 0xf0 ;
F_5 ( V_43 , F_11 ( V_42 ) ) ;
F_5 ( V_44 , F_15 ( V_42 ) ) ;
if ( V_45 != 0x90 )
return V_49 ;
F_14 ( F_24 ( V_42 ) ) ;
F_14 ( F_24 ( V_42 ) ) ;
F_5 ( 0x01 , F_33 ( V_42 ) ) ;
V_46 = V_47 [ ( F_14 ( F_22 ( V_42 ) ) >> 6 ) & 3 ] ;
if ( V_46 == V_48 ) {
F_5 ( 0x5a , F_34 ( V_42 ) ) ;
V_43 = F_14 ( F_34 ( V_42 ) ) ;
F_5 ( 0xa5 , F_34 ( V_42 ) ) ;
V_44 = F_14 ( F_34 ( V_42 ) ) ;
if ( ( V_43 != 0x5a ) || ( V_44 != 0xa5 ) )
V_46 = V_52 ;
}
return V_46 ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_21 ( V_13 ) ;
enum V_41 V_46 ;
if ( ! V_13 || ! V_2 )
return - V_53 ;
if ( ! V_13 -> V_15 || V_13 -> V_15 > 0x1000 - V_54 ||
V_13 -> V_33 < 2 || V_13 -> V_33 > 15 )
return - V_53 ;
if ( ! F_36 ( V_13 -> V_15 , V_54 , L_1 ) )
return - V_55 ;
memset ( & V_2 -> V_16 , 0 , sizeof( V_2 -> V_16 ) ) ;
V_2 -> V_20 . V_56 . V_57 = 1200 ;
if ( ( V_46 = F_32 ( V_13 -> V_15 ) ) == V_49 ) {
F_37 ( V_13 -> V_15 , V_54 ) ;
return - V_58 ;
}
F_5 ( 0 , F_33 ( V_13 -> V_15 ) ) ;
F_5 ( 0x0d , F_11 ( V_13 -> V_15 ) ) ;
F_5 ( 0 , F_38 ( V_13 -> V_15 ) ) ;
if ( F_39 ( V_13 -> V_33 , F_20 , V_59 | V_60 ,
L_1 , V_13 ) ) {
F_37 ( V_13 -> V_15 , V_54 ) ;
return - V_61 ;
}
F_5 ( 2 , F_38 ( V_13 -> V_15 ) ) ;
F_4 ( V_13 , V_2 -> V_24 ? 6 : 4 ) ;
F_40 ( V_62 L_2 ,
V_63 , V_13 -> V_15 , V_13 -> V_33 , V_64 [ V_46 ] ) ;
return 0 ;
}
static int F_41 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_21 ( V_13 ) ;
if ( ! V_13 || ! V_2 )
return - V_65 ;
F_5 ( 0 , F_38 ( V_13 -> V_15 ) ) ;
F_5 ( 1 , F_11 ( V_13 -> V_15 ) ) ;
F_42 ( V_13 -> V_33 , V_13 ) ;
F_37 ( V_13 -> V_15 , V_54 ) ;
F_40 ( V_62 L_3 ,
V_63 , V_13 -> V_15 , V_13 -> V_33 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , const char * V_66 )
{
if ( strchr ( V_66 , '*' ) )
V_2 -> V_24 = 0 ;
else if ( strchr ( V_66 , '+' ) )
V_2 -> V_24 = - 1 ;
else if ( strchr ( V_66 , '@' ) )
V_2 -> V_24 = - 2 ;
else
V_2 -> V_24 = 1 ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 , struct V_67 * V_68 ,
struct V_69 * V_70 , int V_71 )
{
struct V_1 * V_2 ;
struct F_44 V_72 ;
if ( ! V_13 )
return - V_65 ;
V_2 = F_21 ( V_13 ) ;
F_45 ( V_2 -> V_20 . V_36 != V_37 ) ;
if ( V_71 != V_73 )
return - V_74 ;
switch ( V_70 -> V_71 ) {
default:
break;
case V_75 :
strcpy ( V_70 -> V_76 . V_77 , L_4 ) ;
if ( V_2 -> V_24 <= 0 )
strcat ( V_70 -> V_76 . V_77 , ( ! V_2 -> V_24 ) ? L_5 : ( V_2 -> V_24 == - 2 ) ? L_6 : L_7 ) ;
if ( F_46 ( V_68 -> V_78 , V_70 , sizeof( struct V_69 ) ) )
return - V_79 ;
return 0 ;
case V_80 :
if ( F_47 ( V_13 ) || ! F_48 ( V_81 ) )
return - V_55 ;
V_70 -> V_76 . V_77 [ sizeof( V_70 -> V_76 . V_77 ) - 1 ] = '\0' ;
return F_43 ( V_2 , V_70 -> V_76 . V_77 ) ;
case V_82 :
strcpy ( V_70 -> V_76 . V_77 , L_4 ) ;
if ( F_46 ( V_68 -> V_78 , V_70 , sizeof( struct V_69 ) ) )
return - V_79 ;
return 0 ;
case V_83 :
return V_84 | V_85 ;
}
if ( F_49 ( & V_72 , V_68 -> V_78 , sizeof( V_72 ) ) )
return - V_79 ;
switch ( V_72 . V_71 ) {
default:
return - V_74 ;
#ifdef F_2
case V_86 :
V_72 . V_76 . V_87 . V_88 = V_2 -> V_20 . V_89 ;
V_72 . V_76 . V_87 . V_90 = V_2 -> V_5 . V_9 ;
V_72 . V_76 . V_87 . V_91 = V_2 -> V_5 . V_10 ;
break;
#endif
}
if ( F_46 ( V_68 -> V_78 , & V_72 , sizeof( V_72 ) ) )
return - V_79 ;
return 0 ;
}
static int T_2 F_50 ( void )
{
int V_92 , V_93 = 0 ;
char V_94 = 1 ;
F_40 ( V_95 ) ;
for ( V_92 = 0 ; V_92 < V_96 ; V_92 ++ ) {
struct V_12 * V_13 ;
struct V_1 * V_2 ;
char V_97 [ V_98 ] ;
sprintf ( V_97 , L_8 , V_92 ) ;
if ( ! V_99 [ V_92 ] )
V_94 = 0 ;
if ( ! V_94 )
V_42 [ V_92 ] = V_33 [ V_92 ] = 0 ;
V_13 = F_51 ( & V_100 ,
sizeof( struct V_1 ) ,
V_97 , V_42 [ V_92 ] , V_33 [ V_92 ] , 0 ) ;
if ( F_52 ( V_13 ) )
break;
V_2 = F_21 ( V_13 ) ;
if ( V_94 && F_43 ( V_2 , V_99 [ V_92 ] ) )
V_94 = 0 ;
V_93 ++ ;
V_101 [ V_92 ] = V_13 ;
}
if ( ! V_93 )
return - V_53 ;
return 0 ;
}
static void T_3 F_53 ( void )
{
int V_92 ;
for( V_92 = 0 ; V_92 < V_96 ; V_92 ++ ) {
struct V_12 * V_13 = V_101 [ V_92 ] ;
if ( V_13 )
F_54 ( V_13 ) ;
}
}
static int T_2 F_55 ( char * V_102 )
{
static unsigned V_103 ;
int V_104 [ 3 ] ;
if ( V_103 >= V_96 )
return 0 ;
V_102 = F_56 ( V_102 , 3 , V_104 ) ;
if ( V_104 [ 0 ] < 2 )
return 0 ;
V_99 [ V_103 ] = V_102 ;
V_42 [ V_103 ] = V_104 [ 1 ] ;
V_33 [ V_103 ] = V_104 [ 2 ] ;
V_103 ++ ;
return 1 ;
}
