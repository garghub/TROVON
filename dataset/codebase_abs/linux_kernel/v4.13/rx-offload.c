static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( sizeof( struct V_1 ) > sizeof( V_3 -> V_4 ) ) ;
return (struct V_1 * ) V_3 -> V_4 ;
}
static inline bool F_3 ( struct V_5 * V_6 , unsigned int V_7 , unsigned int V_8 )
{
if ( V_6 -> V_9 )
return V_7 <= V_8 ;
else
return V_7 >= V_8 ;
}
static inline unsigned int F_4 ( struct V_5 * V_6 , unsigned int * V_10 )
{
if ( V_6 -> V_9 )
return ( * V_10 ) ++ ;
else
return ( * V_10 ) -- ;
}
static int F_5 ( struct V_11 * V_12 , int V_13 )
{
struct V_5 * V_6 = F_6 ( V_12 , struct V_5 , V_12 ) ;
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_2 * V_3 ;
int V_18 = 0 ;
while ( ( V_18 < V_13 ) &&
( V_3 = F_7 ( & V_6 -> V_19 ) ) ) {
struct V_20 * V_21 = (struct V_20 * ) V_3 -> V_22 ;
V_18 ++ ;
V_17 -> V_23 ++ ;
V_17 -> V_24 += V_21 -> V_25 ;
F_8 ( V_3 ) ;
}
if ( V_18 < V_13 ) {
F_9 ( V_12 , V_18 ) ;
if ( ! F_10 ( & V_6 -> V_19 ) )
F_11 ( & V_6 -> V_12 ) ;
}
F_12 ( V_6 -> V_15 , V_26 ) ;
return V_18 ;
}
static inline void F_13 ( struct V_27 * V_28 , struct V_2 * V_29 ,
int (* F_14)( struct V_2 * V_7 , struct V_2 * V_8 ) )
{
struct V_2 * V_30 , * V_31 = (struct V_2 * ) V_28 ;
F_15 (head, pos) {
const struct V_1 * V_32 , * V_33 ;
V_32 = F_1 ( V_30 ) ;
V_33 = F_1 ( V_29 ) ;
F_16 ( V_29 -> V_15 ,
L_1 ,
V_34 ,
V_32 -> V_35 , V_33 -> V_35 ,
V_33 -> V_35 - V_32 -> V_35 ,
F_17 ( V_28 ) ) ;
if ( F_14 ( V_30 , V_29 ) < 0 )
continue;
V_31 = V_30 ;
break;
}
F_18 ( V_28 , V_31 , V_29 ) ;
}
static int F_19 ( struct V_2 * V_7 , struct V_2 * V_8 )
{
const struct V_1 * V_36 , * V_37 ;
V_36 = F_1 ( V_7 ) ;
V_37 = F_1 ( V_8 ) ;
return V_37 -> V_35 - V_36 -> V_35 ;
}
static struct V_2 * F_20 ( struct V_5 * V_6 , unsigned int V_38 )
{
struct V_2 * V_3 = NULL ;
struct V_1 * V_4 ;
struct V_20 * V_21 ;
int V_39 ;
if ( F_21 ( F_17 ( & V_6 -> V_19 ) <=
V_6 -> V_40 ) )
V_3 = F_22 ( V_6 -> V_15 , & V_21 ) ;
if ( ! V_3 ) {
struct V_20 V_41 ;
T_1 V_35 ;
V_39 = V_6 -> V_42 ( V_6 , & V_41 ,
& V_35 , V_38 ) ;
if ( V_39 )
V_6 -> V_15 -> V_17 . V_43 ++ ;
return NULL ;
}
V_4 = F_1 ( V_3 ) ;
V_39 = V_6 -> V_42 ( V_6 , V_21 , & V_4 -> V_35 , V_38 ) ;
if ( ! V_39 ) {
F_23 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
int F_24 ( struct V_5 * V_6 , T_2 V_44 )
{
struct V_27 V_19 ;
unsigned int V_45 ;
F_25 ( & V_19 ) ;
for ( V_45 = V_6 -> V_46 ;
F_3 ( V_6 , V_45 , V_6 -> V_47 ) ;
F_4 ( V_6 , & V_45 ) ) {
struct V_2 * V_3 ;
if ( ! ( V_44 & F_26 ( V_45 ) ) )
continue;
V_3 = F_20 ( V_6 , V_45 ) ;
if ( ! V_3 )
break;
F_13 ( & V_19 , V_3 , F_19 ) ;
}
if ( ! F_10 ( & V_19 ) ) {
unsigned long V_48 ;
T_1 V_49 ;
F_27 ( & V_6 -> V_19 . V_50 , V_48 ) ;
F_28 ( & V_19 , & V_6 -> V_19 ) ;
F_29 ( & V_6 -> V_19 . V_50 , V_48 ) ;
if ( ( V_49 = F_17 ( & V_6 -> V_19 ) ) >
( V_6 -> V_40 / 8 ) )
F_16 ( V_6 -> V_15 , L_2 ,
V_34 , V_49 ) ;
F_30 ( V_6 ) ;
}
return F_17 ( & V_19 ) ;
}
int F_31 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
int V_51 = 0 ;
while ( ( V_3 = F_20 ( V_6 , 0 ) ) ) {
F_32 ( & V_6 -> V_19 , V_3 ) ;
V_51 ++ ;
}
if ( V_51 )
F_30 ( V_6 ) ;
return V_51 ;
}
int F_33 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
if ( F_17 ( & V_6 -> V_19 ) >
V_6 -> V_40 )
return - V_52 ;
F_32 ( & V_6 -> V_19 , V_3 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
static int F_34 ( struct V_14 * V_15 , struct V_5 * V_6 , unsigned int V_53 )
{
V_6 -> V_15 = V_15 ;
V_6 -> V_40 = 2 << F_35 ( V_53 ) ;
V_6 -> V_40 *= 4 ;
F_36 ( & V_6 -> V_19 ) ;
F_37 ( V_6 ) ;
F_38 ( V_15 , & V_6 -> V_12 , F_5 , V_53 ) ;
F_39 ( V_15 -> V_15 . V_54 , L_3 ,
V_34 , V_6 -> V_40 ) ;
return 0 ;
}
int F_40 ( struct V_14 * V_15 , struct V_5 * V_6 )
{
unsigned int V_53 ;
if ( V_6 -> V_46 > V_55 ||
V_6 -> V_47 > V_55 || ! V_6 -> V_42 )
return - V_56 ;
if ( V_6 -> V_46 < V_6 -> V_47 ) {
V_6 -> V_9 = true ;
V_53 = V_6 -> V_47 - V_6 -> V_46 ;
} else {
V_6 -> V_9 = false ;
V_53 = V_6 -> V_46 - V_6 -> V_47 ;
}
return F_34 ( V_15 , V_6 , V_53 ) ; ;
}
int F_41 ( struct V_14 * V_15 , struct V_5 * V_6 , unsigned int V_53 )
{
if ( ! V_6 -> V_42 )
return - V_56 ;
return F_34 ( V_15 , V_6 , V_53 ) ;
}
void F_42 ( struct V_5 * V_6 )
{
F_37 ( V_6 ) ;
F_43 ( & V_6 -> V_12 ) ;
}
void F_44 ( struct V_5 * V_6 )
{
F_45 ( & V_6 -> V_12 ) ;
F_46 ( & V_6 -> V_19 ) ;
}
void F_37 ( struct V_5 * V_6 )
{
}
