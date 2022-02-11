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
if ( V_9 -> V_20 -> V_21 )
F_16 ( V_9 -> V_20 -> V_21 ) ;
V_20 = F_3 ( V_9 -> V_20 ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
} else {
V_20 = F_17 ( sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 )
return;
V_9 -> V_20 = & V_20 -> V_4 ;
}
V_20 -> V_4 . V_9 = V_9 ;
}
static struct V_6 * F_18 ( struct V_2 * V_9 )
{
struct V_5 * V_20 ;
V_20 = F_17 ( sizeof( * V_20 ) , V_22 ) ;
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
F_22 ( V_20 ) ;
F_23 ( F_3 ( V_20 ) ) ;
}
static bool F_24 ( struct V_2 * V_9 ,
const struct V_23 * V_24 ,
struct V_23 * V_25 )
{
return true ;
}
static void F_25 ( struct V_2 * V_9 )
{
struct V_5 * V_20 = F_3 ( V_9 -> V_20 ) ;
V_20 -> V_26 = V_9 -> V_24 . V_27 ;
V_20 -> V_28 = V_9 -> V_24 . V_29 ;
V_20 -> V_30 = V_9 -> V_24 . V_31 ;
F_26 () ;
V_20 -> V_32 = true ;
}
int F_27 ( struct V_33 * V_34 , unsigned int V_35 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_1 * V_8 = F_1 ( V_37 -> V_9 [ V_35 ] ) ;
struct V_39 * V_40 = V_8 -> V_17 [ 0 ] ;
F_28 ( V_40 , & V_8 -> V_4 ) ;
return 0 ;
}
void F_29 ( struct V_33 * V_34 , unsigned int V_35 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_1 * V_8 = F_1 ( V_37 -> V_9 [ V_35 ] ) ;
struct V_39 * V_40 = V_8 -> V_17 [ 0 ] ;
F_30 ( V_40 ) ;
}
static int F_31 ( struct V_1 * V_8 )
{
int V_41 ;
int V_15 ;
F_32 ( L_1 , V_42 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
V_41 = F_33 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
if ( V_41 ) {
F_34 ( L_2 , V_15 , V_41 ) ;
goto V_43;
}
}
return 0 ;
V_43:
while ( -- V_15 >= 0 )
F_35 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_41 ;
}
static void F_36 ( struct V_1 * V_8 )
{
int V_15 ;
F_32 ( L_1 , V_42 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_35 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
}
static int F_37 ( struct V_1 * V_8 )
{
struct V_2 * V_9 = & V_8 -> V_4 ;
unsigned int V_44 , V_45 , V_31 ;
int V_41 ;
int V_15 ;
F_32 ( L_1 , V_42 ) ;
if ( F_20 ( ! V_9 -> V_20 ) )
return - V_46 ;
V_44 = V_9 -> V_20 -> V_25 . V_27 ;
V_45 = V_9 -> V_20 -> V_25 . V_29 ;
V_31 = V_9 -> V_20 -> V_25 . V_31 ;
V_41 = F_38 ( V_9 -> V_11 -> V_11 ) ;
if ( V_41 < 0 ) {
F_34 ( L_3 , V_41 ) ;
return V_41 ;
}
V_41 = F_39 ( V_8 -> V_19 ) ;
if ( V_41 < 0 ) {
F_34 ( L_4 , V_41 ) ;
goto V_47;
}
V_41 = F_31 ( V_8 ) ;
if ( V_41 < 0 ) {
F_34 ( L_5 , V_41 ) ;
goto V_48;
}
F_32 ( L_6 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_40 ( V_8 -> V_49 ,
V_8 -> V_17 [ V_15 ] -> V_50 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_50 ) ;
F_41 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_50 ) ;
}
F_41 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_50 ) ;
F_42 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
struct V_39 * V_51 = V_8 -> V_17 [ V_15 ] ;
F_43 ( V_51 , V_44 , V_45 , V_31 ) ;
F_44 ( V_51 ) ;
}
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
struct V_53 * V_54 = & V_8 -> V_55 [ V_15 ] . V_4 ;
struct V_56 * V_57 ;
V_57 = F_45 ( V_54 -> V_20 ) ;
F_46 ( V_8 -> V_17 [ 0 ] , V_15 ,
V_57 ) ;
}
return 0 ;
V_48:
F_47 ( V_8 -> V_19 ) ;
V_47:
F_48 ( V_9 -> V_11 -> V_11 ) ;
return V_41 ;
}
static void F_49 ( struct V_1 * V_8 )
{
struct V_33 * V_34 = V_8 -> V_4 . V_11 ;
int V_15 ;
F_32 ( L_1 , V_42 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_50 ( V_8 -> V_17 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
F_51 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_50 ) ;
F_52 ( V_8 -> V_19 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 - 1 ; V_15 ++ ) {
F_53 ( V_8 -> V_49 ,
V_8 -> V_17 [ V_15 ] -> V_50 ,
V_8 -> V_17 [ V_15 + 1 ] -> V_50 ) ;
F_51 ( V_8 -> V_19 ,
V_8 -> V_17 [ V_15 ] -> V_50 ) ;
}
F_51 ( V_8 -> V_19 , V_8 -> V_17 [ V_15 ] -> V_50 ) ;
F_36 ( V_8 ) ;
F_47 ( V_8 -> V_19 ) ;
F_48 ( V_34 -> V_11 ) ;
}
static void F_54 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_39 * V_40 = V_8 -> V_17 [ 0 ] ;
int V_41 ;
F_32 ( L_7 , V_42 , V_9 -> V_4 . V_50 ) ;
V_41 = F_55 ( V_40 -> V_58 ) ;
if ( V_41 ) {
F_34 ( L_8 , V_41 ) ;
return;
}
V_41 = F_37 ( V_8 ) ;
if ( V_41 ) {
F_56 ( V_40 -> V_58 ) ;
return;
}
F_57 ( V_9 ) ;
V_8 -> V_59 = true ;
}
static void F_58 ( struct V_2 * V_9 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_39 * V_40 = V_8 -> V_17 [ 0 ] ;
int V_15 ;
F_32 ( L_7 , V_42 , V_9 -> V_4 . V_50 ) ;
if ( ! V_8 -> V_59 )
return;
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
struct V_53 * V_54 = & V_8 -> V_55 [ V_15 ] . V_4 ;
struct V_56 * V_57 ;
V_57 = F_45 ( V_54 -> V_20 ) ;
V_57 -> V_60 . V_61 = false ;
V_57 -> V_60 . V_62 = true ;
}
V_8 -> V_63 = true ;
F_59 ( V_9 ) ;
F_60 ( V_9 ) ;
F_49 ( V_8 ) ;
F_56 ( V_40 -> V_58 ) ;
V_8 -> V_59 = false ;
}
static void F_61 ( struct V_2 * V_9 ,
struct V_6 * V_64 )
{
struct V_5 * V_20 = F_3 ( V_9 -> V_20 ) ;
struct V_1 * V_8 = F_1 ( V_9 ) ;
if ( V_8 -> V_13 && V_20 -> V_4 . V_13 )
F_34 ( L_9 ) ;
if ( V_20 -> V_4 . V_13 ) {
V_20 -> V_4 . V_13 -> V_35 = F_62 ( V_9 ) ;
F_20 ( F_63 ( V_9 ) != 0 ) ;
V_8 -> V_13 = V_20 -> V_4 . V_13 ;
V_20 -> V_4 . V_13 = NULL ;
}
}
static void F_64 ( struct V_2 * V_9 ,
struct V_6 * V_64 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
unsigned int V_63 = 0 ;
int V_15 ;
if ( V_8 -> V_13 )
V_8 -> V_14 = true ;
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
struct V_53 * V_54 = & V_8 -> V_55 [ V_15 ] . V_4 ;
struct V_56 * V_57 ;
V_57 = F_45 ( V_54 -> V_20 ) ;
if ( V_57 -> V_60 . V_65 ) {
V_57 -> V_60 . V_62 = true ;
V_57 -> V_60 . V_65 = false ;
V_63 |= F_65 ( V_15 ) ;
}
}
if ( V_63 )
V_8 -> V_63 = true ;
}
static int F_66 ( struct V_33 * V_34 ,
struct V_1 * V_8 ,
struct V_53 * V_66 ,
struct V_53 * V_67 , unsigned int V_35 )
{
int V_41 ;
V_41 = F_67 ( V_34 , & V_8 -> V_4 , V_66 , V_67 ,
& V_68 , NULL ) ;
if ( V_41 )
goto V_69;
F_68 ( & V_8 -> V_4 , & V_70 ) ;
return 0 ;
V_69:
F_14 ( & V_8 -> V_4 ) ;
return V_41 ;
}
void F_69 ( struct V_2 * V_9 , struct V_39 * V_40 )
{
struct V_1 * V_8 = F_1 ( V_9 ) ;
struct V_5 * V_20 = F_3 ( V_8 -> V_4 . V_20 ) ;
unsigned int V_15 ;
if ( V_20 -> V_32 ) {
F_43 ( V_40 , V_20 -> V_26 ,
V_20 -> V_28 ,
V_20 -> V_30 ) ;
V_20 -> V_32 = false ;
}
if ( V_8 -> V_63 ) {
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
struct V_53 * V_54 = & V_8 -> V_55 [ V_15 ] . V_4 ;
struct V_56 * V_57 ;
V_57 = F_45 ( V_54 -> V_20 ) ;
if ( V_57 -> V_60 . V_62 ) {
F_46 ( V_40 , V_15 , V_57 ) ;
V_57 -> V_60 . V_62 = false ;
}
}
V_8 -> V_63 = false ;
}
F_9 ( V_8 ) ;
}
int F_70 ( struct V_33 * V_71 ,
const enum V_72 * V_73 , unsigned int V_74 )
{
struct V_36 * V_37 = V_71 -> V_38 ;
struct V_75 * V_11 = V_71 -> V_11 ;
struct V_1 * V_8 ;
enum V_76 type ;
unsigned int V_77 ;
int V_35 = V_37 -> V_78 ;
int V_41 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_74 ; V_15 ++ ) {
enum V_72 V_79 = V_73 [ V_15 ] ;
struct V_80 * V_81 ;
V_81 = V_37 -> V_82 [ V_79 ] ;
if ( ! V_81 ) {
F_71 ( V_11 ,
L_10 ,
V_35 , V_79 ) ;
return 0 ;
}
}
V_8 = F_72 ( V_11 , sizeof( * V_8 ) , V_22 ) ;
if ( ! V_8 )
return - V_83 ;
V_8 -> V_49 = V_37 -> V_49 ;
V_8 -> V_16 = V_74 ;
V_8 -> V_17 = F_73 ( V_11 , V_8 -> V_16 ,
sizeof( * V_8 -> V_17 ) ,
V_22 ) ;
V_8 -> V_19 = F_74 ( V_37 -> V_84 , V_35 ) ;
if ( F_75 ( V_8 -> V_19 ) ) {
V_41 = F_76 ( V_8 -> V_19 ) ;
F_77 ( V_11 , L_11 , V_41 ) ;
return V_41 ;
}
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ ) {
enum V_72 V_79 = V_73 [ V_15 ] ;
struct V_39 * V_51 ;
struct V_80 * V_81 ;
V_81 = V_37 -> V_82 [ V_79 ] ;
V_51 = V_37 -> V_17 [ V_79 ] ;
if ( ! V_51 ) {
F_77 ( V_11 , L_12 ,
V_81 -> V_85 ) ;
V_41 = - V_86 ;
goto V_87;
}
V_41 = F_78 ( V_51 -> V_18 ) ;
if ( V_41 ) {
F_77 ( V_11 ,
L_13 ,
V_81 -> V_85 , V_41 ) ;
goto V_87;
}
V_8 -> V_17 [ V_15 ] = V_51 ;
}
for ( V_77 = 0 ; V_77 < V_52 ; V_77 ++ ) {
type = ( V_77 == 0 ) ? V_88 :
( V_77 == 1 ) ? V_89 :
V_90 ;
V_41 = F_79 ( V_71 , & V_8 -> V_55 [ V_77 ] ,
F_65 ( V_35 ) , type , V_77 ) ;
if ( V_41 )
goto V_87;
}
V_41 = F_66 ( V_71 , V_8 , & V_8 -> V_55 [ 0 ] . V_4 ,
& V_8 -> V_55 [ 1 ] . V_4 , V_35 ) ;
if ( V_41 < 0 )
goto V_87;
V_37 -> V_9 [ V_35 ] = & V_8 -> V_4 ;
V_37 -> V_78 ++ ;
return 0 ;
V_87:
while ( -- V_15 >= 0 )
F_12 ( V_8 -> V_17 [ V_15 ] -> V_18 ) ;
return V_41 ;
}
