static struct V_1 * F_1 ( struct V_2
* V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 V_10 ,
const char * V_11 ,
int V_12 )
{
int V_13 ;
char * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_13 = F_2 ( V_3 , V_5 , V_7 , V_9 , V_10 ) ;
if ( V_13 == - V_19 ) {
struct V_1 * V_20 ;
V_20 = F_3 ( V_5 , V_7 , V_11 , V_12 ) ;
if ( V_20 )
return F_4 ( - V_19 ) ;
F_5 ( V_5 , V_7 , V_10 ) ;
} else if ( V_13 < 0 )
return F_4 ( V_13 ) ;
F_6 ( V_13 > 0 ) ;
V_18 = V_7 -> V_21 [ 0 ] ;
V_16 = F_7 ( V_7 -> V_22 [ 0 ] ) ;
V_14 = F_8 ( V_18 , V_7 -> V_22 [ 0 ] , char ) ;
F_9 ( V_10 > F_10 ( V_18 , V_16 ) ) ;
V_14 += F_10 ( V_18 , V_16 ) - V_10 ;
return (struct V_1 * ) V_14 ;
}
int F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_23 ,
const char * V_11 , T_3 V_12 ,
const void * V_24 , T_3 V_25 )
{
int V_13 = 0 ;
struct V_1 * V_26 ;
unsigned long V_27 , V_28 ;
struct V_8 V_29 , V_30 ;
struct V_31 V_32 ;
struct V_17 * V_18 ;
T_1 V_10 ;
F_9 ( V_12 + V_25 > F_12 ( V_5 ) ) ;
V_29 . V_23 = V_23 ;
F_13 ( & V_29 , V_33 ) ;
V_29 . V_34 = F_14 ( V_11 , V_12 ) ;
V_10 = sizeof( * V_26 ) + V_12 + V_25 ;
V_26 = F_1 ( V_3 , V_5 , V_7 , & V_29 , V_10 ,
V_11 , V_12 ) ;
if ( F_15 ( V_26 ) )
return F_16 ( V_26 ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_18 = V_7 -> V_21 [ 0 ] ;
F_17 ( & V_32 , & V_30 ) ;
F_18 ( V_18 , V_26 , & V_32 ) ;
F_19 ( V_18 , V_26 , V_35 ) ;
F_20 ( V_18 , V_26 , V_12 ) ;
F_21 ( V_18 , V_26 , V_3 -> V_36 ) ;
F_22 ( V_18 , V_26 , V_25 ) ;
V_27 = ( unsigned long ) ( V_26 + 1 ) ;
V_28 = ( unsigned long ) ( ( char * ) V_27 + V_12 ) ;
F_23 ( V_18 , V_11 , V_27 , V_12 ) ;
F_23 ( V_18 , V_24 , V_28 , V_25 ) ;
F_24 ( V_7 -> V_21 [ 0 ] ) ;
return V_13 ;
}
int F_25 ( struct V_2 * V_3 , struct V_4
* V_5 , const char * V_11 , int V_12 ,
struct V_37 * V_38 , struct V_8 * V_30 ,
T_4 type , T_2 V_39 )
{
int V_13 = 0 ;
int V_40 = 0 ;
struct V_6 * V_7 ;
struct V_1 * V_26 ;
struct V_17 * V_18 ;
unsigned long V_27 ;
struct V_8 V_29 ;
struct V_31 V_32 ;
T_1 V_10 ;
V_29 . V_23 = F_26 ( V_38 ) ;
F_13 ( & V_29 , V_41 ) ;
V_29 . V_34 = F_14 ( V_11 , V_12 ) ;
V_7 = F_27 () ;
if ( ! V_7 )
return - V_42 ;
V_7 -> V_43 = 1 ;
F_17 ( & V_32 , V_30 ) ;
V_10 = sizeof( * V_26 ) + V_12 ;
V_26 = F_1 ( V_3 , V_5 , V_7 , & V_29 , V_10 ,
V_11 , V_12 ) ;
if ( F_15 ( V_26 ) ) {
V_13 = F_16 ( V_26 ) ;
if ( V_13 == - V_19 )
goto V_44;
goto V_45;
}
V_18 = V_7 -> V_21 [ 0 ] ;
F_18 ( V_18 , V_26 , & V_32 ) ;
F_19 ( V_18 , V_26 , type ) ;
F_22 ( V_18 , V_26 , 0 ) ;
F_20 ( V_18 , V_26 , V_12 ) ;
F_21 ( V_18 , V_26 , V_3 -> V_36 ) ;
V_27 = ( unsigned long ) ( V_26 + 1 ) ;
F_23 ( V_18 , V_11 , V_27 , V_12 ) ;
F_24 ( V_18 ) ;
V_44:
if ( V_5 == V_5 -> V_46 -> V_47 ) {
V_13 = 0 ;
goto V_45;
}
F_28 ( V_7 ) ;
V_40 = F_29 ( V_3 , V_5 , V_11 , V_12 , V_38 ,
& V_32 , type , V_39 ) ;
V_45:
F_30 ( V_7 ) ;
if ( V_13 )
return V_13 ;
if ( V_40 )
return V_40 ;
return 0 ;
}
struct V_1 * F_31 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_38 ,
const char * V_11 , int V_12 ,
int V_48 )
{
int V_13 ;
struct V_8 V_29 ;
int V_49 = V_48 < 0 ? - 1 : 0 ;
int V_50 = V_48 != 0 ;
V_29 . V_23 = V_38 ;
F_13 ( & V_29 , V_41 ) ;
V_29 . V_34 = F_14 ( V_11 , V_12 ) ;
V_13 = F_32 ( V_3 , V_5 , & V_29 , V_7 , V_49 , V_50 ) ;
if ( V_13 < 0 )
return F_4 ( V_13 ) ;
if ( V_13 > 0 )
return NULL ;
return F_3 ( V_5 , V_7 , V_11 , V_12 ) ;
}
int F_33 ( struct V_4 * V_5 , T_2 V_38 ,
const char * V_11 , int V_12 )
{
int V_13 ;
struct V_8 V_29 ;
struct V_1 * V_20 ;
int V_10 ;
struct V_17 * V_18 ;
int V_51 ;
struct V_6 * V_7 ;
V_7 = F_27 () ;
if ( ! V_7 )
return - V_42 ;
V_29 . V_23 = V_38 ;
F_13 ( & V_29 , V_41 ) ;
V_29 . V_34 = F_14 ( V_11 , V_12 ) ;
V_13 = F_32 ( NULL , V_5 , & V_29 , V_7 , 0 , 0 ) ;
if ( V_13 < 0 )
goto V_52;
if ( V_13 > 0 ) {
V_13 = 0 ;
goto V_52;
}
V_20 = F_3 ( V_5 , V_7 , V_11 , V_12 ) ;
if ( V_20 ) {
V_13 = - V_19 ;
goto V_52;
}
V_10 = sizeof( * V_20 ) + V_12 + sizeof( struct V_15 ) ;
V_18 = V_7 -> V_21 [ 0 ] ;
V_51 = V_7 -> V_22 [ 0 ] ;
if ( V_10 + F_34 ( V_18 , V_51 ) +
sizeof( struct V_15 ) > F_35 ( V_5 ) ) {
V_13 = - V_53 ;
} else {
V_13 = 0 ;
}
V_52:
F_30 ( V_7 ) ;
return V_13 ;
}
struct V_1 *
F_36 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_38 ,
T_2 V_23 , const char * V_11 , int V_12 ,
int V_48 )
{
int V_13 ;
struct V_8 V_29 ;
int V_49 = V_48 < 0 ? - 1 : 0 ;
int V_50 = V_48 != 0 ;
V_29 . V_23 = V_38 ;
F_13 ( & V_29 , V_54 ) ;
V_29 . V_34 = V_23 ;
V_13 = F_32 ( V_3 , V_5 , & V_29 , V_7 , V_49 , V_50 ) ;
if ( V_13 < 0 )
return F_4 ( V_13 ) ;
if ( V_13 > 0 )
return F_4 ( - V_55 ) ;
return F_3 ( V_5 , V_7 , V_11 , V_12 ) ;
}
struct V_1 *
F_37 ( struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_56 ,
const char * V_11 , int V_12 )
{
struct V_17 * V_18 ;
struct V_1 * V_20 ;
struct V_8 V_29 ;
T_1 V_57 ;
int V_13 ;
V_29 . V_23 = V_56 ;
V_29 . type = V_54 ;
V_29 . V_34 = 0 ;
V_13 = F_32 ( NULL , V_5 , & V_29 , V_7 , 0 , 0 ) ;
if ( V_13 < 0 )
return F_4 ( V_13 ) ;
V_18 = V_7 -> V_21 [ 0 ] ;
V_57 = F_38 ( V_18 ) ;
while ( 1 ) {
if ( V_7 -> V_22 [ 0 ] >= V_57 ) {
V_13 = F_39 ( V_5 , V_7 ) ;
if ( V_13 < 0 )
return F_4 ( V_13 ) ;
if ( V_13 > 0 )
break;
V_18 = V_7 -> V_21 [ 0 ] ;
V_57 = F_38 ( V_18 ) ;
continue;
}
F_40 ( V_18 , & V_29 , V_7 -> V_22 [ 0 ] ) ;
if ( V_29 . V_23 != V_56 || V_29 . type != V_54 )
break;
V_20 = F_3 ( V_5 , V_7 , V_11 , V_12 ) ;
if ( V_20 )
return V_20 ;
V_7 -> V_22 [ 0 ] ++ ;
}
return NULL ;
}
struct V_1 * F_41 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_38 ,
const char * V_11 , T_3 V_12 ,
int V_48 )
{
int V_13 ;
struct V_8 V_29 ;
int V_49 = V_48 < 0 ? - 1 : 0 ;
int V_50 = V_48 != 0 ;
V_29 . V_23 = V_38 ;
F_13 ( & V_29 , V_33 ) ;
V_29 . V_34 = F_14 ( V_11 , V_12 ) ;
V_13 = F_32 ( V_3 , V_5 , & V_29 , V_7 , V_49 , V_50 ) ;
if ( V_13 < 0 )
return F_4 ( V_13 ) ;
if ( V_13 > 0 )
return NULL ;
return F_3 ( V_5 , V_7 , V_11 , V_12 ) ;
}
static struct V_1 * F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
const char * V_11 , int V_12 )
{
struct V_1 * V_26 ;
unsigned long V_27 ;
T_1 V_58 ;
T_1 V_59 = 0 ;
T_1 V_60 ;
struct V_17 * V_18 ;
V_18 = V_7 -> V_21 [ 0 ] ;
V_26 = F_8 ( V_18 , V_7 -> V_22 [ 0 ] , struct V_1 ) ;
if ( F_42 ( V_5 , V_18 , V_26 ) )
return NULL ;
V_58 = F_34 ( V_18 , V_7 -> V_22 [ 0 ] ) ;
while ( V_59 < V_58 ) {
V_60 = sizeof( * V_26 ) +
F_43 ( V_18 , V_26 ) +
F_44 ( V_18 , V_26 ) ;
V_27 = ( unsigned long ) ( V_26 + 1 ) ;
if ( F_43 ( V_18 , V_26 ) == V_12 &&
F_45 ( V_18 , V_11 , V_27 , V_12 ) == 0 )
return V_26 ;
V_59 += V_60 ;
V_26 = (struct V_1 * ) ( ( char * ) V_26 +
V_60 ) ;
}
return NULL ;
}
int F_46 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_1 * V_20 )
{
struct V_17 * V_18 ;
T_1 V_61 ;
T_1 V_62 ;
int V_13 = 0 ;
V_18 = V_7 -> V_21 [ 0 ] ;
V_61 = sizeof( * V_20 ) + F_43 ( V_18 , V_20 ) +
F_44 ( V_18 , V_20 ) ;
V_62 = F_34 ( V_18 , V_7 -> V_22 [ 0 ] ) ;
if ( V_61 == V_62 ) {
V_13 = F_47 ( V_3 , V_5 , V_7 ) ;
} else {
unsigned long V_14 = ( unsigned long ) V_20 ;
unsigned long V_63 ;
V_63 = F_48 ( V_18 , V_7 -> V_22 [ 0 ] ) ;
F_49 ( V_18 , V_14 , V_14 + V_61 ,
V_62 - ( V_14 + V_61 - V_63 ) ) ;
F_50 ( V_5 , V_7 , V_62 - V_61 , 1 ) ;
}
return V_13 ;
}
int F_42 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
struct V_1 * V_26 )
{
T_3 V_64 = V_65 ;
T_4 type = F_51 ( V_18 , V_26 ) ;
if ( type >= V_66 ) {
F_52 ( V_67 L_1 ,
( int ) type ) ;
return 1 ;
}
if ( type == V_35 )
V_64 = V_68 ;
if ( F_43 ( V_18 , V_26 ) > V_64 ) {
F_52 ( V_67 L_2 ,
( unsigned ) F_44 ( V_18 , V_26 ) ) ;
return 1 ;
}
if ( ( F_44 ( V_18 , V_26 ) +
F_43 ( V_18 , V_26 ) ) > F_12 ( V_5 ) ) {
F_52 ( V_67 L_3 ,
( unsigned ) F_43 ( V_18 , V_26 ) ,
( unsigned ) F_44 ( V_18 , V_26 ) ) ;
return 1 ;
}
return 0 ;
}
