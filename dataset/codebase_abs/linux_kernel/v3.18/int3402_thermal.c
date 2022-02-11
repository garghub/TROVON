static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long long V_7 ;
T_1 V_8 ;
V_8 = F_2 ( V_5 -> V_9 , L_1 , NULL , & V_7 ) ;
if ( F_3 ( V_8 ) )
return - V_10 ;
* V_3 = F_4 ( V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_11 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_12 ;
if ( V_11 < V_5 -> V_13 )
* V_3 = V_5 -> V_14 [ V_11 ] ;
else if ( V_11 == V_5 -> V_15 )
* V_3 = V_5 -> V_16 ;
else if ( V_11 == V_5 -> V_17 )
* V_3 = V_5 -> V_18 ;
else if ( V_11 == V_5 -> V_19 )
* V_3 = V_5 -> V_20 ;
else {
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ ) {
if ( V_5 -> V_22 [ V_12 ] . V_23 &&
V_5 -> V_22 [ V_12 ] . V_24 == V_11 ) {
* V_3 = V_5 -> V_22 [ V_12 ] . V_3 ;
break;
}
}
if ( V_12 == V_21 )
return - V_25 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_11 , enum V_26 * type )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_12 ;
if ( V_11 < V_5 -> V_13 )
* type = V_27 ;
else if ( V_11 == V_5 -> V_15 )
* type = V_28 ;
else if ( V_11 == V_5 -> V_19 )
* type = V_29 ;
else if ( V_11 == V_5 -> V_17 )
* type = V_27 ;
else {
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ ) {
if ( V_5 -> V_22 [ V_12 ] . V_23 &&
V_5 -> V_22 [ V_12 ] . V_24 == V_11 ) {
* type = V_30 ;
break;
}
}
if ( V_12 == V_21 )
return - V_25 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_11 ,
unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_8 ;
char V_31 [ 10 ] ;
snprintf ( V_31 , sizeof( V_31 ) , L_2 , V_11 ) ;
V_8 = F_8 ( V_5 -> V_9 , V_31 ,
F_9 ( V_3 ) ) ;
if ( F_3 ( V_8 ) )
return - V_32 ;
V_5 -> V_14 [ V_11 ] = V_3 ;
return 0 ;
}
static int F_10 ( T_2 V_9 , char * V_31 ,
unsigned long * V_3 )
{
unsigned long long V_33 ;
T_1 V_8 ;
V_8 = F_2 ( V_9 , V_31 , NULL , & V_33 ) ;
if ( F_3 ( V_8 ) )
return - V_32 ;
* V_3 = F_4 ( V_33 ) ;
return 0 ;
}
static int F_11 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = F_12 ( & V_35 -> V_38 ) ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
T_1 V_8 ;
unsigned long long V_39 ;
int V_40 = 0 , V_12 ;
if ( ! F_13 ( V_37 -> V_9 , L_1 ) )
return - V_10 ;
V_5 = F_14 ( & V_35 -> V_38 , sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
return - V_42 ;
V_8 = F_2 ( V_37 -> V_9 , L_3 , NULL , & V_39 ) ;
if ( F_3 ( V_8 ) )
V_39 = 0 ;
else {
V_5 -> V_14 = F_14 ( & V_35 -> V_38 ,
sizeof( * V_5 -> V_14 ) * V_39 , V_41 ) ;
if ( ! V_5 -> V_14 )
return - V_42 ;
V_40 = V_39 - 1 ;
V_5 -> V_9 = V_37 -> V_9 ;
V_5 -> V_13 = V_39 ;
}
V_5 -> V_15 = - 1 ;
if ( ! F_10 ( V_37 -> V_9 , L_4 , & V_5 -> V_16 ) )
V_5 -> V_15 = V_39 ++ ;
V_5 -> V_19 = - 1 ;
if ( ! F_10 ( V_37 -> V_9 , L_5 , & V_5 -> V_20 ) )
V_5 -> V_19 = V_39 ++ ;
V_5 -> V_17 = - 1 ;
if ( ! F_10 ( V_37 -> V_9 , L_6 , & V_5 -> V_18 ) )
V_5 -> V_17 = V_39 ++ ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ ) {
char V_31 [ 5 ] = { '_' , 'A' , 'C' , '0' + V_12 , '\0' } ;
if ( F_10 ( V_37 -> V_9 , V_31 ,
& V_5 -> V_22 [ V_12 ] . V_3 ) )
break;
V_5 -> V_22 [ V_12 ] . V_24 = V_39 ++ ;
V_5 -> V_22 [ V_12 ] . V_23 = true ;
}
V_2 = F_15 ( F_16 ( V_37 ) , V_39 ,
V_40 , V_5 ,
& V_43 ,
& V_44 ,
0 , 0 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
F_19 ( V_35 , V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_21 ( V_35 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
