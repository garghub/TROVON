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
static void
F_28 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_53 * V_54 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_58 = V_54 -> V_28 ;
if ( V_54 -> V_56 == NULL )
F_26 ( V_54 ) ;
if ( V_58 -> V_68 &&
V_54 -> V_56 != (* V_58 -> V_68 )( V_54 ) )
F_26 ( V_54 ) ;
}
}
bool F_29 ( struct V_55 * V_56 ,
struct V_15 * V_16 ,
int V_69 , int V_70 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_15 * V_73 , V_74 ;
struct V_64 * V_65 = V_56 -> V_28 ;
struct V_57 * V_58 ;
int V_75 , V_76 ;
bool V_77 ;
struct V_53 * V_54 ;
bool V_78 = true ;
V_77 = V_56 -> V_66 ;
V_56 -> V_66 = F_25 ( V_56 ) ;
if ( ! V_56 -> V_66 )
return true ;
V_73 = F_30 ( V_2 , V_16 ) ;
if ( ! V_73 ) {
V_56 -> V_66 = V_77 ;
return false ;
}
V_74 = V_56 -> V_16 ;
V_75 = V_56 -> V_69 ;
V_76 = V_56 -> V_70 ;
V_56 -> V_16 = * V_16 ;
V_56 -> V_69 = V_69 ;
V_56 -> V_70 = V_70 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
if ( V_54 -> V_59 && V_54 -> V_59 -> V_39 -> V_79 ) {
V_78 = V_54 -> V_59 -> V_39 -> V_79 (
V_54 -> V_59 , V_16 , V_73 ) ;
if ( ! V_78 ) {
F_9 ( L_4 ) ;
goto V_80;
}
}
V_58 = V_54 -> V_28 ;
if ( ! ( V_78 = V_58 -> V_79 ( V_54 , V_16 ,
V_73 ) ) ) {
F_9 ( L_5 ) ;
goto V_80;
}
}
if ( ! ( V_78 = V_65 -> V_79 ( V_56 , V_16 , V_73 ) ) ) {
F_9 ( L_6 ) ;
goto V_80;
}
F_9 ( L_7 , V_56 -> V_32 . V_33 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_60 ( V_54 -> V_59 ) ;
V_58 = V_54 -> V_28 ;
V_58 -> V_81 ( V_54 ) ;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_63 ( V_54 -> V_59 ) ;
}
F_28 ( V_2 ) ;
V_65 -> V_81 ( V_56 ) ;
V_78 = ! V_65 -> V_82 ( V_56 , V_16 , V_73 , V_69 , V_70 , V_72 ) ;
if ( ! V_78 )
goto V_80;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
F_9 ( L_8 ,
V_54 -> V_32 . V_33 , F_31 ( V_54 ) ,
V_16 -> V_32 . V_33 , V_16 -> V_83 ) ;
V_58 = V_54 -> V_28 ;
V_58 -> V_82 ( V_54 , V_16 , V_73 ) ;
if ( V_54 -> V_59 && V_54 -> V_59 -> V_39 -> V_82 )
V_54 -> V_59 -> V_39 -> V_82 ( V_54 -> V_59 , V_16 ,
V_73 ) ;
}
V_65 -> V_84 ( V_56 ) ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_54 -> V_56 != V_56 )
continue;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_85 ( V_54 -> V_59 ) ;
V_58 = V_54 -> V_28 ;
V_58 -> V_84 ( V_54 ) ;
if ( V_54 -> V_59 )
V_54 -> V_59 -> V_39 -> V_86 ( V_54 -> V_59 ) ;
}
V_56 -> V_87 = * V_73 ;
F_32 ( V_56 , & V_56 -> V_87 ) ;
V_80:
F_33 ( V_2 , V_73 ) ;
if ( ! V_78 ) {
V_56 -> V_66 = V_77 ;
V_56 -> V_16 = V_74 ;
V_56 -> V_69 = V_75 ;
V_56 -> V_70 = V_76 ;
}
return V_78 ;
}
static int
F_34 ( struct V_55 * V_56 )
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
int F_35 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
struct V_55 * V_90 ;
struct V_53 * V_91 , * V_92 , * V_54 ;
bool V_93 = false ;
bool V_94 = false ;
struct V_3 * V_95 , * V_4 ;
int V_29 = 0 , V_96 , V_97 = 0 ;
struct V_64 * V_65 ;
struct V_88 V_98 ;
int V_78 ;
int V_99 ;
F_9 ( L_9 ) ;
F_36 ( ! V_89 ) ;
F_36 ( ! V_89 -> V_56 ) ;
F_36 ( ! V_89 -> V_56 -> V_28 ) ;
F_36 ( ! V_89 -> V_16 && V_89 -> V_67 ) ;
F_36 ( V_89 -> V_67 && V_89 -> V_100 == 0 ) ;
V_65 = V_89 -> V_56 -> V_28 ;
if ( ! V_89 -> V_16 )
V_89 -> V_67 = NULL ;
if ( V_89 -> V_67 ) {
F_9 ( L_10 ,
V_89 -> V_56 -> V_32 . V_33 , V_89 -> V_67 -> V_32 . V_33 ,
( int ) V_89 -> V_100 , V_89 -> V_69 , V_89 -> V_70 ) ;
} else {
F_9 ( L_11 , V_89 -> V_56 -> V_32 . V_33 ) ;
return F_34 ( V_89 -> V_56 ) ;
}
V_2 = V_89 -> V_56 -> V_2 ;
V_91 = F_37 ( V_2 -> V_12 . V_101 *
sizeof( struct V_53 ) , V_102 ) ;
if ( ! V_91 )
return - V_103 ;
V_95 = F_37 ( V_2 -> V_12 . V_104 *
sizeof( struct V_3 ) , V_102 ) ;
if ( ! V_95 ) {
F_38 ( V_91 ) ;
return - V_103 ;
}
V_29 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
V_91 [ V_29 ++ ] = * V_54 ;
}
V_29 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
V_95 [ V_29 ++ ] = * V_4 ;
}
V_98 . V_56 = V_89 -> V_56 ;
V_98 . V_16 = & V_89 -> V_56 -> V_16 ;
V_98 . V_69 = V_89 -> V_56 -> V_69 ;
V_98 . V_70 = V_89 -> V_56 -> V_70 ;
V_98 . V_67 = V_89 -> V_56 -> V_67 ;
if ( V_89 -> V_56 -> V_67 != V_89 -> V_67 ) {
if ( V_89 -> V_56 -> V_67 == NULL ) {
F_9 ( L_12 ) ;
V_93 = true ;
} else if ( V_89 -> V_67 == NULL ) {
V_93 = true ;
} else if ( V_89 -> V_67 -> V_105 !=
V_89 -> V_56 -> V_67 -> V_105 ) {
V_93 = true ;
} else
V_94 = true ;
}
if ( V_89 -> V_69 != V_89 -> V_56 -> V_69 || V_89 -> V_70 != V_89 -> V_56 -> V_70 )
V_94 = true ;
if ( V_89 -> V_16 && ! F_39 ( V_89 -> V_16 , & V_89 -> V_56 -> V_16 ) ) {
F_9 ( L_13 ) ;
F_23 ( & V_89 -> V_56 -> V_16 ) ;
F_23 ( V_89 -> V_16 ) ;
V_93 = true ;
}
V_29 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
struct V_26 * V_27 =
V_4 -> V_28 ;
V_92 = V_4 -> V_54 ;
for ( V_96 = 0 ; V_96 < V_89 -> V_100 ; V_96 ++ ) {
if ( V_89 -> V_106 [ V_96 ] == V_4 ) {
V_92 = V_27 -> V_107 ( V_4 ) ;
if ( V_92 == NULL )
V_97 = 1 ;
break;
if ( V_4 -> V_61 != V_108 ) {
F_9 ( L_14 ) ;
V_93 = true ;
}
}
}
if ( V_92 != V_4 -> V_54 ) {
F_9 ( L_15 ) ;
V_93 = true ;
if ( V_4 -> V_54 )
V_4 -> V_54 -> V_56 = NULL ;
V_4 -> V_54 = V_92 ;
}
}
if ( V_97 ) {
V_78 = - V_109 ;
goto V_97;
}
V_29 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_54 )
continue;
if ( V_4 -> V_54 -> V_56 == V_89 -> V_56 )
V_90 = NULL ;
else
V_90 = V_4 -> V_54 -> V_56 ;
for ( V_96 = 0 ; V_96 < V_89 -> V_100 ; V_96 ++ ) {
if ( V_89 -> V_106 [ V_96 ] == V_4 )
V_90 = V_89 -> V_56 ;
}
if ( V_90 &&
! F_40 ( V_4 -> V_54 , V_90 ) ) {
V_78 = - V_109 ;
goto V_97;
}
if ( V_90 != V_4 -> V_54 -> V_56 ) {
F_9 ( L_16 ) ;
V_93 = true ;
V_4 -> V_54 -> V_56 = V_90 ;
}
if ( V_90 ) {
F_9 ( L_17 ,
V_4 -> V_32 . V_33 , F_10 ( V_4 ) ,
V_90 -> V_32 . V_33 ) ;
} else {
F_9 ( L_18 ,
V_4 -> V_32 . V_33 , F_10 ( V_4 ) ) ;
}
}
if ( V_94 && ! V_65 -> V_110 )
V_93 = true ;
if ( V_93 ) {
if ( F_25 ( V_89 -> V_56 ) ) {
F_9 ( L_19
L_20 ) ;
F_23 ( V_89 -> V_16 ) ;
V_89 -> V_56 -> V_67 = V_89 -> V_67 ;
if ( ! F_29 ( V_89 -> V_56 , V_89 -> V_16 ,
V_89 -> V_69 , V_89 -> V_70 ,
V_98 . V_67 ) ) {
F_41 ( L_21 ,
V_89 -> V_56 -> V_32 . V_33 ) ;
V_89 -> V_56 -> V_67 = V_98 . V_67 ;
V_78 = - V_109 ;
goto V_97;
}
F_9 ( L_22 ) ;
for ( V_99 = 0 ; V_99 < V_89 -> V_100 ; V_99 ++ ) {
F_9 ( L_23 , V_89 -> V_106 [ V_99 ] -> V_32 . V_33 ,
F_10 ( V_89 -> V_106 [ V_99 ] ) ) ;
V_89 -> V_106 [ V_99 ] -> V_39 -> V_61 ( V_89 -> V_106 [ V_99 ] , V_108 ) ;
}
}
F_27 ( V_2 ) ;
} else if ( V_94 ) {
V_89 -> V_56 -> V_69 = V_89 -> V_69 ;
V_89 -> V_56 -> V_70 = V_89 -> V_70 ;
V_89 -> V_56 -> V_67 = V_89 -> V_67 ;
V_78 = V_65 -> V_110 ( V_89 -> V_56 ,
V_89 -> V_69 , V_89 -> V_70 , V_98 . V_67 ) ;
if ( V_78 != 0 ) {
V_89 -> V_56 -> V_69 = V_98 . V_69 ;
V_89 -> V_56 -> V_70 = V_98 . V_70 ;
V_89 -> V_56 -> V_67 = V_98 . V_67 ;
goto V_97;
}
}
F_38 ( V_95 ) ;
F_38 ( V_91 ) ;
return 0 ;
V_97:
V_29 = 0 ;
F_7 (encoder, &dev->mode_config.encoder_list, head) {
* V_54 = V_91 [ V_29 ++ ] ;
}
V_29 = 0 ;
F_7 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_95 [ V_29 ++ ] ;
}
if ( V_93 &&
! F_29 ( V_98 . V_56 , V_98 . V_16 , V_98 . V_69 ,
V_98 . V_70 , V_98 . V_67 ) )
F_41 ( L_24 ) ;
F_38 ( V_95 ) ;
F_38 ( V_91 ) ;
return V_78 ;
}
static int F_42 ( struct V_53 * V_54 )
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
static void F_43 ( struct V_53 * V_54 , int V_16 )
{
struct V_111 * V_59 = V_54 -> V_59 ;
struct V_57 * V_58 ;
if ( V_59 ) {
if ( V_16 == V_108 )
V_59 -> V_39 -> V_85 ( V_59 ) ;
else
V_59 -> V_39 -> V_60 ( V_59 ) ;
}
V_58 = V_54 -> V_28 ;
if ( V_58 -> V_61 )
V_58 -> V_61 ( V_54 , V_16 ) ;
if ( V_59 ) {
if ( V_16 == V_108 )
V_59 -> V_39 -> V_86 ( V_59 ) ;
else
V_59 -> V_39 -> V_63 ( V_59 ) ;
}
}
static int F_44 ( struct V_55 * V_56 )
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
void F_45 ( struct V_3 * V_4 , int V_16 )
{
struct V_53 * V_54 = V_4 -> V_54 ;
struct V_55 * V_56 = V_54 ? V_54 -> V_56 : NULL ;
int V_112 , V_113 = V_62 ;
if ( V_16 == V_4 -> V_61 )
return;
V_112 = V_4 -> V_61 ;
V_4 -> V_61 = V_16 ;
if ( V_54 )
V_113 = F_42 ( V_54 ) ;
if ( V_16 < V_112 ) {
if ( V_56 ) {
struct V_64 * V_65 = V_56 -> V_28 ;
if ( V_65 -> V_61 )
(* V_65 -> V_61 ) ( V_56 ,
F_44 ( V_56 ) ) ;
}
if ( V_54 )
F_43 ( V_54 , V_113 ) ;
}
if ( V_16 > V_112 ) {
if ( V_54 )
F_43 ( V_54 , V_113 ) ;
if ( V_56 ) {
struct V_64 * V_65 = V_56 -> V_28 ;
if ( V_65 -> V_61 )
(* V_65 -> V_61 ) ( V_56 ,
F_44 ( V_56 ) ) ;
}
}
return;
}
int F_46 ( struct V_71 * V_67 ,
struct V_114 * V_115 )
{
int V_99 ;
V_67 -> V_116 = V_115 -> V_116 ;
V_67 -> V_117 = V_115 -> V_117 ;
for ( V_99 = 0 ; V_99 < 4 ; V_99 ++ ) {
V_67 -> V_118 [ V_99 ] = V_115 -> V_118 [ V_99 ] ;
V_67 -> V_119 [ V_99 ] = V_115 -> V_119 [ V_99 ] ;
}
F_47 ( V_115 -> V_105 , & V_67 -> V_120 ,
& V_67 -> V_121 ) ;
V_67 -> V_105 = V_115 -> V_105 ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_53 * V_54 ;
struct V_64 * V_65 ;
int V_78 , V_113 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_56 -> V_66 )
continue;
V_78 = F_29 ( V_56 , & V_56 -> V_16 ,
V_56 -> V_69 , V_56 -> V_70 , V_56 -> V_67 ) ;
if ( V_78 == false )
F_41 ( L_25 , V_56 ) ;
if ( F_44 ( V_56 ) ) {
F_7 (encoder, &dev->mode_config.encoder_list, head) {
if( V_54 -> V_56 != V_56 )
continue;
V_113 = F_42 (
V_54 ) ;
F_43 ( V_54 , V_113 ) ;
}
V_65 = V_56 -> V_28 ;
if ( V_65 -> V_61 )
(* V_65 -> V_61 ) ( V_56 ,
F_44 ( V_56 ) ) ;
}
}
F_27 ( V_2 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
if ( V_2 -> V_12 . V_39 -> V_122 )
V_2 -> V_12 . V_39 -> V_122 ( V_2 ) ;
}
static void F_51 ( struct V_123 * V_124 )
{
struct V_125 * V_125 = F_52 ( V_124 ) ;
struct V_1 * V_2 = F_53 ( V_125 , struct V_1 , V_12 . V_126 ) ;
struct V_3 * V_4 ;
enum V_127 V_128 ;
bool V_129 = false , V_130 = false ;
if ( ! V_41 )
return;
F_54 ( & V_2 -> V_12 . V_131 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_35 )
continue;
if ( ! V_4 -> V_132 || V_4 -> V_132 == V_133 )
continue;
V_129 = true ;
V_128 = V_4 -> V_20 ;
if ( V_128 == V_37 &&
! ( V_4 -> V_132 & V_134 ) )
continue;
V_4 -> V_20 = V_4 -> V_39 -> V_40 ( V_4 , false ) ;
if ( V_128 != V_4 -> V_20 ) {
const char * V_135 , * V_136 ;
V_135 = F_55 ( V_128 ) ;
V_136 = F_55 ( V_4 -> V_20 ) ;
F_9 ( L_26
L_27 ,
V_4 -> V_32 . V_33 ,
F_10 ( V_4 ) ,
V_135 , V_136 ) ;
V_130 = true ;
}
}
F_56 ( & V_2 -> V_12 . V_131 ) ;
if ( V_130 )
F_49 ( V_2 ) ;
if ( V_129 )
F_57 ( V_125 , V_137 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_12 . V_138 )
return;
F_59 ( & V_2 -> V_12 . V_126 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
bool V_139 = false ;
struct V_3 * V_4 ;
if ( ! V_2 -> V_12 . V_138 || ! V_41 )
return;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_132 & ( V_140 |
V_134 ) )
V_139 = true ;
}
if ( V_139 )
F_57 ( & V_2 -> V_12 . V_126 , V_137 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_61 ( & V_2 -> V_12 . V_126 , F_51 ) ;
V_2 -> V_12 . V_138 = true ;
F_11 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
}
bool F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_127 V_128 ;
bool V_130 = false ;
if ( ! V_2 -> V_12 . V_138 )
return false ;
F_54 ( & V_2 -> V_12 . V_131 ) ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_4 -> V_132 & V_133 ) )
continue;
V_128 = V_4 -> V_20 ;
V_4 -> V_20 = V_4 -> V_39 -> V_40 ( V_4 , false ) ;
F_9 ( L_28 ,
V_4 -> V_32 . V_33 ,
F_10 ( V_4 ) ,
F_55 ( V_128 ) ,
F_55 ( V_4 -> V_20 ) ) ;
if ( V_128 != V_4 -> V_20 )
V_130 = true ;
}
F_56 ( & V_2 -> V_12 . V_131 ) ;
if ( V_130 )
F_49 ( V_2 ) ;
return V_130 ;
}
