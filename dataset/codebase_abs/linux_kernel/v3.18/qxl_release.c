static const char * F_1 ( struct V_1 * V_1 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_1 )
{
return L_2 ;
}
static bool F_3 ( struct V_1 * V_1 )
{
return true ;
}
static long F_4 ( struct V_1 * V_1 , bool V_2 , signed long V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 = 0 , V_9 = 0 ;
bool V_10 ;
unsigned long V_11 , V_12 = V_13 + V_3 ;
V_5 = F_5 ( V_1 -> V_14 , struct V_4 , V_15 ) ;
V_7 = F_5 ( V_1 , struct V_6 , V_16 ) ;
V_10 = V_7 -> type == V_17 ;
V_18:
V_9 ++ ;
if ( F_6 ( V_1 ) )
goto V_19;
F_7 ( V_5 ) ;
for ( V_8 = 0 ; V_8 < 11 ; V_8 ++ ) {
if ( ! F_8 ( V_5 , true ) )
break;
if ( F_6 ( V_1 ) )
goto V_19;
}
if ( F_6 ( V_1 ) )
goto V_19;
if ( V_10 || V_9 < 4 ) {
if ( V_9 > 2 )
F_9 ( 500 , 1000 ) ;
if ( F_10 ( V_13 , V_12 ) )
return 0 ;
if ( V_10 && V_9 > 300 ) {
F_11 ( V_1 , L_3
L_4 ,
V_1 -> V_20 & ~ 0xf0000000 , V_9 ) ;
goto V_19;
}
goto V_18;
}
V_19:
V_11 = V_13 ;
if ( F_10 ( V_11 , V_12 ) )
return 0 ;
return V_12 - V_11 ;
}
static T_1
F_12 ( struct V_4 * V_5 , int type ,
struct V_6 * * V_21 )
{
struct V_6 * V_7 ;
int V_22 ;
T_2 V_23 = sizeof( * V_7 ) ;
V_7 = F_13 ( V_23 , V_24 ) ;
if ( ! V_7 ) {
F_14 ( L_5 ) ;
return 0 ;
}
V_7 -> V_16 . V_25 = NULL ;
V_7 -> type = type ;
V_7 -> V_26 = 0 ;
V_7 -> V_27 = 0 ;
F_15 ( & V_7 -> V_28 ) ;
F_16 ( V_24 ) ;
F_17 ( & V_5 -> V_29 ) ;
V_22 = F_18 ( & V_5 -> V_30 , V_7 , 1 , 0 , V_31 ) ;
V_7 -> V_16 . V_32 = ++ V_5 -> V_33 ;
F_19 ( & V_5 -> V_29 ) ;
F_20 () ;
if ( V_22 < 0 ) {
F_21 ( V_7 ) ;
* V_21 = NULL ;
return V_22 ;
}
* V_21 = V_7 ;
F_22 ( V_5 , L_6 , V_22 ) ;
V_7 -> V_34 = V_22 ;
return V_22 ;
}
static void
F_23 ( struct V_6 * V_7 )
{
while ( ! F_24 ( & V_7 -> V_28 ) ) {
struct V_35 * V_36 ;
struct V_37 * V_38 ;
V_36 = F_5 ( V_7 -> V_28 . V_39 ,
struct V_35 , V_40 . V_41 ) ;
V_38 = F_25 ( V_36 -> V_40 . V_38 ) ;
F_26 ( & V_38 ) ;
F_27 ( & V_36 -> V_40 . V_41 ) ;
F_21 ( V_36 ) ;
}
}
void
F_28 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
F_22 ( V_5 , L_7 , V_7 -> V_34 ,
V_7 -> type ) ;
if ( V_7 -> V_27 )
F_29 ( V_5 , V_7 -> V_27 ) ;
F_17 ( & V_5 -> V_29 ) ;
F_30 ( & V_5 -> V_30 , V_7 -> V_34 ) ;
F_19 ( & V_5 -> V_29 ) ;
if ( V_7 -> V_16 . V_25 ) {
F_31 ( F_24 ( & V_7 -> V_28 ) ) ;
F_23 ( V_7 ) ;
F_32 ( & V_7 -> V_16 ) ;
F_33 ( & V_7 -> V_16 ) ;
} else {
F_23 ( V_7 ) ;
F_21 ( V_7 ) ;
}
}
static int F_34 ( struct V_4 * V_5 ,
struct V_37 * * V_38 )
{
int V_21 ;
V_21 = F_35 ( V_5 , V_42 , false , true ,
V_43 , NULL ,
V_38 ) ;
return V_21 ;
}
int F_36 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
struct V_35 * V_36 ;
F_37 (entry, &release->bos, tv.head) {
if ( V_36 -> V_40 . V_38 == & V_38 -> V_44 )
return 0 ;
}
V_36 = F_13 ( sizeof( struct V_35 ) , V_24 ) ;
if ( ! V_36 )
return - V_45 ;
F_38 ( V_38 ) ;
V_36 -> V_40 . V_38 = & V_38 -> V_44 ;
V_36 -> V_40 . V_46 = false ;
F_39 ( & V_36 -> V_40 . V_41 , & V_7 -> V_28 ) ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 )
{
int V_21 ;
if ( ! V_38 -> V_47 ) {
F_41 ( V_38 , V_38 -> type , false ) ;
V_21 = F_42 ( & V_38 -> V_44 , & V_38 -> V_48 ,
true , false ) ;
if ( V_21 )
return V_21 ;
}
V_21 = F_43 ( V_38 -> V_44 . V_49 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_44 ( V_38 -> V_50 . V_51 -> V_52 , V_38 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
int F_45 ( struct V_6 * V_7 , bool V_53 )
{
int V_21 ;
struct V_35 * V_36 ;
if ( F_46 ( & V_7 -> V_28 ) )
return 0 ;
V_21 = F_47 ( & V_7 -> V_54 , & V_7 -> V_28 , ! V_53 ) ;
if ( V_21 )
return V_21 ;
F_37 (entry, &release->bos, tv.head) {
struct V_37 * V_38 = F_25 ( V_36 -> V_40 . V_38 ) ;
V_21 = F_40 ( V_38 ) ;
if ( V_21 ) {
F_48 ( & V_7 -> V_54 , & V_7 -> V_28 ) ;
return V_21 ;
}
}
return 0 ;
}
void F_49 ( struct V_6 * V_7 )
{
if ( F_46 ( & V_7 -> V_28 ) )
return;
F_48 ( & V_7 -> V_54 , & V_7 -> V_28 ) ;
}
int F_50 ( struct V_4 * V_5 ,
enum V_55 V_56 ,
struct V_6 * V_57 ,
struct V_6 * * V_7 )
{
if ( V_56 == V_58 && V_57 ) {
int V_59 ;
struct V_35 * V_36 = F_51 ( & V_57 -> V_28 , struct V_35 , V_40 . V_41 ) ;
struct V_37 * V_38 ;
union V_60 * V_61 ;
V_59 = F_12 ( V_5 , V_62 , V_7 ) ;
if ( V_59 < 0 )
return V_59 ;
V_38 = F_38 ( F_25 ( V_36 -> V_40 . V_38 ) ) ;
( * V_7 ) -> V_26 = V_57 -> V_26 + 64 ;
F_36 ( * V_7 , V_38 ) ;
V_61 = F_52 ( V_5 , * V_7 ) ;
V_61 -> V_34 = V_59 ;
F_53 ( V_5 , * V_7 , V_61 ) ;
F_26 ( & V_38 ) ;
return 0 ;
}
return F_54 ( V_5 , sizeof( struct V_63 ) ,
V_62 , V_7 , NULL ) ;
}
int F_54 ( struct V_4 * V_5 , unsigned long V_23 ,
int type , struct V_6 * * V_7 ,
struct V_37 * * V_64 )
{
struct V_37 * V_38 ;
int V_59 ;
int V_21 = 0 ;
union V_60 * V_61 ;
int V_65 ;
if ( type == V_17 )
V_65 = 0 ;
else if ( type == V_62 )
V_65 = 1 ;
else if ( type == V_66 )
V_65 = 2 ;
else {
F_14 ( L_8 , type ) ;
return - V_67 ;
}
V_59 = F_12 ( V_5 , type , V_7 ) ;
if ( V_59 < 0 ) {
if ( V_64 )
* V_64 = NULL ;
return V_59 ;
}
F_55 ( & V_5 -> V_68 ) ;
if ( V_5 -> V_69 [ V_65 ] + 1 >= V_70 [ V_65 ] ) {
F_26 ( & V_5 -> V_71 [ V_65 ] ) ;
V_5 -> V_69 [ V_65 ] = 0 ;
V_5 -> V_71 [ V_65 ] = NULL ;
}
if ( ! V_5 -> V_71 [ V_65 ] ) {
V_21 = F_34 ( V_5 , & V_5 -> V_71 [ V_65 ] ) ;
if ( V_21 ) {
F_56 ( & V_5 -> V_68 ) ;
return V_21 ;
}
}
V_38 = F_38 ( V_5 -> V_71 [ V_65 ] ) ;
( * V_7 ) -> V_26 = V_5 -> V_69 [ V_65 ] * V_72 [ V_65 ] ;
V_5 -> V_69 [ V_65 ] ++ ;
if ( V_64 )
* V_64 = V_38 ;
F_56 ( & V_5 -> V_68 ) ;
F_36 ( * V_7 , V_38 ) ;
V_61 = F_52 ( V_5 , * V_7 ) ;
V_61 -> V_34 = V_59 ;
F_53 ( V_5 , * V_7 , V_61 ) ;
F_26 ( & V_38 ) ;
return V_21 ;
}
struct V_6 * F_57 ( struct V_4 * V_5 ,
T_1 V_34 )
{
struct V_6 * V_7 ;
F_17 ( & V_5 -> V_29 ) ;
V_7 = F_58 ( & V_5 -> V_30 , V_34 ) ;
F_19 ( & V_5 -> V_29 ) ;
if ( ! V_7 ) {
F_14 ( L_9 ) ;
return NULL ;
}
return V_7 ;
}
union V_60 * F_52 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
void * V_73 ;
union V_60 * V_61 ;
struct V_35 * V_36 = F_51 ( & V_7 -> V_28 , struct V_35 , V_40 . V_41 ) ;
struct V_37 * V_38 = F_25 ( V_36 -> V_40 . V_38 ) ;
V_73 = F_59 ( V_5 , V_38 , V_7 -> V_26 & V_42 ) ;
if ( ! V_73 )
return NULL ;
V_61 = V_73 + ( V_7 -> V_26 & ~ V_42 ) ;
return V_61 ;
}
void F_53 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
union V_60 * V_61 )
{
struct V_35 * V_36 = F_51 ( & V_7 -> V_28 , struct V_35 , V_40 . V_41 ) ;
struct V_37 * V_38 = F_25 ( V_36 -> V_40 . V_38 ) ;
void * V_73 ;
V_73 = ( ( void * ) V_61 ) - ( V_7 -> V_26 & ~ V_42 ) ;
F_60 ( V_5 , V_38 , V_73 ) ;
}
void F_61 ( struct V_6 * V_7 )
{
struct V_74 * V_38 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_37 * V_81 ;
struct V_82 * V_36 ;
struct V_4 * V_5 ;
if ( F_46 ( & V_7 -> V_28 ) || F_24 ( & V_7 -> V_28 ) )
return;
V_38 = F_51 ( & V_7 -> V_28 , struct V_82 , V_41 ) -> V_38 ;
V_78 = V_38 -> V_78 ;
V_5 = F_5 ( V_78 , struct V_4 , V_83 . V_78 ) ;
F_62 ( & V_7 -> V_16 , & V_84 , & V_5 -> V_15 ,
V_7 -> V_34 | 0xf0000000 , V_7 -> V_16 . V_32 ) ;
F_63 ( & V_7 -> V_16 ) ;
V_80 = V_78 -> V_80 ;
V_76 = V_38 -> V_76 ;
F_17 ( & V_76 -> V_85 ) ;
F_37 (entry, &release->bos, head) {
V_38 = V_36 -> V_38 ;
V_81 = F_25 ( V_38 ) ;
F_64 ( V_38 -> V_49 , & V_7 -> V_16 ) ;
F_65 ( V_38 ) ;
F_66 ( V_38 ) ;
}
F_19 ( & V_76 -> V_85 ) ;
F_67 ( & V_7 -> V_54 ) ;
}
