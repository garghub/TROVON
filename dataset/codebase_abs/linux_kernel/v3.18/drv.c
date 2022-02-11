static T_1 F_1 ( struct V_1 * V_2 , union V_3 * V_4 )
{
union V_3 * V_5 , * V_6 , * V_7 ;
if ( V_4 -> type != V_8 ||
V_4 -> V_9 . V_10 != 2 ||
V_4 -> V_9 . V_11 [ 0 ] . type != V_12 ||
V_4 -> V_9 . V_11 [ 0 ] . integer . V_13 != 0 ) {
F_2 ( V_2 , L_1 ) ;
return 0 ;
}
V_5 = & V_4 -> V_9 . V_11 [ 1 ] ;
if ( V_5 -> type != V_8 ||
V_5 -> V_9 . V_10 < 2 ||
V_5 -> V_9 . V_11 [ 0 ] . type != V_12 ||
V_5 -> V_9 . V_11 [ 1 ] . type != V_12 ) {
F_2 ( V_2 , L_2 ) ;
return 0 ;
}
V_6 = & V_5 -> V_9 . V_11 [ 0 ] ;
V_7 = & V_5 -> V_9 . V_11 [ 1 ] ;
if ( ! ( V_6 -> integer . V_13 & V_14 ) ) {
F_3 ( V_2 , L_3 ) ;
return 0 ;
}
return V_7 -> integer . V_13 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_2 V_17 ;
T_2 V_18 ;
struct V_19 V_4 = { V_20 , NULL } ;
T_3 V_21 ;
V_17 = F_5 ( & V_16 -> V_22 ) ;
if ( ! V_17 ) {
F_3 ( V_2 ,
L_4 ) ;
return;
}
V_21 = F_6 ( V_17 , ( V_23 ) V_24 , & V_18 ) ;
if ( F_7 ( V_21 ) ) {
F_3 ( V_2 , L_5 ) ;
return;
}
V_21 = F_8 ( V_18 , NULL , NULL , & V_4 ) ;
if ( F_7 ( V_21 ) ) {
F_2 ( V_2 , L_6 , V_21 ) ;
return;
}
V_2 -> V_25 = F_1 ( V_2 , V_4 . V_26 ) ;
F_3 ( V_2 , L_7 ,
V_2 -> V_25 ) ;
F_9 ( V_4 . V_26 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_15 * V_16 ) {}
static int F_10 ( struct V_15 * V_16 , const struct V_27 * V_28 )
{
const struct V_29 * V_30 = (struct V_29 * ) ( V_28 -> V_31 ) ;
struct V_1 * V_1 ;
struct V_32 * V_33 ;
int V_34 ;
V_1 = F_11 ( V_16 , V_28 , V_30 ) ;
if ( F_12 ( V_1 ) )
return F_13 ( V_1 ) ;
F_14 ( V_16 , V_1 ) ;
V_33 = F_15 ( V_1 ) ;
V_33 -> V_35 = F_16 ( V_1 , V_30 ) ;
if ( F_12 ( V_33 -> V_35 ) ) {
V_34 = F_13 ( V_33 -> V_35 ) ;
goto V_36;
}
F_4 ( V_1 , V_16 ) ;
V_34 = F_17 ( V_1 , V_1 -> V_37 ) ;
if ( V_34 )
goto V_38;
return 0 ;
V_38:
F_18 ( V_33 -> V_35 ) ;
V_36:
F_19 ( V_1 ) ;
return V_34 ;
}
static void F_20 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_21 ( V_16 ) ;
struct V_32 * V_33 = F_15 ( V_2 ) ;
F_18 ( V_33 -> V_35 ) ;
F_19 ( V_2 ) ;
}
static int F_22 ( struct V_39 * V_39 )
{
return 0 ;
}
static int F_23 ( struct V_39 * V_39 )
{
struct V_15 * V_16 = F_24 ( V_39 ) ;
struct V_1 * V_2 = F_21 ( V_16 ) ;
bool V_40 ;
F_25 ( V_16 , V_41 , 0x00 ) ;
if ( ! V_2 -> V_42 )
return 0 ;
F_26 ( V_2 ) ;
V_40 = F_27 ( V_2 ) ;
F_28 ( V_2 , V_40 ) ;
return 0 ;
}
int T_4 F_29 ( void )
{
int V_34 ;
V_34 = F_30 ( & V_43 ) ;
if ( V_34 )
F_31 ( L_8 ) ;
return V_34 ;
}
void F_32 ( void )
{
F_33 ( & V_43 ) ;
}
