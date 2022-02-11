static bool
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 ;
int V_7 = 0 ;
V_6 = (struct V_5 * ) V_3 ;
if ( V_4 < sizeof( * V_6 ) )
return false ;
while ( V_7 <= V_4 - sizeof( * V_6 ) &&
V_6 -> V_8 >= sizeof( * V_6 ) &&
V_6 -> V_8 <= V_4 - V_7 ) {
V_7 += V_6 -> V_8 ;
if ( ( V_6 -> type == V_9 ||
V_6 -> type == V_10 ) &&
V_6 -> V_11 == V_12 )
return true ;
V_6 = (struct V_5 * ) ( V_3 + V_7 ) ;
}
return false ;
}
static bool
F_2 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
unsigned long V_4 )
{
if ( ( V_4 % 2 ) != 0 )
return false ;
return true ;
}
static bool
F_3 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
unsigned long V_4 )
{
T_3 V_13 ;
int V_14 , V_15 = 0 , V_16 ;
V_16 = F_4 ( V_1 , V_17 ) ;
for ( V_14 = V_2 ; V_14 < V_2 + 4 ; V_14 ++ ) {
if ( V_1 [ V_14 ] > 127 ||
F_5 ( V_1 [ V_14 ] & 0xff ) < 0 )
return true ;
}
if ( V_16 > V_2 + 4 )
return false ;
if ( V_4 < 8 )
return false ;
V_13 = V_3 [ 4 ] | V_3 [ 5 ] << 8 ;
V_15 = F_6 ( ( T_1 * ) ( V_3 + 6 ) , V_4 - 6 ) + 2 ;
if ( ! V_15 )
return false ;
if ( ( V_15 + V_13 + 6 ) > V_4 )
return false ;
return F_1 ( V_1 , V_2 , V_3 + V_15 + 6 ,
V_13 ) ;
}
static bool
F_7 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
unsigned long V_4 )
{
if ( V_4 != 2 )
return false ;
return true ;
}
static bool
F_8 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
unsigned long V_4 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_4 ; V_14 ++ ) {
if ( V_3 [ V_14 ] > 127 )
return false ;
if ( V_3 [ V_14 ] == 0 )
return true ;
}
return false ;
}
static bool
F_9 ( const char * V_1 , T_4 V_4 , const char * V_18 ,
int * V_2 )
{
for ( * V_2 = 0 ; ; ( * V_2 ) ++ ) {
char V_19 = V_18 [ * V_2 ] ;
char V_20 = V_1 [ * V_2 ] ;
if ( V_19 == '*' )
return true ;
if ( ! V_19 && * V_2 == V_4 )
return true ;
if ( V_19 != V_20 )
return false ;
if ( ! V_19 )
return true ;
}
return true ;
}
bool
F_10 ( T_5 V_21 , T_1 * V_1 , T_2 * V_22 ,
unsigned long V_23 )
{
int V_14 ;
unsigned long V_24 ;
T_2 * V_25 ;
V_24 = F_11 ( V_1 ) ;
V_25 = F_12 ( V_24 + 1 , V_26 ) ;
if ( ! V_25 )
return false ;
F_13 ( V_25 , V_1 , V_24 ) ;
V_25 [ V_24 ] = '\0' ;
for ( V_14 = 0 ; V_27 [ V_14 ] . V_28 [ 0 ] != '\0' ; V_14 ++ ) {
const char * V_28 = V_27 [ V_14 ] . V_28 ;
int V_2 = 0 ;
if ( F_14 ( V_21 , V_27 [ V_14 ] . V_21 ) )
continue;
if ( F_9 ( V_25 , V_24 + 1 , V_28 , & V_2 ) ) {
if ( V_27 [ V_14 ] . V_29 == NULL )
break;
F_15 ( V_25 ) ;
return V_27 [ V_14 ] . V_29 ( V_1 , V_2 ,
V_22 , V_23 ) ;
}
}
F_15 ( V_25 ) ;
return true ;
}
bool
F_16 ( T_5 V_21 , const char * V_1 ,
T_4 V_4 )
{
int V_14 ;
bool V_30 = false ;
int V_2 = 0 ;
for ( V_14 = 0 ; V_27 [ V_14 ] . V_28 [ 0 ] != '\0' ; V_14 ++ ) {
if ( F_14 ( V_27 [ V_14 ] . V_21 , V_21 ) )
continue;
if ( F_9 ( V_1 , V_4 ,
V_27 [ V_14 ] . V_28 , & V_2 ) ) {
V_30 = true ;
break;
}
}
return V_30 ;
}
static T_6
F_17 ( T_7 V_31 , unsigned long V_32 )
{
const struct V_33 * V_34 = V_35 -> V_36 ;
if ( ! V_34 -> V_37 )
return V_38 ;
return V_34 -> V_37 ( V_31 , V_32 ) ;
}
static int F_18 ( T_6 V_39 )
{
int V_40 ;
switch ( V_39 ) {
case V_41 :
V_40 = 0 ;
break;
case V_42 :
V_40 = - V_43 ;
break;
case V_44 :
V_40 = - V_45 ;
break;
case V_46 :
V_40 = - V_47 ;
break;
case V_48 :
V_40 = - V_49 ;
break;
case V_50 :
V_40 = - V_51 ;
break;
case V_52 :
V_40 = - V_53 ;
break;
default:
V_40 = - V_43 ;
}
return V_40 ;
}
static bool F_19 ( T_1 * V_54 , T_5 * V_21 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 , * V_59 ;
unsigned long V_60 , V_61 ;
bool V_30 = false ;
V_60 = F_6 ( V_54 , 1024 ) ;
F_20 (entry, n, head, list) {
V_61 = F_6 ( V_58 -> V_62 . V_63 , 1024 ) ;
if ( V_60 == V_61 &&
! memcmp ( V_54 , & ( V_58 -> V_62 . V_63 ) ,
V_61 ) &&
! F_14 ( V_58 -> V_62 . V_64 ,
* V_21 ) ) {
V_30 = true ;
break;
}
}
return V_30 ;
}
static unsigned long F_21 ( T_1 * V_54 ,
unsigned long V_65 )
{
unsigned long V_4 ;
T_1 V_19 ;
for ( V_4 = 2 ; V_4 <= V_65 ; V_4 += sizeof( V_19 ) ) {
V_19 = V_54 [ ( V_4 / sizeof( V_19 ) ) - 1 ] ;
if ( ! V_19 )
break;
}
return F_22 ( V_4 , V_65 ) ;
}
static void F_23 ( T_1 * V_66 , T_5 * V_67 ,
unsigned long V_68 )
{
T_4 V_14 , V_69 = V_68 / sizeof( T_1 ) ;
char * V_70 ;
V_71 = false ;
V_70 = F_24 ( V_69 , V_26 ) ;
if ( ! V_70 )
return;
for ( V_14 = 0 ; V_14 < V_69 ; V_14 ++ )
V_70 [ V_14 ] = V_66 [ V_14 ] ;
F_25 ( V_72 L_1 ,
V_70 , V_67 ) ;
F_15 ( V_70 ) ;
}
int F_26 ( int (* F_27)( T_1 * , T_5 , unsigned long , void * ) ,
void * V_22 , bool V_73 , bool V_74 ,
struct V_55 * V_56 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
unsigned long V_65 = 1024 ;
T_1 * V_54 ;
T_6 V_39 ;
T_5 V_67 ;
int V_40 = 0 ;
V_54 = F_24 ( V_65 , V_26 ) ;
if ( ! V_54 ) {
F_25 ( V_75 L_2 ) ;
return - V_76 ;
}
F_28 ( & V_35 -> V_77 ) ;
do {
V_65 = 1024 ;
V_39 = V_36 -> V_78 ( & V_65 ,
V_54 ,
& V_67 ) ;
switch ( V_39 ) {
case V_41 :
if ( ! V_73 )
F_29 ( & V_35 -> V_77 ) ;
V_65 = F_21 ( V_54 ,
V_65 ) ;
if ( V_74 &&
F_19 ( V_54 , & V_67 , V_56 ) ) {
F_23 ( V_54 , & V_67 ,
V_65 ) ;
if ( ! V_73 )
F_28 ( & V_35 -> V_77 ) ;
V_39 = V_52 ;
break;
}
V_40 = F_27 ( V_54 , V_67 , V_65 , V_22 ) ;
if ( V_40 )
V_39 = V_52 ;
if ( ! V_73 )
F_28 ( & V_35 -> V_77 ) ;
break;
case V_52 :
break;
default:
F_25 ( V_72 L_3 ,
V_39 ) ;
V_39 = V_52 ;
break;
}
} while ( V_39 != V_52 );
F_29 ( & V_35 -> V_77 ) ;
F_15 ( V_54 ) ;
return V_40 ;
}
void F_30 ( struct V_57 * V_58 , struct V_55 * V_56 )
{
F_28 ( & V_35 -> V_77 ) ;
F_31 ( & V_58 -> V_79 , V_56 ) ;
F_29 ( & V_35 -> V_77 ) ;
}
void F_32 ( struct V_57 * V_58 )
{
F_28 ( & V_35 -> V_77 ) ;
F_33 ( & V_58 -> V_79 ) ;
F_29 ( & V_35 -> V_77 ) ;
}
static void F_34 ( struct V_57 * V_58 )
{
F_35 ( & V_35 -> V_77 ) ;
F_33 ( & V_58 -> V_79 ) ;
F_29 ( & V_35 -> V_77 ) ;
}
int F_36 ( struct V_57 * V_58 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
T_6 V_39 ;
F_35 ( & V_35 -> V_77 ) ;
V_39 = V_36 -> V_80 ( V_58 -> V_62 . V_63 ,
& V_58 -> V_62 . V_64 ,
0 , 0 , NULL ) ;
return F_18 ( V_39 ) ;
}
int F_37 ( struct V_57 * V_58 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
T_6 V_39 ;
F_28 ( & V_35 -> V_77 ) ;
V_39 = V_36 -> V_80 ( V_58 -> V_62 . V_63 ,
& V_58 -> V_62 . V_64 ,
0 , 0 , NULL ) ;
if ( ! ( V_39 == V_41 || V_39 == V_52 ) ) {
F_29 ( & V_35 -> V_77 ) ;
return F_18 ( V_39 ) ;
}
F_34 ( V_58 ) ;
return 0 ;
}
int F_38 ( struct V_57 * V_58 , T_7 V_31 ,
unsigned long V_32 , void * V_22 , struct V_55 * V_56 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
T_6 V_39 ;
T_1 * V_28 = V_58 -> V_62 . V_63 ;
T_5 V_21 = V_58 -> V_62 . V_64 ;
F_28 ( & V_35 -> V_77 ) ;
if ( V_56 && F_39 ( V_28 , V_21 , V_56 , false ) ) {
F_29 ( & V_35 -> V_77 ) ;
return - V_81 ;
}
V_39 = F_17 ( V_31 , V_32 + F_6 ( V_28 , 1024 ) ) ;
if ( V_39 == V_41 || V_39 == V_38 )
V_39 = V_36 -> V_80 ( V_28 , & V_21 ,
V_31 , V_32 , V_22 ) ;
F_29 ( & V_35 -> V_77 ) ;
return F_18 ( V_39 ) ;
}
static int
F_40 ( T_1 * V_28 , T_5 V_21 ,
T_7 V_31 , unsigned long V_32 , void * V_22 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
unsigned long V_82 ;
T_6 V_39 ;
if ( ! F_41 ( & V_35 -> V_77 , V_82 ) )
return - V_83 ;
V_39 = F_17 ( V_31 , V_32 + F_6 ( V_28 , 1024 ) ) ;
if ( V_39 != V_41 ) {
F_42 ( & V_35 -> V_77 , V_82 ) ;
return - V_45 ;
}
V_39 = V_36 -> V_84 ( V_28 , & V_21 , V_31 ,
V_32 , V_22 ) ;
F_42 ( & V_35 -> V_77 , V_82 ) ;
return F_18 ( V_39 ) ;
}
int F_43 ( T_1 * V_28 , T_5 V_21 , T_7 V_31 ,
bool V_85 , unsigned long V_32 , void * V_22 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
unsigned long V_82 ;
T_6 V_39 ;
if ( ! V_36 -> V_37 )
return - V_86 ;
if ( ! V_85 && V_36 -> V_84 )
return F_40 ( V_28 , V_21 , V_31 ,
V_32 , V_22 ) ;
if ( ! V_85 ) {
if ( ! F_41 ( & V_35 -> V_77 , V_82 ) )
return - V_83 ;
} else {
F_44 ( & V_35 -> V_77 , V_82 ) ;
}
V_39 = F_17 ( V_31 , V_32 + F_6 ( V_28 , 1024 ) ) ;
if ( V_39 != V_41 ) {
F_42 ( & V_35 -> V_77 , V_82 ) ;
return - V_45 ;
}
V_39 = V_36 -> V_80 ( V_28 , & V_21 , V_31 , V_32 , V_22 ) ;
F_42 ( & V_35 -> V_77 , V_82 ) ;
return F_18 ( V_39 ) ;
}
struct V_57 * F_39 ( T_1 * V_28 , T_5 V_87 ,
struct V_55 * V_56 , bool remove )
{
struct V_57 * V_58 , * V_59 ;
int V_60 , V_61 ;
bool V_30 = false ;
F_35 ( & V_35 -> V_77 ) ;
F_20 (entry, n, head, list) {
V_60 = F_6 ( V_28 , 1024 ) ;
V_61 = F_6 ( V_58 -> V_62 . V_63 , 1024 ) ;
if ( V_60 == V_61 &&
! memcmp ( V_28 , & ( V_58 -> V_62 . V_63 ) , V_60 ) &&
! F_14 ( V_87 , V_58 -> V_62 . V_64 ) ) {
V_30 = true ;
break;
}
}
if ( ! V_30 )
return NULL ;
if ( remove ) {
if ( V_58 -> V_88 ) {
V_58 -> V_89 = true ;
} else
F_33 ( & V_58 -> V_79 ) ;
}
return V_58 ;
}
int F_45 ( struct V_57 * V_58 , unsigned long * V_32 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
T_6 V_39 ;
* V_32 = 0 ;
F_28 ( & V_35 -> V_77 ) ;
V_39 = V_36 -> V_90 ( V_58 -> V_62 . V_63 ,
& V_58 -> V_62 . V_64 , NULL , V_32 , NULL ) ;
F_29 ( & V_35 -> V_77 ) ;
if ( V_39 != V_91 )
return F_18 ( V_39 ) ;
return 0 ;
}
int F_46 ( struct V_57 * V_58 , T_7 * V_31 ,
unsigned long * V_32 , void * V_22 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
T_6 V_39 ;
F_35 ( & V_35 -> V_77 ) ;
V_39 = V_36 -> V_90 ( V_58 -> V_62 . V_63 ,
& V_58 -> V_62 . V_64 ,
V_31 , V_32 , V_22 ) ;
return F_18 ( V_39 ) ;
}
int F_47 ( struct V_57 * V_58 , T_7 * V_31 ,
unsigned long * V_32 , void * V_22 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
T_6 V_39 ;
F_28 ( & V_35 -> V_77 ) ;
V_39 = V_36 -> V_90 ( V_58 -> V_62 . V_63 ,
& V_58 -> V_62 . V_64 ,
V_31 , V_32 , V_22 ) ;
F_29 ( & V_35 -> V_77 ) ;
return F_18 ( V_39 ) ;
}
int F_48 ( struct V_57 * V_58 , T_7 V_31 ,
unsigned long * V_32 , void * V_22 , bool * V_92 )
{
const struct V_33 * V_36 = V_35 -> V_36 ;
T_1 * V_28 = V_58 -> V_62 . V_63 ;
T_5 * V_21 = & V_58 -> V_62 . V_64 ;
T_6 V_39 ;
int V_40 ;
* V_92 = false ;
if ( F_10 ( * V_21 , V_28 , V_22 , * V_32 ) == false )
return - V_43 ;
F_28 ( & V_35 -> V_77 ) ;
V_39 = F_17 ( V_31 , * V_32 + F_6 ( V_28 , 1024 ) ) ;
if ( V_39 != V_41 ) {
if ( V_39 != V_38 ) {
V_40 = F_18 ( V_39 ) ;
goto V_93;
}
if ( * V_32 > 65536 ) {
V_40 = - V_45 ;
goto V_93;
}
}
V_39 = V_36 -> V_80 ( V_28 , V_21 , V_31 , * V_32 , V_22 ) ;
if ( V_39 != V_41 ) {
V_40 = F_18 ( V_39 ) ;
goto V_93;
}
* V_92 = true ;
* V_32 = 0 ;
V_39 = V_36 -> V_90 ( V_58 -> V_62 . V_63 ,
& V_58 -> V_62 . V_64 ,
NULL , V_32 , NULL ) ;
if ( V_39 == V_52 )
F_34 ( V_58 ) ;
else
F_29 ( & V_35 -> V_77 ) ;
if ( V_39 && V_39 != V_91 )
return F_18 ( V_39 ) ;
return 0 ;
V_93:
F_29 ( & V_35 -> V_77 ) ;
return V_40 ;
}
void F_49 ( void )
{
F_28 ( & V_35 -> V_77 ) ;
}
void F_50 ( void )
{
F_29 ( & V_35 -> V_77 ) ;
}
int F_51 ( int (* F_27)( struct V_57 * , void * ) ,
struct V_55 * V_56 , void * V_22 ,
struct V_57 * * V_94 )
{
struct V_57 * V_58 , * V_59 ;
int V_40 = 0 ;
if ( ! V_94 || ! * V_94 ) {
F_20 (entry, n, head, list) {
V_40 = F_27 ( V_58 , V_22 ) ;
if ( V_40 )
break;
}
if ( V_94 )
* V_94 = V_58 ;
return V_40 ;
}
F_52 ((*prev), n, head, list) {
V_40 = F_27 ( * V_94 , V_22 ) ;
if ( V_40 )
break;
}
return V_40 ;
}
int F_53 ( int (* F_27)( struct V_57 * , void * ) ,
struct V_55 * V_56 , void * V_22 )
{
int V_40 = 0 ;
F_49 () ;
V_40 = F_51 ( F_27 , V_56 , V_22 , NULL ) ;
F_50 () ;
return V_40 ;
}
struct V_95 * F_54 ( void )
{
if ( ! V_35 )
return NULL ;
return V_35 -> V_95 ;
}
void F_55 ( void )
{
if ( V_71 )
F_56 ( & V_96 ) ;
}
int F_57 ( struct V_97 * V_97 ,
const struct V_33 * V_36 ,
struct V_95 * V_95 )
{
F_58 ( & V_97 -> V_77 ) ;
V_97 -> V_36 = V_36 ;
V_97 -> V_95 = V_95 ;
V_35 = V_97 ;
return 0 ;
}
int F_59 ( struct V_97 * V_97 )
{
int V_98 ;
if ( ! V_35 ) {
F_25 ( V_75 L_4 ) ;
V_98 = - V_43 ;
goto V_93;
}
if ( V_35 != V_97 ) {
V_98 = - V_43 ;
goto V_93;
}
V_35 = NULL ;
V_98 = 0 ;
V_93:
return V_98 ;
}
