static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_7 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_9 [ V_8 ] . V_10 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_8 ,
const unsigned * * V_11 , unsigned * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_11 = V_4 -> V_5 -> V_6 -> V_9 [ V_8 ] . V_11 ;
* V_12 = V_4 -> V_5 -> V_6 -> V_9 [ V_8 ] . V_13 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_14 * V_15 ,
unsigned V_16 )
{
F_6 ( V_15 , L_1 , V_17 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_18 ;
}
static const char * F_8 ( struct V_1 * V_2 ,
unsigned V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_19 [ V_8 ] . V_10 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_8 ,
const char * const * * V_9 ,
unsigned * const V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_5 -> V_6 -> V_19 [ V_8 ] . V_9 ;
* V_20 = V_4 -> V_5 -> V_6 -> V_19 [ V_8 ] . V_7 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_8 ,
unsigned V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_5 = V_4 -> V_5 ;
const struct V_23 * V_24 = & V_5 -> V_6 -> V_9 [ V_21 ] ;
unsigned long V_25 ;
unsigned int V_26 ;
int V_27 = 0 ;
F_11 ( & V_5 -> V_28 , V_25 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_13 ; ++ V_26 ) {
int V_29 = F_12 ( V_5 , V_24 -> V_11 [ V_26 ] ) ;
struct V_30 * V_31 = & V_4 -> V_32 [ V_29 ] ;
if ( V_31 -> type != V_33 ) {
V_27 = - V_34 ;
goto V_35;
}
}
for ( V_26 = 0 ; V_26 < V_24 -> V_13 ; ++ V_26 ) {
V_27 = F_13 ( V_5 , V_24 -> V_36 [ V_26 ] , V_37 ) ;
if ( V_27 < 0 )
break;
}
V_35:
F_14 ( & V_5 -> V_28 , V_25 ) ;
return V_27 ;
}
static void F_15 ( struct V_1 * V_2 , unsigned V_8 ,
unsigned V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_5 = V_4 -> V_5 ;
const struct V_23 * V_24 = & V_5 -> V_6 -> V_9 [ V_21 ] ;
unsigned long V_25 ;
unsigned int V_26 ;
F_11 ( & V_5 -> V_28 , V_25 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_13 ; ++ V_26 ) {
int V_29 = F_12 ( V_5 , V_24 -> V_11 [ V_26 ] ) ;
struct V_30 * V_31 = & V_4 -> V_32 [ V_29 ] ;
V_31 -> type = V_33 ;
}
F_14 ( & V_5 -> V_28 , V_25 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
unsigned V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_5 = V_4 -> V_5 ;
int V_29 = F_12 ( V_5 , V_16 ) ;
struct V_30 * V_31 = & V_4 -> V_32 [ V_29 ] ;
unsigned long V_25 ;
int V_27 ;
F_11 ( & V_5 -> V_28 , V_25 ) ;
if ( V_31 -> type != V_33 ) {
F_17 ( V_5 -> V_40 ,
L_2 ,
V_16 ) ;
V_27 = - V_34 ;
goto V_35;
}
if ( ! V_5 -> V_41 ) {
const struct V_42 * V_43 = & V_5 -> V_6 -> V_11 [ V_29 ] ;
V_27 = F_13 ( V_5 , V_43 -> V_44 , V_45 ) ;
if ( V_27 < 0 )
goto V_35;
}
V_31 -> type = V_45 ;
V_27 = 0 ;
V_35:
F_14 ( & V_5 -> V_28 , V_25 ) ;
return V_27 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
unsigned V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_5 = V_4 -> V_5 ;
int V_29 = F_12 ( V_5 , V_16 ) ;
struct V_30 * V_31 = & V_4 -> V_32 [ V_29 ] ;
unsigned long V_25 ;
F_11 ( & V_5 -> V_28 , V_25 ) ;
V_31 -> type = V_33 ;
F_14 ( & V_5 -> V_28 , V_25 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
unsigned V_16 , bool V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_5 = V_4 -> V_5 ;
int V_47 = V_46 ? V_48 : V_49 ;
int V_29 = F_12 ( V_5 , V_16 ) ;
const struct V_42 * V_43 = & V_5 -> V_6 -> V_11 [ V_29 ] ;
struct V_30 * V_31 = & V_4 -> V_32 [ V_29 ] ;
unsigned long V_25 ;
unsigned int V_50 ;
int V_27 ;
if ( V_43 -> V_32 ) {
V_50 = V_46 ? V_51 : V_52 ;
if ( ! ( V_43 -> V_32 & V_50 ) )
return - V_53 ;
}
F_11 ( & V_5 -> V_28 , V_25 ) ;
V_27 = F_13 ( V_5 , V_43 -> V_44 , V_47 ) ;
if ( V_27 < 0 )
goto V_35;
V_31 -> type = V_47 ;
V_35:
F_14 ( & V_5 -> V_28 , V_25 ) ;
return V_27 ;
}
static bool F_20 ( struct V_22 * V_5 , unsigned int V_54 ,
enum V_55 V_56 )
{
int V_29 = F_12 ( V_5 , V_54 ) ;
const struct V_42 * V_43 = & V_5 -> V_6 -> V_11 [ V_29 ] ;
switch ( V_56 ) {
case V_57 :
return true ;
case V_58 :
return V_43 -> V_32 & V_59 ;
case V_60 :
return V_43 -> V_32 & V_61 ;
default:
return false ;
}
}
static int F_21 ( struct V_1 * V_2 , unsigned V_54 ,
unsigned long * V_62 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_5 = V_4 -> V_5 ;
enum V_55 V_56 = F_22 ( * V_62 ) ;
unsigned long V_25 ;
unsigned int V_63 ;
if ( ! F_20 ( V_5 , V_54 , V_56 ) )
return - V_64 ;
switch ( V_56 ) {
case V_57 :
case V_58 :
case V_60 :
if ( ! V_5 -> V_6 -> V_65 || ! V_5 -> V_6 -> V_65 -> V_66 )
return - V_64 ;
F_11 ( & V_5 -> V_28 , V_25 ) ;
V_63 = V_5 -> V_6 -> V_65 -> V_66 ( V_5 , V_54 ) ;
F_14 ( & V_5 -> V_28 , V_25 ) ;
if ( V_63 != V_56 )
return - V_53 ;
* V_62 = 0 ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned V_54 ,
unsigned long V_62 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_5 = V_4 -> V_5 ;
enum V_55 V_56 = F_22 ( V_62 ) ;
unsigned long V_25 ;
if ( ! F_20 ( V_5 , V_54 , V_56 ) )
return - V_64 ;
switch ( V_56 ) {
case V_58 :
case V_60 :
case V_57 :
if ( ! V_5 -> V_6 -> V_65 || ! V_5 -> V_6 -> V_65 -> V_67 )
return - V_64 ;
F_11 ( & V_5 -> V_28 , V_25 ) ;
V_5 -> V_6 -> V_65 -> V_67 ( V_5 , V_54 , V_56 ) ;
F_14 ( & V_5 -> V_28 , V_25 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_21 ,
unsigned long V_62 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned int * V_11 ;
unsigned int V_12 ;
unsigned int V_26 ;
V_11 = V_4 -> V_5 -> V_6 -> V_9 [ V_21 ] . V_11 ;
V_12 = V_4 -> V_5 -> V_6 -> V_9 [ V_21 ] . V_13 ;
for ( V_26 = 0 ; V_26 < V_12 ; ++ V_26 )
F_23 ( V_2 , V_11 [ V_26 ] , V_62 ) ;
return 0 ;
}
static int F_25 ( struct V_22 * V_5 , struct V_3 * V_4 )
{
const struct V_68 * V_69 ;
struct V_68 V_70 ;
unsigned int V_71 ;
unsigned int V_13 ;
unsigned int V_26 ;
if ( V_5 -> V_6 -> V_69 == NULL ) {
V_70 . V_72 = 0 ;
V_70 . V_73 = V_5 -> V_6 -> V_13 - 1 ;
V_69 = & V_70 ;
V_71 = 1 ;
} else {
V_69 = V_5 -> V_6 -> V_69 ;
V_71 = V_5 -> V_6 -> V_71 ;
}
V_4 -> V_11 = F_26 ( V_5 -> V_40 ,
sizeof( * V_4 -> V_11 ) * V_5 -> V_6 -> V_13 ,
V_74 ) ;
if ( F_27 ( ! V_4 -> V_11 ) )
return - V_75 ;
V_4 -> V_32 = F_26 ( V_5 -> V_40 ,
sizeof( * V_4 -> V_32 ) * V_5 -> V_6 -> V_13 ,
V_74 ) ;
if ( F_27 ( ! V_4 -> V_32 ) )
return - V_75 ;
for ( V_26 = 0 , V_13 = 0 ; V_26 < V_71 ; ++ V_26 ) {
const struct V_68 * V_39 = & V_69 [ V_26 ] ;
unsigned int V_76 ;
for ( V_76 = V_39 -> V_72 ; V_76 <= V_39 -> V_73 ;
V_76 ++ , V_13 ++ ) {
struct V_30 * V_31 = & V_4 -> V_32 [ V_13 ] ;
struct V_77 * V_43 = & V_4 -> V_11 [ V_13 ] ;
const struct V_42 * V_6 =
& V_5 -> V_6 -> V_11 [ V_13 ] ;
V_43 -> V_76 = V_76 ;
V_43 -> V_10 = V_6 -> V_10 ;
V_31 -> type = V_33 ;
}
}
V_5 -> V_13 = V_69 [ V_71 - 1 ] . V_73 + 1 ;
return V_71 ;
}
int F_28 ( struct V_22 * V_5 )
{
struct V_3 * V_4 ;
int V_71 ;
V_4 = F_26 ( V_5 -> V_40 , sizeof( * V_4 ) , V_74 ) ;
if ( F_27 ( ! V_4 ) )
return - V_75 ;
V_4 -> V_5 = V_5 ;
V_5 -> V_78 = V_4 ;
V_71 = F_25 ( V_5 , V_4 ) ;
if ( F_27 ( V_71 < 0 ) )
return V_71 ;
V_4 -> V_79 . V_10 = V_17 ;
V_4 -> V_79 . V_80 = V_81 ;
V_4 -> V_79 . V_82 = & V_83 ;
V_4 -> V_79 . V_84 = & V_85 ;
V_4 -> V_79 . V_86 = & V_87 ;
V_4 -> V_79 . V_11 = V_4 -> V_11 ;
V_4 -> V_79 . V_88 = V_5 -> V_6 -> V_13 ;
V_4 -> V_89 = F_29 ( & V_4 -> V_79 , V_5 -> V_40 , V_4 ) ;
if ( V_4 -> V_89 == NULL )
return - V_53 ;
return 0 ;
}
int F_30 ( struct V_22 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_78 ;
F_31 ( V_4 -> V_89 ) ;
V_5 -> V_78 = NULL ;
return 0 ;
}
