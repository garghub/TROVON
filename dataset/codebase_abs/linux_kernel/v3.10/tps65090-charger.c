static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 -> V_5 , V_6 ,
V_7 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_1 ,
V_8 , V_6 ) ;
return V_3 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_9 )
{
int V_3 ;
T_1 V_10 = 0 ;
V_3 = F_5 ( V_2 -> V_4 -> V_5 , V_11 ,
& V_10 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_1 ,
V_8 , V_11 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_4 -> V_5 , V_11 ,
( V_10 | V_12 ) ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_1 ,
V_8 , V_11 ) ;
return V_3 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_13 -> V_14 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 ,
L_2 ) ;
return V_3 ;
}
}
return 0 ;
}
static int F_7 ( struct V_15 * V_16 ,
enum V_17 V_18 ,
union V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_16 ,
struct V_1 , V_21 ) ;
if ( V_18 == V_22 ) {
V_20 -> V_23 = V_2 -> V_24 ;
V_2 -> V_25 = V_2 -> V_24 ;
return 0 ;
}
return - V_26 ;
}
static T_2 F_9 ( int V_27 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
int V_3 ;
T_1 V_29 = 0 ;
T_1 V_30 = 0 ;
V_3 = F_5 ( V_2 -> V_4 -> V_5 , V_31 ,
& V_29 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_3 ,
V_8 , V_31 ) ;
return V_32 ;
}
F_10 ( 75 ) ;
V_3 = F_5 ( V_2 -> V_4 -> V_5 , V_33 ,
& V_30 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_3 ,
V_8 , V_33 ) ;
return V_32 ;
}
if ( V_30 & V_34 ) {
V_3 = F_4 ( V_2 , 1 ) ;
if ( V_3 < 0 )
return V_32 ;
V_2 -> V_24 = 1 ;
} else {
V_2 -> V_24 = 0 ;
}
if ( V_2 -> V_25 != V_2 -> V_24 )
F_11 ( & V_2 -> V_21 ) ;
return V_32 ;
}
static struct V_35 *
F_12 ( struct V_36 * V_37 )
{
struct V_35 * V_13 ;
struct V_38 * V_39 = V_37 -> V_4 . V_40 ;
unsigned int V_41 ;
V_13 = F_13 ( & V_37 -> V_4 , sizeof( * V_13 ) , V_42 ) ;
if ( ! V_13 ) {
F_3 ( & V_37 -> V_4 , L_4 ) ;
return NULL ;
}
V_41 = F_14 ( V_39 , L_5 ) ;
V_13 -> V_14 = V_41 ;
V_13 -> V_43 = - 1 ;
return V_13 ;
}
static struct V_35 *
F_12 ( struct V_36 * V_37 )
{
return NULL ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_1 * V_44 ;
struct V_35 * V_13 ;
T_1 V_29 = 0 ;
int V_3 ;
int V_27 ;
V_13 = F_16 ( V_37 -> V_4 . V_5 ) ;
if ( ! V_13 && V_37 -> V_4 . V_40 )
V_13 = F_12 ( V_37 ) ;
if ( ! V_13 ) {
F_3 ( & V_37 -> V_4 , L_6 ,
V_8 ) ;
return - V_45 ;
}
V_44 = F_13 ( & V_37 -> V_4 , sizeof( * V_44 ) , V_42 ) ;
if ( ! V_44 ) {
F_3 ( & V_37 -> V_4 , L_7 ) ;
return - V_46 ;
}
F_17 ( & V_37 -> V_4 , V_44 ) ;
V_44 -> V_4 = & V_37 -> V_4 ;
V_44 -> V_13 = V_13 ;
V_44 -> V_21 . V_47 = L_8 ;
V_44 -> V_21 . type = V_48 ;
V_44 -> V_21 . V_49 = F_7 ;
V_44 -> V_21 . V_50 = V_51 ;
V_44 -> V_21 . V_52 = F_18 ( V_51 ) ;
V_44 -> V_21 . V_53 = V_13 -> V_53 ;
V_44 -> V_21 . V_54 = V_13 -> V_54 ;
V_3 = F_19 ( & V_37 -> V_4 , & V_44 -> V_21 ) ;
if ( V_3 ) {
F_3 ( & V_37 -> V_4 , L_9 ) ;
return V_3 ;
}
V_27 = F_20 ( V_37 , 0 ) ;
if ( V_27 <= 0 ) {
F_21 ( & V_37 -> V_4 , L_10 , V_27 ) ;
V_3 = V_27 ;
goto V_55;
}
V_44 -> V_27 = V_27 ;
V_3 = F_22 ( & V_37 -> V_4 , V_27 , NULL ,
F_9 , 0 , L_11 , V_44 ) ;
if ( V_3 ) {
F_3 ( V_44 -> V_4 , L_12 , V_27 ,
V_3 ) ;
goto V_56;
}
V_3 = F_6 ( V_44 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_37 -> V_4 , L_13 , V_3 ) ;
goto V_56;
}
V_3 = F_5 ( V_44 -> V_4 -> V_5 , V_31 ,
& V_29 ) ;
if ( V_3 < 0 ) {
F_3 ( V_44 -> V_4 , L_14 , V_8 ,
V_31 ) ;
goto V_56;
}
if ( V_29 != 0 ) {
V_3 = F_4 ( V_44 , 1 ) ;
if ( V_3 < 0 ) {
F_3 ( V_44 -> V_4 , L_15 ) ;
goto V_56;
}
V_44 -> V_24 = 1 ;
F_11 ( & V_44 -> V_21 ) ;
}
return 0 ;
V_56:
F_23 ( V_44 -> V_4 , V_27 , V_44 ) ;
V_55:
F_24 ( & V_44 -> V_21 ) ;
return V_3 ;
}
static int F_25 ( struct V_36 * V_37 )
{
struct V_1 * V_44 = F_26 ( & V_37 -> V_4 ) ;
F_23 ( V_44 -> V_4 , V_44 -> V_27 , V_44 ) ;
F_24 ( & V_44 -> V_21 ) ;
return 0 ;
}
