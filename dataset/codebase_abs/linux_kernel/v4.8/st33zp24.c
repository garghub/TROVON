static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_7 , & V_3 , 1 ) ;
V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_7 , & V_3 , 1 ) ;
return V_3 ;
}
static void F_2 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
T_1 V_12 ;
V_12 = V_13 ;
V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_14 , & V_12 , 1 ) ;
}
static T_1 F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
T_1 V_12 ;
V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_14 , & V_12 , 1 ) ;
return V_12 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
T_1 V_12 ;
T_1 V_15 ;
V_15 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_16 , & V_12 , 1 ) ;
if ( V_15 && ( V_12 &
( V_17 | V_18 ) ) ==
( V_17 | V_18 ) )
return V_2 -> V_19 ;
return - V_20 ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
unsigned long V_21 ;
long V_22 ;
T_1 V_12 ;
if ( F_5 ( V_10 ) == V_2 -> V_19 )
return V_2 -> V_19 ;
V_12 = V_23 ;
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_16 , & V_12 , 1 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = V_24 + V_10 -> V_25 ;
do {
if ( F_5 ( V_10 ) >= 0 )
return V_2 -> V_19 ;
F_7 ( V_26 ) ;
} while ( F_8 ( V_24 , V_21 ) );
return - V_20 ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
T_1 V_12 ;
V_12 = V_17 ;
V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_16 , & V_12 , 1 ) ;
}
static int F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
unsigned long V_21 ;
int V_27 , V_15 ;
T_1 V_28 ;
V_21 = V_24 + V_10 -> V_29 ;
do {
V_15 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_14 + 1 ,
& V_28 , 1 ) ;
if ( V_15 < 0 )
return - V_30 ;
V_27 = V_28 ;
V_15 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_14 + 2 ,
& V_28 , 1 ) ;
if ( V_15 < 0 )
return - V_30 ;
V_27 |= V_28 << 8 ;
if ( V_27 )
return V_27 ;
F_7 ( V_26 ) ;
} while ( F_8 ( V_24 , V_21 ) );
return - V_30 ;
}
static bool F_11 ( struct V_9 * V_10 , T_1 V_31 ,
bool V_32 , bool * V_33 )
{
T_1 V_15 = V_10 -> V_4 -> V_15 ( V_10 ) ;
* V_33 = false ;
if ( ( V_15 & V_31 ) == V_31 )
return true ;
if ( V_32 && V_10 -> V_4 -> V_34 ( V_10 , V_15 ) ) {
* V_33 = true ;
return true ;
}
return false ;
}
static int F_12 ( struct V_9 * V_10 , T_1 V_31 , unsigned long V_35 ,
T_2 * V_36 , bool V_32 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
unsigned long V_21 ;
int V_22 = 0 ;
bool V_33 = false ;
bool V_37 ;
T_3 V_38 ;
T_1 V_15 ;
V_15 = F_4 ( V_10 ) ;
if ( ( V_15 & V_31 ) == V_31 )
return 0 ;
V_21 = V_24 + V_35 ;
if ( V_10 -> V_39 & V_40 ) {
V_38 = V_2 -> V_41 ;
F_1 ( V_2 ) ;
F_13 ( V_2 -> V_42 ) ;
do {
if ( V_22 == - V_43 && F_14 ( V_44 ) )
F_15 ( V_45 ) ;
V_35 = V_21 - V_24 ;
if ( ( long ) V_35 <= 0 )
return - 1 ;
V_22 = F_16 ( * V_36 ,
V_38 != V_2 -> V_41 ,
V_35 ) ;
F_1 ( V_2 ) ;
V_37 = F_11 ( V_10 , V_31 ,
V_32 , & V_33 ) ;
if ( V_22 >= 0 && V_37 ) {
if ( V_33 )
return - V_46 ;
return 0 ;
}
} while ( V_22 == - V_43 && F_14 ( V_44 ) );
F_17 ( V_2 -> V_42 ) ;
} else {
do {
F_7 ( V_26 ) ;
V_15 = V_10 -> V_4 -> V_15 ( V_10 ) ;
if ( ( V_15 & V_31 ) == V_31 )
return 0 ;
} while ( F_8 ( V_24 , V_21 ) );
}
return - V_47 ;
}
static int F_18 ( struct V_9 * V_10 , T_1 * V_48 , T_4 V_49 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
int V_50 = 0 , V_27 , V_51 , V_22 ;
while ( V_50 < V_49 &&
F_12 ( V_10 ,
V_52 | V_53 ,
V_10 -> V_54 ,
& V_2 -> V_55 , true ) == 0 ) {
V_27 = F_10 ( V_10 ) ;
if ( V_27 < 0 )
return V_27 ;
V_51 = F_19 ( int , V_27 , V_49 - V_50 ) ;
V_22 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_56 ,
V_48 + V_50 , V_51 ) ;
if ( V_22 < 0 )
return V_22 ;
V_50 += V_51 ;
}
return V_50 ;
}
static T_5 F_20 ( int V_42 , void * V_57 )
{
struct V_9 * V_10 = V_57 ;
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
V_2 -> V_41 ++ ;
F_21 ( & V_2 -> V_55 ) ;
F_17 ( V_2 -> V_42 ) ;
return V_58 ;
}
static int F_22 ( struct V_9 * V_10 , unsigned char * V_48 ,
T_4 V_51 )
{
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
T_3 V_15 , V_59 , V_50 , V_60 ;
int V_27 = 0 ;
int V_22 ;
T_1 V_12 ;
if ( ! V_10 )
return - V_30 ;
if ( V_51 < V_61 )
return - V_30 ;
V_22 = F_6 ( V_10 ) ;
if ( V_22 < 0 )
return V_22 ;
V_15 = F_4 ( V_10 ) ;
if ( ( V_15 & V_13 ) == 0 ) {
F_2 ( V_10 ) ;
if ( F_12
( V_10 , V_13 , V_10 -> V_62 ,
& V_2 -> V_55 , false ) < 0 ) {
V_22 = - V_47 ;
goto V_63;
}
}
for ( V_59 = 0 ; V_59 < V_51 - 1 ; ) {
V_27 = F_10 ( V_10 ) ;
if ( V_27 < 0 )
return V_27 ;
V_50 = F_19 ( int , V_51 - V_59 - 1 , V_27 ) ;
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_56 ,
V_48 + V_59 , V_50 ) ;
if ( V_22 < 0 )
goto V_63;
V_59 += V_50 ;
}
V_15 = F_4 ( V_10 ) ;
if ( ( V_15 & V_64 ) == 0 ) {
V_22 = - V_65 ;
goto V_63;
}
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_56 ,
V_48 + V_51 - 1 , 1 ) ;
if ( V_22 < 0 )
goto V_63;
V_15 = F_4 ( V_10 ) ;
if ( ( V_15 & V_64 ) != 0 ) {
V_22 = - V_65 ;
goto V_63;
}
V_12 = V_66 ;
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_14 , & V_12 , 1 ) ;
if ( V_22 < 0 )
goto V_63;
if ( V_10 -> V_39 & V_40 ) {
V_60 = F_23 ( * ( ( V_67 * ) ( V_48 + 6 ) ) ) ;
V_22 = F_12 ( V_10 , V_52 | V_53 ,
F_24 ( V_10 , V_60 ) ,
& V_2 -> V_55 , false ) ;
if ( V_22 < 0 )
goto V_63;
}
return V_51 ;
V_63:
F_2 ( V_10 ) ;
F_9 ( V_10 ) ;
return V_22 ;
}
static int F_25 ( struct V_9 * V_10 , unsigned char * V_48 ,
T_4 V_49 )
{
int V_50 = 0 ;
int V_68 ;
if ( ! V_10 )
return - V_30 ;
if ( V_49 < V_61 ) {
V_50 = - V_65 ;
goto V_69;
}
V_50 = F_18 ( V_10 , V_48 , V_61 ) ;
if ( V_50 < V_61 ) {
F_26 ( & V_10 -> V_11 , L_1 ) ;
goto V_69;
}
V_68 = F_23 ( * ( V_67 * ) ( V_48 + 2 ) ) ;
if ( V_68 > V_49 ) {
V_50 = - V_65 ;
goto V_69;
}
V_50 += F_18 ( V_10 , & V_48 [ V_61 ] ,
V_68 - V_61 ) ;
if ( V_50 < V_68 ) {
F_26 ( & V_10 -> V_11 , L_2 ) ;
V_50 = - V_47 ;
}
V_69:
F_2 ( V_10 ) ;
F_9 ( V_10 ) ;
return V_50 ;
}
static bool F_27 ( struct V_9 * V_10 , T_1 V_15 )
{
return ( V_15 == V_13 ) ;
}
int F_28 ( void * V_6 , const struct V_70 * V_4 ,
struct V_71 * V_11 , int V_42 , int V_72 )
{
int V_22 ;
T_1 V_73 = 0 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_29 ( V_11 , & V_74 ) ;
if ( F_30 ( V_10 ) )
return F_31 ( V_10 ) ;
V_2 = F_32 ( V_11 , sizeof( struct V_1 ) ,
V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = V_4 ;
F_33 ( & V_10 -> V_11 , V_2 ) ;
V_10 -> V_25 = F_34 ( V_77 ) ;
V_10 -> V_62 = F_34 ( V_78 ) ;
V_10 -> V_54 = F_34 ( V_77 ) ;
V_10 -> V_29 = F_34 ( V_77 ) ;
V_2 -> V_19 = V_79 ;
if ( V_42 ) {
F_35 ( & V_2 -> V_55 ) ;
V_2 -> V_41 = 0 ;
if ( F_6 ( V_10 ) != V_79 ) {
V_22 = - V_80 ;
goto V_81;
}
F_1 ( V_2 ) ;
V_22 = F_36 ( V_11 , V_42 , F_20 ,
V_82 , L_3 ,
V_10 ) ;
if ( V_22 < 0 ) {
F_26 ( & V_10 -> V_11 , L_4 ,
V_42 ) ;
goto V_81;
}
V_73 |= V_83
| V_84
| V_85 ;
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_86 ,
& V_73 , 1 ) ;
if ( V_22 < 0 )
goto V_81;
V_73 = V_87 ;
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , ( V_86 + 3 ) ,
& V_73 , 1 ) ;
if ( V_22 < 0 )
goto V_81;
V_2 -> V_42 = V_42 ;
V_10 -> V_39 |= V_40 ;
F_17 ( V_2 -> V_42 ) ;
F_37 ( V_10 ) ;
}
return F_38 ( V_10 ) ;
V_81:
F_39 ( & V_10 -> V_11 , L_5 ) ;
return V_22 ;
}
int F_40 ( struct V_9 * V_10 )
{
F_41 ( V_10 ) ;
return 0 ;
}
int F_42 ( struct V_71 * V_11 )
{
struct V_9 * V_10 = F_3 ( V_11 ) ;
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
int V_22 = 0 ;
if ( F_43 ( V_2 -> V_72 ) )
F_44 ( V_2 -> V_72 , 0 ) ;
else
V_22 = F_45 ( V_11 ) ;
return V_22 ;
}
int F_46 ( struct V_71 * V_11 )
{
struct V_9 * V_10 = F_3 ( V_11 ) ;
struct V_1 * V_2 = F_3 ( & V_10 -> V_11 ) ;
int V_22 = 0 ;
if ( F_43 ( V_2 -> V_72 ) ) {
F_44 ( V_2 -> V_72 , 1 ) ;
V_22 = F_12 ( V_10 ,
V_53 , V_10 -> V_62 ,
& V_2 -> V_55 , false ) ;
} else {
V_22 = F_47 ( V_11 ) ;
if ( ! V_22 )
F_48 ( V_10 ) ;
}
return V_22 ;
}
