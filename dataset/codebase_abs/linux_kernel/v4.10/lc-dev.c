static inline void F_1 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_3 , 0xff , sizeof( V_2 -> V_3 ) ) ;
}
static inline void F_2 ( struct V_4 * V_2 )
{
memset ( & V_2 -> V_3 , 0xff , sizeof( V_2 -> V_3 ) ) ;
}
int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
if ( F_4 ( & V_6 -> V_9 . V_10 ) )
return - V_11 ;
F_5 ( & V_8 -> V_12 , & V_6 -> V_9 . V_13 ) ;
F_6 ( & V_6 -> V_9 . V_10 ) ;
return 0 ;
}
int F_7 ( struct V_5 * V_6 , struct V_7 * V_14 )
{
if ( F_4 ( & V_6 -> V_9 . V_10 ) )
return - V_11 ;
F_8 ( & V_14 -> V_12 ) ;
F_6 ( & V_6 -> V_9 . V_10 ) ;
return 0 ;
}
void F_9 ( struct V_5 * V_6 , struct V_15 * V_15 , enum V_16 V_17 )
{
struct V_7 * V_18 ;
if ( F_4 ( & V_6 -> V_9 . V_10 ) )
return;
if ( ! F_10 ( & V_6 -> V_9 . V_13 ) ) {
F_11 (handler, &rc->notifs_chain.list, list_node) {
V_18 -> V_19 ( V_18 -> V_3 , V_15 , V_17 ) ;
}
}
F_6 ( & V_6 -> V_9 . V_10 ) ;
}
static void F_12 ( struct V_20 * V_21 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
F_14 ( V_15 -> V_22 ) ;
memset ( V_15 , 0x69 , sizeof( * V_15 ) ) ;
F_15 ( V_15 ) ;
}
void F_16 ( struct V_15 * V_15 )
{
F_17 ( & V_15 -> V_10 ) ;
F_18 ( & V_15 -> V_21 ) ;
V_15 -> V_21 . V_23 = F_12 ;
F_1 ( & V_15 -> V_24 ) ;
F_2 ( & V_15 -> V_25 ) ;
F_19 ( V_15 -> V_26 , V_27 ) ;
}
static T_1 F_20 ( struct V_20 * V_21 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
char V_2 [ V_31 ] ;
F_21 ( V_2 , sizeof( V_2 ) , & V_15 -> V_25 ) ;
return sprintf ( V_30 , L_1 , V_2 ) ;
}
static T_1 F_22 ( struct V_20 * V_21 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
char V_2 [ V_31 ] ;
F_23 ( V_2 , sizeof( V_2 ) , & V_15 -> V_24 ) ;
return sprintf ( V_30 , L_1 , V_2 ) ;
}
static T_1 F_24 ( struct V_20 * V_21 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
struct V_32 * V_22 ;
struct V_33 * V_34 ;
T_2 V_35 ;
V_22 = V_15 -> V_22 ;
F_25 ( & V_22 -> V_10 ) ;
V_34 = (struct V_33 * ) V_22 -> V_36 -> V_37 ;
V_35 = V_22 -> V_36 -> V_38
- ( T_2 ) ( V_34 -> V_39 * V_40 ) ;
F_6 ( & V_22 -> V_10 ) ;
return sprintf ( V_30 , L_2 , V_35 ) ;
}
static T_1 F_26 ( struct V_20 * V_21 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
return F_27 ( V_15 , V_15 -> V_22 , V_30 , V_41 ) ;
}
static T_1 F_28 ( struct V_20 * V_21 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
struct V_32 * V_22 = V_15 -> V_22 ;
T_3 V_42 ;
F_25 ( & V_22 -> V_10 ) ;
V_42 = F_29 ( & V_15 -> V_22 -> V_43 , V_30 ) ;
F_6 ( & V_22 -> V_10 ) ;
return V_42 ;
}
static T_1 F_30 ( struct V_20 * V_21 ,
struct V_28 * V_29 ,
const char * V_30 , T_3 V_44 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
struct V_32 * V_22 = V_15 -> V_22 ;
T_1 V_42 ;
F_25 ( & V_22 -> V_10 ) ;
V_42 = F_31 ( & V_15 -> V_22 -> V_43 , V_30 , V_44 ) ;
F_6 ( & V_22 -> V_10 ) ;
return V_42 ;
}
static T_1 F_32 ( struct V_20 * V_21 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
struct V_32 * V_22 = V_15 -> V_22 ;
T_3 V_42 ;
F_25 ( & V_22 -> V_10 ) ;
V_42 = F_29 ( & V_15 -> V_22 -> V_45 , V_30 ) ;
F_6 ( & V_22 -> V_10 ) ;
return V_42 ;
}
static T_1 F_33 ( struct V_20 * V_21 ,
struct V_28 * V_29 ,
const char * V_30 , T_3 V_44 )
{
struct V_15 * V_15 = F_13 ( V_21 ) ;
struct V_32 * V_22 = V_15 -> V_22 ;
T_1 V_42 ;
F_25 ( & V_22 -> V_10 ) ;
V_42 = F_31 ( & V_15 -> V_22 -> V_45 , V_30 , V_44 ) ;
F_6 ( & V_22 -> V_10 ) ;
return V_42 ;
}
static int F_34 ( struct V_15 * V_15 , struct V_20 * V_46 )
{
struct V_20 * V_21 ;
V_21 = & V_15 -> V_21 ;
V_21 -> V_47 = V_46 ;
F_35 ( V_21 , V_15 ) ;
return F_36 ( V_21 ) ;
}
static void F_37 ( struct V_15 * V_15 )
{
F_35 ( & V_15 -> V_21 , NULL ) ;
F_38 ( & V_15 -> V_21 ) ;
}
int F_39 ( struct V_15 * V_15 , struct V_20 * V_46 ,
struct V_5 * V_48 )
{
int V_42 ;
struct V_20 * V_21 ;
F_40 ( V_15 == NULL ) ;
F_40 ( V_46 == NULL ) ;
F_40 ( V_48 == NULL ) ;
F_25 ( & V_15 -> V_10 ) ;
V_21 = & V_15 -> V_21 ;
V_15 -> V_6 = V_48 ;
V_42 = F_34 ( V_15 , V_46 ) ;
if ( V_42 < 0 )
F_41 ( V_49 L_3 ,
F_42 ( V_21 ) , V_42 ) ;
F_6 ( & V_15 -> V_10 ) ;
return V_42 ;
}
void F_43 ( struct V_15 * V_15 )
{
F_25 ( & V_15 -> V_10 ) ;
F_37 ( V_15 ) ;
F_6 ( & V_15 -> V_10 ) ;
}
static
int F_44 ( struct V_20 * V_21 , void * V_50 )
{
struct V_15 * V_51 = V_50 ;
struct V_15 * V_15 = F_13 ( V_21 ) ;
if ( V_15 == V_51 ) {
F_45 ( V_15 ) ;
return 1 ;
} else
return 0 ;
}
struct V_15 * F_46 ( struct V_5 * V_6 , struct V_15 * V_15 )
{
if ( F_47 ( V_6 , F_44 , V_15 ) )
return V_15 ;
else
return NULL ;
}
int F_48 ( struct V_15 * V_15 , struct V_5 * V_6 )
{
struct V_20 * V_21 = & V_15 -> V_21 ;
char V_52 [ V_31 ] , V_53 [ V_31 ] ;
F_21 ( V_52 , sizeof( V_52 ) , & V_15 -> V_25 ) ;
F_23 ( V_53 , sizeof( V_53 ) , & V_15 -> V_24 ) ;
F_49 ( V_21 , L_4 ,
V_52 , V_53 ,
V_15 -> V_21 . V_54 -> V_55 ,
V_6 ? F_42 ( & ( V_6 -> V_15 . V_21 ) ) : L_5 ) ;
F_43 ( V_15 ) ;
F_8 ( & V_15 -> V_22 -> V_56 ) ;
F_14 ( V_15 -> V_22 ) ;
F_50 ( V_15 ) ;
return 0 ;
}
void F_51 ( struct V_32 * V_22 )
{
struct V_15 * V_15 ;
V_15 = V_22 -> V_15 ;
if ( V_15 ) {
F_9 ( V_15 -> V_6 , V_15 , V_57 ) ;
F_48 ( V_15 , V_15 -> V_6 ) ;
}
}
void F_52 ( struct V_5 * V_6 , struct V_32 * V_22 )
{
int V_42 ;
struct V_20 * V_21 = & V_6 -> V_15 . V_21 ;
struct V_15 * V_15 ;
char V_52 [ V_31 ] , V_53 [ V_31 ] ;
F_21 ( V_52 , sizeof( V_52 ) , V_22 -> V_25 ) ;
F_23 ( V_53 , sizeof( V_53 ) , & V_22 -> V_24 ) ;
V_15 = F_53 ( sizeof( struct V_15 ) , V_58 ) ;
if ( V_15 == NULL ) {
F_54 ( V_21 , L_6 ,
V_52 ) ;
return;
}
F_16 ( V_15 ) ;
V_15 -> V_21 . V_54 = & V_59 ;
V_15 -> V_25 = * V_22 -> V_25 ;
V_15 -> V_24 = V_22 -> V_24 ;
F_55 ( & V_15 -> V_21 , L_7 , V_52 ) ;
V_22 -> V_15 = V_15 ;
V_15 -> V_22 = V_22 ;
F_56 ( V_22 ) ;
V_42 = F_39 ( V_15 , & V_6 -> V_15 . V_21 , V_6 ) ;
if ( V_42 < 0 ) {
F_54 ( V_21 , L_8 ,
V_52 ) ;
goto V_60;
}
F_49 ( V_21 , L_9 ,
V_52 , V_53 , V_15 -> V_21 . V_54 -> V_55 ,
F_42 ( & ( V_6 -> V_15 . V_21 ) ) ) ;
F_9 ( V_6 , V_15 , V_61 ) ;
return;
V_60:
V_22 -> V_15 = NULL ;
F_14 ( V_22 ) ;
F_15 ( V_15 ) ;
return;
}
int F_47 ( struct V_5 * V_6 , T_4 V_62 , void * V_63 )
{
return F_57 ( & V_6 -> V_15 . V_21 , V_63 , V_62 ) ;
}
