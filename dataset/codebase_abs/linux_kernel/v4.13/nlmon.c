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
static int F_6 ( struct V_3 * V_4 )
{
V_4 -> V_8 = F_7 ( struct V_6 ) ;
return V_4 -> V_8 == NULL ? - V_13 : 0 ;
}
static void F_8 ( struct V_3 * V_4 )
{
F_9 ( V_4 -> V_8 ) ;
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_14 * V_14 = F_11 ( V_4 ) ;
V_14 -> V_15 . V_4 = V_4 ;
V_14 -> V_15 . V_16 = V_17 ;
return F_12 ( & V_14 -> V_15 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_14 * V_14 = F_11 ( V_4 ) ;
return F_14 ( & V_14 -> V_15 ) ;
}
static void
F_15 ( struct V_3 * V_4 , struct V_18 * V_7 )
{
int V_19 ;
T_2 V_10 = 0 , V_11 = 0 ;
F_16 (i) {
const struct V_6 * V_20 ;
T_2 V_21 , V_22 ;
unsigned int V_23 ;
V_20 = F_17 ( V_4 -> V_8 , V_19 ) ;
do {
V_23 = F_18 ( & V_20 -> V_9 ) ;
V_21 = V_20 -> V_10 ;
V_22 = V_20 -> V_11 ;
} while ( F_19 ( & V_20 -> V_9 , V_23 ) );
V_11 += V_22 ;
V_10 += V_21 ;
}
V_7 -> V_24 = V_11 ;
V_7 -> V_25 = 0 ;
V_7 -> V_26 = V_10 ;
V_7 -> V_27 = 0 ;
}
static T_3 F_20 ( struct V_3 * V_4 )
{
return 1 ;
}
static void F_21 ( struct V_3 * V_4 )
{
V_4 -> type = V_28 ;
V_4 -> V_29 |= V_30 ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_35 = true ;
V_4 -> V_36 = V_37 | V_38 |
V_39 | V_40 ;
V_4 -> V_41 = V_42 ;
V_4 -> V_43 = V_44 ;
V_4 -> V_45 = sizeof( struct V_46 ) ;
}
static int F_22 ( struct V_47 * V_48 [] , struct V_47 * V_49 [] ,
struct V_50 * V_51 )
{
if ( V_48 [ V_52 ] )
return - V_53 ;
return 0 ;
}
static T_4 int F_23 ( void )
{
return F_24 ( & V_54 ) ;
}
static T_5 void F_25 ( void )
{
F_26 ( & V_54 ) ;
}
