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
static struct V_3 * F_15 ( struct V_16 * V_19 ,
T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_31 , T_1 V_9 )
{
struct V_32 * V_33 ;
struct V_32 * V_34 ;
struct V_3 * V_10 ;
struct V_14 * V_20 ;
struct V_35 * V_36 ;
int V_37 = 0 ;
V_20 = F_13 ( V_19 , V_4 ) ;
if ( V_20 ) {
if ( ( V_20 -> V_4 != V_4 ) || ( V_20 -> V_5 != V_5 ) ) {
return NULL ;
}
V_36 = V_20 -> V_36 ;
F_16 (publ, &info->zone_list, zone_list) {
if ( ( V_10 -> V_12 == V_31 ) && ( V_10 -> V_9 == V_9 ) &&
( ! V_10 -> V_7 || ( V_10 -> V_7 == V_7 ) ) )
return NULL ;
}
} else {
T_1 V_38 ;
struct V_14 * V_39 ;
V_38 = F_14 ( V_19 , V_4 ) ;
if ( ( V_38 < V_19 -> V_29 ) &&
( V_5 >= V_19 -> V_22 [ V_38 ] . V_4 ) ) {
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
V_36 = F_3 ( sizeof( * V_36 ) , V_11 ) ;
if ( ! V_36 ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
F_5 ( & V_36 -> V_40 ) ;
F_5 ( & V_36 -> V_41 ) ;
F_5 ( & V_36 -> V_42 ) ;
V_20 = & V_19 -> V_22 [ V_38 ] ;
V_39 = & V_19 -> V_22 [ V_19 -> V_29 ] ;
memmove ( V_20 + 1 , V_20 , ( V_39 - V_20 ) * sizeof( * V_20 ) ) ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_19 -> V_29 ++ ;
V_20 -> V_4 = V_4 ;
V_20 -> V_5 = V_5 ;
V_20 -> V_36 = V_36 ;
V_37 = 1 ;
}
V_10 = F_2 ( type , V_4 , V_5 , V_6 , V_7 , V_31 , V_9 ) ;
if ( ! V_10 )
return NULL ;
F_17 ( & V_10 -> V_42 , & V_36 -> V_42 ) ;
V_36 -> V_43 ++ ;
if ( F_18 ( V_7 ) ) {
F_17 ( & V_10 -> V_41 , & V_36 -> V_41 ) ;
V_36 -> V_44 ++ ;
}
if ( F_19 ( V_7 ) ) {
F_17 ( & V_10 -> V_40 , & V_36 -> V_40 ) ;
V_36 -> V_45 ++ ;
}
F_20 (s, st, &nseq->subscriptions, nameseq_list) {
F_21 ( V_33 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_46 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_37 ) ;
}
return V_10 ;
}
static struct V_3 * F_22 ( struct V_16 * V_19 , T_1 V_47 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_14 * V_20 = F_13 ( V_19 , V_47 ) ;
struct V_35 * V_36 ;
struct V_14 * free ;
struct V_32 * V_33 , * V_34 ;
int V_48 = 0 ;
if ( ! V_20 )
return NULL ;
V_36 = V_20 -> V_36 ;
F_16 (publ, &info->zone_list, zone_list) {
if ( ( V_10 -> V_9 == V_9 ) && ( V_10 -> V_12 == V_12 ) &&
( ! V_10 -> V_7 || ( V_10 -> V_7 == V_7 ) ) )
goto V_49;
}
return NULL ;
V_49:
F_23 ( & V_10 -> V_42 ) ;
V_36 -> V_43 -- ;
if ( F_18 ( V_7 ) ) {
F_23 ( & V_10 -> V_41 ) ;
V_36 -> V_44 -- ;
}
if ( F_19 ( V_7 ) ) {
F_23 ( & V_10 -> V_40 ) ;
V_36 -> V_45 -- ;
}
if ( F_24 ( & V_36 -> V_42 ) ) {
F_9 ( V_36 ) ;
free = & V_19 -> V_22 [ V_19 -> V_29 -- ] ;
memmove ( V_20 , V_20 + 1 , ( free - ( V_20 + 1 ) ) * sizeof( * V_20 ) ) ;
V_48 = 1 ;
}
F_20 (s, st, &nseq->subscriptions, nameseq_list) {
F_21 ( V_33 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_50 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_48 ) ;
}
return V_10 ;
}
static void F_25 ( struct V_16 * V_19 ,
struct V_32 * V_33 )
{
struct V_14 * V_20 = V_19 -> V_22 ;
F_17 ( & V_33 -> V_51 , & V_19 -> V_25 ) ;
if ( ! V_20 )
return;
while ( V_20 != & V_19 -> V_22 [ V_19 -> V_29 ] ) {
if ( F_26 ( V_33 , V_20 -> V_4 , V_20 -> V_5 ) ) {
struct V_3 * V_52 ;
struct V_35 * V_36 = V_20 -> V_36 ;
int V_53 = 1 ;
F_16 (crs, &info->zone_list, zone_list) {
F_21 ( V_33 ,
V_20 -> V_4 ,
V_20 -> V_5 ,
V_46 ,
V_52 -> V_12 ,
V_52 -> V_7 ,
V_53 ) ;
V_53 = 0 ;
}
}
V_20 ++ ;
}
}
static struct V_16 * F_27 ( T_1 type )
{
struct V_17 * V_18 ;
struct V_16 * V_54 ;
V_18 = & V_55 -> V_56 [ F_1 ( type ) ] ;
F_28 (ns, seq_head, ns_list) {
if ( V_54 -> type == type )
return V_54 ;
}
return NULL ;
}
struct V_3 * F_29 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_31 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_16 * V_57 = F_27 ( type ) ;
int V_58 = F_1 ( type ) ;
if ( ( V_6 < V_59 ) || ( V_6 > V_60 ) ||
( V_4 > V_5 ) ) {
F_30 ( L_4 ,
type , V_4 , V_5 , V_6 ) ;
return NULL ;
}
if ( ! V_57 )
V_57 = F_8 ( type ,
& V_55 -> V_56 [ V_58 ] ) ;
if ( ! V_57 )
return NULL ;
F_31 ( & V_57 -> V_21 ) ;
V_10 = F_15 ( V_57 , type , V_4 , V_5 ,
V_6 , V_7 , V_31 , V_9 ) ;
F_32 ( & V_57 -> V_21 ) ;
return V_10 ;
}
struct V_3 * F_33 ( T_1 type , T_1 V_4 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_16 * V_57 = F_27 ( type ) ;
if ( ! V_57 )
return NULL ;
F_31 ( & V_57 -> V_21 ) ;
V_10 = F_22 ( V_57 , V_4 , V_7 , V_12 , V_9 ) ;
if ( ! V_57 -> V_29 && F_24 ( & V_57 -> V_25 ) ) {
F_34 ( & V_57 -> V_24 ) ;
F_9 ( V_57 -> V_22 ) ;
F_32 ( & V_57 -> V_21 ) ;
F_35 ( V_57 , V_61 ) ;
return V_10 ;
}
F_32 ( & V_57 -> V_21 ) ;
return V_10 ;
}
T_1 F_36 ( T_1 type , T_1 V_26 , T_1 * V_62 )
{
struct V_14 * V_20 ;
struct V_35 * V_36 ;
struct V_3 * V_10 ;
struct V_16 * V_57 ;
T_1 V_12 = 0 ;
T_1 V_7 = 0 ;
if ( ! F_37 ( * V_62 , V_63 ) )
return 0 ;
F_38 () ;
V_57 = F_27 ( type ) ;
if ( F_39 ( ! V_57 ) )
goto V_64;
F_31 ( & V_57 -> V_21 ) ;
V_20 = F_13 ( V_57 , V_26 ) ;
if ( F_39 ( ! V_20 ) )
goto V_65;
V_36 = V_20 -> V_36 ;
if ( F_40 ( ! * V_62 ) ) {
if ( ! F_24 ( & V_36 -> V_40 ) ) {
V_10 = F_41 ( & V_36 -> V_40 ,
struct V_3 ,
V_40 ) ;
F_42 ( & V_10 -> V_40 ,
& V_36 -> V_40 ) ;
} else if ( ! F_24 ( & V_36 -> V_41 ) ) {
V_10 = F_41 ( & V_36 -> V_41 ,
struct V_3 ,
V_41 ) ;
F_42 ( & V_10 -> V_41 ,
& V_36 -> V_41 ) ;
} else {
V_10 = F_41 ( & V_36 -> V_42 ,
struct V_3 ,
V_42 ) ;
F_42 ( & V_10 -> V_42 ,
& V_36 -> V_42 ) ;
}
}
else if ( * V_62 == V_63 ) {
if ( F_24 ( & V_36 -> V_40 ) )
goto V_65;
V_10 = F_41 ( & V_36 -> V_40 , struct V_3 ,
V_40 ) ;
F_42 ( & V_10 -> V_40 , & V_36 -> V_40 ) ;
} else if ( F_43 ( * V_62 ) ) {
if ( F_24 ( & V_36 -> V_41 ) )
goto V_65;
V_10 = F_41 ( & V_36 -> V_41 , struct V_3 ,
V_41 ) ;
F_42 ( & V_10 -> V_41 , & V_36 -> V_41 ) ;
} else {
V_10 = F_41 ( & V_36 -> V_42 , struct V_3 ,
V_42 ) ;
F_42 ( & V_10 -> V_42 , & V_36 -> V_42 ) ;
}
V_12 = V_10 -> V_12 ;
V_7 = V_10 -> V_7 ;
V_65:
F_32 ( & V_57 -> V_21 ) ;
V_64:
F_44 () ;
* V_62 = V_7 ;
return V_12 ;
}
int F_45 ( T_1 type , T_1 V_4 , T_1 V_5 , T_1 V_66 ,
struct V_67 * V_68 )
{
struct V_16 * V_57 ;
struct V_14 * V_20 ;
struct V_14 * V_69 ;
struct V_35 * V_36 ;
int V_70 = 0 ;
F_38 () ;
V_57 = F_27 ( type ) ;
if ( ! V_57 )
goto exit;
F_31 ( & V_57 -> V_21 ) ;
V_20 = V_57 -> V_22 + F_14 ( V_57 , V_4 ) ;
V_69 = V_57 -> V_22 + V_57 -> V_29 ;
for (; V_20 != V_69 ; V_20 ++ ) {
struct V_3 * V_10 ;
if ( V_20 -> V_4 > V_5 )
break;
V_36 = V_20 -> V_36 ;
F_16 (publ, &info->node_list, node_list) {
if ( V_10 -> V_6 <= V_66 )
F_46 ( V_68 , V_10 -> V_12 ) ;
}
if ( V_36 -> V_44 != V_36 -> V_45 )
V_70 = 1 ;
}
F_32 ( & V_57 -> V_21 ) ;
exit:
F_44 () ;
return V_70 ;
}
struct V_3 * F_47 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_8 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_71 * V_72 = NULL ;
F_31 ( & V_73 ) ;
if ( V_55 -> V_74 >= V_75 ) {
F_4 ( L_5 ,
V_75 ) ;
F_32 ( & V_73 ) ;
return NULL ;
}
V_10 = F_29 ( type , V_4 , V_5 , V_6 ,
V_63 , V_8 , V_9 ) ;
if ( F_40 ( V_10 ) ) {
V_55 -> V_74 ++ ;
V_72 = F_48 ( V_10 ) ;
F_49 () ;
}
F_32 ( & V_73 ) ;
if ( V_72 )
F_50 ( V_72 ) ;
return V_10 ;
}
int F_51 ( T_1 type , T_1 V_4 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_71 * V_76 = NULL ;
F_31 ( & V_73 ) ;
V_10 = F_33 ( type , V_4 , V_63 , V_12 , V_9 ) ;
if ( F_40 ( V_10 ) ) {
V_55 -> V_74 -- ;
V_76 = F_52 ( V_10 ) ;
F_49 () ;
F_53 ( & V_10 -> V_13 ) ;
F_35 ( V_10 , V_61 ) ;
} else {
F_54 ( L_6
L_7 ,
type , V_4 , V_12 , V_9 ) ;
}
F_32 ( & V_73 ) ;
if ( V_76 ) {
F_50 ( V_76 ) ;
return 1 ;
}
return 0 ;
}
void F_55 ( struct V_32 * V_33 )
{
T_1 type = V_33 -> V_57 . type ;
int V_58 = F_1 ( type ) ;
struct V_16 * V_57 ;
F_31 ( & V_73 ) ;
V_57 = F_27 ( type ) ;
if ( ! V_57 )
V_57 = F_8 ( type ,
& V_55 -> V_56 [ V_58 ] ) ;
if ( V_57 ) {
F_31 ( & V_57 -> V_21 ) ;
F_25 ( V_57 , V_33 ) ;
F_32 ( & V_57 -> V_21 ) ;
} else {
F_4 ( L_8 ,
V_33 -> V_57 . type , V_33 -> V_57 . V_4 , V_33 -> V_57 . V_5 ) ;
}
F_32 ( & V_73 ) ;
}
void F_56 ( struct V_32 * V_33 )
{
struct V_16 * V_57 ;
F_31 ( & V_73 ) ;
V_57 = F_27 ( V_33 -> V_57 . type ) ;
if ( V_57 != NULL ) {
F_31 ( & V_57 -> V_21 ) ;
F_53 ( & V_33 -> V_51 ) ;
if ( ! V_57 -> V_29 && F_24 ( & V_57 -> V_25 ) ) {
F_34 ( & V_57 -> V_24 ) ;
F_9 ( V_57 -> V_22 ) ;
F_32 ( & V_57 -> V_21 ) ;
F_35 ( V_57 , V_61 ) ;
} else {
F_32 ( & V_57 -> V_21 ) ;
}
}
F_32 ( & V_73 ) ;
}
static int F_57 ( struct V_14 * V_20 , char * V_72 , int V_77 , T_1 V_78 ,
T_1 V_58 )
{
char V_79 [ 27 ] ;
const char * V_80 [] = { L_9 , L_10 , L_11 , L_12 } ;
struct V_3 * V_10 ;
struct V_35 * V_36 ;
int V_81 ;
V_81 = F_58 ( V_72 , V_77 , L_13 , V_20 -> V_4 , V_20 -> V_5 ) ;
if ( V_78 == 2 ) {
V_81 += F_58 ( V_72 - V_81 , V_77 + V_81 , L_14 ) ;
return V_81 ;
}
V_36 = V_20 -> V_36 ;
F_16 (publ, &info->zone_list, zone_list) {
sprintf ( V_79 , L_15 ,
F_59 ( V_10 -> V_7 ) , F_60 ( V_10 -> V_7 ) ,
F_61 ( V_10 -> V_7 ) , V_10 -> V_12 ) ;
V_81 += F_58 ( V_72 + V_81 , V_77 - V_81 , L_16 , V_79 ) ;
if ( V_78 > 3 ) {
V_81 += F_58 ( V_72 + V_81 , V_77 - V_81 , L_17 ,
V_10 -> V_9 , V_80 [ V_10 -> V_6 ] ) ;
}
if ( ! F_62 ( & V_10 -> V_42 , & V_36 -> V_42 ) )
V_81 += F_58 ( V_72 + V_81 , V_77 - V_81 ,
L_18 , L_19 ) ;
}
V_81 += F_58 ( V_72 + V_81 , V_77 - V_81 , L_14 ) ;
return V_81 ;
}
static int V_51 ( struct V_16 * V_57 , char * V_72 , int V_77 , T_1 V_78 ,
T_1 type , T_1 V_82 , T_1 V_83 , T_1 V_58 )
{
struct V_14 * V_20 ;
char V_84 [ 11 ] ;
int V_81 = 0 ;
if ( V_57 -> V_29 == 0 )
return 0 ;
sprintf ( V_84 , L_20 , V_57 -> type ) ;
if ( V_78 == 1 ) {
V_81 += F_58 ( V_72 , V_77 , L_21 , V_84 ) ;
return V_81 ;
}
for ( V_20 = V_57 -> V_22 ; V_20 != & V_57 -> V_22 [ V_57 -> V_29 ] ; V_20 ++ ) {
if ( ( V_82 <= V_20 -> V_5 ) && ( V_83 >= V_20 -> V_4 ) ) {
V_81 += F_58 ( V_72 + V_81 , V_77 - V_81 , L_22 ,
V_84 ) ;
F_31 ( & V_57 -> V_21 ) ;
V_81 += F_57 ( V_20 , V_72 + V_81 , V_77 - V_81 ,
V_78 , V_58 ) ;
F_32 ( & V_57 -> V_21 ) ;
sprintf ( V_84 , L_23 , L_19 ) ;
}
}
return V_81 ;
}
static int F_63 ( char * V_72 , int V_77 , T_1 V_78 )
{
const char * V_85 [] = {
L_24 ,
L_25 ,
L_26 ,
L_27
} ;
int V_86 ;
int V_81 = 0 ;
if ( V_78 > 4 )
V_78 = 4 ;
for ( V_86 = 0 ; V_86 < V_78 ; V_86 ++ )
V_81 += F_58 ( V_72 + V_81 , V_77 - V_81 , V_85 [ V_86 ] ) ;
V_81 += F_58 ( V_72 + V_81 , V_77 - V_81 , L_14 ) ;
return V_81 ;
}
static int F_64 ( char * V_72 , int V_77 , T_1 V_87 ,
T_1 type , T_1 V_82 , T_1 V_83 )
{
struct V_17 * V_18 ;
struct V_16 * V_57 ;
int V_88 ;
int V_81 = 0 ;
T_1 V_78 ;
T_1 V_86 ;
V_88 = ( V_87 & V_89 ) ;
V_78 = ( V_87 & ~ V_89 ) ;
if ( V_78 == 0 )
return 0 ;
if ( V_88 ) {
V_81 += F_63 ( V_72 , V_77 , V_78 ) ;
V_82 = 0 ;
V_83 = ~ 0 ;
for ( V_86 = 0 ; V_86 < V_2 ; V_86 ++ ) {
V_18 = & V_55 -> V_56 [ V_86 ] ;
F_28 (seq, seq_head, ns_list) {
V_81 += V_51 ( V_57 , V_72 + V_81 , V_77 - V_81 ,
V_78 , V_57 -> type ,
V_82 , V_83 , V_86 ) ;
}
}
} else {
if ( V_83 < V_82 ) {
V_81 += F_58 ( V_72 + V_81 , V_77 - V_81 ,
L_28 ) ;
return V_81 ;
}
V_81 += F_63 ( V_72 + V_81 , V_77 - V_81 , V_78 ) ;
V_86 = F_1 ( type ) ;
V_18 = & V_55 -> V_56 [ V_86 ] ;
F_28 (seq, seq_head, ns_list) {
if ( V_57 -> type == type ) {
V_81 += V_51 ( V_57 , V_72 + V_81 , V_77 - V_81 ,
V_78 , type ,
V_82 , V_83 , V_86 ) ;
break;
}
}
}
return V_81 ;
}
struct V_71 * F_65 ( const void * V_90 , int V_91 )
{
struct V_71 * V_72 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
char * V_96 ;
int V_97 ;
int V_98 ;
if ( ! F_66 ( V_90 , V_91 , V_99 ) )
return F_67 ( V_100 ) ;
V_72 = F_68 ( F_69 ( V_101 ) ) ;
if ( ! V_72 )
return NULL ;
V_95 = (struct V_94 * ) V_72 -> V_102 ;
V_96 = F_70 ( V_95 ) ;
V_97 = V_101 ;
V_93 = (struct V_92 * ) F_70 ( V_90 ) ;
F_38 () ;
V_98 = F_64 ( V_96 , V_97 , F_71 ( V_93 -> V_78 ) ,
F_71 ( V_93 -> type ) ,
F_71 ( V_93 -> V_82 ) , F_71 ( V_93 -> V_83 ) ) ;
F_44 () ;
V_98 += 1 ;
F_72 ( V_72 , F_69 ( V_98 ) ) ;
F_73 ( V_95 , V_103 , NULL , V_98 ) ;
return V_72 ;
}
int F_74 ( void )
{
int V_86 ;
V_55 = F_3 ( sizeof( * V_55 ) , V_11 ) ;
if ( ! V_55 )
return - V_104 ;
for ( V_86 = 0 ; V_86 < V_2 ; V_86 ++ )
F_75 ( & V_55 -> V_56 [ V_86 ] ) ;
F_5 ( & V_55 -> V_105 [ V_59 ] ) ;
F_5 ( & V_55 -> V_105 [ V_106 ] ) ;
F_5 ( & V_55 -> V_105 [ V_60 ] ) ;
return 0 ;
}
static void F_76 ( struct V_16 * V_57 )
{
struct V_3 * V_10 , * V_107 ;
struct V_14 * V_20 ;
struct V_35 * V_36 ;
F_31 ( & V_57 -> V_21 ) ;
V_20 = V_57 -> V_22 ;
V_36 = V_20 -> V_36 ;
F_20 (publ, safe, &info->zone_list, zone_list) {
F_33 ( V_10 -> type , V_10 -> V_4 , V_10 -> V_7 ,
V_10 -> V_12 , V_10 -> V_9 ) ;
F_35 ( V_10 , V_61 ) ;
}
F_34 ( & V_57 -> V_24 ) ;
F_9 ( V_57 -> V_22 ) ;
F_32 ( & V_57 -> V_21 ) ;
F_35 ( V_57 , V_61 ) ;
}
void F_77 ( void )
{
T_1 V_86 ;
struct V_16 * V_57 ;
struct V_17 * V_18 ;
F_31 ( & V_73 ) ;
for ( V_86 = 0 ; V_86 < V_2 ; V_86 ++ ) {
if ( F_78 ( & V_55 -> V_56 [ V_86 ] ) )
continue;
V_18 = & V_55 -> V_56 [ V_86 ] ;
F_28 (seq, seq_head, ns_list) {
F_76 ( V_57 ) ;
}
}
F_32 ( & V_73 ) ;
F_79 () ;
F_9 ( V_55 ) ;
}
static int F_80 ( struct V_108 * V_109 ,
struct V_16 * V_57 ,
struct V_14 * V_20 , T_1 * V_110 )
{
void * V_111 ;
struct V_112 * V_113 ;
struct V_112 * V_10 ;
struct V_3 * V_114 ;
if ( * V_110 ) {
F_16 (p, &sseq->info->zone_list, zone_list)
if ( V_114 -> V_9 == * V_110 )
break;
if ( V_114 -> V_9 != * V_110 )
return - V_115 ;
} else {
V_114 = F_41 ( & V_20 -> V_36 -> V_42 , struct V_3 ,
V_42 ) ;
}
F_81 (p, &sseq->info->zone_list, zone_list) {
* V_110 = V_114 -> V_9 ;
V_111 = F_82 ( V_109 -> V_76 , V_109 -> V_116 , V_109 -> V_57 ,
& V_117 , V_118 ,
V_119 ) ;
if ( ! V_111 )
return - V_120 ;
V_113 = F_83 ( V_109 -> V_76 , V_121 ) ;
if ( ! V_113 )
goto V_122;
V_10 = F_83 ( V_109 -> V_76 , V_123 ) ;
if ( ! V_10 )
goto V_124;
if ( F_84 ( V_109 -> V_76 , V_125 , V_57 -> type ) )
goto V_126;
if ( F_84 ( V_109 -> V_76 , V_127 , V_20 -> V_4 ) )
goto V_126;
if ( F_84 ( V_109 -> V_76 , V_128 , V_20 -> V_5 ) )
goto V_126;
if ( F_84 ( V_109 -> V_76 , V_129 , V_114 -> V_6 ) )
goto V_126;
if ( F_84 ( V_109 -> V_76 , V_130 , V_114 -> V_7 ) )
goto V_126;
if ( F_84 ( V_109 -> V_76 , V_131 , V_114 -> V_12 ) )
goto V_126;
if ( F_84 ( V_109 -> V_76 , V_132 , V_114 -> V_9 ) )
goto V_126;
F_85 ( V_109 -> V_76 , V_10 ) ;
F_85 ( V_109 -> V_76 , V_113 ) ;
F_86 ( V_109 -> V_76 , V_111 ) ;
}
* V_110 = 0 ;
return 0 ;
V_126:
F_87 ( V_109 -> V_76 , V_10 ) ;
V_124:
F_87 ( V_109 -> V_76 , V_113 ) ;
V_122:
F_88 ( V_109 -> V_76 , V_111 ) ;
return - V_120 ;
}
static int F_89 ( struct V_108 * V_109 , struct V_16 * V_57 ,
T_1 * V_133 , T_1 * V_110 )
{
struct V_14 * V_20 ;
struct V_14 * V_134 ;
int V_135 ;
if ( * V_133 ) {
V_134 = F_13 ( V_57 , * V_133 ) ;
if ( ! V_134 )
return - V_115 ;
} else {
V_134 = V_57 -> V_22 ;
}
for ( V_20 = V_134 ; V_20 != & V_57 -> V_22 [ V_57 -> V_29 ] ; V_20 ++ ) {
V_135 = F_80 ( V_109 , V_57 , V_20 , V_110 ) ;
if ( V_135 ) {
* V_133 = V_20 -> V_4 ;
return V_135 ;
}
}
* V_133 = 0 ;
return 0 ;
}
static int F_90 ( struct V_108 * V_109 , T_1 * V_136 ,
T_1 * V_133 , T_1 * V_110 )
{
struct V_17 * V_18 ;
struct V_16 * V_57 = NULL ;
int V_135 ;
int V_86 ;
if ( * V_136 )
V_86 = F_1 ( * V_136 ) ;
else
V_86 = 0 ;
for (; V_86 < V_2 ; V_86 ++ ) {
V_18 = & V_55 -> V_56 [ V_86 ] ;
if ( * V_136 ) {
V_57 = F_27 ( * V_136 ) ;
if ( ! V_57 )
return - V_115 ;
} else {
F_28 (seq, seq_head, ns_list)
break;
if ( ! V_57 )
continue;
}
F_91 (seq, ns_list) {
F_31 ( & V_57 -> V_21 ) ;
V_135 = F_89 ( V_109 , V_57 , V_133 ,
V_110 ) ;
if ( V_135 ) {
* V_136 = V_57 -> type ;
F_32 ( & V_57 -> V_21 ) ;
return V_135 ;
}
F_32 ( & V_57 -> V_21 ) ;
}
* V_136 = 0 ;
}
return 0 ;
}
int F_92 ( struct V_71 * V_76 , struct V_137 * V_138 )
{
int V_135 ;
int V_139 = V_138 -> args [ 3 ] ;
T_1 V_136 = V_138 -> args [ 0 ] ;
T_1 V_133 = V_138 -> args [ 1 ] ;
T_1 V_110 = V_138 -> args [ 2 ] ;
struct V_108 V_109 ;
if ( V_139 )
return 0 ;
V_109 . V_76 = V_76 ;
V_109 . V_116 = F_93 ( V_138 -> V_76 ) . V_116 ;
V_109 . V_57 = V_138 -> V_140 -> V_141 ;
F_38 () ;
V_135 = F_90 ( & V_109 , & V_136 , & V_133 , & V_110 ) ;
if ( ! V_135 ) {
V_139 = 1 ;
} else if ( V_135 != - V_120 ) {
V_138 -> V_142 = 1 ;
}
F_44 () ;
V_138 -> args [ 0 ] = V_136 ;
V_138 -> args [ 1 ] = V_133 ;
V_138 -> args [ 2 ] = V_110 ;
V_138 -> args [ 3 ] = V_139 ;
return V_76 -> V_77 ;
}
