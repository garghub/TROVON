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
V_10 = F_3 ( V_1 , V_3 , V_8 , V_6 ) ;
F_4 ( V_1 ) ;
} else {
V_10 = F_5 ( V_1 , V_3 , V_8 , V_6 ) ;
}
V_4 -= V_10 ;
if ( V_10 < V_8 && F_2 ( V_6 ) )
return - V_11 ;
V_3 = 0 ;
}
return 0 ;
}
static int F_6 ( unsigned long V_12 ,
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
unsigned int V_25 = V_26 ;
if ( V_4 == 0 )
return 0 ;
V_21 = ( V_12 + V_4 - 1 ) / V_9 - V_12 / V_9 + 1 ;
if ( V_7 )
V_25 |= V_27 ;
while ( ! V_22 && V_21 && F_2 ( V_6 ) ) {
int V_2 = F_7 ( V_21 , V_23 ) ;
T_1 V_28 ;
V_2 = F_8 ( V_17 , V_15 , V_18 , V_2 ,
V_13 , V_25 ) ;
if ( V_2 <= 0 )
return - V_11 ;
V_28 = V_2 * V_9 - V_20 ;
if ( V_28 > V_4 )
V_28 = V_4 ;
V_22 = F_1 ( V_13 ,
V_20 , V_28 , V_6 ,
V_7 ) ;
V_4 -= V_28 ;
V_20 = 0 ;
V_21 -= V_2 ;
V_18 += V_2 * V_9 ;
while ( V_2 )
F_9 ( V_13 [ -- V_2 ] ) ;
}
return V_22 ;
}
static T_2 F_10 ( T_3 V_29 , struct V_5 * V_6 ,
const struct V_30 * V_31 ,
unsigned long V_32 ,
unsigned long V_25 , int V_7 )
{
struct V_16 * V_17 ;
struct V_1 * V_33 [ V_34 ] ;
struct V_1 * * V_13 = V_33 ;
struct V_14 * V_15 ;
unsigned long V_35 ;
T_2 V_22 = 0 ;
unsigned long V_21 = 0 ;
unsigned long V_36 ;
T_2 V_37 ;
T_1 V_38 = F_2 ( V_6 ) ;
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
V_37 = V_31 [ V_35 ] . V_37 ;
if ( V_37 > 0 ) {
V_36 = ( ( unsigned long ) V_31 [ V_35 ] . V_39
+ V_37 )
/ V_9 - ( unsigned long ) V_31 [ V_35 ] . V_39
/ V_9 + 1 ;
V_21 = F_11 ( V_21 , V_36 ) ;
}
}
if ( V_21 == 0 )
return 0 ;
if ( V_21 > V_34 ) {
V_13 = F_12 ( F_13 ( T_1 , V_24 ,
sizeof( struct V_2 * ) * V_21 ) ,
V_40 ) ;
if ( ! V_13 )
return - V_41 ;
}
F_14 () ;
V_17 = F_15 ( V_29 ) ;
if ( V_17 )
F_16 ( V_17 ) ;
F_17 () ;
if ( ! V_17 ) {
V_22 = - V_42 ;
goto V_43;
}
V_15 = F_18 ( V_17 , V_44 ) ;
if ( ! V_15 || F_19 ( V_15 ) ) {
V_22 = F_19 ( V_15 ) ? F_20 ( V_15 ) : - V_42 ;
if ( V_22 == - V_45 )
V_22 = - V_46 ;
goto V_47;
}
for ( V_35 = 0 ; V_35 < V_32 && F_2 ( V_6 ) && ! V_22 ; V_35 ++ )
V_22 = F_6 (
( unsigned long ) V_31 [ V_35 ] . V_39 , V_31 [ V_35 ] . V_37 ,
V_6 , V_13 , V_15 , V_17 , V_7 ) ;
V_38 -= F_2 ( V_6 ) ;
if ( V_38 )
V_22 = V_38 ;
F_21 ( V_15 ) ;
V_47:
V_47 ( V_17 ) ;
V_43:
if ( V_13 != V_33 )
F_22 ( V_13 ) ;
return V_22 ;
}
static T_2 F_23 ( T_3 V_29 ,
const struct V_30 T_4 * V_48 ,
unsigned long V_49 ,
const struct V_30 T_4 * V_31 ,
unsigned long V_32 ,
unsigned long V_25 , int V_7 )
{
struct V_30 V_50 [ V_51 ] ;
struct V_30 V_52 [ V_51 ] ;
struct V_30 * V_53 = V_50 ;
struct V_30 * V_54 = V_52 ;
struct V_5 V_6 ;
T_2 V_22 ;
int V_55 = V_7 ? V_56 : V_57 ;
if ( V_25 != 0 )
return - V_58 ;
V_22 = F_24 ( V_55 , V_48 , V_49 , V_51 , & V_53 , & V_6 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! F_2 ( & V_6 ) )
goto V_59;
V_22 = F_25 ( V_60 , V_31 , V_32 , V_51 ,
V_52 , & V_54 ) ;
if ( V_22 <= 0 )
goto V_59;
V_22 = F_10 ( V_29 , & V_6 , V_54 , V_32 , V_25 , V_7 ) ;
V_59:
if ( V_54 != V_52 )
F_22 ( V_54 ) ;
F_22 ( V_53 ) ;
return V_22 ;
}
static T_2
F_26 ( T_5 V_29 ,
const struct V_61 T_4 * V_48 ,
unsigned long V_49 ,
const struct V_61 T_4 * V_31 ,
unsigned long V_32 ,
unsigned long V_25 , int V_7 )
{
struct V_30 V_50 [ V_51 ] ;
struct V_30 V_52 [ V_51 ] ;
struct V_30 * V_53 = V_50 ;
struct V_30 * V_54 = V_52 ;
struct V_5 V_6 ;
T_2 V_22 = - V_11 ;
int V_55 = V_7 ? V_56 : V_57 ;
if ( V_25 != 0 )
return - V_58 ;
V_22 = F_27 ( V_55 , V_48 , V_49 , V_51 , & V_53 , & V_6 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! F_2 ( & V_6 ) )
goto V_59;
V_22 = F_28 ( V_60 , V_31 , V_32 ,
V_51 , V_52 ,
& V_54 ) ;
if ( V_22 <= 0 )
goto V_59;
V_22 = F_10 ( V_29 , & V_6 , V_54 , V_32 , V_25 , V_7 ) ;
V_59:
if ( V_54 != V_52 )
F_22 ( V_54 ) ;
F_22 ( V_53 ) ;
return V_22 ;
}
