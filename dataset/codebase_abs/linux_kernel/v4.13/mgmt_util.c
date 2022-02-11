static struct V_1 * F_1 ( T_1 V_2 , T_2 V_3 ,
T_3 V_4 , T_3 V_5 , void * V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 ;
V_9 = F_2 ( 6 + V_5 , V_10 ) ;
if ( ! V_9 )
return NULL ;
F_3 ( V_3 , F_4 ( V_9 , 4 ) ) ;
F_5 ( V_4 , F_4 ( V_9 , 2 ) ) ;
if ( V_6 )
F_6 ( V_9 , V_6 , V_5 ) ;
F_7 ( V_9 ) ;
V_8 = F_8 ( V_9 , V_11 ) ;
V_8 -> V_4 = F_9 ( V_12 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_5 = F_9 ( V_9 -> V_5 - V_11 ) ;
return V_9 ;
}
int F_10 ( T_3 V_13 , struct V_14 * V_15 , unsigned short V_16 ,
void * V_17 , T_3 V_18 , int V_19 , struct V_20 * V_21 )
{
struct V_1 * V_9 ;
struct V_22 * V_8 ;
V_9 = F_11 ( sizeof( * V_8 ) + V_18 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
V_8 = F_4 ( V_9 , sizeof( * V_8 ) ) ;
V_8 -> V_4 = F_9 ( V_13 ) ;
if ( V_15 )
V_8 -> V_2 = F_9 ( V_15 -> V_25 ) ;
else
V_8 -> V_2 = F_9 ( V_26 ) ;
V_8 -> V_5 = F_9 ( V_18 ) ;
if ( V_17 )
F_6 ( V_9 , V_17 , V_18 ) ;
F_7 ( V_9 ) ;
F_12 ( V_16 , V_9 , V_19 , V_21 ) ;
if ( V_16 == V_27 )
F_13 ( V_15 , V_13 , V_17 , V_18 ,
F_14 ( V_9 ) , V_19 , V_21 ) ;
F_15 ( V_9 ) ;
return 0 ;
}
int F_16 ( struct V_20 * V_28 , T_3 V_2 , T_3 V_29 , T_4 V_30 )
{
struct V_1 * V_9 , * V_31 ;
struct V_22 * V_8 ;
struct V_32 * V_33 ;
int V_34 ;
F_17 ( L_1 , V_28 , V_2 , V_29 , V_30 ) ;
V_9 = F_11 ( sizeof( * V_8 ) + sizeof( * V_33 ) , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
V_8 = F_4 ( V_9 , sizeof( * V_8 ) ) ;
V_8 -> V_4 = F_9 ( V_35 ) ;
V_8 -> V_2 = F_9 ( V_2 ) ;
V_8 -> V_5 = F_9 ( sizeof( * V_33 ) ) ;
V_33 = F_4 ( V_9 , sizeof( * V_33 ) ) ;
V_33 -> V_30 = V_30 ;
V_33 -> V_4 = F_9 ( V_29 ) ;
V_31 = F_1 ( V_8 -> V_2 , F_18 ( V_28 ) ,
V_35 , sizeof( * V_33 ) , V_33 ) ;
if ( V_31 )
V_9 -> V_36 = V_31 -> V_36 ;
else
F_7 ( V_9 ) ;
V_34 = F_19 ( V_28 , V_9 ) ;
if ( V_34 < 0 )
F_15 ( V_9 ) ;
if ( V_31 ) {
F_12 ( V_37 , V_31 ,
V_38 , NULL ) ;
F_15 ( V_31 ) ;
}
return V_34 ;
}
int F_20 ( struct V_20 * V_28 , T_3 V_2 , T_3 V_29 , T_4 V_30 ,
void * V_39 , T_5 V_40 )
{
struct V_1 * V_9 , * V_31 ;
struct V_22 * V_8 ;
struct V_41 * V_33 ;
int V_34 ;
F_17 ( L_2 , V_28 ) ;
V_9 = F_11 ( sizeof( * V_8 ) + sizeof( * V_33 ) + V_40 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
V_8 = F_4 ( V_9 , sizeof( * V_8 ) ) ;
V_8 -> V_4 = F_9 ( V_42 ) ;
V_8 -> V_2 = F_9 ( V_2 ) ;
V_8 -> V_5 = F_9 ( sizeof( * V_33 ) + V_40 ) ;
V_33 = F_4 ( V_9 , sizeof( * V_33 ) + V_40 ) ;
V_33 -> V_4 = F_9 ( V_29 ) ;
V_33 -> V_30 = V_30 ;
if ( V_39 )
memcpy ( V_33 -> V_17 , V_39 , V_40 ) ;
V_31 = F_1 ( V_8 -> V_2 , F_18 ( V_28 ) ,
V_42 ,
sizeof( * V_33 ) + V_40 , V_33 ) ;
if ( V_31 )
V_9 -> V_36 = V_31 -> V_36 ;
else
F_7 ( V_9 ) ;
V_34 = F_19 ( V_28 , V_9 ) ;
if ( V_34 < 0 )
F_15 ( V_9 ) ;
if ( V_31 ) {
F_12 ( V_37 , V_31 ,
V_38 , NULL ) ;
F_15 ( V_31 ) ;
}
return V_34 ;
}
struct V_43 * F_21 ( unsigned short V_16 , T_3 V_4 ,
struct V_14 * V_15 )
{
struct V_43 * V_29 ;
F_22 (cmd, &hdev->mgmt_pending, list) {
if ( F_23 ( V_29 -> V_28 ) != V_16 )
continue;
if ( V_29 -> V_4 == V_4 )
return V_29 ;
}
return NULL ;
}
struct V_43 * F_24 ( unsigned short V_16 ,
T_3 V_4 ,
struct V_14 * V_15 ,
const void * V_17 )
{
struct V_43 * V_29 ;
F_22 (cmd, &hdev->mgmt_pending, list) {
if ( V_29 -> V_44 != V_17 )
continue;
if ( V_29 -> V_4 == V_4 )
return V_29 ;
}
return NULL ;
}
void F_25 ( T_3 V_4 , struct V_14 * V_15 ,
void (* F_26)( struct V_43 * V_29 , void * V_17 ) ,
void * V_17 )
{
struct V_43 * V_29 , * V_45 ;
F_27 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_4 > 0 && V_29 -> V_4 != V_4 )
continue;
F_26 ( V_29 , V_17 ) ;
}
}
struct V_43 * F_28 ( struct V_20 * V_28 , T_3 V_4 ,
struct V_14 * V_15 ,
void * V_17 , T_3 V_5 )
{
struct V_43 * V_29 ;
V_29 = F_29 ( sizeof( * V_29 ) , V_23 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_4 = V_4 ;
V_29 -> V_2 = V_15 -> V_25 ;
V_29 -> V_46 = F_30 ( V_17 , V_5 , V_23 ) ;
if ( ! V_29 -> V_46 ) {
F_31 ( V_29 ) ;
return NULL ;
}
V_29 -> V_47 = V_5 ;
V_29 -> V_28 = V_28 ;
F_32 ( V_28 ) ;
F_33 ( & V_29 -> V_48 , & V_15 -> V_49 ) ;
return V_29 ;
}
void F_34 ( struct V_43 * V_29 )
{
F_35 ( V_29 -> V_28 ) ;
F_31 ( V_29 -> V_46 ) ;
F_31 ( V_29 ) ;
}
void F_36 ( struct V_43 * V_29 )
{
F_37 ( & V_29 -> V_48 ) ;
F_34 ( V_29 ) ;
}
