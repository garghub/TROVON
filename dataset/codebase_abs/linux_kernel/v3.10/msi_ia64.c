static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , bool V_4 )
{
struct V_5 V_6 ;
T_2 V_7 , V_8 ;
int V_9 = F_2 ( * V_3 ) ;
unsigned int V_10 = V_2 -> V_10 ;
if ( ! F_3 ( V_9 ) )
return - 1 ;
if ( F_4 ( V_10 , V_9 ) )
return - 1 ;
F_5 ( V_10 , & V_6 ) ;
V_7 = V_6 . V_11 ;
V_7 &= V_12 ;
V_7 |= F_6 ( F_7 ( V_9 ) ) ;
V_6 . V_11 = V_7 ;
V_8 = V_6 . V_8 ;
V_8 &= V_13 ;
V_8 |= F_8 ( F_9 ( V_10 ) ) ;
V_6 . V_8 = V_8 ;
F_10 ( V_10 , & V_6 ) ;
F_11 ( V_2 -> V_14 , F_12 ( V_9 ) ) ;
return 0 ;
}
int F_13 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_5 V_6 ;
unsigned long V_19 ;
int V_10 , V_20 ;
T_1 V_21 ;
V_10 = F_14 () ;
if ( V_10 < 0 )
return V_10 ;
F_15 ( V_10 , V_18 ) ;
F_16 ( & V_21 , & ( F_17 ( V_10 ) ) , V_22 ) ;
V_19 = F_7 ( F_2 ( V_21 ) ) ;
V_20 = F_9 ( V_10 ) ;
V_6 . V_23 = 0 ;
V_6 . V_11 =
V_24 |
V_25 |
V_26 |
F_6 ( V_19 ) ;
V_6 . V_8 =
V_27 |
V_28 |
V_29 |
F_8 ( V_20 ) ;
F_10 ( V_10 , & V_6 ) ;
F_18 ( V_10 , & V_30 , V_31 ) ;
return 0 ;
}
void F_19 ( unsigned int V_10 )
{
F_20 ( V_10 ) ;
}
static void F_21 ( struct V_1 * V_8 )
{
F_22 ( V_8 -> V_10 ) ;
F_23 ( V_8 ) ;
F_24 () ;
}
static int F_25 ( struct V_1 * V_8 )
{
unsigned int V_20 = F_9 ( V_8 -> V_10 ) ;
F_26 ( V_20 ) ;
return 1 ;
}
int F_27 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( V_32 )
return V_32 ( V_16 , V_18 ) ;
return F_13 ( V_16 , V_18 ) ;
}
void F_28 ( unsigned int V_10 )
{
if ( V_33 )
return V_33 ( V_10 ) ;
return F_19 ( V_10 ) ;
}
static int F_29 ( struct V_1 * V_8 ,
const struct V_34 * V_21 , bool V_4 )
{
unsigned int V_10 = V_8 -> V_10 ;
struct V_35 * V_36 = V_35 + V_10 ;
struct V_5 V_6 ;
int V_9 = F_30 ( V_21 ) ;
if ( ! F_3 ( V_9 ) )
return - 1 ;
if ( F_4 ( V_10 , V_9 ) )
return - 1 ;
F_31 ( V_10 , & V_6 ) ;
V_6 . V_8 &= ~ V_13 ;
V_6 . V_8 |= F_8 ( V_36 -> V_20 ) ;
V_6 . V_11 &= ~ V_12 ;
V_6 . V_11 |= F_6 ( F_7 ( V_9 ) ) ;
F_32 ( V_10 , & V_6 ) ;
F_11 ( V_8 -> V_14 , V_21 ) ;
return 0 ;
}
static int
F_33 ( struct V_15 * V_16 , unsigned int V_10 , struct V_5 * V_6 )
{
struct V_35 * V_36 = V_35 + V_10 ;
unsigned V_37 ;
T_1 V_21 ;
F_16 ( & V_21 , & ( F_17 ( V_10 ) ) , V_22 ) ;
V_37 = F_7 ( F_2 ( V_21 ) ) ;
V_6 -> V_23 = 0 ;
V_6 -> V_11 =
V_24 |
V_25 |
V_26 |
F_6 ( V_37 ) ;
V_6 -> V_8 =
V_27 |
V_28 |
V_29 |
F_8 ( V_36 -> V_20 ) ;
return 0 ;
}
int F_34 ( unsigned int V_10 )
{
int V_38 ;
struct V_5 V_6 ;
V_38 = F_33 ( NULL , V_10 , & V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
F_32 ( V_10 , & V_6 ) ;
F_35 ( V_10 , & V_39 , V_31 ,
L_1 ) ;
return 0 ;
}
