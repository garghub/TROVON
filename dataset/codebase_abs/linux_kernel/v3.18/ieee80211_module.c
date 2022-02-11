static inline int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return 0 ;
V_2 -> V_3 = F_2 (
V_4 , sizeof( struct V_5 ) ,
V_6 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_7 L_1 ,
V_2 -> V_8 -> V_9 ) ;
return - V_10 ;
}
return 0 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_5 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
int V_11 ;
F_7 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_4 ; V_11 ++ )
F_8 ( & V_2 -> V_3 [ V_11 ] . V_14 , & V_2 -> V_12 ) ;
}
struct V_15 * F_9 ( int V_16 )
{
struct V_1 * V_2 ;
struct V_15 * V_8 ;
int V_11 , V_17 ;
F_10 ( L_2 ) ;
V_8 = F_11 ( sizeof( struct V_1 ) + V_16 ) ;
if ( ! V_8 ) {
F_12 ( L_3 ) ;
goto V_18;
}
V_2 = F_13 ( V_8 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) + V_16 ) ;
V_2 -> V_8 = V_8 ;
V_17 = F_1 ( V_2 ) ;
if ( V_17 ) {
F_12 ( L_4 ,
V_17 ) ;
goto V_18;
}
F_6 ( V_2 ) ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = 1 ;
V_2 -> V_24 = 1 ;
V_2 -> V_25 = 1 ;
V_2 -> V_26 = 1 ;
F_7 ( & V_2 -> V_27 ) ;
F_14 ( & V_2 -> V_28 ) ;
V_2 -> V_28 . V_29 = ( unsigned long ) V_2 ;
V_2 -> V_28 . V_30 = V_31 ;
F_15 ( & V_2 -> V_32 ) ;
F_15 ( & V_2 -> V_33 ) ;
F_15 ( & V_2 -> V_34 ) ;
F_15 ( & V_2 -> V_35 ) ;
F_16 ( & ( V_2 -> V_36 ) , 0 ) ;
F_16 ( & ( V_2 -> V_37 ) , 0 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_26 = 1 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = 0 ;
F_17 ( V_2 ) ;
V_2 -> V_45 = F_18 ( sizeof( V_46 ) , V_6 ) ;
if ( V_2 -> V_45 == NULL )
{
F_19 ( V_47 , L_5 ) ;
goto V_18;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_48 ; V_11 ++ )
F_7 ( & V_2 -> V_49 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < 17 ; V_11 ++ ) {
V_2 -> V_50 [ V_11 ] = - 1 ;
V_2 -> V_51 [ V_11 ] = - 1 ;
V_2 -> V_52 [ V_11 ] = 0 ;
}
F_23 () ;
F_24 () ;
F_25 () ;
return V_8 ;
V_18:
if ( V_8 )
F_26 ( V_8 ) ;
return NULL ;
}
void F_27 ( struct V_15 * V_8 )
{
struct V_1 * V_2 = F_13 ( V_8 ) ;
int V_11 ;
F_5 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_28 ) ;
F_31 ( V_2 , 1 ) ;
for ( V_11 = 0 ; V_11 < V_53 ; V_11 ++ ) {
struct V_54 * V_55 = V_2 -> V_55 [ V_11 ] ;
if ( V_55 ) {
if ( V_55 -> V_56 )
V_55 -> V_56 -> V_57 ( V_55 -> V_58 ) ;
F_5 ( V_55 ) ;
V_2 -> V_55 [ V_11 ] = NULL ;
}
}
F_4 ( V_2 ) ;
F_26 ( V_8 ) ;
}
static int F_32 ( struct V_59 * V_60 , void * V_61 )
{
return F_33 ( V_60 , L_6 , V_62 ) ;
}
static T_1 F_34 ( struct V_63 * V_63 , const char T_2 * V_64 ,
T_3 V_65 , T_4 * V_66 )
{
unsigned long V_67 ;
int V_17 = F_35 ( V_64 , V_65 , 0 , & V_67 ) ;
if ( V_17 )
return V_17 ;
V_62 = V_67 ;
return V_65 ;
}
static int F_36 ( struct V_68 * V_68 , struct V_63 * V_63 )
{
return F_37 ( V_63 , F_32 , NULL ) ;
}
int T_5 F_38 ( void )
{
struct V_69 * V_70 ;
V_62 = V_71 ;
V_72 = F_39 ( V_73 , V_74 . V_75 ) ;
if ( V_72 == NULL ) {
F_12 ( L_7 V_73
L_8 ) ;
return - V_76 ;
}
V_70 = F_40 ( L_9 , V_77 | V_78 ,
V_72 , & V_79 ) ;
if ( ! V_70 ) {
F_41 ( V_73 , V_74 . V_75 ) ;
V_72 = NULL ;
return - V_76 ;
}
return 0 ;
}
void T_6 F_42 ( void )
{
if ( V_72 ) {
F_41 ( L_9 , V_72 ) ;
F_41 ( V_73 , V_74 . V_75 ) ;
V_72 = NULL ;
}
}
