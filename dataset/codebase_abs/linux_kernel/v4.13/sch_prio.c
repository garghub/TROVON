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
case V_21 :
* V_5 = V_15 | V_22 ;
case V_23 :
return NULL ;
}
#endif
if ( ! V_13 || V_14 < 0 ) {
if ( F_3 ( V_8 ) )
V_8 = 0 ;
return V_7 -> V_24 [ V_7 -> V_25 [ V_8 & V_26 ] ] ;
}
V_8 = V_11 . V_27 ;
}
V_8 = F_7 ( V_8 ) - 1 ;
if ( V_8 >= V_7 -> V_28 )
return V_7 -> V_24 [ V_7 -> V_25 [ 0 ] ] ;
return V_7 -> V_24 [ V_8 ] ;
}
static int
F_8 ( struct V_2 * V_3 , struct V_1 * V_4 , struct V_2 * * V_29 )
{
struct V_1 * V_30 ;
int V_31 ;
V_30 = F_1 ( V_3 , V_4 , & V_31 ) ;
#ifdef F_6
if ( V_30 == NULL ) {
if ( V_31 & V_16 )
F_9 ( V_4 ) ;
F_10 ( V_3 ) ;
return V_31 ;
}
#endif
V_31 = F_11 ( V_3 , V_30 , V_29 ) ;
if ( V_31 == V_15 ) {
F_12 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_32 ++ ;
return V_15 ;
}
if ( F_13 ( V_31 ) )
F_9 ( V_4 ) ;
return V_31 ;
}
static struct V_2 * F_14 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_7 -> V_28 ; V_33 ++ ) {
struct V_1 * V_30 = V_7 -> V_24 [ V_33 ] ;
struct V_2 * V_3 = V_30 -> V_34 -> V_35 ( V_30 ) ;
if ( V_3 )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_15 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_7 -> V_28 ; V_33 ++ ) {
struct V_1 * V_30 = V_7 -> V_24 [ V_33 ] ;
struct V_2 * V_3 = F_16 ( V_30 ) ;
if ( V_3 ) {
F_17 ( V_4 , V_3 ) ;
F_18 ( V_4 , V_3 ) ;
V_4 -> V_7 . V_32 -- ;
return V_3 ;
}
}
return NULL ;
}
static void
F_19 ( struct V_1 * V_4 )
{
int V_33 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
for ( V_33 = 0 ; V_33 < V_7 -> V_28 ; V_33 ++ )
F_20 ( V_7 -> V_24 [ V_33 ] ) ;
V_4 -> V_36 . V_37 = 0 ;
V_4 -> V_7 . V_32 = 0 ;
}
static void
F_21 ( struct V_1 * V_4 )
{
int V_33 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_22 ( V_7 -> V_38 ) ;
for ( V_33 = 0 ; V_33 < V_7 -> V_28 ; V_33 ++ )
F_23 ( V_7 -> V_24 [ V_33 ] ) ;
}
static int F_24 ( struct V_1 * V_4 , struct V_39 * V_40 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_24 [ V_41 ] ;
int V_42 = V_7 -> V_28 , V_43 ;
struct V_44 * V_45 ;
if ( F_25 ( V_40 ) < sizeof( * V_45 ) )
return - V_46 ;
V_45 = F_26 ( V_40 ) ;
if ( V_45 -> V_28 > V_41 || V_45 -> V_28 < 2 )
return - V_46 ;
for ( V_43 = 0 ; V_43 <= V_26 ; V_43 ++ ) {
if ( V_45 -> V_47 [ V_43 ] >= V_45 -> V_28 )
return - V_46 ;
}
for ( V_43 = V_42 ; V_43 < V_45 -> V_28 ; V_43 ++ ) {
V_24 [ V_43 ] = F_27 ( V_4 -> V_48 , & V_49 ,
F_28 ( V_4 -> V_17 , V_43 + 1 ) ) ;
if ( ! V_24 [ V_43 ] ) {
while ( V_43 > V_42 )
F_23 ( V_24 [ -- V_43 ] ) ;
return - V_50 ;
}
}
F_29 ( V_4 ) ;
V_7 -> V_28 = V_45 -> V_28 ;
memcpy ( V_7 -> V_25 , V_45 -> V_47 , V_26 + 1 ) ;
for ( V_43 = V_7 -> V_28 ; V_43 < V_42 ; V_43 ++ ) {
struct V_1 * V_51 = V_7 -> V_24 [ V_43 ] ;
F_30 ( V_51 , V_51 -> V_7 . V_32 ,
V_51 -> V_36 . V_37 ) ;
F_23 ( V_51 ) ;
}
for ( V_43 = V_42 ; V_43 < V_7 -> V_28 ; V_43 ++ ) {
V_7 -> V_24 [ V_43 ] = V_24 [ V_43 ] ;
if ( V_7 -> V_24 [ V_43 ] != & V_52 )
F_31 ( V_7 -> V_24 [ V_43 ] , true ) ;
}
F_32 ( V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_4 , struct V_39 * V_40 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_14 ;
if ( ! V_40 )
return - V_46 ;
V_14 = F_34 ( & V_7 -> V_38 , & V_7 -> V_18 ) ;
if ( V_14 )
return V_14 ;
return F_24 ( V_4 , V_40 ) ;
}
static int F_35 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned char * V_53 = F_36 ( V_3 ) ;
struct V_44 V_40 ;
V_40 . V_28 = V_7 -> V_28 ;
memcpy ( & V_40 . V_47 , V_7 -> V_25 , V_26 + 1 ) ;
if ( F_37 ( V_3 , V_54 , sizeof( V_40 ) , & V_40 ) )
goto V_55;
return V_3 -> V_56 ;
V_55:
F_38 ( V_3 , V_53 ) ;
return - 1 ;
}
static int F_39 ( struct V_1 * V_4 , unsigned long V_57 , struct V_1 * V_58 ,
struct V_1 * * V_59 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_57 - 1 ;
if ( V_58 == NULL )
V_58 = & V_52 ;
* V_59 = F_40 ( V_4 , V_58 , & V_7 -> V_24 [ V_8 ] ) ;
return 0 ;
}
static struct V_1 *
F_41 ( struct V_1 * V_4 , unsigned long V_57 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = V_57 - 1 ;
return V_7 -> V_24 [ V_8 ] ;
}
static unsigned long F_42 ( struct V_1 * V_4 , T_1 V_27 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long V_8 = F_7 ( V_27 ) ;
if ( V_8 - 1 >= V_7 -> V_28 )
return 0 ;
return V_8 ;
}
static unsigned long F_43 ( struct V_1 * V_4 , unsigned long V_60 , T_1 V_27 )
{
return F_42 ( V_4 , V_27 ) ;
}
static void F_44 ( struct V_1 * V_7 , unsigned long V_61 )
{
}
static int F_45 ( struct V_1 * V_4 , unsigned long V_61 , struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_63 -> V_64 |= F_7 ( V_61 ) ;
V_63 -> V_65 = V_7 -> V_24 [ V_61 - 1 ] -> V_17 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_4 , unsigned long V_61 ,
struct V_66 * V_67 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_1 * V_68 ;
V_68 = V_7 -> V_24 [ V_61 - 1 ] ;
if ( F_47 ( F_48 ( V_4 ) ,
V_67 , NULL , & V_68 -> V_69 ) < 0 ||
F_49 ( V_67 , NULL , & V_68 -> V_36 , V_68 -> V_7 . V_32 ) < 0 )
return - 1 ;
return 0 ;
}
static void F_50 ( struct V_1 * V_4 , struct V_70 * V_57 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
int V_33 ;
if ( V_57 -> V_71 )
return;
for ( V_33 = 0 ; V_33 < V_7 -> V_28 ; V_33 ++ ) {
if ( V_57 -> V_72 < V_57 -> V_73 ) {
V_57 -> V_72 ++ ;
continue;
}
if ( V_57 -> V_74 ( V_4 , V_33 + 1 , V_57 ) < 0 ) {
V_57 -> V_71 = 1 ;
break;
}
V_57 -> V_72 ++ ;
}
}
static struct V_75 * F_51 ( struct V_1 * V_4 , unsigned long V_61 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
if ( V_61 )
return NULL ;
return V_7 -> V_38 ;
}
static int T_2 F_52 ( void )
{
return F_53 ( & V_76 ) ;
}
static void T_3 F_54 ( void )
{
F_55 ( & V_76 ) ;
}
