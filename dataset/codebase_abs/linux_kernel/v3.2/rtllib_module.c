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
F_9 ( & V_7 -> V_32 ) ;
F_1 ( & V_7 -> V_33 ,
V_34 ,
( unsigned long ) V_7 ) ;
V_7 -> V_35 = V_35 ;
F_16 ( & V_7 -> V_36 ) ;
F_16 ( & V_7 -> V_37 ) ;
F_16 ( & V_7 -> V_38 ) ;
F_16 ( & V_7 -> V_39 ) ;
F_17 ( & ( V_7 -> V_40 ) , 0 ) ;
F_17 ( & ( V_7 -> V_41 ) , 0 ) ;
V_7 -> V_42 = false ;
V_7 -> V_43 = 0 ;
V_7 -> V_44 = 0 ;
V_7 -> V_45 = 0 ;
V_7 -> V_46 = 0 ;
V_7 -> V_31 = 1 ;
V_7 -> V_47 = 0 ;
V_7 -> V_48 = 0 ;
memset ( V_7 -> V_49 , 0 , sizeof( struct V_50 ) * 32 ) ;
F_18 ( V_7 ) ;
V_7 -> V_51 = F_4 ( sizeof( struct V_52 ) , V_11 ) ;
if ( V_7 -> V_51 == NULL ) {
F_19 ( V_53 , L_5 ) ;
return NULL ;
}
F_20 ( V_7 ) ;
F_21 ( V_7 ) ;
F_22 ( V_7 ) ;
for ( V_16 = 0 ; V_16 < V_54 ; V_16 ++ )
F_9 ( & V_7 -> V_55 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < 17 ; V_16 ++ ) {
V_7 -> V_56 [ V_16 ] = - 1 ;
V_7 -> V_57 [ V_16 ] = - 1 ;
V_7 -> V_58 [ V_16 ] = 0 ;
}
F_23 () ;
F_24 () ;
F_25 () ;
return V_13 ;
V_23:
if ( V_13 )
F_26 ( V_13 ) ;
return NULL ;
}
void F_27 ( struct V_20 * V_13 )
{
struct V_6 * V_7 = (struct V_6 * )
F_15 ( V_13 ) ;
int V_16 ;
F_7 ( V_7 -> V_51 ) ;
V_7 -> V_51 = NULL ;
F_28 ( V_7 ) ;
F_29 ( & V_7 -> V_33 ) ;
F_30 ( V_7 , 1 ) ;
for ( V_16 = 0 ; V_16 < V_59 ; V_16 ++ ) {
struct V_60 * V_61 = V_7 -> V_61 [ V_16 ] ;
if ( V_61 ) {
if ( V_61 -> V_62 )
V_61 -> V_62 -> V_63 ( V_61 -> V_64 ) ;
F_7 ( V_61 ) ;
V_7 -> V_61 [ V_16 ] = NULL ;
}
}
F_6 ( V_7 ) ;
F_26 ( V_13 ) ;
}
static int F_31 ( char * V_65 , char * * V_66 , T_1 V_67 ,
int V_68 , int * V_69 , void * V_4 )
{
return snprintf ( V_65 , V_68 , L_6 , V_70 ) ;
}
static int F_32 ( struct V_71 * V_71 , const char T_2 * V_72 ,
unsigned long V_68 , void * V_4 )
{
char V_73 [] = L_7 ;
unsigned long V_74 = F_33 ( ( unsigned long ) sizeof( V_73 ) - 1 , V_68 ) ;
char * V_75 = ( char * ) V_73 ;
unsigned long V_76 ;
if ( F_34 ( V_73 , V_72 , V_74 ) )
return V_68 ;
V_73 [ V_74 ] = 0 ;
if ( V_75 [ 1 ] == 'x' || V_75 [ 1 ] == 'X' || V_75 [ 0 ] == 'x' || V_75 [ 0 ] == 'X' ) {
V_75 ++ ;
if ( V_75 [ 0 ] == 'x' || V_75 [ 0 ] == 'X' )
V_75 ++ ;
V_76 = F_35 ( V_75 , & V_75 , 16 ) ;
} else
V_76 = F_35 ( V_75 , & V_75 , 10 ) ;
if ( V_75 == V_73 )
F_5 (KERN_INFO DRV_NAME
L_8 , buf) ;
else
V_70 = V_76 ;
return F_36 ( V_73 , V_68 ) ;
}
int T_3 F_37 ( void )
{
struct V_77 * V_78 ;
V_70 = V_79 ;
V_80 = F_38 ( V_81 , V_82 , V_83 . V_84 ) ;
if ( V_80 == NULL ) {
F_14 ( L_9 V_81
L_10 ) ;
return - V_85 ;
}
V_78 = F_38 ( L_11 , V_86 | V_87 | V_88 ,
V_80 ) ;
if ( ! V_78 ) {
F_39 ( V_81 , V_83 . V_84 ) ;
V_80 = NULL ;
return - V_85 ;
}
V_78 -> V_89 = F_31 ;
V_78 -> V_90 = F_32 ;
V_78 -> V_4 = NULL ;
return 0 ;
}
void T_4 F_40 ( void )
{
if ( V_80 ) {
F_39 ( L_11 , V_80 ) ;
F_39 ( V_81 , V_83 . V_84 ) ;
V_80 = NULL ;
}
}
