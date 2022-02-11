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
static int F_9 ( void * V_15 , const void * V_3 ,
T_2 V_16 , const void * V_4 ,
T_2 V_17 )
{
struct V_1 * V_2 = V_15 ;
unsigned int V_18 = * ( T_1 * ) V_3 ;
int V_19 ;
if ( V_18 % V_20 . V_21 )
return - V_22 ;
F_1 ( V_2 , V_23 ,
V_24 ) ;
F_8 ( 100 , 200 ) ;
while ( V_17 ) {
F_2 ( * ( T_1 * ) V_4 , V_2 -> V_25 + V_18 ) ;
V_19 = F_5 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_17 -= V_2 -> V_26 ;
V_4 += V_2 -> V_26 ;
V_18 += V_2 -> V_26 ;
}
F_1 ( V_2 , V_23 ,
V_27 ) ;
return 0 ;
}
static int F_10 ( void * V_15 , const void * V_28 , T_2 V_29 )
{
struct V_1 * V_2 = V_15 ;
unsigned int V_18 = V_2 -> V_30 ;
if ( V_29 <= V_18 )
return - V_22 ;
return F_9 ( V_15 , V_28 , V_2 -> V_30 ,
V_28 + V_18 , V_29 - V_18 ) ;
}
static int F_11 ( void * V_15 , const void * V_3 , T_2 V_16 ,
void * V_4 , T_2 V_17 )
{
struct V_1 * V_2 = V_15 ;
unsigned int V_18 = * ( T_1 * ) V_3 ;
F_1 ( V_2 , V_23 ,
V_24 ) ;
F_8 ( 100 , 200 ) ;
while ( V_17 ) {
* ( T_1 * ) V_4 = F_4 ( V_2 -> V_25 + V_18 ) ;
V_17 -= V_2 -> V_26 ;
V_4 += V_2 -> V_26 ;
V_18 += V_2 -> V_26 ;
}
F_1 ( V_2 , V_23 ,
V_27 ) ;
return 0 ;
}
static bool F_12 ( struct V_31 * V_32 , unsigned int V_3 )
{
return V_3 <= V_20 . V_33 -
V_34 ;
}
static bool F_13 ( struct V_31 * V_32 , unsigned int V_3 )
{
return V_3 <= V_20 . V_33 ;
}
static int F_14 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 = & V_36 -> V_32 ;
struct V_37 * V_38 ;
unsigned long V_39 ;
struct V_40 * V_40 ;
struct V_41 * V_42 ;
int V_19 ;
V_2 = F_15 ( V_32 , sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_42 = F_16 ( V_36 , V_45 , L_1 ) ;
V_2 -> V_5 = F_17 ( V_32 , V_42 ) ;
if ( F_18 ( V_2 -> V_5 ) )
return F_19 ( V_2 -> V_5 ) ;
V_42 = F_16 ( V_36 , V_45 , L_2 ) ;
V_2 -> V_25 = F_17 ( V_32 , V_42 ) ;
if ( F_18 ( V_2 -> V_25 ) )
return F_19 ( V_2 -> V_25 ) ;
V_2 -> V_46 = F_20 ( & V_36 -> V_32 , L_3 ) ;
if ( F_18 ( V_2 -> V_46 ) ) {
F_21 ( & V_36 -> V_32 , L_4 ) ;
return F_19 ( V_2 -> V_46 ) ;
}
V_19 = F_22 ( V_2 -> V_46 ) ;
if ( V_19 < 0 ) {
F_21 ( V_32 , L_5 , V_19 ) ;
return V_19 ;
}
V_38 = F_23 ( V_32 , NULL ) ;
if ( F_18 ( V_38 ) ) {
F_21 ( V_32 , L_6 , F_19 ( V_38 ) ) ;
V_19 = F_19 ( V_38 ) ;
goto V_47;
}
V_19 = F_24 ( V_38 ) ;
if ( V_19 < 0 ) {
F_21 ( V_32 , L_7 , V_19 ) ;
goto V_47;
}
V_2 -> V_26 = V_20 . V_48 / V_49 ;
V_2 -> V_30 = V_20 . V_50 / V_49 ;
V_39 = F_25 ( V_2 -> V_46 ) ;
V_39 = F_26 ( V_39 , V_51 ) - 1 ;
F_1 ( V_2 , V_52 , V_39 ) ;
F_1 ( V_2 , V_53 ,
V_54 ) ;
F_1 ( V_2 , V_23 ,
V_27 ) ;
V_20 . V_33 = F_27 ( V_42 ) - 1 ;
V_20 . V_55 = F_12 ;
V_20 . V_56 = F_13 ;
V_40 = F_28 ( V_32 , & V_57 , V_2 ,
& V_20 ) ;
if ( F_18 ( V_40 ) ) {
F_21 ( V_32 , L_8 , F_19 ( V_40 ) ) ;
V_19 = F_19 ( V_40 ) ;
goto V_47;
}
V_58 . V_32 = V_32 ;
V_2 -> V_59 = F_29 ( & V_58 ) ;
if ( F_18 ( V_2 -> V_59 ) ) {
V_19 = F_19 ( V_2 -> V_59 ) ;
goto V_47;
}
F_30 ( V_36 , V_2 ) ;
return 0 ;
V_47:
F_31 ( V_2 -> V_46 ) ;
return V_19 ;
}
static int F_32 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_33 ( V_36 ) ;
int V_19 ;
V_19 = F_34 ( V_2 -> V_59 ) ;
if ( V_19 < 0 )
return V_19 ;
F_31 ( V_2 -> V_46 ) ;
return 0 ;
}
