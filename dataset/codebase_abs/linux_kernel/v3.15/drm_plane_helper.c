static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_8 ;
int V_9 = 0 ;
F_2 (connector, &dev->mode_config.connector_list, head)
if ( V_8 -> V_10 && V_8 -> V_10 -> V_2 == V_2 ) {
if ( V_4 != NULL && V_9 < V_5 )
* ( V_4 ++ ) = V_8 ;
V_9 ++ ;
}
return V_9 ;
}
int F_3 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_15 , int V_16 ,
unsigned int V_17 , unsigned int V_18 ,
T_1 V_19 , T_1 V_20 ,
T_1 V_21 , T_1 V_22 )
{
struct V_23 V_24 = {
. V_2 = V_2 ,
. V_14 = V_14 ,
. V_25 = & V_2 -> V_25 ,
. V_26 = V_19 >> 16 ,
. V_27 = V_20 >> 16 ,
} ;
struct V_28 V_29 = {
. V_30 = V_15 ,
. y1 = V_16 ,
. V_31 = V_15 + V_17 ,
. V_32 = V_16 + V_18 ,
} ;
struct V_28 V_33 = {
. V_31 = V_2 -> V_25 . V_34 ,
. V_32 = V_2 -> V_25 . V_35 ,
} ;
struct V_3 * * V_4 ;
struct V_13 * V_36 ;
int V_5 , V_37 ;
if ( ! V_2 -> V_38 ) {
F_4 ( L_1 ) ;
return - V_39 ;
}
if ( ( V_19 | V_20 | V_21 | V_22 ) & V_40 ) {
F_4 ( L_2 ) ;
return - V_39 ;
}
if ( V_12 -> V_41 != F_5 ( V_2 ) ) {
F_4 ( L_3 ) ;
return - V_39 ;
}
if ( V_17 != V_21 || V_18 != V_22 ) {
F_4 ( L_4 ) ;
return - V_39 ;
}
F_6 ( & V_29 , & V_33 ) ;
if ( V_29 . V_30 != 0 || V_29 . y1 != 0 ||
V_29 . V_31 != V_2 -> V_25 . V_34 || V_29 . V_32 != V_2 -> V_25 . V_35 ) {
F_4 ( L_5 ) ;
return - V_39 ;
}
V_37 = F_7 ( V_2 , V_15 , V_16 , & V_2 -> V_25 , V_14 ) ;
if ( V_37 )
return V_37 ;
V_5 = F_1 ( V_2 , NULL , 0 ) ;
F_8 ( V_5 == 0 ) ;
V_4 = F_9 ( V_5 * sizeof( * V_4 ) ,
V_42 ) ;
if ( ! V_4 )
return - V_43 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_24 . V_44 = V_4 ;
V_24 . V_5 = V_5 ;
V_36 = V_12 -> V_14 ;
V_37 = V_2 -> V_45 -> V_46 ( & V_24 ) ;
V_12 -> V_14 = V_36 ;
F_10 ( V_4 ) ;
return V_37 ;
}
int F_11 ( struct V_11 * V_12 )
{
return - V_39 ;
}
void F_12 ( struct V_11 * V_12 )
{
V_12 -> V_45 -> V_47 ( V_12 ) ;
F_13 ( V_12 ) ;
F_10 ( V_12 ) ;
}
struct V_11 * F_14 ( struct V_6 * V_7 ,
const T_1 * V_48 ,
int V_49 )
{
struct V_11 * V_50 ;
int V_37 ;
V_50 = F_9 ( sizeof( * V_50 ) , V_42 ) ;
if ( V_50 == NULL ) {
F_4 ( L_6 ) ;
return NULL ;
}
if ( V_48 == NULL ) {
V_48 = V_51 ;
V_49 = F_15 ( V_51 ) ;
}
V_37 = F_16 ( V_7 , V_50 , 0 , & V_52 ,
V_48 , V_49 ,
V_53 ) ;
if ( V_37 ) {
F_10 ( V_50 ) ;
V_50 = NULL ;
}
return V_50 ;
}
int F_17 ( struct V_6 * V_7 , struct V_1 * V_2 ,
const struct V_54 * V_45 )
{
struct V_11 * V_50 ;
V_50 = F_14 ( V_7 , NULL , 0 ) ;
return F_18 ( V_7 , V_2 , V_50 , NULL , V_45 ) ;
}
