static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 , int V_6 )
{
T_1 V_7 ;
T_3 V_8 ;
if ( F_2 ( ( ( unsigned long ) V_4 & 3 ) && ( V_5 > 4 ) ) ) {
F_3 ( L_1 ) ;
return - V_9 ;
}
V_7 = F_4 ( V_3 ) ;
V_8 = F_5 ( V_6 , 0 , 0 , V_7 ) ;
return V_2 -> V_10 -> V_11 ( V_2 -> V_12 ,
V_8 ,
V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
const void * V_4 , T_2 V_5 , int V_6 )
{
T_1 V_7 ;
T_3 V_8 ;
V_7 = F_4 ( V_3 ) ;
V_8 = F_5 ( V_6 , 0 , 0 , V_7 ) ;
return V_2 -> V_10 -> V_13 ( V_2 -> V_12 ,
V_8 ,
V_4 , V_5 ) ;
}
static inline int F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_3 * V_14 )
{
T_4 V_15 ;
int V_16 = F_1 ( V_2 , V_3 , & V_15 , sizeof( V_15 ) , 0 ) ;
* V_14 = F_8 ( V_15 ) ;
return V_16 ;
}
static inline int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_3 V_14 )
{
T_4 V_15 = F_10 ( V_14 ) ;
return F_6 ( V_2 , V_3 , & V_15 , sizeof( V_15 ) , 0 ) ;
}
static inline int F_11 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_14 )
{
T_5 V_15 ;
int V_16 = F_1 ( V_2 , V_3 , & V_15 , sizeof( V_15 ) , 0 ) ;
* V_14 = F_12 ( V_15 ) ;
return V_16 ;
}
static inline int F_13 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_14 )
{
T_5 V_15 = F_14 ( V_14 ) ;
return F_6 ( V_2 , V_3 , & V_15 , sizeof( V_15 ) , 0 ) ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 ,
T_2 V_5 )
{
int V_17 ;
V_2 -> V_10 -> V_18 ( V_2 -> V_12 ) ;
V_17 = F_1 ( V_2 , V_3 , V_4 , V_5 , 0 ) ;
V_2 -> V_10 -> V_19 ( V_2 -> V_12 ) ;
return V_17 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 , const void * V_4 ,
T_2 V_5 )
{
int V_17 ;
V_2 -> V_10 -> V_18 ( V_2 -> V_12 ) ;
V_17 = F_6 ( V_2 , V_3 , V_4 , V_5 , 0 ) ;
V_2 -> V_10 -> V_19 ( V_2 -> V_12 ) ;
return V_17 ;
}
int F_17 ( struct V_1 * V_2 , void * V_4 , T_2 V_5 )
{
int V_17 , V_20 = 1 ;
int V_21 = V_2 -> V_21 ;
V_2 -> V_10 -> V_18 ( V_2 -> V_12 ) ;
while ( V_20 <= V_22 ) {
V_17 = F_1 ( V_2 ,
V_23 , V_4 ,
V_5 , V_21 + 1 ) ;
if ( ! V_17 ) {
V_21 = ( V_21 + 1 ) & 3 ;
V_2 -> V_21 = V_21 ;
break;
} else {
V_20 ++ ;
F_18 ( 1 ) ;
F_3 ( L_2 , V_17 ) ;
}
}
V_2 -> V_10 -> V_19 ( V_2 -> V_12 ) ;
return V_17 ;
}
int F_19 ( struct V_1 * V_2 , const void * V_4 ,
T_2 V_5 )
{
int V_17 , V_20 = 1 ;
int V_24 = V_2 -> V_24 ;
V_2 -> V_10 -> V_18 ( V_2 -> V_12 ) ;
while ( V_20 <= V_22 ) {
V_17 = F_6 ( V_2 ,
V_23 , V_4 ,
V_5 , V_24 ) ;
if ( ! V_17 ) {
V_24 = ( V_24 + 1 ) & 31 ;
V_2 -> V_24 = V_24 ;
break;
} else {
V_20 ++ ;
F_18 ( 1 ) ;
F_3 ( L_2 , V_17 ) ;
}
}
V_2 -> V_10 -> V_19 ( V_2 -> V_12 ) ;
return V_17 ;
}
int F_20 ( struct V_1 * V_2 , T_3 V_3 , void * V_4 ,
T_2 V_5 , T_3 V_25 , T_1 V_26 )
{
T_3 V_27 = 0 ;
int V_16 , V_17 ;
if ( ( V_5 / 2 ) >= 0x1000 ) {
F_3 ( L_3 ) ;
return - V_9 ;
}
V_2 -> V_10 -> V_18 ( V_2 -> V_12 ) ;
V_17 = F_9 ( V_2 , V_28 , V_3 ) ;
if ( V_17 < 0 ) {
F_3 ( L_4 ) ;
goto V_29;
}
V_17 = F_7 ( V_2 , V_30 , & V_27 ) ;
if ( V_17 < 0 ) {
F_3 ( L_5 ) ;
goto V_29;
}
V_17 = F_9 ( V_2 , V_30 ,
V_27 | V_25 ) ;
if ( V_17 < 0 ) {
F_3 ( L_6 ) ;
goto V_29;
}
for ( V_16 = 0 ; V_16 < 20 ; V_16 ++ ) {
V_17 = F_7 ( V_2 , V_30 , & V_27 ) ;
if ( V_17 < 0 ) {
F_3 ( L_7 ) ;
goto V_29;
}
if ( ! ( V_27 & V_25 ) )
break;
F_18 ( V_16 ) ;
}
if ( V_27 & V_25 ) {
F_3 ( L_8 ) ;
goto V_29;
}
V_17 = F_1 ( V_2 , V_26 , V_4 , V_5 , 0 ) ;
if ( V_17 < 0 ) {
F_3 ( L_9 ) ;
goto V_29;
}
V_29:
V_2 -> V_10 -> V_19 ( V_2 -> V_12 ) ;
return V_17 ;
}
int F_21 ( struct V_1 * V_2 , T_3 V_3 , const void * V_4 ,
T_2 V_5 )
{
int V_17 ;
if ( ( V_5 / 2 ) >= 0x1000 ) {
F_3 ( L_10 ) ;
return - V_9 ;
}
V_2 -> V_10 -> V_18 ( V_2 -> V_12 ) ;
V_17 = F_9 ( V_2 , V_28 , V_3 ) ;
if ( V_17 < 0 ) {
F_3 ( L_4 ) ;
goto V_29;
}
V_17 = F_6 ( V_2 , V_31 ,
V_4 , V_5 , 0 ) ;
if ( V_17 < 0 ) {
F_3 ( L_11 ) ;
goto V_29;
}
V_29:
V_2 -> V_10 -> V_19 ( V_2 -> V_12 ) ;
return V_17 ;
}
int F_22 ( struct V_1 * V_2 , int V_32 )
{
T_3 V_27 ;
T_1 V_33 ;
int V_17 ;
if ( V_34 == V_2 -> V_35 ) {
V_17 = F_7 ( V_2 , V_30 , & V_27 ) ;
if ( V_17 < 0 ) {
F_3 ( L_5 ) ;
return V_17 ;
}
if ( V_32 )
V_27 |= V_36 ;
else
V_27 &= ~ V_36 ;
V_17 = F_9 ( V_2 , V_30 , V_27 ) ;
if ( V_17 < 0 ) {
F_3 ( L_12 ) ;
return V_17 ;
}
} else {
V_17 = F_11 ( V_2 , V_30 , & V_33 ) ;
if ( V_17 < 0 ) {
F_3 ( L_13 ) ;
return V_17 ;
}
if ( V_32 )
V_33 |= V_37 ;
else
V_33 &= ~ V_37 ;
V_17 = F_13 ( V_2 , V_30 , V_33 ) ;
if ( V_17 < 0 ) {
F_3 ( L_14 ) ;
return V_17 ;
}
}
return 0 ;
}
