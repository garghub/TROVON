static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
T_1 V_4 ;
V_6 = V_7 + F_6 ( V_8 * 10 ) ;
while ( F_7 ( V_6 ) ) {
V_4 = F_3 ( V_2 , V_9 ) ;
if ( V_4 & V_10 ) {
F_1 ( V_2 , V_11 ,
V_12 ) ;
return 0 ;
}
F_8 ( V_8 * V_13 ,
( V_8 + 1 ) * V_13 ) ;
}
return - V_14 ;
}
static int F_9 ( void * V_15 , unsigned int V_3 ,
void * V_4 , T_2 V_16 )
{
struct V_1 * V_2 = V_15 ;
unsigned int V_17 = V_3 ;
int V_18 ;
if ( ( V_3 > V_2 -> V_19 - V_20 ) ||
( V_3 + V_16 > V_2 -> V_19 - V_20 ) )
return - V_21 ;
F_1 ( V_2 , V_22 ,
V_23 ) ;
F_8 ( 100 , 200 ) ;
while ( V_16 ) {
F_2 ( * ( T_1 * ) V_4 , V_2 -> V_24 + V_17 ) ;
V_18 = F_5 ( V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_16 -= V_2 -> V_25 ;
V_4 += V_2 -> V_25 ;
V_17 += V_2 -> V_25 ;
}
F_1 ( V_2 , V_22 ,
V_26 ) ;
return 0 ;
}
static int F_10 ( void * V_15 , unsigned int V_17 ,
void * V_4 , T_2 V_16 )
{
struct V_1 * V_2 = V_15 ;
F_1 ( V_2 , V_22 ,
V_23 ) ;
F_8 ( 100 , 200 ) ;
while ( V_16 ) {
* ( T_1 * ) V_4 = F_4 ( V_2 -> V_24 + V_17 ) ;
V_16 -= V_2 -> V_25 ;
V_4 += V_2 -> V_25 ;
V_17 += V_2 -> V_25 ;
}
F_1 ( V_2 , V_22 ,
V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 = & V_28 -> V_30 ;
struct V_31 * V_32 ;
unsigned long V_33 ;
struct V_34 * V_35 ;
int V_18 ;
V_2 = F_12 ( V_30 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_35 = F_13 ( V_28 , V_38 , L_1 ) ;
V_2 -> V_5 = F_14 ( V_30 , V_35 ) ;
if ( F_15 ( V_2 -> V_5 ) )
return F_16 ( V_2 -> V_5 ) ;
V_35 = F_13 ( V_28 , V_38 , L_2 ) ;
V_2 -> V_24 = F_14 ( V_30 , V_35 ) ;
if ( F_15 ( V_2 -> V_24 ) )
return F_16 ( V_2 -> V_24 ) ;
V_2 -> V_39 = F_17 ( & V_28 -> V_30 , L_3 ) ;
if ( F_15 ( V_2 -> V_39 ) ) {
F_18 ( & V_28 -> V_30 , L_4 ) ;
return F_16 ( V_2 -> V_39 ) ;
}
V_18 = F_19 ( V_2 -> V_39 ) ;
if ( V_18 < 0 ) {
F_18 ( V_30 , L_5 , V_18 ) ;
return V_18 ;
}
V_32 = F_20 ( V_30 , NULL ) ;
if ( F_15 ( V_32 ) ) {
F_18 ( V_30 , L_6 , F_16 ( V_32 ) ) ;
V_18 = F_16 ( V_32 ) ;
goto V_40;
}
V_18 = F_21 ( V_32 ) ;
if ( V_18 < 0 ) {
F_18 ( V_30 , L_7 , V_18 ) ;
goto V_40;
}
V_2 -> V_25 = 4 ;
V_2 -> V_41 = 4 ;
V_33 = F_22 ( V_2 -> V_39 ) ;
V_33 = F_23 ( V_33 , V_42 ) - 1 ;
F_1 ( V_2 , V_43 , V_33 ) ;
F_1 ( V_2 , V_44 ,
V_45 ) ;
F_1 ( V_2 , V_22 ,
V_26 ) ;
V_2 -> V_19 = F_24 ( V_35 ) ;
V_46 . V_19 = F_24 ( V_35 ) ;
V_46 . V_30 = V_30 ;
V_46 . V_47 = V_2 ;
V_2 -> V_48 = F_25 ( & V_46 ) ;
if ( F_15 ( V_2 -> V_48 ) ) {
V_18 = F_16 ( V_2 -> V_48 ) ;
goto V_40;
}
F_26 ( V_28 , V_2 ) ;
return 0 ;
V_40:
F_27 ( V_2 -> V_39 ) ;
return V_18 ;
}
static int F_28 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_29 ( V_28 ) ;
int V_18 ;
V_18 = F_30 ( V_2 -> V_48 ) ;
if ( V_18 < 0 )
return V_18 ;
F_27 ( V_2 -> V_39 ) ;
return 0 ;
}
