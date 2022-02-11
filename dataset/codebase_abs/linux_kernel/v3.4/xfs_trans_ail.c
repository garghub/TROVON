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
F_12 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_30 == 0 && V_2 -> V_31 &&
! F_2 ( & V_2 -> V_5 ) ) {
V_2 -> V_31 = 0 ;
F_13 ( & V_2 -> V_13 ) ;
F_30 ( V_32 ) ;
F_31 ( V_23 , V_33 ) ;
F_12 ( & V_2 -> V_13 ) ;
}
V_25 = V_2 -> V_34 ;
V_3 = F_21 ( V_2 , & V_15 , V_2 -> V_30 ) ;
if ( ! V_3 || F_32 ( V_23 ) ) {
F_18 ( V_2 , & V_15 ) ;
F_13 ( & V_2 -> V_13 ) ;
goto V_35;
}
F_30 ( V_36 ) ;
V_12 = V_3 -> V_10 ;
while ( ( F_4 ( V_3 -> V_10 , V_25 ) <= 0 ) ) {
int V_37 ;
V_37 = F_33 ( V_3 ) ;
F_13 ( & V_2 -> V_13 ) ;
switch ( V_37 ) {
case V_38 :
F_30 ( V_39 ) ;
F_34 ( V_3 ) ;
F_35 ( V_3 ) ;
V_2 -> V_30 = V_12 ;
break;
case V_40 :
F_30 ( V_41 ) ;
F_36 ( V_3 ) ;
if ( ! F_37 ( V_3 ) ) {
F_38 ( V_3 ) ;
V_27 ++ ;
V_2 -> V_31 ++ ;
} else {
V_2 -> V_30 = V_12 ;
}
V_29 = 1 ;
break;
case V_42 :
F_30 ( V_43 ) ;
F_39 ( V_3 ) ;
V_27 ++ ;
V_2 -> V_31 ++ ;
break;
case V_44 :
F_30 ( V_45 ) ;
F_40 ( V_3 ) ;
V_27 ++ ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_12 ( & V_2 -> V_13 ) ;
if ( F_32 ( V_23 ) )
break;
ASSERT ( V_23 -> V_46 ) ;
V_28 ++ ;
if ( V_27 > 100 )
break;
V_3 = F_17 ( V_2 , & V_15 ) ;
if ( V_3 == NULL )
break;
V_12 = V_3 -> V_10 ;
}
F_18 ( V_2 , & V_15 ) ;
F_13 ( & V_2 -> V_13 ) ;
if ( V_29 ) {
F_41 ( V_23 -> V_47 -> V_48 ) ;
}
V_35:
if ( ! V_28 ) {
V_2 -> V_30 = 0 ;
V_2 -> V_31 = 0 ;
V_26 = 50 ;
} else if ( F_4 ( V_12 , V_25 ) >= 0 ) {
V_26 = 50 ;
V_2 -> V_30 = 0 ;
} else if ( ( V_27 * 100 ) / V_28 > 90 ) {
V_26 = 20 ;
V_2 -> V_30 = 0 ;
}
return V_26 ;
}
static int
F_42 (
void * V_49 )
{
struct V_1 * V_2 = V_49 ;
long V_26 = 0 ;
while ( ! F_43 () ) {
if ( V_26 && V_26 <= 20 )
F_44 ( V_50 ) ;
else
F_44 ( V_51 ) ;
F_45 ( V_26 ?
F_46 ( V_26 ) : V_52 ) ;
F_47 () ;
V_26 = F_29 ( V_2 ) ;
}
return 0 ;
}
void
F_48 (
struct V_1 * V_2 ,
T_2 V_53 )
{
T_1 * V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( ! V_3 || F_32 ( V_2 -> V_24 ) ||
F_4 ( V_53 , V_2 -> V_34 ) <= 0 )
return;
F_49 () ;
F_50 ( V_2 , & V_2 -> V_34 , & V_53 ) ;
F_49 () ;
F_41 ( V_2 -> V_54 ) ;
}
void
F_51 (
struct V_1 * V_2 )
{
T_2 V_53 = F_14 ( V_2 ) ;
if ( V_53 )
F_48 ( V_2 , V_53 ) ;
}
void
F_52 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_19 * * V_55 ,
int V_56 ,
T_2 V_12 ) __releases( V_2 -> V_13 )
{
T_1 * V_57 ;
int V_58 = 0 ;
int V_59 ;
F_53 ( V_60 ) ;
ASSERT ( V_56 > 0 ) ;
V_57 = F_7 ( V_2 ) ;
for ( V_59 = 0 ; V_59 < V_56 ; V_59 ++ ) {
struct V_19 * V_3 = V_55 [ V_59 ] ;
if ( V_3 -> V_6 & V_7 ) {
if ( F_4 ( V_12 , V_3 -> V_10 ) <= 0 )
continue;
F_27 ( V_2 , V_3 ) ;
if ( V_57 == V_3 )
V_58 = 1 ;
} else {
V_3 -> V_6 |= V_7 ;
}
V_3 -> V_10 = V_12 ;
F_54 ( & V_3 -> V_8 , & V_60 ) ;
}
if ( ! F_2 ( & V_60 ) )
F_25 ( V_2 , V_15 , & V_60 , V_12 ) ;
F_13 ( & V_2 -> V_13 ) ;
if ( V_58 && ! F_32 ( V_2 -> V_24 ) ) {
F_55 ( V_2 -> V_24 ) ;
F_56 ( V_2 -> V_24 ) ;
}
}
void
F_57 (
struct V_1 * V_2 ,
struct V_19 * * V_55 ,
int V_56 ) __releases( V_2 -> V_13 )
{
T_1 * V_57 ;
int V_58 = 0 ;
int V_59 ;
V_57 = F_7 ( V_2 ) ;
for ( V_59 = 0 ; V_59 < V_56 ; V_59 ++ ) {
struct V_19 * V_3 = V_55 [ V_59 ] ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
struct V_61 * V_23 = V_2 -> V_24 ;
F_13 ( & V_2 -> V_13 ) ;
if ( ! F_32 ( V_23 ) ) {
F_58 ( V_23 , V_62 ,
L_1 ,
V_63 ) ;
F_59 ( V_23 , V_64 ) ;
}
return;
}
F_27 ( V_2 , V_3 ) ;
V_3 -> V_6 &= ~ V_7 ;
V_3 -> V_10 = 0 ;
if ( V_57 == V_3 )
V_58 = 1 ;
}
F_13 ( & V_2 -> V_13 ) ;
if ( V_58 && ! F_32 ( V_2 -> V_24 ) ) {
F_55 ( V_2 -> V_24 ) ;
F_56 ( V_2 -> V_24 ) ;
}
}
int
F_60 (
T_3 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( sizeof( struct V_1 ) , V_65 ) ;
if ( ! V_2 )
return V_66 ;
V_2 -> V_24 = V_23 ;
F_62 ( & V_2 -> V_5 ) ;
F_62 ( & V_2 -> V_18 ) ;
F_63 ( & V_2 -> V_13 ) ;
V_2 -> V_54 = F_64 ( F_42 , V_2 , L_2 ,
V_2 -> V_24 -> V_67 ) ;
if ( F_65 ( V_2 -> V_54 ) )
goto V_68;
V_23 -> V_69 = V_2 ;
return 0 ;
V_68:
F_66 ( V_2 ) ;
return V_66 ;
}
void
F_67 (
T_3 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_69 ;
F_68 ( V_2 -> V_54 ) ;
F_66 ( V_2 ) ;
}
