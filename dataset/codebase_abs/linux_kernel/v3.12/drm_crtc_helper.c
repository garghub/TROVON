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
if ( V_51 -> V_56 )
V_51 -> V_56 -> V_37 -> V_57 ( V_51 -> V_56 ) ;
if ( V_55 -> V_57 )
(* V_55 -> V_57 )( V_51 ) ;
else
(* V_55 -> V_58 )( V_51 , V_59 ) ;
if ( V_51 -> V_56 )
V_51 -> V_56 -> V_37 -> V_60 ( V_51 -> V_56 ) ;
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
struct V_61 * V_62 = V_53 -> V_26 ;
V_53 -> V_63 = F_25 ( V_53 ) ;
if ( ! V_53 -> V_63 ) {
if ( V_62 -> V_57 )
(* V_62 -> V_57 )( V_53 ) ;
else
(* V_62 -> V_58 )( V_53 , V_59 ) ;
V_53 -> V_64 = NULL ;
}
}
}
static bool F_28 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_52 * V_5 ;
int V_65 = 1 ;
F_29 ( ! V_53 , L_4 ) ;
V_2 = V_53 -> V_2 ;
F_7 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_5 == V_53 )
break;
V_65 <<= 1 ;
}
if ( V_51 -> V_66 & V_65 )
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
if ( V_55 -> V_67 &&
V_51 -> V_53 != (* V_55 -> V_67 )( V_51 ) )
F_26 ( V_51 ) ;
}
}
bool F_31 ( struct V_52 * V_53 ,
struct V_15 * V_16 ,
int V_68 , int V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_15 * V_72 , V_73 , V_74 ;
struct V_61 * V_62 = V_53 -> V_26 ;
struct V_54 * V_55 ;
int V_75 , V_76 ;
struct V_50 * V_51 ;
bool V_77 = true ;
V_53 -> V_63 = F_25 ( V_53 ) ;
if ( ! V_53 -> V_63 )
return true ;
V_72 = F_32 ( V_2 , V_16 ) ;
if ( ! V_72 )
return false ;
V_74 = V_53 -> V_78 ;
V_73 = V_53 -> V_16 ;
V_75 = V_53 -> V_68 ;
V_76 = V_53 -> V_69 ;
V_53 -> V_16 = * V_16 ;
V_53 -> V_68 = V_68 ;
V_53 -> V_69 = V_69 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
if ( V_51 -> V_56 && V_51 -> V_56 -> V_37 -> V_79 ) {
V_77 = V_51 -> V_56 -> V_37 -> V_79 (
V_51 -> V_56 , V_16 , V_72 ) ;
if ( ! V_77 ) {
F_9 ( L_5 ) ;
goto V_80;
}
}
V_55 = V_51 -> V_26 ;
if ( ! ( V_77 = V_55 -> V_79 ( V_51 , V_16 ,
V_72 ) ) ) {
F_9 ( L_6 ) ;
goto V_80;
}
}
if ( ! ( V_77 = V_62 -> V_79 ( V_53 , V_16 , V_72 ) ) ) {
F_9 ( L_7 ) ;
goto V_80;
}
F_9 ( L_8 , V_53 -> V_30 . V_31 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
if ( V_51 -> V_56 )
V_51 -> V_56 -> V_37 -> V_57 ( V_51 -> V_56 ) ;
V_55 = V_51 -> V_26 ;
V_55 -> V_81 ( V_51 ) ;
if ( V_51 -> V_56 )
V_51 -> V_56 -> V_37 -> V_60 ( V_51 -> V_56 ) ;
}
F_30 ( V_2 ) ;
V_62 -> V_81 ( V_53 ) ;
V_77 = ! V_62 -> V_82 ( V_53 , V_16 , V_72 , V_68 , V_69 , V_71 ) ;
if ( ! V_77 )
goto V_80;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
F_9 ( L_9 ,
V_51 -> V_30 . V_31 , F_33 ( V_51 ) ,
V_16 -> V_30 . V_31 , V_16 -> V_83 ) ;
V_55 = V_51 -> V_26 ;
V_55 -> V_82 ( V_51 , V_16 , V_72 ) ;
if ( V_51 -> V_56 && V_51 -> V_56 -> V_37 -> V_82 )
V_51 -> V_56 -> V_37 -> V_82 ( V_51 -> V_56 , V_16 ,
V_72 ) ;
}
V_62 -> V_84 ( V_53 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_51 -> V_53 != V_53 )
continue;
if ( V_51 -> V_56 )
V_51 -> V_56 -> V_37 -> V_85 ( V_51 -> V_56 ) ;
V_55 = V_51 -> V_26 ;
V_55 -> V_84 ( V_51 ) ;
if ( V_51 -> V_56 )
V_51 -> V_56 -> V_37 -> V_86 ( V_51 -> V_56 ) ;
}
V_53 -> V_78 = * V_72 ;
F_34 ( V_53 ) ;
V_80:
F_35 ( V_2 , V_72 ) ;
if ( ! V_77 ) {
V_53 -> V_78 = V_74 ;
V_53 -> V_16 = V_73 ;
V_53 -> V_68 = V_75 ;
V_53 -> V_69 = V_76 ;
}
return V_77 ;
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
int F_37 ( struct V_87 * V_88 )
{
struct V_1 * V_2 ;
struct V_52 * V_89 , * V_90 , * V_53 ;
struct V_50 * V_91 , * V_92 , * V_51 ;
struct V_70 * V_71 = NULL ;
bool V_93 = false ;
bool V_94 = false ;
struct V_3 * V_95 , * V_4 ;
int V_27 = 0 , V_96 , V_97 = 0 ;
struct V_61 * V_62 ;
struct V_87 V_98 ;
int V_77 ;
int V_99 ;
F_9 ( L_10 ) ;
F_38 ( ! V_88 ) ;
F_38 ( ! V_88 -> V_53 ) ;
F_38 ( ! V_88 -> V_53 -> V_26 ) ;
F_38 ( ! V_88 -> V_16 && V_88 -> V_64 ) ;
F_38 ( V_88 -> V_64 && V_88 -> V_100 == 0 ) ;
V_62 = V_88 -> V_53 -> V_26 ;
if ( ! V_88 -> V_16 )
V_88 -> V_64 = NULL ;
if ( V_88 -> V_64 ) {
F_9 ( L_11 ,
V_88 -> V_53 -> V_30 . V_31 , V_88 -> V_64 -> V_30 . V_31 ,
( int ) V_88 -> V_100 , V_88 -> V_68 , V_88 -> V_69 ) ;
} else {
F_9 ( L_12 , V_88 -> V_53 -> V_30 . V_31 ) ;
return F_36 ( V_88 -> V_53 ) ;
}
V_2 = V_88 -> V_53 -> V_2 ;
V_89 = F_39 ( V_2 -> V_12 . V_101 *
sizeof( struct V_52 ) , V_102 ) ;
if ( ! V_89 )
return - V_103 ;
V_91 = F_39 ( V_2 -> V_12 . V_104 *
sizeof( struct V_50 ) , V_102 ) ;
if ( ! V_91 ) {
F_40 ( V_89 ) ;
return - V_103 ;
}
V_95 = F_39 ( V_2 -> V_12 . V_105 *
sizeof( struct V_3 ) , V_102 ) ;
if ( ! V_95 ) {
F_40 ( V_89 ) ;
F_40 ( V_91 ) ;
return - V_103 ;
}
V_27 = 0 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
V_89 [ V_27 ++ ] = * V_53 ;
}
V_27 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_91 [ V_27 ++ ] = * V_51 ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
V_95 [ V_27 ++ ] = * V_4 ;
}
V_98 . V_53 = V_88 -> V_53 ;
V_98 . V_16 = & V_88 -> V_53 -> V_16 ;
V_98 . V_68 = V_88 -> V_53 -> V_68 ;
V_98 . V_69 = V_88 -> V_53 -> V_69 ;
V_98 . V_64 = V_88 -> V_53 -> V_64 ;
if ( V_88 -> V_53 -> V_64 != V_88 -> V_64 ) {
if ( V_88 -> V_53 -> V_64 == NULL ) {
F_9 ( L_13 ) ;
V_93 = true ;
} else if ( V_88 -> V_64 == NULL ) {
V_93 = true ;
} else if ( V_88 -> V_64 -> V_106 !=
V_88 -> V_53 -> V_64 -> V_106 ) {
V_93 = true ;
} else
V_94 = true ;
}
if ( V_88 -> V_68 != V_88 -> V_53 -> V_68 || V_88 -> V_69 != V_88 -> V_53 -> V_69 )
V_94 = true ;
if ( V_88 -> V_16 && ! F_41 ( V_88 -> V_16 , & V_88 -> V_53 -> V_16 ) ) {
F_9 ( L_14 ) ;
F_23 ( & V_88 -> V_53 -> V_16 ) ;
F_23 ( V_88 -> V_16 ) ;
V_93 = true ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
struct V_24 * V_25 =
V_4 -> V_26 ;
V_92 = V_4 -> V_51 ;
for ( V_96 = 0 ; V_96 < V_88 -> V_100 ; V_96 ++ ) {
if ( V_88 -> V_107 [ V_96 ] == V_4 ) {
V_92 = V_25 -> V_108 ( V_4 ) ;
if ( V_92 == NULL )
V_97 = 1 ;
break;
if ( V_4 -> V_58 != V_109 ) {
F_9 ( L_15 ) ;
V_93 = true ;
}
}
}
if ( V_92 != V_4 -> V_51 ) {
F_9 ( L_16 ) ;
V_93 = true ;
if ( V_4 -> V_51 )
V_4 -> V_51 -> V_53 = NULL ;
V_4 -> V_51 = V_92 ;
}
}
if ( V_97 ) {
V_77 = - V_110 ;
goto V_97;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_51 )
continue;
if ( V_4 -> V_51 -> V_53 == V_88 -> V_53 )
V_90 = NULL ;
else
V_90 = V_4 -> V_51 -> V_53 ;
for ( V_96 = 0 ; V_96 < V_88 -> V_100 ; V_96 ++ ) {
if ( V_88 -> V_107 [ V_96 ] == V_4 )
V_90 = V_88 -> V_53 ;
}
if ( V_90 &&
! F_28 ( V_4 -> V_51 , V_90 ) ) {
V_77 = - V_110 ;
goto V_97;
}
if ( V_90 != V_4 -> V_51 -> V_53 ) {
F_9 ( L_17 ) ;
V_93 = true ;
V_4 -> V_51 -> V_53 = V_90 ;
}
if ( V_90 ) {
F_9 ( L_18 ,
V_4 -> V_30 . V_31 , F_10 ( V_4 ) ,
V_90 -> V_30 . V_31 ) ;
} else {
F_9 ( L_19 ,
V_4 -> V_30 . V_31 , F_10 ( V_4 ) ) ;
}
}
if ( V_94 && ! V_62 -> V_111 )
V_93 = true ;
if ( V_93 ) {
V_88 -> V_53 -> V_63 = F_25 ( V_88 -> V_53 ) ;
if ( V_88 -> V_53 -> V_63 ) {
F_9 ( L_20
L_21 ) ;
F_23 ( V_88 -> V_16 ) ;
V_71 = V_88 -> V_53 -> V_64 ;
V_88 -> V_53 -> V_64 = V_88 -> V_64 ;
if ( ! F_31 ( V_88 -> V_53 , V_88 -> V_16 ,
V_88 -> V_68 , V_88 -> V_69 ,
V_71 ) ) {
F_42 ( L_22 ,
V_88 -> V_53 -> V_30 . V_31 ) ;
V_88 -> V_53 -> V_64 = V_71 ;
V_77 = - V_110 ;
goto V_97;
}
F_9 ( L_23 ) ;
for ( V_99 = 0 ; V_99 < V_88 -> V_100 ; V_99 ++ ) {
F_9 ( L_24 , V_88 -> V_107 [ V_99 ] -> V_30 . V_31 ,
F_10 ( V_88 -> V_107 [ V_99 ] ) ) ;
V_88 -> V_107 [ V_99 ] -> V_37 -> V_58 ( V_88 -> V_107 [ V_99 ] , V_109 ) ;
}
}
F_27 ( V_2 ) ;
} else if ( V_94 ) {
V_88 -> V_53 -> V_68 = V_88 -> V_68 ;
V_88 -> V_53 -> V_69 = V_88 -> V_69 ;
V_71 = V_88 -> V_53 -> V_64 ;
if ( V_88 -> V_53 -> V_64 != V_88 -> V_64 )
V_88 -> V_53 -> V_64 = V_88 -> V_64 ;
V_77 = V_62 -> V_111 ( V_88 -> V_53 ,
V_88 -> V_68 , V_88 -> V_69 , V_71 ) ;
if ( V_77 != 0 ) {
V_88 -> V_53 -> V_64 = V_71 ;
goto V_97;
}
}
F_40 ( V_95 ) ;
F_40 ( V_91 ) ;
F_40 ( V_89 ) ;
return 0 ;
V_97:
V_27 = 0 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
* V_53 = V_89 [ V_27 ++ ] ;
}
V_27 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
* V_51 = V_91 [ V_27 ++ ] ;
}
V_27 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_95 [ V_27 ++ ] ;
}
if ( V_93 &&
! F_31 ( V_98 . V_53 , V_98 . V_16 , V_98 . V_68 ,
V_98 . V_69 , V_98 . V_64 ) )
F_42 ( L_25 ) ;
F_40 ( V_95 ) ;
F_40 ( V_91 ) ;
F_40 ( V_89 ) ;
return V_77 ;
}
static int F_43 ( struct V_50 * V_51 )
{
int V_58 = V_59 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_51 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_51 == V_51 )
if ( V_4 -> V_58 < V_58 )
V_58 = V_4 -> V_58 ;
return V_58 ;
}
static void F_44 ( struct V_50 * V_51 , int V_16 )
{
struct V_112 * V_56 = V_51 -> V_56 ;
struct V_54 * V_55 ;
if ( V_56 ) {
if ( V_16 == V_109 )
V_56 -> V_37 -> V_85 ( V_56 ) ;
else
V_56 -> V_37 -> V_57 ( V_56 ) ;
}
V_55 = V_51 -> V_26 ;
if ( V_55 -> V_58 )
V_55 -> V_58 ( V_51 , V_16 ) ;
if ( V_56 ) {
if ( V_16 == V_109 )
V_56 -> V_37 -> V_86 ( V_56 ) ;
else
V_56 -> V_37 -> V_60 ( V_56 ) ;
}
}
static int F_45 ( struct V_52 * V_53 )
{
int V_58 = V_59 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_53 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_51 && V_4 -> V_51 -> V_53 == V_53 )
if ( V_4 -> V_58 < V_58 )
V_58 = V_4 -> V_58 ;
return V_58 ;
}
void F_46 ( struct V_3 * V_4 , int V_16 )
{
struct V_50 * V_51 = V_4 -> V_51 ;
struct V_52 * V_53 = V_51 ? V_51 -> V_53 : NULL ;
int V_113 , V_114 = V_59 ;
if ( V_16 == V_4 -> V_58 )
return;
V_113 = V_4 -> V_58 ;
V_4 -> V_58 = V_16 ;
if ( V_51 )
V_114 = F_43 ( V_51 ) ;
if ( V_16 < V_113 ) {
if ( V_53 ) {
struct V_61 * V_62 = V_53 -> V_26 ;
if ( V_62 -> V_58 )
(* V_62 -> V_58 ) ( V_53 ,
F_45 ( V_53 ) ) ;
}
if ( V_51 )
F_44 ( V_51 , V_114 ) ;
}
if ( V_16 > V_113 ) {
if ( V_51 )
F_44 ( V_51 , V_114 ) ;
if ( V_53 ) {
struct V_61 * V_62 = V_53 -> V_26 ;
if ( V_62 -> V_58 )
(* V_62 -> V_58 ) ( V_53 ,
F_45 ( V_53 ) ) ;
}
}
return;
}
int F_47 ( struct V_70 * V_64 ,
struct V_115 * V_116 )
{
int V_99 ;
V_64 -> V_117 = V_116 -> V_117 ;
V_64 -> V_118 = V_116 -> V_118 ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_64 -> V_119 [ V_99 ] = V_116 -> V_119 [ V_99 ] ;
V_64 -> V_120 [ V_99 ] = V_116 -> V_120 [ V_99 ] ;
}
F_48 ( V_116 -> V_106 , & V_64 -> V_121 ,
& V_64 -> V_122 ) ;
V_64 -> V_106 = V_116 -> V_106 ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
struct V_50 * V_51 ;
struct V_61 * V_62 ;
int V_77 , V_114 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_53 -> V_63 )
continue;
V_77 = F_31 ( V_53 , & V_53 -> V_16 ,
V_53 -> V_68 , V_53 -> V_69 , V_53 -> V_64 ) ;
if ( V_77 == false )
F_42 ( L_26 , V_53 ) ;
if ( F_45 ( V_53 ) ) {
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if( V_51 -> V_53 != V_53 )
continue;
V_114 = F_43 (
V_51 ) ;
F_44 ( V_51 , V_114 ) ;
}
V_62 = V_53 -> V_26 ;
if ( V_62 -> V_58 )
(* V_62 -> V_58 ) ( V_53 ,
F_45 ( V_53 ) ) ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
if ( V_2 -> V_12 . V_37 -> V_123 )
V_2 -> V_12 . V_37 -> V_123 ( V_2 ) ;
}
static void F_52 ( struct V_124 * V_125 )
{
struct V_126 * V_126 = F_53 ( V_125 ) ;
struct V_1 * V_2 = F_54 ( V_126 , struct V_1 , V_12 . V_127 ) ;
struct V_3 * V_4 ;
enum V_128 V_129 ;
bool V_130 = false , V_131 = false ;
if ( ! V_39 )
return;
F_55 ( & V_2 -> V_12 . V_132 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_33 )
continue;
if ( ! V_4 -> V_133 || V_4 -> V_133 == V_134 )
continue;
V_130 = true ;
V_129 = V_4 -> V_19 ;
if ( V_129 == V_35 &&
! ( V_4 -> V_133 & V_135 ) )
continue;
V_4 -> V_19 = V_4 -> V_37 -> V_38 ( V_4 , false ) ;
if ( V_129 != V_4 -> V_19 ) {
const char * V_136 , * V_137 ;
V_136 = F_56 ( V_129 ) ;
V_137 = F_56 ( V_4 -> V_19 ) ;
F_9 ( L_27
L_28 ,
V_4 -> V_30 . V_31 ,
F_10 ( V_4 ) ,
V_136 , V_137 ) ;
V_131 = true ;
}
}
F_57 ( & V_2 -> V_12 . V_132 ) ;
if ( V_131 )
F_50 ( V_2 ) ;
if ( V_130 )
F_58 ( V_126 , V_138 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_12 . V_139 )
return;
F_60 ( & V_2 -> V_12 . V_127 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
bool V_140 = false ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_12 . V_139 || ! V_39 )
return;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_133 & ( V_141 |
V_135 ) )
V_140 = true ;
}
if ( V_140 )
F_58 ( & V_2 -> V_12 . V_127 , V_138 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
F_62 ( & V_2 -> V_12 . V_127 , F_52 ) ;
V_2 -> V_12 . V_139 = true ;
F_11 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_128 V_129 ;
bool V_131 = false ;
if ( ! V_2 -> V_12 . V_139 )
return;
F_55 ( & V_2 -> V_12 . V_132 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_4 -> V_133 & V_134 ) )
continue;
V_129 = V_4 -> V_19 ;
V_4 -> V_19 = V_4 -> V_37 -> V_38 ( V_4 , false ) ;
F_9 ( L_29 ,
V_4 -> V_30 . V_31 ,
F_10 ( V_4 ) ,
F_56 ( V_129 ) ,
F_56 ( V_4 -> V_19 ) ) ;
if ( V_129 != V_4 -> V_19 )
V_131 = true ;
}
F_57 ( & V_2 -> V_12 . V_132 ) ;
if ( V_131 )
F_50 ( V_2 ) ;
}
