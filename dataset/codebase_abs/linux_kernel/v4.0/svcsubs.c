static inline void F_1 ( char * V_1 , struct V_2 * V_3 )
{
T_1 * V_4 = ( T_1 * ) V_3 -> V_5 ;
F_2 ( L_1 ,
V_1 , V_4 [ 0 ] , V_4 [ 1 ] , V_4 [ 2 ] , V_4 [ 3 ] ,
V_4 [ 4 ] , V_4 [ 5 ] , V_4 [ 6 ] , V_4 [ 7 ] ) ;
}
static inline void F_3 ( char * V_1 , struct V_6 * V_7 )
{
struct V_8 * V_8 = F_4 ( V_7 -> V_9 ) ;
F_2 ( L_2 ,
V_1 , V_8 -> V_10 -> V_11 , V_8 -> V_12 ) ;
}
static inline void F_1 ( char * V_1 , struct V_2 * V_3 )
{
return;
}
static inline void F_3 ( char * V_1 , struct V_6 * V_7 )
{
return;
}
static inline unsigned int F_5 ( struct V_2 * V_3 )
{
unsigned int V_13 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
V_13 += V_3 -> V_5 [ V_14 ] ;
return V_13 & ( V_16 - 1 ) ;
}
T_2
F_6 ( struct V_17 * V_18 , struct V_6 * * V_19 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 ;
unsigned int V_20 ;
T_2 V_21 ;
F_1 ( L_3 , V_3 ) ;
V_20 = F_5 ( V_3 ) ;
F_7 ( & V_22 ) ;
F_8 (file, &nlm_files[hash], f_list)
if ( ! F_9 ( & V_7 -> V_23 , V_3 ) )
goto V_24;
F_1 ( L_4 , V_3 ) ;
V_21 = V_25 ;
V_7 = F_10 ( sizeof( * V_7 ) , V_26 ) ;
if ( ! V_7 )
goto V_27;
memcpy ( & V_7 -> V_23 , V_3 , sizeof( struct V_2 ) ) ;
F_11 ( & V_7 -> V_28 ) ;
F_12 ( & V_7 -> V_29 ) ;
F_13 ( & V_7 -> V_30 ) ;
if ( ( V_21 = V_31 -> fopen ( V_18 , V_3 , & V_7 -> V_9 ) ) != 0 ) {
F_2 ( L_5 , V_21 ) ;
goto V_32;
}
F_14 ( & V_7 -> V_29 , & V_33 [ V_20 ] ) ;
V_24:
F_2 ( L_6 , V_7 , V_7 -> V_34 ) ;
* V_19 = V_7 ;
V_7 -> V_34 ++ ;
V_21 = 0 ;
V_27:
F_15 ( & V_22 ) ;
return V_21 ;
V_32:
F_16 ( V_7 ) ;
goto V_27;
}
static inline void
F_17 ( struct V_6 * V_7 )
{
F_3 ( L_7 , V_7 ) ;
if ( ! F_18 ( & V_7 -> V_29 ) ) {
F_19 ( & V_7 -> V_29 ) ;
V_31 -> fclose ( V_7 -> V_9 ) ;
F_16 ( V_7 ) ;
} else {
F_20 ( V_35 L_8 ) ;
}
}
static int
F_21 ( struct V_36 * V_37 , struct V_6 * V_7 ,
T_3 V_38 )
{
struct V_8 * V_8 = F_22 ( V_7 ) ;
struct V_39 * V_40 ;
struct V_41 * V_42 = V_8 -> V_43 ;
struct V_36 * V_44 ;
if ( ! V_42 || F_23 ( & V_42 -> V_45 ) )
return 0 ;
V_46:
V_7 -> V_47 = 0 ;
F_24 ( & V_42 -> V_48 ) ;
F_25 (fl, &flctx->flc_posix, fl_list) {
if ( V_40 -> V_49 != & V_50 )
continue;
V_7 -> V_47 ++ ;
V_44 = (struct V_36 * ) V_40 -> V_51 ;
if ( V_38 ( V_44 , V_37 ) ) {
struct V_39 V_52 = * V_40 ;
F_26 ( & V_42 -> V_48 ) ;
V_52 . V_53 = V_54 ;
V_52 . V_55 = 0 ;
V_52 . V_56 = V_57 ;
if ( F_27 ( V_7 -> V_9 , V_58 , & V_52 , NULL ) < 0 ) {
F_20 ( L_9 ,
__FILE__ , __LINE__ ) ;
return 1 ;
}
goto V_46;
}
}
F_26 ( & V_42 -> V_48 ) ;
return 0 ;
}
static int
F_28 ( void * V_59 , struct V_36 * V_60 )
{
return 1 ;
}
static inline int
F_29 ( struct V_36 * V_37 , struct V_6 * V_7 , T_3 V_38 )
{
F_30 ( V_37 , V_7 , V_38 ) ;
F_31 ( V_37 , V_7 , V_38 ) ;
return F_21 ( V_37 , V_7 , V_38 ) ;
}
static inline int
F_32 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_22 ( V_7 ) ;
struct V_39 * V_40 ;
struct V_41 * V_42 = V_8 -> V_43 ;
if ( V_7 -> V_34 || ! F_33 ( & V_7 -> V_30 ) || V_7 -> V_61 )
return 1 ;
if ( V_42 && ! F_23 ( & V_42 -> V_45 ) ) {
F_24 ( & V_42 -> V_48 ) ;
F_25 (fl, &flctx->flc_posix, fl_list) {
if ( V_40 -> V_49 == & V_50 ) {
F_26 ( & V_42 -> V_48 ) ;
return 1 ;
}
}
F_26 ( & V_42 -> V_48 ) ;
}
V_7 -> V_47 = 0 ;
return 0 ;
}
static int
F_34 ( void * V_5 , T_3 V_38 ,
int (* F_35)( void * V_5 , struct V_6 * V_7 ) )
{
struct V_62 * V_63 ;
struct V_6 * V_7 ;
int V_14 , V_64 = 0 ;
F_7 ( & V_22 ) ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
F_36 (file, next, &nlm_files[i], f_list) {
if ( F_35 && ! F_35 ( V_5 , V_7 ) )
continue;
V_7 -> V_34 ++ ;
F_15 ( & V_22 ) ;
if ( F_29 ( V_5 , V_7 , V_38 ) )
V_64 = 1 ;
F_7 ( & V_22 ) ;
V_7 -> V_34 -- ;
if ( F_33 ( & V_7 -> V_30 ) && ! V_7 -> V_47
&& ! V_7 -> V_61 && ! V_7 -> V_34 ) {
F_19 ( & V_7 -> V_29 ) ;
V_31 -> fclose ( V_7 -> V_9 ) ;
F_16 ( V_7 ) ;
}
}
}
F_15 ( & V_22 ) ;
return V_64 ;
}
void
F_37 ( struct V_6 * V_7 )
{
F_2 ( L_10 ,
V_7 , V_7 -> V_34 ) ;
F_7 ( & V_22 ) ;
if ( -- V_7 -> V_34 == 0 && ! F_32 ( V_7 ) )
F_17 ( V_7 ) ;
F_15 ( & V_22 ) ;
}
static int
F_38 ( void * V_5 , struct V_36 * V_65 )
{
struct V_36 * V_37 = V_5 ;
if ( ( V_65 -> V_66 == NULL ) ||
( V_37 -> V_66 == V_65 -> V_66 ) )
V_37 -> V_67 = 1 ;
return 0 ;
}
static int
F_39 ( void * V_5 , struct V_36 * V_68 )
{
struct V_36 * V_37 = V_5 ;
return V_37 == V_68 ;
}
static int
F_40 ( void * V_5 , struct V_36 * V_69 )
{
struct V_36 * V_37 = V_5 ;
if ( V_37 -> V_70 ) {
if ( V_37 -> V_71 )
V_37 -> V_71 -> V_72 = 1 ;
return 1 ;
} else
return 0 ;
}
void
F_41 ( struct V_66 * V_66 )
{
struct V_36 V_65 ;
F_2 ( L_11 , V_66 ) ;
V_65 . V_66 = V_66 ;
F_34 ( & V_65 , F_38 , NULL ) ;
}
void
F_42 ( struct V_36 * V_37 )
{
F_2 ( L_12 ) ;
if ( F_34 ( V_37 , F_39 , NULL ) ) {
F_20 ( V_35
L_13 ,
V_37 -> V_73 ) ;
F_43 () ;
}
}
void
F_44 ( void )
{
F_34 ( NULL , F_40 , NULL ) ;
}
static int
F_45 ( void * V_74 , struct V_6 * V_7 )
{
struct V_75 * V_76 = V_74 ;
return V_76 == F_4 ( V_7 -> V_9 ) -> V_10 ;
}
int
F_46 ( struct V_75 * V_76 )
{
int V_64 ;
V_64 = F_34 ( V_76 , F_28 , F_45 ) ;
return V_64 ? - V_77 : 0 ;
}
static int
F_47 ( void * V_74 , struct V_36 * V_37 )
{
return F_48 ( F_49 ( V_37 ) , V_74 ) ;
}
int
F_50 ( struct V_78 * V_79 )
{
int V_64 ;
V_64 = F_34 ( V_79 , F_47 , NULL ) ;
return V_64 ? - V_77 : 0 ;
}
