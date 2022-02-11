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
bool * V_35 )
{
const struct V_36 * V_37 ;
struct V_30 * V_13 ;
struct V_38 * V_39 ;
struct V_12 * V_40 ;
unsigned int V_41 = 0 ;
* V_35 = true ;
F_14 () ;
F_15 (conn, n, head, node) {
V_37 = F_16 ( V_34 , V_42 ,
& V_13 -> V_29 ) ;
if ( V_37 == NULL ) {
F_17 ( & V_13 -> V_33 ) ;
F_18 ( V_31 , V_13 ) ;
continue;
}
V_40 = F_19 ( V_37 ) ;
if ( F_20 ( & V_13 -> V_29 , V_29 ) ) {
* V_35 = false ;
} else if ( F_6 ( V_40 ) ) {
F_21 ( V_40 ) ;
F_17 ( & V_13 -> V_33 ) ;
F_18 ( V_31 , V_13 ) ;
continue;
}
F_21 ( V_40 ) ;
V_41 ++ ;
}
F_22 () ;
return V_41 ;
}
static void F_23 ( struct V_43 * V_44 ,
struct V_45 * V_46 [] ,
unsigned int V_47 )
{
struct V_45 * V_48 ;
while ( V_47 ) {
V_48 = V_46 [ -- V_47 ] ;
F_24 ( & V_48 -> V_33 , V_44 ) ;
F_18 ( V_49 , V_48 ) ;
}
}
static unsigned int
F_25 ( struct V_34 * V_34 , struct V_43 * V_44 ,
const struct V_28 * V_29 ,
const union V_6 * V_1 , const union V_6 * V_7 ,
T_3 V_21 )
{
struct V_45 * V_46 [ V_50 ] ;
struct V_51 * * V_52 , * V_53 ;
struct V_45 * V_48 ;
struct V_30 * V_13 ;
unsigned int V_47 ;
bool V_54 = false ;
V_55:
V_47 = 0 ;
V_53 = NULL ;
V_52 = & ( V_44 -> V_51 ) ;
while ( * V_52 ) {
int V_56 ;
bool V_35 ;
V_48 = F_26 ( * V_52 , struct V_45 , V_33 ) ;
V_53 = * V_52 ;
V_56 = F_8 ( V_1 , V_7 , & V_48 -> V_1 , V_21 ) ;
if ( V_56 < 0 ) {
V_52 = & ( ( * V_52 ) -> V_57 ) ;
} else if ( V_56 > 0 ) {
V_52 = & ( ( * V_52 ) -> V_58 ) ;
} else {
unsigned int V_59 ;
V_59 = F_13 ( V_34 , & V_48 -> V_60 , V_29 , & V_35 ) ;
F_23 ( V_44 , V_46 , V_47 ) ;
if ( ! V_35 )
return V_59 ;
if ( ! F_10 ( & V_48 -> V_60 , V_29 , V_1 ) )
return 0 ;
return V_59 + 1 ;
}
if ( V_54 || V_47 >= F_4 ( V_46 ) )
continue;
F_13 ( V_34 , & V_48 -> V_60 , V_29 , & V_35 ) ;
if ( F_27 ( & V_48 -> V_60 ) )
V_46 [ V_47 ++ ] = V_48 ;
}
if ( V_47 ) {
V_54 = true ;
F_23 ( V_44 , V_46 , V_47 ) ;
goto V_55;
}
V_48 = F_11 ( V_49 , V_32 ) ;
if ( V_48 == NULL )
return 0 ;
V_13 = F_11 ( V_31 , V_32 ) ;
if ( V_13 == NULL ) {
F_18 ( V_49 , V_48 ) ;
return 0 ;
}
V_13 -> V_29 = * V_29 ;
V_13 -> V_1 = * V_1 ;
V_48 -> V_1 = * V_1 ;
F_28 ( & V_48 -> V_60 ) ;
F_12 ( & V_13 -> V_33 , & V_48 -> V_60 ) ;
F_29 ( & V_48 -> V_33 , V_53 , V_52 ) ;
F_30 ( & V_48 -> V_33 , V_44 ) ;
return 1 ;
}
static int F_31 ( struct V_34 * V_34 ,
struct V_61 * V_62 ,
const struct V_28 * V_29 ,
const union V_6 * V_1 ,
const union V_6 * V_7 ,
T_2 V_21 )
{
struct V_43 * V_44 ;
int V_59 ;
V_11 V_63 ;
if ( V_21 == V_64 ) {
V_63 = F_3 ( V_1 , V_7 ) ;
V_44 = & V_62 -> V_65 [ V_63 ] ;
} else {
V_63 = F_1 ( V_1 -> V_23 & V_7 -> V_23 ) ;
V_44 = & V_62 -> V_66 [ V_63 ] ;
}
F_32 ( & V_67 [ V_63 % V_68 ] ) ;
V_59 = F_25 ( V_34 , V_44 , V_29 , V_1 , V_7 , V_21 ) ;
F_33 ( & V_67 [ V_63 % V_68 ] ) ;
return V_59 ;
}
static bool
F_34 ( const struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_34 * V_34 = F_35 ( V_72 -> V_73 ? V_72 -> V_73 : V_72 -> V_74 ) ;
const struct V_75 * V_76 = V_72 -> V_77 ;
union V_6 V_1 ;
struct V_28 V_29 ;
const struct V_28 * V_78 = & V_29 ;
enum V_79 V_80 ;
const struct V_12 * V_81 ;
unsigned int V_82 ;
V_81 = F_36 ( V_70 , & V_80 ) ;
if ( V_81 != NULL )
V_78 = & V_81 -> V_83 [ V_84 ] . V_29 ;
else if ( ! F_37 ( V_70 , F_38 ( V_70 ) ,
V_72 -> V_21 , & V_29 ) )
goto V_85;
if ( V_72 -> V_21 == V_64 ) {
const struct V_86 * V_87 = F_39 ( V_70 ) ;
memcpy ( & V_1 . V_10 , ( V_76 -> V_88 & V_89 ) ?
& V_87 -> V_90 : & V_87 -> V_91 , sizeof( V_1 . V_10 ) ) ;
} else {
const struct V_92 * V_87 = F_40 ( V_70 ) ;
V_1 . V_23 = ( V_76 -> V_88 & V_89 ) ?
V_87 -> V_90 : V_87 -> V_91 ;
}
V_82 = F_31 ( V_34 , V_76 -> V_62 , V_78 , & V_1 ,
& V_76 -> V_7 , V_72 -> V_21 ) ;
if ( V_82 == 0 )
goto V_85;
return ( V_82 > V_76 -> V_93 ) ^
! ! ( V_76 -> V_88 & V_94 ) ;
V_85:
V_72 -> V_85 = true ;
return false ;
}
static int F_41 ( const struct V_95 * V_72 )
{
struct V_75 * V_76 = V_72 -> V_77 ;
unsigned int V_9 ;
int V_96 ;
if ( F_42 ( ! V_4 ) ) {
T_4 rand ;
do {
F_43 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_44 ( & V_4 , 0 , rand ) ;
}
V_96 = F_45 ( V_72 -> V_21 ) ;
if ( V_96 < 0 ) {
F_46 ( L_1
L_2 , V_72 -> V_21 ) ;
return V_96 ;
}
V_76 -> V_62 = F_47 ( sizeof( struct V_61 ) , V_97 ) ;
if ( V_76 -> V_62 == NULL ) {
F_48 ( V_72 -> V_21 ) ;
return - V_98 ;
}
for ( V_9 = 0 ; V_9 < F_4 ( V_76 -> V_62 -> V_66 ) ; ++ V_9 )
V_76 -> V_62 -> V_66 [ V_9 ] = V_99 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_76 -> V_62 -> V_65 ) ; ++ V_9 )
V_76 -> V_62 -> V_65 [ V_9 ] = V_99 ;
return 0 ;
}
static void F_49 ( struct V_43 * V_100 )
{
struct V_30 * V_13 ;
struct V_45 * V_48 ;
struct V_38 * V_39 ;
struct V_51 * V_33 ;
while ( ( V_33 = F_50 ( V_100 ) ) != NULL ) {
V_48 = F_26 ( V_33 , struct V_45 , V_33 ) ;
F_24 ( V_33 , V_100 ) ;
F_15 (conn, n, &rbconn->hhead, node)
F_18 ( V_31 , V_13 ) ;
F_18 ( V_49 , V_48 ) ;
}
}
static void F_51 ( const struct V_101 * V_72 )
{
const struct V_75 * V_76 = V_72 -> V_77 ;
unsigned int V_9 ;
F_48 ( V_72 -> V_21 ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_76 -> V_62 -> V_66 ) ; ++ V_9 )
F_49 ( & V_76 -> V_62 -> V_66 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_76 -> V_62 -> V_65 ) ; ++ V_9 )
F_49 ( & V_76 -> V_62 -> V_65 [ V_9 ] ) ;
F_52 ( V_76 -> V_62 ) ;
}
static int T_5 F_53 ( void )
{
int V_96 , V_9 ;
F_54 ( V_68 > V_5 ) ;
F_54 ( ( V_5 % V_68 ) != 0 ) ;
for ( V_9 = 0 ; V_9 < V_68 ; ++ V_9 )
F_55 ( & V_67 [ V_9 ] ) ;
V_31 = F_56 ( L_3 ,
sizeof( struct V_30 ) ,
0 , 0 , NULL ) ;
if ( ! V_31 )
return - V_98 ;
V_49 = F_56 ( L_4 ,
sizeof( struct V_45 ) ,
0 , 0 , NULL ) ;
if ( ! V_49 ) {
F_57 ( V_31 ) ;
return - V_98 ;
}
V_96 = F_58 ( & V_102 ) ;
if ( V_96 != 0 ) {
F_57 ( V_31 ) ;
F_57 ( V_49 ) ;
}
return V_96 ;
}
static void T_6 F_59 ( void )
{
F_60 ( & V_102 ) ;
F_57 ( V_31 ) ;
F_57 ( V_49 ) ;
}
