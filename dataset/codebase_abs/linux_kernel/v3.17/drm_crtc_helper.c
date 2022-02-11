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
struct V_21 * V_22 = V_15 -> V_23 ;
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
struct V_30 * V_31 = V_20 -> V_23 ;
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
struct V_21 * V_22 ;
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
struct V_36 * V_42 , V_43 ;
struct V_30 * V_31 = V_20 -> V_23 ;
struct V_21 * V_22 ;
int V_44 , V_45 ;
bool V_46 ;
struct V_14 * V_15 ;
bool V_47 = true ;
F_14 ( V_2 ) ;
V_46 = V_20 -> V_32 ;
V_20 -> V_32 = F_11 ( V_20 ) ;
if ( ! V_20 -> V_32 )
return true ;
V_42 = F_20 ( V_2 , V_37 ) ;
if ( ! V_42 ) {
V_20 -> V_32 = V_46 ;
return false ;
}
V_43 = V_20 -> V_37 ;
V_44 = V_20 -> V_38 ;
V_45 = V_20 -> V_39 ;
V_20 -> V_37 = * V_37 ;
V_20 -> V_38 = V_38 ;
V_20 -> V_39 = V_39 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
if ( V_15 -> V_24 && V_15 -> V_24 -> V_25 -> V_48 ) {
V_47 = V_15 -> V_24 -> V_25 -> V_48 (
V_15 -> V_24 , V_37 , V_42 ) ;
if ( ! V_47 ) {
F_21 ( L_1 ) ;
goto V_49;
}
}
V_22 = V_15 -> V_23 ;
if ( ! ( V_47 = V_22 -> V_48 ( V_15 , V_37 ,
V_42 ) ) ) {
F_21 ( L_2 ) ;
goto V_49;
}
}
if ( ! ( V_47 = V_31 -> V_48 ( V_20 , V_37 , V_42 ) ) ) {
F_21 ( L_3 ) ;
goto V_49;
}
F_21 ( L_4 , V_20 -> V_50 . V_51 ) ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_26 ( V_15 -> V_24 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_52 ( V_15 ) ;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_29 ( V_15 -> V_24 ) ;
}
F_18 ( V_2 ) ;
V_31 -> V_52 ( V_20 ) ;
V_47 = ! V_31 -> V_53 ( V_20 , V_37 , V_42 , V_38 , V_39 , V_41 ) ;
if ( ! V_47 )
goto V_49;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
F_21 ( L_5 ,
V_15 -> V_50 . V_51 , V_15 -> V_54 ,
V_37 -> V_50 . V_51 , V_37 -> V_54 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_53 ( V_15 , V_37 , V_42 ) ;
if ( V_15 -> V_24 && V_15 -> V_24 -> V_25 -> V_53 )
V_15 -> V_24 -> V_25 -> V_53 ( V_15 -> V_24 , V_37 ,
V_42 ) ;
}
V_31 -> V_55 ( V_20 ) ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_15 -> V_20 != V_20 )
continue;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_56 ( V_15 -> V_24 ) ;
V_22 = V_15 -> V_23 ;
V_22 -> V_55 ( V_15 ) ;
if ( V_15 -> V_24 )
V_15 -> V_24 -> V_25 -> V_57 ( V_15 -> V_24 ) ;
}
V_20 -> V_58 = * V_42 ;
F_22 ( V_20 , & V_20 -> V_58 ) ;
V_49:
F_23 ( V_2 , V_42 ) ;
if ( ! V_47 ) {
V_20 -> V_32 = V_46 ;
V_20 -> V_37 = V_43 ;
V_20 -> V_38 = V_44 ;
V_20 -> V_39 = V_45 ;
}
return V_47 ;
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
int F_25 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
struct V_19 * V_61 ;
struct V_14 * V_62 , * V_63 , * V_15 ;
bool V_64 = false ;
bool V_65 = false ;
struct V_3 * V_66 , * V_4 ;
int V_67 = 0 , V_68 , V_69 = 0 ;
struct V_30 * V_31 ;
struct V_59 V_70 ;
int V_47 ;
int V_71 ;
F_21 ( L_6 ) ;
F_26 ( ! V_60 ) ;
F_26 ( ! V_60 -> V_20 ) ;
F_26 ( ! V_60 -> V_20 -> V_23 ) ;
F_26 ( ! V_60 -> V_37 && V_60 -> V_34 ) ;
F_26 ( V_60 -> V_34 && V_60 -> V_72 == 0 ) ;
V_31 = V_60 -> V_20 -> V_23 ;
if ( ! V_60 -> V_37 )
V_60 -> V_34 = NULL ;
if ( V_60 -> V_34 ) {
F_21 ( L_7 ,
V_60 -> V_20 -> V_50 . V_51 , V_60 -> V_34 -> V_50 . V_51 ,
( int ) V_60 -> V_72 , V_60 -> V_38 , V_60 -> V_39 ) ;
} else {
F_21 ( L_8 , V_60 -> V_20 -> V_50 . V_51 ) ;
F_24 ( V_60 -> V_20 ) ;
return 0 ;
}
V_2 = V_60 -> V_20 -> V_2 ;
F_14 ( V_2 ) ;
V_62 = F_27 ( V_2 -> V_12 . V_73 *
sizeof( struct V_14 ) , V_74 ) ;
if ( ! V_62 )
return - V_75 ;
V_66 = F_27 ( V_2 -> V_12 . V_76 *
sizeof( struct V_3 ) , V_74 ) ;
if ( ! V_66 ) {
F_28 ( V_62 ) ;
return - V_75 ;
}
V_67 = 0 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
V_62 [ V_67 ++ ] = * V_15 ;
}
V_67 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
V_66 [ V_67 ++ ] = * V_4 ;
}
V_70 . V_20 = V_60 -> V_20 ;
V_70 . V_37 = & V_60 -> V_20 -> V_37 ;
V_70 . V_38 = V_60 -> V_20 -> V_38 ;
V_70 . V_39 = V_60 -> V_20 -> V_39 ;
V_70 . V_34 = V_60 -> V_20 -> V_33 -> V_34 ;
if ( V_60 -> V_20 -> V_33 -> V_34 != V_60 -> V_34 ) {
if ( V_60 -> V_20 -> V_33 -> V_34 == NULL ) {
F_21 ( L_9 ) ;
V_64 = true ;
} else if ( V_60 -> V_34 == NULL ) {
V_64 = true ;
} else if ( V_60 -> V_34 -> V_77 !=
V_60 -> V_20 -> V_33 -> V_34 -> V_77 ) {
V_64 = true ;
} else
V_65 = true ;
}
if ( V_60 -> V_38 != V_60 -> V_20 -> V_38 || V_60 -> V_39 != V_60 -> V_20 -> V_39 )
V_65 = true ;
if ( V_60 -> V_37 && ! F_29 ( V_60 -> V_37 , & V_60 -> V_20 -> V_37 ) ) {
F_21 ( L_10 ) ;
F_30 ( & V_60 -> V_20 -> V_37 ) ;
F_30 ( V_60 -> V_37 ) ;
V_64 = true ;
}
V_67 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
struct V_78 * V_79 =
V_4 -> V_23 ;
V_63 = V_4 -> V_15 ;
for ( V_68 = 0 ; V_68 < V_60 -> V_72 ; V_68 ++ ) {
if ( V_60 -> V_80 [ V_68 ] == V_4 ) {
V_63 = V_79 -> V_81 ( V_4 ) ;
if ( V_63 == NULL )
V_69 = 1 ;
if ( V_4 -> V_27 != V_82 ) {
F_21 ( L_11 ) ;
V_64 = true ;
}
break;
}
}
if ( V_63 != V_4 -> V_15 ) {
F_21 ( L_12 ) ;
V_64 = true ;
if ( V_4 -> V_15 )
V_4 -> V_15 -> V_20 = NULL ;
V_4 -> V_15 = V_63 ;
}
}
if ( V_69 ) {
V_47 = - V_83 ;
goto V_69;
}
V_67 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
if ( ! V_4 -> V_15 )
continue;
if ( V_4 -> V_15 -> V_20 == V_60 -> V_20 )
V_61 = NULL ;
else
V_61 = V_4 -> V_15 -> V_20 ;
for ( V_68 = 0 ; V_68 < V_60 -> V_72 ; V_68 ++ ) {
if ( V_60 -> V_80 [ V_68 ] == V_4 )
V_61 = V_60 -> V_20 ;
}
if ( V_61 &&
! F_31 ( V_4 -> V_15 , V_61 ) ) {
V_47 = - V_83 ;
goto V_69;
}
if ( V_61 != V_4 -> V_15 -> V_20 ) {
F_21 ( L_13 ) ;
V_64 = true ;
V_4 -> V_15 -> V_20 = V_61 ;
}
if ( V_61 ) {
F_21 ( L_14 ,
V_4 -> V_50 . V_51 , V_4 -> V_54 ,
V_61 -> V_50 . V_51 ) ;
} else {
F_21 ( L_15 ,
V_4 -> V_50 . V_51 , V_4 -> V_54 ) ;
}
}
if ( V_65 && ! V_31 -> V_84 )
V_64 = true ;
if ( V_64 ) {
if ( F_11 ( V_60 -> V_20 ) ) {
F_21 ( L_16
L_17 ) ;
F_30 ( V_60 -> V_37 ) ;
V_60 -> V_20 -> V_33 -> V_34 = V_60 -> V_34 ;
if ( ! F_19 ( V_60 -> V_20 , V_60 -> V_37 ,
V_60 -> V_38 , V_60 -> V_39 ,
V_70 . V_34 ) ) {
F_32 ( L_18 ,
V_60 -> V_20 -> V_50 . V_51 ) ;
V_60 -> V_20 -> V_33 -> V_34 = V_70 . V_34 ;
V_47 = - V_83 ;
goto V_69;
}
F_21 ( L_19 ) ;
for ( V_71 = 0 ; V_71 < V_60 -> V_72 ; V_71 ++ ) {
F_21 ( L_20 , V_60 -> V_80 [ V_71 ] -> V_50 . V_51 ,
V_60 -> V_80 [ V_71 ] -> V_54 ) ;
V_60 -> V_80 [ V_71 ] -> V_25 -> V_27 ( V_60 -> V_80 [ V_71 ] , V_82 ) ;
}
}
F_13 ( V_2 ) ;
} else if ( V_65 ) {
V_60 -> V_20 -> V_38 = V_60 -> V_38 ;
V_60 -> V_20 -> V_39 = V_60 -> V_39 ;
V_60 -> V_20 -> V_33 -> V_34 = V_60 -> V_34 ;
V_47 = V_31 -> V_84 ( V_60 -> V_20 ,
V_60 -> V_38 , V_60 -> V_39 , V_70 . V_34 ) ;
if ( V_47 != 0 ) {
V_60 -> V_20 -> V_38 = V_70 . V_38 ;
V_60 -> V_20 -> V_39 = V_70 . V_39 ;
V_60 -> V_20 -> V_33 -> V_34 = V_70 . V_34 ;
goto V_69;
}
}
F_28 ( V_66 ) ;
F_28 ( V_62 ) ;
return 0 ;
V_69:
V_67 = 0 ;
F_10 (encoder, &dev->mode_config.encoder_list, head) {
* V_15 = V_62 [ V_67 ++ ] ;
}
V_67 = 0 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
* V_4 = V_66 [ V_67 ++ ] ;
}
if ( V_64 &&
! F_19 ( V_70 . V_20 , V_70 . V_37 , V_70 . V_38 ,
V_70 . V_39 , V_70 . V_34 ) )
F_32 ( L_21 ) ;
F_28 ( V_66 ) ;
F_28 ( V_62 ) ;
return V_47 ;
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
struct V_85 * V_24 = V_15 -> V_24 ;
struct V_21 * V_22 ;
if ( V_24 ) {
if ( V_37 == V_82 )
V_24 -> V_25 -> V_56 ( V_24 ) ;
else
V_24 -> V_25 -> V_26 ( V_24 ) ;
}
V_22 = V_15 -> V_23 ;
if ( V_22 -> V_27 )
V_22 -> V_27 ( V_15 , V_37 ) ;
if ( V_24 ) {
if ( V_37 == V_82 )
V_24 -> V_25 -> V_57 ( V_24 ) ;
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
int V_86 , V_87 = V_28 ;
if ( V_37 == V_4 -> V_27 )
return;
V_86 = V_4 -> V_27 ;
V_4 -> V_27 = V_37 ;
if ( V_15 )
V_87 = F_33 ( V_15 ) ;
if ( V_37 < V_86 ) {
if ( V_20 ) {
struct V_30 * V_31 = V_20 -> V_23 ;
if ( V_31 -> V_27 )
(* V_31 -> V_27 ) ( V_20 ,
F_35 ( V_20 ) ) ;
}
if ( V_15 )
F_34 ( V_15 , V_87 ) ;
}
if ( V_37 > V_86 ) {
if ( V_15 )
F_34 ( V_15 , V_87 ) ;
if ( V_20 ) {
struct V_30 * V_31 = V_20 -> V_23 ;
if ( V_31 -> V_27 )
(* V_31 -> V_27 ) ( V_20 ,
F_35 ( V_20 ) ) ;
}
}
return;
}
void F_37 ( struct V_40 * V_34 ,
struct V_88 * V_89 )
{
int V_71 ;
V_34 -> V_90 = V_89 -> V_90 ;
V_34 -> V_91 = V_89 -> V_91 ;
for ( V_71 = 0 ; V_71 < 4 ; V_71 ++ ) {
V_34 -> V_92 [ V_71 ] = V_89 -> V_92 [ V_71 ] ;
V_34 -> V_93 [ V_71 ] = V_89 -> V_93 [ V_71 ] ;
}
F_38 ( V_89 -> V_77 , & V_34 -> V_94 ,
& V_34 -> V_95 ) ;
V_34 -> V_77 = V_89 -> V_77 ;
V_34 -> V_96 = V_89 -> V_96 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_14 * V_15 ;
struct V_30 * V_31 ;
int V_87 ;
bool V_47 ;
F_16 ( V_2 ) ;
F_10 (crtc, &dev->mode_config.crtc_list, head) {
if ( ! V_20 -> V_32 )
continue;
V_47 = F_19 ( V_20 , & V_20 -> V_37 ,
V_20 -> V_38 , V_20 -> V_39 , V_20 -> V_33 -> V_34 ) ;
if ( V_47 == false )
F_32 ( L_22 , V_20 ) ;
if ( F_35 ( V_20 ) ) {
F_10 (encoder, &dev->mode_config.encoder_list, head) {
if( V_15 -> V_20 != V_20 )
continue;
V_87 = F_33 (
V_15 ) ;
F_34 ( V_15 , V_87 ) ;
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
