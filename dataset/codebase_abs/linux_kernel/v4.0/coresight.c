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
static int F_6 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_6 * V_13 ;
struct V_14 * V_15 ;
V_13 = F_7 ( V_7 -> V_16 . V_17 ,
struct V_6 , V_16 ) ;
for ( V_12 = 0 ; V_12 < V_13 -> V_18 ; V_12 ++ ) {
V_15 = & V_13 -> V_19 [ V_12 ] ;
if ( V_15 -> V_20 == V_7 )
return V_15 -> V_21 ;
}
F_8 ( & V_7 -> V_2 , L_1 ,
F_9 ( & V_13 -> V_2 ) , F_9 ( & V_7 -> V_2 ) ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_6 * V_22 ;
struct V_14 * V_15 ;
V_22 = F_7 ( V_7 -> V_16 . V_23 ,
struct V_6 , V_16 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_18 ; V_12 ++ ) {
V_15 = & V_7 -> V_19 [ V_12 ] ;
if ( V_15 -> V_20 == V_22 )
return V_15 -> V_24 ;
}
F_8 ( & V_7 -> V_2 , L_2 ,
F_9 ( & V_7 -> V_2 ) , F_9 ( & V_22 -> V_2 ) ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
int V_25 ;
if ( ! V_7 -> V_9 ) {
if ( F_12 ( V_7 ) -> V_9 ) {
V_25 = F_12 ( V_7 ) -> V_9 ( V_7 ) ;
if ( V_25 )
return V_25 ;
}
V_7 -> V_9 = true ;
}
F_13 ( V_7 -> V_26 ) ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
if ( F_15 ( V_7 -> V_26 ) == 0 ) {
if ( F_12 ( V_7 ) -> V_27 ) {
F_12 ( V_7 ) -> V_27 ( V_7 ) ;
V_7 -> V_9 = false ;
}
}
}
static int F_16 ( struct V_6 * V_7 )
{
int V_25 ;
int V_28 ;
int V_29 , V_30 , V_24 ;
V_30 = F_6 ( V_7 ) ;
V_24 = F_10 ( V_7 ) ;
V_28 = V_7 -> V_31 . V_28 ;
if ( V_28 == V_32 )
V_29 = V_30 ;
else if ( V_28 == V_33 )
V_29 = V_24 ;
else
V_29 = 0 ;
if ( F_17 ( & V_7 -> V_26 [ V_29 ] ) == 1 ) {
if ( F_18 ( V_7 ) -> V_9 ) {
V_25 = F_18 ( V_7 ) -> V_9 ( V_7 , V_30 , V_24 ) ;
if ( V_25 )
return V_25 ;
}
}
V_7 -> V_9 = true ;
return 0 ;
}
static void F_19 ( struct V_6 * V_7 )
{
int V_12 , V_34 ;
int V_28 ;
int V_29 , V_30 , V_24 ;
V_30 = F_6 ( V_7 ) ;
V_24 = F_10 ( V_7 ) ;
V_28 = V_7 -> V_31 . V_28 ;
if ( V_28 == V_32 ) {
V_29 = V_30 ;
V_34 = V_7 -> V_35 ;
} else if ( V_28 == V_33 ) {
V_29 = V_24 ;
V_34 = V_7 -> V_18 ;
} else {
V_29 = 0 ;
V_34 = 1 ;
}
if ( F_15 ( & V_7 -> V_26 [ V_29 ] ) == 0 ) {
if ( F_18 ( V_7 ) -> V_27 )
F_18 ( V_7 ) -> V_27 ( V_7 , V_30 , V_24 ) ;
}
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ )
if ( F_20 ( & V_7 -> V_26 [ V_12 ] ) != 0 )
return;
V_7 -> V_9 = false ;
}
static int F_21 ( struct V_6 * V_7 )
{
int V_25 ;
if ( ! F_4 ( V_7 ) ) {
F_22 ( & V_7 -> V_2 , L_3 ,
F_3 ( V_7 ) -> V_4 ( V_7 ) ) ;
return - V_36 ;
}
if ( ! V_7 -> V_9 ) {
if ( F_3 ( V_7 ) -> V_9 ) {
V_25 = F_3 ( V_7 ) -> V_9 ( V_7 ) ;
if ( V_25 )
return V_25 ;
}
V_7 -> V_9 = true ;
}
F_13 ( V_7 -> V_26 ) ;
return 0 ;
}
static void F_23 ( struct V_6 * V_7 )
{
if ( F_15 ( V_7 -> V_26 ) == 0 ) {
if ( F_3 ( V_7 ) -> V_27 ) {
F_3 ( V_7 ) -> V_27 ( V_7 ) ;
V_7 -> V_9 = false ;
}
}
}
static int F_24 ( struct V_37 * V_38 )
{
int V_25 = 0 ;
struct V_6 * V_39 ;
F_25 (cd, path, path_link) {
if ( V_39 == F_26 ( V_38 , struct V_6 ,
V_16 ) ) {
V_25 = F_11 ( V_39 ) ;
} else if ( F_27 ( & V_39 -> V_16 , V_38 ) ) {
;
} else {
V_25 = F_16 ( V_39 ) ;
}
if ( V_25 )
goto V_40;
}
return 0 ;
V_40:
F_28 (cd, path, path_link) {
if ( V_39 == F_26 ( V_38 , struct V_6 ,
V_16 ) ) {
F_14 ( V_39 ) ;
} else if ( F_27 ( & V_39 -> V_16 , V_38 ) ) {
;
} else {
F_19 ( V_39 ) ;
}
}
return V_25 ;
}
static int F_29 ( struct V_37 * V_38 )
{
struct V_6 * V_39 ;
F_30 (cd, path, path_link) {
if ( V_39 == F_26 ( V_38 , struct V_6 ,
V_16 ) ) {
F_14 ( V_39 ) ;
} else if ( F_27 ( & V_39 -> V_16 , V_38 ) ) {
;
} else {
F_19 ( V_39 ) ;
}
}
return 0 ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_37 * V_38 ,
bool V_9 )
{
int V_12 , V_25 = - V_36 ;
struct V_14 * V_15 ;
F_32 ( & V_7 -> V_16 , V_38 ) ;
if ( V_7 -> type == V_41 && V_7 -> V_42 ) {
if ( V_9 )
V_25 = F_24 ( V_38 ) ;
else
V_25 = F_29 ( V_38 ) ;
} else {
for ( V_12 = 0 ; V_12 < V_7 -> V_18 ; V_12 ++ ) {
V_15 = & V_7 -> V_19 [ V_12 ] ;
if ( F_31 ( V_15 -> V_20 ,
V_38 , V_9 ) == 0 )
V_25 = 0 ;
}
}
if ( F_26 ( V_38 , struct V_6 , V_16 ) != V_7 )
F_8 ( & V_7 -> V_2 , L_4 , V_43 ) ;
F_33 ( & V_7 -> V_16 ) ;
return V_25 ;
}
int F_34 ( struct V_6 * V_7 )
{
int V_25 = 0 ;
F_35 ( V_38 ) ;
F_36 ( & V_44 ) ;
if ( V_7 -> type != V_10 ) {
V_25 = - V_36 ;
F_8 ( & V_7 -> V_2 , L_5 , V_43 ) ;
goto V_45;
}
if ( V_7 -> V_9 )
goto V_45;
if ( F_31 ( V_7 , & V_38 , true ) ) {
F_8 ( & V_7 -> V_2 , L_6 ) ;
goto V_45;
}
if ( F_21 ( V_7 ) )
F_8 ( & V_7 -> V_2 , L_7 ) ;
V_45:
F_37 ( & V_44 ) ;
return V_25 ;
}
void F_38 ( struct V_6 * V_7 )
{
F_35 ( V_38 ) ;
F_36 ( & V_44 ) ;
if ( V_7 -> type != V_10 ) {
F_8 ( & V_7 -> V_2 , L_5 , V_43 ) ;
goto V_45;
}
if ( ! V_7 -> V_9 )
goto V_45;
F_23 ( V_7 ) ;
if ( F_31 ( V_7 , & V_38 , false ) )
F_8 ( & V_7 -> V_2 , L_8 ) ;
V_45:
F_37 ( & V_44 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_40 ( V_48 , V_49 , L_9 , ( unsigned ) V_7 -> V_42 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
const char * V_48 , T_2 V_50 )
{
int V_25 ;
unsigned long V_51 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_25 = F_42 ( V_48 , 10 , & V_51 ) ;
if ( V_25 )
return V_25 ;
if ( V_51 )
V_7 -> V_42 = true ;
else
V_7 -> V_42 = false ;
return V_50 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_40 ( V_48 , V_49 , L_9 , ( unsigned ) V_7 -> V_9 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
const char * V_48 , T_2 V_50 )
{
int V_25 = 0 ;
unsigned long V_51 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_25 = F_42 ( V_48 , 10 , & V_51 ) ;
if ( V_25 )
return V_25 ;
if ( V_51 ) {
V_25 = F_34 ( V_7 ) ;
if ( V_25 )
return V_25 ;
} else {
F_38 ( V_7 ) ;
}
return V_50 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_46 ( V_7 ) ;
}
static int F_47 ( struct V_1 * V_2 , void * V_3 )
{
int V_12 ;
bool V_52 = false ;
struct V_6 * V_7 , * V_8 ;
struct V_14 * V_15 ;
V_7 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( V_7 == V_8 )
return 0 ;
if ( ! V_8 -> V_53 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_18 ; V_12 ++ ) {
V_15 = & V_8 -> V_19 [ V_12 ] ;
if ( V_15 -> V_20 == NULL ) {
if ( ! strcmp ( F_9 ( & V_7 -> V_2 ) , V_15 -> V_54 ) ) {
V_15 -> V_20 = V_7 ;
} else {
V_52 = true ;
}
}
}
V_8 -> V_53 = V_52 ;
return 0 ;
}
static void F_48 ( struct V_6 * V_7 )
{
F_5 ( & V_11 , NULL ,
V_7 , F_47 ) ;
}
static int F_49 ( struct V_1 * V_2 , void * V_3 )
{
char * V_55 ;
struct V_6 * V_8 ;
V_55 = V_3 ;
V_8 = F_2 ( V_2 ) ;
if ( ! strcmp ( V_55 , F_9 ( & V_8 -> V_2 ) ) )
return 1 ;
return 0 ;
}
static void F_50 ( struct V_6 * V_7 )
{
int V_12 ;
struct V_1 * V_2 = NULL ;
struct V_14 * V_15 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_18 ; V_12 ++ ) {
V_15 = & V_7 -> V_19 [ V_12 ] ;
V_2 = F_51 ( & V_11 , NULL ,
( void * ) V_15 -> V_54 ,
F_49 ) ;
if ( V_2 ) {
V_15 -> V_20 = F_2 ( V_2 ) ;
} else {
V_7 -> V_53 = true ;
V_15 -> V_20 = NULL ;
}
}
}
int F_52 ( void T_3 * V_56 , T_4 V_57 , int V_58 , int V_59 )
{
int V_12 ;
T_4 V_51 ;
for ( V_12 = V_60 ; V_12 > 0 ; V_12 -- ) {
V_51 = F_53 ( V_56 + V_57 ) ;
if ( V_59 ) {
if ( V_51 & F_54 ( V_58 ) )
return 0 ;
} else {
if ( ! ( V_51 & F_54 ( V_58 ) ) )
return 0 ;
}
if ( V_12 - 1 )
F_55 ( 1 ) ;
}
return - V_61 ;
}
static int T_5 F_56 ( void )
{
return F_57 ( & V_11 ) ;
}
struct V_6 * F_58 ( struct V_62 * V_63 )
{
int V_12 ;
int V_25 ;
int V_28 ;
int V_64 = 1 ;
T_6 * V_65 = NULL ;
struct V_6 * V_7 ;
struct V_14 * V_19 ;
V_7 = F_59 ( sizeof( * V_7 ) , V_66 ) ;
if ( ! V_7 ) {
V_25 = - V_67 ;
goto V_68;
}
if ( V_63 -> type == V_69 ||
V_63 -> type == V_70 ) {
V_28 = V_63 -> V_31 . V_28 ;
if ( V_28 == V_32 )
V_64 = V_63 -> V_71 -> V_35 ;
else if ( V_28 == V_33 )
V_64 = V_63 -> V_71 -> V_18 ;
}
V_65 = F_60 ( V_64 , sizeof( * V_65 ) , V_66 ) ;
if ( ! V_65 ) {
V_25 = - V_67 ;
goto V_72;
}
V_7 -> V_26 = V_65 ;
V_7 -> V_35 = V_63 -> V_71 -> V_35 ;
V_7 -> V_18 = V_63 -> V_71 -> V_18 ;
V_19 = F_60 ( V_7 -> V_18 , sizeof( * V_19 ) , V_66 ) ;
if ( ! V_19 ) {
V_25 = - V_67 ;
goto V_73;
}
for ( V_12 = 0 ; V_12 < V_7 -> V_18 ; V_12 ++ ) {
V_19 [ V_12 ] . V_24 = V_63 -> V_71 -> V_74 [ V_12 ] ;
V_19 [ V_12 ] . V_54 = V_63 -> V_71 -> V_75 [ V_12 ] ;
V_19 [ V_12 ] . V_21 = V_63 -> V_71 -> V_76 [ V_12 ] ;
}
V_7 -> V_19 = V_19 ;
V_7 -> type = V_63 -> type ;
V_7 -> V_31 = V_63 -> V_31 ;
V_7 -> V_77 = V_63 -> V_77 ;
V_7 -> V_53 = false ;
V_7 -> V_2 . type = & V_78 [ V_63 -> type ] ;
V_7 -> V_2 . V_79 = V_63 -> V_79 ;
V_7 -> V_2 . V_13 = V_63 -> V_2 ;
V_7 -> V_2 . V_80 = F_45 ;
V_7 -> V_2 . V_81 = & V_11 ;
F_61 ( & V_7 -> V_2 , L_10 , V_63 -> V_71 -> V_82 ) ;
V_25 = F_62 ( & V_7 -> V_2 ) ;
if ( V_25 )
goto V_83;
F_36 ( & V_44 ) ;
F_50 ( V_7 ) ;
F_48 ( V_7 ) ;
F_37 ( & V_44 ) ;
return V_7 ;
V_83:
F_46 ( V_19 ) ;
V_73:
F_46 ( V_65 ) ;
V_72:
F_46 ( V_7 ) ;
V_68:
return F_63 ( V_25 ) ;
}
void F_64 ( struct V_6 * V_7 )
{
F_36 ( & V_44 ) ;
F_46 ( V_7 -> V_19 ) ;
F_65 ( & V_7 -> V_2 ) ;
F_37 ( & V_44 ) ;
}
