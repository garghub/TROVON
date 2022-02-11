static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long long V_7 ;
T_1 V_8 ;
if ( V_5 -> V_9 && V_5 -> V_9 -> V_10 )
return V_5 -> V_9 -> V_10 ( V_2 , V_3 ) ;
V_8 = F_2 ( V_5 -> V_11 -> V_12 , L_1 , NULL , & V_7 ) ;
if ( F_3 ( V_8 ) )
return - V_13 ;
if ( V_5 -> V_14 ) {
int V_15 ;
V_15 = F_4 ( V_5 -> V_14 , ( int ) V_7 ) ;
if ( V_15 < 0 )
return V_15 ;
* V_3 = ( unsigned long ) V_15 * 10 ;
} else
* V_3 = F_5 ( V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_16 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_17 ;
if ( V_5 -> V_9 && V_5 -> V_9 -> V_18 )
return V_5 -> V_9 -> V_18 ( V_2 , V_16 , V_3 ) ;
if ( V_16 < V_5 -> V_19 )
* V_3 = V_5 -> V_20 [ V_16 ] ;
else if ( V_16 == V_5 -> V_21 )
* V_3 = V_5 -> V_22 ;
else if ( V_16 == V_5 -> V_23 )
* V_3 = V_5 -> V_24 ;
else if ( V_16 == V_5 -> V_25 )
* V_3 = V_5 -> V_26 ;
else {
for ( V_17 = 0 ; V_17 < V_27 ; V_17 ++ ) {
if ( V_5 -> V_28 [ V_17 ] . V_29 &&
V_5 -> V_28 [ V_17 ] . V_30 == V_16 ) {
* V_3 = V_5 -> V_28 [ V_17 ] . V_3 ;
break;
}
}
if ( V_17 == V_27 )
return - V_31 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_16 ,
enum V_32 * type )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_17 ;
if ( V_5 -> V_9 && V_5 -> V_9 -> V_33 )
return V_5 -> V_9 -> V_33 ( V_2 , V_16 , type ) ;
if ( V_16 < V_5 -> V_19 )
* type = V_34 ;
else if ( V_16 == V_5 -> V_21 )
* type = V_35 ;
else if ( V_16 == V_5 -> V_25 )
* type = V_36 ;
else if ( V_16 == V_5 -> V_23 )
* type = V_34 ;
else {
for ( V_17 = 0 ; V_17 < V_27 ; V_17 ++ ) {
if ( V_5 -> V_28 [ V_17 ] . V_29 &&
V_5 -> V_28 [ V_17 ] . V_30 == V_16 ) {
* type = V_37 ;
break;
}
}
if ( V_17 == V_27 )
return - V_31 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_16 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_8 ;
char V_38 [ 10 ] ;
if ( V_5 -> V_9 && V_5 -> V_9 -> V_39 )
return V_5 -> V_9 -> V_39 ( V_2 , V_16 , V_3 ) ;
snprintf ( V_38 , sizeof( V_38 ) , L_2 , V_16 ) ;
V_8 = F_9 ( V_5 -> V_11 -> V_12 , V_38 ,
F_10 ( V_3 ) ) ;
if ( F_3 ( V_8 ) )
return - V_13 ;
V_5 -> V_20 [ V_16 ] = V_3 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_16 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_8 ;
unsigned long long V_40 ;
if ( V_5 -> V_9 && V_5 -> V_9 -> V_41 )
return V_5 -> V_9 -> V_41 ( V_2 , V_16 , V_3 ) ;
V_8 = F_2 ( V_5 -> V_11 -> V_12 , L_3 , NULL , & V_40 ) ;
if ( F_3 ( V_8 ) )
return - V_13 ;
* V_3 = V_40 * 100 ;
return 0 ;
}
static int F_12 ( T_2 V_12 , char * V_38 ,
unsigned long * V_3 )
{
unsigned long long V_42 ;
T_1 V_8 ;
V_8 = F_2 ( V_12 , V_38 , NULL , & V_42 ) ;
if ( F_3 ( V_8 ) )
return - V_13 ;
* V_3 = F_5 ( V_42 ) ;
return 0 ;
}
struct V_4 * F_13 ( struct V_43 * V_11 ,
struct V_44 * V_9 )
{
struct V_4 * V_4 ;
T_1 V_8 ;
unsigned long long V_45 ;
int V_46 = 0 , V_17 ;
int V_47 ;
V_4 = F_14 ( sizeof( * V_4 ) ,
V_48 ) ;
if ( ! V_4 )
return F_15 ( - V_49 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_9 = V_9 ;
V_8 = F_2 ( V_11 -> V_12 , L_4 , NULL , & V_45 ) ;
if ( F_3 ( V_8 ) )
V_45 = 0 ;
else {
V_4 -> V_20 = F_14 (
sizeof( * V_4 -> V_20 ) *
V_45 , V_48 ) ;
if ( ! V_4 -> V_20 ) {
V_47 = - V_49 ;
goto V_50;
}
V_46 = F_16 ( V_45 ) - 1 ;
V_4 -> V_19 = V_45 ;
}
V_4 -> V_21 = - 1 ;
if ( ! F_12 ( V_11 -> V_12 , L_5 ,
& V_4 -> V_22 ) )
V_4 -> V_21 = V_45 ++ ;
V_4 -> V_25 = - 1 ;
if ( ! F_12 ( V_11 -> V_12 , L_6 ,
& V_4 -> V_26 ) )
V_4 -> V_25 = V_45 ++ ;
V_4 -> V_23 = - 1 ;
if ( ! F_12 ( V_11 -> V_12 , L_7 ,
& V_4 -> V_24 ) )
V_4 -> V_23 = V_45 ++ ;
for ( V_17 = 0 ; V_17 < V_27 ; V_17 ++ ) {
char V_38 [ 5 ] = { '_' , 'A' , 'C' , '0' + V_17 , '\0' } ;
if ( F_12 ( V_11 -> V_12 , V_38 ,
& V_4 -> V_28 [ V_17 ] . V_3 ) )
break;
V_4 -> V_28 [ V_17 ] . V_30 = V_45 ++ ;
V_4 -> V_28 [ V_17 ] . V_29 = true ;
}
V_4 -> V_14 = F_17 (
V_11 -> V_12 ) ;
V_4 -> V_2 = F_18 (
F_19 ( V_11 ) ,
V_45 ,
V_46 , V_4 ,
& V_51 ,
& V_52 ,
0 , 0 ) ;
if ( F_20 ( V_4 -> V_2 ) ) {
V_47 = F_21 ( V_4 -> V_2 ) ;
goto V_53;
}
return V_4 ;
V_53:
F_22 ( V_4 -> V_14 ) ;
F_23 ( V_4 -> V_20 ) ;
V_50:
F_23 ( V_4 ) ;
return F_15 ( V_47 ) ;
}
void F_24 ( struct V_4
* V_4 )
{
F_25 ( V_4 -> V_2 ) ;
F_22 ( V_4 -> V_14 ) ;
F_23 ( V_4 -> V_20 ) ;
F_23 ( V_4 ) ;
}
