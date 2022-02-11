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
struct V_1 * V_2 ,
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
static long
F_28 (
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
( ! F_29 ( & V_2 -> V_32 ) ||
F_8 ( V_2 ) ) ) {
V_2 -> V_30 = 0 ;
F_30 ( V_33 ) ;
F_31 ( V_23 , V_34 ) ;
}
F_9 ( & V_2 -> V_13 ) ;
F_32 () ;
V_25 = V_2 -> V_35 ;
V_2 -> V_36 = V_25 ;
V_3 = F_20 ( V_2 , & V_15 , V_2 -> V_31 ) ;
if ( ! V_3 ) {
F_16 ( V_2 , & V_15 ) ;
F_11 ( & V_2 -> V_13 ) ;
goto V_37;
}
F_30 ( V_38 ) ;
V_12 = V_3 -> V_10 ;
while ( ( F_4 ( V_3 -> V_10 , V_25 ) <= 0 ) ) {
int V_39 ;
V_39 = V_3 -> V_40 -> V_41 ( V_3 , & V_2 -> V_32 ) ;
switch ( V_39 ) {
case V_42 :
F_30 ( V_43 ) ;
F_33 ( V_3 ) ;
V_2 -> V_31 = V_12 ;
break;
case V_44 :
F_30 ( V_45 ) ;
F_34 ( V_3 ) ;
V_28 ++ ;
V_2 -> V_31 = V_12 ;
break;
case V_46 :
F_30 ( V_47 ) ;
F_35 ( V_3 ) ;
V_27 ++ ;
V_2 -> V_30 ++ ;
break;
case V_48 :
F_30 ( V_49 ) ;
F_36 ( V_3 ) ;
V_27 ++ ;
break;
default:
ASSERT ( 0 ) ;
break;
}
V_29 ++ ;
if ( V_27 > 100 )
break;
V_3 = F_15 ( V_2 , & V_15 ) ;
if ( V_3 == NULL )
break;
V_12 = V_3 -> V_10 ;
}
F_16 ( V_2 , & V_15 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( F_37 ( & V_2 -> V_32 ) )
V_2 -> V_30 ++ ;
if ( ! V_29 || F_4 ( V_12 , V_25 ) >= 0 ) {
V_37:
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
F_38 (
void * V_50 )
{
struct V_1 * V_2 = V_50 ;
long V_26 = 0 ;
V_51 -> V_52 |= V_53 ;
while ( ! F_39 () ) {
if ( V_26 && V_26 <= 20 )
F_40 ( V_54 ) ;
else
F_40 ( V_55 ) ;
F_9 ( & V_2 -> V_13 ) ;
F_32 () ;
if ( ! F_10 ( V_2 ) &&
V_2 -> V_35 == V_2 -> V_36 ) {
F_11 ( & V_2 -> V_13 ) ;
F_41 () ;
V_26 = 0 ;
continue;
}
F_11 ( & V_2 -> V_13 ) ;
if ( V_26 )
F_42 ( F_43 ( V_26 ) ) ;
F_40 ( V_56 ) ;
F_44 () ;
V_26 = F_28 ( V_2 ) ;
}
return 0 ;
}
void
F_45 (
struct V_1 * V_2 ,
T_2 V_57 )
{
T_1 * V_3 ;
V_3 = F_10 ( V_2 ) ;
if ( ! V_3 || F_46 ( V_2 -> V_24 ) ||
F_4 ( V_57 , V_2 -> V_35 ) <= 0 )
return;
F_47 () ;
F_48 ( V_2 , & V_2 -> V_35 , & V_57 ) ;
F_47 () ;
F_49 ( V_2 -> V_58 ) ;
}
void
F_50 (
struct V_1 * V_2 )
{
T_2 V_57 = F_12 ( V_2 ) ;
if ( V_57 )
F_45 ( V_2 , V_57 ) ;
}
void
F_51 (
struct V_1 * V_2 )
{
struct V_19 * V_3 ;
F_52 ( V_59 ) ;
F_9 ( & V_2 -> V_13 ) ;
while ( ( V_3 = F_5 ( V_2 ) ) != NULL ) {
F_53 ( & V_2 -> V_60 , & V_59 , V_61 ) ;
V_2 -> V_35 = V_3 -> V_10 ;
F_49 ( V_2 -> V_58 ) ;
F_11 ( & V_2 -> V_13 ) ;
F_41 () ;
F_9 ( & V_2 -> V_13 ) ;
}
F_11 ( & V_2 -> V_13 ) ;
F_54 ( & V_2 -> V_60 , & V_59 ) ;
}
void
F_55 (
struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_19 * * V_62 ,
int V_63 ,
T_2 V_12 ) __releases( V_2 -> V_13 )
{
T_1 * V_64 ;
int V_65 = 0 ;
int V_66 ;
F_56 ( V_67 ) ;
ASSERT ( V_63 > 0 ) ;
V_64 = F_10 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_63 ; V_66 ++ ) {
struct V_19 * V_3 = V_62 [ V_66 ] ;
if ( V_3 -> V_6 & V_7 ) {
if ( F_4 ( V_12 , V_3 -> V_10 ) <= 0 )
continue;
F_26 ( V_2 , V_3 ) ;
if ( V_64 == V_3 )
V_65 = 1 ;
} else {
V_3 -> V_6 |= V_7 ;
}
V_3 -> V_10 = V_12 ;
F_57 ( & V_3 -> V_8 , & V_67 ) ;
}
if ( ! F_2 ( & V_67 ) )
F_24 ( V_2 , V_15 , & V_67 , V_12 ) ;
if ( V_65 ) {
if ( ! F_46 ( V_2 -> V_24 ) )
F_58 ( V_2 -> V_24 ) ;
F_11 ( & V_2 -> V_13 ) ;
F_59 ( V_2 -> V_24 ) ;
} else {
F_11 ( & V_2 -> V_13 ) ;
}
}
void
F_60 (
struct V_1 * V_2 ,
struct V_19 * * V_62 ,
int V_63 ,
int V_68 ) __releases( V_2 -> V_13 )
{
T_1 * V_64 ;
int V_65 = 0 ;
int V_66 ;
V_64 = F_10 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_63 ; V_66 ++ ) {
struct V_19 * V_3 = V_62 [ V_66 ] ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
struct V_69 * V_23 = V_2 -> V_24 ;
F_11 ( & V_2 -> V_13 ) ;
if ( ! F_46 ( V_23 ) ) {
F_61 ( V_23 , V_70 ,
L_1 ,
V_71 ) ;
F_62 ( V_23 , V_68 ) ;
}
return;
}
F_26 ( V_2 , V_3 ) ;
V_3 -> V_6 &= ~ V_7 ;
V_3 -> V_10 = 0 ;
if ( V_64 == V_3 )
V_65 = 1 ;
}
if ( V_65 ) {
if ( ! F_46 ( V_2 -> V_24 ) )
F_58 ( V_2 -> V_24 ) ;
if ( F_2 ( & V_2 -> V_5 ) )
F_63 ( & V_2 -> V_60 ) ;
F_11 ( & V_2 -> V_13 ) ;
F_59 ( V_2 -> V_24 ) ;
} else {
F_11 ( & V_2 -> V_13 ) ;
}
}
int
F_64 (
T_3 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_65 ( sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_2 )
return V_73 ;
V_2 -> V_24 = V_23 ;
F_66 ( & V_2 -> V_5 ) ;
F_66 ( & V_2 -> V_18 ) ;
F_67 ( & V_2 -> V_13 ) ;
F_66 ( & V_2 -> V_32 ) ;
F_68 ( & V_2 -> V_60 ) ;
V_2 -> V_58 = F_69 ( F_38 , V_2 , L_2 ,
V_2 -> V_24 -> V_74 ) ;
if ( F_70 ( V_2 -> V_58 ) )
goto V_75;
V_23 -> V_76 = V_2 ;
return 0 ;
V_75:
F_71 ( V_2 ) ;
return V_73 ;
}
void
F_72 (
T_3 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_76 ;
F_73 ( V_2 -> V_58 ) ;
F_71 ( V_2 ) ;
}
