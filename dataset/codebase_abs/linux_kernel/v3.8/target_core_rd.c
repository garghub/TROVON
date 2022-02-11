static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_7 ;
V_7 = F_4 ( sizeof( struct V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_5 ( L_1 ) ;
return - V_9 ;
}
V_7 -> V_10 = V_6 ;
V_5 -> V_11 = V_7 ;
F_6 ( L_2
L_3 , V_5 -> V_12 ,
V_13 , V_14 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = V_5 -> V_11 ;
F_6 ( L_4
L_5 , V_5 -> V_12 , V_7 -> V_10 ) ;
F_8 ( V_7 ) ;
V_5 -> V_11 = NULL ;
}
static void F_9 ( struct V_1 * V_1 )
{
T_1 V_15 , V_16 , V_17 = 0 , V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
if ( ! V_1 -> V_25 || ! V_1 -> V_26 )
return;
V_20 = V_1 -> V_25 ;
for ( V_15 = 0 ; V_15 < V_1 -> V_26 ; V_15 ++ ) {
V_24 = V_20 [ V_15 ] . V_20 ;
V_18 = V_20 [ V_15 ] . V_27 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
V_22 = F_10 ( & V_24 [ V_16 ] ) ;
if ( V_22 ) {
F_11 ( V_22 ) ;
V_17 ++ ;
}
}
F_8 ( V_24 ) ;
}
F_6 ( L_6
L_7 ,
V_1 -> V_7 -> V_10 , V_1 -> V_28 , V_17 ,
V_1 -> V_26 , ( unsigned long ) V_17 * V_29 ) ;
F_8 ( V_20 ) ;
V_1 -> V_25 = NULL ;
V_1 -> V_26 = 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
T_1 V_15 = 0 , V_16 , V_30 = 0 , V_18 , V_31 , V_32 ;
T_1 V_33 = ( V_34 /
sizeof( struct V_23 ) ) ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
if ( V_1 -> V_35 <= 0 ) {
F_5 ( L_8 ,
V_1 -> V_35 ) ;
return - V_36 ;
}
V_32 = V_1 -> V_35 ;
V_31 = ( V_32 / V_33 ) + 1 ;
V_20 = F_4 ( V_31 * sizeof( struct V_19 ) , V_8 ) ;
if ( ! V_20 ) {
F_5 ( L_9
L_10 ) ;
return - V_9 ;
}
V_1 -> V_25 = V_20 ;
V_1 -> V_26 = V_31 ;
while ( V_32 ) {
V_18 = ( V_32 > V_33 ) ?
V_33 : V_32 ;
V_24 = F_4 ( V_18 * sizeof( struct V_23 ) ,
V_8 ) ;
if ( ! V_24 ) {
F_5 ( L_11
L_12 ) ;
return - V_9 ;
}
F_13 ( V_24 , V_18 ) ;
V_20 [ V_15 ] . V_20 = V_24 ;
V_20 [ V_15 ] . V_27 = V_18 ;
V_20 [ V_15 ] . V_37 = V_30 ;
V_20 [ V_15 ++ ] . V_38 = ( V_30 + V_18 )
- 1 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
V_22 = F_14 ( V_8 , 0 ) ;
if ( ! V_22 ) {
F_5 ( L_13
L_14 ) ;
return - V_9 ;
}
F_15 ( & V_24 [ V_16 ] , V_22 ) ;
V_24 [ V_16 ] . V_39 = V_29 ;
}
V_30 += V_18 ;
V_32 -= V_18 ;
}
F_6 ( L_15
L_16 , V_1 -> V_7 -> V_10 ,
V_1 -> V_28 , V_1 -> V_35 ,
V_1 -> V_26 ) ;
return 0 ;
}
static struct V_2 * F_16 ( struct V_4 * V_5 , const char * V_40 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 = V_5 -> V_11 ;
V_1 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_1 ) {
F_5 ( L_17 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
return & V_1 -> V_3 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_4 -> V_11 ;
int V_41 ;
if ( ! ( V_1 -> V_42 & V_43 ) ) {
F_6 ( L_18 ) ;
return - V_36 ;
}
V_41 = F_12 ( V_1 ) ;
if ( V_41 < 0 )
goto V_44;
V_3 -> V_45 . V_46 = V_47 ;
V_3 -> V_45 . V_48 = V_49 ;
V_3 -> V_45 . V_50 = V_51 ;
V_1 -> V_28 = V_7 -> V_52 ++ ;
F_6 ( L_19
L_20 ,
V_7 -> V_10 , V_1 -> V_28 , V_1 -> V_35 ,
V_1 -> V_26 ,
( unsigned long ) ( V_1 -> V_35 * V_29 ) ) ;
return 0 ;
V_44:
F_9 ( V_1 ) ;
return V_41 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_9 ( V_1 ) ;
F_8 ( V_1 ) ;
}
static struct V_19 * F_19 ( struct V_1 * V_1 , T_1 V_21 )
{
T_1 V_15 ;
struct V_19 * V_20 ;
for ( V_15 = 0 ; V_15 < V_1 -> V_26 ; V_15 ++ ) {
V_20 = & V_1 -> V_25 [ V_15 ] ;
if ( ( V_20 -> V_37 <= V_21 ) &&
( V_20 -> V_38 >= V_21 ) )
return V_20 ;
}
F_5 ( L_21 ,
V_21 ) ;
return NULL ;
}
static T_2
F_20 ( struct V_53 * V_54 )
{
struct V_23 * V_55 = V_54 -> V_56 ;
T_1 V_57 = V_54 -> V_58 ;
enum V_59 V_60 = V_54 -> V_60 ;
struct V_2 * V_61 = V_54 -> V_61 ;
struct V_1 * V_3 = F_1 ( V_61 ) ;
struct V_19 * V_62 ;
struct V_23 * V_63 ;
struct V_64 V_65 ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
T_3 V_70 ;
V_70 = V_54 -> V_71 * V_61 -> V_45 . V_72 ;
V_66 = F_21 ( V_70 , V_29 ) ;
V_68 = V_70 ;
V_67 = V_54 -> V_73 ;
V_62 = F_19 ( V_3 , V_68 ) ;
if ( ! V_62 )
return V_74 ;
V_63 = & V_62 -> V_20 [ V_68 - V_62 -> V_37 ] ;
F_6 ( L_22 ,
V_3 -> V_28 ,
V_60 == V_75 ? L_23 : L_24 ,
V_54 -> V_71 , V_67 , V_68 , V_66 ) ;
V_69 = V_29 - V_66 ;
F_22 ( & V_65 , V_55 , V_57 ,
V_60 == V_75 ?
V_76 : V_77 ) ;
while ( V_67 ) {
T_1 V_78 ;
void * V_79 ;
F_23 ( & V_65 ) ;
V_78 = F_24 ( ( T_1 ) V_65 . V_39 , V_69 ) ;
V_65 . V_80 = V_78 ;
V_79 = F_25 ( V_63 ) + V_66 ;
if ( V_60 == V_75 )
memcpy ( V_65 . V_81 , V_79 , V_78 ) ;
else
memcpy ( V_79 , V_65 . V_81 , V_78 ) ;
V_67 -= V_78 ;
if ( ! V_67 )
continue;
V_69 -= V_78 ;
if ( V_69 ) {
V_66 += V_78 ;
continue;
}
V_68 ++ ;
V_66 = 0 ;
V_69 = V_29 ;
if ( V_68 <= V_62 -> V_38 ) {
V_63 ++ ;
continue;
}
V_62 = F_19 ( V_3 , V_68 ) ;
if ( ! V_62 ) {
F_26 ( & V_65 ) ;
return V_74 ;
}
V_63 = V_62 -> V_20 ;
}
F_26 ( & V_65 ) ;
F_27 ( V_54 , V_82 ) ;
return 0 ;
}
static T_4 F_28 ( struct V_2 * V_3 ,
const char * V_21 , T_4 V_83 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_84 , * V_85 , * V_86 ;
T_5 args [ V_87 ] ;
int V_41 = 0 , V_88 , V_89 ;
V_86 = F_29 ( V_21 , V_8 ) ;
if ( ! V_86 )
return - V_9 ;
V_84 = V_86 ;
while ( ( V_85 = F_30 ( & V_86 , L_25 ) ) != NULL ) {
if ( ! * V_85 )
continue;
V_89 = F_31 ( V_85 , V_90 , args ) ;
switch ( V_89 ) {
case V_91 :
F_32 ( args , & V_88 ) ;
V_1 -> V_35 = V_88 ;
F_6 ( L_26
L_27 , V_1 -> V_35 ) ;
V_1 -> V_42 |= V_43 ;
break;
default:
break;
}
}
F_8 ( V_84 ) ;
return ( ! V_41 ) ? V_83 : V_41 ;
}
static T_4 F_33 ( struct V_2 * V_3 , char * V_92 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_4 V_93 = sprintf ( V_92 , L_28 ,
V_1 -> V_28 ) ;
V_93 += sprintf ( V_92 + V_93 , L_29
L_30 , V_1 -> V_35 ,
V_29 , V_1 -> V_26 ) ;
return V_93 ;
}
static T_6 F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long long V_94 = ( ( V_1 -> V_35 * V_29 ) /
V_3 -> V_45 . V_72 ) - 1 ;
return V_94 ;
}
static T_2
F_35 ( struct V_53 * V_54 )
{
return F_36 ( V_54 , & V_95 ) ;
}
int T_7 F_37 ( void )
{
int V_41 ;
V_41 = F_38 ( & V_96 ) ;
if ( V_41 < 0 ) {
return V_41 ;
}
return 0 ;
}
void F_39 ( void )
{
F_40 ( & V_96 ) ;
}
