void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
F_3 ( & V_4 -> V_5 ) ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_8 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned int V_9 ;
F_2 ( & V_8 -> V_5 ) ;
do {
V_9 = F_5 ( & V_4 -> V_5 ) ;
V_8 -> V_6 = V_4 -> V_6 ;
V_8 -> V_7 = V_4 -> V_7 ;
} while ( F_6 ( & V_4 -> V_5 , V_9 ) );
F_3 ( & V_8 -> V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_8 ( & V_4 -> V_5 ) ;
F_1 ( V_2 ) ;
}
static struct V_10 * F_9 ( struct V_1 * V_2 ,
T_1 * V_11 )
{
struct V_12 * V_13 = F_10 ( V_2 -> V_14 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_10 * V_21 ;
T_1 V_22 ;
int V_23 ;
V_21 = F_11 ( V_2 -> V_14 , V_2 -> V_24 -> V_25 ) ;
if ( ! V_21 ) {
F_12 ( V_2 -> V_14 , L_1 ) ;
return NULL ;
}
V_22 = F_13 ( & V_20 -> V_26 , V_21 -> V_27 , V_2 -> V_24 -> V_25 ,
V_28 ) ;
V_23 = F_14 ( & V_20 -> V_26 , V_22 ) ;
if ( V_23 ) {
F_15 ( & V_20 -> V_26 , L_2 , V_23 ) ;
goto V_29;
}
* V_11 = V_22 ;
return V_21 ;
V_29:
F_16 ( V_21 ) ;
return NULL ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_12 * V_13 = F_10 ( V_2 -> V_14 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_20 ;
F_18 ( & V_20 -> V_26 , V_11 , V_2 -> V_24 -> V_25 ,
V_28 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_10 * V_21 ,
T_1 V_11 )
{
F_17 ( V_2 , V_11 ) ;
F_16 ( V_21 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 -> V_14 ) ;
struct V_30 * V_31 ;
unsigned int V_32 ;
struct V_33 V_34 ;
T_1 V_11 ;
struct V_10 * V_21 ;
int V_35 , V_36 ;
T_2 V_37 ;
V_32 = F_21 ( V_2 -> V_24 ) ;
V_36 = 0 ;
if ( V_32 > V_13 -> V_38 )
V_32 = V_13 -> V_38 ;
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
V_21 = F_9 ( V_2 , & V_11 ) ;
if ( ! V_21 ) {
F_12 ( V_2 -> V_14 , L_3 ) ;
V_36 = 1 ;
goto V_39;
}
F_22 ( & V_34 , V_11 , V_21 -> V_40 ) ;
V_31 = F_23 ( V_2 -> V_24 , V_41 ,
& V_37 ) ;
if ( ! V_31 ) {
F_19 ( V_2 , V_21 , V_11 ) ;
V_36 = 1 ;
goto V_39;
}
F_24 ( V_2 -> V_24 , V_37 , V_31 , & V_34 ) ;
F_25 ( V_2 -> V_24 , V_37 , V_31 , V_21 ) ;
}
V_39:
if ( V_35 ) {
F_26 () ;
F_27 ( V_2 -> V_24 , V_37 ) ;
}
if ( V_36 )
F_28 ( & V_2 -> V_42 ) ;
return V_35 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_43 * V_24 = V_2 -> V_24 ;
struct V_44 * V_45 ;
struct V_33 V_34 ;
T_2 V_46 ;
while ( ( V_45 = F_30 ( V_24 -> V_47 , V_41 , & V_46 ) ) ) {
if ( F_31 ( V_45 ) )
break;
F_32 ( V_24 , & V_45 -> V_31 , V_46 , & V_34 ) ;
F_33 ( V_24 -> V_47 , V_41 ) ;
F_19 ( V_2 , V_24 -> V_48 [ V_46 ] , F_34 ( & V_34 ) ) ;
}
}
static void F_35 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
( void ) F_20 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_10 * V_49 ,
unsigned int V_50 , T_2 V_46 )
{
struct V_10 * V_21 , * V_51 = V_49 ;
struct V_30 * V_31 ;
unsigned int V_52 ;
struct V_33 V_34 ;
int V_53 = 0 ;
while ( V_50 > 0 ) {
V_31 = F_37 ( V_2 -> V_24 , V_41 ,
& V_21 , & V_46 ) ;
V_53 ++ ;
F_32 ( V_2 -> V_24 , V_31 , V_46 , & V_34 ) ;
F_17 ( V_2 , F_34 ( & V_34 ) ) ;
F_38 ( V_21 -> V_27 ) ;
V_52 = ( V_50 > V_54 ) ? V_54 :
V_50 ;
V_50 -= V_52 ;
F_39 ( V_21 , V_52 ) ;
if ( V_51 == V_49 )
F_40 ( V_49 ) -> V_55 = V_21 ;
else
V_51 -> V_56 = V_21 ;
V_49 -> V_40 += V_21 -> V_40 ;
V_49 -> V_57 += V_21 -> V_40 ;
V_49 -> V_58 += V_21 -> V_58 ;
V_51 = V_21 ;
}
return V_53 ;
}
static int F_41 ( struct V_1 * V_2 , int V_59 )
{
struct V_60 * V_61 = F_42 ( V_2 -> V_24 , struct V_60 , V_24 ) ;
T_3 V_62 = 0 , V_63 = 0 ;
struct V_30 * V_31 ;
int V_53 , V_6 = 0 ;
struct V_33 V_34 ;
struct V_10 * V_21 ;
T_2 V_46 ;
while ( V_6 < V_59 ) {
V_53 = 0 ;
V_31 = F_43 ( V_2 -> V_24 , V_41 , & V_21 ,
& V_46 ) ;
if ( ! V_31 )
break;
F_32 ( V_2 -> V_24 , V_31 , V_46 , & V_34 ) ;
F_17 ( V_2 , F_34 ( & V_34 ) ) ;
F_38 ( V_21 -> V_27 ) ;
V_62 = V_34 . V_40 ;
if ( V_62 <= V_54 ) {
F_39 ( V_21 , V_62 ) ;
} else {
F_39 ( V_21 , V_54 ) ;
V_53 = F_36 ( V_2 , V_21 , V_62 -
V_54 , V_46 ) ;
}
F_44 ( V_2 -> V_24 , V_46 ,
( V_53 + 1 ) * V_41 ) ;
F_45 ( V_21 , V_61 -> V_64 ) ;
V_21 -> V_65 = F_46 ( V_21 , V_2 -> V_14 ) ;
F_47 ( & V_2 -> V_66 , V_21 ) ;
V_6 ++ ;
V_63 += V_62 ;
}
if ( V_6 )
F_28 ( & V_2 -> V_42 ) ;
F_2 ( & V_2 -> V_4 . V_5 ) ;
V_2 -> V_4 . V_6 += V_6 ;
V_2 -> V_4 . V_7 += V_63 ;
F_3 ( & V_2 -> V_4 . V_5 ) ;
return V_6 ;
}
static int F_48 ( struct V_67 * V_66 , int V_59 )
{
struct V_1 * V_2 = F_42 ( V_66 , struct V_1 , V_66 ) ;
struct V_43 * V_24 = V_2 -> V_24 ;
int V_6 ;
V_6 = F_41 ( V_2 , V_59 ) ;
if ( V_6 >= V_59 )
return V_59 ;
F_49 ( V_66 ) ;
F_50 ( V_24 -> V_68 ) ;
return V_6 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 -> V_14 ) ;
F_52 ( V_2 -> V_14 , & V_2 -> V_66 , F_48 , V_13 -> V_38 ) ;
F_53 ( & V_2 -> V_66 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_66 ) ;
F_56 ( & V_2 -> V_66 ) ;
}
static T_4 F_57 ( int V_68 , void * V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_43 * V_24 = V_2 -> V_24 ;
struct V_12 * V_13 ;
F_58 ( V_24 -> V_68 ) ;
V_13 = F_10 ( V_2 -> V_14 ) ;
F_59 ( V_13 -> V_16 , V_24 -> V_69 ) ;
F_60 ( & V_2 -> V_66 ) ;
return V_70 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 -> V_14 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
struct V_43 * V_24 = V_2 -> V_24 ;
int V_23 ;
F_51 ( V_2 ) ;
F_62 ( V_16 , V_24 -> V_69 ,
V_71 , V_72 ,
V_73 , V_74 ,
V_75 ) ;
V_23 = F_63 ( V_24 -> V_68 , F_57 , 0 , V_2 -> V_76 , V_2 ) ;
if ( V_23 ) {
F_54 ( V_2 ) ;
return V_23 ;
}
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_43 * V_24 = V_2 -> V_24 ;
F_65 ( V_24 -> V_68 , V_2 ) ;
F_54 ( V_2 ) ;
}
int F_66 ( struct V_1 * V_2 , struct V_43 * V_24 ,
struct V_77 * V_14 )
{
struct V_60 * V_61 = F_42 ( V_24 , struct V_60 , V_24 ) ;
int V_23 , V_6 , V_78 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_24 = V_24 ;
F_7 ( V_2 ) ;
V_78 = snprintf ( NULL , 0 , L_4 , V_61 -> V_64 ) + 1 ;
V_2 -> V_76 = F_67 ( & V_14 -> V_26 , V_78 , V_79 ) ;
if ( ! V_2 -> V_76 )
return - V_80 ;
sprintf ( V_2 -> V_76 , L_4 , V_61 -> V_64 ) ;
F_68 ( & V_2 -> V_42 , F_35 , ( unsigned long ) V_2 ) ;
V_6 = F_20 ( V_2 ) ;
if ( ! V_6 ) {
V_23 = - V_80 ;
goto V_81;
}
V_23 = F_61 ( V_2 ) ;
if ( V_23 ) {
F_12 ( V_14 , L_5 ) ;
goto V_82;
}
return 0 ;
V_82:
V_81:
F_69 ( & V_2 -> V_42 ) ;
F_29 ( V_2 ) ;
F_70 ( & V_14 -> V_26 , V_2 -> V_76 ) ;
return V_23 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_77 * V_14 = V_2 -> V_14 ;
F_64 ( V_2 ) ;
F_69 ( & V_2 -> V_42 ) ;
F_29 ( V_2 ) ;
F_70 ( & V_14 -> V_26 , V_2 -> V_76 ) ;
}
