int F_1 ( void )
{
if ( ! V_1 ) {
F_2 ( L_1 ) ;
F_2 ( L_2 ) ;
return 1 ;
}
F_3 () ;
return F_4 () ;
}
static inline void F_5 ( void )
{
int V_2 = F_6 () ;
F_7 ( 0x1 , V_3 [ V_2 ] ) ;
while ( ( F_8 ( V_4 + F_9 ( V_2 ) ) >> 4 ) & 0x3 )
;
F_10 () ;
F_7 ( 0x1 , V_4 + F_9 ( V_2 ) ) ;
while ( F_8 ( V_3 [ V_2 ] ) )
;
}
static void T_1 F_11 ( void )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
T_2 V_13 = 0 ;
int V_14 ;
F_2 ( L_3 ) ;
V_8 = F_12 ( NULL , NULL , L_4 ) ;
F_13 ( ! V_8 ) ;
V_10 = F_14 ( sizeof( struct V_9 ) , V_15 ) ;
F_13 ( ! V_10 ) ;
V_10 -> V_16 = F_15 ( L_5 , V_15 ) ;
F_13 ( ! V_10 -> V_16 ) ;
V_10 -> V_17 = 8 ;
V_10 -> V_18 = F_15 ( L_6 , V_15 ) ;
F_13 ( ! V_10 -> V_18 ) ;
F_16 ( V_8 , V_10 ) ;
V_4 = F_17 ( V_8 , 0 ) ;
V_19 = F_17 ( V_8 , 1 ) ;
V_12 = F_18 ( V_8 , NULL ) ;
F_13 ( ! V_12 ) ;
F_19 ( V_12 ) ;
V_6 = F_20 () ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ ) {
F_7 ( 0 , V_4 + F_21 ( V_14 ) ) ;
F_7 ( 0 , V_4 + F_22 ( V_14 ) ) ;
if ( V_14 < 4 )
F_7 ( 0 , V_4 + F_23 ( V_14 ) ) ;
}
for ( V_14 = 0 ; V_14 < V_6 -> V_20 ; V_14 ++ ) {
const struct V_21 * V_22 = V_6 -> V_22 + V_14 ;
F_7 ( ( V_22 -> V_23 & 0xffff0000 ) |
( V_22 -> V_24 << 8 ) |
V_6 -> V_25 , V_4 + F_21 ( V_14 ) ) ;
F_7 ( ( V_22 -> V_26 - 1 ) & 0xffff0000 , V_4 + F_22 ( V_14 ) ) ;
V_13 |= ( 1 << V_14 ) ;
V_13 |= 3 << ( 16 + ( 2 * V_14 ) ) ;
}
F_7 ( V_13 , V_4 + F_24 ( 0 ) ) ;
F_7 ( V_13 , V_4 + F_24 ( 1 ) ) ;
F_7 ( 0 , V_4 + F_25 ( 0 ) ) ;
F_7 ( 0 , V_4 + F_25 ( 1 ) ) ;
for ( V_14 = 0 ; V_14 < V_27 ; V_14 ++ ) {
V_3 [ V_14 ] = F_14 ( V_28 , V_15 ) ;
F_13 ( ! V_3 [ V_14 ] ) ;
V_29 [ V_14 ] =
F_26 ( V_3 [ V_14 ] ) ;
F_13 ( ! V_29 [ V_14 ] ) ;
F_7 ( 0x444 , V_4 + F_27 ( V_14 ) ) ;
F_7 ( 128 , V_4 + F_28 ( V_14 ) ) ;
F_7 ( V_29 [ V_14 ] ,
V_4 + F_29 ( V_14 ) ) ;
}
F_7 ( 0x0 , V_4 + V_30 ) ;
F_7 ( 0x0 , V_4 + V_31 ) ;
V_32 = true ;
}
static inline void F_30 ( void )
{
if ( V_32 ) {
F_5 () ;
return;
}
F_7 ( 0x1 , V_33 + V_34 ) ;
while ( F_8 ( V_33 + V_34 ) & 0x1 ) ;
}
static T_3 F_31 ( struct V_35 * V_36 , struct V_37 * V_37 ,
unsigned long V_38 , T_4 V_26 ,
enum V_39 V_40 ,
struct V_41 * V_42 )
{
if ( V_40 != V_43 )
F_30 () ;
return F_32 ( V_36 , F_33 ( V_37 ) ) + V_38 ;
}
static void F_34 ( struct V_35 * V_36 , T_3 V_44 ,
T_4 V_26 , enum V_39 V_40 ,
struct V_41 * V_42 )
{
if ( V_40 != V_43 )
F_30 () ;
}
static void F_35 ( struct V_35 * V_36 , T_3 V_44 ,
T_4 V_26 , enum V_39 V_40 )
{
if ( V_40 != V_43 )
F_30 () ;
}
static int F_36 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
struct V_35 * V_36 = V_48 ;
if ( V_47 != V_49 )
return V_50 ;
F_37 ( V_36 , & V_51 ) ;
return V_52 ;
}
static void T_1 F_38 ( struct V_7 * V_53 )
{
struct V_54 V_55 ;
F_39 ( V_53 , 0 , & V_55 ) ;
V_56 = V_55 . V_57 ;
F_40 ( & V_56 ) ;
V_1 = F_17 ( V_53 , 0 ) ;
V_33 = F_17 ( V_53 , 1 ) ;
F_1 () ;
}
static void T_5 *
F_41 ( T_6 V_58 , T_4 V_26 ,
unsigned int V_59 , void * V_60 )
{
struct V_54 V_61 ;
F_42 ( & V_61 ) ;
if ( V_61 . V_57 <= V_58 && ( V_58 + V_26 ) <= V_61 . V_62 )
V_59 = V_63 ;
return F_43 ( V_58 , V_26 , V_59 , V_60 ) ;
}
static void T_1 F_44 ( struct V_7 * V_53 )
{
struct V_7 * V_64 ;
V_33 = F_17 ( V_53 , 0 ) ;
V_65 = F_41 ;
F_45 (cache_dn, NULL, L_7 ) {
struct V_9 * V_66 ;
V_66 = F_14 ( sizeof( * V_66 ) , V_15 ) ;
V_66 -> V_18 = F_15 ( L_8 , V_15 ) ;
F_46 ( V_64 , V_66 ) ;
}
}
static int F_47 ( void )
{
struct V_7 * V_53 ;
const struct V_67 * V_68 ;
V_53 = F_48 ( NULL , V_69 , & V_68 ) ;
if ( V_53 ) {
int type = ( int ) V_68 -> V_70 ;
if ( type == V_71 )
return type ;
else if ( type == V_72 && F_49 () )
return type ;
else if ( type == V_73 && F_49 () )
return type ;
}
return V_74 ;
}
int F_50 ( void )
{
return F_47 () != V_74 ;
}
int T_1 F_51 ( void )
{
int type = F_47 () ;
struct V_7 * V_53 ;
V_53 = F_52 ( NULL , V_69 ) ;
if ( type == V_71 )
F_38 ( V_53 ) ;
else if ( type == V_72 ||
type == V_73 )
F_44 ( V_53 ) ;
F_53 ( V_53 ) ;
return 0 ;
}
static int T_1 F_54 ( void )
{
int type = F_47 () ;
if ( type == V_74 )
return 0 ;
if ( type == V_72 ) {
T_2 V_36 , V_75 ;
if ( F_55 ( & V_36 , & V_75 ) == 0 &&
V_75 == V_76 )
F_11 () ;
}
F_56 ( & V_77 ,
& V_78 ) ;
return 0 ;
}
static int T_1 F_57 ( void )
{
if ( F_50 () )
F_56 ( & V_79 ,
& V_80 ) ;
return 0 ;
}
