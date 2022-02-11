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
static void F_7 ( struct V_1 * V_2 )
{
T_2 * V_9 = V_2 -> V_10 ;
int V_20 ;
bool V_21 = false ;
if ( ! V_2 -> V_22 )
return;
for ( V_20 = 0 ; V_20 < V_2 -> V_17 ; V_20 ++ ) {
if ( ! F_5 ( V_9 [ V_20 ] ) ) {
V_21 = true ;
break;
}
}
if ( ! V_21 )
V_2 -> V_22 = 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
int V_23 )
{
T_2 * V_9 ;
int V_8 , V_7 ;
int V_11 = 0 ;
unsigned long V_24 ;
if ( V_2 -> V_14 < 0 )
return 0 ;
if ( V_2 -> V_14 ) {
T_1 V_25 = V_3 + V_4 ;
V_3 >>= V_2 -> V_14 ;
V_25 += ( 1 << V_2 -> V_14 ) - 1 ;
V_25 >>= V_2 -> V_14 ;
V_4 = V_25 - V_3 ;
}
F_9 ( & V_2 -> V_16 , V_24 ) ;
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
T_1 V_26 = V_19 + F_4 ( V_9 [ V_8 ] ) ;
int V_27 = F_5 ( V_9 [ V_8 ] ) ;
if ( V_26 >= V_3 ) {
if ( V_3 == V_19 && V_3 + V_4 >= V_26 )
V_27 = V_23 ;
else
V_27 = V_27 && V_23 ;
if ( V_26 < V_3 + V_4 )
V_26 = V_3 + V_4 ;
if ( V_26 - V_19 <= V_28 ) {
V_9 [ V_8 ] = F_10 ( V_19 , V_26 - V_19 , V_27 ) ;
V_3 = V_26 ;
} else {
if ( F_4 ( V_9 [ V_8 ] ) != V_28 )
V_9 [ V_8 ] = F_10 ( V_19 , V_28 , V_27 ) ;
V_3 = V_19 + V_28 ;
}
V_4 = V_26 - V_3 ;
}
}
if ( V_4 && V_7 < V_2 -> V_17 ) {
T_1 V_19 = F_3 ( V_9 [ V_7 ] ) ;
T_1 V_26 = V_19 + F_4 ( V_9 [ V_7 ] ) ;
int V_27 = F_5 ( V_9 [ V_7 ] ) ;
if ( V_19 <= V_3 + V_4 ) {
if ( V_26 <= V_3 + V_4 ) {
V_26 = V_3 + V_4 ;
V_27 = V_23 ;
} else
V_27 = V_27 && V_23 ;
V_19 = V_3 ;
if ( V_26 - V_19 <= V_28 ) {
V_9 [ V_7 ] = F_10 ( V_19 , V_26 - V_19 , V_27 ) ;
V_3 = V_26 ;
} else {
V_9 [ V_7 ] = F_10 ( V_19 , V_28 , V_27 ) ;
V_3 = V_19 + V_28 ;
}
V_4 = V_26 - V_3 ;
V_8 = V_7 ;
V_7 ++ ;
}
}
if ( V_4 == 0 && V_7 < V_2 -> V_17 ) {
T_1 V_19 = F_3 ( V_9 [ V_7 ] ) ;
int V_29 = F_4 ( V_9 [ V_8 ] ) ;
int V_30 = F_4 ( V_9 [ V_7 ] ) ;
int V_31 = V_29 + V_30 - ( V_3 - V_19 ) ;
if ( V_3 >= V_19 && V_31 < V_28 ) {
int V_27 = F_5 ( V_9 [ V_8 ] ) && F_5 ( V_9 [ V_7 ] ) ;
V_9 [ V_8 ] = F_10 ( F_3 ( V_9 [ V_8 ] ) , V_31 , V_27 ) ;
memmove ( V_9 + V_7 , V_9 + V_7 + 1 ,
( V_2 -> V_17 - V_7 - 1 ) * 8 ) ;
V_2 -> V_17 -- ;
}
}
while ( V_4 ) {
if ( V_2 -> V_17 >= V_32 ) {
V_11 = 1 ;
break;
} else {
int V_33 = V_4 ;
memmove ( V_9 + V_7 + 1 , V_9 + V_7 ,
( V_2 -> V_17 - V_7 ) * 8 ) ;
V_2 -> V_17 ++ ;
if ( V_33 > V_28 )
V_33 = V_28 ;
V_9 [ V_7 ] = F_10 ( V_3 , V_33 , V_23 ) ;
V_4 -= V_33 ;
V_3 += V_33 ;
}
}
V_2 -> V_34 = 1 ;
if ( ! V_23 )
V_2 -> V_22 = 1 ;
else
F_7 ( V_2 ) ;
F_11 ( & V_2 -> V_16 , V_24 ) ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
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
F_13 ( & V_2 -> V_16 ) ;
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
if ( ( F_3 ( V_9 [ V_8 ] ) + F_4 ( V_9 [ V_8 ] ) > V_12 ) &&
( F_3 ( V_9 [ V_8 ] ) < V_12 ) ) {
int V_27 = F_5 ( V_9 [ V_8 ] ) ;
T_1 V_19 = F_3 ( V_9 [ V_8 ] ) ;
T_1 V_35 = V_19 + F_4 ( V_9 [ V_8 ] ) ;
if ( V_19 < V_3 ) {
if ( V_2 -> V_17 >= V_32 ) {
V_11 = - V_36 ;
goto V_37;
}
memmove ( V_9 + V_8 + 1 , V_9 + V_8 , ( V_2 -> V_17 - V_8 ) * 8 ) ;
V_2 -> V_17 ++ ;
V_9 [ V_8 ] = F_10 ( V_19 , V_3 - V_19 , V_27 ) ;
V_8 ++ ;
}
V_9 [ V_8 ] = F_10 ( V_12 , V_35 - V_12 , V_27 ) ;
V_7 = V_8 ;
V_8 -- ;
}
while ( V_8 >= 0 &&
( F_3 ( V_9 [ V_8 ] ) + F_4 ( V_9 [ V_8 ] ) > V_3 ) &&
( F_3 ( V_9 [ V_8 ] ) < V_12 ) ) {
if ( F_3 ( V_9 [ V_8 ] ) < V_3 ) {
int V_27 = F_5 ( V_9 [ V_8 ] ) ;
T_1 V_38 = F_3 ( V_9 [ V_8 ] ) ;
V_9 [ V_8 ] = F_10 ( V_38 , V_3 - V_38 , V_27 ) ;
break;
}
V_8 -- ;
}
if ( V_7 - V_8 > 1 ) {
memmove ( V_9 + V_8 + 1 , V_9 + V_7 , ( V_2 -> V_17 - V_7 ) * 8 ) ;
V_2 -> V_17 -= ( V_7 - V_8 - 1 ) ;
}
}
F_7 ( V_2 ) ;
V_2 -> V_34 = 1 ;
V_37:
F_14 ( & V_2 -> V_16 ) ;
return V_11 ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 == NULL || V_2 -> V_34 )
return;
F_13 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_34 == 0 && V_2 -> V_22 ) {
T_2 * V_9 = V_2 -> V_10 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_17 ; V_20 ++ ) {
if ( ! F_5 ( V_9 [ V_20 ] ) ) {
T_1 V_38 = F_3 ( V_9 [ V_20 ] ) ;
int V_39 = F_4 ( V_9 [ V_20 ] ) ;
V_9 [ V_20 ] = F_10 ( V_38 , V_39 , 1 ) ;
}
}
V_2 -> V_22 = 0 ;
}
F_14 ( & V_2 -> V_16 ) ;
}
T_3 F_16 ( struct V_1 * V_2 , char * V_10 , int V_40 )
{
T_4 V_39 ;
int V_20 ;
T_2 * V_9 = V_2 -> V_10 ;
unsigned V_13 ;
if ( V_2 -> V_14 < 0 )
return 0 ;
V_15:
V_13 = F_2 ( & V_2 -> V_16 ) ;
V_39 = 0 ;
V_20 = 0 ;
while ( V_39 < V_41 && V_20 < V_2 -> V_17 ) {
T_1 V_3 = F_3 ( V_9 [ V_20 ] ) ;
unsigned int V_42 = F_4 ( V_9 [ V_20 ] ) ;
int V_27 = F_5 ( V_9 [ V_20 ] ) ;
V_20 ++ ;
if ( V_40 && V_27 )
continue;
V_39 += snprintf ( V_10 + V_39 , V_41 - V_39 , L_1 ,
( unsigned long long ) V_3 << V_2 -> V_14 ,
V_42 << V_2 -> V_14 ) ;
}
if ( V_40 && V_39 == 0 )
V_2 -> V_22 = 0 ;
if ( F_6 ( & V_2 -> V_16 , V_13 ) )
goto V_15;
return V_39 ;
}
T_3 F_17 ( struct V_1 * V_2 , const char * V_10 , T_4 V_39 ,
int V_40 )
{
unsigned long long V_43 ;
int V_42 ;
char V_44 ;
switch ( sscanf ( V_10 , L_2 , & V_43 , & V_42 , & V_44 ) ) {
case 3 :
if ( V_44 != '\n' )
return - V_45 ;
case 2 :
if ( V_42 <= 0 )
return - V_45 ;
break;
default:
return - V_45 ;
}
if ( F_8 ( V_2 , V_43 , V_42 , ! V_40 ) )
return - V_36 ;
else
return V_39 ;
}
static int F_18 ( struct V_46 * V_47 , struct V_1 * V_2 ,
int V_48 )
{
V_2 -> V_47 = V_47 ;
V_2 -> V_17 = 0 ;
if ( V_48 )
V_2 -> V_14 = 0 ;
else
V_2 -> V_14 = - 1 ;
if ( V_47 )
V_2 -> V_10 = F_19 ( V_47 , V_41 , V_49 ) ;
else
V_2 -> V_10 = F_20 ( V_41 , V_49 ) ;
if ( ! V_2 -> V_10 ) {
V_2 -> V_14 = - 1 ;
return - V_50 ;
}
F_21 ( & V_2 -> V_16 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , int V_48 )
{
return F_18 ( NULL , V_2 , V_48 ) ;
}
int F_23 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_45 ;
return F_18 ( V_47 , V_2 , 1 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_47 )
F_25 ( V_2 -> V_47 , V_2 -> V_10 ) ;
else
F_26 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
