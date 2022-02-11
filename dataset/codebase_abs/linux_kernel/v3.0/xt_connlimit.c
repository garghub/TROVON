static inline unsigned int F_1 ( T_1 V_1 )
{
return F_2 ( ( V_2 V_3 ) V_1 , V_4 ) & 0xFF ;
}
static inline unsigned int
F_3 ( const union V_5 * V_1 ,
const union V_5 * V_6 )
{
union V_5 V_7 ;
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_4 ( V_1 -> V_9 ) ; ++ V_8 )
V_7 . V_9 [ V_8 ] = V_1 -> V_9 [ V_8 ] & V_6 -> V_9 [ V_8 ] ;
return F_5 ( ( V_10 * ) V_7 . V_9 , F_4 ( V_7 . V_9 ) , V_4 ) & 0xFF ;
}
static inline bool F_6 ( const struct V_11 * V_12 )
{
if ( F_7 ( V_12 ) == V_13 )
return V_12 -> V_14 . V_15 . V_16 == V_17 ||
V_12 -> V_14 . V_15 . V_16 == V_18 ;
else
return 0 ;
}
static inline unsigned int
F_8 ( const union V_5 * V_1 ,
const union V_5 * V_6 ,
const union V_5 * V_19 , T_2 V_20 )
{
if ( V_20 == V_21 ) {
return ( V_1 -> V_22 & V_6 -> V_22 ) == ( V_19 -> V_22 & V_6 -> V_22 ) ;
} else {
union V_5 V_23 , V_24 ;
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_4 ( V_1 -> V_9 ) ; ++ V_8 ) {
V_23 . V_9 [ V_8 ] = V_1 -> V_9 [ V_8 ] & V_6 -> V_9 [ V_8 ] ;
V_24 . V_9 [ V_8 ] = V_19 -> V_9 [ V_8 ] & V_6 -> V_9 [ V_8 ] ;
}
return memcmp ( & V_23 . V_9 , & V_24 . V_9 , sizeof( V_23 . V_9 ) ) == 0 ;
}
}
static int F_9 ( struct V_25 * V_25 ,
struct V_26 * V_27 ,
const struct V_28 * V_29 ,
const union V_5 * V_1 ,
const union V_5 * V_6 ,
T_2 V_20 )
{
const struct V_30 * V_31 ;
struct V_32 * V_12 ;
struct V_33 * V_34 , * V_35 ;
struct V_11 * V_36 ;
struct V_37 * V_38 ;
bool V_39 = true ;
int V_40 = 0 ;
if ( V_20 == V_41 )
V_38 = & V_27 -> V_42 [ F_3 ( V_1 , V_6 ) ] ;
else
V_38 = & V_27 -> V_42 [ F_1 ( V_1 -> V_22 & V_6 -> V_22 ) ] ;
F_10 () ;
F_11 (conn, pos, n, hash, node) {
V_31 = F_12 ( V_25 , V_43 ,
& V_12 -> V_29 ) ;
V_36 = NULL ;
if ( V_31 != NULL )
V_36 = F_13 ( V_31 ) ;
if ( V_36 != NULL &&
F_14 ( & V_12 -> V_29 , V_29 ) &&
! F_6 ( V_36 ) )
V_39 = false ;
if ( V_31 == NULL ) {
F_15 ( & V_12 -> V_44 ) ;
F_16 ( V_12 ) ;
continue;
}
if ( F_6 ( V_36 ) ) {
F_17 ( V_36 ) ;
F_15 ( & V_12 -> V_44 ) ;
F_16 ( V_12 ) ;
continue;
}
if ( F_8 ( V_1 , V_6 , & V_12 -> V_1 , V_20 ) )
++ V_40 ;
F_17 ( V_36 ) ;
}
F_18 () ;
if ( V_39 ) {
V_12 = F_19 ( sizeof( * V_12 ) , V_45 ) ;
if ( V_12 == NULL )
return - V_46 ;
V_12 -> V_29 = * V_29 ;
V_12 -> V_1 = * V_1 ;
F_20 ( & V_12 -> V_44 , V_38 ) ;
++ V_40 ;
}
return V_40 ;
}
static bool
F_21 ( const struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_25 * V_25 = F_22 ( V_50 -> V_51 ? V_50 -> V_51 : V_50 -> V_52 ) ;
const struct V_53 * V_54 = V_50 -> V_55 ;
union V_5 V_1 ;
struct V_28 V_29 ;
const struct V_28 * V_56 = & V_29 ;
enum V_57 V_58 ;
const struct V_11 * V_59 ;
int V_60 ;
V_59 = F_23 ( V_48 , & V_58 ) ;
if ( V_59 != NULL )
V_56 = & V_59 -> V_61 [ V_62 ] . V_29 ;
else if ( ! F_24 ( V_48 , F_25 ( V_48 ) ,
V_50 -> V_20 , & V_29 ) )
goto V_63;
if ( V_50 -> V_20 == V_41 ) {
const struct V_64 * V_65 = F_26 ( V_48 ) ;
memcpy ( & V_1 . V_9 , ( V_54 -> V_66 & V_67 ) ?
& V_65 -> V_68 : & V_65 -> V_69 , sizeof( V_1 . V_9 ) ) ;
} else {
const struct V_70 * V_65 = F_27 ( V_48 ) ;
V_1 . V_22 = ( V_54 -> V_66 & V_67 ) ?
V_65 -> V_68 : V_65 -> V_69 ;
}
F_28 ( & V_54 -> V_27 -> V_71 ) ;
V_60 = F_9 ( V_25 , V_54 -> V_27 , V_56 , & V_1 ,
& V_54 -> V_6 , V_50 -> V_20 ) ;
F_29 ( & V_54 -> V_27 -> V_71 ) ;
if ( V_60 < 0 )
goto V_63;
return ( V_60 > V_54 -> V_72 ) ^
! ! ( V_54 -> V_66 & V_73 ) ;
V_63:
V_50 -> V_63 = true ;
return false ;
}
static int F_30 ( const struct V_74 * V_50 )
{
struct V_53 * V_54 = V_50 -> V_55 ;
unsigned int V_8 ;
int V_75 ;
if ( F_31 ( ! V_4 ) ) {
T_3 rand ;
do {
F_32 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_33 ( & V_4 , 0 , rand ) ;
}
V_75 = F_34 ( V_50 -> V_20 ) ;
if ( V_75 < 0 ) {
F_35 ( L_1
L_2 , V_50 -> V_20 ) ;
return V_75 ;
}
V_54 -> V_27 = F_19 ( sizeof( struct V_26 ) , V_76 ) ;
if ( V_54 -> V_27 == NULL ) {
F_36 ( V_50 -> V_20 ) ;
return - V_46 ;
}
F_37 ( & V_54 -> V_27 -> V_71 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_54 -> V_27 -> V_42 ) ; ++ V_8 )
F_38 ( & V_54 -> V_27 -> V_42 [ V_8 ] ) ;
return 0 ;
}
static void F_39 ( const struct V_77 * V_50 )
{
const struct V_53 * V_54 = V_50 -> V_55 ;
struct V_32 * V_12 ;
struct V_33 * V_34 , * V_35 ;
struct V_37 * V_38 = V_54 -> V_27 -> V_42 ;
unsigned int V_8 ;
F_36 ( V_50 -> V_20 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_54 -> V_27 -> V_42 ) ; ++ V_8 ) {
F_11 (conn, pos, n, &hash[i], node) {
F_15 ( & V_12 -> V_44 ) ;
F_16 ( V_12 ) ;
}
}
F_16 ( V_54 -> V_27 ) ;
}
static int T_4 F_40 ( void )
{
return F_41 ( V_78 ,
F_4 ( V_78 ) ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( V_78 , F_4 ( V_78 ) ) ;
}
