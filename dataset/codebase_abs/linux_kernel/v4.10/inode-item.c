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
int F_6 ( struct V_1 * V_2 , T_2 V_17 ,
const char * V_3 , int V_4 ,
struct V_18 * * V_19 )
{
struct V_7 * V_8 ;
struct V_18 * V_20 ;
unsigned long V_10 ;
unsigned long V_11 ;
T_1 V_12 ;
T_1 V_13 = 0 ;
int V_21 ;
V_8 = V_2 -> V_15 [ 0 ] ;
V_12 = F_2 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
V_10 = F_3 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
while ( V_13 < V_12 ) {
V_20 = (struct V_18 * ) ( V_10 + V_13 ) ;
V_11 = ( unsigned long ) ( & V_20 -> V_3 ) ;
V_21 = F_7 ( V_8 , V_20 ) ;
if ( V_21 == V_4 &&
F_8 ( V_8 , V_20 ) == V_17 &&
( F_5 ( V_8 , V_3 , V_11 , V_4 ) == 0 ) ) {
if ( V_19 )
* V_19 = V_20 ;
return 1 ;
}
V_13 += V_21 + sizeof( * V_20 ) ;
}
return 0 ;
}
struct V_18 *
F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_1 * V_2 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , int V_27 ,
int V_28 )
{
int V_29 ;
struct V_30 V_31 ;
struct V_18 * V_20 ;
V_31 . V_32 = V_26 ;
V_31 . type = V_33 ;
V_31 . V_34 = F_10 ( V_17 , V_3 , V_4 ) ;
V_29 = F_11 ( V_23 , V_25 , & V_31 , V_2 , V_27 , V_28 ) ;
if ( V_29 < 0 )
return F_12 ( V_29 ) ;
if ( V_29 > 0 )
return NULL ;
if ( ! F_6 ( V_2 , V_17 , V_3 , V_4 , & V_20 ) )
return NULL ;
return V_20 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 ,
T_2 * V_35 )
{
struct V_1 * V_2 ;
struct V_30 V_31 ;
struct V_18 * V_20 ;
struct V_7 * V_8 ;
int V_29 ;
int V_36 = V_4 + sizeof( * V_20 ) ;
unsigned long V_10 ;
unsigned long V_37 ;
T_1 V_12 ;
V_31 . V_32 = V_26 ;
V_31 . type = V_33 ;
V_31 . V_34 = F_10 ( V_17 , V_3 , V_4 ) ;
V_2 = F_14 () ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_39 = 1 ;
V_29 = F_11 ( V_23 , V_25 , & V_31 , V_2 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_40 ;
if ( V_29 < 0 )
goto V_41;
if ( ! F_6 ( V_2 , V_17 ,
V_3 , V_4 , & V_20 ) ) {
F_15 ( V_25 -> V_42 , - V_40 , NULL ) ;
V_29 = - V_43 ;
goto V_41;
}
V_8 = V_2 -> V_15 [ 0 ] ;
V_12 = F_2 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
if ( V_35 )
* V_35 = F_16 ( V_8 , V_20 ) ;
if ( V_36 == V_12 ) {
V_29 = F_17 ( V_23 , V_25 , V_2 ) ;
goto V_41;
}
V_10 = ( unsigned long ) V_20 ;
V_37 = F_3 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
F_18 ( V_8 , V_10 , V_10 + V_36 ,
V_12 - ( V_10 + V_36 - V_37 ) ) ;
F_19 ( V_25 -> V_42 , V_2 , V_12 - V_36 , 1 ) ;
V_41:
F_20 ( V_2 ) ;
return V_29 ;
}
int F_21 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , T_2 * V_35 )
{
struct V_1 * V_2 ;
struct V_30 V_31 ;
struct V_5 * V_9 ;
struct V_7 * V_8 ;
unsigned long V_10 ;
unsigned long V_37 ;
T_1 V_12 ;
T_1 V_44 ;
int V_29 ;
int V_45 = 0 ;
int V_36 = V_4 + sizeof( * V_9 ) ;
V_31 . V_32 = V_26 ;
V_31 . V_34 = V_17 ;
V_31 . type = V_46 ;
V_2 = F_14 () ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_39 = 1 ;
V_29 = F_11 ( V_23 , V_25 , & V_31 , V_2 , - 1 , 1 ) ;
if ( V_29 > 0 ) {
V_29 = - V_40 ;
V_45 = 1 ;
goto V_41;
} else if ( V_29 < 0 ) {
goto V_41;
}
if ( ! F_1 ( V_2 , V_3 , V_4 , & V_9 ) ) {
V_29 = - V_40 ;
V_45 = 1 ;
goto V_41;
}
V_8 = V_2 -> V_15 [ 0 ] ;
V_12 = F_2 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
if ( V_35 )
* V_35 = F_22 ( V_8 , V_9 ) ;
if ( V_36 == V_12 ) {
V_29 = F_17 ( V_23 , V_25 , V_2 ) ;
goto V_41;
}
V_10 = ( unsigned long ) V_9 ;
V_44 = V_4 + sizeof( * V_9 ) ;
V_37 = F_3 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
F_18 ( V_8 , V_10 , V_10 + V_44 ,
V_12 - ( V_10 + V_44 - V_37 ) ) ;
F_19 ( V_25 -> V_42 , V_2 , V_12 - V_44 , 1 ) ;
V_41:
F_20 ( V_2 ) ;
if ( V_45 ) {
return F_13 ( V_23 , V_25 , V_3 , V_4 ,
V_26 , V_17 , V_35 ) ;
}
return V_29 ;
}
static int F_23 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , T_2 V_35 )
{
struct V_18 * V_20 ;
int V_29 ;
int V_27 = V_4 + sizeof( * V_20 ) ;
unsigned long V_10 ;
struct V_1 * V_2 ;
struct V_30 V_31 ;
struct V_7 * V_8 ;
struct V_47 * V_48 ;
V_31 . V_32 = V_26 ;
V_31 . type = V_33 ;
V_31 . V_34 = F_10 ( V_17 , V_3 , V_4 ) ;
V_2 = F_14 () ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_39 = 1 ;
V_29 = F_24 ( V_23 , V_25 , V_2 , & V_31 ,
V_27 ) ;
if ( V_29 == - V_49 ) {
if ( F_6 ( V_2 , V_17 ,
V_3 , V_4 , NULL ) )
goto V_41;
F_25 ( V_25 -> V_42 , V_2 , V_27 ) ;
V_29 = 0 ;
}
if ( V_29 < 0 )
goto V_41;
V_8 = V_2 -> V_15 [ 0 ] ;
V_48 = F_26 ( V_2 -> V_16 [ 0 ] ) ;
V_10 = ( unsigned long ) F_27 ( V_8 , V_2 -> V_16 [ 0 ] , char ) ;
V_10 += F_28 ( V_8 , V_48 ) - V_27 ;
V_20 = (struct V_18 * ) V_10 ;
F_29 ( V_2 -> V_15 [ 0 ] , V_20 , V_4 ) ;
F_30 ( V_2 -> V_15 [ 0 ] , V_20 , V_35 ) ;
F_31 ( V_2 -> V_15 [ 0 ] , V_20 , V_17 ) ;
V_10 = ( unsigned long ) & V_20 -> V_3 ;
F_32 ( V_2 -> V_15 [ 0 ] , V_3 , V_10 , V_4 ) ;
F_33 ( V_2 -> V_15 [ 0 ] ) ;
V_41:
F_20 ( V_2 ) ;
return V_29 ;
}
int F_34 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , T_2 V_35 )
{
struct V_50 * V_42 = V_25 -> V_42 ;
struct V_1 * V_2 ;
struct V_30 V_31 ;
struct V_5 * V_9 ;
unsigned long V_10 ;
int V_29 ;
int V_27 = V_4 + sizeof( * V_9 ) ;
V_31 . V_32 = V_26 ;
V_31 . V_34 = V_17 ;
V_31 . type = V_46 ;
V_2 = F_14 () ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_39 = 1 ;
V_2 -> V_51 = 1 ;
V_29 = F_24 ( V_23 , V_25 , V_2 , & V_31 ,
V_27 ) ;
if ( V_29 == - V_49 ) {
T_1 V_52 ;
if ( F_1 ( V_2 , V_3 , V_4 , & V_9 ) )
goto V_41;
V_52 = F_2 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ) ;
F_25 ( V_42 , V_2 , V_27 ) ;
V_9 = F_27 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ,
struct V_5 ) ;
V_9 = (struct V_5 * ) ( ( unsigned long ) V_9 + V_52 ) ;
F_35 ( V_2 -> V_15 [ 0 ] , V_9 , V_4 ) ;
F_36 ( V_2 -> V_15 [ 0 ] , V_9 , V_35 ) ;
V_10 = ( unsigned long ) ( V_9 + 1 ) ;
V_29 = 0 ;
} else if ( V_29 < 0 ) {
if ( V_29 == - V_53 ) {
if ( F_1 ( V_2 , V_3 , V_4 , & V_9 ) )
V_29 = - V_49 ;
else
V_29 = - V_54 ;
}
goto V_41;
} else {
V_9 = F_27 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ,
struct V_5 ) ;
F_35 ( V_2 -> V_15 [ 0 ] , V_9 , V_4 ) ;
F_36 ( V_2 -> V_15 [ 0 ] , V_9 , V_35 ) ;
V_10 = ( unsigned long ) ( V_9 + 1 ) ;
}
F_32 ( V_2 -> V_15 [ 0 ] , V_3 , V_10 , V_4 ) ;
F_33 ( V_2 -> V_15 [ 0 ] ) ;
V_41:
F_20 ( V_2 ) ;
if ( V_29 == - V_54 ) {
struct V_55 * V_56 = V_42 -> V_57 ;
if ( F_37 ( V_56 )
& V_58 )
V_29 = F_23 ( V_23 , V_25 , V_3 ,
V_4 ,
V_26 ,
V_17 , V_35 ) ;
}
return V_29 ;
}
int F_38 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_1 * V_2 , T_2 V_32 )
{
struct V_30 V_31 ;
int V_29 ;
V_31 . V_32 = V_32 ;
V_31 . type = V_59 ;
V_31 . V_34 = 0 ;
V_29 = F_24 ( V_23 , V_25 , V_2 , & V_31 ,
sizeof( struct V_60 ) ) ;
return V_29 ;
}
int F_39 ( struct V_22 * V_23 , struct V_24
* V_25 , struct V_1 * V_2 ,
struct V_30 * V_61 , int V_62 )
{
int V_27 = V_62 < 0 ? - 1 : 0 ;
int V_28 = V_62 != 0 ;
int V_29 ;
int V_63 ;
struct V_7 * V_8 ;
struct V_30 V_64 ;
V_29 = F_11 ( V_23 , V_25 , V_61 , V_2 , V_27 , V_28 ) ;
if ( V_29 > 0 && V_61 -> type == V_65 &&
V_61 -> V_34 == ( T_2 ) - 1 && V_2 -> V_16 [ 0 ] != 0 ) {
V_63 = V_2 -> V_16 [ 0 ] - 1 ;
V_8 = V_2 -> V_15 [ 0 ] ;
F_40 ( V_8 , & V_64 , V_63 ) ;
if ( V_64 . V_32 == V_61 -> V_32 &&
V_64 . type == V_61 -> type ) {
V_2 -> V_16 [ 0 ] -- ;
return 0 ;
}
}
return V_29 ;
}
