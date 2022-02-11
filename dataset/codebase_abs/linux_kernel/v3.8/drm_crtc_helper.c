void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 V_7 ;
F_2 ( & V_7 ) ;
F_3 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( V_4 -> V_8 == V_9 ||
V_4 -> V_8 == V_10 )
F_4 ( & V_4 -> V_11 , & V_7 ) ;
}
F_5 ( & V_7 , & V_2 -> V_12 . V_13 ) ;
}
static void F_6 ( struct V_3 * V_4 ,
int V_14 )
{
struct V_15 * V_16 ;
if ( V_14 == ( V_17 | V_18 ) )
return;
F_7 (mode, &connector->modes, head) {
if ( ( V_16 -> V_14 & V_18 ) &&
! ( V_14 & V_18 ) )
V_16 -> V_19 = V_20 ;
if ( ( V_16 -> V_14 & V_17 ) &&
! ( V_14 & V_17 ) )
V_16 -> V_19 = V_21 ;
}
return;
}
int F_8 ( struct V_3 * V_4 ,
T_1 V_22 , T_1 V_23 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 ;
struct V_24 * V_25 =
V_4 -> V_26 ;
int V_27 = 0 ;
int V_28 = 0 ;
F_9 ( L_1 , V_4 -> V_29 . V_30 ,
F_10 ( V_4 ) ) ;
F_7 (mode, &connector->modes, head)
V_16 -> V_19 = V_31 ;
if ( V_4 -> V_32 ) {
if ( V_4 -> V_32 == V_33 )
V_4 -> V_19 = V_34 ;
else
V_4 -> V_19 = V_35 ;
if ( V_4 -> V_36 -> V_32 )
V_4 -> V_36 -> V_32 ( V_4 ) ;
} else {
V_4 -> V_19 = V_4 -> V_36 -> V_37 ( V_4 , true ) ;
}
if ( V_38 != V_2 -> V_12 . V_39 )
F_11 ( V_2 ) ;
V_2 -> V_12 . V_39 = V_38 ;
if ( V_4 -> V_19 == V_35 ) {
F_9 ( L_2 ,
V_4 -> V_29 . V_30 , F_10 ( V_4 ) ) ;
F_12 ( V_4 , NULL ) ;
goto V_40;
}
#ifdef F_13
V_27 = F_14 ( V_4 ) ;
if ( V_27 == 0 )
#endif
V_27 = (* V_25 -> V_41 )( V_4 ) ;
if ( V_27 == 0 && V_4 -> V_19 == V_34 )
V_27 = F_15 ( V_4 , 1024 , 768 ) ;
if ( V_27 == 0 )
goto V_40;
F_16 ( V_4 ) ;
if ( V_22 && V_23 )
F_17 ( V_2 , & V_4 -> V_42 , V_22 ,
V_23 , 0 ) ;
if ( V_4 -> V_43 )
V_28 |= V_18 ;
if ( V_4 -> V_44 )
V_28 |= V_17 ;
F_6 ( V_4 , V_28 ) ;
F_7 (mode, &connector->modes, head) {
if ( V_16 -> V_19 == V_45 )
V_16 -> V_19 = V_25 -> V_46 ( V_4 ,
V_16 ) ;
}
V_40:
F_18 ( V_2 , & V_4 -> V_42 , true ) ;
if ( F_19 ( & V_4 -> V_42 ) )
return 0 ;
F_20 ( & V_4 -> V_42 ) ;
F_9 ( L_3 , V_4 -> V_29 . V_30 ,
F_10 ( V_4 ) ) ;
F_7 (mode, &connector->modes, head) {
V_16 -> V_47 = F_21 ( V_16 ) ;
F_22 ( V_16 , V_48 ) ;
F_23 ( V_16 ) ;
}
return V_27 ;
}
bool F_24 ( struct V_49 * V_50 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = V_50 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_50 == V_50 )
return true ;
return false ;
}
bool F_25 ( struct V_51 * V_52 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 = V_52 -> V_2 ;
F_7 (encoder, &dev->mode_config.encoder_list, head)
if ( V_50 -> V_52 == V_52 && F_24 ( V_50 ) )
return true ;
return false ;
}
static void
F_26 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_26 ;
if ( V_54 -> V_55 )
(* V_54 -> V_55 )( V_50 ) ;
else
(* V_54 -> V_56 )( V_50 , V_57 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_3 * V_4 ;
struct V_51 * V_52 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_50 )
continue;
if ( V_4 -> V_19 == V_35 )
V_4 -> V_50 = NULL ;
}
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_24 ( V_50 ) ) {
F_26 ( V_50 ) ;
V_50 -> V_52 = NULL ;
}
}
F_7 (crtc, &dev->mode_config.crtc_list, head) {
struct V_58 * V_59 = V_52 -> V_26 ;
V_52 -> V_60 = F_25 ( V_52 ) ;
if ( ! V_52 -> V_60 ) {
if ( V_59 -> V_55 )
(* V_59 -> V_55 )( V_52 ) ;
else
(* V_59 -> V_56 )( V_52 , V_57 ) ;
V_52 -> V_61 = NULL ;
}
}
}
static bool F_28 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_51 * V_5 ;
int V_62 = 1 ;
F_29 ( ! V_52 , L_4 ) ;
V_2 = V_52 -> V_2 ;
F_7 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_5 == V_52 )
break;
V_62 <<= 1 ;
}
if ( V_50 -> V_63 & V_62 )
return true ;
return false ;
}
static void
F_30 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
struct V_49 * V_50 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_54 = V_50 -> V_26 ;
if ( V_50 -> V_52 == NULL )
F_26 ( V_50 ) ;
if ( V_54 -> V_64 &&
V_50 -> V_52 != (* V_54 -> V_64 )( V_50 ) )
F_26 ( V_50 ) ;
}
}
bool F_31 ( struct V_51 * V_52 ,
struct V_15 * V_16 ,
int V_65 , int V_66 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_15 * V_69 , V_70 , V_71 ;
struct V_58 * V_59 = V_52 -> V_26 ;
struct V_53 * V_54 ;
int V_72 , V_73 ;
struct V_49 * V_50 ;
bool V_74 = true ;
V_52 -> V_60 = F_25 ( V_52 ) ;
if ( ! V_52 -> V_60 )
return true ;
V_69 = F_32 ( V_2 , V_16 ) ;
if ( ! V_69 )
return false ;
V_71 = V_52 -> V_75 ;
V_70 = V_52 -> V_16 ;
V_72 = V_52 -> V_65 ;
V_73 = V_52 -> V_66 ;
V_52 -> V_16 = * V_16 ;
V_52 -> V_65 = V_65 ;
V_52 -> V_66 = V_66 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_50 -> V_52 != V_52 )
continue;
V_54 = V_50 -> V_26 ;
if ( ! ( V_74 = V_54 -> V_76 ( V_50 , V_16 ,
V_69 ) ) ) {
F_9 ( L_5 ) ;
goto V_77;
}
}
if ( ! ( V_74 = V_59 -> V_76 ( V_52 , V_16 , V_69 ) ) ) {
F_9 ( L_6 ) ;
goto V_77;
}
F_9 ( L_7 , V_52 -> V_29 . V_30 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_50 -> V_52 != V_52 )
continue;
V_54 = V_50 -> V_26 ;
V_54 -> V_78 ( V_50 ) ;
}
F_30 ( V_2 ) ;
V_59 -> V_78 ( V_52 ) ;
V_74 = ! V_59 -> V_79 ( V_52 , V_16 , V_69 , V_65 , V_66 , V_68 ) ;
if ( ! V_74 )
goto V_77;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_50 -> V_52 != V_52 )
continue;
F_9 ( L_8 ,
V_50 -> V_29 . V_30 , F_33 ( V_50 ) ,
V_16 -> V_29 . V_30 , V_16 -> V_80 ) ;
V_54 = V_50 -> V_26 ;
V_54 -> V_79 ( V_50 , V_16 , V_69 ) ;
}
V_59 -> V_81 ( V_52 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_50 -> V_52 != V_52 )
continue;
V_54 = V_50 -> V_26 ;
V_54 -> V_81 ( V_50 ) ;
}
V_52 -> V_75 = * V_69 ;
F_34 ( V_52 ) ;
V_77:
F_35 ( V_2 , V_69 ) ;
if ( ! V_74 ) {
V_52 -> V_75 = V_71 ;
V_52 -> V_16 = V_70 ;
V_52 -> V_65 = V_72 ;
V_52 -> V_66 = V_73 ;
}
return V_74 ;
}
static int
F_36 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_3 * V_4 ;
struct V_49 * V_50 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_50 -> V_52 != V_52 )
continue;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_50 != V_50 )
continue;
V_4 -> V_50 = NULL ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
int F_37 ( struct V_82 * V_83 )
{
struct V_1 * V_2 ;
struct V_51 * V_84 , * V_85 , * V_52 ;
struct V_49 * V_86 , * V_87 , * V_50 ;
struct V_67 * V_68 = NULL ;
bool V_88 = false ;
bool V_89 = false ;
struct V_3 * V_90 , * V_4 ;
int V_27 = 0 , V_91 , V_92 = 0 ;
struct V_58 * V_59 ;
struct V_82 V_93 ;
int V_74 ;
int V_94 ;
F_9 ( L_9 ) ;
if ( ! V_83 )
return - V_95 ;
if ( ! V_83 -> V_52 )
return - V_95 ;
if ( ! V_83 -> V_52 -> V_26 )
return - V_95 ;
V_59 = V_83 -> V_52 -> V_26 ;
if ( ! V_83 -> V_16 )
V_83 -> V_61 = NULL ;
if ( V_83 -> V_61 ) {
F_9 ( L_10 ,
V_83 -> V_52 -> V_29 . V_30 , V_83 -> V_61 -> V_29 . V_30 ,
( int ) V_83 -> V_96 , V_83 -> V_65 , V_83 -> V_66 ) ;
} else {
F_9 ( L_11 , V_83 -> V_52 -> V_29 . V_30 ) ;
return F_36 ( V_83 -> V_52 ) ;
}
V_2 = V_83 -> V_52 -> V_2 ;
V_84 = F_38 ( V_2 -> V_12 . V_97 *
sizeof( struct V_51 ) , V_98 ) ;
if ( ! V_84 )
return - V_99 ;
V_86 = F_38 ( V_2 -> V_12 . V_100 *
sizeof( struct V_49 ) , V_98 ) ;
if ( ! V_86 ) {
F_39 ( V_84 ) ;
return - V_99 ;
}
V_90 = F_38 ( V_2 -> V_12 . V_101 *
sizeof( struct V_3 ) , V_98 ) ;
if ( ! V_90 ) {
F_39 ( V_84 ) ;
F_39 ( V_86 ) ;
return - V_99 ;
}
V_27 = 0 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
V_84 [ V_27 ++ ] = * V_52 ;
}
V_27 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_86 [ V_27 ++ ] = * V_50 ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
V_90 [ V_27 ++ ] = * V_4 ;
}
V_93 . V_52 = V_83 -> V_52 ;
V_93 . V_16 = & V_83 -> V_52 -> V_16 ;
V_93 . V_65 = V_83 -> V_52 -> V_65 ;
V_93 . V_66 = V_83 -> V_52 -> V_66 ;
V_93 . V_61 = V_83 -> V_52 -> V_61 ;
if ( V_83 -> V_52 -> V_61 != V_83 -> V_61 ) {
if ( V_83 -> V_52 -> V_61 == NULL ) {
F_9 ( L_12 ) ;
V_88 = true ;
} else if ( V_83 -> V_61 == NULL ) {
V_88 = true ;
} else if ( V_83 -> V_61 -> V_102 != V_83 -> V_52 -> V_61 -> V_102 ) {
V_88 = true ;
} else if ( V_83 -> V_61 -> V_103 !=
V_83 -> V_52 -> V_61 -> V_103 ) {
V_88 = true ;
} else
V_89 = true ;
}
if ( V_83 -> V_65 != V_83 -> V_52 -> V_65 || V_83 -> V_66 != V_83 -> V_52 -> V_66 )
V_89 = true ;
if ( V_83 -> V_16 && ! F_40 ( V_83 -> V_16 , & V_83 -> V_52 -> V_16 ) ) {
F_9 ( L_13 ) ;
F_23 ( & V_83 -> V_52 -> V_16 ) ;
F_23 ( V_83 -> V_16 ) ;
V_88 = true ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
struct V_24 * V_25 =
V_4 -> V_26 ;
V_87 = V_4 -> V_50 ;
for ( V_91 = 0 ; V_91 < V_83 -> V_96 ; V_91 ++ ) {
if ( V_83 -> V_104 [ V_91 ] == V_4 ) {
V_87 = V_25 -> V_105 ( V_4 ) ;
if ( V_87 == NULL )
V_92 = 1 ;
break;
}
}
if ( V_87 != V_4 -> V_50 ) {
F_9 ( L_14 ) ;
V_88 = true ;
if ( V_4 -> V_50 )
V_4 -> V_50 -> V_52 = NULL ;
V_4 -> V_50 = V_87 ;
}
}
if ( V_92 ) {
V_74 = - V_95 ;
goto V_92;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_50 )
continue;
if ( V_4 -> V_50 -> V_52 == V_83 -> V_52 )
V_85 = NULL ;
else
V_85 = V_4 -> V_50 -> V_52 ;
for ( V_91 = 0 ; V_91 < V_83 -> V_96 ; V_91 ++ ) {
if ( V_83 -> V_104 [ V_91 ] == V_4 )
V_85 = V_83 -> V_52 ;
}
if ( V_85 &&
! F_28 ( V_4 -> V_50 , V_85 ) ) {
V_74 = - V_95 ;
goto V_92;
}
if ( V_85 != V_4 -> V_50 -> V_52 ) {
F_9 ( L_15 ) ;
V_88 = true ;
V_4 -> V_50 -> V_52 = V_85 ;
}
if ( V_85 ) {
F_9 ( L_16 ,
V_4 -> V_29 . V_30 , F_10 ( V_4 ) ,
V_85 -> V_29 . V_30 ) ;
} else {
F_9 ( L_17 ,
V_4 -> V_29 . V_30 , F_10 ( V_4 ) ) ;
}
}
if ( V_89 && ! V_59 -> V_106 )
V_88 = true ;
if ( V_88 ) {
V_83 -> V_52 -> V_60 = F_25 ( V_83 -> V_52 ) ;
if ( V_83 -> V_52 -> V_60 ) {
F_9 ( L_18
L_19 ) ;
F_23 ( V_83 -> V_16 ) ;
V_68 = V_83 -> V_52 -> V_61 ;
V_83 -> V_52 -> V_61 = V_83 -> V_61 ;
if ( ! F_31 ( V_83 -> V_52 , V_83 -> V_16 ,
V_83 -> V_65 , V_83 -> V_66 ,
V_68 ) ) {
F_41 ( L_20 ,
V_83 -> V_52 -> V_29 . V_30 ) ;
V_83 -> V_52 -> V_61 = V_68 ;
V_74 = - V_95 ;
goto V_92;
}
F_9 ( L_21 ) ;
for ( V_94 = 0 ; V_94 < V_83 -> V_96 ; V_94 ++ ) {
F_9 ( L_22 , V_83 -> V_104 [ V_94 ] -> V_29 . V_30 ,
F_10 ( V_83 -> V_104 [ V_94 ] ) ) ;
V_83 -> V_104 [ V_94 ] -> V_36 -> V_56 ( V_83 -> V_104 [ V_94 ] , V_107 ) ;
}
}
F_27 ( V_2 ) ;
} else if ( V_89 ) {
V_83 -> V_52 -> V_65 = V_83 -> V_65 ;
V_83 -> V_52 -> V_66 = V_83 -> V_66 ;
V_68 = V_83 -> V_52 -> V_61 ;
if ( V_83 -> V_52 -> V_61 != V_83 -> V_61 )
V_83 -> V_52 -> V_61 = V_83 -> V_61 ;
V_74 = V_59 -> V_106 ( V_83 -> V_52 ,
V_83 -> V_65 , V_83 -> V_66 , V_68 ) ;
if ( V_74 != 0 ) {
V_83 -> V_52 -> V_61 = V_68 ;
goto V_92;
}
}
F_39 ( V_90 ) ;
F_39 ( V_86 ) ;
F_39 ( V_84 ) ;
return 0 ;
V_92:
V_27 = 0 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
* V_52 = V_84 [ V_27 ++ ] ;
}
V_27 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
* V_50 = V_86 [ V_27 ++ ] ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_90 [ V_27 ++ ] ;
}
if ( V_88 &&
! F_31 ( V_93 . V_52 , V_93 . V_16 , V_93 . V_65 ,
V_93 . V_66 , V_93 . V_61 ) )
F_41 ( L_23 ) ;
F_39 ( V_90 ) ;
F_39 ( V_86 ) ;
F_39 ( V_84 ) ;
return V_74 ;
}
static int F_42 ( struct V_49 * V_50 )
{
int V_56 = V_57 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_50 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_50 == V_50 )
if ( V_4 -> V_56 < V_56 )
V_56 = V_4 -> V_56 ;
return V_56 ;
}
static int F_43 ( struct V_51 * V_52 )
{
int V_56 = V_57 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_52 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_50 && V_4 -> V_50 -> V_52 == V_52 )
if ( V_4 -> V_56 < V_56 )
V_56 = V_4 -> V_56 ;
return V_56 ;
}
void F_44 ( struct V_3 * V_4 , int V_16 )
{
struct V_49 * V_50 = V_4 -> V_50 ;
struct V_51 * V_52 = V_50 ? V_50 -> V_52 : NULL ;
int V_108 ;
if ( V_16 == V_4 -> V_56 )
return;
V_108 = V_4 -> V_56 ;
V_4 -> V_56 = V_16 ;
if ( V_16 < V_108 ) {
if ( V_52 ) {
struct V_58 * V_59 = V_52 -> V_26 ;
if ( V_59 -> V_56 )
(* V_59 -> V_56 ) ( V_52 ,
F_43 ( V_52 ) ) ;
}
if ( V_50 ) {
struct V_53 * V_54 = V_50 -> V_26 ;
if ( V_54 -> V_56 )
(* V_54 -> V_56 ) ( V_50 ,
F_42 ( V_50 ) ) ;
}
}
if ( V_16 > V_108 ) {
if ( V_50 ) {
struct V_53 * V_54 = V_50 -> V_26 ;
if ( V_54 -> V_56 )
(* V_54 -> V_56 ) ( V_50 ,
F_42 ( V_50 ) ) ;
}
if ( V_52 ) {
struct V_58 * V_59 = V_52 -> V_26 ;
if ( V_59 -> V_56 )
(* V_59 -> V_56 ) ( V_52 ,
F_43 ( V_52 ) ) ;
}
}
return;
}
int F_45 ( struct V_67 * V_61 ,
struct V_109 * V_110 )
{
int V_94 ;
V_61 -> V_111 = V_110 -> V_111 ;
V_61 -> V_112 = V_110 -> V_112 ;
for ( V_94 = 0 ; V_94 < 4 ; V_94 ++ ) {
V_61 -> V_113 [ V_94 ] = V_110 -> V_113 [ V_94 ] ;
V_61 -> V_114 [ V_94 ] = V_110 -> V_114 [ V_94 ] ;
}
F_46 ( V_110 -> V_115 , & V_61 -> V_102 ,
& V_61 -> V_103 ) ;
V_61 -> V_115 = V_110 -> V_115 ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_49 * V_50 ;
struct V_53 * V_54 ;
struct V_58 * V_59 ;
int V_74 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_52 -> V_60 )
continue;
V_74 = F_31 ( V_52 , & V_52 -> V_16 ,
V_52 -> V_65 , V_52 -> V_66 , V_52 -> V_61 ) ;
if ( V_74 == false )
F_41 ( L_24 , V_52 ) ;
if ( F_43 ( V_52 ) ) {
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if( V_50 -> V_52 != V_52 )
continue;
V_54 = V_50 -> V_26 ;
if ( V_54 -> V_56 )
(* V_54 -> V_56 ) ( V_50 ,
F_42 ( V_50 ) ) ;
}
V_59 = V_52 -> V_26 ;
if ( V_59 -> V_56 )
(* V_59 -> V_56 ) ( V_52 ,
F_43 ( V_52 ) ) ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 ) ;
if ( V_2 -> V_12 . V_36 -> V_116 )
V_2 -> V_12 . V_36 -> V_116 ( V_2 ) ;
}
static void F_50 ( struct V_117 * V_118 )
{
struct V_119 * V_119 = F_51 ( V_118 ) ;
struct V_1 * V_2 = F_52 ( V_119 , struct V_1 , V_12 . V_120 ) ;
struct V_3 * V_4 ;
enum V_121 V_122 ;
bool V_123 = false , V_124 = false ;
if ( ! V_38 )
return;
F_53 ( & V_2 -> V_12 . V_125 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_32 )
continue;
if ( ! V_4 -> V_126 || V_4 -> V_126 == V_127 )
continue;
V_123 = true ;
V_122 = V_4 -> V_19 ;
if ( V_122 == V_34 &&
! ( V_4 -> V_126 & V_128 ) )
continue;
V_4 -> V_19 = V_4 -> V_36 -> V_37 ( V_4 , false ) ;
F_9 ( L_25 ,
V_4 -> V_29 . V_30 ,
F_10 ( V_4 ) ,
V_122 , V_4 -> V_19 ) ;
if ( V_122 != V_4 -> V_19 )
V_124 = true ;
}
F_54 ( & V_2 -> V_12 . V_125 ) ;
if ( V_124 )
F_48 ( V_2 ) ;
if ( V_123 )
F_55 ( V_119 , V_129 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_12 . V_130 )
return;
F_57 ( & V_2 -> V_12 . V_120 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
bool V_131 = false ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_12 . V_130 || ! V_38 )
return;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_126 & ( V_132 |
V_128 ) )
V_131 = true ;
}
if ( V_131 )
F_55 ( & V_2 -> V_12 . V_120 , V_129 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_12 . V_120 , F_50 ) ;
V_2 -> V_12 . V_130 = true ;
F_11 ( V_2 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_121 V_122 ;
bool V_124 = false ;
if ( ! V_2 -> V_12 . V_130 )
return;
F_53 ( & V_2 -> V_12 . V_125 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_4 -> V_126 & V_127 ) )
continue;
V_122 = V_4 -> V_19 ;
V_4 -> V_19 = V_4 -> V_36 -> V_37 ( V_4 , false ) ;
F_9 ( L_25 ,
V_4 -> V_29 . V_30 ,
F_10 ( V_4 ) ,
V_122 , V_4 -> V_19 ) ;
if ( V_122 != V_4 -> V_19 )
V_124 = true ;
}
F_54 ( & V_2 -> V_12 . V_125 ) ;
if ( V_124 )
F_48 ( V_2 ) ;
}
