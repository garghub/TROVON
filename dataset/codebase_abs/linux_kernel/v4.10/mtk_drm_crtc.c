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
int F_26 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_1 * V_8 = F_1 ( V_36 -> V_9 [ V_34 ] ) ;
struct V_38 * V_39 = V_8 -> V_17 [ 0 ] ;
F_27 ( V_39 , & V_8 -> V_4 ) ;
return 0 ;
}
void F_28 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_1 * V_8 = F_1 ( V_36 -> V_9 [ V_34 ] ) ;
struct V_38 * V_39 = V_8 -> V_17 [ 0 ] ;
F_29 ( V_39 ) ;
}
static int F_30 ( struct V_1 * V_8 )
{
int V_40 ;
int V_15 ;
F_31 ( L_1 , V_41 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
V_40 = F_32 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
if ( V_40 ) {
F_33 ( L_2 , V_15 , V_40 ) ;
goto V_42;
}
}
return 0 ;
V_42:
while ( -- V_15 >= 0 )
F_34 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_40 ;
}
static void F_35 ( struct V_1 * V_8 )
{
int V_15 ;
F_31 ( L_1 , V_41 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_34 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
}
static int F_36 ( struct V_1 * V_8 )
{
struct V_2 * V_9 = & V_8 -> V_4 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
unsigned int V_47 , V_48 , V_30 , V_49 = V_50 ;
int V_40 ;
int V_15 ;
F_31 ( L_1 , V_41 ) ;
if ( F_20 ( ! V_9 -> V_20 ) )
return - V_51 ;
V_47 = V_9 -> V_20 -> V_24 . V_26 ;
V_48 = V_9 -> V_20 -> V_24 . V_28 ;
V_30 = V_9 -> V_20 -> V_24 . V_30 ;
F_37 (encoder, crtc->dev) {
if ( V_46 -> V_9 != V_9 )
continue;
F_38 (connector, crtc->dev) {
if ( V_44 -> V_46 != V_46 )
continue;
if ( V_44 -> V_52 . V_49 != 0 &&
V_49 > V_44 -> V_52 . V_49 )
V_49 = V_44 -> V_52 . V_49 ;
}
}
V_40 = F_39 ( V_9 -> V_11 -> V_11 ) ;
if ( V_40 < 0 ) {
F_33 ( L_3 , V_40 ) ;
return V_40 ;
}
V_40 = F_40 ( V_8 -> V_19 ) ;
if ( V_40 < 0 ) {
F_33 ( L_4 , V_40 ) ;
goto V_53;
}
V_40 = F_30 ( V_8 ) ;
if ( V_40 < 0 ) {
F_33 ( L_5 , V_40 ) ;
goto V_54;
}
F_31 ( L_6 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_41 ( V_8 -> V_55 ,
V_8 -> V_17 [ V_15 ] -> V_56 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_56 ) ;
F_42 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_56 ) ;
}
F_42 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_56 ) ;
F_43 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
struct V_38 * V_57 = V_8 -> V_17 [ V_15 ] ;
F_44 ( V_57 , V_47 , V_48 , V_30 , V_49 ) ;
F_45 ( V_57 ) ;
}
for ( V_15 = 0 ; V_15 < V_58 ; V_15 ++ ) {
struct V_59 * V_60 = & V_8 -> V_61 [ V_15 ] ;
struct V_62 * V_63 ;
V_63 = F_46 ( V_60 -> V_20 ) ;
F_47 ( V_8 -> V_17 [ 0 ] , V_15 ,
V_63 ) ;
}
return 0 ;
V_54:
F_48 ( V_8 -> V_19 ) ;
V_53:
F_49 ( V_9 -> V_11 -> V_11 ) ;
return V_40 ;
}
static void F_50 ( struct V_1 * V_8 )
{
struct V_32 * V_33 = V_8 -> V_4 . V_11 ;
int V_15 ;
F_31 ( L_1 , V_41 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_51 ( V_8 -> V_17 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_52 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_56 ) ;
F_53 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_54 ( V_8 -> V_55 ,
V_8 -> V_17 [ V_15 ] -> V_56 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_56 ) ;
F_52 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_56 ) ;
}
F_52 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_56 ) ;
F_35 ( V_8 ) ;
F_48 ( V_8 -> V_19 ) ;
F_49 ( V_33 -> V_11 ) ;
}
static void F_55 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_38 * V_39 = V_8 -> V_17 [ 0 ] ;
int V_40 ;
F_31 ( L_7 , V_41 , V_9 -> V_4 . V_56 ) ;
V_40 = F_56 ( V_39 -> V_64 ) ;
if ( V_40 ) {
F_33 ( L_8 , V_40 ) ;
return;
}
V_40 = F_36 ( V_8 ) ;
if ( V_40 ) {
F_57 ( V_39 -> V_64 ) ;
return;
}
F_58 ( V_9 ) ;
V_8 -> V_65 = true ;
}
static void F_59 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_38 * V_39 = V_8 -> V_17 [ 0 ] ;
int V_15 ;
F_31 ( L_7 , V_41 , V_9 -> V_4 . V_56 ) ;
if ( ! V_8 -> V_65 )
return;
for ( V_15 = 0 ; V_15 < V_58 ; V_15 ++ ) {
struct V_59 * V_60 = & V_8 -> V_61 [ V_15 ] ;
struct V_62 * V_63 ;
V_63 = F_46 ( V_60 -> V_20 ) ;
V_63 -> V_66 . V_67 = false ;
V_63 -> V_66 . V_68 = true ;
}
V_8 -> V_69 = true ;
F_60 ( V_9 ) ;
F_61 ( V_9 ) ;
F_50 ( V_8 ) ;
F_57 ( V_39 -> V_64 ) ;
V_8 -> V_65 = false ;
}
static void F_62 ( struct V_2 * V_9 ,
struct V_6 * V_70 )
{
struct V_5 * V_20 = F_3 ( V_9 -> V_20 ) ;
struct V_1 * V_8 = F_1 ( V_9 ) ;
if ( V_8 -> V_13 && V_20 -> V_4 . V_13 )
F_33 ( L_9 ) ;
if ( V_20 -> V_4 . V_13 ) {
V_20 -> V_4 . V_13 -> V_34 = F_63 ( V_9 ) ;
F_20 ( F_64 ( V_9 ) != 0 ) ;
V_8 -> V_13 = V_20 -> V_4 . V_13 ;
V_20 -> V_4 . V_13 = NULL ;
}
}
static void F_65 ( struct V_2 * V_9 ,
struct V_6 * V_70 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
unsigned int V_69 = 0 ;
int V_15 ;
if ( V_8 -> V_13 )
V_8 -> V_14 = true ;
for ( V_15 = 0 ; V_15 < V_58 ; V_15 ++ ) {
struct V_59 * V_60 = & V_8 -> V_61 [ V_15 ] ;
struct V_62 * V_63 ;
V_63 = F_46 ( V_60 -> V_20 ) ;
if ( V_63 -> V_66 . V_71 ) {
V_63 -> V_66 . V_68 = true ;
V_63 -> V_66 . V_71 = false ;
V_69 |= F_66 ( V_15 ) ;
}
}
if ( V_69 )
V_8 -> V_69 = true ;
if ( V_9 -> V_20 -> V_72 )
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_67 ( V_8 -> V_17 [ V_15 ] , V_9 -> V_20 ) ;
}
static int F_68 ( struct V_32 * V_33 ,
struct V_1 * V_8 ,
struct V_59 * V_73 ,
struct V_59 * V_74 , unsigned int V_34 )
{
int V_40 ;
V_40 = F_69 ( V_33 , & V_8 -> V_4 , V_73 , V_74 ,
& V_75 , NULL ) ;
if ( V_40 )
goto V_76;
F_70 ( & V_8 -> V_4 , & V_77 ) ;
return 0 ;
V_76:
F_14 ( & V_8 -> V_4 ) ;
return V_40 ;
}
void F_71 ( struct V_2 * V_9 , struct V_38 * V_39 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_5 * V_20 = F_3 ( V_8 -> V_4 . V_20 ) ;
unsigned int V_15 ;
if ( V_20 -> V_31 ) {
F_44 ( V_39 , V_20 -> V_25 ,
V_20 -> V_27 ,
V_20 -> V_29 , 0 ) ;
V_20 -> V_31 = false ;
}
if ( V_8 -> V_69 ) {
for ( V_15 = 0 ; V_15 < V_58 ; V_15 ++ ) {
struct V_59 * V_60 = & V_8 -> V_61 [ V_15 ] ;
struct V_62 * V_63 ;
V_63 = F_46 ( V_60 -> V_20 ) ;
if ( V_63 -> V_66 . V_68 ) {
F_47 ( V_39 , V_15 , V_63 ) ;
V_63 -> V_66 . V_68 = false ;
}
}
V_8 -> V_69 = false ;
}
F_9 ( V_8 ) ;
}
int F_72 ( struct V_32 * V_78 ,
const enum V_79 * V_80 , unsigned int V_81 )
{
struct V_35 * V_36 = V_78 -> V_37 ;
struct V_82 * V_11 = V_78 -> V_11 ;
struct V_1 * V_8 ;
enum V_83 type ;
unsigned int V_84 ;
int V_34 = V_36 -> V_85 ;
int V_40 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_81 ; V_15 ++ ) {
enum V_79 V_86 = V_80 [ V_15 ] ;
struct V_87 * V_88 ;
V_88 = V_36 -> V_89 [ V_86 ] ;
if ( ! V_88 ) {
F_73 ( V_11 ,
L_10 ,
V_34 , V_86 ) ;
return 0 ;
}
}
V_8 = F_74 ( V_11 , sizeof( * V_8 ) , V_21 ) ;
if ( ! V_8 )
return - V_90 ;
V_8 -> V_55 = V_36 -> V_55 ;
V_8 -> V_16 = V_81 ;
V_8 -> V_17 = F_75 ( V_11 , V_8 -> V_16 ,
sizeof( * V_8 -> V_17 ) ,
V_21 ) ;
V_8 -> V_19 = F_76 ( V_36 -> V_91 , V_34 ) ;
if ( F_77 ( V_8 -> V_19 ) ) {
V_40 = F_78 ( V_8 -> V_19 ) ;
F_79 ( V_11 , L_11 , V_40 ) ;
return V_40 ;
}
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
enum V_79 V_86 = V_80 [ V_15 ] ;
struct V_38 * V_57 ;
struct V_87 * V_88 ;
V_88 = V_36 -> V_89 [ V_86 ] ;
V_57 = V_36 -> V_17 [ V_86 ] ;
if ( ! V_57 ) {
F_79 ( V_11 , L_12 ,
V_88 -> V_92 ) ;
V_40 = - V_93 ;
goto V_94;
}
V_40 = F_80 ( V_57 -> V_18 ) ;
if ( V_40 ) {
F_79 ( V_11 ,
L_13 ,
V_88 -> V_92 , V_40 ) ;
goto V_94;
}
V_8 -> V_17 [ V_15 ] = V_57 ;
}
for ( V_84 = 0 ; V_84 < V_58 ; V_84 ++ ) {
type = ( V_84 == 0 ) ? V_95 :
( V_84 == 1 ) ? V_96 :
V_97 ;
V_40 = F_81 ( V_78 , & V_8 -> V_61 [ V_84 ] ,
F_66 ( V_34 ) , type ) ;
if ( V_40 )
goto V_94;
}
V_40 = F_68 ( V_78 , V_8 , & V_8 -> V_61 [ 0 ] ,
& V_8 -> V_61 [ 1 ] , V_34 ) ;
if ( V_40 < 0 )
goto V_94;
F_82 ( & V_8 -> V_4 , V_98 ) ;
F_83 ( & V_8 -> V_4 , 0 , false , V_98 ) ;
V_36 -> V_9 [ V_34 ] = & V_8 -> V_4 ;
V_36 -> V_85 ++ ;
return 0 ;
V_94:
while ( -- V_15 >= 0 )
F_12 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_40 ;
}
