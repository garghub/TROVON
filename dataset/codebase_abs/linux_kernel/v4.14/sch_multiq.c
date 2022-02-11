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
case V_19 :
* V_5 = V_15 | V_20 ;
case V_21 :
return NULL ;
}
#endif
V_8 = F_6 ( V_3 ) ;
if ( V_8 >= V_7 -> V_22 )
return V_7 -> V_23 [ 0 ] ;
return V_7 -> V_23 [ V_8 ] ;
}
static int
F_7 ( struct V_2 * V_3 , struct V_1 * V_4 ,
struct V_2 * * V_24 )
{
struct V_1 * V_25 ;
int V_26 ;
V_25 = F_1 ( V_3 , V_4 , & V_26 ) ;
#ifdef F_5
if ( V_25 == NULL ) {
if ( V_26 & V_16 )
F_8 ( V_4 ) ;
F_9 ( V_3 , V_24 ) ;
return V_26 ;
}
#endif
V_26 = F_10 ( V_3 , V_25 , V_24 ) ;
if ( V_26 == V_15 ) {
V_4 -> V_7 . V_27 ++ ;
return V_15 ;
}
if ( F_11 ( V_26 ) )
F_8 ( V_4 ) ;
return V_26 ;
}
static struct V_2 * F_12 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_25 ;
struct V_2 * V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_22 ; V_8 ++ ) {
V_7 -> V_28 ++ ;
if ( V_7 -> V_28 >= V_7 -> V_22 )
V_7 -> V_28 = 0 ;
if ( ! F_13 (
F_14 ( F_15 ( V_4 ) , V_7 -> V_28 ) ) ) {
V_25 = V_7 -> V_23 [ V_7 -> V_28 ] ;
V_3 = V_25 -> V_29 ( V_25 ) ;
if ( V_3 ) {
F_16 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_27 -- ;
return V_3 ;
}
}
}
return NULL ;
}
static struct V_2 * F_17 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned int V_28 = V_7 -> V_28 ;
struct V_1 * V_25 ;
struct V_2 * V_3 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_22 ; V_8 ++ ) {
V_28 ++ ;
if ( V_28 >= V_7 -> V_22 )
V_28 = 0 ;
if ( ! F_13 (
F_14 ( F_15 ( V_4 ) , V_28 ) ) ) {
V_25 = V_7 -> V_23 [ V_28 ] ;
V_3 = V_25 -> V_30 -> V_31 ( V_25 ) ;
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
for ( V_8 = 0 ; V_8 < V_7 -> V_22 ; V_8 ++ )
F_19 ( V_7 -> V_23 [ V_8 ] ) ;
V_4 -> V_7 . V_27 = 0 ;
V_7 -> V_28 = 0 ;
}
static void
F_20 ( struct V_1 * V_4 )
{
int V_8 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_21 ( V_7 -> V_32 ) ;
for ( V_8 = 0 ; V_8 < V_7 -> V_22 ; V_8 ++ )
F_22 ( V_7 -> V_23 [ V_8 ] ) ;
F_23 ( V_7 -> V_23 ) ;
}
static int F_24 ( struct V_1 * V_4 , struct V_33 * V_34 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_35 * V_36 ;
int V_37 ;
if ( ! F_25 ( F_15 ( V_4 ) ) )
return - V_38 ;
if ( F_26 ( V_34 ) < sizeof( * V_36 ) )
return - V_39 ;
V_36 = F_27 ( V_34 ) ;
V_36 -> V_22 = F_15 ( V_4 ) -> V_40 ;
F_28 ( V_4 ) ;
V_7 -> V_22 = V_36 -> V_22 ;
for ( V_37 = V_7 -> V_22 ; V_37 < V_7 -> V_41 ; V_37 ++ ) {
if ( V_7 -> V_23 [ V_37 ] != & V_42 ) {
struct V_1 * V_43 = V_7 -> V_23 [ V_37 ] ;
V_7 -> V_23 [ V_37 ] = & V_42 ;
F_29 ( V_43 , V_43 -> V_7 . V_27 ,
V_43 -> V_44 . V_45 ) ;
F_22 ( V_43 ) ;
}
}
F_30 ( V_4 ) ;
for ( V_37 = 0 ; V_37 < V_7 -> V_22 ; V_37 ++ ) {
if ( V_7 -> V_23 [ V_37 ] == & V_42 ) {
struct V_1 * V_43 , * V_46 ;
V_43 = F_31 ( V_4 -> V_47 ,
& V_48 ,
F_32 ( V_4 -> V_49 ,
V_37 + 1 ) ) ;
if ( V_43 ) {
F_28 ( V_4 ) ;
V_46 = V_7 -> V_23 [ V_37 ] ;
V_7 -> V_23 [ V_37 ] = V_43 ;
if ( V_43 != & V_42 )
F_33 ( V_43 , true ) ;
if ( V_46 != & V_42 ) {
F_29 ( V_46 ,
V_46 -> V_7 . V_27 ,
V_46 -> V_44 . V_45 ) ;
F_22 ( V_46 ) ;
}
F_30 ( V_4 ) ;
}
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_4 , struct V_33 * V_34 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_37 , V_14 ;
V_7 -> V_23 = NULL ;
if ( V_34 == NULL )
return - V_39 ;
V_14 = F_35 ( & V_7 -> V_32 , & V_7 -> V_13 ) ;
if ( V_14 )
return V_14 ;
V_7 -> V_41 = F_15 ( V_4 ) -> V_50 ;
V_7 -> V_23 = F_36 ( V_7 -> V_41 , sizeof( struct V_1 * ) , V_51 ) ;
if ( ! V_7 -> V_23 )
return - V_52 ;
for ( V_37 = 0 ; V_37 < V_7 -> V_41 ; V_37 ++ )
V_7 -> V_23 [ V_37 ] = & V_42 ;
return F_24 ( V_4 , V_34 ) ;
}
static int F_37 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_53 = F_38 ( V_3 ) ;
struct V_35 V_34 ;
V_34 . V_22 = V_7 -> V_22 ;
V_34 . V_41 = V_7 -> V_41 ;
if ( F_39 ( V_3 , V_54 , sizeof( V_34 ) , & V_34 ) )
goto V_55;
return V_3 -> V_56 ;
V_55:
F_40 ( V_3 , V_53 ) ;
return - 1 ;
}
static int F_41 ( struct V_1 * V_4 , unsigned long V_57 , struct V_1 * V_58 ,
struct V_1 * * V_46 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_57 - 1 ;
if ( V_58 == NULL )
V_58 = & V_42 ;
* V_46 = F_42 ( V_4 , V_58 , & V_7 -> V_23 [ V_8 ] ) ;
return 0 ;
}
static struct V_1 *
F_43 ( struct V_1 * V_4 , unsigned long V_57 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_57 - 1 ;
return V_7 -> V_23 [ V_8 ] ;
}
static unsigned long F_44 ( struct V_1 * V_4 , T_1 V_59 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_45 ( V_59 ) ;
if ( V_8 - 1 >= V_7 -> V_22 )
return 0 ;
return V_8 ;
}
static unsigned long F_46 ( struct V_1 * V_4 , unsigned long V_60 ,
T_1 V_59 )
{
return F_44 ( V_4 , V_59 ) ;
}
static void F_47 ( struct V_1 * V_7 , unsigned long V_61 )
{
}
static int F_48 ( struct V_1 * V_4 , unsigned long V_61 ,
struct V_2 * V_3 , struct V_62 * V_63 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_63 -> V_64 |= F_45 ( V_61 ) ;
V_63 -> V_65 = V_7 -> V_23 [ V_61 - 1 ] -> V_49 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_4 , unsigned long V_61 ,
struct V_66 * V_67 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_68 ;
V_68 = V_7 -> V_23 [ V_61 - 1 ] ;
if ( F_50 ( F_51 ( V_4 ) ,
V_67 , NULL , & V_68 -> V_69 ) < 0 ||
F_52 ( V_67 , NULL , & V_68 -> V_44 , V_68 -> V_7 . V_27 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_4 , struct V_70 * V_57 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_8 ;
if ( V_57 -> V_71 )
return;
for ( V_8 = 0 ; V_8 < V_7 -> V_22 ; V_8 ++ ) {
if ( V_57 -> V_72 < V_57 -> V_73 ) {
V_57 -> V_72 ++ ;
continue;
}
if ( V_57 -> V_74 ( V_4 , V_8 + 1 , V_57 ) < 0 ) {
V_57 -> V_71 = 1 ;
break;
}
V_57 -> V_72 ++ ;
}
}
static struct V_75 * F_54 ( struct V_1 * V_4 , unsigned long V_61 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_61 )
return NULL ;
return V_7 -> V_32 ;
}
static int T_3 F_55 ( void )
{
return F_56 ( & V_76 ) ;
}
static void T_4 F_57 ( void )
{
F_58 ( & V_76 ) ;
}
