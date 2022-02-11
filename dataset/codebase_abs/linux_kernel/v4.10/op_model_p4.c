static inline void F_1 ( void )
{
#ifdef F_2
if ( V_1 == 2 ) {
V_2 = V_3 ;
V_4 = V_5 ;
}
#endif
}
static inline int F_3 ( void )
{
#ifdef F_2
return V_1 == 2 ? 2 : 1 ;
#else
return 1 ;
#endif
}
static unsigned int F_4 ( void )
{
#ifdef F_2
int V_6 = F_5 () ;
return V_6 != F_6 ( F_7 ( V_7 ) ) ;
#endif
return 0 ;
}
static void F_8 ( struct V_8 const * const V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 ; ++ V_10 ) {
if ( V_9 -> V_11 [ V_10 ] . V_12 )
F_9 ( V_9 -> V_11 [ V_10 ] . V_12 ) ;
}
for ( V_10 = V_2 ; V_10 < V_4 ; ++ V_10 ) {
if ( V_9 -> V_13 [ V_10 ] . V_12 )
F_10 ( V_9 -> V_13 [ V_10 ] . V_12 ) ;
}
}
static int F_11 ( struct V_8 * const V_9 )
{
unsigned int V_10 ;
unsigned int V_12 , V_14 , V_15 ;
F_1 () ;
V_15 = F_4 () ;
for ( V_10 = 0 ; V_10 < V_2 ; ++ V_10 ) {
V_12 = V_16 [ F_12 ( V_15 , V_10 ) ] . V_17 ;
V_14 = V_16 [ F_12 ( V_15 , V_10 ) ] . V_18 ;
if ( F_13 ( V_12 ) ) {
V_9 -> V_11 [ V_10 ] . V_12 = V_12 ;
V_9 -> V_13 [ V_10 ] . V_12 = V_14 ;
}
}
for ( V_12 = V_19 + V_15 ;
V_12 < V_20 ; ++ V_10 , V_12 += F_3 () ) {
if ( F_14 ( V_12 ) )
V_9 -> V_13 [ V_10 ] . V_12 = V_12 ;
}
if ( V_21 . V_22 >= 0x3 ) {
for ( V_12 = V_19 + V_15 ;
V_12 <= V_23 ; ++ V_10 , V_12 += F_3 () ) {
if ( F_14 ( V_12 ) )
V_9 -> V_13 [ V_10 ] . V_12 = V_12 ;
}
} else {
for ( V_12 = V_20 + V_15 ;
V_12 <= V_24 ; ++ V_10 , V_12 += F_3 () ) {
if ( F_14 ( V_12 ) )
V_9 -> V_13 [ V_10 ] . V_12 = V_12 ;
}
}
for ( V_12 = V_25 + V_15 ;
V_12 <= V_26 ; ++ V_10 , V_12 += F_3 () ) {
if ( F_14 ( V_12 ) )
V_9 -> V_13 [ V_10 ] . V_12 = V_12 ;
}
for ( V_12 = V_27 + V_15 ;
V_12 <= V_28 ; ++ V_10 , V_12 += F_3 () ) {
if ( F_14 ( V_12 ) )
V_9 -> V_13 [ V_10 ] . V_12 = V_12 ;
}
for ( V_12 = V_29 + V_15 ;
V_12 <= V_30 ; ++ V_10 , V_12 += F_3 () ) {
if ( F_14 ( V_12 ) )
V_9 -> V_13 [ V_10 ] . V_12 = V_12 ;
}
if ( V_2 == V_31 ) {
if ( F_14 ( V_32 ) )
V_9 -> V_13 [ V_10 ++ ] . V_12 = V_32 ;
if ( F_14 ( V_33 ) )
V_9 -> V_13 [ V_10 ++ ] . V_12 = V_33 ;
} else if ( V_15 == 0 ) {
if ( F_14 ( V_33 ) )
V_9 -> V_13 [ V_10 ++ ] . V_12 = V_33 ;
} else {
if ( F_14 ( V_32 ) ) {
V_9 -> V_13 [ V_10 ++ ] . V_12 = V_32 ;
V_9 -> V_13 [ V_10 ++ ] . V_12 = V_32 ;
}
}
for ( V_10 = 0 ; V_10 < V_2 ; ++ V_10 ) {
if ( ! V_34 [ V_10 ] . V_35 )
continue;
if ( V_9 -> V_13 [ V_10 ] . V_12 )
continue;
F_15 ( V_10 ) ;
F_8 ( V_9 ) ;
return - V_36 ;
}
return 0 ;
}
static void F_16 ( unsigned int V_37 )
{
int V_10 ;
int const V_38 = 2 ;
unsigned int V_39 = 0 ;
unsigned int V_40 = 0 ;
unsigned int V_41 = 0 ;
unsigned int V_42 ;
struct V_43 * V_44 = NULL ;
unsigned int V_15 ;
V_15 = F_4 () ;
V_42 = 1 << F_12 ( V_15 , V_37 ) ;
if ( V_34 [ V_37 ] . V_45 <= 0 || V_34 [ V_37 ] . V_45 > V_46 ) {
F_17 ( V_47
L_1 ,
V_34 [ V_37 ] . V_45 ) ;
return;
}
V_44 = & ( V_48 [ V_34 [ V_37 ] . V_45 - 1 ] ) ;
for ( V_10 = 0 ; V_10 < V_38 ; V_10 ++ ) {
if ( V_44 -> V_49 [ V_10 ] . V_50 & V_42 ) {
F_18 ( V_44 -> V_49 [ V_10 ] . V_51 , V_40 , V_41 ) ;
F_19 ( V_40 ) ;
if ( V_15 == 0 ) {
F_20 ( V_40 , V_34 [ V_37 ] . V_52 ) ;
F_21 ( V_40 , V_34 [ V_37 ] . V_53 ) ;
} else {
F_22 ( V_40 , V_34 [ V_37 ] . V_52 ) ;
F_23 ( V_40 , V_34 [ V_37 ] . V_53 ) ;
}
F_24 ( V_40 , V_44 -> V_54 ) ;
F_25 ( V_40 , V_34 [ V_37 ] . V_55 ) ;
F_26 ( V_44 -> V_49 [ V_10 ] . V_51 , V_40 , V_41 ) ;
F_18 ( V_16 [ F_12 ( V_15 , V_37 ) ] . V_18 ,
V_39 , V_41 ) ;
F_27 ( V_39 ) ;
F_28 ( V_39 ) ;
F_29 ( V_39 , V_44 -> V_56 ) ;
if ( V_15 == 0 )
F_30 ( V_39 ) ;
else
F_31 ( V_39 ) ;
F_26 ( V_16 [ F_12 ( V_15 , V_37 ) ] . V_18 ,
V_39 , V_41 ) ;
return;
}
}
F_17 ( V_47
L_2 ,
V_34 [ V_37 ] . V_45 , V_15 , V_37 ) ;
}
static void F_32 ( struct V_57 const * V_58 ,
struct V_8 const * const V_9 )
{
unsigned int V_10 ;
unsigned int V_59 , V_41 ;
unsigned int V_15 ;
V_15 = F_4 () ;
F_18 ( V_60 , V_59 , V_41 ) ;
if ( ! F_33 ( V_59 ) ) {
F_17 ( V_47 L_3 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_2 ; V_10 ++ ) {
if ( F_34 ( ! V_9 -> V_13 [ V_10 ] . V_12 ) )
continue;
F_18 ( V_16 [ F_12 ( V_15 , V_10 ) ] . V_18 , V_59 , V_41 ) ;
F_27 ( V_59 ) ;
F_28 ( V_59 ) ;
F_26 ( V_16 [ F_12 ( V_15 , V_10 ) ] . V_18 , V_59 , V_41 ) ;
}
for ( V_10 = V_2 ; V_10 < V_4 ; V_10 ++ ) {
if ( F_34 ( ! V_9 -> V_13 [ V_10 ] . V_12 ) )
continue;
F_26 ( V_9 -> V_13 [ V_10 ] . V_12 , 0 , 0 ) ;
}
for ( V_10 = 0 ; V_10 < V_2 ; ++ V_10 ) {
if ( V_34 [ V_10 ] . V_35 && V_9 -> V_13 [ V_10 ] . V_12 ) {
V_61 [ V_10 ] = V_34 [ V_10 ] . V_62 ;
F_16 ( V_10 ) ;
F_35 ( V_16 [ F_12 ( V_15 , V_10 ) ] . V_17 ,
- ( V_63 ) V_34 [ V_10 ] . V_62 ) ;
} else {
V_61 [ V_10 ] = 0 ;
}
}
}
static int F_36 ( struct V_64 * const V_65 ,
struct V_8 const * const V_9 )
{
unsigned long V_37 , V_59 , V_41 , V_15 , V_66 ;
int V_10 ;
V_15 = F_4 () ;
for ( V_10 = 0 ; V_10 < V_2 ; ++ V_10 ) {
if ( ! V_61 [ V_10 ] )
continue;
V_66 = F_12 ( V_15 , V_10 ) ;
F_18 ( V_16 [ V_66 ] . V_18 , V_59 , V_41 ) ;
F_18 ( V_16 [ V_66 ] . V_17 , V_37 , V_41 ) ;
if ( F_37 ( V_59 ) || ! ( V_37 & V_67 ) ) {
F_38 ( V_65 , V_10 ) ;
F_35 ( V_16 [ V_66 ] . V_17 ,
- ( V_63 ) V_61 [ V_10 ] ) ;
F_39 ( V_59 ) ;
F_26 ( V_16 [ V_66 ] . V_18 , V_59 , V_41 ) ;
F_35 ( V_16 [ V_66 ] . V_17 ,
- ( V_63 ) V_61 [ V_10 ] ) ;
}
}
F_40 ( V_68 , F_41 ( V_68 ) & ~ V_69 ) ;
return 1 ;
}
static void F_42 ( struct V_8 const * const V_9 )
{
unsigned int V_59 , V_41 , V_15 ;
int V_10 ;
V_15 = F_4 () ;
for ( V_10 = 0 ; V_10 < V_2 ; ++ V_10 ) {
if ( ! V_61 [ V_10 ] )
continue;
F_18 ( V_16 [ F_12 ( V_15 , V_10 ) ] . V_18 , V_59 , V_41 ) ;
F_43 ( V_59 ) ;
F_26 ( V_16 [ F_12 ( V_15 , V_10 ) ] . V_18 , V_59 , V_41 ) ;
}
}
static void F_44 ( struct V_8 const * const V_9 )
{
unsigned int V_59 , V_41 , V_15 ;
int V_10 ;
V_15 = F_4 () ;
for ( V_10 = 0 ; V_10 < V_2 ; ++ V_10 ) {
if ( ! V_61 [ V_10 ] )
continue;
F_18 ( V_16 [ F_12 ( V_15 , V_10 ) ] . V_18 , V_59 , V_41 ) ;
F_45 ( V_59 ) ;
F_26 ( V_16 [ F_12 ( V_15 , V_10 ) ] . V_18 , V_59 , V_41 ) ;
}
}
