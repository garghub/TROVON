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
}
if ( V_13 -> V_27 )
F_13 ( V_11 , NULL , 0 ) ;
F_14 ( V_13 -> V_5 , NULL ) ;
F_15 () ;
V_13 -> V_27 = 0 ;
V_13 -> V_28 = NULL ;
while ( F_16 ( & V_13 -> V_23 ) != 0 && V_26 < 10 ) {
F_17 ( 100 ) ;
V_26 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_3 ,
struct V_29 * V_30 , int V_31 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
int V_32 , V_33 ;
int V_34 , V_26 , V_35 ;
F_3 () ;
if ( V_3 != V_18 )
return - V_15 ;
if ( ! ( V_11 -> V_36 & V_37 ) )
return - V_38 ;
V_33 = F_19 ( V_11 ) ;
V_32 = F_20 ( int , V_11 -> V_39 , V_33 ) ;
V_34 = V_32 - V_11 -> V_40 ;
if ( ! V_34 )
return - V_22 ;
if ( V_34 > V_31 )
V_34 = V_31 ;
V_35 = V_32 - V_34 ;
for ( V_26 = 0 ; V_26 < V_34 ; V_26 ++ ) {
V_30 [ V_26 ] . V_41 = V_11 -> V_42 [ V_35 + V_26 ] . V_41 ;
V_30 [ V_26 ] . V_43 = V_35 + V_26 ;
V_30 [ V_26 ] . V_44 = ( V_35 + V_26 ) * 0x80 ;
}
F_21 ( V_11 , V_32 - V_34 ) ;
F_22 ( V_11 , V_33 - V_34 ) ;
V_2 -> V_16 [ V_3 ] . V_45 = V_34 ;
return V_34 ;
}
static int F_23 ( struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
int V_33 , V_45 ;
F_3 () ;
if ( V_3 != V_18 )
return - V_15 ;
V_33 = F_19 ( V_11 ) ;
V_45 = V_2 -> V_16 [ V_3 ] . V_45 ;
F_22 ( V_11 , V_33 + V_45 ) ;
V_2 -> V_16 [ V_3 ] . V_45 = 0 ;
F_21 ( V_11 , V_11 -> V_39 ) ;
return 0 ;
}
void F_24 ( struct V_10 * V_11 , int V_3 )
{
F_3 () ;
if ( F_25 ( V_11 -> V_2 , V_3 ) ) {
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned int V_46 , V_47 ;
V_46 = V_2 -> V_16 [ V_3 ] . V_45 ;
V_47 = F_19 ( V_11 ) ;
F_22 ( V_11 , V_47 - V_46 ) ;
V_47 = F_6 ( V_11 ) ;
F_7 ( V_11 , V_47 - 1 ) ;
}
}
static int F_26 ( struct V_1 * V_2 , int V_3 ,
struct V_48 * V_49 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_50 * V_51 ;
int V_52 ;
F_27 ( & V_11 -> V_53 ) ;
V_51 = V_49 -> V_54 ;
V_51 -> V_55 = F_28 ( V_11 -> V_56 ) ;
V_52 = F_29 ( V_11 , V_49 -> V_54 , V_49 -> V_57 ,
V_49 -> V_58 ) ;
if ( ! V_52 ) {
struct V_59 * V_60 = V_11 -> V_61 ;
T_1 V_62 = F_30 ( V_60 -> V_63 ) ;
if ( V_49 -> V_64 < V_62 )
V_62 = V_49 -> V_64 ;
memcpy ( V_49 -> V_60 , V_60 , V_62 ) ;
}
F_31 ( & V_11 -> V_53 ) ;
return V_52 ;
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
struct V_4 * V_65 ;
int V_26 ;
if ( ! V_2 )
return;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
V_65 = F_37 ( V_13 -> V_5 ) ;
if ( ! V_65 || ! V_65 -> V_66 )
continue;
V_65 -> V_66 ( V_13 -> V_6 ) ;
}
}
void F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_4 * V_65 ;
int V_26 ;
if ( ! V_2 )
return;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
V_65 = F_37 ( V_13 -> V_5 ) ;
if ( ! V_65 || ! V_65 -> V_67 )
continue;
V_65 -> V_67 ( V_13 -> V_6 ) ;
}
}
void F_39 ( struct V_10 * V_11 , int V_68 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_4 * V_65 ;
int V_26 ;
if ( ! V_2 )
return;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
F_40 () ;
V_65 = F_41 ( V_13 -> V_5 ) ;
if ( ! V_65 || ! V_65 -> V_69 ) {
F_42 () ;
continue;
}
F_32 ( V_13 ) ;
F_42 () ;
V_65 -> V_69 ( V_13 -> V_6 , V_68 ) ;
F_34 ( V_13 ) ;
}
}
void F_43 ( struct V_10 * V_11 , struct V_70 * V_71 )
{
T_2 V_72 = F_30 ( V_71 -> V_72 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_4 * V_65 ;
int V_26 ;
if ( ! V_2 )
return;
F_40 () ;
for ( V_26 = 0 ; V_26 < V_14 ; V_26 ++ ) {
struct V_12 * V_13 = & V_2 -> V_16 [ V_26 ] ;
V_65 = F_41 ( V_13 -> V_5 ) ;
if ( ! V_65 || ! V_65 -> V_73 )
continue;
if ( ! V_13 -> V_28 ||
V_72 > V_13 -> V_27 )
continue;
F_44 () ;
if ( F_10 ( V_72 , V_13 -> V_28 ) )
V_65 -> V_73 ( V_13 -> V_6 , V_71 ) ;
}
F_42 () ;
}
static int F_45 ( struct V_1 * V_2 , int V_3 ,
unsigned long * V_74 , T_2 V_75 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_12 * V_13 ;
if ( V_3 >= V_14 )
return - V_15 ;
V_13 = & V_2 -> V_16 [ V_3 ] ;
V_13 -> V_28 = V_74 ;
F_46 () ;
V_13 -> V_27 = V_75 ;
F_13 ( V_11 , V_74 , V_75 + 1 ) ;
return 0 ;
}
struct V_1 * F_47 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_2 ( V_8 ) ;
struct V_1 * V_2 ;
V_2 = V_11 -> V_2 ;
if ( ! V_2 ) {
V_2 = F_48 ( sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return F_49 ( - V_22 ) ;
V_2 -> V_77 = & V_78 ;
if ( V_11 -> V_36 & V_79 )
V_2 -> V_36 |= V_80 ;
if ( V_11 -> V_36 & V_81 )
V_2 -> V_36 |= V_82 ;
V_2 -> V_9 = V_8 ;
V_2 -> V_83 = V_11 -> V_83 ;
V_11 -> V_2 = V_2 ;
}
return V_11 -> V_2 ;
}
