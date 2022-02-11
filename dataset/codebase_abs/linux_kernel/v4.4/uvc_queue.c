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
static int F_8 ( struct V_15 * V_16 , const void * V_17 ,
unsigned int * V_18 , unsigned int * V_19 ,
unsigned int V_20 [] , void * V_21 [] )
{
const struct V_22 * V_23 = V_17 ;
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
if ( V_23 && V_23 -> V_23 . V_25 . V_26 < V_24 -> V_27 . V_28 )
return - V_29 ;
* V_19 = 1 ;
V_20 [ 0 ] = V_23 ? V_23 -> V_23 . V_25 . V_26
: V_24 -> V_27 . V_28 ;
return 0 ;
}
static int F_10 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_11 ( V_31 ) ;
struct V_2 * V_3 = F_9 ( V_31 -> V_15 ) ;
struct V_12 * V_13 = F_2 ( V_33 , struct V_12 , V_13 ) ;
if ( V_31 -> type == V_34 &&
F_12 ( V_31 , 0 ) > F_13 ( V_31 , 0 ) ) {
F_14 ( V_35 , L_1 ) ;
return - V_29 ;
}
if ( F_15 ( V_3 -> V_36 & V_37 ) )
return - V_38 ;
V_13 -> V_5 = V_39 ;
V_13 -> error = 0 ;
V_13 -> V_40 = F_16 ( V_31 , 0 ) ;
V_13 -> V_41 = F_13 ( V_31 , 0 ) ;
if ( V_31 -> type == V_42 )
V_13 -> V_43 = 0 ;
else
V_13 -> V_43 = F_12 ( V_31 , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_11 ( V_31 ) ;
struct V_2 * V_3 = F_9 ( V_31 -> V_15 ) ;
struct V_12 * V_13 = F_2 ( V_33 , struct V_12 , V_13 ) ;
unsigned long V_36 ;
F_18 ( & V_3 -> V_44 , V_36 ) ;
if ( F_19 ( ! ( V_3 -> V_36 & V_37 ) ) ) {
F_20 ( & V_13 -> V_3 , & V_3 -> V_11 ) ;
} else {
V_13 -> V_5 = V_8 ;
F_7 ( V_31 , V_9 ) ;
}
F_21 ( & V_3 -> V_44 , V_36 ) ;
}
static void F_22 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_11 ( V_31 ) ;
struct V_2 * V_3 = F_9 ( V_31 -> V_15 ) ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_2 ( V_33 , struct V_12 , V_13 ) ;
if ( V_31 -> V_5 == V_45 )
F_23 ( V_24 , V_33 , V_13 ) ;
}
static int F_24 ( struct V_15 * V_16 , unsigned int V_46 )
{
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
unsigned long V_36 ;
int V_47 ;
V_3 -> V_48 = 0 ;
V_47 = F_25 ( V_24 , 1 ) ;
if ( V_47 == 0 )
return 0 ;
F_18 ( & V_3 -> V_44 , V_36 ) ;
F_3 ( V_3 , V_39 ) ;
F_21 ( & V_3 -> V_44 , V_36 ) ;
return V_47 ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_2 * V_3 = F_9 ( V_16 ) ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
unsigned long V_36 ;
F_25 ( V_24 , 0 ) ;
F_18 ( & V_3 -> V_44 , V_36 ) ;
F_3 ( V_3 , V_8 ) ;
F_21 ( & V_3 -> V_44 , V_36 ) ;
}
int F_27 ( struct V_2 * V_3 , enum V_49 type ,
int V_50 )
{
int V_47 ;
V_3 -> V_3 . type = type ;
V_3 -> V_3 . V_51 = V_52 | V_53 | V_54 ;
V_3 -> V_3 . V_55 = V_3 ;
V_3 -> V_3 . V_56 = sizeof( struct V_12 ) ;
V_3 -> V_3 . V_57 = & V_58 ;
V_3 -> V_3 . V_59 = & V_60 ;
V_3 -> V_3 . V_61 = V_62
| V_63 ;
V_3 -> V_3 . V_64 = & V_3 -> V_65 ;
V_47 = F_28 ( & V_3 -> V_3 ) ;
if ( V_47 )
return V_47 ;
F_29 ( & V_3 -> V_65 ) ;
F_30 ( & V_3 -> V_44 ) ;
F_31 ( & V_3 -> V_11 ) ;
V_3 -> V_36 = V_50 ? V_66 : 0 ;
return 0 ;
}
void F_32 ( struct V_2 * V_3 )
{
F_33 ( & V_3 -> V_65 ) ;
F_34 ( & V_3 -> V_3 ) ;
F_35 ( & V_3 -> V_65 ) ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_37 ( & V_3 -> V_3 , V_68 ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ? V_47 : V_68 -> V_46 ;
}
int F_38 ( struct V_2 * V_3 , struct V_69 * V_13 )
{
int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_39 ( & V_3 -> V_3 , V_13 ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ;
}
int F_40 ( struct V_2 * V_3 ,
struct V_70 * V_71 )
{
int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_41 ( & V_3 -> V_3 , V_71 ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ;
}
int F_42 ( struct V_2 * V_3 , struct V_69 * V_13 )
{
int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_43 ( & V_3 -> V_3 , V_13 ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ;
}
int F_44 ( struct V_2 * V_3 ,
struct V_72 * exp )
{
int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_45 ( & V_3 -> V_3 , exp ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ;
}
int F_46 ( struct V_2 * V_3 , struct V_69 * V_13 ,
int V_73 )
{
int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_47 ( & V_3 -> V_3 , V_13 , V_73 ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ;
}
int F_48 ( struct V_2 * V_3 , enum V_49 type )
{
int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_49 ( & V_3 -> V_3 , type ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ;
}
int F_50 ( struct V_2 * V_3 , enum V_49 type )
{
int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_51 ( & V_3 -> V_3 , type ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ;
}
int F_52 ( struct V_2 * V_3 , struct V_74 * V_75 )
{
return F_53 ( & V_3 -> V_3 , V_75 ) ;
}
unsigned long F_54 ( struct V_2 * V_3 ,
unsigned long V_76 )
{
return F_55 ( & V_3 -> V_3 , 0 , 0 , V_76 , 0 ) ;
}
unsigned int F_56 ( struct V_2 * V_3 , struct V_77 * V_77 ,
T_1 * V_78 )
{
unsigned int V_47 ;
F_33 ( & V_3 -> V_65 ) ;
V_47 = F_57 ( & V_3 -> V_3 , V_77 , V_78 ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_47 ;
}
int F_58 ( struct V_2 * V_3 )
{
int V_79 ;
F_33 ( & V_3 -> V_65 ) ;
V_79 = F_59 ( & V_3 -> V_3 ) ;
F_35 ( & V_3 -> V_65 ) ;
return V_79 ;
}
void F_60 ( struct V_2 * V_3 , int V_80 )
{
unsigned long V_36 ;
F_18 ( & V_3 -> V_44 , V_36 ) ;
F_3 ( V_3 , V_8 ) ;
if ( V_80 )
V_3 -> V_36 |= V_37 ;
F_21 ( & V_3 -> V_44 , V_36 ) ;
}
struct V_12 * F_61 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_12 * V_81 ;
unsigned long V_36 ;
if ( ( V_3 -> V_36 & V_66 ) && V_13 -> error ) {
V_13 -> error = 0 ;
V_13 -> V_5 = V_39 ;
V_13 -> V_43 = 0 ;
F_62 ( & V_13 -> V_13 . V_14 , 0 , 0 ) ;
return V_13 ;
}
F_18 ( & V_3 -> V_44 , V_36 ) ;
F_6 ( & V_13 -> V_3 ) ;
if ( ! F_4 ( & V_3 -> V_11 ) )
V_81 = F_5 ( & V_3 -> V_11 , struct V_12 ,
V_3 ) ;
else
V_81 = NULL ;
F_21 ( & V_3 -> V_44 , V_36 ) ;
V_13 -> V_5 = V_13 -> error ? V_9 : V_82 ;
F_62 ( & V_13 -> V_13 . V_14 , 0 , V_13 -> V_43 ) ;
F_7 ( & V_13 -> V_13 . V_14 , V_45 ) ;
return V_81 ;
}
