char *
F_1 ( void )
{
char * V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = V_4 [ V_5 ++ ] ;
if ( V_5 == F_3 ( V_4 ) )
V_5 = 0 ;
F_4 ( & V_3 , V_2 ) ;
return V_1 ;
}
static int
F_5 ( const struct V_6 * V_7 , struct V_8 * V_8 )
{
struct V_9 * V_9 ;
if ( V_7 -> V_10 == 1 && V_7 -> V_11 [ 0 ] == '*' ) {
V_8 -> V_12 = 1 ;
return 0 ;
}
F_6 ( V_9 , sizeof( struct V_9 ) ) ;
if ( ! V_9 )
return - V_13 ;
F_7 ( & V_9 -> V_14 , & V_8 -> V_15 ) ;
F_8 ( & V_9 -> V_16 ) ;
return V_8 -> V_17 -> V_18 ( V_7 -> V_11 ,
V_7 -> V_10 ,
& V_9 -> V_16 ) ;
}
static struct V_8 *
F_9 ( const struct V_6 * V_7 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_8 * V_23 ;
int V_24 ;
unsigned V_25 ;
if ( V_7 -> V_10 >= V_26 )
return NULL ;
V_22 = F_10 ( V_7 -> V_11 ) ;
if ( ! V_22 )
return NULL ;
V_24 = V_7 -> V_10 - strlen ( V_22 -> V_27 ) ;
if ( ! V_24 )
V_25 = 0 ;
else {
if ( ! F_11 ( V_7 -> V_11 + strlen ( V_22 -> V_27 ) ,
V_24 , & V_25 , 0 , V_28 ) )
return NULL ;
}
F_12 (nr, nidlist, nr_link) {
if ( V_23 -> V_17 != V_22 )
continue;
if ( V_23 -> V_29 != V_25 )
continue;
return V_23 ;
}
F_6 ( V_23 , sizeof( struct V_8 ) ) ;
if ( ! V_23 )
return NULL ;
F_7 ( & V_23 -> V_30 , V_20 ) ;
F_8 ( & V_23 -> V_15 ) ;
V_23 -> V_17 = V_22 ;
V_23 -> V_12 = 0 ;
V_23 -> V_29 = V_25 ;
return V_23 ;
}
static int
F_13 ( struct V_6 * V_7 , struct V_19 * V_20 )
{
struct V_6 V_9 ;
struct V_6 V_31 ;
struct V_6 V_32 ;
struct V_8 * V_23 ;
V_32 = * V_7 ;
if ( ! F_14 ( V_7 , '@' , & V_9 ) )
goto V_33;
if ( ! F_14 ( V_7 , '@' , & V_31 ) || V_7 -> V_11 )
goto V_33;
V_23 = F_9 ( & V_31 , V_20 ) ;
if ( ! V_23 )
goto V_33;
if ( F_5 ( & V_9 , V_23 ) )
goto V_33;
return 1 ;
V_33:
return 0 ;
}
static void
F_15 ( struct V_19 * V_34 )
{
while ( ! F_16 ( V_34 ) ) {
struct V_9 * V_35 ;
V_35 = F_17 ( V_34 -> V_36 , struct V_9 , V_14 ) ;
F_18 ( & V_35 -> V_16 ) ;
F_19 ( & V_35 -> V_14 ) ;
F_20 ( V_35 , sizeof( struct V_9 ) ) ;
}
}
void
F_21 ( struct V_19 * V_34 )
{
struct V_19 * V_37 , * V_36 ;
struct V_8 * V_23 ;
F_22 (pos, next, list) {
V_23 = F_17 ( V_37 , struct V_8 , V_30 ) ;
F_15 ( & V_23 -> V_15 ) ;
F_19 ( V_37 ) ;
F_20 ( V_23 , sizeof( struct V_8 ) ) ;
}
}
int
F_23 ( char * V_1 , int V_38 , struct V_19 * V_20 )
{
struct V_6 V_7 ;
struct V_6 V_39 ;
int V_40 ;
V_7 . V_11 = V_1 ;
V_7 . V_10 = V_38 ;
F_8 ( V_20 ) ;
while ( V_7 . V_11 ) {
V_40 = F_14 ( & V_7 , ' ' , & V_39 ) ;
if ( ! V_40 ) {
F_21 ( V_20 ) ;
return 0 ;
}
V_40 = F_13 ( & V_39 , V_20 ) ;
if ( ! V_40 ) {
F_21 ( V_20 ) ;
return 0 ;
}
}
return 1 ;
}
int F_24 ( T_1 V_41 , struct V_19 * V_20 )
{
struct V_8 * V_23 ;
struct V_9 * V_35 ;
F_12 (nr, nidlist, nr_link) {
if ( V_23 -> V_17 -> V_42 != F_25 ( F_26 ( V_41 ) ) )
continue;
if ( V_23 -> V_29 != F_27 ( F_26 ( V_41 ) ) )
continue;
if ( V_23 -> V_12 )
return 1 ;
F_12 (ar, &nr->nr_addrranges, ar_link)
if ( V_23 -> V_17 -> V_43 ( F_28 ( V_41 ) ,
& V_35 -> V_16 ) )
return 1 ;
}
return 0 ;
}
static int
F_29 ( char * V_44 , int V_45 , struct V_8 * V_23 )
{
struct V_21 * V_22 = V_23 -> V_17 ;
if ( ! V_23 -> V_29 )
return F_30 ( V_44 , V_45 , L_1 , V_22 -> V_27 ) ;
else
return F_30 ( V_44 , V_45 , L_2 ,
V_22 -> V_27 , V_23 -> V_29 ) ;
}
static int
F_31 ( char * V_44 , int V_45 , struct V_19 * V_46 ,
struct V_8 * V_23 )
{
int V_47 = 0 ;
struct V_9 * V_35 ;
struct V_21 * V_22 = V_23 -> V_17 ;
F_12 (ar, addrranges, ar_link) {
if ( V_47 )
V_47 += F_30 ( V_44 + V_47 , V_45 - V_47 , L_3 ) ;
V_47 += V_22 -> V_48 ( V_44 + V_47 , V_45 - V_47 ,
& V_35 -> V_16 ) ;
V_47 += F_29 ( V_44 + V_47 , V_45 - V_47 , V_23 ) ;
}
return V_47 ;
}
int F_32 ( char * V_44 , int V_45 , struct V_19 * V_20 )
{
int V_47 = 0 ;
struct V_8 * V_23 ;
if ( V_45 <= 0 )
return 0 ;
F_12 (nr, nidlist, nr_link) {
if ( V_47 )
V_47 += F_30 ( V_44 + V_47 , V_45 - V_47 , L_3 ) ;
if ( V_23 -> V_12 ) {
F_33 ( F_16 ( & V_23 -> V_15 ) ) ;
V_47 += F_30 ( V_44 + V_47 , V_45 - V_47 , L_4 ) ;
V_47 += F_29 ( V_44 + V_47 , V_45 - V_47 , V_23 ) ;
} else {
V_47 += F_31 ( V_44 + V_47 , V_45 - V_47 ,
& V_23 -> V_15 , V_23 ) ;
}
}
return V_47 ;
}
static void F_34 ( struct V_9 * V_35 , T_2 * V_49 ,
T_2 * V_50 )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_2 V_55 = 0 ;
unsigned int V_56 [ 4 ] = { 0 } ;
unsigned int V_57 [ 4 ] = { 0 } ;
int V_58 = 0 ;
F_12 (el, &ar->ar_numaddr_ranges, el_link) {
F_12 (re, &el->el_exprs, re_link) {
V_56 [ V_58 ] = V_54 -> V_59 ;
V_57 [ V_58 ] = V_54 -> V_60 ;
V_58 ++ ;
}
}
V_55 = ( ( V_56 [ 0 ] << 24 ) | ( V_56 [ 1 ] << 16 ) |
( V_56 [ 2 ] << 8 ) | V_56 [ 3 ] ) ;
if ( V_49 )
* V_49 = V_55 ;
V_55 = ( ( V_57 [ 0 ] << 24 ) | ( V_57 [ 1 ] << 16 ) |
( V_57 [ 2 ] << 8 ) | V_57 [ 3 ] ) ;
if ( V_50 )
* V_50 = V_55 ;
}
static void F_35 ( struct V_9 * V_35 , T_2 * V_49 ,
T_2 * V_50 )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
unsigned int V_61 = 0 ;
unsigned int V_62 = 0 ;
F_12 (el, &ar->ar_numaddr_ranges, el_link) {
F_12 (re, &el->el_exprs, re_link) {
if ( V_54 -> V_59 < V_61 || ! V_61 )
V_61 = V_54 -> V_59 ;
if ( V_54 -> V_60 > V_62 )
V_62 = V_54 -> V_60 ;
}
}
if ( V_49 )
* V_49 = V_61 ;
if ( V_50 )
* V_50 = V_62 ;
}
bool F_36 ( struct V_19 * V_20 )
{
struct V_8 * V_23 ;
struct V_21 * V_22 = NULL ;
char * V_63 = NULL ;
int V_25 = - 1 ;
F_12 (nr, nidlist, nr_link) {
V_22 = V_23 -> V_17 ;
if ( ! V_63 )
V_63 = V_22 -> V_27 ;
if ( V_25 == - 1 )
V_25 = V_23 -> V_29 ;
if ( strcmp ( V_63 , V_22 -> V_27 ) ||
V_25 != V_23 -> V_29 )
return false ;
}
if ( ! V_22 )
return false ;
if ( ! V_22 -> V_64 ( V_20 ) )
return false ;
return true ;
}
static bool F_37 ( struct V_19 * V_20 )
{
struct V_8 * V_23 ;
struct V_9 * V_35 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
int V_65 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
T_2 V_68 = 0 ;
F_12 (nr, nidlist, nr_link) {
F_12 (ar, &nr->nr_addrranges, ar_link) {
F_35 ( V_35 , & V_67 ,
& V_68 ) ;
if ( V_66 &&
( V_67 - V_66 != 1 ) )
return false ;
V_66 = V_68 ;
F_12 (el, &ar->ar_numaddr_ranges,
el_link) {
F_12 (re, &el->el_exprs,
re_link) {
if ( V_54 -> V_69 > 1 )
return false ;
else if ( V_65 &&
V_54 -> V_60 - V_65 != 1 )
return false ;
V_65 = V_54 -> V_60 ;
}
}
}
}
return true ;
}
static bool F_38 ( struct V_19 * V_20 )
{
struct V_8 * V_23 ;
struct V_9 * V_35 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
int V_70 ;
int V_65 = 255 ;
int V_71 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
T_2 V_68 = 0 ;
F_12 (nr, nidlist, nr_link) {
F_12 (ar, &nr->nr_addrranges, ar_link) {
V_65 = 255 ;
V_71 = 0 ;
F_34 ( V_35 , & V_67 ,
& V_68 ) ;
if ( V_66 &&
( V_67 - V_66 != 1 ) )
return false ;
V_66 = V_68 ;
F_12 (el, &ar->ar_numaddr_ranges,
el_link) {
V_70 = 0 ;
F_12 (re, &el->el_exprs,
re_link) {
V_70 ++ ;
if ( V_54 -> V_69 > 1 ||
( V_71 > 0 && V_65 != 255 ) ||
( V_71 > 0 && V_65 == 255 &&
V_54 -> V_59 > 0 ) )
return false ;
V_65 = V_54 -> V_60 ;
V_71 = V_54 -> V_60 - V_54 -> V_59 ;
}
}
}
}
return true ;
}
void F_39 ( struct V_19 * V_20 , char * V_49 ,
char * V_50 , T_3 V_72 )
{
struct V_8 * V_23 ;
struct V_21 * V_22 = NULL ;
int V_25 = - 1 ;
T_2 V_61 ;
T_2 V_62 ;
char * V_63 = NULL ;
char V_73 [ V_74 ] ;
char V_75 [ V_74 ] ;
F_12 (nr, nidlist, nr_link) {
V_22 = V_23 -> V_17 ;
V_63 = V_22 -> V_27 ;
if ( V_25 == - 1 )
V_25 = V_23 -> V_29 ;
V_22 -> V_76 ( V_20 , & V_61 , & V_62 ) ;
}
V_22 -> V_77 ( V_61 , V_73 , sizeof( V_73 ) ) ;
V_22 -> V_77 ( V_62 , V_75 , sizeof( V_75 ) ) ;
snprintf ( V_49 , V_72 , L_5 , V_73 , V_63 ,
V_25 ) ;
snprintf ( V_50 , V_72 , L_5 , V_75 , V_63 ,
V_25 ) ;
}
static void F_40 ( struct V_19 * V_20 , T_2 * V_49 ,
T_2 * V_50 )
{
struct V_8 * V_23 ;
struct V_9 * V_35 ;
unsigned int V_78 = 0 ;
unsigned int V_79 = 0 ;
unsigned int V_61 = 0 ;
unsigned int V_62 = 0 ;
F_12 (nr, nidlist, nr_link) {
F_12 (ar, &nr->nr_addrranges, ar_link) {
F_35 ( V_35 , & V_78 ,
& V_79 ) ;
if ( V_78 < V_61 || ! V_61 )
V_61 = V_78 ;
if ( V_79 > V_62 )
V_62 = V_78 ;
}
}
* V_50 = V_62 ;
* V_49 = V_61 ;
}
static void F_41 ( struct V_19 * V_20 , T_2 * V_49 ,
T_2 * V_50 )
{
struct V_8 * V_23 ;
struct V_9 * V_35 ;
T_2 V_80 = 0 ;
T_2 V_81 = 0 ;
T_2 V_82 = 0 ;
T_2 V_83 = 0 ;
F_12 (nr, nidlist, nr_link) {
F_12 (ar, &nr->nr_addrranges, ar_link) {
F_34 ( V_35 , & V_80 ,
& V_81 ) ;
if ( V_80 < V_82 || ! V_82 )
V_82 = V_80 ;
if ( V_81 > V_83 )
V_83 = V_81 ;
}
}
if ( V_49 )
* V_49 = V_82 ;
if ( V_50 )
* V_50 = V_83 ;
}
static int
F_42 ( const char * V_1 , int V_84 , T_2 * V_85 )
{
* V_85 = 0 ;
return 1 ;
}
static void
F_43 ( T_2 V_85 , char * V_1 , T_3 V_86 )
{
snprintf ( V_1 , V_86 , L_6 ,
( V_85 >> 24 ) & 0xff , ( V_85 >> 16 ) & 0xff ,
( V_85 >> 8 ) & 0xff , V_85 & 0xff ) ;
}
static int
F_44 ( const char * V_1 , int V_84 , T_2 * V_85 )
{
unsigned int V_87 ;
unsigned int V_88 ;
unsigned int V_89 ;
unsigned int V_90 ;
int V_91 = V_84 ;
if ( sscanf ( V_1 , L_7 , & V_87 , & V_88 , & V_89 , & V_90 , & V_91 ) >= 4 &&
V_91 == V_84 &&
! ( V_87 & ~ 0xff ) && ! ( V_88 & ~ 0xff ) &&
! ( V_89 & ~ 0xff ) && ! ( V_90 & ~ 0xff ) ) {
* V_85 = ( ( V_87 << 24 ) | ( V_88 << 16 ) | ( V_89 << 8 ) | V_90 ) ;
return 1 ;
}
return 0 ;
}
int
F_45 ( char * V_1 , int V_38 , struct V_19 * V_34 )
{
struct V_51 * V_52 ;
struct V_6 V_7 ;
int V_40 ;
int V_47 ;
V_7 . V_11 = V_1 ;
V_7 . V_10 = V_38 ;
V_47 = 0 ;
while ( V_7 . V_11 ) {
struct V_6 V_39 ;
if ( ! F_14 ( & V_7 , '.' , & V_39 ) ) {
V_40 = - V_92 ;
goto V_93;
}
V_40 = F_46 ( V_39 . V_11 , V_39 . V_10 , 0 , 255 , & V_52 ) ;
if ( V_40 )
goto V_93;
F_7 ( & V_52 -> V_94 , V_34 ) ;
V_47 ++ ;
}
if ( V_47 == 4 )
return 0 ;
V_40 = - V_92 ;
V_93:
F_18 ( V_34 ) ;
return V_40 ;
}
static int
F_47 ( char * V_44 , int V_45 , struct V_19 * V_34 )
{
int V_47 = 0 , V_95 = 0 ;
struct V_51 * V_52 ;
F_12 (el, list, el_link) {
F_33 ( V_95 ++ < 4 ) ;
if ( V_47 )
V_47 += F_30 ( V_44 + V_47 , V_45 - V_47 , L_8 ) ;
V_47 += F_48 ( V_44 + V_47 , V_45 - V_47 , V_52 ) ;
}
return V_47 ;
}
int
F_49 ( T_2 V_85 , struct V_19 * V_34 )
{
struct V_51 * V_52 ;
int V_47 = 0 ;
F_50 (el, list, el_link) {
if ( ! F_51 ( V_85 & 0xff , V_52 ) )
return 0 ;
V_85 >>= 8 ;
V_47 ++ ;
}
return V_47 == 4 ;
}
static void
F_52 ( T_2 V_85 , char * V_1 , T_3 V_86 )
{
snprintf ( V_1 , V_86 , L_9 , V_85 ) ;
}
static int
F_53 ( const char * V_1 , int V_84 , T_2 * V_85 )
{
int V_91 ;
V_91 = V_84 ;
if ( sscanf ( V_1 , L_10 , V_85 , & V_91 ) >= 1 && V_91 == V_84 )
return 1 ;
V_91 = V_84 ;
if ( sscanf ( V_1 , L_11 , V_85 , & V_91 ) >= 1 && V_91 == V_84 )
return 1 ;
V_91 = V_84 ;
if ( sscanf ( V_1 , L_12 , V_85 , & V_91 ) >= 1 && V_91 == V_84 )
return 1 ;
return 0 ;
}
static int
F_54 ( char * V_1 , int V_38 , struct V_19 * V_34 )
{
struct V_51 * V_52 ;
int V_40 ;
V_40 = F_46 ( V_1 , V_38 , 0 , V_28 , & V_52 ) ;
if ( ! V_40 )
F_7 ( & V_52 -> V_94 , V_34 ) ;
return V_40 ;
}
static int
F_55 ( char * V_44 , int V_45 , struct V_19 * V_34 )
{
int V_47 = 0 , V_95 = 0 ;
struct V_51 * V_52 ;
F_12 (el, list, el_link) {
F_33 ( V_95 ++ < 1 ) ;
V_47 += F_48 ( V_44 + V_47 , V_45 - V_47 , V_52 ) ;
}
return V_47 ;
}
static int
F_56 ( T_2 V_85 , struct V_19 * V_96 )
{
struct V_51 * V_52 ;
F_33 ( ! F_16 ( V_96 ) ) ;
V_52 = F_17 ( V_96 -> V_36 , struct V_51 , V_94 ) ;
return F_51 ( V_85 , V_52 ) ;
}
static struct V_21 *
F_57 ( T_2 V_97 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_98 ; V_47 ++ )
if ( V_97 == V_99 [ V_47 ] . V_42 )
return & V_99 [ V_47 ] ;
return NULL ;
}
static struct V_21 *
F_10 ( const char * V_100 )
{
struct V_21 * V_22 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_98 ; V_47 ++ ) {
V_22 = & V_99 [ V_47 ] ;
if ( ! strncmp ( V_100 , V_22 -> V_27 , strlen ( V_22 -> V_27 ) ) )
return V_22 ;
}
return NULL ;
}
static struct V_21 *
F_58 ( const char * V_100 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_98 ; V_47 ++ )
if ( ! strcmp ( V_99 [ V_47 ] . V_27 , V_100 ) )
return & V_99 [ V_47 ] ;
return NULL ;
}
int
F_59 ( T_2 V_97 )
{
return ! ! F_57 ( V_97 ) ;
}
char *
F_60 ( T_2 V_97 )
{
struct V_21 * V_22 = F_57 ( V_97 ) ;
return V_22 ? V_22 -> V_101 : NULL ;
}
int
F_61 ( const char * V_1 )
{
struct V_21 * V_22 = F_58 ( V_1 ) ;
if ( V_22 )
return V_22 -> V_42 ;
return - V_102 ;
}
char *
F_62 ( T_2 V_97 , char * V_103 , T_3 V_104 )
{
struct V_21 * V_22 ;
V_22 = F_57 ( V_97 ) ;
if ( ! V_22 )
snprintf ( V_103 , V_104 , L_13 , V_97 ) ;
else
snprintf ( V_103 , V_104 , L_14 , V_22 -> V_27 ) ;
return V_103 ;
}
char *
F_63 ( T_2 V_31 , char * V_103 , T_3 V_104 )
{
T_2 V_105 = F_27 ( V_31 ) ;
T_2 V_97 = F_25 ( V_31 ) ;
struct V_21 * V_22 ;
V_22 = F_57 ( V_97 ) ;
if ( ! V_22 )
snprintf ( V_103 , V_104 , L_15 , V_97 , V_105 ) ;
else if ( ! V_105 )
snprintf ( V_103 , V_104 , L_14 , V_22 -> V_27 ) ;
else
snprintf ( V_103 , V_104 , L_16 , V_22 -> V_27 , V_105 ) ;
return V_103 ;
}
char *
F_64 ( T_1 V_41 , char * V_103 , T_3 V_104 )
{
T_2 V_85 = F_28 ( V_41 ) ;
T_2 V_31 = F_26 ( V_41 ) ;
T_2 V_105 = F_27 ( V_31 ) ;
T_2 V_97 = F_25 ( V_31 ) ;
struct V_21 * V_22 ;
if ( V_41 == V_106 ) {
strncpy ( V_103 , L_17 , V_104 ) ;
V_103 [ V_104 - 1 ] = '\0' ;
return V_103 ;
}
V_22 = F_57 ( V_97 ) ;
if ( ! V_22 ) {
snprintf ( V_103 , V_104 , L_18 , V_85 , V_97 , V_105 ) ;
} else {
T_3 V_107 ;
V_22 -> V_77 ( V_85 , V_103 , V_104 ) ;
V_107 = strlen ( V_103 ) ;
if ( ! V_105 )
snprintf ( V_103 + V_107 , V_104 - V_107 , L_1 ,
V_22 -> V_27 ) ;
else
snprintf ( V_103 + V_107 , V_104 - V_107 , L_2 ,
V_22 -> V_27 , V_105 ) ;
}
return V_103 ;
}
static struct V_21 *
F_65 ( const char * V_1 , T_2 * V_31 )
{
struct V_21 * V_108 ( V_22 ) ;
int V_84 ;
unsigned int V_25 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_98 ; V_47 ++ ) {
V_22 = & V_99 [ V_47 ] ;
if ( ! strncmp ( V_1 , V_22 -> V_27 , strlen ( V_22 -> V_27 ) ) )
break;
}
if ( V_47 == V_98 )
return NULL ;
V_84 = strlen ( V_22 -> V_27 ) ;
if ( strlen ( V_1 ) == ( unsigned int ) V_84 ) {
V_25 = 0 ;
} else {
if ( V_22 -> V_42 == V_109 )
return NULL ;
V_1 += V_84 ;
V_47 = strlen ( V_1 ) ;
if ( sscanf ( V_1 , L_12 , & V_25 , & V_47 ) < 1 ||
V_47 != ( int ) strlen ( V_1 ) )
return NULL ;
}
* V_31 = F_66 ( V_22 -> V_42 , V_25 ) ;
return V_22 ;
}
T_2
F_67 ( const char * V_1 )
{
T_2 V_31 ;
if ( F_65 ( V_1 , & V_31 ) )
return V_31 ;
return F_26 ( V_106 ) ;
}
T_1
F_68 ( const char * V_1 )
{
const char * V_110 = strchr ( V_1 , '@' ) ;
struct V_21 * V_22 ;
T_2 V_31 ;
T_2 V_85 ;
if ( V_110 ) {
V_22 = F_65 ( V_110 + 1 , & V_31 ) ;
if ( ! V_22 )
return V_106 ;
} else {
V_110 = V_1 + strlen ( V_1 ) ;
V_31 = F_66 ( V_111 , 0 ) ;
V_22 = F_57 ( V_111 ) ;
F_33 ( V_22 ) ;
}
if ( ! V_22 -> V_112 ( V_1 , ( int ) ( V_110 - V_1 ) , & V_85 ) )
return V_106 ;
return F_69 ( V_31 , V_85 ) ;
}
char *
F_70 ( T_4 V_113 )
{
char * V_1 = F_1 () ;
if ( V_113 . V_114 == V_115 ) {
snprintf ( V_1 , V_26 ,
L_19 , F_71 ( V_113 . V_41 ) ) ;
return V_1 ;
}
snprintf ( V_1 , V_26 , L_20 ,
V_113 . V_114 & V_116 ? L_21 : L_22 ,
V_113 . V_114 & ~ V_116 , F_71 ( V_113 . V_41 ) ) ;
return V_1 ;
}
int
F_72 ( T_1 * V_117 , const char * V_1 )
{
if ( ! strcmp ( V_1 , L_4 ) ) {
* V_117 = V_106 ;
return 1 ;
}
* V_117 = F_68 ( V_1 ) ;
return * V_117 != V_106 ;
}
