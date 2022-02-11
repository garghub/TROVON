static int F_1 ( const struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 ;
if ( ( V_3 & V_5 ) == V_6 )
return V_7 ;
else if ( ( V_3 & V_5 ) == V_8 && F_2 ( V_3 ) )
return V_9 ;
else
return V_10 ;
}
static int F_3 ( struct V_11 * V_12 ,
unsigned int V_13 , T_1 V_14 )
{
T_1 V_15 ;
if ( ! V_12 -> V_16 [ V_13 ] . V_17 )
return V_18 ;
V_15 = V_12 -> V_16 [ V_13 ] . V_19 ;
if ( V_15 >= 2 * V_14 )
return V_20 ;
else if ( V_15 > V_14 )
return V_21 ;
else if ( V_15 <= V_14 / 2 )
return V_22 ;
else
return V_23 ;
}
static void F_4 ( struct V_24 * V_25 ,
unsigned int V_13 , int V_26 ,
int V_27 )
{
unsigned int V_28 , V_29 ;
if ( V_26 == V_18 ||
( F_5 ( V_26 ) && F_5 ( V_27 ) ) ||
( F_6 ( V_26 ) && F_6 ( V_27 ) ) )
return;
V_28 = V_29 = V_25 -> V_30 [ V_13 ] . V_31 . V_29 ;
if ( V_27 == V_18 ) {
V_29 ++ ;
} else {
switch ( V_26 ) {
case V_23 :
if ( V_27 == V_20 )
V_29 -= F_7 ( V_29 / 4 , 1U ) ;
else
V_29 -= F_7 ( V_29 / 8 , 1U ) ;
break;
case V_22 :
if ( V_27 == V_20 )
V_29 /= 2 ;
else
V_29 -= F_7 ( V_29 / 4 , 1U ) ;
break;
case V_21 :
V_29 ++ ;
break;
case V_20 :
if ( V_27 == V_22 )
V_29 += 2 ;
else
V_29 ++ ;
break;
}
}
V_29 = F_8 ( V_29 , 1U , V_32 [ V_13 ] ) ;
if ( V_29 != V_28 )
F_9 ( & V_25 -> V_30 [ V_13 ] , V_29 ) ;
}
static void F_10 ( struct V_24 * V_25 ,
int V_33 , int V_34 ,
bool V_35 )
{
unsigned int V_28 , V_29 ;
int V_36 ;
V_28 = V_29 = V_25 -> V_30 [ V_10 ] . V_31 . V_29 ;
if ( V_33 == V_18 && V_34 == V_18 ) {
V_29 += 2 ;
} else if ( V_35 ) {
if ( V_33 == V_18 )
V_36 = V_34 ;
else if ( V_34 == V_18 )
V_36 = V_33 ;
else
V_36 = F_7 ( V_33 , V_34 ) ;
switch ( V_36 ) {
case V_22 :
V_29 += 2 ;
break;
case V_23 :
V_29 ++ ;
break;
case V_21 :
V_29 -= F_7 ( V_29 / 4 , 1U ) ;
break;
case V_20 :
V_29 /= 2 ;
break;
}
}
V_29 = F_8 ( V_29 , 1U , V_32 [ V_10 ] ) ;
if ( V_29 != V_28 )
F_9 ( & V_25 -> V_30 [ V_10 ] , V_29 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_24 * V_25 = V_12 -> V_37 ;
int V_33 , V_34 ;
V_33 = F_3 ( V_12 , V_7 , V_25 -> V_38 ) ;
V_34 = F_3 ( V_12 , V_9 , V_25 -> V_39 ) ;
F_4 ( V_25 , V_7 , V_33 , V_34 ) ;
F_4 ( V_25 , V_9 , V_34 , V_33 ) ;
F_10 ( V_25 , V_33 , V_34 ,
V_12 -> V_16 [ V_10 ] . V_17 != 0 ) ;
if ( ! F_12 ( V_25 -> V_12 ) &&
( ( F_6 ( V_33 ) || F_6 ( V_34 ) ||
V_25 -> V_30 [ V_10 ] . V_31 . V_29 < V_32 [ V_10 ] ) ) )
F_13 ( V_25 -> V_12 , 100 ) ;
}
static unsigned int F_14 ( struct V_24 * V_25 )
{
return V_25 -> V_40 -> V_41 [ 0 ] -> V_42 -> V_43 . V_31 . V_44 ;
}
static struct V_24 * F_15 ( struct V_45 * V_40 )
{
struct V_24 * V_25 ;
unsigned int V_46 ;
unsigned int V_44 ;
int V_47 = - V_48 ;
int V_49 ;
V_25 = F_16 ( sizeof( * V_25 ) , V_50 , V_40 -> V_51 ) ;
if ( ! V_25 )
goto V_52;
V_25 -> V_40 = V_40 ;
V_25 -> V_12 = F_17 ( F_11 , F_1 ,
V_53 , V_25 ) ;
if ( ! V_25 -> V_12 )
goto V_54;
V_46 = F_18 (unsigned int, q->tag_set->queue_depth,
KYBER_MIN_DEPTH) ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
F_19 ( ! V_32 [ V_49 ] ) ;
F_19 ( ! V_55 [ V_49 ] ) ;
V_47 = F_20 ( & V_25 -> V_30 [ V_49 ] ,
V_46 , - 1 , false , V_50 ,
V_40 -> V_51 ) ;
if ( V_47 ) {
while ( -- V_49 >= 0 )
F_21 ( & V_25 -> V_30 [ V_49 ] ) ;
goto V_56;
}
F_9 ( & V_25 -> V_30 [ V_49 ] , V_32 [ V_49 ] ) ;
}
V_44 = F_14 ( V_25 ) ;
V_25 -> V_57 = ( 1U << V_44 ) * V_58 / 100U ;
V_25 -> V_38 = 2000000ULL ;
V_25 -> V_39 = 10000000ULL ;
return V_25 ;
V_56:
F_22 ( V_25 -> V_12 ) ;
V_54:
F_23 ( V_25 ) ;
V_52:
return F_24 ( V_47 ) ;
}
static int F_25 ( struct V_45 * V_40 , struct V_59 * V_60 )
{
struct V_24 * V_25 ;
struct V_61 * V_62 ;
V_62 = F_26 ( V_40 , V_60 ) ;
if ( ! V_62 )
return - V_48 ;
V_25 = F_15 ( V_40 ) ;
if ( F_27 ( V_25 ) ) {
F_28 ( & V_62 -> V_63 ) ;
return F_29 ( V_25 ) ;
}
V_62 -> V_64 = V_25 ;
V_40 -> V_65 = V_62 ;
F_30 ( V_40 , V_25 -> V_12 ) ;
return 0 ;
}
static void F_31 ( struct V_61 * V_60 )
{
struct V_24 * V_25 = V_60 -> V_64 ;
struct V_45 * V_40 = V_25 -> V_40 ;
int V_49 ;
F_32 ( V_40 , V_25 -> V_12 ) ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ )
F_21 ( & V_25 -> V_30 [ V_49 ] ) ;
F_22 ( V_25 -> V_12 ) ;
F_23 ( V_25 ) ;
}
static int F_33 ( struct V_66 * V_67 , unsigned int V_68 )
{
struct V_69 * V_70 ;
int V_49 ;
V_70 = F_16 ( sizeof( * V_70 ) , V_50 , V_67 -> V_71 ) ;
if ( ! V_70 )
return - V_48 ;
F_34 ( & V_70 -> V_72 ) ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
F_35 ( & V_70 -> V_73 [ V_49 ] ) ;
F_35 ( & V_70 -> V_74 [ V_49 ] . V_75 ) ;
F_36 ( & V_70 -> V_76 [ V_49 ] , 0 ) ;
}
V_70 -> V_77 = 0 ;
V_70 -> V_78 = 0 ;
V_67 -> V_79 = V_70 ;
return 0 ;
}
static void F_37 ( struct V_66 * V_67 , unsigned int V_68 )
{
F_23 ( V_67 -> V_79 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
return ( long ) V_2 -> V_80 . V_81 [ 0 ] ;
}
static void F_39 ( struct V_1 * V_2 , int V_82 )
{
V_2 -> V_80 . V_81 [ 0 ] = ( void * ) ( long ) V_82 ;
}
static void F_40 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
unsigned int V_13 ;
int V_83 ;
V_83 = F_38 ( V_2 ) ;
if ( V_83 != - 1 ) {
V_13 = F_1 ( V_2 ) ;
F_41 ( & V_25 -> V_30 [ V_13 ] , V_83 ,
V_2 -> V_84 -> V_85 ) ;
}
}
static void F_42 ( unsigned int V_3 , struct V_86 * V_37 )
{
if ( ! F_2 ( V_3 ) ) {
struct V_24 * V_25 = V_37 -> V_40 -> V_65 -> V_64 ;
V_37 -> V_87 = V_25 -> V_57 ;
}
}
static void F_43 ( struct V_1 * V_2 , struct V_88 * V_88 )
{
F_39 ( V_2 , - 1 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_40 -> V_65 -> V_64 ;
F_40 ( V_25 , V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_45 * V_40 = V_2 -> V_40 ;
struct V_24 * V_25 = V_40 -> V_65 -> V_64 ;
unsigned int V_13 ;
T_1 V_89 , V_15 , V_14 ;
V_13 = F_1 ( V_2 ) ;
switch ( V_13 ) {
case V_7 :
V_14 = V_25 -> V_38 ;
break;
case V_9 :
V_14 = V_25 -> V_39 ;
break;
default:
return;
}
if ( F_12 ( V_25 -> V_12 ) )
return;
V_89 = F_46 ( F_47 ( F_48 () ) ) ;
if ( V_89 < F_49 ( & V_2 -> V_90 ) )
return;
V_15 = V_89 - F_49 ( & V_2 -> V_90 ) ;
if ( V_15 > V_14 )
F_13 ( V_25 -> V_12 , 10 ) ;
}
static void F_50 ( struct V_69 * V_70 ,
struct V_66 * V_67 )
{
F_51 ( V_91 ) ;
struct V_1 * V_2 , * V_92 ;
F_52 ( V_67 , & V_91 ) ;
F_53 (rq, next, &rq_list, queuelist) {
unsigned int V_13 ;
V_13 = F_1 ( V_2 ) ;
F_54 ( & V_2 -> V_93 , & V_70 -> V_73 [ V_13 ] ) ;
}
}
static int F_55 ( T_2 * V_94 , unsigned V_95 , int V_96 ,
void * V_97 )
{
struct V_66 * V_67 = F_56 ( V_94 -> V_98 ) ;
F_57 ( & V_94 -> V_75 ) ;
F_58 ( V_67 , true ) ;
return 1 ;
}
static int F_59 ( struct V_24 * V_25 ,
struct V_69 * V_70 ,
struct V_66 * V_67 )
{
unsigned int V_13 = V_70 -> V_77 ;
struct V_99 * V_30 = & V_25 -> V_30 [ V_13 ] ;
T_2 * V_94 = & V_70 -> V_74 [ V_13 ] ;
struct V_100 * V_101 ;
int V_83 ;
V_83 = F_60 ( V_30 ) ;
if ( V_83 >= 0 )
return V_83 ;
if ( F_61 ( & V_94 -> V_75 ) ) {
F_62 ( V_94 , F_55 ) ;
V_94 -> V_98 = V_67 ;
V_101 = F_63 ( V_30 ,
& V_70 -> V_76 [ V_13 ] ) ;
F_64 ( & V_101 -> V_94 , V_94 ) ;
V_83 = F_60 ( V_30 ) ;
}
return V_83 ;
}
static struct V_1 *
F_65 ( struct V_24 * V_25 ,
struct V_69 * V_70 ,
struct V_66 * V_67 ,
bool * V_102 )
{
struct V_103 * V_73 ;
struct V_1 * V_2 ;
int V_83 ;
V_73 = & V_70 -> V_73 [ V_70 -> V_77 ] ;
V_2 = F_66 ( V_73 , struct V_1 , V_93 ) ;
if ( ! V_2 && ! * V_102 ) {
F_50 ( V_70 , V_67 ) ;
* V_102 = true ;
V_2 = F_66 ( V_73 , struct V_1 , V_93 ) ;
}
if ( V_2 ) {
V_83 = F_59 ( V_25 , V_70 , V_67 ) ;
if ( V_83 >= 0 ) {
V_70 -> V_78 ++ ;
F_39 ( V_2 , V_83 ) ;
F_57 ( & V_2 -> V_93 ) ;
return V_2 ;
}
}
return NULL ;
}
static struct V_1 * F_67 ( struct V_66 * V_67 )
{
struct V_24 * V_25 = V_67 -> V_104 -> V_65 -> V_64 ;
struct V_69 * V_70 = V_67 -> V_79 ;
bool V_102 = false ;
struct V_1 * V_2 ;
int V_49 ;
F_68 ( & V_70 -> V_72 ) ;
if ( V_70 -> V_78 < V_55 [ V_70 -> V_77 ] ) {
V_2 = F_65 ( V_25 , V_70 , V_67 , & V_102 ) ;
if ( V_2 )
goto V_105;
}
V_70 -> V_78 = 0 ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
if ( V_70 -> V_77 == V_53 - 1 )
V_70 -> V_77 = 0 ;
else
V_70 -> V_77 ++ ;
V_2 = F_65 ( V_25 , V_70 , V_67 , & V_102 ) ;
if ( V_2 )
goto V_105;
}
V_2 = NULL ;
V_105:
F_69 ( & V_70 -> V_72 ) ;
return V_2 ;
}
static bool F_70 ( struct V_66 * V_67 )
{
struct V_69 * V_70 = V_67 -> V_79 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
if ( ! F_61 ( & V_70 -> V_73 [ V_49 ] ) )
return true ;
}
return false ;
}
static int F_71 ( void * V_37 , struct V_106 * V_107 )
{
struct V_45 * V_40 = V_37 ;
struct V_24 * V_25 = V_40 -> V_65 -> V_64 ;
F_72 ( V_107 , L_1 , V_25 -> V_57 ) ;
return 0 ;
}
static int F_73 ( void * V_37 , struct V_106 * V_107 )
{
struct V_66 * V_67 = V_37 ;
struct V_69 * V_70 = V_67 -> V_79 ;
switch ( V_70 -> V_77 ) {
case V_7 :
F_74 ( V_107 , L_2 ) ;
break;
case V_9 :
F_74 ( V_107 , L_3 ) ;
break;
case V_10 :
F_74 ( V_107 , L_4 ) ;
break;
default:
F_72 ( V_107 , L_1 , V_70 -> V_77 ) ;
break;
}
return 0 ;
}
static int F_75 ( void * V_37 , struct V_106 * V_107 )
{
struct V_66 * V_67 = V_37 ;
struct V_69 * V_70 = V_67 -> V_79 ;
F_72 ( V_107 , L_1 , V_70 -> V_78 ) ;
return 0 ;
}
static int T_3 F_76 ( void )
{
return F_77 ( & V_108 ) ;
}
static void T_4 F_78 ( void )
{
F_79 ( & V_108 ) ;
}
