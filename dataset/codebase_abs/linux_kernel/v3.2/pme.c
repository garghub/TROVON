static int T_1 F_1 ( char * V_1 )
{
if ( ! strncmp ( V_1 , L_1 , 5 ) )
V_2 = true ;
return 1 ;
}
void F_2 ( struct V_3 * V_4 , bool V_5 )
{
int V_6 ;
T_2 V_7 ;
V_6 = F_3 ( V_4 ) + V_8 ;
F_4 ( V_4 , V_6 , & V_7 ) ;
if ( V_5 )
V_7 |= V_9 ;
else
V_7 &= ~ V_9 ;
F_5 ( V_4 , V_6 , V_7 ) ;
}
static bool F_6 ( struct V_10 * V_11 )
{
struct V_3 * V_4 ;
bool V_12 = false ;
F_7 (dev, &bus->devices, bus_list) {
if ( ! F_8 ( V_4 ) && F_9 ( V_4 ) ) {
if ( V_4 -> V_13 )
V_4 -> V_13 = false ;
F_10 ( V_4 ) ;
F_11 ( & V_4 -> V_4 ) ;
V_12 = true ;
}
if ( V_4 -> V_14 && F_6 ( V_4 -> V_14 ) )
V_12 = true ;
}
return V_12 ;
}
static bool F_12 ( struct V_10 * V_11 , T_3 V_15 )
{
struct V_3 * V_4 ;
bool V_16 = false ;
if ( V_15 )
return false ;
V_4 = F_13 ( V_11 -> V_17 ) ;
if ( ! V_4 )
return false ;
if ( F_8 ( V_4 ) && V_4 -> V_18 == V_19 ) {
F_14 ( & V_20 ) ;
if ( F_6 ( V_11 ) )
V_16 = true ;
F_15 ( & V_20 ) ;
}
F_16 ( V_4 ) ;
return V_16 ;
}
static void F_17 ( struct V_3 * V_21 , T_2 V_22 )
{
T_3 V_23 = V_22 >> 8 , V_15 = V_22 & 0xff ;
struct V_10 * V_11 ;
struct V_3 * V_4 ;
bool V_16 = false ;
if ( V_21 -> V_15 == V_15 && V_21 -> V_11 -> V_24 == V_23 ) {
if ( V_21 -> V_13 )
V_21 -> V_13 = false ;
if ( F_9 ( V_21 ) ) {
F_11 ( & V_21 -> V_4 ) ;
V_16 = true ;
} else {
F_14 ( & V_20 ) ;
V_16 = F_6 ( V_21 -> V_14 ) ;
F_15 ( & V_20 ) ;
}
goto V_25;
}
V_11 = F_18 ( F_19 ( V_21 -> V_11 ) , V_23 ) ;
if ( ! V_11 )
goto V_25;
V_16 = F_12 ( V_11 , V_15 ) ;
if ( V_16 )
goto V_25;
F_14 ( & V_20 ) ;
F_7 (dev, &bus->devices, bus_list) {
F_13 ( V_4 ) ;
if ( V_4 -> V_15 == V_15 ) {
V_16 = true ;
break;
}
F_16 ( V_4 ) ;
}
F_15 ( & V_20 ) ;
if ( V_16 ) {
V_16 = F_9 ( V_4 ) ;
if ( V_16 ) {
if ( V_4 -> V_13 )
V_4 -> V_13 = false ;
F_10 ( V_4 ) ;
F_11 ( & V_4 -> V_4 ) ;
}
F_16 ( V_4 ) ;
} else if ( V_15 ) {
F_20 ( & V_21 -> V_4 , L_2
L_3 ,
V_23 , F_21 ( V_15 ) , F_22 ( V_15 ) ) ;
V_16 = F_12 ( V_11 , 0 ) ;
}
V_25:
if ( ! V_16 )
F_20 ( & V_21 -> V_4 , L_4 ) ;
}
static void F_23 ( struct V_26 * V_27 )
{
struct V_28 * V_29 =
F_24 ( V_27 , struct V_28 , V_27 ) ;
struct V_3 * V_21 = V_29 -> V_30 -> V_21 ;
int V_31 ;
T_4 V_32 ;
V_31 = F_3 ( V_21 ) + V_33 ;
F_25 ( & V_29 -> V_34 ) ;
for (; ; ) {
if ( V_29 -> V_35 )
break;
F_26 ( V_21 , V_31 , & V_32 ) ;
if ( V_32 & V_36 ) {
F_27 ( V_21 ) ;
F_28 ( & V_29 -> V_34 ) ;
F_17 ( V_21 , V_32 & 0xffff ) ;
F_25 ( & V_29 -> V_34 ) ;
continue;
}
if ( ! ( V_32 & V_37 ) )
break;
F_28 ( & V_29 -> V_34 ) ;
F_29 () ;
F_25 ( & V_29 -> V_34 ) ;
}
if ( ! V_29 -> V_35 )
F_2 ( V_21 , true ) ;
F_28 ( & V_29 -> V_34 ) ;
}
static T_5 F_30 ( int V_38 , void * V_39 )
{
struct V_3 * V_21 ;
struct V_28 * V_29 ;
int V_31 ;
T_4 V_32 ;
unsigned long V_40 ;
V_21 = ( (struct V_41 * ) V_39 ) -> V_21 ;
V_29 = F_31 ( (struct V_41 * ) V_39 ) ;
V_31 = F_3 ( V_21 ) + V_33 ;
F_32 ( & V_29 -> V_34 , V_40 ) ;
F_26 ( V_21 , V_31 , & V_32 ) ;
if ( ! ( V_32 & V_36 ) ) {
F_33 ( & V_29 -> V_34 , V_40 ) ;
return V_42 ;
}
F_2 ( V_21 , false ) ;
F_33 ( & V_29 -> V_34 , V_40 ) ;
F_34 ( & V_29 -> V_27 ) ;
return V_43 ;
}
static int F_35 ( struct V_3 * V_4 , void * V_44 )
{
F_36 ( & V_4 -> V_4 , L_5 ) ;
F_37 ( & V_4 -> V_4 , true ) ;
V_4 -> V_45 = true ;
return 0 ;
}
static void F_38 ( struct V_3 * V_21 )
{
F_35 ( V_21 , NULL ) ;
if ( V_21 -> V_14 ) {
F_39 ( V_21 -> V_14 , F_35 , NULL ) ;
} else {
struct V_10 * V_11 = V_21 -> V_11 ;
struct V_3 * V_4 ;
if ( V_21 -> V_18 != V_46 || ! V_11 )
return;
F_14 ( & V_20 ) ;
F_7 (dev, &bus->devices, bus_list)
if ( F_8 ( V_4 )
&& V_4 -> V_18 == V_47 )
F_35 ( V_4 , NULL ) ;
F_15 ( & V_20 ) ;
}
}
static int F_40 ( struct V_41 * V_30 )
{
struct V_3 * V_21 ;
struct V_28 * V_29 ;
int V_12 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_48 ) ;
if ( ! V_29 )
return - V_49 ;
F_42 ( & V_29 -> V_34 ) ;
F_43 ( & V_29 -> V_27 , F_23 ) ;
V_29 -> V_30 = V_30 ;
F_44 ( V_30 , V_29 ) ;
V_21 = V_30 -> V_21 ;
F_2 ( V_21 , false ) ;
F_27 ( V_21 ) ;
V_12 = F_45 ( V_30 -> V_38 , F_30 , V_50 , L_6 , V_30 ) ;
if ( V_12 ) {
F_46 ( V_29 ) ;
} else {
F_38 ( V_21 ) ;
F_2 ( V_21 , true ) ;
}
return V_12 ;
}
static int F_47 ( struct V_41 * V_30 )
{
struct V_28 * V_29 = F_31 ( V_30 ) ;
struct V_3 * V_21 = V_30 -> V_21 ;
F_25 ( & V_29 -> V_34 ) ;
F_2 ( V_21 , false ) ;
F_27 ( V_21 ) ;
V_29 -> V_35 = true ;
F_28 ( & V_29 -> V_34 ) ;
F_48 ( V_30 -> V_38 ) ;
return 0 ;
}
static int F_49 ( struct V_41 * V_30 )
{
struct V_28 * V_29 = F_31 ( V_30 ) ;
struct V_3 * V_21 = V_30 -> V_21 ;
F_25 ( & V_29 -> V_34 ) ;
V_29 -> V_35 = false ;
F_27 ( V_21 ) ;
F_2 ( V_21 , true ) ;
F_28 ( & V_29 -> V_34 ) ;
return 0 ;
}
static void F_50 ( struct V_41 * V_30 )
{
F_47 ( V_30 ) ;
F_51 ( V_30 -> V_38 , V_30 ) ;
F_46 ( F_31 ( V_30 ) ) ;
}
static int T_1 F_52 ( void )
{
return F_53 ( & V_51 ) ;
}
