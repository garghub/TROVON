static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_6 ) ;
}
static void F_4 ( struct V_2 * V_3 ,
enum V_7 V_8 )
{
enum V_9 V_10 = V_8 == V_11
? V_12
: V_13 ;
while ( ! F_5 ( & V_3 -> V_14 ) ) {
struct V_4 * V_6 = F_6 ( & V_3 -> V_14 ,
struct V_4 ,
V_3 ) ;
F_7 ( & V_6 -> V_3 ) ;
V_6 -> V_8 = V_8 ;
F_8 ( & V_6 -> V_6 . V_15 , V_10 ) ;
}
}
static int F_9 ( struct V_16 * V_17 ,
unsigned int * V_18 , unsigned int * V_19 ,
unsigned int V_20 [] , struct V_21 * V_22 [] )
{
struct V_2 * V_3 = F_10 ( V_17 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
unsigned V_24 = V_23 -> V_25 . V_26 ;
if ( * V_19 )
return V_20 [ 0 ] < V_24 ? - V_27 : 0 ;
* V_19 = 1 ;
V_20 [ 0 ] = V_24 ;
return 0 ;
}
static int F_11 ( struct V_28 * V_29 )
{
struct V_5 * V_30 = F_12 ( V_29 ) ;
struct V_2 * V_3 = F_10 ( V_29 -> V_16 ) ;
struct V_4 * V_6 = F_3 ( V_30 ) ;
if ( V_29 -> type == V_31 &&
F_13 ( V_29 , 0 ) > F_14 ( V_29 , 0 ) ) {
F_15 ( V_32 , L_1 ) ;
return - V_27 ;
}
if ( F_16 ( V_3 -> V_33 & V_34 ) )
return - V_35 ;
V_6 -> V_8 = V_36 ;
V_6 -> error = 0 ;
V_6 -> V_37 = F_17 ( V_29 , 0 ) ;
V_6 -> V_38 = F_14 ( V_29 , 0 ) ;
if ( V_29 -> type == V_39 )
V_6 -> V_40 = 0 ;
else
V_6 -> V_40 = F_13 ( V_29 , 0 ) ;
return 0 ;
}
static void F_18 ( struct V_28 * V_29 )
{
struct V_5 * V_30 = F_12 ( V_29 ) ;
struct V_2 * V_3 = F_10 ( V_29 -> V_16 ) ;
struct V_4 * V_6 = F_3 ( V_30 ) ;
unsigned long V_33 ;
F_19 ( & V_3 -> V_41 , V_33 ) ;
if ( F_20 ( ! ( V_3 -> V_33 & V_34 ) ) ) {
F_21 ( & V_6 -> V_3 , & V_3 -> V_14 ) ;
} else {
V_6 -> V_8 = V_11 ;
F_8 ( V_29 , V_12 ) ;
}
F_22 ( & V_3 -> V_41 , V_33 ) ;
}
static void F_23 ( struct V_28 * V_29 )
{
struct V_5 * V_30 = F_12 ( V_29 ) ;
struct V_2 * V_3 = F_10 ( V_29 -> V_16 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_30 ) ;
if ( V_29 -> V_8 == V_42 )
F_24 ( V_23 , V_30 , V_6 ) ;
}
static int F_25 ( struct V_16 * V_17 , unsigned int V_43 )
{
struct V_2 * V_3 = F_10 ( V_17 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
unsigned long V_33 ;
int V_44 ;
V_3 -> V_45 = 0 ;
V_44 = F_26 ( V_23 , 1 ) ;
if ( V_44 == 0 )
return 0 ;
F_19 ( & V_3 -> V_41 , V_33 ) ;
F_4 ( V_3 , V_36 ) ;
F_22 ( & V_3 -> V_41 , V_33 ) ;
return V_44 ;
}
static void F_27 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = F_10 ( V_17 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
unsigned long V_33 ;
F_26 ( V_23 , 0 ) ;
F_19 ( & V_3 -> V_41 , V_33 ) ;
F_4 ( V_3 , V_11 ) ;
F_22 ( & V_3 -> V_41 , V_33 ) ;
}
int F_28 ( struct V_2 * V_3 , enum V_46 type ,
int V_47 )
{
int V_44 ;
V_3 -> V_3 . type = type ;
V_3 -> V_3 . V_48 = V_49 | V_50 | V_51 ;
V_3 -> V_3 . V_52 = V_3 ;
V_3 -> V_3 . V_53 = sizeof( struct V_4 ) ;
V_3 -> V_3 . V_54 = & V_55 ;
V_3 -> V_3 . V_56 = & V_57 ;
V_3 -> V_3 . V_58 = V_59
| V_60 ;
V_3 -> V_3 . V_61 = & V_3 -> V_62 ;
V_44 = F_29 ( & V_3 -> V_3 ) ;
if ( V_44 )
return V_44 ;
F_30 ( & V_3 -> V_62 ) ;
F_31 ( & V_3 -> V_41 ) ;
F_32 ( & V_3 -> V_14 ) ;
V_3 -> V_33 = V_47 ? V_63 : 0 ;
return 0 ;
}
void F_33 ( struct V_2 * V_3 )
{
F_34 ( & V_3 -> V_62 ) ;
F_35 ( & V_3 -> V_3 ) ;
F_36 ( & V_3 -> V_62 ) ;
}
int F_37 ( struct V_2 * V_3 ,
struct V_64 * V_65 )
{
int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_38 ( & V_3 -> V_3 , V_65 ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ? V_44 : V_65 -> V_43 ;
}
int F_39 ( struct V_2 * V_3 , struct V_66 * V_6 )
{
int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_40 ( & V_3 -> V_3 , V_6 ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_41 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_42 ( & V_3 -> V_3 , V_68 ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_43 ( struct V_2 * V_3 , struct V_66 * V_6 )
{
int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_44 ( & V_3 -> V_3 , V_6 ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_45 ( struct V_2 * V_3 ,
struct V_69 * exp )
{
int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_46 ( & V_3 -> V_3 , exp ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_47 ( struct V_2 * V_3 , struct V_66 * V_6 ,
int V_70 )
{
int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_48 ( & V_3 -> V_3 , V_6 , V_70 ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_49 ( struct V_2 * V_3 , enum V_46 type )
{
int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_50 ( & V_3 -> V_3 , type ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_51 ( struct V_2 * V_3 , enum V_46 type )
{
int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_52 ( & V_3 -> V_3 , type ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_53 ( struct V_2 * V_3 , struct V_71 * V_72 )
{
return F_54 ( & V_3 -> V_3 , V_72 ) ;
}
unsigned long F_55 ( struct V_2 * V_3 ,
unsigned long V_73 )
{
return F_56 ( & V_3 -> V_3 , 0 , 0 , V_73 , 0 ) ;
}
unsigned int F_57 ( struct V_2 * V_3 , struct V_74 * V_74 ,
T_1 * V_75 )
{
unsigned int V_44 ;
F_34 ( & V_3 -> V_62 ) ;
V_44 = F_58 ( & V_3 -> V_3 , V_74 , V_75 ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_59 ( struct V_2 * V_3 )
{
int V_76 ;
F_34 ( & V_3 -> V_62 ) ;
V_76 = F_60 ( & V_3 -> V_3 ) ;
F_36 ( & V_3 -> V_62 ) ;
return V_76 ;
}
void F_61 ( struct V_2 * V_3 , int V_77 )
{
unsigned long V_33 ;
F_19 ( & V_3 -> V_41 , V_33 ) ;
F_4 ( V_3 , V_11 ) ;
if ( V_77 )
V_3 -> V_33 |= V_34 ;
F_22 ( & V_3 -> V_41 , V_33 ) ;
}
struct V_4 * F_62 ( struct V_2 * V_3 ,
struct V_4 * V_6 )
{
struct V_4 * V_78 ;
unsigned long V_33 ;
if ( ( V_3 -> V_33 & V_63 ) && V_6 -> error ) {
V_6 -> error = 0 ;
V_6 -> V_8 = V_36 ;
V_6 -> V_40 = 0 ;
F_63 ( & V_6 -> V_6 . V_15 , 0 , 0 ) ;
return V_6 ;
}
F_19 ( & V_3 -> V_41 , V_33 ) ;
F_7 ( & V_6 -> V_3 ) ;
if ( ! F_5 ( & V_3 -> V_14 ) )
V_78 = F_6 ( & V_3 -> V_14 , struct V_4 ,
V_3 ) ;
else
V_78 = NULL ;
F_22 ( & V_3 -> V_41 , V_33 ) ;
V_6 -> V_8 = V_6 -> error ? V_11 : V_79 ;
F_63 ( & V_6 -> V_6 . V_15 , 0 , V_6 -> V_40 ) ;
F_8 ( & V_6 -> V_6 . V_15 , V_42 ) ;
return V_78 ;
}
