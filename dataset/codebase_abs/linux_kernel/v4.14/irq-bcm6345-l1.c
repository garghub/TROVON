static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
#ifdef F_2
return ( 1 * V_2 -> V_4 - V_3 - 1 ) * sizeof( V_5 ) ;
#else
return ( 0 * V_2 -> V_4 + V_3 ) * sizeof( V_5 ) ;
#endif
}
static inline unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
#ifdef F_2
return ( 2 * V_2 -> V_4 - V_3 - 1 ) * sizeof( V_5 ) ;
#else
return ( 1 * V_2 -> V_4 + V_3 ) * sizeof( V_5 ) ;
#endif
}
static inline unsigned int F_4 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
return F_5 ( & V_2 -> V_8 , F_6 ( V_7 ) ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 = F_9 ( V_10 ) ;
unsigned int V_15 ;
#ifdef F_10
V_12 = V_2 -> V_16 [ F_11 ( F_12 () ) ] ;
#else
V_12 = V_2 -> V_16 [ 0 ] ;
#endif
F_13 ( V_14 , V_10 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_4 ; V_15 ++ ) {
int V_17 = V_15 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
unsigned int V_21 ;
V_19 = F_14 ( V_12 -> V_22 + F_3 ( V_2 , V_15 ) ) ;
V_19 &= F_14 ( V_12 -> V_22 + F_1 ( V_2 , V_15 ) ) ;
F_15 (hwirq, &pending, IRQS_PER_WORD) {
V_21 = F_16 ( V_2 -> V_23 , V_17 + V_20 ) ;
if ( V_21 )
F_17 ( V_21 ) ;
else
F_18 () ;
}
}
F_19 ( V_14 , V_10 ) ;
}
static inline void F_20 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_21 ( V_7 ) ;
V_5 V_3 = V_7 -> V_20 / V_18 ;
V_5 V_24 = F_22 ( V_7 -> V_20 % V_18 ) ;
unsigned int V_25 = F_4 ( V_2 , V_7 ) ;
V_2 -> V_16 [ V_25 ] -> V_26 [ V_3 ] |= V_24 ;
F_23 ( V_2 -> V_16 [ V_25 ] -> V_26 [ V_3 ] ,
V_2 -> V_16 [ V_25 ] -> V_22 + F_1 ( V_2 , V_3 ) ) ;
}
static inline void F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_21 ( V_7 ) ;
V_5 V_3 = V_7 -> V_20 / V_18 ;
V_5 V_24 = F_22 ( V_7 -> V_20 % V_18 ) ;
unsigned int V_25 = F_4 ( V_2 , V_7 ) ;
V_2 -> V_16 [ V_25 ] -> V_26 [ V_3 ] &= ~ V_24 ;
F_23 ( V_2 -> V_16 [ V_25 ] -> V_26 [ V_3 ] ,
V_2 -> V_16 [ V_25 ] -> V_22 + F_1 ( V_2 , V_3 ) ) ;
}
static void F_25 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_21 ( V_7 ) ;
unsigned long V_27 ;
F_26 ( & V_2 -> V_28 , V_27 ) ;
F_20 ( V_7 ) ;
F_27 ( & V_2 -> V_28 , V_27 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_21 ( V_7 ) ;
unsigned long V_27 ;
F_26 ( & V_2 -> V_28 , V_27 ) ;
F_24 ( V_7 ) ;
F_27 ( & V_2 -> V_28 , V_27 ) ;
}
static int F_29 ( struct V_6 * V_7 ,
const struct V_8 * V_29 ,
bool V_30 )
{
struct V_1 * V_2 = F_21 ( V_7 ) ;
V_5 V_3 = V_7 -> V_20 / V_18 ;
V_5 V_24 = F_22 ( V_7 -> V_20 % V_18 ) ;
unsigned int V_31 = F_4 ( V_2 , V_7 ) ;
unsigned int V_32 ;
struct V_8 V_33 ;
unsigned long V_27 ;
bool V_34 ;
if ( ! F_30 ( & V_33 , & V_2 -> V_8 , V_29 ) )
return - V_35 ;
V_32 = F_31 ( & V_33 , V_36 ) ;
if ( V_32 >= V_37 )
return - V_35 ;
V_29 = F_32 ( V_32 ) ;
F_26 ( & V_2 -> V_28 , V_27 ) ;
if ( V_31 != V_32 ) {
V_34 = V_2 -> V_16 [ V_31 ] -> V_26 [ V_3 ] & V_24 ;
if ( V_34 )
F_24 ( V_7 ) ;
F_33 ( F_6 ( V_7 ) , V_29 ) ;
if ( V_34 )
F_20 ( V_7 ) ;
} else {
F_33 ( F_6 ( V_7 ) , V_29 ) ;
}
F_27 ( & V_2 -> V_28 , V_27 ) ;
F_34 ( V_7 , F_32 ( V_32 ) ) ;
return V_38 ;
}
static int T_2 F_35 ( struct V_39 * V_40 ,
unsigned int V_15 ,
struct V_1 * V_2 )
{
struct V_41 V_42 ;
T_3 V_43 ;
struct V_11 * V_12 ;
unsigned int V_44 , V_4 ;
if ( F_36 ( V_40 , V_15 , & V_42 ) )
return - V_35 ;
V_43 = F_37 ( & V_42 ) ;
V_4 = V_43 / V_45 ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 = V_4 ;
else if ( V_2 -> V_4 != V_4 )
return - V_35 ;
V_12 = V_2 -> V_16 [ V_15 ] = F_38 ( sizeof( * V_12 ) + V_4 * sizeof( V_5 ) ,
V_46 ) ;
if ( ! V_12 )
return - V_47 ;
V_12 -> V_22 = F_39 ( V_42 . V_48 , V_43 ) ;
if ( ! V_12 -> V_22 )
return - V_47 ;
for ( V_44 = 0 ; V_44 < V_4 ; V_44 ++ ) {
V_12 -> V_26 [ V_44 ] = 0 ;
F_23 ( 0 , V_12 -> V_22 + F_1 ( V_2 , V_44 ) ) ;
}
V_12 -> V_49 = F_40 ( V_40 , V_15 ) ;
if ( ! V_12 -> V_49 ) {
F_41 ( L_1 , V_12 -> V_49 ) ;
return - V_35 ;
}
F_42 ( V_12 -> V_49 ,
F_7 , V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_50 * V_7 , unsigned int V_51 ,
T_1 V_52 )
{
F_44 ( V_51 ,
& V_53 , V_54 ) ;
F_45 ( V_51 , V_7 -> V_55 ) ;
F_46 ( F_47 ( F_48 ( V_51 ) ) ) ;
return 0 ;
}
static int T_2 F_49 ( struct V_39 * V_40 ,
struct V_39 * V_56 )
{
struct V_1 * V_2 ;
unsigned int V_15 ;
int V_57 ;
V_2 = F_38 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
F_50 (idx) {
V_57 = F_35 ( V_40 , V_15 , V_2 ) ;
if ( V_57 )
F_41 ( L_2 ,
V_15 , V_57 ) ;
else
F_51 ( V_15 , & V_2 -> V_8 ) ;
}
if ( ! F_52 ( & V_2 -> V_8 ) ) {
V_57 = - V_58 ;
goto V_59;
}
F_53 ( & V_2 -> V_28 ) ;
V_2 -> V_23 = F_54 ( V_40 , V_18 * V_2 -> V_4 ,
& V_60 ,
V_2 ) ;
if ( ! V_2 -> V_23 ) {
V_57 = - V_47 ;
goto V_61;
}
F_55 ( L_3 ,
V_18 * V_2 -> V_4 ) ;
F_56 (idx, &intc->cpumask) {
struct V_11 * V_12 = V_2 -> V_16 [ V_15 ] ;
F_55 ( L_4 , V_15 ,
V_12 -> V_22 , V_12 -> V_49 ) ;
}
return 0 ;
V_61:
F_50 (idx) {
struct V_11 * V_12 = V_2 -> V_16 [ V_15 ] ;
if ( V_12 ) {
if ( V_12 -> V_22 )
F_57 ( V_12 -> V_22 ) ;
F_58 ( V_12 ) ;
}
}
V_59:
F_58 ( V_2 ) ;
return V_57 ;
}
