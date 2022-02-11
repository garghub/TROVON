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
if ( ! V_7 -> V_8 ) {
F_5 ( V_12 L_1 ,
V_7 -> V_13 -> V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static inline void F_6 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_8 )
return;
F_7 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
}
static inline void F_8 ( struct V_6 * V_7 )
{
int V_16 ;
F_9 ( & V_7 -> V_17 ) ;
F_9 ( & V_7 -> V_18 ) ;
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ )
F_10 ( & V_7 -> V_8 [ V_16 ] . V_19 ,
& V_7 -> V_17 ) ;
}
struct V_20 * F_11 ( int V_21 )
{
struct V_6 * V_7 = NULL ;
struct V_20 * V_13 ;
int V_16 , V_22 ;
F_12 ( L_2 ) ;
V_13 = F_13 ( sizeof( struct V_6 ) + V_21 ) ;
if ( ! V_13 ) {
F_14 ( L_3 ) ;
goto V_23;
}
V_7 = (struct V_6 * ) F_15 ( V_13 ) ;
memset ( V_7 , 0 , sizeof( struct V_6 ) + V_21 ) ;
V_7 -> V_13 = V_13 ;
V_22 = F_3 ( V_7 ) ;
if ( V_22 ) {
F_14 ( L_4 ,
V_22 ) ;
goto V_23;
}
F_8 ( V_7 ) ;
V_7 -> V_24 = V_25 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_28 = 1 ;
V_7 -> V_29 = 1 ;
V_7 -> V_30 = 1 ;
V_7 -> V_31 = 1 ;
V_7 -> V_32 = V_32 ;
F_16 ( & V_7 -> V_33 ) ;
F_16 ( & V_7 -> V_34 ) ;
F_16 ( & V_7 -> V_35 ) ;
F_16 ( & V_7 -> V_36 ) ;
F_17 ( & ( V_7 -> V_37 ) , 0 ) ;
F_17 ( & ( V_7 -> V_38 ) , 0 ) ;
F_18 ( & V_7 -> V_39 , L_5 , & V_7 -> V_33 ) ;
V_7 -> V_40 = false ;
V_7 -> V_41 = 0 ;
V_7 -> V_42 = 0 ;
V_7 -> V_43 = 0 ;
V_7 -> V_44 = 0 ;
V_7 -> V_31 = 1 ;
V_7 -> V_45 = 0 ;
V_7 -> V_46 = 0 ;
memset ( V_7 -> V_47 , 0 , sizeof( struct V_48 ) * 32 ) ;
F_19 ( V_7 ) ;
V_7 -> V_49 = F_4 ( sizeof( struct V_50 ) , V_11 ) ;
if ( V_7 -> V_49 == NULL ) {
F_20 ( V_51 , L_6 ) ;
return NULL ;
}
F_21 ( V_7 ) ;
F_22 ( V_7 ) ;
F_23 ( V_7 ) ;
for ( V_16 = 0 ; V_16 < V_52 ; V_16 ++ )
F_9 ( & V_7 -> V_53 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 17 ; V_16 ++ ) {
V_7 -> V_54 [ V_16 ] = - 1 ;
V_7 -> V_55 [ V_16 ] = - 1 ;
V_7 -> V_56 [ V_16 ] = 0 ;
}
return V_13 ;
V_23:
if ( V_13 )
F_24 ( V_13 ) ;
return NULL ;
}
void F_25 ( struct V_20 * V_13 )
{
struct V_6 * V_7 = (struct V_6 * )
F_15 ( V_13 ) ;
F_7 ( V_7 -> V_49 ) ;
V_7 -> V_49 = NULL ;
F_26 ( V_7 ) ;
F_27 ( & V_7 -> V_39 ) ;
F_6 ( V_7 ) ;
F_24 ( V_13 ) ;
}
static int F_28 ( struct V_57 * V_58 , void * V_59 )
{
return F_29 ( V_58 , L_7 , V_60 ) ;
}
static T_1 F_30 ( struct V_61 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
unsigned long V_65 ;
int V_22 = F_31 ( V_62 , V_63 , 0 , & V_65 ) ;
if ( V_22 )
return V_22 ;
V_60 = V_65 ;
return V_63 ;
}
static int F_32 ( struct V_66 * V_66 , struct V_61 * V_61 )
{
return F_33 ( V_61 , F_28 , NULL ) ;
}
static int T_5 F_34 ( void )
{
struct V_67 * V_68 ;
V_60 = V_69 ;
V_70 = F_35 ( V_71 , V_72 . V_73 ) ;
if ( V_70 == NULL ) {
F_14 ( L_8 V_71
L_9 ) ;
return - V_74 ;
}
V_68 = F_36 ( L_10 , V_75 | V_76 , V_70 , & V_77 ) ;
if ( ! V_68 ) {
F_37 ( V_71 , V_72 . V_73 ) ;
V_70 = NULL ;
return - V_74 ;
}
return 0 ;
}
static void T_6 F_38 ( void )
{
if ( V_70 ) {
F_37 ( L_10 , V_70 ) ;
F_37 ( V_71 , V_72 . V_73 ) ;
V_70 = NULL ;
}
}
