static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = & V_2 -> V_4 ;
T_1 V_5 ;
V_5 = V_2 -> V_6 - sizeof( T_1 ) ;
V_5 = F_2 ( V_5 , sizeof( T_1 ) ) ;
if ( F_3 ( V_3 ) ) {
if ( V_3 -> V_7 . V_8 > V_5 ) {
F_4 ( L_1
L_2 , V_9 ,
V_2 -> V_10 , V_3 -> V_7 . V_8 , V_5 ) ;
return false ;
}
if ( V_3 -> V_11 . V_8 > V_5 ) {
F_4 ( L_3
L_2 , V_9 ,
V_2 -> V_10 , V_3 -> V_11 . V_8 , V_5 ) ;
return false ;
}
}
return true ;
}
static bool F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 . V_15 ;
struct V_17 * V_18 ;
struct V_19 * div ;
if ( V_13 -> type != V_20 )
return false ;
V_18 = & V_15 -> V_18 ;
if ( V_18 -> V_21 && F_6 ( V_18 ) )
return true ;
div = & V_15 -> div ;
if ( ! F_7 ( div ) )
return false ;
if ( ! F_8 ( div ) )
return true ;
div = & V_15 -> V_22 ;
return F_7 ( div ) && ! F_8 ( div ) ;
}
static bool F_9 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_23 * V_4 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_19 * div ;
struct V_17 * V_18 ;
struct V_28 * V_29 ;
const char * V_10 ;
T_1 V_6 ;
T_1 V_5 ;
F_10 ( V_13 -> type != V_20 ) ;
V_15 = V_13 -> V_16 . V_15 ;
V_10 = V_13 -> V_30 . V_10 ;
V_6 = V_13 -> V_2 -> V_6 ;
V_5 = V_6 - sizeof( T_1 ) ;
V_5 = F_2 ( V_5 , sizeof( T_1 ) ) ;
V_4 = & V_15 -> V_4 ;
if ( F_11 ( V_4 ) ) {
if ( V_4 -> V_8 > V_5 ) {
F_4 ( L_4 ,
V_9 , V_10 , V_4 -> V_8 , V_5 ) ;
return false ;
}
}
V_25 = & V_15 -> V_25 ;
V_27 = & V_15 -> V_27 ;
if ( F_12 ( V_25 ) ) {
if ( V_25 -> V_8 > V_5 ) {
F_4 ( L_5 ,
V_9 , V_10 , V_25 -> V_8 , V_5 ) ;
return false ;
}
if ( F_13 ( V_27 ) ) {
if ( V_27 -> V_8 > V_5 ) {
F_4 ( L_6
L_2 , V_9 ,
V_10 , V_27 -> V_8 , V_5 ) ;
return false ;
}
}
} else if ( F_13 ( V_27 ) ) {
F_4 ( L_7 , V_9 , V_10 ) ;
return false ;
}
div = & V_15 -> div ;
if ( F_7 ( div ) ) {
if ( div -> V_16 . V_31 . V_8 > V_5 ) {
F_4 ( L_8 ,
V_9 , V_10 , div -> V_16 . V_31 . V_8 , V_5 ) ;
return false ;
}
}
div = & V_15 -> V_22 ;
if ( F_7 ( div ) ) {
if ( div -> V_16 . V_31 . V_8 > V_5 ) {
F_4 ( L_9
L_2 ,
V_9 , V_10 , div -> V_16 . V_31 . V_8 , V_5 ) ;
return false ;
}
}
V_18 = & V_15 -> V_18 ;
if ( F_6 ( V_18 ) ) {
if ( V_18 -> V_8 > V_5 ) {
F_4 ( L_10 ,
V_9 , V_10 , V_18 -> V_8 , V_5 ) ;
return false ;
}
}
V_29 = & V_15 -> V_29 ;
if ( F_14 ( V_29 ) ) {
if ( V_29 -> V_8 > V_5 ) {
F_4 ( L_11 ,
V_9 , V_10 , V_29 -> V_8 , V_5 ) ;
return false ;
}
}
V_29 = & V_15 -> V_32 ;
if ( F_14 ( V_29 ) ) {
if ( V_29 -> V_8 > V_5 ) {
F_4 ( L_12 ,
V_9 , V_10 , V_29 -> V_8 , V_5 ) ;
return false ;
}
}
return true ;
}
static bool F_15 ( T_1 V_33 , const char * V_34 ,
const char * V_35 )
{
T_1 V_5 = V_36 * sizeof( T_1 ) - 1 ;
if ( V_33 > V_5 ) {
F_4 ( L_13 , V_9 ,
V_34 , V_35 , V_33 , V_5 ) ;
return false ;
}
return true ;
}
static bool F_16 ( T_1 V_37 , T_1 V_38 , const char * V_34 ,
const char * V_35 )
{
T_1 V_5 = V_36 * sizeof( T_1 ) ;
if ( ! V_38 ) {
F_4 ( L_14 , V_9 ,
V_34 , V_35 ) ;
return false ;
}
if ( V_37 + V_38 > V_5 ) {
F_4 ( L_15 , V_9 ,
V_34 , V_35 , V_37 , V_38 , V_5 ) ;
return false ;
}
return true ;
}
static bool
F_17 ( struct V_3 * V_3 , const char * V_39 )
{
struct V_40 * V_7 = & V_3 -> V_7 ;
struct V_41 * V_11 ;
if ( ! F_15 ( V_7 -> V_42 , L_16 , V_39 ) )
return false ;
V_11 = & V_3 -> V_11 ;
if ( ! F_15 ( V_11 -> V_43 , L_17 , V_39 ) )
return false ;
if ( ! F_15 ( V_11 -> V_44 , L_18 , V_39 ) )
return false ;
if ( ! F_15 ( V_11 -> V_45 , L_19 , V_39 ) )
return false ;
return true ;
}
static bool F_18 ( struct V_23 * V_4 , const char * V_35 )
{
if ( ! F_15 ( V_4 -> V_42 , L_20 , V_35 ) )
return false ;
return true ;
}
static bool F_19 ( struct V_24 * V_25 , const char * V_34 ,
const char * V_35 )
{
if ( ! F_15 ( V_25 -> V_46 , L_21 , V_35 ) )
return false ;
if ( F_20 ( V_25 ) ) {
if ( ! F_15 ( V_25 -> V_47 , L_22 , V_35 ) )
return false ;
if ( F_21 ( V_25 ) ) {
if ( ! F_15 ( V_25 -> V_48 ,
L_23 ,
V_35 ) )
return false ;
}
} else {
F_10 ( ! F_21 ( V_25 ) ) ;
}
return true ;
}
static bool F_22 ( struct V_26 * V_27 , const char * V_35 )
{
if ( ! F_15 ( V_27 -> V_47 , L_24 , V_35 ) )
return false ;
if ( ! F_15 ( V_27 -> V_49 , L_25 , V_35 ) )
return false ;
return true ;
}
static bool F_23 ( struct V_17 * V_18 , const char * V_34 ,
const char * V_35 )
{
if ( ! F_16 ( V_18 -> V_37 , V_18 -> V_38 , V_34 , V_35 ) )
return false ;
if ( V_18 -> V_21 ) {
T_1 V_50 ;
T_1 V_5 ;
V_50 = V_18 -> V_51 [ V_18 -> V_21 - 1 ] ;
V_5 = ( 1 << V_18 -> V_38 ) - 1 ;
if ( V_50 > V_5 ) {
F_4 ( L_26
L_27 ,
V_9 , V_35 , V_50 ,
V_18 -> V_38 ) ;
return false ;
}
} else {
F_24 ( L_28 ,
V_9 , V_35 ) ;
F_25 ( V_18 ) ;
F_26 ( V_18 -> V_51 ) ;
V_18 -> V_51 = NULL ;
}
return true ;
}
static bool F_27 ( struct V_19 * div , const char * V_34 ,
const char * V_35 )
{
if ( F_8 ( div ) ) {
if ( div -> V_16 . V_52 == 0 ) {
F_4 ( L_29 , V_9 ,
V_34 , V_35 ) ;
return false ;
}
return true ;
}
if ( ! F_16 ( div -> V_16 . V_31 . V_37 , div -> V_16 . V_31 . V_38 ,
V_34 , V_35 ) )
return false ;
if ( F_28 ( div ) )
if ( div -> V_16 . V_31 . V_53 > div -> V_16 . V_31 . V_38 ) {
F_24 ( L_30 ,
V_9 , V_34 , V_35 ,
div -> V_16 . V_31 . V_53 , div -> V_16 . V_31 . V_38 ) ;
return false ;
}
return true ;
}
static bool F_29 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 . V_15 ;
struct V_19 * div ;
struct V_19 * V_22 ;
T_1 V_5 ;
F_10 ( V_13 -> type != V_20 ) ;
if ( ! F_7 ( & V_15 -> div ) || ! F_7 ( & V_15 -> V_22 ) )
return true ;
div = & V_15 -> div ;
V_22 = & V_15 -> V_22 ;
if ( F_8 ( div ) || F_8 ( V_22 ) )
return true ;
V_5 = V_36 * sizeof( T_1 ) ;
return div -> V_16 . V_31 . V_53 + V_22 -> V_16 . V_31 . V_53 <= V_5 ;
}
static bool F_30 ( struct V_28 * V_29 , const char * V_34 ,
const char * V_35 )
{
return F_15 ( V_29 -> V_42 , V_34 , V_35 ) ;
}
static bool
F_31 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_23 * V_4 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_17 * V_18 ;
struct V_19 * div ;
struct V_19 * V_22 ;
struct V_28 * V_29 ;
const char * V_10 ;
F_10 ( V_13 -> type != V_20 ) ;
if ( ! F_9 ( V_13 ) )
return false ;
V_15 = V_13 -> V_16 . V_15 ;
V_10 = V_13 -> V_30 . V_10 ;
V_4 = & V_15 -> V_4 ;
if ( F_11 ( V_4 ) && ! F_18 ( V_4 , V_10 ) )
return false ;
V_25 = & V_15 -> V_25 ;
if ( F_12 ( V_25 ) && ! F_19 ( V_25 , L_31 , V_10 ) )
return false ;
V_27 = & V_15 -> V_27 ;
if ( F_13 ( V_27 ) && ! F_22 ( V_27 , V_10 ) )
return false ;
V_18 = & V_15 -> V_18 ;
if ( F_6 ( V_18 ) ) {
if ( ! F_23 ( V_18 , L_32 , V_10 ) )
return false ;
} else if ( V_18 -> V_21 > 1 ) {
F_4 ( L_33 ,
V_9 , V_10 ) ;
return false ;
}
div = & V_15 -> div ;
V_22 = & V_15 -> V_22 ;
if ( F_7 ( div ) ) {
if ( ! F_27 ( div , L_34 , V_10 ) )
return false ;
if ( F_7 ( V_22 ) )
if ( ! F_27 ( V_22 , L_35 , V_10 ) )
return false ;
} else if ( F_7 ( V_22 ) ) {
F_4 ( L_36 , V_9 ,
V_10 ) ;
return false ;
}
V_29 = & V_15 -> V_29 ;
if ( F_14 ( V_29 ) ) {
if ( ! F_30 ( V_29 , L_37 , V_10 ) )
return false ;
if ( F_14 ( & V_15 -> V_32 ) ) {
if ( ! F_30 ( V_29 , L_38 , V_10 ) ) {
return false ;
}
}
if ( ! F_5 ( V_13 ) ) {
F_24 ( L_39 ,
V_9 , V_10 ) ;
F_32 ( V_29 ) ;
}
} else if ( F_14 ( & V_15 -> V_32 ) ) {
F_4 ( L_40 , V_9 ,
V_10 ) ;
return false ;
} else if ( F_5 ( V_13 ) ) {
F_4 ( L_41 , V_9 ,
V_10 ) ;
return false ;
}
return F_29 ( V_13 ) ;
}
static bool F_33 ( struct V_12 * V_13 )
{
switch ( V_13 -> type ) {
case V_20 :
if ( ! F_31 ( V_13 ) )
return false ;
break;
default:
F_4 ( L_42 , V_9 ,
( int ) V_13 -> type ) ;
return false ;
}
return true ;
}
static T_1 * F_34 ( const char * V_54 [] ,
T_1 * V_55 , const char * * * V_56 )
{
static const char * * V_57 ;
static T_1 * V_51 ;
const char * * clock ;
T_1 V_21 ;
T_1 V_58 = 0 ;
T_1 V_59 ;
T_1 V_60 ;
T_1 V_61 ;
* V_55 = 0 ;
* V_56 = NULL ;
if ( ! V_54 )
return NULL ;
for ( clock = V_54 ; * clock ; clock ++ )
if ( * clock == V_62 )
V_58 ++ ;
V_59 = ( T_1 ) ( clock - V_54 ) ;
V_21 = V_59 - V_58 ;
if ( ! V_21 )
return NULL ;
if ( V_21 > V_63 ) {
F_4 ( L_43 , V_9 ,
V_21 , V_63 ) ;
return F_35 ( - V_64 ) ;
}
V_57 = F_36 ( V_21 , sizeof( * V_57 ) ,
V_65 ) ;
if ( ! V_57 ) {
F_4 ( L_44 , V_9 ,
V_21 ) ;
return F_35 ( - V_66 ) ;
}
V_51 = F_36 ( V_21 , sizeof( * V_51 ) ,
V_65 ) ;
if ( ! V_51 ) {
F_4 ( L_45 , V_9 ,
V_21 ) ;
F_26 ( V_57 ) ;
return F_35 ( - V_66 ) ;
}
for ( V_60 = 0 , V_61 = 0 ; V_60 < V_59 ; V_60 ++ ) {
if ( V_54 [ V_60 ] != V_62 ) {
V_57 [ V_61 ] = V_54 [ V_60 ] ;
V_51 [ V_61 ] = V_60 ;
V_61 ++ ;
}
}
* V_56 = V_57 ;
* V_55 = V_21 ;
return V_51 ;
}
static int
F_37 ( const char * * V_54 , struct V_17 * V_18 ,
struct V_67 * V_30 )
{
const char * * V_57 = NULL ;
T_1 V_21 = 0 ;
T_1 * V_51 ;
V_51 = F_34 ( V_54 , & V_21 , & V_57 ) ;
if ( F_38 ( V_51 ) ) {
int V_68 = F_39 ( V_51 ) ;
F_4 ( L_46 ,
V_9 , V_30 -> V_10 , V_68 ) ;
return V_68 ;
}
V_30 -> V_57 = V_57 ;
V_30 -> V_69 = V_21 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_51 = V_51 ;
return 0 ;
}
static void F_40 ( struct V_17 * V_18 ,
struct V_67 * V_30 )
{
F_26 ( V_18 -> V_51 ) ;
V_18 -> V_51 = NULL ;
V_18 -> V_21 = 0 ;
V_30 -> V_69 = 0 ;
F_26 ( V_30 -> V_57 ) ;
V_30 -> V_57 = NULL ;
}
static void F_41 ( struct V_14 * V_70 ,
struct V_67 * V_30 )
{
F_40 ( & V_70 -> V_18 , V_30 ) ;
}
static int
F_42 ( struct V_14 * V_70 , struct V_67 * V_30 )
{
V_30 -> V_71 = V_72 ;
return F_37 ( V_70 -> V_54 , & V_70 -> V_18 , V_30 ) ;
}
static void F_43 ( struct V_12 * V_13 )
{
switch ( V_13 -> type ) {
case V_20 :
F_41 ( V_13 -> V_16 . V_70 , & V_13 -> V_30 ) ;
break;
default:
break;
}
V_13 -> V_16 . V_70 = NULL ;
V_13 -> type = V_73 ;
}
static void F_44 ( struct V_74 * V_75 )
{
struct V_12 * V_13 ;
if ( ! V_75 )
return;
F_45 ( V_75 ) ;
V_13 = F_46 ( V_75 ) ;
F_43 ( V_13 ) ;
}
static int F_47 ( struct V_12 * V_13 )
{
int V_68 ;
struct V_67 * V_30 = & V_13 -> V_30 ;
switch ( V_13 -> type ) {
case V_20 :
V_68 = F_42 ( V_13 -> V_16 . V_70 , V_30 ) ;
if ( V_68 )
return V_68 ;
break;
default:
F_4 ( L_47 , V_9 ,
( int ) V_13 -> type , V_30 -> V_10 ) ;
return - V_64 ;
}
if ( ! F_33 ( V_13 ) ) {
F_4 ( L_48 , V_9 ,
V_30 -> V_10 ) ;
V_68 = - V_64 ;
goto V_76;
}
V_13 -> V_75 . V_77 = V_30 ;
V_68 = F_48 ( NULL , & V_13 -> V_75 ) ;
if ( V_68 ) {
F_4 ( L_49 , V_9 ,
V_30 -> V_10 , V_68 ) ;
goto V_76;
}
return 0 ;
V_76:
F_43 ( V_13 ) ;
return V_68 ;
}
static void F_49 ( struct V_1 * V_2 )
{
T_1 V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_78 ; V_60 ++ )
F_44 ( & V_2 -> V_79 [ V_60 ] . V_75 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_80 )
return;
F_51 ( V_2 -> V_81 ) ;
F_49 ( V_2 ) ;
F_52 ( V_2 -> V_81 ) ;
V_2 -> V_81 = NULL ;
F_53 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
}
static bool F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
if ( ! F_1 ( V_2 ) )
return false ;
V_3 = & V_2 -> V_4 ;
if ( F_3 ( V_3 ) )
if ( ! F_17 ( V_3 , V_2 -> V_10 ) )
return false ;
return true ;
}
static struct V_74 *
F_55 ( struct V_82 * V_83 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
unsigned int V_84 = V_83 -> args [ 0 ] ;
if ( V_84 >= V_2 -> V_78 ) {
F_4 ( L_50 , V_9 , V_84 ) ;
return F_35 ( - V_64 ) ;
}
return & V_2 -> V_79 [ V_84 ] . V_75 ;
}
void T_2 F_56 ( struct V_1 * V_2 ,
struct V_85 * V_81 )
{
struct V_86 V_87 = { 0 } ;
T_3 V_6 ;
unsigned int V_60 ;
int V_68 ;
V_68 = F_57 ( V_81 , 0 , & V_87 ) ;
if ( V_68 ) {
F_4 ( L_51 , V_9 ,
V_81 -> V_10 ) ;
goto V_88;
}
V_6 = F_58 ( & V_87 ) ;
if ( V_6 > ( T_3 ) V_89 ) {
F_4 ( L_52 , V_9 ,
V_81 -> V_10 ) ;
goto V_88;
}
V_2 -> V_6 = ( T_1 ) V_6 ;
if ( ! F_54 ( V_2 ) ) {
F_4 ( L_53 , V_9 , V_81 -> V_10 ) ;
goto V_88;
}
V_2 -> V_80 = F_59 ( V_87 . V_90 , V_2 -> V_6 ) ;
if ( ! V_2 -> V_80 ) {
F_4 ( L_54 , V_9 ,
V_81 -> V_10 ) ;
goto V_88;
}
V_2 -> V_81 = F_60 ( V_81 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_78 ; V_60 ++ ) {
if ( ! V_2 -> V_79 [ V_60 ] . V_2 )
continue;
F_47 ( & V_2 -> V_79 [ V_60 ] ) ;
}
V_68 = F_61 ( V_81 , F_55 , V_2 ) ;
if ( V_68 ) {
F_4 ( L_55 , V_9 ,
V_81 -> V_10 , V_68 ) ;
goto V_88;
}
if ( ! F_62 ( V_2 ) )
F_4 ( L_56 , V_81 -> V_10 ) ;
return;
V_88:
F_50 ( V_2 ) ;
F_4 ( L_57 , V_81 -> V_10 ) ;
}
