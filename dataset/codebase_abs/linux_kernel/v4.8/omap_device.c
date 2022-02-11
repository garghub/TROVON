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
V_6 = F_3 ( NULL , V_4 ) ;
if ( F_5 ( V_6 ) && F_7 () ) {
struct V_10 V_11 ;
V_11 . V_12 = F_8 ( NULL , V_4 ) ;
V_6 = F_9 ( & V_11 ) ;
V_7 = F_10 ( V_6 , V_3 ,
F_4 ( & V_2 -> V_8 -> V_9 ) ) ;
} else {
V_7 = F_11 ( V_3 , F_4 ( & V_2 -> V_8 -> V_9 ) ,
V_4 , NULL ) ;
}
if ( V_7 ) {
if ( V_7 == - V_13 || V_7 == - V_14 )
F_12 ( & V_2 -> V_8 -> V_9 ,
L_3 , V_3 ) ;
else
F_12 ( & V_2 -> V_8 -> V_9 ,
L_4 , V_4 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_17 ;
F_1 ( V_2 , L_5 , V_16 -> V_18 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_19 ; V_17 ++ )
F_1 ( V_2 , V_16 -> V_20 [ V_17 ] . V_21 , V_16 -> V_20 [ V_17 ] . V_5 ) ;
}
static int F_14 ( struct V_22 * V_8 )
{
struct V_15 * * V_23 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_24 * V_25 = V_8 -> V_9 . V_26 ;
const char * V_27 ;
int V_28 , V_17 , V_29 = 0 ;
bool V_30 = false ;
V_28 = F_15 ( V_25 , L_6 ) ;
if ( V_28 <= 0 ) {
F_2 ( & V_8 -> V_9 , L_7 ) ;
return - V_13 ;
}
V_23 = F_16 ( sizeof( struct V_15 * ) * V_28 , V_31 ) ;
if ( ! V_23 ) {
V_29 = - V_14 ;
goto V_32;
}
for ( V_17 = 0 ; V_17 < V_28 ; V_17 ++ ) {
F_17 ( V_25 , L_6 , V_17 , & V_27 ) ;
V_16 = F_18 ( V_27 ) ;
if ( ! V_16 ) {
F_12 ( & V_8 -> V_9 , L_8 ,
V_27 ) ;
V_29 = - V_33 ;
goto V_34;
}
V_23 [ V_17 ] = V_16 ;
if ( V_16 -> V_35 & V_36 )
V_30 = true ;
}
V_2 = F_19 ( V_8 , V_23 , V_28 ) ;
if ( F_5 ( V_2 ) ) {
F_12 ( & V_8 -> V_9 , L_9 ,
V_27 ) ;
V_29 = F_20 ( V_2 ) ;
goto V_34;
}
for ( V_17 = 0 ; V_17 < V_8 -> V_37 ; V_17 ++ ) {
struct V_38 * V_6 = & V_8 -> V_38 [ V_17 ] ;
if ( V_6 -> V_39 == NULL )
V_6 -> V_39 = F_4 ( & V_8 -> V_9 ) ;
}
F_21 ( & V_8 -> V_9 , & V_40 ) ;
if ( V_30 ) {
F_22 ( V_8 ) ;
F_23 ( & V_8 -> V_9 ) ;
}
V_34:
F_24 ( V_23 ) ;
V_32:
if ( V_29 )
F_21 ( & V_8 -> V_9 , & V_41 ) ;
return V_29 ;
}
static int F_25 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_9 )
{
struct V_22 * V_8 = F_26 ( V_9 ) ;
struct V_1 * V_2 ;
int V_45 ;
switch ( V_44 ) {
case V_46 :
if ( V_8 -> V_47 . V_2 )
F_27 ( V_8 -> V_47 . V_2 ) ;
break;
case V_48 :
V_2 = F_28 ( V_8 ) ;
if ( V_2 && ( V_2 -> V_49 == V_50 ) ) {
F_29 ( V_9 , L_10 ) ;
V_45 = F_30 ( V_8 ) ;
if ( V_45 )
F_12 ( V_9 , L_11 ) ;
}
break;
case V_51 :
if ( V_8 -> V_9 . V_26 )
F_14 ( V_8 ) ;
F_31 ( V_9 ) ;
default:
V_2 = F_28 ( V_8 ) ;
if ( V_2 )
V_2 -> V_52 = V_44 ;
}
return V_53 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ )
V_29 |= F_33 ( V_2 -> V_23 [ V_17 ] ) ;
return V_29 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ )
V_29 |= F_35 ( V_2 -> V_23 [ V_17 ] ) ;
return V_29 ;
}
int F_36 ( struct V_22 * V_8 )
{
struct V_1 * V_2 ;
T_1 V_29 = 0 ;
V_2 = F_28 ( V_8 ) ;
if ( V_2 -> V_54 )
V_29 = F_37 ( V_2 -> V_23 [ 0 ] ) ;
return V_29 ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned long V_35 )
{
int V_55 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ )
V_55 += F_39 ( V_2 -> V_23 [ V_17 ] , V_35 ) ;
F_40 ( L_12 ,
V_2 -> V_8 -> V_39 , V_55 , V_2 -> V_54 ) ;
return V_55 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_38 * V_56 )
{
int V_17 , V_6 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ ) {
V_6 = F_42 ( V_2 -> V_23 [ V_17 ] , V_56 ) ;
V_56 += V_6 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_38 * V_56 )
{
int V_17 , V_6 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ ) {
V_6 = F_44 ( V_2 -> V_23 [ V_17 ] , V_56 ) ;
V_56 += V_6 ;
}
return 0 ;
}
struct V_1 * F_19 ( struct V_22 * V_8 ,
struct V_15 * * V_57 , int V_28 )
{
int V_29 = - V_14 ;
struct V_1 * V_2 ;
struct V_38 * V_56 = NULL ;
int V_17 , V_58 ;
struct V_15 * * V_23 ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_31 ) ;
if ( ! V_2 ) {
V_29 = - V_14 ;
goto V_59;
}
V_2 -> V_54 = V_28 ;
V_23 = F_45 ( V_57 , sizeof( struct V_15 * ) * V_28 , V_31 ) ;
if ( ! V_23 )
goto V_60;
V_2 -> V_23 = V_23 ;
V_2 -> V_8 = V_8 ;
if ( ! V_8 -> V_37 ) {
V_58 = F_38 ( V_2 , V_61 |
V_62 |
V_63 ) ;
} else {
for ( V_17 = 0 ; V_17 < V_8 -> V_37 ; V_17 ++ ) {
struct V_38 * V_6 = & V_8 -> V_38 [ V_17 ] ;
if ( V_6 -> V_35 == V_62 )
goto V_64;
}
V_58 = F_38 ( V_2 , V_62 ) ;
if ( ! V_58 )
goto V_64;
V_58 += V_8 -> V_37 ;
}
V_56 = F_16 ( sizeof( struct V_38 ) * V_58 , V_31 ) ;
if ( ! V_56 )
goto V_65;
if ( ! V_8 -> V_37 ) {
F_2 ( & V_8 -> V_9 , L_13 ,
V_66 , V_58 ) ;
F_41 ( V_2 , V_56 ) ;
} else {
F_2 ( & V_8 -> V_9 ,
L_14 ,
V_66 , V_58 - V_8 -> V_37 ) ;
memcpy ( V_56 , V_8 -> V_38 ,
sizeof( struct V_38 ) * V_8 -> V_37 ) ;
F_43 ( V_2 , & V_56 [ V_8 -> V_37 ] ) ;
}
V_29 = F_46 ( V_8 , V_56 , V_58 ) ;
F_24 ( V_56 ) ;
if ( V_29 )
goto V_65;
V_64:
V_8 -> V_47 . V_2 = V_2 ;
for ( V_17 = 0 ; V_17 < V_28 ; V_17 ++ ) {
V_23 [ V_17 ] -> V_2 = V_2 ;
F_13 ( V_2 , V_23 [ V_17 ] ) ;
}
return V_2 ;
V_65:
F_24 ( V_23 ) ;
V_60:
F_24 ( V_2 ) ;
V_59:
F_12 ( & V_8 -> V_9 , L_15 , V_29 ) ;
return F_47 ( V_29 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_8 -> V_47 . V_2 = NULL ;
F_24 ( V_2 -> V_23 ) ;
F_24 ( V_2 ) ;
}
struct V_22 T_2 * F_48 ( const char * V_67 ,
int V_68 ,
struct V_15 * V_16 ,
void * V_69 , int V_70 )
{
struct V_15 * V_57 [] = { V_16 } ;
if ( ! V_16 )
return F_47 ( - V_33 ) ;
return F_49 ( V_67 , V_68 , V_57 , 1 , V_69 ,
V_70 ) ;
}
struct V_22 T_2 * F_49 ( const char * V_67 ,
int V_68 ,
struct V_15 * * V_57 ,
int V_28 , void * V_69 ,
int V_70 )
{
int V_29 = - V_14 ;
struct V_22 * V_8 ;
struct V_1 * V_2 ;
if ( ! V_57 || V_28 == 0 || ! V_67 )
return F_47 ( - V_33 ) ;
if ( ! V_69 && V_70 > 0 )
return F_47 ( - V_33 ) ;
V_8 = F_50 ( V_67 , V_68 ) ;
if ( ! V_8 ) {
V_29 = - V_14 ;
goto V_71;
}
if ( V_8 -> V_72 != - 1 )
F_51 ( & V_8 -> V_9 , L_16 , V_8 -> V_39 , V_8 -> V_72 ) ;
else
F_51 ( & V_8 -> V_9 , L_17 , V_8 -> V_39 ) ;
V_2 = F_19 ( V_8 , V_57 , V_28 ) ;
if ( F_5 ( V_2 ) )
goto V_73;
V_29 = F_52 ( V_8 , V_69 , V_70 ) ;
if ( V_29 )
goto V_74;
V_29 = F_53 ( V_8 ) ;
if ( V_29 )
goto V_74;
return V_8 ;
V_74:
F_27 ( V_2 ) ;
V_73:
F_54 ( V_8 ) ;
V_71:
F_55 ( L_18 , V_67 , V_29 ) ;
return F_47 ( V_29 ) ;
}
static int F_56 ( struct V_75 * V_9 )
{
struct V_22 * V_8 = F_26 ( V_9 ) ;
int V_29 ;
V_29 = F_57 ( V_9 ) ;
if ( V_29 )
return V_29 ;
return F_30 ( V_8 ) ;
}
static int F_58 ( struct V_75 * V_9 )
{
struct V_22 * V_8 = F_26 ( V_9 ) ;
int V_29 ;
V_29 = F_22 ( V_8 ) ;
if ( V_29 ) {
F_12 ( V_9 , L_19 ) ;
return V_29 ;
}
return F_59 ( V_9 ) ;
}
static int F_60 ( struct V_75 * V_9 )
{
F_61 ( V_9 , L_20 , V_66 ) ;
return - V_13 ;
}
static int F_62 ( struct V_75 * V_9 )
{
F_61 ( V_9 , L_20 , V_66 ) ;
return - V_13 ;
}
static int F_63 ( struct V_75 * V_9 )
{
struct V_22 * V_8 = F_26 ( V_9 ) ;
struct V_1 * V_2 = F_28 ( V_8 ) ;
int V_29 ;
if ( V_2 -> V_52 != V_76 )
return 0 ;
V_29 = F_64 ( V_9 ) ;
if ( ! V_29 && ! F_65 ( V_9 ) ) {
if ( F_57 ( V_9 ) == 0 ) {
F_66 ( V_9 ) ;
F_30 ( V_8 ) ;
V_2 -> V_35 |= V_77 ;
}
}
return V_29 ;
}
static int F_67 ( struct V_75 * V_9 )
{
struct V_22 * V_8 = F_26 ( V_9 ) ;
struct V_1 * V_2 = F_28 ( V_8 ) ;
if ( V_2 -> V_35 & V_77 ) {
V_2 -> V_35 &= ~ V_77 ;
F_22 ( V_8 ) ;
F_68 ( F_23 ( V_9 ) ,
L_21 , F_4 ( V_9 ) ) ;
F_59 ( V_9 ) ;
}
return F_69 ( V_9 ) ;
}
int F_53 ( struct V_22 * V_8 )
{
F_40 ( L_22 , V_8 -> V_39 ) ;
F_21 ( & V_8 -> V_9 , & V_40 ) ;
return F_70 ( V_8 ) ;
}
int F_22 ( struct V_22 * V_8 )
{
int V_29 ;
struct V_1 * V_2 ;
V_2 = F_28 ( V_8 ) ;
if ( V_2 -> V_49 == V_50 ) {
F_61 ( & V_8 -> V_9 ,
L_23 ,
V_66 , V_2 -> V_49 ) ;
return - V_33 ;
}
V_29 = F_32 ( V_2 ) ;
if ( V_29 == 0 )
V_2 -> V_49 = V_50 ;
return V_29 ;
}
int F_30 ( struct V_22 * V_8 )
{
int V_29 ;
struct V_1 * V_2 ;
V_2 = F_28 ( V_8 ) ;
if ( V_2 -> V_49 != V_50 ) {
F_61 ( & V_8 -> V_9 ,
L_23 ,
V_66 , V_2 -> V_49 ) ;
return - V_33 ;
}
V_29 = F_34 ( V_2 ) ;
if ( V_29 == 0 )
V_2 -> V_49 = V_78 ;
return V_29 ;
}
int F_71 ( struct V_22 * V_8 , const char * V_39 )
{
struct V_1 * V_2 = F_28 ( V_8 ) ;
int V_29 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ ) {
V_29 = F_72 ( V_2 -> V_23 [ V_17 ] , V_39 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
int F_73 ( struct V_22 * V_8 ,
const char * V_39 )
{
struct V_1 * V_2 = F_28 ( V_8 ) ;
int V_29 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ ) {
V_29 = F_74 ( V_2 -> V_23 [ V_17 ] , V_39 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
struct V_75 * F_75 ( const char * V_27 )
{
struct V_15 * V_16 ;
if ( ! V_27 ) {
F_68 ( 1 , L_24 , V_66 ) ;
return F_47 ( - V_33 ) ;
}
V_16 = F_18 ( V_27 ) ;
if ( ! V_16 ) {
F_68 ( 1 , L_25 , V_66 ,
V_27 ) ;
return F_47 ( - V_13 ) ;
}
if ( ! V_16 -> V_2 ) {
F_68 ( 1 , L_26 , V_66 ,
V_27 ) ;
return F_47 ( - V_13 ) ;
}
return & V_16 -> V_2 -> V_8 -> V_9 ;
}
static int T_2 F_76 ( void )
{
F_77 ( & V_79 , & V_80 ) ;
return 0 ;
}
static int T_2 F_78 ( struct V_75 * V_9 , void * V_81 )
{
struct V_22 * V_8 = F_26 ( V_9 ) ;
struct V_1 * V_2 = F_28 ( V_8 ) ;
int V_17 ;
if ( ! V_2 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ )
if ( V_2 -> V_23 [ V_17 ] -> V_35 & V_36 )
return 0 ;
if ( V_2 -> V_52 != V_76 &&
V_2 -> V_52 != V_82 ) {
if ( V_2 -> V_49 == V_50 ) {
F_61 ( V_9 , L_27 ,
V_66 ) ;
F_30 ( V_8 ) ;
}
}
return 0 ;
}
static int T_2 F_79 ( void )
{
F_80 ( & V_79 , NULL , NULL , F_78 ) ;
F_68 ( ! F_7 () ,
L_28 ) ;
return 0 ;
}
