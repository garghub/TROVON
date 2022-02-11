int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_1 * V_5 , int * V_6 )
{
int V_7 ;
int V_8 ;
T_2 * V_9 = V_2 -> V_10 ;
int V_11 ;
T_1 V_12 = V_3 + V_4 ;
unsigned V_13 ;
if ( V_2 -> V_14 > 0 ) {
V_3 >>= V_2 -> V_14 ;
V_12 += ( 1 << V_2 -> V_14 ) - 1 ;
V_12 >>= V_2 -> V_14 ;
V_4 = V_12 - V_3 ;
}
V_15:
V_13 = F_2 ( & V_2 -> V_16 ) ;
V_8 = 0 ;
V_11 = 0 ;
V_7 = V_2 -> V_17 ;
while ( V_7 - V_8 > 1 ) {
int V_18 = ( V_8 + V_7 ) / 2 ;
T_1 V_19 = F_3 ( V_9 [ V_18 ] ) ;
if ( V_19 < V_12 )
V_8 = V_18 ;
else
V_7 = V_18 ;
}
if ( V_7 > V_8 ) {
while ( V_8 >= 0 &&
F_3 ( V_9 [ V_8 ] ) + F_4 ( V_9 [ V_8 ] ) > V_3 ) {
if ( F_3 ( V_9 [ V_8 ] ) < V_12 ) {
if ( V_11 != - 1 && F_5 ( V_9 [ V_8 ] ) )
V_11 = 1 ;
else
V_11 = - 1 ;
* V_5 = F_3 ( V_9 [ V_8 ] ) ;
* V_6 = F_4 ( V_9 [ V_8 ] ) ;
}
V_8 -- ;
}
}
if ( F_6 ( & V_2 -> V_16 , V_13 ) )
goto V_15;
return V_11 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
int V_20 )
{
T_2 * V_9 ;
int V_8 , V_7 ;
int V_11 = 0 ;
unsigned long V_21 ;
if ( V_2 -> V_14 < 0 )
return 0 ;
if ( V_2 -> V_14 ) {
T_1 V_22 = V_3 + V_4 ;
V_3 >>= V_2 -> V_14 ;
V_22 += ( 1 << V_2 -> V_14 ) - 1 ;
V_22 >>= V_2 -> V_14 ;
V_4 = V_22 - V_3 ;
}
F_8 ( & V_2 -> V_16 , V_21 ) ;
V_9 = V_2 -> V_10 ;
V_8 = 0 ;
V_7 = V_2 -> V_17 ;
while ( V_7 - V_8 > 1 ) {
int V_18 = ( V_8 + V_7 ) / 2 ;
T_1 V_19 = F_3 ( V_9 [ V_18 ] ) ;
if ( V_19 <= V_3 )
V_8 = V_18 ;
else
V_7 = V_18 ;
}
if ( V_7 > V_8 && F_3 ( V_9 [ V_8 ] ) > V_3 )
V_7 = V_8 ;
if ( V_7 > V_8 ) {
T_1 V_19 = F_3 ( V_9 [ V_8 ] ) ;
T_1 V_23 = V_19 + F_4 ( V_9 [ V_8 ] ) ;
int V_24 = F_5 ( V_9 [ V_8 ] ) ;
if ( V_23 >= V_3 ) {
if ( V_3 == V_19 && V_3 + V_4 >= V_23 )
V_24 = V_20 ;
else
V_24 = V_24 && V_20 ;
if ( V_23 < V_3 + V_4 )
V_23 = V_3 + V_4 ;
if ( V_23 - V_19 <= V_25 ) {
V_9 [ V_8 ] = F_9 ( V_19 , V_23 - V_19 , V_24 ) ;
V_3 = V_23 ;
} else {
if ( F_4 ( V_9 [ V_8 ] ) != V_25 )
V_9 [ V_8 ] = F_9 ( V_19 , V_25 , V_24 ) ;
V_3 = V_19 + V_25 ;
}
V_4 = V_23 - V_3 ;
}
}
if ( V_4 && V_7 < V_2 -> V_17 ) {
T_1 V_19 = F_3 ( V_9 [ V_7 ] ) ;
T_1 V_23 = V_19 + F_4 ( V_9 [ V_7 ] ) ;
int V_24 = F_5 ( V_9 [ V_7 ] ) ;
if ( V_19 <= V_3 + V_4 ) {
if ( V_23 <= V_3 + V_4 ) {
V_23 = V_3 + V_4 ;
V_24 = V_20 ;
} else
V_24 = V_24 && V_20 ;
V_19 = V_3 ;
if ( V_23 - V_19 <= V_25 ) {
V_9 [ V_7 ] = F_9 ( V_19 , V_23 - V_19 , V_24 ) ;
V_3 = V_23 ;
} else {
V_9 [ V_7 ] = F_9 ( V_19 , V_25 , V_24 ) ;
V_3 = V_19 + V_25 ;
}
V_4 = V_23 - V_3 ;
V_8 = V_7 ;
V_7 ++ ;
}
}
if ( V_4 == 0 && V_7 < V_2 -> V_17 ) {
T_1 V_19 = F_3 ( V_9 [ V_7 ] ) ;
int V_26 = F_4 ( V_9 [ V_8 ] ) ;
int V_27 = F_4 ( V_9 [ V_7 ] ) ;
int V_28 = V_26 + V_27 - ( V_3 - V_19 ) ;
if ( V_3 >= V_19 && V_28 < V_25 ) {
int V_24 = F_5 ( V_9 [ V_8 ] ) && F_5 ( V_9 [ V_7 ] ) ;
V_9 [ V_8 ] = F_9 ( F_3 ( V_9 [ V_8 ] ) , V_28 , V_24 ) ;
memmove ( V_9 + V_7 , V_9 + V_7 + 1 ,
( V_2 -> V_17 - V_7 - 1 ) * 8 ) ;
V_2 -> V_17 -- ;
}
}
while ( V_4 ) {
if ( V_2 -> V_17 >= V_29 ) {
V_11 = 1 ;
break;
} else {
int V_30 = V_4 ;
memmove ( V_9 + V_7 + 1 , V_9 + V_7 ,
( V_2 -> V_17 - V_7 ) * 8 ) ;
V_2 -> V_17 ++ ;
if ( V_30 > V_25 )
V_30 = V_25 ;
V_9 [ V_7 ] = F_9 ( V_3 , V_30 , V_20 ) ;
V_4 -= V_30 ;
V_3 += V_30 ;
}
}
V_2 -> V_31 = 1 ;
if ( ! V_20 )
V_2 -> V_32 = 1 ;
F_10 ( & V_2 -> V_16 , V_21 ) ;
return V_11 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
T_2 * V_9 ;
int V_8 , V_7 ;
T_1 V_12 = V_3 + V_4 ;
int V_11 = 0 ;
if ( V_2 -> V_14 > 0 ) {
V_3 += ( 1 << V_2 -> V_14 ) - 1 ;
V_3 >>= V_2 -> V_14 ;
V_12 >>= V_2 -> V_14 ;
V_4 = V_12 - V_3 ;
}
F_12 ( & V_2 -> V_16 ) ;
V_9 = V_2 -> V_10 ;
V_8 = 0 ;
V_7 = V_2 -> V_17 ;
while ( V_7 - V_8 > 1 ) {
int V_18 = ( V_8 + V_7 ) / 2 ;
T_1 V_19 = F_3 ( V_9 [ V_18 ] ) ;
if ( V_19 < V_12 )
V_8 = V_18 ;
else
V_7 = V_18 ;
}
if ( V_7 > V_8 ) {
if ( F_3 ( V_9 [ V_8 ] ) + F_4 ( V_9 [ V_8 ] ) > V_12 ) {
int V_24 = F_5 ( V_9 [ V_8 ] ) ;
T_1 V_19 = F_3 ( V_9 [ V_8 ] ) ;
T_1 V_33 = V_19 + F_4 ( V_9 [ V_8 ] ) ;
if ( V_19 < V_3 ) {
if ( V_2 -> V_17 >= V_29 ) {
V_11 = - V_34 ;
goto V_35;
}
memmove ( V_9 + V_8 + 1 , V_9 + V_8 , ( V_2 -> V_17 - V_8 ) * 8 ) ;
V_2 -> V_17 ++ ;
V_9 [ V_8 ] = F_9 ( V_19 , V_3 - V_19 , V_24 ) ;
V_8 ++ ;
}
V_9 [ V_8 ] = F_9 ( V_12 , V_33 - V_12 , V_24 ) ;
V_7 = V_8 ;
V_8 -- ;
}
while ( V_8 >= 0 &&
F_3 ( V_9 [ V_8 ] ) + F_4 ( V_9 [ V_8 ] ) > V_3 ) {
if ( F_3 ( V_9 [ V_8 ] ) < V_3 ) {
int V_24 = F_5 ( V_9 [ V_8 ] ) ;
T_1 V_36 = F_3 ( V_9 [ V_8 ] ) ;
V_9 [ V_8 ] = F_9 ( V_36 , V_3 - V_36 , V_24 ) ;
break;
}
V_8 -- ;
}
if ( V_7 - V_8 > 1 ) {
memmove ( V_9 + V_8 + 1 , V_9 + V_7 , ( V_2 -> V_17 - V_7 ) * 8 ) ;
V_2 -> V_17 -= ( V_7 - V_8 - 1 ) ;
}
}
V_2 -> V_31 = 1 ;
V_35:
F_13 ( & V_2 -> V_16 ) ;
return V_11 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 == NULL || V_2 -> V_31 )
return;
F_12 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_31 == 0 && V_2 -> V_32 ) {
T_2 * V_9 = V_2 -> V_10 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_17 ; V_37 ++ ) {
if ( ! F_5 ( V_9 [ V_37 ] ) ) {
T_1 V_36 = F_3 ( V_9 [ V_37 ] ) ;
int V_38 = F_4 ( V_9 [ V_37 ] ) ;
V_9 [ V_37 ] = F_9 ( V_36 , V_38 , 1 ) ;
}
}
V_2 -> V_32 = 0 ;
}
F_13 ( & V_2 -> V_16 ) ;
}
T_3 F_15 ( struct V_1 * V_2 , char * V_10 , int V_39 )
{
T_4 V_38 ;
int V_37 ;
T_2 * V_9 = V_2 -> V_10 ;
unsigned V_13 ;
if ( V_2 -> V_14 < 0 )
return 0 ;
V_15:
V_13 = F_2 ( & V_2 -> V_16 ) ;
V_38 = 0 ;
V_37 = 0 ;
while ( V_38 < V_40 && V_37 < V_2 -> V_17 ) {
T_1 V_3 = F_3 ( V_9 [ V_37 ] ) ;
unsigned int V_41 = F_4 ( V_9 [ V_37 ] ) ;
int V_24 = F_5 ( V_9 [ V_37 ] ) ;
V_37 ++ ;
if ( V_39 && V_24 )
continue;
V_38 += snprintf ( V_10 + V_38 , V_40 - V_38 , L_1 ,
( unsigned long long ) V_3 << V_2 -> V_14 ,
V_41 << V_2 -> V_14 ) ;
}
if ( V_39 && V_38 == 0 )
V_2 -> V_32 = 0 ;
if ( F_6 ( & V_2 -> V_16 , V_13 ) )
goto V_15;
return V_38 ;
}
T_3 F_16 ( struct V_1 * V_2 , const char * V_10 , T_4 V_38 ,
int V_39 )
{
unsigned long long V_42 ;
int V_41 ;
char V_43 ;
switch ( sscanf ( V_10 , L_2 , & V_42 , & V_41 , & V_43 ) ) {
case 3 :
if ( V_43 != '\n' )
return - V_44 ;
case 2 :
if ( V_41 <= 0 )
return - V_44 ;
break;
default:
return - V_44 ;
}
if ( F_7 ( V_2 , V_42 , V_41 , ! V_39 ) )
return - V_34 ;
else
return V_38 ;
}
static int F_17 ( struct V_45 * V_46 , struct V_1 * V_2 ,
int V_47 )
{
V_2 -> V_46 = V_46 ;
V_2 -> V_17 = 0 ;
if ( V_47 )
V_2 -> V_14 = 0 ;
else
V_2 -> V_14 = - 1 ;
if ( V_46 )
V_2 -> V_10 = F_18 ( V_46 , V_40 , V_48 ) ;
else
V_2 -> V_10 = F_19 ( V_40 , V_48 ) ;
if ( ! V_2 -> V_10 ) {
V_2 -> V_14 = - 1 ;
return - V_49 ;
}
F_20 ( & V_2 -> V_16 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , int V_47 )
{
return F_17 ( NULL , V_2 , V_47 ) ;
}
int F_22 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_44 ;
return F_17 ( V_46 , V_2 , 1 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_46 )
F_24 ( V_2 -> V_46 , V_2 -> V_10 ) ;
else
F_25 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
