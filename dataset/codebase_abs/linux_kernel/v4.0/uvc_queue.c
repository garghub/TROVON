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
F_7 ( & V_13 -> V_13 , V_7 ) ;
}
}
static int F_8 ( struct V_14 * V_15 , const struct V_16 * V_17 ,
unsigned int * V_18 , unsigned int * V_19 ,
unsigned int V_20 [] , void * V_21 [] )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
if ( V_17 && V_17 -> V_17 . V_23 . V_24 < V_22 -> V_25 . V_26 )
return - V_27 ;
* V_19 = 1 ;
V_20 [ 0 ] = V_17 ? V_17 -> V_17 . V_23 . V_24
: V_22 -> V_25 . V_26 ;
return 0 ;
}
static int F_10 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_9 ( V_29 -> V_14 ) ;
struct V_12 * V_13 = F_2 ( V_29 , struct V_12 , V_13 ) ;
if ( V_29 -> V_30 . type == V_31 &&
F_11 ( V_29 , 0 ) > F_12 ( V_29 , 0 ) ) {
F_13 ( V_32 , L_1 ) ;
return - V_27 ;
}
if ( F_14 ( V_3 -> V_33 & V_34 ) )
return - V_35 ;
V_13 -> V_5 = V_36 ;
V_13 -> error = 0 ;
V_13 -> V_37 = F_15 ( V_29 , 0 ) ;
V_13 -> V_38 = F_12 ( V_29 , 0 ) ;
if ( V_29 -> V_30 . type == V_39 )
V_13 -> V_40 = 0 ;
else
V_13 -> V_40 = F_11 ( V_29 , 0 ) ;
return 0 ;
}
static void F_16 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_9 ( V_29 -> V_14 ) ;
struct V_12 * V_13 = F_2 ( V_29 , struct V_12 , V_13 ) ;
unsigned long V_33 ;
F_17 ( & V_3 -> V_41 , V_33 ) ;
if ( F_18 ( ! ( V_3 -> V_33 & V_34 ) ) ) {
F_19 ( & V_13 -> V_3 , & V_3 -> V_11 ) ;
} else {
V_13 -> V_5 = V_8 ;
F_7 ( & V_13 -> V_13 , V_9 ) ;
}
F_20 ( & V_3 -> V_41 , V_33 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_9 ( V_29 -> V_14 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_2 ( V_29 , struct V_12 , V_13 ) ;
if ( V_29 -> V_5 == V_42 )
F_22 ( V_22 , & V_29 -> V_30 , V_13 ) ;
}
static int F_23 ( struct V_14 * V_15 , unsigned int V_43 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned long V_33 ;
int V_44 ;
V_3 -> V_45 = 0 ;
V_44 = F_24 ( V_22 , 1 ) ;
if ( V_44 == 0 )
return 0 ;
F_17 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_36 ) ;
F_20 ( & V_3 -> V_41 , V_33 ) ;
return V_44 ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned long V_33 ;
F_24 ( V_22 , 0 ) ;
F_17 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_8 ) ;
F_20 ( & V_3 -> V_41 , V_33 ) ;
}
int F_26 ( struct V_2 * V_3 , enum V_46 type ,
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
V_44 = F_27 ( & V_3 -> V_3 ) ;
if ( V_44 )
return V_44 ;
F_28 ( & V_3 -> V_62 ) ;
F_29 ( & V_3 -> V_41 ) ;
F_30 ( & V_3 -> V_11 ) ;
V_3 -> V_33 = V_47 ? V_63 : 0 ;
return 0 ;
}
void F_31 ( struct V_2 * V_3 )
{
F_32 ( & V_3 -> V_62 ) ;
F_33 ( & V_3 -> V_3 ) ;
F_34 ( & V_3 -> V_62 ) ;
}
int F_35 ( struct V_2 * V_3 ,
struct V_64 * V_65 )
{
int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_36 ( & V_3 -> V_3 , V_65 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ? V_44 : V_65 -> V_43 ;
}
int F_37 ( struct V_2 * V_3 , struct V_66 * V_13 )
{
int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_38 ( & V_3 -> V_3 , V_13 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_39 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_40 ( & V_3 -> V_3 , V_68 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_41 ( struct V_2 * V_3 , struct V_66 * V_13 )
{
int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_42 ( & V_3 -> V_3 , V_13 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_43 ( struct V_2 * V_3 , struct V_66 * V_13 ,
int V_69 )
{
int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_44 ( & V_3 -> V_3 , V_13 , V_69 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_45 ( struct V_2 * V_3 , enum V_46 type )
{
int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_46 ( & V_3 -> V_3 , type ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_47 ( struct V_2 * V_3 , enum V_46 type )
{
int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_48 ( & V_3 -> V_3 , type ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_49 ( struct V_2 * V_3 , struct V_70 * V_71 )
{
int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_50 ( & V_3 -> V_3 , V_71 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
unsigned long F_51 ( struct V_2 * V_3 ,
unsigned long V_72 )
{
unsigned long V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_52 ( & V_3 -> V_3 , 0 , 0 , V_72 , 0 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
unsigned int F_53 ( struct V_2 * V_3 , struct V_73 * V_73 ,
T_1 * V_74 )
{
unsigned int V_44 ;
F_32 ( & V_3 -> V_62 ) ;
V_44 = F_54 ( & V_3 -> V_3 , V_73 , V_74 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_44 ;
}
int F_55 ( struct V_2 * V_3 )
{
int V_75 ;
F_32 ( & V_3 -> V_62 ) ;
V_75 = F_56 ( & V_3 -> V_3 ) ;
F_34 ( & V_3 -> V_62 ) ;
return V_75 ;
}
void F_57 ( struct V_2 * V_3 , int V_76 )
{
unsigned long V_33 ;
F_17 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_8 ) ;
if ( V_76 )
V_3 -> V_33 |= V_34 ;
F_20 ( & V_3 -> V_41 , V_33 ) ;
}
struct V_12 * F_58 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_12 * V_77 ;
unsigned long V_33 ;
if ( ( V_3 -> V_33 & V_63 ) && V_13 -> error ) {
V_13 -> error = 0 ;
V_13 -> V_5 = V_36 ;
V_13 -> V_40 = 0 ;
F_59 ( & V_13 -> V_13 , 0 , 0 ) ;
return V_13 ;
}
F_17 ( & V_3 -> V_41 , V_33 ) ;
F_6 ( & V_13 -> V_3 ) ;
if ( ! F_4 ( & V_3 -> V_11 ) )
V_77 = F_5 ( & V_3 -> V_11 , struct V_12 ,
V_3 ) ;
else
V_77 = NULL ;
F_20 ( & V_3 -> V_41 , V_33 ) ;
V_13 -> V_5 = V_13 -> error ? V_9 : V_78 ;
F_59 ( & V_13 -> V_13 , 0 , V_13 -> V_40 ) ;
F_7 ( & V_13 -> V_13 , V_42 ) ;
return V_77 ;
}
