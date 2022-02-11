static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned long V_7 = V_6 -> V_8 ( V_6 , V_3 ) ;
if ( V_4 )
V_2 -> V_9 |= V_7 ;
else
V_2 -> V_9 &= ~ V_7 ;
V_6 -> V_10 ( V_2 -> V_11 + V_12 , V_2 -> V_9 ) ;
}
static int F_2 ( struct V_5 * V_6 , unsigned V_3 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
if ( V_3 >= V_6 -> V_13 )
return - V_14 ;
if ( V_2 -> V_15 [ V_3 ] . V_16 < 0 )
return - V_14 ;
return F_4 ( V_2 -> V_17 , V_3 ) ;
}
static int F_5 ( struct V_18 * V_19 , unsigned int type )
{
struct V_1 * V_2 = F_6 ( V_19 ) ;
unsigned long V_20 ;
T_1 V_7 = F_7 ( V_19 -> V_21 ) ;
T_1 V_22 ;
T_1 V_23 ;
T_1 V_24 ;
T_1 V_25 ;
switch ( type ) {
case V_26 :
V_24 = 0 ;
V_25 = 0 ;
break;
case V_27 :
V_24 = V_7 ;
V_25 = 0 ;
break;
case V_28 :
V_24 = 0 ;
V_25 = V_7 ;
break;
case V_29 :
V_24 = V_7 ;
V_25 = V_7 ;
break;
default:
return - V_30 ;
}
F_8 ( & V_2 -> V_6 . V_31 , V_20 ) ;
V_22 = V_2 -> V_6 . V_32 ( V_2 -> V_11 + V_33 ) & ~ V_7 ;
V_23 = V_2 -> V_6 . V_32 ( V_2 -> V_11 + V_34 ) & ~ V_7 ;
V_2 -> V_6 . V_10 ( V_2 -> V_11 + V_33 , V_22 | V_24 ) ;
V_2 -> V_6 . V_10 ( V_2 -> V_11 + V_34 , V_23 | V_25 ) ;
F_9 ( & V_2 -> V_6 . V_31 , V_20 ) ;
return 0 ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_6 ( V_19 ) ;
int V_3 = V_19 -> V_21 ;
unsigned long V_20 ;
F_8 ( & V_2 -> V_6 . V_31 , V_20 ) ;
F_1 ( V_2 , V_3 , 0 ) ;
F_9 ( & V_2 -> V_6 . V_31 , V_20 ) ;
}
static void F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_6 ( V_19 ) ;
int V_3 = V_19 -> V_21 ;
unsigned long V_20 ;
F_8 ( & V_2 -> V_6 . V_31 , V_20 ) ;
F_1 ( V_2 , V_3 , 1 ) ;
F_9 ( & V_2 -> V_6 . V_31 , V_20 ) ;
}
static T_2 F_12 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
int V_13 = V_2 -> V_6 . V_13 ;
unsigned long V_20 ;
int V_37 ;
int V_38 = 0 ;
F_8 ( & V_2 -> V_6 . V_31 , V_20 ) ;
for ( V_37 = 0 ; V_37 < V_13 ; V_37 ++ ) {
struct V_39 * V_40 = & V_2 -> V_15 [ V_37 ] ;
if ( V_2 -> V_9 & F_7 ( V_37 ) && V_40 -> V_16 >= 0 &&
V_2 -> V_41 [ V_40 -> V_16 ] . V_42 == V_35 ) {
F_13 ( V_40 -> V_35 ) ;
V_38 = 1 ;
}
}
F_9 ( & V_2 -> V_6 . V_31 , V_20 ) ;
if ( ! V_38 )
F_14 ( V_2 -> V_36 , L_1 , V_35 ) ;
return V_43 ;
}
static int F_15 ( struct V_44 * V_19 , unsigned int V_35 ,
T_3 V_21 )
{
struct V_1 * V_2 = V_19 -> V_45 ;
struct V_39 * V_40 ;
struct V_46 * V_42 ;
unsigned long V_20 ;
int V_3 = V_21 ;
int V_47 = 0 ;
if ( ! V_2 )
return - V_30 ;
V_40 = & V_2 -> V_15 [ V_3 ] ;
if ( V_40 -> V_16 < 0 )
return - V_30 ;
F_16 ( V_2 -> V_36 , L_2 ,
V_35 , V_3 ) ;
F_8 ( & V_2 -> V_6 . V_31 , V_20 ) ;
V_40 -> V_35 = V_35 ;
V_42 = & V_2 -> V_41 [ V_40 -> V_16 ] ;
if ( V_42 -> V_48 == 0 ) {
V_47 = F_17 ( V_42 -> V_42 , F_12 , 0 ,
F_18 ( V_2 -> V_36 ) , V_2 ) ;
if ( V_47 ) {
F_19 ( V_2 -> V_36 ,
L_3 ,
V_42 -> V_42 ) ;
F_9 ( & V_2 -> V_6 . V_31 , V_20 ) ;
return V_47 ;
}
}
V_42 -> V_48 ++ ;
F_9 ( & V_2 -> V_6 . V_31 , V_20 ) ;
F_20 ( V_35 , V_2 ) ;
F_21 ( V_35 , & V_49 ,
V_50 ) ;
F_22 ( V_35 ) ;
return V_47 ;
}
static void F_23 ( struct V_44 * V_19 , unsigned int V_35 )
{
struct V_1 * V_2 = V_19 -> V_45 ;
int V_16 ;
struct V_39 * V_40 ;
struct V_46 * V_42 ;
unsigned long V_20 ;
int V_13 = V_2 -> V_6 . V_13 ;
int V_37 ;
F_21 ( V_35 , NULL , NULL ) ;
F_20 ( V_35 , NULL ) ;
F_8 ( & V_2 -> V_6 . V_31 , V_20 ) ;
V_16 = - 1 ;
for ( V_37 = 0 ; V_37 < V_13 ; V_37 ++ ) {
V_40 = & V_2 -> V_15 [ V_37 ] ;
if ( V_40 -> V_35 == V_35 ) {
F_1 ( V_2 , V_37 , 0 ) ;
V_40 -> V_35 = 0 ;
V_16 = V_40 -> V_16 ;
break;
}
}
F_24 ( V_16 < 0 ) ;
if ( V_16 >= 0 ) {
V_42 = & V_2 -> V_41 [ V_40 -> V_16 ] ;
V_42 -> V_48 -- ;
if ( V_42 -> V_48 == 0 )
F_25 ( V_42 -> V_42 , V_2 ) ;
}
F_9 ( & V_2 -> V_6 . V_31 , V_20 ) ;
}
static int F_26 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_36 . V_55 ;
void T_4 * V_11 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
int V_58 ;
T_1 V_59 ;
T_5 * V_60 ;
int V_61 ;
int V_37 ;
V_2 = F_27 ( & V_52 -> V_36 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_57 = F_28 ( V_52 , V_64 , 0 ) ;
V_11 = F_29 ( & V_52 -> V_36 , V_57 ) ;
if ( F_30 ( V_11 ) )
return F_31 ( V_11 ) ;
V_6 = & V_2 -> V_6 ;
V_58 = F_32 ( V_6 , & V_52 -> V_36 , 4 , V_11 + V_65 ,
V_11 + V_66 , NULL , V_11 + V_67 , NULL ,
V_68 ) ;
if ( V_58 ) {
F_19 ( & V_52 -> V_36 , L_4 ) ;
return V_58 ;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_9 = V_6 -> V_32 ( V_11 + V_12 ) ;
V_2 -> V_36 = & V_52 -> V_36 ;
V_6 -> V_55 = V_54 ;
V_6 -> V_69 = V_70 ;
V_6 -> V_71 = F_2 ;
V_6 -> V_72 = F_33 ( & V_52 -> V_36 , V_62 , L_5 , V_54 ) ;
V_6 -> V_73 = - 1 ;
V_58 = F_34 ( V_54 , L_6 , & V_59 ) ;
if ( V_58 || V_59 <= 0 || V_59 > V_74 ) {
V_6 -> V_13 = V_74 ;
F_16 ( & V_52 -> V_36 ,
L_7 , V_6 -> V_13 ) ;
} else {
V_6 -> V_13 = V_59 ;
}
V_60 = ( T_5 * ) F_35 ( V_54 , L_8 , & V_61 ) ;
if ( V_60 ) {
if ( V_61 < V_6 -> V_13 ) {
F_19 ( & V_52 -> V_36 ,
L_9 ,
V_61 , V_6 -> V_13 ) ;
return - V_30 ;
}
V_2 -> V_17 = F_36 ( V_54 , V_6 -> V_13 ,
& V_75 ,
V_2 ) ;
if ( ! V_2 -> V_17 ) {
F_19 ( & V_52 -> V_36 , L_10 ) ;
return - V_30 ;
}
for ( V_37 = 0 ; V_37 < V_6 -> V_13 ; V_37 ++ ) {
struct V_39 * V_40 ;
int V_47 ;
V_40 = & V_2 -> V_15 [ V_37 ] ;
V_40 -> V_16 = V_60 [ V_37 ] ;
if ( V_40 -> V_16 < 0 )
continue;
V_47 = F_37 ( V_52 , V_40 -> V_16 ) ;
if ( V_47 <= 0 ) {
F_19 ( V_2 -> V_36 ,
L_11 , V_37 ) ;
continue;
}
V_2 -> V_41 [ V_40 -> V_16 ] . V_42 = V_47 ;
}
}
F_38 ( V_52 , V_2 ) ;
V_58 = F_39 ( V_6 , V_2 ) ;
if ( V_58 ) {
F_19 ( & V_52 -> V_36 , L_12 ) ;
if ( V_2 -> V_17 )
F_40 ( V_2 -> V_17 ) ;
return V_58 ;
}
F_41 ( & V_52 -> V_36 , L_13 ,
V_2 -> V_11 , V_6 -> V_73 , V_6 -> V_13 , V_2 -> V_17 ? L_14 : L_15 ) ;
return 0 ;
}
static int F_42 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_43 ( V_52 ) ;
unsigned long V_20 ;
int V_37 ;
int V_47 = 0 ;
F_8 ( & V_2 -> V_6 . V_31 , V_20 ) ;
if ( V_2 -> V_17 ) {
for ( V_37 = 0 ; V_37 < V_74 ; V_37 ++ ) {
if ( V_2 -> V_41 [ V_37 ] . V_48 != 0 ) {
V_47 = - V_76 ;
goto V_77;
}
}
}
F_44 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_17 )
F_40 ( V_2 -> V_17 ) ;
V_77:
F_9 ( & V_2 -> V_6 . V_31 , V_20 ) ;
return V_47 ;
}
