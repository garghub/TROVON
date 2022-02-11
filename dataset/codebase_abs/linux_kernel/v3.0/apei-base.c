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
int F_11 ( struct V_1 * V_2 , T_3 V_19 )
{
int V_11 ;
T_1 V_20 , V_21 ;
struct V_6 * V_9 ;
T_4 V_22 ;
V_2 -> V_21 = 0 ;
rewind:
V_21 = 0 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_8 ; V_20 ++ ) {
V_9 = & V_2 -> V_7 [ V_20 ] ;
if ( V_9 -> V_19 != V_19 )
continue;
if ( V_21 == V_2 -> V_21 ) {
if ( V_9 -> V_23 >= V_2 -> V_5 ||
! V_2 -> V_4 [ V_9 -> V_23 ] . V_22 ) {
F_12 (FW_WARN APEI_PFX
L_1 ,
entry->instruction) ;
return - V_24 ;
}
V_22 = V_2 -> V_4 [ V_9 -> V_23 ] . V_22 ;
V_11 = V_22 ( V_2 , V_9 ) ;
if ( V_11 < 0 )
return V_11 ;
else if ( V_11 != V_25 )
V_2 -> V_21 ++ ;
}
V_21 ++ ;
if ( V_2 -> V_21 < V_21 )
goto rewind;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_5 V_26 ,
void * V_27 ,
int * V_28 )
{
T_3 V_29 ;
int V_20 , V_11 ;
struct V_6 * V_9 ;
struct V_3 * V_4 = V_2 -> V_4 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_8 ; V_20 ++ ) {
V_9 = V_2 -> V_7 + V_20 ;
V_29 = V_9 -> V_23 ;
if ( V_28 )
* V_28 = V_20 ;
if ( V_29 >= V_2 -> V_5 || ! V_4 [ V_29 ] . V_22 ) {
F_12 (FW_WARN APEI_PFX
L_1 ,
ins) ;
return - V_24 ;
}
V_11 = V_26 ( V_2 , V_9 , V_27 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_6 * V_9 ,
void * V_27 )
{
T_3 V_29 = V_9 -> V_23 ;
if ( V_2 -> V_4 [ V_29 ] . V_16 & V_30 )
return F_15 ( & V_9 -> V_12 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_11 , V_28 ;
V_11 = F_13 ( V_2 , F_14 ,
NULL , & V_28 ) ;
if ( V_11 ) {
struct V_1 V_31 ;
memcpy ( & V_31 , V_2 , sizeof( * V_2 ) ) ;
V_31 . V_8 = V_28 ;
F_17 ( & V_31 ) ;
}
return V_11 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_6 * V_9 ,
void * V_27 )
{
T_3 V_29 = V_9 -> V_23 ;
if ( V_2 -> V_4 [ V_29 ] . V_16 & V_30 )
F_19 ( & V_9 -> V_12 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , F_18 ,
NULL , NULL ) ;
}
static int F_20 ( struct V_32 * V_33 ,
unsigned long V_34 , unsigned long V_35 )
{
struct V_36 * V_37 , * V_38 , * V_39 = NULL ;
unsigned long V_28 = V_34 + V_35 ;
if ( V_28 <= V_34 )
return 0 ;
V_40:
F_21 (res, resn, res_list, list) {
if ( V_37 -> V_34 > V_28 || V_37 -> V_28 < V_34 )
continue;
else if ( V_28 <= V_37 -> V_28 && V_34 >= V_37 -> V_34 ) {
F_22 ( V_39 ) ;
return 0 ;
}
F_23 ( & V_37 -> V_41 ) ;
V_37 -> V_34 = V_34 = F_24 ( V_37 -> V_34 , V_34 ) ;
V_37 -> V_28 = V_28 = F_25 ( V_37 -> V_28 , V_28 ) ;
F_22 ( V_39 ) ;
V_39 = V_37 ;
goto V_40;
}
if ( V_39 )
F_26 ( & V_39 -> V_41 , V_33 ) ;
else {
V_39 = F_27 ( sizeof( * V_37 ) , V_42 ) ;
if ( ! V_39 )
return - V_43 ;
V_39 -> V_34 = V_34 ;
V_39 -> V_28 = V_28 ;
F_26 ( & V_39 -> V_41 , V_33 ) ;
}
return 0 ;
}
static int F_28 ( struct V_32 * V_44 ,
struct V_32 * V_45 )
{
struct V_36 * V_46 , * V_47 , * V_48 , * V_37 ;
V_46 = F_29 ( V_44 -> V_49 , struct V_36 , V_41 ) ;
V_47 = F_29 ( V_46 -> V_41 . V_49 , struct V_36 , V_41 ) ;
while ( & V_46 -> V_41 != V_44 ) {
F_30 (res2, res_list2, list) {
if ( V_46 -> V_34 >= V_48 -> V_28 ||
V_46 -> V_28 <= V_48 -> V_34 )
continue;
else if ( V_46 -> V_28 <= V_48 -> V_28 &&
V_46 -> V_34 >= V_48 -> V_34 ) {
F_23 ( & V_46 -> V_41 ) ;
F_22 ( V_46 ) ;
break;
} else if ( V_46 -> V_28 > V_48 -> V_28 &&
V_46 -> V_34 < V_48 -> V_34 ) {
V_37 = F_27 ( sizeof( * V_37 ) , V_42 ) ;
if ( ! V_37 )
return - V_43 ;
V_37 -> V_34 = V_48 -> V_28 ;
V_37 -> V_28 = V_46 -> V_28 ;
V_46 -> V_28 = V_48 -> V_34 ;
F_26 ( & V_37 -> V_41 , & V_46 -> V_41 ) ;
V_47 = V_37 ;
} else {
if ( V_46 -> V_34 < V_48 -> V_34 )
V_46 -> V_28 = V_48 -> V_34 ;
else
V_46 -> V_34 = V_48 -> V_28 ;
}
}
V_46 = V_47 ;
V_47 = F_29 ( V_47 -> V_41 . V_49 , struct V_36 , V_41 ) ;
}
return 0 ;
}
static void F_31 ( struct V_32 * V_33 )
{
struct V_36 * V_37 , * V_38 ;
F_21 (res, resn, res_list, list) {
F_23 ( & V_37 -> V_41 ) ;
F_22 ( V_37 ) ;
}
}
void F_32 ( struct V_50 * V_51 )
{
F_31 ( & V_51 -> V_52 ) ;
F_31 ( & V_51 -> V_53 ) ;
}
static int F_33 ( struct V_50 * V_54 ,
struct V_50 * V_55 )
{
int V_11 ;
struct V_36 * V_37 ;
F_30 (res, &resources2->iomem, list) {
V_11 = F_20 ( & V_54 -> V_52 , V_37 -> V_34 ,
V_37 -> V_28 - V_37 -> V_34 ) ;
if ( V_11 )
return V_11 ;
}
F_30 (res, &resources2->ioport, list) {
V_11 = F_20 ( & V_54 -> V_53 , V_37 -> V_34 ,
V_37 -> V_28 - V_37 -> V_34 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
int F_34 ( struct V_50 * V_54 ,
struct V_50 * V_55 )
{
int V_11 ;
V_11 = F_28 ( & V_54 -> V_52 , & V_55 -> V_52 ) ;
if ( V_11 )
return V_11 ;
return F_28 ( & V_54 -> V_53 , & V_55 -> V_53 ) ;
}
int F_35 ( struct V_50 * V_51 ,
const char * V_56 )
{
struct V_36 * V_37 , * V_57 = NULL ;
struct V_58 * V_59 ;
int V_11 ;
V_11 = F_34 ( V_51 , & V_60 ) ;
if ( V_11 )
return V_11 ;
V_11 = - V_24 ;
F_30 (res, &resources->iomem, list) {
V_59 = F_36 ( V_37 -> V_34 , V_37 -> V_28 - V_37 -> V_34 ,
V_56 ) ;
if ( ! V_59 ) {
F_37 ( V_61
L_2 ,
( unsigned long long ) V_37 -> V_34 ,
( unsigned long long ) V_37 -> V_28 ) ;
V_57 = V_37 ;
goto V_62;
}
}
F_30 (res, &resources->ioport, list) {
V_59 = F_38 ( V_37 -> V_34 , V_37 -> V_28 - V_37 -> V_34 , V_56 ) ;
if ( ! V_59 ) {
F_37 ( V_61
L_3 ,
( unsigned long long ) V_37 -> V_34 ,
( unsigned long long ) V_37 -> V_28 ) ;
V_57 = V_37 ;
goto V_63;
}
}
V_11 = F_33 ( & V_60 , V_51 ) ;
if ( V_11 ) {
F_37 ( V_61 L_4 ) ;
goto V_63;
}
return 0 ;
V_63:
F_30 (res, &resources->ioport, list) {
if ( V_37 == V_57 )
break;
F_39 ( V_37 -> V_34 , V_37 -> V_28 - V_37 -> V_34 ) ;
}
V_57 = NULL ;
V_62:
F_30 (res, &resources->iomem, list) {
if ( V_37 == V_57 )
break;
F_40 ( V_37 -> V_34 , V_37 -> V_28 - V_37 -> V_34 ) ;
}
return V_11 ;
}
void F_41 ( struct V_50 * V_51 )
{
int V_11 ;
struct V_36 * V_37 ;
F_30 (res, &resources->iomem, list)
F_40 ( V_37 -> V_34 , V_37 -> V_28 - V_37 -> V_34 ) ;
F_30 (res, &resources->ioport, list)
F_39 ( V_37 -> V_34 , V_37 -> V_28 - V_37 -> V_34 ) ;
V_11 = F_34 ( & V_60 , V_51 ) ;
if ( V_11 )
F_37 ( V_61 L_5 ) ;
}
static int F_42 ( struct V_64 * V_65 , T_2 * V_66 )
{
T_1 V_67 , V_68 ;
V_67 = V_65 -> V_69 ;
V_68 = V_65 -> V_68 ;
memcpy ( V_66 , & V_65 -> V_70 , sizeof( * V_66 ) ) ;
if ( ! * V_66 ) {
F_12 (FW_BUG APEI_PFX
L_6 ,
*paddr, width, space_id) ;
return - V_24 ;
}
if ( ( V_67 != 8 ) && ( V_67 != 16 ) && ( V_67 != 32 ) && ( V_67 != 64 ) ) {
F_12 (FW_BUG APEI_PFX
L_7 ,
*paddr, width, space_id) ;
return - V_24 ;
}
if ( V_68 != V_71 &&
V_68 != V_72 ) {
F_12 (FW_BUG APEI_PFX
L_8 ,
*paddr, width, space_id) ;
return - V_24 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_6 * V_9 ,
void * V_27 )
{
struct V_50 * V_51 = V_27 ;
struct V_64 * V_65 = & V_9 -> V_12 ;
T_3 V_29 = V_9 -> V_23 ;
T_2 V_66 ;
int V_11 ;
if ( ! ( V_2 -> V_4 [ V_29 ] . V_16 & V_30 ) )
return 0 ;
V_11 = F_42 ( V_65 , & V_66 ) ;
if ( V_11 )
return V_11 ;
switch ( V_65 -> V_68 ) {
case V_71 :
return F_20 ( & V_51 -> V_52 , V_66 ,
V_65 -> V_69 / 8 ) ;
case V_72 :
return F_20 ( & V_51 -> V_53 , V_66 ,
V_65 -> V_69 / 8 ) ;
default:
return - V_24 ;
}
}
int F_44 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
return F_13 ( V_2 , F_43 ,
V_51 , NULL ) ;
}
struct V_73 * F_45 ( void )
{
static struct V_73 * V_74 ;
if ( ! V_74 )
V_74 = F_46 ( L_9 , NULL ) ;
return V_74 ;
}
