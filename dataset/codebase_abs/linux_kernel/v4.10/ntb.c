int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 )
{
if ( ! V_2 )
return - V_6 ;
if ( ! F_2 ( & V_2 -> V_7 ) )
return - V_6 ;
memset ( & V_2 -> V_8 , 0 , sizeof( V_2 -> V_8 ) ) ;
V_2 -> V_8 . V_9 = & V_10 ;
V_2 -> V_8 . V_11 = V_5 ;
V_2 -> V_8 . V_12 = V_4 ;
return F_3 ( & V_2 -> V_8 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_8 ) ;
}
int F_6 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return - V_6 ;
if ( ! V_14 -> V_15 )
return - V_6 ;
if ( ! V_14 -> V_7 )
return - V_6 ;
if ( ! F_7 ( V_14 -> V_7 ) )
return - V_6 ;
F_8 ( & V_14 -> V_16 ) ;
memset ( & V_14 -> V_17 , 0 , sizeof( V_14 -> V_17 ) ) ;
V_14 -> V_17 . V_9 = & V_10 ;
V_14 -> V_17 . V_18 = & V_14 -> V_15 -> V_17 ;
V_14 -> V_17 . V_19 = V_20 ;
F_9 ( & V_14 -> V_17 , L_1 , F_10 ( V_14 -> V_15 ) ) ;
V_14 -> V_21 = NULL ;
V_14 -> V_22 = NULL ;
F_11 ( & V_14 -> V_23 ) ;
return F_12 ( & V_14 -> V_17 ) ;
}
void F_13 ( struct V_13 * V_14 )
{
F_14 ( & V_14 -> V_17 ) ;
F_15 ( & V_14 -> V_16 ) ;
}
int F_16 ( struct V_13 * V_14 , void * V_21 ,
const struct V_24 * V_22 )
{
unsigned long V_25 ;
if ( ! F_17 ( V_22 ) )
return - V_6 ;
if ( V_14 -> V_22 )
return - V_6 ;
F_18 ( & V_14 -> V_23 , V_25 ) ;
{
V_14 -> V_21 = V_21 ;
V_14 -> V_22 = V_22 ;
}
F_19 ( & V_14 -> V_23 , V_25 ) ;
return 0 ;
}
void F_20 ( struct V_13 * V_14 )
{
unsigned long V_25 ;
F_18 ( & V_14 -> V_23 , V_25 ) ;
{
V_14 -> V_22 = NULL ;
V_14 -> V_21 = NULL ;
}
F_19 ( & V_14 -> V_23 , V_25 ) ;
}
void F_21 ( struct V_13 * V_14 )
{
unsigned long V_25 ;
F_18 ( & V_14 -> V_23 , V_25 ) ;
{
if ( V_14 -> V_22 && V_14 -> V_22 -> V_26 )
V_14 -> V_22 -> V_26 ( V_14 -> V_21 ) ;
}
F_19 ( & V_14 -> V_23 , V_25 ) ;
}
void F_22 ( struct V_13 * V_14 , int V_27 )
{
unsigned long V_25 ;
F_18 ( & V_14 -> V_23 , V_25 ) ;
{
if ( V_14 -> V_22 && V_14 -> V_22 -> V_28 )
V_14 -> V_22 -> V_28 ( V_14 -> V_21 , V_27 ) ;
}
F_19 ( & V_14 -> V_23 , V_25 ) ;
}
static int F_23 ( struct V_29 * V_17 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_30 ;
F_24 ( V_17 ) ;
V_14 = F_25 ( V_17 ) ;
V_2 = F_26 ( V_17 -> V_31 ) ;
V_30 = V_2 -> V_7 . V_32 ( V_2 , V_14 ) ;
if ( V_30 )
F_27 ( V_17 ) ;
return V_30 ;
}
static int F_28 ( struct V_29 * V_17 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
if ( V_17 -> V_31 ) {
V_14 = F_25 ( V_17 ) ;
V_2 = F_26 ( V_17 -> V_31 ) ;
V_2 -> V_7 . remove ( V_2 , V_14 ) ;
F_27 ( V_17 ) ;
}
return 0 ;
}
static void V_20 ( struct V_29 * V_17 )
{
struct V_13 * V_14 = F_25 ( V_17 ) ;
F_29 ( & V_14 -> V_16 ) ;
}
static int T_1 F_30 ( void )
{
return F_31 ( & V_10 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_10 ) ;
}
