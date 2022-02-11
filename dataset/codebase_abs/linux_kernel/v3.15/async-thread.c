static inline struct V_1
* F_1 ( const char * V_2 , int V_3 , int V_4 ,
int V_5 )
{
struct V_1 * V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( F_3 ( ! V_6 ) )
return NULL ;
V_6 -> V_4 = V_4 ;
F_4 ( & V_6 -> V_8 , 0 ) ;
if ( V_5 == 0 )
V_5 = V_9 ;
if ( V_5 < V_9 ) {
V_6 -> V_10 = V_4 ;
V_6 -> V_5 = V_11 ;
} else {
V_6 -> V_10 = 1 ;
V_6 -> V_5 = V_5 ;
}
if ( V_3 & V_12 )
V_6 -> V_13 = F_5 ( L_1 , V_3 ,
V_6 -> V_4 ,
L_2 , V_2 ) ;
else
V_6 -> V_13 = F_5 ( L_3 , V_3 ,
V_6 -> V_4 , L_2 ,
V_2 ) ;
if ( F_3 ( ! V_6 -> V_13 ) ) {
F_6 ( V_6 ) ;
return NULL ;
}
F_7 ( & V_6 -> V_14 ) ;
F_8 ( & V_6 -> V_15 ) ;
F_8 ( & V_6 -> V_16 ) ;
F_9 ( V_6 , V_2 , V_3 & V_12 ) ;
return V_6 ;
}
struct V_17 * F_10 ( const char * V_2 ,
int V_3 ,
int V_4 ,
int V_5 )
{
struct V_17 * V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( F_3 ( ! V_6 ) )
return NULL ;
V_6 -> V_18 = F_1 ( V_2 , V_3 & ~ V_12 ,
V_4 , V_5 ) ;
if ( F_3 ( ! V_6 -> V_18 ) ) {
F_6 ( V_6 ) ;
return NULL ;
}
if ( V_3 & V_12 ) {
V_6 -> V_19 = F_1 ( V_2 , V_3 , V_4 ,
V_5 ) ;
if ( F_3 ( ! V_6 -> V_19 ) ) {
F_11 ( V_6 -> V_18 ) ;
F_6 ( V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
static inline void F_12 ( struct V_1 * V_20 )
{
if ( V_20 -> V_5 == V_11 )
return;
F_13 ( & V_20 -> V_8 ) ;
}
static inline void F_14 ( struct V_1 * V_20 )
{
int V_21 ;
long V_8 ;
int V_22 = 0 ;
if ( V_20 -> V_5 == V_11 )
return;
F_15 ( & V_20 -> V_8 ) ;
F_16 ( & V_20 -> V_16 ) ;
V_20 -> V_23 ++ ;
V_20 -> V_23 %= ( V_20 -> V_5 / 4 ) ;
if ( ! V_20 -> V_23 )
goto V_24;
V_21 = V_20 -> V_10 ;
V_8 = F_17 ( & V_20 -> V_8 ) ;
if ( V_8 > V_20 -> V_5 )
V_21 ++ ;
if ( V_8 < V_20 -> V_5 / 2 )
V_21 -- ;
V_21 = F_18 ( V_21 , 1 , V_20 -> V_4 ) ;
if ( V_21 != V_20 -> V_10 ) {
V_22 = 1 ;
V_20 -> V_10 = V_21 ;
}
V_24:
F_19 ( & V_20 -> V_16 ) ;
if ( V_22 ) {
F_20 ( V_20 -> V_13 , V_20 -> V_10 ) ;
}
}
static void F_21 ( struct V_1 * V_20 )
{
struct V_25 * V_26 = & V_20 -> V_14 ;
struct V_27 * V_28 ;
T_1 * V_29 = & V_20 -> V_15 ;
unsigned long V_3 ;
while ( 1 ) {
F_22 ( V_29 , V_3 ) ;
if ( F_23 ( V_26 ) )
break;
V_28 = F_24 ( V_26 -> V_30 , struct V_27 ,
V_14 ) ;
if ( ! F_25 ( V_31 , & V_28 -> V_3 ) )
break;
if ( F_26 ( V_32 , & V_28 -> V_3 ) )
break;
F_27 ( V_28 ) ;
F_28 ( V_29 , V_3 ) ;
V_28 -> V_33 ( V_28 ) ;
F_22 ( V_29 , V_3 ) ;
F_29 ( & V_28 -> V_14 ) ;
F_28 ( V_29 , V_3 ) ;
V_28 -> V_34 ( V_28 ) ;
F_30 ( V_28 ) ;
}
F_28 ( V_29 , V_3 ) ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_27 * V_28 ;
struct V_1 * V_20 ;
int V_37 = 0 ;
V_28 = F_32 ( V_36 , struct V_27 , V_38 ) ;
if ( V_28 -> V_33 )
V_37 = 1 ;
V_20 = V_28 -> V_20 ;
F_33 ( V_28 ) ;
F_14 ( V_20 ) ;
V_28 -> V_39 ( V_28 ) ;
if ( V_37 ) {
F_34 ( V_31 , & V_28 -> V_3 ) ;
F_21 ( V_20 ) ;
}
if ( ! V_37 )
F_30 ( V_28 ) ;
}
void F_35 ( struct V_27 * V_28 ,
T_2 V_39 ,
T_2 V_33 ,
T_2 V_34 )
{
V_28 -> V_39 = V_39 ;
V_28 -> V_33 = V_33 ;
V_28 -> V_34 = V_34 ;
F_36 ( & V_28 -> V_38 , F_31 ) ;
F_7 ( & V_28 -> V_14 ) ;
V_28 -> V_3 = 0 ;
}
static inline void F_37 ( struct V_1 * V_20 ,
struct V_27 * V_28 )
{
unsigned long V_3 ;
V_28 -> V_20 = V_20 ;
F_12 ( V_20 ) ;
if ( V_28 -> V_33 ) {
F_22 ( & V_20 -> V_15 , V_3 ) ;
F_38 ( & V_28 -> V_14 , & V_20 -> V_14 ) ;
F_28 ( & V_20 -> V_15 , V_3 ) ;
}
F_39 ( V_20 -> V_13 , & V_28 -> V_38 ) ;
F_40 ( V_28 ) ;
}
void F_41 ( struct V_17 * V_20 ,
struct V_27 * V_28 )
{
struct V_1 * V_40 ;
if ( F_25 ( V_41 , & V_28 -> V_3 ) && V_20 -> V_19 )
V_40 = V_20 -> V_19 ;
else
V_40 = V_20 -> V_18 ;
F_37 ( V_40 , V_28 ) ;
}
static inline void
F_11 ( struct V_1 * V_20 )
{
F_42 ( V_20 -> V_13 ) ;
F_43 ( V_20 ) ;
F_6 ( V_20 ) ;
}
void F_44 ( struct V_17 * V_20 )
{
if ( ! V_20 )
return;
if ( V_20 -> V_19 )
F_11 ( V_20 -> V_19 ) ;
F_11 ( V_20 -> V_18 ) ;
F_6 ( V_20 ) ;
}
void F_45 ( struct V_17 * V_20 , int V_42 )
{
if ( ! V_20 )
return;
V_20 -> V_18 -> V_4 = V_42 ;
if ( V_20 -> V_19 )
V_20 -> V_19 -> V_4 = V_42 ;
}
void F_46 ( struct V_27 * V_28 )
{
F_34 ( V_41 , & V_28 -> V_3 ) ;
}
