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
static int F_12 ( struct V_23 * V_24 ,
unsigned long V_25 , void * V_26 )
{
struct V_13 * V_14 = F_13 ( V_24 ,
struct V_13 ,
V_27 ) ;
int V_16 ;
V_16 = F_10 ( V_14 -> V_6 -> V_8 , V_21 ,
V_28 ) ;
if ( V_16 )
F_8 ( V_14 -> V_6 -> V_19 , L_5 ,
V_16 ) ;
return V_29 ;
}
static int F_14 ( struct V_30 * V_31 )
{
int V_16 ;
struct V_6 * V_6 ;
struct V_13 * V_14 ;
if ( ! V_31 -> V_19 . V_32 )
return - V_33 ;
V_6 = F_15 ( V_31 -> V_19 . V_32 ) ;
if ( ! V_6 )
return - V_33 ;
V_14 = F_16 ( & V_31 -> V_19 , sizeof( * V_14 ) , V_34 ) ;
if ( ! V_14 )
return - V_35 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_17 . V_36 = & V_37 ;
V_14 -> V_17 . V_38 = & V_39 ;
V_14 -> V_17 . V_40 = V_41 ;
V_14 -> V_17 . V_42 = V_43 ;
V_14 -> V_17 . V_18 = V_44 ;
V_14 -> V_17 . V_45 = V_46 ;
F_17 ( & V_14 -> V_17 , V_14 ) ;
F_18 ( & V_31 -> V_19 , V_14 ) ;
V_16 = F_19 ( & V_14 -> V_17 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_27 . V_47 = F_12 ;
V_14 -> V_27 . V_48 = 128 ;
V_16 = F_20 ( & V_14 -> V_27 ) ;
if ( V_16 )
F_6 ( V_14 -> V_6 -> V_19 ,
L_6 , V_16 ) ;
return 0 ;
}
static int F_21 ( struct V_30 * V_31 )
{
struct V_13 * V_14 = F_15 ( & V_31 -> V_19 ) ;
F_22 ( & V_14 -> V_27 ) ;
F_23 ( & V_14 -> V_17 ) ;
return 0 ;
}
