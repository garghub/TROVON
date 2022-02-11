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
F_14 ( V_28 , V_29 ) ;
F_15 () ;
F_16 ( & V_2 -> V_30 , & V_28 ) ;
F_17 ( & V_2 -> V_31 , V_27 ) ;
while ( 1 ) {
F_18 ( V_32 ) ;
if ( ! V_2 -> V_33 )
break;
F_19 ( & V_2 -> V_31 , V_27 ) ;
F_20 () ;
F_17 ( & V_2 -> V_31 , V_27 ) ;
}
F_18 ( V_34 ) ;
V_2 -> V_33 = 1 ;
F_19 ( & V_2 -> V_31 , V_27 ) ;
F_21 ( & V_2 -> V_30 , & V_28 ) ;
return;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
F_17 ( & V_2 -> V_31 , V_27 ) ;
V_2 -> V_33 = 0 ;
F_19 ( & V_2 -> V_31 , V_27 ) ;
F_23 ( & V_2 -> V_30 ) ;
return;
}
static T_3 F_24 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
if ( V_2 -> V_37 ) {
F_13 ( V_2 ) ;
F_25 ( V_2 -> V_37 ) ;
F_22 ( V_2 ) ;
return V_38 ;
} else {
return V_39 ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
int V_6 ;
F_27 ( L_9 ) ;
V_6 = F_28 ( V_2 -> V_19 -> V_35 , NULL ,
F_24 ,
V_40 | V_41 ,
L_10 , V_2 ) ;
if ( F_29 ( V_6 < 0 ) )
goto exit;
V_6 = F_30 ( V_2 -> V_19 -> V_35 ) ;
if ( F_29 ( V_6 ) )
goto V_42;
return 0 ;
V_42:
V_42 ( V_2 -> V_19 -> V_35 , V_2 ) ;
exit:
return V_6 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
F_27 ( L_11 ) ;
F_32 ( V_2 -> V_19 -> V_35 ) ;
V_42 ( V_2 -> V_19 -> V_35 , V_2 ) ;
return V_6 ;
}
static int F_33 ( const struct V_43 * V_44 )
{
if ( V_44 -> V_45 ) {
F_34 ( V_44 -> V_45 , 0 ) ;
F_35 ( 30 ) ;
F_36 ( V_44 -> V_45 ) ;
}
if ( V_44 -> V_46 )
V_44 -> V_46 ( V_44 , false ) ;
if ( V_44 -> V_47 )
V_44 -> V_47 ( V_44 , false ) ;
return 0 ;
}
static int F_37 ( const struct V_43 * V_44 )
{
if ( V_44 -> V_45 ) {
F_38 ( V_44 -> V_45 , L_12 ) ;
F_39 ( V_44 -> V_45 , 0 ) ;
}
if ( V_44 -> V_48 ) {
F_38 ( V_44 -> V_48 , L_13 ) ;
F_39 ( V_44 -> V_48 , 0 ) ;
}
if ( V_44 -> V_45 || V_44 -> V_48 )
F_35 ( 10 ) ;
if ( V_44 -> V_46 ) {
if ( V_44 -> V_46 ( V_44 , true ) ) {
F_40 ( L_14 ) ;
return - 1 ;
}
}
if ( V_44 -> V_47 ) {
if ( V_44 -> V_47 ( V_44 , true ) ) {
F_40 ( L_15 ) ;
return - 1 ;
}
F_35 ( 10 ) ;
}
if ( V_44 -> V_48 ) {
F_34 ( V_44 -> V_48 , 1 ) ;
F_35 ( 250 ) ;
}
if ( V_44 -> V_45 ) {
F_34 ( V_44 -> V_45 , 1 ) ;
F_35 ( 50 ) ;
}
return 0 ;
}
static T_4 F_41 ( struct V_1 * V_2 , T_4 V_49 )
{
return V_49 & 1 ? V_49 + 1 : V_49 ;
}
static int F_42 ( struct V_1 * V_2 , bool V_50 )
{
return F_43 ( V_2 -> V_19 -> V_35 , V_50 ) ;
}
static int F_44 ( struct V_51 * V_19 )
{
const struct V_43 * V_52 =
F_45 ( & V_19 -> V_53 ) ;
struct V_1 * V_2 ;
int V_54 ;
if ( V_19 -> V_55 > 52000000 )
V_19 -> V_55 = 52000000 ;
if ( V_19 -> V_55 < 1000000 )
V_19 -> V_55 = 1000000 ;
if ( V_52 -> V_56 )
V_19 -> V_20 = V_52 -> V_56 ;
if ( ! V_19 -> V_20 )
V_19 -> V_20 = 16 ;
V_19 -> V_57 = V_58 ;
F_4 ( L_16 ,
V_19 -> V_59 , V_19 -> V_57 , V_19 -> V_20 ,
V_19 -> V_55 ) ;
if ( F_37 ( V_52 ) ) {
F_40 ( L_17 ) ;
return - 1 ;
}
if ( F_46 ( V_19 ) ) {
F_40 ( L_18 ) ;
return - 1 ;
}
V_2 = F_47 ( & V_19 -> V_53 , sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 ) {
F_40 ( L_19 ) ;
return - V_61 ;
}
V_2 -> V_44 = V_52 ;
V_2 -> V_19 = V_19 ;
F_48 ( & V_2 -> V_31 ) ;
F_49 ( V_19 , V_2 ) ;
F_50 ( & V_2 -> V_30 ) ;
V_54 = F_26 ( V_2 ) ;
V_54 = F_51 ( & V_62 ,
V_2 , & V_19 -> V_53 , & V_2 -> V_37 ,
V_2 -> V_44 -> V_63 ,
V_2 -> V_44 -> V_64 ,
V_2 -> V_44 -> V_65 ,
V_2 -> V_44 -> V_66 ) ;
if ( V_54 ) {
F_31 ( V_2 ) ;
F_33 ( V_52 ) ;
}
return V_54 ;
}
static int F_52 ( struct V_51 * V_19 )
{
struct V_1 * V_2 = F_53 ( V_19 ) ;
if ( V_2 ) {
F_31 ( V_2 ) ;
if ( V_2 -> V_37 ) {
F_54 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
}
F_33 ( F_45 ( & V_19 -> V_53 ) ) ;
return 0 ;
}
static int F_55 ( struct V_67 * V_53 , T_5 V_68 )
{
struct V_1 * V_2 = F_53 ( F_56 ( V_53 ) ) ;
if ( ! F_57 ( V_2 -> V_37 ) )
return - V_69 ;
return 0 ;
}
static int F_58 ( struct V_67 * V_53 )
{
return 0 ;
}
