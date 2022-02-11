static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
}
static void F_2 ( struct V_1 * V_2 )
{
unsigned long V_5 = F_3 ( V_6 ) ;
unsigned long V_7 = V_2 -> V_3 + V_5 ;
unsigned long V_8 = V_4 ;
unsigned int V_9 ;
if ( F_4 ( V_8 , V_7 ) ) {
V_9 = F_5 ( V_7 - V_8 ) ;
F_6 ( V_2 -> V_10 -> V_11 ,
L_1 , V_9 ) ;
F_7 ( V_9 ) ;
}
}
static unsigned int F_8 ( unsigned int V_12 )
{
unsigned int V_13 ;
for ( V_13 = V_14 ; V_13 <= V_15 ; V_13 ++ ) {
if ( V_16 [ V_13 ] >= V_12 )
return V_13 ;
}
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_17 ;
F_2 ( V_2 ) ;
V_17 = F_10 ( V_2 -> V_10 -> V_18 ,
V_19 ,
V_20 ,
V_20 ) ;
F_1 ( V_2 ) ;
return V_17 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
struct V_22 * V_23 = V_2 -> V_10 ;
int V_17 ;
V_17 = F_9 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return F_10 ( V_23 -> V_18 ,
V_24 ,
V_25 ,
V_21 ) ;
}
static int F_12 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
unsigned int V_28 ;
int V_17 ;
V_28 = F_8 ( V_2 -> V_29 . V_7 ) ;
V_17 = F_11 ( V_2 , V_28 ) ;
if ( V_17 )
F_14 ( V_2 -> V_10 -> V_11 , L_2 ,
V_17 ) ;
return V_17 ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_17 ;
V_17 = F_9 ( V_2 ) ;
if ( V_17 ) {
F_14 ( V_2 -> V_10 -> V_11 , L_3 ,
V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_2 -> V_10 -> V_18 ,
V_24 ,
V_25 ,
V_30 ) ;
if ( V_17 )
F_14 ( V_2 -> V_10 -> V_11 , L_4 ,
V_17 ) ;
return V_17 ;
}
static int F_16 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_17 ;
V_17 = F_9 ( V_2 ) ;
if ( V_17 )
F_14 ( V_2 -> V_10 -> V_11 , L_3 ,
V_17 ) ;
return V_17 ;
}
static int F_17 ( struct V_26 * V_27 ,
unsigned int V_7 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
unsigned int V_28 ;
int V_17 ;
V_28 = F_8 ( V_7 ) ;
V_17 = F_11 ( V_2 , V_28 ) ;
if ( V_17 )
F_14 ( V_2 -> V_10 -> V_11 , L_5 ,
V_17 ) ;
else
V_27 -> V_7 = V_16 [ V_28 ] ;
return V_17 ;
}
static int F_18 ( struct V_31 * V_32 )
{
int V_17 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
V_23 = F_19 ( V_32 -> V_11 . V_33 ) ;
if ( ! V_23 )
return - V_34 ;
V_2 = F_20 ( & V_32 -> V_11 , sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_10 = V_23 ;
V_2 -> V_29 . V_37 = & V_38 ;
V_2 -> V_29 . V_39 = & V_40 ;
V_2 -> V_29 . V_41 = V_42 ;
V_2 -> V_29 . V_43 = V_44 ;
V_2 -> V_29 . V_7 = V_45 ;
V_2 -> V_29 . V_46 = V_47 ;
F_21 ( & V_2 -> V_29 , V_2 ) ;
F_22 ( & V_32 -> V_11 , V_2 ) ;
V_17 = F_23 ( & V_2 -> V_29 ) ;
if ( V_17 < 0 ) {
F_14 ( V_2 -> V_10 -> V_11 ,
L_6 , V_17 ) ;
return V_17 ;
}
F_1 ( V_2 ) ;
V_17 = F_16 ( & V_2 -> V_29 ) ;
if ( V_17 < 0 )
F_24 ( & V_2 -> V_29 ) ;
return V_17 ;
}
static int F_25 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_19 ( & V_32 -> V_11 ) ;
F_24 ( & V_2 -> V_29 ) ;
return 0 ;
}
