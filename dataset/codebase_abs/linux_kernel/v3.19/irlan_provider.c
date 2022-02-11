static int F_1 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 ;
V_6 = V_1 ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == IRLAN_MAGIC, return -1;) ;
F_2 (skb != NULL, return -1;) ;
V_7 = V_4 -> V_8 [ 0 ] ;
switch( V_7 ) {
case V_9 :
F_3 ( L_1 ) ;
F_4 ( V_6 , V_10 , V_4 ) ;
break;
case V_11 :
F_3 ( L_2 ) ;
F_4 ( V_6 , V_12 , V_4 ) ;
break;
case V_13 :
F_3 ( L_3 ) ;
F_4 ( V_6 , V_14 , V_4 ) ;
break;
case V_15 :
F_3 ( L_4 ) ;
F_4 ( V_6 , V_16 , V_4 ) ;
break;
case V_17 :
F_3 ( L_5 , V_18 ) ;
F_3 ( L_6 , V_18 ) ;
break;
case V_19 :
F_3 ( L_7 ) ;
F_3 ( L_6 , V_18 ) ;
break;
default:
F_3 ( L_8 , V_18 ) ;
break;
}
return 0 ;
}
static void F_5 ( void * V_1 , void * V_2 ,
struct V_20 * V_21 ,
T_2 V_22 ,
T_1 V_23 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 ;
V_6 = V_1 ;
V_25 = V_2 ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == IRLAN_MAGIC, return;) ;
F_2 (tsap == self->provider.tsap_ctrl,return;) ;
F_2 (self->provider.state == IRLAN_IDLE, return;) ;
V_6 -> V_26 . V_22 = V_22 ;
V_6 -> V_26 . V_23 = V_23 ;
F_4 ( V_6 , V_27 , NULL ) ;
if ( ( V_6 -> V_26 . V_28 == V_29 ) &&
( V_6 -> V_30 . V_31 == V_32 ) )
{
F_6 ( V_6 , V_6 -> V_33 , V_6 -> V_34 ) ;
}
}
void F_7 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == IRLAN_MAGIC, return;) ;
F_8 ( V_25 , V_35 , NULL ) ;
}
static void F_9 ( void * V_1 , void * V_2 ,
T_3 V_36 ,
struct V_3 * V_37 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 ;
F_3 ( L_9 , V_18 , V_36 ) ;
V_6 = V_1 ;
V_25 = V_2 ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == IRLAN_MAGIC, return;) ;
F_2 (tsap != NULL, return;) ;
F_2 (tsap->magic == TTP_TSAP_MAGIC, return;) ;
F_2 (tsap == self->provider.tsap_ctrl, return;) ;
F_4 ( V_6 , V_38 , NULL ) ;
}
int F_10 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_39 ;
V_39 = F_11 ( V_6 , V_13 , V_4 ) ;
F_12 ( V_6 ) ;
return V_39 ;
}
int F_11 ( struct V_5 * V_6 , int V_40 ,
struct V_3 * V_4 )
{
T_1 * V_41 ;
T_1 * V_42 ;
int V_43 ;
T_4 V_44 ;
int V_45 ;
char * V_46 ;
char * V_47 ;
int V_39 = V_48 ;
F_2 (skb != NULL, return -RSP_PROTOCOL_ERROR;) ;
F_3 ( L_10 , V_18 , ( int ) V_4 -> V_49 ) ;
F_2 (self != NULL, return -RSP_PROTOCOL_ERROR;) ;
F_2 (self->magic == IRLAN_MAGIC, return -RSP_PROTOCOL_ERROR;) ;
if ( ! V_4 )
return - V_50 ;
V_41 = V_4 -> V_8 ;
V_46 = F_13 ( 255 , V_51 ) ;
if ( ! V_46 )
return - V_52 ;
V_47 = F_13 ( 1016 , V_51 ) ;
if ( ! V_47 ) {
F_14 ( V_46 ) ;
return - V_52 ;
}
V_43 = V_41 [ 1 ] ;
F_3 ( L_11 , V_43 ) ;
V_42 = V_41 + 2 ;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
V_39 = F_15 ( V_42 , V_46 , V_47 , & V_44 ) ;
if ( V_39 < 0 ) {
F_3 ( L_12 , V_18 ) ;
break;
}
V_42 += V_39 ;
V_39 = V_48 ;
F_16 ( V_6 , V_46 , V_47 ) ;
}
F_14 ( V_46 ) ;
F_14 ( V_47 ) ;
return V_39 ;
}
void F_17 ( struct V_5 * V_6 , int V_53 ,
int V_54 )
{
struct V_3 * V_4 ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == IRLAN_MAGIC, return;) ;
V_4 = F_18 ( V_55 + V_56 +
F_19 ( L_13 , L_14 ) +
F_19 ( L_13 , L_15 ) +
F_19 ( L_13 , L_16 ) +
F_19 ( L_17 , L_18 ) ,
V_51 ) ;
if ( ! V_4 )
return;
F_20 ( V_4 , V_6 -> V_26 . V_23 ) ;
F_21 ( V_4 , 2 ) ;
switch ( V_53 ) {
case V_9 :
V_4 -> V_8 [ 0 ] = 0x00 ;
V_4 -> V_8 [ 1 ] = 0x02 ;
switch ( V_6 -> V_57 ) {
case V_58 :
F_22 ( V_4 , L_19 , L_20 ) ;
break;
case V_59 :
F_22 ( V_4 , L_19 , L_21 ) ;
break;
default:
F_3 ( L_22 , V_18 ) ;
break;
}
F_23 ( V_4 , L_23 , 0x0101 ) ;
break;
case V_11 :
V_4 -> V_8 [ 0 ] = 0x00 ;
V_4 -> V_8 [ 1 ] = 0x05 ;
F_22 ( V_4 , L_13 , L_14 ) ;
F_22 ( V_4 , L_13 , L_15 ) ;
F_22 ( V_4 , L_13 , L_16 ) ;
switch ( V_6 -> V_26 . V_28 ) {
case V_60 :
F_22 ( V_4 , L_17 , L_24 ) ;
break;
case V_29 :
F_22 ( V_4 , L_17 , L_25 ) ;
break;
case V_61 :
F_22 ( V_4 , L_17 , L_18 ) ;
break;
default:
F_3 ( L_26 , V_18 ) ;
break;
}
F_23 ( V_4 , L_27 , 0x05ee ) ;
break;
case V_13 :
V_4 -> V_8 [ 0 ] = 0x00 ;
if ( V_6 -> V_26 . V_62 ) {
V_4 -> V_8 [ 1 ] = 0x03 ;
F_23 ( V_4 , L_28 ,
V_6 -> V_26 . V_62 ) ;
} else
V_4 -> V_8 [ 1 ] = 0x02 ;
F_24 ( V_4 , L_29 , V_6 -> V_63 ) ;
F_22 ( V_4 , L_30 , L_31 ) ;
break;
case V_15 :
F_25 ( V_6 , V_4 ) ;
break;
default:
F_3 ( L_8 , V_18 ) ;
break;
}
F_26 ( V_6 -> V_26 . V_64 , V_4 ) ;
}
int F_27 ( struct V_5 * V_6 )
{
struct V_24 * V_25 ;
T_5 V_65 ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == IRLAN_MAGIC, return -1;) ;
if ( V_6 -> V_26 . V_64 )
return - 1 ;
F_28 ( & V_65 ) ;
V_65 . V_66 = F_1 ;
V_65 . V_67 = F_5 ;
V_65 . V_68 = F_9 ;
V_65 . V_1 = V_6 ;
F_29 ( V_65 . V_46 , L_32 , sizeof( V_65 . V_46 ) ) ;
V_25 = F_30 ( V_69 , 1 , & V_65 ) ;
if ( ! V_25 ) {
F_3 ( L_33 , V_18 ) ;
return - 1 ;
}
V_6 -> V_26 . V_64 = V_25 ;
F_31 ( V_6 , V_25 -> V_70 ) ;
return 0 ;
}
