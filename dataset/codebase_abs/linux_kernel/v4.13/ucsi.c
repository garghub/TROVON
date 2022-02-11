static inline int F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_3 )
return V_1 -> V_2 -> V_3 ( V_1 -> V_2 ) ;
return 0 ;
}
static int F_2 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
int V_6 ;
F_3 ( V_5 ) ;
F_4 ( V_7 , & V_1 -> V_8 ) ;
V_6 = V_1 -> V_2 -> V_9 ( V_1 -> V_2 , V_5 ) ;
if ( V_6 )
goto V_10;
if ( ! F_5 ( & V_1 -> V_11 ,
F_6 ( V_12 ) ) ) {
F_7 ( V_1 -> V_13 , L_1 ) ;
V_6 = - V_14 ;
}
V_10:
F_8 ( V_7 , & V_1 -> V_8 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_15 )
{
struct V_4 V_5 ;
int V_6 ;
F_10 ( V_15 ) ;
F_4 ( V_16 , & V_1 -> V_8 ) ;
F_11 ( V_5 , V_15 ) ;
V_6 = V_1 -> V_2 -> V_9 ( V_1 -> V_2 , & V_5 ) ;
if ( V_6 )
goto V_17;
if ( V_15 == V_18 )
goto V_17;
if ( ! F_5 ( & V_1 -> V_11 ,
F_6 ( V_12 ) ) )
V_6 = - V_14 ;
V_17:
F_8 ( V_16 , & V_1 -> V_8 ) ;
if ( V_6 )
F_12 ( V_1 -> V_13 , L_2 , V_19 ) ;
return V_6 ;
}
static int F_13 ( struct V_1 * V_1 , struct V_4 * V_5 ,
void * V_20 , T_2 V_21 )
{
struct V_4 V_22 ;
T_1 V_23 ;
T_3 error ;
int V_6 ;
V_6 = F_2 ( V_1 , V_5 ) ;
if ( V_6 )
goto V_24;
switch ( V_1 -> V_25 ) {
case V_26 :
V_6 = F_1 ( V_1 ) ;
if ( V_6 )
F_7 ( V_1 -> V_13 , L_3 , V_19 ) ;
if ( V_20 )
memcpy ( V_20 , V_1 -> V_2 -> V_20 -> V_27 , V_21 ) ;
V_23 = V_1 -> V_2 -> V_20 -> V_28 . V_23 ;
V_6 = F_9 ( V_1 , V_29 ) ;
if ( ! V_6 )
V_6 = V_23 ;
break;
case V_30 :
V_6 = - V_31 ;
break;
case V_32 :
V_6 = F_9 ( V_1 , V_29 ) ;
if ( V_6 )
break;
V_22 . V_33 = 0 ;
V_22 . V_9 . V_9 = V_34 ;
V_6 = F_2 ( V_1 , & V_22 ) ;
if ( V_6 ) {
F_12 ( V_1 -> V_13 , L_4 ) ;
break;
}
memcpy ( & error , V_1 -> V_2 -> V_20 -> V_27 , sizeof( error ) ) ;
if ( F_14 ( V_1 -> V_25 == V_32 ) ) {
V_6 = - V_35 ;
break;
}
V_6 = F_9 ( V_1 , V_29 ) ;
if ( V_6 )
break;
switch ( error ) {
case V_36 :
V_6 = - V_37 ;
break;
case V_38 :
V_6 = - V_39 ;
break;
case V_40 :
V_6 = - V_41 ;
break;
case V_42 :
F_7 ( V_1 -> V_13 , L_5 ) ;
V_6 = - V_43 ;
break;
case V_44 :
case V_45 :
case V_46 :
F_7 ( V_1 -> V_13 ,
L_6 ,
V_19 , error ) ;
V_6 = - V_47 ;
break;
default:
F_7 ( V_1 -> V_13 ,
L_7 , V_19 ) ;
V_6 = - V_48 ;
break;
}
break;
}
V_24:
F_15 ( V_5 , V_6 ) ;
return V_6 ;
}
static void F_16 ( struct V_49 * V_50 )
{
switch ( V_50 -> V_25 . V_51 ) {
case V_52 :
F_17 ( V_50 -> V_53 , V_54 ) ;
break;
case V_55 :
F_17 ( V_50 -> V_53 , V_56 ) ;
break;
case V_57 :
F_17 ( V_50 -> V_53 , V_58 ) ;
break;
default:
F_17 ( V_50 -> V_53 , V_59 ) ;
break;
}
}
static int F_18 ( struct V_49 * V_50 )
{
struct V_60 V_61 ;
if ( V_50 -> V_61 )
return 0 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
switch ( V_50 -> V_25 . V_62 ) {
case V_63 :
V_61 . V_64 = V_65 ;
break;
case V_66 :
V_61 . V_64 = V_67 ;
break;
default:
break;
}
V_61 . V_68 = V_50 -> V_25 . V_51 == V_52 ;
V_50 -> V_61 = F_19 ( V_50 -> V_53 , & V_61 ) ;
if ( ! V_50 -> V_61 ) {
F_12 ( V_50 -> V_1 -> V_13 , L_8 ,
V_50 -> V_69 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_20 ( struct V_49 * V_50 )
{
F_21 ( V_50 -> V_61 ) ;
V_50 -> V_61 = NULL ;
}
static void F_22 ( struct V_70 * V_71 )
{
struct V_49 * V_50 = F_23 ( V_71 , struct V_49 ,
V_71 ) ;
struct V_1 * V_1 = V_50 -> V_1 ;
struct V_4 V_5 ;
int V_6 ;
F_24 ( & V_1 -> V_72 ) ;
F_25 ( V_5 , V_50 -> V_69 ) ;
V_6 = F_13 ( V_1 , & V_5 , & V_50 -> V_25 , sizeof( V_50 -> V_25 ) ) ;
if ( V_6 < 0 ) {
F_12 ( V_1 -> V_13 , L_9 ,
V_19 , V_6 ) ;
goto V_73;
}
if ( V_50 -> V_25 . V_74 & V_75 )
F_16 ( V_50 ) ;
if ( V_50 -> V_25 . V_74 & V_76 ) {
F_26 ( V_50 -> V_53 , V_50 -> V_25 . V_77 ) ;
if ( ! F_27 ( & V_50 -> V_11 ) )
V_11 ( & V_50 -> V_11 ) ;
}
if ( V_50 -> V_25 . V_74 & V_78 ) {
switch ( V_50 -> V_25 . V_62 ) {
case V_79 :
F_28 ( V_50 -> V_53 , V_80 ) ;
break;
case V_81 :
F_28 ( V_50 -> V_53 , V_82 ) ;
break;
default:
break;
}
if ( ! F_27 ( & V_50 -> V_11 ) )
V_11 ( & V_50 -> V_11 ) ;
}
if ( V_50 -> V_25 . V_74 & V_83 ) {
if ( V_50 -> V_25 . V_84 )
F_18 ( V_50 ) ;
else
F_20 ( V_50 ) ;
}
V_6 = F_9 ( V_1 , V_18 ) ;
if ( V_6 )
F_12 ( V_1 -> V_13 , L_10 , V_19 , V_6 ) ;
F_29 ( V_50 -> V_69 , & V_50 -> V_25 ) ;
V_73:
F_8 ( V_85 , & V_1 -> V_8 ) ;
F_30 ( & V_1 -> V_72 ) ;
}
void F_31 ( struct V_1 * V_1 )
{
struct V_86 * V_28 ;
F_1 ( V_1 ) ;
V_28 = & V_1 -> V_2 -> V_20 -> V_28 ;
if ( V_28 -> error )
V_1 -> V_25 = V_32 ;
else if ( V_28 -> V_87 )
V_1 -> V_25 = V_30 ;
else
V_1 -> V_25 = V_26 ;
if ( V_28 -> V_88 && F_32 ( V_7 , & V_1 -> V_8 ) ) {
V_11 ( & V_1 -> V_11 ) ;
} else if ( V_28 -> V_89 && F_32 ( V_16 , & V_1 -> V_8 ) ) {
V_11 ( & V_1 -> V_11 ) ;
} else if ( V_28 -> V_90 ) {
struct V_49 * V_50 ;
V_50 = & V_1 -> V_91 [ V_28 -> V_90 - 1 ] ;
if ( ! F_33 ( V_85 , & V_1 -> V_8 ) )
F_34 ( & V_50 -> V_71 ) ;
}
F_35 ( V_1 -> V_2 -> V_20 -> V_92 ) ;
}
static int F_36 ( struct V_49 * V_50 , bool V_93 )
{
struct V_4 V_5 ;
F_37 ( V_5 , V_50 , V_93 ) ;
return F_13 ( V_50 -> V_1 , & V_5 , NULL , 0 ) ;
}
static int F_38 ( struct V_1 * V_1 )
{
struct V_4 V_5 ;
unsigned long V_94 ;
int V_6 ;
V_5 . V_33 = 0 ;
V_5 . V_9 . V_9 = V_95 ;
F_3 ( & V_5 ) ;
V_6 = V_1 -> V_2 -> V_9 ( V_1 -> V_2 , & V_5 ) ;
if ( V_6 )
goto V_24;
V_94 = V_96 + F_6 ( V_12 ) ;
do {
V_6 = F_1 ( V_1 ) ;
if ( V_6 )
goto V_24;
if ( V_1 -> V_2 -> V_20 -> V_28 . V_97 )
break;
if ( V_1 -> V_2 -> V_20 -> V_92 ) {
F_39 ( V_1 -> V_13 ,
L_11 ) ;
F_3 ( & V_5 ) ;
V_6 = V_1 -> V_2 -> V_9 ( V_1 -> V_2 , & V_5 ) ;
if ( V_6 )
goto V_24;
}
F_40 ( 20 ) ;
V_6 = - V_14 ;
} while ( F_41 ( V_94 ) );
V_24:
F_42 ( & V_5 , V_6 ) ;
return V_6 ;
}
static int F_43 ( struct V_49 * V_50 , struct V_4 * V_5 )
{
int V_6 ;
V_6 = F_13 ( V_50 -> V_1 , V_5 , NULL , 0 ) ;
if ( V_6 == - V_14 ) {
struct V_4 V_98 ;
F_38 ( V_50 -> V_1 ) ;
F_44 ( V_98 , V_99 ) ;
F_13 ( V_50 -> V_1 , & V_98 , NULL , 0 ) ;
F_36 ( V_50 , true ) ;
}
return V_6 ;
}
static int
F_45 ( const struct V_100 * V_101 , enum V_102 V_103 )
{
struct V_49 * V_50 = F_46 ( V_101 ) ;
struct V_4 V_5 ;
int V_6 = 0 ;
if ( ! V_50 -> V_61 )
return - V_104 ;
F_24 ( & V_50 -> V_1 -> V_72 ) ;
if ( ( V_50 -> V_25 . V_62 == V_81 &&
V_103 == V_82 ) ||
( V_50 -> V_25 . V_62 == V_79 &&
V_103 == V_80 ) )
goto V_73;
F_47 ( V_5 , V_50 , V_103 ) ;
V_6 = F_43 ( V_50 , & V_5 ) ;
if ( V_6 < 0 )
goto V_73;
F_30 ( & V_50 -> V_1 -> V_72 ) ;
if ( ! F_5 ( & V_50 -> V_11 ,
F_6 ( V_105 ) ) )
return - V_14 ;
return 0 ;
V_73:
F_30 ( & V_50 -> V_1 -> V_72 ) ;
return V_6 ;
}
static int
F_48 ( const struct V_100 * V_101 , enum V_106 V_103 )
{
struct V_49 * V_50 = F_46 ( V_101 ) ;
struct V_4 V_5 ;
int V_6 = 0 ;
if ( ! V_50 -> V_61 )
return - V_104 ;
F_24 ( & V_50 -> V_1 -> V_72 ) ;
if ( V_50 -> V_25 . V_77 == V_103 )
goto V_73;
F_49 ( V_5 , V_50 , V_103 ) ;
V_6 = F_43 ( V_50 , & V_5 ) ;
if ( V_6 < 0 )
goto V_73;
F_30 ( & V_50 -> V_1 -> V_72 ) ;
if ( ! F_5 ( & V_50 -> V_11 ,
F_6 ( V_105 ) ) )
return - V_14 ;
F_24 ( & V_50 -> V_1 -> V_72 ) ;
if ( V_50 -> V_25 . V_51 != V_52 ) {
F_36 ( V_50 , true ) ;
V_6 = - V_41 ;
}
V_73:
F_30 ( & V_50 -> V_1 -> V_72 ) ;
return V_6 ;
}
static struct V_107 * F_50 ( struct V_49 * V_50 )
{
struct V_107 * V_108 ;
int V_109 = 1 ;
F_51 (con->ucsi->dev, fwnode)
if ( V_109 ++ == V_50 -> V_69 )
return V_108 ;
return NULL ;
}
static int F_52 ( struct V_1 * V_1 , int V_110 )
{
struct V_49 * V_50 = & V_1 -> V_91 [ V_110 ] ;
struct V_100 * V_101 = & V_50 -> V_111 ;
enum V_112 * V_64 = V_101 -> V_64 ;
struct V_4 V_5 ;
int V_6 ;
F_53 ( & V_50 -> V_71 , F_22 ) ;
F_54 ( & V_50 -> V_11 ) ;
V_50 -> V_69 = V_110 + 1 ;
V_50 -> V_1 = V_1 ;
F_55 ( V_5 , V_50 -> V_69 ) ;
V_6 = F_13 ( V_1 , & V_5 , & V_50 -> V_101 , sizeof( V_50 -> V_101 ) ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_50 -> V_101 . V_113 & V_114 )
V_101 -> type = V_115 ;
else if ( V_50 -> V_101 . V_113 & V_116 )
V_101 -> type = V_117 ;
else if ( V_50 -> V_101 . V_113 & V_118 )
V_101 -> type = V_119 ;
V_101 -> V_120 = V_1 -> V_101 . V_121 ;
V_101 -> V_122 = V_1 -> V_101 . V_123 ;
V_101 -> V_124 = V_125 ;
if ( V_50 -> V_101 . V_113 & V_126 )
* V_64 ++ = V_67 ;
if ( V_50 -> V_101 . V_113 & V_127 )
* V_64 = V_65 ;
V_101 -> V_108 = F_50 ( V_50 ) ;
V_101 -> V_128 = F_45 ;
V_101 -> V_129 = F_48 ;
V_50 -> V_53 = F_56 ( V_1 -> V_13 , V_101 ) ;
if ( ! V_50 -> V_53 )
return - V_35 ;
F_25 ( V_5 , V_50 -> V_69 ) ;
V_6 = F_13 ( V_1 , & V_5 , & V_50 -> V_25 , sizeof( V_50 -> V_25 ) ) ;
if ( V_6 < 0 ) {
F_12 ( V_1 -> V_13 , L_12 , V_50 -> V_69 ) ;
return 0 ;
}
F_16 ( V_50 ) ;
F_26 ( V_50 -> V_53 , V_50 -> V_25 . V_77 ) ;
switch ( V_50 -> V_25 . V_62 ) {
case V_79 :
F_28 ( V_50 -> V_53 , V_80 ) ;
break;
case V_81 :
F_28 ( V_50 -> V_53 , V_82 ) ;
break;
default:
break;
}
if ( V_50 -> V_25 . V_84 )
F_18 ( V_50 ) ;
F_57 ( V_50 -> V_69 , & V_50 -> V_25 ) ;
return 0 ;
}
static void F_58 ( struct V_70 * V_71 )
{
struct V_1 * V_1 = F_23 ( V_71 , struct V_1 , V_71 ) ;
struct V_49 * V_50 ;
struct V_4 V_5 ;
int V_6 ;
int V_109 ;
F_24 ( & V_1 -> V_72 ) ;
V_6 = F_38 ( V_1 ) ;
if ( V_6 ) {
F_12 ( V_1 -> V_13 , L_13 ) ;
goto V_24;
}
F_44 ( V_5 , V_130 |
V_131 ) ;
V_6 = F_13 ( V_1 , & V_5 , NULL , 0 ) ;
if ( V_6 < 0 )
goto V_132;
F_59 ( V_5 ) ;
V_6 = F_13 ( V_1 , & V_5 , & V_1 -> V_101 , sizeof( V_1 -> V_101 ) ) ;
if ( V_6 < 0 )
goto V_132;
if ( ! V_1 -> V_101 . V_133 ) {
V_6 = - V_35 ;
goto V_132;
}
V_1 -> V_91 = F_60 ( V_1 -> V_101 . V_133 + 1 ,
sizeof( * V_1 -> V_91 ) , V_134 ) ;
if ( ! V_1 -> V_91 ) {
V_6 = - V_135 ;
goto V_132;
}
for ( V_109 = 0 ; V_109 < V_1 -> V_101 . V_133 ; V_109 ++ ) {
V_6 = F_52 ( V_1 , V_109 ) ;
if ( V_6 )
goto V_136;
}
F_44 ( V_5 , V_99 ) ;
V_6 = F_13 ( V_1 , & V_5 , NULL , 0 ) ;
if ( V_6 < 0 )
goto V_136;
F_30 ( & V_1 -> V_72 ) ;
return;
V_136:
for ( V_50 = V_1 -> V_91 ; V_50 -> V_53 ; V_50 ++ ) {
F_20 ( V_50 ) ;
F_61 ( V_50 -> V_53 ) ;
V_50 -> V_53 = NULL ;
}
V_132:
F_38 ( V_1 ) ;
V_24:
F_30 ( & V_1 -> V_72 ) ;
F_12 ( V_1 -> V_13 , L_14 , V_6 ) ;
}
struct V_1 * F_62 ( struct V_137 * V_13 , struct V_138 * V_2 )
{
struct V_1 * V_1 ;
V_1 = F_63 ( sizeof( * V_1 ) , V_134 ) ;
if ( ! V_1 )
return F_64 ( - V_135 ) ;
F_53 ( & V_1 -> V_71 , F_58 ) ;
F_54 ( & V_1 -> V_11 ) ;
F_65 ( & V_1 -> V_72 ) ;
V_1 -> V_13 = V_13 ;
V_1 -> V_2 = V_2 ;
F_66 ( V_139 , & V_1 -> V_71 ) ;
return V_1 ;
}
void F_67 ( struct V_1 * V_1 )
{
struct V_4 V_5 ;
int V_109 ;
F_68 ( & V_1 -> V_71 ) ;
F_24 ( & V_1 -> V_72 ) ;
F_44 (ctrl, UCSI_ENABLE_NTFY_CMD_COMPLETE)
F_13 ( V_1 , & V_5 , NULL , 0 ) ;
F_30 ( & V_1 -> V_72 ) ;
for ( V_109 = 0 ; V_109 < V_1 -> V_101 . V_133 ; V_109 ++ ) {
F_68 ( & V_1 -> V_91 [ V_109 ] . V_71 ) ;
F_20 ( & V_1 -> V_91 [ V_109 ] ) ;
F_61 ( V_1 -> V_91 [ V_109 ] . V_53 ) ;
}
F_38 ( V_1 ) ;
F_69 ( V_1 -> V_91 ) ;
F_69 ( V_1 ) ;
}
