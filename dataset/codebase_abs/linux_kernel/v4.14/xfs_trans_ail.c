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
}
static T_1 *
F_5 (
struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_5 ) )
return NULL ;
return F_3 ( V_2 -> V_5 . V_9 , T_1 , V_8 ) ;
}
static T_1 *
F_6 (
struct V_1 * V_2 ,
T_1 * V_3 )
{
if ( V_3 -> V_8 . V_11 == & V_2 -> V_5 )
return NULL ;
return F_7 ( & V_3 -> V_8 , T_1 , V_8 ) ;
}
T_2
F_8 (
struct V_1 * V_2 )
{
T_2 V_12 = 0 ;
T_1 * V_3 ;
F_9 ( & V_2 -> V_13 ) ;
V_3 = F_10 ( V_2 ) ;
if ( V_3 )
V_12 = V_3 -> V_10 ;
F_11 ( & V_2 -> V_13 ) ;
return V_12 ;
}
static T_2
F_12 (
struct V_1 * V_2 )
{
T_2 V_12 = 0 ;
T_1 * V_3 ;
F_9 ( & V_2 -> V_13 ) ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 )
V_12 = V_3 -> V_10 ;
F_11 ( & V_2 -> V_13 ) ;
return V_12 ;
}
STATIC void
F_13 (
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
V_15 -> V_16 = NULL ;
F_14 ( & V_15 -> V_17 , & V_2 -> V_18 ) ;
}
struct V_19 *
F_15 (
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_19 * V_3 = V_15 -> V_16 ;
if ( ( V_20 ) V_3 & 1 )
V_3 = F_10 ( V_2 ) ;
if ( V_3 )
V_15 -> V_16 = F_6 ( V_2 , V_3 ) ;
return V_3 ;
}
void
F_16 (
struct V_14 * V_15 )
{
V_15 -> V_16 = NULL ;
F_17 ( & V_15 -> V_17 ) ;
}
STATIC void
F_18 (
struct V_1 * V_2 ,
struct V_19 * V_3 )
{
struct V_14 * V_15 ;
F_19 (cur, &ailp->xa_cursors, list) {
if ( V_15 -> V_16 == V_3 )
V_15 -> V_16 = (struct V_19 * )
( ( V_20 ) V_15 -> V_16 | 1 ) ;
}
}
T_1 *
F_20 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
T_2 V_12 )
{
T_1 * V_3 ;
F_13 ( V_2 , V_15 ) ;
if ( V_12 == 0 ) {
V_3 = F_10 ( V_2 ) ;
goto V_21;
}
F_19 (lip, &ailp->xa_ail, li_ail) {
if ( F_4 ( V_3 -> V_10 , V_12 ) >= 0 )
goto V_21;
}
return NULL ;
V_21:
if ( V_3 )
V_15 -> V_16 = F_6 ( V_2 , V_3 ) ;
return V_3 ;
}
static struct V_19 *
F_21 (
struct V_1 * V_2 ,
T_2 V_12 )
{
T_1 * V_3 ;
F_22 (lip, &ailp->xa_ail, li_ail) {
if ( F_4 ( V_3 -> V_10 , V_12 ) <= 0 )
return V_3 ;
}
return NULL ;
}
struct V_19 *
F_23 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
T_2 V_12 )
{
F_13 ( V_2 , V_15 ) ;
V_15 -> V_16 = F_21 ( V_2 , V_12 ) ;
return V_15 -> V_16 ;
}
static void
F_24 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_22 * V_17 ,
T_2 V_12 )
{
struct V_19 * V_3 ;
ASSERT ( ! F_2 ( V_17 ) ) ;
V_3 = V_15 ? V_15 -> V_16 : NULL ;
if ( ! V_3 || ( V_20 ) V_3 & 1 )
V_3 = F_21 ( V_2 , V_12 ) ;
if ( V_15 )
V_15 -> V_16 = F_3 ( V_17 -> V_9 , struct V_19 , V_8 ) ;
if ( V_3 )
F_25 ( V_17 , & V_3 -> V_8 ) ;
else
F_25 ( V_17 , & V_2 -> V_5 ) ;
}
static void
F_26 (
struct V_1 * V_2 ,
T_1 * V_3 )
{
F_1 ( V_2 , V_3 ) ;
F_27 ( & V_3 -> V_8 ) ;
F_18 ( V_2 , V_3 ) ;
}
static inline T_3
F_28 (
struct V_1 * V_2 ,
struct V_19 * V_3 )
{
if ( F_29 ( false , V_2 -> V_23 , V_24 ) )
return V_25 ;
return V_3 -> V_26 -> V_27 ( V_3 , & V_2 -> V_28 ) ;
}
static long
F_30 (
struct V_1 * V_2 )
{
T_4 * V_29 = V_2 -> V_23 ;
struct V_14 V_15 ;
T_1 * V_3 ;
T_2 V_12 ;
T_2 V_30 ;
long V_31 ;
int V_32 = 0 ;
int V_33 = 0 ;
int V_34 = 0 ;
if ( V_2 -> V_35 && V_2 -> V_36 == 0 &&
( ! F_31 ( & V_2 -> V_28 ) ||
F_8 ( V_2 ) ) ) {
V_2 -> V_35 = 0 ;
F_32 ( V_29 , V_37 ) ;
F_33 ( V_29 , V_38 ) ;
}
F_9 ( & V_2 -> V_13 ) ;
F_34 () ;
V_30 = V_2 -> V_39 ;
V_2 -> V_40 = V_30 ;
V_3 = F_20 ( V_2 , & V_15 , V_2 -> V_36 ) ;
if ( ! V_3 ) {
F_16 ( & V_15 ) ;
F_11 ( & V_2 -> V_13 ) ;
goto V_41;
}
F_32 ( V_29 , V_42 ) ;
V_12 = V_3 -> V_10 ;
while ( ( F_4 ( V_3 -> V_10 , V_30 ) <= 0 ) ) {
int V_43 ;
V_43 = F_28 ( V_2 , V_3 ) ;
switch ( V_43 ) {
case V_44 :
F_32 ( V_29 , V_45 ) ;
F_35 ( V_3 ) ;
V_2 -> V_36 = V_12 ;
break;
case V_46 :
F_32 ( V_29 , V_47 ) ;
F_36 ( V_3 ) ;
V_33 ++ ;
V_2 -> V_36 = V_12 ;
break;
case V_25 :
F_32 ( V_29 , V_48 ) ;
F_37 ( V_3 ) ;
V_32 ++ ;
V_2 -> V_35 ++ ;
break;
case V_49 :
F_32 ( V_29 , V_50 ) ;
F_38 ( V_3 ) ;
V_32 ++ ;
break;
default:
ASSERT ( 0 ) ;
break;
}
V_34 ++ ;
if ( V_32 > 100 )
break;
V_3 = F_15 ( V_2 , & V_15 ) ;
if ( V_3 == NULL )
break;
V_12 = V_3 -> V_10 ;
}
F_16 ( & V_15 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( F_39 ( & V_2 -> V_28 ) )
V_2 -> V_35 ++ ;
if ( ! V_34 || F_4 ( V_12 , V_30 ) >= 0 ) {
V_41:
V_31 = 50 ;
V_2 -> V_36 = 0 ;
} else if ( ( ( V_32 + V_33 ) * 100 ) / V_34 > 90 ) {
V_31 = 20 ;
V_2 -> V_36 = 0 ;
} else {
V_31 = 10 ;
}
return V_31 ;
}
static int
F_40 (
void * V_51 )
{
struct V_1 * V_2 = V_51 ;
long V_31 = 0 ;
V_52 -> V_53 |= V_54 ;
F_41 () ;
while ( ! F_42 () ) {
if ( V_31 && V_31 <= 20 )
F_43 ( V_55 ) ;
else
F_43 ( V_56 ) ;
F_9 ( & V_2 -> V_13 ) ;
F_34 () ;
if ( ! F_10 ( V_2 ) &&
V_2 -> V_39 == V_2 -> V_40 ) {
F_11 ( & V_2 -> V_13 ) ;
F_44 () ;
V_31 = 0 ;
continue;
}
F_11 ( & V_2 -> V_13 ) ;
if ( V_31 )
F_45 ( F_46 ( V_31 ) ) ;
F_43 ( V_57 ) ;
F_47 () ;
V_31 = F_30 ( V_2 ) ;
}
return 0 ;
}
void
F_48 (
struct V_1 * V_2 ,
T_2 V_58 )
{
T_1 * V_3 ;
V_3 = F_10 ( V_2 ) ;
if ( ! V_3 || F_49 ( V_2 -> V_23 ) ||
F_4 ( V_58 , V_2 -> V_39 ) <= 0 )
return;
F_50 () ;
F_51 ( V_2 , & V_2 -> V_39 , & V_58 ) ;
F_50 () ;
F_52 ( V_2 -> V_59 ) ;
}
void
F_53 (
struct V_1 * V_2 )
{
T_2 V_58 = F_12 ( V_2 ) ;
if ( V_58 )
F_48 ( V_2 , V_58 ) ;
}
void
F_54 (
struct V_1 * V_2 )
{
struct V_19 * V_3 ;
F_55 ( V_60 ) ;
F_9 ( & V_2 -> V_13 ) ;
while ( ( V_3 = F_5 ( V_2 ) ) != NULL ) {
F_56 ( & V_2 -> V_61 , & V_60 , V_62 ) ;
V_2 -> V_39 = V_3 -> V_10 ;
F_52 ( V_2 -> V_59 ) ;
F_11 ( & V_2 -> V_13 ) ;
F_57 () ;
F_9 ( & V_2 -> V_13 ) ;
}
F_11 ( & V_2 -> V_13 ) ;
F_58 ( & V_2 -> V_61 , & V_60 ) ;
}
void
F_59 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_19 * * V_63 ,
int V_64 ,
T_2 V_12 ) __releases( V_2 -> V_13 )
{
T_1 * V_65 ;
int V_66 = 0 ;
int V_67 ;
F_60 ( V_68 ) ;
ASSERT ( V_64 > 0 ) ;
V_65 = F_10 ( V_2 ) ;
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ ) {
struct V_19 * V_3 = V_63 [ V_67 ] ;
if ( V_3 -> V_6 & V_7 ) {
if ( F_4 ( V_12 , V_3 -> V_10 ) <= 0 )
continue;
F_61 ( V_3 , V_3 -> V_10 , V_12 ) ;
F_26 ( V_2 , V_3 ) ;
if ( V_65 == V_3 )
V_66 = 1 ;
} else {
V_3 -> V_6 |= V_7 ;
F_62 ( V_3 , 0 , V_12 ) ;
}
V_3 -> V_10 = V_12 ;
F_63 ( & V_3 -> V_8 , & V_68 ) ;
}
if ( ! F_2 ( & V_68 ) )
F_24 ( V_2 , V_15 , & V_68 , V_12 ) ;
if ( V_66 ) {
if ( ! F_49 ( V_2 -> V_23 ) )
F_64 ( V_2 -> V_23 ) ;
F_11 ( & V_2 -> V_13 ) ;
F_65 ( V_2 -> V_23 ) ;
} else {
F_11 ( & V_2 -> V_13 ) ;
}
}
bool
F_66 (
struct V_1 * V_2 ,
struct V_19 * V_3 )
{
struct V_19 * V_65 = F_10 ( V_2 ) ;
F_67 ( V_3 , V_65 -> V_10 , V_3 -> V_10 ) ;
F_26 ( V_2 , V_3 ) ;
F_68 ( V_3 ) ;
V_3 -> V_6 &= ~ V_7 ;
V_3 -> V_10 = 0 ;
return V_65 == V_3 ;
}
void
F_69 (
struct V_1 * V_2 ,
struct V_19 * V_3 ,
int V_69 ) __releases( V_2 -> V_13 )
{
struct V_70 * V_29 = V_2 -> V_23 ;
bool V_66 ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
F_11 ( & V_2 -> V_13 ) ;
if ( ! F_49 ( V_29 ) ) {
F_70 ( V_29 , V_71 ,
L_1 ,
V_72 ) ;
F_71 ( V_29 , V_69 ) ;
}
return;
}
V_66 = F_66 ( V_2 , V_3 ) ;
if ( V_66 ) {
if ( ! F_49 ( V_29 ) )
F_64 ( V_29 ) ;
if ( F_2 ( & V_2 -> V_5 ) )
F_72 ( & V_2 -> V_61 ) ;
}
F_11 ( & V_2 -> V_13 ) ;
if ( V_66 )
F_65 ( V_2 -> V_23 ) ;
}
int
F_73 (
T_4 * V_29 )
{
struct V_1 * V_2 ;
V_2 = F_74 ( sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_23 = V_29 ;
F_75 ( & V_2 -> V_5 ) ;
F_75 ( & V_2 -> V_18 ) ;
F_76 ( & V_2 -> V_13 ) ;
F_75 ( & V_2 -> V_28 ) ;
F_77 ( & V_2 -> V_61 ) ;
V_2 -> V_59 = F_78 ( F_40 , V_2 , L_2 ,
V_2 -> V_23 -> V_75 ) ;
if ( F_79 ( V_2 -> V_59 ) )
goto V_76;
V_29 -> V_77 = V_2 ;
return 0 ;
V_76:
F_80 ( V_2 ) ;
return - V_74 ;
}
void
F_81 (
T_4 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_77 ;
F_82 ( V_2 -> V_59 ) ;
F_80 ( V_2 ) ;
}
