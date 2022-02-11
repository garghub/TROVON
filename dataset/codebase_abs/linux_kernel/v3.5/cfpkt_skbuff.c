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
if ( F_8 ( F_9 () ) )
V_4 = F_10 ( V_11 + V_12 , V_13 ) ;
else
V_4 = F_10 ( V_11 + V_12 , V_14 ) ;
if ( F_11 ( V_4 == NULL ) )
return NULL ;
F_12 ( V_4 , V_12 ) ;
return F_4 ( V_4 ) ;
}
inline struct V_2 * F_13 ( T_1 V_11 )
{
return F_7 ( V_11 + V_15 , V_16 ) ;
}
void F_14 ( struct V_2 * V_3 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
F_15 ( V_4 ) ;
}
inline bool F_16 ( struct V_2 * V_3 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
return V_4 -> V_11 > 0 ;
}
int F_17 ( struct V_2 * V_3 , void * V_17 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
if ( F_18 ( V_4 ) >= V_11 ) {
memcpy ( V_17 , V_4 -> V_17 , V_11 ) ;
return 0 ;
}
return ! F_19 ( V_3 , V_17 , V_11 ) &&
! F_20 ( V_3 , V_17 , V_11 ) ;
}
int F_19 ( struct V_2 * V_3 , void * V_17 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
T_2 * V_18 ;
if ( F_11 ( F_2 ( V_3 ) ) )
return - V_19 ;
if ( F_11 ( V_11 > V_4 -> V_11 ) ) {
F_21 ( V_3 , L_1 ) ;
return - V_19 ;
}
if ( F_11 ( V_11 > F_18 ( V_4 ) ) ) {
if ( F_11 ( F_22 ( V_4 ) != 0 ) ) {
F_21 ( V_3 , L_2 ) ;
return - V_19 ;
}
}
V_18 = F_23 ( V_4 , V_11 ) ;
V_18 -= V_11 ;
if ( V_17 )
memcpy ( V_17 , V_18 , V_11 ) ;
return 0 ;
}
int F_24 ( struct V_2 * V_3 , void * V_20 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
T_2 * V_17 = V_20 ;
T_2 * V_18 ;
if ( F_11 ( F_2 ( V_3 ) ) )
return - V_19 ;
if ( F_11 ( F_22 ( V_4 ) != 0 ) ) {
F_21 ( V_3 , L_2 ) ;
return - V_19 ;
}
if ( F_11 ( V_4 -> V_17 + V_11 > F_25 ( V_4 ) ) ) {
F_21 ( V_3 , L_1 ) ;
return - V_19 ;
}
V_18 = F_25 ( V_4 ) - V_11 ;
F_26 ( V_4 , V_4 -> V_11 - V_11 ) ;
memcpy ( V_17 , V_18 , V_11 ) ;
return 0 ;
}
int F_27 ( struct V_2 * V_3 , T_1 V_11 )
{
return F_28 ( V_3 , NULL , V_11 ) ;
}
int F_28 ( struct V_2 * V_3 , const void * V_17 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
struct V_7 * V_21 ;
T_2 * V_22 ;
T_1 V_23 = 0 ;
if ( F_11 ( F_2 ( V_3 ) ) )
return - V_19 ;
V_21 = V_4 ;
if ( F_11 ( F_29 ( V_4 ) < V_11 ) ) {
if ( F_8 ( V_11 < V_24 ) )
V_23 = V_24 ;
else
V_23 = V_11 ;
}
if ( F_11 ( ( V_23 > 0 ) || F_30 ( V_4 ) || F_31 ( V_4 ) ) ) {
if ( F_11 ( F_32 ( V_4 , V_23 , & V_21 ) < 0 ) ) {
F_21 ( V_3 , L_3 ) ;
return - V_19 ;
}
if ( V_21 != V_4 ) {
F_33 ( L_4 ) ;
V_4 -> V_11 += V_11 ;
V_4 -> V_25 += V_11 ;
}
}
V_22 = F_34 ( V_21 , V_11 ) ;
if ( F_8 ( V_17 ) )
memcpy ( V_22 , V_17 , V_11 ) ;
return 0 ;
}
inline int F_35 ( struct V_2 * V_3 , T_2 V_17 )
{
return F_28 ( V_3 , & V_17 , 1 ) ;
}
int F_20 ( struct V_2 * V_3 , const void * V_26 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
struct V_7 * V_21 ;
T_2 * V_22 ;
const T_2 * V_17 = V_26 ;
int V_27 ;
if ( F_11 ( F_2 ( V_3 ) ) )
return - V_19 ;
if ( F_11 ( F_36 ( V_4 ) < V_11 ) ) {
F_21 ( V_3 , L_5 ) ;
return - V_19 ;
}
V_27 = F_32 ( V_4 , 0 , & V_21 ) ;
if ( F_11 ( V_27 < 0 ) ) {
F_21 ( V_3 , L_3 ) ;
return V_27 ;
}
V_22 = F_37 ( V_4 , V_11 ) ;
memcpy ( V_22 , V_17 , V_11 ) ;
return 0 ;
}
inline int F_38 ( struct V_2 * V_3 , const void * V_17 , T_1 V_11 )
{
return F_28 ( V_3 , V_17 , V_11 ) ;
}
inline T_1 F_39 ( struct V_2 * V_3 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
return V_4 -> V_11 ;
}
inline T_1 F_40 ( struct V_2 * V_3 ,
T_1 (* F_41)( T_1 , void * , T_1 ) ,
T_1 V_17 )
{
if ( F_11 ( F_2 ( V_3 ) ) )
return - V_19 ;
if ( F_11 ( F_22 ( & V_3 -> V_4 ) != 0 ) ) {
F_21 ( V_3 , L_2 ) ;
return - V_19 ;
}
return F_41 ( V_17 , V_3 -> V_4 . V_17 , F_39 ( V_3 ) ) ;
}
int F_42 ( struct V_2 * V_3 , T_1 V_11 )
{
struct V_7 * V_4 = F_3 ( V_3 ) ;
if ( F_11 ( F_2 ( V_3 ) ) )
return - V_19 ;
if ( F_8 ( V_11 <= V_4 -> V_11 ) ) {
if ( F_11 ( V_4 -> V_25 ) )
F_43 ( V_4 , V_11 ) ;
else
F_26 ( V_4 , V_11 ) ;
return F_39 ( V_3 ) ;
}
if ( F_11 ( ! F_27 ( V_3 , V_11 - V_4 -> V_11 ) ) )
F_21 ( V_3 , L_6 ) ;
return F_39 ( V_3 ) ;
}
struct V_2 * F_44 ( struct V_2 * V_28 ,
struct V_2 * V_29 ,
T_1 V_30 )
{
struct V_7 * V_31 = F_3 ( V_28 ) ;
struct V_7 * V_32 = F_3 ( V_29 ) ;
T_1 V_23 = F_18 ( V_32 ) ;
T_1 V_33 ;
struct V_7 * V_34 ;
T_1 V_35 ;
T_1 V_36 ;
if ( F_11 ( F_2 ( V_28 ) || F_2 ( V_29 ) ) ) {
return V_28 ;
}
if ( V_30 > V_23 )
V_33 = V_30 ;
else
V_33 = V_23 ;
if ( V_31 -> V_37 + V_33 > V_31 -> V_38 ) {
struct V_2 * V_39 ;
V_35 = F_18 ( V_31 ) ;
V_36 = V_35 + V_33 ;
V_39 = F_13 ( V_36 + V_16 + V_15 ) ;
if ( V_39 == NULL )
return NULL ;
V_34 = F_3 ( V_39 ) ;
F_45 ( V_34 , V_35 ) ;
V_34 -> V_11 = V_35 ;
memcpy ( V_34 -> V_17 , V_31 -> V_17 , V_35 ) ;
F_14 ( V_28 ) ;
V_31 = V_34 ;
}
memcpy ( F_25 ( V_31 ) , V_32 -> V_17 , F_18 ( V_32 ) ) ;
F_14 ( V_29 ) ;
V_31 -> V_37 += V_23 ;
V_31 -> V_11 += V_23 ;
return F_4 ( V_31 ) ;
}
struct V_2 * F_46 ( struct V_2 * V_3 , T_1 V_40 )
{
struct V_7 * V_41 ;
struct V_7 * V_4 = F_3 ( V_3 ) ;
struct V_2 * V_39 ;
T_2 * V_42 = V_4 -> V_17 + V_40 ;
T_1 V_43 = F_25 ( V_4 ) - V_42 ;
if ( F_11 ( F_2 ( V_3 ) ) )
return NULL ;
if ( V_4 -> V_17 + V_40 > F_25 ( V_4 ) ) {
F_21 ( V_3 , L_7 ) ;
return NULL ;
}
V_39 = F_7 ( V_43 + V_16 + V_15 ,
V_16 ) ;
if ( V_39 == NULL )
return NULL ;
V_41 = F_3 ( V_39 ) ;
if ( V_41 == NULL )
return NULL ;
F_45 ( V_4 , V_40 ) ;
V_4 -> V_11 = V_40 ;
memcpy ( V_41 -> V_17 , V_42 , V_43 ) ;
V_41 -> V_37 += V_43 ;
V_41 -> V_11 += V_43 ;
V_41 -> V_44 = V_4 -> V_44 ;
return F_4 ( V_41 ) ;
}
bool F_47 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_6 ;
}
struct V_45 * F_48 ( struct V_2 * V_3 )
{
return (struct V_45 * ) & F_3 ( V_3 ) -> V_5 ;
}
void F_49 ( struct V_2 * V_3 , int V_46 )
{
F_3 ( V_3 ) -> V_44 = V_46 ;
}
