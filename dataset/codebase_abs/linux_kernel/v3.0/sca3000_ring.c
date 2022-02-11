static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * * V_4 ,
int V_5 )
{
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 [ 2 ] = {
{
. V_5 = 1 ,
. V_11 = V_2 -> V_12 ,
} , {
. V_5 = V_5 ,
}
} ;
* V_4 = F_2 ( V_5 , V_13 ) ;
if ( * V_4 == NULL ) {
V_6 = - V_14 ;
goto V_15;
}
V_10 [ 1 ] . V_16 = * V_4 ;
V_2 -> V_12 [ 0 ] = F_3 ( V_3 ) ;
F_4 ( & V_8 ) ;
F_5 ( & V_10 [ 0 ] , & V_8 ) ;
F_5 ( & V_10 [ 1 ] , & V_8 ) ;
V_6 = F_6 ( V_2 -> V_17 , & V_8 ) ;
if ( V_6 ) {
F_7 ( F_8 ( & V_2 -> V_17 -> V_18 ) , L_1 ) ;
goto V_19;
}
return 0 ;
V_19:
F_9 ( * V_4 ) ;
V_15:
return V_6 ;
}
static int F_10 ( struct V_20 * V_21 ,
T_3 V_22 , char T_4 * V_23 )
{
struct V_24 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_1 * V_2 = V_27 -> V_29 ;
T_2 * V_30 ;
int V_6 , V_31 , V_32 , V_33 = 0 ;
int V_34 = 1 ;
if ( V_2 -> V_35 == 11 )
V_34 = 2 ;
F_12 ( & V_2 -> V_36 ) ;
if ( V_22 % V_34 ) {
V_6 = - V_37 ;
goto V_15;
}
V_6 = F_13 ( V_2 , V_38 , 1 ) ;
if ( V_6 )
goto V_15;
else
V_32 = V_2 -> V_30 [ 0 ] ;
if ( V_22 > V_32 * V_34 )
V_33 = V_32 * V_34 ;
else
V_33 = V_22 ;
V_6 = F_1 ( V_2 ,
V_39 ,
& V_30 , V_33 ) ;
if ( V_6 )
goto V_15;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ )
* ( ( ( V_40 * ) V_30 ) + V_31 ) = F_14 ( ( V_40 * ) V_30 + V_31 ) ;
if ( F_15 ( V_23 , V_30 , V_33 ) )
V_6 = - V_41 ;
F_9 ( V_30 ) ;
V_21 -> V_42 = 0 ;
V_15:
F_16 ( & V_2 -> V_36 ) ;
return V_6 ? V_6 : V_33 ;
}
static int F_17 ( struct V_20 * V_21 )
{
return 64 ;
}
static int F_18 ( struct V_20 * V_21 )
{
return 6 ;
}
static void F_19 ( struct V_43 * V_18 )
{
struct V_20 * V_21 = F_20 ( V_18 ) ;
F_9 ( F_11 ( V_21 ) ) ;
}
static T_5 F_21 ( struct V_43 * V_18 ,
struct V_44 * V_45 ,
char * V_23 )
{
struct V_46 * V_47 = F_22 ( V_45 ) ;
int V_6 , V_48 ;
struct V_20 * V_49 = F_23 ( V_18 ) ;
struct V_26 * V_27 = V_49 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_29 ;
F_12 ( & V_2 -> V_36 ) ;
V_6 = F_13 ( V_2 , V_50 , 1 ) ;
V_48 = V_2 -> V_30 [ 0 ] ;
F_16 ( & V_2 -> V_36 ) ;
if ( V_6 )
return V_6 ;
return sprintf ( V_23 , L_2 , ! ! ( V_48 & V_47 -> V_51 ) ) ;
}
static T_5 F_24 ( struct V_43 * V_18 ,
struct V_44 * V_45 ,
const char * V_23 ,
T_3 V_5 )
{
struct V_20 * V_49 = F_23 ( V_18 ) ;
struct V_26 * V_27 = V_49 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_46 * V_47 = F_22 ( V_45 ) ;
long V_48 ;
int V_6 ;
F_12 ( & V_2 -> V_36 ) ;
V_6 = F_25 ( V_23 , 10 , & V_48 ) ;
if ( V_6 )
goto V_15;
V_6 = F_13 ( V_2 , V_50 , 1 ) ;
if ( V_6 )
goto V_15;
if ( V_48 )
V_6 = F_26 ( V_2 ,
V_50 ,
V_2 -> V_30 [ 0 ] | V_47 -> V_51 ) ;
else
V_6 = F_26 ( V_2 ,
V_50 ,
V_2 -> V_30 [ 0 ] & ~ V_47 -> V_51 ) ;
V_15:
F_16 ( & V_2 -> V_36 ) ;
return V_6 ? V_6 : V_5 ;
}
static T_5 F_27 ( struct V_43 * V_18 ,
struct V_44 * V_45 ,
char * V_23 )
{
int V_5 = 0 , V_6 ;
struct V_20 * V_49 = F_23 ( V_18 ) ;
struct V_26 * V_27 = V_49 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_29 ;
F_12 ( & V_2 -> V_36 ) ;
V_6 = F_13 ( V_2 , V_52 , 1 ) ;
if ( V_6 )
goto V_15;
if ( V_2 -> V_30 [ 0 ] & V_53 )
V_5 = sprintf ( V_23 , L_3 ) ;
else
V_5 = sprintf ( V_23 , L_4 ) ;
V_15:
F_16 ( & V_2 -> V_36 ) ;
return V_6 ? V_6 : V_5 ;
}
static T_5 F_28 ( struct V_43 * V_18 ,
struct V_44 * V_45 ,
const char * V_23 ,
T_3 V_5 )
{
struct V_20 * V_49 = F_23 ( V_18 ) ;
struct V_26 * V_27 = V_49 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_29 ;
int V_6 ;
F_12 ( & V_2 -> V_36 ) ;
V_6 = F_13 ( V_2 , V_52 , 1 ) ;
if ( V_6 )
goto V_15;
if ( F_29 ( V_23 , L_5 ) ) {
V_6 = F_26 ( V_2 , V_52 ,
V_2 -> V_30 [ 0 ] | V_53 ) ;
V_2 -> V_35 = 8 ;
} else if ( F_29 ( V_23 , L_6 ) ) {
V_6 = F_26 ( V_2 , V_52 ,
V_2 -> V_30 [ 0 ] & ~ V_53 ) ;
V_2 -> V_35 = 11 ;
} else
V_6 = - V_37 ;
V_15:
F_16 ( & V_2 -> V_36 ) ;
return V_6 ? V_6 : V_5 ;
}
static T_5 F_30 ( struct V_43 * V_18 ,
struct V_44 * V_45 ,
char * V_23 )
{
struct V_20 * V_49 = F_23 ( V_18 ) ;
struct V_26 * V_27 = V_49 -> V_27 ;
struct V_1 * V_2 = V_27 -> V_29 ;
return sprintf ( V_23 , L_7 , 4 * V_2 -> V_54 -> V_55 ) ;
}
static struct V_20 * F_31 ( struct V_26 * V_27 )
{
struct V_20 * V_23 ;
struct V_24 * V_49 ;
V_49 = F_32 ( sizeof *V_49 , V_13 ) ;
if ( ! V_49 )
return NULL ;
V_49 -> V_28 = V_27 ;
V_23 = & V_49 -> V_23 ;
V_23 -> V_42 = 0 ;
F_33 ( V_23 , V_27 ) ;
V_23 -> V_18 . type = & V_56 ;
V_23 -> V_18 . V_57 = & V_27 -> V_18 ;
F_34 ( & V_23 -> V_18 , ( void * ) V_23 ) ;
return V_23 ;
}
static inline void F_35 ( struct V_20 * V_21 )
{
if ( V_21 )
F_36 ( V_21 ) ;
}
int F_37 ( struct V_26 * V_27 )
{
V_27 -> V_49 = F_31 ( V_27 ) ;
if ( V_27 -> V_49 == NULL )
return - V_14 ;
V_27 -> V_58 |= V_59 ;
V_27 -> V_49 -> V_60 = & V_61 ;
F_38 ( V_27 -> V_49 , 0 ) ;
F_38 ( V_27 -> V_49 , 1 ) ;
F_38 ( V_27 -> V_49 , 2 ) ;
return 0 ;
}
void F_39 ( struct V_26 * V_27 )
{
F_35 ( V_27 -> V_49 ) ;
}
static inline
int F_40 ( struct V_26 * V_27 , bool V_62 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_6 ;
F_12 ( & V_2 -> V_36 ) ;
V_6 = F_13 ( V_2 , V_52 , 1 ) ;
if ( V_6 )
goto V_15;
if ( V_62 ) {
F_41 ( V_63 L_8 ) ;
V_6 = F_26 ( V_2 ,
V_52 ,
( V_2 -> V_30 [ 0 ] | V_64 ) ) ;
} else
V_6 = F_26 ( V_2 ,
V_52 ,
( V_2 -> V_30 [ 0 ] & ~ V_64 ) ) ;
V_15:
F_16 ( & V_2 -> V_36 ) ;
return V_6 ;
}
static int F_42 ( struct V_26 * V_27 )
{
return F_40 ( V_27 , 1 ) ;
}
static int F_43 ( struct V_26 * V_27 )
{
return F_40 ( V_27 , 0 ) ;
}
void F_44 ( struct V_26 * V_27 )
{
V_27 -> V_49 -> V_65 = & V_66 ;
}
void F_45 ( T_2 V_48 , struct V_20 * V_49 )
{
if ( V_48 & ( V_67 |
V_68 ) ) {
V_49 -> V_42 = true ;
F_46 ( & V_49 -> V_69 ) ;
}
}
