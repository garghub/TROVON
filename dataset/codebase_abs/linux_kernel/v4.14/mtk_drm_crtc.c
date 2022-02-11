static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_8 )
{
struct V_2 * V_9 = & V_8 -> V_4 ;
unsigned long V_10 ;
F_5 ( & V_9 -> V_11 -> V_12 , V_10 ) ;
F_6 ( V_9 , V_8 -> V_13 ) ;
F_7 ( V_9 ) ;
V_8 -> V_13 = NULL ;
F_8 ( & V_9 -> V_11 -> V_12 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_8 )
{
F_10 ( & V_8 -> V_4 ) ;
if ( V_8 -> V_14 ) {
F_4 ( V_8 ) ;
V_8 -> V_14 = false ;
}
}
static void F_11 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_12 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
F_13 ( V_8 -> V_19 ) ;
F_14 ( V_9 ) ;
}
static void F_15 ( struct V_2 * V_9 )
{
struct V_5 * V_20 ;
if ( V_9 -> V_20 ) {
F_16 ( V_9 -> V_20 ) ;
V_20 = F_3 ( V_9 -> V_20 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
} else {
V_20 = F_17 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return;
V_9 -> V_20 = & V_20 -> V_4 ;
}
V_20 -> V_4 . V_9 = V_9 ;
}
static struct V_6 * F_18 ( struct V_2 * V_9 )
{
struct V_5 * V_20 ;
V_20 = F_17 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return NULL ;
F_19 ( V_9 , & V_20 -> V_4 ) ;
F_20 ( V_20 -> V_4 . V_9 != V_9 ) ;
V_20 -> V_4 . V_9 = V_9 ;
return & V_20 -> V_4 ;
}
static void F_21 ( struct V_2 * V_9 ,
struct V_6 * V_20 )
{
F_16 ( V_20 ) ;
F_22 ( F_3 ( V_20 ) ) ;
}
static bool F_23 ( struct V_2 * V_9 ,
const struct V_22 * V_23 ,
struct V_22 * V_24 )
{
return true ;
}
static void F_24 ( struct V_2 * V_9 )
{
struct V_5 * V_20 = F_3 ( V_9 -> V_20 ) ;
V_20 -> V_25 = V_9 -> V_23 . V_26 ;
V_20 -> V_27 = V_9 -> V_23 . V_28 ;
V_20 -> V_29 = V_9 -> V_23 . V_30 ;
F_25 () ;
V_20 -> V_31 = true ;
}
static int F_26 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_32 * V_33 = V_8 -> V_17 [ 0 ] ;
F_27 ( V_33 , & V_8 -> V_4 ) ;
return 0 ;
}
static void F_28 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_32 * V_33 = V_8 -> V_17 [ 0 ] ;
F_29 ( V_33 ) ;
}
static int F_30 ( struct V_1 * V_8 )
{
int V_34 ;
int V_15 ;
F_31 ( L_1 , V_35 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
V_34 = F_32 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
if ( V_34 ) {
F_33 ( L_2 , V_15 , V_34 ) ;
goto V_36;
}
}
return 0 ;
V_36:
while ( -- V_15 >= 0 )
F_34 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_34 ;
}
static void F_35 ( struct V_1 * V_8 )
{
int V_15 ;
F_31 ( L_1 , V_35 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_34 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
}
static int F_36 ( struct V_1 * V_8 )
{
struct V_2 * V_9 = & V_8 -> V_4 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_41 V_42 ;
unsigned int V_43 , V_44 , V_30 , V_45 = V_46 ;
int V_34 ;
int V_15 ;
F_31 ( L_1 , V_35 ) ;
if ( F_20 ( ! V_9 -> V_20 ) )
return - V_47 ;
V_43 = V_9 -> V_20 -> V_24 . V_26 ;
V_44 = V_9 -> V_20 -> V_24 . V_28 ;
V_30 = V_9 -> V_20 -> V_24 . V_30 ;
F_37 (encoder, crtc->dev) {
if ( V_40 -> V_9 != V_9 )
continue;
F_38 ( V_9 -> V_11 , & V_42 ) ;
F_39 (connector, &conn_iter) {
if ( V_38 -> V_40 != V_40 )
continue;
if ( V_38 -> V_48 . V_45 != 0 &&
V_45 > V_38 -> V_48 . V_45 )
V_45 = V_38 -> V_48 . V_45 ;
}
F_40 ( & V_42 ) ;
}
V_34 = F_41 ( V_9 -> V_11 -> V_11 ) ;
if ( V_34 < 0 ) {
F_33 ( L_3 , V_34 ) ;
return V_34 ;
}
V_34 = F_42 ( V_8 -> V_19 ) ;
if ( V_34 < 0 ) {
F_33 ( L_4 , V_34 ) ;
goto V_49;
}
V_34 = F_30 ( V_8 ) ;
if ( V_34 < 0 ) {
F_33 ( L_5 , V_34 ) ;
goto V_50;
}
F_31 ( L_6 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_43 ( V_8 -> V_51 ,
V_8 -> V_17 [ V_15 ] -> V_52 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_52 ) ;
F_44 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_52 ) ;
}
F_44 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_52 ) ;
F_45 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
struct V_32 * V_53 = V_8 -> V_17 [ V_15 ] ;
F_46 ( V_53 , V_43 , V_44 , V_30 , V_45 ) ;
F_47 ( V_53 ) ;
}
for ( V_15 = 0 ; V_15 < V_54 ; V_15 ++ ) {
struct V_55 * V_56 = & V_8 -> V_57 [ V_15 ] ;
struct V_58 * V_59 ;
V_59 = F_48 ( V_56 -> V_20 ) ;
F_49 ( V_8 -> V_17 [ 0 ] , V_15 ,
V_59 ) ;
}
return 0 ;
V_50:
F_50 ( V_8 -> V_19 ) ;
V_49:
F_51 ( V_9 -> V_11 -> V_11 ) ;
return V_34 ;
}
static void F_52 ( struct V_1 * V_8 )
{
struct V_60 * V_61 = V_8 -> V_4 . V_11 ;
int V_15 ;
F_31 ( L_1 , V_35 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_53 ( V_8 -> V_17 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_54 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_52 ) ;
F_55 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_56 ( V_8 -> V_51 ,
V_8 -> V_17 [ V_15 ] -> V_52 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_52 ) ;
F_54 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_52 ) ;
}
F_54 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_52 ) ;
F_35 ( V_8 ) ;
F_50 ( V_8 -> V_19 ) ;
F_51 ( V_61 -> V_11 ) ;
}
static void F_57 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_5 * V_20 = F_3 ( V_8 -> V_4 . V_20 ) ;
struct V_32 * V_33 = V_8 -> V_17 [ 0 ] ;
unsigned int V_15 ;
if ( V_20 -> V_31 ) {
F_46 ( V_33 , V_20 -> V_25 ,
V_20 -> V_27 ,
V_20 -> V_29 , 0 ) ;
V_20 -> V_31 = false ;
}
if ( V_8 -> V_62 ) {
for ( V_15 = 0 ; V_15 < V_54 ; V_15 ++ ) {
struct V_55 * V_56 = & V_8 -> V_57 [ V_15 ] ;
struct V_58 * V_59 ;
V_59 = F_48 ( V_56 -> V_20 ) ;
if ( V_59 -> V_63 . V_64 ) {
F_49 ( V_33 , V_15 , V_59 ) ;
V_59 -> V_63 . V_64 = false ;
}
}
V_8 -> V_62 = false ;
}
}
static void F_58 ( struct V_2 * V_9 ,
struct V_6 * V_65 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_32 * V_33 = V_8 -> V_17 [ 0 ] ;
int V_34 ;
F_31 ( L_7 , V_35 , V_9 -> V_4 . V_52 ) ;
V_34 = F_59 ( V_33 -> V_66 ) ;
if ( V_34 ) {
F_33 ( L_8 , V_34 ) ;
return;
}
V_34 = F_36 ( V_8 ) ;
if ( V_34 ) {
F_60 ( V_33 -> V_66 ) ;
return;
}
F_61 ( V_9 ) ;
V_8 -> V_67 = true ;
}
static void F_62 ( struct V_2 * V_9 ,
struct V_6 * V_65 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_32 * V_33 = V_8 -> V_17 [ 0 ] ;
int V_15 ;
F_31 ( L_7 , V_35 , V_9 -> V_4 . V_52 ) ;
if ( ! V_8 -> V_67 )
return;
for ( V_15 = 0 ; V_15 < V_54 ; V_15 ++ ) {
struct V_55 * V_56 = & V_8 -> V_57 [ V_15 ] ;
struct V_58 * V_59 ;
V_59 = F_48 ( V_56 -> V_20 ) ;
V_59 -> V_63 . V_68 = false ;
V_59 -> V_63 . V_64 = true ;
}
V_8 -> V_62 = true ;
F_63 ( V_9 ) ;
F_64 ( V_9 ) ;
F_52 ( V_8 ) ;
F_60 ( V_33 -> V_66 ) ;
V_8 -> V_67 = false ;
}
static void F_65 ( struct V_2 * V_9 ,
struct V_6 * V_69 )
{
struct V_5 * V_20 = F_3 ( V_9 -> V_20 ) ;
struct V_1 * V_8 = F_1 ( V_9 ) ;
if ( V_8 -> V_13 && V_20 -> V_4 . V_13 )
F_33 ( L_9 ) ;
if ( V_20 -> V_4 . V_13 ) {
V_20 -> V_4 . V_13 -> V_70 = F_66 ( V_9 ) ;
F_20 ( F_67 ( V_9 ) != 0 ) ;
V_8 -> V_13 = V_20 -> V_4 . V_13 ;
V_20 -> V_4 . V_13 = NULL ;
}
}
static void F_68 ( struct V_2 * V_9 ,
struct V_6 * V_69 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_71 * V_72 = V_9 -> V_11 -> V_73 ;
unsigned int V_62 = 0 ;
int V_15 ;
if ( V_8 -> V_13 )
V_8 -> V_14 = true ;
for ( V_15 = 0 ; V_15 < V_54 ; V_15 ++ ) {
struct V_55 * V_56 = & V_8 -> V_57 [ V_15 ] ;
struct V_58 * V_59 ;
V_59 = F_48 ( V_56 -> V_20 ) ;
if ( V_59 -> V_63 . V_74 ) {
V_59 -> V_63 . V_64 = true ;
V_59 -> V_63 . V_74 = false ;
V_62 |= F_69 ( V_15 ) ;
}
}
if ( V_62 )
V_8 -> V_62 = true ;
if ( V_9 -> V_20 -> V_75 )
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_70 ( V_8 -> V_17 [ V_15 ] , V_9 -> V_20 ) ;
if ( V_72 -> V_76 -> V_77 ) {
F_71 ( V_8 -> V_19 ) ;
F_57 ( V_9 ) ;
F_72 ( V_8 -> V_19 ) ;
}
}
static int F_73 ( struct V_60 * V_61 ,
struct V_1 * V_8 ,
struct V_55 * V_78 ,
struct V_55 * V_79 , unsigned int V_70 )
{
int V_34 ;
V_34 = F_74 ( V_61 , & V_8 -> V_4 , V_78 , V_79 ,
& V_80 , NULL ) ;
if ( V_34 )
goto V_81;
F_75 ( & V_8 -> V_4 , & V_82 ) ;
return 0 ;
V_81:
F_14 ( & V_8 -> V_4 ) ;
return V_34 ;
}
void F_76 ( struct V_2 * V_9 , struct V_32 * V_33 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_71 * V_72 = V_9 -> V_11 -> V_73 ;
if ( ! V_72 -> V_76 -> V_77 )
F_57 ( V_9 ) ;
F_9 ( V_8 ) ;
}
int F_77 ( struct V_60 * V_83 ,
const enum V_84 * V_85 , unsigned int V_86 )
{
struct V_71 * V_72 = V_83 -> V_73 ;
struct V_87 * V_11 = V_83 -> V_11 ;
struct V_1 * V_8 ;
enum V_88 type ;
unsigned int V_89 ;
int V_70 = V_72 -> V_90 ;
int V_34 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_86 ; V_15 ++ ) {
enum V_84 V_91 = V_85 [ V_15 ] ;
struct V_92 * V_93 ;
V_93 = V_72 -> V_94 [ V_91 ] ;
if ( ! V_93 ) {
F_78 ( V_11 ,
L_10 ,
V_70 , V_91 ) ;
return 0 ;
}
}
V_8 = F_79 ( V_11 , sizeof( * V_8 ) , V_21 ) ;
if ( ! V_8 )
return - V_95 ;
V_8 -> V_51 = V_72 -> V_51 ;
V_8 -> V_16 = V_86 ;
V_8 -> V_17 = F_80 ( V_11 , V_8 -> V_16 ,
sizeof( * V_8 -> V_17 ) ,
V_21 ) ;
if ( ! V_8 -> V_17 )
return - V_95 ;
V_8 -> V_19 = F_81 ( V_72 -> V_96 , V_70 ) ;
if ( F_82 ( V_8 -> V_19 ) ) {
V_34 = F_83 ( V_8 -> V_19 ) ;
F_84 ( V_11 , L_11 , V_34 ) ;
return V_34 ;
}
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
enum V_84 V_91 = V_85 [ V_15 ] ;
struct V_32 * V_53 ;
struct V_92 * V_93 ;
V_93 = V_72 -> V_94 [ V_91 ] ;
V_53 = V_72 -> V_17 [ V_91 ] ;
if ( ! V_53 ) {
F_84 ( V_11 , L_12 , V_93 ) ;
V_34 = - V_97 ;
goto V_98;
}
V_34 = F_85 ( V_53 -> V_18 ) ;
if ( V_34 ) {
F_84 ( V_11 ,
L_13 ,
V_93 , V_34 ) ;
goto V_98;
}
V_8 -> V_17 [ V_15 ] = V_53 ;
}
for ( V_89 = 0 ; V_89 < V_54 ; V_89 ++ ) {
type = ( V_89 == 0 ) ? V_99 :
( V_89 == 1 ) ? V_100 :
V_101 ;
V_34 = F_86 ( V_83 , & V_8 -> V_57 [ V_89 ] ,
F_69 ( V_70 ) , type ) ;
if ( V_34 )
goto V_98;
}
V_34 = F_73 ( V_83 , V_8 , & V_8 -> V_57 [ 0 ] ,
& V_8 -> V_57 [ 1 ] , V_70 ) ;
if ( V_34 < 0 )
goto V_98;
F_87 ( & V_8 -> V_4 , V_102 ) ;
F_88 ( & V_8 -> V_4 , 0 , false , V_102 ) ;
V_72 -> V_90 ++ ;
return 0 ;
V_98:
while ( -- V_15 >= 0 )
F_12 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_34 ;
}
