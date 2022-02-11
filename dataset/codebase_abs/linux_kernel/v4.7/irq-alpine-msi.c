static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( struct V_3 * V_4 , int V_5 )
{
int V_6 ;
F_8 ( & V_4 -> V_7 ) ;
V_6 = F_9 ( V_4 -> V_8 , V_4 -> V_9 , 0 ,
V_5 , 0 ) ;
if ( V_6 >= V_4 -> V_9 ) {
F_10 ( & V_4 -> V_7 ) ;
return - V_10 ;
}
F_11 ( V_4 -> V_8 , V_6 , V_5 ) ;
F_10 ( & V_4 -> V_7 ) ;
return V_4 -> V_11 + V_6 ;
}
static void F_12 ( struct V_3 * V_4 , unsigned V_12 ,
int V_5 )
{
int V_6 = V_12 - V_4 -> V_11 ;
F_8 ( & V_4 -> V_7 ) ;
F_13 ( V_4 -> V_8 , V_6 , V_5 ) ;
F_10 ( & V_4 -> V_7 ) ;
}
static void F_14 ( struct V_1 * V_13 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_15 ( V_13 ) ;
T_1 V_16 = V_4 -> V_17 ;
V_16 |= ( V_13 -> V_18 << 3 ) ;
V_15 -> V_19 = F_16 ( V_16 ) ;
V_15 -> V_20 = F_17 ( V_16 ) ;
V_15 -> V_13 = 0 ;
}
static int F_18 ( struct V_21 * V_22 ,
unsigned int V_23 , int V_12 )
{
struct V_24 V_25 ;
struct V_1 * V_2 ;
int V_26 ;
if ( ! F_19 ( V_22 -> V_27 -> V_28 ) )
return - V_29 ;
V_25 . V_28 = V_22 -> V_27 -> V_28 ;
V_25 . V_30 = 3 ;
V_25 . V_31 [ 0 ] = 0 ;
V_25 . V_31 [ 1 ] = V_12 ;
V_25 . V_31 [ 2 ] = V_32 ;
V_26 = F_20 ( V_22 , V_23 , 1 , & V_25 ) ;
if ( V_26 )
return V_26 ;
V_2 = F_21 ( V_22 -> V_27 , V_23 ) ;
V_2 -> V_33 -> V_34 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_22 ( struct V_21 * V_22 ,
unsigned int V_23 ,
unsigned int V_35 , void * args )
{
struct V_3 * V_4 = V_22 -> V_36 ;
int V_12 , V_37 , V_38 ;
V_12 = F_7 ( V_4 , V_35 ) ;
if ( V_12 < 0 )
return V_12 ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
V_37 = F_18 ( V_22 , V_23 + V_38 , V_12 + V_38 ) ;
if ( V_37 )
goto V_39;
F_23 ( V_22 , V_23 + V_38 , V_12 + V_38 ,
& V_40 , V_4 ) ;
}
return 0 ;
V_39:
while ( -- V_38 >= 0 )
F_24 ( V_22 , V_23 , V_38 ) ;
F_12 ( V_4 , V_12 , V_35 ) ;
return V_37 ;
}
static void F_25 ( struct V_21 * V_22 ,
unsigned int V_23 ,
unsigned int V_35 )
{
struct V_1 * V_2 = F_21 ( V_22 , V_23 ) ;
struct V_3 * V_4 = F_15 ( V_2 ) ;
F_24 ( V_22 , V_23 , V_35 ) ;
F_12 ( V_4 , V_2 -> V_18 , V_35 ) ;
}
static int F_26 ( struct V_3 * V_4 ,
struct V_41 * V_42 )
{
struct V_21 * V_43 , * V_44 , * V_45 ;
struct V_41 * V_46 ;
V_46 = F_27 ( V_42 ) ;
if ( ! V_46 ) {
F_28 ( L_1 ) ;
return - V_47 ;
}
V_45 = F_29 ( V_46 ) ;
if ( ! V_45 ) {
F_28 ( L_2 ) ;
return - V_48 ;
}
V_43 = F_30 ( NULL ,
& V_49 ,
V_4 ) ;
if ( ! V_43 ) {
F_28 ( L_3 ) ;
return - V_50 ;
}
V_43 -> V_27 = V_45 ;
V_44 = F_31 ( F_32 ( V_42 ) ,
& V_51 ,
V_43 ) ;
if ( ! V_44 ) {
F_28 ( L_4 ) ;
F_33 ( V_43 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_34 ( struct V_41 * V_42 ,
struct V_41 * V_27 )
{
struct V_3 * V_4 ;
struct V_52 V_53 ;
int V_26 ;
V_4 = F_35 ( sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return - V_50 ;
F_36 ( & V_4 -> V_7 ) ;
V_26 = F_37 ( V_42 , 0 , & V_53 ) ;
if ( V_26 ) {
F_28 ( L_5 ) ;
goto V_55;
}
V_4 -> V_17 = V_53 . V_56 & F_38 ( 63 , 20 ) ;
V_4 -> V_17 |= V_57 ;
if ( F_39 ( V_42 , L_6 , & V_4 -> V_11 ) ) {
F_28 ( L_7 ) ;
V_26 = - V_29 ;
goto V_55;
}
if ( F_39 ( V_42 , L_8 , & V_4 -> V_9 ) ) {
F_28 ( L_9 ) ;
V_26 = - V_29 ;
goto V_55;
}
V_4 -> V_8 = F_35 ( sizeof( * V_4 -> V_8 ) * F_40 ( V_4 -> V_9 ) ,
V_54 ) ;
if ( ! V_4 -> V_8 ) {
V_26 = - V_50 ;
goto V_55;
}
F_41 ( L_10 ,
V_4 -> V_9 , V_4 -> V_11 ) ;
V_26 = F_26 ( V_4 , V_42 ) ;
if ( V_26 )
goto V_58;
return 0 ;
V_58:
F_42 ( V_4 -> V_8 ) ;
V_55:
F_42 ( V_4 ) ;
return V_26 ;
}
