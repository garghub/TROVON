struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_3 , V_6 ) ;
if ( V_5 ) {
if ( V_4 )
V_5 -> V_7 = V_4 ;
else
V_5 -> V_7 = V_8 ;
V_5 -> V_9 = F_3 ( V_5 -> V_7 , V_6 ) ;
if ( ! V_5 -> V_9 ) {
F_4 ( V_3 , V_5 ) ;
V_5 = NULL ;
}
}
return V_5 ;
}
void F_5 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
F_6 ( V_5 -> V_9 ) ;
F_4 ( V_3 , V_5 ) ;
}
static void F_7 ( struct V_10 * V_11 , struct V_2 * V_3 )
{
int V_12 ;
if ( V_3 -> V_13 ) {
V_12 = F_8 ( V_3 ) ;
if ( V_12 < 0 )
F_9 ( V_11 , L_1 ,
V_3 -> V_14 , V_12 ) ;
V_3 -> V_13 = NULL ;
}
}
void F_10 ( struct V_10 * V_11 ,
struct V_2 * V_15 , struct V_2 * V_16 ,
struct V_2 * V_17 , struct V_2 * V_18 )
{
F_7 ( V_11 , V_15 ) ;
F_7 ( V_11 , V_16 ) ;
if ( V_17 )
F_7 ( V_11 , V_17 ) ;
if ( V_18 )
F_7 ( V_11 , V_18 ) ;
}
static void F_11 ( unsigned long V_19 )
{
struct V_10 * V_11 = ( void * ) V_19 ;
struct V_20 * V_21 = V_11 -> V_22 ;
if ( ! V_11 -> V_23 )
return;
if ( V_21 -> V_24 != V_25 ) {
int V_26 = F_12 ( V_21 ) ;
F_13 ( V_11 , L_2 , V_27 , V_26 ) ;
}
}
static void F_14 ( struct V_10 * V_11 )
{
if ( V_11 -> V_22 -> V_24 == V_25 )
return;
if ( V_28 ) {
F_15 ( & V_29 , V_30 + ( V_31 * V_28 ) ) ;
F_9 ( V_11 , L_3 , V_28 ) ;
} else
F_9 ( V_11 , L_4 , V_27 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
F_9 ( V_11 , L_4 , V_27 ) ;
F_17 ( & V_29 ) ;
}
static int T_1 F_18 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_19 ( V_11 , V_32 ) ;
if ( V_26 < 0 )
return V_26 ;
V_33 . V_34 = V_32 [ V_35 ] . V_36 ;
V_33 . V_37 = V_32 [ V_38 ] . V_36 ;
V_33 . V_39 = V_32 [ V_40 ] . V_36 ;
F_20 ( & V_29 , F_11 , ( unsigned long ) V_11 ) ;
if ( V_41 ) {
F_21 ( V_11 , V_28 != 0 ) ;
F_22 ( V_11 , V_28 != 0 ) ;
} else {
F_22 ( V_11 , V_28 != 0 ) ;
F_21 ( V_11 , V_28 != 0 ) ;
}
F_23 ( V_11 , & V_42 ) ;
F_13 ( V_11 , L_5 V_43 L_6 , V_44 ) ;
return 0 ;
}
static int F_24 ( struct V_10 * V_11 )
{
F_25 ( & V_29 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_45 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_45 ) ;
}
