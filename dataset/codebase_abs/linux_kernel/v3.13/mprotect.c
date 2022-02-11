static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_2 ;
}
static unsigned long F_2 ( struct V_3 * V_4 , T_2 * V_5 ,
unsigned long V_6 , unsigned long V_7 , T_1 V_2 ,
int V_8 , int V_9 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
T_3 * V_13 , V_14 ;
T_4 * V_15 ;
unsigned long V_16 = 0 ;
V_13 = F_3 ( V_11 , V_5 , V_6 , & V_15 ) ;
F_4 () ;
do {
V_14 = * V_13 ;
if ( F_5 ( V_14 ) ) {
T_3 V_17 ;
bool V_18 = false ;
if ( ! V_9 ) {
V_17 = F_6 ( V_11 , V_6 , V_13 ) ;
if ( F_7 ( V_17 ) )
V_17 = F_8 ( V_17 ) ;
V_17 = F_9 ( V_17 , V_2 ) ;
V_18 = true ;
} else {
struct V_19 * V_19 ;
V_17 = * V_13 ;
V_19 = F_10 ( V_4 , V_6 , V_14 ) ;
if ( V_19 ) {
if ( ! F_7 ( V_14 ) ) {
V_17 = F_11 ( V_17 ) ;
F_12 ( V_11 , V_6 , V_13 , V_17 ) ;
V_18 = true ;
}
}
}
if ( V_8 && F_13 ( V_17 ) ) {
V_17 = F_14 ( V_17 ) ;
V_18 = true ;
}
if ( V_18 )
V_16 ++ ;
if ( ! V_9 )
F_15 ( V_11 , V_6 , V_13 , V_17 ) ;
} else if ( F_16 ( V_20 ) && ! F_17 ( V_14 ) ) {
T_5 V_21 = F_18 ( V_14 ) ;
if ( F_19 ( V_21 ) ) {
T_3 V_22 ;
F_20 ( & V_21 ) ;
V_22 = F_21 ( V_21 ) ;
if ( F_22 ( V_14 ) )
V_22 = F_23 ( V_22 ) ;
F_12 ( V_11 , V_6 , V_13 , V_22 ) ;
V_16 ++ ;
}
}
} while ( V_13 ++ , V_6 += V_23 , V_6 != V_7 );
F_24 () ;
F_25 ( V_13 - 1 , V_15 ) ;
return V_16 ;
}
static inline unsigned long F_26 ( struct V_3 * V_4 ,
T_6 * V_24 , unsigned long V_6 , unsigned long V_7 ,
T_1 V_2 , int V_8 , int V_9 )
{
T_2 * V_5 ;
unsigned long V_25 ;
unsigned long V_16 = 0 ;
unsigned long V_26 = 0 ;
V_5 = F_27 ( V_24 , V_6 ) ;
do {
unsigned long V_27 ;
V_25 = F_28 ( V_6 , V_7 ) ;
if ( F_29 ( * V_5 ) ) {
if ( V_25 - V_6 != V_28 )
F_30 ( V_4 , V_6 , V_5 ) ;
else {
int V_29 = F_31 ( V_4 , V_5 , V_6 ,
V_2 , V_9 ) ;
if ( V_29 ) {
if ( V_29 == V_30 ) {
V_16 += V_30 ;
V_26 ++ ;
}
continue;
}
}
}
if ( F_32 ( V_5 ) )
continue;
V_27 = F_2 ( V_4 , V_5 , V_6 , V_25 , V_2 ,
V_8 , V_9 ) ;
V_16 += V_27 ;
} while ( V_5 ++ , V_6 = V_25 , V_6 != V_7 );
if ( V_26 )
F_33 ( V_31 , V_26 ) ;
return V_16 ;
}
static inline unsigned long F_34 ( struct V_3 * V_4 ,
T_7 * V_32 , unsigned long V_6 , unsigned long V_7 ,
T_1 V_2 , int V_8 , int V_9 )
{
T_6 * V_24 ;
unsigned long V_25 ;
unsigned long V_16 = 0 ;
V_24 = F_35 ( V_32 , V_6 ) ;
do {
V_25 = F_36 ( V_6 , V_7 ) ;
if ( F_37 ( V_24 ) )
continue;
V_16 += F_26 ( V_4 , V_24 , V_6 , V_25 , V_2 ,
V_8 , V_9 ) ;
} while ( V_24 ++ , V_6 = V_25 , V_6 != V_7 );
return V_16 ;
}
static unsigned long F_38 ( struct V_3 * V_4 ,
unsigned long V_6 , unsigned long V_7 , T_1 V_2 ,
int V_8 , int V_9 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
T_7 * V_32 ;
unsigned long V_25 ;
unsigned long V_33 = V_6 ;
unsigned long V_16 = 0 ;
F_39 ( V_6 >= V_7 ) ;
V_32 = F_40 ( V_11 , V_6 ) ;
F_41 ( V_4 , V_6 , V_7 ) ;
F_42 ( V_11 ) ;
do {
V_25 = F_43 ( V_6 , V_7 ) ;
if ( F_44 ( V_32 ) )
continue;
V_16 += F_34 ( V_4 , V_32 , V_6 , V_25 , V_2 ,
V_8 , V_9 ) ;
} while ( V_32 ++ , V_6 = V_25 , V_6 != V_7 );
if ( V_16 )
F_45 ( V_4 , V_33 , V_7 ) ;
F_46 ( V_11 ) ;
return V_16 ;
}
unsigned long F_47 ( struct V_3 * V_4 , unsigned long V_33 ,
unsigned long V_7 , T_1 V_2 ,
int V_8 , int V_9 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned long V_16 ;
F_48 ( V_11 , V_33 , V_7 ) ;
if ( F_49 ( V_4 ) )
V_16 = F_50 ( V_4 , V_33 , V_7 , V_2 ) ;
else
V_16 = F_38 ( V_4 , V_33 , V_7 , V_2 , V_8 , V_9 ) ;
F_51 ( V_11 , V_33 , V_7 ) ;
return V_16 ;
}
int
F_52 ( struct V_3 * V_4 , struct V_3 * * V_34 ,
unsigned long V_33 , unsigned long V_7 , unsigned long V_35 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned long V_36 = V_4 -> V_37 ;
long V_38 = ( V_7 - V_33 ) >> V_39 ;
unsigned long V_40 = 0 ;
T_8 V_41 ;
int error ;
int V_8 = 0 ;
if ( V_35 == V_36 ) {
* V_34 = V_4 ;
return 0 ;
}
if ( V_35 & V_42 ) {
if ( ! ( V_36 & ( V_43 | V_42 | V_44 |
V_45 | V_46 ) ) ) {
V_40 = V_38 ;
if ( F_53 ( V_11 , V_40 ) )
return - V_47 ;
V_35 |= V_43 ;
}
}
V_41 = V_4 -> V_48 + ( ( V_33 - V_4 -> V_49 ) >> V_39 ) ;
* V_34 = F_54 ( V_11 , * V_34 , V_33 , V_7 , V_35 ,
V_4 -> V_50 , V_4 -> V_51 , V_41 , F_55 ( V_4 ) ) ;
if ( * V_34 ) {
V_4 = * V_34 ;
goto V_52;
}
* V_34 = V_4 ;
if ( V_33 != V_4 -> V_49 ) {
error = F_56 ( V_11 , V_4 , V_33 , 1 ) ;
if ( error )
goto V_53;
}
if ( V_7 != V_4 -> V_54 ) {
error = F_56 ( V_11 , V_4 , V_7 , 0 ) ;
if ( error )
goto V_53;
}
V_52:
V_4 -> V_37 = V_35 ;
V_4 -> V_55 = F_1 ( V_4 -> V_55 ,
F_57 ( V_35 ) ) ;
if ( F_58 ( V_4 ) ) {
V_4 -> V_55 = F_57 ( V_35 & ~ V_45 ) ;
V_8 = 1 ;
}
F_47 ( V_4 , V_33 , V_7 , V_4 -> V_55 ,
V_8 , 0 ) ;
F_59 ( V_11 , V_36 , V_4 -> V_51 , - V_38 ) ;
F_59 ( V_11 , V_35 , V_4 -> V_51 , V_38 ) ;
F_60 ( V_4 ) ;
return 0 ;
V_53:
F_61 ( V_40 ) ;
return error ;
}
