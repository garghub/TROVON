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
static bool F_19 ( T_1 * V_38 , T_5 * V_20 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 , * V_43 ;
unsigned long V_44 , V_45 ;
bool V_29 = false ;
V_44 = F_6 ( V_38 , 1024 ) ;
F_20 (entry, n, head, list) {
V_45 = F_6 ( V_42 -> V_46 . V_47 , 1024 ) ;
if ( V_44 == V_45 &&
! memcmp ( V_38 , & ( V_42 -> V_46 . V_47 ) ,
V_45 ) &&
! F_14 ( V_42 -> V_46 . V_48 ,
* V_20 ) ) {
V_29 = true ;
break;
}
}
return V_29 ;
}
static unsigned long F_21 ( T_1 * V_38 ,
unsigned long V_49 )
{
unsigned long V_4 ;
T_1 V_19 ;
for ( V_4 = 2 ; V_4 <= V_49 ; V_4 += sizeof( V_19 ) ) {
V_19 = V_38 [ ( V_4 / sizeof( V_19 ) ) - 1 ] ;
if ( ! V_19 )
break;
}
return F_22 ( V_4 , V_49 ) ;
}
static void F_23 ( T_1 * V_50 , T_5 * V_51 ,
unsigned long V_52 )
{
T_4 V_14 , V_53 = V_52 / sizeof( T_1 ) ;
char * V_54 ;
V_55 = false ;
V_54 = F_24 ( V_53 , V_25 ) ;
if ( ! V_54 )
return;
for ( V_14 = 0 ; V_14 < V_53 ; V_14 ++ )
V_54 [ V_14 ] = V_50 [ V_14 ] ;
F_25 ( V_56 L_1 ,
V_54 , V_51 ) ;
F_15 ( V_54 ) ;
}
int F_26 ( int (* F_27)( T_1 * , T_5 , unsigned long , void * ) ,
void * V_21 , bool V_57 , struct V_39 * V_40 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
unsigned long V_49 = 1024 ;
T_1 * V_38 ;
T_6 V_58 ;
T_5 V_51 ;
int V_59 = 0 ;
V_38 = F_24 ( V_49 , V_25 ) ;
if ( ! V_38 ) {
F_25 ( V_60 L_2 ) ;
return - V_61 ;
}
F_28 ( & V_34 -> V_62 ) ;
do {
V_49 = 1024 ;
V_58 = V_35 -> V_63 ( & V_49 ,
V_38 ,
& V_51 ) ;
switch ( V_58 ) {
case V_64 :
if ( V_57 )
F_29 ( & V_34 -> V_62 ) ;
V_49 = F_21 ( V_38 ,
V_49 ) ;
if ( V_57 &&
F_19 ( V_38 , & V_51 ,
V_40 ) ) {
F_23 ( V_38 , & V_51 ,
V_49 ) ;
V_58 = V_65 ;
} else {
V_59 = F_27 ( V_38 , V_51 ,
V_49 , V_21 ) ;
if ( V_59 )
V_58 = V_65 ;
}
if ( V_57 )
F_28 ( & V_34 -> V_62 ) ;
break;
case V_65 :
break;
default:
F_25 ( V_56 L_3 ,
V_58 ) ;
V_58 = V_65 ;
break;
}
} while ( V_58 != V_65 );
F_29 ( & V_34 -> V_62 ) ;
F_15 ( V_38 ) ;
return V_59 ;
}
void F_30 ( struct V_41 * V_42 , struct V_39 * V_40 )
{
F_28 ( & V_34 -> V_62 ) ;
F_31 ( & V_42 -> V_66 , V_40 ) ;
F_29 ( & V_34 -> V_62 ) ;
}
void F_32 ( struct V_41 * V_42 )
{
F_28 ( & V_34 -> V_62 ) ;
F_33 ( & V_42 -> V_66 ) ;
F_29 ( & V_34 -> V_62 ) ;
}
static void F_34 ( struct V_41 * V_42 )
{
F_35 ( & V_34 -> V_62 ) ;
F_33 ( & V_42 -> V_66 ) ;
F_29 ( & V_34 -> V_62 ) ;
}
int F_36 ( struct V_41 * V_42 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_58 ;
F_35 ( & V_34 -> V_62 ) ;
V_58 = V_35 -> V_67 ( V_42 -> V_46 . V_47 ,
& V_42 -> V_46 . V_48 ,
0 , 0 , NULL ) ;
return F_37 ( V_58 ) ;
}
int F_38 ( struct V_41 * V_42 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_58 ;
F_28 ( & V_34 -> V_62 ) ;
V_58 = V_35 -> V_67 ( V_42 -> V_46 . V_47 ,
& V_42 -> V_46 . V_48 ,
0 , 0 , NULL ) ;
if ( ! ( V_58 == V_64 || V_58 == V_65 ) ) {
F_29 ( & V_34 -> V_62 ) ;
return F_37 ( V_58 ) ;
}
F_34 ( V_42 ) ;
return 0 ;
}
int F_39 ( struct V_41 * V_42 , T_7 V_30 ,
unsigned long V_31 , void * V_21 , struct V_39 * V_40 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_58 ;
T_1 * V_27 = V_42 -> V_46 . V_47 ;
T_5 V_20 = V_42 -> V_46 . V_48 ;
F_28 ( & V_34 -> V_62 ) ;
if ( V_40 && F_40 ( V_27 , V_20 , V_40 , false ) ) {
F_29 ( & V_34 -> V_62 ) ;
return - V_68 ;
}
V_58 = F_17 ( V_30 , V_31 + F_6 ( V_27 , 1024 ) ) ;
if ( V_58 == V_64 || V_58 == V_37 )
V_58 = V_35 -> V_67 ( V_27 , & V_20 ,
V_30 , V_31 , V_21 ) ;
F_29 ( & V_34 -> V_62 ) ;
return F_37 ( V_58 ) ;
}
static int
F_41 ( T_1 * V_27 , T_5 V_20 ,
T_7 V_30 , unsigned long V_31 , void * V_21 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
unsigned long V_69 ;
T_6 V_58 ;
if ( ! F_42 ( & V_34 -> V_62 , V_69 ) )
return - V_70 ;
V_58 = F_18 ( V_30 ,
V_31 + F_6 ( V_27 , 1024 ) ) ;
if ( V_58 != V_64 ) {
F_43 ( & V_34 -> V_62 , V_69 ) ;
return - V_71 ;
}
V_58 = V_35 -> V_72 ( V_27 , & V_20 , V_30 ,
V_31 , V_21 ) ;
F_43 ( & V_34 -> V_62 , V_69 ) ;
return F_37 ( V_58 ) ;
}
int F_44 ( T_1 * V_27 , T_5 V_20 , T_7 V_30 ,
bool V_73 , unsigned long V_31 , void * V_21 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
unsigned long V_69 ;
T_6 V_58 ;
if ( ! V_35 -> V_36 )
return - V_74 ;
if ( ! V_73 && V_35 -> V_72 )
return F_41 ( V_27 , V_20 , V_30 ,
V_31 , V_21 ) ;
if ( ! V_73 ) {
if ( ! F_42 ( & V_34 -> V_62 , V_69 ) )
return - V_70 ;
} else {
F_45 ( & V_34 -> V_62 , V_69 ) ;
}
V_58 = F_17 ( V_30 , V_31 + F_6 ( V_27 , 1024 ) ) ;
if ( V_58 != V_64 ) {
F_43 ( & V_34 -> V_62 , V_69 ) ;
return - V_71 ;
}
V_58 = V_35 -> V_67 ( V_27 , & V_20 , V_30 , V_31 , V_21 ) ;
F_43 ( & V_34 -> V_62 , V_69 ) ;
return F_37 ( V_58 ) ;
}
struct V_41 * F_40 ( T_1 * V_27 , T_5 V_75 ,
struct V_39 * V_40 , bool remove )
{
struct V_41 * V_42 , * V_43 ;
int V_44 , V_45 ;
bool V_29 = false ;
F_35 ( & V_34 -> V_62 ) ;
F_20 (entry, n, head, list) {
V_44 = F_6 ( V_27 , 1024 ) ;
V_45 = F_6 ( V_42 -> V_46 . V_47 , 1024 ) ;
if ( V_44 == V_45 &&
! memcmp ( V_27 , & ( V_42 -> V_46 . V_47 ) , V_44 ) &&
! F_14 ( V_75 , V_42 -> V_46 . V_48 ) ) {
V_29 = true ;
break;
}
}
if ( ! V_29 )
return NULL ;
if ( remove ) {
if ( V_42 -> V_76 ) {
V_42 -> V_77 = true ;
} else
F_33 ( & V_42 -> V_66 ) ;
}
return V_42 ;
}
int F_46 ( struct V_41 * V_42 , unsigned long * V_31 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_58 ;
* V_31 = 0 ;
F_28 ( & V_34 -> V_62 ) ;
V_58 = V_35 -> V_78 ( V_42 -> V_46 . V_47 ,
& V_42 -> V_46 . V_48 , NULL , V_31 , NULL ) ;
F_29 ( & V_34 -> V_62 ) ;
if ( V_58 != V_79 )
return F_37 ( V_58 ) ;
return 0 ;
}
int F_47 ( struct V_41 * V_42 , T_7 * V_30 ,
unsigned long * V_31 , void * V_21 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_58 ;
F_35 ( & V_34 -> V_62 ) ;
V_58 = V_35 -> V_78 ( V_42 -> V_46 . V_47 ,
& V_42 -> V_46 . V_48 ,
V_30 , V_31 , V_21 ) ;
return F_37 ( V_58 ) ;
}
int F_48 ( struct V_41 * V_42 , T_7 * V_30 ,
unsigned long * V_31 , void * V_21 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_6 V_58 ;
F_28 ( & V_34 -> V_62 ) ;
V_58 = V_35 -> V_78 ( V_42 -> V_46 . V_47 ,
& V_42 -> V_46 . V_48 ,
V_30 , V_31 , V_21 ) ;
F_29 ( & V_34 -> V_62 ) ;
return F_37 ( V_58 ) ;
}
int F_49 ( struct V_41 * V_42 , T_7 V_30 ,
unsigned long * V_31 , void * V_21 , bool * V_80 )
{
const struct V_32 * V_35 = V_34 -> V_35 ;
T_1 * V_27 = V_42 -> V_46 . V_47 ;
T_5 * V_20 = & V_42 -> V_46 . V_48 ;
T_6 V_58 ;
int V_59 ;
* V_80 = false ;
if ( F_10 ( * V_20 , V_27 , V_21 , * V_31 ) == false )
return - V_81 ;
F_28 ( & V_34 -> V_62 ) ;
V_58 = F_17 ( V_30 , * V_31 + F_6 ( V_27 , 1024 ) ) ;
if ( V_58 != V_64 ) {
if ( V_58 != V_37 ) {
V_59 = F_37 ( V_58 ) ;
goto V_82;
}
if ( * V_31 > 65536 ) {
V_59 = - V_71 ;
goto V_82;
}
}
V_58 = V_35 -> V_67 ( V_27 , V_20 , V_30 , * V_31 , V_21 ) ;
if ( V_58 != V_64 ) {
V_59 = F_37 ( V_58 ) ;
goto V_82;
}
* V_80 = true ;
* V_31 = 0 ;
V_58 = V_35 -> V_78 ( V_42 -> V_46 . V_47 ,
& V_42 -> V_46 . V_48 ,
NULL , V_31 , NULL ) ;
if ( V_58 == V_65 )
F_34 ( V_42 ) ;
else
F_29 ( & V_34 -> V_62 ) ;
if ( V_58 && V_58 != V_79 )
return F_37 ( V_58 ) ;
return 0 ;
V_82:
F_29 ( & V_34 -> V_62 ) ;
return V_59 ;
}
void F_50 ( void )
{
F_28 ( & V_34 -> V_62 ) ;
}
void F_51 ( void )
{
F_29 ( & V_34 -> V_62 ) ;
}
int F_52 ( int (* F_27)( struct V_41 * , void * ) ,
struct V_39 * V_40 , void * V_21 ,
struct V_41 * * V_83 )
{
struct V_41 * V_42 , * V_43 ;
int V_59 = 0 ;
if ( ! V_83 || ! * V_83 ) {
F_20 (entry, n, head, list) {
V_59 = F_27 ( V_42 , V_21 ) ;
if ( V_59 )
break;
}
if ( V_83 )
* V_83 = V_42 ;
return V_59 ;
}
F_53 ((*prev), n, head, list) {
V_59 = F_27 ( * V_83 , V_21 ) ;
if ( V_59 )
break;
}
return V_59 ;
}
int F_54 ( int (* F_27)( struct V_41 * , void * ) ,
struct V_39 * V_40 , void * V_21 )
{
int V_59 = 0 ;
F_50 () ;
V_59 = F_52 ( F_27 , V_40 , V_21 , NULL ) ;
F_51 () ;
return V_59 ;
}
struct V_84 * F_55 ( void )
{
if ( ! V_34 )
return NULL ;
return V_34 -> V_84 ;
}
void F_56 ( void )
{
if ( V_55 )
F_57 ( & V_85 ) ;
}
int F_58 ( struct V_86 * V_86 ,
const struct V_32 * V_35 ,
struct V_84 * V_84 )
{
F_59 ( & V_86 -> V_62 ) ;
V_86 -> V_35 = V_35 ;
V_86 -> V_84 = V_84 ;
V_34 = V_86 ;
return 0 ;
}
int F_60 ( struct V_86 * V_86 )
{
int V_87 ;
if ( ! V_34 ) {
F_25 ( V_60 L_4 ) ;
V_87 = - V_81 ;
goto V_82;
}
if ( V_34 != V_86 ) {
V_87 = - V_81 ;
goto V_82;
}
V_34 = NULL ;
V_87 = 0 ;
V_82:
return V_87 ;
}
