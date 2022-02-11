static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_2 ( V_2 ) ;
V_3 = F_3 ( & V_8 -> V_9 ) ;
if ( V_3 )
F_4 ( L_1 ) ;
F_5 ( V_2 ) ;
return;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_10 * V_11 = & V_5 -> V_12 ;
T_1 V_13 ;
if ( V_11 -> V_14 & 0x0FFFFFFF ) {
F_7 ( V_2 -> V_2 , L_2 ) ;
return - V_15 ;
}
V_13 = ( V_11 -> V_16 >> V_17 ) * 4 ;
V_13 = ( V_13 + V_18 - 1 ) >> V_17 ;
V_13 = ( V_13 < V_11 -> V_19 ) ? V_13 : V_11 -> V_19 ;
V_5 -> V_20 = V_11 -> V_14 +
( V_13 << V_17 ) * 1024 ;
F_8 ( & V_5 -> V_21 ) ;
F_8 ( & V_5 -> V_22 ) ;
F_9 ( 0x00000000 , V_23 ) ;
F_9 ( 0x00000000 , V_24 ) ;
F_10 ( V_24 ) ;
F_9 ( ( F_10 ( V_25 ) & ~ V_26 ) ,
V_25 ) ;
F_10 ( V_25 ) ;
F_11 ( V_5 ) ;
F_9 ( V_11 -> V_27 , V_28 ) ;
F_10 ( V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 ) {
if ( V_5 -> V_29 )
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_5 -> V_30 -> V_31 )
V_5 -> V_30 -> V_31 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( V_5 -> V_32 ) {
F_16 ( V_5 -> V_32 ) ;
V_5 -> V_32 = NULL ;
}
if ( V_5 -> V_33 ) {
struct V_10 * V_11 = & V_5 -> V_12 ;
F_17 ( & V_11 -> V_34 ) ;
F_18 (
F_19
( V_5 -> V_33 ) ,
V_11 -> V_14 ,
V_5 -> V_35 >> V_17 ) ;
F_20 ( & V_11 -> V_34 ) ;
F_21 ( V_5 -> V_33 ) ;
V_5 -> V_33 = NULL ;
}
F_22 ( V_2 ) ;
if ( V_5 -> V_36 ) {
F_23 ( V_5 -> V_36 , 1 ) ;
F_24 ( V_5 -> V_36 ) ;
V_5 -> V_36 = NULL ;
}
if ( V_5 -> V_37 ) {
F_25 ( V_5 -> V_37 ) ;
V_5 -> V_37 = NULL ;
}
if ( V_5 -> V_38 ) {
F_25 ( V_5 -> V_38 ) ;
V_5 -> V_38 = NULL ;
}
if ( V_5 -> V_39 ) {
F_25 ( V_5 -> V_39 ) ;
V_5 -> V_39 = NULL ;
}
if ( V_5 -> V_40 )
F_26 ( V_5 -> V_40 ) ;
F_27 ( V_2 ) ;
F_28 ( V_5 ) ;
V_2 -> V_6 = NULL ;
}
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_4 * V_5 ;
unsigned long V_42 , V_43 ;
unsigned long V_44 ;
int V_3 = - V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_48 ;
struct V_10 * V_11 ;
V_5 = F_31 ( sizeof( * V_5 ) , V_49 ) ;
if ( V_5 == NULL )
return - V_45 ;
V_5 -> V_30 = (struct V_50 * ) V_41 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = ( void * ) V_5 ;
V_11 = & V_5 -> V_12 ;
F_32 ( V_2 -> V_51 ) ;
V_5 -> V_52 = V_5 -> V_30 -> V_53 ;
V_42 = F_33 ( V_2 -> V_51 , V_54 ) ;
V_5 -> V_37 =
F_34 ( V_42 + V_55 , V_56 ) ;
if ( ! V_5 -> V_37 )
goto V_57;
V_5 -> V_38 = F_34 ( V_42 + V_5 -> V_30 -> V_58 ,
V_59 ) ;
if ( ! V_5 -> V_38 )
goto V_57;
if ( F_35 ( V_2 ) ) {
V_5 -> V_40 = F_36 ( 0 , F_37 ( 3 , 0 ) ) ;
if ( V_5 -> V_40 ) {
V_42 = F_33 ( V_5 -> V_40 ,
V_60 ) ;
V_43 = F_38 ( V_5 -> V_40 ,
V_60 ) ;
V_5 -> V_39 = F_39 ( V_42 ,
V_43 ) ;
if ( ! V_5 -> V_39 )
goto V_57;
F_40 ( L_3 ) ;
} else {
V_5 -> V_39 = V_5 -> V_37 ;
F_40 ( L_4 ) ;
}
V_5 -> V_61 = V_5 -> V_39 ;
} else {
V_5 -> V_61 = V_5 -> V_37 ;
}
F_41 ( V_2 ) ;
V_3 = V_5 -> V_30 -> V_62 ( V_2 ) ;
if ( V_3 )
goto V_57;
F_42 ( V_2 ) ;
V_3 = - V_45 ;
V_5 -> V_36 = F_43 ( V_63 | V_64 ) ;
if ( ! V_5 -> V_36 )
goto V_57;
F_44 ( V_5 -> V_36 , 1 ) ;
V_3 = F_45 ( V_2 , 0 ) ;
if ( V_3 )
goto V_57;
V_5 -> V_33 = F_46 ( V_2 , 1 , 0 , 0 ) ;
if ( ! V_5 -> V_33 )
goto V_57;
V_5 -> V_32 = F_47 ( V_5 -> V_33 , 1 , 0 ) ;
if ( ! V_5 -> V_32 )
goto V_57;
V_3 = F_6 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_17 ( & V_11 -> V_34 ) ;
V_3 = F_48 ( F_19 ( V_5 -> V_33 ) ,
V_5 -> V_65 >> V_17 ,
V_11 -> V_27 ,
V_11 -> V_16 >> V_17 , 0 ) ;
F_20 ( & V_11 -> V_34 ) ;
F_49 ( F_19 ( V_5 -> V_33 ) , 0 ) ;
F_49 ( V_5 -> V_32 , 1 ) ;
F_9 ( 0x20000000 , V_66 ) ;
F_9 ( 0x30000000 , V_67 ) ;
F_50 () ;
V_3 = F_51 ( V_2 , V_5 -> V_52 ) ;
if ( V_3 )
goto V_57;
V_5 -> V_68 = 0 ;
V_5 -> V_69 [ 0 ] = 0 ;
V_5 -> V_69 [ 1 ] = 0 ;
V_5 -> V_69 [ 2 ] = 0 ;
F_52 ( & V_5 -> V_21 , V_44 ) ;
F_53 ( 0xFFFFFFFF , V_70 ) ;
F_53 ( 0x00000000 , V_71 ) ;
F_53 ( 0xFFFFFFFF , V_72 ) ;
F_54 ( & V_5 -> V_21 , V_44 ) ;
F_55 ( V_2 ) ;
V_2 -> V_73 = true ;
V_2 -> V_74 = 0xffffff ;
V_2 -> V_75 -> V_76 = V_77 ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 (connector, &dev->mode_config.connector_list,
head) {
V_48 = F_60 ( V_47 ) ;
switch ( V_48 -> type ) {
case V_78 :
case V_79 :
V_3 = F_61 ( V_2 ) ;
break;
}
}
if ( V_3 )
return V_3 ;
F_62 ( V_2 ) ;
#if 0
pm_runtime_enable(&dev->pdev->dev);
pm_runtime_set_active(&dev->pdev->dev);
#endif
return 0 ;
V_57:
F_12 ( V_2 ) ;
return V_3 ;
}
static int F_63 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_64 ( struct V_29 * V_80 )
{
#ifdef F_65
if ( V_80 ) {
V_80 -> V_81 . V_82 = V_80 -> V_30 -> F_64 ( V_80 ) ;
F_66 ( V_80 ) ;
}
#endif
}
static long F_67 ( struct V_83 * V_84 , unsigned int V_85 ,
unsigned long V_86 )
{
struct V_87 * V_88 = V_84 -> V_89 ;
struct V_1 * V_2 = V_88 -> V_90 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
static unsigned int V_91 ;
if ( V_91 == 1 && V_5 -> V_92 ) {
V_91 ++ ;
F_68 ( & V_2 -> V_51 -> V_2 ) ;
V_5 -> V_93 = 1 ;
}
return F_69 ( V_84 , V_85 , V_86 ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_87 * V_94 )
{
}
static int F_71 ( struct V_95 * V_51 , const struct V_96 * V_97 )
{
return F_72 ( V_51 , V_97 , & V_75 ) ;
}
static void F_73 ( struct V_95 * V_51 )
{
struct V_1 * V_2 = F_74 ( V_51 ) ;
F_75 ( V_2 ) ;
}
static int T_2 F_76 ( void )
{
return F_77 ( & V_75 , & V_98 ) ;
}
static void T_3 F_78 ( void )
{
F_79 ( & V_75 , & V_98 ) ;
}
