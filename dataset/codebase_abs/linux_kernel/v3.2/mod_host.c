static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
struct V_9 * V_10 , * V_11 ;
F_6 (ureq, next,
&hpriv->ureq_link_active,
ureq_link) {
F_7 ( V_8 , L_1 , V_10 ) ;
F_8 ( V_10 ) ;
}
F_6 (ureq, next, &hpriv->ureq_link_free, ureq_link)
F_8 ( V_10 ) ;
}
static struct V_9 * F_9 ( struct V_1 * V_2 ,
struct V_12 * V_12 ,
T_1 V_13 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
if ( F_12 ( & V_2 -> V_4 ) ) {
V_10 = F_13 ( sizeof( struct V_9 ) , V_13 ) ;
if ( V_10 )
F_2 ( & V_10 -> V_16 ) ;
} else {
V_10 = F_14 ( V_2 -> V_4 . V_11 ,
struct V_9 ,
V_16 ) ;
if ( V_10 )
F_15 ( & V_10 -> V_16 ) ;
}
if ( ! V_10 ) {
F_7 ( V_8 , L_2 ) ;
return NULL ;
}
F_16 ( & V_10 -> V_17 ) ;
F_17 ( & V_10 -> V_16 , & V_2 -> V_3 ) ;
V_10 -> V_12 = V_12 ;
return V_10 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_18 * V_17 = & V_10 -> V_17 ;
F_16 ( V_17 ) ;
V_10 -> V_12 = NULL ;
F_15 ( & V_10 -> V_16 ) ;
F_17 ( & V_10 -> V_16 , & V_2 -> V_4 ) ;
}
static int F_19 ( struct V_19 * V_20 )
{
return ! F_12 ( & V_20 -> V_21 ) ;
}
static struct V_19 * F_20 ( struct V_1 * V_2 ,
struct V_12 * V_12 )
{
struct V_19 * V_20 = NULL ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
struct V_22 * V_23 = F_21 ( V_12 ) ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
int V_24 ;
if ( 0 == F_22 ( V_12 -> V_25 ) ) {
V_20 = F_23 ( V_2 ) ;
goto V_26;
}
F_24 (udev, hpriv, i) {
if ( F_25 ( V_20 ) )
continue;
goto V_26;
}
F_7 ( V_8 , L_3 ) ;
return NULL ;
V_26:
if ( F_19 ( V_20 ) )
F_26 ( V_8 , L_4 ) ;
F_2 ( & V_20 -> V_21 ) ;
F_27 ( & V_23 -> V_8 , V_20 ) ;
V_20 -> V_23 = V_23 ;
F_28 ( V_15 ,
F_29 ( V_2 , V_20 ) ,
F_29 ( V_2 , V_20 ) ,
0 ,
V_23 -> V_27 ) ;
F_30 ( V_8 , L_5 , V_28 ,
F_29 ( V_2 , V_20 ) , V_20 ) ;
return V_20 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
struct V_22 * V_23 = F_25 ( V_20 ) ;
F_30 ( V_8 , L_5 , V_28 ,
F_29 ( V_2 , V_20 ) , V_20 ) ;
if ( F_19 ( V_20 ) )
F_26 ( V_8 , L_6 ) ;
F_27 ( & V_23 -> V_8 , NULL ) ;
V_20 -> V_23 = NULL ;
}
struct V_29 * F_32 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_30 * V_31 ,
int V_32 ,
T_1 V_13 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_29 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_25 , * V_37 ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
struct V_38 * V_39 = & V_31 -> V_39 ;
int type , V_24 , V_40 ;
unsigned int V_41 ;
V_32 = ! ! V_32 ;
V_33 = F_13 ( sizeof( struct V_29 ) , V_13 ) ;
if ( ! V_33 ) {
F_7 ( V_8 , L_7 ) ;
return NULL ;
}
if ( F_33 ( V_39 ) ) {
V_37 = F_34 ( V_2 ) ;
goto V_42;
}
type = F_35 ( V_39 ) ;
V_41 = ~ 0 ;
V_37 = NULL ;
F_36 (pipe, priv, i) {
if ( ! F_37 ( V_25 , type ) )
continue;
V_40 = ! ! F_38 ( V_25 ) ;
if ( 0 != ( V_40 - V_32 ) )
continue;
V_35 = V_34 ( V_25 ) ;
if ( V_41 > V_35 -> V_43 ) {
V_41 = V_35 -> V_43 ;
V_37 = V_25 ;
}
}
if ( F_39 ( ! V_37 ) ) {
F_7 ( V_8 , L_8 ) ;
F_8 ( V_33 ) ;
return NULL ;
}
V_42:
V_33 -> V_25 = V_37 ;
V_33 -> V_44 = F_40 ( V_39 ) ;
F_41 ( V_33 ) = V_20 ;
F_42 ( V_31 ) = V_33 ;
V_35 = V_34 ( V_37 ) ;
V_35 -> V_43 ++ ;
F_2 ( & V_33 -> V_45 ) ;
F_17 ( & V_33 -> V_45 , & V_20 -> V_21 ) ;
F_43 ( V_33 -> V_25 ) ;
F_44 ( V_33 -> V_25 ,
F_29 ( V_2 , V_20 ) ,
F_45 ( V_39 ) ,
V_33 -> V_44 ) ;
F_30 ( V_8 , L_9 , V_28 ,
F_29 ( V_2 , V_20 ) ,
F_46 ( V_33 -> V_25 ) , V_33 ) ;
return V_33 ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
struct V_29 * V_33 = F_42 ( V_31 ) ;
struct V_34 * V_35 ;
if ( ! V_33 )
return;
F_30 ( V_8 , L_9 , V_28 ,
F_29 ( V_2 , F_41 ( V_33 ) ) ,
F_46 ( V_33 -> V_25 ) , V_33 ) ;
V_35 = V_34 ( V_33 -> V_25 ) ;
V_35 -> V_43 -- ;
F_15 ( & V_33 -> V_45 ) ;
F_41 ( V_33 ) = NULL ;
F_42 ( V_31 ) = NULL ;
F_8 ( V_33 ) ;
}
static void F_48 ( struct V_14 * V_15 , struct V_18 * V_17 )
{
struct V_9 * V_10 = F_49 ( V_17 ) ;
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_10 -> V_12 ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
F_30 ( V_8 , L_10 , V_28 ) ;
if ( ! V_12 ) {
F_26 ( V_8 , L_11 ) ;
return;
}
V_12 -> V_46 = V_17 -> V_47 ;
F_18 ( V_2 , V_10 ) ;
F_51 ( V_12 ) = NULL ;
F_52 ( V_6 , V_12 ) ;
F_53 ( V_6 , V_12 , 0 ) ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_36 * V_25 ,
struct V_12 * V_12 )
{
struct V_9 * V_10 = F_51 ( V_12 ) ;
struct V_18 * V_17 = & V_10 -> V_17 ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
void * V_48 ;
int V_49 ;
if ( F_55 ( V_12 -> V_25 ) ) {
F_7 ( V_8 , L_12 ) ;
return - V_50 ;
}
if ( F_56 ( V_12 -> V_25 ) )
V_25 -> V_51 = & V_52 ;
else
V_25 -> V_51 = & V_53 ;
V_48 = ( void * ) ( V_12 -> V_54 + V_12 -> V_46 ) ;
V_49 = V_12 -> V_55 - V_12 -> V_46 ;
F_30 ( V_8 , L_10 , V_28 ) ;
F_57 ( V_25 , V_17 , F_48 ,
V_48 , V_49 , ( V_12 -> V_56 & V_57 ) ) ;
F_58 ( V_25 ) ;
return 0 ;
}
static int F_59 ( struct V_12 * V_12 )
{
struct V_58 * V_59 ;
V_59 = (struct V_58 * ) V_12 -> V_60 ;
if ( ( V_61 == V_59 -> V_62 << 8 ) &&
( V_63 == V_59 -> V_64 ) )
return 1 ;
else
return 0 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_12 * V_12 ,
struct V_36 * V_25 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_58 V_65 ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
F_61 ( & V_2 -> V_66 ) ;
memcpy ( & V_65 , V_12 -> V_60 , sizeof( struct V_58 ) ) ;
if ( F_59 ( V_12 ) ) {
V_65 . V_67 = 1 ;
F_30 ( V_8 , L_13 , V_65 . V_67 ) ;
}
F_62 ( V_15 , & V_65 ) ;
F_63 ( & V_2 -> V_66 ) ;
F_30 ( V_8 , L_14 , V_28 ) ;
}
static void F_64 ( struct V_14 * V_15 ,
struct V_18 * V_17 )
{
struct V_9 * V_10 = F_49 ( V_17 ) ;
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_12 * V_12 = V_10 -> V_12 ;
F_18 ( V_2 , V_10 ) ;
F_51 ( V_12 ) = NULL ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_12 * V_12 ,
struct V_36 * V_25 )
{
struct V_9 * V_10 ;
struct V_18 * V_17 ;
V_10 = F_51 ( V_12 ) ;
V_17 = & V_10 -> V_17 ;
if ( F_56 ( V_12 -> V_25 ) )
V_25 -> V_51 = & V_68 ;
else
V_25 -> V_51 = & V_69 ;
F_57 ( V_25 , V_17 ,
F_64 ,
V_12 -> V_54 ,
V_12 -> V_55 ,
( V_12 -> V_56 & V_57 ) ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_12 * V_12 ,
struct V_36 * V_25 )
{
struct V_9 * V_10 ;
struct V_18 * V_17 ;
V_10 = F_9 ( V_2 , V_12 , V_70 ) ;
V_17 = & V_10 -> V_17 ;
if ( F_56 ( V_12 -> V_25 ) )
V_25 -> V_51 = & V_71 ;
else
V_25 -> V_51 = & V_72 ;
F_57 ( V_25 , V_17 ,
F_48 ,
NULL ,
V_12 -> V_55 ,
0 ) ;
}
static int F_67 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_36 * V_25 ,
struct V_12 * V_12 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
F_30 ( V_8 , L_10 , V_28 ) ;
F_60 ( V_2 , V_12 , V_25 ) ;
if ( V_12 -> V_55 )
F_65 ( V_2 , V_12 , V_25 ) ;
F_66 ( V_2 , V_12 , V_25 ) ;
F_58 ( V_25 ) ;
return 0 ;
}
static int F_68 ( struct V_18 * V_17 , int V_73 )
{
return 0 ;
}
static int F_69 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_70 ( struct V_5 * V_6 )
{
}
static int F_71 ( struct V_5 * V_6 ,
struct V_12 * V_12 ,
T_1 V_13 )
{
struct V_1 * V_2 = F_72 ( V_6 ) ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
struct V_22 * V_23 = F_21 ( V_12 ) ;
struct V_30 * V_31 = V_12 -> V_31 ;
struct V_9 * V_10 ;
struct V_19 * V_20 , * V_74 = NULL ;
struct V_36 * V_25 ;
struct V_29 * V_33 ;
int V_75 = F_56 ( V_12 -> V_25 ) ;
int V_76 ;
F_30 ( V_8 , L_15 , V_28 , V_75 ? L_16 : L_17 ) ;
V_76 = F_73 ( V_6 , V_12 ) ;
if ( V_76 )
goto V_77;
V_20 = F_74 ( V_23 ) ;
if ( ! V_20 ) {
V_74 = F_20 ( V_2 , V_12 ) ;
if ( ! V_74 )
goto V_77;
V_20 = V_74 ;
}
V_33 = F_42 ( V_31 ) ;
if ( ! V_33 ) {
V_33 = F_32 ( V_2 , V_20 , V_31 ,
V_75 , V_13 ) ;
if ( ! V_33 )
goto V_78;
}
V_25 = F_75 ( V_33 ) ;
V_10 = F_9 ( V_2 , V_12 , V_13 ) ;
if ( F_39 ( ! V_10 ) ) {
V_76 = - V_79 ;
goto V_80;
}
F_51 ( V_12 ) = V_10 ;
if ( F_76 ( V_12 -> V_25 ) )
F_67 ( V_6 , V_2 , V_25 , V_12 ) ;
else
F_54 ( V_6 , V_25 , V_12 ) ;
return 0 ;
V_80:
F_47 ( V_2 , V_31 ) ;
V_78:
if ( V_74 )
F_31 ( V_2 , V_74 ) ;
V_77:
F_30 ( V_8 , L_18 , V_28 ) ;
return V_76 ;
}
static int F_77 ( struct V_5 * V_6 , struct V_12 * V_12 , int V_81 )
{
struct V_1 * V_2 = F_72 ( V_6 ) ;
struct V_9 * V_10 = F_51 ( V_12 ) ;
if ( V_10 ) {
F_18 ( V_2 , V_10 ) ;
F_51 ( V_12 ) = NULL ;
}
return 0 ;
}
static void F_78 ( struct V_5 * V_6 ,
struct V_30 * V_31 )
{
struct V_29 * V_33 = F_42 ( V_31 ) ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
if ( ! V_33 )
return;
V_20 = F_41 ( V_33 ) ;
V_2 = F_72 ( V_6 ) ;
F_47 ( V_2 , V_31 ) ;
V_31 -> V_82 = NULL ;
if ( ! F_19 ( V_20 ) )
F_31 ( V_2 , V_20 ) ;
}
static int F_79 ( struct V_5 * V_6 , char * V_48 )
{
struct V_1 * V_2 = F_72 ( V_6 ) ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
int V_83 = 1 ;
if ( F_80 ( V_2 ) & 0xFFFF0000 )
* V_48 = ( 1 << V_83 ) ;
else
* V_48 = 0 ;
F_30 ( V_8 , L_19 , V_28 , * V_48 ) ;
return ! ! ( * V_48 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
T_2 V_84 , T_2 V_67 ,
T_2 V_85 , char * V_48 , T_2 V_86 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
switch ( V_67 ) {
case V_87 :
case V_88 :
F_30 ( V_8 , L_20 , V_28 ) ;
return 0 ;
}
return - V_89 ;
}
static int F_82 ( struct V_1 * V_2 ,
T_2 V_84 , T_2 V_67 ,
T_2 V_85 , char * V_48 , T_2 V_86 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
int V_90 = ( V_84 == V_91 ) ;
int V_27 , V_24 , V_92 = 128 ;
int V_83 = 1 ;
if ( V_85 > V_83 || V_86 != 0 )
return - V_89 ;
switch ( V_67 ) {
case V_93 :
F_83 ( V_15 , V_90 ) ;
F_30 ( V_8 , L_21 , V_28 ) ;
break;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
F_30 ( V_8 , L_22 , V_28 ) ;
break;
case V_101 :
if ( ! V_90 )
break;
F_84 ( V_2 ,
V_102 |
V_103 ) ;
F_85 ( V_15 ) ;
F_86 ( 20 ) ;
F_87 ( V_15 ) ;
for ( V_24 = 0 ; V_24 < V_92 ; V_24 ++ ) {
switch ( F_88 ( V_15 ) ) {
case V_104 :
V_27 = V_103 ;
goto V_105;
case V_106 :
V_27 = V_102 ;
goto V_105;
case V_107 :
V_27 = 0 ;
goto V_105;
}
F_86 ( 20 ) ;
}
return - V_89 ;
V_105:
F_89 ( V_2 , V_27 ) ;
F_89 ( V_2 , V_108 ) ;
F_30 ( V_8 , L_23 ,
V_28 , V_27 ) ;
return 0 ;
default:
return - V_89 ;
}
if ( V_90 )
F_89 ( V_2 , ( 1 << V_67 ) ) ;
else
F_84 ( V_2 , ( 1 << V_67 ) ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
T_2 V_84 , T_2 V_67 ,
T_2 V_85 , char * V_48 , T_2 V_86 )
{
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_109 * V_39 = (struct V_109 * ) V_48 ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
int V_83 = 1 ;
switch ( V_84 ) {
case V_110 :
F_30 ( V_8 , L_24 , V_28 ) ;
* V_48 = 0x00 ;
break;
case V_111 :
if ( V_85 != V_83 )
return - V_89 ;
F_30 ( V_8 , L_25 , V_28 ) ;
* ( V_112 * ) V_48 = F_91 ( F_80 ( V_2 ) ) ;
break;
case V_113 :
V_39 -> V_114 = 0x29 ;
V_39 -> V_115 = 0 ;
V_39 -> V_116 = V_83 ;
V_39 -> V_117 = 9 ;
V_39 -> V_118 = 0 ;
V_39 -> V_119 = F_92 ( 0x0011 ) ;
V_39 -> V_120 . V_121 . V_122 [ 0 ] = ( V_83 << 1 ) ;
V_39 -> V_120 . V_121 . V_122 [ 1 ] = ~ 0 ;
F_30 ( V_8 , L_26 , V_28 ) ;
break;
}
return 0 ;
}
static int F_93 ( struct V_5 * V_6 , T_2 V_84 , T_2 V_67 ,
T_2 V_85 , char * V_48 , T_2 V_86 )
{
struct V_1 * V_2 = F_72 ( V_6 ) ;
struct V_14 * V_15 = F_10 ( V_2 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
int V_76 = - V_89 ;
switch ( V_84 ) {
case V_123 :
case V_124 :
V_76 = F_81 ( V_2 , V_84 ,
V_67 , V_85 , V_48 , V_86 ) ;
break;
case V_91 :
case V_125 :
V_76 = F_82 ( V_2 , V_84 ,
V_67 , V_85 , V_48 , V_86 ) ;
break;
case V_110 :
case V_111 :
case V_113 :
V_76 = F_90 ( V_2 , V_84 ,
V_67 , V_85 , V_48 , V_86 ) ;
break;
}
F_30 ( V_8 , L_27 ,
V_84 , V_76 , F_80 ( V_2 ) ) ;
return V_76 ;
}
static int F_94 ( struct V_14 * V_15 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
F_30 ( V_8 , L_28 ) ;
F_89 ( V_2 , V_128 ) ;
F_89 ( V_2 , V_129 << 16 ) ;
return 0 ;
}
static int F_95 ( struct V_14 * V_15 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
F_30 ( V_8 , L_29 ) ;
F_84 ( V_2 , V_128 ) ;
F_89 ( V_2 , V_129 << 16 ) ;
return 0 ;
}
static int F_96 ( struct V_14 * V_15 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
F_30 ( V_8 , L_30 ) ;
F_97 ( & V_2 -> V_66 ) ;
return 0 ;
}
static int F_98 ( struct V_14 * V_15 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
F_30 ( V_8 , L_31 ) ;
F_97 ( & V_2 -> V_66 ) ;
return 0 ;
}
static void F_99 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_34 * V_130 = V_2 -> V_130 ;
struct V_36 * V_25 ;
T_3 * V_131 = F_100 ( V_15 , V_131 ) ;
int V_132 = F_100 ( V_15 , V_132 ) ;
int V_133 , V_40 , V_24 ;
V_133 = V_134 ;
for ( V_24 = 0 ; V_24 < V_132 ; V_24 ++ ) {
V_130 [ V_24 ] . V_43 = 0 ;
V_40 = ( V_131 [ V_24 ] == V_133 ) ;
V_133 = V_131 [ V_24 ] ;
if ( V_134 == V_131 [ V_24 ] ) {
V_25 = F_101 ( V_15 ) ;
F_34 ( V_2 ) = V_25 ;
} else {
V_25 = F_102 ( V_15 ,
V_131 [ V_24 ] ,
V_40 ) ;
}
V_25 -> V_135 = V_130 + V_24 ;
}
}
static int F_103 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_136 * V_137 = F_104 ( V_15 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
int V_76 ;
V_76 = F_105 ( V_6 , 0 , 0 ) ;
if ( V_76 < 0 )
return 0 ;
F_106 ( V_15 ,
F_68 ) ;
F_107 ( V_15 ) ;
F_99 ( V_15 ) ;
F_108 ( V_15 , 1 ) ;
F_109 ( V_15 , 1 ) ;
F_110 ( V_15 , 1 ) ;
V_137 -> V_138 = F_94 ;
V_137 -> V_139 = F_95 ;
V_137 -> V_140 = F_96 ;
V_137 -> V_141 = F_98 ;
F_111 ( V_15 , V_137 ) ;
F_30 ( V_8 , L_32 ) ;
return V_76 ;
}
static int F_112 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_136 * V_137 = F_104 ( V_15 ) ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
V_137 -> V_138 = NULL ;
V_137 -> V_139 = NULL ;
V_137 -> V_140 = NULL ;
V_137 -> V_141 = NULL ;
F_111 ( V_15 , V_137 ) ;
F_113 ( V_6 ) ;
F_108 ( V_15 , 0 ) ;
F_109 ( V_15 , 0 ) ;
F_110 ( V_15 , 0 ) ;
F_30 ( V_8 , L_33 ) ;
return 0 ;
}
int F_114 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_34 * V_130 ;
struct V_19 * V_20 ;
struct V_7 * V_8 = F_11 ( V_15 ) ;
int V_132 = F_100 ( V_15 , V_132 ) ;
int V_24 ;
V_6 = F_115 ( & V_142 , V_8 , V_143 ) ;
if ( ! V_6 ) {
F_7 ( V_8 , L_34 ) ;
return - V_79 ;
}
V_6 -> V_144 = 1 ;
V_130 = F_13 ( sizeof( * V_130 ) * V_132 , V_70 ) ;
if ( ! V_130 ) {
F_7 ( V_8 , L_35 ) ;
goto V_145;
}
V_2 = F_72 ( V_6 ) ;
F_116 ( V_15 , & V_2 -> V_137 , V_146 ) ;
V_2 -> V_137 . V_147 = L_36 ;
V_2 -> V_137 . V_148 = F_103 ;
V_2 -> V_137 . V_149 = F_112 ;
V_2 -> V_130 = V_130 ;
V_2 -> V_132 = V_132 ;
F_1 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 (udev, hpriv, i) {
V_20 -> V_23 = NULL ;
F_2 ( & V_20 -> V_21 ) ;
}
F_119 ( V_8 , L_37 ) ;
return 0 ;
V_145:
F_120 ( V_6 ) ;
return - V_79 ;
}
int F_121 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_50 ( V_15 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
F_3 ( V_2 ) ;
F_120 ( V_6 ) ;
return 0 ;
}
