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
if ( ! V_2 )
return - V_25 ;
F_18 ( V_4 , V_2 ) ;
V_23 = F_19 ( V_2 -> V_4 , sizeof( * V_23 ) , V_26 ) ;
if ( ! V_23 ) {
V_8 = - V_25 ;
goto V_27;
}
V_2 -> V_17 = V_23 ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
V_4 -> V_28 = F_19 ( V_4 , sizeof( * V_4 -> V_28 ) ,
V_26 ) ;
if ( ! V_4 -> V_28 ) {
V_8 = - V_25 ;
goto V_29;
}
if ( V_9 ) {
V_6 = F_22 ( & V_30 ,
0x00000000 ,
V_31 ) ;
if ( F_23 ( V_6 ) ) {
V_8 = F_24 ( V_6 ) ;
goto V_29;
}
V_8 = F_25 ( V_4 , F_3 ( 32 ) ) ;
if ( V_8 )
goto V_32;
F_4 ( V_4 , F_3 ( 32 ) ) ;
V_8 = F_5 ( V_4 , V_6 ) ;
if ( V_8 )
goto V_32;
}
V_8 = F_26 ( V_4 , V_2 ) ;
if ( V_8 )
goto V_33;
F_27 ( V_2 ) ;
V_2 -> V_34 = true ;
V_8 = F_28 ( V_2 , V_18 ) ;
if ( V_8 )
goto V_35;
F_29 ( V_2 ) ;
V_8 = F_30 ( V_2 ) ;
if ( V_8 )
goto V_36;
V_8 = F_31 ( V_2 , 0 ) ;
if ( V_8 )
goto V_37;
if ( V_9 )
F_32 ( V_6 ) ;
return 0 ;
V_37:
F_33 ( V_2 ) ;
V_36:
F_34 ( V_2 ) ;
V_35:
F_35 ( V_2 ) ;
F_36 ( V_4 , V_2 ) ;
V_33:
if ( V_9 )
F_7 ( V_4 ) ;
V_32:
if ( V_9 )
F_32 ( V_6 ) ;
V_29:
F_37 ( V_2 ) ;
V_2 -> V_17 = NULL ;
V_27:
F_38 ( V_2 ) ;
return V_8 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_40 ( V_4 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_4 , V_2 ) ;
if ( V_9 )
F_7 ( V_4 ) ;
F_37 ( V_2 ) ;
V_2 -> V_17 = NULL ;
F_41 ( V_2 ) ;
F_38 ( V_2 ) ;
F_18 ( V_4 , NULL ) ;
}
static void F_42 ( struct V_1 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_17 ;
F_43 ( & V_16 -> V_38 ) ;
}
void F_44 ( struct V_1 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_17 ;
F_45 () ;
F_46 ( & V_16 -> V_38 , 1 ) ;
F_47 () ;
}
void F_48 ( struct V_1 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_17 ;
F_45 () ;
F_46 ( & V_16 -> V_38 , 0 ) ;
F_47 () ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_1 * V_20 = F_40 ( V_4 ) ;
struct V_15 * V_16 = V_20 -> V_17 ;
F_50 ( V_20 ) ;
F_44 ( V_20 ) ;
V_16 -> V_39 = F_51 ( V_20 ) ;
if ( F_23 ( V_16 -> V_39 ) ) {
F_48 ( V_20 ) ;
F_52 ( V_20 ) ;
return F_24 ( V_16 -> V_39 ) ;
}
return 0 ;
}
static int F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_20 = F_40 ( V_4 ) ;
struct V_15 * V_16 = V_20 -> V_17 ;
F_54 ( V_20 , V_16 -> V_39 ) ;
F_48 ( V_20 ) ;
F_52 ( V_20 ) ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 , void * V_40 )
{
struct V_41 * V_42 = V_40 ;
return V_4 -> V_43 == V_42 ;
}
static void F_56 ( struct V_3 * V_4 ,
struct V_44 * * V_45 ,
struct V_41 * V_46 )
{
struct V_41 * V_47 , * V_48 ;
F_57 (port, ep) {
V_48 = F_58 ( V_47 ) ;
if ( ! V_48 || ! F_59 ( V_48 ) ) {
F_60 ( V_48 ) ;
continue;
} else if ( ! F_59 ( V_48 -> V_49 ) ) {
F_61 ( V_4 , L_1 ,
V_48 -> V_50 ) ;
F_60 ( V_48 ) ;
continue;
}
F_62 ( V_4 , V_45 , F_55 , V_48 ) ;
F_60 ( V_48 ) ;
}
}
static int F_63 ( struct V_51 * V_52 )
{
struct V_3 * V_4 = & V_52 -> V_4 ;
struct V_44 * V_45 = NULL ;
struct V_41 * V_42 = V_4 -> V_43 ;
struct V_41 * V_46 ;
int V_21 ;
if ( ! V_42 )
return - V_53 ;
for ( V_21 = 0 ; ; V_21 ++ ) {
struct V_41 * V_54 ;
V_46 = F_64 ( V_42 , L_2 , V_21 ) ;
if ( ! V_46 )
break;
if ( ! F_59 ( V_46 -> V_49 ) ) {
F_60 ( V_46 ) ;
continue;
}
V_54 = F_64 ( V_46 -> V_49 , L_3 , 0 ) ;
if ( ! V_54 || ! F_59 ( V_54 -> V_49 ) ) {
F_65 ( V_4 , L_4 ,
V_46 -> V_49 -> V_50 ) ;
V_9 = false ;
}
F_60 ( V_54 ) ;
F_62 ( V_4 , & V_45 , F_55 , V_46 -> V_49 ) ;
F_60 ( V_46 ) ;
}
if ( V_21 == 0 ) {
F_66 ( V_4 , L_5 ) ;
return - V_53 ;
}
if ( ! V_45 ) {
F_66 ( V_4 , L_6 ) ;
return - V_53 ;
}
for ( V_21 = 0 ; ; V_21 ++ ) {
V_46 = F_64 ( V_42 , L_2 , V_21 ) ;
if ( ! V_46 )
break;
if ( ! F_59 ( V_46 -> V_49 ) ) {
F_60 ( V_46 ) ;
continue;
}
F_56 ( V_4 , & V_45 , V_46 ) ;
F_60 ( V_46 ) ;
}
return F_67 ( V_4 , & V_55 , V_45 ) ;
}
static int F_68 ( struct V_51 * V_52 )
{
F_69 ( & V_52 -> V_4 , & V_55 ) ;
return 0 ;
}
