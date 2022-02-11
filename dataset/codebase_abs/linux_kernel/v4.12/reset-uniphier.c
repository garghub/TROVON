static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , int assert )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 ;
for ( V_7 = V_5 -> V_8 ; V_7 -> V_3 != V_9 ; V_7 ++ ) {
unsigned int V_10 , V_11 ;
if ( V_7 -> V_3 != V_3 )
continue;
V_10 = F_3 ( V_7 -> V_12 ) ;
if ( assert )
V_11 = V_10 ;
else
V_11 = ~ V_10 ;
if ( V_7 -> V_13 & V_14 )
V_11 = ~ V_11 ;
return F_4 ( V_5 -> V_15 , V_7 -> V_16 , V_10 , V_11 ) ;
}
F_5 ( V_5 -> V_17 , L_1 , V_3 ) ;
return - V_18 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , 1 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 ;
for ( V_7 = V_5 -> V_8 ; V_7 -> V_3 != V_9 ; V_7 ++ ) {
unsigned int V_11 ;
int V_19 , V_20 ;
if ( V_7 -> V_3 != V_3 )
continue;
V_19 = F_9 ( V_5 -> V_15 , V_7 -> V_16 , & V_11 ) ;
if ( V_19 )
return V_19 ;
V_20 = ! ! ( V_11 & F_3 ( V_7 -> V_12 ) ) ;
if ( V_7 -> V_13 & V_14 )
V_20 = ! V_20 ;
return V_20 ;
}
F_5 ( V_5 -> V_17 , L_2 , V_3 ) ;
return - V_18 ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_23 * V_17 = & V_22 -> V_17 ;
struct V_4 * V_5 ;
const struct V_6 * V_7 , * V_8 ;
struct V_15 * V_15 ;
struct V_24 * V_25 ;
unsigned int V_26 = 0 ;
V_8 = F_11 ( V_17 ) ;
if ( F_12 ( ! V_8 ) )
return - V_18 ;
V_25 = F_13 ( V_17 -> V_27 ) ;
V_15 = F_14 ( V_25 ) ;
F_15 ( V_25 ) ;
if ( F_16 ( V_15 ) ) {
F_5 ( V_17 , L_3 ,
F_17 ( V_15 ) ) ;
return F_17 ( V_15 ) ;
}
V_5 = F_18 ( V_17 , sizeof( * V_5 ) , V_28 ) ;
if ( ! V_5 )
return - V_29 ;
for ( V_7 = V_8 ; V_7 -> V_3 != V_9 ; V_7 ++ )
V_26 = F_19 ( V_26 , V_7 -> V_3 + 1 ) ;
V_5 -> V_2 . V_30 = & V_31 ;
V_5 -> V_2 . V_32 = V_17 -> V_33 -> V_32 ;
V_5 -> V_2 . V_27 = V_17 -> V_27 ;
V_5 -> V_2 . V_26 = V_26 ;
V_5 -> V_17 = V_17 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_8 = V_8 ;
return F_20 ( & V_22 -> V_17 , & V_5 -> V_2 ) ;
}
