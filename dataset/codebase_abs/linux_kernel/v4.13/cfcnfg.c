struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
F_2 () ;
V_2 = F_3 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = F_4 () ;
if ( ! V_2 -> V_6 )
goto V_7;
V_2 -> V_8 = F_5 () ;
if ( ! V_2 -> V_8 )
goto V_7;
V_4 = F_6 ( V_2 -> V_8 ) ;
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_12 ;
V_4 -> V_16 = V_12 ;
V_4 -> V_17 = V_12 ;
V_4 -> V_18 = V_12 ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = V_22 ;
F_7 ( & V_2 -> V_23 ) ;
F_8 ( V_2 -> V_6 , V_2 -> V_8 , 0 ) ;
F_9 ( V_2 -> V_8 , V_2 -> V_6 ) ;
F_10 ( V_2 -> V_8 , V_2 ) ;
F_11 ( & V_2 -> V_24 ) ;
return V_2 ;
V_7:
F_12 () ;
F_13 ( V_2 -> V_6 ) ;
F_13 ( V_2 -> V_8 ) ;
F_13 ( V_2 ) ;
return NULL ;
}
void F_14 ( struct V_1 * V_25 )
{
F_2 () ;
if ( V_25 ) {
F_12 () ;
F_13 ( V_25 -> V_6 ) ;
F_15 ( V_25 -> V_8 ) ;
F_13 ( V_25 ) ;
}
}
static void V_12 ( void )
{
}
static struct V_26 * F_16 ( struct V_1 * V_27 ,
T_1 V_28 )
{
struct V_26 * V_29 ;
F_17 (phy, &cnfg->phys, node)
if ( V_29 -> V_30 == V_28 )
return V_29 ;
return NULL ;
}
static void V_10 ( void )
{
}
static struct V_31 * F_18 ( struct V_1 * V_27 ,
enum V_32 V_33 )
{
struct V_26 * V_29 ;
F_17 (phy, &cnfg->phys, node) {
if ( V_29 -> V_34 && V_29 -> V_35 == V_33 &&
V_29 -> V_36 != NULL )
return & V_29 -> V_31 ;
}
F_17 (phy, &cnfg->phys, node)
if ( V_29 -> V_34 )
return & V_29 -> V_31 ;
return NULL ;
}
static int F_19 ( struct V_1 * V_27 , int V_37 )
{
struct V_26 * V_29 ;
F_17 (phy, &cnfg->phys, node)
if ( V_29 -> V_38 == V_37 && V_29 -> V_34 )
return V_29 -> V_30 ;
return - V_39 ;
}
int F_20 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
T_1 V_43 ;
struct V_1 * V_25 = F_21 ( V_40 ) ;
F_22 ( V_42 != NULL ) ;
F_23 ( V_25 -> V_8 , V_42 ) ;
V_43 = V_42 -> V_30 ;
if ( V_43 != 0 ) {
struct V_41 * V_44 ;
V_44 = F_24 ( V_25 -> V_6 , V_43 ) ;
F_25 ( V_25 -> V_8 , V_43 , V_42 ) ;
if ( V_44 != NULL )
F_10 ( V_44 , NULL ) ;
} else
F_26 ( L_1 ) ;
F_12 () ;
if ( V_42 -> V_45 != NULL )
V_42 -> V_45 ( V_42 , V_46 , 0 ) ;
return 0 ;
}
static void V_14 ( struct V_41 * V_47 , T_1 V_43 )
{
}
static int F_27 ( struct V_1 * V_27 ,
struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_31 * V_31 ;
enum V_32 V_35 ;
int V_52 ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_53 = V_54 - V_49 -> V_53 + 1 ;
if ( V_49 -> V_38 != 0 ) {
V_52 = F_19 ( V_27 , V_49 -> V_38 ) ;
if ( V_52 < 0 )
return V_52 ;
V_51 -> V_28 = V_52 ;
} else {
switch ( V_49 -> V_55 ) {
case V_56 :
V_35 = V_57 ;
break;
case V_58 :
V_35 = V_59 ;
break;
default:
return - V_60 ;
}
V_31 = F_18 ( V_27 , V_35 ) ;
if ( V_31 == NULL )
return - V_39 ;
V_51 -> V_28 = V_31 -> V_30 ;
}
switch ( V_49 -> V_61 ) {
case V_62 :
V_51 -> V_63 = V_64 ;
V_51 -> V_65 = ( V_49 -> V_66 . V_67 . V_68 . type >> 2 ) & 0x3 ;
V_51 -> V_69 = V_49 -> V_66 . V_67 . V_68 . type & 0x3 ;
break;
case V_70 :
V_51 -> V_63 = V_71 ;
V_51 -> V_69 = 0x00 ;
V_51 -> V_67 . V_72 . V_73 = V_49 -> V_66 . V_67 . V_74 . V_75 ;
break;
case V_76 :
V_51 -> V_63 = V_71 ;
V_51 -> V_69 = 0x03 ;
V_51 -> V_65 = 0x00 ;
V_51 -> V_67 . V_72 . V_73 = V_49 -> V_66 . V_67 . V_74 . V_75 ;
break;
case V_77 :
V_51 -> V_63 = V_78 ;
V_51 -> V_67 . V_72 . V_73 = V_49 -> V_66 . V_67 . V_79 . V_75 ;
strncpy ( V_51 -> V_67 . V_79 . V_80 , V_49 -> V_66 . V_67 . V_79 . V_80 ,
sizeof( V_51 -> V_67 . V_79 . V_80 ) - 1 ) ;
V_51 -> V_67 . V_79 . V_80 [ sizeof( V_51 -> V_67 . V_79 . V_80 ) - 1 ] = 0 ;
break;
case V_81 :
V_51 -> V_63 = V_82 ;
V_51 -> V_65 = 0x00 ;
V_51 -> V_69 = 0x00 ;
strncpy ( V_51 -> V_67 . V_83 . V_84 , V_49 -> V_66 . V_67 . V_85 . V_86 ,
sizeof( V_51 -> V_67 . V_83 . V_84 ) - 1 ) ;
V_51 -> V_67 . V_83 . V_84 [ sizeof( V_51 -> V_67 . V_83 . V_84 ) - 1 ] = 0 ;
F_22 ( sizeof( V_51 -> V_67 . V_83 . V_84 ) > 10 ) ;
V_51 -> V_67 . V_83 . V_87 = V_49 -> V_88 . V_89 ;
if ( V_51 -> V_67 . V_83 . V_87 > sizeof( V_51 -> V_67 . V_83 . V_90 ) )
V_51 -> V_67 . V_83 . V_87 = sizeof( V_51 -> V_67 . V_83 . V_90 ) ;
memcpy ( V_51 -> V_67 . V_83 . V_90 , V_49 -> V_88 . V_91 ,
V_51 -> V_67 . V_83 . V_87 ) ;
break;
case V_92 :
V_51 -> V_63 = V_93 ;
V_51 -> V_65 = V_49 -> V_66 . V_67 . V_94 . V_86 ;
V_51 -> V_69 = V_49 -> V_66 . V_67 . V_94 . type ;
break;
default:
return - V_60 ;
}
return 0 ;
}
int F_28 ( struct V_40 * V_40 , struct V_48 * V_95 ,
struct V_41 * V_42 , int * V_38 ,
int * V_96 , int * V_97 )
{
struct V_41 * V_98 ;
struct V_26 * V_29 ;
int V_99 ;
struct V_50 V_88 ;
struct V_1 * V_25 = F_21 ( V_40 ) ;
F_29 () ;
V_99 = F_27 ( V_25 , V_95 , & V_88 ) ;
if ( V_99 )
goto V_100;
V_29 = F_16 ( V_25 , V_88 . V_28 ) ;
if ( ! V_29 ) {
V_99 = - V_39 ;
goto V_100;
}
V_99 = - V_60 ;
if ( V_42 == NULL ) {
F_30 ( L_2 ) ;
goto V_100;
}
if ( V_42 -> V_101 == NULL ) {
F_30 ( L_3 ) ;
goto V_100;
}
if ( V_42 -> V_45 == NULL ) {
F_30 ( L_4 ) ;
goto V_100;
}
V_99 = - V_39 ;
V_98 = V_29 -> V_36 ;
if ( V_98 == NULL ) {
F_30 ( L_5 ) ;
goto V_100;
}
F_22 ( V_88 . V_28 == V_29 -> V_30 ) ;
F_22 ( V_29 -> V_36 -> V_30 ==
V_88 . V_28 ) ;
F_22 ( V_29 -> V_102 -> V_30 ==
V_88 . V_28 ) ;
* V_38 = V_29 -> V_38 ;
* V_97 = 2 ;
* V_96 = V_103 [ V_88 . V_63 ] + V_29 -> V_104 ;
F_31 () ;
F_32 ( V_25 -> V_8 , V_88 . V_28 ) ;
return F_33 ( V_25 -> V_8 , & V_88 , V_42 ) ;
V_100:
F_31 () ;
return V_99 ;
}
static void V_22 ( struct V_41 * V_47 , T_1 V_43 ,
struct V_41 * V_105 )
{
if ( V_105 != NULL && V_105 -> V_45 != NULL )
V_105 -> V_45 ( V_105 ,
V_106 , 0 ) ;
}
static void
V_20 ( struct V_41 * V_47 , T_1 V_43 , enum V_107 V_108 ,
T_1 V_28 , struct V_41 * V_105 )
{
struct V_1 * V_27 = F_34 ( V_47 ) ;
struct V_41 * V_109 = NULL ;
struct V_26 * V_110 ;
struct V_111 * V_112 ;
if ( V_43 == 0 ) {
F_35 ( L_6 ) ;
if ( V_105 != NULL && V_105 -> V_45 != NULL )
V_105 -> V_45 ( V_105 ,
V_106 , 0 ) ;
return;
}
F_29 () ;
if ( V_105 == NULL ) {
F_26 ( L_7 ) ;
F_25 ( V_27 -> V_8 , V_43 , NULL ) ;
goto V_100;
}
F_22 ( V_27 != NULL ) ;
F_22 ( V_28 != 0 ) ;
V_110 = F_16 ( V_27 , V_28 ) ;
if ( V_110 == NULL ) {
F_30 ( L_8 ) ;
goto V_100;
}
F_22 ( V_110 != NULL ) ;
F_22 ( V_110 -> V_30 == V_28 ) ;
F_22 ( V_110 -> V_102 != NULL ) ;
F_22 ( V_110 -> V_102 -> V_30 == V_28 ) ;
V_105 -> V_30 = V_43 ;
switch ( V_108 ) {
case V_64 :
V_109 = F_36 ( V_43 , & V_110 -> V_31 ) ;
break;
case V_71 :
V_109 = F_37 ( V_43 ,
& V_110 -> V_31 ) ;
break;
case V_78 :
V_112 = V_110 -> V_31 . V_113 ;
V_109 = F_38 ( V_43 , & V_110 -> V_31 ,
V_112 -> V_114 ) ;
break;
case V_82 :
V_109 = F_39 ( V_43 , & V_110 -> V_31 ) ;
break;
case V_115 :
V_109 = F_40 ( V_43 , & V_110 -> V_31 ) ;
break;
case V_93 :
V_109 = F_41 ( V_43 , & V_110 -> V_31 ) ;
break;
default:
F_30 ( L_9 ) ;
goto V_100;
}
if ( ! V_109 )
goto V_100;
F_9 ( V_109 , V_27 -> V_6 ) ;
F_8 ( V_27 -> V_6 , V_109 , V_43 ) ;
F_10 ( V_109 , V_105 ) ;
F_9 ( V_105 , V_109 ) ;
F_31 () ;
V_109 -> V_45 ( V_109 , V_116 , 0 ) ;
return;
V_100:
F_31 () ;
}
void
F_42 ( struct V_1 * V_27 ,
struct V_111 * V_113 , struct V_41 * V_102 ,
enum V_32 V_35 ,
struct V_41 * V_117 ,
bool V_118 , int V_104 )
{
struct V_41 * V_98 ;
struct V_26 * V_110 = NULL ;
int V_119 ;
T_1 V_28 ;
F_43 ( & V_27 -> V_24 ) ;
for ( V_119 = 0 ; V_119 < 7 ; V_119 ++ ) {
V_28 = ( V_113 -> V_38 + V_119 ) & 0x7 ;
if ( V_28 == 0 )
continue;
if ( F_16 ( V_27 , V_28 ) == NULL )
goto V_120;
}
F_35 ( L_10 ) ;
goto V_121;
V_120:
V_110 = F_3 ( sizeof( struct V_26 ) , V_5 ) ;
if ( ! V_110 )
goto V_122;
V_102 -> V_30 = V_28 ;
V_110 -> V_35 = V_35 ;
V_110 -> V_30 = V_28 ;
V_110 -> V_31 . V_30 = V_28 ;
V_110 -> V_31 . V_113 = V_113 ;
V_110 -> V_102 = V_102 ;
V_110 -> V_38 = V_113 -> V_38 ;
V_110 -> V_104 = V_104 ;
V_110 -> V_123 = V_118 ;
V_98 = F_44 ( V_28 , V_118 ) ;
if ( ! V_98 )
goto V_122;
V_110 -> V_36 = V_98 ;
F_10 ( V_98 , V_27 -> V_6 ) ;
if ( V_117 != NULL ) {
V_117 -> V_30 = V_28 ;
F_9 ( V_98 , V_117 ) ;
F_10 ( V_117 , V_98 ) ;
F_9 ( V_117 , V_102 ) ;
F_10 ( V_102 , V_117 ) ;
} else {
F_9 ( V_98 , V_102 ) ;
F_10 ( V_102 , V_98 ) ;
}
F_45 ( & V_110 -> V_124 , & V_27 -> V_23 ) ;
V_121:
F_46 ( & V_27 -> V_24 ) ;
return;
V_122:
F_13 ( V_110 ) ;
F_46 ( & V_27 -> V_24 ) ;
}
int F_47 ( struct V_1 * V_27 , struct V_41 * V_102 ,
bool V_34 )
{
struct V_26 * V_110 ;
F_29 () ;
V_110 = F_16 ( V_27 , V_102 -> V_30 ) ;
if ( V_110 == NULL ) {
F_31 () ;
return - V_39 ;
}
if ( V_110 -> V_34 == V_34 ) {
F_31 () ;
return 0 ;
}
V_110 -> V_34 = V_34 ;
if ( V_34 ) {
F_48 ( V_110 -> V_36 ) ;
F_49 ( V_27 -> V_6 , V_110 -> V_36 ,
V_102 -> V_30 ) ;
} else {
F_50 ( V_27 -> V_6 , V_102 -> V_30 ) ;
F_51 ( V_110 -> V_36 ) ;
}
F_31 () ;
return 0 ;
}
int F_52 ( struct V_1 * V_27 , struct V_41 * V_102 )
{
struct V_41 * V_98 , * V_125 ;
T_2 V_28 ;
struct V_26 * V_110 ;
F_2 () ;
F_43 ( & V_27 -> V_24 ) ;
V_28 = V_102 -> V_30 ;
V_110 = F_16 ( V_27 , V_28 ) ;
if ( V_110 == NULL ) {
F_46 ( & V_27 -> V_24 ) ;
return 0 ;
}
F_22 ( V_28 == V_110 -> V_30 ) ;
F_22 ( V_102 == V_110 -> V_102 ) ;
F_22 ( V_102 -> V_30 == V_28 ) ;
F_22 ( V_110 -> V_36 -> V_30 == V_28 ) ;
F_53 ( & V_110 -> V_124 ) ;
F_12 () ;
if ( F_54 ( V_110 -> V_36 ) != 0 ) {
F_55 ( L_11 ) ;
F_45 ( & V_110 -> V_124 , & V_27 -> V_23 ) ;
F_46 ( & V_27 -> V_24 ) ;
return - V_126 ;
}
V_98 = V_110 -> V_36 ;
V_125 = V_98 -> V_127 ;
F_56 ( V_98 , NULL ) ;
F_57 ( V_98 , NULL ) ;
if ( V_102 != V_125 ) {
F_10 ( V_125 , NULL ) ;
F_9 ( V_125 , NULL ) ;
}
F_10 ( V_102 , NULL ) ;
if ( V_110 -> V_102 != V_125 )
F_13 ( V_125 ) ;
F_58 ( V_98 ) ;
F_13 ( V_110 ) ;
F_46 ( & V_27 -> V_24 ) ;
return 0 ;
}
