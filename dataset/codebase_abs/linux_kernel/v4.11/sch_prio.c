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
F_8 ( struct V_2 * V_3 , struct V_1 * V_4 , struct V_2 * * V_28 )
{
struct V_1 * V_29 ;
int V_30 ;
V_29 = F_1 ( V_3 , V_4 , & V_30 ) ;
#ifdef F_6
if ( V_29 == NULL ) {
if ( V_30 & V_16 )
F_9 ( V_4 ) ;
F_10 ( V_3 ) ;
return V_30 ;
}
#endif
V_30 = F_11 ( V_3 , V_29 , V_28 ) ;
if ( V_30 == V_15 ) {
F_12 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_31 ++ ;
return V_15 ;
}
if ( F_13 ( V_30 ) )
F_9 ( V_4 ) ;
return V_30 ;
}
static struct V_2 * F_14 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_7 -> V_27 ; V_32 ++ ) {
struct V_1 * V_29 = V_7 -> V_23 [ V_32 ] ;
struct V_2 * V_3 = V_29 -> V_33 -> V_34 ( V_29 ) ;
if ( V_3 )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_15 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_7 -> V_27 ; V_32 ++ ) {
struct V_1 * V_29 = V_7 -> V_23 [ V_32 ] ;
struct V_2 * V_3 = F_16 ( V_29 ) ;
if ( V_3 ) {
F_17 ( V_4 , V_3 ) ;
F_18 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_31 -- ;
return V_3 ;
}
}
return NULL ;
}
static void
F_19 ( struct V_1 * V_4 )
{
int V_32 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
for ( V_32 = 0 ; V_32 < V_7 -> V_27 ; V_32 ++ )
F_20 ( V_7 -> V_23 [ V_32 ] ) ;
V_4 -> V_35 . V_36 = 0 ;
V_4 -> V_7 . V_31 = 0 ;
}
static void
F_21 ( struct V_1 * V_4 )
{
int V_32 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_22 ( & V_7 -> V_18 ) ;
for ( V_32 = 0 ; V_32 < V_7 -> V_27 ; V_32 ++ )
F_23 ( V_7 -> V_23 [ V_32 ] ) ;
}
static int F_24 ( struct V_1 * V_4 , struct V_37 * V_38 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_23 [ V_39 ] ;
int V_40 = V_7 -> V_27 , V_41 ;
struct V_42 * V_43 ;
if ( F_25 ( V_38 ) < sizeof( * V_43 ) )
return - V_44 ;
V_43 = F_26 ( V_38 ) ;
if ( V_43 -> V_27 > V_39 || V_43 -> V_27 < 2 )
return - V_44 ;
for ( V_41 = 0 ; V_41 <= V_25 ; V_41 ++ ) {
if ( V_43 -> V_45 [ V_41 ] >= V_43 -> V_27 )
return - V_44 ;
}
for ( V_41 = V_40 ; V_41 < V_43 -> V_27 ; V_41 ++ ) {
V_23 [ V_41 ] = F_27 ( V_4 -> V_46 , & V_47 ,
F_28 ( V_4 -> V_17 , V_41 + 1 ) ) ;
if ( ! V_23 [ V_41 ] ) {
while ( V_41 > V_40 )
F_23 ( V_23 [ -- V_41 ] ) ;
return - V_48 ;
}
}
F_29 ( V_4 ) ;
V_7 -> V_27 = V_43 -> V_27 ;
memcpy ( V_7 -> V_24 , V_43 -> V_45 , V_25 + 1 ) ;
for ( V_41 = V_7 -> V_27 ; V_41 < V_40 ; V_41 ++ ) {
struct V_1 * V_49 = V_7 -> V_23 [ V_41 ] ;
F_30 ( V_49 , V_49 -> V_7 . V_31 ,
V_49 -> V_35 . V_36 ) ;
F_23 ( V_49 ) ;
}
for ( V_41 = V_40 ; V_41 < V_7 -> V_27 ; V_41 ++ )
V_7 -> V_23 [ V_41 ] = V_23 [ V_41 ] ;
F_31 ( V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_4 , struct V_37 * V_38 )
{
if ( ! V_38 )
return - V_44 ;
return F_24 ( V_4 , V_38 ) ;
}
static int F_33 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_50 = F_34 ( V_3 ) ;
struct V_42 V_38 ;
V_38 . V_27 = V_7 -> V_27 ;
memcpy ( & V_38 . V_45 , V_7 -> V_24 , V_25 + 1 ) ;
if ( F_35 ( V_3 , V_51 , sizeof( V_38 ) , & V_38 ) )
goto V_52;
return V_3 -> V_53 ;
V_52:
F_36 ( V_3 , V_50 ) ;
return - 1 ;
}
static int F_37 ( struct V_1 * V_4 , unsigned long V_54 , struct V_1 * V_55 ,
struct V_1 * * V_56 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_54 - 1 ;
if ( V_55 == NULL )
V_55 = & V_57 ;
* V_56 = F_38 ( V_4 , V_55 , & V_7 -> V_23 [ V_8 ] ) ;
return 0 ;
}
static struct V_1 *
F_39 ( struct V_1 * V_4 , unsigned long V_54 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_54 - 1 ;
return V_7 -> V_23 [ V_8 ] ;
}
static unsigned long F_40 ( struct V_1 * V_4 , T_1 V_26 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_7 ( V_26 ) ;
if ( V_8 - 1 >= V_7 -> V_27 )
return 0 ;
return V_8 ;
}
static unsigned long F_41 ( struct V_1 * V_4 , unsigned long V_58 , T_1 V_26 )
{
return F_40 ( V_4 , V_26 ) ;
}
static void F_42 ( struct V_1 * V_7 , unsigned long V_59 )
{
}
static int F_43 ( struct V_1 * V_4 , unsigned long V_59 , struct V_2 * V_3 ,
struct V_60 * V_61 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_61 -> V_62 |= F_7 ( V_59 ) ;
V_61 -> V_63 = V_7 -> V_23 [ V_59 - 1 ] -> V_17 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_4 , unsigned long V_59 ,
struct V_64 * V_65 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_66 ;
V_66 = V_7 -> V_23 [ V_59 - 1 ] ;
if ( F_45 ( F_46 ( V_4 ) ,
V_65 , NULL , & V_66 -> V_67 ) < 0 ||
F_47 ( V_65 , NULL , & V_66 -> V_35 , V_66 -> V_7 . V_31 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_4 , struct V_68 * V_54 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_32 ;
if ( V_54 -> V_69 )
return;
for ( V_32 = 0 ; V_32 < V_7 -> V_27 ; V_32 ++ ) {
if ( V_54 -> V_70 < V_54 -> V_71 ) {
V_54 -> V_70 ++ ;
continue;
}
if ( V_54 -> V_72 ( V_4 , V_32 + 1 , V_54 ) < 0 ) {
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
