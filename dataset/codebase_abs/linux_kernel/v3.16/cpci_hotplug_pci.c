T_1 F_1 ( struct V_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
V_2 = F_2 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_6 ) ;
if ( ! V_2 )
return 0 ;
if ( F_3 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
& V_3 ) )
return 0 ;
return V_3 & 0x0008 ? 1 : 0 ;
}
int F_4 ( struct V_1 * V_1 , int V_7 )
{
int V_2 ;
T_2 V_3 ;
V_2 = F_2 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_6 ) ;
if ( ! V_2 )
return 0 ;
if ( F_3 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
& V_3 ) )
return 0 ;
if ( V_7 )
V_3 |= V_8 ;
else
V_3 &= ~ V_8 ;
if ( F_5 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
V_3 ) )
return 0 ;
return 1 ;
}
T_2 F_6 ( struct V_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
V_2 = F_2 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_6 ) ;
if ( ! V_2 )
return 0xFFFF ;
if ( F_3 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
& V_3 ) )
return 0xFFFF ;
return V_3 ;
}
int F_7 ( struct V_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
int V_9 = 0 ;
V_2 = F_2 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_6 ) ;
if ( ! V_2 )
return 0 ;
if ( F_3 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
& V_3 ) )
return 0 ;
if ( V_3 & V_10 ) {
if ( F_5 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
V_3 ) )
V_9 = 0 ;
else
V_9 = 1 ;
}
return V_9 ;
}
int F_8 ( struct V_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
int V_11 = 0 ;
V_2 = F_2 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_6 ) ;
if ( ! V_2 )
return 0 ;
if ( F_3 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
& V_3 ) )
return 0 ;
if ( V_3 & V_12 )
V_11 = 1 ;
return V_11 ;
}
int F_9 ( struct V_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
V_2 = F_2 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_6 ) ;
if ( ! V_2 )
return - V_13 ;
if ( F_3 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
& V_3 ) )
return - V_13 ;
if ( V_3 & V_12 ) {
if ( F_5 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
V_3 ) )
return - V_13 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
V_2 = F_2 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_6 ) ;
if ( ! V_2 )
return - V_13 ;
if ( F_3 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
& V_3 ) )
return - V_13 ;
if ( ( V_3 & V_8 ) != V_8 ) {
V_3 |= V_8 ;
if ( F_5 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
V_3 ) ) {
F_11 ( L_1 ,
F_12 ( V_1 -> V_14 ) ) ;
return - V_13 ;
}
}
return 0 ;
}
int F_13 ( struct V_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
V_2 = F_2 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_6 ) ;
if ( ! V_2 )
return - V_13 ;
if ( F_3 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
& V_3 ) )
return - V_13 ;
if ( V_3 & V_8 ) {
V_3 &= ~ V_8 ;
if ( F_5 ( V_1 -> V_4 ,
V_1 -> V_5 ,
V_2 + 2 ,
V_3 ) ) {
F_11 ( L_2 ,
F_12 ( V_1 -> V_14 ) ) ;
return - V_13 ;
}
}
return 0 ;
}
int F_14 ( struct V_1 * V_1 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 = 0 ;
F_15 ( L_3 , V_20 ) ;
F_16 () ;
if ( V_1 -> V_16 == NULL ) {
F_15 ( L_4 ,
V_1 -> V_4 -> V_21 , F_17 ( V_1 -> V_5 ) , F_18 ( V_1 -> V_5 ) ) ;
V_1 -> V_16 = F_19 ( V_1 -> V_4 , V_1 -> V_5 ) ;
}
if ( V_1 -> V_16 == NULL ) {
int V_22 ;
F_15 ( L_5 ) ;
V_22 = F_20 ( V_1 -> V_4 , V_1 -> V_5 ) ;
F_15 ( L_6 , V_20 , V_22 ) ;
V_1 -> V_16 = F_19 ( V_1 -> V_4 , V_1 -> V_5 ) ;
if ( V_1 -> V_16 == NULL ) {
F_11 ( L_7 , V_1 -> V_21 ) ;
V_19 = - V_13 ;
goto V_23;
}
}
V_18 = V_1 -> V_16 -> V_4 ;
F_21 (dev, &parent->devices, bus_list)
if ( F_17 ( V_16 -> V_5 ) != F_17 ( V_1 -> V_5 ) )
continue;
if ( F_22 ( V_16 ) )
F_23 ( V_16 ) ;
F_24 ( V_18 -> V_24 ) ;
F_25 ( V_18 ) ;
V_23:
F_26 () ;
F_15 ( L_8 , V_20 ) ;
return V_19 ;
}
int F_27 ( struct V_1 * V_1 )
{
struct V_15 * V_16 , * V_25 ;
F_15 ( L_3 , V_20 ) ;
if ( ! V_1 -> V_16 ) {
F_11 ( L_9 , V_1 -> V_21 ) ;
return - V_13 ;
}
F_16 () ;
F_28 (dev, temp, &slot->bus->devices, bus_list) {
if ( F_17 ( V_16 -> V_5 ) != F_17 ( V_1 -> V_5 ) )
continue;
F_29 ( V_16 ) ;
F_30 ( V_16 ) ;
F_31 ( V_16 ) ;
}
F_31 ( V_1 -> V_16 ) ;
V_1 -> V_16 = NULL ;
F_26 () ;
F_15 ( L_8 , V_20 ) ;
return 0 ;
}
