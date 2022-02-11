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
F_27 ( V_34 ) ;
F_17 ( & V_34 -> V_57 , & V_19 -> V_25 ) ;
if ( ! V_20 )
return;
while ( V_20 != & V_19 -> V_22 [ V_19 -> V_29 ] ) {
if ( F_28 ( & V_53 , V_20 -> V_4 , V_20 -> V_5 ) ) {
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
static struct V_16 * F_29 ( struct V_31 * V_31 , T_1 type )
{
struct V_60 * V_61 = F_30 ( V_31 , V_62 ) ;
struct V_17 * V_18 ;
struct V_16 * V_53 ;
V_18 = & V_61 -> V_63 -> V_64 [ F_1 ( type ) ] ;
F_31 (ns, seq_head, ns_list) {
if ( V_53 -> type == type )
return V_53 ;
}
return NULL ;
}
struct V_3 * F_32 ( struct V_31 * V_31 , T_1 type ,
T_1 V_4 , T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_32 , T_1 V_9 )
{
struct V_60 * V_61 = F_30 ( V_31 , V_62 ) ;
struct V_3 * V_10 ;
struct V_16 * V_55 = F_29 ( V_31 , type ) ;
int V_65 = F_1 ( type ) ;
if ( ( V_6 < V_66 ) || ( V_6 > V_67 ) ||
( V_4 > V_5 ) ) {
F_33 ( L_4 ,
type , V_4 , V_5 , V_6 ) ;
return NULL ;
}
if ( ! V_55 )
V_55 = F_8 ( type , & V_61 -> V_63 -> V_64 [ V_65 ] ) ;
if ( ! V_55 )
return NULL ;
F_34 ( & V_55 -> V_21 ) ;
V_10 = F_15 ( V_31 , V_55 , type , V_4 , V_5 ,
V_6 , V_7 , V_32 , V_9 ) ;
F_35 ( & V_55 -> V_21 ) ;
return V_10 ;
}
struct V_3 * F_36 ( struct V_31 * V_31 , T_1 type ,
T_1 V_4 , T_1 V_7 , T_1 V_12 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_16 * V_55 = F_29 ( V_31 , type ) ;
if ( ! V_55 )
return NULL ;
F_34 ( & V_55 -> V_21 ) ;
V_10 = F_22 ( V_31 , V_55 , V_4 , V_7 , V_12 , V_9 ) ;
if ( ! V_55 -> V_29 && F_24 ( & V_55 -> V_25 ) ) {
F_37 ( & V_55 -> V_24 ) ;
F_9 ( V_55 -> V_22 ) ;
F_35 ( & V_55 -> V_21 ) ;
F_38 ( V_55 , V_68 ) ;
return V_10 ;
}
F_35 ( & V_55 -> V_21 ) ;
return V_10 ;
}
T_1 F_39 ( struct V_31 * V_31 , T_1 type , T_1 V_26 ,
T_1 * V_69 )
{
struct V_60 * V_61 = F_30 ( V_31 , V_62 ) ;
struct V_14 * V_20 ;
struct V_36 * V_37 ;
struct V_3 * V_10 ;
struct V_16 * V_55 ;
T_1 V_12 = 0 ;
T_1 V_7 = 0 ;
if ( ! F_40 ( * V_69 , V_61 -> V_70 ) )
return 0 ;
F_41 () ;
V_55 = F_29 ( V_31 , type ) ;
if ( F_42 ( ! V_55 ) )
goto V_71;
F_34 ( & V_55 -> V_21 ) ;
V_20 = F_13 ( V_55 , V_26 ) ;
if ( F_42 ( ! V_20 ) )
goto V_72;
V_37 = V_20 -> V_37 ;
if ( F_43 ( ! * V_69 ) ) {
if ( ! F_24 ( & V_37 -> V_41 ) ) {
V_10 = F_44 ( & V_37 -> V_41 ,
struct V_3 ,
V_41 ) ;
F_45 ( & V_10 -> V_41 ,
& V_37 -> V_41 ) ;
} else if ( ! F_24 ( & V_37 -> V_42 ) ) {
V_10 = F_44 ( & V_37 -> V_42 ,
struct V_3 ,
V_42 ) ;
F_45 ( & V_10 -> V_42 ,
& V_37 -> V_42 ) ;
} else {
V_10 = F_44 ( & V_37 -> V_43 ,
struct V_3 ,
V_43 ) ;
F_45 ( & V_10 -> V_43 ,
& V_37 -> V_43 ) ;
}
}
else if ( * V_69 == V_61 -> V_70 ) {
if ( F_24 ( & V_37 -> V_41 ) )
goto V_72;
V_10 = F_44 ( & V_37 -> V_41 , struct V_3 ,
V_41 ) ;
F_45 ( & V_10 -> V_41 , & V_37 -> V_41 ) ;
} else if ( F_46 ( V_31 , * V_69 ) ) {
if ( F_24 ( & V_37 -> V_42 ) )
goto V_72;
V_10 = F_44 ( & V_37 -> V_42 , struct V_3 ,
V_42 ) ;
F_45 ( & V_10 -> V_42 , & V_37 -> V_42 ) ;
} else {
V_10 = F_44 ( & V_37 -> V_43 , struct V_3 ,
V_43 ) ;
F_45 ( & V_10 -> V_43 , & V_37 -> V_43 ) ;
}
V_12 = V_10 -> V_12 ;
V_7 = V_10 -> V_7 ;
V_72:
F_35 ( & V_55 -> V_21 ) ;
V_71:
F_47 () ;
* V_69 = V_7 ;
return V_12 ;
}
int F_48 ( struct V_31 * V_31 , T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_73 , struct V_74 * V_75 )
{
struct V_16 * V_55 ;
struct V_14 * V_20 ;
struct V_14 * V_76 ;
struct V_36 * V_37 ;
int V_77 = 0 ;
F_41 () ;
V_55 = F_29 ( V_31 , type ) ;
if ( ! V_55 )
goto exit;
F_34 ( & V_55 -> V_21 ) ;
V_20 = V_55 -> V_22 + F_14 ( V_55 , V_4 ) ;
V_76 = V_55 -> V_22 + V_55 -> V_29 ;
for (; V_20 != V_76 ; V_20 ++ ) {
struct V_3 * V_10 ;
if ( V_20 -> V_4 > V_5 )
break;
V_37 = V_20 -> V_37 ;
F_16 (publ, &info->node_list, node_list) {
if ( V_10 -> V_6 <= V_73 )
F_49 ( V_75 , V_10 -> V_12 ) ;
}
if ( V_37 -> V_45 != V_37 -> V_46 )
V_77 = 1 ;
}
F_35 ( & V_55 -> V_21 ) ;
exit:
F_47 () ;
return V_77 ;
}
void F_50 ( struct V_31 * V_31 , T_1 type , T_1 V_4 ,
T_1 V_5 , T_1 V_78 ,
struct V_79 * V_80 )
{
struct V_14 * V_20 , * V_81 ;
struct V_3 * V_10 ;
struct V_36 * V_37 ;
struct V_16 * V_55 ;
F_41 () ;
V_55 = F_29 ( V_31 , type ) ;
if ( ! V_55 )
goto exit;
F_34 ( & V_55 -> V_21 ) ;
V_20 = V_55 -> V_22 + F_14 ( V_55 , V_4 ) ;
V_81 = V_55 -> V_22 + V_55 -> V_29 ;
for (; V_20 -> V_4 <= V_5 && V_20 != V_81 ; V_20 ++ ) {
V_37 = V_20 -> V_37 ;
F_16 (publ, &info->zone_list, zone_list) {
if ( F_40 ( V_78 , V_10 -> V_7 ) )
F_51 ( V_80 , V_10 -> V_7 ) ;
}
}
F_35 ( & V_55 -> V_21 ) ;
exit:
F_47 () ;
}
struct V_3 * F_52 ( struct V_31 * V_31 , T_1 type , T_1 V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_8 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_82 * V_83 = NULL ;
struct V_60 * V_61 = F_30 ( V_31 , V_62 ) ;
F_34 ( & V_61 -> V_84 ) ;
if ( V_61 -> V_63 -> V_85 >= V_86 ) {
F_4 ( L_5 ,
V_86 ) ;
F_35 ( & V_61 -> V_84 ) ;
return NULL ;
}
V_10 = F_32 ( V_31 , type , V_4 , V_5 , V_6 ,
V_61 -> V_70 , V_8 , V_9 ) ;
if ( F_43 ( V_10 ) ) {
V_61 -> V_63 -> V_85 ++ ;
V_83 = F_53 ( V_31 , V_10 ) ;
F_54 ( V_31 ) ;
}
F_35 ( & V_61 -> V_84 ) ;
if ( V_83 )
F_55 ( V_31 , V_83 ) ;
return V_10 ;
}
int F_56 ( struct V_31 * V_31 , T_1 type , T_1 V_4 , T_1 V_12 ,
T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_82 * V_87 = NULL ;
struct V_60 * V_61 = F_30 ( V_31 , V_62 ) ;
F_34 ( & V_61 -> V_84 ) ;
V_10 = F_36 ( V_31 , type , V_4 , V_61 -> V_70 ,
V_12 , V_9 ) ;
if ( F_43 ( V_10 ) ) {
V_61 -> V_63 -> V_85 -- ;
V_87 = F_57 ( V_31 , V_10 ) ;
F_54 ( V_31 ) ;
F_58 ( & V_10 -> V_13 ) ;
F_38 ( V_10 , V_68 ) ;
} else {
F_59 ( L_6
L_7 ,
type , V_4 , V_12 , V_9 ) ;
}
F_35 ( & V_61 -> V_84 ) ;
if ( V_87 ) {
F_55 ( V_31 , V_87 ) ;
return 1 ;
}
return 0 ;
}
void F_60 ( struct V_33 * V_34 )
{
struct V_60 * V_61 = F_30 ( V_34 -> V_31 , V_62 ) ;
T_1 type = F_61 ( V_34 -> V_54 . V_34 . V_55 . type , V_34 -> V_56 ) ;
int V_65 = F_1 ( type ) ;
struct V_16 * V_55 ;
struct V_52 V_53 ;
F_34 ( & V_61 -> V_84 ) ;
V_55 = F_29 ( V_34 -> V_31 , type ) ;
if ( ! V_55 )
V_55 = F_8 ( type , & V_61 -> V_63 -> V_64 [ V_65 ] ) ;
if ( V_55 ) {
F_34 ( & V_55 -> V_21 ) ;
F_25 ( V_55 , V_34 ) ;
F_35 ( & V_55 -> V_21 ) ;
} else {
F_26 ( & V_34 -> V_54 . V_34 . V_55 , V_34 -> V_56 , & V_53 ) ;
F_4 ( L_8 ,
V_53 . type , V_53 . V_4 , V_53 . V_5 ) ;
}
F_35 ( & V_61 -> V_84 ) ;
}
void F_62 ( struct V_33 * V_34 )
{
struct V_60 * V_61 = F_30 ( V_34 -> V_31 , V_62 ) ;
struct V_16 * V_55 ;
T_1 type = F_61 ( V_34 -> V_54 . V_34 . V_55 . type , V_34 -> V_56 ) ;
F_34 ( & V_61 -> V_84 ) ;
V_55 = F_29 ( V_34 -> V_31 , type ) ;
if ( V_55 != NULL ) {
F_34 ( & V_55 -> V_21 ) ;
F_58 ( & V_34 -> V_57 ) ;
F_63 ( V_34 ) ;
if ( ! V_55 -> V_29 && F_24 ( & V_55 -> V_25 ) ) {
F_37 ( & V_55 -> V_24 ) ;
F_9 ( V_55 -> V_22 ) ;
F_35 ( & V_55 -> V_21 ) ;
F_38 ( V_55 , V_68 ) ;
} else {
F_35 ( & V_55 -> V_21 ) ;
}
}
F_35 ( & V_61 -> V_84 ) ;
}
int F_64 ( struct V_31 * V_31 )
{
struct V_60 * V_61 = F_30 ( V_31 , V_62 ) ;
struct V_88 * V_89 ;
int V_90 ;
V_89 = F_3 ( sizeof( * V_89 ) , V_11 ) ;
if ( ! V_89 )
return - V_91 ;
for ( V_90 = 0 ; V_90 < V_2 ; V_90 ++ )
F_65 ( & V_89 -> V_64 [ V_90 ] ) ;
F_5 ( & V_89 -> V_92 [ V_66 ] ) ;
F_5 ( & V_89 -> V_92 [ V_93 ] ) ;
F_5 ( & V_89 -> V_92 [ V_67 ] ) ;
V_61 -> V_63 = V_89 ;
F_10 ( & V_61 -> V_84 ) ;
return 0 ;
}
static void F_66 ( struct V_31 * V_31 , struct V_16 * V_55 )
{
struct V_3 * V_10 , * V_94 ;
struct V_14 * V_20 ;
struct V_36 * V_37 ;
F_34 ( & V_55 -> V_21 ) ;
V_20 = V_55 -> V_22 ;
V_37 = V_20 -> V_37 ;
F_20 (publ, safe, &info->zone_list, zone_list) {
F_22 ( V_31 , V_55 , V_10 -> V_4 , V_10 -> V_7 ,
V_10 -> V_12 , V_10 -> V_9 ) ;
F_38 ( V_10 , V_68 ) ;
}
F_37 ( & V_55 -> V_24 ) ;
F_9 ( V_55 -> V_22 ) ;
F_35 ( & V_55 -> V_21 ) ;
F_38 ( V_55 , V_68 ) ;
}
void F_67 ( struct V_31 * V_31 )
{
T_1 V_90 ;
struct V_16 * V_55 ;
struct V_17 * V_18 ;
struct V_60 * V_61 = F_30 ( V_31 , V_62 ) ;
struct V_88 * V_89 = V_61 -> V_63 ;
F_34 ( & V_61 -> V_84 ) ;
for ( V_90 = 0 ; V_90 < V_2 ; V_90 ++ ) {
if ( F_68 ( & V_89 -> V_64 [ V_90 ] ) )
continue;
V_18 = & V_89 -> V_64 [ V_90 ] ;
F_31 (seq, seq_head, ns_list) {
F_66 ( V_31 , V_55 ) ;
}
}
F_35 ( & V_61 -> V_84 ) ;
F_69 () ;
F_9 ( V_89 ) ;
}
static int F_70 ( struct V_95 * V_96 ,
struct V_16 * V_55 ,
struct V_14 * V_20 , T_1 * V_97 )
{
void * V_98 ;
struct V_99 * V_100 ;
struct V_99 * V_10 ;
struct V_3 * V_101 ;
if ( * V_97 ) {
F_16 (p, &sseq->info->zone_list, zone_list)
if ( V_101 -> V_9 == * V_97 )
break;
if ( V_101 -> V_9 != * V_97 )
return - V_102 ;
} else {
V_101 = F_44 ( & V_20 -> V_37 -> V_43 , struct V_3 ,
V_43 ) ;
}
F_71 (p, &sseq->info->zone_list, zone_list) {
* V_97 = V_101 -> V_9 ;
V_98 = F_72 ( V_96 -> V_87 , V_96 -> V_103 , V_96 -> V_55 ,
& V_104 , V_105 ,
V_106 ) ;
if ( ! V_98 )
return - V_107 ;
V_100 = F_73 ( V_96 -> V_87 , V_108 ) ;
if ( ! V_100 )
goto V_109;
V_10 = F_73 ( V_96 -> V_87 , V_110 ) ;
if ( ! V_10 )
goto V_111;
if ( F_74 ( V_96 -> V_87 , V_112 , V_55 -> type ) )
goto V_113;
if ( F_74 ( V_96 -> V_87 , V_114 , V_20 -> V_4 ) )
goto V_113;
if ( F_74 ( V_96 -> V_87 , V_115 , V_20 -> V_5 ) )
goto V_113;
if ( F_74 ( V_96 -> V_87 , V_116 , V_101 -> V_6 ) )
goto V_113;
if ( F_74 ( V_96 -> V_87 , V_117 , V_101 -> V_7 ) )
goto V_113;
if ( F_74 ( V_96 -> V_87 , V_118 , V_101 -> V_12 ) )
goto V_113;
if ( F_74 ( V_96 -> V_87 , V_119 , V_101 -> V_9 ) )
goto V_113;
F_75 ( V_96 -> V_87 , V_10 ) ;
F_75 ( V_96 -> V_87 , V_100 ) ;
F_76 ( V_96 -> V_87 , V_98 ) ;
}
* V_97 = 0 ;
return 0 ;
V_113:
F_77 ( V_96 -> V_87 , V_10 ) ;
V_111:
F_77 ( V_96 -> V_87 , V_100 ) ;
V_109:
F_78 ( V_96 -> V_87 , V_98 ) ;
return - V_107 ;
}
static int F_79 ( struct V_95 * V_96 , struct V_16 * V_55 ,
T_1 * V_120 , T_1 * V_97 )
{
struct V_14 * V_20 ;
struct V_14 * V_121 ;
int V_122 ;
if ( * V_120 ) {
V_121 = F_13 ( V_55 , * V_120 ) ;
if ( ! V_121 )
return - V_102 ;
} else {
V_121 = V_55 -> V_22 ;
}
for ( V_20 = V_121 ; V_20 != & V_55 -> V_22 [ V_55 -> V_29 ] ; V_20 ++ ) {
V_122 = F_70 ( V_96 , V_55 , V_20 , V_97 ) ;
if ( V_122 ) {
* V_120 = V_20 -> V_4 ;
return V_122 ;
}
}
* V_120 = 0 ;
return 0 ;
}
static int F_80 ( struct V_31 * V_31 , struct V_95 * V_96 ,
T_1 * V_123 , T_1 * V_120 , T_1 * V_97 )
{
struct V_60 * V_61 = F_30 ( V_31 , V_62 ) ;
struct V_17 * V_18 ;
struct V_16 * V_55 = NULL ;
int V_122 ;
int V_90 ;
if ( * V_123 )
V_90 = F_1 ( * V_123 ) ;
else
V_90 = 0 ;
for (; V_90 < V_2 ; V_90 ++ ) {
V_18 = & V_61 -> V_63 -> V_64 [ V_90 ] ;
if ( * V_123 ) {
V_55 = F_29 ( V_31 , * V_123 ) ;
if ( ! V_55 )
return - V_102 ;
} else {
F_31 (seq, seq_head, ns_list)
break;
if ( ! V_55 )
continue;
}
F_81 (seq, ns_list) {
F_34 ( & V_55 -> V_21 ) ;
V_122 = F_79 ( V_96 , V_55 , V_120 ,
V_97 ) ;
if ( V_122 ) {
* V_123 = V_55 -> type ;
F_35 ( & V_55 -> V_21 ) ;
return V_122 ;
}
F_35 ( & V_55 -> V_21 ) ;
}
* V_123 = 0 ;
}
return 0 ;
}
int F_82 ( struct V_82 * V_87 , struct V_124 * V_125 )
{
int V_122 ;
int V_126 = V_125 -> args [ 3 ] ;
T_1 V_123 = V_125 -> args [ 0 ] ;
T_1 V_120 = V_125 -> args [ 1 ] ;
T_1 V_97 = V_125 -> args [ 2 ] ;
struct V_31 * V_31 = F_83 ( V_87 -> V_127 ) ;
struct V_95 V_96 ;
if ( V_126 )
return 0 ;
V_96 . V_87 = V_87 ;
V_96 . V_103 = F_84 ( V_125 -> V_87 ) . V_103 ;
V_96 . V_55 = V_125 -> V_128 -> V_129 ;
F_41 () ;
V_122 = F_80 ( V_31 , & V_96 , & V_123 , & V_120 , & V_97 ) ;
if ( ! V_122 ) {
V_126 = 1 ;
} else if ( V_122 != - V_107 ) {
V_125 -> V_130 = 1 ;
}
F_47 () ;
V_125 -> args [ 0 ] = V_123 ;
V_125 -> args [ 1 ] = V_120 ;
V_125 -> args [ 2 ] = V_97 ;
V_125 -> args [ 3 ] = V_126 ;
return V_87 -> V_131 ;
}
bool F_85 ( struct V_74 * V_132 , T_1 V_133 )
{
struct V_134 * V_135 ;
F_16 (item, l, list) {
if ( V_135 -> V_133 == V_133 )
return true ;
}
return false ;
}
bool F_49 ( struct V_74 * V_132 , T_1 V_133 )
{
struct V_134 * V_135 ;
F_16 (item, l, list) {
if ( V_135 -> V_133 == V_133 )
return false ;
}
V_135 = F_86 ( sizeof( * V_135 ) , V_11 ) ;
if ( F_42 ( ! V_135 ) )
return false ;
V_135 -> V_133 = V_133 ;
F_17 ( & V_135 -> V_136 , V_132 ) ;
return true ;
}
T_1 F_87 ( struct V_74 * V_132 )
{
struct V_134 * V_135 ;
T_1 V_133 = 0 ;
if ( F_24 ( V_132 ) )
return 0 ;
V_135 = F_44 ( V_132 , F_88 ( * V_135 ) , V_136 ) ;
V_133 = V_135 -> V_133 ;
F_23 ( & V_135 -> V_136 ) ;
F_9 ( V_135 ) ;
return V_133 ;
}
bool F_89 ( struct V_74 * V_132 , T_1 V_133 )
{
struct V_134 * V_135 , * V_137 ;
F_20 (item, tmp, l, list) {
if ( V_135 -> V_133 != V_133 )
continue;
F_23 ( & V_135 -> V_136 ) ;
F_9 ( V_135 ) ;
return true ;
}
return false ;
}
void F_90 ( struct V_74 * V_132 )
{
struct V_134 * V_135 , * V_137 ;
F_20 (item, tmp, l, list) {
F_23 ( & V_135 -> V_136 ) ;
F_9 ( V_135 ) ;
}
}
int F_91 ( struct V_74 * V_132 )
{
struct V_134 * V_135 ;
int V_90 = 0 ;
F_16 (item, l, list) {
V_90 ++ ;
}
return V_90 ;
}
