static void F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
int V_4 )
{
V_3 -> V_5 = V_1 [ V_6 ] & 0xff ;
V_3 -> V_7 = V_1 [ V_8 ] & 0xff ;
if ( V_4 )
V_3 -> V_9 = V_1 [ V_10 ] & 0x1f ;
else {
V_3 -> V_9 = V_1 [ V_10 ] & 0x0f ;
if ( V_1 [ V_10 ] & V_11 )
V_3 -> V_9 += 12 ;
}
V_3 -> V_12 = F_2 ( V_1 [ V_13 ] & 0xff ) - 1 ;
V_3 -> V_14 = V_1 [ V_15 ] & 0x1f ;
V_3 -> V_16 = ( V_1 [ V_17 ] & 0x0f ) - 1 ;
V_3 -> V_18 = V_1 [ V_19 ] & 0xff ;
V_3 -> V_20 = 0 ;
V_3 -> V_21 = 0 ;
}
static int F_3 ( struct V_2 * V_3 , T_1 * V_1 )
{
V_1 [ V_6 ] = V_3 -> V_5 ;
V_1 [ V_8 ] = V_3 -> V_7 ;
V_1 [ V_10 ] = V_3 -> V_9 ;
V_1 [ V_13 ] = 1 << V_3 -> V_12 ;
V_1 [ V_15 ] = V_3 -> V_14 ;
V_1 [ V_17 ] = V_3 -> V_16 + 1 ;
V_1 [ V_19 ] = V_3 -> V_18 ;
return 0 ;
}
static int F_4 ( struct V_22 * V_23 ,
enum V_24 V_25 )
{
int V_26 ;
unsigned int V_1 ;
if ( V_25 == V_27 )
V_1 = 1 << V_28 ;
else
V_1 = 1 << V_29 ;
V_26 = F_5 ( V_23 -> V_30 -> V_31 ,
V_32 , V_1 , V_1 ) ;
if ( V_26 < 0 )
F_6 ( V_23 -> V_33 , L_1 ,
V_34 , V_26 , V_1 ) ;
else {
F_7 ( V_35 ,
V_35 * 2 ) ;
}
return V_26 ;
}
static int F_8 ( struct V_36 * V_33 , struct V_2 * V_3 )
{
struct V_22 * V_23 = F_9 ( V_33 ) ;
T_1 V_1 [ V_37 ] ;
int V_26 ;
F_10 ( & V_23 -> V_38 ) ;
V_26 = F_4 ( V_23 , V_39 ) ;
if ( V_26 < 0 )
goto V_40;
V_26 = F_11 ( V_23 -> V_30 -> V_31 ,
V_41 , V_1 , V_37 ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_2 , V_34 ,
V_26 ) ;
goto V_40;
}
F_1 ( V_1 , V_3 , V_23 -> V_4 ) ;
V_26 = F_12 ( V_3 ) ;
V_40:
F_13 ( & V_23 -> V_38 ) ;
return V_26 ;
}
static int F_14 ( struct V_36 * V_33 , struct V_2 * V_3 )
{
struct V_22 * V_23 = F_9 ( V_33 ) ;
T_1 V_1 [ V_37 ] ;
int V_26 ;
V_26 = F_3 ( V_3 , V_1 ) ;
if ( V_26 < 0 )
return V_26 ;
F_10 ( & V_23 -> V_38 ) ;
V_26 = F_15 ( V_23 -> V_30 -> V_31 ,
V_41 , V_1 , V_37 ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_3 , V_34 ,
V_26 ) ;
goto V_40;
}
V_26 = F_4 ( V_23 , V_27 ) ;
V_40:
F_13 ( & V_23 -> V_38 ) ;
return V_26 ;
}
static int F_16 ( struct V_36 * V_33 , struct V_42 * V_43 )
{
struct V_22 * V_23 = F_9 ( V_33 ) ;
T_1 V_1 [ V_37 ] ;
unsigned int V_44 ;
int V_26 ;
F_10 ( & V_23 -> V_38 ) ;
V_26 = F_4 ( V_23 , V_39 ) ;
if ( V_26 < 0 )
goto V_40;
V_26 = F_11 ( V_23 -> V_30 -> V_31 ,
V_45 , V_1 , V_37 ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_4 ,
V_34 , __LINE__ , V_26 ) ;
goto V_40;
}
F_1 ( V_1 , & V_43 -> time , V_23 -> V_4 ) ;
V_43 -> V_46 = 0 ;
V_26 = F_17 ( V_23 -> V_30 -> V_31 ,
V_47 , & V_44 ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_5 ,
V_34 , __LINE__ , V_26 ) ;
goto V_40;
}
if ( V_44 )
V_43 -> V_46 = 1 ;
V_43 -> V_48 = 0 ;
V_26 = F_17 ( V_23 -> V_30 -> V_31 , V_49 , & V_44 ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_6 ,
V_34 , __LINE__ , V_26 ) ;
goto V_40;
}
if ( V_44 & ( 1 << 2 ) )
V_43 -> V_48 = 1 ;
V_40:
F_13 ( & V_23 -> V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
int V_26 ;
if ( ! F_19 ( & V_23 -> V_38 ) )
F_20 ( V_23 -> V_33 , L_7 , V_34 ) ;
V_26 = F_4 ( V_23 , V_39 ) ;
if ( V_26 < 0 )
goto V_40;
V_26 = F_21 ( V_23 -> V_30 -> V_31 ,
V_47 , 0 ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_8 ,
V_34 , V_26 ) ;
goto V_40;
}
V_26 = F_4 ( V_23 , V_27 ) ;
V_40:
return V_26 ;
}
static int F_22 ( struct V_22 * V_23 )
{
int V_26 ;
if ( ! F_19 ( & V_23 -> V_38 ) )
F_20 ( V_23 -> V_33 , L_7 ,
V_34 ) ;
V_26 = F_4 ( V_23 , V_39 ) ;
if ( V_26 < 0 )
goto V_40;
V_26 = F_21 ( V_23 -> V_30 -> V_31 ,
V_47 ,
V_50 ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_9 ,
V_34 , V_26 ) ;
goto V_40;
}
V_26 = F_4 ( V_23 , V_27 ) ;
V_40:
return V_26 ;
}
static int F_23 ( struct V_36 * V_33 , struct V_42 * V_43 )
{
struct V_22 * V_23 = F_9 ( V_33 ) ;
T_1 V_1 [ V_37 ] ;
int V_26 ;
V_26 = F_3 ( & V_43 -> time , V_1 ) ;
if ( V_26 < 0 )
return V_26 ;
F_10 ( & V_23 -> V_38 ) ;
V_26 = F_18 ( V_23 ) ;
if ( V_26 < 0 )
goto V_40;
V_26 = F_15 ( V_23 -> V_30 -> V_31 ,
V_45 , V_1 , V_37 ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_8 ,
V_34 , V_26 ) ;
goto V_40;
}
V_26 = F_4 ( V_23 , V_27 ) ;
if ( V_26 < 0 )
goto V_40;
if ( V_43 -> V_46 )
V_26 = F_22 ( V_23 ) ;
V_40:
F_13 ( & V_23 -> V_38 ) ;
return V_26 ;
}
static int F_24 ( struct V_36 * V_33 ,
unsigned int V_46 )
{
struct V_22 * V_23 = F_9 ( V_33 ) ;
int V_26 ;
F_10 ( & V_23 -> V_38 ) ;
if ( V_46 )
V_26 = F_22 ( V_23 ) ;
else
V_26 = F_18 ( V_23 ) ;
F_13 ( & V_23 -> V_38 ) ;
return V_26 ;
}
static T_2 F_25 ( int V_51 , void * V_1 )
{
struct V_22 * V_23 = V_1 ;
F_26 ( V_23 -> V_33 , L_10 , V_34 , V_51 ) ;
F_27 ( V_23 -> V_52 , 1 , V_53 | V_54 ) ;
return V_55 ;
}
static int F_28 ( struct V_22 * V_23 )
{
T_1 V_1 [ 2 ] ;
int V_26 ;
F_4 ( V_23 , V_39 ) ;
V_1 [ 0 ] = ( 1 << V_56 ) | ( 1 << V_57 ) ;
V_1 [ 1 ] = ( 0 << V_56 ) | ( 1 << V_57 ) ;
V_23 -> V_4 = 1 ;
V_26 = F_15 ( V_23 -> V_30 -> V_31 ,
V_58 , V_1 , F_29 ( V_1 ) ) ;
if ( V_26 < 0 ) {
F_6 ( V_23 -> V_33 , L_11 ,
V_34 , V_26 ) ;
return V_26 ;
}
V_26 = F_4 ( V_23 , V_27 ) ;
return V_26 ;
}
static int F_30 ( struct V_59 * V_60 )
{
struct V_61 * V_30 = F_9 ( V_60 -> V_33 . V_62 ) ;
struct V_22 * V_23 ;
int V_26 ;
F_26 ( & V_60 -> V_33 , L_12 , V_34 ) ;
V_23 = F_31 ( & V_60 -> V_33 , sizeof( struct V_22 ) ,
V_63 ) ;
if ( ! V_23 )
return - V_64 ;
F_32 ( & V_23 -> V_38 ) ;
V_23 -> V_33 = & V_60 -> V_33 ;
V_23 -> V_30 = V_30 ;
V_23 -> V_65 = V_30 -> V_66 ;
F_33 ( V_60 , V_23 ) ;
V_26 = F_28 ( V_23 ) ;
if ( V_26 < 0 ) {
F_6 ( & V_60 -> V_33 , L_13 , V_26 ) ;
return V_26 ;
}
F_34 ( & V_60 -> V_33 , 1 ) ;
V_23 -> V_52 = F_35 ( & V_60 -> V_33 , L_14 ,
& V_67 , V_68 ) ;
if ( F_36 ( V_23 -> V_52 ) ) {
V_26 = F_37 ( V_23 -> V_52 ) ;
F_6 ( & V_60 -> V_33 , L_15 , V_26 ) ;
if ( V_26 == 0 )
V_26 = - V_69 ;
return V_26 ;
}
if ( ! V_30 -> V_70 ) {
F_6 ( & V_60 -> V_33 , L_16 ) ;
return - V_69 ;
}
V_23 -> V_71 = F_38 ( V_30 -> V_70 ,
V_72 ) ;
if ( V_23 -> V_71 <= 0 ) {
F_6 ( & V_60 -> V_33 , L_17 ,
V_72 ) ;
return - V_69 ;
}
V_26 = F_39 ( & V_60 -> V_33 , V_23 -> V_71 , NULL ,
F_25 , 0 , L_18 ,
V_23 ) ;
if ( V_26 < 0 )
F_6 ( & V_60 -> V_33 , L_19 ,
V_23 -> V_71 , V_26 ) ;
return V_26 ;
}
static int F_40 ( struct V_36 * V_33 )
{
if ( F_41 ( V_33 ) ) {
struct V_22 * V_23 = F_9 ( V_33 ) ;
return F_42 ( V_23 -> V_71 ) ;
}
return 0 ;
}
static int F_43 ( struct V_36 * V_33 )
{
if ( F_41 ( V_33 ) ) {
struct V_22 * V_23 = F_9 ( V_33 ) ;
return F_44 ( V_23 -> V_71 ) ;
}
return 0 ;
}
