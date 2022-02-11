static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 , * V_6 ;
if ( V_3 == ( V_7 | V_8 ) )
return;
F_2 (mode, t, &connector->modes, head) {
if ( ( V_5 -> V_3 & V_8 ) &&
! ( V_3 & V_8 ) )
V_5 -> V_9 = V_10 ;
if ( ( V_5 -> V_3 & V_7 ) &&
! ( V_3 & V_7 ) )
V_5 -> V_9 = V_11 ;
}
return;
}
int F_3 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_13 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_4 * V_5 , * V_6 ;
struct V_16 * V_17 =
V_2 -> V_18 ;
int V_19 = 0 ;
int V_20 = 0 ;
F_4 ( L_1 , V_2 -> V_21 . V_22 ,
F_5 ( V_2 ) ) ;
F_2 (mode, t, &connector->modes, head)
V_5 -> V_9 = V_23 ;
if ( V_2 -> V_24 ) {
if ( V_2 -> V_24 == V_25 )
V_2 -> V_9 = V_26 ;
else
V_2 -> V_9 = V_27 ;
if ( V_2 -> V_28 -> V_24 )
V_2 -> V_28 -> V_24 ( V_2 ) ;
} else {
V_2 -> V_9 = V_2 -> V_28 -> V_29 ( V_2 , true ) ;
F_6 ( V_15 ) ;
}
if ( V_2 -> V_9 == V_27 ) {
F_4 ( L_2 ,
V_2 -> V_21 . V_22 , F_5 ( V_2 ) ) ;
F_7 ( V_2 , NULL ) ;
goto V_30;
}
V_19 = (* V_17 -> V_31 )( V_2 ) ;
if ( V_19 == 0 && V_2 -> V_9 == V_26 )
V_19 = F_8 ( V_2 , 1024 , 768 ) ;
if ( V_19 == 0 )
goto V_30;
F_9 ( V_2 ) ;
if ( V_12 && V_13 )
F_10 ( V_15 , & V_2 -> V_32 , V_12 ,
V_13 , 0 ) ;
if ( V_2 -> V_33 )
V_20 |= V_8 ;
if ( V_2 -> V_34 )
V_20 |= V_7 ;
F_1 ( V_2 , V_20 ) ;
F_2 (mode, t, &connector->modes, head) {
if ( V_5 -> V_9 == V_35 )
V_5 -> V_9 = V_17 -> V_36 ( V_2 ,
V_5 ) ;
}
V_30:
F_11 ( V_15 , & V_2 -> V_32 , true ) ;
if ( F_12 ( & V_2 -> V_32 ) )
return 0 ;
F_13 ( & V_2 -> V_32 ) ;
F_4 ( L_3 , V_2 -> V_21 . V_22 ,
F_5 ( V_2 ) ) ;
F_2 (mode, t, &connector->modes, head) {
V_5 -> V_37 = F_14 ( V_5 ) ;
F_15 ( V_5 , V_38 ) ;
F_16 ( V_5 ) ;
}
return V_19 ;
}
bool F_17 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 = V_40 -> V_15 ;
F_18 (connector, &dev->mode_config.connector_list, head)
if ( V_2 -> V_40 == V_40 )
return true ;
return false ;
}
bool F_19 ( struct V_41 * V_42 )
{
struct V_39 * V_40 ;
struct V_14 * V_15 = V_42 -> V_15 ;
F_18 (encoder, &dev->mode_config.encoder_list, head)
if ( V_40 -> V_42 == V_42 && F_17 ( V_40 ) )
return true ;
return false ;
}
static void
F_20 ( struct V_39 * V_40 )
{
struct V_43 * V_44 = V_40 -> V_18 ;
if ( V_44 -> V_45 )
(* V_44 -> V_45 )( V_40 ) ;
else
(* V_44 -> V_46 )( V_40 , V_47 ) ;
}
void F_21 ( struct V_14 * V_15 )
{
struct V_39 * V_40 ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
F_18 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_2 -> V_40 )
continue;
if ( V_2 -> V_9 == V_27 )
V_2 -> V_40 = NULL ;
}
F_18 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_17 ( V_40 ) ) {
F_20 ( V_40 ) ;
V_40 -> V_42 = NULL ;
}
}
F_18 (crtc, &dev->mode_config.crtc_list, head) {
struct V_48 * V_49 = V_42 -> V_18 ;
V_42 -> V_50 = F_19 ( V_42 ) ;
if ( ! V_42 -> V_50 ) {
if ( V_49 -> V_45 )
(* V_49 -> V_45 )( V_42 ) ;
else
(* V_49 -> V_46 )( V_42 , V_47 ) ;
V_42 -> V_51 = NULL ;
}
}
}
static bool F_22 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_14 * V_15 ;
struct V_41 * V_52 ;
int V_53 = 1 ;
F_23 ( ! V_42 , L_4 ) ;
V_15 = V_42 -> V_15 ;
F_18 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_52 == V_42 )
break;
V_53 <<= 1 ;
}
if ( V_40 -> V_54 & V_53 )
return true ;
return false ;
}
static void
F_24 ( struct V_14 * V_15 )
{
struct V_43 * V_44 ;
struct V_39 * V_40 ;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
V_44 = V_40 -> V_18 ;
if ( V_40 -> V_42 == NULL )
F_20 ( V_40 ) ;
if ( V_44 -> V_55 &&
V_40 -> V_42 != (* V_44 -> V_55 )( V_40 ) )
F_20 ( V_40 ) ;
}
}
bool F_25 ( struct V_41 * V_42 ,
struct V_4 * V_5 ,
int V_56 , int V_57 ,
struct V_58 * V_59 )
{
struct V_14 * V_15 = V_42 -> V_15 ;
struct V_4 * V_60 , V_61 , V_62 ;
struct V_48 * V_49 = V_42 -> V_18 ;
struct V_43 * V_44 ;
int V_63 , V_64 ;
struct V_39 * V_40 ;
bool V_65 = true ;
V_42 -> V_50 = F_19 ( V_42 ) ;
if ( ! V_42 -> V_50 )
return true ;
V_60 = F_26 ( V_15 , V_5 ) ;
V_62 = V_42 -> V_66 ;
V_61 = V_42 -> V_5 ;
V_63 = V_42 -> V_56 ;
V_64 = V_42 -> V_57 ;
V_42 -> V_5 = * V_5 ;
V_42 -> V_56 = V_56 ;
V_42 -> V_57 = V_57 ;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_40 -> V_42 != V_42 )
continue;
V_44 = V_40 -> V_18 ;
if ( ! ( V_65 = V_44 -> V_67 ( V_40 , V_5 ,
V_60 ) ) ) {
goto V_68;
}
}
if ( ! ( V_65 = V_49 -> V_67 ( V_42 , V_5 , V_60 ) ) ) {
goto V_68;
}
F_4 ( L_5 , V_42 -> V_21 . V_22 ) ;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_40 -> V_42 != V_42 )
continue;
V_44 = V_40 -> V_18 ;
V_44 -> V_69 ( V_40 ) ;
}
F_24 ( V_15 ) ;
V_49 -> V_69 ( V_42 ) ;
V_65 = ! V_49 -> V_70 ( V_42 , V_5 , V_60 , V_56 , V_57 , V_59 ) ;
if ( ! V_65 )
goto V_68;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_40 -> V_42 != V_42 )
continue;
F_4 ( L_6 ,
V_40 -> V_21 . V_22 , F_27 ( V_40 ) ,
V_5 -> V_21 . V_22 , V_5 -> V_71 ) ;
V_44 = V_40 -> V_18 ;
V_44 -> V_70 ( V_40 , V_5 , V_60 ) ;
}
V_49 -> V_72 ( V_42 ) ;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_40 -> V_42 != V_42 )
continue;
V_44 = V_40 -> V_18 ;
V_44 -> V_72 ( V_40 ) ;
}
V_42 -> V_66 = * V_60 ;
F_28 ( V_42 ) ;
V_68:
F_29 ( V_15 , V_60 ) ;
if ( ! V_65 ) {
V_42 -> V_66 = V_62 ;
V_42 -> V_5 = V_61 ;
V_42 -> V_56 = V_63 ;
V_42 -> V_57 = V_64 ;
}
return V_65 ;
}
int F_30 ( struct V_73 * V_74 )
{
struct V_14 * V_15 ;
struct V_41 * V_75 , * V_76 , * V_42 ;
struct V_39 * V_77 , * V_78 , * V_40 ;
struct V_58 * V_59 = NULL ;
bool V_79 = false ;
bool V_80 = false ;
struct V_1 * V_81 , * V_2 ;
int V_19 = 0 , V_82 , V_83 = 0 ;
struct V_48 * V_49 ;
int V_65 = 0 ;
int V_84 ;
F_4 ( L_7 ) ;
if ( ! V_74 )
return - V_85 ;
if ( ! V_74 -> V_42 )
return - V_85 ;
if ( ! V_74 -> V_42 -> V_18 )
return - V_85 ;
V_49 = V_74 -> V_42 -> V_18 ;
if ( ! V_74 -> V_5 )
V_74 -> V_51 = NULL ;
if ( V_74 -> V_51 ) {
F_4 ( L_8 ,
V_74 -> V_42 -> V_21 . V_22 , V_74 -> V_51 -> V_21 . V_22 ,
( int ) V_74 -> V_86 , V_74 -> V_56 , V_74 -> V_57 ) ;
} else {
F_4 ( L_9 , V_74 -> V_42 -> V_21 . V_22 ) ;
V_74 -> V_5 = NULL ;
V_74 -> V_86 = 0 ;
}
V_15 = V_74 -> V_42 -> V_15 ;
V_75 = F_31 ( V_15 -> V_87 . V_88 *
sizeof( struct V_41 ) , V_89 ) ;
if ( ! V_75 )
return - V_90 ;
V_77 = F_31 ( V_15 -> V_87 . V_91 *
sizeof( struct V_39 ) , V_89 ) ;
if ( ! V_77 ) {
F_32 ( V_75 ) ;
return - V_90 ;
}
V_81 = F_31 ( V_15 -> V_87 . V_92 *
sizeof( struct V_1 ) , V_89 ) ;
if ( ! V_81 ) {
F_32 ( V_75 ) ;
F_32 ( V_77 ) ;
return - V_90 ;
}
V_19 = 0 ;
F_18 (crtc, &dev->mode_config.crtc_list, head) {
V_75 [ V_19 ++ ] = * V_42 ;
}
V_19 = 0 ;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
V_77 [ V_19 ++ ] = * V_40 ;
}
V_19 = 0 ;
F_18 (connector, &dev->mode_config.connector_list, head) {
V_81 [ V_19 ++ ] = * V_2 ;
}
if ( V_74 -> V_42 -> V_51 != V_74 -> V_51 ) {
if ( V_74 -> V_42 -> V_51 == NULL ) {
F_4 ( L_10 ) ;
V_79 = true ;
} else if ( V_74 -> V_51 == NULL ) {
V_79 = true ;
} else if ( V_74 -> V_51 -> V_93 != V_74 -> V_42 -> V_51 -> V_93 ) {
V_79 = true ;
} else if ( V_74 -> V_51 -> V_94 !=
V_74 -> V_42 -> V_51 -> V_94 ) {
V_79 = true ;
} else
V_80 = true ;
}
if ( V_74 -> V_56 != V_74 -> V_42 -> V_56 || V_74 -> V_57 != V_74 -> V_42 -> V_57 )
V_80 = true ;
if ( V_74 -> V_5 && ! F_33 ( V_74 -> V_5 , & V_74 -> V_42 -> V_5 ) ) {
F_4 ( L_11 ) ;
F_16 ( & V_74 -> V_42 -> V_5 ) ;
F_16 ( V_74 -> V_5 ) ;
V_79 = true ;
}
V_19 = 0 ;
F_18 (connector, &dev->mode_config.connector_list, head) {
struct V_16 * V_17 =
V_2 -> V_18 ;
V_78 = V_2 -> V_40 ;
for ( V_82 = 0 ; V_82 < V_74 -> V_86 ; V_82 ++ ) {
if ( V_74 -> V_95 [ V_82 ] == V_2 ) {
V_78 = V_17 -> V_96 ( V_2 ) ;
if ( V_78 == NULL )
V_83 = 1 ;
break;
}
}
if ( V_78 != V_2 -> V_40 ) {
F_4 ( L_12 ) ;
V_79 = true ;
if ( V_2 -> V_40 )
V_2 -> V_40 -> V_42 = NULL ;
V_2 -> V_40 = V_78 ;
}
}
if ( V_83 ) {
V_65 = - V_85 ;
goto V_83;
}
V_19 = 0 ;
F_18 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_2 -> V_40 )
continue;
if ( V_2 -> V_40 -> V_42 == V_74 -> V_42 )
V_76 = NULL ;
else
V_76 = V_2 -> V_40 -> V_42 ;
for ( V_82 = 0 ; V_82 < V_74 -> V_86 ; V_82 ++ ) {
if ( V_74 -> V_95 [ V_82 ] == V_2 )
V_76 = V_74 -> V_42 ;
}
if ( V_76 &&
! F_22 ( V_2 -> V_40 , V_76 ) ) {
V_65 = - V_85 ;
goto V_83;
}
if ( V_76 != V_2 -> V_40 -> V_42 ) {
F_4 ( L_13 ) ;
V_79 = true ;
V_2 -> V_40 -> V_42 = V_76 ;
}
if ( V_76 ) {
F_4 ( L_14 ,
V_2 -> V_21 . V_22 , F_5 ( V_2 ) ,
V_76 -> V_21 . V_22 ) ;
} else {
F_4 ( L_15 ,
V_2 -> V_21 . V_22 , F_5 ( V_2 ) ) ;
}
}
if ( V_80 && ! V_49 -> V_97 )
V_79 = true ;
if ( V_79 ) {
V_74 -> V_42 -> V_50 = F_19 ( V_74 -> V_42 ) ;
if ( V_74 -> V_42 -> V_50 ) {
F_4 ( L_16
L_17 ) ;
F_16 ( V_74 -> V_5 ) ;
V_59 = V_74 -> V_42 -> V_51 ;
V_74 -> V_42 -> V_51 = V_74 -> V_51 ;
if ( ! F_25 ( V_74 -> V_42 , V_74 -> V_5 ,
V_74 -> V_56 , V_74 -> V_57 ,
V_59 ) ) {
F_34 ( L_18 ,
V_74 -> V_42 -> V_21 . V_22 ) ;
V_74 -> V_42 -> V_51 = V_59 ;
V_65 = - V_85 ;
goto V_83;
}
F_4 ( L_19 ) ;
for ( V_84 = 0 ; V_84 < V_74 -> V_86 ; V_84 ++ ) {
F_4 ( L_20 , V_74 -> V_95 [ V_84 ] -> V_21 . V_22 ,
F_5 ( V_74 -> V_95 [ V_84 ] ) ) ;
V_74 -> V_95 [ V_84 ] -> V_46 = V_98 ;
}
}
F_21 ( V_15 ) ;
} else if ( V_80 ) {
V_74 -> V_42 -> V_56 = V_74 -> V_56 ;
V_74 -> V_42 -> V_57 = V_74 -> V_57 ;
V_59 = V_74 -> V_42 -> V_51 ;
if ( V_74 -> V_42 -> V_51 != V_74 -> V_51 )
V_74 -> V_42 -> V_51 = V_74 -> V_51 ;
V_65 = V_49 -> V_97 ( V_74 -> V_42 ,
V_74 -> V_56 , V_74 -> V_57 , V_59 ) ;
if ( V_65 != 0 ) {
V_74 -> V_42 -> V_51 = V_59 ;
goto V_83;
}
}
F_32 ( V_81 ) ;
F_32 ( V_77 ) ;
F_32 ( V_75 ) ;
return 0 ;
V_83:
V_19 = 0 ;
F_18 (crtc, &dev->mode_config.crtc_list, head) {
* V_42 = V_75 [ V_19 ++ ] ;
}
V_19 = 0 ;
F_18 (encoder, &dev->mode_config.encoder_list, head) {
* V_40 = V_77 [ V_19 ++ ] ;
}
V_19 = 0 ;
F_18 (connector, &dev->mode_config.connector_list, head) {
* V_2 = V_81 [ V_19 ++ ] ;
}
F_32 ( V_81 ) ;
F_32 ( V_77 ) ;
F_32 ( V_75 ) ;
return V_65 ;
}
static int F_35 ( struct V_39 * V_40 )
{
int V_46 = V_47 ;
struct V_1 * V_2 ;
struct V_14 * V_15 = V_40 -> V_15 ;
F_18 (connector, &dev->mode_config.connector_list, head)
if ( V_2 -> V_40 == V_40 )
if ( V_2 -> V_46 < V_46 )
V_46 = V_2 -> V_46 ;
return V_46 ;
}
static int F_36 ( struct V_41 * V_42 )
{
int V_46 = V_47 ;
struct V_1 * V_2 ;
struct V_14 * V_15 = V_42 -> V_15 ;
F_18 (connector, &dev->mode_config.connector_list, head)
if ( V_2 -> V_40 && V_2 -> V_40 -> V_42 == V_42 )
if ( V_2 -> V_46 < V_46 )
V_46 = V_2 -> V_46 ;
return V_46 ;
}
void F_37 ( struct V_1 * V_2 , int V_5 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_41 * V_42 = V_40 ? V_40 -> V_42 : NULL ;
int V_99 ;
if ( V_5 == V_2 -> V_46 )
return;
V_99 = V_2 -> V_46 ;
V_2 -> V_46 = V_5 ;
if ( V_5 < V_99 ) {
if ( V_42 ) {
struct V_48 * V_49 = V_42 -> V_18 ;
if ( V_49 -> V_46 )
(* V_49 -> V_46 ) ( V_42 ,
F_36 ( V_42 ) ) ;
}
if ( V_40 ) {
struct V_43 * V_44 = V_40 -> V_18 ;
if ( V_44 -> V_46 )
(* V_44 -> V_46 ) ( V_40 ,
F_35 ( V_40 ) ) ;
}
}
if ( V_5 > V_99 ) {
if ( V_40 ) {
struct V_43 * V_44 = V_40 -> V_18 ;
if ( V_44 -> V_46 )
(* V_44 -> V_46 ) ( V_40 ,
F_35 ( V_40 ) ) ;
}
if ( V_42 ) {
struct V_48 * V_49 = V_42 -> V_18 ;
if ( V_49 -> V_46 )
(* V_49 -> V_46 ) ( V_42 ,
F_36 ( V_42 ) ) ;
}
}
return;
}
int F_38 ( struct V_58 * V_51 ,
struct V_100 * V_101 )
{
V_51 -> V_102 = V_101 -> V_102 ;
V_51 -> V_103 = V_101 -> V_103 ;
V_51 -> V_104 = V_101 -> V_104 ;
V_51 -> V_94 = V_101 -> V_105 ;
V_51 -> V_93 = V_101 -> V_93 ;
return 0 ;
}
int F_39 ( struct V_14 * V_15 )
{
struct V_41 * V_42 ;
struct V_39 * V_40 ;
struct V_43 * V_44 ;
struct V_48 * V_49 ;
int V_65 ;
F_18 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_42 -> V_50 )
continue;
V_65 = F_25 ( V_42 , & V_42 -> V_5 ,
V_42 -> V_56 , V_42 -> V_57 , V_42 -> V_51 ) ;
if ( V_65 == false )
F_34 ( L_21 , V_42 ) ;
if ( F_36 ( V_42 ) ) {
F_18 (encoder, &dev->mode_config.encoder_list, head) {
if( V_40 -> V_42 != V_42 )
continue;
V_44 = V_40 -> V_18 ;
if ( V_44 -> V_46 )
(* V_44 -> V_46 ) ( V_40 ,
F_35 ( V_40 ) ) ;
}
V_49 = V_42 -> V_18 ;
if ( V_49 -> V_46 )
(* V_49 -> V_46 ) ( V_42 ,
F_36 ( V_42 ) ) ;
}
}
F_21 ( V_15 ) ;
return 0 ;
}
static void F_40 ( struct V_106 * V_107 )
{
struct V_108 * V_108 = F_41 ( V_107 ) ;
struct V_14 * V_15 = F_42 ( V_108 , struct V_14 , V_87 . V_109 ) ;
struct V_1 * V_2 ;
enum V_110 V_111 ;
bool V_112 = false , V_113 = false ;
if ( ! V_114 )
return;
F_43 ( & V_15 -> V_87 . V_115 ) ;
F_18 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_2 -> V_116 )
continue;
else if ( V_2 -> V_116 & ( V_117 | V_118 ) )
V_112 = true ;
V_111 = V_2 -> V_9 ;
if ( V_111 == V_26 &&
! ( V_2 -> V_116 & V_118 ) &&
! ( V_2 -> V_116 & V_119 ) )
continue;
V_2 -> V_9 = V_2 -> V_28 -> V_29 ( V_2 , false ) ;
F_4 ( L_22 ,
V_2 -> V_21 . V_22 ,
F_5 ( V_2 ) ,
V_111 , V_2 -> V_9 ) ;
if ( V_111 != V_2 -> V_9 )
V_113 = true ;
}
F_44 ( & V_15 -> V_87 . V_115 ) ;
if ( V_113 ) {
F_45 ( V_15 ) ;
if ( V_15 -> V_87 . V_28 -> V_120 )
V_15 -> V_87 . V_28 -> V_120 ( V_15 ) ;
}
if ( V_112 )
F_46 ( V_121 , V_108 , V_122 ) ;
}
void F_47 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_87 . V_123 )
return;
F_48 ( & V_15 -> V_87 . V_109 ) ;
}
void F_6 ( struct V_14 * V_15 )
{
bool V_124 = false ;
struct V_1 * V_2 ;
if ( ! V_15 -> V_87 . V_123 || ! V_114 )
return;
F_18 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_116 )
V_124 = true ;
}
if ( V_124 )
F_46 ( V_121 , & V_15 -> V_87 . V_109 , V_122 ) ;
}
void F_49 ( struct V_14 * V_15 )
{
F_50 ( & V_15 -> V_87 . V_109 , F_40 ) ;
V_15 -> V_87 . V_123 = true ;
F_6 ( V_15 ) ;
}
void F_51 ( struct V_14 * V_15 )
{
F_47 ( V_15 ) ;
}
void F_52 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_87 . V_123 )
return;
F_53 ( & V_15 -> V_87 . V_109 ) ;
if ( V_114 )
F_46 ( V_121 , & V_15 -> V_87 . V_109 , 0 ) ;
}
