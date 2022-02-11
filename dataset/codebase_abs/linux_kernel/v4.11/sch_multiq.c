static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_1 * V_4 , int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
T_1 V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 = F_3 ( V_7 -> V_13 ) ;
int V_14 ;
* V_5 = V_15 | V_16 ;
V_14 = F_4 ( V_3 , V_12 , & V_10 , false ) ;
#ifdef F_5
switch ( V_14 ) {
case V_17 :
case V_18 :
* V_5 = V_15 | V_19 ;
case V_20 :
return NULL ;
}
#endif
V_8 = F_6 ( V_3 ) ;
if ( V_8 >= V_7 -> V_21 )
return V_7 -> V_22 [ 0 ] ;
return V_7 -> V_22 [ V_8 ] ;
}
static int
F_7 ( struct V_2 * V_3 , struct V_1 * V_4 ,
struct V_2 * * V_23 )
{
struct V_1 * V_24 ;
int V_25 ;
V_24 = F_1 ( V_3 , V_4 , & V_25 ) ;
#ifdef F_5
if ( V_24 == NULL ) {
if ( V_25 & V_16 )
F_8 ( V_4 ) ;
F_9 ( V_3 , V_23 ) ;
return V_25 ;
}
#endif
V_25 = F_10 ( V_3 , V_24 , V_23 ) ;
if ( V_25 == V_15 ) {
V_4 -> V_7 . V_26 ++ ;
return V_15 ;
}
if ( F_11 ( V_25 ) )
F_8 ( V_4 ) ;
return V_25 ;
}
static struct V_2 * F_12 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_24 ;
struct V_2 * V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ ) {
V_7 -> V_27 ++ ;
if ( V_7 -> V_27 >= V_7 -> V_21 )
V_7 -> V_27 = 0 ;
if ( ! F_13 (
F_14 ( F_15 ( V_4 ) , V_7 -> V_27 ) ) ) {
V_24 = V_7 -> V_22 [ V_7 -> V_27 ] ;
V_3 = V_24 -> V_28 ( V_24 ) ;
if ( V_3 ) {
F_16 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_26 -- ;
return V_3 ;
}
}
}
return NULL ;
}
static struct V_2 * F_17 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned int V_27 = V_7 -> V_27 ;
struct V_1 * V_24 ;
struct V_2 * V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ ) {
V_27 ++ ;
if ( V_27 >= V_7 -> V_21 )
V_27 = 0 ;
if ( ! F_13 (
F_14 ( F_15 ( V_4 ) , V_27 ) ) ) {
V_24 = V_7 -> V_22 [ V_27 ] ;
V_3 = V_24 -> V_29 -> V_30 ( V_24 ) ;
if ( V_3 )
return V_3 ;
}
}
return NULL ;
}
static void
F_18 ( struct V_1 * V_4 )
{
T_2 V_8 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ )
F_19 ( V_7 -> V_22 [ V_8 ] ) ;
V_4 -> V_7 . V_26 = 0 ;
V_7 -> V_27 = 0 ;
}
static void
F_20 ( struct V_1 * V_4 )
{
int V_8 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_21 ( & V_7 -> V_13 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ )
F_22 ( V_7 -> V_22 [ V_8 ] ) ;
F_23 ( V_7 -> V_22 ) ;
}
static int F_24 ( struct V_1 * V_4 , struct V_31 * V_32 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_33 * V_34 ;
int V_35 ;
if ( ! F_25 ( F_15 ( V_4 ) ) )
return - V_36 ;
if ( F_26 ( V_32 ) < sizeof( * V_34 ) )
return - V_37 ;
V_34 = F_27 ( V_32 ) ;
V_34 -> V_21 = F_15 ( V_4 ) -> V_38 ;
F_28 ( V_4 ) ;
V_7 -> V_21 = V_34 -> V_21 ;
for ( V_35 = V_7 -> V_21 ; V_35 < V_7 -> V_39 ; V_35 ++ ) {
if ( V_7 -> V_22 [ V_35 ] != & V_40 ) {
struct V_1 * V_41 = V_7 -> V_22 [ V_35 ] ;
V_7 -> V_22 [ V_35 ] = & V_40 ;
F_29 ( V_41 , V_41 -> V_7 . V_26 ,
V_41 -> V_42 . V_43 ) ;
F_22 ( V_41 ) ;
}
}
F_30 ( V_4 ) ;
for ( V_35 = 0 ; V_35 < V_7 -> V_21 ; V_35 ++ ) {
if ( V_7 -> V_22 [ V_35 ] == & V_40 ) {
struct V_1 * V_41 , * V_44 ;
V_41 = F_31 ( V_4 -> V_45 ,
& V_46 ,
F_32 ( V_4 -> V_47 ,
V_35 + 1 ) ) ;
if ( V_41 ) {
F_28 ( V_4 ) ;
V_44 = V_7 -> V_22 [ V_35 ] ;
V_7 -> V_22 [ V_35 ] = V_41 ;
if ( V_44 != & V_40 ) {
F_29 ( V_44 ,
V_44 -> V_7 . V_26 ,
V_44 -> V_42 . V_43 ) ;
F_22 ( V_44 ) ;
}
F_30 ( V_4 ) ;
}
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_4 , struct V_31 * V_32 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_35 , V_14 ;
V_7 -> V_22 = NULL ;
if ( V_32 == NULL )
return - V_37 ;
V_7 -> V_39 = F_15 ( V_4 ) -> V_48 ;
V_7 -> V_22 = F_34 ( V_7 -> V_39 , sizeof( struct V_1 * ) , V_49 ) ;
if ( ! V_7 -> V_22 )
return - V_50 ;
for ( V_35 = 0 ; V_35 < V_7 -> V_39 ; V_35 ++ )
V_7 -> V_22 [ V_35 ] = & V_40 ;
V_14 = F_24 ( V_4 , V_32 ) ;
if ( V_14 )
F_23 ( V_7 -> V_22 ) ;
return V_14 ;
}
static int F_35 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_51 = F_36 ( V_3 ) ;
struct V_33 V_32 ;
V_32 . V_21 = V_7 -> V_21 ;
V_32 . V_39 = V_7 -> V_39 ;
if ( F_37 ( V_3 , V_52 , sizeof( V_32 ) , & V_32 ) )
goto V_53;
return V_3 -> V_54 ;
V_53:
F_38 ( V_3 , V_51 ) ;
return - 1 ;
}
static int F_39 ( struct V_1 * V_4 , unsigned long V_55 , struct V_1 * V_56 ,
struct V_1 * * V_44 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_55 - 1 ;
if ( V_56 == NULL )
V_56 = & V_40 ;
* V_44 = F_40 ( V_4 , V_56 , & V_7 -> V_22 [ V_8 ] ) ;
return 0 ;
}
static struct V_1 *
F_41 ( struct V_1 * V_4 , unsigned long V_55 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_55 - 1 ;
return V_7 -> V_22 [ V_8 ] ;
}
static unsigned long F_42 ( struct V_1 * V_4 , T_1 V_57 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_43 ( V_57 ) ;
if ( V_8 - 1 >= V_7 -> V_21 )
return 0 ;
return V_8 ;
}
static unsigned long F_44 ( struct V_1 * V_4 , unsigned long V_58 ,
T_1 V_57 )
{
return F_42 ( V_4 , V_57 ) ;
}
static void F_45 ( struct V_1 * V_7 , unsigned long V_59 )
{
}
static int F_46 ( struct V_1 * V_4 , unsigned long V_59 ,
struct V_2 * V_3 , struct V_60 * V_61 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_61 -> V_62 |= F_43 ( V_59 ) ;
V_61 -> V_63 = V_7 -> V_22 [ V_59 - 1 ] -> V_47 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_4 , unsigned long V_59 ,
struct V_64 * V_65 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_66 ;
V_66 = V_7 -> V_22 [ V_59 - 1 ] ;
if ( F_48 ( F_49 ( V_4 ) ,
V_65 , NULL , & V_66 -> V_67 ) < 0 ||
F_50 ( V_65 , NULL , & V_66 -> V_42 , V_66 -> V_7 . V_26 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_4 , struct V_68 * V_55 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_8 ;
if ( V_55 -> V_69 )
return;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ ) {
if ( V_55 -> V_70 < V_55 -> V_71 ) {
V_55 -> V_70 ++ ;
continue;
}
if ( V_55 -> V_72 ( V_4 , V_8 + 1 , V_55 ) < 0 ) {
V_55 -> V_69 = 1 ;
break;
}
V_55 -> V_70 ++ ;
}
}
static struct V_11 T_3 * * F_52 ( struct V_1 * V_4 ,
unsigned long V_59 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_59 )
return NULL ;
return & V_7 -> V_13 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_73 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_73 ) ;
}
