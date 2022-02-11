static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return ( V_7 -> V_8 [ V_3 ] & V_4 ) >> V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 V_5 , T_2 V_9 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 = 0 ;
T_2 V_11 ;
if ( V_3 >= V_12 )
return - V_13 ;
F_4 ( & V_7 -> V_14 ) ;
V_11 = V_7 -> V_8 [ V_3 ] ;
V_11 &= ~ V_4 ;
V_11 |= V_9 << V_5 ;
V_10 = F_5 ( V_2 , V_3 , V_11 ) ;
if ( ! V_10 )
V_7 -> V_8 [ V_3 ] = V_11 ;
F_6 ( & V_7 -> V_14 ) ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_15 ,
V_16 , V_17 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_18 )
{
return F_3 ( V_2 , V_15 ,
V_16 , V_17 , V_18 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_19 ,
V_20 , V_21 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_22 )
{
return F_3 ( V_2 , V_19 ,
V_20 , V_21 , V_22 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_19 ,
V_20 , V_21 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_23 )
{
return F_3 ( V_2 , V_19 ,
V_20 , V_21 , V_23 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_24 )
{
return F_3 ( V_2 , V_19 ,
V_25 | V_26 , 0 ,
V_24 ? V_25 : V_26 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_27 = V_7 -> V_8 [ V_19 ] ;
return ~ V_27 & V_26 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_28 , V_29 , V_18 , V_30 ;
F_4 ( & V_7 -> V_14 ) ;
V_28 = F_16 ( V_2 , V_31 ) ;
if ( V_28 < 0 ) {
F_6 ( & V_7 -> V_14 ) ;
return V_28 ;
}
V_29 = F_16 ( V_2 , V_32 ) ;
F_6 ( & V_7 -> V_14 ) ;
if ( V_29 < 0 )
return V_29 ;
V_18 = F_7 ( V_2 ) ;
V_30 = ( 4 - F_9 ( V_2 ) ) * 4 ;
return ( ( ( V_29 << 8 ) | V_28 ) * V_33 [ V_18 ] ) >> V_30 ;
}
static T_3 F_17 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
return sprintf ( V_38 , L_1 , F_7 ( V_2 ) ) ;
}
static T_3 F_19 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_38 , T_4 V_39 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
unsigned long V_9 ;
int V_10 ;
if ( ( F_20 ( V_38 , 10 , & V_9 ) < 0 ) || ( V_9 > 3 ) )
return - V_13 ;
V_10 = F_8 ( V_2 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_39 ;
}
static T_3 F_21 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
return sprintf ( V_38 , L_2 , F_9 ( V_2 ) ) ;
}
static T_3 F_22 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_38 , T_4 V_39 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
unsigned long V_9 ;
int V_10 ;
if ( ( F_20 ( V_38 , 10 , & V_9 ) < 0 ) || ( V_9 > 3 ) )
return - V_13 ;
V_10 = F_10 ( V_2 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_39 ;
}
static T_3 F_23 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
return sprintf ( V_38 , L_2 , F_11 ( V_2 ) ) ;
}
static T_3 F_24 ( struct V_34 * V_35 ,
struct V_36 * V_37 , const char * V_38 , T_4 V_39 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
unsigned long V_9 ;
int V_10 ;
if ( ( F_20 ( V_38 , 10 , & V_9 ) < 0 ) || ( V_9 > 2 ) )
return - V_13 ;
V_10 = F_12 ( V_2 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_39 ;
}
static T_3 F_25 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
return sprintf ( V_38 , L_2 , F_14 ( V_2 ) ) ;
}
static T_3 F_26 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_38 , T_4 V_39 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
unsigned long V_9 ;
int V_10 ;
if ( ( F_20 ( V_38 , 10 , & V_9 ) < 0 ) || ( V_9 > 1 ) )
return - V_13 ;
V_10 = F_13 ( V_2 , V_9 ) ;
return V_10 ? V_10 : V_39 ;
}
static T_3 F_27 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
if ( ! F_14 ( V_2 ) )
return - V_40 ;
return sprintf ( V_38 , L_2 , F_15 ( V_2 ) ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_29 ( V_7 -> V_8 ) ; V_41 ++ ) {
int V_42 = F_16 ( V_2 , V_41 ) ;
if ( V_42 < 0 )
return - V_43 ;
V_7 -> V_8 [ V_41 ] = V_42 ;
}
F_8 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_13 ( V_2 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_44 * V_45 )
{
struct V_46 * V_47 = F_31 ( V_2 -> V_35 . V_48 ) ;
struct V_6 * V_7 ;
int V_49 = 0 ;
if ( ! F_32 ( V_47 , V_50 ) )
return - V_51 ;
V_7 = F_33 ( sizeof( struct V_6 ) , V_52 ) ;
if ( ! V_7 )
return - V_53 ;
V_7 -> V_2 = V_2 ;
F_34 ( V_2 , V_7 ) ;
F_35 ( & V_7 -> V_14 ) ;
V_49 = F_28 ( V_2 ) ;
if ( V_49 )
goto V_54;
V_49 = F_36 ( & V_2 -> V_35 . V_55 , & V_56 ) ;
if ( V_49 )
goto V_54;
F_37 ( & V_2 -> V_35 , L_3 , V_57 ) ;
return 0 ;
V_54:
F_38 ( V_7 ) ;
return V_49 ;
}
static int F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_35 . V_55 , & V_56 ) ;
F_13 ( V_2 , 0 ) ;
F_38 ( F_2 ( V_2 ) ) ;
return 0 ;
}
static int F_41 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_18 ( V_35 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_58 = F_14 ( V_2 ) ;
return F_13 ( V_2 , 0 ) ;
}
static int F_42 ( struct V_34 * V_35 )
{
int V_41 ;
struct V_1 * V_2 = F_18 ( V_35 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < F_29 ( V_7 -> V_8 ) ; V_41 ++ )
if ( F_5 ( V_2 , V_41 , V_7 -> V_8 [ V_41 ] ) )
return - V_51 ;
return F_13 ( V_2 ,
V_7 -> V_58 ) ;
}
