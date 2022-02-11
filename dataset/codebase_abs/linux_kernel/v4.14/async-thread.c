struct V_1 *
F_1 ( const struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
struct V_1 *
F_2 ( const struct V_5 * V_6 )
{
return V_6 -> V_3 -> V_4 ;
}
bool F_3 ( const struct V_7 * V_3 )
{
if ( V_3 -> V_8 -> V_9 == V_10 )
return false ;
return F_4 ( & V_3 -> V_8 -> V_11 ) > V_3 -> V_8 -> V_9 * 2 ;
}
static struct V_2 *
F_5 ( struct V_1 * V_4 , const char * V_12 ,
unsigned int V_13 , int V_14 , int V_9 )
{
struct V_2 * V_15 = F_6 ( sizeof( * V_15 ) , V_16 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_4 = V_4 ;
V_15 -> V_14 = V_14 ;
F_7 ( & V_15 -> V_11 , 0 ) ;
if ( V_9 == 0 )
V_9 = V_17 ;
if ( V_9 < V_17 ) {
V_15 -> V_18 = V_14 ;
V_15 -> V_9 = V_10 ;
} else {
V_15 -> V_18 = 1 ;
V_15 -> V_9 = V_9 ;
}
if ( V_13 & V_19 )
V_15 -> V_20 = F_8 ( L_1 , V_13 ,
V_15 -> V_18 , L_2 ,
V_12 ) ;
else
V_15 -> V_20 = F_8 ( L_3 , V_13 ,
V_15 -> V_18 , L_2 ,
V_12 ) ;
if ( ! V_15 -> V_20 ) {
F_9 ( V_15 ) ;
return NULL ;
}
F_10 ( & V_15 -> V_21 ) ;
F_11 ( & V_15 -> V_22 ) ;
F_11 ( & V_15 -> V_23 ) ;
F_12 ( V_15 , V_12 , V_13 & V_19 ) ;
return V_15 ;
}
struct V_7 * F_13 ( struct V_1 * V_4 ,
const char * V_12 ,
unsigned int V_13 ,
int V_14 ,
int V_9 )
{
struct V_7 * V_15 = F_6 ( sizeof( * V_15 ) , V_16 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_8 = F_5 ( V_4 , V_12 ,
V_13 & ~ V_19 ,
V_14 , V_9 ) ;
if ( ! V_15 -> V_8 ) {
F_9 ( V_15 ) ;
return NULL ;
}
if ( V_13 & V_19 ) {
V_15 -> V_24 = F_5 ( V_4 , V_12 , V_13 ,
V_14 , V_9 ) ;
if ( ! V_15 -> V_24 ) {
F_14 ( V_15 -> V_8 ) ;
F_9 ( V_15 ) ;
return NULL ;
}
}
return V_15 ;
}
static inline void F_15 ( struct V_2 * V_3 )
{
if ( V_3 -> V_9 == V_10 )
return;
F_16 ( & V_3 -> V_11 ) ;
}
static inline void F_17 ( struct V_2 * V_3 )
{
int V_25 ;
long V_11 ;
int V_26 = 0 ;
if ( V_3 -> V_9 == V_10 )
return;
F_18 ( & V_3 -> V_11 ) ;
F_19 ( & V_3 -> V_23 ) ;
V_3 -> V_27 ++ ;
V_3 -> V_27 %= ( V_3 -> V_9 / 4 ) ;
if ( ! V_3 -> V_27 )
goto V_28;
V_25 = V_3 -> V_18 ;
V_11 = F_4 ( & V_3 -> V_11 ) ;
if ( V_11 > V_3 -> V_9 )
V_25 ++ ;
if ( V_11 < V_3 -> V_9 / 2 )
V_25 -- ;
V_25 = F_20 ( V_25 , 1 , V_3 -> V_14 ) ;
if ( V_25 != V_3 -> V_18 ) {
V_26 = 1 ;
V_3 -> V_18 = V_25 ;
}
V_28:
F_21 ( & V_3 -> V_23 ) ;
if ( V_26 ) {
F_22 ( V_3 -> V_20 , V_3 -> V_18 ) ;
}
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = & V_3 -> V_21 ;
struct V_5 * V_6 ;
T_1 * V_31 = & V_3 -> V_22 ;
unsigned long V_13 ;
while ( 1 ) {
void * V_32 ;
F_24 ( V_31 , V_13 ) ;
if ( F_25 ( V_30 ) )
break;
V_6 = F_26 ( V_30 -> V_33 , struct V_5 ,
V_21 ) ;
if ( ! F_27 ( V_34 , & V_6 -> V_13 ) )
break;
if ( F_28 ( V_35 , & V_6 -> V_13 ) )
break;
F_29 ( V_6 ) ;
F_30 ( V_31 , V_13 ) ;
V_6 -> V_36 ( V_6 ) ;
F_24 ( V_31 , V_13 ) ;
F_31 ( & V_6 -> V_21 ) ;
F_30 ( V_31 , V_13 ) ;
V_32 = V_6 ;
V_6 -> V_37 ( V_6 ) ;
F_32 ( V_3 -> V_4 , V_32 ) ;
}
F_30 ( V_31 , V_13 ) ;
}
static void F_33 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
void * V_32 ;
int V_38 = 0 ;
if ( V_6 -> V_36 )
V_38 = 1 ;
V_3 = V_6 -> V_3 ;
V_32 = V_6 ;
F_34 ( V_6 ) ;
F_17 ( V_3 ) ;
V_6 -> V_39 ( V_6 ) ;
if ( V_38 ) {
F_35 ( V_34 , & V_6 -> V_13 ) ;
F_23 ( V_3 ) ;
}
if ( ! V_38 )
F_32 ( V_3 -> V_4 , V_32 ) ;
}
void F_36 ( struct V_5 * V_6 , T_2 V_40 ,
T_3 V_39 ,
T_3 V_36 ,
T_3 V_37 )
{
V_6 -> V_39 = V_39 ;
V_6 -> V_36 = V_36 ;
V_6 -> V_37 = V_37 ;
F_37 ( & V_6 -> V_41 , V_40 ) ;
F_10 ( & V_6 -> V_21 ) ;
V_6 -> V_13 = 0 ;
}
static inline void F_38 ( struct V_2 * V_3 ,
struct V_5 * V_6 )
{
unsigned long V_13 ;
V_6 -> V_3 = V_3 ;
F_15 ( V_3 ) ;
if ( V_6 -> V_36 ) {
F_24 ( & V_3 -> V_22 , V_13 ) ;
F_39 ( & V_6 -> V_21 , & V_3 -> V_21 ) ;
F_30 ( & V_3 -> V_22 , V_13 ) ;
}
F_40 ( V_6 ) ;
F_41 ( V_3 -> V_20 , & V_6 -> V_41 ) ;
}
void F_42 ( struct V_7 * V_3 ,
struct V_5 * V_6 )
{
struct V_2 * V_42 ;
if ( F_27 ( V_43 , & V_6 -> V_13 ) && V_3 -> V_24 )
V_42 = V_3 -> V_24 ;
else
V_42 = V_3 -> V_8 ;
F_38 ( V_42 , V_6 ) ;
}
static inline void
F_14 ( struct V_2 * V_3 )
{
F_43 ( V_3 -> V_20 ) ;
F_44 ( V_3 ) ;
F_9 ( V_3 ) ;
}
void F_45 ( struct V_7 * V_3 )
{
if ( ! V_3 )
return;
if ( V_3 -> V_24 )
F_14 ( V_3 -> V_24 ) ;
F_14 ( V_3 -> V_8 ) ;
F_9 ( V_3 ) ;
}
void F_46 ( struct V_7 * V_3 , int V_14 )
{
if ( ! V_3 )
return;
V_3 -> V_8 -> V_14 = V_14 ;
if ( V_3 -> V_24 )
V_3 -> V_24 -> V_14 = V_14 ;
}
void F_47 ( struct V_5 * V_6 )
{
F_35 ( V_43 , & V_6 -> V_13 ) ;
}
