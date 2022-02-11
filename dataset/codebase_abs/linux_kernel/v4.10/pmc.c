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
F_7 ( V_5 , L_1 , V_16 ) ;
goto V_17;
}
if ( ( V_7 <= 0 ) || ( V_8 <= 0 ) ) {
F_7 ( V_5 ,
L_2 ,
V_7 , V_8 ) ;
V_14 = - V_18 ;
goto V_17;
}
if ( V_7 > ( 1 << V_19 ) ) {
F_7 ( V_5 ,
L_3 ,
V_7 , 1 << V_19 ) ;
V_14 = - V_18 ;
goto V_17;
}
if ( V_7 > V_20 / V_8 ) {
F_7 ( V_5 ,
L_4 ,
V_7 , V_8 ) ;
V_14 = - V_18 ;
goto V_17;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
F_8 ( V_5 , L_5 ,
V_16 , V_7 , V_8 ) ;
V_2 -> V_21 = F_9 ( V_7 ,
sizeof( struct V_22 ) ,
V_23 ) ;
if ( ! V_2 -> V_21 ) {
F_7 ( V_5 , L_6 , V_16 ) ;
goto V_17;
}
F_8 ( V_5 ,
L_7 ,
V_16 , V_2 -> V_21 ) ;
V_2 -> V_3 = F_10 ( V_11 ,
sizeof( struct V_24 ) * V_7 ,
& V_2 -> V_25 ,
V_23 ) ;
F_8 ( V_5 ,
L_8 ,
V_16 ,
V_2 -> V_3 , & V_2 -> V_25 ,
sizeof( struct V_24 ) ,
V_7 ,
sizeof( struct V_24 ) * V_7 ) ;
if ( ! V_2 -> V_3 ) {
F_7 ( V_5 , L_9 , V_16 ) ;
goto V_26;
}
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
struct V_24 * V_27 = & V_2 -> V_3 [ V_9 ] ;
struct V_24 V_28 = {} , * V_29 = & V_28 ;
int V_30 = 0 ;
V_2 -> V_21 [ V_9 ] . V_31 = F_10 ( V_11 ,
V_8 ,
& V_2 -> V_21 [ V_9 ] . V_32 ,
V_23 ) ;
if ( F_11 ( ! V_2 -> V_21 [ V_9 ] . V_31 ) ) {
F_7 ( V_5 ,
L_10 ,
V_16 , V_9 ) ;
goto V_33;
}
for ( V_30 = 0 ; V_30 < V_8 / sizeof( T_1 ) ; V_30 ++ ) {
T_1 * V_34 = ( T_1 * ) V_2 -> V_21 [ V_9 ] . V_31 + V_30 ;
* V_34 = V_35 | V_30 ;
}
V_29 -> V_36 . V_37 . V_38 =
F_12 ( F_13 ( V_2 -> V_21 [ V_9 ] . V_32 ) ) ;
V_29 -> V_36 . V_37 . V_39 =
F_14 ( ( V_40 ) F_15 ( V_2 -> V_21 [ V_9 ] . V_32 ) ) ;
V_29 -> V_36 . V_41 = 0 ;
V_29 -> V_36 . V_42 = F_14 ( V_8 ) ;
V_29 -> V_36 . V_43 = F_16 ( 9 ) | V_44 ;
* V_27 = * V_29 ;
}
F_8 ( V_5 , L_11 , V_16 ) ;
V_13 . V_45 = V_46 ;
V_13 . V_47 = F_14 ( V_2 -> V_7 ) ;
V_13 . V_48 = F_17 ( V_2 -> V_25 ) ;
F_8 ( V_5 , L_12 , V_16 ) ;
V_2 -> V_49 = F_18 ( V_5 ,
V_50 ,
& V_13 ,
sizeof( V_13 ) ) ;
if ( V_2 -> V_49 ) {
F_7 ( V_5 ,
L_13 ,
V_16 , V_2 -> V_49 ) ;
goto V_33;
}
F_19 ( & V_2 -> V_6 ) ;
return;
V_33:
F_7 ( V_5 , L_14 , V_16 ) ;
for ( V_9 = 0 ; V_2 -> V_21 [ V_9 ] . V_31 && V_9 < V_7 ; V_9 ++ ) {
F_20 ( V_11 ,
V_8 ,
V_2 -> V_21 [ V_9 ] . V_31 ,
V_2 -> V_21 [ V_9 ] . V_32 ) ;
V_2 -> V_21 [ V_9 ] . V_31 = NULL ;
}
F_7 ( V_5 , L_15 , V_16 ) ;
F_20 ( V_11 ,
sizeof( struct V_24 ) * V_7 ,
V_2 -> V_3 ,
V_2 -> V_25 ) ;
V_2 -> V_3 = NULL ;
V_26:
F_7 ( V_5 , L_16 ,
V_16 ) ;
F_21 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
V_17:
V_2 -> V_49 = V_14 ;
F_19 ( & V_2 -> V_6 ) ;
}
void F_22 ( struct V_4 * V_5 , int V_51 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_5 ) ;
struct V_12 V_13 = { 0 } ;
F_6 ( & V_2 -> V_6 ) ;
V_2 -> V_49 = 0 ;
if ( ! F_1 ( V_2 ) ) {
F_8 ( V_5 , L_17 ,
V_16 ) ;
V_2 -> V_49 = - V_52 ;
F_19 ( & V_2 -> V_6 ) ;
return;
}
if ( V_51 ) {
F_8 ( V_5 , L_18 ,
V_16 ) ;
V_13 . V_45 = V_53 ;
V_2 -> V_49 =
F_18 ( V_5 , V_50 , & V_13 ,
sizeof( V_13 ) ) ;
if ( V_2 -> V_49 ) {
F_7 ( V_5 ,
L_19 ,
V_16 , V_2 -> V_49 ) ;
}
}
if ( V_2 -> V_3 ) {
T_2 V_54 = sizeof( struct V_24 ) *
V_2 -> V_7 ;
F_8 ( V_5 , L_20 ,
V_16 , V_2 -> V_3 ) ;
F_20 ( V_11 , V_54 , V_2 -> V_3 , V_2 -> V_25 ) ;
V_2 -> V_3 = NULL ;
} else {
V_2 -> V_49 = - V_55 ;
}
if ( V_2 -> V_21 ) {
int V_9 ;
for ( V_9 = 0 ;
V_2 -> V_21 [ V_9 ] . V_31 && V_9 < V_2 -> V_7 ; V_9 ++ ) {
F_20 ( V_11 ,
V_2 -> V_8 ,
V_2 -> V_21 [ V_9 ] . V_31 ,
V_2 -> V_21 [ V_9 ] . V_32 ) ;
V_2 -> V_21 [ V_9 ] . V_31 = NULL ;
}
F_8 ( V_5 , L_21 ,
V_16 , V_9 , V_2 -> V_7 ) ;
F_8 ( V_5 ,
L_22 ,
V_16 , V_2 -> V_21 ) ;
F_21 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
} else {
V_2 -> V_49 = - V_55 ;
}
F_19 ( & V_2 -> V_6 ) ;
}
int F_23 ( struct V_4 * V_5 )
{
F_8 ( V_5 , L_23 , V_16 ,
V_5 -> V_2 . V_49 ) ;
return V_5 -> V_2 . V_49 ;
}
T_3 F_24 ( struct V_56 * V_57 , char T_4 * V_58 , T_2 V_59 ,
T_5 * V_60 )
{
struct V_4 * V_5 = V_57 -> V_61 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
T_2 V_62 = 0 ;
unsigned long long V_63 ;
T_5 V_64 ;
T_2 V_65 ;
F_6 ( & V_2 -> V_6 ) ;
if ( ! F_1 ( V_2 ) ) {
F_7 ( V_5 , L_24 , V_16 ) ;
V_2 -> V_49 = - V_52 ;
F_19 ( & V_2 -> V_6 ) ;
return - V_52 ;
}
V_65 = V_2 -> V_8 * V_2 -> V_7 ;
F_8 ( V_5 ,
L_25 ,
V_16 , ( unsigned ) V_59 , * V_60 ) ;
V_2 -> V_49 = 0 ;
V_63 = * V_60 ;
F_25 ( V_63 , V_2 -> V_8 ) ;
V_64 = * V_60 - ( V_63 * V_2 -> V_8 ) ;
if ( * V_60 >= V_65 ) {
F_8 ( V_5 , L_26 ,
V_16 , * V_60 , ( unsigned ) V_65 ) ;
V_2 -> V_49 = - V_66 ;
goto V_67;
}
F_8 ( V_5 ,
L_27 ,
V_16 , * V_60 , V_63 , V_64 , V_59 ) ;
V_62 = F_26 ( V_58 ,
V_59 ,
& V_64 ,
V_2 -> V_21 [ V_63 ] . V_31 ,
V_2 -> V_8 ) ;
* V_60 += V_62 ;
V_67:
F_19 ( & V_2 -> V_6 ) ;
return V_62 ;
}
T_5 F_27 ( struct V_56 * V_57 , T_5 V_68 , int V_69 )
{
T_5 V_70 ;
struct V_4 * V_5 = V_57 -> V_61 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
T_2 V_65 ;
F_6 ( & V_2 -> V_6 ) ;
if ( ! F_1 ( V_2 ) ) {
F_7 ( V_5 , L_28 ) ;
V_2 -> V_49 = - V_52 ;
F_19 ( & V_2 -> V_6 ) ;
return - V_52 ;
}
V_65 = V_2 -> V_8 * V_2 -> V_7 ;
switch ( V_69 ) {
case 0 :
V_70 = V_68 ;
break;
case 1 :
V_70 = V_57 -> V_60 + V_68 ;
break;
case 2 :
V_70 = V_65 ;
break;
default:
V_70 = - V_18 ;
goto V_67;
}
if ( V_70 < 0 ) {
V_70 = - V_18 ;
goto V_67;
}
if ( V_70 > V_65 )
V_70 = V_65 ;
V_57 -> V_60 = V_70 ;
V_67:
F_19 ( & V_2 -> V_6 ) ;
return V_70 ;
}
