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
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_2 ( V_3 , L_1 , V_2 ) ;
F_6 ( F_12 ( & V_2 -> V_4 ) > 1 ) ;
F_13 ( & V_2 -> V_4 ) ;
}
static T_1 F_14 ( struct V_11 * V_12 , const void * V_13 , unsigned V_14 )
{
int V_15 ;
T_1 V_16 ;
char * V_17 ;
V_16 = 0 ;
V_17 = ( char * ) V_13 ;
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
if ( V_17 [ V_15 ] == '\0' )
break;
V_16 = ( V_16 << 4 ) ^ ( V_16 >> 28 ) ^ V_17 [ V_15 ] ;
}
return ( V_16 % V_14 ) ;
}
static void * F_15 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_20 , struct V_1 , V_5 ) ;
return V_2 -> V_21 ;
}
static int F_17 ( const void * V_13 , struct V_19 * V_22 )
{
char * V_21 ;
struct V_1 * V_2 ;
V_21 = ( char * ) V_13 ;
V_2 = F_16 ( V_22 , struct V_1 , V_5 ) ;
return ! strncmp ( V_21 , V_2 -> V_21 , V_18 ) ;
}
static void * F_18 ( struct V_19 * V_20 )
{
return F_16 ( V_20 , struct V_1 , V_5 ) ;
}
static void F_19 ( struct V_11 * V_23 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_20 , struct V_1 , V_5 ) ;
F_1 ( V_2 ) ;
}
static void F_20 ( struct V_11 * V_23 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_20 , struct V_1 , V_5 ) ;
F_11 ( V_2 ) ;
}
static void * F_21 ( struct V_24 * V_25 , void * V_26 , T_2 * V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) V_25 -> V_30 ;
int V_31 ;
F_22 ( V_29 -> V_32 == V_33 , L_2 , V_29 -> V_32 ) ;
if ( * V_27 >= F_23 ( V_29 -> V_2 ) )
return NULL ;
V_31 = V_29 -> V_34 ;
F_24 ( & F_25 ( V_29 -> V_2 ) ) ;
V_29 -> V_34 ++ ;
if ( V_29 -> V_34 == F_23 ( V_29 -> V_2 ) ) {
V_29 -> V_34 = V_31 ;
F_26 ( & F_25 ( V_29 -> V_2 ) ) ;
return NULL ;
}
F_26 ( & F_25 ( V_29 -> V_2 ) ) ;
( * V_27 ) ++ ;
return V_29 ;
}
static void * F_27 ( struct V_24 * V_25 , T_2 * V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 -> V_30 ;
struct V_28 * V_29 ;
F_1 ( V_2 ) ;
if ( ( F_23 ( V_2 ) == 0 ) ||
( * V_27 >= F_23 ( V_2 ) ) ) {
F_4 ( V_2 ) ;
return NULL ;
}
V_29 = F_28 ( sizeof( * V_29 ) , V_35 ) ;
if ( ! V_29 )
return F_29 ( - V_36 ) ;
V_29 -> V_32 = V_33 ;
V_29 -> V_2 = V_2 ;
V_29 -> V_34 = 0 ;
V_25 -> V_30 = V_29 ;
if ( * V_27 > 0 ) {
T_2 V_15 ;
void * V_37 ;
V_15 = 0 ;
do {
V_37 = F_21 ( V_25 , & V_29 , & V_15 ) ;
} while ( ( V_15 < * V_27 ) && ( V_37 != NULL ) );
return V_37 ;
}
return V_29 ;
}
static void F_30 ( struct V_24 * V_25 , void * V_26 )
{
struct V_28 * V_29 = (struct V_28 * ) V_25 -> V_30 ;
if ( ( V_29 ) && ( V_29 -> V_32 == V_33 ) ) {
V_25 -> V_30 = V_29 -> V_2 ;
F_4 ( V_29 -> V_2 ) ;
F_10 ( V_29 ) ;
}
return;
}
static int F_31 ( struct V_24 * V_25 , void * V_26 )
{
struct V_28 * V_29 = (struct V_28 * ) V_26 ;
struct V_38 * V_39 ;
F_22 ( V_29 -> V_32 == V_33 , L_2 , V_29 -> V_32 ) ;
F_6 ( V_29 -> V_2 != NULL ) ;
F_6 ( V_29 -> V_34 <= F_23 ( V_29 -> V_2 ) ) ;
F_24 ( & F_25 ( V_29 -> V_2 ) ) ;
V_39 = F_32 ( V_29 -> V_2 , V_29 -> V_34 ) ;
F_26 ( & F_25 ( V_29 -> V_2 ) ) ;
if ( V_39 )
F_33 ( V_25 , L_3 , F_34 ( & ( V_39 -> V_40 ) ) ) ;
return 0 ;
}
static int F_35 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
int V_43 ;
V_43 = F_36 ( V_42 , & V_44 ) ;
if ( ! V_43 ) {
struct V_24 * V_25 = V_42 -> V_45 ;
V_25 -> V_30 = V_41 -> V_46 ;
}
return V_43 ;
}
void F_37 ( int V_47 , struct V_1 * V_2 )
{
int V_15 ;
F_1 ( V_2 ) ;
F_2 ( V_47 , L_4 V_48 L_5 ,
V_2 -> V_21 , V_2 -> V_10 . V_49 ) ;
F_24 ( & F_25 ( V_2 ) ) ;
for ( V_15 = 0 ; V_15 < F_23 ( V_2 ) ; V_15 ++ ) {
if ( ! F_32 ( V_2 , V_15 ) || ! ( F_32 ( V_2 , V_15 ) ) -> V_50 )
continue;
F_2 ( V_47 , L_4 V_48 L_6 ,
V_2 -> V_21 , V_15 ,
F_34 ( & ( ( F_32 ( V_2 , V_15 ) ) -> V_40 ) ) ) ;
}
F_26 ( & F_25 ( V_2 ) ) ;
F_4 ( V_2 ) ;
}
int F_38 ( struct V_51 * V_52 , unsigned int V_53 )
{
if ( V_53 == 0 )
V_53 = V_54 ;
V_52 -> V_55 = NULL ;
V_52 -> V_49 = 0 ;
F_39 ( & V_52 -> V_56 ) ;
V_52 -> V_57 = V_53 ;
V_52 -> V_55 = F_40 ( V_52 -> V_57 , sizeof( V_52 -> V_55 [ 0 ] ) , V_35 ) ;
if ( V_52 -> V_55 == NULL ) {
V_52 -> V_57 = 0 ;
return - V_36 ;
}
return 0 ;
}
int F_41 ( struct V_51 * V_52 , unsigned int V_58 )
{
T_1 * V_59 ;
int V_60 ;
F_6 ( V_58 != 0 ) ;
if ( V_52 -> V_49 < V_52 -> V_57 )
return 0 ;
V_60 = F_42 ( V_58 , 2 * V_52 -> V_57 ) ;
V_59 = F_40 ( V_60 , sizeof( V_52 -> V_55 [ 0 ] ) , V_35 ) ;
if ( V_59 == NULL )
return - V_36 ;
memcpy ( V_59 , V_52 -> V_55 , V_52 -> V_57 * sizeof( V_52 -> V_55 [ 0 ] ) ) ;
F_10 ( V_52 -> V_55 ) ;
V_52 -> V_55 = V_59 ;
V_52 -> V_57 = V_60 ;
return 0 ;
}
int F_43 ( struct V_51 * V_52 , T_1 V_34 , unsigned int V_58 )
{
int V_43 = 0 , V_15 ;
F_44 ( & V_52 -> V_56 ) ;
V_43 = F_41 ( V_52 , V_58 ) ;
if ( V_43 )
goto V_61;
for ( V_15 = 0 ; V_15 < V_52 -> V_49 ; V_15 ++ ) {
if ( V_52 -> V_55 [ V_15 ] == V_34 ) {
V_43 = - V_62 ;
goto V_61;
}
}
V_52 -> V_55 [ V_52 -> V_49 ] = V_34 ;
V_52 -> V_49 ++ ;
V_61:
F_45 ( & V_52 -> V_56 ) ;
return V_43 ;
}
int F_46 ( struct V_51 * V_52 , T_1 V_34 )
{
int V_15 ;
F_44 ( & V_52 -> V_56 ) ;
for ( V_15 = 0 ; V_15 < V_52 -> V_49 ; V_15 ++ ) {
if ( V_52 -> V_55 [ V_15 ] == V_34 ) {
memmove ( & V_52 -> V_55 [ V_15 ] , & V_52 -> V_55 [ V_15 + 1 ] ,
( V_52 -> V_49 - V_15 - 1 ) * sizeof( V_52 -> V_55 [ 0 ] ) ) ;
V_52 -> V_49 -- ;
F_45 ( & V_52 -> V_56 ) ;
return 0 ;
}
}
F_45 ( & V_52 -> V_56 ) ;
return - V_63 ;
}
int F_9 ( struct V_51 * V_52 )
{
if ( V_52 -> V_57 == 0 )
return 0 ;
F_44 ( & V_52 -> V_56 ) ;
F_10 ( V_52 -> V_55 ) ;
V_52 -> V_55 = NULL ;
V_52 -> V_49 = 0 ;
V_52 -> V_57 = 0 ;
F_45 ( & V_52 -> V_56 ) ;
return 0 ;
}
int F_47 ( struct V_64 * V_65 , char * V_17 )
{
struct V_66 * V_67 ;
struct V_1 * V_68 ;
int V_43 ;
V_67 = & ( V_65 -> V_69 . V_67 ) ;
if ( strlen ( V_17 ) > V_18 )
return - V_70 ;
V_68 = F_28 ( sizeof( * V_68 ) , V_35 ) ;
if ( ! V_68 )
return - V_36 ;
strncpy ( V_68 -> V_21 , V_17 , V_18 ) ;
V_68 -> V_21 [ V_18 ] = '\0' ;
V_68 -> V_71 = V_65 ;
F_48 ( & V_68 -> V_4 , 1 ) ;
V_43 = F_38 ( & V_68 -> V_10 , 0 ) ;
if ( V_43 )
goto V_72;
memset ( & ( V_68 -> V_8 ) , 0 , sizeof( struct V_73 ) ) ;
V_43 = F_38 ( & V_68 -> V_8 . V_9 , 0 ) ;
if ( V_43 )
goto V_74;
F_49 ( & V_68 -> V_5 ) ;
F_1 ( V_68 ) ;
V_68 -> V_7 = F_50 (
V_67 -> V_75 ,
V_17 , V_68 ,
& V_76 ) ;
if ( F_51 ( V_68 -> V_7 ) ) {
F_52 ( L_7 V_48 L_8 ,
V_17 ) ;
V_68 -> V_7 = NULL ;
F_4 ( V_68 ) ;
}
F_2 ( V_3 , L_9 ,
V_68 , V_68 -> V_7 ) ;
F_53 ( & V_65 -> V_77 ) ;
F_54 ( & V_68 -> V_6 , & V_67 -> V_78 ) ;
V_67 -> V_79 ++ ;
F_55 ( & V_65 -> V_77 ) ;
V_43 = F_56 ( V_67 -> V_80 , V_17 ,
& V_68 -> V_5 ) ;
if ( V_43 ) {
V_43 = - V_62 ;
goto V_72;
}
F_2 ( V_81 , V_48 L_10 ,
V_17 , V_67 -> V_79 ) ;
return 0 ;
V_72:
F_53 ( & V_65 -> V_77 ) ;
F_57 ( & V_68 -> V_6 ) ;
V_67 -> V_79 -- ;
F_55 ( & V_65 -> V_77 ) ;
F_58 ( & V_68 -> V_7 ) ;
F_9 ( & V_68 -> V_8 . V_9 ) ;
V_74:
F_9 ( & V_68 -> V_10 ) ;
F_10 ( V_68 ) ;
return V_43 ;
}
int F_59 ( struct V_64 * V_65 , char * V_17 )
{
struct V_66 * V_67 ;
struct V_1 * V_2 ;
V_67 = & ( V_65 -> V_69 . V_67 ) ;
V_2 = F_60 ( V_67 -> V_80 , V_17 ) ;
if ( V_2 == NULL )
return - V_82 ;
if ( ! F_51 ( V_2 -> V_7 ) ) {
F_2 ( V_3 , L_11 , V_2 -> V_7 ) ;
F_58 ( & V_2 -> V_7 ) ;
F_4 ( V_2 ) ;
}
F_53 ( & V_65 -> V_77 ) ;
F_57 ( & V_2 -> V_6 ) ;
V_67 -> V_79 -- ;
F_55 ( & V_65 -> V_77 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
int F_61 ( struct V_64 * V_65 , char * V_17 , char * V_83 )
{
struct V_84 V_85 ;
struct V_66 * V_67 ;
struct V_1 * V_2 ;
unsigned int V_86 ;
int V_43 ;
V_67 = & ( V_65 -> V_69 . V_67 ) ;
V_2 = F_62 ( V_67 -> V_80 , V_17 ) ;
if ( V_2 == NULL )
return - V_82 ;
F_63 ( & V_85 , V_83 ) ;
F_64 ( V_65 ) ;
for ( V_86 = 0 ; V_86 < V_67 -> V_87 . V_88 ; V_86 ++ ) {
if ( ! V_67 -> V_89 [ V_86 ] )
continue;
if ( F_65 ( & V_85 ,
& ( V_67 -> V_89 [ V_86 ] -> V_40 ) ) )
break;
}
if ( V_86 == V_67 -> V_87 . V_88 ) {
V_43 = - V_63 ;
goto V_61;
}
V_43 = F_43 ( & V_2 -> V_10 , V_86 , V_67 -> V_90 ) ;
if ( V_43 )
goto V_61;
V_2 -> V_8 . V_91 = 1 ;
F_2 ( V_81 , L_12 V_48 L_13 ,
V_83 , V_17 , F_23 ( V_2 ) ) ;
V_61:
F_66 ( V_65 ) ;
F_4 ( V_2 ) ;
return V_43 ;
}
int F_67 ( struct V_64 * V_65 , char * V_17 , char * V_83 )
{
struct V_84 V_85 ;
struct V_66 * V_67 ;
struct V_1 * V_2 ;
unsigned int V_86 ;
int V_43 = 0 ;
V_67 = & ( V_65 -> V_69 . V_67 ) ;
V_2 = F_62 ( V_67 -> V_80 , V_17 ) ;
if ( V_2 == NULL )
return - V_82 ;
F_63 ( & V_85 , V_83 ) ;
F_64 ( V_65 ) ;
for ( V_86 = 0 ; V_86 < V_67 -> V_87 . V_88 ; V_86 ++ ) {
if ( ! V_67 -> V_89 [ V_86 ] )
continue;
if ( F_65 ( & V_85 ,
& ( V_67 -> V_89 [ V_86 ] -> V_40 ) ) )
break;
}
if ( V_86 == V_67 -> V_87 . V_88 ) {
V_43 = - V_63 ;
goto V_61;
}
F_46 ( & V_2 -> V_10 , V_86 ) ;
V_2 -> V_8 . V_91 = 1 ;
F_2 ( V_81 , L_14 V_48 L_8 , V_83 ,
V_17 ) ;
V_61:
F_66 ( V_65 ) ;
F_4 ( V_2 ) ;
return V_43 ;
}
int F_68 ( T_1 V_34 , struct V_1 * V_2 )
{
int V_15 , V_43 ;
F_1 ( V_2 ) ;
F_24 ( & F_25 ( V_2 ) ) ;
for ( V_15 = 0 ; V_15 < F_23 ( V_2 ) ; V_15 ++ ) {
if ( F_69 ( V_2 ) [ V_15 ] == V_34 ) {
V_43 = 0 ;
goto V_61;
}
}
V_43 = - V_82 ;
V_61:
F_26 ( & F_25 ( V_2 ) ) ;
F_4 ( V_2 ) ;
return V_43 ;
}
struct V_1 * F_70 ( struct V_66 * V_67 , char * V_17 )
{
struct V_1 * V_2 ;
V_2 = NULL ;
if ( V_17 [ 0 ] != '\0' ) {
V_2 = F_62 ( V_67 -> V_80 , V_17 ) ;
if ( V_2 == NULL )
F_52 ( L_15 V_48 L_16 ,
V_17 ) ;
if ( ( V_2 != NULL ) && ( F_23 ( V_2 ) == 0 ) ) {
F_52 ( L_17 V_48 L_16 ,
V_17 ) ;
F_4 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
