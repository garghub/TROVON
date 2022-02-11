static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
int V_9 ;
V_9 = F_2 ( V_6 -> V_10 , V_4 ) ;
if ( V_9 != V_11 )
return V_9 ;
F_3 ( V_6 -> V_12 != V_2 ) ;
F_3 ( ! V_6 -> V_13 ) ;
if ( ! F_4 ( V_6 -> V_13 ) &&
V_6 -> V_13 -> V_14 )
return V_6 -> V_13 -> V_14 ( V_2 , V_4 ) ;
return V_11 ;
}
static int F_5 ( struct V_15 * V_7 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_16 * V_13 ;
if ( F_6 ( V_6 -> V_12 ) )
return - V_17 ;
V_6 -> V_12 = V_2 ;
V_13 = F_7 ( V_7 -> V_7 , sizeof( * V_13 ) ,
V_18 ) ;
if ( ! V_13 )
return - V_19 ;
if ( V_2 -> V_20 ) {
V_6 -> V_13 = V_2 -> V_20 ;
* V_13 = * V_6 -> V_13 ;
} else {
V_6 -> V_13 = F_8 ( - V_21 ) ;
}
V_13 -> V_14 = F_1 ;
F_9 ( V_2 , V_13 ) ;
F_10 ( V_7 -> V_7 , L_1 ,
V_2 -> V_22 ) ;
return 0 ;
}
static
struct V_1 * F_11 ( struct V_15 * V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 ;
int V_26 ;
F_12 (connector, &ddev->mode_config.connector_list, head)
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
if ( V_2 -> V_28 [ V_26 ] == V_25 -> V_29 . V_30 )
return V_2 ;
F_13 ( V_23 -> V_7 , L_2 ,
V_25 -> V_22 , V_25 -> V_29 . V_30 ) ;
return NULL ;
}
int F_14 ( struct V_15 * V_23 )
{
struct V_5 * V_6 = V_23 -> V_8 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
F_12 (encoder, &ddev->mode_config.encoder_list, head)
if ( V_25 -> V_31 & ( 1 << V_6 -> V_10 -> V_32 ) )
break;
if ( ! V_25 ) {
F_13 ( V_23 -> V_7 , L_3 , V_33 ) ;
return - V_34 ;
}
V_2 = F_11 ( V_23 , V_25 ) ;
if ( ! V_2 )
return - V_34 ;
F_15 ( V_6 -> V_10 , true ) ;
F_16 ( V_6 -> V_10 , & V_35 ) ;
return F_5 ( V_23 , V_2 ) ;
}
void F_17 ( struct V_15 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
if ( F_4 ( V_6 -> V_13 ) )
F_9 ( V_6 -> V_12 , NULL ) ;
else if ( V_6 -> V_13 )
F_9 ( V_6 -> V_12 ,
V_6 -> V_13 ) ;
}
static
int F_18 ( struct V_15 * V_23 , struct V_36 * V_37 )
{
struct V_5 * V_6 = V_23 -> V_8 ;
struct V_1 * V_2 ;
int V_9 ;
V_6 -> V_38 -> V_31 = F_19 ( 0 ) ;
V_9 = F_20 ( V_6 -> V_38 , V_37 , NULL ) ;
if ( V_9 ) {
F_13 ( V_23 -> V_7 , L_4 , V_9 ) ;
return V_9 ;
}
F_16 ( V_6 -> V_10 , & V_39 ) ;
V_2 = F_11 ( V_23 , V_6 -> V_38 ) ;
if ( ! V_2 )
return - V_34 ;
V_9 = F_5 ( V_23 , V_2 ) ;
return V_9 ;
}
int F_21 ( struct V_15 * V_23 )
{
struct V_5 * V_6 = V_23 -> V_8 ;
struct V_40 * V_41 ;
struct V_36 * V_37 ;
int V_9 ;
V_41 = F_22 ( V_23 -> V_7 -> V_42 , 0 , 0 ) ;
if ( ! V_41 )
return 0 ;
V_37 = F_23 ( V_41 ) ;
F_24 ( V_41 ) ;
if ( ! V_37 )
return - V_43 ;
V_6 -> V_38 = F_7 ( V_23 -> V_7 ,
sizeof( * V_6 -> V_38 ) ,
V_18 ) ;
if ( ! V_6 -> V_38 )
return - V_19 ;
V_9 = F_25 ( V_23 , V_6 -> V_38 ,
& V_44 ,
V_45 , NULL ) ;
if ( V_9 ) {
F_13 ( V_23 -> V_7 , L_5 , V_9 ) ;
return V_9 ;
}
V_9 = F_18 ( V_23 , V_37 ) ;
if ( V_9 )
F_26 ( V_6 -> V_38 ) ;
return V_9 ;
}
static int F_27 ( struct V_46 * V_7 , void * V_47 )
{
return V_7 -> V_42 == V_47 ;
}
int F_28 ( struct V_46 * V_7 ,
struct V_48 * * V_49 )
{
struct V_40 * V_50 ;
V_50 = F_22 ( V_7 -> V_42 , 0 , 0 ) ;
if ( ! F_29 ( V_50 , L_6 ) ) {
F_24 ( V_50 ) ;
return 0 ;
}
if ( V_49 )
F_30 ( V_7 , V_49 , F_27 , V_50 ) ;
F_24 ( V_50 ) ;
return 1 ;
}
