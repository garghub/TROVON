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
if ( V_6 > V_19 )
F_23 ( V_2 -> V_11 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_6 )
{
if ( V_6 > V_19 )
F_25 ( V_2 -> V_11 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_9 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_19 ( V_2 , V_10 , false ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
void F_27 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
F_28 ( & V_2 -> V_11 -> V_20 ) ;
F_22 ( V_2 , V_6 ) ;
F_26 ( V_2 , V_3 , V_4 , V_5 ) ;
F_24 ( V_2 , V_6 ) ;
F_29 ( & V_2 -> V_11 -> V_20 ) ;
}
void F_30 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
F_26 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_9 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_19 ( V_2 , V_10 , true ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
void F_32 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
F_28 ( & V_2 -> V_11 -> V_20 ) ;
F_22 ( V_2 , V_6 ) ;
F_31 ( V_2 , V_3 , V_4 , V_5 ) ;
F_24 ( V_2 , V_6 ) ;
F_29 ( & V_2 -> V_11 -> V_20 ) ;
}
void F_33 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
F_31 ( V_2 , V_3 , V_4 , V_5 ) ;
}
unsigned long F_34 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 8 ) ;
int V_8 ;
T_3 V_5 = 0 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
V_5 |= ( T_3 ) V_10 -> V_21 << ( V_8 * 8 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_5 ;
}
void F_35 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 8 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_10 ( & V_10 -> V_13 ) ;
V_10 -> V_21 = ( V_5 >> ( V_8 * 8 ) ) & F_36 ( 7 , 8 - V_22 ) ;
F_13 ( & V_10 -> V_13 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
unsigned long F_37 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 2 ) ;
T_2 V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_23 == V_24 )
V_7 |= ( 2U << ( V_8 * 2 ) ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_7 ;
}
void F_38 ( struct V_1 * V_2 ,
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
if ( F_39 ( V_8 * 2 + 1 , & V_5 ) )
V_10 -> V_23 = V_24 ;
else
V_10 -> V_23 = V_25 ;
F_13 ( & V_10 -> V_13 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
T_3 F_40 ( struct V_1 * V_2 , T_2 V_6 )
{
int V_8 ;
T_3 V_5 = 0 ;
int V_26 = V_2 -> V_11 -> V_27 . V_28 . V_29 + V_19 ;
for ( V_8 = 0 ; V_8 < 32 ; V_8 ++ ) {
struct V_9 * V_10 ;
if ( ( V_6 + V_8 ) < V_30 || ( V_6 + V_8 ) >= V_26 )
continue;
V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_23 == V_25 && V_10 -> V_31 )
V_5 |= ( 1U << V_8 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
return V_5 ;
}
void F_41 ( struct V_1 * V_2 , T_2 V_6 ,
const T_3 V_5 )
{
int V_8 ;
int V_26 = V_2 -> V_11 -> V_27 . V_28 . V_29 + V_19 ;
for ( V_8 = 0 ; V_8 < 32 ; V_8 ++ ) {
struct V_9 * V_10 ;
bool V_32 ;
if ( ( V_6 + V_8 ) < V_30 || ( V_6 + V_8 ) >= V_26 )
continue;
V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
V_32 = ! ! ( V_5 & ( 1U << V_8 ) ) ;
F_10 ( & V_10 -> V_13 ) ;
V_10 -> V_31 = V_32 ;
if ( V_32 )
F_11 ( V_2 -> V_11 , V_10 ) ;
else
F_13 ( & V_10 -> V_13 ) ;
F_7 ( V_2 -> V_11 , V_10 ) ;
}
}
static int F_42 ( const void * V_33 , const void * V_34 )
{
const unsigned int V_35 = ( unsigned long ) V_33 ;
const struct V_36 * V_37 = V_34 ;
if ( V_35 < V_37 -> V_38 )
return - 1 ;
if ( V_35 >= V_37 -> V_38 + V_37 -> V_4 )
return 1 ;
return 0 ;
}
const struct V_36 *
F_43 ( const struct V_36 * V_39 ,
int V_40 , unsigned int V_35 )
{
return bsearch ( ( void * ) ( V_41 ) V_35 , V_39 , V_40 ,
sizeof( V_39 [ 0 ] ) , F_42 ) ;
}
void F_44 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
if ( V_44 . type == V_45 )
F_45 ( V_2 , V_43 ) ;
else
F_46 ( V_2 , V_43 ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
if ( V_44 . type == V_45 )
F_48 ( V_2 , V_43 ) ;
else
F_49 ( V_2 , V_43 ) ;
}
unsigned long F_50 ( const void * V_5 , unsigned int V_4 )
{
unsigned long V_46 = F_51 ( V_5 , V_4 ) ;
switch ( V_4 ) {
case 1 :
return V_46 ;
case 2 :
return F_52 ( V_46 ) ;
case 4 :
return F_53 ( V_46 ) ;
default:
return F_54 ( V_46 ) ;
}
}
void F_55 ( void * V_47 , unsigned int V_4 ,
unsigned long V_46 )
{
switch ( V_4 ) {
case 1 :
break;
case 2 :
V_46 = F_56 ( V_46 ) ;
break;
case 4 :
V_46 = F_57 ( V_46 ) ;
break;
default:
V_46 = F_58 ( V_46 ) ;
}
F_59 ( V_47 , V_4 , V_46 ) ;
}
static
struct V_48 * F_60 ( const struct V_49 * V_50 )
{
return F_61 ( V_50 , struct V_48 , V_50 ) ;
}
static bool F_62 ( const struct V_11 * V_11 ,
const struct V_36 * V_37 ,
T_1 V_3 , int V_4 )
{
int V_51 , V_26 = V_11 -> V_27 . V_28 . V_29 + V_19 ;
switch ( V_4 ) {
case sizeof( V_52 ) :
V_51 = V_53 ;
break;
case sizeof( T_2 ) :
V_51 = V_54 ;
break;
case sizeof( T_3 ) :
V_51 = V_55 ;
break;
default:
return false ;
}
if ( ( V_37 -> V_56 & V_51 ) && F_63 ( V_3 , V_4 ) ) {
if ( ! V_37 -> V_57 )
return true ;
return F_5 ( V_3 , V_37 -> V_57 ) < V_26 ;
}
return false ;
}
const struct V_36 *
F_64 ( struct V_1 * V_2 , struct V_48 * V_58 ,
T_1 V_3 , int V_4 )
{
const struct V_36 * V_37 ;
V_37 = F_43 ( V_58 -> V_39 , V_58 -> V_40 ,
V_3 - V_58 -> V_59 ) ;
if ( ! V_37 || ! F_62 ( V_2 -> V_11 , V_37 , V_3 , V_4 ) )
return NULL ;
return V_37 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_49 * V_50 ,
T_1 V_3 , T_2 * V_5 )
{
struct V_48 * V_58 = F_60 ( V_50 ) ;
const struct V_36 * V_37 ;
struct V_1 * V_60 ;
V_37 = F_64 ( V_2 , V_58 , V_3 , sizeof( T_2 ) ) ;
if ( ! V_37 ) {
* V_5 = 0 ;
return 0 ;
}
V_60 = V_58 -> V_61 ? V_58 -> V_61 : V_2 ;
if ( V_37 -> V_62 )
* V_5 = V_37 -> V_62 ( V_60 , V_3 , sizeof( T_2 ) ) ;
else
* V_5 = V_37 -> V_63 ( V_60 , V_3 , sizeof( T_2 ) ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_49 * V_50 ,
T_1 V_3 , const T_2 * V_5 )
{
struct V_48 * V_58 = F_60 ( V_50 ) ;
const struct V_36 * V_37 ;
struct V_1 * V_60 ;
V_37 = F_64 ( V_2 , V_58 , V_3 , sizeof( T_2 ) ) ;
if ( ! V_37 )
return 0 ;
V_60 = V_58 -> V_61 ? V_58 -> V_61 : V_2 ;
if ( V_37 -> V_64 )
V_37 -> V_64 ( V_60 , V_3 , sizeof( T_2 ) , * V_5 ) ;
else
V_37 -> V_65 ( V_60 , V_3 , sizeof( T_2 ) , * V_5 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 , struct V_48 * V_50 ,
bool V_66 , int V_35 , T_2 * V_5 )
{
if ( V_66 )
return F_66 ( V_2 , & V_50 -> V_50 , V_35 , V_5 ) ;
else
return F_65 ( V_2 , & V_50 -> V_50 , V_35 , V_5 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_49 * V_50 ,
T_1 V_3 , int V_4 , void * V_5 )
{
struct V_48 * V_58 = F_60 ( V_50 ) ;
const struct V_36 * V_37 ;
unsigned long V_46 = 0 ;
V_37 = F_64 ( V_2 , V_58 , V_3 , V_4 ) ;
if ( ! V_37 ) {
memset ( V_5 , 0 , V_4 ) ;
return 0 ;
}
switch ( V_58 -> V_67 ) {
case V_68 :
V_46 = V_37 -> V_63 ( V_2 , V_3 , V_4 ) ;
break;
case V_69 :
V_46 = V_37 -> V_63 ( V_2 , V_3 , V_4 ) ;
break;
case V_70 :
V_46 = V_37 -> V_63 ( V_58 -> V_61 , V_3 , V_4 ) ;
break;
case V_71 :
V_46 = V_37 -> V_72 ( V_2 -> V_11 , V_58 -> V_73 , V_3 , V_4 ) ;
break;
}
F_55 ( V_5 , V_4 , V_46 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_49 * V_50 ,
T_1 V_3 , int V_4 , const void * V_5 )
{
struct V_48 * V_58 = F_60 ( V_50 ) ;
const struct V_36 * V_37 ;
unsigned long V_46 = F_50 ( V_5 , V_4 ) ;
V_37 = F_64 ( V_2 , V_58 , V_3 , V_4 ) ;
if ( ! V_37 )
return 0 ;
switch ( V_58 -> V_67 ) {
case V_68 :
V_37 -> V_65 ( V_2 , V_3 , V_4 , V_46 ) ;
break;
case V_69 :
V_37 -> V_65 ( V_2 , V_3 , V_4 , V_46 ) ;
break;
case V_70 :
V_37 -> V_65 ( V_58 -> V_61 , V_3 , V_4 , V_46 ) ;
break;
case V_71 :
V_37 -> V_74 ( V_2 -> V_11 , V_58 -> V_73 , V_3 , V_4 , V_46 ) ;
break;
}
return 0 ;
}
int F_70 ( struct V_11 * V_11 , T_1 V_75 ,
enum V_76 type )
{
struct V_48 * V_77 = & V_11 -> V_27 . V_28 . V_78 ;
int V_79 = 0 ;
unsigned int V_4 ;
switch ( type ) {
case V_45 :
V_4 = F_71 ( V_77 ) ;
break;
case V_80 :
V_4 = F_72 ( V_77 ) ;
break;
default:
F_73 ( 1 ) ;
}
V_77 -> V_59 = V_75 ;
V_77 -> V_67 = V_69 ;
V_77 -> V_61 = NULL ;
F_28 ( & V_11 -> V_81 ) ;
V_79 = F_74 ( V_11 , V_82 , V_75 ,
V_4 , & V_77 -> V_50 ) ;
F_29 ( & V_11 -> V_81 ) ;
return V_79 ;
}
