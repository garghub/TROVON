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
unsigned long V_11 ;
F_5 ( & V_5 -> V_12 , V_11 ) ;
if ( V_8 )
V_6 -> V_13 |= V_9 ;
else
V_6 -> V_13 &= ~ V_9 ;
V_5 -> V_14 ( V_6 -> V_15 + V_16 , V_6 -> V_13 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
}
static int F_7 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_7 > V_3 -> V_17 )
return - V_18 ;
if ( V_6 -> V_19 [ V_7 ] . V_20 < 0 )
return - V_18 ;
return F_8 ( V_6 -> V_21 , V_7 ) ;
}
static int F_9 ( struct V_22 * V_23 , unsigned int type )
{
struct V_1 * V_6 = F_10 ( V_23 ) ;
unsigned long V_11 ;
T_1 V_9 = F_11 ( V_23 -> V_24 ) ;
T_1 V_25 ;
T_1 V_26 ;
T_1 V_27 ;
T_1 V_28 ;
switch ( type ) {
case V_29 :
V_27 = 0 ;
V_28 = 0 ;
break;
case V_30 :
V_27 = V_9 ;
V_28 = 0 ;
break;
case V_31 :
V_27 = 0 ;
V_28 = V_9 ;
break;
case V_32 :
V_27 = V_9 ;
V_28 = V_9 ;
break;
default:
return - V_33 ;
}
F_5 ( & V_6 -> V_5 . V_12 , V_11 ) ;
V_25 = V_6 -> V_5 . V_34 ( V_6 -> V_15 + V_35 ) & ~ V_9 ;
V_26 = V_6 -> V_5 . V_34 ( V_6 -> V_15 + V_36 ) & ~ V_9 ;
V_6 -> V_5 . V_14 ( V_6 -> V_15 + V_35 , V_25 | V_27 ) ;
V_6 -> V_5 . V_14 ( V_6 -> V_15 + V_36 , V_26 | V_28 ) ;
F_6 ( & V_6 -> V_5 . V_12 , V_11 ) ;
return 0 ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_1 * V_6 = F_10 ( V_23 ) ;
int V_7 = V_23 -> V_24 ;
F_4 ( V_6 , V_7 , 0 ) ;
}
static void F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_6 = F_10 ( V_23 ) ;
int V_7 = V_23 -> V_24 ;
F_4 ( V_6 , V_7 , 1 ) ;
}
static T_2 F_14 ( int V_37 , void * V_38 )
{
struct V_1 * V_6 = V_38 ;
int V_17 = V_6 -> V_5 . V_3 . V_17 ;
unsigned long V_11 ;
int V_39 ;
int V_40 = 0 ;
F_5 ( & V_6 -> V_5 . V_12 , V_11 ) ;
for ( V_39 = 0 ; V_39 < V_17 ; V_39 ++ ) {
struct V_41 * V_42 = & V_6 -> V_19 [ V_39 ] ;
if ( V_6 -> V_13 & F_11 ( V_39 ) && V_42 -> V_20 >= 0 &&
V_6 -> V_43 [ V_42 -> V_20 ] . V_44 == V_37 ) {
F_15 ( V_42 -> V_37 ) ;
V_40 = 1 ;
}
}
F_6 ( & V_6 -> V_5 . V_12 , V_11 ) ;
if ( ! V_40 )
F_16 ( V_6 -> V_38 , L_1 , V_37 ) ;
return V_45 ;
}
static int F_17 ( struct V_46 * V_23 , unsigned int V_37 ,
T_3 V_24 )
{
struct V_1 * V_6 = V_23 -> V_47 ;
struct V_41 * V_42 ;
struct V_48 * V_44 ;
unsigned long V_11 ;
int V_7 = V_24 ;
int V_49 = 0 ;
if ( ! V_6 )
return - V_33 ;
V_42 = & V_6 -> V_19 [ V_7 ] ;
if ( V_42 -> V_20 < 0 )
return - V_33 ;
F_18 ( V_6 -> V_38 , L_2 ,
V_37 , V_7 ) ;
F_5 ( & V_6 -> V_5 . V_12 , V_11 ) ;
V_42 -> V_37 = V_37 ;
V_44 = & V_6 -> V_43 [ V_42 -> V_20 ] ;
if ( V_44 -> V_50 == 0 ) {
V_49 = F_19 ( V_44 -> V_44 , F_14 , 0 ,
F_20 ( V_6 -> V_38 ) , V_6 ) ;
if ( V_49 ) {
F_21 ( V_6 -> V_38 ,
L_3 ,
V_44 -> V_44 ) ;
F_6 ( & V_6 -> V_5 . V_12 , V_11 ) ;
return V_49 ;
}
}
V_44 -> V_50 ++ ;
F_6 ( & V_6 -> V_5 . V_12 , V_11 ) ;
F_22 ( V_37 , V_6 ) ;
F_23 ( V_37 , & V_51 ,
V_52 ) ;
F_24 ( V_37 , V_53 ) ;
#ifdef F_25
F_26 ( V_37 , V_54 ) ;
#else
F_27 ( V_37 ) ;
#endif
return V_49 ;
}
static void F_28 ( struct V_46 * V_23 , unsigned int V_37 )
{
struct V_1 * V_6 = V_23 -> V_47 ;
int V_20 ;
struct V_41 * V_42 ;
struct V_48 * V_44 ;
unsigned long V_11 ;
int V_17 = V_6 -> V_5 . V_3 . V_17 ;
int V_39 ;
#ifdef F_25
F_26 ( V_37 , 0 ) ;
#endif
F_23 ( V_37 , NULL , NULL ) ;
F_22 ( V_37 , NULL ) ;
F_5 ( & V_6 -> V_5 . V_12 , V_11 ) ;
V_20 = - 1 ;
for ( V_39 = 0 ; V_39 < V_17 ; V_39 ++ ) {
V_42 = & V_6 -> V_19 [ V_39 ] ;
if ( V_42 -> V_37 == V_37 ) {
F_4 ( V_6 , V_39 , 0 ) ;
V_42 -> V_37 = 0 ;
V_20 = V_42 -> V_20 ;
break;
}
}
F_29 ( V_20 < 0 ) ;
if ( V_20 >= 0 ) {
V_44 = & V_6 -> V_43 [ V_42 -> V_20 ] ;
V_44 -> V_50 -- ;
if ( V_44 -> V_50 == 0 )
F_30 ( V_44 -> V_44 , V_6 ) ;
}
F_6 ( & V_6 -> V_5 . V_12 , V_11 ) ;
}
static int F_31 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = V_56 -> V_38 . V_59 ;
void T_4 * V_15 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_1 * V_6 ;
struct V_60 * V_61 ;
int V_62 ;
T_1 V_63 ;
T_5 * V_64 ;
int V_65 ;
int V_39 ;
V_6 = F_32 ( & V_56 -> V_38 , sizeof( * V_6 ) , V_66 ) ;
if ( ! V_6 )
return - V_67 ;
V_61 = F_33 ( V_56 , V_68 , 0 ) ;
V_15 = F_34 ( & V_56 -> V_38 , V_61 ) ;
if ( F_35 ( V_15 ) )
return F_36 ( V_15 ) ;
V_5 = & V_6 -> V_5 ;
V_62 = F_37 ( V_5 , & V_56 -> V_38 , 4 , V_15 + V_69 ,
V_15 + V_70 , NULL , V_15 + V_71 , NULL ,
V_72 ) ;
if ( V_62 ) {
F_21 ( & V_56 -> V_38 , L_4 ) ;
return V_62 ;
}
V_6 -> V_15 = V_15 ;
V_6 -> V_13 = V_5 -> V_34 ( V_15 + V_16 ) ;
V_6 -> V_38 = & V_56 -> V_38 ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_59 = V_58 ;
V_3 -> V_73 = V_74 ;
V_3 -> V_75 = F_7 ;
V_3 -> V_76 = V_58 -> V_77 ;
V_3 -> V_78 = - 1 ;
V_62 = F_38 ( V_58 , L_5 , & V_63 ) ;
if ( V_62 || V_63 <= 0 || V_63 > V_79 ) {
V_3 -> V_17 = V_79 ;
F_18 ( & V_56 -> V_38 ,
L_6 , V_3 -> V_17 ) ;
} else {
V_3 -> V_17 = V_63 ;
}
V_64 = ( T_5 * ) F_39 ( V_58 , L_7 , & V_65 ) ;
if ( V_64 ) {
if ( V_65 < V_3 -> V_17 ) {
F_21 ( & V_56 -> V_38 ,
L_8 ,
V_65 , V_3 -> V_17 ) ;
return - V_33 ;
}
V_6 -> V_21 = F_40 ( V_58 , V_3 -> V_17 ,
& V_80 ,
V_6 ) ;
if ( ! V_6 -> V_21 ) {
F_21 ( & V_56 -> V_38 , L_9 ) ;
return - V_33 ;
}
for ( V_39 = 0 ; V_39 < V_3 -> V_17 ; V_39 ++ ) {
struct V_41 * V_42 ;
int V_49 ;
V_42 = & V_6 -> V_19 [ V_39 ] ;
V_42 -> V_20 = V_64 [ V_39 ] ;
if ( V_42 -> V_20 < 0 )
continue;
V_49 = F_41 ( V_56 , V_42 -> V_20 ) ;
if ( V_49 <= 0 ) {
F_21 ( V_6 -> V_38 ,
L_10 , V_39 ) ;
continue;
}
V_6 -> V_43 [ V_42 -> V_20 ] . V_44 = V_49 ;
}
}
F_42 ( V_56 , V_6 ) ;
V_62 = F_43 ( V_3 ) ;
if ( V_62 ) {
F_21 ( & V_56 -> V_38 , L_11 ) ;
if ( V_6 -> V_21 )
F_44 ( V_6 -> V_21 ) ;
return V_62 ;
}
F_45 ( & V_56 -> V_38 , L_12 ,
V_6 -> V_15 , V_3 -> V_78 , V_3 -> V_17 , V_6 -> V_21 ? L_13 : L_14 ) ;
return 0 ;
}
static int F_46 ( struct V_55 * V_56 )
{
struct V_1 * V_6 = F_47 ( V_56 ) ;
unsigned long V_11 ;
int V_39 ;
int V_49 = 0 ;
F_5 ( & V_6 -> V_5 . V_12 , V_11 ) ;
if ( V_6 -> V_21 ) {
for ( V_39 = 0 ; V_39 < V_79 ; V_39 ++ ) {
if ( V_6 -> V_43 [ V_39 ] . V_50 != 0 ) {
V_49 = - V_81 ;
goto V_82;
}
}
}
F_48 ( & V_6 -> V_5 . V_3 ) ;
if ( V_6 -> V_21 )
F_44 ( V_6 -> V_21 ) ;
V_82:
F_6 ( & V_6 -> V_5 . V_12 , V_11 ) ;
return V_49 ;
}
