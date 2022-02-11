static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_9 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
V_9 = F_3 ( V_4 ) ;
if ( V_9 < 0 ) {
F_4 ( L_1 ) ;
return;
}
F_5 ( & V_4 -> V_13 , V_12 ) ;
if ( V_4 -> V_14 ) {
V_11 = F_6 ( V_4 ) ;
if ( ! V_11 )
V_11 = F_7 ( V_4 ) ;
if ( V_11 ) {
V_11 -> V_15 |= V_4 -> V_14 ;
} else {
V_4 -> V_16 &= ~ V_4 -> V_14 ;
}
}
V_4 -> V_14 = F_8 ( V_9 ) ;
F_9 ( V_17 , V_7 -> V_18 . V_19 + V_9 * V_4 -> V_20 ) ;
F_9 ( V_21 , V_7 -> V_18 . V_18 . V_22 ) ;
F_9 ( V_23 , V_24 ) ;
F_9 ( V_25 , V_24 ) ;
F_10 ( & V_4 -> V_13 , V_12 ) ;
}
static void
F_11 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_12 ( V_27 ) ;
struct V_10 * V_11 = F_6 ( V_4 ) ;
if ( ! V_11 )
return;
F_13 ( V_27 , V_11 ) ;
F_14 ( V_27 ) ;
}
static void
F_15 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_12 ( V_27 ) ;
struct V_10 * V_11 = F_6 ( V_4 ) ;
if ( ! V_11 )
return;
F_16 ( & V_11 -> V_28 , & V_4 -> V_29 ) ;
F_14 ( V_27 ) ;
}
static void
F_17 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_12 ( V_27 ) ;
struct V_10 * V_11 = F_18 ( V_4 ) ;
if ( ! V_11 )
return;
V_4 -> V_30 ++ ;
F_16 ( & V_11 -> V_28 , & V_4 -> V_31 ) ;
if ( V_11 -> V_32 ) {
F_19 ( V_11 -> V_32 ) ;
V_11 -> V_32 = NULL ;
}
F_20 ( V_27 ) ;
F_21 ( & V_4 -> V_33 ) ;
F_22 ( & V_4 -> V_34 ) ;
}
T_1
F_23 ( int V_35 , void * V_36 )
{
struct V_26 * V_27 = V_36 ;
struct V_3 * V_4 = F_12 ( V_27 ) ;
T_2 V_37 ;
T_1 V_38 = V_39 ;
F_24 () ;
V_37 = F_25 ( V_23 ) ;
F_9 ( V_23 , V_37 ) ;
if ( V_37 & V_24 ) {
F_9 ( V_40 , V_24 ) ;
F_22 ( & V_4 -> V_5 ) ;
V_38 = V_41 ;
}
if ( V_37 & V_42 ) {
F_26 ( & V_4 -> V_13 ) ;
F_11 ( V_27 ) ;
F_27 ( & V_4 -> V_13 ) ;
V_38 = V_41 ;
}
if ( V_37 & V_43 ) {
F_26 ( & V_4 -> V_13 ) ;
F_17 ( V_27 ) ;
F_27 ( & V_4 -> V_13 ) ;
V_38 = V_41 ;
}
return V_38 ;
}
void
F_28 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_12 ( V_27 ) ;
F_29 ( & V_4 -> V_33 ) ;
F_30 ( & V_4 -> V_5 , F_1 ) ;
F_9 ( V_23 , V_44 ) ;
}
int
F_31 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_12 ( V_27 ) ;
F_9 ( V_25 , V_44 ) ;
return 0 ;
}
void
F_32 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_12 ( V_27 ) ;
F_9 ( V_40 , V_44 ) ;
F_9 ( V_23 , V_44 ) ;
F_33 ( & V_4 -> V_5 ) ;
}
void F_34 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_12 ( V_27 ) ;
unsigned long V_12 ;
F_9 ( V_23 , V_44 ) ;
F_9 ( V_25 , V_44 ) ;
F_5 ( & V_4 -> V_13 , V_12 ) ;
F_15 ( V_27 ) ;
F_17 ( V_27 ) ;
F_10 ( & V_4 -> V_13 , V_12 ) ;
}
