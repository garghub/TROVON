struct V_1 * F_1 ( T_1 V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_7 = F_3 ( int ) ;
if ( V_5 -> V_7 == NULL ) {
F_4 ( V_5 ) ;
return NULL ;
}
F_5 ( F_6 ( struct V_4 , V_8 ) == 0 ) ;
V_5 -> V_8 . V_9 = V_10 ;
V_5 -> V_8 . V_11 = V_12 ;
V_5 -> V_8 . V_13 = V_14 ;
snprintf ( V_5 -> V_8 . V_15 , V_16 , L_1 , V_2 ) ;
V_5 -> V_17 = V_3 ;
V_5 -> V_8 . V_18 = V_2 ;
return (struct V_1 * ) V_5 ;
}
void F_7 ( struct V_1 * V_8 )
{
struct V_4 * V_5 = F_8 ( V_8 ) ;
F_9 ( V_5 -> V_7 ) ;
F_4 ( V_8 ) ;
}
void F_10 ( struct V_1 * V_5 , struct V_1 * V_19 )
{
V_5 -> V_19 = V_19 ;
}
void F_11 ( struct V_1 * V_5 , struct V_1 * V_20 )
{
V_5 -> V_20 = V_20 ;
}
static T_1 F_12 ( T_1 V_21 , void * V_22 , T_1 V_23 )
{
return F_13 ( V_21 , V_22 , V_23 ) ;
}
static int V_10 ( struct V_1 * V_24 , struct V_25 * V_26 )
{
T_1 V_27 ;
T_1 V_23 ;
T_1 V_28 ;
T_1 V_29 ;
struct V_4 * V_5 ;
V_5 = F_8 ( V_24 ) ;
F_14 ( V_26 , & V_27 , 2 ) ;
V_23 = F_15 ( V_27 ) ;
if ( ! V_5 -> V_17 )
V_23 -= 2 ;
if ( F_16 ( V_26 , V_23 ) < 0 ) {
++ V_30 ;
F_17 ( L_2 , V_23 ) ;
F_18 ( V_26 ) ;
return - V_31 ;
}
if ( V_5 -> V_17 ) {
F_19 ( V_26 , & V_27 , 2 ) ;
V_28 = F_15 ( V_27 ) ;
V_29 = F_20 ( V_26 , F_12 , 0xffff ) ;
if ( V_29 != V_28 ) {
F_21 ( V_26 , & V_27 , 2 ) ;
++ V_30 ;
++ V_32 ;
F_22 ( L_3 ,
V_28 , V_29 ) ;
return - V_33 ;
}
}
if ( F_23 ( V_26 ) ) {
++ V_30 ;
F_17 ( L_4 ) ;
F_18 ( V_26 ) ;
return - V_31 ;
}
if ( V_24 -> V_19 == NULL ) {
F_17 ( L_5 ) ;
F_18 ( V_26 ) ;
return - V_34 ;
}
return V_24 -> V_19 -> V_9 ( V_24 -> V_19 , V_26 ) ;
}
static int V_12 ( struct V_1 * V_24 , struct V_25 * V_26 )
{
T_1 V_21 ;
T_1 V_23 ;
T_2 V_35 ;
struct V_4 * V_5 = F_8 ( V_24 ) ;
if ( V_5 -> V_17 ) {
V_21 = F_20 ( V_26 , F_12 , 0xffff ) ;
V_35 = F_24 ( V_21 ) ;
F_21 ( V_26 , & V_35 , 2 ) ;
} else {
F_25 ( V_26 , 2 ) ;
}
V_23 = F_26 ( V_26 ) ;
V_35 = F_24 ( V_23 ) ;
F_27 ( V_26 , & V_35 , 2 ) ;
F_28 ( V_26 ) -> V_36 += 2 ;
if ( F_23 ( V_26 ) ) {
F_17 ( L_4 ) ;
F_18 ( V_26 ) ;
return - V_31 ;
}
if ( V_24 -> V_20 == NULL ) {
F_18 ( V_26 ) ;
return - V_37 ;
}
return V_24 -> V_20 -> V_11 ( V_24 -> V_20 , V_26 ) ;
}
static void V_14 ( struct V_1 * V_24 , enum V_38 V_39 ,
int V_2 )
{
if ( V_24 -> V_19 && V_24 -> V_19 -> V_13 )
V_24 -> V_19 -> V_13 ( V_24 -> V_19 , V_39 , V_24 -> V_18 ) ;
}
void F_29 ( struct V_1 * V_24 )
{
struct V_4 * V_5 = F_8 ( V_24 ) ;
if ( V_24 != NULL && V_5 -> V_7 != NULL )
F_30 ( * V_5 -> V_7 ) ;
}
void F_31 ( struct V_1 * V_24 )
{
struct V_4 * V_5 = F_8 ( V_24 ) ;
if ( V_24 != NULL && V_5 -> V_7 != NULL )
F_32 ( * V_5 -> V_7 ) ;
}
int F_33 ( struct V_1 * V_24 )
{
int V_40 , V_41 = 0 ;
struct V_4 * V_5 = F_8 ( V_24 ) ;
F_34 (i)
V_41 += * F_35 ( V_5 -> V_7 , V_40 ) ;
return V_41 ;
}
