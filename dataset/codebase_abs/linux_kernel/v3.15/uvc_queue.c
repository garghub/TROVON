static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 =
F_3 ( V_10 , struct V_11 , V_10 ) ;
if ( V_4 && V_4 -> V_4 . V_13 . V_14 < V_12 -> V_15 . V_16 )
return - V_17 ;
* V_6 = 1 ;
V_7 [ 0 ] = V_4 ? V_4 -> V_4 . V_13 . V_14
: V_12 -> V_15 . V_16 ;
return 0 ;
}
static int F_4 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_19 -> V_1 ) ;
struct V_20 * V_21 = F_3 ( V_19 , struct V_20 , V_21 ) ;
if ( V_19 -> V_22 . type == V_23 &&
F_5 ( V_19 , 0 ) > F_6 ( V_19 , 0 ) ) {
F_7 ( V_24 , L_1 ) ;
return - V_17 ;
}
if ( F_8 ( V_10 -> V_25 & V_26 ) )
return - V_27 ;
V_21 -> V_28 = V_29 ;
V_21 -> error = 0 ;
V_21 -> V_30 = F_9 ( V_19 , 0 ) ;
V_21 -> V_31 = F_6 ( V_19 , 0 ) ;
if ( V_19 -> V_22 . type == V_32 )
V_21 -> V_33 = 0 ;
else
V_21 -> V_33 = F_5 ( V_19 , 0 ) ;
return 0 ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_19 -> V_1 ) ;
struct V_20 * V_21 = F_3 ( V_19 , struct V_20 , V_21 ) ;
unsigned long V_25 ;
F_11 ( & V_10 -> V_34 , V_25 ) ;
if ( F_12 ( ! ( V_10 -> V_25 & V_26 ) ) ) {
F_13 ( & V_21 -> V_10 , & V_10 -> V_35 ) ;
} else {
V_21 -> V_28 = V_36 ;
F_14 ( & V_21 -> V_21 , V_37 ) ;
}
F_15 ( & V_10 -> V_34 , V_25 ) ;
}
static void F_16 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_19 -> V_1 ) ;
struct V_11 * V_12 =
F_3 ( V_10 , struct V_11 , V_10 ) ;
struct V_20 * V_21 = F_3 ( V_19 , struct V_20 , V_21 ) ;
if ( V_19 -> V_28 == V_38 )
F_17 ( V_12 , & V_19 -> V_22 , V_21 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_19 ( & V_10 -> V_39 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_21 ( & V_10 -> V_39 ) ;
}
int F_22 ( struct V_9 * V_10 , enum V_40 type ,
int V_41 )
{
int V_42 ;
V_10 -> V_10 . type = type ;
V_10 -> V_10 . V_43 = V_44 | V_45 | V_46 ;
V_10 -> V_10 . V_47 = V_10 ;
V_10 -> V_10 . V_48 = sizeof( struct V_20 ) ;
V_10 -> V_10 . V_49 = & V_50 ;
V_10 -> V_10 . V_51 = & V_52 ;
V_10 -> V_10 . V_53 = V_54
| V_55 ;
V_42 = F_23 ( & V_10 -> V_10 ) ;
if ( V_42 )
return V_42 ;
F_24 ( & V_10 -> V_39 ) ;
F_25 ( & V_10 -> V_34 ) ;
F_26 ( & V_10 -> V_35 ) ;
V_10 -> V_25 = V_41 ? V_56 : 0 ;
return 0 ;
}
int F_27 ( struct V_9 * V_10 ,
struct V_57 * V_58 )
{
int V_42 ;
F_21 ( & V_10 -> V_39 ) ;
V_42 = F_28 ( & V_10 -> V_10 , V_58 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_42 ? V_42 : V_58 -> V_59 ;
}
void F_29 ( struct V_9 * V_10 )
{
F_21 ( & V_10 -> V_39 ) ;
F_30 ( & V_10 -> V_10 ) ;
F_19 ( & V_10 -> V_39 ) ;
}
int F_31 ( struct V_9 * V_10 , struct V_60 * V_21 )
{
int V_42 ;
F_21 ( & V_10 -> V_39 ) ;
V_42 = F_32 ( & V_10 -> V_10 , V_21 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_42 ;
}
int F_33 ( struct V_9 * V_10 ,
struct V_61 * V_62 )
{
int V_42 ;
F_21 ( & V_10 -> V_39 ) ;
V_42 = F_34 ( & V_10 -> V_10 , V_62 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_42 ;
}
int F_35 ( struct V_9 * V_10 , struct V_60 * V_21 )
{
int V_42 ;
F_21 ( & V_10 -> V_39 ) ;
V_42 = F_36 ( & V_10 -> V_10 , V_21 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_42 ;
}
int F_37 ( struct V_9 * V_10 , struct V_60 * V_21 ,
int V_63 )
{
int V_42 ;
F_21 ( & V_10 -> V_39 ) ;
V_42 = F_38 ( & V_10 -> V_10 , V_21 , V_63 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_42 ;
}
int F_39 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
int V_42 ;
F_21 ( & V_10 -> V_39 ) ;
V_42 = F_40 ( & V_10 -> V_10 , V_65 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_42 ;
}
unsigned long F_41 ( struct V_9 * V_10 ,
unsigned long V_66 )
{
unsigned long V_42 ;
F_21 ( & V_10 -> V_39 ) ;
V_42 = F_42 ( & V_10 -> V_10 , 0 , 0 , V_66 , 0 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_42 ;
}
unsigned int F_43 ( struct V_9 * V_10 , struct V_67 * V_67 ,
T_1 * V_68 )
{
unsigned int V_42 ;
F_21 ( & V_10 -> V_39 ) ;
V_42 = F_44 ( & V_10 -> V_10 , V_67 , V_68 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_42 ;
}
int F_45 ( struct V_9 * V_10 )
{
int V_69 ;
F_21 ( & V_10 -> V_39 ) ;
V_69 = F_46 ( & V_10 -> V_10 ) ;
F_19 ( & V_10 -> V_39 ) ;
return V_69 ;
}
int F_47 ( struct V_9 * V_10 , int V_70 )
{
unsigned long V_25 ;
int V_42 ;
F_21 ( & V_10 -> V_39 ) ;
if ( V_70 ) {
V_42 = F_48 ( & V_10 -> V_10 , V_10 -> V_10 . type ) ;
if ( V_42 < 0 )
goto V_71;
V_10 -> V_72 = 0 ;
} else {
V_42 = F_49 ( & V_10 -> V_10 , V_10 -> V_10 . type ) ;
if ( V_42 < 0 )
goto V_71;
F_11 ( & V_10 -> V_34 , V_25 ) ;
F_26 ( & V_10 -> V_35 ) ;
F_15 ( & V_10 -> V_34 , V_25 ) ;
}
V_71:
F_19 ( & V_10 -> V_39 ) ;
return V_42 ;
}
void F_50 ( struct V_9 * V_10 , int V_73 )
{
struct V_20 * V_21 ;
unsigned long V_25 ;
F_11 ( & V_10 -> V_34 , V_25 ) ;
while ( ! F_51 ( & V_10 -> V_35 ) ) {
V_21 = F_52 ( & V_10 -> V_35 , struct V_20 ,
V_10 ) ;
F_53 ( & V_21 -> V_10 ) ;
V_21 -> V_28 = V_36 ;
F_14 ( & V_21 -> V_21 , V_37 ) ;
}
if ( V_73 )
V_10 -> V_25 |= V_26 ;
F_15 ( & V_10 -> V_34 , V_25 ) ;
}
struct V_20 * F_54 ( struct V_9 * V_10 ,
struct V_20 * V_21 )
{
struct V_20 * V_74 ;
unsigned long V_25 ;
if ( ( V_10 -> V_25 & V_56 ) && V_21 -> error ) {
V_21 -> error = 0 ;
V_21 -> V_28 = V_29 ;
V_21 -> V_33 = 0 ;
F_55 ( & V_21 -> V_21 , 0 , 0 ) ;
return V_21 ;
}
F_11 ( & V_10 -> V_34 , V_25 ) ;
F_53 ( & V_21 -> V_10 ) ;
if ( ! F_51 ( & V_10 -> V_35 ) )
V_74 = F_52 ( & V_10 -> V_35 , struct V_20 ,
V_10 ) ;
else
V_74 = NULL ;
F_15 ( & V_10 -> V_34 , V_25 ) ;
V_21 -> V_28 = V_21 -> error ? V_37 : V_75 ;
F_55 ( & V_21 -> V_21 , 0 , V_21 -> V_33 ) ;
F_14 ( & V_21 -> V_21 , V_38 ) ;
return V_74 ;
}
