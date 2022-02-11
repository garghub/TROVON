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
L_2 ,
V_2 -> V_10 , V_13 ) ;
if ( V_13 > V_12 -> V_18 ) {
V_12 -> V_19 = V_13 ;
if ( V_12 -> V_20 & V_21 ) {
V_12 -> V_18 = V_13 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_3 ,
V_2 -> V_10 , V_13 ) ;
} else
F_6 ( & V_2 -> V_8 -> V_9 ,
L_4 ,
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
F_2 ( & V_2 -> V_8 -> V_9 , L_5 ) ;
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
L_6 ,
V_2 -> V_10 , V_23 ) ;
if ( V_23 > V_12 -> V_25 ) {
V_12 -> V_26 = V_23 ;
if ( V_12 -> V_20 & V_21 ) {
V_12 -> V_25 = V_23 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_7 ,
V_2 -> V_10 , V_23 ) ;
} else
F_6 ( & V_2 -> V_8 -> V_9 ,
L_8 ,
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
F_2 ( & V_2 -> V_8 -> V_9 , L_9 , V_27 , V_28 ) ;
V_30 = F_9 ( F_10 ( & V_2 -> V_8 -> V_9 ) , V_27 ) ;
if ( ! F_11 ( V_30 ) ) {
F_6 ( & V_2 -> V_8 -> V_9 ,
L_10 , V_27 ) ;
F_12 ( V_30 ) ;
return;
}
V_30 = F_13 ( NULL , V_28 ) ;
if ( F_11 ( V_30 ) ) {
F_14 ( & V_2 -> V_8 -> V_9 ,
L_11 , V_28 ) ;
return;
}
V_32 = F_15 ( V_30 , V_27 , F_10 ( & V_2 -> V_8 -> V_9 ) ) ;
if ( ! V_32 ) {
F_14 ( & V_2 -> V_8 -> V_9 ,
L_12 , V_27 ) ;
return;
}
F_16 ( V_32 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_35 ;
F_8 ( V_2 , L_13 , V_34 -> V_36 ) ;
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
V_46 = F_19 ( V_43 , L_14 ) ;
if ( ! V_46 || F_20 ( V_46 ) ) {
F_2 ( & V_8 -> V_9 , L_15 ) ;
return - V_48 ;
}
V_41 = F_21 ( sizeof( struct V_33 * ) * V_46 , V_49 ) ;
if ( ! V_41 ) {
V_47 = - V_50 ;
goto V_51;
}
for ( V_35 = 0 ; V_35 < V_46 ; V_35 ++ ) {
F_22 ( V_43 , L_14 , V_35 , & V_45 ) ;
V_34 = F_23 ( V_45 ) ;
if ( ! V_34 ) {
F_14 ( & V_8 -> V_9 , L_16 ,
V_45 ) ;
V_47 = - V_52 ;
goto V_53;
}
V_41 [ V_35 ] = V_34 ;
}
V_2 = F_24 ( V_8 , V_41 , V_46 , NULL , 0 ) ;
if ( ! V_2 ) {
F_14 ( & V_8 -> V_9 , L_17 ,
V_45 ) ;
V_47 = F_25 ( V_2 ) ;
goto V_53;
}
for ( V_35 = 0 ; V_35 < V_8 -> V_54 ; V_35 ++ ) {
struct V_55 * V_30 = & V_8 -> V_55 [ V_35 ] ;
if ( V_30 -> V_56 == NULL )
V_30 -> V_56 = F_10 ( & V_8 -> V_9 ) ;
}
if ( F_26 ( V_43 , L_18 , NULL ) )
F_27 ( V_8 ) ;
V_8 -> V_9 . V_57 = & V_58 ;
V_53:
F_28 ( V_41 ) ;
V_51:
return V_47 ;
}
static int F_29 ( struct V_59 * V_60 ,
unsigned long V_61 , void * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
struct V_1 * V_2 ;
switch ( V_61 ) {
case V_62 :
if ( V_8 -> V_63 . V_2 )
F_31 ( V_8 -> V_63 . V_2 ) ;
break;
case V_64 :
if ( V_8 -> V_9 . V_44 )
F_18 ( V_8 ) ;
default:
V_2 = F_32 ( V_8 ) ;
if ( V_2 )
V_2 -> V_65 = V_61 ;
}
return V_66 ;
}
int F_33 ( struct V_40 * V_8 )
{
struct V_1 * V_2 ;
T_2 V_47 = 0 ;
V_2 = F_32 ( V_8 ) ;
if ( V_2 -> V_67 )
V_47 = F_34 ( V_2 -> V_41 [ 0 ] ) ;
return V_47 ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned long V_20 )
{
int V_7 = 0 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ )
V_7 += F_36 ( V_2 -> V_41 [ V_35 ] , V_20 ) ;
F_37 ( L_19 ,
V_2 -> V_8 -> V_56 , V_7 , V_2 -> V_67 ) ;
return V_7 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_55 * V_68 )
{
int V_35 , V_30 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ ) {
V_30 = F_39 ( V_2 -> V_41 [ V_35 ] , V_68 ) ;
V_68 += V_30 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_55 * V_68 )
{
int V_35 , V_30 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ ) {
V_30 = F_41 ( V_2 -> V_41 [ V_35 ] , V_68 ) ;
V_68 += V_30 ;
}
return 0 ;
}
struct V_1 * F_24 ( struct V_40 * V_8 ,
struct V_33 * * V_69 , int V_46 ,
struct V_11 * V_14 ,
int V_22 )
{
int V_47 = - V_50 ;
struct V_1 * V_2 ;
struct V_55 * V_68 = NULL ;
int V_35 , V_70 ;
struct V_33 * * V_41 ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_49 ) ;
if ( ! V_2 ) {
V_47 = - V_50 ;
goto V_71;
}
V_2 -> V_67 = V_46 ;
V_41 = F_42 ( V_69 , sizeof( struct V_33 * ) * V_46 , V_49 ) ;
if ( ! V_41 )
goto V_72;
V_2 -> V_41 = V_41 ;
V_2 -> V_8 = V_8 ;
if ( ! V_8 -> V_54 ) {
V_70 = F_35 ( V_2 , V_73 |
V_74 |
V_75 ) ;
} else {
for ( V_35 = 0 ; V_35 < V_8 -> V_54 ; V_35 ++ ) {
struct V_55 * V_30 = & V_8 -> V_55 [ V_35 ] ;
if ( V_30 -> V_20 == V_74 )
goto V_76;
}
V_70 = F_35 ( V_2 , V_74 ) ;
if ( ! V_70 )
goto V_76;
V_70 += V_8 -> V_54 ;
}
V_68 = F_21 ( sizeof( struct V_55 ) * V_70 , V_49 ) ;
if ( ! V_68 )
goto V_77;
if ( ! V_8 -> V_54 ) {
F_2 ( & V_8 -> V_9 , L_20 ,
V_78 , V_70 ) ;
F_38 ( V_2 , V_68 ) ;
} else {
F_2 ( & V_8 -> V_9 ,
L_21 ,
V_78 , V_70 - V_8 -> V_54 ) ;
memcpy ( V_68 , V_8 -> V_55 ,
sizeof( struct V_55 ) * V_8 -> V_54 ) ;
F_40 ( V_2 , & V_68 [ V_8 -> V_54 ] ) ;
}
V_47 = F_43 ( V_8 , V_68 , V_70 ) ;
F_28 ( V_68 ) ;
if ( V_47 )
goto V_77;
V_76:
if ( ! V_14 ) {
V_14 = V_79 ;
V_22 = F_44 ( V_79 ) ;
}
V_2 -> V_22 = V_22 ;
V_2 -> V_14 = F_42 ( V_14 ,
sizeof( struct V_11 ) * V_22 ,
V_49 ) ;
if ( ! V_2 -> V_14 )
goto V_77;
V_8 -> V_63 . V_2 = V_2 ;
for ( V_35 = 0 ; V_35 < V_46 ; V_35 ++ ) {
V_41 [ V_35 ] -> V_2 = V_2 ;
F_17 ( V_2 , V_41 [ V_35 ] ) ;
}
return V_2 ;
V_77:
F_28 ( V_41 ) ;
V_72:
F_28 ( V_2 ) ;
V_71:
F_14 ( & V_8 -> V_9 , L_22 , V_47 ) ;
return F_45 ( V_47 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
V_2 -> V_8 -> V_63 . V_2 = NULL ;
F_28 ( V_2 -> V_14 ) ;
F_28 ( V_2 -> V_41 ) ;
F_28 ( V_2 ) ;
}
struct V_40 T_3 * F_46 ( const char * V_80 , int V_81 ,
struct V_33 * V_34 , void * V_82 ,
int V_83 ,
struct V_11 * V_14 ,
int V_22 , int V_84 )
{
struct V_33 * V_69 [] = { V_34 } ;
if ( ! V_34 )
return F_45 ( - V_52 ) ;
return F_47 ( V_80 , V_81 , V_69 , 1 , V_82 ,
V_83 , V_14 , V_22 ,
V_84 ) ;
}
struct V_40 T_3 * F_47 ( const char * V_80 , int V_81 ,
struct V_33 * * V_69 , int V_46 ,
void * V_82 , int V_83 ,
struct V_11 * V_14 ,
int V_22 , int V_84 )
{
int V_47 = - V_50 ;
struct V_40 * V_8 ;
struct V_1 * V_2 ;
if ( ! V_69 || V_46 == 0 || ! V_80 )
return F_45 ( - V_52 ) ;
if ( ! V_82 && V_83 > 0 )
return F_45 ( - V_52 ) ;
V_8 = F_48 ( V_80 , V_81 ) ;
if ( ! V_8 ) {
V_47 = - V_50 ;
goto V_85;
}
if ( V_8 -> V_86 != - 1 )
F_49 ( & V_8 -> V_9 , L_23 , V_8 -> V_56 , V_8 -> V_86 ) ;
else
F_49 ( & V_8 -> V_9 , L_24 , V_8 -> V_56 ) ;
V_2 = F_24 ( V_8 , V_69 , V_46 , V_14 , V_22 ) ;
if ( F_11 ( V_2 ) )
goto V_87;
V_47 = F_50 ( V_8 , V_82 , V_83 ) ;
if ( V_47 )
goto V_88;
if ( V_84 )
V_47 = F_51 ( V_8 ) ;
else
V_47 = F_52 ( V_8 ) ;
if ( V_47 )
goto V_88;
return V_8 ;
V_88:
F_31 ( V_2 ) ;
V_87:
F_53 ( V_8 ) ;
V_85:
F_54 ( L_25 , V_80 , V_47 ) ;
return F_45 ( V_47 ) ;
}
static int T_3 F_51 ( struct V_40 * V_8 )
{
struct V_40 * V_89 [ 1 ] ;
V_89 [ 0 ] = V_8 ;
F_55 ( V_89 , 1 ) ;
return 0 ;
}
static int F_56 ( struct V_90 * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
int V_47 ;
V_47 = F_57 ( V_9 ) ;
if ( ! V_47 )
F_58 ( V_8 ) ;
return V_47 ;
}
static int F_59 ( struct V_90 * V_9 )
{
return F_60 ( V_9 ) ;
}
static int F_61 ( struct V_90 * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
F_62 ( V_8 ) ;
return F_63 ( V_9 ) ;
}
static int F_64 ( struct V_90 * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
struct V_1 * V_2 = F_32 ( V_8 ) ;
int V_47 ;
if ( V_2 -> V_65 != V_91 )
return 0 ;
V_47 = F_65 ( V_9 ) ;
if ( ! V_47 && ! F_66 ( V_9 ) ) {
if ( F_57 ( V_9 ) == 0 ) {
if ( ! ( V_2 -> V_20 & V_92 ) )
F_58 ( V_8 ) ;
V_2 -> V_20 |= V_93 ;
}
}
return V_47 ;
}
static int F_67 ( struct V_90 * V_9 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
struct V_1 * V_2 = F_32 ( V_8 ) ;
if ( ( V_2 -> V_20 & V_93 ) &&
! F_66 ( V_9 ) ) {
V_2 -> V_20 &= ~ V_93 ;
if ( ! ( V_2 -> V_20 & V_92 ) )
F_62 ( V_8 ) ;
F_63 ( V_9 ) ;
}
return F_68 ( V_9 ) ;
}
int F_52 ( struct V_40 * V_8 )
{
F_37 ( L_26 , V_8 -> V_56 ) ;
V_8 -> V_9 . V_57 = & V_58 ;
return F_69 ( V_8 ) ;
}
int F_62 ( struct V_40 * V_8 )
{
int V_47 ;
struct V_1 * V_2 ;
V_2 = F_32 ( V_8 ) ;
if ( V_2 -> V_94 == V_95 ) {
F_6 ( & V_8 -> V_9 ,
L_27 ,
V_78 , V_2 -> V_94 ) ;
return - V_52 ;
}
if ( V_2 -> V_94 == V_96 )
V_2 -> V_10 = V_2 -> V_22 ;
V_47 = F_1 ( V_2 , V_97 ) ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_98 ;
V_2 -> V_94 = V_95 ;
return V_47 ;
}
int F_58 ( struct V_40 * V_8 )
{
int V_47 ;
struct V_1 * V_2 ;
V_2 = F_32 ( V_8 ) ;
if ( V_2 -> V_94 != V_95 ) {
F_6 ( & V_8 -> V_9 ,
L_27 ,
V_78 , V_2 -> V_94 ) ;
return - V_52 ;
}
V_47 = F_7 ( V_2 , V_99 ) ;
V_2 -> V_94 = V_100 ;
return V_47 ;
}
int F_70 ( struct V_40 * V_8 )
{
int V_47 , V_35 ;
struct V_1 * V_2 ;
V_2 = F_32 ( V_8 ) ;
if ( V_2 -> V_94 != V_95 &&
V_2 -> V_94 != V_100 ) {
F_6 ( & V_8 -> V_9 ,
L_27 ,
V_78 , V_2 -> V_94 ) ;
return - V_52 ;
}
V_47 = F_7 ( V_2 , V_97 ) ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ )
F_71 ( V_2 -> V_41 [ V_35 ] ) ;
V_2 -> V_94 = V_101 ;
return V_47 ;
}
int F_72 ( struct V_40 * V_8 , const char * V_56 )
{
struct V_1 * V_2 = F_32 ( V_8 ) ;
int V_47 = 0 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ ) {
V_47 = F_73 ( V_2 -> V_41 [ V_35 ] , V_56 ) ;
if ( V_47 )
break;
}
return V_47 ;
}
int F_74 ( struct V_40 * V_8 ,
const char * V_56 )
{
struct V_1 * V_2 = F_32 ( V_8 ) ;
int V_47 = 0 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ ) {
V_47 = F_75 ( V_2 -> V_41 [ V_35 ] , V_56 ) ;
if ( V_47 )
break;
}
return V_47 ;
}
int F_76 ( struct V_40 * V_8 ,
T_2 V_102 )
{
int V_47 = - V_52 ;
struct V_1 * V_2 ;
V_2 = F_32 ( V_8 ) ;
if ( V_102 == V_2 -> V_15 )
return 0 ;
V_2 -> V_16 = V_102 ;
if ( V_2 -> V_94 != V_100 )
return 0 ;
else if ( V_102 > V_2 -> V_15 )
V_47 = F_7 ( V_2 , V_99 ) ;
else if ( V_102 < V_2 -> V_15 )
V_47 = F_1 ( V_2 , V_99 ) ;
return V_47 ;
}
struct V_103 * F_77 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_67 )
return NULL ;
return F_78 ( V_2 -> V_41 [ 0 ] ) ;
}
void T_4 * F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 != 1 )
return NULL ;
return F_80 ( V_2 -> V_41 [ 0 ] ) ;
}
struct V_90 * F_81 ( const char * V_45 )
{
struct V_33 * V_34 ;
if ( ! V_45 ) {
F_82 ( 1 , L_28 , V_78 ) ;
return F_45 ( - V_52 ) ;
}
V_34 = F_23 ( V_45 ) ;
if ( F_83 ( V_34 ) ) {
F_82 ( 1 , L_29 , V_78 ,
V_45 ) ;
return F_45 ( V_34 ? F_25 ( V_34 ) : - V_48 ) ;
}
if ( F_83 ( V_34 -> V_2 ) ) {
F_82 ( 1 , L_30 , V_78 ,
V_45 ) ;
return F_45 ( V_34 -> V_2 ? F_25 ( V_34 -> V_2 ) : - V_48 ) ;
}
if ( F_83 ( V_34 -> V_2 -> V_8 ) )
return F_45 ( V_34 -> V_2 -> V_8 ? F_25 ( V_34 -> V_2 -> V_8 ) : - V_48 ) ;
return & V_34 -> V_2 -> V_8 -> V_9 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ )
F_85 ( V_2 -> V_41 [ V_35 ] ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ )
F_87 ( V_2 -> V_41 [ V_35 ] ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ )
F_89 ( V_2 -> V_41 [ V_35 ] ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_67 ; V_35 ++ )
F_91 ( V_2 -> V_41 [ V_35 ] ) ;
return 0 ;
}
static int T_3 F_92 ( void )
{
F_93 ( & V_104 , & V_105 ) ;
return 0 ;
}
static int T_3 F_94 ( struct V_90 * V_9 , void * V_106 )
{
struct V_40 * V_8 = F_30 ( V_9 ) ;
struct V_1 * V_2 = F_32 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_65 != V_91 ) {
if ( V_2 -> V_94 == V_95 ) {
F_6 ( V_9 , L_31 ,
V_78 ) ;
F_58 ( V_8 ) ;
}
}
return 0 ;
}
static int T_3 F_95 ( void )
{
F_96 ( & V_104 , NULL , NULL , F_94 ) ;
return 0 ;
}
