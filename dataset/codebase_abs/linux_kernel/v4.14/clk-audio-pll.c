static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
V_7 , 0 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
V_7 ,
V_7 ) ;
F_3 ( V_4 -> V_5 , V_8 ,
V_9 , V_4 -> V_10 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
V_11 |
V_12 ,
V_11 |
F_4 ( V_4 -> V_13 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
F_3 ( V_15 -> V_5 , V_8 ,
V_16 ,
F_7 ( V_15 -> V_17 , V_15 -> div ) ) ;
F_3 ( V_15 -> V_5 , V_6 ,
V_18 , V_18 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_9 ( V_2 ) ;
F_3 ( V_20 -> V_5 , V_6 ,
V_21 |
V_22 ,
V_21 |
F_10 ( V_20 -> V_23 ) ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
V_11 , 0 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
V_7 , 0 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
F_3 ( V_15 -> V_5 , V_6 ,
V_18 , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_9 ( V_2 ) ;
F_3 ( V_20 -> V_5 , V_6 ,
V_21 , 0 ) ;
}
static unsigned long F_14 ( unsigned long V_24 ,
unsigned long V_13 , unsigned long V_10 )
{
unsigned long long V_25 = ( unsigned long long ) V_24 * V_10 ;
F_15 ( L_1 , V_26 , V_25 ) ;
V_25 = F_16 ( V_25 , V_27 ) ;
F_15 ( L_1 , V_26 , V_25 ) ;
return V_24 * ( V_13 + 1 ) + V_25 ;
}
static unsigned long F_17 ( struct V_1 * V_2 ,
unsigned long V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_28 ;
V_28 = F_14 ( V_24 , V_4 -> V_13 , V_4 -> V_10 ) ;
F_15 ( L_2 , V_26 ,
V_28 , V_4 -> V_13 , ( unsigned long ) V_4 -> V_10 ) ;
return V_28 ;
}
static unsigned long F_18 ( struct V_1 * V_2 ,
unsigned long V_24 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
unsigned long V_29 = 0 ;
if ( V_15 -> V_17 && V_15 -> div )
V_29 = V_24 / ( V_15 -> V_17 * V_15 -> div ) ;
F_15 ( L_3 ,
V_26 , V_29 , V_15 -> div , V_15 -> V_17 ) ;
return V_29 ;
}
static unsigned long F_19 ( struct V_1 * V_2 ,
unsigned long V_24 )
{
struct V_19 * V_20 = F_9 ( V_2 ) ;
unsigned long V_30 = 0 ;
V_30 = V_24 / ( V_20 -> V_23 + 1 ) ;
F_15 ( L_4 , V_26 ,
V_30 , V_20 -> V_23 ) ;
return V_30 ;
}
static int F_20 ( unsigned long V_31 ,
unsigned long V_24 ,
unsigned long * V_13 ,
unsigned long * V_10 )
{
unsigned long long V_32 , V_33 ;
if ( ! V_31 )
return - V_34 ;
V_32 = V_31 ;
V_33 = F_21 ( V_32 , V_24 ) ;
if ( ! V_32 || V_32 >= V_35 )
return - V_34 ;
* V_13 = V_32 - 1 ;
V_32 = V_33 * V_27 ;
V_32 = F_16 ( V_32 , V_24 ) ;
if ( V_32 > V_9 )
return - V_34 ;
* V_10 = ( unsigned long ) V_32 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
unsigned long V_10 , V_13 ;
int V_38 ;
F_15 ( L_5 , V_26 ,
V_37 -> V_31 , V_37 -> V_39 ) ;
V_37 -> V_31 = F_23 ( V_37 -> V_31 , V_40 , V_41 ) ;
V_37 -> V_42 = F_24 ( V_37 -> V_42 , V_40 ) ;
V_37 -> V_43 = F_25 ( V_37 -> V_43 , V_41 ) ;
V_38 = F_20 ( V_37 -> V_31 , V_37 -> V_39 ,
& V_13 , & V_10 ) ;
if ( V_38 )
return V_38 ;
V_37 -> V_31 = F_14 ( V_37 -> V_39 , V_13 , V_10 ) ;
V_37 -> V_44 = F_26 ( V_2 ) ;
F_15 ( L_6 ,
V_26 , V_37 -> V_31 , V_13 , V_10 ) ;
return 0 ;
}
static long F_27 ( struct V_1 * V_2 , unsigned long V_31 ,
unsigned long * V_24 )
{
struct V_1 * V_45 = F_26 ( V_2 ) ;
long V_46 = - V_34 ;
unsigned long V_39 ;
unsigned long V_47 ;
T_1 div ;
long V_48 ;
int V_49 ;
int V_50 = - 1 ;
F_15 ( L_7 , V_26 ,
V_31 , * V_24 ) ;
for ( V_47 = 1 ; V_47 < V_51 ; V_47 ++ )
for ( div = 2 ; div <= 3 ; div ++ ) {
if ( div == 2 && V_47 % 3 == 0 )
continue;
V_39 = F_28 ( V_45 ,
V_31 * V_47 * div ) ;
V_48 = V_39 / ( div * V_47 ) ;
V_49 = abs ( V_31 - V_48 ) ;
if ( V_50 < 0 || V_50 > V_49 ) {
* V_24 = V_39 ;
V_46 = V_48 ;
V_50 = V_49 ;
}
}
F_15 ( L_8 ,
V_26 , V_46 , V_39 ) ;
return V_46 ;
}
static long F_29 ( struct V_1 * V_2 , unsigned long V_31 ,
unsigned long * V_24 )
{
struct V_1 * V_45 = F_26 ( V_2 ) ;
long V_46 = - V_34 ;
unsigned long V_39 = 0 ;
T_1 V_47 = 0 , div ;
long V_48 ;
int V_49 ;
int V_50 = - 1 ;
F_15 ( L_9 , V_26 ,
V_31 , * V_24 ) ;
for ( div = 1 ; div <= V_52 ; div ++ ) {
V_39 = F_30 ( V_45 -> V_53 , V_31 * div ) ;
V_48 = V_39 / div ;
V_49 = abs ( V_31 - V_48 ) ;
if ( V_50 < 0 || V_50 > V_49 ) {
* V_24 = V_39 ;
V_46 = V_48 ;
V_50 = V_49 ;
V_47 = div ;
}
}
F_15 ( L_10 ,
V_26 , V_46 , * V_24 , V_47 - 1 ) ;
return V_46 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_31 ,
unsigned long V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_10 , V_13 ;
int V_38 ;
F_15 ( L_5 , V_26 , V_31 ,
V_24 ) ;
if ( V_31 < V_40 || V_31 > V_41 )
return - V_34 ;
V_38 = F_20 ( V_31 , V_24 , & V_13 , & V_10 ) ;
if ( V_38 )
return V_38 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_10 = V_10 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , unsigned long V_31 ,
unsigned long V_24 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
T_2 V_54 ;
F_15 ( L_7 , V_26 ,
V_31 , V_24 ) ;
if ( ! V_31 )
return - V_34 ;
V_54 = V_24 / V_31 ;
if ( V_54 % 3 == 0 ) {
V_15 -> V_17 = V_54 / 3 ;
V_15 -> div = 3 ;
} else {
V_15 -> V_17 = V_54 / 2 ;
V_15 -> div = 2 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , unsigned long V_31 ,
unsigned long V_24 )
{
struct V_19 * V_20 = F_9 ( V_2 ) ;
if ( ! V_31 )
return - V_34 ;
F_15 ( L_9 , V_26 ,
V_31 , V_24 ) ;
V_20 -> V_23 = V_24 / V_31 - 1 ;
return 0 ;
}
static int F_34 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_1 * V_2 ,
struct V_5 * * V_59 )
{
struct V_5 * V_5 ;
const char * V_60 [ 1 ] ;
int V_38 ;
V_5 = F_35 ( F_36 ( V_56 ) ) ;
if ( F_37 ( V_5 ) )
return F_38 ( V_5 ) ;
V_58 -> V_61 = V_56 -> V_61 ;
F_39 ( V_56 , V_60 , 1 ) ;
V_58 -> V_60 = V_60 ;
V_58 -> V_62 = 1 ;
V_2 -> V_58 = V_58 ;
* V_59 = V_5 ;
V_38 = F_40 ( NULL , V_2 ) ;
if ( V_38 )
return V_38 ;
return F_41 ( V_56 , V_63 , V_2 ) ;
}
static void T_3 F_42 ( struct V_55 * V_56 )
{
struct V_3 * V_64 ;
struct V_57 V_58 = {} ;
V_64 = F_43 ( sizeof( * V_64 ) , V_65 ) ;
if ( ! V_64 )
return;
V_58 . V_66 = & V_67 ;
V_58 . V_68 = V_69 ;
if ( F_34 ( V_56 , & V_58 , & V_64 -> V_2 ,
& V_64 -> V_5 ) )
F_44 ( V_64 ) ;
}
static void T_3 F_45 ( struct V_55 * V_56 )
{
struct V_14 * V_15 ;
struct V_57 V_58 = {} ;
V_15 = F_43 ( sizeof( * V_15 ) , V_65 ) ;
if ( ! V_15 )
return;
V_58 . V_66 = & V_70 ;
V_58 . V_68 = V_69 | V_71 |
V_72 ;
if ( F_34 ( V_56 , & V_58 , & V_15 -> V_2 ,
& V_15 -> V_5 ) )
F_44 ( V_15 ) ;
}
static void T_3 F_46 ( struct V_55 * V_56 )
{
struct V_14 * V_20 ;
struct V_57 V_58 = {} ;
V_20 = F_43 ( sizeof( * V_20 ) , V_65 ) ;
if ( ! V_20 )
return;
V_58 . V_66 = & V_73 ;
V_58 . V_68 = V_69 | V_71 |
V_72 ;
if ( F_34 ( V_56 , & V_58 , & V_20 -> V_2 ,
& V_20 -> V_5 ) )
F_44 ( V_20 ) ;
}
