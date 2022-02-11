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
F_6 ( ! V_2 -> V_7 ) ;
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
} while ( ( V_15 < * V_27 ) && V_37 );
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
}
static int F_31 ( struct V_24 * V_25 , void * V_26 )
{
struct V_28 * V_29 = (struct V_28 * ) V_26 ;
struct V_38 * V_39 ;
F_22 ( V_29 -> V_32 == V_33 , L_2 , V_29 -> V_32 ) ;
F_6 ( V_29 -> V_2 ) ;
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
int F_37 ( struct V_47 * V_48 , unsigned int V_49 )
{
if ( V_49 == 0 )
V_49 = V_50 ;
V_48 -> V_51 = NULL ;
V_48 -> V_52 = 0 ;
F_38 ( & V_48 -> V_53 ) ;
V_48 -> V_54 = V_49 ;
V_48 -> V_51 = F_39 ( V_48 -> V_54 , sizeof( V_48 -> V_51 [ 0 ] ) , V_35 ) ;
if ( ! V_48 -> V_51 ) {
V_48 -> V_54 = 0 ;
return - V_36 ;
}
return 0 ;
}
int F_40 ( struct V_47 * V_48 , unsigned int V_55 )
{
T_1 * V_56 ;
int V_57 ;
F_6 ( V_55 != 0 ) ;
if ( V_48 -> V_52 < V_48 -> V_54 )
return 0 ;
V_57 = F_41 ( V_55 , 2 * V_48 -> V_54 ) ;
V_56 = F_39 ( V_57 , sizeof( V_48 -> V_51 [ 0 ] ) , V_35 ) ;
if ( ! V_56 )
return - V_36 ;
memcpy ( V_56 , V_48 -> V_51 , V_48 -> V_54 * sizeof( V_48 -> V_51 [ 0 ] ) ) ;
F_10 ( V_48 -> V_51 ) ;
V_48 -> V_51 = V_56 ;
V_48 -> V_54 = V_57 ;
return 0 ;
}
int F_42 ( struct V_47 * V_48 , T_1 V_34 , unsigned int V_55 )
{
int V_43 = 0 , V_15 ;
F_43 ( & V_48 -> V_53 ) ;
V_43 = F_40 ( V_48 , V_55 ) ;
if ( V_43 )
goto V_58;
for ( V_15 = 0 ; V_15 < V_48 -> V_52 ; V_15 ++ ) {
if ( V_48 -> V_51 [ V_15 ] == V_34 ) {
V_43 = - V_59 ;
goto V_58;
}
}
V_48 -> V_51 [ V_48 -> V_52 ] = V_34 ;
V_48 -> V_52 ++ ;
V_58:
F_44 ( & V_48 -> V_53 ) ;
return V_43 ;
}
int F_45 ( struct V_47 * V_48 , T_1 V_34 )
{
int V_15 ;
F_43 ( & V_48 -> V_53 ) ;
for ( V_15 = 0 ; V_15 < V_48 -> V_52 ; V_15 ++ ) {
if ( V_48 -> V_51 [ V_15 ] == V_34 ) {
memmove ( & V_48 -> V_51 [ V_15 ] , & V_48 -> V_51 [ V_15 + 1 ] ,
( V_48 -> V_52 - V_15 - 1 ) * sizeof( V_48 -> V_51 [ 0 ] ) ) ;
V_48 -> V_52 -- ;
F_44 ( & V_48 -> V_53 ) ;
return 0 ;
}
}
F_44 ( & V_48 -> V_53 ) ;
return - V_60 ;
}
int F_9 ( struct V_47 * V_48 )
{
if ( V_48 -> V_54 == 0 )
return 0 ;
F_43 ( & V_48 -> V_53 ) ;
F_10 ( V_48 -> V_51 ) ;
V_48 -> V_51 = NULL ;
V_48 -> V_52 = 0 ;
V_48 -> V_54 = 0 ;
F_44 ( & V_48 -> V_53 ) ;
return 0 ;
}
int F_46 ( struct V_61 * V_62 , char * V_17 )
{
struct V_63 * V_64 ;
struct V_1 * V_65 ;
int V_43 ;
V_64 = & ( V_62 -> V_66 . V_64 ) ;
if ( strlen ( V_17 ) > V_18 )
return - V_67 ;
V_65 = F_28 ( sizeof( * V_65 ) , V_35 ) ;
if ( ! V_65 )
return - V_36 ;
F_47 ( V_65 -> V_21 , V_17 , sizeof( V_65 -> V_21 ) ) ;
V_65 -> V_68 = V_62 ;
F_48 ( & V_65 -> V_4 , 1 ) ;
V_43 = F_37 ( & V_65 -> V_10 , 0 ) ;
if ( V_43 )
goto V_69;
memset ( & ( V_65 -> V_8 ) , 0 , sizeof( struct V_70 ) ) ;
V_43 = F_37 ( & V_65 -> V_8 . V_9 , 0 ) ;
if ( V_43 )
goto V_71;
F_49 ( & V_65 -> V_5 ) ;
F_1 ( V_65 ) ;
V_65 -> V_7 = F_50 (
V_64 -> V_72 ,
V_17 , V_65 ,
& V_73 ) ;
if ( F_51 ( V_65 -> V_7 ) ) {
F_52 ( L_4 V_74 L_5 ,
V_17 ) ;
V_65 -> V_7 = NULL ;
F_4 ( V_65 ) ;
}
F_2 ( V_3 , L_6 ,
V_65 , V_65 -> V_7 ) ;
F_53 ( & V_62 -> V_75 ) ;
F_54 ( & V_65 -> V_6 , & V_64 -> V_76 ) ;
V_64 -> V_77 ++ ;
F_55 ( & V_62 -> V_75 ) ;
V_43 = F_56 ( V_64 -> V_78 , V_17 ,
& V_65 -> V_5 ) ;
if ( V_43 ) {
V_43 = - V_59 ;
goto V_69;
}
F_2 ( V_79 , V_74 L_7 ,
V_17 , V_64 -> V_77 ) ;
return 0 ;
V_69:
F_53 ( & V_62 -> V_75 ) ;
F_57 ( & V_65 -> V_6 ) ;
V_64 -> V_77 -- ;
F_55 ( & V_62 -> V_75 ) ;
F_58 ( & V_65 -> V_7 ) ;
F_9 ( & V_65 -> V_8 . V_9 ) ;
V_71:
F_9 ( & V_65 -> V_10 ) ;
F_10 ( V_65 ) ;
return V_43 ;
}
int F_59 ( struct V_61 * V_62 , char * V_17 )
{
struct V_63 * V_64 ;
struct V_1 * V_2 ;
V_64 = & ( V_62 -> V_66 . V_64 ) ;
V_2 = F_60 ( V_64 -> V_78 , V_17 ) ;
if ( ! V_2 )
return - V_80 ;
if ( ! F_51 ( V_2 -> V_7 ) ) {
F_2 ( V_3 , L_8 , V_2 -> V_7 ) ;
F_58 ( & V_2 -> V_7 ) ;
F_4 ( V_2 ) ;
}
F_53 ( & V_62 -> V_75 ) ;
F_57 ( & V_2 -> V_6 ) ;
V_64 -> V_77 -- ;
F_55 ( & V_62 -> V_75 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
int F_61 ( struct V_61 * V_62 , char * V_17 , char * V_81 )
{
struct V_82 V_83 ;
struct V_63 * V_64 ;
struct V_1 * V_2 ;
unsigned int V_84 ;
int V_43 ;
V_64 = & ( V_62 -> V_66 . V_64 ) ;
V_2 = F_62 ( V_64 -> V_78 , V_17 ) ;
if ( ! V_2 )
return - V_80 ;
F_63 ( & V_83 , V_81 ) ;
F_64 ( V_62 ) ;
for ( V_84 = 0 ; V_84 < V_64 -> V_85 . V_86 ; V_84 ++ ) {
if ( ! V_64 -> V_87 [ V_84 ] )
continue;
if ( F_65 ( & V_83 ,
& ( V_64 -> V_87 [ V_84 ] -> V_40 ) ) )
break;
}
if ( V_84 == V_64 -> V_85 . V_86 ) {
V_43 = - V_60 ;
goto V_58;
}
V_43 = F_42 ( & V_2 -> V_10 , V_84 , V_64 -> V_88 ) ;
if ( V_43 )
goto V_58;
V_2 -> V_8 . V_89 = 1 ;
F_2 ( V_79 , L_9 V_74 L_10 ,
V_81 , V_17 , F_23 ( V_2 ) ) ;
V_58:
F_66 ( V_62 ) ;
F_4 ( V_2 ) ;
return V_43 ;
}
int F_67 ( struct V_61 * V_62 , char * V_17 , char * V_81 )
{
struct V_82 V_83 ;
struct V_63 * V_64 ;
struct V_1 * V_2 ;
unsigned int V_84 ;
int V_43 = 0 ;
V_64 = & ( V_62 -> V_66 . V_64 ) ;
V_2 = F_62 ( V_64 -> V_78 , V_17 ) ;
if ( ! V_2 )
return - V_80 ;
F_63 ( & V_83 , V_81 ) ;
F_64 ( V_62 ) ;
for ( V_84 = 0 ; V_84 < V_64 -> V_85 . V_86 ; V_84 ++ ) {
if ( ! V_64 -> V_87 [ V_84 ] )
continue;
if ( F_65 ( & V_83 ,
& ( V_64 -> V_87 [ V_84 ] -> V_40 ) ) )
break;
}
if ( V_84 == V_64 -> V_85 . V_86 ) {
V_43 = - V_60 ;
goto V_58;
}
F_45 ( & V_2 -> V_10 , V_84 ) ;
V_2 -> V_8 . V_89 = 1 ;
F_2 ( V_79 , L_11 V_74 L_5 , V_81 ,
V_17 ) ;
V_58:
F_66 ( V_62 ) ;
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
goto V_58;
}
}
V_43 = - V_80 ;
V_58:
F_26 ( & F_25 ( V_2 ) ) ;
F_4 ( V_2 ) ;
return V_43 ;
}
struct V_1 * F_70 ( struct V_63 * V_64 , char * V_17 )
{
struct V_1 * V_2 ;
V_2 = NULL ;
if ( V_17 [ 0 ] != '\0' ) {
V_2 = F_62 ( V_64 -> V_78 , V_17 ) ;
if ( ! V_2 )
F_52 ( L_12 V_74 L_13 ,
V_17 ) ;
if ( V_2 && ( F_23 ( V_2 ) == 0 ) ) {
F_52 ( L_14 V_74 L_13 ,
V_17 ) ;
F_4 ( V_2 ) ;
V_2 = NULL ;
}
}
return V_2 ;
}
