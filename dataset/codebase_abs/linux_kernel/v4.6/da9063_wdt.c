static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
for ( V_2 = V_3 ; V_2 <= V_4 ; V_2 ++ ) {
if ( V_5 [ V_2 ] >= V_1 )
return V_2 ;
}
return V_4 ;
}
static int F_2 ( struct V_6 * V_6 , unsigned int V_7 )
{
return F_3 ( V_6 -> V_8 , V_9 ,
V_10 , V_7 ) ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
unsigned int V_15 ;
int V_16 ;
V_15 = F_1 ( V_14 -> V_17 . V_18 ) ;
V_16 = F_2 ( V_14 -> V_6 , V_15 ) ;
if ( V_16 )
F_6 ( V_14 -> V_6 -> V_19 , L_1 ,
V_16 ) ;
return V_16 ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
int V_16 ;
V_16 = F_3 ( V_14 -> V_6 -> V_8 , V_9 ,
V_10 , V_20 ) ;
if ( V_16 )
F_8 ( V_14 -> V_6 -> V_19 , L_2 ,
V_16 ) ;
return V_16 ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
int V_16 ;
V_16 = F_10 ( V_14 -> V_6 -> V_8 , V_21 ,
V_22 ) ;
if ( V_16 )
F_8 ( V_14 -> V_6 -> V_19 , L_3 ,
V_16 ) ;
return V_16 ;
}
static int F_11 ( struct V_11 * V_12 ,
unsigned int V_18 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
unsigned int V_15 ;
int V_16 ;
V_15 = F_1 ( V_18 ) ;
V_16 = F_2 ( V_14 -> V_6 , V_15 ) ;
if ( V_16 )
F_6 ( V_14 -> V_6 -> V_19 , L_4 ,
V_16 ) ;
else
V_12 -> V_18 = V_5 [ V_15 ] ;
return V_16 ;
}
static int F_12 ( struct V_11 * V_12 , unsigned long V_23 ,
void * V_24 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
int V_16 ;
V_16 = F_10 ( V_14 -> V_6 -> V_8 , V_21 ,
V_25 ) ;
if ( V_16 )
F_8 ( V_14 -> V_6 -> V_19 , L_5 ,
V_16 ) ;
return V_16 ;
}
static int F_13 ( struct V_26 * V_27 )
{
int V_16 ;
struct V_6 * V_6 ;
struct V_13 * V_14 ;
if ( ! V_27 -> V_19 . V_28 )
return - V_29 ;
V_6 = F_14 ( V_27 -> V_19 . V_28 ) ;
if ( ! V_6 )
return - V_29 ;
V_14 = F_15 ( & V_27 -> V_19 , sizeof( * V_14 ) , V_30 ) ;
if ( ! V_14 )
return - V_31 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_17 . V_32 = & V_33 ;
V_14 -> V_17 . V_34 = & V_35 ;
V_14 -> V_17 . V_36 = V_37 ;
V_14 -> V_17 . V_38 = V_39 ;
V_14 -> V_17 . V_18 = V_40 ;
V_14 -> V_17 . V_28 = & V_27 -> V_19 ;
V_14 -> V_17 . V_41 = V_42 ;
F_16 ( & V_14 -> V_17 , 128 ) ;
F_17 ( & V_14 -> V_17 , V_14 ) ;
F_18 ( & V_27 -> V_19 , V_14 ) ;
V_16 = F_19 ( & V_14 -> V_17 ) ;
if ( V_16 )
return V_16 ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_14 ( & V_27 -> V_19 ) ;
F_21 ( & V_14 -> V_17 ) ;
return 0 ;
}
