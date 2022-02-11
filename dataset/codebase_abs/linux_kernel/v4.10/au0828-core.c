T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_4 = 0 ;
F_2 ( V_2 , V_5 , 0 , V_3 , & V_4 , 1 ) ;
F_3 ( 8 , L_1 , V_6 , V_3 , V_4 ) ;
return V_4 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_7 )
{
F_3 ( 8 , L_2 , V_6 , V_3 , V_7 ) ;
return F_5 ( V_2 , V_8 , V_7 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 )
{
int V_12 = - V_13 ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_7 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_15 | V_16 |
V_17 ,
V_10 , V_11 , NULL , 0 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( L_3 ,
V_6 , V_12 ) ;
}
}
return V_12 ;
}
static int F_2 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 , unsigned char * V_18 , T_2 V_19 )
{
int V_12 = - V_13 ;
F_10 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_11 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_21 | V_16 | V_17 ,
V_10 , V_11 ,
V_2 -> V_22 , V_19 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( L_4 ,
V_6 , V_12 ) ;
}
memcpy ( V_18 , V_2 -> V_22 , V_19 ) ;
}
F_12 ( & V_2 -> V_20 ) ;
return V_12 ;
}
static void F_13 ( struct V_1 * V_2 )
{
#ifdef F_14
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_26 * V_27 , * V_28 ;
if ( ! V_24 || ! F_15 ( V_24 -> V_29 ) )
return;
F_16 (notify, nextp, &mdev->entity_notify, list) {
if ( V_27 -> V_27 != V_30 )
continue;
F_17 ( V_24 , V_27 ) ;
}
V_2 -> V_25 -> V_31 = NULL ;
V_2 -> V_25 -> V_32 = NULL ;
V_2 -> V_25 -> V_33 = NULL ;
F_18 ( V_2 -> V_25 ) ;
F_19 ( V_2 -> V_25 ) ;
F_20 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
#endif
}
void F_21 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_22 ( V_2 ) ;
F_20 ( V_2 ) ;
}
static void F_23 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_24 ( V_35 ) ;
F_3 ( 1 , L_5 , V_6 ) ;
F_25 ( V_36 , & V_2 -> V_37 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_35 , NULL ) ;
F_10 ( & V_2 -> V_20 ) ;
V_2 -> V_14 = NULL ;
F_12 ( & V_2 -> V_20 ) ;
if ( F_29 ( V_2 ) ) {
return;
}
F_21 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
#ifdef F_14
struct V_23 * V_24 ;
V_24 = F_31 ( sizeof( * V_24 ) , V_40 ) ;
if ( ! V_24 )
return - V_41 ;
if ( ! V_24 -> V_2 )
F_32 ( V_24 , V_39 , V_39 -> V_42 ) ;
V_2 -> V_25 = V_24 ;
#endif
return 0 ;
}
static void V_30 ( struct V_43 * V_44 ,
void * V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
int V_46 ;
struct V_43 * V_47 , * V_48 = NULL , * V_49 = NULL ;
if ( ! V_44 ) {
F_33 (entity, dev->media_dev) {
if ( V_47 -> V_50 == V_51 )
V_48 = V_47 ;
else if ( V_47 -> V_50 == V_52 )
V_49 = V_47 ;
}
goto V_53;
}
switch ( V_44 -> V_50 ) {
case V_51 :
V_48 = V_44 ;
if ( V_2 -> V_49 )
V_49 = V_2 -> V_49 ;
break;
case V_52 :
F_33 (entity, dev->media_dev) {
if ( V_47 -> V_50 == V_51 )
V_48 = V_47 ;
}
V_49 = V_44 ;
break;
default:
break;
}
V_53:
if ( V_49 && V_48 ) {
V_46 = F_34 ( V_49 ,
V_54 ,
V_48 , 0 ,
V_55 ) ;
if ( V_46 )
F_35 ( & V_2 -> V_14 -> V_2 ,
L_6 , V_46 ) ;
}
}
static int F_36 ( struct V_43 * V_47 ,
struct V_56 * V_57 )
{
struct V_43 * V_58 , * V_59 ;
struct V_43 * V_60 ;
struct V_61 * V_62 , * V_63 = NULL ;
int V_46 = 0 ;
struct V_23 * V_24 = V_47 -> V_64 . V_24 ;
struct V_1 * V_2 ;
if ( ! V_24 )
return - V_13 ;
F_10 ( & V_24 -> V_65 ) ;
V_2 = V_24 -> V_31 ;
if ( V_47 -> V_50 == V_66 ) {
V_60 = V_47 ;
V_59 = V_2 -> V_67 ;
} else {
if ( ! V_2 -> V_49 ) {
V_46 = - V_13 ;
goto V_68;
}
V_60 = V_2 -> V_49 ;
if ( V_2 -> V_69 == V_70 )
V_59 = V_2 -> V_67 ;
else if ( V_2 -> V_69 == V_71 ||
V_2 -> V_69 == V_72 )
V_59 = & V_2 -> V_73 [ V_2 -> V_69 ] ;
else {
V_46 = 0 ;
goto V_68;
}
}
if ( V_2 -> V_74 ) {
if ( V_2 -> V_74 -> V_60 -> V_47 == V_60 &&
V_2 -> V_74 -> V_58 -> V_47 == V_59 ) {
if ( V_2 -> V_75 != V_47 &&
V_2 -> V_75 -> V_50 ==
V_76 ) {
F_37 ( L_7 ) ;
V_46 = - V_77 ;
goto V_68;
}
V_46 = 0 ;
goto V_68;
} else {
V_46 = - V_77 ;
goto V_68;
}
}
F_38 (link, &sink->links, list) {
if ( V_62 -> V_60 -> V_47 == V_60 &&
V_62 -> V_58 -> V_47 == V_59 ) {
V_63 = V_62 ;
break;
}
}
if ( ! V_63 ) {
V_46 = - V_13 ;
goto V_68;
}
V_58 = V_63 -> V_58 -> V_47 ;
V_46 = F_39 ( V_63 , V_55 ) ;
if ( V_46 ) {
F_9 ( L_8 ,
V_58 -> V_78 , V_60 -> V_78 , V_46 ) ;
goto V_68;
}
V_46 = F_40 ( V_47 , V_57 ) ;
if ( V_46 ) {
F_9 ( L_9 ,
V_58 -> V_78 , V_47 -> V_78 , V_46 ) ;
V_46 = F_39 ( V_63 , 0 ) ;
F_9 ( L_10 , V_46 ) ;
goto V_68;
}
V_2 -> V_74 = V_63 ;
V_2 -> V_75 = V_47 ;
V_2 -> V_79 = V_58 ;
V_2 -> V_80 = V_60 ;
F_37 ( L_11 ,
V_2 -> V_79 -> V_78 , V_2 -> V_80 -> V_78 ,
V_2 -> V_75 -> V_78 , V_46 ) ;
V_68:
F_12 ( & V_24 -> V_65 ) ;
F_37 ( L_12 ,
V_47 -> V_78 , V_47 -> V_50 , V_46 ) ;
return V_46 ;
}
static void F_41 ( struct V_43 * V_47 )
{
int V_46 = 0 ;
struct V_23 * V_24 = V_47 -> V_64 . V_24 ;
struct V_1 * V_2 ;
if ( ! V_24 )
return;
F_10 ( & V_24 -> V_65 ) ;
V_2 = V_24 -> V_31 ;
if ( ! V_2 -> V_74 ) {
V_46 = - V_13 ;
goto V_68;
}
if ( V_2 -> V_74 -> V_60 -> V_47 == V_2 -> V_80 &&
V_2 -> V_74 -> V_58 -> V_47 == V_2 -> V_79 ) {
if ( V_2 -> V_75 != V_47 )
goto V_68;
F_42 ( V_47 ) ;
V_46 = F_39 ( V_2 -> V_74 , 0 ) ;
if ( V_46 )
F_9 ( L_10 , V_46 ) ;
F_37 ( L_13 ,
V_2 -> V_79 -> V_78 , V_2 -> V_80 -> V_78 ,
V_2 -> V_75 -> V_78 , V_46 ) ;
V_2 -> V_74 = NULL ;
V_2 -> V_75 = NULL ;
V_2 -> V_79 = NULL ;
V_2 -> V_80 = NULL ;
}
V_68:
F_12 ( & V_24 -> V_65 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
#ifdef F_14
int V_46 ;
struct V_43 * V_47 , * V_81 = NULL ;
struct V_61 * V_62 ;
if ( ! V_2 -> V_25 )
return 0 ;
if ( ! F_15 ( V_2 -> V_25 -> V_29 ) ) {
V_46 = F_44 ( V_2 -> V_25 ) ;
if ( V_46 ) {
F_35 ( & V_39 -> V_2 ,
L_14 , V_46 ) ;
return V_46 ;
}
} else {
V_30 ( NULL , ( void * ) V_2 ) ;
}
F_33 (entity, dev->media_dev) {
switch ( V_47 -> V_50 ) {
case V_82 :
V_2 -> V_67 = V_47 ;
break;
case V_52 :
V_2 -> V_49 = V_47 ;
break;
case V_66 :
V_81 = V_47 ;
break;
}
}
if ( V_2 -> V_67 ) {
F_38 (link, &dev->tuner->links, list) {
if ( V_81 && V_62 -> V_60 -> V_47 == V_81 )
F_45 ( V_62 , 0 ) ;
if ( V_2 -> V_49 && V_62 -> V_60 -> V_47 == V_2 -> V_49 )
F_45 ( V_62 , 0 ) ;
}
}
V_2 -> V_83 . V_45 = ( void * ) V_2 ;
V_2 -> V_83 . V_27 = ( void * ) V_30 ;
V_46 = F_46 ( V_2 -> V_25 ,
& V_2 -> V_83 ) ;
if ( V_46 ) {
F_35 ( & V_39 -> V_2 ,
L_15 ,
V_46 ) ;
return V_46 ;
}
V_2 -> V_25 -> V_31 = ( void * ) V_2 ;
V_2 -> V_25 -> V_32 = F_36 ;
V_2 -> V_25 -> V_33 = F_41 ;
#endif
return 0 ;
}
static int F_47 ( struct V_34 * V_35 ,
const struct V_84 * V_85 )
{
int V_86 ;
int V_87 = 0 ;
struct V_1 * V_2 ;
struct V_38 * V_14 = F_48 ( V_35 ) ;
V_86 = V_35 -> V_88 -> V_89 . V_90 ;
if ( V_86 != 0 )
return - V_13 ;
F_3 ( 1 , L_16 , V_6 ,
F_49 ( V_14 -> V_91 . V_92 ) ,
F_49 ( V_14 -> V_91 . V_93 ) ,
V_86 ) ;
if ( V_14 -> V_94 != V_95 && V_96 == 0 ) {
F_9 ( L_17 ) ;
F_9 ( L_18 ) ;
return - V_13 ;
}
V_2 = F_31 ( sizeof( * V_2 ) , V_40 ) ;
if ( V_2 == NULL ) {
F_9 ( L_19 , V_6 ) ;
return - V_41 ;
}
F_50 ( & V_2 -> V_97 ) ;
F_10 ( & V_2 -> V_97 ) ;
F_50 ( & V_2 -> V_20 ) ;
F_50 ( & V_2 -> V_98 . V_97 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_99 = V_85 -> V_100 ;
V_2 -> V_101 = V_102 [ V_2 -> V_99 ] ;
V_87 = F_30 ( V_2 , V_14 ) ;
if ( V_87 ) {
F_9 ( L_20 ,
V_6 ) ;
F_12 ( & V_2 -> V_97 ) ;
F_20 ( V_2 ) ;
return V_87 ;
}
V_87 = F_51 ( V_35 , V_2 ) ;
if ( V_87 ) {
F_52 ( V_2 ) ;
F_12 ( & V_2 -> V_97 ) ;
F_20 ( V_2 ) ;
return V_87 ;
}
F_53 ( V_2 , V_103 , 1 << 4 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
V_87 = F_57 ( V_2 , V_35 ) ;
if ( V_87 ) {
F_9 ( L_21 ,
V_6 ) ;
goto V_104;
}
V_87 = F_58 ( V_2 ) ;
if ( V_87 )
F_9 ( L_22 ,
V_6 ) ;
F_59 ( V_2 ) ;
F_28 ( V_35 , V_2 ) ;
F_60 ( L_23 ,
V_2 -> V_101 . V_78 == NULL ? L_24 : V_2 -> V_101 . V_78 ) ;
F_12 ( & V_2 -> V_97 ) ;
V_87 = F_43 ( V_2 , V_14 ) ;
V_104:
if ( V_87 < 0 )
F_23 ( V_35 ) ;
return V_87 ;
}
static int F_61 ( struct V_34 * V_35 ,
T_4 V_105 )
{
struct V_1 * V_2 = F_24 ( V_35 ) ;
if ( ! V_2 )
return 0 ;
F_60 ( L_25 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_24 ( V_35 ) ;
if ( ! V_2 )
return 0 ;
F_60 ( L_26 ) ;
F_53 ( V_2 , V_103 , 1 << 4 ) ;
F_54 ( V_2 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
static int T_5 F_69 ( void )
{
int V_46 ;
if ( V_106 & 1 )
F_60 ( L_27 , V_6 ) ;
if ( V_106 & 2 )
F_60 ( L_28 , V_6 ) ;
if ( V_106 & 4 )
F_60 ( L_29 , V_6 ) ;
if ( V_106 & 8 )
F_60 ( L_30 ,
V_6 ) ;
if ( V_106 & 16 )
F_60 ( L_31 ,
V_6 ) ;
F_60 ( L_32 ) ;
V_46 = F_70 ( & V_107 ) ;
if ( V_46 )
F_9 ( L_33 , V_46 ) ;
return V_46 ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_107 ) ;
}
