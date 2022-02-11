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
bool F_6 ( struct V_14 * V_15 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( ! V_16 ) {
F_7 ( ! F_8 ( & V_2 -> V_12 . V_17 ) ) ;
F_7 ( ! F_9 ( & V_2 -> V_12 . V_18 ) ) ;
}
F_10 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_15 == V_15 )
return true ;
return false ;
}
bool F_11 ( struct V_19 * V_20 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 = V_20 -> V_2 ;
if ( ! V_16 )
F_7 ( ! F_8 ( & V_2 -> V_12 . V_17 ) ) ;
F_10 (encoder, &dev->mode_config.encoder_list, head)
if ( V_15 -> V_20 == V_20 && F_6 ( V_15 ) )
return true ;
return false ;
}
static void
F_12 ( struct V_14 * V_15 )
{
const struct V_21 * V_22 = V_15 -> V_23 ;
F_13 ( V_15 -> V_24 ) ;
if ( V_22 -> V_25 )
(* V_22 -> V_25 )( V_15 ) ;
else
(* V_22 -> V_26 )( V_15 , V_27 ) ;
F_14 ( V_15 -> V_24 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_19 * V_20 ;
F_16 ( V_2 ) ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_6 ( V_15 ) ) {
F_12 ( V_15 ) ;
V_15 -> V_20 = NULL ;
}
}
F_10 (crtc, &dev->mode_config.crtc_list, head) {
const struct V_28 * V_29 = V_20 -> V_23 ;
V_20 -> V_30 = F_11 ( V_20 ) ;
if ( ! V_20 -> V_30 ) {
if ( V_29 -> V_25 )
(* V_29 -> V_25 )( V_20 ) ;
else
(* V_29 -> V_26 )( V_20 , V_27 ) ;
V_20 -> V_31 -> V_32 = NULL ;
}
}
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_15 ( V_2 ) ;
F_19 ( V_2 ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
const struct V_21 * V_22 ;
struct V_14 * V_15 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
V_22 = V_15 -> V_23 ;
if ( V_15 -> V_20 == NULL )
F_12 ( V_15 ) ;
if ( V_22 -> V_33 &&
V_15 -> V_20 != (* V_22 -> V_33 )( V_15 ) )
F_12 ( V_15 ) ;
}
}
bool F_21 ( struct V_19 * V_20 ,
struct V_34 * V_35 ,
int V_36 , int V_37 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_34 * V_40 , V_41 , V_42 ;
const struct V_28 * V_29 = V_20 -> V_23 ;
const struct V_21 * V_22 ;
int V_43 , V_44 ;
bool V_45 ;
struct V_14 * V_15 ;
bool V_46 = true ;
F_16 ( V_2 ) ;
V_45 = V_20 -> V_30 ;
V_20 -> V_30 = F_11 ( V_20 ) ;
if ( ! V_20 -> V_30 )
return true ;
V_40 = F_22 ( V_2 , V_35 ) ;
if ( ! V_40 ) {
V_20 -> V_30 = V_45 ;
return false ;
}
V_41 = V_20 -> V_35 ;
V_42 = V_20 -> V_47 ;
V_43 = V_20 -> V_36 ;
V_44 = V_20 -> V_37 ;
V_20 -> V_35 = * V_35 ;
V_20 -> V_36 = V_36 ;
V_20 -> V_37 = V_37 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
V_46 = F_23 ( V_15 -> V_24 ,
V_35 , V_40 ) ;
if ( ! V_46 ) {
F_24 ( L_1 ) ;
goto V_48;
}
V_22 = V_15 -> V_23 ;
if ( ! ( V_46 = V_22 -> V_49 ( V_15 , V_35 ,
V_40 ) ) ) {
F_24 ( L_2 ) ;
goto V_48;
}
}
if ( ! ( V_46 = V_29 -> V_49 ( V_20 , V_35 , V_40 ) ) ) {
F_24 ( L_3 ) ;
goto V_48;
}
F_24 ( L_4 , V_20 -> V_50 . V_51 ) ;
V_20 -> V_47 = * V_40 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
F_13 ( V_15 -> V_24 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_52 ( V_15 ) ;
F_14 ( V_15 -> V_24 ) ;
}
F_20 ( V_2 ) ;
V_29 -> V_52 ( V_20 ) ;
V_46 = ! V_29 -> V_53 ( V_20 , V_35 , V_40 , V_36 , V_37 , V_39 ) ;
if ( ! V_46 )
goto V_48;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
F_24 ( L_5 ,
V_15 -> V_50 . V_51 , V_15 -> V_54 ,
V_35 -> V_50 . V_51 , V_35 -> V_54 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_53 ( V_15 , V_35 , V_40 ) ;
F_25 ( V_15 -> V_24 , V_35 , V_40 ) ;
}
V_29 -> V_55 ( V_20 ) ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
F_26 ( V_15 -> V_24 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_55 ( V_15 ) ;
F_27 ( V_15 -> V_24 ) ;
}
F_28 ( V_20 , & V_20 -> V_47 ) ;
V_48:
F_29 ( V_2 , V_40 ) ;
if ( ! V_46 ) {
V_20 -> V_30 = V_45 ;
V_20 -> V_35 = V_41 ;
V_20 -> V_47 = V_42 ;
V_20 -> V_36 = V_43 ;
V_20 -> V_37 = V_44 ;
}
return V_46 ;
}
static void
F_30 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
F_10 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_15 != V_15 )
continue;
V_4 -> V_15 = NULL ;
V_4 -> V_26 = V_27 ;
}
}
F_15 ( V_2 ) ;
}
int F_31 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
struct V_19 * V_58 ;
struct V_14 * V_59 , * V_60 , * V_15 ;
bool V_61 = false ;
bool V_62 = false ;
struct V_3 * V_63 , * V_4 ;
int V_64 = 0 , V_65 , V_66 = 0 ;
const struct V_28 * V_29 ;
struct V_56 V_67 ;
int V_46 ;
int V_68 ;
F_24 ( L_6 ) ;
F_32 ( ! V_57 ) ;
F_32 ( ! V_57 -> V_20 ) ;
F_32 ( ! V_57 -> V_20 -> V_23 ) ;
F_32 ( ! V_57 -> V_35 && V_57 -> V_32 ) ;
F_32 ( V_57 -> V_32 && V_57 -> V_69 == 0 ) ;
V_29 = V_57 -> V_20 -> V_23 ;
if ( ! V_57 -> V_35 )
V_57 -> V_32 = NULL ;
if ( V_57 -> V_32 ) {
F_24 ( L_7 ,
V_57 -> V_20 -> V_50 . V_51 , V_57 -> V_32 -> V_50 . V_51 ,
( int ) V_57 -> V_69 , V_57 -> V_36 , V_57 -> V_37 ) ;
} else {
F_24 ( L_8 , V_57 -> V_20 -> V_50 . V_51 ) ;
F_30 ( V_57 -> V_20 ) ;
return 0 ;
}
V_2 = V_57 -> V_20 -> V_2 ;
F_16 ( V_2 ) ;
V_59 = F_33 ( V_2 -> V_12 . V_70 *
sizeof( struct V_14 ) , V_71 ) ;
if ( ! V_59 )
return - V_72 ;
V_63 = F_33 ( V_2 -> V_12 . V_73 *
sizeof( struct V_3 ) , V_71 ) ;
if ( ! V_63 ) {
F_34 ( V_59 ) ;
return - V_72 ;
}
V_64 = 0 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
V_59 [ V_64 ++ ] = * V_15 ;
}
V_64 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
V_63 [ V_64 ++ ] = * V_4 ;
}
V_67 . V_20 = V_57 -> V_20 ;
V_67 . V_35 = & V_57 -> V_20 -> V_35 ;
V_67 . V_36 = V_57 -> V_20 -> V_36 ;
V_67 . V_37 = V_57 -> V_20 -> V_37 ;
V_67 . V_32 = V_57 -> V_20 -> V_31 -> V_32 ;
if ( V_57 -> V_20 -> V_31 -> V_32 != V_57 -> V_32 ) {
if ( V_57 -> V_20 -> V_31 -> V_32 == NULL ) {
F_24 ( L_9 ) ;
V_61 = true ;
} else if ( V_57 -> V_32 == NULL ) {
V_61 = true ;
} else if ( V_57 -> V_32 -> V_74 !=
V_57 -> V_20 -> V_31 -> V_32 -> V_74 ) {
V_61 = true ;
} else
V_62 = true ;
}
if ( V_57 -> V_36 != V_57 -> V_20 -> V_36 || V_57 -> V_37 != V_57 -> V_20 -> V_37 )
V_62 = true ;
if ( V_57 -> V_35 && ! F_35 ( V_57 -> V_35 , & V_57 -> V_20 -> V_35 ) ) {
F_24 ( L_10 ) ;
F_36 ( & V_57 -> V_20 -> V_35 ) ;
F_36 ( V_57 -> V_35 ) ;
V_61 = true ;
}
V_64 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
const struct V_75 * V_76 =
V_4 -> V_23 ;
V_60 = V_4 -> V_15 ;
for ( V_65 = 0 ; V_65 < V_57 -> V_69 ; V_65 ++ ) {
if ( V_57 -> V_77 [ V_65 ] == V_4 ) {
V_60 = V_76 -> V_78 ( V_4 ) ;
if ( V_60 == NULL )
V_66 = 1 ;
if ( V_4 -> V_26 != V_79 ) {
F_24 ( L_11 ) ;
V_61 = true ;
}
break;
}
}
if ( V_60 != V_4 -> V_15 ) {
F_24 ( L_12 ) ;
V_61 = true ;
if ( V_4 -> V_15 )
V_4 -> V_15 -> V_20 = NULL ;
V_4 -> V_15 = V_60 ;
}
}
if ( V_66 ) {
V_46 = - V_80 ;
goto V_66;
}
V_64 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_15 )
continue;
if ( V_4 -> V_15 -> V_20 == V_57 -> V_20 )
V_58 = NULL ;
else
V_58 = V_4 -> V_15 -> V_20 ;
for ( V_65 = 0 ; V_65 < V_57 -> V_69 ; V_65 ++ ) {
if ( V_57 -> V_77 [ V_65 ] == V_4 )
V_58 = V_57 -> V_20 ;
}
if ( V_58 &&
! F_37 ( V_4 -> V_15 , V_58 ) ) {
V_46 = - V_80 ;
goto V_66;
}
if ( V_58 != V_4 -> V_15 -> V_20 ) {
F_24 ( L_13 ) ;
V_61 = true ;
V_4 -> V_15 -> V_20 = V_58 ;
}
if ( V_58 ) {
F_24 ( L_14 ,
V_4 -> V_50 . V_51 , V_4 -> V_54 ,
V_58 -> V_50 . V_51 ) ;
} else {
F_24 ( L_15 ,
V_4 -> V_50 . V_51 , V_4 -> V_54 ) ;
}
}
if ( V_62 && ! V_29 -> V_81 )
V_61 = true ;
if ( V_61 ) {
if ( F_11 ( V_57 -> V_20 ) ) {
F_24 ( L_16
L_17 ) ;
F_36 ( V_57 -> V_35 ) ;
V_57 -> V_20 -> V_31 -> V_32 = V_57 -> V_32 ;
if ( ! F_21 ( V_57 -> V_20 , V_57 -> V_35 ,
V_57 -> V_36 , V_57 -> V_37 ,
V_67 . V_32 ) ) {
F_38 ( L_18 ,
V_57 -> V_20 -> V_50 . V_51 ) ;
V_57 -> V_20 -> V_31 -> V_32 = V_67 . V_32 ;
V_46 = - V_80 ;
goto V_66;
}
F_24 ( L_19 ) ;
for ( V_68 = 0 ; V_68 < V_57 -> V_69 ; V_68 ++ ) {
F_24 ( L_20 , V_57 -> V_77 [ V_68 ] -> V_50 . V_51 ,
V_57 -> V_77 [ V_68 ] -> V_54 ) ;
V_57 -> V_77 [ V_68 ] -> V_82 -> V_26 ( V_57 -> V_77 [ V_68 ] , V_79 ) ;
}
}
F_15 ( V_2 ) ;
} else if ( V_62 ) {
V_57 -> V_20 -> V_36 = V_57 -> V_36 ;
V_57 -> V_20 -> V_37 = V_57 -> V_37 ;
V_57 -> V_20 -> V_31 -> V_32 = V_57 -> V_32 ;
V_46 = V_29 -> V_81 ( V_57 -> V_20 ,
V_57 -> V_36 , V_57 -> V_37 , V_67 . V_32 ) ;
if ( V_46 != 0 ) {
V_57 -> V_20 -> V_36 = V_67 . V_36 ;
V_57 -> V_20 -> V_37 = V_67 . V_37 ;
V_57 -> V_20 -> V_31 -> V_32 = V_67 . V_32 ;
goto V_66;
}
}
F_34 ( V_63 ) ;
F_34 ( V_59 ) ;
return 0 ;
V_66:
V_64 = 0 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
* V_15 = V_59 [ V_64 ++ ] ;
}
V_64 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_63 [ V_64 ++ ] ;
}
if ( V_61 &&
! F_21 ( V_67 . V_20 , V_67 . V_35 , V_67 . V_36 ,
V_67 . V_37 , V_67 . V_32 ) )
F_38 ( L_21 ) ;
F_34 ( V_63 ) ;
F_34 ( V_59 ) ;
return V_46 ;
}
static int F_39 ( struct V_14 * V_15 )
{
int V_26 = V_27 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_10 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_15 == V_15 )
if ( V_4 -> V_26 < V_26 )
V_26 = V_4 -> V_26 ;
return V_26 ;
}
static void F_40 ( struct V_14 * V_15 , int V_35 )
{
struct V_83 * V_24 = V_15 -> V_24 ;
const struct V_21 * V_22 ;
if ( V_35 == V_79 )
F_26 ( V_24 ) ;
else
F_13 ( V_24 ) ;
V_22 = V_15 -> V_23 ;
if ( V_22 -> V_26 )
V_22 -> V_26 ( V_15 , V_35 ) ;
if ( V_35 == V_79 )
F_27 ( V_24 ) ;
else
F_14 ( V_24 ) ;
}
static int F_41 ( struct V_19 * V_20 )
{
int V_26 = V_27 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_20 -> V_2 ;
F_10 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_15 && V_4 -> V_15 -> V_20 == V_20 )
if ( V_4 -> V_26 < V_26 )
V_26 = V_4 -> V_26 ;
return V_26 ;
}
void F_42 ( struct V_3 * V_4 , int V_35 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_19 * V_20 = V_15 ? V_15 -> V_20 : NULL ;
int V_84 , V_85 = V_27 ;
if ( V_35 == V_4 -> V_26 )
return;
V_84 = V_4 -> V_26 ;
V_4 -> V_26 = V_35 ;
if ( V_15 )
V_85 = F_39 ( V_15 ) ;
if ( V_35 < V_84 ) {
if ( V_20 ) {
const struct V_28 * V_29 = V_20 -> V_23 ;
if ( V_29 -> V_26 )
(* V_29 -> V_26 ) ( V_20 ,
F_41 ( V_20 ) ) ;
}
if ( V_15 )
F_40 ( V_15 , V_85 ) ;
}
if ( V_35 > V_84 ) {
if ( V_15 )
F_40 ( V_15 , V_85 ) ;
if ( V_20 ) {
const struct V_28 * V_29 = V_20 -> V_23 ;
if ( V_29 -> V_26 )
(* V_29 -> V_26 ) ( V_20 ,
F_41 ( V_20 ) ) ;
}
}
return;
}
void F_43 ( struct V_38 * V_32 ,
struct V_86 * V_87 )
{
int V_68 ;
V_32 -> V_88 = V_87 -> V_88 ;
V_32 -> V_89 = V_87 -> V_89 ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ ) {
V_32 -> V_90 [ V_68 ] = V_87 -> V_90 [ V_68 ] ;
V_32 -> V_91 [ V_68 ] = V_87 -> V_91 [ V_68 ] ;
V_32 -> V_92 [ V_68 ] = V_87 -> V_92 [ V_68 ] ;
}
F_44 ( V_87 -> V_74 , & V_32 -> V_93 ,
& V_32 -> V_94 ) ;
V_32 -> V_74 = V_87 -> V_74 ;
V_32 -> V_95 = V_87 -> V_95 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_14 * V_15 ;
const struct V_28 * V_29 ;
int V_85 ;
bool V_46 ;
F_18 ( V_2 ) ;
F_10 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_20 -> V_30 )
continue;
V_46 = F_21 ( V_20 , & V_20 -> V_35 ,
V_20 -> V_36 , V_20 -> V_37 , V_20 -> V_31 -> V_32 ) ;
if ( V_46 == false )
F_38 ( L_22 , V_20 ) ;
if ( F_41 ( V_20 ) ) {
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if( V_15 -> V_20 != V_20 )
continue;
V_85 = F_39 (
V_15 ) ;
F_40 ( V_15 , V_85 ) ;
}
V_29 = V_20 -> V_23 ;
if ( V_29 -> V_26 )
(* V_29 -> V_26 ) ( V_20 ,
F_41 ( V_20 ) ) ;
}
}
F_15 ( V_2 ) ;
F_19 ( V_2 ) ;
}
int F_46 ( struct V_19 * V_20 , struct V_34 * V_35 ,
struct V_34 * V_40 , int V_36 , int V_37 ,
struct V_38 * V_39 )
{
struct V_96 * V_97 ;
const struct V_28 * V_29 = V_20 -> V_23 ;
int V_46 ;
if ( V_20 -> V_82 -> V_98 )
V_97 = V_20 -> V_82 -> V_98 ( V_20 ) ;
else {
V_97 = F_33 ( sizeof( * V_97 ) , V_71 ) ;
if ( ! V_97 )
return - V_72 ;
if ( V_20 -> V_99 )
F_47 ( V_20 , V_97 ) ;
else
V_97 -> V_20 = V_20 ;
}
V_97 -> V_100 = true ;
V_97 -> V_61 = true ;
V_46 = F_48 ( V_97 , V_35 ) ;
if ( V_46 )
goto V_101;
F_49 ( & V_97 -> V_40 , V_40 ) ;
if ( V_29 -> V_102 ) {
V_46 = V_29 -> V_102 ( V_20 , V_97 ) ;
if ( V_46 )
goto V_101;
}
F_50 ( V_20 -> V_99 , V_97 ) ;
V_29 -> V_103 ( V_20 ) ;
V_46 = F_51 ( V_20 , V_36 , V_37 , V_39 ) ;
V_101:
if ( V_20 -> V_82 -> V_104 )
V_20 -> V_82 -> V_104 ( V_20 , V_97 ) ;
else {
F_52 ( V_20 , V_97 ) ;
F_34 ( V_97 ) ;
}
return V_46 ;
}
int F_51 ( struct V_19 * V_20 , int V_36 , int V_37 ,
struct V_38 * V_39 )
{
struct V_105 * V_106 ;
struct V_107 * V_108 = V_20 -> V_31 ;
if ( V_108 -> V_82 -> V_98 )
V_106 = V_108 -> V_82 -> V_98 ( V_108 ) ;
else if ( V_108 -> V_99 )
V_106 = F_53 ( V_108 ) ;
else
V_106 = F_33 ( sizeof( * V_106 ) , V_71 ) ;
if ( ! V_106 )
return - V_72 ;
V_106 -> V_108 = V_108 ;
V_106 -> V_20 = V_20 ;
F_54 ( V_106 , V_20 -> V_31 -> V_32 ) ;
V_106 -> V_109 = 0 ;
V_106 -> V_110 = 0 ;
V_106 -> V_111 = V_20 -> V_35 . V_112 ;
V_106 -> V_113 = V_20 -> V_35 . V_114 ;
V_106 -> V_115 = V_36 << 16 ;
V_106 -> V_116 = V_37 << 16 ;
V_106 -> V_117 = V_20 -> V_35 . V_112 << 16 ;
V_106 -> V_118 = V_20 -> V_35 . V_114 << 16 ;
return F_55 ( V_108 , V_106 , V_39 ) ;
}
