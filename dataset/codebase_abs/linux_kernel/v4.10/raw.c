static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 -> V_9 -> V_7 ;
int V_10 = 0 ;
if ( V_3 > V_11 ) {
F_2 ( V_7 , L_1 ) ;
return - V_12 ;
}
F_3 ( & V_2 -> V_13 ) ;
if ( ( V_2 -> V_14 + V_3 ) > V_15 ) {
F_2 ( V_7 , L_2 ) ;
V_10 = - V_12 ;
goto exit;
}
V_5 = F_4 ( sizeof( * V_5 ) + V_3 , V_16 ) ;
if ( ! V_5 ) {
V_10 = - V_17 ;
goto exit;
}
V_2 -> V_14 += V_3 ;
V_5 -> V_3 = V_3 ;
memcpy ( & V_5 -> V_4 [ 0 ] , V_4 , V_3 ) ;
F_5 ( & V_5 -> V_18 , & V_2 -> V_19 ) ;
exit:
F_6 ( & V_2 -> V_13 ) ;
return V_10 ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_22 * V_8 = V_21 -> V_8 ;
struct V_6 * V_7 = & V_8 -> V_9 -> V_7 ;
struct V_1 * V_2 = F_8 ( V_8 -> V_9 ) ;
struct V_23 * V_24 ;
T_1 V_3 ;
if ( V_21 -> type != V_25 ) {
F_2 ( V_7 , L_3 , V_21 -> type ) ;
return - V_12 ;
}
if ( V_21 -> V_26 -> V_27 < sizeof( * V_24 ) ) {
F_2 ( V_7 , L_4 ,
V_21 -> V_26 -> V_27 , sizeof( * V_24 ) ) ;
return - V_12 ;
}
V_24 = V_21 -> V_26 -> V_28 ;
V_3 = F_9 ( V_24 -> V_3 ) ;
if ( V_3 != ( int ) ( V_21 -> V_26 -> V_27 - sizeof( V_29 ) ) ) {
F_2 ( V_7 , L_5 , V_3 ,
( int ) ( V_21 -> V_26 -> V_27 - sizeof( V_29 ) ) ) ;
return - V_12 ;
}
if ( V_3 == 0 ) {
F_2 ( V_7 , L_6 ) ;
return - V_12 ;
}
return F_1 ( V_2 , V_3 , V_24 -> V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , const char T_3 * V_4 )
{
struct V_22 * V_8 = V_2 -> V_8 ;
struct V_23 * V_26 ;
int V_10 ;
V_26 = F_4 ( V_3 + sizeof( * V_26 ) , V_16 ) ;
if ( ! V_26 )
return - V_17 ;
if ( F_11 ( & V_26 -> V_4 [ 0 ] , V_4 , V_3 ) ) {
F_12 ( V_26 ) ;
return - V_30 ;
}
V_26 -> V_3 = F_13 ( V_3 ) ;
V_10 = F_14 ( V_8 , V_25 ,
V_26 , V_3 + sizeof( * V_26 ) ,
NULL , 0 ) ;
F_12 ( V_26 ) ;
return V_10 ;
}
static int F_15 ( struct V_31 * V_9 ,
const struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_22 * V_8 ;
struct V_1 * V_2 ;
int V_10 ;
int V_36 ;
if ( V_9 -> V_37 != 1 )
return - V_38 ;
V_35 = & V_9 -> V_35 [ 0 ] ;
if ( V_35 -> V_39 != V_40 )
return - V_38 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_17 ;
V_8 = F_17 ( V_9 , F_18 ( V_35 -> V_33 ) ,
F_7 ) ;
if ( F_19 ( V_8 ) ) {
V_10 = F_20 ( V_8 ) ;
goto V_41;
}
F_21 ( & V_2 -> V_19 ) ;
F_22 ( & V_2 -> V_13 ) ;
V_2 -> V_8 = V_8 ;
F_23 ( V_9 , V_2 ) ;
V_36 = F_24 ( & V_42 , 0 , 0 , V_16 ) ;
if ( V_36 < 0 ) {
V_10 = V_36 ;
goto V_43;
}
V_2 -> V_7 = F_25 ( V_44 , V_36 ) ;
F_26 ( & V_2 -> V_45 , & V_46 ) ;
V_10 = F_27 ( V_8 ) ;
if ( V_10 )
goto V_47;
V_10 = F_28 ( & V_2 -> V_45 , V_2 -> V_7 , 1 ) ;
if ( V_10 )
goto V_48;
V_2 -> V_6 = F_29 ( V_49 , & V_8 -> V_9 -> V_7 ,
V_2 -> V_7 , V_2 , L_7 , V_36 ) ;
if ( F_19 ( V_2 -> V_6 ) ) {
V_10 = F_20 ( V_2 -> V_6 ) ;
goto V_50;
}
return 0 ;
V_50:
F_30 ( & V_2 -> V_45 ) ;
V_48:
F_31 ( V_8 ) ;
V_47:
F_32 ( & V_42 , V_36 ) ;
V_43:
F_33 ( V_8 ) ;
V_41:
F_12 ( V_2 ) ;
return V_10 ;
}
static void F_34 ( struct V_31 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_22 * V_8 = V_2 -> V_8 ;
struct V_5 * V_5 ;
struct V_5 * V_51 ;
F_35 ( V_49 , V_2 -> V_7 ) ;
F_30 ( & V_2 -> V_45 ) ;
F_31 ( V_8 ) ;
F_32 ( & V_42 , F_36 ( V_2 -> V_7 ) ) ;
F_33 ( V_8 ) ;
F_3 ( & V_2 -> V_13 ) ;
F_37 (raw_data, temp, &raw->list, entry) {
F_38 ( & V_5 -> V_18 ) ;
F_12 ( V_5 ) ;
}
F_6 ( & V_2 -> V_13 ) ;
F_12 ( V_2 ) ;
}
static int F_39 ( struct V_52 * V_52 , struct V_53 * V_53 )
{
struct V_45 * V_45 = V_52 -> V_54 ;
struct V_1 * V_2 = F_40 ( V_45 , struct V_1 , V_45 ) ;
V_53 -> V_55 = V_2 ;
return 0 ;
}
static T_4 F_41 ( struct V_53 * V_53 , const char T_3 * V_56 ,
T_5 V_57 , T_6 * V_58 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
int V_10 ;
if ( ! V_57 )
return 0 ;
if ( V_57 > V_11 )
return - V_59 ;
V_10 = F_10 ( V_2 , V_57 , V_56 ) ;
if ( V_10 )
return V_10 ;
return V_57 ;
}
static T_4 F_42 ( struct V_53 * V_53 , char T_3 * V_56 , T_5 V_57 ,
T_6 * V_58 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
int V_10 = 0 ;
struct V_5 * V_5 ;
F_3 ( & V_2 -> V_13 ) ;
if ( F_43 ( & V_2 -> V_19 ) )
goto exit;
V_5 = F_44 ( & V_2 -> V_19 , struct V_5 , V_18 ) ;
if ( V_5 -> V_3 > V_57 ) {
V_10 = - V_60 ;
goto exit;
}
if ( F_45 ( V_56 , & V_5 -> V_4 [ 0 ] , V_5 -> V_3 ) ) {
V_10 = - V_30 ;
goto exit;
}
F_38 ( & V_5 -> V_18 ) ;
V_2 -> V_14 -= V_5 -> V_3 ;
V_10 = V_5 -> V_3 ;
F_12 ( V_5 ) ;
exit:
F_6 ( & V_2 -> V_13 ) ;
return V_10 ;
}
static int F_46 ( void )
{
T_7 V_7 ;
int V_10 ;
V_49 = F_47 ( V_61 , L_8 ) ;
if ( F_19 ( V_49 ) ) {
V_10 = F_20 ( V_49 ) ;
goto V_62;
}
V_10 = F_48 ( & V_7 , 0 , V_63 , L_8 ) ;
if ( V_10 < 0 )
goto V_64;
V_44 = F_49 ( V_7 ) ;
V_10 = F_50 ( & V_65 ) ;
if ( V_10 )
goto V_66;
return 0 ;
V_66:
F_51 ( V_7 , V_63 ) ;
V_64:
F_52 ( V_49 ) ;
V_62:
return V_10 ;
}
static void T_8 F_53 ( void )
{
F_54 ( & V_65 ) ;
F_51 ( F_25 ( V_44 , 0 ) , V_63 ) ;
F_52 ( V_49 ) ;
F_55 ( & V_42 ) ;
}
