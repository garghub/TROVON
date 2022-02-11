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
return sprintf ( V_12 , L_1 , V_8 -> V_13 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_14 = 0 ;
int V_15 ;
V_8 = F_2 ( V_2 ) ;
if ( ! V_8 ) {
V_14 = - V_16 ;
goto exit;
}
V_14 = F_6 ( V_8 -> V_9 -> V_17 ) ;
if ( V_14 )
goto exit;
V_6 = V_8 -> V_9 -> type ;
if ( V_6 -> V_18 ) {
V_14 = V_6 -> V_18 ( V_8 ) ;
if ( V_14 )
goto V_19;
}
V_14 = F_7 ( V_2 , & V_20 ) ;
if ( V_14 ) {
if ( V_6 -> V_21 )
V_14 = V_6 -> V_21 ( V_8 ) ;
goto V_19;
}
V_15 = V_8 -> V_15 ;
F_8 ( V_22 , V_15 , V_2 ) ;
F_9 ( & V_8 -> V_9 -> V_2 -> V_2 ,
L_2 ,
V_6 -> V_23 , V_15 ) ;
V_19:
F_10 ( V_8 -> V_9 -> V_17 ) ;
exit:
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_14 = 0 ;
int V_15 ;
V_8 = F_2 ( V_2 ) ;
if ( ! V_8 )
return - V_16 ;
F_6 ( V_8 -> V_9 -> V_17 ) ;
V_15 = V_8 -> V_15 ;
F_12 ( V_22 , V_15 ) ;
F_13 ( & V_8 -> V_2 , & V_20 ) ;
V_6 = V_8 -> V_9 -> type ;
if ( V_6 -> V_21 )
V_14 = V_6 -> V_21 ( V_8 ) ;
F_9 ( V_2 , L_3 ,
V_6 -> V_23 , V_15 ) ;
F_10 ( V_8 -> V_9 -> V_17 ) ;
return V_14 ;
}
static T_1 F_14 ( struct V_3 * V_6 ,
const char * V_12 , T_2 V_24 )
{
struct V_5 * V_25 = F_3 ( V_6 ) ;
T_1 V_14 = F_15 ( & V_25 -> V_26 , V_25 -> V_27 ,
V_6 , V_12 , V_24 ) ;
if ( V_14 >= 0 && V_25 -> V_28 != NULL )
V_14 = F_15 ( & V_25 -> V_28 -> V_26 ,
V_25 -> V_28 -> V_27 ,
& V_25 -> V_28 -> V_29 . V_6 ,
V_12 , V_24 ) ;
return V_14 ;
}
static T_1 F_16 ( struct V_3 * V_6 , char * V_12 )
{
struct V_5 * V_25 = F_3 ( V_6 ) ;
return F_17 ( & V_25 -> V_26 , V_12 ) ;
}
static void F_18 ( struct V_5 * V_4 )
{
struct V_30 * V_31 , * V_32 ;
F_19 ( & V_4 -> V_26 . V_33 ) ;
F_20 (dynid, n, &drv->dynids.list, node) {
F_21 ( & V_31 -> V_34 ) ;
F_22 ( V_31 ) ;
}
F_23 ( & V_4 -> V_26 . V_33 ) ;
}
int F_24 ( struct V_5 * V_6 )
{
int V_14 ;
V_6 -> V_6 . V_35 = & V_36 ;
F_25 ( & V_6 -> V_26 . V_33 ) ;
F_26 ( & V_6 -> V_26 . V_37 ) ;
V_14 = F_27 ( & V_6 -> V_6 ) ;
return V_14 ;
}
void F_28 ( struct V_5 * V_6 )
{
F_18 ( V_6 ) ;
F_29 ( & V_6 -> V_6 ) ;
}
