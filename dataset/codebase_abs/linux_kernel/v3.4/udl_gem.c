struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( V_5 == NULL )
return NULL ;
if ( F_3 ( V_3 , & V_5 -> V_7 , V_4 ) != 0 ) {
F_4 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
static int
F_5 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
T_2 V_4 ,
T_3 * V_10 )
{
struct V_1 * V_5 ;
int V_11 ;
T_4 V_12 ;
V_4 = F_6 ( V_4 , V_13 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 == NULL )
return - V_14 ;
V_11 = F_7 ( V_9 , & V_5 -> V_7 , & V_12 ) ;
if ( V_11 ) {
F_8 ( & V_5 -> V_7 ) ;
F_4 ( V_5 ) ;
return V_11 ;
}
F_9 ( & V_5 -> V_7 ) ;
* V_10 = V_12 ;
return 0 ;
}
int F_10 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
struct V_15 * args )
{
args -> V_16 = args -> V_17 * ( ( args -> V_18 + 1 ) / 8 ) ;
args -> V_4 = args -> V_16 * args -> V_19 ;
return F_5 ( V_9 , V_3 ,
args -> V_4 , & args -> V_12 ) ;
}
int F_11 ( struct V_8 * V_9 , struct V_2 * V_3 ,
T_3 V_12 )
{
return F_12 ( V_9 , V_12 ) ;
}
int F_13 ( struct V_9 * V_20 , struct V_21 * V_22 )
{
int V_11 ;
V_11 = F_14 ( V_20 , V_22 ) ;
if ( V_11 )
return V_11 ;
V_22 -> V_23 &= ~ V_24 ;
V_22 -> V_23 |= V_25 ;
return V_11 ;
}
int F_15 ( struct V_21 * V_22 , struct V_26 * V_27 )
{
struct V_1 * V_5 = F_16 ( V_22 -> V_28 ) ;
struct V_29 * V_29 ;
unsigned int V_30 ;
int V_11 = 0 ;
V_30 = ( ( unsigned long ) V_27 -> V_31 - V_22 -> V_32 ) >>
V_33 ;
if ( ! V_5 -> V_34 )
return V_35 ;
V_29 = V_5 -> V_34 [ V_30 ] ;
V_11 = F_17 ( V_22 , ( unsigned long ) V_27 -> V_31 , V_29 ) ;
switch ( V_11 ) {
case - V_36 :
F_18 () ;
case 0 :
case - V_37 :
return V_38 ;
case - V_14 :
return V_39 ;
default:
return V_35 ;
}
}
int F_19 ( struct V_40 * V_5 )
{
F_20 () ;
return 0 ;
}
static int F_21 ( struct V_1 * V_5 , T_5 V_41 )
{
int V_42 , V_43 ;
struct V_29 * V_29 ;
struct V_44 * V_44 ;
struct V_45 * V_46 ;
if ( V_5 -> V_34 )
return 0 ;
V_42 = V_5 -> V_7 . V_4 / V_13 ;
F_22 ( V_5 -> V_34 != NULL ) ;
V_5 -> V_34 = F_23 ( V_42 , sizeof( struct V_29 * ) ) ;
if ( V_5 -> V_34 == NULL )
return - V_14 ;
V_44 = V_5 -> V_7 . V_20 -> V_47 . V_48 -> V_49 ;
V_46 = V_44 -> V_50 ;
V_41 |= F_24 ( V_46 ) ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_29 = F_25 ( V_46 , V_43 , V_41 ) ;
if ( F_26 ( V_29 ) )
goto V_51;
V_5 -> V_34 [ V_43 ] = V_29 ;
}
return 0 ;
V_51:
while ( V_43 -- )
F_27 ( V_5 -> V_34 [ V_43 ] ) ;
F_28 ( V_5 -> V_34 ) ;
V_5 -> V_34 = NULL ;
return F_29 ( V_29 ) ;
}
static void F_30 ( struct V_1 * V_5 )
{
int V_42 = V_5 -> V_7 . V_4 / V_13 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
F_27 ( V_5 -> V_34 [ V_43 ] ) ;
F_28 ( V_5 -> V_34 ) ;
V_5 -> V_34 = NULL ;
}
int F_31 ( struct V_1 * V_5 )
{
int V_42 = V_5 -> V_7 . V_4 / V_13 ;
int V_11 ;
V_11 = F_21 ( V_5 , V_6 ) ;
if ( V_11 )
return V_11 ;
V_5 -> V_52 = F_32 ( V_5 -> V_34 , V_42 , 0 , V_53 ) ;
if ( ! V_5 -> V_52 )
return - V_14 ;
return 0 ;
}
void F_33 ( struct V_1 * V_5 )
{
if ( V_5 -> V_52 )
F_34 ( V_5 -> V_52 ) ;
F_30 ( V_5 ) ;
}
void F_35 ( struct V_40 * V_54 )
{
struct V_1 * V_5 = F_16 ( V_54 ) ;
if ( V_5 -> V_52 )
F_33 ( V_5 ) ;
if ( V_5 -> V_34 )
F_30 ( V_5 ) ;
if ( V_54 -> V_55 . V_56 )
F_36 ( V_54 ) ;
}
int F_37 ( struct V_8 * V_9 , struct V_2 * V_3 ,
T_3 V_12 , T_2 * V_57 )
{
struct V_1 * V_58 ;
struct V_40 * V_5 ;
int V_11 = 0 ;
F_38 ( & V_3 -> V_59 ) ;
V_5 = F_39 ( V_3 , V_9 , V_12 ) ;
if ( V_5 == NULL ) {
V_11 = - V_60 ;
goto V_61;
}
V_58 = F_16 ( V_5 ) ;
V_11 = F_21 ( V_58 , V_6 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_58 -> V_7 . V_55 . V_56 ) {
V_11 = F_40 ( V_5 ) ;
if ( V_11 )
goto V_62;
}
* V_57 = ( V_63 ) V_58 -> V_7 . V_55 . V_64 . V_65 << V_33 ;
V_62:
F_9 ( & V_58 -> V_7 ) ;
V_61:
F_41 ( & V_3 -> V_59 ) ;
return V_11 ;
}
