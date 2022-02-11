static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 =
F_3 ( V_10 , struct V_11 , V_10 ) ;
if ( * V_5 > V_13 )
* V_5 = V_13 ;
* V_6 = 1 ;
V_7 [ 0 ] = V_12 -> V_14 . V_15 ;
return 0 ;
}
static int F_4 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_2 ( V_17 -> V_1 ) ;
struct V_18 * V_19 = F_3 ( V_17 , struct V_18 , V_19 ) ;
if ( V_17 -> V_20 . type == V_21 &&
F_5 ( V_17 , 0 ) > F_6 ( V_17 , 0 ) ) {
F_7 ( V_22 , L_1 ) ;
return - V_23 ;
}
if ( F_8 ( V_10 -> V_24 & V_25 ) )
return - V_26 ;
V_19 -> V_27 = V_28 ;
V_19 -> error = 0 ;
V_19 -> V_29 = F_9 ( V_17 , 0 ) ;
V_19 -> V_30 = F_6 ( V_17 , 0 ) ;
if ( V_17 -> V_20 . type == V_31 )
V_19 -> V_32 = 0 ;
else
V_19 -> V_32 = F_5 ( V_17 , 0 ) ;
return 0 ;
}
static void F_10 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_2 ( V_17 -> V_1 ) ;
struct V_18 * V_19 = F_3 ( V_17 , struct V_18 , V_19 ) ;
unsigned long V_24 ;
F_11 ( & V_10 -> V_33 , V_24 ) ;
if ( F_12 ( ! ( V_10 -> V_24 & V_25 ) ) ) {
F_13 ( & V_19 -> V_10 , & V_10 -> V_34 ) ;
} else {
V_19 -> V_27 = V_35 ;
F_14 ( & V_19 -> V_19 , V_36 ) ;
}
F_15 ( & V_10 -> V_33 , V_24 ) ;
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_2 ( V_17 -> V_1 ) ;
struct V_11 * V_12 =
F_3 ( V_10 , struct V_11 , V_10 ) ;
struct V_18 * V_19 = F_3 ( V_17 , struct V_18 , V_19 ) ;
F_17 ( V_12 , & V_17 -> V_20 , V_19 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_19 ( & V_10 -> V_37 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_21 ( & V_10 -> V_37 ) ;
}
int F_22 ( struct V_9 * V_10 , enum V_38 type ,
int V_39 )
{
int V_40 ;
V_10 -> V_10 . type = type ;
V_10 -> V_10 . V_41 = V_42 | V_43 | V_44 ;
V_10 -> V_10 . V_45 = V_10 ;
V_10 -> V_10 . V_46 = sizeof( struct V_18 ) ;
V_10 -> V_10 . V_47 = & V_48 ;
V_10 -> V_10 . V_49 = & V_50 ;
V_40 = F_23 ( & V_10 -> V_10 ) ;
if ( V_40 )
return V_40 ;
F_24 ( & V_10 -> V_37 ) ;
F_25 ( & V_10 -> V_33 ) ;
F_26 ( & V_10 -> V_34 ) ;
V_10 -> V_24 = V_39 ? V_51 : 0 ;
return 0 ;
}
int F_27 ( struct V_9 * V_10 ,
struct V_52 * V_53 )
{
int V_40 ;
F_21 ( & V_10 -> V_37 ) ;
V_40 = F_28 ( & V_10 -> V_10 , V_53 ) ;
F_19 ( & V_10 -> V_37 ) ;
return V_40 ? V_40 : V_53 -> V_54 ;
}
void F_29 ( struct V_9 * V_10 )
{
F_21 ( & V_10 -> V_37 ) ;
F_30 ( & V_10 -> V_10 ) ;
F_19 ( & V_10 -> V_37 ) ;
}
int F_31 ( struct V_9 * V_10 , struct V_55 * V_19 )
{
int V_40 ;
F_21 ( & V_10 -> V_37 ) ;
V_40 = F_32 ( & V_10 -> V_10 , V_19 ) ;
F_19 ( & V_10 -> V_37 ) ;
return V_40 ;
}
int F_33 ( struct V_9 * V_10 , struct V_55 * V_19 )
{
int V_40 ;
F_21 ( & V_10 -> V_37 ) ;
V_40 = F_34 ( & V_10 -> V_10 , V_19 ) ;
F_19 ( & V_10 -> V_37 ) ;
return V_40 ;
}
int F_35 ( struct V_9 * V_10 , struct V_55 * V_19 ,
int V_56 )
{
int V_40 ;
F_21 ( & V_10 -> V_37 ) ;
V_40 = F_36 ( & V_10 -> V_10 , V_19 , V_56 ) ;
F_19 ( & V_10 -> V_37 ) ;
return V_40 ;
}
int F_37 ( struct V_9 * V_10 , struct V_57 * V_58 )
{
int V_40 ;
F_21 ( & V_10 -> V_37 ) ;
V_40 = F_38 ( & V_10 -> V_10 , V_58 ) ;
F_19 ( & V_10 -> V_37 ) ;
return V_40 ;
}
unsigned long F_39 ( struct V_9 * V_10 ,
unsigned long V_59 )
{
unsigned long V_40 ;
F_21 ( & V_10 -> V_37 ) ;
V_40 = F_40 ( & V_10 -> V_10 , 0 , 0 , V_59 , 0 ) ;
F_19 ( & V_10 -> V_37 ) ;
return V_40 ;
}
unsigned int F_41 ( struct V_9 * V_10 , struct V_60 * V_60 ,
T_1 * V_61 )
{
unsigned int V_40 ;
F_21 ( & V_10 -> V_37 ) ;
V_40 = F_42 ( & V_10 -> V_10 , V_60 , V_61 ) ;
F_19 ( & V_10 -> V_37 ) ;
return V_40 ;
}
int F_43 ( struct V_9 * V_10 )
{
int V_62 ;
F_21 ( & V_10 -> V_37 ) ;
V_62 = F_44 ( & V_10 -> V_10 ) ;
F_19 ( & V_10 -> V_37 ) ;
return V_62 ;
}
int F_45 ( struct V_9 * V_10 , int V_63 )
{
unsigned long V_24 ;
int V_40 ;
F_21 ( & V_10 -> V_37 ) ;
if ( V_63 ) {
V_40 = F_46 ( & V_10 -> V_10 , V_10 -> V_10 . type ) ;
if ( V_40 < 0 )
goto V_64;
V_10 -> V_65 = 0 ;
} else {
V_40 = F_47 ( & V_10 -> V_10 , V_10 -> V_10 . type ) ;
if ( V_40 < 0 )
goto V_64;
F_11 ( & V_10 -> V_33 , V_24 ) ;
F_26 ( & V_10 -> V_34 ) ;
F_15 ( & V_10 -> V_33 , V_24 ) ;
}
V_64:
F_19 ( & V_10 -> V_37 ) ;
return V_40 ;
}
void F_48 ( struct V_9 * V_10 , int V_66 )
{
struct V_18 * V_19 ;
unsigned long V_24 ;
F_11 ( & V_10 -> V_33 , V_24 ) ;
while ( ! F_49 ( & V_10 -> V_34 ) ) {
V_19 = F_50 ( & V_10 -> V_34 , struct V_18 ,
V_10 ) ;
F_51 ( & V_19 -> V_10 ) ;
V_19 -> V_27 = V_35 ;
F_14 ( & V_19 -> V_19 , V_36 ) ;
}
if ( V_66 )
V_10 -> V_24 |= V_25 ;
F_15 ( & V_10 -> V_33 , V_24 ) ;
}
struct V_18 * F_52 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_18 * V_67 ;
unsigned long V_24 ;
if ( ( V_10 -> V_24 & V_51 ) && V_19 -> error ) {
V_19 -> error = 0 ;
V_19 -> V_27 = V_28 ;
V_19 -> V_32 = 0 ;
F_53 ( & V_19 -> V_19 , 0 , 0 ) ;
return V_19 ;
}
F_11 ( & V_10 -> V_33 , V_24 ) ;
F_51 ( & V_19 -> V_10 ) ;
if ( ! F_49 ( & V_10 -> V_34 ) )
V_67 = F_50 ( & V_10 -> V_34 , struct V_18 ,
V_10 ) ;
else
V_67 = NULL ;
F_15 ( & V_10 -> V_33 , V_24 ) ;
V_19 -> V_27 = V_19 -> error ? V_36 : V_68 ;
F_53 ( & V_19 -> V_19 , 0 , V_19 -> V_32 ) ;
F_14 ( & V_19 -> V_19 , V_69 ) ;
return V_67 ;
}
