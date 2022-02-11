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
struct V_36 * V_41 ;
V_42:
V_7 -> V_43 = 0 ;
F_23 () ;
for ( V_40 = V_8 -> V_44 ; V_40 ; V_40 = V_40 -> V_45 ) {
if ( V_40 -> V_46 != & V_47 )
continue;
V_7 -> V_43 ++ ;
V_41 = (struct V_36 * ) V_40 -> V_48 ;
if ( V_38 ( V_41 , V_37 ) ) {
struct V_39 V_49 = * V_40 ;
F_24 () ;
V_49 . V_50 = V_51 ;
V_49 . V_52 = 0 ;
V_49 . V_53 = V_54 ;
if ( F_25 ( V_7 -> V_9 , V_55 , & V_49 , NULL ) < 0 ) {
F_20 ( L_9 ,
__FILE__ , __LINE__ ) ;
return 1 ;
}
goto V_42;
}
}
F_24 () ;
return 0 ;
}
static int
F_26 ( void * V_56 , struct V_36 * V_57 )
{
return 1 ;
}
static inline int
F_27 ( struct V_36 * V_37 , struct V_6 * V_7 , T_3 V_38 )
{
F_28 ( V_37 , V_7 , V_38 ) ;
F_29 ( V_37 , V_7 , V_38 ) ;
return F_21 ( V_37 , V_7 , V_38 ) ;
}
static inline int
F_30 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_22 ( V_7 ) ;
struct V_39 * V_40 ;
if ( V_7 -> V_34 || ! F_31 ( & V_7 -> V_30 ) || V_7 -> V_58 )
return 1 ;
F_23 () ;
for ( V_40 = V_8 -> V_44 ; V_40 ; V_40 = V_40 -> V_45 ) {
if ( V_40 -> V_46 == & V_47 ) {
F_24 () ;
return 1 ;
}
}
F_24 () ;
V_7 -> V_43 = 0 ;
return 0 ;
}
static int
F_32 ( void * V_5 , T_3 V_38 ,
int (* F_33)( void * V_5 , struct V_6 * V_7 ) )
{
struct V_59 * V_60 ;
struct V_6 * V_7 ;
int V_14 , V_61 = 0 ;
F_7 ( & V_22 ) ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
F_34 (file, next, &nlm_files[i], f_list) {
if ( F_33 && ! F_33 ( V_5 , V_7 ) )
continue;
V_7 -> V_34 ++ ;
F_15 ( & V_22 ) ;
if ( F_27 ( V_5 , V_7 , V_38 ) )
V_61 = 1 ;
F_7 ( & V_22 ) ;
V_7 -> V_34 -- ;
if ( F_31 ( & V_7 -> V_30 ) && ! V_7 -> V_43
&& ! V_7 -> V_58 && ! V_7 -> V_34 ) {
F_19 ( & V_7 -> V_29 ) ;
V_31 -> fclose ( V_7 -> V_9 ) ;
F_16 ( V_7 ) ;
}
}
}
F_15 ( & V_22 ) ;
return V_61 ;
}
void
F_35 ( struct V_6 * V_7 )
{
F_2 ( L_10 ,
V_7 , V_7 -> V_34 ) ;
F_7 ( & V_22 ) ;
if ( -- V_7 -> V_34 == 0 && ! F_30 ( V_7 ) )
F_17 ( V_7 ) ;
F_15 ( & V_22 ) ;
}
static int
F_36 ( void * V_5 , struct V_36 * V_62 )
{
struct V_36 * V_37 = V_5 ;
if ( ( V_62 -> V_63 == NULL ) ||
( V_37 -> V_63 == V_62 -> V_63 ) )
V_37 -> V_64 = 1 ;
return 0 ;
}
static int
F_37 ( void * V_5 , struct V_36 * V_65 )
{
struct V_36 * V_37 = V_5 ;
return V_37 == V_65 ;
}
static int
F_38 ( void * V_5 , struct V_36 * V_66 )
{
struct V_36 * V_37 = V_5 ;
if ( V_37 -> V_67 ) {
if ( V_37 -> V_68 )
V_37 -> V_68 -> V_69 = 1 ;
return 1 ;
} else
return 0 ;
}
void
F_39 ( struct V_63 * V_63 )
{
struct V_36 V_62 ;
F_2 ( L_11 , V_63 ) ;
V_62 . V_63 = V_63 ;
F_32 ( & V_62 , F_36 , NULL ) ;
}
void
F_40 ( struct V_36 * V_37 )
{
F_2 ( L_12 ) ;
if ( F_32 ( V_37 , F_37 , NULL ) ) {
F_20 ( V_35
L_13 ,
V_37 -> V_70 ) ;
F_41 () ;
}
}
void
F_42 ( void )
{
F_32 ( NULL , F_38 , NULL ) ;
}
static int
F_43 ( void * V_71 , struct V_6 * V_7 )
{
struct V_72 * V_73 = V_71 ;
return V_73 == V_7 -> V_9 -> V_74 . V_75 -> V_76 ;
}
int
F_44 ( struct V_72 * V_73 )
{
int V_61 ;
V_61 = F_32 ( V_73 , F_26 , F_43 ) ;
return V_61 ? - V_77 : 0 ;
}
static int
F_45 ( void * V_71 , struct V_36 * V_37 )
{
return F_46 ( F_47 ( V_37 ) , V_71 ) ;
}
int
F_48 ( struct V_78 * V_79 )
{
int V_61 ;
V_61 = F_32 ( V_79 , F_45 , NULL ) ;
return V_61 ? - V_77 : 0 ;
}
