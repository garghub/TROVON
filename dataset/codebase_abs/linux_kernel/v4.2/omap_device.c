static void F_1 ( struct V_1 * V_2 , const char * V_3 ,
const char * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
if ( ! V_3 || ! V_4 )
return;
F_2 ( & V_2 -> V_8 -> V_9 , L_1 , V_3 , V_4 ) ;
V_6 = F_3 ( F_4 ( & V_2 -> V_8 -> V_9 ) , V_3 ) ;
if ( ! F_5 ( V_6 ) ) {
F_2 ( & V_2 -> V_8 -> V_9 ,
L_2 , V_3 ) ;
F_6 ( V_6 ) ;
return;
}
V_7 = F_7 ( V_3 , F_4 ( & V_2 -> V_8 -> V_9 ) , V_4 , NULL ) ;
if ( V_7 ) {
if ( V_7 == - V_10 || V_7 == - V_11 )
F_8 ( & V_2 -> V_8 -> V_9 ,
L_3 , V_3 ) ;
else
F_8 ( & V_2 -> V_8 -> V_9 ,
L_4 , V_4 ) ;
}
}
static void F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_14 ;
F_1 ( V_2 , L_5 , V_13 -> V_15 ) ;
for ( V_14 = 0 ; V_14 < V_13 -> V_16 ; V_14 ++ )
F_1 ( V_2 , V_13 -> V_17 [ V_14 ] . V_18 , V_13 -> V_17 [ V_14 ] . V_5 ) ;
}
static int F_10 ( struct V_19 * V_8 )
{
struct V_12 * * V_20 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_21 * V_22 = V_8 -> V_9 . V_23 ;
const char * V_24 ;
int V_25 , V_14 , V_26 = 0 ;
bool V_27 = false ;
V_25 = F_11 ( V_22 , L_6 ) ;
if ( V_25 <= 0 ) {
F_2 ( & V_8 -> V_9 , L_7 ) ;
return - V_10 ;
}
V_20 = F_12 ( sizeof( struct V_12 * ) * V_25 , V_28 ) ;
if ( ! V_20 ) {
V_26 = - V_11 ;
goto V_29;
}
for ( V_14 = 0 ; V_14 < V_25 ; V_14 ++ ) {
F_13 ( V_22 , L_6 , V_14 , & V_24 ) ;
V_13 = F_14 ( V_24 ) ;
if ( ! V_13 ) {
F_8 ( & V_8 -> V_9 , L_8 ,
V_24 ) ;
V_26 = - V_30 ;
goto V_31;
}
V_20 [ V_14 ] = V_13 ;
if ( V_13 -> V_32 & V_33 )
V_27 = true ;
}
V_2 = F_15 ( V_8 , V_20 , V_25 ) ;
if ( F_5 ( V_2 ) ) {
F_8 ( & V_8 -> V_9 , L_9 ,
V_24 ) ;
V_26 = F_16 ( V_2 ) ;
goto V_31;
}
for ( V_14 = 0 ; V_14 < V_8 -> V_34 ; V_14 ++ ) {
struct V_35 * V_6 = & V_8 -> V_35 [ V_14 ] ;
if ( V_6 -> V_36 == NULL )
V_6 -> V_36 = F_4 ( & V_8 -> V_9 ) ;
}
V_8 -> V_9 . V_37 = & V_38 ;
if ( V_27 ) {
F_17 ( V_8 ) ;
F_18 ( & V_8 -> V_9 ) ;
}
V_31:
F_19 ( V_20 ) ;
V_29:
if ( V_26 )
V_8 -> V_9 . V_37 = & V_39 ;
return V_26 ;
}
static int F_20 ( struct V_40 * V_41 ,
unsigned long V_42 , void * V_9 )
{
struct V_19 * V_8 = F_21 ( V_9 ) ;
struct V_1 * V_2 ;
switch ( V_42 ) {
case V_43 :
if ( V_8 -> V_44 . V_2 )
F_22 ( V_8 -> V_44 . V_2 ) ;
break;
case V_45 :
if ( V_8 -> V_9 . V_23 )
F_10 ( V_8 ) ;
F_23 ( V_9 ) ;
default:
V_2 = F_24 ( V_8 ) ;
if ( V_2 )
V_2 -> V_46 = V_42 ;
}
return V_47 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_48 ; V_14 ++ )
V_26 |= F_26 ( V_2 -> V_20 [ V_14 ] ) ;
return V_26 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_48 ; V_14 ++ )
V_26 |= F_28 ( V_2 -> V_20 [ V_14 ] ) ;
return V_26 ;
}
int F_29 ( struct V_19 * V_8 )
{
struct V_1 * V_2 ;
T_1 V_26 = 0 ;
V_2 = F_24 ( V_8 ) ;
if ( V_2 -> V_48 )
V_26 = F_30 ( V_2 -> V_20 [ 0 ] ) ;
return V_26 ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
int V_49 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_48 ; V_14 ++ )
V_49 += F_32 ( V_2 -> V_20 [ V_14 ] , V_32 ) ;
F_33 ( L_10 ,
V_2 -> V_8 -> V_36 , V_49 , V_2 -> V_48 ) ;
return V_49 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_35 * V_50 )
{
int V_14 , V_6 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_48 ; V_14 ++ ) {
V_6 = F_35 ( V_2 -> V_20 [ V_14 ] , V_50 ) ;
V_50 += V_6 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_35 * V_50 )
{
int V_14 , V_6 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_48 ; V_14 ++ ) {
V_6 = F_37 ( V_2 -> V_20 [ V_14 ] , V_50 ) ;
V_50 += V_6 ;
}
return 0 ;
}
struct V_1 * F_15 ( struct V_19 * V_8 ,
struct V_12 * * V_51 , int V_25 )
{
int V_26 = - V_11 ;
struct V_1 * V_2 ;
struct V_35 * V_50 = NULL ;
int V_14 , V_52 ;
struct V_12 * * V_20 ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
V_26 = - V_11 ;
goto V_53;
}
V_2 -> V_48 = V_25 ;
V_20 = F_38 ( V_51 , sizeof( struct V_12 * ) * V_25 , V_28 ) ;
if ( ! V_20 )
goto V_54;
V_2 -> V_20 = V_20 ;
V_2 -> V_8 = V_8 ;
if ( ! V_8 -> V_34 ) {
V_52 = F_31 ( V_2 , V_55 |
V_56 |
V_57 ) ;
} else {
for ( V_14 = 0 ; V_14 < V_8 -> V_34 ; V_14 ++ ) {
struct V_35 * V_6 = & V_8 -> V_35 [ V_14 ] ;
if ( V_6 -> V_32 == V_56 )
goto V_58;
}
V_52 = F_31 ( V_2 , V_56 ) ;
if ( ! V_52 )
goto V_58;
V_52 += V_8 -> V_34 ;
}
V_50 = F_12 ( sizeof( struct V_35 ) * V_52 , V_28 ) ;
if ( ! V_50 )
goto V_59;
if ( ! V_8 -> V_34 ) {
F_2 ( & V_8 -> V_9 , L_11 ,
V_60 , V_52 ) ;
F_34 ( V_2 , V_50 ) ;
} else {
F_2 ( & V_8 -> V_9 ,
L_12 ,
V_60 , V_52 - V_8 -> V_34 ) ;
memcpy ( V_50 , V_8 -> V_35 ,
sizeof( struct V_35 ) * V_8 -> V_34 ) ;
F_36 ( V_2 , & V_50 [ V_8 -> V_34 ] ) ;
}
V_26 = F_39 ( V_8 , V_50 , V_52 ) ;
F_19 ( V_50 ) ;
if ( V_26 )
goto V_59;
V_58:
V_8 -> V_44 . V_2 = V_2 ;
for ( V_14 = 0 ; V_14 < V_25 ; V_14 ++ ) {
V_20 [ V_14 ] -> V_2 = V_2 ;
F_9 ( V_2 , V_20 [ V_14 ] ) ;
}
return V_2 ;
V_59:
F_19 ( V_20 ) ;
V_54:
F_19 ( V_2 ) ;
V_53:
F_8 ( & V_8 -> V_9 , L_13 , V_26 ) ;
return F_40 ( V_26 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_8 -> V_44 . V_2 = NULL ;
F_19 ( V_2 -> V_20 ) ;
F_19 ( V_2 ) ;
}
struct V_19 T_2 * F_41 ( const char * V_61 ,
int V_62 ,
struct V_12 * V_13 ,
void * V_63 , int V_64 )
{
struct V_12 * V_51 [] = { V_13 } ;
if ( ! V_13 )
return F_40 ( - V_30 ) ;
return F_42 ( V_61 , V_62 , V_51 , 1 , V_63 ,
V_64 ) ;
}
struct V_19 T_2 * F_42 ( const char * V_61 ,
int V_62 ,
struct V_12 * * V_51 ,
int V_25 , void * V_63 ,
int V_64 )
{
int V_26 = - V_11 ;
struct V_19 * V_8 ;
struct V_1 * V_2 ;
if ( ! V_51 || V_25 == 0 || ! V_61 )
return F_40 ( - V_30 ) ;
if ( ! V_63 && V_64 > 0 )
return F_40 ( - V_30 ) ;
V_8 = F_43 ( V_61 , V_62 ) ;
if ( ! V_8 ) {
V_26 = - V_11 ;
goto V_65;
}
if ( V_8 -> V_66 != - 1 )
F_44 ( & V_8 -> V_9 , L_14 , V_8 -> V_36 , V_8 -> V_66 ) ;
else
F_44 ( & V_8 -> V_9 , L_15 , V_8 -> V_36 ) ;
V_2 = F_15 ( V_8 , V_51 , V_25 ) ;
if ( F_5 ( V_2 ) )
goto V_67;
V_26 = F_45 ( V_8 , V_63 , V_64 ) ;
if ( V_26 )
goto V_68;
V_26 = F_46 ( V_8 ) ;
if ( V_26 )
goto V_68;
return V_8 ;
V_68:
F_22 ( V_2 ) ;
V_67:
F_47 ( V_8 ) ;
V_65:
F_48 ( L_16 , V_61 , V_26 ) ;
return F_40 ( V_26 ) ;
}
static int F_49 ( struct V_69 * V_9 )
{
struct V_19 * V_8 = F_21 ( V_9 ) ;
int V_26 ;
V_26 = F_50 ( V_9 ) ;
if ( V_26 )
return V_26 ;
return F_51 ( V_8 ) ;
}
static int F_52 ( struct V_69 * V_9 )
{
struct V_19 * V_8 = F_21 ( V_9 ) ;
int V_26 ;
V_26 = F_17 ( V_8 ) ;
if ( V_26 )
return V_26 ;
return F_53 ( V_9 ) ;
}
static int F_54 ( struct V_69 * V_9 )
{
F_55 ( V_9 , L_17 , V_60 ) ;
return - V_10 ;
}
static int F_56 ( struct V_69 * V_9 )
{
F_55 ( V_9 , L_17 , V_60 ) ;
return - V_10 ;
}
static int F_57 ( struct V_69 * V_9 )
{
struct V_19 * V_8 = F_21 ( V_9 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_26 ;
if ( V_2 -> V_46 != V_70 )
return 0 ;
V_26 = F_58 ( V_9 ) ;
if ( ! V_26 && ! F_59 ( V_9 ) ) {
if ( F_50 ( V_9 ) == 0 ) {
F_60 ( V_9 ) ;
F_51 ( V_8 ) ;
V_2 -> V_32 |= V_71 ;
}
}
return V_26 ;
}
static int F_61 ( struct V_69 * V_9 )
{
struct V_19 * V_8 = F_21 ( V_9 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
if ( V_2 -> V_32 & V_71 ) {
V_2 -> V_32 &= ~ V_71 ;
F_17 ( V_8 ) ;
F_62 ( F_18 ( V_9 ) ,
L_18 , F_4 ( V_9 ) ) ;
F_53 ( V_9 ) ;
}
return F_63 ( V_9 ) ;
}
int F_46 ( struct V_19 * V_8 )
{
F_33 ( L_19 , V_8 -> V_36 ) ;
V_8 -> V_9 . V_37 = & V_38 ;
return F_64 ( V_8 ) ;
}
int F_17 ( struct V_19 * V_8 )
{
int V_26 ;
struct V_1 * V_2 ;
V_2 = F_24 ( V_8 ) ;
if ( V_2 -> V_72 == V_73 ) {
F_55 ( & V_8 -> V_9 ,
L_20 ,
V_60 , V_2 -> V_72 ) ;
return - V_30 ;
}
V_26 = F_25 ( V_2 ) ;
if ( V_26 == 0 )
V_2 -> V_72 = V_73 ;
return V_26 ;
}
int F_51 ( struct V_19 * V_8 )
{
int V_26 ;
struct V_1 * V_2 ;
V_2 = F_24 ( V_8 ) ;
if ( V_2 -> V_72 != V_73 ) {
F_55 ( & V_8 -> V_9 ,
L_20 ,
V_60 , V_2 -> V_72 ) ;
return - V_30 ;
}
V_26 = F_27 ( V_2 ) ;
if ( V_26 == 0 )
V_2 -> V_72 = V_74 ;
return V_26 ;
}
int F_65 ( struct V_19 * V_8 , const char * V_36 )
{
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_26 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_48 ; V_14 ++ ) {
V_26 = F_66 ( V_2 -> V_20 [ V_14 ] , V_36 ) ;
if ( V_26 )
break;
}
return V_26 ;
}
int F_67 ( struct V_19 * V_8 ,
const char * V_36 )
{
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_26 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_48 ; V_14 ++ ) {
V_26 = F_68 ( V_2 -> V_20 [ V_14 ] , V_36 ) ;
if ( V_26 )
break;
}
return V_26 ;
}
struct V_69 * F_69 ( const char * V_24 )
{
struct V_12 * V_13 ;
if ( ! V_24 ) {
F_62 ( 1 , L_21 , V_60 ) ;
return F_40 ( - V_30 ) ;
}
V_13 = F_14 ( V_24 ) ;
if ( ! V_13 ) {
F_62 ( 1 , L_22 , V_60 ,
V_24 ) ;
return F_40 ( - V_10 ) ;
}
if ( ! V_13 -> V_2 ) {
F_62 ( 1 , L_23 , V_60 ,
V_24 ) ;
return F_40 ( - V_10 ) ;
}
return & V_13 -> V_2 -> V_8 -> V_9 ;
}
static int T_2 F_70 ( void )
{
F_71 ( & V_75 , & V_76 ) ;
return 0 ;
}
static int T_2 F_72 ( struct V_69 * V_9 , void * V_77 )
{
struct V_19 * V_8 = F_21 ( V_9 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_14 ;
if ( ! V_2 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_48 ; V_14 ++ )
if ( V_2 -> V_20 [ V_14 ] -> V_32 & V_33 )
return 0 ;
if ( V_2 -> V_46 != V_70 ) {
if ( V_2 -> V_72 == V_73 ) {
F_55 ( V_9 , L_24 ,
V_60 ) ;
F_51 ( V_8 ) ;
}
}
return 0 ;
}
static int T_2 F_73 ( void )
{
F_74 ( & V_75 , NULL , NULL , F_72 ) ;
F_62 ( ! F_75 () ,
L_25 ) ;
return 0 ;
}
