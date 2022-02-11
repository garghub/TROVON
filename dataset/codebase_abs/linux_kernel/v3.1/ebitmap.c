int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
if ( V_2 -> V_7 != V_3 -> V_7 )
return 0 ;
V_5 = V_2 -> V_8 ;
V_6 = V_3 -> V_8 ;
while ( V_5 && V_6 &&
( V_5 -> V_9 == V_6 -> V_9 ) &&
! memcmp ( V_5 -> V_10 , V_6 -> V_10 , V_11 / 8 ) ) {
V_5 = V_5 -> V_12 ;
V_6 = V_6 -> V_12 ;
}
if ( V_5 || V_6 )
return 0 ;
return 1 ;
}
int F_2 ( struct V_1 * V_13 , struct V_1 * V_14 )
{
struct V_4 * V_15 , * V_16 , * V_17 ;
F_3 ( V_13 ) ;
V_15 = V_14 -> V_8 ;
V_17 = NULL ;
while ( V_15 ) {
V_16 = F_4 ( sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 ) {
F_5 ( V_13 ) ;
return - V_19 ;
}
V_16 -> V_9 = V_15 -> V_9 ;
memcpy ( V_16 -> V_10 , V_15 -> V_10 , V_11 / 8 ) ;
V_16 -> V_12 = NULL ;
if ( V_17 )
V_17 -> V_12 = V_16 ;
else
V_13 -> V_8 = V_16 ;
V_17 = V_16 ;
V_15 = V_15 -> V_12 ;
}
V_13 -> V_7 = V_14 -> V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_20 ,
struct V_21 * * V_22 )
{
struct V_4 * V_23 = V_20 -> V_8 ;
struct V_21 * V_24 ;
T_1 V_25 , V_26 ;
int V_27 ;
if ( V_23 == NULL ) {
* V_22 = NULL ;
return 0 ;
}
V_24 = F_7 ( V_18 ) ;
if ( V_24 == NULL )
return - V_19 ;
* V_22 = V_24 ;
V_24 -> V_9 = V_23 -> V_9 & ~ ( V_28 - 1 ) ;
while ( V_23 ) {
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
unsigned int V_30 , V_31 , V_32 ;
V_31 = V_23 -> V_9 + V_27 * V_33 ;
V_32 = V_24 -> V_9 + V_28 ;
if ( V_31 >= V_32 ) {
V_24 -> V_12
= F_7 ( V_18 ) ;
if ( V_24 -> V_12 == NULL )
goto V_34;
V_24 = V_24 -> V_12 ;
V_24 -> V_9
= V_31 & ~ ( V_28 - 1 ) ;
}
V_30 = V_31 - V_24 -> V_9 ;
V_25 = V_30 / V_35 ;
V_26 = V_30 % V_35 ;
V_24 -> V_36 [ V_25 ]
|= V_23 -> V_10 [ V_27 ] << V_26 ;
}
V_23 = V_23 -> V_12 ;
}
return 0 ;
V_34:
F_8 ( * V_22 ) ;
return - V_19 ;
}
int F_9 ( struct V_1 * V_20 ,
struct V_21 * V_22 )
{
struct V_4 * V_23 = NULL ;
struct V_4 * V_37 = NULL ;
struct V_21 * V_24 = V_22 ;
T_1 V_38 , V_39 , V_40 , V_41 ;
do {
for ( V_38 = 0 ; V_38 < V_42 ; V_38 ++ ) {
unsigned int V_30 ;
T_2 V_43 = V_24 -> V_36 [ V_38 ] ;
if ( ! V_43 )
continue;
V_39 = V_24 -> V_9
+ V_38 * V_35 ;
if ( ! V_23
|| V_39 >= V_23 -> V_9 + V_11 ) {
V_23 = F_4 ( sizeof( * V_23 ) , V_18 ) ;
if ( ! V_23 )
goto V_44;
V_23 -> V_9
= V_39 - ( V_39 % V_11 ) ;
if ( V_37 == NULL )
V_20 -> V_8 = V_23 ;
else
V_37 -> V_12 = V_23 ;
V_37 = V_23 ;
}
V_30 = V_39 - V_23 -> V_9 ;
V_40 = V_30 / V_33 ;
V_41 = V_30 % V_33 ;
while ( V_43 ) {
V_23 -> V_10 [ V_40 ++ ] |= V_43 & ( - 1UL ) ;
V_43 = F_10 ( V_43 ) ;
}
}
V_24 = V_24 -> V_12 ;
} while ( V_24 );
if ( V_23 != NULL )
V_20 -> V_7 = V_23 -> V_9 + V_11 ;
else
F_5 ( V_20 ) ;
return 0 ;
V_44:
F_5 ( V_20 ) ;
return - V_19 ;
}
int F_11 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
int V_27 ;
if ( V_2 -> V_7 < V_3 -> V_7 )
return 0 ;
V_5 = V_2 -> V_8 ;
V_6 = V_3 -> V_8 ;
while ( V_5 && V_6 && ( V_5 -> V_9 <= V_6 -> V_9 ) ) {
if ( V_5 -> V_9 < V_6 -> V_9 ) {
V_5 = V_5 -> V_12 ;
continue;
}
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( ( V_5 -> V_10 [ V_27 ] & V_6 -> V_10 [ V_27 ] ) != V_6 -> V_10 [ V_27 ] )
return 0 ;
}
V_5 = V_5 -> V_12 ;
V_6 = V_6 -> V_12 ;
}
if ( V_6 )
return 0 ;
return 1 ;
}
int F_12 ( struct V_1 * V_45 , unsigned long V_46 )
{
struct V_4 * V_15 ;
if ( V_45 -> V_7 < V_46 )
return 0 ;
V_15 = V_45 -> V_8 ;
while ( V_15 && ( V_15 -> V_9 <= V_46 ) ) {
if ( ( V_15 -> V_9 + V_11 ) > V_46 )
return F_13 ( V_15 , V_46 ) ;
V_15 = V_15 -> V_12 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_45 , unsigned long V_46 , int V_47 )
{
struct V_4 * V_15 , * V_17 , * V_16 ;
V_17 = NULL ;
V_15 = V_45 -> V_8 ;
while ( V_15 && V_15 -> V_9 <= V_46 ) {
if ( ( V_15 -> V_9 + V_11 ) > V_46 ) {
if ( V_47 ) {
F_15 ( V_15 , V_46 ) ;
} else {
unsigned int V_48 ;
F_16 ( V_15 , V_46 ) ;
V_48 = F_17 ( V_15 -> V_10 , V_11 ) ;
if ( V_48 < V_11 )
return 0 ;
if ( ! V_15 -> V_12 ) {
if ( V_17 )
V_45 -> V_7 = V_17 -> V_9
+ V_11 ;
else
V_45 -> V_7 = 0 ;
}
if ( V_17 )
V_17 -> V_12 = V_15 -> V_12 ;
else
V_45 -> V_8 = V_15 -> V_12 ;
F_18 ( V_15 ) ;
}
return 0 ;
}
V_17 = V_15 ;
V_15 = V_15 -> V_12 ;
}
if ( ! V_47 )
return 0 ;
V_16 = F_4 ( sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 )
return - V_19 ;
V_16 -> V_9 = V_46 - ( V_46 % V_11 ) ;
F_15 ( V_16 , V_46 ) ;
if ( ! V_15 )
V_45 -> V_7 = V_16 -> V_9 + V_11 ;
if ( V_17 ) {
V_16 -> V_12 = V_17 -> V_12 ;
V_17 -> V_12 = V_16 ;
} else {
V_16 -> V_12 = V_45 -> V_8 ;
V_45 -> V_8 = V_16 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_45 )
{
struct V_4 * V_15 , * V_49 ;
if ( ! V_45 )
return;
V_15 = V_45 -> V_8 ;
while ( V_15 ) {
V_49 = V_15 ;
V_15 = V_15 -> V_12 ;
F_18 ( V_49 ) ;
}
V_45 -> V_7 = 0 ;
V_45 -> V_8 = NULL ;
return;
}
int F_19 ( struct V_1 * V_45 , void * V_50 )
{
struct V_4 * V_15 = NULL ;
T_1 V_51 , V_52 , V_9 , V_53 ;
T_2 V_43 ;
T_3 V_54 [ 3 ] ;
int V_55 , V_27 ;
F_3 ( V_45 ) ;
V_55 = F_20 ( V_54 , V_50 , sizeof V_54 ) ;
if ( V_55 < 0 )
goto V_56;
V_51 = F_21 ( V_54 [ 0 ] ) ;
V_45 -> V_7 = F_21 ( V_54 [ 1 ] ) ;
V_52 = F_21 ( V_54 [ 2 ] ) ;
if ( V_51 != V_57 ) {
F_22 ( V_58 L_1
L_2 ,
V_51 , V_57 , V_45 -> V_7 ) ;
goto V_59;
}
V_45 -> V_7 += V_11 - 1 ;
V_45 -> V_7 -= ( V_45 -> V_7 % V_11 ) ;
if ( ! V_45 -> V_7 ) {
V_45 -> V_8 = NULL ;
goto V_60;
}
for ( V_27 = 0 ; V_27 < V_52 ; V_27 ++ ) {
V_55 = F_20 ( & V_9 , V_50 , sizeof( T_1 ) ) ;
if ( V_55 < 0 ) {
F_22 ( V_58 L_3 ) ;
goto V_59;
}
V_9 = F_21 ( V_9 ) ;
if ( V_9 & ( V_51 - 1 ) ) {
F_22 ( V_58 L_4
L_5 ,
V_9 , V_51 ) ;
goto V_59;
}
if ( V_9 > V_45 -> V_7 - V_51 ) {
F_22 ( V_58 L_4
L_6 ,
V_9 , ( V_45 -> V_7 - V_51 ) ) ;
goto V_59;
}
if ( ! V_15 || V_9 >= V_15 -> V_9 + V_11 ) {
struct V_4 * V_61 ;
V_61 = F_4 ( sizeof( * V_61 ) , V_62 ) ;
if ( ! V_61 ) {
F_22 ( V_58
L_7 ) ;
V_55 = - V_19 ;
goto V_59;
}
V_61 -> V_9 = V_9 - ( V_9 % V_11 ) ;
if ( V_15 )
V_15 -> V_12 = V_61 ;
else
V_45 -> V_8 = V_61 ;
V_15 = V_61 ;
} else if ( V_9 <= V_15 -> V_9 ) {
F_22 ( V_58 L_8
L_9 ,
V_9 , V_15 -> V_9 ) ;
goto V_59;
}
V_55 = F_20 ( & V_43 , V_50 , sizeof( T_2 ) ) ;
if ( V_55 < 0 ) {
F_22 ( V_58 L_3 ) ;
goto V_59;
}
V_43 = F_23 ( V_43 ) ;
V_53 = ( V_9 - V_15 -> V_9 ) / V_33 ;
while ( V_43 ) {
V_15 -> V_10 [ V_53 ++ ] = V_43 & ( - 1UL ) ;
V_43 = F_10 ( V_43 ) ;
}
}
V_60:
V_55 = 0 ;
V_56:
return V_55 ;
V_59:
if ( ! V_55 )
V_55 = - V_63 ;
F_5 ( V_45 ) ;
goto V_56;
}
int F_24 ( struct V_1 * V_45 , void * V_50 )
{
struct V_4 * V_15 ;
T_1 V_52 ;
T_3 V_54 [ 3 ] ;
T_2 V_43 ;
int V_46 , V_64 , V_65 , V_55 ;
V_54 [ 0 ] = F_25 ( V_57 ) ;
V_52 = 0 ;
V_64 = 0 ;
V_65 = - 1 ;
F_26 (e, n, bit) {
if ( F_27 ( V_46 , ( int ) V_57 ) > V_65 ) {
V_52 ++ ;
V_65 = F_27 ( V_46 , V_57 ) ;
}
V_64 = F_28 ( V_46 + 1 , V_57 ) ;
}
V_54 [ 1 ] = F_25 ( V_64 ) ;
V_54 [ 2 ] = F_25 ( V_52 ) ;
V_55 = F_29 ( V_54 , sizeof( T_1 ) , 3 , V_50 ) ;
if ( V_55 )
return V_55 ;
V_43 = 0 ;
V_65 = V_66 ;
F_26 (e, n, bit) {
if ( F_27 ( V_46 , ( int ) V_57 ) > V_65 ) {
T_4 V_67 [ 1 ] ;
if ( ! V_43 ) {
V_65 = F_27 ( V_46 , V_57 ) ;
V_43 = ( T_2 ) 1 << ( V_46 - V_65 ) ;
continue;
}
V_54 [ 0 ] = F_25 ( V_65 ) ;
V_55 = F_29 ( V_54 , sizeof( T_1 ) , 1 , V_50 ) ;
if ( V_55 )
return V_55 ;
V_67 [ 0 ] = F_30 ( V_43 ) ;
V_55 = F_29 ( V_67 , sizeof( T_2 ) , 1 , V_50 ) ;
if ( V_55 )
return V_55 ;
V_43 = 0 ;
V_65 = F_27 ( V_46 , V_57 ) ;
}
V_43 |= ( T_2 ) 1 << ( V_46 - V_65 ) ;
}
if ( V_43 ) {
T_4 V_67 [ 1 ] ;
V_54 [ 0 ] = F_25 ( V_65 ) ;
V_55 = F_29 ( V_54 , sizeof( T_1 ) , 1 , V_50 ) ;
if ( V_55 )
return V_55 ;
V_67 [ 0 ] = F_30 ( V_43 ) ;
V_55 = F_29 ( V_67 , sizeof( T_2 ) , 1 , V_50 ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
