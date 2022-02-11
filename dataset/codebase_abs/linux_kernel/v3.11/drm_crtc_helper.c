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
bool V_29 = true ;
F_9 ( L_1 , V_4 -> V_30 . V_31 ,
F_10 ( V_4 ) ) ;
F_7 (mode, &connector->modes, head)
V_16 -> V_19 = V_32 ;
if ( V_4 -> V_33 ) {
if ( V_4 -> V_33 == V_34 )
V_4 -> V_19 = V_35 ;
else
V_4 -> V_19 = V_36 ;
if ( V_4 -> V_37 -> V_33 )
V_4 -> V_37 -> V_33 ( V_4 ) ;
} else {
V_4 -> V_19 = V_4 -> V_37 -> V_38 ( V_4 , true ) ;
}
if ( V_39 != V_2 -> V_12 . V_40 )
F_11 ( V_2 ) ;
V_2 -> V_12 . V_40 = V_39 ;
if ( V_4 -> V_19 == V_36 ) {
F_9 ( L_2 ,
V_4 -> V_30 . V_31 , F_10 ( V_4 ) ) ;
F_12 ( V_4 , NULL ) ;
V_29 = false ;
goto V_41;
}
#ifdef F_13
V_27 = F_14 ( V_4 ) ;
if ( V_27 == 0 )
#endif
V_27 = (* V_25 -> V_42 )( V_4 ) ;
if ( V_27 == 0 && V_4 -> V_19 == V_35 )
V_27 = F_15 ( V_4 , 1024 , 768 ) ;
if ( V_27 == 0 )
goto V_41;
F_16 ( V_4 ) ;
if ( V_22 && V_23 )
F_17 ( V_2 , & V_4 -> V_43 , V_22 ,
V_23 , 0 ) ;
if ( V_4 -> V_44 )
V_28 |= V_18 ;
if ( V_4 -> V_45 )
V_28 |= V_17 ;
F_6 ( V_4 , V_28 ) ;
F_7 (mode, &connector->modes, head) {
if ( V_16 -> V_19 == V_46 )
V_16 -> V_19 = V_25 -> V_47 ( V_4 ,
V_16 ) ;
}
V_41:
F_18 ( V_2 , & V_4 -> V_43 , V_29 ) ;
if ( F_19 ( & V_4 -> V_43 ) )
return 0 ;
F_7 (mode, &connector->modes, head)
V_16 -> V_48 = F_20 ( V_16 ) ;
F_21 ( & V_4 -> V_43 ) ;
F_9 ( L_3 , V_4 -> V_30 . V_31 ,
F_10 ( V_4 ) ) ;
F_7 (mode, &connector->modes, head) {
F_22 ( V_16 , V_49 ) ;
F_23 ( V_16 ) ;
}
return V_27 ;
}
bool F_24 ( struct V_50 * V_51 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = V_51 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_51 == V_51 )
return true ;
return false ;
}
bool F_25 ( struct V_52 * V_53 )
{
struct V_50 * V_51 ;
struct V_1 * V_2 = V_53 -> V_2 ;
F_7 (encoder, &dev->mode_config.encoder_list, head)
if ( V_51 -> V_53 == V_53 && F_24 ( V_51 ) )
return true ;
return false ;
}
static void
F_26 ( struct V_50 * V_51 )
{
struct V_54 * V_55 = V_51 -> V_26 ;
if ( V_55 -> V_56 )
(* V_55 -> V_56 )( V_51 ) ;
else
(* V_55 -> V_57 )( V_51 , V_58 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
struct V_3 * V_4 ;
struct V_52 * V_53 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_51 )
continue;
if ( V_4 -> V_19 == V_36 )
V_4 -> V_51 = NULL ;
}
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_24 ( V_51 ) ) {
F_26 ( V_51 ) ;
V_51 -> V_53 = NULL ;
}
}
F_7 (crtc, &dev->mode_config.crtc_list, head) {
struct V_59 * V_60 = V_53 -> V_26 ;
V_53 -> V_61 = F_25 ( V_53 ) ;
if ( ! V_53 -> V_61 ) {
if ( V_60 -> V_56 )
(* V_60 -> V_56 )( V_53 ) ;
else
(* V_60 -> V_57 )( V_53 , V_58 ) ;
V_53 -> V_62 = NULL ;
}
}
}
static bool F_28 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_52 * V_5 ;
int V_63 = 1 ;
F_29 ( ! V_53 , L_4 ) ;
V_2 = V_53 -> V_2 ;
F_7 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_5 == V_53 )
break;
V_63 <<= 1 ;
}
if ( V_51 -> V_64 & V_63 )
return true ;
return false ;
}
static void
F_30 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
struct V_50 * V_51 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_55 = V_51 -> V_26 ;
if ( V_51 -> V_53 == NULL )
F_26 ( V_51 ) ;
if ( V_55 -> V_65 &&
V_51 -> V_53 != (* V_55 -> V_65 )( V_51 ) )
F_26 ( V_51 ) ;
}
}
bool F_31 ( struct V_52 * V_53 ,
struct V_15 * V_16 ,
int V_66 , int V_67 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_15 * V_70 , V_71 , V_72 ;
struct V_59 * V_60 = V_53 -> V_26 ;
struct V_54 * V_55 ;
int V_73 , V_74 ;
struct V_50 * V_51 ;
bool V_75 = true ;
V_53 -> V_61 = F_25 ( V_53 ) ;
if ( ! V_53 -> V_61 )
return true ;
V_70 = F_32 ( V_2 , V_16 ) ;
if ( ! V_70 )
return false ;
V_72 = V_53 -> V_76 ;
V_71 = V_53 -> V_16 ;
V_73 = V_53 -> V_66 ;
V_74 = V_53 -> V_67 ;
V_53 -> V_16 = * V_16 ;
V_53 -> V_66 = V_66 ;
V_53 -> V_67 = V_67 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
V_55 = V_51 -> V_26 ;
if ( ! ( V_75 = V_55 -> V_77 ( V_51 , V_16 ,
V_70 ) ) ) {
F_9 ( L_5 ) ;
goto V_78;
}
}
if ( ! ( V_75 = V_60 -> V_77 ( V_53 , V_16 , V_70 ) ) ) {
F_9 ( L_6 ) ;
goto V_78;
}
F_9 ( L_7 , V_53 -> V_30 . V_31 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
V_55 = V_51 -> V_26 ;
V_55 -> V_79 ( V_51 ) ;
}
F_30 ( V_2 ) ;
V_60 -> V_79 ( V_53 ) ;
V_75 = ! V_60 -> V_80 ( V_53 , V_16 , V_70 , V_66 , V_67 , V_69 ) ;
if ( ! V_75 )
goto V_78;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
F_9 ( L_8 ,
V_51 -> V_30 . V_31 , F_33 ( V_51 ) ,
V_16 -> V_30 . V_31 , V_16 -> V_81 ) ;
V_55 = V_51 -> V_26 ;
V_55 -> V_80 ( V_51 , V_16 , V_70 ) ;
}
V_60 -> V_82 ( V_53 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
V_55 = V_51 -> V_26 ;
V_55 -> V_82 ( V_51 ) ;
}
V_53 -> V_76 = * V_70 ;
F_34 ( V_53 ) ;
V_78:
F_35 ( V_2 , V_70 ) ;
if ( ! V_75 ) {
V_53 -> V_76 = V_72 ;
V_53 -> V_16 = V_71 ;
V_53 -> V_66 = V_73 ;
V_53 -> V_67 = V_74 ;
}
return V_75 ;
}
static int
F_36 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_3 * V_4 ;
struct V_50 * V_51 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_51 != V_51 )
continue;
V_4 -> V_51 = NULL ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
int F_37 ( struct V_83 * V_84 )
{
struct V_1 * V_2 ;
struct V_52 * V_85 , * V_86 , * V_53 ;
struct V_50 * V_87 , * V_88 , * V_51 ;
struct V_68 * V_69 = NULL ;
bool V_89 = false ;
bool V_90 = false ;
struct V_3 * V_91 , * V_4 ;
int V_27 = 0 , V_92 , V_93 = 0 ;
struct V_59 * V_60 ;
struct V_83 V_94 ;
int V_75 ;
int V_95 ;
F_9 ( L_9 ) ;
F_38 ( ! V_84 ) ;
F_38 ( ! V_84 -> V_53 ) ;
F_38 ( ! V_84 -> V_53 -> V_26 ) ;
F_38 ( ! V_84 -> V_16 && V_84 -> V_62 ) ;
F_38 ( V_84 -> V_62 && V_84 -> V_96 == 0 ) ;
V_60 = V_84 -> V_53 -> V_26 ;
if ( ! V_84 -> V_16 )
V_84 -> V_62 = NULL ;
if ( V_84 -> V_62 ) {
F_9 ( L_10 ,
V_84 -> V_53 -> V_30 . V_31 , V_84 -> V_62 -> V_30 . V_31 ,
( int ) V_84 -> V_96 , V_84 -> V_66 , V_84 -> V_67 ) ;
} else {
F_9 ( L_11 , V_84 -> V_53 -> V_30 . V_31 ) ;
return F_36 ( V_84 -> V_53 ) ;
}
V_2 = V_84 -> V_53 -> V_2 ;
V_85 = F_39 ( V_2 -> V_12 . V_97 *
sizeof( struct V_52 ) , V_98 ) ;
if ( ! V_85 )
return - V_99 ;
V_87 = F_39 ( V_2 -> V_12 . V_100 *
sizeof( struct V_50 ) , V_98 ) ;
if ( ! V_87 ) {
F_40 ( V_85 ) ;
return - V_99 ;
}
V_91 = F_39 ( V_2 -> V_12 . V_101 *
sizeof( struct V_3 ) , V_98 ) ;
if ( ! V_91 ) {
F_40 ( V_85 ) ;
F_40 ( V_87 ) ;
return - V_99 ;
}
V_27 = 0 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
V_85 [ V_27 ++ ] = * V_53 ;
}
V_27 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_87 [ V_27 ++ ] = * V_51 ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
V_91 [ V_27 ++ ] = * V_4 ;
}
V_94 . V_53 = V_84 -> V_53 ;
V_94 . V_16 = & V_84 -> V_53 -> V_16 ;
V_94 . V_66 = V_84 -> V_53 -> V_66 ;
V_94 . V_67 = V_84 -> V_53 -> V_67 ;
V_94 . V_62 = V_84 -> V_53 -> V_62 ;
if ( V_84 -> V_53 -> V_62 != V_84 -> V_62 ) {
if ( V_84 -> V_53 -> V_62 == NULL ) {
F_9 ( L_12 ) ;
V_89 = true ;
} else if ( V_84 -> V_62 == NULL ) {
V_89 = true ;
} else if ( V_84 -> V_62 -> V_102 !=
V_84 -> V_53 -> V_62 -> V_102 ) {
V_89 = true ;
} else
V_90 = true ;
}
if ( V_84 -> V_66 != V_84 -> V_53 -> V_66 || V_84 -> V_67 != V_84 -> V_53 -> V_67 )
V_90 = true ;
if ( V_84 -> V_16 && ! F_41 ( V_84 -> V_16 , & V_84 -> V_53 -> V_16 ) ) {
F_9 ( L_13 ) ;
F_23 ( & V_84 -> V_53 -> V_16 ) ;
F_23 ( V_84 -> V_16 ) ;
V_89 = true ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
struct V_24 * V_25 =
V_4 -> V_26 ;
V_88 = V_4 -> V_51 ;
for ( V_92 = 0 ; V_92 < V_84 -> V_96 ; V_92 ++ ) {
if ( V_84 -> V_103 [ V_92 ] == V_4 ) {
V_88 = V_25 -> V_104 ( V_4 ) ;
if ( V_88 == NULL )
V_93 = 1 ;
break;
if ( V_4 -> V_57 != V_105 ) {
F_9 ( L_14 ) ;
V_89 = true ;
}
}
}
if ( V_88 != V_4 -> V_51 ) {
F_9 ( L_15 ) ;
V_89 = true ;
if ( V_4 -> V_51 )
V_4 -> V_51 -> V_53 = NULL ;
V_4 -> V_51 = V_88 ;
}
}
if ( V_93 ) {
V_75 = - V_106 ;
goto V_93;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_51 )
continue;
if ( V_4 -> V_51 -> V_53 == V_84 -> V_53 )
V_86 = NULL ;
else
V_86 = V_4 -> V_51 -> V_53 ;
for ( V_92 = 0 ; V_92 < V_84 -> V_96 ; V_92 ++ ) {
if ( V_84 -> V_103 [ V_92 ] == V_4 )
V_86 = V_84 -> V_53 ;
}
if ( V_86 &&
! F_28 ( V_4 -> V_51 , V_86 ) ) {
V_75 = - V_106 ;
goto V_93;
}
if ( V_86 != V_4 -> V_51 -> V_53 ) {
F_9 ( L_16 ) ;
V_89 = true ;
V_4 -> V_51 -> V_53 = V_86 ;
}
if ( V_86 ) {
F_9 ( L_17 ,
V_4 -> V_30 . V_31 , F_10 ( V_4 ) ,
V_86 -> V_30 . V_31 ) ;
} else {
F_9 ( L_18 ,
V_4 -> V_30 . V_31 , F_10 ( V_4 ) ) ;
}
}
if ( V_90 && ! V_60 -> V_107 )
V_89 = true ;
if ( V_89 ) {
V_84 -> V_53 -> V_61 = F_25 ( V_84 -> V_53 ) ;
if ( V_84 -> V_53 -> V_61 ) {
F_9 ( L_19
L_20 ) ;
F_23 ( V_84 -> V_16 ) ;
V_69 = V_84 -> V_53 -> V_62 ;
V_84 -> V_53 -> V_62 = V_84 -> V_62 ;
if ( ! F_31 ( V_84 -> V_53 , V_84 -> V_16 ,
V_84 -> V_66 , V_84 -> V_67 ,
V_69 ) ) {
F_42 ( L_21 ,
V_84 -> V_53 -> V_30 . V_31 ) ;
V_84 -> V_53 -> V_62 = V_69 ;
V_75 = - V_106 ;
goto V_93;
}
F_9 ( L_22 ) ;
for ( V_95 = 0 ; V_95 < V_84 -> V_96 ; V_95 ++ ) {
F_9 ( L_23 , V_84 -> V_103 [ V_95 ] -> V_30 . V_31 ,
F_10 ( V_84 -> V_103 [ V_95 ] ) ) ;
V_84 -> V_103 [ V_95 ] -> V_37 -> V_57 ( V_84 -> V_103 [ V_95 ] , V_105 ) ;
}
}
F_27 ( V_2 ) ;
} else if ( V_90 ) {
V_84 -> V_53 -> V_66 = V_84 -> V_66 ;
V_84 -> V_53 -> V_67 = V_84 -> V_67 ;
V_69 = V_84 -> V_53 -> V_62 ;
if ( V_84 -> V_53 -> V_62 != V_84 -> V_62 )
V_84 -> V_53 -> V_62 = V_84 -> V_62 ;
V_75 = V_60 -> V_107 ( V_84 -> V_53 ,
V_84 -> V_66 , V_84 -> V_67 , V_69 ) ;
if ( V_75 != 0 ) {
V_84 -> V_53 -> V_62 = V_69 ;
goto V_93;
}
}
F_40 ( V_91 ) ;
F_40 ( V_87 ) ;
F_40 ( V_85 ) ;
return 0 ;
V_93:
V_27 = 0 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
* V_53 = V_85 [ V_27 ++ ] ;
}
V_27 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
* V_51 = V_87 [ V_27 ++ ] ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_91 [ V_27 ++ ] ;
}
if ( V_89 &&
! F_31 ( V_94 . V_53 , V_94 . V_16 , V_94 . V_66 ,
V_94 . V_67 , V_94 . V_62 ) )
F_42 ( L_24 ) ;
F_40 ( V_91 ) ;
F_40 ( V_87 ) ;
F_40 ( V_85 ) ;
return V_75 ;
}
static int F_43 ( struct V_50 * V_51 )
{
int V_57 = V_58 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_51 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_51 == V_51 )
if ( V_4 -> V_57 < V_57 )
V_57 = V_4 -> V_57 ;
return V_57 ;
}
static int F_44 ( struct V_52 * V_53 )
{
int V_57 = V_58 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_53 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_51 && V_4 -> V_51 -> V_53 == V_53 )
if ( V_4 -> V_57 < V_57 )
V_57 = V_4 -> V_57 ;
return V_57 ;
}
void F_45 ( struct V_3 * V_4 , int V_16 )
{
struct V_50 * V_51 = V_4 -> V_51 ;
struct V_52 * V_53 = V_51 ? V_51 -> V_53 : NULL ;
int V_108 ;
if ( V_16 == V_4 -> V_57 )
return;
V_108 = V_4 -> V_57 ;
V_4 -> V_57 = V_16 ;
if ( V_16 < V_108 ) {
if ( V_53 ) {
struct V_59 * V_60 = V_53 -> V_26 ;
if ( V_60 -> V_57 )
(* V_60 -> V_57 ) ( V_53 ,
F_44 ( V_53 ) ) ;
}
if ( V_51 ) {
struct V_54 * V_55 = V_51 -> V_26 ;
if ( V_55 -> V_57 )
(* V_55 -> V_57 ) ( V_51 ,
F_43 ( V_51 ) ) ;
}
}
if ( V_16 > V_108 ) {
if ( V_51 ) {
struct V_54 * V_55 = V_51 -> V_26 ;
if ( V_55 -> V_57 )
(* V_55 -> V_57 ) ( V_51 ,
F_43 ( V_51 ) ) ;
}
if ( V_53 ) {
struct V_59 * V_60 = V_53 -> V_26 ;
if ( V_60 -> V_57 )
(* V_60 -> V_57 ) ( V_53 ,
F_44 ( V_53 ) ) ;
}
}
return;
}
int F_46 ( struct V_68 * V_62 ,
struct V_109 * V_110 )
{
int V_95 ;
V_62 -> V_111 = V_110 -> V_111 ;
V_62 -> V_112 = V_110 -> V_112 ;
for ( V_95 = 0 ; V_95 < 4 ; V_95 ++ ) {
V_62 -> V_113 [ V_95 ] = V_110 -> V_113 [ V_95 ] ;
V_62 -> V_114 [ V_95 ] = V_110 -> V_114 [ V_95 ] ;
}
F_47 ( V_110 -> V_102 , & V_62 -> V_115 ,
& V_62 -> V_116 ) ;
V_62 -> V_102 = V_110 -> V_102 ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
struct V_50 * V_51 ;
struct V_54 * V_55 ;
struct V_59 * V_60 ;
int V_75 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_53 -> V_61 )
continue;
V_75 = F_31 ( V_53 , & V_53 -> V_16 ,
V_53 -> V_66 , V_53 -> V_67 , V_53 -> V_62 ) ;
if ( V_75 == false )
F_42 ( L_25 , V_53 ) ;
if ( F_44 ( V_53 ) ) {
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if( V_51 -> V_53 != V_53 )
continue;
V_55 = V_51 -> V_26 ;
if ( V_55 -> V_57 )
(* V_55 -> V_57 ) ( V_51 ,
F_43 ( V_51 ) ) ;
}
V_60 = V_53 -> V_26 ;
if ( V_60 -> V_57 )
(* V_60 -> V_57 ) ( V_53 ,
F_44 ( V_53 ) ) ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
if ( V_2 -> V_12 . V_37 -> V_117 )
V_2 -> V_12 . V_37 -> V_117 ( V_2 ) ;
}
static void F_51 ( struct V_118 * V_119 )
{
struct V_120 * V_120 = F_52 ( V_119 ) ;
struct V_1 * V_2 = F_53 ( V_120 , struct V_1 , V_12 . V_121 ) ;
struct V_3 * V_4 ;
enum V_122 V_123 ;
bool V_124 = false , V_125 = false ;
if ( ! V_39 )
return;
F_54 ( & V_2 -> V_12 . V_126 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_33 )
continue;
if ( ! V_4 -> V_127 || V_4 -> V_127 == V_128 )
continue;
V_124 = true ;
V_123 = V_4 -> V_19 ;
if ( V_123 == V_35 &&
! ( V_4 -> V_127 & V_129 ) )
continue;
V_4 -> V_19 = V_4 -> V_37 -> V_38 ( V_4 , false ) ;
if ( V_123 != V_4 -> V_19 ) {
const char * V_130 , * V_131 ;
V_130 = F_55 ( V_123 ) ;
V_131 = F_55 ( V_4 -> V_19 ) ;
F_9 ( L_26
L_27 ,
V_4 -> V_30 . V_31 ,
F_10 ( V_4 ) ,
V_130 , V_131 ) ;
V_125 = true ;
}
}
F_56 ( & V_2 -> V_12 . V_126 ) ;
if ( V_125 )
F_49 ( V_2 ) ;
if ( V_124 )
F_57 ( V_120 , V_132 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_12 . V_133 )
return;
F_59 ( & V_2 -> V_12 . V_121 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
bool V_134 = false ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_12 . V_133 || ! V_39 )
return;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_127 & ( V_135 |
V_129 ) )
V_134 = true ;
}
if ( V_134 )
F_57 ( & V_2 -> V_12 . V_121 , V_132 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_61 ( & V_2 -> V_12 . V_121 , F_51 ) ;
V_2 -> V_12 . V_133 = true ;
F_11 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_122 V_123 ;
bool V_125 = false ;
if ( ! V_2 -> V_12 . V_133 )
return;
F_54 ( & V_2 -> V_12 . V_126 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_4 -> V_127 & V_128 ) )
continue;
V_123 = V_4 -> V_19 ;
V_4 -> V_19 = V_4 -> V_37 -> V_38 ( V_4 , false ) ;
F_9 ( L_28 ,
V_4 -> V_30 . V_31 ,
F_10 ( V_4 ) ,
F_55 ( V_123 ) ,
F_55 ( V_4 -> V_19 ) ) ;
if ( V_123 != V_4 -> V_19 )
V_125 = true ;
}
F_56 ( & V_2 -> V_12 . V_126 ) ;
if ( V_125 )
F_49 ( V_2 ) ;
}
