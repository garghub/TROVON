static inline const struct V_1 * T_1
F_1 ( const struct V_2 * V_3 )
{
const struct V_4 * V_5 ;
const struct V_6 * V_6 ;
V_5 = F_2 ( V_3 -> V_7 ) ;
V_6 = F_3 ( V_5 , struct V_6 , V_8 ) ;
return & V_6 -> V_9 ;
}
static inline void F_4 ( const struct V_2 * V_3 , int V_10 )
{
F_5 ( V_11 , V_10 ) ;
}
static inline void F_6 ( const struct V_2 * V_3 , int V_10 )
{
F_5 ( V_12 , V_10 ) ;
}
static inline int F_7 ( const struct V_2 * V_3 )
{
return ! ! F_8 ( V_13 ) ;
}
static T_2 F_9 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
return F_10 ( V_3 , V_14 , 0 , 0 , V_15 , V_16 ) ;
}
static T_2 F_11 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
return F_12 ( V_3 , V_14 , 0 , 0 , V_15 , V_16 ) ;
}
static T_2 F_13 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
return F_10 ( V_3 , V_14 , 1 , 0 , V_15 , V_16 ) ;
}
static T_2 F_14 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
return F_12 ( V_3 , V_14 , 1 , 0 , V_15 , V_16 ) ;
}
static T_2 F_15 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
unsigned V_17 = V_3 -> V_7 -> V_17 ;
return F_10 ( V_3 , V_14 , 0 , V_17 , V_15 , V_16 ) ;
}
static T_2 F_16 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
unsigned V_17 = V_3 -> V_7 -> V_17 ;
return F_12 ( V_3 , V_14 , 0 , V_17 , V_15 , V_16 ) ;
}
static T_2 F_17 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
unsigned V_17 = V_3 -> V_7 -> V_17 ;
return F_10 ( V_3 , V_14 , 1 , V_17 , V_15 , V_16 ) ;
}
static T_2 F_18 ( struct V_2 * V_3 ,
unsigned V_14 , T_2 V_15 , T_3 V_16 )
{
unsigned V_17 = V_3 -> V_7 -> V_17 ;
return F_12 ( V_3 , V_14 , 1 , V_17 , V_15 , V_16 ) ;
}
static void F_19 ( struct V_2 * V_3 , int V_18 )
{
unsigned long V_19 = ( unsigned long ) V_3 -> V_20 ;
if ( V_18 )
F_4 ( V_3 , V_3 -> V_21 & V_22 ) ;
if ( V_19 != V_23 ) {
F_5 ( V_19 , ( V_3 -> V_21 & V_24 ) ? V_18 : ! V_18 ) ;
}
}
static int F_20 ( struct V_2 * V_3 )
{
unsigned long V_19 = ( unsigned long ) V_3 -> V_20 ;
int V_25 = 0 ;
if ( V_3 -> V_26 > 32 )
return - V_27 ;
if ( ! V_3 -> V_28 ) {
if ( V_19 != V_23 ) {
V_25 = F_21 ( V_19 , F_22 ( & V_3 -> V_29 ) ) ;
if ( V_25 )
return V_25 ;
V_25 = F_23 ( V_19 , V_3 -> V_21 & V_24 ) ;
}
}
if ( ! V_25 )
V_25 = F_24 ( V_3 ) ;
if ( V_25 ) {
if ( ! V_3 -> V_28 && V_19 != V_23 )
F_25 ( V_19 ) ;
}
return V_25 ;
}
static void F_26 ( struct V_2 * V_3 )
{
unsigned long V_19 = ( unsigned long ) V_3 -> V_20 ;
if ( V_19 != V_23 )
F_25 ( V_19 ) ;
F_27 ( V_3 ) ;
}
static int T_4 F_28 ( unsigned V_30 , const char * V_31 , bool V_32 )
{
int V_33 ;
V_33 = F_21 ( V_30 , V_31 ) ;
if ( V_33 == 0 ) {
if ( V_32 )
V_33 = F_29 ( V_30 ) ;
else
V_33 = F_23 ( V_30 , 0 ) ;
}
return V_33 ;
}
static int T_4
F_30 ( struct V_1 * V_9 , const char * V_31 ,
T_5 * V_34 )
{
int V_33 ;
if ( V_12 != V_35 ) {
V_33 = F_28 ( V_12 , V_31 , false ) ;
if ( V_33 )
goto V_36;
} else {
* V_34 |= V_37 ;
}
if ( V_13 != V_38 ) {
V_33 = F_28 ( V_13 , V_31 , true ) ;
if ( V_33 )
goto V_39;
} else {
* V_34 |= V_40 ;
}
V_33 = F_28 ( V_11 , V_31 , false ) ;
if ( V_33 )
goto V_41;
goto V_36;
V_41:
if ( V_13 != V_38 )
F_25 ( V_13 ) ;
V_39:
if ( V_12 != V_35 )
F_25 ( V_12 ) ;
V_36:
return V_33 ;
}
static int T_4 F_31 ( struct V_42 * V_43 )
{
int V_25 ;
struct V_44 * V_7 ;
struct V_6 * V_6 ;
struct V_1 * V_9 ;
T_5 V_45 = 0 ;
V_9 = V_43 -> V_29 . V_46 ;
#ifdef F_32
if ( ! V_9 || ! V_9 -> V_47 )
return - V_48 ;
#endif
V_25 = F_30 ( V_9 , F_22 ( & V_43 -> V_29 ) , & V_45 ) ;
if ( V_25 < 0 )
return V_25 ;
V_7 = F_33 ( & V_43 -> V_29 , sizeof *V_6 ) ;
if ( ! V_7 ) {
V_25 = - V_49 ;
goto F_25;
}
V_6 = F_2 ( V_7 ) ;
F_34 ( V_43 , V_6 ) ;
V_6 -> V_43 = V_43 ;
if ( V_9 )
V_6 -> V_9 = * V_9 ;
V_7 -> V_17 = V_45 ;
V_7 -> V_50 = V_43 -> V_51 ;
V_7 -> V_47 = V_52 ;
V_7 -> V_53 = F_20 ;
V_7 -> V_54 = F_26 ;
V_6 -> V_8 . V_7 = F_35 ( V_7 ) ;
V_6 -> V_8 . V_55 = F_19 ;
if ( ( V_45 & ( V_37 | V_40 ) ) == 0 ) {
V_6 -> V_8 . V_56 [ V_57 ] = F_9 ;
V_6 -> V_8 . V_56 [ V_58 ] = F_11 ;
V_6 -> V_8 . V_56 [ V_59 ] = F_13 ;
V_6 -> V_8 . V_56 [ V_60 ] = F_14 ;
} else {
V_6 -> V_8 . V_56 [ V_57 ] = F_15 ;
V_6 -> V_8 . V_56 [ V_58 ] = F_16 ;
V_6 -> V_8 . V_56 [ V_59 ] = F_17 ;
V_6 -> V_8 . V_56 [ V_60 ] = F_18 ;
}
V_6 -> V_8 . V_61 = V_62 ;
V_6 -> V_8 . V_17 = V_24 ;
V_25 = F_36 ( & V_6 -> V_8 ) ;
if ( V_25 < 0 ) {
F_37 ( V_6 -> V_8 . V_7 ) ;
F_25:
if ( V_13 != V_38 )
F_25 ( V_13 ) ;
if ( V_12 != V_35 )
F_25 ( V_12 ) ;
F_25 ( V_11 ) ;
F_37 ( V_7 ) ;
}
return V_25 ;
}
static int T_6 F_38 ( struct V_42 * V_43 )
{
struct V_6 * V_6 ;
struct V_1 * V_9 ;
int V_25 ;
V_6 = F_39 ( V_43 ) ;
V_9 = V_43 -> V_29 . V_46 ;
V_25 = F_40 ( & V_6 -> V_8 ) ;
F_37 ( V_6 -> V_8 . V_7 ) ;
F_34 ( V_43 , NULL ) ;
if ( V_13 != V_38 )
F_25 ( V_13 ) ;
if ( V_12 != V_35 )
F_25 ( V_12 ) ;
F_25 ( V_11 ) ;
return V_25 ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_63 , F_31 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_63 ) ;
}
