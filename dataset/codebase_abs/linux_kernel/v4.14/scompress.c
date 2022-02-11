static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
strncpy ( V_6 . type , L_1 , sizeof( V_6 . type ) ) ;
if ( F_2 ( V_2 , V_7 ,
sizeof( struct V_5 ) , & V_6 ) )
goto V_8;
return 0 ;
V_8:
return - V_9 ;
}
static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return - V_10 ;
}
static void F_3 ( struct V_11 * V_12 , struct V_3 * V_4 )
{
F_4 ( V_12 , L_2 ) ;
}
static void F_5 ( void * T_1 * V_13 )
{
int V_14 ;
if ( ! V_13 )
return;
F_6 (i)
F_7 ( * F_8 ( V_13 , V_14 ) ) ;
F_9 ( V_13 ) ;
}
static void * T_1 * F_10 ( void )
{
void * T_1 * V_13 ;
int V_14 ;
V_13 = F_11 ( void * ) ;
if ( ! V_13 )
return NULL ;
F_6 (i) {
void * V_15 ;
V_15 = F_12 ( V_16 , F_13 ( V_14 ) ) ;
if ( ! V_15 )
goto error;
* F_8 ( V_13 , V_14 ) = V_15 ;
}
return V_13 ;
error:
F_5 ( V_13 ) ;
return NULL ;
}
static void F_14 ( void )
{
if ( ! -- V_17 ) {
F_5 ( V_18 ) ;
F_5 ( V_19 ) ;
V_18 = NULL ;
V_19 = NULL ;
}
}
static int F_15 ( void )
{
if ( ! V_17 ++ ) {
V_18 = F_10 () ;
if ( ! V_18 )
return - V_20 ;
V_19 = F_10 () ;
if ( ! V_19 ) {
F_5 ( V_18 ) ;
V_18 = NULL ;
return - V_20 ;
}
}
return 0 ;
}
static int F_16 ( struct V_21 * V_22 )
{
int V_23 ;
F_17 ( & V_24 ) ;
V_23 = F_15 () ;
F_18 ( & V_24 ) ;
return V_23 ;
}
static void F_19 ( struct V_25 * V_26 )
{
int V_14 , V_27 ;
struct V_28 * V_28 ;
if ( ! V_26 )
return;
V_27 = F_20 ( V_26 ) ;
F_21 (sgl, sgl, n, i) {
V_28 = F_22 ( V_26 ) ;
if ( V_28 )
F_23 ( V_28 ) ;
}
F_24 ( V_26 ) ;
}
static struct V_25 * F_25 ( T_2 V_29 , T_3 V_30 )
{
struct V_25 * V_26 ;
struct V_28 * V_28 ;
int V_14 , V_27 ;
V_27 = ( ( V_29 - 1 ) >> V_31 ) + 1 ;
V_26 = F_26 ( V_27 , sizeof( struct V_25 ) , V_30 ) ;
if ( ! V_26 )
return NULL ;
F_27 ( V_26 , V_27 ) ;
for ( V_14 = 0 ; V_14 < V_27 ; V_14 ++ ) {
V_28 = F_28 ( V_30 ) ;
if ( ! V_28 )
goto V_32;
F_29 ( V_26 + V_14 , V_28 , V_33 , 0 ) ;
}
return V_26 ;
V_32:
F_30 ( V_26 + V_14 ) ;
F_19 ( V_26 ) ;
return NULL ;
}
static int F_31 ( struct V_34 * V_35 , int V_36 )
{
struct V_37 * V_22 = F_32 ( V_35 ) ;
void * * V_38 = F_33 ( V_22 ) ;
struct V_39 * V_40 = * V_38 ;
void * * V_41 = F_34 ( V_35 ) ;
const int V_42 = F_35 () ;
T_4 * V_43 = * F_8 ( V_18 , V_42 ) ;
T_4 * V_44 = * F_8 ( V_19 , V_42 ) ;
int V_23 ;
if ( ! V_35 -> V_45 || ! V_35 -> V_46 || V_35 -> V_46 > V_16 ) {
V_23 = - V_47 ;
goto V_48;
}
if ( V_35 -> V_49 && ! V_35 -> V_50 ) {
V_23 = - V_47 ;
goto V_48;
}
if ( ! V_35 -> V_50 || V_35 -> V_50 > V_16 )
V_35 -> V_50 = V_16 ;
F_36 ( V_43 , V_35 -> V_45 , 0 , V_35 -> V_46 , 0 ) ;
if ( V_36 )
V_23 = F_37 ( V_40 , V_43 , V_35 -> V_46 ,
V_44 , & V_35 -> V_50 , * V_41 ) ;
else
V_23 = F_38 ( V_40 , V_43 , V_35 -> V_46 ,
V_44 , & V_35 -> V_50 , * V_41 ) ;
if ( ! V_23 ) {
if ( ! V_35 -> V_49 ) {
V_35 -> V_49 = F_25 ( V_35 -> V_50 , V_51 ) ;
if ( ! V_35 -> V_49 )
goto V_48;
}
F_36 ( V_44 , V_35 -> V_49 , 0 , V_35 -> V_50 ,
1 ) ;
}
V_48:
F_39 () ;
return V_23 ;
}
static int F_40 ( struct V_34 * V_35 )
{
return F_31 ( V_35 , 1 ) ;
}
static int F_41 ( struct V_34 * V_35 )
{
return F_31 ( V_35 , 0 ) ;
}
static void F_42 ( struct V_21 * V_22 )
{
struct V_39 * * V_41 = F_43 ( V_22 ) ;
F_44 ( * V_41 ) ;
F_17 ( & V_24 ) ;
F_14 () ;
F_18 ( & V_24 ) ;
}
int F_45 ( struct V_21 * V_22 )
{
struct V_3 * V_52 = V_22 -> V_53 ;
struct V_37 * V_54 = F_46 ( V_22 ) ;
struct V_39 * * V_41 = F_43 ( V_22 ) ;
struct V_39 * V_40 ;
if ( ! F_47 ( V_52 ) )
return - V_55 ;
V_40 = F_48 ( V_52 , & V_56 ) ;
if ( F_49 ( V_40 ) ) {
F_50 ( V_52 ) ;
return F_51 ( V_40 ) ;
}
* V_41 = V_40 ;
V_22 -> exit = F_42 ;
V_54 -> V_57 = F_40 ;
V_54 -> V_58 = F_41 ;
V_54 -> V_59 = F_19 ;
V_54 -> V_60 = sizeof( void * ) ;
return 0 ;
}
struct V_34 * F_52 ( struct V_34 * V_35 )
{
struct V_37 * V_61 = F_32 ( V_35 ) ;
struct V_21 * V_22 = F_53 ( V_61 ) ;
struct V_39 * * V_38 = F_43 ( V_22 ) ;
struct V_39 * V_40 = * V_38 ;
void * V_41 ;
V_41 = F_54 ( V_40 ) ;
if ( F_49 ( V_41 ) ) {
F_24 ( V_35 ) ;
return NULL ;
}
* V_35 -> V_62 = V_41 ;
return V_35 ;
}
void F_55 ( struct V_34 * V_35 )
{
struct V_37 * V_61 = F_32 ( V_35 ) ;
struct V_21 * V_22 = F_53 ( V_61 ) ;
struct V_39 * * V_38 = F_43 ( V_22 ) ;
struct V_39 * V_40 = * V_38 ;
void * V_41 = * V_35 -> V_62 ;
if ( V_41 )
F_56 ( V_40 , V_41 ) ;
}
int F_57 ( struct V_63 * V_4 )
{
struct V_3 * V_64 = & V_4 -> V_64 ;
V_64 -> V_65 = & V_56 ;
V_64 -> V_66 &= ~ V_67 ;
V_64 -> V_66 |= V_68 ;
return F_58 ( V_64 ) ;
}
int F_59 ( struct V_63 * V_4 )
{
return F_60 ( & V_4 -> V_64 ) ;
}
int F_61 ( struct V_63 * V_69 , int V_70 )
{
int V_14 , V_23 ;
for ( V_14 = 0 ; V_14 < V_70 ; V_14 ++ ) {
V_23 = F_57 ( & V_69 [ V_14 ] ) ;
if ( V_23 )
goto V_32;
}
return 0 ;
V_32:
for ( -- V_14 ; V_14 >= 0 ; -- V_14 )
F_59 ( & V_69 [ V_14 ] ) ;
return V_23 ;
}
void F_62 ( struct V_63 * V_69 , int V_70 )
{
int V_14 ;
for ( V_14 = V_70 - 1 ; V_14 >= 0 ; -- V_14 )
F_59 ( & V_69 [ V_14 ] ) ;
}
