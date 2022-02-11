static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
const struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
if ( ! V_8 )
return 0 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 == V_8 -> V_9 -> type )
return 1 ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_12 , L_1 , V_8 -> V_13 - V_8 -> V_9 -> V_14 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_15 = 0 ;
int V_14 ;
V_8 = F_2 ( V_2 ) ;
if ( ! V_8 ) {
V_15 = - V_16 ;
goto exit;
}
V_6 = V_8 -> V_9 -> type ;
if ( V_6 -> V_17 ) {
V_15 = V_6 -> V_17 ( V_8 ) ;
if ( V_15 )
goto exit;
}
V_15 = F_6 ( V_2 , & V_18 ) ;
if ( V_15 ) {
if ( V_6 -> V_19 )
V_15 = V_6 -> V_19 ( V_8 ) ;
goto exit;
}
V_14 = V_8 -> V_13 ;
F_7 ( V_20 , V_14 , V_2 ) ;
F_8 ( & V_8 -> V_9 -> V_2 -> V_2 ,
L_2 ,
V_6 -> V_21 , V_14 ) ;
exit:
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_15 = 0 ;
int V_14 ;
V_8 = F_2 ( V_2 ) ;
if ( ! V_8 )
return - V_16 ;
F_10 ( & V_8 -> V_2 , & V_18 ) ;
V_6 = V_8 -> V_9 -> type ;
if ( V_6 -> V_19 )
V_15 = V_6 -> V_19 ( V_8 ) ;
V_14 = V_8 -> V_13 ;
F_11 ( V_20 , V_14 ) ;
F_8 ( V_2 , L_3 ,
V_6 -> V_21 , V_14 ) ;
return V_15 ;
}
static T_1 F_12 ( struct V_3 * V_6 ,
const char * V_12 , T_2 V_22 )
{
struct V_5 * V_23 = F_3 ( V_6 ) ;
T_1 V_15 = F_13 ( & V_23 -> V_24 , V_6 , V_12 , V_22 ) ;
if ( V_15 >= 0 && V_23 -> V_25 != NULL )
V_15 = F_13 ( & V_23 -> V_25 -> V_24 ,
& V_23 -> V_25 -> V_26 . V_6 ,
V_12 , V_22 ) ;
return V_15 ;
}
static T_1 F_14 ( struct V_3 * V_6 , char * V_12 )
{
struct V_5 * V_23 = F_3 ( V_6 ) ;
return F_15 ( & V_23 -> V_24 , V_12 ) ;
}
static void F_16 ( struct V_5 * V_4 )
{
struct V_27 * V_28 , * V_29 ;
F_17 ( & V_4 -> V_24 . V_30 ) ;
F_18 (dynid, n, &drv->dynids.list, node) {
F_19 ( & V_28 -> V_31 ) ;
F_20 ( V_28 ) ;
}
F_21 ( & V_4 -> V_24 . V_30 ) ;
}
static inline void F_16 ( struct V_5 * V_4 )
{
}
int F_22 ( struct V_5 * V_6 )
{
int V_15 ;
V_6 -> V_6 . V_32 = & V_33 ;
F_23 ( & V_6 -> V_24 . V_30 ) ;
F_24 ( & V_6 -> V_24 . V_34 ) ;
V_15 = F_25 ( & V_6 -> V_6 ) ;
return V_15 ;
}
void F_26 ( struct V_5 * V_6 )
{
F_16 ( V_6 ) ;
F_27 ( & V_6 -> V_6 ) ;
}
