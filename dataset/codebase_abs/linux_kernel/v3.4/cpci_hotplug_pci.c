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
int T_3 F_14 ( struct V_1 * V_1 )
{
struct V_15 * V_16 ;
int V_17 ;
F_15 ( L_3 , V_18 ) ;
if ( V_1 -> V_19 == NULL ) {
F_15 ( L_4 ,
V_1 -> V_4 -> V_20 , F_16 ( V_1 -> V_5 ) , F_17 ( V_1 -> V_5 ) ) ;
V_1 -> V_19 = F_18 ( V_1 -> V_4 , V_1 -> V_5 ) ;
}
if ( V_1 -> V_19 == NULL ) {
int V_21 ;
F_15 ( L_5 ) ;
V_21 = F_19 ( V_1 -> V_4 , V_1 -> V_5 ) ;
F_15 ( L_6 , V_18 , V_21 ) ;
V_1 -> V_19 = F_18 ( V_1 -> V_4 , V_1 -> V_5 ) ;
if ( V_1 -> V_19 == NULL ) {
F_11 ( L_7 , V_1 -> V_20 ) ;
return - V_13 ;
}
}
V_16 = V_1 -> V_19 -> V_4 ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
struct V_22 * V_19 ;
V_19 = F_18 ( V_16 , F_20 ( F_16 ( V_1 -> V_5 ) , V_17 ) ) ;
if ( ! V_19 )
continue;
if ( ( V_19 -> V_23 == V_24 ) ||
( V_19 -> V_23 == V_25 ) ) {
struct V_15 * V_26 ;
unsigned char V_27 , V_28 = V_16 -> V_29 ;
unsigned char V_30 = V_16 -> V_31 ;
for ( V_27 = V_28 ; V_27 <= V_30 ; V_27 ++ ) {
if ( ! F_21 ( F_22 ( V_16 ) ,
V_27 ) )
break;
}
if ( V_27 >= V_30 ) {
F_11 ( L_8 ) ;
F_23 ( V_19 ) ;
continue;
}
V_26 = F_24 ( V_16 , V_19 , V_27 ) ;
if ( ! V_26 ) {
F_11 ( L_9 ,
F_25 ( V_19 ) ) ;
F_23 ( V_19 ) ;
continue;
}
V_26 -> V_31 = F_26 ( V_26 ) ;
F_27 ( V_26 ) ;
}
F_23 ( V_19 ) ;
}
F_28 ( V_16 ) ;
F_29 ( V_16 ) ;
F_30 ( V_16 ) ;
F_15 ( L_10 , V_18 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_1 )
{
int V_32 ;
struct V_22 * V_19 ;
F_15 ( L_3 , V_18 ) ;
if ( ! V_1 -> V_19 ) {
F_11 ( L_11 , V_1 -> V_20 ) ;
return - V_13 ;
}
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
V_19 = F_18 ( V_1 -> V_4 ,
F_20 ( F_16 ( V_1 -> V_5 ) , V_32 ) ) ;
if ( V_19 ) {
F_32 ( V_19 ) ;
F_23 ( V_19 ) ;
}
}
F_23 ( V_1 -> V_19 ) ;
V_1 -> V_19 = NULL ;
F_15 ( L_10 , V_18 ) ;
return 0 ;
}
