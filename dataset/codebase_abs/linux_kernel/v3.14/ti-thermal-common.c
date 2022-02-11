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
static inline int F_6 ( void * V_12 , long * V_13 )
{
struct V_14 * V_15 = NULL ;
struct V_3 * V_4 = V_12 ;
struct V_16 * V_17 ;
const struct V_18 * V_9 ;
int V_19 , V_20 , V_21 , V_22 ;
unsigned long V_23 ;
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
unsigned long * V_13 )
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
V_36 ) ;
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
enum V_37 * V_38 )
{
struct V_3 * V_4 = V_30 -> V_12 ;
if ( V_4 )
* V_38 = V_4 -> V_38 ;
return 0 ;
}
static int F_17 ( struct V_14 * V_30 ,
enum V_37 V_38 )
{
struct V_3 * V_4 = V_30 -> V_12 ;
struct V_16 * V_17 ;
V_17 = V_4 -> V_17 ;
if ( ! V_4 -> V_6 ) {
F_18 ( & V_30 -> V_7 , L_3 ) ;
return 0 ;
}
F_19 ( & V_4 -> V_6 -> V_39 ) ;
if ( V_38 == V_40 )
V_4 -> V_6 -> V_41 = V_42 ;
else
V_4 -> V_6 -> V_41 = 0 ;
F_20 ( & V_4 -> V_6 -> V_39 ) ;
V_4 -> V_38 = V_38 ;
F_21 ( V_17 , V_4 -> V_26 ,
V_4 -> V_6 -> V_41 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( & V_30 -> V_7 , L_4 ,
V_4 -> V_6 -> V_41 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_30 ,
int V_43 , enum V_44 * type )
{
if ( ! F_23 ( V_43 ) )
return - V_45 ;
if ( V_43 + 1 == V_46 )
* type = V_47 ;
else
* type = V_48 ;
return 0 ;
}
static int F_24 ( struct V_14 * V_30 ,
int V_43 , unsigned long * V_13 )
{
if ( ! F_23 ( V_43 ) )
return - V_45 ;
* V_13 = F_25 ( V_43 ) ;
return 0 ;
}
static int F_26 ( void * V_49 , long * V_50 )
{
struct V_3 * V_4 = V_49 ;
struct V_16 * V_17 ;
int V_33 , V_51 , V_19 = 0 ;
V_17 = V_4 -> V_17 ;
V_33 = V_4 -> V_26 ;
V_19 = F_27 ( V_17 , V_33 , & V_51 ) ;
if ( V_19 )
return V_19 ;
* V_50 = V_51 ;
return 0 ;
}
static int F_28 ( struct V_14 * V_30 ,
int V_43 , enum V_52 * V_50 )
{
int V_19 ;
long V_51 ;
V_19 = F_26 ( V_30 -> V_12 , & V_51 ) ;
if ( V_19 )
return V_19 ;
if ( V_51 > 0 )
* V_50 = V_53 ;
else if ( V_51 < 0 )
* V_50 = V_54 ;
else
* V_50 = V_55 ;
return 0 ;
}
static int F_29 ( struct V_14 * V_30 ,
unsigned long * V_13 )
{
return F_24 ( V_30 , V_46 - 1 , V_13 ) ;
}
static struct V_3
* F_30 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_17 -> V_29 , sizeof( * V_4 ) , V_56 ) ;
if ( ! V_4 ) {
F_10 ( V_17 -> V_29 , L_5 ) ;
return NULL ;
}
V_4 -> V_26 = V_33 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_38 = V_40 ;
V_4 -> V_15 = F_32 ( L_6 ) ;
F_33 ( & V_4 -> V_5 , F_1 ) ;
return V_4 ;
}
int F_34 ( struct V_16 * V_17 , int V_33 ,
char * V_57 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_17 , V_33 ) ;
if ( ! V_4 || F_8 ( V_4 ) )
V_4 = F_30 ( V_17 , V_33 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_6 = F_36 ( V_17 -> V_29 , V_33 ,
V_4 , F_6 ,
F_26 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
V_4 -> V_6 = F_37 ( V_57 ,
V_46 , 0 , V_4 , & V_58 ,
NULL , V_42 ,
V_42 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
F_10 ( V_17 -> V_29 , L_7 ) ;
return F_38 ( V_4 -> V_6 ) ;
}
V_4 -> V_6 -> V_41 = V_42 ;
V_4 -> V_59 = true ;
}
F_39 ( V_17 , V_33 , V_4 ) ;
F_21 ( V_17 , V_4 -> V_26 ,
V_4 -> V_6 -> V_41 ) ;
return 0 ;
}
int F_40 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_17 , V_33 ) ;
if ( V_4 && V_4 -> V_6 ) {
if ( V_4 -> V_59 )
F_41 ( V_4 -> V_6 ) ;
else
F_42 ( V_17 -> V_29 ,
V_4 -> V_6 ) ;
}
return 0 ;
}
int F_43 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_17 , V_33 ) ;
F_44 ( & V_4 -> V_5 ) ;
return 0 ;
}
int F_45 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
struct V_60 * V_61 = V_17 -> V_29 -> V_62 ;
if ( F_46 ( V_61 , L_8 , NULL ) )
return 0 ;
V_4 = F_35 ( V_17 , V_33 ) ;
if ( ! V_4 || F_8 ( V_4 ) )
V_4 = F_30 ( V_17 , V_33 ) ;
if ( ! V_4 )
return - V_45 ;
if ( ! F_47 () ) {
F_4 ( V_17 -> V_29 , L_9 ) ;
return - V_63 ;
}
V_4 -> V_35 = F_48 ( V_64 ) ;
if ( F_8 ( V_4 -> V_35 ) ) {
F_10 ( V_17 -> V_29 ,
L_10 ) ;
return F_38 ( V_4 -> V_35 ) ;
}
F_39 ( V_17 , V_33 , V_4 ) ;
return 0 ;
}
int F_49 ( struct V_16 * V_17 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_17 , V_33 ) ;
if ( V_4 && V_4 -> V_35 )
F_50 ( V_4 -> V_35 ) ;
return 0 ;
}
