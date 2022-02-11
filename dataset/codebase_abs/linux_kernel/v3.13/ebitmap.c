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
int F_11 ( struct V_1 * V_2 , struct V_1 * V_3 , T_1 V_45 )
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
for ( V_27 = V_29 - 1 ; ( V_27 >= 0 ) && ! V_6 -> V_10 [ V_27 ] ; )
V_27 -- ;
if ( V_45 && ( V_27 >= 0 ) ) {
T_1 V_46 = V_6 -> V_9 + V_27 * V_33 +
F_12 ( V_6 -> V_10 [ V_27 ] ) ;
if ( V_46 > V_45 )
return 0 ;
}
while ( V_27 >= 0 ) {
if ( ( V_5 -> V_10 [ V_27 ] & V_6 -> V_10 [ V_27 ] ) != V_6 -> V_10 [ V_27 ] )
return 0 ;
V_27 -- ;
}
V_5 = V_5 -> V_12 ;
V_6 = V_6 -> V_12 ;
}
if ( V_6 )
return 0 ;
return 1 ;
}
int F_13 ( struct V_1 * V_47 , unsigned long V_48 )
{
struct V_4 * V_15 ;
if ( V_47 -> V_7 < V_48 )
return 0 ;
V_15 = V_47 -> V_8 ;
while ( V_15 && ( V_15 -> V_9 <= V_48 ) ) {
if ( ( V_15 -> V_9 + V_11 ) > V_48 )
return F_14 ( V_15 , V_48 ) ;
V_15 = V_15 -> V_12 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_47 , unsigned long V_48 , int V_49 )
{
struct V_4 * V_15 , * V_17 , * V_16 ;
V_17 = NULL ;
V_15 = V_47 -> V_8 ;
while ( V_15 && V_15 -> V_9 <= V_48 ) {
if ( ( V_15 -> V_9 + V_11 ) > V_48 ) {
if ( V_49 ) {
F_16 ( V_15 , V_48 ) ;
} else {
unsigned int V_50 ;
F_17 ( V_15 , V_48 ) ;
V_50 = F_18 ( V_15 -> V_10 , V_11 ) ;
if ( V_50 < V_11 )
return 0 ;
if ( ! V_15 -> V_12 ) {
if ( V_17 )
V_47 -> V_7 = V_17 -> V_9
+ V_11 ;
else
V_47 -> V_7 = 0 ;
}
if ( V_17 )
V_17 -> V_12 = V_15 -> V_12 ;
else
V_47 -> V_8 = V_15 -> V_12 ;
F_19 ( V_15 ) ;
}
return 0 ;
}
V_17 = V_15 ;
V_15 = V_15 -> V_12 ;
}
if ( ! V_49 )
return 0 ;
V_16 = F_4 ( sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 )
return - V_19 ;
V_16 -> V_9 = V_48 - ( V_48 % V_11 ) ;
F_16 ( V_16 , V_48 ) ;
if ( ! V_15 )
V_47 -> V_7 = V_16 -> V_9 + V_11 ;
if ( V_17 ) {
V_16 -> V_12 = V_17 -> V_12 ;
V_17 -> V_12 = V_16 ;
} else {
V_16 -> V_12 = V_47 -> V_8 ;
V_47 -> V_8 = V_16 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_47 )
{
struct V_4 * V_15 , * V_51 ;
if ( ! V_47 )
return;
V_15 = V_47 -> V_8 ;
while ( V_15 ) {
V_51 = V_15 ;
V_15 = V_15 -> V_12 ;
F_19 ( V_51 ) ;
}
V_47 -> V_7 = 0 ;
V_47 -> V_8 = NULL ;
return;
}
int F_20 ( struct V_1 * V_47 , void * V_52 )
{
struct V_4 * V_15 = NULL ;
T_1 V_53 , V_54 , V_9 , V_55 ;
T_2 V_43 ;
T_3 V_56 [ 3 ] ;
int V_57 , V_27 ;
F_3 ( V_47 ) ;
V_57 = F_21 ( V_56 , V_52 , sizeof V_56 ) ;
if ( V_57 < 0 )
goto V_58;
V_53 = F_22 ( V_56 [ 0 ] ) ;
V_47 -> V_7 = F_22 ( V_56 [ 1 ] ) ;
V_54 = F_22 ( V_56 [ 2 ] ) ;
if ( V_53 != V_59 ) {
F_23 ( V_60 L_1
L_2 ,
V_53 , V_59 , V_47 -> V_7 ) ;
goto V_61;
}
V_47 -> V_7 += V_11 - 1 ;
V_47 -> V_7 -= ( V_47 -> V_7 % V_11 ) ;
if ( ! V_47 -> V_7 ) {
V_47 -> V_8 = NULL ;
goto V_62;
}
for ( V_27 = 0 ; V_27 < V_54 ; V_27 ++ ) {
V_57 = F_21 ( & V_9 , V_52 , sizeof( T_1 ) ) ;
if ( V_57 < 0 ) {
F_23 ( V_60 L_3 ) ;
goto V_61;
}
V_9 = F_22 ( V_9 ) ;
if ( V_9 & ( V_53 - 1 ) ) {
F_23 ( V_60 L_4
L_5 ,
V_9 , V_53 ) ;
goto V_61;
}
if ( V_9 > V_47 -> V_7 - V_53 ) {
F_23 ( V_60 L_4
L_6 ,
V_9 , ( V_47 -> V_7 - V_53 ) ) ;
goto V_61;
}
if ( ! V_15 || V_9 >= V_15 -> V_9 + V_11 ) {
struct V_4 * V_63 ;
V_63 = F_4 ( sizeof( * V_63 ) , V_64 ) ;
if ( ! V_63 ) {
F_23 ( V_60
L_7 ) ;
V_57 = - V_19 ;
goto V_61;
}
V_63 -> V_9 = V_9 - ( V_9 % V_11 ) ;
if ( V_15 )
V_15 -> V_12 = V_63 ;
else
V_47 -> V_8 = V_63 ;
V_15 = V_63 ;
} else if ( V_9 <= V_15 -> V_9 ) {
F_23 ( V_60 L_8
L_9 ,
V_9 , V_15 -> V_9 ) ;
goto V_61;
}
V_57 = F_21 ( & V_43 , V_52 , sizeof( T_2 ) ) ;
if ( V_57 < 0 ) {
F_23 ( V_60 L_3 ) ;
goto V_61;
}
V_43 = F_24 ( V_43 ) ;
V_55 = ( V_9 - V_15 -> V_9 ) / V_33 ;
while ( V_43 ) {
V_15 -> V_10 [ V_55 ++ ] = V_43 & ( - 1UL ) ;
V_43 = F_10 ( V_43 ) ;
}
}
V_62:
V_57 = 0 ;
V_58:
return V_57 ;
V_61:
if ( ! V_57 )
V_57 = - V_65 ;
F_5 ( V_47 ) ;
goto V_58;
}
int F_25 ( struct V_1 * V_47 , void * V_52 )
{
struct V_4 * V_15 ;
T_1 V_54 ;
T_3 V_56 [ 3 ] ;
T_2 V_43 ;
int V_48 , V_66 , V_67 , V_57 ;
V_56 [ 0 ] = F_26 ( V_59 ) ;
V_54 = 0 ;
V_66 = 0 ;
V_67 = - 1 ;
F_27 (e, n, bit) {
if ( F_28 ( V_48 , ( int ) V_59 ) > V_67 ) {
V_54 ++ ;
V_67 = F_28 ( V_48 , V_59 ) ;
}
V_66 = F_29 ( V_48 + 1 , V_59 ) ;
}
V_56 [ 1 ] = F_26 ( V_66 ) ;
V_56 [ 2 ] = F_26 ( V_54 ) ;
V_57 = F_30 ( V_56 , sizeof( T_1 ) , 3 , V_52 ) ;
if ( V_57 )
return V_57 ;
V_43 = 0 ;
V_67 = V_68 ;
F_27 (e, n, bit) {
if ( F_28 ( V_48 , ( int ) V_59 ) > V_67 ) {
T_4 V_69 [ 1 ] ;
if ( ! V_43 ) {
V_67 = F_28 ( V_48 , V_59 ) ;
V_43 = ( T_2 ) 1 << ( V_48 - V_67 ) ;
continue;
}
V_56 [ 0 ] = F_26 ( V_67 ) ;
V_57 = F_30 ( V_56 , sizeof( T_1 ) , 1 , V_52 ) ;
if ( V_57 )
return V_57 ;
V_69 [ 0 ] = F_31 ( V_43 ) ;
V_57 = F_30 ( V_69 , sizeof( T_2 ) , 1 , V_52 ) ;
if ( V_57 )
return V_57 ;
V_43 = 0 ;
V_67 = F_28 ( V_48 , V_59 ) ;
}
V_43 |= ( T_2 ) 1 << ( V_48 - V_67 ) ;
}
if ( V_43 ) {
T_4 V_69 [ 1 ] ;
V_56 [ 0 ] = F_26 ( V_67 ) ;
V_57 = F_30 ( V_56 , sizeof( T_1 ) , 1 , V_52 ) ;
if ( V_57 )
return V_57 ;
V_69 [ 0 ] = F_31 ( V_43 ) ;
V_57 = F_30 ( V_69 , sizeof( T_2 ) , 1 , V_52 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
