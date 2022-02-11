static inline
unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 -> V_4 . V_5 ;
}
struct V_6 * F_3 ( void )
{
struct V_6 * V_7 ;
int V_8 , V_9 ;
F_4 ( V_7 , V_10 ) ;
if ( ! V_7 )
return NULL ;
V_8 = V_10 / sizeof( struct V_6 ) ;
F_5 ( V_8 > V_11 ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_6 ( V_7 + V_9 ) ;
return V_7 ;
}
static inline int F_7 ( struct V_12 * V_13 )
{
return V_13 -> V_14 == V_15 ;
}
static inline void F_8 ( struct V_12 * V_13 )
{
F_5 ( F_7 ( V_13 ) ) ;
F_9 ( & V_13 -> V_16 . V_17 . V_18 ) ;
F_10 ( & V_13 -> V_19 ) ;
V_20 [ V_13 -> V_14 ] -- ;
F_11 ( V_13 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
int V_9 ;
struct V_21 * V_22 ;
struct V_12 * V_23 ;
F_13 ( & V_24 ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
F_14 (oc, next, hash + i,
u.tgt.c_hash)
F_8 ( V_23 ) ;
}
F_15 ( & V_24 ) ;
F_16 ( V_7 , V_10 ) ;
}
static inline int F_17 ( struct V_25 * V_26 )
{
return ( F_18 ( V_26 ) ^ F_19 ( V_26 ) ) *
( unsigned long ) ( F_20 ( V_26 ) + 1 ) % V_11 ;
}
static inline int F_21 ( struct V_12 * V_23 )
{
return F_22 ( F_23 ( V_23 -> V_27 ,
F_24 ( V_23 -> V_28 . V_29 ) * 2 / 3 ) ,
F_25 () ) ;
}
static struct V_12 * F_26 ( struct V_30 * V_31 ,
struct V_6 * V_32 , int V_33 )
{
struct V_12 * V_13 ;
int V_34 = V_33 ? F_27 ( struct V_30 , V_35 ) : sizeof( * V_31 ) ;
F_28 (ocapa, head, u.tgt.c_hash) {
if ( memcmp ( & V_13 -> V_28 , V_31 , V_34 ) )
continue;
if ( V_33 && F_21 ( V_13 ) )
continue;
F_5 ( F_7 ( V_13 ) ) ;
F_29 ( V_36 , & V_13 -> V_28 , L_1 ) ;
return V_13 ;
}
return NULL ;
}
static inline void F_30 ( struct V_37 * V_32 )
{
struct V_12 * V_13 ;
struct V_37 * V_38 = V_32 -> V_22 ;
int V_39 = 0 ;
while ( V_39 ++ < V_40 ) {
V_13 = F_31 ( V_38 , struct V_12 , V_19 ) ;
V_38 = V_38 -> V_22 ;
if ( F_32 ( & V_13 -> V_41 ) )
continue;
F_29 ( V_36 , & V_13 -> V_28 , L_2 ) ;
F_8 ( V_13 ) ;
}
}
struct V_12 * F_33 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
struct V_6 * V_32 = V_7 + F_17 ( & V_31 -> V_42 ) ;
struct V_12 * V_13 , * V_43 = NULL ;
struct V_37 * V_44 = & V_45 [ V_15 ] ;
V_13 = F_34 ( V_15 ) ;
if ( F_35 ( V_13 ) )
return NULL ;
F_13 ( & V_24 ) ;
V_43 = F_26 ( V_31 , V_32 , 0 ) ;
if ( ! V_43 ) {
V_13 -> V_28 = * V_31 ;
F_36 ( V_13 ) ;
F_37 ( & V_13 -> V_16 . V_17 . V_18 , V_32 ) ;
F_38 ( & V_13 -> V_19 , V_44 ) ;
F_39 ( V_13 ) ;
V_20 [ V_15 ] ++ ;
if ( V_20 [ V_15 ] > V_46 )
F_30 ( V_44 ) ;
F_15 ( & V_24 ) ;
return V_13 ;
}
F_39 ( V_43 ) ;
F_15 ( & V_24 ) ;
F_11 ( V_13 ) ;
return V_43 ;
}
struct V_12 * F_40 ( struct V_6 * V_7 , struct V_30 * V_31 ,
int V_33 )
{
struct V_12 * V_13 ;
F_13 ( & V_24 ) ;
V_13 = F_26 ( V_31 , V_7 + F_17 ( & V_31 -> V_42 ) , V_33 ) ;
if ( V_13 ) {
F_41 ( & V_13 -> V_19 ,
& V_45 [ V_15 ] ) ;
F_39 ( V_13 ) ;
}
F_15 ( & V_24 ) ;
return V_13 ;
}
static inline int F_42 ( struct V_47 * V_2 ,
T_1 * V_48 , unsigned int * V_49 ,
struct V_50 * V_51 ,
unsigned int V_52 , T_1 * V_53 )
{
struct V_54 V_55 ;
int V_56 ;
V_55 . V_2 = V_2 ;
V_55 . V_57 = 0 ;
V_56 = F_43 ( V_55 . V_2 , V_48 , * V_49 ) ;
if ( V_56 ) {
F_44 ( L_3 , V_56 ) ;
return V_56 ;
}
return F_45 ( & V_55 , V_51 , V_52 , V_53 ) ;
}
int F_46 ( T_2 * V_58 , struct V_30 * V_31 , T_2 * V_48 )
{
struct V_47 * V_2 ;
struct V_59 * V_60 ;
int V_49 ;
struct V_50 V_61 ;
if ( F_47 ( V_31 ) != V_62 ) {
F_44 ( L_4 ) ;
return - V_63 ;
}
V_60 = & V_64 [ F_47 ( V_31 ) ] ;
V_2 = F_48 ( V_60 -> V_65 , 0 , 0 ) ;
if ( F_35 ( V_2 ) ) {
F_44 ( L_5 ) ;
return F_49 ( V_2 ) ;
}
V_49 = V_60 -> V_66 ;
F_50 ( & V_61 , 1 ) ;
F_51 ( & V_61 , F_52 ( V_31 ) ,
F_27 ( struct V_30 , V_67 ) ,
( unsigned long ) ( V_31 ) % V_10 ) ;
F_42 ( V_2 , V_48 , & V_49 , & V_61 , V_61 . V_68 , V_58 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
int F_54 ( T_3 * V_69 , T_3 * V_70 , T_2 * V_48 , int V_49 )
{
struct V_1 * V_2 ;
struct V_50 V_71 ;
struct V_50 V_72 ;
struct V_73 V_55 ;
unsigned int V_74 ;
int V_75 ;
char V_60 [ V_76 + 1 ] = L_6 ;
V_2 = F_55 ( V_60 , 0 , 0 ) ;
if ( F_35 ( V_2 ) ) {
F_44 ( L_7 ) ;
return F_49 ( V_2 ) ;
}
V_74 = F_1 ( V_2 ) ;
if ( V_49 < V_74 ) {
F_44 ( L_8 , V_74 * 8 ) ;
V_75 = - V_77 ;
goto V_78;
}
V_75 = F_56 ( V_2 , V_48 , V_74 ) ;
if ( V_75 ) {
F_44 ( L_9 ) ;
goto V_78;
}
F_50 ( & V_71 , 1 ) ;
F_51 ( & V_71 , F_52 ( V_69 ) , 16 ,
( unsigned long ) ( V_69 ) % V_10 ) ;
F_50 ( & V_72 , 1 ) ;
F_51 ( & V_72 , F_52 ( V_70 ) , 16 ,
( unsigned long ) ( V_70 ) % V_10 ) ;
V_55 . V_2 = V_2 ;
V_55 . V_79 = NULL ;
V_55 . V_57 = 0 ;
V_75 = F_57 ( & V_55 , & V_71 , & V_72 , 16 ) ;
if ( V_75 ) {
F_44 ( L_10 ) ;
goto V_78;
}
V_78:
F_58 ( V_2 ) ;
return V_75 ;
}
int F_59 ( T_3 * V_69 , T_3 * V_70 , T_2 * V_48 , int V_49 )
{
struct V_1 * V_2 ;
struct V_50 V_71 ;
struct V_50 V_72 ;
struct V_73 V_55 ;
unsigned int V_74 ;
int V_75 ;
char V_60 [ V_76 + 1 ] = L_6 ;
V_2 = F_55 ( V_60 , 0 , 0 ) ;
if ( F_35 ( V_2 ) ) {
F_44 ( L_7 ) ;
return F_49 ( V_2 ) ;
}
V_74 = F_1 ( V_2 ) ;
if ( V_49 < V_74 ) {
F_44 ( L_8 , V_74 * 8 ) ;
V_75 = - V_77 ;
goto V_78;
}
V_75 = F_56 ( V_2 , V_48 , V_74 ) ;
if ( V_75 ) {
F_44 ( L_9 ) ;
goto V_78;
}
F_50 ( & V_71 , 1 ) ;
F_51 ( & V_71 , F_52 ( V_69 ) , 16 ,
( unsigned long ) ( V_69 ) % V_10 ) ;
F_50 ( & V_72 , 1 ) ;
F_51 ( & V_72 , F_52 ( V_70 ) , 16 ,
( unsigned long ) ( V_70 ) % V_10 ) ;
V_55 . V_2 = V_2 ;
V_55 . V_79 = NULL ;
V_55 . V_57 = 0 ;
V_75 = F_60 ( & V_55 , & V_71 , & V_72 , 16 ) ;
if ( V_75 ) {
F_44 ( L_11 ) ;
goto V_78;
}
V_78:
F_58 ( V_2 ) ;
return V_75 ;
}
void F_61 ( void * V_31 , struct V_12 * V_13 )
{
F_13 ( & V_13 -> V_80 ) ;
* (struct V_30 * ) V_31 = V_13 -> V_28 ;
F_15 ( & V_13 -> V_80 ) ;
}
void F_62 ( struct V_30 * V_81 ,
struct V_82 * V_83 ,
const char * V_84 , ... )
{
T_4 args ;
va_start ( args , V_84 ) ;
F_63 ( V_83 , V_84 , args ,
L_12 V_85 L_13 ,
V_81 , F_64 ( F_65 ( V_81 ) ) , F_66 ( V_81 ) ,
F_67 ( V_81 ) , F_68 ( V_81 ) , F_69 ( V_81 ) ,
F_47 ( V_81 ) , F_70 ( V_81 ) , F_71 ( V_81 ) ,
F_72 ( V_81 ) ) ;
va_end ( args ) ;
}
