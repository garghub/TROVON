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
F_20 ( L_3 , V_59 ) ;
V_13 = (struct V_12 * ) F_21 ( sizeof( * V_13 ) ) ;
if ( ! V_13 ) {
F_22 ( L_4 ) ;
return;
}
V_13 -> V_8 . V_60 = V_13 ;
V_13 -> V_8 . V_61 = V_58 ;
F_23 ( & V_62 ) ;
if ( F_24 ( & V_13 -> V_8 ) ) {
F_25 ( & V_62 ) ;
F_22 ( L_5 ) ;
F_26 ( & V_13 -> V_63 ) ;
return;
}
F_13 ( V_13 ) ;
F_27 ( & V_13 -> V_64 , & V_65 ) ;
F_25 ( & V_62 ) ;
if ( F_28 ( V_13 ) ) {
F_22 ( L_6 ) ;
F_29 ( V_58 ) ;
}
F_30 ( L_7 ,
F_31 ( V_13 -> V_8 . V_66 . V_67 ) ) ;
return;
}
static void F_29 ( struct V_57 * V_58 )
{
struct V_12 * V_68 , * V_69 ;
F_14 ( L_2 , V_20 , V_58 ) ;
F_23 ( & V_62 ) ;
F_32 (dev, tmp, &dev_list, entry) {
if ( V_68 -> V_8 . V_61 == V_58 ) {
V_68 -> V_8 . V_70 = V_71 ;
F_33 () ;
F_34 ( & V_68 -> V_19 ) ;
F_35 ( & V_68 -> V_64 ) ;
F_36 ( V_68 ) ;
F_37 ( & V_68 -> V_8 ) ;
F_38 ( & V_68 -> V_21 ) ;
F_38 ( & V_68 -> V_15 ) ;
F_38 ( & V_68 -> V_22 ) ;
F_26 ( & V_68 -> V_63 ) ;
break;
}
}
F_25 ( & V_62 ) ;
}
static void F_39 ( struct V_57 * V_58 , T_1 V_72 , T_1 V_73 )
{
struct V_74 * V_8 = V_58 -> V_60 ;
struct V_12 * V_13 ;
struct V_75 V_76 ;
T_1 V_77 = V_73 + 1 ;
int V_78 = 0 ;
if ( ! V_8 )
return;
V_13 = F_40 ( V_8 ) ;
switch ( V_72 ) {
case V_79 : {
V_8 -> V_70 = V_71 ;
F_33 () ;
V_76 . V_76 = V_80 ;
V_78 = 1 ;
break;
}
case V_81 : {
V_76 . V_76 = V_82 ;
V_78 = 1 ;
break;
}
case V_83 : {
V_76 . V_76 = V_84 ;
V_78 = 1 ;
break;
}
case V_85 : {
F_6 ( V_13 ) ;
break;
}
case V_86 : {
F_10 ( V_13 , 1 ) ;
break;
}
case V_87 : {
unsigned long V_88 = 1000 ;
unsigned short V_89 ;
F_6 ( V_13 ) ;
F_41 ( & V_89 , 2 ) ;
V_88 += V_89 & 1023 ;
F_42 ( & V_13 -> V_19 ,
F_43 ( V_88 ) ) ;
break;
}
}
if ( V_78 ) {
V_76 . V_90 = & V_13 -> V_63 ;
V_76 . V_91 . V_92 = V_77 ;
F_44 ( & V_76 ) ;
}
return;
}
static int T_2 F_45 ( void )
{
int V_93 ;
V_93 = F_46 () ;
if ( V_93 )
return V_93 ;
V_93 = F_47 () ;
if ( V_93 )
return V_93 ;
F_48 ( V_94 ) ;
F_49 ( & V_95 ) ;
return 0 ;
}
static void T_3 F_50 ( void )
{
F_51 ( & V_95 ) ;
F_52 ( V_94 ) ;
F_53 () ;
F_54 () ;
}
