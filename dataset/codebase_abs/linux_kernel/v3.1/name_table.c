static int F_1 ( int V_1 )
{
return V_1 & ( V_2 - 1 ) ;
}
static struct V_3 * F_2 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 )
{
struct V_3 * V_10 = F_3 ( sizeof( * V_10 ) , V_11 ) ;
if ( V_10 == NULL ) {
F_4 ( L_1 ) ;
return NULL ;
}
V_10 -> type = type ;
V_10 -> V_4 = V_4 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_7 = V_7 ;
V_10 -> V_12 = V_8 ;
V_10 -> V_9 = V_9 ;
F_5 ( & V_10 -> V_13 ) ;
F_5 ( & V_10 -> V_14 ) ;
F_5 ( & V_10 -> V_15 . V_16 ) ;
return V_10 ;
}
static struct V_17 * F_6 ( T_1 V_18 )
{
struct V_17 * V_19 = F_7 ( V_18 , sizeof( struct V_17 ) , V_11 ) ;
return V_19 ;
}
static struct V_20 * F_8 ( T_1 type , struct V_21 * V_22 )
{
struct V_20 * V_23 = F_3 ( sizeof( * V_23 ) , V_11 ) ;
struct V_17 * V_19 = F_6 ( 1 ) ;
if ( ! V_23 || ! V_19 ) {
F_4 ( L_2 ) ;
F_9 ( V_23 ) ;
F_9 ( V_19 ) ;
return NULL ;
}
F_10 ( & V_23 -> V_24 ) ;
V_23 -> type = type ;
V_23 -> V_25 = V_19 ;
V_23 -> V_26 = 1 ;
F_11 ( & V_23 -> V_27 ) ;
F_5 ( & V_23 -> V_28 ) ;
F_12 ( & V_23 -> V_27 , V_22 ) ;
return V_23 ;
}
static struct V_17 * F_13 ( struct V_20 * V_23 ,
T_1 V_29 )
{
struct V_17 * V_25 = V_23 -> V_25 ;
int V_30 = 0 ;
int V_31 = V_23 -> V_32 - 1 ;
int V_33 ;
while ( V_30 <= V_31 ) {
V_33 = ( V_30 + V_31 ) / 2 ;
if ( V_29 < V_25 [ V_33 ] . V_4 )
V_31 = V_33 - 1 ;
else if ( V_29 > V_25 [ V_33 ] . V_5 )
V_30 = V_33 + 1 ;
else
return & V_25 [ V_33 ] ;
}
return NULL ;
}
static T_1 F_14 ( struct V_20 * V_23 , T_1 V_29 )
{
struct V_17 * V_25 = V_23 -> V_25 ;
int V_30 = 0 ;
int V_31 = V_23 -> V_32 - 1 ;
int V_33 ;
while ( V_30 <= V_31 ) {
V_33 = ( V_30 + V_31 ) / 2 ;
if ( V_29 < V_25 [ V_33 ] . V_4 )
V_31 = V_33 - 1 ;
else if ( V_29 > V_25 [ V_33 ] . V_5 )
V_30 = V_33 + 1 ;
else
return V_33 ;
}
return V_30 ;
}
static struct V_3 * F_15 ( struct V_20 * V_23 ,
T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_34 , T_1 V_9 )
{
struct V_35 * V_36 ;
struct V_35 * V_37 ;
struct V_3 * V_10 ;
struct V_17 * V_19 ;
struct V_38 * V_39 ;
int V_40 = 0 ;
V_19 = F_13 ( V_23 , V_4 ) ;
if ( V_19 ) {
if ( ( V_19 -> V_4 != V_4 ) || ( V_19 -> V_5 != V_5 ) ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
V_39 = V_19 -> V_39 ;
} else {
T_1 V_41 ;
struct V_17 * V_42 ;
V_41 = F_14 ( V_23 , V_4 ) ;
if ( ( V_41 < V_23 -> V_32 ) &&
( V_5 >= V_23 -> V_25 [ V_41 ] . V_4 ) ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
if ( V_23 -> V_32 == V_23 -> V_26 ) {
struct V_17 * V_25 = F_6 ( V_23 -> V_26 * 2 ) ;
if ( ! V_25 ) {
F_4 ( L_4 ,
type , V_4 , V_5 ) ;
return NULL ;
}
memcpy ( V_25 , V_23 -> V_25 ,
V_23 -> V_26 * sizeof( struct V_17 ) ) ;
F_9 ( V_23 -> V_25 ) ;
V_23 -> V_25 = V_25 ;
V_23 -> V_26 *= 2 ;
}
V_39 = F_3 ( sizeof( * V_39 ) , V_11 ) ;
if ( ! V_39 ) {
F_4 ( L_4 ,
type , V_4 , V_5 ) ;
return NULL ;
}
F_5 ( & V_39 -> V_43 ) ;
F_5 ( & V_39 -> V_44 ) ;
F_5 ( & V_39 -> V_45 ) ;
V_19 = & V_23 -> V_25 [ V_41 ] ;
V_42 = & V_23 -> V_25 [ V_23 -> V_32 ] ;
memmove ( V_19 + 1 , V_19 , ( V_42 - V_19 ) * sizeof( * V_19 ) ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_23 -> V_32 ++ ;
V_19 -> V_4 = V_4 ;
V_19 -> V_5 = V_5 ;
V_19 -> V_39 = V_39 ;
V_40 = 1 ;
}
V_10 = F_2 ( type , V_4 , V_5 , V_6 , V_7 , V_34 , V_9 ) ;
if ( ! V_10 )
return NULL ;
F_16 ( & V_10 -> V_45 , & V_39 -> V_45 ) ;
V_39 -> V_46 ++ ;
if ( F_17 ( V_7 ) ) {
F_16 ( & V_10 -> V_44 , & V_39 -> V_44 ) ;
V_39 -> V_47 ++ ;
}
if ( V_7 == V_48 ) {
F_16 ( & V_10 -> V_43 , & V_39 -> V_43 ) ;
V_39 -> V_49 ++ ;
}
F_18 (s, st, &nseq->subscriptions, nameseq_list) {
F_19 ( V_36 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_50 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_40 ) ;
}
return V_10 ;
}
static struct V_3 * F_20 ( struct V_20 * V_23 , T_1 V_51 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_17 * V_19 = F_13 ( V_23 , V_51 ) ;
struct V_38 * V_39 ;
struct V_17 * free ;
struct V_35 * V_36 , * V_37 ;
int V_52 = 0 ;
if ( ! V_19 )
return NULL ;
V_39 = V_19 -> V_39 ;
F_21 (publ, &info->zone_list, zone_list) {
if ( ( V_10 -> V_9 == V_9 ) && ( V_10 -> V_12 == V_12 ) &&
( ! V_10 -> V_7 || ( V_10 -> V_7 == V_7 ) ) )
goto V_53;
}
return NULL ;
V_53:
F_22 ( & V_10 -> V_45 ) ;
V_39 -> V_46 -- ;
if ( F_17 ( V_7 ) ) {
F_22 ( & V_10 -> V_44 ) ;
V_39 -> V_47 -- ;
}
if ( V_7 == V_48 ) {
F_22 ( & V_10 -> V_43 ) ;
V_39 -> V_49 -- ;
}
if ( F_23 ( & V_39 -> V_45 ) ) {
F_9 ( V_39 ) ;
free = & V_23 -> V_25 [ V_23 -> V_32 -- ] ;
memmove ( V_19 , V_19 + 1 , ( free - ( V_19 + 1 ) ) * sizeof( * V_19 ) ) ;
V_52 = 1 ;
}
F_18 (s, st, &nseq->subscriptions, nameseq_list) {
F_19 ( V_36 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_54 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_52 ) ;
}
return V_10 ;
}
static void F_24 ( struct V_20 * V_23 , struct V_35 * V_36 )
{
struct V_17 * V_19 = V_23 -> V_25 ;
F_16 ( & V_36 -> V_55 , & V_23 -> V_28 ) ;
if ( ! V_19 )
return;
while ( V_19 != & V_23 -> V_25 [ V_23 -> V_32 ] ) {
if ( F_25 ( V_36 , V_19 -> V_4 , V_19 -> V_5 ) ) {
struct V_3 * V_56 ;
struct V_38 * V_39 = V_19 -> V_39 ;
int V_57 = 1 ;
F_21 (crs, &info->zone_list, zone_list) {
F_19 ( V_36 ,
V_19 -> V_4 ,
V_19 -> V_5 ,
V_50 ,
V_56 -> V_12 ,
V_56 -> V_7 ,
V_57 ) ;
V_57 = 0 ;
}
}
V_19 ++ ;
}
}
static struct V_20 * F_26 ( T_1 type )
{
struct V_21 * V_22 ;
struct V_58 * V_59 ;
struct V_20 * V_60 ;
V_22 = & V_61 . V_62 [ F_1 ( type ) ] ;
F_27 (ns, seq_node, seq_head, ns_list) {
if ( V_60 -> type == type )
return V_60 ;
}
return NULL ;
}
struct V_3 * F_28 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_34 , T_1 V_9 )
{
struct V_20 * V_63 = F_26 ( type ) ;
if ( V_4 > V_5 ) {
F_4 ( L_5 ,
type , V_4 , V_5 ) ;
return NULL ;
}
if ( ! V_63 )
V_63 = F_8 ( type , & V_61 . V_62 [ F_1 ( type ) ] ) ;
if ( ! V_63 )
return NULL ;
return F_15 ( V_63 , type , V_4 , V_5 ,
V_6 , V_7 , V_34 , V_9 ) ;
}
struct V_3 * F_29 ( T_1 type , T_1 V_4 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_20 * V_63 = F_26 ( type ) ;
if ( ! V_63 )
return NULL ;
V_10 = F_20 ( V_63 , V_4 , V_7 , V_12 , V_9 ) ;
if ( ! V_63 -> V_32 && F_23 ( & V_63 -> V_28 ) ) {
F_30 ( & V_63 -> V_27 ) ;
F_9 ( V_63 -> V_25 ) ;
F_9 ( V_63 ) ;
}
return V_10 ;
}
T_1 F_31 ( T_1 type , T_1 V_29 , T_1 * V_64 )
{
struct V_17 * V_19 ;
struct V_38 * V_39 ;
struct V_3 * V_10 ;
struct V_20 * V_63 ;
T_1 V_12 = 0 ;
if ( ! F_32 ( * V_64 , V_48 ) )
return 0 ;
F_33 ( & V_65 ) ;
V_63 = F_26 ( type ) ;
if ( F_34 ( ! V_63 ) )
goto V_66;
V_19 = F_13 ( V_63 , V_29 ) ;
if ( F_34 ( ! V_19 ) )
goto V_66;
F_35 ( & V_63 -> V_24 ) ;
V_39 = V_19 -> V_39 ;
if ( F_36 ( ! * V_64 ) ) {
if ( ! F_23 ( & V_39 -> V_43 ) ) {
V_10 = F_37 ( & V_39 -> V_43 ,
struct V_3 ,
V_43 ) ;
F_38 ( & V_10 -> V_43 ,
& V_39 -> V_43 ) ;
} else if ( ! F_23 ( & V_39 -> V_44 ) ) {
V_10 = F_37 ( & V_39 -> V_44 ,
struct V_3 ,
V_44 ) ;
F_38 ( & V_10 -> V_44 ,
& V_39 -> V_44 ) ;
} else {
V_10 = F_37 ( & V_39 -> V_45 ,
struct V_3 ,
V_45 ) ;
F_38 ( & V_10 -> V_45 ,
& V_39 -> V_45 ) ;
}
}
else if ( * V_64 == V_48 ) {
if ( F_23 ( & V_39 -> V_43 ) )
goto V_67;
V_10 = F_37 ( & V_39 -> V_43 , struct V_3 ,
V_43 ) ;
F_38 ( & V_10 -> V_43 , & V_39 -> V_43 ) ;
} else if ( F_17 ( * V_64 ) ) {
if ( F_23 ( & V_39 -> V_44 ) )
goto V_67;
V_10 = F_37 ( & V_39 -> V_44 , struct V_3 ,
V_44 ) ;
F_38 ( & V_10 -> V_44 , & V_39 -> V_44 ) ;
} else {
V_10 = F_37 ( & V_39 -> V_45 , struct V_3 ,
V_45 ) ;
F_38 ( & V_10 -> V_45 , & V_39 -> V_45 ) ;
}
V_12 = V_10 -> V_12 ;
* V_64 = V_10 -> V_7 ;
V_67:
F_39 ( & V_63 -> V_24 ) ;
V_66:
F_40 ( & V_65 ) ;
return V_12 ;
}
int F_41 ( T_1 type , T_1 V_4 , T_1 V_5 , T_1 V_68 ,
struct V_69 * V_70 )
{
struct V_20 * V_63 ;
struct V_17 * V_19 ;
struct V_17 * V_71 ;
struct V_38 * V_39 ;
int V_72 = 0 ;
F_33 ( & V_65 ) ;
V_63 = F_26 ( type ) ;
if ( ! V_63 )
goto exit;
F_35 ( & V_63 -> V_24 ) ;
V_19 = V_63 -> V_25 + F_14 ( V_63 , V_4 ) ;
V_71 = V_63 -> V_25 + V_63 -> V_32 ;
for (; V_19 != V_71 ; V_19 ++ ) {
struct V_3 * V_10 ;
if ( V_19 -> V_4 > V_5 )
break;
V_39 = V_19 -> V_39 ;
F_21 (publ, &info->node_list, node_list) {
if ( V_10 -> V_6 <= V_68 )
F_42 ( V_70 , V_10 -> V_12 ) ;
}
if ( V_39 -> V_47 != V_39 -> V_49 )
V_72 = 1 ;
}
F_39 ( & V_63 -> V_24 ) ;
exit:
F_40 ( & V_65 ) ;
return V_72 ;
}
int F_43 ( T_1 V_12 , unsigned int V_6 ,
struct V_73 const * V_63 )
{
int V_72 ;
F_44 ( & V_74 ) ;
V_72 = F_45 ( V_12 , V_6 , V_63 ) ;
F_46 ( & V_74 ) ;
return V_72 ;
}
struct V_3 * F_47 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_8 , T_1 V_9 )
{
struct V_3 * V_10 ;
if ( V_61 . V_75 >= V_76 ) {
F_4 ( L_6 ,
V_76 ) ;
return NULL ;
}
if ( ( type < V_77 ) && ! F_48 ( & V_74 ) ) {
F_4 ( L_7 ,
type , V_4 , V_5 ) ;
return NULL ;
}
F_49 ( & V_65 ) ;
V_61 . V_75 ++ ;
V_10 = F_28 ( type , V_4 , V_5 , V_6 ,
V_48 , V_8 , V_9 ) ;
if ( V_10 && ( V_6 != V_78 ) )
F_50 ( V_10 ) ;
F_51 ( & V_65 ) ;
return V_10 ;
}
int F_52 ( T_1 type , T_1 V_4 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
F_49 ( & V_65 ) ;
V_10 = F_29 ( type , V_4 , V_48 , V_12 , V_9 ) ;
if ( F_36 ( V_10 ) ) {
V_61 . V_75 -- ;
if ( V_10 -> V_6 != V_78 )
F_53 ( V_10 ) ;
F_51 ( & V_65 ) ;
F_54 ( & V_10 -> V_14 ) ;
F_9 ( V_10 ) ;
return 1 ;
}
F_51 ( & V_65 ) ;
F_55 ( L_8
L_9 ,
type , V_4 , V_12 , V_9 ) ;
return 0 ;
}
void F_56 ( struct V_35 * V_36 )
{
T_1 type = V_36 -> V_63 . type ;
struct V_20 * V_63 ;
F_49 ( & V_65 ) ;
V_63 = F_26 ( type ) ;
if ( ! V_63 )
V_63 = F_8 ( type , & V_61 . V_62 [ F_1 ( type ) ] ) ;
if ( V_63 ) {
F_35 ( & V_63 -> V_24 ) ;
F_24 ( V_63 , V_36 ) ;
F_39 ( & V_63 -> V_24 ) ;
} else {
F_4 ( L_10 ,
V_36 -> V_63 . type , V_36 -> V_63 . V_4 , V_36 -> V_63 . V_5 ) ;
}
F_51 ( & V_65 ) ;
}
void F_57 ( struct V_35 * V_36 )
{
struct V_20 * V_63 ;
F_49 ( & V_65 ) ;
V_63 = F_26 ( V_36 -> V_63 . type ) ;
if ( V_63 != NULL ) {
F_35 ( & V_63 -> V_24 ) ;
F_54 ( & V_36 -> V_55 ) ;
F_39 ( & V_63 -> V_24 ) ;
if ( ( V_63 -> V_32 == 0 ) && F_23 ( & V_63 -> V_28 ) ) {
F_30 ( & V_63 -> V_27 ) ;
F_9 ( V_63 -> V_25 ) ;
F_9 ( V_63 ) ;
}
}
F_51 ( & V_65 ) ;
}
static void F_58 ( struct V_17 * V_19 , struct V_79 * V_80 , T_1 V_81 ,
T_1 V_82 )
{
char V_83 [ 27 ] ;
const char * V_84 [] = { L_11 , L_12 , L_13 , L_14 } ;
struct V_3 * V_10 ;
struct V_38 * V_39 ;
F_59 ( V_80 , L_15 , V_19 -> V_4 , V_19 -> V_5 ) ;
if ( V_81 == 2 ) {
F_59 ( V_80 , L_16 ) ;
return;
}
V_39 = V_19 -> V_39 ;
F_21 (publ, &info->zone_list, zone_list) {
sprintf ( V_83 , L_17 ,
F_60 ( V_10 -> V_7 ) , F_61 ( V_10 -> V_7 ) ,
F_62 ( V_10 -> V_7 ) , V_10 -> V_12 ) ;
F_59 ( V_80 , L_18 , V_83 ) ;
if ( V_81 > 3 ) {
F_59 ( V_80 , L_19 , V_10 -> V_9 ,
V_84 [ V_10 -> V_6 ] ) ;
}
if ( ! F_63 ( & V_10 -> V_45 , & V_39 -> V_45 ) )
F_59 ( V_80 , L_20 , L_21 ) ;
} ;
F_59 ( V_80 , L_16 ) ;
}
static void V_55 ( struct V_20 * V_63 , struct V_79 * V_80 , T_1 V_81 ,
T_1 type , T_1 V_85 , T_1 V_86 , T_1 V_82 )
{
struct V_17 * V_19 ;
char V_87 [ 11 ] ;
if ( V_63 -> V_32 == 0 )
return;
sprintf ( V_87 , L_22 , V_63 -> type ) ;
if ( V_81 == 1 ) {
F_59 ( V_80 , L_23 , V_87 ) ;
return;
}
for ( V_19 = V_63 -> V_25 ; V_19 != & V_63 -> V_25 [ V_63 -> V_32 ] ; V_19 ++ ) {
if ( ( V_85 <= V_19 -> V_5 ) && ( V_86 >= V_19 -> V_4 ) ) {
F_59 ( V_80 , L_24 , V_87 ) ;
F_35 ( & V_63 -> V_24 ) ;
F_58 ( V_19 , V_80 , V_81 , V_82 ) ;
F_39 ( & V_63 -> V_24 ) ;
sprintf ( V_87 , L_25 , L_21 ) ;
}
}
}
static void F_64 ( struct V_79 * V_80 , T_1 V_81 )
{
const char * V_88 [] = {
L_26 ,
L_27 ,
L_28 ,
L_29
} ;
int V_89 ;
if ( V_81 > 4 )
V_81 = 4 ;
for ( V_89 = 0 ; V_89 < V_81 ; V_89 ++ )
F_59 ( V_80 , V_88 [ V_89 ] ) ;
F_59 ( V_80 , L_16 ) ;
}
static void F_65 ( struct V_79 * V_80 , T_1 V_90 ,
T_1 type , T_1 V_85 , T_1 V_86 )
{
struct V_21 * V_22 ;
struct V_58 * V_59 ;
struct V_20 * V_63 ;
int V_91 ;
T_1 V_81 ;
T_1 V_89 ;
V_91 = ( V_90 & V_92 ) ;
V_81 = ( V_90 & ~ V_92 ) ;
if ( V_81 == 0 )
return;
if ( V_91 ) {
F_64 ( V_80 , V_81 ) ;
V_85 = 0 ;
V_86 = ~ 0 ;
for ( V_89 = 0 ; V_89 < V_2 ; V_89 ++ ) {
V_22 = & V_61 . V_62 [ V_89 ] ;
F_27 (seq, seq_node, seq_head, ns_list) {
V_55 ( V_63 , V_80 , V_81 , V_63 -> type ,
V_85 , V_86 , V_89 ) ;
}
}
} else {
if ( V_86 < V_85 ) {
F_59 ( V_80 , L_30 ) ;
return;
}
F_64 ( V_80 , V_81 ) ;
V_89 = F_1 ( type ) ;
V_22 = & V_61 . V_62 [ V_89 ] ;
F_27 (seq, seq_node, seq_head, ns_list) {
if ( V_63 -> type == type ) {
V_55 ( V_63 , V_80 , V_81 , type ,
V_85 , V_86 , V_89 ) ;
break;
}
}
}
}
struct V_93 * F_66 ( const void * V_94 , int V_95 )
{
struct V_93 * V_80 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_79 V_100 ;
int V_101 ;
if ( ! F_67 ( V_94 , V_95 , V_102 ) )
return F_68 ( V_103 ) ;
V_80 = F_69 ( F_70 ( V_104 ) ) ;
if ( ! V_80 )
return NULL ;
V_99 = (struct V_98 * ) V_80 -> V_105 ;
F_71 ( & V_100 , F_72 ( V_99 ) , V_104 ) ;
V_97 = (struct V_96 * ) F_72 ( V_94 ) ;
F_33 ( & V_65 ) ;
F_65 ( & V_100 , F_73 ( V_97 -> V_81 ) , F_73 ( V_97 -> type ) ,
F_73 ( V_97 -> V_85 ) , F_73 ( V_97 -> V_86 ) ) ;
F_40 ( & V_65 ) ;
V_101 = F_74 ( & V_100 ) ;
F_75 ( V_80 , F_70 ( V_101 ) ) ;
F_76 ( V_99 , V_106 , NULL , V_101 ) ;
return V_80 ;
}
int F_77 ( void )
{
V_61 . V_62 = F_7 ( V_2 , sizeof( struct V_21 ) ,
V_11 ) ;
if ( ! V_61 . V_62 )
return - V_107 ;
V_61 . V_75 = 0 ;
return 0 ;
}
void F_78 ( void )
{
T_1 V_89 ;
if ( ! V_61 . V_62 )
return;
F_49 ( & V_65 ) ;
for ( V_89 = 0 ; V_89 < V_2 ; V_89 ++ ) {
if ( ! F_79 ( & V_61 . V_62 [ V_89 ] ) )
F_55 ( L_31 , V_89 ) ;
}
F_9 ( V_61 . V_62 ) ;
V_61 . V_62 = NULL ;
F_51 ( & V_65 ) ;
}
