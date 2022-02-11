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
return V_10 ;
}
static struct V_14 * F_6 ( T_1 V_15 )
{
return F_7 ( V_15 , sizeof( struct V_14 ) , V_11 ) ;
}
static struct V_16 * F_8 ( T_1 type , struct V_17 * V_18 )
{
struct V_16 * V_19 = F_3 ( sizeof( * V_19 ) , V_11 ) ;
struct V_14 * V_20 = F_6 ( 1 ) ;
if ( ! V_19 || ! V_20 ) {
F_4 ( L_2 ) ;
F_9 ( V_19 ) ;
F_9 ( V_20 ) ;
return NULL ;
}
F_10 ( & V_19 -> V_21 ) ;
V_19 -> type = type ;
V_19 -> V_22 = V_20 ;
V_19 -> V_23 = 1 ;
F_11 ( & V_19 -> V_24 ) ;
F_5 ( & V_19 -> V_25 ) ;
F_12 ( & V_19 -> V_24 , V_18 ) ;
return V_19 ;
}
static struct V_14 * F_13 ( struct V_16 * V_19 ,
T_1 V_26 )
{
struct V_14 * V_22 = V_19 -> V_22 ;
int V_27 = 0 ;
int V_28 = V_19 -> V_29 - 1 ;
int V_30 ;
while ( V_27 <= V_28 ) {
V_30 = ( V_27 + V_28 ) / 2 ;
if ( V_26 < V_22 [ V_30 ] . V_4 )
V_28 = V_30 - 1 ;
else if ( V_26 > V_22 [ V_30 ] . V_5 )
V_27 = V_30 + 1 ;
else
return & V_22 [ V_30 ] ;
}
return NULL ;
}
static T_1 F_14 ( struct V_16 * V_19 , T_1 V_26 )
{
struct V_14 * V_22 = V_19 -> V_22 ;
int V_27 = 0 ;
int V_28 = V_19 -> V_29 - 1 ;
int V_30 ;
while ( V_27 <= V_28 ) {
V_30 = ( V_27 + V_28 ) / 2 ;
if ( V_26 < V_22 [ V_30 ] . V_4 )
V_28 = V_30 - 1 ;
else if ( V_26 > V_22 [ V_30 ] . V_5 )
V_27 = V_30 + 1 ;
else
return V_30 ;
}
return V_27 ;
}
static struct V_3 * F_15 ( struct V_31 * V_31 ,
struct V_16 * V_19 ,
T_1 type , T_1 V_4 ,
T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_32 , T_1 V_9 )
{
struct V_33 * V_34 ;
struct V_33 * V_35 ;
struct V_3 * V_10 ;
struct V_14 * V_20 ;
struct V_36 * V_37 ;
int V_38 = 0 ;
V_20 = F_13 ( V_19 , V_4 ) ;
if ( V_20 ) {
if ( ( V_20 -> V_4 != V_4 ) || ( V_20 -> V_5 != V_5 ) ) {
return NULL ;
}
V_37 = V_20 -> V_37 ;
F_16 (publ, &info->zone_list, zone_list) {
if ( ( V_10 -> V_12 == V_32 ) && ( V_10 -> V_9 == V_9 ) &&
( ! V_10 -> V_7 || ( V_10 -> V_7 == V_7 ) ) )
return NULL ;
}
} else {
T_1 V_39 ;
struct V_14 * V_40 ;
V_39 = F_14 ( V_19 , V_4 ) ;
if ( ( V_39 < V_19 -> V_29 ) &&
( V_5 >= V_19 -> V_22 [ V_39 ] . V_4 ) ) {
return NULL ;
}
if ( V_19 -> V_29 == V_19 -> V_23 ) {
struct V_14 * V_22 = F_6 ( V_19 -> V_23 * 2 ) ;
if ( ! V_22 ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
memcpy ( V_22 , V_19 -> V_22 ,
V_19 -> V_23 * sizeof( struct V_14 ) ) ;
F_9 ( V_19 -> V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_23 *= 2 ;
}
V_37 = F_3 ( sizeof( * V_37 ) , V_11 ) ;
if ( ! V_37 ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
F_5 ( & V_37 -> V_41 ) ;
F_5 ( & V_37 -> V_42 ) ;
F_5 ( & V_37 -> V_43 ) ;
V_20 = & V_19 -> V_22 [ V_39 ] ;
V_40 = & V_19 -> V_22 [ V_19 -> V_29 ] ;
memmove ( V_20 + 1 , V_20 , ( V_40 - V_20 ) * sizeof( * V_20 ) ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_19 -> V_29 ++ ;
V_20 -> V_4 = V_4 ;
V_20 -> V_5 = V_5 ;
V_20 -> V_37 = V_37 ;
V_38 = 1 ;
}
V_10 = F_2 ( type , V_4 , V_5 , V_6 , V_7 , V_32 , V_9 ) ;
if ( ! V_10 )
return NULL ;
F_17 ( & V_10 -> V_43 , & V_37 -> V_43 ) ;
V_37 -> V_44 ++ ;
if ( F_18 ( V_31 , V_7 ) ) {
F_17 ( & V_10 -> V_42 , & V_37 -> V_42 ) ;
V_37 -> V_45 ++ ;
}
if ( F_19 ( V_31 , V_7 ) ) {
F_17 ( & V_10 -> V_41 , & V_37 -> V_41 ) ;
V_37 -> V_46 ++ ;
}
F_20 (s, st, &nseq->subscriptions, nameseq_list) {
F_21 ( V_34 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_47 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_38 ) ;
}
return V_10 ;
}
static struct V_3 * F_22 ( struct V_31 * V_31 ,
struct V_16 * V_19 ,
T_1 V_48 , T_1 V_7 ,
T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_14 * V_20 = F_13 ( V_19 , V_48 ) ;
struct V_36 * V_37 ;
struct V_14 * free ;
struct V_33 * V_34 , * V_35 ;
int V_49 = 0 ;
if ( ! V_20 )
return NULL ;
V_37 = V_20 -> V_37 ;
F_16 (publ, &info->zone_list, zone_list) {
if ( ( V_10 -> V_9 == V_9 ) && ( V_10 -> V_12 == V_12 ) &&
( ! V_10 -> V_7 || ( V_10 -> V_7 == V_7 ) ) )
goto V_50;
}
return NULL ;
V_50:
F_23 ( & V_10 -> V_43 ) ;
V_37 -> V_44 -- ;
if ( F_18 ( V_31 , V_7 ) ) {
F_23 ( & V_10 -> V_42 ) ;
V_37 -> V_45 -- ;
}
if ( F_19 ( V_31 , V_7 ) ) {
F_23 ( & V_10 -> V_41 ) ;
V_37 -> V_46 -- ;
}
if ( F_24 ( & V_37 -> V_43 ) ) {
F_9 ( V_37 ) ;
free = & V_19 -> V_22 [ V_19 -> V_29 -- ] ;
memmove ( V_20 , V_20 + 1 , ( free - ( V_20 + 1 ) ) * sizeof( * V_20 ) ) ;
V_49 = 1 ;
}
F_20 (s, st, &nseq->subscriptions, nameseq_list) {
F_21 ( V_34 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_51 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_49 ) ;
}
return V_10 ;
}
static void F_25 ( struct V_16 * V_19 ,
struct V_33 * V_34 )
{
struct V_14 * V_20 = V_19 -> V_22 ;
F_17 ( & V_34 -> V_52 , & V_19 -> V_25 ) ;
if ( ! V_20 )
return;
while ( V_20 != & V_19 -> V_22 [ V_19 -> V_29 ] ) {
if ( F_26 ( V_34 , V_20 -> V_4 , V_20 -> V_5 ) ) {
struct V_3 * V_53 ;
struct V_36 * V_37 = V_20 -> V_37 ;
int V_54 = 1 ;
F_16 (crs, &info->zone_list, zone_list) {
F_21 ( V_34 ,
V_20 -> V_4 ,
V_20 -> V_5 ,
V_47 ,
V_53 -> V_12 ,
V_53 -> V_7 ,
V_54 ) ;
V_54 = 0 ;
}
}
V_20 ++ ;
}
}
static struct V_16 * F_27 ( struct V_31 * V_31 , T_1 type )
{
struct V_55 * V_56 = F_28 ( V_31 , V_57 ) ;
struct V_17 * V_18 ;
struct V_16 * V_58 ;
V_18 = & V_56 -> V_59 -> V_60 [ F_1 ( type ) ] ;
F_29 (ns, seq_head, ns_list) {
if ( V_58 -> type == type )
return V_58 ;
}
return NULL ;
}
struct V_3 * F_30 ( struct V_31 * V_31 , T_1 type ,
T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_32 , T_1 V_9 )
{
struct V_55 * V_56 = F_28 ( V_31 , V_57 ) ;
struct V_3 * V_10 ;
struct V_16 * V_61 = F_27 ( V_31 , type ) ;
int V_62 = F_1 ( type ) ;
if ( ( V_6 < V_63 ) || ( V_6 > V_64 ) ||
( V_4 > V_5 ) ) {
F_31 ( L_4 ,
type , V_4 , V_5 , V_6 ) ;
return NULL ;
}
if ( ! V_61 )
V_61 = F_8 ( type , & V_56 -> V_59 -> V_60 [ V_62 ] ) ;
if ( ! V_61 )
return NULL ;
F_32 ( & V_61 -> V_21 ) ;
V_10 = F_15 ( V_31 , V_61 , type , V_4 , V_5 ,
V_6 , V_7 , V_32 , V_9 ) ;
F_33 ( & V_61 -> V_21 ) ;
return V_10 ;
}
struct V_3 * F_34 ( struct V_31 * V_31 , T_1 type ,
T_1 V_4 , T_1 V_7 , T_1 V_12 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_16 * V_61 = F_27 ( V_31 , type ) ;
if ( ! V_61 )
return NULL ;
F_32 ( & V_61 -> V_21 ) ;
V_10 = F_22 ( V_31 , V_61 , V_4 , V_7 , V_12 , V_9 ) ;
if ( ! V_61 -> V_29 && F_24 ( & V_61 -> V_25 ) ) {
F_35 ( & V_61 -> V_24 ) ;
F_9 ( V_61 -> V_22 ) ;
F_33 ( & V_61 -> V_21 ) ;
F_36 ( V_61 , V_65 ) ;
return V_10 ;
}
F_33 ( & V_61 -> V_21 ) ;
return V_10 ;
}
T_1 F_37 ( struct V_31 * V_31 , T_1 type , T_1 V_26 ,
T_1 * V_66 )
{
struct V_55 * V_56 = F_28 ( V_31 , V_57 ) ;
struct V_14 * V_20 ;
struct V_36 * V_37 ;
struct V_3 * V_10 ;
struct V_16 * V_61 ;
T_1 V_12 = 0 ;
T_1 V_7 = 0 ;
if ( ! F_38 ( * V_66 , V_56 -> V_67 ) )
return 0 ;
F_39 () ;
V_61 = F_27 ( V_31 , type ) ;
if ( F_40 ( ! V_61 ) )
goto V_68;
F_32 ( & V_61 -> V_21 ) ;
V_20 = F_13 ( V_61 , V_26 ) ;
if ( F_40 ( ! V_20 ) )
goto V_69;
V_37 = V_20 -> V_37 ;
if ( F_41 ( ! * V_66 ) ) {
if ( ! F_24 ( & V_37 -> V_41 ) ) {
V_10 = F_42 ( & V_37 -> V_41 ,
struct V_3 ,
V_41 ) ;
F_43 ( & V_10 -> V_41 ,
& V_37 -> V_41 ) ;
} else if ( ! F_24 ( & V_37 -> V_42 ) ) {
V_10 = F_42 ( & V_37 -> V_42 ,
struct V_3 ,
V_42 ) ;
F_43 ( & V_10 -> V_42 ,
& V_37 -> V_42 ) ;
} else {
V_10 = F_42 ( & V_37 -> V_43 ,
struct V_3 ,
V_43 ) ;
F_43 ( & V_10 -> V_43 ,
& V_37 -> V_43 ) ;
}
}
else if ( * V_66 == V_56 -> V_67 ) {
if ( F_24 ( & V_37 -> V_41 ) )
goto V_69;
V_10 = F_42 ( & V_37 -> V_41 , struct V_3 ,
V_41 ) ;
F_43 ( & V_10 -> V_41 , & V_37 -> V_41 ) ;
} else if ( F_44 ( V_31 , * V_66 ) ) {
if ( F_24 ( & V_37 -> V_42 ) )
goto V_69;
V_10 = F_42 ( & V_37 -> V_42 , struct V_3 ,
V_42 ) ;
F_43 ( & V_10 -> V_42 , & V_37 -> V_42 ) ;
} else {
V_10 = F_42 ( & V_37 -> V_43 , struct V_3 ,
V_43 ) ;
F_43 ( & V_10 -> V_43 , & V_37 -> V_43 ) ;
}
V_12 = V_10 -> V_12 ;
V_7 = V_10 -> V_7 ;
V_69:
F_33 ( & V_61 -> V_21 ) ;
V_68:
F_45 () ;
* V_66 = V_7 ;
return V_12 ;
}
int F_46 ( struct V_31 * V_31 , T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_70 , struct V_71 * V_72 )
{
struct V_16 * V_61 ;
struct V_14 * V_20 ;
struct V_14 * V_73 ;
struct V_36 * V_37 ;
int V_74 = 0 ;
F_39 () ;
V_61 = F_27 ( V_31 , type ) ;
if ( ! V_61 )
goto exit;
F_32 ( & V_61 -> V_21 ) ;
V_20 = V_61 -> V_22 + F_14 ( V_61 , V_4 ) ;
V_73 = V_61 -> V_22 + V_61 -> V_29 ;
for (; V_20 != V_73 ; V_20 ++ ) {
struct V_3 * V_10 ;
if ( V_20 -> V_4 > V_5 )
break;
V_37 = V_20 -> V_37 ;
F_16 (publ, &info->node_list, node_list) {
if ( V_10 -> V_6 <= V_70 )
F_47 ( V_72 , V_10 -> V_12 ) ;
}
if ( V_37 -> V_45 != V_37 -> V_46 )
V_74 = 1 ;
}
F_33 ( & V_61 -> V_21 ) ;
exit:
F_45 () ;
return V_74 ;
}
struct V_3 * F_48 ( struct V_31 * V_31 , T_1 type , T_1 V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_8 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_75 * V_76 = NULL ;
struct V_55 * V_56 = F_28 ( V_31 , V_57 ) ;
F_32 ( & V_56 -> V_77 ) ;
if ( V_56 -> V_59 -> V_78 >= V_79 ) {
F_4 ( L_5 ,
V_79 ) ;
F_33 ( & V_56 -> V_77 ) ;
return NULL ;
}
V_10 = F_30 ( V_31 , type , V_4 , V_5 , V_6 ,
V_56 -> V_67 , V_8 , V_9 ) ;
if ( F_41 ( V_10 ) ) {
V_56 -> V_59 -> V_78 ++ ;
V_76 = F_49 ( V_31 , V_10 ) ;
F_50 ( V_31 ) ;
}
F_33 ( & V_56 -> V_77 ) ;
if ( V_76 )
F_51 ( V_31 , V_76 ) ;
return V_10 ;
}
int F_52 ( struct V_31 * V_31 , T_1 type , T_1 V_4 , T_1 V_12 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_75 * V_80 = NULL ;
struct V_55 * V_56 = F_28 ( V_31 , V_57 ) ;
F_32 ( & V_56 -> V_77 ) ;
V_10 = F_34 ( V_31 , type , V_4 , V_56 -> V_67 ,
V_12 , V_9 ) ;
if ( F_41 ( V_10 ) ) {
V_56 -> V_59 -> V_78 -- ;
V_80 = F_53 ( V_31 , V_10 ) ;
F_50 ( V_31 ) ;
F_54 ( & V_10 -> V_13 ) ;
F_36 ( V_10 , V_65 ) ;
} else {
F_55 ( L_6
L_7 ,
type , V_4 , V_12 , V_9 ) ;
}
F_33 ( & V_56 -> V_77 ) ;
if ( V_80 ) {
F_51 ( V_31 , V_80 ) ;
return 1 ;
}
return 0 ;
}
void F_56 ( struct V_33 * V_34 )
{
struct V_55 * V_56 = F_28 ( V_34 -> V_31 , V_57 ) ;
T_1 type = V_34 -> V_61 . type ;
int V_62 = F_1 ( type ) ;
struct V_16 * V_61 ;
F_32 ( & V_56 -> V_77 ) ;
V_61 = F_27 ( V_34 -> V_31 , type ) ;
if ( ! V_61 )
V_61 = F_8 ( type , & V_56 -> V_59 -> V_60 [ V_62 ] ) ;
if ( V_61 ) {
F_32 ( & V_61 -> V_21 ) ;
F_25 ( V_61 , V_34 ) ;
F_33 ( & V_61 -> V_21 ) ;
} else {
F_4 ( L_8 ,
V_34 -> V_61 . type , V_34 -> V_61 . V_4 , V_34 -> V_61 . V_5 ) ;
}
F_33 ( & V_56 -> V_77 ) ;
}
void F_57 ( struct V_33 * V_34 )
{
struct V_55 * V_56 = F_28 ( V_34 -> V_31 , V_57 ) ;
struct V_16 * V_61 ;
F_32 ( & V_56 -> V_77 ) ;
V_61 = F_27 ( V_34 -> V_31 , V_34 -> V_61 . type ) ;
if ( V_61 != NULL ) {
F_32 ( & V_61 -> V_21 ) ;
F_54 ( & V_34 -> V_52 ) ;
if ( ! V_61 -> V_29 && F_24 ( & V_61 -> V_25 ) ) {
F_35 ( & V_61 -> V_24 ) ;
F_9 ( V_61 -> V_22 ) ;
F_33 ( & V_61 -> V_21 ) ;
F_36 ( V_61 , V_65 ) ;
} else {
F_33 ( & V_61 -> V_21 ) ;
}
}
F_33 ( & V_56 -> V_77 ) ;
}
int F_58 ( struct V_31 * V_31 )
{
struct V_55 * V_56 = F_28 ( V_31 , V_57 ) ;
struct V_81 * V_82 ;
int V_83 ;
V_82 = F_3 ( sizeof( * V_82 ) , V_11 ) ;
if ( ! V_82 )
return - V_84 ;
for ( V_83 = 0 ; V_83 < V_2 ; V_83 ++ )
F_59 ( & V_82 -> V_60 [ V_83 ] ) ;
F_5 ( & V_82 -> V_85 [ V_63 ] ) ;
F_5 ( & V_82 -> V_85 [ V_86 ] ) ;
F_5 ( & V_82 -> V_85 [ V_64 ] ) ;
V_56 -> V_59 = V_82 ;
F_10 ( & V_56 -> V_77 ) ;
return 0 ;
}
static void F_60 ( struct V_31 * V_31 , struct V_16 * V_61 )
{
struct V_3 * V_10 , * V_87 ;
struct V_14 * V_20 ;
struct V_36 * V_37 ;
F_32 ( & V_61 -> V_21 ) ;
V_20 = V_61 -> V_22 ;
V_37 = V_20 -> V_37 ;
F_20 (publ, safe, &info->zone_list, zone_list) {
F_34 ( V_31 , V_10 -> type , V_10 -> V_4 ,
V_10 -> V_7 , V_10 -> V_12 , V_10 -> V_9 ) ;
F_36 ( V_10 , V_65 ) ;
}
F_35 ( & V_61 -> V_24 ) ;
F_9 ( V_61 -> V_22 ) ;
F_33 ( & V_61 -> V_21 ) ;
F_36 ( V_61 , V_65 ) ;
}
void F_61 ( struct V_31 * V_31 )
{
T_1 V_83 ;
struct V_16 * V_61 ;
struct V_17 * V_18 ;
struct V_55 * V_56 = F_28 ( V_31 , V_57 ) ;
struct V_81 * V_82 = V_56 -> V_59 ;
F_32 ( & V_56 -> V_77 ) ;
for ( V_83 = 0 ; V_83 < V_2 ; V_83 ++ ) {
if ( F_62 ( & V_82 -> V_60 [ V_83 ] ) )
continue;
V_18 = & V_82 -> V_60 [ V_83 ] ;
F_29 (seq, seq_head, ns_list) {
F_60 ( V_31 , V_61 ) ;
}
}
F_33 ( & V_56 -> V_77 ) ;
F_63 () ;
F_9 ( V_82 ) ;
}
static int F_64 ( struct V_88 * V_89 ,
struct V_16 * V_61 ,
struct V_14 * V_20 , T_1 * V_90 )
{
void * V_91 ;
struct V_92 * V_93 ;
struct V_92 * V_10 ;
struct V_3 * V_94 ;
if ( * V_90 ) {
F_16 (p, &sseq->info->zone_list, zone_list)
if ( V_94 -> V_9 == * V_90 )
break;
if ( V_94 -> V_9 != * V_90 )
return - V_95 ;
} else {
V_94 = F_42 ( & V_20 -> V_37 -> V_43 , struct V_3 ,
V_43 ) ;
}
F_65 (p, &sseq->info->zone_list, zone_list) {
* V_90 = V_94 -> V_9 ;
V_91 = F_66 ( V_89 -> V_80 , V_89 -> V_96 , V_89 -> V_61 ,
& V_97 , V_98 ,
V_99 ) ;
if ( ! V_91 )
return - V_100 ;
V_93 = F_67 ( V_89 -> V_80 , V_101 ) ;
if ( ! V_93 )
goto V_102;
V_10 = F_67 ( V_89 -> V_80 , V_103 ) ;
if ( ! V_10 )
goto V_104;
if ( F_68 ( V_89 -> V_80 , V_105 , V_61 -> type ) )
goto V_106;
if ( F_68 ( V_89 -> V_80 , V_107 , V_20 -> V_4 ) )
goto V_106;
if ( F_68 ( V_89 -> V_80 , V_108 , V_20 -> V_5 ) )
goto V_106;
if ( F_68 ( V_89 -> V_80 , V_109 , V_94 -> V_6 ) )
goto V_106;
if ( F_68 ( V_89 -> V_80 , V_110 , V_94 -> V_7 ) )
goto V_106;
if ( F_68 ( V_89 -> V_80 , V_111 , V_94 -> V_12 ) )
goto V_106;
if ( F_68 ( V_89 -> V_80 , V_112 , V_94 -> V_9 ) )
goto V_106;
F_69 ( V_89 -> V_80 , V_10 ) ;
F_69 ( V_89 -> V_80 , V_93 ) ;
F_70 ( V_89 -> V_80 , V_91 ) ;
}
* V_90 = 0 ;
return 0 ;
V_106:
F_71 ( V_89 -> V_80 , V_10 ) ;
V_104:
F_71 ( V_89 -> V_80 , V_93 ) ;
V_102:
F_72 ( V_89 -> V_80 , V_91 ) ;
return - V_100 ;
}
static int F_73 ( struct V_88 * V_89 , struct V_16 * V_61 ,
T_1 * V_113 , T_1 * V_90 )
{
struct V_14 * V_20 ;
struct V_14 * V_114 ;
int V_115 ;
if ( * V_113 ) {
V_114 = F_13 ( V_61 , * V_113 ) ;
if ( ! V_114 )
return - V_95 ;
} else {
V_114 = V_61 -> V_22 ;
}
for ( V_20 = V_114 ; V_20 != & V_61 -> V_22 [ V_61 -> V_29 ] ; V_20 ++ ) {
V_115 = F_64 ( V_89 , V_61 , V_20 , V_90 ) ;
if ( V_115 ) {
* V_113 = V_20 -> V_4 ;
return V_115 ;
}
}
* V_113 = 0 ;
return 0 ;
}
static int F_74 ( struct V_31 * V_31 , struct V_88 * V_89 ,
T_1 * V_116 , T_1 * V_113 , T_1 * V_90 )
{
struct V_55 * V_56 = F_28 ( V_31 , V_57 ) ;
struct V_17 * V_18 ;
struct V_16 * V_61 = NULL ;
int V_115 ;
int V_83 ;
if ( * V_116 )
V_83 = F_1 ( * V_116 ) ;
else
V_83 = 0 ;
for (; V_83 < V_2 ; V_83 ++ ) {
V_18 = & V_56 -> V_59 -> V_60 [ V_83 ] ;
if ( * V_116 ) {
V_61 = F_27 ( V_31 , * V_116 ) ;
if ( ! V_61 )
return - V_95 ;
} else {
F_29 (seq, seq_head, ns_list)
break;
if ( ! V_61 )
continue;
}
F_75 (seq, ns_list) {
F_32 ( & V_61 -> V_21 ) ;
V_115 = F_73 ( V_89 , V_61 , V_113 ,
V_90 ) ;
if ( V_115 ) {
* V_116 = V_61 -> type ;
F_33 ( & V_61 -> V_21 ) ;
return V_115 ;
}
F_33 ( & V_61 -> V_21 ) ;
}
* V_116 = 0 ;
}
return 0 ;
}
int F_76 ( struct V_75 * V_80 , struct V_117 * V_118 )
{
int V_115 ;
int V_119 = V_118 -> args [ 3 ] ;
T_1 V_116 = V_118 -> args [ 0 ] ;
T_1 V_113 = V_118 -> args [ 1 ] ;
T_1 V_90 = V_118 -> args [ 2 ] ;
struct V_31 * V_31 = F_77 ( V_80 -> V_120 ) ;
struct V_88 V_89 ;
if ( V_119 )
return 0 ;
V_89 . V_80 = V_80 ;
V_89 . V_96 = F_78 ( V_118 -> V_80 ) . V_96 ;
V_89 . V_61 = V_118 -> V_121 -> V_122 ;
F_39 () ;
V_115 = F_74 ( V_31 , & V_89 , & V_116 , & V_113 , & V_90 ) ;
if ( ! V_115 ) {
V_119 = 1 ;
} else if ( V_115 != - V_100 ) {
V_118 -> V_123 = 1 ;
}
F_45 () ;
V_118 -> args [ 0 ] = V_116 ;
V_118 -> args [ 1 ] = V_113 ;
V_118 -> args [ 2 ] = V_90 ;
V_118 -> args [ 3 ] = V_119 ;
return V_80 -> V_124 ;
}
void F_47 ( struct V_71 * V_125 , T_1 V_32 )
{
struct V_71 * V_126 ;
if ( F_41 ( ! V_125 -> V_32 ) ) {
V_125 -> V_32 = V_32 ;
return;
}
if ( V_125 -> V_32 == V_32 )
return;
F_16 (nl, &pl->list, list) {
if ( V_126 -> V_32 == V_32 )
return;
}
V_126 = F_79 ( sizeof( * V_126 ) , V_11 ) ;
if ( V_126 ) {
V_126 -> V_32 = V_32 ;
F_17 ( & V_126 -> V_127 , & V_125 -> V_127 ) ;
}
}
T_1 F_80 ( struct V_71 * V_125 )
{
struct V_71 * V_126 ;
T_1 V_32 = 0 ;
if ( F_41 ( F_24 ( & V_125 -> V_127 ) ) ) {
V_32 = V_125 -> V_32 ;
V_125 -> V_32 = 0 ;
return V_32 ;
}
V_126 = F_42 ( & V_125 -> V_127 , F_81 ( * V_126 ) , V_127 ) ;
V_32 = V_126 -> V_32 ;
F_23 ( & V_126 -> V_127 ) ;
F_9 ( V_126 ) ;
return V_32 ;
}
