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
static void F_23 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
F_24 ( & V_3 -> V_43 ) ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
F_26 ( & V_3 -> V_43 ) ;
}
static int F_27 ( struct V_14 * V_15 , unsigned int V_44 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned long V_33 ;
int V_45 ;
V_3 -> V_46 = 0 ;
V_45 = F_28 ( V_22 , 1 ) ;
if ( V_45 == 0 )
return 0 ;
F_17 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_36 ) ;
F_20 ( & V_3 -> V_41 , V_33 ) ;
return V_45 ;
}
static void F_29 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned long V_33 ;
F_28 ( V_22 , 0 ) ;
F_17 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_8 ) ;
F_20 ( & V_3 -> V_41 , V_33 ) ;
}
int F_30 ( struct V_2 * V_3 , enum V_47 type ,
int V_48 )
{
int V_45 ;
V_3 -> V_3 . type = type ;
V_3 -> V_3 . V_49 = V_50 | V_51 | V_52 ;
V_3 -> V_3 . V_53 = V_3 ;
V_3 -> V_3 . V_54 = sizeof( struct V_12 ) ;
V_3 -> V_3 . V_55 = & V_56 ;
V_3 -> V_3 . V_57 = & V_58 ;
V_3 -> V_3 . V_59 = V_60
| V_61 ;
V_45 = F_31 ( & V_3 -> V_3 ) ;
if ( V_45 )
return V_45 ;
F_32 ( & V_3 -> V_43 ) ;
F_33 ( & V_3 -> V_41 ) ;
F_34 ( & V_3 -> V_11 ) ;
V_3 -> V_33 = V_48 ? V_62 : 0 ;
return 0 ;
}
void F_35 ( struct V_2 * V_3 )
{
F_26 ( & V_3 -> V_43 ) ;
F_36 ( & V_3 -> V_3 ) ;
F_24 ( & V_3 -> V_43 ) ;
}
int F_37 ( struct V_2 * V_3 ,
struct V_63 * V_64 )
{
int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_38 ( & V_3 -> V_3 , V_64 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ? V_45 : V_64 -> V_44 ;
}
int F_39 ( struct V_2 * V_3 , struct V_65 * V_13 )
{
int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_40 ( & V_3 -> V_3 , V_13 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
int F_41 ( struct V_2 * V_3 ,
struct V_66 * V_67 )
{
int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_42 ( & V_3 -> V_3 , V_67 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
int F_43 ( struct V_2 * V_3 , struct V_65 * V_13 )
{
int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_44 ( & V_3 -> V_3 , V_13 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
int F_45 ( struct V_2 * V_3 , struct V_65 * V_13 ,
int V_68 )
{
int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_46 ( & V_3 -> V_3 , V_13 , V_68 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
int F_47 ( struct V_2 * V_3 , enum V_47 type )
{
int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_48 ( & V_3 -> V_3 , type ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
int F_49 ( struct V_2 * V_3 , enum V_47 type )
{
int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_50 ( & V_3 -> V_3 , type ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
int F_51 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_52 ( & V_3 -> V_3 , V_70 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
unsigned long F_53 ( struct V_2 * V_3 ,
unsigned long V_71 )
{
unsigned long V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_54 ( & V_3 -> V_3 , 0 , 0 , V_71 , 0 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
unsigned int F_55 ( struct V_2 * V_3 , struct V_72 * V_72 ,
T_1 * V_73 )
{
unsigned int V_45 ;
F_26 ( & V_3 -> V_43 ) ;
V_45 = F_56 ( & V_3 -> V_3 , V_72 , V_73 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_45 ;
}
int F_57 ( struct V_2 * V_3 )
{
int V_74 ;
F_26 ( & V_3 -> V_43 ) ;
V_74 = F_58 ( & V_3 -> V_3 ) ;
F_24 ( & V_3 -> V_43 ) ;
return V_74 ;
}
void F_59 ( struct V_2 * V_3 , int V_75 )
{
unsigned long V_33 ;
F_17 ( & V_3 -> V_41 , V_33 ) ;
F_3 ( V_3 , V_8 ) ;
if ( V_75 )
V_3 -> V_33 |= V_34 ;
F_20 ( & V_3 -> V_41 , V_33 ) ;
}
struct V_12 * F_60 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_12 * V_76 ;
unsigned long V_33 ;
if ( ( V_3 -> V_33 & V_62 ) && V_13 -> error ) {
V_13 -> error = 0 ;
V_13 -> V_5 = V_36 ;
V_13 -> V_40 = 0 ;
F_61 ( & V_13 -> V_13 , 0 , 0 ) ;
return V_13 ;
}
F_17 ( & V_3 -> V_41 , V_33 ) ;
F_6 ( & V_13 -> V_3 ) ;
if ( ! F_4 ( & V_3 -> V_11 ) )
V_76 = F_5 ( & V_3 -> V_11 , struct V_12 ,
V_3 ) ;
else
V_76 = NULL ;
F_20 ( & V_3 -> V_41 , V_33 ) ;
V_13 -> V_5 = V_13 -> error ? V_9 : V_77 ;
F_61 ( & V_13 -> V_13 , 0 , V_13 -> V_40 ) ;
F_7 ( & V_13 -> V_13 , V_42 ) ;
return V_76 ;
}
