bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! V_7 ) {
F_2 ( ! F_3 ( & V_6 -> V_8 . V_9 ) ) ;
F_2 ( ! F_4 ( & V_6 -> V_8 . V_10 ) ) ;
}
F_5 (connector, dev)
if ( V_4 -> V_2 == V_2 )
return true ;
return false ;
}
bool F_6 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = V_12 -> V_6 ;
if ( ! V_7 )
F_2 ( ! F_3 ( & V_6 -> V_8 . V_9 ) ) ;
F_7 (encoder, dev)
if ( V_2 -> V_12 == V_12 && F_1 ( V_2 ) )
return true ;
return false ;
}
static void
F_8 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = V_2 -> V_15 ;
if ( ! V_14 )
return;
F_9 ( V_2 -> V_16 ) ;
if ( V_14 -> V_17 )
(* V_14 -> V_17 )( V_2 ) ;
else if ( V_14 -> V_18 )
(* V_14 -> V_18 )( V_2 , V_19 ) ;
F_10 ( V_2 -> V_16 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_12 ( V_6 ) ;
F_7 (encoder, dev) {
if ( ! F_1 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_2 -> V_12 = NULL ;
}
}
F_13 (crtc, dev) {
const struct V_20 * V_21 = V_12 -> V_15 ;
V_12 -> V_22 = F_6 ( V_12 ) ;
if ( ! V_12 -> V_22 ) {
if ( V_21 -> V_17 )
(* V_21 -> V_17 )( V_12 ) ;
else
(* V_21 -> V_18 )( V_12 , V_19 ) ;
V_12 -> V_23 -> V_24 = NULL ;
}
}
}
void F_14 ( struct V_5 * V_6 )
{
if ( F_15 ( V_6 , V_25 ) )
F_16 ( L_1 ) ;
F_17 ( V_6 ) ;
F_11 ( V_6 ) ;
F_18 ( V_6 ) ;
}
static void
F_19 ( struct V_5 * V_6 )
{
const struct V_13 * V_14 ;
struct V_1 * V_2 ;
F_7 (encoder, dev) {
V_14 = V_2 -> V_15 ;
if ( ! V_14 )
continue;
if ( V_2 -> V_12 == NULL )
F_8 ( V_2 ) ;
if ( V_14 -> V_26 &&
V_2 -> V_12 != (* V_14 -> V_26 )( V_2 ) )
F_8 ( V_2 ) ;
}
}
bool F_20 ( struct V_11 * V_12 ,
struct V_27 * V_28 ,
int V_29 , int V_30 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = V_12 -> V_6 ;
struct V_27 * V_33 , V_34 , V_35 ;
const struct V_20 * V_21 = V_12 -> V_15 ;
const struct V_13 * V_14 ;
int V_36 , V_37 ;
bool V_38 ;
struct V_1 * V_2 ;
bool V_39 = true ;
F_12 ( V_6 ) ;
V_38 = V_12 -> V_22 ;
V_12 -> V_22 = F_6 ( V_12 ) ;
if ( ! V_12 -> V_22 )
return true ;
V_33 = F_21 ( V_6 , V_28 ) ;
if ( ! V_33 ) {
V_12 -> V_22 = V_38 ;
return false ;
}
V_34 = V_12 -> V_28 ;
V_35 = V_12 -> V_40 ;
V_36 = V_12 -> V_29 ;
V_37 = V_12 -> V_30 ;
V_12 -> V_28 = * V_28 ;
V_12 -> V_29 = V_29 ;
V_12 -> V_30 = V_30 ;
F_7 (encoder, dev) {
if ( V_2 -> V_12 != V_12 )
continue;
V_14 = V_2 -> V_15 ;
if ( ! V_14 )
continue;
V_39 = F_22 ( V_2 -> V_16 ,
V_28 , V_33 ) ;
if ( ! V_39 ) {
F_23 ( L_2 ) ;
goto V_41;
}
V_14 = V_2 -> V_15 ;
if ( V_14 -> V_42 ) {
if ( ! ( V_39 = V_14 -> V_42 ( V_2 , V_28 ,
V_33 ) ) ) {
F_23 ( L_3 ) ;
goto V_41;
}
}
}
if ( V_21 -> V_42 ) {
if ( ! ( V_39 = V_21 -> V_42 ( V_12 , V_28 ,
V_33 ) ) ) {
F_23 ( L_4 ) ;
goto V_41;
}
}
F_23 ( L_5 , V_12 -> V_43 . V_44 , V_12 -> V_45 ) ;
V_12 -> V_40 = * V_33 ;
F_7 (encoder, dev) {
if ( V_2 -> V_12 != V_12 )
continue;
V_14 = V_2 -> V_15 ;
if ( ! V_14 )
continue;
F_9 ( V_2 -> V_16 ) ;
if ( V_14 -> V_46 )
V_14 -> V_46 ( V_2 ) ;
F_10 ( V_2 -> V_16 ) ;
}
F_19 ( V_6 ) ;
V_21 -> V_46 ( V_12 ) ;
V_39 = ! V_21 -> V_47 ( V_12 , V_28 , V_33 , V_29 , V_30 , V_32 ) ;
if ( ! V_39 )
goto V_41;
F_7 (encoder, dev) {
if ( V_2 -> V_12 != V_12 )
continue;
V_14 = V_2 -> V_15 ;
if ( ! V_14 )
continue;
F_23 ( L_6 ,
V_2 -> V_43 . V_44 , V_2 -> V_45 ,
V_28 -> V_43 . V_44 , V_28 -> V_45 ) ;
if ( V_14 -> V_47 )
V_14 -> V_47 ( V_2 , V_28 , V_33 ) ;
F_24 ( V_2 -> V_16 , V_28 , V_33 ) ;
}
V_21 -> V_48 ( V_12 ) ;
F_7 (encoder, dev) {
if ( V_2 -> V_12 != V_12 )
continue;
V_14 = V_2 -> V_15 ;
if ( ! V_14 )
continue;
F_25 ( V_2 -> V_16 ) ;
if ( V_14 -> V_48 )
V_14 -> V_48 ( V_2 ) ;
F_26 ( V_2 -> V_16 ) ;
}
F_27 ( V_12 , & V_12 -> V_40 ) ;
V_41:
F_28 ( V_6 , V_33 ) ;
if ( ! V_39 ) {
V_12 -> V_22 = V_38 ;
V_12 -> V_28 = V_34 ;
V_12 -> V_40 = V_35 ;
V_12 -> V_29 = V_36 ;
V_12 -> V_30 = V_37 ;
}
return V_39 ;
}
static void
F_29 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_6 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
F_7 (encoder, dev) {
if ( V_2 -> V_12 != V_12 )
continue;
F_5 (connector, dev) {
if ( V_4 -> V_2 != V_2 )
continue;
V_4 -> V_2 = NULL ;
V_4 -> V_18 = V_19 ;
F_30 ( V_4 ) ;
}
}
F_11 ( V_6 ) ;
}
int F_31 ( struct V_49 * V_50 )
{
struct V_5 * V_6 ;
struct V_11 * * V_51 , * V_52 ;
struct V_1 * * V_53 , * V_54 , * V_2 ;
bool V_55 = false ;
bool V_56 = false ;
struct V_3 * V_4 ;
int V_57 = 0 , V_58 , V_59 = 0 ;
const struct V_20 * V_21 ;
struct V_49 V_60 ;
int V_39 ;
int V_61 ;
F_23 ( L_7 ) ;
F_32 ( ! V_50 ) ;
F_32 ( ! V_50 -> V_12 ) ;
F_32 ( ! V_50 -> V_12 -> V_15 ) ;
F_32 ( ! V_50 -> V_28 && V_50 -> V_24 ) ;
F_32 ( V_50 -> V_24 && V_50 -> V_62 == 0 ) ;
V_21 = V_50 -> V_12 -> V_15 ;
if ( ! V_50 -> V_28 )
V_50 -> V_24 = NULL ;
if ( V_50 -> V_24 ) {
F_23 ( L_8 ,
V_50 -> V_12 -> V_43 . V_44 , V_50 -> V_12 -> V_45 ,
V_50 -> V_24 -> V_43 . V_44 ,
( int ) V_50 -> V_62 , V_50 -> V_29 , V_50 -> V_30 ) ;
} else {
F_23 ( L_9 ,
V_50 -> V_12 -> V_43 . V_44 , V_50 -> V_12 -> V_45 ) ;
F_29 ( V_50 -> V_12 ) ;
return 0 ;
}
V_6 = V_50 -> V_12 -> V_6 ;
F_12 ( V_6 ) ;
V_51 = F_33 ( V_6 -> V_8 . V_63 *
sizeof( struct V_11 * ) , V_64 ) ;
if ( ! V_51 )
return - V_65 ;
V_53 = F_33 ( V_6 -> V_8 . V_66 *
sizeof( struct V_1 * ) , V_64 ) ;
if ( ! V_53 ) {
F_34 ( V_51 ) ;
return - V_65 ;
}
V_57 = 0 ;
F_7 (encoder, dev) {
V_51 [ V_57 ++ ] = V_2 -> V_12 ;
}
V_57 = 0 ;
F_5 (connector, dev) {
V_53 [ V_57 ++ ] = V_4 -> V_2 ;
}
V_60 . V_12 = V_50 -> V_12 ;
V_60 . V_28 = & V_50 -> V_12 -> V_28 ;
V_60 . V_29 = V_50 -> V_12 -> V_29 ;
V_60 . V_30 = V_50 -> V_12 -> V_30 ;
V_60 . V_24 = V_50 -> V_12 -> V_23 -> V_24 ;
if ( V_50 -> V_12 -> V_23 -> V_24 != V_50 -> V_24 ) {
if ( V_50 -> V_12 -> V_23 -> V_24 == NULL ) {
F_23 ( L_10 ) ;
V_55 = true ;
} else if ( V_50 -> V_24 -> V_67 !=
V_50 -> V_12 -> V_23 -> V_24 -> V_67 ) {
V_55 = true ;
} else
V_56 = true ;
}
if ( V_50 -> V_29 != V_50 -> V_12 -> V_29 || V_50 -> V_30 != V_50 -> V_12 -> V_30 )
V_56 = true ;
if ( ! F_35 ( V_50 -> V_28 , & V_50 -> V_12 -> V_28 ) ) {
F_23 ( L_11 ) ;
F_36 ( & V_50 -> V_12 -> V_28 ) ;
F_36 ( V_50 -> V_28 ) ;
V_55 = true ;
}
for ( V_58 = 0 ; V_58 < V_50 -> V_62 ; V_58 ++ ) {
if ( V_50 -> V_68 [ V_58 ] -> V_2 )
continue;
F_37 ( V_50 -> V_68 [ V_58 ] ) ;
}
V_57 = 0 ;
F_5 (connector, dev) {
const struct V_69 * V_70 =
V_4 -> V_15 ;
V_54 = V_4 -> V_2 ;
for ( V_58 = 0 ; V_58 < V_50 -> V_62 ; V_58 ++ ) {
if ( V_50 -> V_68 [ V_58 ] == V_4 ) {
V_54 = V_70 -> V_71 ( V_4 ) ;
if ( V_54 == NULL )
V_59 = 1 ;
if ( V_4 -> V_18 != V_72 ) {
F_23 ( L_12 ) ;
V_55 = true ;
}
break;
}
}
if ( V_54 != V_4 -> V_2 ) {
F_23 ( L_13 ) ;
V_55 = true ;
if ( V_4 -> V_2 )
V_4 -> V_2 -> V_12 = NULL ;
V_4 -> V_2 = V_54 ;
}
}
if ( V_59 ) {
V_39 = - V_73 ;
goto V_59;
}
V_57 = 0 ;
F_5 (connector, dev) {
if ( ! V_4 -> V_2 )
continue;
if ( V_4 -> V_2 -> V_12 == V_50 -> V_12 )
V_52 = NULL ;
else
V_52 = V_4 -> V_2 -> V_12 ;
for ( V_58 = 0 ; V_58 < V_50 -> V_62 ; V_58 ++ ) {
if ( V_50 -> V_68 [ V_58 ] == V_4 )
V_52 = V_50 -> V_12 ;
}
if ( V_52 &&
! F_38 ( V_4 -> V_2 , V_52 ) ) {
V_39 = - V_73 ;
goto V_59;
}
if ( V_52 != V_4 -> V_2 -> V_12 ) {
F_23 ( L_14 ) ;
V_55 = true ;
V_4 -> V_2 -> V_12 = V_52 ;
}
if ( V_52 ) {
F_23 ( L_15 ,
V_4 -> V_43 . V_44 , V_4 -> V_45 ,
V_52 -> V_43 . V_44 , V_52 -> V_45 ) ;
} else {
F_23 ( L_16 ,
V_4 -> V_43 . V_44 , V_4 -> V_45 ) ;
}
}
if ( V_56 && ! V_21 -> V_74 )
V_55 = true ;
if ( V_55 ) {
if ( F_6 ( V_50 -> V_12 ) ) {
F_23 ( L_17
L_18 ) ;
F_36 ( V_50 -> V_28 ) ;
V_50 -> V_12 -> V_23 -> V_24 = V_50 -> V_24 ;
if ( ! F_20 ( V_50 -> V_12 , V_50 -> V_28 ,
V_50 -> V_29 , V_50 -> V_30 ,
V_60 . V_24 ) ) {
F_16 ( L_19 ,
V_50 -> V_12 -> V_43 . V_44 , V_50 -> V_12 -> V_45 ) ;
V_50 -> V_12 -> V_23 -> V_24 = V_60 . V_24 ;
V_39 = - V_73 ;
goto V_59;
}
F_23 ( L_20 ) ;
for ( V_61 = 0 ; V_61 < V_50 -> V_62 ; V_61 ++ ) {
F_23 ( L_21 , V_50 -> V_68 [ V_61 ] -> V_43 . V_44 ,
V_50 -> V_68 [ V_61 ] -> V_45 ) ;
V_50 -> V_68 [ V_61 ] -> V_75 -> V_18 ( V_50 -> V_68 [ V_61 ] , V_72 ) ;
}
}
F_11 ( V_6 ) ;
} else if ( V_56 ) {
V_50 -> V_12 -> V_29 = V_50 -> V_29 ;
V_50 -> V_12 -> V_30 = V_50 -> V_30 ;
V_50 -> V_12 -> V_23 -> V_24 = V_50 -> V_24 ;
V_39 = V_21 -> V_74 ( V_50 -> V_12 ,
V_50 -> V_29 , V_50 -> V_30 , V_60 . V_24 ) ;
if ( V_39 != 0 ) {
V_50 -> V_12 -> V_29 = V_60 . V_29 ;
V_50 -> V_12 -> V_30 = V_60 . V_30 ;
V_50 -> V_12 -> V_23 -> V_24 = V_60 . V_24 ;
goto V_59;
}
}
F_34 ( V_53 ) ;
F_34 ( V_51 ) ;
return 0 ;
V_59:
V_57 = 0 ;
F_7 (encoder, dev) {
V_2 -> V_12 = V_51 [ V_57 ++ ] ;
}
V_57 = 0 ;
F_5 (connector, dev) {
V_4 -> V_2 = V_53 [ V_57 ++ ] ;
}
for ( V_58 = 0 ; V_58 < V_50 -> V_62 ; V_58 ++ ) {
if ( V_50 -> V_68 [ V_58 ] -> V_2 )
continue;
F_30 ( V_50 -> V_68 [ V_58 ] ) ;
}
if ( V_55 &&
! F_20 ( V_60 . V_12 , V_60 . V_28 , V_60 . V_29 ,
V_60 . V_30 , V_60 . V_24 ) )
F_16 ( L_22 ) ;
F_34 ( V_53 ) ;
F_34 ( V_51 ) ;
return V_39 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_18 = V_19 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_5 (connector, dev)
if ( V_4 -> V_2 == V_2 )
if ( V_4 -> V_18 < V_18 )
V_18 = V_4 -> V_18 ;
return V_18 ;
}
static void F_40 ( struct V_1 * V_2 , int V_28 )
{
struct V_76 * V_16 = V_2 -> V_16 ;
const struct V_13 * V_14 ;
V_14 = V_2 -> V_15 ;
if ( ! V_14 )
return;
if ( V_28 == V_72 )
F_25 ( V_16 ) ;
else
F_9 ( V_16 ) ;
if ( V_14 -> V_18 )
V_14 -> V_18 ( V_2 , V_28 ) ;
if ( V_28 == V_72 )
F_26 ( V_16 ) ;
else
F_10 ( V_16 ) ;
}
static int F_41 ( struct V_11 * V_12 )
{
int V_18 = V_19 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = V_12 -> V_6 ;
F_5 (connector, dev)
if ( V_4 -> V_2 && V_4 -> V_2 -> V_12 == V_12 )
if ( V_4 -> V_18 < V_18 )
V_18 = V_4 -> V_18 ;
return V_18 ;
}
int F_42 ( struct V_3 * V_4 , int V_28 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_2 ? V_2 -> V_12 : NULL ;
int V_77 , V_78 = V_19 ;
if ( V_28 == V_4 -> V_18 )
return 0 ;
V_77 = V_4 -> V_18 ;
V_4 -> V_18 = V_28 ;
if ( V_2 )
V_78 = F_39 ( V_2 ) ;
if ( V_28 < V_77 ) {
if ( V_12 ) {
const struct V_20 * V_21 = V_12 -> V_15 ;
if ( V_21 -> V_18 )
(* V_21 -> V_18 ) ( V_12 ,
F_41 ( V_12 ) ) ;
}
if ( V_2 )
F_40 ( V_2 , V_78 ) ;
}
if ( V_28 > V_77 ) {
if ( V_2 )
F_40 ( V_2 , V_78 ) ;
if ( V_12 ) {
const struct V_20 * V_21 = V_12 -> V_15 ;
if ( V_21 -> V_18 )
(* V_21 -> V_18 ) ( V_12 ,
F_41 ( V_12 ) ) ;
}
}
return 0 ;
}
void F_43 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
const struct V_20 * V_21 ;
int V_78 ;
bool V_39 ;
F_17 ( V_6 ) ;
F_13 (crtc, dev) {
if ( ! V_12 -> V_22 )
continue;
V_39 = F_20 ( V_12 , & V_12 -> V_28 ,
V_12 -> V_29 , V_12 -> V_30 , V_12 -> V_23 -> V_24 ) ;
if ( V_39 == false )
F_16 ( L_23 , V_12 ) ;
if ( F_41 ( V_12 ) ) {
F_7 (encoder, dev) {
if( V_2 -> V_12 != V_12 )
continue;
V_78 = F_39 (
V_2 ) ;
F_40 ( V_2 , V_78 ) ;
}
V_21 = V_12 -> V_15 ;
if ( V_21 -> V_18 )
(* V_21 -> V_18 ) ( V_12 ,
F_41 ( V_12 ) ) ;
}
}
F_11 ( V_6 ) ;
F_18 ( V_6 ) ;
}
int F_44 ( struct V_11 * V_12 , struct V_27 * V_28 ,
struct V_27 * V_33 , int V_29 , int V_30 ,
struct V_31 * V_32 )
{
struct V_79 * V_80 ;
const struct V_20 * V_21 = V_12 -> V_15 ;
int V_39 ;
if ( V_12 -> V_75 -> V_81 )
V_80 = V_12 -> V_75 -> V_81 ( V_12 ) ;
else {
if ( ! V_12 -> V_82 )
F_45 ( V_12 ) ;
V_80 = F_46 ( V_12 ) ;
}
if ( ! V_80 )
return - V_65 ;
V_80 -> V_83 = true ;
V_80 -> V_55 = true ;
V_39 = F_47 ( V_80 , V_28 ) ;
if ( V_39 )
goto V_84;
F_48 ( & V_80 -> V_33 , V_33 ) ;
if ( V_21 -> V_85 ) {
V_39 = V_21 -> V_85 ( V_12 , V_80 ) ;
if ( V_39 )
goto V_84;
}
F_49 ( V_12 -> V_82 , V_80 ) ;
V_21 -> V_86 ( V_12 ) ;
V_39 = F_50 ( V_12 , V_29 , V_30 , V_32 ) ;
V_84:
if ( V_80 ) {
if ( V_12 -> V_75 -> V_87 )
V_12 -> V_75 -> V_87 ( V_12 , V_80 ) ;
else
F_51 ( V_12 , V_80 ) ;
}
return V_39 ;
}
int F_50 ( struct V_11 * V_12 , int V_29 , int V_30 ,
struct V_31 * V_32 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 = V_12 -> V_23 ;
if ( V_91 -> V_75 -> V_81 )
V_89 = V_91 -> V_75 -> V_81 ( V_91 ) ;
else {
if ( ! V_91 -> V_82 )
F_52 ( V_91 ) ;
V_89 = F_53 ( V_91 ) ;
}
if ( ! V_89 )
return - V_65 ;
V_89 -> V_91 = V_91 ;
V_89 -> V_12 = V_12 ;
F_54 ( V_89 , V_12 -> V_23 -> V_24 ) ;
V_89 -> V_92 = 0 ;
V_89 -> V_93 = 0 ;
V_89 -> V_94 = V_12 -> V_28 . V_95 ;
V_89 -> V_96 = V_12 -> V_28 . V_97 ;
V_89 -> V_98 = V_29 << 16 ;
V_89 -> V_99 = V_30 << 16 ;
V_89 -> V_100 = V_12 -> V_28 . V_95 << 16 ;
V_89 -> V_101 = V_12 -> V_28 . V_97 << 16 ;
return F_55 ( V_91 , V_89 , V_32 ) ;
}
