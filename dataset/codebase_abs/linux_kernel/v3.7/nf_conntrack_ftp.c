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
if ( * V_9 == V_5 && V_13 == V_11 - 1 )
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
struct V_15 * V_16 , char V_5 )
{
int V_17 ;
T_3 V_10 [ 6 ] ;
V_17 = F_4 ( V_9 , V_2 , V_10 , 6 , ',' , V_5 ) ;
if ( V_17 == 0 )
return 0 ;
V_16 -> V_18 . V_19 = F_7 ( ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) |
( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ) ;
V_16 -> V_20 . V_21 . V_22 = F_8 ( ( V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ) ;
return V_17 ;
}
static int F_9 ( const char * V_9 , int V_23 , T_1 V_2 , char V_24 ,
T_4 * V_22 )
{
T_5 V_25 = 0 ;
int V_13 ;
for ( V_13 = V_23 ; V_13 < V_2 ; V_13 ++ ) {
if ( V_9 [ V_13 ] == V_24 ) {
if ( V_25 == 0 )
break;
* V_22 = F_8 ( V_25 ) ;
F_5 ( L_3 , V_25 ) ;
return V_13 + 1 ;
}
else if ( V_9 [ V_13 ] >= '0' && V_9 [ V_13 ] <= '9' )
V_25 = V_25 * 10 + V_9 [ V_13 ] - '0' ;
else {
F_5 ( L_4 ) ;
break;
}
}
return 0 ;
}
static int F_10 ( const char * V_9 , T_1 V_2 , struct V_15 * V_16 ,
char V_5 )
{
char V_24 ;
int V_17 ;
if ( V_2 <= 3 ) {
F_5 ( L_5 ) ;
return 0 ;
}
V_24 = V_9 [ 0 ] ;
if ( isdigit ( V_24 ) || V_24 < 33 || V_24 > 126 || V_9 [ 2 ] != V_24 ) {
F_5 ( L_6 ) ;
return 0 ;
}
if ( ( V_16 -> V_26 == V_27 && V_9 [ 1 ] != '1' ) ||
( V_16 -> V_26 == V_28 && V_9 [ 1 ] != '2' ) ) {
F_5 ( L_7 ) ;
return 0 ;
}
F_5 ( L_8 , V_24 , V_9 [ 1 ] , V_24 ) ;
if ( V_9 [ 1 ] == '1' ) {
T_3 V_10 [ 4 ] ;
V_17 = F_4 ( V_9 + 3 , V_2 - 3 , V_10 , 4 , '.' , V_24 ) ;
if ( V_17 != 0 )
V_16 -> V_18 . V_19 = F_7 ( ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 )
| ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ) ;
} else {
V_17 = F_1 ( V_9 + 3 , V_2 - 3 ,
(struct V_3 * ) V_16 -> V_18 . V_29 , V_24 ) ;
}
if ( V_17 == 0 )
return 0 ;
F_5 ( L_9 ) ;
return F_9 ( V_9 , 3 + V_17 + 1 , V_2 , V_24 , & V_16 -> V_20 . V_21 . V_22 ) ;
}
static int F_11 ( const char * V_9 , T_1 V_2 ,
struct V_15 * V_16 , char V_5 )
{
char V_24 ;
if ( V_2 <= 3 ) return 0 ;
V_24 = V_9 [ 0 ] ;
if ( isdigit ( V_24 ) || V_24 < 33 || V_24 > 126 ||
V_9 [ 1 ] != V_24 || V_9 [ 2 ] != V_24 )
return 0 ;
return F_9 ( V_9 , 3 , V_2 , V_24 , & V_16 -> V_20 . V_21 . V_22 ) ;
}
static int F_12 ( const char * V_9 , T_1 V_2 ,
const char * V_30 , T_1 V_31 ,
char V_32 , char V_5 ,
unsigned int * V_33 ,
unsigned int * V_34 ,
struct V_15 * V_16 ,
int (* F_13)( const char * , T_1 ,
struct V_15 * , char ) )
{
T_1 V_13 ;
F_5 ( L_10 , V_30 , V_2 ) ;
if ( V_2 == 0 )
return 0 ;
if ( V_2 <= V_31 ) {
if ( F_14 ( V_9 , V_30 , V_2 ) == 0 )
return - 1 ;
else return 0 ;
}
if ( F_14 ( V_9 , V_30 , V_31 ) != 0 ) {
#if 0
size_t i;
pr_debug("ftp: string mismatch\n");
for (i = 0; i < plen; i++) {
pr_debug("ftp:char %u `%c'(%u) vs `%c'(%u)\n",
i, data[i], data[i],
pattern[i], pattern[i]);
}
#endif
return 0 ;
}
F_5 ( L_11 ) ;
for ( V_13 = V_31 ; V_9 [ V_13 ] != V_32 ; V_13 ++ )
if ( V_13 == V_2 - 1 ) return - 1 ;
V_13 ++ ;
F_5 ( L_12 , V_32 ) ;
* V_33 = V_13 ;
* V_34 = F_13 ( V_9 + V_13 , V_2 - V_13 , V_16 , V_5 ) ;
if ( ! * V_34 )
return - 1 ;
F_5 ( L_13 ) ;
return 1 ;
}
static int F_15 ( T_6 V_35 , const struct V_36 * V_37 , int V_38 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_37 -> V_39 [ V_38 ] ; V_13 ++ )
if ( V_37 -> V_40 [ V_38 ] [ V_13 ] == V_35 )
return 1 ;
return 0 ;
}
static void F_16 ( struct V_41 * V_42 , T_6 V_43 ,
struct V_36 * V_37 , int V_38 ,
struct V_44 * V_45 )
{
unsigned int V_13 , V_46 ;
for ( V_13 = 0 ; V_13 < V_37 -> V_39 [ V_38 ] ; V_13 ++ ) {
if ( V_37 -> V_40 [ V_38 ] [ V_13 ] == V_43 )
return;
}
if ( V_37 -> V_39 [ V_38 ] < V_47 ) {
V_37 -> V_40 [ V_38 ] [ V_37 -> V_39 [ V_38 ] ++ ] = V_43 ;
} else {
if ( F_17 ( V_37 -> V_40 [ V_38 ] [ 0 ] , V_37 -> V_40 [ V_38 ] [ 1 ] ) )
V_46 = 0 ;
else
V_46 = 1 ;
if ( F_18 ( V_43 , V_37 -> V_40 [ V_38 ] [ V_46 ] ) )
V_37 -> V_40 [ V_38 ] [ V_46 ] = V_43 ;
}
}
static int F_19 ( struct V_44 * V_45 ,
unsigned int V_48 ,
struct V_41 * V_42 ,
enum V_49 V_50 )
{
unsigned int V_51 , V_52 ;
const struct V_53 * V_54 ;
struct V_53 V_55 ;
const char * V_56 ;
int V_7 ;
T_6 V_35 ;
int V_38 = F_20 ( V_50 ) ;
unsigned int V_57 ( V_58 ) , V_57 ( V_59 ) ;
struct V_36 * V_60 = F_21 ( V_42 ) ;
struct V_61 * exp ;
union V_62 * V_63 ;
struct V_15 V_16 = {} ;
unsigned int V_13 ;
int V_64 = 0 , V_65 ;
F_22 (nf_nat_ftp_hook) V_66 ;
if ( V_50 != V_67 &&
V_50 != V_68 ) {
F_5 ( L_14 , V_50 ) ;
return V_69 ;
}
V_54 = F_23 ( V_45 , V_48 , sizeof( V_55 ) , & V_55 ) ;
if ( V_54 == NULL )
return V_69 ;
V_51 = V_48 + V_54 -> V_70 * 4 ;
if ( V_51 >= V_45 -> V_14 ) {
F_5 ( L_15 , V_51 ,
V_45 -> V_14 ) ;
return V_69 ;
}
V_52 = V_45 -> V_14 - V_51 ;
F_24 ( & V_71 ) ;
V_56 = F_23 ( V_45 , V_51 , V_52 , V_72 ) ;
F_25 ( V_56 == NULL ) ;
V_65 = ( V_56 [ V_52 - 1 ] == '\n' ) ;
V_35 = F_26 ( V_54 -> V_35 ) + V_52 ;
if ( ! F_15 ( F_26 ( V_54 -> V_35 ) , V_60 , V_38 ) ) {
if ( F_27 ( V_60 -> V_73 [ V_38 ] & V_74 ) ) {
V_60 -> V_73 [ V_38 ] ^= V_74 ;
goto V_75;
}
F_5 ( L_16 ,
V_60 -> V_39 [ V_38 ] > 0 ? L_17 : L_18 ,
V_60 -> V_40 [ V_38 ] [ 0 ] ,
V_60 -> V_39 [ V_38 ] > 1 ? L_17 : L_18 ,
V_60 -> V_40 [ V_38 ] [ 1 ] ) ;
V_7 = V_69 ;
goto V_76;
}
V_75:
V_16 . V_26 = F_28 ( V_42 ) ;
memcpy ( V_16 . V_18 . V_77 , & V_42 -> V_78 [ V_38 ] . V_79 . V_1 . V_18 . V_77 ,
sizeof( V_16 . V_18 . V_77 ) ) ;
for ( V_13 = 0 ; V_13 < F_29 ( V_80 [ V_38 ] ) ; V_13 ++ ) {
V_64 = F_12 ( V_56 , V_52 ,
V_80 [ V_38 ] [ V_13 ] . V_30 ,
V_80 [ V_38 ] [ V_13 ] . V_31 ,
V_80 [ V_38 ] [ V_13 ] . V_32 ,
V_80 [ V_38 ] [ V_13 ] . V_5 ,
& V_59 , & V_58 ,
& V_16 ,
V_80 [ V_38 ] [ V_13 ] . F_13 ) ;
if ( V_64 ) break;
}
if ( V_64 == - 1 ) {
F_5 ( L_19 ,
V_80 [ V_38 ] [ V_13 ] . V_30 , F_26 ( V_54 -> V_35 ) , V_52 ) ;
V_7 = V_81 ;
goto V_82;
} else if ( V_64 == 0 ) {
V_7 = V_69 ;
goto V_76;
}
F_5 ( L_20 ,
V_58 , V_56 + V_59 ,
V_58 , F_26 ( V_54 -> V_35 ) + V_59 ) ;
exp = F_30 ( V_42 ) ;
if ( exp == NULL ) {
V_7 = V_81 ;
goto V_82;
}
V_63 = & V_42 -> V_78 [ ! V_38 ] . V_79 . V_4 . V_18 ;
if ( ( V_16 . V_26 == F_28 ( V_42 ) ) &&
memcmp ( & V_16 . V_18 . V_77 , & V_42 -> V_78 [ V_38 ] . V_79 . V_1 . V_18 . V_77 ,
sizeof( V_16 . V_18 . V_77 ) ) ) {
if ( V_16 . V_26 == V_27 ) {
F_5 ( L_21 ,
& V_16 . V_18 . V_19 ,
& V_42 -> V_78 [ V_38 ] . V_79 . V_1 . V_18 . V_19 ) ;
} else {
F_5 ( L_22 ,
V_16 . V_18 . V_29 ,
V_42 -> V_78 [ V_38 ] . V_79 . V_1 . V_18 . V_29 ) ;
}
if ( ! V_83 ) {
V_7 = V_69 ;
goto V_84;
}
V_63 = & V_16 . V_18 ;
}
F_31 ( exp , V_85 , V_16 . V_26 ,
& V_42 -> V_78 [ ! V_38 ] . V_79 . V_1 . V_18 , V_63 ,
V_86 , NULL , & V_16 . V_20 . V_21 . V_22 ) ;
V_66 = F_32 ( V_87 ) ;
if ( V_66 && V_42 -> V_88 & V_89 )
V_7 = V_66 ( V_45 , V_50 , V_80 [ V_38 ] [ V_13 ] . V_90 ,
V_48 , V_59 , V_58 , exp ) ;
else {
if ( F_33 ( exp ) != 0 )
V_7 = V_81 ;
else
V_7 = V_69 ;
}
V_84:
F_34 ( exp ) ;
V_76:
if ( V_65 )
F_16 ( V_42 , V_35 , V_60 , V_38 , V_45 ) ;
V_82:
F_35 ( & V_71 ) ;
return V_7 ;
}
static int F_36 ( struct V_91 * V_92 , struct V_41 * V_42 )
{
struct V_36 * V_93 = F_21 ( V_42 ) ;
V_93 -> V_73 [ V_94 ] |= V_74 ;
V_93 -> V_73 [ V_95 ] |= V_74 ;
return 0 ;
}
static void F_37 ( void )
{
int V_13 , V_96 ;
for ( V_13 = 0 ; V_13 < V_97 ; V_13 ++ ) {
for ( V_96 = 0 ; V_96 < 2 ; V_96 ++ ) {
if ( V_93 [ V_13 ] [ V_96 ] . V_98 == NULL )
continue;
F_5 ( L_23
L_24 ,
V_93 [ V_13 ] [ V_96 ] . V_79 . V_1 . V_26 , V_99 [ V_13 ] ) ;
F_38 ( & V_93 [ V_13 ] [ V_96 ] ) ;
}
}
F_39 ( V_72 ) ;
}
static int T_7 F_40 ( void )
{
int V_13 , V_96 = - 1 , V_7 = 0 ;
V_72 = F_41 ( 65536 , V_100 ) ;
if ( ! V_72 )
return - V_101 ;
if ( V_97 == 0 )
V_99 [ V_97 ++ ] = V_102 ;
for ( V_13 = 0 ; V_13 < V_97 ; V_13 ++ ) {
V_93 [ V_13 ] [ 0 ] . V_79 . V_1 . V_26 = V_27 ;
V_93 [ V_13 ] [ 1 ] . V_79 . V_1 . V_26 = V_28 ;
for ( V_96 = 0 ; V_96 < 2 ; V_96 ++ ) {
V_93 [ V_13 ] [ V_96 ] . V_103 = sizeof( struct V_36 ) ;
V_93 [ V_13 ] [ V_96 ] . V_79 . V_1 . V_20 . V_21 . V_22 = F_8 ( V_99 [ V_13 ] ) ;
V_93 [ V_13 ] [ V_96 ] . V_79 . V_4 . V_104 = V_86 ;
V_93 [ V_13 ] [ V_96 ] . V_105 = & V_106 ;
V_93 [ V_13 ] [ V_96 ] . V_98 = V_107 ;
V_93 [ V_13 ] [ V_96 ] . F_19 = F_19 ;
V_93 [ V_13 ] [ V_96 ] . V_108 = F_36 ;
if ( V_99 [ V_13 ] == V_102 )
sprintf ( V_93 [ V_13 ] [ V_96 ] . V_109 , L_25 ) ;
else
sprintf ( V_93 [ V_13 ] [ V_96 ] . V_109 , L_26 , V_99 [ V_13 ] ) ;
F_5 ( L_27
L_24 ,
V_93 [ V_13 ] [ V_96 ] . V_79 . V_1 . V_26 , V_99 [ V_13 ] ) ;
V_7 = F_42 ( & V_93 [ V_13 ] [ V_96 ] ) ;
if ( V_7 ) {
F_43 ( V_110 L_28
L_29 ,
V_93 [ V_13 ] [ V_96 ] . V_79 . V_1 . V_26 , V_99 [ V_13 ] ) ;
F_37 () ;
return V_7 ;
}
}
}
return 0 ;
}
