static inline unsigned int F_1 ( T_1 V_1 )
{
return F_2 ( ( V_2 V_3 ) V_1 ,
V_4 ) % V_5 ;
}
static inline unsigned int
F_3 ( const union V_6 * V_1 ,
const union V_6 * V_7 )
{
union V_6 V_8 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_1 -> V_10 ) ; ++ V_9 )
V_8 . V_10 [ V_9 ] = V_1 -> V_10 [ V_9 ] & V_7 -> V_10 [ V_9 ] ;
return F_5 ( ( V_11 * ) V_8 . V_10 , F_4 ( V_8 . V_10 ) ,
V_4 ) % V_5 ;
}
static inline bool F_6 ( const struct V_12 * V_13 )
{
if ( F_7 ( V_13 ) == V_14 )
return V_13 -> V_15 . V_16 . V_17 == V_18 ||
V_13 -> V_15 . V_16 . V_17 == V_19 ;
else
return 0 ;
}
static int
F_8 ( const union V_6 * V_1 ,
const union V_6 * V_7 ,
const union V_6 * V_20 , T_2 V_21 )
{
if ( V_21 == V_22 ) {
return F_9 ( V_1 -> V_23 & V_7 -> V_23 ) -
F_9 ( V_20 -> V_23 & V_7 -> V_23 ) ;
} else {
union V_6 V_24 , V_25 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_1 -> V_10 ) ; ++ V_9 ) {
V_24 . V_10 [ V_9 ] = V_1 -> V_10 [ V_9 ] & V_7 -> V_10 [ V_9 ] ;
V_25 . V_10 [ V_9 ] = V_20 -> V_10 [ V_9 ] & V_7 -> V_10 [ V_9 ] ;
}
return memcmp ( & V_24 . V_10 , & V_25 . V_10 , sizeof( V_24 . V_10 ) ) ;
}
}
static bool F_10 ( struct V_26 * V_27 ,
const struct V_28 * V_29 ,
const union V_6 * V_1 )
{
struct V_30 * V_13 ;
V_13 = F_11 ( V_31 , V_32 ) ;
if ( V_13 == NULL )
return false ;
V_13 -> V_29 = * V_29 ;
V_13 -> V_1 = * V_1 ;
F_12 ( & V_13 -> V_33 , V_27 ) ;
return true ;
}
static unsigned int F_13 ( struct V_34 * V_34 ,
struct V_26 * V_27 ,
const struct V_28 * V_29 ,
const struct V_35 * V_36 ,
bool * V_37 )
{
const struct V_38 * V_39 ;
struct V_30 * V_13 ;
struct V_40 * V_41 ;
struct V_12 * V_42 ;
unsigned int V_43 = 0 ;
* V_37 = true ;
F_14 () ;
F_15 (conn, n, head, node) {
V_39 = F_16 ( V_34 , V_36 , & V_13 -> V_29 ) ;
if ( V_39 == NULL ) {
F_17 ( & V_13 -> V_33 ) ;
F_18 ( V_31 , V_13 ) ;
continue;
}
V_42 = F_19 ( V_39 ) ;
if ( F_20 ( & V_13 -> V_29 , V_29 ) ) {
* V_37 = false ;
} else if ( F_6 ( V_42 ) ) {
F_21 ( V_42 ) ;
F_17 ( & V_13 -> V_33 ) ;
F_18 ( V_31 , V_13 ) ;
continue;
}
F_21 ( V_42 ) ;
V_43 ++ ;
}
F_22 () ;
return V_43 ;
}
static void F_23 ( struct V_44 * V_45 ,
struct V_46 * V_47 [] ,
unsigned int V_48 )
{
struct V_46 * V_49 ;
while ( V_48 ) {
V_49 = V_47 [ -- V_48 ] ;
F_24 ( & V_49 -> V_33 , V_45 ) ;
F_18 ( V_50 , V_49 ) ;
}
}
static unsigned int
F_25 ( struct V_34 * V_34 , struct V_44 * V_45 ,
const struct V_28 * V_29 ,
const union V_6 * V_1 , const union V_6 * V_7 ,
T_3 V_21 , const struct V_35 * V_36 )
{
struct V_46 * V_47 [ V_51 ] ;
struct V_52 * * V_53 , * V_54 ;
struct V_46 * V_49 ;
struct V_30 * V_13 ;
unsigned int V_48 ;
bool V_55 = false ;
V_56:
V_48 = 0 ;
V_54 = NULL ;
V_53 = & ( V_45 -> V_52 ) ;
while ( * V_53 ) {
int V_57 ;
bool V_37 ;
V_49 = F_26 ( * V_53 , struct V_46 , V_33 ) ;
V_54 = * V_53 ;
V_57 = F_8 ( V_1 , V_7 , & V_49 -> V_1 , V_21 ) ;
if ( V_57 < 0 ) {
V_53 = & ( ( * V_53 ) -> V_58 ) ;
} else if ( V_57 > 0 ) {
V_53 = & ( ( * V_53 ) -> V_59 ) ;
} else {
unsigned int V_60 ;
V_60 = F_13 ( V_34 , & V_49 -> V_61 , V_29 , V_36 , & V_37 ) ;
F_23 ( V_45 , V_47 , V_48 ) ;
if ( ! V_37 )
return V_60 ;
if ( ! F_10 ( & V_49 -> V_61 , V_29 , V_1 ) )
return 0 ;
return V_60 + 1 ;
}
if ( V_55 || V_48 >= F_4 ( V_47 ) )
continue;
F_13 ( V_34 , & V_49 -> V_61 , V_29 , V_36 , & V_37 ) ;
if ( F_27 ( & V_49 -> V_61 ) )
V_47 [ V_48 ++ ] = V_49 ;
}
if ( V_48 ) {
V_55 = true ;
F_23 ( V_45 , V_47 , V_48 ) ;
goto V_56;
}
V_49 = F_11 ( V_50 , V_32 ) ;
if ( V_49 == NULL )
return 0 ;
V_13 = F_11 ( V_31 , V_32 ) ;
if ( V_13 == NULL ) {
F_18 ( V_50 , V_49 ) ;
return 0 ;
}
V_13 -> V_29 = * V_29 ;
V_13 -> V_1 = * V_1 ;
V_49 -> V_1 = * V_1 ;
F_28 ( & V_49 -> V_61 ) ;
F_12 ( & V_13 -> V_33 , & V_49 -> V_61 ) ;
F_29 ( & V_49 -> V_33 , V_54 , V_53 ) ;
F_30 ( & V_49 -> V_33 , V_45 ) ;
return 1 ;
}
static int F_31 ( struct V_34 * V_34 ,
struct V_62 * V_63 ,
const struct V_28 * V_29 ,
const union V_6 * V_1 ,
const union V_6 * V_7 ,
T_2 V_21 ,
const struct V_35 * V_36 )
{
struct V_44 * V_45 ;
int V_60 ;
V_11 V_64 ;
if ( V_21 == V_65 ) {
V_64 = F_3 ( V_1 , V_7 ) ;
V_45 = & V_63 -> V_66 [ V_64 ] ;
} else {
V_64 = F_1 ( V_1 -> V_23 & V_7 -> V_23 ) ;
V_45 = & V_63 -> V_67 [ V_64 ] ;
}
F_32 ( & V_68 [ V_64 % V_69 ] ) ;
V_60 = F_25 ( V_34 , V_45 , V_29 , V_1 , V_7 , V_21 , V_36 ) ;
F_33 ( & V_68 [ V_64 % V_69 ] ) ;
return V_60 ;
}
static bool
F_34 ( const struct V_70 * V_71 , struct V_72 * V_73 )
{
struct V_34 * V_34 = V_73 -> V_34 ;
const struct V_74 * V_75 = V_73 -> V_76 ;
union V_6 V_1 ;
struct V_28 V_29 ;
const struct V_28 * V_77 = & V_29 ;
const struct V_35 * V_36 = & V_78 ;
enum V_79 V_80 ;
const struct V_12 * V_81 ;
unsigned int V_82 ;
V_81 = F_35 ( V_71 , & V_80 ) ;
if ( V_81 != NULL ) {
V_77 = & V_81 -> V_83 [ V_84 ] . V_29 ;
V_36 = F_36 ( V_81 ) ;
} else if ( ! F_37 ( V_71 , F_38 ( V_71 ) ,
V_73 -> V_21 , V_34 , & V_29 ) ) {
goto V_85;
}
if ( V_73 -> V_21 == V_65 ) {
const struct V_86 * V_87 = F_39 ( V_71 ) ;
memcpy ( & V_1 . V_10 , ( V_75 -> V_88 & V_89 ) ?
& V_87 -> V_90 : & V_87 -> V_91 , sizeof( V_1 . V_10 ) ) ;
} else {
const struct V_92 * V_87 = F_40 ( V_71 ) ;
V_1 . V_23 = ( V_75 -> V_88 & V_89 ) ?
V_87 -> V_90 : V_87 -> V_91 ;
}
V_82 = F_31 ( V_34 , V_75 -> V_63 , V_77 , & V_1 ,
& V_75 -> V_7 , V_73 -> V_21 , V_36 ) ;
if ( V_82 == 0 )
goto V_85;
return ( V_82 > V_75 -> V_93 ) ^
! ! ( V_75 -> V_88 & V_94 ) ;
V_85:
V_73 -> V_85 = true ;
return false ;
}
static int F_41 ( const struct V_95 * V_73 )
{
struct V_74 * V_75 = V_73 -> V_76 ;
unsigned int V_9 ;
int V_96 ;
F_42 ( & V_4 , sizeof( V_4 ) ) ;
V_96 = F_43 ( V_73 -> V_21 ) ;
if ( V_96 < 0 ) {
F_44 ( L_1
L_2 , V_73 -> V_21 ) ;
return V_96 ;
}
V_75 -> V_63 = F_45 ( sizeof( struct V_62 ) , V_97 ) ;
if ( V_75 -> V_63 == NULL ) {
F_46 ( V_73 -> V_21 ) ;
return - V_98 ;
}
for ( V_9 = 0 ; V_9 < F_4 ( V_75 -> V_63 -> V_67 ) ; ++ V_9 )
V_75 -> V_63 -> V_67 [ V_9 ] = V_99 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_75 -> V_63 -> V_66 ) ; ++ V_9 )
V_75 -> V_63 -> V_66 [ V_9 ] = V_99 ;
return 0 ;
}
static void F_47 ( struct V_44 * V_100 )
{
struct V_30 * V_13 ;
struct V_46 * V_49 ;
struct V_40 * V_41 ;
struct V_52 * V_33 ;
while ( ( V_33 = F_48 ( V_100 ) ) != NULL ) {
V_49 = F_26 ( V_33 , struct V_46 , V_33 ) ;
F_24 ( V_33 , V_100 ) ;
F_15 (conn, n, &rbconn->hhead, node)
F_18 ( V_31 , V_13 ) ;
F_18 ( V_50 , V_49 ) ;
}
}
static void F_49 ( const struct V_101 * V_73 )
{
const struct V_74 * V_75 = V_73 -> V_76 ;
unsigned int V_9 ;
F_46 ( V_73 -> V_21 ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_75 -> V_63 -> V_67 ) ; ++ V_9 )
F_47 ( & V_75 -> V_63 -> V_67 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_75 -> V_63 -> V_66 ) ; ++ V_9 )
F_47 ( & V_75 -> V_63 -> V_66 [ V_9 ] ) ;
F_50 ( V_75 -> V_63 ) ;
}
static int T_4 F_51 ( void )
{
int V_96 , V_9 ;
F_52 ( V_69 > V_5 ) ;
F_52 ( ( V_5 % V_69 ) != 0 ) ;
for ( V_9 = 0 ; V_9 < V_69 ; ++ V_9 )
F_53 ( & V_68 [ V_9 ] ) ;
V_31 = F_54 ( L_3 ,
sizeof( struct V_30 ) ,
0 , 0 , NULL ) ;
if ( ! V_31 )
return - V_98 ;
V_50 = F_54 ( L_4 ,
sizeof( struct V_46 ) ,
0 , 0 , NULL ) ;
if ( ! V_50 ) {
F_55 ( V_31 ) ;
return - V_98 ;
}
V_96 = F_56 ( & V_102 ) ;
if ( V_96 != 0 ) {
F_55 ( V_31 ) ;
F_55 ( V_50 ) ;
}
return V_96 ;
}
static void T_5 F_57 ( void )
{
F_58 ( & V_102 ) ;
F_55 ( V_31 ) ;
F_55 ( V_50 ) ;
}
