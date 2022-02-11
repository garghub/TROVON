static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_6 * V_7 ;
struct V_8 * div ;
if ( V_2 -> type != V_9 )
return false ;
V_7 = & V_4 -> V_7 ;
if ( V_7 -> V_10 && F_2 ( V_7 ) )
return true ;
div = & V_4 -> div ;
if ( ! F_3 ( div ) )
return false ;
if ( ! F_4 ( div ) )
return true ;
div = & V_4 -> V_11 ;
return F_3 ( div ) && ! F_4 ( div ) ;
}
static bool F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_8 * div ;
struct V_6 * V_7 ;
struct V_14 * V_15 ;
const char * V_16 ;
T_1 V_17 ;
T_1 V_18 ;
F_6 ( V_2 -> type != V_9 ) ;
V_4 = V_2 -> V_5 . V_4 ;
V_16 = V_2 -> V_16 ;
V_17 = V_2 -> V_19 -> V_17 ;
V_18 = V_17 - sizeof( T_1 ) ;
V_18 = F_7 ( V_18 , sizeof( T_1 ) ) ;
V_13 = & V_4 -> V_13 ;
if ( F_8 ( V_13 ) ) {
if ( V_13 -> V_20 > V_18 ) {
F_9 ( L_1 ,
V_21 , V_16 , V_13 -> V_20 , V_18 ) ;
return false ;
}
}
div = & V_4 -> div ;
if ( F_3 ( div ) ) {
if ( div -> V_5 . V_22 . V_20 > V_18 ) {
F_9 ( L_2 ,
V_21 , V_16 , div -> V_5 . V_22 . V_20 , V_18 ) ;
return false ;
}
}
div = & V_4 -> V_11 ;
if ( F_3 ( div ) ) {
if ( div -> V_5 . V_22 . V_20 > V_18 ) {
F_9 ( L_3
L_4 ,
V_21 , V_16 , div -> V_5 . V_22 . V_20 , V_18 ) ;
return false ;
}
}
V_7 = & V_4 -> V_7 ;
if ( F_2 ( V_7 ) ) {
if ( V_7 -> V_20 > V_18 ) {
F_9 ( L_5 ,
V_21 , V_16 , V_7 -> V_20 , V_18 ) ;
return false ;
}
}
V_15 = & V_4 -> V_15 ;
if ( F_10 ( V_15 ) ) {
if ( V_15 -> V_20 > V_18 ) {
F_9 ( L_6 ,
V_21 , V_16 , V_15 -> V_20 , V_18 ) ;
return false ;
}
}
V_15 = & V_4 -> V_23 ;
if ( F_10 ( V_15 ) ) {
if ( V_15 -> V_20 > V_18 ) {
F_9 ( L_7 ,
V_21 , V_16 , V_15 -> V_20 , V_18 ) ;
return false ;
}
}
return true ;
}
static bool F_11 ( T_1 V_24 , const char * V_25 ,
const char * V_26 )
{
T_1 V_18 = V_27 * sizeof( T_1 ) - 1 ;
if ( V_24 > V_18 ) {
F_9 ( L_8 , V_21 ,
V_25 , V_26 , V_24 , V_18 ) ;
return false ;
}
return true ;
}
static bool F_12 ( T_1 V_28 , T_1 V_29 , const char * V_25 ,
const char * V_26 )
{
T_1 V_18 = V_27 * sizeof( T_1 ) ;
if ( ! V_29 ) {
F_9 ( L_9 , V_21 ,
V_25 , V_26 ) ;
return false ;
}
if ( V_28 + V_29 > V_18 ) {
F_9 ( L_10 , V_21 ,
V_25 , V_26 , V_28 , V_29 , V_18 ) ;
return false ;
}
return true ;
}
static bool F_13 ( struct V_12 * V_13 , const char * V_25 ,
const char * V_26 )
{
if ( ! F_11 ( V_13 -> V_30 , L_11 , V_26 ) )
return false ;
if ( F_14 ( V_13 ) ) {
if ( ! F_11 ( V_13 -> V_31 , L_12 , V_26 ) )
return false ;
if ( F_15 ( V_13 ) ) {
if ( ! F_11 ( V_13 -> V_32 ,
L_13 ,
V_26 ) )
return false ;
}
} else {
F_6 ( ! F_15 ( V_13 ) ) ;
}
return true ;
}
static bool F_16 ( struct V_6 * V_7 , const char * V_25 ,
const char * V_26 )
{
if ( ! F_12 ( V_7 -> V_28 , V_7 -> V_29 , V_25 , V_26 ) )
return false ;
if ( V_7 -> V_10 ) {
T_1 V_33 ;
T_1 V_18 ;
V_33 = V_7 -> V_34 [ V_7 -> V_10 - 1 ] ;
V_18 = ( 1 << V_7 -> V_29 ) - 1 ;
if ( V_33 > V_18 ) {
F_9 ( L_14
L_15 ,
V_21 , V_26 , V_33 ,
V_7 -> V_29 ) ;
return false ;
}
} else {
F_17 ( L_16 ,
V_21 , V_26 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 -> V_34 ) ;
V_7 -> V_34 = NULL ;
}
return true ;
}
static bool F_20 ( struct V_8 * div , const char * V_25 ,
const char * V_26 )
{
if ( F_4 ( div ) ) {
if ( div -> V_5 . V_35 == 0 ) {
F_9 ( L_17 , V_21 ,
V_25 , V_26 ) ;
return false ;
}
return true ;
}
if ( ! F_12 ( div -> V_5 . V_22 . V_28 , div -> V_5 . V_22 . V_29 ,
V_25 , V_26 ) )
return false ;
if ( F_21 ( div ) )
if ( div -> V_5 . V_22 . V_36 > div -> V_5 . V_22 . V_29 ) {
F_17 ( L_18 ,
V_21 , V_25 , V_26 ,
div -> V_5 . V_22 . V_36 , div -> V_5 . V_22 . V_29 ) ;
return false ;
}
return true ;
}
static bool F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_8 * div ;
struct V_8 * V_11 ;
T_1 V_18 ;
F_6 ( V_2 -> type != V_9 ) ;
if ( ! F_3 ( & V_4 -> div ) || ! F_3 ( & V_4 -> V_11 ) )
return true ;
div = & V_4 -> div ;
V_11 = & V_4 -> V_11 ;
if ( F_4 ( div ) || F_4 ( V_11 ) )
return true ;
V_18 = V_27 * sizeof( T_1 ) ;
return div -> V_5 . V_22 . V_36 + V_11 -> V_5 . V_22 . V_36 <= V_18 ;
}
static bool F_23 ( struct V_14 * V_15 , const char * V_25 ,
const char * V_26 )
{
return F_11 ( V_15 -> V_37 , V_25 , V_26 ) ;
}
static bool
F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_6 * V_7 ;
struct V_8 * div ;
struct V_8 * V_11 ;
struct V_14 * V_15 ;
const char * V_16 ;
F_6 ( V_2 -> type != V_9 ) ;
if ( ! F_5 ( V_2 ) )
return false ;
V_4 = V_2 -> V_5 . V_4 ;
V_16 = V_2 -> V_16 ;
V_13 = & V_4 -> V_13 ;
if ( F_8 ( V_13 ) && ! F_13 ( V_13 , L_19 , V_16 ) )
return false ;
V_7 = & V_4 -> V_7 ;
if ( F_2 ( V_7 ) ) {
if ( ! F_16 ( V_7 , L_20 , V_16 ) )
return false ;
} else if ( V_7 -> V_10 > 1 ) {
F_9 ( L_21 ,
V_21 , V_16 ) ;
return false ;
}
div = & V_4 -> div ;
V_11 = & V_4 -> V_11 ;
if ( F_3 ( div ) ) {
if ( ! F_20 ( div , L_22 , V_16 ) )
return false ;
if ( F_3 ( V_11 ) )
if ( ! F_20 ( V_11 , L_23 , V_16 ) )
return false ;
} else if ( F_3 ( V_11 ) ) {
F_9 ( L_24 , V_21 ,
V_16 ) ;
return false ;
}
V_15 = & V_4 -> V_15 ;
if ( F_10 ( V_15 ) ) {
if ( ! F_23 ( V_15 , L_25 , V_16 ) )
return false ;
if ( F_10 ( & V_4 -> V_23 ) ) {
if ( ! F_23 ( V_15 , L_26 , V_16 ) ) {
return false ;
}
}
if ( ! F_1 ( V_2 ) ) {
F_17 ( L_27 ,
V_21 , V_16 ) ;
F_25 ( V_15 ) ;
}
} else if ( F_10 ( & V_4 -> V_23 ) ) {
F_9 ( L_28 , V_21 ,
V_16 ) ;
return false ;
} else if ( F_1 ( V_2 ) ) {
F_9 ( L_29 , V_21 ,
V_16 ) ;
return false ;
}
return F_22 ( V_2 ) ;
}
static bool F_26 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_9 :
if ( ! F_24 ( V_2 ) )
return false ;
break;
default:
F_9 ( L_30 , V_21 ,
( int ) V_2 -> type ) ;
return false ;
}
return true ;
}
static T_1 * F_27 ( const char * V_38 [] ,
T_1 * V_39 , const char * * * V_40 )
{
static const char * * V_41 ;
static T_1 * V_34 ;
const char * * clock ;
T_1 V_10 ;
T_1 V_42 = 0 ;
T_1 V_43 ;
T_1 V_44 ;
T_1 V_45 ;
* V_39 = 0 ;
* V_40 = NULL ;
if ( ! V_38 )
return NULL ;
for ( clock = V_38 ; * clock ; clock ++ )
if ( * clock == V_46 )
V_42 ++ ;
V_43 = ( T_1 ) ( clock - V_38 ) ;
V_10 = V_43 - V_42 ;
if ( ! V_10 )
return NULL ;
if ( V_10 > V_47 ) {
F_9 ( L_31 , V_21 ,
V_10 , V_47 ) ;
return F_28 ( - V_48 ) ;
}
V_41 = F_29 ( V_10 * sizeof( V_41 ) , V_49 ) ;
if ( ! V_41 ) {
F_9 ( L_32 , V_21 ,
V_10 ) ;
return F_28 ( - V_50 ) ;
}
V_34 = F_29 ( V_10 * sizeof( * V_34 ) , V_49 ) ;
if ( ! V_34 ) {
F_9 ( L_33 , V_21 ,
V_10 ) ;
F_19 ( V_41 ) ;
return F_28 ( - V_50 ) ;
}
for ( V_44 = 0 , V_45 = 0 ; V_44 < V_43 ; V_44 ++ ) {
if ( V_38 [ V_44 ] != V_46 ) {
V_41 [ V_45 ] = V_38 [ V_44 ] ;
V_34 [ V_45 ] = V_44 ;
V_45 ++ ;
}
}
* V_40 = V_41 ;
* V_39 = V_10 ;
return V_34 ;
}
static int
F_30 ( const char * * V_38 , struct V_6 * V_7 ,
struct V_51 * V_52 )
{
const char * * V_41 = NULL ;
T_1 V_10 = 0 ;
T_1 * V_34 ;
V_34 = F_27 ( V_38 , & V_10 , & V_41 ) ;
if ( F_31 ( V_34 ) ) {
int V_53 = F_32 ( V_34 ) ;
F_9 ( L_34 ,
V_21 , V_52 -> V_16 , V_53 ) ;
return V_53 ;
}
V_52 -> V_41 = V_41 ;
V_52 -> V_54 = V_10 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_34 = V_34 ;
return 0 ;
}
static void F_33 ( struct V_6 * V_7 ,
struct V_51 * V_52 )
{
F_19 ( V_7 -> V_34 ) ;
V_7 -> V_34 = NULL ;
V_7 -> V_10 = 0 ;
V_52 -> V_54 = 0 ;
F_19 ( V_52 -> V_41 ) ;
V_52 -> V_41 = NULL ;
}
static void F_34 ( struct V_3 * V_55 ,
struct V_51 * V_52 )
{
F_33 ( & V_55 -> V_7 , V_52 ) ;
V_52 -> V_56 = NULL ;
}
static int F_35 ( struct V_57 * V_19 , struct V_3 * V_55 ,
struct V_51 * V_52 )
{
V_52 -> V_56 = & V_58 ;
V_52 -> V_59 = V_60 ;
return F_30 ( V_55 -> V_38 , & V_55 -> V_7 , V_52 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_9 :
F_34 ( V_2 -> V_5 . V_55 , & V_2 -> V_52 ) ;
break;
default:
break;
}
V_2 -> V_5 . V_55 = NULL ;
V_2 -> type = V_61 ;
}
static void F_37 ( struct V_62 * V_62 )
{
struct V_63 * V_64 ;
struct V_1 * V_2 ;
if ( ! V_62 )
return;
V_64 = F_38 ( V_62 ) ;
if ( ! V_64 ) {
F_9 ( L_35 , V_21 , V_62 ) ;
return;
}
F_39 ( V_62 ) ;
V_2 = F_40 ( V_64 ) ;
F_36 ( V_2 ) ;
}
struct V_62 * F_41 ( struct V_57 * V_19 , const char * V_16 ,
enum V_65 type , void * V_55 )
{
struct V_1 * V_2 ;
struct V_51 * V_52 ;
struct V_62 * V_62 = NULL ;
V_2 = F_42 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 ) {
F_9 ( L_36 , V_21 ,
V_16 ) ;
return NULL ;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_16 = V_16 ;
V_52 = & V_2 -> V_52 ;
V_52 -> V_16 = V_16 ;
switch ( type ) {
case V_9 :
if ( F_35 ( V_19 , V_55 , V_52 ) )
goto V_66;
break;
default:
V_55 = NULL ;
break;
}
V_2 -> type = type ;
V_2 -> V_5 . V_55 = V_55 ;
if ( ! F_26 ( V_2 ) ) {
F_9 ( L_37 , V_21 , V_16 ) ;
goto V_67;
}
V_2 -> V_64 . V_68 = V_52 ;
V_62 = F_43 ( NULL , & V_2 -> V_64 ) ;
if ( F_31 ( V_62 ) ) {
F_9 ( L_38 , V_21 ,
V_16 , F_32 ( V_62 ) ) ;
goto V_67;
}
F_6 ( ! V_62 ) ;
return V_62 ;
V_67:
F_36 ( V_2 ) ;
V_66:
F_19 ( V_2 ) ;
return NULL ;
}
static void F_44 ( struct V_57 * V_19 )
{
T_1 V_44 ;
for ( V_44 = 0 ; V_44 < V_19 -> V_55 . V_69 ; V_44 ++ )
F_37 ( V_19 -> V_55 . V_70 [ V_44 ] ) ;
F_19 ( V_19 -> V_55 . V_70 ) ;
}
static void F_45 ( struct V_57 * V_19 )
{
if ( ! V_19 )
return;
if ( ! V_19 -> V_71 )
goto V_72;
F_46 ( V_19 -> V_73 ) ;
F_44 ( V_19 ) ;
F_47 ( & V_19 -> V_74 ) ;
F_48 ( V_19 -> V_73 ) ;
F_49 ( V_19 -> V_71 ) ;
V_72:
F_19 ( V_19 -> V_16 ) ;
F_19 ( V_19 ) ;
}
void T_2 F_50 ( struct V_75 * V_73 ,
int (* F_51)( struct V_57 * ) )
{
struct V_57 * V_19 ;
struct V_76 V_77 = { 0 } ;
T_3 V_17 ;
int V_53 ;
V_19 = F_42 ( sizeof( * V_19 ) , V_49 ) ;
if ( V_19 )
V_19 -> V_16 = F_52 ( V_73 -> V_16 , V_49 ) ;
if ( ! V_19 || ! V_19 -> V_16 ) {
F_9 ( L_39 ,
V_21 , V_73 -> V_16 ) ;
F_19 ( V_19 ) ;
return;
}
V_53 = F_53 ( V_73 , 0 , & V_77 ) ;
if ( V_53 ) {
F_9 ( L_40 , V_21 ,
V_73 -> V_16 ) ;
goto V_78;
}
V_17 = F_54 ( & V_77 ) ;
if ( V_17 > ( T_3 ) V_79 ) {
F_9 ( L_41 , V_21 ,
V_73 -> V_16 ) ;
goto V_78;
}
V_19 -> V_17 = ( T_1 ) V_17 ;
V_19 -> V_71 = F_55 ( V_77 . V_80 , V_19 -> V_17 ) ;
if ( ! V_19 -> V_71 ) {
F_9 ( L_42 , V_21 ,
V_73 -> V_16 ) ;
goto V_78;
}
F_56 ( & V_19 -> V_81 ) ;
F_57 ( & V_19 -> V_74 ) ;
V_19 -> V_73 = F_58 ( V_73 ) ;
F_59 ( & V_19 -> V_74 , & V_82 ) ;
if ( F_51 ( V_19 ) )
goto V_78;
V_53 = F_60 ( V_73 , V_83 , & V_19 -> V_55 ) ;
if ( V_53 ) {
F_9 ( L_43 , V_21 ,
V_73 -> V_16 , V_53 ) ;
goto V_78;
}
if ( ! F_61 ( V_19 ) )
F_9 ( L_44 , V_73 -> V_16 ) ;
return;
V_78:
F_45 ( V_19 ) ;
F_9 ( L_45 , V_73 -> V_16 ) ;
}
