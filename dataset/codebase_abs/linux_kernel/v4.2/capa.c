static inline
unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 -> V_4 . V_5 ;
}
struct V_6 * F_3 ( void )
{
struct V_6 * V_7 ;
int V_8 , V_9 ;
V_7 = F_4 ( V_10 , V_11 ) ;
if ( ! V_7 )
return NULL ;
V_8 = V_10 / sizeof( struct V_6 ) ;
F_5 ( V_8 > V_12 ) ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
F_6 ( V_7 + V_9 ) ;
return V_7 ;
}
static inline int F_7 ( struct V_13 * V_14 )
{
return V_14 -> V_15 == V_16 ;
}
static inline void F_8 ( struct V_13 * V_14 )
{
F_5 ( F_7 ( V_14 ) ) ;
F_9 ( & V_14 -> V_17 . V_18 . V_19 ) ;
F_10 ( & V_14 -> V_20 ) ;
V_21 [ V_14 -> V_15 ] -- ;
F_11 ( V_14 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
int V_9 ;
struct V_22 * V_23 ;
struct V_13 * V_24 ;
F_13 ( & V_25 ) ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
F_14 (oc, next, hash + i,
u.tgt.c_hash)
F_8 ( V_24 ) ;
}
F_15 ( & V_25 ) ;
F_16 ( V_7 ) ;
}
static inline int F_17 ( struct V_26 * V_27 )
{
return ( F_18 ( V_27 ) ^ F_19 ( V_27 ) ) *
( unsigned long ) ( F_20 ( V_27 ) + 1 ) % V_12 ;
}
static inline int F_21 ( struct V_13 * V_24 )
{
return F_22 ( F_23 ( V_24 -> V_28 ,
F_24 ( V_24 -> V_29 . V_30 ) * 2 / 3 ) ,
F_25 () ) ;
}
static struct V_13 * F_26 ( struct V_31 * V_32 ,
struct V_6 * V_33 , int V_34 )
{
struct V_13 * V_14 ;
int V_35 = V_34 ? F_27 ( struct V_31 , V_36 ) : sizeof( * V_32 ) ;
F_28 (ocapa, head, u.tgt.c_hash) {
if ( memcmp ( & V_14 -> V_29 , V_32 , V_35 ) )
continue;
if ( V_34 && F_21 ( V_14 ) )
continue;
F_5 ( F_7 ( V_14 ) ) ;
F_29 ( V_37 , & V_14 -> V_29 , L_1 ) ;
return V_14 ;
}
return NULL ;
}
static inline void F_30 ( struct V_38 * V_33 )
{
struct V_13 * V_14 ;
struct V_38 * V_39 = V_33 -> V_23 ;
int V_40 = 0 ;
while ( V_40 ++ < V_41 ) {
V_14 = F_31 ( V_39 , struct V_13 , V_20 ) ;
V_39 = V_39 -> V_23 ;
if ( F_32 ( & V_14 -> V_42 ) )
continue;
F_29 ( V_37 , & V_14 -> V_29 , L_2 ) ;
F_8 ( V_14 ) ;
}
}
struct V_13 * F_33 ( struct V_6 * V_7 , struct V_31 * V_32 )
{
struct V_6 * V_33 = V_7 + F_17 ( & V_32 -> V_43 ) ;
struct V_13 * V_14 , * V_44 = NULL ;
struct V_38 * V_45 = & V_46 [ V_16 ] ;
V_14 = F_34 ( V_16 ) ;
if ( F_35 ( V_14 ) )
return NULL ;
F_13 ( & V_25 ) ;
V_44 = F_26 ( V_32 , V_33 , 0 ) ;
if ( ! V_44 ) {
V_14 -> V_29 = * V_32 ;
F_36 ( V_14 ) ;
F_37 ( & V_14 -> V_17 . V_18 . V_19 , V_33 ) ;
F_38 ( & V_14 -> V_20 , V_45 ) ;
F_39 ( V_14 ) ;
V_21 [ V_16 ] ++ ;
if ( V_21 [ V_16 ] > V_47 )
F_30 ( V_45 ) ;
F_15 ( & V_25 ) ;
return V_14 ;
}
F_39 ( V_44 ) ;
F_15 ( & V_25 ) ;
F_11 ( V_14 ) ;
return V_44 ;
}
struct V_13 * F_40 ( struct V_6 * V_7 , struct V_31 * V_32 ,
int V_34 )
{
struct V_13 * V_14 ;
F_13 ( & V_25 ) ;
V_14 = F_26 ( V_32 , V_7 + F_17 ( & V_32 -> V_43 ) , V_34 ) ;
if ( V_14 ) {
F_41 ( & V_14 -> V_20 ,
& V_46 [ V_16 ] ) ;
F_39 ( V_14 ) ;
}
F_15 ( & V_25 ) ;
return V_14 ;
}
static inline int F_42 ( struct V_48 * V_2 ,
T_1 * V_49 , unsigned int * V_50 ,
struct V_51 * V_52 ,
unsigned int V_53 , T_1 * V_54 )
{
struct V_55 V_56 ;
int V_57 ;
V_56 . V_2 = V_2 ;
V_56 . V_58 = 0 ;
V_57 = F_43 ( V_56 . V_2 , V_49 , * V_50 ) ;
if ( V_57 ) {
F_44 ( L_3 , V_57 ) ;
return V_57 ;
}
return F_45 ( & V_56 , V_52 , V_53 , V_54 ) ;
}
int F_46 ( T_2 * V_59 , struct V_31 * V_32 , T_2 * V_49 )
{
struct V_48 * V_2 ;
struct V_60 * V_61 ;
int V_50 ;
struct V_51 V_62 ;
if ( F_47 ( V_32 ) != V_63 ) {
F_44 ( L_4 ) ;
return - V_64 ;
}
V_61 = & V_65 [ F_47 ( V_32 ) ] ;
V_2 = F_48 ( V_61 -> V_66 , 0 , 0 ) ;
if ( F_35 ( V_2 ) ) {
F_44 ( L_5 ) ;
return F_49 ( V_2 ) ;
}
V_50 = V_61 -> V_67 ;
F_50 ( & V_62 , 1 ) ;
F_51 ( & V_62 , F_52 ( V_32 ) ,
F_27 ( struct V_31 , V_68 ) ,
( unsigned long ) ( V_32 ) % V_10 ) ;
F_42 ( V_2 , V_49 , & V_50 , & V_62 , V_62 . V_69 , V_59 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
int F_54 ( T_3 * V_70 , T_3 * V_71 , T_2 * V_49 , int V_50 )
{
struct V_1 * V_2 ;
struct V_51 V_72 ;
struct V_51 V_73 ;
struct V_74 V_56 ;
unsigned int V_75 ;
int V_76 ;
char V_61 [ V_77 + 1 ] = L_6 ;
V_2 = F_55 ( V_61 , 0 , 0 ) ;
if ( F_35 ( V_2 ) ) {
F_44 ( L_7 ) ;
return F_49 ( V_2 ) ;
}
V_75 = F_1 ( V_2 ) ;
if ( V_50 < V_75 ) {
F_44 ( L_8 , V_75 * 8 ) ;
V_76 = - V_78 ;
goto V_79;
}
V_76 = F_56 ( V_2 , V_49 , V_75 ) ;
if ( V_76 ) {
F_44 ( L_9 ) ;
goto V_79;
}
F_50 ( & V_72 , 1 ) ;
F_51 ( & V_72 , F_52 ( V_70 ) , 16 ,
( unsigned long ) ( V_70 ) % V_10 ) ;
F_50 ( & V_73 , 1 ) ;
F_51 ( & V_73 , F_52 ( V_71 ) , 16 ,
( unsigned long ) ( V_71 ) % V_10 ) ;
V_56 . V_2 = V_2 ;
V_56 . V_80 = NULL ;
V_56 . V_58 = 0 ;
V_76 = F_57 ( & V_56 , & V_72 , & V_73 , 16 ) ;
if ( V_76 ) {
F_44 ( L_10 ) ;
goto V_79;
}
V_79:
F_58 ( V_2 ) ;
return V_76 ;
}
int F_59 ( T_3 * V_70 , T_3 * V_71 , T_2 * V_49 , int V_50 )
{
struct V_1 * V_2 ;
struct V_51 V_72 ;
struct V_51 V_73 ;
struct V_74 V_56 ;
unsigned int V_75 ;
int V_76 ;
char V_61 [ V_77 + 1 ] = L_6 ;
V_2 = F_55 ( V_61 , 0 , 0 ) ;
if ( F_35 ( V_2 ) ) {
F_44 ( L_7 ) ;
return F_49 ( V_2 ) ;
}
V_75 = F_1 ( V_2 ) ;
if ( V_50 < V_75 ) {
F_44 ( L_8 , V_75 * 8 ) ;
V_76 = - V_78 ;
goto V_79;
}
V_76 = F_56 ( V_2 , V_49 , V_75 ) ;
if ( V_76 ) {
F_44 ( L_9 ) ;
goto V_79;
}
F_50 ( & V_72 , 1 ) ;
F_51 ( & V_72 , F_52 ( V_70 ) , 16 ,
( unsigned long ) ( V_70 ) % V_10 ) ;
F_50 ( & V_73 , 1 ) ;
F_51 ( & V_73 , F_52 ( V_71 ) , 16 ,
( unsigned long ) ( V_71 ) % V_10 ) ;
V_56 . V_2 = V_2 ;
V_56 . V_80 = NULL ;
V_56 . V_58 = 0 ;
V_76 = F_60 ( & V_56 , & V_72 , & V_73 , 16 ) ;
if ( V_76 ) {
F_44 ( L_11 ) ;
goto V_79;
}
V_79:
F_58 ( V_2 ) ;
return V_76 ;
}
void F_61 ( void * V_32 , struct V_13 * V_14 )
{
F_13 ( & V_14 -> V_81 ) ;
* (struct V_31 * ) V_32 = V_14 -> V_29 ;
F_15 ( & V_14 -> V_81 ) ;
}
void F_62 ( struct V_31 * V_82 ,
struct V_83 * V_84 ,
const char * V_85 , ... )
{
T_4 args ;
va_start ( args , V_85 ) ;
F_63 ( V_84 , V_85 , args ,
L_12 V_86 L_13 ,
V_82 , F_64 ( F_65 ( V_82 ) ) , F_66 ( V_82 ) ,
F_67 ( V_82 ) , F_68 ( V_82 ) , F_69 ( V_82 ) ,
F_47 ( V_82 ) , F_70 ( V_82 ) , F_71 ( V_82 ) ,
F_72 ( V_82 ) ) ;
va_end ( args ) ;
}
