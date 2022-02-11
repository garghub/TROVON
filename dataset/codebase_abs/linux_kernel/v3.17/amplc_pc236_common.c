static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_9 ;
F_3 ( & V_2 -> V_10 , V_9 ) ;
V_7 -> V_11 = V_3 ;
if ( V_5 -> V_12 )
V_5 -> V_12 ( V_2 , V_3 ) ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
}
static bool F_5 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
bool V_13 = false ;
unsigned long V_9 ;
F_3 ( & V_2 -> V_10 , V_9 ) ;
if ( V_7 -> V_11 ) {
if ( V_5 -> V_14 )
V_13 = V_5 -> V_14 ( V_2 ) ;
else
V_13 = true ;
}
F_4 ( & V_2 -> V_10 , V_9 ) ;
return V_13 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_17 * V_18 ,
unsigned int * V_19 )
{
V_19 [ 1 ] = 0 ;
return V_18 -> V_20 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_21 * V_22 )
{
int V_23 = 0 ;
V_23 |= F_8 ( & V_22 -> V_24 , V_25 ) ;
V_23 |= F_8 ( & V_22 -> V_26 , V_27 ) ;
V_23 |= F_8 ( & V_22 -> V_28 , V_29 ) ;
V_23 |= F_8 ( & V_22 -> V_30 , V_31 ) ;
V_23 |= F_8 ( & V_22 -> V_32 , V_33 ) ;
if ( V_23 )
return 1 ;
if ( V_23 )
return 2 ;
V_23 |= F_9 ( & V_22 -> V_34 , 0 ) ;
V_23 |= F_9 ( & V_22 -> V_35 , 0 ) ;
V_23 |= F_9 ( & V_22 -> V_36 , 0 ) ;
V_23 |= F_9 ( & V_22 -> V_37 , V_22 -> V_38 ) ;
V_23 |= F_9 ( & V_22 -> V_39 , 0 ) ;
if ( V_23 )
return 3 ;
if ( V_23 )
return 4 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
F_1 ( V_2 , true ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , false ) ;
return 0 ;
}
static T_1 F_12 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = V_41 ;
struct V_15 * V_16 = V_2 -> V_42 ;
bool V_43 ;
V_43 = F_5 ( V_2 ) ;
if ( V_2 -> V_44 && V_43 ) {
F_13 ( V_16 , 0 ) ;
V_16 -> V_45 -> V_46 |= V_47 | V_48 ;
F_14 ( V_2 , V_16 ) ;
}
return F_15 ( V_43 ) ;
}
int F_16 ( struct V_1 * V_2 , unsigned long V_49 ,
unsigned int V_40 , unsigned long V_50 )
{
struct V_15 * V_16 ;
int V_51 ;
V_2 -> V_49 = V_49 ;
V_51 = F_17 ( V_2 , 2 ) ;
if ( V_51 )
return V_51 ;
V_16 = & V_2 -> V_52 [ 0 ] ;
V_51 = F_18 ( V_2 , V_16 , NULL , V_49 ) ;
if ( V_51 )
return V_51 ;
V_16 = & V_2 -> V_52 [ 1 ] ;
V_2 -> V_42 = V_16 ;
V_16 -> type = V_53 ;
F_1 ( V_2 , false ) ;
if ( V_40 ) {
if ( F_19 ( V_40 , F_12 , V_50 ,
V_2 -> V_54 , V_2 ) >= 0 ) {
V_2 -> V_40 = V_40 ;
V_16 -> type = V_55 ;
V_16 -> V_56 = V_57 | V_58 ;
V_16 -> V_59 = 1 ;
V_16 -> V_60 = 1 ;
V_16 -> V_61 = & V_62 ;
V_16 -> V_63 = F_6 ;
V_16 -> V_64 = 1 ;
V_16 -> V_65 = F_7 ;
V_16 -> V_66 = F_10 ;
V_16 -> V_67 = F_11 ;
}
}
return 0 ;
}
static int T_2 F_20 ( void )
{
return 0 ;
}
static void T_3 F_21 ( void )
{
}
