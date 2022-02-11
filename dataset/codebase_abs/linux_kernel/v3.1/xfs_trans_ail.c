STATIC void
F_1 (
struct V_1 * V_2 ,
T_1 * V_3 )
{
T_1 * V_4 ;
if ( F_2 ( & V_2 -> V_5 ) )
return;
ASSERT ( ( V_3 -> V_6 & V_7 ) != 0 ) ;
V_4 = F_3 ( V_3 -> V_8 . V_9 , T_1 , V_8 ) ;
if ( & V_4 -> V_8 != & V_2 -> V_5 )
ASSERT ( F_4 ( V_4 -> V_10 , V_3 -> V_10 ) <= 0 ) ;
V_4 = F_3 ( V_3 -> V_8 . V_11 , T_1 , V_8 ) ;
if ( & V_4 -> V_8 != & V_2 -> V_5 )
ASSERT ( F_4 ( V_4 -> V_10 , V_3 -> V_10 ) >= 0 ) ;
#ifdef F_5
V_4 = F_3 ( & V_2 -> V_5 , T_1 , V_8 ) ;
F_6 (lip, &ailp->xa_ail, li_ail) {
if ( & V_4 -> V_8 != & V_2 -> V_5 )
ASSERT ( F_4 ( V_4 -> V_10 , V_3 -> V_10 ) <= 0 ) ;
ASSERT ( ( V_3 -> V_6 & V_7 ) != 0 ) ;
V_4 = V_3 ;
}
#endif
}
static T_1 *
F_7 (
struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_5 ) )
return NULL ;
return F_8 ( & V_2 -> V_5 , T_1 , V_8 ) ;
}
static T_1 *
F_9 (
struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_5 ) )
return NULL ;
return F_3 ( V_2 -> V_5 . V_9 , T_1 , V_8 ) ;
}
static T_1 *
F_10 (
struct V_1 * V_2 ,
T_1 * V_3 )
{
if ( V_3 -> V_8 . V_11 == & V_2 -> V_5 )
return NULL ;
return F_8 ( & V_3 -> V_8 , T_1 , V_8 ) ;
}
T_2
F_11 (
struct V_1 * V_2 )
{
T_2 V_12 = 0 ;
T_1 * V_3 ;
F_12 ( & V_2 -> V_13 ) ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
V_12 = V_3 -> V_10 ;
F_13 ( & V_2 -> V_13 ) ;
return V_12 ;
}
static T_2
F_14 (
struct V_1 * V_2 )
{
T_2 V_12 = 0 ;
T_1 * V_3 ;
F_12 ( & V_2 -> V_13 ) ;
V_3 = F_9 ( V_2 ) ;
if ( V_3 )
V_12 = V_3 -> V_10 ;
F_13 ( & V_2 -> V_13 ) ;
return V_12 ;
}
STATIC void
F_15 (
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
V_15 -> V_16 = NULL ;
F_16 ( & V_15 -> V_17 , & V_2 -> V_18 ) ;
}
struct V_19 *
F_17 (
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_19 * V_3 = V_15 -> V_16 ;
if ( ( V_20 ) V_3 & 1 )
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
V_15 -> V_16 = F_10 ( V_2 , V_3 ) ;
return V_3 ;
}
void
F_18 (
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
V_15 -> V_16 = NULL ;
F_19 ( & V_15 -> V_17 ) ;
}
STATIC void
F_20 (
struct V_1 * V_2 ,
struct V_19 * V_3 )
{
struct V_14 * V_15 ;
F_6 (cur, &ailp->xa_cursors, list) {
if ( V_15 -> V_16 == V_3 )
V_15 -> V_16 = (struct V_19 * )
( ( V_20 ) V_15 -> V_16 | 1 ) ;
}
}
T_1 *
F_21 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
T_2 V_12 )
{
T_1 * V_3 ;
F_15 ( V_2 , V_15 ) ;
if ( V_12 == 0 ) {
V_3 = F_7 ( V_2 ) ;
goto V_21;
}
F_6 (lip, &ailp->xa_ail, li_ail) {
if ( F_4 ( V_3 -> V_10 , V_12 ) >= 0 )
goto V_21;
}
return NULL ;
V_21:
if ( V_3 )
V_15 -> V_16 = F_10 ( V_2 , V_3 ) ;
return V_3 ;
}
static struct V_19 *
F_22 (
struct V_1 * V_2 ,
T_2 V_12 )
{
T_1 * V_3 ;
F_23 (lip, &ailp->xa_ail, li_ail) {
if ( F_4 ( V_3 -> V_10 , V_12 ) <= 0 )
return V_3 ;
}
return NULL ;
}
struct V_19 *
F_24 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
T_2 V_12 )
{
F_15 ( V_2 , V_15 ) ;
V_15 -> V_16 = F_22 ( V_2 , V_12 ) ;
return V_15 -> V_16 ;
}
static void
F_25 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_22 * V_17 ,
T_2 V_12 )
{
struct V_19 * V_3 ;
ASSERT ( ! F_2 ( V_17 ) ) ;
V_3 = V_15 ? V_15 -> V_16 : NULL ;
if ( ! V_3 || ( V_20 ) V_3 & 1 )
V_3 = F_22 ( V_2 , V_12 ) ;
if ( V_15 )
V_15 -> V_16 = F_3 ( V_17 -> V_9 , struct V_19 , V_8 ) ;
if ( V_3 )
F_26 ( V_17 , & V_3 -> V_8 ) ;
else
F_26 ( V_17 , & V_2 -> V_5 ) ;
}
static void
F_27 (
struct V_1 * V_2 ,
T_1 * V_3 )
{
F_1 ( V_2 , V_3 ) ;
F_28 ( & V_3 -> V_8 ) ;
F_20 ( V_2 , V_3 ) ;
}
static long
F_29 (
struct V_1 * V_2 )
{
T_3 * V_23 = V_2 -> V_24 ;
struct V_14 V_15 ;
T_1 * V_3 ;
T_2 V_12 ;
T_2 V_25 ;
long V_26 = 10 ;
int V_27 = 0 ;
int V_28 = 0 ;
int V_29 = 0 ;
int V_30 = 0 ;
F_12 ( & V_2 -> V_13 ) ;
V_25 = V_2 -> V_31 ;
V_3 = F_21 ( V_2 , & V_15 , V_2 -> V_32 ) ;
if ( ! V_3 || F_30 ( V_23 ) ) {
F_18 ( V_2 , & V_15 ) ;
F_13 ( & V_2 -> V_13 ) ;
goto V_33;
}
F_31 ( V_34 ) ;
V_12 = V_3 -> V_10 ;
while ( ( F_4 ( V_3 -> V_10 , V_25 ) <= 0 ) ) {
int V_35 ;
V_35 = F_32 ( V_3 ) ;
F_13 ( & V_2 -> V_13 ) ;
switch ( V_35 ) {
case V_36 :
F_31 ( V_37 ) ;
F_33 ( V_3 ) ;
V_2 -> V_32 = V_12 ;
break;
case V_38 :
F_31 ( V_39 ) ;
if ( ! F_34 ( V_3 ) ) {
V_28 ++ ;
V_27 = 1 ;
} else {
V_2 -> V_32 = V_12 ;
}
V_30 = 1 ;
break;
case V_40 :
F_31 ( V_41 ) ;
V_28 ++ ;
V_27 = 1 ;
break;
case V_42 :
F_31 ( V_43 ) ;
V_28 ++ ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_12 ( & V_2 -> V_13 ) ;
if ( F_30 ( V_23 ) )
break;
ASSERT ( V_23 -> V_44 ) ;
V_29 ++ ;
if ( V_28 > 100 )
break;
V_3 = F_17 ( V_2 , & V_15 ) ;
if ( V_3 == NULL )
break;
V_12 = V_3 -> V_10 ;
}
F_18 ( V_2 , & V_15 ) ;
F_13 ( & V_2 -> V_13 ) ;
if ( V_27 ) {
F_31 ( V_45 ) ;
F_35 ( V_23 , 0 ) ;
}
if ( V_30 ) {
F_36 ( V_23 -> V_46 -> V_47 ) ;
}
V_33:
if ( ! V_29 ) {
V_2 -> V_32 = 0 ;
V_26 = 50 ;
} else if ( F_4 ( V_12 , V_25 ) >= 0 ) {
V_26 = 50 ;
V_2 -> V_32 = 0 ;
} else if ( ( V_28 * 100 ) / V_29 > 90 ) {
V_26 = 20 ;
}
return V_26 ;
}
static int
F_37 (
void * V_48 )
{
struct V_1 * V_2 = V_48 ;
long V_26 = 0 ;
while ( ! F_38 () ) {
if ( V_26 && V_26 <= 20 )
F_39 ( V_49 ) ;
else
F_39 ( V_50 ) ;
F_40 ( V_26 ?
F_41 ( V_26 ) : V_51 ) ;
F_42 () ;
V_26 = F_29 ( V_2 ) ;
}
return 0 ;
}
void
F_43 (
struct V_1 * V_2 ,
T_2 V_52 )
{
T_1 * V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( ! V_3 || F_30 ( V_2 -> V_24 ) ||
F_4 ( V_52 , V_2 -> V_31 ) <= 0 )
return;
F_44 () ;
F_45 ( V_2 , & V_2 -> V_31 , & V_52 ) ;
F_44 () ;
F_36 ( V_2 -> V_53 ) ;
}
void
F_46 (
struct V_1 * V_2 )
{
T_2 V_52 = F_14 ( V_2 ) ;
if ( V_52 )
F_43 ( V_2 , V_52 ) ;
}
void
F_47 (
struct V_1 * V_2 ,
T_1 * V_3 )
{
T_1 * V_54 ;
if ( ! ( V_3 -> V_6 & V_7 ) ||
F_30 ( V_2 -> V_24 ) ) {
return;
}
V_54 = F_7 ( V_2 ) ;
if ( V_54 == V_3 )
F_48 ( V_2 -> V_24 , 1 ) ;
}
void
F_49 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_19 * * V_55 ,
int V_56 ,
T_2 V_12 ) __releases( V_2 -> V_13 )
{
T_1 * V_57 ;
T_2 V_58 ;
int V_59 = 0 ;
int V_60 ;
F_50 ( V_61 ) ;
ASSERT ( V_56 > 0 ) ;
V_57 = F_7 ( V_2 ) ;
for ( V_60 = 0 ; V_60 < V_56 ; V_60 ++ ) {
struct V_19 * V_3 = V_55 [ V_60 ] ;
if ( V_3 -> V_6 & V_7 ) {
if ( F_4 ( V_12 , V_3 -> V_10 ) <= 0 )
continue;
F_27 ( V_2 , V_3 ) ;
if ( V_57 == V_3 )
V_59 = 1 ;
} else {
V_3 -> V_6 |= V_7 ;
}
V_3 -> V_10 = V_12 ;
F_51 ( & V_3 -> V_8 , & V_61 ) ;
}
if ( ! F_2 ( & V_61 ) )
F_25 ( V_2 , V_15 , & V_61 , V_12 ) ;
if ( ! V_59 ) {
F_13 ( & V_2 -> V_13 ) ;
return;
}
V_57 = F_7 ( V_2 ) ;
V_58 = V_57 -> V_10 ;
F_13 ( & V_2 -> V_13 ) ;
F_48 ( V_2 -> V_24 , V_58 ) ;
}
void
F_52 (
struct V_1 * V_2 ,
struct V_19 * * V_55 ,
int V_56 ) __releases( V_2 -> V_13 )
{
T_1 * V_57 ;
T_2 V_58 ;
int V_59 = 0 ;
int V_60 ;
V_57 = F_7 ( V_2 ) ;
for ( V_60 = 0 ; V_60 < V_56 ; V_60 ++ ) {
struct V_19 * V_3 = V_55 [ V_60 ] ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
struct V_62 * V_23 = V_2 -> V_24 ;
F_13 ( & V_2 -> V_13 ) ;
if ( ! F_30 ( V_23 ) ) {
F_53 ( V_23 , V_63 ,
L_1 ,
V_64 ) ;
F_54 ( V_23 , V_65 ) ;
}
return;
}
F_27 ( V_2 , V_3 ) ;
V_3 -> V_6 &= ~ V_7 ;
V_3 -> V_10 = 0 ;
if ( V_57 == V_3 )
V_59 = 1 ;
}
if ( ! V_59 ) {
F_13 ( & V_2 -> V_13 ) ;
return;
}
V_57 = F_7 ( V_2 ) ;
V_58 = V_57 ? V_57 -> V_10 : 0 ;
F_13 ( & V_2 -> V_13 ) ;
F_48 ( V_2 -> V_24 , V_58 ) ;
}
int
F_55 (
T_3 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( sizeof( struct V_1 ) , V_66 ) ;
if ( ! V_2 )
return V_67 ;
V_2 -> V_24 = V_23 ;
F_57 ( & V_2 -> V_5 ) ;
F_57 ( & V_2 -> V_18 ) ;
F_58 ( & V_2 -> V_13 ) ;
V_2 -> V_53 = F_59 ( F_37 , V_2 , L_2 ,
V_2 -> V_24 -> V_68 ) ;
if ( F_60 ( V_2 -> V_53 ) )
goto V_69;
V_23 -> V_70 = V_2 ;
return 0 ;
V_69:
F_61 ( V_2 ) ;
return V_67 ;
}
void
F_62 (
T_3 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_70 ;
F_63 ( V_2 -> V_53 ) ;
F_61 ( V_2 ) ;
}
