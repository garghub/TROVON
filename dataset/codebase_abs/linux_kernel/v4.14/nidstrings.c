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
unsigned int V_25 ;
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
struct V_8 * V_23 ;
if ( ! F_14 ( V_7 , '@' , & V_9 ) )
goto V_32;
if ( ! F_14 ( V_7 , '@' , & V_31 ) || V_7 -> V_11 )
goto V_32;
V_23 = F_9 ( & V_31 , V_20 ) ;
if ( ! V_23 )
goto V_32;
if ( F_5 ( & V_9 , V_23 ) )
goto V_32;
return 1 ;
V_32:
return 0 ;
}
static void
F_15 ( struct V_19 * V_33 )
{
while ( ! F_16 ( V_33 ) ) {
struct V_9 * V_34 ;
V_34 = F_17 ( V_33 -> V_35 , struct V_9 , V_14 ) ;
F_18 ( & V_34 -> V_16 ) ;
F_19 ( & V_34 -> V_14 ) ;
F_20 ( V_34 , sizeof( struct V_9 ) ) ;
}
}
void
F_21 ( struct V_19 * V_33 )
{
struct V_19 * V_36 , * V_35 ;
struct V_8 * V_23 ;
F_22 (pos, next, list) {
V_23 = F_17 ( V_36 , struct V_8 , V_30 ) ;
F_15 ( & V_23 -> V_15 ) ;
F_19 ( V_36 ) ;
F_20 ( V_23 , sizeof( struct V_8 ) ) ;
}
}
int
F_23 ( char * V_1 , int V_37 , struct V_19 * V_20 )
{
struct V_6 V_7 ;
struct V_6 V_38 ;
int V_39 ;
V_7 . V_11 = V_1 ;
V_7 . V_10 = V_37 ;
F_8 ( V_20 ) ;
while ( V_7 . V_11 ) {
V_39 = F_14 ( & V_7 , ' ' , & V_38 ) ;
if ( ! V_39 ) {
F_21 ( V_20 ) ;
return 0 ;
}
V_39 = F_13 ( & V_38 , V_20 ) ;
if ( ! V_39 ) {
F_21 ( V_20 ) ;
return 0 ;
}
}
return 1 ;
}
int F_24 ( T_1 V_40 , struct V_19 * V_20 )
{
struct V_8 * V_23 ;
struct V_9 * V_34 ;
F_12 (nr, nidlist, nr_link) {
if ( V_23 -> V_17 -> V_41 != F_25 ( F_26 ( V_40 ) ) )
continue;
if ( V_23 -> V_29 != F_27 ( F_26 ( V_40 ) ) )
continue;
if ( V_23 -> V_12 )
return 1 ;
F_12 (ar, &nr->nr_addrranges, ar_link)
if ( V_23 -> V_17 -> V_42 ( F_28 ( V_40 ) ,
& V_34 -> V_16 ) )
return 1 ;
}
return 0 ;
}
static int
F_29 ( char * V_43 , int V_44 , struct V_8 * V_23 )
{
struct V_21 * V_22 = V_23 -> V_17 ;
if ( ! V_23 -> V_29 )
return F_30 ( V_43 , V_44 , L_1 , V_22 -> V_27 ) ;
else
return F_30 ( V_43 , V_44 , L_2 ,
V_22 -> V_27 , V_23 -> V_29 ) ;
}
static int
F_31 ( char * V_43 , int V_44 , struct V_19 * V_45 ,
struct V_8 * V_23 )
{
int V_46 = 0 ;
struct V_9 * V_34 ;
struct V_21 * V_22 = V_23 -> V_17 ;
F_12 (ar, addrranges, ar_link) {
if ( V_46 )
V_46 += F_30 ( V_43 + V_46 , V_44 - V_46 , L_3 ) ;
V_46 += V_22 -> V_47 ( V_43 + V_46 , V_44 - V_46 ,
& V_34 -> V_16 ) ;
V_46 += F_29 ( V_43 + V_46 , V_44 - V_46 , V_23 ) ;
}
return V_46 ;
}
int F_32 ( char * V_43 , int V_44 , struct V_19 * V_20 )
{
int V_46 = 0 ;
struct V_8 * V_23 ;
if ( V_44 <= 0 )
return 0 ;
F_12 (nr, nidlist, nr_link) {
if ( V_46 )
V_46 += F_30 ( V_43 + V_46 , V_44 - V_46 , L_3 ) ;
if ( V_23 -> V_12 ) {
F_33 ( F_16 ( & V_23 -> V_15 ) ) ;
V_46 += F_30 ( V_43 + V_46 , V_44 - V_46 , L_4 ) ;
V_46 += F_29 ( V_43 + V_46 , V_44 - V_46 , V_23 ) ;
} else {
V_46 += F_31 ( V_43 + V_46 , V_44 - V_46 ,
& V_23 -> V_15 , V_23 ) ;
}
}
return V_46 ;
}
static void F_34 ( struct V_9 * V_34 , T_2 * V_48 ,
T_2 * V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
T_2 V_54 = 0 ;
unsigned int V_55 [ 4 ] = { 0 } ;
unsigned int V_56 [ 4 ] = { 0 } ;
int V_57 = 0 ;
F_12 (el, &ar->ar_numaddr_ranges, el_link) {
F_12 (re, &el->el_exprs, re_link) {
V_55 [ V_57 ] = V_53 -> V_58 ;
V_56 [ V_57 ] = V_53 -> V_59 ;
V_57 ++ ;
}
}
V_54 = ( ( V_55 [ 0 ] << 24 ) | ( V_55 [ 1 ] << 16 ) |
( V_55 [ 2 ] << 8 ) | V_55 [ 3 ] ) ;
if ( V_48 )
* V_48 = V_54 ;
V_54 = ( ( V_56 [ 0 ] << 24 ) | ( V_56 [ 1 ] << 16 ) |
( V_56 [ 2 ] << 8 ) | V_56 [ 3 ] ) ;
if ( V_49 )
* V_49 = V_54 ;
}
static void F_35 ( struct V_9 * V_34 , T_2 * V_48 ,
T_2 * V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
unsigned int V_60 = 0 ;
unsigned int V_61 = 0 ;
F_12 (el, &ar->ar_numaddr_ranges, el_link) {
F_12 (re, &el->el_exprs, re_link) {
if ( V_53 -> V_58 < V_60 || ! V_60 )
V_60 = V_53 -> V_58 ;
if ( V_53 -> V_59 > V_61 )
V_61 = V_53 -> V_59 ;
}
}
if ( V_48 )
* V_48 = V_60 ;
if ( V_49 )
* V_49 = V_61 ;
}
bool F_36 ( struct V_19 * V_20 )
{
struct V_8 * V_23 ;
struct V_21 * V_22 = NULL ;
char * V_62 = NULL ;
int V_25 = - 1 ;
F_12 (nr, nidlist, nr_link) {
V_22 = V_23 -> V_17 ;
if ( ! V_62 )
V_62 = V_22 -> V_27 ;
if ( V_25 == - 1 )
V_25 = V_23 -> V_29 ;
if ( strcmp ( V_62 , V_22 -> V_27 ) ||
V_25 != V_23 -> V_29 )
return false ;
}
if ( ! V_22 )
return false ;
if ( ! V_22 -> V_63 ( V_20 ) )
return false ;
return true ;
}
static bool F_37 ( struct V_19 * V_20 )
{
struct V_8 * V_23 ;
struct V_9 * V_34 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_64 = 0 ;
T_2 V_65 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
F_12 (nr, nidlist, nr_link) {
F_12 (ar, &nr->nr_addrranges, ar_link) {
F_35 ( V_34 , & V_66 ,
& V_67 ) ;
if ( V_65 &&
( V_66 - V_65 != 1 ) )
return false ;
V_65 = V_67 ;
F_12 (el, &ar->ar_numaddr_ranges,
el_link) {
F_12 (re, &el->el_exprs,
re_link) {
if ( V_53 -> V_68 > 1 )
return false ;
else if ( V_64 &&
V_53 -> V_59 - V_64 != 1 )
return false ;
V_64 = V_53 -> V_59 ;
}
}
}
}
return true ;
}
static bool F_38 ( struct V_19 * V_20 )
{
struct V_8 * V_23 ;
struct V_9 * V_34 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_69 ;
int V_64 = 255 ;
int V_70 = 0 ;
T_2 V_65 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
F_12 (nr, nidlist, nr_link) {
F_12 (ar, &nr->nr_addrranges, ar_link) {
V_64 = 255 ;
V_70 = 0 ;
F_34 ( V_34 , & V_66 ,
& V_67 ) ;
if ( V_65 &&
( V_66 - V_65 != 1 ) )
return false ;
V_65 = V_67 ;
F_12 (el, &ar->ar_numaddr_ranges,
el_link) {
V_69 = 0 ;
F_12 (re, &el->el_exprs,
re_link) {
V_69 ++ ;
if ( V_53 -> V_68 > 1 ||
( V_70 > 0 && V_64 != 255 ) ||
( V_70 > 0 && V_64 == 255 &&
V_53 -> V_58 > 0 ) )
return false ;
V_64 = V_53 -> V_59 ;
V_70 = V_53 -> V_59 - V_53 -> V_58 ;
}
}
}
}
return true ;
}
void F_39 ( struct V_19 * V_20 , char * V_48 ,
char * V_49 , T_3 V_71 )
{
struct V_8 * V_23 ;
struct V_21 * V_22 = NULL ;
int V_25 = - 1 ;
T_2 V_60 ;
T_2 V_61 ;
char * V_62 = NULL ;
char V_72 [ V_73 ] ;
char V_74 [ V_73 ] ;
F_12 (nr, nidlist, nr_link) {
V_22 = V_23 -> V_17 ;
V_62 = V_22 -> V_27 ;
if ( V_25 == - 1 )
V_25 = V_23 -> V_29 ;
V_22 -> V_75 ( V_20 , & V_60 , & V_61 ) ;
}
V_22 -> V_76 ( V_60 , V_72 , sizeof( V_72 ) ) ;
V_22 -> V_76 ( V_61 , V_74 , sizeof( V_74 ) ) ;
snprintf ( V_48 , V_71 , L_5 , V_72 , V_62 ,
V_25 ) ;
snprintf ( V_49 , V_71 , L_5 , V_74 , V_62 ,
V_25 ) ;
}
static void F_40 ( struct V_19 * V_20 , T_2 * V_48 ,
T_2 * V_49 )
{
struct V_8 * V_23 ;
struct V_9 * V_34 ;
unsigned int V_77 = 0 ;
unsigned int V_78 = 0 ;
unsigned int V_60 = 0 ;
unsigned int V_61 = 0 ;
F_12 (nr, nidlist, nr_link) {
F_12 (ar, &nr->nr_addrranges, ar_link) {
F_35 ( V_34 , & V_77 ,
& V_78 ) ;
if ( V_77 < V_60 || ! V_60 )
V_60 = V_77 ;
if ( V_78 > V_61 )
V_61 = V_77 ;
}
}
* V_49 = V_61 ;
* V_48 = V_60 ;
}
static void F_41 ( struct V_19 * V_20 , T_2 * V_48 ,
T_2 * V_49 )
{
struct V_8 * V_23 ;
struct V_9 * V_34 ;
T_2 V_79 = 0 ;
T_2 V_80 = 0 ;
T_2 V_81 = 0 ;
T_2 V_82 = 0 ;
F_12 (nr, nidlist, nr_link) {
F_12 (ar, &nr->nr_addrranges, ar_link) {
F_34 ( V_34 , & V_79 ,
& V_80 ) ;
if ( V_79 < V_81 || ! V_81 )
V_81 = V_79 ;
if ( V_80 > V_82 )
V_82 = V_80 ;
}
}
if ( V_48 )
* V_48 = V_81 ;
if ( V_49 )
* V_49 = V_82 ;
}
static int
F_42 ( const char * V_1 , int V_83 , T_2 * V_84 )
{
* V_84 = 0 ;
return 1 ;
}
static void
F_43 ( T_2 V_84 , char * V_1 , T_3 V_85 )
{
snprintf ( V_1 , V_85 , L_6 ,
( V_84 >> 24 ) & 0xff , ( V_84 >> 16 ) & 0xff ,
( V_84 >> 8 ) & 0xff , V_84 & 0xff ) ;
}
static int
F_44 ( const char * V_1 , int V_83 , T_2 * V_84 )
{
unsigned int V_86 ;
unsigned int V_87 ;
unsigned int V_88 ;
unsigned int V_89 ;
int V_90 = V_83 ;
if ( sscanf ( V_1 , L_7 , & V_86 , & V_87 , & V_88 , & V_89 , & V_90 ) >= 4 &&
V_90 == V_83 &&
! ( V_86 & ~ 0xff ) && ! ( V_87 & ~ 0xff ) &&
! ( V_88 & ~ 0xff ) && ! ( V_89 & ~ 0xff ) ) {
* V_84 = ( ( V_86 << 24 ) | ( V_87 << 16 ) | ( V_88 << 8 ) | V_89 ) ;
return 1 ;
}
return 0 ;
}
int
F_45 ( char * V_1 , int V_37 , struct V_19 * V_33 )
{
struct V_50 * V_51 ;
struct V_6 V_7 ;
int V_39 ;
int V_46 ;
V_7 . V_11 = V_1 ;
V_7 . V_10 = V_37 ;
V_46 = 0 ;
while ( V_7 . V_11 ) {
struct V_6 V_38 ;
if ( ! F_14 ( & V_7 , '.' , & V_38 ) ) {
V_39 = - V_91 ;
goto V_92;
}
V_39 = F_46 ( V_38 . V_11 , V_38 . V_10 , 0 , 255 , & V_51 ) ;
if ( V_39 )
goto V_92;
F_7 ( & V_51 -> V_93 , V_33 ) ;
V_46 ++ ;
}
if ( V_46 == 4 )
return 0 ;
V_39 = - V_91 ;
V_92:
F_18 ( V_33 ) ;
return V_39 ;
}
static int
F_47 ( char * V_43 , int V_44 , struct V_19 * V_33 )
{
int V_46 = 0 , V_94 = 0 ;
struct V_50 * V_51 ;
F_12 (el, list, el_link) {
F_33 ( V_94 ++ < 4 ) ;
if ( V_46 )
V_46 += F_30 ( V_43 + V_46 , V_44 - V_46 , L_8 ) ;
V_46 += F_48 ( V_43 + V_46 , V_44 - V_46 , V_51 ) ;
}
return V_46 ;
}
int
F_49 ( T_2 V_84 , struct V_19 * V_33 )
{
struct V_50 * V_51 ;
int V_46 = 0 ;
F_50 (el, list, el_link) {
if ( ! F_51 ( V_84 & 0xff , V_51 ) )
return 0 ;
V_84 >>= 8 ;
V_46 ++ ;
}
return V_46 == 4 ;
}
static void
F_52 ( T_2 V_84 , char * V_1 , T_3 V_85 )
{
snprintf ( V_1 , V_85 , L_9 , V_84 ) ;
}
static int
F_53 ( const char * V_1 , int V_83 , T_2 * V_84 )
{
int V_90 ;
V_90 = V_83 ;
if ( sscanf ( V_1 , L_10 , V_84 , & V_90 ) >= 1 && V_90 == V_83 )
return 1 ;
V_90 = V_83 ;
if ( sscanf ( V_1 , L_11 , V_84 , & V_90 ) >= 1 && V_90 == V_83 )
return 1 ;
V_90 = V_83 ;
if ( sscanf ( V_1 , L_12 , V_84 , & V_90 ) >= 1 && V_90 == V_83 )
return 1 ;
return 0 ;
}
static int
F_54 ( char * V_1 , int V_37 , struct V_19 * V_33 )
{
struct V_50 * V_51 ;
int V_39 ;
V_39 = F_46 ( V_1 , V_37 , 0 , V_28 , & V_51 ) ;
if ( ! V_39 )
F_7 ( & V_51 -> V_93 , V_33 ) ;
return V_39 ;
}
static int
F_55 ( char * V_43 , int V_44 , struct V_19 * V_33 )
{
int V_46 = 0 , V_94 = 0 ;
struct V_50 * V_51 ;
F_12 (el, list, el_link) {
F_33 ( V_94 ++ < 1 ) ;
V_46 += F_48 ( V_43 + V_46 , V_44 - V_46 , V_51 ) ;
}
return V_46 ;
}
static int
F_56 ( T_2 V_84 , struct V_19 * V_95 )
{
struct V_50 * V_51 ;
F_33 ( ! F_16 ( V_95 ) ) ;
V_51 = F_17 ( V_95 -> V_35 , struct V_50 , V_93 ) ;
return F_51 ( V_84 , V_51 ) ;
}
static struct V_21 *
F_57 ( T_2 V_96 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_97 ; V_46 ++ )
if ( V_96 == V_98 [ V_46 ] . V_41 )
return & V_98 [ V_46 ] ;
return NULL ;
}
static struct V_21 *
F_10 ( const char * V_99 )
{
struct V_21 * V_22 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_97 ; V_46 ++ ) {
V_22 = & V_98 [ V_46 ] ;
if ( ! strncmp ( V_99 , V_22 -> V_27 , strlen ( V_22 -> V_27 ) ) )
return V_22 ;
}
return NULL ;
}
static struct V_21 *
F_58 ( const char * V_99 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_97 ; V_46 ++ )
if ( ! strcmp ( V_98 [ V_46 ] . V_27 , V_99 ) )
return & V_98 [ V_46 ] ;
return NULL ;
}
int
F_59 ( T_2 V_96 )
{
return ! ! F_57 ( V_96 ) ;
}
char *
F_60 ( T_2 V_96 )
{
struct V_21 * V_22 = F_57 ( V_96 ) ;
return V_22 ? V_22 -> V_100 : NULL ;
}
int
F_61 ( const char * V_1 )
{
struct V_21 * V_22 = F_58 ( V_1 ) ;
if ( V_22 )
return V_22 -> V_41 ;
return - V_101 ;
}
char *
F_62 ( T_2 V_96 , char * V_102 , T_3 V_103 )
{
struct V_21 * V_22 ;
V_22 = F_57 ( V_96 ) ;
if ( ! V_22 )
snprintf ( V_102 , V_103 , L_13 , V_96 ) ;
else
snprintf ( V_102 , V_103 , L_14 , V_22 -> V_27 ) ;
return V_102 ;
}
char *
F_63 ( T_2 V_31 , char * V_102 , T_3 V_103 )
{
T_2 V_104 = F_27 ( V_31 ) ;
T_2 V_96 = F_25 ( V_31 ) ;
struct V_21 * V_22 ;
V_22 = F_57 ( V_96 ) ;
if ( ! V_22 )
snprintf ( V_102 , V_103 , L_15 , V_96 , V_104 ) ;
else if ( ! V_104 )
snprintf ( V_102 , V_103 , L_14 , V_22 -> V_27 ) ;
else
snprintf ( V_102 , V_103 , L_16 , V_22 -> V_27 , V_104 ) ;
return V_102 ;
}
char *
F_64 ( T_1 V_40 , char * V_102 , T_3 V_103 )
{
T_2 V_84 = F_28 ( V_40 ) ;
T_2 V_31 = F_26 ( V_40 ) ;
T_2 V_104 = F_27 ( V_31 ) ;
T_2 V_96 = F_25 ( V_31 ) ;
struct V_21 * V_22 ;
if ( V_40 == V_105 ) {
strncpy ( V_102 , L_17 , V_103 ) ;
V_102 [ V_103 - 1 ] = '\0' ;
return V_102 ;
}
V_22 = F_57 ( V_96 ) ;
if ( ! V_22 ) {
snprintf ( V_102 , V_103 , L_18 , V_84 , V_96 , V_104 ) ;
} else {
T_3 V_106 ;
V_22 -> V_76 ( V_84 , V_102 , V_103 ) ;
V_106 = strlen ( V_102 ) ;
if ( ! V_104 )
snprintf ( V_102 + V_106 , V_103 - V_106 , L_1 ,
V_22 -> V_27 ) ;
else
snprintf ( V_102 + V_106 , V_103 - V_106 , L_2 ,
V_22 -> V_27 , V_104 ) ;
}
return V_102 ;
}
static struct V_21 *
F_65 ( const char * V_1 , T_2 * V_31 )
{
struct V_21 * V_22 = NULL ;
int V_83 ;
unsigned int V_25 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_97 ; V_46 ++ ) {
V_22 = & V_98 [ V_46 ] ;
if ( ! strncmp ( V_1 , V_22 -> V_27 , strlen ( V_22 -> V_27 ) ) )
break;
}
if ( V_46 == V_97 )
return NULL ;
V_83 = strlen ( V_22 -> V_27 ) ;
if ( strlen ( V_1 ) == ( unsigned int ) V_83 ) {
V_25 = 0 ;
} else {
if ( V_22 -> V_41 == V_107 )
return NULL ;
V_1 += V_83 ;
V_46 = strlen ( V_1 ) ;
if ( sscanf ( V_1 , L_12 , & V_25 , & V_46 ) < 1 ||
V_46 != ( int ) strlen ( V_1 ) )
return NULL ;
}
* V_31 = F_66 ( V_22 -> V_41 , V_25 ) ;
return V_22 ;
}
T_2
F_67 ( const char * V_1 )
{
T_2 V_31 ;
if ( F_65 ( V_1 , & V_31 ) )
return V_31 ;
return F_26 ( V_105 ) ;
}
T_1
F_68 ( const char * V_1 )
{
const char * V_108 = strchr ( V_1 , '@' ) ;
struct V_21 * V_22 ;
T_2 V_31 ;
T_2 V_84 ;
if ( V_108 ) {
V_22 = F_65 ( V_108 + 1 , & V_31 ) ;
if ( ! V_22 )
return V_105 ;
} else {
V_108 = V_1 + strlen ( V_1 ) ;
V_31 = F_66 ( V_109 , 0 ) ;
V_22 = F_57 ( V_109 ) ;
F_33 ( V_22 ) ;
}
if ( ! V_22 -> V_110 ( V_1 , ( int ) ( V_108 - V_1 ) , & V_84 ) )
return V_105 ;
return F_69 ( V_31 , V_84 ) ;
}
char *
F_70 ( struct V_111 V_112 )
{
char * V_1 = F_1 () ;
if ( V_112 . V_113 == V_114 ) {
snprintf ( V_1 , V_26 ,
L_19 , F_71 ( V_112 . V_40 ) ) ;
return V_1 ;
}
snprintf ( V_1 , V_26 , L_20 ,
V_112 . V_113 & V_115 ? L_21 : L_22 ,
V_112 . V_113 & ~ V_115 , F_71 ( V_112 . V_40 ) ) ;
return V_1 ;
}
int
F_72 ( T_1 * V_116 , const char * V_1 )
{
if ( ! strcmp ( V_1 , L_4 ) ) {
* V_116 = V_105 ;
return 1 ;
}
* V_116 = F_68 ( V_1 ) ;
return * V_116 != V_105 ;
}
