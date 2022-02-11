int F_1 ( T_1 V_1 , struct V_2 * V_3 , unsigned short V_4 ,
void * V_5 , T_1 V_6 , int V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_11 = F_2 ( sizeof( * V_13 ) + V_6 , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_13 = ( void * ) F_3 ( V_11 , sizeof( * V_13 ) ) ;
V_13 -> V_16 = F_4 ( V_1 ) ;
if ( V_3 )
V_13 -> V_17 = F_4 ( V_3 -> V_18 ) ;
else
V_13 -> V_17 = F_4 ( V_19 ) ;
V_13 -> V_20 = F_4 ( V_6 ) ;
if ( V_5 )
memcpy ( F_3 ( V_11 , V_6 ) , V_5 , V_6 ) ;
F_5 ( V_11 ) ;
F_6 ( V_4 , V_11 , V_7 , V_9 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
int F_8 ( struct V_8 * V_21 , T_1 V_17 , T_1 V_22 , T_2 V_23 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_24 * V_25 ;
int V_26 ;
F_9 ( L_1 , V_21 , V_17 , V_22 , V_23 ) ;
V_11 = F_2 ( sizeof( * V_13 ) + sizeof( * V_25 ) , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_13 = ( void * ) F_3 ( V_11 , sizeof( * V_13 ) ) ;
V_13 -> V_16 = F_4 ( V_27 ) ;
V_13 -> V_17 = F_4 ( V_17 ) ;
V_13 -> V_20 = F_4 ( sizeof( * V_25 ) ) ;
V_25 = ( void * ) F_3 ( V_11 , sizeof( * V_25 ) ) ;
V_25 -> V_23 = V_23 ;
V_25 -> V_16 = F_4 ( V_22 ) ;
V_26 = F_10 ( V_21 , V_11 ) ;
if ( V_26 < 0 )
F_7 ( V_11 ) ;
return V_26 ;
}
int F_11 ( struct V_8 * V_21 , T_1 V_17 , T_1 V_22 , T_2 V_23 ,
void * V_28 , T_3 V_29 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_30 * V_25 ;
int V_26 ;
F_9 ( L_2 , V_21 ) ;
V_11 = F_2 ( sizeof( * V_13 ) + sizeof( * V_25 ) + V_29 , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_13 = ( void * ) F_3 ( V_11 , sizeof( * V_13 ) ) ;
V_13 -> V_16 = F_4 ( V_31 ) ;
V_13 -> V_17 = F_4 ( V_17 ) ;
V_13 -> V_20 = F_4 ( sizeof( * V_25 ) + V_29 ) ;
V_25 = ( void * ) F_3 ( V_11 , sizeof( * V_25 ) + V_29 ) ;
V_25 -> V_16 = F_4 ( V_22 ) ;
V_25 -> V_23 = V_23 ;
if ( V_28 )
memcpy ( V_25 -> V_5 , V_28 , V_29 ) ;
V_26 = F_10 ( V_21 , V_11 ) ;
if ( V_26 < 0 )
F_7 ( V_11 ) ;
return V_26 ;
}
struct V_32 * F_12 ( unsigned short V_4 , T_1 V_16 ,
struct V_2 * V_3 )
{
struct V_32 * V_22 ;
F_13 (cmd, &hdev->mgmt_pending, list) {
if ( F_14 ( V_22 -> V_21 ) != V_4 )
continue;
if ( V_22 -> V_16 == V_16 )
return V_22 ;
}
return NULL ;
}
struct V_32 * F_15 ( unsigned short V_4 ,
T_1 V_16 ,
struct V_2 * V_3 ,
const void * V_5 )
{
struct V_32 * V_22 ;
F_13 (cmd, &hdev->mgmt_pending, list) {
if ( V_22 -> V_33 != V_5 )
continue;
if ( V_22 -> V_16 == V_16 )
return V_22 ;
}
return NULL ;
}
void F_16 ( T_1 V_16 , struct V_2 * V_3 ,
void (* F_17)( struct V_32 * V_22 , void * V_5 ) ,
void * V_5 )
{
struct V_32 * V_22 , * V_34 ;
F_18 (cmd, tmp, &hdev->mgmt_pending, list) {
if ( V_16 > 0 && V_22 -> V_16 != V_16 )
continue;
F_17 ( V_22 , V_5 ) ;
}
}
struct V_32 * F_19 ( struct V_8 * V_21 , T_1 V_16 ,
struct V_2 * V_3 ,
void * V_5 , T_1 V_20 )
{
struct V_32 * V_22 ;
V_22 = F_20 ( sizeof( * V_22 ) , V_14 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_16 = V_16 ;
V_22 -> V_17 = V_3 -> V_18 ;
V_22 -> V_35 = F_21 ( V_5 , V_20 , V_14 ) ;
if ( ! V_22 -> V_35 ) {
F_22 ( V_22 ) ;
return NULL ;
}
V_22 -> V_36 = V_20 ;
V_22 -> V_21 = V_21 ;
F_23 ( V_21 ) ;
F_24 ( & V_22 -> V_37 , & V_3 -> V_38 ) ;
return V_22 ;
}
void F_25 ( struct V_32 * V_22 )
{
F_26 ( V_22 -> V_21 ) ;
F_22 ( V_22 -> V_35 ) ;
F_22 ( V_22 ) ;
}
void F_27 ( struct V_32 * V_22 )
{
F_28 ( & V_22 -> V_37 ) ;
F_25 ( V_22 ) ;
}
