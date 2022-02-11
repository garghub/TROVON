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
struct V_18 * V_9 ;
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
int V_31 , V_32 ;
if ( F_9 ( V_4 ) )
return - V_33 ;
if ( V_4 -> V_34 != V_30 )
return 0 ;
V_32 = V_4 -> V_26 ;
V_31 = V_4 -> V_17 -> V_24 -> V_25 [ V_32 ] . V_35 . V_36 ;
return F_10 ( V_13 , 0 , V_30 ,
V_37 ,
V_37 ) ;
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
enum V_38 * V_39 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
if ( V_4 )
* V_39 = V_4 -> V_39 ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 ,
enum V_38 V_39 )
{
struct V_3 * V_4 = V_13 -> V_15 ;
if ( ! V_4 -> V_6 ) {
F_15 ( & V_13 -> V_7 , L_2 ) ;
return 0 ;
}
F_16 ( & V_4 -> V_6 -> V_40 ) ;
if ( V_39 == V_41 )
V_4 -> V_6 -> V_42 = V_43 ;
else
V_4 -> V_6 -> V_42 = 0 ;
F_17 ( & V_4 -> V_6 -> V_40 ) ;
V_4 -> V_39 = V_39 ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( & V_13 -> V_7 , L_3 ,
V_4 -> V_6 -> V_42 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
int V_44 , enum V_45 * type )
{
if ( ! F_19 ( V_44 ) )
return - V_46 ;
if ( V_44 + 1 == V_47 )
* type = V_48 ;
else
* type = V_49 ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 ,
int V_44 , unsigned long * V_14 )
{
if ( ! F_19 ( V_44 ) )
return - V_46 ;
* V_14 = F_21 ( V_44 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 ,
unsigned long * V_14 )
{
return F_20 ( V_13 , V_47 - 1 , V_14 ) ;
}
static struct V_3
* F_23 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
V_4 = F_24 ( V_17 -> V_50 , sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 ) {
F_25 ( V_17 -> V_50 , L_4 ) ;
return NULL ;
}
V_4 -> V_26 = V_32 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_39 = V_41 ;
F_26 ( & V_4 -> V_5 , F_1 ) ;
return V_4 ;
}
int F_27 ( struct V_16 * V_17 , int V_32 ,
char * V_52 )
{
struct V_53 V_54 ;
V_4 = F_28 ( V_17 , V_32 ) ;
if ( ! V_4 )
V_4 = F_29 ( V_17 , V_32 ) ;
if ( ! V_4 )
return - V_46 ;
V_4 -> V_6 = F_30 ( V_52 ,
V_47 , 0 , V_4 , & V_55 ,
V_43 ,
V_43 ) ;
if ( F_9 ( V_4 -> V_6 ) ) {
F_25 ( V_17 -> V_50 , L_5 ) ;
return F_31 ( V_4 -> V_6 ) ;
}
V_4 -> V_6 -> V_42 = V_43 ;
F_32 ( V_17 , V_32 , V_4 ) ;
return 0 ;
}
int F_33 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( V_17 , V_32 ) ;
F_34 ( V_4 -> V_6 ) ;
return 0 ;
}
int F_35 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( V_17 , V_32 ) ;
F_36 ( & V_4 -> V_5 ) ;
return 0 ;
}
static int F_37 ( struct V_16 * V_17 ,
struct V_56 * * V_57 ,
int * V_58 )
{
struct V_59 * V_60 ;
struct V_56 * V_61 ;
int V_62 , V_63 = 0 ;
V_60 = F_38 ( 0 ) ;
if ( F_9 ( V_60 ) ) {
F_25 ( V_17 -> V_50 ,
L_6 ,
V_64 , V_60 ) ;
return - V_46 ;
}
for ( V_62 = 0 ; V_60 [ V_62 ] . V_65 != V_66 ; V_62 ++ ) {
unsigned int V_67 = V_60 [ V_62 ] . V_65 ;
if ( V_67 == V_68 )
continue;
V_63 ++ ;
}
V_61 = F_24 ( V_17 -> V_50 , sizeof( * V_61 ) * V_63 , V_51 ) ;
if ( ! V_61 ) {
F_25 ( V_17 -> V_50 ,
L_7 , V_64 ) ;
return - V_69 ;
}
for ( V_62 = 0 ; V_60 [ V_62 ] . V_65 != V_66 ; V_62 ++ ) {
unsigned int V_67 = V_60 [ V_62 ] . V_65 ;
if ( V_67 == V_68 )
continue;
V_61 [ V_63 - V_62 - 1 ] . V_70 = V_67 ;
V_61 [ V_63 - V_62 - 1 ] . V_71 = V_72 ;
V_61 [ V_63 - V_62 - 1 ] . V_73 = F_39 ( 0 ) ;
}
* V_57 = V_61 ;
* V_58 = V_63 ;
return 0 ;
}
int F_40 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
struct V_56 * V_57 ;
int V_58 , V_19 ;
V_4 = F_28 ( V_17 , V_32 ) ;
if ( ! V_4 )
V_4 = F_29 ( V_17 , V_32 ) ;
if ( ! V_4 )
return - V_46 ;
V_19 = F_37 ( V_17 , & V_57 , & V_58 ) ;
if ( V_19 < 0 ) {
F_25 ( V_17 -> V_50 ,
L_8 , V_64 ) ;
return V_19 ;
}
V_4 -> V_34 = F_41 ( V_57 , V_58 ) ;
if ( F_9 ( V_4 -> V_34 ) ) {
F_25 ( V_17 -> V_50 ,
L_9 ) ;
return F_31 ( V_4 -> V_34 ) ;
}
V_17 -> V_24 -> V_25 [ V_32 ] . V_35 . V_36 = V_58 ;
F_32 ( V_17 , V_32 , V_4 ) ;
return 0 ;
}
int F_42 ( struct V_16 * V_17 , int V_32 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( V_17 , V_32 ) ;
F_43 ( V_4 -> V_34 ) ;
return 0 ;
}
