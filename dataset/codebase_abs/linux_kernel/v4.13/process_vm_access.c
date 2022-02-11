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
unsigned int V_25 = 0 ;
if ( V_4 == 0 )
return 0 ;
V_21 = ( V_12 + V_4 - 1 ) / V_9 - V_12 / V_9 + 1 ;
if ( V_7 )
V_25 |= V_26 ;
while ( ! V_22 && V_21 && F_2 ( V_6 ) ) {
int V_2 = F_7 ( V_21 , V_23 ) ;
int V_27 = 1 ;
T_1 V_28 ;
F_8 ( & V_15 -> V_29 ) ;
V_2 = F_9 ( V_17 , V_15 , V_18 , V_2 , V_25 ,
V_13 , NULL , & V_27 ) ;
if ( V_27 )
F_10 ( & V_15 -> V_29 ) ;
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
F_11 ( V_13 [ -- V_2 ] ) ;
}
return V_22 ;
}
static T_2 F_12 ( T_3 V_30 , struct V_5 * V_6 ,
const struct V_31 * V_32 ,
unsigned long V_33 ,
unsigned long V_25 , int V_7 )
{
struct V_16 * V_17 ;
struct V_1 * V_34 [ V_35 ] ;
struct V_1 * * V_13 = V_34 ;
struct V_14 * V_15 ;
unsigned long V_36 ;
T_2 V_22 = 0 ;
unsigned long V_21 = 0 ;
unsigned long V_37 ;
T_2 V_38 ;
T_1 V_39 = F_2 ( V_6 ) ;
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ ) {
V_38 = V_32 [ V_36 ] . V_38 ;
if ( V_38 > 0 ) {
V_37 = ( ( unsigned long ) V_32 [ V_36 ] . V_40
+ V_38 )
/ V_9 - ( unsigned long ) V_32 [ V_36 ] . V_40
/ V_9 + 1 ;
V_21 = F_13 ( V_21 , V_37 ) ;
}
}
if ( V_21 == 0 )
return 0 ;
if ( V_21 > V_35 ) {
V_13 = F_14 ( F_15 ( T_1 , V_24 ,
sizeof( struct V_2 * ) * V_21 ) ,
V_41 ) ;
if ( ! V_13 )
return - V_42 ;
}
F_16 () ;
V_17 = F_17 ( V_30 ) ;
if ( V_17 )
F_18 ( V_17 ) ;
F_19 () ;
if ( ! V_17 ) {
V_22 = - V_43 ;
goto V_44;
}
V_15 = F_20 ( V_17 , V_45 ) ;
if ( ! V_15 || F_21 ( V_15 ) ) {
V_22 = F_21 ( V_15 ) ? F_22 ( V_15 ) : - V_43 ;
if ( V_22 == - V_46 )
V_22 = - V_47 ;
goto V_48;
}
for ( V_36 = 0 ; V_36 < V_33 && F_2 ( V_6 ) && ! V_22 ; V_36 ++ )
V_22 = F_6 (
( unsigned long ) V_32 [ V_36 ] . V_40 , V_32 [ V_36 ] . V_38 ,
V_6 , V_13 , V_15 , V_17 , V_7 ) ;
V_39 -= F_2 ( V_6 ) ;
if ( V_39 )
V_22 = V_39 ;
F_23 ( V_15 ) ;
V_48:
V_48 ( V_17 ) ;
V_44:
if ( V_13 != V_34 )
F_24 ( V_13 ) ;
return V_22 ;
}
static T_2 F_25 ( T_3 V_30 ,
const struct V_31 T_4 * V_49 ,
unsigned long V_50 ,
const struct V_31 T_4 * V_32 ,
unsigned long V_33 ,
unsigned long V_25 , int V_7 )
{
struct V_31 V_51 [ V_52 ] ;
struct V_31 V_53 [ V_52 ] ;
struct V_31 * V_54 = V_51 ;
struct V_31 * V_55 = V_53 ;
struct V_5 V_6 ;
T_2 V_22 ;
int V_56 = V_7 ? V_57 : V_58 ;
if ( V_25 != 0 )
return - V_59 ;
V_22 = F_26 ( V_56 , V_49 , V_50 , V_52 , & V_54 , & V_6 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! F_2 ( & V_6 ) )
goto V_60;
V_22 = F_27 ( V_61 , V_32 , V_33 , V_52 ,
V_53 , & V_55 ) ;
if ( V_22 <= 0 )
goto V_60;
V_22 = F_12 ( V_30 , & V_6 , V_55 , V_33 , V_25 , V_7 ) ;
V_60:
if ( V_55 != V_53 )
F_24 ( V_55 ) ;
F_24 ( V_54 ) ;
return V_22 ;
}
static T_2
F_28 ( T_5 V_30 ,
const struct V_62 T_4 * V_49 ,
unsigned long V_50 ,
const struct V_62 T_4 * V_32 ,
unsigned long V_33 ,
unsigned long V_25 , int V_7 )
{
struct V_31 V_51 [ V_52 ] ;
struct V_31 V_53 [ V_52 ] ;
struct V_31 * V_54 = V_51 ;
struct V_31 * V_55 = V_53 ;
struct V_5 V_6 ;
T_2 V_22 = - V_11 ;
int V_56 = V_7 ? V_57 : V_58 ;
if ( V_25 != 0 )
return - V_59 ;
V_22 = F_29 ( V_56 , V_49 , V_50 , V_52 , & V_54 , & V_6 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! F_2 ( & V_6 ) )
goto V_60;
V_22 = F_30 ( V_61 , V_32 , V_33 ,
V_52 , V_53 ,
& V_55 ) ;
if ( V_22 <= 0 )
goto V_60;
V_22 = F_12 ( V_30 , & V_6 , V_55 , V_33 , V_25 , V_7 ) ;
V_60:
if ( V_55 != V_53 )
F_24 ( V_55 ) ;
F_24 ( V_54 ) ;
return V_22 ;
}
