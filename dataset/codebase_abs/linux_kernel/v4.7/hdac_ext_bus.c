static void F_1 ( T_1 V_1 , T_1 T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
static T_1 F_3 ( T_1 T_2 * V_2 )
{
return F_4 ( V_2 ) ;
}
static void F_5 ( T_3 V_1 , T_3 T_2 * V_2 )
{
F_6 ( V_1 , V_2 ) ;
}
static T_3 F_7 ( T_3 T_2 * V_2 )
{
return F_8 ( V_2 ) ;
}
static void F_9 ( T_4 V_1 , T_4 T_2 * V_2 )
{
F_10 ( V_1 , V_2 ) ;
}
static T_4 F_11 ( T_4 T_2 * V_2 )
{
return F_12 ( V_2 ) ;
}
static int F_13 ( struct V_3 * V_4 , int type ,
T_5 V_5 , struct V_6 * V_7 )
{
return F_14 ( type , V_4 -> V_8 , V_5 , V_7 ) ;
}
static void F_15 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
}
int F_17 ( struct V_9 * V_10 , struct V_11 * V_8 ,
const struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
int V_16 ;
static int V_17 ;
if ( V_15 == NULL )
V_15 = & V_18 ;
V_16 = F_18 ( & V_10 -> V_4 , V_8 , V_13 , V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
F_19 ( & V_10 -> V_19 ) ;
V_10 -> V_17 = V_17 ++ ;
F_20 ( & V_10 -> V_20 ) ;
V_10 -> V_21 = true ;
return 0 ;
}
void F_21 ( struct V_9 * V_10 )
{
F_22 ( & V_10 -> V_4 ) ;
F_23 ( ! F_24 ( & V_10 -> V_19 ) ) ;
}
static void F_25 ( struct V_11 * V_8 )
{
F_26 ( F_27 ( V_8 , struct V_22 , V_8 ) ) ;
}
int F_28 ( struct V_9 * V_10 , int V_2 )
{
struct V_23 * V_24 ;
struct V_22 * V_25 = NULL ;
struct V_3 * V_4 = F_29 ( V_10 ) ;
char V_26 [ 15 ] ;
int V_16 ;
V_24 = F_30 ( sizeof( * V_24 ) , V_27 ) ;
if ( ! V_24 )
return - V_28 ;
V_25 = & V_24 -> V_29 ;
V_24 -> V_10 = V_10 ;
snprintf ( V_26 , sizeof( V_26 ) , L_1 , V_10 -> V_17 , V_2 ) ;
V_16 = F_31 ( V_25 , V_4 , V_26 , V_2 ) ;
if ( V_16 < 0 ) {
F_32 ( V_4 -> V_8 , L_2 ) ;
return V_16 ;
}
V_25 -> type = V_30 ;
V_25 -> V_8 . V_31 = F_25 ;
V_16 = F_33 ( V_25 ) ;
if ( V_16 ) {
F_32 ( V_4 -> V_8 , L_3 ) ;
F_26 ( V_25 ) ;
return V_16 ;
}
return 0 ;
}
void F_26 ( struct V_22 * V_25 )
{
struct V_23 * V_24 = F_34 ( V_25 ) ;
F_35 ( V_25 ) ;
F_36 ( V_24 ) ;
}
void F_37 ( struct V_9 * V_10 )
{
struct V_22 * V_32 , * V_33 ;
F_38 (codec, __codec, &ebus->bus.codec_list, list) {
F_39 ( V_32 ) ;
F_40 ( & V_32 -> V_8 ) ;
}
}
static inline struct V_34 * F_41 ( struct V_11 * V_8 )
{
struct V_35 * V_36 = F_42 ( V_8 -> V_37 ) ;
struct V_34 * V_38 = F_43 ( V_36 ) ;
return V_38 ;
}
static inline struct V_23 * F_44 ( struct V_11 * V_8 )
{
struct V_22 * V_25 = F_45 ( V_8 ) ;
struct V_23 * V_24 = F_34 ( V_25 ) ;
return V_24 ;
}
static int F_46 ( struct V_11 * V_8 )
{
return ( F_41 ( V_8 ) ) -> F_47 ( F_44 ( V_8 ) ) ;
}
static int F_48 ( struct V_11 * V_8 )
{
return ( F_41 ( V_8 ) ) -> remove ( F_44 ( V_8 ) ) ;
}
static void F_49 ( struct V_11 * V_8 )
{
return ( F_41 ( V_8 ) ) -> F_50 ( F_44 ( V_8 ) ) ;
}
int F_51 ( struct V_34 * V_39 )
{
V_39 -> V_29 . type = V_30 ;
V_39 -> V_29 . V_37 . V_4 = & V_40 ;
if ( V_39 -> F_47 )
V_39 -> V_29 . V_37 . F_47 = F_46 ;
if ( V_39 -> remove )
V_39 -> V_29 . V_37 . remove = F_48 ;
if ( V_39 -> F_50 )
V_39 -> V_29 . V_37 . F_50 = F_49 ;
return F_52 ( & V_39 -> V_29 . V_37 ) ;
}
void F_53 ( struct V_34 * V_39 )
{
F_54 ( & V_39 -> V_29 . V_37 ) ;
}
