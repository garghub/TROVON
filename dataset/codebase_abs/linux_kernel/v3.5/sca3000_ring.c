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
static T_5 F_20 ( struct V_42 * V_18 ,
struct V_43 * V_44 ,
char * V_23 )
{
struct V_45 * V_46 = F_21 ( V_44 ) ;
int V_6 , V_47 ;
struct V_26 * V_27 = F_22 ( V_18 ) ;
struct V_1 * V_2 = F_12 ( V_27 ) ;
F_13 ( & V_2 -> V_35 ) ;
V_6 = F_14 ( V_2 , V_48 , 1 ) ;
V_47 = V_2 -> V_29 [ 0 ] ;
F_17 ( & V_2 -> V_35 ) ;
if ( V_6 )
return V_6 ;
return sprintf ( V_23 , L_2 , ! ! ( V_47 & V_46 -> V_49 ) ) ;
}
static T_5 F_23 ( struct V_42 * V_18 ,
struct V_43 * V_44 ,
const char * V_23 ,
T_3 V_5 )
{
struct V_26 * V_27 = F_22 ( V_18 ) ;
struct V_1 * V_2 = F_12 ( V_27 ) ;
struct V_45 * V_46 = F_21 ( V_44 ) ;
long V_47 ;
int V_6 ;
F_13 ( & V_2 -> V_35 ) ;
V_6 = F_24 ( V_23 , 10 , & V_47 ) ;
if ( V_6 )
goto V_15;
V_6 = F_14 ( V_2 , V_48 , 1 ) ;
if ( V_6 )
goto V_15;
if ( V_47 )
V_6 = F_25 ( V_2 ,
V_48 ,
V_2 -> V_29 [ 0 ] | V_46 -> V_49 ) ;
else
V_6 = F_25 ( V_2 ,
V_48 ,
V_2 -> V_29 [ 0 ] & ~ V_46 -> V_49 ) ;
V_15:
F_17 ( & V_2 -> V_35 ) ;
return V_6 ? V_6 : V_5 ;
}
static T_5 F_26 ( struct V_42 * V_18 ,
struct V_43 * V_44 ,
char * V_23 )
{
struct V_26 * V_27 = F_22 ( V_18 ) ;
struct V_1 * V_2 = F_12 ( V_27 ) ;
return sprintf ( V_23 , L_3 , 4 * V_2 -> V_50 -> V_51 ) ;
}
static struct V_20 * F_27 ( struct V_26 * V_27 )
{
struct V_20 * V_23 ;
struct V_24 * V_52 ;
V_52 = F_28 ( sizeof *V_52 , V_13 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_28 = V_27 ;
V_23 = & V_52 -> V_23 ;
V_23 -> V_41 = 0 ;
V_23 -> V_53 = & V_54 ;
F_29 ( V_23 ) ;
return V_23 ;
}
static inline void F_30 ( struct V_20 * V_21 )
{
F_9 ( F_11 ( V_21 ) ) ;
}
int F_31 ( struct V_26 * V_27 )
{
V_27 -> V_55 = F_27 ( V_27 ) ;
if ( V_27 -> V_55 == NULL )
return - V_14 ;
V_27 -> V_56 |= V_57 ;
V_27 -> V_55 -> V_58 = & V_59 ;
return 0 ;
}
void F_32 ( struct V_26 * V_27 )
{
F_30 ( V_27 -> V_55 ) ;
}
static inline
int F_33 ( struct V_26 * V_27 , bool V_60 )
{
struct V_1 * V_2 = F_12 ( V_27 ) ;
int V_6 ;
F_13 ( & V_2 -> V_35 ) ;
V_6 = F_14 ( V_2 , V_61 , 1 ) ;
if ( V_6 )
goto V_15;
if ( V_60 ) {
F_34 ( V_62 L_4 ) ;
V_6 = F_25 ( V_2 ,
V_61 ,
( V_2 -> V_29 [ 0 ] | V_63 ) ) ;
} else
V_6 = F_25 ( V_2 ,
V_61 ,
( V_2 -> V_29 [ 0 ] & ~ V_63 ) ) ;
V_15:
F_17 ( & V_2 -> V_35 ) ;
return V_6 ;
}
static int F_35 ( struct V_26 * V_27 )
{
return F_33 ( V_27 , 1 ) ;
}
static int F_36 ( struct V_26 * V_27 )
{
return F_33 ( V_27 , 0 ) ;
}
void F_37 ( struct V_26 * V_27 )
{
V_27 -> V_64 = & V_65 ;
}
void F_38 ( T_2 V_47 , struct V_20 * V_52 )
{
if ( V_47 & ( V_66 |
V_67 ) ) {
V_52 -> V_41 = true ;
F_39 ( & V_52 -> V_68 ) ;
}
}
