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
static struct V_5 *
F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_1 * V_2 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , int V_27 ,
int V_28 )
{
int V_29 ;
struct V_30 V_31 ;
struct V_5 * V_9 ;
V_31 . V_32 = V_26 ;
V_31 . type = V_33 ;
V_31 . V_34 = V_17 ;
V_29 = F_10 ( V_23 , V_25 , & V_31 , V_2 , V_27 , V_28 ) ;
if ( V_29 < 0 )
return F_11 ( V_29 ) ;
if ( V_29 > 0 )
return NULL ;
if ( ! F_1 ( V_2 , V_3 , V_4 , & V_9 ) )
return NULL ;
return V_9 ;
}
struct V_18 *
F_12 ( struct V_22 * V_23 ,
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
V_31 . type = V_35 ;
V_31 . V_34 = F_13 ( V_17 , V_3 , V_4 ) ;
V_29 = F_10 ( V_23 , V_25 , & V_31 , V_2 , V_27 , V_28 ) ;
if ( V_29 < 0 )
return F_11 ( V_29 ) ;
if ( V_29 > 0 )
return NULL ;
if ( ! F_6 ( V_2 , V_17 , V_3 , V_4 , & V_20 ) )
return NULL ;
return V_20 ;
}
int F_14 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_1 * V_2 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , int V_36 ,
T_2 * V_37 )
{
struct V_5 * V_9 ;
struct V_18 * V_20 ;
int V_27 = V_36 < 0 ? - 1 : 0 ;
int V_28 = V_36 != 0 ;
V_9 = F_9 ( V_23 , V_25 , V_2 , V_3 , V_4 ,
V_26 , V_17 , V_27 ,
V_28 ) ;
if ( F_15 ( V_9 ) )
return F_16 ( V_9 ) ;
if ( V_9 != NULL ) {
* V_37 = F_17 ( V_2 -> V_15 [ 0 ] , V_9 ) ;
return 0 ;
}
F_18 ( V_2 ) ;
V_20 = F_12 ( V_23 , V_25 , V_2 , V_3 ,
V_4 , V_26 ,
V_17 , V_27 , V_28 ) ;
if ( F_15 ( V_20 ) )
return F_16 ( V_20 ) ;
if ( V_20 ) {
* V_37 = F_19 ( V_2 -> V_15 [ 0 ] , V_20 ) ;
return 0 ;
}
return - V_38 ;
}
static int F_20 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 ,
T_2 * V_39 )
{
struct V_1 * V_2 ;
struct V_30 V_31 ;
struct V_18 * V_20 ;
struct V_7 * V_8 ;
int V_29 ;
int V_40 = V_4 + sizeof( * V_20 ) ;
unsigned long V_10 ;
unsigned long V_41 ;
T_1 V_12 ;
V_31 . V_32 = V_26 ;
F_21 ( & V_31 , V_35 ) ;
V_31 . V_34 = F_13 ( V_17 , V_3 , V_4 ) ;
V_2 = F_22 () ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_43 = 1 ;
V_29 = F_10 ( V_23 , V_25 , & V_31 , V_2 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_38 ;
if ( V_29 < 0 )
goto V_44;
if ( ! F_6 ( V_2 , V_17 ,
V_3 , V_4 , & V_20 ) ) {
F_23 ( V_25 -> V_45 , - V_38 ) ;
V_29 = - V_46 ;
goto V_44;
}
V_8 = V_2 -> V_15 [ 0 ] ;
V_12 = F_2 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
if ( V_39 )
* V_39 = F_19 ( V_8 , V_20 ) ;
if ( V_40 == V_12 ) {
V_29 = F_24 ( V_23 , V_25 , V_2 ) ;
goto V_44;
}
V_10 = ( unsigned long ) V_20 ;
V_41 = F_3 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
F_25 ( V_8 , V_10 , V_10 + V_40 ,
V_12 - ( V_10 + V_40 - V_41 ) ) ;
F_26 ( V_25 , V_2 , V_12 - V_40 , 1 ) ;
V_44:
F_27 ( V_2 ) ;
return V_29 ;
}
int F_28 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , T_2 * V_39 )
{
struct V_1 * V_2 ;
struct V_30 V_31 ;
struct V_5 * V_9 ;
struct V_7 * V_8 ;
unsigned long V_10 ;
unsigned long V_41 ;
T_1 V_12 ;
T_1 V_47 ;
int V_29 ;
int V_48 = 0 ;
int V_40 = V_4 + sizeof( * V_9 ) ;
V_31 . V_32 = V_26 ;
V_31 . V_34 = V_17 ;
F_21 ( & V_31 , V_33 ) ;
V_2 = F_22 () ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_43 = 1 ;
V_29 = F_10 ( V_23 , V_25 , & V_31 , V_2 , - 1 , 1 ) ;
if ( V_29 > 0 ) {
V_29 = - V_38 ;
V_48 = 1 ;
goto V_44;
} else if ( V_29 < 0 ) {
goto V_44;
}
if ( ! F_1 ( V_2 , V_3 , V_4 , & V_9 ) ) {
V_29 = - V_38 ;
V_48 = 1 ;
goto V_44;
}
V_8 = V_2 -> V_15 [ 0 ] ;
V_12 = F_2 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
if ( V_39 )
* V_39 = F_17 ( V_8 , V_9 ) ;
if ( V_40 == V_12 ) {
V_29 = F_24 ( V_23 , V_25 , V_2 ) ;
goto V_44;
}
V_10 = ( unsigned long ) V_9 ;
V_47 = V_4 + sizeof( * V_9 ) ;
V_41 = F_3 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
F_25 ( V_8 , V_10 , V_10 + V_47 ,
V_12 - ( V_10 + V_47 - V_41 ) ) ;
F_26 ( V_25 , V_2 , V_12 - V_47 , 1 ) ;
V_44:
F_27 ( V_2 ) ;
if ( V_48 ) {
return F_20 ( V_23 , V_25 , V_3 , V_4 ,
V_26 , V_17 , V_39 ) ;
}
return V_29 ;
}
static int F_29 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , T_2 V_39 )
{
struct V_18 * V_20 ;
int V_29 ;
int V_27 = V_4 + sizeof( * V_20 ) ;
unsigned long V_10 ;
struct V_1 * V_2 ;
struct V_30 V_31 ;
struct V_7 * V_8 ;
struct V_49 * V_50 ;
V_31 . V_32 = V_26 ;
V_31 . type = V_35 ;
V_31 . V_34 = F_13 ( V_17 , V_3 , V_4 ) ;
V_2 = F_22 () ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_43 = 1 ;
V_29 = F_30 ( V_23 , V_25 , V_2 , & V_31 ,
V_27 ) ;
if ( V_29 == - V_51 ) {
if ( F_6 ( V_2 , V_17 ,
V_3 , V_4 , NULL ) )
goto V_44;
F_31 ( V_25 , V_2 , V_27 ) ;
V_29 = 0 ;
}
if ( V_29 < 0 )
goto V_44;
V_8 = V_2 -> V_15 [ 0 ] ;
V_50 = F_32 ( V_8 , V_2 -> V_16 [ 0 ] ) ;
V_10 = ( unsigned long ) F_33 ( V_8 , V_2 -> V_16 [ 0 ] , char ) ;
V_10 += F_34 ( V_8 , V_50 ) - V_27 ;
V_20 = (struct V_18 * ) V_10 ;
F_35 ( V_2 -> V_15 [ 0 ] , V_20 , V_4 ) ;
F_36 ( V_2 -> V_15 [ 0 ] , V_20 , V_39 ) ;
F_37 ( V_2 -> V_15 [ 0 ] , V_20 , V_17 ) ;
V_10 = ( unsigned long ) & V_20 -> V_3 ;
F_38 ( V_2 -> V_15 [ 0 ] , V_3 , V_10 , V_4 ) ;
F_39 ( V_2 -> V_15 [ 0 ] ) ;
V_44:
F_27 ( V_2 ) ;
return V_29 ;
}
int F_40 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 , int V_4 ,
T_2 V_26 , T_2 V_17 , T_2 V_39 )
{
struct V_1 * V_2 ;
struct V_30 V_31 ;
struct V_5 * V_9 ;
unsigned long V_10 ;
int V_29 ;
int V_27 = V_4 + sizeof( * V_9 ) ;
V_31 . V_32 = V_26 ;
V_31 . V_34 = V_17 ;
F_21 ( & V_31 , V_33 ) ;
V_2 = F_22 () ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_43 = 1 ;
V_29 = F_30 ( V_23 , V_25 , V_2 , & V_31 ,
V_27 ) ;
if ( V_29 == - V_51 ) {
T_1 V_52 ;
if ( F_1 ( V_2 , V_3 , V_4 , & V_9 ) )
goto V_44;
V_52 = F_2 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ) ;
F_31 ( V_25 , V_2 , V_27 ) ;
V_9 = F_33 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ,
struct V_5 ) ;
V_9 = (struct V_5 * ) ( ( unsigned long ) V_9 + V_52 ) ;
F_41 ( V_2 -> V_15 [ 0 ] , V_9 , V_4 ) ;
F_42 ( V_2 -> V_15 [ 0 ] , V_9 , V_39 ) ;
V_10 = ( unsigned long ) ( V_9 + 1 ) ;
V_29 = 0 ;
} else if ( V_29 < 0 ) {
if ( V_29 == - V_53 )
V_29 = - V_54 ;
goto V_44;
} else {
V_9 = F_33 ( V_2 -> V_15 [ 0 ] , V_2 -> V_16 [ 0 ] ,
struct V_5 ) ;
F_41 ( V_2 -> V_15 [ 0 ] , V_9 , V_4 ) ;
F_42 ( V_2 -> V_15 [ 0 ] , V_9 , V_39 ) ;
V_10 = ( unsigned long ) ( V_9 + 1 ) ;
}
F_38 ( V_2 -> V_15 [ 0 ] , V_3 , V_10 , V_4 ) ;
F_39 ( V_2 -> V_15 [ 0 ] ) ;
V_44:
F_27 ( V_2 ) ;
if ( V_29 == - V_54 ) {
struct V_55 * V_56 = V_25 -> V_45 -> V_57 ;
if ( F_43 ( V_56 )
& V_58 )
V_29 = F_29 ( V_23 , V_25 , V_3 ,
V_4 ,
V_26 ,
V_17 , V_39 ) ;
}
return V_29 ;
}
int F_44 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_1 * V_2 , T_2 V_32 )
{
struct V_30 V_31 ;
int V_29 ;
V_31 . V_32 = V_32 ;
F_21 ( & V_31 , V_59 ) ;
V_31 . V_34 = 0 ;
V_29 = F_30 ( V_23 , V_25 , V_2 , & V_31 ,
sizeof( struct V_60 ) ) ;
return V_29 ;
}
int F_45 ( struct V_22 * V_23 , struct V_24
* V_25 , struct V_1 * V_2 ,
struct V_30 * V_61 , int V_36 )
{
int V_27 = V_36 < 0 ? - 1 : 0 ;
int V_28 = V_36 != 0 ;
int V_29 ;
int V_62 ;
struct V_7 * V_8 ;
struct V_30 V_63 ;
V_29 = F_10 ( V_23 , V_25 , V_61 , V_2 , V_27 , V_28 ) ;
if ( V_29 > 0 && F_46 ( V_61 ) == V_64 &&
V_61 -> V_34 == ( T_2 ) - 1 && V_2 -> V_16 [ 0 ] != 0 ) {
V_62 = V_2 -> V_16 [ 0 ] - 1 ;
V_8 = V_2 -> V_15 [ 0 ] ;
F_47 ( V_8 , & V_63 , V_62 ) ;
if ( V_63 . V_32 == V_61 -> V_32 &&
F_46 ( & V_63 ) == F_46 ( V_61 ) ) {
V_2 -> V_16 [ 0 ] -- ;
return 0 ;
}
}
return V_29 ;
}
