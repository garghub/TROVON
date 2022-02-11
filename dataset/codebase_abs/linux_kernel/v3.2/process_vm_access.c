static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 ,
unsigned long V_7 ,
unsigned long V_8 ,
unsigned long V_9 ,
const struct V_10 * V_11 ,
unsigned long V_12 ,
unsigned long * V_13 ,
T_1 * V_14 ,
int V_15 ,
unsigned int V_16 ,
T_2 * V_17 )
{
int V_18 ;
void * V_19 ;
int V_20 = 0 ;
int V_21 ;
int V_22 ;
T_2 V_23 ;
T_2 V_24 = 0 ;
* V_17 = 0 ;
F_2 ( & V_4 -> V_25 ) ;
V_18 = F_3 ( V_2 , V_4 , V_7 ,
V_16 ,
V_15 , 0 , V_6 , NULL ) ;
F_4 ( & V_4 -> V_25 ) ;
if ( V_18 != V_16 ) {
V_24 = - V_26 ;
goto V_27;
}
for ( V_20 = 0 ;
( V_20 < V_16 ) && ( * V_13 < V_12 ) ;
V_20 ++ ) {
while ( * V_13 < V_12
&& V_11 [ * V_13 ] . V_28 == 0 )
( * V_13 ) ++ ;
if ( * V_13 == V_12 )
break;
V_23 = F_5 ( T_2 , V_29 - V_8 ,
V_9 - * V_17 ) ;
V_23 = F_5 ( T_2 , V_23 ,
V_11 [ * V_13 ] . V_28
- * V_14 ) ;
V_19 = F_6 ( V_6 [ V_20 ] ) + V_8 ;
if ( V_15 )
V_22 = F_7 ( V_19 ,
V_11 [ * V_13 ] . V_30
+ * V_14 ,
V_23 ) ;
else
V_22 = F_8 ( V_11 [ * V_13 ] . V_30
+ * V_14 ,
V_19 , V_23 ) ;
F_9 ( V_6 [ V_20 ] ) ;
if ( V_22 ) {
* V_17 += V_23 - V_22 ;
V_20 ++ ;
V_24 = - V_26 ;
goto V_27;
}
* V_17 += V_23 ;
* V_14 += V_23 ;
if ( * V_14 == V_11 [ * V_13 ] . V_28 ) {
( * V_13 ) ++ ;
* V_14 = 0 ;
V_8 = ( V_8 + V_23 )
% V_29 ;
if ( V_8 )
V_20 -- ;
} else {
V_8 = 0 ;
}
}
V_27:
if ( V_15 ) {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ ) {
if ( V_21 < V_20 )
F_10 ( V_6 [ V_21 ] ) ;
F_11 ( V_6 [ V_21 ] ) ;
}
} else {
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
F_11 ( V_6 [ V_21 ] ) ;
}
return V_24 ;
}
static int F_12 ( unsigned long V_31 ,
unsigned long V_9 ,
const struct V_10 * V_11 ,
unsigned long V_12 ,
unsigned long * V_13 ,
T_1 * V_14 ,
struct V_5 * * V_6 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_15 ,
T_2 * V_17 )
{
unsigned long V_7 = V_31 & V_32 ;
unsigned long V_8 = V_31 - V_7 ;
unsigned long V_33 ;
T_2 V_34 ;
T_2 V_24 = 0 ;
unsigned long V_35 = 0 ;
unsigned long V_16 ;
unsigned long V_36 = V_37
/ sizeof( struct V_38 * ) ;
* V_17 = 0 ;
if ( V_9 == 0 )
return 0 ;
V_33 = ( V_31 + V_9 - 1 ) / V_29 - V_31 / V_29 + 1 ;
while ( ( V_35 < V_33 ) && ( * V_13 < V_12 ) ) {
V_16 = F_13 ( V_33 - V_35 ,
V_36 ) ;
V_24 = F_1 ( V_2 , V_4 , V_6 , V_7 ,
V_8 , V_9 ,
V_11 , V_12 ,
V_13 , V_14 ,
V_15 , V_16 ,
& V_34 ) ;
V_8 = 0 ;
* V_17 += V_34 ;
if ( V_24 < 0 ) {
return V_24 ;
} else {
V_9 -= V_34 ;
V_35 += V_16 ;
V_7 += V_16 * V_29 ;
}
}
return V_24 ;
}
static T_2 F_14 ( T_3 V_39 , const struct V_10 * V_11 ,
unsigned long V_40 ,
const struct V_10 * V_41 ,
unsigned long V_42 ,
unsigned long V_43 , int V_15 )
{
struct V_1 * V_2 ;
struct V_5 * V_44 [ V_45 ] ;
struct V_5 * * V_6 = V_44 ;
struct V_3 * V_4 ;
unsigned long V_46 ;
T_2 V_24 = 0 ;
T_2 V_34 ;
T_2 V_17 = 0 ;
unsigned long V_33 = 0 ;
unsigned long V_47 ;
unsigned long V_48 = 0 ;
T_1 V_49 = 0 ;
T_2 V_28 ;
for ( V_46 = 0 ; V_46 < V_42 ; V_46 ++ ) {
V_28 = V_41 [ V_46 ] . V_28 ;
if ( V_28 > 0 ) {
V_47 = ( ( unsigned long ) V_41 [ V_46 ] . V_30
+ V_28 )
/ V_29 - ( unsigned long ) V_41 [ V_46 ] . V_30
/ V_29 + 1 ;
V_33 = F_15 ( V_33 , V_47 ) ;
}
}
if ( V_33 == 0 )
return 0 ;
if ( V_33 > V_45 ) {
V_6 = F_16 ( F_5 ( T_1 , V_37 ,
sizeof( struct V_38 * ) * V_33 ) ,
V_50 ) ;
if ( ! V_6 )
return - V_51 ;
}
F_17 () ;
V_2 = F_18 ( V_39 ) ;
if ( V_2 )
F_19 ( V_2 ) ;
F_20 () ;
if ( ! V_2 ) {
V_24 = - V_52 ;
goto V_53;
}
F_21 ( V_2 ) ;
if ( F_22 ( V_2 , V_54 ) ) {
F_23 ( V_2 ) ;
V_24 = - V_55 ;
goto V_56;
}
V_4 = V_2 -> V_4 ;
if ( ! V_4 || ( V_2 -> V_43 & V_57 ) ) {
F_23 ( V_2 ) ;
V_24 = - V_58 ;
goto V_56;
}
F_24 ( & V_4 -> V_59 ) ;
F_23 ( V_2 ) ;
for ( V_46 = 0 ; V_46 < V_42 && V_48 < V_40 ; V_46 ++ ) {
V_24 = F_12 (
( unsigned long ) V_41 [ V_46 ] . V_30 , V_41 [ V_46 ] . V_28 ,
V_11 , V_40 , & V_48 , & V_49 ,
V_6 , V_4 , V_2 , V_15 , & V_34 ) ;
V_17 += V_34 ;
if ( V_24 != 0 ) {
if ( V_17 )
V_24 = V_17 ;
goto V_60;
}
}
V_24 = V_17 ;
V_60:
F_25 ( V_4 ) ;
V_56:
V_56 ( V_2 ) ;
V_53:
if ( V_6 != V_44 )
F_26 ( V_6 ) ;
return V_24 ;
}
static T_2 F_27 ( T_3 V_39 ,
const struct V_10 T_4 * V_11 ,
unsigned long V_40 ,
const struct V_10 T_4 * V_41 ,
unsigned long V_42 ,
unsigned long V_43 , int V_15 )
{
struct V_10 V_61 [ V_62 ] ;
struct V_10 V_63 [ V_62 ] ;
struct V_10 * V_64 = V_61 ;
struct V_10 * V_65 = V_63 ;
T_2 V_24 ;
if ( V_43 != 0 )
return - V_58 ;
if ( V_15 )
V_24 = F_28 ( V_66 , V_11 , V_40 , V_62 ,
V_61 , & V_64 , 1 ) ;
else
V_24 = F_28 ( V_67 , V_11 , V_40 , V_62 ,
V_61 , & V_64 , 1 ) ;
if ( V_24 <= 0 )
goto V_68;
V_24 = F_28 ( V_67 , V_41 , V_42 , V_62 ,
V_63 , & V_65 , 0 ) ;
if ( V_24 <= 0 )
goto V_68;
V_24 = F_14 ( V_39 , V_64 , V_40 , V_65 , V_42 , V_43 ,
V_15 ) ;
V_68:
if ( V_65 != V_63 )
F_26 ( V_65 ) ;
if ( V_64 != V_61 )
F_26 ( V_64 ) ;
return V_24 ;
}
T_5 T_2
F_29 ( T_6 V_39 ,
const struct V_69 T_4 * V_11 ,
unsigned long V_40 ,
const struct V_69 T_4 * V_41 ,
unsigned long V_42 ,
unsigned long V_43 , int V_15 )
{
struct V_10 V_61 [ V_62 ] ;
struct V_10 V_63 [ V_62 ] ;
struct V_10 * V_64 = V_61 ;
struct V_10 * V_65 = V_63 ;
T_2 V_24 = - V_26 ;
if ( V_43 != 0 )
return - V_58 ;
if ( ! F_30 ( V_70 , V_11 , V_40 * sizeof( * V_11 ) ) )
goto V_71;
if ( ! F_30 ( V_70 , V_41 , V_42 * sizeof( * V_41 ) ) )
goto V_71;
if ( V_15 )
V_24 = F_31 ( V_66 , V_11 , V_40 ,
V_62 , V_61 ,
& V_64 , 1 ) ;
else
V_24 = F_31 ( V_67 , V_11 , V_40 ,
V_62 , V_61 ,
& V_64 , 1 ) ;
if ( V_24 <= 0 )
goto V_68;
V_24 = F_31 ( V_67 , V_41 , V_42 ,
V_62 , V_63 ,
& V_65 , 0 ) ;
if ( V_24 <= 0 )
goto V_68;
V_24 = F_14 ( V_39 , V_64 , V_40 , V_65 , V_42 , V_43 ,
V_15 ) ;
V_68:
if ( V_65 != V_63 )
F_26 ( V_65 ) ;
if ( V_64 != V_61 )
F_26 ( V_64 ) ;
V_71:
return V_24 ;
}
T_5 T_2
F_32 ( T_6 V_39 ,
const struct V_69 T_4 * V_11 ,
unsigned long V_40 ,
const struct V_69 T_4 * V_41 ,
unsigned long V_42 ,
unsigned long V_43 )
{
return F_29 ( V_39 , V_11 , V_40 , V_41 ,
V_42 , V_43 , 0 ) ;
}
T_5 T_2
F_33 ( T_6 V_39 ,
const struct V_69 T_4 * V_11 ,
unsigned long V_40 ,
const struct V_69 T_4 * V_41 ,
unsigned long V_42 ,
unsigned long V_43 )
{
return F_29 ( V_39 , V_11 , V_40 , V_41 ,
V_42 , V_43 , 1 ) ;
}
