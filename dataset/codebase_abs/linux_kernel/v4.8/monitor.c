static struct V_1 * V_1 ( struct V_2 * V_2 , int V_3 )
{
return F_1 ( V_2 ) -> V_4 [ V_3 ] ;
}
static int F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
return ( ( void * ) & V_6 -> V_8 - ( void * ) V_6 ) + ( V_7 * sizeof( V_9 ) ) ;
}
static int F_3 ( int V_10 )
{
int V_11 = 0 ;
while ( ( V_11 * V_11 ) < V_10 )
V_11 ++ ;
return V_11 < V_12 ? V_11 : V_12 ;
}
static void F_4 ( T_2 * V_13 , int V_11 , unsigned int V_14 )
{
* V_13 &= ~ ( 1ULL << V_11 ) ;
* V_13 |= ( ( T_2 ) V_14 << V_11 ) ;
}
static int F_5 ( T_2 V_13 , int V_11 )
{
return ( V_13 & ( 1 << V_11 ) ) >> V_11 ;
}
static struct V_15 * F_6 ( struct V_15 * V_16 )
{
return F_7 ( & V_16 -> V_17 , struct V_15 , V_17 ) ;
}
static struct V_15 * F_8 ( struct V_15 * V_16 )
{
return F_9 ( & V_16 -> V_17 , struct V_15 , V_17 ) ;
}
static struct V_15 * F_10 ( struct V_15 * V_16 )
{
while ( ! V_16 -> V_18 )
V_16 = F_6 ( V_16 ) ;
return V_16 ;
}
static struct V_15 * F_11 ( struct V_1 * V_19 , V_9 V_20 )
{
struct V_15 * V_16 ;
unsigned int V_21 = F_12 ( V_20 ) ;
F_13 (peer, &mon->peers[thash], hash) {
if ( V_16 -> V_20 == V_20 )
return V_16 ;
}
return NULL ;
}
static struct V_15 * F_14 ( struct V_2 * V_2 , int V_3 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
return V_19 -> V_22 ;
}
static inline bool F_15 ( struct V_2 * V_2 , struct V_1 * V_19 )
{
struct F_1 * V_23 = F_1 ( V_2 ) ;
return V_19 -> V_24 > V_23 -> V_25 ;
}
static void F_16 ( struct V_15 * V_16 ,
struct V_5 * V_26 ,
int V_27 )
{
struct V_15 * V_28 = V_16 ;
struct V_5 * V_29 = V_16 -> V_30 ;
int V_31 = V_16 -> V_32 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
V_28 = F_8 ( V_28 ) ;
if ( ! V_28 -> V_33 || ! F_5 ( V_26 -> V_13 , V_11 ) )
continue;
if ( V_28 -> V_34 )
continue;
if ( ! V_31 || ( V_31 < V_11 ) ) {
V_28 -> V_35 = 1 ;
continue;
}
if ( ! F_5 ( V_29 -> V_13 , V_11 ) )
V_28 -> V_35 ++ ;
}
}
static void F_17 ( struct V_1 * V_19 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = V_16 -> V_30 ;
struct V_15 * V_28 ;
V_9 V_20 ;
int V_11 ;
if ( ! V_6 || ! V_16 -> V_33 )
return;
V_16 -> V_32 = 0 ;
V_28 = F_8 ( V_16 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_36 ; V_11 ++ ) {
V_20 = V_6 -> V_8 [ V_11 ] ;
if ( V_20 != V_28 -> V_20 )
return;
V_16 -> V_32 ++ ;
V_28 = F_8 ( V_28 ) ;
}
}
static void F_18 ( struct V_1 * V_19 )
{
struct V_15 * V_22 = V_19 -> V_22 ;
struct V_5 * V_37 = & V_19 -> V_37 ;
struct V_5 * V_6 = V_22 -> V_30 ;
struct V_15 * V_16 = V_22 ;
T_2 V_38 = V_6 -> V_13 ;
T_1 V_36 , V_11 ;
bool V_39 ;
V_36 = F_3 ( V_19 -> V_24 ) - 1 ;
V_22 -> V_32 = V_36 ;
V_6 -> V_40 = F_2 ( V_6 , V_36 ) ;
V_39 = V_6 -> V_36 != V_36 ;
V_6 -> V_36 = V_36 ;
for ( V_11 = 0 ; V_11 < V_36 ; V_11 ++ ) {
V_16 = F_8 ( V_16 ) ;
V_39 |= V_6 -> V_8 [ V_11 ] != V_16 -> V_20 ;
V_6 -> V_8 [ V_11 ] = V_16 -> V_20 ;
F_4 ( & V_6 -> V_13 , V_11 , V_16 -> V_33 ) ;
V_37 -> V_8 [ V_11 ] = F_19 ( V_16 -> V_20 ) ;
}
V_39 |= V_6 -> V_13 != V_38 ;
if ( ! V_39 )
return;
V_6 -> V_41 = ++ V_19 -> V_42 ;
V_37 -> V_40 = F_20 ( V_6 -> V_40 ) ;
V_37 -> V_41 = F_20 ( V_6 -> V_41 ) ;
V_37 -> V_36 = F_20 ( V_36 ) ;
V_37 -> V_13 = F_21 ( V_6 -> V_13 ) ;
F_17 ( V_19 , V_22 ) ;
}
static void F_22 ( struct V_1 * V_19 ,
struct V_15 * V_16 )
{
int V_43 , V_11 ;
V_43 = F_3 ( V_19 -> V_24 ) ;
for ( V_11 = 0 ; V_11 < V_43 ; V_11 ++ ) {
F_17 ( V_19 , V_16 ) ;
V_16 = F_6 ( V_16 ) ;
}
}
static void F_23 ( struct V_1 * V_19 , struct V_15 * V_44 )
{
struct V_15 * V_16 = F_8 ( V_44 ) ;
struct V_15 * V_22 = V_19 -> V_22 ;
int V_11 = 0 ;
for (; V_16 != V_22 ; V_16 = F_8 ( V_16 ) ) {
V_16 -> V_34 = false ;
if ( V_11 ++ < V_44 -> V_32 ) {
V_16 -> V_18 = false ;
if ( V_44 == V_22 )
V_16 -> V_34 = true ;
continue;
}
if ( ! V_16 -> V_33 )
continue;
if ( V_16 -> V_18 )
break;
V_44 = V_16 ;
V_44 -> V_18 = true ;
V_11 = 0 ;
}
V_19 -> V_45 ++ ;
}
void F_24 ( struct V_2 * V_2 , V_9 V_20 , int V_3 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
struct V_15 * V_22 = F_14 ( V_2 , V_3 ) ;
struct V_15 * V_16 , * V_46 , * V_44 ;
F_25 ( & V_19 -> V_47 ) ;
V_16 = F_11 ( V_19 , V_20 ) ;
if ( ! V_16 )
goto exit;
V_46 = F_6 ( V_16 ) ;
F_26 ( & V_16 -> V_17 ) ;
F_27 ( & V_16 -> V_48 ) ;
F_28 ( V_16 -> V_30 ) ;
F_28 ( V_16 ) ;
V_19 -> V_24 -- ;
V_44 = F_10 ( V_46 ) ;
if ( V_44 == V_22 )
F_18 ( V_19 ) ;
F_22 ( V_19 , V_46 ) ;
if ( ! F_15 ( V_2 , V_19 ) ) {
F_29 (peer, &self->list, list) {
F_28 ( V_16 -> V_30 ) ;
V_16 -> V_30 = NULL ;
V_16 -> V_32 = 0 ;
}
}
F_23 ( V_19 , V_44 ) ;
exit:
F_30 ( & V_19 -> V_47 ) ;
}
static bool F_31 ( struct V_1 * V_19 , V_9 V_20 ,
struct V_15 * * V_16 )
{
struct V_15 * V_22 = V_19 -> V_22 ;
struct V_15 * V_49 , * V_46 , * V_50 ;
V_50 = F_32 ( sizeof( * V_50 ) , V_51 ) ;
* V_16 = V_50 ;
if ( ! V_50 )
return false ;
V_50 -> V_20 = V_20 ;
F_33 ( & V_50 -> V_17 ) ;
F_34 ( & V_50 -> V_48 , & V_19 -> V_10 [ F_12 ( V_20 ) ] ) ;
V_46 = V_22 ;
F_29 (cur, &self->list, list) {
if ( ( V_20 > V_46 -> V_20 ) && ( V_20 < V_49 -> V_20 ) )
break;
if ( ( ( V_20 < V_49 -> V_20 ) || ( V_20 > V_46 -> V_20 ) ) &&
( V_46 -> V_20 > V_49 -> V_20 ) )
break;
V_46 = V_49 ;
}
F_35 ( & V_50 -> V_17 , & V_49 -> V_17 ) ;
V_19 -> V_24 ++ ;
F_22 ( V_19 , V_50 ) ;
return true ;
}
void F_36 ( struct V_2 * V_2 , V_9 V_20 , int V_3 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
struct V_15 * V_22 = F_14 ( V_2 , V_3 ) ;
struct V_15 * V_16 , * V_44 ;
F_25 ( & V_19 -> V_47 ) ;
V_16 = F_11 ( V_19 , V_20 ) ;
if ( ! V_16 && ! F_31 ( V_19 , V_20 , & V_16 ) )
goto exit;
V_16 -> V_33 = true ;
V_44 = F_10 ( V_16 ) ;
if ( V_44 == V_22 )
F_18 ( V_19 ) ;
F_23 ( V_19 , V_44 ) ;
exit:
F_30 ( & V_19 -> V_47 ) ;
}
void F_37 ( struct V_2 * V_2 , V_9 V_20 , int V_3 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
struct V_15 * V_22 = F_14 ( V_2 , V_3 ) ;
struct V_15 * V_16 , * V_44 ;
struct V_5 * V_6 ;
int V_32 ;
F_25 ( & V_19 -> V_47 ) ;
V_16 = F_11 ( V_19 , V_20 ) ;
if ( ! V_16 ) {
F_38 ( L_1 , V_20 , V_3 ) ;
goto exit;
}
V_32 = V_16 -> V_32 ;
V_16 -> V_32 = 0 ;
V_6 = V_16 -> V_30 ;
V_16 -> V_30 = NULL ;
if ( V_16 -> V_18 )
F_16 ( V_16 , V_6 , V_32 ) ;
F_28 ( V_6 ) ;
V_16 -> V_33 = false ;
V_16 -> V_18 = false ;
V_16 -> V_34 = false ;
V_16 -> V_35 = 0 ;
V_44 = F_10 ( V_16 ) ;
if ( V_44 == V_22 )
F_18 ( V_19 ) ;
F_23 ( V_19 , V_44 ) ;
exit:
F_30 ( & V_19 -> V_47 ) ;
}
void F_39 ( struct V_2 * V_2 , void * V_52 , T_1 V_53 , V_9 V_20 ,
struct V_54 * V_55 , int V_3 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
struct V_5 * V_56 = V_52 ;
struct V_5 V_26 ;
struct V_5 * V_6 ;
struct V_15 * V_16 ;
T_1 V_57 = F_40 ( V_56 -> V_36 ) ;
int V_58 = F_2 ( V_56 , V_57 ) ;
T_1 V_59 = F_40 ( V_56 -> V_41 ) ;
T_1 V_60 = F_40 ( V_56 -> V_61 ) ;
bool V_62 = V_55 -> V_62 ;
int V_11 , V_27 ;
V_55 -> V_62 = false ;
if ( ! V_53 )
return;
if ( ( V_53 < V_58 ) || F_40 ( V_56 -> V_40 ) != V_58 ) {
F_41 ( L_2 ) ;
return;
}
if ( ! V_55 -> V_63 ) {
V_55 -> V_64 = V_59 - 1 ;
V_55 -> V_60 = V_60 ;
V_55 -> V_63 = true ;
}
if ( F_42 ( V_60 , V_55 -> V_60 ) )
V_55 -> V_60 = V_60 ;
if ( ! F_42 ( V_59 , V_55 -> V_64 ) && ! V_62 )
return;
F_25 ( & V_19 -> V_47 ) ;
V_16 = F_11 ( V_19 , V_20 ) ;
if ( ! V_16 || ! V_16 -> V_33 )
goto exit;
V_16 -> V_35 = 0 ;
if ( ! F_42 ( V_59 , V_55 -> V_64 ) )
goto exit;
V_55 -> V_64 = V_59 ;
V_26 . V_36 = 0 ;
V_6 = V_16 -> V_30 ;
if ( V_6 )
memcpy ( & V_26 , V_6 , V_6 -> V_40 ) ;
if ( ! V_6 || ( V_6 -> V_40 < V_58 ) ) {
F_28 ( V_6 ) ;
V_6 = F_43 ( V_58 , V_51 ) ;
V_16 -> V_30 = V_6 ;
if ( ! V_6 )
goto exit;
}
V_6 -> V_40 = V_58 ;
V_6 -> V_41 = V_59 ;
V_6 -> V_36 = V_57 ;
V_6 -> V_13 = F_44 ( V_56 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_57 ; V_11 ++ )
V_6 -> V_8 [ V_11 ] = F_45 ( V_56 -> V_8 [ V_11 ] ) ;
V_27 = V_16 -> V_32 ;
F_17 ( V_19 , V_16 ) ;
F_16 ( V_16 , & V_26 , V_27 ) ;
F_23 ( V_19 , F_10 ( V_16 ) ) ;
exit:
F_30 ( & V_19 -> V_47 ) ;
}
void F_46 ( struct V_2 * V_2 , void * V_52 , int * V_53 ,
struct V_54 * V_55 , int V_3 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
struct V_5 * V_6 = V_52 ;
T_1 V_41 = V_19 -> V_42 ;
T_1 V_40 ;
if ( ! F_15 ( V_2 , V_19 ) )
return;
if ( F_47 ( V_55 -> V_60 == V_41 ) ) {
V_40 = F_2 ( V_6 , 0 ) ;
* V_53 = V_40 ;
V_6 -> V_40 = F_20 ( V_40 ) ;
V_6 -> V_41 = F_20 ( V_41 ) ;
V_6 -> V_61 = F_20 ( V_55 -> V_64 ) ;
V_6 -> V_36 = 0 ;
return;
}
F_48 ( & V_19 -> V_47 ) ;
V_40 = F_40 ( V_19 -> V_37 . V_40 ) ;
* V_53 = V_40 ;
memcpy ( V_52 , & V_19 -> V_37 , V_40 ) ;
F_49 ( & V_19 -> V_47 ) ;
V_6 -> V_61 = F_20 ( V_55 -> V_64 ) ;
}
void F_50 ( struct V_2 * V_2 , V_9 V_20 ,
struct V_54 * V_55 ,
int V_3 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
struct V_15 * V_16 ;
if ( ! V_55 -> V_62 &&
( V_55 -> V_45 == V_19 -> V_45 ) &&
( V_55 -> V_60 == V_19 -> V_42 ) )
return;
F_48 ( & V_19 -> V_47 ) ;
V_16 = F_11 ( V_19 , V_20 ) ;
if ( V_16 ) {
V_55 -> V_62 = V_55 -> V_60 != V_19 -> V_42 ;
V_55 -> V_62 |= V_16 -> V_35 ;
V_55 -> V_65 |= V_16 -> V_35 >= V_66 ;
V_55 -> V_67 = V_16 -> V_34 ;
V_55 -> V_67 |= V_16 -> V_18 ;
V_55 -> V_45 = V_19 -> V_45 ;
}
F_49 ( & V_19 -> V_47 ) ;
}
static void F_51 ( unsigned long V_68 )
{
struct V_1 * V_19 = ( void * ) V_68 ;
struct V_15 * V_22 ;
int V_69 = F_3 ( V_19 -> V_24 ) - 1 ;
F_25 ( & V_19 -> V_47 ) ;
V_22 = V_19 -> V_22 ;
if ( V_22 && ( V_69 != V_22 -> V_32 ) ) {
F_18 ( V_19 ) ;
F_23 ( V_19 , V_22 ) ;
}
F_30 ( & V_19 -> V_47 ) ;
F_52 ( & V_19 -> V_70 , V_71 + V_19 -> V_72 ) ;
}
int F_53 ( struct V_2 * V_2 , int V_3 )
{
struct F_1 * V_23 = F_1 ( V_2 ) ;
struct V_1 * V_19 ;
struct V_15 * V_22 ;
struct V_5 * V_6 ;
if ( V_23 -> V_4 [ V_3 ] )
return 0 ;
V_19 = F_32 ( sizeof( * V_19 ) , V_51 ) ;
V_22 = F_32 ( sizeof( * V_22 ) , V_51 ) ;
V_6 = F_32 ( sizeof( * V_6 ) , V_51 ) ;
if ( ! V_19 || ! V_22 || ! V_6 ) {
F_28 ( V_19 ) ;
F_28 ( V_22 ) ;
F_28 ( V_6 ) ;
return - V_73 ;
}
V_23 -> V_4 [ V_3 ] = V_19 ;
F_54 ( & V_19 -> V_47 ) ;
V_19 -> V_2 = V_2 ;
V_19 -> V_24 = 1 ;
V_19 -> V_22 = V_22 ;
V_22 -> V_30 = V_6 ;
V_22 -> V_20 = F_55 ( V_2 ) ;
V_22 -> V_33 = true ;
V_22 -> V_18 = true ;
F_33 ( & V_22 -> V_17 ) ;
F_56 ( & V_19 -> V_70 , F_51 , ( unsigned long ) V_19 ) ;
V_19 -> V_72 = F_57 ( V_74 + ( V_23 -> V_75 & 0xffff ) ) ;
F_52 ( & V_19 -> V_70 , V_71 + V_19 -> V_72 ) ;
return 0 ;
}
void F_58 ( struct V_2 * V_2 , int V_3 )
{
struct F_1 * V_23 = F_1 ( V_2 ) ;
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
struct V_15 * V_22 = F_14 ( V_2 , V_3 ) ;
struct V_15 * V_16 , * V_76 ;
F_25 ( & V_19 -> V_47 ) ;
V_23 -> V_4 [ V_3 ] = NULL ;
F_59 (peer, tmp, &self->list, list) {
F_26 ( & V_16 -> V_17 ) ;
F_27 ( & V_16 -> V_48 ) ;
F_28 ( V_16 -> V_30 ) ;
F_28 ( V_16 ) ;
}
V_19 -> V_22 = NULL ;
F_30 ( & V_19 -> V_47 ) ;
F_60 ( & V_19 -> V_70 ) ;
F_28 ( V_22 -> V_30 ) ;
F_28 ( V_22 ) ;
F_28 ( V_19 ) ;
}
int F_61 ( struct V_2 * V_2 , V_9 V_77 )
{
struct F_1 * V_23 = F_1 ( V_2 ) ;
if ( V_77 > V_78 )
return - V_79 ;
V_23 -> V_25 = V_77 ;
return 0 ;
}
int F_62 ( struct V_2 * V_2 )
{
struct F_1 * V_23 = F_1 ( V_2 ) ;
return V_23 -> V_25 ;
}
int F_63 ( struct V_15 * V_16 , struct V_80 * V_81 )
{
struct V_5 * V_6 = V_16 -> V_30 ;
struct V_82 * V_83 ;
void * V_84 ;
V_84 = F_64 ( V_81 -> V_85 , V_81 -> V_86 , V_81 -> V_87 , & V_88 ,
V_89 , V_90 ) ;
if ( ! V_84 )
return - V_91 ;
V_83 = F_65 ( V_81 -> V_85 , V_92 ) ;
if ( ! V_83 )
goto V_93;
if ( F_66 ( V_81 -> V_85 , V_94 , V_16 -> V_20 ) )
goto V_95;
if ( F_66 ( V_81 -> V_85 , V_96 , V_16 -> V_32 ) )
goto V_95;
if ( V_16 -> V_33 )
if ( F_67 ( V_81 -> V_85 , V_97 ) )
goto V_95;
if ( V_16 -> V_34 )
if ( F_67 ( V_81 -> V_85 , V_98 ) )
goto V_95;
if ( V_16 -> V_18 )
if ( F_67 ( V_81 -> V_85 , V_99 ) )
goto V_95;
if ( V_6 ) {
if ( F_66 ( V_81 -> V_85 , V_100 , V_6 -> V_41 ) )
goto V_95;
if ( F_68 ( V_81 -> V_85 , V_101 ,
V_6 -> V_13 , V_102 ) )
goto V_95;
if ( F_69 ( V_81 -> V_85 , V_103 ,
V_6 -> V_36 * sizeof( V_9 ) , & V_6 -> V_8 ) )
goto V_95;
}
F_70 ( V_81 -> V_85 , V_83 ) ;
F_71 ( V_81 -> V_85 , V_84 ) ;
return 0 ;
V_95:
F_72 ( V_81 -> V_85 , V_83 ) ;
V_93:
F_73 ( V_81 -> V_85 , V_84 ) ;
return - V_91 ;
}
int F_74 ( struct V_2 * V_2 , struct V_80 * V_81 ,
V_9 V_3 , V_9 * V_104 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
struct V_15 * V_16 ;
if ( ! V_19 )
return - V_79 ;
F_48 ( & V_19 -> V_47 ) ;
V_16 = V_19 -> V_22 ;
do {
if ( * V_104 ) {
if ( V_16 -> V_20 == * V_104 )
* V_104 = 0 ;
else
continue;
}
if ( F_63 ( V_16 , V_81 ) ) {
* V_104 = V_16 -> V_20 ;
F_49 ( & V_19 -> V_47 ) ;
return - V_91 ;
}
} while ( ( V_16 = F_8 ( V_16 ) ) != V_19 -> V_22 );
F_49 ( & V_19 -> V_47 ) ;
return 0 ;
}
int F_75 ( struct V_2 * V_2 , struct V_80 * V_81 ,
V_9 V_3 )
{
struct V_1 * V_19 = V_1 ( V_2 , V_3 ) ;
char V_105 [ V_106 ] ;
struct V_82 * V_83 ;
void * V_84 ;
int V_107 ;
V_107 = F_76 ( V_2 , V_105 , V_3 ) ;
if ( V_107 || ! V_19 )
return - V_79 ;
V_84 = F_64 ( V_81 -> V_85 , V_81 -> V_86 , V_81 -> V_87 , & V_88 ,
V_89 , V_108 ) ;
if ( ! V_84 )
return - V_91 ;
V_83 = F_65 ( V_81 -> V_85 , V_109 ) ;
if ( ! V_83 )
goto V_93;
F_48 ( & V_19 -> V_47 ) ;
if ( F_66 ( V_81 -> V_85 , V_110 , V_3 ) )
goto V_95;
if ( F_15 ( V_2 , V_19 ) )
if ( F_67 ( V_81 -> V_85 , V_111 ) )
goto V_95;
if ( F_77 ( V_81 -> V_85 , V_112 , V_105 ) )
goto V_95;
if ( F_66 ( V_81 -> V_85 , V_113 , V_19 -> V_24 ) )
goto V_95;
if ( F_66 ( V_81 -> V_85 , V_114 , V_19 -> V_45 ) )
goto V_95;
F_49 ( & V_19 -> V_47 ) ;
F_70 ( V_81 -> V_85 , V_83 ) ;
F_71 ( V_81 -> V_85 , V_84 ) ;
return 0 ;
V_95:
F_49 ( & V_19 -> V_47 ) ;
F_72 ( V_81 -> V_85 , V_83 ) ;
V_93:
F_73 ( V_81 -> V_85 , V_84 ) ;
return - V_91 ;
}
