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
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_18 * V_8 = & V_5 -> V_8 ;
struct V_19 * V_20 ;
enum V_21 V_22 ;
unsigned long V_23 , V_24 , V_25 , V_26 ;
unsigned V_27 ;
int V_28 ;
V_23 = V_15 -> V_23 ;
if ( ! V_23 )
V_23 = V_2 -> V_29 ;
if ( V_15 -> V_30 & V_31 ||
V_32 == - 1 ) {
V_25 = ~ 0ul ;
V_24 = 1 ;
} else {
V_25 = F_12 ( ( V_33 ) V_32 ,
V_17 -> V_34 ) ;
V_24 = F_13 ( V_17 -> V_35 , V_25 ) ;
}
V_20 = F_14 ( V_24 , sizeof( * V_20 ) , V_6 ) ;
if ( ! V_20 )
return - V_7 ;
V_22 = V_36 ;
if ( V_15 -> V_30 & V_37 )
V_22 = V_38 ;
V_17 -> V_39 = 0 ;
V_26 = V_17 -> V_35 ;
F_6 ( & V_5 -> V_9 ) ;
for ( V_27 = 0 ; V_27 < V_24 ; ++ V_27 ) {
unsigned long V_40 = F_15 ( V_26 , V_25 ) ;
V_33 V_41 = V_17 -> V_34 ;
unsigned long V_39 ;
if ( V_40 == V_25 )
V_41 = V_25 ;
V_28 = F_16 ( V_8 , & V_20 [ V_27 ] ,
V_40 , V_41 , 0 ,
V_15 -> V_42 , V_23 ,
V_22 ) ;
if ( F_17 ( V_28 ) )
goto error;
V_39 = V_20 [ V_27 ] . V_39 + V_20 [ V_27 ] . V_29 ;
if ( V_39 > V_17 -> V_35 )
V_39 -= V_17 -> V_35 ;
else
V_39 = 0 ;
V_17 -> V_39 = F_12 ( V_17 -> V_39 , V_39 ) ;
V_26 -= V_40 ;
}
F_8 ( & V_5 -> V_9 ) ;
V_17 -> V_43 = V_20 ;
return 0 ;
error:
while ( V_27 -- )
F_18 ( & V_20 [ V_27 ] ) ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_20 ) ;
return V_28 == - V_44 ? 0 : V_28 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_19 * V_20 = V_17 -> V_43 ;
unsigned V_40 = V_17 -> V_35 ;
if ( ! V_17 -> V_43 )
return;
F_6 ( & V_5 -> V_9 ) ;
while ( V_40 ) {
V_40 -= V_20 -> V_29 ;
F_18 ( V_20 ) ;
++ V_20 ;
}
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_17 -> V_43 ) ;
V_17 -> V_43 = NULL ;
}
static void F_20 ( struct V_1 * V_2 ,
const char * V_45 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_46 V_47 = F_21 ( V_45 ) ;
F_6 ( & V_5 -> V_9 ) ;
F_22 ( & V_5 -> V_8 , & V_47 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
