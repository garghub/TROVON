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
static void F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 = F_14 ( V_11 ) ;
unsigned int V_16 ;
#ifdef F_15
V_13 = V_2 -> V_17 [ F_16 ( F_17 () ) ] ;
#else
V_13 = V_2 -> V_17 [ 0 ] ;
#endif
F_18 ( V_15 , V_11 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_4 ; V_16 ++ ) {
int V_18 = V_16 * V_19 ;
unsigned long V_20 , V_21 ;
int V_22 ;
F_19 ( & V_2 -> V_23 , V_21 ) ;
V_20 = F_5 ( V_13 -> V_24 + F_1 ( V_2 , V_16 ) ) &
~ V_13 -> V_25 [ V_16 ] ;
F_20 ( & V_2 -> V_23 , V_21 ) ;
F_21 (hwirq, &pending, IRQS_PER_WORD) {
F_22 ( F_23 ( V_2 -> V_26 ,
V_18 + V_22 ) ) ;
}
}
F_24 ( V_15 , V_11 ) ;
}
static void F_25 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_1 * V_2 = F_26 ( V_28 ) ;
V_5 V_3 = V_28 -> V_22 / V_19 ;
V_5 V_30 = F_27 ( V_28 -> V_22 % V_19 ) ;
V_2 -> V_17 [ V_29 ] -> V_25 [ V_3 ] &= ~ V_30 ;
F_9 ( V_30 , V_2 -> V_17 [ V_29 ] -> V_24 +
F_4 ( V_2 , V_3 ) ) ;
}
static void F_28 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_1 * V_2 = F_26 ( V_28 ) ;
V_5 V_3 = V_28 -> V_22 / V_19 ;
V_5 V_30 = F_27 ( V_28 -> V_22 % V_19 ) ;
V_2 -> V_17 [ V_29 ] -> V_25 [ V_3 ] |= V_30 ;
F_9 ( V_30 , V_2 -> V_17 [ V_29 ] -> V_24 +
F_3 ( V_2 , V_3 ) ) ;
}
static void F_29 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_26 ( V_28 ) ;
unsigned long V_21 ;
F_19 ( & V_2 -> V_23 , V_21 ) ;
F_25 ( V_28 , V_2 -> V_31 [ V_28 -> V_22 ] ) ;
F_20 ( & V_2 -> V_23 , V_21 ) ;
}
static void F_30 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_26 ( V_28 ) ;
unsigned long V_21 ;
F_19 ( & V_2 -> V_23 , V_21 ) ;
F_28 ( V_28 , V_2 -> V_31 [ V_28 -> V_22 ] ) ;
F_20 ( & V_2 -> V_23 , V_21 ) ;
}
static int F_31 ( struct V_27 * V_28 ,
const struct V_32 * V_33 ,
bool V_34 )
{
struct V_1 * V_2 = F_26 ( V_28 ) ;
unsigned long V_21 ;
T_2 V_35 = V_28 -> V_22 ;
V_5 V_3 = V_35 / V_19 ;
V_5 V_30 = F_27 ( V_35 % V_19 ) ;
unsigned int V_36 = F_32 ( V_33 , V_37 ) ;
bool V_38 ;
F_19 ( & V_2 -> V_23 , V_21 ) ;
V_38 = ! ! ( V_2 -> V_17 [ V_2 -> V_31 [ V_35 ] ] -> V_25 [ V_3 ] &
V_30 ) ;
F_28 ( V_28 , V_2 -> V_31 [ V_35 ] ) ;
V_2 -> V_31 [ V_35 ] = V_36 ;
if ( ! V_38 )
F_25 ( V_28 , V_36 ) ;
F_20 ( & V_2 -> V_23 , V_21 ) ;
return 0 ;
}
static int T_3 F_33 ( struct V_39 * V_40 ,
unsigned int V_16 ,
struct V_1 * V_2 )
{
struct V_41 V_42 ;
T_4 V_43 ;
struct V_12 * V_13 ;
unsigned int V_44 , V_4 , V_45 ;
if ( F_34 ( V_40 , V_16 , & V_42 ) )
return - V_46 ;
V_43 = F_35 ( & V_42 ) ;
V_4 = V_43 / V_47 ;
if ( V_4 > V_48 )
return - V_46 ;
else if ( ! V_2 -> V_4 )
V_2 -> V_4 = V_4 ;
else if ( V_2 -> V_4 != V_4 )
return - V_46 ;
V_13 = V_2 -> V_17 [ V_16 ] = F_36 ( sizeof( * V_13 ) + V_4 * sizeof( V_5 ) ,
V_49 ) ;
if ( ! V_13 )
return - V_50 ;
V_13 -> V_24 = F_37 ( V_42 . V_51 , V_43 ) ;
if ( ! V_13 -> V_24 )
return - V_50 ;
for ( V_44 = 0 ; V_44 < V_4 ; V_44 ++ ) {
F_9 ( 0xffffffff , V_13 -> V_24 + F_3 ( V_2 , V_44 ) ) ;
V_13 -> V_25 [ V_44 ] = 0xffffffff ;
}
V_45 = F_38 ( V_40 , V_16 ) ;
if ( ! V_45 ) {
F_39 ( L_1 , V_45 ) ;
return - V_46 ;
}
F_40 ( V_45 , F_12 ,
V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_52 * V_28 , unsigned int V_53 ,
T_2 V_54 )
{
F_42 ( V_53 , & V_55 , V_56 ) ;
F_43 ( V_53 , V_28 -> V_57 ) ;
return 0 ;
}
int T_3 F_44 ( struct V_39 * V_40 ,
struct V_39 * V_58 )
{
struct V_1 * V_2 ;
int V_16 , V_59 ;
V_2 = F_36 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return - V_50 ;
F_45 ( & V_2 -> V_23 ) ;
F_46 (idx) {
V_59 = F_33 ( V_40 , V_16 , V_2 ) ;
if ( V_59 < 0 ) {
if ( V_16 )
break;
F_39 ( L_2 ) ;
goto V_60;
}
}
V_2 -> V_26 = F_47 ( V_40 , V_19 * V_2 -> V_4 ,
& V_61 ,
V_2 ) ;
if ( ! V_2 -> V_26 ) {
V_59 = - V_50 ;
goto V_62;
}
F_48 ( L_3 ,
V_2 -> V_17 [ 0 ] -> V_24 , V_19 * V_2 -> V_4 ) ;
return 0 ;
V_62:
F_46 (idx) {
struct V_12 * V_13 = V_2 -> V_17 [ V_16 ] ;
if ( V_13 ) {
if ( V_13 -> V_24 )
F_49 ( V_13 -> V_24 ) ;
F_50 ( V_13 ) ;
}
}
V_60:
F_50 ( V_2 ) ;
return V_59 ;
}
