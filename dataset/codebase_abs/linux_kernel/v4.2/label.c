static T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
V_1 &= V_3 ;
V_2 &= V_3 ;
if ( V_1 == 0 || V_1 == V_2 )
return V_2 ;
else if ( V_2 == 0 )
return V_1 ;
else if ( F_2 ( V_1 ) == V_2 )
return V_2 ;
else
return V_1 ;
}
T_2 F_3 ( struct V_4 * V_5 )
{
T_1 V_6 ;
if ( V_5 -> V_7 )
return V_5 -> V_7 ;
V_6 = V_5 -> V_8 . V_9 / 129 ;
V_6 /= V_10 * 2 ;
V_5 -> V_7 = V_6 * V_10 ;
return V_5 -> V_7 ;
}
int F_4 ( struct V_4 * V_5 )
{
return V_5 -> V_8 . V_9 / 129 ;
}
int F_5 ( struct V_4 * V_5 )
{
struct V_11 * V_12 [] = {
F_6 ( V_5 , 0 ) ,
F_6 ( V_5 , 1 ) ,
} ;
const int V_13 = F_7 ( V_12 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
bool V_16 [ 2 ] = { 0 } ;
int V_17 , V_18 = 0 ;
T_1 V_19 ;
for ( V_17 = 0 ; V_17 < V_13 ; V_17 ++ ) {
T_1 V_20 ;
T_3 V_21 [ V_22 ] ;
T_4 V_23 , V_24 , V_25 ;
memcpy ( V_21 , V_12 [ V_17 ] -> V_21 , V_22 ) ;
if ( memcmp ( V_21 , V_26 , V_22 ) != 0 ) {
F_8 ( V_15 , L_1 ,
V_27 , V_17 ) ;
continue;
}
V_23 = F_9 ( V_12 [ V_17 ] -> V_28 ) ;
V_12 [ V_17 ] -> V_28 = F_10 ( 0 ) ;
V_24 = F_11 ( V_12 [ V_17 ] , F_3 ( V_5 ) , 1 ) ;
V_12 [ V_17 ] -> V_28 = F_10 ( V_23 ) ;
if ( V_24 != V_23 ) {
F_8 ( V_15 , L_2 ,
V_27 , V_17 ) ;
continue;
}
V_19 = F_12 ( V_12 [ V_17 ] -> V_19 ) ;
if ( ( V_19 & V_3 ) == 0 ) {
F_8 ( V_15 , L_3 ,
V_27 , V_17 , V_19 ) ;
continue;
}
if ( F_9 ( V_12 [ V_17 ] -> V_29 )
!= V_17 * F_3 ( V_5 ) ) {
F_8 ( V_15 , L_4 ,
V_27 , V_17 , ( unsigned long long )
F_9 ( V_12 [ V_17 ] -> V_29 ) ) ;
continue;
}
if ( F_9 ( V_12 [ V_17 ] -> V_30 )
!= ( ! V_17 ) * F_3 ( V_5 ) ) {
F_8 ( V_15 , L_5 ,
V_27 , V_17 , ( unsigned long long )
F_9 ( V_12 [ V_17 ] -> V_30 ) ) ;
continue;
}
V_25 = F_9 ( V_12 [ V_17 ] -> V_31 ) ;
if ( V_25 > F_3 ( V_5 )
|| V_25 < sizeof( struct V_11 ) ) {
F_8 ( V_15 , L_6 ,
V_27 , V_17 , V_25 ) ;
continue;
}
V_20 = F_12 ( V_12 [ V_17 ] -> V_20 ) ;
if ( V_20 * sizeof( struct V_32 )
+ 2 * F_3 ( V_5 )
> V_5 -> V_8 . V_9 ) {
F_8 ( V_15 , L_7 ,
V_27 , V_17 , V_20 ,
V_5 -> V_8 . V_9 ) ;
continue;
}
V_16 [ V_17 ] = true ;
V_18 ++ ;
}
switch ( V_18 ) {
case 0 :
break;
case 1 :
for ( V_17 = 0 ; V_17 < V_13 ; V_17 ++ )
if ( V_16 [ V_17 ] )
return V_17 ;
F_13 ( 1 ) ;
break;
default:
V_19 = F_1 ( F_12 ( V_12 [ 0 ] -> V_19 ) ,
F_12 ( V_12 [ 1 ] -> V_19 ) ) ;
if ( V_19 == ( F_12 ( V_12 [ 1 ] -> V_19 ) & V_3 ) )
return 1 ;
else
return 0 ;
break;
}
return - 1 ;
}
void F_14 ( struct V_4 * V_5 , struct V_11 * V_33 ,
struct V_11 * V_34 )
{
if ( V_33 && V_34 )
;
else
return;
memcpy ( V_33 , V_34 , F_3 ( V_5 ) ) ;
}
static struct V_32 * F_15 ( struct V_4 * V_5 )
{
void * V_35 = F_6 ( V_5 , 0 ) ;
return V_35 + 2 * F_3 ( V_5 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_32 * V_36 )
{
return V_36 - F_15 ( V_5 ) ;
}
static bool F_17 ( struct V_4 * V_5 , int V_37 ,
struct V_11 * * V_38 ,
unsigned long * * free , T_1 * V_20 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_5 , V_37 ) ;
if ( V_12 == NULL )
return false ;
* free = ( unsigned long * ) V_12 -> free ;
* V_20 = F_12 ( V_12 -> V_20 ) ;
* V_38 = V_12 ;
return true ;
}
char * F_18 ( struct V_39 * V_40 , T_3 * V_41 , T_1 V_42 )
{
if ( ! V_40 || ! V_41 )
return NULL ;
snprintf ( V_40 -> V_43 , V_44 , L_8 ,
V_42 & V_45 ? L_9 : L_10 , V_41 ) ;
return V_40 -> V_43 ;
}
static bool F_19 ( struct V_4 * V_5 ,
struct V_11 * * V_12 ,
unsigned long * * free , T_1 * V_20 )
{
return F_17 ( V_5 , V_5 -> V_46 , V_12 ,
free , V_20 ) ;
}
static bool F_20 ( struct V_4 * V_5 ,
struct V_11 * * V_12 ,
unsigned long * * free , T_1 * V_20 )
{
return F_17 ( V_5 , V_5 -> V_47 , V_12 ,
free , V_20 ) ;
}
static bool F_21 ( struct V_32 * V_36 , T_1 V_48 )
{
if ( V_48 != F_12 ( V_36 -> V_48 ) )
return false ;
if ( ( F_9 ( V_36 -> V_49 )
| F_9 ( V_36 -> V_50 ) ) % V_51 )
return false ;
return true ;
}
int F_22 ( struct V_4 * V_5 )
{
struct V_11 * V_12 ;
unsigned long * free ;
T_1 V_20 , V_48 ;
if ( ! F_19 ( V_5 , & V_12 , & free , & V_20 ) )
return 0 ;
F_23 (slot, free, nslot) {
struct V_32 * V_36 ;
struct V_52 * V_52 = NULL ;
T_3 V_53 [ V_54 ] ;
struct V_39 V_40 ;
struct V_55 * V_56 ;
T_1 V_42 ;
V_36 = F_15 ( V_5 ) + V_48 ;
if ( ! F_21 ( V_36 , V_48 ) )
continue;
memcpy ( V_53 , V_36 -> V_41 , V_54 ) ;
V_42 = F_12 ( V_36 -> V_42 ) ;
F_18 ( & V_40 , V_53 , V_42 ) ;
V_56 = F_24 ( V_5 , & V_40 ,
F_9 ( V_36 -> V_49 ) ,
F_9 ( V_36 -> V_50 ) ) ;
F_25 ( V_52 , V_5 , V_56 , L_11 ) ;
if ( ! V_56 )
return - V_57 ;
}
return 0 ;
}
int F_26 ( struct V_4 * V_5 )
{
struct V_11 * V_12 ;
unsigned long * free ;
T_1 V_20 , V_48 ;
int V_58 = 0 ;
if ( ! F_19 ( V_5 , & V_12 , & free , & V_20 ) )
return 0 ;
F_23 (slot, free, nslot) {
struct V_32 * V_36 ;
V_36 = F_15 ( V_5 ) + V_48 ;
if ( ! F_21 ( V_36 , V_48 ) ) {
T_1 V_59 = F_12 ( V_36 -> V_48 ) ;
T_4 V_25 = F_9 ( V_36 -> V_50 ) ;
T_4 V_49 = F_9 ( V_36 -> V_49 ) ;
F_8 ( V_5 -> V_15 ,
L_12 ,
V_27 , V_48 , V_59 , V_49 , V_25 ) ;
continue;
}
V_58 ++ ;
}
return V_58 ;
}
struct V_32 * F_27 ( struct V_4 * V_5 , int V_60 )
{
struct V_11 * V_12 ;
unsigned long * free ;
T_1 V_20 , V_48 ;
if ( ! F_19 ( V_5 , & V_12 , & free , & V_20 ) )
return NULL ;
F_23 (slot, free, nslot) {
struct V_32 * V_36 ;
V_36 = F_15 ( V_5 ) + V_48 ;
if ( ! F_21 ( V_36 , V_48 ) )
continue;
if ( V_60 -- == 0 )
return F_15 ( V_5 ) + V_48 ;
}
return NULL ;
}
T_1 F_28 ( struct V_4 * V_5 )
{
struct V_11 * V_12 ;
unsigned long * free ;
T_1 V_20 , V_48 ;
if ( ! F_20 ( V_5 , & V_12 , & free , & V_20 ) )
return V_61 ;
F_13 ( ! F_29 ( V_5 -> V_15 ) ) ;
V_48 = F_30 ( free , V_20 , 0 ) ;
if ( V_48 == V_20 )
return V_61 ;
F_31 ( V_48 , free ) ;
return V_48 ;
}
bool F_32 ( struct V_4 * V_5 , T_1 V_48 )
{
struct V_11 * V_12 ;
unsigned long * free ;
T_1 V_20 ;
if ( ! F_20 ( V_5 , & V_12 , & free , & V_20 ) )
return false ;
F_13 ( ! F_29 ( V_5 -> V_15 ) ) ;
if ( V_48 < V_20 )
return ! F_33 ( V_48 , free ) ;
return false ;
}
T_1 F_34 ( struct V_4 * V_5 )
{
struct V_11 * V_12 ;
unsigned long * free ;
T_1 V_20 ;
F_13 ( ! F_29 ( V_5 -> V_15 ) ) ;
if ( ! F_20 ( V_5 , & V_12 , & free , & V_20 ) )
return F_4 ( V_5 ) ;
return F_35 ( free , V_20 ) ;
}
static int F_36 ( struct V_4 * V_5 , int V_62 , T_1 V_19 ,
unsigned long V_42 )
{
struct V_11 * V_12 ;
unsigned long V_63 ;
T_4 V_28 ;
T_1 V_20 ;
int V_64 ;
V_12 = F_6 ( V_5 , V_62 ) ;
if ( V_42 & V_65 )
V_20 = F_4 ( V_5 ) ;
else
V_20 = F_12 ( V_12 -> V_20 ) ;
memcpy ( V_12 -> V_21 , V_26 , V_22 ) ;
V_12 -> V_42 = F_37 ( 0 ) ;
V_12 -> V_19 = F_37 ( V_19 ) ;
V_63 = ( unsigned long ) V_12
- ( unsigned long ) F_6 ( V_5 , 0 ) ;
V_12 -> V_29 = F_10 ( V_63 ) ;
V_12 -> V_31 = F_10 ( F_3 ( V_5 ) ) ;
V_63 = ( unsigned long ) F_6 ( V_5 ,
F_38 ( V_62 ) )
- ( unsigned long ) F_6 ( V_5 , 0 ) ;
V_12 -> V_30 = F_10 ( V_63 ) ;
V_63 = ( unsigned long ) F_15 ( V_5 )
- ( unsigned long ) F_6 ( V_5 , 0 ) ;
V_12 -> V_66 = F_10 ( V_63 ) ;
V_12 -> V_20 = F_37 ( V_20 ) ;
V_12 -> V_67 = F_39 ( 1 ) ;
V_12 -> V_68 = F_39 ( 1 ) ;
V_12 -> V_28 = F_10 ( 0 ) ;
if ( V_42 & V_65 ) {
unsigned long * free = ( unsigned long * ) V_12 -> free ;
T_1 V_69 = F_40 ( V_20 , V_70 ) ;
int V_71 , V_17 ;
memset ( V_12 -> free , 0xff , V_69 / 8 ) ;
for ( V_17 = 0 , V_71 = V_69 - V_20 ; V_17 < V_71 ; V_17 ++ )
F_31 ( V_20 + V_17 , free ) ;
}
V_28 = F_11 ( V_12 , F_3 ( V_5 ) , 1 ) ;
V_12 -> V_28 = F_10 ( V_28 ) ;
V_64 = F_41 ( V_5 , F_9 ( V_12 -> V_29 ) ,
V_12 , F_3 ( V_5 ) ) ;
if ( V_64 < 0 )
return V_64 ;
if ( V_42 & V_65 )
return 0 ;
F_13 ( V_62 != V_5 -> V_47 ) ;
F_14 ( V_5 , F_42 ( V_5 ) , V_12 ) ;
V_5 -> V_46 = F_38 ( V_5 -> V_46 ) ;
V_5 -> V_47 = F_38 ( V_5 -> V_47 ) ;
F_13 ( V_5 -> V_46 == V_5 -> V_47 ) ;
return 0 ;
}
static unsigned long F_43 ( struct V_4 * V_5 ,
struct V_32 * V_36 )
{
return ( unsigned long ) V_36
- ( unsigned long ) F_6 ( V_5 , 0 ) ;
}
static int F_44 ( struct V_52 * V_52 ,
struct V_72 * V_72 , struct V_73 * V_74 ,
int V_75 )
{
T_4 V_76 = F_45 ( V_52 ) , V_50 ;
struct V_4 * V_5 = F_46 ( V_72 ) ;
struct V_32 * V_77 ;
struct V_32 * V_36 ;
struct V_11 * V_12 ;
unsigned long * free ;
T_1 V_20 , V_48 ;
T_2 V_63 ;
int V_64 ;
if ( ! F_20 ( V_5 , & V_12 , & free , & V_20 ) )
return - V_78 ;
V_48 = F_28 ( V_5 ) ;
if ( V_48 == V_61 )
return - V_78 ;
F_8 ( V_5 -> V_15 , L_13 , V_27 , V_48 ) ;
V_36 = F_15 ( V_5 ) + V_48 ;
memset ( V_36 , 0 , sizeof( struct V_32 ) ) ;
memcpy ( V_36 -> V_41 , V_74 -> V_41 , V_54 ) ;
if ( V_74 -> V_79 )
memcpy ( V_36 -> V_80 , V_74 -> V_79 , V_81 ) ;
V_36 -> V_42 = F_37 ( V_82 ) ;
V_36 -> V_83 = F_39 ( V_52 -> V_84 ) ;
V_36 -> V_85 = F_39 ( V_75 ) ;
V_36 -> V_86 = F_10 ( V_76 ) ;
V_50 = F_47 ( F_48 ( & V_74 -> V_87 . V_56 ) ,
V_52 -> V_84 ) ;
V_36 -> V_50 = F_10 ( V_50 ) ;
V_36 -> V_49 = F_10 ( V_72 -> V_88 ) ;
V_36 -> V_48 = F_37 ( V_48 ) ;
V_63 = F_43 ( V_5 , V_36 ) ;
V_64 = F_41 ( V_5 , V_63 , V_36 ,
sizeof( struct V_32 ) ) ;
if ( V_64 < 0 )
return V_64 ;
V_77 = V_72 -> V_89 [ 0 ] ;
if ( V_77 ) {
V_48 = F_16 ( V_5 , V_77 ) ;
F_32 ( V_5 , V_48 ) ;
F_8 ( V_5 -> V_15 , L_14 , V_27 , V_48 ) ;
}
V_64 = F_36 ( V_5 , V_5 -> V_47 ,
F_2 ( F_12 ( V_12 -> V_19 ) ) , 0 ) ;
if ( V_64 < 0 )
return V_64 ;
V_72 -> V_89 [ 0 ] = V_36 ;
return 0 ;
}
static void F_49 ( struct V_72 * V_72 , int V_90 )
{
struct V_32 * V_91 , * V_36 ;
struct V_4 * V_5 = F_46 ( V_72 ) ;
unsigned int V_48 ;
int V_92 ;
V_36 = V_72 -> V_89 [ V_90 ] ;
V_48 = F_16 ( V_5 , V_36 ) ;
F_50 ( V_5 -> V_15 , L_15 , V_27 , V_48 ) ;
for ( V_92 = V_90 ; ( V_91 = V_72 -> V_89 [ V_92 + 1 ] ) ; V_92 ++ )
V_72 -> V_89 [ V_92 ] = V_91 ;
V_72 -> V_89 [ V_92 ] = NULL ;
}
static bool F_51 ( struct V_55 * V_56 , struct V_55 * * V_93 , int V_60 )
{
int V_17 ;
if ( V_56 -> V_42 & V_94 )
return false ;
for ( V_17 = 0 ; V_17 < V_60 ; V_17 ++ )
if ( V_56 == V_93 [ V_17 ] )
return true ;
return false ;
}
static struct V_55 * F_52 ( struct V_4 * V_5 ,
struct V_32 * V_36 )
{
struct V_55 * V_56 ;
F_53 (ndd, res) {
if ( V_56 -> V_88 != F_9 ( V_36 -> V_49 ) )
continue;
if ( F_48 ( V_56 ) != F_9 ( V_36 -> V_50 ) )
continue;
return V_56 ;
}
return NULL ;
}
static int F_54 ( struct V_52 * V_52 ,
struct V_72 * V_72 , struct V_95 * V_96 ,
int V_97 )
{
int V_17 , V_90 , V_98 , V_99 , V_69 , V_100 , V_83 , V_64 = - V_78 ;
struct V_4 * V_5 = F_46 ( V_72 ) ;
struct V_32 * V_36 ;
struct V_11 * V_12 ;
unsigned long * free , * V_101 = NULL ;
struct V_55 * V_56 , * * V_102 ;
struct V_39 V_40 ;
T_3 V_41 [ V_54 ] ;
T_1 V_20 , V_48 ;
if ( ! F_20 ( V_5 , & V_12 , & free , & V_20 ) )
return - V_78 ;
V_102 = V_96 -> V_56 ;
V_69 = F_34 ( V_5 ) ;
V_100 = V_96 -> V_103 ;
F_18 ( & V_40 , V_96 -> V_41 , V_45 ) ;
V_98 = 0 ;
F_53 (ndd, res) {
if ( strcmp ( V_56 -> V_80 , V_40 . V_43 ) != 0 )
continue;
if ( ! F_51 ( V_56 , V_102 , V_100 ) )
V_98 ++ ;
}
V_99 = 0 ;
if ( V_100 ) {
V_101 = F_55 ( F_56 ( V_20 ) , sizeof( long ) ,
V_104 ) ;
if ( ! V_101 )
return - V_105 ;
F_23 (slot, free, nslot) {
V_36 = F_15 ( V_5 ) + V_48 ;
memcpy ( V_41 , V_36 -> V_41 , V_54 ) ;
if ( memcmp ( V_41 , V_96 -> V_41 , V_54 ) != 0 )
continue;
V_56 = F_52 ( V_5 , V_36 ) ;
if ( V_56 && F_51 ( V_56 , V_102 ,
V_100 ) )
continue;
V_48 = F_16 ( V_5 , V_36 ) ;
F_57 ( V_48 , V_101 ) ;
V_99 ++ ;
}
}
if ( V_69 - V_98 < 0 || V_69 - V_98 + V_99 < 1 ) {
F_58 ( & V_96 -> V_106 . V_15 , L_16 ) ;
F_59 ( V_101 ) ;
return - V_107 ;
}
V_96 -> V_56 = NULL ;
V_96 -> V_103 = 0 ;
F_53 (ndd, res) {
if ( strcmp ( V_56 -> V_80 , V_40 . V_43 ) != 0 )
continue;
if ( ! F_60 ( V_52 , V_5 , V_96 , V_56 -> V_88 ) ) {
V_64 = - V_105 ;
goto abort;
}
}
for ( V_17 = 0 ; V_17 < V_96 -> V_103 ; V_17 ++ ) {
T_2 V_63 ;
V_56 = V_96 -> V_56 [ V_17 ] ;
if ( F_51 ( V_56 , V_102 , V_100 ) )
continue;
V_48 = F_28 ( V_5 ) ;
if ( V_48 == V_61 )
goto abort;
F_8 ( V_5 -> V_15 , L_13 , V_27 , V_48 ) ;
V_36 = F_15 ( V_5 ) + V_48 ;
memset ( V_36 , 0 , sizeof( struct V_32 ) ) ;
memcpy ( V_36 -> V_41 , V_96 -> V_41 , V_54 ) ;
if ( V_96 -> V_79 )
memcpy ( V_36 -> V_80 , V_96 -> V_79 ,
V_81 ) ;
V_36 -> V_42 = F_37 ( V_45 ) ;
V_36 -> V_83 = F_39 ( 0 ) ;
V_36 -> V_85 = F_39 ( 0 ) ;
V_36 -> V_86 = F_10 ( 0 ) ;
V_36 -> V_49 = F_10 ( V_56 -> V_88 ) ;
V_36 -> V_50 = F_10 ( F_48 ( V_56 ) ) ;
V_36 -> V_108 = F_10 ( V_96 -> V_108 ) ;
V_36 -> V_48 = F_37 ( V_48 ) ;
V_63 = F_43 ( V_5 , V_36 ) ;
V_64 = F_41 ( V_5 , V_63 , V_36 ,
sizeof( struct V_32 ) ) ;
if ( V_64 < 0 )
goto abort;
}
F_61 (slot, victim_map, victim_map ? nslot : 0 ) {
F_8 ( V_5 -> V_15 , L_14 , V_27 , V_48 ) ;
F_32 ( V_5 , V_48 ) ;
}
V_64 = F_36 ( V_5 , V_5 -> V_47 ,
F_2 ( F_12 ( V_12 -> V_19 ) ) , 0 ) ;
if ( V_64 )
goto abort;
V_83 = 0 ;
F_62 (l, nd_label, nd_mapping->labels) {
V_83 ++ ;
memcpy ( V_41 , V_36 -> V_41 , V_54 ) ;
if ( memcmp ( V_41 , V_96 -> V_41 , V_54 ) != 0 )
continue;
V_83 -- ;
F_49 ( V_72 , V_90 ) ;
V_90 -- ;
}
if ( V_83 + V_96 -> V_103 > V_97 ) {
F_63 ( 1 ) ;
V_64 = - V_78 ;
goto V_109;
}
F_23 (slot, free, nslot) {
V_36 = F_15 ( V_5 ) + V_48 ;
memcpy ( V_41 , V_36 -> V_41 , V_54 ) ;
if ( memcmp ( V_41 , V_96 -> V_41 , V_54 ) != 0 )
continue;
V_56 = F_52 ( V_5 , V_36 ) ;
V_56 -> V_42 &= ~ V_94 ;
F_50 ( & V_96 -> V_106 . V_15 , L_17 ,
V_90 , V_48 ) ;
V_72 -> V_89 [ V_90 ++ ] = V_36 ;
}
V_72 -> V_89 [ V_90 ] = NULL ;
V_109:
F_59 ( V_102 ) ;
F_59 ( V_101 ) ;
return V_64 ;
abort:
F_14 ( V_5 , V_12 , F_42 ( V_5 ) ) ;
F_59 ( V_96 -> V_56 ) ;
V_96 -> V_56 = V_102 ;
V_96 -> V_103 = V_100 ;
V_102 = NULL ;
goto V_109;
}
static int F_64 ( struct V_72 * V_72 , int V_97 )
{
int V_17 , V_90 , V_110 = 0 ;
struct V_11 * V_12 ;
struct V_32 * V_36 ;
struct V_4 * V_5 = F_46 ( V_72 ) ;
T_2 V_25 = ( V_97 + 1 ) * sizeof( struct V_32 * ) ;
F_62 (l, nd_label, nd_mapping->labels)
V_110 ++ ;
if ( V_97 > V_110 ) {
struct V_32 * * V_89 ;
V_89 = F_65 ( V_72 -> V_89 , V_25 , V_104 ) ;
if ( ! V_89 )
return - V_105 ;
V_72 -> V_89 = V_89 ;
}
if ( ! V_72 -> V_89 )
return - V_105 ;
for ( V_17 = V_110 ; V_17 <= V_97 ; V_17 ++ )
V_72 -> V_89 [ V_17 ] = NULL ;
if ( V_5 -> V_46 == - 1 || V_5 -> V_47 == - 1 )
;
else
return F_66 ( V_97 , V_110 ) ;
V_12 = F_6 ( V_5 , 0 ) ;
memset ( V_12 , 0 , V_5 -> V_8 . V_9 ) ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
int V_64 = F_36 ( V_5 , V_17 , V_17 * 2 , V_65 ) ;
if ( V_64 )
return V_64 ;
}
V_5 -> V_47 = 1 ;
V_5 -> V_46 = 0 ;
return F_66 ( V_97 , V_110 ) ;
}
static int F_67 ( struct V_72 * V_72 , T_3 * V_41 )
{
struct V_4 * V_5 = F_46 ( V_72 ) ;
struct V_32 * V_36 ;
struct V_11 * V_12 ;
T_3 V_53 [ V_54 ] ;
int V_90 , V_111 = 0 ;
unsigned long * free ;
T_1 V_20 , V_48 ;
if ( ! V_41 )
return 0 ;
if ( ! F_20 ( V_5 , & V_12 , & free , & V_20 )
|| ! V_72 -> V_89 )
return 0 ;
F_62 (l, nd_label, nd_mapping->labels) {
memcpy ( V_53 , V_36 -> V_41 , V_54 ) ;
if ( memcmp ( V_53 , V_41 , V_54 ) != 0 )
continue;
V_48 = F_16 ( V_5 , V_36 ) ;
F_32 ( V_5 , V_48 ) ;
F_8 ( V_5 -> V_15 , L_14 , V_27 , V_48 ) ;
F_49 ( V_72 , V_90 ) ;
V_111 ++ ;
V_90 -- ;
}
if ( V_111 > V_90 ) {
F_59 ( V_72 -> V_89 ) ;
V_72 -> V_89 = NULL ;
F_8 ( V_5 -> V_15 , L_18 , V_27 ) ;
}
return F_36 ( V_5 , V_5 -> V_47 ,
F_2 ( F_12 ( V_12 -> V_19 ) ) , 0 ) ;
}
int F_68 ( struct V_52 * V_52 ,
struct V_73 * V_74 , T_5 V_25 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_52 -> V_84 ; V_17 ++ ) {
struct V_72 * V_72 = & V_52 -> V_112 [ V_17 ] ;
int V_64 ;
if ( V_25 == 0 ) {
V_64 = F_67 ( V_72 , V_74 -> V_41 ) ;
if ( V_64 )
return V_64 ;
continue;
}
V_64 = F_64 ( V_72 , 1 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_44 ( V_52 , V_72 , V_74 , V_17 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
int F_69 ( struct V_52 * V_52 ,
struct V_95 * V_96 , T_5 V_25 )
{
struct V_72 * V_72 = & V_52 -> V_112 [ 0 ] ;
struct V_55 * V_56 ;
int V_58 = 0 ;
if ( V_25 == 0 )
return F_67 ( V_72 , V_96 -> V_41 ) ;
F_53 (to_ndd(nd_mapping), res)
V_58 ++ ;
V_58 = F_64 ( V_72 , V_58 ) ;
if ( V_58 < 0 )
return V_58 ;
return F_54 ( V_52 , V_72 , V_96 , V_58 ) ;
}
