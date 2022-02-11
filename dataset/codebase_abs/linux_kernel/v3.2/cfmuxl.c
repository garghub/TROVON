struct V_1 * F_1 ( void )
{
struct V_2 * V_3 = F_2 ( sizeof( struct V_2 ) , V_4 ) ;
if ( ! V_3 )
return NULL ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_5 . V_6 = V_7 ;
V_3 -> V_5 . V_8 = V_9 ;
V_3 -> V_5 . V_10 = V_11 ;
F_3 ( & V_3 -> V_12 ) ;
F_3 ( & V_3 -> V_13 ) ;
F_4 ( & V_3 -> V_14 ) ;
F_4 ( & V_3 -> V_15 ) ;
snprintf ( V_3 -> V_5 . V_16 , V_17 , L_1 ) ;
return & V_3 -> V_5 ;
}
int F_5 ( struct V_1 * V_18 , struct V_1 * V_19 , T_1 V_20 )
{
struct V_2 * V_21 = (struct V_2 * ) V_18 ;
F_6 ( & V_21 -> V_14 ) ;
F_7 ( & V_19 -> V_22 , & V_21 -> V_13 ) ;
F_8 ( & V_21 -> V_14 ) ;
return 0 ;
}
static struct V_1 * F_9 ( struct V_23 * V_24 , T_2 V_25 )
{
struct V_1 * V_26 ;
F_10 (lyr, list, node) {
if ( V_26 -> V_25 == V_25 )
return V_26 ;
}
return NULL ;
}
int F_11 ( struct V_1 * V_18 , struct V_1 * V_27 , T_1 V_28 )
{
struct V_2 * V_21 = F_12 ( V_18 ) ;
struct V_1 * V_29 ;
F_6 ( & V_21 -> V_15 ) ;
V_29 = F_9 ( & V_21 -> V_12 , V_28 ) ;
if ( V_29 != NULL )
F_13 ( & V_29 -> V_22 ) ;
F_7 ( & V_27 -> V_22 , & V_21 -> V_12 ) ;
F_8 ( & V_21 -> V_15 ) ;
return 0 ;
}
struct V_1 * F_14 ( struct V_1 * V_18 , T_1 V_20 )
{
struct V_2 * V_21 = F_12 ( V_18 ) ;
struct V_1 * V_19 ;
int V_30 = V_20 % V_31 ;
F_6 ( & V_21 -> V_14 ) ;
F_15 ( V_21 -> V_32 [ V_30 ] , NULL ) ;
V_19 = F_9 ( & V_21 -> V_13 , V_20 ) ;
if ( V_19 == NULL )
goto V_33;
F_13 ( & V_19 -> V_22 ) ;
F_16 ( V_19 != NULL ) ;
V_33:
F_8 ( & V_21 -> V_14 ) ;
return V_19 ;
}
static struct V_1 * F_17 ( struct V_2 * V_21 , T_2 V_25 )
{
struct V_1 * V_27 ;
int V_30 = V_25 % V_34 ;
V_27 = F_18 ( V_21 -> V_35 [ V_30 ] ) ;
if ( V_27 == NULL || V_27 -> V_25 != V_25 ) {
F_6 ( & V_21 -> V_15 ) ;
V_27 = F_9 ( & V_21 -> V_12 , V_25 ) ;
F_19 ( V_21 -> V_35 [ V_30 ] , V_27 ) ;
F_8 ( & V_21 -> V_15 ) ;
}
return V_27 ;
}
static struct V_1 * F_20 ( struct V_2 * V_21 , struct V_36 * V_36 )
{
struct V_1 * V_19 ;
int V_30 = V_36 -> V_25 % V_31 ;
V_19 = F_18 ( V_21 -> V_32 [ V_30 ] ) ;
if ( V_19 == NULL || V_19 -> V_25 != V_36 -> V_25 ) {
F_6 ( & V_21 -> V_14 ) ;
V_19 = F_9 ( & V_21 -> V_13 , V_36 -> V_25 ) ;
F_19 ( V_21 -> V_32 [ V_30 ] , V_19 ) ;
F_8 ( & V_21 -> V_14 ) ;
}
return V_19 ;
}
struct V_1 * F_21 ( struct V_1 * V_18 , T_1 V_25 )
{
struct V_1 * V_27 ;
struct V_2 * V_21 = F_12 ( V_18 ) ;
int V_30 = V_25 % V_34 ;
if ( V_25 == 0 ) {
F_22 ( L_2 ) ;
return NULL ;
}
F_6 ( & V_21 -> V_15 ) ;
V_27 = F_9 ( & V_21 -> V_12 , V_25 ) ;
if ( V_27 == NULL )
goto V_33;
F_15 ( V_21 -> V_35 [ V_30 ] , NULL ) ;
F_13 ( & V_27 -> V_22 ) ;
V_33:
F_8 ( & V_21 -> V_15 ) ;
return V_27 ;
}
static int V_7 ( struct V_1 * V_18 , struct V_37 * V_38 )
{
int V_39 ;
struct V_2 * V_21 = F_12 ( V_18 ) ;
T_1 V_25 ;
struct V_1 * V_27 ;
if ( F_23 ( V_38 , & V_25 , 1 ) < 0 ) {
F_24 ( L_3 ) ;
F_25 ( V_38 ) ;
return - V_40 ;
}
F_26 () ;
V_27 = F_17 ( V_21 , V_25 ) ;
if ( V_27 == NULL ) {
F_27 ( L_4
L_5 , V_25 , V_25 ) ;
F_25 ( V_38 ) ;
F_28 () ;
return 0 ;
}
F_29 ( V_27 ) ;
F_28 () ;
V_39 = V_27 -> V_6 ( V_27 , V_38 ) ;
F_30 ( V_27 ) ;
return V_39 ;
}
static int V_9 ( struct V_1 * V_18 , struct V_37 * V_38 )
{
struct V_2 * V_21 = F_12 ( V_18 ) ;
int V_41 ;
T_1 V_28 ;
struct V_1 * V_19 ;
struct V_42 * V_43 = F_31 ( V_38 ) ;
F_32 ( ! V_43 ) ;
F_26 () ;
V_19 = F_20 ( V_21 , V_43 -> V_36 ) ;
if ( V_19 == NULL ) {
F_27 ( L_6 ,
V_43 -> V_36 -> V_25 , V_43 -> V_36 -> V_25 ) ;
F_28 () ;
F_25 ( V_38 ) ;
return - V_44 ;
}
V_43 -> V_45 += 1 ;
V_28 = V_43 -> V_46 ;
F_33 ( V_38 , & V_28 , 1 ) ;
F_34 ( V_19 ) ;
F_28 () ;
V_41 = V_19 -> V_8 ( V_19 , V_38 ) ;
F_35 ( V_19 ) ;
return V_41 ;
}
static void V_11 ( struct V_1 * V_18 , enum V_47 V_48 ,
int V_20 )
{
struct V_2 * V_21 = F_12 ( V_18 ) ;
struct V_1 * V_5 ;
int V_30 ;
F_26 () ;
F_10 (layer, &muxl->srvl_list, node) {
if ( F_36 ( V_5 , V_20 ) && V_5 -> V_10 ) {
if ( ( V_48 == V_49 ||
V_48 == V_50 ) &&
V_5 -> V_25 != 0 ) {
V_30 = V_5 -> V_25 % V_34 ;
F_6 ( & V_21 -> V_15 ) ;
F_15 ( V_21 -> V_35 [ V_30 ] , NULL ) ;
F_13 ( & V_5 -> V_22 ) ;
F_8 ( & V_21 -> V_15 ) ;
}
V_5 -> V_10 ( V_5 , V_48 , V_20 ) ;
}
}
F_28 () ;
}
