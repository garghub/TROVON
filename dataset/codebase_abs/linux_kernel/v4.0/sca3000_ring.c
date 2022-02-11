static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * * V_4 ,
int V_5 )
{
int V_6 ;
struct V_7 V_8 [ 2 ] = {
{
. V_5 = 1 ,
. V_9 = V_2 -> V_10 ,
} , {
. V_5 = V_5 ,
}
} ;
* V_4 = F_2 ( V_5 , V_11 ) ;
if ( * V_4 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
V_8 [ 1 ] . V_14 = * V_4 ;
V_2 -> V_10 [ 0 ] = F_3 ( V_3 ) ;
V_6 = F_4 ( V_2 -> V_15 , V_8 , F_5 ( V_8 ) ) ;
if ( V_6 ) {
F_6 ( F_7 ( & V_2 -> V_15 -> V_16 ) , L_1 ) ;
goto V_17;
}
return 0 ;
V_17:
F_8 ( * V_4 ) ;
V_13:
return V_6 ;
}
static int F_9 ( struct V_18 * V_19 ,
T_3 V_20 , char T_4 * V_21 )
{
struct V_22 * V_23 = F_10 ( V_19 ) ;
struct V_24 * V_25 = V_23 -> V_26 ;
struct V_1 * V_2 = F_11 ( V_25 ) ;
T_2 * V_27 ;
int V_6 , V_28 , V_29 , V_30 = 0 ;
int V_31 = 1 ;
if ( V_2 -> V_32 == 11 )
V_31 = 2 ;
F_12 ( & V_2 -> V_33 ) ;
if ( V_20 % V_31 ) {
V_6 = - V_34 ;
goto V_13;
}
V_6 = F_13 ( V_2 , V_35 , 1 ) ;
if ( V_6 )
goto V_13;
else
V_29 = V_2 -> V_27 [ 0 ] ;
if ( V_20 > V_29 * V_31 )
V_30 = V_29 * V_31 ;
else
V_30 = V_20 ;
V_6 = F_1 ( V_2 ,
V_36 ,
& V_27 , V_30 ) ;
if ( V_6 )
goto V_13;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ )
* ( ( ( V_37 * ) V_27 ) + V_28 ) = F_14 ( ( V_38 * ) V_27 + V_28 ) ;
if ( F_15 ( V_21 , V_27 , V_30 ) )
V_6 = - V_39 ;
F_8 ( V_27 ) ;
V_19 -> V_40 = 0 ;
V_13:
F_16 ( & V_2 -> V_33 ) ;
return V_6 ? V_6 : V_30 ;
}
static bool F_17 ( struct V_18 * V_19 )
{
return V_19 -> V_40 ;
}
static T_5 F_18 ( struct V_41 * V_16 ,
struct V_42 * V_43 ,
char * V_21 )
{
struct V_44 * V_45 = F_19 ( V_43 ) ;
int V_6 , V_46 ;
struct V_24 * V_25 = F_20 ( V_16 ) ;
struct V_1 * V_2 = F_11 ( V_25 ) ;
F_12 ( & V_2 -> V_33 ) ;
V_6 = F_13 ( V_2 , V_47 , 1 ) ;
V_46 = V_2 -> V_27 [ 0 ] ;
F_16 ( & V_2 -> V_33 ) ;
if ( V_6 )
return V_6 ;
return sprintf ( V_21 , L_2 , ! ! ( V_46 & V_45 -> V_48 ) ) ;
}
static T_5 F_21 ( struct V_41 * V_16 ,
struct V_42 * V_43 ,
const char * V_21 ,
T_3 V_5 )
{
struct V_24 * V_25 = F_20 ( V_16 ) ;
struct V_1 * V_2 = F_11 ( V_25 ) ;
struct V_44 * V_45 = F_19 ( V_43 ) ;
T_2 V_46 ;
int V_6 ;
F_12 ( & V_2 -> V_33 ) ;
V_6 = F_22 ( V_21 , 10 , & V_46 ) ;
if ( V_6 )
goto V_13;
V_6 = F_13 ( V_2 , V_47 , 1 ) ;
if ( V_6 )
goto V_13;
if ( V_46 )
V_6 = F_23 ( V_2 ,
V_47 ,
V_2 -> V_27 [ 0 ] | V_45 -> V_48 ) ;
else
V_6 = F_23 ( V_2 ,
V_47 ,
V_2 -> V_27 [ 0 ] & ~ V_45 -> V_48 ) ;
V_13:
F_16 ( & V_2 -> V_33 ) ;
return V_6 ? V_6 : V_5 ;
}
static T_5 F_24 ( struct V_41 * V_16 ,
struct V_42 * V_43 ,
char * V_21 )
{
struct V_24 * V_25 = F_20 ( V_16 ) ;
struct V_1 * V_2 = F_11 ( V_25 ) ;
return sprintf ( V_21 , L_3 , 4 * V_2 -> V_49 -> V_50 ) ;
}
static struct V_18 * F_25 ( struct V_24 * V_25 )
{
struct V_18 * V_21 ;
struct V_22 * V_51 ;
V_51 = F_26 ( sizeof( * V_51 ) , V_11 ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_26 = V_25 ;
V_21 = & V_51 -> V_21 ;
V_21 -> V_40 = 0 ;
V_21 -> V_52 = 64 ;
V_21 -> V_53 = V_54 ;
F_27 ( V_21 ) ;
return V_21 ;
}
static void F_28 ( struct V_18 * V_19 )
{
F_8 ( F_10 ( V_19 ) ) ;
}
int F_29 ( struct V_24 * V_25 )
{
struct V_18 * V_55 ;
V_55 = F_25 ( V_25 ) ;
if ( V_55 == NULL )
return - V_12 ;
V_25 -> V_56 |= V_57 ;
V_25 -> V_55 -> V_58 = & V_59 ;
F_30 ( V_25 , V_55 ) ;
return 0 ;
}
void F_31 ( struct V_24 * V_25 )
{
F_32 ( V_25 -> V_55 ) ;
}
static inline
int F_33 ( struct V_24 * V_25 , bool V_60 )
{
struct V_1 * V_2 = F_11 ( V_25 ) ;
int V_6 ;
F_12 ( & V_2 -> V_33 ) ;
V_6 = F_13 ( V_2 , V_61 , 1 ) ;
if ( V_6 )
goto V_13;
if ( V_60 ) {
F_34 ( & V_25 -> V_16 , L_4 ) ;
V_6 = F_23 ( V_2 ,
V_61 ,
( V_2 -> V_27 [ 0 ] | V_62 ) ) ;
} else
V_6 = F_23 ( V_2 ,
V_61 ,
( V_2 -> V_27 [ 0 ] & ~ V_62 ) ) ;
V_13:
F_16 ( & V_2 -> V_33 ) ;
return V_6 ;
}
static int F_35 ( struct V_24 * V_25 )
{
return F_33 ( V_25 , 1 ) ;
}
static int F_36 ( struct V_24 * V_25 )
{
return F_33 ( V_25 , 0 ) ;
}
void F_37 ( struct V_24 * V_25 )
{
V_25 -> V_63 = & V_64 ;
}
void F_38 ( T_2 V_46 , struct V_18 * V_51 )
{
if ( V_46 & ( V_65 |
V_66 ) ) {
V_51 -> V_40 = true ;
F_39 ( & V_51 -> V_67 ) ;
}
}
