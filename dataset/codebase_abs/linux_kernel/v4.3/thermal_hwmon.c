static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> type ) ;
}
static T_1
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
int V_8 ;
int V_9 ;
struct V_10 * V_11
= F_4 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13
= F_4 ( V_11 , struct V_12 ,
V_14 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
V_9 = F_5 ( V_16 , & V_8 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_5 , L_2 , V_8 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_10 * V_11
= F_4 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13
= F_4 ( V_11 , struct V_12 ,
V_17 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
int V_8 ;
int V_9 ;
V_9 = V_16 -> V_18 -> V_19 ( V_16 , 0 , & V_8 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_5 , L_2 , V_8 ) ;
}
static struct V_6 *
F_7 ( const struct V_15 * V_16 )
{
struct V_6 * V_7 ;
F_8 ( & V_20 ) ;
F_9 (hwmon, &thermal_hwmon_list, node)
if ( ! strcmp ( V_7 -> type , V_16 -> type ) ) {
F_10 ( & V_20 ) ;
return V_7 ;
}
F_10 ( & V_20 ) ;
return NULL ;
}
static struct V_12 *
F_11 ( const struct V_6 * V_7 ,
const struct V_15 * V_16 )
{
struct V_12 * V_13 ;
F_8 ( & V_20 ) ;
F_9 (temp, &hwmon->tz_list, hwmon_node)
if ( V_13 -> V_16 == V_16 ) {
F_10 ( & V_20 ) ;
return V_13 ;
}
F_10 ( & V_20 ) ;
return NULL ;
}
static bool F_12 ( struct V_15 * V_16 )
{
int V_13 ;
return V_16 -> V_18 -> V_21 && ! V_16 -> V_18 -> V_21 ( V_16 , & V_13 ) ;
}
int F_13 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
int V_22 = 1 ;
int V_23 ;
V_7 = F_7 ( V_16 ) ;
if ( V_7 ) {
V_22 = 0 ;
goto V_24;
}
V_7 = F_14 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return - V_26 ;
F_15 ( & V_7 -> V_27 ) ;
F_16 ( V_7 -> type , V_16 -> type , V_28 ) ;
V_7 -> V_1 = F_17 ( NULL ) ;
if ( F_18 ( V_7 -> V_1 ) ) {
V_23 = F_19 ( V_7 -> V_1 ) ;
goto V_29;
}
F_20 ( V_7 -> V_1 , V_7 ) ;
V_23 = F_21 ( V_7 -> V_1 , & V_30 ) ;
if ( V_23 )
goto V_29;
V_24:
V_13 = F_14 ( sizeof( * V_13 ) , V_25 ) ;
if ( ! V_13 ) {
V_23 = - V_26 ;
goto V_31;
}
V_13 -> V_16 = V_16 ;
V_7 -> V_32 ++ ;
snprintf ( V_13 -> V_14 . V_33 , sizeof( V_13 -> V_14 . V_33 ) ,
L_3 , V_7 -> V_32 ) ;
V_13 -> V_14 . V_4 . V_4 . V_33 = V_13 -> V_14 . V_33 ;
V_13 -> V_14 . V_4 . V_4 . V_34 = 0444 ;
V_13 -> V_14 . V_4 . V_35 = F_3 ;
F_22 ( & V_13 -> V_14 . V_4 . V_4 ) ;
V_23 = F_21 ( V_7 -> V_1 , & V_13 -> V_14 . V_4 ) ;
if ( V_23 )
goto V_36;
if ( F_12 ( V_16 ) ) {
snprintf ( V_13 -> V_17 . V_33 ,
sizeof( V_13 -> V_17 . V_33 ) ,
L_4 , V_7 -> V_32 ) ;
V_13 -> V_17 . V_4 . V_4 . V_33 = V_13 -> V_17 . V_33 ;
V_13 -> V_17 . V_4 . V_4 . V_34 = 0444 ;
V_13 -> V_17 . V_4 . V_35 = F_6 ;
F_22 ( & V_13 -> V_17 . V_4 . V_4 ) ;
V_23 = F_21 ( V_7 -> V_1 ,
& V_13 -> V_17 . V_4 ) ;
if ( V_23 )
goto V_37;
}
F_8 ( & V_20 ) ;
if ( V_22 )
F_23 ( & V_7 -> V_38 , & V_39 ) ;
F_23 ( & V_13 -> V_40 , & V_7 -> V_27 ) ;
F_10 ( & V_20 ) ;
return 0 ;
V_37:
F_24 ( V_7 -> V_1 , & V_13 -> V_14 . V_4 ) ;
V_36:
F_25 ( V_13 ) ;
V_31:
if ( V_22 ) {
F_24 ( V_7 -> V_1 , & V_30 ) ;
F_26 ( V_7 -> V_1 ) ;
}
V_29:
if ( V_22 )
F_25 ( V_7 ) ;
return V_23 ;
}
void F_27 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
V_7 = F_7 ( V_16 ) ;
if ( F_28 ( ! V_7 ) ) {
F_29 ( & V_16 -> V_1 , L_5 ) ;
return;
}
V_13 = F_11 ( V_7 , V_16 ) ;
if ( F_28 ( ! V_13 ) ) {
F_29 ( & V_16 -> V_1 , L_6 ) ;
return;
}
F_24 ( V_7 -> V_1 , & V_13 -> V_14 . V_4 ) ;
if ( F_12 ( V_16 ) )
F_24 ( V_7 -> V_1 , & V_13 -> V_17 . V_4 ) ;
F_8 ( & V_20 ) ;
F_30 ( & V_13 -> V_40 ) ;
F_25 ( V_13 ) ;
if ( ! F_31 ( & V_7 -> V_27 ) ) {
F_10 ( & V_20 ) ;
return;
}
F_30 ( & V_7 -> V_38 ) ;
F_10 ( & V_20 ) ;
F_24 ( V_7 -> V_1 , & V_30 ) ;
F_26 ( V_7 -> V_1 ) ;
F_25 ( V_7 ) ;
}
