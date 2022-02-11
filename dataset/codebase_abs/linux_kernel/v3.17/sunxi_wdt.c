static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
F_2 ( V_4 | V_5 , V_6 + V_7 ) ;
F_2 ( V_8 , V_6 + V_9 ) ;
while ( 1 ) {
F_3 ( 5 ) ;
F_2 ( V_4 | V_5 ,
V_6 + V_7 ) ;
}
}
static int F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_1 * V_14 = V_13 -> V_14 ;
F_6 ( V_8 , V_14 + V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 ,
unsigned int V_15 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_1 * V_14 = V_13 -> V_14 ;
T_2 V_16 ;
if ( V_17 [ V_15 ] == 0 )
V_15 ++ ;
V_13 -> V_11 . V_15 = V_15 ;
V_16 = F_8 ( V_14 + V_7 ) ;
V_16 &= ~ V_18 ;
V_16 |= F_9 ( V_17 [ V_15 ] ) ;
F_6 ( V_16 , V_14 + V_7 ) ;
F_4 ( V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_1 * V_14 = V_13 -> V_14 ;
F_6 ( 0 , V_14 + V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 )
{
T_2 V_16 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
void T_1 * V_14 = V_13 -> V_14 ;
int V_19 ;
V_19 = F_7 ( & V_13 -> V_11 ,
V_13 -> V_11 . V_15 ) ;
if ( V_19 < 0 )
return V_19 ;
V_16 = F_8 ( V_14 + V_7 ) ;
V_16 |= ( V_5 | V_4 ) ;
F_6 ( V_16 , V_14 + V_7 ) ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_12 * V_13 ;
struct V_22 * V_23 ;
int V_24 ;
V_13 = F_13 ( & V_21 -> V_25 , sizeof( * V_13 ) , V_26 ) ;
if ( ! V_13 )
return - V_27 ;
F_14 ( V_21 , V_13 ) ;
V_23 = F_15 ( V_21 , V_28 , 0 ) ;
V_13 -> V_14 = F_16 ( & V_21 -> V_25 , V_23 ) ;
if ( F_17 ( V_13 -> V_14 ) )
return F_18 ( V_13 -> V_14 ) ;
V_13 -> V_11 . V_29 = & V_30 ;
V_13 -> V_11 . V_31 = & V_32 ;
V_13 -> V_11 . V_15 = V_33 ;
V_13 -> V_11 . V_34 = V_33 ;
V_13 -> V_11 . V_35 = V_36 ;
V_13 -> V_11 . V_37 = & V_21 -> V_25 ;
F_19 ( & V_13 -> V_11 , V_15 , & V_21 -> V_25 ) ;
F_20 ( & V_13 -> V_11 , V_38 ) ;
F_21 ( & V_13 -> V_11 , V_13 ) ;
F_10 ( & V_13 -> V_11 ) ;
V_24 = F_22 ( & V_13 -> V_11 ) ;
if ( F_23 ( V_24 ) )
return V_24 ;
V_6 = V_13 -> V_14 ;
V_39 = F_1 ;
F_24 ( & V_21 -> V_25 , L_1 ,
V_13 -> V_11 . V_15 , V_38 ) ;
return 0 ;
}
static int F_25 ( struct V_20 * V_21 )
{
struct V_12 * V_13 = F_26 ( V_21 ) ;
V_39 = NULL ;
F_27 ( & V_13 -> V_11 ) ;
F_21 ( & V_13 -> V_11 , NULL ) ;
return 0 ;
}
static void F_28 ( struct V_20 * V_21 )
{
struct V_12 * V_13 = F_26 ( V_21 ) ;
F_10 ( & V_13 -> V_11 ) ;
}
