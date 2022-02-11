static void F_1 ( struct V_1 * V_2 , const char * V_3 ,
const char * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( ! V_3 || ! V_4 )
return;
F_2 ( & V_2 -> V_9 -> V_10 , L_1 , V_3 , V_4 ) ;
V_6 = F_3 ( F_4 ( & V_2 -> V_9 -> V_10 ) , V_3 ) ;
if ( ! F_5 ( V_6 ) ) {
F_2 ( & V_2 -> V_9 -> V_10 ,
L_2 , V_3 ) ;
F_6 ( V_6 ) ;
return;
}
V_6 = F_7 ( NULL , V_4 ) ;
if ( F_5 ( V_6 ) ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_3 , V_4 ) ;
return;
}
V_8 = F_9 ( V_6 , V_3 , F_4 ( & V_2 -> V_9 -> V_10 ) ) ;
if ( ! V_8 ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_4 , V_3 ) ;
return;
}
F_10 ( V_8 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_13 ;
F_1 ( V_2 , L_5 , V_12 -> V_14 ) ;
for ( V_13 = 0 ; V_13 < V_12 -> V_15 ; V_13 ++ )
F_1 ( V_2 , V_12 -> V_16 [ V_13 ] . V_17 , V_12 -> V_16 [ V_13 ] . V_5 ) ;
}
static int F_12 ( struct V_18 * V_9 )
{
struct V_11 * * V_19 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_20 * V_21 = V_9 -> V_10 . V_22 ;
const char * V_23 ;
int V_24 , V_13 , V_25 = 0 ;
bool V_26 = false ;
V_24 = F_13 ( V_21 , L_6 ) ;
if ( V_24 <= 0 ) {
F_2 ( & V_9 -> V_10 , L_7 ) ;
return - V_27 ;
}
V_19 = F_14 ( sizeof( struct V_11 * ) * V_24 , V_28 ) ;
if ( ! V_19 ) {
V_25 = - V_29 ;
goto V_30;
}
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
F_15 ( V_21 , L_6 , V_13 , & V_23 ) ;
V_12 = F_16 ( V_23 ) ;
if ( ! V_12 ) {
F_8 ( & V_9 -> V_10 , L_8 ,
V_23 ) ;
V_25 = - V_31 ;
goto V_32;
}
V_19 [ V_13 ] = V_12 ;
if ( V_12 -> V_33 & V_34 )
V_26 = true ;
}
V_2 = F_17 ( V_9 , V_19 , V_24 ) ;
if ( F_5 ( V_2 ) ) {
F_8 ( & V_9 -> V_10 , L_9 ,
V_23 ) ;
V_25 = F_18 ( V_2 ) ;
goto V_32;
}
for ( V_13 = 0 ; V_13 < V_9 -> V_35 ; V_13 ++ ) {
struct V_36 * V_6 = & V_9 -> V_36 [ V_13 ] ;
if ( V_6 -> V_37 == NULL )
V_6 -> V_37 = F_4 ( & V_9 -> V_10 ) ;
}
V_9 -> V_10 . V_38 = & V_39 ;
if ( V_26 ) {
F_19 ( V_9 ) ;
F_20 ( & V_9 -> V_10 ) ;
}
V_32:
F_21 ( V_19 ) ;
V_30:
if ( V_25 )
V_9 -> V_10 . V_38 = & V_40 ;
return V_25 ;
}
static int F_22 ( struct V_41 * V_42 ,
unsigned long V_43 , void * V_10 )
{
struct V_18 * V_9 = F_23 ( V_10 ) ;
struct V_1 * V_2 ;
switch ( V_43 ) {
case V_44 :
if ( V_9 -> V_45 . V_2 )
F_24 ( V_9 -> V_45 . V_2 ) ;
break;
case V_46 :
if ( V_9 -> V_10 . V_22 )
F_12 ( V_9 ) ;
F_25 ( V_10 ) ;
default:
V_2 = F_26 ( V_9 ) ;
if ( V_2 )
V_2 -> V_47 = V_43 ;
}
return V_48 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_49 ; V_13 ++ )
F_28 ( V_2 -> V_19 [ V_13 ] ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_49 ; V_13 ++ )
F_30 ( V_2 -> V_19 [ V_13 ] ) ;
return 0 ;
}
int F_31 ( struct V_18 * V_9 )
{
struct V_1 * V_2 ;
T_1 V_25 = 0 ;
V_2 = F_26 ( V_9 ) ;
if ( V_2 -> V_49 )
V_25 = F_32 ( V_2 -> V_19 [ 0 ] ) ;
return V_25 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned long V_33 )
{
int V_50 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_49 ; V_13 ++ )
V_50 += F_34 ( V_2 -> V_19 [ V_13 ] , V_33 ) ;
F_35 ( L_10 ,
V_2 -> V_9 -> V_37 , V_50 , V_2 -> V_49 ) ;
return V_50 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_36 * V_51 )
{
int V_13 , V_6 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_49 ; V_13 ++ ) {
V_6 = F_37 ( V_2 -> V_19 [ V_13 ] , V_51 ) ;
V_51 += V_6 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_36 * V_51 )
{
int V_13 , V_6 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_49 ; V_13 ++ ) {
V_6 = F_39 ( V_2 -> V_19 [ V_13 ] , V_51 ) ;
V_51 += V_6 ;
}
return 0 ;
}
struct V_1 * F_17 ( struct V_18 * V_9 ,
struct V_11 * * V_52 , int V_24 )
{
int V_25 = - V_29 ;
struct V_1 * V_2 ;
struct V_36 * V_51 = NULL ;
int V_13 , V_53 ;
struct V_11 * * V_19 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
V_25 = - V_29 ;
goto V_54;
}
V_2 -> V_49 = V_24 ;
V_19 = F_40 ( V_52 , sizeof( struct V_11 * ) * V_24 , V_28 ) ;
if ( ! V_19 )
goto V_55;
V_2 -> V_19 = V_19 ;
V_2 -> V_9 = V_9 ;
if ( ! V_9 -> V_35 ) {
V_53 = F_33 ( V_2 , V_56 |
V_57 |
V_58 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_9 -> V_35 ; V_13 ++ ) {
struct V_36 * V_6 = & V_9 -> V_36 [ V_13 ] ;
if ( V_6 -> V_33 == V_57 )
goto V_59;
}
V_53 = F_33 ( V_2 , V_57 ) ;
if ( ! V_53 )
goto V_59;
V_53 += V_9 -> V_35 ;
}
V_51 = F_14 ( sizeof( struct V_36 ) * V_53 , V_28 ) ;
if ( ! V_51 )
goto V_60;
if ( ! V_9 -> V_35 ) {
F_2 ( & V_9 -> V_10 , L_11 ,
V_61 , V_53 ) ;
F_36 ( V_2 , V_51 ) ;
} else {
F_2 ( & V_9 -> V_10 ,
L_12 ,
V_61 , V_53 - V_9 -> V_35 ) ;
memcpy ( V_51 , V_9 -> V_36 ,
sizeof( struct V_36 ) * V_9 -> V_35 ) ;
F_38 ( V_2 , & V_51 [ V_9 -> V_35 ] ) ;
}
V_25 = F_41 ( V_9 , V_51 , V_53 ) ;
F_21 ( V_51 ) ;
if ( V_25 )
goto V_60;
V_59:
V_9 -> V_45 . V_2 = V_2 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
V_19 [ V_13 ] -> V_2 = V_2 ;
F_11 ( V_2 , V_19 [ V_13 ] ) ;
}
return V_2 ;
V_60:
F_21 ( V_19 ) ;
V_55:
F_21 ( V_2 ) ;
V_54:
F_8 ( & V_9 -> V_10 , L_13 , V_25 ) ;
return F_42 ( V_25 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_9 -> V_45 . V_2 = NULL ;
F_21 ( V_2 -> V_19 ) ;
F_21 ( V_2 ) ;
}
struct V_18 T_2 * F_43 ( const char * V_62 ,
int V_63 ,
struct V_11 * V_12 ,
void * V_64 , int V_65 )
{
struct V_11 * V_52 [] = { V_12 } ;
if ( ! V_12 )
return F_42 ( - V_31 ) ;
return F_44 ( V_62 , V_63 , V_52 , 1 , V_64 ,
V_65 ) ;
}
struct V_18 T_2 * F_44 ( const char * V_62 ,
int V_63 ,
struct V_11 * * V_52 ,
int V_24 , void * V_64 ,
int V_65 )
{
int V_25 = - V_29 ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
if ( ! V_52 || V_24 == 0 || ! V_62 )
return F_42 ( - V_31 ) ;
if ( ! V_64 && V_65 > 0 )
return F_42 ( - V_31 ) ;
V_9 = F_45 ( V_62 , V_63 ) ;
if ( ! V_9 ) {
V_25 = - V_29 ;
goto V_66;
}
if ( V_9 -> V_67 != - 1 )
F_46 ( & V_9 -> V_10 , L_14 , V_9 -> V_37 , V_9 -> V_67 ) ;
else
F_46 ( & V_9 -> V_10 , L_15 , V_9 -> V_37 ) ;
V_2 = F_17 ( V_9 , V_52 , V_24 ) ;
if ( F_5 ( V_2 ) )
goto V_68;
V_25 = F_47 ( V_9 , V_64 , V_65 ) ;
if ( V_25 )
goto V_69;
V_25 = F_48 ( V_9 ) ;
if ( V_25 )
goto V_69;
return V_9 ;
V_69:
F_24 ( V_2 ) ;
V_68:
F_49 ( V_9 ) ;
V_66:
F_50 ( L_16 , V_62 , V_25 ) ;
return F_42 ( V_25 ) ;
}
static int F_51 ( struct V_70 * V_10 )
{
struct V_18 * V_9 = F_23 ( V_10 ) ;
int V_25 ;
V_25 = F_52 ( V_10 ) ;
if ( ! V_25 )
F_53 ( V_9 ) ;
return V_25 ;
}
static int F_54 ( struct V_70 * V_10 )
{
struct V_18 * V_9 = F_23 ( V_10 ) ;
F_19 ( V_9 ) ;
return F_55 ( V_10 ) ;
}
static int F_56 ( struct V_70 * V_10 )
{
F_57 ( V_10 , L_17 , V_61 ) ;
return - V_27 ;
}
static int F_58 ( struct V_70 * V_10 )
{
F_57 ( V_10 , L_17 , V_61 ) ;
return - V_27 ;
}
static int F_59 ( struct V_70 * V_10 )
{
struct V_18 * V_9 = F_23 ( V_10 ) ;
struct V_1 * V_2 = F_26 ( V_9 ) ;
int V_25 ;
if ( V_2 -> V_47 != V_71 )
return 0 ;
V_25 = F_60 ( V_10 ) ;
if ( ! V_25 && ! F_61 ( V_10 ) ) {
if ( F_52 ( V_10 ) == 0 ) {
F_62 ( V_10 ) ;
F_53 ( V_9 ) ;
V_2 -> V_33 |= V_72 ;
}
}
return V_25 ;
}
static int F_63 ( struct V_70 * V_10 )
{
struct V_18 * V_9 = F_23 ( V_10 ) ;
struct V_1 * V_2 = F_26 ( V_9 ) ;
if ( V_2 -> V_33 & V_72 ) {
V_2 -> V_33 &= ~ V_72 ;
F_19 ( V_9 ) ;
F_64 ( F_20 ( V_10 ) ,
L_18 , F_4 ( V_10 ) ) ;
F_55 ( V_10 ) ;
}
return F_65 ( V_10 ) ;
}
int F_48 ( struct V_18 * V_9 )
{
F_35 ( L_19 , V_9 -> V_37 ) ;
V_9 -> V_10 . V_38 = & V_39 ;
return F_66 ( V_9 ) ;
}
int F_19 ( struct V_18 * V_9 )
{
int V_25 ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_9 ) ;
if ( V_2 -> V_73 == V_74 ) {
F_57 ( & V_9 -> V_10 ,
L_20 ,
V_61 , V_2 -> V_73 ) ;
return - V_31 ;
}
V_25 = F_27 ( V_2 ) ;
V_2 -> V_73 = V_74 ;
return V_25 ;
}
int F_53 ( struct V_18 * V_9 )
{
int V_25 ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_9 ) ;
if ( V_2 -> V_73 != V_74 ) {
F_57 ( & V_9 -> V_10 ,
L_20 ,
V_61 , V_2 -> V_73 ) ;
return - V_31 ;
}
V_25 = F_29 ( V_2 ) ;
V_2 -> V_73 = V_75 ;
return V_25 ;
}
int F_67 ( struct V_18 * V_9 , const char * V_37 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
int V_25 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_49 ; V_13 ++ ) {
V_25 = F_68 ( V_2 -> V_19 [ V_13 ] , V_37 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_69 ( struct V_18 * V_9 ,
const char * V_37 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
int V_25 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_49 ; V_13 ++ ) {
V_25 = F_70 ( V_2 -> V_19 [ V_13 ] , V_37 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
struct V_70 * F_71 ( const char * V_23 )
{
struct V_11 * V_12 ;
if ( ! V_23 ) {
F_64 ( 1 , L_21 , V_61 ) ;
return F_42 ( - V_31 ) ;
}
V_12 = F_16 ( V_23 ) ;
if ( ! V_12 ) {
F_64 ( 1 , L_22 , V_61 ,
V_23 ) ;
return F_42 ( - V_27 ) ;
}
if ( ! V_12 -> V_2 ) {
F_64 ( 1 , L_23 , V_61 ,
V_23 ) ;
return F_42 ( - V_27 ) ;
}
return & V_12 -> V_2 -> V_9 -> V_10 ;
}
static int T_2 F_72 ( void )
{
F_73 ( & V_76 , & V_77 ) ;
return 0 ;
}
static int T_2 F_74 ( struct V_70 * V_10 , void * V_78 )
{
struct V_18 * V_9 = F_23 ( V_10 ) ;
struct V_1 * V_2 = F_26 ( V_9 ) ;
int V_13 ;
if ( ! V_2 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_49 ; V_13 ++ )
if ( V_2 -> V_19 [ V_13 ] -> V_33 & V_34 )
return 0 ;
if ( V_2 -> V_47 != V_71 ) {
if ( V_2 -> V_73 == V_74 ) {
F_57 ( V_10 , L_24 ,
V_61 ) ;
F_53 ( V_9 ) ;
}
}
return 0 ;
}
static int T_2 F_75 ( void )
{
F_76 ( & V_76 , NULL , NULL , F_74 ) ;
return 0 ;
}
