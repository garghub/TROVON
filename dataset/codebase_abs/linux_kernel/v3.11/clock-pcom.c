static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
unsigned V_5 = F_1 ( V_3 ) -> V_5 ;
int V_6 = F_5 ( V_7 , & V_5 , NULL ) ;
if ( V_6 < 0 )
return V_6 ;
else
return ( int ) V_5 < 0 ? - V_8 : 0 ;
}
static void F_6 ( struct V_2 * V_3 )
{
unsigned V_5 = F_1 ( V_3 ) -> V_5 ;
F_5 ( V_9 , & V_5 , NULL ) ;
}
static int F_7 ( struct V_2 * V_3 , enum V_10 V_11 )
{
int V_6 ;
unsigned V_5 = F_1 ( V_3 ) -> V_5 ;
if ( V_11 == V_12 )
V_6 = F_5 ( V_13 , & V_5 , NULL ) ;
else
V_6 = F_5 ( V_14 , & V_5 , NULL ) ;
if ( V_6 < 0 )
return V_6 ;
else
return ( int ) V_5 < 0 ? - V_8 : 0 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned long V_15 ,
unsigned long V_16 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
unsigned V_5 = V_17 -> V_5 , V_18 = V_15 ;
int V_6 ;
if ( V_17 -> V_19 & V_20 )
V_6 = F_5 ( V_21 , & V_5 , & V_18 ) ;
else
V_6 = F_5 ( V_22 , & V_5 , & V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return ( int ) V_5 < 0 ? - V_8 : 0 ;
}
static unsigned long F_9 ( struct V_2 * V_3 , unsigned long V_16 )
{
unsigned V_5 = F_1 ( V_3 ) -> V_5 ;
if ( F_5 ( V_23 , & V_5 , NULL ) )
return 0 ;
else
return V_5 ;
}
static int F_10 ( struct V_2 * V_3 )
{
unsigned V_5 = F_1 ( V_3 ) -> V_5 ;
if ( F_5 ( V_24 , & V_5 , NULL ) )
return 0 ;
else
return V_5 ;
}
static long F_11 ( struct V_2 * V_3 , unsigned long V_18 ,
unsigned long * V_16 )
{
return V_18 ;
}
static int F_12 ( struct V_25 * V_26 )
{
const struct V_27 * V_28 = V_26 -> V_29 . V_30 ;
int V_31 , V_32 ;
for ( V_31 = 0 ; V_31 < V_28 -> V_33 ; V_31 ++ ) {
const struct V_34 * V_35 = & V_28 -> V_36 [ V_31 ] ;
struct V_37 * V_38 ;
struct V_1 * V_17 ;
struct V_2 * V_3 ;
struct V_39 V_40 ;
V_17 = F_13 ( & V_26 -> V_29 , sizeof( * V_17 ) , V_41 ) ;
if ( ! V_17 )
return - V_42 ;
V_17 -> V_5 = V_35 -> V_5 ;
V_17 -> V_19 = V_35 -> V_19 ;
V_17 -> V_4 . V_43 = F_7 ;
V_3 = & V_17 -> V_4 . V_3 ;
V_3 -> V_40 = & V_40 ;
V_40 . V_44 = V_35 -> V_44 ;
V_40 . V_45 = & V_46 ;
V_40 . V_47 = 0 ;
V_40 . V_19 = V_48 ;
if ( ! ( V_17 -> V_19 & V_49 ) )
V_40 . V_19 |= V_50 ;
V_38 = F_14 ( & V_26 -> V_29 , V_3 ) ;
V_32 = F_15 ( V_38 , V_35 -> V_51 , V_35 -> V_29 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
