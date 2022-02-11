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
if ( V_15 == & V_2 -> V_17 )
return;
V_15 -> V_11 = V_2 -> V_17 . V_11 ;
V_2 -> V_17 . V_11 = V_15 ;
}
STATIC void
F_16 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_18 * V_3 )
{
if ( V_3 )
V_15 -> V_16 = F_10 ( V_2 , V_3 ) ;
}
struct V_18 *
F_17 (
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_18 * V_3 = V_15 -> V_16 ;
if ( ( V_19 ) V_3 & 1 )
V_3 = F_7 ( V_2 ) ;
F_16 ( V_2 , V_15 , V_3 ) ;
return V_3 ;
}
void
F_18 (
struct V_1 * V_2 ,
struct V_14 * V_20 )
{
struct V_14 * V_9 = NULL ;
struct V_14 * V_15 ;
V_20 -> V_16 = NULL ;
if ( V_20 == & V_2 -> V_17 )
return;
V_9 = & V_2 -> V_17 ;
for ( V_15 = V_9 -> V_11 ; V_15 ; V_9 = V_15 , V_15 = V_9 -> V_11 ) {
if ( V_15 == V_20 ) {
V_9 -> V_11 = V_15 -> V_11 ;
break;
}
}
ASSERT ( V_15 ) ;
}
STATIC void
F_19 (
struct V_1 * V_2 ,
struct V_18 * V_3 )
{
struct V_14 * V_15 ;
for ( V_15 = & V_2 -> V_17 ; V_15 ; V_15 = V_15 -> V_11 ) {
if ( V_15 -> V_16 == V_3 )
V_15 -> V_16 = (struct V_18 * )
( ( V_19 ) V_15 -> V_16 | 1 ) ;
}
}
T_1 *
F_20 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
T_2 V_12 )
{
T_1 * V_3 ;
F_15 ( V_2 , V_15 ) ;
V_3 = F_7 ( V_2 ) ;
if ( V_12 == 0 )
goto V_21;
F_6 (lip, &ailp->xa_ail, li_ail) {
if ( F_4 ( V_3 -> V_10 , V_12 ) >= 0 )
goto V_21;
}
V_3 = NULL ;
V_21:
F_16 ( V_2 , V_15 , V_3 ) ;
return V_3 ;
}
static void
F_21 (
struct V_1 * V_2 ,
struct V_22 * V_23 ,
T_2 V_12 )
{
T_1 * V_24 ;
if ( F_2 ( & V_2 -> V_5 ) ) {
F_22 ( V_23 , & V_2 -> V_5 ) ;
return;
}
F_23 (next_lip, &ailp->xa_ail, li_ail) {
if ( F_4 ( V_24 -> V_10 , V_12 ) <= 0 )
break;
}
ASSERT ( & V_24 -> V_8 == & V_2 -> V_5 ||
F_4 ( V_24 -> V_10 , V_12 ) <= 0 ) ;
F_24 ( V_23 , & V_24 -> V_8 ) ;
}
static void
F_25 (
struct V_1 * V_2 ,
T_1 * V_3 )
{
F_1 ( V_2 , V_3 ) ;
F_26 ( & V_3 -> V_8 ) ;
F_19 ( V_2 , V_3 ) ;
}
STATIC void
F_27 (
struct V_25 * V_26 )
{
struct V_1 * V_2 = F_28 ( F_29 ( V_26 ) ,
struct V_1 , V_27 ) ;
T_3 * V_28 = V_2 -> V_29 ;
struct V_14 * V_15 = & V_2 -> V_17 ;
T_1 * V_3 ;
T_2 V_12 ;
T_2 V_30 ;
long V_31 = 10 ;
int V_32 = 0 ;
int V_33 = 0 ;
int V_34 = 0 ;
int V_35 = 0 ;
F_12 ( & V_2 -> V_13 ) ;
V_30 = V_2 -> V_36 ;
F_15 ( V_2 , V_15 ) ;
V_3 = F_20 ( V_2 , V_15 , V_2 -> V_37 ) ;
if ( ! V_3 || F_30 ( V_28 ) ) {
F_18 ( V_2 , V_15 ) ;
F_13 ( & V_2 -> V_13 ) ;
goto V_38;
}
F_31 ( V_39 ) ;
V_12 = V_3 -> V_10 ;
while ( ( F_4 ( V_3 -> V_10 , V_30 ) <= 0 ) ) {
int V_40 ;
V_40 = F_32 ( V_3 ) ;
F_13 ( & V_2 -> V_13 ) ;
switch ( V_40 ) {
case V_41 :
F_31 ( V_42 ) ;
F_33 ( V_3 ) ;
V_2 -> V_37 = V_12 ;
break;
case V_43 :
F_31 ( V_44 ) ;
F_34 ( V_3 ) ;
V_2 -> V_37 = V_12 ;
V_35 = 1 ;
break;
case V_45 :
F_31 ( V_46 ) ;
V_33 ++ ;
V_32 = 1 ;
break;
case V_47 :
F_31 ( V_48 ) ;
V_2 -> V_37 = V_12 ;
V_33 ++ ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_12 ( & V_2 -> V_13 ) ;
if ( F_30 ( V_28 ) )
break;
ASSERT ( V_28 -> V_49 ) ;
V_34 ++ ;
if ( V_33 > 100 )
break;
V_3 = F_17 ( V_2 , V_15 ) ;
if ( V_3 == NULL )
break;
V_12 = V_3 -> V_10 ;
}
F_18 ( V_2 , V_15 ) ;
F_13 ( & V_2 -> V_13 ) ;
if ( V_32 ) {
F_31 ( V_50 ) ;
F_35 ( V_28 , 0 ) ;
}
if ( V_35 ) {
F_36 ( V_28 -> V_51 -> V_52 ) ;
}
V_38:
if ( ! V_34 ) {
V_2 -> V_37 = 0 ;
F_37 ( V_53 , & V_2 -> V_54 ) ;
F_38 () ;
if ( F_4 ( V_2 -> V_36 , V_30 ) == 0 ||
F_39 ( V_53 , & V_2 -> V_54 ) )
return;
V_31 = 50 ;
} else if ( F_4 ( V_12 , V_30 ) >= 0 ) {
V_31 = 50 ;
V_2 -> V_37 = 0 ;
} else if ( ( V_33 * 100 ) / V_34 > 90 ) {
V_31 = 20 ;
}
F_40 ( V_55 , & V_2 -> V_27 ,
F_41 ( V_31 ) ) ;
}
void
F_42 (
struct V_1 * V_2 ,
T_2 V_56 )
{
T_1 * V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( ! V_3 || F_30 ( V_2 -> V_29 ) ||
F_4 ( V_56 , V_2 -> V_36 ) <= 0 )
return;
F_43 () ;
F_44 ( V_2 , & V_2 -> V_36 , & V_56 ) ;
if ( ! F_39 ( V_53 , & V_2 -> V_54 ) )
F_40 ( V_55 , & V_2 -> V_27 , 0 ) ;
}
void
F_45 (
struct V_1 * V_2 )
{
T_2 V_56 = F_14 ( V_2 ) ;
if ( V_56 )
F_42 ( V_2 , V_56 ) ;
}
void
F_46 (
struct V_1 * V_2 ,
T_1 * V_3 )
{
T_1 * V_57 ;
if ( ! ( V_3 -> V_6 & V_7 ) ||
F_30 ( V_2 -> V_29 ) ) {
return;
}
V_57 = F_7 ( V_2 ) ;
if ( V_57 == V_3 )
F_47 ( V_2 -> V_29 , 1 ) ;
}
void
F_48 (
struct V_1 * V_2 ,
struct V_18 * * V_58 ,
int V_59 ,
T_2 V_12 ) __releases( V_2 -> V_13 )
{
T_1 * V_60 ;
T_2 V_61 ;
int V_62 = 0 ;
int V_63 ;
F_49 ( V_64 ) ;
V_60 = F_7 ( V_2 ) ;
for ( V_63 = 0 ; V_63 < V_59 ; V_63 ++ ) {
struct V_18 * V_3 = V_58 [ V_63 ] ;
if ( V_3 -> V_6 & V_7 ) {
if ( F_4 ( V_12 , V_3 -> V_10 ) <= 0 )
continue;
F_25 ( V_2 , V_3 ) ;
if ( V_60 == V_3 )
V_62 = 1 ;
} else {
V_3 -> V_6 |= V_7 ;
}
V_3 -> V_10 = V_12 ;
F_50 ( & V_3 -> V_8 , & V_64 ) ;
}
F_21 ( V_2 , & V_64 , V_12 ) ;
if ( ! V_62 ) {
F_13 ( & V_2 -> V_13 ) ;
return;
}
V_60 = F_7 ( V_2 ) ;
V_61 = V_60 -> V_10 ;
F_13 ( & V_2 -> V_13 ) ;
F_47 ( V_2 -> V_29 , V_61 ) ;
}
void
F_51 (
struct V_1 * V_2 ,
struct V_18 * * V_58 ,
int V_59 ) __releases( V_2 -> V_13 )
{
T_1 * V_60 ;
T_2 V_61 ;
int V_62 = 0 ;
int V_63 ;
V_60 = F_7 ( V_2 ) ;
for ( V_63 = 0 ; V_63 < V_59 ; V_63 ++ ) {
struct V_18 * V_3 = V_58 [ V_63 ] ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
struct V_65 * V_28 = V_2 -> V_29 ;
F_13 ( & V_2 -> V_13 ) ;
if ( ! F_30 ( V_28 ) ) {
F_52 ( V_28 , V_66 ,
L_1 ,
V_67 ) ;
F_53 ( V_28 , V_68 ) ;
}
return;
}
F_25 ( V_2 , V_3 ) ;
V_3 -> V_6 &= ~ V_7 ;
V_3 -> V_10 = 0 ;
if ( V_60 == V_3 )
V_62 = 1 ;
}
if ( ! V_62 ) {
F_13 ( & V_2 -> V_13 ) ;
return;
}
V_60 = F_7 ( V_2 ) ;
V_61 = V_60 ? V_60 -> V_10 : 0 ;
F_13 ( & V_2 -> V_13 ) ;
F_47 ( V_2 -> V_29 , V_61 ) ;
}
int
F_54 (
T_3 * V_28 )
{
struct V_1 * V_2 ;
V_2 = F_55 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_2 )
return V_70 ;
V_2 -> V_29 = V_28 ;
F_56 ( & V_2 -> V_5 ) ;
F_57 ( & V_2 -> V_13 ) ;
F_58 ( & V_2 -> V_27 , F_27 ) ;
V_28 -> V_71 = V_2 ;
return 0 ;
}
void
F_59 (
T_3 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_71 ;
F_60 ( & V_2 -> V_27 ) ;
F_61 ( V_2 ) ;
}
