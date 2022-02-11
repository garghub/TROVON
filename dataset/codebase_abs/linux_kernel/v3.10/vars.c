static bool
F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
struct V_6 * V_7 ;
int V_8 = 0 ;
V_7 = (struct V_6 * ) V_4 ;
if ( V_5 < sizeof( * V_7 ) )
return false ;
while ( V_8 <= V_5 - sizeof( * V_7 ) &&
V_7 -> V_9 >= sizeof( * V_7 ) &&
V_7 -> V_9 <= V_5 - V_8 ) {
V_8 += V_7 -> V_9 ;
if ( ( V_7 -> type == V_10 ||
V_7 -> type == V_11 ) &&
V_7 -> V_12 == V_13 )
return true ;
V_7 = (struct V_6 * ) ( V_4 + V_8 ) ;
}
return false ;
}
static bool
F_2 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
if ( ( V_5 % 2 ) != 0 )
return false ;
return true ;
}
static bool
F_3 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
T_2 V_14 ;
int V_15 , V_16 = 0 , V_17 ;
V_17 = F_4 ( V_2 -> V_18 , sizeof( V_2 -> V_18 ) ) ;
for ( V_15 = V_3 ; V_15 < V_3 + 4 ; V_15 ++ ) {
if ( V_2 -> V_18 [ V_15 ] > 127 ||
F_5 ( V_2 -> V_18 [ V_15 ] & 0xff ) < 0 )
return true ;
}
if ( V_17 > V_3 + 4 )
return false ;
if ( V_5 < 8 )
return false ;
V_14 = V_4 [ 4 ] | V_4 [ 5 ] << 8 ;
V_16 = F_6 ( ( V_19 * ) ( V_4 + 6 ) , V_5 - 6 ) + 2 ;
if ( ! V_16 )
return false ;
if ( ( V_16 + V_14 + 6 ) > V_5 )
return false ;
return F_1 ( V_2 , V_3 , V_4 + V_16 + 6 ,
V_14 ) ;
}
static bool
F_7 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
if ( V_5 != 2 )
return false ;
return true ;
}
static bool
F_8 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
unsigned long V_5 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ ) {
if ( V_4 [ V_15 ] > 127 )
return false ;
if ( V_4 [ V_15 ] == 0 )
return true ;
}
return false ;
}
bool
F_9 ( struct V_1 * V_2 , T_1 * V_20 , unsigned long V_5 )
{
int V_15 ;
T_2 * V_21 = V_2 -> V_18 ;
for ( V_15 = 0 ; V_22 [ V_15 ] . V_23 != NULL ; V_15 ++ ) {
const char * V_24 = V_22 [ V_15 ] . V_24 ;
int V_3 ;
for ( V_3 = 0 ; ; V_3 ++ ) {
char V_25 = V_24 [ V_3 ] ;
T_2 V_26 = V_21 [ V_3 ] ;
if ( V_26 > 127 )
return true ;
if ( V_25 == '*' )
return V_22 [ V_15 ] . V_23 ( V_2 ,
V_3 , V_20 , V_5 ) ;
if ( V_25 != V_26 )
break;
if ( ! V_25 )
return V_22 [ V_15 ] . V_23 ( V_2 ,
V_3 , V_20 , V_5 ) ;
}
}
return true ;
}
static T_3
F_10 ( T_4 V_27 , unsigned long V_28 )
{
const struct V_29 * V_30 = V_31 -> V_32 ;
if ( ! V_30 -> V_33 )
return V_34 ;
return V_30 -> V_33 ( V_27 , V_28 ) ;
}
static int F_11 ( T_3 V_35 )
{
int V_36 ;
switch ( V_35 ) {
case V_37 :
V_36 = 0 ;
break;
case V_38 :
V_36 = - V_39 ;
break;
case V_40 :
V_36 = - V_41 ;
break;
case V_42 :
V_36 = - V_43 ;
break;
case V_44 :
V_36 = - V_45 ;
break;
case V_46 :
V_36 = - V_47 ;
break;
case V_48 :
V_36 = - V_49 ;
break;
default:
V_36 = - V_39 ;
}
return V_36 ;
}
static bool F_12 ( V_19 * V_50 , T_5 * V_51 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 , * V_56 ;
unsigned long V_57 , V_58 ;
bool V_59 = false ;
V_57 = F_6 ( V_50 , 1024 ) ;
F_13 (entry, n, head, list) {
V_58 = F_6 ( V_55 -> V_2 . V_18 , 1024 ) ;
if ( V_57 == V_58 &&
! memcmp ( V_50 , & ( V_55 -> V_2 . V_18 ) ,
V_58 ) &&
! F_14 ( V_55 -> V_2 . V_60 ,
* V_51 ) ) {
V_59 = true ;
break;
}
}
return V_59 ;
}
static unsigned long F_15 ( V_19 * V_50 ,
unsigned long V_61 )
{
unsigned long V_5 ;
V_19 V_25 ;
for ( V_5 = 2 ; V_5 <= V_61 ; V_5 += sizeof( V_25 ) ) {
V_25 = V_50 [ ( V_5 / sizeof( V_25 ) ) - 1 ] ;
if ( ! V_25 )
break;
}
return F_16 ( V_5 , V_61 ) ;
}
static void F_17 ( V_19 * V_62 , T_5 * V_63 ,
unsigned long V_64 )
{
T_6 V_15 , V_65 = V_64 / sizeof( V_19 ) ;
char * V_66 ;
V_67 = false ;
V_66 = F_18 ( V_65 , V_68 ) ;
if ( ! V_66 )
return;
for ( V_15 = 0 ; V_15 < V_65 ; V_15 ++ )
V_66 [ V_15 ] = V_62 [ V_15 ] ;
F_19 ( V_69 L_1 ,
V_66 , V_63 ) ;
F_20 ( V_66 ) ;
}
int F_21 ( int (* F_22)( V_19 * , T_5 , unsigned long , void * ) ,
void * V_20 , bool V_70 , bool V_71 ,
struct V_52 * V_53 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
unsigned long V_61 = 1024 ;
V_19 * V_50 ;
T_3 V_35 ;
T_5 V_63 ;
int V_36 = 0 ;
V_50 = F_18 ( V_61 , V_68 ) ;
if ( ! V_50 ) {
F_19 ( V_72 L_2 ) ;
return - V_73 ;
}
F_23 ( & V_31 -> V_74 ) ;
do {
V_61 = 1024 ;
V_35 = V_32 -> V_75 ( & V_61 ,
V_50 ,
& V_63 ) ;
switch ( V_35 ) {
case V_37 :
if ( ! V_70 )
F_24 ( & V_31 -> V_74 ) ;
V_61 = F_15 ( V_50 ,
V_61 ) ;
if ( V_71 &&
F_12 ( V_50 , & V_63 , V_53 ) ) {
F_17 ( V_50 , & V_63 ,
V_61 ) ;
if ( ! V_70 )
F_23 ( & V_31 -> V_74 ) ;
V_35 = V_48 ;
break;
}
V_36 = F_22 ( V_50 , V_63 , V_61 , V_20 ) ;
if ( V_36 )
V_35 = V_48 ;
if ( ! V_70 )
F_23 ( & V_31 -> V_74 ) ;
break;
case V_48 :
break;
default:
F_19 ( V_69 L_3 ,
V_35 ) ;
V_35 = V_48 ;
break;
}
} while ( V_35 != V_48 );
F_24 ( & V_31 -> V_74 ) ;
F_20 ( V_50 ) ;
return V_36 ;
}
void F_25 ( struct V_54 * V_55 , struct V_52 * V_53 )
{
F_23 ( & V_31 -> V_74 ) ;
F_26 ( & V_55 -> V_76 , V_53 ) ;
F_24 ( & V_31 -> V_74 ) ;
}
void F_27 ( struct V_54 * V_55 )
{
F_23 ( & V_31 -> V_74 ) ;
F_28 ( & V_55 -> V_76 ) ;
F_24 ( & V_31 -> V_74 ) ;
}
static void F_29 ( struct V_54 * V_55 )
{
F_30 ( ! F_31 ( & V_31 -> V_74 ) ) ;
F_28 ( & V_55 -> V_76 ) ;
F_24 ( & V_31 -> V_74 ) ;
}
int F_32 ( struct V_54 * V_55 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
T_3 V_35 ;
F_30 ( ! F_31 ( & V_31 -> V_74 ) ) ;
V_35 = V_32 -> V_77 ( V_55 -> V_2 . V_18 ,
& V_55 -> V_2 . V_60 ,
0 , 0 , NULL ) ;
return F_11 ( V_35 ) ;
}
int F_33 ( struct V_54 * V_55 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
T_3 V_35 ;
F_23 ( & V_31 -> V_74 ) ;
V_35 = V_32 -> V_77 ( V_55 -> V_2 . V_18 ,
& V_55 -> V_2 . V_60 ,
0 , 0 , NULL ) ;
if ( ! ( V_35 == V_37 || V_35 == V_48 ) ) {
F_24 ( & V_31 -> V_74 ) ;
return F_11 ( V_35 ) ;
}
F_29 ( V_55 ) ;
return 0 ;
}
int F_34 ( struct V_54 * V_55 , T_4 V_27 ,
unsigned long V_28 , void * V_20 , struct V_52 * V_53 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
T_3 V_35 ;
V_19 * V_24 = V_55 -> V_2 . V_18 ;
T_5 V_51 = V_55 -> V_2 . V_60 ;
F_23 ( & V_31 -> V_74 ) ;
if ( V_53 && F_35 ( V_24 , V_51 , V_53 , false ) ) {
F_24 ( & V_31 -> V_74 ) ;
return - V_78 ;
}
V_35 = F_10 ( V_27 , V_28 + F_6 ( V_24 , 1024 ) ) ;
if ( V_35 == V_37 || V_35 == V_34 )
V_35 = V_32 -> V_77 ( V_24 , & V_51 ,
V_27 , V_28 , V_20 ) ;
F_24 ( & V_31 -> V_74 ) ;
return F_11 ( V_35 ) ;
}
int F_36 ( V_19 * V_24 , T_5 V_51 , T_4 V_27 ,
bool V_79 , unsigned long V_28 , void * V_20 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
unsigned long V_80 ;
T_3 V_35 ;
if ( ! V_32 -> V_33 )
return - V_81 ;
if ( ! V_79 ) {
if ( ! F_37 ( & V_31 -> V_74 , V_80 ) )
return - V_82 ;
} else {
F_38 ( & V_31 -> V_74 , V_80 ) ;
}
V_35 = F_10 ( V_27 , V_28 + F_6 ( V_24 , 1024 ) ) ;
if ( V_35 != V_37 ) {
F_39 ( & V_31 -> V_74 , V_80 ) ;
return - V_41 ;
}
V_35 = V_32 -> V_77 ( V_24 , & V_51 , V_27 , V_28 , V_20 ) ;
F_39 ( & V_31 -> V_74 , V_80 ) ;
return F_11 ( V_35 ) ;
}
struct V_54 * F_35 ( V_19 * V_24 , T_5 V_83 ,
struct V_52 * V_53 , bool remove )
{
struct V_54 * V_55 , * V_56 ;
int V_57 , V_58 ;
bool V_59 = false ;
F_30 ( ! F_31 ( & V_31 -> V_74 ) ) ;
F_13 (entry, n, head, list) {
V_57 = F_6 ( V_24 , 1024 ) ;
V_58 = F_6 ( V_55 -> V_2 . V_18 , 1024 ) ;
if ( V_57 == V_58 &&
! memcmp ( V_24 , & ( V_55 -> V_2 . V_18 ) , V_57 ) &&
! F_14 ( V_83 , V_55 -> V_2 . V_60 ) ) {
V_59 = true ;
break;
}
}
if ( ! V_59 )
return NULL ;
if ( remove )
F_28 ( & V_55 -> V_76 ) ;
return V_55 ;
}
int F_40 ( struct V_54 * V_55 , unsigned long * V_28 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
T_3 V_35 ;
* V_28 = 0 ;
F_23 ( & V_31 -> V_74 ) ;
V_35 = V_32 -> V_84 ( V_55 -> V_2 . V_18 ,
& V_55 -> V_2 . V_60 , NULL , V_28 , NULL ) ;
F_24 ( & V_31 -> V_74 ) ;
if ( V_35 != V_85 )
return F_11 ( V_35 ) ;
return 0 ;
}
int F_41 ( struct V_54 * V_55 , T_4 * V_27 ,
unsigned long * V_28 , void * V_20 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
T_3 V_35 ;
F_30 ( ! F_31 ( & V_31 -> V_74 ) ) ;
V_35 = V_32 -> V_84 ( V_55 -> V_2 . V_18 ,
& V_55 -> V_2 . V_60 ,
V_27 , V_28 , V_20 ) ;
return F_11 ( V_35 ) ;
}
int F_42 ( struct V_54 * V_55 , T_4 * V_27 ,
unsigned long * V_28 , void * V_20 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
T_3 V_35 ;
F_23 ( & V_31 -> V_74 ) ;
V_35 = V_32 -> V_84 ( V_55 -> V_2 . V_18 ,
& V_55 -> V_2 . V_60 ,
V_27 , V_28 , V_20 ) ;
F_24 ( & V_31 -> V_74 ) ;
return F_11 ( V_35 ) ;
}
int F_43 ( struct V_54 * V_55 , T_4 V_27 ,
unsigned long * V_28 , void * V_20 , bool * V_86 )
{
const struct V_29 * V_32 = V_31 -> V_32 ;
V_19 * V_24 = V_55 -> V_2 . V_18 ;
T_5 * V_51 = & V_55 -> V_2 . V_60 ;
T_3 V_35 ;
int V_36 ;
* V_86 = false ;
if ( F_9 ( & V_55 -> V_2 , V_20 , * V_28 ) == false )
return - V_39 ;
F_23 ( & V_31 -> V_74 ) ;
V_35 = F_10 ( V_27 , * V_28 + F_6 ( V_24 , 1024 ) ) ;
if ( V_35 != V_37 ) {
if ( V_35 != V_34 ) {
V_36 = F_11 ( V_35 ) ;
goto V_87;
}
if ( * V_28 > 65536 ) {
V_36 = - V_41 ;
goto V_87;
}
}
V_35 = V_32 -> V_77 ( V_24 , V_51 , V_27 , * V_28 , V_20 ) ;
if ( V_35 != V_37 ) {
V_36 = F_11 ( V_35 ) ;
goto V_87;
}
* V_86 = true ;
* V_28 = 0 ;
V_35 = V_32 -> V_84 ( V_55 -> V_2 . V_18 ,
& V_55 -> V_2 . V_60 ,
NULL , V_28 , NULL ) ;
if ( V_35 == V_48 )
F_29 ( V_55 ) ;
else
F_24 ( & V_31 -> V_74 ) ;
if ( V_35 && V_35 != V_85 )
return F_11 ( V_35 ) ;
return 0 ;
V_87:
F_24 ( & V_31 -> V_74 ) ;
return V_36 ;
}
void F_44 ( void )
{
F_23 ( & V_31 -> V_74 ) ;
}
void F_45 ( void )
{
F_24 ( & V_31 -> V_74 ) ;
}
int F_46 ( int (* F_22)( struct V_54 * , void * ) ,
struct V_52 * V_53 , void * V_20 ,
struct V_54 * * V_88 )
{
struct V_54 * V_55 , * V_56 ;
int V_36 = 0 ;
if ( ! V_88 || ! * V_88 ) {
F_13 (entry, n, head, list) {
V_36 = F_22 ( V_55 , V_20 ) ;
if ( V_36 )
break;
}
if ( V_88 )
* V_88 = V_55 ;
return V_36 ;
}
F_47 ((*prev), n, head, list) {
V_36 = F_22 ( * V_88 , V_20 ) ;
if ( V_36 )
break;
}
return V_36 ;
}
int F_48 ( int (* F_22)( struct V_54 * , void * ) ,
struct V_52 * V_53 , void * V_20 )
{
int V_36 = 0 ;
F_44 () ;
V_36 = F_46 ( F_22 , V_53 , V_20 , NULL ) ;
F_45 () ;
return V_36 ;
}
struct V_89 * F_49 ( void )
{
if ( ! V_31 )
return NULL ;
return V_31 -> V_89 ;
}
void F_50 ( void )
{
if ( V_67 )
F_51 ( & V_90 ) ;
}
int F_52 ( struct V_91 * V_91 ,
const struct V_29 * V_32 ,
struct V_89 * V_89 )
{
F_53 ( & V_91 -> V_74 ) ;
V_91 -> V_32 = V_32 ;
V_91 -> V_89 = V_89 ;
V_31 = V_91 ;
return 0 ;
}
int F_54 ( struct V_91 * V_91 )
{
int V_92 ;
if ( ! V_31 ) {
F_19 ( V_72 L_4 ) ;
V_92 = - V_39 ;
goto V_87;
}
if ( V_31 != V_91 ) {
V_92 = - V_39 ;
goto V_87;
}
V_31 = NULL ;
V_92 = 0 ;
V_87:
return V_92 ;
}
