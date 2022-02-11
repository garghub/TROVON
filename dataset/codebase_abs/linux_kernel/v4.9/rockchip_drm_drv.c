int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 . V_6 ;
int V_8 ;
if ( ! V_9 )
return 0 ;
V_8 = F_2 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
return V_8 ;
F_4 ( V_4 , F_3 ( 32 ) ) ;
return F_5 ( V_4 , V_6 ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_9 )
return;
F_7 ( V_4 ) ;
}
int F_8 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
int V_14 = F_9 ( V_11 ) ;
struct V_15 * V_16 = V_11 -> V_4 -> V_17 ;
if ( V_14 >= V_18 )
return - V_19 ;
V_16 -> V_13 [ V_14 ] = V_13 ;
return 0 ;
}
void F_10 ( struct V_10 * V_11 )
{
int V_14 = F_9 ( V_11 ) ;
struct V_15 * V_16 = V_11 -> V_4 -> V_17 ;
if ( V_14 >= V_18 )
return;
V_16 -> V_13 [ V_14 ] = NULL ;
}
static struct V_10 * F_11 ( struct V_1 * V_20 ,
int V_14 )
{
struct V_10 * V_11 ;
int V_21 = 0 ;
F_12 (crtc, &drm->mode_config.crtc_list, head)
if ( V_21 ++ == V_14 )
return V_11 ;
return NULL ;
}
static int F_13 ( struct V_1 * V_4 ,
unsigned int V_14 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
struct V_10 * V_11 = F_11 ( V_4 , V_14 ) ;
if ( V_11 && V_16 -> V_13 [ V_14 ] &&
V_16 -> V_13 [ V_14 ] -> V_22 )
return V_16 -> V_13 [ V_14 ] -> V_22 ( V_11 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_4 ,
unsigned int V_14 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
struct V_10 * V_11 = F_11 ( V_4 , V_14 ) ;
if ( V_11 && V_16 -> V_13 [ V_14 ] &&
V_16 -> V_13 [ V_14 ] -> V_22 )
V_16 -> V_13 [ V_14 ] -> F_15 ( V_11 ) ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_23 ;
struct V_5 * V_6 = NULL ;
int V_8 ;
V_2 = F_17 ( & V_24 , V_4 ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
F_20 ( V_4 , V_2 ) ;
V_23 = F_21 ( V_2 -> V_4 , sizeof( * V_23 ) , V_25 ) ;
if ( ! V_23 ) {
V_8 = - V_26 ;
goto V_27;
}
V_2 -> V_17 = V_23 ;
F_22 ( & V_23 -> V_28 ) ;
F_23 ( & V_23 -> V_29 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
V_4 -> V_30 = F_21 ( V_4 , sizeof( * V_4 -> V_30 ) ,
V_25 ) ;
if ( ! V_4 -> V_30 ) {
V_8 = - V_26 ;
goto V_31;
}
if ( V_9 ) {
V_6 = F_26 ( & V_32 ,
0x00000000 ,
V_33 ) ;
if ( F_18 ( V_6 ) ) {
V_8 = F_19 ( V_6 ) ;
goto V_31;
}
V_8 = F_27 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
goto V_34;
F_4 ( V_4 , F_3 ( 32 ) ) ;
V_8 = F_5 ( V_4 , V_6 ) ;
if ( V_8 )
goto V_34;
}
V_8 = F_28 ( V_4 , V_2 ) ;
if ( V_8 )
goto V_35;
F_29 ( V_2 ) ;
V_2 -> V_36 = true ;
V_8 = F_30 ( V_2 , V_18 ) ;
if ( V_8 )
goto V_37;
F_31 ( V_2 ) ;
V_8 = F_32 ( V_2 ) ;
if ( V_8 )
goto V_38;
V_8 = F_33 ( V_2 , 0 ) ;
if ( V_8 )
goto V_39;
if ( V_9 )
F_34 ( V_6 ) ;
return 0 ;
V_39:
F_35 ( V_2 ) ;
V_38:
F_36 ( V_2 ) ;
V_37:
F_37 ( V_2 ) ;
F_38 ( V_4 , V_2 ) ;
V_35:
if ( V_9 )
F_7 ( V_4 ) ;
V_34:
if ( V_9 )
F_34 ( V_6 ) ;
V_31:
F_39 ( V_2 ) ;
V_2 -> V_17 = NULL ;
V_27:
F_40 ( V_2 ) ;
return V_8 ;
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_42 ( V_4 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_4 , V_2 ) ;
if ( V_9 )
F_7 ( V_4 ) ;
F_39 ( V_2 ) ;
V_2 -> V_17 = NULL ;
F_43 ( V_2 ) ;
F_40 ( V_2 ) ;
F_20 ( V_4 , NULL ) ;
}
static void F_44 ( struct V_1 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
F_45 ( & V_16 -> V_40 ) ;
}
static void F_46 ( struct V_1 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_17 ;
F_47 () ;
F_48 ( & V_16 -> V_40 , 1 ) ;
F_49 () ;
}
static void F_50 ( struct V_1 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_17 ;
F_47 () ;
F_48 ( & V_16 -> V_40 , 0 ) ;
F_49 () ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_20 = F_42 ( V_4 ) ;
struct V_15 * V_16 = V_20 -> V_17 ;
F_52 ( V_20 ) ;
F_46 ( V_20 ) ;
V_16 -> V_41 = F_53 ( V_20 ) ;
if ( F_18 ( V_16 -> V_41 ) ) {
F_50 ( V_20 ) ;
F_54 ( V_20 ) ;
return F_19 ( V_16 -> V_41 ) ;
}
return 0 ;
}
static int F_55 ( struct V_3 * V_4 )
{
struct V_1 * V_20 = F_42 ( V_4 ) ;
struct V_15 * V_16 = V_20 -> V_17 ;
F_56 ( V_20 , V_16 -> V_41 ) ;
F_50 ( V_20 ) ;
F_54 ( V_20 ) ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
return V_4 -> V_45 == V_44 ;
}
static void F_58 ( struct V_3 * V_4 ,
struct V_46 * * V_47 ,
struct V_43 * V_48 )
{
struct V_43 * V_49 , * V_50 ;
F_59 (port, ep) {
V_50 = F_60 ( V_49 ) ;
if ( ! V_50 || ! F_61 ( V_50 ) ) {
F_62 ( V_50 ) ;
continue;
} else if ( ! F_61 ( V_50 -> V_51 ) ) {
F_63 ( V_4 , L_1 ,
V_50 -> V_52 ) ;
F_62 ( V_50 ) ;
continue;
}
F_64 ( V_4 , V_47 , F_57 , V_50 ) ;
F_62 ( V_50 ) ;
}
}
static int F_65 ( struct V_53 * V_54 )
{
struct V_3 * V_4 = & V_54 -> V_4 ;
struct V_46 * V_47 = NULL ;
struct V_43 * V_44 = V_4 -> V_45 ;
struct V_43 * V_48 ;
int V_21 ;
if ( ! V_44 )
return - V_55 ;
for ( V_21 = 0 ; ; V_21 ++ ) {
struct V_43 * V_56 ;
V_48 = F_66 ( V_44 , L_2 , V_21 ) ;
if ( ! V_48 )
break;
if ( ! F_61 ( V_48 -> V_51 ) ) {
F_62 ( V_48 ) ;
continue;
}
V_56 = F_66 ( V_48 -> V_51 , L_3 , 0 ) ;
if ( ! V_56 || ! F_61 ( V_56 -> V_51 ) ) {
F_67 ( V_4 , L_4 ,
V_48 -> V_51 -> V_52 ) ;
V_9 = false ;
}
F_62 ( V_56 ) ;
F_64 ( V_4 , & V_47 , F_57 , V_48 -> V_51 ) ;
F_62 ( V_48 ) ;
}
if ( V_21 == 0 ) {
F_68 ( V_4 , L_5 ) ;
return - V_55 ;
}
if ( ! V_47 ) {
F_68 ( V_4 , L_6 ) ;
return - V_55 ;
}
for ( V_21 = 0 ; ; V_21 ++ ) {
V_48 = F_66 ( V_44 , L_2 , V_21 ) ;
if ( ! V_48 )
break;
if ( ! F_61 ( V_48 -> V_51 ) ) {
F_62 ( V_48 ) ;
continue;
}
F_58 ( V_4 , & V_47 , V_48 ) ;
F_62 ( V_48 ) ;
}
return F_69 ( V_4 , & V_57 , V_47 ) ;
}
static int F_70 ( struct V_53 * V_54 )
{
F_71 ( & V_54 -> V_4 , & V_57 ) ;
return 0 ;
}
