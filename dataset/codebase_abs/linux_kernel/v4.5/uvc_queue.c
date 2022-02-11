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
unsigned int V_19 [] , void * V_20 [] )
{
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
unsigned V_22 = V_21 -> V_23 . V_24 ;
if ( * V_18 )
return V_19 [ 0 ] < V_22 ? - V_25 : 0 ;
* V_18 = 1 ;
V_19 [ 0 ] = V_22 ;
return 0 ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_11 ( V_27 ) ;
struct V_2 * V_3 = F_9 ( V_27 -> V_15 ) ;
struct V_12 * V_13 = F_2 ( V_29 , struct V_12 , V_13 ) ;
if ( V_27 -> type == V_30 &&
F_12 ( V_27 , 0 ) > F_13 ( V_27 , 0 ) ) {
F_14 ( V_31 , L_1 ) ;
return - V_25 ;
}
if ( F_15 ( V_3 -> V_32 & V_33 ) )
return - V_34 ;
V_13 -> V_5 = V_35 ;
V_13 -> error = 0 ;
V_13 -> V_36 = F_16 ( V_27 , 0 ) ;
V_13 -> V_37 = F_13 ( V_27 , 0 ) ;
if ( V_27 -> type == V_38 )
V_13 -> V_39 = 0 ;
else
V_13 -> V_39 = F_12 ( V_27 , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_11 ( V_27 ) ;
struct V_2 * V_3 = F_9 ( V_27 -> V_15 ) ;
struct V_12 * V_13 = F_2 ( V_29 , struct V_12 , V_13 ) ;
unsigned long V_32 ;
F_18 ( & V_3 -> V_40 , V_32 ) ;
if ( F_19 ( ! ( V_3 -> V_32 & V_33 ) ) ) {
F_20 ( & V_13 -> V_3 , & V_3 -> V_11 ) ;
} else {
V_13 -> V_5 = V_8 ;
F_7 ( V_27 , V_9 ) ;
}
F_21 ( & V_3 -> V_40 , V_32 ) ;
}
static void F_22 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_11 ( V_27 ) ;
struct V_2 * V_3 = F_9 ( V_27 -> V_15 ) ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_2 ( V_29 , struct V_12 , V_13 ) ;
if ( V_27 -> V_5 == V_41 )
F_23 ( V_21 , V_29 , V_13 ) ;
}
static int F_24 ( struct V_15 * V_16 , unsigned int V_42 )
{
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
unsigned long V_32 ;
int V_43 ;
V_3 -> V_44 = 0 ;
V_43 = F_25 ( V_21 , 1 ) ;
if ( V_43 == 0 )
return 0 ;
F_18 ( & V_3 -> V_40 , V_32 ) ;
F_3 ( V_3 , V_35 ) ;
F_21 ( & V_3 -> V_40 , V_32 ) ;
return V_43 ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
unsigned long V_32 ;
F_25 ( V_21 , 0 ) ;
F_18 ( & V_3 -> V_40 , V_32 ) ;
F_3 ( V_3 , V_8 ) ;
F_21 ( & V_3 -> V_40 , V_32 ) ;
}
int F_27 ( struct V_2 * V_3 , enum V_45 type ,
int V_46 )
{
int V_43 ;
V_3 -> V_3 . type = type ;
V_3 -> V_3 . V_47 = V_48 | V_49 | V_50 ;
V_3 -> V_3 . V_51 = V_3 ;
V_3 -> V_3 . V_52 = sizeof( struct V_12 ) ;
V_3 -> V_3 . V_53 = & V_54 ;
V_3 -> V_3 . V_55 = & V_56 ;
V_3 -> V_3 . V_57 = V_58
| V_59 ;
V_3 -> V_3 . V_60 = & V_3 -> V_61 ;
V_43 = F_28 ( & V_3 -> V_3 ) ;
if ( V_43 )
return V_43 ;
F_29 ( & V_3 -> V_61 ) ;
F_30 ( & V_3 -> V_40 ) ;
F_31 ( & V_3 -> V_11 ) ;
V_3 -> V_32 = V_46 ? V_62 : 0 ;
return 0 ;
}
void F_32 ( struct V_2 * V_3 )
{
F_33 ( & V_3 -> V_61 ) ;
F_34 ( & V_3 -> V_3 ) ;
F_35 ( & V_3 -> V_61 ) ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_63 * V_64 )
{
int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_37 ( & V_3 -> V_3 , V_64 ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ? V_43 : V_64 -> V_42 ;
}
int F_38 ( struct V_2 * V_3 , struct V_65 * V_13 )
{
int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_39 ( & V_3 -> V_3 , V_13 ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ;
}
int F_40 ( struct V_2 * V_3 ,
struct V_66 * V_67 )
{
int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_41 ( & V_3 -> V_3 , V_67 ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ;
}
int F_42 ( struct V_2 * V_3 , struct V_65 * V_13 )
{
int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_43 ( & V_3 -> V_3 , V_13 ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ;
}
int F_44 ( struct V_2 * V_3 ,
struct V_68 * exp )
{
int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_45 ( & V_3 -> V_3 , exp ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ;
}
int F_46 ( struct V_2 * V_3 , struct V_65 * V_13 ,
int V_69 )
{
int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_47 ( & V_3 -> V_3 , V_13 , V_69 ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ;
}
int F_48 ( struct V_2 * V_3 , enum V_45 type )
{
int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_49 ( & V_3 -> V_3 , type ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ;
}
int F_50 ( struct V_2 * V_3 , enum V_45 type )
{
int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_51 ( & V_3 -> V_3 , type ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ;
}
int F_52 ( struct V_2 * V_3 , struct V_70 * V_71 )
{
return F_53 ( & V_3 -> V_3 , V_71 ) ;
}
unsigned long F_54 ( struct V_2 * V_3 ,
unsigned long V_72 )
{
return F_55 ( & V_3 -> V_3 , 0 , 0 , V_72 , 0 ) ;
}
unsigned int F_56 ( struct V_2 * V_3 , struct V_73 * V_73 ,
T_1 * V_74 )
{
unsigned int V_43 ;
F_33 ( & V_3 -> V_61 ) ;
V_43 = F_57 ( & V_3 -> V_3 , V_73 , V_74 ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_43 ;
}
int F_58 ( struct V_2 * V_3 )
{
int V_75 ;
F_33 ( & V_3 -> V_61 ) ;
V_75 = F_59 ( & V_3 -> V_3 ) ;
F_35 ( & V_3 -> V_61 ) ;
return V_75 ;
}
void F_60 ( struct V_2 * V_3 , int V_76 )
{
unsigned long V_32 ;
F_18 ( & V_3 -> V_40 , V_32 ) ;
F_3 ( V_3 , V_8 ) ;
if ( V_76 )
V_3 -> V_32 |= V_33 ;
F_21 ( & V_3 -> V_40 , V_32 ) ;
}
struct V_12 * F_61 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_12 * V_77 ;
unsigned long V_32 ;
if ( ( V_3 -> V_32 & V_62 ) && V_13 -> error ) {
V_13 -> error = 0 ;
V_13 -> V_5 = V_35 ;
V_13 -> V_39 = 0 ;
F_62 ( & V_13 -> V_13 . V_14 , 0 , 0 ) ;
return V_13 ;
}
F_18 ( & V_3 -> V_40 , V_32 ) ;
F_6 ( & V_13 -> V_3 ) ;
if ( ! F_4 ( & V_3 -> V_11 ) )
V_77 = F_5 ( & V_3 -> V_11 , struct V_12 ,
V_3 ) ;
else
V_77 = NULL ;
F_21 ( & V_3 -> V_40 , V_32 ) ;
V_13 -> V_5 = V_13 -> error ? V_9 : V_78 ;
F_62 ( & V_13 -> V_13 . V_14 , 0 , V_13 -> V_39 ) ;
F_7 ( & V_13 -> V_13 . V_14 , V_41 ) ;
return V_77 ;
}
