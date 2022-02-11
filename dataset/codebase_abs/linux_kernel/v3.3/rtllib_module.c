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
static int F_28 ( char * V_57 , char * * V_58 , T_1 V_59 ,
int V_60 , int * V_61 , void * V_4 )
{
return snprintf ( V_57 , V_60 , L_7 , V_62 ) ;
}
static int F_29 ( struct V_63 * V_63 , const char T_2 * V_64 ,
unsigned long V_60 , void * V_4 )
{
char V_65 [] = L_8 ;
unsigned long V_66 = F_30 ( ( unsigned long ) sizeof( V_65 ) - 1 , V_60 ) ;
char * V_67 = ( char * ) V_65 ;
unsigned long V_68 ;
if ( F_31 ( V_65 , V_64 , V_66 ) )
return V_60 ;
V_65 [ V_66 ] = 0 ;
if ( V_67 [ 1 ] == 'x' || V_67 [ 1 ] == 'X' || V_67 [ 0 ] == 'x' || V_67 [ 0 ] == 'X' ) {
V_67 ++ ;
if ( V_67 [ 0 ] == 'x' || V_67 [ 0 ] == 'X' )
V_67 ++ ;
V_68 = F_32 ( V_67 , & V_67 , 16 ) ;
} else
V_68 = F_32 ( V_67 , & V_67 , 10 ) ;
if ( V_67 == V_65 )
F_5 (KERN_INFO DRV_NAME
L_9 , buf) ;
else
V_62 = V_68 ;
return F_33 ( V_65 , V_60 ) ;
}
int T_3 F_34 ( void )
{
struct V_69 * V_70 ;
V_62 = V_71 ;
V_72 = F_35 ( V_73 , V_74 , V_75 . V_76 ) ;
if ( V_72 == NULL ) {
F_14 ( L_10 V_73
L_11 ) ;
return - V_77 ;
}
V_70 = F_35 ( L_12 , V_78 | V_79 | V_80 ,
V_72 ) ;
if ( ! V_70 ) {
F_36 ( V_73 , V_75 . V_76 ) ;
V_72 = NULL ;
return - V_77 ;
}
V_70 -> V_81 = F_28 ;
V_70 -> V_82 = F_29 ;
V_70 -> V_4 = NULL ;
return 0 ;
}
void T_4 F_37 ( void )
{
if ( V_72 ) {
F_36 ( L_12 , V_72 ) ;
F_36 ( V_73 , V_75 . V_76 ) ;
V_72 = NULL ;
}
}
