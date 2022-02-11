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
if ( ! V_37 . V_38 )
return;
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
struct V_7 * V_8 = V_6 -> V_39 ;
struct V_11 * V_12 = (struct V_11 * ) V_8 -> V_13 ;
struct V_20 * V_30 , * V_21 ;
int V_40 = F_11 () ;
int V_22 , V_29 ;
T_1 V_28 ;
if ( ! F_1 ( & V_8 -> V_14 ) )
return - 1 ;
V_28 = F_4 ( V_12 -> V_18 ) ;
if ( V_28 <= V_6 -> V_41 ) {
F_12 ( V_6 , L_3 ,
V_28 , V_6 -> V_41 ) ;
}
V_6 -> V_41 = V_28 ;
V_29 = F_3 ( V_12 -> V_42 ) ;
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
V_10 -> V_43 = V_10 -> V_15 ;
break;
}
if ( V_10 -> V_25 == V_40 ) {
if ( V_6 -> V_44 && V_6 -> V_44 != V_10 -> V_15 ) {
F_12 ( V_6 , L_4
L_5 , V_6 -> V_44 ,
V_10 -> V_15 ) ;
return - 1 ;
}
if ( ! V_6 -> V_44 )
V_6 -> V_44 = V_10 -> V_15 ;
}
if ( ! V_10 -> V_15 ) {
F_12 ( V_6 , L_6 ,
V_10 -> V_25 ) ;
return - 1 ;
}
}
return 0 ;
}
int F_14 ( struct V_5 * V_6 , int * V_29 , int * V_45 ,
struct V_19 * * V_46 , T_1 * V_47 )
{
struct V_9 * V_10 ;
struct V_19 * V_31 ;
int V_40 = F_11 () ;
int V_32 , V_48 , V_22 ;
int V_49 = 0 ;
int V_50 = 0 ;
int V_51 = 0 ;
T_1 V_28 = 0 ;
F_13 (memb, &ls->ls_nodes, list) {
if ( V_10 -> V_25 == V_40 ) {
V_10 -> V_15 = V_6 -> V_44 ;
V_10 -> V_17 = V_6 -> V_41 ;
break;
}
}
F_13 (memb, &ls->ls_nodes, list) {
if ( V_10 -> V_17 > V_28 )
V_28 = V_10 -> V_17 ;
if ( V_10 -> V_15 == - 1 )
return - 1 ;
if ( ! V_10 -> V_15 )
V_49 ++ ;
V_51 ++ ;
if ( ! V_50 || V_50 < V_10 -> V_15 )
V_50 = V_10 -> V_15 ;
if ( V_10 -> V_43 && V_10 -> V_15 && V_10 -> V_43 != V_10 -> V_15 ) {
F_12 ( V_6 , L_7 ,
V_10 -> V_25 , V_10 -> V_43 , V_10 -> V_15 ) ;
return - 1 ;
}
V_10 -> V_43 = V_10 -> V_15 ;
}
V_32 = V_50 + V_49 ;
V_31 = F_15 ( V_32 * sizeof( struct V_19 ) , V_52 ) ;
if ( ! V_31 )
return - V_53 ;
V_51 = 0 ;
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
V_51 ++ ;
}
F_13 (memb, &ls->ls_nodes, list) {
if ( V_10 -> V_15 )
continue;
for ( V_22 = 0 ; V_22 < V_32 ; V_22 ++ ) {
if ( V_31 [ V_22 ] . V_25 )
continue;
V_10 -> V_15 = V_22 + 1 ;
V_10 -> V_43 = V_10 -> V_15 ;
V_31 [ V_22 ] . V_25 = V_10 -> V_25 ;
V_31 [ V_22 ] . V_15 = V_10 -> V_15 ;
V_51 ++ ;
if ( ! V_6 -> V_44 && V_10 -> V_25 == V_40 )
V_6 -> V_44 = V_10 -> V_15 ;
break;
}
if ( ! V_10 -> V_15 ) {
F_12 ( V_6 , L_9 ) ;
F_16 ( V_31 ) ;
return - 1 ;
}
}
V_28 ++ ;
F_8 ( V_6 , V_28 , V_51 , NULL , V_31 , V_32 ) ;
V_48 = ( V_37 . V_54 - sizeof( struct V_7 ) -
sizeof( struct V_11 ) ) / sizeof( struct V_20 ) ;
if ( V_51 > V_48 ) {
F_12 ( V_6 , L_10 ,
V_51 , V_48 ) ;
F_16 ( V_31 ) ;
return - 1 ;
}
* V_47 = V_28 ;
* V_46 = V_31 ;
* V_45 = V_32 ;
* V_29 = V_51 ;
return 0 ;
}
static void F_17 ( struct V_5 * V_6 , struct V_9 * V_55 )
{
struct V_9 * V_10 = NULL ;
struct V_56 * V_57 ;
struct V_56 * V_58 = & V_55 -> V_59 ;
struct V_56 * V_60 = & V_6 -> V_61 ;
F_18 (tmp, head) {
V_10 = F_19 ( V_57 , struct V_9 , V_59 ) ;
if ( V_55 -> V_25 < V_10 -> V_25 )
break;
}
if ( ! V_10 )
F_20 ( V_58 , V_60 ) ;
else {
V_58 -> V_62 = V_57 -> V_62 ;
V_58 -> V_63 = V_57 ;
V_57 -> V_62 -> V_63 = V_58 ;
V_57 -> V_62 = V_58 ;
}
}
static int F_21 ( struct V_5 * V_6 , struct V_64 * V_65 )
{
struct V_9 * V_10 ;
int error ;
V_10 = F_15 ( sizeof( struct V_9 ) , V_52 ) ;
if ( ! V_10 )
return - V_53 ;
error = F_22 ( V_65 -> V_25 ) ;
if ( error < 0 ) {
F_16 ( V_10 ) ;
return error ;
}
V_10 -> V_25 = V_65 -> V_25 ;
V_10 -> V_66 = V_65 -> V_66 ;
V_10 -> V_67 = V_65 -> V_67 ;
F_17 ( V_6 , V_10 ) ;
V_6 -> V_68 ++ ;
return 0 ;
}
static struct V_9 * F_23 ( struct V_56 * V_60 , int V_25 )
{
struct V_9 * V_10 ;
F_13 (memb, head, list) {
if ( V_10 -> V_25 == V_25 )
return V_10 ;
}
return NULL ;
}
int F_24 ( struct V_5 * V_6 , int V_25 )
{
if ( F_23 ( & V_6 -> V_61 , V_25 ) )
return 1 ;
return 0 ;
}
int F_25 ( struct V_5 * V_6 , int V_25 )
{
if ( F_23 ( & V_6 -> V_69 , V_25 ) )
return 1 ;
return 0 ;
}
static void F_26 ( struct V_56 * V_60 )
{
struct V_9 * V_10 ;
while ( ! F_27 ( V_60 ) ) {
V_10 = F_19 ( V_60 -> V_63 , struct V_9 , V_59 ) ;
F_28 ( & V_10 -> V_59 ) ;
F_16 ( V_10 ) ;
}
}
void F_29 ( struct V_5 * V_6 )
{
F_26 ( & V_6 -> V_61 ) ;
V_6 -> V_68 = 0 ;
}
void F_30 ( struct V_5 * V_6 )
{
F_26 ( & V_6 -> V_69 ) ;
}
static void F_31 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
int V_22 , V_70 , V_71 = 0 , V_72 = 0 , V_73 = 0 , * V_31 ;
F_16 ( V_6 -> V_74 ) ;
V_6 -> V_74 = NULL ;
F_13 (memb, &ls->ls_nodes, list) {
if ( V_10 -> V_66 )
V_72 += V_10 -> V_66 ;
}
if ( ! V_72 ) {
V_72 = V_6 -> V_68 ;
V_73 = 1 ;
}
V_6 -> V_75 = V_72 ;
V_31 = F_32 ( sizeof( int ) * V_72 , V_52 ) ;
if ( ! V_31 )
return;
F_13 (memb, &ls->ls_nodes, list) {
if ( ! V_73 && ! V_10 -> V_66 )
continue;
if ( V_73 )
V_70 = 1 ;
else
V_70 = V_10 -> V_66 ;
F_33 (x < total, printk(L_11, total, x);) ;
for ( V_22 = 0 ; V_22 < V_70 ; V_22 ++ )
V_31 [ V_71 ++ ] = V_10 -> V_25 ;
}
V_6 -> V_74 = V_31 ;
}
static int F_34 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
int error = 0 ;
F_13 (memb, &ls->ls_nodes, list) {
error = F_35 ( V_6 ) ;
if ( error )
break;
error = F_36 ( V_6 , V_10 -> V_25 , 0 ) ;
if ( error )
break;
}
if ( error )
F_9 ( V_6 , L_12 ,
error , V_6 -> V_76 ) ;
return error ;
}
static void F_37 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_77 || ! V_6 -> V_77 -> V_78 )
return;
V_6 -> V_77 -> V_78 ( V_6 -> V_79 ) ;
}
static void F_38 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
struct V_19 V_15 ;
T_1 V_80 ;
int error ;
if ( ! V_6 -> V_77 || ! V_6 -> V_77 -> V_81 )
return;
error = F_39 ( V_10 -> V_25 , & V_80 ) ;
if ( ! error && V_80 == V_10 -> V_67 )
return;
V_15 . V_25 = V_10 -> V_25 ;
V_15 . V_15 = V_10 -> V_15 ;
V_6 -> V_77 -> V_81 ( V_6 -> V_79 , & V_15 ) ;
}
void F_40 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_19 * V_82 ;
int V_22 , V_51 ;
if ( ! V_6 -> V_77 || ! V_6 -> V_77 -> V_83 )
return;
V_51 = V_6 -> V_68 ;
V_82 = F_15 ( V_51 * sizeof( struct V_19 ) , V_84 ) ;
if ( ! V_82 )
return;
V_22 = 0 ;
F_13 (memb, &ls->ls_nodes, list) {
if ( V_22 == V_51 ) {
F_12 ( V_6 , L_13 , V_51 ) ;
goto V_85;
}
V_82 [ V_22 ] . V_25 = V_10 -> V_25 ;
V_82 [ V_22 ] . V_15 = V_10 -> V_15 ;
V_22 ++ ;
}
V_6 -> V_77 -> V_83 ( V_6 -> V_79 , V_82 , V_51 ,
V_6 -> V_44 , V_6 -> V_41 ) ;
V_85:
F_16 ( V_82 ) ;
}
static struct V_64 * F_41 ( struct V_86 * V_87 ,
int V_25 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_87 -> V_88 ; V_22 ++ ) {
if ( V_87 -> V_89 [ V_22 ] . V_25 == V_25 )
return & V_87 -> V_89 [ V_22 ] ;
}
return NULL ;
}
int F_42 ( struct V_5 * V_6 , struct V_86 * V_87 , int * V_90 )
{
struct V_9 * V_10 , * V_91 ;
struct V_64 * V_65 ;
int V_22 , error , V_92 = 0 , V_93 = - 1 ;
F_13 (memb, &ls->ls_nodes_gone, list) {
F_9 ( V_6 , L_14 , V_10 -> V_25 ) ;
V_92 ++ ;
}
F_43 (memb, safe, &ls->ls_nodes, list) {
V_65 = F_41 ( V_87 , V_10 -> V_25 ) ;
if ( V_65 && ! V_65 -> V_55 )
continue;
if ( ! V_65 ) {
F_9 ( V_6 , L_15 , V_10 -> V_25 ) ;
} else {
F_9 ( V_6 , L_16 ,
V_10 -> V_25 , V_10 -> V_67 , V_65 -> V_67 ) ;
}
V_92 ++ ;
F_44 ( & V_10 -> V_59 , & V_6 -> V_69 ) ;
V_6 -> V_68 -- ;
F_38 ( V_6 , V_10 ) ;
}
for ( V_22 = 0 ; V_22 < V_87 -> V_88 ; V_22 ++ ) {
V_65 = & V_87 -> V_89 [ V_22 ] ;
if ( F_24 ( V_6 , V_65 -> V_25 ) )
continue;
F_21 ( V_6 , V_65 ) ;
F_9 ( V_6 , L_17 , V_65 -> V_25 ) ;
}
F_13 (memb, &ls->ls_nodes, list) {
if ( V_93 == - 1 || V_10 -> V_25 < V_93 )
V_93 = V_10 -> V_25 ;
}
V_6 -> V_94 = V_93 ;
F_31 ( V_6 ) ;
* V_90 = V_92 ;
error = F_34 ( V_6 ) ;
if ( ! error || error == - V_95 ) {
V_6 -> V_96 = error ;
F_45 ( & V_6 -> V_97 ) ;
}
F_9 ( V_6 , L_18 , V_6 -> V_68 ) ;
return error ;
}
int F_46 ( struct V_5 * V_6 )
{
int V_55 ;
F_47 ( & V_6 -> V_98 ) ;
F_48 ( & V_6 -> V_99 ) ;
F_49 ( V_100 , & V_6 -> V_101 ) ;
V_55 = F_50 ( V_102 , & V_6 -> V_101 ) ;
V_6 -> V_103 ++ ;
F_51 ( & V_6 -> V_99 ) ;
F_52 ( & V_6 -> V_98 ) ;
if ( V_55 )
F_47 ( & V_6 -> V_104 ) ;
F_53 ( V_6 ) ;
F_48 ( & V_6 -> V_99 ) ;
F_16 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
V_6 -> V_105 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_106 = 0 ;
F_51 ( & V_6 -> V_99 ) ;
F_54 ( V_6 ) ;
if ( ! V_6 -> V_107 )
V_6 -> V_107 = V_108 ;
F_37 ( V_6 ) ;
return 0 ;
}
int F_55 ( struct V_5 * V_6 )
{
struct V_86 * V_87 = NULL , * V_109 ;
struct V_64 * V_89 ;
int error , V_110 ;
V_87 = F_15 ( sizeof( struct V_86 ) , V_52 ) ;
if ( ! V_87 )
return - V_53 ;
error = F_56 ( V_6 -> V_111 , & V_89 , & V_110 ) ;
if ( error < 0 )
goto V_112;
F_48 ( & V_6 -> V_99 ) ;
if ( ! F_57 ( V_6 ) ) {
F_51 ( & V_6 -> V_99 ) ;
F_12 ( V_6 , L_19 ) ;
error = - V_113 ;
goto V_112;
}
V_87 -> V_89 = V_89 ;
V_87 -> V_88 = V_110 ;
V_87 -> V_80 = ++ V_6 -> V_103 ;
V_109 = V_6 -> V_114 ;
V_6 -> V_114 = V_87 ;
F_51 ( & V_6 -> V_99 ) ;
if ( V_109 ) {
F_12 ( V_6 , L_20 ,
( unsigned long long ) V_109 -> V_80 , V_109 -> V_88 ) ;
F_16 ( V_109 -> V_89 ) ;
F_16 ( V_109 ) ;
}
F_58 ( V_6 ) ;
return 0 ;
V_112:
F_16 ( V_87 ) ;
F_16 ( V_89 ) ;
return error ;
}
