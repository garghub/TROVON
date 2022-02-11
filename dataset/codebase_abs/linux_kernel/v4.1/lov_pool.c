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
F_28 ( V_29 ) ;
if ( ! V_29 )
return F_29 ( - V_35 ) ;
V_29 -> V_32 = V_33 ;
V_29 -> V_2 = V_2 ;
V_29 -> V_34 = 0 ;
V_25 -> V_30 = V_29 ;
if ( * V_27 > 0 ) {
T_2 V_15 ;
void * V_36 ;
V_15 = 0 ;
do {
V_36 = F_21 ( V_25 , & V_29 , & V_15 ) ;
} while ( ( V_15 < * V_27 ) && ( V_36 != NULL ) );
return V_36 ;
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
struct V_37 * V_38 ;
F_22 ( V_29 -> V_32 == V_33 , L_2 , V_29 -> V_32 ) ;
F_6 ( V_29 -> V_2 != NULL ) ;
F_6 ( V_29 -> V_34 <= F_23 ( V_29 -> V_2 ) ) ;
F_24 ( & F_25 ( V_29 -> V_2 ) ) ;
V_38 = F_32 ( V_29 -> V_2 , V_29 -> V_34 ) ;
F_26 ( & F_25 ( V_29 -> V_2 ) ) ;
if ( V_38 )
F_33 ( V_25 , L_3 , F_34 ( & ( V_38 -> V_39 ) ) ) ;
return 0 ;
}
static int F_35 ( struct V_40 * V_40 , struct V_41 * V_41 )
{
int V_42 ;
V_42 = F_36 ( V_41 , & V_43 ) ;
if ( ! V_42 ) {
struct V_24 * V_25 = V_41 -> V_44 ;
V_25 -> V_30 = F_37 ( V_40 ) ;
}
return V_42 ;
}
void F_38 ( int V_45 , struct V_1 * V_2 )
{
int V_15 ;
F_1 ( V_2 ) ;
F_2 ( V_45 , L_4 V_46 L_5 ,
V_2 -> V_21 , V_2 -> V_10 . V_47 ) ;
F_24 ( & F_25 ( V_2 ) ) ;
for ( V_15 = 0 ; V_15 < F_23 ( V_2 ) ; V_15 ++ ) {
if ( ! F_32 ( V_2 , V_15 ) || ! ( F_32 ( V_2 , V_15 ) ) -> V_48 )
continue;
F_2 ( V_45 , L_4 V_46 L_6 ,
V_2 -> V_21 , V_15 ,
F_34 ( & ( ( F_32 ( V_2 , V_15 ) ) -> V_39 ) ) ) ;
}
F_26 ( & F_25 ( V_2 ) ) ;
F_4 ( V_2 ) ;
}
int F_39 ( struct V_49 * V_50 , unsigned int V_51 )
{
if ( V_51 == 0 )
V_51 = V_52 ;
V_50 -> V_53 = NULL ;
V_50 -> V_47 = 0 ;
F_40 ( & V_50 -> V_54 ) ;
V_50 -> V_55 = V_51 ;
F_41 ( V_50 -> V_53 , V_50 -> V_55 * sizeof( V_50 -> V_53 [ 0 ] ) ) ;
if ( V_50 -> V_53 == NULL ) {
V_50 -> V_55 = 0 ;
return - V_35 ;
}
return 0 ;
}
int F_42 ( struct V_49 * V_50 , unsigned int V_56 )
{
T_1 * V_57 ;
int V_58 ;
F_6 ( V_56 != 0 ) ;
if ( V_50 -> V_47 < V_50 -> V_55 )
return 0 ;
V_58 = F_43 ( V_56 , 2 * V_50 -> V_55 ) ;
F_41 ( V_57 , V_58 * sizeof( V_50 -> V_53 [ 0 ] ) ) ;
if ( V_57 == NULL )
return - V_35 ;
memcpy ( V_57 , V_50 -> V_53 , V_50 -> V_55 * sizeof( V_50 -> V_53 [ 0 ] ) ) ;
F_44 ( V_50 -> V_53 , V_50 -> V_55 * sizeof( V_50 -> V_53 [ 0 ] ) ) ;
V_50 -> V_53 = V_57 ;
V_50 -> V_55 = V_58 ;
return 0 ;
}
int F_45 ( struct V_49 * V_50 , T_1 V_34 , unsigned int V_56 )
{
int V_42 = 0 , V_15 ;
F_46 ( & V_50 -> V_54 ) ;
V_42 = F_42 ( V_50 , V_56 ) ;
if ( V_42 )
goto V_59;
for ( V_15 = 0 ; V_15 < V_50 -> V_47 ; V_15 ++ ) {
if ( V_50 -> V_53 [ V_15 ] == V_34 ) {
V_42 = - V_60 ;
goto V_59;
}
}
V_50 -> V_53 [ V_50 -> V_47 ] = V_34 ;
V_50 -> V_47 ++ ;
V_59:
F_47 ( & V_50 -> V_54 ) ;
return V_42 ;
}
int F_48 ( struct V_49 * V_50 , T_1 V_34 )
{
int V_15 ;
F_46 ( & V_50 -> V_54 ) ;
for ( V_15 = 0 ; V_15 < V_50 -> V_47 ; V_15 ++ ) {
if ( V_50 -> V_53 [ V_15 ] == V_34 ) {
memmove ( & V_50 -> V_53 [ V_15 ] , & V_50 -> V_53 [ V_15 + 1 ] ,
( V_50 -> V_47 - V_15 - 1 ) * sizeof( V_50 -> V_53 [ 0 ] ) ) ;
V_50 -> V_47 -- ;
F_47 ( & V_50 -> V_54 ) ;
return 0 ;
}
}
F_47 ( & V_50 -> V_54 ) ;
return - V_61 ;
}
int F_9 ( struct V_49 * V_50 )
{
if ( V_50 -> V_55 == 0 )
return 0 ;
F_46 ( & V_50 -> V_54 ) ;
F_44 ( V_50 -> V_53 , V_50 -> V_55 * sizeof( V_50 -> V_53 [ 0 ] ) ) ;
V_50 -> V_53 = NULL ;
V_50 -> V_47 = 0 ;
V_50 -> V_55 = 0 ;
F_47 ( & V_50 -> V_54 ) ;
return 0 ;
}
int F_49 ( struct V_62 * V_63 , char * V_17 )
{
struct V_64 * V_65 ;
struct V_1 * V_66 ;
int V_42 ;
V_65 = & ( V_63 -> V_67 . V_65 ) ;
if ( strlen ( V_17 ) > V_18 )
return - V_68 ;
F_28 ( V_66 ) ;
if ( V_66 == NULL )
return - V_35 ;
strncpy ( V_66 -> V_21 , V_17 , V_18 ) ;
V_66 -> V_21 [ V_18 ] = '\0' ;
V_66 -> V_69 = V_63 ;
F_50 ( & V_66 -> V_4 , 1 ) ;
V_42 = F_39 ( & V_66 -> V_10 , 0 ) ;
if ( V_42 )
goto V_70;
memset ( & ( V_66 -> V_8 ) , 0 , sizeof( struct V_71 ) ) ;
V_42 = F_39 ( & V_66 -> V_8 . V_9 , 0 ) ;
if ( V_42 )
goto V_72;
F_51 ( & V_66 -> V_5 ) ;
#if F_52 ( V_73 )
F_1 ( V_66 ) ;
V_66 -> V_7 = F_53 ( V_65 -> V_74 ,
V_17 , V_66 ,
& V_75 ) ;
if ( F_54 ( V_66 -> V_7 ) ) {
F_55 ( L_7 V_46 L_8 , V_17 ) ;
V_66 -> V_7 = NULL ;
F_4 ( V_66 ) ;
}
F_2 ( V_3 , L_9 , V_66 , V_66 -> V_7 ) ;
#endif
F_56 ( & V_63 -> V_76 ) ;
F_57 ( & V_66 -> V_6 , & V_65 -> V_77 ) ;
V_65 -> V_78 ++ ;
F_58 ( & V_63 -> V_76 ) ;
V_42 = F_59 ( V_65 -> V_79 , V_17 ,
& V_66 -> V_5 ) ;
if ( V_42 ) {
V_42 = - V_60 ;
goto V_70;
}
F_2 ( V_80 , V_46 L_10 ,
V_17 , V_65 -> V_78 ) ;
return 0 ;
V_70:
F_56 ( & V_63 -> V_76 ) ;
F_60 ( & V_66 -> V_6 ) ;
V_65 -> V_78 -- ;
F_58 ( & V_63 -> V_76 ) ;
F_61 ( & V_66 -> V_7 ) ;
F_9 ( & V_66 -> V_8 . V_9 ) ;
V_72:
F_9 ( & V_66 -> V_10 ) ;
F_10 ( V_66 ) ;
return V_42 ;
}
int F_62 ( struct V_62 * V_63 , char * V_17 )
{
struct V_64 * V_65 ;
struct V_1 * V_2 ;
V_65 = & ( V_63 -> V_67 . V_65 ) ;
V_2 = F_63 ( V_65 -> V_79 , V_17 ) ;
if ( V_2 == NULL )
return - V_81 ;
if ( V_2 -> V_7 != NULL ) {
F_2 ( V_3 , L_11 , V_2 -> V_7 ) ;
F_61 ( & V_2 -> V_7 ) ;
F_4 ( V_2 ) ;
}
F_56 ( & V_63 -> V_76 ) ;
F_60 ( & V_2 -> V_6 ) ;
V_65 -> V_78 -- ;
F_58 ( & V_63 -> V_76 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
int F_64 ( struct V_62 * V_63 , char * V_17 , char * V_82 )
{
struct V_83 V_84 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
unsigned int V_85 ;
int V_42 ;
V_65 = & ( V_63 -> V_67 . V_65 ) ;
V_2 = F_65 ( V_65 -> V_79 , V_17 ) ;
if ( V_2 == NULL )
return - V_81 ;
F_66 ( & V_84 , V_82 ) ;
F_67 ( V_63 ) ;
for ( V_85 = 0 ; V_85 < V_65 -> V_86 . V_87 ; V_85 ++ ) {
if ( ! V_65 -> V_88 [ V_85 ] )
continue;
if ( F_68 ( & V_84 ,
& ( V_65 -> V_88 [ V_85 ] -> V_39 ) ) )
break;
}
if ( V_85 == V_65 -> V_86 . V_87 ) {
V_42 = - V_61 ;
goto V_59;
}
V_42 = F_45 ( & V_2 -> V_10 , V_85 , V_65 -> V_89 ) ;
if ( V_42 )
goto V_59;
V_2 -> V_8 . V_90 = 1 ;
F_2 ( V_80 , L_12 V_46 L_13 ,
V_82 , V_17 , F_23 ( V_2 ) ) ;
V_59:
F_69 ( V_63 ) ;
F_4 ( V_2 ) ;
return V_42 ;
}
int F_70 ( struct V_62 * V_63 , char * V_17 , char * V_82 )
{
struct V_83 V_84 ;
struct V_64 * V_65 ;
struct V_1 * V_2 ;
unsigned int V_85 ;
int V_42 = 0 ;
V_65 = & ( V_63 -> V_67 . V_65 ) ;
V_2 = F_65 ( V_65 -> V_79 , V_17 ) ;
if ( V_2 == NULL )
return - V_81 ;
F_66 ( & V_84 , V_82 ) ;
F_67 ( V_63 ) ;
for ( V_85 = 0 ; V_85 < V_65 -> V_86 . V_87 ; V_85 ++ ) {
if ( ! V_65 -> V_88 [ V_85 ] )
continue;
if ( F_68 ( & V_84 ,
& ( V_65 -> V_88 [ V_85 ] -> V_39 ) ) )
break;
}
if ( V_85 == V_65 -> V_86 . V_87 ) {
V_42 = - V_61 ;
goto V_59;
}
F_48 ( & V_2 -> V_10 , V_85 ) ;
V_2 -> V_8 . V_90 = 1 ;
F_2 ( V_80 , L_14 V_46 L_8 , V_82 ,
V_17 ) ;
V_59:
F_69 ( V_63 ) ;
F_4 ( V_2 ) ;
return V_42 ;
}
int F_71 ( T_1 V_34 , struct V_1 * V_2 )
{
int V_15 , V_42 ;
F_1 ( V_2 ) ;
F_24 ( & F_25 ( V_2 ) ) ;
for ( V_15 = 0 ; V_15 < F_23 ( V_2 ) ; V_15 ++ ) {
if ( F_72 ( V_2 ) [ V_15 ] == V_34 ) {
V_42 = 0 ;
goto V_59;
}
}
V_42 = - V_81 ;
V_59:
F_26 ( & F_25 ( V_2 ) ) ;
F_4 ( V_2 ) ;
return V_42 ;
}
struct V_1 * F_73 ( struct V_64 * V_65 , char * V_17 )
{
struct V_1 * V_2 ;
V_2 = NULL ;
if ( V_17 [ 0 ] != '\0' ) {
V_2 = F_65 ( V_65 -> V_79 , V_17 ) ;
if ( V_2 == NULL )
F_55 ( L_15 V_46 L_16 ,
V_17 ) ;
if ( ( V_2 != NULL ) && ( F_23 ( V_2 ) == 0 ) ) {
F_55 ( L_17 V_46 L_16 ,
V_17 ) ;
F_4 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
