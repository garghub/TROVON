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
unsigned int V_41 , V_42 , V_30 , V_43 = V_44 ;
int V_34 ;
int V_15 ;
F_31 ( L_1 , V_35 ) ;
if ( F_20 ( ! V_9 -> V_20 ) )
return - V_45 ;
V_41 = V_9 -> V_20 -> V_24 . V_26 ;
V_42 = V_9 -> V_20 -> V_24 . V_28 ;
V_30 = V_9 -> V_20 -> V_24 . V_30 ;
F_37 (encoder, crtc->dev) {
if ( V_40 -> V_9 != V_9 )
continue;
F_38 (connector, crtc->dev) {
if ( V_38 -> V_40 != V_40 )
continue;
if ( V_38 -> V_46 . V_43 != 0 &&
V_43 > V_38 -> V_46 . V_43 )
V_43 = V_38 -> V_46 . V_43 ;
}
}
V_34 = F_39 ( V_9 -> V_11 -> V_11 ) ;
if ( V_34 < 0 ) {
F_33 ( L_3 , V_34 ) ;
return V_34 ;
}
V_34 = F_40 ( V_8 -> V_19 ) ;
if ( V_34 < 0 ) {
F_33 ( L_4 , V_34 ) ;
goto V_47;
}
V_34 = F_30 ( V_8 ) ;
if ( V_34 < 0 ) {
F_33 ( L_5 , V_34 ) ;
goto V_48;
}
F_31 ( L_6 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_41 ( V_8 -> V_49 ,
V_8 -> V_17 [ V_15 ] -> V_50 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_50 ) ;
F_42 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_50 ) ;
}
F_42 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_50 ) ;
F_43 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
struct V_32 * V_51 = V_8 -> V_17 [ V_15 ] ;
F_44 ( V_51 , V_41 , V_42 , V_30 , V_43 ) ;
F_45 ( V_51 ) ;
}
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
struct V_53 * V_54 = & V_8 -> V_55 [ V_15 ] ;
struct V_56 * V_57 ;
V_57 = F_46 ( V_54 -> V_20 ) ;
F_47 ( V_8 -> V_17 [ 0 ] , V_15 ,
V_57 ) ;
}
return 0 ;
V_48:
F_48 ( V_8 -> V_19 ) ;
V_47:
F_49 ( V_9 -> V_11 -> V_11 ) ;
return V_34 ;
}
static void F_50 ( struct V_1 * V_8 )
{
struct V_58 * V_59 = V_8 -> V_4 . V_11 ;
int V_15 ;
F_31 ( L_1 , V_35 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_51 ( V_8 -> V_17 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_52 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_50 ) ;
F_53 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_54 ( V_8 -> V_49 ,
V_8 -> V_17 [ V_15 ] -> V_50 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_50 ) ;
F_52 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_50 ) ;
}
F_52 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_50 ) ;
F_35 ( V_8 ) ;
F_48 ( V_8 -> V_19 ) ;
F_49 ( V_59 -> V_11 ) ;
}
static void F_55 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_5 * V_20 = F_3 ( V_8 -> V_4 . V_20 ) ;
struct V_32 * V_33 = V_8 -> V_17 [ 0 ] ;
unsigned int V_15 ;
if ( V_20 -> V_31 ) {
F_44 ( V_33 , V_20 -> V_25 ,
V_20 -> V_27 ,
V_20 -> V_29 , 0 ) ;
V_20 -> V_31 = false ;
}
if ( V_8 -> V_60 ) {
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
struct V_53 * V_54 = & V_8 -> V_55 [ V_15 ] ;
struct V_56 * V_57 ;
V_57 = F_46 ( V_54 -> V_20 ) ;
if ( V_57 -> V_61 . V_62 ) {
F_47 ( V_33 , V_15 , V_57 ) ;
V_57 -> V_61 . V_62 = false ;
}
}
V_8 -> V_60 = false ;
}
}
static void F_56 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_32 * V_33 = V_8 -> V_17 [ 0 ] ;
int V_34 ;
F_31 ( L_7 , V_35 , V_9 -> V_4 . V_50 ) ;
V_34 = F_57 ( V_33 -> V_63 ) ;
if ( V_34 ) {
F_33 ( L_8 , V_34 ) ;
return;
}
V_34 = F_36 ( V_8 ) ;
if ( V_34 ) {
F_58 ( V_33 -> V_63 ) ;
return;
}
F_59 ( V_9 ) ;
V_8 -> V_64 = true ;
}
static void F_60 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_32 * V_33 = V_8 -> V_17 [ 0 ] ;
int V_15 ;
F_31 ( L_7 , V_35 , V_9 -> V_4 . V_50 ) ;
if ( ! V_8 -> V_64 )
return;
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
struct V_53 * V_54 = & V_8 -> V_55 [ V_15 ] ;
struct V_56 * V_57 ;
V_57 = F_46 ( V_54 -> V_20 ) ;
V_57 -> V_61 . V_65 = false ;
V_57 -> V_61 . V_62 = true ;
}
V_8 -> V_60 = true ;
F_61 ( V_9 ) ;
F_62 ( V_9 ) ;
F_50 ( V_8 ) ;
F_58 ( V_33 -> V_63 ) ;
V_8 -> V_64 = false ;
}
static void F_63 ( struct V_2 * V_9 ,
struct V_6 * V_66 )
{
struct V_5 * V_20 = F_3 ( V_9 -> V_20 ) ;
struct V_1 * V_8 = F_1 ( V_9 ) ;
if ( V_8 -> V_13 && V_20 -> V_4 . V_13 )
F_33 ( L_9 ) ;
if ( V_20 -> V_4 . V_13 ) {
V_20 -> V_4 . V_13 -> V_67 = F_64 ( V_9 ) ;
F_20 ( F_65 ( V_9 ) != 0 ) ;
V_8 -> V_13 = V_20 -> V_4 . V_13 ;
V_20 -> V_4 . V_13 = NULL ;
}
}
static void F_66 ( struct V_2 * V_9 ,
struct V_6 * V_66 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_68 * V_69 = V_9 -> V_11 -> V_70 ;
unsigned int V_60 = 0 ;
int V_15 ;
if ( V_8 -> V_13 )
V_8 -> V_14 = true ;
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
struct V_53 * V_54 = & V_8 -> V_55 [ V_15 ] ;
struct V_56 * V_57 ;
V_57 = F_46 ( V_54 -> V_20 ) ;
if ( V_57 -> V_61 . V_71 ) {
V_57 -> V_61 . V_62 = true ;
V_57 -> V_61 . V_71 = false ;
V_60 |= F_67 ( V_15 ) ;
}
}
if ( V_60 )
V_8 -> V_60 = true ;
if ( V_9 -> V_20 -> V_72 )
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_68 ( V_8 -> V_17 [ V_15 ] , V_9 -> V_20 ) ;
if ( V_69 -> V_73 -> V_74 ) {
F_69 ( V_8 -> V_19 ) ;
F_55 ( V_9 ) ;
F_70 ( V_8 -> V_19 ) ;
}
}
static int F_71 ( struct V_58 * V_59 ,
struct V_1 * V_8 ,
struct V_53 * V_75 ,
struct V_53 * V_76 , unsigned int V_67 )
{
int V_34 ;
V_34 = F_72 ( V_59 , & V_8 -> V_4 , V_75 , V_76 ,
& V_77 , NULL ) ;
if ( V_34 )
goto V_78;
F_73 ( & V_8 -> V_4 , & V_79 ) ;
return 0 ;
V_78:
F_14 ( & V_8 -> V_4 ) ;
return V_34 ;
}
void F_74 ( struct V_2 * V_9 , struct V_32 * V_33 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_68 * V_69 = V_9 -> V_11 -> V_70 ;
if ( ! V_69 -> V_73 -> V_74 )
F_55 ( V_9 ) ;
F_9 ( V_8 ) ;
}
int F_75 ( struct V_58 * V_80 ,
const enum V_81 * V_82 , unsigned int V_83 )
{
struct V_68 * V_69 = V_80 -> V_70 ;
struct V_84 * V_11 = V_80 -> V_11 ;
struct V_1 * V_8 ;
enum V_85 type ;
unsigned int V_86 ;
int V_67 = V_69 -> V_87 ;
int V_34 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_83 ; V_15 ++ ) {
enum V_81 V_88 = V_82 [ V_15 ] ;
struct V_89 * V_90 ;
V_90 = V_69 -> V_91 [ V_88 ] ;
if ( ! V_90 ) {
F_76 ( V_11 ,
L_10 ,
V_67 , V_88 ) ;
return 0 ;
}
}
V_8 = F_77 ( V_11 , sizeof( * V_8 ) , V_21 ) ;
if ( ! V_8 )
return - V_92 ;
V_8 -> V_49 = V_69 -> V_49 ;
V_8 -> V_16 = V_83 ;
V_8 -> V_17 = F_78 ( V_11 , V_8 -> V_16 ,
sizeof( * V_8 -> V_17 ) ,
V_21 ) ;
V_8 -> V_19 = F_79 ( V_69 -> V_93 , V_67 ) ;
if ( F_80 ( V_8 -> V_19 ) ) {
V_34 = F_81 ( V_8 -> V_19 ) ;
F_82 ( V_11 , L_11 , V_34 ) ;
return V_34 ;
}
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
enum V_81 V_88 = V_82 [ V_15 ] ;
struct V_32 * V_51 ;
struct V_89 * V_90 ;
V_90 = V_69 -> V_91 [ V_88 ] ;
V_51 = V_69 -> V_17 [ V_88 ] ;
if ( ! V_51 ) {
F_82 ( V_11 , L_12 ,
V_90 -> V_94 ) ;
V_34 = - V_95 ;
goto V_96;
}
V_34 = F_83 ( V_51 -> V_18 ) ;
if ( V_34 ) {
F_82 ( V_11 ,
L_13 ,
V_90 -> V_94 , V_34 ) ;
goto V_96;
}
V_8 -> V_17 [ V_15 ] = V_51 ;
}
for ( V_86 = 0 ; V_86 < V_52 ; V_86 ++ ) {
type = ( V_86 == 0 ) ? V_97 :
( V_86 == 1 ) ? V_98 :
V_99 ;
V_34 = F_84 ( V_80 , & V_8 -> V_55 [ V_86 ] ,
F_67 ( V_67 ) , type ) ;
if ( V_34 )
goto V_96;
}
V_34 = F_71 ( V_80 , V_8 , & V_8 -> V_55 [ 0 ] ,
& V_8 -> V_55 [ 1 ] , V_67 ) ;
if ( V_34 < 0 )
goto V_96;
F_85 ( & V_8 -> V_4 , V_100 ) ;
F_86 ( & V_8 -> V_4 , 0 , false , V_100 ) ;
V_69 -> V_87 ++ ;
return 0 ;
V_96:
while ( -- V_15 >= 0 )
F_12 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_34 ;
}
