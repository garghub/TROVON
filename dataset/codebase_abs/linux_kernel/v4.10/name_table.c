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
F_21 ( V_34 , V_10 -> V_4 , V_10 -> V_5 ,
V_47 , V_10 -> V_12 ,
V_10 -> V_7 , V_38 ) ;
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
F_21 ( V_34 , V_10 -> V_4 , V_10 -> V_5 ,
V_51 , V_10 -> V_12 ,
V_10 -> V_7 , V_49 ) ;
}
return V_10 ;
}
static void F_25 ( struct V_16 * V_19 ,
struct V_33 * V_34 )
{
struct V_14 * V_20 = V_19 -> V_22 ;
struct V_52 V_53 ;
F_26 ( & V_34 -> V_54 . V_34 . V_55 , V_34 -> V_56 , & V_53 ) ;
F_17 ( & V_34 -> V_57 , & V_19 -> V_25 ) ;
if ( ! V_20 )
return;
while ( V_20 != & V_19 -> V_22 [ V_19 -> V_29 ] ) {
if ( F_27 ( & V_53 , V_20 -> V_4 , V_20 -> V_5 ) ) {
struct V_3 * V_58 ;
struct V_36 * V_37 = V_20 -> V_37 ;
int V_59 = 1 ;
F_16 (crs, &info->zone_list, zone_list) {
F_21 ( V_34 , V_20 -> V_4 ,
V_20 -> V_5 ,
V_47 ,
V_58 -> V_12 , V_58 -> V_7 ,
V_59 ) ;
V_59 = 0 ;
}
}
V_20 ++ ;
}
}
static struct V_16 * F_28 ( struct V_31 * V_31 , T_1 type )
{
struct V_60 * V_61 = F_29 ( V_31 , V_62 ) ;
struct V_17 * V_18 ;
struct V_16 * V_53 ;
V_18 = & V_61 -> V_63 -> V_64 [ F_1 ( type ) ] ;
F_30 (ns, seq_head, ns_list) {
if ( V_53 -> type == type )
return V_53 ;
}
return NULL ;
}
struct V_3 * F_31 ( struct V_31 * V_31 , T_1 type ,
T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_32 , T_1 V_9 )
{
struct V_60 * V_61 = F_29 ( V_31 , V_62 ) ;
struct V_3 * V_10 ;
struct V_16 * V_55 = F_28 ( V_31 , type ) ;
int V_65 = F_1 ( type ) ;
if ( ( V_6 < V_66 ) || ( V_6 > V_67 ) ||
( V_4 > V_5 ) ) {
F_32 ( L_4 ,
type , V_4 , V_5 , V_6 ) ;
return NULL ;
}
if ( ! V_55 )
V_55 = F_8 ( type , & V_61 -> V_63 -> V_64 [ V_65 ] ) ;
if ( ! V_55 )
return NULL ;
F_33 ( & V_55 -> V_21 ) ;
V_10 = F_15 ( V_31 , V_55 , type , V_4 , V_5 ,
V_6 , V_7 , V_32 , V_9 ) ;
F_34 ( & V_55 -> V_21 ) ;
return V_10 ;
}
struct V_3 * F_35 ( struct V_31 * V_31 , T_1 type ,
T_1 V_4 , T_1 V_7 , T_1 V_12 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_16 * V_55 = F_28 ( V_31 , type ) ;
if ( ! V_55 )
return NULL ;
F_33 ( & V_55 -> V_21 ) ;
V_10 = F_22 ( V_31 , V_55 , V_4 , V_7 , V_12 , V_9 ) ;
if ( ! V_55 -> V_29 && F_24 ( & V_55 -> V_25 ) ) {
F_36 ( & V_55 -> V_24 ) ;
F_9 ( V_55 -> V_22 ) ;
F_34 ( & V_55 -> V_21 ) ;
F_37 ( V_55 , V_68 ) ;
return V_10 ;
}
F_34 ( & V_55 -> V_21 ) ;
return V_10 ;
}
T_1 F_38 ( struct V_31 * V_31 , T_1 type , T_1 V_26 ,
T_1 * V_69 )
{
struct V_60 * V_61 = F_29 ( V_31 , V_62 ) ;
struct V_14 * V_20 ;
struct V_36 * V_37 ;
struct V_3 * V_10 ;
struct V_16 * V_55 ;
T_1 V_12 = 0 ;
T_1 V_7 = 0 ;
if ( ! F_39 ( * V_69 , V_61 -> V_70 ) )
return 0 ;
F_40 () ;
V_55 = F_28 ( V_31 , type ) ;
if ( F_41 ( ! V_55 ) )
goto V_71;
F_33 ( & V_55 -> V_21 ) ;
V_20 = F_13 ( V_55 , V_26 ) ;
if ( F_41 ( ! V_20 ) )
goto V_72;
V_37 = V_20 -> V_37 ;
if ( F_42 ( ! * V_69 ) ) {
if ( ! F_24 ( & V_37 -> V_41 ) ) {
V_10 = F_43 ( & V_37 -> V_41 ,
struct V_3 ,
V_41 ) ;
F_44 ( & V_10 -> V_41 ,
& V_37 -> V_41 ) ;
} else if ( ! F_24 ( & V_37 -> V_42 ) ) {
V_10 = F_43 ( & V_37 -> V_42 ,
struct V_3 ,
V_42 ) ;
F_44 ( & V_10 -> V_42 ,
& V_37 -> V_42 ) ;
} else {
V_10 = F_43 ( & V_37 -> V_43 ,
struct V_3 ,
V_43 ) ;
F_44 ( & V_10 -> V_43 ,
& V_37 -> V_43 ) ;
}
}
else if ( * V_69 == V_61 -> V_70 ) {
if ( F_24 ( & V_37 -> V_41 ) )
goto V_72;
V_10 = F_43 ( & V_37 -> V_41 , struct V_3 ,
V_41 ) ;
F_44 ( & V_10 -> V_41 , & V_37 -> V_41 ) ;
} else if ( F_45 ( V_31 , * V_69 ) ) {
if ( F_24 ( & V_37 -> V_42 ) )
goto V_72;
V_10 = F_43 ( & V_37 -> V_42 , struct V_3 ,
V_42 ) ;
F_44 ( & V_10 -> V_42 , & V_37 -> V_42 ) ;
} else {
V_10 = F_43 ( & V_37 -> V_43 , struct V_3 ,
V_43 ) ;
F_44 ( & V_10 -> V_43 , & V_37 -> V_43 ) ;
}
V_12 = V_10 -> V_12 ;
V_7 = V_10 -> V_7 ;
V_72:
F_34 ( & V_55 -> V_21 ) ;
V_71:
F_46 () ;
* V_69 = V_7 ;
return V_12 ;
}
int F_47 ( struct V_31 * V_31 , T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_73 , struct V_74 * V_75 )
{
struct V_16 * V_55 ;
struct V_14 * V_20 ;
struct V_14 * V_76 ;
struct V_36 * V_37 ;
int V_77 = 0 ;
F_40 () ;
V_55 = F_28 ( V_31 , type ) ;
if ( ! V_55 )
goto exit;
F_33 ( & V_55 -> V_21 ) ;
V_20 = V_55 -> V_22 + F_14 ( V_55 , V_4 ) ;
V_76 = V_55 -> V_22 + V_55 -> V_29 ;
for (; V_20 != V_76 ; V_20 ++ ) {
struct V_3 * V_10 ;
if ( V_20 -> V_4 > V_5 )
break;
V_37 = V_20 -> V_37 ;
F_16 (publ, &info->node_list, node_list) {
if ( V_10 -> V_6 <= V_73 )
F_48 ( V_75 , V_10 -> V_12 ) ;
}
if ( V_37 -> V_45 != V_37 -> V_46 )
V_77 = 1 ;
}
F_34 ( & V_55 -> V_21 ) ;
exit:
F_46 () ;
return V_77 ;
}
struct V_3 * F_49 ( struct V_31 * V_31 , T_1 type , T_1 V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_8 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_78 * V_79 = NULL ;
struct V_60 * V_61 = F_29 ( V_31 , V_62 ) ;
F_33 ( & V_61 -> V_80 ) ;
if ( V_61 -> V_63 -> V_81 >= V_82 ) {
F_4 ( L_5 ,
V_82 ) ;
F_34 ( & V_61 -> V_80 ) ;
return NULL ;
}
V_10 = F_31 ( V_31 , type , V_4 , V_5 , V_6 ,
V_61 -> V_70 , V_8 , V_9 ) ;
if ( F_42 ( V_10 ) ) {
V_61 -> V_63 -> V_81 ++ ;
V_79 = F_50 ( V_31 , V_10 ) ;
F_51 ( V_31 ) ;
}
F_34 ( & V_61 -> V_80 ) ;
if ( V_79 )
F_52 ( V_31 , V_79 ) ;
return V_10 ;
}
int F_53 ( struct V_31 * V_31 , T_1 type , T_1 V_4 , T_1 V_12 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_78 * V_83 = NULL ;
struct V_60 * V_61 = F_29 ( V_31 , V_62 ) ;
F_33 ( & V_61 -> V_80 ) ;
V_10 = F_35 ( V_31 , type , V_4 , V_61 -> V_70 ,
V_12 , V_9 ) ;
if ( F_42 ( V_10 ) ) {
V_61 -> V_63 -> V_81 -- ;
V_83 = F_54 ( V_31 , V_10 ) ;
F_51 ( V_31 ) ;
F_55 ( & V_10 -> V_13 ) ;
F_37 ( V_10 , V_68 ) ;
} else {
F_56 ( L_6
L_7 ,
type , V_4 , V_12 , V_9 ) ;
}
F_34 ( & V_61 -> V_80 ) ;
if ( V_83 ) {
F_52 ( V_31 , V_83 ) ;
return 1 ;
}
return 0 ;
}
void F_57 ( struct V_33 * V_34 )
{
struct V_60 * V_61 = F_29 ( V_34 -> V_31 , V_62 ) ;
T_1 type = F_58 ( V_34 -> V_54 . V_34 . V_55 . type , V_34 -> V_56 ) ;
int V_65 = F_1 ( type ) ;
struct V_16 * V_55 ;
struct V_52 V_53 ;
F_33 ( & V_61 -> V_80 ) ;
V_55 = F_28 ( V_34 -> V_31 , type ) ;
if ( ! V_55 )
V_55 = F_8 ( type , & V_61 -> V_63 -> V_64 [ V_65 ] ) ;
if ( V_55 ) {
F_33 ( & V_55 -> V_21 ) ;
F_25 ( V_55 , V_34 ) ;
F_34 ( & V_55 -> V_21 ) ;
} else {
F_26 ( & V_34 -> V_54 . V_34 . V_55 , V_34 -> V_56 , & V_53 ) ;
F_4 ( L_8 ,
V_53 . type , V_53 . V_4 , V_53 . V_5 ) ;
}
F_34 ( & V_61 -> V_80 ) ;
}
void F_59 ( struct V_33 * V_34 )
{
struct V_60 * V_61 = F_29 ( V_34 -> V_31 , V_62 ) ;
struct V_16 * V_55 ;
T_1 type = F_58 ( V_34 -> V_54 . V_34 . V_55 . type , V_34 -> V_56 ) ;
F_33 ( & V_61 -> V_80 ) ;
V_55 = F_28 ( V_34 -> V_31 , type ) ;
if ( V_55 != NULL ) {
F_33 ( & V_55 -> V_21 ) ;
F_55 ( & V_34 -> V_57 ) ;
if ( ! V_55 -> V_29 && F_24 ( & V_55 -> V_25 ) ) {
F_36 ( & V_55 -> V_24 ) ;
F_9 ( V_55 -> V_22 ) ;
F_34 ( & V_55 -> V_21 ) ;
F_37 ( V_55 , V_68 ) ;
} else {
F_34 ( & V_55 -> V_21 ) ;
}
}
F_34 ( & V_61 -> V_80 ) ;
}
int F_60 ( struct V_31 * V_31 )
{
struct V_60 * V_61 = F_29 ( V_31 , V_62 ) ;
struct V_84 * V_85 ;
int V_86 ;
V_85 = F_3 ( sizeof( * V_85 ) , V_11 ) ;
if ( ! V_85 )
return - V_87 ;
for ( V_86 = 0 ; V_86 < V_2 ; V_86 ++ )
F_61 ( & V_85 -> V_64 [ V_86 ] ) ;
F_5 ( & V_85 -> V_88 [ V_66 ] ) ;
F_5 ( & V_85 -> V_88 [ V_89 ] ) ;
F_5 ( & V_85 -> V_88 [ V_67 ] ) ;
V_61 -> V_63 = V_85 ;
F_10 ( & V_61 -> V_80 ) ;
return 0 ;
}
static void F_62 ( struct V_31 * V_31 , struct V_16 * V_55 )
{
struct V_3 * V_10 , * V_90 ;
struct V_14 * V_20 ;
struct V_36 * V_37 ;
F_33 ( & V_55 -> V_21 ) ;
V_20 = V_55 -> V_22 ;
V_37 = V_20 -> V_37 ;
F_20 (publ, safe, &info->zone_list, zone_list) {
F_22 ( V_31 , V_55 , V_10 -> V_4 , V_10 -> V_7 ,
V_10 -> V_12 , V_10 -> V_9 ) ;
F_37 ( V_10 , V_68 ) ;
}
F_36 ( & V_55 -> V_24 ) ;
F_9 ( V_55 -> V_22 ) ;
F_34 ( & V_55 -> V_21 ) ;
F_37 ( V_55 , V_68 ) ;
}
void F_63 ( struct V_31 * V_31 )
{
T_1 V_86 ;
struct V_16 * V_55 ;
struct V_17 * V_18 ;
struct V_60 * V_61 = F_29 ( V_31 , V_62 ) ;
struct V_84 * V_85 = V_61 -> V_63 ;
F_33 ( & V_61 -> V_80 ) ;
for ( V_86 = 0 ; V_86 < V_2 ; V_86 ++ ) {
if ( F_64 ( & V_85 -> V_64 [ V_86 ] ) )
continue;
V_18 = & V_85 -> V_64 [ V_86 ] ;
F_30 (seq, seq_head, ns_list) {
F_62 ( V_31 , V_55 ) ;
}
}
F_34 ( & V_61 -> V_80 ) ;
F_65 () ;
F_9 ( V_85 ) ;
}
static int F_66 ( struct V_91 * V_92 ,
struct V_16 * V_55 ,
struct V_14 * V_20 , T_1 * V_93 )
{
void * V_94 ;
struct V_95 * V_96 ;
struct V_95 * V_10 ;
struct V_3 * V_97 ;
if ( * V_93 ) {
F_16 (p, &sseq->info->zone_list, zone_list)
if ( V_97 -> V_9 == * V_93 )
break;
if ( V_97 -> V_9 != * V_93 )
return - V_98 ;
} else {
V_97 = F_43 ( & V_20 -> V_37 -> V_43 , struct V_3 ,
V_43 ) ;
}
F_67 (p, &sseq->info->zone_list, zone_list) {
* V_93 = V_97 -> V_9 ;
V_94 = F_68 ( V_92 -> V_83 , V_92 -> V_99 , V_92 -> V_55 ,
& V_100 , V_101 ,
V_102 ) ;
if ( ! V_94 )
return - V_103 ;
V_96 = F_69 ( V_92 -> V_83 , V_104 ) ;
if ( ! V_96 )
goto V_105;
V_10 = F_69 ( V_92 -> V_83 , V_106 ) ;
if ( ! V_10 )
goto V_107;
if ( F_70 ( V_92 -> V_83 , V_108 , V_55 -> type ) )
goto V_109;
if ( F_70 ( V_92 -> V_83 , V_110 , V_20 -> V_4 ) )
goto V_109;
if ( F_70 ( V_92 -> V_83 , V_111 , V_20 -> V_5 ) )
goto V_109;
if ( F_70 ( V_92 -> V_83 , V_112 , V_97 -> V_6 ) )
goto V_109;
if ( F_70 ( V_92 -> V_83 , V_113 , V_97 -> V_7 ) )
goto V_109;
if ( F_70 ( V_92 -> V_83 , V_114 , V_97 -> V_12 ) )
goto V_109;
if ( F_70 ( V_92 -> V_83 , V_115 , V_97 -> V_9 ) )
goto V_109;
F_71 ( V_92 -> V_83 , V_10 ) ;
F_71 ( V_92 -> V_83 , V_96 ) ;
F_72 ( V_92 -> V_83 , V_94 ) ;
}
* V_93 = 0 ;
return 0 ;
V_109:
F_73 ( V_92 -> V_83 , V_10 ) ;
V_107:
F_73 ( V_92 -> V_83 , V_96 ) ;
V_105:
F_74 ( V_92 -> V_83 , V_94 ) ;
return - V_103 ;
}
static int F_75 ( struct V_91 * V_92 , struct V_16 * V_55 ,
T_1 * V_116 , T_1 * V_93 )
{
struct V_14 * V_20 ;
struct V_14 * V_117 ;
int V_118 ;
if ( * V_116 ) {
V_117 = F_13 ( V_55 , * V_116 ) ;
if ( ! V_117 )
return - V_98 ;
} else {
V_117 = V_55 -> V_22 ;
}
for ( V_20 = V_117 ; V_20 != & V_55 -> V_22 [ V_55 -> V_29 ] ; V_20 ++ ) {
V_118 = F_66 ( V_92 , V_55 , V_20 , V_93 ) ;
if ( V_118 ) {
* V_116 = V_20 -> V_4 ;
return V_118 ;
}
}
* V_116 = 0 ;
return 0 ;
}
static int F_76 ( struct V_31 * V_31 , struct V_91 * V_92 ,
T_1 * V_119 , T_1 * V_116 , T_1 * V_93 )
{
struct V_60 * V_61 = F_29 ( V_31 , V_62 ) ;
struct V_17 * V_18 ;
struct V_16 * V_55 = NULL ;
int V_118 ;
int V_86 ;
if ( * V_119 )
V_86 = F_1 ( * V_119 ) ;
else
V_86 = 0 ;
for (; V_86 < V_2 ; V_86 ++ ) {
V_18 = & V_61 -> V_63 -> V_64 [ V_86 ] ;
if ( * V_119 ) {
V_55 = F_28 ( V_31 , * V_119 ) ;
if ( ! V_55 )
return - V_98 ;
} else {
F_30 (seq, seq_head, ns_list)
break;
if ( ! V_55 )
continue;
}
F_77 (seq, ns_list) {
F_33 ( & V_55 -> V_21 ) ;
V_118 = F_75 ( V_92 , V_55 , V_116 ,
V_93 ) ;
if ( V_118 ) {
* V_119 = V_55 -> type ;
F_34 ( & V_55 -> V_21 ) ;
return V_118 ;
}
F_34 ( & V_55 -> V_21 ) ;
}
* V_119 = 0 ;
}
return 0 ;
}
int F_78 ( struct V_78 * V_83 , struct V_120 * V_121 )
{
int V_118 ;
int V_122 = V_121 -> args [ 3 ] ;
T_1 V_119 = V_121 -> args [ 0 ] ;
T_1 V_116 = V_121 -> args [ 1 ] ;
T_1 V_93 = V_121 -> args [ 2 ] ;
struct V_31 * V_31 = F_79 ( V_83 -> V_123 ) ;
struct V_91 V_92 ;
if ( V_122 )
return 0 ;
V_92 . V_83 = V_83 ;
V_92 . V_99 = F_80 ( V_121 -> V_83 ) . V_99 ;
V_92 . V_55 = V_121 -> V_124 -> V_125 ;
F_40 () ;
V_118 = F_76 ( V_31 , & V_92 , & V_119 , & V_116 , & V_93 ) ;
if ( ! V_118 ) {
V_122 = 1 ;
} else if ( V_118 != - V_103 ) {
V_121 -> V_126 = 1 ;
}
F_46 () ;
V_121 -> args [ 0 ] = V_119 ;
V_121 -> args [ 1 ] = V_116 ;
V_121 -> args [ 2 ] = V_93 ;
V_121 -> args [ 3 ] = V_122 ;
return V_83 -> V_127 ;
}
void F_48 ( struct V_74 * V_128 , T_1 V_32 )
{
struct V_74 * V_129 ;
if ( F_42 ( ! V_128 -> V_32 ) ) {
V_128 -> V_32 = V_32 ;
return;
}
if ( V_128 -> V_32 == V_32 )
return;
F_16 (nl, &pl->list, list) {
if ( V_129 -> V_32 == V_32 )
return;
}
V_129 = F_81 ( sizeof( * V_129 ) , V_11 ) ;
if ( V_129 ) {
V_129 -> V_32 = V_32 ;
F_17 ( & V_129 -> V_130 , & V_128 -> V_130 ) ;
}
}
T_1 F_82 ( struct V_74 * V_128 )
{
struct V_74 * V_129 ;
T_1 V_32 = 0 ;
if ( F_42 ( F_24 ( & V_128 -> V_130 ) ) ) {
V_32 = V_128 -> V_32 ;
V_128 -> V_32 = 0 ;
return V_32 ;
}
V_129 = F_43 ( & V_128 -> V_130 , F_83 ( * V_129 ) , V_130 ) ;
V_32 = V_129 -> V_32 ;
F_23 ( & V_129 -> V_130 ) ;
F_9 ( V_129 ) ;
return V_32 ;
}
