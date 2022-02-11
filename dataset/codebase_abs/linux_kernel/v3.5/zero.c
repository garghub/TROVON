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
int V_32 ;
struct V_20 * V_22 = V_11 -> V_22 ;
int V_33 ;
V_33 = F_19 ( V_11 ) ;
if ( V_33 < 0 )
return V_33 ;
V_34 [ V_35 ] . V_33 = V_33 ;
V_36 . V_37 = V_33 ;
V_33 = F_19 ( V_11 ) ;
if ( V_33 < 0 )
return V_33 ;
V_34 [ V_38 ] . V_33 = V_33 ;
V_36 . V_39 = V_33 ;
V_33 = F_19 ( V_11 ) ;
if ( V_33 < 0 )
return V_33 ;
V_34 [ V_40 ] . V_33 = V_33 ;
V_36 . V_41 = V_33 ;
F_20 ( & V_29 , F_11 , ( unsigned long ) V_11 ) ;
if ( V_42 ) {
F_21 ( V_11 , V_28 != 0 ) ;
F_22 ( V_11 , V_28 != 0 ) ;
} else {
F_22 ( V_11 , V_28 != 0 ) ;
F_21 ( V_11 , V_28 != 0 ) ;
}
V_32 = F_23 ( V_22 ) ;
if ( V_32 >= 0 )
V_36 . V_43 = F_24 ( 0x0200 + V_32 ) ;
else {
F_25 ( L_5 ,
V_44 , V_22 -> V_14 ) ;
V_36 . V_43 = F_24 ( 0x9999 ) ;
}
F_13 ( V_11 , L_6 V_45 L_7 , V_44 ) ;
snprintf ( V_46 , sizeof V_46 , L_8 ,
F_26 () -> V_47 , F_26 () -> V_48 ,
V_22 -> V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 )
{
F_28 ( & V_29 ) ;
return 0 ;
}
static int T_1 F_29 ( void )
{
return F_30 ( & V_49 , F_18 ) ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_49 ) ;
}
