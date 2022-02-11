static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
F_5 ( & V_7 -> V_8 ) ;
F_6 ( V_7 -> V_9 , V_7 -> V_10 + V_11 ) ;
F_7 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_7 )
{
unsigned long V_12 ;
V_12 = F_9 ( V_7 -> V_10 + V_13 ) ;
V_12 &= ~ ( V_14 | V_15 ) ;
F_6 ( V_12 , V_7 -> V_10 + V_13 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
F_5 ( & V_7 -> V_8 ) ;
F_8 ( V_7 ) ;
F_7 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
unsigned long V_12 ;
struct V_1 * V_7 = F_4 ( V_6 ) ;
F_5 ( & V_7 -> V_8 ) ;
F_8 ( V_7 ) ;
V_12 = F_9 ( V_7 -> V_10 + V_13 ) ;
V_12 |= V_14 | V_16 ;
if ( V_17 ) {
V_12 |= V_18 ;
V_12 &= ~ V_15 ;
} else {
V_12 &= ~ V_18 ;
V_12 |= V_15 ;
}
F_12 ( L_1 ,
V_19 , V_7 -> V_9 , V_12 ) ;
F_6 ( V_7 -> V_9 , V_7 -> V_10 + V_20 ) ;
F_6 ( V_7 -> V_9 , V_7 -> V_10 + V_11 ) ;
F_6 ( V_12 , V_7 -> V_10 + V_13 ) ;
F_7 ( & V_7 -> V_8 ) ;
return 0 ;
}
static inline int F_13 ( struct V_1 * V_7 )
{
return F_9 ( V_7 -> V_10 + V_13 ) & V_14 ;
}
static int F_14 ( struct V_5 * V_6 , unsigned V_21 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
unsigned long V_22 = F_15 ( V_7 -> clock ) ;
unsigned int V_9 ;
unsigned int V_23 = 1 ;
unsigned long V_12 ;
if ( V_21 < 1 )
return - V_24 ;
V_22 /= 128 ;
V_9 = V_21 * V_22 ;
F_12 ( L_2 ,
V_19 , V_9 , V_21 , V_22 ) ;
if ( V_9 >= 0x10000 ) {
for ( V_23 = 1 ; V_23 <= 0x100 ; V_23 ++ ) {
if ( ( V_9 / V_23 ) < 0x10000 )
break;
}
if ( ( V_9 / V_23 ) >= 0x10000 ) {
F_16 ( V_7 -> V_25 , L_3 , V_21 ) ;
return - V_24 ;
}
}
F_12 ( L_4 ,
V_19 , V_21 , V_23 , V_9 , V_9 / V_23 ) ;
V_9 /= V_23 ;
V_7 -> V_9 = V_9 ;
V_12 = F_9 ( V_7 -> V_10 + V_13 ) ;
V_12 &= ~ V_26 ;
V_12 |= F_17 ( V_23 - 1 ) ;
F_6 ( V_9 , V_7 -> V_10 + V_20 ) ;
F_6 ( V_12 , V_7 -> V_10 + V_13 ) ;
V_6 -> V_21 = ( V_9 * V_23 ) / V_22 ;
return 0 ;
}
static T_1 F_18 ( int V_27 , void * V_28 )
{
struct V_1 * V_7 = F_19 ( V_28 ) ;
F_20 ( V_7 -> V_25 , L_5 ) ;
F_3 ( & V_7 -> V_29 ) ;
return V_30 ;
}
static int F_21 ( struct V_2 * V_3 ,
unsigned long V_31 , void * V_32 )
{
int V_33 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( ! F_13 ( V_7 ) )
goto V_34;
if ( V_31 == V_35 ) {
F_3 ( & V_7 -> V_29 ) ;
} else if ( V_31 == V_36 ) {
F_10 ( & V_7 -> V_29 ) ;
V_33 = F_14 ( & V_7 -> V_29 ,
V_7 -> V_29 . V_21 ) ;
if ( V_33 >= 0 )
F_11 ( & V_7 -> V_29 ) ;
else
goto V_37;
}
V_34:
return 0 ;
V_37:
F_16 ( V_7 -> V_25 , L_6 ,
V_7 -> V_29 . V_21 ) ;
return V_33 ;
}
static inline int F_22 ( struct V_1 * V_7 )
{
V_7 -> V_4 . V_38 = F_21 ;
return F_23 ( & V_7 -> V_4 ,
V_39 ) ;
}
static inline void F_24 ( struct V_1 * V_7 )
{
V_7 -> V_4 . V_38 = F_21 ;
F_25 ( & V_7 -> V_4 ,
V_39 ) ;
}
static inline int F_22 ( struct V_1 * V_7 )
{
return 0 ;
}
static inline void F_24 ( struct V_1 * V_7 )
{
}
static int F_26 ( struct V_40 * V_41 )
{
struct V_42 * V_25 ;
struct V_1 * V_7 ;
struct V_43 * V_44 ;
struct V_43 * V_45 ;
unsigned int V_12 ;
int V_46 = 0 ;
int V_33 ;
F_12 ( L_7 , V_19 , V_41 ) ;
V_25 = & V_41 -> V_25 ;
V_7 = F_27 ( V_25 , sizeof( * V_7 ) , V_47 ) ;
if ( ! V_7 )
return - V_48 ;
V_7 -> V_25 = & V_41 -> V_25 ;
F_28 ( & V_7 -> V_8 ) ;
V_7 -> V_29 = V_49 ;
V_45 = F_29 ( V_41 , V_50 , 0 ) ;
if ( V_45 == NULL ) {
F_16 ( V_25 , L_8 ) ;
V_33 = - V_51 ;
goto V_37;
}
V_44 = F_29 ( V_41 , V_52 , 0 ) ;
V_7 -> V_10 = F_30 ( V_25 , V_44 ) ;
if ( F_31 ( V_7 -> V_10 ) ) {
V_33 = F_32 ( V_7 -> V_10 ) ;
goto V_37;
}
F_12 ( L_9 , V_7 -> V_10 ) ;
V_7 -> clock = F_33 ( V_25 , L_10 ) ;
if ( F_31 ( V_7 -> clock ) ) {
F_16 ( V_25 , L_11 ) ;
V_33 = F_32 ( V_7 -> clock ) ;
goto V_37;
}
F_34 ( V_7 -> clock ) ;
V_33 = F_22 ( V_7 ) ;
if ( V_33 < 0 ) {
F_16 ( V_25 , L_12 ) ;
goto V_53;
}
F_35 ( & V_7 -> V_29 , V_7 ) ;
F_36 ( & V_7 -> V_29 , V_54 , & V_41 -> V_25 ) ;
V_33 = F_14 ( & V_7 -> V_29 ,
V_7 -> V_29 . V_21 ) ;
if ( V_33 ) {
V_46 = F_14 ( & V_7 -> V_29 ,
V_55 ) ;
if ( V_46 == 0 )
F_20 ( V_25 ,
L_13 ,
V_55 ) ;
else
F_20 ( V_25 , L_14
L_15 ) ;
}
V_33 = F_37 ( V_25 , V_45 -> V_56 , F_18 , 0 ,
V_41 -> V_57 , V_41 ) ;
if ( V_33 != 0 ) {
F_16 ( V_25 , L_16 , V_33 ) ;
goto V_58;
}
F_38 ( & V_7 -> V_29 , V_59 ) ;
V_33 = F_39 ( & V_7 -> V_29 ) ;
if ( V_33 ) {
F_16 ( V_25 , L_17 , V_33 ) ;
goto V_58;
}
if ( V_60 && V_46 == 0 ) {
F_20 ( V_25 , L_18 ) ;
F_11 ( & V_7 -> V_29 ) ;
} else if ( ! V_60 ) {
F_10 ( & V_7 -> V_29 ) ;
}
F_40 ( V_41 , V_7 ) ;
V_12 = F_9 ( V_7 -> V_10 + V_13 ) ;
F_20 ( V_25 , L_19 ,
( V_12 & V_14 ) ? L_20 : L_21 ,
( V_12 & V_15 ) ? L_22 : L_23 ,
( V_12 & V_18 ) ? L_22 : L_23 ) ;
return 0 ;
V_58:
F_24 ( V_7 ) ;
V_53:
F_41 ( V_7 -> clock ) ;
V_7 -> clock = NULL ;
V_37:
return V_33 ;
}
static int F_42 ( struct V_40 * V_25 )
{
struct V_1 * V_7 = F_19 ( V_25 ) ;
F_43 ( & V_7 -> V_29 ) ;
F_24 ( V_7 ) ;
F_41 ( V_7 -> clock ) ;
V_7 -> clock = NULL ;
return 0 ;
}
static void F_44 ( struct V_40 * V_25 )
{
struct V_1 * V_7 = F_19 ( V_25 ) ;
F_10 ( & V_7 -> V_29 ) ;
}
static int F_45 ( struct V_42 * V_25 )
{
struct V_1 * V_7 = F_46 ( V_25 ) ;
V_7 -> V_61 = F_9 ( V_7 -> V_10 + V_13 ) ;
V_7 -> V_62 = F_9 ( V_7 -> V_10 + V_20 ) ;
F_10 ( & V_7 -> V_29 ) ;
return 0 ;
}
static int F_47 ( struct V_42 * V_25 )
{
struct V_1 * V_7 = F_46 ( V_25 ) ;
F_6 ( V_7 -> V_62 , V_7 -> V_10 + V_20 ) ;
F_6 ( V_7 -> V_62 , V_7 -> V_10 + V_11 ) ;
F_6 ( V_7 -> V_61 , V_7 -> V_10 + V_13 ) ;
F_20 ( V_25 , L_24 ,
( V_7 -> V_61 & V_14 ) ? L_22 : L_23 ) ;
return 0 ;
}
