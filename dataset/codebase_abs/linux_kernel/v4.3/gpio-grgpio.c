static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_6 , unsigned int V_7 ,
int V_8 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
unsigned long V_9 = V_5 -> V_10 ( V_5 , V_7 ) ;
if ( V_8 )
V_6 -> V_11 |= V_9 ;
else
V_6 -> V_11 &= ~ V_9 ;
V_5 -> V_12 ( V_6 -> V_13 + V_14 , V_6 -> V_11 ) ;
}
static int F_5 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_7 >= V_3 -> V_15 )
return - V_16 ;
if ( V_6 -> V_17 [ V_7 ] . V_18 < 0 )
return - V_16 ;
return F_6 ( V_6 -> V_19 , V_7 ) ;
}
static int F_7 ( struct V_20 * V_21 , unsigned int type )
{
struct V_1 * V_6 = F_8 ( V_21 ) ;
unsigned long V_22 ;
T_1 V_9 = F_9 ( V_21 -> V_23 ) ;
T_1 V_24 ;
T_1 V_25 ;
T_1 V_26 ;
T_1 V_27 ;
switch ( type ) {
case V_28 :
V_26 = 0 ;
V_27 = 0 ;
break;
case V_29 :
V_26 = V_9 ;
V_27 = 0 ;
break;
case V_30 :
V_26 = 0 ;
V_27 = V_9 ;
break;
case V_31 :
V_26 = V_9 ;
V_27 = V_9 ;
break;
default:
return - V_32 ;
}
F_10 ( & V_6 -> V_5 . V_33 , V_22 ) ;
V_24 = V_6 -> V_5 . V_34 ( V_6 -> V_13 + V_35 ) & ~ V_9 ;
V_25 = V_6 -> V_5 . V_34 ( V_6 -> V_13 + V_36 ) & ~ V_9 ;
V_6 -> V_5 . V_12 ( V_6 -> V_13 + V_35 , V_24 | V_26 ) ;
V_6 -> V_5 . V_12 ( V_6 -> V_13 + V_36 , V_25 | V_27 ) ;
F_11 ( & V_6 -> V_5 . V_33 , V_22 ) ;
return 0 ;
}
static void F_12 ( struct V_20 * V_21 )
{
struct V_1 * V_6 = F_8 ( V_21 ) ;
int V_7 = V_21 -> V_23 ;
unsigned long V_22 ;
F_10 ( & V_6 -> V_5 . V_33 , V_22 ) ;
F_4 ( V_6 , V_7 , 0 ) ;
F_11 ( & V_6 -> V_5 . V_33 , V_22 ) ;
}
static void F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_6 = F_8 ( V_21 ) ;
int V_7 = V_21 -> V_23 ;
unsigned long V_22 ;
F_10 ( & V_6 -> V_5 . V_33 , V_22 ) ;
F_4 ( V_6 , V_7 , 1 ) ;
F_11 ( & V_6 -> V_5 . V_33 , V_22 ) ;
}
static T_2 F_14 ( int V_37 , void * V_38 )
{
struct V_1 * V_6 = V_38 ;
int V_15 = V_6 -> V_5 . V_3 . V_15 ;
unsigned long V_22 ;
int V_39 ;
int V_40 = 0 ;
F_10 ( & V_6 -> V_5 . V_33 , V_22 ) ;
for ( V_39 = 0 ; V_39 < V_15 ; V_39 ++ ) {
struct V_41 * V_42 = & V_6 -> V_17 [ V_39 ] ;
if ( V_6 -> V_11 & F_9 ( V_39 ) && V_42 -> V_18 >= 0 &&
V_6 -> V_43 [ V_42 -> V_18 ] . V_44 == V_37 ) {
F_15 ( V_42 -> V_37 ) ;
V_40 = 1 ;
}
}
F_11 ( & V_6 -> V_5 . V_33 , V_22 ) ;
if ( ! V_40 )
F_16 ( V_6 -> V_38 , L_1 , V_37 ) ;
return V_45 ;
}
static int F_17 ( struct V_46 * V_21 , unsigned int V_37 ,
T_3 V_23 )
{
struct V_1 * V_6 = V_21 -> V_47 ;
struct V_41 * V_42 ;
struct V_48 * V_44 ;
unsigned long V_22 ;
int V_7 = V_23 ;
int V_49 = 0 ;
if ( ! V_6 )
return - V_32 ;
V_42 = & V_6 -> V_17 [ V_7 ] ;
if ( V_42 -> V_18 < 0 )
return - V_32 ;
F_18 ( V_6 -> V_38 , L_2 ,
V_37 , V_7 ) ;
F_10 ( & V_6 -> V_5 . V_33 , V_22 ) ;
V_42 -> V_37 = V_37 ;
V_44 = & V_6 -> V_43 [ V_42 -> V_18 ] ;
if ( V_44 -> V_50 == 0 ) {
V_49 = F_19 ( V_44 -> V_44 , F_14 , 0 ,
F_20 ( V_6 -> V_38 ) , V_6 ) ;
if ( V_49 ) {
F_21 ( V_6 -> V_38 ,
L_3 ,
V_44 -> V_44 ) ;
F_11 ( & V_6 -> V_5 . V_33 , V_22 ) ;
return V_49 ;
}
}
V_44 -> V_50 ++ ;
F_11 ( & V_6 -> V_5 . V_33 , V_22 ) ;
F_22 ( V_37 , V_6 ) ;
F_23 ( V_37 , & V_51 ,
V_52 ) ;
F_24 ( V_37 ) ;
return V_49 ;
}
static void F_25 ( struct V_46 * V_21 , unsigned int V_37 )
{
struct V_1 * V_6 = V_21 -> V_47 ;
int V_18 ;
struct V_41 * V_42 ;
struct V_48 * V_44 ;
unsigned long V_22 ;
int V_15 = V_6 -> V_5 . V_3 . V_15 ;
int V_39 ;
F_23 ( V_37 , NULL , NULL ) ;
F_22 ( V_37 , NULL ) ;
F_10 ( & V_6 -> V_5 . V_33 , V_22 ) ;
V_18 = - 1 ;
for ( V_39 = 0 ; V_39 < V_15 ; V_39 ++ ) {
V_42 = & V_6 -> V_17 [ V_39 ] ;
if ( V_42 -> V_37 == V_37 ) {
F_4 ( V_6 , V_39 , 0 ) ;
V_42 -> V_37 = 0 ;
V_18 = V_42 -> V_18 ;
break;
}
}
F_26 ( V_18 < 0 ) ;
if ( V_18 >= 0 ) {
V_44 = & V_6 -> V_43 [ V_42 -> V_18 ] ;
V_44 -> V_50 -- ;
if ( V_44 -> V_50 == 0 )
F_27 ( V_44 -> V_44 , V_6 ) ;
}
F_11 ( & V_6 -> V_5 . V_33 , V_22 ) ;
}
static int F_28 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_38 . V_57 ;
void T_4 * V_13 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_1 * V_6 ;
struct V_58 * V_59 ;
int V_60 ;
T_1 V_61 ;
T_5 * V_62 ;
int V_63 ;
int V_39 ;
V_6 = F_29 ( & V_54 -> V_38 , sizeof( * V_6 ) , V_64 ) ;
if ( ! V_6 )
return - V_65 ;
V_59 = F_30 ( V_54 , V_66 , 0 ) ;
V_13 = F_31 ( & V_54 -> V_38 , V_59 ) ;
if ( F_32 ( V_13 ) )
return F_33 ( V_13 ) ;
V_5 = & V_6 -> V_5 ;
V_60 = F_34 ( V_5 , & V_54 -> V_38 , 4 , V_13 + V_67 ,
V_13 + V_68 , NULL , V_13 + V_69 , NULL ,
V_70 ) ;
if ( V_60 ) {
F_21 ( & V_54 -> V_38 , L_4 ) ;
return V_60 ;
}
V_6 -> V_13 = V_13 ;
V_6 -> V_11 = V_5 -> V_34 ( V_13 + V_14 ) ;
V_6 -> V_38 = & V_54 -> V_38 ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_57 = V_56 ;
V_3 -> V_71 = V_72 ;
V_3 -> V_73 = F_5 ;
V_3 -> V_74 = V_56 -> V_75 ;
V_3 -> V_76 = - 1 ;
V_60 = F_35 ( V_56 , L_5 , & V_61 ) ;
if ( V_60 || V_61 <= 0 || V_61 > V_77 ) {
V_3 -> V_15 = V_77 ;
F_18 ( & V_54 -> V_38 ,
L_6 , V_3 -> V_15 ) ;
} else {
V_3 -> V_15 = V_61 ;
}
V_62 = ( T_5 * ) F_36 ( V_56 , L_7 , & V_63 ) ;
if ( V_62 ) {
if ( V_63 < V_3 -> V_15 ) {
F_21 ( & V_54 -> V_38 ,
L_8 ,
V_63 , V_3 -> V_15 ) ;
return - V_32 ;
}
V_6 -> V_19 = F_37 ( V_56 , V_3 -> V_15 ,
& V_78 ,
V_6 ) ;
if ( ! V_6 -> V_19 ) {
F_21 ( & V_54 -> V_38 , L_9 ) ;
return - V_32 ;
}
for ( V_39 = 0 ; V_39 < V_3 -> V_15 ; V_39 ++ ) {
struct V_41 * V_42 ;
int V_49 ;
V_42 = & V_6 -> V_17 [ V_39 ] ;
V_42 -> V_18 = V_62 [ V_39 ] ;
if ( V_42 -> V_18 < 0 )
continue;
V_49 = F_38 ( V_54 , V_42 -> V_18 ) ;
if ( V_49 <= 0 ) {
F_21 ( V_6 -> V_38 ,
L_10 , V_39 ) ;
continue;
}
V_6 -> V_43 [ V_42 -> V_18 ] . V_44 = V_49 ;
}
}
F_39 ( V_54 , V_6 ) ;
V_60 = F_40 ( V_3 ) ;
if ( V_60 ) {
F_21 ( & V_54 -> V_38 , L_11 ) ;
if ( V_6 -> V_19 )
F_41 ( V_6 -> V_19 ) ;
return V_60 ;
}
F_42 ( & V_54 -> V_38 , L_12 ,
V_6 -> V_13 , V_3 -> V_76 , V_3 -> V_15 , V_6 -> V_19 ? L_13 : L_14 ) ;
return 0 ;
}
static int F_43 ( struct V_53 * V_54 )
{
struct V_1 * V_6 = F_44 ( V_54 ) ;
unsigned long V_22 ;
int V_39 ;
int V_49 = 0 ;
F_10 ( & V_6 -> V_5 . V_33 , V_22 ) ;
if ( V_6 -> V_19 ) {
for ( V_39 = 0 ; V_39 < V_77 ; V_39 ++ ) {
if ( V_6 -> V_43 [ V_39 ] . V_50 != 0 ) {
V_49 = - V_79 ;
goto V_80;
}
}
}
F_45 ( & V_6 -> V_5 . V_3 ) ;
if ( V_6 -> V_19 )
F_41 ( V_6 -> V_19 ) ;
V_80:
F_11 ( & V_6 -> V_5 . V_33 , V_22 ) ;
return V_49 ;
}
