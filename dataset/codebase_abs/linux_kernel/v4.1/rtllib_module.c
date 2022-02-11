void F_1 ( struct V_1 * V_2 , void * V_3 , unsigned long V_4 )
{
V_2 -> V_5 = V_3 ;
V_2 -> V_4 = V_4 ;
F_2 ( V_2 ) ;
}
static inline int F_3 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 )
return 0 ;
V_7 -> V_8 = F_4 (
V_9 * sizeof( struct V_10 ) ,
V_11 ) ;
if ( ! V_7 -> V_8 )
return - V_12 ;
return 0 ;
}
static inline void F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_8 )
return;
F_6 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
}
static inline void F_7 ( struct V_6 * V_7 )
{
int V_13 ;
F_8 ( & V_7 -> V_14 ) ;
F_8 ( & V_7 -> V_15 ) ;
for ( V_13 = 0 ; V_13 < V_9 ; V_13 ++ )
F_9 ( & V_7 -> V_8 [ V_13 ] . V_16 ,
& V_7 -> V_14 ) ;
}
struct V_17 * F_10 ( int V_18 )
{
struct V_6 * V_7 = NULL ;
struct V_17 * V_19 ;
int V_13 , V_20 ;
F_11 ( L_1 ) ;
V_19 = F_12 ( sizeof( struct V_6 ) + V_18 ) ;
if ( ! V_19 ) {
F_13 ( L_2 ) ;
return NULL ;
}
V_7 = (struct V_6 * ) F_14 ( V_19 ) ;
memset ( V_7 , 0 , sizeof( struct V_6 ) + V_18 ) ;
V_7 -> V_19 = V_19 ;
V_20 = F_3 ( V_7 ) ;
if ( V_20 ) {
F_13 ( L_3 ,
V_20 ) ;
goto V_21;
}
F_7 ( V_7 ) ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_26 = 1 ;
V_7 -> V_27 = 1 ;
V_7 -> V_28 = 1 ;
V_7 -> V_29 = 1 ;
V_7 -> V_30 = V_30 ;
F_15 ( & V_7 -> V_31 ) ;
F_15 ( & V_7 -> V_32 ) ;
F_15 ( & V_7 -> V_33 ) ;
F_15 ( & V_7 -> V_34 ) ;
F_16 ( & ( V_7 -> V_35 ) , 0 ) ;
F_16 ( & ( V_7 -> V_36 ) , 0 ) ;
F_17 ( & V_7 -> V_37 , L_4 , & V_7 -> V_31 ) ;
V_7 -> V_38 = false ;
V_7 -> V_39 = 0 ;
V_7 -> V_40 = 0 ;
V_7 -> V_41 = 0 ;
V_7 -> V_42 = 0 ;
V_7 -> V_29 = 1 ;
V_7 -> V_43 = 0 ;
V_7 -> V_44 = 0 ;
memset ( V_7 -> V_45 , 0 , sizeof( struct V_46 ) * 32 ) ;
F_18 ( V_7 ) ;
V_7 -> V_47 = F_4 ( sizeof( struct V_48 ) , V_11 ) ;
if ( V_7 -> V_47 == NULL )
return NULL ;
F_19 ( V_7 ) ;
F_20 ( V_7 ) ;
F_21 ( V_7 ) ;
for ( V_13 = 0 ; V_13 < V_49 ; V_13 ++ )
F_8 ( & V_7 -> V_50 [ V_13 ] ) ;
for ( V_13 = 0 ; V_13 < 17 ; V_13 ++ ) {
V_7 -> V_51 [ V_13 ] = - 1 ;
V_7 -> V_52 [ V_13 ] = - 1 ;
V_7 -> V_53 [ V_13 ] = 0 ;
}
return V_19 ;
V_21:
F_22 ( V_19 ) ;
return NULL ;
}
void F_23 ( struct V_17 * V_19 )
{
struct V_6 * V_7 = (struct V_6 * )
F_14 ( V_19 ) ;
F_6 ( V_7 -> V_47 ) ;
V_7 -> V_47 = NULL ;
F_24 ( V_7 ) ;
F_25 ( & V_7 -> V_37 ) ;
F_5 ( V_7 ) ;
F_22 ( V_19 ) ;
}
static int F_26 ( struct V_54 * V_55 , void * V_56 )
{
F_27 ( V_55 , L_5 , V_57 ) ;
return 0 ;
}
static T_1 F_28 ( struct V_58 * V_58 , const char T_2 * V_59 ,
T_3 V_60 , T_4 * V_61 )
{
unsigned long V_62 ;
int V_20 = F_29 ( V_59 , V_60 , 0 , & V_62 ) ;
if ( V_20 )
return V_20 ;
V_57 = V_62 ;
return V_60 ;
}
static int F_30 ( struct V_63 * V_63 , struct V_58 * V_58 )
{
return F_31 ( V_58 , F_26 , NULL ) ;
}
static int T_5 F_32 ( void )
{
struct V_64 * V_65 ;
V_57 = V_66 ;
V_67 = F_33 ( V_68 , V_69 . V_70 ) ;
if ( V_67 == NULL ) {
F_13 ( L_6 V_68
L_7 ) ;
return - V_71 ;
}
V_65 = F_34 ( L_8 , V_72 | V_73 , V_67 , & V_74 ) ;
if ( ! V_65 ) {
F_35 ( V_68 , V_69 . V_70 ) ;
V_67 = NULL ;
return - V_71 ;
}
return 0 ;
}
static void T_6 F_36 ( void )
{
if ( V_67 ) {
F_35 ( L_8 , V_67 ) ;
F_35 ( V_68 , V_69 . V_70 ) ;
V_67 = NULL ;
}
}
