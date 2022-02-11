static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_6 ( & V_7 , V_6 -> V_8 ) ;
F_3 ( V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
if ( F_8 ( V_2 , V_10 ) )
return 1 ;
if ( V_10 -> V_11 )
return strncmp ( F_9 ( V_2 ) , V_10 -> V_11 ,
V_12 ) == 0 ;
return 0 ;
}
int F_10 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_13 ;
F_11 ( & V_4 -> V_2 , L_1 , V_6 -> V_8 , V_4 -> V_14 ) ;
V_13 = F_12 ( & V_4 -> V_2 ) ;
if ( V_13 < 0 ) {
F_13 ( & V_4 -> V_2 , L_2 ,
F_9 ( & V_4 -> V_2 ) , V_13 ) ;
goto V_15;
}
F_14 ( & V_4 -> V_2 , L_3 , F_9 ( & V_4 -> V_2 ) ) ;
V_15:
return V_13 ;
}
void F_15 ( struct V_3 * V_4 )
{
F_16 ( & V_4 -> V_2 ) ;
}
static inline int
F_17 ( struct V_5 * V_6 , T_1 V_16 , T_1 V_17 )
{
if ( ! V_6 || ! V_6 -> V_18 || V_6 -> V_2 . type != & V_19 )
return - V_20 ;
return V_6 -> V_18 ( V_6 , V_16 , V_17 ) ;
}
static inline int F_18 ( struct V_5 * V_6 , T_1 V_16 ,
T_1 V_17 , T_2 V_21 , T_1 * V_22 , T_3 V_23 )
{
if ( ! V_6 || ! V_6 -> V_24 || V_6 -> V_2 . type != & V_19 )
return - V_20 ;
return V_6 -> V_24 ( V_6 , V_16 , V_17 , V_21 , V_22 , V_23 ) ;
}
static inline int F_19 ( struct V_5 * V_6 , T_1 V_16 ,
T_1 V_17 , T_2 V_21 , const T_1 * V_22 , T_3 V_23 )
{
if ( ! V_6 || ! V_6 -> V_25 || V_6 -> V_2 . type != & V_19 )
return - V_20 ;
return V_6 -> V_25 ( V_6 , V_16 , V_17 , V_21 , V_22 , V_23 ) ;
}
int F_20 ( struct V_3 * V_4 , T_1 V_21 , T_1 * V_22 )
{
if ( V_21 > 0x1F )
return - V_20 ;
return F_18 ( V_4 -> V_6 , V_26 , V_4 -> V_14 , V_21 ,
V_22 , 1 ) ;
}
int F_21 ( struct V_3 * V_4 , T_1 V_21 , T_1 * V_22 ,
T_3 V_23 )
{
if ( V_23 == 0 || V_23 > 16 )
return - V_20 ;
return F_18 ( V_4 -> V_6 , V_27 , V_4 -> V_14 , V_21 ,
V_22 , V_23 ) ;
}
int F_22 ( struct V_3 * V_4 , T_2 V_21 , T_1 * V_22 ,
T_3 V_23 )
{
if ( V_23 == 0 || V_23 > 8 )
return - V_20 ;
return F_18 ( V_4 -> V_6 , V_28 , V_4 -> V_14 , V_21 ,
V_22 , V_23 ) ;
}
int F_23 ( struct V_3 * V_4 , T_1 V_21 , T_1 V_29 )
{
if ( V_21 > 0x1F )
return - V_20 ;
return F_19 ( V_4 -> V_6 , V_30 , V_4 -> V_14 , V_21 ,
& V_29 , 1 ) ;
}
int F_24 ( struct V_3 * V_4 , T_1 V_29 )
{
return F_19 ( V_4 -> V_6 , V_31 , V_4 -> V_14 , 0 ,
& V_29 , 1 ) ;
}
int F_25 ( struct V_3 * V_4 , T_1 V_21 , const T_1 * V_22 ,
T_3 V_23 )
{
if ( V_23 == 0 || V_23 > 16 )
return - V_20 ;
return F_19 ( V_4 -> V_6 , V_32 , V_4 -> V_14 , V_21 ,
V_22 , V_23 ) ;
}
int F_26 ( struct V_3 * V_4 , T_2 V_21 , const T_1 * V_22 ,
T_3 V_23 )
{
if ( V_23 == 0 || V_23 > 8 )
return - V_20 ;
return F_19 ( V_4 -> V_6 , V_33 , V_4 -> V_14 ,
V_21 , V_22 , V_23 ) ;
}
int F_27 ( struct V_3 * V_4 )
{
return F_17 ( V_4 -> V_6 , V_34 , V_4 -> V_14 ) ;
}
int F_28 ( struct V_3 * V_4 )
{
return F_17 ( V_4 -> V_6 , V_35 , V_4 -> V_14 ) ;
}
int F_29 ( struct V_3 * V_4 )
{
return F_17 ( V_4 -> V_6 , V_36 , V_4 -> V_14 ) ;
}
int F_30 ( struct V_3 * V_4 )
{
return F_17 ( V_4 -> V_6 , V_37 , V_4 -> V_14 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
const struct V_38 * V_39 = F_32 ( V_2 -> V_40 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_13 ;
V_13 = F_29 ( V_4 ) ;
if ( V_13 )
goto V_41;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
V_13 = V_39 -> V_42 ( V_4 ) ;
if ( V_13 )
goto V_43;
return 0 ;
V_43:
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
V_41:
return V_13 ;
}
static int F_39 ( struct V_1 * V_2 )
{
const struct V_38 * V_39 = F_32 ( V_2 -> V_40 ) ;
F_40 ( V_2 ) ;
V_39 -> remove ( F_2 ( V_2 ) ) ;
F_38 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_41 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
V_4 = F_42 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = V_6 ;
F_43 ( & V_4 -> V_2 ) ;
V_4 -> V_2 . V_45 = & V_6 -> V_2 ;
V_4 -> V_2 . V_46 = & V_47 ;
V_4 -> V_2 . type = & V_48 ;
return V_4 ;
}
struct V_5 * F_44 ( struct V_1 * V_45 ,
T_3 V_49 )
{
struct V_5 * V_6 ;
int V_50 ;
if ( F_45 ( ! V_45 ) )
return NULL ;
V_6 = F_42 ( sizeof( * V_6 ) + V_49 , V_44 ) ;
if ( ! V_6 )
return NULL ;
F_43 ( & V_6 -> V_2 ) ;
V_6 -> V_2 . type = & V_19 ;
V_6 -> V_2 . V_46 = & V_47 ;
V_6 -> V_2 . V_45 = V_45 ;
V_6 -> V_2 . V_51 = V_45 -> V_51 ;
F_46 ( V_6 , & V_6 [ 1 ] ) ;
V_50 = F_47 ( & V_7 , 0 , 0 , V_44 ) ;
if ( V_50 < 0 ) {
F_13 ( V_45 ,
L_4 ) ;
F_48 ( V_6 ) ;
return NULL ;
}
V_6 -> V_8 = V_50 ;
F_11 ( & V_6 -> V_2 , L_5 , V_50 ) ;
F_14 ( & V_6 -> V_2 , L_6 , V_6 , V_50 ) ;
return V_6 ;
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_52 * V_53 ;
int V_13 ;
if ( ! V_6 -> V_2 . V_51 )
return;
F_50 (ctrl->dev.of_node, node) {
struct V_3 * V_4 ;
T_4 V_54 [ 2 ] ;
F_14 ( & V_6 -> V_2 , L_7 , V_53 -> V_55 ) ;
V_13 = F_51 ( V_53 , L_8 , V_54 , 2 ) ;
if ( V_13 ) {
F_13 ( & V_6 -> V_2 ,
L_9 ,
V_53 -> V_55 , V_13 ) ;
continue;
}
if ( V_54 [ 1 ] != V_56 ) {
F_13 ( & V_6 -> V_2 ,
L_10 ,
V_53 -> V_55 ) ;
continue;
}
if ( V_54 [ 0 ] >= V_57 ) {
F_13 ( & V_6 -> V_2 ,
L_11 ,
V_53 -> V_55 ) ;
continue;
}
F_14 ( & V_6 -> V_2 , L_12 , V_54 [ 0 ] ) ;
V_4 = F_41 ( V_6 ) ;
if ( ! V_4 )
continue;
V_4 -> V_2 . V_51 = V_53 ;
V_4 -> V_14 = ( T_1 ) V_54 [ 0 ] ;
V_13 = F_10 ( V_4 ) ;
if ( V_13 ) {
F_13 ( & V_4 -> V_2 ,
L_13 , V_13 ) ;
F_52 ( V_4 ) ;
}
}
}
int F_53 ( struct V_5 * V_6 )
{
int V_58 ;
if ( F_45 ( ! V_47 . V_59 ) )
return - V_60 ;
V_58 = F_12 ( & V_6 -> V_2 ) ;
if ( V_58 )
return V_58 ;
if ( F_54 ( V_61 ) )
F_49 ( V_6 ) ;
F_14 ( & V_6 -> V_2 , L_14 ,
V_6 -> V_8 , & V_6 -> V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , void * V_29 )
{
struct V_3 * V_62 = F_2 ( V_2 ) ;
if ( V_2 -> type == & V_48 )
F_15 ( V_62 ) ;
return 0 ;
}
void F_56 ( struct V_5 * V_6 )
{
int V_63 ;
if ( ! V_6 )
return;
V_63 = F_57 ( & V_6 -> V_2 , NULL ,
F_55 ) ;
F_58 ( & V_6 -> V_2 ) ;
}
int F_59 ( struct V_38 * V_39 )
{
V_39 -> V_40 . V_46 = & V_47 ;
return F_60 ( & V_39 -> V_40 ) ;
}
static void T_5 F_61 ( void )
{
F_62 ( & V_47 ) ;
}
static int T_6 F_63 ( void )
{
return F_64 ( & V_47 ) ;
}
