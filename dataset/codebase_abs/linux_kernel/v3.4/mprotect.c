static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_2 ;
}
static void F_2 ( struct V_3 * V_4 , T_2 * V_5 ,
unsigned long V_6 , unsigned long V_7 , T_1 V_2 ,
int V_8 )
{
T_3 * V_9 , V_10 ;
T_4 * V_11 ;
V_9 = F_3 ( V_4 , V_5 , V_6 , & V_11 ) ;
F_4 () ;
do {
V_10 = * V_9 ;
if ( F_5 ( V_10 ) ) {
T_3 V_12 ;
V_12 = F_6 ( V_4 , V_6 , V_9 ) ;
V_12 = F_7 ( V_12 , V_2 ) ;
if ( V_8 && F_8 ( V_12 ) )
V_12 = F_9 ( V_12 ) ;
F_10 ( V_4 , V_6 , V_9 , V_12 ) ;
} else if ( F_11 ( V_13 ) && ! F_12 ( V_10 ) ) {
T_5 V_14 = F_13 ( V_10 ) ;
if ( F_14 ( V_14 ) ) {
F_15 ( & V_14 ) ;
F_16 ( V_4 , V_6 , V_9 ,
F_17 ( V_14 ) ) ;
}
}
} while ( V_9 ++ , V_6 += V_15 , V_6 != V_7 );
F_18 () ;
F_19 ( V_9 - 1 , V_11 ) ;
}
static inline void F_20 ( struct V_16 * V_17 , T_6 * V_18 ,
unsigned long V_6 , unsigned long V_7 , T_1 V_2 ,
int V_8 )
{
T_2 * V_5 ;
unsigned long V_19 ;
V_5 = F_21 ( V_18 , V_6 ) ;
do {
V_19 = F_22 ( V_6 , V_7 ) ;
if ( F_23 ( * V_5 ) ) {
if ( V_19 - V_6 != V_20 )
F_24 ( V_17 -> V_21 , V_5 ) ;
else if ( F_25 ( V_17 , V_5 , V_6 , V_2 ) )
continue;
}
if ( F_26 ( V_5 ) )
continue;
F_2 ( V_17 -> V_21 , V_5 , V_6 , V_19 , V_2 ,
V_8 ) ;
} while ( V_5 ++ , V_6 = V_19 , V_6 != V_7 );
}
static inline void F_27 ( struct V_16 * V_17 , T_7 * V_22 ,
unsigned long V_6 , unsigned long V_7 , T_1 V_2 ,
int V_8 )
{
T_6 * V_18 ;
unsigned long V_19 ;
V_18 = F_28 ( V_22 , V_6 ) ;
do {
V_19 = F_29 ( V_6 , V_7 ) ;
if ( F_30 ( V_18 ) )
continue;
F_20 ( V_17 , V_18 , V_6 , V_19 , V_2 ,
V_8 ) ;
} while ( V_18 ++ , V_6 = V_19 , V_6 != V_7 );
}
static void F_31 ( struct V_16 * V_17 ,
unsigned long V_6 , unsigned long V_7 , T_1 V_2 ,
int V_8 )
{
struct V_3 * V_4 = V_17 -> V_21 ;
T_7 * V_22 ;
unsigned long V_19 ;
unsigned long V_23 = V_6 ;
F_32 ( V_6 >= V_7 ) ;
V_22 = F_33 ( V_4 , V_6 ) ;
F_34 ( V_17 , V_6 , V_7 ) ;
do {
V_19 = F_35 ( V_6 , V_7 ) ;
if ( F_36 ( V_22 ) )
continue;
F_27 ( V_17 , V_22 , V_6 , V_19 , V_2 ,
V_8 ) ;
} while ( V_22 ++ , V_6 = V_19 , V_6 != V_7 );
F_37 ( V_17 , V_23 , V_7 ) ;
}
int
F_38 ( struct V_16 * V_17 , struct V_16 * * V_24 ,
unsigned long V_23 , unsigned long V_7 , unsigned long V_25 )
{
struct V_3 * V_4 = V_17 -> V_21 ;
unsigned long V_26 = V_17 -> V_27 ;
long V_28 = ( V_7 - V_23 ) >> V_29 ;
unsigned long V_30 = 0 ;
T_8 V_31 ;
int error ;
int V_8 = 0 ;
if ( V_25 == V_26 ) {
* V_24 = V_17 ;
return 0 ;
}
if ( V_25 & V_32 ) {
if ( ! ( V_26 & ( V_33 | V_32 | V_34 |
V_35 | V_36 ) ) ) {
V_30 = V_28 ;
if ( F_39 ( V_4 , V_30 ) )
return - V_37 ;
V_25 |= V_33 ;
}
}
V_31 = V_17 -> V_38 + ( ( V_23 - V_17 -> V_39 ) >> V_29 ) ;
* V_24 = F_40 ( V_4 , * V_24 , V_23 , V_7 , V_25 ,
V_17 -> V_40 , V_17 -> V_41 , V_31 , F_41 ( V_17 ) ) ;
if ( * V_24 ) {
V_17 = * V_24 ;
goto V_42;
}
* V_24 = V_17 ;
if ( V_23 != V_17 -> V_39 ) {
error = F_42 ( V_4 , V_17 , V_23 , 1 ) ;
if ( error )
goto V_43;
}
if ( V_7 != V_17 -> V_44 ) {
error = F_42 ( V_4 , V_17 , V_7 , 0 ) ;
if ( error )
goto V_43;
}
V_42:
V_17 -> V_27 = V_25 ;
V_17 -> V_45 = F_1 ( V_17 -> V_45 ,
F_43 ( V_25 ) ) ;
if ( F_44 ( V_17 ) ) {
V_17 -> V_45 = F_43 ( V_25 & ~ V_35 ) ;
V_8 = 1 ;
}
F_45 ( V_4 , V_23 , V_7 ) ;
if ( F_46 ( V_17 ) )
F_47 ( V_17 , V_23 , V_7 , V_17 -> V_45 ) ;
else
F_31 ( V_17 , V_23 , V_7 , V_17 -> V_45 , V_8 ) ;
F_48 ( V_4 , V_23 , V_7 ) ;
F_49 ( V_4 , V_26 , V_17 -> V_41 , - V_28 ) ;
F_49 ( V_4 , V_25 , V_17 -> V_41 , V_28 ) ;
F_50 ( V_17 ) ;
return 0 ;
V_43:
F_51 ( V_30 ) ;
return error ;
}
