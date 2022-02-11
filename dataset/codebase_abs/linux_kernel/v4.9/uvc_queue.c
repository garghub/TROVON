static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
enum V_6 V_7 = V_5 == V_8
? V_9
: V_10 ;
while ( ! F_4 ( & V_3 -> V_11 ) ) {
struct V_12 * V_13 = F_5 ( & V_3 -> V_11 ,
struct V_12 ,
V_3 ) ;
F_6 ( & V_13 -> V_3 ) ;
V_13 -> V_5 = V_5 ;
F_7 ( & V_13 -> V_13 . V_14 , V_7 ) ;
}
}
static int F_8 ( struct V_15 * V_16 ,
unsigned int * V_17 , unsigned int * V_18 ,
unsigned int V_19 [] , struct V_20 * V_21 [] )
{
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned V_23 = V_22 -> V_24 . V_25 ;
if ( * V_18 )
return V_19 [ 0 ] < V_23 ? - V_26 : 0 ;
* V_18 = 1 ;
V_19 [ 0 ] = V_23 ;
return 0 ;
}
static int F_10 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_11 ( V_28 ) ;
struct V_2 * V_3 = F_9 ( V_28 -> V_15 ) ;
struct V_12 * V_13 = F_2 ( V_30 , struct V_12 , V_13 ) ;
if ( V_28 -> type == V_31 &&
F_12 ( V_28 , 0 ) > F_13 ( V_28 , 0 ) ) {
F_14 ( V_32 , L_1 ) ;
return - V_26 ;
}
if ( F_15 ( V_3 -> V_33 & V_34 ) )
return - V_35 ;
V_13 -> V_5 = V_36 ;
V_13 -> error = 0 ;
V_13 -> V_37 = F_16 ( V_28 , 0 ) ;
V_13 -> V_38 = F_13 ( V_28 , 0 ) ;
if ( V_28 -> type == V_39 )
V_13 -> V_40 = 0 ;
else
V_13 -> V_40 = F_12 ( V_28 , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_11 ( V_28 ) ;
struct V_2 * V_3 = F_9 ( V_28 -> V_15 ) ;
struct V_12 * V_13 = F_2 ( V_30 , struct V_12 , V_13 ) ;
unsigned long V_33 ;
F_18 ( & V_3 -> V_41 , V_33 ) ;
if ( F_19 ( ! ( V_3 -> V_33 & V_34 ) ) ) {
F_20 ( & V_13 -> V_3 , & V_3 -> V_11 ) ;
} else {
V_13 -> V_5 = V_8 ;
F_7 ( V_28 , V_9 ) ;
}
F_21 ( & V_3 -> V_41 , V_33 ) ;
}
static void F_22 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_11 ( V_28 ) ;
struct V_2 * V_3 = F_9 ( V_28 -> V_15 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_2 ( V_30 , struct V_12 , V_13 ) ;
if ( V_28 -> V_5 == V_42 )
F_23 ( V_22 , V_30 , V_13 ) ;
}
static int F_24 ( struct V_15 * V_16 , unsigned int V_43 )
{
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned long V_33 ;
int V_44 ;
V_3 -> V_45 = 0 ;
V_44 = F_25 ( V_22 , 1 ) ;
if ( V_44 == 0 )
return 0 ;
F_18 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_36 ) ;
F_21 ( & V_3 -> V_41 , V_33 ) ;
return V_44 ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned long V_33 ;
F_25 ( V_22 , 0 ) ;
F_18 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_8 ) ;
F_21 ( & V_3 -> V_41 , V_33 ) ;
}
int F_27 ( struct V_2 * V_3 , enum V_46 type ,
int V_47 )
{
int V_44 ;
V_3 -> V_3 . type = type ;
V_3 -> V_3 . V_48 = V_49 | V_50 | V_51 ;
V_3 -> V_3 . V_52 = V_3 ;
V_3 -> V_3 . V_53 = sizeof( struct V_12 ) ;
V_3 -> V_3 . V_54 = & V_55 ;
V_3 -> V_3 . V_56 = & V_57 ;
V_3 -> V_3 . V_58 = V_59
| V_60 ;
V_3 -> V_3 . V_61 = & V_3 -> V_62 ;
V_44 = F_28 ( & V_3 -> V_3 ) ;
if ( V_44 )
return V_44 ;
F_29 ( & V_3 -> V_62 ) ;
F_30 ( & V_3 -> V_41 ) ;
F_31 ( & V_3 -> V_11 ) ;
V_3 -> V_33 = V_47 ? V_63 : 0 ;
return 0 ;
}
void F_32 ( struct V_2 * V_3 )
{
F_33 ( & V_3 -> V_62 ) ;
F_34 ( & V_3 -> V_3 ) ;
F_35 ( & V_3 -> V_62 ) ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_64 * V_65 )
{
int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_37 ( & V_3 -> V_3 , V_65 ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ? V_44 : V_65 -> V_43 ;
}
int F_38 ( struct V_2 * V_3 , struct V_66 * V_13 )
{
int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_39 ( & V_3 -> V_3 , V_13 ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_40 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_41 ( & V_3 -> V_3 , V_68 ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_42 ( struct V_2 * V_3 , struct V_66 * V_13 )
{
int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_43 ( & V_3 -> V_3 , V_13 ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_44 ( struct V_2 * V_3 ,
struct V_69 * exp )
{
int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_45 ( & V_3 -> V_3 , exp ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_46 ( struct V_2 * V_3 , struct V_66 * V_13 ,
int V_70 )
{
int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_47 ( & V_3 -> V_3 , V_13 , V_70 ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_48 ( struct V_2 * V_3 , enum V_46 type )
{
int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_49 ( & V_3 -> V_3 , type ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_50 ( struct V_2 * V_3 , enum V_46 type )
{
int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_51 ( & V_3 -> V_3 , type ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_52 ( struct V_2 * V_3 , struct V_71 * V_72 )
{
return F_53 ( & V_3 -> V_3 , V_72 ) ;
}
unsigned long F_54 ( struct V_2 * V_3 ,
unsigned long V_73 )
{
return F_55 ( & V_3 -> V_3 , 0 , 0 , V_73 , 0 ) ;
}
unsigned int F_56 ( struct V_2 * V_3 , struct V_74 * V_74 ,
T_1 * V_75 )
{
unsigned int V_44 ;
F_33 ( & V_3 -> V_62 ) ;
V_44 = F_57 ( & V_3 -> V_3 , V_74 , V_75 ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_58 ( struct V_2 * V_3 )
{
int V_76 ;
F_33 ( & V_3 -> V_62 ) ;
V_76 = F_59 ( & V_3 -> V_3 ) ;
F_35 ( & V_3 -> V_62 ) ;
return V_76 ;
}
void F_60 ( struct V_2 * V_3 , int V_77 )
{
unsigned long V_33 ;
F_18 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_8 ) ;
if ( V_77 )
V_3 -> V_33 |= V_34 ;
F_21 ( & V_3 -> V_41 , V_33 ) ;
}
struct V_12 * F_61 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_12 * V_78 ;
unsigned long V_33 ;
if ( ( V_3 -> V_33 & V_63 ) && V_13 -> error ) {
V_13 -> error = 0 ;
V_13 -> V_5 = V_36 ;
V_13 -> V_40 = 0 ;
F_62 ( & V_13 -> V_13 . V_14 , 0 , 0 ) ;
return V_13 ;
}
F_18 ( & V_3 -> V_41 , V_33 ) ;
F_6 ( & V_13 -> V_3 ) ;
if ( ! F_4 ( & V_3 -> V_11 ) )
V_78 = F_5 ( & V_3 -> V_11 , struct V_12 ,
V_3 ) ;
else
V_78 = NULL ;
F_21 ( & V_3 -> V_41 , V_33 ) ;
V_13 -> V_5 = V_13 -> error ? V_9 : V_79 ;
F_62 ( & V_13 -> V_13 . V_14 , 0 , V_13 -> V_40 ) ;
F_7 ( & V_13 -> V_13 . V_14 , V_42 ) ;
return V_78 ;
}
