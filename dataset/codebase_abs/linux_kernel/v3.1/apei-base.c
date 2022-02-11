void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_6 * V_7 ,
T_1 V_8 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
}
int F_2 ( struct V_6 * V_9 , T_2 * V_10 )
{
int V_11 ;
V_11 = F_3 ( V_10 , & V_9 -> V_12 ) ;
if ( V_11 )
return V_11 ;
* V_10 >>= V_9 -> V_12 . V_13 ;
* V_10 &= V_9 -> V_14 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_6 * V_9 )
{
int V_11 ;
T_2 V_10 = 0 ;
V_11 = F_2 ( V_9 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_15 = V_10 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_6 * V_9 )
{
int V_11 ;
V_11 = F_4 ( V_2 , V_9 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_15 = ( V_2 -> V_15 == V_9 -> V_15 ) ;
return 0 ;
}
int F_6 ( struct V_6 * V_9 , T_2 V_10 )
{
int V_11 ;
V_10 &= V_9 -> V_14 ;
V_10 <<= V_9 -> V_12 . V_13 ;
if ( V_9 -> V_16 & V_17 ) {
T_2 V_18 = 0 ;
V_11 = F_3 ( & V_18 , & V_9 -> V_12 ) ;
if ( V_11 )
return V_11 ;
V_18 &= ~ ( V_9 -> V_14 << V_9 -> V_12 . V_13 ) ;
V_10 |= V_18 ;
}
V_11 = F_7 ( V_10 , & V_9 -> V_12 ) ;
return V_11 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_6 * V_9 )
{
return F_6 ( V_9 , V_2 -> V_15 ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_6 * V_9 )
{
int V_11 ;
V_2 -> V_15 = V_9 -> V_15 ;
V_11 = F_8 ( V_2 , V_9 ) ;
return V_11 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_6 * V_9 )
{
return 0 ;
}
int F_11 ( struct V_1 * V_2 , T_3 V_19 ,
bool V_20 )
{
int V_11 = - V_21 ;
T_1 V_22 , V_23 ;
struct V_6 * V_9 ;
T_4 V_24 ;
V_2 -> V_23 = 0 ;
rewind:
V_23 = 0 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_8 ; V_22 ++ ) {
V_9 = & V_2 -> V_7 [ V_22 ] ;
if ( V_9 -> V_19 != V_19 )
continue;
if ( V_23 == V_2 -> V_23 ) {
if ( V_9 -> V_25 >= V_2 -> V_5 ||
! V_2 -> V_4 [ V_9 -> V_25 ] . V_24 ) {
F_12 (FW_WARN APEI_PFX
L_1 ,
entry->instruction) ;
return - V_26 ;
}
V_24 = V_2 -> V_4 [ V_9 -> V_25 ] . V_24 ;
V_11 = V_24 ( V_2 , V_9 ) ;
if ( V_11 < 0 )
return V_11 ;
else if ( V_11 != V_27 )
V_2 -> V_23 ++ ;
}
V_23 ++ ;
if ( V_2 -> V_23 < V_23 )
goto rewind;
}
return ! V_20 && V_11 < 0 ? V_11 : 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_5 V_28 ,
void * V_29 ,
int * V_30 )
{
T_3 V_31 ;
int V_22 , V_11 ;
struct V_6 * V_9 ;
struct V_3 * V_4 = V_2 -> V_4 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_8 ; V_22 ++ ) {
V_9 = V_2 -> V_7 + V_22 ;
V_31 = V_9 -> V_25 ;
if ( V_30 )
* V_30 = V_22 ;
if ( V_31 >= V_2 -> V_5 || ! V_4 [ V_31 ] . V_24 ) {
F_12 (FW_WARN APEI_PFX
L_1 ,
ins) ;
return - V_26 ;
}
V_11 = V_28 ( V_2 , V_9 , V_29 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_6 * V_9 ,
void * V_29 )
{
T_3 V_31 = V_9 -> V_25 ;
if ( V_2 -> V_4 [ V_31 ] . V_16 & V_32 )
return F_15 ( & V_9 -> V_12 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_11 , V_30 ;
V_11 = F_13 ( V_2 , F_14 ,
NULL , & V_30 ) ;
if ( V_11 ) {
struct V_1 V_33 ;
memcpy ( & V_33 , V_2 , sizeof( * V_2 ) ) ;
V_33 . V_8 = V_30 ;
F_17 ( & V_33 ) ;
}
return V_11 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_6 * V_9 ,
void * V_29 )
{
T_3 V_31 = V_9 -> V_25 ;
if ( V_2 -> V_4 [ V_31 ] . V_16 & V_32 )
F_19 ( & V_9 -> V_12 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , F_18 ,
NULL , NULL ) ;
}
static int F_20 ( struct V_34 * V_35 ,
unsigned long V_36 , unsigned long V_37 )
{
struct V_38 * V_39 , * V_40 , * V_41 = NULL ;
unsigned long V_30 = V_36 + V_37 ;
if ( V_30 <= V_36 )
return 0 ;
V_42:
F_21 (res, resn, res_list, list) {
if ( V_39 -> V_36 > V_30 || V_39 -> V_30 < V_36 )
continue;
else if ( V_30 <= V_39 -> V_30 && V_36 >= V_39 -> V_36 ) {
F_22 ( V_41 ) ;
return 0 ;
}
F_23 ( & V_39 -> V_43 ) ;
V_39 -> V_36 = V_36 = F_24 ( V_39 -> V_36 , V_36 ) ;
V_39 -> V_30 = V_30 = F_25 ( V_39 -> V_30 , V_30 ) ;
F_22 ( V_41 ) ;
V_41 = V_39 ;
goto V_42;
}
if ( V_41 )
F_26 ( & V_41 -> V_43 , V_35 ) ;
else {
V_41 = F_27 ( sizeof( * V_39 ) , V_44 ) ;
if ( ! V_41 )
return - V_45 ;
V_41 -> V_36 = V_36 ;
V_41 -> V_30 = V_30 ;
F_26 ( & V_41 -> V_43 , V_35 ) ;
}
return 0 ;
}
static int F_28 ( struct V_34 * V_46 ,
struct V_34 * V_47 )
{
struct V_38 * V_48 , * V_49 , * V_50 , * V_39 ;
V_48 = F_29 ( V_46 -> V_51 , struct V_38 , V_43 ) ;
V_49 = F_29 ( V_48 -> V_43 . V_51 , struct V_38 , V_43 ) ;
while ( & V_48 -> V_43 != V_46 ) {
F_30 (res2, res_list2, list) {
if ( V_48 -> V_36 >= V_50 -> V_30 ||
V_48 -> V_30 <= V_50 -> V_36 )
continue;
else if ( V_48 -> V_30 <= V_50 -> V_30 &&
V_48 -> V_36 >= V_50 -> V_36 ) {
F_23 ( & V_48 -> V_43 ) ;
F_22 ( V_48 ) ;
break;
} else if ( V_48 -> V_30 > V_50 -> V_30 &&
V_48 -> V_36 < V_50 -> V_36 ) {
V_39 = F_27 ( sizeof( * V_39 ) , V_44 ) ;
if ( ! V_39 )
return - V_45 ;
V_39 -> V_36 = V_50 -> V_30 ;
V_39 -> V_30 = V_48 -> V_30 ;
V_48 -> V_30 = V_50 -> V_36 ;
F_26 ( & V_39 -> V_43 , & V_48 -> V_43 ) ;
V_49 = V_39 ;
} else {
if ( V_48 -> V_36 < V_50 -> V_36 )
V_48 -> V_30 = V_50 -> V_36 ;
else
V_48 -> V_36 = V_50 -> V_30 ;
}
}
V_48 = V_49 ;
V_49 = F_29 ( V_49 -> V_43 . V_51 , struct V_38 , V_43 ) ;
}
return 0 ;
}
static void F_31 ( struct V_34 * V_35 )
{
struct V_38 * V_39 , * V_40 ;
F_21 (res, resn, res_list, list) {
F_23 ( & V_39 -> V_43 ) ;
F_22 ( V_39 ) ;
}
}
void F_32 ( struct V_52 * V_53 )
{
F_31 ( & V_53 -> V_54 ) ;
F_31 ( & V_53 -> V_55 ) ;
}
static int F_33 ( struct V_52 * V_56 ,
struct V_52 * V_57 )
{
int V_11 ;
struct V_38 * V_39 ;
F_30 (res, &resources2->iomem, list) {
V_11 = F_20 ( & V_56 -> V_54 , V_39 -> V_36 ,
V_39 -> V_30 - V_39 -> V_36 ) ;
if ( V_11 )
return V_11 ;
}
F_30 (res, &resources2->ioport, list) {
V_11 = F_20 ( & V_56 -> V_55 , V_39 -> V_36 ,
V_39 -> V_30 - V_39 -> V_36 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
int F_34 ( struct V_52 * V_56 ,
struct V_52 * V_57 )
{
int V_11 ;
V_11 = F_28 ( & V_56 -> V_54 , & V_57 -> V_54 ) ;
if ( V_11 )
return V_11 ;
return F_28 ( & V_56 -> V_55 , & V_57 -> V_55 ) ;
}
int F_35 ( struct V_52 * V_53 ,
const char * V_58 )
{
struct V_38 * V_39 , * V_59 = NULL ;
struct V_60 * V_61 ;
int V_11 ;
V_11 = F_34 ( V_53 , & V_62 ) ;
if ( V_11 )
return V_11 ;
V_11 = - V_26 ;
F_30 (res, &resources->iomem, list) {
V_61 = F_36 ( V_39 -> V_36 , V_39 -> V_30 - V_39 -> V_36 ,
V_58 ) ;
if ( ! V_61 ) {
F_37 ( V_63
L_2 ,
( unsigned long long ) V_39 -> V_36 ,
( unsigned long long ) V_39 -> V_30 ) ;
V_59 = V_39 ;
goto V_64;
}
}
F_30 (res, &resources->ioport, list) {
V_61 = F_38 ( V_39 -> V_36 , V_39 -> V_30 - V_39 -> V_36 , V_58 ) ;
if ( ! V_61 ) {
F_37 ( V_63
L_3 ,
( unsigned long long ) V_39 -> V_36 ,
( unsigned long long ) V_39 -> V_30 ) ;
V_59 = V_39 ;
goto V_65;
}
}
V_11 = F_33 ( & V_62 , V_53 ) ;
if ( V_11 ) {
F_37 ( V_63 L_4 ) ;
goto V_65;
}
return 0 ;
V_65:
F_30 (res, &resources->ioport, list) {
if ( V_39 == V_59 )
break;
F_39 ( V_39 -> V_36 , V_39 -> V_30 - V_39 -> V_36 ) ;
}
V_59 = NULL ;
V_64:
F_30 (res, &resources->iomem, list) {
if ( V_39 == V_59 )
break;
F_40 ( V_39 -> V_36 , V_39 -> V_30 - V_39 -> V_36 ) ;
}
return V_11 ;
}
void F_41 ( struct V_52 * V_53 )
{
int V_11 ;
struct V_38 * V_39 ;
F_30 (res, &resources->iomem, list)
F_40 ( V_39 -> V_36 , V_39 -> V_30 - V_39 -> V_36 ) ;
F_30 (res, &resources->ioport, list)
F_39 ( V_39 -> V_36 , V_39 -> V_30 - V_39 -> V_36 ) ;
V_11 = F_34 ( & V_62 , V_53 ) ;
if ( V_11 )
F_37 ( V_63 L_5 ) ;
}
static int F_42 ( struct V_66 * V_67 , T_2 * V_68 )
{
T_1 V_69 , V_70 ;
V_69 = V_67 -> V_71 ;
V_70 = V_67 -> V_70 ;
memcpy ( V_68 , & V_67 -> V_72 , sizeof( * V_68 ) ) ;
if ( ! * V_68 ) {
F_12 (FW_BUG APEI_PFX
L_6 ,
*paddr, width, space_id) ;
return - V_26 ;
}
if ( ( V_69 != 8 ) && ( V_69 != 16 ) && ( V_69 != 32 ) && ( V_69 != 64 ) ) {
F_12 (FW_BUG APEI_PFX
L_7 ,
*paddr, width, space_id) ;
return - V_26 ;
}
if ( V_70 != V_73 &&
V_70 != V_74 ) {
F_12 (FW_BUG APEI_PFX
L_8 ,
*paddr, width, space_id) ;
return - V_26 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_6 * V_9 ,
void * V_29 )
{
struct V_52 * V_53 = V_29 ;
struct V_66 * V_67 = & V_9 -> V_12 ;
T_3 V_31 = V_9 -> V_25 ;
T_2 V_68 ;
int V_11 ;
if ( ! ( V_2 -> V_4 [ V_31 ] . V_16 & V_32 ) )
return 0 ;
V_11 = F_42 ( V_67 , & V_68 ) ;
if ( V_11 )
return V_11 ;
switch ( V_67 -> V_70 ) {
case V_73 :
return F_20 ( & V_53 -> V_54 , V_68 ,
V_67 -> V_71 / 8 ) ;
case V_74 :
return F_20 ( & V_53 -> V_55 , V_68 ,
V_67 -> V_71 / 8 ) ;
default:
return - V_26 ;
}
}
int F_44 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
return F_13 ( V_2 , F_43 ,
V_53 , NULL ) ;
}
struct V_75 * F_45 ( void )
{
static struct V_75 * V_76 ;
if ( ! V_76 )
V_76 = F_46 ( L_9 , NULL ) ;
return V_76 ;
}
int F_47 ( void )
{
static T_3 V_77 [] = L_10 ;
T_6 V_78 ;
T_1 V_79 [ 3 ] ;
struct V_80 V_81 = {
. V_82 = V_77 ,
. V_83 = 1 ,
. V_84 . V_85 = sizeof( V_79 ) ,
. V_84 . V_86 = V_79 ,
} ;
V_79 [ V_87 ] = V_88 ;
V_79 [ V_89 ] = 1 ;
V_79 [ V_90 ] = 0 ;
if ( F_48 ( F_49 ( NULL , L_11 , & V_78 ) )
|| F_48 ( F_50 ( V_78 , & V_81 ) ) )
return - V_91 ;
else {
F_22 ( V_81 . V_92 . V_86 ) ;
return 0 ;
}
}
