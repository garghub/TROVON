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
}
return V_7 ;
}
void F_7 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_8 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_9 ( & V_10 -> V_13 ) ;
V_10 -> V_12 = true ;
F_10 ( V_2 -> V_11 , V_10 ) ;
}
}
void F_11 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_8 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_9 ( & V_10 -> V_13 ) ;
V_10 -> V_12 = false ;
F_12 ( & V_10 -> V_13 ) ;
}
}
unsigned long F_13 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
T_2 V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 8 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_14 )
V_7 |= ( 1U << V_8 ) ;
}
return V_7 ;
}
void F_14 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_8 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_9 ( & V_10 -> V_13 ) ;
V_10 -> V_14 = true ;
if ( V_10 -> V_15 == V_16 )
V_10 -> V_17 = true ;
F_10 ( V_2 -> V_11 , V_10 ) ;
}
}
void F_15 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_8 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_9 ( & V_10 -> V_13 ) ;
if ( V_10 -> V_15 == V_16 ) {
V_10 -> V_17 = false ;
V_10 -> V_14 = V_10 -> V_18 ;
} else {
V_10 -> V_14 = false ;
}
F_12 ( & V_10 -> V_13 ) ;
}
}
unsigned long F_16 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
T_2 V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 8 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_19 )
V_7 |= ( 1U << V_8 ) ;
}
return V_7 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_9 * V_10 ,
bool V_20 )
{
F_9 ( & V_10 -> V_13 ) ;
while ( V_10 -> V_2 &&
V_10 -> V_2 -> V_21 != - 1 )
F_18 ( & V_10 -> V_13 ) ;
V_10 -> V_19 = V_20 ;
if ( V_20 )
F_10 ( V_2 -> V_11 , V_10 ) ;
else
F_12 ( & V_10 -> V_13 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_6 )
{
if ( V_6 < V_22 )
F_20 ( V_2 ) ;
else
F_21 ( V_2 -> V_11 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_6 )
{
if ( V_6 < V_22 )
F_23 ( V_2 ) ;
else
F_24 ( V_2 -> V_11 ) ;
}
void F_25 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_19 ( V_2 , V_6 ) ;
F_8 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_17 ( V_2 , V_10 , false ) ;
}
F_22 ( V_2 , V_6 ) ;
}
void F_26 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 1 ) ;
int V_8 ;
F_19 ( V_2 , V_6 ) ;
F_8 (i, &val, len * 8 ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_17 ( V_2 , V_10 , true ) ;
}
F_22 ( V_2 , V_6 ) ;
}
unsigned long F_27 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 8 ) ;
int V_8 ;
T_3 V_5 = 0 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
V_5 |= ( T_3 ) V_10 -> V_23 << ( V_8 * 8 ) ;
}
return V_5 ;
}
void F_28 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 8 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
F_9 ( & V_10 -> V_13 ) ;
V_10 -> V_23 = ( V_5 >> ( V_8 * 8 ) ) & F_29 ( 7 , 8 - V_24 ) ;
F_12 ( & V_10 -> V_13 ) ;
}
}
unsigned long F_30 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_6 = F_5 ( V_3 , 2 ) ;
T_2 V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_10 -> V_15 == V_25 )
V_7 |= ( 2U << ( V_8 * 2 ) ) ;
}
return V_7 ;
}
void F_31 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_5 ( V_3 , 2 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 * 4 ; V_8 ++ ) {
struct V_9 * V_10 = F_6 ( V_2 -> V_11 , V_2 , V_6 + V_8 ) ;
if ( V_6 + V_8 < V_22 )
continue;
F_9 ( & V_10 -> V_13 ) ;
if ( F_32 ( V_8 * 2 + 1 , & V_5 ) ) {
V_10 -> V_15 = V_25 ;
} else {
V_10 -> V_15 = V_16 ;
V_10 -> V_14 = V_10 -> V_18 | V_10 -> V_17 ;
}
F_12 ( & V_10 -> V_13 ) ;
}
}
static int F_33 ( const void * V_26 , const void * V_27 )
{
const unsigned int V_28 = ( unsigned long ) V_26 ;
const struct V_29 * V_30 = V_27 ;
if ( V_28 < V_30 -> V_31 )
return - 1 ;
if ( V_28 >= V_30 -> V_31 + V_30 -> V_4 )
return 1 ;
return 0 ;
}
static const struct V_29 *
F_34 ( const struct V_29 * V_30 , int V_32 ,
unsigned int V_28 )
{
return bsearch ( ( void * ) ( V_33 ) V_28 , V_30 , V_32 ,
sizeof( V_30 [ 0 ] ) , F_33 ) ;
}
unsigned long F_35 ( const void * V_5 , unsigned int V_4 )
{
unsigned long V_34 = F_36 ( V_5 , V_4 ) ;
switch ( V_4 ) {
case 1 :
return V_34 ;
case 2 :
return F_37 ( V_34 ) ;
case 4 :
return F_38 ( V_34 ) ;
default:
return F_39 ( V_34 ) ;
}
}
void F_40 ( void * V_35 , unsigned int V_4 ,
unsigned long V_34 )
{
switch ( V_4 ) {
case 1 :
break;
case 2 :
V_34 = F_41 ( V_34 ) ;
break;
case 4 :
V_34 = F_42 ( V_34 ) ;
break;
default:
V_34 = F_43 ( V_34 ) ;
}
F_44 ( V_35 , V_4 , V_34 ) ;
}
static
struct V_36 * F_45 ( const struct V_37 * V_38 )
{
return F_46 ( V_38 , struct V_36 , V_38 ) ;
}
static bool F_47 ( const struct V_29 * V_30 ,
T_1 V_3 , int V_4 )
{
if ( ( V_30 -> V_39 & V_40 ) && V_4 == 1 )
return true ;
if ( ( V_30 -> V_39 & V_41 ) &&
V_4 == sizeof( T_2 ) && ! ( V_3 & 3 ) )
return true ;
if ( ( V_30 -> V_39 & V_42 ) &&
V_4 == sizeof( T_3 ) && ! ( V_3 & 7 ) )
return true ;
return false ;
}
static int F_48 ( struct V_1 * V_2 , struct V_37 * V_38 ,
T_1 V_3 , int V_4 , void * V_5 )
{
struct V_36 * V_43 = F_45 ( V_38 ) ;
const struct V_29 * V_30 ;
struct V_1 * V_44 ;
unsigned long V_34 ;
V_30 = F_34 ( V_43 -> V_45 , V_43 -> V_32 ,
V_3 - V_43 -> V_46 ) ;
if ( ! V_30 || ! F_47 ( V_30 , V_3 , V_4 ) ) {
memset ( V_5 , 0 , V_4 ) ;
return 0 ;
}
V_44 = V_43 -> V_47 ? V_43 -> V_47 : V_2 ;
V_34 = V_30 -> V_48 ( V_44 , V_3 , V_4 ) ;
F_40 ( V_5 , V_4 , V_34 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_37 * V_38 ,
T_1 V_3 , int V_4 , const void * V_5 )
{
struct V_36 * V_43 = F_45 ( V_38 ) ;
const struct V_29 * V_30 ;
struct V_1 * V_44 ;
unsigned long V_34 = F_35 ( V_5 , V_4 ) ;
V_30 = F_34 ( V_43 -> V_45 , V_43 -> V_32 ,
V_3 - V_43 -> V_46 ) ;
if ( ! V_30 )
return 0 ;
if ( ! F_47 ( V_30 , V_3 , V_4 ) )
return 0 ;
V_44 = V_43 -> V_47 ? V_43 -> V_47 : V_2 ;
V_30 -> V_49 ( V_44 , V_3 , V_4 , V_34 ) ;
return 0 ;
}
int F_50 ( struct V_11 * V_11 , T_1 V_50 ,
enum V_51 type )
{
struct V_36 * V_52 = & V_11 -> V_53 . V_54 . V_55 ;
int V_56 = 0 ;
unsigned int V_4 ;
switch ( type ) {
case V_57 :
V_4 = F_51 ( V_52 ) ;
break;
#ifdef F_52
case V_58 :
V_4 = F_53 ( V_52 ) ;
break;
#endif
default:
F_54 ( 1 ) ;
}
V_52 -> V_46 = V_50 ;
V_52 -> V_47 = NULL ;
F_55 ( & V_11 -> V_59 ) ;
V_56 = F_56 ( V_11 , V_60 , V_50 ,
V_4 , & V_52 -> V_38 ) ;
F_57 ( & V_11 -> V_59 ) ;
return V_56 ;
}
