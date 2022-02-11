struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 , V_5 ) ;
if ( V_4 ) {
V_4 -> V_6 = V_7 ;
V_4 -> V_8 = F_3 ( V_7 , V_5 ) ;
if ( ! V_4 -> V_8 ) {
F_4 ( V_3 , V_4 ) ;
V_4 = NULL ;
}
}
return V_4 ;
}
void F_5 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
F_6 ( V_4 -> V_8 ) ;
F_4 ( V_3 , V_4 ) ;
}
static void F_7 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_11 ;
if ( V_3 -> V_12 ) {
V_11 = F_8 ( V_3 ) ;
if ( V_11 < 0 )
F_9 ( V_10 , L_1 ,
V_3 -> V_13 , V_11 ) ;
V_3 -> V_12 = NULL ;
}
}
void F_10 ( struct V_9 * V_10 ,
struct V_2 * V_14 , struct V_2 * V_15 )
{
F_7 ( V_10 , V_14 ) ;
F_7 ( V_10 , V_15 ) ;
}
static void F_11 ( unsigned long V_16 )
{
struct V_9 * V_10 = ( void * ) V_16 ;
struct V_17 * V_18 = V_10 -> V_19 ;
if ( ! V_10 -> V_20 )
return;
if ( V_18 -> V_21 != V_22 ) {
int V_23 = F_12 ( V_18 ) ;
F_13 ( V_10 , L_2 , V_24 , V_23 ) ;
}
}
static void F_14 ( struct V_9 * V_10 )
{
if ( V_10 -> V_19 -> V_21 == V_22 )
return;
if ( V_25 ) {
F_15 ( & V_26 , V_27 + ( V_28 * V_25 ) ) ;
F_9 ( V_10 , L_3 , V_25 ) ;
} else
F_9 ( V_10 , L_4 , V_24 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
F_9 ( V_10 , L_4 , V_24 ) ;
F_17 ( & V_26 ) ;
}
static int T_1 F_18 ( struct V_9 * V_10 )
{
int V_29 ;
struct V_17 * V_19 = V_10 -> V_19 ;
int V_30 ;
V_30 = F_19 ( V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
V_31 [ V_32 ] . V_30 = V_30 ;
V_33 . V_34 = V_30 ;
V_30 = F_19 ( V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
V_31 [ V_35 ] . V_30 = V_30 ;
V_33 . V_36 = V_30 ;
V_30 = F_19 ( V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
V_31 [ V_37 ] . V_30 = V_30 ;
V_33 . V_38 = V_30 ;
F_20 ( & V_26 , F_11 , ( unsigned long ) V_10 ) ;
if ( V_39 ) {
F_21 ( V_10 , V_25 != 0 ) ;
F_22 ( V_10 , V_25 != 0 ) ;
} else {
F_22 ( V_10 , V_25 != 0 ) ;
F_21 ( V_10 , V_25 != 0 ) ;
}
V_29 = F_23 ( V_19 ) ;
if ( V_29 >= 0 )
V_33 . V_40 = F_24 ( 0x0200 + V_29 ) ;
else {
F_25 ( L_5 ,
V_41 , V_19 -> V_13 ) ;
V_33 . V_40 = F_24 ( 0x9999 ) ;
}
F_13 ( V_10 , L_6 V_42 L_7 , V_41 ) ;
snprintf ( V_43 , sizeof V_43 , L_8 ,
F_26 () -> V_44 , F_26 () -> V_45 ,
V_19 -> V_13 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
F_28 ( & V_26 ) ;
return 0 ;
}
static int T_1 F_29 ( void )
{
return F_30 ( & V_46 , F_18 ) ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_46 ) ;
}
