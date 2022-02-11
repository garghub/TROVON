static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 [ 2 ] = { V_7 , V_3 } ;
int V_8 ;
V_8 = F_2 ( V_5 , V_6 , sizeof( V_6 ) ) ;
if ( V_8 != sizeof( V_6 ) ) {
F_3 ( & V_5 -> V_9 ,
L_1 , V_10 , V_8 ) ;
return ( V_8 < 0 ) ? V_8 : - V_11 ;
}
V_2 -> V_3 = V_3 ;
return 0 ;
}
static int F_4 ( struct V_12 * V_13 , T_2 V_14 ,
const void * V_15 , T_3 V_16 )
{
struct V_1 * V_2 =
F_5 ( V_13 , struct V_1 , V_13 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_3 V_17 = V_16 + 1 ;
int V_8 ;
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_19 || V_2 -> V_20 < V_17 ) {
if ( V_2 -> V_19 )
F_7 ( & V_5 -> V_9 , V_2 -> V_19 ) ;
V_2 -> V_20 = V_17 + V_21 ;
V_2 -> V_19 = F_8 ( & V_5 -> V_9 ,
V_2 -> V_20 ,
V_22 ) ;
if ( ! V_2 -> V_19 ) {
V_2 -> V_20 = 0 ;
V_8 = - V_23 ;
goto exit;
}
}
V_2 -> V_19 [ 0 ] = V_14 & 0xff ;
memcpy ( V_2 -> V_19 + 1 , V_15 , V_16 ) ;
if ( F_9 ( V_14 ) != V_2 -> V_3 ) {
V_8 = F_1 ( V_2 , F_9 ( V_14 ) ) ;
if ( V_8 )
goto exit;
}
V_8 = F_2 ( V_5 , V_2 -> V_19 , V_17 ) ;
if ( V_8 == V_17 )
V_8 = 0 ;
else if ( V_8 >= 0 )
V_8 = - V_11 ;
exit:
F_10 ( V_24 , & V_5 -> V_9 ,
L_2 ,
V_16 , V_14 , V_8 , ( int ) V_16 , V_15 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_8 ;
}
static int F_12 ( struct V_12 * V_13 , T_2 V_14 ,
void * V_15 , T_3 V_16 )
{
struct V_1 * V_2 =
F_5 ( V_13 , struct V_1 , V_13 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_25 = V_14 & 0xff ;
int V_8 ;
struct V_26 V_27 [] = {
{
. V_14 = V_5 -> V_14 ,
. V_16 = sizeof( V_25 ) ,
. V_15 = & V_25 ,
} ,
{
. V_14 = V_5 -> V_14 ,
. V_28 = V_29 ,
. V_16 = V_16 ,
. V_15 = V_15 ,
} ,
} ;
F_6 ( & V_2 -> V_18 ) ;
if ( F_9 ( V_14 ) != V_2 -> V_3 ) {
V_8 = F_1 ( V_2 , F_9 ( V_14 ) ) ;
if ( V_8 )
goto exit;
}
V_8 = F_13 ( V_5 -> V_30 , V_27 , F_14 ( V_27 ) ) ;
if ( V_8 == F_14 ( V_27 ) )
V_8 = 0 ;
else if ( V_8 >= 0 )
V_8 = - V_11 ;
exit:
F_10 ( V_24 , & V_5 -> V_9 ,
L_3 ,
V_16 , V_14 , V_8 , ( int ) V_16 , V_15 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_8 ;
}
static T_4 F_15 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_33 * V_34 = V_2 -> V_13 . V_34 ;
int V_35 ;
V_35 = F_16 ( V_34 ) ;
if ( V_35 )
F_10 ( V_24 , & V_34 -> V_9 ,
L_4 , V_35 ) ;
return V_36 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
int V_37 = F_19 ( F_20 ( V_2 -> V_31 ) ) ;
int V_35 ;
if ( ! V_37 )
V_37 = V_38 ;
V_35 = F_21 ( & V_5 -> V_9 , V_2 -> V_31 , NULL ,
F_15 , V_37 | V_39 , V_5 -> V_40 ,
V_2 ) ;
if ( V_35 < 0 ) {
F_22 ( & V_5 -> V_9 , L_5 ,
V_2 -> V_31 ) ;
return V_35 ;
}
return 0 ;
}
static void F_23 ( void * V_41 )
{
struct V_1 * V_2 = V_41 ;
F_24 ( F_14 ( V_2 -> V_42 ) ,
V_2 -> V_42 ) ;
}
static void F_25 ( void * V_41 )
{
struct V_1 * V_2 = V_41 ;
F_26 ( & V_2 -> V_13 ) ;
}
static int F_27 ( struct V_4 * V_5 ,
const struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_45 * V_47 =
F_28 ( & V_5 -> V_9 ) ;
struct V_1 * V_2 ;
int V_8 ;
V_2 = F_8 ( & V_5 -> V_9 , sizeof( struct V_1 ) ,
V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_46 = & V_2 -> V_13 . V_46 ;
if ( ! V_5 -> V_9 . V_48 && V_47 )
* V_46 = * V_47 ;
if ( V_5 -> V_31 > 0 )
V_2 -> V_31 = V_5 -> V_31 ;
F_10 ( V_24 , & V_5 -> V_9 , L_6 ,
F_29 ( & V_5 -> V_9 ) ) ;
if ( ! F_30 ( V_5 -> V_30 , V_49 ) ) {
F_3 ( & V_5 -> V_9 ,
L_7 ) ;
return - V_50 ;
}
V_2 -> V_42 [ 0 ] . V_51 = L_8 ;
V_2 -> V_42 [ 1 ] . V_51 = L_9 ;
V_8 = F_31 ( & V_5 -> V_9 ,
F_14 ( V_2 -> V_42 ) ,
V_2 -> V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_32 ( F_14 ( V_2 -> V_42 ) ,
V_2 -> V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_33 ( & V_5 -> V_9 ,
F_23 ,
V_2 ) ;
if ( V_8 )
return V_8 ;
F_34 ( V_5 -> V_9 . V_48 , L_10 ,
& V_2 -> V_52 ) ;
F_35 ( V_2 -> V_52 ) ;
V_2 -> V_5 = V_5 ;
F_36 ( & V_2 -> V_18 ) ;
V_2 -> V_13 . V_9 = & V_5 -> V_9 ;
V_2 -> V_13 . V_53 = L_11 ;
V_2 -> V_13 . V_54 = & V_55 ;
F_37 ( V_5 , V_2 ) ;
V_8 = F_1 ( V_2 , 0 ) ;
if ( V_8 ) {
F_3 ( & V_5 -> V_9 , L_12 ) ;
return V_8 ;
}
V_8 = F_38 ( & V_2 -> V_13 ) ;
if ( V_8 ) {
F_3 ( & V_5 -> V_9 , L_13 ,
V_5 -> V_14 ) ;
return V_8 ;
}
V_8 = F_33 ( & V_5 -> V_9 ,
F_25 ,
V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_17 ( V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
F_39 ( & V_5 -> V_9 , L_14 ,
V_5 -> V_14 ) ;
return 0 ;
}
static int F_40 ( struct V_56 * V_9 )
{
struct V_4 * V_5 = F_41 ( V_9 ) ;
struct V_1 * V_2 = F_18 ( V_5 ) ;
int V_35 ;
V_35 = F_42 ( V_2 -> V_13 . V_34 ) ;
if ( V_35 )
F_22 ( V_9 , L_15 , V_35 ) ;
F_43 ( V_2 -> V_31 ) ;
if ( F_44 ( & V_5 -> V_9 ) ) {
V_35 = F_45 ( V_2 -> V_31 ) ;
if ( ! V_35 )
F_22 ( V_9 , L_16 ,
V_35 ) ;
}
F_24 ( F_14 ( V_2 -> V_42 ) ,
V_2 -> V_42 ) ;
return V_35 ;
}
static int F_46 ( struct V_56 * V_9 )
{
struct V_4 * V_5 = F_41 ( V_9 ) ;
struct V_1 * V_2 = F_18 ( V_5 ) ;
int V_35 ;
V_35 = F_32 ( F_14 ( V_2 -> V_42 ) ,
V_2 -> V_42 ) ;
if ( V_35 )
return V_35 ;
F_35 ( V_2 -> V_52 ) ;
F_47 ( V_2 -> V_31 ) ;
if ( F_44 ( & V_5 -> V_9 ) ) {
V_35 = F_48 ( V_2 -> V_31 ) ;
if ( ! V_35 )
F_22 ( V_9 , L_17 ,
V_35 ) ;
}
V_35 = F_49 ( V_2 -> V_13 . V_34 ) ;
if ( V_35 )
F_22 ( V_9 , L_15 , V_35 ) ;
return V_35 ;
}
static int F_50 ( struct V_56 * V_9 )
{
struct V_4 * V_5 = F_41 ( V_9 ) ;
struct V_1 * V_2 = F_18 ( V_5 ) ;
int V_35 ;
V_35 = F_42 ( V_2 -> V_13 . V_34 ) ;
if ( V_35 )
F_22 ( V_9 , L_15 , V_35 ) ;
F_43 ( V_2 -> V_31 ) ;
F_24 ( F_14 ( V_2 -> V_42 ) ,
V_2 -> V_42 ) ;
return 0 ;
}
static int F_51 ( struct V_56 * V_9 )
{
struct V_4 * V_5 = F_41 ( V_9 ) ;
struct V_1 * V_2 = F_18 ( V_5 ) ;
int V_35 ;
V_35 = F_32 ( F_14 ( V_2 -> V_42 ) ,
V_2 -> V_42 ) ;
if ( V_35 )
return V_35 ;
F_35 ( V_2 -> V_52 ) ;
F_47 ( V_2 -> V_31 ) ;
V_35 = F_49 ( V_2 -> V_13 . V_34 ) ;
if ( V_35 )
F_22 ( V_9 , L_15 , V_35 ) ;
return 0 ;
}
