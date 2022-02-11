static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return ( 0 * V_2 -> V_4 + V_3 ) * sizeof( V_5 ) ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return ( 1 * V_2 -> V_4 + V_3 ) * sizeof( V_5 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return ( 2 * V_2 -> V_4 + V_3 ) * sizeof( V_5 ) ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return ( 3 * V_2 -> V_4 + V_3 ) * sizeof( V_5 ) ;
}
static inline V_5 F_5 ( void T_1 * V_6 )
{
if ( F_6 ( V_7 ) && F_6 ( V_8 ) )
return F_7 ( V_6 ) ;
else
return F_8 ( V_6 ) ;
}
static inline void F_9 ( V_5 V_9 , void T_1 * V_6 )
{
if ( F_6 ( V_7 ) && F_6 ( V_8 ) )
F_10 ( V_9 , V_6 ) ;
else
F_11 ( V_9 , V_6 ) ;
}
static void F_12 ( unsigned int V_10 , struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 = F_14 ( V_12 ) ;
unsigned int V_17 ;
#ifdef F_15
V_14 = V_2 -> V_18 [ F_16 ( F_17 () ) ] ;
#else
V_14 = V_2 -> V_18 [ 0 ] ;
#endif
F_18 ( V_16 , V_12 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 ; V_17 ++ ) {
int V_19 = V_17 * V_20 ;
unsigned long V_21 , V_22 ;
int V_23 ;
F_19 ( & V_2 -> V_24 , V_22 ) ;
V_21 = F_5 ( V_14 -> V_25 + F_1 ( V_2 , V_17 ) ) &
~ V_14 -> V_26 [ V_17 ] ;
F_20 ( & V_2 -> V_24 , V_22 ) ;
F_21 (hwirq, &pending, IRQS_PER_WORD) {
F_22 ( F_23 ( V_2 -> V_27 ,
V_19 + V_23 ) ) ;
}
}
F_24 ( V_16 , V_12 ) ;
}
static void F_25 ( struct V_28 * V_29 , unsigned int V_30 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
V_5 V_3 = V_29 -> V_23 / V_20 ;
V_5 V_31 = F_27 ( V_29 -> V_23 % V_20 ) ;
V_2 -> V_18 [ V_30 ] -> V_26 [ V_3 ] &= ~ V_31 ;
F_9 ( V_31 , V_2 -> V_18 [ V_30 ] -> V_25 +
F_4 ( V_2 , V_3 ) ) ;
}
static void F_28 ( struct V_28 * V_29 , unsigned int V_30 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
V_5 V_3 = V_29 -> V_23 / V_20 ;
V_5 V_31 = F_27 ( V_29 -> V_23 % V_20 ) ;
V_2 -> V_18 [ V_30 ] -> V_26 [ V_3 ] |= V_31 ;
F_9 ( V_31 , V_2 -> V_18 [ V_30 ] -> V_25 +
F_3 ( V_2 , V_3 ) ) ;
}
static void F_29 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
unsigned long V_22 ;
F_19 ( & V_2 -> V_24 , V_22 ) ;
F_25 ( V_29 , V_2 -> V_32 [ V_29 -> V_23 ] ) ;
F_20 ( & V_2 -> V_24 , V_22 ) ;
}
static void F_30 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
unsigned long V_22 ;
F_19 ( & V_2 -> V_24 , V_22 ) ;
F_28 ( V_29 , V_2 -> V_32 [ V_29 -> V_23 ] ) ;
F_20 ( & V_2 -> V_24 , V_22 ) ;
}
static int F_31 ( struct V_28 * V_29 ,
const struct V_33 * V_34 ,
bool V_35 )
{
struct V_1 * V_2 = F_26 ( V_29 ) ;
unsigned long V_22 ;
T_2 V_36 = V_29 -> V_23 ;
V_5 V_3 = V_36 / V_20 ;
V_5 V_31 = F_27 ( V_36 % V_20 ) ;
unsigned int V_37 = F_32 ( V_34 , V_38 ) ;
bool V_39 ;
F_19 ( & V_2 -> V_24 , V_22 ) ;
V_39 = ! ! ( V_2 -> V_18 [ V_2 -> V_32 [ V_36 ] ] -> V_26 [ V_3 ] &
V_31 ) ;
F_28 ( V_29 , V_2 -> V_32 [ V_36 ] ) ;
V_2 -> V_32 [ V_36 ] = V_37 ;
if ( ! V_39 )
F_25 ( V_29 , V_37 ) ;
F_20 ( & V_2 -> V_24 , V_22 ) ;
return 0 ;
}
static int T_3 F_33 ( struct V_40 * V_41 ,
unsigned int V_17 ,
struct V_1 * V_2 )
{
struct V_42 V_43 ;
T_4 V_44 ;
struct V_13 * V_14 ;
unsigned int V_45 , V_4 , V_46 ;
if ( F_34 ( V_41 , V_17 , & V_43 ) )
return - V_47 ;
V_44 = F_35 ( & V_43 ) ;
V_4 = V_44 / V_48 ;
if ( V_4 > V_49 )
return - V_47 ;
else if ( ! V_2 -> V_4 )
V_2 -> V_4 = V_4 ;
else if ( V_2 -> V_4 != V_4 )
return - V_47 ;
V_14 = V_2 -> V_18 [ V_17 ] = F_36 ( sizeof( * V_14 ) + V_4 * sizeof( V_5 ) ,
V_50 ) ;
if ( ! V_14 )
return - V_51 ;
V_14 -> V_25 = F_37 ( V_43 . V_52 , V_44 ) ;
if ( ! V_14 -> V_25 )
return - V_51 ;
for ( V_45 = 0 ; V_45 < V_4 ; V_45 ++ ) {
F_9 ( 0xffffffff , V_14 -> V_25 + F_3 ( V_2 , V_45 ) ) ;
V_14 -> V_26 [ V_45 ] = 0xffffffff ;
}
V_46 = F_38 ( V_41 , V_17 ) ;
if ( ! V_46 ) {
F_39 ( L_1 , V_46 ) ;
return - V_47 ;
}
F_40 ( V_46 , V_2 ) ;
F_41 ( V_46 , F_12 ) ;
return 0 ;
}
static int F_42 ( struct V_53 * V_29 , unsigned int V_54 ,
T_2 V_55 )
{
F_43 ( V_54 , & V_56 , V_57 ) ;
F_44 ( V_54 , V_29 -> V_58 ) ;
return 0 ;
}
int T_3 F_45 ( struct V_40 * V_41 ,
struct V_40 * V_59 )
{
struct V_1 * V_2 ;
int V_17 , V_60 ;
V_2 = F_36 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
F_46 ( & V_2 -> V_24 ) ;
F_47 (idx) {
V_60 = F_33 ( V_41 , V_17 , V_2 ) ;
if ( V_60 < 0 ) {
if ( V_17 )
break;
F_39 ( L_2 ) ;
goto V_61;
}
}
V_2 -> V_27 = F_48 ( V_41 , V_20 * V_2 -> V_4 ,
& V_62 ,
V_2 ) ;
if ( ! V_2 -> V_27 ) {
V_60 = - V_51 ;
goto V_63;
}
F_49 ( L_3 ,
V_2 -> V_18 [ 0 ] -> V_25 , V_20 * V_2 -> V_4 ) ;
return 0 ;
V_63:
F_47 (idx) {
struct V_13 * V_14 = V_2 -> V_18 [ V_17 ] ;
if ( V_14 ) {
if ( V_14 -> V_25 )
F_50 ( V_14 -> V_25 ) ;
F_51 ( V_14 ) ;
}
}
V_61:
F_51 ( V_2 ) ;
return V_60 ;
}
