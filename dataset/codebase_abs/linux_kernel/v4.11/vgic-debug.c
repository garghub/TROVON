static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 ) {
V_2 -> V_3 ++ ;
return;
}
V_2 -> V_4 ++ ;
if ( V_2 -> V_4 == V_5 &&
++ V_2 -> V_6 < V_2 -> V_7 )
V_2 -> V_4 = 0 ;
}
static void F_2 ( struct V_8 * V_8 , struct V_1 * V_2 ,
T_1 V_9 )
{
int V_7 = F_3 ( & V_8 -> V_10 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_11 = V_8 -> V_12 . V_13 . V_11 ;
while ( V_9 -- )
F_1 ( V_2 ) ;
}
static bool F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 > 0 &&
V_2 -> V_6 == V_2 -> V_7 &&
( V_2 -> V_4 - V_5 ) == V_2 -> V_11 ;
}
static void * F_5 ( struct V_14 * V_15 , T_1 * V_9 )
{
struct V_8 * V_8 = (struct V_8 * ) V_15 -> V_16 ;
struct V_1 * V_2 ;
F_6 ( & V_8 -> V_17 ) ;
V_2 = V_8 -> V_12 . V_13 . V_2 ;
if ( V_2 ) {
V_2 = F_7 ( - V_18 ) ;
goto V_19;
}
V_2 = F_8 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 ) {
V_2 = F_7 ( - V_21 ) ;
goto V_19;
}
F_2 ( V_8 , V_2 , * V_9 ) ;
V_8 -> V_12 . V_13 . V_2 = V_2 ;
if ( F_4 ( V_2 ) )
V_2 = NULL ;
V_19:
F_9 ( & V_8 -> V_17 ) ;
return V_2 ;
}
static void * F_10 ( struct V_14 * V_15 , void * V_22 , T_1 * V_9 )
{
struct V_8 * V_8 = (struct V_8 * ) V_15 -> V_16 ;
struct V_1 * V_2 = V_8 -> V_12 . V_13 . V_2 ;
++ * V_9 ;
F_1 ( V_2 ) ;
if ( F_4 ( V_2 ) )
V_2 = NULL ;
return V_2 ;
}
static void F_11 ( struct V_14 * V_15 , void * V_22 )
{
struct V_8 * V_8 = (struct V_8 * ) V_15 -> V_16 ;
struct V_1 * V_2 ;
if ( F_12 ( V_22 ) )
return;
F_6 ( & V_8 -> V_17 ) ;
V_2 = V_8 -> V_12 . V_13 . V_2 ;
F_13 ( V_2 ) ;
V_8 -> V_12 . V_13 . V_2 = NULL ;
F_9 ( & V_8 -> V_17 ) ;
}
static void F_14 ( struct V_14 * V_15 , struct V_23 * V_24 )
{
F_15 ( V_15 , L_1 ) ;
F_15 ( V_15 , L_2 ) ;
F_15 ( V_15 , L_3 ,
( V_24 -> V_25 == V_26 ) ?
L_4 : L_5 ) ;
F_15 ( V_15 , L_6 , V_24 -> V_11 ) ;
F_15 ( V_15 , L_7 , V_24 -> V_27 ) ;
F_15 ( V_15 , L_8 ) ;
F_15 ( V_15 , L_9 ) ;
F_15 ( V_15 , L_10 ) ;
}
static void F_16 ( struct V_14 * V_15 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
int V_32 = 0 ;
char * V_33 = L_11 ;
if ( V_31 ) {
V_33 = L_12 ;
V_32 = V_31 -> V_6 ;
}
F_15 ( V_15 , L_8 ) ;
F_15 ( V_15 , L_13 , V_33 , V_32 ) ;
F_15 ( V_15 , L_14 ) ;
}
static void F_17 ( struct V_14 * V_15 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
char * type ;
if ( V_29 -> V_4 < V_34 )
type = L_15 ;
else if ( V_29 -> V_4 < V_5 )
type = L_16 ;
else
type = L_17 ;
if ( V_29 -> V_4 == 0 || V_29 -> V_4 == V_5 )
F_16 ( V_15 , V_29 , V_31 ) ;
F_15 ( V_15 , L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_8 ,
type , V_29 -> V_4 ,
( V_29 -> V_35 ) ? V_29 -> V_35 -> V_6 : - 1 ,
V_29 -> V_36 ,
V_29 -> V_37 ,
V_29 -> V_38 ,
V_29 -> V_27 ,
V_29 -> V_39 ,
V_29 -> V_40 == V_41 ,
V_29 -> V_42 ,
V_29 -> V_43 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
( V_29 -> V_31 ) ? V_29 -> V_31 -> V_6 : - 1 ) ;
}
static int F_18 ( struct V_14 * V_15 , void * V_22 )
{
struct V_8 * V_8 = (struct V_8 * ) V_15 -> V_16 ;
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
struct V_28 * V_29 ;
struct V_30 * V_31 = NULL ;
if ( V_2 -> V_3 == 0 ) {
F_14 ( V_15 , & V_8 -> V_12 . V_13 ) ;
return 0 ;
}
if ( ! V_8 -> V_12 . V_13 . V_46 )
return 0 ;
if ( V_2 -> V_6 < V_2 -> V_7 ) {
V_31 = F_19 ( V_8 , V_2 -> V_6 ) ;
V_29 = & V_31 -> V_12 . V_47 . V_48 [ V_2 -> V_4 ] ;
} else {
V_29 = & V_8 -> V_12 . V_13 . V_49 [ V_2 -> V_4 - V_5 ] ;
}
F_20 ( & V_29 -> V_50 ) ;
F_17 ( V_15 , V_29 , V_31 ) ;
F_21 ( & V_29 -> V_50 ) ;
return 0 ;
}
static int F_22 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
int V_53 ;
V_53 = F_23 ( V_52 , & V_54 ) ;
if ( ! V_53 ) {
struct V_14 * V_55 ;
V_55 = V_52 -> V_56 ;
V_55 -> V_16 = V_51 -> V_57 ;
}
return V_53 ;
}
int F_24 ( struct V_8 * V_8 )
{
if ( ! V_8 -> V_58 )
return - V_59 ;
if ( ! F_25 ( L_26 , 0444 ,
V_8 -> V_58 ,
V_8 ,
& V_60 ) )
return - V_21 ;
return 0 ;
}
int F_26 ( struct V_8 * V_8 )
{
return 0 ;
}
