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
static int F_7 ( struct V_18 * V_19 ,
const char * V_20 ,
enum V_21 type ,
unsigned long * V_22 ,
unsigned int V_23 )
{
unsigned long * V_24 ;
V_24 = F_8 ( V_22 , V_23 * sizeof( * V_24 ) ,
V_25 ) ;
if ( V_24 == NULL )
return - V_26 ;
V_19 -> type = type ;
V_19 -> V_27 . V_22 . V_20 = V_20 ;
V_19 -> V_27 . V_22 . V_22 = V_24 ;
V_19 -> V_27 . V_22 . V_23 = V_23 ;
return 0 ;
}
static int F_9 ( struct V_28 * V_29 , struct V_30 * V_31 ,
struct V_18 * * V_19 ,
unsigned int * V_32 , unsigned int * V_33 )
{
struct V_18 * V_34 = * V_19 ;
unsigned int V_35 = * V_32 ;
unsigned int V_36 = * V_33 ;
unsigned int V_23 ;
const char * V_37 = NULL ;
unsigned long * V_22 ;
struct V_38 * V_39 ;
unsigned int V_40 ;
unsigned int V_12 ;
const char * V_41 ;
const char * V_42 ;
int V_43 ;
V_43 = F_10 ( V_31 , L_2 , & V_37 ) ;
if ( V_43 < 0 && V_43 != - V_44 ) {
F_11 ( V_29 , L_3 ) ;
return V_43 ;
}
V_43 = F_12 ( V_31 , & V_22 , & V_23 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( ! V_37 && V_23 == 0 ) {
F_11 ( V_29 ,
L_4 ) ;
goto V_45;
}
V_43 = F_13 ( V_31 , L_5 ) ;
if ( V_43 == - V_44 ) {
V_12 = 0 ;
} else if ( V_43 < 0 ) {
F_11 ( V_29 , L_6 ) ;
goto V_45;
} else {
V_12 = V_43 ;
}
V_43 = F_13 ( V_31 , L_7 ) ;
if ( V_43 == - V_44 ) {
V_40 = 0 ;
} else if ( V_43 < 0 ) {
F_11 ( V_29 , L_8 ) ;
goto V_45;
} else {
V_40 = V_43 ;
}
if ( ! V_12 && ! V_40 ) {
F_11 ( V_29 , L_9 ) ;
V_43 = - V_46 ;
goto V_45;
}
if ( V_37 )
V_35 += V_40 ;
if ( V_22 )
V_35 += V_12 + V_40 ;
V_34 = F_14 ( V_34 , sizeof( * V_34 ) * V_35 , V_25 ) ;
if ( V_34 == NULL ) {
V_43 = - V_26 ;
goto V_45;
}
* V_19 = V_34 ;
* V_32 = V_35 ;
F_15 (np, L_7 , prop, group) {
if ( V_37 ) {
V_34 [ V_36 ] . type = V_47 ;
V_34 [ V_36 ] . V_27 . V_48 . V_41 = V_41 ;
V_34 [ V_36 ] . V_27 . V_48 . V_37 = V_37 ;
V_36 ++ ;
}
if ( V_22 ) {
V_43 = F_7 ( & V_34 [ V_36 ] , V_41 ,
V_49 ,
V_22 , V_23 ) ;
if ( V_43 < 0 )
goto V_45;
V_36 ++ ;
}
}
if ( ! V_22 ) {
V_43 = 0 ;
goto V_45;
}
F_15 (np, L_5 , prop, pin) {
V_43 = F_7 ( & V_34 [ V_36 ] , V_42 ,
V_50 ,
V_22 , V_23 ) ;
if ( V_43 < 0 )
goto V_45;
V_36 ++ ;
}
V_45:
* V_33 = V_36 ;
F_16 ( V_22 ) ;
return V_43 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_18 * V_19 , unsigned V_32 )
{
unsigned int V_51 ;
if ( V_19 == NULL )
return;
for ( V_51 = 0 ; V_51 < V_32 ; ++ V_51 ) {
if ( V_19 [ V_51 ] . type == V_49 ||
V_19 [ V_51 ] . type == V_50 )
F_16 ( V_19 [ V_51 ] . V_27 . V_22 . V_22 ) ;
}
F_16 ( V_19 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_18 * * V_19 , unsigned * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_29 = V_4 -> V_5 -> V_29 ;
struct V_30 * V_52 ;
unsigned int V_33 ;
int V_43 ;
* V_19 = NULL ;
* V_32 = 0 ;
V_33 = 0 ;
F_19 (np, child) {
V_43 = F_9 ( V_29 , V_52 , V_19 , V_32 ,
& V_33 ) ;
if ( V_43 < 0 )
goto V_45;
}
if ( * V_32 == 0 ) {
V_43 = F_9 ( V_29 , V_31 , V_19 , V_32 , & V_33 ) ;
if ( V_43 < 0 )
goto V_45;
}
if ( * V_32 )
return 0 ;
F_11 ( V_29 , L_10 , V_31 -> V_53 ) ;
V_43 = - V_44 ;
V_45:
if ( V_43 < 0 )
F_17 ( V_2 , * V_19 , * V_32 ) ;
return V_43 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_54 ;
}
static const char * F_21 ( struct V_1 * V_2 ,
unsigned V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 -> V_55 [ V_8 ] . V_10 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned V_8 ,
const char * const * * V_9 ,
unsigned * const V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_5 -> V_6 -> V_55 [ V_8 ] . V_9 ;
* V_40 = V_4 -> V_5 -> V_6 -> V_55 [ V_8 ] . V_7 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned V_8 ,
unsigned V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_56 * V_5 = V_4 -> V_5 ;
const struct V_57 * V_58 = & V_5 -> V_6 -> V_9 [ V_41 ] ;
unsigned long V_59 ;
unsigned int V_51 ;
int V_43 = 0 ;
F_24 ( & V_5 -> V_60 , V_59 ) ;
for ( V_51 = 0 ; V_51 < V_58 -> V_13 ; ++ V_51 ) {
int V_36 = F_25 ( V_5 , V_58 -> V_11 [ V_51 ] ) ;
struct V_61 * V_62 = & V_4 -> V_22 [ V_36 ] ;
if ( V_62 -> type != V_63 ) {
V_43 = - V_64 ;
goto V_45;
}
}
for ( V_51 = 0 ; V_51 < V_58 -> V_13 ; ++ V_51 ) {
V_43 = F_26 ( V_5 , V_58 -> V_48 [ V_51 ] , V_65 ) ;
if ( V_43 < 0 )
break;
}
V_45:
F_27 ( & V_5 -> V_60 , V_59 ) ;
return V_43 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned V_8 ,
unsigned V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_56 * V_5 = V_4 -> V_5 ;
const struct V_57 * V_58 = & V_5 -> V_6 -> V_9 [ V_41 ] ;
unsigned long V_59 ;
unsigned int V_51 ;
F_24 ( & V_5 -> V_60 , V_59 ) ;
for ( V_51 = 0 ; V_51 < V_58 -> V_13 ; ++ V_51 ) {
int V_36 = F_25 ( V_5 , V_58 -> V_11 [ V_51 ] ) ;
struct V_61 * V_62 = & V_4 -> V_22 [ V_36 ] ;
V_62 -> type = V_63 ;
}
F_27 ( & V_5 -> V_60 , V_59 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
unsigned V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_56 * V_5 = V_4 -> V_5 ;
int V_36 = F_25 ( V_5 , V_16 ) ;
struct V_61 * V_62 = & V_4 -> V_22 [ V_36 ] ;
unsigned long V_59 ;
int V_43 ;
F_24 ( & V_5 -> V_60 , V_59 ) ;
if ( V_62 -> type != V_63 ) {
F_11 ( V_5 -> V_29 ,
L_11 ,
V_16 ) ;
V_43 = - V_64 ;
goto V_45;
}
if ( ! V_5 -> V_68 ) {
const struct V_69 * V_42 = & V_5 -> V_6 -> V_11 [ V_36 ] ;
V_43 = F_26 ( V_5 , V_42 -> V_70 , V_71 ) ;
if ( V_43 < 0 )
goto V_45;
}
V_62 -> type = V_71 ;
V_43 = 0 ;
V_45:
F_27 ( & V_5 -> V_60 , V_59 ) ;
return V_43 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
unsigned V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_56 * V_5 = V_4 -> V_5 ;
int V_36 = F_25 ( V_5 , V_16 ) ;
struct V_61 * V_62 = & V_4 -> V_22 [ V_36 ] ;
unsigned long V_59 ;
F_24 ( & V_5 -> V_60 , V_59 ) ;
V_62 -> type = V_63 ;
F_27 ( & V_5 -> V_60 , V_59 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
unsigned V_16 , bool V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_56 * V_5 = V_4 -> V_5 ;
int V_73 = V_72 ? V_74 : V_75 ;
int V_36 = F_25 ( V_5 , V_16 ) ;
const struct V_69 * V_42 = & V_5 -> V_6 -> V_11 [ V_36 ] ;
struct V_61 * V_62 = & V_4 -> V_22 [ V_36 ] ;
unsigned long V_59 ;
unsigned int V_76 ;
int V_43 ;
if ( V_42 -> V_22 ) {
V_76 = V_72 ? V_77 : V_78 ;
if ( ! ( V_42 -> V_22 & V_76 ) )
return - V_44 ;
}
F_24 ( & V_5 -> V_60 , V_59 ) ;
V_43 = F_26 ( V_5 , V_42 -> V_70 , V_73 ) ;
if ( V_43 < 0 )
goto V_45;
V_62 -> type = V_73 ;
V_45:
F_27 ( & V_5 -> V_60 , V_59 ) ;
return V_43 ;
}
static bool F_32 ( struct V_56 * V_5 , unsigned int V_79 ,
enum V_80 V_81 )
{
int V_36 = F_25 ( V_5 , V_79 ) ;
const struct V_69 * V_42 = & V_5 -> V_6 -> V_11 [ V_36 ] ;
switch ( V_81 ) {
case V_82 :
return true ;
case V_83 :
return V_42 -> V_22 & V_84 ;
case V_85 :
return V_42 -> V_22 & V_86 ;
default:
return false ;
}
}
static int F_33 ( struct V_1 * V_2 , unsigned V_79 ,
unsigned long * V_87 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_56 * V_5 = V_4 -> V_5 ;
enum V_80 V_81 = F_34 ( * V_87 ) ;
unsigned long V_59 ;
unsigned int V_88 ;
if ( ! F_32 ( V_5 , V_79 , V_81 ) )
return - V_89 ;
switch ( V_81 ) {
case V_82 :
case V_83 :
case V_85 :
if ( ! V_5 -> V_6 -> V_90 || ! V_5 -> V_6 -> V_90 -> V_91 )
return - V_89 ;
F_24 ( & V_5 -> V_60 , V_59 ) ;
V_88 = V_5 -> V_6 -> V_90 -> V_91 ( V_5 , V_79 ) ;
F_27 ( & V_5 -> V_60 , V_59 ) ;
if ( V_88 != V_81 )
return - V_44 ;
* V_87 = 0 ;
break;
default:
return - V_89 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned V_79 ,
unsigned long V_87 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_56 * V_5 = V_4 -> V_5 ;
enum V_80 V_81 = F_34 ( V_87 ) ;
unsigned long V_59 ;
if ( ! F_32 ( V_5 , V_79 , V_81 ) )
return - V_89 ;
switch ( V_81 ) {
case V_83 :
case V_85 :
case V_82 :
if ( ! V_5 -> V_6 -> V_90 || ! V_5 -> V_6 -> V_90 -> V_92 )
return - V_89 ;
F_24 ( & V_5 -> V_60 , V_59 ) ;
V_5 -> V_6 -> V_90 -> V_92 ( V_5 , V_79 , V_81 ) ;
F_27 ( & V_5 -> V_60 , V_59 ) ;
break;
default:
return - V_89 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , unsigned V_41 ,
unsigned long V_87 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned int * V_11 ;
unsigned int V_12 ;
unsigned int V_51 ;
V_11 = V_4 -> V_5 -> V_6 -> V_9 [ V_41 ] . V_11 ;
V_12 = V_4 -> V_5 -> V_6 -> V_9 [ V_41 ] . V_13 ;
for ( V_51 = 0 ; V_51 < V_12 ; ++ V_51 )
F_35 ( V_2 , V_11 [ V_51 ] , V_87 ) ;
return 0 ;
}
static int F_37 ( struct V_56 * V_5 , struct V_3 * V_4 )
{
const struct V_93 * V_94 ;
struct V_93 V_95 ;
unsigned int V_96 ;
unsigned int V_13 ;
unsigned int V_51 ;
if ( V_5 -> V_6 -> V_94 == NULL ) {
V_95 . V_97 = 0 ;
V_95 . V_98 = V_5 -> V_6 -> V_13 - 1 ;
V_94 = & V_95 ;
V_96 = 1 ;
} else {
V_94 = V_5 -> V_6 -> V_94 ;
V_96 = V_5 -> V_6 -> V_96 ;
}
V_4 -> V_11 = F_38 ( V_5 -> V_29 ,
sizeof( * V_4 -> V_11 ) * V_5 -> V_6 -> V_13 ,
V_25 ) ;
if ( F_39 ( ! V_4 -> V_11 ) )
return - V_26 ;
V_4 -> V_22 = F_38 ( V_5 -> V_29 ,
sizeof( * V_4 -> V_22 ) * V_5 -> V_6 -> V_13 ,
V_25 ) ;
if ( F_39 ( ! V_4 -> V_22 ) )
return - V_26 ;
for ( V_51 = 0 , V_13 = 0 ; V_51 < V_96 ; ++ V_51 ) {
const struct V_93 * V_67 = & V_94 [ V_51 ] ;
unsigned int V_99 ;
for ( V_99 = V_67 -> V_97 ; V_99 <= V_67 -> V_98 ;
V_99 ++ , V_13 ++ ) {
struct V_61 * V_62 = & V_4 -> V_22 [ V_13 ] ;
struct V_100 * V_42 = & V_4 -> V_11 [ V_13 ] ;
const struct V_69 * V_6 =
& V_5 -> V_6 -> V_11 [ V_13 ] ;
V_42 -> V_99 = V_99 ;
V_42 -> V_10 = V_6 -> V_10 ;
V_62 -> type = V_63 ;
}
}
V_5 -> V_13 = V_94 [ V_96 - 1 ] . V_98 + 1 ;
return V_96 ;
}
int F_40 ( struct V_56 * V_5 )
{
struct V_3 * V_4 ;
int V_96 ;
V_4 = F_38 ( V_5 -> V_29 , sizeof( * V_4 ) , V_25 ) ;
if ( F_39 ( ! V_4 ) )
return - V_26 ;
V_4 -> V_5 = V_5 ;
V_5 -> V_101 = V_4 ;
V_96 = F_37 ( V_5 , V_4 ) ;
if ( F_39 ( V_96 < 0 ) )
return V_96 ;
V_4 -> V_102 . V_10 = V_17 ;
V_4 -> V_102 . V_103 = V_104 ;
V_4 -> V_102 . V_105 = & V_106 ;
V_4 -> V_102 . V_107 = & V_108 ;
V_4 -> V_102 . V_109 = & V_110 ;
V_4 -> V_102 . V_11 = V_4 -> V_11 ;
V_4 -> V_102 . V_111 = V_5 -> V_6 -> V_13 ;
V_4 -> V_112 = F_41 ( & V_4 -> V_102 , V_5 -> V_29 , V_4 ) ;
if ( V_4 -> V_112 == NULL )
return - V_44 ;
return 0 ;
}
int F_42 ( struct V_56 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_101 ;
F_43 ( V_4 -> V_112 ) ;
V_5 -> V_101 = NULL ;
return 0 ;
}
