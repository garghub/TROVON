static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( struct V_4 ) ;
if ( ! V_2 -> V_3 )
return - V_5 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ) ;
V_6 -> V_7 . V_2 = V_2 ;
V_6 -> V_7 . V_8 = V_9 ;
return F_7 ( & V_6 -> V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ) ;
return F_9 ( & V_6 -> V_7 ) ;
}
static T_1 F_10 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_12 = V_11 -> V_12 ;
struct V_4 * V_13 = F_11 ( V_2 -> V_3 ) ;
F_12 ( & V_13 -> V_14 ) ;
V_13 -> V_15 += V_12 ;
V_13 -> V_16 ++ ;
F_13 ( & V_13 -> V_14 ) ;
F_14 ( V_11 ) ;
return V_17 ;
}
static void
F_15 ( struct V_1 * V_2 , struct V_18 * V_13 )
{
int V_19 ;
T_2 V_20 = 0 , V_21 = 0 ;
F_16 (i) {
const struct V_4 * V_22 ;
T_2 V_23 , V_24 ;
unsigned int V_25 ;
V_22 = F_17 ( V_2 -> V_3 , V_19 ) ;
do {
V_25 = F_18 ( & V_22 -> V_14 ) ;
V_23 = V_22 -> V_15 ;
V_24 = V_22 -> V_16 ;
} while ( F_19 ( & V_22 -> V_14 , V_25 ) );
V_21 += V_24 ;
V_20 += V_23 ;
}
V_13 -> V_16 = V_21 ;
V_13 -> V_26 = 0 ;
V_13 -> V_15 = V_20 ;
V_13 -> V_27 = 0 ;
}
static int F_20 ( int V_28 )
{
return V_28 >= ( int ) sizeof( struct V_29 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_28 )
{
if ( ! F_20 ( V_28 ) )
return - V_30 ;
V_2 -> V_31 = V_28 ;
return 0 ;
}
static T_3 F_22 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_2 -> type = V_32 ;
V_2 -> V_33 |= V_34 ;
V_2 -> V_35 = & V_36 ;
V_2 -> V_37 = & V_38 ;
V_2 -> V_39 = true ;
V_2 -> V_40 = V_41 | V_42 |
V_43 | V_44 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_31 = V_47 ;
}
static T_4 int F_24 ( void )
{
return F_25 ( & V_48 ) ;
}
static T_5 void F_26 ( void )
{
F_27 ( & V_48 ) ;
}
