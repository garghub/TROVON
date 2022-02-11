static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
V_3 = F_2 ( & V_8 -> V_9 ) ;
if ( V_3 )
F_3 ( L_1 ) ;
return;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_10 * V_11 = & V_5 -> V_12 ;
T_1 V_13 ;
if ( V_11 -> V_14 & 0x0FFFFFFF ) {
F_5 ( V_2 -> V_2 , L_2 ) ;
return - V_15 ;
}
V_13 = ( V_11 -> V_16 >> V_17 ) * 4 ;
V_13 = ( V_13 + V_18 - 1 ) >> V_17 ;
V_13 = ( V_13 < V_11 -> V_19 ) ? V_13 : V_11 -> V_19 ;
V_5 -> V_20 = V_11 -> V_14 +
( V_13 << V_17 ) * 1024 ;
F_6 ( & V_5 -> V_21 ) ;
F_6 ( & V_5 -> V_22 ) ;
F_7 ( 0x00000000 , V_23 ) ;
F_7 ( 0x00000000 , V_24 ) ;
F_8 ( V_24 ) ;
F_7 ( ( F_8 ( V_25 ) & ~ V_26 ) ,
V_25 ) ;
F_8 ( V_25 ) ;
F_9 ( V_5 ) ;
F_7 ( V_11 -> V_27 , V_28 ) ;
F_8 ( V_28 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 ) {
if ( V_5 -> V_29 )
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_5 -> V_30 -> V_31 )
V_5 -> V_30 -> V_31 ( V_2 ) ;
F_13 ( V_2 ) ;
if ( V_5 -> V_32 ) {
F_14 ( V_5 -> V_32 ) ;
V_5 -> V_32 = NULL ;
}
if ( V_5 -> V_33 ) {
struct V_10 * V_11 = & V_5 -> V_12 ;
F_15 ( & V_11 -> V_34 ) ;
F_16 (
F_17
( V_5 -> V_33 ) ,
V_11 -> V_14 ,
V_5 -> V_35 >> V_17 ) ;
F_18 ( & V_11 -> V_34 ) ;
F_19 ( V_5 -> V_33 ) ;
V_5 -> V_33 = NULL ;
}
F_20 ( V_2 ) ;
if ( V_5 -> V_36 ) {
F_21 ( V_5 -> V_36 , 1 ) ;
F_22 ( V_5 -> V_36 ) ;
V_5 -> V_36 = NULL ;
}
if ( V_5 -> V_37 ) {
F_23 ( V_5 -> V_37 ) ;
V_5 -> V_37 = NULL ;
}
if ( V_5 -> V_38 ) {
F_23 ( V_5 -> V_38 ) ;
V_5 -> V_38 = NULL ;
}
if ( V_5 -> V_39 ) {
F_23 ( V_5 -> V_39 ) ;
V_5 -> V_39 = NULL ;
}
if ( V_5 -> V_40 )
F_24 ( V_5 -> V_40 ) ;
F_25 ( V_2 ) ;
F_26 ( V_5 ) ;
V_2 -> V_6 = NULL ;
}
F_27 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_4 * V_5 ;
unsigned long V_42 , V_43 ;
unsigned long V_44 ;
int V_3 = - V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_48 ;
struct V_10 * V_11 ;
V_5 = F_29 ( sizeof( * V_5 ) , V_49 ) ;
if ( V_5 == NULL )
return - V_45 ;
V_5 -> V_30 = (struct V_50 * ) V_41 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = ( void * ) V_5 ;
V_11 = & V_5 -> V_12 ;
F_30 ( V_2 -> V_51 ) ;
V_5 -> V_52 = V_5 -> V_30 -> V_53 ;
V_42 = F_31 ( V_2 -> V_51 , V_54 ) ;
V_5 -> V_37 =
F_32 ( V_42 + V_55 , V_56 ) ;
if ( ! V_5 -> V_37 )
goto V_57;
V_5 -> V_38 = F_32 ( V_42 + V_5 -> V_30 -> V_58 ,
V_59 ) ;
if ( ! V_5 -> V_38 )
goto V_57;
if ( F_33 ( V_2 ) ) {
V_5 -> V_40 = F_34 ( 0 , F_35 ( 3 , 0 ) ) ;
if ( V_5 -> V_40 ) {
V_42 = F_31 ( V_5 -> V_40 ,
V_60 ) ;
V_43 = F_36 ( V_5 -> V_40 ,
V_60 ) ;
V_5 -> V_39 = F_37 ( V_42 ,
V_43 ) ;
if ( ! V_5 -> V_39 )
goto V_57;
F_38 ( L_3 ) ;
} else {
V_5 -> V_39 = V_5 -> V_37 ;
F_38 ( L_4 ) ;
}
V_5 -> V_61 = V_5 -> V_39 ;
} else {
V_5 -> V_61 = V_5 -> V_37 ;
}
F_39 ( V_2 ) ;
V_3 = V_5 -> V_30 -> V_62 ( V_2 ) ;
if ( V_3 )
goto V_57;
F_40 ( V_2 ) ;
V_3 = - V_45 ;
V_5 -> V_36 = F_41 ( V_63 | V_64 ) ;
if ( ! V_5 -> V_36 )
goto V_57;
F_42 ( V_5 -> V_36 , 1 ) ;
V_3 = F_43 ( V_2 , 0 ) ;
if ( V_3 )
goto V_57;
V_5 -> V_33 = F_44 ( V_2 , 1 , 0 , 0 ) ;
if ( ! V_5 -> V_33 )
goto V_57;
V_5 -> V_32 = F_45 ( V_5 -> V_33 , 1 , 0 ) ;
if ( ! V_5 -> V_32 )
goto V_57;
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_15 ( & V_11 -> V_34 ) ;
V_3 = F_46 ( F_17 ( V_5 -> V_33 ) ,
V_5 -> V_65 >> V_17 ,
V_11 -> V_27 ,
V_11 -> V_16 >> V_17 , 0 ) ;
F_18 ( & V_11 -> V_34 ) ;
F_47 ( F_17 ( V_5 -> V_33 ) , 0 ) ;
F_47 ( V_5 -> V_32 , 1 ) ;
F_7 ( 0x20000000 , V_66 ) ;
F_7 ( 0x30000000 , V_67 ) ;
F_48 () ;
V_3 = F_49 ( V_2 , V_5 -> V_52 ) ;
if ( V_3 )
goto V_57;
V_5 -> V_68 = 0 ;
V_5 -> V_69 [ 0 ] = 0 ;
V_5 -> V_69 [ 1 ] = 0 ;
V_5 -> V_69 [ 2 ] = 0 ;
F_50 ( & V_5 -> V_21 , V_44 ) ;
F_51 ( 0xFFFFFFFF , V_70 ) ;
F_51 ( 0x00000000 , V_71 ) ;
F_51 ( 0xFFFFFFFF , V_72 ) ;
F_52 ( & V_5 -> V_21 , V_44 ) ;
F_53 ( V_2 , V_2 -> V_51 -> V_73 ) ;
V_2 -> V_74 = true ;
V_2 -> V_75 = 0xffffff ;
V_2 -> V_76 -> V_77 = V_78 ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 (connector, &dev->mode_config.connector_list,
head) {
V_48 = F_58 ( V_47 ) ;
switch ( V_48 -> type ) {
case V_79 :
case V_80 :
V_3 = F_59 ( V_2 ) ;
break;
}
}
if ( V_3 )
return V_3 ;
F_60 ( V_2 ) ;
#if 0
pm_runtime_enable(&dev->pdev->dev);
pm_runtime_set_active(&dev->pdev->dev);
#endif
return 0 ;
V_57:
F_10 ( V_2 ) ;
return V_3 ;
}
static int F_61 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_62 ( struct V_29 * V_81 )
{
#ifdef F_63
if ( V_81 ) {
V_81 -> V_82 . V_83 = V_81 -> V_30 -> F_62 ( V_81 ) ;
F_64 ( V_81 ) ;
}
#endif
}
static long F_65 ( struct V_84 * V_85 , unsigned int V_86 ,
unsigned long V_87 )
{
struct V_88 * V_89 = V_85 -> V_90 ;
struct V_1 * V_2 = V_89 -> V_91 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
static unsigned int V_92 ;
if ( V_92 == 1 && V_5 -> V_93 ) {
V_92 ++ ;
F_66 ( & V_2 -> V_51 -> V_2 ) ;
V_5 -> V_94 = 1 ;
}
return F_67 ( V_85 , V_86 , V_87 ) ;
}
static void F_68 ( struct V_1 * V_2 , struct V_88 * V_95 )
{
}
static int F_69 ( struct V_96 * V_51 , const struct V_97 * V_98 )
{
return F_70 ( V_51 , V_98 , & V_76 ) ;
}
static void F_71 ( struct V_96 * V_51 )
{
struct V_1 * V_2 = F_72 ( V_51 ) ;
F_73 ( V_2 ) ;
}
static int T_2 F_74 ( void )
{
return F_75 ( & V_76 , & V_99 ) ;
}
static void T_3 F_76 ( void )
{
F_77 ( & V_76 , & V_99 ) ;
}
