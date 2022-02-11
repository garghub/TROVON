static T_1 * F_1 ( struct V_1 * V_2 , T_2 * V_3 ,
unsigned long V_4 , int V_5 , T_3 * * V_6 )
{
T_1 * V_7 ;
T_3 * V_8 ;
if ( ! V_5 )
return F_2 ( V_2 -> V_9 , V_3 , V_4 , V_6 ) ;
V_8 = F_3 ( V_2 -> V_9 , V_3 ) ;
if ( F_4 ( F_5 ( * V_3 ) || F_6 ( * V_3 ) ) ) {
F_7 ( V_8 ) ;
return NULL ;
}
V_7 = F_2 ( V_2 -> V_9 , V_3 , V_4 , V_6 ) ;
F_7 ( V_8 ) ;
return V_7 ;
}
static unsigned long F_8 ( struct V_1 * V_2 , T_2 * V_3 ,
unsigned long V_4 , unsigned long V_10 , T_4 V_11 ,
int V_12 , int V_5 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
T_1 * V_7 , V_15 ;
T_3 * V_6 ;
unsigned long V_16 = 0 ;
V_7 = F_1 ( V_2 , V_3 , V_4 , V_5 , & V_6 ) ;
if ( ! V_7 )
return 0 ;
F_9 () ;
do {
V_15 = * V_7 ;
if ( F_10 ( V_15 ) ) {
T_1 V_17 ;
bool V_18 = V_5 && F_11 ( V_15 ) ;
if ( V_5 ) {
struct V_19 * V_19 ;
V_19 = F_12 ( V_2 , V_4 , V_15 ) ;
if ( ! V_19 || F_13 ( V_19 ) )
continue;
if ( F_14 ( V_15 ) )
continue;
}
V_17 = F_15 ( V_14 , V_4 , V_7 ) ;
V_17 = F_16 ( V_17 , V_11 ) ;
if ( V_18 )
V_17 = F_17 ( V_17 ) ;
if ( V_12 && F_18 ( V_17 ) &&
( F_19 ( V_17 ) ||
! ( V_2 -> V_20 & V_21 ) ) ) {
V_17 = F_17 ( V_17 ) ;
}
F_20 ( V_14 , V_4 , V_7 , V_17 ) ;
V_16 ++ ;
} else if ( F_21 ( V_22 ) ) {
T_5 V_23 = F_22 ( V_15 ) ;
if ( F_23 ( V_23 ) ) {
T_1 V_24 ;
F_24 ( & V_23 ) ;
V_24 = F_25 ( V_23 ) ;
if ( F_26 ( V_15 ) )
V_24 = F_27 ( V_24 ) ;
F_28 ( V_14 , V_4 , V_7 , V_24 ) ;
V_16 ++ ;
}
}
} while ( V_7 ++ , V_4 += V_25 , V_4 != V_10 );
F_29 () ;
F_30 ( V_7 - 1 , V_6 ) ;
return V_16 ;
}
static inline unsigned long F_31 ( struct V_1 * V_2 ,
T_6 * V_26 , unsigned long V_4 , unsigned long V_10 ,
T_4 V_11 , int V_12 , int V_5 )
{
T_2 * V_3 ;
struct V_13 * V_14 = V_2 -> V_9 ;
unsigned long V_27 ;
unsigned long V_16 = 0 ;
unsigned long V_28 = 0 ;
unsigned long V_29 = 0 ;
V_3 = F_32 ( V_26 , V_4 ) ;
do {
unsigned long V_30 ;
V_27 = F_33 ( V_4 , V_10 ) ;
if ( ! F_5 ( * V_3 ) && F_34 ( V_3 ) )
continue;
if ( ! V_29 ) {
V_29 = V_4 ;
F_35 ( V_14 , V_29 , V_10 ) ;
}
if ( F_5 ( * V_3 ) ) {
if ( V_27 - V_4 != V_31 )
F_36 ( V_2 , V_4 , V_3 ) ;
else {
int V_32 = F_37 ( V_2 , V_3 , V_4 ,
V_11 , V_5 ) ;
if ( V_32 ) {
if ( V_32 == V_33 ) {
V_16 += V_33 ;
V_28 ++ ;
}
continue;
}
}
}
V_30 = F_8 ( V_2 , V_3 , V_4 , V_27 , V_11 ,
V_12 , V_5 ) ;
V_16 += V_30 ;
} while ( V_3 ++ , V_4 = V_27 , V_4 != V_10 );
if ( V_29 )
F_38 ( V_14 , V_29 , V_10 ) ;
if ( V_28 )
F_39 ( V_34 , V_28 ) ;
return V_16 ;
}
static inline unsigned long F_40 ( struct V_1 * V_2 ,
T_7 * V_35 , unsigned long V_4 , unsigned long V_10 ,
T_4 V_11 , int V_12 , int V_5 )
{
T_6 * V_26 ;
unsigned long V_27 ;
unsigned long V_16 = 0 ;
V_26 = F_41 ( V_35 , V_4 ) ;
do {
V_27 = F_42 ( V_4 , V_10 ) ;
if ( F_43 ( V_26 ) )
continue;
V_16 += F_31 ( V_2 , V_26 , V_4 , V_27 , V_11 ,
V_12 , V_5 ) ;
} while ( V_26 ++ , V_4 = V_27 , V_4 != V_10 );
return V_16 ;
}
static unsigned long F_44 ( struct V_1 * V_2 ,
unsigned long V_4 , unsigned long V_10 , T_4 V_11 ,
int V_12 , int V_5 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
T_7 * V_35 ;
unsigned long V_27 ;
unsigned long V_36 = V_4 ;
unsigned long V_16 = 0 ;
F_45 ( V_4 >= V_10 ) ;
V_35 = F_46 ( V_14 , V_4 ) ;
F_47 ( V_2 , V_4 , V_10 ) ;
F_48 ( V_14 ) ;
do {
V_27 = F_49 ( V_4 , V_10 ) ;
if ( F_50 ( V_35 ) )
continue;
V_16 += F_40 ( V_2 , V_35 , V_4 , V_27 , V_11 ,
V_12 , V_5 ) ;
} while ( V_35 ++ , V_4 = V_27 , V_4 != V_10 );
if ( V_16 )
F_51 ( V_2 , V_36 , V_10 ) ;
F_52 ( V_14 ) ;
return V_16 ;
}
unsigned long F_53 ( struct V_1 * V_2 , unsigned long V_36 ,
unsigned long V_10 , T_4 V_11 ,
int V_12 , int V_5 )
{
unsigned long V_16 ;
if ( F_54 ( V_2 ) )
V_16 = F_55 ( V_2 , V_36 , V_10 , V_11 ) ;
else
V_16 = F_44 ( V_2 , V_36 , V_10 , V_11 , V_12 , V_5 ) ;
return V_16 ;
}
int
F_56 ( struct V_1 * V_2 , struct V_1 * * V_37 ,
unsigned long V_36 , unsigned long V_10 , unsigned long V_38 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
unsigned long V_39 = V_2 -> V_20 ;
long V_40 = ( V_10 - V_36 ) >> V_41 ;
unsigned long V_42 = 0 ;
T_8 V_43 ;
int error ;
int V_12 = 0 ;
if ( V_38 == V_39 ) {
* V_37 = V_2 ;
return 0 ;
}
if ( V_38 & V_44 ) {
if ( ! ( V_39 & ( V_45 | V_44 | V_46 |
V_47 | V_48 ) ) ) {
V_42 = V_40 ;
if ( F_57 ( V_14 , V_42 ) )
return - V_49 ;
V_38 |= V_45 ;
}
}
V_43 = V_2 -> V_50 + ( ( V_36 - V_2 -> V_51 ) >> V_41 ) ;
* V_37 = F_58 ( V_14 , * V_37 , V_36 , V_10 , V_38 ,
V_2 -> V_52 , V_2 -> V_53 , V_43 , F_59 ( V_2 ) ) ;
if ( * V_37 ) {
V_2 = * V_37 ;
goto V_54;
}
* V_37 = V_2 ;
if ( V_36 != V_2 -> V_51 ) {
error = F_60 ( V_14 , V_2 , V_36 , 1 ) ;
if ( error )
goto V_55;
}
if ( V_10 != V_2 -> V_56 ) {
error = F_60 ( V_14 , V_2 , V_10 , 0 ) ;
if ( error )
goto V_55;
}
V_54:
V_2 -> V_20 = V_38 ;
V_12 = F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
F_53 ( V_2 , V_36 , V_10 , V_2 -> V_57 ,
V_12 , 0 ) ;
F_63 ( V_14 , V_39 , V_2 -> V_53 , - V_40 ) ;
F_63 ( V_14 , V_38 , V_2 -> V_53 , V_40 ) ;
F_64 ( V_2 ) ;
return 0 ;
V_55:
F_65 ( V_42 ) ;
return error ;
}
