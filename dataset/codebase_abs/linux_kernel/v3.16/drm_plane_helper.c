static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_8 ;
int V_9 = 0 ;
F_2 ( ! F_3 ( & V_7 -> V_10 . V_11 ) ) ;
F_4 (connector, &dev->mode_config.connector_list, head)
if ( V_8 -> V_12 && V_8 -> V_12 -> V_2 == V_2 ) {
if ( V_4 != NULL && V_9 < V_5 )
* ( V_4 ++ ) = V_8 ;
V_9 ++ ;
}
return V_9 ;
}
int F_5 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_17 * V_19 ,
const struct V_17 * V_20 ,
int V_21 ,
int V_22 ,
bool V_23 ,
bool V_24 ,
bool * V_25 )
{
int V_26 , V_27 ;
if ( ! V_2 -> V_28 && ! V_24 ) {
F_6 ( L_1 ) ;
return - V_29 ;
}
V_26 = F_7 ( V_18 , V_19 , V_21 , V_22 ) ;
V_27 = F_8 ( V_18 , V_19 , V_21 , V_22 ) ;
if ( V_26 < 0 || V_27 < 0 ) {
F_6 ( L_2 ) ;
return - V_30 ;
}
* V_25 = F_9 ( V_18 , V_19 , V_20 , V_26 , V_27 ) ;
if ( ! * V_25 )
return 0 ;
if ( ! V_23 && ! F_10 ( V_19 , V_20 ) ) {
F_6 ( L_3 ) ;
return - V_29 ;
}
return 0 ;
}
int F_11 ( struct V_13 * V_14 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_31 , int V_32 ,
unsigned int V_33 , unsigned int V_34 ,
T_1 V_35 , T_1 V_36 ,
T_1 V_37 , T_1 V_38 )
{
struct V_39 V_40 = {
. V_2 = V_2 ,
. V_16 = V_16 ,
. V_41 = & V_2 -> V_41 ,
. V_42 = V_35 >> 16 ,
. V_43 = V_36 >> 16 ,
} ;
struct V_17 V_18 = {
. V_44 = V_35 ,
. y1 = V_36 ,
. V_45 = V_35 + V_37 ,
. V_46 = V_36 + V_38 ,
} ;
struct V_17 V_19 = {
. V_44 = V_31 ,
. y1 = V_32 ,
. V_45 = V_31 + V_33 ,
. V_46 = V_32 + V_34 ,
} ;
const struct V_17 V_20 = {
. V_45 = V_2 -> V_41 . V_47 ,
. V_46 = V_2 -> V_41 . V_48 ,
} ;
struct V_3 * * V_4 ;
int V_5 , V_49 ;
bool V_25 ;
V_49 = F_5 ( V_14 , V_2 , V_16 ,
& V_18 , & V_19 , & V_20 ,
V_50 ,
V_50 ,
false , false , & V_25 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_25 )
return V_14 -> V_51 -> V_52 ( V_14 ) ;
V_5 = F_1 ( V_2 , NULL , 0 ) ;
F_12 ( V_5 == 0 ) ;
V_4 = F_13 ( V_5 * sizeof( * V_4 ) ,
V_53 ) ;
if ( ! V_4 )
return - V_54 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_40 . V_55 = V_4 ;
V_40 . V_5 = V_5 ;
V_49 = V_2 -> V_51 -> V_56 ( & V_40 ) ;
F_14 ( V_4 ) ;
return V_49 ;
}
int F_15 ( struct V_13 * V_14 )
{
return - V_29 ;
}
void F_16 ( struct V_13 * V_14 )
{
F_17 ( V_14 ) ;
F_14 ( V_14 ) ;
}
struct V_13 * F_18 ( struct V_6 * V_7 ,
const T_1 * V_57 ,
int V_58 )
{
struct V_13 * V_59 ;
int V_49 ;
V_59 = F_13 ( sizeof( * V_59 ) , V_53 ) ;
if ( V_59 == NULL ) {
F_6 ( L_4 ) ;
return NULL ;
}
if ( V_57 == NULL ) {
V_57 = V_60 ;
V_58 = F_19 ( V_60 ) ;
}
V_49 = F_20 ( V_7 , V_59 , 0 , & V_61 ,
V_57 , V_58 ,
V_62 ) ;
if ( V_49 ) {
F_14 ( V_59 ) ;
V_59 = NULL ;
}
return V_59 ;
}
int F_21 ( struct V_6 * V_7 , struct V_1 * V_2 ,
const struct V_63 * V_51 )
{
struct V_13 * V_59 ;
V_59 = F_18 ( V_7 , NULL , 0 ) ;
return F_22 ( V_7 , V_2 , V_59 , NULL , V_51 ) ;
}
