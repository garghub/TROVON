static int F_1 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 ;
unsigned int V_7 = 0 ;
* V_2 = 0 ;
F_2 (p, &drm_dev->mode_config.plane_list, head) {
struct V_8 * V_9 = F_3 ( V_6 ) ;
* V_2 |= V_9 -> V_10 . V_11 << V_7 ;
V_7 ++ ;
}
return 0 ;
}
static int F_4 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 ;
unsigned int V_7 = 0 ;
F_2 (p, &drm_dev->mode_config.plane_list, head) {
struct V_8 * V_9 = F_3 ( V_6 ) ;
V_9 -> V_10 . V_11 = ( V_2 >> V_7 ) & 1 ;
V_7 ++ ;
}
return 0 ;
}
static int F_5 ( struct V_12 * V_13 , void * V_1 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_3 * V_17 = V_15 -> V_18 -> V_17 ;
struct V_5 * V_6 ;
F_2 (p, &dev->mode_config.plane_list, head) {
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_6 ( V_13 , L_1 ,
V_9 -> V_10 . V_19 ,
V_9 -> V_10 . V_20 ) ;
}
return 0 ;
}
static int F_7 ( struct V_21 * V_22 ,
struct V_23 * V_18 ,
const char * V_24 ,
const struct V_25 * V_26 )
{
struct V_3 * V_17 = V_18 -> V_17 ;
struct V_14 * V_15 ;
struct V_21 * V_27 ;
V_27 = F_8 ( V_24 , V_28 | V_29 , V_22 , V_17 , V_26 ) ;
if ( F_9 ( V_27 ) )
return F_10 ( V_27 ) ;
V_15 = F_11 ( sizeof( * V_15 ) , V_30 ) ;
if ( ! V_15 ) {
F_12 ( V_27 ) ;
return - V_31 ;
}
V_15 -> V_18 = V_18 ;
V_15 -> V_32 = V_27 ;
V_15 -> V_33 = ( void * ) V_26 ;
F_13 ( & V_18 -> V_34 ) ;
F_14 ( & V_15 -> V_35 , & V_18 -> V_36 ) ;
F_15 ( & V_18 -> V_34 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_18 )
{
int V_37 ;
V_37 = F_17 ( V_38 ,
F_18 ( V_38 ) ,
V_18 -> V_39 , V_18 ) ;
if ( V_37 )
goto V_40;
V_37 = F_7 ( V_18 -> V_39 , V_18 , L_2 ,
& V_41 ) ;
if ( V_37 )
goto V_40;
F_19 ( L_3 , V_42 ) ;
return 0 ;
V_40:
F_20 ( L_4 , V_42 ) ;
return V_37 ;
}
void F_21 ( struct V_23 * V_18 )
{
F_22 ( V_38 ,
F_18 ( V_38 ) , V_18 ) ;
F_22 ( (struct V_43 * ) & V_41 ,
1 , V_18 ) ;
}
static void F_23 ( struct V_44 * V_16 ,
struct V_45 * V_46 )
{
V_16 -> V_47 . V_46 = V_46 ;
F_24 ( & V_16 -> V_47 . V_48 ) ;
}
static void F_25 ( struct V_44 * V_16 ,
struct V_45 * V_46 )
{
struct V_3 * V_49 = V_16 -> V_4 ;
F_26 ( V_49 , V_46 ) ;
F_27 ( V_49 , V_46 , false ) ;
F_28 ( V_49 , V_46 ) ;
F_29 ( V_49 , V_46 ) ;
F_30 ( V_49 , V_46 ) ;
F_31 ( V_46 ) ;
}
static void F_32 ( struct V_50 * V_48 )
{
struct V_44 * V_16 = F_33 ( V_48 ,
struct V_44 , V_47 . V_48 ) ;
F_25 ( V_16 , V_16 -> V_47 . V_46 ) ;
}
static int F_34 ( struct V_3 * V_49 ,
struct V_45 * V_46 , bool V_51 )
{
struct V_44 * V_16 = V_49 -> V_52 ;
int V_40 ;
V_40 = F_35 ( V_49 , V_46 ) ;
if ( V_40 )
return V_40 ;
F_13 ( & V_16 -> V_47 . V_53 ) ;
F_36 ( & V_16 -> V_47 . V_48 ) ;
F_37 ( V_46 , true ) ;
if ( V_51 )
F_23 ( V_16 , V_46 ) ;
else
F_25 ( V_16 , V_46 ) ;
F_15 ( & V_16 -> V_47 . V_53 ) ;
return 0 ;
}
static void F_38 ( struct V_3 * V_54 )
{
struct V_44 * V_16 = V_54 -> V_52 ;
if ( ! V_54 -> V_55 . V_56 )
return;
if ( V_16 -> V_57 ) {
F_39 ( V_16 -> V_57 ) ;
return;
}
V_16 -> V_57 = F_40 ( V_54 , 32 ,
V_54 -> V_55 . V_58 ,
V_54 -> V_55 . V_56 ) ;
if ( F_9 ( V_16 -> V_57 ) )
V_16 -> V_57 = NULL ;
}
static void F_41 ( struct V_3 * V_17 )
{
V_17 -> V_55 . V_59 = 0 ;
V_17 -> V_55 . V_60 = 0 ;
V_17 -> V_55 . V_61 = V_62 ;
V_17 -> V_55 . V_63 = V_64 ;
V_17 -> V_55 . V_65 = & V_66 ;
}
static int F_42 ( struct V_67 * V_17 , void * V_1 )
{
return V_17 -> V_68 == V_1 ;
}
static int F_43 ( struct V_3 * V_54 )
{
struct V_44 * V_16 ;
V_16 = F_44 ( sizeof( * V_16 ) , V_30 ) ;
if ( ! V_16 )
return - V_31 ;
V_54 -> V_52 = ( void * ) V_16 ;
F_45 ( V_54 -> V_17 , V_54 ) ;
V_16 -> V_4 = V_54 ;
F_46 ( & V_16 -> V_47 . V_53 ) ;
F_47 ( & V_16 -> V_47 . V_48 , F_32 ) ;
F_48 ( V_54 ) ;
F_41 ( V_54 ) ;
F_49 ( V_54 ) ;
return 0 ;
}
static void F_50 ( struct V_3 * V_54 )
{
struct V_44 * V_16 = V_54 -> V_52 ;
if ( V_16 -> V_57 ) {
F_51 ( V_16 -> V_57 ) ;
V_16 -> V_57 = NULL ;
}
F_52 ( V_54 ) ;
F_53 ( V_54 ) ;
F_54 ( V_16 ) ;
V_54 -> V_52 = NULL ;
}
static int F_55 ( struct V_67 * V_17 )
{
struct V_3 * V_54 ;
int V_37 ;
V_54 = F_56 ( & V_69 , V_17 ) ;
if ( ! V_54 )
return - V_31 ;
V_54 -> V_70 = F_57 ( V_17 ) ;
V_37 = F_43 ( V_54 ) ;
if ( V_37 )
goto V_71;
V_37 = F_58 ( V_54 -> V_17 , V_54 ) ;
if ( V_37 )
goto V_72;
V_37 = F_59 ( V_54 , 0 ) ;
if ( V_37 )
goto V_73;
F_60 ( V_54 ) ;
return 0 ;
V_73:
F_61 ( V_54 ) ;
V_72:
F_50 ( V_54 ) ;
V_71:
F_62 ( V_54 ) ;
return V_37 ;
}
static void F_63 ( struct V_67 * V_17 )
{
struct V_3 * V_54 = F_64 ( V_17 ) ;
F_65 ( V_54 ) ;
F_50 ( V_54 ) ;
F_62 ( V_54 ) ;
}
static int F_66 ( struct V_74 * V_75 )
{
struct V_67 * V_17 = & V_75 -> V_17 ;
struct V_76 * V_15 = V_17 -> V_68 ;
struct V_76 * V_77 ;
struct V_78 * V_79 = NULL ;
F_67 ( V_17 , F_68 ( 32 ) ) ;
F_69 ( V_15 , NULL , NULL , V_17 ) ;
V_77 = F_70 ( V_15 , NULL ) ;
while ( V_77 ) {
F_71 ( V_17 , & V_79 , F_42 , V_77 ) ;
F_72 ( V_77 ) ;
V_77 = F_70 ( V_15 , V_77 ) ;
}
return F_73 ( V_17 , & V_80 , V_79 ) ;
}
static int F_74 ( struct V_74 * V_75 )
{
F_75 ( & V_75 -> V_17 , & V_80 ) ;
F_76 ( & V_75 -> V_17 ) ;
return 0 ;
}
static int F_77 ( void )
{
return F_78 ( V_81 , F_18 ( V_81 ) ) ;
}
static void F_79 ( void )
{
F_80 ( V_81 , F_18 ( V_81 ) ) ;
}
