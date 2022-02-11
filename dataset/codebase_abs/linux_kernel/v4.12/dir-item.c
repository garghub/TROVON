static struct V_1 * F_1 ( struct V_2
* V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 V_10 ,
const char * V_11 ,
int V_12 )
{
struct V_13 * V_14 = V_5 -> V_14 ;
int V_15 ;
char * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
V_15 = F_2 ( V_3 , V_5 , V_7 , V_9 , V_10 ) ;
if ( V_15 == - V_21 ) {
struct V_1 * V_22 ;
V_22 = F_3 ( V_14 , V_7 , V_11 , V_12 ) ;
if ( V_22 )
return F_4 ( - V_21 ) ;
F_5 ( V_14 , V_7 , V_10 ) ;
} else if ( V_15 < 0 )
return F_4 ( V_15 ) ;
F_6 ( V_15 > 0 ) ;
V_20 = V_7 -> V_23 [ 0 ] ;
V_18 = F_7 ( V_7 -> V_24 [ 0 ] ) ;
V_16 = F_8 ( V_20 , V_7 -> V_24 [ 0 ] , char ) ;
F_9 ( V_10 > F_10 ( V_20 , V_18 ) ) ;
V_16 += F_10 ( V_20 , V_18 ) - V_10 ;
return (struct V_1 * ) V_16 ;
}
int F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_25 ,
const char * V_11 , T_3 V_12 ,
const void * V_26 , T_3 V_27 )
{
int V_15 = 0 ;
struct V_1 * V_28 ;
unsigned long V_29 , V_30 ;
struct V_8 V_31 , V_32 ;
struct V_33 V_34 ;
struct V_19 * V_20 ;
T_1 V_10 ;
if ( V_12 + V_27 > F_12 ( V_5 -> V_14 ) )
return - V_35 ;
V_31 . V_25 = V_25 ;
V_31 . type = V_36 ;
V_31 . V_37 = F_13 ( V_11 , V_12 ) ;
V_10 = sizeof( * V_28 ) + V_12 + V_27 ;
V_28 = F_1 ( V_3 , V_5 , V_7 , & V_31 , V_10 ,
V_11 , V_12 ) ;
if ( F_14 ( V_28 ) )
return F_15 ( V_28 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_20 = V_7 -> V_23 [ 0 ] ;
F_16 ( & V_34 , & V_32 ) ;
F_17 ( V_20 , V_28 , & V_34 ) ;
F_18 ( V_20 , V_28 , V_38 ) ;
F_19 ( V_20 , V_28 , V_12 ) ;
F_20 ( V_20 , V_28 , V_3 -> V_39 ) ;
F_21 ( V_20 , V_28 , V_27 ) ;
V_29 = ( unsigned long ) ( V_28 + 1 ) ;
V_30 = ( unsigned long ) ( ( char * ) V_29 + V_12 ) ;
F_22 ( V_20 , V_11 , V_29 , V_12 ) ;
F_22 ( V_20 , V_26 , V_30 , V_27 ) ;
F_23 ( V_7 -> V_23 [ 0 ] ) ;
return V_15 ;
}
int F_24 ( struct V_2 * V_3 , struct V_4
* V_5 , const char * V_11 , int V_12 ,
struct V_40 * V_41 , struct V_8 * V_32 ,
T_4 type , T_2 V_42 )
{
int V_15 = 0 ;
int V_43 = 0 ;
struct V_6 * V_7 ;
struct V_1 * V_28 ;
struct V_19 * V_20 ;
unsigned long V_29 ;
struct V_8 V_31 ;
struct V_33 V_34 ;
T_1 V_10 ;
V_31 . V_25 = F_25 ( V_41 ) ;
V_31 . type = V_44 ;
V_31 . V_37 = F_13 ( V_11 , V_12 ) ;
V_7 = F_26 () ;
if ( ! V_7 )
return - V_45 ;
V_7 -> V_46 = 1 ;
F_16 ( & V_34 , V_32 ) ;
V_10 = sizeof( * V_28 ) + V_12 ;
V_28 = F_1 ( V_3 , V_5 , V_7 , & V_31 , V_10 ,
V_11 , V_12 ) ;
if ( F_14 ( V_28 ) ) {
V_15 = F_15 ( V_28 ) ;
if ( V_15 == - V_21 )
goto V_47;
goto V_48;
}
V_20 = V_7 -> V_23 [ 0 ] ;
F_17 ( V_20 , V_28 , & V_34 ) ;
F_18 ( V_20 , V_28 , type ) ;
F_21 ( V_20 , V_28 , 0 ) ;
F_19 ( V_20 , V_28 , V_12 ) ;
F_20 ( V_20 , V_28 , V_3 -> V_39 ) ;
V_29 = ( unsigned long ) ( V_28 + 1 ) ;
F_22 ( V_20 , V_11 , V_29 , V_12 ) ;
F_23 ( V_20 ) ;
V_47:
if ( V_5 == V_5 -> V_14 -> V_49 ) {
V_15 = 0 ;
goto V_48;
}
F_27 ( V_7 ) ;
V_43 = F_28 ( V_3 , V_5 -> V_14 , V_11 ,
V_12 , V_41 , & V_34 , type , V_42 ) ;
V_48:
F_29 ( V_7 ) ;
if ( V_15 )
return V_15 ;
if ( V_43 )
return V_43 ;
return 0 ;
}
struct V_1 * F_30 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_41 ,
const char * V_11 , int V_12 ,
int V_50 )
{
int V_15 ;
struct V_8 V_31 ;
int V_51 = V_50 < 0 ? - 1 : 0 ;
int V_52 = V_50 != 0 ;
V_31 . V_25 = V_41 ;
V_31 . type = V_44 ;
V_31 . V_37 = F_13 ( V_11 , V_12 ) ;
V_15 = F_31 ( V_3 , V_5 , & V_31 , V_7 , V_51 , V_52 ) ;
if ( V_15 < 0 )
return F_4 ( V_15 ) ;
if ( V_15 > 0 )
return NULL ;
return F_3 ( V_5 -> V_14 , V_7 , V_11 , V_12 ) ;
}
int F_32 ( struct V_4 * V_5 , T_2 V_41 ,
const char * V_11 , int V_12 )
{
int V_15 ;
struct V_8 V_31 ;
struct V_1 * V_22 ;
int V_10 ;
struct V_19 * V_20 ;
int V_53 ;
struct V_6 * V_7 ;
V_7 = F_26 () ;
if ( ! V_7 )
return - V_45 ;
V_31 . V_25 = V_41 ;
V_31 . type = V_44 ;
V_31 . V_37 = F_13 ( V_11 , V_12 ) ;
V_15 = F_31 ( NULL , V_5 , & V_31 , V_7 , 0 , 0 ) ;
if ( V_15 < 0 )
goto V_54;
if ( V_15 > 0 ) {
V_15 = 0 ;
goto V_54;
}
V_22 = F_3 ( V_5 -> V_14 , V_7 , V_11 , V_12 ) ;
if ( V_22 ) {
V_15 = - V_21 ;
goto V_54;
}
V_10 = sizeof( * V_22 ) + V_12 ;
V_20 = V_7 -> V_23 [ 0 ] ;
V_53 = V_7 -> V_24 [ 0 ] ;
if ( V_10 + F_33 ( V_20 , V_53 ) +
sizeof( struct V_17 ) > F_34 ( V_5 -> V_14 ) ) {
V_15 = - V_55 ;
} else {
V_15 = 0 ;
}
V_54:
F_29 ( V_7 ) ;
return V_15 ;
}
struct V_1 *
F_35 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_41 ,
T_2 V_25 , const char * V_11 , int V_12 ,
int V_50 )
{
int V_15 ;
struct V_8 V_31 ;
int V_51 = V_50 < 0 ? - 1 : 0 ;
int V_52 = V_50 != 0 ;
V_31 . V_25 = V_41 ;
V_31 . type = V_56 ;
V_31 . V_37 = V_25 ;
V_15 = F_31 ( V_3 , V_5 , & V_31 , V_7 , V_51 , V_52 ) ;
if ( V_15 < 0 )
return F_4 ( V_15 ) ;
if ( V_15 > 0 )
return F_4 ( - V_57 ) ;
return F_3 ( V_5 -> V_14 , V_7 , V_11 , V_12 ) ;
}
struct V_1 *
F_36 ( struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_58 ,
const char * V_11 , int V_12 )
{
struct V_19 * V_20 ;
struct V_1 * V_22 ;
struct V_8 V_31 ;
T_1 V_59 ;
int V_15 ;
V_31 . V_25 = V_58 ;
V_31 . type = V_56 ;
V_31 . V_37 = 0 ;
V_15 = F_31 ( NULL , V_5 , & V_31 , V_7 , 0 , 0 ) ;
if ( V_15 < 0 )
return F_4 ( V_15 ) ;
V_20 = V_7 -> V_23 [ 0 ] ;
V_59 = F_37 ( V_20 ) ;
while ( 1 ) {
if ( V_7 -> V_24 [ 0 ] >= V_59 ) {
V_15 = F_38 ( V_5 , V_7 ) ;
if ( V_15 < 0 )
return F_4 ( V_15 ) ;
if ( V_15 > 0 )
break;
V_20 = V_7 -> V_23 [ 0 ] ;
V_59 = F_37 ( V_20 ) ;
continue;
}
F_39 ( V_20 , & V_31 , V_7 -> V_24 [ 0 ] ) ;
if ( V_31 . V_25 != V_58 || V_31 . type != V_56 )
break;
V_22 = F_3 ( V_5 -> V_14 , V_7 ,
V_11 , V_12 ) ;
if ( V_22 )
return V_22 ;
V_7 -> V_24 [ 0 ] ++ ;
}
return NULL ;
}
struct V_1 * F_40 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , T_2 V_41 ,
const char * V_11 , T_3 V_12 ,
int V_50 )
{
int V_15 ;
struct V_8 V_31 ;
int V_51 = V_50 < 0 ? - 1 : 0 ;
int V_52 = V_50 != 0 ;
V_31 . V_25 = V_41 ;
V_31 . type = V_36 ;
V_31 . V_37 = F_13 ( V_11 , V_12 ) ;
V_15 = F_31 ( V_3 , V_5 , & V_31 , V_7 , V_51 , V_52 ) ;
if ( V_15 < 0 )
return F_4 ( V_15 ) ;
if ( V_15 > 0 )
return NULL ;
return F_3 ( V_5 -> V_14 , V_7 , V_11 , V_12 ) ;
}
struct V_1 * F_3 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
const char * V_11 , int V_12 )
{
struct V_1 * V_28 ;
unsigned long V_29 ;
T_1 V_60 ;
T_1 V_61 = 0 ;
T_1 V_62 ;
struct V_19 * V_20 ;
V_20 = V_7 -> V_23 [ 0 ] ;
V_28 = F_8 ( V_20 , V_7 -> V_24 [ 0 ] , struct V_1 ) ;
if ( F_41 ( V_14 , V_20 , V_28 ) )
return NULL ;
V_60 = F_33 ( V_20 , V_7 -> V_24 [ 0 ] ) ;
while ( V_61 < V_60 ) {
V_62 = sizeof( * V_28 ) +
F_42 ( V_20 , V_28 ) +
F_43 ( V_20 , V_28 ) ;
V_29 = ( unsigned long ) ( V_28 + 1 ) ;
if ( F_42 ( V_20 , V_28 ) == V_12 &&
F_44 ( V_20 , V_11 , V_29 , V_12 ) == 0 )
return V_28 ;
V_61 += V_62 ;
V_28 = (struct V_1 * ) ( ( char * ) V_28 +
V_62 ) ;
}
return NULL ;
}
int F_45 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_1 * V_22 )
{
struct V_19 * V_20 ;
T_1 V_63 ;
T_1 V_64 ;
int V_15 = 0 ;
V_20 = V_7 -> V_23 [ 0 ] ;
V_63 = sizeof( * V_22 ) + F_42 ( V_20 , V_22 ) +
F_43 ( V_20 , V_22 ) ;
V_64 = F_33 ( V_20 , V_7 -> V_24 [ 0 ] ) ;
if ( V_63 == V_64 ) {
V_15 = F_46 ( V_3 , V_5 , V_7 ) ;
} else {
unsigned long V_16 = ( unsigned long ) V_22 ;
unsigned long V_65 ;
V_65 = F_47 ( V_20 , V_7 -> V_24 [ 0 ] ) ;
F_48 ( V_20 , V_16 , V_16 + V_63 ,
V_64 - ( V_16 + V_63 - V_65 ) ) ;
F_49 ( V_5 -> V_14 , V_7 ,
V_64 - V_63 , 1 ) ;
}
return V_15 ;
}
int F_41 ( struct V_13 * V_14 ,
struct V_19 * V_20 ,
struct V_1 * V_28 )
{
T_3 V_66 = V_67 ;
T_4 type = F_50 ( V_20 , V_28 ) ;
if ( type >= V_68 ) {
F_51 ( V_14 , L_1 , ( int ) type ) ;
return 1 ;
}
if ( type == V_38 )
V_66 = V_69 ;
if ( F_42 ( V_20 , V_28 ) > V_66 ) {
F_51 ( V_14 , L_2 ,
( unsigned ) F_42 ( V_20 , V_28 ) ) ;
return 1 ;
}
if ( ( F_43 ( V_20 , V_28 ) +
F_42 ( V_20 , V_28 ) ) >
F_12 ( V_14 ) ) {
F_51 ( V_14 , L_3 ,
( unsigned ) F_42 ( V_20 , V_28 ) ,
( unsigned ) F_43 ( V_20 , V_28 ) ) ;
return 1 ;
}
return 0 ;
}
