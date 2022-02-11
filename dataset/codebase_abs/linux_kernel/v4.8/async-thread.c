struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
struct V_1 *
F_2 ( struct V_5 * V_6 )
{
return V_6 -> V_3 -> V_4 ;
}
static struct V_2 *
F_3 ( struct V_1 * V_4 , const char * V_7 ,
unsigned int V_8 , int V_9 , int V_10 )
{
struct V_2 * V_11 = F_4 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_4 = V_4 ;
V_11 -> V_9 = V_9 ;
F_5 ( & V_11 -> V_13 , 0 ) ;
if ( V_10 == 0 )
V_10 = V_14 ;
if ( V_10 < V_14 ) {
V_11 -> V_15 = V_9 ;
V_11 -> V_10 = V_16 ;
} else {
V_11 -> V_15 = 1 ;
V_11 -> V_10 = V_10 ;
}
if ( V_8 & V_17 )
V_11 -> V_18 = F_6 ( L_1 , V_8 ,
V_11 -> V_15 , L_2 ,
V_7 ) ;
else
V_11 -> V_18 = F_6 ( L_3 , V_8 ,
V_11 -> V_15 , L_2 ,
V_7 ) ;
if ( ! V_11 -> V_18 ) {
F_7 ( V_11 ) ;
return NULL ;
}
F_8 ( & V_11 -> V_19 ) ;
F_9 ( & V_11 -> V_20 ) ;
F_9 ( & V_11 -> V_21 ) ;
F_10 ( V_11 , V_7 , V_8 & V_17 ) ;
return V_11 ;
}
struct V_22 * F_11 ( struct V_1 * V_4 ,
const char * V_7 ,
unsigned int V_8 ,
int V_9 ,
int V_10 )
{
struct V_22 * V_11 = F_4 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_23 = F_3 ( V_4 , V_7 ,
V_8 & ~ V_17 ,
V_9 , V_10 ) ;
if ( ! V_11 -> V_23 ) {
F_7 ( V_11 ) ;
return NULL ;
}
if ( V_8 & V_17 ) {
V_11 -> V_24 = F_3 ( V_4 , V_7 , V_8 ,
V_9 , V_10 ) ;
if ( ! V_11 -> V_24 ) {
F_12 ( V_11 -> V_23 ) ;
F_7 ( V_11 ) ;
return NULL ;
}
}
return V_11 ;
}
static inline void F_13 ( struct V_2 * V_3 )
{
if ( V_3 -> V_10 == V_16 )
return;
F_14 ( & V_3 -> V_13 ) ;
}
static inline void F_15 ( struct V_2 * V_3 )
{
int V_25 ;
long V_13 ;
int V_26 = 0 ;
if ( V_3 -> V_10 == V_16 )
return;
F_16 ( & V_3 -> V_13 ) ;
F_17 ( & V_3 -> V_21 ) ;
V_3 -> V_27 ++ ;
V_3 -> V_27 %= ( V_3 -> V_10 / 4 ) ;
if ( ! V_3 -> V_27 )
goto V_28;
V_25 = V_3 -> V_15 ;
V_13 = F_18 ( & V_3 -> V_13 ) ;
if ( V_13 > V_3 -> V_10 )
V_25 ++ ;
if ( V_13 < V_3 -> V_10 / 2 )
V_25 -- ;
V_25 = F_19 ( V_25 , 1 , V_3 -> V_9 ) ;
if ( V_25 != V_3 -> V_15 ) {
V_26 = 1 ;
V_3 -> V_15 = V_25 ;
}
V_28:
F_20 ( & V_3 -> V_21 ) ;
if ( V_26 ) {
F_21 ( V_3 -> V_18 , V_3 -> V_15 ) ;
}
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = & V_3 -> V_19 ;
struct V_5 * V_6 ;
T_1 * V_31 = & V_3 -> V_20 ;
unsigned long V_8 ;
while ( 1 ) {
F_23 ( V_31 , V_8 ) ;
if ( F_24 ( V_30 ) )
break;
V_6 = F_25 ( V_30 -> V_32 , struct V_5 ,
V_19 ) ;
if ( ! F_26 ( V_33 , & V_6 -> V_8 ) )
break;
if ( F_27 ( V_34 , & V_6 -> V_8 ) )
break;
F_28 ( V_6 ) ;
F_29 ( V_31 , V_8 ) ;
V_6 -> V_35 ( V_6 ) ;
F_23 ( V_31 , V_8 ) ;
F_30 ( & V_6 -> V_19 ) ;
F_29 ( V_31 , V_8 ) ;
V_6 -> V_36 ( V_6 ) ;
F_31 ( V_6 ) ;
}
F_29 ( V_31 , V_8 ) ;
}
static void F_32 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
int V_37 = 0 ;
if ( V_6 -> V_35 )
V_37 = 1 ;
V_3 = V_6 -> V_3 ;
F_33 ( V_6 ) ;
F_15 ( V_3 ) ;
V_6 -> V_38 ( V_6 ) ;
if ( V_37 ) {
F_34 ( V_33 , & V_6 -> V_8 ) ;
F_22 ( V_3 ) ;
}
if ( ! V_37 )
F_31 ( V_6 ) ;
}
void F_35 ( struct V_5 * V_6 , T_2 V_39 ,
T_3 V_38 ,
T_3 V_35 ,
T_3 V_36 )
{
V_6 -> V_38 = V_38 ;
V_6 -> V_35 = V_35 ;
V_6 -> V_36 = V_36 ;
F_36 ( & V_6 -> V_40 , V_39 ) ;
F_8 ( & V_6 -> V_19 ) ;
V_6 -> V_8 = 0 ;
}
static inline void F_37 ( struct V_2 * V_3 ,
struct V_5 * V_6 )
{
unsigned long V_8 ;
V_6 -> V_3 = V_3 ;
F_13 ( V_3 ) ;
if ( V_6 -> V_35 ) {
F_23 ( & V_3 -> V_20 , V_8 ) ;
F_38 ( & V_6 -> V_19 , & V_3 -> V_19 ) ;
F_29 ( & V_3 -> V_20 , V_8 ) ;
}
F_39 ( V_6 ) ;
F_40 ( V_3 -> V_18 , & V_6 -> V_40 ) ;
}
void F_41 ( struct V_22 * V_3 ,
struct V_5 * V_6 )
{
struct V_2 * V_41 ;
if ( F_26 ( V_42 , & V_6 -> V_8 ) && V_3 -> V_24 )
V_41 = V_3 -> V_24 ;
else
V_41 = V_3 -> V_23 ;
F_37 ( V_41 , V_6 ) ;
}
static inline void
F_12 ( struct V_2 * V_3 )
{
F_42 ( V_3 -> V_18 ) ;
F_43 ( V_3 ) ;
F_7 ( V_3 ) ;
}
void F_44 ( struct V_22 * V_3 )
{
if ( ! V_3 )
return;
if ( V_3 -> V_24 )
F_12 ( V_3 -> V_24 ) ;
F_12 ( V_3 -> V_23 ) ;
F_7 ( V_3 ) ;
}
void F_45 ( struct V_22 * V_3 , int V_9 )
{
if ( ! V_3 )
return;
V_3 -> V_23 -> V_9 = V_9 ;
if ( V_3 -> V_24 )
V_3 -> V_24 -> V_9 = V_9 ;
}
void F_46 ( struct V_5 * V_6 )
{
F_34 ( V_42 , & V_6 -> V_8 ) ;
}
