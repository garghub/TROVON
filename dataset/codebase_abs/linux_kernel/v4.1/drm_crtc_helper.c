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
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_26 ( V_15 -> V_24 ) ;
if ( V_22 -> V_26 )
(* V_22 -> V_26 )( V_15 ) ;
else
(* V_22 -> V_27 )( V_15 , V_28 ) ;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_29 ( V_15 -> V_24 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_19 * V_20 ;
F_14 ( V_2 ) ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_6 ( V_15 ) ) {
F_12 ( V_15 ) ;
V_15 -> V_20 = NULL ;
}
}
F_10 (crtc, &dev->mode_config.crtc_list, head) {
const struct V_30 * V_31 = V_20 -> V_23 ;
V_20 -> V_32 = F_11 ( V_20 ) ;
if ( ! V_20 -> V_32 ) {
if ( V_31 -> V_26 )
(* V_31 -> V_26 )( V_20 ) ;
else
(* V_31 -> V_27 )( V_20 , V_28 ) ;
V_20 -> V_33 -> V_34 = NULL ;
}
}
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_13 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
const struct V_21 * V_22 ;
struct V_14 * V_15 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
V_22 = V_15 -> V_23 ;
if ( V_15 -> V_20 == NULL )
F_12 ( V_15 ) ;
if ( V_22 -> V_35 &&
V_15 -> V_20 != (* V_22 -> V_35 )( V_15 ) )
F_12 ( V_15 ) ;
}
}
bool F_19 ( struct V_19 * V_20 ,
struct V_36 * V_37 ,
int V_38 , int V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_36 * V_42 , V_43 , V_44 ;
const struct V_30 * V_31 = V_20 -> V_23 ;
const struct V_21 * V_22 ;
int V_45 , V_46 ;
bool V_47 ;
struct V_14 * V_15 ;
bool V_48 = true ;
F_14 ( V_2 ) ;
V_47 = V_20 -> V_32 ;
V_20 -> V_32 = F_11 ( V_20 ) ;
if ( ! V_20 -> V_32 )
return true ;
V_42 = F_20 ( V_2 , V_37 ) ;
if ( ! V_42 ) {
V_20 -> V_32 = V_47 ;
return false ;
}
V_43 = V_20 -> V_37 ;
V_44 = V_20 -> V_49 ;
V_45 = V_20 -> V_38 ;
V_46 = V_20 -> V_39 ;
V_20 -> V_37 = * V_37 ;
V_20 -> V_38 = V_38 ;
V_20 -> V_39 = V_39 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
if ( V_15 -> V_24 && V_15 -> V_24 -> V_25 -> V_50 ) {
V_48 = V_15 -> V_24 -> V_25 -> V_50 (
V_15 -> V_24 , V_37 , V_42 ) ;
if ( ! V_48 ) {
F_21 ( L_1 ) ;
goto V_51;
}
}
V_22 = V_15 -> V_23 ;
if ( ! ( V_48 = V_22 -> V_50 ( V_15 , V_37 ,
V_42 ) ) ) {
F_21 ( L_2 ) ;
goto V_51;
}
}
if ( ! ( V_48 = V_31 -> V_50 ( V_20 , V_37 , V_42 ) ) ) {
F_21 ( L_3 ) ;
goto V_51;
}
F_21 ( L_4 , V_20 -> V_52 . V_53 ) ;
V_20 -> V_49 = * V_42 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_26 ( V_15 -> V_24 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_54 ( V_15 ) ;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_29 ( V_15 -> V_24 ) ;
}
F_18 ( V_2 ) ;
V_31 -> V_54 ( V_20 ) ;
V_48 = ! V_31 -> V_55 ( V_20 , V_37 , V_42 , V_38 , V_39 , V_41 ) ;
if ( ! V_48 )
goto V_51;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
F_21 ( L_5 ,
V_15 -> V_52 . V_53 , V_15 -> V_56 ,
V_37 -> V_52 . V_53 , V_37 -> V_56 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_55 ( V_15 , V_37 , V_42 ) ;
if ( V_15 -> V_24 && V_15 -> V_24 -> V_25 -> V_55 )
V_15 -> V_24 -> V_25 -> V_55 ( V_15 -> V_24 , V_37 ,
V_42 ) ;
}
V_31 -> V_57 ( V_20 ) ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_58 ( V_15 -> V_24 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_57 ( V_15 ) ;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_59 ( V_15 -> V_24 ) ;
}
F_22 ( V_20 , & V_20 -> V_49 ) ;
V_51:
F_23 ( V_2 , V_42 ) ;
if ( ! V_48 ) {
V_20 -> V_32 = V_47 ;
V_20 -> V_37 = V_43 ;
V_20 -> V_49 = V_44 ;
V_20 -> V_38 = V_45 ;
V_20 -> V_39 = V_46 ;
}
return V_48 ;
}
static void
F_24 ( struct V_19 * V_20 )
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
V_4 -> V_27 = V_28 ;
}
}
F_13 ( V_2 ) ;
}
int F_25 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
struct V_19 * V_62 ;
struct V_14 * V_63 , * V_64 , * V_15 ;
bool V_65 = false ;
bool V_66 = false ;
struct V_3 * V_67 , * V_4 ;
int V_68 = 0 , V_69 , V_70 = 0 ;
const struct V_30 * V_31 ;
struct V_60 V_71 ;
int V_48 ;
int V_72 ;
F_21 ( L_6 ) ;
F_26 ( ! V_61 ) ;
F_26 ( ! V_61 -> V_20 ) ;
F_26 ( ! V_61 -> V_20 -> V_23 ) ;
F_26 ( ! V_61 -> V_37 && V_61 -> V_34 ) ;
F_26 ( V_61 -> V_34 && V_61 -> V_73 == 0 ) ;
V_31 = V_61 -> V_20 -> V_23 ;
if ( ! V_61 -> V_37 )
V_61 -> V_34 = NULL ;
if ( V_61 -> V_34 ) {
F_21 ( L_7 ,
V_61 -> V_20 -> V_52 . V_53 , V_61 -> V_34 -> V_52 . V_53 ,
( int ) V_61 -> V_73 , V_61 -> V_38 , V_61 -> V_39 ) ;
} else {
F_21 ( L_8 , V_61 -> V_20 -> V_52 . V_53 ) ;
F_24 ( V_61 -> V_20 ) ;
return 0 ;
}
V_2 = V_61 -> V_20 -> V_2 ;
F_14 ( V_2 ) ;
V_63 = F_27 ( V_2 -> V_12 . V_74 *
sizeof( struct V_14 ) , V_75 ) ;
if ( ! V_63 )
return - V_76 ;
V_67 = F_27 ( V_2 -> V_12 . V_77 *
sizeof( struct V_3 ) , V_75 ) ;
if ( ! V_67 ) {
F_28 ( V_63 ) ;
return - V_76 ;
}
V_68 = 0 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
V_63 [ V_68 ++ ] = * V_15 ;
}
V_68 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
V_67 [ V_68 ++ ] = * V_4 ;
}
V_71 . V_20 = V_61 -> V_20 ;
V_71 . V_37 = & V_61 -> V_20 -> V_37 ;
V_71 . V_38 = V_61 -> V_20 -> V_38 ;
V_71 . V_39 = V_61 -> V_20 -> V_39 ;
V_71 . V_34 = V_61 -> V_20 -> V_33 -> V_34 ;
if ( V_61 -> V_20 -> V_33 -> V_34 != V_61 -> V_34 ) {
if ( V_61 -> V_20 -> V_33 -> V_34 == NULL ) {
F_21 ( L_9 ) ;
V_65 = true ;
} else if ( V_61 -> V_34 == NULL ) {
V_65 = true ;
} else if ( V_61 -> V_34 -> V_78 !=
V_61 -> V_20 -> V_33 -> V_34 -> V_78 ) {
V_65 = true ;
} else
V_66 = true ;
}
if ( V_61 -> V_38 != V_61 -> V_20 -> V_38 || V_61 -> V_39 != V_61 -> V_20 -> V_39 )
V_66 = true ;
if ( V_61 -> V_37 && ! F_29 ( V_61 -> V_37 , & V_61 -> V_20 -> V_37 ) ) {
F_21 ( L_10 ) ;
F_30 ( & V_61 -> V_20 -> V_37 ) ;
F_30 ( V_61 -> V_37 ) ;
V_65 = true ;
}
V_68 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
const struct V_79 * V_80 =
V_4 -> V_23 ;
V_64 = V_4 -> V_15 ;
for ( V_69 = 0 ; V_69 < V_61 -> V_73 ; V_69 ++ ) {
if ( V_61 -> V_81 [ V_69 ] == V_4 ) {
V_64 = V_80 -> V_82 ( V_4 ) ;
if ( V_64 == NULL )
V_70 = 1 ;
if ( V_4 -> V_27 != V_83 ) {
F_21 ( L_11 ) ;
V_65 = true ;
}
break;
}
}
if ( V_64 != V_4 -> V_15 ) {
F_21 ( L_12 ) ;
V_65 = true ;
if ( V_4 -> V_15 )
V_4 -> V_15 -> V_20 = NULL ;
V_4 -> V_15 = V_64 ;
}
}
if ( V_70 ) {
V_48 = - V_84 ;
goto V_70;
}
V_68 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_15 )
continue;
if ( V_4 -> V_15 -> V_20 == V_61 -> V_20 )
V_62 = NULL ;
else
V_62 = V_4 -> V_15 -> V_20 ;
for ( V_69 = 0 ; V_69 < V_61 -> V_73 ; V_69 ++ ) {
if ( V_61 -> V_81 [ V_69 ] == V_4 )
V_62 = V_61 -> V_20 ;
}
if ( V_62 &&
! F_31 ( V_4 -> V_15 , V_62 ) ) {
V_48 = - V_84 ;
goto V_70;
}
if ( V_62 != V_4 -> V_15 -> V_20 ) {
F_21 ( L_13 ) ;
V_65 = true ;
V_4 -> V_15 -> V_20 = V_62 ;
}
if ( V_62 ) {
F_21 ( L_14 ,
V_4 -> V_52 . V_53 , V_4 -> V_56 ,
V_62 -> V_52 . V_53 ) ;
} else {
F_21 ( L_15 ,
V_4 -> V_52 . V_53 , V_4 -> V_56 ) ;
}
}
if ( V_66 && ! V_31 -> V_85 )
V_65 = true ;
if ( V_65 ) {
if ( F_11 ( V_61 -> V_20 ) ) {
F_21 ( L_16
L_17 ) ;
F_30 ( V_61 -> V_37 ) ;
V_61 -> V_20 -> V_33 -> V_34 = V_61 -> V_34 ;
if ( ! F_19 ( V_61 -> V_20 , V_61 -> V_37 ,
V_61 -> V_38 , V_61 -> V_39 ,
V_71 . V_34 ) ) {
F_32 ( L_18 ,
V_61 -> V_20 -> V_52 . V_53 ) ;
V_61 -> V_20 -> V_33 -> V_34 = V_71 . V_34 ;
V_48 = - V_84 ;
goto V_70;
}
F_21 ( L_19 ) ;
for ( V_72 = 0 ; V_72 < V_61 -> V_73 ; V_72 ++ ) {
F_21 ( L_20 , V_61 -> V_81 [ V_72 ] -> V_52 . V_53 ,
V_61 -> V_81 [ V_72 ] -> V_56 ) ;
V_61 -> V_81 [ V_72 ] -> V_25 -> V_27 ( V_61 -> V_81 [ V_72 ] , V_83 ) ;
}
}
F_13 ( V_2 ) ;
} else if ( V_66 ) {
V_61 -> V_20 -> V_38 = V_61 -> V_38 ;
V_61 -> V_20 -> V_39 = V_61 -> V_39 ;
V_61 -> V_20 -> V_33 -> V_34 = V_61 -> V_34 ;
V_48 = V_31 -> V_85 ( V_61 -> V_20 ,
V_61 -> V_38 , V_61 -> V_39 , V_71 . V_34 ) ;
if ( V_48 != 0 ) {
V_61 -> V_20 -> V_38 = V_71 . V_38 ;
V_61 -> V_20 -> V_39 = V_71 . V_39 ;
V_61 -> V_20 -> V_33 -> V_34 = V_71 . V_34 ;
goto V_70;
}
}
F_28 ( V_67 ) ;
F_28 ( V_63 ) ;
return 0 ;
V_70:
V_68 = 0 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
* V_15 = V_63 [ V_68 ++ ] ;
}
V_68 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_67 [ V_68 ++ ] ;
}
if ( V_65 &&
! F_19 ( V_71 . V_20 , V_71 . V_37 , V_71 . V_38 ,
V_71 . V_39 , V_71 . V_34 ) )
F_32 ( L_21 ) ;
F_28 ( V_67 ) ;
F_28 ( V_63 ) ;
return V_48 ;
}
static int F_33 ( struct V_14 * V_15 )
{
int V_27 = V_28 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_10 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_15 == V_15 )
if ( V_4 -> V_27 < V_27 )
V_27 = V_4 -> V_27 ;
return V_27 ;
}
static void F_34 ( struct V_14 * V_15 , int V_37 )
{
struct V_86 * V_24 = V_15 -> V_24 ;
const struct V_21 * V_22 ;
if ( V_24 ) {
if ( V_37 == V_83 )
V_24 -> V_25 -> V_58 ( V_24 ) ;
else
V_24 -> V_25 -> V_26 ( V_24 ) ;
}
V_22 = V_15 -> V_23 ;
if ( V_22 -> V_27 )
V_22 -> V_27 ( V_15 , V_37 ) ;
if ( V_24 ) {
if ( V_37 == V_83 )
V_24 -> V_25 -> V_59 ( V_24 ) ;
else
V_24 -> V_25 -> V_29 ( V_24 ) ;
}
}
static int F_35 ( struct V_19 * V_20 )
{
int V_27 = V_28 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_20 -> V_2 ;
F_10 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_15 && V_4 -> V_15 -> V_20 == V_20 )
if ( V_4 -> V_27 < V_27 )
V_27 = V_4 -> V_27 ;
return V_27 ;
}
void F_36 ( struct V_3 * V_4 , int V_37 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_19 * V_20 = V_15 ? V_15 -> V_20 : NULL ;
int V_87 , V_88 = V_28 ;
if ( V_37 == V_4 -> V_27 )
return;
V_87 = V_4 -> V_27 ;
V_4 -> V_27 = V_37 ;
if ( V_15 )
V_88 = F_33 ( V_15 ) ;
if ( V_37 < V_87 ) {
if ( V_20 ) {
const struct V_30 * V_31 = V_20 -> V_23 ;
if ( V_31 -> V_27 )
(* V_31 -> V_27 ) ( V_20 ,
F_35 ( V_20 ) ) ;
}
if ( V_15 )
F_34 ( V_15 , V_88 ) ;
}
if ( V_37 > V_87 ) {
if ( V_15 )
F_34 ( V_15 , V_88 ) ;
if ( V_20 ) {
const struct V_30 * V_31 = V_20 -> V_23 ;
if ( V_31 -> V_27 )
(* V_31 -> V_27 ) ( V_20 ,
F_35 ( V_20 ) ) ;
}
}
return;
}
void F_37 ( struct V_40 * V_34 ,
struct V_89 * V_90 )
{
int V_72 ;
V_34 -> V_91 = V_90 -> V_91 ;
V_34 -> V_92 = V_90 -> V_92 ;
for ( V_72 = 0 ; V_72 < 4 ; V_72 ++ ) {
V_34 -> V_93 [ V_72 ] = V_90 -> V_93 [ V_72 ] ;
V_34 -> V_94 [ V_72 ] = V_90 -> V_94 [ V_72 ] ;
V_34 -> V_95 [ V_72 ] = V_90 -> V_95 [ V_72 ] ;
}
F_38 ( V_90 -> V_78 , & V_34 -> V_96 ,
& V_34 -> V_97 ) ;
V_34 -> V_78 = V_90 -> V_78 ;
V_34 -> V_98 = V_90 -> V_98 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_14 * V_15 ;
const struct V_30 * V_31 ;
int V_88 ;
bool V_48 ;
F_16 ( V_2 ) ;
F_10 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_20 -> V_32 )
continue;
V_48 = F_19 ( V_20 , & V_20 -> V_37 ,
V_20 -> V_38 , V_20 -> V_39 , V_20 -> V_33 -> V_34 ) ;
if ( V_48 == false )
F_32 ( L_22 , V_20 ) ;
if ( F_35 ( V_20 ) ) {
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if( V_15 -> V_20 != V_20 )
continue;
V_88 = F_33 (
V_15 ) ;
F_34 ( V_15 , V_88 ) ;
}
V_31 = V_20 -> V_23 ;
if ( V_31 -> V_27 )
(* V_31 -> V_27 ) ( V_20 ,
F_35 ( V_20 ) ) ;
}
}
F_13 ( V_2 ) ;
F_17 ( V_2 ) ;
}
int F_40 ( struct V_19 * V_20 , struct V_36 * V_37 ,
struct V_36 * V_42 , int V_38 , int V_39 ,
struct V_40 * V_41 )
{
struct V_99 * V_100 ;
const struct V_30 * V_31 = V_20 -> V_23 ;
int V_48 ;
if ( V_20 -> V_25 -> V_101 )
V_100 = V_20 -> V_25 -> V_101 ( V_20 ) ;
else if ( V_20 -> V_102 )
V_100 = F_41 ( V_20 -> V_102 , sizeof( * V_100 ) ,
V_75 ) ;
else
V_100 = F_27 ( sizeof( * V_100 ) , V_75 ) ;
if ( ! V_100 )
return - V_76 ;
V_100 -> V_20 = V_20 ;
V_100 -> V_59 = true ;
V_100 -> V_103 = true ;
V_100 -> V_65 = true ;
F_42 ( & V_100 -> V_37 , V_37 ) ;
F_42 ( & V_100 -> V_42 , V_42 ) ;
if ( V_31 -> V_104 ) {
V_48 = V_31 -> V_104 ( V_20 , V_100 ) ;
if ( V_48 ) {
F_28 ( V_100 ) ;
return V_48 ;
}
}
F_43 ( V_20 -> V_102 , V_100 ) ;
V_31 -> V_105 ( V_20 ) ;
if ( V_100 ) {
if ( V_20 -> V_25 -> V_106 )
V_20 -> V_25 -> V_106 ( V_20 , V_100 ) ;
else
F_28 ( V_100 ) ;
}
return F_44 ( V_20 , V_38 , V_39 , V_41 ) ;
}
int F_44 ( struct V_19 * V_20 , int V_38 , int V_39 ,
struct V_40 * V_41 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 = V_20 -> V_33 ;
if ( V_110 -> V_25 -> V_101 )
V_108 = V_110 -> V_25 -> V_101 ( V_110 ) ;
else if ( V_110 -> V_102 )
V_108 = F_45 ( V_110 ) ;
else
V_108 = F_27 ( sizeof( * V_108 ) , V_75 ) ;
if ( ! V_108 )
return - V_76 ;
V_108 -> V_110 = V_110 ;
V_108 -> V_20 = V_20 ;
F_46 ( V_108 , V_20 -> V_33 -> V_34 ) ;
V_108 -> V_111 = 0 ;
V_108 -> V_112 = 0 ;
V_108 -> V_113 = V_20 -> V_37 . V_114 ;
V_108 -> V_115 = V_20 -> V_37 . V_116 ;
V_108 -> V_117 = V_38 << 16 ;
V_108 -> V_118 = V_39 << 16 ;
V_108 -> V_119 = V_20 -> V_37 . V_114 << 16 ;
V_108 -> V_120 = V_20 -> V_37 . V_116 << 16 ;
return F_47 ( V_110 , V_108 , V_41 ) ;
}
