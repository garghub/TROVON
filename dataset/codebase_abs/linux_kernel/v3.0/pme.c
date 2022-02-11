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
F_10 ( V_4 ) ;
F_11 ( & V_4 -> V_4 ) ;
V_12 = true ;
}
if ( V_4 -> V_13 && F_6 ( V_4 -> V_13 ) )
V_12 = true ;
}
return V_12 ;
}
static bool F_12 ( struct V_10 * V_11 , T_3 V_14 )
{
struct V_3 * V_4 ;
bool V_15 = false ;
if ( V_14 )
return false ;
V_4 = F_13 ( V_11 -> V_16 ) ;
if ( ! V_4 )
return false ;
if ( F_8 ( V_4 ) && V_4 -> V_17 == V_18 ) {
F_14 ( & V_19 ) ;
if ( F_6 ( V_11 ) )
V_15 = true ;
F_15 ( & V_19 ) ;
}
F_16 ( V_4 ) ;
return V_15 ;
}
static void F_17 ( struct V_3 * V_20 , T_2 V_21 )
{
T_3 V_22 = V_21 >> 8 , V_14 = V_21 & 0xff ;
struct V_10 * V_11 ;
struct V_3 * V_4 ;
bool V_15 = false ;
if ( V_20 -> V_14 == V_14 && V_20 -> V_11 -> V_23 == V_22 ) {
if ( F_9 ( V_20 ) ) {
F_11 ( & V_20 -> V_4 ) ;
V_15 = true ;
} else {
F_14 ( & V_19 ) ;
V_15 = F_6 ( V_20 -> V_13 ) ;
F_15 ( & V_19 ) ;
}
goto V_24;
}
V_11 = F_18 ( F_19 ( V_20 -> V_11 ) , V_22 ) ;
if ( ! V_11 )
goto V_24;
V_15 = F_12 ( V_11 , V_14 ) ;
if ( V_15 )
goto V_24;
F_14 ( & V_19 ) ;
F_7 (dev, &bus->devices, bus_list) {
F_13 ( V_4 ) ;
if ( V_4 -> V_14 == V_14 ) {
V_15 = true ;
break;
}
F_16 ( V_4 ) ;
}
F_15 ( & V_19 ) ;
if ( V_15 ) {
V_15 = F_9 ( V_4 ) ;
if ( V_15 ) {
F_10 ( V_4 ) ;
F_11 ( & V_4 -> V_4 ) ;
}
F_16 ( V_4 ) ;
} else if ( V_14 ) {
F_20 ( & V_20 -> V_4 , L_2
L_3 ,
V_22 , F_21 ( V_14 ) , F_22 ( V_14 ) ) ;
V_15 = F_12 ( V_11 , 0 ) ;
}
V_24:
if ( ! V_15 )
F_20 ( & V_20 -> V_4 , L_4 ) ;
}
static void F_23 ( struct V_25 * V_26 )
{
struct V_27 * V_28 =
F_24 ( V_26 , struct V_27 , V_26 ) ;
struct V_3 * V_20 = V_28 -> V_29 -> V_20 ;
int V_30 ;
T_4 V_31 ;
V_30 = F_3 ( V_20 ) + V_32 ;
F_25 ( & V_28 -> V_33 ) ;
for (; ; ) {
if ( V_28 -> V_34 )
break;
F_26 ( V_20 , V_30 , & V_31 ) ;
if ( V_31 & V_35 ) {
F_27 ( V_20 ) ;
F_28 ( & V_28 -> V_33 ) ;
F_17 ( V_20 , V_31 & 0xffff ) ;
F_25 ( & V_28 -> V_33 ) ;
continue;
}
if ( ! ( V_31 & V_36 ) )
break;
F_28 ( & V_28 -> V_33 ) ;
F_29 () ;
F_25 ( & V_28 -> V_33 ) ;
}
if ( ! V_28 -> V_34 )
F_2 ( V_20 , true ) ;
F_28 ( & V_28 -> V_33 ) ;
}
static T_5 F_30 ( int V_37 , void * V_38 )
{
struct V_3 * V_20 ;
struct V_27 * V_28 ;
int V_30 ;
T_4 V_31 ;
unsigned long V_39 ;
V_20 = ( (struct V_40 * ) V_38 ) -> V_20 ;
V_28 = F_31 ( (struct V_40 * ) V_38 ) ;
V_30 = F_3 ( V_20 ) + V_32 ;
F_32 ( & V_28 -> V_33 , V_39 ) ;
F_26 ( V_20 , V_30 , & V_31 ) ;
if ( ! ( V_31 & V_35 ) ) {
F_33 ( & V_28 -> V_33 , V_39 ) ;
return V_41 ;
}
F_2 ( V_20 , false ) ;
F_33 ( & V_28 -> V_33 , V_39 ) ;
F_34 ( & V_28 -> V_26 ) ;
return V_42 ;
}
static int F_35 ( struct V_3 * V_4 , void * V_43 )
{
F_36 ( & V_4 -> V_4 , L_5 ) ;
F_37 ( & V_4 -> V_4 , true ) ;
V_4 -> V_44 = true ;
return 0 ;
}
static void F_38 ( struct V_3 * V_20 )
{
F_35 ( V_20 , NULL ) ;
if ( V_20 -> V_13 ) {
F_39 ( V_20 -> V_13 , F_35 , NULL ) ;
} else {
struct V_10 * V_11 = V_20 -> V_11 ;
struct V_3 * V_4 ;
if ( V_20 -> V_17 != V_45 || ! V_11 )
return;
F_14 ( & V_19 ) ;
F_7 (dev, &bus->devices, bus_list)
if ( F_8 ( V_4 )
&& V_4 -> V_17 == V_46 )
F_35 ( V_4 , NULL ) ;
F_15 ( & V_19 ) ;
}
}
static int F_40 ( struct V_40 * V_29 )
{
struct V_3 * V_20 ;
struct V_27 * V_28 ;
int V_12 ;
V_28 = F_41 ( sizeof( * V_28 ) , V_47 ) ;
if ( ! V_28 )
return - V_48 ;
F_42 ( & V_28 -> V_33 ) ;
F_43 ( & V_28 -> V_26 , F_23 ) ;
V_28 -> V_29 = V_29 ;
F_44 ( V_29 , V_28 ) ;
V_20 = V_29 -> V_20 ;
F_2 ( V_20 , false ) ;
F_27 ( V_20 ) ;
V_12 = F_45 ( V_29 -> V_37 , F_30 , V_49 , L_6 , V_29 ) ;
if ( V_12 ) {
F_46 ( V_28 ) ;
} else {
F_38 ( V_20 ) ;
F_2 ( V_20 , true ) ;
}
return V_12 ;
}
static int F_47 ( struct V_40 * V_29 )
{
struct V_27 * V_28 = F_31 ( V_29 ) ;
struct V_3 * V_20 = V_29 -> V_20 ;
F_25 ( & V_28 -> V_33 ) ;
F_2 ( V_20 , false ) ;
F_27 ( V_20 ) ;
V_28 -> V_34 = true ;
F_28 ( & V_28 -> V_33 ) ;
F_48 ( V_29 -> V_37 ) ;
return 0 ;
}
static int F_49 ( struct V_40 * V_29 )
{
struct V_27 * V_28 = F_31 ( V_29 ) ;
struct V_3 * V_20 = V_29 -> V_20 ;
F_25 ( & V_28 -> V_33 ) ;
V_28 -> V_34 = false ;
F_27 ( V_20 ) ;
F_2 ( V_20 , true ) ;
F_28 ( & V_28 -> V_33 ) ;
return 0 ;
}
static void F_50 ( struct V_40 * V_29 )
{
F_47 ( V_29 ) ;
F_51 ( V_29 -> V_37 , V_29 ) ;
F_46 ( F_31 ( V_29 ) ) ;
}
static int T_1 F_52 ( void )
{
return F_53 ( & V_50 ) ;
}
