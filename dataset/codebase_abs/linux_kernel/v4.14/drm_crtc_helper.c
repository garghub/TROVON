bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_9 ) {
F_2 ( ! F_3 ( & V_8 -> V_10 . V_11 ) ) ;
F_2 ( ! F_4 ( & V_8 -> V_10 . V_12 ) ) ;
}
F_5 ( V_8 , & V_6 ) ;
F_6 (connector, &conn_iter) {
if ( V_4 -> V_2 == V_2 ) {
F_7 ( & V_6 ) ;
return true ;
}
}
F_7 ( & V_6 ) ;
return false ;
}
bool F_8 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_14 -> V_8 ;
if ( ! V_9 )
F_2 ( ! F_3 ( & V_8 -> V_10 . V_11 ) ) ;
F_9 (encoder, dev)
if ( V_2 -> V_14 == V_14 && F_1 ( V_2 ) )
return true ;
return false ;
}
static void
F_10 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_17 ;
if ( ! V_16 )
return;
F_11 ( V_2 -> V_18 ) ;
if ( V_16 -> V_19 )
(* V_16 -> V_19 )( V_2 ) ;
else if ( V_16 -> V_20 )
(* V_16 -> V_20 )( V_2 , V_21 ) ;
F_12 ( V_2 -> V_18 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
F_14 ( V_8 ) ;
F_9 (encoder, dev) {
if ( ! F_1 ( V_2 ) ) {
F_10 ( V_2 ) ;
V_2 -> V_14 = NULL ;
}
}
F_15 (crtc, dev) {
const struct V_22 * V_23 = V_14 -> V_17 ;
V_14 -> V_24 = F_8 ( V_14 ) ;
if ( ! V_14 -> V_24 ) {
if ( V_23 -> V_19 )
(* V_23 -> V_19 )( V_14 ) ;
else
(* V_23 -> V_20 )( V_14 , V_21 ) ;
V_14 -> V_25 -> V_26 = NULL ;
}
}
}
void F_16 ( struct V_7 * V_8 )
{
if ( F_17 ( V_8 , V_27 ) )
F_18 ( L_1 ) ;
F_19 ( V_8 ) ;
F_13 ( V_8 ) ;
F_20 ( V_8 ) ;
}
static void
F_21 ( struct V_7 * V_8 )
{
const struct V_15 * V_16 ;
struct V_1 * V_2 ;
F_9 (encoder, dev) {
V_16 = V_2 -> V_17 ;
if ( ! V_16 )
continue;
if ( V_2 -> V_14 == NULL )
F_10 ( V_2 ) ;
if ( V_16 -> V_28 &&
V_2 -> V_14 != (* V_16 -> V_28 )( V_2 ) )
F_10 ( V_2 ) ;
}
}
bool F_22 ( struct V_13 * V_14 ,
struct V_29 * V_30 ,
int V_31 , int V_32 ,
struct V_33 * V_34 )
{
struct V_7 * V_8 = V_14 -> V_8 ;
struct V_29 * V_35 , V_36 , V_37 ;
const struct V_22 * V_23 = V_14 -> V_17 ;
const struct V_15 * V_16 ;
int V_38 , V_39 ;
bool V_40 ;
struct V_1 * V_2 ;
bool V_41 = true ;
F_14 ( V_8 ) ;
V_40 = V_14 -> V_24 ;
V_14 -> V_24 = F_8 ( V_14 ) ;
if ( ! V_14 -> V_24 )
return true ;
V_35 = F_23 ( V_8 , V_30 ) ;
if ( ! V_35 ) {
V_14 -> V_24 = V_40 ;
return false ;
}
V_36 = V_14 -> V_30 ;
V_37 = V_14 -> V_42 ;
V_38 = V_14 -> V_31 ;
V_39 = V_14 -> V_32 ;
V_14 -> V_30 = * V_30 ;
V_14 -> V_31 = V_31 ;
V_14 -> V_32 = V_32 ;
F_9 (encoder, dev) {
if ( V_2 -> V_14 != V_14 )
continue;
V_16 = V_2 -> V_17 ;
if ( ! V_16 )
continue;
V_41 = F_24 ( V_2 -> V_18 ,
V_30 , V_35 ) ;
if ( ! V_41 ) {
F_25 ( L_2 ) ;
goto V_43;
}
V_16 = V_2 -> V_17 ;
if ( V_16 -> V_44 ) {
if ( ! ( V_41 = V_16 -> V_44 ( V_2 , V_30 ,
V_35 ) ) ) {
F_25 ( L_3 ) ;
goto V_43;
}
}
}
if ( V_23 -> V_44 ) {
if ( ! ( V_41 = V_23 -> V_44 ( V_14 , V_30 ,
V_35 ) ) ) {
F_25 ( L_4 ) ;
goto V_43;
}
}
F_25 ( L_5 , V_14 -> V_45 . V_46 , V_14 -> V_47 ) ;
V_14 -> V_42 = * V_35 ;
F_9 (encoder, dev) {
if ( V_2 -> V_14 != V_14 )
continue;
V_16 = V_2 -> V_17 ;
if ( ! V_16 )
continue;
F_11 ( V_2 -> V_18 ) ;
if ( V_16 -> V_48 )
V_16 -> V_48 ( V_2 ) ;
F_12 ( V_2 -> V_18 ) ;
}
F_21 ( V_8 ) ;
V_23 -> V_48 ( V_14 ) ;
V_41 = ! V_23 -> V_49 ( V_14 , V_30 , V_35 , V_31 , V_32 , V_34 ) ;
if ( ! V_41 )
goto V_43;
F_9 (encoder, dev) {
if ( V_2 -> V_14 != V_14 )
continue;
V_16 = V_2 -> V_17 ;
if ( ! V_16 )
continue;
F_25 ( L_6 ,
V_2 -> V_45 . V_46 , V_2 -> V_47 ,
V_30 -> V_45 . V_46 , V_30 -> V_47 ) ;
if ( V_16 -> V_49 )
V_16 -> V_49 ( V_2 , V_30 , V_35 ) ;
F_26 ( V_2 -> V_18 , V_30 , V_35 ) ;
}
V_23 -> V_50 ( V_14 ) ;
F_9 (encoder, dev) {
if ( V_2 -> V_14 != V_14 )
continue;
V_16 = V_2 -> V_17 ;
if ( ! V_16 )
continue;
F_27 ( V_2 -> V_18 ) ;
if ( V_16 -> V_50 )
V_16 -> V_50 ( V_2 ) ;
F_28 ( V_2 -> V_18 ) ;
}
F_29 ( V_14 , & V_14 -> V_42 ) ;
V_43:
F_30 ( V_8 , V_35 ) ;
if ( ! V_41 ) {
V_14 -> V_24 = V_40 ;
V_14 -> V_30 = V_36 ;
V_14 -> V_42 = V_37 ;
V_14 -> V_31 = V_38 ;
V_14 -> V_32 = V_39 ;
}
return V_41 ;
}
static void
F_31 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_8 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
F_9 (encoder, dev) {
struct V_5 V_6 ;
if ( V_2 -> V_14 != V_14 )
continue;
F_5 ( V_8 , & V_6 ) ;
F_6 (connector, &conn_iter) {
if ( V_4 -> V_2 != V_2 )
continue;
V_4 -> V_2 = NULL ;
V_4 -> V_20 = V_21 ;
F_32 ( V_4 ) ;
}
F_7 ( & V_6 ) ;
}
F_13 ( V_8 ) ;
}
int F_33 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 ;
struct V_13 * * V_55 , * V_56 ;
struct V_1 * * V_57 , * V_58 , * V_2 ;
bool V_59 = false ;
bool V_60 = false ;
struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_61 = 0 , V_62 , V_63 = 0 ;
const struct V_22 * V_23 ;
struct V_51 V_64 ;
int V_41 ;
int V_65 ;
F_25 ( L_7 ) ;
F_34 ( ! V_52 ) ;
F_34 ( ! V_52 -> V_14 ) ;
F_34 ( ! V_52 -> V_14 -> V_17 ) ;
F_34 ( ! V_52 -> V_30 && V_52 -> V_26 ) ;
F_34 ( V_52 -> V_26 && V_52 -> V_66 == 0 ) ;
V_23 = V_52 -> V_14 -> V_17 ;
if ( ! V_52 -> V_30 )
V_52 -> V_26 = NULL ;
if ( V_52 -> V_26 ) {
F_25 ( L_8 ,
V_52 -> V_14 -> V_45 . V_46 , V_52 -> V_14 -> V_47 ,
V_52 -> V_26 -> V_45 . V_46 ,
( int ) V_52 -> V_66 , V_52 -> V_31 , V_52 -> V_32 ) ;
} else {
F_25 ( L_9 ,
V_52 -> V_14 -> V_45 . V_46 , V_52 -> V_14 -> V_47 ) ;
F_31 ( V_52 -> V_14 ) ;
return 0 ;
}
V_8 = V_52 -> V_14 -> V_8 ;
F_14 ( V_8 ) ;
V_55 = F_35 ( V_8 -> V_10 . V_67 *
sizeof( struct V_13 * ) , V_68 ) ;
if ( ! V_55 )
return - V_69 ;
V_57 = F_35 ( V_8 -> V_10 . V_70 *
sizeof( struct V_1 * ) , V_68 ) ;
if ( ! V_57 ) {
F_36 ( V_55 ) ;
return - V_69 ;
}
V_61 = 0 ;
F_9 (encoder, dev) {
V_55 [ V_61 ++ ] = V_2 -> V_14 ;
}
V_61 = 0 ;
F_5 ( V_8 , & V_6 ) ;
F_6 (connector, &conn_iter)
V_57 [ V_61 ++ ] = V_4 -> V_2 ;
F_7 ( & V_6 ) ;
V_64 . V_14 = V_52 -> V_14 ;
V_64 . V_30 = & V_52 -> V_14 -> V_30 ;
V_64 . V_31 = V_52 -> V_14 -> V_31 ;
V_64 . V_32 = V_52 -> V_14 -> V_32 ;
V_64 . V_26 = V_52 -> V_14 -> V_25 -> V_26 ;
if ( V_52 -> V_14 -> V_25 -> V_26 != V_52 -> V_26 ) {
if ( V_52 -> V_14 -> V_25 -> V_26 == NULL ) {
F_25 ( L_10 ) ;
V_59 = true ;
} else if ( V_52 -> V_26 -> V_71 != V_52 -> V_14 -> V_25 -> V_26 -> V_71 ) {
V_59 = true ;
} else
V_60 = true ;
}
if ( V_52 -> V_31 != V_52 -> V_14 -> V_31 || V_52 -> V_32 != V_52 -> V_14 -> V_32 )
V_60 = true ;
if ( ! F_37 ( V_52 -> V_30 , & V_52 -> V_14 -> V_30 ) ) {
F_25 ( L_11 ) ;
F_38 ( & V_52 -> V_14 -> V_30 ) ;
F_38 ( V_52 -> V_30 ) ;
V_59 = true ;
}
for ( V_62 = 0 ; V_62 < V_52 -> V_66 ; V_62 ++ ) {
if ( V_52 -> V_72 [ V_62 ] -> V_2 )
continue;
F_39 ( V_52 -> V_72 [ V_62 ] ) ;
}
V_61 = 0 ;
F_5 ( V_8 , & V_6 ) ;
F_6 (connector, &conn_iter) {
const struct V_73 * V_74 =
V_4 -> V_17 ;
V_58 = V_4 -> V_2 ;
for ( V_62 = 0 ; V_62 < V_52 -> V_66 ; V_62 ++ ) {
if ( V_52 -> V_72 [ V_62 ] == V_4 ) {
V_58 = V_74 -> V_75 ( V_4 ) ;
if ( V_58 == NULL )
V_63 = 1 ;
if ( V_4 -> V_20 != V_76 ) {
F_25 ( L_12 ) ;
V_59 = true ;
}
break;
}
}
if ( V_58 != V_4 -> V_2 ) {
F_25 ( L_13 ) ;
V_59 = true ;
if ( V_4 -> V_2 )
V_4 -> V_2 -> V_14 = NULL ;
V_4 -> V_2 = V_58 ;
}
}
F_7 ( & V_6 ) ;
if ( V_63 ) {
V_41 = - V_77 ;
goto V_63;
}
V_61 = 0 ;
F_5 ( V_8 , & V_6 ) ;
F_6 (connector, &conn_iter) {
if ( ! V_4 -> V_2 )
continue;
if ( V_4 -> V_2 -> V_14 == V_52 -> V_14 )
V_56 = NULL ;
else
V_56 = V_4 -> V_2 -> V_14 ;
for ( V_62 = 0 ; V_62 < V_52 -> V_66 ; V_62 ++ ) {
if ( V_52 -> V_72 [ V_62 ] == V_4 )
V_56 = V_52 -> V_14 ;
}
if ( V_56 &&
! F_40 ( V_4 -> V_2 , V_56 ) ) {
V_41 = - V_77 ;
F_7 ( & V_6 ) ;
goto V_63;
}
if ( V_56 != V_4 -> V_2 -> V_14 ) {
F_25 ( L_14 ) ;
V_59 = true ;
V_4 -> V_2 -> V_14 = V_56 ;
}
if ( V_56 ) {
F_25 ( L_15 ,
V_4 -> V_45 . V_46 , V_4 -> V_47 ,
V_56 -> V_45 . V_46 , V_56 -> V_47 ) ;
} else {
F_25 ( L_16 ,
V_4 -> V_45 . V_46 , V_4 -> V_47 ) ;
}
}
F_7 ( & V_6 ) ;
if ( V_60 && ! V_23 -> V_78 )
V_59 = true ;
if ( V_59 ) {
if ( F_8 ( V_52 -> V_14 ) ) {
F_25 ( L_17
L_18 ) ;
F_38 ( V_52 -> V_30 ) ;
V_52 -> V_14 -> V_25 -> V_26 = V_52 -> V_26 ;
if ( ! F_22 ( V_52 -> V_14 , V_52 -> V_30 ,
V_52 -> V_31 , V_52 -> V_32 ,
V_64 . V_26 ) ) {
F_18 ( L_19 ,
V_52 -> V_14 -> V_45 . V_46 , V_52 -> V_14 -> V_47 ) ;
V_52 -> V_14 -> V_25 -> V_26 = V_64 . V_26 ;
V_41 = - V_77 ;
goto V_63;
}
F_25 ( L_20 ) ;
for ( V_65 = 0 ; V_65 < V_52 -> V_66 ; V_65 ++ ) {
F_25 ( L_21 , V_52 -> V_72 [ V_65 ] -> V_45 . V_46 ,
V_52 -> V_72 [ V_65 ] -> V_47 ) ;
V_52 -> V_72 [ V_65 ] -> V_79 -> V_20 ( V_52 -> V_72 [ V_65 ] , V_76 ) ;
}
}
F_13 ( V_8 ) ;
} else if ( V_60 ) {
V_52 -> V_14 -> V_31 = V_52 -> V_31 ;
V_52 -> V_14 -> V_32 = V_52 -> V_32 ;
V_52 -> V_14 -> V_25 -> V_26 = V_52 -> V_26 ;
V_41 = V_23 -> V_78 ( V_52 -> V_14 ,
V_52 -> V_31 , V_52 -> V_32 , V_64 . V_26 ) ;
if ( V_41 != 0 ) {
V_52 -> V_14 -> V_31 = V_64 . V_31 ;
V_52 -> V_14 -> V_32 = V_64 . V_32 ;
V_52 -> V_14 -> V_25 -> V_26 = V_64 . V_26 ;
goto V_63;
}
}
F_36 ( V_57 ) ;
F_36 ( V_55 ) ;
return 0 ;
V_63:
V_61 = 0 ;
F_9 (encoder, dev) {
V_2 -> V_14 = V_55 [ V_61 ++ ] ;
}
V_61 = 0 ;
F_5 ( V_8 , & V_6 ) ;
F_6 (connector, &conn_iter)
V_4 -> V_2 = V_57 [ V_61 ++ ] ;
F_7 ( & V_6 ) ;
for ( V_62 = 0 ; V_62 < V_52 -> V_66 ; V_62 ++ ) {
if ( V_52 -> V_72 [ V_62 ] -> V_2 )
continue;
F_32 ( V_52 -> V_72 [ V_62 ] ) ;
}
if ( V_59 &&
! F_22 ( V_64 . V_14 , V_64 . V_30 , V_64 . V_31 ,
V_64 . V_32 , V_64 . V_26 ) )
F_18 ( L_22 ) ;
F_36 ( V_57 ) ;
F_36 ( V_55 ) ;
return V_41 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_20 = V_21 ;
struct V_3 * V_4 ;
struct V_5 V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_5 ( V_8 , & V_6 ) ;
F_6 (connector, &conn_iter)
if ( V_4 -> V_2 == V_2 )
if ( V_4 -> V_20 < V_20 )
V_20 = V_4 -> V_20 ;
F_7 ( & V_6 ) ;
return V_20 ;
}
static void F_42 ( struct V_1 * V_2 , int V_30 )
{
struct V_80 * V_18 = V_2 -> V_18 ;
const struct V_15 * V_16 ;
V_16 = V_2 -> V_17 ;
if ( ! V_16 )
return;
if ( V_30 == V_76 )
F_27 ( V_18 ) ;
else
F_11 ( V_18 ) ;
if ( V_16 -> V_20 )
V_16 -> V_20 ( V_2 , V_30 ) ;
if ( V_30 == V_76 )
F_28 ( V_18 ) ;
else
F_12 ( V_18 ) ;
}
static int F_43 ( struct V_13 * V_14 )
{
int V_20 = V_21 ;
struct V_3 * V_4 ;
struct V_5 V_6 ;
struct V_7 * V_8 = V_14 -> V_8 ;
F_5 ( V_8 , & V_6 ) ;
F_6 (connector, &conn_iter)
if ( V_4 -> V_2 && V_4 -> V_2 -> V_14 == V_14 )
if ( V_4 -> V_20 < V_20 )
V_20 = V_4 -> V_20 ;
F_7 ( & V_6 ) ;
return V_20 ;
}
int F_44 ( struct V_3 * V_4 , int V_30 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_13 * V_14 = V_2 ? V_2 -> V_14 : NULL ;
int V_81 , V_82 = V_21 ;
if ( V_30 == V_4 -> V_20 )
return 0 ;
V_81 = V_4 -> V_20 ;
V_4 -> V_20 = V_30 ;
if ( V_2 )
V_82 = F_41 ( V_2 ) ;
if ( V_30 < V_81 ) {
if ( V_14 ) {
const struct V_22 * V_23 = V_14 -> V_17 ;
if ( V_23 -> V_20 )
(* V_23 -> V_20 ) ( V_14 ,
F_43 ( V_14 ) ) ;
}
if ( V_2 )
F_42 ( V_2 , V_82 ) ;
}
if ( V_30 > V_81 ) {
if ( V_2 )
F_42 ( V_2 , V_82 ) ;
if ( V_14 ) {
const struct V_22 * V_23 = V_14 -> V_17 ;
if ( V_23 -> V_20 )
(* V_23 -> V_20 ) ( V_14 ,
F_43 ( V_14 ) ) ;
}
}
return 0 ;
}
void F_45 ( struct V_7 * V_8 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
const struct V_22 * V_23 ;
int V_82 ;
bool V_41 ;
F_19 ( V_8 ) ;
F_15 (crtc, dev) {
if ( ! V_14 -> V_24 )
continue;
V_41 = F_22 ( V_14 , & V_14 -> V_30 ,
V_14 -> V_31 , V_14 -> V_32 , V_14 -> V_25 -> V_26 ) ;
if ( V_41 == false )
F_18 ( L_23 , V_14 ) ;
if ( F_43 ( V_14 ) ) {
F_9 (encoder, dev) {
if( V_2 -> V_14 != V_14 )
continue;
V_82 = F_41 (
V_2 ) ;
F_42 ( V_2 , V_82 ) ;
}
V_23 = V_14 -> V_17 ;
if ( V_23 -> V_20 )
(* V_23 -> V_20 ) ( V_14 ,
F_43 ( V_14 ) ) ;
}
}
F_13 ( V_8 ) ;
F_20 ( V_8 ) ;
}
int F_46 ( struct V_13 * V_14 , struct V_29 * V_30 ,
struct V_29 * V_35 , int V_31 , int V_32 ,
struct V_33 * V_34 )
{
struct V_83 * V_84 ;
const struct V_22 * V_23 = V_14 -> V_17 ;
int V_41 ;
if ( V_14 -> V_79 -> V_85 )
V_84 = V_14 -> V_79 -> V_85 ( V_14 ) ;
else {
if ( ! V_14 -> V_86 )
F_47 ( V_14 ) ;
V_84 = F_48 ( V_14 ) ;
}
if ( ! V_84 )
return - V_69 ;
V_84 -> V_87 = true ;
V_84 -> V_59 = true ;
V_41 = F_49 ( V_84 , V_30 ) ;
if ( V_41 )
goto V_88;
F_50 ( & V_84 -> V_35 , V_35 ) ;
if ( V_23 -> V_89 ) {
V_41 = V_23 -> V_89 ( V_14 , V_84 ) ;
if ( V_41 )
goto V_88;
}
F_51 ( V_14 -> V_86 , V_84 ) ;
V_23 -> V_90 ( V_14 ) ;
V_41 = F_52 ( V_14 , V_31 , V_32 , V_34 ) ;
V_88:
if ( V_84 ) {
if ( V_14 -> V_79 -> V_91 )
V_14 -> V_79 -> V_91 ( V_14 , V_84 ) ;
else
F_53 ( V_14 , V_84 ) ;
}
return V_41 ;
}
int F_52 ( struct V_13 * V_14 , int V_31 , int V_32 ,
struct V_33 * V_34 )
{
struct V_92 * V_93 ;
struct V_94 * V_95 = V_14 -> V_25 ;
if ( V_95 -> V_79 -> V_85 )
V_93 = V_95 -> V_79 -> V_85 ( V_95 ) ;
else {
if ( ! V_95 -> V_86 )
F_54 ( V_95 ) ;
V_93 = F_55 ( V_95 ) ;
}
if ( ! V_93 )
return - V_69 ;
V_93 -> V_95 = V_95 ;
V_93 -> V_14 = V_14 ;
F_56 ( V_93 , V_14 -> V_25 -> V_26 ) ;
V_93 -> V_96 = 0 ;
V_93 -> V_97 = 0 ;
V_93 -> V_98 = V_14 -> V_30 . V_99 ;
V_93 -> V_100 = V_14 -> V_30 . V_101 ;
V_93 -> V_102 = V_31 << 16 ;
V_93 -> V_103 = V_32 << 16 ;
V_93 -> V_104 = V_14 -> V_30 . V_99 << 16 ;
V_93 -> V_105 = V_14 -> V_30 . V_101 << 16 ;
return F_57 ( V_95 , V_93 , V_34 ) ;
}
