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
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_9 = 0 ;
V_3 = F_5 ( V_2 -> V_4 -> V_5 , V_10 ,
& V_9 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_1 ,
V_8 , V_10 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_4 -> V_5 , V_10 ,
( V_9 | V_11 ) ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_2 ,
V_8 , V_10 ) ;
return V_3 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_12 = 0 ;
int V_3 ;
if ( V_2 -> V_13 -> V_14 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 ,
L_3 ) ;
return V_3 ;
}
}
V_3 = F_5 ( V_2 -> V_4 -> V_5 , V_15 ,
& V_12 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_1 ,
V_8 , V_15 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_4 -> V_5 , V_15 ,
( V_12 | V_16 ) ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_2 ,
V_8 , V_10 ) ;
return V_3 ;
}
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
union V_21 * V_22 )
{
struct V_1 * V_2 = F_8 ( V_18 ,
struct V_1 , V_23 ) ;
if ( V_20 == V_24 ) {
V_22 -> V_25 = V_2 -> V_26 ;
V_2 -> V_27 = V_2 -> V_26 ;
return 0 ;
}
return - V_28 ;
}
static T_2 F_9 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
int V_3 ;
T_1 V_31 = 0 ;
T_1 V_32 = 0 ;
V_3 = F_5 ( V_2 -> V_4 -> V_5 , V_33 ,
& V_31 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_4 ,
V_8 , V_33 ) ;
return V_34 ;
}
F_10 ( 75 ) ;
V_3 = F_5 ( V_2 -> V_4 -> V_5 , V_35 ,
& V_32 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_4 ,
V_8 , V_35 ) ;
return V_34 ;
}
if ( V_32 & V_16 ) {
V_3 = F_4 ( V_2 ) ;
if ( V_3 < 0 )
return V_34 ;
V_2 -> V_26 = 1 ;
} else {
V_2 -> V_26 = 0 ;
}
V_3 = F_2 ( V_2 -> V_4 -> V_5 , V_35 , 0x00 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 , L_5 ,
V_8 , V_35 ) ;
}
if ( V_2 -> V_27 != V_2 -> V_26 )
F_11 ( & V_2 -> V_23 ) ;
return V_34 ;
}
static struct V_36 *
F_12 ( struct V_37 * V_38 )
{
struct V_36 * V_13 ;
struct V_39 * V_40 = V_38 -> V_4 . V_41 ;
unsigned int V_42 ;
V_13 = F_13 ( & V_38 -> V_4 , sizeof( * V_13 ) , V_43 ) ;
if ( ! V_13 ) {
F_3 ( & V_38 -> V_4 , L_6 ) ;
return NULL ;
}
V_42 = F_14 ( V_40 , L_7 ) ;
V_13 -> V_14 = V_42 ;
V_13 -> V_44 = - 1 ;
return V_13 ;
}
static struct V_36 *
F_12 ( struct V_37 * V_38 )
{
return NULL ;
}
static int F_15 ( struct V_37 * V_38 )
{
struct V_1 * V_45 ;
struct V_36 * V_13 ;
T_1 V_31 = 0 ;
int V_3 ;
int V_29 ;
V_13 = F_16 ( V_38 -> V_4 . V_5 ) ;
if ( ! V_13 && V_38 -> V_4 . V_41 )
V_13 = F_12 ( V_38 ) ;
if ( ! V_13 ) {
F_3 ( & V_38 -> V_4 , L_8 ,
V_8 ) ;
return - V_46 ;
}
V_45 = F_13 ( & V_38 -> V_4 , sizeof( * V_45 ) , V_43 ) ;
if ( ! V_45 ) {
F_3 ( & V_38 -> V_4 , L_9 ) ;
return - V_47 ;
}
F_17 ( V_38 , V_45 ) ;
V_45 -> V_4 = & V_38 -> V_4 ;
V_45 -> V_13 = V_13 ;
V_45 -> V_23 . V_48 = L_10 ;
V_45 -> V_23 . type = V_49 ;
V_45 -> V_23 . V_50 = F_7 ;
V_45 -> V_23 . V_51 = V_52 ;
V_45 -> V_23 . V_53 = F_18 ( V_52 ) ;
V_45 -> V_23 . V_54 = V_13 -> V_54 ;
V_45 -> V_23 . V_55 = V_13 -> V_55 ;
V_45 -> V_23 . V_41 = V_38 -> V_4 . V_41 ;
V_3 = F_19 ( & V_38 -> V_4 , & V_45 -> V_23 ) ;
if ( V_3 ) {
F_3 ( & V_38 -> V_4 , L_11 ) ;
return V_3 ;
}
V_29 = F_20 ( V_38 , 0 ) ;
if ( V_29 <= 0 ) {
F_21 ( & V_38 -> V_4 , L_12 , V_29 ) ;
V_3 = V_29 ;
goto V_56;
}
V_45 -> V_29 = V_29 ;
V_3 = F_22 ( & V_38 -> V_4 , V_29 , NULL ,
F_9 , 0 , L_13 , V_45 ) ;
if ( V_3 ) {
F_3 ( V_45 -> V_4 , L_14 , V_29 ,
V_3 ) ;
goto V_57;
}
V_3 = F_6 ( V_45 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_38 -> V_4 , L_15 , V_3 ) ;
goto V_57;
}
V_3 = F_5 ( V_45 -> V_4 -> V_5 , V_33 ,
& V_31 ) ;
if ( V_3 < 0 ) {
F_3 ( V_45 -> V_4 , L_16 , V_8 ,
V_33 ) ;
goto V_57;
}
if ( V_31 != 0 ) {
V_3 = F_4 ( V_45 ) ;
if ( V_3 < 0 ) {
F_3 ( V_45 -> V_4 , L_17 ) ;
goto V_57;
}
V_45 -> V_26 = 1 ;
F_11 ( & V_45 -> V_23 ) ;
}
return 0 ;
V_57:
F_23 ( V_45 -> V_4 , V_29 , V_45 ) ;
V_56:
F_24 ( & V_45 -> V_23 ) ;
return V_3 ;
}
static int F_25 ( struct V_37 * V_38 )
{
struct V_1 * V_45 = F_26 ( V_38 ) ;
F_23 ( V_45 -> V_4 , V_45 -> V_29 , V_45 ) ;
F_24 ( & V_45 -> V_23 ) ;
return 0 ;
}
