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
int V_38 = 0 ;
V_19 = F_13 ( V_23 , V_4 ) ;
if ( V_19 ) {
if ( ( V_19 -> V_4 != V_4 ) || ( V_19 -> V_5 != V_5 ) ) {
F_4 ( L_3 ,
type , V_4 , V_5 ) ;
return NULL ;
}
} else {
T_1 V_39 ;
struct V_17 * V_40 ;
V_39 = F_14 ( V_23 , V_4 ) ;
if ( ( V_39 < V_23 -> V_32 ) &&
( V_5 >= V_23 -> V_25 [ V_39 ] . V_4 ) ) {
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
V_19 = & V_23 -> V_25 [ V_39 ] ;
V_40 = & V_23 -> V_25 [ V_23 -> V_32 ] ;
memmove ( V_19 + 1 , V_19 , ( V_40 - V_19 ) * sizeof( * V_19 ) ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_23 -> V_32 ++ ;
V_19 -> V_4 = V_4 ;
V_19 -> V_5 = V_5 ;
V_38 = 1 ;
}
V_10 = F_2 ( type , V_4 , V_5 , V_6 , V_7 , V_34 , V_9 ) ;
if ( ! V_10 )
return NULL ;
V_19 -> V_41 ++ ;
if ( ! V_19 -> V_42 )
V_19 -> V_42 = V_10 -> V_43 = V_10 ;
else {
V_10 -> V_43 = V_19 -> V_42 -> V_43 ;
V_19 -> V_42 -> V_43 = V_10 ;
}
if ( F_16 ( V_7 ) ) {
V_19 -> V_44 ++ ;
if ( ! V_19 -> V_45 )
V_19 -> V_45 = V_10 -> V_46 = V_10 ;
else {
V_10 -> V_46 =
V_19 -> V_45 -> V_46 ;
V_19 -> V_45 -> V_46 = V_10 ;
}
}
if ( V_7 == V_47 ) {
V_19 -> V_48 ++ ;
if ( ! V_19 -> V_49 )
V_19 -> V_49 = V_10 -> V_50 = V_10 ;
else {
V_10 -> V_50 = V_19 -> V_49 -> V_50 ;
V_19 -> V_49 -> V_50 = V_10 ;
}
}
F_17 (s, st, &nseq->subscriptions, nameseq_list) {
F_18 ( V_36 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_51 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_38 ) ;
}
return V_10 ;
}
static struct V_3 * F_19 ( struct V_20 * V_23 , T_1 V_52 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_3 * V_53 ;
struct V_3 * V_54 ;
struct V_17 * V_19 = F_13 ( V_23 , V_52 ) ;
struct V_17 * free ;
struct V_35 * V_36 , * V_37 ;
int V_55 = 0 ;
if ( ! V_19 )
return NULL ;
V_54 = V_19 -> V_42 ;
V_10 = V_19 -> V_42 -> V_43 ;
while ( ( V_10 -> V_9 != V_9 ) || ( V_10 -> V_12 != V_12 ) ||
( V_10 -> V_7 && ( V_10 -> V_7 != V_7 ) ) ) {
V_54 = V_10 ;
V_10 = V_10 -> V_43 ;
if ( V_54 == V_19 -> V_42 ) {
return NULL ;
}
}
if ( V_10 != V_19 -> V_42 )
V_54 -> V_43 = V_10 -> V_43 ;
else if ( V_10 -> V_43 != V_10 ) {
V_54 -> V_43 = V_10 -> V_43 ;
V_19 -> V_42 = V_10 -> V_43 ;
} else {
V_19 -> V_42 = NULL ;
}
V_19 -> V_41 -- ;
if ( F_16 ( V_7 ) ) {
V_54 = V_19 -> V_45 ;
V_53 = V_19 -> V_45 -> V_46 ;
while ( V_53 != V_10 ) {
V_54 = V_53 ;
V_53 = V_53 -> V_46 ;
if ( V_54 == V_19 -> V_45 ) {
F_20 ( L_5
L_6 ,
V_10 -> type , V_10 -> V_4 , V_10 -> V_7 ,
V_10 -> V_12 , V_10 -> V_9 ) ;
goto V_56;
}
}
if ( V_10 != V_19 -> V_45 )
V_54 -> V_46 = V_10 -> V_46 ;
else if ( V_10 -> V_46 != V_10 ) {
V_54 -> V_46 = V_10 -> V_46 ;
V_19 -> V_45 = V_10 -> V_46 ;
} else {
V_19 -> V_45 = NULL ;
}
V_19 -> V_44 -- ;
}
V_56:
if ( V_7 == V_47 ) {
V_54 = V_19 -> V_49 ;
V_53 = V_19 -> V_49 -> V_50 ;
while ( V_53 != V_10 ) {
V_54 = V_53 ;
V_53 = V_53 -> V_50 ;
if ( V_54 == V_19 -> V_49 ) {
F_20 ( L_7
L_6 ,
V_10 -> type , V_10 -> V_4 , V_10 -> V_7 ,
V_10 -> V_12 , V_10 -> V_9 ) ;
goto V_57;
}
}
if ( V_10 != V_19 -> V_49 )
V_54 -> V_50 = V_10 -> V_50 ;
else if ( V_10 -> V_50 != V_10 ) {
V_54 -> V_50 = V_10 -> V_50 ;
V_19 -> V_49 = V_10 -> V_50 ;
} else {
V_19 -> V_49 = NULL ;
}
V_19 -> V_48 -- ;
}
V_57:
if ( ! V_19 -> V_42 ) {
free = & V_23 -> V_25 [ V_23 -> V_32 -- ] ;
memmove ( V_19 , V_19 + 1 , ( free - ( V_19 + 1 ) ) * sizeof( * V_19 ) ) ;
V_55 = 1 ;
}
F_17 (s, st, &nseq->subscriptions, nameseq_list) {
F_18 ( V_36 ,
V_10 -> V_4 ,
V_10 -> V_5 ,
V_58 ,
V_10 -> V_12 ,
V_10 -> V_7 ,
V_55 ) ;
}
return V_10 ;
}
static void F_21 ( struct V_20 * V_23 , struct V_35 * V_36 )
{
struct V_17 * V_19 = V_23 -> V_25 ;
F_22 ( & V_36 -> V_59 , & V_23 -> V_28 ) ;
if ( ! V_19 )
return;
while ( V_19 != & V_23 -> V_25 [ V_23 -> V_32 ] ) {
struct V_3 * V_60 = V_19 -> V_42 ;
if ( V_60 && F_23 ( V_36 , V_19 -> V_4 , V_19 -> V_5 ) ) {
struct V_3 * V_61 = V_60 ;
int V_62 = 1 ;
do {
F_18 ( V_36 ,
V_19 -> V_4 ,
V_19 -> V_5 ,
V_51 ,
V_61 -> V_12 ,
V_61 -> V_7 ,
V_62 ) ;
V_62 = 0 ;
V_61 = V_61 -> V_43 ;
} while ( V_61 != V_60 );
}
V_19 ++ ;
}
}
static struct V_20 * F_24 ( T_1 type )
{
struct V_21 * V_22 ;
struct V_63 * V_64 ;
struct V_20 * V_65 ;
V_22 = & V_66 . V_67 [ F_1 ( type ) ] ;
F_25 (ns, seq_node, seq_head, ns_list) {
if ( V_65 -> type == type )
return V_65 ;
}
return NULL ;
}
struct V_3 * F_26 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_34 , T_1 V_9 )
{
struct V_20 * V_68 = F_24 ( type ) ;
if ( V_4 > V_5 ) {
F_4 ( L_8 ,
type , V_4 , V_5 ) ;
return NULL ;
}
if ( ! V_68 )
V_68 = F_8 ( type , & V_66 . V_67 [ F_1 ( type ) ] ) ;
if ( ! V_68 )
return NULL ;
return F_15 ( V_68 , type , V_4 , V_5 ,
V_6 , V_7 , V_34 , V_9 ) ;
}
struct V_3 * F_27 ( T_1 type , T_1 V_4 ,
T_1 V_7 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
struct V_20 * V_68 = F_24 ( type ) ;
if ( ! V_68 )
return NULL ;
V_10 = F_19 ( V_68 , V_4 , V_7 , V_12 , V_9 ) ;
if ( ! V_68 -> V_32 && F_28 ( & V_68 -> V_28 ) ) {
F_29 ( & V_68 -> V_27 ) ;
F_9 ( V_68 -> V_25 ) ;
F_9 ( V_68 ) ;
}
return V_10 ;
}
T_1 F_30 ( T_1 type , T_1 V_29 , T_1 * V_69 )
{
struct V_17 * V_19 ;
struct V_3 * V_10 = NULL ;
struct V_20 * V_68 ;
T_1 V_12 ;
if ( ! F_31 ( * V_69 , V_47 ) )
return 0 ;
F_32 ( & V_70 ) ;
V_68 = F_24 ( type ) ;
if ( F_33 ( ! V_68 ) )
goto V_71;
V_19 = F_13 ( V_68 , V_29 ) ;
if ( F_33 ( ! V_19 ) )
goto V_71;
F_34 ( & V_68 -> V_24 ) ;
if ( F_35 ( ! * V_69 ) ) {
V_10 = V_19 -> V_49 ;
if ( V_10 ) {
V_19 -> V_49 = V_10 -> V_50 ;
V_72:
V_12 = V_10 -> V_12 ;
* V_69 = V_10 -> V_7 ;
F_36 ( & V_68 -> V_24 ) ;
F_37 ( & V_70 ) ;
return V_12 ;
}
V_10 = V_19 -> V_45 ;
if ( V_10 ) {
V_19 -> V_45 = V_10 -> V_46 ;
goto V_72;
}
V_10 = V_19 -> V_42 ;
if ( V_10 ) {
V_19 -> V_42 = V_10 -> V_43 ;
goto V_72;
}
}
else if ( * V_69 == V_47 ) {
V_10 = V_19 -> V_49 ;
if ( V_10 ) {
V_19 -> V_49 = V_10 -> V_50 ;
goto V_72;
}
} else if ( F_16 ( * V_69 ) ) {
V_10 = V_19 -> V_45 ;
if ( V_10 ) {
V_19 -> V_45 = V_10 -> V_46 ;
goto V_72;
}
} else {
V_10 = V_19 -> V_42 ;
if ( V_10 ) {
V_19 -> V_42 = V_10 -> V_43 ;
goto V_72;
}
}
F_36 ( & V_68 -> V_24 ) ;
V_71:
F_37 ( & V_70 ) ;
return 0 ;
}
int F_38 ( T_1 type , T_1 V_4 , T_1 V_5 , T_1 V_73 ,
struct V_74 * V_75 )
{
struct V_20 * V_68 ;
struct V_17 * V_19 ;
struct V_17 * V_76 ;
int V_77 = 0 ;
F_32 ( & V_70 ) ;
V_68 = F_24 ( type ) ;
if ( ! V_68 )
goto exit;
F_34 ( & V_68 -> V_24 ) ;
V_19 = V_68 -> V_25 + F_14 ( V_68 , V_4 ) ;
V_76 = V_68 -> V_25 + V_68 -> V_32 ;
for (; V_19 != V_76 ; V_19 ++ ) {
struct V_3 * V_10 ;
if ( V_19 -> V_4 > V_5 )
break;
V_10 = V_19 -> V_49 ;
if ( V_10 ) {
do {
if ( V_10 -> V_6 <= V_73 )
F_39 ( V_75 , V_10 -> V_12 ) ;
V_10 = V_10 -> V_50 ;
} while ( V_10 != V_19 -> V_49 );
}
if ( V_19 -> V_44 != V_19 -> V_48 )
V_77 = 1 ;
}
F_36 ( & V_68 -> V_24 ) ;
exit:
F_37 ( & V_70 ) ;
return V_77 ;
}
int F_40 ( T_1 V_12 , unsigned int V_6 ,
struct V_78 const * V_68 )
{
int V_77 ;
F_41 ( & V_79 ) ;
V_77 = F_42 ( V_12 , V_6 , V_68 ) ;
F_43 ( & V_79 ) ;
return V_77 ;
}
struct V_3 * F_44 ( T_1 type , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_8 , T_1 V_9 )
{
struct V_3 * V_10 ;
if ( V_66 . V_80 >= V_81 ) {
F_4 ( L_9 ,
V_81 ) ;
return NULL ;
}
if ( ( type < V_82 ) && ! F_45 ( & V_79 ) ) {
F_4 ( L_10 ,
type , V_4 , V_5 ) ;
return NULL ;
}
F_46 ( & V_70 ) ;
V_66 . V_80 ++ ;
V_10 = F_26 ( type , V_4 , V_5 , V_6 ,
V_47 , V_8 , V_9 ) ;
if ( V_10 && ( V_6 != V_83 ) )
F_47 ( V_10 ) ;
F_48 ( & V_70 ) ;
return V_10 ;
}
int F_49 ( T_1 type , T_1 V_4 , T_1 V_12 , T_1 V_9 )
{
struct V_3 * V_10 ;
F_46 ( & V_70 ) ;
V_10 = F_27 ( type , V_4 , V_47 , V_12 , V_9 ) ;
if ( F_35 ( V_10 ) ) {
V_66 . V_80 -- ;
if ( V_10 -> V_6 != V_83 )
F_50 ( V_10 ) ;
F_48 ( & V_70 ) ;
F_51 ( & V_10 -> V_14 ) ;
F_9 ( V_10 ) ;
return 1 ;
}
F_48 ( & V_70 ) ;
F_20 ( L_11
L_12 ,
type , V_4 , V_12 , V_9 ) ;
return 0 ;
}
void F_52 ( struct V_35 * V_36 )
{
T_1 type = V_36 -> V_68 . type ;
struct V_20 * V_68 ;
F_46 ( & V_70 ) ;
V_68 = F_24 ( type ) ;
if ( ! V_68 )
V_68 = F_8 ( type , & V_66 . V_67 [ F_1 ( type ) ] ) ;
if ( V_68 ) {
F_34 ( & V_68 -> V_24 ) ;
F_21 ( V_68 , V_36 ) ;
F_36 ( & V_68 -> V_24 ) ;
} else {
F_4 ( L_13 ,
V_36 -> V_68 . type , V_36 -> V_68 . V_4 , V_36 -> V_68 . V_5 ) ;
}
F_48 ( & V_70 ) ;
}
void F_53 ( struct V_35 * V_36 )
{
struct V_20 * V_68 ;
F_46 ( & V_70 ) ;
V_68 = F_24 ( V_36 -> V_68 . type ) ;
if ( V_68 != NULL ) {
F_34 ( & V_68 -> V_24 ) ;
F_51 ( & V_36 -> V_59 ) ;
F_36 ( & V_68 -> V_24 ) ;
if ( ( V_68 -> V_32 == 0 ) && F_28 ( & V_68 -> V_28 ) ) {
F_29 ( & V_68 -> V_27 ) ;
F_9 ( V_68 -> V_25 ) ;
F_9 ( V_68 ) ;
}
}
F_48 ( & V_70 ) ;
}
static void F_54 ( struct V_17 * V_19 , struct V_84 * V_85 , T_1 V_86 ,
T_1 V_87 )
{
char V_88 [ 27 ] ;
const char * V_89 [] = { L_14 , L_15 , L_16 , L_17 } ;
struct V_3 * V_10 = V_19 -> V_42 ;
F_55 ( V_85 , L_18 , V_19 -> V_4 , V_19 -> V_5 ) ;
if ( V_86 == 2 || ! V_10 ) {
F_55 ( V_85 , L_19 ) ;
return;
}
do {
sprintf ( V_88 , L_20 ,
F_56 ( V_10 -> V_7 ) , F_57 ( V_10 -> V_7 ) ,
F_58 ( V_10 -> V_7 ) , V_10 -> V_12 ) ;
F_55 ( V_85 , L_21 , V_88 ) ;
if ( V_86 > 3 ) {
F_55 ( V_85 , L_22 , V_10 -> V_9 ,
V_89 [ V_10 -> V_6 ] ) ;
}
V_10 = V_10 -> V_43 ;
if ( V_10 == V_19 -> V_42 )
break;
F_55 ( V_85 , L_23 , L_24 ) ;
} while ( 1 );
F_55 ( V_85 , L_19 ) ;
}
static void V_59 ( struct V_20 * V_68 , struct V_84 * V_85 , T_1 V_86 ,
T_1 type , T_1 V_90 , T_1 V_91 , T_1 V_87 )
{
struct V_17 * V_19 ;
char V_92 [ 11 ] ;
if ( V_68 -> V_32 == 0 )
return;
sprintf ( V_92 , L_25 , V_68 -> type ) ;
if ( V_86 == 1 ) {
F_55 ( V_85 , L_26 , V_92 ) ;
return;
}
for ( V_19 = V_68 -> V_25 ; V_19 != & V_68 -> V_25 [ V_68 -> V_32 ] ; V_19 ++ ) {
if ( ( V_90 <= V_19 -> V_5 ) && ( V_91 >= V_19 -> V_4 ) ) {
F_55 ( V_85 , L_27 , V_92 ) ;
F_34 ( & V_68 -> V_24 ) ;
F_54 ( V_19 , V_85 , V_86 , V_87 ) ;
F_36 ( & V_68 -> V_24 ) ;
sprintf ( V_92 , L_28 , L_24 ) ;
}
}
}
static void F_59 ( struct V_84 * V_85 , T_1 V_86 )
{
const char * V_93 [] = {
L_29 ,
L_30 ,
L_31 ,
L_32
} ;
int V_94 ;
if ( V_86 > 4 )
V_86 = 4 ;
for ( V_94 = 0 ; V_94 < V_86 ; V_94 ++ )
F_55 ( V_85 , V_93 [ V_94 ] ) ;
F_55 ( V_85 , L_19 ) ;
}
static void F_60 ( struct V_84 * V_85 , T_1 V_95 ,
T_1 type , T_1 V_90 , T_1 V_91 )
{
struct V_21 * V_22 ;
struct V_63 * V_64 ;
struct V_20 * V_68 ;
int V_96 ;
T_1 V_86 ;
T_1 V_94 ;
V_96 = ( V_95 & V_97 ) ;
V_86 = ( V_95 & ~ V_97 ) ;
if ( V_86 == 0 )
return;
if ( V_96 ) {
F_59 ( V_85 , V_86 ) ;
V_90 = 0 ;
V_91 = ~ 0 ;
for ( V_94 = 0 ; V_94 < V_2 ; V_94 ++ ) {
V_22 = & V_66 . V_67 [ V_94 ] ;
F_25 (seq, seq_node, seq_head, ns_list) {
V_59 ( V_68 , V_85 , V_86 , V_68 -> type ,
V_90 , V_91 , V_94 ) ;
}
}
} else {
if ( V_91 < V_90 ) {
F_55 ( V_85 , L_33 ) ;
return;
}
F_59 ( V_85 , V_86 ) ;
V_94 = F_1 ( type ) ;
V_22 = & V_66 . V_67 [ V_94 ] ;
F_25 (seq, seq_node, seq_head, ns_list) {
if ( V_68 -> type == type ) {
V_59 ( V_68 , V_85 , V_86 , type ,
V_90 , V_91 , V_94 ) ;
break;
}
}
}
}
struct V_98 * F_61 ( const void * V_99 , int V_100 )
{
struct V_98 * V_85 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_84 V_105 ;
int V_106 ;
if ( ! F_62 ( V_99 , V_100 , V_107 ) )
return F_63 ( V_108 ) ;
V_85 = F_64 ( F_65 ( V_109 ) ) ;
if ( ! V_85 )
return NULL ;
V_104 = (struct V_103 * ) V_85 -> V_110 ;
F_66 ( & V_105 , F_67 ( V_104 ) , V_109 ) ;
V_102 = (struct V_101 * ) F_67 ( V_99 ) ;
F_32 ( & V_70 ) ;
F_60 ( & V_105 , F_68 ( V_102 -> V_86 ) , F_68 ( V_102 -> type ) ,
F_68 ( V_102 -> V_90 ) , F_68 ( V_102 -> V_91 ) ) ;
F_37 ( & V_70 ) ;
V_106 = F_69 ( & V_105 ) ;
F_70 ( V_85 , F_65 ( V_106 ) ) ;
F_71 ( V_104 , V_111 , NULL , V_106 ) ;
return V_85 ;
}
int F_72 ( void )
{
V_66 . V_67 = F_7 ( V_2 , sizeof( struct V_21 ) ,
V_11 ) ;
if ( ! V_66 . V_67 )
return - V_112 ;
V_66 . V_80 = 0 ;
return 0 ;
}
void F_73 ( void )
{
T_1 V_94 ;
if ( ! V_66 . V_67 )
return;
F_46 ( & V_70 ) ;
for ( V_94 = 0 ; V_94 < V_2 ; V_94 ++ ) {
if ( ! F_74 ( & V_66 . V_67 [ V_94 ] ) )
F_20 ( L_34 , V_94 ) ;
}
F_9 ( V_66 . V_67 ) ;
V_66 . V_67 = NULL ;
F_48 ( & V_70 ) ;
}
