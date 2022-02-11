static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 , V_5 ;
struct V_6 * V_7 , * V_8 ;
V_7 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 == V_7 || ! V_8 -> V_9 ||
V_8 -> type != V_10 )
return 0 ;
V_4 = F_3 ( V_7 ) -> V_4 ( V_7 ) ;
V_5 = F_3 ( V_8 ) -> V_4 ( V_8 ) ;
if ( V_4 == V_5 )
return 1 ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 )
{
int V_4 = F_3 ( V_7 ) -> V_4 ( V_7 ) ;
if ( V_4 < 0 )
return 0 ;
return ! F_5 ( & V_11 , NULL ,
V_7 , F_1 ) ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_6 * V_12 )
{
int V_13 ;
struct V_14 * V_15 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_16 ; V_13 ++ ) {
V_15 = & V_12 -> V_17 [ V_13 ] ;
if ( V_15 -> V_18 == V_7 )
return V_15 -> V_19 ;
}
F_7 ( & V_7 -> V_2 , L_1 ,
F_8 ( & V_12 -> V_2 ) , F_8 ( & V_7 -> V_2 ) ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 ,
struct V_6 * V_20 )
{
int V_13 ;
struct V_14 * V_15 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
V_15 = & V_7 -> V_17 [ V_13 ] ;
if ( V_15 -> V_18 == V_20 )
return V_15 -> V_21 ;
}
F_7 ( & V_7 -> V_2 , L_2 ,
F_8 ( & V_7 -> V_2 ) , F_8 ( & V_20 -> V_2 ) ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , T_1 V_22 )
{
int V_23 ;
if ( ! V_7 -> V_9 ) {
if ( F_11 ( V_7 ) -> V_9 ) {
V_23 = F_11 ( V_7 ) -> V_9 ( V_7 , V_22 ) ;
if ( V_23 )
return V_23 ;
}
V_7 -> V_9 = true ;
}
F_12 ( V_7 -> V_24 ) ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 )
{
if ( F_14 ( V_7 -> V_24 ) == 0 ) {
if ( F_11 ( V_7 ) -> V_25 ) {
F_11 ( V_7 ) -> V_25 ( V_7 ) ;
V_7 -> V_9 = false ;
}
}
}
static int F_15 ( struct V_6 * V_7 ,
struct V_6 * V_12 ,
struct V_6 * V_20 )
{
int V_23 ;
int V_26 ;
int V_27 , V_28 , V_21 ;
if ( ! V_12 || ! V_20 )
return - V_29 ;
V_28 = F_6 ( V_7 , V_12 ) ;
V_21 = F_9 ( V_7 , V_20 ) ;
V_26 = V_7 -> V_30 . V_26 ;
if ( V_26 == V_31 )
V_27 = V_28 ;
else if ( V_26 == V_32 )
V_27 = V_21 ;
else
V_27 = 0 ;
if ( F_16 ( & V_7 -> V_24 [ V_27 ] ) == 1 ) {
if ( F_17 ( V_7 ) -> V_9 ) {
V_23 = F_17 ( V_7 ) -> V_9 ( V_7 , V_28 , V_21 ) ;
if ( V_23 )
return V_23 ;
}
}
V_7 -> V_9 = true ;
return 0 ;
}
static void F_18 ( struct V_6 * V_7 ,
struct V_6 * V_12 ,
struct V_6 * V_20 )
{
int V_13 , V_33 ;
int V_26 ;
int V_27 , V_28 , V_21 ;
if ( ! V_12 || ! V_20 )
return;
V_28 = F_6 ( V_7 , V_12 ) ;
V_21 = F_9 ( V_7 , V_20 ) ;
V_26 = V_7 -> V_30 . V_26 ;
if ( V_26 == V_31 ) {
V_27 = V_28 ;
V_33 = V_7 -> V_34 ;
} else if ( V_26 == V_32 ) {
V_27 = V_21 ;
V_33 = V_7 -> V_16 ;
} else {
V_27 = 0 ;
V_33 = 1 ;
}
if ( F_14 ( & V_7 -> V_24 [ V_27 ] ) == 0 ) {
if ( F_17 ( V_7 ) -> V_25 )
F_17 ( V_7 ) -> V_25 ( V_7 , V_28 , V_21 ) ;
}
for ( V_13 = 0 ; V_13 < V_33 ; V_13 ++ )
if ( F_19 ( & V_7 -> V_24 [ V_13 ] ) != 0 )
return;
V_7 -> V_9 = false ;
}
static int F_20 ( struct V_6 * V_7 , T_1 V_22 )
{
int V_23 ;
if ( ! F_4 ( V_7 ) ) {
F_21 ( & V_7 -> V_2 , L_3 ,
F_3 ( V_7 ) -> V_4 ( V_7 ) ) ;
return - V_29 ;
}
if ( ! V_7 -> V_9 ) {
if ( F_3 ( V_7 ) -> V_9 ) {
V_23 = F_3 ( V_7 ) -> V_9 ( V_7 , NULL , V_22 ) ;
if ( V_23 )
return V_23 ;
}
V_7 -> V_9 = true ;
}
F_12 ( V_7 -> V_24 ) ;
return 0 ;
}
static bool F_22 ( struct V_6 * V_7 )
{
if ( F_14 ( V_7 -> V_24 ) == 0 ) {
if ( F_3 ( V_7 ) -> V_25 )
F_3 ( V_7 ) -> V_25 ( V_7 , NULL ) ;
V_7 -> V_9 = false ;
}
return ! V_7 -> V_9 ;
}
void F_23 ( struct V_35 * V_36 )
{
T_1 type ;
struct V_37 * V_38 ;
struct V_6 * V_7 , * V_12 , * V_20 ;
F_24 (nd, path, link) {
V_7 = V_38 -> V_7 ;
type = V_7 -> type ;
if ( type == V_39 )
type = ( V_7 == F_25 ( V_36 ) ) ?
V_40 :
V_41 ;
switch ( type ) {
case V_40 :
F_13 ( V_7 ) ;
break;
case V_10 :
break;
case V_41 :
V_12 = F_26 ( V_38 , V_42 ) -> V_7 ;
V_20 = F_27 ( V_38 , V_42 ) -> V_7 ;
F_18 ( V_7 , V_12 , V_20 ) ;
break;
default:
break;
}
}
}
int F_28 ( struct V_35 * V_36 , T_1 V_22 )
{
int V_23 = 0 ;
T_1 type ;
struct V_37 * V_38 ;
struct V_6 * V_7 , * V_12 , * V_20 ;
F_29 (nd, path, link) {
V_7 = V_38 -> V_7 ;
type = V_7 -> type ;
if ( type == V_39 )
type = ( V_7 == F_25 ( V_36 ) ) ?
V_40 :
V_41 ;
switch ( type ) {
case V_40 :
V_23 = F_10 ( V_7 , V_22 ) ;
if ( V_23 )
goto V_43;
break;
case V_10 :
break;
case V_41 :
V_12 = F_26 ( V_38 , V_42 ) -> V_7 ;
V_20 = F_27 ( V_38 , V_42 ) -> V_7 ;
V_23 = F_15 ( V_7 , V_12 , V_20 ) ;
if ( V_23 )
goto V_43;
break;
default:
goto V_43;
}
}
V_44:
return V_23 ;
V_43:
F_23 ( V_36 ) ;
goto V_44;
}
struct V_6 * F_25 ( struct V_35 * V_36 )
{
struct V_6 * V_7 ;
if ( ! V_36 )
return NULL ;
V_7 = F_30 ( V_36 , struct V_37 , V_42 ) -> V_7 ;
if ( V_7 -> type != V_40 &&
V_7 -> type != V_39 )
return NULL ;
return V_7 ;
}
static int F_31 ( struct V_1 * V_2 , void * V_3 )
{
bool * V_45 = V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ( V_7 -> type == V_40 ||
V_7 -> type == V_39 ) &&
V_7 -> V_46 ) {
if ( * V_45 )
V_7 -> V_46 = false ;
return 1 ;
}
return 0 ;
}
struct V_6 * F_32 ( bool V_47 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_33 ( & V_11 , NULL , & V_47 ,
F_31 ) ;
return V_2 ? F_2 ( V_2 ) : NULL ;
}
static int F_34 ( struct V_6 * V_7 ,
struct V_6 * V_48 ,
struct V_35 * V_36 )
{
int V_13 ;
bool V_49 = false ;
struct V_37 * V_50 ;
if ( V_7 == V_48 )
goto V_44;
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
struct V_6 * V_18 = V_7 -> V_17 [ V_13 ] . V_18 ;
if ( V_18 &&
F_34 ( V_18 , V_48 , V_36 ) == 0 ) {
V_49 = true ;
break;
}
}
if ( ! V_49 )
return - V_51 ;
V_44:
V_50 = F_35 ( sizeof( struct V_37 ) , V_52 ) ;
if ( ! V_50 )
return - V_53 ;
V_50 -> V_7 = V_7 ;
F_36 ( & V_50 -> V_42 , V_36 ) ;
F_37 ( V_7 -> V_2 . V_12 ) ;
return 0 ;
}
struct V_35 * F_38 ( struct V_6 * V_54 ,
struct V_6 * V_48 )
{
struct V_35 * V_36 ;
int V_55 ;
if ( ! V_48 )
return F_39 ( - V_29 ) ;
V_36 = F_35 ( sizeof( struct V_35 ) , V_52 ) ;
if ( ! V_36 )
return F_39 ( - V_53 ) ;
F_40 ( V_36 ) ;
V_55 = F_34 ( V_54 , V_48 , V_36 ) ;
if ( V_55 ) {
F_41 ( V_36 ) ;
return F_39 ( V_55 ) ;
}
return V_36 ;
}
void F_42 ( struct V_35 * V_36 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 , * V_56 ;
F_43 (nd, next, path, link) {
V_7 = V_38 -> V_7 ;
F_44 ( V_7 -> V_2 . V_12 ) ;
F_45 ( & V_38 -> V_42 ) ;
F_41 ( V_38 ) ;
}
F_41 ( V_36 ) ;
V_36 = NULL ;
}
static int F_46 ( struct V_6 * V_7 ,
const char * V_57 )
{
T_1 type , V_30 ;
type = V_7 -> type ;
V_30 = V_7 -> V_30 . V_58 ;
if ( type != V_10 ) {
F_7 ( & V_7 -> V_2 , L_4 , V_57 ) ;
return - V_29 ;
}
if ( V_30 != V_59 &&
V_30 != V_60 ) {
F_7 ( & V_7 -> V_2 , L_5 , V_57 ) ;
return - V_29 ;
}
return 0 ;
}
int F_47 ( struct V_6 * V_7 )
{
int V_61 , V_23 = 0 ;
struct V_6 * V_48 ;
struct V_35 * V_36 ;
enum V_62 V_30 ;
V_30 = V_7 -> V_30 . V_58 ;
F_48 ( & V_63 ) ;
V_23 = F_46 ( V_7 , V_64 ) ;
if ( V_23 )
goto V_44;
if ( V_7 -> V_9 ) {
if ( V_30 == V_60 )
F_12 ( V_7 -> V_24 ) ;
goto V_44;
}
V_48 = F_32 ( false ) ;
if ( ! V_48 ) {
V_23 = - V_29 ;
goto V_44;
}
V_36 = F_38 ( V_7 , V_48 ) ;
if ( F_49 ( V_36 ) ) {
F_50 ( L_6 ) ;
V_23 = F_51 ( V_36 ) ;
goto V_44;
}
V_23 = F_28 ( V_36 , V_65 ) ;
if ( V_23 )
goto V_66;
V_23 = F_20 ( V_7 , V_65 ) ;
if ( V_23 )
goto V_67;
switch ( V_30 ) {
case V_59 :
V_61 = F_3 ( V_7 ) -> F_52 ( V_7 ) ;
F_53 ( V_68 , V_61 ) = V_36 ;
break;
case V_60 :
V_69 = V_36 ;
break;
default:
break;
}
V_44:
F_54 ( & V_63 ) ;
return V_23 ;
V_67:
F_23 ( V_36 ) ;
V_66:
F_42 ( V_36 ) ;
goto V_44;
}
void F_55 ( struct V_6 * V_7 )
{
int V_61 , V_23 ;
struct V_35 * V_36 = NULL ;
F_48 ( & V_63 ) ;
V_23 = F_46 ( V_7 , V_64 ) ;
if ( V_23 )
goto V_44;
if ( ! V_7 -> V_9 || ! F_22 ( V_7 ) )
goto V_44;
switch ( V_7 -> V_30 . V_58 ) {
case V_59 :
V_61 = F_3 ( V_7 ) -> F_52 ( V_7 ) ;
V_36 = F_53 ( V_68 , V_61 ) ;
F_53 ( V_68 , V_61 ) = NULL ;
break;
case V_60 :
V_36 = V_69 ;
V_69 = NULL ;
break;
default:
break;
}
F_23 ( V_36 ) ;
F_42 ( V_36 ) ;
V_44:
F_54 ( & V_63 ) ;
}
static T_2 F_56 ( struct V_1 * V_2 ,
struct V_70 * V_71 , char * V_72 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_57 ( V_72 , V_73 , L_7 , V_7 -> V_46 ) ;
}
static T_2 F_58 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
const char * V_72 , T_3 V_74 )
{
int V_23 ;
unsigned long V_75 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_23 = F_59 ( V_72 , 10 , & V_75 ) ;
if ( V_23 )
return V_23 ;
if ( V_75 )
V_7 -> V_46 = true ;
else
V_7 -> V_46 = false ;
return V_74 ;
}
static T_2 F_60 ( struct V_1 * V_2 ,
struct V_70 * V_71 , char * V_72 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_57 ( V_72 , V_73 , L_7 , V_7 -> V_9 ) ;
}
static T_2 F_61 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
const char * V_72 , T_3 V_74 )
{
int V_23 = 0 ;
unsigned long V_75 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_23 = F_59 ( V_72 , 10 , & V_75 ) ;
if ( V_23 )
return V_23 ;
if ( V_75 ) {
V_23 = F_47 ( V_7 ) ;
if ( V_23 )
return V_23 ;
} else {
F_55 ( V_7 ) ;
}
return V_74 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_41 ( V_7 -> V_17 ) ;
F_41 ( V_7 -> V_24 ) ;
F_41 ( V_7 ) ;
}
static int F_63 ( struct V_1 * V_2 , void * V_3 )
{
int V_13 ;
bool V_76 = false ;
struct V_6 * V_7 , * V_8 ;
struct V_14 * V_15 ;
V_7 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( V_7 == V_8 )
return 0 ;
if ( ! V_8 -> V_77 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_8 -> V_16 ; V_13 ++ ) {
V_15 = & V_8 -> V_17 [ V_13 ] ;
if ( V_15 -> V_18 == NULL ) {
if ( V_15 -> V_78 &&
! strcmp ( F_8 ( & V_7 -> V_2 ) , V_15 -> V_78 ) ) {
V_15 -> V_18 = V_7 ;
} else {
V_76 = true ;
}
}
}
V_8 -> V_77 = V_76 ;
return 0 ;
}
static void F_64 ( struct V_6 * V_7 )
{
F_5 ( & V_11 , NULL ,
V_7 , F_63 ) ;
}
static int F_65 ( struct V_1 * V_2 , void * V_3 )
{
char * V_79 ;
struct V_6 * V_8 ;
V_79 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( V_79 && ! strcmp ( V_79 , F_8 ( & V_8 -> V_2 ) ) )
return 1 ;
return 0 ;
}
static void F_66 ( struct V_6 * V_7 )
{
int V_13 ;
struct V_1 * V_2 = NULL ;
struct V_14 * V_15 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
V_15 = & V_7 -> V_17 [ V_13 ] ;
V_2 = F_33 ( & V_11 , NULL ,
( void * ) V_15 -> V_78 ,
F_65 ) ;
if ( V_2 ) {
V_15 -> V_18 = F_2 ( V_2 ) ;
F_67 ( V_2 ) ;
} else {
V_7 -> V_77 = true ;
V_15 -> V_18 = NULL ;
}
}
}
static int F_68 ( struct V_1 * V_2 , void * V_3 )
{
int V_13 ;
struct V_6 * V_7 , * V_80 ;
struct V_14 * V_15 ;
V_7 = V_3 ;
V_80 = F_2 ( V_2 ) ;
if ( V_7 == V_80 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_80 -> V_16 ; V_13 ++ ) {
V_15 = & V_80 -> V_17 [ V_13 ] ;
if ( V_15 -> V_18 == NULL )
continue;
if ( ! strcmp ( F_8 ( & V_7 -> V_2 ) , V_15 -> V_78 ) ) {
V_80 -> V_77 = true ;
V_15 -> V_18 = NULL ;
break;
}
}
return 0 ;
}
static void F_69 ( struct V_6 * V_7 )
{
F_5 ( & V_11 , NULL ,
V_7 , F_68 ) ;
}
int F_70 ( void T_4 * V_81 , T_1 V_82 , int V_83 , int V_84 )
{
int V_13 ;
T_1 V_75 ;
for ( V_13 = V_85 ; V_13 > 0 ; V_13 -- ) {
V_75 = F_71 ( V_81 + V_82 ) ;
if ( V_84 ) {
if ( V_75 & F_72 ( V_83 ) )
return 0 ;
} else {
if ( ! ( V_75 & F_72 ( V_83 ) ) )
return 0 ;
}
if ( V_13 - 1 )
F_73 ( 1 ) ;
}
return - V_86 ;
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_11 ) ;
}
struct V_6 * F_76 ( struct V_87 * V_88 )
{
int V_13 ;
int V_23 ;
int V_26 ;
int V_89 = 1 ;
T_6 * V_90 = NULL ;
struct V_6 * V_7 ;
struct V_14 * V_17 = NULL ;
V_7 = F_35 ( sizeof( * V_7 ) , V_52 ) ;
if ( ! V_7 ) {
V_23 = - V_53 ;
goto V_91;
}
if ( V_88 -> type == V_41 ||
V_88 -> type == V_39 ) {
V_26 = V_88 -> V_30 . V_26 ;
if ( V_26 == V_31 )
V_89 = V_88 -> V_92 -> V_34 ;
else if ( V_26 == V_32 )
V_89 = V_88 -> V_92 -> V_16 ;
}
V_90 = F_77 ( V_89 , sizeof( * V_90 ) , V_52 ) ;
if ( ! V_90 ) {
V_23 = - V_53 ;
goto V_93;
}
V_7 -> V_24 = V_90 ;
V_7 -> V_34 = V_88 -> V_92 -> V_34 ;
V_7 -> V_16 = V_88 -> V_92 -> V_16 ;
if ( V_7 -> V_16 ) {
V_17 = F_77 ( V_7 -> V_16 , sizeof( * V_17 ) , V_52 ) ;
if ( ! V_17 ) {
V_23 = - V_53 ;
goto V_94;
}
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
V_17 [ V_13 ] . V_21 = V_88 -> V_92 -> V_95 [ V_13 ] ;
V_17 [ V_13 ] . V_78 = V_88 -> V_92 -> V_96 [ V_13 ] ;
V_17 [ V_13 ] . V_19 = V_88 -> V_92 -> V_97 [ V_13 ] ;
}
}
V_7 -> V_17 = V_17 ;
V_7 -> type = V_88 -> type ;
V_7 -> V_30 = V_88 -> V_30 ;
V_7 -> V_98 = V_88 -> V_98 ;
V_7 -> V_77 = false ;
V_7 -> V_2 . type = & V_99 [ V_88 -> type ] ;
V_7 -> V_2 . V_100 = V_88 -> V_100 ;
V_7 -> V_2 . V_12 = V_88 -> V_2 ;
V_7 -> V_2 . V_101 = F_62 ;
V_7 -> V_2 . V_102 = & V_11 ;
F_78 ( & V_7 -> V_2 , L_8 , V_88 -> V_92 -> V_103 ) ;
V_23 = F_79 ( & V_7 -> V_2 ) ;
if ( V_23 )
goto V_104;
F_48 ( & V_63 ) ;
F_66 ( V_7 ) ;
F_64 ( V_7 ) ;
F_54 ( & V_63 ) ;
return V_7 ;
V_104:
F_41 ( V_17 ) ;
V_94:
F_41 ( V_90 ) ;
V_93:
F_41 ( V_7 ) ;
V_91:
return F_39 ( V_23 ) ;
}
void F_80 ( struct V_6 * V_7 )
{
F_69 ( V_7 ) ;
F_81 ( & V_7 -> V_2 ) ;
}
