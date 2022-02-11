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
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_10 ;
int V_11 = 0 ;
int V_12 ;
V_8 = F_2 ( V_2 ) ;
if ( ! V_8 )
return - V_13 ;
V_11 = F_5 ( V_8 -> V_9 -> V_14 ) ;
if ( V_11 )
return V_11 ;
V_6 = V_8 -> V_9 -> type ;
if ( V_6 -> V_15 ) {
V_11 = V_6 -> V_15 ( V_8 ) ;
if ( V_11 )
goto V_16;
}
V_12 = V_8 -> V_12 ;
V_10 = F_6 ( V_17 , V_12 , V_2 ) ;
if ( F_7 ( V_10 ) ) {
V_11 = F_8 ( V_10 ) ;
goto V_18;
}
F_9 ( V_8 -> V_9 -> V_14 ) ;
F_10 ( & V_8 -> V_9 -> V_2 -> V_2 ,
L_1 ,
V_6 -> V_19 , V_12 ) ;
return 0 ;
V_18:
if ( V_6 -> V_20 )
V_6 -> V_20 ( V_8 ) ;
V_16:
F_9 ( V_8 -> V_9 -> V_14 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_11 = 0 ;
int V_12 ;
int V_21 ;
V_8 = F_2 ( V_2 ) ;
if ( ! V_8 )
return - V_13 ;
V_21 = F_5 ( V_8 -> V_9 -> V_14 ) ;
V_12 = V_8 -> V_12 ;
F_12 ( V_17 , V_12 ) ;
V_6 = V_8 -> V_9 -> type ;
if ( V_6 -> V_20 )
V_11 = V_6 -> V_20 ( V_8 ) ;
F_10 ( V_2 , L_2 ,
V_6 -> V_19 , V_12 ) ;
if ( ! V_21 )
F_9 ( V_8 -> V_9 -> V_14 ) ;
return V_11 ;
}
static T_1 F_13 ( struct V_3 * V_6 ,
const char * V_22 , T_2 V_23 )
{
struct V_5 * V_24 = F_3 ( V_6 ) ;
T_1 V_11 = F_14 ( & V_24 -> V_25 , V_24 -> V_26 ,
V_6 , V_22 , V_23 ) ;
if ( V_11 >= 0 && V_24 -> V_27 != NULL )
V_11 = F_14 ( & V_24 -> V_27 -> V_25 ,
V_24 -> V_27 -> V_26 ,
& V_24 -> V_27 -> V_28 . V_6 ,
V_22 , V_23 ) ;
return V_11 ;
}
static T_1 F_15 ( struct V_3 * V_6 , char * V_22 )
{
struct V_5 * V_24 = F_3 ( V_6 ) ;
return F_16 ( & V_24 -> V_25 , V_22 ) ;
}
static void F_17 ( struct V_5 * V_4 )
{
struct V_29 * V_30 , * V_31 ;
F_18 ( & V_4 -> V_25 . V_32 ) ;
F_19 (dynid, n, &drv->dynids.list, node) {
F_20 ( & V_30 -> V_33 ) ;
F_21 ( V_30 ) ;
}
F_22 ( & V_4 -> V_25 . V_32 ) ;
}
int F_23 ( struct V_5 * V_6 )
{
int V_11 ;
V_6 -> V_6 . V_34 = & V_35 ;
F_24 ( & V_6 -> V_25 . V_32 ) ;
F_25 ( & V_6 -> V_25 . V_36 ) ;
V_11 = F_26 ( & V_6 -> V_6 ) ;
return V_11 ;
}
void F_27 ( struct V_5 * V_6 )
{
F_17 ( V_6 ) ;
F_28 ( & V_6 -> V_6 ) ;
}
