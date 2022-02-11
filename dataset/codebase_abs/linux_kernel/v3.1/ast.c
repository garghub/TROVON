static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ,
V_2 -> V_4 ,
( unsigned long long ) V_2 -> V_5 . V_6 ,
V_2 -> V_5 . V_7 ,
V_2 -> V_5 . V_8 ,
V_2 -> V_5 . V_9 ,
V_2 -> V_5 . V_10 ) ;
F_2 ( L_2 ,
V_2 -> V_4 ,
( unsigned long long ) V_2 -> V_11 . V_6 ,
V_2 -> V_11 . V_7 ,
V_2 -> V_11 . V_8 ,
V_2 -> V_11 . V_9 ,
V_2 -> V_11 . V_10 ) ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
F_2 ( L_3 ,
V_2 -> V_4 ,
( unsigned long long ) V_2 -> V_13 [ V_3 ] . V_6 ,
V_2 -> V_13 [ V_3 ] . V_7 ,
V_2 -> V_13 [ V_3 ] . V_8 ,
V_2 -> V_13 [ V_3 ] . V_9 ,
V_2 -> V_13 [ V_3 ] . V_10 ) ;
}
}
int F_3 ( struct V_1 * V_2 , T_1 V_7 , int V_8 ,
int V_14 , T_1 V_15 , T_2 V_6 )
{
struct V_16 * V_17 = V_2 -> V_18 -> V_19 ;
T_2 V_20 ;
int V_21 ;
int V_3 , V_22 ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
if ( V_2 -> V_13 [ V_3 ] . V_6 )
continue;
if ( ( V_3 > 0 ) && ( V_7 & V_23 ) &&
( V_2 -> V_13 [ V_3 - 1 ] . V_7 & V_23 ) ) {
V_20 = V_2 -> V_13 [ V_3 - 1 ] . V_6 ;
V_21 = V_2 -> V_13 [ V_3 - 1 ] . V_8 ;
if ( ( V_21 == V_8 ) ||
( V_21 > V_8 && V_21 > V_24 ) ) {
F_4 ( V_17 , L_4
L_5 ,
V_2 -> V_4 ,
( unsigned long long ) V_6 ,
V_8 ,
( unsigned long long ) V_20 ,
V_21 ) ;
V_22 = 0 ;
goto V_25;
}
}
V_2 -> V_13 [ V_3 ] . V_6 = V_6 ;
V_2 -> V_13 [ V_3 ] . V_7 = V_7 ;
V_2 -> V_13 [ V_3 ] . V_8 = V_8 ;
V_2 -> V_13 [ V_3 ] . V_9 = V_14 ;
V_2 -> V_13 [ V_3 ] . V_10 = ( V_15 & 0x000000FF ) ;
V_22 = 0 ;
break;
}
if ( V_3 == V_12 ) {
F_5 ( V_17 , L_6 ,
V_2 -> V_4 , ( unsigned long long ) V_6 ,
V_7 , V_8 , V_14 , V_15 ) ;
F_1 ( V_2 ) ;
V_22 = - 1 ;
goto V_25;
}
V_25:
return V_22 ;
}
int F_6 ( struct V_16 * V_17 , struct V_1 * V_2 ,
struct V_26 * V_27 , int * V_28 )
{
int V_3 , V_22 ;
* V_28 = 0 ;
if ( ! V_2 -> V_13 [ 0 ] . V_6 ) {
V_22 = - V_29 ;
goto V_25;
}
memcpy ( V_27 , & V_2 -> V_13 [ 0 ] , sizeof( struct V_26 ) ) ;
memset ( & V_2 -> V_13 [ 0 ] , 0 , sizeof( struct V_26 ) ) ;
for ( V_3 = 1 ; V_3 < V_12 ; V_3 ++ ) {
if ( ! V_2 -> V_13 [ V_3 ] . V_6 )
break;
memcpy ( & V_2 -> V_13 [ V_3 - 1 ] , & V_2 -> V_13 [ V_3 ] ,
sizeof( struct V_26 ) ) ;
memset ( & V_2 -> V_13 [ V_3 ] , 0 , sizeof( struct V_26 ) ) ;
( * V_28 ) ++ ;
}
if ( ( V_27 -> V_7 & V_23 ) && V_2 -> V_11 . V_6 ) {
if ( F_7 ( V_27 -> V_8 , V_2 -> V_11 . V_8 ) ) {
V_27 -> V_7 |= V_30 ;
F_4 ( V_17 , L_7
L_8 ,
V_2 -> V_4 ,
( unsigned long long ) V_27 -> V_6 ,
V_27 -> V_8 ,
( unsigned long long ) V_2 -> V_11 . V_6 ,
V_2 -> V_11 . V_8 ) ;
V_22 = 0 ;
goto V_25;
}
}
if ( V_27 -> V_7 & V_31 ) {
memcpy ( & V_2 -> V_11 , V_27 , sizeof( struct V_26 ) ) ;
V_2 -> V_32 = F_8 () ;
}
if ( V_27 -> V_7 & V_23 ) {
memcpy ( & V_2 -> V_5 , V_27 , sizeof( struct V_26 ) ) ;
V_2 -> V_33 = F_8 () ;
}
V_22 = 0 ;
V_25:
return V_22 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_7 , int V_8 , int V_14 ,
T_1 V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 -> V_19 ;
T_2 V_34 , V_20 ;
int V_22 ;
F_10 ( & V_35 ) ;
V_34 = ++ V_36 ;
F_11 ( & V_35 ) ;
if ( V_2 -> V_37 & V_38 ) {
F_12 ( V_2 , V_7 , V_8 , V_14 , V_15 , V_34 ) ;
return;
}
F_13 ( & V_2 -> V_39 ) ;
V_20 = V_2 -> V_13 [ 0 ] . V_6 ;
V_22 = F_3 ( V_2 , V_7 , V_8 , V_14 , V_15 , V_34 ) ;
if ( V_22 < 0 )
goto V_25;
if ( ! V_20 ) {
F_14 ( & V_2 -> V_40 ) ;
if ( F_15 ( V_41 , & V_17 -> V_42 ) ) {
F_13 ( & V_17 -> V_43 ) ;
F_16 ( & V_2 -> V_44 , & V_17 -> V_45 ) ;
F_17 ( & V_17 -> V_43 ) ;
} else {
F_18 ( V_17 -> V_46 , & V_2 -> V_47 ) ;
}
}
V_25:
F_17 ( & V_2 -> V_39 ) ;
}
void F_19 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_20 ( V_49 , struct V_1 , V_47 ) ;
struct V_16 * V_17 = V_2 -> V_18 -> V_19 ;
void (* F_21) ( void * V_50 );
void (* F_22) ( void * V_50 , int V_8 );
struct V_26 V_51 [ V_12 ] ;
int V_3 , V_22 , V_28 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
F_13 ( & V_2 -> V_39 ) ;
if ( ! V_2 -> V_13 [ 0 ] . V_6 ) {
F_5 ( V_17 , L_9 , V_2 -> V_4 ) ;
F_23 ( V_2 ) ;
F_1 ( V_2 ) ;
}
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
V_22 = F_6 ( V_17 , V_2 , & V_51 [ V_3 ] , & V_28 ) ;
if ( V_22 < 0 )
break;
}
if ( V_28 ) {
F_5 ( V_17 , L_10 , V_2 -> V_4 ,
V_28 ) ;
F_23 ( V_2 ) ;
F_1 ( V_2 ) ;
}
F_17 ( & V_2 -> V_39 ) ;
F_21 = V_2 -> V_52 ;
F_22 = V_2 -> V_53 ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
if ( ! V_51 [ V_3 ] . V_6 )
break;
if ( V_51 [ V_3 ] . V_7 & V_30 ) {
continue;
} else if ( V_51 [ V_3 ] . V_7 & V_23 ) {
F_22 ( V_2 -> V_54 , V_51 [ V_3 ] . V_8 ) ;
} else if ( V_51 [ V_3 ] . V_7 & V_31 ) {
V_2 -> V_55 -> V_9 = V_51 [ V_3 ] . V_9 ;
V_2 -> V_55 -> V_10 = V_51 [ V_3 ] . V_10 ;
F_21 ( V_2 -> V_54 ) ;
}
}
F_24 ( V_2 ) ;
}
int F_25 ( struct V_16 * V_17 )
{
V_17 -> V_46 = F_26 ( L_11 ,
V_56 |
V_57 |
V_58 ,
0 ) ;
if ( ! V_17 -> V_46 ) {
F_2 ( L_12 ) ;
return - V_59 ;
}
return 0 ;
}
void F_27 ( struct V_16 * V_17 )
{
if ( V_17 -> V_46 )
F_28 ( V_17 -> V_46 ) ;
}
void F_29 ( struct V_16 * V_17 )
{
F_30 ( V_41 , & V_17 -> V_42 ) ;
if ( V_17 -> V_46 )
F_31 ( V_17 -> V_46 ) ;
}
void F_32 ( struct V_16 * V_17 )
{
struct V_1 * V_2 , * V_60 ;
int V_61 = 0 ;
F_33 ( V_41 , & V_17 -> V_42 ) ;
if ( ! V_17 -> V_46 )
return;
F_13 ( & V_17 -> V_43 ) ;
F_34 (lkb, safe, &ls->ls_cb_delay, lkb_cb_list) {
F_35 ( & V_2 -> V_44 ) ;
F_18 ( V_17 -> V_46 , & V_2 -> V_47 ) ;
V_61 ++ ;
}
F_17 ( & V_17 -> V_43 ) ;
F_4 ( V_17 , L_13 , V_61 ) ;
}
