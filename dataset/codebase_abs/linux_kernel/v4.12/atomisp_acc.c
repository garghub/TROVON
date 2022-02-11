static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_5 = F_3 ( V_2 ) ;
if ( ! V_3 -> V_5 ) {
F_4 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
static void F_5 ( struct V_1 * V_3 )
{
F_6 ( V_3 -> V_5 ) ;
F_4 ( V_3 ) ;
}
static struct V_1 *
F_7 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_1 * V_3 ;
F_8 (acc_fw, &asd->acc.fw, list)
if ( V_3 -> V_8 == V_8 )
return V_3 ;
return NULL ;
}
static struct V_9 * F_9 ( struct V_6 * V_7 ,
unsigned long V_10 , T_1 V_11 )
{
struct V_9 * V_9 ;
F_8 (atomisp_map, &asd->acc.memory_maps, list) {
if ( V_9 -> V_12 == V_10 &&
V_9 -> V_11 == V_11 )
return V_9 ;
}
return NULL ;
}
static int F_10 ( struct V_6 * V_7 )
{
int V_13 ;
V_13 = F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
return V_13 ;
}
void F_13 ( struct V_14 * V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_17 ; V_16 ++ )
F_14 ( & V_15 -> V_7 [ V_16 ] . V_18 . V_19 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_3 , * V_20 ;
struct V_9 * V_9 , * V_21 ;
if ( V_7 -> V_18 . V_22 )
F_10 ( V_7 ) ;
F_16 (acc_fw, ta, &asd->acc.fw, list) {
F_17 ( & V_3 -> V_23 ) ;
F_18 ( & V_7 -> V_18 . V_19 , V_3 -> V_8 ) ;
F_5 ( V_3 ) ;
}
F_16 (atomisp_map, tm, &asd->acc.memory_maps, list) {
F_17 ( & V_9 -> V_23 ) ;
F_19 ( V_9 -> V_12 ) ;
F_4 ( V_9 ) ;
}
}
int F_20 ( struct V_6 * V_7 ,
struct V_24 * V_25 )
{
static const unsigned int V_26 =
V_27 | V_28 |
V_29 |
V_30 | V_31 ;
struct V_1 * V_3 ;
int V_8 ;
if ( ! V_25 -> V_32 || V_25 -> V_33 < sizeof( * V_3 -> V_5 ) )
return - V_34 ;
if ( ! ( V_25 -> V_35 & V_26 ) )
return - V_34 ;
if ( V_25 -> V_35 & ~ V_26 )
return - V_34 ;
if ( V_25 -> type < V_36 ||
V_25 -> type > V_37 )
return - V_34 ;
if ( V_7 -> V_18 . V_22 || V_7 -> V_18 . V_38 )
return - V_39 ;
V_3 = F_1 ( V_25 -> V_33 ) ;
if ( ! V_3 )
return - V_40 ;
if ( F_21 ( V_3 -> V_5 , V_25 -> V_32 , V_25 -> V_33 ) ) {
F_5 ( V_3 ) ;
return - V_41 ;
}
if ( ! F_22 ( & V_7 -> V_18 . V_19 , V_4 ) ||
F_23 ( & V_7 -> V_18 . V_19 , 1 , & V_8 ) ) {
F_5 ( V_3 ) ;
return - V_42 ;
}
V_25 -> V_43 = V_8 ;
V_3 -> V_8 = V_8 ;
V_3 -> V_35 = V_25 -> V_35 ;
V_3 -> type = V_25 -> type ;
V_3 -> V_5 -> V_8 = V_8 ;
if ( V_3 -> V_5 -> type == V_44 ) {
static const int V_45 [] = {
[ V_36 ] =
V_46 ,
[ V_47 ] =
V_48 ,
[ V_37 ] =
V_49 ,
} ;
V_3 -> V_5 -> V_50 . V_15 . type = V_45 [ V_3 -> type ] ;
}
F_24 ( & V_3 -> V_23 , & V_7 -> V_18 . V_5 ) ;
return 0 ;
}
int F_25 ( struct V_6 * V_7 ,
struct V_51 * V_25 )
{
struct V_24 V_52 = { 0 } ;
int V_53 ;
V_52 . V_35 = V_31 ;
V_52 . type = V_37 ;
V_52 . V_33 = V_25 -> V_33 ;
V_52 . V_32 = V_25 -> V_32 ;
V_53 = F_20 ( V_7 , & V_52 ) ;
V_25 -> V_43 = V_52 . V_43 ;
return V_53 ;
}
int F_26 ( struct V_6 * V_7 , unsigned int * V_8 )
{
struct V_1 * V_3 ;
if ( V_7 -> V_18 . V_22 || V_7 -> V_18 . V_38 )
return - V_39 ;
V_3 = F_7 ( V_7 , * V_8 ) ;
if ( ! V_3 )
return - V_34 ;
F_17 ( & V_3 -> V_23 ) ;
F_18 ( & V_7 -> V_18 . V_19 , V_3 -> V_8 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
int F_27 ( struct V_6 * V_7 , unsigned int * V_8 )
{
struct V_14 * V_15 = V_7 -> V_15 ;
struct V_1 * V_3 ;
int V_13 ;
unsigned int V_54 ;
if ( V_7 -> V_18 . V_22 || V_7 -> V_18 . V_38 )
return - V_39 ;
F_28 () ;
V_13 = F_29 ( V_7 ) ;
if ( V_13 )
return V_13 ;
V_54 = 0 ;
F_8 (acc_fw, &asd->acc.fw, list) {
if ( * V_8 != 0 && * V_8 != V_3 -> V_8 )
continue;
if ( V_3 -> type != V_37 )
continue;
V_13 = F_30 ( V_7 , V_3 -> V_5 , V_54 ) ;
if ( V_13 < 0 ) {
F_31 ( V_15 -> V_55 , L_1 ) ;
goto V_56;
}
V_13 = F_32 ( V_3 ) ;
if ( V_13 < 0 ) {
F_31 ( V_15 -> V_55 , L_2 ) ;
goto V_56;
}
V_54 ++ ;
}
if ( V_54 < 1 ) {
F_31 ( V_15 -> V_55 , L_3 , V_57 ) ;
V_13 = - V_34 ;
goto V_56;
}
V_13 = F_33 ( V_7 ) ;
if ( V_13 ) {
F_31 ( V_15 -> V_55 , L_4 ,
V_57 ) ;
goto V_56;
}
return 0 ;
V_56:
F_12 ( V_7 ) ;
return V_13 ;
}
int F_34 ( struct V_6 * V_7 , unsigned int * V_8 )
{
struct V_14 * V_15 = V_7 -> V_15 ;
int V_13 ;
if ( ! V_7 -> V_18 . V_22 )
return - V_58 ;
if ( * V_8 && ! F_7 ( V_7 , * V_8 ) )
return - V_34 ;
V_13 = F_35 ( V_7 ) ;
if ( F_10 ( V_7 ) == - V_59 ) {
F_36 ( V_15 ) ;
return - V_34 ;
}
return V_13 ;
}
void F_37 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_60 V_61 = { 0 } ;
V_61 . type = V_62 ;
V_61 . V_63 . V_64 . V_65 = F_38 ( & V_7 -> V_66 ) ;
V_61 . V_67 = V_8 ;
F_39 ( V_7 -> V_68 . V_69 , & V_61 ) ;
}
int F_40 ( struct V_6 * V_7 , struct F_40 * V_70 )
{
struct V_9 * V_9 ;
T_2 V_71 ;
int V_72 ;
if ( V_70 -> V_10 )
return - V_34 ;
if ( V_7 -> V_18 . V_22 )
return - V_39 ;
if ( V_70 -> V_73 ) {
if ( ( unsigned long ) V_70 -> V_73 & ~ V_74 ) {
F_31 ( V_7 -> V_15 -> V_55 ,
L_5 ,
V_57 , V_70 -> V_73 ) ;
return - V_34 ;
}
V_72 = F_41 ( V_70 -> V_11 , V_75 ) ;
V_71 = F_42 (
V_70 -> V_11 , V_70 -> V_73 ,
V_72 , V_76 ,
( V_70 -> V_35 & V_77 ) ) ;
} else {
if ( V_70 -> V_35 & V_77 )
V_71 = F_43 ( V_70 -> V_11 ) ;
else
V_71 = F_44 ( V_70 -> V_11 ) ;
}
if ( ! V_71 )
return - V_40 ;
V_9 = F_45 ( sizeof( * V_9 ) , V_4 ) ;
if ( ! V_9 ) {
F_19 ( V_71 ) ;
return - V_40 ;
}
V_9 -> V_12 = V_71 ;
V_9 -> V_11 = V_70 -> V_11 ;
F_46 ( & V_9 -> V_23 , & V_7 -> V_18 . V_78 ) ;
F_47 ( V_7 -> V_15 -> V_55 , L_6 ,
V_57 , V_70 -> V_73 , V_71 , V_70 -> V_11 ) ;
V_70 -> V_10 = V_71 ;
return 0 ;
}
int F_48 ( struct V_6 * V_7 , struct F_40 * V_70 )
{
struct V_9 * V_9 ;
if ( V_7 -> V_18 . V_22 )
return - V_39 ;
V_9 = F_9 ( V_7 , V_70 -> V_10 , V_70 -> V_11 ) ;
if ( ! V_9 )
return - V_34 ;
F_17 ( & V_9 -> V_23 ) ;
F_19 ( V_9 -> V_12 ) ;
F_4 ( V_9 ) ;
return 0 ;
}
int F_49 ( struct V_6 * V_7 ,
struct F_49 * V_79 )
{
struct V_1 * V_3 ;
if ( V_79 -> V_80 >= V_81 )
return - V_34 ;
if ( V_7 -> V_18 . V_22 )
return - V_39 ;
V_3 = F_7 ( V_7 , V_79 -> V_43 ) ;
if ( ! V_3 )
return - V_34 ;
if ( V_79 -> V_10 != 0 || V_79 -> V_11 != 0 ) {
if ( ! F_9 ( V_7 , V_79 -> V_10 , V_79 -> V_11 ) )
return - V_34 ;
}
V_3 -> args [ V_79 -> V_80 ] . V_11 = V_79 -> V_11 ;
V_3 -> args [ V_79 -> V_80 ] . V_10 = V_79 -> V_10 ;
F_47 ( V_7 -> V_15 -> V_55 , L_7 ,
V_57 , V_79 -> V_80 , ( void * ) V_79 -> V_10 ,
( unsigned long ) V_79 -> V_11 ) ;
return 0 ;
}
int F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_3 ;
bool V_82 = false ;
bool V_83 = V_7 -> V_84 -> V_85 &&
V_7 -> V_86 -> V_85 == V_87 ;
int V_13 = 0 , V_16 = - 1 ;
struct V_14 * V_15 = V_7 -> V_15 ;
if ( V_7 -> V_18 . V_22 || V_7 -> V_18 . V_38 )
return - V_39 ;
F_28 () ;
F_8 (acc_fw, &asd->acc.fw, list) {
if ( V_3 -> type != V_36 &&
V_3 -> type != V_47 )
continue;
for ( V_16 = 0 ; V_16 < F_51 ( V_88 ) ; V_16 ++ ) {
if ( ! V_83 &&
V_88 [ V_16 ] . V_89 ==
V_31 )
continue;
if ( V_3 -> V_35 & V_88 [ V_16 ] . V_89 ) {
V_13 = F_52 ( V_7 ,
V_3 -> V_5 ,
V_88 [ V_16 ] . V_90 ,
V_3 -> type ) ;
if ( V_13 )
goto error;
V_82 = true ;
}
}
V_13 = F_32 ( V_3 ) ;
if ( V_13 < 0 )
goto error;
}
if ( ! V_82 )
return V_13 ;
V_13 = F_53 ( V_7 ) ;
if ( V_13 ) {
F_31 ( V_15 -> V_55 , L_8 , V_57 ) ;
goto error;
}
V_7 -> V_18 . V_38 = true ;
return 0 ;
error:
while ( -- V_16 >= 0 ) {
if ( V_3 -> V_35 & V_88 [ V_16 ] . V_89 ) {
F_54 ( V_7 , V_3 -> V_5 ,
V_88 [ V_16 ] . V_90 ) ;
}
}
F_55 (acc_fw, &asd->acc.fw, list) {
if ( V_3 -> type != V_36 &&
V_3 -> type != V_47 )
continue;
for ( V_16 = F_51 ( V_88 ) - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( ! V_83 &&
V_88 [ V_16 ] . V_89 ==
V_31 )
continue;
if ( V_3 -> V_35 & V_88 [ V_16 ] . V_89 ) {
F_54 ( V_7 ,
V_3 -> V_5 ,
V_88 [ V_16 ] . V_90 ) ;
}
}
}
return V_13 ;
}
void F_56 ( struct V_6 * V_7 )
{
struct V_1 * V_3 ;
int V_16 ;
if ( ! V_7 -> V_18 . V_38 )
return;
F_57 (acc_fw, &asd->acc.fw, list) {
if ( V_3 -> type != V_36 &&
V_3 -> type != V_47 )
continue;
for ( V_16 = F_51 ( V_88 ) - 1 ; V_16 >= 0 ; V_16 -- ) {
if ( V_3 -> V_35 & V_88 [ V_16 ] . V_89 ) {
F_54 ( V_7 ,
V_3 -> V_5 ,
V_88 [ V_16 ] . V_90 ) ;
}
}
}
V_7 -> V_18 . V_38 = false ;
}
int F_58 ( struct V_6 * V_7 ,
struct V_91 * V_79 )
{
struct V_1 * V_3 ;
bool V_92 = ( V_79 -> V_35 & V_93 ) != 0 ;
struct V_94 * V_95 ;
enum V_96 V_53 ;
int V_16 ;
if ( ! V_7 -> V_18 . V_38 )
return - V_39 ;
if ( V_79 -> V_35 & ~ V_93 )
return - V_34 ;
V_3 = F_7 ( V_7 , V_79 -> V_43 ) ;
if ( ! V_3 )
return - V_34 ;
if ( V_92 )
F_28 () ;
for ( V_16 = 0 ; V_16 < F_51 ( V_88 ) ; V_16 ++ ) {
if ( V_3 -> V_35 & V_88 [ V_16 ] . V_89 ) {
V_95 = V_7 -> V_97 [ V_98 ] .
V_99 [ V_88 [ V_16 ] . V_90 ] ;
V_53 = F_59 ( V_95 , V_3 -> V_8 ,
V_92 ) ;
if ( V_53 != V_100 )
return - V_101 ;
}
}
if ( V_92 )
V_3 -> V_35 |= V_102 ;
else
V_3 -> V_35 &= ~ V_102 ;
return 0 ;
}
int F_60 ( struct V_6 * V_7 ,
struct V_91 * V_79 )
{
struct V_1 * V_3 ;
if ( ! V_7 -> V_18 . V_38 )
return - V_39 ;
V_3 = F_7 ( V_7 , V_79 -> V_43 ) ;
if ( ! V_3 )
return - V_34 ;
V_79 -> V_35 = V_3 -> V_35 ;
return 0 ;
}
