static int F_1 ( struct V_1 * * V_2 ,
unsigned V_3 ,
T_1 V_4 ,
struct V_5 * V_6 ,
int V_7 )
{
while ( V_4 && F_2 ( V_6 ) ) {
struct V_1 * V_1 = * V_2 ++ ;
T_1 V_8 = V_9 - V_3 ;
T_1 V_10 ;
if ( V_8 > V_4 )
V_8 = V_4 ;
if ( V_7 ) {
if ( V_8 > F_2 ( V_6 ) )
V_8 = F_2 ( V_6 ) ;
V_10 = F_3 ( V_1 , V_6 ,
V_3 , V_8 ) ;
F_4 ( V_6 , V_10 ) ;
F_5 ( V_1 ) ;
} else {
V_10 = F_6 ( V_1 , V_3 , V_8 , V_6 ) ;
}
V_4 -= V_10 ;
if ( V_10 < V_8 && F_2 ( V_6 ) )
return - V_11 ;
V_3 = 0 ;
}
return 0 ;
}
static int F_7 ( unsigned long V_12 ,
unsigned long V_4 ,
struct V_5 * V_6 ,
struct V_1 * * V_13 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
int V_7 )
{
unsigned long V_18 = V_12 & V_19 ;
unsigned long V_20 = V_12 - V_18 ;
unsigned long V_21 ;
T_2 V_22 = 0 ;
unsigned long V_23 = V_24
/ sizeof( struct V_2 * ) ;
if ( V_4 == 0 )
return 0 ;
V_21 = ( V_12 + V_4 - 1 ) / V_9 - V_12 / V_9 + 1 ;
while ( ! V_22 && V_21 && F_2 ( V_6 ) ) {
int V_2 = F_8 ( V_21 , V_23 ) ;
T_1 V_25 ;
F_9 ( & V_15 -> V_26 ) ;
V_2 = F_10 ( V_17 , V_15 , V_18 , V_2 ,
V_7 , 0 , V_13 , NULL ) ;
F_11 ( & V_15 -> V_26 ) ;
if ( V_2 <= 0 )
return - V_11 ;
V_25 = V_2 * V_9 - V_20 ;
if ( V_25 > V_4 )
V_25 = V_4 ;
V_22 = F_1 ( V_13 ,
V_20 , V_25 , V_6 ,
V_7 ) ;
V_4 -= V_25 ;
V_20 = 0 ;
V_21 -= V_2 ;
V_18 += V_2 * V_9 ;
while ( V_2 )
F_12 ( V_13 [ -- V_2 ] ) ;
}
return V_22 ;
}
static T_2 F_13 ( T_3 V_27 , struct V_5 * V_6 ,
const struct V_28 * V_29 ,
unsigned long V_30 ,
unsigned long V_31 , int V_7 )
{
struct V_16 * V_17 ;
struct V_1 * V_32 [ V_33 ] ;
struct V_1 * * V_13 = V_32 ;
struct V_14 * V_15 ;
unsigned long V_34 ;
T_2 V_22 = 0 ;
unsigned long V_21 = 0 ;
unsigned long V_35 ;
T_2 V_36 ;
T_1 V_37 = F_2 ( V_6 ) ;
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
V_36 = V_29 [ V_34 ] . V_36 ;
if ( V_36 > 0 ) {
V_35 = ( ( unsigned long ) V_29 [ V_34 ] . V_38
+ V_36 )
/ V_9 - ( unsigned long ) V_29 [ V_34 ] . V_38
/ V_9 + 1 ;
V_21 = F_14 ( V_21 , V_35 ) ;
}
}
if ( V_21 == 0 )
return 0 ;
if ( V_21 > V_33 ) {
V_13 = F_15 ( F_16 ( T_1 , V_24 ,
sizeof( struct V_2 * ) * V_21 ) ,
V_39 ) ;
if ( ! V_13 )
return - V_40 ;
}
F_17 () ;
V_17 = F_18 ( V_27 ) ;
if ( V_17 )
F_19 ( V_17 ) ;
F_20 () ;
if ( ! V_17 ) {
V_22 = - V_41 ;
goto V_42;
}
V_15 = F_21 ( V_17 , V_43 ) ;
if ( ! V_15 || F_22 ( V_15 ) ) {
V_22 = F_22 ( V_15 ) ? F_23 ( V_15 ) : - V_41 ;
if ( V_22 == - V_44 )
V_22 = - V_45 ;
goto V_46;
}
for ( V_34 = 0 ; V_34 < V_30 && F_2 ( V_6 ) && ! V_22 ; V_34 ++ )
V_22 = F_7 (
( unsigned long ) V_29 [ V_34 ] . V_38 , V_29 [ V_34 ] . V_36 ,
V_6 , V_13 , V_15 , V_17 , V_7 ) ;
V_37 -= F_2 ( V_6 ) ;
if ( V_37 )
V_22 = V_37 ;
F_24 ( V_15 ) ;
V_46:
V_46 ( V_17 ) ;
V_42:
if ( V_13 != V_32 )
F_25 ( V_13 ) ;
return V_22 ;
}
static T_2 F_26 ( T_3 V_27 ,
const struct V_28 T_4 * V_47 ,
unsigned long V_48 ,
const struct V_28 T_4 * V_29 ,
unsigned long V_30 ,
unsigned long V_31 , int V_7 )
{
struct V_28 V_49 [ V_50 ] ;
struct V_28 V_51 [ V_50 ] ;
struct V_28 * V_52 = V_49 ;
struct V_28 * V_53 = V_51 ;
struct V_5 V_6 ;
T_2 V_22 ;
if ( V_31 != 0 )
return - V_54 ;
if ( V_7 )
V_22 = F_27 ( V_55 , V_47 , V_48 , V_50 ,
V_49 , & V_52 ) ;
else
V_22 = F_27 ( V_56 , V_47 , V_48 , V_50 ,
V_49 , & V_52 ) ;
if ( V_22 <= 0 )
goto V_57;
F_28 ( & V_6 , V_52 , V_48 , V_22 , 0 ) ;
V_22 = F_27 ( V_58 , V_29 , V_30 , V_50 ,
V_51 , & V_53 ) ;
if ( V_22 <= 0 )
goto V_57;
V_22 = F_13 ( V_27 , & V_6 , V_53 , V_30 , V_31 , V_7 ) ;
V_57:
if ( V_53 != V_51 )
F_25 ( V_53 ) ;
if ( V_52 != V_49 )
F_25 ( V_52 ) ;
return V_22 ;
}
static T_2
F_29 ( T_5 V_27 ,
const struct V_59 T_4 * V_47 ,
unsigned long V_48 ,
const struct V_59 T_4 * V_29 ,
unsigned long V_30 ,
unsigned long V_31 , int V_7 )
{
struct V_28 V_49 [ V_50 ] ;
struct V_28 V_51 [ V_50 ] ;
struct V_28 * V_52 = V_49 ;
struct V_28 * V_53 = V_51 ;
struct V_5 V_6 ;
T_2 V_22 = - V_11 ;
if ( V_31 != 0 )
return - V_54 ;
if ( V_7 )
V_22 = F_30 ( V_55 , V_47 , V_48 ,
V_50 , V_49 ,
& V_52 ) ;
else
V_22 = F_30 ( V_56 , V_47 , V_48 ,
V_50 , V_49 ,
& V_52 ) ;
if ( V_22 <= 0 )
goto V_57;
F_28 ( & V_6 , V_52 , V_48 , V_22 , 0 ) ;
V_22 = F_30 ( V_58 , V_29 , V_30 ,
V_50 , V_51 ,
& V_53 ) ;
if ( V_22 <= 0 )
goto V_57;
V_22 = F_13 ( V_27 , & V_6 , V_53 , V_30 , V_31 , V_7 ) ;
V_57:
if ( V_53 != V_51 )
F_25 ( V_53 ) ;
if ( V_52 != V_49 )
F_25 ( V_52 ) ;
return V_22 ;
}
