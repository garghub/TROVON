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
return NULL ;
V_12 -> V_13 = V_19 -> V_13 ;
if ( V_12 -> V_13 . V_14 ) {
V_20 = V_12 -> V_13 . V_22 * sizeof( * V_12 -> V_13 . V_14 ) ;
V_12 -> V_13 . V_14 = F_11 ( V_20 , V_21 ) ;
memcpy ( V_12 -> V_13 . V_14 , V_19 -> V_13 . V_14 , V_20 ) ;
}
V_12 -> V_15 = V_19 -> V_15 ;
if ( V_12 -> V_15 . V_14 ) {
V_20 = V_12 -> V_15 . V_22 * sizeof( * V_12 -> V_15 . V_14 ) ;
V_12 -> V_15 . V_14 = F_11 ( V_20 , V_21 ) ;
memcpy ( V_12 -> V_15 . V_14 , V_19 -> V_15 . V_14 , V_20 ) ;
}
V_12 -> V_1 . V_23 = & V_24 ;
V_12 -> V_1 . V_25 = & V_17 -> V_1 ;
V_12 -> V_1 . V_26 = F_7 ;
F_12 ( & V_12 -> V_1 , L_3 , V_19 -> V_10 ) ;
V_12 -> V_1 . V_27 = V_19 -> V_27 ;
if ( V_19 -> V_28 )
V_12 -> V_1 . V_28 = * V_19 -> V_28 ;
if ( F_13 ( & V_12 -> V_1 ) < 0 ) {
F_14 ( L_4 , V_19 -> V_10 ) ;
F_15 ( & V_12 -> V_1 ) ;
}
return V_12 ;
}
static void F_16 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_16 * V_33 ;
F_17 (cl_info, &hsi_board_list, list)
if ( V_32 -> V_19 . V_34 == V_30 -> V_35 ) {
V_33 = F_18 ( V_30 , V_32 -> V_19 . V_17 ) ;
if ( ! V_33 )
continue;
F_10 ( V_33 , & V_32 -> V_19 ) ;
}
}
static int F_19 ( struct V_36 * V_37 , char * V_10 ,
unsigned int * V_38 )
{
const char * V_39 ;
int V_40 ;
V_40 = F_20 ( V_37 , V_10 , & V_39 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( strcmp ( V_39 , L_5 ) == 0 )
* V_38 = V_41 ;
else if ( strcmp ( V_39 , L_6 ) == 0 )
* V_38 = V_42 ;
else
return - V_43 ;
return 0 ;
}
static int F_21 ( struct V_36 * V_37 , char * V_10 ,
unsigned int * V_38 )
{
const char * V_44 ;
int V_40 ;
V_40 = F_20 ( V_37 , V_10 , & V_44 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( strcmp ( V_44 , L_7 ) == 0 )
* V_38 = V_45 ;
else if ( strcmp ( V_44 , L_8 ) == 0 )
* V_38 = V_46 ;
else
return - V_43 ;
return 0 ;
}
static int F_22 ( struct V_36 * V_37 ,
char * V_10 , unsigned int * V_38 )
{
const char * V_47 ;
int V_40 ;
V_40 = F_20 ( V_37 , V_10 , & V_47 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( strcmp ( V_47 , L_9 ) == 0 )
* V_38 = V_48 ;
else if ( strcmp ( V_47 , L_10 ) == 0 )
* V_38 = V_49 ;
else
return - V_43 ;
return 0 ;
}
static void F_23 ( struct V_16 * V_17 ,
struct V_36 * V_37 )
{
struct V_11 * V_12 ;
struct V_50 V_51 ;
struct V_52 * V_53 ;
char V_10 [ 32 ] ;
int V_54 , V_55 , V_40 , V_56 , V_57 , V_39 ;
V_12 = F_11 ( sizeof( * V_12 ) , V_21 ) ;
if ( ! V_12 )
return;
V_40 = F_24 ( V_37 , V_10 , sizeof( V_10 ) ) ;
if ( V_40 )
goto V_40;
F_12 ( & V_12 -> V_1 , L_3 , V_10 ) ;
V_40 = F_19 ( V_37 , L_11 , & V_39 ) ;
if ( V_40 ) {
V_40 = F_19 ( V_37 , L_12 ,
& V_12 -> V_15 . V_39 ) ;
if ( V_40 )
goto V_40;
V_40 = F_19 ( V_37 , L_13 ,
& V_12 -> V_13 . V_39 ) ;
if ( V_40 )
goto V_40;
} else {
V_12 -> V_15 . V_39 = V_39 ;
V_12 -> V_13 . V_39 = V_39 ;
}
V_40 = F_25 ( V_37 , L_14 ,
& V_12 -> V_13 . V_58 ) ;
if ( V_40 )
goto V_40;
V_12 -> V_15 . V_58 = V_12 -> V_13 . V_58 ;
V_40 = F_21 ( V_37 , L_15 ,
& V_12 -> V_15 . V_44 ) ;
if ( V_40 )
goto V_40;
V_40 = F_22 ( V_37 , L_16 ,
& V_12 -> V_15 . V_47 ) ;
if ( V_40 )
goto V_40;
V_53 = F_26 ( V_37 , L_17 , & V_54 ) ;
if ( ! V_53 ) {
V_40 = - V_43 ;
goto V_40;
}
V_55 = V_54 / sizeof( V_59 ) ;
V_12 -> V_15 . V_22 = V_55 ;
V_12 -> V_13 . V_22 = V_55 ;
V_12 -> V_15 . V_14 = F_11 ( V_55 * sizeof( V_51 ) , V_21 ) ;
if ( ! V_12 -> V_15 . V_14 ) {
V_40 = - V_60 ;
goto V_40;
}
V_12 -> V_13 . V_14 = F_11 ( V_55 * sizeof( V_51 ) , V_21 ) ;
if ( ! V_12 -> V_13 . V_14 ) {
V_40 = - V_60 ;
goto V_61;
}
V_57 = 0 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
V_40 = F_27 ( V_37 , L_17 , V_56 ,
& V_51 . V_35 ) ;
if ( V_40 )
goto V_62;
V_40 = F_28 ( V_37 , L_18 ,
V_56 , & V_51 . V_10 ) ;
if ( V_40 )
V_51 . V_10 = NULL ;
if ( V_51 . V_35 > V_57 )
V_57 = V_51 . V_35 ;
V_12 -> V_15 . V_14 [ V_56 ] = V_51 ;
V_12 -> V_13 . V_14 [ V_56 ] = V_51 ;
}
V_12 -> V_15 . V_63 = V_57 + 1 ;
V_12 -> V_13 . V_63 = V_57 + 1 ;
V_12 -> V_1 . V_23 = & V_24 ;
V_12 -> V_1 . V_25 = & V_17 -> V_1 ;
V_12 -> V_1 . V_26 = F_7 ;
V_12 -> V_1 . V_64 = V_37 ;
if ( F_13 ( & V_12 -> V_1 ) < 0 ) {
F_14 ( L_4 , V_10 ) ;
F_15 ( & V_12 -> V_1 ) ;
goto V_62;
}
return;
V_62:
F_9 ( V_12 -> V_13 . V_14 ) ;
V_61:
F_9 ( V_12 -> V_15 . V_14 ) ;
V_40:
F_9 ( V_12 ) ;
F_14 ( L_19 , V_40 ) ;
}
void F_29 ( struct V_16 * V_17 , struct V_36 * V_65 )
{
struct V_36 * V_66 ;
F_10 ( V_17 , & V_67 ) ;
F_30 (clients, child)
F_23 ( V_17 , V_66 ) ;
}
int F_31 ( struct V_1 * V_2 , void * T_4 V_4 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , void * T_4 V_4 )
{
F_34 ( V_2 , NULL , F_31 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_36 ( V_2 ) ;
F_9 ( V_30 -> V_17 ) ;
F_9 ( V_30 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_9 ( F_38 ( V_2 ) ) ;
}
void F_39 ( struct V_16 * V_17 )
{
F_34 ( & V_17 -> V_1 , NULL , F_31 ) ;
}
void F_40 ( struct V_29 * V_30 )
{
F_34 ( & V_30 -> V_1 , NULL , F_33 ) ;
F_32 ( & V_30 -> V_1 ) ;
}
int F_41 ( struct V_29 * V_30 )
{
unsigned int V_56 ;
int V_40 ;
V_40 = F_42 ( & V_30 -> V_1 ) ;
if ( V_40 < 0 )
return V_40 ;
for ( V_56 = 0 ; V_56 < V_30 -> V_68 ; V_56 ++ ) {
V_30 -> V_17 [ V_56 ] -> V_1 . V_25 = & V_30 -> V_1 ;
V_40 = F_42 ( & V_30 -> V_17 [ V_56 ] -> V_1 ) ;
if ( V_40 < 0 )
goto V_69;
}
F_16 ( V_30 ) ;
return 0 ;
V_69:
while ( V_56 -- > 0 )
F_43 ( & V_30 -> V_17 [ V_56 ] -> V_1 ) ;
F_43 ( & V_30 -> V_1 ) ;
return V_40 ;
}
int F_44 ( struct V_70 * V_71 )
{
V_71 -> V_9 . V_23 = & V_24 ;
return F_45 ( & V_71 -> V_9 ) ;
}
static inline int F_46 ( struct V_72 * T_5 V_4 )
{
return 0 ;
}
static inline int F_47 ( struct V_11 * V_12 V_4 )
{
return 0 ;
}
void F_48 ( struct V_29 * V_30 )
{
unsigned int V_56 ;
if ( ! V_30 )
return;
for ( V_56 = 0 ; V_56 < V_30 -> V_68 ; V_56 ++ )
if ( V_30 -> V_17 && V_30 -> V_17 [ V_56 ] )
F_15 ( & V_30 -> V_17 [ V_56 ] -> V_1 ) ;
F_15 ( & V_30 -> V_1 ) ;
}
struct V_29 * F_49 ( unsigned int V_73 , T_6 V_74 )
{
struct V_29 * V_30 ;
struct V_16 * * V_17 ;
unsigned int V_56 ;
if ( ! V_73 )
return NULL ;
V_30 = F_11 ( sizeof( * V_30 ) , V_74 ) ;
if ( ! V_30 )
return NULL ;
V_17 = F_11 ( sizeof( * V_17 ) * V_73 , V_74 ) ;
if ( ! V_17 ) {
F_9 ( V_30 ) ;
return NULL ;
}
V_30 -> V_68 = V_73 ;
V_30 -> V_17 = V_17 ;
V_30 -> V_1 . V_26 = F_35 ;
F_50 ( & V_30 -> V_1 ) ;
for ( V_56 = 0 ; V_56 < V_73 ; V_56 ++ ) {
V_17 [ V_56 ] = F_11 ( sizeof( * * V_17 ) , V_74 ) ;
if ( V_17 [ V_56 ] == NULL )
goto V_69;
V_17 [ V_56 ] -> V_75 = V_56 ;
V_17 [ V_56 ] -> V_76 = F_46 ;
V_17 [ V_56 ] -> V_77 = F_47 ;
V_17 [ V_56 ] -> V_78 = F_47 ;
V_17 [ V_56 ] -> V_79 = F_47 ;
V_17 [ V_56 ] -> V_80 = F_47 ;
V_17 [ V_56 ] -> V_26 = F_47 ;
F_51 ( & V_17 [ V_56 ] -> V_81 ) ;
F_52 ( & V_17 [ V_56 ] -> V_82 ) ;
F_12 ( & V_17 [ V_56 ] -> V_1 , L_20 , V_56 ) ;
V_30 -> V_17 [ V_56 ] -> V_1 . V_26 = F_37 ;
F_50 ( & V_30 -> V_17 [ V_56 ] -> V_1 ) ;
}
return V_30 ;
V_69:
F_48 ( V_30 ) ;
return NULL ;
}
void F_53 ( struct V_72 * T_5 )
{
if ( ! T_5 )
return;
F_54 ( & T_5 -> V_83 ) ;
F_9 ( T_5 ) ;
}
struct V_72 * F_55 ( unsigned int V_84 , T_6 V_74 )
{
struct V_72 * T_5 ;
int V_40 ;
T_5 = F_11 ( sizeof( * T_5 ) , V_74 ) ;
if ( ! T_5 )
return NULL ;
if ( ! V_84 )
return T_5 ;
V_40 = F_56 ( & T_5 -> V_83 , V_84 , V_74 ) ;
if ( F_57 ( V_40 ) ) {
F_9 ( T_5 ) ;
T_5 = NULL ;
}
return T_5 ;
}
int F_58 ( struct V_11 * V_12 , struct V_72 * T_5 )
{
struct V_16 * V_17 = F_59 ( V_12 ) ;
if ( ! F_60 ( V_12 ) )
return - V_85 ;
F_61 ( ! T_5 -> V_86 || ! T_5 -> V_87 ) ;
T_5 -> V_12 = V_12 ;
return V_17 -> V_76 ( T_5 ) ;
}
int F_62 ( struct V_11 * V_12 , unsigned int V_88 )
{
struct V_16 * V_17 = F_59 ( V_12 ) ;
int V_40 = 0 ;
F_63 ( & V_17 -> V_81 ) ;
if ( ( V_17 -> V_89 ) && ( ! V_17 -> V_90 || ! V_88 ) ) {
V_40 = - V_91 ;
goto V_69;
}
if ( ! F_64 ( F_36 ( V_17 -> V_1 . V_25 ) -> V_92 ) ) {
V_40 = - V_93 ;
goto V_69;
}
V_17 -> V_89 ++ ;
V_17 -> V_90 = ! ! V_88 ;
V_12 -> V_94 = 1 ;
V_69:
F_65 ( & V_17 -> V_81 ) ;
return V_40 ;
}
void F_66 ( struct V_11 * V_12 )
{
struct V_16 * V_17 = F_59 ( V_12 ) ;
F_63 ( & V_17 -> V_81 ) ;
V_17 -> V_26 ( V_12 ) ;
if ( V_12 -> V_94 )
V_17 -> V_89 -- ;
F_67 ( V_17 -> V_89 < 0 ) ;
V_12 -> V_94 = 0 ;
if ( ! V_17 -> V_89 )
V_17 -> V_90 = 0 ;
F_68 ( F_36 ( V_17 -> V_1 . V_25 ) -> V_92 ) ;
F_65 ( & V_17 -> V_81 ) ;
}
static int F_69 ( struct V_95 * V_96 ,
unsigned long V_97 , void * T_4 V_4 )
{
struct V_11 * V_12 = F_70 ( V_96 , struct V_11 , V_96 ) ;
(* V_12 -> V_98 )( V_12 , V_97 ) ;
return 0 ;
}
int F_71 ( struct V_11 * V_12 ,
void (* F_72)( struct V_11 * , unsigned long ) )
{
struct V_16 * V_17 = F_59 ( V_12 ) ;
if ( ! F_72 || V_12 -> V_98 )
return - V_43 ;
if ( ! F_60 ( V_12 ) )
return - V_85 ;
V_12 -> V_98 = F_72 ;
V_12 -> V_96 . V_99 = F_69 ;
return F_73 ( & V_17 -> V_82 , & V_12 -> V_96 ) ;
}
int F_74 ( struct V_11 * V_12 )
{
struct V_16 * V_17 = F_59 ( V_12 ) ;
int V_40 ;
F_75 ( ! F_60 ( V_12 ) ) ;
V_40 = F_76 ( & V_17 -> V_82 , & V_12 -> V_96 ) ;
if ( ! V_40 )
V_12 -> V_98 = NULL ;
return V_40 ;
}
int F_77 ( struct V_16 * V_17 , unsigned long V_97 )
{
return F_78 ( & V_17 -> V_82 , V_97 , NULL ) ;
}
int F_79 ( struct V_11 * V_12 , char * V_10 )
{
int V_56 ;
if ( ! V_12 -> V_15 . V_14 )
return - V_100 ;
for ( V_56 = 0 ; V_56 < V_12 -> V_15 . V_22 ; V_56 ++ )
if ( ! strcmp ( V_12 -> V_15 . V_14 [ V_56 ] . V_10 , V_10 ) )
return V_12 -> V_15 . V_14 [ V_56 ] . V_35 ;
return - V_101 ;
}
static int T_7 F_80 ( void )
{
return F_81 ( & V_24 ) ;
}
static void T_8 F_82 ( void )
{
F_83 ( & V_24 ) ;
}
