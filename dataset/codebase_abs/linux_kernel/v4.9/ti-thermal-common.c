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
V_22 = V_10 -> V_22 ;
V_23 = V_10 -> V_23 ;
V_16 = V_4 -> V_16 ;
if ( ! F_8 ( V_16 ) ) {
V_20 = F_9 ( V_16 , & V_24 ) ;
if ( ! V_20 ) {
V_21 -= V_24 ;
V_22 = V_10 -> V_28 ;
V_23 = V_10 -> V_29 ;
} else {
F_10 ( V_18 -> V_30 ,
L_2 ) ;
V_20 = 0 ;
}
}
* V_14 = F_5 ( V_21 , V_22 , V_23 ) ;
return V_20 ;
}
static inline int F_11 ( struct V_15 * V_31 ,
int * V_14 )
{
struct V_3 * V_4 = V_31 -> V_13 ;
return F_6 ( V_4 , V_14 ) ;
}
static int F_12 ( struct V_15 * V_31 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = V_31 -> V_13 ;
int V_34 ;
if ( ! V_4 || F_8 ( V_4 ) )
return - V_35 ;
if ( V_4 -> V_36 != V_33 )
return 0 ;
V_34 = V_4 -> V_27 ;
return F_13 ( V_31 , 0 , V_33 ,
V_37 ,
V_37 ,
V_38 ) ;
}
static int F_14 ( struct V_15 * V_31 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = V_31 -> V_13 ;
if ( ! V_4 || F_8 ( V_4 ) )
return - V_35 ;
if ( V_4 -> V_36 != V_33 )
return 0 ;
return F_15 ( V_31 , 0 , V_33 ) ;
}
static int F_16 ( struct V_15 * V_31 ,
enum V_39 * V_40 )
{
struct V_3 * V_4 = V_31 -> V_13 ;
if ( V_4 )
* V_40 = V_4 -> V_40 ;
return 0 ;
}
static int F_17 ( struct V_15 * V_31 ,
enum V_39 V_40 )
{
struct V_3 * V_4 = V_31 -> V_13 ;
struct V_17 * V_18 ;
V_18 = V_4 -> V_18 ;
if ( ! V_4 -> V_6 ) {
F_18 ( & V_31 -> V_8 , L_3 ) ;
return 0 ;
}
F_19 ( & V_4 -> V_6 -> V_41 ) ;
if ( V_40 == V_42 )
V_4 -> V_6 -> V_43 = V_44 ;
else
V_4 -> V_6 -> V_43 = 0 ;
F_20 ( & V_4 -> V_6 -> V_41 ) ;
V_4 -> V_40 = V_40 ;
F_21 ( V_18 , V_4 -> V_27 ,
V_4 -> V_6 -> V_43 ) ;
F_3 ( V_4 -> V_6 , V_7 ) ;
F_4 ( & V_31 -> V_8 , L_4 ,
V_4 -> V_6 -> V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_15 * V_31 ,
int V_45 , enum V_46 * type )
{
if ( ! F_23 ( V_45 ) )
return - V_47 ;
if ( V_45 + 1 == V_48 )
* type = V_49 ;
else
* type = V_50 ;
return 0 ;
}
static int F_24 ( struct V_15 * V_31 ,
int V_45 , int * V_14 )
{
if ( ! F_23 ( V_45 ) )
return - V_47 ;
* V_14 = F_25 ( V_45 ) ;
return 0 ;
}
static int F_26 ( void * V_51 , int V_45 , enum V_52 * V_53 )
{
struct V_3 * V_4 = V_51 ;
struct V_17 * V_18 ;
int V_34 , V_54 , V_20 = 0 ;
V_18 = V_4 -> V_18 ;
V_34 = V_4 -> V_27 ;
V_20 = F_27 ( V_18 , V_34 , & V_54 ) ;
if ( V_20 )
return V_20 ;
if ( V_54 > 0 )
* V_53 = V_55 ;
else if ( V_54 < 0 )
* V_53 = V_56 ;
else
* V_53 = V_57 ;
return 0 ;
}
static int F_28 ( struct V_15 * V_31 ,
int V_45 , enum V_52 * V_53 )
{
return F_26 ( V_31 -> V_13 , V_45 , V_53 ) ;
}
static int F_29 ( struct V_15 * V_31 ,
int * V_14 )
{
return F_24 ( V_31 , V_48 - 1 , V_14 ) ;
}
static struct V_3
* F_30 ( struct V_17 * V_18 , int V_34 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_18 -> V_30 , sizeof( * V_4 ) , V_58 ) ;
if ( ! V_4 ) {
F_10 ( V_18 -> V_30 , L_5 ) ;
return NULL ;
}
V_4 -> V_27 = V_34 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_40 = V_42 ;
V_4 -> V_16 = F_32 ( L_6 ) ;
F_33 ( & V_4 -> V_5 , F_1 ) ;
return V_4 ;
}
int F_34 ( struct V_17 * V_18 , int V_34 ,
char * V_59 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_18 , V_34 ) ;
if ( ! V_4 || F_8 ( V_4 ) )
V_4 = F_30 ( V_18 , V_34 ) ;
if ( ! V_4 )
return - V_47 ;
V_4 -> V_6 = F_36 ( V_18 -> V_30 , V_34 ,
V_4 , & V_60 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
V_4 -> V_6 = F_37 ( V_59 ,
V_48 , 0 , V_4 , & V_61 ,
NULL , V_44 ,
V_44 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
F_10 ( V_18 -> V_30 , L_7 ) ;
return F_38 ( V_4 -> V_6 ) ;
}
V_4 -> V_6 -> V_43 = V_44 ;
V_4 -> V_62 = true ;
}
F_39 ( V_18 , V_34 , V_4 ) ;
F_21 ( V_18 , V_4 -> V_27 ,
V_4 -> V_6 -> V_43 ) ;
return 0 ;
}
int F_40 ( struct V_17 * V_18 , int V_34 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_18 , V_34 ) ;
if ( V_4 && V_4 -> V_6 ) {
if ( V_4 -> V_62 )
F_41 ( V_4 -> V_6 ) ;
}
return 0 ;
}
int F_42 ( struct V_17 * V_18 , int V_34 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_18 , V_34 ) ;
F_43 ( & V_4 -> V_5 ) ;
return 0 ;
}
int F_44 ( struct V_17 * V_18 , int V_34 )
{
struct V_3 * V_4 ;
struct V_63 * V_64 = V_18 -> V_30 -> V_65 ;
if ( F_45 ( V_64 , L_8 , NULL ) )
return 0 ;
V_4 = F_35 ( V_18 , V_34 ) ;
if ( ! V_4 || F_8 ( V_4 ) )
V_4 = F_30 ( V_18 , V_34 ) ;
if ( ! V_4 )
return - V_47 ;
V_4 -> V_36 = F_46 ( V_66 ) ;
if ( F_8 ( V_4 -> V_36 ) ) {
int V_20 = F_38 ( V_4 -> V_36 ) ;
if ( V_20 != - V_67 )
F_10 ( V_18 -> V_30 ,
L_9 ,
V_20 ) ;
return V_20 ;
}
F_39 ( V_18 , V_34 , V_4 ) ;
return 0 ;
}
int F_47 ( struct V_17 * V_18 , int V_34 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_18 , V_34 ) ;
if ( V_4 )
F_48 ( V_4 -> V_36 ) ;
return 0 ;
}
