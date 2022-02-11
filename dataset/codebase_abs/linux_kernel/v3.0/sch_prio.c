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
struct V_2 * V_3 = V_26 -> V_34 ( V_26 ) ;
if ( V_3 ) {
F_13 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_30 -- ;
return V_3 ;
}
}
return NULL ;
}
static unsigned int F_14 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
unsigned int V_35 ;
struct V_1 * V_26 ;
for ( V_31 = V_7 -> V_25 - 1 ; V_31 >= 0 ; V_31 -- ) {
V_26 = V_7 -> V_21 [ V_31 ] ;
if ( V_26 -> V_32 -> V_36 && ( V_35 = V_26 -> V_32 -> V_36 ( V_26 ) ) != 0 ) {
V_4 -> V_7 . V_30 -- ;
return V_35 ;
}
}
return 0 ;
}
static void
F_15 ( struct V_1 * V_4 )
{
int V_31 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
for ( V_31 = 0 ; V_31 < V_7 -> V_25 ; V_31 ++ )
F_16 ( V_7 -> V_21 [ V_31 ] ) ;
V_4 -> V_7 . V_30 = 0 ;
}
static void
F_17 ( struct V_1 * V_4 )
{
int V_31 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_18 ( & V_7 -> V_16 ) ;
for ( V_31 = 0 ; V_31 < V_7 -> V_25 ; V_31 ++ )
F_19 ( V_7 -> V_21 [ V_31 ] ) ;
}
static int F_20 ( struct V_1 * V_4 , struct V_37 * V_38 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_39 * V_40 ;
int V_41 ;
if ( F_21 ( V_38 ) < sizeof( * V_40 ) )
return - V_42 ;
V_40 = F_22 ( V_38 ) ;
if ( V_40 -> V_25 > V_43 || V_40 -> V_25 < 2 )
return - V_42 ;
for ( V_41 = 0 ; V_41 <= V_23 ; V_41 ++ ) {
if ( V_40 -> V_44 [ V_41 ] >= V_40 -> V_25 )
return - V_42 ;
}
F_23 ( V_4 ) ;
V_7 -> V_25 = V_40 -> V_25 ;
memcpy ( V_7 -> V_22 , V_40 -> V_44 , V_23 + 1 ) ;
for ( V_41 = V_7 -> V_25 ; V_41 < V_43 ; V_41 ++ ) {
struct V_1 * V_45 = V_7 -> V_21 [ V_41 ] ;
V_7 -> V_21 [ V_41 ] = & V_46 ;
if ( V_45 != & V_46 ) {
F_24 ( V_45 , V_45 -> V_7 . V_30 ) ;
F_19 ( V_45 ) ;
}
}
F_25 ( V_4 ) ;
for ( V_41 = 0 ; V_41 < V_7 -> V_25 ; V_41 ++ ) {
if ( V_7 -> V_21 [ V_41 ] == & V_46 ) {
struct V_1 * V_45 , * V_47 ;
V_45 = F_26 ( V_4 -> V_48 ,
& V_49 ,
F_27 ( V_4 -> V_15 , V_41 + 1 ) ) ;
if ( V_45 ) {
F_23 ( V_4 ) ;
V_47 = V_7 -> V_21 [ V_41 ] ;
V_7 -> V_21 [ V_41 ] = V_45 ;
if ( V_47 != & V_46 ) {
F_24 ( V_47 ,
V_47 -> V_7 . V_30 ) ;
F_19 ( V_47 ) ;
}
F_25 ( V_4 ) ;
}
}
}
return 0 ;
}
static int F_28 ( struct V_1 * V_4 , struct V_37 * V_38 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
V_7 -> V_21 [ V_41 ] = & V_46 ;
if ( V_38 == NULL ) {
return - V_42 ;
} else {
int V_12 ;
if ( ( V_12 = F_20 ( V_4 , V_38 ) ) != 0 )
return V_12 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_50 = F_30 ( V_3 ) ;
struct V_39 V_38 ;
V_38 . V_25 = V_7 -> V_25 ;
memcpy ( & V_38 . V_44 , V_7 -> V_22 , V_23 + 1 ) ;
F_31 ( V_3 , V_51 , sizeof( V_38 ) , & V_38 ) ;
return V_3 -> V_35 ;
V_52:
F_32 ( V_3 , V_50 ) ;
return - 1 ;
}
static int F_33 ( struct V_1 * V_4 , unsigned long V_53 , struct V_1 * V_54 ,
struct V_1 * * V_47 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_53 - 1 ;
if ( V_54 == NULL )
V_54 = & V_46 ;
F_23 ( V_4 ) ;
* V_47 = V_7 -> V_21 [ V_8 ] ;
V_7 -> V_21 [ V_8 ] = V_54 ;
F_24 ( * V_47 , ( * V_47 ) -> V_7 . V_30 ) ;
F_16 ( * V_47 ) ;
F_25 ( V_4 ) ;
return 0 ;
}
static struct V_1 *
F_34 ( struct V_1 * V_4 , unsigned long V_53 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_53 - 1 ;
return V_7 -> V_21 [ V_8 ] ;
}
static unsigned long F_35 ( struct V_1 * V_4 , T_1 V_24 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_6 ( V_24 ) ;
if ( V_8 - 1 >= V_7 -> V_25 )
return 0 ;
return V_8 ;
}
static unsigned long F_36 ( struct V_1 * V_4 , unsigned long V_55 , T_1 V_24 )
{
return F_35 ( V_4 , V_24 ) ;
}
static void F_37 ( struct V_1 * V_7 , unsigned long V_56 )
{
}
static int F_38 ( struct V_1 * V_4 , unsigned long V_56 , struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_58 -> V_59 |= F_6 ( V_56 ) ;
V_58 -> V_60 = V_7 -> V_21 [ V_56 - 1 ] -> V_15 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_4 , unsigned long V_56 ,
struct V_61 * V_62 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_63 ;
V_63 = V_7 -> V_21 [ V_56 - 1 ] ;
V_63 -> V_28 . V_30 = V_63 -> V_7 . V_30 ;
if ( F_40 ( V_62 , & V_63 -> V_64 ) < 0 ||
F_41 ( V_62 , & V_63 -> V_28 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_4 , struct V_65 * V_53 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
if ( V_53 -> V_66 )
return;
for ( V_31 = 0 ; V_31 < V_7 -> V_25 ; V_31 ++ ) {
if ( V_53 -> V_67 < V_53 -> V_68 ) {
V_53 -> V_67 ++ ;
continue;
}
if ( V_53 -> V_69 ( V_4 , V_31 + 1 , V_53 ) < 0 ) {
V_53 -> V_66 = 1 ;
break;
}
V_53 -> V_67 ++ ;
}
}
static struct V_70 * * F_43 ( struct V_1 * V_4 , unsigned long V_56 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_56 )
return NULL ;
return & V_7 -> V_16 ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_71 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_71 ) ;
}
