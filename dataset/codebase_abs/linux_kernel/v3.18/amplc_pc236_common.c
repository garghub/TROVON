static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_10 ;
F_2 ( & V_2 -> V_11 , V_10 ) ;
V_8 -> V_12 = V_3 ;
if ( V_5 -> V_13 )
V_5 -> V_13 ( V_2 , V_3 ) ;
F_3 ( & V_2 -> V_11 , V_10 ) ;
}
static bool F_4 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
bool V_14 = false ;
unsigned long V_10 ;
F_2 ( & V_2 -> V_11 , V_10 ) ;
if ( V_8 -> V_12 ) {
if ( V_5 -> V_15 )
V_14 = V_5 -> V_15 ( V_2 ) ;
else
V_14 = true ;
}
F_3 ( & V_2 -> V_11 , V_10 ) ;
return V_14 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_16 * V_17 , struct V_18 * V_19 ,
unsigned int * V_20 )
{
V_20 [ 1 ] = 0 ;
return V_19 -> V_21 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_22 * V_23 )
{
int V_24 = 0 ;
V_24 |= F_7 ( & V_23 -> V_25 , V_26 ) ;
V_24 |= F_7 ( & V_23 -> V_27 , V_28 ) ;
V_24 |= F_7 ( & V_23 -> V_29 , V_30 ) ;
V_24 |= F_7 ( & V_23 -> V_31 , V_32 ) ;
V_24 |= F_7 ( & V_23 -> V_33 , V_34 ) ;
if ( V_24 )
return 1 ;
V_24 |= F_8 ( & V_23 -> V_35 , 0 ) ;
V_24 |= F_8 ( & V_23 -> V_36 , 0 ) ;
V_24 |= F_8 ( & V_23 -> V_37 , 0 ) ;
V_24 |= F_8 ( & V_23 -> V_38 , V_23 -> V_39 ) ;
V_24 |= F_8 ( & V_23 -> V_40 , 0 ) ;
if ( V_24 )
return 3 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
F_1 ( V_2 , true ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
F_1 ( V_2 , false ) ;
return 0 ;
}
static T_1 F_11 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_16 * V_17 = V_2 -> V_43 ;
bool V_44 ;
V_44 = F_4 ( V_2 ) ;
if ( V_2 -> V_45 && V_44 ) {
F_12 ( V_17 , 0 ) ;
V_17 -> V_46 -> V_47 |= V_48 | V_49 ;
F_13 ( V_2 , V_17 ) ;
}
return F_14 ( V_44 ) ;
}
int F_15 ( struct V_1 * V_2 , unsigned long V_50 ,
unsigned int V_41 , unsigned long V_51 )
{
struct V_16 * V_17 ;
int V_52 ;
V_2 -> V_50 = V_50 ;
V_52 = F_16 ( V_2 , 2 ) ;
if ( V_52 )
return V_52 ;
V_17 = & V_2 -> V_53 [ 0 ] ;
V_52 = F_17 ( V_2 , V_17 , NULL , 0x00 ) ;
if ( V_52 )
return V_52 ;
V_17 = & V_2 -> V_53 [ 1 ] ;
V_2 -> V_43 = V_17 ;
V_17 -> type = V_54 ;
F_1 ( V_2 , false ) ;
if ( V_41 ) {
if ( F_18 ( V_41 , F_11 , V_51 ,
V_2 -> V_55 , V_2 ) >= 0 ) {
V_2 -> V_41 = V_41 ;
V_17 -> type = V_56 ;
V_17 -> V_57 = V_58 | V_59 ;
V_17 -> V_60 = 1 ;
V_17 -> V_61 = 1 ;
V_17 -> V_62 = & V_63 ;
V_17 -> V_64 = F_5 ;
V_17 -> V_65 = 1 ;
V_17 -> V_66 = F_6 ;
V_17 -> V_67 = F_9 ;
V_17 -> V_68 = F_10 ;
}
}
return 0 ;
}
static int T_2 F_19 ( void )
{
return 0 ;
}
static void T_3 F_20 ( void )
{
}
