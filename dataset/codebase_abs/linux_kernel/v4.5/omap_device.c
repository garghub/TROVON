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
F_17 ( & V_8 -> V_9 , & V_37 ) ;
if ( V_27 ) {
F_18 ( V_8 ) ;
F_19 ( & V_8 -> V_9 ) ;
}
V_31:
F_20 ( V_20 ) ;
V_29:
if ( V_26 )
F_17 ( & V_8 -> V_9 , & V_38 ) ;
return V_26 ;
}
static int F_21 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_9 )
{
struct V_19 * V_8 = F_22 ( V_9 ) ;
struct V_1 * V_2 ;
int V_42 ;
switch ( V_41 ) {
case V_43 :
if ( V_8 -> V_44 . V_2 )
F_23 ( V_8 -> V_44 . V_2 ) ;
break;
case V_45 :
V_2 = F_24 ( V_8 ) ;
if ( V_2 && ( V_2 -> V_46 == V_47 ) ) {
F_25 ( V_9 , L_10 ) ;
V_42 = F_26 ( V_8 ) ;
if ( V_42 )
F_8 ( V_9 , L_11 ) ;
}
break;
case V_48 :
if ( V_8 -> V_9 . V_23 )
F_10 ( V_8 ) ;
F_27 ( V_9 ) ;
default:
V_2 = F_24 ( V_8 ) ;
if ( V_2 )
V_2 -> V_49 = V_41 ;
}
return V_50 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_51 ; V_14 ++ )
V_26 |= F_29 ( V_2 -> V_20 [ V_14 ] ) ;
return V_26 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_51 ; V_14 ++ )
V_26 |= F_31 ( V_2 -> V_20 [ V_14 ] ) ;
return V_26 ;
}
int F_32 ( struct V_19 * V_8 )
{
struct V_1 * V_2 ;
T_1 V_26 = 0 ;
V_2 = F_24 ( V_8 ) ;
if ( V_2 -> V_51 )
V_26 = F_33 ( V_2 -> V_20 [ 0 ] ) ;
return V_26 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
int V_52 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_51 ; V_14 ++ )
V_52 += F_35 ( V_2 -> V_20 [ V_14 ] , V_32 ) ;
F_36 ( L_12 ,
V_2 -> V_8 -> V_36 , V_52 , V_2 -> V_51 ) ;
return V_52 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_35 * V_53 )
{
int V_14 , V_6 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_51 ; V_14 ++ ) {
V_6 = F_38 ( V_2 -> V_20 [ V_14 ] , V_53 ) ;
V_53 += V_6 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_35 * V_53 )
{
int V_14 , V_6 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_51 ; V_14 ++ ) {
V_6 = F_40 ( V_2 -> V_20 [ V_14 ] , V_53 ) ;
V_53 += V_6 ;
}
return 0 ;
}
struct V_1 * F_15 ( struct V_19 * V_8 ,
struct V_12 * * V_54 , int V_25 )
{
int V_26 = - V_11 ;
struct V_1 * V_2 ;
struct V_35 * V_53 = NULL ;
int V_14 , V_55 ;
struct V_12 * * V_20 ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
V_26 = - V_11 ;
goto V_56;
}
V_2 -> V_51 = V_25 ;
V_20 = F_41 ( V_54 , sizeof( struct V_12 * ) * V_25 , V_28 ) ;
if ( ! V_20 )
goto V_57;
V_2 -> V_20 = V_20 ;
V_2 -> V_8 = V_8 ;
if ( ! V_8 -> V_34 ) {
V_55 = F_34 ( V_2 , V_58 |
V_59 |
V_60 ) ;
} else {
for ( V_14 = 0 ; V_14 < V_8 -> V_34 ; V_14 ++ ) {
struct V_35 * V_6 = & V_8 -> V_35 [ V_14 ] ;
if ( V_6 -> V_32 == V_59 )
goto V_61;
}
V_55 = F_34 ( V_2 , V_59 ) ;
if ( ! V_55 )
goto V_61;
V_55 += V_8 -> V_34 ;
}
V_53 = F_12 ( sizeof( struct V_35 ) * V_55 , V_28 ) ;
if ( ! V_53 )
goto V_62;
if ( ! V_8 -> V_34 ) {
F_2 ( & V_8 -> V_9 , L_13 ,
V_63 , V_55 ) ;
F_37 ( V_2 , V_53 ) ;
} else {
F_2 ( & V_8 -> V_9 ,
L_14 ,
V_63 , V_55 - V_8 -> V_34 ) ;
memcpy ( V_53 , V_8 -> V_35 ,
sizeof( struct V_35 ) * V_8 -> V_34 ) ;
F_39 ( V_2 , & V_53 [ V_8 -> V_34 ] ) ;
}
V_26 = F_42 ( V_8 , V_53 , V_55 ) ;
F_20 ( V_53 ) ;
if ( V_26 )
goto V_62;
V_61:
V_8 -> V_44 . V_2 = V_2 ;
for ( V_14 = 0 ; V_14 < V_25 ; V_14 ++ ) {
V_20 [ V_14 ] -> V_2 = V_2 ;
F_9 ( V_2 , V_20 [ V_14 ] ) ;
}
return V_2 ;
V_62:
F_20 ( V_20 ) ;
V_57:
F_20 ( V_2 ) ;
V_56:
F_8 ( & V_8 -> V_9 , L_15 , V_26 ) ;
return F_43 ( V_26 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_8 -> V_44 . V_2 = NULL ;
F_20 ( V_2 -> V_20 ) ;
F_20 ( V_2 ) ;
}
struct V_19 T_2 * F_44 ( const char * V_64 ,
int V_65 ,
struct V_12 * V_13 ,
void * V_66 , int V_67 )
{
struct V_12 * V_54 [] = { V_13 } ;
if ( ! V_13 )
return F_43 ( - V_30 ) ;
return F_45 ( V_64 , V_65 , V_54 , 1 , V_66 ,
V_67 ) ;
}
struct V_19 T_2 * F_45 ( const char * V_64 ,
int V_65 ,
struct V_12 * * V_54 ,
int V_25 , void * V_66 ,
int V_67 )
{
int V_26 = - V_11 ;
struct V_19 * V_8 ;
struct V_1 * V_2 ;
if ( ! V_54 || V_25 == 0 || ! V_64 )
return F_43 ( - V_30 ) ;
if ( ! V_66 && V_67 > 0 )
return F_43 ( - V_30 ) ;
V_8 = F_46 ( V_64 , V_65 ) ;
if ( ! V_8 ) {
V_26 = - V_11 ;
goto V_68;
}
if ( V_8 -> V_69 != - 1 )
F_47 ( & V_8 -> V_9 , L_16 , V_8 -> V_36 , V_8 -> V_69 ) ;
else
F_47 ( & V_8 -> V_9 , L_17 , V_8 -> V_36 ) ;
V_2 = F_15 ( V_8 , V_54 , V_25 ) ;
if ( F_5 ( V_2 ) )
goto V_70;
V_26 = F_48 ( V_8 , V_66 , V_67 ) ;
if ( V_26 )
goto V_71;
V_26 = F_49 ( V_8 ) ;
if ( V_26 )
goto V_71;
return V_8 ;
V_71:
F_23 ( V_2 ) ;
V_70:
F_50 ( V_8 ) ;
V_68:
F_51 ( L_18 , V_64 , V_26 ) ;
return F_43 ( V_26 ) ;
}
static int F_52 ( struct V_72 * V_9 )
{
struct V_19 * V_8 = F_22 ( V_9 ) ;
int V_26 ;
V_26 = F_53 ( V_9 ) ;
if ( V_26 )
return V_26 ;
return F_26 ( V_8 ) ;
}
static int F_54 ( struct V_72 * V_9 )
{
struct V_19 * V_8 = F_22 ( V_9 ) ;
int V_26 ;
V_26 = F_18 ( V_8 ) ;
if ( V_26 ) {
F_8 ( V_9 , L_19 ) ;
return V_26 ;
}
return F_55 ( V_9 ) ;
}
static int F_56 ( struct V_72 * V_9 )
{
F_57 ( V_9 , L_20 , V_63 ) ;
return - V_10 ;
}
static int F_58 ( struct V_72 * V_9 )
{
F_57 ( V_9 , L_20 , V_63 ) ;
return - V_10 ;
}
static int F_59 ( struct V_72 * V_9 )
{
struct V_19 * V_8 = F_22 ( V_9 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_26 ;
if ( V_2 -> V_49 != V_73 )
return 0 ;
V_26 = F_60 ( V_9 ) ;
if ( ! V_26 && ! F_61 ( V_9 ) ) {
if ( F_53 ( V_9 ) == 0 ) {
F_62 ( V_9 ) ;
F_26 ( V_8 ) ;
V_2 -> V_32 |= V_74 ;
}
}
return V_26 ;
}
static int F_63 ( struct V_72 * V_9 )
{
struct V_19 * V_8 = F_22 ( V_9 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
if ( V_2 -> V_32 & V_74 ) {
V_2 -> V_32 &= ~ V_74 ;
F_18 ( V_8 ) ;
F_64 ( F_19 ( V_9 ) ,
L_21 , F_4 ( V_9 ) ) ;
F_55 ( V_9 ) ;
}
return F_65 ( V_9 ) ;
}
int F_49 ( struct V_19 * V_8 )
{
F_36 ( L_22 , V_8 -> V_36 ) ;
F_17 ( & V_8 -> V_9 , & V_37 ) ;
return F_66 ( V_8 ) ;
}
int F_18 ( struct V_19 * V_8 )
{
int V_26 ;
struct V_1 * V_2 ;
V_2 = F_24 ( V_8 ) ;
if ( V_2 -> V_46 == V_47 ) {
F_57 ( & V_8 -> V_9 ,
L_23 ,
V_63 , V_2 -> V_46 ) ;
return - V_30 ;
}
V_26 = F_28 ( V_2 ) ;
if ( V_26 == 0 )
V_2 -> V_46 = V_47 ;
return V_26 ;
}
int F_26 ( struct V_19 * V_8 )
{
int V_26 ;
struct V_1 * V_2 ;
V_2 = F_24 ( V_8 ) ;
if ( V_2 -> V_46 != V_47 ) {
F_57 ( & V_8 -> V_9 ,
L_23 ,
V_63 , V_2 -> V_46 ) ;
return - V_30 ;
}
V_26 = F_30 ( V_2 ) ;
if ( V_26 == 0 )
V_2 -> V_46 = V_75 ;
return V_26 ;
}
int F_67 ( struct V_19 * V_8 , const char * V_36 )
{
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_26 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_51 ; V_14 ++ ) {
V_26 = F_68 ( V_2 -> V_20 [ V_14 ] , V_36 ) ;
if ( V_26 )
break;
}
return V_26 ;
}
int F_69 ( struct V_19 * V_8 ,
const char * V_36 )
{
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_26 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_51 ; V_14 ++ ) {
V_26 = F_70 ( V_2 -> V_20 [ V_14 ] , V_36 ) ;
if ( V_26 )
break;
}
return V_26 ;
}
struct V_72 * F_71 ( const char * V_24 )
{
struct V_12 * V_13 ;
if ( ! V_24 ) {
F_64 ( 1 , L_24 , V_63 ) ;
return F_43 ( - V_30 ) ;
}
V_13 = F_14 ( V_24 ) ;
if ( ! V_13 ) {
F_64 ( 1 , L_25 , V_63 ,
V_24 ) ;
return F_43 ( - V_10 ) ;
}
if ( ! V_13 -> V_2 ) {
F_64 ( 1 , L_26 , V_63 ,
V_24 ) ;
return F_43 ( - V_10 ) ;
}
return & V_13 -> V_2 -> V_8 -> V_9 ;
}
static int T_2 F_72 ( void )
{
F_73 ( & V_76 , & V_77 ) ;
return 0 ;
}
static int T_2 F_74 ( struct V_72 * V_9 , void * V_78 )
{
struct V_19 * V_8 = F_22 ( V_9 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_14 ;
if ( ! V_2 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_51 ; V_14 ++ )
if ( V_2 -> V_20 [ V_14 ] -> V_32 & V_33 )
return 0 ;
if ( V_2 -> V_49 != V_73 &&
V_2 -> V_49 != V_79 ) {
if ( V_2 -> V_46 == V_47 ) {
F_57 ( V_9 , L_27 ,
V_63 ) ;
F_26 ( V_8 ) ;
}
}
return 0 ;
}
static int T_2 F_75 ( void )
{
F_76 ( & V_76 , NULL , NULL , F_74 ) ;
F_64 ( ! F_77 () ,
L_28 ) ;
return 0 ;
}
