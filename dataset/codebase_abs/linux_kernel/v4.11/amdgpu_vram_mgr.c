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
enum V_23 V_24 ;
unsigned long V_25 , V_26 , V_27 , V_28 ;
unsigned V_29 ;
int V_30 ;
V_25 = V_15 -> V_25 ;
if ( ! V_25 )
V_25 = V_2 -> V_31 ;
if ( V_19 -> V_32 & V_33 ||
V_15 -> V_25 || V_34 == - 1 ) {
V_27 = ~ 0ul ;
V_26 = 1 ;
} else {
V_27 = F_13 ( ( V_35 ) V_34 ,
V_17 -> V_36 ) ;
V_26 = F_14 ( V_17 -> V_37 , V_27 ) ;
}
V_22 = F_15 ( V_26 , sizeof( * V_22 ) , V_6 ) ;
if ( ! V_22 )
return - V_7 ;
V_24 = V_38 ;
if ( V_15 -> V_32 & V_39 )
V_24 = V_40 ;
V_28 = V_17 -> V_37 ;
F_6 ( & V_5 -> V_9 ) ;
for ( V_29 = 0 ; V_29 < V_26 ; ++ V_29 ) {
unsigned long V_41 = F_16 ( V_28 , V_27 ) ;
V_35 V_42 = V_17 -> V_36 ;
if ( V_41 == V_27 )
V_42 = V_27 ;
V_30 = F_17 ( V_8 , & V_22 [ V_29 ] ,
V_41 , V_42 , 0 ,
V_15 -> V_43 , V_25 ,
V_24 ) ;
if ( F_18 ( V_30 ) )
goto error;
V_28 -= V_41 ;
}
F_8 ( & V_5 -> V_9 ) ;
V_17 -> V_44 = V_26 == 1 ? V_22 [ 0 ] . V_44 : V_45 ;
V_17 -> V_46 = V_22 ;
return 0 ;
error:
while ( V_29 -- )
F_19 ( & V_22 [ V_29 ] ) ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_22 ) ;
return V_30 == - V_47 ? 0 : V_30 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_21 * V_22 = V_17 -> V_46 ;
unsigned V_41 = V_17 -> V_37 ;
if ( ! V_17 -> V_46 )
return;
F_6 ( & V_5 -> V_9 ) ;
while ( V_41 ) {
V_41 -= V_22 -> V_31 ;
F_19 ( V_22 ) ;
++ V_22 ;
}
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_17 -> V_46 ) ;
V_17 -> V_46 = NULL ;
}
static void F_21 ( struct V_1 * V_2 ,
const char * V_48 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_49 V_50 = F_22 ( V_48 ) ;
F_6 ( & V_5 -> V_9 ) ;
F_23 ( & V_5 -> V_8 , & V_50 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
