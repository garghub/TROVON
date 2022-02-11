static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , L_1 , V_2 ) ;
F_3 ( & V_2 -> V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_3 , L_1 , V_2 ) ;
if ( F_5 ( & V_2 -> V_4 ) ) {
F_6 ( F_7 ( & V_2 -> V_5 ) ) ;
F_6 ( F_8 ( & V_2 -> V_6 ) ) ;
F_6 ( V_2 -> V_7 == NULL ) ;
F_9 ( & ( V_2 -> V_8 . V_9 ) ) ;
F_9 ( & ( V_2 -> V_10 ) ) ;
F_10 ( V_2 ) ;
EXIT ;
}
}
void F_11 ( struct V_1 * V_2 )
{
F_2 ( V_3 , L_1 , V_2 ) ;
F_6 ( F_12 ( & V_2 -> V_4 ) > 1 ) ;
F_13 ( & V_2 -> V_4 ) ;
}
static T_1 F_14 ( T_2 * V_11 , const void * V_12 , unsigned V_13 )
{
int V_14 ;
T_1 V_15 ;
char * V_16 ;
V_15 = 0 ;
V_16 = ( char * ) V_12 ;
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ ) {
if ( V_16 [ V_14 ] == '\0' )
break;
V_15 = ( V_15 << 4 ) ^ ( V_15 >> 28 ) ^ V_16 [ V_14 ] ;
}
return ( V_15 % V_13 ) ;
}
static void * F_15 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_19 , struct V_1 , V_5 ) ;
return ( V_2 -> V_20 ) ;
}
static int F_17 ( const void * V_12 , struct V_18 * V_21 )
{
char * V_20 ;
struct V_1 * V_2 ;
V_20 = ( char * ) V_12 ;
V_2 = F_16 ( V_21 , struct V_1 , V_5 ) ;
return ! strncmp ( V_20 , V_2 -> V_20 , V_17 ) ;
}
static void * F_18 ( struct V_18 * V_19 )
{
return F_16 ( V_19 , struct V_1 , V_5 ) ;
}
static void F_19 ( T_2 * V_22 , struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_19 , struct V_1 , V_5 ) ;
F_1 ( V_2 ) ;
}
static void F_20 ( T_2 * V_22 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_19 , struct V_1 , V_5 ) ;
F_11 ( V_2 ) ;
}
static void * F_21 ( struct V_23 * V_24 , void * V_25 , T_3 * V_26 )
{
struct V_27 * V_28 = (struct V_27 * ) V_24 -> V_29 ;
int V_30 ;
F_22 ( V_28 -> V_31 == V_32 , L_2 , V_28 -> V_31 ) ;
if ( * V_26 >= F_23 ( V_28 -> V_2 ) )
return NULL ;
V_30 = V_28 -> V_33 ;
F_24 ( & F_25 ( V_28 -> V_2 ) ) ;
V_28 -> V_33 ++ ;
if ( V_28 -> V_33 == F_23 ( V_28 -> V_2 ) ) {
V_28 -> V_33 = V_30 ;
F_26 ( & F_25 ( V_28 -> V_2 ) ) ;
return NULL ;
}
F_26 ( & F_25 ( V_28 -> V_2 ) ) ;
( * V_26 ) ++ ;
return V_28 ;
}
static void * F_27 ( struct V_23 * V_24 , T_3 * V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_29 ;
struct V_27 * V_28 ;
F_1 ( V_2 ) ;
if ( ( F_23 ( V_2 ) == 0 ) ||
( * V_26 >= F_23 ( V_2 ) ) ) {
F_4 ( V_2 ) ;
return NULL ;
}
F_28 ( V_28 ) ;
if ( ! V_28 )
return F_29 ( - V_34 ) ;
V_28 -> V_31 = V_32 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_33 = 0 ;
V_24 -> V_29 = V_28 ;
if ( * V_26 > 0 ) {
T_3 V_14 ;
void * V_35 ;
V_14 = 0 ;
do {
V_35 = F_21 ( V_24 , & V_28 , & V_14 ) ;
} while ( ( V_14 < * V_26 ) && ( V_35 != NULL ) );
return V_35 ;
}
return V_28 ;
}
static void F_30 ( struct V_23 * V_24 , void * V_25 )
{
struct V_27 * V_28 = (struct V_27 * ) V_24 -> V_29 ;
if ( ( V_28 ) && ( V_28 -> V_31 == V_32 ) ) {
V_24 -> V_29 = V_28 -> V_2 ;
F_4 ( V_28 -> V_2 ) ;
F_10 ( V_28 ) ;
}
return;
}
static int F_31 ( struct V_23 * V_24 , void * V_25 )
{
struct V_27 * V_28 = (struct V_27 * ) V_25 ;
struct V_36 * V_37 ;
F_22 ( V_28 -> V_31 == V_32 , L_2 , V_28 -> V_31 ) ;
F_6 ( V_28 -> V_2 != NULL ) ;
F_6 ( V_28 -> V_33 <= F_23 ( V_28 -> V_2 ) ) ;
F_24 ( & F_25 ( V_28 -> V_2 ) ) ;
V_37 = F_32 ( V_28 -> V_2 , V_28 -> V_33 ) ;
F_26 ( & F_25 ( V_28 -> V_2 ) ) ;
if ( V_37 )
F_33 ( V_24 , L_3 , F_34 ( & ( V_37 -> V_38 ) ) ) ;
return 0 ;
}
static int F_35 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
int V_41 ;
V_41 = F_36 ( V_40 , & V_42 ) ;
if ( ! V_41 ) {
struct V_23 * V_24 = V_40 -> V_43 ;
V_24 -> V_29 = F_37 ( V_39 ) ;
}
return V_41 ;
}
void F_38 ( int V_44 , struct V_1 * V_2 )
{
int V_14 ;
F_1 ( V_2 ) ;
F_2 ( V_44 , L_4 V_45 L_5 ,
V_2 -> V_20 , V_2 -> V_10 . V_46 ) ;
F_24 ( & F_25 ( V_2 ) ) ;
for ( V_14 = 0 ; V_14 < F_23 ( V_2 ) ; V_14 ++ ) {
if ( ! F_32 ( V_2 , V_14 ) || ! ( F_32 ( V_2 , V_14 ) ) -> V_47 )
continue;
F_2 ( V_44 , L_4 V_45 L_6 ,
V_2 -> V_20 , V_14 ,
F_34 ( & ( ( F_32 ( V_2 , V_14 ) ) -> V_38 ) ) ) ;
}
F_26 ( & F_25 ( V_2 ) ) ;
F_4 ( V_2 ) ;
}
int F_39 ( struct V_48 * V_49 , unsigned int V_50 )
{
V_51 ;
if ( V_50 == 0 )
V_50 = V_52 ;
V_49 -> V_53 = NULL ;
V_49 -> V_46 = 0 ;
F_40 ( & V_49 -> V_54 ) ;
V_49 -> V_55 = V_50 ;
F_41 ( V_49 -> V_53 , V_49 -> V_55 * sizeof( V_49 -> V_53 [ 0 ] ) ) ;
if ( V_49 -> V_53 == NULL ) {
V_49 -> V_55 = 0 ;
RETURN ( - V_34 ) ;
}
EXIT ;
return 0 ;
}
int F_42 ( struct V_48 * V_49 , unsigned int V_56 )
{
T_1 * V_57 ;
int V_58 ;
F_6 ( V_56 != 0 ) ;
if ( V_49 -> V_46 < V_49 -> V_55 )
return 0 ;
V_58 = F_43 ( V_56 , 2 * V_49 -> V_55 ) ;
F_41 ( V_57 , V_58 * sizeof( V_49 -> V_53 [ 0 ] ) ) ;
if ( V_57 == NULL )
return - V_34 ;
memcpy ( V_57 , V_49 -> V_53 , V_49 -> V_55 * sizeof( V_49 -> V_53 [ 0 ] ) ) ;
F_44 ( V_49 -> V_53 , V_49 -> V_55 * sizeof( V_49 -> V_53 [ 0 ] ) ) ;
V_49 -> V_53 = V_57 ;
V_49 -> V_55 = V_58 ;
return 0 ;
}
int F_45 ( struct V_48 * V_49 , T_1 V_33 , unsigned int V_56 )
{
int V_41 = 0 , V_14 ;
V_51 ;
F_46 ( & V_49 -> V_54 ) ;
V_41 = F_42 ( V_49 , V_56 ) ;
if ( V_41 )
GOTO ( V_59 , V_41 ) ;
for ( V_14 = 0 ; V_14 < V_49 -> V_46 ; V_14 ++ ) {
if ( V_49 -> V_53 [ V_14 ] == V_33 )
GOTO ( V_59 , V_41 = - V_60 ) ;
}
V_49 -> V_53 [ V_49 -> V_46 ] = V_33 ;
V_49 -> V_46 ++ ;
EXIT ;
V_59:
F_47 ( & V_49 -> V_54 ) ;
return V_41 ;
}
int F_48 ( struct V_48 * V_49 , T_1 V_33 )
{
int V_14 ;
V_51 ;
F_46 ( & V_49 -> V_54 ) ;
for ( V_14 = 0 ; V_14 < V_49 -> V_46 ; V_14 ++ ) {
if ( V_49 -> V_53 [ V_14 ] == V_33 ) {
memmove ( & V_49 -> V_53 [ V_14 ] , & V_49 -> V_53 [ V_14 + 1 ] ,
( V_49 -> V_46 - V_14 - 1 ) * sizeof( V_49 -> V_53 [ 0 ] ) ) ;
V_49 -> V_46 -- ;
F_47 ( & V_49 -> V_54 ) ;
EXIT ;
return 0 ;
}
}
F_47 ( & V_49 -> V_54 ) ;
RETURN ( - V_61 ) ;
}
int F_9 ( struct V_48 * V_49 )
{
V_51 ;
if ( V_49 -> V_55 == 0 )
RETURN ( 0 ) ;
F_46 ( & V_49 -> V_54 ) ;
F_44 ( V_49 -> V_53 , V_49 -> V_55 * sizeof( V_49 -> V_53 [ 0 ] ) ) ;
V_49 -> V_53 = NULL ;
V_49 -> V_46 = 0 ;
V_49 -> V_55 = 0 ;
F_47 ( & V_49 -> V_54 ) ;
RETURN ( 0 ) ;
}
int F_49 ( struct V_62 * V_63 , char * V_16 )
{
struct V_64 * V_65 ;
struct V_1 * V_66 ;
int V_41 ;
V_51 ;
V_65 = & ( V_63 -> V_67 . V_65 ) ;
if ( strlen ( V_16 ) > V_17 )
RETURN ( - V_68 ) ;
F_28 ( V_66 ) ;
if ( V_66 == NULL )
RETURN ( - V_34 ) ;
strncpy ( V_66 -> V_20 , V_16 , V_17 ) ;
V_66 -> V_20 [ V_17 ] = '\0' ;
V_66 -> V_69 = V_63 ;
F_50 ( & V_66 -> V_4 , 1 ) ;
V_41 = F_39 ( & V_66 -> V_10 , 0 ) ;
if ( V_41 )
GOTO ( V_70 , V_41 ) ;
memset ( & ( V_66 -> V_8 ) , 0 , sizeof( struct V_71 ) ) ;
V_41 = F_39 ( & V_66 -> V_8 . V_9 , 0 ) ;
if ( V_41 )
GOTO ( V_72 , V_41 ) ;
F_51 ( & V_66 -> V_5 ) ;
#ifdef F_52
F_1 ( V_66 ) ;
V_66 -> V_7 = F_53 ( V_65 -> V_73 ,
V_16 , V_66 ,
& V_74 ) ;
if ( F_54 ( V_66 -> V_7 ) ) {
F_55 ( L_7 V_45 L_8 , V_16 ) ;
V_66 -> V_7 = NULL ;
F_4 ( V_66 ) ;
}
F_2 ( V_3 , L_9 , V_66 , V_66 -> V_7 ) ;
#endif
F_56 ( & V_63 -> V_75 ) ;
F_57 ( & V_66 -> V_6 , & V_65 -> V_76 ) ;
V_65 -> V_77 ++ ;
F_58 ( & V_63 -> V_75 ) ;
V_41 = F_59 ( V_65 -> V_78 , V_16 ,
& V_66 -> V_5 ) ;
if ( V_41 )
GOTO ( V_70 , V_41 = - V_60 ) ;
F_2 ( V_79 , V_45 L_10 ,
V_16 , V_65 -> V_77 ) ;
RETURN ( 0 ) ;
V_70:
F_56 ( & V_63 -> V_75 ) ;
F_60 ( & V_66 -> V_6 ) ;
V_65 -> V_77 -- ;
F_58 ( & V_63 -> V_75 ) ;
F_61 ( & V_66 -> V_7 ) ;
F_9 ( & V_66 -> V_8 . V_9 ) ;
V_72:
F_9 ( & V_66 -> V_10 ) ;
F_10 ( V_66 ) ;
return V_41 ;
}
int F_62 ( struct V_62 * V_63 , char * V_16 )
{
struct V_64 * V_65 ;
struct V_1 * V_2 ;
V_51 ;
V_65 = & ( V_63 -> V_67 . V_65 ) ;
V_2 = F_63 ( V_65 -> V_78 , V_16 ) ;
if ( V_2 == NULL )
RETURN ( - V_80 ) ;
if ( V_2 -> V_7 != NULL ) {
F_2 ( V_3 , L_11 , V_2 -> V_7 ) ;
F_61 ( & V_2 -> V_7 ) ;
F_4 ( V_2 ) ;
}
F_56 ( & V_63 -> V_75 ) ;
F_60 ( & V_2 -> V_6 ) ;
V_65 -> V_77 -- ;
F_58 ( & V_63 -> V_75 ) ;
F_4 ( V_2 ) ;
RETURN ( 0 ) ;
}
int F_64 ( struct V_62 * V_63 , char * V_16 , char * V_81 )
{
struct V_82 V_83 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
unsigned int V_84 ;
int V_41 ;
V_51 ;
V_65 = & ( V_63 -> V_67 . V_65 ) ;
V_2 = F_65 ( V_65 -> V_78 , V_16 ) ;
if ( V_2 == NULL )
RETURN ( - V_80 ) ;
F_66 ( & V_83 , V_81 ) ;
F_67 ( V_63 ) ;
for ( V_84 = 0 ; V_84 < V_65 -> V_85 . V_86 ; V_84 ++ ) {
if ( ! V_65 -> V_87 [ V_84 ] )
continue;
if ( F_68 ( & V_83 ,
& ( V_65 -> V_87 [ V_84 ] -> V_38 ) ) )
break;
}
if ( V_84 == V_65 -> V_85 . V_86 )
GOTO ( V_59 , V_41 = - V_61 ) ;
V_41 = F_45 ( & V_2 -> V_10 , V_84 , V_65 -> V_88 ) ;
if ( V_41 )
GOTO ( V_59 , V_41 ) ;
V_2 -> V_8 . V_89 = 1 ;
F_2 ( V_79 , L_12 V_45 L_13 ,
V_81 , V_16 , F_23 ( V_2 ) ) ;
EXIT ;
V_59:
F_69 ( V_63 ) ;
F_4 ( V_2 ) ;
return V_41 ;
}
int F_70 ( struct V_62 * V_63 , char * V_16 , char * V_81 )
{
struct V_82 V_83 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
unsigned int V_84 ;
int V_41 = 0 ;
V_51 ;
V_65 = & ( V_63 -> V_67 . V_65 ) ;
V_2 = F_65 ( V_65 -> V_78 , V_16 ) ;
if ( V_2 == NULL )
RETURN ( - V_80 ) ;
F_66 ( & V_83 , V_81 ) ;
F_67 ( V_63 ) ;
for ( V_84 = 0 ; V_84 < V_65 -> V_85 . V_86 ; V_84 ++ ) {
if ( ! V_65 -> V_87 [ V_84 ] )
continue;
if ( F_68 ( & V_83 ,
& ( V_65 -> V_87 [ V_84 ] -> V_38 ) ) )
break;
}
if ( V_84 == V_65 -> V_85 . V_86 )
GOTO ( V_59 , V_41 = - V_61 ) ;
F_48 ( & V_2 -> V_10 , V_84 ) ;
V_2 -> V_8 . V_89 = 1 ;
F_2 ( V_79 , L_14 V_45 L_8 , V_81 ,
V_16 ) ;
EXIT ;
V_59:
F_69 ( V_63 ) ;
F_4 ( V_2 ) ;
return V_41 ;
}
int F_71 ( T_1 V_33 , struct V_1 * V_2 )
{
int V_14 , V_41 ;
V_51 ;
F_1 ( V_2 ) ;
F_24 ( & F_25 ( V_2 ) ) ;
for ( V_14 = 0 ; V_14 < F_23 ( V_2 ) ; V_14 ++ ) {
if ( F_72 ( V_2 ) [ V_14 ] == V_33 )
GOTO ( V_59 , V_41 = 0 ) ;
}
V_41 = - V_80 ;
EXIT ;
V_59:
F_26 ( & F_25 ( V_2 ) ) ;
F_4 ( V_2 ) ;
return V_41 ;
}
struct V_1 * F_73 ( struct V_64 * V_65 , char * V_16 )
{
struct V_1 * V_2 ;
V_2 = NULL ;
if ( V_16 [ 0 ] != '\0' ) {
V_2 = F_65 ( V_65 -> V_78 , V_16 ) ;
if ( V_2 == NULL )
F_55 ( L_15 V_45 L_16 ,
V_16 ) ;
if ( ( V_2 != NULL ) && ( F_23 ( V_2 ) == 0 ) ) {
F_55 ( L_17 V_45 L_16 ,
V_16 ) ;
F_4 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
