static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( & V_2 -> V_4 ) ;
V_3 = V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
F_3 ( & V_2 -> V_4 ) ;
if ( ! V_3 )
return 0 ;
F_4 ( V_2 -> V_5 ) ;
F_5 ( V_2 -> V_5 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_3 = V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
F_3 ( & V_2 -> V_4 ) ;
if ( V_3 )
F_4 ( V_2 -> V_5 ) ;
return 1 ;
}
static T_1 F_6 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_3 = 1 ;
F_8 ( V_2 -> V_5 ) ;
F_9 ( & V_2 -> V_4 ) ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_9 ;
V_2 -> V_10 = ( V_2 -> V_11 + V_2 -> V_12 + ! V_2 -> V_13 ) / 2 ;
if ( V_2 -> V_11 == V_2 -> V_12 + 1 ) {
F_11 ( & V_2 -> V_14 ) ;
return;
}
V_9 = F_12 ( V_2 -> V_15 , V_2 -> V_13 ? 0 : V_2 -> V_16 ) ;
if ( V_9 < 0 )
goto V_17;
F_1 ( V_2 ) ;
V_9 = F_12 ( V_2 -> V_15 , V_2 -> V_10 ) ;
if ( V_9 < 0 )
goto V_17;
F_13 ( & V_2 -> V_18 ,
F_14 ( V_2 -> V_19 ) ) ;
return;
V_17:
V_2 -> V_10 = V_9 ;
F_11 ( & V_2 -> V_14 ) ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 , struct V_1 ,
V_18 . V_21 ) ;
if ( ! F_1 ( V_2 ) ^ ! V_2 -> V_13 )
V_2 -> V_12 = V_2 -> V_10 ;
else
V_2 -> V_11 = V_2 -> V_10 ;
F_10 ( V_2 ) ;
}
static int F_17 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int * V_26 , int * V_27 , long V_28 )
{
struct V_1 * V_2 = F_18 ( V_23 ) ;
int V_9 ;
switch ( V_28 ) {
case V_29 :
F_19 ( & V_2 -> V_30 ) ;
V_2 -> V_11 = V_2 -> V_16 + V_2 -> V_13 ;
V_2 -> V_12 = - 1 + V_2 -> V_13 ;
F_10 ( V_2 ) ;
F_20 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_10 < 0 ) {
V_9 = V_2 -> V_10 ;
goto V_31;
}
* V_26 = V_2 -> V_13 ? V_2 -> V_16 - V_2 -> V_10 : V_2 -> V_10 ;
F_21 ( & V_2 -> V_30 ) ;
return V_32 ;
case V_33 :
return F_22 ( V_2 -> V_15 , V_26 , V_27 ) ;
}
return - V_34 ;
V_31:
F_21 ( & V_2 -> V_30 ) ;
return V_9 ;
}
static T_2 F_23 ( struct V_22 * V_23 ,
T_3 V_35 ,
struct V_24 const * V_36 , char * V_37 )
{
struct V_1 * V_2 = F_18 ( V_23 ) ;
return sprintf ( V_37 , L_1 , V_2 -> V_13 ) ;
}
static T_2 F_24 ( struct V_22 * V_23 ,
T_3 V_35 ,
struct V_24 const * V_36 ,
const char * V_37 , T_4 V_38 )
{
struct V_1 * V_2 = F_18 ( V_23 ) ;
unsigned long V_13 ;
int V_9 ;
T_5 V_39 ;
V_9 = F_25 ( V_37 , 0 , & V_13 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_13 > 1 )
return - V_34 ;
V_39 = V_13 ? V_2 -> V_40 : V_2 -> V_41 ;
F_19 ( & V_2 -> V_30 ) ;
if ( V_13 != V_2 -> V_13 )
V_9 = F_26 ( V_2 -> V_5 , V_39 ) ;
if ( ! V_9 ) {
V_2 -> V_13 = V_13 ;
V_9 = V_38 ;
}
F_21 ( & V_2 -> V_30 ) ;
return V_9 ;
}
static T_2 F_27 ( struct V_22 * V_23 ,
T_3 V_35 ,
struct V_24 const * V_36 ,
char * V_37 )
{
struct V_1 * V_2 = F_18 ( V_23 ) ;
return sprintf ( V_37 , L_1 , V_2 -> V_19 ) ;
}
static T_2 F_28 ( struct V_22 * V_23 ,
T_3 V_35 ,
struct V_24 const * V_36 ,
const char * V_37 , T_4 V_38 )
{
struct V_1 * V_2 = F_18 ( V_23 ) ;
unsigned long V_42 ;
int V_9 ;
V_9 = F_25 ( V_37 , 0 , & V_42 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_42 > 1000 )
return - V_34 ;
F_19 ( & V_2 -> V_30 ) ;
V_2 -> V_19 = V_42 ;
F_21 ( & V_2 -> V_30 ) ;
return V_38 ;
}
static int F_29 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = & V_44 -> V_46 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
enum V_47 type ;
int V_9 ;
V_23 = F_30 ( V_46 , sizeof( * V_2 ) ) ;
if ( ! V_23 )
return - V_48 ;
F_31 ( V_44 , V_23 ) ;
V_2 = F_18 ( V_23 ) ;
V_2 -> V_19 = 50 ;
F_32 ( & V_2 -> V_4 ) ;
F_33 ( & V_2 -> V_30 ) ;
F_34 ( & V_2 -> V_14 ) ;
F_35 ( & V_2 -> V_18 , F_15 ) ;
V_23 -> V_49 = F_36 ( V_46 ) ;
V_23 -> V_46 . V_50 = V_46 ;
V_23 -> V_46 . V_51 = V_46 -> V_51 ;
V_23 -> V_52 = & V_53 ;
V_23 -> V_54 = & V_55 ;
V_23 -> V_56 = 1 ;
V_2 -> V_15 = F_37 ( V_46 , L_2 ) ;
if ( F_38 ( V_2 -> V_15 ) ) {
if ( F_39 ( V_2 -> V_15 ) != - V_57 )
F_40 ( V_46 , L_3 ) ;
return F_39 ( V_2 -> V_15 ) ;
}
V_2 -> V_5 = F_41 ( V_44 , L_4 ) ;
if ( V_2 -> V_5 < 0 ) {
if ( V_2 -> V_5 != - V_57 )
F_40 ( V_46 , L_5 ) ;
return V_2 -> V_5 ;
}
V_9 = F_42 ( V_46 , V_2 -> V_5 , F_6 ,
0 , L_6 , V_2 ) ;
if ( V_9 ) {
if ( V_9 != - V_57 )
F_40 ( V_46 , L_7 ) ;
return V_9 ;
}
V_2 -> V_41 = F_43 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_58 )
V_2 -> V_40 |= V_59 ;
if ( V_2 -> V_41 & V_59 )
V_2 -> V_40 |= V_58 ;
if ( V_2 -> V_41 & V_60 )
V_2 -> V_40 |= V_61 ;
if ( V_2 -> V_41 & V_61 )
V_2 -> V_40 |= V_60 ;
V_9 = F_44 ( V_2 -> V_15 , & type ) ;
if ( V_9 < 0 )
return V_9 ;
if ( type != V_62 ) {
F_40 ( V_46 , L_8 ) ;
return - V_34 ;
}
V_9 = F_45 ( V_2 -> V_15 , & V_2 -> V_16 ) ;
if ( V_9 < 0 ) {
F_40 ( V_46 , L_9 ) ;
return V_9 ;
}
return F_46 ( V_46 , V_23 ) ;
}
