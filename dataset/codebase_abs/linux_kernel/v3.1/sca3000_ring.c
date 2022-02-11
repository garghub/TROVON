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
struct V_1 * V_2 = F_12 ( V_27 ) ;
T_2 * V_29 ;
int V_6 , V_30 , V_31 , V_32 = 0 ;
int V_33 = 1 ;
if ( V_2 -> V_34 == 11 )
V_33 = 2 ;
F_13 ( & V_2 -> V_35 ) ;
if ( V_22 % V_33 ) {
V_6 = - V_36 ;
goto V_15;
}
V_6 = F_14 ( V_2 , V_37 , 1 ) ;
if ( V_6 )
goto V_15;
else
V_31 = V_2 -> V_29 [ 0 ] ;
if ( V_22 > V_31 * V_33 )
V_32 = V_31 * V_33 ;
else
V_32 = V_22 ;
V_6 = F_1 ( V_2 ,
V_38 ,
& V_29 , V_32 ) ;
if ( V_6 )
goto V_15;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ )
* ( ( ( V_39 * ) V_29 ) + V_30 ) = F_15 ( ( V_39 * ) V_29 + V_30 ) ;
if ( F_16 ( V_23 , V_29 , V_32 ) )
V_6 = - V_40 ;
F_9 ( V_29 ) ;
V_21 -> V_41 = 0 ;
V_15:
F_17 ( & V_2 -> V_35 ) ;
return V_6 ? V_6 : V_32 ;
}
static int F_18 ( struct V_20 * V_21 )
{
return 64 ;
}
static int F_19 ( struct V_20 * V_21 )
{
return 6 ;
}
static void F_20 ( struct V_42 * V_18 )
{
struct V_20 * V_21 = F_21 ( V_18 ) ;
F_9 ( F_11 ( V_21 ) ) ;
}
static T_5 F_22 ( struct V_42 * V_18 ,
struct V_43 * V_44 ,
char * V_23 )
{
struct V_45 * V_46 = F_23 ( V_44 ) ;
int V_6 , V_47 ;
struct V_20 * V_48 = F_24 ( V_18 ) ;
struct V_26 * V_27 = V_48 -> V_27 ;
struct V_1 * V_2 = F_12 ( V_27 ) ;
F_13 ( & V_2 -> V_35 ) ;
V_6 = F_14 ( V_2 , V_49 , 1 ) ;
V_47 = V_2 -> V_29 [ 0 ] ;
F_17 ( & V_2 -> V_35 ) ;
if ( V_6 )
return V_6 ;
return sprintf ( V_23 , L_2 , ! ! ( V_47 & V_46 -> V_50 ) ) ;
}
static T_5 F_25 ( struct V_42 * V_18 ,
struct V_43 * V_44 ,
const char * V_23 ,
T_3 V_5 )
{
struct V_20 * V_48 = F_24 ( V_18 ) ;
struct V_26 * V_27 = V_48 -> V_27 ;
struct V_1 * V_2 = F_12 ( V_27 ) ;
struct V_45 * V_46 = F_23 ( V_44 ) ;
long V_47 ;
int V_6 ;
F_13 ( & V_2 -> V_35 ) ;
V_6 = F_26 ( V_23 , 10 , & V_47 ) ;
if ( V_6 )
goto V_15;
V_6 = F_14 ( V_2 , V_49 , 1 ) ;
if ( V_6 )
goto V_15;
if ( V_47 )
V_6 = F_27 ( V_2 ,
V_49 ,
V_2 -> V_29 [ 0 ] | V_46 -> V_50 ) ;
else
V_6 = F_27 ( V_2 ,
V_49 ,
V_2 -> V_29 [ 0 ] & ~ V_46 -> V_50 ) ;
V_15:
F_17 ( & V_2 -> V_35 ) ;
return V_6 ? V_6 : V_5 ;
}
static T_5 F_28 ( struct V_42 * V_18 ,
struct V_43 * V_44 ,
char * V_23 )
{
int V_5 = 0 , V_6 ;
struct V_20 * V_48 = F_24 ( V_18 ) ;
struct V_26 * V_27 = V_48 -> V_27 ;
struct V_1 * V_2 = F_12 ( V_27 ) ;
F_13 ( & V_2 -> V_35 ) ;
V_6 = F_14 ( V_2 , V_51 , 1 ) ;
if ( V_6 )
goto V_15;
if ( V_2 -> V_29 [ 0 ] & V_52 )
V_5 = sprintf ( V_23 , L_3 ) ;
else
V_5 = sprintf ( V_23 , L_4 ) ;
V_15:
F_17 ( & V_2 -> V_35 ) ;
return V_6 ? V_6 : V_5 ;
}
static T_5 F_29 ( struct V_42 * V_18 ,
struct V_43 * V_44 ,
const char * V_23 ,
T_3 V_5 )
{
struct V_20 * V_48 = F_24 ( V_18 ) ;
struct V_26 * V_27 = V_48 -> V_27 ;
struct V_1 * V_2 = F_12 ( V_27 ) ;
int V_6 ;
F_13 ( & V_2 -> V_35 ) ;
V_6 = F_14 ( V_2 , V_51 , 1 ) ;
if ( V_6 )
goto V_15;
if ( F_30 ( V_23 , L_5 ) ) {
V_6 = F_27 ( V_2 , V_51 ,
V_2 -> V_29 [ 0 ] | V_52 ) ;
V_2 -> V_34 = 8 ;
} else if ( F_30 ( V_23 , L_6 ) ) {
V_6 = F_27 ( V_2 , V_51 ,
V_2 -> V_29 [ 0 ] & ~ V_52 ) ;
V_2 -> V_34 = 11 ;
} else
V_6 = - V_36 ;
V_15:
F_17 ( & V_2 -> V_35 ) ;
return V_6 ? V_6 : V_5 ;
}
static T_5 F_31 ( struct V_42 * V_18 ,
struct V_43 * V_44 ,
char * V_23 )
{
struct V_20 * V_48 = F_24 ( V_18 ) ;
struct V_26 * V_27 = V_48 -> V_27 ;
struct V_1 * V_2 = F_12 ( V_27 ) ;
return sprintf ( V_23 , L_7 , 4 * V_2 -> V_53 -> V_54 ) ;
}
static struct V_20 * F_32 ( struct V_26 * V_27 )
{
struct V_20 * V_23 ;
struct V_24 * V_48 ;
V_48 = F_33 ( sizeof *V_48 , V_13 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_28 = V_27 ;
V_23 = & V_48 -> V_23 ;
V_23 -> V_41 = 0 ;
F_34 ( V_23 , V_27 ) ;
V_23 -> V_18 . type = & V_55 ;
V_23 -> V_18 . V_56 = & V_27 -> V_18 ;
F_35 ( & V_23 -> V_18 , ( void * ) V_23 ) ;
return V_23 ;
}
static inline void F_36 ( struct V_20 * V_21 )
{
if ( V_21 )
F_37 ( V_21 ) ;
}
int F_38 ( struct V_26 * V_27 )
{
V_27 -> V_48 = F_32 ( V_27 ) ;
if ( V_27 -> V_48 == NULL )
return - V_14 ;
V_27 -> V_57 |= V_58 ;
V_27 -> V_48 -> V_59 = & V_60 ;
F_39 ( V_27 -> V_48 , 0 ) ;
F_39 ( V_27 -> V_48 , 1 ) ;
F_39 ( V_27 -> V_48 , 2 ) ;
return 0 ;
}
void F_40 ( struct V_26 * V_27 )
{
F_36 ( V_27 -> V_48 ) ;
}
static inline
int F_41 ( struct V_26 * V_27 , bool V_61 )
{
struct V_1 * V_2 = F_12 ( V_27 ) ;
int V_6 ;
F_13 ( & V_2 -> V_35 ) ;
V_6 = F_14 ( V_2 , V_51 , 1 ) ;
if ( V_6 )
goto V_15;
if ( V_61 ) {
F_42 ( V_62 L_8 ) ;
V_6 = F_27 ( V_2 ,
V_51 ,
( V_2 -> V_29 [ 0 ] | V_63 ) ) ;
} else
V_6 = F_27 ( V_2 ,
V_51 ,
( V_2 -> V_29 [ 0 ] & ~ V_63 ) ) ;
V_15:
F_17 ( & V_2 -> V_35 ) ;
return V_6 ;
}
static int F_43 ( struct V_26 * V_27 )
{
return F_41 ( V_27 , 1 ) ;
}
static int F_44 ( struct V_26 * V_27 )
{
return F_41 ( V_27 , 0 ) ;
}
void F_45 ( struct V_26 * V_27 )
{
V_27 -> V_48 -> V_64 = & V_65 ;
}
void F_46 ( T_2 V_47 , struct V_20 * V_48 )
{
if ( V_47 & ( V_66 |
V_67 ) ) {
V_48 -> V_41 = true ;
F_47 ( & V_48 -> V_68 ) ;
}
}
