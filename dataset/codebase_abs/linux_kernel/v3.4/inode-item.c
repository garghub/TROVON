static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
int V_4 , struct V_5 * * V_6 )
{
struct V_7 * V_8 ;
struct V_5 * V_9 ;
unsigned long V_10 ;
unsigned long V_11 ;
T_1 V_12 ;
T_1 V_13 = 0 ;
int V_14 ;
V_8 = V_2 -> V_15 [ 0 ] ;
V_12 = F_2 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
V_10 = F_3 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
while ( V_13 < V_12 ) {
V_9 = (struct V_5 * ) ( V_10 + V_13 ) ;
V_14 = F_4 ( V_8 , V_9 ) ;
V_11 = ( unsigned long ) ( V_9 + 1 ) ;
V_13 += V_14 + sizeof( * V_9 ) ;
if ( V_14 != V_4 )
continue;
if ( F_5 ( V_8 , V_3 , V_11 , V_4 ) == 0 ) {
* V_6 = V_9 ;
return 1 ;
}
}
return 0 ;
}
struct V_5 *
F_6 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_1 * V_2 ,
const char * V_3 , int V_4 ,
T_2 V_21 , T_2 V_22 , int V_23 )
{
struct V_24 V_25 ;
struct V_5 * V_9 ;
int V_26 = V_23 < 0 ? - 1 : 0 ;
int V_27 = V_23 != 0 ;
int V_28 ;
V_25 . V_29 = V_21 ;
V_25 . type = V_30 ;
V_25 . V_31 = V_22 ;
V_28 = F_7 ( V_18 , V_20 , & V_25 , V_2 , V_26 , V_27 ) ;
if ( V_28 < 0 )
return F_8 ( V_28 ) ;
if ( V_28 > 0 )
return NULL ;
if ( ! F_1 ( V_2 , V_3 , V_4 , & V_9 ) )
return NULL ;
return V_9 ;
}
int F_9 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_3 , int V_4 ,
T_2 V_21 , T_2 V_22 , T_2 * V_32 )
{
struct V_1 * V_2 ;
struct V_24 V_25 ;
struct V_5 * V_9 ;
struct V_7 * V_8 ;
unsigned long V_10 ;
unsigned long V_33 ;
T_1 V_12 ;
T_1 V_34 ;
int V_28 ;
int V_35 = V_4 + sizeof( * V_9 ) ;
V_25 . V_29 = V_21 ;
V_25 . V_31 = V_22 ;
F_10 ( & V_25 , V_30 ) ;
V_2 = F_11 () ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_37 = 1 ;
V_28 = F_7 ( V_18 , V_20 , & V_25 , V_2 , - 1 , 1 ) ;
if ( V_28 > 0 ) {
V_28 = - V_38 ;
goto V_39;
} else if ( V_28 < 0 ) {
goto V_39;
}
if ( ! F_1 ( V_2 , V_3 , V_4 , & V_9 ) ) {
V_28 = - V_38 ;
goto V_39;
}
V_8 = V_2 -> V_15 [ 0 ] ;
V_12 = F_2 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
if ( V_32 )
* V_32 = F_12 ( V_8 , V_9 ) ;
if ( V_35 == V_12 ) {
V_28 = F_13 ( V_18 , V_20 , V_2 ) ;
goto V_39;
}
V_10 = ( unsigned long ) V_9 ;
V_34 = V_4 + sizeof( * V_9 ) ;
V_33 = F_3 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
F_14 ( V_8 , V_10 , V_10 + V_34 ,
V_12 - ( V_10 + V_34 - V_33 ) ) ;
F_15 ( V_18 , V_20 , V_2 ,
V_12 - V_34 , 1 ) ;
V_39:
F_16 ( V_2 ) ;
return V_28 ;
}
int F_17 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_3 , int V_4 ,
T_2 V_21 , T_2 V_22 , T_2 V_32 )
{
struct V_1 * V_2 ;
struct V_24 V_25 ;
struct V_5 * V_9 ;
unsigned long V_10 ;
int V_28 ;
int V_26 = V_4 + sizeof( * V_9 ) ;
V_25 . V_29 = V_21 ;
V_25 . V_31 = V_22 ;
F_10 ( & V_25 , V_30 ) ;
V_2 = F_11 () ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_37 = 1 ;
V_28 = F_18 ( V_18 , V_20 , V_2 , & V_25 ,
V_26 ) ;
if ( V_28 == - V_40 ) {
T_1 V_41 ;
if ( F_1 ( V_2 , V_3 , V_4 , & V_9 ) )
goto V_39;
V_41 = F_2 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ) ;
F_19 ( V_18 , V_20 , V_2 , V_26 ) ;
V_9 = F_20 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ,
struct V_5 ) ;
V_9 = (struct V_5 * ) ( ( unsigned long ) V_9 + V_41 ) ;
F_21 ( V_2 -> V_15 [ 0 ] , V_9 , V_4 ) ;
F_22 ( V_2 -> V_15 [ 0 ] , V_9 , V_32 ) ;
V_10 = ( unsigned long ) ( V_9 + 1 ) ;
V_28 = 0 ;
} else if ( V_28 < 0 ) {
if ( V_28 == - V_42 )
V_28 = - V_43 ;
goto V_39;
} else {
V_9 = F_20 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ,
struct V_5 ) ;
F_21 ( V_2 -> V_15 [ 0 ] , V_9 , V_4 ) ;
F_22 ( V_2 -> V_15 [ 0 ] , V_9 , V_32 ) ;
V_10 = ( unsigned long ) ( V_9 + 1 ) ;
}
F_23 ( V_2 -> V_15 [ 0 ] , V_3 , V_10 , V_4 ) ;
F_24 ( V_2 -> V_15 [ 0 ] ) ;
V_39:
F_16 ( V_2 ) ;
return V_28 ;
}
int F_25 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_1 * V_2 , T_2 V_29 )
{
struct V_24 V_25 ;
int V_28 ;
V_25 . V_29 = V_29 ;
F_10 ( & V_25 , V_44 ) ;
V_25 . V_31 = 0 ;
V_28 = F_18 ( V_18 , V_20 , V_2 , & V_25 ,
sizeof( struct V_45 ) ) ;
return V_28 ;
}
int F_26 ( struct V_17 * V_18 , struct V_19
* V_20 , struct V_1 * V_2 ,
struct V_24 * V_46 , int V_23 )
{
int V_26 = V_23 < 0 ? - 1 : 0 ;
int V_27 = V_23 != 0 ;
int V_28 ;
int V_47 ;
struct V_7 * V_8 ;
struct V_24 V_48 ;
V_28 = F_7 ( V_18 , V_20 , V_46 , V_2 , V_26 , V_27 ) ;
if ( V_28 > 0 && F_27 ( V_46 ) == V_49 &&
V_46 -> V_31 == ( T_2 ) - 1 && V_2 -> V_16 [ 0 ] != 0 ) {
V_47 = V_2 -> V_16 [ 0 ] - 1 ;
V_8 = V_2 -> V_15 [ 0 ] ;
F_28 ( V_8 , & V_48 , V_47 ) ;
if ( V_48 . V_29 == V_46 -> V_29 &&
F_27 ( & V_48 ) == F_27 ( V_46 ) ) {
V_2 -> V_16 [ 0 ] -- ;
return 0 ;
}
}
return V_28 ;
}
