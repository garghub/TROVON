void F_1 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_3 ) ;
F_3 ( V_2 -> V_3 -> V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_3 ) ;
F_5 ( V_2 -> V_3 -> V_4 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned char V_6 ;
unsigned long V_7 ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_3 ) ;
F_7 ( L_1 , F_8 ( V_2 ) ) ;
V_5 = F_9 ( V_2 -> V_3 , 0 , 0 , V_8 , 0 , & V_6 ) ;
if ( V_5 )
goto V_9;
V_6 |= 1 << V_2 -> V_10 ;
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 , V_8 , V_6 , NULL ) ;
if ( V_5 )
goto V_9;
V_7 = V_11 + F_10 ( V_2 -> V_12 ) ;
while ( 1 ) {
V_5 = F_9 ( V_2 -> V_3 , 0 , 0 , V_13 , 0 , & V_6 ) ;
if ( V_5 )
goto V_9;
if ( V_6 & ( 1 << V_2 -> V_10 ) )
break;
V_5 = - V_14 ;
if ( F_11 ( V_11 , V_7 ) )
goto V_9;
}
F_7 ( L_2 , F_8 ( V_2 ) ) ;
return 0 ;
V_9:
F_7 ( L_3 , F_8 ( V_2 ) ) ;
return V_5 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned char V_6 ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_3 ) ;
F_7 ( L_4 , F_8 ( V_2 ) ) ;
V_5 = F_9 ( V_2 -> V_3 , 0 , 0 , V_8 , 0 , & V_6 ) ;
if ( V_5 )
goto V_9;
V_6 &= ~ ( 1 << V_2 -> V_10 ) ;
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 , V_8 , V_6 , NULL ) ;
if ( V_5 )
goto V_9;
F_7 ( L_5 , F_8 ( V_2 ) ) ;
return 0 ;
V_9:
F_7 ( L_6 , F_8 ( V_2 ) ) ;
return - V_15 ;
}
int F_13 ( struct V_1 * V_2 , unsigned V_16 )
{
int V_5 ;
if ( V_16 > V_2 -> V_3 -> V_4 -> V_17 )
return - V_18 ;
if ( V_16 == 0 ) {
V_16 = F_14 ( V_2 -> V_19 , V_2 -> V_3 -> V_4 -> V_17 ) ;
V_16 = F_14 ( V_16 , 512u ) ;
}
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 ,
F_15 ( V_2 -> V_10 ) + V_20 ,
V_16 & 0xff , NULL ) ;
if ( V_5 )
return V_5 ;
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 ,
F_15 ( V_2 -> V_10 ) + V_20 + 1 ,
( V_16 >> 8 ) & 0xff , NULL ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_21 = V_16 ;
return 0 ;
}
static inline unsigned int F_16 ( struct V_1 * V_2 )
{
unsigned V_22 = F_14 ( V_2 -> V_3 -> V_4 -> V_23 ,
V_2 -> V_3 -> V_4 -> V_17 ) ;
if ( F_17 ( V_2 -> V_3 ) )
V_22 = F_14 ( V_22 , V_2 -> V_21 ) ;
else
V_22 = F_14 ( V_22 , V_2 -> V_19 ) ;
if ( F_18 ( V_2 -> V_3 ) )
return F_14 ( V_22 , 511u ) ;
return F_14 ( V_22 , 512u ) ;
}
unsigned int F_19 ( struct V_1 * V_2 , unsigned int V_24 )
{
unsigned int V_25 ;
unsigned int V_26 , V_27 ;
unsigned V_28 ;
V_25 = V_24 ;
V_24 = F_20 ( V_2 -> V_3 , V_24 ) ;
if ( V_24 <= F_16 ( V_2 ) )
return V_24 ;
if ( V_2 -> V_3 -> V_29 . V_30 ) {
if ( ( V_24 % V_2 -> V_21 ) == 0 )
return V_24 ;
V_26 = ( ( V_24 + V_2 -> V_21 - 1 ) /
V_2 -> V_21 ) * V_2 -> V_21 ;
V_26 = F_20 ( V_2 -> V_3 , V_26 ) ;
if ( ( V_26 % V_2 -> V_21 ) == 0 )
return V_26 ;
V_27 = F_20 ( V_2 -> V_3 ,
V_24 % V_2 -> V_21 ) ;
if ( V_27 <= F_16 ( V_2 ) ) {
V_26 = V_24 / V_2 -> V_21 ;
return V_26 * V_2 -> V_21 + V_27 ;
}
} else {
V_28 = F_20 ( V_2 -> V_3 ,
F_16 ( V_2 ) ) ;
if ( V_28 == F_16 ( V_2 ) ) {
V_27 = V_25 % V_28 ;
if ( V_27 ) {
V_27 = F_20 ( V_2 -> V_3 ,
V_27 ) ;
}
return ( V_25 / V_28 ) * V_28 + V_27 ;
}
}
return V_25 ;
}
static int F_21 ( struct V_1 * V_2 , int V_31 ,
unsigned V_32 , int V_33 , T_1 * V_34 , unsigned V_35 )
{
unsigned V_36 = V_35 ;
unsigned V_37 ;
int V_5 ;
if ( V_2 -> V_3 -> V_29 . V_30 && ( V_35 > F_16 ( V_2 ) ) ) {
V_37 = F_14 ( V_2 -> V_3 -> V_4 -> V_38 ,
V_2 -> V_3 -> V_4 -> V_23 / V_2 -> V_21 ) ;
V_37 = F_14 ( V_37 , 511u ) ;
while ( V_36 >= V_2 -> V_21 ) {
unsigned V_39 ;
V_39 = V_36 / V_2 -> V_21 ;
if ( V_39 > V_37 )
V_39 = V_37 ;
V_35 = V_39 * V_2 -> V_21 ;
V_5 = F_22 ( V_2 -> V_3 , V_31 ,
V_2 -> V_10 , V_32 , V_33 , V_34 ,
V_39 , V_2 -> V_21 ) ;
if ( V_5 )
return V_5 ;
V_36 -= V_35 ;
V_34 += V_35 ;
if ( V_33 )
V_32 += V_35 ;
}
}
while ( V_36 > 0 ) {
V_35 = F_14 ( V_36 , F_16 ( V_2 ) ) ;
V_5 = F_22 ( V_2 -> V_3 , V_31 , V_2 -> V_10 , V_32 ,
V_33 , V_34 , 0 , V_35 ) ;
if ( V_5 )
return V_5 ;
V_36 -= V_35 ;
V_34 += V_35 ;
if ( V_33 )
V_32 += V_35 ;
}
return 0 ;
}
T_1 F_23 ( struct V_1 * V_2 , unsigned int V_32 , int * V_40 )
{
int V_5 ;
T_1 V_41 ;
F_2 ( ! V_2 ) ;
if ( V_40 )
* V_40 = 0 ;
V_5 = F_9 ( V_2 -> V_3 , 0 , V_2 -> V_10 , V_32 , 0 , & V_41 ) ;
if ( V_5 ) {
if ( V_40 )
* V_40 = V_5 ;
return 0xFF ;
}
return V_41 ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_42 , unsigned int V_32 , int * V_40 )
{
int V_5 ;
F_2 ( ! V_2 ) ;
V_5 = F_9 ( V_2 -> V_3 , 1 , V_2 -> V_10 , V_32 , V_42 , NULL ) ;
if ( V_40 )
* V_40 = V_5 ;
}
T_1 F_25 ( struct V_1 * V_2 , T_1 V_43 ,
unsigned int V_32 , int * V_40 )
{
int V_5 ;
T_1 V_41 ;
V_5 = F_9 ( V_2 -> V_3 , 1 , V_2 -> V_10 , V_32 ,
V_43 , & V_41 ) ;
if ( V_40 )
* V_40 = V_5 ;
if ( V_5 )
V_41 = 0xff ;
return V_41 ;
}
int F_26 ( struct V_1 * V_2 , void * V_44 ,
unsigned int V_32 , int V_45 )
{
return F_21 ( V_2 , 0 , V_32 , 1 , V_44 , V_45 ) ;
}
int F_27 ( struct V_1 * V_2 , unsigned int V_32 ,
void * V_46 , int V_45 )
{
return F_21 ( V_2 , 1 , V_32 , 1 , V_46 , V_45 ) ;
}
int F_28 ( struct V_1 * V_2 , void * V_44 , unsigned int V_32 ,
int V_45 )
{
return F_21 ( V_2 , 0 , V_32 , 0 , V_44 , V_45 ) ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_32 , void * V_46 ,
int V_45 )
{
return F_21 ( V_2 , 1 , V_32 , 0 , V_46 , V_45 ) ;
}
T_2 F_30 ( struct V_1 * V_2 , unsigned int V_32 , int * V_40 )
{
int V_5 ;
if ( V_40 )
* V_40 = 0 ;
V_5 = F_26 ( V_2 , V_2 -> V_47 , V_32 , 2 ) ;
if ( V_5 ) {
if ( V_40 )
* V_40 = V_5 ;
return 0xFFFF ;
}
return F_31 ( ( V_48 * ) V_2 -> V_47 ) ;
}
void F_32 ( struct V_1 * V_2 , T_2 V_42 , unsigned int V_32 , int * V_40 )
{
int V_5 ;
* ( V_48 * ) V_2 -> V_47 = F_33 ( V_42 ) ;
V_5 = F_27 ( V_2 , V_32 , V_2 -> V_47 , 2 ) ;
if ( V_40 )
* V_40 = V_5 ;
}
T_3 F_34 ( struct V_1 * V_2 , unsigned int V_32 , int * V_40 )
{
int V_5 ;
if ( V_40 )
* V_40 = 0 ;
V_5 = F_26 ( V_2 , V_2 -> V_47 , V_32 , 4 ) ;
if ( V_5 ) {
if ( V_40 )
* V_40 = V_5 ;
return 0xFFFFFFFF ;
}
return F_35 ( ( V_49 * ) V_2 -> V_47 ) ;
}
void F_36 ( struct V_1 * V_2 , T_3 V_42 , unsigned int V_32 , int * V_40 )
{
int V_5 ;
* ( V_49 * ) V_2 -> V_47 = F_37 ( V_42 ) ;
V_5 = F_27 ( V_2 , V_32 , V_2 -> V_47 , 4 ) ;
if ( V_40 )
* V_40 = V_5 ;
}
unsigned char F_38 ( struct V_1 * V_2 , unsigned int V_32 ,
int * V_40 )
{
int V_5 ;
unsigned char V_41 ;
F_2 ( ! V_2 ) ;
if ( V_40 )
* V_40 = 0 ;
V_5 = F_9 ( V_2 -> V_3 , 0 , 0 , V_32 , 0 , & V_41 ) ;
if ( V_5 ) {
if ( V_40 )
* V_40 = V_5 ;
return 0xFF ;
}
return V_41 ;
}
void F_39 ( struct V_1 * V_2 , unsigned char V_42 , unsigned int V_32 ,
int * V_40 )
{
int V_5 ;
F_2 ( ! V_2 ) ;
if ( ( V_32 < 0xF0 || V_32 > 0xFF ) && ( ! F_40 ( V_2 -> V_3 ) ) ) {
if ( V_40 )
* V_40 = - V_18 ;
return;
}
V_5 = F_9 ( V_2 -> V_3 , 1 , 0 , V_32 , V_42 , NULL ) ;
if ( V_40 )
* V_40 = V_5 ;
}
T_4 F_41 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_3 ) ;
return V_2 -> V_3 -> V_4 -> V_50 ;
}
int F_42 ( struct V_1 * V_2 , T_4 V_51 )
{
struct V_52 * V_4 ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_2 -> V_3 ) ;
V_4 = V_2 -> V_3 -> V_4 ;
if ( V_51 & ~ V_4 -> V_50 )
return - V_18 ;
V_4 -> V_53 |= V_51 ;
return 0 ;
}
