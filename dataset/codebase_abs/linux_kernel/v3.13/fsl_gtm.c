struct V_1 * F_1 ( void )
{
struct V_2 * V_2 = NULL ;
int V_3 ;
F_2 (gtm, &gtms, list_node) {
F_3 ( & V_2 -> V_4 ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_2 -> V_5 ) ; V_3 ++ ) {
if ( ! V_2 -> V_5 [ V_3 ] . V_6 ) {
V_2 -> V_5 [ V_3 ] . V_6 = true ;
F_5 ( & V_2 -> V_4 ) ;
return & V_2 -> V_5 [ V_3 ] ;
}
}
F_5 ( & V_2 -> V_4 ) ;
}
if ( V_2 )
return F_6 ( - V_7 ) ;
return F_6 ( - V_8 ) ;
}
struct V_1 * F_7 ( struct V_2 * V_2 ,
unsigned int V_9 )
{
struct V_1 * V_10 = F_6 ( - V_7 ) ;
if ( V_9 > 3 )
return F_6 ( - V_11 ) ;
F_3 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_5 [ V_9 ] . V_6 )
goto V_12;
V_10 = & V_2 -> V_5 [ V_9 ] ;
V_10 -> V_6 = true ;
V_12:
F_5 ( & V_2 -> V_4 ) ;
return V_10 ;
}
void F_8 ( struct V_1 * V_13 )
{
F_9 ( V_13 ) ;
F_3 ( & V_13 -> V_2 -> V_4 ) ;
V_13 -> V_6 = false ;
F_5 ( & V_13 -> V_2 -> V_4 ) ;
}
static int F_10 ( struct V_1 * V_13 , int V_14 ,
int V_15 , bool V_16 )
{
struct V_2 * V_2 = V_13 -> V_2 ;
int V_17 = V_13 - & V_2 -> V_5 [ 0 ] ;
unsigned int V_18 ;
T_1 V_19 = V_20 ;
T_1 V_21 ;
T_1 V_22 ;
unsigned long V_23 ;
int V_24 = 256 * 256 * 16 ;
if ( ! V_13 -> V_25 )
V_24 /= 256 ;
V_18 = V_2 -> clock / V_14 ;
if ( V_18 > V_24 )
return - V_11 ;
if ( V_18 > V_24 / 16 ) {
V_19 = V_26 ;
V_18 /= 16 ;
}
if ( V_18 <= 256 ) {
V_21 = 0 ;
V_22 = V_18 - 1 ;
} else {
V_21 = 256 - 1 ;
V_22 = V_18 / 256 - 1 ;
}
F_11 ( & V_2 -> V_4 , V_23 ) ;
F_12 ( V_13 -> V_27 , ~ ( F_13 ( V_17 ) | F_14 ( V_17 ) ) ,
F_13 ( V_17 ) | F_14 ( V_17 ) ) ;
F_15 ( V_13 -> V_27 , F_13 ( V_17 ) ) ;
if ( V_13 -> V_25 )
F_16 ( V_13 -> V_25 , V_21 ) ;
F_17 ( V_13 -> V_28 , 0xFFFF , V_19 | F_18 ( V_22 ) |
V_29 | ( V_16 ? V_30 : 0 ) ) ;
F_16 ( V_13 -> V_31 , 0 ) ;
F_16 ( V_13 -> V_32 , V_15 ) ;
F_16 ( V_13 -> V_33 , 0xFFFF ) ;
F_19 ( V_13 -> V_27 , F_13 ( V_17 ) ) ;
F_20 ( & V_2 -> V_4 , V_23 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_13 , unsigned long V_34 , bool V_35 )
{
int V_36 = 1000000 ;
unsigned int V_37 ;
V_37 = F_22 ( V_34 ) ;
if ( V_37 > 15 ) {
V_36 >>= V_37 - 15 ;
V_34 >>= V_37 - 15 ;
}
if ( ! V_36 )
return - V_11 ;
return F_10 ( V_13 , V_36 , V_34 , V_35 ) ;
}
int F_23 ( struct V_1 * V_13 , T_2 V_34 , bool V_35 )
{
const int V_36 = 1000000 ;
return F_10 ( V_13 , V_36 , V_34 , V_35 ) ;
}
void F_9 ( struct V_1 * V_13 )
{
struct V_2 * V_2 = V_13 -> V_2 ;
int V_17 = V_13 - & V_2 -> V_5 [ 0 ] ;
unsigned long V_23 ;
F_11 ( & V_2 -> V_4 , V_23 ) ;
F_15 ( V_13 -> V_27 , F_13 ( V_17 ) ) ;
F_16 ( V_13 -> V_33 , 0xFFFF ) ;
F_20 ( & V_2 -> V_4 , V_23 ) ;
}
void F_24 ( struct V_1 * V_13 , T_2 V_38 )
{
F_16 ( V_13 -> V_33 , V_38 ) ;
}
static void T_3 F_25 ( struct V_39 * V_40 ,
struct V_1 * V_5 ,
struct V_41 T_4 * V_42 )
{
V_5 [ 0 ] . V_27 = & V_42 -> V_43 ;
V_5 [ 0 ] . V_28 = & V_42 -> V_44 ;
V_5 [ 0 ] . V_31 = & V_42 -> V_45 ;
V_5 [ 0 ] . V_32 = & V_42 -> V_46 ;
V_5 [ 0 ] . V_33 = & V_42 -> V_47 ;
V_5 [ 1 ] . V_27 = & V_42 -> V_43 ;
V_5 [ 1 ] . V_28 = & V_42 -> V_48 ;
V_5 [ 1 ] . V_31 = & V_42 -> V_49 ;
V_5 [ 1 ] . V_32 = & V_42 -> V_50 ;
V_5 [ 1 ] . V_33 = & V_42 -> V_51 ;
V_5 [ 2 ] . V_27 = & V_42 -> V_52 ;
V_5 [ 2 ] . V_28 = & V_42 -> V_53 ;
V_5 [ 2 ] . V_31 = & V_42 -> V_54 ;
V_5 [ 2 ] . V_32 = & V_42 -> V_55 ;
V_5 [ 2 ] . V_33 = & V_42 -> V_56 ;
V_5 [ 3 ] . V_27 = & V_42 -> V_52 ;
V_5 [ 3 ] . V_28 = & V_42 -> V_57 ;
V_5 [ 3 ] . V_31 = & V_42 -> V_58 ;
V_5 [ 3 ] . V_32 = & V_42 -> V_59 ;
V_5 [ 3 ] . V_33 = & V_42 -> V_60 ;
if ( ! F_26 ( V_40 , L_1 ) ) {
V_5 [ 0 ] . V_25 = & V_42 -> V_61 ;
V_5 [ 1 ] . V_25 = & V_42 -> V_62 ;
V_5 [ 2 ] . V_25 = & V_42 -> V_63 ;
V_5 [ 3 ] . V_25 = & V_42 -> V_64 ;
}
}
static int T_3 F_27 ( void )
{
struct V_39 * V_40 ;
F_28 (np, NULL, L_2 ) {
int V_3 ;
struct V_2 * V_2 ;
const T_5 * clock ;
int V_65 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 ) {
F_30 ( L_3 ,
V_40 -> V_67 ) ;
continue;
}
F_31 ( & V_2 -> V_4 ) ;
clock = F_32 ( V_40 , L_4 , & V_65 ) ;
if ( ! clock || V_65 != sizeof( * clock ) ) {
F_30 ( L_5 , V_40 -> V_67 ) ;
goto V_68;
}
V_2 -> clock = * clock ;
for ( V_3 = 0 ; V_3 < F_4 ( V_2 -> V_5 ) ; V_3 ++ ) {
unsigned int V_69 ;
V_69 = F_33 ( V_40 , V_3 ) ;
if ( V_69 == V_70 ) {
F_30 ( L_6 ,
V_40 -> V_67 ) ;
goto V_68;
}
V_2 -> V_5 [ V_3 ] . V_69 = V_69 ;
V_2 -> V_5 [ V_3 ] . V_2 = V_2 ;
}
V_2 -> V_42 = F_34 ( V_40 , 0 ) ;
if ( ! V_2 -> V_42 ) {
F_30 ( L_7 ,
V_40 -> V_67 ) ;
goto V_68;
}
F_25 ( V_40 , V_2 -> V_5 , V_2 -> V_42 ) ;
F_35 ( & V_2 -> V_71 , & V_72 ) ;
V_40 -> V_73 = V_2 ;
F_36 ( V_40 ) ;
continue;
V_68:
F_37 ( V_2 ) ;
}
return 0 ;
}
