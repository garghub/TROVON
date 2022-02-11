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
V_24 = F_14 ( V_21 , L_6 ) ;
if ( ! V_24 || F_15 ( V_24 ) ) {
F_2 ( & V_9 -> V_10 , L_7 ) ;
return - V_26 ;
}
V_19 = F_16 ( sizeof( struct V_11 * ) * V_24 , V_27 ) ;
if ( ! V_19 ) {
V_25 = - V_28 ;
goto V_29;
}
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
F_17 ( V_21 , L_6 , V_13 , & V_23 ) ;
V_12 = F_18 ( V_23 ) ;
if ( ! V_12 ) {
F_9 ( & V_9 -> V_10 , L_8 ,
V_23 ) ;
V_25 = - V_30 ;
goto V_31;
}
V_19 [ V_13 ] = V_12 ;
}
V_2 = F_19 ( V_9 , V_19 , V_24 ) ;
if ( ! V_2 ) {
F_9 ( & V_9 -> V_10 , L_9 ,
V_23 ) ;
V_25 = F_20 ( V_2 ) ;
goto V_31;
}
for ( V_13 = 0 ; V_13 < V_9 -> V_32 ; V_13 ++ ) {
struct V_33 * V_6 = & V_9 -> V_33 [ V_13 ] ;
if ( V_6 -> V_34 == NULL )
V_6 -> V_34 = F_4 ( & V_9 -> V_10 ) ;
}
if ( F_21 ( V_21 , L_10 , NULL ) )
F_22 ( V_9 ) ;
V_9 -> V_10 . V_35 = & V_36 ;
V_31:
F_23 ( V_19 ) ;
V_29:
return V_25 ;
}
static int F_24 ( struct V_37 * V_38 ,
unsigned long V_39 , void * V_10 )
{
struct V_18 * V_9 = F_25 ( V_10 ) ;
struct V_1 * V_2 ;
switch ( V_39 ) {
case V_40 :
if ( V_9 -> V_41 . V_2 )
F_26 ( V_9 -> V_41 . V_2 ) ;
break;
case V_42 :
if ( V_9 -> V_10 . V_22 )
F_13 ( V_9 ) ;
default:
V_2 = F_27 ( V_9 ) ;
if ( V_2 )
V_2 -> V_43 = V_39 ;
}
return V_44 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_45 ; V_13 ++ )
F_29 ( V_2 -> V_19 [ V_13 ] ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_45 ; V_13 ++ )
F_31 ( V_2 -> V_19 [ V_13 ] ) ;
return 0 ;
}
int F_32 ( struct V_18 * V_9 )
{
struct V_1 * V_2 ;
T_1 V_25 = 0 ;
V_2 = F_27 ( V_9 ) ;
if ( V_2 -> V_45 )
V_25 = F_33 ( V_2 -> V_19 [ 0 ] ) ;
return V_25 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned long V_46 )
{
int V_47 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_45 ; V_13 ++ )
V_47 += F_35 ( V_2 -> V_19 [ V_13 ] , V_46 ) ;
F_36 ( L_11 ,
V_2 -> V_9 -> V_34 , V_47 , V_2 -> V_45 ) ;
return V_47 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_33 * V_48 )
{
int V_13 , V_6 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_45 ; V_13 ++ ) {
V_6 = F_38 ( V_2 -> V_19 [ V_13 ] , V_48 ) ;
V_48 += V_6 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_33 * V_48 )
{
int V_13 , V_6 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_45 ; V_13 ++ ) {
V_6 = F_40 ( V_2 -> V_19 [ V_13 ] , V_48 ) ;
V_48 += V_6 ;
}
return 0 ;
}
struct V_1 * F_19 ( struct V_18 * V_9 ,
struct V_11 * * V_49 , int V_24 )
{
int V_25 = - V_28 ;
struct V_1 * V_2 ;
struct V_33 * V_48 = NULL ;
int V_13 , V_50 ;
struct V_11 * * V_19 ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_2 ) {
V_25 = - V_28 ;
goto V_51;
}
V_2 -> V_45 = V_24 ;
V_19 = F_41 ( V_49 , sizeof( struct V_11 * ) * V_24 , V_27 ) ;
if ( ! V_19 )
goto V_52;
V_2 -> V_19 = V_19 ;
V_2 -> V_9 = V_9 ;
if ( ! V_9 -> V_32 ) {
V_50 = F_34 ( V_2 , V_53 |
V_54 |
V_55 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_9 -> V_32 ; V_13 ++ ) {
struct V_33 * V_6 = & V_9 -> V_33 [ V_13 ] ;
if ( V_6 -> V_46 == V_54 )
goto V_56;
}
V_50 = F_34 ( V_2 , V_54 ) ;
if ( ! V_50 )
goto V_56;
V_50 += V_9 -> V_32 ;
}
V_48 = F_16 ( sizeof( struct V_33 ) * V_50 , V_27 ) ;
if ( ! V_48 )
goto V_57;
if ( ! V_9 -> V_32 ) {
F_2 ( & V_9 -> V_10 , L_12 ,
V_58 , V_50 ) ;
F_37 ( V_2 , V_48 ) ;
} else {
F_2 ( & V_9 -> V_10 ,
L_13 ,
V_58 , V_50 - V_9 -> V_32 ) ;
memcpy ( V_48 , V_9 -> V_33 ,
sizeof( struct V_33 ) * V_9 -> V_32 ) ;
F_39 ( V_2 , & V_48 [ V_9 -> V_32 ] ) ;
}
V_25 = F_42 ( V_9 , V_48 , V_50 ) ;
F_23 ( V_48 ) ;
if ( V_25 )
goto V_57;
V_56:
V_9 -> V_41 . V_2 = V_2 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
V_19 [ V_13 ] -> V_2 = V_2 ;
F_12 ( V_2 , V_19 [ V_13 ] ) ;
}
return V_2 ;
V_57:
F_23 ( V_19 ) ;
V_52:
F_23 ( V_2 ) ;
V_51:
F_9 ( & V_9 -> V_10 , L_14 , V_25 ) ;
return F_43 ( V_25 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_9 -> V_41 . V_2 = NULL ;
F_23 ( V_2 -> V_19 ) ;
F_23 ( V_2 ) ;
}
struct V_18 T_2 * F_44 ( const char * V_59 ,
int V_60 ,
struct V_11 * V_12 ,
void * V_61 , int V_62 )
{
struct V_11 * V_49 [] = { V_12 } ;
if ( ! V_12 )
return F_43 ( - V_30 ) ;
return F_45 ( V_59 , V_60 , V_49 , 1 , V_61 ,
V_62 ) ;
}
struct V_18 T_2 * F_45 ( const char * V_59 ,
int V_60 ,
struct V_11 * * V_49 ,
int V_24 , void * V_61 ,
int V_62 )
{
int V_25 = - V_28 ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
if ( ! V_49 || V_24 == 0 || ! V_59 )
return F_43 ( - V_30 ) ;
if ( ! V_61 && V_62 > 0 )
return F_43 ( - V_30 ) ;
V_9 = F_46 ( V_59 , V_60 ) ;
if ( ! V_9 ) {
V_25 = - V_28 ;
goto V_63;
}
if ( V_9 -> V_64 != - 1 )
F_47 ( & V_9 -> V_10 , L_15 , V_9 -> V_34 , V_9 -> V_64 ) ;
else
F_47 ( & V_9 -> V_10 , L_16 , V_9 -> V_34 ) ;
V_2 = F_19 ( V_9 , V_49 , V_24 ) ;
if ( F_5 ( V_2 ) )
goto V_65;
V_25 = F_48 ( V_9 , V_61 , V_62 ) ;
if ( V_25 )
goto V_66;
V_25 = F_49 ( V_9 ) ;
if ( V_25 )
goto V_66;
return V_9 ;
V_66:
F_26 ( V_2 ) ;
V_65:
F_50 ( V_9 ) ;
V_63:
F_51 ( L_17 , V_59 , V_25 ) ;
return F_43 ( V_25 ) ;
}
static int F_52 ( struct V_67 * V_10 )
{
struct V_18 * V_9 = F_25 ( V_10 ) ;
int V_25 ;
V_25 = F_53 ( V_10 ) ;
if ( ! V_25 )
F_54 ( V_9 ) ;
return V_25 ;
}
static int F_55 ( struct V_67 * V_10 )
{
return F_56 ( V_10 ) ;
}
static int F_57 ( struct V_67 * V_10 )
{
struct V_18 * V_9 = F_25 ( V_10 ) ;
F_58 ( V_9 ) ;
return F_59 ( V_10 ) ;
}
static int F_60 ( struct V_67 * V_10 )
{
struct V_18 * V_9 = F_25 ( V_10 ) ;
struct V_1 * V_2 = F_27 ( V_9 ) ;
int V_25 ;
if ( V_2 -> V_43 != V_68 )
return 0 ;
V_25 = F_61 ( V_10 ) ;
if ( ! V_25 && ! F_62 ( V_10 ) ) {
if ( F_53 ( V_10 ) == 0 ) {
if ( ! ( V_2 -> V_46 & V_69 ) )
F_54 ( V_9 ) ;
V_2 -> V_46 |= V_70 ;
}
}
return V_25 ;
}
static int F_63 ( struct V_67 * V_10 )
{
struct V_18 * V_9 = F_25 ( V_10 ) ;
struct V_1 * V_2 = F_27 ( V_9 ) ;
if ( ( V_2 -> V_46 & V_70 ) &&
! F_62 ( V_10 ) ) {
V_2 -> V_46 &= ~ V_70 ;
if ( ! ( V_2 -> V_46 & V_69 ) )
F_58 ( V_9 ) ;
F_59 ( V_10 ) ;
}
return F_64 ( V_10 ) ;
}
int F_49 ( struct V_18 * V_9 )
{
F_36 ( L_18 , V_9 -> V_34 ) ;
V_9 -> V_10 . V_35 = & V_36 ;
return F_65 ( V_9 ) ;
}
int F_58 ( struct V_18 * V_9 )
{
int V_25 ;
struct V_1 * V_2 ;
V_2 = F_27 ( V_9 ) ;
if ( V_2 -> V_71 == V_72 ) {
F_6 ( & V_9 -> V_10 ,
L_19 ,
V_58 , V_2 -> V_71 ) ;
return - V_30 ;
}
V_25 = F_28 ( V_2 ) ;
V_2 -> V_71 = V_72 ;
return V_25 ;
}
int F_54 ( struct V_18 * V_9 )
{
int V_25 ;
struct V_1 * V_2 ;
V_2 = F_27 ( V_9 ) ;
if ( V_2 -> V_71 != V_72 ) {
F_6 ( & V_9 -> V_10 ,
L_19 ,
V_58 , V_2 -> V_71 ) ;
return - V_30 ;
}
V_25 = F_30 ( V_2 ) ;
V_2 -> V_71 = V_73 ;
return V_25 ;
}
int F_66 ( struct V_18 * V_9 , const char * V_34 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
int V_25 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_45 ; V_13 ++ ) {
V_25 = F_67 ( V_2 -> V_19 [ V_13 ] , V_34 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_68 ( struct V_18 * V_9 ,
const char * V_34 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
int V_25 = 0 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_45 ; V_13 ++ ) {
V_25 = F_69 ( V_2 -> V_19 [ V_13 ] , V_34 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
struct V_67 * F_70 ( const char * V_23 )
{
struct V_11 * V_12 ;
if ( ! V_23 ) {
F_71 ( 1 , L_20 , V_58 ) ;
return F_43 ( - V_30 ) ;
}
V_12 = F_18 ( V_23 ) ;
if ( F_72 ( V_12 ) ) {
F_71 ( 1 , L_21 , V_58 ,
V_23 ) ;
return F_43 ( V_12 ? F_20 ( V_12 ) : - V_26 ) ;
}
if ( F_72 ( V_12 -> V_2 ) ) {
F_71 ( 1 , L_22 , V_58 ,
V_23 ) ;
return F_43 ( V_12 -> V_2 ? F_20 ( V_12 -> V_2 ) : - V_26 ) ;
}
if ( F_72 ( V_12 -> V_2 -> V_9 ) )
return F_43 ( V_12 -> V_2 -> V_9 ? F_20 ( V_12 -> V_2 -> V_9 ) : - V_26 ) ;
return & V_12 -> V_2 -> V_9 -> V_10 ;
}
static int T_2 F_73 ( void )
{
F_74 ( & V_74 , & V_75 ) ;
return 0 ;
}
static int T_2 F_75 ( struct V_67 * V_10 , void * V_76 )
{
struct V_18 * V_9 = F_25 ( V_10 ) ;
struct V_1 * V_2 = F_27 ( V_9 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_43 != V_68 ) {
if ( V_2 -> V_71 == V_72 ) {
F_6 ( V_10 , L_23 ,
V_58 ) ;
F_54 ( V_9 ) ;
}
}
return 0 ;
}
static int T_2 F_76 ( void )
{
F_77 ( & V_74 , NULL , NULL , F_75 ) ;
return 0 ;
}
