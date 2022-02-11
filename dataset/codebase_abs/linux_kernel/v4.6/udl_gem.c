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
V_5 -> V_8 = V_9 ;
return V_5 ;
}
static int
F_5 ( struct V_10 * V_11 ,
struct V_2 * V_3 ,
T_2 V_4 ,
T_3 * V_12 )
{
struct V_1 * V_5 ;
int V_13 ;
T_4 V_14 ;
V_4 = F_6 ( V_4 , V_15 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 == NULL )
return - V_16 ;
V_13 = F_7 ( V_11 , & V_5 -> V_7 , & V_14 ) ;
if ( V_13 ) {
F_8 ( & V_5 -> V_7 ) ;
F_4 ( V_5 ) ;
return V_13 ;
}
F_9 ( & V_5 -> V_7 ) ;
* V_12 = V_14 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_5 ,
struct V_17 * V_18 )
{
F_11 ( L_1 , V_5 -> V_8 ) ;
if ( V_5 -> V_8 & V_9 ) {
V_18 -> V_19 = F_12 ( V_18 -> V_20 ) ;
} else if ( V_5 -> V_8 & V_21 ) {
V_18 -> V_19 =
F_13 ( F_12 ( V_18 -> V_20 ) ) ;
} else {
V_18 -> V_19 =
F_14 ( F_12 ( V_18 -> V_20 ) ) ;
}
}
int F_15 ( struct V_10 * V_11 ,
struct V_2 * V_3 ,
struct V_22 * args )
{
args -> V_23 = args -> V_24 * F_16 ( args -> V_25 , 8 ) ;
args -> V_4 = args -> V_23 * args -> V_26 ;
return F_5 ( V_11 , V_3 ,
args -> V_4 , & args -> V_14 ) ;
}
int F_17 ( struct V_11 * V_27 , struct V_17 * V_18 )
{
int V_13 ;
V_13 = F_18 ( V_27 , V_18 ) ;
if ( V_13 )
return V_13 ;
V_18 -> V_20 &= ~ V_28 ;
V_18 -> V_20 |= V_29 ;
F_10 ( F_19 ( V_18 -> V_30 ) , V_18 ) ;
return V_13 ;
}
int F_20 ( struct V_17 * V_18 , struct V_31 * V_32 )
{
struct V_1 * V_5 = F_19 ( V_18 -> V_30 ) ;
struct V_33 * V_33 ;
unsigned int V_34 ;
int V_13 = 0 ;
V_34 = ( ( unsigned long ) V_32 -> V_35 - V_18 -> V_36 ) >>
V_37 ;
if ( ! V_5 -> V_38 )
return V_39 ;
V_33 = V_5 -> V_38 [ V_34 ] ;
V_13 = F_21 ( V_18 , ( unsigned long ) V_32 -> V_35 , V_33 ) ;
switch ( V_13 ) {
case - V_40 :
case 0 :
case - V_41 :
return V_42 ;
case - V_16 :
return V_43 ;
default:
return V_39 ;
}
}
int F_22 ( struct V_1 * V_5 )
{
struct V_33 * * V_38 ;
if ( V_5 -> V_38 )
return 0 ;
V_38 = F_23 ( & V_5 -> V_7 ) ;
if ( F_24 ( V_38 ) )
return F_25 ( V_38 ) ;
V_5 -> V_38 = V_38 ;
return 0 ;
}
void F_26 ( struct V_1 * V_5 )
{
if ( V_5 -> V_7 . V_44 ) {
F_27 ( V_5 -> V_38 ) ;
V_5 -> V_38 = NULL ;
return;
}
F_28 ( & V_5 -> V_7 , V_5 -> V_38 , false , false ) ;
V_5 -> V_38 = NULL ;
}
int F_29 ( struct V_1 * V_5 )
{
int V_45 = V_5 -> V_7 . V_4 / V_15 ;
int V_13 ;
if ( V_5 -> V_7 . V_44 ) {
V_5 -> V_46 = F_30 ( V_5 -> V_7 . V_44 -> V_47 ) ;
if ( ! V_5 -> V_46 )
return - V_16 ;
return 0 ;
}
V_13 = F_22 ( V_5 ) ;
if ( V_13 )
return V_13 ;
V_5 -> V_46 = F_31 ( V_5 -> V_38 , V_45 , 0 , V_48 ) ;
if ( ! V_5 -> V_46 )
return - V_16 ;
return 0 ;
}
void F_32 ( struct V_1 * V_5 )
{
if ( V_5 -> V_7 . V_44 ) {
F_33 ( V_5 -> V_7 . V_44 -> V_47 , V_5 -> V_46 ) ;
return;
}
F_34 ( V_5 -> V_46 ) ;
F_26 ( V_5 ) ;
}
void F_35 ( struct V_49 * V_50 )
{
struct V_1 * V_5 = F_19 ( V_50 ) ;
if ( V_5 -> V_46 )
F_32 ( V_5 ) ;
if ( V_50 -> V_44 ) {
F_36 ( V_50 , V_5 -> V_51 ) ;
F_37 ( V_50 -> V_3 -> V_3 ) ;
}
if ( V_5 -> V_38 )
F_26 ( V_5 ) ;
F_38 ( V_50 ) ;
}
int F_39 ( struct V_10 * V_11 , struct V_2 * V_3 ,
T_3 V_14 , T_2 * V_52 )
{
struct V_1 * V_53 ;
struct V_49 * V_5 ;
int V_13 = 0 ;
F_40 ( & V_3 -> V_54 ) ;
V_5 = F_41 ( V_3 , V_11 , V_14 ) ;
if ( V_5 == NULL ) {
V_13 = - V_55 ;
goto V_56;
}
V_53 = F_19 ( V_5 ) ;
V_13 = F_22 ( V_53 ) ;
if ( V_13 )
goto V_57;
V_13 = F_42 ( V_5 ) ;
if ( V_13 )
goto V_57;
* V_52 = F_43 ( & V_53 -> V_7 . V_58 ) ;
V_57:
F_44 ( & V_53 -> V_7 ) ;
V_56:
F_45 ( & V_3 -> V_54 ) ;
return V_13 ;
}
