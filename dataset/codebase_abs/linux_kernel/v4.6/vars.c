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
switch ( V_19 ) {
case '*' :
return true ;
case '\0' :
return ( * V_2 == V_4 ) ;
default:
if ( * V_2 < V_4 && V_19 == V_1 [ * V_2 ] )
continue;
return false ;
}
}
}
bool
F_10 ( T_5 V_20 , T_1 * V_1 , T_2 * V_21 ,
unsigned long V_22 )
{
int V_14 ;
unsigned long V_23 ;
T_2 * V_24 ;
V_23 = F_11 ( V_1 ) ;
V_24 = F_12 ( V_23 + 1 , V_25 ) ;
if ( ! V_24 )
return false ;
F_13 ( V_24 , V_1 , V_23 ) ;
V_24 [ V_23 ] = '\0' ;
for ( V_14 = 0 ; V_26 [ V_14 ] . V_27 [ 0 ] != '\0' ; V_14 ++ ) {
const char * V_27 = V_26 [ V_14 ] . V_27 ;
int V_2 = 0 ;
if ( F_14 ( V_20 , V_26 [ V_14 ] . V_20 ) )
continue;
if ( F_9 ( V_24 , V_23 + 1 , V_27 , & V_2 ) ) {
if ( V_26 [ V_14 ] . V_28 == NULL )
break;
F_15 ( V_24 ) ;
return V_26 [ V_14 ] . V_28 ( V_1 , V_2 ,
V_21 , V_22 ) ;
}
}
F_15 ( V_24 ) ;
return true ;
}
bool
F_16 ( T_5 V_20 , const char * V_1 ,
T_4 V_4 )
{
int V_14 ;
bool V_29 = false ;
int V_2 = 0 ;
for ( V_14 = 0 ; V_26 [ V_14 ] . V_27 [ 0 ] != '\0' ; V_14 ++ ) {
if ( F_14 ( V_26 [ V_14 ] . V_20 , V_20 ) )
continue;
if ( F_9 ( V_1 , V_4 ,
V_26 [ V_14 ] . V_27 , & V_2 ) ) {
V_29 = true ;
break;
}
}
return V_29 ;
}
static T_6
F_17 ( T_7 V_30 , unsigned long V_31 )
{
const struct V_32 * V_33 = V_34 -> V_35 ;
if ( ! V_33 -> V_36 )
return V_37 ;
return V_33 -> V_36 ( V_30 , V_31 , false ) ;
}
static T_6
F_18 ( T_7 V_30 , unsigned long V_31 )
{
const struct V_32 * V_33 = V_34 -> V_35 ;
if ( ! V_33 -> V_36 )
return V_37 ;
return V_33 -> V_36 ( V_30 , V_31 , true ) ;
}
static int F_19 ( T_6 V_38 )
{
int V_39 ;
switch ( V_38 ) {
case V_40 :
V_39 = 0 ;
break;
case V_41 :
V_39 = - V_42 ;
break;
case V_43 :
V_39 = - V_44 ;
break;
case V_45 :
V_39 = - V_46 ;
break;
case V_47 :
V_39 = - V_48 ;
break;
case V_49 :
V_39 = - V_50 ;
break;
case V_51 :
V_39 = - V_52 ;
break;
default:
V_39 = - V_42 ;
}
return V_39 ;
}
static bool F_20 ( T_1 * V_53 , T_5 * V_20 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 , * V_58 ;
unsigned long V_59 , V_60 ;
bool V_29 = false ;
V_59 = F_6 ( V_53 , 1024 ) ;
F_21 (entry, n, head, list) {
V_60 = F_6 ( V_57 -> V_61 . V_62 , 1024 ) ;
if ( V_59 == V_60 &&
! memcmp ( V_53 , & ( V_57 -> V_61 . V_62 ) ,
V_60 ) &&
! F_14 ( V_57 -> V_61 . V_63 ,
* V_20 ) ) {
V_29 = true ;
break;
}
}
return V_29 ;
}
static unsigned long F_22 ( T_1 * V_53 ,
unsigned long V_64 )
{
unsigned long V_4 ;
T_1 V_19 ;
for ( V_4 = 2 ; V_4 <= V_64 ; V_4 += sizeof( V_19 ) ) {
V_19 = V_53 [ ( V_4 / sizeof( V_19 ) ) - 1 ] ;
if ( ! V_19 )
break;
}
return F_23 ( V_4 , V_64 ) ;
}
static void F_24 ( T_1 * V_65 , T_5 * V_66 ,
unsigned long V_67 )
{
T_4 V_14 , V_68 = V_67 / sizeof( T_1 ) ;
char * V_69 ;
V_70 = false ;
V_69 = F_25 ( V_68 , V_25 ) ;
if ( ! V_69 )
return;
for ( V_14 = 0 ; V_14 < V_68 ; V_14 ++ )
V_69 [ V_14 ] = V_65 [ V_14 ] ;
F_26 ( V_71 L_1 ,
V_69 , V_66 ) ;
F_15 ( V_69 ) ;
}
int F_27 ( int (* F_28)( T_1 * , T_5 , unsigned long , void * ) ,
void * V_21 , bool V_72 , bool V_73 ,
struct V_54 * V_55 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
unsigned long V_64 = 1024 ;
T_1 * V_53 ;
T_6 V_38 ;
T_5 V_66 ;
int V_39 = 0 ;
V_53 = F_25 ( V_64 , V_25 ) ;
if ( ! V_53 ) {
F_26 ( V_74 L_2 ) ;
return - V_75 ;
}
F_29 ( & V_34 -> V_76 ) ;
do {
V_64 = 1024 ;
V_38 = V_35 -> V_77 ( & V_64 ,
V_53 ,
& V_66 ) ;
switch ( V_38 ) {
case V_40 :
if ( ! V_72 )
F_30 ( & V_34 -> V_76 ) ;
V_64 = F_22 ( V_53 ,
V_64 ) ;
if ( V_73 &&
F_20 ( V_53 , & V_66 , V_55 ) ) {
F_24 ( V_53 , & V_66 ,
V_64 ) ;
if ( ! V_72 )
F_29 ( & V_34 -> V_76 ) ;
V_38 = V_51 ;
break;
}
V_39 = F_28 ( V_53 , V_66 , V_64 , V_21 ) ;
if ( V_39 )
V_38 = V_51 ;
if ( ! V_72 )
F_29 ( & V_34 -> V_76 ) ;
break;
case V_51 :
break;
default:
F_26 ( V_71 L_3 ,
V_38 ) ;
V_38 = V_51 ;
break;
}
} while ( V_38 != V_51 );
F_30 ( & V_34 -> V_76 ) ;
F_15 ( V_53 ) ;
return V_39 ;
}
void F_31 ( struct V_56 * V_57 , struct V_54 * V_55 )
{
F_29 ( & V_34 -> V_76 ) ;
F_32 ( & V_57 -> V_78 , V_55 ) ;
F_30 ( & V_34 -> V_76 ) ;
}
void F_33 ( struct V_56 * V_57 )
{
F_29 ( & V_34 -> V_76 ) ;
F_34 ( & V_57 -> V_78 ) ;
F_30 ( & V_34 -> V_76 ) ;
}
static void F_35 ( struct V_56 * V_57 )
{
F_36 ( & V_34 -> V_76 ) ;
F_34 ( & V_57 -> V_78 ) ;
F_30 ( & V_34 -> V_76 ) ;
}
int F_37 ( struct V_56 * V_57 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_38 ;
F_36 ( & V_34 -> V_76 ) ;
V_38 = V_35 -> V_79 ( V_57 -> V_61 . V_62 ,
& V_57 -> V_61 . V_63 ,
0 , 0 , NULL ) ;
return F_19 ( V_38 ) ;
}
int F_38 ( struct V_56 * V_57 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_38 ;
F_29 ( & V_34 -> V_76 ) ;
V_38 = V_35 -> V_79 ( V_57 -> V_61 . V_62 ,
& V_57 -> V_61 . V_63 ,
0 , 0 , NULL ) ;
if ( ! ( V_38 == V_40 || V_38 == V_51 ) ) {
F_30 ( & V_34 -> V_76 ) ;
return F_19 ( V_38 ) ;
}
F_35 ( V_57 ) ;
return 0 ;
}
int F_39 ( struct V_56 * V_57 , T_7 V_30 ,
unsigned long V_31 , void * V_21 , struct V_54 * V_55 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_38 ;
T_1 * V_27 = V_57 -> V_61 . V_62 ;
T_5 V_20 = V_57 -> V_61 . V_63 ;
F_29 ( & V_34 -> V_76 ) ;
if ( V_55 && F_40 ( V_27 , V_20 , V_55 , false ) ) {
F_30 ( & V_34 -> V_76 ) ;
return - V_80 ;
}
V_38 = F_17 ( V_30 , V_31 + F_6 ( V_27 , 1024 ) ) ;
if ( V_38 == V_40 || V_38 == V_37 )
V_38 = V_35 -> V_79 ( V_27 , & V_20 ,
V_30 , V_31 , V_21 ) ;
F_30 ( & V_34 -> V_76 ) ;
return F_19 ( V_38 ) ;
}
static int
F_41 ( T_1 * V_27 , T_5 V_20 ,
T_7 V_30 , unsigned long V_31 , void * V_21 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
unsigned long V_81 ;
T_6 V_38 ;
if ( ! F_42 ( & V_34 -> V_76 , V_81 ) )
return - V_82 ;
V_38 = F_18 ( V_30 ,
V_31 + F_6 ( V_27 , 1024 ) ) ;
if ( V_38 != V_40 ) {
F_43 ( & V_34 -> V_76 , V_81 ) ;
return - V_44 ;
}
V_38 = V_35 -> V_83 ( V_27 , & V_20 , V_30 ,
V_31 , V_21 ) ;
F_43 ( & V_34 -> V_76 , V_81 ) ;
return F_19 ( V_38 ) ;
}
int F_44 ( T_1 * V_27 , T_5 V_20 , T_7 V_30 ,
bool V_84 , unsigned long V_31 , void * V_21 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
unsigned long V_81 ;
T_6 V_38 ;
if ( ! V_35 -> V_36 )
return - V_85 ;
if ( ! V_84 && V_35 -> V_83 )
return F_41 ( V_27 , V_20 , V_30 ,
V_31 , V_21 ) ;
if ( ! V_84 ) {
if ( ! F_42 ( & V_34 -> V_76 , V_81 ) )
return - V_82 ;
} else {
F_45 ( & V_34 -> V_76 , V_81 ) ;
}
V_38 = F_17 ( V_30 , V_31 + F_6 ( V_27 , 1024 ) ) ;
if ( V_38 != V_40 ) {
F_43 ( & V_34 -> V_76 , V_81 ) ;
return - V_44 ;
}
V_38 = V_35 -> V_79 ( V_27 , & V_20 , V_30 , V_31 , V_21 ) ;
F_43 ( & V_34 -> V_76 , V_81 ) ;
return F_19 ( V_38 ) ;
}
struct V_56 * F_40 ( T_1 * V_27 , T_5 V_86 ,
struct V_54 * V_55 , bool remove )
{
struct V_56 * V_57 , * V_58 ;
int V_59 , V_60 ;
bool V_29 = false ;
F_36 ( & V_34 -> V_76 ) ;
F_21 (entry, n, head, list) {
V_59 = F_6 ( V_27 , 1024 ) ;
V_60 = F_6 ( V_57 -> V_61 . V_62 , 1024 ) ;
if ( V_59 == V_60 &&
! memcmp ( V_27 , & ( V_57 -> V_61 . V_62 ) , V_59 ) &&
! F_14 ( V_86 , V_57 -> V_61 . V_63 ) ) {
V_29 = true ;
break;
}
}
if ( ! V_29 )
return NULL ;
if ( remove ) {
if ( V_57 -> V_87 ) {
V_57 -> V_88 = true ;
} else
F_34 ( & V_57 -> V_78 ) ;
}
return V_57 ;
}
int F_46 ( struct V_56 * V_57 , unsigned long * V_31 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_38 ;
* V_31 = 0 ;
F_29 ( & V_34 -> V_76 ) ;
V_38 = V_35 -> V_89 ( V_57 -> V_61 . V_62 ,
& V_57 -> V_61 . V_63 , NULL , V_31 , NULL ) ;
F_30 ( & V_34 -> V_76 ) ;
if ( V_38 != V_90 )
return F_19 ( V_38 ) ;
return 0 ;
}
int F_47 ( struct V_56 * V_57 , T_7 * V_30 ,
unsigned long * V_31 , void * V_21 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_38 ;
F_36 ( & V_34 -> V_76 ) ;
V_38 = V_35 -> V_89 ( V_57 -> V_61 . V_62 ,
& V_57 -> V_61 . V_63 ,
V_30 , V_31 , V_21 ) ;
return F_19 ( V_38 ) ;
}
int F_48 ( struct V_56 * V_57 , T_7 * V_30 ,
unsigned long * V_31 , void * V_21 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_38 ;
F_29 ( & V_34 -> V_76 ) ;
V_38 = V_35 -> V_89 ( V_57 -> V_61 . V_62 ,
& V_57 -> V_61 . V_63 ,
V_30 , V_31 , V_21 ) ;
F_30 ( & V_34 -> V_76 ) ;
return F_19 ( V_38 ) ;
}
int F_49 ( struct V_56 * V_57 , T_7 V_30 ,
unsigned long * V_31 , void * V_21 , bool * V_91 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_1 * V_27 = V_57 -> V_61 . V_62 ;
T_5 * V_20 = & V_57 -> V_61 . V_63 ;
T_6 V_38 ;
int V_39 ;
* V_91 = false ;
if ( F_10 ( * V_20 , V_27 , V_21 , * V_31 ) == false )
return - V_42 ;
F_29 ( & V_34 -> V_76 ) ;
V_38 = F_17 ( V_30 , * V_31 + F_6 ( V_27 , 1024 ) ) ;
if ( V_38 != V_40 ) {
if ( V_38 != V_37 ) {
V_39 = F_19 ( V_38 ) ;
goto V_92;
}
if ( * V_31 > 65536 ) {
V_39 = - V_44 ;
goto V_92;
}
}
V_38 = V_35 -> V_79 ( V_27 , V_20 , V_30 , * V_31 , V_21 ) ;
if ( V_38 != V_40 ) {
V_39 = F_19 ( V_38 ) ;
goto V_92;
}
* V_91 = true ;
* V_31 = 0 ;
V_38 = V_35 -> V_89 ( V_57 -> V_61 . V_62 ,
& V_57 -> V_61 . V_63 ,
NULL , V_31 , NULL ) ;
if ( V_38 == V_51 )
F_35 ( V_57 ) ;
else
F_30 ( & V_34 -> V_76 ) ;
if ( V_38 && V_38 != V_90 )
return F_19 ( V_38 ) ;
return 0 ;
V_92:
F_30 ( & V_34 -> V_76 ) ;
return V_39 ;
}
void F_50 ( void )
{
F_29 ( & V_34 -> V_76 ) ;
}
void F_51 ( void )
{
F_30 ( & V_34 -> V_76 ) ;
}
int F_52 ( int (* F_28)( struct V_56 * , void * ) ,
struct V_54 * V_55 , void * V_21 ,
struct V_56 * * V_93 )
{
struct V_56 * V_57 , * V_58 ;
int V_39 = 0 ;
if ( ! V_93 || ! * V_93 ) {
F_21 (entry, n, head, list) {
V_39 = F_28 ( V_57 , V_21 ) ;
if ( V_39 )
break;
}
if ( V_93 )
* V_93 = V_57 ;
return V_39 ;
}
F_53 ((*prev), n, head, list) {
V_39 = F_28 ( * V_93 , V_21 ) ;
if ( V_39 )
break;
}
return V_39 ;
}
int F_54 ( int (* F_28)( struct V_56 * , void * ) ,
struct V_54 * V_55 , void * V_21 )
{
int V_39 = 0 ;
F_50 () ;
V_39 = F_52 ( F_28 , V_55 , V_21 , NULL ) ;
F_51 () ;
return V_39 ;
}
struct V_94 * F_55 ( void )
{
if ( ! V_34 )
return NULL ;
return V_34 -> V_94 ;
}
void F_56 ( void )
{
if ( V_70 )
F_57 ( & V_95 ) ;
}
int F_58 ( struct V_96 * V_96 ,
const struct V_32 * V_35 ,
struct V_94 * V_94 )
{
F_59 ( & V_96 -> V_76 ) ;
V_96 -> V_35 = V_35 ;
V_96 -> V_94 = V_94 ;
V_34 = V_96 ;
return 0 ;
}
int F_60 ( struct V_96 * V_96 )
{
int V_97 ;
if ( ! V_34 ) {
F_26 ( V_74 L_4 ) ;
V_97 = - V_42 ;
goto V_92;
}
if ( V_34 != V_96 ) {
V_97 = - V_42 ;
goto V_92;
}
V_34 = NULL ;
V_97 = 0 ;
V_92:
return V_97 ;
}
