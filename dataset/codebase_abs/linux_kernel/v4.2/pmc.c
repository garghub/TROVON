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
F_6 ( & V_2 -> V_6 ) ;
if ( F_1 ( V_2 ) ) {
F_7 ( V_5 , L_1 , V_14 ) ;
goto V_15;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
F_8 ( V_5 , L_2 ,
V_14 , V_7 , V_8 ) ;
V_2 -> V_16 = F_9 ( V_7 ,
sizeof( struct V_17 ) ,
V_18 ) ;
if ( ! V_2 -> V_16 ) {
F_7 ( V_5 , L_3 , V_14 ) ;
goto V_15;
}
F_8 ( V_5 ,
L_4 ,
V_14 , V_2 -> V_16 ) ;
V_2 -> V_3 = F_10 ( V_11 ,
sizeof( struct V_19 ) * V_7 ,
& V_2 -> V_20 ,
V_18 ) ;
F_8 ( V_5 ,
L_5 ,
V_14 ,
V_2 -> V_3 , & V_2 -> V_20 ,
sizeof( struct V_19 ) ,
V_7 ,
sizeof( struct V_19 ) * V_7 ) ;
if ( ! V_2 -> V_3 ) {
F_7 ( V_5 , L_6 , V_14 ) ;
goto V_21;
}
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
struct V_19 * V_22 = & V_2 -> V_3 [ V_9 ] ;
struct V_19 V_23 , * V_24 = & V_23 ;
int V_25 = 0 ;
V_2 -> V_16 [ V_9 ] . V_26 = F_10 ( V_11 ,
V_8 ,
& V_2 -> V_16 [ V_9 ] . V_27 ,
V_18 ) ;
if ( F_11 ( ! V_2 -> V_16 [ V_9 ] . V_26 ) ) {
F_7 ( V_5 ,
L_7 ,
V_14 , V_9 ) ;
goto V_28;
}
for ( V_25 = 0 ; V_25 < V_8 / sizeof( T_1 ) ; V_25 ++ ) {
T_1 * V_29 = ( T_1 * ) V_2 -> V_16 [ V_9 ] . V_26 + V_25 ;
* V_29 = V_30 | V_25 ;
}
V_24 -> V_31 . V_32 . V_33 =
F_12 ( F_13 ( V_2 -> V_16 [ V_9 ] . V_27 ) ) ;
V_24 -> V_31 . V_32 . V_34 =
F_14 ( ( V_35 ) F_15 ( V_2 -> V_16 [ V_9 ] . V_27 ) ) ;
V_24 -> V_31 . V_36 = 0 ;
V_24 -> V_31 . V_37 = F_14 ( V_8 ) ;
V_24 -> V_31 . V_38 = F_16 ( 9 ) | V_39 ;
* V_22 = * V_24 ;
}
F_8 ( V_5 , L_8 , V_14 ) ;
V_13 . V_40 = V_41 ;
V_13 . V_42 = F_14 ( V_2 -> V_7 ) ;
V_13 . V_43 = F_17 ( V_2 -> V_20 ) ;
F_8 ( V_5 , L_9 , V_14 ) ;
V_2 -> V_44 = F_18 ( V_5 ,
V_45 ,
& V_13 ,
sizeof( V_13 ) ) ;
if ( V_2 -> V_44 ) {
F_7 ( V_5 ,
L_10 ,
V_14 , V_2 -> V_44 ) ;
goto V_28;
}
F_19 ( & V_2 -> V_6 ) ;
return;
V_28:
F_7 ( V_5 , L_11 , V_14 ) ;
for ( V_9 = 0 ; V_2 -> V_16 [ V_9 ] . V_26 && V_9 < V_7 ; V_9 ++ ) {
F_20 ( V_11 ,
V_8 ,
V_2 -> V_16 [ V_9 ] . V_26 ,
V_2 -> V_16 [ V_9 ] . V_27 ) ;
V_2 -> V_16 [ V_9 ] . V_26 = NULL ;
}
F_7 ( V_5 , L_12 , V_14 ) ;
F_20 ( V_11 ,
sizeof( struct V_19 ) * V_7 ,
V_2 -> V_3 ,
V_2 -> V_20 ) ;
V_2 -> V_3 = NULL ;
V_21:
F_7 ( V_5 , L_13 ,
V_14 ) ;
F_21 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
V_15:
V_2 -> V_44 = - V_46 ;
F_19 ( & V_2 -> V_6 ) ;
}
void F_22 ( struct V_4 * V_5 , int V_47 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_5 ) ;
struct V_12 V_13 = { 0 } ;
F_6 ( & V_2 -> V_6 ) ;
V_2 -> V_44 = 0 ;
if ( ! F_1 ( V_2 ) ) {
F_8 ( V_5 , L_14 ,
V_14 ) ;
V_2 -> V_44 = - V_48 ;
F_19 ( & V_2 -> V_6 ) ;
return;
}
if ( V_47 ) {
F_8 ( V_5 , L_15 ,
V_14 ) ;
V_13 . V_40 = V_49 ;
V_2 -> V_44 =
F_18 ( V_5 , V_45 , & V_13 ,
sizeof( V_13 ) ) ;
if ( V_2 -> V_44 ) {
F_7 ( V_5 ,
L_16 ,
V_14 , V_2 -> V_44 ) ;
}
}
if ( V_2 -> V_3 ) {
T_2 V_50 = sizeof( struct V_19 ) *
V_2 -> V_7 ;
F_8 ( V_5 , L_17 ,
V_14 , V_2 -> V_3 ) ;
F_20 ( V_11 , V_50 , V_2 -> V_3 , V_2 -> V_20 ) ;
V_2 -> V_3 = NULL ;
} else {
V_2 -> V_44 = - V_51 ;
}
if ( V_2 -> V_16 ) {
int V_9 ;
for ( V_9 = 0 ;
V_2 -> V_16 [ V_9 ] . V_26 && V_9 < V_2 -> V_7 ; V_9 ++ ) {
F_20 ( V_11 ,
V_2 -> V_8 ,
V_2 -> V_16 [ V_9 ] . V_26 ,
V_2 -> V_16 [ V_9 ] . V_27 ) ;
V_2 -> V_16 [ V_9 ] . V_26 = NULL ;
}
F_8 ( V_5 , L_18 ,
V_14 , V_9 , V_2 -> V_7 ) ;
F_8 ( V_5 ,
L_19 ,
V_14 , V_2 -> V_16 ) ;
F_21 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
} else {
V_2 -> V_44 = - V_51 ;
}
F_19 ( & V_2 -> V_6 ) ;
}
int F_23 ( struct V_4 * V_5 )
{
F_8 ( V_5 , L_20 , V_14 ,
V_5 -> V_2 . V_44 ) ;
return V_5 -> V_2 . V_44 ;
}
T_3 F_24 ( struct V_52 * V_53 , char T_4 * V_54 , T_2 V_55 ,
T_5 * V_56 )
{
struct V_4 * V_5 = V_53 -> V_57 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
T_2 V_58 = 0 ;
unsigned long long V_59 ;
T_5 V_60 ;
T_2 V_61 = V_2 -> V_8 * V_2 -> V_7 ;
F_6 ( & V_2 -> V_6 ) ;
if ( ! F_1 ( V_2 ) ) {
F_7 ( V_5 , L_21 , V_14 ) ;
V_2 -> V_44 = - V_48 ;
F_19 ( & V_2 -> V_6 ) ;
return - V_48 ;
}
F_8 ( V_5 ,
L_22 ,
V_14 , ( unsigned ) V_55 , * V_56 ) ;
V_2 -> V_44 = 0 ;
V_59 = * V_56 ;
F_25 ( V_59 , V_2 -> V_8 ) ;
V_60 = * V_56 - ( V_59 * V_2 -> V_8 ) ;
if ( * V_56 >= V_61 ) {
F_8 ( V_5 , L_23 ,
V_14 , * V_56 , ( unsigned ) V_61 ) ;
V_2 -> V_44 = - V_62 ;
goto V_63;
}
F_8 ( V_5 ,
L_24 ,
V_14 , * V_56 , V_59 , V_60 , V_55 ) ;
V_58 = F_26 ( V_54 ,
V_55 ,
& V_60 ,
V_2 -> V_16 [ V_59 ] . V_26 ,
V_2 -> V_8 ) ;
* V_56 += V_58 ;
V_63:
F_19 ( & V_2 -> V_6 ) ;
return V_58 ;
}
T_5 F_27 ( struct V_52 * V_53 , T_5 V_64 , int V_65 )
{
T_5 V_66 ;
struct V_4 * V_5 = V_53 -> V_57 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
T_2 V_61 = V_2 -> V_8 * V_2 -> V_7 ;
switch ( V_65 ) {
case 0 :
V_66 = V_64 ;
break;
case 1 :
V_66 = V_53 -> V_56 + V_64 ;
break;
case 2 :
V_66 = V_61 ;
break;
default:
return - V_67 ;
}
if ( V_66 < 0 )
return - V_67 ;
if ( V_66 > V_61 )
V_66 = V_61 ;
V_53 -> V_56 = V_66 ;
return V_66 ;
}
