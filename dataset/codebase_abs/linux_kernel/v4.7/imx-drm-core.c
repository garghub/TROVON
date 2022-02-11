unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_4 ( V_6 -> V_8 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_6 ( V_4 ) ;
if ( V_6 -> V_8 )
F_7 ( V_6 -> V_8 ) ;
F_8 ( V_4 -> V_9 , V_4 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
F_11 ( V_4 -> V_10 , NULL ) ;
return 0 ;
}
static struct V_1 * F_12 ( struct V_11 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_9 -> V_7 ;
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( V_6 -> V_2 [ V_12 ] && V_6 -> V_2 [ V_12 ] -> V_2 == V_2 )
return V_6 -> V_2 [ V_12 ] ;
return NULL ;
}
int F_13 ( struct V_14 * V_15 , T_1 V_16 ,
int V_17 , int V_18 , T_1 V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_22 ;
V_22 = F_12 ( V_15 -> V_2 ) ;
if ( ! V_22 )
return - V_23 ;
V_21 = & V_22 -> V_24 ;
if ( V_21 -> V_25 )
return V_21 -> V_25 ( V_15 -> V_2 ,
V_16 , V_17 , V_18 ,
V_19 ) ;
return 0 ;
}
int F_14 ( struct V_14 * V_15 , T_1 V_16 )
{
return F_13 ( V_15 , V_16 , 2 , 3 ,
V_26 |
V_27 ) ;
}
int F_15 ( struct V_1 * V_1 )
{
return F_16 ( V_1 -> V_2 ) ;
}
void F_17 ( struct V_1 * V_1 )
{
F_18 ( V_1 -> V_2 ) ;
}
void F_19 ( struct V_1 * V_1 )
{
F_20 ( V_1 -> V_2 ) ;
}
static int F_21 ( struct V_3 * V_4 , unsigned int V_28 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 = V_6 -> V_2 [ V_28 ] ;
int V_29 ;
if ( ! V_1 )
return - V_23 ;
if ( ! V_1 -> V_24 . V_30 )
return - V_31 ;
V_29 = V_1 -> V_24 . V_30 (
V_1 -> V_2 ) ;
return V_29 ;
}
static void F_22 ( struct V_3 * V_4 , unsigned int V_28 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 = V_6 -> V_2 [ V_28 ] ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_24 . V_32 )
return;
V_1 -> V_24 . V_32 ( V_1 -> V_2 ) ;
}
void F_23 ( struct V_33 * V_34 )
{
F_24 ( V_34 ) ;
F_25 ( V_34 ) ;
}
void F_26 ( struct V_14 * V_15 )
{
F_27 ( V_15 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_29 ( V_6 -> V_8 ) ;
}
static int F_30 ( struct V_3 * V_4 , unsigned long V_35 )
{
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_29 ;
V_6 = F_31 ( V_4 -> V_9 , sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 = V_6 ;
V_4 -> V_38 = true ;
V_4 -> V_39 . V_40 = 64 ;
V_4 -> V_39 . V_41 = 64 ;
V_4 -> V_39 . V_42 = 4096 ;
V_4 -> V_39 . V_43 = 4096 ;
V_4 -> V_39 . V_44 = & V_45 ;
F_32 ( V_4 ) ;
V_29 = F_33 ( V_4 , V_13 ) ;
if ( V_29 )
goto V_46;
F_11 ( V_4 -> V_10 , V_4 ) ;
V_29 = F_34 ( V_4 -> V_9 , V_4 ) ;
if ( V_29 )
goto V_47;
F_35 (connector, &drm->mode_config.connector_list, head) {
V_29 = F_36 ( V_34 ) ;
if ( V_29 ) {
F_37 ( V_4 -> V_9 ,
L_1 ,
V_34 -> V_48 . V_49 ,
V_34 -> V_50 , V_29 ) ;
goto V_51;
}
}
#if F_38 ( V_52 )
if ( V_53 != 16 && V_53 != 32 ) {
F_39 ( V_4 -> V_9 , L_2 ) ;
V_53 = 16 ;
}
F_40 ( V_4 ) ;
V_6 -> V_8 = F_41 ( V_4 , V_53 ,
V_4 -> V_39 . V_54 , V_13 ) ;
if ( F_42 ( V_6 -> V_8 ) ) {
V_29 = F_43 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
goto V_51;
}
#endif
F_44 ( V_4 ) ;
return 0 ;
V_51:
F_8 ( V_4 -> V_9 , V_4 ) ;
V_47:
F_9 ( V_4 ) ;
V_46:
F_10 ( V_4 ) ;
return V_29 ;
}
int F_45 ( struct V_3 * V_4 , struct V_11 * V_2 ,
struct V_1 * * V_55 , struct V_56 * V_57 ,
const struct V_20 * V_24 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 ;
if ( V_6 -> V_60 >= V_13 )
return - V_23 ;
if ( V_6 -> V_4 -> V_61 )
return - V_62 ;
V_1 = F_46 ( sizeof( * V_1 ) , V_36 ) ;
if ( ! V_1 )
return - V_37 ;
V_1 -> V_24 = * V_24 ;
V_1 -> V_2 = V_2 ;
V_2 -> V_59 = V_59 ;
V_6 -> V_2 [ V_6 -> V_60 ++ ] = V_1 ;
* V_55 = V_1 ;
F_47 ( V_2 ,
V_1 -> V_24 . V_63 ) ;
F_48 ( V_4 , V_2 , V_57 , NULL ,
V_1 -> V_24 . V_64 , NULL ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_2 -> V_9 -> V_7 ;
unsigned int V_28 = F_2 ( V_1 -> V_2 ) ;
F_50 ( V_1 -> V_2 ) ;
V_6 -> V_2 [ V_28 ] = NULL ;
F_51 ( V_1 ) ;
return 0 ;
}
int F_52 ( struct V_3 * V_4 ,
struct V_14 * V_15 , struct V_58 * V_65 )
{
T_2 V_66 = F_53 ( V_4 , V_65 ) ;
if ( V_66 == 0 )
return - V_67 ;
V_15 -> V_68 = V_66 ;
V_15 -> V_69 = ~ 0 ;
return 0 ;
}
static int F_54 ( struct V_70 * V_9 , void * V_71 )
{
struct V_58 * V_65 = V_71 ;
if ( strcmp ( V_9 -> V_72 -> V_50 , L_3 ) == 0 ) {
struct V_73 * V_74 = V_9 -> V_75 ;
return V_74 -> V_76 == V_65 ;
}
if ( F_55 ( V_65 -> V_50 , L_4 ) == 0 ) {
V_65 = F_56 ( V_65 ) ;
F_57 ( V_65 ) ;
}
return V_9 -> V_76 == V_65 ;
}
static int F_58 ( struct V_70 * V_9 )
{
return F_59 ( & V_77 , F_60 ( V_9 ) ) ;
}
static void F_61 ( struct V_70 * V_9 )
{
F_62 ( F_63 ( V_9 ) ) ;
}
static int F_64 ( struct V_78 * V_79 )
{
int V_29 = F_65 ( & V_79 -> V_9 , F_54 , & V_80 ) ;
if ( ! V_29 )
V_29 = F_66 ( & V_79 -> V_9 , F_67 ( 32 ) ) ;
return V_29 ;
}
static int F_68 ( struct V_78 * V_79 )
{
F_69 ( & V_79 -> V_9 , & V_80 ) ;
return 0 ;
}
static int F_70 ( struct V_70 * V_9 )
{
struct V_3 * V_81 = F_63 ( V_9 ) ;
if ( V_81 == NULL )
return 0 ;
F_71 ( V_81 ) ;
return 0 ;
}
static int F_72 ( struct V_70 * V_9 )
{
struct V_3 * V_81 = F_63 ( V_9 ) ;
if ( V_81 == NULL )
return 0 ;
F_73 ( V_81 ) ;
F_74 ( V_81 ) ;
return 0 ;
}
