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
void F_23 ( struct V_30 * V_31 )
{
F_24 ( V_31 ) ;
F_25 ( V_31 ) ;
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
static int F_30 ( struct V_3 * V_4 , unsigned long V_32 )
{
struct V_5 * V_6 ;
struct V_30 * V_31 ;
int V_26 ;
V_6 = F_31 ( V_4 -> V_9 , sizeof( * V_6 ) , V_33 ) ;
if ( ! V_6 )
return - V_34 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 = V_6 ;
V_4 -> V_35 = true ;
V_4 -> V_36 . V_37 = 64 ;
V_4 -> V_36 . V_38 = 64 ;
V_4 -> V_36 . V_39 = 4096 ;
V_4 -> V_36 . V_40 = 4096 ;
V_4 -> V_36 . V_41 = & V_42 ;
F_32 ( V_4 ) ;
V_26 = F_33 ( V_4 , V_13 ) ;
if ( V_26 )
goto V_43;
V_4 -> V_44 = true ;
F_11 ( V_4 -> V_10 , V_4 ) ;
V_26 = F_34 ( V_4 -> V_9 , V_4 ) ;
if ( V_26 )
goto V_45;
F_35 (connector, &drm->mode_config.connector_list, head) {
V_26 = F_36 ( V_31 ) ;
if ( V_26 ) {
F_37 ( V_4 -> V_9 ,
L_1 ,
V_31 -> V_46 . V_47 ,
V_31 -> V_48 , V_26 ) ;
goto V_49;
}
}
#if F_38 ( V_50 )
if ( V_51 != 16 && V_51 != 32 ) {
F_39 ( V_4 -> V_9 , L_2 ) ;
V_51 = 16 ;
}
F_40 ( V_4 ) ;
V_6 -> V_8 = F_41 ( V_4 , V_51 ,
V_4 -> V_36 . V_52 , V_13 ) ;
if ( F_42 ( V_6 -> V_8 ) ) {
V_26 = F_43 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
goto V_49;
}
#endif
F_44 ( V_4 ) ;
return 0 ;
V_49:
F_8 ( V_4 -> V_9 , V_4 ) ;
V_45:
F_9 ( V_4 ) ;
V_43:
F_10 ( V_4 ) ;
return V_26 ;
}
int F_45 ( struct V_3 * V_4 , struct V_11 * V_2 ,
struct V_1 * * V_53 , struct V_54 * V_55 ,
const struct V_19 * V_23 ,
struct V_56 * V_57 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 ;
if ( V_6 -> V_58 >= V_13 )
return - V_22 ;
if ( V_6 -> V_4 -> V_59 )
return - V_60 ;
V_1 = F_46 ( sizeof( * V_1 ) , V_33 ) ;
if ( ! V_1 )
return - V_34 ;
V_1 -> V_23 = * V_23 ;
V_1 -> V_2 = V_2 ;
V_2 -> V_57 = V_57 ;
V_6 -> V_2 [ V_6 -> V_58 ++ ] = V_1 ;
* V_53 = V_1 ;
F_47 ( V_2 ,
V_1 -> V_23 . V_61 ) ;
F_48 ( V_4 , V_2 , V_55 , NULL ,
V_1 -> V_23 . V_62 , NULL ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_2 -> V_9 -> V_7 ;
unsigned int V_25 = F_2 ( V_1 -> V_2 ) ;
F_50 ( V_1 -> V_2 ) ;
V_6 -> V_2 [ V_25 ] = NULL ;
F_51 ( V_1 ) ;
return 0 ;
}
int F_52 ( struct V_3 * V_4 ,
struct V_14 * V_15 , struct V_56 * V_63 )
{
T_2 V_64 = F_53 ( V_4 , V_63 ) ;
if ( V_64 == 0 )
return - V_65 ;
V_15 -> V_66 = V_64 ;
V_15 -> V_67 = ~ 0 ;
return 0 ;
}
static int F_54 ( struct V_68 * V_9 , void * V_69 )
{
struct V_56 * V_63 = V_69 ;
if ( F_55 ( V_63 -> V_48 , L_3 ) == 0 ) {
V_63 = F_56 ( V_63 ) ;
F_57 ( V_63 ) ;
}
return V_9 -> V_70 == V_63 ;
}
static int F_58 ( struct V_68 * V_9 )
{
return F_59 ( & V_71 , F_60 ( V_9 ) ) ;
}
static void F_61 ( struct V_68 * V_9 )
{
F_62 ( F_63 ( V_9 ) ) ;
}
static int F_64 ( struct V_72 * V_73 )
{
int V_26 = F_65 ( & V_73 -> V_9 , F_54 , & V_74 ) ;
if ( ! V_26 )
V_26 = F_66 ( & V_73 -> V_9 , F_67 ( 32 ) ) ;
return V_26 ;
}
static int F_68 ( struct V_72 * V_73 )
{
F_69 ( & V_73 -> V_9 , & V_74 ) ;
return 0 ;
}
static int F_70 ( struct V_68 * V_9 )
{
struct V_3 * V_75 = F_63 ( V_9 ) ;
if ( V_75 == NULL )
return 0 ;
F_71 ( V_75 ) ;
return 0 ;
}
static int F_72 ( struct V_68 * V_9 )
{
struct V_3 * V_75 = F_63 ( V_9 ) ;
if ( V_75 == NULL )
return 0 ;
F_73 ( V_75 ) ;
F_74 ( V_75 ) ;
return 0 ;
}
