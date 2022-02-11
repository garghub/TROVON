static int
F_1 ( const char * V_1 , T_1 V_2 , struct V_3 * V_4 , T_2 V_5 )
{
const char * V_6 ;
int V_7 = F_2 ( V_1 , F_3 ( T_1 , V_2 , 0xffff ) , ( V_8 * ) V_4 , V_5 , & V_6 ) ;
if ( V_7 > 0 )
return ( int ) ( V_6 - V_1 ) ;
return 0 ;
}
static int F_4 ( const char * V_9 , T_1 V_2 , T_3 V_10 [] ,
int V_11 , char V_12 , char V_5 )
{
T_3 V_13 , V_14 ;
memset ( V_10 , 0 , sizeof( V_10 [ 0 ] ) * V_11 ) ;
for ( V_13 = 0 , V_14 = 0 ; V_14 < V_2 && V_13 < V_11 ; V_14 ++ , V_9 ++ ) {
if ( * V_9 >= '0' && * V_9 <= '9' ) {
V_10 [ V_13 ] = V_10 [ V_13 ] * 10 + * V_9 - '0' ;
}
else if ( * V_9 == V_12 )
V_13 ++ ;
else {
if ( ( * V_9 == V_5 || ! V_5 ) && V_13 == V_11 - 1 )
return V_14 ;
F_5 ( L_1 ,
V_14 , V_13 , * V_9 ) ;
return 0 ;
}
}
F_5 ( L_2 ,
V_11 , V_12 ) ;
return 0 ;
}
static int F_6 ( const char * V_9 , T_1 V_2 ,
struct V_15 * V_16 , char V_5 ,
unsigned int * V_17 )
{
int V_18 ;
T_3 V_10 [ 6 ] ;
V_18 = F_4 ( V_9 , V_2 , V_10 , 6 , ',' , V_5 ) ;
if ( V_18 == 0 )
return 0 ;
V_16 -> V_19 . V_20 = F_7 ( ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) |
( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ) ;
V_16 -> V_21 . V_22 . V_23 = F_8 ( ( V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ) ;
return V_18 ;
}
static int F_9 ( const char * V_9 , T_1 V_2 ,
struct V_15 * V_16 , char V_5 ,
unsigned int * V_17 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 ; V_13 ++ )
if ( isdigit ( V_9 [ V_13 ] ) )
break;
if ( V_13 == V_2 )
return 0 ;
* V_17 += V_13 ;
return F_6 ( V_9 + V_13 , V_2 - V_13 , V_16 , 0 , V_17 ) ;
}
static int F_10 ( const char * V_9 , int V_24 , T_1 V_2 , char V_25 ,
T_4 * V_23 )
{
T_5 V_26 = 0 ;
int V_13 ;
for ( V_13 = V_24 ; V_13 < V_2 ; V_13 ++ ) {
if ( V_9 [ V_13 ] == V_25 ) {
if ( V_26 == 0 )
break;
* V_23 = F_8 ( V_26 ) ;
F_5 ( L_3 , V_26 ) ;
return V_13 + 1 ;
}
else if ( V_9 [ V_13 ] >= '0' && V_9 [ V_13 ] <= '9' )
V_26 = V_26 * 10 + V_9 [ V_13 ] - '0' ;
else {
F_5 ( L_4 ) ;
break;
}
}
return 0 ;
}
static int F_11 ( const char * V_9 , T_1 V_2 , struct V_15 * V_16 ,
char V_5 , unsigned int * V_17 )
{
char V_25 ;
int V_18 ;
if ( V_2 <= 3 ) {
F_5 ( L_5 ) ;
return 0 ;
}
V_25 = V_9 [ 0 ] ;
if ( isdigit ( V_25 ) || V_25 < 33 || V_25 > 126 || V_9 [ 2 ] != V_25 ) {
F_5 ( L_6 ) ;
return 0 ;
}
if ( ( V_16 -> V_27 == V_28 && V_9 [ 1 ] != '1' ) ||
( V_16 -> V_27 == V_29 && V_9 [ 1 ] != '2' ) ) {
F_5 ( L_7 ) ;
return 0 ;
}
F_5 ( L_8 , V_25 , V_9 [ 1 ] , V_25 ) ;
if ( V_9 [ 1 ] == '1' ) {
T_3 V_10 [ 4 ] ;
V_18 = F_4 ( V_9 + 3 , V_2 - 3 , V_10 , 4 , '.' , V_25 ) ;
if ( V_18 != 0 )
V_16 -> V_19 . V_20 = F_7 ( ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 )
| ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ) ;
} else {
V_18 = F_1 ( V_9 + 3 , V_2 - 3 ,
(struct V_3 * ) V_16 -> V_19 . V_30 , V_25 ) ;
}
if ( V_18 == 0 )
return 0 ;
F_5 ( L_9 ) ;
return F_10 ( V_9 , 3 + V_18 + 1 , V_2 , V_25 , & V_16 -> V_21 . V_22 . V_23 ) ;
}
static int F_12 ( const char * V_9 , T_1 V_2 ,
struct V_15 * V_16 , char V_5 ,
unsigned int * V_17 )
{
char V_25 ;
if ( V_2 <= 3 ) return 0 ;
V_25 = V_9 [ 0 ] ;
if ( isdigit ( V_25 ) || V_25 < 33 || V_25 > 126 ||
V_9 [ 1 ] != V_25 || V_9 [ 2 ] != V_25 )
return 0 ;
return F_10 ( V_9 , 3 , V_2 , V_25 , & V_16 -> V_21 . V_22 . V_23 ) ;
}
static int F_13 ( const char * V_9 , T_1 V_2 ,
const char * V_31 , T_1 V_32 ,
char V_33 , char V_5 ,
unsigned int * V_34 ,
unsigned int * V_35 ,
struct V_15 * V_16 ,
int (* F_14)( const char * , T_1 ,
struct V_15 * , char ,
unsigned int * ) )
{
T_1 V_13 = V_32 ;
F_5 ( L_10 , V_31 , V_2 ) ;
if ( V_2 <= V_32 ) {
if ( strncasecmp ( V_9 , V_31 , V_2 ) == 0 )
return - 1 ;
else return 0 ;
}
if ( strncasecmp ( V_9 , V_31 , V_32 ) != 0 )
return 0 ;
F_5 ( L_11 ) ;
if ( V_33 ) {
for ( V_13 = V_32 ; V_9 [ V_13 ] != V_33 ; V_13 ++ )
if ( V_13 == V_2 - 1 ) return - 1 ;
V_13 ++ ;
}
F_5 ( L_12 , V_33 ) ;
* V_34 = V_13 ;
* V_35 = F_14 ( V_9 + V_13 , V_2 - V_13 , V_16 , V_5 , V_34 ) ;
if ( ! * V_35 )
return - 1 ;
F_5 ( L_13 ) ;
return 1 ;
}
static int F_15 ( T_6 V_36 , const struct V_37 * V_38 , int V_39 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_38 -> V_40 [ V_39 ] ; V_13 ++ )
if ( V_38 -> V_41 [ V_39 ] [ V_13 ] == V_36 )
return 1 ;
return 0 ;
}
static void F_16 ( struct V_42 * V_43 , T_6 V_44 ,
struct V_37 * V_38 , int V_39 ,
struct V_45 * V_46 )
{
unsigned int V_13 , V_47 ;
for ( V_13 = 0 ; V_13 < V_38 -> V_40 [ V_39 ] ; V_13 ++ ) {
if ( V_38 -> V_41 [ V_39 ] [ V_13 ] == V_44 )
return;
}
if ( V_38 -> V_40 [ V_39 ] < V_48 ) {
V_38 -> V_41 [ V_39 ] [ V_38 -> V_40 [ V_39 ] ++ ] = V_44 ;
} else {
if ( F_17 ( V_38 -> V_41 [ V_39 ] [ 0 ] , V_38 -> V_41 [ V_39 ] [ 1 ] ) )
V_47 = 0 ;
else
V_47 = 1 ;
if ( F_18 ( V_44 , V_38 -> V_41 [ V_39 ] [ V_47 ] ) )
V_38 -> V_41 [ V_39 ] [ V_47 ] = V_44 ;
}
}
static int F_19 ( struct V_45 * V_46 ,
unsigned int V_49 ,
struct V_42 * V_43 ,
enum V_50 V_51 )
{
unsigned int V_52 , V_53 ;
const struct V_54 * V_55 ;
struct V_54 V_56 ;
const char * V_57 ;
int V_7 ;
T_6 V_36 ;
int V_39 = F_20 ( V_51 ) ;
unsigned int V_58 ( V_59 ) , V_58 ( V_60 ) ;
struct V_37 * V_61 = F_21 ( V_43 ) ;
struct V_62 * exp ;
union V_63 * V_64 ;
struct V_15 V_16 = {} ;
unsigned int V_13 ;
int V_65 = 0 , V_66 ;
F_22 (nf_nat_ftp_hook) V_67 ;
if ( V_51 != V_68 &&
V_51 != V_69 ) {
F_5 ( L_14 , V_51 ) ;
return V_70 ;
}
V_55 = F_23 ( V_46 , V_49 , sizeof( V_56 ) , & V_56 ) ;
if ( V_55 == NULL )
return V_70 ;
V_52 = V_49 + V_55 -> V_71 * 4 ;
if ( V_52 >= V_46 -> V_14 ) {
F_5 ( L_15 , V_52 ,
V_46 -> V_14 ) ;
return V_70 ;
}
V_53 = V_46 -> V_14 - V_52 ;
F_24 ( & V_72 ) ;
V_57 = F_23 ( V_46 , V_52 , V_53 , V_73 ) ;
F_25 ( V_57 == NULL ) ;
V_66 = ( V_57 [ V_53 - 1 ] == '\n' ) ;
V_36 = F_26 ( V_55 -> V_36 ) + V_53 ;
if ( ! F_15 ( F_26 ( V_55 -> V_36 ) , V_61 , V_39 ) ) {
if ( F_27 ( V_61 -> V_74 [ V_39 ] & V_75 ) ) {
V_61 -> V_74 [ V_39 ] ^= V_75 ;
goto V_76;
}
F_5 ( L_16 ,
V_61 -> V_40 [ V_39 ] > 0 ? L_17 : L_18 ,
V_61 -> V_41 [ V_39 ] [ 0 ] ,
V_61 -> V_40 [ V_39 ] > 1 ? L_17 : L_18 ,
V_61 -> V_41 [ V_39 ] [ 1 ] ) ;
V_7 = V_70 ;
goto V_77;
}
V_76:
V_16 . V_27 = F_28 ( V_43 ) ;
memcpy ( V_16 . V_19 . V_78 , & V_43 -> V_79 [ V_39 ] . V_80 . V_1 . V_19 . V_78 ,
sizeof( V_16 . V_19 . V_78 ) ) ;
for ( V_13 = 0 ; V_13 < F_29 ( V_81 [ V_39 ] ) ; V_13 ++ ) {
V_65 = F_13 ( V_57 , V_53 ,
V_81 [ V_39 ] [ V_13 ] . V_31 ,
V_81 [ V_39 ] [ V_13 ] . V_32 ,
V_81 [ V_39 ] [ V_13 ] . V_33 ,
V_81 [ V_39 ] [ V_13 ] . V_5 ,
& V_60 , & V_59 ,
& V_16 ,
V_81 [ V_39 ] [ V_13 ] . F_14 ) ;
if ( V_65 ) break;
}
if ( V_65 == - 1 ) {
F_30 ( V_46 , V_43 , L_19 ,
V_81 [ V_39 ] [ V_13 ] . V_31 ) ;
V_7 = V_82 ;
goto V_83;
} else if ( V_65 == 0 ) {
V_7 = V_70 ;
goto V_77;
}
F_5 ( L_20 ,
V_59 , V_57 + V_60 ,
V_59 , F_26 ( V_55 -> V_36 ) + V_60 ) ;
exp = F_31 ( V_43 ) ;
if ( exp == NULL ) {
F_30 ( V_46 , V_43 , L_21 ) ;
V_7 = V_82 ;
goto V_83;
}
V_64 = & V_43 -> V_79 [ ! V_39 ] . V_80 . V_4 . V_19 ;
if ( ( V_16 . V_27 == F_28 ( V_43 ) ) &&
memcmp ( & V_16 . V_19 . V_78 , & V_43 -> V_79 [ V_39 ] . V_80 . V_1 . V_19 . V_78 ,
sizeof( V_16 . V_19 . V_78 ) ) ) {
if ( V_16 . V_27 == V_28 ) {
F_5 ( L_22 ,
& V_16 . V_19 . V_20 ,
& V_43 -> V_79 [ V_39 ] . V_80 . V_1 . V_19 . V_20 ) ;
} else {
F_5 ( L_23 ,
V_16 . V_19 . V_30 ,
V_43 -> V_79 [ V_39 ] . V_80 . V_1 . V_19 . V_30 ) ;
}
if ( ! V_84 ) {
V_7 = V_70 ;
goto V_85;
}
V_64 = & V_16 . V_19 ;
}
F_32 ( exp , V_86 , V_16 . V_27 ,
& V_43 -> V_79 [ ! V_39 ] . V_80 . V_1 . V_19 , V_64 ,
V_87 , NULL , & V_16 . V_21 . V_22 . V_23 ) ;
V_67 = F_33 ( V_88 ) ;
if ( V_67 && V_43 -> V_89 & V_90 )
V_7 = V_67 ( V_46 , V_51 , V_81 [ V_39 ] [ V_13 ] . V_91 ,
V_49 , V_60 , V_59 , exp ) ;
else {
if ( F_34 ( exp ) != 0 ) {
F_30 ( V_46 , V_43 , L_24 ) ;
V_7 = V_82 ;
} else
V_7 = V_70 ;
}
V_85:
F_35 ( exp ) ;
V_77:
if ( V_66 )
F_16 ( V_43 , V_36 , V_61 , V_39 , V_46 ) ;
V_83:
F_36 ( & V_72 ) ;
return V_7 ;
}
static int F_37 ( struct V_92 * V_93 , struct V_42 * V_43 )
{
struct V_37 * V_94 = F_21 ( V_43 ) ;
V_94 -> V_74 [ V_95 ] |= V_75 ;
V_94 -> V_74 [ V_96 ] |= V_75 ;
return 0 ;
}
static void F_38 ( void )
{
F_39 ( V_94 , V_97 * 2 ) ;
F_40 ( V_73 ) ;
}
static int T_7 F_41 ( void )
{
int V_13 , V_7 = 0 ;
F_42 ( sizeof( struct V_37 ) ) ;
V_73 = F_43 ( 65536 , V_98 ) ;
if ( ! V_73 )
return - V_99 ;
if ( V_97 == 0 )
V_100 [ V_97 ++ ] = V_101 ;
for ( V_13 = 0 ; V_13 < V_97 ; V_13 ++ ) {
F_44 ( & V_94 [ 2 * V_13 ] , V_102 , V_87 , L_25 ,
V_101 , V_100 [ V_13 ] , V_100 [ V_13 ] , & V_103 ,
0 , F_19 , F_37 , V_104 ) ;
F_44 ( & V_94 [ 2 * V_13 + 1 ] , V_105 , V_87 , L_25 ,
V_101 , V_100 [ V_13 ] , V_100 [ V_13 ] , & V_103 ,
0 , F_19 , F_37 , V_104 ) ;
}
V_7 = F_45 ( V_94 , V_97 * 2 ) ;
if ( V_7 < 0 ) {
F_46 ( L_26 ) ;
F_40 ( V_73 ) ;
return V_7 ;
}
return 0 ;
}
