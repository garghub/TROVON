static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_7 , & V_3 , 1 ) ;
V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_7 , & V_3 , 1 ) ;
return V_3 ;
}
static void F_2 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
T_1 V_11 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_11 = V_12 ;
V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_13 , & V_11 , 1 ) ;
}
static T_1 F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
T_1 V_11 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_13 , & V_11 , 1 ) ;
return V_11 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
T_1 V_11 ;
T_1 V_14 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_14 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_15 , & V_11 , 1 ) ;
if ( V_14 && ( V_11 &
( V_16 | V_17 ) ) ==
( V_16 | V_17 ) )
return V_10 -> V_18 . V_19 ;
return - V_20 ;
}
static int F_6 ( struct V_9 * V_10 )
{
unsigned long V_21 ;
long V_22 ;
struct V_1 * V_2 ;
T_1 V_11 ;
if ( F_5 ( V_10 ) == V_10 -> V_18 . V_19 )
return V_10 -> V_18 . V_19 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_11 = V_23 ;
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_15 , & V_11 , 1 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = V_24 + V_10 -> V_18 . V_25 ;
do {
if ( F_5 ( V_10 ) >= 0 )
return V_10 -> V_18 . V_19 ;
F_7 ( V_26 ) ;
} while ( F_8 ( V_24 , V_21 ) );
return - V_20 ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
T_1 V_11 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_11 = V_16 ;
V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_15 , & V_11 , 1 ) ;
}
static int F_10 ( struct V_9 * V_10 )
{
unsigned long V_21 ;
int V_27 , V_14 ;
T_1 V_28 , V_29 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_21 = V_24 + V_10 -> V_18 . V_30 ;
do {
V_28 = V_13 + 1 ;
V_14 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_28 , & V_29 , 1 ) ;
if ( V_14 < 0 )
return - V_31 ;
V_28 = V_13 + 2 ;
V_27 = V_29 ;
V_14 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_28 , & V_29 , 1 ) ;
if ( V_14 < 0 )
return - V_31 ;
V_27 |= V_29 << 8 ;
if ( V_27 )
return V_27 ;
F_7 ( V_26 ) ;
} while ( F_8 ( V_24 , V_21 ) );
return - V_31 ;
}
static bool F_11 ( struct V_9 * V_10 , T_1 V_32 ,
bool V_33 , bool * V_34 )
{
T_1 V_14 = V_10 -> V_4 -> V_14 ( V_10 ) ;
* V_34 = false ;
if ( ( V_14 & V_32 ) == V_32 )
return true ;
if ( V_33 && V_10 -> V_4 -> V_35 ( V_10 , V_14 ) ) {
* V_34 = true ;
return true ;
}
return false ;
}
static int F_12 ( struct V_9 * V_10 , T_1 V_32 , unsigned long V_36 ,
T_2 * V_37 , bool V_33 )
{
unsigned long V_21 ;
int V_22 = 0 ;
bool V_34 = false ;
bool V_38 ;
T_3 V_39 ;
T_1 V_14 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_14 = F_4 ( V_10 ) ;
if ( ( V_14 & V_32 ) == V_32 )
return 0 ;
V_21 = V_24 + V_36 ;
if ( V_10 -> V_18 . V_40 ) {
V_39 = V_2 -> V_41 ;
F_1 ( V_2 ) ;
F_13 ( V_10 -> V_18 . V_40 ) ;
do {
if ( V_22 == - V_42 && F_14 ( V_43 ) )
F_15 ( V_44 ) ;
V_36 = V_21 - V_24 ;
if ( ( long ) V_36 <= 0 )
return - 1 ;
V_22 = F_16 ( * V_37 ,
V_39 != V_2 -> V_41 ,
V_36 ) ;
F_1 ( V_2 ) ;
V_38 = F_11 ( V_10 , V_32 ,
V_33 , & V_34 ) ;
if ( V_22 >= 0 && V_38 ) {
if ( V_34 )
return - V_45 ;
return 0 ;
}
} while ( V_22 == - V_42 && F_14 ( V_43 ) );
F_17 ( V_10 -> V_18 . V_40 ) ;
} else {
do {
F_7 ( V_26 ) ;
V_14 = V_10 -> V_4 -> V_14 ( V_10 ) ;
if ( ( V_14 & V_32 ) == V_32 )
return 0 ;
} while ( F_8 ( V_24 , V_21 ) );
}
return - V_46 ;
}
static int F_18 ( struct V_9 * V_10 , T_1 * V_47 , T_4 V_48 )
{
int V_49 = 0 , V_27 , V_50 , V_22 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
while ( V_49 < V_48 &&
F_12 ( V_10 ,
V_51 | V_52 ,
V_10 -> V_18 . V_53 ,
& V_10 -> V_18 . V_54 , true ) == 0 ) {
V_27 = F_10 ( V_10 ) ;
if ( V_27 < 0 )
return V_27 ;
V_50 = F_19 ( int , V_27 , V_48 - V_49 ) ;
V_22 = V_2 -> V_4 -> V_5 ( V_2 -> V_6 , V_55 ,
V_47 + V_49 , V_50 ) ;
if ( V_22 < 0 )
return V_22 ;
V_49 += V_50 ;
}
return V_49 ;
}
static T_5 F_20 ( int V_40 , void * V_56 )
{
struct V_9 * V_10 = V_56 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_2 -> V_41 ++ ;
F_21 ( & V_10 -> V_18 . V_54 ) ;
F_17 ( V_10 -> V_18 . V_40 ) ;
return V_57 ;
}
static int F_22 ( struct V_9 * V_10 , unsigned char * V_47 ,
T_4 V_50 )
{
T_3 V_14 , V_58 , V_49 , V_59 ;
int V_27 = 0 ;
int V_22 ;
T_1 V_11 ;
struct V_1 * V_2 ;
if ( ! V_10 )
return - V_31 ;
if ( V_50 < V_60 )
return - V_31 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_22 = F_6 ( V_10 ) ;
if ( V_22 < 0 )
return V_22 ;
V_14 = F_4 ( V_10 ) ;
if ( ( V_14 & V_12 ) == 0 ) {
F_2 ( V_10 ) ;
if ( F_12
( V_10 , V_12 , V_10 -> V_18 . V_61 ,
& V_10 -> V_18 . V_54 , false ) < 0 ) {
V_22 = - V_46 ;
goto V_62;
}
}
for ( V_58 = 0 ; V_58 < V_50 - 1 ; ) {
V_27 = F_10 ( V_10 ) ;
if ( V_27 < 0 )
return V_27 ;
V_49 = F_19 ( int , V_50 - V_58 - 1 , V_27 ) ;
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_55 ,
V_47 + V_58 , V_49 ) ;
if ( V_22 < 0 )
goto V_62;
V_58 += V_49 ;
}
V_14 = F_4 ( V_10 ) ;
if ( ( V_14 & V_63 ) == 0 ) {
V_22 = - V_64 ;
goto V_62;
}
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_55 ,
V_47 + V_50 - 1 , 1 ) ;
if ( V_22 < 0 )
goto V_62;
V_14 = F_4 ( V_10 ) ;
if ( ( V_14 & V_63 ) != 0 ) {
V_22 = - V_64 ;
goto V_62;
}
V_11 = V_65 ;
V_22 = V_2 -> V_4 -> V_8 ( V_2 -> V_6 , V_13 , & V_11 , 1 ) ;
if ( V_22 < 0 )
goto V_62;
if ( V_10 -> V_18 . V_40 ) {
V_59 = F_23 ( * ( ( V_66 * ) ( V_47 + 6 ) ) ) ;
V_22 = F_12 ( V_10 , V_51 | V_52 ,
F_24 ( V_10 , V_59 ) ,
& V_10 -> V_18 . V_54 , false ) ;
if ( V_22 < 0 )
goto V_62;
}
return V_50 ;
V_62:
F_2 ( V_10 ) ;
F_9 ( V_10 ) ;
return V_22 ;
}
static int F_25 ( struct V_9 * V_10 , unsigned char * V_47 ,
T_4 V_48 )
{
int V_49 = 0 ;
int V_67 ;
if ( ! V_10 )
return - V_31 ;
if ( V_48 < V_60 ) {
V_49 = - V_64 ;
goto V_68;
}
V_49 = F_18 ( V_10 , V_47 , V_60 ) ;
if ( V_49 < V_60 ) {
F_26 ( & V_10 -> V_69 , L_1 ) ;
goto V_68;
}
V_67 = F_23 ( * ( V_66 * ) ( V_47 + 2 ) ) ;
if ( V_67 > V_48 ) {
V_49 = - V_64 ;
goto V_68;
}
V_49 += F_18 ( V_10 , & V_47 [ V_60 ] ,
V_67 - V_60 ) ;
if ( V_49 < V_67 ) {
F_26 ( & V_10 -> V_69 , L_2 ) ;
V_49 = - V_46 ;
}
V_68:
F_2 ( V_10 ) ;
F_9 ( V_10 ) ;
return V_49 ;
}
static bool F_27 ( struct V_9 * V_10 , T_1 V_14 )
{
return ( V_14 == V_12 ) ;
}
int F_28 ( void * V_6 , const struct V_70 * V_4 ,
struct V_71 * V_69 , int V_40 , int V_72 )
{
int V_22 ;
T_1 V_73 = 0 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_29 ( V_69 , & V_74 ) ;
if ( F_30 ( V_10 ) )
return F_31 ( V_10 ) ;
V_2 = F_32 ( V_69 , sizeof( struct V_1 ) ,
V_75 ) ;
if ( ! V_2 )
return - V_76 ;
F_3 ( V_10 ) = V_2 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = V_4 ;
V_10 -> V_18 . V_25 = F_33 ( V_77 ) ;
V_10 -> V_18 . V_61 = F_33 ( V_78 ) ;
V_10 -> V_18 . V_53 = F_33 ( V_77 ) ;
V_10 -> V_18 . V_30 = F_33 ( V_77 ) ;
V_10 -> V_18 . V_19 = V_79 ;
if ( V_40 ) {
F_34 ( & V_10 -> V_18 . V_54 ) ;
V_2 -> V_41 = 0 ;
if ( F_6 ( V_10 ) != V_79 ) {
V_22 = - V_80 ;
goto V_81;
}
F_1 ( V_2 ) ;
V_22 = F_35 ( V_69 , V_40 , F_20 ,
V_82 , L_3 ,
V_10 ) ;
if ( V_22 < 0 ) {
F_26 ( & V_10 -> V_69 , L_4 ,
V_40 ) ;
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
V_10 -> V_18 . V_40 = V_40 ;
F_17 ( V_10 -> V_18 . V_40 ) ;
F_36 ( V_10 ) ;
}
F_37 ( V_10 ) ;
F_38 ( V_10 ) ;
return F_39 ( V_10 ) ;
V_81:
F_40 ( & V_10 -> V_69 , L_5 ) ;
return V_22 ;
}
int F_41 ( struct V_9 * V_10 )
{
F_42 ( V_10 ) ;
return 0 ;
}
int F_43 ( struct V_71 * V_69 )
{
struct V_9 * V_10 = F_44 ( V_69 ) ;
struct V_1 * V_2 ;
int V_22 = 0 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
if ( F_45 ( V_2 -> V_72 ) )
F_46 ( V_2 -> V_72 , 0 ) ;
else
V_22 = F_47 ( V_69 ) ;
return V_22 ;
}
int F_48 ( struct V_71 * V_69 )
{
struct V_9 * V_10 = F_44 ( V_69 ) ;
struct V_1 * V_2 ;
int V_22 = 0 ;
V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
if ( F_45 ( V_2 -> V_72 ) ) {
F_46 ( V_2 -> V_72 , 1 ) ;
V_22 = F_12 ( V_10 ,
V_52 , V_10 -> V_18 . V_61 ,
& V_10 -> V_18 . V_54 , false ) ;
} else {
V_22 = F_49 ( V_69 ) ;
if ( ! V_22 )
F_38 ( V_10 ) ;
}
return V_22 ;
}
