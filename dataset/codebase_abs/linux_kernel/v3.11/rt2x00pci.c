static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
if ( V_2 -> V_5 . V_6 ) {
F_3 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_5 ( V_2 -> V_8 ) ;
V_2 -> V_5 . V_6 = F_6 ( V_7 , 0 ) ;
if ( ! V_2 -> V_5 . V_6 )
goto exit;
V_2 -> V_4 = F_7 ( V_2 -> V_9 -> V_10 , V_11 ) ;
if ( ! V_2 -> V_4 )
goto exit;
V_2 -> V_3 = F_7 ( V_2 -> V_9 -> V_12 , V_11 ) ;
if ( ! V_2 -> V_3 )
goto exit;
return 0 ;
exit:
F_8 ( L_1 ) ;
F_1 ( V_2 ) ;
return - V_13 ;
}
int F_9 ( struct V_7 * V_7 , const struct V_14 * V_9 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_17 ;
T_1 V_18 ;
V_17 = F_10 ( V_7 ) ;
if ( V_17 ) {
F_8 ( L_2 ) ;
return V_17 ;
}
V_17 = F_11 ( V_7 , F_12 ( V_7 ) ) ;
if ( V_17 ) {
F_8 ( L_3 ) ;
goto V_19;
}
F_13 ( V_7 ) ;
if ( F_14 ( V_7 ) )
F_8 ( L_4 ) ;
if ( F_15 ( & V_7 -> V_8 , F_16 ( 32 ) ) ) {
F_8 ( L_5 ) ;
V_17 = - V_20 ;
goto V_21;
}
F_17 ( V_7 ) ;
V_16 = F_18 ( sizeof( struct V_1 ) , V_9 -> V_16 ) ;
if ( ! V_16 ) {
F_8 ( L_6 ) ;
V_17 = - V_13 ;
goto V_22;
}
F_19 ( V_7 , V_16 ) ;
V_2 = V_16 -> V_23 ;
V_2 -> V_8 = & V_7 -> V_8 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_24 = V_7 -> V_24 ;
V_2 -> V_25 = F_12 ( V_7 ) ;
if ( F_20 ( V_7 ) )
F_21 ( V_2 , V_26 ) ;
else
F_21 ( V_2 , V_27 ) ;
V_17 = F_4 ( V_2 ) ;
if ( V_17 )
goto V_28;
F_22 ( V_7 , V_29 , & V_18 ) ;
V_2 -> V_18 . V_30 = V_18 ;
V_17 = F_23 ( V_2 ) ;
if ( V_17 )
goto V_31;
return 0 ;
V_31:
F_1 ( V_2 ) ;
V_28:
F_24 ( V_16 ) ;
V_22:
F_25 ( V_7 ) ;
V_21:
F_26 ( V_7 ) ;
V_19:
F_27 ( V_7 ) ;
F_19 ( V_7 , NULL ) ;
return V_17 ;
}
void F_28 ( struct V_7 * V_7 )
{
struct V_15 * V_16 = F_29 ( V_7 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
F_30 ( V_2 ) ;
F_1 ( V_2 ) ;
F_24 ( V_16 ) ;
F_25 ( V_7 ) ;
F_19 ( V_7 , NULL ) ;
F_27 ( V_7 ) ;
F_26 ( V_7 ) ;
}
int F_31 ( struct V_7 * V_7 , T_2 V_32 )
{
struct V_15 * V_16 = F_29 ( V_7 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
int V_17 ;
V_17 = F_32 ( V_2 , V_32 ) ;
if ( V_17 )
return V_17 ;
F_33 ( V_7 ) ;
F_27 ( V_7 ) ;
return F_34 ( V_7 , F_35 ( V_7 , V_32 ) ) ;
}
int F_36 ( struct V_7 * V_7 )
{
struct V_15 * V_16 = F_29 ( V_7 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
if ( F_34 ( V_7 , V_33 ) ||
F_10 ( V_7 ) ) {
F_37 ( V_2 , L_7 ) ;
return - V_20 ;
}
F_38 ( V_7 ) ;
return F_39 ( V_2 ) ;
}
