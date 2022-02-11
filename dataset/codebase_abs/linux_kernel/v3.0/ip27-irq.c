static inline int F_1 ( int V_1 , int V_2 )
{
struct V_3 * V_4 = V_3 ( F_2 ( V_1 ) ) ;
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
int V_9 ;
V_9 = F_3 ( V_4 -> V_10 , V_11 ) ;
if ( V_9 >= V_11 )
F_4 ( L_1 , V_1 ) ;
F_5 ( V_9 , V_4 -> V_10 ) ;
V_6 -> V_12 [ V_9 ] = V_2 ;
return V_9 ;
}
static inline int F_6 ( T_1 * V_13 , int V_2 )
{
int V_1 , V_14 ;
F_7 (cpu) {
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
for ( V_14 = V_15 ; V_14 < V_11 ; V_14 ++ )
if ( V_6 -> V_12 [ V_14 ] == V_2 ) {
* V_13 = V_1 ;
return V_14 ;
}
}
F_4 ( L_2 , V_2 ) ;
}
static int F_8 ( unsigned long V_16 )
{
int V_17 = 0 , V_18 ;
V_18 = 16 ; if ( V_16 >> 16 == 0 ) V_18 = 0 ; V_17 += V_18 ; V_16 >>= V_18 ;
V_18 = 8 ; if ( V_16 >> 8 == 0 ) V_18 = 0 ; V_17 += V_18 ; V_16 >>= V_18 ;
V_18 = 4 ; if ( V_16 >> 4 == 0 ) V_18 = 0 ; V_17 += V_18 ; V_16 >>= V_18 ;
V_18 = 2 ; if ( V_16 >> 2 == 0 ) V_18 = 0 ; V_17 += V_18 ; V_16 >>= V_18 ;
V_18 = 1 ; if ( V_16 >> 1 == 0 ) V_18 = 0 ; V_17 += V_18 ;
return V_17 ;
}
static void F_9 ( void )
{
int V_2 , V_19 ;
T_2 V_20 , V_21 ;
T_1 V_1 = F_10 () ;
int V_22 =
( F_11 ( V_1 ) == 0 ) ? V_23 : V_24 ;
V_20 = F_12 ( V_25 ) ;
V_21 = F_12 ( V_22 ) ;
V_20 &= V_21 ;
if ( ! V_20 )
return;
V_19 = F_8 ( V_20 ) ;
#ifdef F_13
if ( V_20 & ( 1UL << V_26 ) ) {
F_14 ( V_26 ) ;
F_15 () ;
} else if ( V_20 & ( 1UL << V_27 ) ) {
F_14 ( V_27 ) ;
F_15 () ;
} else if ( V_20 & ( 1UL << V_28 ) ) {
F_14 ( V_28 ) ;
F_16 () ;
} else if ( V_20 & ( 1UL << V_29 ) ) {
F_14 ( V_29 ) ;
F_16 () ;
} else
#endif
{
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
V_2 = V_6 -> V_12 [ V_19 ] ;
F_17 ( V_2 ) ;
}
F_12 ( V_25 ) ;
}
static void F_18 ( void )
{
int V_2 , V_19 ;
T_2 V_30 , V_31 ;
T_1 V_1 = F_10 () ;
int V_32 = ( F_11 ( V_1 ) == 0 ) ? V_33 : V_34 ;
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
V_30 = F_12 ( V_35 ) ;
V_31 = F_12 ( V_32 ) ;
V_30 &= V_31 ;
if ( ! V_30 )
return;
V_19 = F_8 ( V_30 ) ;
V_2 = V_6 -> V_12 [ V_19 ] ;
F_14 ( V_19 ) ;
F_17 ( V_2 ) ;
F_12 ( V_35 ) ;
}
static void F_19 ( void )
{
F_4 ( L_3 , F_10 () ) ;
}
static void F_20 ( void )
{
F_4 ( L_4 , F_10 () ) ;
}
static int F_21 ( int V_1 , int V_36 )
{
T_3 V_37 = F_22 ( F_2 ( V_1 ) ) ;
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
F_23 ( V_36 , V_6 -> V_38 ) ;
if ( ! F_11 ( V_1 ) ) {
F_24 ( V_37 , V_23 , V_6 -> V_38 [ 0 ] ) ;
F_24 ( V_37 , V_33 , V_6 -> V_38 [ 1 ] ) ;
} else {
F_24 ( V_37 , V_24 , V_6 -> V_38 [ 0 ] ) ;
F_24 ( V_37 , V_34 , V_6 -> V_38 [ 1 ] ) ;
}
return 0 ;
}
static int F_25 ( int V_1 , int V_36 )
{
T_3 V_37 = F_22 ( F_2 ( V_1 ) ) ;
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
F_26 ( V_36 , V_6 -> V_38 ) ;
if ( ! F_11 ( V_1 ) ) {
F_24 ( V_37 , V_23 , V_6 -> V_38 [ 0 ] ) ;
F_24 ( V_37 , V_33 , V_6 -> V_38 [ 1 ] ) ;
} else {
F_24 ( V_37 , V_24 , V_6 -> V_38 [ 0 ] ) ;
F_24 ( V_37 , V_34 , V_6 -> V_38 [ 1 ] ) ;
}
return 0 ;
}
static unsigned int F_27 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
T_4 V_43 ;
T_5 * V_44 ;
int V_45 , V_19 ;
T_1 V_1 ;
V_45 = F_28 ( V_40 -> V_2 ) ;
V_42 = F_29 ( V_40 -> V_2 ) ;
V_44 = V_42 -> V_46 ;
F_30 ( L_5 , V_40 -> V_2 , V_45 ) ;
V_19 = F_6 ( & V_1 , V_40 -> V_2 ) ;
V_44 -> V_47 [ V_45 ] . V_48 = ( 0x20000 | V_19 | ( V_42 -> V_37 << 8 ) ) ;
V_44 -> V_49 |= ( 1 << V_45 ) ;
V_44 -> V_49 |= 0x7ffffe00 ;
V_44 -> V_50 |= ( 1UL << V_45 ) ;
V_43 = V_44 -> V_51 ;
V_43 &= ~ ( 7 << ( V_45 * 3 ) ) ;
V_43 |= ( V_45 << ( V_45 * 3 ) ) ;
V_44 -> V_51 = V_43 ;
V_44 -> V_52 ;
F_21 ( V_1 , V_19 ) ;
return 0 ;
}
static void F_31 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_29 ( V_40 -> V_2 ) ;
T_5 * V_44 = V_42 -> V_46 ;
int V_45 , V_19 ;
T_1 V_1 ;
F_30 ( L_6 , V_40 -> V_2 ) ;
V_45 = F_28 ( V_40 -> V_2 ) ;
V_19 = F_6 ( & V_1 , V_40 -> V_2 ) ;
F_25 ( V_1 , V_19 ) ;
V_44 -> V_49 &= ~ ( 1 << V_45 ) ;
V_44 -> V_52 ;
}
static inline void F_32 ( struct V_39 * V_40 )
{
T_1 V_1 ;
int V_19 ;
V_19 = F_6 ( & V_1 , V_40 -> V_2 ) ;
F_21 ( V_1 , V_19 ) ;
}
static inline void F_33 ( struct V_39 * V_40 )
{
T_1 V_1 ;
int V_19 ;
V_19 = F_6 ( & V_1 , V_40 -> V_2 ) ;
F_25 ( V_1 , V_19 ) ;
}
void T_6 F_34 ( unsigned int V_2 )
{
F_35 ( V_2 , & V_53 , V_54 ) ;
}
int T_6 F_36 ( struct V_41 * V_42 )
{
int V_2 = F_37 () ;
int V_19 , V_1 ;
T_3 V_37 ;
if ( V_2 < 0 )
return V_2 ;
V_1 = V_42 -> V_55 ;
V_19 = F_1 ( V_1 , V_2 ) ;
if ( F_38 ( V_19 < 0 ) ) {
F_39 ( V_2 ) ;
return - V_56 ;
}
V_37 = F_22 ( F_2 ( V_1 ) ) ;
F_40 ( V_37 , V_19 ) ;
F_21 ( V_1 , V_19 ) ;
F_34 ( V_2 ) ;
return V_2 ;
}
T_7 void F_41 ( void )
{
unsigned long V_57 = F_42 () & F_43 () ;
extern unsigned int V_58 ;
if ( V_57 & V_59 )
F_17 ( V_58 ) ;
else if ( V_57 & V_60 )
F_9 () ;
else if ( V_57 & V_61 )
F_18 () ;
else if ( V_57 & V_62 )
F_19 () ;
else if ( V_57 & V_63 )
F_20 () ;
}
void T_8 F_44 ( void )
{
}
void F_45 ( void )
{
int V_64 = F_12 ( V_65 ) ;
int V_1 = F_10 () ;
struct V_5 * V_6 = V_7 [ V_1 ] . V_8 ;
struct V_3 * V_4 = V_3 ( F_2 ( V_1 ) ) ;
int V_66 , V_67 ;
V_66 = V_26 + V_64 ;
F_5 ( V_66 , V_4 -> V_10 ) ;
F_5 ( V_66 , V_6 -> V_38 ) ;
F_14 ( V_66 ) ;
V_67 = V_28 + V_64 ;
F_5 ( V_67 , V_4 -> V_10 ) ;
F_5 ( V_67 , V_6 -> V_38 ) ;
F_14 ( V_67 ) ;
if ( V_64 == 0 ) {
F_46 ( V_23 , V_6 -> V_38 [ 0 ] ) ;
F_46 ( V_33 , V_6 -> V_38 [ 1 ] ) ;
} else {
F_46 ( V_24 , V_6 -> V_38 [ 0 ] ) ;
F_46 ( V_34 , V_6 -> V_38 [ 1 ] ) ;
}
}
