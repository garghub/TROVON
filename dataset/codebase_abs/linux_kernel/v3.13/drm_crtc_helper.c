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
if ( V_14 == ( V_17 | V_18 |
V_19 ) )
return;
F_7 (mode, &connector->modes, head) {
if ( ( V_16 -> V_14 & V_18 ) &&
! ( V_14 & V_18 ) )
V_16 -> V_20 = V_21 ;
if ( ( V_16 -> V_14 & V_17 ) &&
! ( V_14 & V_17 ) )
V_16 -> V_20 = V_22 ;
if ( ( V_16 -> V_14 & V_19 ) &&
! ( V_14 & V_19 ) )
V_16 -> V_20 = V_23 ;
}
return;
}
int F_8 ( struct V_3 * V_4 ,
T_1 V_24 , T_1 V_25 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 ;
struct V_26 * V_27 =
V_4 -> V_28 ;
int V_29 = 0 ;
int V_30 = 0 ;
bool V_31 = true ;
F_9 ( L_1 , V_4 -> V_32 . V_33 ,
F_10 ( V_4 ) ) ;
F_7 (mode, &connector->modes, head)
V_16 -> V_20 = V_34 ;
if ( V_4 -> V_35 ) {
if ( V_4 -> V_35 == V_36 )
V_4 -> V_20 = V_37 ;
else
V_4 -> V_20 = V_38 ;
if ( V_4 -> V_39 -> V_35 )
V_4 -> V_39 -> V_35 ( V_4 ) ;
} else {
V_4 -> V_20 = V_4 -> V_39 -> V_40 ( V_4 , true ) ;
}
if ( V_41 != V_2 -> V_12 . V_42 )
F_11 ( V_2 ) ;
V_2 -> V_12 . V_42 = V_41 ;
if ( V_4 -> V_20 == V_38 ) {
F_9 ( L_2 ,
V_4 -> V_32 . V_33 , F_10 ( V_4 ) ) ;
F_12 ( V_4 , NULL ) ;
V_31 = false ;
goto V_43;
}
#ifdef F_13
V_29 = F_14 ( V_4 ) ;
if ( V_29 == 0 )
#endif
V_29 = (* V_27 -> V_44 )( V_4 ) ;
if ( V_29 == 0 && V_4 -> V_20 == V_37 )
V_29 = F_15 ( V_4 , 1024 , 768 ) ;
if ( V_29 == 0 )
goto V_43;
F_16 ( V_4 ) ;
if ( V_24 && V_25 )
F_17 ( V_2 , & V_4 -> V_45 , V_24 ,
V_25 , 0 ) ;
if ( V_4 -> V_46 )
V_30 |= V_18 ;
if ( V_4 -> V_47 )
V_30 |= V_17 ;
if ( V_4 -> V_48 )
V_30 |= V_19 ;
F_6 ( V_4 , V_30 ) ;
F_7 (mode, &connector->modes, head) {
if ( V_16 -> V_20 == V_49 )
V_16 -> V_20 = V_27 -> V_50 ( V_4 ,
V_16 ) ;
}
V_43:
F_18 ( V_2 , & V_4 -> V_45 , V_31 ) ;
if ( F_19 ( & V_4 -> V_45 ) )
return 0 ;
F_7 (mode, &connector->modes, head)
V_16 -> V_51 = F_20 ( V_16 ) ;
F_21 ( & V_4 -> V_45 ) ;
F_9 ( L_3 , V_4 -> V_32 . V_33 ,
F_10 ( V_4 ) ) ;
F_7 (mode, &connector->modes, head) {
F_22 ( V_16 , V_52 ) ;
F_23 ( V_16 ) ;
}
return V_29 ;
}
bool F_24 ( struct V_53 * V_54 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = V_54 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_54 == V_54 )
return true ;
return false ;
}
bool F_25 ( struct V_55 * V_56 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 = V_56 -> V_2 ;
F_7 (encoder, &dev->mode_config.encoder_list, head)
if ( V_54 -> V_56 == V_56 && F_24 ( V_54 ) )
return true ;
return false ;
}
static void
F_26 ( struct V_53 * V_54 )
{
struct V_57 * V_58 = V_54 -> V_28 ;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_60 ( V_54 -> V_59 ) ;
if ( V_58 -> V_60 )
(* V_58 -> V_60 )( V_54 ) ;
else
(* V_58 -> V_61 )( V_54 , V_62 ) ;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_63 ( V_54 -> V_59 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
struct V_3 * V_4 ;
struct V_55 * V_56 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_54 )
continue;
if ( V_4 -> V_20 == V_38 )
V_4 -> V_54 = NULL ;
}
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_24 ( V_54 ) ) {
F_26 ( V_54 ) ;
V_54 -> V_56 = NULL ;
}
}
F_7 (crtc, &dev->mode_config.crtc_list, head) {
struct V_64 * V_65 = V_56 -> V_28 ;
V_56 -> V_66 = F_25 ( V_56 ) ;
if ( ! V_56 -> V_66 ) {
if ( V_65 -> V_60 )
(* V_65 -> V_60 )( V_56 ) ;
else
(* V_65 -> V_61 )( V_56 , V_62 ) ;
V_56 -> V_67 = NULL ;
}
}
}
static bool F_28 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_55 * V_5 ;
int V_68 = 1 ;
F_29 ( ! V_56 , L_4 ) ;
V_2 = V_56 -> V_2 ;
F_7 (tmp, &dev->mode_config.crtc_list, head) {
if ( V_5 == V_56 )
break;
V_68 <<= 1 ;
}
if ( V_54 -> V_69 & V_68 )
return true ;
return false ;
}
static void
F_30 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_53 * V_54 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_58 = V_54 -> V_28 ;
if ( V_54 -> V_56 == NULL )
F_26 ( V_54 ) ;
if ( V_58 -> V_70 &&
V_54 -> V_56 != (* V_58 -> V_70 )( V_54 ) )
F_26 ( V_54 ) ;
}
}
bool F_31 ( struct V_55 * V_56 ,
struct V_15 * V_16 ,
int V_71 , int V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_15 * V_75 , V_76 ;
struct V_64 * V_65 = V_56 -> V_28 ;
struct V_57 * V_58 ;
int V_77 , V_78 ;
bool V_79 ;
struct V_53 * V_54 ;
bool V_80 = true ;
V_79 = V_56 -> V_66 ;
V_56 -> V_66 = F_25 ( V_56 ) ;
if ( ! V_56 -> V_66 )
return true ;
V_75 = F_32 ( V_2 , V_16 ) ;
if ( ! V_75 ) {
V_56 -> V_66 = V_79 ;
return false ;
}
V_76 = V_56 -> V_16 ;
V_77 = V_56 -> V_71 ;
V_78 = V_56 -> V_72 ;
V_56 -> V_16 = * V_16 ;
V_56 -> V_71 = V_71 ;
V_56 -> V_72 = V_72 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
if ( V_54 -> V_59 && V_54 -> V_59 -> V_39 -> V_81 ) {
V_80 = V_54 -> V_59 -> V_39 -> V_81 (
V_54 -> V_59 , V_16 , V_75 ) ;
if ( ! V_80 ) {
F_9 ( L_5 ) ;
goto V_82;
}
}
V_58 = V_54 -> V_28 ;
if ( ! ( V_80 = V_58 -> V_81 ( V_54 , V_16 ,
V_75 ) ) ) {
F_9 ( L_6 ) ;
goto V_82;
}
}
if ( ! ( V_80 = V_65 -> V_81 ( V_56 , V_16 , V_75 ) ) ) {
F_9 ( L_7 ) ;
goto V_82;
}
F_9 ( L_8 , V_56 -> V_32 . V_33 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_60 ( V_54 -> V_59 ) ;
V_58 = V_54 -> V_28 ;
V_58 -> V_83 ( V_54 ) ;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_63 ( V_54 -> V_59 ) ;
}
F_30 ( V_2 ) ;
V_65 -> V_83 ( V_56 ) ;
V_80 = ! V_65 -> V_84 ( V_56 , V_16 , V_75 , V_71 , V_72 , V_74 ) ;
if ( ! V_80 )
goto V_82;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
F_9 ( L_9 ,
V_54 -> V_32 . V_33 , F_33 ( V_54 ) ,
V_16 -> V_32 . V_33 , V_16 -> V_85 ) ;
V_58 = V_54 -> V_28 ;
V_58 -> V_84 ( V_54 , V_16 , V_75 ) ;
if ( V_54 -> V_59 && V_54 -> V_59 -> V_39 -> V_84 )
V_54 -> V_59 -> V_39 -> V_84 ( V_54 -> V_59 , V_16 ,
V_75 ) ;
}
V_65 -> V_86 ( V_56 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_87 ( V_54 -> V_59 ) ;
V_58 = V_54 -> V_28 ;
V_58 -> V_86 ( V_54 ) ;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_88 ( V_54 -> V_59 ) ;
}
V_56 -> V_89 = * V_75 ;
F_34 ( V_56 ) ;
V_82:
F_35 ( V_2 , V_75 ) ;
if ( ! V_80 ) {
V_56 -> V_66 = V_79 ;
V_56 -> V_16 = V_76 ;
V_56 -> V_71 = V_77 ;
V_56 -> V_72 = V_78 ;
}
return V_80 ;
}
static int
F_36 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 ;
struct V_53 * V_54 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_54 != V_54 )
continue;
V_4 -> V_54 = NULL ;
V_4 -> V_61 = V_62 ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
int F_37 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
struct V_55 * V_92 ;
struct V_53 * V_93 , * V_94 , * V_54 ;
bool V_95 = false ;
bool V_96 = false ;
struct V_3 * V_97 , * V_4 ;
int V_29 = 0 , V_98 , V_99 = 0 ;
struct V_64 * V_65 ;
struct V_90 V_100 ;
int V_80 ;
int V_101 ;
F_9 ( L_10 ) ;
F_38 ( ! V_91 ) ;
F_38 ( ! V_91 -> V_56 ) ;
F_38 ( ! V_91 -> V_56 -> V_28 ) ;
F_38 ( ! V_91 -> V_16 && V_91 -> V_67 ) ;
F_38 ( V_91 -> V_67 && V_91 -> V_102 == 0 ) ;
V_65 = V_91 -> V_56 -> V_28 ;
if ( ! V_91 -> V_16 )
V_91 -> V_67 = NULL ;
if ( V_91 -> V_67 ) {
F_9 ( L_11 ,
V_91 -> V_56 -> V_32 . V_33 , V_91 -> V_67 -> V_32 . V_33 ,
( int ) V_91 -> V_102 , V_91 -> V_71 , V_91 -> V_72 ) ;
} else {
F_9 ( L_12 , V_91 -> V_56 -> V_32 . V_33 ) ;
return F_36 ( V_91 -> V_56 ) ;
}
V_2 = V_91 -> V_56 -> V_2 ;
V_93 = F_39 ( V_2 -> V_12 . V_103 *
sizeof( struct V_53 ) , V_104 ) ;
if ( ! V_93 )
return - V_105 ;
V_97 = F_39 ( V_2 -> V_12 . V_106 *
sizeof( struct V_3 ) , V_104 ) ;
if ( ! V_97 ) {
F_40 ( V_93 ) ;
return - V_105 ;
}
V_29 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_93 [ V_29 ++ ] = * V_54 ;
}
V_29 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
V_97 [ V_29 ++ ] = * V_4 ;
}
V_100 . V_56 = V_91 -> V_56 ;
V_100 . V_16 = & V_91 -> V_56 -> V_16 ;
V_100 . V_71 = V_91 -> V_56 -> V_71 ;
V_100 . V_72 = V_91 -> V_56 -> V_72 ;
V_100 . V_67 = V_91 -> V_56 -> V_67 ;
if ( V_91 -> V_56 -> V_67 != V_91 -> V_67 ) {
if ( V_91 -> V_56 -> V_67 == NULL ) {
F_9 ( L_13 ) ;
V_95 = true ;
} else if ( V_91 -> V_67 == NULL ) {
V_95 = true ;
} else if ( V_91 -> V_67 -> V_107 !=
V_91 -> V_56 -> V_67 -> V_107 ) {
V_95 = true ;
} else
V_96 = true ;
}
if ( V_91 -> V_71 != V_91 -> V_56 -> V_71 || V_91 -> V_72 != V_91 -> V_56 -> V_72 )
V_96 = true ;
if ( V_91 -> V_16 && ! F_41 ( V_91 -> V_16 , & V_91 -> V_56 -> V_16 ) ) {
F_9 ( L_14 ) ;
F_23 ( & V_91 -> V_56 -> V_16 ) ;
F_23 ( V_91 -> V_16 ) ;
V_95 = true ;
}
V_29 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
struct V_26 * V_27 =
V_4 -> V_28 ;
V_94 = V_4 -> V_54 ;
for ( V_98 = 0 ; V_98 < V_91 -> V_102 ; V_98 ++ ) {
if ( V_91 -> V_108 [ V_98 ] == V_4 ) {
V_94 = V_27 -> V_109 ( V_4 ) ;
if ( V_94 == NULL )
V_99 = 1 ;
break;
if ( V_4 -> V_61 != V_110 ) {
F_9 ( L_15 ) ;
V_95 = true ;
}
}
}
if ( V_94 != V_4 -> V_54 ) {
F_9 ( L_16 ) ;
V_95 = true ;
if ( V_4 -> V_54 )
V_4 -> V_54 -> V_56 = NULL ;
V_4 -> V_54 = V_94 ;
}
}
if ( V_99 ) {
V_80 = - V_111 ;
goto V_99;
}
V_29 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_54 )
continue;
if ( V_4 -> V_54 -> V_56 == V_91 -> V_56 )
V_92 = NULL ;
else
V_92 = V_4 -> V_54 -> V_56 ;
for ( V_98 = 0 ; V_98 < V_91 -> V_102 ; V_98 ++ ) {
if ( V_91 -> V_108 [ V_98 ] == V_4 )
V_92 = V_91 -> V_56 ;
}
if ( V_92 &&
! F_28 ( V_4 -> V_54 , V_92 ) ) {
V_80 = - V_111 ;
goto V_99;
}
if ( V_92 != V_4 -> V_54 -> V_56 ) {
F_9 ( L_17 ) ;
V_95 = true ;
V_4 -> V_54 -> V_56 = V_92 ;
}
if ( V_92 ) {
F_9 ( L_18 ,
V_4 -> V_32 . V_33 , F_10 ( V_4 ) ,
V_92 -> V_32 . V_33 ) ;
} else {
F_9 ( L_19 ,
V_4 -> V_32 . V_33 , F_10 ( V_4 ) ) ;
}
}
if ( V_96 && ! V_65 -> V_112 )
V_95 = true ;
if ( V_95 ) {
if ( F_25 ( V_91 -> V_56 ) ) {
F_9 ( L_20
L_21 ) ;
F_23 ( V_91 -> V_16 ) ;
V_91 -> V_56 -> V_67 = V_91 -> V_67 ;
if ( ! F_31 ( V_91 -> V_56 , V_91 -> V_16 ,
V_91 -> V_71 , V_91 -> V_72 ,
V_100 . V_67 ) ) {
F_42 ( L_22 ,
V_91 -> V_56 -> V_32 . V_33 ) ;
V_91 -> V_56 -> V_67 = V_100 . V_67 ;
V_80 = - V_111 ;
goto V_99;
}
F_9 ( L_23 ) ;
for ( V_101 = 0 ; V_101 < V_91 -> V_102 ; V_101 ++ ) {
F_9 ( L_24 , V_91 -> V_108 [ V_101 ] -> V_32 . V_33 ,
F_10 ( V_91 -> V_108 [ V_101 ] ) ) ;
V_91 -> V_108 [ V_101 ] -> V_39 -> V_61 ( V_91 -> V_108 [ V_101 ] , V_110 ) ;
}
}
F_27 ( V_2 ) ;
} else if ( V_96 ) {
V_91 -> V_56 -> V_71 = V_91 -> V_71 ;
V_91 -> V_56 -> V_72 = V_91 -> V_72 ;
V_91 -> V_56 -> V_67 = V_91 -> V_67 ;
V_80 = V_65 -> V_112 ( V_91 -> V_56 ,
V_91 -> V_71 , V_91 -> V_72 , V_100 . V_67 ) ;
if ( V_80 != 0 ) {
V_91 -> V_56 -> V_71 = V_100 . V_71 ;
V_91 -> V_56 -> V_72 = V_100 . V_72 ;
V_91 -> V_56 -> V_67 = V_100 . V_67 ;
goto V_99;
}
}
F_40 ( V_97 ) ;
F_40 ( V_93 ) ;
return 0 ;
V_99:
V_29 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
* V_54 = V_93 [ V_29 ++ ] ;
}
V_29 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_97 [ V_29 ++ ] ;
}
if ( V_95 &&
! F_31 ( V_100 . V_56 , V_100 . V_16 , V_100 . V_71 ,
V_100 . V_72 , V_100 . V_67 ) )
F_42 ( L_25 ) ;
F_40 ( V_97 ) ;
F_40 ( V_93 ) ;
return V_80 ;
}
static int F_43 ( struct V_53 * V_54 )
{
int V_61 = V_62 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_54 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_54 == V_54 )
if ( V_4 -> V_61 < V_61 )
V_61 = V_4 -> V_61 ;
return V_61 ;
}
static void F_44 ( struct V_53 * V_54 , int V_16 )
{
struct V_113 * V_59 = V_54 -> V_59 ;
struct V_57 * V_58 ;
if ( V_59 ) {
if ( V_16 == V_110 )
V_59 -> V_39 -> V_87 ( V_59 ) ;
else
V_59 -> V_39 -> V_60 ( V_59 ) ;
}
V_58 = V_54 -> V_28 ;
if ( V_58 -> V_61 )
V_58 -> V_61 ( V_54 , V_16 ) ;
if ( V_59 ) {
if ( V_16 == V_110 )
V_59 -> V_39 -> V_88 ( V_59 ) ;
else
V_59 -> V_39 -> V_63 ( V_59 ) ;
}
}
static int F_45 ( struct V_55 * V_56 )
{
int V_61 = V_62 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_56 -> V_2 ;
F_7 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_54 && V_4 -> V_54 -> V_56 == V_56 )
if ( V_4 -> V_61 < V_61 )
V_61 = V_4 -> V_61 ;
return V_61 ;
}
void F_46 ( struct V_3 * V_4 , int V_16 )
{
struct V_53 * V_54 = V_4 -> V_54 ;
struct V_55 * V_56 = V_54 ? V_54 -> V_56 : NULL ;
int V_114 , V_115 = V_62 ;
if ( V_16 == V_4 -> V_61 )
return;
V_114 = V_4 -> V_61 ;
V_4 -> V_61 = V_16 ;
if ( V_54 )
V_115 = F_43 ( V_54 ) ;
if ( V_16 < V_114 ) {
if ( V_56 ) {
struct V_64 * V_65 = V_56 -> V_28 ;
if ( V_65 -> V_61 )
(* V_65 -> V_61 ) ( V_56 ,
F_45 ( V_56 ) ) ;
}
if ( V_54 )
F_44 ( V_54 , V_115 ) ;
}
if ( V_16 > V_114 ) {
if ( V_54 )
F_44 ( V_54 , V_115 ) ;
if ( V_56 ) {
struct V_64 * V_65 = V_56 -> V_28 ;
if ( V_65 -> V_61 )
(* V_65 -> V_61 ) ( V_56 ,
F_45 ( V_56 ) ) ;
}
}
return;
}
int F_47 ( struct V_73 * V_67 ,
struct V_116 * V_117 )
{
int V_101 ;
V_67 -> V_118 = V_117 -> V_118 ;
V_67 -> V_119 = V_117 -> V_119 ;
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_67 -> V_120 [ V_101 ] = V_117 -> V_120 [ V_101 ] ;
V_67 -> V_121 [ V_101 ] = V_117 -> V_121 [ V_101 ] ;
}
F_48 ( V_117 -> V_107 , & V_67 -> V_122 ,
& V_67 -> V_123 ) ;
V_67 -> V_107 = V_117 -> V_107 ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_53 * V_54 ;
struct V_64 * V_65 ;
int V_80 , V_115 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_56 -> V_66 )
continue;
V_80 = F_31 ( V_56 , & V_56 -> V_16 ,
V_56 -> V_71 , V_56 -> V_72 , V_56 -> V_67 ) ;
if ( V_80 == false )
F_42 ( L_26 , V_56 ) ;
if ( F_45 ( V_56 ) ) {
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if( V_54 -> V_56 != V_56 )
continue;
V_115 = F_43 (
V_54 ) ;
F_44 ( V_54 , V_115 ) ;
}
V_65 = V_56 -> V_28 ;
if ( V_65 -> V_61 )
(* V_65 -> V_61 ) ( V_56 ,
F_45 ( V_56 ) ) ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
if ( V_2 -> V_12 . V_39 -> V_124 )
V_2 -> V_12 . V_39 -> V_124 ( V_2 ) ;
}
static void F_52 ( struct V_125 * V_126 )
{
struct V_127 * V_127 = F_53 ( V_126 ) ;
struct V_1 * V_2 = F_54 ( V_127 , struct V_1 , V_12 . V_128 ) ;
struct V_3 * V_4 ;
enum V_129 V_130 ;
bool V_131 = false , V_132 = false ;
if ( ! V_41 )
return;
F_55 ( & V_2 -> V_12 . V_133 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_35 )
continue;
if ( ! V_4 -> V_134 || V_4 -> V_134 == V_135 )
continue;
V_131 = true ;
V_130 = V_4 -> V_20 ;
if ( V_130 == V_37 &&
! ( V_4 -> V_134 & V_136 ) )
continue;
V_4 -> V_20 = V_4 -> V_39 -> V_40 ( V_4 , false ) ;
if ( V_130 != V_4 -> V_20 ) {
const char * V_137 , * V_138 ;
V_137 = F_56 ( V_130 ) ;
V_138 = F_56 ( V_4 -> V_20 ) ;
F_9 ( L_27
L_28 ,
V_4 -> V_32 . V_33 ,
F_10 ( V_4 ) ,
V_137 , V_138 ) ;
V_132 = true ;
}
}
F_57 ( & V_2 -> V_12 . V_133 ) ;
if ( V_132 )
F_50 ( V_2 ) ;
if ( V_131 )
F_58 ( V_127 , V_139 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_12 . V_140 )
return;
F_60 ( & V_2 -> V_12 . V_128 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
bool V_141 = false ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_12 . V_140 || ! V_41 )
return;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_134 & ( V_142 |
V_136 ) )
V_141 = true ;
}
if ( V_141 )
F_58 ( & V_2 -> V_12 . V_128 , V_139 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
F_62 ( & V_2 -> V_12 . V_128 , F_52 ) ;
V_2 -> V_12 . V_140 = true ;
F_11 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
}
bool F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_129 V_130 ;
bool V_132 = false ;
if ( ! V_2 -> V_12 . V_140 )
return false ;
F_55 ( & V_2 -> V_12 . V_133 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_4 -> V_134 & V_135 ) )
continue;
V_130 = V_4 -> V_20 ;
V_4 -> V_20 = V_4 -> V_39 -> V_40 ( V_4 , false ) ;
F_9 ( L_29 ,
V_4 -> V_32 . V_33 ,
F_10 ( V_4 ) ,
F_56 ( V_130 ) ,
F_56 ( V_4 -> V_20 ) ) ;
if ( V_130 != V_4 -> V_20 )
V_132 = true ;
}
F_57 ( & V_2 -> V_12 . V_133 ) ;
if ( V_132 )
F_50 ( V_2 ) ;
return V_132 ;
}
