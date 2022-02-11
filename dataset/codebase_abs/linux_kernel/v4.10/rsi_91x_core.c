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
static T_2 F_4 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 ;
T_2 V_20 = 0 ;
T_3 V_21 = V_2 -> V_4 [ V_14 ] . V_21 * 32 ;
T_4 V_22 ;
struct V_23 V_24 ;
V_24 . V_25 = V_26 * 5 * 10 ;
if ( V_14 == V_27 )
V_21 = ( ( V_21 << 5 ) / 80 ) ;
if ( F_2 ( & V_2 -> V_8 [ V_14 ] ) )
V_19 = F_5 ( & V_2 -> V_8 [ V_14 ] ) ;
else
return 0 ;
do {
V_22 = F_6 ( V_16 -> V_28 ,
V_16 -> V_29 [ 0 ] ,
V_2 -> V_30 ,
V_19 -> V_31 , & V_24 ) ;
V_21 -= F_7 ( V_22 ) ;
V_20 += 1 ;
if ( F_2 ( & V_2 -> V_8 [ V_14 ] ) - V_20 )
V_19 = V_19 -> V_32 ;
else
break;
} while ( V_21 > 0 );
return V_20 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
bool V_12 = false ;
T_2 V_5 = 0 ;
T_1 V_14 = V_33 ;
T_1 V_6 = 0 ;
if ( F_2 ( & V_2 -> V_8 [ V_34 ] ) ) {
if ( ! V_2 -> V_35 )
V_14 = V_34 ;
return V_14 ;
}
if ( V_2 -> V_36 )
return V_14 ;
if ( V_2 -> V_20 != 0 ) {
-- V_2 -> V_20 ;
return V_2 -> V_37 ;
}
V_38:
V_12 = false ;
V_14 = F_1 ( V_2 ) ;
V_6 = V_14 ;
for (; V_6 < V_7 ; V_6 ++ ) {
V_5 = F_2 ( & V_2 -> V_8 [ V_6 ] ) ;
if ( ( ( V_2 -> V_4 [ V_6 ] . V_9 ) &&
( V_2 -> V_4 [ V_6 ] . V_11 < V_2 -> V_10 ) ) &&
V_5 ) {
V_2 -> V_10 = V_2 -> V_4 [ V_6 ] . V_11 ;
V_14 = V_6 ;
}
}
if ( V_14 < V_7 )
V_2 -> V_4 [ V_14 ] . V_9 = 0 ;
V_12 = F_3 ( V_2 ) ;
V_5 = F_2 ( & V_2 -> V_8 [ V_14 ] ) ;
if ( ! V_5 ) {
if ( V_12 )
goto V_38;
V_14 = V_33 ;
return V_14 ;
}
V_2 -> V_37 = V_14 ;
V_5 = F_2 ( & V_2 -> V_8 [ V_14 ] ) ;
if ( V_14 == V_39 || V_14 == V_27 ) {
V_2 -> V_20 = F_4 ( V_2 , V_14 ) ;
V_2 -> V_20 -= 1 ;
}
return V_14 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
T_1 V_14 = V_19 -> V_40 ;
if ( V_14 >= V_41 ) {
F_10 ( V_42 , L_1 ,
V_43 , V_14 ) ;
F_11 ( V_19 ) ;
return;
}
F_12 ( & V_2 -> V_8 [ V_14 ] , V_19 ) ;
}
static struct V_18 * F_13 ( struct V_1 * V_2 ,
T_1 V_14 )
{
if ( V_14 >= V_41 ) {
F_10 ( V_42 , L_1 ,
V_43 , V_14 ) ;
return NULL ;
}
return F_14 ( & V_2 -> V_8 [ V_14 ] ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 ;
unsigned long V_44 , V_45 ;
T_1 V_14 ;
int V_46 ;
V_44 = V_47 ;
while ( 1 ) {
V_14 = F_8 ( V_2 ) ;
F_10 ( V_48 ,
L_2 , V_43 , V_14 ) ;
if ( V_14 == V_33 ) {
F_10 ( V_48 , L_3 , V_43 ) ;
break;
}
F_16 ( & V_2 -> V_49 ) ;
V_46 = V_16 -> V_50 ( V_16 , V_14 ) ;
if ( ( V_46 <= 0 ) ) {
F_17 ( & V_2 -> V_49 ) ;
break;
}
if ( ( V_14 < V_34 ) &&
( ( F_2 ( & V_2 -> V_8 [ V_14 ] ) ) <=
V_51 ) ) {
if ( F_18 ( V_16 -> V_28 , F_19 ( V_14 ) ) )
F_20 ( V_16 -> V_28 ,
F_19 ( V_14 ) ) ;
}
V_19 = F_13 ( V_2 , V_14 ) ;
if ( V_19 == NULL ) {
F_10 ( V_42 , L_4 ) ;
F_17 ( & V_2 -> V_49 ) ;
break;
}
if ( V_14 == V_34 )
V_46 = F_21 ( V_2 , V_19 ) ;
else
V_46 = F_22 ( V_2 , V_19 ) ;
if ( V_46 ) {
F_17 ( & V_2 -> V_49 ) ;
break;
}
V_2 -> V_52 . V_53 [ V_14 ] ++ ;
V_45 = V_47 ;
F_17 ( & V_2 -> V_49 ) ;
if ( V_45 > V_44 + ( 300 * V_54 / 1000 ) )
F_23 () ;
}
}
void F_24 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 = NULL ;
T_1 V_14 , V_61 = 0 ;
if ( ( ! V_19 ) || ( ! V_19 -> V_31 ) ) {
F_10 ( V_42 , L_5 ,
V_43 ) ;
goto V_62;
}
V_56 = F_25 ( V_19 ) ;
V_58 = (struct V_57 * ) V_56 -> V_63 ;
V_60 = (struct V_59 * ) & V_19 -> V_64 [ 0 ] ;
if ( V_2 -> V_65 != V_66 ) {
F_10 ( V_42 , L_6 , V_43 ) ;
goto V_62;
}
if ( ( F_26 ( V_60 -> V_67 ) ) ||
( F_27 ( V_60 -> V_67 ) ) ||
( F_28 ( V_60 -> V_67 ) ) ) {
V_14 = V_34 ;
V_19 -> V_40 = V_14 ;
} else {
if ( F_29 ( V_60 -> V_67 ) ) {
V_61 = ( V_19 -> V_64 [ 24 ] & V_68 ) ;
V_19 -> V_40 = F_30 ( V_61 ) ;
} else {
V_61 = V_69 ;
V_19 -> V_40 = V_70 ;
}
V_14 = V_19 -> V_40 ;
V_58 -> V_61 = V_61 ;
V_58 -> V_71 = 0 ;
}
if ( ( V_14 != V_34 ) &&
( ( F_2 ( & V_2 -> V_8 [ V_14 ] ) + 1 ) >=
V_72 ) ) {
F_10 ( V_42 , L_7 , V_43 ) ;
if ( ! F_18 ( V_16 -> V_28 , F_19 ( V_14 ) ) )
F_31 ( V_16 -> V_28 , F_19 ( V_14 ) ) ;
F_32 ( & V_2 -> V_73 . V_74 ) ;
goto V_62;
}
F_9 ( V_2 , V_19 ) ;
F_10 ( V_48 , L_8 , V_43 ) ;
F_32 ( & V_2 -> V_73 . V_74 ) ;
return;
V_62:
F_10 ( V_42 , L_9 , V_43 ) ;
F_33 ( V_2 -> V_17 -> V_28 , V_19 ) ;
}
