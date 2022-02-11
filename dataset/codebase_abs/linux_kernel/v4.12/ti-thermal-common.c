static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 , V_7 ) ;
F_4 ( & V_4 -> V_6 -> V_8 , L_1 ,
V_4 -> V_6 -> type ) ;
}
static inline int F_5 ( int V_9 , int V_10 , int V_11 )
{
int V_12 = V_9 * V_10 / 1000 + V_11 ;
if ( V_12 < 0 )
V_12 = 0 ;
return V_9 + V_12 ;
}
static inline int F_6 ( void * V_13 , int * V_14 )
{
struct V_15 * V_16 = NULL ;
struct V_3 * V_4 = V_13 ;
struct V_17 * V_18 ;
const struct V_19 * V_10 ;
int V_20 , V_21 , V_22 , V_23 ;
int V_24 ;
if ( ! V_4 )
return 0 ;
V_18 = V_4 -> V_18 ;
V_10 = & V_18 -> V_25 -> V_26 [ V_4 -> V_27 ] ;
V_20 = F_7 ( V_18 , V_4 -> V_27 , & V_21 ) ;
if ( V_20 )
return V_20 ;
V_22 = F_8 ( V_4 -> V_6 ) ;
V_23 = F_9 ( V_4 -> V_6 ) ;
V_16 = V_4 -> V_16 ;
if ( ! F_10 ( V_16 ) ) {
V_20 = F_11 ( V_16 , & V_24 ) ;
if ( ! V_20 ) {
V_21 -= V_24 ;
V_22 = V_10 -> V_28 ;
V_23 = V_10 -> V_29 ;
} else {
F_12 ( V_18 -> V_30 ,
L_2 ) ;
V_20 = 0 ;
}
}
* V_14 = F_5 ( V_21 , V_22 , V_23 ) ;
return V_20 ;
}
static inline int F_13 ( struct V_15 * V_31 ,
int * V_14 )
{
struct V_3 * V_4 = V_31 -> V_13 ;
return F_6 ( V_4 , V_14 ) ;
}
static int F_14 ( void * V_32 , int V_33 , enum V_34 * V_35 )
{
struct V_3 * V_4 = V_32 ;
struct V_17 * V_18 ;
int V_36 , V_37 , V_20 = 0 ;
V_18 = V_4 -> V_18 ;
V_36 = V_4 -> V_27 ;
V_20 = F_15 ( V_18 , V_36 , & V_37 ) ;
if ( V_20 )
return V_20 ;
if ( V_37 > 0 )
* V_35 = V_38 ;
else if ( V_37 < 0 )
* V_35 = V_39 ;
else
* V_35 = V_40 ;
return 0 ;
}
static struct V_3
* F_16 ( struct V_17 * V_18 , int V_36 )
{
struct V_3 * V_4 ;
V_4 = F_17 ( V_18 -> V_30 , sizeof( * V_4 ) , V_41 ) ;
if ( ! V_4 ) {
F_12 ( V_18 -> V_30 , L_3 ) ;
return NULL ;
}
V_4 -> V_27 = V_36 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_42 = V_43 ;
V_4 -> V_16 = F_18 ( L_4 ) ;
F_19 ( & V_4 -> V_5 , F_1 ) ;
return V_4 ;
}
int F_20 ( struct V_17 * V_18 , int V_36 ,
char * V_44 )
{
struct V_3 * V_4 ;
V_4 = F_21 ( V_18 , V_36 ) ;
if ( ! V_4 || F_10 ( V_4 ) )
V_4 = F_16 ( V_18 , V_36 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_6 = F_22 ( V_18 -> V_30 , V_36 ,
V_4 , & V_46 ) ;
if ( F_10 ( V_4 -> V_6 ) ) {
F_12 ( V_18 -> V_30 , L_5 ) ;
return F_23 ( V_4 -> V_6 ) ;
}
F_24 ( V_18 , V_36 , V_4 ) ;
F_25 ( V_18 , V_4 -> V_27 ,
V_4 -> V_6 -> V_47 ) ;
return 0 ;
}
int F_26 ( struct V_17 * V_18 , int V_36 )
{
struct V_3 * V_4 ;
V_4 = F_21 ( V_18 , V_36 ) ;
if ( V_4 && V_4 -> V_6 ) {
if ( V_4 -> V_48 )
F_27 ( V_4 -> V_6 ) ;
}
return 0 ;
}
int F_28 ( struct V_17 * V_18 , int V_36 )
{
struct V_3 * V_4 ;
V_4 = F_21 ( V_18 , V_36 ) ;
F_29 ( & V_4 -> V_5 ) ;
return 0 ;
}
int F_30 ( struct V_17 * V_18 , int V_36 )
{
struct V_3 * V_4 ;
struct V_49 * V_50 = V_18 -> V_30 -> V_51 ;
if ( F_31 ( V_50 , L_6 , NULL ) )
return 0 ;
V_4 = F_21 ( V_18 , V_36 ) ;
if ( ! V_4 || F_10 ( V_4 ) )
V_4 = F_16 ( V_18 , V_36 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_52 = F_32 ( V_53 ) ;
if ( F_10 ( V_4 -> V_52 ) ) {
int V_20 = F_23 ( V_4 -> V_52 ) ;
if ( V_20 != - V_54 )
F_12 ( V_18 -> V_30 ,
L_7 ,
V_20 ) ;
return V_20 ;
}
F_24 ( V_18 , V_36 , V_4 ) ;
return 0 ;
}
int F_33 ( struct V_17 * V_18 , int V_36 )
{
struct V_3 * V_4 ;
V_4 = F_21 ( V_18 , V_36 ) ;
if ( V_4 )
F_34 ( V_4 -> V_52 ) ;
return 0 ;
}
