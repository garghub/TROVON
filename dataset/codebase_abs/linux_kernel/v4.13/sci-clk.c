static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_5 = V_4 -> V_6 & V_7 ;
bool V_8 = V_4 -> V_6 & V_9 ;
bool V_10 = V_4 -> V_6 & V_11 ;
return V_4 -> V_12 -> V_13 -> V_14 ( V_4 -> V_12 -> V_15 , V_4 -> V_16 ,
V_4 -> V_17 , V_5 ,
V_8 ,
V_10 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
V_18 = V_4 -> V_12 -> V_13 -> V_19 ( V_4 -> V_12 -> V_15 , V_4 -> V_16 ,
V_4 -> V_17 ) ;
if ( V_18 )
F_4 ( V_4 -> V_12 -> V_20 ,
L_1 ,
V_4 -> V_16 , V_4 -> V_17 , V_18 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_21 , V_22 ;
int V_18 ;
V_18 = V_4 -> V_12 -> V_13 -> V_23 ( V_4 -> V_12 -> V_15 , V_4 -> V_16 ,
V_4 -> V_17 , & V_21 ,
& V_22 ) ;
if ( V_18 ) {
F_4 ( V_4 -> V_12 -> V_20 ,
L_2 ,
V_4 -> V_16 , V_4 -> V_17 , V_18 ) ;
return 0 ;
}
return V_21 ;
}
static unsigned long F_6 ( struct V_1 * V_2 ,
unsigned long V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_25 ;
int V_18 ;
V_18 = V_4 -> V_12 -> V_13 -> V_26 ( V_4 -> V_12 -> V_15 , V_4 -> V_16 ,
V_4 -> V_17 , & V_25 ) ;
if ( V_18 ) {
F_4 ( V_4 -> V_12 -> V_20 ,
L_3 ,
V_4 -> V_16 , V_4 -> V_17 , V_18 ) ;
return 0 ;
}
return V_25 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 ;
T_1 V_29 ;
V_18 = V_4 -> V_12 -> V_13 -> V_30 ( V_4 -> V_12 -> V_15 ,
V_4 -> V_16 ,
V_4 -> V_17 ,
V_28 -> V_31 ,
V_28 -> V_32 ,
V_28 -> V_33 ,
& V_29 ) ;
if ( V_18 ) {
F_4 ( V_4 -> V_12 -> V_20 ,
L_4 ,
V_4 -> V_16 , V_4 -> V_17 , V_18 ) ;
return V_18 ;
}
V_28 -> V_32 = V_29 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_32 ,
unsigned long V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_12 -> V_13 -> V_34 ( V_4 -> V_12 -> V_15 , V_4 -> V_16 ,
V_4 -> V_17 , V_32 , V_32 , V_32 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_35 ;
int V_18 ;
V_18 = V_4 -> V_12 -> V_13 -> V_36 ( V_4 -> V_12 -> V_15 , V_4 -> V_16 ,
V_4 -> V_17 , & V_35 ) ;
if ( V_18 ) {
F_4 ( V_4 -> V_12 -> V_20 ,
L_5 ,
V_4 -> V_16 , V_4 -> V_17 , V_18 ) ;
return 0 ;
}
return V_35 - V_4 -> V_17 - 1 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_12 -> V_13 -> V_38 ( V_4 -> V_12 -> V_15 , V_4 -> V_16 ,
V_4 -> V_17 ,
V_37 + 1 + V_4 -> V_17 ) ;
}
static struct V_1 * F_11 ( struct V_39 * V_12 ,
T_3 V_16 , T_2 V_17 )
{
struct V_40 V_41 = { NULL } ;
struct V_3 * V_3 = NULL ;
char * V_42 = NULL ;
char * * V_43 = NULL ;
int V_44 ;
int V_18 ;
V_3 = F_12 ( V_12 -> V_20 , sizeof( * V_3 ) , V_45 ) ;
if ( ! V_3 )
return F_13 ( - V_46 ) ;
V_3 -> V_16 = V_16 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_12 = V_12 ;
V_18 = V_12 -> V_13 -> V_47 ( V_12 -> V_15 , V_16 ,
V_17 ,
& V_41 . V_48 ) ;
if ( V_18 )
goto V_49;
V_42 = F_14 ( V_45 , L_6 , F_15 ( V_12 -> V_20 ) ,
V_3 -> V_16 , V_3 -> V_17 ) ;
V_41 . V_42 = V_42 ;
if ( V_41 . V_48 < 2 )
V_41 . V_48 = 0 ;
if ( V_41 . V_48 ) {
V_43 = F_16 ( V_41 . V_48 , sizeof( char * ) ,
V_45 ) ;
if ( ! V_43 ) {
V_18 = - V_46 ;
goto V_49;
}
for ( V_44 = 0 ; V_44 < V_41 . V_48 ; V_44 ++ ) {
char * V_50 ;
V_50 = F_14 ( V_45 , L_6 ,
F_15 ( V_12 -> V_20 ) ,
V_3 -> V_16 ,
V_3 -> V_17 + 1 + V_44 ) ;
if ( ! V_50 ) {
V_18 = - V_46 ;
goto V_49;
}
V_43 [ V_44 ] = V_50 ;
}
V_41 . V_43 = ( void * ) V_43 ;
}
V_41 . V_13 = & V_51 ;
V_3 -> V_2 . V_41 = & V_41 ;
V_18 = F_17 ( V_12 -> V_20 , & V_3 -> V_2 ) ;
if ( V_18 )
F_4 ( V_12 -> V_20 , L_7 , V_18 ) ;
V_49:
if ( V_43 ) {
for ( V_44 = 0 ; V_44 < V_41 . V_48 ; V_44 ++ )
F_18 ( V_43 [ V_44 ] ) ;
F_18 ( V_43 ) ;
}
F_18 ( V_42 ) ;
if ( V_18 )
return F_13 ( V_18 ) ;
return & V_3 -> V_2 ;
}
static int F_19 ( const void * V_52 , const void * V_53 )
{
const struct V_3 * V_54 = V_52 ;
const struct V_3 * V_55 = * (struct V_3 * * ) V_53 ;
if ( V_54 -> V_16 == V_55 -> V_16 && V_54 -> V_17 == V_55 -> V_17 )
return 0 ;
if ( V_54 -> V_16 > V_55 -> V_16 ||
( V_54 -> V_16 == V_55 -> V_16 && V_54 -> V_17 > V_55 -> V_17 ) )
return 1 ;
return - 1 ;
}
static struct V_1 * F_20 ( struct V_56 * V_57 , void * V_58 )
{
struct V_39 * V_12 = V_58 ;
struct V_3 * * V_4 ;
struct V_3 V_59 ;
if ( V_57 -> V_60 != 2 )
return F_13 ( - V_61 ) ;
V_59 . V_16 = V_57 -> args [ 0 ] ;
V_59 . V_17 = V_57 -> args [ 1 ] ;
V_4 = bsearch ( & V_59 , V_12 -> V_62 , V_12 -> V_63 ,
sizeof( V_4 ) , F_19 ) ;
if ( ! V_4 )
return F_13 ( - V_64 ) ;
return & ( * V_4 ) -> V_2 ;
}
static int F_21 ( struct V_39 * V_65 )
{
const struct V_66 * V_58 = V_65 -> V_67 ;
struct V_1 * V_2 ;
int V_44 ;
int V_68 = 0 ;
while ( V_58 -> V_68 ) {
V_68 += V_58 -> V_68 ;
V_58 ++ ;
}
V_65 -> V_63 = V_68 ;
V_65 -> V_62 = F_22 ( V_65 -> V_20 , V_68 , sizeof( struct V_3 ) ,
V_45 ) ;
if ( ! V_65 -> V_62 )
return - V_46 ;
V_68 = 0 ;
V_58 = V_65 -> V_67 ;
while ( V_58 -> V_68 ) {
for ( V_44 = 0 ; V_44 < V_58 -> V_68 ; V_44 ++ ) {
V_2 = F_11 ( V_65 , V_58 -> V_20 , V_44 ) ;
if ( ! F_23 ( V_2 ) ) {
V_65 -> V_62 [ V_68 ++ ] = V_2 ;
continue;
}
if ( F_24 ( V_2 ) == - V_64 )
continue;
return F_24 ( V_2 ) ;
}
V_58 ++ ;
}
return 0 ;
}
static int F_25 ( struct V_69 * V_70 )
{
struct V_71 * V_20 = & V_70 -> V_20 ;
struct V_72 * V_73 = V_20 -> V_74 ;
struct V_39 * V_12 ;
const struct V_75 * V_76 ;
const struct V_66 * V_58 ;
int V_18 ;
V_58 = F_26 ( V_20 ) ;
if ( ! V_58 )
return - V_61 ;
V_76 = F_27 ( V_20 ) ;
if ( F_23 ( V_76 ) )
return F_24 ( V_76 ) ;
V_12 = F_12 ( V_20 , sizeof( * V_12 ) , V_45 ) ;
if ( ! V_12 )
return - V_46 ;
V_12 -> V_67 = V_58 ;
V_12 -> V_15 = V_76 ;
V_12 -> V_13 = & V_76 -> V_13 . V_77 ;
V_12 -> V_20 = V_20 ;
V_18 = F_21 ( V_12 ) ;
if ( V_18 ) {
F_28 ( L_8 ) ;
return V_18 ;
}
return F_29 ( V_73 , F_20 , V_12 ) ;
}
static int F_30 ( struct V_69 * V_70 )
{
F_31 ( V_70 -> V_20 . V_74 ) ;
return 0 ;
}
