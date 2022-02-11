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
unsigned long V_24 ;
T_1 V_25 ;
unsigned int V_26 ;
int V_27 ;
if ( V_23 == NULL ) {
* V_22 = NULL ;
return 0 ;
}
if ( * V_22 != NULL )
F_7 ( * V_22 ) ;
* V_22 = NULL ;
while ( V_23 ) {
V_25 = V_23 -> V_9 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
V_24 = V_23 -> V_10 [ V_26 ] ;
if ( V_24 != 0 ) {
V_27 = F_8 ( V_22 ,
V_25 ,
V_24 ,
V_18 ) ;
if ( V_27 != 0 )
goto V_29;
}
V_25 += V_30 ;
}
V_23 = V_23 -> V_12 ;
}
return 0 ;
V_29:
F_7 ( * V_22 ) ;
return - V_19 ;
}
int F_9 ( struct V_1 * V_20 ,
struct V_21 * V_22 )
{
int V_27 ;
struct V_4 * V_23 = NULL ;
struct V_4 * V_31 = NULL ;
T_1 V_25 = 0 , V_32 ;
unsigned long V_33 ;
for (; ; ) {
V_27 = F_10 ( V_22 , & V_25 , & V_33 ) ;
if ( V_27 < 0 )
goto V_34;
if ( V_25 == ( T_1 ) - 1 )
return 0 ;
if ( V_33 == 0 ) {
V_25 += V_30 ;
continue;
}
if ( V_23 == NULL ||
V_25 >= V_23 -> V_9 + V_11 ) {
V_31 = V_23 ;
V_23 = F_4 ( sizeof( * V_23 ) , V_18 ) ;
if ( V_23 == NULL )
goto V_34;
V_23 -> V_9 = V_25 & ~ ( V_11 - 1 ) ;
if ( V_31 == NULL )
V_20 -> V_8 = V_23 ;
else
V_31 -> V_12 = V_23 ;
V_20 -> V_7 = V_23 -> V_9 + V_11 ;
}
V_32 = F_11 ( V_23 , V_25 ) ;
V_23 -> V_10 [ V_32 ] = V_33 ;
V_25 += V_30 ;
}
return 0 ;
V_34:
F_5 ( V_20 ) ;
return - V_19 ;
}
int F_12 ( struct V_1 * V_2 , struct V_1 * V_3 , T_1 V_35 )
{
struct V_4 * V_5 , * V_6 ;
int V_36 ;
if ( V_2 -> V_7 < V_3 -> V_7 )
return 0 ;
V_5 = V_2 -> V_8 ;
V_6 = V_3 -> V_8 ;
while ( V_5 && V_6 && ( V_5 -> V_9 <= V_6 -> V_9 ) ) {
if ( V_5 -> V_9 < V_6 -> V_9 ) {
V_5 = V_5 -> V_12 ;
continue;
}
for ( V_36 = V_28 - 1 ; ( V_36 >= 0 ) && ! V_6 -> V_10 [ V_36 ] ; )
V_36 -- ;
if ( V_35 && ( V_36 >= 0 ) ) {
T_1 V_37 = V_6 -> V_9 + V_36 * V_30 +
F_13 ( V_6 -> V_10 [ V_36 ] ) ;
if ( V_37 > V_35 )
return 0 ;
}
while ( V_36 >= 0 ) {
if ( ( V_5 -> V_10 [ V_36 ] & V_6 -> V_10 [ V_36 ] ) != V_6 -> V_10 [ V_36 ] )
return 0 ;
V_36 -- ;
}
V_5 = V_5 -> V_12 ;
V_6 = V_6 -> V_12 ;
}
if ( V_6 )
return 0 ;
return 1 ;
}
int F_14 ( struct V_1 * V_38 , unsigned long V_39 )
{
struct V_4 * V_15 ;
if ( V_38 -> V_7 < V_39 )
return 0 ;
V_15 = V_38 -> V_8 ;
while ( V_15 && ( V_15 -> V_9 <= V_39 ) ) {
if ( ( V_15 -> V_9 + V_11 ) > V_39 )
return F_15 ( V_15 , V_39 ) ;
V_15 = V_15 -> V_12 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_38 , unsigned long V_39 , int V_40 )
{
struct V_4 * V_15 , * V_17 , * V_16 ;
V_17 = NULL ;
V_15 = V_38 -> V_8 ;
while ( V_15 && V_15 -> V_9 <= V_39 ) {
if ( ( V_15 -> V_9 + V_11 ) > V_39 ) {
if ( V_40 ) {
F_17 ( V_15 , V_39 ) ;
} else {
unsigned int V_41 ;
F_18 ( V_15 , V_39 ) ;
V_41 = F_19 ( V_15 -> V_10 , V_11 ) ;
if ( V_41 < V_11 )
return 0 ;
if ( ! V_15 -> V_12 ) {
if ( V_17 )
V_38 -> V_7 = V_17 -> V_9
+ V_11 ;
else
V_38 -> V_7 = 0 ;
}
if ( V_17 )
V_17 -> V_12 = V_15 -> V_12 ;
else
V_38 -> V_8 = V_15 -> V_12 ;
F_20 ( V_15 ) ;
}
return 0 ;
}
V_17 = V_15 ;
V_15 = V_15 -> V_12 ;
}
if ( ! V_40 )
return 0 ;
V_16 = F_4 ( sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 )
return - V_19 ;
V_16 -> V_9 = V_39 - ( V_39 % V_11 ) ;
F_17 ( V_16 , V_39 ) ;
if ( ! V_15 )
V_38 -> V_7 = V_16 -> V_9 + V_11 ;
if ( V_17 ) {
V_16 -> V_12 = V_17 -> V_12 ;
V_17 -> V_12 = V_16 ;
} else {
V_16 -> V_12 = V_38 -> V_8 ;
V_38 -> V_8 = V_16 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_38 )
{
struct V_4 * V_15 , * V_42 ;
if ( ! V_38 )
return;
V_15 = V_38 -> V_8 ;
while ( V_15 ) {
V_42 = V_15 ;
V_15 = V_15 -> V_12 ;
F_20 ( V_42 ) ;
}
V_38 -> V_7 = 0 ;
V_38 -> V_8 = NULL ;
return;
}
int F_21 ( struct V_1 * V_38 , void * V_43 )
{
struct V_4 * V_15 = NULL ;
T_1 V_44 , V_45 , V_9 , V_46 ;
T_2 V_47 ;
T_3 V_48 [ 3 ] ;
int V_27 , V_36 ;
F_3 ( V_38 ) ;
V_27 = F_22 ( V_48 , V_43 , sizeof V_48 ) ;
if ( V_27 < 0 )
goto V_49;
V_44 = F_23 ( V_48 [ 0 ] ) ;
V_38 -> V_7 = F_23 ( V_48 [ 1 ] ) ;
V_45 = F_23 ( V_48 [ 2 ] ) ;
if ( V_44 != V_50 ) {
F_24 ( V_51 L_1
L_2 ,
V_44 , V_50 , V_38 -> V_7 ) ;
goto V_52;
}
V_38 -> V_7 += V_11 - 1 ;
V_38 -> V_7 -= ( V_38 -> V_7 % V_11 ) ;
if ( ! V_38 -> V_7 ) {
V_38 -> V_8 = NULL ;
goto V_53;
}
for ( V_36 = 0 ; V_36 < V_45 ; V_36 ++ ) {
V_27 = F_22 ( & V_9 , V_43 , sizeof( T_1 ) ) ;
if ( V_27 < 0 ) {
F_24 ( V_51 L_3 ) ;
goto V_52;
}
V_9 = F_23 ( V_9 ) ;
if ( V_9 & ( V_44 - 1 ) ) {
F_24 ( V_51 L_4
L_5 ,
V_9 , V_44 ) ;
goto V_52;
}
if ( V_9 > V_38 -> V_7 - V_44 ) {
F_24 ( V_51 L_4
L_6 ,
V_9 , ( V_38 -> V_7 - V_44 ) ) ;
goto V_52;
}
if ( ! V_15 || V_9 >= V_15 -> V_9 + V_11 ) {
struct V_4 * V_54 ;
V_54 = F_4 ( sizeof( * V_54 ) , V_55 ) ;
if ( ! V_54 ) {
F_24 ( V_51
L_7 ) ;
V_27 = - V_19 ;
goto V_52;
}
V_54 -> V_9 = V_9 - ( V_9 % V_11 ) ;
if ( V_15 )
V_15 -> V_12 = V_54 ;
else
V_38 -> V_8 = V_54 ;
V_15 = V_54 ;
} else if ( V_9 <= V_15 -> V_9 ) {
F_24 ( V_51 L_8
L_9 ,
V_9 , V_15 -> V_9 ) ;
goto V_52;
}
V_27 = F_22 ( & V_47 , V_43 , sizeof( T_2 ) ) ;
if ( V_27 < 0 ) {
F_24 ( V_51 L_3 ) ;
goto V_52;
}
V_47 = F_25 ( V_47 ) ;
V_46 = ( V_9 - V_15 -> V_9 ) / V_30 ;
while ( V_47 ) {
V_15 -> V_10 [ V_46 ++ ] = V_47 & ( - 1UL ) ;
V_47 = F_26 ( V_47 ) ;
}
}
V_53:
V_27 = 0 ;
V_49:
return V_27 ;
V_52:
if ( ! V_27 )
V_27 = - V_56 ;
F_5 ( V_38 ) ;
goto V_49;
}
int F_27 ( struct V_1 * V_38 , void * V_43 )
{
struct V_4 * V_15 ;
T_1 V_45 ;
T_3 V_48 [ 3 ] ;
T_2 V_47 ;
int V_39 , V_57 , V_58 , V_27 ;
V_48 [ 0 ] = F_28 ( V_50 ) ;
V_45 = 0 ;
V_57 = 0 ;
V_58 = - 1 ;
F_29 (e, n, bit) {
if ( F_30 ( V_39 , ( int ) V_50 ) > V_58 ) {
V_45 ++ ;
V_58 = F_30 ( V_39 , V_50 ) ;
}
V_57 = F_31 ( V_39 + 1 , V_50 ) ;
}
V_48 [ 1 ] = F_28 ( V_57 ) ;
V_48 [ 2 ] = F_28 ( V_45 ) ;
V_27 = F_32 ( V_48 , sizeof( T_1 ) , 3 , V_43 ) ;
if ( V_27 )
return V_27 ;
V_47 = 0 ;
V_58 = V_59 ;
F_29 (e, n, bit) {
if ( F_30 ( V_39 , ( int ) V_50 ) > V_58 ) {
T_4 V_60 [ 1 ] ;
if ( ! V_47 ) {
V_58 = F_30 ( V_39 , V_50 ) ;
V_47 = ( T_2 ) 1 << ( V_39 - V_58 ) ;
continue;
}
V_48 [ 0 ] = F_28 ( V_58 ) ;
V_27 = F_32 ( V_48 , sizeof( T_1 ) , 1 , V_43 ) ;
if ( V_27 )
return V_27 ;
V_60 [ 0 ] = F_33 ( V_47 ) ;
V_27 = F_32 ( V_60 , sizeof( T_2 ) , 1 , V_43 ) ;
if ( V_27 )
return V_27 ;
V_47 = 0 ;
V_58 = F_30 ( V_39 , V_50 ) ;
}
V_47 |= ( T_2 ) 1 << ( V_39 - V_58 ) ;
}
if ( V_47 ) {
T_4 V_60 [ 1 ] ;
V_48 [ 0 ] = F_28 ( V_58 ) ;
V_27 = F_32 ( V_48 , sizeof( T_1 ) , 1 , V_43 ) ;
if ( V_27 )
return V_27 ;
V_60 [ 0 ] = F_33 ( V_47 ) ;
V_27 = F_32 ( V_60 , sizeof( T_2 ) , 1 , V_43 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
