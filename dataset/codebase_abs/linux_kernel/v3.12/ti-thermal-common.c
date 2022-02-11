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
struct V_12 * V_15 = NULL ;
struct V_3 * V_4 = V_13 -> V_16 ;
struct V_17 * V_18 ;
const struct V_19 * V_9 ;
int V_20 , V_21 , V_22 , V_23 ;
unsigned long V_24 ;
if ( ! V_4 )
return 0 ;
V_18 = V_4 -> V_18 ;
V_9 = & V_18 -> V_25 -> V_26 [ V_4 -> V_27 ] ;
V_20 = F_7 ( V_18 , V_4 -> V_27 , & V_21 ) ;
if ( V_20 )
return V_20 ;
V_22 = V_9 -> V_22 ;
V_23 = V_9 -> V_23 ;
V_15 = V_4 -> V_15 ;
if ( ! F_8 ( V_15 ) ) {
V_20 = F_9 ( V_15 , & V_24 ) ;
if ( ! V_20 ) {
V_21 -= V_24 ;
V_22 = V_9 -> V_28 ;
V_23 = V_9 -> V_29 ;
} else {
F_10 ( V_18 -> V_30 ,
L_2 ) ;
V_20 = 0 ;
}
}
* V_14 = F_5 ( V_21 , V_22 , V_23 ) ;
return V_20 ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_13 -> V_16 ;
int V_33 ;
if ( ! V_4 || F_8 ( V_4 ) )
return - V_34 ;
if ( V_4 -> V_35 != V_32 )
return 0 ;
V_33 = V_4 -> V_27 ;
return F_12 ( V_13 , 0 , V_32 ,
V_36 ,
V_36 ) ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = V_13 -> V_16 ;
if ( ! V_4 || F_8 ( V_4 ) )
return - V_34 ;
if ( V_4 -> V_35 != V_32 )
return 0 ;
return F_14 ( V_13 , 0 , V_32 ) ;
}
static int F_15 ( struct V_12 * V_13 ,
enum V_37 * V_38 )
{
struct V_3 * V_4 = V_13 -> V_16 ;
if ( V_4 )
* V_38 = V_4 -> V_38 ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 ,
enum V_37 V_38 )
{
struct V_3 * V_4 = V_13 -> V_16 ;
struct V_17 * V_18 ;
V_18 = V_4 -> V_18 ;
if ( ! V_4 -> V_6 ) {
F_17 ( & V_13 -> V_7 , L_3 ) ;
return 0 ;
}
F_18 ( & V_4 -> V_6 -> V_39 ) ;
if ( V_38 == V_40 )
V_4 -> V_6 -> V_41 = V_42 ;
else
V_4 -> V_6 -> V_41 = 0 ;
F_19 ( & V_4 -> V_6 -> V_39 ) ;
V_4 -> V_38 = V_38 ;
F_20 ( V_18 , V_4 -> V_27 ,
V_4 -> V_6 -> V_41 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( & V_13 -> V_7 , L_4 ,
V_4 -> V_6 -> V_41 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 ,
int V_43 , enum V_44 * type )
{
if ( ! F_22 ( V_43 ) )
return - V_45 ;
if ( V_43 + 1 == V_46 )
* type = V_47 ;
else
* type = V_48 ;
return 0 ;
}
static int F_23 ( struct V_12 * V_13 ,
int V_43 , unsigned long * V_14 )
{
if ( ! F_22 ( V_43 ) )
return - V_45 ;
* V_14 = F_24 ( V_43 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 ,
int V_43 , enum V_49 * V_50 )
{
struct V_3 * V_4 = V_13 -> V_16 ;
struct V_17 * V_18 ;
int V_33 , V_51 , V_20 = 0 ;
V_18 = V_4 -> V_18 ;
V_33 = V_4 -> V_27 ;
V_20 = F_26 ( V_18 , V_33 , & V_51 ) ;
if ( V_20 )
return V_20 ;
if ( V_51 > 0 )
* V_50 = V_52 ;
else if ( V_51 < 0 )
* V_50 = V_53 ;
else
* V_50 = V_54 ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 ,
unsigned long * V_14 )
{
return F_23 ( V_13 , V_46 - 1 , V_14 ) ;
}
static struct V_3
* F_28 ( struct V_17 * V_18 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_29 ( V_18 -> V_30 , sizeof( * V_4 ) , V_55 ) ;
if ( ! V_4 ) {
F_10 ( V_18 -> V_30 , L_5 ) ;
return NULL ;
}
V_4 -> V_27 = V_33 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_38 = V_40 ;
V_4 -> V_15 = F_30 ( L_6 ) ;
F_31 ( & V_4 -> V_5 , F_1 ) ;
return V_4 ;
}
int F_32 ( struct V_17 * V_18 , int V_33 ,
char * V_56 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_18 , V_33 ) ;
if ( ! V_4 || F_8 ( V_4 ) )
V_4 = F_28 ( V_18 , V_33 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_6 = F_34 ( V_56 ,
V_46 , 0 , V_4 , & V_57 ,
NULL , V_42 ,
V_42 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
F_10 ( V_18 -> V_30 , L_7 ) ;
return F_35 ( V_4 -> V_6 ) ;
}
V_4 -> V_6 -> V_41 = V_42 ;
F_36 ( V_18 , V_33 , V_4 ) ;
F_20 ( V_18 , V_4 -> V_27 ,
V_4 -> V_6 -> V_41 ) ;
return 0 ;
}
int F_37 ( struct V_17 * V_18 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_18 , V_33 ) ;
F_38 ( V_4 -> V_6 ) ;
return 0 ;
}
int F_39 ( struct V_17 * V_18 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_18 , V_33 ) ;
F_40 ( & V_4 -> V_5 ) ;
return 0 ;
}
int F_41 ( struct V_17 * V_18 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_18 , V_33 ) ;
if ( ! V_4 || F_8 ( V_4 ) )
V_4 = F_28 ( V_18 , V_33 ) ;
if ( ! V_4 )
return - V_45 ;
if ( ! F_42 () ) {
F_4 ( V_18 -> V_30 , L_8 ) ;
return - V_58 ;
}
V_4 -> V_35 = F_43 ( V_59 ) ;
if ( F_8 ( V_4 -> V_35 ) ) {
F_10 ( V_18 -> V_30 ,
L_9 ) ;
return F_35 ( V_4 -> V_35 ) ;
}
F_36 ( V_18 , V_33 , V_4 ) ;
return 0 ;
}
int F_44 ( struct V_17 * V_18 , int V_33 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_18 , V_33 ) ;
F_45 ( V_4 -> V_35 ) ;
return 0 ;
}
