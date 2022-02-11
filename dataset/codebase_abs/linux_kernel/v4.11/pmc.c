static int F_1 ( struct V_1 * V_2 )
{
return ! ! V_2 -> V_3 ;
}
void F_2 ( struct V_4 * V_5 )
{
memset ( & V_5 -> V_2 , 0 , sizeof( struct V_1 ) ) ;
F_3 ( & V_5 -> V_2 . V_6 ) ;
}
void F_4 ( struct V_4 * V_5 ,
int V_7 ,
int V_8 )
{
T_1 V_9 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_5 ) ;
struct V_12 V_13 = { 0 } ;
int V_14 = - V_15 ;
F_6 ( & V_2 -> V_6 ) ;
if ( F_1 ( V_2 ) ) {
F_7 ( V_5 , L_1 ) ;
goto V_16;
}
if ( ( V_7 <= 0 ) || ( V_8 <= 0 ) ) {
F_7 ( V_5 ,
L_2 ,
V_7 , V_8 ) ;
V_14 = - V_17 ;
goto V_16;
}
if ( V_7 > ( 1 << V_18 ) ) {
F_7 ( V_5 ,
L_3 ,
V_7 , 1 << V_18 ) ;
V_14 = - V_17 ;
goto V_16;
}
if ( V_7 > V_19 / V_8 ) {
F_7 ( V_5 ,
L_4 ,
V_7 , V_8 ) ;
V_14 = - V_17 ;
goto V_16;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
F_8 ( V_5 , L_5 ,
V_7 , V_8 ) ;
V_2 -> V_20 = F_9 ( V_7 ,
sizeof( struct V_21 ) ,
V_22 ) ;
if ( ! V_2 -> V_20 ) {
F_7 ( V_5 , L_6 ) ;
goto V_16;
}
F_8 ( V_5 , L_7 ,
V_2 -> V_20 ) ;
V_2 -> V_3 = F_10 ( V_11 ,
sizeof( struct V_23 ) * V_7 ,
& V_2 -> V_24 ,
V_22 ) ;
F_8 ( V_5 ,
L_8 ,
V_2 -> V_3 , & V_2 -> V_24 ,
sizeof( struct V_23 ) ,
V_7 ,
sizeof( struct V_23 ) * V_7 ) ;
if ( ! V_2 -> V_3 ) {
F_7 ( V_5 , L_9 ) ;
goto V_25;
}
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
struct V_23 * V_26 = & V_2 -> V_3 [ V_9 ] ;
struct V_23 V_27 = {} , * V_28 = & V_27 ;
int V_29 = 0 ;
V_2 -> V_20 [ V_9 ] . V_30 = F_10 ( V_11 ,
V_8 ,
& V_2 -> V_20 [ V_9 ] . V_31 ,
V_22 ) ;
if ( F_11 ( ! V_2 -> V_20 [ V_9 ] . V_30 ) ) {
F_7 ( V_5 , L_10 , V_9 ) ;
goto V_32;
}
for ( V_29 = 0 ; V_29 < V_8 / sizeof( T_1 ) ; V_29 ++ ) {
T_1 * V_33 = ( T_1 * ) V_2 -> V_20 [ V_9 ] . V_30 + V_29 ;
* V_33 = V_34 | V_29 ;
}
V_28 -> V_35 . V_36 . V_37 =
F_12 ( F_13 ( V_2 -> V_20 [ V_9 ] . V_31 ) ) ;
V_28 -> V_35 . V_36 . V_38 =
F_14 ( ( V_39 ) F_15 ( V_2 -> V_20 [ V_9 ] . V_31 ) ) ;
V_28 -> V_35 . V_40 = 0 ;
V_28 -> V_35 . V_41 = F_14 ( V_8 ) ;
V_28 -> V_35 . V_42 = F_16 ( 9 ) | V_43 ;
* V_26 = * V_28 ;
}
F_8 ( V_5 , L_11 ) ;
V_13 . V_44 = V_45 ;
V_13 . V_46 = F_14 ( V_2 -> V_7 ) ;
V_13 . V_47 = F_17 ( V_2 -> V_24 ) ;
F_8 ( V_5 , L_12 ) ;
V_2 -> V_48 = F_18 ( V_5 ,
V_49 ,
& V_13 ,
sizeof( V_13 ) ) ;
if ( V_2 -> V_48 ) {
F_7 ( V_5 ,
L_13 ,
V_2 -> V_48 ) ;
goto V_32;
}
F_19 ( & V_2 -> V_6 ) ;
return;
V_32:
F_7 ( V_5 , L_14 ) ;
for ( V_9 = 0 ; V_2 -> V_20 [ V_9 ] . V_30 && V_9 < V_7 ; V_9 ++ ) {
F_20 ( V_11 ,
V_8 ,
V_2 -> V_20 [ V_9 ] . V_30 ,
V_2 -> V_20 [ V_9 ] . V_31 ) ;
V_2 -> V_20 [ V_9 ] . V_30 = NULL ;
}
F_7 ( V_5 , L_15 ) ;
F_20 ( V_11 ,
sizeof( struct V_23 ) * V_7 ,
V_2 -> V_3 ,
V_2 -> V_24 ) ;
V_2 -> V_3 = NULL ;
V_25:
F_7 ( V_5 , L_16 ) ;
F_21 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_16:
V_2 -> V_48 = V_14 ;
F_19 ( & V_2 -> V_6 ) ;
}
void F_22 ( struct V_4 * V_5 , int V_50 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_5 ) ;
struct V_12 V_13 = { 0 } ;
F_6 ( & V_2 -> V_6 ) ;
V_2 -> V_48 = 0 ;
if ( ! F_1 ( V_2 ) ) {
F_8 ( V_5 ,
L_17 ) ;
V_2 -> V_48 = - V_51 ;
F_19 ( & V_2 -> V_6 ) ;
return;
}
if ( V_50 ) {
F_8 ( V_5 , L_18 ) ;
V_13 . V_44 = V_52 ;
V_2 -> V_48 =
F_18 ( V_5 , V_49 , & V_13 ,
sizeof( V_13 ) ) ;
if ( V_2 -> V_48 ) {
F_7 ( V_5 ,
L_19 ,
V_2 -> V_48 ) ;
}
}
if ( V_2 -> V_3 ) {
T_2 V_53 = sizeof( struct V_23 ) *
V_2 -> V_7 ;
F_8 ( V_5 , L_20 ,
V_2 -> V_3 ) ;
F_20 ( V_11 , V_53 , V_2 -> V_3 , V_2 -> V_24 ) ;
V_2 -> V_3 = NULL ;
} else {
V_2 -> V_48 = - V_54 ;
}
if ( V_2 -> V_20 ) {
int V_9 ;
for ( V_9 = 0 ;
V_2 -> V_20 [ V_9 ] . V_30 && V_9 < V_2 -> V_7 ; V_9 ++ ) {
F_20 ( V_11 ,
V_2 -> V_8 ,
V_2 -> V_20 [ V_9 ] . V_30 ,
V_2 -> V_20 [ V_9 ] . V_31 ) ;
V_2 -> V_20 [ V_9 ] . V_30 = NULL ;
}
F_8 ( V_5 , L_21 , V_9 ,
V_2 -> V_7 ) ;
F_8 ( V_5 ,
L_22 ,
V_2 -> V_20 ) ;
F_21 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
} else {
V_2 -> V_48 = - V_54 ;
}
F_19 ( & V_2 -> V_6 ) ;
}
int F_23 ( struct V_4 * V_5 )
{
F_8 ( V_5 , L_23 ,
V_5 -> V_2 . V_48 ) ;
return V_5 -> V_2 . V_48 ;
}
T_3 F_24 ( struct V_55 * V_56 , char T_4 * V_57 , T_2 V_58 ,
T_5 * V_59 )
{
struct V_4 * V_5 = V_56 -> V_60 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
T_2 V_61 = 0 ;
unsigned long long V_62 ;
T_5 V_63 ;
T_2 V_64 ;
F_6 ( & V_2 -> V_6 ) ;
if ( ! F_1 ( V_2 ) ) {
F_7 ( V_5 , L_24 ) ;
V_2 -> V_48 = - V_51 ;
F_19 ( & V_2 -> V_6 ) ;
return - V_51 ;
}
V_64 = V_2 -> V_8 * V_2 -> V_7 ;
F_8 ( V_5 ,
L_25 ,
( T_1 ) V_58 , * V_59 ) ;
V_2 -> V_48 = 0 ;
V_62 = * V_59 ;
F_25 ( V_62 , V_2 -> V_8 ) ;
V_63 = * V_59 - ( V_62 * V_2 -> V_8 ) ;
if ( * V_59 >= V_64 ) {
F_8 ( V_5 ,
L_26 ,
* V_59 , ( T_1 ) V_64 ) ;
V_2 -> V_48 = - V_65 ;
goto V_66;
}
F_8 ( V_5 ,
L_27 ,
* V_59 , V_62 , V_63 , V_58 ) ;
V_61 = F_26 ( V_57 ,
V_58 ,
& V_63 ,
V_2 -> V_20 [ V_62 ] . V_30 ,
V_2 -> V_8 ) ;
* V_59 += V_61 ;
V_66:
F_19 ( & V_2 -> V_6 ) ;
return V_61 ;
}
T_5 F_27 ( struct V_55 * V_56 , T_5 V_67 , int V_68 )
{
T_5 V_69 ;
struct V_4 * V_5 = V_56 -> V_60 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
T_2 V_64 ;
F_6 ( & V_2 -> V_6 ) ;
if ( ! F_1 ( V_2 ) ) {
F_7 ( V_5 , L_24 ) ;
V_2 -> V_48 = - V_51 ;
F_19 ( & V_2 -> V_6 ) ;
return - V_51 ;
}
V_64 = V_2 -> V_8 * V_2 -> V_7 ;
switch ( V_68 ) {
case 0 :
V_69 = V_67 ;
break;
case 1 :
V_69 = V_56 -> V_59 + V_67 ;
break;
case 2 :
V_69 = V_64 ;
break;
default:
V_69 = - V_17 ;
goto V_66;
}
if ( V_69 < 0 ) {
V_69 = - V_17 ;
goto V_66;
}
if ( V_69 > V_64 )
V_69 = V_64 ;
V_56 -> V_59 = V_69 ;
V_66:
F_19 ( & V_2 -> V_6 ) ;
return V_69 ;
}
