static void F_1 ( T_1 * V_1 , T_1 type , struct V_2 * V_3 )
{
V_3 -> type = type ;
V_3 -> V_4 = F_2 ( V_1 ) ;
V_3 -> V_5 = F_2 ( V_1 + sizeof( V_6 ) ) ;
}
static int F_3 ( struct V_7 * V_8 , T_1 * V_1 ,
T_1 type , V_6 V_9 )
{
int V_10 ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 ;
int V_15 ;
T_2 V_16 ;
unsigned long V_5 ;
struct V_2 V_3 ;
if ( F_4 ( ! V_8 ) ) {
V_10 = - V_17 ;
goto V_18;
}
V_12 = F_5 () ;
if ( ! V_12 ) {
V_10 = - V_19 ;
goto V_18;
}
F_1 ( V_1 , type , & V_3 ) ;
V_10 = F_6 ( NULL , V_8 , & V_3 , V_12 , 0 , 0 ) ;
if ( V_10 < 0 ) {
goto V_18;
} else if ( V_10 > 0 ) {
V_10 = - V_17 ;
goto V_18;
}
V_14 = V_12 -> V_20 [ 0 ] ;
V_15 = V_12 -> V_21 [ 0 ] ;
V_16 = F_7 ( V_14 , V_15 ) ;
V_5 = F_8 ( V_14 , V_15 ) ;
V_10 = - V_17 ;
if ( ! F_9 ( V_16 , sizeof( V_6 ) ) ) {
F_10 ( V_8 -> V_22 , L_1 ,
( unsigned long ) V_16 ) ;
goto V_18;
}
while ( V_16 ) {
T_3 V_23 ;
F_11 ( V_14 , & V_23 , V_5 , sizeof( V_23 ) ) ;
if ( F_12 ( V_23 ) == V_9 ) {
V_10 = 0 ;
break;
}
V_5 += sizeof( V_23 ) ;
V_16 -= sizeof( V_23 ) ;
}
V_18:
F_13 ( V_12 ) ;
return V_10 ;
}
int F_14 ( struct V_24 * V_25 ,
struct V_7 * V_8 , T_1 * V_1 , T_1 type ,
V_6 V_26 )
{
int V_10 ;
struct V_11 * V_12 = NULL ;
struct V_2 V_3 ;
struct V_13 * V_14 ;
int V_15 ;
unsigned long V_5 ;
T_3 V_27 ;
V_10 = F_3 ( V_8 , V_1 , type , V_26 ) ;
if ( V_10 != - V_17 )
return V_10 ;
if ( F_4 ( ! V_8 ) ) {
V_10 = - V_28 ;
goto V_18;
}
F_1 ( V_1 , type , & V_3 ) ;
V_12 = F_5 () ;
if ( ! V_12 ) {
V_10 = - V_19 ;
goto V_18;
}
V_10 = F_15 ( V_25 , V_8 , V_12 , & V_3 ,
sizeof( V_27 ) ) ;
if ( V_10 >= 0 ) {
V_14 = V_12 -> V_20 [ 0 ] ;
V_15 = V_12 -> V_21 [ 0 ] ;
V_5 = F_8 ( V_14 , V_15 ) ;
} else if ( V_10 == - V_29 ) {
F_16 ( V_8 , V_12 , sizeof( V_27 ) ) ;
V_14 = V_12 -> V_20 [ 0 ] ;
V_15 = V_12 -> V_21 [ 0 ] ;
V_5 = F_8 ( V_14 , V_15 ) ;
V_5 += F_7 ( V_14 , V_15 ) - sizeof( V_27 ) ;
} else if ( V_10 < 0 ) {
F_10 ( V_8 -> V_22 , L_2
L_3 ,
V_10 , ( unsigned long long ) V_3 . V_4 ,
( unsigned long long ) V_3 . V_5 , type ) ;
goto V_18;
}
V_10 = 0 ;
V_27 = F_17 ( V_26 ) ;
F_18 ( V_14 , & V_27 , V_5 , sizeof( V_27 ) ) ;
F_19 ( V_14 ) ;
V_18:
F_13 ( V_12 ) ;
return V_10 ;
}
int F_20 ( struct V_24 * V_25 ,
struct V_7 * V_8 , T_1 * V_1 , T_1 type ,
V_6 V_9 )
{
int V_10 ;
struct V_11 * V_12 = NULL ;
struct V_2 V_3 ;
struct V_13 * V_14 ;
int V_15 ;
unsigned long V_5 ;
T_2 V_16 ;
unsigned long V_30 ;
unsigned long V_31 ;
unsigned long V_32 ;
if ( F_4 ( ! V_8 ) ) {
V_10 = - V_28 ;
goto V_18;
}
F_1 ( V_1 , type , & V_3 ) ;
V_12 = F_5 () ;
if ( ! V_12 ) {
V_10 = - V_19 ;
goto V_18;
}
V_10 = F_6 ( V_25 , V_8 , & V_3 , V_12 , - 1 , 1 ) ;
if ( V_10 < 0 ) {
F_10 ( V_8 -> V_22 , L_4 ,
V_10 ) ;
goto V_18;
}
if ( V_10 > 0 ) {
V_10 = - V_17 ;
goto V_18;
}
V_14 = V_12 -> V_20 [ 0 ] ;
V_15 = V_12 -> V_21 [ 0 ] ;
V_5 = F_8 ( V_14 , V_15 ) ;
V_16 = F_7 ( V_14 , V_15 ) ;
if ( ! F_9 ( V_16 , sizeof( V_6 ) ) ) {
F_10 ( V_8 -> V_22 , L_1 ,
( unsigned long ) V_16 ) ;
V_10 = - V_17 ;
goto V_18;
}
while ( V_16 ) {
T_3 V_33 ;
F_11 ( V_14 , & V_33 , V_5 , sizeof( V_33 ) ) ;
if ( F_12 ( V_33 ) == V_9 )
break;
V_5 += sizeof( V_33 ) ;
V_16 -= sizeof( V_33 ) ;
}
if ( ! V_16 ) {
V_10 = - V_17 ;
goto V_18;
}
V_16 = F_7 ( V_14 , V_15 ) ;
if ( V_16 == sizeof( V_9 ) ) {
V_10 = F_21 ( V_25 , V_8 , V_12 ) ;
goto V_18;
}
V_30 = V_5 ;
V_31 = V_5 + sizeof( V_9 ) ;
V_32 = V_16 - ( V_31 - F_8 ( V_14 , V_15 ) ) ;
F_22 ( V_14 , V_30 , V_31 , V_32 ) ;
F_23 ( V_8 , V_12 , V_16 - sizeof( V_9 ) , 1 ) ;
V_18:
F_13 ( V_12 ) ;
return V_10 ;
}
static int F_24 ( struct V_7 * V_8 , T_1 * V_1 , T_1 type ,
V_6 V_9 )
{
struct V_24 * V_25 ;
int V_10 ;
V_25 = F_25 ( V_8 , 1 ) ;
if ( F_26 ( V_25 ) ) {
V_10 = F_27 ( V_25 ) ;
goto V_18;
}
V_10 = F_20 ( V_25 , V_8 , V_1 , type , V_9 ) ;
F_28 ( V_25 , V_8 ) ;
V_18:
return V_10 ;
}
int F_29 ( struct V_34 * V_22 ,
int (* F_30)( struct V_34 * , T_1 * , T_1 ,
V_6 ) )
{
struct V_7 * V_35 = V_22 -> V_8 ;
struct V_2 V_3 ;
struct V_11 * V_12 ;
int V_10 = 0 ;
struct V_13 * V_36 ;
int V_15 ;
T_2 V_16 ;
unsigned long V_5 ;
V_12 = F_5 () ;
if ( ! V_12 ) {
V_10 = - V_19 ;
goto V_18;
}
V_3 . V_4 = 0 ;
V_3 . type = 0 ;
V_3 . V_5 = 0 ;
V_37:
V_12 -> V_38 = 1 ;
V_10 = F_31 ( V_35 , & V_3 , V_12 , 0 ) ;
if ( V_10 ) {
if ( V_10 > 0 )
V_10 = 0 ;
goto V_18;
}
while ( 1 ) {
F_32 () ;
V_36 = V_12 -> V_20 [ 0 ] ;
V_15 = V_12 -> V_21 [ 0 ] ;
F_33 ( V_36 , & V_3 , V_15 ) ;
if ( V_3 . type != V_39 &&
V_3 . type != V_40 )
goto V_41;
V_5 = F_8 ( V_36 , V_15 ) ;
V_16 = F_7 ( V_36 , V_15 ) ;
if ( ! F_9 ( V_16 , sizeof( V_6 ) ) ) {
F_10 ( V_22 , L_1 ,
( unsigned long ) V_16 ) ;
goto V_41;
}
while ( V_16 ) {
T_1 V_1 [ V_42 ] ;
T_3 V_27 ;
V_6 V_26 ;
F_34 ( V_3 . V_4 , V_1 ) ;
F_34 ( V_3 . V_5 , V_1 + sizeof( V_6 ) ) ;
F_11 ( V_36 , & V_27 , V_5 ,
sizeof( V_27 ) ) ;
V_26 = F_12 ( V_27 ) ;
V_10 = F_30 ( V_22 , V_1 , V_3 . type , V_26 ) ;
if ( V_10 < 0 )
goto V_18;
if ( V_10 > 0 ) {
F_35 ( V_12 ) ;
V_10 = F_24 ( V_35 , V_1 , V_3 . type ,
V_26 ) ;
if ( V_10 == 0 ) {
goto V_37;
}
if ( V_10 < 0 && V_10 != - V_17 )
goto V_18;
}
V_16 -= sizeof( V_27 ) ;
V_5 += sizeof( V_27 ) ;
}
V_41:
V_10 = F_36 ( V_35 , V_12 ) ;
if ( V_10 == 0 )
continue;
else if ( V_10 > 0 )
V_10 = 0 ;
break;
}
V_18:
F_13 ( V_12 ) ;
if ( V_10 )
F_10 ( V_22 , L_5 , V_10 ) ;
return 0 ;
}
