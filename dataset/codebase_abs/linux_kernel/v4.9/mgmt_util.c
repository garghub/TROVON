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
memcpy ( F_4 ( V_9 , V_5 ) , V_6 , V_5 ) ;
F_6 ( V_9 ) ;
V_8 = ( void * ) F_7 ( V_9 , V_11 ) ;
V_8 -> V_4 = F_8 ( V_12 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_5 = F_8 ( V_9 -> V_5 - V_11 ) ;
return V_9 ;
}
int F_9 ( T_3 V_13 , struct V_14 * V_15 , unsigned short V_16 ,
void * V_17 , T_3 V_18 , int V_19 , struct V_20 * V_21 )
{
struct V_1 * V_9 ;
struct V_22 * V_8 ;
V_9 = F_10 ( sizeof( * V_8 ) + V_18 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
V_8 = ( void * ) F_4 ( V_9 , sizeof( * V_8 ) ) ;
V_8 -> V_4 = F_8 ( V_13 ) ;
if ( V_15 )
V_8 -> V_2 = F_8 ( V_15 -> V_25 ) ;
else
V_8 -> V_2 = F_8 ( V_26 ) ;
V_8 -> V_5 = F_8 ( V_18 ) ;
if ( V_17 )
memcpy ( F_4 ( V_9 , V_18 ) , V_17 , V_18 ) ;
F_6 ( V_9 ) ;
F_11 ( V_16 , V_9 , V_19 , V_21 ) ;
if ( V_16 == V_27 )
F_12 ( V_15 , V_13 , V_17 , V_18 ,
F_13 ( V_9 ) , V_19 , V_21 ) ;
F_14 ( V_9 ) ;
return 0 ;
}
int F_15 ( struct V_20 * V_28 , T_3 V_2 , T_3 V_29 , T_4 V_30 )
{
struct V_1 * V_9 , * V_31 ;
struct V_22 * V_8 ;
struct V_32 * V_33 ;
int V_34 ;
F_16 ( L_1 , V_28 , V_2 , V_29 , V_30 ) ;
V_9 = F_10 ( sizeof( * V_8 ) + sizeof( * V_33 ) , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
V_8 = ( void * ) F_4 ( V_9 , sizeof( * V_8 ) ) ;
V_8 -> V_4 = F_8 ( V_35 ) ;
V_8 -> V_2 = F_8 ( V_2 ) ;
V_8 -> V_5 = F_8 ( sizeof( * V_33 ) ) ;
V_33 = ( void * ) F_4 ( V_9 , sizeof( * V_33 ) ) ;
V_33 -> V_30 = V_30 ;
V_33 -> V_4 = F_8 ( V_29 ) ;
V_31 = F_1 ( V_8 -> V_2 , F_17 ( V_28 ) ,
V_35 , sizeof( * V_33 ) , V_33 ) ;
if ( V_31 )
V_9 -> V_36 = V_31 -> V_36 ;
else
F_6 ( V_9 ) ;
V_34 = F_18 ( V_28 , V_9 ) ;
if ( V_34 < 0 )
F_14 ( V_9 ) ;
if ( V_31 ) {
F_11 ( V_37 , V_31 ,
V_38 , NULL ) ;
F_14 ( V_31 ) ;
}
return V_34 ;
}
int F_19 ( struct V_20 * V_28 , T_3 V_2 , T_3 V_29 , T_4 V_30 ,
void * V_39 , T_5 V_40 )
{
struct V_1 * V_9 , * V_31 ;
struct V_22 * V_8 ;
struct V_41 * V_33 ;
int V_34 ;
F_16 ( L_2 , V_28 ) ;
V_9 = F_10 ( sizeof( * V_8 ) + sizeof( * V_33 ) + V_40 , V_23 ) ;
if ( ! V_9 )
return - V_24 ;
V_8 = ( void * ) F_4 ( V_9 , sizeof( * V_8 ) ) ;
V_8 -> V_4 = F_8 ( V_42 ) ;
V_8 -> V_2 = F_8 ( V_2 ) ;
V_8 -> V_5 = F_8 ( sizeof( * V_33 ) + V_40 ) ;
V_33 = ( void * ) F_4 ( V_9 , sizeof( * V_33 ) + V_40 ) ;
V_33 -> V_4 = F_8 ( V_29 ) ;
V_33 -> V_30 = V_30 ;
if ( V_39 )
memcpy ( V_33 -> V_17 , V_39 , V_40 ) ;
V_31 = F_1 ( V_8 -> V_2 , F_17 ( V_28 ) ,
V_42 ,
sizeof( * V_33 ) + V_40 , V_33 ) ;
if ( V_31 )
V_9 -> V_36 = V_31 -> V_36 ;
else
F_6 ( V_9 ) ;
V_34 = F_18 ( V_28 , V_9 ) ;
if ( V_34 < 0 )
F_14 ( V_9 ) ;
if ( V_31 ) {
F_11 ( V_37 , V_31 ,
V_38 , NULL ) ;
F_14 ( V_31 ) ;
}
return V_34 ;
}
struct V_43 * F_20 ( unsigned short V_16 , T_3 V_4 ,
struct V_14 * V_15 )
{
struct V_43 * V_29 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( F_22 ( V_29 -> V_28 ) != V_16 )
continue;
if ( V_29 -> V_4 == V_4 )
return V_29 ;
}
return NULL ;
}
struct V_43 * F_23 ( unsigned short V_16 ,
T_3 V_4 ,
struct V_14 * V_15 ,
const void * V_17 )
{
struct V_43 * V_29 ;
F_21 (cmd, &hdev->mgmt_pending, list) {
if ( V_29 -> V_44 != V_17 )
continue;
if ( V_29 -> V_4 == V_4 )
return V_29 ;
}
return NULL ;
}
void F_24 ( T_3 V_4 , struct V_14 * V_15 ,
void (* F_25)( struct V_43 * V_29 , void * V_17 ) ,
void * V_17 )
{
struct V_43 * V_29 , * V_45 ;
F_26 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_4 > 0 && V_29 -> V_4 != V_4 )
continue;
F_25 ( V_29 , V_17 ) ;
}
}
struct V_43 * F_27 ( struct V_20 * V_28 , T_3 V_4 ,
struct V_14 * V_15 ,
void * V_17 , T_3 V_5 )
{
struct V_43 * V_29 ;
V_29 = F_28 ( sizeof( * V_29 ) , V_23 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_4 = V_4 ;
V_29 -> V_2 = V_15 -> V_25 ;
V_29 -> V_46 = F_29 ( V_17 , V_5 , V_23 ) ;
if ( ! V_29 -> V_46 ) {
F_30 ( V_29 ) ;
return NULL ;
}
V_29 -> V_47 = V_5 ;
V_29 -> V_28 = V_28 ;
F_31 ( V_28 ) ;
F_32 ( & V_29 -> V_48 , & V_15 -> V_49 ) ;
return V_29 ;
}
void F_33 ( struct V_43 * V_29 )
{
F_34 ( V_29 -> V_28 ) ;
F_30 ( V_29 -> V_46 ) ;
F_30 ( V_29 ) ;
}
void F_35 ( struct V_43 * V_29 )
{
F_36 ( & V_29 -> V_48 ) ;
F_33 ( V_29 ) ;
}
