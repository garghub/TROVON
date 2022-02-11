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
F_6 ( & V_2 -> V_9 -> V_10 ,
L_2 , V_3 ) ;
F_7 ( V_6 ) ;
return;
}
V_6 = F_8 ( NULL , V_4 ) ;
if ( F_5 ( V_6 ) ) {
F_9 ( & V_2 -> V_9 -> V_10 ,
L_3 , V_4 ) ;
return;
}
V_8 = F_10 ( V_6 , V_3 , F_4 ( & V_2 -> V_9 -> V_10 ) ) ;
if ( ! V_8 ) {
F_9 ( & V_2 -> V_9 -> V_10 ,
L_4 , V_3 ) ;
return;
}
F_11 ( V_8 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_13 ;
F_1 ( V_2 , L_5 , V_12 -> V_14 ) ;
for ( V_13 = 0 ; V_13 < V_12 -> V_15 ; V_13 ++ )
F_1 ( V_2 , V_12 -> V_16 [ V_13 ] . V_17 , V_12 -> V_16 [ V_13 ] . V_5 ) ;
}
static int F_13 ( struct V_18 * V_9 )
{
struct V_11 * * V_19 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_20 * V_21 = V_9 -> V_10 . V_22 ;
const char * V_23 ;
int V_24 , V_13 , V_25 = 0 ;
bool V_26 = false ;
V_24 = F_14 ( V_21 , L_6 ) ;
if ( V_24 <= 0 ) {
F_2 ( & V_9 -> V_10 , L_7 ) ;
return - V_27 ;
}
V_19 = F_15 ( sizeof( struct V_11 * ) * V_24 , V_28 ) ;
if ( ! V_19 ) {
V_25 = - V_29 ;
goto V_30;
}
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
F_16 ( V_21 , L_6 , V_13 , & V_23 ) ;
V_12 = F_17 ( V_23 ) ;
if ( ! V_12 ) {
F_9 ( & V_9 -> V_10 , L_8 ,
V_23 ) ;
V_25 = - V_31 ;
goto V_32;
}
V_19 [ V_13 ] = V_12 ;
if ( V_12 -> V_33 & V_34 )
V_26 = true ;
}
V_2 = F_18 ( V_9 , V_19 , V_24 ) ;
if ( ! V_2 ) {
F_9 ( & V_9 -> V_10 , L_9 ,
V_23 ) ;
V_25 = F_19 ( V_2 ) ;
goto V_32;
}
for ( V_13 = 0 ; V_13 < V_9 -> V_35 ; V_13 ++ ) {
struct V_36 * V_6 = & V_9 -> V_36 [ V_13 ] ;
if ( V_6 -> V_37 == NULL )
V_6 -> V_37 = F_4 ( & V_9 -> V_10 ) ;
}
V_9 -> V_10 . V_38 = & V_39 ;
if ( V_26 ) {
F_20 ( V_9 ) ;
F_21 ( & V_9 -> V_10 ) ;
}
V_32:
F_22 ( V_19 ) ;
V_30:
return V_25 ;
}
static int F_23 ( struct V_40 * V_41 ,
unsigned long V_42 , void * V_10 )
{
struct V_18 * V_9 = F_24 ( V_10 ) ;
struct V_1 * V_2 ;
switch ( V_42 ) {
case V_43 :
if ( V_9 -> V_44 . V_2 )
F_25 ( V_9 -> V_44 . V_2 ) ;
break;
case V_45 :
if ( V_9 -> V_10 . V_22 )
F_13 ( V_9 ) ;
default:
V_2 = F_26 ( V_9 ) ;
if ( V_2 )
V_2 -> V_46 = V_42 ;
}
return V_47 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_48 ; V_13 ++ )
F_28 ( V_2 -> V_19 [ V_13 ] ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_48 ; V_13 ++ )
F_30 ( V_2 -> V_19 [ V_13 ] ) ;
return 0 ;
}
int F_31 ( struct V_18 * V_9 )
{
struct V_1 * V_2 ;
T_1 V_25 = 0 ;
V_2 = F_26 ( V_9 ) ;
if ( V_2 -> V_48 )
V_25 = F_32 ( V_2 -> V_19 [ 0 ] ) ;
return V_25 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned long V_33 )
{
int V_49 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_48 ; V_13 ++ )
V_49 += F_34 ( V_2 -> V_19 [ V_13 ] , V_33 ) ;
F_35 ( L_10 ,
V_2 -> V_9 -> V_37 , V_49 , V_2 -> V_48 ) ;
return V_49 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_36 * V_50 )
{
int V_13 , V_6 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_48 ; V_13 ++ ) {
V_6 = F_37 ( V_2 -> V_19 [ V_13 ] , V_50 ) ;
V_50 += V_6 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_36 * V_50 )
{
int V_13 , V_6 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_48 ; V_13 ++ ) {
V_6 = F_39 ( V_2 -> V_19 [ V_13 ] , V_50 ) ;
V_50 += V_6 ;
}
return 0 ;
}
struct V_1 * F_18 ( struct V_18 * V_9 ,
struct V_11 * * V_51 , int V_24 )
{
int V_25 = - V_29 ;
struct V_1 * V_2 ;
struct V_36 * V_50 = NULL ;
int V_13 , V_52 ;
struct V_11 * * V_19 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
V_25 = - V_29 ;
goto V_53;
}
V_2 -> V_48 = V_24 ;
V_19 = F_40 ( V_51 , sizeof( struct V_11 * ) * V_24 , V_28 ) ;
if ( ! V_19 )
goto V_54;
V_2 -> V_19 = V_19 ;
V_2 -> V_9 = V_9 ;
if ( ! V_9 -> V_35 ) {
V_52 = F_33 ( V_2 , V_55 |
V_56 |
V_57 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_9 -> V_35 ; V_13 ++ ) {
struct V_36 * V_6 = & V_9 -> V_36 [ V_13 ] ;
if ( V_6 -> V_33 == V_56 )
goto V_58;
}
V_52 = F_33 ( V_2 , V_56 ) ;
if ( ! V_52 )
goto V_58;
V_52 += V_9 -> V_35 ;
}
V_50 = F_15 ( sizeof( struct V_36 ) * V_52 , V_28 ) ;
if ( ! V_50 )
goto V_59;
if ( ! V_9 -> V_35 ) {
F_2 ( & V_9 -> V_10 , L_11 ,
V_60 , V_52 ) ;
F_36 ( V_2 , V_50 ) ;
} else {
F_2 ( & V_9 -> V_10 ,
L_12 ,
V_60 , V_52 - V_9 -> V_35 ) ;
memcpy ( V_50 , V_9 -> V_36 ,
sizeof( struct V_36 ) * V_9 -> V_35 ) ;
F_38 ( V_2 , & V_50 [ V_9 -> V_35 ] ) ;
}
V_25 = F_41 ( V_9 , V_50 , V_52 ) ;
F_22 ( V_50 ) ;
if ( V_25 )
goto V_59;
V_58:
V_9 -> V_44 . V_2 = V_2 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
V_19 [ V_13 ] -> V_2 = V_2 ;
F_12 ( V_2 , V_19 [ V_13 ] ) ;
}
return V_2 ;
V_59:
F_22 ( V_19 ) ;
V_54:
F_22 ( V_2 ) ;
V_53:
F_9 ( & V_9 -> V_10 , L_13 , V_25 ) ;
return F_42 ( V_25 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_9 -> V_44 . V_2 = NULL ;
F_22 ( V_2 -> V_19 ) ;
F_22 ( V_2 ) ;
}
struct V_18 T_2 * F_43 ( const char * V_61 ,
int V_62 ,
struct V_11 * V_12 ,
void * V_63 , int V_64 )
{
struct V_11 * V_51 [] = { V_12 } ;
if ( ! V_12 )
return F_42 ( - V_31 ) ;
return F_44 ( V_61 , V_62 , V_51 , 1 , V_63 ,
V_64 ) ;
}
struct V_18 T_2 * F_44 ( const char * V_61 ,
int V_62 ,
struct V_11 * * V_51 ,
int V_24 , void * V_63 ,
int V_64 )
{
int V_25 = - V_29 ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
if ( ! V_51 || V_24 == 0 || ! V_61 )
return F_42 ( - V_31 ) ;
if ( ! V_63 && V_64 > 0 )
return F_42 ( - V_31 ) ;
V_9 = F_45 ( V_61 , V_62 ) ;
if ( ! V_9 ) {
V_25 = - V_29 ;
goto V_65;
}
if ( V_9 -> V_66 != - 1 )
F_46 ( & V_9 -> V_10 , L_14 , V_9 -> V_37 , V_9 -> V_66 ) ;
else
F_46 ( & V_9 -> V_10 , L_15 , V_9 -> V_37 ) ;
V_2 = F_18 ( V_9 , V_51 , V_24 ) ;
if ( F_5 ( V_2 ) )
goto V_67;
V_25 = F_47 ( V_9 , V_63 , V_64 ) ;
if ( V_25 )
goto V_68;
V_25 = F_48 ( V_9 ) ;
if ( V_25 )
goto V_68;
return V_9 ;
V_68:
F_25 ( V_2 ) ;
V_67:
F_49 ( V_9 ) ;
V_65:
F_50 ( L_16 , V_61 , V_25 ) ;
return F_42 ( V_25 ) ;
}
static int F_51 ( struct V_69 * V_10 )
{
struct V_18 * V_9 = F_24 ( V_10 ) ;
int V_25 ;
V_25 = F_52 ( V_10 ) ;
if ( ! V_25 )
F_53 ( V_9 ) ;
return V_25 ;
}
static int F_54 ( struct V_69 * V_10 )
{
struct V_18 * V_9 = F_24 ( V_10 ) ;
F_20 ( V_9 ) ;
return F_55 ( V_10 ) ;
}
static int F_56 ( struct V_69 * V_10 )
{
struct V_18 * V_9 = F_24 ( V_10 ) ;
struct V_1 * V_2 = F_26 ( V_9 ) ;
int V_25 ;
if ( V_2 -> V_46 != V_70 )
return 0 ;
V_25 = F_57 ( V_10 ) ;
if ( ! V_25 && ! F_58 ( V_10 ) ) {
if ( F_52 ( V_10 ) == 0 ) {
F_53 ( V_9 ) ;
V_2 -> V_33 |= V_71 ;
}
}
return V_25 ;
}
static int F_59 ( struct V_69 * V_10 )
{
struct V_18 * V_9 = F_24 ( V_10 ) ;
struct V_1 * V_2 = F_26 ( V_9 ) ;
if ( ( V_2 -> V_33 & V_71 ) &&
! F_58 ( V_10 ) ) {
V_2 -> V_33 &= ~ V_71 ;
F_20 ( V_9 ) ;
F_55 ( V_10 ) ;
}
return F_60 ( V_10 ) ;
}
int F_48 ( struct V_18 * V_9 )
{
F_35 ( L_17 , V_9 -> V_37 ) ;
V_9 -> V_10 . V_38 = & V_39 ;
return F_61 ( V_9 ) ;
}
int F_20 ( struct V_18 * V_9 )
{
int V_25 ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_9 ) ;
if ( V_2 -> V_72 == V_73 ) {
F_6 ( & V_9 -> V_10 ,
L_18 ,
V_60 , V_2 -> V_72 ) ;
return - V_31 ;
}
V_25 = F_27 ( V_2 ) ;
V_2 -> V_72 = V_73 ;
return V_25 ;
}
int F_53 ( struct V_18 * V_9 )
{
int V_25 ;
struct V_1 * V_2 ;
V_2 = F_26 ( V_9 ) ;
if ( V_2 -> V_72 != V_73 ) {
F_6 ( & V_9 -> V_10 ,
L_18 ,
V_60 , V_2 -> V_72 ) ;
return - V_31 ;
}
V_25 = F_29 ( V_2 ) ;
V_2 -> V_72 = V_74 ;
return V_25 ;
}
int F_62 ( struct V_18 * V_9 , const char * V_37 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
int V_25 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_48 ; V_13 ++ ) {
V_25 = F_63 ( V_2 -> V_19 [ V_13 ] , V_37 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_64 ( struct V_18 * V_9 ,
const char * V_37 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
int V_25 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_48 ; V_13 ++ ) {
V_25 = F_65 ( V_2 -> V_19 [ V_13 ] , V_37 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
struct V_69 * F_66 ( const char * V_23 )
{
struct V_11 * V_12 ;
if ( ! V_23 ) {
F_67 ( 1 , L_19 , V_60 ) ;
return F_42 ( - V_31 ) ;
}
V_12 = F_17 ( V_23 ) ;
if ( ! V_12 ) {
F_67 ( 1 , L_20 , V_60 ,
V_23 ) ;
return F_42 ( - V_27 ) ;
}
if ( ! V_12 -> V_2 ) {
F_67 ( 1 , L_21 , V_60 ,
V_23 ) ;
return F_42 ( - V_27 ) ;
}
return & V_12 -> V_2 -> V_9 -> V_10 ;
}
static int T_2 F_68 ( void )
{
F_69 ( & V_75 , & V_76 ) ;
return 0 ;
}
static int T_2 F_70 ( struct V_69 * V_10 , void * V_77 )
{
struct V_18 * V_9 = F_24 ( V_10 ) ;
struct V_1 * V_2 = F_26 ( V_9 ) ;
int V_13 ;
if ( ! V_2 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_48 ; V_13 ++ )
if ( V_2 -> V_19 [ V_13 ] -> V_33 & V_34 )
return 0 ;
if ( V_2 -> V_46 != V_70 ) {
if ( V_2 -> V_72 == V_73 ) {
F_6 ( V_10 , L_22 ,
V_60 ) ;
F_53 ( V_9 ) ;
}
}
return 0 ;
}
static int T_2 F_71 ( void )
{
F_72 ( & V_75 , NULL , NULL , F_70 ) ;
return 0 ;
}
