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
static inline int F_6 ( struct V_12 * V_13 ,
unsigned long * V_14 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
struct V_16 * V_17 ;
const struct V_18 * V_9 ;
int V_19 , V_20 , V_21 , V_22 , V_23 ;
if ( ! V_4 )
return 0 ;
V_17 = V_4 -> V_17 ;
V_9 = & V_17 -> V_24 -> V_25 [ V_4 -> V_26 ] ;
V_19 = F_7 ( V_17 , V_4 -> V_26 , & V_20 ) ;
if ( V_19 )
return V_19 ;
V_21 = 0 ;
if ( V_21 ) {
V_20 -= V_21 ;
V_22 = V_9 -> V_27 ;
V_23 = V_9 -> V_28 ;
} else {
V_22 = V_9 -> V_22 ;
V_23 = V_9 -> V_23 ;
}
* V_14 = F_5 ( V_20 , V_22 , V_23 ) ;
return V_19 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
int V_31 ;
if ( F_9 ( V_4 ) )
return - V_32 ;
if ( V_4 -> V_33 != V_30 )
return 0 ;
V_31 = V_4 -> V_26 ;
return F_10 ( V_13 , 0 , V_30 ,
V_34 ,
V_34 ) ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
if ( F_9 ( V_4 ) )
return - V_32 ;
if ( V_4 -> V_33 != V_30 )
return 0 ;
return F_12 ( V_13 , 0 , V_30 ) ;
}
static int F_13 ( struct V_12 * V_13 ,
enum V_35 * V_36 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
if ( V_4 )
* V_36 = V_4 -> V_36 ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 ,
enum V_35 V_36 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
if ( ! V_4 -> V_6 ) {
F_15 ( & V_13 -> V_7 , L_2 ) ;
return 0 ;
}
F_16 ( & V_4 -> V_6 -> V_37 ) ;
if ( V_36 == V_38 )
V_4 -> V_6 -> V_39 = V_40 ;
else
V_4 -> V_6 -> V_39 = 0 ;
F_17 ( & V_4 -> V_6 -> V_37 ) ;
V_4 -> V_36 = V_36 ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( & V_13 -> V_7 , L_3 ,
V_4 -> V_6 -> V_39 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
int V_41 , enum V_42 * type )
{
if ( ! F_19 ( V_41 ) )
return - V_43 ;
if ( V_41 + 1 == V_44 )
* type = V_45 ;
else
* type = V_46 ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 ,
int V_41 , unsigned long * V_14 )
{
if ( ! F_19 ( V_41 ) )
return - V_43 ;
* V_14 = F_21 ( V_41 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 ,
int V_41 , enum V_47 * V_48 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
struct V_16 * V_17 ;
int V_31 , V_49 , V_19 = 0 ;
V_17 = V_4 -> V_17 ;
V_31 = V_4 -> V_26 ;
V_19 = F_23 ( V_17 , V_31 , & V_49 ) ;
if ( V_19 )
return V_19 ;
if ( V_49 > 0 )
* V_48 = V_50 ;
else if ( V_49 < 0 )
* V_48 = V_51 ;
else
* V_48 = V_52 ;
return 0 ;
}
static int F_24 ( struct V_12 * V_13 ,
unsigned long * V_14 )
{
return F_20 ( V_13 , V_44 - 1 , V_14 ) ;
}
static struct V_3
* F_25 ( struct V_16 * V_17 , int V_31 )
{
struct V_3 * V_4 ;
V_4 = F_26 ( V_17 -> V_53 , sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 ) {
F_27 ( V_17 -> V_53 , L_4 ) ;
return NULL ;
}
V_4 -> V_26 = V_31 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_36 = V_38 ;
F_28 ( & V_4 -> V_5 , F_1 ) ;
return V_4 ;
}
int F_29 ( struct V_16 * V_17 , int V_31 ,
char * V_55 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_17 , V_31 ) ;
if ( F_9 ( V_4 ) )
V_4 = F_25 ( V_17 , V_31 ) ;
if ( ! V_4 )
return - V_43 ;
V_4 -> V_6 = F_31 ( V_55 ,
V_44 , 0 , V_4 , & V_56 ,
NULL , V_40 ,
V_40 ) ;
if ( F_9 ( V_4 -> V_6 ) ) {
F_27 ( V_17 -> V_53 , L_5 ) ;
return F_32 ( V_4 -> V_6 ) ;
}
V_4 -> V_6 -> V_39 = V_40 ;
F_33 ( V_17 , V_31 , V_4 ) ;
return 0 ;
}
int F_34 ( struct V_16 * V_17 , int V_31 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_17 , V_31 ) ;
F_35 ( V_4 -> V_6 ) ;
return 0 ;
}
int F_36 ( struct V_16 * V_17 , int V_31 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_17 , V_31 ) ;
F_37 ( & V_4 -> V_5 ) ;
return 0 ;
}
int F_38 ( struct V_16 * V_17 , int V_31 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_17 , V_31 ) ;
if ( F_9 ( V_4 ) )
V_4 = F_25 ( V_17 , V_31 ) ;
if ( ! V_4 )
return - V_43 ;
if ( ! F_39 () ) {
F_4 ( V_17 -> V_53 , L_6 ) ;
return - V_57 ;
}
V_4 -> V_33 = F_40 ( V_58 ) ;
if ( F_9 ( V_4 -> V_33 ) ) {
F_27 ( V_17 -> V_53 ,
L_7 ) ;
return F_32 ( V_4 -> V_33 ) ;
}
F_33 ( V_17 , V_31 , V_4 ) ;
return 0 ;
}
int F_41 ( struct V_16 * V_17 , int V_31 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_17 , V_31 ) ;
F_42 ( V_4 -> V_33 ) ;
return 0 ;
}
