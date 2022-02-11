static int T_1 F_1 ( char * V_1 )
{
if ( ! strncmp ( V_1 , L_1 , 5 ) )
V_2 = true ;
return 1 ;
}
void F_2 ( struct V_3 * V_4 , bool V_5 )
{
if ( V_5 )
F_3 ( V_4 , V_6 ,
V_7 ) ;
else
F_4 ( V_4 , V_6 ,
V_7 ) ;
}
static bool F_5 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
bool V_10 = false ;
F_6 (dev, &bus->devices, bus_list) {
if ( ! F_7 ( V_4 ) && F_8 ( V_4 ) ) {
if ( V_4 -> V_11 )
V_4 -> V_11 = false ;
F_9 ( V_4 ) ;
F_10 ( & V_4 -> V_4 ) ;
V_10 = true ;
}
if ( V_4 -> V_12 && F_5 ( V_4 -> V_12 ) )
V_10 = true ;
}
return V_10 ;
}
static bool F_11 ( struct V_8 * V_9 , T_2 V_13 )
{
struct V_3 * V_4 ;
bool V_14 = false ;
if ( V_13 )
return false ;
V_4 = F_12 ( V_9 -> V_15 ) ;
if ( ! V_4 )
return false ;
if ( F_7 ( V_4 ) && F_13 ( V_4 ) == V_16 ) {
F_14 ( & V_17 ) ;
if ( F_5 ( V_9 ) )
V_14 = true ;
F_15 ( & V_17 ) ;
}
F_16 ( V_4 ) ;
return V_14 ;
}
static void F_17 ( struct V_3 * V_18 , T_3 V_19 )
{
T_2 V_20 = V_19 >> 8 , V_13 = V_19 & 0xff ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
bool V_14 = false ;
if ( V_18 -> V_13 == V_13 && V_18 -> V_9 -> V_21 == V_20 ) {
if ( V_18 -> V_11 )
V_18 -> V_11 = false ;
if ( F_8 ( V_18 ) ) {
F_10 ( & V_18 -> V_4 ) ;
V_14 = true ;
} else {
F_14 ( & V_17 ) ;
V_14 = F_5 ( V_18 -> V_12 ) ;
F_15 ( & V_17 ) ;
}
goto V_22;
}
V_9 = F_18 ( F_19 ( V_18 -> V_9 ) , V_20 ) ;
if ( ! V_9 )
goto V_22;
V_14 = F_11 ( V_9 , V_13 ) ;
if ( V_14 )
goto V_22;
F_14 ( & V_17 ) ;
F_6 (dev, &bus->devices, bus_list) {
F_12 ( V_4 ) ;
if ( V_4 -> V_13 == V_13 ) {
V_14 = true ;
break;
}
F_16 ( V_4 ) ;
}
F_15 ( & V_17 ) ;
if ( V_14 ) {
V_14 = F_8 ( V_4 ) ;
if ( V_14 ) {
if ( V_4 -> V_11 )
V_4 -> V_11 = false ;
F_9 ( V_4 ) ;
F_10 ( & V_4 -> V_4 ) ;
}
F_16 ( V_4 ) ;
} else if ( V_13 ) {
F_20 ( & V_18 -> V_4 , L_2 ,
V_20 , F_21 ( V_13 ) , F_22 ( V_13 ) ) ;
V_14 = F_11 ( V_9 , 0 ) ;
}
V_22:
if ( ! V_14 )
F_20 ( & V_18 -> V_4 , L_3 ) ;
}
static void F_23 ( struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_24 ( V_24 , struct V_25 , V_24 ) ;
struct V_3 * V_18 = V_26 -> V_27 -> V_18 ;
T_4 V_28 ;
F_25 ( & V_26 -> V_29 ) ;
for (; ; ) {
if ( V_26 -> V_30 != V_31 )
break;
F_26 ( V_18 , V_32 , & V_28 ) ;
if ( V_28 & V_33 ) {
F_27 ( V_18 ) ;
F_28 ( & V_26 -> V_29 ) ;
F_17 ( V_18 , V_28 & 0xffff ) ;
F_25 ( & V_26 -> V_29 ) ;
continue;
}
if ( ! ( V_28 & V_34 ) )
break;
F_28 ( & V_26 -> V_29 ) ;
F_29 () ;
F_25 ( & V_26 -> V_29 ) ;
}
if ( V_26 -> V_30 == V_31 )
F_2 ( V_18 , true ) ;
F_28 ( & V_26 -> V_29 ) ;
}
static T_5 F_30 ( int V_35 , void * V_36 )
{
struct V_3 * V_18 ;
struct V_25 * V_26 ;
T_4 V_28 ;
unsigned long V_37 ;
V_18 = ( (struct V_38 * ) V_36 ) -> V_18 ;
V_26 = F_31 ( (struct V_38 * ) V_36 ) ;
F_32 ( & V_26 -> V_29 , V_37 ) ;
F_26 ( V_18 , V_32 , & V_28 ) ;
if ( ! ( V_28 & V_33 ) ) {
F_33 ( & V_26 -> V_29 , V_37 ) ;
return V_39 ;
}
F_2 ( V_18 , false ) ;
F_33 ( & V_26 -> V_29 , V_37 ) ;
F_34 ( & V_26 -> V_24 ) ;
return V_40 ;
}
static int F_35 ( struct V_3 * V_4 , void * V_41 )
{
F_36 ( & V_4 -> V_4 , L_4 ) ;
F_37 ( & V_4 -> V_4 , true ) ;
V_4 -> V_42 = true ;
return 0 ;
}
static void F_38 ( struct V_3 * V_18 )
{
F_35 ( V_18 , NULL ) ;
if ( V_18 -> V_12 ) {
F_39 ( V_18 -> V_12 , F_35 , NULL ) ;
} else {
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_3 * V_4 ;
if ( F_13 ( V_18 ) != V_43 || ! V_9 )
return;
F_14 ( & V_17 ) ;
F_6 (dev, &bus->devices, bus_list)
if ( F_7 ( V_4 )
&& F_13 ( V_4 ) == V_44 )
F_35 ( V_4 , NULL ) ;
F_15 ( & V_17 ) ;
}
}
static int F_40 ( struct V_38 * V_27 )
{
struct V_3 * V_18 ;
struct V_25 * V_26 ;
int V_10 ;
V_26 = F_41 ( sizeof( * V_26 ) , V_45 ) ;
if ( ! V_26 )
return - V_46 ;
F_42 ( & V_26 -> V_29 ) ;
F_43 ( & V_26 -> V_24 , F_23 ) ;
V_26 -> V_27 = V_27 ;
F_44 ( V_27 , V_26 ) ;
V_18 = V_27 -> V_18 ;
F_2 ( V_18 , false ) ;
F_27 ( V_18 ) ;
V_10 = F_45 ( V_27 -> V_35 , F_30 , V_47 , L_5 , V_27 ) ;
if ( V_10 ) {
F_46 ( V_26 ) ;
} else {
F_38 ( V_18 ) ;
F_2 ( V_18 , true ) ;
}
return V_10 ;
}
static bool F_47 ( struct V_8 * V_9 )
{
struct V_3 * V_4 ;
if ( ! V_9 )
return false ;
F_6 (dev, &bus->devices, bus_list)
if ( F_48 ( & V_4 -> V_4 )
|| F_47 ( V_4 -> V_12 ) )
return true ;
return false ;
}
static int F_49 ( struct V_38 * V_27 )
{
struct V_25 * V_26 = F_31 ( V_27 ) ;
struct V_3 * V_18 = V_27 -> V_18 ;
bool V_48 ;
int V_10 ;
if ( F_48 ( & V_18 -> V_4 ) ) {
V_48 = true ;
} else {
F_14 ( & V_17 ) ;
V_48 = F_47 ( V_18 -> V_12 ) ;
F_15 ( & V_17 ) ;
}
F_25 ( & V_26 -> V_29 ) ;
if ( V_48 ) {
V_10 = F_50 ( V_27 -> V_35 ) ;
V_26 -> V_30 = V_49 ;
}
if ( ! V_48 || V_10 ) {
struct V_3 * V_18 = V_27 -> V_18 ;
F_2 ( V_18 , false ) ;
F_27 ( V_18 ) ;
V_26 -> V_30 = V_50 ;
}
F_28 ( & V_26 -> V_29 ) ;
F_51 ( V_27 -> V_35 ) ;
return 0 ;
}
static int F_52 ( struct V_38 * V_27 )
{
struct V_25 * V_26 = F_31 ( V_27 ) ;
F_25 ( & V_26 -> V_29 ) ;
if ( V_26 -> V_30 == V_50 ) {
struct V_3 * V_18 = V_27 -> V_18 ;
F_27 ( V_18 ) ;
F_2 ( V_18 , true ) ;
} else {
F_53 ( V_27 -> V_35 ) ;
}
V_26 -> V_30 = V_31 ;
F_28 ( & V_26 -> V_29 ) ;
return 0 ;
}
static void F_54 ( struct V_38 * V_27 )
{
F_49 ( V_27 ) ;
F_55 ( V_27 -> V_35 , V_27 ) ;
F_46 ( F_31 ( V_27 ) ) ;
}
static int T_1 F_56 ( void )
{
return F_57 ( & V_51 ) ;
}
