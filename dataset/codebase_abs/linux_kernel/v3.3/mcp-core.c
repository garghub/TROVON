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
static int F_6 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
int V_10 = 0 ;
if ( V_2 -> V_7 ) {
struct V_6 * V_4 = F_4 ( V_2 -> V_7 ) ;
V_10 = V_4 -> V_11 ( V_5 , V_9 ) ;
}
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ) ;
int V_10 = 0 ;
if ( V_2 -> V_7 ) {
struct V_6 * V_4 = F_4 ( V_2 -> V_7 ) ;
V_10 = V_4 -> V_12 ( V_5 ) ;
}
return V_10 ;
}
void F_8 ( struct V_5 * V_5 , unsigned int div )
{
unsigned long V_13 ;
F_9 ( & V_5 -> V_14 , V_13 ) ;
V_5 -> V_15 -> V_16 ( V_5 , div ) ;
F_10 ( & V_5 -> V_14 , V_13 ) ;
}
void F_11 ( struct V_5 * V_5 , unsigned int div )
{
unsigned long V_13 ;
F_9 ( & V_5 -> V_14 , V_13 ) ;
V_5 -> V_15 -> V_17 ( V_5 , div ) ;
F_10 ( & V_5 -> V_14 , V_13 ) ;
}
void F_12 ( struct V_5 * V_5 , unsigned int V_18 , unsigned int V_19 )
{
unsigned long V_13 ;
F_9 ( & V_5 -> V_14 , V_13 ) ;
V_5 -> V_15 -> V_20 ( V_5 , V_18 , V_19 ) ;
F_10 ( & V_5 -> V_14 , V_13 ) ;
}
unsigned int F_13 ( struct V_5 * V_5 , unsigned int V_18 )
{
unsigned long V_13 ;
unsigned int V_19 ;
F_9 ( & V_5 -> V_14 , V_13 ) ;
V_19 = V_5 -> V_15 -> V_21 ( V_5 , V_18 ) ;
F_10 ( & V_5 -> V_14 , V_13 ) ;
return V_19 ;
}
void F_14 ( struct V_5 * V_5 )
{
unsigned long V_13 ;
F_9 ( & V_5 -> V_14 , V_13 ) ;
if ( V_5 -> V_22 ++ == 0 )
V_5 -> V_15 -> V_23 ( V_5 ) ;
F_10 ( & V_5 -> V_14 , V_13 ) ;
}
void F_15 ( struct V_5 * V_5 )
{
unsigned long V_13 ;
F_9 ( & V_5 -> V_14 , V_13 ) ;
if ( -- V_5 -> V_22 == 0 )
V_5 -> V_15 -> V_24 ( V_5 ) ;
F_10 ( & V_5 -> V_14 , V_13 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_17 ( V_2 , struct V_5 , V_25 ) ;
F_18 ( V_5 ) ;
}
struct V_5 * F_19 ( struct V_1 * V_26 , T_2 V_27 )
{
struct V_5 * V_5 ;
V_5 = F_20 ( sizeof( struct V_5 ) + V_27 , V_28 ) ;
if ( V_5 ) {
F_21 ( & V_5 -> V_14 ) ;
V_5 -> V_25 . V_26 = V_26 ;
V_5 -> V_25 . V_29 = & V_30 ;
V_5 -> V_25 . V_31 = V_26 -> V_31 ;
V_5 -> V_25 . V_32 = F_16 ;
}
return V_5 ;
}
int F_22 ( struct V_5 * V_5 )
{
F_23 ( & V_5 -> V_25 , L_1 ) ;
return F_24 ( & V_5 -> V_25 ) ;
}
void F_25 ( struct V_5 * V_5 )
{
F_26 ( & V_5 -> V_25 ) ;
}
int F_27 ( struct V_6 * V_33 )
{
V_33 -> V_4 . V_29 = & V_30 ;
return F_28 ( & V_33 -> V_4 ) ;
}
void F_29 ( struct V_6 * V_33 )
{
F_30 ( & V_33 -> V_4 ) ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_30 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_30 ) ;
}
