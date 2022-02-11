static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_1 * V_4 , int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
T_1 V_8 ;
struct V_9 V_10 ;
int V_11 ;
* V_5 = V_12 | V_13 ;
V_11 = F_3 ( V_3 , V_7 -> V_14 , & V_10 ) ;
#ifdef F_4
switch ( V_11 ) {
case V_15 :
case V_16 :
* V_5 = V_12 | V_17 ;
case V_18 :
return NULL ;
}
#endif
V_8 = F_5 ( V_3 ) ;
if ( V_8 >= V_7 -> V_19 )
return V_7 -> V_20 [ 0 ] ;
return V_7 -> V_20 [ V_8 ] ;
}
static int
F_6 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_1 * V_21 ;
int V_22 ;
V_21 = F_1 ( V_3 , V_4 , & V_22 ) ;
#ifdef F_4
if ( V_21 == NULL ) {
if ( V_22 & V_13 )
V_4 -> V_23 . V_24 ++ ;
F_7 ( V_3 ) ;
return V_22 ;
}
#endif
V_22 = F_8 ( V_3 , V_21 ) ;
if ( V_22 == V_12 ) {
V_4 -> V_7 . V_25 ++ ;
return V_12 ;
}
if ( F_9 ( V_22 ) )
V_4 -> V_23 . V_24 ++ ;
return V_22 ;
}
static struct V_2 * F_10 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_21 ;
struct V_2 * V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_19 ; V_8 ++ ) {
V_7 -> V_26 ++ ;
if ( V_7 -> V_26 >= V_7 -> V_19 )
V_7 -> V_26 = 0 ;
if ( ! F_11 ( F_12 ( V_4 ) , V_7 -> V_26 ) ) {
V_21 = V_7 -> V_20 [ V_7 -> V_26 ] ;
V_3 = V_21 -> V_27 ( V_21 ) ;
if ( V_3 ) {
F_13 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_25 -- ;
return V_3 ;
}
}
}
return NULL ;
}
static struct V_2 * F_14 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned int V_26 = V_7 -> V_26 ;
struct V_1 * V_21 ;
struct V_2 * V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_19 ; V_8 ++ ) {
V_26 ++ ;
if ( V_26 >= V_7 -> V_19 )
V_26 = 0 ;
if ( ! F_11 ( F_12 ( V_4 ) , V_26 ) ) {
V_21 = V_7 -> V_20 [ V_26 ] ;
V_3 = V_21 -> V_28 -> V_29 ( V_21 ) ;
if ( V_3 )
return V_3 ;
}
}
return NULL ;
}
static unsigned int F_15 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_8 ;
unsigned int V_30 ;
struct V_1 * V_21 ;
for ( V_8 = V_7 -> V_19 - 1 ; V_8 >= 0 ; V_8 -- ) {
V_21 = V_7 -> V_20 [ V_8 ] ;
if ( V_21 -> V_28 -> V_31 ) {
V_30 = V_21 -> V_28 -> V_31 ( V_21 ) ;
if ( V_30 != 0 ) {
V_4 -> V_7 . V_25 -- ;
return V_30 ;
}
}
}
return 0 ;
}
static void
F_16 ( struct V_1 * V_4 )
{
T_2 V_8 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_19 ; V_8 ++ )
F_17 ( V_7 -> V_20 [ V_8 ] ) ;
V_4 -> V_7 . V_25 = 0 ;
V_7 -> V_26 = 0 ;
}
static void
F_18 ( struct V_1 * V_4 )
{
int V_8 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_19 ( & V_7 -> V_14 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_19 ; V_8 ++ )
F_20 ( V_7 -> V_20 [ V_8 ] ) ;
F_21 ( V_7 -> V_20 ) ;
}
static int F_22 ( struct V_1 * V_4 , struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_34 * V_35 ;
int V_36 ;
if ( ! F_23 ( F_12 ( V_4 ) ) )
return - V_37 ;
if ( F_24 ( V_33 ) < sizeof( * V_35 ) )
return - V_38 ;
V_35 = F_25 ( V_33 ) ;
V_35 -> V_19 = F_12 ( V_4 ) -> V_39 ;
F_26 ( V_4 ) ;
V_7 -> V_19 = V_35 -> V_19 ;
for ( V_36 = V_7 -> V_19 ; V_36 < V_7 -> V_40 ; V_36 ++ ) {
if ( V_7 -> V_20 [ V_36 ] != & V_41 ) {
struct V_1 * V_42 = V_7 -> V_20 [ V_36 ] ;
V_7 -> V_20 [ V_36 ] = & V_41 ;
F_27 ( V_42 , V_42 -> V_7 . V_25 ) ;
F_20 ( V_42 ) ;
}
}
F_28 ( V_4 ) ;
for ( V_36 = 0 ; V_36 < V_7 -> V_19 ; V_36 ++ ) {
if ( V_7 -> V_20 [ V_36 ] == & V_41 ) {
struct V_1 * V_42 , * V_43 ;
V_42 = F_29 ( V_4 -> V_44 ,
& V_45 ,
F_30 ( V_4 -> V_46 ,
V_36 + 1 ) ) ;
if ( V_42 ) {
F_26 ( V_4 ) ;
V_43 = V_7 -> V_20 [ V_36 ] ;
V_7 -> V_20 [ V_36 ] = V_42 ;
if ( V_43 != & V_41 ) {
F_27 ( V_43 ,
V_43 -> V_7 . V_25 ) ;
F_20 ( V_43 ) ;
}
F_28 ( V_4 ) ;
}
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_4 , struct V_32 * V_33 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_36 , V_11 ;
V_7 -> V_20 = NULL ;
if ( V_33 == NULL )
return - V_38 ;
V_7 -> V_40 = F_12 ( V_4 ) -> V_47 ;
V_7 -> V_20 = F_32 ( V_7 -> V_40 , sizeof( struct V_1 * ) , V_48 ) ;
if ( ! V_7 -> V_20 )
return - V_49 ;
for ( V_36 = 0 ; V_36 < V_7 -> V_40 ; V_36 ++ )
V_7 -> V_20 [ V_36 ] = & V_41 ;
V_11 = F_22 ( V_4 , V_33 ) ;
if ( V_11 )
F_21 ( V_7 -> V_20 ) ;
return V_11 ;
}
static int F_33 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_50 = F_34 ( V_3 ) ;
struct V_34 V_33 ;
V_33 . V_19 = V_7 -> V_19 ;
V_33 . V_40 = V_7 -> V_40 ;
F_35 ( V_3 , V_51 , sizeof( V_33 ) , & V_33 ) ;
return V_3 -> V_30 ;
V_52:
F_36 ( V_3 , V_50 ) ;
return - 1 ;
}
static int F_37 ( struct V_1 * V_4 , unsigned long V_53 , struct V_1 * V_54 ,
struct V_1 * * V_43 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_53 - 1 ;
if ( V_54 == NULL )
V_54 = & V_41 ;
F_26 ( V_4 ) ;
* V_43 = V_7 -> V_20 [ V_8 ] ;
V_7 -> V_20 [ V_8 ] = V_54 ;
F_27 ( * V_43 , ( * V_43 ) -> V_7 . V_25 ) ;
F_17 ( * V_43 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static struct V_1 *
F_38 ( struct V_1 * V_4 , unsigned long V_53 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_53 - 1 ;
return V_7 -> V_20 [ V_8 ] ;
}
static unsigned long F_39 ( struct V_1 * V_4 , T_1 V_55 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_40 ( V_55 ) ;
if ( V_8 - 1 >= V_7 -> V_19 )
return 0 ;
return V_8 ;
}
static unsigned long F_41 ( struct V_1 * V_4 , unsigned long V_56 ,
T_1 V_55 )
{
return F_39 ( V_4 , V_55 ) ;
}
static void F_42 ( struct V_1 * V_7 , unsigned long V_57 )
{
}
static int F_43 ( struct V_1 * V_4 , unsigned long V_57 ,
struct V_2 * V_3 , struct V_58 * V_59 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_59 -> V_60 |= F_40 ( V_57 ) ;
V_59 -> V_61 = V_7 -> V_20 [ V_57 - 1 ] -> V_46 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_4 , unsigned long V_57 ,
struct V_62 * V_63 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_64 ;
V_64 = V_7 -> V_20 [ V_57 - 1 ] ;
V_64 -> V_23 . V_25 = V_64 -> V_7 . V_25 ;
if ( F_45 ( V_63 , & V_64 -> V_65 ) < 0 ||
F_46 ( V_63 , & V_64 -> V_23 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_47 ( struct V_1 * V_4 , struct V_66 * V_53 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_8 ;
if ( V_53 -> V_67 )
return;
for ( V_8 = 0 ; V_8 < V_7 -> V_19 ; V_8 ++ ) {
if ( V_53 -> V_68 < V_53 -> V_69 ) {
V_53 -> V_68 ++ ;
continue;
}
if ( V_53 -> V_70 ( V_4 , V_8 + 1 , V_53 ) < 0 ) {
V_53 -> V_67 = 1 ;
break;
}
V_53 -> V_68 ++ ;
}
}
static struct V_71 * * F_48 ( struct V_1 * V_4 , unsigned long V_57 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_57 )
return NULL ;
return & V_7 -> V_14 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_72 ) ;
}
static void T_4 F_51 ( void )
{
F_52 ( & V_72 ) ;
}
