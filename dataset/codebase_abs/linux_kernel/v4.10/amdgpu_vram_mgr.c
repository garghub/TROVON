static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
F_3 ( & V_5 -> V_8 , 0 , V_3 ) ;
F_4 ( & V_5 -> V_9 ) ;
V_2 -> V_10 = V_5 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
F_6 ( & V_5 -> V_9 ) ;
if ( ! F_7 ( & V_5 -> V_8 ) ) {
F_8 ( & V_5 -> V_9 ) ;
return - V_11 ;
}
F_9 ( & V_5 -> V_8 ) ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_5 ) ;
V_2 -> V_10 = NULL ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
const struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_12 ( V_13 , struct V_18 , V_13 ) ;
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_20 * V_8 = & V_5 -> V_8 ;
struct V_21 * V_22 ;
enum V_23 V_24 = V_25 ;
enum V_26 V_27 = V_28 ;
unsigned long V_29 , V_30 , V_31 , V_32 ;
unsigned V_33 ;
int V_34 ;
V_29 = V_15 -> V_29 ;
if ( ! V_29 )
V_29 = V_2 -> V_35 ;
if ( V_19 -> V_36 & V_37 ||
V_15 -> V_29 || V_38 == - 1 ) {
V_31 = ~ 0ul ;
V_30 = 1 ;
} else {
V_31 = F_13 ( ( V_39 ) V_38 ,
V_17 -> V_40 ) ;
V_30 = F_14 ( V_17 -> V_41 , V_31 ) ;
}
V_22 = F_15 ( V_30 , sizeof( * V_22 ) , V_6 ) ;
if ( ! V_22 )
return - V_7 ;
if ( V_15 -> V_36 & V_42 ) {
V_24 = V_43 ;
V_27 = V_44 ;
}
V_32 = V_17 -> V_41 ;
F_6 ( & V_5 -> V_9 ) ;
for ( V_33 = 0 ; V_33 < V_30 ; ++ V_33 ) {
unsigned long V_45 = F_16 ( V_32 , V_31 ) ;
V_39 V_46 = V_17 -> V_40 ;
if ( V_45 == V_31 )
V_46 = V_31 ;
else
V_24 |= V_47 ;
V_34 = F_17 ( V_8 , & V_22 [ V_33 ] , V_45 ,
V_46 , 0 ,
V_15 -> V_48 , V_29 ,
V_24 , V_27 ) ;
if ( F_18 ( V_34 ) )
goto error;
V_32 -= V_45 ;
}
F_8 ( & V_5 -> V_9 ) ;
V_17 -> V_49 = V_30 == 1 ? V_22 [ 0 ] . V_49 : V_50 ;
V_17 -> V_51 = V_22 ;
return 0 ;
error:
while ( V_33 -- )
F_19 ( & V_22 [ V_33 ] ) ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_22 ) ;
return V_34 == - V_52 ? 0 : V_34 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_21 * V_22 = V_17 -> V_51 ;
unsigned V_45 = V_17 -> V_41 ;
if ( ! V_17 -> V_51 )
return;
F_6 ( & V_5 -> V_9 ) ;
while ( V_45 ) {
V_45 -= V_22 -> V_35 ;
F_19 ( V_22 ) ;
++ V_22 ;
}
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_17 -> V_51 ) ;
V_17 -> V_51 = NULL ;
}
static void F_21 ( struct V_1 * V_2 ,
const char * V_53 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
F_6 ( & V_5 -> V_9 ) ;
F_22 ( & V_5 -> V_8 , V_53 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
