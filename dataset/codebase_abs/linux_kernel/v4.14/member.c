int F_1 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 & 0x0000FFFF ) < V_4 )
return 0 ;
return 1 ;
}
void F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_8 -> V_13 ;
if ( ! F_1 ( & V_8 -> V_14 ) )
return;
V_10 -> V_15 = F_3 ( V_12 -> V_16 ) ;
V_10 -> V_17 = F_4 ( V_12 -> V_18 ) ;
}
void F_5 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_19 * V_15 ;
struct V_20 * V_21 ;
int V_22 ;
V_21 = (struct V_20 * ) ( V_8 -> V_13 + sizeof( struct V_11 ) ) ;
for ( V_22 = 0 ; V_22 < V_6 -> V_23 ; V_22 ++ ) {
V_15 = & V_6 -> V_24 [ V_22 ] ;
if ( ! V_15 -> V_25 )
continue;
V_21 -> V_26 = F_6 ( V_15 -> V_25 ) ;
V_21 -> V_27 = F_7 ( V_15 -> V_15 ) ;
V_21 ++ ;
}
}
static void F_8 ( struct V_5 * V_6 , T_1 V_28 , int V_29 ,
struct V_20 * V_30 , struct V_19 * V_31 ,
int V_32 )
{
char line [ V_33 ] ;
int V_34 = V_33 - 1 ;
int V_35 = 0 ;
int V_36 , V_22 ;
memset ( line , 0 , sizeof( line ) ) ;
if ( V_31 ) {
for ( V_22 = 0 ; V_22 < V_32 ; V_22 ++ ) {
if ( ! V_31 [ V_22 ] . V_25 )
continue;
V_36 = snprintf ( line + V_35 , V_34 - V_35 , L_1 ,
V_31 [ V_22 ] . V_15 , V_31 [ V_22 ] . V_25 ) ;
if ( V_36 >= V_34 - V_35 )
break;
V_35 += V_36 ;
}
} else if ( V_30 ) {
for ( V_22 = 0 ; V_22 < V_29 ; V_22 ++ ) {
V_36 = snprintf ( line + V_35 , V_34 - V_35 , L_1 ,
V_30 [ V_22 ] . V_27 , V_30 [ V_22 ] . V_26 ) ;
if ( V_36 >= V_34 - V_35 )
break;
V_35 += V_36 ;
}
}
F_9 ( V_6 , L_2 , V_28 , V_29 , line ) ;
}
int F_10 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 = V_6 -> V_37 ;
struct V_11 * V_12 = (struct V_11 * ) V_8 -> V_13 ;
struct V_20 * V_30 , * V_21 ;
int V_38 = F_11 () ;
int V_22 , V_29 ;
T_1 V_28 ;
if ( ! F_1 ( & V_8 -> V_14 ) )
return - 1 ;
V_28 = F_4 ( V_12 -> V_18 ) ;
if ( V_28 <= V_6 -> V_39 ) {
F_12 ( V_6 , L_3 ,
V_28 , V_6 -> V_39 ) ;
}
V_6 -> V_39 = V_28 ;
V_29 = F_3 ( V_12 -> V_40 ) ;
if ( ! V_29 )
return - 1 ;
V_30 = (struct V_20 * ) ( V_8 -> V_13 + sizeof( struct V_11 ) ) ;
for ( V_22 = 0 , V_21 = V_30 ; V_22 < V_29 ; V_22 ++ , V_21 ++ ) {
V_21 -> V_26 = F_4 ( V_21 -> V_26 ) ;
V_21 -> V_27 = F_3 ( V_21 -> V_27 ) ;
}
F_8 ( V_6 , V_28 , V_29 , V_30 , NULL , 0 ) ;
F_13 (memb, &ls->ls_nodes, list) {
for ( V_22 = 0 , V_21 = V_30 ; V_22 < V_29 ; V_22 ++ , V_21 ++ ) {
if ( V_21 -> V_26 != V_10 -> V_25 )
continue;
V_10 -> V_15 = V_21 -> V_27 ;
V_10 -> V_41 = V_10 -> V_15 ;
break;
}
if ( V_10 -> V_25 == V_38 ) {
if ( V_6 -> V_42 && V_6 -> V_42 != V_10 -> V_15 ) {
F_12 ( V_6 , L_4
L_5 , V_6 -> V_42 ,
V_10 -> V_15 ) ;
return - 1 ;
}
if ( ! V_6 -> V_42 )
V_6 -> V_42 = V_10 -> V_15 ;
}
if ( ! V_10 -> V_15 ) {
F_12 ( V_6 , L_6 ,
V_10 -> V_25 ) ;
return - 1 ;
}
}
return 0 ;
}
int F_14 ( struct V_5 * V_6 , int * V_29 , int * V_43 ,
struct V_19 * * V_44 , T_1 * V_45 )
{
struct V_9 * V_10 ;
struct V_19 * V_31 ;
int V_38 = F_11 () ;
int V_32 , V_46 , V_22 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 = 0 ;
T_1 V_28 = 0 ;
F_13 (memb, &ls->ls_nodes, list) {
if ( V_10 -> V_25 == V_38 ) {
V_10 -> V_15 = V_6 -> V_42 ;
V_10 -> V_17 = V_6 -> V_39 ;
break;
}
}
F_13 (memb, &ls->ls_nodes, list) {
if ( V_10 -> V_17 > V_28 )
V_28 = V_10 -> V_17 ;
if ( V_10 -> V_15 == - 1 )
return - 1 ;
if ( ! V_10 -> V_15 )
V_47 ++ ;
V_49 ++ ;
if ( ! V_48 || V_48 < V_10 -> V_15 )
V_48 = V_10 -> V_15 ;
if ( V_10 -> V_41 && V_10 -> V_15 && V_10 -> V_41 != V_10 -> V_15 ) {
F_12 ( V_6 , L_7 ,
V_10 -> V_25 , V_10 -> V_41 , V_10 -> V_15 ) ;
return - 1 ;
}
V_10 -> V_41 = V_10 -> V_15 ;
}
V_32 = V_48 + V_47 ;
V_31 = F_15 ( V_32 , sizeof( * V_31 ) , V_50 ) ;
if ( ! V_31 )
return - V_51 ;
V_49 = 0 ;
F_13 (memb, &ls->ls_nodes, list) {
if ( ! V_10 -> V_15 )
continue;
if ( V_10 -> V_15 > V_32 ) {
F_12 ( V_6 , L_8 , V_10 -> V_15 ) ;
F_16 ( V_31 ) ;
return - 1 ;
}
V_31 [ V_10 -> V_15 - 1 ] . V_25 = V_10 -> V_25 ;
V_31 [ V_10 -> V_15 - 1 ] . V_15 = V_10 -> V_15 ;
V_49 ++ ;
}
F_13 (memb, &ls->ls_nodes, list) {
if ( V_10 -> V_15 )
continue;
for ( V_22 = 0 ; V_22 < V_32 ; V_22 ++ ) {
if ( V_31 [ V_22 ] . V_25 )
continue;
V_10 -> V_15 = V_22 + 1 ;
V_10 -> V_41 = V_10 -> V_15 ;
V_31 [ V_22 ] . V_25 = V_10 -> V_25 ;
V_31 [ V_22 ] . V_15 = V_10 -> V_15 ;
V_49 ++ ;
if ( ! V_6 -> V_42 && V_10 -> V_25 == V_38 )
V_6 -> V_42 = V_10 -> V_15 ;
break;
}
if ( ! V_10 -> V_15 ) {
F_12 ( V_6 , L_9 ) ;
F_16 ( V_31 ) ;
return - 1 ;
}
}
V_28 ++ ;
F_8 ( V_6 , V_28 , V_49 , NULL , V_31 , V_32 ) ;
V_46 = ( V_52 . V_53 - sizeof( struct V_7 ) -
sizeof( struct V_11 ) ) / sizeof( struct V_20 ) ;
if ( V_49 > V_46 ) {
F_12 ( V_6 , L_10 ,
V_49 , V_46 ) ;
F_16 ( V_31 ) ;
return - 1 ;
}
* V_45 = V_28 ;
* V_44 = V_31 ;
* V_43 = V_32 ;
* V_29 = V_49 ;
return 0 ;
}
static void F_17 ( struct V_5 * V_6 , struct V_9 * V_54 )
{
struct V_9 * V_10 = NULL ;
struct V_55 * V_56 ;
struct V_55 * V_57 = & V_54 -> V_58 ;
struct V_55 * V_59 = & V_6 -> V_60 ;
F_18 (tmp, head) {
V_10 = F_19 ( V_56 , struct V_9 , V_58 ) ;
if ( V_54 -> V_25 < V_10 -> V_25 )
break;
}
if ( ! V_10 )
F_20 ( V_57 , V_59 ) ;
else {
V_57 -> V_61 = V_56 -> V_61 ;
V_57 -> V_62 = V_56 ;
V_56 -> V_61 -> V_62 = V_57 ;
V_56 -> V_61 = V_57 ;
}
}
static int F_21 ( struct V_5 * V_6 , struct V_63 * V_64 )
{
struct V_9 * V_10 ;
int error ;
V_10 = F_22 ( sizeof( * V_10 ) , V_50 ) ;
if ( ! V_10 )
return - V_51 ;
error = F_23 ( V_64 -> V_25 ) ;
if ( error < 0 ) {
F_16 ( V_10 ) ;
return error ;
}
V_10 -> V_25 = V_64 -> V_25 ;
V_10 -> V_65 = V_64 -> V_65 ;
V_10 -> V_66 = V_64 -> V_66 ;
F_17 ( V_6 , V_10 ) ;
V_6 -> V_67 ++ ;
return 0 ;
}
static struct V_9 * F_24 ( struct V_55 * V_59 , int V_25 )
{
struct V_9 * V_10 ;
F_13 (memb, head, list) {
if ( V_10 -> V_25 == V_25 )
return V_10 ;
}
return NULL ;
}
int F_25 ( struct V_5 * V_6 , int V_25 )
{
if ( F_24 ( & V_6 -> V_60 , V_25 ) )
return 1 ;
return 0 ;
}
int F_26 ( struct V_5 * V_6 , int V_25 )
{
if ( F_24 ( & V_6 -> V_68 , V_25 ) )
return 1 ;
return 0 ;
}
static void F_27 ( struct V_55 * V_59 )
{
struct V_9 * V_10 ;
while ( ! F_28 ( V_59 ) ) {
V_10 = F_19 ( V_59 -> V_62 , struct V_9 , V_58 ) ;
F_29 ( & V_10 -> V_58 ) ;
F_16 ( V_10 ) ;
}
}
void F_30 ( struct V_5 * V_6 )
{
F_27 ( & V_6 -> V_60 ) ;
V_6 -> V_67 = 0 ;
}
void F_31 ( struct V_5 * V_6 )
{
F_27 ( & V_6 -> V_68 ) ;
}
static void F_32 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
int V_22 , V_69 , V_70 = 0 , V_71 = 0 , V_72 = 0 , * V_31 ;
F_16 ( V_6 -> V_73 ) ;
V_6 -> V_73 = NULL ;
F_13 (memb, &ls->ls_nodes, list) {
if ( V_10 -> V_65 )
V_71 += V_10 -> V_65 ;
}
if ( ! V_71 ) {
V_71 = V_6 -> V_67 ;
V_72 = 1 ;
}
V_6 -> V_74 = V_71 ;
V_31 = F_33 ( V_71 , sizeof( * V_31 ) , V_50 ) ;
if ( ! V_31 )
return;
F_13 (memb, &ls->ls_nodes, list) {
if ( ! V_72 && ! V_10 -> V_65 )
continue;
if ( V_72 )
V_69 = 1 ;
else
V_69 = V_10 -> V_65 ;
F_34 (x < total, printk(L_11, total, x);) ;
for ( V_22 = 0 ; V_22 < V_69 ; V_22 ++ )
V_31 [ V_70 ++ ] = V_10 -> V_25 ;
}
V_6 -> V_73 = V_31 ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
int error = 0 ;
F_13 (memb, &ls->ls_nodes, list) {
error = F_36 ( V_6 ) ;
if ( error )
break;
error = F_37 ( V_6 , V_10 -> V_25 , 0 ) ;
if ( error )
break;
}
if ( error )
F_9 ( V_6 , L_12 ,
error , V_6 -> V_75 ) ;
return error ;
}
static void F_38 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_76 || ! V_6 -> V_76 -> V_77 )
return;
V_6 -> V_76 -> V_77 ( V_6 -> V_78 ) ;
}
static void F_39 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
struct V_19 V_15 ;
T_1 V_79 ;
int error ;
if ( ! V_6 -> V_76 || ! V_6 -> V_76 -> V_80 )
return;
error = F_40 ( V_10 -> V_25 , & V_79 ) ;
if ( ! error && V_79 == V_10 -> V_66 )
return;
V_15 . V_25 = V_10 -> V_25 ;
V_15 . V_15 = V_10 -> V_15 ;
V_6 -> V_76 -> V_80 ( V_6 -> V_78 , & V_15 ) ;
}
void F_41 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_19 * V_81 ;
int V_22 , V_49 ;
if ( ! V_6 -> V_76 || ! V_6 -> V_76 -> V_82 )
return;
V_49 = V_6 -> V_67 ;
V_81 = F_15 ( V_49 , sizeof( * V_81 ) , V_83 ) ;
if ( ! V_81 )
return;
V_22 = 0 ;
F_13 (memb, &ls->ls_nodes, list) {
if ( V_22 == V_49 ) {
F_12 ( V_6 , L_13 , V_49 ) ;
goto V_84;
}
V_81 [ V_22 ] . V_25 = V_10 -> V_25 ;
V_81 [ V_22 ] . V_15 = V_10 -> V_15 ;
V_22 ++ ;
}
V_6 -> V_76 -> V_82 ( V_6 -> V_78 , V_81 , V_49 ,
V_6 -> V_42 , V_6 -> V_39 ) ;
V_84:
F_16 ( V_81 ) ;
}
static struct V_63 * F_42 ( struct V_85 * V_86 ,
int V_25 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_86 -> V_87 ; V_22 ++ ) {
if ( V_86 -> V_88 [ V_22 ] . V_25 == V_25 )
return & V_86 -> V_88 [ V_22 ] ;
}
return NULL ;
}
int F_43 ( struct V_5 * V_6 , struct V_85 * V_86 , int * V_89 )
{
struct V_9 * V_10 , * V_90 ;
struct V_63 * V_64 ;
int V_22 , error , V_91 = 0 , V_92 = - 1 ;
F_13 (memb, &ls->ls_nodes_gone, list) {
F_9 ( V_6 , L_14 , V_10 -> V_25 ) ;
V_91 ++ ;
}
F_44 (memb, safe, &ls->ls_nodes, list) {
V_64 = F_42 ( V_86 , V_10 -> V_25 ) ;
if ( V_64 && ! V_64 -> V_54 )
continue;
if ( ! V_64 ) {
F_9 ( V_6 , L_15 , V_10 -> V_25 ) ;
} else {
F_9 ( V_6 , L_16 ,
V_10 -> V_25 , V_10 -> V_66 , V_64 -> V_66 ) ;
}
V_91 ++ ;
F_45 ( & V_10 -> V_58 , & V_6 -> V_68 ) ;
V_6 -> V_67 -- ;
F_39 ( V_6 , V_10 ) ;
}
for ( V_22 = 0 ; V_22 < V_86 -> V_87 ; V_22 ++ ) {
V_64 = & V_86 -> V_88 [ V_22 ] ;
if ( F_25 ( V_6 , V_64 -> V_25 ) )
continue;
F_21 ( V_6 , V_64 ) ;
F_9 ( V_6 , L_17 , V_64 -> V_25 ) ;
}
F_13 (memb, &ls->ls_nodes, list) {
if ( V_92 == - 1 || V_10 -> V_25 < V_92 )
V_92 = V_10 -> V_25 ;
}
V_6 -> V_93 = V_92 ;
F_32 ( V_6 ) ;
* V_89 = V_91 ;
error = F_35 ( V_6 ) ;
if ( ! error || error == - V_94 ) {
V_6 -> V_95 = error ;
F_46 ( & V_6 -> V_96 ) ;
}
F_9 ( V_6 , L_18 , V_6 -> V_67 ) ;
return error ;
}
int F_47 ( struct V_5 * V_6 )
{
int V_54 ;
F_48 ( & V_6 -> V_97 ) ;
F_49 ( & V_6 -> V_98 ) ;
F_50 ( V_99 , & V_6 -> V_100 ) ;
V_54 = F_51 ( V_101 , & V_6 -> V_100 ) ;
V_6 -> V_102 ++ ;
F_52 ( & V_6 -> V_98 ) ;
F_53 ( & V_6 -> V_97 ) ;
if ( V_54 ) {
F_50 ( V_103 , & V_6 -> V_100 ) ;
F_54 ( V_6 -> V_104 ) ;
F_55 ( V_6 -> V_105 ,
F_56 ( V_106 , & V_6 -> V_100 ) ) ;
}
F_57 ( V_6 ) ;
F_49 ( & V_6 -> V_98 ) ;
F_16 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
V_6 -> V_107 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_108 = 0 ;
F_52 ( & V_6 -> V_98 ) ;
F_58 ( V_6 ) ;
if ( ! V_6 -> V_109 )
V_6 -> V_109 = V_110 ;
F_38 ( V_6 ) ;
return 0 ;
}
int F_59 ( struct V_5 * V_6 )
{
struct V_85 * V_86 , * V_111 ;
struct V_63 * V_88 ;
int error , V_112 ;
V_86 = F_22 ( sizeof( * V_86 ) , V_50 ) ;
if ( ! V_86 )
return - V_51 ;
error = F_60 ( V_6 -> V_113 , & V_88 , & V_112 ) ;
if ( error < 0 )
goto V_114;
F_49 ( & V_6 -> V_98 ) ;
if ( ! F_61 ( V_6 ) ) {
F_52 ( & V_6 -> V_98 ) ;
F_12 ( V_6 , L_19 ) ;
error = - V_115 ;
goto V_114;
}
V_86 -> V_88 = V_88 ;
V_86 -> V_87 = V_112 ;
V_86 -> V_79 = ++ V_6 -> V_102 ;
V_111 = V_6 -> V_116 ;
V_6 -> V_116 = V_86 ;
F_52 ( & V_6 -> V_98 ) ;
if ( V_111 ) {
F_12 ( V_6 , L_20 ,
( unsigned long long ) V_111 -> V_79 , V_111 -> V_87 ) ;
F_16 ( V_111 -> V_88 ) ;
F_16 ( V_111 ) ;
}
F_50 ( V_117 , & V_6 -> V_100 ) ;
F_54 ( V_6 -> V_104 ) ;
return 0 ;
V_114:
F_16 ( V_86 ) ;
F_16 ( V_88 ) ;
return error ;
}
