int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_6 V_10 ;
struct V_6 V_11 ;
struct V_12 * V_13 ;
int V_14 ;
int V_15 ;
V_10 . V_3 = V_3 ;
V_10 . type = V_16 ;
V_10 . V_17 = ( T_1 ) - 1 ;
V_9 = F_2 () ;
if ( ! V_9 )
return - V_18 ;
V_14 = F_3 ( NULL , V_2 , & V_10 , V_9 , 0 , 0 ) ;
if ( V_14 < 0 )
goto V_19;
F_4 ( V_14 == 0 ) ;
if ( V_9 -> V_20 [ 0 ] == 0 ) {
V_14 = 1 ;
goto V_19;
}
V_13 = V_9 -> V_21 [ 0 ] ;
V_15 = V_9 -> V_20 [ 0 ] - 1 ;
F_5 ( V_13 , & V_11 , V_15 ) ;
if ( V_11 . V_3 != V_3 ||
V_11 . type != V_16 ) {
V_14 = 1 ;
goto V_19;
}
if ( V_5 )
F_6 ( V_13 , V_5 , F_7 ( V_13 , V_15 ) ,
sizeof( * V_5 ) ) ;
if ( V_7 )
memcpy ( V_7 , & V_11 , sizeof( V_11 ) ) ;
V_14 = 0 ;
V_19:
F_8 ( V_9 ) ;
return V_14 ;
}
int F_9 ( struct V_4 * V_5 ,
struct V_12 * V_22 )
{
F_10 ( V_5 , V_22 -> V_23 ) ;
F_11 ( V_5 , F_12 ( V_22 ) ) ;
F_13 ( V_5 , F_14 ( V_22 ) ) ;
return 0 ;
}
int F_15 ( struct V_24 * V_25 , struct V_1
* V_2 , struct V_6 * V_7 , struct V_4
* V_5 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
int V_14 ;
int V_15 ;
unsigned long V_26 ;
V_9 = F_2 () ;
F_4 ( ! V_9 ) ;
V_14 = F_3 ( V_25 , V_2 , V_7 , V_9 , 0 , 1 ) ;
if ( V_14 < 0 )
goto V_19;
if ( V_14 != 0 ) {
F_16 ( V_2 , V_9 -> V_21 [ 0 ] ) ;
F_17 ( V_27 L_1 ,
( unsigned long long ) V_7 -> V_3 , V_7 -> type ,
( unsigned long long ) V_7 -> V_17 ) ;
F_4 ( 1 ) ;
}
V_13 = V_9 -> V_21 [ 0 ] ;
V_15 = V_9 -> V_20 [ 0 ] ;
V_26 = F_7 ( V_13 , V_15 ) ;
F_18 ( V_13 , V_5 , V_26 , sizeof( * V_5 ) ) ;
F_19 ( V_9 -> V_21 [ 0 ] ) ;
V_19:
F_8 ( V_9 ) ;
return V_14 ;
}
int F_20 ( struct V_24 * V_25 , struct V_1
* V_2 , struct V_6 * V_7 , struct V_4
* V_5 )
{
int V_14 ;
V_14 = F_21 ( V_25 , V_2 , V_7 , V_5 , sizeof( * V_5 ) ) ;
return V_14 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_1 * V_28 ;
struct V_4 * V_29 ;
struct V_6 V_7 ;
struct V_6 V_11 ;
struct V_8 * V_9 ;
int V_14 ;
T_2 V_30 ;
struct V_12 * V_31 ;
int V_15 ;
V_7 . V_3 = V_3 ;
F_23 ( & V_7 , V_16 ) ;
V_7 . V_17 = 0 ;
V_9 = F_2 () ;
if ( ! V_9 )
return - V_18 ;
V_32:
V_14 = F_3 ( NULL , V_2 , & V_7 , V_9 , 0 , 0 ) ;
if ( V_14 < 0 )
goto V_33;
while ( 1 ) {
V_31 = V_9 -> V_21 [ 0 ] ;
V_30 = F_24 ( V_31 ) ;
V_15 = V_9 -> V_20 [ 0 ] ;
if ( V_15 >= V_30 ) {
V_14 = F_25 ( V_2 , V_9 ) ;
if ( V_14 )
break;
V_31 = V_9 -> V_21 [ 0 ] ;
V_30 = F_24 ( V_31 ) ;
V_15 = V_9 -> V_20 [ 0 ] ;
}
F_5 ( V_31 , & V_7 , V_15 ) ;
if ( F_26 ( & V_7 ) != V_16 )
goto V_34;
if ( V_7 . V_3 < V_3 )
goto V_34;
if ( V_7 . V_3 > V_3 )
break;
V_29 = F_27 ( V_31 , V_15 , struct V_4 ) ;
if ( F_28 ( V_31 , V_29 ) != 0 )
goto V_34;
memcpy ( & V_11 , & V_7 , sizeof( V_7 ) ) ;
V_7 . V_17 ++ ;
F_29 ( V_9 ) ;
V_28 =
F_30 ( V_2 -> V_35 -> V_36 ,
& V_11 ) ;
if ( F_31 ( V_28 ) ) {
V_14 = F_32 ( V_28 ) ;
goto V_33;
}
V_14 = F_33 ( V_28 ) ;
if ( V_14 )
goto V_33;
goto V_32;
V_34:
V_15 ++ ;
V_9 -> V_20 [ 0 ] ++ ;
}
V_14 = 0 ;
V_33:
F_8 ( V_9 ) ;
return V_14 ;
}
int F_34 ( struct V_1 * V_36 )
{
struct V_12 * V_31 ;
struct V_8 * V_9 ;
struct V_6 V_7 ;
struct V_6 V_37 ;
struct V_1 * V_2 ;
int V_33 = 0 ;
int V_14 ;
V_9 = F_2 () ;
if ( ! V_9 )
return - V_18 ;
V_7 . V_3 = V_38 ;
V_7 . type = V_39 ;
V_7 . V_17 = 0 ;
V_37 . type = V_16 ;
V_37 . V_17 = ( T_1 ) - 1 ;
while ( 1 ) {
V_14 = F_3 ( NULL , V_36 , & V_7 , V_9 , 0 , 0 ) ;
if ( V_14 < 0 ) {
V_33 = V_14 ;
break;
}
V_31 = V_9 -> V_21 [ 0 ] ;
if ( V_9 -> V_20 [ 0 ] >= F_24 ( V_31 ) ) {
V_14 = F_25 ( V_36 , V_9 ) ;
if ( V_14 < 0 )
V_33 = V_14 ;
if ( V_14 != 0 )
break;
V_31 = V_9 -> V_21 [ 0 ] ;
}
F_5 ( V_31 , & V_7 , V_9 -> V_20 [ 0 ] ) ;
F_29 ( V_9 ) ;
if ( V_7 . V_3 != V_38 ||
V_7 . type != V_39 )
break;
V_37 . V_3 = V_7 . V_17 ;
V_7 . V_17 ++ ;
V_2 = F_35 ( V_36 -> V_35 ,
& V_37 ) ;
if ( ! F_31 ( V_2 ) )
continue;
V_14 = F_32 ( V_2 ) ;
if ( V_14 != - V_40 ) {
V_33 = V_14 ;
break;
}
V_14 = F_22 ( V_36 , V_37 . V_3 ) ;
if ( V_14 ) {
V_33 = V_14 ;
break;
}
}
F_8 ( V_9 ) ;
return V_33 ;
}
int F_36 ( struct V_24 * V_25 , struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_14 ;
struct V_4 * V_29 ;
struct V_12 * V_31 ;
V_9 = F_2 () ;
if ( ! V_9 )
return - V_18 ;
V_14 = F_3 ( V_25 , V_2 , V_7 , V_9 , - 1 , 1 ) ;
if ( V_14 < 0 )
goto V_19;
F_4 ( V_14 != 0 ) ;
V_31 = V_9 -> V_21 [ 0 ] ;
V_29 = F_27 ( V_31 , V_9 -> V_20 [ 0 ] , struct V_4 ) ;
V_14 = F_37 ( V_25 , V_2 , V_9 ) ;
V_19:
F_8 ( V_9 ) ;
return V_14 ;
}
int F_38 ( struct V_24 * V_25 ,
struct V_1 * V_36 ,
T_1 V_41 , T_1 V_42 , T_1 V_43 , T_1 * V_44 ,
const char * V_45 , int V_46 )
{
struct V_8 * V_9 ;
struct V_47 * V_48 ;
struct V_12 * V_31 ;
struct V_6 V_7 ;
unsigned long V_26 ;
int V_33 = 0 ;
int V_14 ;
V_9 = F_2 () ;
if ( ! V_9 )
return - V_18 ;
V_7 . V_3 = V_41 ;
V_7 . type = V_49 ;
V_7 . V_17 = V_42 ;
V_32:
V_14 = F_3 ( V_25 , V_36 , & V_7 , V_9 , - 1 , 1 ) ;
F_4 ( V_14 < 0 ) ;
if ( V_14 == 0 ) {
V_31 = V_9 -> V_21 [ 0 ] ;
V_48 = F_27 ( V_31 , V_9 -> V_20 [ 0 ] ,
struct V_47 ) ;
F_39 ( F_40 ( V_31 , V_48 ) != V_43 ) ;
F_39 ( F_41 ( V_31 , V_48 ) != V_46 ) ;
V_26 = ( unsigned long ) ( V_48 + 1 ) ;
F_39 ( F_42 ( V_31 , V_45 , V_26 , V_46 ) ) ;
* V_44 = F_43 ( V_31 , V_48 ) ;
V_14 = F_37 ( V_25 , V_36 , V_9 ) ;
if ( V_14 ) {
V_33 = V_14 ;
goto V_19;
}
} else
V_33 = - V_40 ;
if ( V_7 . type == V_49 ) {
F_29 ( V_9 ) ;
V_7 . V_3 = V_42 ;
V_7 . type = V_50 ;
V_7 . V_17 = V_41 ;
goto V_32;
}
V_19:
F_8 ( V_9 ) ;
return V_33 ;
}
int F_44 ( struct V_1 * V_36 ,
struct V_8 * V_9 ,
T_1 V_41 , T_1 V_42 )
{
struct V_6 V_7 ;
int V_14 ;
V_7 . V_3 = V_41 ;
V_7 . type = V_50 ;
V_7 . V_17 = V_42 ;
V_14 = F_3 ( NULL , V_36 , & V_7 , V_9 , 0 , 0 ) ;
return V_14 ;
}
int F_45 ( struct V_24 * V_25 ,
struct V_1 * V_36 ,
T_1 V_41 , T_1 V_42 , T_1 V_43 , T_1 V_44 ,
const char * V_45 , int V_46 )
{
struct V_6 V_7 ;
int V_14 ;
struct V_8 * V_9 ;
struct V_47 * V_48 ;
struct V_12 * V_31 ;
unsigned long V_26 ;
V_9 = F_2 () ;
if ( ! V_9 )
return - V_18 ;
V_7 . V_3 = V_41 ;
V_7 . type = V_49 ;
V_7 . V_17 = V_42 ;
V_32:
V_14 = F_46 ( V_25 , V_36 , V_9 , & V_7 ,
sizeof( * V_48 ) + V_46 ) ;
F_4 ( V_14 ) ;
V_31 = V_9 -> V_21 [ 0 ] ;
V_48 = F_27 ( V_31 , V_9 -> V_20 [ 0 ] , struct V_47 ) ;
F_47 ( V_31 , V_48 , V_43 ) ;
F_48 ( V_31 , V_48 , V_44 ) ;
F_49 ( V_31 , V_48 , V_46 ) ;
V_26 = ( unsigned long ) ( V_48 + 1 ) ;
F_18 ( V_31 , V_45 , V_26 , V_46 ) ;
F_19 ( V_31 ) ;
if ( V_7 . type == V_49 ) {
F_29 ( V_9 ) ;
V_7 . V_3 = V_42 ;
V_7 . type = V_50 ;
V_7 . V_17 = V_41 ;
goto V_32;
}
F_8 ( V_9 ) ;
return 0 ;
}
void F_50 ( struct V_4 * V_51 )
{
T_1 V_52 = F_51 ( V_51 -> V_53 . V_54 ) ;
if ( ! ( V_52 & V_55 ) ) {
V_52 |= V_55 ;
V_51 -> V_53 . V_54 = F_52 ( V_52 ) ;
V_51 -> V_54 = 0 ;
V_51 -> V_56 = 0 ;
}
}
