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
if ( ! V_16 )
F_7 ( ! F_8 ( & V_2 -> V_12 . V_17 ) ) ;
F_9 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_15 == V_15 )
return true ;
return false ;
}
bool F_10 ( struct V_18 * V_19 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_16 )
F_7 ( ! F_8 ( & V_2 -> V_12 . V_17 ) ) ;
F_9 (encoder, &dev->mode_config.encoder_list, head)
if ( V_15 -> V_19 == V_19 && F_6 ( V_15 ) )
return true ;
return false ;
}
static void
F_11 ( struct V_14 * V_15 )
{
struct V_20 * V_21 = V_15 -> V_22 ;
if ( V_15 -> V_23 )
V_15 -> V_23 -> V_24 -> V_25 ( V_15 -> V_23 ) ;
if ( V_21 -> V_25 )
(* V_21 -> V_25 )( V_15 ) ;
else
(* V_21 -> V_26 )( V_15 , V_27 ) ;
if ( V_15 -> V_23 )
V_15 -> V_23 -> V_24 -> V_28 ( V_15 -> V_23 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
struct V_18 * V_19 ;
F_13 ( V_2 ) ;
F_9 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_15 )
continue;
}
F_9 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_6 ( V_15 ) ) {
F_11 ( V_15 ) ;
V_15 -> V_19 = NULL ;
}
}
F_9 (crtc, &dev->mode_config.crtc_list, head) {
struct V_29 * V_30 = V_19 -> V_22 ;
V_19 -> V_31 = F_10 ( V_19 ) ;
if ( ! V_19 -> V_31 ) {
if ( V_30 -> V_25 )
(* V_30 -> V_25 )( V_19 ) ;
else
(* V_30 -> V_26 )( V_19 , V_27 ) ;
V_19 -> V_32 -> V_33 = NULL ;
}
}
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_12 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static void
F_17 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
F_9 (encoder, &dev->mode_config.encoder_list, head) {
V_21 = V_15 -> V_22 ;
if ( V_15 -> V_19 == NULL )
F_11 ( V_15 ) ;
if ( V_21 -> V_34 &&
V_15 -> V_19 != (* V_21 -> V_34 )( V_15 ) )
F_11 ( V_15 ) ;
}
}
bool F_18 ( struct V_18 * V_19 ,
struct V_35 * V_36 ,
int V_37 , int V_38 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_35 * V_41 , V_42 ;
struct V_29 * V_30 = V_19 -> V_22 ;
struct V_20 * V_21 ;
int V_43 , V_44 ;
bool V_45 ;
struct V_14 * V_15 ;
bool V_46 = true ;
F_13 ( V_2 ) ;
V_45 = V_19 -> V_31 ;
V_19 -> V_31 = F_10 ( V_19 ) ;
if ( ! V_19 -> V_31 )
return true ;
V_41 = F_19 ( V_2 , V_36 ) ;
if ( ! V_41 ) {
V_19 -> V_31 = V_45 ;
return false ;
}
V_42 = V_19 -> V_36 ;
V_43 = V_19 -> V_37 ;
V_44 = V_19 -> V_38 ;
V_19 -> V_36 = * V_36 ;
V_19 -> V_37 = V_37 ;
V_19 -> V_38 = V_38 ;
F_9 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_19 != V_19 )
continue;
if ( V_15 -> V_23 && V_15 -> V_23 -> V_24 -> V_47 ) {
V_46 = V_15 -> V_23 -> V_24 -> V_47 (
V_15 -> V_23 , V_36 , V_41 ) ;
if ( ! V_46 ) {
F_20 ( L_1 ) ;
goto V_48;
}
}
V_21 = V_15 -> V_22 ;
if ( ! ( V_46 = V_21 -> V_47 ( V_15 , V_36 ,
V_41 ) ) ) {
F_20 ( L_2 ) ;
goto V_48;
}
}
if ( ! ( V_46 = V_30 -> V_47 ( V_19 , V_36 , V_41 ) ) ) {
F_20 ( L_3 ) ;
goto V_48;
}
F_20 ( L_4 , V_19 -> V_49 . V_50 ) ;
F_9 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_19 != V_19 )
continue;
if ( V_15 -> V_23 )
V_15 -> V_23 -> V_24 -> V_25 ( V_15 -> V_23 ) ;
V_21 = V_15 -> V_22 ;
V_21 -> V_51 ( V_15 ) ;
if ( V_15 -> V_23 )
V_15 -> V_23 -> V_24 -> V_28 ( V_15 -> V_23 ) ;
}
F_17 ( V_2 ) ;
V_30 -> V_51 ( V_19 ) ;
V_46 = ! V_30 -> V_52 ( V_19 , V_36 , V_41 , V_37 , V_38 , V_40 ) ;
if ( ! V_46 )
goto V_48;
F_9 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_19 != V_19 )
continue;
F_20 ( L_5 ,
V_15 -> V_49 . V_50 , F_21 ( V_15 ) ,
V_36 -> V_49 . V_50 , V_36 -> V_53 ) ;
V_21 = V_15 -> V_22 ;
V_21 -> V_52 ( V_15 , V_36 , V_41 ) ;
if ( V_15 -> V_23 && V_15 -> V_23 -> V_24 -> V_52 )
V_15 -> V_23 -> V_24 -> V_52 ( V_15 -> V_23 , V_36 ,
V_41 ) ;
}
V_30 -> V_54 ( V_19 ) ;
F_9 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_19 != V_19 )
continue;
if ( V_15 -> V_23 )
V_15 -> V_23 -> V_24 -> V_55 ( V_15 -> V_23 ) ;
V_21 = V_15 -> V_22 ;
V_21 -> V_54 ( V_15 ) ;
if ( V_15 -> V_23 )
V_15 -> V_23 -> V_24 -> V_56 ( V_15 -> V_23 ) ;
}
V_19 -> V_57 = * V_41 ;
F_22 ( V_19 , & V_19 -> V_57 ) ;
V_48:
F_23 ( V_2 , V_41 ) ;
if ( ! V_46 ) {
V_19 -> V_31 = V_45 ;
V_19 -> V_36 = V_42 ;
V_19 -> V_37 = V_43 ;
V_19 -> V_38 = V_44 ;
}
return V_46 ;
}
static int
F_24 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
F_9 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_19 != V_19 )
continue;
F_9 (connector, &dev->mode_config.connector_list, head) {
if ( V_4 -> V_15 != V_15 )
continue;
V_4 -> V_15 = NULL ;
V_4 -> V_26 = V_27 ;
}
}
F_12 ( V_2 ) ;
return 0 ;
}
int F_25 ( struct V_58 * V_59 )
{
struct V_1 * V_2 ;
struct V_18 * V_60 ;
struct V_14 * V_61 , * V_62 , * V_15 ;
bool V_63 = false ;
bool V_64 = false ;
struct V_3 * V_65 , * V_4 ;
int V_66 = 0 , V_67 , V_68 = 0 ;
struct V_29 * V_30 ;
struct V_58 V_69 ;
int V_46 ;
int V_70 ;
F_20 ( L_6 ) ;
F_26 ( ! V_59 ) ;
F_26 ( ! V_59 -> V_19 ) ;
F_26 ( ! V_59 -> V_19 -> V_22 ) ;
F_26 ( ! V_59 -> V_36 && V_59 -> V_33 ) ;
F_26 ( V_59 -> V_33 && V_59 -> V_71 == 0 ) ;
V_30 = V_59 -> V_19 -> V_22 ;
if ( ! V_59 -> V_36 )
V_59 -> V_33 = NULL ;
if ( V_59 -> V_33 ) {
F_20 ( L_7 ,
V_59 -> V_19 -> V_49 . V_50 , V_59 -> V_33 -> V_49 . V_50 ,
( int ) V_59 -> V_71 , V_59 -> V_37 , V_59 -> V_38 ) ;
} else {
F_20 ( L_8 , V_59 -> V_19 -> V_49 . V_50 ) ;
return F_24 ( V_59 -> V_19 ) ;
}
V_2 = V_59 -> V_19 -> V_2 ;
F_13 ( V_2 ) ;
V_61 = F_27 ( V_2 -> V_12 . V_72 *
sizeof( struct V_14 ) , V_73 ) ;
if ( ! V_61 )
return - V_74 ;
V_65 = F_27 ( V_2 -> V_12 . V_75 *
sizeof( struct V_3 ) , V_73 ) ;
if ( ! V_65 ) {
F_28 ( V_61 ) ;
return - V_74 ;
}
V_66 = 0 ;
F_9 (encoder, &dev->mode_config.encoder_list, head) {
V_61 [ V_66 ++ ] = * V_15 ;
}
V_66 = 0 ;
F_9 (connector, &dev->mode_config.connector_list, head) {
V_65 [ V_66 ++ ] = * V_4 ;
}
V_69 . V_19 = V_59 -> V_19 ;
V_69 . V_36 = & V_59 -> V_19 -> V_36 ;
V_69 . V_37 = V_59 -> V_19 -> V_37 ;
V_69 . V_38 = V_59 -> V_19 -> V_38 ;
V_69 . V_33 = V_59 -> V_19 -> V_32 -> V_33 ;
if ( V_59 -> V_19 -> V_32 -> V_33 != V_59 -> V_33 ) {
if ( V_59 -> V_19 -> V_32 -> V_33 == NULL ) {
F_20 ( L_9 ) ;
V_63 = true ;
} else if ( V_59 -> V_33 == NULL ) {
V_63 = true ;
} else if ( V_59 -> V_33 -> V_76 !=
V_59 -> V_19 -> V_32 -> V_33 -> V_76 ) {
V_63 = true ;
} else
V_64 = true ;
}
if ( V_59 -> V_37 != V_59 -> V_19 -> V_37 || V_59 -> V_38 != V_59 -> V_19 -> V_38 )
V_64 = true ;
if ( V_59 -> V_36 && ! F_29 ( V_59 -> V_36 , & V_59 -> V_19 -> V_36 ) ) {
F_20 ( L_10 ) ;
F_30 ( & V_59 -> V_19 -> V_36 ) ;
F_30 ( V_59 -> V_36 ) ;
V_63 = true ;
}
V_66 = 0 ;
F_9 (connector, &dev->mode_config.connector_list, head) {
struct V_77 * V_78 =
V_4 -> V_22 ;
V_62 = V_4 -> V_15 ;
for ( V_67 = 0 ; V_67 < V_59 -> V_71 ; V_67 ++ ) {
if ( V_59 -> V_79 [ V_67 ] == V_4 ) {
V_62 = V_78 -> V_80 ( V_4 ) ;
if ( V_62 == NULL )
V_68 = 1 ;
if ( V_4 -> V_26 != V_81 ) {
F_20 ( L_11 ) ;
V_63 = true ;
}
break;
}
}
if ( V_62 != V_4 -> V_15 ) {
F_20 ( L_12 ) ;
V_63 = true ;
if ( V_4 -> V_15 )
V_4 -> V_15 -> V_19 = NULL ;
V_4 -> V_15 = V_62 ;
}
}
if ( V_68 ) {
V_46 = - V_82 ;
goto V_68;
}
V_66 = 0 ;
F_9 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_15 )
continue;
if ( V_4 -> V_15 -> V_19 == V_59 -> V_19 )
V_60 = NULL ;
else
V_60 = V_4 -> V_15 -> V_19 ;
for ( V_67 = 0 ; V_67 < V_59 -> V_71 ; V_67 ++ ) {
if ( V_59 -> V_79 [ V_67 ] == V_4 )
V_60 = V_59 -> V_19 ;
}
if ( V_60 &&
! F_31 ( V_4 -> V_15 , V_60 ) ) {
V_46 = - V_82 ;
goto V_68;
}
if ( V_60 != V_4 -> V_15 -> V_19 ) {
F_20 ( L_13 ) ;
V_63 = true ;
V_4 -> V_15 -> V_19 = V_60 ;
}
if ( V_60 ) {
F_20 ( L_14 ,
V_4 -> V_49 . V_50 , F_32 ( V_4 ) ,
V_60 -> V_49 . V_50 ) ;
} else {
F_20 ( L_15 ,
V_4 -> V_49 . V_50 , F_32 ( V_4 ) ) ;
}
}
if ( V_64 && ! V_30 -> V_83 )
V_63 = true ;
if ( V_63 ) {
if ( F_10 ( V_59 -> V_19 ) ) {
F_20 ( L_16
L_17 ) ;
F_30 ( V_59 -> V_36 ) ;
V_59 -> V_19 -> V_32 -> V_33 = V_59 -> V_33 ;
if ( ! F_18 ( V_59 -> V_19 , V_59 -> V_36 ,
V_59 -> V_37 , V_59 -> V_38 ,
V_69 . V_33 ) ) {
F_33 ( L_18 ,
V_59 -> V_19 -> V_49 . V_50 ) ;
V_59 -> V_19 -> V_32 -> V_33 = V_69 . V_33 ;
V_46 = - V_82 ;
goto V_68;
}
F_20 ( L_19 ) ;
for ( V_70 = 0 ; V_70 < V_59 -> V_71 ; V_70 ++ ) {
F_20 ( L_20 , V_59 -> V_79 [ V_70 ] -> V_49 . V_50 ,
F_32 ( V_59 -> V_79 [ V_70 ] ) ) ;
V_59 -> V_79 [ V_70 ] -> V_24 -> V_26 ( V_59 -> V_79 [ V_70 ] , V_81 ) ;
}
}
F_12 ( V_2 ) ;
} else if ( V_64 ) {
V_59 -> V_19 -> V_37 = V_59 -> V_37 ;
V_59 -> V_19 -> V_38 = V_59 -> V_38 ;
V_59 -> V_19 -> V_32 -> V_33 = V_59 -> V_33 ;
V_46 = V_30 -> V_83 ( V_59 -> V_19 ,
V_59 -> V_37 , V_59 -> V_38 , V_69 . V_33 ) ;
if ( V_46 != 0 ) {
V_59 -> V_19 -> V_37 = V_69 . V_37 ;
V_59 -> V_19 -> V_38 = V_69 . V_38 ;
V_59 -> V_19 -> V_32 -> V_33 = V_69 . V_33 ;
goto V_68;
}
}
F_28 ( V_65 ) ;
F_28 ( V_61 ) ;
return 0 ;
V_68:
V_66 = 0 ;
F_9 (encoder, &dev->mode_config.encoder_list, head) {
* V_15 = V_61 [ V_66 ++ ] ;
}
V_66 = 0 ;
F_9 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_65 [ V_66 ++ ] ;
}
if ( V_63 &&
! F_18 ( V_69 . V_19 , V_69 . V_36 , V_69 . V_37 ,
V_69 . V_38 , V_69 . V_33 ) )
F_33 ( L_21 ) ;
F_28 ( V_65 ) ;
F_28 ( V_61 ) ;
return V_46 ;
}
static int F_34 ( struct V_14 * V_15 )
{
int V_26 = V_27 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_9 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_15 == V_15 )
if ( V_4 -> V_26 < V_26 )
V_26 = V_4 -> V_26 ;
return V_26 ;
}
static void F_35 ( struct V_14 * V_15 , int V_36 )
{
struct V_84 * V_23 = V_15 -> V_23 ;
struct V_20 * V_21 ;
if ( V_23 ) {
if ( V_36 == V_81 )
V_23 -> V_24 -> V_55 ( V_23 ) ;
else
V_23 -> V_24 -> V_25 ( V_23 ) ;
}
V_21 = V_15 -> V_22 ;
if ( V_21 -> V_26 )
V_21 -> V_26 ( V_15 , V_36 ) ;
if ( V_23 ) {
if ( V_36 == V_81 )
V_23 -> V_24 -> V_56 ( V_23 ) ;
else
V_23 -> V_24 -> V_28 ( V_23 ) ;
}
}
static int F_36 ( struct V_18 * V_19 )
{
int V_26 = V_27 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_19 -> V_2 ;
F_9 (connector, &dev->mode_config.connector_list, head)
if ( V_4 -> V_15 && V_4 -> V_15 -> V_19 == V_19 )
if ( V_4 -> V_26 < V_26 )
V_26 = V_4 -> V_26 ;
return V_26 ;
}
void F_37 ( struct V_3 * V_4 , int V_36 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_18 * V_19 = V_15 ? V_15 -> V_19 : NULL ;
int V_85 , V_86 = V_27 ;
if ( V_36 == V_4 -> V_26 )
return;
V_85 = V_4 -> V_26 ;
V_4 -> V_26 = V_36 ;
if ( V_15 )
V_86 = F_34 ( V_15 ) ;
if ( V_36 < V_85 ) {
if ( V_19 ) {
struct V_29 * V_30 = V_19 -> V_22 ;
if ( V_30 -> V_26 )
(* V_30 -> V_26 ) ( V_19 ,
F_36 ( V_19 ) ) ;
}
if ( V_15 )
F_35 ( V_15 , V_86 ) ;
}
if ( V_36 > V_85 ) {
if ( V_15 )
F_35 ( V_15 , V_86 ) ;
if ( V_19 ) {
struct V_29 * V_30 = V_19 -> V_22 ;
if ( V_30 -> V_26 )
(* V_30 -> V_26 ) ( V_19 ,
F_36 ( V_19 ) ) ;
}
}
return;
}
void F_38 ( struct V_39 * V_33 ,
struct V_87 * V_88 )
{
int V_70 ;
V_33 -> V_89 = V_88 -> V_89 ;
V_33 -> V_90 = V_88 -> V_90 ;
for ( V_70 = 0 ; V_70 < 4 ; V_70 ++ ) {
V_33 -> V_91 [ V_70 ] = V_88 -> V_91 [ V_70 ] ;
V_33 -> V_92 [ V_70 ] = V_88 -> V_92 [ V_70 ] ;
}
F_39 ( V_88 -> V_76 , & V_33 -> V_93 ,
& V_33 -> V_94 ) ;
V_33 -> V_76 = V_88 -> V_76 ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_14 * V_15 ;
struct V_29 * V_30 ;
int V_86 ;
bool V_46 ;
F_15 ( V_2 ) ;
F_9 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_19 -> V_31 )
continue;
V_46 = F_18 ( V_19 , & V_19 -> V_36 ,
V_19 -> V_37 , V_19 -> V_38 , V_19 -> V_32 -> V_33 ) ;
if ( V_46 == false )
F_33 ( L_22 , V_19 ) ;
if ( F_36 ( V_19 ) ) {
F_9 (encoder, &dev->mode_config.encoder_list, head) {
if( V_15 -> V_19 != V_19 )
continue;
V_86 = F_34 (
V_15 ) ;
F_35 ( V_15 , V_86 ) ;
}
V_30 = V_19 -> V_22 ;
if ( V_30 -> V_26 )
(* V_30 -> V_26 ) ( V_19 ,
F_36 ( V_19 ) ) ;
}
}
F_12 ( V_2 ) ;
F_16 ( V_2 ) ;
}
