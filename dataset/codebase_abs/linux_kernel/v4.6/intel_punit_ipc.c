static inline T_1 F_1 ( T_2 * V_1 , T_3 type )
{
return F_2 ( V_1 -> V_2 [ type ] [ V_3 ] ) ;
}
static inline void F_3 ( T_2 * V_1 , T_3 type , T_1 V_4 )
{
F_4 ( V_4 , V_1 -> V_2 [ type ] [ V_3 ] ) ;
}
static inline T_1 F_5 ( T_2 * V_1 , T_3 type )
{
return F_2 ( V_1 -> V_2 [ type ] [ V_5 ] + V_6 ) ;
}
static inline T_1 F_6 ( T_2 * V_1 , T_3 type )
{
return F_2 ( V_1 -> V_2 [ type ] [ V_5 ] + V_7 ) ;
}
static inline void F_7 ( T_2 * V_1 , T_3 type , T_1 V_8 )
{
F_4 ( V_8 , V_1 -> V_2 [ type ] [ V_5 ] + V_6 ) ;
}
static inline void F_8 ( T_2 * V_1 , T_3 type , T_1 V_8 )
{
F_4 ( V_8 , V_1 -> V_2 [ type ] [ V_5 ] + V_7 ) ;
}
static const char * F_9 ( int error )
{
if ( error == V_9 )
return L_1 ;
else if ( error == V_10 )
return L_2 ;
else if ( error == V_11 )
return L_3 ;
else if ( error == V_12 )
return L_4 ;
else if ( error == V_13 )
return L_5 ;
else if ( error == V_14 )
return L_6 ;
else if ( error == V_15 )
return L_7 ;
else
return L_8 ;
}
static int F_10 ( T_2 * V_1 , T_3 type )
{
int V_16 = V_17 * V_18 ;
int V_19 ;
int V_20 ;
if ( V_1 -> V_21 ) {
if ( ! F_11 ( & V_1 -> V_22 ,
V_17 * V_23 ) ) {
F_12 ( V_1 -> V_24 , L_9 ) ;
return - V_25 ;
}
} else {
while ( ( F_1 ( V_1 , type ) & V_26 ) && -- V_16 )
F_13 ( 1 ) ;
if ( ! V_16 ) {
F_12 ( V_1 -> V_24 , L_9 ) ;
return - V_25 ;
}
}
V_20 = F_1 ( V_1 , type ) ;
V_19 = V_20 & V_27 ;
if ( V_19 ) {
F_12 ( V_1 -> V_24 , L_10 ,
F_9 ( V_19 ) , V_20 ) ;
return - V_28 ;
}
return 0 ;
}
int F_14 ( int V_4 , int V_29 , int V_30 )
{
T_2 * V_1 = V_31 ;
T_3 type ;
T_1 V_32 ;
int V_33 ;
F_15 ( & V_1 -> V_34 ) ;
F_16 ( & V_1 -> V_22 ) ;
type = ( V_4 & V_35 ) >> V_36 ;
V_32 = V_4 & ~ V_35 ;
V_32 |= V_26 | V_30 << V_37 | V_29 << V_38 ;
F_3 ( V_1 , type , V_32 ) ;
V_33 = F_10 ( V_1 , type ) ;
F_17 ( & V_1 -> V_34 ) ;
return V_33 ;
}
int F_18 ( T_1 V_4 , T_1 V_29 , T_1 V_30 , T_1 * V_39 , T_1 * V_40 )
{
T_2 * V_1 = V_31 ;
T_3 type ;
T_1 V_32 ;
int V_33 ;
F_15 ( & V_1 -> V_34 ) ;
F_16 ( & V_1 -> V_22 ) ;
type = ( V_4 & V_35 ) >> V_36 ;
if ( V_39 ) {
F_7 ( V_1 , type , * V_39 ) ;
if ( type == V_41 || type == V_42 )
F_8 ( V_1 , type , * ++ V_39 ) ;
}
V_32 = V_4 & ~ V_35 ;
V_32 |= V_26 | V_30 << V_37 | V_29 << V_38 ;
F_3 ( V_1 , type , V_32 ) ;
V_33 = F_10 ( V_1 , type ) ;
if ( V_33 )
goto V_40;
if ( V_40 ) {
* V_40 = F_5 ( V_1 , type ) ;
if ( type == V_41 || type == V_42 )
* ++ V_40 = F_6 ( V_1 , type ) ;
}
V_40:
F_17 ( & V_1 -> V_34 ) ;
return V_33 ;
}
static T_4 F_19 ( int V_21 , void * V_43 )
{
T_2 * V_1 = V_43 ;
F_20 ( & V_1 -> V_22 ) ;
return V_44 ;
}
static int F_21 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
void T_5 * V_49 ;
V_48 = F_22 ( V_46 , V_50 , 0 ) ;
V_49 = F_23 ( & V_46 -> V_24 , V_48 ) ;
if ( F_24 ( V_49 ) )
return F_25 ( V_49 ) ;
V_31 -> V_2 [ V_51 ] [ V_5 ] = V_49 ;
V_48 = F_22 ( V_46 , V_50 , 1 ) ;
V_49 = F_23 ( & V_46 -> V_24 , V_48 ) ;
if ( F_24 ( V_49 ) )
return F_25 ( V_49 ) ;
V_31 -> V_2 [ V_51 ] [ V_3 ] = V_49 ;
V_48 = F_22 ( V_46 , V_50 , 2 ) ;
if ( V_48 ) {
V_49 = F_23 ( & V_46 -> V_24 , V_48 ) ;
if ( ! F_24 ( V_49 ) )
V_31 -> V_2 [ V_42 ] [ V_5 ] = V_49 ;
}
V_48 = F_22 ( V_46 , V_50 , 3 ) ;
if ( V_48 ) {
V_49 = F_23 ( & V_46 -> V_24 , V_48 ) ;
if ( ! F_24 ( V_49 ) )
V_31 -> V_2 [ V_42 ] [ V_3 ] = V_49 ;
}
V_48 = F_22 ( V_46 , V_50 , 4 ) ;
if ( V_48 ) {
V_49 = F_23 ( & V_46 -> V_24 , V_48 ) ;
if ( ! F_24 ( V_49 ) )
V_31 -> V_2 [ V_41 ] [ V_5 ] = V_49 ;
}
V_48 = F_22 ( V_46 , V_50 , 5 ) ;
if ( V_48 ) {
V_49 = F_23 ( & V_46 -> V_24 , V_48 ) ;
if ( ! F_24 ( V_49 ) )
V_31 -> V_2 [ V_41 ] [ V_3 ] = V_49 ;
}
return 0 ;
}
static int F_26 ( struct V_45 * V_46 )
{
int V_21 , V_33 ;
V_31 = F_27 ( & V_46 -> V_24 ,
sizeof( * V_31 ) , V_52 ) ;
if ( ! V_31 )
return - V_53 ;
F_28 ( V_46 , V_31 ) ;
V_21 = F_29 ( V_46 , 0 ) ;
if ( V_21 < 0 ) {
V_31 -> V_21 = 0 ;
F_30 ( & V_46 -> V_24 , L_11 ) ;
} else {
V_33 = F_31 ( & V_46 -> V_24 , V_21 , F_19 ,
V_54 , L_12 ,
& V_31 ) ;
if ( V_33 ) {
F_12 ( & V_46 -> V_24 , L_13 , V_21 ) ;
return V_33 ;
}
V_31 -> V_21 = V_21 ;
}
V_33 = F_21 ( V_46 ) ;
if ( V_33 )
goto V_40;
V_31 -> V_24 = & V_46 -> V_24 ;
F_32 ( & V_31 -> V_34 ) ;
F_33 ( & V_31 -> V_22 ) ;
V_40:
return V_33 ;
}
static int F_34 ( struct V_45 * V_46 )
{
return 0 ;
}
static int T_6 F_35 ( void )
{
return F_36 ( & V_55 ) ;
}
static void T_7 F_37 ( void )
{
F_38 ( & V_55 ) ;
}
