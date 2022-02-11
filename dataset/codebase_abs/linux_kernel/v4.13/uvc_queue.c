static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , struct V_6 * V_7 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 , struct V_10 , V_9 ) ;
if ( * V_3 > V_12 )
* V_3 = V_12 ;
* V_4 = 1 ;
V_5 [ 0 ] = V_11 -> V_13 ;
return 0 ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_2 ( V_15 -> V_1 ) ;
struct V_16 * V_17 = F_5 ( V_15 ) ;
struct V_18 * V_19 = F_3 ( V_17 , struct V_18 , V_19 ) ;
if ( V_15 -> type == V_20 &&
F_6 ( V_15 , 0 ) > F_7 ( V_15 , 0 ) ) {
F_8 ( V_21 , L_1 ) ;
return - V_22 ;
}
if ( F_9 ( V_9 -> V_23 & V_24 ) )
return - V_25 ;
V_19 -> V_26 = V_27 ;
V_19 -> V_28 = F_10 ( V_15 , 0 ) ;
V_19 -> V_29 = F_7 ( V_15 , 0 ) ;
if ( V_15 -> type == V_30 )
V_19 -> V_31 = 0 ;
else
V_19 -> V_31 = F_6 ( V_15 , 0 ) ;
return 0 ;
}
static void F_11 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_2 ( V_15 -> V_1 ) ;
struct V_16 * V_17 = F_5 ( V_15 ) ;
struct V_18 * V_19 = F_3 ( V_17 , struct V_18 , V_19 ) ;
unsigned long V_23 ;
F_12 ( & V_9 -> V_32 , V_23 ) ;
if ( F_13 ( ! ( V_9 -> V_23 & V_24 ) ) ) {
F_14 ( & V_19 -> V_9 , & V_9 -> V_33 ) ;
} else {
V_19 -> V_26 = V_34 ;
F_15 ( V_15 , V_35 ) ;
}
F_16 ( & V_9 -> V_32 , V_23 ) ;
}
int F_17 ( struct V_8 * V_9 , enum V_36 type ,
struct V_37 * V_38 )
{
int V_39 ;
V_9 -> V_9 . type = type ;
V_9 -> V_9 . V_40 = V_41 | V_42 | V_43 ;
V_9 -> V_9 . V_44 = V_9 ;
V_9 -> V_9 . V_45 = sizeof( struct V_18 ) ;
V_9 -> V_9 . V_46 = & V_47 ;
V_9 -> V_9 . V_38 = V_38 ;
V_9 -> V_9 . V_48 = & V_49 ;
V_9 -> V_9 . V_50 = V_51
| V_52 ;
V_39 = F_18 ( & V_9 -> V_9 ) ;
if ( V_39 )
return V_39 ;
F_19 ( & V_9 -> V_32 ) ;
F_20 ( & V_9 -> V_33 ) ;
V_9 -> V_23 = 0 ;
return 0 ;
}
void F_21 ( struct V_8 * V_9 )
{
F_22 ( & V_9 -> V_9 ) ;
}
int F_23 ( struct V_8 * V_9 ,
struct V_53 * V_54 )
{
int V_39 ;
V_39 = F_24 ( & V_9 -> V_9 , V_54 ) ;
return V_39 ? V_39 : V_54 -> V_55 ;
}
int F_25 ( struct V_8 * V_9 , struct V_56 * V_19 )
{
return F_26 ( & V_9 -> V_9 , V_19 ) ;
}
int F_27 ( struct V_8 * V_9 , struct V_56 * V_19 )
{
unsigned long V_23 ;
int V_39 ;
V_39 = F_28 ( & V_9 -> V_9 , V_19 ) ;
if ( V_39 < 0 )
return V_39 ;
F_12 ( & V_9 -> V_32 , V_23 ) ;
V_39 = ( V_9 -> V_23 & V_57 ) != 0 ;
V_9 -> V_23 &= ~ V_57 ;
F_16 ( & V_9 -> V_32 , V_23 ) ;
return V_39 ;
}
int F_29 ( struct V_8 * V_9 , struct V_56 * V_19 ,
int V_58 )
{
return F_30 ( & V_9 -> V_9 , V_19 , V_58 ) ;
}
unsigned int F_31 ( struct V_8 * V_9 , struct V_59 * V_59 ,
T_1 * V_60 )
{
return F_32 ( & V_9 -> V_9 , V_59 , V_60 ) ;
}
int F_33 ( struct V_8 * V_9 , struct V_61 * V_62 )
{
return F_34 ( & V_9 -> V_9 , V_62 ) ;
}
unsigned long F_35 ( struct V_8 * V_9 ,
unsigned long V_63 )
{
return F_36 ( & V_9 -> V_9 , 0 , 0 , V_63 , 0 ) ;
}
void F_37 ( struct V_8 * V_9 , int V_64 )
{
struct V_18 * V_19 ;
unsigned long V_23 ;
F_12 ( & V_9 -> V_32 , V_23 ) ;
while ( ! F_38 ( & V_9 -> V_33 ) ) {
V_19 = F_39 ( & V_9 -> V_33 , struct V_18 ,
V_9 ) ;
F_40 ( & V_19 -> V_9 ) ;
V_19 -> V_26 = V_34 ;
F_15 ( & V_19 -> V_19 . V_65 , V_35 ) ;
}
if ( V_64 )
V_9 -> V_23 |= V_24 ;
F_16 ( & V_9 -> V_32 , V_23 ) ;
}
int F_41 ( struct V_8 * V_9 , int V_66 )
{
unsigned long V_23 ;
int V_39 = 0 ;
if ( V_66 ) {
V_39 = F_42 ( & V_9 -> V_9 , V_9 -> V_9 . type ) ;
if ( V_39 < 0 )
return V_39 ;
V_9 -> V_67 = 0 ;
V_9 -> V_68 = 0 ;
} else {
V_39 = F_43 ( & V_9 -> V_9 , V_9 -> V_9 . type ) ;
if ( V_39 < 0 )
return V_39 ;
F_12 ( & V_9 -> V_32 , V_23 ) ;
F_20 ( & V_9 -> V_33 ) ;
V_9 -> V_23 &= ~ V_24 ;
F_16 ( & V_9 -> V_32 , V_23 ) ;
}
return V_39 ;
}
struct V_18 * F_44 ( struct V_8 * V_9 ,
struct V_18 * V_19 )
{
struct V_18 * V_69 ;
if ( ( V_9 -> V_23 & V_70 ) &&
V_19 -> V_29 != V_19 -> V_31 ) {
V_19 -> V_26 = V_27 ;
F_45 ( & V_19 -> V_19 . V_65 , 0 , 0 ) ;
return V_19 ;
}
F_40 ( & V_19 -> V_9 ) ;
if ( ! F_38 ( & V_9 -> V_33 ) )
V_69 = F_39 ( & V_9 -> V_33 , struct V_18 ,
V_9 ) ;
else
V_69 = NULL ;
V_19 -> V_19 . V_71 = V_72 ;
V_19 -> V_19 . V_67 = V_9 -> V_67 ++ ;
V_19 -> V_19 . V_65 . V_73 = F_46 () ;
F_45 ( & V_19 -> V_19 . V_65 , 0 , V_19 -> V_31 ) ;
F_15 ( & V_19 -> V_19 . V_65 , V_74 ) ;
return V_69 ;
}
struct V_18 * F_47 ( struct V_8 * V_9 )
{
struct V_18 * V_19 = NULL ;
if ( ! F_38 ( & V_9 -> V_33 ) )
V_19 = F_39 ( & V_9 -> V_33 , struct V_18 ,
V_9 ) ;
else
V_9 -> V_23 |= V_57 ;
return V_19 ;
}
