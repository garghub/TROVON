static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_1 * V_4 , int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
T_1 V_8 = V_3 -> V_9 ;
struct V_10 V_11 ;
int V_12 ;
* V_5 = V_13 | V_14 ;
if ( F_3 ( V_3 -> V_9 ) != V_4 -> V_15 ) {
V_12 = F_4 ( V_3 , V_7 -> V_16 , & V_11 ) ;
#ifdef F_5
switch ( V_12 ) {
case V_17 :
case V_18 :
* V_5 = V_13 | V_19 ;
case V_20 :
return NULL ;
}
#endif
if ( ! V_7 -> V_16 || V_12 < 0 ) {
if ( F_3 ( V_8 ) )
V_8 = 0 ;
return V_7 -> V_21 [ V_7 -> V_22 [ V_8 & V_23 ] ] ;
}
V_8 = V_11 . V_24 ;
}
V_8 = F_6 ( V_8 ) - 1 ;
if ( V_8 >= V_7 -> V_25 )
return V_7 -> V_21 [ V_7 -> V_22 [ 0 ] ] ;
return V_7 -> V_21 [ V_8 ] ;
}
static int
F_7 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_1 * V_26 ;
int V_27 ;
V_26 = F_1 ( V_3 , V_4 , & V_27 ) ;
#ifdef F_5
if ( V_26 == NULL ) {
if ( V_27 & V_14 )
V_4 -> V_28 . V_29 ++ ;
F_8 ( V_3 ) ;
return V_27 ;
}
#endif
V_27 = F_9 ( V_3 , V_26 ) ;
if ( V_27 == V_13 ) {
V_4 -> V_7 . V_30 ++ ;
return V_13 ;
}
if ( F_10 ( V_27 ) )
V_4 -> V_28 . V_29 ++ ;
return V_27 ;
}
static struct V_2 * F_11 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_7 -> V_25 ; V_31 ++ ) {
struct V_1 * V_26 = V_7 -> V_21 [ V_31 ] ;
struct V_2 * V_3 = V_26 -> V_32 -> V_33 ( V_26 ) ;
if ( V_3 )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_12 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_7 -> V_25 ; V_31 ++ ) {
struct V_1 * V_26 = V_7 -> V_21 [ V_31 ] ;
struct V_2 * V_3 = F_13 ( V_26 ) ;
if ( V_3 ) {
F_14 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_30 -- ;
return V_3 ;
}
}
return NULL ;
}
static unsigned int F_15 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
unsigned int V_34 ;
struct V_1 * V_26 ;
for ( V_31 = V_7 -> V_25 - 1 ; V_31 >= 0 ; V_31 -- ) {
V_26 = V_7 -> V_21 [ V_31 ] ;
if ( V_26 -> V_32 -> V_35 && ( V_34 = V_26 -> V_32 -> V_35 ( V_26 ) ) != 0 ) {
V_4 -> V_7 . V_30 -- ;
return V_34 ;
}
}
return 0 ;
}
static void
F_16 ( struct V_1 * V_4 )
{
int V_31 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
for ( V_31 = 0 ; V_31 < V_7 -> V_25 ; V_31 ++ )
F_17 ( V_7 -> V_21 [ V_31 ] ) ;
V_4 -> V_7 . V_30 = 0 ;
}
static void
F_18 ( struct V_1 * V_4 )
{
int V_31 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_19 ( & V_7 -> V_16 ) ;
for ( V_31 = 0 ; V_31 < V_7 -> V_25 ; V_31 ++ )
F_20 ( V_7 -> V_21 [ V_31 ] ) ;
}
static int F_21 ( struct V_1 * V_4 , struct V_36 * V_37 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_38 * V_39 ;
int V_40 ;
if ( F_22 ( V_37 ) < sizeof( * V_39 ) )
return - V_41 ;
V_39 = F_23 ( V_37 ) ;
if ( V_39 -> V_25 > V_42 || V_39 -> V_25 < 2 )
return - V_41 ;
for ( V_40 = 0 ; V_40 <= V_23 ; V_40 ++ ) {
if ( V_39 -> V_43 [ V_40 ] >= V_39 -> V_25 )
return - V_41 ;
}
F_24 ( V_4 ) ;
V_7 -> V_25 = V_39 -> V_25 ;
memcpy ( V_7 -> V_22 , V_39 -> V_43 , V_23 + 1 ) ;
for ( V_40 = V_7 -> V_25 ; V_40 < V_42 ; V_40 ++ ) {
struct V_1 * V_44 = V_7 -> V_21 [ V_40 ] ;
V_7 -> V_21 [ V_40 ] = & V_45 ;
if ( V_44 != & V_45 ) {
F_25 ( V_44 , V_44 -> V_7 . V_30 ) ;
F_20 ( V_44 ) ;
}
}
F_26 ( V_4 ) ;
for ( V_40 = 0 ; V_40 < V_7 -> V_25 ; V_40 ++ ) {
if ( V_7 -> V_21 [ V_40 ] == & V_45 ) {
struct V_1 * V_44 , * V_46 ;
V_44 = F_27 ( V_4 -> V_47 ,
& V_48 ,
F_28 ( V_4 -> V_15 , V_40 + 1 ) ) ;
if ( V_44 ) {
F_24 ( V_4 ) ;
V_46 = V_7 -> V_21 [ V_40 ] ;
V_7 -> V_21 [ V_40 ] = V_44 ;
if ( V_46 != & V_45 ) {
F_25 ( V_46 ,
V_46 -> V_7 . V_30 ) ;
F_20 ( V_46 ) ;
}
F_26 ( V_4 ) ;
}
}
}
return 0 ;
}
static int F_29 ( struct V_1 * V_4 , struct V_36 * V_37 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ )
V_7 -> V_21 [ V_40 ] = & V_45 ;
if ( V_37 == NULL ) {
return - V_41 ;
} else {
int V_12 ;
if ( ( V_12 = F_21 ( V_4 , V_37 ) ) != 0 )
return V_12 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_49 = F_31 ( V_3 ) ;
struct V_38 V_37 ;
V_37 . V_25 = V_7 -> V_25 ;
memcpy ( & V_37 . V_43 , V_7 -> V_22 , V_23 + 1 ) ;
F_32 ( V_3 , V_50 , sizeof( V_37 ) , & V_37 ) ;
return V_3 -> V_34 ;
V_51:
F_33 ( V_3 , V_49 ) ;
return - 1 ;
}
static int F_34 ( struct V_1 * V_4 , unsigned long V_52 , struct V_1 * V_53 ,
struct V_1 * * V_46 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_52 - 1 ;
if ( V_53 == NULL )
V_53 = & V_45 ;
F_24 ( V_4 ) ;
* V_46 = V_7 -> V_21 [ V_8 ] ;
V_7 -> V_21 [ V_8 ] = V_53 ;
F_25 ( * V_46 , ( * V_46 ) -> V_7 . V_30 ) ;
F_17 ( * V_46 ) ;
F_26 ( V_4 ) ;
return 0 ;
}
static struct V_1 *
F_35 ( struct V_1 * V_4 , unsigned long V_52 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_52 - 1 ;
return V_7 -> V_21 [ V_8 ] ;
}
static unsigned long F_36 ( struct V_1 * V_4 , T_1 V_24 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_6 ( V_24 ) ;
if ( V_8 - 1 >= V_7 -> V_25 )
return 0 ;
return V_8 ;
}
static unsigned long F_37 ( struct V_1 * V_4 , unsigned long V_54 , T_1 V_24 )
{
return F_36 ( V_4 , V_24 ) ;
}
static void F_38 ( struct V_1 * V_7 , unsigned long V_55 )
{
}
static int F_39 ( struct V_1 * V_4 , unsigned long V_55 , struct V_2 * V_3 ,
struct V_56 * V_57 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_57 -> V_58 |= F_6 ( V_55 ) ;
V_57 -> V_59 = V_7 -> V_21 [ V_55 - 1 ] -> V_15 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_4 , unsigned long V_55 ,
struct V_60 * V_61 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_62 ;
V_62 = V_7 -> V_21 [ V_55 - 1 ] ;
V_62 -> V_28 . V_30 = V_62 -> V_7 . V_30 ;
if ( F_41 ( V_61 , & V_62 -> V_63 ) < 0 ||
F_42 ( V_61 , & V_62 -> V_28 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_4 , struct V_64 * V_52 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
if ( V_52 -> V_65 )
return;
for ( V_31 = 0 ; V_31 < V_7 -> V_25 ; V_31 ++ ) {
if ( V_52 -> V_66 < V_52 -> V_67 ) {
V_52 -> V_66 ++ ;
continue;
}
if ( V_52 -> V_68 ( V_4 , V_31 + 1 , V_52 ) < 0 ) {
V_52 -> V_65 = 1 ;
break;
}
V_52 -> V_66 ++ ;
}
}
static struct V_69 * * F_44 ( struct V_1 * V_4 , unsigned long V_55 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_55 )
return NULL ;
return & V_7 -> V_16 ;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_70 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_70 ) ;
}
