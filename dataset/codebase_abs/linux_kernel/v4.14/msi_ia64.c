static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , bool V_4 )
{
struct V_5 V_6 ;
T_2 V_7 , V_8 ;
int V_9 = F_2 ( V_3 , V_10 ) ;
unsigned int V_11 = V_2 -> V_11 ;
if ( F_3 ( V_11 , V_9 ) )
return - 1 ;
F_4 ( F_5 ( V_2 ) , & V_6 ) ;
V_7 = V_6 . V_12 ;
V_7 &= V_13 ;
V_7 |= F_6 ( F_7 ( V_9 ) ) ;
V_6 . V_12 = V_7 ;
V_8 = V_6 . V_8 ;
V_8 &= V_14 ;
V_8 |= F_8 ( F_9 ( V_11 ) ) ;
V_6 . V_8 = V_8 ;
F_10 ( V_11 , & V_6 ) ;
F_11 ( F_12 ( V_2 ) , F_13 ( V_9 ) ) ;
return 0 ;
}
int F_14 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_5 V_6 ;
unsigned long V_19 ;
int V_11 , V_20 ;
V_11 = F_15 () ;
if ( V_11 < 0 )
return V_11 ;
F_16 ( V_11 , V_18 ) ;
V_19 = F_7 ( F_17 ( & ( F_18 ( V_11 ) ) ,
V_10 ) ) ;
V_20 = F_9 ( V_11 ) ;
V_6 . V_21 = 0 ;
V_6 . V_12 =
V_22 |
V_23 |
V_24 |
F_6 ( V_19 ) ;
V_6 . V_8 =
V_25 |
V_26 |
V_27 |
F_8 ( V_20 ) ;
F_10 ( V_11 , & V_6 ) ;
F_19 ( V_11 , & V_28 , V_29 ) ;
return 0 ;
}
void F_20 ( unsigned int V_11 )
{
F_21 ( V_11 ) ;
}
static void F_22 ( struct V_1 * V_8 )
{
F_23 ( V_8 -> V_11 ) ;
F_24 ( V_8 ) ;
F_25 () ;
}
static int F_26 ( struct V_1 * V_8 )
{
unsigned int V_20 = F_9 ( V_8 -> V_11 ) ;
F_27 ( V_20 ) ;
return 1 ;
}
int F_28 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
if ( V_30 )
return V_30 ( V_16 , V_18 ) ;
return F_14 ( V_16 , V_18 ) ;
}
void F_29 ( unsigned int V_11 )
{
if ( V_31 )
return V_31 ( V_11 ) ;
return F_20 ( V_11 ) ;
}
static int F_30 ( struct V_1 * V_8 ,
const struct V_32 * V_33 , bool V_4 )
{
unsigned int V_11 = V_8 -> V_11 ;
struct V_34 * V_35 = V_34 + V_11 ;
struct V_5 V_6 ;
int V_9 = F_2 ( V_33 , V_10 ) ;
if ( F_3 ( V_11 , V_9 ) )
return - 1 ;
F_31 ( V_11 , & V_6 ) ;
V_6 . V_8 &= ~ V_14 ;
V_6 . V_8 |= F_8 ( V_35 -> V_20 ) ;
V_6 . V_12 &= ~ V_13 ;
V_6 . V_12 |= F_6 ( F_7 ( V_9 ) ) ;
F_32 ( V_11 , & V_6 ) ;
F_11 ( F_12 ( V_8 ) , V_33 ) ;
return 0 ;
}
static void
F_33 ( struct V_15 * V_16 , unsigned int V_11 , struct V_5 * V_6 )
{
struct V_34 * V_35 = V_34 + V_11 ;
unsigned V_36 ;
V_36 = F_7 ( F_2 ( & ( F_18 ( V_11 ) ) ,
V_10 ) ) ;
V_6 -> V_21 = 0 ;
V_6 -> V_12 =
V_22 |
V_23 |
V_24 |
F_6 ( V_36 ) ;
V_6 -> V_8 =
V_25 |
V_26 |
V_27 |
F_8 ( V_35 -> V_20 ) ;
}
int F_34 ( int V_37 , int V_38 , void * V_39 )
{
int V_11 ;
struct V_5 V_6 ;
V_11 = F_15 () ;
if ( V_11 > 0 ) {
F_35 ( V_11 , V_39 ) ;
F_36 ( V_11 , & V_40 ,
V_29 , L_1 ) ;
F_33 ( NULL , V_11 , & V_6 ) ;
F_32 ( V_11 , & V_6 ) ;
}
return V_11 ;
}
void F_37 ( int V_11 )
{
F_35 ( V_11 , NULL ) ;
F_21 ( V_11 ) ;
}
