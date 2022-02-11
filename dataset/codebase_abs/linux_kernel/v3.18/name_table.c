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
return F_7 ( V_18 , sizeof( struct V_17 ) , V_11 ) ;
}
static struct V_19 * F_8 ( T_1 type , struct V_20 * V_21 )
{
struct V_19 * V_22 = F_3 ( sizeof( * V_22 ) , V_11 ) ;
struct V_17 * V_23 = F_6 ( 1 ) ;
if ( ! V_22 || ! V_23 ) {
F_4 ( L_2 ) ;
F_9 ( V_22 ) ;
F_9 ( V_23 ) ;
return NULL ;
}
F_10 ( & V_22 -> V_24 ) ;
V_22 -> type = type ;
V_22 -> V_25 = V_23 ;
V_22 -> V_26 = 1 ;
F_11 ( & V_22 -> V_27 ) ;
F_5 ( & V_22 -> V_28 ) ;
F_12 ( & V_22 -> V_27 , V_21 ) ;
return V_22 ;
}
static void F_13 ( struct V_19 * V_29 )
{
if ( ! V_29 -> V_30 && F_14 ( & V_29 -> V_28 ) ) {
F_15 ( & V_29 -> V_27 ) ;
F_9 ( V_29 -> V_25 ) ;
F_9 ( V_29 ) ;
}
}
static struct V_17 * F_16 ( struct V_19 * V_22 ,
T_1 V_31 )
{
struct V_17 * V_25 = V_22 -> V_25 ;
int V_32 = 0 ;
int V_33 = V_22 -> V_30 - 1 ;
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
static T_1 F_17 ( struct V_19 * V_22 , T_1 V_31 )
{
struct V_17 * V_25 = V_22 -> V_25 ;
int V_32 = 0 ;
int V_33 = V_22 -> V_30 - 1 ;
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
static struct V_3 * F_18 ( struct V_19 * V_22 ,
T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_35 , T_1 V_9 )
{
struct V_36 * V_37 ;
struct V_36 * V_38 ;
struct V_3 * V_10 ;
struct V_17 * V_23 ;
struct V_39 * V_40 ;
int V_41 = 0 ;
V_23 = F_16 ( V_22 , V_4 ) ;
if ( V_23 ) {
if ( ( V_23 -> V_4 != V_4 ) || ( V_23 -> V_5 != V_5 ) ) {
return NULL ;
}
V_40 = V_23 -> V_40 ;
F_19 (publ, &info->zone_list, zone_list) {
if ( ( V_10 -> V_12 == V_35 ) && ( V_10 -> V_9 == V_9 ) &&
( ! V_10 -> V_7 || ( V_10 -> V_7 == V_7 ) ) )
return NULL ;
}
} else {
T_1 V_42 ;
struct V_17 * V_43 ;
V_42 = F_17 ( V_22 , V_4 ) ;
if ( ( V_42 < V_22 -> V_30 ) &&
( V_5 >= V_22 -> V_25 [ V_42 ] . V_4 ) ) {
return NULL ;
}
if ( V_22 -> V_30 == V_22 -> V_26 ) {
struct V_17 * V_25 = F_6 ( V_22 -> V_26 * 2 ) ;
if ( ! V_25 ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
memcpy ( V_25 , V_22 -> V_25 ,
V_22 -> V_26 * sizeof( struct V_17 ) ) ;
F_9 ( V_22 -> V_25 ) ;
V_22 -> V_25 = V_25 ;
V_22 -> V_26 *= 2 ;
}
V_40 = F_3 ( sizeof( * V_40 ) , V_11 ) ;
if ( ! V_40 ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
F_5 ( & V_40 -> V_44 ) ;
F_5 ( & V_40 -> V_45 ) ;
F_5 ( & V_40 -> V_46 ) ;
V_23 = & V_22 -> V_25 [ V_42 ] ;
V_43 = & V_22 -> V_25 [ V_22 -> V_30 ] ;
memmove ( V_23 + 1 , V_23 , ( V_43 - V_23 ) * sizeof( * V_23 ) ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_22 -> V_30 ++ ;
V_23 -> V_4 = V_4 ;
V_23 -> V_5 = V_5 ;
V_23 -> V_40 = V_40 ;
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
static struct V_3 * F_25 ( struct V_19 * V_22 , T_1 V_51 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_17 * V_23 = F_16 ( V_22 , V_51 ) ;
struct V_39 * V_40 ;
struct V_17 * free ;
struct V_36 * V_37 , * V_38 ;
int V_52 = 0 ;
if ( ! V_23 )
return NULL ;
V_40 = V_23 -> V_40 ;
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
free = & V_22 -> V_25 [ V_22 -> V_30 -- ] ;
memmove ( V_23 , V_23 + 1 , ( free - ( V_23 + 1 ) ) * sizeof( * V_23 ) ) ;
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
static void F_27 ( struct V_19 * V_22 ,
struct V_36 * V_37 )
{
struct V_17 * V_23 = V_22 -> V_25 ;
F_20 ( & V_37 -> V_55 , & V_22 -> V_28 ) ;
if ( ! V_23 )
return;
while ( V_23 != & V_22 -> V_25 [ V_22 -> V_30 ] ) {
if ( F_28 ( V_37 , V_23 -> V_4 , V_23 -> V_5 ) ) {
struct V_3 * V_56 ;
struct V_39 * V_40 = V_23 -> V_40 ;
int V_57 = 1 ;
F_19 (crs, &info->zone_list, zone_list) {
F_24 ( V_37 ,
V_23 -> V_4 ,
V_23 -> V_5 ,
V_50 ,
V_56 -> V_12 ,
V_56 -> V_7 ,
V_57 ) ;
V_57 = 0 ;
}
}
V_23 ++ ;
}
}
static struct V_19 * F_29 ( T_1 type )
{
struct V_20 * V_21 ;
struct V_19 * V_58 ;
V_21 = & V_59 . V_60 [ F_1 ( type ) ] ;
F_30 (ns, seq_head, ns_list) {
if ( V_58 -> type == type )
return V_58 ;
}
return NULL ;
}
struct V_3 * F_31 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_35 , T_1 V_9 )
{
struct V_19 * V_29 = F_29 ( type ) ;
if ( ( V_6 < V_61 ) || ( V_6 > V_62 ) ||
( V_4 > V_5 ) ) {
F_32 ( L_4 ,
type , V_4 , V_5 , V_6 ) ;
return NULL ;
}
if ( ! V_29 )
V_29 = F_8 ( type , & V_59 . V_60 [ F_1 ( type ) ] ) ;
if ( ! V_29 )
return NULL ;
return F_18 ( V_29 , type , V_4 , V_5 ,
V_6 , V_7 , V_35 , V_9 ) ;
}
struct V_3 * F_33 ( T_1 type , T_1 V_4 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_19 * V_29 = F_29 ( type ) ;
if ( ! V_29 )
return NULL ;
V_10 = F_25 ( V_29 , V_4 , V_7 , V_12 , V_9 ) ;
F_13 ( V_29 ) ;
return V_10 ;
}
T_1 F_34 ( T_1 type , T_1 V_31 , T_1 * V_63 )
{
struct V_17 * V_23 ;
struct V_39 * V_40 ;
struct V_3 * V_10 ;
struct V_19 * V_29 ;
T_1 V_12 = 0 ;
T_1 V_7 = 0 ;
if ( ! F_35 ( * V_63 , V_64 ) )
return 0 ;
F_36 ( & V_65 ) ;
V_29 = F_29 ( type ) ;
if ( F_37 ( ! V_29 ) )
goto V_66;
V_23 = F_16 ( V_29 , V_31 ) ;
if ( F_37 ( ! V_23 ) )
goto V_66;
F_38 ( & V_29 -> V_24 ) ;
V_40 = V_23 -> V_40 ;
if ( F_39 ( ! * V_63 ) ) {
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
else if ( * V_63 == V_64 ) {
if ( F_14 ( & V_40 -> V_44 ) )
goto V_67;
V_10 = F_40 ( & V_40 -> V_44 , struct V_3 ,
V_44 ) ;
F_41 ( & V_10 -> V_44 , & V_40 -> V_44 ) ;
} else if ( F_42 ( * V_63 ) ) {
if ( F_14 ( & V_40 -> V_45 ) )
goto V_67;
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
V_67:
F_43 ( & V_29 -> V_24 ) ;
V_66:
F_44 ( & V_65 ) ;
* V_63 = V_7 ;
return V_12 ;
}
int F_45 ( T_1 type , T_1 V_4 , T_1 V_5 , T_1 V_68 ,
struct V_69 * V_70 )
{
struct V_19 * V_29 ;
struct V_17 * V_23 ;
struct V_17 * V_71 ;
struct V_39 * V_40 ;
int V_72 = 0 ;
F_36 ( & V_65 ) ;
V_29 = F_29 ( type ) ;
if ( ! V_29 )
goto exit;
F_38 ( & V_29 -> V_24 ) ;
V_23 = V_29 -> V_25 + F_17 ( V_29 , V_4 ) ;
V_71 = V_29 -> V_25 + V_29 -> V_30 ;
for (; V_23 != V_71 ; V_23 ++ ) {
struct V_3 * V_10 ;
if ( V_23 -> V_4 > V_5 )
break;
V_40 = V_23 -> V_40 ;
F_19 (publ, &info->node_list, node_list) {
if ( V_10 -> V_6 <= V_68 )
F_46 ( V_70 , V_10 -> V_12 ) ;
}
if ( V_40 -> V_48 != V_40 -> V_49 )
V_72 = 1 ;
}
F_43 ( & V_29 -> V_24 ) ;
exit:
F_44 ( & V_65 ) ;
return V_72 ;
}
struct V_3 * F_47 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_8 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_73 * V_74 = NULL ;
if ( V_59 . V_75 >= V_76 ) {
F_4 ( L_5 ,
V_76 ) ;
return NULL ;
}
F_48 ( & V_65 ) ;
V_10 = F_31 ( type , V_4 , V_5 , V_6 ,
V_64 , V_8 , V_9 ) ;
if ( F_39 ( V_10 ) ) {
V_59 . V_75 ++ ;
V_74 = F_49 ( V_10 ) ;
F_50 () ;
}
F_51 ( & V_65 ) ;
if ( V_74 )
F_52 ( V_74 ) ;
return V_10 ;
}
int F_53 ( T_1 type , T_1 V_4 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_73 * V_74 ;
F_48 ( & V_65 ) ;
V_10 = F_33 ( type , V_4 , V_64 , V_12 , V_9 ) ;
if ( F_39 ( V_10 ) ) {
V_59 . V_75 -- ;
V_74 = F_54 ( V_10 ) ;
F_50 () ;
F_51 ( & V_65 ) ;
F_55 ( & V_10 -> V_14 ) ;
F_9 ( V_10 ) ;
if ( V_74 )
F_52 ( V_74 ) ;
return 1 ;
}
F_51 ( & V_65 ) ;
F_56 ( L_6
L_7 ,
type , V_4 , V_12 , V_9 ) ;
return 0 ;
}
void F_57 ( struct V_36 * V_37 )
{
T_1 type = V_37 -> V_29 . type ;
struct V_19 * V_29 ;
F_48 ( & V_65 ) ;
V_29 = F_29 ( type ) ;
if ( ! V_29 )
V_29 = F_8 ( type , & V_59 . V_60 [ F_1 ( type ) ] ) ;
if ( V_29 ) {
F_38 ( & V_29 -> V_24 ) ;
F_27 ( V_29 , V_37 ) ;
F_43 ( & V_29 -> V_24 ) ;
} else {
F_4 ( L_8 ,
V_37 -> V_29 . type , V_37 -> V_29 . V_4 , V_37 -> V_29 . V_5 ) ;
}
F_51 ( & V_65 ) ;
}
void F_58 ( struct V_36 * V_37 )
{
struct V_19 * V_29 ;
F_48 ( & V_65 ) ;
V_29 = F_29 ( V_37 -> V_29 . type ) ;
if ( V_29 != NULL ) {
F_38 ( & V_29 -> V_24 ) ;
F_55 ( & V_37 -> V_55 ) ;
F_43 ( & V_29 -> V_24 ) ;
F_13 ( V_29 ) ;
}
F_51 ( & V_65 ) ;
}
static int F_59 ( struct V_17 * V_23 , char * V_74 , int V_77 , T_1 V_78 ,
T_1 V_79 )
{
char V_80 [ 27 ] ;
const char * V_81 [] = { L_9 , L_10 , L_11 , L_12 } ;
struct V_3 * V_10 ;
struct V_39 * V_40 ;
int V_82 ;
V_82 = F_60 ( V_74 , V_77 , L_13 , V_23 -> V_4 , V_23 -> V_5 ) ;
if ( V_78 == 2 ) {
V_82 += F_60 ( V_74 - V_82 , V_77 + V_82 , L_14 ) ;
return V_82 ;
}
V_40 = V_23 -> V_40 ;
F_19 (publ, &info->zone_list, zone_list) {
sprintf ( V_80 , L_15 ,
F_61 ( V_10 -> V_7 ) , F_62 ( V_10 -> V_7 ) ,
F_63 ( V_10 -> V_7 ) , V_10 -> V_12 ) ;
V_82 += F_60 ( V_74 + V_82 , V_77 - V_82 , L_16 , V_80 ) ;
if ( V_78 > 3 ) {
V_82 += F_60 ( V_74 + V_82 , V_77 - V_82 , L_17 ,
V_10 -> V_9 , V_81 [ V_10 -> V_6 ] ) ;
}
if ( ! F_64 ( & V_10 -> V_46 , & V_40 -> V_46 ) )
V_82 += F_60 ( V_74 + V_82 , V_77 - V_82 ,
L_18 , L_19 ) ;
}
V_82 += F_60 ( V_74 + V_82 , V_77 - V_82 , L_14 ) ;
return V_82 ;
}
static int V_55 ( struct V_19 * V_29 , char * V_74 , int V_77 , T_1 V_78 ,
T_1 type , T_1 V_83 , T_1 V_84 , T_1 V_79 )
{
struct V_17 * V_23 ;
char V_85 [ 11 ] ;
int V_82 = 0 ;
if ( V_29 -> V_30 == 0 )
return 0 ;
sprintf ( V_85 , L_20 , V_29 -> type ) ;
if ( V_78 == 1 ) {
V_82 += F_60 ( V_74 , V_77 , L_21 , V_85 ) ;
return V_82 ;
}
for ( V_23 = V_29 -> V_25 ; V_23 != & V_29 -> V_25 [ V_29 -> V_30 ] ; V_23 ++ ) {
if ( ( V_83 <= V_23 -> V_5 ) && ( V_84 >= V_23 -> V_4 ) ) {
V_82 += F_60 ( V_74 + V_82 , V_77 - V_82 , L_22 ,
V_85 ) ;
F_38 ( & V_29 -> V_24 ) ;
V_82 += F_59 ( V_23 , V_74 + V_82 , V_77 - V_82 ,
V_78 , V_79 ) ;
F_43 ( & V_29 -> V_24 ) ;
sprintf ( V_85 , L_23 , L_19 ) ;
}
}
return V_82 ;
}
static int F_65 ( char * V_74 , int V_77 , T_1 V_78 )
{
const char * V_86 [] = {
L_24 ,
L_25 ,
L_26 ,
L_27
} ;
int V_87 ;
int V_82 = 0 ;
if ( V_78 > 4 )
V_78 = 4 ;
for ( V_87 = 0 ; V_87 < V_78 ; V_87 ++ )
V_82 += F_60 ( V_74 + V_82 , V_77 - V_82 , V_86 [ V_87 ] ) ;
V_82 += F_60 ( V_74 + V_82 , V_77 - V_82 , L_14 ) ;
return V_82 ;
}
static int F_66 ( char * V_74 , int V_77 , T_1 V_88 ,
T_1 type , T_1 V_83 , T_1 V_84 )
{
struct V_20 * V_21 ;
struct V_19 * V_29 ;
int V_89 ;
int V_82 = 0 ;
T_1 V_78 ;
T_1 V_87 ;
V_89 = ( V_88 & V_90 ) ;
V_78 = ( V_88 & ~ V_90 ) ;
if ( V_78 == 0 )
return 0 ;
if ( V_89 ) {
V_82 += F_65 ( V_74 , V_77 , V_78 ) ;
V_83 = 0 ;
V_84 = ~ 0 ;
for ( V_87 = 0 ; V_87 < V_2 ; V_87 ++ ) {
V_21 = & V_59 . V_60 [ V_87 ] ;
F_30 (seq, seq_head, ns_list) {
V_82 += V_55 ( V_29 , V_74 + V_82 , V_77 - V_82 ,
V_78 , V_29 -> type ,
V_83 , V_84 , V_87 ) ;
}
}
} else {
if ( V_84 < V_83 ) {
V_82 += F_60 ( V_74 + V_82 , V_77 - V_82 ,
L_28 ) ;
return V_82 ;
}
V_82 += F_65 ( V_74 + V_82 , V_77 - V_82 , V_78 ) ;
V_87 = F_1 ( type ) ;
V_21 = & V_59 . V_60 [ V_87 ] ;
F_30 (seq, seq_head, ns_list) {
if ( V_29 -> type == type ) {
V_82 += V_55 ( V_29 , V_74 + V_82 , V_77 - V_82 ,
V_78 , type ,
V_83 , V_84 , V_87 ) ;
break;
}
}
}
return V_82 ;
}
struct V_73 * F_67 ( const void * V_91 , int V_92 )
{
struct V_73 * V_74 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
char * V_97 ;
int V_98 ;
int V_99 ;
if ( ! F_68 ( V_91 , V_92 , V_100 ) )
return F_69 ( V_101 ) ;
V_74 = F_70 ( F_71 ( V_102 ) ) ;
if ( ! V_74 )
return NULL ;
V_96 = (struct V_95 * ) V_74 -> V_103 ;
V_97 = F_72 ( V_96 ) ;
V_98 = V_102 ;
V_94 = (struct V_93 * ) F_72 ( V_91 ) ;
F_36 ( & V_65 ) ;
V_99 = F_66 ( V_97 , V_98 , F_73 ( V_94 -> V_78 ) ,
F_73 ( V_94 -> type ) ,
F_73 ( V_94 -> V_83 ) , F_73 ( V_94 -> V_84 ) ) ;
F_44 ( & V_65 ) ;
V_99 += 1 ;
F_74 ( V_74 , F_71 ( V_99 ) ) ;
F_75 ( V_96 , V_104 , NULL , V_99 ) ;
return V_74 ;
}
int F_76 ( void )
{
V_59 . V_60 = F_7 ( V_2 , sizeof( struct V_20 ) ,
V_11 ) ;
if ( ! V_59 . V_60 )
return - V_105 ;
V_59 . V_75 = 0 ;
return 0 ;
}
static void F_77 ( struct V_19 * V_29 )
{
struct V_3 * V_10 , * V_106 ;
struct V_17 * V_23 ;
struct V_39 * V_40 ;
if ( ! V_29 -> V_25 ) {
F_13 ( V_29 ) ;
return;
}
V_23 = V_29 -> V_25 ;
V_40 = V_23 -> V_40 ;
F_23 (publ, safe, &info->zone_list, zone_list) {
F_33 ( V_10 -> type , V_10 -> V_4 , V_10 -> V_7 ,
V_10 -> V_12 , V_10 -> V_9 ) ;
F_9 ( V_10 ) ;
}
}
void F_78 ( void )
{
T_1 V_87 ;
struct V_19 * V_29 ;
struct V_20 * V_21 ;
struct V_107 * V_106 ;
F_48 ( & V_65 ) ;
for ( V_87 = 0 ; V_87 < V_2 ; V_87 ++ ) {
if ( F_79 ( & V_59 . V_60 [ V_87 ] ) )
continue;
V_21 = & V_59 . V_60 [ V_87 ] ;
F_80 (seq, safe, seq_head, ns_list) {
F_77 ( V_29 ) ;
}
}
F_9 ( V_59 . V_60 ) ;
V_59 . V_60 = NULL ;
F_51 ( & V_65 ) ;
}
