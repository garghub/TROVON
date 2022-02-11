static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 , V_6 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_5 , F_1 ) ;
}
static struct V_3 *
F_6 ( struct V_7 * V_8 , T_1 type , T_1 V_9 )
{
struct V_3 * V_10 , * V_4 = NULL ;
F_7 () ;
F_8 (tvlv_handler_tmp,
&bat_priv->tvlv.handler_list, list) {
if ( V_10 -> type != type )
continue;
if ( V_10 -> V_9 != V_9 )
continue;
if ( ! F_9 ( & V_10 -> V_5 ) )
continue;
V_4 = V_10 ;
break;
}
F_10 () ;
return V_4 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_2 ( V_2 , struct V_11 , V_5 ) ;
F_12 ( V_12 ) ;
}
static void F_13 ( struct V_11 * V_12 )
{
F_5 ( & V_12 -> V_5 , F_11 ) ;
}
static struct V_11 *
F_14 ( struct V_7 * V_8 , T_1 type , T_1 V_9 )
{
struct V_11 * V_13 , * V_12 = NULL ;
F_15 ( & V_8 -> V_12 . V_14 ) ;
F_16 (tvlv_tmp, &bat_priv->tvlv.container_list, list) {
if ( V_13 -> V_15 . type != type )
continue;
if ( V_13 -> V_15 . V_9 != V_9 )
continue;
F_17 ( & V_13 -> V_5 ) ;
V_12 = V_13 ;
break;
}
return V_12 ;
}
static T_2 F_18 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
T_2 V_16 = 0 ;
F_15 ( & V_8 -> V_12 . V_14 ) ;
F_16 (tvlv, &bat_priv->tvlv.container_list, list) {
V_16 += sizeof( struct V_17 ) ;
V_16 += F_19 ( V_12 -> V_15 . V_18 ) ;
}
return V_16 ;
}
static void F_20 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
F_15 ( & V_8 -> V_12 . V_14 ) ;
if ( ! V_12 )
return;
F_21 ( & V_12 -> V_19 ) ;
F_13 ( V_12 ) ;
F_13 ( V_12 ) ;
}
void F_22 ( struct V_7 * V_8 ,
T_1 type , T_1 V_9 )
{
struct V_11 * V_12 ;
F_23 ( & V_8 -> V_12 . V_14 ) ;
V_12 = F_14 ( V_8 , type , V_9 ) ;
F_20 ( V_8 , V_12 ) ;
F_24 ( & V_8 -> V_12 . V_14 ) ;
}
void F_25 ( struct V_7 * V_8 ,
T_1 type , T_1 V_9 ,
void * V_20 , T_2 V_21 )
{
struct V_11 * V_22 , * V_23 ;
if ( ! V_20 )
V_21 = 0 ;
V_23 = F_26 ( sizeof( * V_23 ) + V_21 , V_24 ) ;
if ( ! V_23 )
return;
V_23 -> V_15 . V_9 = V_9 ;
V_23 -> V_15 . type = type ;
V_23 -> V_15 . V_18 = F_27 ( V_21 ) ;
memcpy ( V_23 + 1 , V_20 , F_19 ( V_23 -> V_15 . V_18 ) ) ;
F_28 ( & V_23 -> V_19 ) ;
F_29 ( & V_23 -> V_5 ) ;
F_23 ( & V_8 -> V_12 . V_14 ) ;
V_22 = F_14 ( V_8 , type , V_9 ) ;
F_20 ( V_8 , V_22 ) ;
F_17 ( & V_23 -> V_5 ) ;
F_30 ( & V_23 -> V_19 , & V_8 -> V_12 . V_25 ) ;
F_24 ( & V_8 -> V_12 . V_14 ) ;
F_13 ( V_23 ) ;
}
static bool F_31 ( unsigned char * * V_26 ,
int * V_27 ,
int V_28 ,
int V_29 )
{
unsigned char * V_30 ;
V_30 = F_32 ( V_28 + V_29 , V_24 ) ;
if ( ! V_30 )
return false ;
memcpy ( V_30 , * V_26 , V_28 ) ;
F_12 ( * V_26 ) ;
* V_26 = V_30 ;
* V_27 = V_28 + V_29 ;
return true ;
}
T_2 F_33 ( struct V_7 * V_8 ,
unsigned char * * V_26 ,
int * V_27 , int V_31 )
{
struct V_11 * V_12 ;
struct V_17 * V_15 ;
T_2 V_21 ;
void * V_20 ;
bool V_32 ;
F_23 ( & V_8 -> V_12 . V_14 ) ;
V_21 = F_18 ( V_8 ) ;
V_32 = F_31 ( V_26 , V_27 ,
V_31 , V_21 ) ;
if ( ! V_32 )
goto V_33;
if ( ! V_21 )
goto V_33;
V_20 = ( * V_26 ) + V_31 ;
F_16 (tvlv, &bat_priv->tvlv.container_list, list) {
V_15 = V_20 ;
V_15 -> type = V_12 -> V_15 . type ;
V_15 -> V_9 = V_12 -> V_15 . V_9 ;
V_15 -> V_18 = V_12 -> V_15 . V_18 ;
V_20 = V_15 + 1 ;
memcpy ( V_20 , V_12 + 1 , F_19 ( V_12 -> V_15 . V_18 ) ) ;
V_20 = ( T_1 * ) V_20 + F_19 ( V_12 -> V_15 . V_18 ) ;
}
V_33:
F_24 ( & V_8 -> V_12 . V_14 ) ;
return V_21 ;
}
static int F_34 ( struct V_7 * V_8 ,
struct V_3 * V_4 ,
bool V_34 ,
struct V_35 * V_36 ,
T_1 * V_37 , T_1 * V_38 ,
void * V_20 , T_2 V_21 )
{
if ( ! V_4 )
return V_39 ;
if ( V_34 ) {
if ( ! V_4 -> V_40 )
return V_39 ;
if ( ! V_36 )
return V_39 ;
V_4 -> V_40 ( V_8 , V_36 ,
V_41 ,
V_20 , V_21 ) ;
V_4 -> V_42 |= V_43 ;
} else {
if ( ! V_37 )
return V_39 ;
if ( ! V_38 )
return V_39 ;
if ( ! V_4 -> V_44 )
return V_39 ;
return V_4 -> V_44 ( V_8 , V_37 ,
V_38 , V_20 ,
V_21 ) ;
}
return V_39 ;
}
int F_35 ( struct V_7 * V_8 ,
bool V_34 ,
struct V_35 * V_36 ,
T_1 * V_37 , T_1 * V_38 ,
void * V_20 , T_2 V_21 )
{
struct V_3 * V_4 ;
struct V_17 * V_15 ;
T_2 V_45 ;
T_1 V_46 = V_47 ;
int V_32 = V_39 ;
while ( V_21 >= sizeof( * V_15 ) ) {
V_15 = V_20 ;
V_45 = F_19 ( V_15 -> V_18 ) ;
V_20 = V_15 + 1 ;
V_21 -= sizeof( * V_15 ) ;
if ( V_45 > V_21 )
break;
V_4 = F_6 ( V_8 ,
V_15 -> type ,
V_15 -> V_9 ) ;
V_32 |= F_34 ( V_8 , V_4 ,
V_34 , V_36 ,
V_37 , V_38 , V_20 ,
V_45 ) ;
if ( V_4 )
F_4 ( V_4 ) ;
V_20 = ( T_1 * ) V_20 + V_45 ;
V_21 -= V_45 ;
}
if ( ! V_34 )
return V_32 ;
F_7 () ;
F_8 (tvlv_handler,
&bat_priv->tvlv.handler_list, list) {
if ( ( V_4 -> V_42 & V_47 ) &&
! ( V_4 -> V_42 & V_43 ) )
V_4 -> V_40 ( V_8 , V_36 ,
V_46 , NULL , 0 ) ;
V_4 -> V_42 &= ~ V_43 ;
}
F_10 () ;
return V_39 ;
}
void F_36 ( struct V_7 * V_8 ,
struct V_48 * V_48 ,
struct V_35 * V_36 )
{
void * V_20 ;
T_2 V_21 ;
if ( ! V_48 )
return;
V_21 = F_19 ( V_48 -> V_16 ) ;
if ( ! V_21 )
return;
V_20 = V_48 + 1 ;
F_35 ( V_8 , true , V_36 , NULL , NULL ,
V_20 , V_21 ) ;
}
void F_37 ( struct V_7 * V_8 ,
void (* F_38)( struct V_7 * V_8 ,
struct V_35 * V_49 ,
T_1 V_42 ,
void * V_20 ,
T_2 V_21 ) ,
int (* F_39)( struct V_7 * V_8 ,
T_1 * V_37 , T_1 * V_38 ,
void * V_20 ,
T_2 V_21 ) ,
T_1 type , T_1 V_9 , T_1 V_42 )
{
struct V_3 * V_4 ;
V_4 = F_6 ( V_8 , type , V_9 ) ;
if ( V_4 ) {
F_4 ( V_4 ) ;
return;
}
V_4 = F_26 ( sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return;
V_4 -> V_40 = F_38 ;
V_4 -> V_44 = F_39 ;
V_4 -> type = type ;
V_4 -> V_9 = V_9 ;
V_4 -> V_42 = V_42 ;
F_29 ( & V_4 -> V_5 ) ;
F_28 ( & V_4 -> V_19 ) ;
F_23 ( & V_8 -> V_12 . V_50 ) ;
F_17 ( & V_4 -> V_5 ) ;
F_40 ( & V_4 -> V_19 , & V_8 -> V_12 . V_51 ) ;
F_24 ( & V_8 -> V_12 . V_50 ) ;
F_4 ( V_4 ) ;
}
void F_41 ( struct V_7 * V_8 ,
T_1 type , T_1 V_9 )
{
struct V_3 * V_4 ;
V_4 = F_6 ( V_8 , type , V_9 ) ;
if ( ! V_4 )
return;
F_4 ( V_4 ) ;
F_23 ( & V_8 -> V_12 . V_50 ) ;
F_42 ( & V_4 -> V_19 ) ;
F_24 ( & V_8 -> V_12 . V_50 ) ;
F_4 ( V_4 ) ;
}
void F_43 ( struct V_7 * V_8 , T_1 * V_37 ,
T_1 * V_38 , T_1 type , T_1 V_9 ,
void * V_20 , T_2 V_21 )
{
struct V_52 * V_53 ;
struct V_17 * V_15 ;
struct V_35 * V_36 ;
struct V_54 * V_55 ;
unsigned char * V_56 ;
unsigned int V_16 ;
T_3 V_57 = sizeof( * V_53 ) ;
V_36 = F_44 ( V_8 , V_38 ) ;
if ( ! V_36 )
return;
V_16 = sizeof( * V_15 ) + V_21 ;
V_55 = F_45 ( NULL , V_58 + V_57 + V_16 ) ;
if ( ! V_55 )
goto V_59;
V_55 -> V_60 = V_61 ;
F_46 ( V_55 , V_58 ) ;
V_56 = F_47 ( V_55 , sizeof( * V_53 ) + V_16 ) ;
V_53 = (struct V_52 * ) V_56 ;
V_53 -> V_62 = V_63 ;
V_53 -> V_9 = V_64 ;
V_53 -> V_65 = V_66 ;
V_53 -> V_67 = 0 ;
V_53 -> V_16 = F_27 ( V_16 ) ;
V_53 -> V_68 = 0 ;
F_48 ( V_53 -> V_37 , V_37 ) ;
F_48 ( V_53 -> V_38 , V_38 ) ;
V_56 = ( unsigned char * ) ( V_53 + 1 ) ;
V_15 = (struct V_17 * ) V_56 ;
V_15 -> V_9 = V_9 ;
V_15 -> type = type ;
V_15 -> V_18 = F_27 ( V_21 ) ;
V_56 += sizeof( * V_15 ) ;
memcpy ( V_56 , V_20 , V_21 ) ;
F_49 ( V_55 , V_36 , NULL ) ;
V_59:
F_50 ( V_36 ) ;
}
