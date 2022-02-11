static int F_1 ( struct V_1 * V_2 ,
int * V_3 )
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
int V_16 , int * V_3 )
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
int V_16 , int V_3 )
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
int V_16 , int * V_3 )
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
int * V_3 )
{
unsigned long long V_42 ;
T_1 V_8 ;
V_8 = F_2 ( V_12 , V_38 , NULL , & V_42 ) ;
if ( F_3 ( V_8 ) )
return - V_13 ;
* V_3 = F_5 ( V_42 ) ;
return 0 ;
}
int F_13 ( struct V_4 * V_43 )
{
int V_44 = V_43 -> V_19 ;
int V_17 ;
V_43 -> V_21 = - 1 ;
if ( ! F_12 ( V_43 -> V_11 -> V_12 , L_4 ,
& V_43 -> V_22 ) )
V_43 -> V_21 = V_44 ++ ;
V_43 -> V_25 = - 1 ;
if ( ! F_12 ( V_43 -> V_11 -> V_12 , L_5 ,
& V_43 -> V_26 ) )
V_43 -> V_25 = V_44 ++ ;
V_43 -> V_23 = - 1 ;
if ( ! F_12 ( V_43 -> V_11 -> V_12 , L_6 ,
& V_43 -> V_24 ) )
V_43 -> V_23 = V_44 ++ ;
for ( V_17 = 0 ; V_17 < V_27 ; V_17 ++ ) {
char V_38 [ 5 ] = { '_' , 'A' , 'C' , '0' + V_17 , '\0' } ;
if ( F_12 ( V_43 -> V_11 -> V_12 ,
V_38 ,
& V_43 -> V_28 [ V_17 ] . V_3 ) )
break;
V_43 -> V_28 [ V_17 ] . V_30 = V_44 ++ ;
V_43 -> V_28 [ V_17 ] . V_29 = true ;
}
return V_44 ;
}
struct V_4 * F_14 ( struct V_45 * V_11 ,
struct V_46 * V_9 )
{
struct V_4 * V_4 ;
T_1 V_8 ;
unsigned long long V_44 ;
int V_47 = 0 ;
int V_48 ;
V_4 = F_15 ( sizeof( * V_4 ) ,
V_49 ) ;
if ( ! V_4 )
return F_16 ( - V_50 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_9 = V_9 ;
V_8 = F_2 ( V_11 -> V_12 , L_7 , NULL , & V_44 ) ;
if ( F_3 ( V_8 ) )
V_44 = 0 ;
else {
V_4 -> V_20 = F_15 (
sizeof( * V_4 -> V_20 ) *
V_44 , V_49 ) ;
if ( ! V_4 -> V_20 ) {
V_48 = - V_50 ;
goto V_51;
}
V_47 = F_17 ( V_44 ) - 1 ;
V_4 -> V_19 = V_44 ;
}
V_44 = F_13 ( V_4 ) ;
V_4 -> V_14 = F_18 (
V_11 -> V_12 ) ;
V_4 -> V_2 = F_19 (
F_20 ( V_11 ) ,
V_44 ,
V_47 , V_4 ,
& V_52 ,
& V_53 ,
0 , 0 ) ;
if ( F_21 ( V_4 -> V_2 ) ) {
V_48 = F_22 ( V_4 -> V_2 ) ;
goto V_54;
}
return V_4 ;
V_54:
F_23 ( V_4 -> V_14 ) ;
F_24 ( V_4 -> V_20 ) ;
V_51:
F_24 ( V_4 ) ;
return F_16 ( V_48 ) ;
}
void F_25 ( struct V_4
* V_4 )
{
F_26 ( V_4 -> V_2 ) ;
F_23 ( V_4 -> V_14 ) ;
F_24 ( V_4 -> V_20 ) ;
F_24 ( V_4 ) ;
}
