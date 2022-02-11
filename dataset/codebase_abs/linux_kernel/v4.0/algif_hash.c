static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 )
{
int V_8 = V_9 * V_10 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
long V_17 = 0 ;
int V_18 ;
if ( V_8 > V_11 -> V_19 )
V_8 = V_11 -> V_19 ;
F_3 ( V_11 ) ;
if ( ! V_15 -> V_20 ) {
V_18 = F_4 ( & V_15 -> V_21 ) ;
if ( V_18 )
goto V_22;
}
V_15 -> V_20 = 0 ;
while ( F_5 ( & V_6 -> V_23 ) ) {
int V_24 = F_5 ( & V_6 -> V_23 ) ;
if ( V_24 > V_8 )
V_24 = V_8 ;
V_24 = F_6 ( & V_15 -> V_25 , & V_6 -> V_23 , V_24 ) ;
if ( V_24 < 0 ) {
V_18 = V_17 ? 0 : V_24 ;
goto V_22;
}
F_7 ( & V_15 -> V_21 , V_15 -> V_25 . V_26 , NULL , V_24 ) ;
V_18 = F_8 ( F_9 ( & V_15 -> V_21 ) ,
& V_15 -> V_27 ) ;
F_10 ( & V_15 -> V_25 ) ;
if ( V_18 )
goto V_22;
V_17 += V_24 ;
F_11 ( & V_6 -> V_23 , V_24 ) ;
}
V_18 = 0 ;
V_15 -> V_20 = V_6 -> V_28 & V_29 ;
if ( ! V_15 -> V_20 ) {
F_7 ( & V_15 -> V_21 , NULL , V_15 -> V_30 , 0 ) ;
V_18 = F_8 ( F_12 ( & V_15 -> V_21 ) ,
& V_15 -> V_27 ) ;
}
V_22:
F_13 ( V_11 ) ;
return V_18 ? : V_17 ;
}
static T_2 F_14 ( struct V_3 * V_4 , struct V_31 * V_31 ,
int V_32 , T_1 V_33 , int V_34 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
int V_18 ;
if ( V_34 & V_35 )
V_34 |= V_29 ;
F_3 ( V_11 ) ;
F_15 ( V_15 -> V_25 . V_26 , 1 ) ;
F_16 ( V_15 -> V_25 . V_26 , V_31 , V_33 , V_32 ) ;
F_7 ( & V_15 -> V_21 , V_15 -> V_25 . V_26 , V_15 -> V_30 , V_33 ) ;
if ( ! ( V_34 & V_29 ) ) {
if ( V_15 -> V_20 )
V_18 = F_17 ( & V_15 -> V_21 ) ;
else
V_18 = F_18 ( & V_15 -> V_21 ) ;
} else {
if ( ! V_15 -> V_20 ) {
V_18 = F_4 ( & V_15 -> V_21 ) ;
if ( V_18 )
goto V_22;
}
V_18 = F_9 ( & V_15 -> V_21 ) ;
}
V_18 = F_8 ( V_18 , & V_15 -> V_27 ) ;
if ( V_18 )
goto V_22;
V_15 -> V_20 = V_34 & V_29 ;
V_22:
F_13 ( V_11 ) ;
return V_18 ? : V_33 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_24 , int V_34 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
unsigned V_36 = F_20 ( F_21 ( & V_15 -> V_21 ) ) ;
int V_18 ;
if ( V_24 > V_36 )
V_24 = V_36 ;
else if ( V_24 < V_36 )
V_6 -> V_28 |= V_37 ;
F_3 ( V_11 ) ;
if ( V_15 -> V_20 ) {
V_15 -> V_20 = 0 ;
F_7 ( & V_15 -> V_21 , NULL , V_15 -> V_30 , 0 ) ;
V_18 = F_8 ( F_12 ( & V_15 -> V_21 ) ,
& V_15 -> V_27 ) ;
if ( V_18 )
goto V_22;
}
V_18 = F_22 ( V_6 , V_15 -> V_30 , V_24 ) ;
V_22:
F_13 ( V_11 ) ;
return V_18 ? : V_24 ;
}
static int F_23 ( struct V_3 * V_4 , struct V_3 * V_38 , int V_34 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_39 * V_21 = & V_15 -> V_21 ;
char V_40 [ F_24 ( F_21 ( V_21 ) ) ] ;
struct V_4 * V_41 ;
struct V_12 * V_42 ;
struct V_14 * V_43 ;
int V_18 ;
V_18 = F_25 ( V_21 , V_40 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_26 ( V_13 -> V_44 , V_38 ) ;
if ( V_18 )
return V_18 ;
V_41 = V_38 -> V_11 ;
V_42 = F_2 ( V_41 ) ;
V_43 = V_42 -> V_16 ;
V_43 -> V_20 = 1 ;
V_18 = F_27 ( & V_43 -> V_21 , V_40 ) ;
if ( V_18 ) {
F_28 ( V_41 ) ;
F_29 ( V_41 ) ;
}
return V_18 ;
}
static void * F_30 ( const char * V_45 , T_3 type , T_3 V_46 )
{
return F_31 ( V_45 , type , V_46 ) ;
}
static void F_32 ( void * V_16 )
{
F_33 ( V_16 ) ;
}
static int F_34 ( void * V_16 , const T_4 * V_47 , unsigned int V_48 )
{
return F_35 ( V_16 , V_47 , V_48 ) ;
}
static void F_36 ( struct V_4 * V_11 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
F_37 ( V_11 , V_15 -> V_30 ,
F_20 ( F_21 ( & V_15 -> V_21 ) ) ) ;
F_38 ( V_11 , V_15 , V_15 -> V_24 ) ;
F_39 ( V_11 ) ;
}
static int F_40 ( void * V_16 , struct V_4 * V_11 )
{
struct V_14 * V_15 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned V_24 = sizeof( * V_15 ) + F_41 ( V_16 ) ;
unsigned V_36 = F_20 ( V_16 ) ;
V_15 = F_42 ( V_11 , V_24 , V_49 ) ;
if ( ! V_15 )
return - V_50 ;
V_15 -> V_30 = F_42 ( V_11 , V_36 , V_49 ) ;
if ( ! V_15 -> V_30 ) {
F_38 ( V_11 , V_15 , V_24 ) ;
return - V_50 ;
}
memset ( V_15 -> V_30 , 0 , V_36 ) ;
V_15 -> V_24 = V_24 ;
V_15 -> V_20 = 0 ;
F_43 ( & V_15 -> V_27 ) ;
V_13 -> V_16 = V_15 ;
F_44 ( & V_15 -> V_21 , V_16 ) ;
F_45 ( & V_15 -> V_21 , V_51 ,
V_52 , & V_15 -> V_27 ) ;
V_11 -> V_53 = F_36 ;
return 0 ;
}
static int T_5 F_46 ( void )
{
return F_47 ( & V_54 ) ;
}
static void T_6 F_48 ( void )
{
int V_18 = F_49 ( & V_54 ) ;
F_50 ( V_18 ) ;
}
