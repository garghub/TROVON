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
struct V_2 * V_9 = F_27 ( V_33 , V_34 ) ;
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_35 * V_36 = V_8 -> V_17 [ 0 ] ;
F_28 ( V_36 , & V_8 -> V_4 ) ;
return 0 ;
}
void F_29 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_2 * V_9 = F_27 ( V_33 , V_34 ) ;
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_35 * V_36 = V_8 -> V_17 [ 0 ] ;
F_30 ( V_36 ) ;
}
static int F_31 ( struct V_1 * V_8 )
{
int V_37 ;
int V_15 ;
F_32 ( L_1 , V_38 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
V_37 = F_33 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
if ( V_37 ) {
F_34 ( L_2 , V_15 , V_37 ) ;
goto V_39;
}
}
return 0 ;
V_39:
while ( -- V_15 >= 0 )
F_35 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_37 ;
}
static void F_36 ( struct V_1 * V_8 )
{
int V_15 ;
F_32 ( L_1 , V_38 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_35 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
}
static int F_37 ( struct V_1 * V_8 )
{
struct V_2 * V_9 = & V_8 -> V_4 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
unsigned int V_44 , V_45 , V_30 , V_46 = V_47 ;
int V_37 ;
int V_15 ;
F_32 ( L_1 , V_38 ) ;
if ( F_20 ( ! V_9 -> V_20 ) )
return - V_48 ;
V_44 = V_9 -> V_20 -> V_24 . V_26 ;
V_45 = V_9 -> V_20 -> V_24 . V_28 ;
V_30 = V_9 -> V_20 -> V_24 . V_30 ;
F_38 (encoder, crtc->dev) {
if ( V_43 -> V_9 != V_9 )
continue;
F_39 (connector, crtc->dev) {
if ( V_41 -> V_43 != V_43 )
continue;
if ( V_41 -> V_49 . V_46 != 0 &&
V_46 > V_41 -> V_49 . V_46 )
V_46 = V_41 -> V_49 . V_46 ;
}
}
V_37 = F_40 ( V_9 -> V_11 -> V_11 ) ;
if ( V_37 < 0 ) {
F_34 ( L_3 , V_37 ) ;
return V_37 ;
}
V_37 = F_41 ( V_8 -> V_19 ) ;
if ( V_37 < 0 ) {
F_34 ( L_4 , V_37 ) ;
goto V_50;
}
V_37 = F_31 ( V_8 ) ;
if ( V_37 < 0 ) {
F_34 ( L_5 , V_37 ) ;
goto V_51;
}
F_32 ( L_6 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_42 ( V_8 -> V_52 ,
V_8 -> V_17 [ V_15 ] -> V_53 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_53 ) ;
F_43 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_53 ) ;
}
F_43 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_53 ) ;
F_44 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
struct V_35 * V_54 = V_8 -> V_17 [ V_15 ] ;
F_45 ( V_54 , V_44 , V_45 , V_30 , V_46 ) ;
F_46 ( V_54 ) ;
}
for ( V_15 = 0 ; V_15 < V_55 ; V_15 ++ ) {
struct V_56 * V_57 = & V_8 -> V_58 [ V_15 ] ;
struct V_59 * V_60 ;
V_60 = F_47 ( V_57 -> V_20 ) ;
F_48 ( V_8 -> V_17 [ 0 ] , V_15 ,
V_60 ) ;
}
return 0 ;
V_51:
F_49 ( V_8 -> V_19 ) ;
V_50:
F_50 ( V_9 -> V_11 -> V_11 ) ;
return V_37 ;
}
static void F_51 ( struct V_1 * V_8 )
{
struct V_32 * V_33 = V_8 -> V_4 . V_11 ;
int V_15 ;
F_32 ( L_1 , V_38 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_52 ( V_8 -> V_17 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_53 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_53 ) ;
F_54 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_55 ( V_8 -> V_52 ,
V_8 -> V_17 [ V_15 ] -> V_53 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_53 ) ;
F_53 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_53 ) ;
}
F_53 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_53 ) ;
F_36 ( V_8 ) ;
F_49 ( V_8 -> V_19 ) ;
F_50 ( V_33 -> V_11 ) ;
}
static void F_56 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_35 * V_36 = V_8 -> V_17 [ 0 ] ;
int V_37 ;
F_32 ( L_7 , V_38 , V_9 -> V_4 . V_53 ) ;
V_37 = F_57 ( V_36 -> V_61 ) ;
if ( V_37 ) {
F_34 ( L_8 , V_37 ) ;
return;
}
V_37 = F_37 ( V_8 ) ;
if ( V_37 ) {
F_58 ( V_36 -> V_61 ) ;
return;
}
F_59 ( V_9 ) ;
V_8 -> V_62 = true ;
}
static void F_60 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_35 * V_36 = V_8 -> V_17 [ 0 ] ;
int V_15 ;
F_32 ( L_7 , V_38 , V_9 -> V_4 . V_53 ) ;
if ( ! V_8 -> V_62 )
return;
for ( V_15 = 0 ; V_15 < V_55 ; V_15 ++ ) {
struct V_56 * V_57 = & V_8 -> V_58 [ V_15 ] ;
struct V_59 * V_60 ;
V_60 = F_47 ( V_57 -> V_20 ) ;
V_60 -> V_63 . V_64 = false ;
V_60 -> V_63 . V_65 = true ;
}
V_8 -> V_66 = true ;
F_61 ( V_9 ) ;
F_62 ( V_9 ) ;
F_51 ( V_8 ) ;
F_58 ( V_36 -> V_61 ) ;
V_8 -> V_62 = false ;
}
static void F_63 ( struct V_2 * V_9 ,
struct V_6 * V_67 )
{
struct V_5 * V_20 = F_3 ( V_9 -> V_20 ) ;
struct V_1 * V_8 = F_1 ( V_9 ) ;
if ( V_8 -> V_13 && V_20 -> V_4 . V_13 )
F_34 ( L_9 ) ;
if ( V_20 -> V_4 . V_13 ) {
V_20 -> V_4 . V_13 -> V_34 = F_64 ( V_9 ) ;
F_20 ( F_65 ( V_9 ) != 0 ) ;
V_8 -> V_13 = V_20 -> V_4 . V_13 ;
V_20 -> V_4 . V_13 = NULL ;
}
}
static void F_66 ( struct V_2 * V_9 ,
struct V_6 * V_67 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
unsigned int V_66 = 0 ;
int V_15 ;
if ( V_8 -> V_13 )
V_8 -> V_14 = true ;
for ( V_15 = 0 ; V_15 < V_55 ; V_15 ++ ) {
struct V_56 * V_57 = & V_8 -> V_58 [ V_15 ] ;
struct V_59 * V_60 ;
V_60 = F_47 ( V_57 -> V_20 ) ;
if ( V_60 -> V_63 . V_68 ) {
V_60 -> V_63 . V_65 = true ;
V_60 -> V_63 . V_68 = false ;
V_66 |= F_67 ( V_15 ) ;
}
}
if ( V_66 )
V_8 -> V_66 = true ;
if ( V_9 -> V_20 -> V_69 )
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_68 ( V_8 -> V_17 [ V_15 ] , V_9 -> V_20 ) ;
}
static int F_69 ( struct V_32 * V_33 ,
struct V_1 * V_8 ,
struct V_56 * V_70 ,
struct V_56 * V_71 , unsigned int V_34 )
{
int V_37 ;
V_37 = F_70 ( V_33 , & V_8 -> V_4 , V_70 , V_71 ,
& V_72 , NULL ) ;
if ( V_37 )
goto V_73;
F_71 ( & V_8 -> V_4 , & V_74 ) ;
return 0 ;
V_73:
F_14 ( & V_8 -> V_4 ) ;
return V_37 ;
}
void F_72 ( struct V_2 * V_9 , struct V_35 * V_36 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_5 * V_20 = F_3 ( V_8 -> V_4 . V_20 ) ;
unsigned int V_15 ;
if ( V_20 -> V_31 ) {
F_45 ( V_36 , V_20 -> V_25 ,
V_20 -> V_27 ,
V_20 -> V_29 , 0 ) ;
V_20 -> V_31 = false ;
}
if ( V_8 -> V_66 ) {
for ( V_15 = 0 ; V_15 < V_55 ; V_15 ++ ) {
struct V_56 * V_57 = & V_8 -> V_58 [ V_15 ] ;
struct V_59 * V_60 ;
V_60 = F_47 ( V_57 -> V_20 ) ;
if ( V_60 -> V_63 . V_65 ) {
F_48 ( V_36 , V_15 , V_60 ) ;
V_60 -> V_63 . V_65 = false ;
}
}
V_8 -> V_66 = false ;
}
F_9 ( V_8 ) ;
}
int F_73 ( struct V_32 * V_75 ,
const enum V_76 * V_77 , unsigned int V_78 )
{
struct V_79 * V_80 = V_75 -> V_81 ;
struct V_82 * V_11 = V_75 -> V_11 ;
struct V_1 * V_8 ;
enum V_83 type ;
unsigned int V_84 ;
int V_34 = V_80 -> V_85 ;
int V_37 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_78 ; V_15 ++ ) {
enum V_76 V_86 = V_77 [ V_15 ] ;
struct V_87 * V_88 ;
V_88 = V_80 -> V_89 [ V_86 ] ;
if ( ! V_88 ) {
F_74 ( V_11 ,
L_10 ,
V_34 , V_86 ) ;
return 0 ;
}
}
V_8 = F_75 ( V_11 , sizeof( * V_8 ) , V_21 ) ;
if ( ! V_8 )
return - V_90 ;
V_8 -> V_52 = V_80 -> V_52 ;
V_8 -> V_16 = V_78 ;
V_8 -> V_17 = F_76 ( V_11 , V_8 -> V_16 ,
sizeof( * V_8 -> V_17 ) ,
V_21 ) ;
V_8 -> V_19 = F_77 ( V_80 -> V_91 , V_34 ) ;
if ( F_78 ( V_8 -> V_19 ) ) {
V_37 = F_79 ( V_8 -> V_19 ) ;
F_80 ( V_11 , L_11 , V_37 ) ;
return V_37 ;
}
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
enum V_76 V_86 = V_77 [ V_15 ] ;
struct V_35 * V_54 ;
struct V_87 * V_88 ;
V_88 = V_80 -> V_89 [ V_86 ] ;
V_54 = V_80 -> V_17 [ V_86 ] ;
if ( ! V_54 ) {
F_80 ( V_11 , L_12 ,
V_88 -> V_92 ) ;
V_37 = - V_93 ;
goto V_94;
}
V_37 = F_81 ( V_54 -> V_18 ) ;
if ( V_37 ) {
F_80 ( V_11 ,
L_13 ,
V_88 -> V_92 , V_37 ) ;
goto V_94;
}
V_8 -> V_17 [ V_15 ] = V_54 ;
}
for ( V_84 = 0 ; V_84 < V_55 ; V_84 ++ ) {
type = ( V_84 == 0 ) ? V_95 :
( V_84 == 1 ) ? V_96 :
V_97 ;
V_37 = F_82 ( V_75 , & V_8 -> V_58 [ V_84 ] ,
F_67 ( V_34 ) , type ) ;
if ( V_37 )
goto V_94;
}
V_37 = F_69 ( V_75 , V_8 , & V_8 -> V_58 [ 0 ] ,
& V_8 -> V_58 [ 1 ] , V_34 ) ;
if ( V_37 < 0 )
goto V_94;
F_83 ( & V_8 -> V_4 , V_98 ) ;
F_84 ( & V_8 -> V_4 , 0 , false , V_98 ) ;
V_80 -> V_85 ++ ;
return 0 ;
V_94:
while ( -- V_15 >= 0 )
F_12 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_37 ;
}
