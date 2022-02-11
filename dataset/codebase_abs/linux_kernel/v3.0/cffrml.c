struct V_1 * F_1 ( T_1 V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_5 -> V_7 = F_4 ( int ) ;
if ( V_5 -> V_7 == NULL ) {
F_5 ( V_5 ) ;
return NULL ;
}
F_6 ( F_7 ( struct V_4 , V_8 ) == 0 ) ;
memset ( V_5 , 0 , sizeof( struct V_1 ) ) ;
V_5 -> V_8 . V_9 = V_10 ;
V_5 -> V_8 . V_11 = V_12 ;
V_5 -> V_8 . V_13 = V_14 ;
snprintf ( V_5 -> V_8 . V_15 , V_16 , L_2 , V_2 ) ;
V_5 -> V_17 = V_3 ;
V_5 -> V_8 . V_18 = V_2 ;
return (struct V_1 * ) V_5 ;
}
void F_8 ( struct V_1 * V_8 )
{
struct V_4 * V_5 = F_9 ( V_8 ) ;
F_10 ( V_5 -> V_7 ) ;
F_5 ( V_8 ) ;
}
void F_11 ( struct V_1 * V_5 , struct V_1 * V_19 )
{
V_5 -> V_19 = V_19 ;
}
void F_12 ( struct V_1 * V_5 , struct V_1 * V_20 )
{
V_5 -> V_20 = V_20 ;
}
static T_1 F_13 ( T_1 V_21 , void * V_22 , T_1 V_23 )
{
return F_14 ( V_21 , V_22 , V_23 ) ;
}
static int V_10 ( struct V_1 * V_24 , struct V_25 * V_26 )
{
T_1 V_27 ;
T_1 V_23 ;
T_1 V_28 ;
T_1 V_29 ;
struct V_4 * V_5 ;
V_5 = F_9 ( V_24 ) ;
F_15 ( V_26 , & V_27 , 2 ) ;
V_23 = F_16 ( V_27 ) ;
if ( ! V_5 -> V_17 )
V_23 -= 2 ;
if ( F_17 ( V_26 , V_23 ) < 0 ) {
++ V_30 ;
F_18 ( L_3 , V_23 ) ;
F_19 ( V_26 ) ;
return - V_31 ;
}
if ( V_5 -> V_17 ) {
F_20 ( V_26 , & V_27 , 2 ) ;
V_28 = F_16 ( V_27 ) ;
V_29 = F_21 ( V_26 , F_13 , 0xffff ) ;
if ( V_29 != V_28 ) {
F_22 ( V_26 , & V_27 , 2 ) ;
++ V_30 ;
++ V_32 ;
F_23 ( L_4 ,
V_28 , V_29 ) ;
return - V_33 ;
}
}
if ( F_24 ( V_26 ) ) {
++ V_30 ;
F_18 ( L_5 ) ;
F_19 ( V_26 ) ;
return - V_31 ;
}
if ( V_24 -> V_19 == NULL ) {
F_18 ( L_6 ) ;
F_19 ( V_26 ) ;
return - V_34 ;
}
return V_24 -> V_19 -> V_9 ( V_24 -> V_19 , V_26 ) ;
}
static int V_12 ( struct V_1 * V_24 , struct V_25 * V_26 )
{
int V_27 ;
T_1 V_21 ;
T_1 V_23 ;
struct V_4 * V_5 = F_9 ( V_24 ) ;
if ( V_5 -> V_17 ) {
V_21 = F_21 ( V_26 , F_13 , 0xffff ) ;
V_27 = F_25 ( V_21 ) ;
F_22 ( V_26 , & V_27 , 2 ) ;
} else {
F_26 ( V_26 , 2 ) ;
}
V_23 = F_27 ( V_26 ) ;
V_27 = F_25 ( V_23 ) ;
F_28 ( V_26 , & V_27 , 2 ) ;
F_29 ( V_26 ) -> V_35 += 2 ;
if ( F_24 ( V_26 ) ) {
F_18 ( L_5 ) ;
F_19 ( V_26 ) ;
return - V_31 ;
}
if ( V_24 -> V_20 == NULL ) {
F_19 ( V_26 ) ;
return - V_36 ;
}
return V_24 -> V_20 -> V_11 ( V_24 -> V_20 , V_26 ) ;
}
static void V_14 ( struct V_1 * V_24 , enum V_37 V_38 ,
int V_2 )
{
if ( V_24 -> V_19 && V_24 -> V_19 -> V_13 )
V_24 -> V_19 -> V_13 ( V_24 -> V_19 , V_38 , V_24 -> V_18 ) ;
}
void F_30 ( struct V_1 * V_24 )
{
struct V_4 * V_5 = F_9 ( V_24 ) ;
if ( V_24 != NULL && V_5 -> V_7 != NULL )
F_31 ( * V_5 -> V_7 ) ;
}
void F_32 ( struct V_1 * V_24 )
{
struct V_4 * V_5 = F_9 ( V_24 ) ;
if ( V_24 != NULL && V_5 -> V_7 != NULL )
F_33 ( * V_5 -> V_7 ) ;
}
int F_34 ( struct V_1 * V_24 )
{
int V_39 , V_40 = 0 ;
struct V_4 * V_5 = F_9 ( V_24 ) ;
F_35 (i)
V_40 += * F_36 ( V_5 -> V_7 , V_39 ) ;
return V_40 ;
}
