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
bool
F_9 ( T_1 * V_1 , T_2 * V_18 , unsigned long V_4 )
{
int V_14 ;
T_3 * V_19 = V_1 ;
for ( V_14 = 0 ; V_20 [ V_14 ] . V_21 != NULL ; V_14 ++ ) {
const char * V_22 = V_20 [ V_14 ] . V_22 ;
int V_2 ;
for ( V_2 = 0 ; ; V_2 ++ ) {
char V_23 = V_22 [ V_2 ] ;
T_3 V_24 = V_19 [ V_2 ] ;
if ( V_24 > 127 )
return true ;
if ( V_23 == '*' )
return V_20 [ V_14 ] . V_21 ( V_1 ,
V_2 , V_18 , V_4 ) ;
if ( V_23 != V_24 )
break;
if ( ! V_23 )
return V_20 [ V_14 ] . V_21 ( V_1 ,
V_2 , V_18 , V_4 ) ;
}
}
return true ;
}
static T_4
F_10 ( T_5 V_25 , unsigned long V_26 )
{
const struct V_27 * V_28 = V_29 -> V_30 ;
if ( ! V_28 -> V_31 )
return V_32 ;
return V_28 -> V_31 ( V_25 , V_26 ) ;
}
static int F_11 ( T_4 V_33 )
{
int V_34 ;
switch ( V_33 ) {
case V_35 :
V_34 = 0 ;
break;
case V_36 :
V_34 = - V_37 ;
break;
case V_38 :
V_34 = - V_39 ;
break;
case V_40 :
V_34 = - V_41 ;
break;
case V_42 :
V_34 = - V_43 ;
break;
case V_44 :
V_34 = - V_45 ;
break;
case V_46 :
V_34 = - V_47 ;
break;
default:
V_34 = - V_37 ;
}
return V_34 ;
}
static bool F_12 ( T_1 * V_48 , T_6 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 , * V_54 ;
unsigned long V_55 , V_56 ;
bool V_57 = false ;
V_55 = F_6 ( V_48 , 1024 ) ;
F_13 (entry, n, head, list) {
V_56 = F_6 ( V_53 -> V_58 . V_59 , 1024 ) ;
if ( V_55 == V_56 &&
! memcmp ( V_48 , & ( V_53 -> V_58 . V_59 ) ,
V_56 ) &&
! F_14 ( V_53 -> V_58 . V_60 ,
* V_49 ) ) {
V_57 = true ;
break;
}
}
return V_57 ;
}
static unsigned long F_15 ( T_1 * V_48 ,
unsigned long V_61 )
{
unsigned long V_4 ;
T_1 V_23 ;
for ( V_4 = 2 ; V_4 <= V_61 ; V_4 += sizeof( V_23 ) ) {
V_23 = V_48 [ ( V_4 / sizeof( V_23 ) ) - 1 ] ;
if ( ! V_23 )
break;
}
return F_16 ( V_4 , V_61 ) ;
}
static void F_17 ( T_1 * V_62 , T_6 * V_63 ,
unsigned long V_64 )
{
T_7 V_14 , V_65 = V_64 / sizeof( T_1 ) ;
char * V_66 ;
V_67 = false ;
V_66 = F_18 ( V_65 , V_68 ) ;
if ( ! V_66 )
return;
for ( V_14 = 0 ; V_14 < V_65 ; V_14 ++ )
V_66 [ V_14 ] = V_62 [ V_14 ] ;
F_19 ( V_69 L_1 ,
V_66 , V_63 ) ;
F_20 ( V_66 ) ;
}
int F_21 ( int (* F_22)( T_1 * , T_6 , unsigned long , void * ) ,
void * V_18 , bool V_70 , bool V_71 ,
struct V_50 * V_51 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
unsigned long V_61 = 1024 ;
T_1 * V_48 ;
T_4 V_33 ;
T_6 V_63 ;
int V_34 = 0 ;
V_48 = F_18 ( V_61 , V_68 ) ;
if ( ! V_48 ) {
F_19 ( V_72 L_2 ) ;
return - V_73 ;
}
F_23 ( & V_29 -> V_74 ) ;
do {
V_61 = 1024 ;
V_33 = V_30 -> V_75 ( & V_61 ,
V_48 ,
& V_63 ) ;
switch ( V_33 ) {
case V_35 :
if ( ! V_70 )
F_24 ( & V_29 -> V_74 ) ;
V_61 = F_15 ( V_48 ,
V_61 ) ;
if ( V_71 &&
F_12 ( V_48 , & V_63 , V_51 ) ) {
F_17 ( V_48 , & V_63 ,
V_61 ) ;
if ( ! V_70 )
F_23 ( & V_29 -> V_74 ) ;
V_33 = V_46 ;
break;
}
V_34 = F_22 ( V_48 , V_63 , V_61 , V_18 ) ;
if ( V_34 )
V_33 = V_46 ;
if ( ! V_70 )
F_23 ( & V_29 -> V_74 ) ;
break;
case V_46 :
break;
default:
F_19 ( V_69 L_3 ,
V_33 ) ;
V_33 = V_46 ;
break;
}
} while ( V_33 != V_46 );
F_24 ( & V_29 -> V_74 ) ;
F_20 ( V_48 ) ;
return V_34 ;
}
void F_25 ( struct V_52 * V_53 , struct V_50 * V_51 )
{
F_23 ( & V_29 -> V_74 ) ;
F_26 ( & V_53 -> V_76 , V_51 ) ;
F_24 ( & V_29 -> V_74 ) ;
}
void F_27 ( struct V_52 * V_53 )
{
F_23 ( & V_29 -> V_74 ) ;
F_28 ( & V_53 -> V_76 ) ;
F_24 ( & V_29 -> V_74 ) ;
}
static void F_29 ( struct V_52 * V_53 )
{
F_30 ( ! F_31 ( & V_29 -> V_74 ) ) ;
F_28 ( & V_53 -> V_76 ) ;
F_24 ( & V_29 -> V_74 ) ;
}
int F_32 ( struct V_52 * V_53 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
T_4 V_33 ;
F_30 ( ! F_31 ( & V_29 -> V_74 ) ) ;
V_33 = V_30 -> V_77 ( V_53 -> V_58 . V_59 ,
& V_53 -> V_58 . V_60 ,
0 , 0 , NULL ) ;
return F_11 ( V_33 ) ;
}
int F_33 ( struct V_52 * V_53 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
T_4 V_33 ;
F_23 ( & V_29 -> V_74 ) ;
V_33 = V_30 -> V_77 ( V_53 -> V_58 . V_59 ,
& V_53 -> V_58 . V_60 ,
0 , 0 , NULL ) ;
if ( ! ( V_33 == V_35 || V_33 == V_46 ) ) {
F_24 ( & V_29 -> V_74 ) ;
return F_11 ( V_33 ) ;
}
F_29 ( V_53 ) ;
return 0 ;
}
int F_34 ( struct V_52 * V_53 , T_5 V_25 ,
unsigned long V_26 , void * V_18 , struct V_50 * V_51 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
T_4 V_33 ;
T_1 * V_22 = V_53 -> V_58 . V_59 ;
T_6 V_49 = V_53 -> V_58 . V_60 ;
F_23 ( & V_29 -> V_74 ) ;
if ( V_51 && F_35 ( V_22 , V_49 , V_51 , false ) ) {
F_24 ( & V_29 -> V_74 ) ;
return - V_78 ;
}
V_33 = F_10 ( V_25 , V_26 + F_6 ( V_22 , 1024 ) ) ;
if ( V_33 == V_35 || V_33 == V_32 )
V_33 = V_30 -> V_77 ( V_22 , & V_49 ,
V_25 , V_26 , V_18 ) ;
F_24 ( & V_29 -> V_74 ) ;
return F_11 ( V_33 ) ;
}
int F_36 ( T_1 * V_22 , T_6 V_49 , T_5 V_25 ,
bool V_79 , unsigned long V_26 , void * V_18 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
unsigned long V_80 ;
T_4 V_33 ;
if ( ! V_30 -> V_31 )
return - V_81 ;
if ( ! V_79 ) {
if ( ! F_37 ( & V_29 -> V_74 , V_80 ) )
return - V_82 ;
} else {
F_38 ( & V_29 -> V_74 , V_80 ) ;
}
V_33 = F_10 ( V_25 , V_26 + F_6 ( V_22 , 1024 ) ) ;
if ( V_33 != V_35 ) {
F_39 ( & V_29 -> V_74 , V_80 ) ;
return - V_39 ;
}
V_33 = V_30 -> V_77 ( V_22 , & V_49 , V_25 , V_26 , V_18 ) ;
F_39 ( & V_29 -> V_74 , V_80 ) ;
return F_11 ( V_33 ) ;
}
struct V_52 * F_35 ( T_1 * V_22 , T_6 V_83 ,
struct V_50 * V_51 , bool remove )
{
struct V_52 * V_53 , * V_54 ;
int V_55 , V_56 ;
bool V_57 = false ;
F_30 ( ! F_31 ( & V_29 -> V_74 ) ) ;
F_13 (entry, n, head, list) {
V_55 = F_6 ( V_22 , 1024 ) ;
V_56 = F_6 ( V_53 -> V_58 . V_59 , 1024 ) ;
if ( V_55 == V_56 &&
! memcmp ( V_22 , & ( V_53 -> V_58 . V_59 ) , V_55 ) &&
! F_14 ( V_83 , V_53 -> V_58 . V_60 ) ) {
V_57 = true ;
break;
}
}
if ( ! V_57 )
return NULL ;
if ( remove ) {
if ( V_53 -> V_84 ) {
V_53 -> V_85 = true ;
} else
F_28 ( & V_53 -> V_76 ) ;
}
return V_53 ;
}
int F_40 ( struct V_52 * V_53 , unsigned long * V_26 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
T_4 V_33 ;
* V_26 = 0 ;
F_23 ( & V_29 -> V_74 ) ;
V_33 = V_30 -> V_86 ( V_53 -> V_58 . V_59 ,
& V_53 -> V_58 . V_60 , NULL , V_26 , NULL ) ;
F_24 ( & V_29 -> V_74 ) ;
if ( V_33 != V_87 )
return F_11 ( V_33 ) ;
return 0 ;
}
int F_41 ( struct V_52 * V_53 , T_5 * V_25 ,
unsigned long * V_26 , void * V_18 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
T_4 V_33 ;
F_30 ( ! F_31 ( & V_29 -> V_74 ) ) ;
V_33 = V_30 -> V_86 ( V_53 -> V_58 . V_59 ,
& V_53 -> V_58 . V_60 ,
V_25 , V_26 , V_18 ) ;
return F_11 ( V_33 ) ;
}
int F_42 ( struct V_52 * V_53 , T_5 * V_25 ,
unsigned long * V_26 , void * V_18 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
T_4 V_33 ;
F_23 ( & V_29 -> V_74 ) ;
V_33 = V_30 -> V_86 ( V_53 -> V_58 . V_59 ,
& V_53 -> V_58 . V_60 ,
V_25 , V_26 , V_18 ) ;
F_24 ( & V_29 -> V_74 ) ;
return F_11 ( V_33 ) ;
}
int F_43 ( struct V_52 * V_53 , T_5 V_25 ,
unsigned long * V_26 , void * V_18 , bool * V_88 )
{
const struct V_27 * V_30 = V_29 -> V_30 ;
T_1 * V_22 = V_53 -> V_58 . V_59 ;
T_6 * V_49 = & V_53 -> V_58 . V_60 ;
T_4 V_33 ;
int V_34 ;
* V_88 = false ;
if ( F_9 ( V_22 , V_18 , * V_26 ) == false )
return - V_37 ;
F_23 ( & V_29 -> V_74 ) ;
V_33 = F_10 ( V_25 , * V_26 + F_6 ( V_22 , 1024 ) ) ;
if ( V_33 != V_35 ) {
if ( V_33 != V_32 ) {
V_34 = F_11 ( V_33 ) ;
goto V_89;
}
if ( * V_26 > 65536 ) {
V_34 = - V_39 ;
goto V_89;
}
}
V_33 = V_30 -> V_77 ( V_22 , V_49 , V_25 , * V_26 , V_18 ) ;
if ( V_33 != V_35 ) {
V_34 = F_11 ( V_33 ) ;
goto V_89;
}
* V_88 = true ;
* V_26 = 0 ;
V_33 = V_30 -> V_86 ( V_53 -> V_58 . V_59 ,
& V_53 -> V_58 . V_60 ,
NULL , V_26 , NULL ) ;
if ( V_33 == V_46 )
F_29 ( V_53 ) ;
else
F_24 ( & V_29 -> V_74 ) ;
if ( V_33 && V_33 != V_87 )
return F_11 ( V_33 ) ;
return 0 ;
V_89:
F_24 ( & V_29 -> V_74 ) ;
return V_34 ;
}
void F_44 ( void )
{
F_23 ( & V_29 -> V_74 ) ;
}
void F_45 ( void )
{
F_24 ( & V_29 -> V_74 ) ;
}
int F_46 ( int (* F_22)( struct V_52 * , void * ) ,
struct V_50 * V_51 , void * V_18 ,
struct V_52 * * V_90 )
{
struct V_52 * V_53 , * V_54 ;
int V_34 = 0 ;
if ( ! V_90 || ! * V_90 ) {
F_13 (entry, n, head, list) {
V_34 = F_22 ( V_53 , V_18 ) ;
if ( V_34 )
break;
}
if ( V_90 )
* V_90 = V_53 ;
return V_34 ;
}
F_47 ((*prev), n, head, list) {
V_34 = F_22 ( * V_90 , V_18 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
int F_48 ( int (* F_22)( struct V_52 * , void * ) ,
struct V_50 * V_51 , void * V_18 )
{
int V_34 = 0 ;
F_44 () ;
V_34 = F_46 ( F_22 , V_51 , V_18 , NULL ) ;
F_45 () ;
return V_34 ;
}
struct V_91 * F_49 ( void )
{
if ( ! V_29 )
return NULL ;
return V_29 -> V_91 ;
}
void F_50 ( void )
{
if ( V_67 )
F_51 ( & V_92 ) ;
}
int F_52 ( struct V_93 * V_93 ,
const struct V_27 * V_30 ,
struct V_91 * V_91 )
{
F_53 ( & V_93 -> V_74 ) ;
V_93 -> V_30 = V_30 ;
V_93 -> V_91 = V_91 ;
V_29 = V_93 ;
return 0 ;
}
int F_54 ( struct V_93 * V_93 )
{
int V_94 ;
if ( ! V_29 ) {
F_19 ( V_72 L_4 ) ;
V_94 = - V_37 ;
goto V_89;
}
if ( V_29 != V_93 ) {
V_94 = - V_37 ;
goto V_89;
}
V_29 = NULL ;
V_94 = 0 ;
V_89:
return V_94 ;
}
