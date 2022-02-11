static int F_1 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 ;
F_2 ( & V_5 -> V_6 ) ;
return 0 ;
}
static int F_3 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 ;
if ( V_3 )
F_4 ( V_5 -> V_7 -> V_8 . V_9 . V_10 , V_5 -> V_6 . V_11 ) ;
F_5 ( & V_5 -> V_6 ) ;
return 0 ;
}
static void F_6 ( struct V_12 * V_13 )
{
F_7 ( & V_13 -> V_14 ) ;
F_8 ( & V_13 -> V_15 , F_1 , NULL ) ;
F_9 ( & V_13 -> V_14 ) ;
}
static void F_10 ( struct V_12 * V_13 , int V_16 )
{
F_7 ( & V_13 -> V_14 ) ;
F_8 ( & V_13 -> V_15 , F_3 ,
( void * ) ( unsigned long ) V_16 ) ;
F_9 ( & V_13 -> V_14 ) ;
}
static void F_11 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_12 ( V_18 , struct V_12 ,
V_19 . V_18 ) ;
F_10 ( V_13 , 1 ) ;
}
static void F_13 ( struct V_12 * V_13 )
{
F_14 ( L_1 , V_20 , V_13 ) ;
F_15 ( & V_13 -> V_21 ) ;
F_15 ( & V_13 -> V_15 ) ;
F_15 ( & V_13 -> V_22 ) ;
F_16 ( & V_13 -> V_14 ) ;
F_17 ( & V_13 -> V_19 , F_11 ) ;
V_13 -> V_23 . V_24 = V_25 - 32 ;
V_13 -> V_23 . V_26 = V_27 ;
V_13 -> V_23 . V_28 = V_29 ;
V_13 -> V_23 . V_30 = V_29 ;
V_13 -> V_23 . V_31 = V_32 - 1 ;
V_13 -> V_23 . V_33 = V_34 ;
V_13 -> V_23 . V_35 = F_18 ( & V_13 -> V_8 ) ;
V_13 -> V_23 . V_36 = V_37 ;
V_13 -> V_23 . V_38 = V_39 - 1 ;
V_13 -> V_23 . V_40 = V_41 ;
V_13 -> V_23 . V_42 = V_43 ;
V_13 -> V_23 . V_44 = 0 ;
V_13 -> V_23 . V_45 = 8 ;
V_13 -> V_23 . V_46 =
V_13 -> V_23 . V_45 * V_13 -> V_23 . V_24 ;
V_13 -> V_23 . V_47 = 8 ;
V_13 -> V_23 . V_48 =
V_13 -> V_23 . V_47 * V_13 -> V_23 . V_24 ;
V_13 -> V_23 . V_49 = 0 ;
V_13 -> V_23 . V_50 = 0 ;
V_13 -> V_23 . V_51 = 0 ;
V_13 -> V_23 . V_52 = V_13 -> V_23 . V_35 - 1 ;
V_13 -> V_23 . V_53 = 1 ;
V_13 -> V_23 . V_54 = 1 ;
V_13 -> V_23 . V_55 = 1 ;
V_13 -> V_23 . V_56 = 1 ;
return;
}
static void F_19 ( struct V_57 * V_58 )
{
struct V_12 * V_13 ;
F_14 ( L_2 , V_20 , V_58 ) ;
F_20 (KERN_INFO MOD L_3 ,
DRV_VERSION) ;
V_13 = (struct V_12 * ) F_21 ( sizeof( * V_13 ) ) ;
if ( ! V_13 ) {
F_22 (KERN_ERR MOD L_4 ) ;
return;
}
V_13 -> V_8 . V_59 = V_13 ;
V_13 -> V_8 . V_60 = V_58 ;
F_23 ( & V_61 ) ;
if ( F_24 ( & V_13 -> V_8 ) ) {
F_25 ( & V_61 ) ;
F_22 (KERN_ERR MOD L_5 ) ;
F_26 ( & V_13 -> V_62 ) ;
return;
}
F_13 ( V_13 ) ;
F_27 ( & V_13 -> V_63 , & V_64 ) ;
F_25 ( & V_61 ) ;
if ( F_28 ( V_13 ) ) {
F_22 (KERN_ERR MOD L_6 ) ;
F_29 ( V_58 ) ;
}
F_22 (KERN_INFO MOD L_7 ,
pci_name(rnicp->rdev.rnic_info.pdev)) ;
return;
}
static void F_29 ( struct V_57 * V_58 )
{
struct V_12 * V_65 , * V_66 ;
F_14 ( L_2 , V_20 , V_58 ) ;
F_23 ( & V_61 ) ;
F_30 (dev, tmp, &dev_list, entry) {
if ( V_65 -> V_8 . V_60 == V_58 ) {
V_65 -> V_8 . V_67 = V_68 ;
F_31 () ;
F_32 ( & V_65 -> V_19 ) ;
F_33 ( & V_65 -> V_63 ) ;
F_34 ( V_65 ) ;
F_35 ( & V_65 -> V_8 ) ;
F_36 ( & V_65 -> V_21 ) ;
F_36 ( & V_65 -> V_15 ) ;
F_36 ( & V_65 -> V_22 ) ;
F_26 ( & V_65 -> V_62 ) ;
break;
}
}
F_25 ( & V_61 ) ;
}
static void F_37 ( struct V_57 * V_58 , T_1 V_69 , T_1 V_70 )
{
struct V_71 * V_8 = V_58 -> V_59 ;
struct V_12 * V_13 ;
struct V_72 V_73 ;
T_1 V_74 = V_70 + 1 ;
int V_75 = 0 ;
if ( ! V_8 )
return;
V_13 = F_38 ( V_8 ) ;
switch ( V_69 ) {
case V_76 : {
V_8 -> V_67 = V_68 ;
F_31 () ;
V_73 . V_73 = V_77 ;
V_75 = 1 ;
break;
}
case V_78 : {
V_73 . V_73 = V_79 ;
V_75 = 1 ;
break;
}
case V_80 : {
V_73 . V_73 = V_81 ;
V_75 = 1 ;
break;
}
case V_82 : {
F_6 ( V_13 ) ;
break;
}
case V_83 : {
F_10 ( V_13 , 1 ) ;
break;
}
case V_84 : {
unsigned long V_85 = 1000 ;
unsigned short V_86 ;
F_6 ( V_13 ) ;
F_39 ( & V_86 , 2 ) ;
V_85 += V_86 & 1023 ;
F_40 ( & V_13 -> V_19 ,
F_41 ( V_85 ) ) ;
break;
}
}
if ( V_75 ) {
V_73 . V_87 = & V_13 -> V_62 ;
V_73 . V_88 . V_89 = V_74 ;
F_42 ( & V_73 ) ;
}
return;
}
static int T_2 F_43 ( void )
{
int V_90 ;
V_90 = F_44 () ;
if ( V_90 )
return V_90 ;
V_90 = F_45 () ;
if ( V_90 )
return V_90 ;
F_46 ( V_91 ) ;
F_47 ( & V_92 ) ;
return 0 ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_92 ) ;
F_50 ( V_91 ) ;
F_51 () ;
F_52 () ;
}
