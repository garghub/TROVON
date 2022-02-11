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
static void F_22 ( struct V_6 * V_7 )
{
if ( F_14 ( V_7 -> V_24 ) == 0 ) {
if ( F_3 ( V_7 ) -> V_25 ) {
F_3 ( V_7 ) -> V_25 ( V_7 , NULL ) ;
V_7 -> V_9 = false ;
}
}
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
static int F_31 ( struct V_6 * V_7 ,
struct V_35 * V_36 )
{
int V_13 ;
bool V_45 = false ;
struct V_37 * V_46 ;
if ( ( V_7 -> type == V_40 ||
V_7 -> type == V_39 ) && V_7 -> V_47 )
goto V_44;
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
struct V_6 * V_18 = V_7 -> V_17 [ V_13 ] . V_18 ;
if ( V_18 && F_31 ( V_18 , V_36 ) == 0 ) {
V_45 = true ;
break;
}
}
if ( ! V_45 )
return - V_48 ;
V_44:
V_46 = F_32 ( sizeof( struct V_37 ) , V_49 ) ;
if ( ! V_46 )
return - V_50 ;
V_46 -> V_7 = V_7 ;
F_33 ( & V_46 -> V_42 , V_36 ) ;
F_34 ( V_7 -> V_2 . V_12 ) ;
return 0 ;
}
struct V_35 * F_35 ( struct V_6 * V_7 )
{
struct V_35 * V_36 ;
int V_51 ;
V_36 = F_32 ( sizeof( struct V_35 ) , V_49 ) ;
if ( ! V_36 )
return F_36 ( - V_50 ) ;
F_37 ( V_36 ) ;
V_51 = F_31 ( V_7 , V_36 ) ;
if ( V_51 ) {
F_38 ( V_36 ) ;
return F_36 ( V_51 ) ;
}
return V_36 ;
}
void F_39 ( struct V_35 * V_36 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 , * V_52 ;
F_40 (nd, next, path, link) {
V_7 = V_38 -> V_7 ;
F_41 ( V_7 -> V_2 . V_12 ) ;
F_42 ( & V_38 -> V_42 ) ;
F_38 ( V_38 ) ;
}
F_38 ( V_36 ) ;
V_36 = NULL ;
}
static int F_43 ( struct V_6 * V_7 ,
const char * V_53 )
{
T_1 type , V_30 ;
type = V_7 -> type ;
V_30 = V_7 -> V_30 . V_54 ;
if ( type != V_10 ) {
F_7 ( & V_7 -> V_2 , L_4 , V_53 ) ;
return - V_29 ;
}
if ( V_30 != V_55 &&
V_30 != V_56 ) {
F_7 ( & V_7 -> V_2 , L_5 , V_53 ) ;
return - V_29 ;
}
return 0 ;
}
int F_44 ( struct V_6 * V_7 )
{
int V_57 , V_23 = 0 ;
struct V_35 * V_36 ;
F_45 ( & V_58 ) ;
V_23 = F_43 ( V_7 , V_59 ) ;
if ( V_23 )
goto V_44;
if ( V_7 -> V_9 )
goto V_44;
V_36 = F_35 ( V_7 ) ;
if ( F_46 ( V_36 ) ) {
F_47 ( L_6 ) ;
V_23 = F_48 ( V_36 ) ;
goto V_44;
}
V_23 = F_28 ( V_36 , V_60 ) ;
if ( V_23 )
goto V_61;
V_23 = F_20 ( V_7 , V_60 ) ;
if ( V_23 )
goto V_62;
switch ( V_7 -> V_30 . V_54 ) {
case V_55 :
V_57 = F_3 ( V_7 ) -> F_49 ( V_7 ) ;
F_50 ( V_63 , V_57 ) = V_36 ;
break;
case V_56 :
V_64 = V_36 ;
break;
default:
break;
}
V_44:
F_51 ( & V_58 ) ;
return V_23 ;
V_62:
F_23 ( V_36 ) ;
V_61:
F_39 ( V_36 ) ;
goto V_44;
}
void F_52 ( struct V_6 * V_7 )
{
int V_57 , V_23 ;
struct V_35 * V_36 = NULL ;
F_45 ( & V_58 ) ;
V_23 = F_43 ( V_7 , V_59 ) ;
if ( V_23 )
goto V_44;
if ( ! V_7 -> V_9 )
goto V_44;
switch ( V_7 -> V_30 . V_54 ) {
case V_55 :
V_57 = F_3 ( V_7 ) -> F_49 ( V_7 ) ;
V_36 = F_50 ( V_63 , V_57 ) ;
F_50 ( V_63 , V_57 ) = NULL ;
break;
case V_56 :
V_36 = V_64 ;
V_64 = NULL ;
break;
default:
break;
}
F_22 ( V_7 ) ;
F_23 ( V_36 ) ;
F_39 ( V_36 ) ;
V_44:
F_51 ( & V_58 ) ;
}
static T_2 F_53 ( struct V_1 * V_2 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_54 ( V_67 , V_68 , L_7 , V_7 -> V_47 ) ;
}
static T_2 F_55 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
const char * V_67 , T_3 V_69 )
{
int V_23 ;
unsigned long V_70 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_23 = F_56 ( V_67 , 10 , & V_70 ) ;
if ( V_23 )
return V_23 ;
if ( V_70 )
V_7 -> V_47 = true ;
else
V_7 -> V_47 = false ;
return V_69 ;
}
static T_2 F_57 ( struct V_1 * V_2 ,
struct V_65 * V_66 , char * V_67 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_54 ( V_67 , V_68 , L_7 , V_7 -> V_9 ) ;
}
static T_2 F_58 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
const char * V_67 , T_3 V_69 )
{
int V_23 = 0 ;
unsigned long V_70 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_23 = F_56 ( V_67 , 10 , & V_70 ) ;
if ( V_23 )
return V_23 ;
if ( V_70 ) {
V_23 = F_44 ( V_7 ) ;
if ( V_23 )
return V_23 ;
} else {
F_52 ( V_7 ) ;
}
return V_69 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_38 ( V_7 -> V_17 ) ;
F_38 ( V_7 -> V_24 ) ;
F_38 ( V_7 ) ;
}
static int F_60 ( struct V_1 * V_2 , void * V_3 )
{
int V_13 ;
bool V_71 = false ;
struct V_6 * V_7 , * V_8 ;
struct V_14 * V_15 ;
V_7 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( V_7 == V_8 )
return 0 ;
if ( ! V_8 -> V_72 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_8 -> V_16 ; V_13 ++ ) {
V_15 = & V_8 -> V_17 [ V_13 ] ;
if ( V_15 -> V_18 == NULL ) {
if ( V_15 -> V_73 &&
! strcmp ( F_8 ( & V_7 -> V_2 ) , V_15 -> V_73 ) ) {
V_15 -> V_18 = V_7 ;
} else {
V_71 = true ;
}
}
}
V_8 -> V_72 = V_71 ;
return 0 ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_5 ( & V_11 , NULL ,
V_7 , F_60 ) ;
}
static int F_62 ( struct V_1 * V_2 , void * V_3 )
{
char * V_74 ;
struct V_6 * V_8 ;
V_74 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( V_74 && ! strcmp ( V_74 , F_8 ( & V_8 -> V_2 ) ) )
return 1 ;
return 0 ;
}
static void F_63 ( struct V_6 * V_7 )
{
int V_13 ;
struct V_1 * V_2 = NULL ;
struct V_14 * V_15 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
V_15 = & V_7 -> V_17 [ V_13 ] ;
V_2 = F_64 ( & V_11 , NULL ,
( void * ) V_15 -> V_73 ,
F_62 ) ;
if ( V_2 ) {
V_15 -> V_18 = F_2 ( V_2 ) ;
F_65 ( V_2 ) ;
} else {
V_7 -> V_72 = true ;
V_15 -> V_18 = NULL ;
}
}
}
static int F_66 ( struct V_1 * V_2 , void * V_3 )
{
int V_13 ;
struct V_6 * V_7 , * V_75 ;
struct V_14 * V_15 ;
V_7 = V_3 ;
V_75 = F_2 ( V_2 ) ;
if ( V_7 == V_75 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_75 -> V_16 ; V_13 ++ ) {
V_15 = & V_75 -> V_17 [ V_13 ] ;
if ( V_15 -> V_18 == NULL )
continue;
if ( ! strcmp ( F_8 ( & V_7 -> V_2 ) , V_15 -> V_73 ) ) {
V_75 -> V_72 = true ;
V_15 -> V_18 = NULL ;
break;
}
}
return 0 ;
}
static void F_67 ( struct V_6 * V_7 )
{
F_5 ( & V_11 , NULL ,
V_7 , F_66 ) ;
}
int F_68 ( void T_4 * V_76 , T_1 V_77 , int V_78 , int V_79 )
{
int V_13 ;
T_1 V_70 ;
for ( V_13 = V_80 ; V_13 > 0 ; V_13 -- ) {
V_70 = F_69 ( V_76 + V_77 ) ;
if ( V_79 ) {
if ( V_70 & F_70 ( V_78 ) )
return 0 ;
} else {
if ( ! ( V_70 & F_70 ( V_78 ) ) )
return 0 ;
}
if ( V_13 - 1 )
F_71 ( 1 ) ;
}
return - V_81 ;
}
static int T_5 F_72 ( void )
{
return F_73 ( & V_11 ) ;
}
struct V_6 * F_74 ( struct V_82 * V_83 )
{
int V_13 ;
int V_23 ;
int V_26 ;
int V_84 = 1 ;
T_6 * V_85 = NULL ;
struct V_6 * V_7 ;
struct V_14 * V_17 = NULL ;
V_7 = F_32 ( sizeof( * V_7 ) , V_49 ) ;
if ( ! V_7 ) {
V_23 = - V_50 ;
goto V_86;
}
if ( V_83 -> type == V_41 ||
V_83 -> type == V_39 ) {
V_26 = V_83 -> V_30 . V_26 ;
if ( V_26 == V_31 )
V_84 = V_83 -> V_87 -> V_34 ;
else if ( V_26 == V_32 )
V_84 = V_83 -> V_87 -> V_16 ;
}
V_85 = F_75 ( V_84 , sizeof( * V_85 ) , V_49 ) ;
if ( ! V_85 ) {
V_23 = - V_50 ;
goto V_88;
}
V_7 -> V_24 = V_85 ;
V_7 -> V_34 = V_83 -> V_87 -> V_34 ;
V_7 -> V_16 = V_83 -> V_87 -> V_16 ;
if ( V_7 -> V_16 ) {
V_17 = F_75 ( V_7 -> V_16 , sizeof( * V_17 ) , V_49 ) ;
if ( ! V_17 ) {
V_23 = - V_50 ;
goto V_89;
}
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
V_17 [ V_13 ] . V_21 = V_83 -> V_87 -> V_90 [ V_13 ] ;
V_17 [ V_13 ] . V_73 = V_83 -> V_87 -> V_91 [ V_13 ] ;
V_17 [ V_13 ] . V_19 = V_83 -> V_87 -> V_92 [ V_13 ] ;
}
}
V_7 -> V_17 = V_17 ;
V_7 -> type = V_83 -> type ;
V_7 -> V_30 = V_83 -> V_30 ;
V_7 -> V_93 = V_83 -> V_93 ;
V_7 -> V_72 = false ;
V_7 -> V_2 . type = & V_94 [ V_83 -> type ] ;
V_7 -> V_2 . V_95 = V_83 -> V_95 ;
V_7 -> V_2 . V_12 = V_83 -> V_2 ;
V_7 -> V_2 . V_96 = F_59 ;
V_7 -> V_2 . V_97 = & V_11 ;
F_76 ( & V_7 -> V_2 , L_8 , V_83 -> V_87 -> V_98 ) ;
V_23 = F_77 ( & V_7 -> V_2 ) ;
if ( V_23 )
goto V_99;
F_45 ( & V_58 ) ;
F_63 ( V_7 ) ;
F_61 ( V_7 ) ;
F_51 ( & V_58 ) ;
return V_7 ;
V_99:
F_38 ( V_17 ) ;
V_89:
F_38 ( V_85 ) ;
V_88:
F_38 ( V_7 ) ;
V_86:
return F_36 ( V_23 ) ;
}
void F_78 ( struct V_6 * V_7 )
{
F_67 ( V_7 ) ;
F_79 ( & V_7 -> V_2 ) ;
}
