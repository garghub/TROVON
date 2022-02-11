static inline T_1 F_1 ( unsigned int V_1 ,
T_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
T_1 V_5 ;
V_4 = F_2 ( F_3 () ) ;
V_5 = F_4 ( F_5 ( V_1 ) . V_6 . V_7 ,
F_5 ( V_1 ) . V_6 . system ) ;
V_5 = F_4 ( V_5 , F_5 ( V_1 ) . V_6 . V_8 ) ;
V_5 = F_4 ( V_5 , F_5 ( V_1 ) . V_6 . V_9 ) ;
V_5 = F_4 ( V_5 , F_5 ( V_1 ) . V_6 . V_10 ) ;
V_5 = F_4 ( V_5 , F_5 ( V_1 ) . V_6 . V_11 ) ;
V_3 = F_6 ( V_4 , V_5 ) ;
if ( V_2 )
* V_2 = ( T_1 ) F_7 ( V_4 ) ;
return ( T_1 ) F_7 ( V_3 ) ;
}
static inline T_1 F_8 ( unsigned int V_1 , T_1 * V_2 )
{
T_2 V_3 = F_9 ( V_1 , NULL ) ;
if ( V_3 == - 1ULL )
return F_1 ( V_1 , V_2 ) ;
else
V_3 += F_10 ( V_1 , V_2 ) ;
return V_3 ;
}
static int
F_11 ( struct V_12 * V_13 , unsigned long V_14 ,
void * V_15 )
{
struct V_16 * V_17 = V_15 ;
struct V_18 * V_19 = & F_12 ( V_20 ,
V_17 -> V_1 ) ;
struct V_21 * V_22 ;
if ( ! V_19 -> V_23 )
return 0 ;
V_22 = V_19 -> V_24 ;
if ( V_19 -> V_25 > V_22 -> V_26
|| V_19 -> V_25 < V_22 -> V_27 )
V_19 -> V_25 = V_17 -> V_28 ;
return 0 ;
}
static T_3 F_13 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_33 )
{
return sprintf ( V_33 , L_1 , V_34 ) ;
}
static T_3 F_14 ( struct V_29 * V_35 ,
struct V_31 * V_36 ,
const char * V_33 , T_4 V_37 )
{
unsigned int V_38 ;
int V_39 ;
V_39 = sscanf ( V_33 , L_2 , & V_38 ) ;
if ( V_39 != 1 || V_38 > V_40 || V_38 < 1 )
return - V_41 ;
V_42 . V_43 = V_38 ;
return V_37 ;
}
static T_3 F_15 ( struct V_29 * V_35 , struct V_31 * V_36 ,
const char * V_33 , T_4 V_37 )
{
unsigned int V_38 ;
int V_39 ;
V_39 = sscanf ( V_33 , L_2 , & V_38 ) ;
if ( V_39 != 1 )
return - V_41 ;
V_42 . V_44 = V_26 ( V_38 , V_34 ) ;
return V_37 ;
}
static T_3 F_16 ( struct V_29 * V_35 , struct V_31 * V_36 ,
const char * V_33 , T_4 V_37 )
{
unsigned int V_38 ;
int V_39 ;
V_39 = sscanf ( V_33 , L_2 , & V_38 ) ;
if ( V_39 != 1 || V_38 > 100 ||
V_38 <= V_42 . V_45 )
return - V_41 ;
V_42 . V_46 = V_38 ;
return V_37 ;
}
static T_3 F_17 ( struct V_29 * V_35 , struct V_31 * V_36 ,
const char * V_33 , T_4 V_37 )
{
unsigned int V_38 ;
int V_39 ;
V_39 = sscanf ( V_33 , L_2 , & V_38 ) ;
if ( V_39 != 1 || V_38 < 11 || V_38 > 100 ||
V_38 >= V_42 . V_46 )
return - V_41 ;
V_42 . V_45 = V_38 ;
return V_37 ;
}
static T_3 F_18 ( struct V_29 * V_35 , struct V_31 * V_36 ,
const char * V_33 , T_4 V_37 )
{
unsigned int V_38 ;
int V_39 ;
unsigned int V_47 ;
V_39 = sscanf ( V_33 , L_2 , & V_38 ) ;
if ( V_39 != 1 )
return - V_41 ;
if ( V_38 > 1 )
V_38 = 1 ;
if ( V_38 == V_42 . V_48 )
return V_37 ;
V_42 . V_48 = V_38 ;
F_19 (j) {
struct V_18 * V_49 ;
V_49 = & F_12 ( V_20 , V_47 ) ;
V_49 -> V_50 = F_8 ( V_47 ,
& V_49 -> V_51 ) ;
if ( V_42 . V_48 )
V_49 -> V_52 = F_5 ( V_47 ) . V_6 . V_11 ;
}
return V_37 ;
}
static T_3 F_20 ( struct V_29 * V_35 , struct V_31 * V_36 ,
const char * V_33 , T_4 V_37 )
{
unsigned int V_38 ;
int V_39 ;
V_39 = sscanf ( V_33 , L_2 , & V_38 ) ;
if ( V_39 != 1 )
return - V_41 ;
if ( V_38 > 100 )
V_38 = 100 ;
V_42 . V_53 = V_38 ;
return V_37 ;
}
static void F_21 ( struct V_18 * V_19 )
{
unsigned int V_54 = 0 ;
unsigned int V_55 = 0 ;
unsigned int V_56 ;
struct V_21 * V_22 ;
unsigned int V_47 ;
V_22 = V_19 -> V_24 ;
F_22 (j, policy->cpus) {
struct V_18 * V_57 ;
T_1 V_4 , V_58 ;
unsigned int V_3 , V_59 ;
V_57 = & F_12 ( V_20 , V_47 ) ;
V_58 = F_8 ( V_47 , & V_4 ) ;
V_59 = ( unsigned int ) F_6 ( V_4 ,
V_57 -> V_51 ) ;
V_57 -> V_51 = V_4 ;
V_3 = ( unsigned int ) F_6 ( V_58 ,
V_57 -> V_50 ) ;
V_57 -> V_50 = V_58 ;
if ( V_42 . V_48 ) {
T_1 V_60 ;
unsigned long V_61 ;
V_60 = F_6 ( F_5 ( V_47 ) . V_6 . V_11 ,
V_57 -> V_52 ) ;
V_61 = ( unsigned long )
F_23 ( V_60 ) ;
V_57 -> V_52 = F_5 ( V_47 ) . V_6 . V_11 ;
V_3 += F_7 ( V_61 ) ;
}
if ( F_24 ( ! V_59 || V_59 < V_3 ) )
continue;
V_54 = 100 * ( V_59 - V_3 ) / V_59 ;
if ( V_54 > V_55 )
V_55 = V_54 ;
}
if ( V_42 . V_53 == 0 )
return;
if ( V_55 > V_42 . V_46 ) {
V_19 -> V_62 = 0 ;
if ( V_19 -> V_25 == V_22 -> V_26 )
return;
V_56 = ( V_42 . V_53 * V_22 -> V_26 ) / 100 ;
if ( F_24 ( V_56 == 0 ) )
V_56 = 5 ;
V_19 -> V_25 += V_56 ;
if ( V_19 -> V_25 > V_22 -> V_26 )
V_19 -> V_25 = V_22 -> V_26 ;
F_25 ( V_22 , V_19 -> V_25 ,
V_63 ) ;
return;
}
if ( V_55 < ( V_42 . V_45 - 10 ) ) {
V_56 = ( V_42 . V_53 * V_22 -> V_26 ) / 100 ;
V_19 -> V_25 -= V_56 ;
if ( V_19 -> V_25 < V_22 -> V_27 )
V_19 -> V_25 = V_22 -> V_27 ;
if ( V_22 -> V_64 == V_22 -> V_27 )
return;
F_25 ( V_22 , V_19 -> V_25 ,
V_63 ) ;
return;
}
}
static void F_26 ( struct V_65 * V_66 )
{
struct V_18 * V_49 =
F_27 ( V_66 , struct V_18 , V_66 . V_66 ) ;
unsigned int V_1 = V_49 -> V_1 ;
int V_67 = F_28 ( V_42 . V_44 ) ;
V_67 -= V_68 % V_67 ;
F_29 ( & V_49 -> V_69 ) ;
F_21 ( V_49 ) ;
F_30 ( V_1 , & V_49 -> V_66 , V_67 ) ;
F_31 ( & V_49 -> V_69 ) ;
}
static inline void F_32 ( struct V_18 * V_49 )
{
int V_67 = F_28 ( V_42 . V_44 ) ;
V_67 -= V_68 % V_67 ;
V_49 -> V_23 = 1 ;
F_33 ( & V_49 -> V_66 , F_26 ) ;
F_30 ( V_49 -> V_1 , & V_49 -> V_66 , V_67 ) ;
}
static inline void F_34 ( struct V_18 * V_49 )
{
V_49 -> V_23 = 0 ;
F_35 ( & V_49 -> V_66 ) ;
}
static int F_36 ( struct V_21 * V_22 ,
unsigned int V_70 )
{
unsigned int V_1 = V_22 -> V_1 ;
struct V_18 * V_19 ;
unsigned int V_47 ;
int V_71 ;
V_19 = & F_12 ( V_20 , V_1 ) ;
switch ( V_70 ) {
case V_72 :
if ( ( ! F_37 ( V_1 ) ) || ( ! V_22 -> V_64 ) )
return - V_41 ;
F_29 ( & V_73 ) ;
F_22 (j, policy->cpus) {
struct V_18 * V_57 ;
V_57 = & F_12 ( V_20 , V_47 ) ;
V_57 -> V_24 = V_22 ;
V_57 -> V_50 = F_8 ( V_47 ,
& V_57 -> V_51 ) ;
if ( V_42 . V_48 ) {
V_57 -> V_52 =
F_5 ( V_47 ) . V_6 . V_11 ;
}
}
V_19 -> V_62 = 0 ;
V_19 -> V_25 = V_22 -> V_64 ;
F_38 ( & V_19 -> V_69 ) ;
V_74 ++ ;
if ( V_74 == 1 ) {
unsigned int V_75 ;
V_75 = V_22 -> V_76 . V_77 / 1000 ;
if ( V_75 == 0 )
V_75 = 1 ;
V_71 = F_39 ( V_78 ,
& V_79 ) ;
if ( V_71 ) {
F_31 ( & V_73 ) ;
return V_71 ;
}
V_34 =
V_80 * F_7 ( 10 ) ;
V_34 = V_26 ( V_34 ,
V_81 * V_75 ) ;
V_42 . V_44 =
V_26 ( V_34 ,
V_75 * V_82 ) ;
F_40 (
& V_83 ,
V_84 ) ;
}
F_31 ( & V_73 ) ;
F_32 ( V_19 ) ;
break;
case V_85 :
F_34 ( V_19 ) ;
F_29 ( & V_73 ) ;
V_74 -- ;
F_41 ( & V_19 -> V_69 ) ;
if ( V_74 == 0 )
F_42 (
& V_83 ,
V_84 ) ;
F_31 ( & V_73 ) ;
if ( ! V_74 )
F_43 ( V_78 ,
& V_79 ) ;
break;
case V_86 :
F_29 ( & V_19 -> V_69 ) ;
if ( V_22 -> V_26 < V_19 -> V_24 -> V_64 )
F_25 (
V_19 -> V_24 ,
V_22 -> V_26 , V_63 ) ;
else if ( V_22 -> V_27 > V_19 -> V_24 -> V_64 )
F_25 (
V_19 -> V_24 ,
V_22 -> V_27 , V_87 ) ;
F_31 ( & V_19 -> V_69 ) ;
break;
}
return 0 ;
}
static int T_5 F_44 ( void )
{
return F_45 ( & V_88 ) ;
}
static void T_6 F_46 ( void )
{
F_47 ( & V_88 ) ;
}
