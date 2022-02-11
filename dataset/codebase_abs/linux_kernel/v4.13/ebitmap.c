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
V_16 = F_4 ( V_18 , V_19 ) ;
if ( ! V_16 ) {
F_5 ( V_13 ) ;
return - V_20 ;
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
int F_6 ( struct V_1 * V_21 ,
struct V_22 * * V_23 )
{
struct V_4 * V_24 = V_21 -> V_8 ;
unsigned long V_25 ;
T_1 V_26 ;
unsigned int V_27 ;
int V_28 ;
if ( V_24 == NULL ) {
* V_23 = NULL ;
return 0 ;
}
if ( * V_23 != NULL )
F_7 ( * V_23 ) ;
* V_23 = NULL ;
while ( V_24 ) {
V_26 = V_24 -> V_9 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
V_25 = V_24 -> V_10 [ V_27 ] ;
if ( V_25 != 0 ) {
V_28 = F_8 ( V_23 ,
V_26 ,
V_25 ,
V_19 ) ;
if ( V_28 != 0 )
goto V_30;
}
V_26 += V_31 ;
}
V_24 = V_24 -> V_12 ;
}
return 0 ;
V_30:
F_7 ( * V_23 ) ;
return - V_20 ;
}
int F_9 ( struct V_1 * V_21 ,
struct V_22 * V_23 )
{
int V_28 ;
struct V_4 * V_24 = NULL ;
struct V_4 * V_32 = NULL ;
T_1 V_26 = 0 , V_33 ;
unsigned long V_34 ;
for (; ; ) {
V_28 = F_10 ( V_23 , & V_26 , & V_34 ) ;
if ( V_28 < 0 )
goto V_35;
if ( V_26 == ( T_1 ) - 1 )
return 0 ;
if ( V_34 == 0 ) {
V_26 += V_31 ;
continue;
}
if ( V_24 == NULL ||
V_26 >= V_24 -> V_9 + V_11 ) {
V_32 = V_24 ;
V_24 = F_4 ( V_18 , V_19 ) ;
if ( V_24 == NULL )
goto V_35;
V_24 -> V_9 = V_26 - ( V_26 % V_11 ) ;
if ( V_32 == NULL )
V_21 -> V_8 = V_24 ;
else
V_32 -> V_12 = V_24 ;
V_21 -> V_7 = V_24 -> V_9 + V_11 ;
}
V_33 = F_11 ( V_24 , V_26 ) ;
V_24 -> V_10 [ V_33 ] = V_34 ;
V_26 += V_31 ;
}
return 0 ;
V_35:
F_5 ( V_21 ) ;
return - V_20 ;
}
int F_12 ( struct V_1 * V_2 , struct V_1 * V_3 , T_1 V_36 )
{
struct V_4 * V_5 , * V_6 ;
int V_37 ;
if ( V_2 -> V_7 < V_3 -> V_7 )
return 0 ;
V_5 = V_2 -> V_8 ;
V_6 = V_3 -> V_8 ;
while ( V_5 && V_6 && ( V_5 -> V_9 <= V_6 -> V_9 ) ) {
if ( V_5 -> V_9 < V_6 -> V_9 ) {
V_5 = V_5 -> V_12 ;
continue;
}
for ( V_37 = V_29 - 1 ; ( V_37 >= 0 ) && ! V_6 -> V_10 [ V_37 ] ; )
V_37 -- ;
if ( V_36 && ( V_37 >= 0 ) ) {
T_1 V_38 = V_6 -> V_9 + V_37 * V_31 +
F_13 ( V_6 -> V_10 [ V_37 ] ) ;
if ( V_38 > V_36 )
return 0 ;
}
while ( V_37 >= 0 ) {
if ( ( V_5 -> V_10 [ V_37 ] & V_6 -> V_10 [ V_37 ] ) != V_6 -> V_10 [ V_37 ] )
return 0 ;
V_37 -- ;
}
V_5 = V_5 -> V_12 ;
V_6 = V_6 -> V_12 ;
}
if ( V_6 )
return 0 ;
return 1 ;
}
int F_14 ( struct V_1 * V_39 , unsigned long V_40 )
{
struct V_4 * V_15 ;
if ( V_39 -> V_7 < V_40 )
return 0 ;
V_15 = V_39 -> V_8 ;
while ( V_15 && ( V_15 -> V_9 <= V_40 ) ) {
if ( ( V_15 -> V_9 + V_11 ) > V_40 )
return F_15 ( V_15 , V_40 ) ;
V_15 = V_15 -> V_12 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_39 , unsigned long V_40 , int V_41 )
{
struct V_4 * V_15 , * V_17 , * V_16 ;
V_17 = NULL ;
V_15 = V_39 -> V_8 ;
while ( V_15 && V_15 -> V_9 <= V_40 ) {
if ( ( V_15 -> V_9 + V_11 ) > V_40 ) {
if ( V_41 ) {
F_17 ( V_15 , V_40 ) ;
} else {
unsigned int V_42 ;
F_18 ( V_15 , V_40 ) ;
V_42 = F_19 ( V_15 -> V_10 , V_11 ) ;
if ( V_42 < V_11 )
return 0 ;
if ( ! V_15 -> V_12 ) {
if ( V_17 )
V_39 -> V_7 = V_17 -> V_9
+ V_11 ;
else
V_39 -> V_7 = 0 ;
}
if ( V_17 )
V_17 -> V_12 = V_15 -> V_12 ;
else
V_39 -> V_8 = V_15 -> V_12 ;
F_20 ( V_18 , V_15 ) ;
}
return 0 ;
}
V_17 = V_15 ;
V_15 = V_15 -> V_12 ;
}
if ( ! V_41 )
return 0 ;
V_16 = F_4 ( V_18 , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
V_16 -> V_9 = V_40 - ( V_40 % V_11 ) ;
F_17 ( V_16 , V_40 ) ;
if ( ! V_15 )
V_39 -> V_7 = V_16 -> V_9 + V_11 ;
if ( V_17 ) {
V_16 -> V_12 = V_17 -> V_12 ;
V_17 -> V_12 = V_16 ;
} else {
V_16 -> V_12 = V_39 -> V_8 ;
V_39 -> V_8 = V_16 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_39 )
{
struct V_4 * V_15 , * V_43 ;
if ( ! V_39 )
return;
V_15 = V_39 -> V_8 ;
while ( V_15 ) {
V_43 = V_15 ;
V_15 = V_15 -> V_12 ;
F_20 ( V_18 , V_43 ) ;
}
V_39 -> V_7 = 0 ;
V_39 -> V_8 = NULL ;
return;
}
int F_21 ( struct V_1 * V_39 , void * V_44 )
{
struct V_4 * V_15 = NULL ;
T_1 V_45 , V_46 , V_9 , V_47 ;
T_2 V_48 ;
T_3 V_49 [ 3 ] ;
int V_28 , V_37 ;
F_3 ( V_39 ) ;
V_28 = F_22 ( V_49 , V_44 , sizeof V_49 ) ;
if ( V_28 < 0 )
goto V_50;
V_45 = F_23 ( V_49 [ 0 ] ) ;
V_39 -> V_7 = F_23 ( V_49 [ 1 ] ) ;
V_46 = F_23 ( V_49 [ 2 ] ) ;
if ( V_45 != V_51 ) {
F_24 ( V_52 L_1
L_2 ,
V_45 , V_51 , V_39 -> V_7 ) ;
goto V_53;
}
V_39 -> V_7 += V_11 - 1 ;
V_39 -> V_7 -= ( V_39 -> V_7 % V_11 ) ;
if ( ! V_39 -> V_7 ) {
V_39 -> V_8 = NULL ;
goto V_54;
}
if ( V_39 -> V_7 && ! V_46 )
goto V_53;
for ( V_37 = 0 ; V_37 < V_46 ; V_37 ++ ) {
V_28 = F_22 ( & V_9 , V_44 , sizeof( T_1 ) ) ;
if ( V_28 < 0 ) {
F_24 ( V_52 L_3 ) ;
goto V_53;
}
V_9 = F_23 ( V_9 ) ;
if ( V_9 & ( V_45 - 1 ) ) {
F_24 ( V_52 L_4
L_5 ,
V_9 , V_45 ) ;
goto V_53;
}
if ( V_9 > V_39 -> V_7 - V_45 ) {
F_24 ( V_52 L_4
L_6 ,
V_9 , ( V_39 -> V_7 - V_45 ) ) ;
goto V_53;
}
if ( ! V_15 || V_9 >= V_15 -> V_9 + V_11 ) {
struct V_4 * V_55 ;
V_55 = F_4 ( V_18 , V_56 ) ;
if ( ! V_55 ) {
F_24 ( V_52
L_7 ) ;
V_28 = - V_20 ;
goto V_53;
}
V_55 -> V_9 = V_9 - ( V_9 % V_11 ) ;
if ( V_15 )
V_15 -> V_12 = V_55 ;
else
V_39 -> V_8 = V_55 ;
V_15 = V_55 ;
} else if ( V_9 <= V_15 -> V_9 ) {
F_24 ( V_52 L_8
L_9 ,
V_9 , V_15 -> V_9 ) ;
goto V_53;
}
V_28 = F_22 ( & V_48 , V_44 , sizeof( T_2 ) ) ;
if ( V_28 < 0 ) {
F_24 ( V_52 L_3 ) ;
goto V_53;
}
V_48 = F_25 ( V_48 ) ;
V_47 = ( V_9 - V_15 -> V_9 ) / V_31 ;
while ( V_48 ) {
V_15 -> V_10 [ V_47 ++ ] = V_48 & ( - 1UL ) ;
V_48 = F_26 ( V_48 ) ;
}
}
V_54:
V_28 = 0 ;
V_50:
return V_28 ;
V_53:
if ( ! V_28 )
V_28 = - V_57 ;
F_5 ( V_39 ) ;
goto V_50;
}
int F_27 ( struct V_1 * V_39 , void * V_44 )
{
struct V_4 * V_15 ;
T_1 V_46 ;
T_3 V_49 [ 3 ] ;
T_2 V_48 ;
int V_40 , V_58 , V_59 , V_28 ;
V_49 [ 0 ] = F_28 ( V_51 ) ;
V_46 = 0 ;
V_58 = 0 ;
V_59 = - 1 ;
F_29 (e, n, bit) {
if ( F_30 ( V_40 , ( int ) V_51 ) > V_59 ) {
V_46 ++ ;
V_59 = F_30 ( V_40 , V_51 ) ;
}
V_58 = F_31 ( V_40 + 1 , V_51 ) ;
}
V_49 [ 1 ] = F_28 ( V_58 ) ;
V_49 [ 2 ] = F_28 ( V_46 ) ;
V_28 = F_32 ( V_49 , sizeof( T_1 ) , 3 , V_44 ) ;
if ( V_28 )
return V_28 ;
V_48 = 0 ;
V_59 = V_60 ;
F_29 (e, n, bit) {
if ( F_30 ( V_40 , ( int ) V_51 ) > V_59 ) {
T_4 V_61 [ 1 ] ;
if ( ! V_48 ) {
V_59 = F_30 ( V_40 , V_51 ) ;
V_48 = ( T_2 ) 1 << ( V_40 - V_59 ) ;
continue;
}
V_49 [ 0 ] = F_28 ( V_59 ) ;
V_28 = F_32 ( V_49 , sizeof( T_1 ) , 1 , V_44 ) ;
if ( V_28 )
return V_28 ;
V_61 [ 0 ] = F_33 ( V_48 ) ;
V_28 = F_32 ( V_61 , sizeof( T_2 ) , 1 , V_44 ) ;
if ( V_28 )
return V_28 ;
V_48 = 0 ;
V_59 = F_30 ( V_40 , V_51 ) ;
}
V_48 |= ( T_2 ) 1 << ( V_40 - V_59 ) ;
}
if ( V_48 ) {
T_4 V_61 [ 1 ] ;
V_49 [ 0 ] = F_28 ( V_59 ) ;
V_28 = F_32 ( V_49 , sizeof( T_1 ) , 1 , V_44 ) ;
if ( V_28 )
return V_28 ;
V_61 [ 0 ] = F_33 ( V_48 ) ;
V_28 = F_32 ( V_61 , sizeof( T_2 ) , 1 , V_44 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
void F_34 ( void )
{
V_18 = F_35 ( L_10 ,
sizeof( struct V_4 ) ,
0 , V_62 , NULL ) ;
}
void F_36 ( void )
{
F_37 ( V_18 ) ;
}
