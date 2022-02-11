static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , bool V_4 )
{
struct V_5 V_6 ;
T_2 V_7 , V_8 ;
int V_9 = F_2 ( V_3 , V_10 ) ;
unsigned int V_11 = V_2 -> V_11 ;
if ( F_3 ( V_11 , V_9 ) )
return - 1 ;
F_4 ( V_11 , & V_6 ) ;
V_7 = V_6 . V_12 ;
V_7 &= V_13 ;
V_7 |= F_5 ( F_6 ( V_9 ) ) ;
V_6 . V_12 = V_7 ;
V_8 = V_6 . V_8 ;
V_8 &= V_14 ;
V_8 |= F_7 ( F_8 ( V_11 ) ) ;
V_6 . V_8 = V_8 ;
F_9 ( V_11 , & V_6 ) ;
F_10 ( V_2 -> V_15 , F_11 ( V_9 ) ) ;
return 0 ;
}
int F_12 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_5 V_6 ;
unsigned long V_20 ;
int V_11 , V_21 ;
T_1 V_22 ;
V_11 = F_13 () ;
if ( V_11 < 0 )
return V_11 ;
F_14 ( V_11 , V_19 ) ;
F_15 ( & V_22 , & ( F_16 ( V_11 ) ) , V_10 ) ;
V_20 = F_6 ( F_17 ( V_22 ) ) ;
V_21 = F_8 ( V_11 ) ;
V_6 . V_23 = 0 ;
V_6 . V_12 =
V_24 |
V_25 |
V_26 |
F_5 ( V_20 ) ;
V_6 . V_8 =
V_27 |
V_28 |
V_29 |
F_7 ( V_21 ) ;
F_9 ( V_11 , & V_6 ) ;
F_18 ( V_11 , & V_30 , V_31 ) ;
return 0 ;
}
void F_19 ( unsigned int V_11 )
{
F_20 ( V_11 ) ;
}
static void F_21 ( struct V_1 * V_8 )
{
F_22 ( V_8 -> V_11 ) ;
F_23 ( V_8 ) ;
F_24 () ;
}
static int F_25 ( struct V_1 * V_8 )
{
unsigned int V_21 = F_8 ( V_8 -> V_11 ) ;
F_26 ( V_21 ) ;
return 1 ;
}
int F_27 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
if ( V_32 )
return V_32 ( V_17 , V_19 ) ;
return F_12 ( V_17 , V_19 ) ;
}
void F_28 ( unsigned int V_11 )
{
if ( V_33 )
return V_33 ( V_11 ) ;
return F_19 ( V_11 ) ;
}
static int F_29 ( struct V_1 * V_8 ,
const struct V_34 * V_22 , bool V_4 )
{
unsigned int V_11 = V_8 -> V_11 ;
struct V_35 * V_36 = V_35 + V_11 ;
struct V_5 V_6 ;
int V_9 = F_2 ( V_22 , V_10 ) ;
if ( F_3 ( V_11 , V_9 ) )
return - 1 ;
F_30 ( V_11 , & V_6 ) ;
V_6 . V_8 &= ~ V_14 ;
V_6 . V_8 |= F_7 ( V_36 -> V_21 ) ;
V_6 . V_12 &= ~ V_13 ;
V_6 . V_12 |= F_5 ( F_6 ( V_9 ) ) ;
F_31 ( V_11 , & V_6 ) ;
F_10 ( V_8 -> V_15 , V_22 ) ;
return 0 ;
}
static int
F_32 ( struct V_16 * V_17 , unsigned int V_11 , struct V_5 * V_6 )
{
struct V_35 * V_36 = V_35 + V_11 ;
unsigned V_37 ;
T_1 V_22 ;
F_15 ( & V_22 , & ( F_16 ( V_11 ) ) , V_10 ) ;
V_37 = F_6 ( F_17 ( V_22 ) ) ;
V_6 -> V_23 = 0 ;
V_6 -> V_12 =
V_24 |
V_25 |
V_26 |
F_5 ( V_37 ) ;
V_6 -> V_8 =
V_27 |
V_28 |
V_29 |
F_7 ( V_36 -> V_21 ) ;
return 0 ;
}
int F_33 ( unsigned int V_11 )
{
int V_38 ;
struct V_5 V_6 ;
V_38 = F_32 ( NULL , V_11 , & V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
F_31 ( V_11 , & V_6 ) ;
F_34 ( V_11 , & V_39 , V_31 ,
L_1 ) ;
return 0 ;
}
