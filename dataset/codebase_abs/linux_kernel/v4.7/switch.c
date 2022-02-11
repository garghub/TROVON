static const char * F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> type >> 16 ) {
case 0 :
switch ( ( V_3 ) V_2 -> type ) {
case 0 :
return L_1 ;
case 1 :
return L_2 ;
case 2 :
return L_3 ;
default:
return L_4 ;
}
case 0x2 :
return L_5 ;
case 0x8 :
return L_6 ;
case 0xe :
return L_7 ;
case 0x10 :
return L_8 ;
case 0x20 :
return L_9 ;
default:
return L_4 ;
}
}
static void F_2 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
F_3 ( V_4 ,
L_10 ,
V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_7 ,
V_2 -> V_8 , V_2 -> V_9 , F_1 ( V_2 ) ,
V_2 -> type ) ;
F_3 ( V_4 , L_11 ,
V_2 -> V_10 , V_2 -> V_11 ) ;
F_3 ( V_4 , L_12 , V_2 -> V_12 ) ;
F_3 ( V_4 , L_13 , V_2 -> V_13 ) ;
}
static int F_4 ( struct V_14 * V_2 )
{
struct V_15 V_16 ;
int V_17 ;
if ( V_2 -> V_18 == 0 ) {
F_5 ( V_2 , L_14 ) ;
return - V_19 ;
}
V_17 = F_6 ( V_2 , & V_16 , V_20 , V_2 -> V_18 , 2 ) ;
if ( V_17 )
return V_17 ;
return V_16 . V_21 ;
}
int F_7 ( struct V_14 * V_2 , bool V_22 )
{
int V_23 = 10 ;
int V_21 ;
if ( ! V_2 -> V_18 ) {
F_5 ( V_2 , L_15 ) ;
return - V_19 ;
}
if ( F_8 ( V_2 ) ) {
F_5 ( V_2 , L_16 ) ;
return - V_19 ;
}
while ( V_23 -- ) {
V_21 = F_4 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 == V_24 ) {
F_9 ( V_2 , L_17 ) ;
return 0 ;
}
if ( V_21 == V_25 ) {
if ( V_22 ) {
F_9 ( V_2 ,
L_18 ) ;
F_10 ( 100 ) ;
continue;
}
F_9 ( V_2 , L_19 ) ;
return 0 ;
}
if ( V_21 == V_26 ) {
F_9 ( V_2 ,
L_20 ) ;
return 1 ;
}
F_9 ( V_2 ,
L_21 ,
V_21 ) ;
F_10 ( 100 ) ;
}
F_11 ( V_2 ,
L_22 ) ;
return 0 ;
}
int F_12 ( struct V_14 * V_2 , int V_27 )
{
if ( V_27 == 0 )
return 0 ;
F_9 ( V_2 ,
L_23 ,
V_27 ,
V_2 -> V_28 . V_13 ,
V_2 -> V_28 . V_13 + V_27 ) ;
V_2 -> V_28 . V_13 += V_27 ;
return F_13 ( V_2 , & V_2 -> V_28 . V_13 ,
V_20 , 4 , 1 ) ;
}
int F_14 ( struct V_14 * V_2 , int V_29 )
{
T_1 V_30 [ 3 ] = { 0 , 0 , 0 } ;
F_9 ( V_2 , L_24 , V_29 ) ;
return F_13 ( V_2 , V_30 , V_31 , 3 * V_29 , 3 ) ;
}
static int F_15 ( struct V_14 * V_2 )
{
int V_17 ;
int V_32 ;
V_17 = F_6 ( V_2 , & V_2 -> V_28 , V_20 , 0 , 8 ) ;
if ( V_17 )
return V_17 ;
if ( V_2 -> V_28 . type == V_33 && V_2 -> V_2 != 0 ) {
V_32 = F_16 ( V_2 , V_20 , V_34 ) ;
if ( V_32 > 0 )
V_2 -> V_18 = V_32 ;
else
F_5 ( V_2 , L_25 ) ;
}
F_2 ( V_2 -> V_35 -> V_4 , & V_2 -> V_28 ) ;
return 0 ;
}
static void F_17 ( struct V_4 * V_4 , struct V_36 * V_35 )
{
F_3 ( V_4 ,
L_26 ,
V_35 -> V_6 , V_35 -> V_7 , V_35 -> V_8 ,
V_35 -> V_9 ) ;
F_3 ( V_4 , L_27 , V_35 -> V_37 ) ;
F_3 ( V_4 , L_28 ) ;
F_3 ( V_4 ,
L_29 ,
V_35 -> V_38 , V_35 -> V_39 ,
( ( ( V_40 ) V_35 -> V_41 ) << 32 ) | V_35 -> V_42 ,
V_35 -> V_43 , V_35 -> V_44 ) ;
F_3 ( V_4 ,
L_30 ,
V_35 -> V_45 , V_35 -> V_46 ) ;
}
int F_18 ( struct V_4 * V_4 , V_40 V_47 )
{
struct V_48 V_17 ;
struct V_36 V_49 = {
V_49 . V_41 = V_47 >> 32 ,
V_49 . V_42 = V_47 ,
V_49 . V_43 = true ,
} ;
F_3 ( V_4 , L_31 , V_47 ) ;
V_17 . V_50 = F_19 ( V_4 -> V_51 , ( ( T_1 * ) & V_49 ) + 2 , V_47 ,
0 , 2 , 2 , 2 ) ;
if ( V_17 . V_50 )
return V_17 . V_50 ;
V_17 = F_20 ( V_4 -> V_51 , V_47 , V_52 ) ;
if ( V_17 . V_50 > 0 )
return - V_53 ;
return V_17 . V_50 ;
}
struct V_54 * F_21 ( struct V_54 * V_35 , V_40 V_47 )
{
V_3 V_55 = V_47 ;
if ( V_47 == 0 )
return V_35 ;
if ( V_55 > V_35 -> V_28 . V_37 )
return NULL ;
if ( F_8 ( & V_35 -> V_56 [ V_55 ] ) )
return NULL ;
if ( ! V_35 -> V_56 [ V_55 ] . V_57 )
return NULL ;
return F_21 ( V_35 -> V_56 [ V_55 ] . V_57 -> V_35 ,
V_47 >> V_58 ) ;
}
static int F_22 ( struct V_54 * V_35 , bool V_59 )
{
T_1 V_60 ;
int V_17 ;
V_35 -> V_28 . V_44 = 0xff ;
V_17 = F_23 ( V_35 , ( ( T_1 * ) & V_35 -> V_28 ) + 4 , V_61 , 4 , 1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_24 ( V_35 , & V_60 , V_61 , V_35 -> V_62 + 1 , 1 ) ;
if ( V_17 )
return V_17 ;
if ( V_59 ) {
V_60 = V_60 & 0xFFFFFF83 ;
switch ( V_35 -> V_28 . V_7 ) {
case V_63 :
case V_64 :
case V_65 :
break;
default:
V_60 |= 4 ;
}
} else {
V_60 = V_60 | 0x7c ;
}
return F_23 ( V_35 , & V_60 , V_61 ,
V_35 -> V_62 + 1 , 1 ) ;
}
void F_25 ( struct V_54 * V_35 )
{
int V_66 ;
for ( V_66 = 1 ; V_66 <= V_35 -> V_28 . V_37 ; V_66 ++ ) {
if ( F_8 ( & V_35 -> V_56 [ V_66 ] ) )
continue;
if ( V_35 -> V_56 [ V_66 ] . V_57 )
F_25 ( V_35 -> V_56 [ V_66 ] . V_57 -> V_35 ) ;
V_35 -> V_56 [ V_66 ] . V_57 = NULL ;
}
if ( ! V_35 -> V_67 )
F_22 ( V_35 , false ) ;
F_26 ( V_35 -> V_56 ) ;
F_26 ( V_35 -> V_68 ) ;
F_26 ( V_35 ) ;
}
struct V_54 * F_27 ( struct V_4 * V_4 , V_40 V_47 )
{
int V_66 ;
int V_32 ;
struct V_54 * V_35 ;
int V_69 = F_28 ( V_4 -> V_51 , V_47 ) ;
if ( V_69 < 0 )
return NULL ;
V_35 = F_29 ( sizeof( * V_35 ) , V_70 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_4 = V_4 ;
if ( F_30 ( V_4 -> V_51 , & V_35 -> V_28 , V_47 , 0 , V_61 , 0 , 5 ) )
goto V_50;
F_3 ( V_4 ,
L_32 ,
V_47 , F_31 ( V_47 ) , V_69 ) ;
F_3 ( V_4 , L_33 ) ;
F_17 ( V_4 , & V_35 -> V_28 ) ;
V_35 -> V_28 . V_38 = V_69 ;
V_35 -> V_28 . V_39 = F_31 ( V_47 ) ;
V_35 -> V_28 . V_42 = V_47 ;
V_35 -> V_28 . V_41 = V_47 >> 32 ;
V_35 -> V_28 . V_43 = 1 ;
if ( V_35 -> V_28 . V_6 != 0x8086 )
F_32 ( V_35 , L_34 ,
V_35 -> V_28 . V_6 ) ;
if ( V_35 -> V_28 . V_7 != V_63 &&
V_35 -> V_28 . V_7 != V_71 &&
V_35 -> V_28 . V_7 != V_65 )
F_32 ( V_35 , L_35 ,
V_35 -> V_28 . V_7 ) ;
if ( F_23 ( V_35 , 1 + ( T_1 * ) & V_35 -> V_28 , V_61 , 1 , 3 ) )
goto V_50;
V_35 -> V_56 = F_33 ( V_35 -> V_28 . V_37 + 1 , sizeof( * V_35 -> V_56 ) ,
V_70 ) ;
if ( ! V_35 -> V_56 )
goto V_50;
for ( V_66 = 0 ; V_66 <= V_35 -> V_28 . V_37 ; V_66 ++ ) {
V_35 -> V_56 [ V_66 ] . V_35 = V_35 ;
V_35 -> V_56 [ V_66 ] . V_2 = V_66 ;
}
V_32 = F_16 ( & V_35 -> V_56 [ 0 ] , V_61 , V_72 ) ;
if ( V_32 < 0 ) {
F_32 ( V_35 , L_36 ) ;
goto V_50;
}
V_35 -> V_62 = V_32 ;
if ( F_34 ( V_35 ) )
F_32 ( V_35 , L_37 ) ;
F_35 ( V_35 , L_38 , V_35 -> V_73 ) ;
for ( V_66 = 0 ; V_66 <= V_35 -> V_28 . V_37 ; V_66 ++ ) {
if ( V_35 -> V_56 [ V_66 ] . V_74 ) {
F_9 ( & V_35 -> V_56 [ V_66 ] , L_39 ) ;
continue;
}
if ( F_15 ( & V_35 -> V_56 [ V_66 ] ) )
goto V_50;
}
if ( F_22 ( V_35 , true ) )
goto V_50;
return V_35 ;
V_50:
F_26 ( V_35 -> V_56 ) ;
F_26 ( V_35 -> V_68 ) ;
F_26 ( V_35 ) ;
return NULL ;
}
void F_36 ( struct V_54 * V_35 )
{
int V_66 ;
if ( V_35 == V_35 -> V_4 -> V_75 ) {
F_37 ( V_35 , L_40 ) ;
return;
}
if ( V_35 -> V_67 ) {
F_37 ( V_35 , L_41 ) ;
return;
}
V_35 -> V_67 = true ;
for ( V_66 = 0 ; V_66 <= V_35 -> V_28 . V_37 ; V_66 ++ ) {
if ( ! F_8 ( & V_35 -> V_56 [ V_66 ] ) && V_35 -> V_56 [ V_66 ] . V_57 )
F_36 ( V_35 -> V_56 [ V_66 ] . V_57 -> V_35 ) ;
}
}
int F_38 ( struct V_54 * V_35 )
{
int V_66 , V_50 ;
V_40 V_73 ;
F_35 ( V_35 , L_42 ) ;
V_50 = F_39 ( V_35 , & V_73 ) ;
if ( V_50 ) {
F_32 ( V_35 , L_43 ) ;
return V_50 ;
}
if ( V_35 -> V_73 != V_73 ) {
F_35 ( V_35 ,
L_44 ,
V_35 -> V_73 , V_73 ) ;
return - V_76 ;
}
V_50 = F_23 ( V_35 , 1 + ( T_1 * ) & V_35 -> V_28 , V_61 , 1 , 3 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_22 ( V_35 , true ) ;
if ( V_50 )
return V_50 ;
for ( V_66 = 1 ; V_66 <= V_35 -> V_28 . V_37 ; V_66 ++ ) {
struct V_14 * V_2 = & V_35 -> V_56 [ V_66 ] ;
if ( F_8 ( V_2 ) )
continue;
if ( ! V_2 -> V_57 )
continue;
if ( F_7 ( V_2 , true ) <= 0
|| F_38 ( V_2 -> V_57 -> V_35 ) ) {
F_11 ( V_2 ,
L_45 ) ;
F_36 ( V_2 -> V_57 -> V_35 ) ;
}
}
return 0 ;
}
void F_40 ( struct V_54 * V_35 )
{
int V_66 , V_50 ;
V_50 = F_22 ( V_35 , false ) ;
if ( V_50 )
return;
for ( V_66 = 1 ; V_66 <= V_35 -> V_28 . V_37 ; V_66 ++ ) {
if ( ! F_8 ( & V_35 -> V_56 [ V_66 ] ) && V_35 -> V_56 [ V_66 ] . V_57 )
F_40 ( V_35 -> V_56 [ V_66 ] . V_57 -> V_35 ) ;
}
}
