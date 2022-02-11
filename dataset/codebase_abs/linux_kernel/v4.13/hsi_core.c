static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * T_2 V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , F_2 ( V_2 ) ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_4 ( V_7 , L_2 , F_2 ( V_2 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( F_6 ( V_2 , V_9 ) )
return true ;
if ( strcmp ( F_2 ( V_2 ) , V_9 -> V_10 ) == 0 )
return true ;
return false ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_8 ( V_2 ) ;
F_9 ( V_12 -> V_13 . V_14 ) ;
F_9 ( V_12 -> V_15 . V_14 ) ;
F_9 ( V_12 ) ;
}
struct V_11 * F_10 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_11 * V_12 ;
T_3 V_20 ;
V_12 = F_11 ( sizeof( * V_12 ) , V_21 ) ;
if ( ! V_12 )
goto V_22;
V_12 -> V_13 = V_19 -> V_13 ;
if ( V_12 -> V_13 . V_14 ) {
V_20 = V_12 -> V_13 . V_23 * sizeof( * V_12 -> V_13 . V_14 ) ;
V_12 -> V_13 . V_14 = F_12 ( V_19 -> V_13 . V_14 , V_20 ,
V_21 ) ;
if ( ! V_12 -> V_13 . V_14 )
goto V_24;
}
V_12 -> V_15 = V_19 -> V_15 ;
if ( V_12 -> V_15 . V_14 ) {
V_20 = V_12 -> V_15 . V_23 * sizeof( * V_12 -> V_15 . V_14 ) ;
V_12 -> V_15 . V_14 = F_12 ( V_19 -> V_15 . V_14 , V_20 ,
V_21 ) ;
if ( ! V_12 -> V_15 . V_14 )
goto V_25;
}
V_12 -> V_1 . V_26 = & V_27 ;
V_12 -> V_1 . V_28 = & V_17 -> V_1 ;
V_12 -> V_1 . V_29 = F_7 ;
F_13 ( & V_12 -> V_1 , L_3 , V_19 -> V_10 ) ;
V_12 -> V_1 . V_30 = V_19 -> V_30 ;
if ( V_19 -> V_31 )
V_12 -> V_1 . V_31 = * V_19 -> V_31 ;
if ( F_14 ( & V_12 -> V_1 ) < 0 ) {
F_15 ( L_4 , V_19 -> V_10 ) ;
F_16 ( & V_12 -> V_1 ) ;
}
return V_12 ;
V_25:
F_9 ( V_12 -> V_13 . V_14 ) ;
V_24:
F_9 ( V_12 ) ;
V_22:
return NULL ;
}
static void F_17 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_16 * V_36 ;
F_18 (cl_info, &hsi_board_list, list)
if ( V_35 -> V_19 . V_37 == V_33 -> V_38 ) {
V_36 = F_19 ( V_33 , V_35 -> V_19 . V_17 ) ;
if ( ! V_36 )
continue;
F_10 ( V_36 , & V_35 -> V_19 ) ;
}
}
static int F_20 ( struct V_39 * V_40 , char * V_10 ,
unsigned int * V_41 )
{
const char * V_42 ;
int V_22 ;
V_22 = F_21 ( V_40 , V_10 , & V_42 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( strcmp ( V_42 , L_5 ) == 0 )
* V_41 = V_43 ;
else if ( strcmp ( V_42 , L_6 ) == 0 )
* V_41 = V_44 ;
else
return - V_45 ;
return 0 ;
}
static int F_22 ( struct V_39 * V_40 , char * V_10 ,
unsigned int * V_41 )
{
const char * V_46 ;
int V_22 ;
V_22 = F_21 ( V_40 , V_10 , & V_46 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( strcmp ( V_46 , L_7 ) == 0 )
* V_41 = V_47 ;
else if ( strcmp ( V_46 , L_8 ) == 0 )
* V_41 = V_48 ;
else
return - V_45 ;
return 0 ;
}
static int F_23 ( struct V_39 * V_40 ,
char * V_10 , unsigned int * V_41 )
{
const char * V_49 ;
int V_22 ;
V_22 = F_21 ( V_40 , V_10 , & V_49 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( strcmp ( V_49 , L_9 ) == 0 )
* V_41 = V_50 ;
else if ( strcmp ( V_49 , L_10 ) == 0 )
* V_41 = V_51 ;
else
return - V_45 ;
return 0 ;
}
static void F_24 ( struct V_16 * V_17 ,
struct V_39 * V_40 )
{
struct V_11 * V_12 ;
struct V_52 V_53 ;
struct V_54 * V_55 ;
char V_10 [ 32 ] ;
int V_56 , V_57 , V_22 , V_58 , V_59 , V_42 ;
V_12 = F_11 ( sizeof( * V_12 ) , V_21 ) ;
if ( ! V_12 )
return;
V_22 = F_25 ( V_40 , V_10 , sizeof( V_10 ) ) ;
if ( V_22 )
goto V_22;
F_13 ( & V_12 -> V_1 , L_3 , V_10 ) ;
V_22 = F_20 ( V_40 , L_11 , & V_42 ) ;
if ( V_22 ) {
V_22 = F_20 ( V_40 , L_12 ,
& V_12 -> V_15 . V_42 ) ;
if ( V_22 )
goto V_22;
V_22 = F_20 ( V_40 , L_13 ,
& V_12 -> V_13 . V_42 ) ;
if ( V_22 )
goto V_22;
} else {
V_12 -> V_15 . V_42 = V_42 ;
V_12 -> V_13 . V_42 = V_42 ;
}
V_22 = F_26 ( V_40 , L_14 ,
& V_12 -> V_13 . V_60 ) ;
if ( V_22 )
goto V_22;
V_12 -> V_15 . V_60 = V_12 -> V_13 . V_60 ;
V_22 = F_22 ( V_40 , L_15 ,
& V_12 -> V_15 . V_46 ) ;
if ( V_22 )
goto V_22;
V_22 = F_23 ( V_40 , L_16 ,
& V_12 -> V_15 . V_49 ) ;
if ( V_22 )
goto V_22;
V_55 = F_27 ( V_40 , L_17 , & V_56 ) ;
if ( ! V_55 ) {
V_22 = - V_45 ;
goto V_22;
}
V_57 = V_56 / sizeof( V_61 ) ;
V_12 -> V_15 . V_23 = V_57 ;
V_12 -> V_13 . V_23 = V_57 ;
V_12 -> V_15 . V_14 = F_28 ( V_57 , sizeof( V_53 ) , V_21 ) ;
if ( ! V_12 -> V_15 . V_14 ) {
V_22 = - V_62 ;
goto V_22;
}
V_12 -> V_13 . V_14 = F_28 ( V_57 , sizeof( V_53 ) , V_21 ) ;
if ( ! V_12 -> V_13 . V_14 ) {
V_22 = - V_62 ;
goto V_63;
}
V_59 = 0 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_22 = F_29 ( V_40 , L_17 , V_58 ,
& V_53 . V_38 ) ;
if ( V_22 )
goto V_64;
V_22 = F_30 ( V_40 , L_18 ,
V_58 , & V_53 . V_10 ) ;
if ( V_22 )
V_53 . V_10 = NULL ;
if ( V_53 . V_38 > V_59 )
V_59 = V_53 . V_38 ;
V_12 -> V_15 . V_14 [ V_58 ] = V_53 ;
V_12 -> V_13 . V_14 [ V_58 ] = V_53 ;
}
V_12 -> V_15 . V_65 = V_59 + 1 ;
V_12 -> V_13 . V_65 = V_59 + 1 ;
V_12 -> V_1 . V_26 = & V_27 ;
V_12 -> V_1 . V_28 = & V_17 -> V_1 ;
V_12 -> V_1 . V_29 = F_7 ;
V_12 -> V_1 . V_66 = V_40 ;
if ( F_14 ( & V_12 -> V_1 ) < 0 ) {
F_15 ( L_4 , V_10 ) ;
F_16 ( & V_12 -> V_1 ) ;
}
return;
V_64:
F_9 ( V_12 -> V_13 . V_14 ) ;
V_63:
F_9 ( V_12 -> V_15 . V_14 ) ;
V_22:
F_9 ( V_12 ) ;
F_15 ( L_19 , V_22 ) ;
}
void F_31 ( struct V_16 * V_17 , struct V_39 * V_67 )
{
struct V_39 * V_68 ;
F_10 ( V_17 , & V_69 ) ;
F_32 (clients, child)
F_24 ( V_17 , V_68 ) ;
}
int F_33 ( struct V_1 * V_2 , void * T_4 V_4 )
{
F_34 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , void * T_4 V_4 )
{
F_36 ( V_2 , NULL , F_33 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_38 ( V_2 ) ;
F_9 ( V_33 -> V_17 ) ;
F_9 ( V_33 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_9 ( F_40 ( V_2 ) ) ;
}
void F_41 ( struct V_16 * V_17 )
{
F_36 ( & V_17 -> V_1 , NULL , F_33 ) ;
}
void F_42 ( struct V_32 * V_33 )
{
F_36 ( & V_33 -> V_1 , NULL , F_35 ) ;
F_34 ( & V_33 -> V_1 ) ;
}
int F_43 ( struct V_32 * V_33 )
{
unsigned int V_58 ;
int V_22 ;
V_22 = F_44 ( & V_33 -> V_1 ) ;
if ( V_22 < 0 )
return V_22 ;
for ( V_58 = 0 ; V_58 < V_33 -> V_70 ; V_58 ++ ) {
V_33 -> V_17 [ V_58 ] -> V_1 . V_28 = & V_33 -> V_1 ;
V_22 = F_44 ( & V_33 -> V_17 [ V_58 ] -> V_1 ) ;
if ( V_22 < 0 )
goto V_71;
}
F_17 ( V_33 ) ;
return 0 ;
V_71:
while ( V_58 -- > 0 )
F_45 ( & V_33 -> V_17 [ V_58 ] -> V_1 ) ;
F_45 ( & V_33 -> V_1 ) ;
return V_22 ;
}
int F_46 ( struct V_72 * V_73 )
{
V_73 -> V_9 . V_26 = & V_27 ;
return F_47 ( & V_73 -> V_9 ) ;
}
static inline int F_48 ( struct V_74 * T_5 V_4 )
{
return 0 ;
}
static inline int F_49 ( struct V_11 * V_12 V_4 )
{
return 0 ;
}
void F_50 ( struct V_32 * V_33 )
{
unsigned int V_58 ;
if ( ! V_33 )
return;
for ( V_58 = 0 ; V_58 < V_33 -> V_70 ; V_58 ++ )
if ( V_33 -> V_17 && V_33 -> V_17 [ V_58 ] )
F_16 ( & V_33 -> V_17 [ V_58 ] -> V_1 ) ;
F_16 ( & V_33 -> V_1 ) ;
}
struct V_32 * F_51 ( unsigned int V_75 , T_6 V_76 )
{
struct V_32 * V_33 ;
struct V_16 * * V_17 ;
unsigned int V_58 ;
if ( ! V_75 )
return NULL ;
V_33 = F_11 ( sizeof( * V_33 ) , V_76 ) ;
if ( ! V_33 )
return NULL ;
V_17 = F_28 ( V_75 , sizeof( * V_17 ) , V_76 ) ;
if ( ! V_17 ) {
F_9 ( V_33 ) ;
return NULL ;
}
V_33 -> V_70 = V_75 ;
V_33 -> V_17 = V_17 ;
V_33 -> V_1 . V_29 = F_37 ;
F_52 ( & V_33 -> V_1 ) ;
for ( V_58 = 0 ; V_58 < V_75 ; V_58 ++ ) {
V_17 [ V_58 ] = F_11 ( sizeof( * * V_17 ) , V_76 ) ;
if ( V_17 [ V_58 ] == NULL )
goto V_71;
V_17 [ V_58 ] -> V_77 = V_58 ;
V_17 [ V_58 ] -> V_78 = F_48 ;
V_17 [ V_58 ] -> V_79 = F_49 ;
V_17 [ V_58 ] -> V_80 = F_49 ;
V_17 [ V_58 ] -> V_81 = F_49 ;
V_17 [ V_58 ] -> V_82 = F_49 ;
V_17 [ V_58 ] -> V_29 = F_49 ;
F_53 ( & V_17 [ V_58 ] -> V_83 ) ;
F_54 ( & V_17 [ V_58 ] -> V_84 ) ;
F_13 ( & V_17 [ V_58 ] -> V_1 , L_20 , V_58 ) ;
V_33 -> V_17 [ V_58 ] -> V_1 . V_29 = F_39 ;
F_52 ( & V_33 -> V_17 [ V_58 ] -> V_1 ) ;
}
return V_33 ;
V_71:
F_50 ( V_33 ) ;
return NULL ;
}
void F_55 ( struct V_74 * T_5 )
{
if ( ! T_5 )
return;
F_56 ( & T_5 -> V_85 ) ;
F_9 ( T_5 ) ;
}
struct V_74 * F_57 ( unsigned int V_86 , T_6 V_76 )
{
struct V_74 * T_5 ;
int V_22 ;
T_5 = F_11 ( sizeof( * T_5 ) , V_76 ) ;
if ( ! T_5 )
return NULL ;
if ( ! V_86 )
return T_5 ;
V_22 = F_58 ( & T_5 -> V_85 , V_86 , V_76 ) ;
if ( F_59 ( V_22 ) ) {
F_9 ( T_5 ) ;
T_5 = NULL ;
}
return T_5 ;
}
int F_60 ( struct V_11 * V_12 , struct V_74 * T_5 )
{
struct V_16 * V_17 = F_61 ( V_12 ) ;
if ( ! F_62 ( V_12 ) )
return - V_87 ;
F_63 ( ! T_5 -> V_88 || ! T_5 -> V_89 ) ;
T_5 -> V_12 = V_12 ;
return V_17 -> V_78 ( T_5 ) ;
}
int F_64 ( struct V_11 * V_12 , unsigned int V_90 )
{
struct V_16 * V_17 = F_61 ( V_12 ) ;
int V_22 = 0 ;
F_65 ( & V_17 -> V_83 ) ;
if ( ( V_17 -> V_91 ) && ( ! V_17 -> V_92 || ! V_90 ) ) {
V_22 = - V_93 ;
goto V_71;
}
if ( ! F_66 ( F_38 ( V_17 -> V_1 . V_28 ) -> V_94 ) ) {
V_22 = - V_95 ;
goto V_71;
}
V_17 -> V_91 ++ ;
V_17 -> V_92 = ! ! V_90 ;
V_12 -> V_96 = 1 ;
V_71:
F_67 ( & V_17 -> V_83 ) ;
return V_22 ;
}
void F_68 ( struct V_11 * V_12 )
{
struct V_16 * V_17 = F_61 ( V_12 ) ;
F_65 ( & V_17 -> V_83 ) ;
V_17 -> V_29 ( V_12 ) ;
if ( V_12 -> V_96 )
V_17 -> V_91 -- ;
F_69 ( V_17 -> V_91 < 0 ) ;
V_12 -> V_96 = 0 ;
if ( ! V_17 -> V_91 )
V_17 -> V_92 = 0 ;
F_70 ( F_38 ( V_17 -> V_1 . V_28 ) -> V_94 ) ;
F_67 ( & V_17 -> V_83 ) ;
}
static int F_71 ( struct V_97 * V_98 ,
unsigned long V_99 , void * T_4 V_4 )
{
struct V_11 * V_12 = F_72 ( V_98 , struct V_11 , V_98 ) ;
(* V_12 -> V_100 )( V_12 , V_99 ) ;
return 0 ;
}
int F_73 ( struct V_11 * V_12 ,
void (* F_74)( struct V_11 * , unsigned long ) )
{
struct V_16 * V_17 = F_61 ( V_12 ) ;
if ( ! F_74 || V_12 -> V_100 )
return - V_45 ;
if ( ! F_62 ( V_12 ) )
return - V_87 ;
V_12 -> V_100 = F_74 ;
V_12 -> V_98 . V_101 = F_71 ;
return F_75 ( & V_17 -> V_84 , & V_12 -> V_98 ) ;
}
int F_76 ( struct V_11 * V_12 )
{
struct V_16 * V_17 = F_61 ( V_12 ) ;
int V_22 ;
F_77 ( ! F_62 ( V_12 ) ) ;
V_22 = F_78 ( & V_17 -> V_84 , & V_12 -> V_98 ) ;
if ( ! V_22 )
V_12 -> V_100 = NULL ;
return V_22 ;
}
int F_79 ( struct V_16 * V_17 , unsigned long V_99 )
{
return F_80 ( & V_17 -> V_84 , V_99 , NULL ) ;
}
int F_81 ( struct V_11 * V_12 , char * V_10 )
{
int V_58 ;
if ( ! V_12 -> V_15 . V_14 )
return - V_102 ;
for ( V_58 = 0 ; V_58 < V_12 -> V_15 . V_23 ; V_58 ++ )
if ( ! strcmp ( V_12 -> V_15 . V_14 [ V_58 ] . V_10 , V_10 ) )
return V_12 -> V_15 . V_14 [ V_58 ] . V_38 ;
return - V_103 ;
}
static int T_7 F_82 ( void )
{
return F_83 ( & V_27 ) ;
}
static void T_8 F_84 ( void )
{
F_85 ( & V_27 ) ;
}
