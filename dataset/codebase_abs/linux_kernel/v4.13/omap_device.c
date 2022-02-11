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
if ( F_5 ( V_6 ) ) {
struct V_10 V_11 ;
V_11 . V_12 = F_7 ( NULL , V_4 ) ;
V_6 = F_8 ( & V_11 ) ;
V_7 = F_9 ( V_6 , V_3 ,
F_4 ( & V_2 -> V_8 -> V_9 ) ) ;
} else {
V_7 = F_10 ( V_3 , F_4 ( & V_2 -> V_8 -> V_9 ) ,
V_4 , NULL ) ;
}
if ( V_7 ) {
if ( V_7 == - V_13 || V_7 == - V_14 )
F_11 ( & V_2 -> V_8 -> V_9 ,
L_3 , V_3 ) ;
else
F_11 ( & V_2 -> V_8 -> V_9 ,
L_4 , V_4 ) ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_17 ;
F_1 ( V_2 , L_5 , V_16 -> V_18 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_19 ; V_17 ++ )
F_1 ( V_2 , V_16 -> V_20 [ V_17 ] . V_21 , V_16 -> V_20 [ V_17 ] . V_5 ) ;
}
static int F_13 ( struct V_22 * V_8 )
{
struct V_15 * * V_23 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_24 * V_25 = V_8 -> V_9 . V_26 ;
const char * V_27 ;
int V_28 , V_17 , V_29 = 0 ;
bool V_30 = false ;
V_28 = F_14 ( V_25 , L_6 ) ;
if ( V_28 <= 0 ) {
F_2 ( & V_8 -> V_9 , L_7 ) ;
return - V_13 ;
}
V_23 = F_15 ( sizeof( struct V_15 * ) * V_28 , V_31 ) ;
if ( ! V_23 ) {
V_29 = - V_14 ;
goto V_32;
}
for ( V_17 = 0 ; V_17 < V_28 ; V_17 ++ ) {
F_16 ( V_25 , L_6 , V_17 , & V_27 ) ;
V_16 = F_17 ( V_27 ) ;
if ( ! V_16 ) {
F_11 ( & V_8 -> V_9 , L_8 ,
V_27 ) ;
V_29 = - V_33 ;
goto V_34;
}
V_23 [ V_17 ] = V_16 ;
if ( V_16 -> V_35 & V_36 )
V_30 = true ;
}
V_2 = F_18 ( V_8 , V_23 , V_28 ) ;
if ( F_5 ( V_2 ) ) {
F_11 ( & V_8 -> V_9 , L_9 ,
V_27 ) ;
V_29 = F_19 ( V_2 ) ;
goto V_34;
}
for ( V_17 = 0 ; V_17 < V_8 -> V_37 ; V_17 ++ ) {
struct V_38 * V_6 = & V_8 -> V_38 [ V_17 ] ;
if ( V_6 -> V_39 == NULL )
V_6 -> V_39 = F_4 ( & V_8 -> V_9 ) ;
}
F_20 ( & V_8 -> V_9 , & V_40 ) ;
if ( V_30 ) {
F_21 ( V_8 ) ;
F_22 ( & V_8 -> V_9 ) ;
}
V_34:
F_23 ( V_23 ) ;
V_32:
if ( V_29 )
F_20 ( & V_8 -> V_9 , & V_41 ) ;
return V_29 ;
}
static int F_24 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_9 )
{
struct V_22 * V_8 = F_25 ( V_9 ) ;
struct V_1 * V_2 ;
int V_45 ;
switch ( V_44 ) {
case V_46 :
if ( V_8 -> V_47 . V_2 )
F_26 ( V_8 -> V_47 . V_2 ) ;
break;
case V_48 :
V_2 = F_27 ( V_8 ) ;
if ( V_2 && ( V_2 -> V_49 == V_50 ) ) {
F_28 ( V_9 , L_10 ) ;
V_45 = F_29 ( V_8 ) ;
if ( V_45 )
F_11 ( V_9 , L_11 ) ;
}
break;
case V_51 :
V_2 = F_27 ( V_8 ) ;
if ( V_2 && ( V_2 -> V_49 == V_50 ) &&
F_30 ( V_9 ) ) {
V_2 -> V_52 = V_51 ;
F_22 ( V_9 ) ;
}
break;
case V_53 :
if ( V_8 -> V_9 . V_26 )
F_13 ( V_8 ) ;
F_31 ( V_9 ) ;
default:
V_2 = F_27 ( V_8 ) ;
if ( V_2 )
V_2 -> V_52 = V_44 ;
}
return V_54 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_55 ; V_17 ++ )
V_29 |= F_33 ( V_2 -> V_23 [ V_17 ] ) ;
return V_29 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_55 ; V_17 ++ )
V_29 |= F_35 ( V_2 -> V_23 [ V_17 ] ) ;
return V_29 ;
}
int F_36 ( struct V_22 * V_8 )
{
struct V_1 * V_2 ;
T_1 V_29 = 0 ;
V_2 = F_27 ( V_8 ) ;
if ( V_2 -> V_55 )
V_29 = F_37 ( V_2 -> V_23 [ 0 ] ) ;
return V_29 ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned long V_35 )
{
int V_56 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_55 ; V_17 ++ )
V_56 += F_39 ( V_2 -> V_23 [ V_17 ] , V_35 ) ;
F_40 ( L_12 ,
V_2 -> V_8 -> V_39 , V_56 , V_2 -> V_55 ) ;
return V_56 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_38 * V_57 )
{
int V_17 , V_6 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_55 ; V_17 ++ ) {
V_6 = F_42 ( V_2 -> V_23 [ V_17 ] , V_57 ) ;
V_57 += V_6 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_38 * V_57 )
{
int V_17 , V_6 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_55 ; V_17 ++ ) {
V_6 = F_44 ( V_2 -> V_23 [ V_17 ] , V_57 ) ;
V_57 += V_6 ;
}
return 0 ;
}
struct V_1 * F_18 ( struct V_22 * V_8 ,
struct V_15 * * V_58 , int V_28 )
{
int V_29 = - V_14 ;
struct V_1 * V_2 ;
struct V_38 * V_57 = NULL ;
int V_17 , V_59 ;
struct V_15 * * V_23 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_31 ) ;
if ( ! V_2 ) {
V_29 = - V_14 ;
goto V_60;
}
V_2 -> V_55 = V_28 ;
V_23 = F_45 ( V_58 , sizeof( struct V_15 * ) * V_28 , V_31 ) ;
if ( ! V_23 )
goto V_61;
V_2 -> V_23 = V_23 ;
V_2 -> V_8 = V_8 ;
if ( ! V_8 -> V_37 ) {
V_59 = F_38 ( V_2 , V_62 |
V_63 |
V_64 ) ;
} else {
for ( V_17 = 0 ; V_17 < V_8 -> V_37 ; V_17 ++ ) {
struct V_38 * V_6 = & V_8 -> V_38 [ V_17 ] ;
if ( V_6 -> V_35 == V_63 )
goto V_65;
}
V_59 = F_38 ( V_2 , V_63 ) ;
if ( ! V_59 )
goto V_65;
V_59 += V_8 -> V_37 ;
}
V_57 = F_15 ( sizeof( struct V_38 ) * V_59 , V_31 ) ;
if ( ! V_57 )
goto V_66;
if ( ! V_8 -> V_37 ) {
F_2 ( & V_8 -> V_9 , L_13 ,
V_67 , V_59 ) ;
F_41 ( V_2 , V_57 ) ;
} else {
F_2 ( & V_8 -> V_9 ,
L_14 ,
V_67 , V_59 - V_8 -> V_37 ) ;
memcpy ( V_57 , V_8 -> V_38 ,
sizeof( struct V_38 ) * V_8 -> V_37 ) ;
F_43 ( V_2 , & V_57 [ V_8 -> V_37 ] ) ;
}
V_29 = F_46 ( V_8 , V_57 , V_59 ) ;
F_23 ( V_57 ) ;
if ( V_29 )
goto V_66;
V_65:
V_8 -> V_47 . V_2 = V_2 ;
for ( V_17 = 0 ; V_17 < V_28 ; V_17 ++ ) {
V_23 [ V_17 ] -> V_2 = V_2 ;
F_12 ( V_2 , V_23 [ V_17 ] ) ;
}
return V_2 ;
V_66:
F_23 ( V_23 ) ;
V_61:
F_23 ( V_2 ) ;
V_60:
F_11 ( & V_8 -> V_9 , L_15 , V_29 ) ;
return F_47 ( V_29 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_8 -> V_47 . V_2 = NULL ;
F_23 ( V_2 -> V_23 ) ;
F_23 ( V_2 ) ;
}
struct V_22 T_2 * F_48 ( const char * V_68 ,
int V_69 ,
struct V_15 * V_16 ,
void * V_70 , int V_71 )
{
struct V_15 * V_58 [] = { V_16 } ;
if ( ! V_16 )
return F_47 ( - V_33 ) ;
return F_49 ( V_68 , V_69 , V_58 , 1 , V_70 ,
V_71 ) ;
}
struct V_22 T_2 * F_49 ( const char * V_68 ,
int V_69 ,
struct V_15 * * V_58 ,
int V_28 , void * V_70 ,
int V_71 )
{
int V_29 = - V_14 ;
struct V_22 * V_8 ;
struct V_1 * V_2 ;
if ( ! V_58 || V_28 == 0 || ! V_68 )
return F_47 ( - V_33 ) ;
if ( ! V_70 && V_71 > 0 )
return F_47 ( - V_33 ) ;
V_8 = F_50 ( V_68 , V_69 ) ;
if ( ! V_8 ) {
V_29 = - V_14 ;
goto V_72;
}
if ( V_8 -> V_73 != - 1 )
F_51 ( & V_8 -> V_9 , L_16 , V_8 -> V_39 , V_8 -> V_73 ) ;
else
F_51 ( & V_8 -> V_9 , L_17 , V_8 -> V_39 ) ;
V_2 = F_18 ( V_8 , V_58 , V_28 ) ;
if ( F_5 ( V_2 ) )
goto V_74;
V_29 = F_52 ( V_8 , V_70 , V_71 ) ;
if ( V_29 )
goto V_75;
V_29 = F_53 ( V_8 ) ;
if ( V_29 )
goto V_75;
return V_8 ;
V_75:
F_26 ( V_2 ) ;
V_74:
F_54 ( V_8 ) ;
V_72:
F_55 ( L_18 , V_68 , V_29 ) ;
return F_47 ( V_29 ) ;
}
static int F_56 ( struct V_76 * V_9 )
{
struct V_22 * V_8 = F_25 ( V_9 ) ;
int V_29 ;
V_29 = F_57 ( V_9 ) ;
if ( V_29 )
return V_29 ;
return F_29 ( V_8 ) ;
}
static int F_58 ( struct V_76 * V_9 )
{
struct V_22 * V_8 = F_25 ( V_9 ) ;
int V_29 ;
V_29 = F_21 ( V_8 ) ;
if ( V_29 ) {
F_11 ( V_9 , L_19 ) ;
return V_29 ;
}
return F_59 ( V_9 ) ;
}
static int F_60 ( struct V_76 * V_9 )
{
F_61 ( V_9 , L_20 , V_67 ) ;
return - V_13 ;
}
static int F_62 ( struct V_76 * V_9 )
{
F_61 ( V_9 , L_20 , V_67 ) ;
return - V_13 ;
}
static int F_63 ( struct V_76 * V_9 )
{
struct V_22 * V_8 = F_25 ( V_9 ) ;
struct V_1 * V_2 = F_27 ( V_8 ) ;
int V_29 ;
if ( V_2 -> V_52 != V_77 )
return 0 ;
V_29 = F_64 ( V_9 ) ;
if ( ! V_29 && ! F_30 ( V_9 ) ) {
if ( F_57 ( V_9 ) == 0 ) {
F_65 ( V_9 ) ;
F_29 ( V_8 ) ;
V_2 -> V_35 |= V_78 ;
}
}
return V_29 ;
}
static int F_66 ( struct V_76 * V_9 )
{
struct V_22 * V_8 = F_25 ( V_9 ) ;
struct V_1 * V_2 = F_27 ( V_8 ) ;
if ( V_2 -> V_35 & V_78 ) {
V_2 -> V_35 &= ~ V_78 ;
F_21 ( V_8 ) ;
F_67 ( F_22 ( V_9 ) ,
L_21 , F_4 ( V_9 ) ) ;
F_59 ( V_9 ) ;
}
return F_68 ( V_9 ) ;
}
int F_53 ( struct V_22 * V_8 )
{
F_40 ( L_22 , V_8 -> V_39 ) ;
F_20 ( & V_8 -> V_9 , & V_40 ) ;
return F_69 ( V_8 ) ;
}
int F_21 ( struct V_22 * V_8 )
{
int V_29 ;
struct V_1 * V_2 ;
V_2 = F_27 ( V_8 ) ;
if ( V_2 -> V_49 == V_50 ) {
F_61 ( & V_8 -> V_9 ,
L_23 ,
V_67 , V_2 -> V_49 ) ;
return - V_33 ;
}
V_29 = F_32 ( V_2 ) ;
if ( V_29 == 0 )
V_2 -> V_49 = V_50 ;
return V_29 ;
}
int F_29 ( struct V_22 * V_8 )
{
int V_29 ;
struct V_1 * V_2 ;
V_2 = F_27 ( V_8 ) ;
if ( V_2 -> V_49 != V_50 ) {
F_61 ( & V_8 -> V_9 ,
L_23 ,
V_67 , V_2 -> V_49 ) ;
return - V_33 ;
}
V_29 = F_34 ( V_2 ) ;
if ( V_29 == 0 )
V_2 -> V_49 = V_79 ;
return V_29 ;
}
int F_70 ( struct V_22 * V_8 , const char * V_39 )
{
struct V_1 * V_2 = F_27 ( V_8 ) ;
int V_29 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_55 ; V_17 ++ ) {
V_29 = F_71 ( V_2 -> V_23 [ V_17 ] , V_39 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
int F_72 ( struct V_22 * V_8 ,
const char * V_39 )
{
struct V_1 * V_2 = F_27 ( V_8 ) ;
int V_29 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_55 ; V_17 ++ ) {
V_29 = F_73 ( V_2 -> V_23 [ V_17 ] , V_39 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
struct V_76 * F_74 ( const char * V_27 )
{
struct V_15 * V_16 ;
if ( ! V_27 ) {
F_67 ( 1 , L_24 , V_67 ) ;
return F_47 ( - V_33 ) ;
}
V_16 = F_17 ( V_27 ) ;
if ( ! V_16 ) {
F_67 ( 1 , L_25 , V_67 ,
V_27 ) ;
return F_47 ( - V_13 ) ;
}
if ( ! V_16 -> V_2 ) {
F_67 ( 1 , L_26 , V_67 ,
V_27 ) ;
return F_47 ( - V_13 ) ;
}
return & V_16 -> V_2 -> V_8 -> V_9 ;
}
static int T_2 F_75 ( void )
{
F_76 ( & V_80 , & V_81 ) ;
return 0 ;
}
static int T_2 F_77 ( struct V_76 * V_9 , void * V_82 )
{
struct V_22 * V_8 = F_25 ( V_9 ) ;
struct V_1 * V_2 = F_27 ( V_8 ) ;
int V_17 ;
if ( ! V_2 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_55 ; V_17 ++ )
if ( V_2 -> V_23 [ V_17 ] -> V_35 & V_36 )
return 0 ;
if ( V_2 -> V_52 != V_77 &&
V_2 -> V_52 != V_51 ) {
if ( V_2 -> V_49 == V_50 ) {
F_61 ( V_9 , L_27 ,
V_67 ) ;
F_29 ( V_8 ) ;
}
}
return 0 ;
}
static int T_2 F_78 ( void )
{
F_79 ( & V_80 , NULL , NULL , F_77 ) ;
return 0 ;
}
