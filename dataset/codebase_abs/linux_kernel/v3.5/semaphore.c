void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( F_3 ( V_2 -> V_5 > 0 ) )
V_2 -> V_5 -- ;
else
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_4 , V_3 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_6 = 0 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( F_3 ( V_2 -> V_5 > 0 ) )
V_2 -> V_5 -- ;
else
V_6 = F_7 ( V_2 ) ;
F_5 ( & V_2 -> V_4 , V_3 ) ;
return V_6 ;
}
int F_8 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_6 = 0 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( F_3 ( V_2 -> V_5 > 0 ) )
V_2 -> V_5 -- ;
else
V_6 = F_9 ( V_2 ) ;
F_5 ( & V_2 -> V_4 , V_3 ) ;
return V_6 ;
}
int F_10 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_5 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
V_5 = V_2 -> V_5 - 1 ;
if ( F_3 ( V_5 >= 0 ) )
V_2 -> V_5 = V_5 ;
F_5 ( & V_2 -> V_4 , V_3 ) ;
return ( V_5 < 0 ) ;
}
int F_11 ( struct V_1 * V_2 , long V_7 )
{
unsigned long V_3 ;
int V_6 = 0 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( F_3 ( V_2 -> V_5 > 0 ) )
V_2 -> V_5 -- ;
else
V_6 = F_12 ( V_2 , V_7 ) ;
F_5 ( & V_2 -> V_4 , V_3 ) ;
return V_6 ;
}
void F_13 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( F_3 ( F_14 ( & V_2 -> V_8 ) ) )
V_2 -> V_5 ++ ;
else
F_15 ( V_2 ) ;
F_5 ( & V_2 -> V_4 , V_3 ) ;
}
static inline int T_1 F_16 ( struct V_1 * V_2 , long V_9 ,
long V_10 )
{
struct V_11 * V_12 = V_13 ;
struct V_14 V_15 ;
F_17 ( & V_15 . V_16 , & V_2 -> V_8 ) ;
V_15 . V_12 = V_12 ;
V_15 . F_13 = 0 ;
for (; ; ) {
if ( F_18 ( V_9 , V_12 ) )
goto V_17;
if ( V_10 <= 0 )
goto V_18;
F_19 ( V_12 , V_9 ) ;
F_20 ( & V_2 -> V_4 ) ;
V_10 = F_21 ( V_10 ) ;
F_22 ( & V_2 -> V_4 ) ;
if ( V_15 . F_13 )
return 0 ;
}
V_18:
F_23 ( & V_15 . V_16 ) ;
return - V_19 ;
V_17:
F_23 ( & V_15 . V_16 ) ;
return - V_20 ;
}
static T_2 void T_1 F_4 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_21 , V_22 ) ;
}
static T_2 int T_1 F_7 ( struct V_1 * V_2 )
{
return F_16 ( V_2 , V_23 , V_22 ) ;
}
static T_2 int T_1 F_9 ( struct V_1 * V_2 )
{
return F_16 ( V_2 , V_24 , V_22 ) ;
}
static T_2 int T_1 F_12 ( struct V_1 * V_2 , long V_7 )
{
return F_16 ( V_2 , V_21 , V_7 ) ;
}
static T_2 void T_1 F_15 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_24 ( & V_2 -> V_8 ,
struct V_14 , V_16 ) ;
F_23 ( & V_15 -> V_16 ) ;
V_15 -> F_13 = 1 ;
F_25 ( V_15 -> V_12 ) ;
}
