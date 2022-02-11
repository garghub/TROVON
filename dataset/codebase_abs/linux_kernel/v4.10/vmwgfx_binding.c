static const struct V_1 *
F_1 ( const struct V_2 * V_3 )
{
if ( F_2 ( & V_3 -> V_4 ) )
return NULL ;
return F_3 ( & V_3 -> V_4 , struct V_5 ,
V_6 ) -> V_7 ;
}
static struct V_5 *
F_4 ( struct V_2 * V_3 ,
enum V_8 V_9 , T_1 V_10 , T_1 V_11 )
{
const struct V_12 * V_13 = & V_14 [ V_9 ] ;
T_2 V_15 = V_13 -> V_16 [ V_10 ] + V_13 -> V_17 * V_11 ;
return (struct V_5 * ) ( ( V_18 * ) V_3 + V_15 ) ;
}
static void F_5 ( struct V_5 * V_19 )
{
F_6 ( & V_19 -> V_6 ) ;
if ( ! F_2 ( & V_19 -> V_20 ) )
F_6 ( & V_19 -> V_20 ) ;
V_19 -> V_7 = NULL ;
}
void F_7 ( struct V_2 * V_3 ,
const struct V_5 * V_19 ,
T_1 V_10 , T_1 V_11 )
{
struct V_5 * V_21 =
F_4 ( V_3 , V_19 -> V_9 , V_10 , V_11 ) ;
const struct V_12 * V_13 = & V_14 [ V_19 -> V_9 ] ;
if ( V_21 -> V_7 != NULL )
F_5 ( V_21 ) ;
memcpy ( V_21 , V_19 , V_13 -> V_17 ) ;
V_21 -> V_22 = false ;
F_8 ( & V_21 -> V_6 , & V_3 -> V_4 ) ;
F_9 ( & V_21 -> V_20 ) ;
}
static void F_10 ( struct V_2 * V_3 ,
const struct V_2 * V_23 ,
const struct V_5 * V_19 )
{
T_2 V_15 = ( unsigned long ) V_19 - ( unsigned long ) V_23 ;
struct V_5 * V_21 = (struct V_5 * )
( ( unsigned long ) V_3 + V_15 ) ;
if ( V_21 -> V_7 != NULL ) {
F_11 ( V_19 -> V_22 ) ;
F_5 ( V_21 ) ;
}
if ( V_19 -> V_24 != NULL ) {
memcpy ( V_21 , V_19 , V_14 [ V_19 -> V_9 ] . V_17 ) ;
F_12 ( & V_21 -> V_6 , & V_3 -> V_4 ) ;
F_12 ( & V_21 -> V_20 , & V_21 -> V_24 -> V_25 ) ;
}
}
void F_13 ( struct V_2 * V_3 )
{
struct V_5 * V_26 , * V_27 ;
F_14 ( V_3 ) ;
F_15 (entry, next, &cbs->list, ctx_list)
F_5 ( V_26 ) ;
}
void F_14 ( struct V_2 * V_3 )
{
struct V_5 * V_26 ;
F_16 (entry, &cbs->list, ctx_list) {
if ( ! V_26 -> V_22 ) {
( void ) V_14 [ V_26 -> V_9 ] . F_17
( V_26 , false ) ;
V_26 -> V_22 = true ;
}
}
( void ) F_18 ( V_3 ) ;
}
void F_19 ( struct V_28 * V_29 )
{
struct V_5 * V_26 , * V_27 ;
F_20 ( V_29 ) ;
F_15 (entry, next, head, res_list)
F_5 ( V_26 ) ;
}
void F_20 ( struct V_28 * V_29 )
{
struct V_5 * V_26 ;
F_16 (entry, head, res_list) {
if ( ! V_26 -> V_22 ) {
( void ) V_14 [ V_26 -> V_9 ] . F_17
( V_26 , false ) ;
V_26 -> V_22 = true ;
}
}
F_16 (entry, head, res_list) {
struct V_2 * V_3 =
F_21 ( V_26 -> V_7 ) ;
( void ) F_18 ( V_3 ) ;
}
}
void F_22 ( struct V_2 * V_30 ,
struct V_2 * V_23 )
{
struct V_5 * V_26 , * V_27 ;
F_15 (entry, next, &from->list, ctx_list) {
F_10 ( V_30 , V_23 , V_26 ) ;
F_5 ( V_26 ) ;
}
}
int F_23 ( struct V_2 * V_3 )
{
struct V_5 * V_26 ;
int V_31 ;
F_16 (entry, &cbs->list, ctx_list) {
if ( F_24 ( ! V_26 -> V_22 ) )
continue;
if ( ( V_26 -> V_24 == NULL || V_26 -> V_24 -> V_32 ==
V_33 ) )
continue;
V_31 = V_14 [ V_26 -> V_9 ] . F_17 ( V_26 , true ) ;
if ( F_25 ( V_31 != 0 ) )
return V_31 ;
V_26 -> V_22 = false ;
}
return F_18 ( V_3 ) ;
}
static int F_26 ( struct V_5 * V_19 , bool V_34 )
{
struct V_35 * V_36 =
F_27 ( V_19 , F_28 ( * V_36 ) , V_19 ) ;
struct V_37 * V_38 = V_19 -> V_7 -> V_38 ;
struct {
T_3 V_39 ;
T_4 V_40 ;
} * V_41 ;
V_41 = F_29 ( V_38 , sizeof( * V_41 ) ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_1
L_2 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_43 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) ;
V_41 -> V_40 . V_44 = V_19 -> V_7 -> V_32 ;
V_41 -> V_40 . type = V_36 -> V_10 + V_45 ;
V_41 -> V_40 . V_46 = ( ( V_34 ) ? V_19 -> V_24 -> V_32 : V_33 ) ;
F_31 ( V_38 , sizeof( * V_41 ) ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_19 ,
bool V_34 )
{
struct V_47 * V_36 =
F_27 ( V_19 , F_28 ( * V_36 ) , V_19 ) ;
struct V_37 * V_38 = V_19 -> V_7 -> V_38 ;
struct {
T_3 V_39 ;
T_5 V_40 ;
} * V_41 ;
V_41 = F_29 ( V_38 , sizeof( * V_41 ) ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_3
L_2 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_48 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) ;
V_41 -> V_40 . V_44 = V_19 -> V_7 -> V_32 ;
V_41 -> V_40 . type = V_36 -> V_11 ;
V_41 -> V_40 . V_49 . V_50 = ( ( V_34 ) ? V_19 -> V_24 -> V_32 : V_33 ) ;
V_41 -> V_40 . V_49 . V_51 = 0 ;
V_41 -> V_40 . V_49 . V_52 = 0 ;
F_31 ( V_38 , sizeof( * V_41 ) ) ;
return 0 ;
}
static int F_33 ( struct V_5 * V_19 ,
bool V_34 )
{
struct V_53 * V_36 =
F_27 ( V_19 , F_28 ( * V_36 ) , V_19 ) ;
struct V_37 * V_38 = V_19 -> V_7 -> V_38 ;
struct {
T_3 V_39 ;
struct {
T_6 V_54 ;
T_7 V_55 ;
} V_40 ;
} * V_41 ;
V_41 = F_29 ( V_38 , sizeof( * V_41 ) ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_4
L_2 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_56 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) ;
V_41 -> V_40 . V_54 . V_44 = V_19 -> V_7 -> V_32 ;
V_41 -> V_40 . V_55 . V_57 = V_36 -> V_58 ;
V_41 -> V_40 . V_55 . V_59 = V_60 ;
V_41 -> V_40 . V_55 . V_61 = ( ( V_34 ) ? V_19 -> V_24 -> V_32 : V_33 ) ;
F_31 ( V_38 , sizeof( * V_41 ) ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_19 , bool V_34 )
{
struct V_35 * V_36 =
F_27 ( V_19 , F_28 ( * V_36 ) , V_19 ) ;
struct V_37 * V_38 = V_19 -> V_7 -> V_38 ;
struct {
T_3 V_39 ;
T_8 V_40 ;
} * V_41 ;
V_41 = F_35 ( V_38 , sizeof( * V_41 ) , V_19 -> V_7 -> V_32 ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_5
L_2 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_62 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) ;
V_41 -> V_40 . type = V_36 -> V_10 + V_45 ;
V_41 -> V_40 . V_63 = ( ( V_34 ) ? V_19 -> V_24 -> V_32 : V_33 ) ;
F_31 ( V_38 , sizeof( * V_41 ) ) ;
return 0 ;
}
static int F_36 ( struct V_5 * V_19 , bool V_34 )
{
struct V_64 * V_36 =
F_27 ( V_19 , F_28 ( * V_36 ) , V_19 ) ;
struct V_37 * V_38 = V_19 -> V_7 -> V_38 ;
struct {
T_3 V_39 ;
T_9 V_40 ;
} * V_41 ;
V_41 = F_35 ( V_38 , sizeof( * V_41 ) , V_19 -> V_7 -> V_32 ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_5
L_2 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_65 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) ;
V_41 -> V_40 . V_11 = V_36 -> V_11 ;
V_41 -> V_40 . type = V_36 -> V_10 + V_45 ;
if ( V_34 ) {
V_41 -> V_40 . V_66 = V_36 -> V_15 ;
V_41 -> V_40 . V_67 = V_36 -> V_17 ;
V_41 -> V_40 . V_50 = V_19 -> V_24 -> V_32 ;
} else {
V_41 -> V_40 . V_66 = 0 ;
V_41 -> V_40 . V_67 = 0 ;
V_41 -> V_40 . V_50 = V_33 ;
}
F_31 ( V_38 , sizeof( * V_41 ) ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 ,
const struct V_5 * V_19 ,
T_1 V_68 )
{
const struct V_47 * V_69 =
F_27 ( V_19 , struct V_47 , V_19 ) ;
unsigned long V_70 ;
V_3 -> V_71 = 0 ;
V_3 -> V_72 = 0 ;
for ( V_70 = 0 ; V_70 < V_68 ; ++ V_70 , ++ V_69 ) {
if ( ! V_69 -> V_19 . V_7 )
break;
V_3 -> V_73 [ V_3 -> V_71 ++ ] =
( ( V_69 -> V_19 . V_22 ) ?
V_33 : V_69 -> V_19 . V_24 -> V_32 ) ;
}
}
static void F_38 ( struct V_2 * V_3 ,
const struct V_5 * V_19 ,
unsigned long * V_74 ,
T_1 V_68 )
{
const struct V_47 * V_69 =
F_27 ( V_19 , struct V_47 , V_19 ) ;
unsigned long V_70 , V_75 ;
V_3 -> V_71 = 0 ;
V_70 = F_39 ( V_74 , V_68 ) ;
V_75 = V_70 ;
V_3 -> V_72 = V_70 ;
V_69 += V_70 ;
for (; V_70 < V_68 ; ++ V_70 , ++ V_69 ) {
V_3 -> V_73 [ V_3 -> V_71 ++ ] =
( ( ! V_69 -> V_19 . V_7 || V_69 -> V_19 . V_22 ) ?
V_33 : V_69 -> V_19 . V_24 -> V_32 ) ;
if ( V_75 == V_70 ) {
V_75 = F_40 ( V_74 , V_68 , V_70 + 1 ) ;
if ( V_75 >= V_68 )
break;
}
}
}
static int F_41 ( struct V_2 * V_3 ,
int V_10 )
{
const struct V_5 * V_21 =
& V_3 -> V_76 [ V_10 ] . V_77 [ 0 ] . V_19 ;
struct {
T_3 V_39 ;
T_10 V_40 ;
} * V_41 ;
T_2 V_78 , V_79 ;
const struct V_1 * V_7 = F_1 ( V_3 ) ;
F_38 ( V_3 , V_21 ,
V_3 -> V_76 [ V_10 ] . V_80 ,
V_81 ) ;
if ( V_3 -> V_71 == 0 )
return 0 ;
V_79 = V_3 -> V_71 * sizeof( V_82 ) ;
V_78 = sizeof( * V_41 ) + V_79 ;
V_41 = F_35 ( V_7 -> V_38 , V_78 , V_7 -> V_32 ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_6
L_7 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_83 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) + V_79 ;
V_41 -> V_40 . type = V_10 + V_45 ;
V_41 -> V_40 . V_84 = V_3 -> V_72 ;
memcpy ( & V_41 [ 1 ] , V_3 -> V_73 , V_79 ) ;
F_31 ( V_7 -> V_38 , V_78 ) ;
F_42 ( V_3 -> V_76 [ V_10 ] . V_80 ,
V_3 -> V_72 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
const struct V_5 * V_21 = & V_3 -> V_85 [ 0 ] . V_19 ;
struct {
T_3 V_39 ;
T_11 V_40 ;
} * V_41 ;
T_2 V_78 , V_79 ;
const struct V_1 * V_7 = F_1 ( V_3 ) ;
F_37 ( V_3 , V_21 , V_86 ) ;
V_79 = V_3 -> V_71 * sizeof( V_82 ) ;
V_78 = sizeof( * V_41 ) + V_79 ;
V_41 = F_35 ( V_7 -> V_38 , V_78 , V_7 -> V_32 ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_8
L_9 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_87 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) + V_79 ;
if ( V_3 -> V_88 . V_19 . V_7 && ! V_3 -> V_88 . V_19 . V_22 )
V_41 -> V_40 . V_89 = V_3 -> V_88 . V_19 . V_24 -> V_32 ;
else
V_41 -> V_40 . V_89 = V_33 ;
memcpy ( & V_41 [ 1 ] , V_3 -> V_73 , V_79 ) ;
F_31 ( V_7 -> V_38 , V_78 ) ;
return 0 ;
}
static void F_44 ( struct V_2 * V_3 ,
const struct V_5 * V_19 ,
T_1 V_68 )
{
const struct V_90 * V_91 =
F_27 ( V_19 , struct V_90 , V_19 ) ;
unsigned long V_70 ;
T_12 * V_92 = ( T_12 * ) V_3 -> V_73 ;
V_3 -> V_71 = 0 ;
V_3 -> V_72 = 0 ;
for ( V_70 = 0 ; V_70 < V_68 ; ++ V_70 , ++ V_91 , ++ V_92 ,
++ V_3 -> V_71 ) {
if ( ! V_91 -> V_19 . V_7 )
break;
if ( ! V_91 -> V_19 . V_22 ) {
V_92 -> V_50 = V_91 -> V_19 . V_24 -> V_32 ;
V_92 -> V_15 = V_91 -> V_15 ;
V_92 -> V_67 = V_91 -> V_17 ;
} else {
V_92 -> V_50 = V_33 ;
V_92 -> V_15 = 0 ;
V_92 -> V_67 = 0 ;
}
}
}
static int F_45 ( struct V_2 * V_3 )
{
const struct V_5 * V_21 = & V_3 -> V_93 [ 0 ] . V_19 ;
struct {
T_3 V_39 ;
T_13 V_40 ;
} * V_41 ;
T_2 V_78 , V_94 ;
const struct V_1 * V_7 = F_1 ( V_3 ) ;
F_44 ( V_3 , V_21 , V_95 ) ;
if ( V_3 -> V_71 == 0 )
return 0 ;
V_94 = V_3 -> V_71 * sizeof( T_12 ) ;
V_78 = sizeof( * V_41 ) + V_94 ;
V_41 = F_35 ( V_7 -> V_38 , V_78 , V_7 -> V_32 ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_10
L_9 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_96 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) + V_94 ;
memcpy ( & V_41 [ 1 ] , V_3 -> V_73 , V_94 ) ;
F_31 ( V_7 -> V_38 , V_78 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_97 * V_98 = & V_3 -> V_76 [ 0 ] ;
T_1 V_70 ;
int V_31 ;
for ( V_70 = 0 ; V_70 < V_99 ; ++ V_70 , ++ V_98 ) {
if ( ! F_47 ( V_100 , & V_98 -> V_74 ) )
continue;
V_31 = F_41 ( V_3 , V_70 ) ;
if ( V_31 )
break;
F_48 ( V_100 , & V_98 -> V_74 ) ;
}
return 0 ;
}
static void F_49 ( struct V_2 * V_3 ,
const struct V_5 * V_19 ,
unsigned long * V_74 ,
T_1 V_68 )
{
const struct V_101 * V_69 =
F_27 ( V_19 , struct V_101 , V_19 ) ;
unsigned long V_70 , V_75 ;
T_14 * V_102 = ( T_14 * ) & V_3 -> V_73 ;
V_3 -> V_71 = 0 ;
V_70 = F_39 ( V_74 , V_68 ) ;
V_75 = V_70 ;
V_3 -> V_72 = V_70 ;
V_69 += V_70 ;
for (; V_70 < V_68 ; ++ V_70 , ++ V_69 , ++ V_102 ) {
if ( ! V_69 -> V_19 . V_7 || V_69 -> V_19 . V_22 ) {
V_102 -> V_50 = V_33 ;
V_102 -> V_103 = 0 ;
V_102 -> V_15 = 0 ;
} else {
V_102 -> V_50 = V_69 -> V_19 . V_24 -> V_32 ;
V_102 -> V_103 = V_69 -> V_103 ;
V_102 -> V_15 = V_69 -> V_15 ;
}
V_3 -> V_71 ++ ;
if ( V_75 == V_70 ) {
V_75 = F_40 ( V_74 , V_68 , V_70 + 1 ) ;
if ( V_75 >= V_68 )
break;
}
}
}
static int F_50 ( struct V_2 * V_3 )
{
const struct V_5 * V_21 =
& V_3 -> V_104 [ 0 ] . V_19 ;
struct {
T_3 V_39 ;
T_15 V_40 ;
} * V_41 ;
T_2 V_78 , V_105 ;
const struct V_1 * V_7 = F_1 ( V_3 ) ;
F_49 ( V_3 , V_21 , V_3 -> V_106 ,
V_107 ) ;
if ( V_3 -> V_71 == 0 )
return 0 ;
V_105 = V_3 -> V_71 * sizeof( T_14 ) ;
V_78 = sizeof( * V_41 ) + V_105 ;
V_41 = F_35 ( V_7 -> V_38 , V_78 , V_7 -> V_32 ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_11
L_9 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_108 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) + V_105 ;
V_41 -> V_40 . V_109 = V_3 -> V_72 ;
memcpy ( & V_41 [ 1 ] , V_3 -> V_73 , V_105 ) ;
F_31 ( V_7 -> V_38 , V_78 ) ;
F_42 ( V_3 -> V_106 ,
V_3 -> V_72 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
int V_31 = 0 ;
unsigned long V_110 = 0 ;
while ( ( V_110 = F_40 ( & V_3 -> V_74 , V_111 , V_110 ) )
< V_111 ) {
switch ( V_110 ) {
case V_112 :
V_31 = F_43 ( V_3 ) ;
break;
case V_113 :
V_31 = F_46 ( V_3 ) ;
break;
case V_114 :
V_31 = F_45 ( V_3 ) ;
break;
case V_115 :
V_31 = F_50 ( V_3 ) ;
break;
default:
F_51 () ;
}
if ( V_31 )
return V_31 ;
F_48 ( V_110 , & V_3 -> V_74 ) ;
V_110 ++ ;
}
return 0 ;
}
static int F_52 ( struct V_5 * V_19 , bool V_34 )
{
struct V_47 * V_69 =
F_27 ( V_19 , struct V_47 , V_19 ) ;
struct V_2 * V_3 =
F_21 ( V_19 -> V_7 ) ;
F_53 ( V_69 -> V_11 , V_3 -> V_76 [ V_69 -> V_10 ] . V_80 ) ;
F_53 ( V_100 ,
& V_3 -> V_76 [ V_69 -> V_10 ] . V_74 ) ;
F_53 ( V_113 , & V_3 -> V_74 ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_19 , bool V_34 )
{
struct V_2 * V_3 =
F_21 ( V_19 -> V_7 ) ;
F_53 ( V_112 , & V_3 -> V_74 ) ;
return 0 ;
}
static int F_55 ( struct V_5 * V_19 , bool V_34 )
{
struct V_2 * V_3 =
F_21 ( V_19 -> V_7 ) ;
F_53 ( V_114 , & V_3 -> V_74 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_19 , bool V_34 )
{
struct V_101 * V_116 =
F_27 ( V_19 , struct V_101 , V_19 ) ;
struct V_2 * V_3 =
F_21 ( V_19 -> V_7 ) ;
F_53 ( V_116 -> V_11 , V_3 -> V_106 ) ;
F_53 ( V_115 , & V_3 -> V_74 ) ;
return 0 ;
}
static int F_57 ( struct V_5 * V_19 , bool V_34 )
{
struct V_117 * V_36 =
F_27 ( V_19 , F_28 ( * V_36 ) , V_19 ) ;
struct V_37 * V_38 = V_19 -> V_7 -> V_38 ;
struct {
T_3 V_39 ;
T_16 V_40 ;
} * V_41 ;
V_41 = F_35 ( V_38 , sizeof( * V_41 ) , V_19 -> V_7 -> V_32 ) ;
if ( F_25 ( V_41 == NULL ) ) {
F_30 ( L_12
L_13 ) ;
return - V_42 ;
}
V_41 -> V_39 . V_32 = V_118 ;
V_41 -> V_39 . V_17 = sizeof( V_41 -> V_40 ) ;
if ( V_34 ) {
V_41 -> V_40 . V_50 = V_19 -> V_24 -> V_32 ;
V_41 -> V_40 . V_119 = V_36 -> V_119 ;
V_41 -> V_40 . V_15 = V_36 -> V_15 ;
} else {
V_41 -> V_40 . V_50 = V_33 ;
V_41 -> V_40 . V_119 = 0 ;
V_41 -> V_40 . V_15 = 0 ;
}
F_31 ( V_38 , sizeof( * V_41 ) ) ;
return 0 ;
}
struct V_2 *
F_58 ( struct V_37 * V_38 )
{
struct V_2 * V_3 ;
int V_31 ;
V_31 = F_59 ( F_60 ( V_38 ) , sizeof( * V_3 ) ,
false , false ) ;
if ( V_31 )
return F_61 ( V_31 ) ;
V_3 = F_62 ( sizeof( * V_3 ) ) ;
if ( ! V_3 ) {
F_63 ( F_60 ( V_38 ) , sizeof( * V_3 ) ) ;
return F_61 ( - V_42 ) ;
}
V_3 -> V_38 = V_38 ;
F_9 ( & V_3 -> V_4 ) ;
return V_3 ;
}
void F_64 ( struct V_2 * V_3 )
{
struct V_37 * V_38 = V_3 -> V_38 ;
F_65 ( V_3 ) ;
F_63 ( F_60 ( V_38 ) , sizeof( * V_3 ) ) ;
}
struct V_28 * F_66 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 ;
}
void F_67 ( struct V_2 * V_3 )
{
struct V_5 * V_26 , * V_27 ;
F_15 (entry, next, &cbs->list, ctx_list)
F_5 ( V_26 ) ;
}
static void F_68 ( void )
{
F_69 ( V_99 != 3 ) ;
F_69 ( V_86 > V_120 ) ;
F_69 ( sizeof( V_82 ) != sizeof( T_1 ) ) ;
F_69 ( V_121 < V_120 ) ;
F_69 ( V_121 < V_81 ) ;
F_69 ( V_121 < V_122 ) ;
F_69 ( V_95 * sizeof( T_12 ) >
V_121 * sizeof( T_1 ) ) ;
F_69 ( V_107 * sizeof( T_14 ) >
V_121 * sizeof( T_1 ) ) ;
}
