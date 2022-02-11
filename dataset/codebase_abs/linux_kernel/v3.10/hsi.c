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
return strcmp ( F_2 ( V_2 ) , V_9 -> V_10 ) == 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( F_8 ( V_2 ) ) ;
}
static void F_9 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_16 = F_10 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return;
V_16 -> V_18 = V_14 -> V_18 ;
V_16 -> V_19 = V_14 -> V_19 ;
V_16 -> V_1 . V_20 = & V_21 ;
V_16 -> V_1 . V_22 = & V_12 -> V_1 ;
V_16 -> V_1 . V_23 = F_6 ;
F_11 ( & V_16 -> V_1 , V_14 -> V_10 ) ;
V_16 -> V_1 . V_24 = V_14 -> V_24 ;
if ( V_14 -> V_25 )
V_16 -> V_1 . V_25 = * V_14 -> V_25 ;
if ( F_12 ( & V_16 -> V_1 ) < 0 ) {
F_13 ( L_3 , V_14 -> V_10 ) ;
F_14 ( & V_16 -> V_1 ) ;
}
}
static void F_15 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_11 * V_30 ;
F_16 (cl_info, &hsi_board_list, list)
if ( V_29 -> V_14 . V_31 == V_27 -> V_32 ) {
V_30 = F_17 ( V_27 , V_29 -> V_14 . V_12 ) ;
if ( ! V_30 )
continue;
F_9 ( V_30 , & V_29 -> V_14 ) ;
}
}
static int F_18 ( struct V_1 * V_2 , void * T_3 V_4 )
{
F_19 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , void * T_3 V_4 )
{
F_21 ( V_2 , NULL , F_18 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_23 ( V_2 ) ;
F_7 ( V_27 -> V_12 ) ;
F_7 ( V_27 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_7 ( F_25 ( V_2 ) ) ;
}
void F_26 ( struct V_26 * V_27 )
{
F_21 ( & V_27 -> V_1 , NULL , F_20 ) ;
F_19 ( & V_27 -> V_1 ) ;
}
int F_27 ( struct V_26 * V_27 )
{
unsigned int V_33 ;
int V_34 ;
V_34 = F_28 ( & V_27 -> V_1 ) ;
if ( V_34 < 0 )
return V_34 ;
for ( V_33 = 0 ; V_33 < V_27 -> V_35 ; V_33 ++ ) {
V_27 -> V_12 [ V_33 ] -> V_1 . V_22 = & V_27 -> V_1 ;
V_34 = F_28 ( & V_27 -> V_12 [ V_33 ] -> V_1 ) ;
if ( V_34 < 0 )
goto V_36;
}
F_15 ( V_27 ) ;
return 0 ;
V_36:
while ( V_33 -- > 0 )
F_29 ( & V_27 -> V_12 [ V_33 ] -> V_1 ) ;
F_29 ( & V_27 -> V_1 ) ;
return V_34 ;
}
int F_30 ( struct V_37 * V_38 )
{
V_38 -> V_9 . V_20 = & V_21 ;
return F_31 ( & V_38 -> V_9 ) ;
}
static inline int F_32 ( struct V_39 * T_4 V_4 )
{
return 0 ;
}
static inline int F_33 ( struct V_15 * V_16 V_4 )
{
return 0 ;
}
void F_34 ( struct V_26 * V_27 )
{
unsigned int V_33 ;
if ( ! V_27 )
return;
for ( V_33 = 0 ; V_33 < V_27 -> V_35 ; V_33 ++ )
if ( V_27 -> V_12 && V_27 -> V_12 [ V_33 ] )
F_14 ( & V_27 -> V_12 [ V_33 ] -> V_1 ) ;
F_14 ( & V_27 -> V_1 ) ;
}
struct V_26 * F_35 ( unsigned int V_40 , T_5 V_41 )
{
struct V_26 * V_27 ;
struct V_11 * * V_12 ;
unsigned int V_33 ;
if ( ! V_40 )
return NULL ;
V_27 = F_10 ( sizeof( * V_27 ) , V_41 ) ;
if ( ! V_27 )
return NULL ;
V_12 = F_10 ( sizeof( * V_12 ) * V_40 , V_41 ) ;
if ( ! V_12 ) {
F_7 ( V_27 ) ;
return NULL ;
}
V_27 -> V_35 = V_40 ;
V_27 -> V_12 = V_12 ;
V_27 -> V_1 . V_23 = F_22 ;
F_36 ( & V_27 -> V_1 ) ;
for ( V_33 = 0 ; V_33 < V_40 ; V_33 ++ ) {
V_12 [ V_33 ] = F_10 ( sizeof( * * V_12 ) , V_41 ) ;
if ( V_12 [ V_33 ] == NULL )
goto V_36;
V_12 [ V_33 ] -> V_42 = V_33 ;
V_12 [ V_33 ] -> V_43 = F_32 ;
V_12 [ V_33 ] -> V_44 = F_33 ;
V_12 [ V_33 ] -> V_45 = F_33 ;
V_12 [ V_33 ] -> V_46 = F_33 ;
V_12 [ V_33 ] -> V_47 = F_33 ;
V_12 [ V_33 ] -> V_23 = F_33 ;
F_37 ( & V_12 [ V_33 ] -> V_48 ) ;
F_38 ( & V_12 [ V_33 ] -> V_49 ) ;
F_11 ( & V_12 [ V_33 ] -> V_1 , L_4 , V_33 ) ;
V_27 -> V_12 [ V_33 ] -> V_1 . V_23 = F_24 ;
F_36 ( & V_27 -> V_12 [ V_33 ] -> V_1 ) ;
}
return V_27 ;
V_36:
F_34 ( V_27 ) ;
return NULL ;
}
void F_39 ( struct V_39 * T_4 )
{
if ( ! T_4 )
return;
F_40 ( & T_4 -> V_50 ) ;
F_7 ( T_4 ) ;
}
struct V_39 * F_41 ( unsigned int V_51 , T_5 V_41 )
{
struct V_39 * T_4 ;
int V_34 ;
T_4 = F_10 ( sizeof( * T_4 ) , V_41 ) ;
if ( ! T_4 )
return NULL ;
if ( ! V_51 )
return T_4 ;
V_34 = F_42 ( & T_4 -> V_50 , V_51 , V_41 ) ;
if ( F_43 ( V_34 ) ) {
F_7 ( T_4 ) ;
T_4 = NULL ;
}
return T_4 ;
}
int F_44 ( struct V_15 * V_16 , struct V_39 * T_4 )
{
struct V_11 * V_12 = F_45 ( V_16 ) ;
if ( ! F_46 ( V_16 ) )
return - V_52 ;
F_47 ( ! T_4 -> V_53 || ! T_4 -> V_54 ) ;
T_4 -> V_16 = V_16 ;
return V_12 -> V_43 ( T_4 ) ;
}
int F_48 ( struct V_15 * V_16 , unsigned int V_55 )
{
struct V_11 * V_12 = F_45 ( V_16 ) ;
int V_34 = 0 ;
F_49 ( & V_12 -> V_48 ) ;
if ( ( V_12 -> V_56 ) && ( ! V_12 -> V_57 || ! V_55 ) ) {
V_34 = - V_58 ;
goto V_36;
}
if ( ! F_50 ( F_23 ( V_12 -> V_1 . V_22 ) -> V_59 ) ) {
V_34 = - V_60 ;
goto V_36;
}
V_12 -> V_56 ++ ;
V_12 -> V_57 = ! ! V_55 ;
V_16 -> V_61 = 1 ;
V_36:
F_51 ( & V_12 -> V_48 ) ;
return V_34 ;
}
void F_52 ( struct V_15 * V_16 )
{
struct V_11 * V_12 = F_45 ( V_16 ) ;
F_49 ( & V_12 -> V_48 ) ;
V_12 -> V_23 ( V_16 ) ;
if ( V_16 -> V_61 )
V_12 -> V_56 -- ;
F_53 ( V_12 -> V_56 < 0 ) ;
V_16 -> V_61 = 0 ;
if ( ! V_12 -> V_56 )
V_12 -> V_57 = 0 ;
F_54 ( F_23 ( V_12 -> V_1 . V_22 ) -> V_59 ) ;
F_51 ( & V_12 -> V_48 ) ;
}
static int F_55 ( struct V_62 * V_63 ,
unsigned long V_64 , void * T_3 V_4 )
{
struct V_15 * V_16 = F_56 ( V_63 , struct V_15 , V_63 ) ;
(* V_16 -> V_65 )( V_16 , V_64 ) ;
return 0 ;
}
int F_57 ( struct V_15 * V_16 ,
void (* F_58)( struct V_15 * , unsigned long ) )
{
struct V_11 * V_12 = F_45 ( V_16 ) ;
if ( ! F_58 || V_16 -> V_65 )
return - V_66 ;
if ( ! F_46 ( V_16 ) )
return - V_52 ;
V_16 -> V_65 = F_58 ;
V_16 -> V_63 . V_67 = F_55 ;
return F_59 ( & V_12 -> V_49 , & V_16 -> V_63 ) ;
}
int F_60 ( struct V_15 * V_16 )
{
struct V_11 * V_12 = F_45 ( V_16 ) ;
int V_34 ;
F_61 ( ! F_46 ( V_16 ) ) ;
V_34 = F_62 ( & V_12 -> V_49 , & V_16 -> V_63 ) ;
if ( ! V_34 )
V_16 -> V_65 = NULL ;
return V_34 ;
}
int F_63 ( struct V_11 * V_12 , unsigned long V_64 )
{
return F_64 ( & V_12 -> V_49 , V_64 , NULL ) ;
}
static int T_6 F_65 ( void )
{
return F_66 ( & V_21 ) ;
}
static void T_7 F_67 ( void )
{
F_68 ( & V_21 ) ;
}
