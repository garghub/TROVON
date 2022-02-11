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
int V_18 ;
if ( ! V_6 || ! V_6 -> V_19 || V_6 -> V_2 . type != & V_20 )
return - V_21 ;
V_18 = V_6 -> V_19 ( V_6 , V_16 , V_17 ) ;
F_18 ( V_16 , V_17 , V_18 ) ;
return V_18 ;
}
static inline int F_19 ( struct V_5 * V_6 , T_1 V_16 ,
T_1 V_17 , T_2 V_22 , T_1 * V_23 , T_3 V_24 )
{
int V_18 ;
if ( ! V_6 || ! V_6 -> V_25 || V_6 -> V_2 . type != & V_20 )
return - V_21 ;
F_20 ( V_16 , V_17 , V_22 ) ;
V_18 = V_6 -> V_25 ( V_6 , V_16 , V_17 , V_22 , V_23 , V_24 ) ;
F_21 ( V_16 , V_17 , V_22 , V_18 , V_24 , V_23 ) ;
return V_18 ;
}
static inline int F_22 ( struct V_5 * V_6 , T_1 V_16 ,
T_1 V_17 , T_2 V_22 , const T_1 * V_23 , T_3 V_24 )
{
int V_18 ;
if ( ! V_6 || ! V_6 -> V_26 || V_6 -> V_2 . type != & V_20 )
return - V_21 ;
F_23 ( V_16 , V_17 , V_22 , V_24 , V_23 ) ;
V_18 = V_6 -> V_26 ( V_6 , V_16 , V_17 , V_22 , V_23 , V_24 ) ;
F_24 ( V_16 , V_17 , V_22 , V_18 ) ;
return V_18 ;
}
int F_25 ( struct V_3 * V_4 , T_1 V_22 , T_1 * V_23 )
{
if ( V_22 > 0x1F )
return - V_21 ;
return F_19 ( V_4 -> V_6 , V_27 , V_4 -> V_14 , V_22 ,
V_23 , 1 ) ;
}
int F_26 ( struct V_3 * V_4 , T_1 V_22 , T_1 * V_23 ,
T_3 V_24 )
{
if ( V_24 == 0 || V_24 > 16 )
return - V_21 ;
return F_19 ( V_4 -> V_6 , V_28 , V_4 -> V_14 , V_22 ,
V_23 , V_24 ) ;
}
int F_27 ( struct V_3 * V_4 , T_2 V_22 , T_1 * V_23 ,
T_3 V_24 )
{
if ( V_24 == 0 || V_24 > 8 )
return - V_21 ;
return F_19 ( V_4 -> V_6 , V_29 , V_4 -> V_14 , V_22 ,
V_23 , V_24 ) ;
}
int F_28 ( struct V_3 * V_4 , T_1 V_22 , T_1 V_30 )
{
if ( V_22 > 0x1F )
return - V_21 ;
return F_22 ( V_4 -> V_6 , V_31 , V_4 -> V_14 , V_22 ,
& V_30 , 1 ) ;
}
int F_29 ( struct V_3 * V_4 , T_1 V_30 )
{
return F_22 ( V_4 -> V_6 , V_32 , V_4 -> V_14 , 0 ,
& V_30 , 1 ) ;
}
int F_30 ( struct V_3 * V_4 , T_1 V_22 , const T_1 * V_23 ,
T_3 V_24 )
{
if ( V_24 == 0 || V_24 > 16 )
return - V_21 ;
return F_22 ( V_4 -> V_6 , V_33 , V_4 -> V_14 , V_22 ,
V_23 , V_24 ) ;
}
int F_31 ( struct V_3 * V_4 , T_2 V_22 , const T_1 * V_23 ,
T_3 V_24 )
{
if ( V_24 == 0 || V_24 > 8 )
return - V_21 ;
return F_22 ( V_4 -> V_6 , V_34 , V_4 -> V_14 ,
V_22 , V_23 , V_24 ) ;
}
int F_32 ( struct V_3 * V_4 )
{
return F_17 ( V_4 -> V_6 , V_35 , V_4 -> V_14 ) ;
}
int F_33 ( struct V_3 * V_4 )
{
return F_17 ( V_4 -> V_6 , V_36 , V_4 -> V_14 ) ;
}
int F_34 ( struct V_3 * V_4 )
{
return F_17 ( V_4 -> V_6 , V_37 , V_4 -> V_14 ) ;
}
int F_35 ( struct V_3 * V_4 )
{
return F_17 ( V_4 -> V_6 , V_38 , V_4 -> V_14 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_37 ( V_2 -> V_41 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_13 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
V_13 = V_40 -> V_42 ( V_4 ) ;
if ( V_13 )
goto V_43;
return 0 ;
V_43:
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
return V_13 ;
}
static int F_44 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_37 ( V_2 -> V_41 ) ;
F_45 ( V_2 ) ;
V_40 -> remove ( F_2 ( V_2 ) ) ;
F_43 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_46 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
V_4 = F_47 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = V_6 ;
F_48 ( & V_4 -> V_2 ) ;
V_4 -> V_2 . V_45 = & V_6 -> V_2 ;
V_4 -> V_2 . V_46 = & V_47 ;
V_4 -> V_2 . type = & V_48 ;
return V_4 ;
}
struct V_5 * F_49 ( struct V_1 * V_45 ,
T_3 V_49 )
{
struct V_5 * V_6 ;
int V_50 ;
if ( F_50 ( ! V_45 ) )
return NULL ;
V_6 = F_47 ( sizeof( * V_6 ) + V_49 , V_44 ) ;
if ( ! V_6 )
return NULL ;
F_48 ( & V_6 -> V_2 ) ;
V_6 -> V_2 . type = & V_20 ;
V_6 -> V_2 . V_46 = & V_47 ;
V_6 -> V_2 . V_45 = V_45 ;
V_6 -> V_2 . V_51 = V_45 -> V_51 ;
F_51 ( V_6 , & V_6 [ 1 ] ) ;
V_50 = F_52 ( & V_7 , 0 , 0 , V_44 ) ;
if ( V_50 < 0 ) {
F_13 ( V_45 ,
L_4 ) ;
F_53 ( V_6 ) ;
return NULL ;
}
V_6 -> V_8 = V_50 ;
F_11 ( & V_6 -> V_2 , L_5 , V_50 ) ;
F_14 ( & V_6 -> V_2 , L_6 , V_6 , V_50 ) ;
return V_6 ;
}
static void F_54 ( struct V_5 * V_6 )
{
struct V_52 * V_53 ;
int V_13 ;
if ( ! V_6 -> V_2 . V_51 )
return;
F_55 (ctrl->dev.of_node, node) {
struct V_3 * V_4 ;
T_4 V_54 [ 2 ] ;
F_14 ( & V_6 -> V_2 , L_7 , V_53 -> V_55 ) ;
V_13 = F_56 ( V_53 , L_8 , V_54 , 2 ) ;
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
V_4 = F_46 ( V_6 ) ;
if ( ! V_4 )
continue;
V_4 -> V_2 . V_51 = V_53 ;
V_4 -> V_14 = ( T_1 ) V_54 [ 0 ] ;
V_13 = F_10 ( V_4 ) ;
if ( V_13 ) {
F_13 ( & V_4 -> V_2 ,
L_13 , V_13 ) ;
F_57 ( V_4 ) ;
}
}
}
int F_58 ( struct V_5 * V_6 )
{
int V_18 ;
if ( F_50 ( ! V_47 . V_58 ) )
return - V_59 ;
V_18 = F_12 ( & V_6 -> V_2 ) ;
if ( V_18 )
return V_18 ;
if ( F_59 ( V_60 ) )
F_54 ( V_6 ) ;
F_14 ( & V_6 -> V_2 , L_14 ,
V_6 -> V_8 , & V_6 -> V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , void * V_30 )
{
struct V_3 * V_61 = F_2 ( V_2 ) ;
if ( V_2 -> type == & V_48 )
F_15 ( V_61 ) ;
return 0 ;
}
void F_61 ( struct V_5 * V_6 )
{
int V_62 ;
if ( ! V_6 )
return;
V_62 = F_62 ( & V_6 -> V_2 , NULL ,
F_60 ) ;
F_63 ( & V_6 -> V_2 ) ;
}
int F_64 ( struct V_39 * V_40 )
{
V_40 -> V_41 . V_46 = & V_47 ;
return F_65 ( & V_40 -> V_41 ) ;
}
static void T_5 F_66 ( void )
{
F_67 ( & V_47 ) ;
}
static int T_6 F_68 ( void )
{
return F_69 ( & V_47 ) ;
}
