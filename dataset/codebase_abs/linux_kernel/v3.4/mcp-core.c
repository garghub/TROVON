static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_4 = F_4 ( V_2 -> V_7 ) ;
return V_4 -> V_8 ( V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_4 = F_4 ( V_2 -> V_7 ) ;
V_4 -> remove ( V_5 ) ;
return 0 ;
}
void F_6 ( struct V_5 * V_5 , unsigned int div )
{
unsigned long V_9 ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_11 -> V_12 ( V_5 , div ) ;
F_8 ( & V_5 -> V_10 , V_9 ) ;
}
void F_9 ( struct V_5 * V_5 , unsigned int div )
{
unsigned long V_9 ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_11 -> V_13 ( V_5 , div ) ;
F_8 ( & V_5 -> V_10 , V_9 ) ;
}
void F_10 ( struct V_5 * V_5 , unsigned int V_14 , unsigned int V_15 )
{
unsigned long V_9 ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_11 -> V_16 ( V_5 , V_14 , V_15 ) ;
F_8 ( & V_5 -> V_10 , V_9 ) ;
}
unsigned int F_11 ( struct V_5 * V_5 , unsigned int V_14 )
{
unsigned long V_9 ;
unsigned int V_15 ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
V_15 = V_5 -> V_11 -> V_17 ( V_5 , V_14 ) ;
F_8 ( & V_5 -> V_10 , V_9 ) ;
return V_15 ;
}
void F_12 ( struct V_5 * V_5 )
{
unsigned long V_9 ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
if ( V_5 -> V_18 ++ == 0 )
V_5 -> V_11 -> V_19 ( V_5 ) ;
F_8 ( & V_5 -> V_10 , V_9 ) ;
}
void F_13 ( struct V_5 * V_5 )
{
unsigned long V_9 ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
if ( -- V_5 -> V_18 == 0 )
V_5 -> V_11 -> V_20 ( V_5 ) ;
F_8 ( & V_5 -> V_10 , V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_15 ( V_2 , struct V_5 , V_21 ) ;
F_16 ( V_5 ) ;
}
struct V_5 * F_17 ( struct V_1 * V_22 , T_1 V_23 )
{
struct V_5 * V_5 ;
V_5 = F_18 ( sizeof( struct V_5 ) + V_23 , V_24 ) ;
if ( V_5 ) {
F_19 ( & V_5 -> V_10 ) ;
F_20 ( & V_5 -> V_21 ) ;
V_5 -> V_21 . V_22 = V_22 ;
V_5 -> V_21 . V_25 = & V_26 ;
V_5 -> V_21 . V_27 = V_22 -> V_27 ;
V_5 -> V_21 . V_28 = F_14 ;
}
return V_5 ;
}
int F_21 ( struct V_5 * V_5 , void * V_29 )
{
V_5 -> V_21 . V_30 = V_29 ;
F_22 ( & V_5 -> V_21 , L_1 ) ;
return F_23 ( & V_5 -> V_21 ) ;
}
void F_24 ( struct V_5 * V_5 )
{
F_25 ( & V_5 -> V_21 ) ;
}
void F_26 ( struct V_5 * V_5 )
{
F_27 ( & V_5 -> V_21 ) ;
}
int F_28 ( struct V_6 * V_31 )
{
V_31 -> V_4 . V_25 = & V_26 ;
return F_29 ( & V_31 -> V_4 ) ;
}
void F_30 ( struct V_6 * V_31 )
{
F_31 ( & V_31 -> V_4 ) ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_26 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_26 ) ;
}
