void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 ;
int V_6 , V_7 ;
F_3 ( L_1 ,
L_2 , L_3 , L_4 , L_5 , L_6 ) ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
F_3 ( L_7 , V_7 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_8 [ V_7 ] ; V_6 ++ ) {
V_5 = & V_4 -> V_9 [ V_7 ] [ V_6 ] ;
if ( V_5 -> V_10 & V_11 )
F_3 ( L_8 ,
V_7 , V_6 , V_5 -> V_10 , V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 ) ;
}
}
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
F_3 ( L_9 , V_7 ) ;
for ( V_6 = 0 ; V_6 < V_4 -> V_15 [ V_7 ] ; V_6 ++ ) {
V_5 = & V_4 -> V_16 [ V_7 ] [ V_6 ] ;
if ( V_5 -> V_10 & V_11 )
F_3 ( L_10 ,
V_7 , V_6 , V_5 -> V_10 , V_5 -> V_12 ,
V_5 -> V_13 , V_5 -> V_14 ) ;
}
}
}
static inline unsigned int F_4 (
struct V_3 * V_4 )
{
unsigned int V_17 ;
V_17 = V_4 -> V_18 [ 0 ] ++ ;
if ( F_5 ( V_4 -> V_18 [ 0 ] >= V_19 ) )
V_4 -> V_18 [ 0 ] = 0 ;
return V_17 ;
}
static inline unsigned int F_6 ( void )
{
return V_20 - V_21 ;
}
static inline int F_7 ( struct V_5 * V_5 )
{
return V_5 -> V_13 & ( V_22 | V_23 ) ;
}
static inline T_1 F_8 ( T_1 V_13 , int V_24 )
{
V_13 &= V_25 ;
if ( ! V_24 ) {
V_13 &= ~ V_26 ;
V_13 |= ( V_13 & V_27 ) << 1 ;
}
return V_13 | V_27 ;
}
static inline T_1 F_9 ( T_1 V_12 , int V_24 )
{
#ifdef F_10
return ( V_12 & V_28 ) | V_29 ;
#else
return V_12 & V_28 ;
#endif
}
static inline void F_11 ( struct V_5 * V_30 )
{
F_12 ( V_31 , V_30 -> V_10 ) ;
F_12 ( V_32 , V_30 -> V_12 ) ;
F_12 ( V_33 , V_30 -> V_13 ) ;
F_12 ( V_34 , V_30 -> V_14 ) ;
__asm__ __volatile__ ("tlbwe\n" : : );
}
static inline void F_13 ( struct V_3 * V_4 ,
int V_7 , int V_35 )
{
struct V_5 * V_30 = & V_4 -> V_16 [ V_7 ] [ V_35 ] ;
F_14 () ;
if ( V_7 == 0 ) {
F_11 ( V_30 ) ;
} else {
unsigned register V_36 ;
V_36 = F_15 ( V_37 ) ;
F_12 ( V_37 , F_16 ( 1 ) | F_17 ( F_18 ( V_35 ) ) ) ;
F_11 ( V_30 ) ;
F_12 ( V_37 , V_36 ) ;
}
F_19 () ;
}
void F_20 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
unsigned register V_36 ;
F_14 () ;
V_36 = F_15 ( V_37 ) ;
for ( V_6 = 0 ; V_6 < F_6 () ; V_6 ++ ) {
struct V_5 * V_30 = & V_4 -> V_16 [ 1 ] [ V_6 ] ;
if ( F_21 ( V_30 ) ) {
F_12 ( V_37 , F_16 ( 1 )
| F_17 ( F_18 ( V_6 ) ) ) ;
F_11 ( V_30 ) ;
}
}
F_12 ( V_37 , V_36 ) ;
F_19 () ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 () ;
}
static int F_24 ( struct V_3 * V_4 ,
T_2 V_39 , int V_7 , unsigned int V_40 , int V_41 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_8 [ V_7 ] ; V_6 ++ ) {
struct V_5 * V_5 = & V_4 -> V_9 [ V_7 ] [ V_6 ] ;
unsigned int V_42 ;
if ( V_39 < F_25 ( V_5 ) )
continue;
if ( V_39 > F_26 ( V_5 ) )
continue;
V_42 = F_27 ( V_5 ) ;
if ( V_42 && ( V_42 != V_40 ) )
continue;
if ( ! F_21 ( V_5 ) )
continue;
if ( F_28 ( V_5 ) != V_41 && V_41 != - 1 )
continue;
return V_6 ;
}
return - 1 ;
}
static void F_29 ( struct V_3 * V_4 ,
int V_7 , int V_35 )
{
struct V_5 * V_30 = & V_4 -> V_16 [ V_7 ] [ V_35 ] ;
struct V_43 * V_43 = V_4 -> V_44 [ V_7 ] [ V_35 ] ;
if ( V_43 ) {
V_4 -> V_44 [ V_7 ] [ V_35 ] = NULL ;
if ( F_21 ( V_30 ) ) {
if ( F_7 ( V_30 ) )
F_30 ( V_43 ) ;
else
F_31 ( V_43 ) ;
}
}
}
static void F_32 ( struct V_3 * V_4 ,
int V_7 , int V_35 )
{
struct V_5 * V_30 = & V_4 -> V_16 [ V_7 ] [ V_35 ] ;
F_29 ( V_4 , V_7 , V_35 ) ;
V_30 -> V_10 = 0 ;
F_33 ( F_34 ( V_7 , V_35 ) ) ;
}
static void F_35 ( struct V_3 * V_4 ,
T_2 V_39 , T_2 V_45 , T_1 V_42 )
{
unsigned int V_40 = V_42 & 0xff ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_8 [ 1 ] ; V_6 ++ ) {
struct V_5 * V_30 = & V_4 -> V_16 [ 1 ] [ V_6 ] ;
unsigned int V_42 ;
if ( ! F_21 ( V_30 ) )
continue;
if ( V_45 < F_25 ( V_30 ) )
continue;
if ( V_39 > F_26 ( V_30 ) )
continue;
V_42 = F_27 ( V_30 ) ;
if ( V_42 && ( V_42 != V_40 ) )
continue;
F_32 ( V_4 , 1 , V_6 ) ;
F_13 ( V_4 , 1 , V_6 ) ;
}
}
static inline void F_36 ( struct V_1 * V_2 ,
unsigned int V_39 , int V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_17 , V_46 , V_47 ;
int V_7 ;
V_7 = ( V_4 -> V_48 >> 28 ) & 0x1 ;
V_17 = ( V_7 == 0 ) ? F_4 ( V_4 ) : 0 ;
V_46 = ( V_4 -> V_48 >> 16 ) & 0xf ;
V_47 = ( V_4 -> V_48 >> 7 ) & 0x1f ;
V_4 -> V_36 = F_16 ( V_7 ) | F_17 ( V_17 )
| F_37 ( V_4 -> V_18 [ V_7 ] ) ;
V_4 -> V_10 = V_11 | ( V_41 ? V_49 : 0 )
| F_38 ( V_4 -> V_40 [ V_46 ] )
| F_39 ( V_47 ) ;
V_4 -> V_12 = ( V_39 & V_50 )
| ( V_4 -> V_48 & V_28 ) ;
V_4 -> V_13 &= V_51 | V_52 | V_53 | V_54 ;
V_4 -> V_55 = ( V_4 -> V_55 & V_56 )
| ( F_40 ( V_2 ) << 16 )
| ( V_41 ? V_57 : 0 ) ;
V_4 -> V_14 = 0 ;
}
static inline void F_41 ( struct V_3 * V_4 ,
T_3 V_58 , T_4 V_59 , struct V_5 * V_60 , int V_7 , int V_35 )
{
struct V_43 * V_61 ;
struct V_5 * V_30 ;
T_5 V_62 ;
V_30 = & V_4 -> V_16 [ V_7 ] [ V_35 ] ;
V_61 = F_42 ( V_4 -> V_2 . V_63 , V_59 ) ;
if ( F_43 ( V_61 ) ) {
F_3 ( V_64 L_11 ,
( long ) V_59 ) ;
F_31 ( V_61 ) ;
return;
}
V_62 = F_44 ( V_61 ) ;
F_29 ( V_4 , V_7 , V_35 ) ;
V_4 -> V_44 [ V_7 ] [ V_35 ] = V_61 ;
V_30 -> V_10 = F_39 ( V_65 )
| F_38 ( F_27 ( V_60 ) ) | V_49 | V_11 ;
V_30 -> V_12 = ( V_58 & V_50 )
| F_9 ( V_60 -> V_12 ,
V_4 -> V_2 . V_66 . V_67 -> V_68 & V_69 ) ;
V_30 -> V_13 = ( V_62 & V_70 )
| F_8 ( V_60 -> V_13 ,
V_4 -> V_2 . V_66 . V_67 -> V_68 & V_69 ) ;
V_30 -> V_14 = ( V_62 >> 32 ) & V_71 ;
F_45 ( F_34 ( V_7 , V_35 ) , V_30 -> V_10 , V_30 -> V_12 ,
V_30 -> V_13 , V_30 -> V_14 ) ;
}
static int F_46 ( struct V_3 * V_4 ,
int V_7 , int V_35 )
{
struct V_5 * V_60 ;
V_60 = & V_4 -> V_9 [ V_7 ] [ V_35 ] ;
F_41 ( V_4 , F_25 ( V_60 ) ,
F_47 ( V_60 ) >> V_72 ,
V_60 , V_7 , V_35 ) ;
return V_35 ;
}
static int F_48 ( struct V_3 * V_4 ,
T_3 V_58 , T_4 V_59 , struct V_5 * V_60 )
{
unsigned int V_17 ;
V_17 = V_4 -> V_18 [ 1 ] ++ ;
if ( F_5 ( V_4 -> V_18 [ 1 ] >= F_6 () ) )
V_4 -> V_18 [ 1 ] = 0 ;
F_41 ( V_4 , V_58 , V_59 , V_60 , 1 , V_17 ) ;
return V_17 ;
}
void F_49 ( struct V_1 * V_2 , int V_24 )
{
if ( V_24 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_6 () ; V_6 ++ )
F_32 ( V_4 , 1 , V_6 ) ;
F_23 () ;
}
}
static int F_50 ( struct V_3 * V_4 ,
int V_7 , int V_35 )
{
struct V_5 * V_60 = & V_4 -> V_9 [ V_7 ] [ V_35 ] ;
if ( F_5 ( F_51 ( V_60 ) ) )
return - 1 ;
if ( V_7 == 1 ) {
F_35 ( V_4 , F_25 ( V_60 ) ,
F_26 ( V_60 ) ,
F_27 ( V_60 ) ) ;
} else {
F_32 ( V_4 , V_7 , V_35 ) ;
}
V_60 -> V_10 = 0 ;
return 0 ;
}
int F_52 ( struct V_3 * V_4 , T_6 V_73 )
{
int V_35 ;
if ( V_73 & V_74 )
for ( V_35 = 0 ; V_35 < V_4 -> V_8 [ 0 ] ; V_35 ++ )
F_50 ( V_4 , 0 , V_35 ) ;
if ( V_73 & V_75 )
for ( V_35 = 0 ; V_35 < V_4 -> V_8 [ 1 ] ; V_35 ++ )
F_50 ( V_4 , 1 , V_35 ) ;
F_23 () ;
return V_76 ;
}
int F_53 ( struct V_1 * V_2 , int V_77 , int V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_79 ;
int V_35 , V_7 ;
T_2 V_80 ;
V_80 = ( ( V_77 ) ? F_54 ( V_2 , V_77 ) : 0 ) + F_54 ( V_2 , V_78 ) ;
V_79 = ( V_80 >> 2 ) & 0x1 ;
V_7 = ( V_80 >> 3 ) & 0x1 ;
if ( V_79 ) {
for ( V_35 = 0 ; V_35 < V_4 -> V_8 [ V_7 ] ; V_35 ++ )
F_50 ( V_4 , V_7 , V_35 ) ;
} else {
V_80 &= 0xfffff000 ;
V_35 = F_24 ( V_4 , V_80 , V_7 ,
F_40 ( V_2 ) , - 1 ) ;
if ( V_35 >= 0 )
F_50 ( V_4 , V_7 , V_35 ) ;
}
F_23 () ;
return V_76 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_35 ;
struct V_5 * V_60 ;
V_7 = F_56 ( V_4 ) ;
V_35 = F_57 ( V_4 , V_7 ) ;
V_60 = & V_4 -> V_9 [ V_7 ] [ V_35 ] ;
V_4 -> V_36 &= ~ F_37 ( ~ 0 ) ;
V_4 -> V_36 |= F_37 ( V_4 -> V_18 [ V_7 ] ) ;
V_4 -> V_10 = V_60 -> V_10 ;
V_4 -> V_12 = V_60 -> V_12 ;
V_4 -> V_13 = V_60 -> V_13 ;
V_4 -> V_14 = V_60 -> V_14 ;
return V_76 ;
}
int F_58 ( struct V_1 * V_2 , int V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_41 = ! ! F_59 ( V_4 ) ;
unsigned int V_40 = F_60 ( V_4 ) ;
int V_35 , V_7 ;
struct V_5 * V_60 = NULL ;
T_2 V_80 ;
V_80 = F_54 ( V_2 , V_78 ) ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
V_35 = F_24 ( V_4 , V_80 , V_7 , V_40 , V_41 ) ;
if ( V_35 >= 0 ) {
V_60 = & V_4 -> V_9 [ V_7 ] [ V_35 ] ;
break;
}
}
if ( V_60 ) {
V_4 -> V_36 = F_16 ( V_7 ) | F_17 ( V_35 )
| F_37 ( V_4 -> V_18 [ V_7 ] ) ;
V_4 -> V_10 = V_60 -> V_10 ;
V_4 -> V_12 = V_60 -> V_12 ;
V_4 -> V_13 = V_60 -> V_13 ;
V_4 -> V_14 = V_60 -> V_14 ;
} else {
int V_17 ;
V_7 = V_4 -> V_48 >> 28 & 0x1 ;
V_17 = ( V_7 == 0 ) ? F_4 ( V_4 ) : 0 ;
V_4 -> V_36 = F_16 ( V_7 ) | F_17 ( V_17 )
| F_37 ( V_4 -> V_18 [ V_7 ] ) ;
V_4 -> V_10 = ( V_4 -> V_55 & V_81 )
| ( V_4 -> V_55 & ( V_57 ? V_49 : 0 ) )
| ( V_4 -> V_48 & F_61 ( ~ 0 ) ) ;
V_4 -> V_12 &= V_50 ;
V_4 -> V_12 |= V_4 -> V_48 & V_28 ;
V_4 -> V_13 &= V_51 | V_52 | V_53 | V_54 ;
V_4 -> V_14 = 0 ;
}
F_62 ( V_2 , V_82 ) ;
return V_76 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_39 ;
T_3 V_83 ;
T_1 V_42 ;
struct V_5 * V_60 ;
int V_7 , V_35 , V_84 , V_85 ;
V_7 = F_56 ( V_4 ) ;
V_35 = F_57 ( V_4 , V_7 ) ;
V_60 = & V_4 -> V_9 [ V_7 ] [ V_35 ] ;
if ( F_21 ( V_60 ) && V_7 == 1 ) {
V_39 = F_25 ( V_60 ) ;
V_42 = F_27 ( V_60 ) ;
F_35 ( V_4 , V_39 ,
F_26 ( V_60 ) , V_42 ) ;
}
V_60 -> V_10 = V_4 -> V_10 ;
V_60 -> V_12 = V_4 -> V_12 ;
V_60 -> V_13 = V_4 -> V_13 ;
V_60 -> V_14 = V_4 -> V_14 ;
F_64 ( V_4 -> V_36 , V_60 -> V_10 , V_60 -> V_12 ,
V_60 -> V_13 , V_60 -> V_14 ) ;
if ( F_65 ( V_2 , V_60 ) ) {
switch ( V_7 ) {
case 0 :
V_60 -> V_10 &= ~ F_39 ( ~ 0 ) ;
V_60 -> V_10 |= F_39 ( V_65 ) ;
V_84 = 0 ;
V_85 = F_46 ( V_4 , 0 , V_35 ) ;
break;
case 1 :
V_39 = F_25 ( V_60 ) ;
V_83 = F_47 ( V_60 ) ;
V_84 = 1 ;
V_85 = F_48 ( V_4 , V_39 ,
V_83 >> V_72 , V_60 ) ;
break;
default:
F_66 () ;
}
F_13 ( V_4 , V_84 , V_85 ) ;
}
F_62 ( V_2 , V_86 ) ;
return V_76 ;
}
int F_67 ( struct V_1 * V_2 , T_2 V_39 )
{
unsigned int V_41 = ! ! ( V_2 -> V_66 . V_67 -> V_68 & V_87 ) ;
return F_68 ( V_2 , V_39 , F_40 ( V_2 ) , V_41 ) ;
}
int F_69 ( struct V_1 * V_2 , T_2 V_39 )
{
unsigned int V_41 = ! ! ( V_2 -> V_66 . V_67 -> V_68 & V_88 ) ;
return F_68 ( V_2 , V_39 , F_40 ( V_2 ) , V_41 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
unsigned int V_41 = ! ! ( V_2 -> V_66 . V_67 -> V_68 & V_87 ) ;
F_36 ( V_2 , V_2 -> V_66 . V_89 , V_41 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
unsigned int V_41 = ! ! ( V_2 -> V_66 . V_67 -> V_68 & V_88 ) ;
F_36 ( V_2 , V_2 -> V_66 . V_90 , V_41 ) ;
}
T_7 F_72 ( struct V_1 * V_2 , unsigned int V_91 ,
T_2 V_39 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_60 =
& V_4 -> V_9 [ F_73 ( V_91 ) ] [ F_74 ( V_91 ) ] ;
T_3 V_92 = F_75 ( V_60 ) - 1 ;
return F_47 ( V_60 ) | ( V_39 & V_92 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_6 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ )
for ( V_6 = 0 ; V_6 < V_4 -> V_8 [ V_7 ] ; V_6 ++ )
F_29 ( V_4 , V_7 , V_6 ) ;
F_23 () ;
}
void F_77 ( struct V_1 * V_2 , T_3 V_39 , T_7 V_93 ,
unsigned int V_91 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = F_73 ( V_91 ) ;
int V_35 = F_74 ( V_91 ) ;
int V_84 , V_85 ;
switch ( V_7 ) {
case 0 :
V_84 = 0 ;
V_85 = V_35 ;
break;
case 1 : {
T_4 V_59 = V_93 >> V_72 ;
struct V_5 * V_60
= & V_4 -> V_9 [ V_7 ] [ V_35 ] ;
V_84 = 1 ;
V_85 = F_48 ( V_4 , V_39 , V_59 , V_60 ) ;
break;
}
default:
F_66 () ;
break;
}
F_13 ( V_4 , V_84 , V_85 ) ;
}
int F_68 ( struct V_1 * V_2 ,
T_2 V_39 , unsigned int V_40 , int V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_35 , V_7 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
V_35 = F_24 ( V_4 , V_39 , V_7 , V_40 , V_41 ) ;
if ( V_35 >= 0 )
return F_34 ( V_7 , V_35 ) ;
}
return - 1 ;
}
void F_78 ( struct V_1 * V_2 , T_1 V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_40 [ 0 ] = V_2 -> V_66 . V_94 =
V_2 -> V_66 . V_40 = V_40 ;
}
void F_79 ( struct V_3 * V_4 )
{
struct V_5 * V_5 ;
V_5 = & V_4 -> V_9 [ 1 ] [ 0 ] ;
V_5 -> V_10 = V_11 | F_39 ( V_95 ) ;
V_5 -> V_12 = 0 ;
V_5 -> V_13 = V_27 ;
V_5 -> V_14 = 0 ;
V_5 = & V_4 -> V_9 [ 1 ] [ 1 ] ;
V_5 -> V_10 = V_11 | F_39 ( V_65 ) ;
V_5 -> V_12 = ( 0xe0004500 & 0xFFFFF000 ) | V_96 | V_97 ;
V_5 -> V_13 = ( 0xe0004500 & 0xFFFFF000 ) | V_27 ;
V_5 -> V_14 = 0 ;
}
int F_80 ( struct V_3 * V_4 )
{
V_20 = F_15 ( V_98 ) & 0xFFF ;
V_4 -> V_8 [ 0 ] = V_99 ;
V_4 -> V_9 [ 0 ] =
F_81 ( sizeof( struct V_5 ) * V_99 , V_100 ) ;
if ( V_4 -> V_9 [ 0 ] == NULL )
goto V_101;
V_4 -> V_15 [ 0 ] = V_99 ;
V_4 -> V_16 [ 0 ] =
F_81 ( sizeof( struct V_5 ) * V_99 , V_100 ) ;
if ( V_4 -> V_16 [ 0 ] == NULL )
goto V_102;
V_4 -> V_8 [ 1 ] = V_103 ;
V_4 -> V_9 [ 1 ] =
F_81 ( sizeof( struct V_5 ) * V_103 , V_100 ) ;
if ( V_4 -> V_9 [ 1 ] == NULL )
goto V_104;
V_4 -> V_15 [ 1 ] = V_20 ;
V_4 -> V_16 [ 1 ] =
F_81 ( sizeof( struct V_5 ) * V_20 , V_100 ) ;
if ( V_4 -> V_16 [ 1 ] == NULL )
goto V_105;
V_4 -> V_44 [ 0 ] = (struct V_43 * * )
F_81 ( sizeof( struct V_43 * ) * V_99 , V_100 ) ;
if ( V_4 -> V_44 [ 0 ] == NULL )
goto V_106;
V_4 -> V_44 [ 1 ] = (struct V_43 * * )
F_81 ( sizeof( struct V_43 * ) * V_20 , V_100 ) ;
if ( V_4 -> V_44 [ 1 ] == NULL )
goto V_107;
V_4 -> V_108 = F_15 ( V_109 ) & ~ 0xfffUL ;
V_4 -> V_108 |= V_4 -> V_8 [ 0 ] ;
V_4 -> V_110 = F_15 ( V_98 ) & ~ 0xfffUL ;
V_4 -> V_110 |= V_4 -> V_8 [ 1 ] ;
return 0 ;
V_107:
F_82 ( V_4 -> V_44 [ 0 ] ) ;
V_106:
F_82 ( V_4 -> V_16 [ 1 ] ) ;
V_105:
F_82 ( V_4 -> V_9 [ 1 ] ) ;
V_104:
F_82 ( V_4 -> V_16 [ 0 ] ) ;
V_102:
F_82 ( V_4 -> V_9 [ 0 ] ) ;
V_101:
return - 1 ;
}
void F_83 ( struct V_3 * V_4 )
{
F_82 ( V_4 -> V_44 [ 1 ] ) ;
F_82 ( V_4 -> V_44 [ 0 ] ) ;
F_82 ( V_4 -> V_16 [ 1 ] ) ;
F_82 ( V_4 -> V_9 [ 1 ] ) ;
F_82 ( V_4 -> V_16 [ 0 ] ) ;
F_82 ( V_4 -> V_9 [ 0 ] ) ;
}
