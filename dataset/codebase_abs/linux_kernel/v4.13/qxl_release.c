static const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_2 )
{
return L_2 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return true ;
}
static long F_4 ( struct V_1 * V_2 , bool V_3 ,
signed long V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 , V_10 = 0 ;
bool V_11 ;
unsigned long V_12 , V_13 = V_14 + V_4 ;
V_6 = F_5 ( V_2 -> V_15 , struct V_5 , V_16 ) ;
V_8 = F_5 ( V_2 , struct V_7 , V_17 ) ;
V_11 = V_8 -> type == V_18 ;
V_19:
V_10 ++ ;
if ( F_6 ( V_2 ) )
goto V_20;
F_7 ( V_6 ) ;
for ( V_9 = 0 ; V_9 < 11 ; V_9 ++ ) {
if ( ! F_8 ( V_6 , true ) )
break;
if ( F_6 ( V_2 ) )
goto V_20;
}
if ( F_6 ( V_2 ) )
goto V_20;
if ( V_11 || V_10 < 4 ) {
if ( V_10 > 2 )
F_9 ( 500 , 1000 ) ;
if ( F_10 ( V_14 , V_13 ) )
return 0 ;
if ( V_11 && V_10 > 300 ) {
F_11 ( V_2 , L_3
L_4 ,
V_2 -> V_21 & ~ 0xf0000000 , V_10 ) ;
goto V_20;
}
goto V_19;
}
V_20:
V_12 = V_14 ;
if ( F_10 ( V_12 , V_13 ) )
return 0 ;
return V_13 - V_12 ;
}
static int
F_12 ( struct V_5 * V_6 , int type ,
struct V_7 * * V_22 )
{
struct V_7 * V_8 ;
int V_23 ;
T_1 V_24 = sizeof( * V_8 ) ;
V_8 = F_13 ( V_24 , V_25 ) ;
if ( ! V_8 ) {
F_14 ( L_5 ) ;
return - V_26 ;
}
V_8 -> V_17 . V_27 = NULL ;
V_8 -> type = type ;
V_8 -> V_28 = 0 ;
V_8 -> V_29 = 0 ;
F_15 ( & V_8 -> V_30 ) ;
F_16 ( V_25 ) ;
F_17 ( & V_6 -> V_31 ) ;
V_23 = F_18 ( & V_6 -> V_32 , V_8 , 1 , 0 , V_33 ) ;
V_8 -> V_17 . V_34 = ++ V_6 -> V_35 ;
F_19 ( & V_6 -> V_31 ) ;
F_20 () ;
if ( V_23 < 0 ) {
F_21 ( V_8 ) ;
* V_22 = NULL ;
return V_23 ;
}
* V_22 = V_8 ;
F_22 ( V_6 , L_6 , V_23 ) ;
V_8 -> V_36 = V_23 ;
return V_23 ;
}
static void
F_23 ( struct V_7 * V_8 )
{
while ( ! F_24 ( & V_8 -> V_30 ) ) {
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_38 = F_5 ( V_8 -> V_30 . V_41 ,
struct V_37 , V_42 . V_43 ) ;
V_40 = F_25 ( V_38 -> V_42 . V_40 ) ;
F_26 ( & V_40 ) ;
F_27 ( & V_38 -> V_42 . V_43 ) ;
F_21 ( V_38 ) ;
}
}
void
F_28 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_22 ( V_6 , L_7 , V_8 -> V_36 ,
V_8 -> type ) ;
if ( V_8 -> V_29 )
F_29 ( V_6 , V_8 -> V_29 ) ;
F_17 ( & V_6 -> V_31 ) ;
F_30 ( & V_6 -> V_32 , V_8 -> V_36 ) ;
F_19 ( & V_6 -> V_31 ) ;
if ( V_8 -> V_17 . V_27 ) {
F_31 ( F_24 ( & V_8 -> V_30 ) ) ;
F_23 ( V_8 ) ;
F_32 ( & V_8 -> V_17 ) ;
F_33 ( & V_8 -> V_17 ) ;
} else {
F_23 ( V_8 ) ;
F_21 ( V_8 ) ;
}
}
static int F_34 ( struct V_5 * V_6 ,
struct V_39 * * V_40 )
{
return F_35 ( V_6 , V_44 , false , true ,
V_45 , NULL , V_40 ) ;
}
int F_36 ( struct V_7 * V_8 , struct V_39 * V_40 )
{
struct V_37 * V_38 ;
F_37 (entry, &release->bos, tv.head) {
if ( V_38 -> V_42 . V_40 == & V_40 -> V_46 )
return 0 ;
}
V_38 = F_13 ( sizeof( struct V_37 ) , V_25 ) ;
if ( ! V_38 )
return - V_26 ;
F_38 ( V_40 ) ;
V_38 -> V_42 . V_40 = & V_40 -> V_46 ;
V_38 -> V_42 . V_47 = false ;
F_39 ( & V_38 -> V_42 . V_43 , & V_8 -> V_30 ) ;
return 0 ;
}
static int F_40 ( struct V_39 * V_40 )
{
int V_22 ;
if ( ! V_40 -> V_48 ) {
F_41 ( V_40 , V_40 -> type , false ) ;
V_22 = F_42 ( & V_40 -> V_46 , & V_40 -> V_49 ,
true , false ) ;
if ( V_22 )
return V_22 ;
}
V_22 = F_43 ( V_40 -> V_46 . V_50 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_44 ( V_40 -> V_51 . V_52 -> V_53 , V_40 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
int F_45 ( struct V_7 * V_8 , bool V_54 )
{
int V_22 ;
struct V_37 * V_38 ;
if ( F_46 ( & V_8 -> V_30 ) )
return 0 ;
V_22 = F_47 ( & V_8 -> V_55 , & V_8 -> V_30 ,
! V_54 , NULL ) ;
if ( V_22 )
return V_22 ;
F_37 (entry, &release->bos, tv.head) {
struct V_39 * V_40 = F_25 ( V_38 -> V_42 . V_40 ) ;
V_22 = F_40 ( V_40 ) ;
if ( V_22 ) {
F_48 ( & V_8 -> V_55 , & V_8 -> V_30 ) ;
return V_22 ;
}
}
return 0 ;
}
void F_49 ( struct V_7 * V_8 )
{
if ( F_46 ( & V_8 -> V_30 ) )
return;
F_48 ( & V_8 -> V_55 , & V_8 -> V_30 ) ;
}
int F_50 ( struct V_5 * V_6 ,
enum V_56 V_57 ,
struct V_7 * V_58 ,
struct V_7 * * V_8 )
{
if ( V_57 == V_59 && V_58 ) {
int V_60 ;
struct V_37 * V_38 = F_51 ( & V_58 -> V_30 , struct V_37 , V_42 . V_43 ) ;
struct V_39 * V_40 ;
union V_61 * V_62 ;
V_60 = F_12 ( V_6 , V_63 , V_8 ) ;
if ( V_60 < 0 )
return V_60 ;
V_40 = F_25 ( V_38 -> V_42 . V_40 ) ;
( * V_8 ) -> V_28 = V_58 -> V_28 + 64 ;
F_36 ( * V_8 , V_40 ) ;
V_62 = F_52 ( V_6 , * V_8 ) ;
V_62 -> V_36 = V_60 ;
F_53 ( V_6 , * V_8 , V_62 ) ;
return 0 ;
}
return F_54 ( V_6 , sizeof( struct V_64 ) ,
V_63 , V_8 , NULL ) ;
}
int F_54 ( struct V_5 * V_6 , unsigned long V_24 ,
int type , struct V_7 * * V_8 ,
struct V_39 * * V_65 )
{
struct V_39 * V_40 ;
int V_60 ;
int V_22 = 0 ;
union V_61 * V_62 ;
int V_66 ;
if ( type == V_18 )
V_66 = 0 ;
else if ( type == V_63 )
V_66 = 1 ;
else if ( type == V_67 )
V_66 = 2 ;
else {
F_14 ( L_8 , type ) ;
return - V_68 ;
}
V_60 = F_12 ( V_6 , type , V_8 ) ;
if ( V_60 < 0 ) {
if ( V_65 )
* V_65 = NULL ;
return V_60 ;
}
F_55 ( & V_6 -> V_69 ) ;
if ( V_6 -> V_70 [ V_66 ] + 1 >= V_71 [ V_66 ] ) {
F_26 ( & V_6 -> V_72 [ V_66 ] ) ;
V_6 -> V_70 [ V_66 ] = 0 ;
V_6 -> V_72 [ V_66 ] = NULL ;
}
if ( ! V_6 -> V_72 [ V_66 ] ) {
V_22 = F_34 ( V_6 , & V_6 -> V_72 [ V_66 ] ) ;
if ( V_22 ) {
F_56 ( & V_6 -> V_69 ) ;
F_28 ( V_6 , * V_8 ) ;
return V_22 ;
}
}
V_40 = F_38 ( V_6 -> V_72 [ V_66 ] ) ;
( * V_8 ) -> V_28 = V_6 -> V_70 [ V_66 ] * V_73 [ V_66 ] ;
V_6 -> V_70 [ V_66 ] ++ ;
if ( V_65 )
* V_65 = V_40 ;
F_56 ( & V_6 -> V_69 ) ;
V_22 = F_36 ( * V_8 , V_40 ) ;
F_26 ( & V_40 ) ;
if ( V_22 ) {
F_28 ( V_6 , * V_8 ) ;
return V_22 ;
}
V_62 = F_52 ( V_6 , * V_8 ) ;
V_62 -> V_36 = V_60 ;
F_53 ( V_6 , * V_8 , V_62 ) ;
return V_22 ;
}
struct V_7 * F_57 ( struct V_5 * V_6 ,
T_2 V_36 )
{
struct V_7 * V_8 ;
F_17 ( & V_6 -> V_31 ) ;
V_8 = F_58 ( & V_6 -> V_32 , V_36 ) ;
F_19 ( & V_6 -> V_31 ) ;
if ( ! V_8 ) {
F_14 ( L_9 ) ;
return NULL ;
}
return V_8 ;
}
union V_61 * F_52 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
void * V_74 ;
union V_61 * V_62 ;
struct V_37 * V_38 = F_51 ( & V_8 -> V_30 , struct V_37 , V_42 . V_43 ) ;
struct V_39 * V_40 = F_25 ( V_38 -> V_42 . V_40 ) ;
V_74 = F_59 ( V_6 , V_40 , V_8 -> V_28 & V_44 ) ;
if ( ! V_74 )
return NULL ;
V_62 = V_74 + ( V_8 -> V_28 & ~ V_44 ) ;
return V_62 ;
}
void F_53 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
union V_61 * V_62 )
{
struct V_37 * V_38 = F_51 ( & V_8 -> V_30 , struct V_37 , V_42 . V_43 ) ;
struct V_39 * V_40 = F_25 ( V_38 -> V_42 . V_40 ) ;
void * V_74 ;
V_74 = ( ( void * ) V_62 ) - ( V_8 -> V_28 & ~ V_44 ) ;
F_60 ( V_6 , V_40 , V_74 ) ;
}
void F_61 ( struct V_7 * V_8 )
{
struct V_75 * V_40 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_39 * V_82 ;
struct V_83 * V_38 ;
struct V_5 * V_6 ;
if ( F_46 ( & V_8 -> V_30 ) || F_24 ( & V_8 -> V_30 ) )
return;
V_40 = F_51 ( & V_8 -> V_30 , struct V_83 , V_43 ) -> V_40 ;
V_79 = V_40 -> V_79 ;
V_6 = F_5 ( V_79 , struct V_5 , V_84 . V_79 ) ;
F_62 ( & V_8 -> V_17 , & V_85 , & V_6 -> V_16 ,
V_8 -> V_36 | 0xf0000000 , V_8 -> V_17 . V_34 ) ;
F_63 ( & V_8 -> V_17 ) ;
V_81 = V_79 -> V_81 ;
V_77 = V_40 -> V_77 ;
F_17 ( & V_77 -> V_86 ) ;
F_37 (entry, &release->bos, head) {
V_40 = V_38 -> V_40 ;
V_82 = F_25 ( V_40 ) ;
F_64 ( V_40 -> V_50 , & V_8 -> V_17 ) ;
F_65 ( V_40 ) ;
F_66 ( V_40 ) ;
}
F_19 ( & V_77 -> V_86 ) ;
F_67 ( & V_8 -> V_55 ) ;
}
