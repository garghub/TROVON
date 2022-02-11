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
struct V_33 * V_34 ;
struct V_11 * V_35 ;
struct V_36 * V_37 ;
bool V_38 = true ;
int V_39 = 0 ;
if ( V_20 == V_40 )
V_37 = & V_27 -> V_41 [ F_3 ( V_1 , V_6 ) ] ;
else
V_37 = & V_27 -> V_41 [ F_1 ( V_1 -> V_22 & V_6 -> V_22 ) ] ;
F_10 () ;
F_11 (conn, n, hash, node) {
V_31 = F_12 ( V_25 , V_42 ,
& V_12 -> V_29 ) ;
V_35 = NULL ;
if ( V_31 != NULL )
V_35 = F_13 ( V_31 ) ;
if ( V_35 != NULL &&
F_14 ( & V_12 -> V_29 , V_29 ) &&
! F_6 ( V_35 ) )
V_38 = false ;
if ( V_31 == NULL ) {
F_15 ( & V_12 -> V_43 ) ;
F_16 ( V_12 ) ;
continue;
}
if ( F_6 ( V_35 ) ) {
F_17 ( V_35 ) ;
F_15 ( & V_12 -> V_43 ) ;
F_16 ( V_12 ) ;
continue;
}
if ( F_8 ( V_1 , V_6 , & V_12 -> V_1 , V_20 ) )
++ V_39 ;
F_17 ( V_35 ) ;
}
F_18 () ;
if ( V_38 ) {
V_12 = F_19 ( sizeof( * V_12 ) , V_44 ) ;
if ( V_12 == NULL )
return - V_45 ;
V_12 -> V_29 = * V_29 ;
V_12 -> V_1 = * V_1 ;
F_20 ( & V_12 -> V_43 , V_37 ) ;
++ V_39 ;
}
return V_39 ;
}
static bool
F_21 ( const struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_25 * V_25 = F_22 ( V_49 -> V_50 ? V_49 -> V_50 : V_49 -> V_51 ) ;
const struct V_52 * V_53 = V_49 -> V_54 ;
union V_5 V_1 ;
struct V_28 V_29 ;
const struct V_28 * V_55 = & V_29 ;
enum V_56 V_57 ;
const struct V_11 * V_58 ;
int V_59 ;
V_58 = F_23 ( V_47 , & V_57 ) ;
if ( V_58 != NULL )
V_55 = & V_58 -> V_60 [ V_61 ] . V_29 ;
else if ( ! F_24 ( V_47 , F_25 ( V_47 ) ,
V_49 -> V_20 , & V_29 ) )
goto V_62;
if ( V_49 -> V_20 == V_40 ) {
const struct V_63 * V_64 = F_26 ( V_47 ) ;
memcpy ( & V_1 . V_9 , ( V_53 -> V_65 & V_66 ) ?
& V_64 -> V_67 : & V_64 -> V_68 , sizeof( V_1 . V_9 ) ) ;
} else {
const struct V_69 * V_64 = F_27 ( V_47 ) ;
V_1 . V_22 = ( V_53 -> V_65 & V_66 ) ?
V_64 -> V_67 : V_64 -> V_68 ;
}
F_28 ( & V_53 -> V_27 -> V_70 ) ;
V_59 = F_9 ( V_25 , V_53 -> V_27 , V_55 , & V_1 ,
& V_53 -> V_6 , V_49 -> V_20 ) ;
F_29 ( & V_53 -> V_27 -> V_70 ) ;
if ( V_59 < 0 )
goto V_62;
return ( V_59 > V_53 -> V_71 ) ^
! ! ( V_53 -> V_65 & V_72 ) ;
V_62:
V_49 -> V_62 = true ;
return false ;
}
static int F_30 ( const struct V_73 * V_49 )
{
struct V_52 * V_53 = V_49 -> V_54 ;
unsigned int V_8 ;
int V_74 ;
if ( F_31 ( ! V_4 ) ) {
T_3 rand ;
do {
F_32 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_33 ( & V_4 , 0 , rand ) ;
}
V_74 = F_34 ( V_49 -> V_20 ) ;
if ( V_74 < 0 ) {
F_35 ( L_1
L_2 , V_49 -> V_20 ) ;
return V_74 ;
}
V_53 -> V_27 = F_19 ( sizeof( struct V_26 ) , V_75 ) ;
if ( V_53 -> V_27 == NULL ) {
F_36 ( V_49 -> V_20 ) ;
return - V_45 ;
}
F_37 ( & V_53 -> V_27 -> V_70 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_53 -> V_27 -> V_41 ) ; ++ V_8 )
F_38 ( & V_53 -> V_27 -> V_41 [ V_8 ] ) ;
return 0 ;
}
static void F_39 ( const struct V_76 * V_49 )
{
const struct V_52 * V_53 = V_49 -> V_54 ;
struct V_32 * V_12 ;
struct V_33 * V_34 ;
struct V_36 * V_37 = V_53 -> V_27 -> V_41 ;
unsigned int V_8 ;
F_36 ( V_49 -> V_20 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_53 -> V_27 -> V_41 ) ; ++ V_8 ) {
F_11 (conn, n, &hash[i], node) {
F_15 ( & V_12 -> V_43 ) ;
F_16 ( V_12 ) ;
}
}
F_16 ( V_53 -> V_27 ) ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_77 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_77 ) ;
}
