static inline void F_1 ( char * V_1 , struct V_2 * V_3 )
{
T_1 * V_4 = ( T_1 * ) V_3 -> V_5 ;
F_2 ( L_1 ,
V_1 , V_4 [ 0 ] , V_4 [ 1 ] , V_4 [ 2 ] , V_4 [ 3 ] ,
V_4 [ 4 ] , V_4 [ 5 ] , V_4 [ 6 ] , V_4 [ 7 ] ) ;
}
static inline void F_3 ( char * V_1 , struct V_6 * V_7 )
{
struct V_8 * V_8 = V_7 -> V_9 -> V_10 . V_11 -> V_12 ;
F_2 ( L_2 ,
V_1 , V_8 -> V_13 -> V_14 , V_8 -> V_15 ) ;
}
static inline void F_1 ( char * V_1 , struct V_2 * V_3 )
{
return;
}
static inline void F_3 ( char * V_1 , struct V_6 * V_7 )
{
return;
}
static inline unsigned int F_4 ( struct V_2 * V_3 )
{
unsigned int V_16 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
V_16 += V_3 -> V_5 [ V_17 ] ;
return V_16 & ( V_19 - 1 ) ;
}
T_2
F_5 ( struct V_20 * V_21 , struct V_6 * * V_22 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 ;
struct V_6 * V_7 ;
unsigned int V_25 ;
T_2 V_26 ;
F_1 ( L_3 , V_3 ) ;
V_25 = F_4 ( V_3 ) ;
F_6 ( & V_27 ) ;
F_7 (file, pos, &nlm_files[hash], f_list)
if ( ! F_8 ( & V_7 -> V_28 , V_3 ) )
goto V_29;
F_1 ( L_4 , V_3 ) ;
V_26 = V_30 ;
V_7 = F_9 ( sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
goto V_32;
memcpy ( & V_7 -> V_28 , V_3 , sizeof( struct V_2 ) ) ;
F_10 ( & V_7 -> V_33 ) ;
F_11 ( & V_7 -> V_34 ) ;
F_12 ( & V_7 -> V_35 ) ;
if ( ( V_26 = V_36 -> fopen ( V_21 , V_3 , & V_7 -> V_9 ) ) != 0 ) {
F_2 ( L_5 , V_26 ) ;
goto V_37;
}
F_13 ( & V_7 -> V_34 , & V_38 [ V_25 ] ) ;
V_29:
F_2 ( L_6 , V_7 , V_7 -> V_39 ) ;
* V_22 = V_7 ;
V_7 -> V_39 ++ ;
V_26 = 0 ;
V_32:
F_14 ( & V_27 ) ;
return V_26 ;
V_37:
F_15 ( V_7 ) ;
goto V_32;
}
static inline void
F_16 ( struct V_6 * V_7 )
{
F_3 ( L_7 , V_7 ) ;
if ( ! F_17 ( & V_7 -> V_34 ) ) {
F_18 ( & V_7 -> V_34 ) ;
V_36 -> fclose ( V_7 -> V_9 ) ;
F_15 ( V_7 ) ;
} else {
F_19 ( V_40 L_8 ) ;
}
}
static int
F_20 ( struct V_41 * V_42 , struct V_6 * V_7 ,
T_3 V_43 )
{
struct V_8 * V_8 = F_21 ( V_7 ) ;
struct V_44 * V_45 ;
struct V_41 * V_46 ;
V_47:
V_7 -> V_48 = 0 ;
F_22 () ;
for ( V_45 = V_8 -> V_49 ; V_45 ; V_45 = V_45 -> V_50 ) {
if ( V_45 -> V_51 != & V_52 )
continue;
V_7 -> V_48 ++ ;
V_46 = (struct V_41 * ) V_45 -> V_53 ;
if ( V_43 ( V_46 , V_42 ) ) {
struct V_44 V_54 = * V_45 ;
F_23 () ;
V_54 . V_55 = V_56 ;
V_54 . V_57 = 0 ;
V_54 . V_58 = V_59 ;
if ( F_24 ( V_7 -> V_9 , V_60 , & V_54 , NULL ) < 0 ) {
F_19 ( L_9 ,
__FILE__ , __LINE__ ) ;
return 1 ;
}
goto V_47;
}
}
F_23 () ;
return 0 ;
}
static int
F_25 ( void * V_61 , struct V_41 * V_62 )
{
return 1 ;
}
static inline int
F_26 ( struct V_41 * V_42 , struct V_6 * V_7 , T_3 V_43 )
{
F_27 ( V_42 , V_7 , V_43 ) ;
F_28 ( V_42 , V_7 , V_43 ) ;
return F_20 ( V_42 , V_7 , V_43 ) ;
}
static inline int
F_29 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_21 ( V_7 ) ;
struct V_44 * V_45 ;
if ( V_7 -> V_39 || ! F_30 ( & V_7 -> V_35 ) || V_7 -> V_63 )
return 1 ;
F_22 () ;
for ( V_45 = V_8 -> V_49 ; V_45 ; V_45 = V_45 -> V_50 ) {
if ( V_45 -> V_51 == & V_52 ) {
F_23 () ;
return 1 ;
}
}
F_23 () ;
V_7 -> V_48 = 0 ;
return 0 ;
}
static int
F_31 ( void * V_5 , T_3 V_43 ,
int (* F_32)( void * V_5 , struct V_6 * V_7 ) )
{
struct V_23 * V_24 , * V_64 ;
struct V_6 * V_7 ;
int V_17 , V_65 = 0 ;
F_6 ( & V_27 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
F_33 (file, pos, next, &nlm_files[i], f_list) {
if ( F_32 && ! F_32 ( V_5 , V_7 ) )
continue;
V_7 -> V_39 ++ ;
F_14 ( & V_27 ) ;
if ( F_26 ( V_5 , V_7 , V_43 ) )
V_65 = 1 ;
F_6 ( & V_27 ) ;
V_7 -> V_39 -- ;
if ( F_30 ( & V_7 -> V_35 ) && ! V_7 -> V_48
&& ! V_7 -> V_63 && ! V_7 -> V_39 ) {
F_18 ( & V_7 -> V_34 ) ;
V_36 -> fclose ( V_7 -> V_9 ) ;
F_15 ( V_7 ) ;
}
}
}
F_14 ( & V_27 ) ;
return V_65 ;
}
void
F_34 ( struct V_6 * V_7 )
{
F_2 ( L_10 ,
V_7 , V_7 -> V_39 ) ;
F_6 ( & V_27 ) ;
if ( -- V_7 -> V_39 == 0 && ! F_29 ( V_7 ) )
F_16 ( V_7 ) ;
F_14 ( & V_27 ) ;
}
static int
F_35 ( void * V_5 , struct V_41 * V_66 )
{
struct V_41 * V_42 = V_5 ;
if ( ( V_66 -> V_67 == NULL ) ||
( V_42 -> V_67 == V_66 -> V_67 ) )
V_42 -> V_68 = 1 ;
return 0 ;
}
static int
F_36 ( void * V_5 , struct V_41 * V_69 )
{
struct V_41 * V_42 = V_5 ;
return V_42 == V_69 ;
}
static int
F_37 ( void * V_5 , struct V_41 * V_70 )
{
struct V_41 * V_42 = V_5 ;
if ( V_42 -> V_71 ) {
if ( V_42 -> V_72 )
V_42 -> V_72 -> V_73 = 1 ;
return 1 ;
} else
return 0 ;
}
void
F_38 ( struct V_67 * V_67 )
{
struct V_41 V_66 ;
F_2 ( L_11 , V_67 ) ;
V_66 . V_67 = V_67 ;
F_31 ( & V_66 , F_35 , NULL ) ;
}
void
F_39 ( struct V_41 * V_42 )
{
F_2 ( L_12 ) ;
if ( F_31 ( V_42 , F_36 , NULL ) ) {
F_19 ( V_40
L_13 ,
V_42 -> V_74 ) ;
F_40 () ;
}
}
void
F_41 ( void )
{
F_31 ( NULL , F_37 , NULL ) ;
}
static int
F_42 ( void * V_75 , struct V_6 * V_7 )
{
struct V_76 * V_77 = V_75 ;
return V_77 == V_7 -> V_9 -> V_10 . V_11 -> V_78 ;
}
int
F_43 ( struct V_76 * V_77 )
{
int V_65 ;
V_65 = F_31 ( V_77 , F_25 , F_42 ) ;
return V_65 ? - V_79 : 0 ;
}
static int
F_44 ( void * V_75 , struct V_41 * V_42 )
{
return F_45 ( F_46 ( V_42 ) , V_75 ) ;
}
int
F_47 ( struct V_80 * V_81 )
{
int V_65 ;
V_65 = F_31 ( V_81 , F_44 , NULL ) ;
return V_65 ? - V_79 : 0 ;
}
