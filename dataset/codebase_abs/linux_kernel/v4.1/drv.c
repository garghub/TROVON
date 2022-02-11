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
const struct V_29 * T_4 V_32 = NULL ;
struct V_1 * V_1 ;
struct V_33 * V_34 ;
int V_35 ;
V_1 = F_11 ( V_16 , V_28 , V_30 ) ;
if ( F_12 ( V_1 ) )
return F_13 ( V_1 ) ;
#if F_14 ( V_36 )
if ( V_30 == & V_37 )
T_4 = & V_38 ;
else if ( V_30 == & V_39 )
T_4 = & V_40 ;
else if ( V_30 == & V_41 )
T_4 = & V_42 ;
if ( T_4 &&
( V_1 -> V_43 & V_44 ) == V_45 ) {
V_30 = T_4 ;
V_1 -> V_30 = T_4 ;
}
#endif
F_15 ( V_16 , V_1 ) ;
V_34 = F_16 ( V_1 ) ;
V_34 -> V_46 = F_17 ( V_1 , V_30 ) ;
if ( F_12 ( V_34 -> V_46 ) ) {
V_35 = F_13 ( V_34 -> V_46 ) ;
goto V_47;
}
F_4 ( V_1 , V_16 ) ;
V_35 = F_18 ( V_1 , V_1 -> V_48 ) ;
if ( V_35 )
goto V_49;
return 0 ;
V_49:
F_19 ( V_34 -> V_46 ) ;
V_47:
F_20 ( V_1 ) ;
return V_35 ;
}
static void F_21 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_22 ( V_16 ) ;
struct V_33 * V_34 = F_16 ( V_2 ) ;
F_19 ( V_34 -> V_46 ) ;
F_20 ( V_2 ) ;
}
static int F_23 ( struct V_50 * V_50 )
{
return 0 ;
}
static int F_24 ( struct V_50 * V_50 )
{
struct V_15 * V_16 = F_25 ( V_50 ) ;
struct V_1 * V_2 = F_22 ( V_16 ) ;
bool V_51 ;
F_26 ( V_16 , V_52 , 0x00 ) ;
if ( ! V_2 -> V_53 )
return 0 ;
F_27 ( V_2 ) ;
V_51 = F_28 ( V_2 ) ;
F_29 ( V_2 , V_51 ) ;
return 0 ;
}
int T_5 F_30 ( void )
{
int V_35 ;
V_35 = F_31 ( & V_54 ) ;
if ( V_35 )
F_32 ( L_8 ) ;
return V_35 ;
}
void F_33 ( void )
{
F_34 ( & V_54 ) ;
}
