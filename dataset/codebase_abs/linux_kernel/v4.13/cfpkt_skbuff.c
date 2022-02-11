static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 . V_5 ;
}
static inline bool F_2 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_6 ;
}
static inline struct V_7 * F_3 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 ;
}
static inline struct V_2 * F_4 ( struct V_7 * V_4 )
{
return (struct V_2 * ) V_4 ;
}
struct V_2 * F_5 ( enum V_8 V_9 , void * V_10 )
{
struct V_2 * V_3 = F_4 ( V_10 ) ;
F_1 ( V_3 ) -> V_6 = false ;
return V_3 ;
}
void * F_6 ( struct V_2 * V_3 )
{
return ( void * ) V_3 ;
}
static struct V_2 * F_7 ( T_1 V_11 , T_1 V_12 )
{
struct V_7 * V_4 ;
V_4 = F_8 ( V_11 + V_12 , V_13 ) ;
if ( F_9 ( V_4 == NULL ) )
return NULL ;
F_10 ( V_4 , V_12 ) ;
return F_4 ( V_4 ) ;
}
inline struct V_2 * F_11 ( T_1 V_11 )
{
return F_7 ( V_11 + V_14 , V_15 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
F_13 ( V_4 ) ;
}
inline bool F_14 ( struct V_2 * V_3 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
return V_4 -> V_11 > 0 ;
}
int F_15 ( struct V_2 * V_3 , void * V_16 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
if ( F_16 ( V_4 ) >= V_11 ) {
memcpy ( V_16 , V_4 -> V_16 , V_11 ) ;
return 0 ;
}
return ! F_17 ( V_3 , V_16 , V_11 ) &&
! F_18 ( V_3 , V_16 , V_11 ) ;
}
int F_17 ( struct V_2 * V_3 , void * V_16 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
T_2 * V_17 ;
if ( F_9 ( F_2 ( V_3 ) ) )
return - V_18 ;
if ( F_9 ( V_11 > V_4 -> V_11 ) ) {
F_19 ( V_3 , L_1 ) ;
return - V_18 ;
}
if ( F_9 ( V_11 > F_16 ( V_4 ) ) ) {
if ( F_9 ( F_20 ( V_4 ) != 0 ) ) {
F_19 ( V_3 , L_2 ) ;
return - V_18 ;
}
}
V_17 = F_21 ( V_4 , V_11 ) ;
V_17 -= V_11 ;
if ( V_16 )
memcpy ( V_16 , V_17 , V_11 ) ;
return 0 ;
}
int F_22 ( struct V_2 * V_3 , void * V_19 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
T_2 * V_16 = V_19 ;
T_2 * V_17 ;
if ( F_9 ( F_2 ( V_3 ) ) )
return - V_18 ;
if ( F_9 ( F_20 ( V_4 ) != 0 ) ) {
F_19 ( V_3 , L_2 ) ;
return - V_18 ;
}
if ( F_9 ( V_4 -> V_16 + V_11 > F_23 ( V_4 ) ) ) {
F_19 ( V_3 , L_1 ) ;
return - V_18 ;
}
V_17 = F_23 ( V_4 ) - V_11 ;
F_24 ( V_4 , V_4 -> V_11 - V_11 ) ;
memcpy ( V_16 , V_17 , V_11 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_3 , T_1 V_11 )
{
return F_26 ( V_3 , NULL , V_11 ) ;
}
int F_26 ( struct V_2 * V_3 , const void * V_16 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
struct V_7 * V_20 ;
T_2 * V_21 ;
T_1 V_22 = 0 ;
if ( F_9 ( F_2 ( V_3 ) ) )
return - V_18 ;
V_20 = V_4 ;
if ( F_9 ( F_27 ( V_4 ) < V_11 ) ) {
if ( F_28 ( V_11 < V_23 ) )
V_22 = V_23 ;
else
V_22 = V_11 ;
}
if ( F_9 ( ( V_22 > 0 ) || F_29 ( V_4 ) || F_30 ( V_4 ) ) ) {
if ( F_9 ( F_31 ( V_4 , V_22 , & V_20 ) < 0 ) ) {
F_19 ( V_3 , L_3 ) ;
return - V_18 ;
}
}
V_21 = F_32 ( V_4 , V_20 , V_11 ) ;
if ( F_28 ( V_16 ) )
memcpy ( V_21 , V_16 , V_11 ) ;
return 0 ;
}
inline int F_33 ( struct V_2 * V_3 , T_2 V_16 )
{
return F_26 ( V_3 , & V_16 , 1 ) ;
}
int F_18 ( struct V_2 * V_3 , const void * V_24 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
struct V_7 * V_20 ;
T_2 * V_21 ;
const T_2 * V_16 = V_24 ;
int V_25 ;
if ( F_9 ( F_2 ( V_3 ) ) )
return - V_18 ;
if ( F_9 ( F_34 ( V_4 ) < V_11 ) ) {
F_19 ( V_3 , L_4 ) ;
return - V_18 ;
}
V_25 = F_31 ( V_4 , 0 , & V_20 ) ;
if ( F_9 ( V_25 < 0 ) ) {
F_19 ( V_3 , L_3 ) ;
return V_25 ;
}
V_21 = F_35 ( V_4 , V_11 ) ;
memcpy ( V_21 , V_16 , V_11 ) ;
return 0 ;
}
inline int F_36 ( struct V_2 * V_3 , const void * V_16 , T_1 V_11 )
{
return F_26 ( V_3 , V_16 , V_11 ) ;
}
inline T_1 F_37 ( struct V_2 * V_3 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
return V_4 -> V_11 ;
}
int F_38 ( struct V_2 * V_3 ,
T_1 (* F_39)( T_1 , void * , T_1 ) ,
T_1 V_16 )
{
if ( F_9 ( F_2 ( V_3 ) ) )
return - V_18 ;
if ( F_9 ( F_20 ( & V_3 -> V_4 ) != 0 ) ) {
F_19 ( V_3 , L_2 ) ;
return - V_18 ;
}
return F_39 ( V_16 , V_3 -> V_4 . V_16 , F_37 ( V_3 ) ) ;
}
int F_40 ( struct V_2 * V_3 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
if ( F_9 ( F_2 ( V_3 ) ) )
return - V_18 ;
if ( F_28 ( V_11 <= V_4 -> V_11 ) ) {
if ( F_9 ( V_4 -> V_26 ) )
F_41 ( V_4 , V_11 ) ;
else
F_24 ( V_4 , V_11 ) ;
return F_37 ( V_3 ) ;
}
if ( F_9 ( ! F_25 ( V_3 , V_11 - V_4 -> V_11 ) ) )
F_19 ( V_3 , L_5 ) ;
return F_37 ( V_3 ) ;
}
struct V_2 * F_42 ( struct V_2 * V_27 ,
struct V_2 * V_28 ,
T_1 V_29 )
{
struct V_7 * V_30 = F_3 ( V_27 ) ;
struct V_7 * V_31 = F_3 ( V_28 ) ;
T_1 V_22 = F_16 ( V_31 ) ;
T_1 V_32 ;
struct V_7 * V_33 ;
T_1 V_34 ;
T_1 V_35 ;
if ( F_9 ( F_2 ( V_27 ) || F_2 ( V_28 ) ) ) {
return V_27 ;
}
if ( V_29 > V_22 )
V_32 = V_29 ;
else
V_32 = V_22 ;
if ( V_30 -> V_36 + V_32 > V_30 -> V_37 ) {
struct V_2 * V_38 ;
V_34 = F_16 ( V_30 ) ;
V_35 = V_34 + V_32 ;
V_38 = F_11 ( V_35 + V_15 + V_14 ) ;
if ( V_38 == NULL )
return NULL ;
V_33 = F_3 ( V_38 ) ;
F_43 ( V_33 , V_34 ) ;
V_33 -> V_11 = V_34 ;
memcpy ( V_33 -> V_16 , V_30 -> V_16 , V_34 ) ;
F_12 ( V_27 ) ;
V_30 = V_33 ;
}
memcpy ( F_23 ( V_30 ) , V_31 -> V_16 , F_16 ( V_31 ) ) ;
F_12 ( V_28 ) ;
V_30 -> V_36 += V_22 ;
V_30 -> V_11 += V_22 ;
return F_4 ( V_30 ) ;
}
struct V_2 * F_44 ( struct V_2 * V_3 , T_1 V_39 )
{
struct V_7 * V_40 ;
struct V_7 * V_4 = F_3 ( V_3 ) ;
struct V_2 * V_38 ;
T_2 * V_41 = V_4 -> V_16 + V_39 ;
T_1 V_42 = F_23 ( V_4 ) - V_41 ;
if ( F_9 ( F_2 ( V_3 ) ) )
return NULL ;
if ( V_4 -> V_16 + V_39 > F_23 ( V_4 ) ) {
F_19 ( V_3 , L_6 ) ;
return NULL ;
}
V_38 = F_7 ( V_42 + V_15 + V_14 ,
V_15 ) ;
if ( V_38 == NULL )
return NULL ;
V_40 = F_3 ( V_38 ) ;
if ( V_40 == NULL )
return NULL ;
F_43 ( V_4 , V_39 ) ;
V_4 -> V_11 = V_39 ;
memcpy ( V_40 -> V_16 , V_41 , V_42 ) ;
V_40 -> V_36 += V_42 ;
V_40 -> V_11 += V_42 ;
V_40 -> V_43 = V_4 -> V_43 ;
return F_4 ( V_40 ) ;
}
bool F_45 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_6 ;
}
struct V_44 * F_46 ( struct V_2 * V_3 )
{
return (struct V_44 * ) & F_3 ( V_3 ) -> V_5 ;
}
void F_47 ( struct V_2 * V_3 , int V_45 )
{
F_3 ( V_3 ) -> V_43 = V_45 ;
}
