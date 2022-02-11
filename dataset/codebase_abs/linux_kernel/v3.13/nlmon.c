static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
F_3 ( & V_7 -> V_9 ) ;
V_7 -> V_10 += V_5 ;
V_7 -> V_11 ++ ;
F_4 ( & V_7 -> V_9 ) ;
F_5 ( V_2 ) ;
return V_12 ;
}
static int F_6 ( int V_13 )
{
return V_13 >= ( int ) sizeof( struct V_14 ) ;
}
static int F_7 ( struct V_3 * V_4 , int V_13 )
{
if ( ! F_6 ( V_13 ) )
return - V_15 ;
V_4 -> V_16 = V_13 ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_17 ;
V_4 -> V_8 = F_9 ( struct V_6 ) ;
F_10 (i) {
struct V_6 * V_18 ;
V_18 = F_11 ( V_4 -> V_8 , V_17 ) ;
F_12 ( & V_18 -> V_9 ) ;
}
return V_4 -> V_8 == NULL ? - V_19 : 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_8 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_20 * V_20 = F_16 ( V_4 ) ;
V_20 -> V_21 . V_4 = V_4 ;
V_20 -> V_21 . V_22 = V_23 ;
return F_17 ( & V_20 -> V_21 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_20 * V_20 = F_16 ( V_4 ) ;
return F_19 ( & V_20 -> V_21 ) ;
}
static struct V_24 *
F_20 ( struct V_3 * V_4 , struct V_24 * V_7 )
{
int V_17 ;
T_2 V_10 = 0 , V_11 = 0 ;
F_10 (i) {
const struct V_6 * V_25 ;
T_2 V_26 , V_27 ;
unsigned int V_28 ;
V_25 = F_11 ( V_4 -> V_8 , V_17 ) ;
do {
V_28 = F_21 ( & V_25 -> V_9 ) ;
V_26 = V_25 -> V_10 ;
V_27 = V_25 -> V_11 ;
} while ( F_22 ( & V_25 -> V_9 , V_28 ) );
V_11 += V_27 ;
V_10 += V_26 ;
}
V_7 -> V_29 = V_11 ;
V_7 -> V_30 = 0 ;
V_7 -> V_31 = V_10 ;
V_7 -> V_32 = 0 ;
return V_7 ;
}
static T_3 F_23 ( struct V_3 * V_4 )
{
return 1 ;
}
static void F_24 ( struct V_3 * V_4 )
{
V_4 -> type = V_33 ;
V_4 -> V_34 = 0 ;
V_4 -> V_35 = & V_36 ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_39 = V_40 ;
V_4 -> V_41 = V_42 | V_43 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_16 = V_46 ;
}
static int F_25 ( struct V_47 * V_48 [] , struct V_47 * V_49 [] )
{
if ( V_48 [ V_50 ] )
return - V_15 ;
return 0 ;
}
static T_4 int F_26 ( void )
{
return F_27 ( & V_51 ) ;
}
static T_5 void F_28 ( void )
{
F_29 ( & V_51 ) ;
}
