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
void F_18 ( struct V_9 * V_10 , enum V_37 type ,
int V_38 )
{
V_10 -> V_10 . type = type ;
V_10 -> V_10 . V_39 = V_40 | V_41 ;
V_10 -> V_10 . V_42 = V_10 ;
V_10 -> V_10 . V_43 = sizeof( struct V_18 ) ;
V_10 -> V_10 . V_44 = & V_45 ;
V_10 -> V_10 . V_46 = & V_47 ;
F_19 ( & V_10 -> V_10 ) ;
F_20 ( & V_10 -> V_48 ) ;
F_21 ( & V_10 -> V_33 ) ;
F_22 ( & V_10 -> V_34 ) ;
V_10 -> V_24 = V_38 ? V_49 : 0 ;
}
int F_23 ( struct V_9 * V_10 ,
struct V_50 * V_51 )
{
int V_52 ;
F_24 ( & V_10 -> V_48 ) ;
V_52 = F_25 ( & V_10 -> V_10 , V_51 ) ;
F_26 ( & V_10 -> V_48 ) ;
return V_52 ? V_52 : V_51 -> V_53 ;
}
void F_27 ( struct V_9 * V_10 )
{
F_24 ( & V_10 -> V_48 ) ;
F_28 ( & V_10 -> V_10 ) ;
F_26 ( & V_10 -> V_48 ) ;
}
int F_29 ( struct V_9 * V_10 , struct V_54 * V_19 )
{
int V_52 ;
F_24 ( & V_10 -> V_48 ) ;
V_52 = F_30 ( & V_10 -> V_10 , V_19 ) ;
F_26 ( & V_10 -> V_48 ) ;
return V_52 ;
}
int F_31 ( struct V_9 * V_10 , struct V_54 * V_19 )
{
int V_52 ;
F_24 ( & V_10 -> V_48 ) ;
V_52 = F_32 ( & V_10 -> V_10 , V_19 ) ;
F_26 ( & V_10 -> V_48 ) ;
return V_52 ;
}
int F_33 ( struct V_9 * V_10 , struct V_54 * V_19 ,
int V_55 )
{
int V_52 ;
F_24 ( & V_10 -> V_48 ) ;
V_52 = F_34 ( & V_10 -> V_10 , V_19 , V_55 ) ;
F_26 ( & V_10 -> V_48 ) ;
return V_52 ;
}
int F_35 ( struct V_9 * V_10 , struct V_56 * V_57 )
{
int V_52 ;
F_24 ( & V_10 -> V_48 ) ;
V_52 = F_36 ( & V_10 -> V_10 , V_57 ) ;
F_26 ( & V_10 -> V_48 ) ;
return V_52 ;
}
unsigned long F_37 ( struct V_9 * V_10 ,
unsigned long V_58 )
{
unsigned long V_52 ;
F_24 ( & V_10 -> V_48 ) ;
V_52 = F_38 ( & V_10 -> V_10 , 0 , 0 , V_58 , 0 ) ;
F_26 ( & V_10 -> V_48 ) ;
return V_52 ;
}
unsigned int F_39 ( struct V_9 * V_10 , struct V_59 * V_59 ,
T_1 * V_60 )
{
unsigned int V_52 ;
F_24 ( & V_10 -> V_48 ) ;
V_52 = F_40 ( & V_10 -> V_10 , V_59 , V_60 ) ;
F_26 ( & V_10 -> V_48 ) ;
return V_52 ;
}
int F_41 ( struct V_9 * V_10 )
{
int V_61 ;
F_24 ( & V_10 -> V_48 ) ;
V_61 = F_42 ( & V_10 -> V_10 ) ;
F_26 ( & V_10 -> V_48 ) ;
return V_61 ;
}
int F_43 ( struct V_9 * V_10 , int V_62 )
{
unsigned long V_24 ;
int V_52 ;
F_24 ( & V_10 -> V_48 ) ;
if ( V_62 ) {
V_52 = F_44 ( & V_10 -> V_10 , V_10 -> V_10 . type ) ;
if ( V_52 < 0 )
goto V_63;
V_10 -> V_64 = 0 ;
} else {
V_52 = F_45 ( & V_10 -> V_10 , V_10 -> V_10 . type ) ;
if ( V_52 < 0 )
goto V_63;
F_11 ( & V_10 -> V_33 , V_24 ) ;
F_22 ( & V_10 -> V_34 ) ;
F_15 ( & V_10 -> V_33 , V_24 ) ;
}
V_63:
F_26 ( & V_10 -> V_48 ) ;
return V_52 ;
}
void F_46 ( struct V_9 * V_10 , int V_65 )
{
struct V_18 * V_19 ;
unsigned long V_24 ;
F_11 ( & V_10 -> V_33 , V_24 ) ;
while ( ! F_47 ( & V_10 -> V_34 ) ) {
V_19 = F_48 ( & V_10 -> V_34 , struct V_18 ,
V_10 ) ;
F_49 ( & V_19 -> V_10 ) ;
V_19 -> V_27 = V_35 ;
F_14 ( & V_19 -> V_19 , V_36 ) ;
}
if ( V_65 )
V_10 -> V_24 |= V_25 ;
F_15 ( & V_10 -> V_33 , V_24 ) ;
}
struct V_18 * F_50 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_18 * V_66 ;
unsigned long V_24 ;
if ( ( V_10 -> V_24 & V_49 ) && V_19 -> error ) {
V_19 -> error = 0 ;
V_19 -> V_27 = V_28 ;
F_51 ( & V_19 -> V_19 , 0 , 0 ) ;
return V_19 ;
}
F_11 ( & V_10 -> V_33 , V_24 ) ;
F_49 ( & V_19 -> V_10 ) ;
if ( ! F_47 ( & V_10 -> V_34 ) )
V_66 = F_48 ( & V_10 -> V_34 , struct V_18 ,
V_10 ) ;
else
V_66 = NULL ;
F_15 ( & V_10 -> V_33 , V_24 ) ;
V_19 -> V_27 = V_19 -> error ? V_36 : V_67 ;
F_51 ( & V_19 -> V_19 , 0 , V_19 -> V_32 ) ;
F_14 ( & V_19 -> V_19 , V_68 ) ;
return V_66 ;
}
