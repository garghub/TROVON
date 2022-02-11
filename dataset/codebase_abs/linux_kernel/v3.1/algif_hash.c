static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 )
{
int V_8 = V_9 * V_10 ;
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
unsigned long V_17 ;
struct V_18 * V_19 ;
long V_20 = 0 ;
int V_21 ;
if ( V_8 > V_11 -> V_22 )
V_8 = V_11 -> V_22 ;
F_3 ( V_11 ) ;
if ( ! V_15 -> V_23 ) {
V_21 = F_4 ( & V_15 -> V_24 ) ;
if ( V_21 )
goto V_25;
}
V_15 -> V_23 = 0 ;
for ( V_19 = V_6 -> V_26 , V_17 = V_6 -> V_27 ; V_17 > 0 ;
V_17 -- , V_19 ++ ) {
unsigned long V_28 = V_19 -> V_29 ;
char T_2 * V_30 = V_19 -> V_31 ;
while ( V_28 ) {
int V_32 = F_5 (unsigned long, seglen, limit) ;
int V_33 ;
V_33 = F_6 ( & V_15 -> V_34 , V_30 , V_32 , 0 ) ;
if ( V_33 < 0 ) {
V_21 = V_20 ? 0 : V_33 ;
goto V_25;
}
F_7 ( & V_15 -> V_24 , V_15 -> V_34 . V_35 , NULL ,
V_33 ) ;
V_21 = F_8 (
F_9 ( & V_15 -> V_24 ) ,
& V_15 -> V_36 ) ;
F_10 ( & V_15 -> V_34 ) ;
if ( V_21 )
goto V_25;
V_28 -= V_33 ;
V_30 += V_33 ;
V_20 += V_33 ;
}
}
V_21 = 0 ;
V_15 -> V_23 = V_6 -> V_37 & V_38 ;
if ( ! V_15 -> V_23 ) {
F_7 ( & V_15 -> V_24 , NULL , V_15 -> V_39 , 0 ) ;
V_21 = F_8 ( F_11 ( & V_15 -> V_24 ) ,
& V_15 -> V_36 ) ;
}
V_25:
F_12 ( V_11 ) ;
return V_21 ? : V_20 ;
}
static T_3 F_13 ( struct V_3 * V_4 , struct V_40 * V_40 ,
int V_41 , T_1 V_42 , int V_43 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
int V_21 ;
F_3 ( V_11 ) ;
F_14 ( V_15 -> V_34 . V_35 , 1 ) ;
F_15 ( V_15 -> V_34 . V_35 , V_40 , V_42 , V_41 ) ;
F_7 ( & V_15 -> V_24 , V_15 -> V_34 . V_35 , V_15 -> V_39 , V_42 ) ;
if ( ! ( V_43 & V_38 ) ) {
if ( V_15 -> V_23 )
V_21 = F_16 ( & V_15 -> V_24 ) ;
else
V_21 = F_17 ( & V_15 -> V_24 ) ;
} else {
if ( ! V_15 -> V_23 ) {
V_21 = F_4 ( & V_15 -> V_24 ) ;
if ( V_21 )
goto V_25;
}
V_21 = F_9 ( & V_15 -> V_24 ) ;
}
V_21 = F_8 ( V_21 , & V_15 -> V_36 ) ;
if ( V_21 )
goto V_25;
V_15 -> V_23 = V_43 & V_38 ;
V_25:
F_12 ( V_11 ) ;
return V_21 ? : V_42 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_32 , int V_43 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
unsigned V_44 = F_19 ( F_20 ( & V_15 -> V_24 ) ) ;
int V_21 ;
if ( V_32 > V_44 )
V_32 = V_44 ;
else if ( V_32 < V_44 )
V_6 -> V_37 |= V_45 ;
F_3 ( V_11 ) ;
if ( V_15 -> V_23 ) {
V_15 -> V_23 = 0 ;
F_7 ( & V_15 -> V_24 , NULL , V_15 -> V_39 , 0 ) ;
V_21 = F_8 ( F_11 ( & V_15 -> V_24 ) ,
& V_15 -> V_36 ) ;
if ( V_21 )
goto V_25;
}
V_21 = F_21 ( V_6 -> V_26 , V_15 -> V_39 , V_32 ) ;
V_25:
F_12 ( V_11 ) ;
return V_21 ? : V_32 ;
}
static int F_22 ( struct V_3 * V_4 , struct V_3 * V_46 , int V_43 )
{
struct V_4 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_47 * V_24 = & V_15 -> V_24 ;
char V_48 [ F_23 ( F_20 ( V_24 ) ) ] ;
struct V_4 * V_49 ;
struct V_12 * V_50 ;
struct V_14 * V_51 ;
int V_21 ;
V_21 = F_24 ( V_24 , V_48 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_25 ( V_13 -> V_52 , V_46 ) ;
if ( V_21 )
return V_21 ;
V_49 = V_46 -> V_11 ;
V_50 = F_2 ( V_49 ) ;
V_51 = V_50 -> V_16 ;
V_51 -> V_23 = 1 ;
V_21 = F_26 ( & V_51 -> V_24 , V_48 ) ;
if ( V_21 ) {
F_27 ( V_49 ) ;
F_28 ( V_49 ) ;
}
return V_21 ;
}
static void * F_29 ( const char * V_53 , T_4 type , T_4 V_54 )
{
return F_30 ( V_53 , type , V_54 ) ;
}
static void F_31 ( void * V_16 )
{
F_32 ( V_16 ) ;
}
static int F_33 ( void * V_16 , const T_5 * V_55 , unsigned int V_56 )
{
return F_34 ( V_16 , V_55 , V_56 ) ;
}
static void F_35 ( struct V_4 * V_11 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
F_36 ( V_11 , V_15 -> V_39 ,
F_19 ( F_20 ( & V_15 -> V_24 ) ) ) ;
F_36 ( V_11 , V_15 , V_15 -> V_32 ) ;
F_37 ( V_11 ) ;
}
static int F_38 ( void * V_16 , struct V_4 * V_11 )
{
struct V_14 * V_15 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned V_32 = sizeof( * V_15 ) + F_39 ( V_16 ) ;
unsigned V_44 = F_19 ( V_16 ) ;
V_15 = F_40 ( V_11 , V_32 , V_57 ) ;
if ( ! V_15 )
return - V_58 ;
V_15 -> V_39 = F_40 ( V_11 , V_44 , V_57 ) ;
if ( ! V_15 -> V_39 ) {
F_36 ( V_11 , V_15 , V_32 ) ;
return - V_58 ;
}
memset ( V_15 -> V_39 , 0 , V_44 ) ;
V_15 -> V_32 = V_32 ;
V_15 -> V_23 = 0 ;
F_41 ( & V_15 -> V_36 ) ;
V_13 -> V_16 = V_15 ;
F_42 ( & V_15 -> V_24 , V_16 ) ;
F_43 ( & V_15 -> V_24 , V_59 ,
V_60 , & V_15 -> V_36 ) ;
V_11 -> V_61 = F_35 ;
return 0 ;
}
static int T_6 F_44 ( void )
{
return F_45 ( & V_62 ) ;
}
static void T_7 F_46 ( void )
{
int V_21 = F_47 ( & V_62 ) ;
F_48 ( V_21 ) ;
}
