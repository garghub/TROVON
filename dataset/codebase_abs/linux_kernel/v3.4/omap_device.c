static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 , V_6 , V_7 ;
F_2 ( & V_2 -> V_8 -> V_9 , L_1 ) ;
while ( V_2 -> V_10 > 0 ) {
struct V_11 * V_12 ;
unsigned long long V_13 = 0 ;
V_2 -> V_10 -- ;
V_12 = V_2 -> V_14 + V_2 -> V_10 ;
if ( ! V_3 &&
( V_2 -> V_15 <= V_2 -> V_16 ) )
break;
F_3 ( & V_5 ) ;
V_12 -> V_17 ( V_2 ) ;
F_3 ( & V_6 ) ;
V_7 = F_4 ( V_6 , V_5 ) ;
V_13 = F_5 ( & V_7 ) ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_2
L_3 , V_2 -> V_10 , V_13 ) ;
if ( V_13 > V_12 -> V_18 ) {
V_12 -> V_19 = V_13 ;
if ( V_12 -> V_20 & V_21 ) {
V_12 -> V_18 = V_13 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_4
L_5 ,
V_2 -> V_10 , V_13 ) ;
} else
F_6 ( & V_2 -> V_8 -> V_9 ,
L_6
L_7 ,
V_2 -> V_10 , V_13 ,
V_12 -> V_18 ) ;
}
V_2 -> V_15 -= V_12 -> V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 , V_6 , V_7 ;
F_2 ( & V_2 -> V_8 -> V_9 , L_8 ) ;
while ( V_2 -> V_10 < V_2 -> V_22 ) {
struct V_11 * V_12 ;
unsigned long long V_23 = 0 ;
V_12 = V_2 -> V_14 + V_2 -> V_10 ;
if ( ! V_3 &&
( ( V_2 -> V_15 + V_12 -> V_18 ) >
V_2 -> V_16 ) )
break;
F_3 ( & V_5 ) ;
V_12 -> V_24 ( V_2 ) ;
F_3 ( & V_6 ) ;
V_7 = F_4 ( V_6 , V_5 ) ;
V_23 = F_5 ( & V_7 ) ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_9
L_3 , V_2 -> V_10 , V_23 ) ;
if ( V_23 > V_12 -> V_25 ) {
V_12 -> V_26 = V_23 ;
if ( V_12 -> V_20 & V_21 ) {
V_12 -> V_25 = V_23 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_10
L_5 ,
V_2 -> V_10 , V_23 ) ;
} else
F_6 ( & V_2 -> V_8 -> V_9 ,
L_11
L_7 ,
V_2 -> V_10 , V_23 ,
V_12 -> V_25 ) ;
}
V_2 -> V_15 += V_12 -> V_18 ;
V_2 -> V_10 ++ ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , const char * V_27 ,
const char * V_28 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
if ( ! V_27 || ! V_28 )
return;
F_2 ( & V_2 -> V_8 -> V_9 , L_12 , V_27 , V_28 ) ;
V_30 = F_9 ( F_10 ( & V_2 -> V_8 -> V_9 ) , V_27 ) ;
if ( ! F_11 ( V_30 ) ) {
F_6 ( & V_2 -> V_8 -> V_9 ,
L_13 , V_27 ) ;
F_12 ( V_30 ) ;
return;
}
V_30 = F_13 ( V_28 ) ;
if ( F_11 ( V_30 ) ) {
F_14 ( & V_2 -> V_8 -> V_9 ,
L_14 , V_28 ) ;
return;
}
V_32 = F_15 ( V_30 , V_27 , F_10 ( & V_2 -> V_8 -> V_9 ) ) ;
if ( ! V_32 ) {
F_14 ( & V_2 -> V_8 -> V_9 ,
L_15 , V_27 ) ;
return;
}
F_16 ( V_32 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_35 ;
F_8 ( V_2 , L_16 , V_34 -> V_36 ) ;
for ( V_35 = 0 ; V_35 < V_34 -> V_37 ; V_35 ++ )
F_8 ( V_2 , V_34 -> V_38 [ V_35 ] . V_39 , V_34 -> V_38 [ V_35 ] . V_29 ) ;
}
static int F_18 ( struct V_40 * V_8 )
{
struct V_33 * * V_41 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
struct V_42 * V_43 = V_8 -> V_9 . V_44 ;
const char * V_45 ;
int V_46 , V_35 , V_47 = 0 ;
V_46 = F_19 ( V_43 , L_17 ) ;
if ( ! V_46 || F_20 ( V_46 ) ) {
F_2 ( & V_8 -> V_9 , L_18 ) ;
return - V_48 ;
}
V_41 = F_21 ( sizeof( struct V_33 * ) * V_46 , V_49 ) ;
if ( ! V_41 ) {
V_47 = - V_50 ;
goto V_51;
}
for ( V_35 = 0 ; V_35 < V_46 ; V_35 ++ ) {
F_22 ( V_43 , L_17 , V_35 , & V_45 ) ;
V_34 = F_23 ( V_45 ) ;
if ( ! V_34 ) {
F_14 ( & V_8 -> V_9 , L_19 ,
V_45 ) ;
V_47 = - V_52 ;
goto V_53;
}
V_41 [ V_35 ] = V_34 ;
}
V_2 = F_24 ( V_8 , V_41 , V_46 , NULL , 0 ) ;
if ( ! V_2 ) {
F_14 ( & V_8 -> V_9 , L_20 ,
V_45 ) ;
V_47 = F_25 ( V_2 ) ;
goto V_53;
}
if ( F_26 ( V_43 , L_21 , NULL ) )
F_27 ( V_8 ) ;
V_8 -> V_9 . V_54 = & V_55 ;
V_53:
F_28 ( V_41 ) ;
V_51:
return V_47 ;
}
static int F_29 ( struct V_56 * V_57 ,
unsigned long V_58 , void * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
switch ( V_58 ) {
case V_59 :
if ( V_8 -> V_9 . V_44 )
F_18 ( V_8 ) ;
break;
case V_60 :
if ( V_8 -> V_61 . V_2 )
F_31 ( V_8 -> V_61 . V_2 ) ;
break;
}
return V_62 ;
}
int F_32 ( struct V_40 * V_8 )
{
struct V_1 * V_2 ;
T_2 V_47 = 0 ;
V_2 = F_33 ( V_8 ) ;
if ( V_2 -> V_63 )
V_47 = F_34 ( V_2 -> V_41 [ 0 ] ) ;
return V_47 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_63 ; V_35 ++ )
V_7 += F_36 ( V_2 -> V_41 [ V_35 ] ) ;
F_37 ( L_22
L_23 , V_2 -> V_8 -> V_64 , V_7 , V_2 -> V_63 ) ;
return V_7 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
int V_7 = 0 ;
int V_35 , V_30 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_63 ; V_35 ++ ) {
V_30 = F_39 ( V_2 -> V_41 [ V_35 ] , V_66 ) ;
V_66 += V_30 ;
V_7 += V_30 ;
}
return 0 ;
}
struct V_1 * F_24 ( struct V_40 * V_8 ,
struct V_33 * * V_67 , int V_46 ,
struct V_11 * V_14 ,
int V_22 )
{
int V_47 = - V_50 ;
struct V_1 * V_2 ;
struct V_65 * V_66 = NULL ;
int V_35 , V_68 ;
struct V_33 * * V_41 ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_49 ) ;
if ( ! V_2 ) {
V_47 = - V_50 ;
goto V_69;
}
V_2 -> V_63 = V_46 ;
V_41 = F_40 ( V_67 , sizeof( struct V_33 * ) * V_46 , V_49 ) ;
if ( ! V_41 )
goto V_70;
V_2 -> V_41 = V_41 ;
V_2 -> V_8 = V_8 ;
if ( V_8 -> V_71 && V_8 -> V_65 )
F_6 ( & V_8 -> V_9 , L_24 ,
V_72 , V_8 -> V_71 ) ;
V_68 = F_35 ( V_2 ) ;
if ( V_68 > 0 ) {
F_2 ( & V_8 -> V_9 , L_25 ,
V_72 , V_68 ) ;
V_66 = F_21 ( sizeof( struct V_65 ) * V_68 , V_49 ) ;
if ( ! V_66 )
goto V_73;
F_38 ( V_2 , V_66 ) ;
V_47 = F_41 ( V_8 , V_66 , V_68 ) ;
F_28 ( V_66 ) ;
if ( V_47 )
goto V_73;
}
if ( ! V_14 ) {
V_14 = V_74 ;
V_22 = F_42 ( V_74 ) ;
}
V_2 -> V_22 = V_22 ;
V_2 -> V_14 = F_40 ( V_14 ,
sizeof( struct V_11 ) * V_22 ,
V_49 ) ;
if ( ! V_2 -> V_14 )
goto V_73;
V_8 -> V_61 . V_2 = V_2 ;
for ( V_35 = 0 ; V_35 < V_46 ; V_35 ++ ) {
V_41 [ V_35 ] -> V_2 = V_2 ;
F_17 ( V_2 , V_41 [ V_35 ] ) ;
}
return V_2 ;
V_73:
F_28 ( V_41 ) ;
V_70:
F_28 ( V_2 ) ;
V_69:
F_14 ( & V_8 -> V_9 , L_26 , V_47 ) ;
return F_43 ( V_47 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_8 -> V_61 . V_2 = NULL ;
F_28 ( V_2 -> V_14 ) ;
F_28 ( V_2 -> V_41 ) ;
F_28 ( V_2 ) ;
}
struct V_40 T_3 * F_44 ( const char * V_75 , int V_76 ,
struct V_33 * V_34 , void * V_77 ,
int V_78 ,
struct V_11 * V_14 ,
int V_22 , int V_79 )
{
struct V_33 * V_67 [] = { V_34 } ;
if ( ! V_34 )
return F_43 ( - V_52 ) ;
return F_45 ( V_75 , V_76 , V_67 , 1 , V_77 ,
V_78 , V_14 , V_22 ,
V_79 ) ;
}
struct V_40 T_3 * F_45 ( const char * V_75 , int V_76 ,
struct V_33 * * V_67 , int V_46 ,
void * V_77 , int V_78 ,
struct V_11 * V_14 ,
int V_22 , int V_79 )
{
int V_47 = - V_50 ;
struct V_40 * V_8 ;
struct V_1 * V_2 ;
if ( ! V_67 || V_46 == 0 || ! V_75 )
return F_43 ( - V_52 ) ;
if ( ! V_77 && V_78 > 0 )
return F_43 ( - V_52 ) ;
V_8 = F_46 ( V_75 , V_76 ) ;
if ( ! V_8 ) {
V_47 = - V_50 ;
goto V_80;
}
if ( V_8 -> V_81 != - 1 )
F_47 ( & V_8 -> V_9 , L_27 , V_8 -> V_64 , V_8 -> V_81 ) ;
else
F_47 ( & V_8 -> V_9 , L_28 , V_8 -> V_64 ) ;
V_2 = F_24 ( V_8 , V_67 , V_46 , V_14 , V_22 ) ;
if ( ! V_2 )
goto V_82;
V_47 = F_48 ( V_8 , V_77 , V_78 ) ;
if ( V_47 )
goto V_83;
if ( V_79 )
V_47 = F_49 ( V_8 ) ;
else
V_47 = F_50 ( V_8 ) ;
if ( V_47 )
goto V_83;
return V_8 ;
V_83:
F_31 ( V_2 ) ;
V_82:
F_51 ( V_8 ) ;
V_80:
F_52 ( L_29 , V_75 , V_47 ) ;
return F_43 ( V_47 ) ;
}
static int T_3 F_49 ( struct V_40 * V_8 )
{
struct V_40 * V_84 [ 1 ] ;
V_84 [ 0 ] = V_8 ;
F_53 ( V_84 , 1 ) ;
return 0 ;
}
static int F_54 ( struct V_85 * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
int V_47 ;
V_47 = F_55 ( V_9 ) ;
if ( ! V_47 )
F_56 ( V_8 ) ;
return V_47 ;
}
static int F_57 ( struct V_85 * V_9 )
{
return F_58 ( V_9 ) ;
}
static int F_59 ( struct V_85 * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
F_60 ( V_8 ) ;
return F_61 ( V_9 ) ;
}
static int F_62 ( struct V_85 * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
struct V_1 * V_2 = F_33 ( V_8 ) ;
int V_47 ;
V_47 = F_63 ( V_9 ) ;
if ( ! V_47 && ! F_64 ( V_9 ) ) {
if ( F_55 ( V_9 ) == 0 ) {
if ( ! ( V_2 -> V_20 & V_86 ) )
F_56 ( V_8 ) ;
V_2 -> V_20 |= V_87 ;
}
}
return V_47 ;
}
static int F_65 ( struct V_85 * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
struct V_1 * V_2 = F_33 ( V_8 ) ;
if ( ( V_2 -> V_20 & V_87 ) &&
! F_64 ( V_9 ) ) {
V_2 -> V_20 &= ~ V_87 ;
if ( ! ( V_2 -> V_20 & V_86 ) )
F_60 ( V_8 ) ;
F_61 ( V_9 ) ;
}
return F_66 ( V_9 ) ;
}
int F_50 ( struct V_40 * V_8 )
{
F_37 ( L_30 , V_8 -> V_64 ) ;
V_8 -> V_9 . V_54 = & V_55 ;
return F_67 ( V_8 ) ;
}
int F_60 ( struct V_40 * V_8 )
{
int V_47 ;
struct V_1 * V_2 ;
V_2 = F_33 ( V_8 ) ;
if ( V_2 -> V_88 == V_89 ) {
F_6 ( & V_8 -> V_9 ,
L_31 ,
V_72 , V_2 -> V_88 ) ;
return - V_52 ;
}
if ( V_2 -> V_88 == V_90 )
V_2 -> V_10 = V_2 -> V_22 ;
V_47 = F_1 ( V_2 , V_91 ) ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_92 ;
V_2 -> V_88 = V_89 ;
return V_47 ;
}
int F_56 ( struct V_40 * V_8 )
{
int V_47 ;
struct V_1 * V_2 ;
V_2 = F_33 ( V_8 ) ;
if ( V_2 -> V_88 != V_89 ) {
F_6 ( & V_8 -> V_9 ,
L_31 ,
V_72 , V_2 -> V_88 ) ;
return - V_52 ;
}
V_47 = F_7 ( V_2 , V_93 ) ;
V_2 -> V_88 = V_94 ;
return V_47 ;
}
int F_68 ( struct V_40 * V_8 )
{
int V_47 , V_35 ;
struct V_1 * V_2 ;
V_2 = F_33 ( V_8 ) ;
if ( V_2 -> V_88 != V_89 &&
V_2 -> V_88 != V_94 ) {
F_6 ( & V_8 -> V_9 ,
L_31 ,
V_72 , V_2 -> V_88 ) ;
return - V_52 ;
}
V_47 = F_7 ( V_2 , V_91 ) ;
for ( V_35 = 0 ; V_35 < V_2 -> V_63 ; V_35 ++ )
F_69 ( V_2 -> V_41 [ V_35 ] ) ;
V_2 -> V_88 = V_95 ;
return V_47 ;
}
int F_70 ( struct V_40 * V_8 ,
T_2 V_96 )
{
int V_47 = - V_52 ;
struct V_1 * V_2 ;
V_2 = F_33 ( V_8 ) ;
if ( V_96 == V_2 -> V_15 )
return 0 ;
V_2 -> V_16 = V_96 ;
if ( V_2 -> V_88 != V_94 )
return 0 ;
else if ( V_96 > V_2 -> V_15 )
V_47 = F_7 ( V_2 , V_93 ) ;
else if ( V_96 < V_2 -> V_15 )
V_47 = F_1 ( V_2 , V_93 ) ;
return V_47 ;
}
struct V_97 * F_71 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_63 )
return NULL ;
return F_72 ( V_2 -> V_41 [ 0 ] ) ;
}
void T_4 * F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 != 1 )
return NULL ;
return F_74 ( V_2 -> V_41 [ 0 ] ) ;
}
struct V_85 * F_75 ( const char * V_45 )
{
struct V_33 * V_34 ;
if ( ! V_45 ) {
F_76 ( 1 , L_32 , V_72 ) ;
return F_43 ( - V_52 ) ;
}
V_34 = F_23 ( V_45 ) ;
if ( F_77 ( V_34 ) ) {
F_76 ( 1 , L_33 , V_72 ,
V_45 ) ;
return F_43 ( V_34 ? F_25 ( V_34 ) : - V_48 ) ;
}
if ( F_77 ( V_34 -> V_2 ) ) {
F_76 ( 1 , L_34 , V_72 ,
V_45 ) ;
return F_43 ( V_34 -> V_2 ? F_25 ( V_34 -> V_2 ) : - V_48 ) ;
}
if ( F_77 ( V_34 -> V_2 -> V_8 ) )
return F_43 ( V_34 -> V_2 -> V_8 ? F_25 ( V_34 -> V_2 -> V_8 ) : - V_48 ) ;
return & V_34 -> V_2 -> V_8 -> V_9 ;
}
int F_78 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_63 ; V_35 ++ )
F_79 ( V_2 -> V_41 [ V_35 ] ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_63 ; V_35 ++ )
F_81 ( V_2 -> V_41 [ V_35 ] ) ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_63 ; V_35 ++ )
F_83 ( V_2 -> V_41 [ V_35 ] ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_63 ; V_35 ++ )
F_85 ( V_2 -> V_41 [ V_35 ] ) ;
return 0 ;
}
static int T_3 F_86 ( void )
{
F_87 ( & V_98 , & V_99 ) ;
return 0 ;
}
