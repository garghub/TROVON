static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_5 = 0 ;
T_1 V_6 = 0 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = F_2 ( & V_2 -> V_8 [ V_6 ] ) ;
if ( ( V_4 [ V_6 ] . V_9 ) && V_5 ) {
V_2 -> V_10 = V_4 [ V_6 ] . V_11 ;
break;
}
}
return V_6 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_12 = false ;
T_1 V_6 = 0 ;
T_2 V_5 = 0 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_5 = F_2 ( & V_2 -> V_8 [ V_6 ] ) ;
if ( V_5 ) {
if ( V_4 [ V_6 ] . V_9 ) {
V_4 [ V_6 ] . V_11 =
( ( V_4 [ V_6 ] . V_11 > V_2 -> V_10 ) ?
V_4 [ V_6 ] . V_11 - V_2 -> V_10 : 0 ) ;
} else {
V_4 [ V_6 ] . V_9 = 1 ;
V_4 [ V_6 ] . V_11 = V_4 [ V_6 ] . V_13 ;
V_12 = true ;
}
} else {
V_4 [ V_6 ] . V_11 = 0 ;
V_4 [ V_6 ] . V_9 = 0 ;
}
}
return V_12 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
bool V_12 = false ;
T_2 V_5 = 0 ;
T_1 V_14 = V_15 ;
T_1 V_6 = 0 , V_16 = 0 ;
if ( F_2 ( & V_2 -> V_8 [ V_17 ] ) ) {
if ( ! V_2 -> V_18 )
V_14 = V_17 ;
return V_14 ;
}
if ( V_2 -> V_19 != 0 ) {
-- V_2 -> V_19 ;
return V_2 -> V_20 ;
}
V_21:
V_12 = false ;
V_14 = F_1 ( V_2 ) ;
V_5 = F_2 ( & V_2 -> V_8 [ V_6 ] ) ;
V_6 = V_14 ;
for (; V_6 < V_7 ; V_6 ++ ) {
if ( ( ( V_2 -> V_4 [ V_6 ] . V_9 ) &&
( V_2 -> V_4 [ V_6 ] . V_11 < V_16 ) ) && V_5 ) {
V_16 = V_2 -> V_4 [ V_6 ] . V_11 ;
V_14 = V_6 ;
}
}
if ( V_14 < V_7 )
V_2 -> V_4 [ V_14 ] . V_9 = 0 ;
V_12 = F_3 ( V_2 ) ;
V_5 = F_2 ( & V_2 -> V_8 [ V_14 ] ) ;
if ( ! V_5 ) {
if ( V_12 )
goto V_21;
V_14 = V_15 ;
return V_14 ;
}
V_2 -> V_20 = V_14 ;
V_5 = F_2 ( & V_2 -> V_8 [ V_14 ] ) ;
switch ( V_2 -> V_20 ) {
case V_22 :
if ( V_5 > V_23 )
V_2 -> V_19 = ( V_23 - 1 ) ;
else
V_2 -> V_19 = -- V_5 ;
break;
case V_24 :
if ( V_5 > V_25 )
V_2 -> V_19 = ( V_25 - 1 ) ;
else
V_2 -> V_19 = -- V_5 ;
break;
default:
V_2 -> V_19 = 0 ;
break;
}
return V_14 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_1 V_14 = V_27 -> V_28 ;
if ( V_14 >= V_29 ) {
F_6 ( V_30 , L_1 ,
V_31 , V_14 ) ;
F_7 ( V_27 ) ;
return;
}
F_8 ( & V_2 -> V_8 [ V_14 ] , V_27 ) ;
}
static struct V_26 * F_9 ( struct V_1 * V_2 ,
T_1 V_14 )
{
if ( V_14 >= V_29 ) {
F_6 ( V_30 , L_1 ,
V_31 , V_14 ) ;
return NULL ;
}
return F_10 ( & V_2 -> V_8 [ V_14 ] ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_34 ;
struct V_26 * V_27 ;
unsigned long V_35 , V_36 ;
T_1 V_14 ;
int V_37 ;
V_35 = V_38 ;
while ( 1 ) {
V_14 = F_4 ( V_2 ) ;
F_6 ( V_39 ,
L_2 , V_31 , V_14 ) ;
if ( V_14 == V_15 ) {
F_6 ( V_39 , L_3 , V_31 ) ;
break;
}
F_12 ( & V_2 -> V_40 ) ;
V_37 = V_33 -> V_41 ( V_33 , V_14 ) ;
if ( ( V_37 <= 0 ) ) {
F_13 ( & V_2 -> V_40 ) ;
break;
}
if ( ( V_14 < V_17 ) &&
( ( F_2 ( & V_2 -> V_8 [ V_14 ] ) ) <=
V_42 ) ) {
if ( F_14 ( V_33 -> V_43 , F_15 ( V_14 ) ) )
F_16 ( V_33 -> V_43 ,
F_15 ( V_14 ) ) ;
}
V_27 = F_9 ( V_2 , V_14 ) ;
if ( V_27 == NULL ) {
F_13 ( & V_2 -> V_40 ) ;
break;
}
if ( V_14 == V_17 )
V_37 = F_17 ( V_2 , V_27 ) ;
else
V_37 = F_18 ( V_2 , V_27 ) ;
if ( V_37 ) {
F_13 ( & V_2 -> V_40 ) ;
break;
}
V_2 -> V_44 . V_45 [ V_14 ] ++ ;
V_36 = V_38 ;
F_13 ( & V_2 -> V_40 ) ;
if ( V_36 > V_35 + ( 300 * V_46 / 1000 ) )
F_19 () ;
}
}
void F_20 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_32 * V_33 = V_2 -> V_34 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 = NULL ;
T_1 V_14 , V_53 = 0 ;
if ( ( ! V_27 ) || ( ! V_27 -> V_54 ) ) {
F_6 ( V_30 , L_4 ,
V_31 ) ;
goto V_55;
}
V_48 = F_21 ( V_27 ) ;
V_50 = (struct V_49 * ) V_48 -> V_56 ;
V_52 = (struct V_51 * ) & V_27 -> V_57 [ 0 ] ;
if ( V_2 -> V_58 != V_59 ) {
F_6 ( V_30 , L_5 , V_31 ) ;
goto V_55;
}
if ( ( F_22 ( V_52 -> V_60 ) ) ||
( F_23 ( V_52 -> V_60 ) ) ) {
V_14 = V_17 ;
V_27 -> V_28 = V_14 ;
} else {
if ( F_24 ( V_52 -> V_60 ) ) {
V_53 = ( V_27 -> V_57 [ 24 ] & V_61 ) ;
V_27 -> V_28 = F_25 ( V_53 ) ;
} else {
V_53 = V_62 ;
V_27 -> V_28 = V_63 ;
}
V_14 = V_27 -> V_28 ;
V_50 -> V_53 = V_53 ;
V_50 -> V_64 = 0 ;
}
if ( ( V_14 != V_17 ) &&
( ( F_2 ( & V_2 -> V_8 [ V_14 ] ) + 1 ) >=
V_65 ) ) {
if ( ! F_14 ( V_33 -> V_43 , F_15 ( V_14 ) ) )
F_26 ( V_33 -> V_43 , F_15 ( V_14 ) ) ;
F_27 ( & V_2 -> V_66 . V_67 ) ;
goto V_55;
}
F_5 ( V_2 , V_27 ) ;
F_6 ( V_39 , L_6 , V_31 ) ;
F_27 ( & V_2 -> V_66 . V_67 ) ;
return;
V_55:
F_6 ( V_30 , L_7 , V_31 ) ;
F_28 ( V_2 -> V_34 -> V_43 , V_27 ) ;
}
