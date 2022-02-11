static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_1 * V_4 , int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
T_1 V_8 = V_3 -> V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
int V_14 ;
* V_5 = V_15 | V_16 ;
if ( F_3 ( V_3 -> V_9 ) != V_4 -> V_17 ) {
V_13 = F_4 ( V_7 -> V_18 ) ;
V_14 = F_5 ( V_3 , V_13 , & V_11 , false ) ;
#ifdef F_6
switch ( V_14 ) {
case V_19 :
case V_20 :
* V_5 = V_15 | V_21 ;
case V_22 :
return NULL ;
}
#endif
if ( ! V_13 || V_14 < 0 ) {
if ( F_3 ( V_8 ) )
V_8 = 0 ;
return V_7 -> V_23 [ V_7 -> V_24 [ V_8 & V_25 ] ] ;
}
V_8 = V_11 . V_26 ;
}
V_8 = F_7 ( V_8 ) - 1 ;
if ( V_8 >= V_7 -> V_27 )
return V_7 -> V_23 [ V_7 -> V_24 [ 0 ] ] ;
return V_7 -> V_23 [ V_8 ] ;
}
static int
F_8 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_1 * V_28 ;
int V_29 ;
V_28 = F_1 ( V_3 , V_4 , & V_29 ) ;
#ifdef F_6
if ( V_28 == NULL ) {
if ( V_29 & V_16 )
F_9 ( V_4 ) ;
F_10 ( V_3 ) ;
return V_29 ;
}
#endif
V_29 = F_11 ( V_3 , V_28 ) ;
if ( V_29 == V_15 ) {
F_12 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_30 ++ ;
return V_15 ;
}
if ( F_13 ( V_29 ) )
F_9 ( V_4 ) ;
return V_29 ;
}
static struct V_2 * F_14 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_7 -> V_27 ; V_31 ++ ) {
struct V_1 * V_28 = V_7 -> V_23 [ V_31 ] ;
struct V_2 * V_3 = V_28 -> V_32 -> V_33 ( V_28 ) ;
if ( V_3 )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_15 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_7 -> V_27 ; V_31 ++ ) {
struct V_1 * V_28 = V_7 -> V_23 [ V_31 ] ;
struct V_2 * V_3 = F_16 ( V_28 ) ;
if ( V_3 ) {
F_17 ( V_4 , V_3 ) ;
F_18 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_30 -- ;
return V_3 ;
}
}
return NULL ;
}
static unsigned int F_19 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
unsigned int V_34 ;
struct V_1 * V_28 ;
for ( V_31 = V_7 -> V_27 - 1 ; V_31 >= 0 ; V_31 -- ) {
V_28 = V_7 -> V_23 [ V_31 ] ;
if ( V_28 -> V_32 -> V_35 && ( V_34 = V_28 -> V_32 -> V_35 ( V_28 ) ) != 0 ) {
V_4 -> V_36 . V_37 -= V_34 ;
V_4 -> V_7 . V_30 -- ;
return V_34 ;
}
}
return 0 ;
}
static void
F_20 ( struct V_1 * V_4 )
{
int V_31 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
for ( V_31 = 0 ; V_31 < V_7 -> V_27 ; V_31 ++ )
F_21 ( V_7 -> V_23 [ V_31 ] ) ;
V_4 -> V_36 . V_37 = 0 ;
V_4 -> V_7 . V_30 = 0 ;
}
static void
F_22 ( struct V_1 * V_4 )
{
int V_31 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_23 ( & V_7 -> V_18 ) ;
for ( V_31 = 0 ; V_31 < V_7 -> V_27 ; V_31 ++ )
F_24 ( V_7 -> V_23 [ V_31 ] ) ;
}
static int F_25 ( struct V_1 * V_4 , struct V_38 * V_39 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_23 [ V_40 ] ;
int V_41 = V_7 -> V_27 , V_42 ;
struct V_43 * V_44 ;
if ( F_26 ( V_39 ) < sizeof( * V_44 ) )
return - V_45 ;
V_44 = F_27 ( V_39 ) ;
if ( V_44 -> V_27 > V_40 || V_44 -> V_27 < 2 )
return - V_45 ;
for ( V_42 = 0 ; V_42 <= V_25 ; V_42 ++ ) {
if ( V_44 -> V_46 [ V_42 ] >= V_44 -> V_27 )
return - V_45 ;
}
for ( V_42 = V_41 ; V_42 < V_44 -> V_27 ; V_42 ++ ) {
V_23 [ V_42 ] = F_28 ( V_4 -> V_47 , & V_48 ,
F_29 ( V_4 -> V_17 , V_42 + 1 ) ) ;
if ( ! V_23 [ V_42 ] ) {
while ( V_42 > V_41 )
F_24 ( V_23 [ -- V_42 ] ) ;
return - V_49 ;
}
}
F_30 ( V_4 ) ;
V_7 -> V_27 = V_44 -> V_27 ;
memcpy ( V_7 -> V_24 , V_44 -> V_46 , V_25 + 1 ) ;
for ( V_42 = V_7 -> V_27 ; V_42 < V_41 ; V_42 ++ ) {
struct V_1 * V_50 = V_7 -> V_23 [ V_42 ] ;
F_31 ( V_50 , V_50 -> V_7 . V_30 ,
V_50 -> V_36 . V_37 ) ;
F_24 ( V_50 ) ;
}
for ( V_42 = V_41 ; V_42 < V_7 -> V_27 ; V_42 ++ )
V_7 -> V_23 [ V_42 ] = V_23 [ V_42 ] ;
F_32 ( V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_4 , struct V_38 * V_39 )
{
if ( ! V_39 )
return - V_45 ;
return F_25 ( V_4 , V_39 ) ;
}
static int F_34 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_51 = F_35 ( V_3 ) ;
struct V_43 V_39 ;
V_39 . V_27 = V_7 -> V_27 ;
memcpy ( & V_39 . V_46 , V_7 -> V_24 , V_25 + 1 ) ;
if ( F_36 ( V_3 , V_52 , sizeof( V_39 ) , & V_39 ) )
goto V_53;
return V_3 -> V_34 ;
V_53:
F_37 ( V_3 , V_51 ) ;
return - 1 ;
}
static int F_38 ( struct V_1 * V_4 , unsigned long V_54 , struct V_1 * V_55 ,
struct V_1 * * V_56 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_54 - 1 ;
if ( V_55 == NULL )
V_55 = & V_57 ;
* V_56 = F_39 ( V_4 , V_55 , & V_7 -> V_23 [ V_8 ] ) ;
return 0 ;
}
static struct V_1 *
F_40 ( struct V_1 * V_4 , unsigned long V_54 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_54 - 1 ;
return V_7 -> V_23 [ V_8 ] ;
}
static unsigned long F_41 ( struct V_1 * V_4 , T_1 V_26 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_7 ( V_26 ) ;
if ( V_8 - 1 >= V_7 -> V_27 )
return 0 ;
return V_8 ;
}
static unsigned long F_42 ( struct V_1 * V_4 , unsigned long V_58 , T_1 V_26 )
{
return F_41 ( V_4 , V_26 ) ;
}
static void F_43 ( struct V_1 * V_7 , unsigned long V_59 )
{
}
static int F_44 ( struct V_1 * V_4 , unsigned long V_59 , struct V_2 * V_3 ,
struct V_60 * V_61 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_61 -> V_62 |= F_7 ( V_59 ) ;
V_61 -> V_63 = V_7 -> V_23 [ V_59 - 1 ] -> V_17 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_4 , unsigned long V_59 ,
struct V_64 * V_65 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_66 ;
V_66 = V_7 -> V_23 [ V_59 - 1 ] ;
if ( F_46 ( V_65 , NULL , & V_66 -> V_67 ) < 0 ||
F_47 ( V_65 , NULL , & V_66 -> V_36 , V_66 -> V_7 . V_30 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_4 , struct V_68 * V_54 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_31 ;
if ( V_54 -> V_69 )
return;
for ( V_31 = 0 ; V_31 < V_7 -> V_27 ; V_31 ++ ) {
if ( V_54 -> V_70 < V_54 -> V_71 ) {
V_54 -> V_70 ++ ;
continue;
}
if ( V_54 -> V_72 ( V_4 , V_31 + 1 , V_54 ) < 0 ) {
V_54 -> V_69 = 1 ;
break;
}
V_54 -> V_70 ++ ;
}
}
static struct V_12 T_2 * * F_49 ( struct V_1 * V_4 ,
unsigned long V_59 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_59 )
return NULL ;
return & V_7 -> V_18 ;
}
static int T_3 F_50 ( void )
{
return F_51 ( & V_73 ) ;
}
static void T_4 F_52 ( void )
{
F_53 ( & V_73 ) ;
}
