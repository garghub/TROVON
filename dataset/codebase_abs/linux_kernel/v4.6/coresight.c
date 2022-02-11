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
F_3 ( V_7 ) -> V_25 ( V_7 ) ;
V_7 -> V_9 = false ;
}
}
}
void F_23 ( struct V_35 * V_36 )
{
struct V_37 * V_38 ;
struct V_6 * V_7 , * V_12 , * V_20 ;
F_24 (nd, path, link) {
V_7 = V_38 -> V_7 ;
switch ( V_7 -> type ) {
case V_39 :
case V_40 :
F_13 ( V_7 ) ;
break;
case V_10 :
break;
case V_41 :
V_12 = F_25 ( V_38 , V_42 ) -> V_7 ;
V_20 = F_26 ( V_38 , V_42 ) -> V_7 ;
F_18 ( V_7 , V_12 , V_20 ) ;
break;
default:
break;
}
}
}
int F_27 ( struct V_35 * V_36 , T_1 V_22 )
{
int V_23 = 0 ;
struct V_37 * V_38 ;
struct V_6 * V_7 , * V_12 , * V_20 ;
F_28 (nd, path, link) {
V_7 = V_38 -> V_7 ;
switch ( V_7 -> type ) {
case V_39 :
case V_40 :
V_23 = F_10 ( V_7 , V_22 ) ;
if ( V_23 )
goto V_43;
break;
case V_10 :
break;
case V_41 :
V_12 = F_25 ( V_38 , V_42 ) -> V_7 ;
V_20 = F_26 ( V_38 , V_42 ) -> V_7 ;
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
struct V_6 * F_29 ( struct V_35 * V_36 )
{
struct V_6 * V_7 ;
if ( ! V_36 )
return NULL ;
V_7 = F_30 ( V_36 , struct V_37 , V_42 ) -> V_7 ;
if ( V_7 -> type != V_39 &&
V_7 -> type != V_40 )
return NULL ;
return V_7 ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_35 * V_36 )
{
int V_13 ;
bool V_45 = false ;
struct V_37 * V_46 ;
struct V_14 * V_15 ;
if ( ( V_7 -> type == V_39 ||
V_7 -> type == V_40 ) && V_7 -> V_47 )
goto V_44;
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
V_15 = & V_7 -> V_17 [ V_13 ] ;
if ( F_31 ( V_15 -> V_18 , V_36 ) == 0 ) {
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
V_36 = F_32 ( sizeof( struct V_35 ) , V_49 ) ;
if ( ! V_36 )
return NULL ;
F_36 ( V_36 ) ;
if ( F_31 ( V_7 , V_36 ) ) {
F_37 ( V_36 ) ;
V_36 = NULL ;
}
return V_36 ;
}
void F_38 ( struct V_35 * V_36 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 , * V_51 ;
F_39 (nd, next, path, link) {
V_7 = V_38 -> V_7 ;
F_40 ( V_7 -> V_2 . V_12 ) ;
F_41 ( & V_38 -> V_42 ) ;
F_37 ( V_38 ) ;
}
F_37 ( V_36 ) ;
V_36 = NULL ;
}
int F_42 ( struct V_6 * V_7 )
{
int V_23 = 0 ;
int V_52 ;
struct V_35 * V_36 ;
F_43 ( & V_53 ) ;
if ( V_7 -> type != V_10 ) {
V_23 = - V_29 ;
F_7 ( & V_7 -> V_2 , L_4 , V_54 ) ;
goto V_44;
}
if ( V_7 -> V_9 )
goto V_44;
V_36 = F_35 ( V_7 ) ;
if ( ! V_36 ) {
F_44 ( L_5 ) ;
goto V_44;
}
V_23 = F_27 ( V_36 , V_55 ) ;
if ( V_23 )
goto V_56;
V_23 = F_20 ( V_7 , V_55 ) ;
if ( V_23 )
goto V_57;
V_52 = F_3 ( V_7 ) -> F_45 ( V_7 ) ;
F_46 ( V_58 , V_52 ) = V_36 ;
V_44:
F_47 ( & V_53 ) ;
return V_23 ;
V_57:
F_23 ( V_36 ) ;
V_56:
F_38 ( V_36 ) ;
goto V_44;
}
void F_48 ( struct V_6 * V_7 )
{
int V_52 ;
struct V_35 * V_36 ;
F_43 ( & V_53 ) ;
if ( V_7 -> type != V_10 ) {
F_7 ( & V_7 -> V_2 , L_4 , V_54 ) ;
goto V_44;
}
if ( ! V_7 -> V_9 )
goto V_44;
V_52 = F_3 ( V_7 ) -> F_45 ( V_7 ) ;
V_36 = F_46 ( V_58 , V_52 ) ;
F_22 ( V_7 ) ;
F_23 ( V_36 ) ;
F_38 ( V_36 ) ;
F_46 ( V_58 , V_52 ) = NULL ;
V_44:
F_47 ( & V_53 ) ;
}
static T_2 F_49 ( struct V_1 * V_2 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_50 ( V_61 , V_62 , L_6 , ( unsigned ) V_7 -> V_47 ) ;
}
static T_2 F_51 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
const char * V_61 , T_3 V_63 )
{
int V_23 ;
unsigned long V_64 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_23 = F_52 ( V_61 , 10 , & V_64 ) ;
if ( V_23 )
return V_23 ;
if ( V_64 )
V_7 -> V_47 = true ;
else
V_7 -> V_47 = false ;
return V_63 ;
}
static T_2 F_53 ( struct V_1 * V_2 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_50 ( V_61 , V_62 , L_6 , ( unsigned ) V_7 -> V_9 ) ;
}
static T_2 F_54 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
const char * V_61 , T_3 V_63 )
{
int V_23 = 0 ;
unsigned long V_64 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_23 = F_52 ( V_61 , 10 , & V_64 ) ;
if ( V_23 )
return V_23 ;
if ( V_64 ) {
V_23 = F_42 ( V_7 ) ;
if ( V_23 )
return V_23 ;
} else {
F_48 ( V_7 ) ;
}
return V_63 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_37 ( V_7 -> V_17 ) ;
F_37 ( V_7 -> V_24 ) ;
F_37 ( V_7 ) ;
}
static int F_56 ( struct V_1 * V_2 , void * V_3 )
{
int V_13 ;
bool V_65 = false ;
struct V_6 * V_7 , * V_8 ;
struct V_14 * V_15 ;
V_7 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( V_7 == V_8 )
return 0 ;
if ( ! V_8 -> V_66 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_8 -> V_16 ; V_13 ++ ) {
V_15 = & V_8 -> V_17 [ V_13 ] ;
if ( V_15 -> V_18 == NULL ) {
if ( ! strcmp ( F_8 ( & V_7 -> V_2 ) , V_15 -> V_67 ) ) {
V_15 -> V_18 = V_7 ;
} else {
V_65 = true ;
}
}
}
V_8 -> V_66 = V_65 ;
return 0 ;
}
static void F_57 ( struct V_6 * V_7 )
{
F_5 ( & V_11 , NULL ,
V_7 , F_56 ) ;
}
static int F_58 ( struct V_1 * V_2 , void * V_3 )
{
char * V_68 ;
struct V_6 * V_8 ;
V_68 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( V_68 && ! strcmp ( V_68 , F_8 ( & V_8 -> V_2 ) ) )
return 1 ;
return 0 ;
}
static void F_59 ( struct V_6 * V_7 )
{
int V_13 ;
struct V_1 * V_2 = NULL ;
struct V_14 * V_15 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
V_15 = & V_7 -> V_17 [ V_13 ] ;
V_2 = F_60 ( & V_11 , NULL ,
( void * ) V_15 -> V_67 ,
F_58 ) ;
if ( V_2 ) {
V_15 -> V_18 = F_2 ( V_2 ) ;
F_61 ( V_2 ) ;
} else {
V_7 -> V_66 = true ;
V_15 -> V_18 = NULL ;
}
}
}
static int F_62 ( struct V_1 * V_2 , void * V_3 )
{
int V_13 ;
struct V_6 * V_7 , * V_69 ;
struct V_14 * V_15 ;
V_7 = V_3 ;
V_69 = F_2 ( V_2 ) ;
if ( V_7 == V_69 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_16 ; V_13 ++ ) {
V_15 = & V_69 -> V_17 [ V_13 ] ;
if ( V_15 -> V_18 == NULL )
continue;
if ( ! strcmp ( F_8 ( & V_7 -> V_2 ) , V_15 -> V_67 ) ) {
V_69 -> V_66 = true ;
V_15 -> V_18 = NULL ;
break;
}
}
return 0 ;
}
static void F_63 ( struct V_6 * V_7 )
{
F_5 ( & V_11 , NULL ,
V_7 , F_62 ) ;
}
int F_64 ( void T_4 * V_70 , T_1 V_71 , int V_72 , int V_73 )
{
int V_13 ;
T_1 V_64 ;
for ( V_13 = V_74 ; V_13 > 0 ; V_13 -- ) {
V_64 = F_65 ( V_70 + V_71 ) ;
if ( V_73 ) {
if ( V_64 & F_66 ( V_72 ) )
return 0 ;
} else {
if ( ! ( V_64 & F_66 ( V_72 ) ) )
return 0 ;
}
if ( V_13 - 1 )
F_67 ( 1 ) ;
}
return - V_75 ;
}
static int T_5 F_68 ( void )
{
return F_69 ( & V_11 ) ;
}
struct V_6 * F_70 ( struct V_76 * V_77 )
{
int V_13 ;
int V_23 ;
int V_26 ;
int V_78 = 1 ;
T_6 * V_79 = NULL ;
struct V_6 * V_7 ;
struct V_14 * V_17 ;
V_7 = F_32 ( sizeof( * V_7 ) , V_49 ) ;
if ( ! V_7 ) {
V_23 = - V_50 ;
goto V_80;
}
if ( V_77 -> type == V_41 ||
V_77 -> type == V_40 ) {
V_26 = V_77 -> V_30 . V_26 ;
if ( V_26 == V_31 )
V_78 = V_77 -> V_81 -> V_34 ;
else if ( V_26 == V_32 )
V_78 = V_77 -> V_81 -> V_16 ;
}
V_79 = F_71 ( V_78 , sizeof( * V_79 ) , V_49 ) ;
if ( ! V_79 ) {
V_23 = - V_50 ;
goto V_82;
}
V_7 -> V_24 = V_79 ;
V_7 -> V_34 = V_77 -> V_81 -> V_34 ;
V_7 -> V_16 = V_77 -> V_81 -> V_16 ;
V_17 = F_71 ( V_7 -> V_16 , sizeof( * V_17 ) , V_49 ) ;
if ( ! V_17 ) {
V_23 = - V_50 ;
goto V_83;
}
for ( V_13 = 0 ; V_13 < V_7 -> V_16 ; V_13 ++ ) {
V_17 [ V_13 ] . V_21 = V_77 -> V_81 -> V_84 [ V_13 ] ;
V_17 [ V_13 ] . V_67 = V_77 -> V_81 -> V_85 [ V_13 ] ;
V_17 [ V_13 ] . V_19 = V_77 -> V_81 -> V_86 [ V_13 ] ;
}
V_7 -> V_17 = V_17 ;
V_7 -> type = V_77 -> type ;
V_7 -> V_30 = V_77 -> V_30 ;
V_7 -> V_87 = V_77 -> V_87 ;
V_7 -> V_66 = false ;
V_7 -> V_2 . type = & V_88 [ V_77 -> type ] ;
V_7 -> V_2 . V_89 = V_77 -> V_89 ;
V_7 -> V_2 . V_12 = V_77 -> V_2 ;
V_7 -> V_2 . V_90 = F_55 ;
V_7 -> V_2 . V_91 = & V_11 ;
F_72 ( & V_7 -> V_2 , L_7 , V_77 -> V_81 -> V_92 ) ;
V_23 = F_73 ( & V_7 -> V_2 ) ;
if ( V_23 )
goto V_93;
F_43 ( & V_53 ) ;
F_59 ( V_7 ) ;
F_57 ( V_7 ) ;
F_47 ( & V_53 ) ;
return V_7 ;
V_93:
F_37 ( V_17 ) ;
V_83:
F_37 ( V_79 ) ;
V_82:
F_37 ( V_7 ) ;
V_80:
return F_74 ( V_23 ) ;
}
void F_75 ( struct V_6 * V_7 )
{
F_63 ( V_7 ) ;
F_76 ( & V_7 -> V_2 ) ;
}
