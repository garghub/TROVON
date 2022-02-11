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
F_7 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_1 * V_23 ;
int V_24 ;
V_23 = F_1 ( V_3 , V_4 , & V_24 ) ;
#ifdef F_5
if ( V_23 == NULL ) {
if ( V_24 & V_16 )
F_8 ( V_4 ) ;
F_9 ( V_3 ) ;
return V_24 ;
}
#endif
V_24 = F_10 ( V_3 , V_23 ) ;
if ( V_24 == V_15 ) {
V_4 -> V_7 . V_25 ++ ;
return V_15 ;
}
if ( F_11 ( V_24 ) )
F_8 ( V_4 ) ;
return V_24 ;
}
static struct V_2 * F_12 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_23 ;
struct V_2 * V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ ) {
V_7 -> V_26 ++ ;
if ( V_7 -> V_26 >= V_7 -> V_21 )
V_7 -> V_26 = 0 ;
if ( ! F_13 (
F_14 ( F_15 ( V_4 ) , V_7 -> V_26 ) ) ) {
V_23 = V_7 -> V_22 [ V_7 -> V_26 ] ;
V_3 = V_23 -> V_27 ( V_23 ) ;
if ( V_3 ) {
F_16 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_25 -- ;
return V_3 ;
}
}
}
return NULL ;
}
static struct V_2 * F_17 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned int V_26 = V_7 -> V_26 ;
struct V_1 * V_23 ;
struct V_2 * V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ ) {
V_26 ++ ;
if ( V_26 >= V_7 -> V_21 )
V_26 = 0 ;
if ( ! F_13 (
F_14 ( F_15 ( V_4 ) , V_26 ) ) ) {
V_23 = V_7 -> V_22 [ V_26 ] ;
V_3 = V_23 -> V_28 -> V_29 ( V_23 ) ;
if ( V_3 )
return V_3 ;
}
}
return NULL ;
}
static unsigned int F_18 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_8 ;
unsigned int V_30 ;
struct V_1 * V_23 ;
for ( V_8 = V_7 -> V_21 - 1 ; V_8 >= 0 ; V_8 -- ) {
V_23 = V_7 -> V_22 [ V_8 ] ;
if ( V_23 -> V_28 -> V_31 ) {
V_30 = V_23 -> V_28 -> V_31 ( V_23 ) ;
if ( V_30 != 0 ) {
V_4 -> V_7 . V_25 -- ;
return V_30 ;
}
}
}
return 0 ;
}
static void
F_19 ( struct V_1 * V_4 )
{
T_2 V_8 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ )
F_20 ( V_7 -> V_22 [ V_8 ] ) ;
V_4 -> V_7 . V_25 = 0 ;
V_7 -> V_26 = 0 ;
}
static void
F_21 ( struct V_1 * V_4 )
{
int V_8 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_22 ( & V_7 -> V_13 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ )
F_23 ( V_7 -> V_22 [ V_8 ] ) ;
F_24 ( V_7 -> V_22 ) ;
}
static int F_25 ( struct V_1 * V_4 , struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_34 * V_35 ;
int V_36 ;
if ( ! F_26 ( F_15 ( V_4 ) ) )
return - V_37 ;
if ( F_27 ( V_33 ) < sizeof( * V_35 ) )
return - V_38 ;
V_35 = F_28 ( V_33 ) ;
V_35 -> V_21 = F_15 ( V_4 ) -> V_39 ;
F_29 ( V_4 ) ;
V_7 -> V_21 = V_35 -> V_21 ;
for ( V_36 = V_7 -> V_21 ; V_36 < V_7 -> V_40 ; V_36 ++ ) {
if ( V_7 -> V_22 [ V_36 ] != & V_41 ) {
struct V_1 * V_42 = V_7 -> V_22 [ V_36 ] ;
V_7 -> V_22 [ V_36 ] = & V_41 ;
F_30 ( V_42 , V_42 -> V_7 . V_25 ) ;
F_23 ( V_42 ) ;
}
}
F_31 ( V_4 ) ;
for ( V_36 = 0 ; V_36 < V_7 -> V_21 ; V_36 ++ ) {
if ( V_7 -> V_22 [ V_36 ] == & V_41 ) {
struct V_1 * V_42 , * V_43 ;
V_42 = F_32 ( V_4 -> V_44 ,
& V_45 ,
F_33 ( V_4 -> V_46 ,
V_36 + 1 ) ) ;
if ( V_42 ) {
F_29 ( V_4 ) ;
V_43 = V_7 -> V_22 [ V_36 ] ;
V_7 -> V_22 [ V_36 ] = V_42 ;
if ( V_43 != & V_41 ) {
F_30 ( V_43 ,
V_43 -> V_7 . V_25 ) ;
F_23 ( V_43 ) ;
}
F_31 ( V_4 ) ;
}
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_4 , struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_36 , V_14 ;
V_7 -> V_22 = NULL ;
if ( V_33 == NULL )
return - V_38 ;
V_7 -> V_40 = F_15 ( V_4 ) -> V_47 ;
V_7 -> V_22 = F_35 ( V_7 -> V_40 , sizeof( struct V_1 * ) , V_48 ) ;
if ( ! V_7 -> V_22 )
return - V_49 ;
for ( V_36 = 0 ; V_36 < V_7 -> V_40 ; V_36 ++ )
V_7 -> V_22 [ V_36 ] = & V_41 ;
V_14 = F_25 ( V_4 , V_33 ) ;
if ( V_14 )
F_24 ( V_7 -> V_22 ) ;
return V_14 ;
}
static int F_36 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_50 = F_37 ( V_3 ) ;
struct V_34 V_33 ;
V_33 . V_21 = V_7 -> V_21 ;
V_33 . V_40 = V_7 -> V_40 ;
if ( F_38 ( V_3 , V_51 , sizeof( V_33 ) , & V_33 ) )
goto V_52;
return V_3 -> V_30 ;
V_52:
F_39 ( V_3 , V_50 ) ;
return - 1 ;
}
static int F_40 ( struct V_1 * V_4 , unsigned long V_53 , struct V_1 * V_54 ,
struct V_1 * * V_43 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_53 - 1 ;
if ( V_54 == NULL )
V_54 = & V_41 ;
F_29 ( V_4 ) ;
* V_43 = V_7 -> V_22 [ V_8 ] ;
V_7 -> V_22 [ V_8 ] = V_54 ;
F_30 ( * V_43 , ( * V_43 ) -> V_7 . V_25 ) ;
F_20 ( * V_43 ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static struct V_1 *
F_41 ( struct V_1 * V_4 , unsigned long V_53 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_53 - 1 ;
return V_7 -> V_22 [ V_8 ] ;
}
static unsigned long F_42 ( struct V_1 * V_4 , T_1 V_55 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_43 ( V_55 ) ;
if ( V_8 - 1 >= V_7 -> V_21 )
return 0 ;
return V_8 ;
}
static unsigned long F_44 ( struct V_1 * V_4 , unsigned long V_56 ,
T_1 V_55 )
{
return F_42 ( V_4 , V_55 ) ;
}
static void F_45 ( struct V_1 * V_7 , unsigned long V_57 )
{
}
static int F_46 ( struct V_1 * V_4 , unsigned long V_57 ,
struct V_2 * V_3 , struct V_58 * V_59 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_59 -> V_60 |= F_43 ( V_57 ) ;
V_59 -> V_61 = V_7 -> V_22 [ V_57 - 1 ] -> V_46 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_4 , unsigned long V_57 ,
struct V_62 * V_63 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_64 ;
V_64 = V_7 -> V_22 [ V_57 - 1 ] ;
if ( F_48 ( V_63 , NULL , & V_64 -> V_65 ) < 0 ||
F_49 ( V_63 , NULL , & V_64 -> V_66 , V_64 -> V_7 . V_25 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_50 ( struct V_1 * V_4 , struct V_67 * V_53 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_8 ;
if ( V_53 -> V_68 )
return;
for ( V_8 = 0 ; V_8 < V_7 -> V_21 ; V_8 ++ ) {
if ( V_53 -> V_69 < V_53 -> V_70 ) {
V_53 -> V_69 ++ ;
continue;
}
if ( V_53 -> V_71 ( V_4 , V_8 + 1 , V_53 ) < 0 ) {
V_53 -> V_68 = 1 ;
break;
}
V_53 -> V_69 ++ ;
}
}
static struct V_11 T_3 * * F_51 ( struct V_1 * V_4 ,
unsigned long V_57 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_57 )
return NULL ;
return & V_7 -> V_13 ;
}
static int T_4 F_52 ( void )
{
return F_53 ( & V_72 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_72 ) ;
}
