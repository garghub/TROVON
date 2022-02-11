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
V_4 -> V_8 = F_9 ( struct V_6 ) ;
return V_4 -> V_8 == NULL ? - V_17 : 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_11 ( V_4 -> V_8 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_18 * V_18 = F_13 ( V_4 ) ;
V_18 -> V_19 . V_4 = V_4 ;
V_18 -> V_19 . V_20 = V_21 ;
return F_14 ( & V_18 -> V_19 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_18 * V_18 = F_13 ( V_4 ) ;
return F_16 ( & V_18 -> V_19 ) ;
}
static struct V_22 *
F_17 ( struct V_3 * V_4 , struct V_22 * V_7 )
{
int V_23 ;
T_2 V_10 = 0 , V_11 = 0 ;
F_18 (i) {
const struct V_6 * V_24 ;
T_2 V_25 , V_26 ;
unsigned int V_27 ;
V_24 = F_19 ( V_4 -> V_8 , V_23 ) ;
do {
V_27 = F_20 ( & V_24 -> V_9 ) ;
V_25 = V_24 -> V_10 ;
V_26 = V_24 -> V_11 ;
} while ( F_21 ( & V_24 -> V_9 , V_27 ) );
V_11 += V_26 ;
V_10 += V_25 ;
}
V_7 -> V_28 = V_11 ;
V_7 -> V_29 = 0 ;
V_7 -> V_30 = V_10 ;
V_7 -> V_31 = 0 ;
return V_7 ;
}
static T_3 F_22 ( struct V_3 * V_4 )
{
return 1 ;
}
static void F_23 ( struct V_3 * V_4 )
{
V_4 -> type = V_32 ;
V_4 -> V_33 = 0 ;
V_4 -> V_34 = & V_35 ;
V_4 -> V_36 = & V_37 ;
V_4 -> V_38 = V_39 ;
V_4 -> V_40 = V_41 | V_42 ;
V_4 -> V_43 = V_44 ;
V_4 -> V_16 = V_45 ;
}
static int F_24 ( struct V_46 * V_47 [] , struct V_46 * V_48 [] )
{
if ( V_47 [ V_49 ] )
return - V_15 ;
return 0 ;
}
static T_4 int F_25 ( void )
{
return F_26 ( & V_50 ) ;
}
static T_5 void F_27 ( void )
{
F_28 ( & V_50 ) ;
}
