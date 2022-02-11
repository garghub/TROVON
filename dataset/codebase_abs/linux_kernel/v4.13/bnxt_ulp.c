static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_12 * V_13 ;
F_3 () ;
if ( V_3 >= V_14 )
return - V_15 ;
V_13 = & V_2 -> V_16 [ V_3 ] ;
if ( F_4 ( V_13 -> V_5 ) ) {
F_5 ( V_11 -> V_8 , L_1 , V_3 ) ;
return - V_17 ;
}
if ( V_3 == V_18 ) {
unsigned int V_19 ;
V_19 = F_6 ( V_11 ) ;
if ( V_19 <= V_20 ||
V_11 -> V_21 == V_19 )
return - V_22 ;
F_7 ( V_11 , V_19 -
V_20 ) ;
}
F_8 ( & V_13 -> V_23 , 0 ) ;
V_13 -> V_6 = V_6 ;
F_9 ( V_13 -> V_5 , V_5 ) ;
if ( V_3 == V_18 ) {
if ( F_10 ( V_24 , & V_11 -> V_25 ) )
F_11 ( V_11 , 0 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_12 * V_13 ;
int V_26 = 0 ;
F_3 () ;
if ( V_3 >= V_14 )
return - V_15 ;
V_13 = & V_2 -> V_16 [ V_3 ] ;
if ( ! F_4 ( V_13 -> V_5 ) ) {
F_5 ( V_11 -> V_8 , L_2 , V_3 ) ;
return - V_15 ;
}
if ( V_3 == V_18 ) {
unsigned int V_19 ;
V_19 = F_6 ( V_11 ) ;
F_7 ( V_11 , V_19 + 1 ) ;
if ( V_13 -> V_27 )
V_2 -> V_28 -> V_29 ( V_2 , V_3 ) ;
}
if ( V_13 -> V_30 )
F_13 ( V_11 , NULL , 0 ) ;
F_14 ( V_13 -> V_5 , NULL ) ;
F_15 () ;
V_13 -> V_30 = 0 ;
V_13 -> V_31 = NULL ;
while ( F_16 ( & V_13 -> V_23 ) != 0 && V_26 < 10 ) {
F_17 ( 100 ) ;
V_26 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_3 ,
struct V_32 * V_33 , int V_34 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
int V_35 , V_36 ;
int V_37 , V_26 , V_38 ;
F_3 () ;
if ( V_3 != V_18 )
return - V_15 ;
if ( ! ( V_11 -> V_39 & V_40 ) )
return - V_41 ;
V_36 = F_19 ( V_11 ) ;
V_35 = F_20 ( int , V_11 -> V_42 , V_36 ) ;
V_37 = V_35 - V_11 -> V_43 ;
if ( ! V_37 )
return - V_22 ;
if ( V_37 > V_34 )
V_37 = V_34 ;
V_38 = V_35 - V_37 ;
for ( V_26 = 0 ; V_26 < V_37 ; V_26 ++ ) {
V_33 [ V_26 ] . V_44 = V_11 -> V_45 [ V_38 + V_26 ] . V_44 ;
V_33 [ V_26 ] . V_46 = V_38 + V_26 ;
V_33 [ V_26 ] . V_47 = ( V_38 + V_26 ) * 0x80 ;
}
F_21 ( V_11 , V_35 - V_37 ) ;
F_22 ( V_11 , V_36 - V_37 ) ;
V_2 -> V_16 [ V_3 ] . V_27 = V_37 ;
return V_37 ;
}
static int F_23 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
int V_36 , V_27 ;
F_3 () ;
if ( V_3 != V_18 )
return - V_15 ;
V_36 = F_19 ( V_11 ) ;
V_27 = V_2 -> V_16 [ V_3 ] . V_27 ;
F_22 ( V_11 , V_36 + V_27 ) ;
V_2 -> V_16 [ V_3 ] . V_27 = 0 ;
F_21 ( V_11 , V_11 -> V_42 ) ;
return 0 ;
}
void F_24 ( struct V_10 * V_11 , int V_3 )
{
F_3 () ;
if ( F_25 ( V_11 -> V_2 , V_3 ) ) {
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned int V_48 , V_49 ;
V_48 = V_2 -> V_16 [ V_3 ] . V_27 ;
V_49 = F_19 ( V_11 ) ;
F_22 ( V_11 , V_49 - V_48 ) ;
V_49 = F_6 ( V_11 ) ;
F_7 ( V_11 , V_49 - 1 ) ;
}
}
static int F_26 ( struct V_1 * V_2 , int V_3 ,
struct V_50 * V_51 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_52 * V_53 ;
int V_54 ;
F_27 ( & V_11 -> V_55 ) ;
V_53 = V_51 -> V_56 ;
V_53 -> V_57 = F_28 ( V_11 -> V_58 ) ;
V_54 = F_29 ( V_11 , V_51 -> V_56 , V_51 -> V_59 ,
V_51 -> V_60 ) ;
if ( ! V_54 ) {
struct V_61 * V_62 = V_11 -> V_63 ;
T_1 V_64 = F_30 ( V_62 -> V_65 ) ;
if ( V_51 -> V_66 < V_64 )
V_64 = V_51 -> V_66 ;
memcpy ( V_51 -> V_62 , V_62 , V_64 ) ;
}
F_31 ( & V_11 -> V_55 ) ;
return V_54 ;
}
static void F_32 ( struct V_12 * V_13 )
{
F_33 ( & V_13 -> V_23 ) ;
}
static void F_34 ( struct V_12 * V_13 )
{
F_35 ( & V_13 -> V_23 ) ;
}
void F_36 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_4 * V_67 ;
int V_26 ;
if ( ! V_2 )
return;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
V_67 = F_37 ( V_13 -> V_5 ) ;
if ( ! V_67 || ! V_67 -> V_68 )
continue;
V_67 -> V_68 ( V_13 -> V_6 ) ;
}
}
void F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_4 * V_67 ;
int V_26 ;
if ( ! V_2 )
return;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
V_67 = F_37 ( V_13 -> V_5 ) ;
if ( ! V_67 || ! V_67 -> V_69 )
continue;
V_67 -> V_69 ( V_13 -> V_6 ) ;
}
}
void F_39 ( struct V_10 * V_11 , int V_70 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_4 * V_67 ;
int V_26 ;
if ( ! V_2 )
return;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
F_40 () ;
V_67 = F_41 ( V_13 -> V_5 ) ;
if ( ! V_67 || ! V_67 -> V_71 ) {
F_42 () ;
continue;
}
F_32 ( V_13 ) ;
F_42 () ;
V_67 -> V_71 ( V_13 -> V_6 , V_70 ) ;
F_34 ( V_13 ) ;
}
}
void F_43 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_4 * V_67 ;
int V_26 ;
if ( ! V_2 )
return;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
V_67 = F_37 ( V_13 -> V_5 ) ;
if ( ! V_67 || ! V_67 -> V_72 )
continue;
V_67 -> V_72 ( V_13 -> V_6 ) ;
}
}
void F_44 ( struct V_10 * V_11 , struct V_73 * V_74 )
{
T_2 V_75 = F_30 ( V_74 -> V_75 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_4 * V_67 ;
int V_26 ;
if ( ! V_2 )
return;
F_40 () ;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
V_67 = F_41 ( V_13 -> V_5 ) ;
if ( ! V_67 || ! V_67 -> V_76 )
continue;
if ( ! V_13 -> V_31 ||
V_75 > V_13 -> V_30 )
continue;
F_45 () ;
if ( F_10 ( V_75 , V_13 -> V_31 ) )
V_67 -> V_76 ( V_13 -> V_6 , V_74 ) ;
}
F_42 () ;
}
static int F_46 ( struct V_1 * V_2 , int V_3 ,
unsigned long * V_77 , T_2 V_78 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_12 * V_13 ;
if ( V_3 >= V_14 )
return - V_15 ;
V_13 = & V_2 -> V_16 [ V_3 ] ;
V_13 -> V_31 = V_77 ;
F_47 () ;
V_13 -> V_30 = V_78 ;
F_13 ( V_11 , V_77 , V_78 + 1 ) ;
return 0 ;
}
struct V_1 * F_48 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_1 * V_2 ;
V_2 = V_11 -> V_2 ;
if ( ! V_2 ) {
V_2 = F_49 ( sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return F_50 ( - V_22 ) ;
V_2 -> V_28 = & V_80 ;
if ( V_11 -> V_39 & V_81 )
V_2 -> V_39 |= V_82 ;
if ( V_11 -> V_39 & V_83 )
V_2 -> V_39 |= V_84 ;
V_2 -> V_9 = V_8 ;
V_2 -> V_85 = V_11 -> V_85 ;
V_11 -> V_2 = V_2 ;
}
return V_11 -> V_2 ;
}
