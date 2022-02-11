static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_2 ;
}
static T_2 * F_2 ( struct V_3 * V_4 , T_3 * V_5 ,
unsigned long V_6 , int V_7 , T_4 * * V_8 )
{
T_2 * V_9 ;
T_4 * V_10 ;
if ( ! V_7 )
return F_3 ( V_4 -> V_11 , V_5 , V_6 , V_8 ) ;
V_10 = F_4 ( V_4 -> V_11 , V_5 ) ;
if ( F_5 ( F_6 ( * V_5 ) || F_7 ( * V_5 ) ) ) {
F_8 ( V_10 ) ;
return NULL ;
}
V_9 = F_3 ( V_4 -> V_11 , V_5 , V_6 , V_8 ) ;
F_8 ( V_10 ) ;
return V_9 ;
}
static unsigned long F_9 ( struct V_3 * V_4 , T_3 * V_5 ,
unsigned long V_6 , unsigned long V_12 , T_1 V_2 ,
int V_13 , int V_7 )
{
struct V_14 * V_15 = V_4 -> V_11 ;
T_2 * V_9 , V_16 ;
T_4 * V_8 ;
unsigned long V_17 = 0 ;
V_9 = F_2 ( V_4 , V_5 , V_6 , V_7 , & V_8 ) ;
if ( ! V_9 )
return 0 ;
F_10 () ;
do {
V_16 = * V_9 ;
if ( F_11 ( V_16 ) ) {
T_2 V_18 ;
bool V_19 = false ;
if ( ! V_7 ) {
V_18 = F_12 ( V_15 , V_6 , V_9 ) ;
if ( F_13 ( V_18 ) )
V_18 = F_14 ( V_18 ) ;
V_18 = F_15 ( V_18 , V_2 ) ;
if ( V_13 && F_16 ( V_18 ) )
V_18 = F_17 ( V_18 ) ;
F_18 ( V_15 , V_6 , V_9 , V_18 ) ;
V_19 = true ;
} else {
struct V_20 * V_20 ;
V_20 = F_19 ( V_4 , V_6 , V_16 ) ;
if ( V_20 && ! F_20 ( V_20 ) ) {
if ( ! F_13 ( V_16 ) ) {
F_21 ( V_15 , V_6 , V_9 ) ;
V_19 = true ;
}
}
}
if ( V_19 )
V_17 ++ ;
} else if ( F_22 ( V_21 ) && ! F_23 ( V_16 ) ) {
T_5 V_22 = F_24 ( V_16 ) ;
if ( F_25 ( V_22 ) ) {
T_2 V_23 ;
F_26 ( & V_22 ) ;
V_23 = F_27 ( V_22 ) ;
if ( F_28 ( V_16 ) )
V_23 = F_29 ( V_23 ) ;
F_30 ( V_15 , V_6 , V_9 , V_23 ) ;
V_17 ++ ;
}
}
} while ( V_9 ++ , V_6 += V_24 , V_6 != V_12 );
F_31 () ;
F_32 ( V_9 - 1 , V_8 ) ;
return V_17 ;
}
static inline unsigned long F_33 ( struct V_3 * V_4 ,
T_6 * V_25 , unsigned long V_6 , unsigned long V_12 ,
T_1 V_2 , int V_13 , int V_7 )
{
T_3 * V_5 ;
struct V_14 * V_15 = V_4 -> V_11 ;
unsigned long V_26 ;
unsigned long V_17 = 0 ;
unsigned long V_27 = 0 ;
unsigned long V_28 = 0 ;
V_5 = F_34 ( V_25 , V_6 ) ;
do {
unsigned long V_29 ;
V_26 = F_35 ( V_6 , V_12 ) ;
if ( ! F_6 ( * V_5 ) && F_36 ( V_5 ) )
continue;
if ( ! V_28 ) {
V_28 = V_6 ;
F_37 ( V_15 , V_28 , V_12 ) ;
}
if ( F_6 ( * V_5 ) ) {
if ( V_26 - V_6 != V_30 )
F_38 ( V_4 , V_6 , V_5 ) ;
else {
int V_31 = F_39 ( V_4 , V_5 , V_6 ,
V_2 , V_7 ) ;
if ( V_31 ) {
if ( V_31 == V_32 ) {
V_17 += V_32 ;
V_27 ++ ;
}
continue;
}
}
}
V_29 = F_9 ( V_4 , V_5 , V_6 , V_26 , V_2 ,
V_13 , V_7 ) ;
V_17 += V_29 ;
} while ( V_5 ++ , V_6 = V_26 , V_6 != V_12 );
if ( V_28 )
F_40 ( V_15 , V_28 , V_12 ) ;
if ( V_27 )
F_41 ( V_33 , V_27 ) ;
return V_17 ;
}
static inline unsigned long F_42 ( struct V_3 * V_4 ,
T_7 * V_34 , unsigned long V_6 , unsigned long V_12 ,
T_1 V_2 , int V_13 , int V_7 )
{
T_6 * V_25 ;
unsigned long V_26 ;
unsigned long V_17 = 0 ;
V_25 = F_43 ( V_34 , V_6 ) ;
do {
V_26 = F_44 ( V_6 , V_12 ) ;
if ( F_45 ( V_25 ) )
continue;
V_17 += F_33 ( V_4 , V_25 , V_6 , V_26 , V_2 ,
V_13 , V_7 ) ;
} while ( V_25 ++ , V_6 = V_26 , V_6 != V_12 );
return V_17 ;
}
static unsigned long F_46 ( struct V_3 * V_4 ,
unsigned long V_6 , unsigned long V_12 , T_1 V_2 ,
int V_13 , int V_7 )
{
struct V_14 * V_15 = V_4 -> V_11 ;
T_7 * V_34 ;
unsigned long V_26 ;
unsigned long V_35 = V_6 ;
unsigned long V_17 = 0 ;
F_47 ( V_6 >= V_12 ) ;
V_34 = F_48 ( V_15 , V_6 ) ;
F_49 ( V_4 , V_6 , V_12 ) ;
F_50 ( V_15 ) ;
do {
V_26 = F_51 ( V_6 , V_12 ) ;
if ( F_52 ( V_34 ) )
continue;
V_17 += F_42 ( V_4 , V_34 , V_6 , V_26 , V_2 ,
V_13 , V_7 ) ;
} while ( V_34 ++ , V_6 = V_26 , V_6 != V_12 );
if ( V_17 )
F_53 ( V_4 , V_35 , V_12 ) ;
F_54 ( V_15 ) ;
return V_17 ;
}
unsigned long F_55 ( struct V_3 * V_4 , unsigned long V_35 ,
unsigned long V_12 , T_1 V_2 ,
int V_13 , int V_7 )
{
unsigned long V_17 ;
if ( F_56 ( V_4 ) )
V_17 = F_57 ( V_4 , V_35 , V_12 , V_2 ) ;
else
V_17 = F_46 ( V_4 , V_35 , V_12 , V_2 , V_13 , V_7 ) ;
return V_17 ;
}
int
F_58 ( struct V_3 * V_4 , struct V_3 * * V_36 ,
unsigned long V_35 , unsigned long V_12 , unsigned long V_37 )
{
struct V_14 * V_15 = V_4 -> V_11 ;
unsigned long V_38 = V_4 -> V_39 ;
long V_40 = ( V_12 - V_35 ) >> V_41 ;
unsigned long V_42 = 0 ;
T_8 V_43 ;
int error ;
int V_13 = 0 ;
if ( V_37 == V_38 ) {
* V_36 = V_4 ;
return 0 ;
}
if ( V_37 & V_44 ) {
if ( ! ( V_38 & ( V_45 | V_44 | V_46 |
V_47 | V_48 ) ) ) {
V_42 = V_40 ;
if ( F_59 ( V_15 , V_42 ) )
return - V_49 ;
V_37 |= V_45 ;
}
}
V_43 = V_4 -> V_50 + ( ( V_35 - V_4 -> V_51 ) >> V_41 ) ;
* V_36 = F_60 ( V_15 , * V_36 , V_35 , V_12 , V_37 ,
V_4 -> V_52 , V_4 -> V_53 , V_43 , F_61 ( V_4 ) ) ;
if ( * V_36 ) {
V_4 = * V_36 ;
goto V_54;
}
* V_36 = V_4 ;
if ( V_35 != V_4 -> V_51 ) {
error = F_62 ( V_15 , V_4 , V_35 , 1 ) ;
if ( error )
goto V_55;
}
if ( V_12 != V_4 -> V_56 ) {
error = F_62 ( V_15 , V_4 , V_12 , 0 ) ;
if ( error )
goto V_55;
}
V_54:
V_4 -> V_39 = V_37 ;
V_4 -> V_57 = F_1 ( V_4 -> V_57 ,
F_63 ( V_37 ) ) ;
if ( F_64 ( V_4 ) ) {
V_4 -> V_57 = F_63 ( V_37 & ~ V_47 ) ;
V_13 = 1 ;
}
F_55 ( V_4 , V_35 , V_12 , V_4 -> V_57 ,
V_13 , 0 ) ;
F_65 ( V_15 , V_38 , V_4 -> V_53 , - V_40 ) ;
F_65 ( V_15 , V_37 , V_4 -> V_53 , V_40 ) ;
F_66 ( V_4 ) ;
return 0 ;
V_55:
F_67 ( V_42 ) ;
return error ;
}
