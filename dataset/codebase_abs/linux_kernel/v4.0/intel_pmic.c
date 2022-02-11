static int F_1 ( int V_1 , struct V_2 * V_3 ,
int V_4 , int * V_5 , int * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
if ( V_3 [ V_7 ] . V_1 == V_1 ) {
* V_5 = V_3 [ V_7 ] . V_5 ;
if ( V_6 )
* V_6 = V_3 [ V_7 ] . V_6 ;
return 0 ;
}
}
return - V_8 ;
}
static T_1 F_2 ( T_2 V_9 ,
T_3 V_1 , T_2 V_10 , T_4 * V_11 ,
void * V_12 , void * V_13 )
{
struct V_14 * V_15 = V_13 ;
struct V_16 * V_16 = V_15 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_19 ;
int V_5 , V_6 , V_20 ;
if ( V_10 != 32 || ! V_11 )
return V_21 ;
if ( V_9 == V_22 && ! ( * V_11 == 0 || * V_11 == 1 ) )
return V_21 ;
V_20 = F_1 ( V_1 , V_18 -> V_23 ,
V_18 -> V_24 , & V_5 , & V_6 ) ;
if ( V_20 == - V_8 )
return V_21 ;
F_3 ( & V_15 -> V_25 ) ;
V_20 = V_9 == V_26 ?
V_18 -> V_27 ( V_16 , V_5 , V_6 , V_11 ) :
V_18 -> V_28 ( V_16 , V_5 , V_6 , * V_11 == 1 ) ;
F_4 ( & V_15 -> V_25 ) ;
return V_20 ? V_29 : V_30 ;
}
static int F_5 ( struct V_14 * V_15 ,
int V_5 , T_4 * V_31 )
{
int V_32 , V_33 ;
if ( ! V_15 -> V_19 -> V_34 )
return - V_35 ;
V_32 = V_15 -> V_19 -> V_34 ( V_15 -> V_16 , V_5 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! V_15 -> V_36 ) {
* V_31 = V_32 ;
return 0 ;
}
V_33 = F_6 ( V_15 -> V_36 , V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
* V_31 = V_33 ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 , int V_5 ,
T_2 V_9 , T_4 * V_31 )
{
return V_9 == V_26 ?
F_5 ( V_15 , V_5 , V_31 ) : - V_37 ;
}
static int F_8 ( struct V_14 * V_15 , int V_5 ,
T_2 V_9 , T_4 * V_31 )
{
int V_32 ;
if ( V_9 == V_26 )
return F_5 ( V_15 , V_5 , V_31 ) ;
if ( ! V_15 -> V_19 -> V_38 )
return - V_35 ;
if ( V_15 -> V_36 ) {
V_32 = F_9 ( V_15 -> V_36 , * V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
} else {
V_32 = * V_31 ;
}
return V_15 -> V_19 -> V_38 ( V_15 -> V_16 , V_5 , V_32 ) ;
}
static int F_10 ( struct V_14 * V_15 , int V_5 ,
T_2 V_9 , T_4 * V_31 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_16 * V_16 = V_15 -> V_16 ;
if ( ! V_18 -> V_39 || ! V_18 -> V_40 )
return - V_35 ;
if ( V_9 == V_26 )
return V_18 -> V_39 ( V_16 , V_5 , V_31 ) ;
if ( * V_31 != 0 && * V_31 != 1 )
return - V_37 ;
return V_18 -> V_40 ( V_16 , V_5 , * V_31 ) ;
}
static bool F_11 ( int V_1 )
{
return ( V_1 <= 0x3c ) && ! ( V_1 % 12 ) ;
}
static bool F_12 ( int V_1 )
{
return ( V_1 >= 4 && V_1 <= 0x40 && ! ( ( V_1 - 4 ) % 12 ) ) ||
( V_1 >= 8 && V_1 <= 0x44 && ! ( ( V_1 - 8 ) % 12 ) ) ;
}
static bool F_13 ( int V_1 )
{
return V_1 >= 0x48 && V_1 <= 0x5c ;
}
static T_1 F_14 ( T_2 V_9 ,
T_3 V_1 , T_2 V_10 , T_4 * V_11 ,
void * V_12 , void * V_13 )
{
struct V_14 * V_15 = V_13 ;
struct V_17 * V_18 = V_15 -> V_19 ;
int V_5 , V_20 ;
if ( V_10 != 32 || ! V_11 )
return V_21 ;
V_20 = F_1 ( V_1 , V_18 -> V_41 ,
V_18 -> V_42 , & V_5 , NULL ) ;
if ( V_20 == - V_8 )
return V_21 ;
F_3 ( & V_15 -> V_25 ) ;
if ( F_11 ( V_1 ) )
V_20 = F_7 ( V_15 , V_5 , V_9 , V_11 ) ;
else if ( F_12 ( V_1 ) )
V_20 = F_8 ( V_15 , V_5 , V_9 , V_11 ) ;
else if ( F_13 ( V_1 ) )
V_20 = F_10 ( V_15 , V_5 , V_9 , V_11 ) ;
else
V_20 = - V_37 ;
F_4 ( & V_15 -> V_25 ) ;
if ( V_20 < 0 ) {
if ( V_20 == - V_37 )
return V_21 ;
else
return V_29 ;
}
return V_30 ;
}
int F_15 ( struct V_43 * V_44 , T_5 V_45 ,
struct V_16 * V_16 ,
struct V_17 * V_18 )
{
T_1 V_46 ;
struct V_14 * V_15 ;
int V_47 ;
if ( ! V_44 || ! V_16 || ! V_18 )
return - V_37 ;
if ( ! V_45 )
return - V_48 ;
V_15 = F_16 ( V_44 , sizeof( * V_15 ) , V_49 ) ;
if ( ! V_15 )
return - V_50 ;
F_17 ( & V_15 -> V_25 ) ;
V_15 -> V_16 = V_16 ;
V_15 -> V_36 = F_18 ( V_45 ) ;
V_46 = F_19 ( V_45 ,
V_51 ,
F_2 ,
NULL , V_15 ) ;
if ( F_20 ( V_46 ) ) {
V_47 = - V_48 ;
goto V_52;
}
V_46 = F_19 ( V_45 ,
V_53 ,
F_14 ,
NULL , V_15 ) ;
if ( F_20 ( V_46 ) ) {
F_21 ( V_45 , V_51 ,
F_2 ) ;
V_47 = - V_48 ;
goto V_52;
}
V_15 -> V_19 = V_18 ;
return 0 ;
V_52:
F_22 ( V_15 -> V_36 ) ;
return V_47 ;
}
