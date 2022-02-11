static T_1 F_1 ( void T_2 * V_1 ,
bool V_2 )
{
if ( V_2 )
return F_2 ( V_1 ) ;
else
return F_3 ( V_1 ) ;
}
static void F_4 ( T_1 V_3 ,
void T_2 * V_1 ,
bool V_2 )
{
if ( V_2 )
F_5 ( V_3 , V_1 ) ;
else
F_6 ( V_3 , V_1 ) ;
}
static int F_7 ( struct V_4 * V_5 ,
struct V_6 T_2 * V_1 ,
bool V_2 )
{
unsigned int V_7 ;
V_7 = V_8 ;
while ( ( F_1 ( & V_1 -> V_9 , V_2 ) &
V_10 ) && V_7 ) {
F_8 () ;
V_7 -- ;
}
if ( ! V_7 ) {
F_9 ( V_5 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_5 ,
struct V_6 T_2 * V_1 ,
bool V_2 )
{
unsigned int V_7 ;
V_7 = V_8 ;
while ( ( F_1 ( & V_1 -> V_9 , V_2 ) &
V_10 ) && V_7 ) {
F_8 () ;
V_7 -- ;
}
if ( ! V_7 ) {
F_9 ( V_5 , L_2 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , int V_14 , int V_15 , T_3 V_3 )
{
struct V_16 * V_17 = (struct V_16 * ) V_13 -> V_17 ;
struct V_6 T_2 * V_1 = V_17 -> V_18 ;
T_4 V_19 ;
T_1 V_20 , V_9 ;
int V_21 ;
bool V_22 = V_17 -> V_2 ;
V_9 = F_1 ( & V_1 -> V_9 , V_22 ) ;
if ( V_15 & V_23 ) {
V_19 = ( V_15 >> 16 ) & 0x1f ;
V_9 |= V_24 ;
} else {
V_19 = V_15 & 0x1f ;
V_9 &= ~ V_24 ;
}
F_4 ( V_9 , & V_1 -> V_9 , V_22 ) ;
V_21 = F_7 ( & V_13 -> V_5 , V_1 , V_22 ) ;
if ( V_21 )
return V_21 ;
V_20 = F_12 ( V_14 ) | F_13 ( V_19 ) ;
F_4 ( V_20 , & V_1 -> V_20 , V_22 ) ;
if ( V_15 & V_23 ) {
F_4 ( V_15 & 0xffff , & V_1 -> V_25 , V_22 ) ;
V_21 = F_7 ( & V_13 -> V_5 , V_1 , V_22 ) ;
if ( V_21 )
return V_21 ;
}
F_4 ( F_14 ( V_3 ) , & V_1 -> V_26 , V_22 ) ;
V_21 = F_10 ( & V_13 -> V_5 , V_1 , V_22 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 , int V_14 , int V_15 )
{
struct V_16 * V_17 = (struct V_16 * ) V_13 -> V_17 ;
struct V_6 T_2 * V_1 = V_17 -> V_18 ;
T_4 V_19 ;
T_5 V_9 ;
T_5 V_20 ;
T_4 V_3 ;
int V_21 ;
bool V_22 = V_17 -> V_2 ;
V_9 = F_1 ( & V_1 -> V_9 , V_22 ) ;
if ( V_15 & V_23 ) {
V_19 = ( V_15 >> 16 ) & 0x1f ;
V_9 |= V_24 ;
} else {
V_19 = V_15 & 0x1f ;
V_9 &= ~ V_24 ;
}
F_4 ( V_9 , & V_1 -> V_9 , V_22 ) ;
V_21 = F_7 ( & V_13 -> V_5 , V_1 , V_22 ) ;
if ( V_21 )
return V_21 ;
V_20 = F_12 ( V_14 ) | F_13 ( V_19 ) ;
F_4 ( V_20 , & V_1 -> V_20 , V_22 ) ;
if ( V_15 & V_23 ) {
F_4 ( V_15 & 0xffff , & V_1 -> V_25 , V_22 ) ;
V_21 = F_7 ( & V_13 -> V_5 , V_1 , V_22 ) ;
if ( V_21 )
return V_21 ;
}
F_4 ( V_20 | V_27 , & V_1 -> V_20 , V_22 ) ;
V_21 = F_10 ( & V_13 -> V_5 , V_1 , V_22 ) ;
if ( V_21 )
return V_21 ;
if ( F_1 ( & V_1 -> V_9 , V_22 ) & V_28 ) {
F_9 ( & V_13 -> V_5 ,
L_3 ,
V_14 , V_19 , V_15 ) ;
return 0xffff ;
}
V_3 = F_1 ( & V_1 -> V_26 , V_22 ) & 0xffff ;
F_16 ( & V_13 -> V_5 , L_4 , V_3 ) ;
return V_3 ;
}
static int F_17 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_5 . V_33 ;
struct V_12 * V_13 ;
struct V_34 V_35 ;
struct V_16 * V_17 ;
int V_21 ;
V_21 = F_18 ( V_32 , 0 , & V_35 ) ;
if ( V_21 ) {
F_9 ( & V_30 -> V_5 , L_5 ) ;
return V_21 ;
}
V_13 = F_19 ( sizeof( struct V_16 ) ) ;
if ( ! V_13 )
return - V_36 ;
V_13 -> V_37 = L_6 ;
V_13 -> V_38 = F_15 ;
V_13 -> V_39 = F_11 ;
V_13 -> V_40 = & V_30 -> V_5 ;
snprintf ( V_13 -> V_41 , V_42 , L_7 , ( unsigned long long ) V_35 . V_43 ) ;
V_17 = V_13 -> V_17 ;
V_17 -> V_18 = F_20 ( V_32 , 0 ) ;
if ( ! V_17 -> V_18 ) {
V_21 = - V_36 ;
goto V_44;
}
if ( F_21 ( V_30 -> V_5 . V_33 ,
L_8 , NULL ) )
V_17 -> V_2 = true ;
else
V_17 -> V_2 = false ;
V_21 = F_22 ( V_13 , V_32 ) ;
if ( V_21 ) {
F_9 ( & V_30 -> V_5 , L_9 ) ;
goto V_45;
}
F_23 ( V_30 , V_13 ) ;
return 0 ;
V_45:
F_24 ( V_17 -> V_18 ) ;
V_44:
F_25 ( V_13 ) ;
return V_21 ;
}
static int F_26 ( struct V_29 * V_30 )
{
struct V_12 * V_13 = F_27 ( V_30 ) ;
F_28 ( V_13 ) ;
F_24 ( V_13 -> V_17 ) ;
F_25 ( V_13 ) ;
return 0 ;
}
