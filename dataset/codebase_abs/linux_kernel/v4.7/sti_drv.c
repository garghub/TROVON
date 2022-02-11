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
int V_19 ;
V_19 = F_6 ( & V_17 -> V_20 ) ;
if ( V_19 )
return V_19 ;
F_2 (p, &dev->mode_config.plane_list, head) {
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_7 ( V_13 , L_1 ,
V_9 -> V_10 . V_21 ,
V_9 -> V_10 . V_22 ) ;
}
F_8 ( & V_17 -> V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 ,
struct V_25 * V_18 ,
const char * V_26 ,
const struct V_27 * V_28 )
{
struct V_3 * V_17 = V_18 -> V_17 ;
struct V_14 * V_15 ;
struct V_23 * V_29 ;
V_29 = F_10 ( V_26 , V_30 | V_31 , V_24 , V_17 , V_28 ) ;
if ( F_11 ( V_29 ) )
return F_12 ( V_29 ) ;
V_15 = F_13 ( sizeof( * V_15 ) , V_32 ) ;
if ( ! V_15 ) {
F_14 ( V_29 ) ;
return - V_33 ;
}
V_15 -> V_18 = V_18 ;
V_15 -> V_34 = V_29 ;
V_15 -> V_35 = ( void * ) V_28 ;
F_15 ( & V_18 -> V_36 ) ;
F_16 ( & V_15 -> V_37 , & V_18 -> V_38 ) ;
F_8 ( & V_18 -> V_36 ) ;
return 0 ;
}
static int F_17 ( struct V_25 * V_18 )
{
int V_19 ;
V_19 = F_18 ( V_39 ,
F_19 ( V_39 ) ,
V_18 -> V_40 , V_18 ) ;
if ( V_19 )
goto V_41;
V_19 = F_9 ( V_18 -> V_40 , V_18 , L_2 ,
& V_42 ) ;
if ( V_19 )
goto V_41;
F_20 ( L_3 , V_43 ) ;
return 0 ;
V_41:
F_21 ( L_4 , V_43 ) ;
return V_19 ;
}
void F_22 ( struct V_25 * V_18 )
{
F_23 ( V_39 ,
F_19 ( V_39 ) , V_18 ) ;
F_23 ( (struct V_44 * ) & V_42 ,
1 , V_18 ) ;
}
static void F_24 ( struct V_45 * V_16 ,
struct V_46 * V_47 )
{
V_16 -> V_48 . V_47 = V_47 ;
F_25 ( & V_16 -> V_48 . V_49 ) ;
}
static void F_26 ( struct V_45 * V_16 ,
struct V_46 * V_47 )
{
struct V_3 * V_50 = V_16 -> V_4 ;
F_27 ( V_50 , V_47 ) ;
F_28 ( V_50 , V_47 , false ) ;
F_29 ( V_50 , V_47 ) ;
F_30 ( V_50 , V_47 ) ;
F_31 ( V_50 , V_47 ) ;
F_32 ( V_47 ) ;
}
static void F_33 ( struct V_51 * V_49 )
{
struct V_45 * V_16 = F_34 ( V_49 ,
struct V_45 , V_48 . V_49 ) ;
F_26 ( V_16 , V_16 -> V_48 . V_47 ) ;
}
static int F_35 ( struct V_3 * V_50 ,
struct V_46 * V_47 , bool V_52 )
{
struct V_45 * V_16 = V_50 -> V_53 ;
int V_41 ;
V_41 = F_36 ( V_50 , V_47 ) ;
if ( V_41 )
return V_41 ;
F_15 ( & V_16 -> V_48 . V_54 ) ;
F_37 ( & V_16 -> V_48 . V_49 ) ;
F_38 ( V_50 , V_47 ) ;
if ( V_52 )
F_24 ( V_16 , V_47 ) ;
else
F_26 ( V_16 , V_47 ) ;
F_8 ( & V_16 -> V_48 . V_54 ) ;
return 0 ;
}
static void F_39 ( struct V_3 * V_17 )
{
V_17 -> V_55 . V_56 = 0 ;
V_17 -> V_55 . V_57 = 0 ;
V_17 -> V_55 . V_58 = V_59 ;
V_17 -> V_55 . V_60 = V_61 ;
V_17 -> V_55 . V_62 = & V_63 ;
}
static int F_40 ( struct V_3 * V_17 , unsigned long V_64 )
{
struct V_45 * V_16 ;
int V_19 ;
V_16 = F_41 ( sizeof( * V_16 ) , V_32 ) ;
if ( ! V_16 ) {
F_21 ( L_5 ) ;
return - V_33 ;
}
V_17 -> V_53 = ( void * ) V_16 ;
V_16 -> V_4 = V_17 ;
F_42 ( & V_16 -> V_48 . V_54 ) ;
F_43 ( & V_16 -> V_48 . V_49 , F_33 ) ;
F_44 ( V_17 ) ;
F_45 ( V_17 ) ;
F_39 ( V_17 ) ;
V_19 = F_46 ( V_17 -> V_17 , V_17 ) ;
if ( V_19 ) {
F_47 ( V_17 ) ;
F_48 ( V_17 ) ;
F_49 ( V_16 ) ;
return V_19 ;
}
F_50 ( V_17 ) ;
F_51 ( V_17 ) ;
F_52 ( V_17 , 32 ,
V_17 -> V_55 . V_65 ,
V_17 -> V_55 . V_66 ) ;
return 0 ;
}
static int F_53 ( struct V_67 * V_17 , void * V_1 )
{
return V_17 -> V_68 == V_1 ;
}
static int F_54 ( struct V_67 * V_17 )
{
return F_55 ( & V_69 , F_56 ( V_17 ) ) ;
}
static void F_57 ( struct V_67 * V_17 )
{
F_58 ( F_59 ( V_17 ) ) ;
}
static int F_60 ( struct V_70 * V_71 )
{
struct V_67 * V_17 = & V_71 -> V_17 ;
struct V_72 * V_15 = V_17 -> V_68 ;
struct V_72 * V_73 ;
struct V_74 * V_75 = NULL ;
F_61 ( V_17 , F_62 ( 32 ) ) ;
F_63 ( V_15 , NULL , NULL , V_17 ) ;
V_73 = F_64 ( V_15 , NULL ) ;
while ( V_73 ) {
F_65 ( V_17 , & V_75 , F_53 , V_73 ) ;
F_66 ( V_73 ) ;
V_73 = F_64 ( V_15 , V_73 ) ;
}
return F_67 ( V_17 , & V_76 , V_75 ) ;
}
static int F_68 ( struct V_70 * V_71 )
{
F_69 ( & V_71 -> V_17 , & V_76 ) ;
F_70 ( & V_71 -> V_17 ) ;
return 0 ;
}
static int F_71 ( void )
{
return F_72 ( V_77 , F_19 ( V_77 ) ) ;
}
static void F_73 ( void )
{
F_74 ( V_77 , F_19 ( V_77 ) ) ;
}
