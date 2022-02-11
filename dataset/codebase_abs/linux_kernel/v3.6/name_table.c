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
static void F_13 ( struct V_20 * V_29 )
{
if ( ! V_29 -> V_30 && F_14 ( & V_29 -> V_28 ) ) {
F_15 ( & V_29 -> V_27 ) ;
F_9 ( V_29 -> V_25 ) ;
F_9 ( V_29 ) ;
}
}
static struct V_17 * F_16 ( struct V_20 * V_23 ,
T_1 V_31 )
{
struct V_17 * V_25 = V_23 -> V_25 ;
int V_32 = 0 ;
int V_33 = V_23 -> V_30 - 1 ;
int V_34 ;
while ( V_32 <= V_33 ) {
V_34 = ( V_32 + V_33 ) / 2 ;
if ( V_31 < V_25 [ V_34 ] . V_4 )
V_33 = V_34 - 1 ;
else if ( V_31 > V_25 [ V_34 ] . V_5 )
V_32 = V_34 + 1 ;
else
return & V_25 [ V_34 ] ;
}
return NULL ;
}
static T_1 F_17 ( struct V_20 * V_23 , T_1 V_31 )
{
struct V_17 * V_25 = V_23 -> V_25 ;
int V_32 = 0 ;
int V_33 = V_23 -> V_30 - 1 ;
int V_34 ;
while ( V_32 <= V_33 ) {
V_34 = ( V_32 + V_33 ) / 2 ;
if ( V_31 < V_25 [ V_34 ] . V_4 )
V_33 = V_34 - 1 ;
else if ( V_31 > V_25 [ V_34 ] . V_5 )
V_32 = V_34 + 1 ;
else
return V_34 ;
}
return V_32 ;
}
static struct V_3 * F_18 ( struct V_20 * V_23 ,
T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_35 , T_1 V_9 )
{
struct V_36 * V_37 ;
struct V_36 * V_38 ;
struct V_3 * V_10 ;
struct V_17 * V_19 ;
struct V_39 * V_40 ;
int V_41 = 0 ;
V_19 = F_16 ( V_23 , V_4 ) ;
if ( V_19 ) {
if ( ( V_19 -> V_4 != V_4 ) || ( V_19 -> V_5 != V_5 ) ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
V_40 = V_19 -> V_40 ;
F_19 (publ, &info->zone_list, zone_list) {
if ( ( V_10 -> V_12 == V_35 ) && ( V_10 -> V_9 == V_9 ) &&
( ! V_10 -> V_7 || ( V_10 -> V_7 == V_7 ) ) )
return NULL ;
}
} else {
T_1 V_42 ;
struct V_17 * V_43 ;
V_42 = F_17 ( V_23 , V_4 ) ;
if ( ( V_42 < V_23 -> V_30 ) &&
( V_5 >= V_23 -> V_25 [ V_42 ] . V_4 ) ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
if ( V_23 -> V_30 == V_23 -> V_26 ) {
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
V_40 = F_3 ( sizeof( * V_40 ) , V_11 ) ;
if ( ! V_40 ) {
F_4 ( L_4 ,
type , V_4 , V_5 ) ;
return NULL ;
}
F_5 ( & V_40 -> V_44 ) ;
F_5 ( & V_40 -> V_45 ) ;
F_5 ( & V_40 -> V_46 ) ;
V_19 = & V_23 -> V_25 [ V_42 ] ;
V_43 = & V_23 -> V_25 [ V_23 -> V_30 ] ;
memmove ( V_19 + 1 , V_19 , ( V_43 - V_19 ) * sizeof( * V_19 ) ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_23 -> V_30 ++ ;
V_19 -> V_4 = V_4 ;
V_19 -> V_5 = V_5 ;
V_19 -> V_40 = V_40 ;
V_41 = 1 ;
}
V_10 = F_2 ( type , V_4 , V_5 , V_6 , V_7 , V_35 , V_9 ) ;
if ( ! V_10 )
return NULL ;
F_20 ( & V_10 -> V_46 , & V_40 -> V_46 ) ;
V_40 -> V_47 ++ ;
if ( F_21 ( V_7 ) ) {
F_20 ( & V_10 -> V_45 , & V_40 -> V_45 ) ;
V_40 -> V_48 ++ ;
}
if ( F_22 ( V_7 ) ) {
F_20 ( & V_10 -> V_44 , & V_40 -> V_44 ) ;
V_40 -> V_49 ++ ;
}
F_23 (s, st, &nseq->subscriptions, nameseq_list) {
F_24 ( V_37 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_50 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_41 ) ;
}
return V_10 ;
}
static struct V_3 * F_25 ( struct V_20 * V_23 , T_1 V_51 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_17 * V_19 = F_16 ( V_23 , V_51 ) ;
struct V_39 * V_40 ;
struct V_17 * free ;
struct V_36 * V_37 , * V_38 ;
int V_52 = 0 ;
if ( ! V_19 )
return NULL ;
V_40 = V_19 -> V_40 ;
F_19 (publ, &info->zone_list, zone_list) {
if ( ( V_10 -> V_9 == V_9 ) && ( V_10 -> V_12 == V_12 ) &&
( ! V_10 -> V_7 || ( V_10 -> V_7 == V_7 ) ) )
goto V_53;
}
return NULL ;
V_53:
F_26 ( & V_10 -> V_46 ) ;
V_40 -> V_47 -- ;
if ( F_21 ( V_7 ) ) {
F_26 ( & V_10 -> V_45 ) ;
V_40 -> V_48 -- ;
}
if ( F_22 ( V_7 ) ) {
F_26 ( & V_10 -> V_44 ) ;
V_40 -> V_49 -- ;
}
if ( F_14 ( & V_40 -> V_46 ) ) {
F_9 ( V_40 ) ;
free = & V_23 -> V_25 [ V_23 -> V_30 -- ] ;
memmove ( V_19 , V_19 + 1 , ( free - ( V_19 + 1 ) ) * sizeof( * V_19 ) ) ;
V_52 = 1 ;
}
F_23 (s, st, &nseq->subscriptions, nameseq_list) {
F_24 ( V_37 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_54 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_52 ) ;
}
return V_10 ;
}
static void F_27 ( struct V_20 * V_23 ,
struct V_36 * V_37 )
{
struct V_17 * V_19 = V_23 -> V_25 ;
F_20 ( & V_37 -> V_55 , & V_23 -> V_28 ) ;
if ( ! V_19 )
return;
while ( V_19 != & V_23 -> V_25 [ V_23 -> V_30 ] ) {
if ( F_28 ( V_37 , V_19 -> V_4 , V_19 -> V_5 ) ) {
struct V_3 * V_56 ;
struct V_39 * V_40 = V_19 -> V_40 ;
int V_57 = 1 ;
F_19 (crs, &info->zone_list, zone_list) {
F_24 ( V_37 ,
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
static struct V_20 * F_29 ( T_1 type )
{
struct V_21 * V_22 ;
struct V_58 * V_59 ;
struct V_20 * V_60 ;
V_22 = & V_61 . V_62 [ F_1 ( type ) ] ;
F_30 (ns, seq_node, seq_head, ns_list) {
if ( V_60 -> type == type )
return V_60 ;
}
return NULL ;
}
struct V_3 * F_31 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_35 , T_1 V_9 )
{
struct V_20 * V_29 = F_29 ( type ) ;
if ( ( V_6 < V_63 ) || ( V_6 > V_64 ) ||
( V_4 > V_5 ) ) {
F_32 ( L_5 ,
type , V_4 , V_5 , V_6 ) ;
return NULL ;
}
if ( ! V_29 )
V_29 = F_8 ( type , & V_61 . V_62 [ F_1 ( type ) ] ) ;
if ( ! V_29 )
return NULL ;
return F_18 ( V_29 , type , V_4 , V_5 ,
V_6 , V_7 , V_35 , V_9 ) ;
}
struct V_3 * F_33 ( T_1 type , T_1 V_4 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_20 * V_29 = F_29 ( type ) ;
if ( ! V_29 )
return NULL ;
V_10 = F_25 ( V_29 , V_4 , V_7 , V_12 , V_9 ) ;
F_13 ( V_29 ) ;
return V_10 ;
}
T_1 F_34 ( T_1 type , T_1 V_31 , T_1 * V_65 )
{
struct V_17 * V_19 ;
struct V_39 * V_40 ;
struct V_3 * V_10 ;
struct V_20 * V_29 ;
T_1 V_12 = 0 ;
T_1 V_7 = 0 ;
if ( ! F_35 ( * V_65 , V_66 ) )
return 0 ;
F_36 ( & V_67 ) ;
V_29 = F_29 ( type ) ;
if ( F_37 ( ! V_29 ) )
goto V_68;
V_19 = F_16 ( V_29 , V_31 ) ;
if ( F_37 ( ! V_19 ) )
goto V_68;
F_38 ( & V_29 -> V_24 ) ;
V_40 = V_19 -> V_40 ;
if ( F_39 ( ! * V_65 ) ) {
if ( ! F_14 ( & V_40 -> V_44 ) ) {
V_10 = F_40 ( & V_40 -> V_44 ,
struct V_3 ,
V_44 ) ;
F_41 ( & V_10 -> V_44 ,
& V_40 -> V_44 ) ;
} else if ( ! F_14 ( & V_40 -> V_45 ) ) {
V_10 = F_40 ( & V_40 -> V_45 ,
struct V_3 ,
V_45 ) ;
F_41 ( & V_10 -> V_45 ,
& V_40 -> V_45 ) ;
} else {
V_10 = F_40 ( & V_40 -> V_46 ,
struct V_3 ,
V_46 ) ;
F_41 ( & V_10 -> V_46 ,
& V_40 -> V_46 ) ;
}
}
else if ( * V_65 == V_66 ) {
if ( F_14 ( & V_40 -> V_44 ) )
goto V_69;
V_10 = F_40 ( & V_40 -> V_44 , struct V_3 ,
V_44 ) ;
F_41 ( & V_10 -> V_44 , & V_40 -> V_44 ) ;
} else if ( F_42 ( * V_65 ) ) {
if ( F_14 ( & V_40 -> V_45 ) )
goto V_69;
V_10 = F_40 ( & V_40 -> V_45 , struct V_3 ,
V_45 ) ;
F_41 ( & V_10 -> V_45 , & V_40 -> V_45 ) ;
} else {
V_10 = F_40 ( & V_40 -> V_46 , struct V_3 ,
V_46 ) ;
F_41 ( & V_10 -> V_46 , & V_40 -> V_46 ) ;
}
V_12 = V_10 -> V_12 ;
V_7 = V_10 -> V_7 ;
V_69:
F_43 ( & V_29 -> V_24 ) ;
V_68:
F_44 ( & V_67 ) ;
* V_65 = V_7 ;
return V_12 ;
}
int F_45 ( T_1 type , T_1 V_4 , T_1 V_5 , T_1 V_70 ,
struct V_71 * V_72 )
{
struct V_20 * V_29 ;
struct V_17 * V_19 ;
struct V_17 * V_73 ;
struct V_39 * V_40 ;
int V_74 = 0 ;
F_36 ( & V_67 ) ;
V_29 = F_29 ( type ) ;
if ( ! V_29 )
goto exit;
F_38 ( & V_29 -> V_24 ) ;
V_19 = V_29 -> V_25 + F_17 ( V_29 , V_4 ) ;
V_73 = V_29 -> V_25 + V_29 -> V_30 ;
for (; V_19 != V_73 ; V_19 ++ ) {
struct V_3 * V_10 ;
if ( V_19 -> V_4 > V_5 )
break;
V_40 = V_19 -> V_40 ;
F_19 (publ, &info->node_list, node_list) {
if ( V_10 -> V_6 <= V_70 )
F_46 ( V_72 , V_10 -> V_12 ) ;
}
if ( V_40 -> V_48 != V_40 -> V_49 )
V_74 = 1 ;
}
F_43 ( & V_29 -> V_24 ) ;
exit:
F_44 ( & V_67 ) ;
return V_74 ;
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
F_48 ( & V_67 ) ;
V_10 = F_31 ( type , V_4 , V_5 , V_6 ,
V_66 , V_8 , V_9 ) ;
if ( F_39 ( V_10 ) ) {
V_61 . V_75 ++ ;
F_49 ( V_10 ) ;
}
F_50 ( & V_67 ) ;
return V_10 ;
}
int F_51 ( T_1 type , T_1 V_4 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
F_48 ( & V_67 ) ;
V_10 = F_33 ( type , V_4 , V_66 , V_12 , V_9 ) ;
if ( F_39 ( V_10 ) ) {
V_61 . V_75 -- ;
F_52 ( V_10 ) ;
F_50 ( & V_67 ) ;
F_53 ( & V_10 -> V_14 ) ;
F_9 ( V_10 ) ;
return 1 ;
}
F_50 ( & V_67 ) ;
F_54 ( L_7
L_8 ,
type , V_4 , V_12 , V_9 ) ;
return 0 ;
}
void F_55 ( struct V_36 * V_37 )
{
T_1 type = V_37 -> V_29 . type ;
struct V_20 * V_29 ;
F_48 ( & V_67 ) ;
V_29 = F_29 ( type ) ;
if ( ! V_29 )
V_29 = F_8 ( type , & V_61 . V_62 [ F_1 ( type ) ] ) ;
if ( V_29 ) {
F_38 ( & V_29 -> V_24 ) ;
F_27 ( V_29 , V_37 ) ;
F_43 ( & V_29 -> V_24 ) ;
} else {
F_4 ( L_9 ,
V_37 -> V_29 . type , V_37 -> V_29 . V_4 , V_37 -> V_29 . V_5 ) ;
}
F_50 ( & V_67 ) ;
}
void F_56 ( struct V_36 * V_37 )
{
struct V_20 * V_29 ;
F_48 ( & V_67 ) ;
V_29 = F_29 ( V_37 -> V_29 . type ) ;
if ( V_29 != NULL ) {
F_38 ( & V_29 -> V_24 ) ;
F_53 ( & V_37 -> V_55 ) ;
F_43 ( & V_29 -> V_24 ) ;
F_13 ( V_29 ) ;
}
F_50 ( & V_67 ) ;
}
static int F_57 ( struct V_17 * V_19 , char * V_77 , int V_78 , T_1 V_79 ,
T_1 V_80 )
{
char V_81 [ 27 ] ;
const char * V_82 [] = { L_10 , L_11 , L_12 , L_13 } ;
struct V_3 * V_10 ;
struct V_39 * V_40 ;
int V_83 ;
V_83 = F_58 ( V_77 , V_78 , L_14 , V_19 -> V_4 , V_19 -> V_5 ) ;
if ( V_79 == 2 ) {
V_83 += F_58 ( V_77 - V_83 , V_78 + V_83 , L_15 ) ;
return V_83 ;
}
V_40 = V_19 -> V_40 ;
F_19 (publ, &info->zone_list, zone_list) {
sprintf ( V_81 , L_16 ,
F_59 ( V_10 -> V_7 ) , F_60 ( V_10 -> V_7 ) ,
F_61 ( V_10 -> V_7 ) , V_10 -> V_12 ) ;
V_83 += F_58 ( V_77 + V_83 , V_78 - V_83 , L_17 , V_81 ) ;
if ( V_79 > 3 ) {
V_83 += F_58 ( V_77 + V_83 , V_78 - V_83 , L_18 ,
V_10 -> V_9 , V_82 [ V_10 -> V_6 ] ) ;
}
if ( ! F_62 ( & V_10 -> V_46 , & V_40 -> V_46 ) )
V_83 += F_58 ( V_77 + V_83 , V_78 - V_83 ,
L_19 , L_20 ) ;
} ;
V_83 += F_58 ( V_77 + V_83 , V_78 - V_83 , L_15 ) ;
return V_83 ;
}
static int V_55 ( struct V_20 * V_29 , char * V_77 , int V_78 , T_1 V_79 ,
T_1 type , T_1 V_84 , T_1 V_85 , T_1 V_80 )
{
struct V_17 * V_19 ;
char V_86 [ 11 ] ;
int V_83 = 0 ;
if ( V_29 -> V_30 == 0 )
return 0 ;
sprintf ( V_86 , L_21 , V_29 -> type ) ;
if ( V_79 == 1 ) {
V_83 += F_58 ( V_77 , V_78 , L_22 , V_86 ) ;
return V_83 ;
}
for ( V_19 = V_29 -> V_25 ; V_19 != & V_29 -> V_25 [ V_29 -> V_30 ] ; V_19 ++ ) {
if ( ( V_84 <= V_19 -> V_5 ) && ( V_85 >= V_19 -> V_4 ) ) {
V_83 += F_58 ( V_77 + V_83 , V_78 - V_83 , L_23 ,
V_86 ) ;
F_38 ( & V_29 -> V_24 ) ;
V_83 += F_57 ( V_19 , V_77 + V_83 , V_78 - V_83 ,
V_79 , V_80 ) ;
F_43 ( & V_29 -> V_24 ) ;
sprintf ( V_86 , L_24 , L_20 ) ;
}
}
return V_83 ;
}
static int F_63 ( char * V_77 , int V_78 , T_1 V_79 )
{
const char * V_87 [] = {
L_25 ,
L_26 ,
L_27 ,
L_28
} ;
int V_88 ;
int V_83 = 0 ;
if ( V_79 > 4 )
V_79 = 4 ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ )
V_83 += F_58 ( V_77 + V_83 , V_78 - V_83 , V_87 [ V_88 ] ) ;
V_83 += F_58 ( V_77 + V_83 , V_78 - V_83 , L_15 ) ;
return V_83 ;
}
static int F_64 ( char * V_77 , int V_78 , T_1 V_89 ,
T_1 type , T_1 V_84 , T_1 V_85 )
{
struct V_21 * V_22 ;
struct V_58 * V_59 ;
struct V_20 * V_29 ;
int V_90 ;
int V_83 = 0 ;
T_1 V_79 ;
T_1 V_88 ;
V_90 = ( V_89 & V_91 ) ;
V_79 = ( V_89 & ~ V_91 ) ;
if ( V_79 == 0 )
return 0 ;
if ( V_90 ) {
V_83 += F_63 ( V_77 , V_78 , V_79 ) ;
V_84 = 0 ;
V_85 = ~ 0 ;
for ( V_88 = 0 ; V_88 < V_2 ; V_88 ++ ) {
V_22 = & V_61 . V_62 [ V_88 ] ;
F_30 (seq, seq_node, seq_head, ns_list) {
V_83 += V_55 ( V_29 , V_77 + V_83 , V_78 - V_83 ,
V_79 , V_29 -> type ,
V_84 , V_85 , V_88 ) ;
}
}
} else {
if ( V_85 < V_84 ) {
V_83 += F_58 ( V_77 + V_83 , V_78 - V_83 ,
L_29 ) ;
return V_83 ;
}
V_83 += F_63 ( V_77 + V_83 , V_78 - V_83 , V_79 ) ;
V_88 = F_1 ( type ) ;
V_22 = & V_61 . V_62 [ V_88 ] ;
F_30 (seq, seq_node, seq_head, ns_list) {
if ( V_29 -> type == type ) {
V_83 += V_55 ( V_29 , V_77 + V_83 , V_78 - V_83 ,
V_79 , type ,
V_84 , V_85 , V_88 ) ;
break;
}
}
}
return V_83 ;
}
struct V_92 * F_65 ( const void * V_93 , int V_94 )
{
struct V_92 * V_77 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
char * V_99 ;
int V_100 ;
int V_101 ;
if ( ! F_66 ( V_93 , V_94 , V_102 ) )
return F_67 ( V_103 ) ;
V_77 = F_68 ( F_69 ( V_104 ) ) ;
if ( ! V_77 )
return NULL ;
V_98 = (struct V_97 * ) V_77 -> V_105 ;
V_99 = F_70 ( V_98 ) ;
V_100 = V_104 ;
V_96 = (struct V_95 * ) F_70 ( V_93 ) ;
F_36 ( & V_67 ) ;
V_101 = F_64 ( V_99 , V_100 , F_71 ( V_96 -> V_79 ) ,
F_71 ( V_96 -> type ) ,
F_71 ( V_96 -> V_84 ) , F_71 ( V_96 -> V_85 ) ) ;
F_44 ( & V_67 ) ;
V_101 += 1 ;
F_72 ( V_77 , F_69 ( V_101 ) ) ;
F_73 ( V_98 , V_106 , NULL , V_101 ) ;
return V_77 ;
}
int F_74 ( void )
{
V_61 . V_62 = F_7 ( V_2 , sizeof( struct V_21 ) ,
V_11 ) ;
if ( ! V_61 . V_62 )
return - V_107 ;
V_61 . V_75 = 0 ;
return 0 ;
}
void F_75 ( void )
{
T_1 V_88 ;
if ( ! V_61 . V_62 )
return;
F_48 ( & V_67 ) ;
for ( V_88 = 0 ; V_88 < V_2 ; V_88 ++ ) {
if ( F_76 ( & V_61 . V_62 [ V_88 ] ) )
continue;
F_54 ( L_30 ) ;
break;
}
F_9 ( V_61 . V_62 ) ;
V_61 . V_62 = NULL ;
F_50 ( & V_67 ) ;
}
