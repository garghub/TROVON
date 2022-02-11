static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_6 -> V_7 , L_1 ,
V_4 -> V_6 -> type ) ;
}
static inline int F_5 ( int V_8 , int V_9 , int V_10 )
{
int V_11 = V_8 * V_9 / 1000 + V_10 ;
if ( V_11 < 0 )
V_11 = 0 ;
return V_8 + V_11 ;
}
static inline int F_6 ( void * V_12 , int * V_13 )
{
struct V_14 * V_15 = NULL ;
struct V_3 * V_4 = V_12 ;
struct V_16 * V_17 ;
const struct V_18 * V_9 ;
int V_19 , V_20 , V_21 , V_22 ;
int V_23 ;
if ( ! V_4 )
return 0 ;
V_17 = V_4 -> V_17 ;
V_9 = & V_17 -> V_24 -> V_25 [ V_4 -> V_26 ] ;
V_19 = F_7 ( V_17 , V_4 -> V_26 , & V_20 ) ;
if ( V_19 )
return V_19 ;
V_21 = V_9 -> V_21 ;
V_22 = V_9 -> V_22 ;
V_15 = V_4 -> V_15 ;
if ( ! F_8 ( V_15 ) ) {
V_19 = F_9 ( V_15 , & V_23 ) ;
if ( ! V_19 ) {
V_20 -= V_23 ;
V_21 = V_9 -> V_27 ;
V_22 = V_9 -> V_28 ;
} else {
F_10 ( V_17 -> V_29 ,
L_2 ) ;
V_19 = 0 ;
}
}
* V_13 = F_5 ( V_20 , V_21 , V_22 ) ;
return V_19 ;
}
static inline int F_11 ( struct V_14 * V_30 ,
int * V_13 )
{
struct V_3 * V_4 = V_30 -> V_12 ;
return F_6 ( V_4 , V_13 ) ;
}
static int F_12 ( struct V_14 * V_30 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_30 -> V_12 ;
int V_33 ;
if ( ! V_4 || F_8 ( V_4 ) )
return - V_34 ;
if ( V_4 -> V_35 != V_32 )
return 0 ;
V_33 = V_4 -> V_26 ;
return F_13 ( V_30 , 0 , V_32 ,
V_36 ,
V_36 ,
V_37 ) ;
}
static int F_14 ( struct V_14 * V_30 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_30 -> V_12 ;
if ( ! V_4 || F_8 ( V_4 ) )
return - V_34 ;
if ( V_4 -> V_35 != V_32 )
return 0 ;
return F_15 ( V_30 , 0 , V_32 ) ;
}
static int F_16 ( struct V_14 * V_30 ,
enum V_38 * V_39 )
{
struct V_3 * V_4 = V_30 -> V_12 ;
if ( V_4 )
* V_39 = V_4 -> V_39 ;
return 0 ;
}
static int F_17 ( struct V_14 * V_30 ,
enum V_38 V_39 )
{
struct V_3 * V_4 = V_30 -> V_12 ;
struct V_16 * V_17 ;
V_17 = V_4 -> V_17 ;
if ( ! V_4 -> V_6 ) {
F_18 ( & V_30 -> V_7 , L_3 ) ;
return 0 ;
}
F_19 ( & V_4 -> V_6 -> V_40 ) ;
if ( V_39 == V_41 )
V_4 -> V_6 -> V_42 = V_43 ;
else
V_4 -> V_6 -> V_42 = 0 ;
F_20 ( & V_4 -> V_6 -> V_40 ) ;
V_4 -> V_39 = V_39 ;
F_21 ( V_17 , V_4 -> V_26 ,
V_4 -> V_6 -> V_42 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( & V_30 -> V_7 , L_4 ,
V_4 -> V_6 -> V_42 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_30 ,
int V_44 , enum V_45 * type )
{
if ( ! F_23 ( V_44 ) )
return - V_46 ;
if ( V_44 + 1 == V_47 )
* type = V_48 ;
else
* type = V_49 ;
return 0 ;
}
static int F_24 ( struct V_14 * V_30 ,
int V_44 , int * V_13 )
{
if ( ! F_23 ( V_44 ) )
return - V_46 ;
* V_13 = F_25 ( V_44 ) ;
return 0 ;
}
static int F_26 ( void * V_50 , long * V_51 )
{
struct V_3 * V_4 = V_50 ;
struct V_16 * V_17 ;
int V_33 , V_52 , V_19 = 0 ;
V_17 = V_4 -> V_17 ;
V_33 = V_4 -> V_26 ;
V_19 = F_27 ( V_17 , V_33 , & V_52 ) ;
if ( V_19 )
return V_19 ;
* V_51 = V_52 ;
return 0 ;
}
static int F_28 ( struct V_14 * V_30 ,
int V_44 , enum V_53 * V_51 )
{
int V_19 ;
long V_52 ;
V_19 = F_26 ( V_30 -> V_12 , & V_52 ) ;
if ( V_19 )
return V_19 ;
if ( V_52 > 0 )
* V_51 = V_54 ;
else if ( V_52 < 0 )
* V_51 = V_55 ;
else
* V_51 = V_56 ;
return 0 ;
}
static int F_29 ( struct V_14 * V_30 ,
int * V_13 )
{
return F_24 ( V_30 , V_47 - 1 , V_13 ) ;
}
static struct V_3
* F_30 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_17 -> V_29 , sizeof( * V_4 ) , V_57 ) ;
if ( ! V_4 ) {
F_10 ( V_17 -> V_29 , L_5 ) ;
return NULL ;
}
V_4 -> V_26 = V_33 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_39 = V_41 ;
V_4 -> V_15 = F_32 ( L_6 ) ;
F_33 ( & V_4 -> V_5 , F_1 ) ;
return V_4 ;
}
int F_34 ( struct V_16 * V_17 , int V_33 ,
char * V_58 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_17 , V_33 ) ;
if ( ! V_4 || F_8 ( V_4 ) )
V_4 = F_30 ( V_17 , V_33 ) ;
if ( ! V_4 )
return - V_46 ;
V_4 -> V_6 = F_36 ( V_17 -> V_29 , V_33 ,
V_4 , & V_59 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
V_4 -> V_6 = F_37 ( V_58 ,
V_47 , 0 , V_4 , & V_60 ,
NULL , V_43 ,
V_43 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
F_10 ( V_17 -> V_29 , L_7 ) ;
return F_38 ( V_4 -> V_6 ) ;
}
V_4 -> V_6 -> V_42 = V_43 ;
V_4 -> V_61 = true ;
}
F_39 ( V_17 , V_33 , V_4 ) ;
F_21 ( V_17 , V_4 -> V_26 ,
V_4 -> V_6 -> V_42 ) ;
return 0 ;
}
int F_40 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_17 , V_33 ) ;
if ( V_4 && V_4 -> V_6 ) {
if ( V_4 -> V_61 )
F_41 ( V_4 -> V_6 ) ;
}
return 0 ;
}
int F_42 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_17 , V_33 ) ;
F_43 ( & V_4 -> V_5 ) ;
return 0 ;
}
int F_44 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
struct V_62 * V_63 = V_17 -> V_29 -> V_64 ;
if ( F_45 ( V_63 , L_8 , NULL ) )
return 0 ;
V_4 = F_35 ( V_17 , V_33 ) ;
if ( ! V_4 || F_8 ( V_4 ) )
V_4 = F_30 ( V_17 , V_33 ) ;
if ( ! V_4 )
return - V_46 ;
V_4 -> V_35 = F_46 ( V_65 ) ;
if ( F_8 ( V_4 -> V_35 ) ) {
int V_19 = F_38 ( V_4 -> V_35 ) ;
if ( V_19 != - V_66 )
F_10 ( V_17 -> V_29 ,
L_9 ,
V_19 ) ;
return V_19 ;
}
F_39 ( V_17 , V_33 , V_4 ) ;
return 0 ;
}
int F_47 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_17 , V_33 ) ;
if ( V_4 )
F_48 ( V_4 -> V_35 ) ;
return 0 ;
}
