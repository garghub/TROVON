int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( V_3 , V_2 , V_1 ) ;
}
int F_3 ( T_1 V_2 )
{
return F_4 ( V_3 , V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 , unsigned V_6 )
{
switch ( F_6 ( V_6 ) ) {
case V_7 :
case V_8 :
case V_9 :
return 0 ;
default:
return - V_10 ;
}
}
static int F_7 ( struct V_4 * V_5 , unsigned V_6 )
{
int V_2 , V_11 ;
V_2 = F_6 ( V_6 ) ;
V_11 = F_3 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_2 == V_12 )
V_13 = V_11 ;
return ! ! ( V_11 & F_8 ( V_6 ) ) ;
}
static int F_9 ( struct V_4 * V_5 , unsigned V_6 , int V_1 )
{
int V_14 , V_15 ;
if ( F_6 ( V_6 ) != V_12 )
return - V_10 ;
V_14 = F_8 ( V_6 ) ;
V_15 = V_13 ;
V_15 &= ~ V_14 ;
if ( V_1 )
V_15 |= V_14 ;
V_13 = V_15 ;
return F_1 ( V_15 , V_12 ) ;
}
static void F_10 ( struct V_4 * V_5 , unsigned V_6 , int V_1 )
{
F_9 ( V_5 , V_6 , V_1 ) ;
}
static struct V_16 * F_11 ( struct V_17 * V_18 , const char * V_19 ,
void * V_20 , unsigned V_21 ,
bool V_22 , int V_23 )
{
struct V_24 * V_25 ;
int V_11 ;
V_25 = F_12 ( V_19 , - 1 ) ;
if ( ! V_25 )
return F_13 ( - V_26 ) ;
F_14 ( & V_25 -> V_27 , V_22 ) ;
V_25 -> V_27 . V_28 = & V_18 -> V_27 ;
if ( V_20 ) {
V_11 = F_15 ( V_25 , V_20 , V_21 ) ;
if ( V_11 < 0 ) {
F_16 ( & V_25 -> V_27 , L_1 ) ;
goto V_29;
}
}
if ( V_23 ) {
struct V_30 V_31 = {
. V_32 = V_23 ,
. V_33 = V_34 ,
} ;
V_11 = F_17 ( V_25 , & V_31 , 1 ) ;
if ( V_11 < 0 ) {
F_16 ( & V_25 -> V_27 , L_2 ) ;
goto V_29;
}
}
V_11 = F_18 ( V_25 ) ;
if ( V_11 )
goto V_29;
return & V_25 -> V_27 ;
V_29:
F_19 ( V_25 ) ;
F_20 ( & V_18 -> V_27 , L_3 , V_19 ) ;
return F_13 ( V_11 ) ;
}
static int F_21 ( struct V_17 * V_18 )
{
static const struct {
int V_6 ;
char * V_35 ;
} V_36 [] = {
{ 8 + 0 , L_4 , } ,
{ 8 + 1 , L_5 , } ,
{ 8 + 2 , L_6 , } ,
{ 8 + 3 , L_7 , } ,
{ 8 + 4 , L_8 , } ,
} ;
struct V_16 * V_37 ;
int V_11 ;
int V_38 ;
V_39 . V_28 = & V_18 -> V_27 ;
V_11 = F_22 ( & V_39 , NULL ) ;
if ( V_11 < 0 )
return V_11 ;
if ( F_23 () ) {
#define F_24 ( T_2 ) .name = l, .active_low = true
static struct V_40 V_41 [] = {
{ F_24 ( L_9 ) ,
. V_42 = L_10 , } ,
{ F_24 ( L_11 ) ,
. V_42 = L_12 , } ,
{ F_24 ( L_13 ) ,
. V_42 = L_14 , } ,
{ F_24 ( L_15 ) ,
. V_42 = L_16 , } ,
{ F_24 ( L_17 ) , } ,
{ F_24 ( L_18 ) , } ,
{ F_24 ( L_19 ) , } ,
{ F_24 ( L_20 ) , } ,
} ;
#undef F_24
struct V_43 V_44 = {
. V_45 = F_25 ( V_41 ) ,
. V_46 = V_41 ,
} ;
for ( V_38 = 0 ; V_38 < F_25 ( V_41 ) ; V_38 ++ )
V_41 [ V_38 ] . V_47 = V_38 + V_39 . V_48 ;
V_37 = F_11 ( V_18 , L_21 ,
& V_44 , sizeof( V_44 ) ,
false , 0 ) ;
if ( F_26 ( V_37 ) )
return F_27 ( V_37 ) ;
}
for ( V_38 = 0 ; V_38 < F_25 ( V_36 ) ; V_38 ++ ) {
int V_47 = V_39 . V_48 + V_36 [ V_38 ] . V_6 ;
F_28 ( V_47 , V_49 , V_36 [ V_38 ] . V_35 ) ;
F_29 ( V_47 , false ) ;
}
if ( F_30 ( & V_18 -> V_27 ) ) {
void (* F_31)( unsigned ) = F_30 ( & V_18 -> V_27 ) ;
F_31 ( V_39 . V_48 + 8 + 5 ) ;
}
if ( F_32 () ) {
V_37 = F_11 ( V_18 , L_22 ,
NULL , 0 , false , 0 ) ;
if ( F_26 ( V_37 ) )
return F_27 ( V_37 ) ;
}
if ( F_33 () ) {
V_37 = F_11 ( V_18 , L_23 ,
NULL , 0 , true , V_18 -> V_23 ) ;
if ( F_26 ( V_37 ) )
return F_27 ( V_37 ) ;
}
return 0 ;
}
static void F_34 ( unsigned V_50 )
{
int V_11 ;
V_11 = F_1 ( V_50 , V_51 ) ;
if ( V_11 < 0 )
F_20 ( & V_3 -> V_27 , L_24 ,
V_50 , V_11 ) ;
}
static void F_35 ( void )
{
F_34 ( V_52 ) ;
}
static int F_36 ( struct V_17 * V_18 )
{
V_53 = NULL ;
V_3 = NULL ;
return 0 ;
}
static int
F_37 ( struct V_17 * V_18 , const struct V_54 * V_55 )
{
int V_11 ;
const char * V_56 = F_38 () ? L_25 : L_26 ;
if ( V_3 )
return - V_57 ;
V_3 = V_18 ;
V_11 = F_3 ( V_58 ) ;
if ( V_11 < 0 )
goto V_59;
F_39 ( & V_18 -> V_27 , L_27 ,
V_11 , V_56 ) ;
V_11 = F_1 ( F_38 () ? 0 : V_60 ,
V_61 ) ;
if ( V_11 < 0 )
F_40 ( & V_18 -> V_27 , L_28 ,
V_11 , V_56 ) ;
V_13 = 0xff ;
F_1 ( V_13 , V_12 ) ;
V_11 = F_21 ( V_18 ) ;
if ( V_11 < 0 )
goto V_59;
V_53 = F_35 ;
return 0 ;
V_59:
F_36 ( V_18 ) ;
return V_11 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_62 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_62 ) ;
}
