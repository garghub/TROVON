static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
V_4 = F_2 ( V_2 ) ;
V_6 = & V_4 -> V_9 ;
F_3 ( & V_4 -> V_10 , V_7 ) ;
V_8 = F_4 ( V_6 -> V_11 + V_12 ) ;
V_8 |= F_5 ( F_6 ( V_2 ) ) ;
F_7 ( V_8 , V_6 -> V_11 + V_12 ) ;
F_8 ( & V_4 -> V_10 , V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
V_4 = F_2 ( V_2 ) ;
V_6 = & V_4 -> V_9 ;
F_3 ( & V_4 -> V_10 , V_7 ) ;
V_8 = F_4 ( V_6 -> V_11 + V_12 ) ;
V_8 &= ~ F_5 ( F_6 ( V_2 ) ) ;
F_7 ( V_8 , V_6 -> V_11 + V_12 ) ;
F_8 ( & V_4 -> V_10 , V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( type == V_13 )
return 0 ;
if ( type == V_14 &&
V_4 -> V_15 == V_14 )
return 0 ;
if ( type == V_16 &&
V_4 -> V_15 == V_16 )
return 0 ;
if ( type == V_17 &&
V_4 -> V_15 == V_17 )
return 0 ;
if ( type == V_18 &&
V_4 -> V_15 == V_18 )
return 0 ;
return - V_19 ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , unsigned V_22 )
{
struct V_5 * V_6 ;
V_6 = F_13 ( V_21 ) ;
return ! ! ( F_4 ( V_6 -> V_11 + V_23 ) & F_5 ( V_22 ) ) ;
}
static void F_14 ( struct V_20 * V_21 , unsigned V_22 , int V_24 )
{
struct V_5 * V_6 ;
struct V_3 * V_25 ;
unsigned long V_7 ;
unsigned int V_26 ;
V_6 = F_13 ( V_21 ) ;
V_25 = F_15 ( V_6 , struct V_3 , V_9 ) ;
F_3 ( & V_25 -> V_10 , V_7 ) ;
V_26 = F_4 ( V_6 -> V_11 + V_23 ) ;
if ( V_24 )
V_26 |= F_5 ( V_22 ) ;
else
V_26 &= ~ F_5 ( V_22 ) ;
F_7 ( V_26 , V_6 -> V_11 + V_23 ) ;
F_8 ( & V_25 -> V_10 , V_7 ) ;
}
static int F_16 ( struct V_20 * V_21 , unsigned V_22 )
{
struct V_5 * V_6 ;
struct V_3 * V_25 ;
unsigned long V_7 ;
unsigned int V_27 ;
V_6 = F_13 ( V_21 ) ;
V_25 = F_15 ( V_6 , struct V_3 , V_9 ) ;
F_3 ( & V_25 -> V_10 , V_7 ) ;
V_27 = F_4 ( V_6 -> V_11 + V_28 ) ;
V_27 &= ~ F_5 ( V_22 ) ;
F_7 ( V_27 , V_6 -> V_11 + V_28 ) ;
F_8 ( & V_25 -> V_10 , V_7 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 ,
unsigned V_22 , int V_24 )
{
struct V_5 * V_6 ;
struct V_3 * V_25 ;
unsigned long V_7 ;
unsigned int V_26 , V_27 ;
V_6 = F_13 ( V_21 ) ;
V_25 = F_15 ( V_6 , struct V_3 , V_9 ) ;
F_3 ( & V_25 -> V_10 , V_7 ) ;
V_26 = F_4 ( V_6 -> V_11 + V_23 ) ;
if ( V_24 )
V_26 |= F_5 ( V_22 ) ;
else
V_26 &= ~ F_5 ( V_22 ) ;
F_7 ( V_26 , V_6 -> V_11 + V_23 ) ;
V_27 = F_4 ( V_6 -> V_11 + V_28 ) ;
V_27 |= F_5 ( V_22 ) ;
F_7 ( V_27 , V_6 -> V_11 + V_28 ) ;
F_8 ( & V_25 -> V_10 , V_7 ) ;
return 0 ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_3 * V_4 ;
struct V_31 * V_25 ;
struct V_5 * V_6 ;
struct V_32 * V_33 ;
unsigned long V_34 ;
int V_35 ;
V_4 = F_19 ( V_30 ) ;
V_25 = F_20 ( V_30 ) ;
V_6 = & V_4 -> V_9 ;
V_33 = V_4 -> V_9 . V_21 . V_33 ;
F_21 ( V_25 , V_30 ) ;
while ( ( V_34 =
( F_4 ( V_6 -> V_11 + V_36 ) &
F_4 ( V_6 -> V_11 + V_12 ) ) ) ) {
F_7 ( V_34 , V_6 -> V_11 + V_36 ) ;
F_22 (i, &status, mm_gc->gc.ngpio) {
F_23 ( F_24 ( V_33 , V_35 ) ) ;
}
}
F_25 ( V_25 , V_30 ) ;
}
static void F_26 ( struct V_29 * V_30 )
{
struct V_3 * V_4 ;
struct V_31 * V_25 ;
struct V_5 * V_6 ;
struct V_32 * V_33 ;
unsigned long V_34 ;
int V_35 ;
V_4 = F_19 ( V_30 ) ;
V_25 = F_20 ( V_30 ) ;
V_6 = & V_4 -> V_9 ;
V_33 = V_4 -> V_9 . V_21 . V_33 ;
F_21 ( V_25 , V_30 ) ;
V_34 = F_4 ( V_6 -> V_11 + V_23 ) ;
V_34 &= F_4 ( V_6 -> V_11 + V_12 ) ;
F_22 (i, &status, mm_gc->gc.ngpio) {
F_23 ( F_24 ( V_33 , V_35 ) ) ;
}
F_25 ( V_25 , V_30 ) ;
}
static int F_27 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_41 . V_42 ;
int V_43 , V_44 ;
struct V_3 * V_4 ;
V_4 = F_28 ( & V_38 -> V_41 , sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return - V_46 ;
F_29 ( & V_4 -> V_10 ) ;
if ( F_30 ( V_40 , L_1 , & V_43 ) )
V_4 -> V_9 . V_21 . V_47 = V_48 ;
else
V_4 -> V_9 . V_21 . V_47 = V_43 ;
if ( V_4 -> V_9 . V_21 . V_47 > V_48 ) {
F_31 ( & V_38 -> V_41 ,
L_2 ,
V_48 , V_48 ) ;
V_4 -> V_9 . V_21 . V_47 = V_48 ;
}
V_4 -> V_9 . V_21 . V_49 = F_16 ;
V_4 -> V_9 . V_21 . V_50 = F_17 ;
V_4 -> V_9 . V_21 . V_51 = F_12 ;
V_4 -> V_9 . V_21 . V_52 = F_14 ;
V_4 -> V_9 . V_21 . V_53 = V_54 ;
V_4 -> V_9 . V_21 . V_41 = & V_38 -> V_41 ;
V_44 = F_32 ( V_40 , & V_4 -> V_9 ) ;
if ( V_44 ) {
F_33 ( & V_38 -> V_41 , L_3 ) ;
return V_44 ;
}
F_34 ( V_38 , V_4 ) ;
V_4 -> V_55 = F_35 ( V_38 , 0 ) ;
if ( V_4 -> V_55 < 0 )
goto V_56;
if ( F_30 ( V_40 , L_4 , & V_43 ) ) {
V_44 = - V_19 ;
F_33 ( & V_38 -> V_41 ,
L_5 ) ;
goto V_57;
}
V_4 -> V_15 = V_43 ;
V_44 = F_36 ( & V_4 -> V_9 . V_21 , & V_58 , 0 ,
V_59 , V_13 ) ;
if ( V_44 ) {
F_37 ( & V_38 -> V_41 , L_6 ) ;
return V_44 ;
}
F_38 ( & V_4 -> V_9 . V_21 ,
& V_58 ,
V_4 -> V_55 ,
V_4 -> V_15 == V_14 ?
F_26 :
F_18 ) ;
V_56:
return 0 ;
V_57:
F_39 ( L_7 ,
V_40 -> V_60 , V_44 ) ;
return V_44 ;
}
static int F_40 ( struct V_37 * V_38 )
{
struct V_3 * V_4 = F_41 ( V_38 ) ;
F_42 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_61 ) ;
}
static void T_3 F_45 ( void )
{
F_46 ( & V_61 ) ;
}
