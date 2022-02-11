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
F_10 ( & V_24 -> V_31 ) ;
V_2 -> V_25 -> V_32 = NULL ;
V_2 -> V_25 -> V_33 = NULL ;
V_2 -> V_25 -> V_34 = NULL ;
F_12 ( & V_24 -> V_31 ) ;
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
static void F_23 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_24 ( V_36 ) ;
F_3 ( 1 , L_5 , V_6 ) ;
F_25 ( V_37 , & V_2 -> V_38 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_36 , NULL ) ;
F_10 ( & V_2 -> V_20 ) ;
V_2 -> V_14 = NULL ;
F_12 ( & V_2 -> V_20 ) ;
if ( F_29 ( V_2 ) ) {
return;
}
F_21 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
#ifdef F_14
struct V_23 * V_24 ;
V_24 = F_31 ( sizeof( * V_24 ) , V_41 ) ;
if ( ! V_24 )
return - V_42 ;
if ( ! V_24 -> V_2 )
F_32 ( V_24 , V_40 , V_40 -> V_43 ) ;
V_2 -> V_25 = V_24 ;
#endif
return 0 ;
}
static void V_30 ( struct V_44 * V_45 ,
void * V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_46 ;
int V_47 ;
struct V_44 * V_48 , * V_49 = NULL , * V_50 = NULL ;
if ( ! V_45 ) {
F_33 (entity, dev->media_dev) {
if ( V_48 -> V_51 == V_52 )
V_49 = V_48 ;
else if ( V_48 -> V_51 == V_53 )
V_50 = V_48 ;
}
goto V_54;
}
switch ( V_45 -> V_51 ) {
case V_52 :
V_49 = V_45 ;
if ( V_2 -> V_50 )
V_50 = V_2 -> V_50 ;
break;
case V_53 :
F_33 (entity, dev->media_dev) {
if ( V_48 -> V_51 == V_52 )
V_49 = V_48 ;
}
V_50 = V_45 ;
break;
default:
break;
}
V_54:
if ( V_50 && V_49 ) {
V_47 = F_34 ( V_50 ,
V_55 ,
V_49 , 0 ,
V_56 ) ;
if ( V_47 )
F_35 ( & V_2 -> V_14 -> V_2 ,
L_6 , V_47 ) ;
}
}
static int F_36 ( struct V_44 * V_48 ,
struct V_57 * V_58 )
{
struct V_44 * V_59 , * V_60 ;
struct V_44 * V_61 ;
struct V_62 * V_63 , * V_64 = NULL ;
int V_47 = 0 ;
struct V_23 * V_24 = V_48 -> V_65 . V_24 ;
struct V_1 * V_2 ;
if ( ! V_24 )
return - V_13 ;
V_2 = V_24 -> V_32 ;
if ( V_48 -> V_51 == V_66 ) {
V_61 = V_48 ;
V_60 = V_2 -> V_67 ;
} else {
if ( ! V_2 -> V_50 ) {
V_47 = - V_13 ;
goto V_68;
}
V_61 = V_2 -> V_50 ;
if ( V_2 -> V_69 == V_70 )
V_60 = V_2 -> V_67 ;
else if ( V_2 -> V_69 == V_71 ||
V_2 -> V_69 == V_72 )
V_60 = & V_2 -> V_73 [ V_2 -> V_69 ] ;
else {
V_47 = 0 ;
goto V_68;
}
}
if ( V_2 -> V_74 ) {
if ( V_2 -> V_74 -> V_61 -> V_48 == V_61 &&
V_2 -> V_74 -> V_59 -> V_48 == V_60 ) {
if ( V_2 -> V_75 != V_48 &&
V_2 -> V_75 -> V_51 ==
V_76 ) {
F_37 ( L_7 ) ;
V_47 = - V_77 ;
goto V_68;
}
V_47 = 0 ;
goto V_68;
} else {
V_47 = - V_77 ;
goto V_68;
}
}
F_38 (link, &sink->links, list) {
if ( V_63 -> V_61 -> V_48 == V_61 &&
V_63 -> V_59 -> V_48 == V_60 ) {
V_64 = V_63 ;
break;
}
}
if ( ! V_64 ) {
V_47 = - V_13 ;
goto V_68;
}
V_59 = V_64 -> V_59 -> V_48 ;
V_47 = F_39 ( V_64 , V_56 ) ;
if ( V_47 ) {
F_9 ( L_8 ,
V_59 -> V_78 , V_61 -> V_78 , V_47 ) ;
goto V_68;
}
V_47 = F_40 ( V_48 , V_58 ) ;
if ( V_47 ) {
F_9 ( L_9 ,
V_59 -> V_78 , V_48 -> V_78 , V_47 ) ;
V_47 = F_39 ( V_64 , 0 ) ;
F_9 ( L_10 , V_47 ) ;
goto V_68;
}
V_2 -> V_74 = V_64 ;
V_2 -> V_75 = V_48 ;
V_2 -> V_79 = V_59 ;
V_2 -> V_80 = V_61 ;
F_37 ( L_11 ,
V_2 -> V_79 -> V_78 , V_2 -> V_80 -> V_78 ,
V_2 -> V_75 -> V_78 , V_47 ) ;
V_68:
F_37 ( L_12 ,
V_48 -> V_78 , V_48 -> V_51 , V_47 ) ;
return V_47 ;
}
static void F_41 ( struct V_44 * V_48 )
{
int V_47 = 0 ;
struct V_23 * V_24 = V_48 -> V_65 . V_24 ;
struct V_1 * V_2 ;
if ( ! V_24 )
return;
V_2 = V_24 -> V_32 ;
if ( ! V_2 -> V_74 )
return;
if ( V_2 -> V_74 -> V_61 -> V_48 == V_2 -> V_80 &&
V_2 -> V_74 -> V_59 -> V_48 == V_2 -> V_79 ) {
if ( V_2 -> V_75 != V_48 )
return;
F_42 ( V_48 ) ;
V_47 = F_39 ( V_2 -> V_74 , 0 ) ;
if ( V_47 )
F_9 ( L_10 , V_47 ) ;
F_37 ( L_13 ,
V_2 -> V_79 -> V_78 , V_2 -> V_80 -> V_78 ,
V_2 -> V_75 -> V_78 , V_47 ) ;
V_2 -> V_74 = NULL ;
V_2 -> V_75 = NULL ;
V_2 -> V_79 = NULL ;
V_2 -> V_80 = NULL ;
}
}
static int F_43 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
#ifdef F_14
int V_47 ;
struct V_44 * V_48 , * V_81 = NULL ;
struct V_62 * V_63 ;
if ( ! V_2 -> V_25 )
return 0 ;
if ( ! F_15 ( V_2 -> V_25 -> V_29 ) ) {
V_47 = F_44 ( V_2 -> V_25 ) ;
if ( V_47 ) {
F_35 ( & V_40 -> V_2 ,
L_14 , V_47 ) ;
return V_47 ;
}
} else {
V_30 ( NULL , ( void * ) V_2 ) ;
}
F_33 (entity, dev->media_dev) {
switch ( V_48 -> V_51 ) {
case V_82 :
V_2 -> V_67 = V_48 ;
break;
case V_53 :
V_2 -> V_50 = V_48 ;
break;
case V_66 :
V_81 = V_48 ;
break;
}
}
if ( V_2 -> V_67 ) {
F_38 (link, &dev->tuner->links, list) {
if ( V_81 && V_63 -> V_61 -> V_48 == V_81 )
F_45 ( V_63 , 0 ) ;
if ( V_2 -> V_50 && V_63 -> V_61 -> V_48 == V_2 -> V_50 )
F_45 ( V_63 , 0 ) ;
}
}
V_2 -> V_83 . V_46 = ( void * ) V_2 ;
V_2 -> V_83 . V_27 = ( void * ) V_30 ;
V_47 = F_46 ( V_2 -> V_25 ,
& V_2 -> V_83 ) ;
if ( V_47 ) {
F_35 ( & V_40 -> V_2 ,
L_15 ,
V_47 ) ;
return V_47 ;
}
F_10 ( & V_2 -> V_25 -> V_31 ) ;
V_2 -> V_25 -> V_32 = ( void * ) V_2 ;
V_2 -> V_25 -> V_33 = F_36 ;
V_2 -> V_25 -> V_34 = F_41 ;
F_12 ( & V_2 -> V_25 -> V_31 ) ;
#endif
return 0 ;
}
static int F_47 ( struct V_35 * V_36 ,
const struct V_84 * V_85 )
{
int V_86 ;
int V_87 = 0 ;
struct V_1 * V_2 ;
struct V_39 * V_14 = F_48 ( V_36 ) ;
V_86 = V_36 -> V_88 -> V_89 . V_90 ;
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
V_2 = F_31 ( sizeof( * V_2 ) , V_41 ) ;
if ( V_2 == NULL ) {
F_9 ( L_19 , V_6 ) ;
return - V_42 ;
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
V_87 = F_51 ( V_36 , V_2 ) ;
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
V_87 = F_57 ( V_2 , V_36 ) ;
if ( V_87 ) {
F_9 ( L_21 ,
V_6 ) ;
F_12 ( & V_2 -> V_97 ) ;
F_20 ( V_2 ) ;
goto V_104;
}
V_87 = F_58 ( V_2 ) ;
if ( V_87 )
F_9 ( L_22 ,
V_6 ) ;
F_59 ( V_2 ) ;
F_28 ( V_36 , V_2 ) ;
F_60 ( L_23 ,
V_2 -> V_101 . V_78 == NULL ? L_24 : V_2 -> V_101 . V_78 ) ;
F_12 ( & V_2 -> V_97 ) ;
V_87 = F_43 ( V_2 , V_14 ) ;
V_104:
if ( V_87 < 0 )
F_23 ( V_36 ) ;
return V_87 ;
}
static int F_61 ( struct V_35 * V_36 ,
T_4 V_105 )
{
struct V_1 * V_2 = F_24 ( V_36 ) ;
if ( ! V_2 )
return 0 ;
F_60 ( L_25 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_24 ( V_36 ) ;
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
int V_47 ;
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
V_47 = F_70 ( & V_107 ) ;
if ( V_47 )
F_9 ( L_33 , V_47 ) ;
return V_47 ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_107 ) ;
}
