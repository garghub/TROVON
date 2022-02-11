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
int V_17 , int V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_21 ;
V_21 = F_12 ( V_15 -> V_2 ) ;
if ( ! V_21 )
return - V_22 ;
V_20 = & V_21 -> V_23 ;
if ( V_20 -> V_24 )
return V_20 -> V_24 ( V_15 -> V_2 ,
V_16 , V_17 , V_18 ) ;
return 0 ;
}
int F_14 ( struct V_14 * V_15 , T_1 V_16 )
{
return F_13 ( V_15 , V_16 , 2 , 3 ) ;
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
static int F_21 ( struct V_3 * V_4 , unsigned int V_25 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 = V_6 -> V_2 [ V_25 ] ;
int V_26 ;
if ( ! V_1 )
return - V_22 ;
if ( ! V_1 -> V_23 . V_27 )
return - V_28 ;
V_26 = V_1 -> V_23 . V_27 (
V_1 -> V_2 ) ;
return V_26 ;
}
static void F_22 ( struct V_3 * V_4 , unsigned int V_25 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 = V_6 -> V_2 [ V_25 ] ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_23 . V_29 )
return;
V_1 -> V_23 . V_29 ( V_1 -> V_2 ) ;
}
static void F_23 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
int V_12 ;
if ( ! V_31 -> V_32 )
return;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
F_22 ( V_4 , V_12 ) ;
}
void F_24 ( struct V_33 * V_34 )
{
F_25 ( V_34 ) ;
F_26 ( V_34 ) ;
}
void F_27 ( struct V_14 * V_15 )
{
F_28 ( V_15 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_30 ( V_6 -> V_8 ) ;
}
static int F_31 ( struct V_3 * V_4 , unsigned long V_35 )
{
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_26 ;
V_6 = F_32 ( V_4 -> V_9 , sizeof( * V_6 ) , V_36 ) ;
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
F_33 ( V_4 ) ;
V_26 = F_34 ( V_4 , V_13 ) ;
if ( V_26 )
goto V_46;
V_4 -> V_47 = true ;
F_11 ( V_4 -> V_10 , V_4 ) ;
V_26 = F_35 ( V_4 -> V_9 , V_4 ) ;
if ( V_26 )
goto V_48;
F_36 (connector, &drm->mode_config.connector_list, head) {
V_26 = F_37 ( V_34 ) ;
if ( V_26 ) {
F_38 ( V_4 -> V_9 ,
L_1 ,
V_34 -> V_49 . V_50 ,
V_34 -> V_51 , V_26 ) ;
goto V_52;
}
}
#if F_39 ( V_53 )
if ( V_54 != 16 && V_54 != 32 ) {
F_40 ( V_4 -> V_9 , L_2 ) ;
V_54 = 16 ;
}
F_41 ( V_4 ) ;
V_6 -> V_8 = F_42 ( V_4 , V_54 ,
V_4 -> V_39 . V_55 , V_13 ) ;
if ( F_43 ( V_6 -> V_8 ) ) {
V_26 = F_44 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
goto V_52;
}
#endif
F_45 ( V_4 ) ;
return 0 ;
V_52:
F_8 ( V_4 -> V_9 , V_4 ) ;
V_48:
F_9 ( V_4 ) ;
V_46:
F_10 ( V_4 ) ;
return V_26 ;
}
int F_46 ( struct V_3 * V_4 , struct V_11 * V_2 ,
struct V_1 * * V_56 , struct V_57 * V_58 ,
const struct V_19 * V_23 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 ;
int V_26 ;
if ( V_6 -> V_61 >= V_13 )
return - V_22 ;
if ( V_6 -> V_4 -> V_62 )
return - V_63 ;
V_1 = F_47 ( sizeof( * V_1 ) , V_36 ) ;
if ( ! V_1 )
return - V_37 ;
V_1 -> V_23 = * V_23 ;
V_1 -> V_2 = V_2 ;
V_2 -> V_60 = V_60 ;
V_6 -> V_2 [ V_6 -> V_61 ++ ] = V_1 ;
* V_56 = V_1 ;
V_26 = F_48 ( V_1 -> V_2 , 256 ) ;
if ( V_26 )
goto V_64;
F_49 ( V_2 ,
V_1 -> V_23 . V_65 ) ;
F_50 ( V_4 , V_2 , V_58 , NULL ,
V_1 -> V_23 . V_66 , NULL ) ;
return 0 ;
V_64:
V_6 -> V_2 [ -- V_6 -> V_61 ] = NULL ;
F_51 ( V_1 ) ;
return V_26 ;
}
int F_52 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_2 -> V_9 -> V_7 ;
unsigned int V_25 = F_2 ( V_1 -> V_2 ) ;
F_53 ( V_1 -> V_2 ) ;
V_6 -> V_2 [ V_25 ] = NULL ;
F_51 ( V_1 ) ;
return 0 ;
}
int F_54 ( struct V_3 * V_4 ,
struct V_14 * V_15 , struct V_59 * V_67 )
{
T_2 V_68 = F_55 ( V_4 , V_67 ) ;
if ( V_68 == 0 )
return - V_69 ;
V_15 -> V_70 = V_68 ;
V_15 -> V_71 = ~ 0 ;
return 0 ;
}
int F_56 ( struct V_59 * V_72 ,
struct V_14 * V_15 )
{
struct V_1 * V_21 = F_12 ( V_15 -> V_2 ) ;
struct V_59 * V_73 ;
struct V_74 V_75 ;
struct V_59 * V_60 ;
int V_26 ;
if ( ! V_72 || ! V_21 )
return - V_22 ;
F_57 (node, ep) {
V_60 = F_58 ( V_73 ) ;
F_59 ( V_60 ) ;
if ( V_60 == V_21 -> V_2 -> V_60 ) {
V_26 = F_60 ( V_73 , & V_75 ) ;
F_59 ( V_73 ) ;
return V_26 ? V_26 : V_75 . V_60 ;
}
}
return - V_22 ;
}
static int F_61 ( struct V_76 * V_9 , void * V_77 )
{
struct V_59 * V_67 = V_77 ;
if ( F_62 ( V_67 -> V_51 , L_3 ) == 0 ) {
V_67 = F_63 ( V_67 ) ;
F_59 ( V_67 ) ;
}
return V_9 -> V_78 == V_67 ;
}
static int F_64 ( struct V_76 * V_9 )
{
return F_65 ( & V_79 , F_66 ( V_9 ) ) ;
}
static void F_67 ( struct V_76 * V_9 )
{
F_68 ( F_69 ( V_9 ) ) ;
}
static int F_70 ( struct V_80 * V_81 )
{
int V_26 = F_71 ( & V_81 -> V_9 , F_61 , & V_82 ) ;
if ( ! V_26 )
V_26 = F_72 ( & V_81 -> V_9 , F_73 ( 32 ) ) ;
return V_26 ;
}
static int F_74 ( struct V_80 * V_81 )
{
F_75 ( & V_81 -> V_9 , & V_82 ) ;
return 0 ;
}
static int F_76 ( struct V_76 * V_9 )
{
struct V_3 * V_83 = F_69 ( V_9 ) ;
if ( V_83 == NULL )
return 0 ;
F_77 ( V_83 ) ;
return 0 ;
}
static int F_78 ( struct V_76 * V_9 )
{
struct V_3 * V_83 = F_69 ( V_9 ) ;
if ( V_83 == NULL )
return 0 ;
F_79 ( V_83 ) ;
F_80 ( V_83 ) ;
return 0 ;
}
