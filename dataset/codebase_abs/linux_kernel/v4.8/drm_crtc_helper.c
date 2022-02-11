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
F_10 (connector, dev)
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
F_12 (encoder, dev)
if ( V_15 -> V_20 == V_20 && F_6 ( V_15 ) )
return true ;
return false ;
}
static void
F_13 ( struct V_14 * V_15 )
{
const struct V_21 * V_22 = V_15 -> V_23 ;
if ( ! V_22 )
return;
F_14 ( V_15 -> V_24 ) ;
if ( V_22 -> V_25 )
(* V_22 -> V_25 )( V_15 ) ;
else if ( V_22 -> V_26 )
(* V_22 -> V_26 )( V_15 , V_27 ) ;
F_15 ( V_15 -> V_24 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_19 * V_20 ;
F_17 ( V_2 ) ;
F_12 (encoder, dev) {
if ( ! F_6 ( V_15 ) ) {
F_13 ( V_15 ) ;
V_15 -> V_20 = NULL ;
}
}
F_18 (crtc, dev) {
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
void F_19 ( struct V_1 * V_2 )
{
if ( F_20 ( V_2 , V_33 ) )
F_21 ( L_1 ) ;
F_22 ( V_2 ) ;
F_16 ( V_2 ) ;
F_23 ( V_2 ) ;
}
static void
F_24 ( struct V_1 * V_2 )
{
const struct V_21 * V_22 ;
struct V_14 * V_15 ;
F_12 (encoder, dev) {
V_22 = V_15 -> V_23 ;
if ( ! V_22 )
continue;
if ( V_15 -> V_20 == NULL )
F_13 ( V_15 ) ;
if ( V_22 -> V_34 &&
V_15 -> V_20 != (* V_22 -> V_34 )( V_15 ) )
F_13 ( V_15 ) ;
}
}
bool F_25 ( struct V_19 * V_20 ,
struct V_35 * V_36 ,
int V_37 , int V_38 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_35 * V_41 , V_42 , V_43 ;
const struct V_28 * V_29 = V_20 -> V_23 ;
const struct V_21 * V_22 ;
int V_44 , V_45 ;
bool V_46 ;
struct V_14 * V_15 ;
bool V_47 = true ;
F_17 ( V_2 ) ;
V_46 = V_20 -> V_30 ;
V_20 -> V_30 = F_11 ( V_20 ) ;
if ( ! V_20 -> V_30 )
return true ;
V_41 = F_26 ( V_2 , V_36 ) ;
if ( ! V_41 ) {
V_20 -> V_30 = V_46 ;
return false ;
}
V_42 = V_20 -> V_36 ;
V_43 = V_20 -> V_48 ;
V_44 = V_20 -> V_37 ;
V_45 = V_20 -> V_38 ;
V_20 -> V_36 = * V_36 ;
V_20 -> V_37 = V_37 ;
V_20 -> V_38 = V_38 ;
F_12 (encoder, dev) {
if ( V_15 -> V_20 != V_20 )
continue;
V_22 = V_15 -> V_23 ;
if ( ! V_22 )
continue;
V_47 = F_27 ( V_15 -> V_24 ,
V_36 , V_41 ) ;
if ( ! V_47 ) {
F_28 ( L_2 ) ;
goto V_49;
}
V_22 = V_15 -> V_23 ;
if ( V_22 -> V_50 ) {
if ( ! ( V_47 = V_22 -> V_50 ( V_15 , V_36 ,
V_41 ) ) ) {
F_28 ( L_3 ) ;
goto V_49;
}
}
}
if ( V_29 -> V_50 ) {
if ( ! ( V_47 = V_29 -> V_50 ( V_20 , V_36 ,
V_41 ) ) ) {
F_28 ( L_4 ) ;
goto V_49;
}
}
F_28 ( L_5 , V_20 -> V_51 . V_52 , V_20 -> V_53 ) ;
V_20 -> V_48 = * V_41 ;
F_12 (encoder, dev) {
if ( V_15 -> V_20 != V_20 )
continue;
V_22 = V_15 -> V_23 ;
if ( ! V_22 )
continue;
F_14 ( V_15 -> V_24 ) ;
if ( V_22 -> V_54 )
V_22 -> V_54 ( V_15 ) ;
F_15 ( V_15 -> V_24 ) ;
}
F_24 ( V_2 ) ;
V_29 -> V_54 ( V_20 ) ;
V_47 = ! V_29 -> V_55 ( V_20 , V_36 , V_41 , V_37 , V_38 , V_40 ) ;
if ( ! V_47 )
goto V_49;
F_12 (encoder, dev) {
if ( V_15 -> V_20 != V_20 )
continue;
V_22 = V_15 -> V_23 ;
if ( ! V_22 )
continue;
F_28 ( L_6 ,
V_15 -> V_51 . V_52 , V_15 -> V_53 ,
V_36 -> V_51 . V_52 , V_36 -> V_53 ) ;
if ( V_22 -> V_55 )
V_22 -> V_55 ( V_15 , V_36 , V_41 ) ;
F_29 ( V_15 -> V_24 , V_36 , V_41 ) ;
}
V_29 -> V_56 ( V_20 ) ;
F_12 (encoder, dev) {
if ( V_15 -> V_20 != V_20 )
continue;
V_22 = V_15 -> V_23 ;
if ( ! V_22 )
continue;
F_30 ( V_15 -> V_24 ) ;
if ( V_22 -> V_56 )
V_22 -> V_56 ( V_15 ) ;
F_31 ( V_15 -> V_24 ) ;
}
F_32 ( V_20 , & V_20 -> V_48 ) ;
V_49:
F_33 ( V_2 , V_41 ) ;
if ( ! V_47 ) {
V_20 -> V_30 = V_46 ;
V_20 -> V_36 = V_42 ;
V_20 -> V_48 = V_43 ;
V_20 -> V_37 = V_44 ;
V_20 -> V_38 = V_45 ;
}
return V_47 ;
}
static void
F_34 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
F_12 (encoder, dev) {
if ( V_15 -> V_20 != V_20 )
continue;
F_10 (connector, dev) {
if ( V_4 -> V_15 != V_15 )
continue;
V_4 -> V_15 = NULL ;
V_4 -> V_26 = V_27 ;
F_35 ( V_4 ) ;
}
}
F_16 ( V_2 ) ;
}
int F_36 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_19 * * V_59 , * V_60 ;
struct V_14 * * V_61 , * V_62 , * V_15 ;
bool V_63 = false ;
bool V_64 = false ;
struct V_3 * V_4 ;
int V_65 = 0 , V_66 , V_67 = 0 ;
const struct V_28 * V_29 ;
struct V_57 V_68 ;
int V_47 ;
int V_69 ;
F_28 ( L_7 ) ;
F_37 ( ! V_58 ) ;
F_37 ( ! V_58 -> V_20 ) ;
F_37 ( ! V_58 -> V_20 -> V_23 ) ;
F_37 ( ! V_58 -> V_36 && V_58 -> V_32 ) ;
F_37 ( V_58 -> V_32 && V_58 -> V_70 == 0 ) ;
V_29 = V_58 -> V_20 -> V_23 ;
if ( ! V_58 -> V_36 )
V_58 -> V_32 = NULL ;
if ( V_58 -> V_32 ) {
F_28 ( L_8 ,
V_58 -> V_20 -> V_51 . V_52 , V_58 -> V_20 -> V_53 ,
V_58 -> V_32 -> V_51 . V_52 ,
( int ) V_58 -> V_70 , V_58 -> V_37 , V_58 -> V_38 ) ;
} else {
F_28 ( L_9 ,
V_58 -> V_20 -> V_51 . V_52 , V_58 -> V_20 -> V_53 ) ;
F_34 ( V_58 -> V_20 ) ;
return 0 ;
}
V_2 = V_58 -> V_20 -> V_2 ;
F_17 ( V_2 ) ;
V_59 = F_38 ( V_2 -> V_12 . V_71 *
sizeof( struct V_19 * ) , V_72 ) ;
if ( ! V_59 )
return - V_73 ;
V_61 = F_38 ( V_2 -> V_12 . V_74 *
sizeof( struct V_14 * ) , V_72 ) ;
if ( ! V_61 ) {
F_39 ( V_59 ) ;
return - V_73 ;
}
V_65 = 0 ;
F_12 (encoder, dev) {
V_59 [ V_65 ++ ] = V_15 -> V_20 ;
}
V_65 = 0 ;
F_10 (connector, dev) {
V_61 [ V_65 ++ ] = V_4 -> V_15 ;
}
V_68 . V_20 = V_58 -> V_20 ;
V_68 . V_36 = & V_58 -> V_20 -> V_36 ;
V_68 . V_37 = V_58 -> V_20 -> V_37 ;
V_68 . V_38 = V_58 -> V_20 -> V_38 ;
V_68 . V_32 = V_58 -> V_20 -> V_31 -> V_32 ;
if ( V_58 -> V_20 -> V_31 -> V_32 != V_58 -> V_32 ) {
if ( V_58 -> V_20 -> V_31 -> V_32 == NULL ) {
F_28 ( L_10 ) ;
V_63 = true ;
} else if ( V_58 -> V_32 -> V_75 !=
V_58 -> V_20 -> V_31 -> V_32 -> V_75 ) {
V_63 = true ;
} else
V_64 = true ;
}
if ( V_58 -> V_37 != V_58 -> V_20 -> V_37 || V_58 -> V_38 != V_58 -> V_20 -> V_38 )
V_64 = true ;
if ( ! F_40 ( V_58 -> V_36 , & V_58 -> V_20 -> V_36 ) ) {
F_28 ( L_11 ) ;
F_41 ( & V_58 -> V_20 -> V_36 ) ;
F_41 ( V_58 -> V_36 ) ;
V_63 = true ;
}
for ( V_66 = 0 ; V_66 < V_58 -> V_70 ; V_66 ++ ) {
if ( V_58 -> V_76 [ V_66 ] -> V_15 )
continue;
F_42 ( V_58 -> V_76 [ V_66 ] ) ;
}
V_65 = 0 ;
F_10 (connector, dev) {
const struct V_77 * V_78 =
V_4 -> V_23 ;
V_62 = V_4 -> V_15 ;
for ( V_66 = 0 ; V_66 < V_58 -> V_70 ; V_66 ++ ) {
if ( V_58 -> V_76 [ V_66 ] == V_4 ) {
V_62 = V_78 -> V_79 ( V_4 ) ;
if ( V_62 == NULL )
V_67 = 1 ;
if ( V_4 -> V_26 != V_80 ) {
F_28 ( L_12 ) ;
V_63 = true ;
}
break;
}
}
if ( V_62 != V_4 -> V_15 ) {
F_28 ( L_13 ) ;
V_63 = true ;
if ( V_4 -> V_15 )
V_4 -> V_15 -> V_20 = NULL ;
V_4 -> V_15 = V_62 ;
}
}
if ( V_67 ) {
V_47 = - V_81 ;
goto V_67;
}
V_65 = 0 ;
F_10 (connector, dev) {
if ( ! V_4 -> V_15 )
continue;
if ( V_4 -> V_15 -> V_20 == V_58 -> V_20 )
V_60 = NULL ;
else
V_60 = V_4 -> V_15 -> V_20 ;
for ( V_66 = 0 ; V_66 < V_58 -> V_70 ; V_66 ++ ) {
if ( V_58 -> V_76 [ V_66 ] == V_4 )
V_60 = V_58 -> V_20 ;
}
if ( V_60 &&
! F_43 ( V_4 -> V_15 , V_60 ) ) {
V_47 = - V_81 ;
goto V_67;
}
if ( V_60 != V_4 -> V_15 -> V_20 ) {
F_28 ( L_14 ) ;
V_63 = true ;
V_4 -> V_15 -> V_20 = V_60 ;
}
if ( V_60 ) {
F_28 ( L_15 ,
V_4 -> V_51 . V_52 , V_4 -> V_53 ,
V_60 -> V_51 . V_52 , V_60 -> V_53 ) ;
} else {
F_28 ( L_16 ,
V_4 -> V_51 . V_52 , V_4 -> V_53 ) ;
}
}
if ( V_64 && ! V_29 -> V_82 )
V_63 = true ;
if ( V_63 ) {
if ( F_11 ( V_58 -> V_20 ) ) {
F_28 ( L_17
L_18 ) ;
F_41 ( V_58 -> V_36 ) ;
V_58 -> V_20 -> V_31 -> V_32 = V_58 -> V_32 ;
if ( ! F_25 ( V_58 -> V_20 , V_58 -> V_36 ,
V_58 -> V_37 , V_58 -> V_38 ,
V_68 . V_32 ) ) {
F_21 ( L_19 ,
V_58 -> V_20 -> V_51 . V_52 , V_58 -> V_20 -> V_53 ) ;
V_58 -> V_20 -> V_31 -> V_32 = V_68 . V_32 ;
V_47 = - V_81 ;
goto V_67;
}
F_28 ( L_20 ) ;
for ( V_69 = 0 ; V_69 < V_58 -> V_70 ; V_69 ++ ) {
F_28 ( L_21 , V_58 -> V_76 [ V_69 ] -> V_51 . V_52 ,
V_58 -> V_76 [ V_69 ] -> V_53 ) ;
V_58 -> V_76 [ V_69 ] -> V_83 -> V_26 ( V_58 -> V_76 [ V_69 ] , V_80 ) ;
}
}
F_16 ( V_2 ) ;
} else if ( V_64 ) {
V_58 -> V_20 -> V_37 = V_58 -> V_37 ;
V_58 -> V_20 -> V_38 = V_58 -> V_38 ;
V_58 -> V_20 -> V_31 -> V_32 = V_58 -> V_32 ;
V_47 = V_29 -> V_82 ( V_58 -> V_20 ,
V_58 -> V_37 , V_58 -> V_38 , V_68 . V_32 ) ;
if ( V_47 != 0 ) {
V_58 -> V_20 -> V_37 = V_68 . V_37 ;
V_58 -> V_20 -> V_38 = V_68 . V_38 ;
V_58 -> V_20 -> V_31 -> V_32 = V_68 . V_32 ;
goto V_67;
}
}
F_39 ( V_61 ) ;
F_39 ( V_59 ) ;
return 0 ;
V_67:
V_65 = 0 ;
F_12 (encoder, dev) {
V_15 -> V_20 = V_59 [ V_65 ++ ] ;
}
V_65 = 0 ;
F_10 (connector, dev) {
V_4 -> V_15 = V_61 [ V_65 ++ ] ;
}
for ( V_66 = 0 ; V_66 < V_58 -> V_70 ; V_66 ++ ) {
if ( V_58 -> V_76 [ V_66 ] -> V_15 )
continue;
F_35 ( V_58 -> V_76 [ V_66 ] ) ;
}
if ( V_63 &&
! F_25 ( V_68 . V_20 , V_68 . V_36 , V_68 . V_37 ,
V_68 . V_38 , V_68 . V_32 ) )
F_21 ( L_22 ) ;
F_39 ( V_61 ) ;
F_39 ( V_59 ) ;
return V_47 ;
}
static int F_44 ( struct V_14 * V_15 )
{
int V_26 = V_27 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_10 (connector, dev)
if ( V_4 -> V_15 == V_15 )
if ( V_4 -> V_26 < V_26 )
V_26 = V_4 -> V_26 ;
return V_26 ;
}
static void F_45 ( struct V_14 * V_15 , int V_36 )
{
struct V_84 * V_24 = V_15 -> V_24 ;
const struct V_21 * V_22 ;
V_22 = V_15 -> V_23 ;
if ( ! V_22 )
return;
if ( V_36 == V_80 )
F_30 ( V_24 ) ;
else
F_14 ( V_24 ) ;
if ( V_22 -> V_26 )
V_22 -> V_26 ( V_15 , V_36 ) ;
if ( V_36 == V_80 )
F_31 ( V_24 ) ;
else
F_15 ( V_24 ) ;
}
static int F_46 ( struct V_19 * V_20 )
{
int V_26 = V_27 ;
struct V_3 * V_4 ;
struct V_1 * V_2 = V_20 -> V_2 ;
F_10 (connector, dev)
if ( V_4 -> V_15 && V_4 -> V_15 -> V_20 == V_20 )
if ( V_4 -> V_26 < V_26 )
V_26 = V_4 -> V_26 ;
return V_26 ;
}
int F_47 ( struct V_3 * V_4 , int V_36 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_19 * V_20 = V_15 ? V_15 -> V_20 : NULL ;
int V_85 , V_86 = V_27 ;
if ( V_36 == V_4 -> V_26 )
return 0 ;
V_85 = V_4 -> V_26 ;
V_4 -> V_26 = V_36 ;
if ( V_15 )
V_86 = F_44 ( V_15 ) ;
if ( V_36 < V_85 ) {
if ( V_20 ) {
const struct V_28 * V_29 = V_20 -> V_23 ;
if ( V_29 -> V_26 )
(* V_29 -> V_26 ) ( V_20 ,
F_46 ( V_20 ) ) ;
}
if ( V_15 )
F_45 ( V_15 , V_86 ) ;
}
if ( V_36 > V_85 ) {
if ( V_15 )
F_45 ( V_15 , V_86 ) ;
if ( V_20 ) {
const struct V_28 * V_29 = V_20 -> V_23 ;
if ( V_29 -> V_26 )
(* V_29 -> V_26 ) ( V_20 ,
F_46 ( V_20 ) ) ;
}
}
return 0 ;
}
void F_48 ( struct V_39 * V_32 ,
const struct V_87 * V_88 )
{
int V_69 ;
V_32 -> V_89 = V_88 -> V_89 ;
V_32 -> V_90 = V_88 -> V_90 ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
V_32 -> V_91 [ V_69 ] = V_88 -> V_91 [ V_69 ] ;
V_32 -> V_92 [ V_69 ] = V_88 -> V_92 [ V_69 ] ;
V_32 -> V_93 [ V_69 ] = V_88 -> V_93 [ V_69 ] ;
}
F_49 ( V_88 -> V_75 , & V_32 -> V_94 ,
& V_32 -> V_95 ) ;
V_32 -> V_75 = V_88 -> V_75 ;
V_32 -> V_96 = V_88 -> V_96 ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_14 * V_15 ;
const struct V_28 * V_29 ;
int V_86 ;
bool V_47 ;
F_22 ( V_2 ) ;
F_18 (crtc, dev) {
if ( ! V_20 -> V_30 )
continue;
V_47 = F_25 ( V_20 , & V_20 -> V_36 ,
V_20 -> V_37 , V_20 -> V_38 , V_20 -> V_31 -> V_32 ) ;
if ( V_47 == false )
F_21 ( L_23 , V_20 ) ;
if ( F_46 ( V_20 ) ) {
F_12 (encoder, dev) {
if( V_15 -> V_20 != V_20 )
continue;
V_86 = F_44 (
V_15 ) ;
F_45 ( V_15 , V_86 ) ;
}
V_29 = V_20 -> V_23 ;
if ( V_29 -> V_26 )
(* V_29 -> V_26 ) ( V_20 ,
F_46 ( V_20 ) ) ;
}
}
F_16 ( V_2 ) ;
F_23 ( V_2 ) ;
}
int F_51 ( struct V_19 * V_20 , struct V_35 * V_36 ,
struct V_35 * V_41 , int V_37 , int V_38 ,
struct V_39 * V_40 )
{
struct V_97 * V_98 ;
const struct V_28 * V_29 = V_20 -> V_23 ;
int V_47 ;
if ( V_20 -> V_83 -> V_99 )
V_98 = V_20 -> V_83 -> V_99 ( V_20 ) ;
else {
if ( ! V_20 -> V_100 )
F_52 ( V_20 ) ;
V_98 = F_53 ( V_20 ) ;
}
if ( ! V_98 )
return - V_73 ;
V_98 -> V_101 = true ;
V_98 -> V_63 = true ;
V_47 = F_54 ( V_98 , V_36 ) ;
if ( V_47 )
goto V_102;
F_55 ( & V_98 -> V_41 , V_41 ) ;
if ( V_29 -> V_103 ) {
V_47 = V_29 -> V_103 ( V_20 , V_98 ) ;
if ( V_47 )
goto V_102;
}
F_56 ( V_20 -> V_100 , V_98 ) ;
V_29 -> V_104 ( V_20 ) ;
V_47 = F_57 ( V_20 , V_37 , V_38 , V_40 ) ;
V_102:
if ( V_98 ) {
if ( V_20 -> V_83 -> V_105 )
V_20 -> V_83 -> V_105 ( V_20 , V_98 ) ;
else
F_58 ( V_20 , V_98 ) ;
}
return V_47 ;
}
int F_57 ( struct V_19 * V_20 , int V_37 , int V_38 ,
struct V_39 * V_40 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 = V_20 -> V_31 ;
if ( V_109 -> V_83 -> V_99 )
V_107 = V_109 -> V_83 -> V_99 ( V_109 ) ;
else {
if ( ! V_109 -> V_100 )
F_59 ( V_109 ) ;
V_107 = F_60 ( V_109 ) ;
}
if ( ! V_107 )
return - V_73 ;
V_107 -> V_109 = V_109 ;
V_107 -> V_20 = V_20 ;
F_61 ( V_107 , V_20 -> V_31 -> V_32 ) ;
V_107 -> V_110 = 0 ;
V_107 -> V_111 = 0 ;
V_107 -> V_112 = V_20 -> V_36 . V_113 ;
V_107 -> V_114 = V_20 -> V_36 . V_115 ;
V_107 -> V_116 = V_37 << 16 ;
V_107 -> V_117 = V_38 << 16 ;
V_107 -> V_118 = V_20 -> V_36 . V_113 << 16 ;
V_107 -> V_119 = V_20 -> V_36 . V_115 << 16 ;
return F_62 ( V_109 , V_107 , V_40 ) ;
}
