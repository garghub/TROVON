void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( ! V_2 ) )
return;
F_3 ( V_2 -> V_3 -> V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( ! V_2 ) )
return;
F_5 ( V_2 -> V_3 -> V_4 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned char V_6 ;
unsigned long V_7 ;
if ( ! V_2 )
return - V_8 ;
F_7 ( L_1 , F_8 ( V_2 ) ) ;
V_5 = F_9 ( V_2 -> V_3 , 0 , 0 , V_9 , 0 , & V_6 ) ;
if ( V_5 )
goto V_10;
V_6 |= 1 << V_2 -> V_11 ;
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 , V_9 , V_6 , NULL ) ;
if ( V_5 )
goto V_10;
V_7 = V_12 + F_10 ( V_2 -> V_13 ) ;
while ( 1 ) {
V_5 = F_9 ( V_2 -> V_3 , 0 , 0 , V_14 , 0 , & V_6 ) ;
if ( V_5 )
goto V_10;
if ( V_6 & ( 1 << V_2 -> V_11 ) )
break;
V_5 = - V_15 ;
if ( F_11 ( V_12 , V_7 ) )
goto V_10;
}
F_7 ( L_2 , F_8 ( V_2 ) ) ;
return 0 ;
V_10:
F_7 ( L_3 , F_8 ( V_2 ) ) ;
return V_5 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned char V_6 ;
if ( ! V_2 )
return - V_8 ;
F_7 ( L_4 , F_8 ( V_2 ) ) ;
V_5 = F_9 ( V_2 -> V_3 , 0 , 0 , V_9 , 0 , & V_6 ) ;
if ( V_5 )
goto V_10;
V_6 &= ~ ( 1 << V_2 -> V_11 ) ;
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 , V_9 , V_6 , NULL ) ;
if ( V_5 )
goto V_10;
F_7 ( L_5 , F_8 ( V_2 ) ) ;
return 0 ;
V_10:
F_7 ( L_6 , F_8 ( V_2 ) ) ;
return - V_16 ;
}
int F_13 ( struct V_1 * V_2 , unsigned V_17 )
{
int V_5 ;
if ( V_17 > V_2 -> V_3 -> V_4 -> V_18 )
return - V_8 ;
if ( V_17 == 0 ) {
V_17 = F_14 ( V_2 -> V_19 , V_2 -> V_3 -> V_4 -> V_18 ) ;
V_17 = F_14 ( V_17 , 512u ) ;
}
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 ,
F_15 ( V_2 -> V_11 ) + V_20 ,
V_17 & 0xff , NULL ) ;
if ( V_5 )
return V_5 ;
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 ,
F_15 ( V_2 -> V_11 ) + V_20 + 1 ,
( V_17 >> 8 ) & 0xff , NULL ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_21 = V_17 ;
return 0 ;
}
static inline unsigned int F_16 ( struct V_1 * V_2 )
{
unsigned V_22 = V_2 -> V_3 -> V_4 -> V_18 ;
if ( F_17 ( V_2 -> V_3 ) )
V_22 = F_14 ( V_22 , V_2 -> V_21 ) ;
else
V_22 = F_14 ( V_22 , V_2 -> V_19 ) ;
if ( F_18 ( V_2 -> V_3 ) )
return F_14 ( V_22 , 511u ) ;
return F_14 ( V_22 , 512u ) ;
}
unsigned int F_19 ( struct V_1 * V_2 , unsigned int V_23 )
{
unsigned int V_24 ;
unsigned int V_25 , V_26 ;
unsigned V_27 ;
V_24 = V_23 ;
V_23 = F_20 ( V_2 -> V_3 , V_23 ) ;
if ( V_23 <= F_16 ( V_2 ) )
return V_23 ;
if ( V_2 -> V_3 -> V_28 . V_29 ) {
if ( ( V_23 % V_2 -> V_21 ) == 0 )
return V_23 ;
V_25 = ( ( V_23 + V_2 -> V_21 - 1 ) /
V_2 -> V_21 ) * V_2 -> V_21 ;
V_25 = F_20 ( V_2 -> V_3 , V_25 ) ;
if ( ( V_25 % V_2 -> V_21 ) == 0 )
return V_25 ;
V_26 = F_20 ( V_2 -> V_3 ,
V_23 % V_2 -> V_21 ) ;
if ( V_26 <= F_16 ( V_2 ) ) {
V_25 = V_23 / V_2 -> V_21 ;
return V_25 * V_2 -> V_21 + V_26 ;
}
} else {
V_27 = F_20 ( V_2 -> V_3 ,
F_16 ( V_2 ) ) ;
if ( V_27 == F_16 ( V_2 ) ) {
V_26 = V_24 % V_27 ;
if ( V_26 ) {
V_26 = F_20 ( V_2 -> V_3 ,
V_26 ) ;
}
return ( V_24 / V_27 ) * V_27 + V_26 ;
}
}
return V_24 ;
}
static int F_21 ( struct V_1 * V_2 , int V_30 ,
unsigned V_31 , int V_32 , T_1 * V_33 , unsigned V_34 )
{
unsigned V_35 = V_34 ;
unsigned V_36 ;
int V_5 ;
if ( ! V_2 || ( V_2 -> V_11 > 7 ) )
return - V_8 ;
if ( V_2 -> V_3 -> V_28 . V_29 && ( V_34 > F_16 ( V_2 ) ) ) {
V_36 = F_14 ( V_2 -> V_3 -> V_4 -> V_37 , 511u ) ;
while ( V_35 >= V_2 -> V_21 ) {
unsigned V_38 ;
V_38 = V_35 / V_2 -> V_21 ;
if ( V_38 > V_36 )
V_38 = V_36 ;
V_34 = V_38 * V_2 -> V_21 ;
V_5 = F_22 ( V_2 -> V_3 , V_30 ,
V_2 -> V_11 , V_31 , V_32 , V_33 ,
V_38 , V_2 -> V_21 ) ;
if ( V_5 )
return V_5 ;
V_35 -= V_34 ;
V_33 += V_34 ;
if ( V_32 )
V_31 += V_34 ;
}
}
while ( V_35 > 0 ) {
V_34 = F_14 ( V_35 , F_16 ( V_2 ) ) ;
V_5 = F_22 ( V_2 -> V_3 , V_30 , V_2 -> V_11 , V_31 ,
V_32 , V_33 , 0 , V_34 ) ;
if ( V_5 )
return V_5 ;
V_35 -= V_34 ;
V_33 += V_34 ;
if ( V_32 )
V_31 += V_34 ;
}
return 0 ;
}
T_1 F_23 ( struct V_1 * V_2 , unsigned int V_31 , int * V_39 )
{
int V_5 ;
T_1 V_40 ;
if ( ! V_2 ) {
if ( V_39 )
* V_39 = - V_8 ;
return 0xFF ;
}
V_5 = F_9 ( V_2 -> V_3 , 0 , V_2 -> V_11 , V_31 , 0 , & V_40 ) ;
if ( V_39 )
* V_39 = V_5 ;
if ( V_5 )
return 0xFF ;
return V_40 ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_41 , unsigned int V_31 , int * V_39 )
{
int V_5 ;
if ( ! V_2 ) {
if ( V_39 )
* V_39 = - V_8 ;
return;
}
V_5 = F_9 ( V_2 -> V_3 , 1 , V_2 -> V_11 , V_31 , V_41 , NULL ) ;
if ( V_39 )
* V_39 = V_5 ;
}
T_1 F_25 ( struct V_1 * V_2 , T_1 V_42 ,
unsigned int V_31 , int * V_39 )
{
int V_5 ;
T_1 V_40 ;
V_5 = F_9 ( V_2 -> V_3 , 1 , V_2 -> V_11 , V_31 ,
V_42 , & V_40 ) ;
if ( V_39 )
* V_39 = V_5 ;
if ( V_5 )
return 0xff ;
return V_40 ;
}
int F_26 ( struct V_1 * V_2 , void * V_43 ,
unsigned int V_31 , int V_44 )
{
return F_21 ( V_2 , 0 , V_31 , 1 , V_43 , V_44 ) ;
}
int F_27 ( struct V_1 * V_2 , unsigned int V_31 ,
void * V_45 , int V_44 )
{
return F_21 ( V_2 , 1 , V_31 , 1 , V_45 , V_44 ) ;
}
int F_28 ( struct V_1 * V_2 , void * V_43 , unsigned int V_31 ,
int V_44 )
{
return F_21 ( V_2 , 0 , V_31 , 0 , V_43 , V_44 ) ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_31 , void * V_45 ,
int V_44 )
{
return F_21 ( V_2 , 1 , V_31 , 0 , V_45 , V_44 ) ;
}
T_2 F_30 ( struct V_1 * V_2 , unsigned int V_31 , int * V_39 )
{
int V_5 ;
V_5 = F_26 ( V_2 , V_2 -> V_46 , V_31 , 2 ) ;
if ( V_39 )
* V_39 = V_5 ;
if ( V_5 )
return 0xFFFF ;
return F_31 ( ( V_47 * ) V_2 -> V_46 ) ;
}
void F_32 ( struct V_1 * V_2 , T_2 V_41 , unsigned int V_31 , int * V_39 )
{
int V_5 ;
* ( V_47 * ) V_2 -> V_46 = F_33 ( V_41 ) ;
V_5 = F_27 ( V_2 , V_31 , V_2 -> V_46 , 2 ) ;
if ( V_39 )
* V_39 = V_5 ;
}
T_3 F_34 ( struct V_1 * V_2 , unsigned int V_31 , int * V_39 )
{
int V_5 ;
V_5 = F_26 ( V_2 , V_2 -> V_46 , V_31 , 4 ) ;
if ( V_39 )
* V_39 = V_5 ;
if ( V_5 )
return 0xFFFFFFFF ;
return F_35 ( ( V_48 * ) V_2 -> V_46 ) ;
}
void F_36 ( struct V_1 * V_2 , T_3 V_41 , unsigned int V_31 , int * V_39 )
{
int V_5 ;
* ( V_48 * ) V_2 -> V_46 = F_37 ( V_41 ) ;
V_5 = F_27 ( V_2 , V_31 , V_2 -> V_46 , 4 ) ;
if ( V_39 )
* V_39 = V_5 ;
}
unsigned char F_38 ( struct V_1 * V_2 , unsigned int V_31 ,
int * V_39 )
{
int V_5 ;
unsigned char V_40 ;
if ( ! V_2 ) {
if ( V_39 )
* V_39 = - V_8 ;
return 0xFF ;
}
V_5 = F_9 ( V_2 -> V_3 , 0 , 0 , V_31 , 0 , & V_40 ) ;
if ( V_39 )
* V_39 = V_5 ;
if ( V_5 )
return 0xFF ;
return V_40 ;
}
void F_39 ( struct V_1 * V_2 , unsigned char V_41 , unsigned int V_31 ,
int * V_39 )
{
int V_5 ;
if ( ! V_2 ) {
if ( V_39 )
* V_39 = - V_8 ;
return;
}
if ( ( V_31 < 0xF0 || V_31 > 0xFF ) && ( ! F_40 ( V_2 -> V_3 ) ) ) {
if ( V_39 )
* V_39 = - V_8 ;
return;
}
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 , V_31 , V_41 , NULL ) ;
if ( V_39 )
* V_39 = V_5 ;
}
T_4 F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return V_2 -> V_3 -> V_4 -> V_49 ;
}
int F_42 ( struct V_1 * V_2 , T_4 V_50 )
{
struct V_51 * V_4 ;
if ( ! V_2 )
return - V_8 ;
V_4 = V_2 -> V_3 -> V_4 ;
if ( V_50 & ~ V_4 -> V_49 )
return - V_8 ;
V_4 -> V_52 |= V_50 ;
return 0 ;
}
