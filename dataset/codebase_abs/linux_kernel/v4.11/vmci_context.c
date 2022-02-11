static void F_1 ( struct V_1 * V_2 )
{
* V_2 -> V_3 = true ;
}
static void F_2 ( struct V_1 * V_2 )
{
* V_2 -> V_3 = false ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == 0 &&
F_4 ( V_2 -> V_5 ) == 0 )
F_2 ( V_2 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_4 )
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_6 ) ;
}
struct V_1 * F_8 ( T_1 V_7 , T_1 V_8 ,
T_2 V_9 ,
int V_10 ,
const struct V_11 * V_11 )
{
struct V_1 * V_2 ;
int error ;
if ( V_7 == V_12 ) {
F_9 ( L_1 ) ;
error = - V_13 ;
goto V_14;
}
if ( V_8 & ~ V_15 ) {
F_9 ( L_2 ,
V_8 ) ;
error = - V_13 ;
goto V_14;
}
if ( V_10 == 0 ) {
F_9 ( L_3 , V_10 ) ;
error = - V_13 ;
goto V_14;
}
V_2 = F_10 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
F_11 ( L_4 ) ;
error = - V_13 ;
goto V_14;
}
F_12 ( & V_2 -> V_17 ) ;
F_13 ( & V_2 -> V_6 ) ;
F_14 ( & V_2 -> V_18 ) ;
F_14 ( & V_2 -> V_19 ) ;
F_14 ( & V_2 -> V_20 ) ;
F_15 ( & V_2 -> V_21 . V_22 ) ;
V_2 -> V_23 = F_16 ( 0 ) ;
if ( ! V_2 -> V_23 ) {
error = - V_24 ;
goto V_25;
}
V_2 -> V_26 = F_16 ( 0 ) ;
if ( ! V_2 -> V_26 ) {
error = - V_24 ;
goto V_27;
}
V_2 -> V_5 = F_16 ( 0 ) ;
if ( ! V_2 -> V_5 ) {
error = - V_24 ;
goto V_28;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_8 = V_8 ;
if ( V_11 )
V_2 -> V_11 = F_17 ( V_11 ) ;
V_2 -> V_3 = & V_29 ;
V_2 -> V_30 = NULL ;
F_6 ( & V_31 . V_6 ) ;
while ( F_18 ( V_7 ) ) {
V_7 = F_19 ( V_7 , V_32 - 1 ) + 1 ;
if ( V_7 == V_12 )
V_7 = V_32 ;
}
V_2 -> V_7 = V_7 ;
F_20 ( & V_2 -> V_18 , & V_31 . V_33 ) ;
F_7 ( & V_31 . V_6 ) ;
return V_2 ;
V_28:
F_21 ( V_2 -> V_26 ) ;
V_27:
F_21 ( V_2 -> V_23 ) ;
V_25:
F_22 ( V_2 ) ;
V_14:
return F_23 ( error ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_6 ( & V_31 . V_6 ) ;
F_25 ( & V_2 -> V_18 ) ;
F_7 ( & V_31 . V_6 ) ;
F_26 () ;
F_27 ( V_2 ) ;
}
static int F_28 ( T_1 V_34 , T_1 V_8 )
{
T_1 V_35 , V_36 ;
struct V_1 * V_37 ;
struct V_38 * V_39 ;
struct V_40 V_41 =
F_29 ( V_34 , V_42 ) ;
V_39 = F_16 ( 0 ) ;
if ( V_39 == NULL )
return V_43 ;
F_30 () ;
F_31 (sub_ctx, &ctx_list.head, list_item) {
struct V_44 * V_45 ;
if ( F_32 ( V_8 , V_37 -> V_8 ) )
continue;
F_31 (node, &sub_ctx->notifier_list, node) {
if ( ! F_33 ( V_45 -> V_46 , V_41 ) )
continue;
F_34 ( & V_39 ,
F_29 ( V_37 -> V_7 ,
V_42 ) ) ;
}
}
F_35 () ;
V_36 = F_4 ( V_39 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
int V_47 ;
struct V_48 V_49 ;
V_49 . V_50 . V_51 . V_52 = F_36 ( V_39 , V_35 ) ;
V_49 . V_50 . V_51 . V_53 = F_29 ( V_54 ,
V_55 ) ;
V_49 . V_50 . V_51 . V_56 = sizeof( V_49 ) - sizeof( V_49 . V_50 . V_51 ) ;
V_49 . V_50 . V_57 . V_58 = V_59 ;
V_49 . V_60 . V_34 = V_34 ;
V_47 = F_37 ( V_54 ,
& V_49 . V_50 . V_51 , false ) ;
if ( V_47 < V_61 ) {
F_9 ( L_5 ,
V_49 . V_50 . V_57 . V_58 ,
V_49 . V_50 . V_51 . V_52 . V_2 ) ;
}
}
F_21 ( V_39 ) ;
return V_61 ;
}
int F_38 ( T_1 V_7 , T_1 * V_62 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( V_7 ) ;
if ( V_2 == NULL )
return V_63 ;
F_6 ( & V_2 -> V_6 ) ;
if ( V_62 )
* V_62 = V_2 -> V_4 ;
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
return V_61 ;
}
int F_40 ( T_1 V_7 , struct V_64 * V_65 )
{
struct V_66 * V_67 ;
struct V_1 * V_2 ;
struct V_40 V_68 ;
T_3 V_69 ;
V_69 = F_41 ( V_65 ) ;
if ( V_69 > V_70 ) {
F_9 ( L_6 , V_69 ) ;
return V_63 ;
}
V_2 = F_39 ( V_7 ) ;
if ( ! V_2 ) {
F_9 ( L_7 , V_7 ) ;
return V_63 ;
}
V_67 = F_42 ( sizeof( * V_67 ) , V_16 ) ;
if ( V_67 == NULL ) {
F_11 ( L_8 ) ;
F_27 ( V_2 ) ;
return V_43 ;
}
V_67 -> V_65 = V_65 ;
V_67 -> V_71 = V_69 ;
V_68 = V_65 -> V_53 ;
F_14 ( & V_67 -> V_18 ) ;
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_72 + V_69 >=
V_73 &&
( ! F_33 ( V_68 ,
F_29
( V_54 ,
V_55 ) ) ||
V_2 -> V_72 + V_69 >=
V_74 ) ) {
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
F_22 ( V_67 ) ;
F_9 ( L_9 , V_7 ) ;
return V_75 ;
}
F_43 ( & V_67 -> V_18 , & V_2 -> V_19 ) ;
V_2 -> V_4 ++ ;
V_2 -> V_72 += V_69 ;
F_1 ( V_2 ) ;
F_44 ( & V_2 -> V_21 . V_22 ) ;
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
return V_69 ;
}
bool F_18 ( T_1 V_7 )
{
struct V_1 * V_2 ;
bool V_76 = false ;
F_30 () ;
F_31 (context, &ctx_list.head, list_item) {
if ( V_2 -> V_7 == V_7 ) {
V_76 = true ;
break;
}
}
F_35 () ;
return V_76 ;
}
struct V_1 * F_39 ( T_1 V_7 )
{
struct V_1 * V_77 , * V_2 = NULL ;
if ( V_7 == V_12 )
return NULL ;
F_30 () ;
F_31 (c, &ctx_list.head, list_item) {
if ( V_77 -> V_7 == V_7 ) {
V_2 = V_77 ;
F_45 ( & V_2 -> V_17 ) ;
break;
}
}
F_35 () ;
return V_2 ;
}
static void F_46 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = F_47 ( V_17 , struct V_1 , V_17 ) ;
struct V_66 * V_67 , * V_78 ;
struct V_40 V_79 ;
struct V_44 * V_80 , * V_81 ;
F_28 ( V_2 -> V_7 , V_2 -> V_8 ) ;
V_79 = F_36 ( V_2 -> V_23 , 0 ) ;
while ( ! F_33 ( V_79 , V_82 ) ) {
if ( F_48 ( V_79 ,
V_2 ) < V_61 ) {
F_49 ( V_2 -> V_23 ,
V_79 ) ;
}
V_79 =
F_36 ( V_2 -> V_23 , 0 ) ;
}
F_50 (dq_entry, dq_entry_tmp,
&context->datagram_queue, list_item) {
F_51 ( V_67 -> V_71 != F_41 ( V_67 -> V_65 ) ) ;
F_52 ( & V_67 -> V_18 ) ;
F_22 ( V_67 -> V_65 ) ;
F_22 ( V_67 ) ;
}
F_50 (notifier, tmp,
&context->notifier_list, node) {
F_52 ( & V_80 -> V_45 ) ;
F_22 ( V_80 ) ;
}
F_21 ( V_2 -> V_23 ) ;
F_21 ( V_2 -> V_26 ) ;
F_21 ( V_2 -> V_5 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_11 )
F_54 ( V_2 -> V_11 ) ;
F_22 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_17 , F_46 ) ;
}
int F_56 ( struct V_1 * V_2 ,
T_3 * V_83 ,
struct V_64 * * V_65 )
{
struct V_66 * V_67 ;
struct V_84 * V_18 ;
int V_85 ;
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_4 == 0 ) {
F_3 ( V_2 ) ;
F_7 ( & V_2 -> V_6 ) ;
F_9 ( L_10 ) ;
return V_86 ;
}
V_18 = V_2 -> V_19 . V_87 ;
V_67 =
F_57 ( V_18 , struct V_66 , V_18 ) ;
if ( * V_83 < V_67 -> V_71 ) {
* V_83 = V_67 -> V_71 ;
F_7 ( & V_2 -> V_6 ) ;
F_9 ( L_11 ,
( T_1 ) * V_83 ) ;
return V_43 ;
}
F_52 ( V_18 ) ;
V_2 -> V_4 -- ;
V_2 -> V_72 -= V_67 -> V_71 ;
if ( V_2 -> V_4 == 0 ) {
F_3 ( V_2 ) ;
V_85 = V_61 ;
} else {
struct V_66 * V_88 ;
V_18 = V_2 -> V_19 . V_87 ;
V_88 =
F_57 ( V_18 , struct V_66 ,
V_18 ) ;
V_85 = ( int ) V_88 -> V_71 ;
}
F_7 ( & V_2 -> V_6 ) ;
* V_65 = V_67 -> V_65 ;
V_67 -> V_65 = NULL ;
F_22 ( V_67 ) ;
return V_85 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_89 * V_30 ;
F_6 ( & V_2 -> V_6 ) ;
V_30 = V_2 -> V_30 ;
V_2 -> V_3 = & V_29 ;
V_2 -> V_30 = NULL ;
F_7 ( & V_2 -> V_6 ) ;
if ( V_30 ) {
F_58 ( V_30 ) ;
F_59 ( V_30 ) ;
}
}
int F_60 ( T_1 V_34 , T_1 V_90 )
{
struct V_1 * V_2 ;
struct V_44 * V_80 , * V_91 ;
int V_47 ;
bool V_76 = false ;
V_2 = F_39 ( V_34 ) ;
if ( ! V_2 )
return V_92 ;
if ( F_61 ( V_34 ) && F_61 ( V_90 ) ) {
F_9 ( L_12 ,
V_34 , V_90 ) ;
V_47 = V_93 ;
goto V_94;
}
if ( V_2 -> V_8 & V_95 ) {
V_47 = V_96 ;
goto V_94;
}
V_80 = F_42 ( sizeof( struct V_44 ) , V_16 ) ;
if ( ! V_80 ) {
V_47 = V_43 ;
goto V_94;
}
F_14 ( & V_80 -> V_45 ) ;
V_80 -> V_46 = F_29 ( V_90 , V_42 ) ;
F_6 ( & V_2 -> V_6 ) ;
F_62 (n, &context->notifier_list, node) {
if ( F_33 ( V_91 -> V_46 , V_80 -> V_46 ) ) {
V_76 = true ;
break;
}
}
if ( V_76 ) {
F_22 ( V_80 ) ;
V_47 = V_97 ;
} else {
F_20 ( & V_80 -> V_45 , & V_2 -> V_20 ) ;
V_2 -> V_98 ++ ;
V_47 = V_61 ;
}
F_7 ( & V_2 -> V_6 ) ;
V_94:
F_27 ( V_2 ) ;
return V_47 ;
}
int F_63 ( T_1 V_34 , T_1 V_90 )
{
struct V_1 * V_2 ;
struct V_44 * V_80 , * V_81 ;
struct V_40 V_46 ;
bool V_99 = false ;
V_2 = F_39 ( V_34 ) ;
if ( ! V_2 )
return V_92 ;
V_46 = F_29 ( V_90 , V_42 ) ;
F_6 ( & V_2 -> V_6 ) ;
F_50 (notifier, tmp,
&context->notifier_list, node) {
if ( F_33 ( V_80 -> V_46 , V_46 ) ) {
F_25 ( & V_80 -> V_45 ) ;
V_2 -> V_98 -- ;
V_99 = true ;
break;
}
}
F_7 ( & V_2 -> V_6 ) ;
if ( V_99 ) {
F_26 () ;
F_22 ( V_80 ) ;
}
F_27 ( V_2 ) ;
return V_99 ? V_61 : V_92 ;
}
static int F_64 ( struct V_1 * V_2 ,
T_1 * V_100 , void * * V_101 )
{
T_1 * V_102 ;
T_3 V_103 ;
struct V_44 * V_104 ;
int V_35 = 0 ;
if ( V_2 -> V_98 == 0 ) {
* V_100 = 0 ;
* V_101 = NULL ;
return V_61 ;
}
V_103 = V_2 -> V_98 * sizeof( * V_102 ) ;
if ( * V_100 < V_103 ) {
* V_100 = V_103 ;
return V_105 ;
}
V_102 = F_42 ( V_103 , V_106 ) ;
if ( ! V_102 )
return V_43 ;
F_62 (entry, &context->notifier_list, node)
V_102 [ V_35 ++ ] = V_104 -> V_46 . V_2 ;
* V_100 = V_103 ;
* V_101 = V_102 ;
return V_61 ;
}
static int F_65 ( struct V_1 * V_2 ,
T_1 * V_100 , void * * V_101 )
{
struct V_107 * V_108 ;
T_3 V_109 ;
int V_35 ;
V_109 = F_4 ( V_2 -> V_26 ) ;
if ( V_109 > 0 ) {
T_3 V_103 = V_109 * sizeof( * V_108 ) ;
if ( * V_100 < V_103 ) {
* V_100 = V_103 ;
return V_105 ;
}
V_108 = F_42 ( V_103 , V_106 ) ;
if ( ! V_108 )
return V_43 ;
for ( V_35 = 0 ; V_35 < V_109 ; V_35 ++ )
V_108 [ V_35 ] . V_46 = F_36 (
V_2 -> V_26 , V_35 ) ;
* V_100 = V_103 ;
* V_101 = V_108 ;
} else {
* V_100 = 0 ;
* V_101 = NULL ;
}
return V_61 ;
}
int F_66 ( T_1 V_34 ,
T_1 V_110 ,
T_1 * V_100 ,
void * * V_101 )
{
struct V_1 * V_2 ;
int V_47 ;
V_2 = F_39 ( V_34 ) ;
if ( ! V_2 )
return V_92 ;
F_6 ( & V_2 -> V_6 ) ;
switch ( V_110 ) {
case V_111 :
V_47 = F_64 ( V_2 , V_100 , V_101 ) ;
break;
case V_112 :
* V_100 = 0 ;
* V_101 = NULL ;
V_47 = V_61 ;
break;
case V_113 :
V_47 = F_65 ( V_2 , V_100 , V_101 ) ;
break;
default:
F_9 ( L_13 , V_110 ) ;
V_47 = V_63 ;
break;
}
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
return V_47 ;
}
int F_67 ( T_1 V_34 ,
T_1 V_110 ,
T_1 V_100 ,
void * V_114 )
{
T_1 V_35 ;
T_1 V_115 ;
int V_47 = V_61 ;
T_1 V_116 = V_100 / sizeof( T_1 ) ;
if ( V_110 == V_112 && V_116 > 0 ) {
F_11 ( L_14 ) ;
return V_117 ;
}
if ( V_110 != V_111 ) {
F_9 ( L_13 , V_110 ) ;
return V_63 ;
}
for ( V_35 = 0 ; V_35 < V_116 && V_47 == V_61 ; V_35 ++ ) {
V_115 = ( ( T_1 * ) V_114 ) [ V_35 ] ;
V_47 = F_60 ( V_34 , V_115 ) ;
if ( V_47 != V_61 )
break;
}
if ( V_47 != V_61 )
F_9 ( L_15 ,
V_110 , V_47 ) ;
return V_47 ;
}
int F_68 ( T_1 V_34 ,
struct V_38 * * V_118 ,
struct V_38 * * V_119 )
{
struct V_1 * V_2 ;
int V_47 = V_61 ;
V_2 = F_39 ( V_34 ) ;
if ( V_2 == NULL )
return V_92 ;
F_6 ( & V_2 -> V_6 ) ;
* V_118 = V_2 -> V_5 ;
V_2 -> V_5 = F_16 ( 0 ) ;
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = * V_118 ;
* V_118 = NULL ;
V_47 = V_43 ;
}
* V_119 = NULL ;
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
return V_47 ;
}
void F_69 ( T_1 V_34 ,
struct V_38 * V_118 ,
struct V_38 * V_119 ,
bool V_120 )
{
struct V_1 * V_2 = F_39 ( V_34 ) ;
F_6 ( & V_2 -> V_6 ) ;
if ( ! V_120 ) {
struct V_40 V_46 ;
V_46 = F_70 (
V_2 -> V_5 ) ;
while ( ! F_71 ( V_46 ) ) {
if ( ! F_72 ( V_118 ,
V_46 ) ) {
F_34 (
& V_118 , V_46 ) ;
}
V_46 = F_70 (
V_2 -> V_5 ) ;
}
F_21 ( V_2 -> V_5 ) ;
V_2 -> V_5 = V_118 ;
V_118 = NULL ;
} else {
F_3 ( V_2 ) ;
}
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
if ( V_118 )
F_21 ( V_118 ) ;
if ( V_119 )
F_21 ( V_119 ) ;
}
int F_73 ( T_1 V_34 , struct V_40 V_46 )
{
struct V_1 * V_2 ;
int V_47 ;
if ( V_34 == V_12 || F_71 ( V_46 ) )
return V_63 ;
V_2 = F_39 ( V_34 ) ;
if ( V_2 == NULL )
return V_92 ;
F_6 ( & V_2 -> V_6 ) ;
if ( ! F_72 ( V_2 -> V_26 , V_46 ) ) {
F_34 ( & V_2 -> V_26 , V_46 ) ;
V_47 = V_61 ;
} else {
V_47 = V_121 ;
}
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
return V_47 ;
}
int F_74 ( T_1 V_34 , struct V_40 V_46 )
{
struct V_1 * V_2 ;
struct V_40 V_122 ;
if ( V_34 == V_12 || F_71 ( V_46 ) )
return V_63 ;
V_2 = F_39 ( V_34 ) ;
if ( V_2 == NULL )
return V_92 ;
F_6 ( & V_2 -> V_6 ) ;
V_122 =
F_49 ( V_2 -> V_26 , V_46 ) ;
F_49 ( V_2 -> V_5 , V_46 ) ;
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
return F_71 ( V_122 ) ?
V_92 : V_61 ;
}
int F_75 ( T_1 V_34 )
{
struct V_1 * V_2 ;
struct V_40 V_46 ;
if ( V_34 == V_12 )
return V_63 ;
V_2 = F_39 ( V_34 ) ;
if ( V_2 == NULL )
return V_92 ;
F_6 ( & V_2 -> V_6 ) ;
do {
struct V_38 * V_123 = V_2 -> V_26 ;
V_46 = F_70 ( V_123 ) ;
} while ( ! F_71 ( V_46 ) );
do {
struct V_38 * V_123 = V_2 -> V_5 ;
V_46 = F_70 ( V_123 ) ;
} while ( ! F_71 ( V_46 ) );
F_7 ( & V_2 -> V_6 ) ;
F_27 ( V_2 ) ;
return V_61 ;
}
int F_76 ( T_1 V_124 ,
struct V_40 V_46 ,
T_1 V_125 )
{
struct V_1 * V_126 ;
int V_47 ;
if ( F_71 ( V_46 ) )
return V_63 ;
V_126 = F_39 ( V_46 . V_2 ) ;
if ( ! V_126 ) {
F_9 ( L_7 , V_46 . V_2 ) ;
return V_92 ;
}
if ( V_124 != V_46 . V_2 ) {
T_1 V_127 ;
if ( F_61 ( V_124 ) &&
F_61 ( V_46 . V_2 ) ) {
F_9 ( L_16 ,
V_124 , V_46 . V_2 ) ;
V_47 = V_93 ;
goto V_94;
}
V_47 = F_77 ( V_46 , & V_127 ) ;
if ( V_47 < V_61 ) {
F_11 ( L_17 ,
V_46 . V_2 , V_46 . V_128 ) ;
goto V_94;
}
if ( V_124 != V_129 ||
V_125 == V_130 ) {
V_125 = F_78 ( V_124 ) ;
}
if ( F_32 ( V_125 , V_127 ) ) {
V_47 = V_96 ;
goto V_94;
}
}
if ( V_46 . V_2 == V_129 ) {
V_47 = F_79 ( V_124 , V_46 ) ;
} else {
F_6 ( & V_126 -> V_6 ) ;
if ( ! F_72 ( V_126 -> V_26 ,
V_46 ) ) {
V_47 = V_92 ;
} else {
if ( ! F_72 (
V_126 -> V_5 ,
V_46 ) ) {
F_34 (
& V_126 -> V_5 ,
V_46 ) ;
F_1 ( V_126 ) ;
F_44 ( & V_126 -> V_21 . V_22 ) ;
}
V_47 = V_61 ;
}
F_7 ( & V_126 -> V_6 ) ;
}
V_94:
F_27 ( V_126 ) ;
return V_47 ;
}
bool F_80 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_10 >= V_131 ;
}
int F_81 ( struct V_1 * V_2 , struct V_40 V_46 )
{
int V_47 ;
if ( V_2 == NULL || F_71 ( V_46 ) )
return V_63 ;
if ( ! F_72 ( V_2 -> V_23 , V_46 ) ) {
F_34 ( & V_2 -> V_23 ,
V_46 ) ;
V_47 = V_61 ;
} else {
V_47 = V_121 ;
}
return V_47 ;
}
int F_82 ( struct V_1 * V_2 , struct V_40 V_46 )
{
struct V_40 V_132 ;
if ( V_2 == NULL || F_71 ( V_46 ) )
return V_63 ;
V_132 = F_49 ( V_2 -> V_23 , V_46 ) ;
return F_71 ( V_132 ) ?
V_92 : V_61 ;
}
bool F_83 ( struct V_1 * V_2 , struct V_40 V_46 )
{
if ( V_2 == NULL || F_71 ( V_46 ) )
return false ;
return F_72 ( V_2 -> V_23 , V_46 ) ;
}
T_1 F_78 ( T_1 V_34 )
{
if ( F_84 () ) {
T_1 V_133 ;
struct V_1 * V_2 ;
V_2 = F_39 ( V_34 ) ;
if ( ! V_2 )
return V_134 ;
V_133 = V_2 -> V_8 ;
F_27 ( V_2 ) ;
return V_133 ;
}
return V_130 ;
}
bool F_85 ( T_1 V_34 , T_4 V_135 )
{
bool V_136 = false ;
if ( F_84 () ) {
struct V_1 * V_2 = F_39 ( V_34 ) ;
if ( V_2 ) {
if ( V_2 -> V_11 )
V_136 = F_86 ( V_2 -> V_11 -> V_135 , V_135 ) ;
F_27 ( V_2 ) ;
}
}
return V_136 ;
}
