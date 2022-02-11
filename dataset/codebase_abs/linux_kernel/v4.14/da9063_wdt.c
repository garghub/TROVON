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
struct V_6 * V_6 = F_5 ( V_12 ) ;
unsigned int V_13 ;
int V_14 ;
V_13 = F_1 ( V_12 -> V_15 ) ;
V_14 = F_2 ( V_6 , V_13 ) ;
if ( V_14 )
F_6 ( V_6 -> V_16 , L_1 ,
V_14 ) ;
return V_14 ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_6 * V_6 = F_5 ( V_12 ) ;
int V_14 ;
V_14 = F_3 ( V_6 -> V_8 , V_9 ,
V_10 , V_17 ) ;
if ( V_14 )
F_8 ( V_6 -> V_16 , L_2 ,
V_14 ) ;
return V_14 ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_6 * V_6 = F_5 ( V_12 ) ;
int V_14 ;
V_14 = F_10 ( V_6 -> V_8 , V_18 ,
V_19 ) ;
if ( V_14 )
F_8 ( V_6 -> V_16 , L_3 ,
V_14 ) ;
return V_14 ;
}
static int F_11 ( struct V_11 * V_12 ,
unsigned int V_15 )
{
struct V_6 * V_6 = F_5 ( V_12 ) ;
unsigned int V_13 ;
int V_14 ;
V_13 = F_1 ( V_15 ) ;
V_14 = F_2 ( V_6 , V_13 ) ;
if ( V_14 )
F_6 ( V_6 -> V_16 , L_4 ,
V_14 ) ;
else
V_12 -> V_15 = V_5 [ V_13 ] ;
return V_14 ;
}
static int F_12 ( struct V_11 * V_12 , unsigned long V_20 ,
void * V_21 )
{
struct V_6 * V_6 = F_5 ( V_12 ) ;
int V_14 ;
V_14 = F_10 ( V_6 -> V_8 , V_18 ,
V_22 ) ;
if ( V_14 )
F_8 ( V_6 -> V_16 , L_5 ,
V_14 ) ;
return V_14 ;
}
static int F_13 ( struct V_23 * V_24 )
{
struct V_6 * V_6 ;
struct V_11 * V_12 ;
if ( ! V_24 -> V_16 . V_25 )
return - V_26 ;
V_6 = F_14 ( V_24 -> V_16 . V_25 ) ;
if ( ! V_6 )
return - V_26 ;
V_12 = F_15 ( & V_24 -> V_16 , sizeof( * V_12 ) , V_27 ) ;
if ( ! V_12 )
return - V_28 ;
V_12 -> V_29 = & V_30 ;
V_12 -> V_31 = & V_32 ;
V_12 -> V_33 = V_34 ;
V_12 -> V_35 = V_36 ;
V_12 -> V_37 = V_38 ;
V_12 -> V_15 = V_39 ;
V_12 -> V_25 = & V_24 -> V_16 ;
V_12 -> V_40 = V_41 ;
F_16 ( V_12 , 128 ) ;
F_17 ( V_12 , V_6 ) ;
return F_18 ( & V_24 -> V_16 , V_12 ) ;
}
