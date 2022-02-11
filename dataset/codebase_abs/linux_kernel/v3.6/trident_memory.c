static inline void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_4 , T_1 V_5 )
{
V_3 <<= 1 ;
F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
F_2 ( V_2 , V_3 + 1 , V_4 + V_6 , V_5 + V_6 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= 1 ;
F_2 ( V_2 , V_3 , ( unsigned long ) V_2 -> V_7 . V_8 . V_9 , V_2 -> V_7 . V_8 . V_5 ) ;
F_2 ( V_2 , V_3 + 1 , ( unsigned long ) V_2 -> V_7 . V_8 . V_9 , V_2 -> V_7 . V_8 . V_5 ) ;
}
static inline void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_4 , T_1 V_5 )
{
int V_10 ;
V_3 *= V_11 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ , V_3 ++ ) {
F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
V_4 += V_6 ;
V_5 += V_6 ;
}
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 )
{
int V_10 ;
V_3 *= V_11 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ , V_3 ++ )
F_2 ( V_2 , V_3 , ( unsigned long ) V_2 -> V_7 . V_8 . V_9 , V_2 -> V_7 . V_8 . V_5 ) ;
}
static inline void * F_4 ( struct V_1 * V_2 , int V_12 )
{
char * V_4 ;
V_4 = F_5 ( V_2 , F_6 ( V_12 ) ) ;
V_4 += V_12 % V_13 ;
return ( void * ) V_4 ;
}
static struct V_14 *
F_7 ( struct V_15 * V_16 , int V_17 )
{
struct V_14 * V_18 , * V_19 ;
int V_3 , V_20 ;
struct V_21 * V_22 ;
V_20 = F_6 ( V_17 + V_13 - 1 ) ;
V_19 = NULL ;
V_3 = 0 ;
F_8 (p, &hdr->block) {
V_18 = F_9 ( V_22 , struct V_14 , V_23 ) ;
if ( V_3 + V_20 <= F_10 ( V_18 ) )
goto V_24;
V_3 = F_11 ( V_18 ) + 1 ;
}
if ( V_3 + V_20 > V_25 )
return NULL ;
V_24:
V_18 = F_12 ( V_16 , V_20 * V_13 , V_22 -> V_19 ) ;
if ( V_18 == NULL )
return NULL ;
V_18 -> V_12 = F_13 ( V_3 ) ;
F_10 ( V_18 ) = V_3 ;
F_11 ( V_18 ) = V_3 + V_20 - 1 ;
return V_18 ;
}
static int F_14 ( unsigned long V_4 )
{
if ( V_4 & ~ 0x3fffffffUL ) {
F_15 ( V_26 L_1 ) ;
return 0 ;
}
if ( V_4 & ( V_6 - 1 ) ) {
F_15 ( V_26 L_2 ) ;
return 0 ;
}
return 1 ;
}
static struct V_14 *
F_16 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_15 * V_16 ;
struct V_14 * V_18 ;
struct V_29 * V_30 = V_28 -> V_30 ;
int V_31 , V_3 ;
if ( F_17 ( V_30 -> V_32 <= 0 ||
V_30 -> V_32 > V_33 *
V_6 ) )
return NULL ;
V_16 = V_2 -> V_7 . V_34 ;
if ( F_17 ( ! V_16 ) )
return NULL ;
F_18 ( & V_16 -> V_35 ) ;
V_18 = F_7 ( V_16 , V_30 -> V_32 ) ;
if ( V_18 == NULL ) {
F_19 ( & V_16 -> V_35 ) ;
return NULL ;
}
V_31 = 0 ;
for ( V_3 = F_10 ( V_18 ) ; V_3 <= F_11 ( V_18 ) ; V_3 ++ , V_31 ++ ) {
unsigned long V_36 = V_31 << V_37 ;
T_1 V_5 = F_20 ( V_28 , V_36 ) ;
unsigned long V_4 = ( unsigned long )
F_21 ( V_28 , V_36 ) ;
if ( ! F_14 ( V_5 ) ) {
F_22 ( V_16 , V_18 ) ;
F_19 ( & V_16 -> V_35 ) ;
return NULL ;
}
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
F_19 ( & V_16 -> V_35 ) ;
return V_18 ;
}
static struct V_14 *
F_23 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_15 * V_16 ;
struct V_14 * V_18 ;
int V_3 ;
struct V_29 * V_30 = V_28 -> V_30 ;
T_1 V_5 ;
unsigned long V_4 ;
if ( F_17 ( V_30 -> V_32 <= 0 ||
V_30 -> V_32 > V_33 *
V_6 ) )
return NULL ;
V_16 = V_2 -> V_7 . V_34 ;
if ( F_17 ( ! V_16 ) )
return NULL ;
F_18 ( & V_16 -> V_35 ) ;
V_18 = F_7 ( V_16 , V_30 -> V_32 ) ;
if ( V_18 == NULL ) {
F_19 ( & V_16 -> V_35 ) ;
return NULL ;
}
V_5 = V_30 -> V_38 ;
V_4 = ( unsigned long ) V_30 -> V_39 ;
for ( V_3 = F_10 ( V_18 ) ; V_3 <= F_11 ( V_18 ) ; V_3 ++ ,
V_4 += V_6 , V_5 += V_6 ) {
if ( ! F_14 ( V_5 ) ) {
F_22 ( V_16 , V_18 ) ;
F_19 ( & V_16 -> V_35 ) ;
return NULL ;
}
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
F_19 ( & V_16 -> V_35 ) ;
return V_18 ;
}
struct V_14 *
F_24 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
if ( F_17 ( ! V_2 || ! V_28 ) )
return NULL ;
if ( V_28 -> V_40 . V_41 . type == V_42 )
return F_16 ( V_2 , V_28 ) ;
else
return F_23 ( V_2 , V_28 ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
struct V_15 * V_16 ;
int V_3 ;
if ( F_17 ( ! V_2 || ! V_18 ) )
return - V_43 ;
V_16 = V_2 -> V_7 . V_34 ;
F_18 ( & V_16 -> V_35 ) ;
for ( V_3 = F_10 ( V_18 ) ; V_3 <= F_11 ( V_18 ) ; V_3 ++ )
F_3 ( V_2 , V_3 ) ;
F_22 ( V_16 , V_18 ) ;
F_19 ( & V_16 -> V_35 ) ;
return 0 ;
}
