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
void F_22 ( struct V_1 * V_2 )
{
int V_14 ;
volatile struct V_11 V_12 ;
F_9 ( L_10 ) ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
V_12 = V_2 -> V_3 . V_30 [ F_2 () ] [ V_14 ] ;
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
static int F_23 ( struct V_7 * V_7 , T_2 V_31 )
{
int V_32 , V_33 = 0 ;
T_3 V_34 ;
if ( V_7 -> V_3 . V_35 [ V_31 ] != V_36 )
return 0 ;
V_32 = F_24 ( & V_7 -> V_37 ) ;
V_34 = F_25 ( V_7 , V_31 ) ;
if ( F_26 ( V_34 ) ) {
F_27 ( L_11 V_22 L_12 , V_31 ) ;
V_33 = - V_38 ;
goto V_39;
}
V_7 -> V_3 . V_35 [ V_31 ] = V_34 ;
V_39:
F_28 ( & V_7 -> V_37 , V_32 ) ;
return V_33 ;
}
unsigned long F_29 ( struct V_1 * V_2 ,
unsigned long V_40 )
{
T_2 V_31 ;
T_1 V_41 = V_40 & ~ V_42 ;
struct V_7 * V_7 = V_2 -> V_7 ;
if ( F_30 ( V_40 ) != V_43 ) {
F_27 ( L_13 , V_44 ,
F_31 ( 0 ) , V_40 ) ;
return V_36 ;
}
V_31 = ( F_32 ( V_40 ) >> V_45 ) ;
if ( V_31 >= V_7 -> V_3 . V_46 ) {
F_27 ( L_14 , V_44 , V_31 ,
V_40 ) ;
return V_36 ;
}
if ( F_23 ( V_2 -> V_7 , V_31 ) < 0 )
return V_47 ;
return ( V_7 -> V_3 . V_35 [ V_31 ] << V_45 ) + V_41 ;
}
int
F_33 ( struct V_1 * V_2 , unsigned long V_48 ,
unsigned long V_49 , unsigned long V_50 , int V_51 )
{
unsigned long V_13 ;
unsigned long V_9 ;
volatile int V_52 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
F_17 ( V_48 ) ;
F_11 () ;
F_34 () ;
F_35 () ;
V_52 = F_36 () ;
if ( V_52 > V_15 . V_16 ) {
F_27 ( L_15 , V_44 , V_52 ) ;
F_5 () ;
return - 1 ;
}
if ( V_52 < 0 ) {
V_52 = F_37 () % V_15 . V_16 ;
F_10 ( V_52 ) ;
F_11 () ;
}
F_38 ( V_49 ) ;
F_39 ( V_50 ) ;
F_11 () ;
F_40 () ;
F_13 () ;
#ifdef F_41
if ( V_53 ) {
F_42 ( L_16
L_17 ,
V_2 -> V_3 . V_54 , V_52 , F_7 () ,
F_14 () , F_15 () ) ;
}
#endif
if ( V_51 ) {
if ( V_49 & V_21 ) {
++ V_2 -> V_55 . V_56 ;
F_43 ( ( V_48 & V_57 ) & ~ V_51 ) ;
}
if ( V_50 & V_21 ) {
++ V_2 -> V_55 . V_56 ;
F_43 ( ( ( V_48 & V_57 ) & ~ V_51 ) |
( 0x1 << V_45 ) ) ;
}
}
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
return 0 ;
}
int F_44 ( unsigned long V_58 ,
struct V_1 * V_2 )
{
T_2 V_31 ;
T_3 V_59 , V_60 ;
unsigned long V_61 = 0 ;
unsigned long V_48 = 0 , V_49 = 0 , V_50 = 0 ;
int V_62 ;
struct V_7 * V_7 = V_2 -> V_7 ;
const int V_51 = 0 ;
if ( F_30 ( V_58 ) != V_43 ) {
F_27 ( L_18 , V_44 , V_58 ) ;
F_5 () ;
return - 1 ;
}
V_31 = ( F_32 ( V_58 ) >> V_45 ) ;
if ( V_31 >= V_7 -> V_3 . V_46 ) {
F_27 ( L_19 , V_44 ,
V_31 , V_58 ) ;
F_5 () ;
return - 1 ;
}
V_62 = ! ( V_31 & 0x1 ) ;
V_61 = V_58 & ( V_42 << 1 ) ;
if ( F_23 ( V_2 -> V_7 , V_31 ) < 0 )
return - 1 ;
if ( F_23 ( V_2 -> V_7 , V_31 ^ 0x1 ) < 0 )
return - 1 ;
if ( V_62 ) {
V_59 = V_7 -> V_3 . V_35 [ V_31 ] ;
V_60 = V_7 -> V_3 . V_35 [ V_31 ^ 0x1 ] ;
} else {
V_59 = V_7 -> V_3 . V_35 [ V_31 ^ 0x1 ] ;
V_60 = V_7 -> V_3 . V_35 [ V_31 ] ;
}
V_48 = ( V_61 | F_1 ( V_2 ) ) ;
V_49 = F_45 ( V_59 << V_45 ) | ( 0x3 << 3 ) | ( 1 << 2 ) |
( 0x1 << 1 ) ;
V_50 = F_45 ( V_60 << V_45 ) | ( 0x3 << 3 ) | ( 1 << 2 ) |
( 0x1 << 1 ) ;
return F_33 ( V_2 , V_48 , V_49 , V_50 ,
V_51 ) ;
}
int F_46 ( unsigned long V_58 ,
struct V_1 * V_2 )
{
T_3 V_59 , V_60 ;
unsigned long V_13 , V_9 = 0 , V_61 = 0 ;
unsigned long V_49 = 0 , V_50 = 0 ;
V_59 = F_47 ( V_2 -> V_3 . V_63 ) >> V_45 ;
V_60 = 0 ;
V_49 = F_45 ( V_59 << V_45 ) | ( 0x3 << 3 ) | ( 1 << 2 ) |
( 0x1 << 1 ) ;
V_50 = 0 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
V_61 = V_58 & ( V_42 << 1 ) ;
F_17 ( V_61 | F_1 ( V_2 ) ) ;
F_11 () ;
F_38 ( V_49 ) ;
F_11 () ;
F_39 ( V_50 ) ;
F_11 () ;
F_10 ( F_4 ( V_2 ) ) ;
F_11 () ;
F_40 () ;
F_11 () ;
F_13 () ;
#ifdef F_41
F_42 ( L_20 ,
V_2 -> V_3 . V_54 , F_36 () , F_7 () ,
F_14 () , F_15 () ) ;
#endif
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
return 0 ;
}
int
F_48 ( struct V_1 * V_2 ,
struct V_11 * V_12 , unsigned long * V_64 , unsigned long * V_65 )
{
unsigned long V_48 = 0 , V_49 = 0 , V_50 = 0 ;
struct V_7 * V_7 = V_2 -> V_7 ;
T_3 V_59 , V_60 ;
if ( ( V_12 -> V_17 & V_57 ) == 0 ) {
V_59 = 0 ;
V_60 = 0 ;
} else {
if ( F_23 ( V_7 , F_16 ( V_12 -> V_18 ) >> V_45 ) < 0 )
return - 1 ;
if ( F_23 ( V_7 , F_16 ( V_12 -> V_19 ) >> V_45 ) < 0 )
return - 1 ;
V_59 = V_7 -> V_3 . V_35 [ F_16 ( V_12 -> V_18 ) >> V_45 ] ;
V_60 = V_7 -> V_3 . V_35 [ F_16 ( V_12 -> V_19 ) >> V_45 ] ;
}
if ( V_64 )
* V_64 = V_59 << V_45 ;
if ( V_65 )
* V_65 = V_60 << V_45 ;
V_48 = ( V_12 -> V_17 & V_57 ) | ( F_49 ( V_2 ) ?
F_1 ( V_2 ) : F_3 ( V_2 ) ) ;
V_49 = F_45 ( V_59 << V_45 ) | ( 0x3 << 3 ) |
( V_12 -> V_18 & V_24 ) | ( V_12 -> V_18 & V_21 ) ;
V_50 = F_45 ( V_60 << V_45 ) | ( 0x3 << 3 ) |
( V_12 -> V_19 & V_24 ) | ( V_12 -> V_19 & V_21 ) ;
#ifdef F_41
F_42 ( L_21 , V_2 -> V_3 . V_54 ,
V_12 -> V_18 , V_12 -> V_19 ) ;
#endif
return F_33 ( V_2 , V_48 , V_49 , V_50 ,
V_12 -> V_20 ) ;
}
int F_50 ( struct V_1 * V_2 , unsigned long V_48 )
{
int V_14 ;
int V_66 = - 1 ;
struct V_11 * V_12 = V_2 -> V_3 . V_29 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
if ( ( ( F_51 ( V_12 [ V_14 ] ) & ~ V_12 [ V_14 ] . V_20 ) == ( ( V_48 & V_57 ) & ~ V_12 [ V_14 ] . V_20 ) ) &&
( F_52 ( V_12 [ V_14 ] ) || ( F_53 ( V_12 [ V_14 ] ) == ( V_48 & V_5 ) ) ) ) {
V_66 = V_14 ;
break;
}
}
#ifdef F_41
F_42 ( L_22 ,
V_44 , V_48 , V_66 , V_12 [ V_14 ] . V_18 , V_12 [ V_14 ] . V_19 ) ;
#endif
return V_66 ;
}
int F_54 ( struct V_1 * V_2 , unsigned long V_61 )
{
unsigned long V_9 , V_13 ;
volatile int V_52 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
if ( F_49 ( V_2 ) )
F_17 ( ( V_61 & V_57 ) | F_1 ( V_2 ) ) ;
else {
F_17 ( ( V_61 & V_57 ) | F_3 ( V_2 ) ) ;
}
F_11 () ;
F_34 () ;
F_35 () ;
V_52 = F_36 () ;
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
#ifdef F_41
F_42 ( L_23 , V_61 , V_52 ) ;
#endif
return V_52 ;
}
int F_55 ( struct V_1 * V_2 , unsigned long V_67 )
{
int V_52 ;
unsigned long V_13 , V_9 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
F_17 ( ( V_67 & V_57 ) | F_3 ( V_2 ) ) ;
F_11 () ;
F_34 () ;
F_35 () ;
V_52 = F_36 () ;
if ( V_52 >= V_15 . V_16 )
F_56 () ;
if ( V_52 > 0 ) {
F_17 ( F_57 ( V_52 ) ) ;
F_11 () ;
F_38 ( 0 ) ;
F_11 () ;
F_39 ( 0 ) ;
F_11 () ;
F_40 () ;
F_11 () ;
}
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
#ifdef F_41
if ( V_52 > 0 ) {
F_42 ( L_24 , V_44 ,
( V_67 & V_57 ) | ( V_2 -> V_3 . V_68 [ V_67 & V_5 ] & V_5 ) , V_52 ) ;
}
#endif
return 0 ;
}
int F_58 ( struct V_1 * V_2 , int V_66 )
{
unsigned long V_13 , V_9 ;
if ( V_66 >= V_15 . V_16 )
F_56 () ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
F_17 ( F_57 ( V_66 ) ) ;
F_11 () ;
F_10 ( V_66 ) ;
F_11 () ;
F_38 ( 0 ) ;
F_11 () ;
F_39 ( 0 ) ;
F_11 () ;
F_40 () ;
F_11 () ;
F_13 () ;
F_17 ( V_9 ) ;
F_11 () ;
F_13 () ;
F_19 ( V_13 ) ;
return 0 ;
}
void F_59 ( int V_69 )
{
unsigned long V_13 ;
unsigned long V_9 , V_48 ;
unsigned long V_10 ;
int V_70 = 0 ;
int V_71 = V_15 . V_16 ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
V_10 = F_8 () ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
F_10 ( V_70 ) ;
F_11 () ;
if ( V_69 ) {
F_12 () ;
F_13 () ;
V_48 = F_7 () ;
if ( F_30 ( V_48 ) == V_43 ) {
continue;
}
}
F_17 ( F_57 ( V_70 ) ) ;
F_11 () ;
F_38 ( 0 ) ;
F_11 () ;
F_39 ( 0 ) ;
F_11 () ;
F_40 () ;
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
F_60 ( struct V_72 * V_73 , unsigned long V_74 ,
struct V_1 * V_2 )
{
unsigned long V_75 = F_61 ( V_74 ) ;
if ( ! ( ( V_75 += V_76 ) & V_5 ) ) {
if ( V_77 ) {
F_62 () ;
}
F_63 () ;
if ( ! V_75 )
V_75 = V_78 ;
}
F_64 ( V_74 , V_73 ) = F_61 ( V_74 ) = V_75 ;
}
void F_65 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
unsigned long V_9 ;
unsigned long V_10 ;
int V_70 = 0 ;
int V_74 = F_2 () ;
F_6 ( V_13 ) ;
V_9 = F_7 () ;
V_10 = F_8 () ;
for ( V_70 = 0 ; V_70 < V_15 . V_16 ; V_70 ++ ) {
F_10 ( V_70 ) ;
F_11 () ;
F_12 () ;
F_13 () ;
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_17 = F_7 () ;
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_18 = F_14 () ;
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_19 = F_15 () ;
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_20 = F_8 () ;
}
F_17 ( V_9 ) ;
F_18 ( V_10 ) ;
F_11 () ;
F_19 ( V_13 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
unsigned long V_79 ;
int V_70 ;
int V_74 = F_2 () ;
F_6 ( V_13 ) ;
V_79 = F_7 () ;
for ( V_70 = 0 ; V_70 < V_15 . V_16 ; V_70 ++ ) {
F_17 ( V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_17 ) ;
F_11 () ;
F_38 ( V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_18 ) ;
F_39 ( V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_19 ) ;
F_10 ( V_70 ) ;
F_11 () ;
F_40 () ;
F_13 () ;
}
F_13 () ;
F_17 ( V_79 ) ;
F_11 () ;
F_19 ( V_13 ) ;
}
void F_63 ( void )
{
unsigned long V_13 ;
unsigned long V_79 ;
int V_70 = 0 ;
F_6 ( V_13 ) ;
V_79 = F_7 () ;
F_38 ( 0 ) ;
F_39 ( 0 ) ;
while ( V_70 < V_15 . V_16 ) {
F_17 ( F_57 ( V_70 ) ) ;
F_10 ( V_70 ) ;
F_11 () ;
F_40 () ;
V_70 ++ ;
}
F_13 () ;
F_17 ( V_79 ) ;
F_11 () ;
F_19 ( V_13 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
int V_74 , V_70 ;
F_68 (cpu) {
for ( V_70 = 0 ; V_70 < V_15 . V_16 ; V_70 ++ ) {
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_17 =
F_57 ( V_70 ) ;
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_18 = 0x0 ;
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_19 = 0x0 ;
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_20 =
F_8 () ;
#ifdef F_41
F_42
( L_25 ,
V_74 , V_70 ,
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_17 ,
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_18 ,
V_2 -> V_3 . V_30 [ V_74 ] [ V_70 ] . V_19 ) ;
#endif
}
}
}
void F_69 ( struct V_1 * V_2 , int V_74 )
{
unsigned long V_13 ;
int V_80 = 0 ;
#ifdef F_41
F_42 ( L_26 , V_44 , V_2 , V_74 ) ;
#endif
F_6 ( V_13 ) ;
if ( ( ( V_2 -> V_3 .
V_4 [ V_74 ] ^ F_61 ( V_74 ) ) & V_81 ) ) {
F_60 ( & V_2 -> V_3 . V_82 , V_74 , V_2 ) ;
V_2 -> V_3 . V_4 [ V_74 ] =
V_2 -> V_3 . V_82 . V_83 . V_75 [ V_74 ] ;
F_60 ( & V_2 -> V_3 . V_84 , V_74 , V_2 ) ;
V_2 -> V_3 . V_6 [ V_74 ] =
V_2 -> V_3 . V_84 . V_83 . V_75 [ V_74 ] ;
V_80 ++ ;
F_70 ( L_27 , V_74 ,
F_64 ( V_74 , V_85 -> V_73 ) ) ;
F_70 ( L_28 ,
V_74 , V_2 -> V_3 . V_4 [ V_74 ] ) ;
F_70 ( L_29 , V_74 ,
V_2 -> V_3 . V_6 [ V_74 ] ) ;
}
if ( V_2 -> V_3 . V_86 != V_74 ) {
F_70 ( L_30 ,
V_2 -> V_3 . V_86 , V_74 , V_2 -> V_87 ) ;
}
#if 0
if ((atomic_read(&kvm_mips_instance) > 1) && !newasid) {
kvm_mips_flush_host_tlb(0);
kvm_shadow_tlb_load(vcpu);
}
#endif
if ( ! V_80 ) {
if ( V_85 -> V_13 & V_88 ) {
F_17 ( V_2 -> V_3 .
V_89 & V_5 ) ;
F_71 () ;
}
} else {
if ( V_85 -> V_13 & V_88 ) {
if ( F_49 ( V_2 ) )
F_17 ( V_2 -> V_3 .
V_4 [ V_74 ] &
V_5 ) ;
else
F_17 ( V_2 -> V_3 .
V_6 [ V_74 ] &
V_5 ) ;
F_71 () ;
}
}
F_19 ( V_13 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
T_1 V_74 ;
F_6 ( V_13 ) ;
V_74 = F_2 () ;
V_2 -> V_3 . V_89 = F_7 () ;
V_2 -> V_3 . V_86 = V_74 ;
#if 0
if ((atomic_read(&kvm_mips_instance) > 1)) {
kvm_shadow_tlb_put(vcpu);
}
#endif
if ( ( ( F_64 ( V_74 , V_85 -> V_73 ) ^ F_61 ( V_74 ) ) &
V_81 ) ) {
F_42 ( L_31 , V_44 ,
F_64 ( V_74 , V_85 -> V_73 ) ) ;
F_73 ( V_85 -> V_73 , V_74 ) ;
}
F_17 ( F_74 ( V_74 , V_85 -> V_73 ) ) ;
F_71 () ;
F_19 ( V_13 ) ;
}
T_1 F_75 ( T_1 * V_90 , struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_3 . V_27 ;
unsigned long V_91 , V_13 ;
T_1 V_92 ;
int V_66 ;
if ( F_30 ( ( unsigned long ) V_90 ) < V_43 ||
F_30 ( ( unsigned long ) V_90 ) == V_93 ) {
F_6 ( V_13 ) ;
V_66 = F_54 ( V_2 , ( unsigned long ) V_90 ) ;
if ( V_66 >= 0 ) {
V_92 = * ( V_90 ) ;
} else {
V_66 =
F_50 ( V_2 ,
( ( unsigned long ) V_90 & V_57 )
|
( F_21
( V_27 ) & V_5 ) ) ;
if ( V_66 < 0 ) {
F_27
( L_32 ,
V_44 , V_90 , V_2 , F_7 () ) ;
F_5 () ;
F_19 ( V_13 ) ;
return V_94 ;
}
F_48 ( V_2 ,
& V_2 -> V_3 .
V_29 [ V_66 ] ,
NULL , NULL ) ;
V_92 = * ( V_90 ) ;
}
F_19 ( V_13 ) ;
} else if ( F_30 ( V_90 ) == V_43 ) {
V_91 =
F_29 ( V_2 ,
( unsigned long ) V_90 ) ;
V_92 = * ( T_1 * ) F_76 ( V_91 ) ;
} else {
F_27 ( L_33 , V_44 , V_90 ) ;
return V_94 ;
}
return V_92 ;
}
