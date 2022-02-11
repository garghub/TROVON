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
if ( V_2 -> V_23 &&
F_15 ( & V_2 -> V_23 -> V_24 ) ) {
V_2 -> V_23 -> V_25 = NULL ;
V_2 -> V_23 -> V_26 = NULL ;
V_2 -> V_23 -> V_27 = NULL ;
F_16 ( V_2 -> V_23 ) ;
F_17 ( V_2 -> V_23 ) ;
F_18 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
#endif
}
void F_19 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_20 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_22 ( V_29 ) ;
F_3 ( 1 , L_5 , V_6 ) ;
F_23 ( V_30 , & V_2 -> V_31 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_26 ( V_29 , NULL ) ;
F_10 ( & V_2 -> V_20 ) ;
V_2 -> V_14 = NULL ;
F_12 ( & V_2 -> V_20 ) ;
if ( F_27 ( V_2 ) ) {
return;
}
F_19 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
#ifdef F_14
struct V_34 * V_35 ;
V_35 = F_29 ( sizeof( * V_35 ) , V_36 ) ;
if ( ! V_35 )
return - V_37 ;
if ( ! V_35 -> V_2 )
F_30 ( V_35 , V_33 , V_33 -> V_38 ) ;
V_2 -> V_23 = V_35 ;
#endif
return 0 ;
}
static void F_31 ( struct V_39 * V_40 ,
void * V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 ;
int V_42 ;
struct V_39 * V_43 , * V_44 = NULL , * V_45 = NULL ;
if ( ! V_40 ) {
F_32 (entity, dev->media_dev) {
if ( V_43 -> V_46 == V_47 )
V_44 = V_43 ;
else if ( V_43 -> V_46 == V_48 )
V_45 = V_43 ;
}
goto V_49;
}
switch ( V_40 -> V_46 ) {
case V_47 :
V_44 = V_40 ;
if ( V_2 -> V_45 )
V_45 = V_2 -> V_45 ;
break;
case V_48 :
F_32 (entity, dev->media_dev) {
if ( V_43 -> V_46 == V_47 )
V_44 = V_43 ;
}
V_45 = V_40 ;
break;
default:
break;
}
V_49:
if ( V_45 && V_44 ) {
V_42 = F_33 ( V_45 ,
V_50 ,
V_44 , 0 ,
V_51 ) ;
if ( V_42 )
F_34 ( & V_2 -> V_14 -> V_2 ,
L_6 , V_42 ) ;
}
}
static int F_35 ( struct V_39 * V_43 ,
struct V_52 * V_53 )
{
struct V_39 * V_54 , * V_55 ;
struct V_39 * V_56 ;
struct V_57 * V_58 , * V_59 = NULL ;
int V_42 = 0 ;
struct V_34 * V_35 = V_43 -> V_60 . V_35 ;
struct V_1 * V_2 ;
if ( ! V_35 )
return - V_13 ;
F_10 ( & V_35 -> V_61 ) ;
V_2 = V_35 -> V_25 ;
if ( V_43 -> V_46 == V_62 ) {
V_56 = V_43 ;
V_55 = V_2 -> V_63 ;
} else {
if ( ! V_2 -> V_45 ) {
V_42 = - V_13 ;
goto V_64;
}
V_56 = V_2 -> V_45 ;
if ( V_2 -> V_65 == V_66 )
V_55 = V_2 -> V_63 ;
else if ( V_2 -> V_65 == V_67 ||
V_2 -> V_65 == V_68 )
V_55 = & V_2 -> V_69 [ V_2 -> V_65 ] ;
else {
V_42 = 0 ;
goto V_64;
}
}
if ( V_2 -> V_70 ) {
if ( V_2 -> V_70 -> V_56 -> V_43 == V_56 &&
V_2 -> V_70 -> V_54 -> V_43 == V_55 ) {
if ( V_2 -> V_71 != V_43 &&
V_2 -> V_71 -> V_46 ==
V_72 ) {
F_36 ( L_7 ) ;
V_42 = - V_73 ;
goto V_64;
}
V_42 = 0 ;
goto V_64;
} else {
V_42 = - V_73 ;
goto V_64;
}
}
F_37 (link, &sink->links, list) {
if ( V_58 -> V_56 -> V_43 == V_56 &&
V_58 -> V_54 -> V_43 == V_55 ) {
V_59 = V_58 ;
break;
}
}
if ( ! V_59 ) {
V_42 = - V_13 ;
goto V_64;
}
V_54 = V_59 -> V_54 -> V_43 ;
V_42 = F_38 ( V_59 , V_51 ) ;
if ( V_42 ) {
F_9 ( L_8 ,
V_54 -> V_74 , V_56 -> V_74 , V_42 ) ;
goto V_64;
}
V_42 = F_39 ( V_43 , V_53 ) ;
if ( V_42 ) {
F_9 ( L_9 ,
V_54 -> V_74 , V_43 -> V_74 , V_42 ) ;
V_42 = F_38 ( V_59 , 0 ) ;
F_9 ( L_10 , V_42 ) ;
goto V_64;
}
V_2 -> V_70 = V_59 ;
V_2 -> V_71 = V_43 ;
V_2 -> V_75 = V_54 ;
V_2 -> V_76 = V_56 ;
F_36 ( L_11 ,
V_2 -> V_75 -> V_74 , V_2 -> V_76 -> V_74 ,
V_2 -> V_71 -> V_74 , V_42 ) ;
V_64:
F_12 ( & V_35 -> V_61 ) ;
F_36 ( L_12 ,
V_43 -> V_74 , V_43 -> V_46 , V_42 ) ;
return V_42 ;
}
static void F_40 ( struct V_39 * V_43 )
{
int V_42 = 0 ;
struct V_34 * V_35 = V_43 -> V_60 . V_35 ;
struct V_1 * V_2 ;
if ( ! V_35 )
return;
F_10 ( & V_35 -> V_61 ) ;
V_2 = V_35 -> V_25 ;
if ( ! V_2 -> V_70 ) {
V_42 = - V_13 ;
goto V_64;
}
if ( V_2 -> V_70 -> V_56 -> V_43 == V_2 -> V_76 &&
V_2 -> V_70 -> V_54 -> V_43 == V_2 -> V_75 ) {
if ( V_2 -> V_71 != V_43 )
goto V_64;
F_41 ( V_43 ) ;
V_42 = F_38 ( V_2 -> V_70 , 0 ) ;
if ( V_42 )
F_9 ( L_10 , V_42 ) ;
F_36 ( L_13 ,
V_2 -> V_75 -> V_74 , V_2 -> V_76 -> V_74 ,
V_2 -> V_71 -> V_74 , V_42 ) ;
V_2 -> V_70 = NULL ;
V_2 -> V_71 = NULL ;
V_2 -> V_75 = NULL ;
V_2 -> V_76 = NULL ;
}
V_64:
F_12 ( & V_35 -> V_61 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
#ifdef F_14
int V_42 ;
struct V_39 * V_43 , * V_77 = NULL ;
struct V_57 * V_58 ;
if ( ! V_2 -> V_23 )
return 0 ;
if ( ! F_15 ( & V_2 -> V_23 -> V_24 ) ) {
V_42 = F_43 ( V_2 -> V_23 ) ;
if ( V_42 ) {
F_34 ( & V_33 -> V_2 ,
L_14 , V_42 ) ;
return V_42 ;
}
} else {
F_31 ( NULL , ( void * ) V_2 ) ;
}
F_32 (entity, dev->media_dev) {
switch ( V_43 -> V_46 ) {
case V_78 :
V_2 -> V_63 = V_43 ;
break;
case V_48 :
V_2 -> V_45 = V_43 ;
break;
case V_62 :
V_77 = V_43 ;
break;
}
}
if ( V_2 -> V_63 ) {
F_37 (link, &dev->tuner->links, list) {
if ( V_77 && V_58 -> V_56 -> V_43 == V_77 )
F_44 ( V_58 , 0 ) ;
if ( V_2 -> V_45 && V_58 -> V_56 -> V_43 == V_2 -> V_45 )
F_44 ( V_58 , 0 ) ;
}
}
V_2 -> V_79 . V_41 = ( void * ) V_2 ;
V_2 -> V_79 . V_80 = ( void * ) F_31 ;
V_42 = F_45 ( V_2 -> V_23 ,
& V_2 -> V_79 ) ;
if ( V_42 ) {
F_34 ( & V_33 -> V_2 ,
L_15 ,
V_42 ) ;
return V_42 ;
}
V_2 -> V_23 -> V_25 = ( void * ) V_2 ;
V_2 -> V_23 -> V_26 = F_35 ;
V_2 -> V_23 -> V_27 = F_40 ;
#endif
return 0 ;
}
static int F_46 ( struct V_28 * V_29 ,
const struct V_81 * V_82 )
{
int V_83 ;
int V_84 = 0 ;
struct V_1 * V_2 ;
struct V_32 * V_14 = F_47 ( V_29 ) ;
V_83 = V_29 -> V_85 -> V_86 . V_87 ;
if ( V_83 != 0 )
return - V_13 ;
F_3 ( 1 , L_16 , V_6 ,
F_48 ( V_14 -> V_88 . V_89 ) ,
F_48 ( V_14 -> V_88 . V_90 ) ,
V_83 ) ;
if ( V_14 -> V_91 != V_92 && V_93 == 0 ) {
F_9 ( L_17 ) ;
F_9 ( L_18 ) ;
return - V_13 ;
}
V_2 = F_29 ( sizeof( * V_2 ) , V_36 ) ;
if ( V_2 == NULL ) {
F_9 ( L_19 , V_6 ) ;
return - V_37 ;
}
F_49 ( & V_2 -> V_94 ) ;
F_10 ( & V_2 -> V_94 ) ;
F_49 ( & V_2 -> V_20 ) ;
F_49 ( & V_2 -> V_95 . V_94 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_96 = V_82 -> V_97 ;
V_2 -> V_98 = V_99 [ V_2 -> V_96 ] ;
V_84 = F_28 ( V_2 , V_14 ) ;
if ( V_84 ) {
F_9 ( L_20 ,
V_6 ) ;
F_12 ( & V_2 -> V_94 ) ;
F_18 ( V_2 ) ;
return V_84 ;
}
V_84 = F_50 ( V_29 , V_2 ) ;
if ( V_84 ) {
F_51 ( V_2 ) ;
F_12 ( & V_2 -> V_94 ) ;
F_18 ( V_2 ) ;
return V_84 ;
}
F_52 ( V_2 , V_100 , 1 << 4 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
V_84 = F_56 ( V_2 , V_29 ) ;
if ( V_84 ) {
F_9 ( L_21 ,
V_6 ) ;
goto V_101;
}
V_84 = F_57 ( V_2 ) ;
if ( V_84 )
F_9 ( L_22 ,
V_6 ) ;
F_58 ( V_2 ) ;
F_26 ( V_29 , V_2 ) ;
F_59 ( L_23 ,
V_2 -> V_98 . V_74 == NULL ? L_24 : V_2 -> V_98 . V_74 ) ;
F_12 ( & V_2 -> V_94 ) ;
V_84 = F_42 ( V_2 , V_14 ) ;
V_101:
if ( V_84 < 0 )
F_21 ( V_29 ) ;
return V_84 ;
}
static int F_60 ( struct V_28 * V_29 ,
T_4 V_102 )
{
struct V_1 * V_2 = F_22 ( V_29 ) ;
if ( ! V_2 )
return 0 ;
F_59 ( L_25 ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_22 ( V_29 ) ;
if ( ! V_2 )
return 0 ;
F_59 ( L_26 ) ;
F_52 ( V_2 , V_100 , 1 << 4 ) ;
F_53 ( V_2 ) ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int T_5 F_68 ( void )
{
int V_42 ;
if ( V_103 & 1 )
F_59 ( L_27 , V_6 ) ;
if ( V_103 & 2 )
F_59 ( L_28 , V_6 ) ;
if ( V_103 & 4 )
F_59 ( L_29 , V_6 ) ;
if ( V_103 & 8 )
F_59 ( L_30 ,
V_6 ) ;
if ( V_103 & 16 )
F_59 ( L_31 ,
V_6 ) ;
F_59 ( L_32 ) ;
V_42 = F_69 ( & V_104 ) ;
if ( V_42 )
F_9 ( L_33 , V_42 ) ;
return V_42 ;
}
static void T_6 F_70 ( void )
{
F_71 ( & V_104 ) ;
}
