static inline void F_1 ( unsigned long V_1 , unsigned long V_2 , int V_3 ,
struct V_4 * V_5 )
{
unsigned long * V_6 ;
V_6 = ( unsigned long * ) & V_5 -> V_7 ;
if ( * V_6 >= V_1 && * V_6 < V_2 )
* V_6 += V_3 ;
V_6 = ( unsigned long * ) & V_5 -> V_8 ;
if ( * V_6 >= V_1 && * V_6 < V_2 )
* V_6 += V_3 ;
}
static int F_2 ( T_1 * V_9 , int V_10 )
{
T_2 * V_11 , * V_12 ;
int V_13 , V_14 ;
int V_15 ;
unsigned long V_16 , V_17 ;
if ( V_10 <= V_9 -> V_10 )
return - V_18 ;
V_14 = V_10 - V_9 -> V_10 ;
V_11 = F_3 ( sizeof( T_2 ) * V_10 , V_19 ) ;
if ( V_11 == NULL )
return - V_20 ;
if ( V_9 -> V_10 > 0 ) {
memcpy ( V_11 , V_9 -> V_11 ,
sizeof( T_2 ) * V_9 -> V_10 ) ;
V_15 = ( char * ) V_11 - ( char * ) V_9 -> V_11 ;
V_16 = ( unsigned long ) V_9 -> V_11 ;
V_17 = ( unsigned long ) ( V_9 -> V_11 + V_9 -> V_10 ) ;
for ( V_13 = 0 , V_12 = V_11 ; V_13 < V_9 -> V_10 ; V_13 ++ , V_12 ++ )
F_1 ( V_16 , V_17 , V_15 , & V_12 -> V_21 ) ;
F_1 ( V_16 , V_17 , V_15 , & V_9 -> V_22 ) ;
F_1 ( V_16 , V_17 , V_15 , & V_9 -> V_23 ) ;
F_1 ( V_16 , V_17 , V_15 , & V_9 -> V_24 ) ;
if ( ( V_9 -> V_25 & V_26 ) == 0 )
F_4 ( V_9 -> V_11 ) ;
}
V_9 -> V_11 = V_11 ;
V_9 -> V_27 += V_14 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_25 &= ~ V_26 ;
V_12 = V_11 + V_9 -> V_10 - V_14 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ , V_12 ++ )
F_5 ( & V_12 -> V_21 , & V_9 -> V_22 ) ;
return 0 ;
}
static int F_6 ( T_1 * V_9 , int V_28 )
{
int V_10 ;
if ( V_28 >= 4 )
return - V_18 ;
if ( V_9 -> V_27 >= V_28 )
return 0 ;
V_10 = ( ( V_9 -> V_10 + V_28 ) + 15 ) & ~ 15 ;
return F_2 ( V_9 , V_10 ) ;
}
static T_2 * F_7 ( T_1 * V_9 )
{
T_2 * V_12 ;
if ( V_9 -> V_27 == 0 ) {
F_8 ( V_29 L_1 ) ;
return NULL ;
}
V_12 = F_9 ( V_9 -> V_22 . V_7 , T_2 , V_21 ) ;
F_10 ( & V_12 -> V_21 ) ;
V_9 -> V_27 -- ;
V_12 -> V_30 = 0 ;
V_12 -> V_31 = 0 ;
V_12 -> V_32 = NULL ;
return V_12 ;
}
static inline void F_11 ( T_1 * V_9 , T_2 * V_12 )
{
F_5 ( & V_12 -> V_21 , & V_9 -> V_22 ) ;
V_9 -> V_27 ++ ;
}
static void F_12 ( T_1 * V_9 , T_2 * V_33 )
{
T_2 * V_12 ;
T_2 * V_34 ;
T_2 * V_35 ;
T_2 * V_7 ;
int V_31 ;
unsigned long V_1 , V_2 , V_36 , V_37 ;
struct V_4 * V_5 ;
V_31 = V_33 -> V_31 ;
V_1 = V_33 -> V_30 ;
V_2 = V_1 + V_31 ;
V_34 = NULL ;
V_35 = NULL ;
V_7 = NULL ;
F_13 (l, &info->free_list) {
V_12 = F_9 ( V_5 , T_2 , V_21 ) ;
V_36 = V_12 -> V_30 ;
V_37 = V_36 + V_12 -> V_31 ;
if ( V_7 == NULL && V_1 >= V_36 )
V_7 = V_12 ;
if ( V_37 == V_1 )
V_34 = V_12 ;
if ( V_2 == V_36 )
V_35 = V_12 ;
if ( V_34 != NULL && V_35 != NULL )
break;
}
if ( V_34 && V_1 != ( V_34 -> V_30 + V_34 -> V_31 ) )
V_34 = NULL ;
if ( V_35 && V_2 != V_35 -> V_30 )
V_35 = NULL ;
if ( V_34 == NULL && V_35 == NULL ) {
if ( V_7 != NULL )
F_5 ( & V_33 -> V_21 , & V_7 -> V_21 ) ;
else
F_5 ( & V_33 -> V_21 , & V_9 -> V_23 ) ;
return;
}
F_11 ( V_9 , V_33 ) ;
if ( V_34 != NULL && V_35 == NULL ) {
V_34 -> V_31 += V_31 ;
return;
}
if ( V_34 == NULL && V_35 != NULL ) {
V_35 -> V_30 -= V_31 ;
V_35 -> V_31 += V_31 ;
return;
}
V_34 -> V_31 += V_31 + V_35 -> V_31 ;
F_14 ( & V_35 -> V_21 ) ;
F_11 ( V_9 , V_35 ) ;
}
static void F_15 ( T_1 * V_9 , T_2 * V_33 )
{
T_2 * V_12 ;
struct V_4 * V_5 ;
F_13 (l, &info->taken_list) {
V_12 = F_9 ( V_5 , T_2 , V_21 ) ;
if ( V_12 -> V_30 > V_33 -> V_30 ) {
F_16 ( & V_33 -> V_21 , & V_12 -> V_21 ) ;
return;
}
}
F_16 ( & V_33 -> V_21 , & V_9 -> V_24 ) ;
}
T_1 * F_17 ( unsigned int V_38 )
{
T_1 * V_9 ;
if ( ( V_38 & ( V_38 - 1 ) ) != 0 )
return F_18 ( - V_18 ) ;
V_9 = F_3 ( sizeof( * V_9 ) , V_19 ) ;
if ( V_9 == NULL )
return F_18 ( - V_20 ) ;
V_9 -> V_38 = V_38 ;
V_9 -> V_11 = NULL ;
V_9 -> V_10 = 0 ;
V_9 -> V_27 = 0 ;
V_9 -> V_25 = 0 ;
F_19 ( & V_9 -> V_22 ) ;
F_19 ( & V_9 -> V_23 ) ;
F_19 ( & V_9 -> V_24 ) ;
return V_9 ;
}
void F_20 ( T_1 * V_9 )
{
if ( ( V_9 -> V_25 & V_26 ) == 0 && V_9 -> V_11 != NULL )
F_4 ( V_9 -> V_11 ) ;
if ( ( V_9 -> V_25 & V_39 ) == 0 )
F_4 ( V_9 ) ;
}
void F_21 ( T_1 * V_9 , unsigned int V_38 , int V_10 ,
T_2 * V_11 )
{
int V_13 ;
T_2 * V_12 ;
if ( ( V_38 & ( V_38 - 1 ) ) != 0 )
return;
V_9 -> V_38 = V_38 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_27 = V_10 ;
V_9 -> V_25 = V_39 | V_26 ;
F_19 ( & V_9 -> V_22 ) ;
F_19 ( & V_9 -> V_23 ) ;
F_19 ( & V_9 -> V_24 ) ;
for ( V_13 = 0 , V_12 = V_11 ; V_13 < V_10 ; V_13 ++ , V_12 ++ )
F_5 ( & V_12 -> V_21 , & V_9 -> V_22 ) ;
}
int F_22 ( T_1 * V_9 , unsigned long V_30 , int V_31 )
{
T_2 * V_12 ;
unsigned long V_1 , V_2 , V_40 ;
int V_41 ;
V_1 = V_30 ;
V_2 = V_1 + V_31 ;
V_40 = V_9 -> V_38 - 1 ;
V_1 = ( V_1 + V_40 ) & ~ V_40 ;
V_2 = V_2 & ~ V_40 ;
if ( F_23 ( V_2 ) || ( V_2 < V_1 ) )
return - V_42 ;
V_30 = V_1 ;
V_31 = V_2 - V_1 ;
V_41 = F_6 ( V_9 , 1 ) ;
if ( V_41 < 0 )
return V_41 ;
V_12 = F_7 ( V_9 ) ;
V_12 -> V_30 = V_30 ;
V_12 -> V_31 = V_31 ;
V_12 -> V_32 = NULL ;
F_12 ( V_9 , V_12 ) ;
return 0 ;
}
unsigned long F_24 ( T_1 * V_9 , unsigned long V_30 , int V_31 )
{
struct V_4 * V_5 ;
T_2 * V_12 , * V_43 ;
unsigned long V_1 , V_2 , V_40 , V_36 , V_37 ;
if ( V_31 <= 0 )
return ( unsigned long ) - V_18 ;
V_1 = V_30 ;
V_2 = V_1 + V_31 ;
V_40 = V_9 -> V_38 - 1 ;
V_1 = ( V_1 + V_40 ) & ~ V_40 ;
V_2 = V_2 & ~ V_40 ;
if ( F_6 ( V_9 , 1 ) < 0 )
return ( unsigned long ) - V_20 ;
V_12 = NULL ;
F_13 (l, &info->free_list) {
V_12 = F_9 ( V_5 , T_2 , V_21 ) ;
V_36 = V_12 -> V_30 ;
V_37 = V_12 -> V_30 + V_12 -> V_31 ;
if ( V_1 >= V_36 && V_2 <= V_37 )
break;
V_12 = NULL ;
}
if ( V_12 == NULL )
return ( unsigned long ) - V_20 ;
if ( V_36 == V_1 && V_37 == V_2 ) {
F_14 ( & V_12 -> V_21 ) ;
F_11 ( V_9 , V_12 ) ;
return V_1 ;
}
if ( V_36 == V_1 || V_37 == V_2 ) {
if ( V_36 == V_1 )
V_12 -> V_30 += V_31 ;
V_12 -> V_31 -= V_31 ;
} else {
V_12 -> V_31 = V_1 - V_36 ;
V_43 = F_7 ( V_9 ) ;
V_43 -> V_30 = V_2 ;
V_43 -> V_31 = V_37 - V_2 ;
F_5 ( & V_43 -> V_21 , & V_12 -> V_21 ) ;
}
return V_1 ;
}
unsigned long F_25 ( T_1 * V_9 , int V_31 , int V_38 , const char * V_32 )
{
struct V_4 * V_5 ;
T_2 * V_12 ;
T_2 * V_43 ;
unsigned long V_30 , V_44 ;
if ( V_31 <= 0 || ( V_38 & ( V_38 - 1 ) ) != 0 )
return ( unsigned long ) - V_18 ;
V_31 = ( V_31 + ( V_9 -> V_38 - 1 ) ) & ~ ( V_9 -> V_38 - 1 ) ;
if ( F_6 ( V_9 , 2 ) < 0 )
return ( unsigned long ) - V_20 ;
V_12 = NULL ;
F_13 (l, &info->free_list) {
V_12 = F_9 ( V_5 , T_2 , V_21 ) ;
if ( V_31 <= V_12 -> V_31 ) {
V_30 = ( V_12 -> V_30 + V_38 - 1 ) & ~ ( V_38 - 1 ) ;
if ( V_30 + V_31 <= V_12 -> V_30 + V_12 -> V_31 )
break;
}
V_12 = NULL ;
}
if ( V_12 == NULL )
return ( unsigned long ) - V_20 ;
if ( V_12 -> V_31 == V_31 ) {
F_14 ( & V_12 -> V_21 ) ;
V_43 = V_12 ;
} else {
V_44 = V_30 - V_12 -> V_30 ;
if ( V_44 ) {
T_2 * V_45 ;
V_45 = F_7 ( V_9 ) ;
V_45 -> V_30 = V_12 -> V_30 ;
V_45 -> V_31 = V_44 ;
F_5 ( & V_45 -> V_21 , V_12 -> V_21 . V_8 ) ;
}
V_43 = F_7 ( V_9 ) ;
V_43 -> V_30 = V_30 ;
V_43 -> V_31 = V_31 ;
V_12 -> V_30 = V_30 + V_31 ;
V_12 -> V_31 -= V_44 + V_31 ;
if ( V_12 -> V_31 == 0 ) {
F_14 ( & V_12 -> V_21 ) ;
F_11 ( V_9 , V_12 ) ;
}
}
V_43 -> V_32 = V_32 ;
F_15 ( V_9 , V_43 ) ;
return V_30 ;
}
unsigned long F_26 ( T_1 * V_9 , int V_31 , const char * V_32 )
{
return F_25 ( V_9 , V_31 , V_9 -> V_38 , V_32 ) ;
}
unsigned long F_27 ( T_1 * V_9 , unsigned long V_30 , int V_31 , const char * V_32 )
{
struct V_4 * V_5 ;
T_2 * V_12 , * V_46 , * V_47 ;
unsigned long V_1 , V_2 , V_40 , V_36 = 0 , V_37 = 0 ;
if ( V_31 <= 0 )
return ( unsigned long ) - V_18 ;
V_1 = V_30 ;
V_2 = V_1 + V_31 ;
V_40 = V_9 -> V_38 - 1 ;
V_1 = ( V_1 + V_40 ) & ~ V_40 ;
V_2 = V_2 & ~ V_40 ;
if ( F_6 ( V_9 , 2 ) < 0 )
return ( unsigned long ) - V_20 ;
V_12 = NULL ;
F_13 (l, &info->free_list) {
V_12 = F_9 ( V_5 , T_2 , V_21 ) ;
V_36 = V_12 -> V_30 ;
V_37 = V_12 -> V_30 + V_12 -> V_31 ;
if ( V_1 >= V_36 && V_2 <= V_37 )
break;
V_12 = NULL ;
}
if ( V_12 == NULL )
return ( unsigned long ) - V_20 ;
if ( V_36 == V_1 && V_37 == V_2 ) {
F_14 ( & V_12 -> V_21 ) ;
V_12 -> V_32 = V_32 ;
V_30 = V_12 -> V_30 ;
F_15 ( V_9 , V_12 ) ;
return V_30 ;
}
if ( V_36 == V_1 || V_37 == V_2 ) {
if ( V_36 == V_1 )
V_12 -> V_30 += V_31 ;
V_12 -> V_31 -= V_31 ;
} else {
V_12 -> V_31 = V_1 - V_36 ;
V_47 = F_7 ( V_9 ) ;
V_47 -> V_30 = V_2 ;
V_47 -> V_31 = V_37 - V_2 ;
F_5 ( & V_47 -> V_21 , & V_12 -> V_21 ) ;
}
V_46 = F_7 ( V_9 ) ;
V_46 -> V_30 = V_1 ;
V_46 -> V_31 = V_2 - V_1 ;
V_46 -> V_32 = V_32 ;
V_30 = V_46 -> V_30 ;
F_15 ( V_9 , V_46 ) ;
return V_30 ;
}
int F_28 ( T_1 * V_9 , unsigned long V_30 )
{
T_2 * V_12 , * V_48 ;
struct V_4 * V_5 ;
int V_31 ;
V_12 = NULL ;
F_13 (l, &info->taken_list) {
V_48 = F_9 ( V_5 , T_2 , V_21 ) ;
if ( V_30 < V_48 -> V_30 )
break;
V_12 = V_48 ;
}
if ( V_12 == NULL || V_30 > ( V_12 -> V_30 + V_12 -> V_31 ) )
return - V_18 ;
F_14 ( & V_12 -> V_21 ) ;
V_31 = V_12 -> V_31 ;
F_12 ( V_9 , V_12 ) ;
return V_31 ;
}
int F_29 ( T_1 * V_9 , int V_49 , int V_50 , T_3 * V_51 )
{
T_2 * V_12 ;
struct V_4 * V_5 ;
struct V_4 * V_52 ;
int V_53 ;
switch ( V_49 ) {
case V_54 :
V_52 = & V_9 -> V_23 ;
break;
case V_55 :
V_52 = & V_9 -> V_24 ;
break;
default:
return - V_18 ;
}
V_53 = 0 ;
F_13 (l, h) {
V_12 = F_9 ( V_5 , T_2 , V_21 ) ;
if ( V_51 != NULL && V_53 < V_50 ) {
V_51 -> V_30 = V_12 -> V_30 ;
V_51 -> V_31 = V_12 -> V_31 ;
V_51 -> V_32 = V_12 -> V_32 ;
V_51 ++ ;
}
V_53 ++ ;
}
return V_53 ;
}
int F_30 ( T_1 * V_9 , unsigned long V_30 , const char * V_32 )
{
T_2 * V_12 , * V_48 ;
struct V_4 * V_5 ;
int V_31 ;
V_12 = NULL ;
F_13 (l, &info->taken_list) {
V_48 = F_9 ( V_5 , T_2 , V_21 ) ;
if ( V_30 < V_48 -> V_30 )
break;
V_12 = V_48 ;
}
if ( V_12 == NULL || V_30 > ( V_12 -> V_30 + V_12 -> V_31 ) )
return - V_18 ;
V_12 -> V_32 = V_32 ;
V_31 = V_12 -> V_31 ;
return V_31 ;
}
void F_31 ( T_1 * V_9 )
{
static T_3 V_56 [ 32 ] ;
int V_57 ;
int V_13 , V_53 ;
V_57 = F_32 ( V_56 ) ;
F_8 ( V_58
L_2 ,
V_9 , V_9 -> V_27 , V_9 -> V_10 ) ;
F_8 ( V_58 L_3 ) ;
V_53 = F_29 ( V_9 , V_54 , V_57 , V_56 ) ;
if ( V_53 > V_57 )
V_53 = V_57 ;
for ( V_13 = 0 ; V_13 < V_53 ; V_13 ++ )
F_8 ( V_58
L_4 ,
V_56 [ V_13 ] . V_30 , V_56 [ V_13 ] . V_30 + V_56 [ V_13 ] . V_31 ,
V_56 [ V_13 ] . V_31 ) ;
F_8 ( V_58 L_5 ) ;
F_8 ( V_58 L_6 ) ;
V_53 = F_29 ( V_9 , V_55 , V_57 , V_56 ) ;
if ( V_53 > V_57 )
V_53 = V_57 ;
for ( V_13 = 0 ; V_13 < V_53 ; V_13 ++ )
F_8 ( V_58
L_7 ,
V_56 [ V_13 ] . V_30 , V_56 [ V_13 ] . V_30 + V_56 [ V_13 ] . V_31 ,
V_56 [ V_13 ] . V_31 , V_56 [ V_13 ] . V_32 != NULL ? V_56 [ V_13 ] . V_32 : L_8 ) ;
F_8 ( V_58 L_5 ) ;
}
void F_33 ( T_1 * V_9 , T_2 * V_12 )
{
F_8 ( V_58
L_9 ,
V_12 , V_12 -> V_30 , V_12 -> V_30 + V_12 -> V_31 , V_12 -> V_31 ) ;
}
