struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 , V_4 ;
F_2 ( V_2 , V_5 ) ;
if ( ! V_2 )
return NULL ;
V_3 = V_5 / sizeof( struct V_1 ) ;
F_3 ( V_3 > V_6 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
F_4 ( V_2 + V_4 ) ;
return V_2 ;
}
static inline int F_5 ( struct V_7 * V_8 )
{
return V_8 -> V_9 == V_10 ;
}
static inline void F_6 ( struct V_7 * V_8 )
{
F_3 ( F_5 ( V_8 ) ) ;
F_7 ( & V_8 -> V_11 . V_12 . V_13 ) ;
F_8 ( & V_8 -> V_14 ) ;
V_15 [ V_8 -> V_9 ] -- ;
F_9 ( V_8 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_16 * V_17 ;
struct V_7 * V_18 ;
F_11 ( & V_19 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
F_12 (oc, next, hash + i,
u.tgt.c_hash)
F_6 ( V_18 ) ;
}
F_13 ( & V_19 ) ;
F_14 ( V_2 , V_5 ) ;
}
static inline int F_15 ( struct V_20 * V_21 )
{
return ( F_16 ( V_21 ) ^ F_17 ( V_21 ) ) *
( unsigned long ) ( F_18 ( V_21 ) + 1 ) % V_6 ;
}
static inline int F_19 ( struct V_7 * V_18 )
{
return F_20 ( F_21 ( V_18 -> V_22 ,
F_22 ( V_18 -> V_23 . V_24 ) * 2 / 3 ) ,
F_23 () ) ;
}
static struct V_7 * F_24 ( struct V_25 * V_26 ,
struct V_1 * V_27 , int V_28 )
{
struct V_7 * V_8 ;
int V_29 = V_28 ? F_25 ( struct V_25 , V_30 ) : sizeof( * V_26 ) ;
F_26 (ocapa, head, u.tgt.c_hash) {
if ( memcmp ( & V_8 -> V_23 , V_26 , V_29 ) )
continue;
if ( V_28 && F_19 ( V_8 ) )
continue;
F_3 ( F_5 ( V_8 ) ) ;
F_27 ( V_31 , & V_8 -> V_23 , L_1 ) ;
return V_8 ;
}
return NULL ;
}
static inline void F_28 ( struct V_32 * V_27 )
{
struct V_7 * V_8 ;
struct V_32 * V_33 = V_27 -> V_17 ;
int V_34 = 0 ;
while ( V_34 ++ < V_35 ) {
V_8 = F_29 ( V_33 , struct V_7 , V_14 ) ;
V_33 = V_33 -> V_17 ;
if ( F_30 ( & V_8 -> V_36 ) )
continue;
F_27 ( V_31 , & V_8 -> V_23 , L_2 ) ;
F_6 ( V_8 ) ;
}
}
struct V_7 * F_31 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_1 * V_27 = V_2 + F_15 ( & V_26 -> V_37 ) ;
struct V_7 * V_8 , * V_38 = NULL ;
struct V_32 * V_39 = & V_40 [ V_10 ] ;
V_8 = F_32 ( V_10 ) ;
if ( F_33 ( V_8 ) )
return NULL ;
F_11 ( & V_19 ) ;
V_38 = F_24 ( V_26 , V_27 , 0 ) ;
if ( ! V_38 ) {
V_8 -> V_23 = * V_26 ;
F_34 ( V_8 ) ;
F_35 ( & V_8 -> V_11 . V_12 . V_13 , V_27 ) ;
F_36 ( & V_8 -> V_14 , V_39 ) ;
F_37 ( V_8 ) ;
V_15 [ V_10 ] ++ ;
if ( V_15 [ V_10 ] > V_41 )
F_28 ( V_39 ) ;
F_13 ( & V_19 ) ;
return V_8 ;
} else {
F_37 ( V_38 ) ;
F_13 ( & V_19 ) ;
F_9 ( V_8 ) ;
return V_38 ;
}
}
struct V_7 * F_38 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_28 )
{
struct V_7 * V_8 ;
F_11 ( & V_19 ) ;
V_8 = F_24 ( V_26 , V_2 + F_15 ( & V_26 -> V_37 ) , V_28 ) ;
if ( V_8 ) {
F_39 ( & V_8 -> V_14 ,
& V_40 [ V_10 ] ) ;
F_37 ( V_8 ) ;
}
F_13 ( & V_19 ) ;
return V_8 ;
}
int F_40 ( T_1 * V_42 , struct V_25 * V_26 , T_1 * V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_48 ;
struct V_49 V_50 ;
if ( F_41 ( V_26 ) != V_51 ) {
F_42 ( L_3 ) ;
return - V_52 ;
}
V_47 = & V_53 [ F_41 ( V_26 ) ] ;
V_45 = F_43 ( V_47 -> V_54 , 0 , 0 ) ;
if ( ! V_45 ) {
F_42 ( L_4
L_5 ) ;
return - V_55 ;
}
V_48 = V_47 -> V_56 ;
F_44 ( & V_50 , F_45 ( V_26 ) ,
F_25 ( struct V_25 , V_57 ) ,
( unsigned long ) ( V_26 ) % V_5 ) ;
F_46 ( V_45 , V_43 , & V_48 , & V_50 , V_50 . V_58 , V_42 ) ;
F_47 ( V_45 ) ;
return 0 ;
}
int F_48 ( T_2 * V_59 , T_2 * V_60 , T_1 * V_43 , int V_48 )
{
struct V_61 * V_45 ;
struct V_49 V_62 ;
struct V_49 V_63 ;
struct V_64 V_65 ;
unsigned int V_66 ;
int V_67 ;
char V_47 [ V_68 + 1 ] = L_6 ;
V_69 ;
V_45 = F_49 ( V_47 , 0 , 0 ) ;
if ( F_33 ( V_45 ) ) {
F_42 ( L_7 ) ;
RETURN ( F_50 ( V_45 ) ) ;
}
V_66 = F_51 ( V_45 ) ;
if ( V_48 < V_66 ) {
F_42 ( L_8 , V_66 * 8 ) ;
GOTO ( V_70 , V_67 = - V_71 ) ;
}
V_67 = F_52 ( V_45 , V_43 , V_66 ) ;
if ( V_67 ) {
F_42 ( L_9 ) ;
GOTO ( V_70 , V_67 ) ;
}
F_44 ( & V_62 , F_45 ( V_59 ) , 16 ,
( unsigned long ) ( V_59 ) % V_5 ) ;
F_44 ( & V_63 , F_45 ( V_60 ) , 16 ,
( unsigned long ) ( V_60 ) % V_5 ) ;
V_65 . V_45 = V_45 ;
V_65 . V_72 = NULL ;
V_65 . V_73 = 0 ;
V_67 = F_53 ( & V_65 , & V_62 , & V_63 , 16 ) ;
if ( V_67 ) {
F_42 ( L_10 ) ;
GOTO ( V_70 , V_67 ) ;
}
EXIT ;
V_70:
F_54 ( V_45 ) ;
return V_67 ;
}
int F_55 ( T_2 * V_59 , T_2 * V_60 , T_1 * V_43 , int V_48 )
{
struct V_61 * V_45 ;
struct V_49 V_62 ;
struct V_49 V_63 ;
struct V_64 V_65 ;
unsigned int V_66 ;
int V_67 ;
char V_47 [ V_68 + 1 ] = L_6 ;
V_69 ;
V_45 = F_49 ( V_47 , 0 , 0 ) ;
if ( F_33 ( V_45 ) ) {
F_42 ( L_7 ) ;
RETURN ( F_50 ( V_45 ) ) ;
}
V_66 = F_51 ( V_45 ) ;
if ( V_48 < V_66 ) {
F_42 ( L_8 , V_66 * 8 ) ;
GOTO ( V_70 , V_67 = - V_71 ) ;
}
V_67 = F_52 ( V_45 , V_43 , V_66 ) ;
if ( V_67 ) {
F_42 ( L_9 ) ;
GOTO ( V_70 , V_67 ) ;
}
F_44 ( & V_62 , F_45 ( V_59 ) , 16 ,
( unsigned long ) ( V_59 ) % V_5 ) ;
F_44 ( & V_63 , F_45 ( V_60 ) , 16 ,
( unsigned long ) ( V_60 ) % V_5 ) ;
V_65 . V_45 = V_45 ;
V_65 . V_72 = NULL ;
V_65 . V_73 = 0 ;
V_67 = F_56 ( & V_65 , & V_62 , & V_63 , 16 ) ;
if ( V_67 ) {
F_42 ( L_11 ) ;
GOTO ( V_70 , V_67 ) ;
}
EXIT ;
V_70:
F_54 ( V_45 ) ;
return V_67 ;
}
void F_57 ( void * V_26 , struct V_7 * V_8 )
{
F_11 ( & V_8 -> V_74 ) ;
* (struct V_25 * ) V_26 = V_8 -> V_23 ;
F_13 ( & V_8 -> V_74 ) ;
}
void F_58 ( struct V_25 * V_75 ,
struct V_76 * V_77 ,
const char * V_78 , ... )
{
T_3 args ;
va_start ( args , V_78 ) ;
F_59 ( V_77 , V_78 , args ,
L_12 V_79 L_13 V_80 L_14 V_81
L_15 V_81 L_16
L_17 , V_75 , F_60 ( F_61 ( V_75 ) ) , F_62 ( V_75 ) ,
F_63 ( V_75 ) , F_64 ( V_75 ) , F_65 ( V_75 ) ,
F_41 ( V_75 ) , F_66 ( V_75 ) , F_67 ( V_75 ) ,
F_68 ( V_75 ) ) ;
va_end ( args ) ;
}
