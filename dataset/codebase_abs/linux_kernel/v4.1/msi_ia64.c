static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , bool V_4 )
{
struct V_5 V_6 ;
T_2 V_7 , V_8 ;
int V_9 = F_2 ( V_3 , V_10 ) ;
unsigned int V_11 = V_2 -> V_11 ;
if ( F_3 ( V_11 , V_9 ) )
return - 1 ;
F_4 ( V_2 -> V_12 , & V_6 ) ;
V_7 = V_6 . V_13 ;
V_7 &= V_14 ;
V_7 |= F_5 ( F_6 ( V_9 ) ) ;
V_6 . V_13 = V_7 ;
V_8 = V_6 . V_8 ;
V_8 &= V_15 ;
V_8 |= F_7 ( F_8 ( V_11 ) ) ;
V_6 . V_8 = V_8 ;
F_9 ( V_11 , & V_6 ) ;
F_10 ( V_2 -> V_16 , F_11 ( V_9 ) ) ;
return 0 ;
}
int F_12 ( struct V_17 * V_18 , struct V_12 * V_19 )
{
struct V_5 V_6 ;
unsigned long V_20 ;
int V_11 , V_21 ;
V_11 = F_13 () ;
if ( V_11 < 0 )
return V_11 ;
F_14 ( V_11 , V_19 ) ;
V_20 = F_6 ( F_15 ( & ( F_16 ( V_11 ) ) ,
V_10 ) ) ;
V_21 = F_8 ( V_11 ) ;
V_6 . V_22 = 0 ;
V_6 . V_13 =
V_23 |
V_24 |
V_25 |
F_5 ( V_20 ) ;
V_6 . V_8 =
V_26 |
V_27 |
V_28 |
F_7 ( V_21 ) ;
F_9 ( V_11 , & V_6 ) ;
F_17 ( V_11 , & V_29 , V_30 ) ;
return 0 ;
}
void F_18 ( unsigned int V_11 )
{
F_19 ( V_11 ) ;
}
static void F_20 ( struct V_1 * V_8 )
{
F_21 ( V_8 -> V_11 ) ;
F_22 ( V_8 ) ;
F_23 () ;
}
static int F_24 ( struct V_1 * V_8 )
{
unsigned int V_21 = F_8 ( V_8 -> V_11 ) ;
F_25 ( V_21 ) ;
return 1 ;
}
int F_26 ( struct V_17 * V_18 , struct V_12 * V_19 )
{
if ( V_31 )
return V_31 ( V_18 , V_19 ) ;
return F_12 ( V_18 , V_19 ) ;
}
void F_27 ( unsigned int V_11 )
{
if ( V_32 )
return V_32 ( V_11 ) ;
return F_18 ( V_11 ) ;
}
static int F_28 ( struct V_1 * V_8 ,
const struct V_33 * V_34 , bool V_4 )
{
unsigned int V_11 = V_8 -> V_11 ;
struct V_35 * V_36 = V_35 + V_11 ;
struct V_5 V_6 ;
int V_9 = F_2 ( V_34 , V_10 ) ;
if ( F_3 ( V_11 , V_9 ) )
return - 1 ;
F_29 ( V_11 , & V_6 ) ;
V_6 . V_8 &= ~ V_15 ;
V_6 . V_8 |= F_7 ( V_36 -> V_21 ) ;
V_6 . V_13 &= ~ V_14 ;
V_6 . V_13 |= F_5 ( F_6 ( V_9 ) ) ;
F_30 ( V_11 , & V_6 ) ;
F_10 ( V_8 -> V_16 , V_34 ) ;
return 0 ;
}
static int
F_31 ( struct V_17 * V_18 , unsigned int V_11 , struct V_5 * V_6 )
{
struct V_35 * V_36 = V_35 + V_11 ;
unsigned V_37 ;
V_37 = F_6 ( F_2 ( & ( F_16 ( V_11 ) ) ,
V_10 ) ) ;
V_6 -> V_22 = 0 ;
V_6 -> V_13 =
V_23 |
V_24 |
V_25 |
F_5 ( V_37 ) ;
V_6 -> V_8 =
V_26 |
V_27 |
V_28 |
F_7 ( V_36 -> V_21 ) ;
return 0 ;
}
int F_32 ( unsigned int V_11 )
{
int V_38 ;
struct V_5 V_6 ;
V_38 = F_31 ( NULL , V_11 , & V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
F_30 ( V_11 , & V_6 ) ;
F_33 ( V_11 , & V_39 , V_30 ,
L_1 ) ;
return 0 ;
}
