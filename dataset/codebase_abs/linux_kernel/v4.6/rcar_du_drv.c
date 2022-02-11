static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( & V_4 -> V_8 [ V_7 ] , true ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( & V_4 -> V_8 [ V_7 ] , false ) ;
}
static int F_6 ( struct V_9 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
F_8 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
F_10 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_12 ( V_12 ) ;
struct V_1 * V_10 = V_4 -> V_10 ;
F_13 ( & V_10 -> V_13 . V_14 ) ;
F_14 ( V_10 ) ;
F_15 ( & V_10 -> V_13 . V_14 ) ;
F_16 ( V_10 ) ;
if ( V_4 -> V_6 )
F_17 ( V_4 -> V_6 ) ;
F_18 ( V_10 ) ;
F_19 ( V_10 ) ;
F_20 ( V_10 ) ;
F_21 ( V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_2 . V_17 ;
struct V_3 * V_4 ;
struct V_18 * V_19 ;
struct V_1 * V_10 ;
struct V_20 * V_21 ;
int V_22 ;
if ( V_16 == NULL ) {
F_23 ( & V_12 -> V_2 , L_1 ) ;
return - V_23 ;
}
V_4 = F_24 ( & V_12 -> V_2 , sizeof( * V_4 ) , V_24 ) ;
if ( V_4 == NULL )
return - V_25 ;
F_25 ( & V_4 -> V_26 . V_27 ) ;
V_4 -> V_2 = & V_12 -> V_2 ;
V_4 -> V_28 = F_26 ( V_29 , V_4 -> V_2 ) -> V_30 ;
V_10 = F_27 ( & V_31 , & V_12 -> V_2 ) ;
if ( ! V_10 )
return - V_25 ;
F_28 ( V_10 , F_29 ( & V_12 -> V_2 ) ) ;
V_4 -> V_10 = V_10 ;
V_10 -> V_5 = V_4 ;
F_30 ( V_12 , V_4 ) ;
V_21 = F_31 ( V_12 , V_32 , 0 ) ;
V_4 -> V_33 = F_32 ( & V_12 -> V_2 , V_21 ) ;
if ( F_33 ( V_4 -> V_33 ) ) {
V_22 = F_34 ( V_4 -> V_33 ) ;
goto error;
}
V_22 = F_35 ( V_10 , ( 1 << V_4 -> V_28 -> V_34 ) - 1 ) ;
if ( V_22 < 0 ) {
F_23 ( & V_12 -> V_2 , L_2 ) ;
goto error;
}
V_22 = F_36 ( V_4 ) ;
if ( V_22 < 0 ) {
F_23 ( & V_12 -> V_2 , L_3 , V_22 ) ;
goto error;
}
V_10 -> V_35 = 1 ;
V_22 = F_37 ( V_10 , 0 ) ;
if ( V_22 )
goto error;
F_13 ( & V_10 -> V_13 . V_14 ) ;
F_38 (connector, ddev) {
V_22 = F_39 ( V_19 ) ;
if ( V_22 < 0 )
break;
}
F_15 ( & V_10 -> V_13 . V_14 ) ;
if ( V_22 < 0 )
goto error;
F_40 ( L_4 , F_29 ( & V_12 -> V_2 ) ) ;
return 0 ;
error:
F_11 ( V_12 ) ;
return V_22 ;
}
