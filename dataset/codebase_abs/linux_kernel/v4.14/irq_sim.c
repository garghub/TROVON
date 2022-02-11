static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = false ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = true ;
}
static void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = F_5 ( V_7 , struct V_8 , V_7 ) ;
F_6 ( F_7 ( V_9 -> V_10 ) ) ;
}
int F_8 ( struct V_11 * V_12 , unsigned int V_13 )
{
int V_14 ;
V_12 -> V_15 = F_9 ( V_13 , sizeof( * V_12 -> V_15 ) , V_16 ) ;
if ( ! V_12 -> V_15 )
return - V_17 ;
V_12 -> V_18 = F_10 ( - 1 , 0 , V_13 , 0 ) ;
if ( V_12 -> V_18 < 0 ) {
F_11 ( V_12 -> V_15 ) ;
return V_12 -> V_18 ;
}
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] . V_19 = V_12 -> V_18 + V_14 ;
V_12 -> V_15 [ V_14 ] . V_5 = false ;
F_12 ( V_12 -> V_18 + V_14 , & V_20 ) ;
F_13 ( V_12 -> V_18 + V_14 , & V_12 -> V_15 [ V_14 ] ) ;
F_14 ( V_12 -> V_18 + V_14 , & F_6 ) ;
F_15 ( V_12 -> V_18 + V_14 ,
V_21 | V_22 , V_23 ) ;
}
F_16 ( & V_12 -> V_9 . V_7 , F_4 ) ;
V_12 -> V_24 = V_13 ;
return 0 ;
}
void F_17 ( struct V_11 * V_12 )
{
F_18 ( & V_12 -> V_9 . V_7 ) ;
F_19 ( V_12 -> V_18 , V_12 -> V_24 ) ;
F_11 ( V_12 -> V_15 ) ;
}
static void F_20 ( struct V_25 * V_26 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
F_17 ( V_29 -> V_12 ) ;
}
int F_21 ( struct V_25 * V_26 , struct V_11 * V_12 ,
unsigned int V_13 )
{
struct V_28 * V_30 ;
int V_31 ;
V_30 = F_22 ( F_20 , sizeof( * V_30 ) , V_16 ) ;
if ( ! V_30 )
return - V_17 ;
V_31 = F_8 ( V_12 , V_13 ) ;
if ( V_31 ) {
F_23 ( V_30 ) ;
return V_31 ;
}
V_30 -> V_12 = V_12 ;
F_24 ( V_26 , V_30 ) ;
return 0 ;
}
void F_25 ( struct V_11 * V_12 , unsigned int V_32 )
{
if ( V_12 -> V_15 [ V_32 ] . V_5 ) {
V_12 -> V_9 . V_10 = F_26 ( V_12 , V_32 ) ;
F_27 ( & V_12 -> V_9 . V_7 ) ;
}
}
int F_26 ( struct V_11 * V_12 , unsigned int V_32 )
{
return V_12 -> V_15 [ V_32 ] . V_19 ;
}
