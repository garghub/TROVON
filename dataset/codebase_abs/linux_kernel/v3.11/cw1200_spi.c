static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
void * V_4 , int V_5 )
{
int V_6 , V_7 ;
T_1 V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 = {
. V_13 = & V_8 ,
. V_14 = sizeof( V_8 ) ,
} ;
struct V_11 V_15 = {
. V_16 = V_4 ,
. V_14 = V_5 ,
} ;
V_8 = ( F_2 ( V_3 ) ) << 12 ;
V_8 |= V_17 ;
V_8 |= ( V_5 >> 1 ) ;
#ifdef F_3
F_4 ( L_1 , V_5 , V_3 , V_8 ) ;
#endif
V_8 = F_5 ( V_8 ) ;
#if F_6 ( V_18 )
if ( V_2 -> V_19 -> V_20 == 8 )
#endif
V_8 = F_7 ( V_8 ) ;
F_8 ( & V_10 ) ;
F_9 ( & V_12 , & V_10 ) ;
F_9 ( & V_15 , & V_10 ) ;
V_6 = F_10 ( V_2 -> V_19 , & V_10 ) ;
#ifdef F_3
F_4 ( L_2 ) ;
for ( V_7 = 0 ; V_7 < V_12 . V_14 ; V_7 ++ )
F_11 ( L_3 , ( ( V_21 * ) V_12 . V_13 ) [ V_7 ] ) ;
F_11 ( L_4 ) ;
for ( V_7 = 0 ; V_7 < V_15 . V_14 ; V_7 ++ )
F_11 ( L_3 , ( ( V_21 * ) V_15 . V_16 ) [ V_7 ] ) ;
F_11 ( L_5 ) ;
#endif
#if F_6 ( V_18 )
if ( V_2 -> V_19 -> V_20 == 8 )
#endif
{
T_2 * V_22 = ( T_2 * ) V_4 ;
for ( V_7 = 0 ; V_7 < ( ( V_5 + 1 ) >> 1 ) ; V_7 ++ )
V_22 [ V_7 ] = F_7 ( V_22 [ V_7 ] ) ;
}
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_3 ,
const void * V_23 , int V_5 )
{
int V_24 , V_7 ;
T_1 V_8 ;
struct V_11 V_12 = {
. V_13 = & V_8 ,
. V_14 = sizeof( V_8 ) ,
} ;
struct V_11 V_15 = {
. V_13 = V_23 ,
. V_14 = V_5 ,
} ;
struct V_9 V_10 ;
V_8 = ( F_2 ( V_3 ) ) << 12 ;
V_8 &= V_25 ;
V_8 |= ( V_5 >> 1 ) ;
#ifdef F_3
F_4 ( L_6 , V_5 , V_3 , V_8 ) ;
#endif
V_8 = F_5 ( V_8 ) ;
#if F_6 ( V_18 )
if ( V_2 -> V_19 -> V_20 == 8 )
#endif
{
T_2 * V_22 = ( T_2 * ) V_23 ;
V_8 = F_7 ( V_8 ) ;
for ( V_7 = 0 ; V_7 < ( ( V_5 + 1 ) >> 1 ) ; V_7 ++ )
V_22 [ V_7 ] = F_7 ( V_22 [ V_7 ] ) ;
}
#ifdef F_3
F_4 ( L_7 ) ;
for ( V_7 = 0 ; V_7 < V_12 . V_14 ; V_7 ++ )
F_11 ( L_3 , ( ( V_21 * ) V_12 . V_13 ) [ V_7 ] ) ;
F_11 ( L_4 ) ;
for ( V_7 = 0 ; V_7 < V_15 . V_14 ; V_7 ++ )
F_11 ( L_3 , ( ( V_21 * ) V_15 . V_13 ) [ V_7 ] ) ;
F_11 ( L_5 ) ;
#endif
F_8 ( & V_10 ) ;
F_9 ( & V_12 , & V_10 ) ;
F_9 ( & V_15 , & V_10 ) ;
V_24 = F_10 ( V_2 -> V_19 , & V_10 ) ;
#ifdef F_3
F_4 ( L_8 , V_10 . V_26 ) ;
#endif
#if F_6 ( V_18 )
if ( V_2 -> V_19 -> V_20 == 8 )
#endif
{
T_2 * V_22 = ( T_2 * ) V_23 ;
for ( V_7 = 0 ; V_7 < ( ( V_5 + 1 ) >> 1 ) ; V_7 ++ )
V_22 [ V_7 ] = F_7 ( V_22 [ V_7 ] ) ;
}
return V_24 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
F_14 () ;
F_15 ( & V_2 -> V_28 , V_27 ) ;
while ( 1 ) {
F_16 ( V_29 ) ;
if ( ! V_2 -> V_30 )
break;
F_17 ( & V_2 -> V_28 , V_27 ) ;
F_18 () ;
F_15 ( & V_2 -> V_28 , V_27 ) ;
}
F_16 ( V_31 ) ;
V_2 -> V_30 = 1 ;
F_17 ( & V_2 -> V_28 , V_27 ) ;
return;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
F_15 ( & V_2 -> V_28 , V_27 ) ;
V_2 -> V_30 = 0 ;
F_17 ( & V_2 -> V_28 , V_27 ) ;
return;
}
static T_3 F_20 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
if ( V_2 -> V_34 ) {
F_21 ( V_2 -> V_34 ) ;
return V_35 ;
} else {
return V_36 ;
}
}
static int F_22 ( struct V_1 * V_2 )
{
int V_6 ;
F_23 ( L_9 ) ;
V_6 = F_24 ( V_2 -> V_19 -> V_32 , F_20 ,
V_37 ,
L_10 , V_2 ) ;
if ( F_25 ( V_6 < 0 ) )
goto exit;
V_6 = F_26 ( V_2 -> V_19 -> V_32 ) ;
if ( F_25 ( V_6 ) )
goto V_38;
return 0 ;
V_38:
V_38 ( V_2 -> V_19 -> V_32 , V_2 ) ;
exit:
return V_6 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
F_23 ( L_11 ) ;
F_28 ( V_2 -> V_19 -> V_32 ) ;
V_38 ( V_2 -> V_19 -> V_32 , V_2 ) ;
return V_6 ;
}
static int F_29 ( const struct V_39 * V_40 )
{
if ( V_40 -> V_41 ) {
F_30 ( V_40 -> V_41 , 0 ) ;
F_31 ( 30 ) ;
F_32 ( V_40 -> V_41 ) ;
}
if ( V_40 -> V_42 )
V_40 -> V_42 ( V_40 , false ) ;
if ( V_40 -> V_43 )
V_40 -> V_43 ( V_40 , false ) ;
return 0 ;
}
static int F_33 ( const struct V_39 * V_40 )
{
if ( V_40 -> V_41 ) {
F_34 ( V_40 -> V_41 , L_12 ) ;
F_35 ( V_40 -> V_41 , 0 ) ;
}
if ( V_40 -> V_44 ) {
F_34 ( V_40 -> V_44 , L_13 ) ;
F_35 ( V_40 -> V_44 , 0 ) ;
}
if ( V_40 -> V_41 || V_40 -> V_44 )
F_31 ( 10 ) ;
if ( V_40 -> V_42 ) {
if ( V_40 -> V_42 ( V_40 , true ) ) {
F_36 ( L_14 ) ;
return - 1 ;
}
}
if ( V_40 -> V_43 ) {
if ( V_40 -> V_43 ( V_40 , true ) ) {
F_36 ( L_15 ) ;
return - 1 ;
}
F_31 ( 10 ) ;
}
if ( V_40 -> V_44 ) {
F_30 ( V_40 -> V_44 , 1 ) ;
F_31 ( 250 ) ;
}
if ( V_40 -> V_41 ) {
F_30 ( V_40 -> V_41 , 1 ) ;
F_31 ( 50 ) ;
}
return 0 ;
}
static T_4 F_37 ( struct V_1 * V_2 , T_4 V_45 )
{
return V_45 & 1 ? V_45 + 1 : V_45 ;
}
static int F_38 ( struct V_1 * V_2 , bool V_46 )
{
return F_39 ( V_2 -> V_19 -> V_32 , V_46 ) ;
}
static int F_40 ( struct V_47 * V_19 )
{
const struct V_39 * V_48 =
V_19 -> V_49 . V_50 ;
struct V_1 * V_2 ;
int V_51 ;
if ( V_19 -> V_52 > 52000000 )
V_19 -> V_52 = 52000000 ;
if ( V_19 -> V_52 < 1000000 )
V_19 -> V_52 = 1000000 ;
if ( V_48 -> V_53 )
V_19 -> V_20 = V_48 -> V_53 ;
if ( ! V_19 -> V_20 )
V_19 -> V_20 = 16 ;
V_19 -> V_54 = V_55 ;
F_4 ( L_16 ,
V_19 -> V_56 , V_19 -> V_54 , V_19 -> V_20 ,
V_19 -> V_52 ) ;
if ( F_33 ( V_48 ) ) {
F_36 ( L_17 ) ;
return - 1 ;
}
if ( F_41 ( V_19 ) ) {
F_36 ( L_18 ) ;
return - 1 ;
}
V_2 = F_42 ( sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 ) {
F_36 ( L_19 ) ;
return - V_58 ;
}
V_2 -> V_40 = V_48 ;
V_2 -> V_19 = V_19 ;
F_43 ( & V_2 -> V_28 ) ;
F_44 ( V_19 , V_2 ) ;
V_51 = F_22 ( V_2 ) ;
V_51 = F_45 ( & V_59 ,
V_2 , & V_19 -> V_49 , & V_2 -> V_34 ,
V_2 -> V_40 -> V_60 ,
V_2 -> V_40 -> V_61 ,
V_2 -> V_40 -> V_62 ,
V_2 -> V_40 -> V_63 ) ;
if ( V_51 ) {
F_27 ( V_2 ) ;
F_29 ( V_48 ) ;
F_46 ( V_2 ) ;
}
return V_51 ;
}
static int F_47 ( struct V_47 * V_19 )
{
struct V_1 * V_2 = F_48 ( V_19 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
if ( V_2 -> V_34 ) {
F_49 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
F_46 ( V_2 ) ;
}
F_29 ( V_19 -> V_49 . V_50 ) ;
return 0 ;
}
static int F_50 ( struct V_64 * V_49 , T_5 V_65 )
{
struct V_1 * V_2 = F_48 ( F_51 ( V_49 ) ) ;
if ( ! F_52 ( V_2 -> V_34 ) )
return - V_66 ;
return 0 ;
}
static int F_53 ( struct V_64 * V_49 )
{
return 0 ;
}
