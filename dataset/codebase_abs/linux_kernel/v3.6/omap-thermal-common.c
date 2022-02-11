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
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_18 * V_9 = & V_17 -> V_19 -> V_20 [ V_4 -> V_21 ] ;
int V_22 , V_23 , V_24 , V_25 , V_26 ;
V_22 = F_7 ( V_17 , V_4 -> V_21 , & V_23 ) ;
if ( V_22 )
return V_22 ;
V_24 = 0 ;
if ( V_24 ) {
V_23 -= V_24 ;
V_25 = V_9 -> V_27 ;
V_26 = V_9 -> V_28 ;
} else {
V_25 = V_9 -> V_25 ;
V_26 = V_9 -> V_26 ;
}
* V_14 = F_5 ( V_23 , V_25 , V_26 ) ;
return V_22 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
int V_31 , V_32 ;
if ( F_9 ( V_4 ) )
return - V_33 ;
if ( V_4 -> V_34 != V_30 )
return 0 ;
V_32 = V_4 -> V_21 ;
V_31 = V_4 -> V_17 -> V_19 -> V_20 [ V_32 ] . V_35 . V_36 ;
return F_10 ( V_13 , 0 , V_30 ) ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
if ( F_9 ( V_4 ) )
return - V_33 ;
if ( V_4 -> V_34 != V_30 )
return 0 ;
return F_12 ( V_13 , 0 , V_30 ) ;
}
static int F_13 ( struct V_12 * V_13 ,
enum V_37 * V_38 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
if ( V_4 )
* V_38 = V_4 -> V_38 ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 ,
enum V_37 V_38 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
if ( ! V_4 -> V_6 ) {
F_15 ( & V_13 -> V_7 , L_2 ) ;
return 0 ;
}
F_16 ( & V_4 -> V_6 -> V_39 ) ;
if ( V_38 == V_40 )
V_4 -> V_6 -> V_41 = V_42 ;
else
V_4 -> V_6 -> V_41 = 0 ;
F_17 ( & V_4 -> V_6 -> V_39 ) ;
V_4 -> V_38 = V_38 ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( & V_13 -> V_7 , L_3 ,
V_4 -> V_6 -> V_41 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
int V_43 , enum V_44 * type )
{
if ( ! F_19 ( V_43 ) )
return - V_45 ;
if ( V_43 + 1 == V_46 )
* type = V_47 ;
else
* type = V_48 ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 ,
int V_43 , unsigned long * V_14 )
{
if ( ! F_19 ( V_43 ) )
return - V_45 ;
* V_14 = F_21 ( V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 ,
unsigned long * V_14 )
{
return F_20 ( V_13 , V_46 - 1 , V_14 ) ;
}
int F_23 ( struct V_16 * V_17 , int V_32 ,
char * V_49 )
{
struct V_3 * V_4 ;
V_4 = F_24 ( V_17 -> V_50 , sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 ) {
F_25 ( V_17 -> V_50 , L_4 ) ;
return - V_52 ;
}
V_4 -> V_21 = V_32 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_38 = V_40 ;
F_26 ( & V_4 -> V_5 , F_1 ) ;
V_4 -> V_6 = F_27 ( V_49 ,
V_46 , 0 , V_4 , & V_53 ,
0 , V_42 , 0 , 0 ) ;
if ( F_9 ( V_4 -> V_6 ) ) {
F_25 ( V_17 -> V_50 , L_5 ) ;
return F_28 ( V_4 -> V_6 ) ;
}
V_4 -> V_6 -> V_41 = V_42 ;
F_29 ( V_17 , V_32 , V_4 ) ;
return 0 ;
}
int F_30 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_17 , V_32 ) ;
F_32 ( V_4 -> V_6 ) ;
return 0 ;
}
int F_33 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_17 , V_32 ) ;
F_34 ( & V_4 -> V_5 ) ;
return 0 ;
}
static int F_35 ( struct V_16 * V_17 ,
struct V_54 * * V_55 ,
int * V_56 )
{
struct V_57 * V_58 ;
struct V_54 * V_59 ;
int V_60 , V_61 = 0 ;
V_58 = F_36 ( 0 ) ;
if ( F_9 ( V_58 ) ) {
F_25 ( V_17 -> V_50 ,
L_6 ,
V_62 , V_58 ) ;
return - V_45 ;
}
for ( V_60 = 0 ; V_58 [ V_60 ] . V_63 != V_64 ; V_60 ++ ) {
unsigned int V_65 = V_58 [ V_60 ] . V_63 ;
if ( V_65 == V_66 )
continue;
V_61 ++ ;
}
V_59 = F_24 ( V_17 -> V_50 , sizeof( * V_59 ) * V_61 , V_51 ) ;
if ( ! V_59 ) {
F_25 ( V_17 -> V_50 ,
L_7 , V_62 ) ;
return - V_52 ;
}
for ( V_60 = 0 ; V_58 [ V_60 ] . V_63 != V_64 ; V_60 ++ ) {
unsigned int V_65 = V_58 [ V_60 ] . V_63 ;
if ( V_65 == V_66 )
continue;
V_59 [ V_61 - V_60 - 1 ] . V_67 = V_65 ;
V_59 [ V_61 - V_60 - 1 ] . V_68 = V_69 ;
V_59 [ V_61 - V_60 - 1 ] . V_70 = F_37 ( 0 ) ;
}
* V_55 = V_59 ;
* V_56 = V_61 ;
return 0 ;
}
int F_38 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
struct V_54 * V_55 ;
int V_56 , V_22 ;
V_4 = F_31 ( V_17 , V_32 ) ;
V_22 = F_35 ( V_17 , & V_55 , & V_56 ) ;
if ( V_22 < 0 ) {
F_25 ( V_17 -> V_50 ,
L_8 , V_62 ) ;
return V_22 ;
}
V_4 -> V_34 = F_39 ( V_55 , V_56 ) ;
if ( F_9 ( V_4 -> V_34 ) ) {
F_25 ( V_17 -> V_50 ,
L_9 ) ;
return F_28 ( V_4 -> V_34 ) ;
}
V_17 -> V_19 -> V_20 [ V_32 ] . V_35 . V_36 = V_56 ;
return 0 ;
}
int F_40 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_17 , V_32 ) ;
F_41 ( V_4 -> V_34 ) ;
return 0 ;
}
