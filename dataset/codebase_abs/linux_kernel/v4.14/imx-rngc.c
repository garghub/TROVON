static inline void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_3 |= V_7 | V_8 ;
F_3 ( V_3 , V_2 -> V_5 + V_6 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_4 |= V_10 | V_11 ;
F_3 ( V_4 , V_2 -> V_5 + V_9 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
V_3 &= ~ ( V_7 | V_8 ) ;
F_3 ( V_3 , V_2 -> V_5 + V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_12 ;
F_4 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_9 ) ;
F_3 ( V_4 | V_13 , V_2 -> V_5 + V_9 ) ;
V_12 = F_6 ( & V_2 -> V_14 , V_15 ) ;
if ( ! V_12 ) {
F_1 ( V_2 ) ;
return - V_16 ;
}
if ( V_2 -> V_17 != 0 )
return - V_18 ;
return 0 ;
}
static int F_7 ( struct V_19 * V_20 , void * V_21 , T_2 V_22 , bool V_23 )
{
struct V_1 * V_2 = F_8 ( V_20 , struct V_1 , V_20 ) ;
unsigned int V_24 ;
unsigned int V_25 ;
int V_26 = 0 ;
while ( V_22 >= sizeof( T_1 ) ) {
V_24 = F_2 ( V_2 -> V_5 + V_27 ) ;
if ( V_24 & V_28 )
break;
V_25 = ( V_24 & V_29 ) >>
V_30 ;
if ( V_25 ) {
* ( T_1 * ) V_21 = F_2 ( V_2 -> V_5 + V_31 ) ;
V_26 += sizeof( T_1 ) ;
V_21 += sizeof( T_1 ) ;
V_22 -= sizeof( T_1 ) ;
}
}
return V_26 ? V_26 : - V_18 ;
}
static T_3 F_9 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
T_1 V_24 ;
V_24 = F_2 ( V_2 -> V_5 + V_27 ) ;
V_2 -> V_17 = F_2 ( V_2 -> V_5 + V_34 ) ;
F_1 ( V_2 ) ;
if ( V_24 & ( V_35 | V_36 ) )
F_10 ( & V_2 -> V_14 ) ;
return V_37 ;
}
static int F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 , struct V_1 , V_20 ) ;
T_1 V_4 ;
int V_12 ;
V_4 = F_2 ( V_2 -> V_5 + V_9 ) ;
F_3 ( V_4 | V_11 , V_2 -> V_5 + V_9 ) ;
do {
F_4 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_9 ) ;
F_3 ( V_4 | V_38 , V_2 -> V_5 + V_9 ) ;
V_12 = F_6 ( & V_2 -> V_14 ,
V_15 ) ;
if ( ! V_12 ) {
F_1 ( V_2 ) ;
return - V_16 ;
}
} while ( V_2 -> V_17 == V_39 );
return V_2 -> V_17 ? - V_18 : 0 ;
}
static int F_12 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int V_12 ;
int V_32 ;
V_2 = F_13 ( & V_41 -> V_44 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_43 = F_14 ( V_41 , V_47 , 0 ) ;
V_2 -> V_5 = F_15 ( & V_41 -> V_44 , V_43 ) ;
if ( F_16 ( V_2 -> V_5 ) )
return F_17 ( V_2 -> V_5 ) ;
V_2 -> V_48 = F_18 ( & V_41 -> V_44 , NULL ) ;
if ( F_16 ( V_2 -> V_48 ) ) {
F_19 ( & V_41 -> V_44 , L_1 ) ;
return F_17 ( V_2 -> V_48 ) ;
}
V_32 = F_20 ( V_41 , 0 ) ;
if ( V_32 <= 0 ) {
F_19 ( & V_41 -> V_44 , L_2 , V_32 ) ;
return V_32 ;
}
V_12 = F_21 ( V_2 -> V_48 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_22 ( & V_41 -> V_44 ,
V_32 , F_9 , 0 , V_41 -> V_49 , ( void * ) V_2 ) ;
if ( V_12 ) {
F_19 ( V_2 -> V_44 , L_3 ) ;
goto V_50;
}
F_23 ( & V_2 -> V_14 ) ;
V_2 -> V_20 . V_49 = V_41 -> V_49 ;
V_2 -> V_20 . V_51 = F_11 ;
V_2 -> V_20 . V_52 = F_7 ;
V_2 -> V_44 = & V_41 -> V_44 ;
F_24 ( V_41 , V_2 ) ;
F_1 ( V_2 ) ;
if ( V_53 ) {
V_12 = F_5 ( V_2 ) ;
if ( V_12 ) {
F_19 ( V_2 -> V_44 , L_4 ) ;
goto V_50;
}
}
V_12 = F_25 ( & V_2 -> V_20 ) ;
if ( V_12 ) {
F_19 ( & V_41 -> V_44 , L_5 , V_12 ) ;
goto V_50;
}
F_26 ( & V_41 -> V_44 , L_6 ) ;
return 0 ;
V_50:
F_27 ( V_2 -> V_48 ) ;
return V_12 ;
}
static int T_4 F_28 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_29 ( V_41 ) ;
F_30 ( & V_2 -> V_20 ) ;
F_27 ( V_2 -> V_48 ) ;
return 0 ;
}
static int F_31 ( struct V_54 * V_44 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
F_27 ( V_2 -> V_48 ) ;
return 0 ;
}
static int F_33 ( struct V_54 * V_44 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
F_21 ( V_2 -> V_48 ) ;
return 0 ;
}
