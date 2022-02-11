static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static unsigned long F_3 ( unsigned long V_4 ,
unsigned long V_5 ,
T_1 * div ,
bool * V_6 )
{
unsigned long V_7 = 0 ;
T_1 V_8 = 0 , V_9 ;
bool V_10 ;
for ( V_9 = 1 ; V_9 < 16 ; V_9 ++ ) {
T_1 V_11 ;
for ( V_11 = 1 ; V_11 < 3 ; V_11 ++ ) {
unsigned long V_12 ;
V_12 = V_5 / V_9 / V_11 ;
if ( V_12 > V_4 )
continue;
if ( ! V_7 ||
( V_4 - V_12 ) < ( V_4 - V_7 ) ) {
V_7 = V_12 ;
V_8 = V_9 ;
V_10 = V_11 ;
}
}
}
if ( div && V_6 ) {
* div = V_8 ;
* V_6 = V_10 ;
}
return V_7 ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_2 * V_15 ;
unsigned long V_16 = 0 ;
unsigned long V_4 = V_14 -> V_4 ;
int V_17 = 1 , V_18 = 1 ;
int V_19 , V_20 ;
V_15 = F_5 ( V_3 , 0 ) ;
if ( ! V_15 )
return - V_21 ;
for ( V_19 = 1 ; V_19 < 3 ; V_19 ++ ) {
for ( V_20 = 1 ; V_20 < 16 ; V_20 ++ ) {
unsigned long V_22 = V_4 * V_19 * V_20 ;
unsigned long V_23 ;
V_23 = F_6 ( V_15 , V_22 ) ;
if ( V_23 == V_22 ) {
V_16 = V_23 ;
V_18 = V_19 ;
V_17 = V_20 ;
goto V_24;
}
if ( abs ( V_4 - V_23 / V_19 ) <
abs ( V_4 - V_16 / V_17 ) ) {
V_16 = V_23 ;
V_17 = V_19 ;
}
}
}
V_24:
V_14 -> V_4 = V_16 / V_18 / V_17 ;
V_14 -> V_25 = V_16 ;
V_14 -> V_26 = V_15 ;
return 0 ;
}
static unsigned long F_7 ( struct V_2 * V_3 ,
unsigned long V_5 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
T_2 V_28 ;
V_28 = F_8 ( V_27 -> V_29 -> V_30 + V_31 ) ;
if ( V_28 & V_32 )
V_5 /= 2 ;
V_28 = F_8 ( V_27 -> V_29 -> V_30 + V_33 ) ;
V_28 = ( V_28 >> 4 ) & 0xf ;
if ( ! V_28 )
V_28 = 1 ;
return V_5 / V_28 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned long V_4 ,
unsigned long V_5 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
bool V_6 ;
T_2 V_28 ;
T_1 div ;
F_3 ( V_4 , V_5 , & div , & V_6 ) ;
V_28 = F_8 ( V_27 -> V_29 -> V_30 + V_31 ) ;
V_28 &= ~ V_32 ;
if ( V_6 )
V_28 |= V_32 ;
F_10 ( V_28 , V_27 -> V_29 -> V_30 + V_31 ) ;
V_28 = F_8 ( V_27 -> V_29 -> V_30 + V_33 ) ;
V_28 &= ~ V_34 ;
F_10 ( V_28 | F_11 ( div ) ,
V_27 -> V_29 -> V_30 + V_33 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
T_2 V_28 ;
V_28 = F_8 ( V_27 -> V_29 -> V_30 + V_35 ) ;
return ( ( V_28 & V_36 ) >>
V_37 ) ;
}
static int F_13 ( struct V_2 * V_3 , T_1 V_38 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
T_2 V_28 ;
if ( V_38 > 1 )
return - V_21 ;
V_28 = F_8 ( V_27 -> V_29 -> V_30 + V_35 ) ;
V_28 &= ~ V_36 ;
F_10 ( V_28 | F_14 ( V_38 ) ,
V_27 -> V_29 -> V_30 + V_35 ) ;
return 0 ;
}
int F_15 ( struct V_39 * V_29 )
{
struct V_40 V_41 ;
struct V_1 * V_27 ;
const char * V_42 [ 2 ] ;
V_42 [ 0 ] = F_16 ( V_29 -> V_43 ) ;
if ( ! V_42 [ 0 ] )
return - V_44 ;
V_42 [ 1 ] = F_16 ( V_29 -> V_45 ) ;
if ( ! V_42 [ 1 ] )
return - V_44 ;
V_27 = F_17 ( V_29 -> V_46 , sizeof( * V_27 ) , V_47 ) ;
if ( ! V_27 )
return - V_48 ;
V_41 . V_49 = L_1 ;
V_41 . V_50 = & V_51 ;
V_41 . V_52 = V_42 ;
V_41 . V_53 = 2 ;
V_41 . V_54 = V_55 ;
V_27 -> V_29 = V_29 ;
V_27 -> V_3 . V_41 = & V_41 ;
V_29 -> V_56 = F_18 ( V_29 -> V_46 , & V_27 -> V_3 ) ;
if ( F_19 ( V_29 -> V_56 ) )
return F_20 ( V_29 -> V_56 ) ;
return 0 ;
}
