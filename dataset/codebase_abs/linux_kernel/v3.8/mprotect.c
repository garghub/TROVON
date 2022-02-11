static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_2 ;
}
static unsigned long F_2 ( struct V_3 * V_4 , T_2 * V_5 ,
unsigned long V_6 , unsigned long V_7 , T_1 V_2 ,
int V_8 , int V_9 , bool * V_10 )
{
struct V_11 * V_12 = V_4 -> V_13 ;
T_3 * V_14 , V_15 ;
T_4 * V_16 ;
unsigned long V_17 = 0 ;
bool V_18 = true ;
int V_19 = - 1 ;
V_14 = F_3 ( V_12 , V_5 , V_6 , & V_16 ) ;
F_4 () ;
do {
V_15 = * V_14 ;
if ( F_5 ( V_15 ) ) {
T_3 V_20 ;
bool V_21 = false ;
V_20 = F_6 ( V_12 , V_6 , V_14 ) ;
if ( ! V_9 ) {
V_20 = F_7 ( V_20 , V_2 ) ;
V_21 = true ;
} else {
struct V_22 * V_22 ;
V_22 = F_8 ( V_4 , V_6 , V_15 ) ;
if ( V_22 ) {
int V_23 = F_9 ( V_22 ) ;
if ( V_19 == - 1 )
V_19 = V_23 ;
if ( V_19 != V_23 )
V_18 = false ;
if ( ! F_10 ( V_15 ) &&
F_11 ( V_22 ) == 1 ) {
V_20 = F_12 ( V_20 ) ;
V_21 = true ;
}
}
}
if ( V_8 && F_13 ( V_20 ) ) {
V_20 = F_14 ( V_20 ) ;
V_21 = true ;
}
if ( V_21 )
V_17 ++ ;
F_15 ( V_12 , V_6 , V_14 , V_20 ) ;
} else if ( F_16 ( V_24 ) && ! F_17 ( V_15 ) ) {
T_5 V_25 = F_18 ( V_15 ) ;
if ( F_19 ( V_25 ) ) {
F_20 ( & V_25 ) ;
F_21 ( V_12 , V_6 , V_14 ,
F_22 ( V_25 ) ) ;
}
V_17 ++ ;
}
} while ( V_14 ++ , V_6 += V_26 , V_6 != V_7 );
F_23 () ;
F_24 ( V_14 - 1 , V_16 ) ;
* V_10 = V_18 ;
return V_17 ;
}
static inline void F_25 ( struct V_11 * V_12 , unsigned long V_6 ,
T_2 * V_5 )
{
F_26 ( & V_12 -> V_27 ) ;
F_27 ( V_12 , V_6 & V_28 , V_5 , F_28 ( * V_5 ) ) ;
F_29 ( & V_12 -> V_27 ) ;
}
static inline void F_25 ( struct V_11 * V_12 , unsigned long V_6 ,
T_2 * V_5 )
{
F_30 () ;
}
static inline unsigned long F_31 ( struct V_3 * V_4 ,
T_6 * V_29 , unsigned long V_6 , unsigned long V_7 ,
T_1 V_2 , int V_8 , int V_9 )
{
T_2 * V_5 ;
unsigned long V_30 ;
unsigned long V_17 = 0 ;
bool V_18 ;
V_5 = F_32 ( V_29 , V_6 ) ;
do {
V_30 = F_33 ( V_6 , V_7 ) ;
if ( F_34 ( * V_5 ) ) {
if ( V_30 - V_6 != V_31 )
F_35 ( V_4 , V_6 , V_5 ) ;
else if ( F_36 ( V_4 , V_5 , V_6 , V_2 ,
V_9 ) ) {
V_17 += V_32 ;
continue;
}
}
if ( F_37 ( V_5 ) )
continue;
V_17 += F_2 ( V_4 , V_5 , V_6 , V_30 , V_2 ,
V_8 , V_9 , & V_18 ) ;
if ( V_9 && V_18 )
F_25 ( V_4 -> V_13 , V_6 , V_5 ) ;
} while ( V_5 ++ , V_6 = V_30 , V_6 != V_7 );
return V_17 ;
}
static inline unsigned long F_38 ( struct V_3 * V_4 ,
T_7 * V_33 , unsigned long V_6 , unsigned long V_7 ,
T_1 V_2 , int V_8 , int V_9 )
{
T_6 * V_29 ;
unsigned long V_30 ;
unsigned long V_17 = 0 ;
V_29 = F_39 ( V_33 , V_6 ) ;
do {
V_30 = F_40 ( V_6 , V_7 ) ;
if ( F_41 ( V_29 ) )
continue;
V_17 += F_31 ( V_4 , V_29 , V_6 , V_30 , V_2 ,
V_8 , V_9 ) ;
} while ( V_29 ++ , V_6 = V_30 , V_6 != V_7 );
return V_17 ;
}
static unsigned long F_42 ( struct V_3 * V_4 ,
unsigned long V_6 , unsigned long V_7 , T_1 V_2 ,
int V_8 , int V_9 )
{
struct V_11 * V_12 = V_4 -> V_13 ;
T_7 * V_33 ;
unsigned long V_30 ;
unsigned long V_34 = V_6 ;
unsigned long V_17 = 0 ;
F_43 ( V_6 >= V_7 ) ;
V_33 = F_44 ( V_12 , V_6 ) ;
F_45 ( V_4 , V_6 , V_7 ) ;
do {
V_30 = F_46 ( V_6 , V_7 ) ;
if ( F_47 ( V_33 ) )
continue;
V_17 += F_38 ( V_4 , V_33 , V_6 , V_30 , V_2 ,
V_8 , V_9 ) ;
} while ( V_33 ++ , V_6 = V_30 , V_6 != V_7 );
if ( V_17 )
F_48 ( V_4 , V_34 , V_7 ) ;
return V_17 ;
}
unsigned long F_49 ( struct V_3 * V_4 , unsigned long V_34 ,
unsigned long V_7 , T_1 V_2 ,
int V_8 , int V_9 )
{
struct V_11 * V_12 = V_4 -> V_13 ;
unsigned long V_17 ;
F_50 ( V_12 , V_34 , V_7 ) ;
if ( F_51 ( V_4 ) )
V_17 = F_52 ( V_4 , V_34 , V_7 , V_2 ) ;
else
V_17 = F_42 ( V_4 , V_34 , V_7 , V_2 , V_8 , V_9 ) ;
F_53 ( V_12 , V_34 , V_7 ) ;
return V_17 ;
}
int
F_54 ( struct V_3 * V_4 , struct V_3 * * V_35 ,
unsigned long V_34 , unsigned long V_7 , unsigned long V_36 )
{
struct V_11 * V_12 = V_4 -> V_13 ;
unsigned long V_37 = V_4 -> V_38 ;
long V_39 = ( V_7 - V_34 ) >> V_40 ;
unsigned long V_41 = 0 ;
T_8 V_42 ;
int error ;
int V_8 = 0 ;
if ( V_36 == V_37 ) {
* V_35 = V_4 ;
return 0 ;
}
if ( V_36 & V_43 ) {
if ( ! ( V_37 & ( V_44 | V_43 | V_45 |
V_46 | V_47 ) ) ) {
V_41 = V_39 ;
if ( F_55 ( V_12 , V_41 ) )
return - V_48 ;
V_36 |= V_44 ;
}
}
V_42 = V_4 -> V_49 + ( ( V_34 - V_4 -> V_50 ) >> V_40 ) ;
* V_35 = F_56 ( V_12 , * V_35 , V_34 , V_7 , V_36 ,
V_4 -> V_51 , V_4 -> V_52 , V_42 , F_57 ( V_4 ) ) ;
if ( * V_35 ) {
V_4 = * V_35 ;
goto V_53;
}
* V_35 = V_4 ;
if ( V_34 != V_4 -> V_50 ) {
error = F_58 ( V_12 , V_4 , V_34 , 1 ) ;
if ( error )
goto V_54;
}
if ( V_7 != V_4 -> V_55 ) {
error = F_58 ( V_12 , V_4 , V_7 , 0 ) ;
if ( error )
goto V_54;
}
V_53:
V_4 -> V_38 = V_36 ;
V_4 -> V_56 = F_1 ( V_4 -> V_56 ,
F_59 ( V_36 ) ) ;
if ( F_60 ( V_4 ) ) {
V_4 -> V_56 = F_59 ( V_36 & ~ V_46 ) ;
V_8 = 1 ;
}
F_49 ( V_4 , V_34 , V_7 , V_4 -> V_56 ,
V_8 , 0 ) ;
F_61 ( V_12 , V_37 , V_4 -> V_52 , - V_39 ) ;
F_61 ( V_12 , V_36 , V_4 -> V_52 , V_39 ) ;
F_62 ( V_4 ) ;
return 0 ;
V_54:
F_63 ( V_41 ) ;
return error ;
}
