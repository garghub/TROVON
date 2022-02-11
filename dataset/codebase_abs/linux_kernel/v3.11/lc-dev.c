static inline void F_1 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_3 , 0xff , sizeof( V_2 -> V_3 ) ) ;
}
static inline void F_2 ( struct V_4 * V_2 )
{
memset ( & V_2 -> V_3 , 0xff , sizeof( V_2 -> V_3 ) ) ;
}
static inline int F_3 ( const struct V_1 * V_2 )
{
static const struct V_1 V_5 = { . V_3 = { 0xff , 0xff } } ;
return ! F_4 ( V_2 , & V_5 ) ;
}
int F_5 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( F_6 ( & V_7 -> V_10 . V_11 ) )
return - V_12 ;
F_7 ( & V_9 -> V_13 , & V_7 -> V_10 . V_14 ) ;
F_8 ( & V_7 -> V_10 . V_11 ) ;
return 0 ;
}
int F_9 ( struct V_6 * V_7 , struct V_8 * V_15 )
{
if ( F_6 ( & V_7 -> V_10 . V_11 ) )
return - V_12 ;
F_10 ( & V_15 -> V_13 ) ;
F_8 ( & V_7 -> V_10 . V_11 ) ;
return 0 ;
}
void F_11 ( struct V_6 * V_7 , struct V_16 * V_16 , enum V_17 V_18 )
{
struct V_8 * V_19 ;
if ( F_6 ( & V_7 -> V_10 . V_11 ) )
return;
if ( ! F_12 ( & V_7 -> V_10 . V_14 ) ) {
F_13 (handler, &rc->notifs_chain.list, list_node) {
V_19 -> V_20 ( V_19 -> V_3 , V_16 , V_18 ) ;
}
}
F_8 ( & V_7 -> V_10 . V_11 ) ;
}
static void F_14 ( struct V_21 * V_22 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
F_16 ( V_16 -> V_23 ) ;
memset ( V_16 , 0x69 , sizeof( * V_16 ) ) ;
F_17 ( V_16 ) ;
}
void F_18 ( struct V_16 * V_16 )
{
F_19 ( & V_16 -> V_11 ) ;
F_20 ( & V_16 -> V_22 ) ;
V_16 -> V_22 . V_24 = F_14 ;
F_1 ( & V_16 -> V_25 ) ;
F_2 ( & V_16 -> V_26 ) ;
F_21 ( V_16 -> V_27 , V_28 ) ;
}
static T_1 F_22 ( struct V_21 * V_22 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
char V_2 [ V_32 ] ;
F_23 ( V_2 , sizeof( V_2 ) , & V_16 -> V_26 ) ;
return sprintf ( V_31 , L_1 , V_2 ) ;
}
static T_1 F_24 ( struct V_21 * V_22 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
char V_2 [ V_32 ] ;
F_25 ( V_2 , sizeof( V_2 ) , & V_16 -> V_25 ) ;
return sprintf ( V_31 , L_1 , V_2 ) ;
}
static T_1 F_26 ( struct V_21 * V_22 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
struct V_33 * V_23 ;
struct V_34 * V_35 ;
T_2 V_36 ;
V_23 = V_16 -> V_23 ;
F_27 ( & V_23 -> V_11 ) ;
V_35 = (struct V_34 * ) V_23 -> V_37 -> V_38 ;
V_36 = V_23 -> V_37 -> V_39
- ( T_2 ) ( V_35 -> V_40 * V_41 ) ;
F_8 ( & V_23 -> V_11 ) ;
return sprintf ( V_31 , L_2 , V_36 ) ;
}
static T_1 F_28 ( struct V_21 * V_22 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
return F_29 ( V_16 , V_16 -> V_23 , V_31 , V_42 ) ;
}
static T_1 F_30 ( struct V_21 * V_22 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
struct V_33 * V_23 = V_16 -> V_23 ;
T_3 V_43 ;
F_27 ( & V_23 -> V_11 ) ;
V_43 = F_31 ( & V_16 -> V_23 -> V_44 , V_31 ) ;
F_8 ( & V_23 -> V_11 ) ;
return V_43 ;
}
static T_1 F_32 ( struct V_21 * V_22 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_45 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
struct V_33 * V_23 = V_16 -> V_23 ;
T_1 V_43 ;
F_27 ( & V_23 -> V_11 ) ;
V_43 = F_33 ( & V_16 -> V_23 -> V_44 , V_31 , V_45 ) ;
F_8 ( & V_23 -> V_11 ) ;
return V_43 ;
}
static T_1 F_34 ( struct V_21 * V_22 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
struct V_33 * V_23 = V_16 -> V_23 ;
T_3 V_43 ;
F_27 ( & V_23 -> V_11 ) ;
V_43 = F_31 ( & V_16 -> V_23 -> V_46 , V_31 ) ;
F_8 ( & V_23 -> V_11 ) ;
return V_43 ;
}
static T_1 F_35 ( struct V_21 * V_22 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_45 )
{
struct V_16 * V_16 = F_15 ( V_22 ) ;
struct V_33 * V_23 = V_16 -> V_23 ;
T_1 V_43 ;
F_27 ( & V_23 -> V_11 ) ;
V_43 = F_33 ( & V_16 -> V_23 -> V_46 , V_31 , V_45 ) ;
F_8 ( & V_23 -> V_11 ) ;
return V_43 ;
}
static int F_36 ( struct V_16 * V_16 , struct V_21 * V_47 )
{
struct V_21 * V_22 ;
V_22 = & V_16 -> V_22 ;
if ( & V_16 -> V_7 -> V_16 != V_16 )
V_22 -> V_48 = V_48 ;
V_22 -> V_49 = V_47 ;
F_37 ( V_22 , V_16 ) ;
return F_38 ( V_22 ) ;
}
static void F_39 ( struct V_16 * V_16 )
{
F_37 ( & V_16 -> V_22 , NULL ) ;
F_40 ( & V_16 -> V_22 ) ;
}
int F_41 ( struct V_16 * V_16 , struct V_21 * V_47 ,
struct V_6 * V_50 )
{
int V_43 ;
struct V_21 * V_22 ;
F_42 ( V_16 == NULL ) ;
F_42 ( V_47 == NULL ) ;
F_42 ( V_50 == NULL ) ;
F_27 ( & V_16 -> V_11 ) ;
V_22 = & V_16 -> V_22 ;
V_16 -> V_7 = V_50 ;
V_43 = F_36 ( V_16 , V_47 ) ;
if ( V_43 < 0 )
F_43 ( V_51 L_3 ,
F_44 ( V_22 ) , V_43 ) ;
F_8 ( & V_16 -> V_11 ) ;
return V_43 ;
}
void F_45 ( struct V_16 * V_16 )
{
F_27 ( & V_16 -> V_11 ) ;
F_39 ( V_16 ) ;
F_8 ( & V_16 -> V_11 ) ;
}
static
int F_46 ( struct V_21 * V_22 , void * V_52 )
{
struct V_16 * V_53 = V_52 ;
struct V_16 * V_16 = F_15 ( V_22 ) ;
if ( V_16 == V_53 ) {
F_47 ( V_16 ) ;
return 1 ;
} else
return 0 ;
}
struct V_16 * F_48 ( struct V_6 * V_7 , struct V_16 * V_16 )
{
if ( F_49 ( V_7 , F_46 , V_16 ) )
return V_16 ;
else
return NULL ;
}
int F_50 ( struct V_16 * V_16 , struct V_6 * V_7 )
{
struct V_21 * V_22 = & V_16 -> V_22 ;
char V_54 [ V_32 ] , V_55 [ V_32 ] ;
F_23 ( V_54 , sizeof( V_54 ) , & V_16 -> V_26 ) ;
F_25 ( V_55 , sizeof( V_55 ) , & V_16 -> V_25 ) ;
F_51 ( V_22 , L_4 ,
V_54 , V_55 ,
V_7 ? V_7 -> V_16 . V_22 . V_49 -> V_56 -> V_57 : L_5 ,
V_7 ? F_44 ( V_7 -> V_16 . V_22 . V_49 ) : L_6 ) ;
F_45 ( V_16 ) ;
F_10 ( & V_16 -> V_23 -> V_58 ) ;
F_16 ( V_16 -> V_23 ) ;
F_52 ( V_16 ) ;
return 0 ;
}
void F_53 ( struct V_33 * V_23 )
{
struct V_16 * V_16 ;
V_16 = V_23 -> V_16 ;
if ( V_16 ) {
F_11 ( V_16 -> V_7 , V_16 , V_59 ) ;
F_50 ( V_16 , V_16 -> V_7 ) ;
}
}
void F_54 ( struct V_6 * V_7 , struct V_33 * V_23 )
{
int V_43 ;
struct V_21 * V_22 = & V_7 -> V_16 . V_22 ;
struct V_16 * V_16 ;
char V_54 [ V_32 ] , V_55 [ V_32 ] ;
F_23 ( V_54 , sizeof( V_54 ) , V_23 -> V_26 ) ;
F_25 ( V_55 , sizeof( V_55 ) , & V_23 -> V_25 ) ;
V_16 = F_55 ( sizeof( struct V_16 ) , V_60 ) ;
if ( V_16 == NULL ) {
F_56 ( V_22 , L_7 ,
V_54 ) ;
return;
}
F_18 ( V_16 ) ;
V_16 -> V_26 = * V_23 -> V_26 ;
V_16 -> V_25 = V_23 -> V_25 ;
F_57 ( & V_16 -> V_22 , L_8 , V_54 ) ;
V_43 = F_41 ( V_16 , & V_7 -> V_16 . V_22 , V_7 ) ;
if ( V_43 < 0 ) {
F_56 ( V_22 , L_9 ,
V_54 ) ;
goto V_61;
}
V_23 -> V_16 = V_16 ;
V_16 -> V_23 = V_23 ;
F_58 ( V_23 ) ;
F_51 ( V_22 , L_10 ,
V_54 , V_55 , V_7 -> V_16 . V_22 . V_49 -> V_56 -> V_57 ,
F_44 ( V_7 -> V_16 . V_22 . V_49 ) ) ;
F_11 ( V_7 , V_16 , V_62 ) ;
return;
V_61:
F_17 ( V_16 ) ;
return;
}
int F_49 ( struct V_6 * V_7 , T_4 V_63 , void * V_64 )
{
return F_59 ( & V_7 -> V_16 . V_22 , V_64 , V_63 ) ;
}
