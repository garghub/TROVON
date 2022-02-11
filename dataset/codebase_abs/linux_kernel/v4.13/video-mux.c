static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_7 * V_9 , T_1 V_10 )
{
struct V_2 * V_3 = F_4 ( V_6 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_12 = 0 ;
if ( V_8 -> V_10 & V_13 )
return 0 ;
F_5 ( V_3 -> V_14 , L_1 ,
V_9 -> V_6 -> V_15 , V_9 -> V_16 , V_8 -> V_6 -> V_15 ,
V_8 -> V_16 , V_10 & V_17 ) ;
F_6 ( & V_11 -> V_18 ) ;
if ( V_10 & V_17 ) {
if ( V_11 -> V_19 == V_8 -> V_16 )
goto V_20;
if ( V_11 -> V_19 >= 0 ) {
V_12 = - V_21 ;
goto V_20;
}
F_5 ( V_3 -> V_14 , L_2 , V_8 -> V_16 ) ;
V_12 = F_7 ( V_11 -> V_22 , V_8 -> V_16 ) ;
if ( V_12 < 0 )
goto V_20;
V_11 -> V_19 = V_8 -> V_16 ;
} else {
if ( V_11 -> V_19 != V_8 -> V_16 )
goto V_20;
F_5 ( V_3 -> V_14 , L_3 ) ;
V_11 -> V_19 = - 1 ;
}
V_20:
F_8 ( & V_11 -> V_18 ) ;
return V_12 ;
}
static int F_9 ( struct V_2 * V_3 , int V_23 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_2 * V_24 ;
struct V_7 * V_25 ;
if ( V_11 -> V_19 == - 1 ) {
F_10 ( V_3 -> V_14 , L_4 ) ;
return - V_26 ;
}
V_25 = F_11 ( & V_3 -> V_6 . V_27 [ V_11 -> V_19 ] ) ;
if ( ! V_25 ) {
F_10 ( V_3 -> V_14 , L_5 ) ;
return - V_28 ;
}
if ( ! F_12 ( V_25 -> V_6 ) ) {
F_10 ( V_3 -> V_14 , L_6 ) ;
return - V_29 ;
}
V_24 = F_4 ( V_25 -> V_6 ) ;
return F_13 ( V_24 , V_30 , V_31 , V_23 ) ;
}
static struct V_32 *
F_14 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
unsigned int V_25 , T_1 V_35 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
switch ( V_35 ) {
case V_36 :
return F_15 ( V_3 , V_34 , V_25 ) ;
case V_37 :
return & V_11 -> V_38 [ V_25 ] ;
default:
return NULL ;
}
}
static int F_16 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
struct V_39 * V_40 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
F_6 ( & V_11 -> V_18 ) ;
V_40 -> V_41 = * F_14 ( V_3 , V_34 , V_40 -> V_25 ,
V_40 -> V_35 ) ;
F_8 ( & V_11 -> V_18 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
struct V_39 * V_40 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_32 * V_42 ;
struct V_7 * V_25 = & V_11 -> V_27 [ V_40 -> V_25 ] ;
V_42 = F_14 ( V_3 , V_34 , V_40 -> V_25 ,
V_40 -> V_35 ) ;
if ( ! V_42 )
return - V_26 ;
F_6 ( & V_11 -> V_18 ) ;
if ( ( V_25 -> V_10 & V_13 ) && V_11 -> V_19 >= 0 )
V_40 -> V_41 = V_11 -> V_38 [ V_11 -> V_19 ] ;
* V_42 = V_40 -> V_41 ;
F_8 ( & V_11 -> V_18 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_11 )
{
struct V_43 * V_14 = V_11 -> V_4 . V_14 ;
struct V_44 args ;
struct V_45 V_22 ;
struct V_46 * V_46 ;
T_1 V_47 , V_48 ;
int V_12 ;
V_12 = F_19 ( V_14 -> V_49 , L_7 ,
L_8 , 0 , & args ) ;
if ( V_12 )
return V_12 ;
if ( ! F_20 ( args . V_50 , L_9 ) )
return - V_26 ;
V_46 = F_21 ( args . V_50 -> V_51 ) ;
if ( F_22 ( V_46 ) )
return F_23 ( V_46 ) ;
V_12 = F_24 ( args . V_50 , L_10 ,
2 * args . args [ 0 ] , & V_47 ) ;
if ( ! V_12 )
V_12 = F_24 ( args . V_50 , L_10 ,
2 * args . args [ 0 ] + 1 , & V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
V_22 . V_47 = V_47 ;
V_22 . V_52 = F_25 ( V_48 ) - 1 ;
V_22 . V_53 = F_26 ( V_48 ) - 1 ;
V_11 -> V_22 = F_27 ( V_14 , V_46 , V_22 ) ;
if ( F_22 ( V_11 -> V_22 ) )
return F_23 ( V_11 -> V_22 ) ;
return 0 ;
}
static int F_28 ( struct V_54 * V_55 )
{
struct V_56 * V_50 = V_55 -> V_14 . V_49 ;
struct V_43 * V_14 = & V_55 -> V_14 ;
struct V_56 * V_57 ;
struct V_1 * V_11 ;
unsigned int V_58 = 0 ;
int V_12 ;
int V_59 ;
V_11 = F_29 ( V_14 , sizeof( * V_11 ) , V_60 ) ;
if ( ! V_11 )
return - V_61 ;
F_30 ( V_55 , V_11 ) ;
F_31 ( & V_11 -> V_4 , & V_62 ) ;
snprintf ( V_11 -> V_4 . V_15 , sizeof( V_11 -> V_4 . V_15 ) , L_11 , V_50 -> V_15 ) ;
V_11 -> V_4 . V_10 |= V_63 ;
V_11 -> V_4 . V_14 = V_14 ;
F_32 (np, ep) {
struct V_64 V_65 ;
F_33 ( V_57 , & V_65 ) ;
V_58 = F_34 ( V_58 , V_65 . V_66 + 1 ) ;
}
if ( V_58 < 2 ) {
F_10 ( V_14 , L_12 , V_58 ) ;
return - V_26 ;
}
V_12 = F_18 ( V_11 ) ;
if ( V_12 ) {
if ( V_12 != - V_67 )
F_10 ( V_14 , L_13 , V_12 ) ;
return V_12 ;
}
F_35 ( & V_11 -> V_18 ) ;
V_11 -> V_19 = - 1 ;
V_11 -> V_27 = F_36 ( V_14 , V_58 , sizeof( * V_11 -> V_27 ) ,
V_60 ) ;
V_11 -> V_38 = F_36 ( V_14 , V_58 ,
sizeof( * V_11 -> V_38 ) ,
V_60 ) ;
for ( V_59 = 0 ; V_59 < V_58 - 1 ; V_59 ++ )
V_11 -> V_27 [ V_59 ] . V_10 = V_68 ;
V_11 -> V_27 [ V_58 - 1 ] . V_10 = V_13 ;
V_11 -> V_4 . V_6 . V_69 = V_70 ;
V_12 = F_37 ( & V_11 -> V_4 . V_6 , V_58 ,
V_11 -> V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 -> V_4 . V_6 . V_71 = & V_72 ;
return F_38 ( & V_11 -> V_4 ) ;
}
static int F_39 ( struct V_54 * V_55 )
{
struct V_1 * V_11 = F_40 ( V_55 ) ;
struct V_2 * V_3 = & V_11 -> V_4 ;
F_41 ( V_3 ) ;
F_42 ( & V_3 -> V_6 ) ;
return 0 ;
}
