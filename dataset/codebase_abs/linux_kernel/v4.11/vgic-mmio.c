unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
return 0 ;
}
unsigned long F_2 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
return - 1UL ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , unsigned long V_5 )
{
}
unsigned long F_4 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
T_2 V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 8 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_12 )
V_7 |= ( 1U << V_8 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_7 ;
}
void F_8 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_9 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_10 ( & V_10 -> V_13 ) ;
V_10 -> V_12 = true ;
F_11 ( V_2 -> V_11 , V_10 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
void F_12 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_9 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_10 ( & V_10 -> V_13 ) ;
V_10 -> V_12 = false ;
F_13 ( & V_10 -> V_13 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
unsigned long F_14 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
T_2 V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 8 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( F_15 ( V_10 ) )
V_7 |= ( 1U << V_8 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_7 ;
}
void F_16 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_9 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_10 ( & V_10 -> V_13 ) ;
V_10 -> V_14 = true ;
F_11 ( V_2 -> V_11 , V_10 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
void F_17 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_9 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_10 ( & V_10 -> V_13 ) ;
V_10 -> V_14 = false ;
F_13 ( & V_10 -> V_13 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
unsigned long F_18 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
T_2 V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 8 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_15 )
V_7 |= ( 1U << V_8 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_7 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_9 * V_10 ,
bool V_16 )
{
struct V_1 * V_17 ;
F_10 ( & V_10 -> V_13 ) ;
V_17 = F_20 () ;
while ( V_10 -> V_2 &&
V_10 -> V_2 != V_17 &&
V_10 -> V_2 -> V_18 != - 1 )
F_21 ( & V_10 -> V_13 ) ;
V_10 -> V_15 = V_16 ;
if ( V_16 )
F_11 ( V_2 -> V_11 , V_10 ) ;
else
F_13 ( & V_10 -> V_13 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_6 )
{
if ( V_6 < V_19 )
F_23 ( V_2 ) ;
else
F_24 ( V_2 -> V_11 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_6 )
{
if ( V_6 < V_19 )
F_26 ( V_2 ) ;
else
F_27 ( V_2 -> V_11 ) ;
}
void F_28 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_22 ( V_2 , V_6 ) ;
F_9 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_19 ( V_2 , V_10 , false ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
F_25 ( V_2 , V_6 ) ;
}
void F_29 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_22 ( V_2 , V_6 ) ;
F_9 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_19 ( V_2 , V_10 , true ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
F_25 ( V_2 , V_6 ) ;
}
unsigned long F_30 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 8 ) ;
int V_8 ;
T_3 V_5 = 0 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
V_5 |= ( T_3 ) V_10 -> V_20 << ( V_8 * 8 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_5 ;
}
void F_31 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 8 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_10 ( & V_10 -> V_13 ) ;
V_10 -> V_20 = ( V_5 >> ( V_8 * 8 ) ) & F_32 ( 7 , 8 - V_21 ) ;
F_13 ( & V_10 -> V_13 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
unsigned long F_33 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 2 ) ;
T_2 V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_22 == V_23 )
V_7 |= ( 2U << ( V_8 * 2 ) ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_7 ;
}
void F_34 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 2 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 4 ; V_8 ++ ) {
struct V_9 * V_10 ;
if ( V_6 + V_8 < V_19 )
continue;
V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_10 ( & V_10 -> V_13 ) ;
if ( F_35 ( V_8 * 2 + 1 , & V_5 ) )
V_10 -> V_22 = V_23 ;
else
V_10 -> V_22 = V_24 ;
F_13 ( & V_10 -> V_13 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
T_3 F_36 ( struct V_1 * V_2 , T_2 V_6 )
{
int V_8 ;
T_3 V_5 = 0 ;
int V_25 = V_2 -> V_11 -> V_26 . V_27 . V_28 + V_19 ;
for ( V_8 = 0 ; V_8 < 32 ; V_8 ++ ) {
struct V_9 * V_10 ;
if ( ( V_6 + V_8 ) < V_29 || ( V_6 + V_8 ) >= V_25 )
continue;
V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_22 == V_24 && V_10 -> V_30 )
V_5 |= ( 1U << V_8 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_5 ;
}
void F_37 ( struct V_1 * V_2 , T_2 V_6 ,
const T_3 V_5 )
{
int V_8 ;
int V_25 = V_2 -> V_11 -> V_26 . V_27 . V_28 + V_19 ;
for ( V_8 = 0 ; V_8 < 32 ; V_8 ++ ) {
struct V_9 * V_10 ;
bool V_31 ;
if ( ( V_6 + V_8 ) < V_29 || ( V_6 + V_8 ) >= V_25 )
continue;
V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
V_31 = ! ! ( V_5 & ( 1U << V_8 ) ) ;
F_10 ( & V_10 -> V_13 ) ;
V_10 -> V_30 = V_31 ;
if ( V_31 )
F_11 ( V_2 -> V_11 , V_10 ) ;
else
F_13 ( & V_10 -> V_13 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
static int F_38 ( const void * V_32 , const void * V_33 )
{
const unsigned int V_34 = ( unsigned long ) V_32 ;
const struct V_35 * V_36 = V_33 ;
if ( V_34 < V_36 -> V_37 )
return - 1 ;
if ( V_34 >= V_36 -> V_37 + V_36 -> V_4 )
return 1 ;
return 0 ;
}
static const struct V_35 *
F_39 ( const struct V_35 * V_36 , int V_38 ,
unsigned int V_34 )
{
return bsearch ( ( void * ) ( V_39 ) V_34 , V_36 , V_38 ,
sizeof( V_36 [ 0 ] ) , F_38 ) ;
}
void F_40 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
if ( V_42 . type == V_43 )
F_41 ( V_2 , V_41 ) ;
else
F_42 ( V_2 , V_41 ) ;
}
void F_43 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
if ( V_42 . type == V_43 )
F_44 ( V_2 , V_41 ) ;
else
F_45 ( V_2 , V_41 ) ;
}
unsigned long F_46 ( const void * V_5 , unsigned int V_4 )
{
unsigned long V_44 = F_47 ( V_5 , V_4 ) ;
switch ( V_4 ) {
case 1 :
return V_44 ;
case 2 :
return F_48 ( V_44 ) ;
case 4 :
return F_49 ( V_44 ) ;
default:
return F_50 ( V_44 ) ;
}
}
void F_51 ( void * V_45 , unsigned int V_4 ,
unsigned long V_44 )
{
switch ( V_4 ) {
case 1 :
break;
case 2 :
V_44 = F_52 ( V_44 ) ;
break;
case 4 :
V_44 = F_53 ( V_44 ) ;
break;
default:
V_44 = F_54 ( V_44 ) ;
}
F_55 ( V_45 , V_4 , V_44 ) ;
}
static
struct V_46 * F_56 ( const struct V_47 * V_48 )
{
return F_57 ( V_48 , struct V_46 , V_48 ) ;
}
static bool F_58 ( const struct V_11 * V_11 ,
const struct V_35 * V_36 ,
T_1 V_3 , int V_4 )
{
int V_49 , V_25 = V_11 -> V_26 . V_27 . V_28 + V_19 ;
switch ( V_4 ) {
case sizeof( V_50 ) :
V_49 = V_51 ;
break;
case sizeof( T_2 ) :
V_49 = V_52 ;
break;
case sizeof( T_3 ) :
V_49 = V_53 ;
break;
default:
return false ;
}
if ( ( V_36 -> V_54 & V_49 ) && F_59 ( V_3 , V_4 ) ) {
if ( ! V_36 -> V_55 )
return true ;
return F_5 ( V_3 , V_36 -> V_55 ) < V_25 ;
}
return false ;
}
const struct V_35 *
F_60 ( struct V_1 * V_2 , struct V_46 * V_56 ,
T_1 V_3 , int V_4 )
{
const struct V_35 * V_36 ;
V_36 = F_39 ( V_56 -> V_57 , V_56 -> V_38 ,
V_3 - V_56 -> V_58 ) ;
if ( ! V_36 || ! F_58 ( V_2 -> V_11 , V_36 , V_3 , V_4 ) )
return NULL ;
return V_36 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_1 V_3 , T_2 * V_5 )
{
struct V_46 * V_56 = F_56 ( V_48 ) ;
const struct V_35 * V_36 ;
struct V_1 * V_59 ;
V_36 = F_60 ( V_2 , V_56 , V_3 , sizeof( T_2 ) ) ;
if ( ! V_36 ) {
* V_5 = 0 ;
return 0 ;
}
V_59 = V_56 -> V_60 ? V_56 -> V_60 : V_2 ;
if ( V_36 -> V_61 )
* V_5 = V_36 -> V_61 ( V_59 , V_3 , sizeof( T_2 ) ) ;
else
* V_5 = V_36 -> V_62 ( V_59 , V_3 , sizeof( T_2 ) ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_1 V_3 , const T_2 * V_5 )
{
struct V_46 * V_56 = F_56 ( V_48 ) ;
const struct V_35 * V_36 ;
struct V_1 * V_59 ;
V_36 = F_60 ( V_2 , V_56 , V_3 , sizeof( T_2 ) ) ;
if ( ! V_36 )
return 0 ;
V_59 = V_56 -> V_60 ? V_56 -> V_60 : V_2 ;
if ( V_36 -> V_63 )
V_36 -> V_63 ( V_59 , V_3 , sizeof( T_2 ) , * V_5 ) ;
else
V_36 -> V_64 ( V_59 , V_3 , sizeof( T_2 ) , * V_5 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 , struct V_46 * V_48 ,
bool V_65 , int V_34 , T_2 * V_5 )
{
if ( V_65 )
return F_62 ( V_2 , & V_48 -> V_48 , V_34 , V_5 ) ;
else
return F_61 ( V_2 , & V_48 -> V_48 , V_34 , V_5 ) ;
}
static int F_64 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_1 V_3 , int V_4 , void * V_5 )
{
struct V_46 * V_56 = F_56 ( V_48 ) ;
const struct V_35 * V_36 ;
unsigned long V_44 = 0 ;
V_36 = F_60 ( V_2 , V_56 , V_3 , V_4 ) ;
if ( ! V_36 ) {
memset ( V_5 , 0 , V_4 ) ;
return 0 ;
}
switch ( V_56 -> V_66 ) {
case V_67 :
V_44 = V_36 -> V_62 ( V_2 , V_3 , V_4 ) ;
break;
case V_68 :
V_44 = V_36 -> V_62 ( V_2 , V_3 , V_4 ) ;
break;
case V_69 :
V_44 = V_36 -> V_62 ( V_56 -> V_60 , V_3 , V_4 ) ;
break;
case V_70 :
V_44 = V_36 -> V_71 ( V_2 -> V_11 , V_56 -> V_72 , V_3 , V_4 ) ;
break;
}
F_51 ( V_5 , V_4 , V_44 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_1 V_3 , int V_4 , const void * V_5 )
{
struct V_46 * V_56 = F_56 ( V_48 ) ;
const struct V_35 * V_36 ;
unsigned long V_44 = F_46 ( V_5 , V_4 ) ;
V_36 = F_60 ( V_2 , V_56 , V_3 , V_4 ) ;
if ( ! V_36 )
return 0 ;
switch ( V_56 -> V_66 ) {
case V_67 :
V_36 -> V_64 ( V_2 , V_3 , V_4 , V_44 ) ;
break;
case V_68 :
V_36 -> V_64 ( V_2 , V_3 , V_4 , V_44 ) ;
break;
case V_69 :
V_36 -> V_64 ( V_56 -> V_60 , V_3 , V_4 , V_44 ) ;
break;
case V_70 :
V_36 -> V_73 ( V_2 -> V_11 , V_56 -> V_72 , V_3 , V_4 , V_44 ) ;
break;
}
return 0 ;
}
int F_66 ( struct V_11 * V_11 , T_1 V_74 ,
enum V_75 type )
{
struct V_46 * V_76 = & V_11 -> V_26 . V_27 . V_77 ;
int V_78 = 0 ;
unsigned int V_4 ;
switch ( type ) {
case V_43 :
V_4 = F_67 ( V_76 ) ;
break;
case V_79 :
V_4 = F_68 ( V_76 ) ;
break;
default:
F_69 ( 1 ) ;
}
V_76 -> V_58 = V_74 ;
V_76 -> V_66 = V_68 ;
V_76 -> V_60 = NULL ;
F_70 ( & V_11 -> V_80 ) ;
V_78 = F_71 ( V_11 , V_81 , V_74 ,
V_4 , & V_76 -> V_48 ) ;
F_72 ( & V_11 -> V_80 ) ;
return V_78 ;
}
