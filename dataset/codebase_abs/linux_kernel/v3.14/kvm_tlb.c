T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 [ F_2 () ] & V_5 ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_6 [ F_2 () ] & V_5 ;
}
inline T_1 F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_7 -> V_3 . V_8 ;
}
void F_5 ( void )
{
unsigned long V_9 ;
unsigned long V_10 ;
struct V_11 V_12 ;
unsigned long V_13 ;
int V_14 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
V_10 = F_8 () ;
F_9 ( L_1 ) ;
F_9 ( L_2 , F_7 () & V_5 ) ;
for ( V_14 = 0 ; V_14 < V_15 . V_16 ; V_14 ++ ) {
F_10 ( V_14 ) ;
F_11 () ;
F_12 () ;
F_13 () ;
V_12 . V_17 = F_7 () ;
V_12 . V_18 = F_14 () ;
V_12 . V_19 = F_15 () ;
V_12 . V_20 = F_8 () ;
F_9 ( L_3 ,
( V_12 . V_18 | V_12 . V_19 ) & V_21 ? ' ' : '*' ,
V_14 , V_12 . V_17 ) ;
F_9 ( L_4 V_22 L_5 ,
( V_23 ) F_16 ( V_12 . V_18 ) ,
( V_12 . V_18 & V_24 ) ? 'D' : ' ' ,
( V_12 . V_18 & V_25 ) ? 'G' : ' ' ,
( V_12 . V_18 >> 3 ) & 7 ) ;
F_9 ( L_6 V_22 L_7 ,
( V_23 ) F_16 ( V_12 . V_19 ) ,
( V_12 . V_19 & V_24 ) ? 'D' : ' ' ,
( V_12 . V_19 & V_25 ) ? 'G' : ' ' ,
( V_12 . V_19 >> 3 ) & 7 , V_12 . V_20 ) ;
}
F_17 ( V_9 ) ;
F_18 ( V_10 ) ;
F_11 () ;
F_19 ( V_13 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_3 . V_27 ;
struct V_11 V_12 ;
int V_14 ;
F_9 ( L_8 ) ;
F_9 ( L_9 , F_21 ( V_27 ) ) ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
V_12 = V_2 -> V_3 . V_29 [ V_14 ] ;
F_9 ( L_3 ,
( V_12 . V_18 | V_12 . V_19 ) & V_21 ? ' ' : '*' ,
V_14 , V_12 . V_17 ) ;
F_9 ( L_4 V_22 L_5 ,
( V_23 ) F_16 ( V_12 . V_18 ) ,
( V_12 . V_18 & V_24 ) ? 'D' : ' ' ,
( V_12 . V_18 & V_25 ) ? 'G' : ' ' ,
( V_12 . V_18 >> 3 ) & 7 ) ;
F_9 ( L_6 V_22 L_7 ,
( V_23 ) F_16 ( V_12 . V_19 ) ,
( V_12 . V_19 & V_24 ) ? 'D' : ' ' ,
( V_12 . V_19 & V_25 ) ? 'G' : ' ' ,
( V_12 . V_19 >> 3 ) & 7 , V_12 . V_20 ) ;
}
}
static int F_22 ( struct V_7 * V_7 , T_2 V_30 )
{
int V_31 , V_32 = 0 ;
T_3 V_33 ;
if ( V_7 -> V_3 . V_34 [ V_30 ] != V_35 )
return 0 ;
V_31 = F_23 ( & V_7 -> V_36 ) ;
V_33 = F_24 ( V_7 , V_30 ) ;
if ( F_25 ( V_33 ) ) {
F_26 ( L_10 V_22 L_11 , V_30 ) ;
V_32 = - V_37 ;
goto V_38;
}
V_7 -> V_3 . V_34 [ V_30 ] = V_33 ;
V_38:
F_27 ( & V_7 -> V_36 , V_31 ) ;
return V_32 ;
}
unsigned long F_28 ( struct V_1 * V_2 ,
unsigned long V_39 )
{
T_2 V_30 ;
T_1 V_40 = V_39 & ~ V_41 ;
struct V_7 * V_7 = V_2 -> V_7 ;
if ( F_29 ( V_39 ) != V_42 ) {
F_26 ( L_12 , V_43 ,
F_30 ( 0 ) , V_39 ) ;
return V_35 ;
}
V_30 = ( F_31 ( V_39 ) >> V_44 ) ;
if ( V_30 >= V_7 -> V_3 . V_45 ) {
F_26 ( L_13 , V_43 , V_30 ,
V_39 ) ;
return V_35 ;
}
if ( F_22 ( V_2 -> V_7 , V_30 ) < 0 )
return V_46 ;
return ( V_7 -> V_3 . V_34 [ V_30 ] << V_44 ) + V_40 ;
}
int
F_32 ( struct V_1 * V_2 , unsigned long V_47 ,
unsigned long V_48 , unsigned long V_49 , int V_50 )
{
unsigned long V_13 ;
unsigned long V_9 ;
volatile int V_51 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
F_17 ( V_47 ) ;
F_11 () ;
F_33 () ;
F_34 () ;
V_51 = F_35 () ;
if ( V_51 > V_15 . V_16 ) {
F_26 ( L_14 , V_43 , V_51 ) ;
F_5 () ;
return - 1 ;
}
if ( V_51 < 0 ) {
V_51 = F_36 () % V_15 . V_16 ;
F_10 ( V_51 ) ;
F_11 () ;
}
F_37 ( V_48 ) ;
F_38 ( V_49 ) ;
F_11 () ;
F_39 () ;
F_13 () ;
#ifdef F_40
if ( V_52 ) {
F_41 ( L_15
L_16 ,
V_2 -> V_3 . V_53 , V_51 , F_7 () ,
F_14 () , F_15 () ) ;
}
#endif
if ( V_50 ) {
if ( V_48 & V_21 ) {
++ V_2 -> V_54 . V_55 ;
F_42 ( ( V_47 & V_56 ) & ~ V_50 ) ;
}
if ( V_49 & V_21 ) {
++ V_2 -> V_54 . V_55 ;
F_42 ( ( ( V_47 & V_56 ) & ~ V_50 ) |
( 0x1 << V_44 ) ) ;
}
}
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
return 0 ;
}
int F_43 ( unsigned long V_57 ,
struct V_1 * V_2 )
{
T_2 V_30 ;
T_3 V_58 , V_59 ;
unsigned long V_60 = 0 ;
unsigned long V_47 = 0 , V_48 = 0 , V_49 = 0 ;
int V_61 ;
struct V_7 * V_7 = V_2 -> V_7 ;
const int V_50 = 0 ;
if ( F_29 ( V_57 ) != V_42 ) {
F_26 ( L_17 , V_43 , V_57 ) ;
F_5 () ;
return - 1 ;
}
V_30 = ( F_31 ( V_57 ) >> V_44 ) ;
if ( V_30 >= V_7 -> V_3 . V_45 ) {
F_26 ( L_18 , V_43 ,
V_30 , V_57 ) ;
F_5 () ;
return - 1 ;
}
V_61 = ! ( V_30 & 0x1 ) ;
V_60 = V_57 & ( V_41 << 1 ) ;
if ( F_22 ( V_2 -> V_7 , V_30 ) < 0 )
return - 1 ;
if ( F_22 ( V_2 -> V_7 , V_30 ^ 0x1 ) < 0 )
return - 1 ;
if ( V_61 ) {
V_58 = V_7 -> V_3 . V_34 [ V_30 ] ;
V_59 = V_7 -> V_3 . V_34 [ V_30 ^ 0x1 ] ;
} else {
V_58 = V_7 -> V_3 . V_34 [ V_30 ^ 0x1 ] ;
V_59 = V_7 -> V_3 . V_34 [ V_30 ] ;
}
V_47 = ( V_60 | F_1 ( V_2 ) ) ;
V_48 = F_44 ( V_58 << V_44 ) | ( 0x3 << 3 ) | ( 1 << 2 ) |
( 0x1 << 1 ) ;
V_49 = F_44 ( V_59 << V_44 ) | ( 0x3 << 3 ) | ( 1 << 2 ) |
( 0x1 << 1 ) ;
return F_32 ( V_2 , V_47 , V_48 , V_49 ,
V_50 ) ;
}
int F_45 ( unsigned long V_57 ,
struct V_1 * V_2 )
{
T_3 V_58 , V_59 ;
unsigned long V_13 , V_9 = 0 , V_60 = 0 ;
unsigned long V_48 = 0 , V_49 = 0 ;
V_58 = F_46 ( V_2 -> V_3 . V_62 ) >> V_44 ;
V_59 = 0 ;
V_48 = F_44 ( V_58 << V_44 ) | ( 0x3 << 3 ) | ( 1 << 2 ) |
( 0x1 << 1 ) ;
V_49 = 0 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
V_60 = V_57 & ( V_41 << 1 ) ;
F_17 ( V_60 | F_1 ( V_2 ) ) ;
F_11 () ;
F_37 ( V_48 ) ;
F_11 () ;
F_38 ( V_49 ) ;
F_11 () ;
F_10 ( F_4 ( V_2 ) ) ;
F_11 () ;
F_39 () ;
F_11 () ;
F_13 () ;
#ifdef F_40
F_41 ( L_19 ,
V_2 -> V_3 . V_53 , F_35 () , F_7 () ,
F_14 () , F_15 () ) ;
#endif
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
return 0 ;
}
int
F_47 ( struct V_1 * V_2 ,
struct V_11 * V_12 , unsigned long * V_63 , unsigned long * V_64 )
{
unsigned long V_47 = 0 , V_48 = 0 , V_49 = 0 ;
struct V_7 * V_7 = V_2 -> V_7 ;
T_3 V_58 , V_59 ;
if ( ( V_12 -> V_17 & V_56 ) == 0 ) {
V_58 = 0 ;
V_59 = 0 ;
} else {
if ( F_22 ( V_7 , F_16 ( V_12 -> V_18 ) >> V_44 ) < 0 )
return - 1 ;
if ( F_22 ( V_7 , F_16 ( V_12 -> V_19 ) >> V_44 ) < 0 )
return - 1 ;
V_58 = V_7 -> V_3 . V_34 [ F_16 ( V_12 -> V_18 ) >> V_44 ] ;
V_59 = V_7 -> V_3 . V_34 [ F_16 ( V_12 -> V_19 ) >> V_44 ] ;
}
if ( V_63 )
* V_63 = V_58 << V_44 ;
if ( V_64 )
* V_64 = V_59 << V_44 ;
V_47 = ( V_12 -> V_17 & V_56 ) | ( F_48 ( V_2 ) ?
F_1 ( V_2 ) : F_3 ( V_2 ) ) ;
V_48 = F_44 ( V_58 << V_44 ) | ( 0x3 << 3 ) |
( V_12 -> V_18 & V_24 ) | ( V_12 -> V_18 & V_21 ) ;
V_49 = F_44 ( V_59 << V_44 ) | ( 0x3 << 3 ) |
( V_12 -> V_19 & V_24 ) | ( V_12 -> V_19 & V_21 ) ;
#ifdef F_40
F_41 ( L_20 , V_2 -> V_3 . V_53 ,
V_12 -> V_18 , V_12 -> V_19 ) ;
#endif
return F_32 ( V_2 , V_47 , V_48 , V_49 ,
V_12 -> V_20 ) ;
}
int F_49 ( struct V_1 * V_2 , unsigned long V_47 )
{
int V_14 ;
int V_65 = - 1 ;
struct V_11 * V_12 = V_2 -> V_3 . V_29 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
if ( ( ( F_50 ( V_12 [ V_14 ] ) & ~ V_12 [ V_14 ] . V_20 ) == ( ( V_47 & V_56 ) & ~ V_12 [ V_14 ] . V_20 ) ) &&
( F_51 ( V_12 [ V_14 ] ) || ( F_52 ( V_12 [ V_14 ] ) == ( V_47 & V_5 ) ) ) ) {
V_65 = V_14 ;
break;
}
}
#ifdef F_40
F_41 ( L_21 ,
V_43 , V_47 , V_65 , V_12 [ V_14 ] . V_18 , V_12 [ V_14 ] . V_19 ) ;
#endif
return V_65 ;
}
int F_53 ( struct V_1 * V_2 , unsigned long V_60 )
{
unsigned long V_9 , V_13 ;
volatile int V_51 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
if ( F_48 ( V_2 ) )
F_17 ( ( V_60 & V_56 ) | F_1 ( V_2 ) ) ;
else {
F_17 ( ( V_60 & V_56 ) | F_3 ( V_2 ) ) ;
}
F_11 () ;
F_33 () ;
F_34 () ;
V_51 = F_35 () ;
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
#ifdef F_40
F_41 ( L_22 , V_60 , V_51 ) ;
#endif
return V_51 ;
}
int F_54 ( struct V_1 * V_2 , unsigned long V_66 )
{
int V_51 ;
unsigned long V_13 , V_9 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
F_17 ( ( V_66 & V_56 ) | F_3 ( V_2 ) ) ;
F_11 () ;
F_33 () ;
F_34 () ;
V_51 = F_35 () ;
if ( V_51 >= V_15 . V_16 )
F_55 () ;
if ( V_51 > 0 ) {
F_17 ( F_56 ( V_51 ) ) ;
F_11 () ;
F_37 ( 0 ) ;
F_11 () ;
F_38 ( 0 ) ;
F_11 () ;
F_39 () ;
F_11 () ;
}
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
#ifdef F_40
if ( V_51 > 0 ) {
F_41 ( L_23 , V_43 ,
( V_66 & V_56 ) | ( V_2 -> V_3 . V_67 [ V_66 & V_5 ] & V_5 ) , V_51 ) ;
}
#endif
return 0 ;
}
int F_57 ( struct V_1 * V_2 , int V_65 )
{
unsigned long V_13 , V_9 ;
if ( V_65 >= V_15 . V_16 )
F_55 () ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
F_17 ( F_56 ( V_65 ) ) ;
F_11 () ;
F_10 ( V_65 ) ;
F_11 () ;
F_37 ( 0 ) ;
F_11 () ;
F_38 ( 0 ) ;
F_11 () ;
F_39 () ;
F_11 () ;
F_13 () ;
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
return 0 ;
}
void F_58 ( int V_68 )
{
unsigned long V_13 ;
unsigned long V_9 , V_47 ;
unsigned long V_10 ;
int V_69 = 0 ;
int V_70 = V_15 . V_16 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
V_10 = F_8 () ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
F_10 ( V_69 ) ;
F_11 () ;
if ( V_68 ) {
F_12 () ;
F_13 () ;
V_47 = F_7 () ;
if ( F_29 ( V_47 ) == V_42 ) {
continue;
}
}
F_17 ( F_56 ( V_69 ) ) ;
F_11 () ;
F_37 ( 0 ) ;
F_11 () ;
F_38 ( 0 ) ;
F_11 () ;
F_39 () ;
F_11 () ;
}
F_13 () ;
F_17 ( V_9 ) ;
F_18 ( V_10 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
}
void
F_59 ( struct V_71 * V_72 , unsigned long V_73 ,
struct V_1 * V_2 )
{
unsigned long V_74 = F_60 ( V_73 ) ;
if ( ! ( ( V_74 += V_75 ) & V_5 ) ) {
if ( V_76 ) {
F_61 () ;
}
F_62 () ;
if ( ! V_74 )
V_74 = V_77 ;
}
F_63 ( V_73 , V_72 ) = F_60 ( V_73 ) = V_74 ;
}
void F_62 ( void )
{
unsigned long V_13 ;
unsigned long V_78 ;
int V_69 = 0 ;
F_6 ( V_13 ) ;
V_78 = F_7 () ;
F_37 ( 0 ) ;
F_38 ( 0 ) ;
while ( V_69 < V_15 . V_16 ) {
F_17 ( F_56 ( V_69 ) ) ;
F_10 ( V_69 ) ;
F_11 () ;
F_39 () ;
V_69 ++ ;
}
F_13 () ;
F_17 ( V_78 ) ;
F_11 () ;
F_19 ( V_13 ) ;
}
void F_64 ( struct V_1 * V_2 , int V_73 )
{
unsigned long V_13 ;
int V_79 = 0 ;
#ifdef F_40
F_41 ( L_24 , V_43 , V_2 , V_73 ) ;
#endif
F_6 ( V_13 ) ;
if ( ( ( V_2 -> V_3 .
V_4 [ V_73 ] ^ F_60 ( V_73 ) ) & V_80 ) ) {
F_59 ( & V_2 -> V_3 . V_81 , V_73 , V_2 ) ;
V_2 -> V_3 . V_4 [ V_73 ] =
V_2 -> V_3 . V_81 . V_82 . V_74 [ V_73 ] ;
F_59 ( & V_2 -> V_3 . V_83 , V_73 , V_2 ) ;
V_2 -> V_3 . V_6 [ V_73 ] =
V_2 -> V_3 . V_83 . V_82 . V_74 [ V_73 ] ;
V_79 ++ ;
F_65 ( L_25 , V_73 ,
F_63 ( V_73 , V_84 -> V_72 ) ) ;
F_65 ( L_26 ,
V_73 , V_2 -> V_3 . V_4 [ V_73 ] ) ;
F_65 ( L_27 , V_73 ,
V_2 -> V_3 . V_6 [ V_73 ] ) ;
}
if ( V_2 -> V_3 . V_85 != V_73 ) {
F_65 ( L_28 ,
V_2 -> V_3 . V_85 , V_73 , V_2 -> V_86 ) ;
}
if ( ! V_79 ) {
if ( V_84 -> V_13 & V_87 ) {
F_17 ( V_2 -> V_3 .
V_88 & V_5 ) ;
F_66 () ;
}
} else {
if ( V_84 -> V_13 & V_87 ) {
if ( F_48 ( V_2 ) )
F_17 ( V_2 -> V_3 .
V_4 [ V_73 ] &
V_5 ) ;
else
F_17 ( V_2 -> V_3 .
V_6 [ V_73 ] &
V_5 ) ;
F_66 () ;
}
}
F_19 ( V_13 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
T_1 V_73 ;
F_6 ( V_13 ) ;
V_73 = F_2 () ;
V_2 -> V_3 . V_88 = F_7 () ;
V_2 -> V_3 . V_85 = V_73 ;
if ( ( ( F_63 ( V_73 , V_84 -> V_72 ) ^ F_60 ( V_73 ) ) &
V_80 ) ) {
F_41 ( L_29 , V_43 ,
F_63 ( V_73 , V_84 -> V_72 ) ) ;
F_68 ( V_84 -> V_72 , V_73 ) ;
}
F_17 ( F_69 ( V_73 , V_84 -> V_72 ) ) ;
F_66 () ;
F_19 ( V_13 ) ;
}
T_1 F_70 ( T_1 * V_89 , struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_3 . V_27 ;
unsigned long V_90 , V_13 ;
T_1 V_91 ;
int V_65 ;
if ( F_29 ( ( unsigned long ) V_89 ) < V_42 ||
F_29 ( ( unsigned long ) V_89 ) == V_92 ) {
F_6 ( V_13 ) ;
V_65 = F_53 ( V_2 , ( unsigned long ) V_89 ) ;
if ( V_65 >= 0 ) {
V_91 = * ( V_89 ) ;
} else {
V_65 =
F_49 ( V_2 ,
( ( unsigned long ) V_89 & V_56 )
|
( F_21
( V_27 ) & V_5 ) ) ;
if ( V_65 < 0 ) {
F_26
( L_30 ,
V_43 , V_89 , V_2 , F_7 () ) ;
F_5 () ;
F_19 ( V_13 ) ;
return V_93 ;
}
F_47 ( V_2 ,
& V_2 -> V_3 .
V_29 [ V_65 ] ,
NULL , NULL ) ;
V_91 = * ( V_89 ) ;
}
F_19 ( V_13 ) ;
} else if ( F_29 ( V_89 ) == V_42 ) {
V_90 =
F_28 ( V_2 ,
( unsigned long ) V_89 ) ;
V_91 = * ( T_1 * ) F_71 ( V_90 ) ;
} else {
F_26 ( L_31 , V_43 , V_89 ) ;
return V_93 ;
}
return V_91 ;
}
