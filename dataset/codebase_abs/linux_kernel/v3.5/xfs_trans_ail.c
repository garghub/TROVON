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
T_1 *
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
long V_26 ;
int V_27 = 0 ;
int V_28 = 0 ;
int V_29 = 0 ;
if ( V_2 -> V_30 && V_2 -> V_31 == 0 &&
( ! F_30 ( & V_2 -> V_32 ) ||
F_11 ( V_2 ) ) ) {
V_2 -> V_30 = 0 ;
F_31 ( V_33 ) ;
F_32 ( V_23 , V_34 ) ;
}
F_12 ( & V_2 -> V_13 ) ;
V_3 = F_21 ( V_2 , & V_15 , V_2 -> V_31 ) ;
if ( ! V_3 ) {
F_18 ( V_2 , & V_15 ) ;
F_13 ( & V_2 -> V_13 ) ;
goto V_35;
}
F_31 ( V_36 ) ;
V_12 = V_3 -> V_10 ;
V_25 = V_2 -> V_37 ;
while ( ( F_4 ( V_3 -> V_10 , V_25 ) <= 0 ) ) {
int V_38 ;
V_38 = F_33 ( V_3 , & V_2 -> V_32 ) ;
switch ( V_38 ) {
case V_39 :
F_31 ( V_40 ) ;
F_34 ( V_3 ) ;
V_2 -> V_31 = V_12 ;
break;
case V_41 :
F_31 ( V_42 ) ;
F_35 ( V_3 ) ;
V_28 ++ ;
V_2 -> V_31 = V_12 ;
break;
case V_43 :
F_31 ( V_44 ) ;
F_36 ( V_3 ) ;
V_27 ++ ;
V_2 -> V_30 ++ ;
break;
case V_45 :
F_31 ( V_46 ) ;
F_37 ( V_3 ) ;
V_27 ++ ;
break;
default:
ASSERT ( 0 ) ;
break;
}
V_29 ++ ;
if ( V_27 > 100 )
break;
V_3 = F_17 ( V_2 , & V_15 ) ;
if ( V_3 == NULL )
break;
V_12 = V_3 -> V_10 ;
}
F_18 ( V_2 , & V_15 ) ;
F_13 ( & V_2 -> V_13 ) ;
if ( F_38 ( & V_2 -> V_32 ) )
V_2 -> V_30 ++ ;
if ( ! V_29 || F_4 ( V_12 , V_25 ) >= 0 ) {
V_35:
V_26 = 50 ;
V_2 -> V_31 = 0 ;
} else if ( ( ( V_27 + V_28 ) * 100 ) / V_29 > 90 ) {
V_26 = 20 ;
V_2 -> V_31 = 0 ;
} else {
V_26 = 10 ;
}
return V_26 ;
}
static int
F_39 (
void * V_47 )
{
struct V_1 * V_2 = V_47 ;
long V_26 = 0 ;
V_48 -> V_49 |= V_50 ;
while ( ! F_40 () ) {
if ( V_26 && V_26 <= 20 )
F_41 ( V_51 ) ;
else
F_41 ( V_52 ) ;
F_42 ( V_26 ?
F_43 ( V_26 ) : V_53 ) ;
F_44 () ;
V_26 = F_29 ( V_2 ) ;
}
return 0 ;
}
void
F_45 (
struct V_1 * V_2 ,
T_2 V_54 )
{
T_1 * V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( ! V_3 || F_46 ( V_2 -> V_24 ) ||
F_4 ( V_54 , V_2 -> V_37 ) <= 0 )
return;
F_47 () ;
F_48 ( V_2 , & V_2 -> V_37 , & V_54 ) ;
F_47 () ;
F_49 ( V_2 -> V_55 ) ;
}
void
F_50 (
struct V_1 * V_2 )
{
T_2 V_54 = F_14 ( V_2 ) ;
if ( V_54 )
F_45 ( V_2 , V_54 ) ;
}
void
F_51 (
struct V_1 * V_2 )
{
struct V_19 * V_3 ;
F_52 ( V_56 ) ;
F_12 ( & V_2 -> V_13 ) ;
while ( ( V_3 = F_9 ( V_2 ) ) != NULL ) {
F_53 ( & V_2 -> V_57 , & V_56 , V_58 ) ;
V_2 -> V_37 = V_3 -> V_10 ;
F_49 ( V_2 -> V_55 ) ;
F_13 ( & V_2 -> V_13 ) ;
F_54 () ;
F_12 ( & V_2 -> V_13 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
F_55 ( & V_2 -> V_57 , & V_56 ) ;
}
void
F_56 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_19 * * V_59 ,
int V_60 ,
T_2 V_12 ) __releases( V_2 -> V_13 )
{
T_1 * V_61 ;
int V_62 = 0 ;
int V_63 ;
F_57 ( V_64 ) ;
ASSERT ( V_60 > 0 ) ;
V_61 = F_7 ( V_2 ) ;
for ( V_63 = 0 ; V_63 < V_60 ; V_63 ++ ) {
struct V_19 * V_3 = V_59 [ V_63 ] ;
if ( V_3 -> V_6 & V_7 ) {
if ( F_4 ( V_12 , V_3 -> V_10 ) <= 0 )
continue;
F_27 ( V_2 , V_3 ) ;
if ( V_61 == V_3 )
V_62 = 1 ;
} else {
V_3 -> V_6 |= V_7 ;
}
V_3 -> V_10 = V_12 ;
F_58 ( & V_3 -> V_8 , & V_64 ) ;
}
if ( ! F_2 ( & V_64 ) )
F_25 ( V_2 , V_15 , & V_64 , V_12 ) ;
if ( V_62 ) {
if ( ! F_46 ( V_2 -> V_24 ) )
F_59 ( V_2 -> V_24 ) ;
F_13 ( & V_2 -> V_13 ) ;
F_60 ( V_2 -> V_24 ) ;
} else {
F_13 ( & V_2 -> V_13 ) ;
}
}
void
F_61 (
struct V_1 * V_2 ,
struct V_19 * * V_59 ,
int V_60 ,
int V_65 ) __releases( V_2 -> V_13 )
{
T_1 * V_61 ;
int V_62 = 0 ;
int V_63 ;
V_61 = F_7 ( V_2 ) ;
for ( V_63 = 0 ; V_63 < V_60 ; V_63 ++ ) {
struct V_19 * V_3 = V_59 [ V_63 ] ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
struct V_66 * V_23 = V_2 -> V_24 ;
F_13 ( & V_2 -> V_13 ) ;
if ( ! F_46 ( V_23 ) ) {
F_62 ( V_23 , V_67 ,
L_1 ,
V_68 ) ;
F_63 ( V_23 , V_65 ) ;
}
return;
}
F_27 ( V_2 , V_3 ) ;
V_3 -> V_6 &= ~ V_7 ;
V_3 -> V_10 = 0 ;
if ( V_61 == V_3 )
V_62 = 1 ;
}
if ( V_62 ) {
if ( ! F_46 ( V_2 -> V_24 ) )
F_59 ( V_2 -> V_24 ) ;
if ( F_2 ( & V_2 -> V_5 ) )
F_64 ( & V_2 -> V_57 ) ;
F_13 ( & V_2 -> V_13 ) ;
F_60 ( V_2 -> V_24 ) ;
} else {
F_13 ( & V_2 -> V_13 ) ;
}
}
int
F_65 (
T_3 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_2 )
return V_70 ;
V_2 -> V_24 = V_23 ;
F_67 ( & V_2 -> V_5 ) ;
F_67 ( & V_2 -> V_18 ) ;
F_68 ( & V_2 -> V_13 ) ;
F_67 ( & V_2 -> V_32 ) ;
F_69 ( & V_2 -> V_57 ) ;
V_2 -> V_55 = F_70 ( F_39 , V_2 , L_2 ,
V_2 -> V_24 -> V_71 ) ;
if ( F_71 ( V_2 -> V_55 ) )
goto V_72;
V_23 -> V_73 = V_2 ;
return 0 ;
V_72:
F_72 ( V_2 ) ;
return V_70 ;
}
void
F_73 (
T_3 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_73 ;
F_74 ( V_2 -> V_55 ) ;
F_72 ( V_2 ) ;
}
