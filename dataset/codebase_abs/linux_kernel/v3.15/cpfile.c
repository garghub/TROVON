static inline unsigned long
F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 ;
}
static unsigned long
F_3 ( const struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_5 = V_4 + F_2 ( V_2 ) -> V_6 - 1 ;
F_4 ( V_5 , F_1 ( V_2 ) ) ;
return ( unsigned long ) V_5 ;
}
static unsigned long
F_5 ( const struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_5 = V_4 + F_2 ( V_2 ) -> V_6 - 1 ;
return F_4 ( V_5 , F_1 ( V_2 ) ) ;
}
static unsigned long
F_6 ( const struct V_1 * V_2 ,
T_1 V_7 ,
T_1 V_8 )
{
return F_7 ( T_1 ,
F_1 ( V_2 ) -
F_5 ( V_2 , V_7 ) ,
V_8 - V_7 ) ;
}
static inline int F_8 ( const struct V_1 * V_2 ,
T_1 V_4 )
{
return F_3 ( V_2 , V_4 ) == 0 ;
}
static unsigned int
F_9 ( const struct V_1 * V_2 ,
struct V_9 * V_10 ,
void * V_11 ,
unsigned int V_12 )
{
struct V_13 * V_14 = V_11 + F_10 ( V_10 ) ;
unsigned int V_15 ;
V_15 = F_11 ( V_14 -> V_16 ) + V_12 ;
V_14 -> V_16 = F_12 ( V_15 ) ;
return V_15 ;
}
static unsigned int
F_13 ( const struct V_1 * V_2 ,
struct V_9 * V_10 ,
void * V_11 ,
unsigned int V_12 )
{
struct V_13 * V_14 = V_11 + F_10 ( V_10 ) ;
unsigned int V_15 ;
F_14 ( F_11 ( V_14 -> V_16 ) < V_12 ) ;
V_15 = F_11 ( V_14 -> V_16 ) - V_12 ;
V_14 -> V_16 = F_12 ( V_15 ) ;
return V_15 ;
}
static inline struct V_17 *
F_15 ( const struct V_1 * V_2 ,
struct V_9 * V_10 ,
void * V_11 )
{
return V_11 + F_10 ( V_10 ) ;
}
static struct V_13 *
F_16 ( const struct V_1 * V_2 , T_1 V_4 ,
struct V_9 * V_10 ,
void * V_11 )
{
return V_11 + F_10 ( V_10 ) + F_5 ( V_2 , V_4 ) *
F_2 ( V_2 ) -> V_18 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
void * V_11 )
{
struct V_13 * V_14 = V_11 + F_10 ( V_10 ) ;
T_2 V_19 = F_2 ( V_2 ) -> V_18 ;
int V_12 = F_1 ( V_2 ) ;
while ( V_12 -- > 0 ) {
F_18 ( V_14 ) ;
V_14 = ( void * ) V_14 + V_19 ;
}
}
static inline int F_19 ( struct V_1 * V_2 ,
struct V_9 * * V_20 )
{
return F_20 ( V_2 , 0 , 0 , NULL , V_20 ) ;
}
static inline int F_21 ( struct V_1 * V_2 ,
T_1 V_4 ,
int V_21 ,
struct V_9 * * V_20 )
{
return F_20 ( V_2 ,
F_3 ( V_2 , V_4 ) ,
V_21 , F_17 , V_20 ) ;
}
static inline int F_22 ( struct V_1 * V_2 ,
T_1 V_4 )
{
return F_23 ( V_2 ,
F_3 ( V_2 , V_4 ) ) ;
}
int F_24 ( struct V_1 * V_2 ,
T_1 V_4 ,
int V_21 ,
struct V_13 * * V_22 ,
struct V_9 * * V_20 )
{
struct V_9 * V_23 , * V_24 ;
struct V_17 * V_25 ;
struct V_13 * V_14 ;
void * V_11 ;
int V_26 ;
if ( F_25 ( V_4 < 1 || V_4 > F_26 ( V_2 ) ||
( V_4 < F_26 ( V_2 ) && V_21 ) ) )
return - V_27 ;
F_27 ( & F_2 ( V_2 ) -> V_28 ) ;
V_26 = F_19 ( V_2 , & V_23 ) ;
if ( V_26 < 0 )
goto V_29;
V_26 = F_21 ( V_2 , V_4 , V_21 , & V_24 ) ;
if ( V_26 < 0 )
goto V_30;
V_11 = F_28 ( V_24 -> V_31 ) ;
V_14 = F_16 ( V_2 , V_4 , V_24 , V_11 ) ;
if ( F_29 ( V_14 ) ) {
if ( ! V_21 ) {
F_30 ( V_24 -> V_31 ) ;
F_31 ( V_24 ) ;
V_26 = - V_32 ;
goto V_30;
}
F_32 ( V_14 ) ;
if ( ! F_8 ( V_2 , V_4 ) )
F_9 ( V_2 , V_24 ,
V_11 , 1 ) ;
F_33 ( V_24 ) ;
V_11 = F_34 ( V_23 -> V_31 ) ;
V_25 = F_15 ( V_2 , V_23 ,
V_11 ) ;
F_35 ( & V_25 -> V_33 , 1 ) ;
F_36 ( V_11 ) ;
F_33 ( V_23 ) ;
F_37 ( V_2 ) ;
}
if ( V_22 != NULL )
* V_22 = V_14 ;
* V_20 = V_24 ;
V_30:
F_31 ( V_23 ) ;
V_29:
F_38 ( & F_2 ( V_2 ) -> V_28 ) ;
return V_26 ;
}
void F_39 ( struct V_1 * V_2 , T_1 V_4 ,
struct V_9 * V_10 )
{
F_30 ( V_10 -> V_31 ) ;
F_31 ( V_10 ) ;
}
int F_40 ( struct V_1 * V_2 ,
T_1 V_34 ,
T_1 V_35 )
{
struct V_9 * V_23 , * V_24 ;
struct V_17 * V_25 ;
struct V_13 * V_14 ;
T_2 V_19 = F_2 ( V_2 ) -> V_18 ;
T_1 V_4 ;
void * V_11 ;
unsigned long V_36 ;
int V_26 , V_37 , V_38 , V_39 , V_15 , V_40 ;
if ( F_25 ( V_34 == 0 || V_34 > V_35 ) ) {
F_41 ( V_41 L_1
L_2 , V_42 ,
( unsigned long long ) V_34 , ( unsigned long long ) V_35 ) ;
return - V_27 ;
}
F_27 ( & F_2 ( V_2 ) -> V_28 ) ;
V_26 = F_19 ( V_2 , & V_23 ) ;
if ( V_26 < 0 )
goto V_29;
V_36 = 0 ;
V_39 = 0 ;
for ( V_4 = V_34 ; V_4 < V_35 ; V_4 += V_37 ) {
V_37 = F_6 ( V_2 , V_4 , V_35 ) ;
V_26 = F_21 ( V_2 , V_4 , 0 , & V_24 ) ;
if ( V_26 < 0 ) {
if ( V_26 != - V_32 )
break;
V_26 = 0 ;
continue;
}
V_11 = F_34 ( V_24 -> V_31 ) ;
V_14 = F_16 (
V_2 , V_4 , V_24 , V_11 ) ;
V_38 = 0 ;
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ , V_14 = ( void * ) V_14 + V_19 ) {
if ( F_42 ( V_14 ) ) {
V_39 ++ ;
} else if ( ! F_29 ( V_14 ) ) {
F_18 ( V_14 ) ;
V_38 ++ ;
}
}
if ( V_38 > 0 ) {
V_36 += V_38 ;
F_33 ( V_24 ) ;
F_37 ( V_2 ) ;
if ( ! F_8 ( V_2 , V_4 ) ) {
V_15 =
F_13 (
V_2 , V_24 , V_11 , V_38 ) ;
if ( V_15 == 0 ) {
F_36 ( V_11 ) ;
F_31 ( V_24 ) ;
V_26 =
F_22 (
V_2 , V_4 ) ;
if ( V_26 == 0 )
continue;
F_41 ( V_41
L_3 ,
V_42 ) ;
break;
}
}
}
F_36 ( V_11 ) ;
F_31 ( V_24 ) ;
}
if ( V_36 > 0 ) {
V_11 = F_34 ( V_23 -> V_31 ) ;
V_25 = F_15 ( V_2 , V_23 ,
V_11 ) ;
F_35 ( & V_25 -> V_33 , - ( V_43 ) V_36 ) ;
F_33 ( V_23 ) ;
F_37 ( V_2 ) ;
F_36 ( V_11 ) ;
}
F_31 ( V_23 ) ;
if ( V_39 > 0 )
V_26 = - V_44 ;
V_29:
F_38 ( & F_2 ( V_2 ) -> V_28 ) ;
return V_26 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_45 * V_46 )
{
V_46 -> V_47 = F_11 ( V_14 -> V_48 ) ;
V_46 -> V_49 = F_44 ( V_14 -> V_50 ) ;
V_46 -> V_51 = F_44 ( V_14 -> V_52 ) ;
V_46 -> V_53 = F_44 ( V_14 -> V_54 ) ;
V_46 -> V_55 = F_44 ( V_14 -> V_56 ) ;
V_46 -> V_57 = F_44 ( V_14 -> V_58 ) ;
V_46 -> V_59 = F_44 ( V_14 -> V_60 . V_61 ) ;
}
static T_3 F_45 ( struct V_1 * V_2 , T_1 * V_62 ,
void * V_63 , unsigned V_64 , T_2 V_65 )
{
struct V_13 * V_14 ;
struct V_45 * V_46 = V_63 ;
struct V_9 * V_10 ;
T_2 V_19 = F_2 ( V_2 ) -> V_18 ;
T_1 V_66 = F_26 ( V_2 ) , V_4 = * V_62 ;
void * V_11 ;
int V_12 , V_26 ;
int V_37 , V_40 ;
if ( V_4 == 0 )
return - V_32 ;
F_46 ( & F_2 ( V_2 ) -> V_28 ) ;
for ( V_12 = 0 ; V_4 < V_66 && V_12 < V_65 ; V_4 += V_37 ) {
V_37 = F_6 ( V_2 , V_4 , V_66 ) ;
V_26 = F_21 ( V_2 , V_4 , 0 , & V_10 ) ;
if ( V_26 < 0 ) {
if ( V_26 != - V_32 )
goto V_67;
continue;
}
V_11 = F_34 ( V_10 -> V_31 ) ;
V_14 = F_16 ( V_2 , V_4 , V_10 , V_11 ) ;
for ( V_40 = 0 ; V_40 < V_37 && V_12 < V_65 ; V_40 ++ , V_14 = ( void * ) V_14 + V_19 ) {
if ( ! F_29 ( V_14 ) ) {
F_43 ( V_2 , V_14 ,
V_46 ) ;
V_46 = ( void * ) V_46 + V_64 ;
V_12 ++ ;
}
}
F_36 ( V_11 ) ;
F_31 ( V_10 ) ;
}
V_26 = V_12 ;
if ( V_12 > 0 ) {
V_46 = ( void * ) V_46 - V_64 ;
* V_62 = V_46 -> V_49 + 1 ;
}
V_67:
F_47 ( & F_2 ( V_2 ) -> V_28 ) ;
return V_26 ;
}
static T_3 F_48 ( struct V_1 * V_2 , T_1 * V_62 ,
void * V_63 , unsigned V_64 , T_2 V_65 )
{
struct V_9 * V_10 ;
struct V_17 * V_25 ;
struct V_13 * V_14 ;
struct V_45 * V_46 = V_63 ;
T_1 V_7 = * V_62 , V_68 ;
unsigned long V_69 , V_70 ;
void * V_11 ;
int V_12 = 0 , V_26 ;
F_46 ( & F_2 ( V_2 ) -> V_28 ) ;
if ( V_7 == 0 ) {
V_26 = F_19 ( V_2 , & V_10 ) ;
if ( V_26 < 0 )
goto V_67;
V_11 = F_34 ( V_10 -> V_31 ) ;
V_25 = F_15 ( V_2 , V_10 , V_11 ) ;
V_7 = F_44 ( V_25 -> V_71 . V_61 ) ;
F_36 ( V_11 ) ;
F_31 ( V_10 ) ;
if ( V_7 == 0 ) {
V_26 = 0 ;
goto V_67;
}
} else if ( F_25 ( V_7 == ~ ( T_1 ) 0 ) ) {
V_26 = 0 ;
goto V_67;
}
V_69 = F_3 ( V_2 , V_7 ) ;
V_26 = F_21 ( V_2 , V_7 , 0 , & V_10 ) ;
if ( F_25 ( V_26 < 0 ) ) {
if ( V_26 == - V_32 )
V_26 = 0 ;
goto V_67;
}
V_11 = F_34 ( V_10 -> V_31 ) ;
while ( V_12 < V_65 ) {
V_14 = F_16 ( V_2 , V_7 , V_10 , V_11 ) ;
V_7 = ~ ( T_1 ) 0 ;
if ( F_25 ( F_29 ( V_14 ) ||
! F_42 ( V_14 ) ) )
break;
F_43 ( V_2 , V_14 , V_46 ) ;
V_46 = ( void * ) V_46 + V_64 ;
V_12 ++ ;
V_68 = F_44 ( V_14 -> V_60 . V_61 ) ;
if ( V_68 == 0 )
break;
V_70 = F_3 ( V_2 , V_68 ) ;
if ( V_69 != V_70 ) {
F_36 ( V_11 ) ;
F_31 ( V_10 ) ;
V_26 = F_21 ( V_2 , V_68 ,
0 , & V_10 ) ;
if ( F_25 ( V_26 < 0 ) ) {
F_14 ( V_26 == - V_32 ) ;
goto V_67;
}
V_11 = F_34 ( V_10 -> V_31 ) ;
}
V_7 = V_68 ;
V_69 = V_70 ;
}
F_36 ( V_11 ) ;
F_31 ( V_10 ) ;
* V_62 = V_7 ;
V_26 = V_12 ;
V_67:
F_47 ( & F_2 ( V_2 ) -> V_28 ) ;
return V_26 ;
}
T_3 F_49 ( struct V_1 * V_2 , T_1 * V_62 , int V_72 ,
void * V_63 , unsigned V_64 , T_2 V_65 )
{
switch ( V_72 ) {
case V_73 :
return F_45 ( V_2 , V_62 , V_63 , V_64 , V_65 ) ;
case V_74 :
return F_48 ( V_2 , V_62 , V_63 , V_64 , V_65 ) ;
default:
return - V_27 ;
}
}
int F_50 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_45 V_46 ;
T_1 V_5 = V_4 ;
T_3 V_65 ;
V_65 = F_45 ( V_2 , & V_5 , & V_46 , sizeof( V_46 ) , 1 ) ;
if ( V_65 < 0 )
return V_65 ;
else if ( V_65 == 0 || V_46 . V_49 != V_4 )
return - V_32 ;
else if ( F_51 ( & V_46 ) )
return - V_44 ;
return F_40 ( V_2 , V_4 , V_4 + 1 ) ;
}
static struct V_75 *
F_52 ( const struct V_1 * V_2 ,
T_1 V_4 ,
struct V_9 * V_10 ,
void * V_11 )
{
struct V_17 * V_25 ;
struct V_13 * V_14 ;
struct V_75 * V_76 ;
if ( V_4 != 0 ) {
V_14 = F_16 ( V_2 , V_4 , V_10 , V_11 ) ;
V_76 = & V_14 -> V_60 ;
} else {
V_25 = F_15 ( V_2 , V_10 , V_11 ) ;
V_76 = & V_25 -> V_71 ;
}
return V_76 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_9 * V_23 , * V_77 , * V_78 , * V_24 ;
struct V_17 * V_25 ;
struct V_13 * V_14 ;
struct V_75 * V_76 ;
T_1 V_7 , V_79 ;
unsigned long V_69 , V_80 ;
void * V_11 ;
int V_26 ;
if ( V_4 == 0 )
return - V_32 ;
F_27 ( & F_2 ( V_2 ) -> V_28 ) ;
V_26 = F_21 ( V_2 , V_4 , 0 , & V_24 ) ;
if ( V_26 < 0 )
goto V_29;
V_11 = F_34 ( V_24 -> V_31 ) ;
V_14 = F_16 ( V_2 , V_4 , V_24 , V_11 ) ;
if ( F_29 ( V_14 ) ) {
V_26 = - V_32 ;
F_36 ( V_11 ) ;
goto V_81;
}
if ( F_42 ( V_14 ) ) {
V_26 = 0 ;
F_36 ( V_11 ) ;
goto V_81;
}
F_36 ( V_11 ) ;
V_26 = F_19 ( V_2 , & V_23 ) ;
if ( V_26 < 0 )
goto V_81;
V_11 = F_34 ( V_23 -> V_31 ) ;
V_25 = F_15 ( V_2 , V_23 , V_11 ) ;
V_76 = & V_25 -> V_71 ;
V_77 = V_23 ;
F_54 ( V_77 ) ;
V_7 = 0 ;
V_69 = 0 ;
V_79 = F_44 ( V_76 -> V_82 ) ;
while ( V_79 > V_4 ) {
V_80 = F_3 ( V_2 , V_79 ) ;
V_7 = V_79 ;
if ( V_69 != V_80 ) {
F_36 ( V_11 ) ;
F_31 ( V_77 ) ;
V_26 = F_21 ( V_2 , V_7 ,
0 , & V_77 ) ;
if ( V_26 < 0 )
goto V_30;
V_11 = F_34 ( V_77 -> V_31 ) ;
}
V_69 = V_80 ;
V_14 = F_16 (
V_2 , V_7 , V_77 , V_11 ) ;
V_76 = & V_14 -> V_60 ;
V_79 = F_44 ( V_76 -> V_82 ) ;
}
F_36 ( V_11 ) ;
if ( V_79 != 0 ) {
V_26 = F_21 ( V_2 , V_79 , 0 ,
& V_78 ) ;
if ( V_26 < 0 )
goto V_83;
} else {
V_78 = V_23 ;
F_54 ( V_78 ) ;
}
V_11 = F_34 ( V_77 -> V_31 ) ;
V_76 = F_52 (
V_2 , V_7 , V_77 , V_11 ) ;
V_76 -> V_82 = F_55 ( V_4 ) ;
F_36 ( V_11 ) ;
V_11 = F_34 ( V_24 -> V_31 ) ;
V_14 = F_16 ( V_2 , V_4 , V_24 , V_11 ) ;
V_14 -> V_60 . V_61 = F_55 ( V_7 ) ;
V_14 -> V_60 . V_82 = F_55 ( V_79 ) ;
F_56 ( V_14 ) ;
F_36 ( V_11 ) ;
V_11 = F_34 ( V_78 -> V_31 ) ;
V_76 = F_52 (
V_2 , V_79 , V_78 , V_11 ) ;
V_76 -> V_61 = F_55 ( V_4 ) ;
F_36 ( V_11 ) ;
V_11 = F_34 ( V_23 -> V_31 ) ;
V_25 = F_15 ( V_2 , V_23 , V_11 ) ;
F_35 ( & V_25 -> V_84 , 1 ) ;
F_36 ( V_11 ) ;
F_33 ( V_78 ) ;
F_33 ( V_77 ) ;
F_33 ( V_24 ) ;
F_33 ( V_23 ) ;
F_37 ( V_2 ) ;
F_31 ( V_78 ) ;
V_83:
F_31 ( V_77 ) ;
V_30:
F_31 ( V_23 ) ;
V_81:
F_31 ( V_24 ) ;
V_29:
F_38 ( & F_2 ( V_2 ) -> V_28 ) ;
return V_26 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_9 * V_23 , * V_85 , * V_78 , * V_24 ;
struct V_17 * V_25 ;
struct V_13 * V_14 ;
struct V_75 * V_76 ;
T_1 V_68 , V_79 ;
void * V_11 ;
int V_26 ;
if ( V_4 == 0 )
return - V_32 ;
F_27 ( & F_2 ( V_2 ) -> V_28 ) ;
V_26 = F_21 ( V_2 , V_4 , 0 , & V_24 ) ;
if ( V_26 < 0 )
goto V_29;
V_11 = F_34 ( V_24 -> V_31 ) ;
V_14 = F_16 ( V_2 , V_4 , V_24 , V_11 ) ;
if ( F_29 ( V_14 ) ) {
V_26 = - V_32 ;
F_36 ( V_11 ) ;
goto V_81;
}
if ( ! F_42 ( V_14 ) ) {
V_26 = 0 ;
F_36 ( V_11 ) ;
goto V_81;
}
V_76 = & V_14 -> V_60 ;
V_68 = F_44 ( V_76 -> V_61 ) ;
V_79 = F_44 ( V_76 -> V_82 ) ;
F_36 ( V_11 ) ;
V_26 = F_19 ( V_2 , & V_23 ) ;
if ( V_26 < 0 )
goto V_81;
if ( V_68 != 0 ) {
V_26 = F_21 ( V_2 , V_68 , 0 ,
& V_85 ) ;
if ( V_26 < 0 )
goto V_30;
} else {
V_85 = V_23 ;
F_54 ( V_85 ) ;
}
if ( V_79 != 0 ) {
V_26 = F_21 ( V_2 , V_79 , 0 ,
& V_78 ) ;
if ( V_26 < 0 )
goto V_86;
} else {
V_78 = V_23 ;
F_54 ( V_78 ) ;
}
V_11 = F_34 ( V_85 -> V_31 ) ;
V_76 = F_52 (
V_2 , V_68 , V_85 , V_11 ) ;
V_76 -> V_82 = F_55 ( V_79 ) ;
F_36 ( V_11 ) ;
V_11 = F_34 ( V_78 -> V_31 ) ;
V_76 = F_52 (
V_2 , V_79 , V_78 , V_11 ) ;
V_76 -> V_61 = F_55 ( V_68 ) ;
F_36 ( V_11 ) ;
V_11 = F_34 ( V_24 -> V_31 ) ;
V_14 = F_16 ( V_2 , V_4 , V_24 , V_11 ) ;
V_14 -> V_60 . V_61 = F_55 ( 0 ) ;
V_14 -> V_60 . V_82 = F_55 ( 0 ) ;
F_58 ( V_14 ) ;
F_36 ( V_11 ) ;
V_11 = F_34 ( V_23 -> V_31 ) ;
V_25 = F_15 ( V_2 , V_23 , V_11 ) ;
F_35 ( & V_25 -> V_84 , - 1 ) ;
F_36 ( V_11 ) ;
F_33 ( V_85 ) ;
F_33 ( V_78 ) ;
F_33 ( V_24 ) ;
F_33 ( V_23 ) ;
F_37 ( V_2 ) ;
F_31 ( V_78 ) ;
V_86:
F_31 ( V_85 ) ;
V_30:
F_31 ( V_23 ) ;
V_81:
F_31 ( V_24 ) ;
V_29:
F_38 ( & F_2 ( V_2 ) -> V_28 ) ;
return V_26 ;
}
int F_59 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_9 * V_10 ;
struct V_13 * V_14 ;
void * V_11 ;
int V_26 ;
if ( V_4 == 0 || V_4 >= F_26 ( V_2 ) )
return - V_32 ;
F_46 ( & F_2 ( V_2 ) -> V_28 ) ;
V_26 = F_21 ( V_2 , V_4 , 0 , & V_10 ) ;
if ( V_26 < 0 )
goto V_67;
V_11 = F_34 ( V_10 -> V_31 ) ;
V_14 = F_16 ( V_2 , V_4 , V_10 , V_11 ) ;
if ( F_29 ( V_14 ) )
V_26 = - V_32 ;
else
V_26 = F_42 ( V_14 ) ;
F_36 ( V_11 ) ;
F_31 ( V_10 ) ;
V_67:
F_47 ( & F_2 ( V_2 ) -> V_28 ) ;
return V_26 ;
}
int F_60 ( struct V_1 * V_2 , T_1 V_4 , int V_72 )
{
int V_26 ;
switch ( V_72 ) {
case V_73 :
if ( F_61 ( V_2 -> V_87 , V_4 ) )
V_26 = - V_44 ;
else
V_26 = F_57 ( V_2 , V_4 ) ;
return V_26 ;
case V_74 :
return F_53 ( V_2 , V_4 ) ;
default:
return - V_27 ;
}
}
int F_62 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_9 * V_10 ;
struct V_17 * V_25 ;
void * V_11 ;
int V_26 ;
F_46 ( & F_2 ( V_2 ) -> V_28 ) ;
V_26 = F_19 ( V_2 , & V_10 ) ;
if ( V_26 < 0 )
goto V_29;
V_11 = F_34 ( V_10 -> V_31 ) ;
V_25 = F_15 ( V_2 , V_10 , V_11 ) ;
V_89 -> V_90 = F_26 ( V_2 ) ;
V_89 -> V_91 = F_44 ( V_25 -> V_33 ) ;
V_89 -> V_92 = F_44 ( V_25 -> V_84 ) ;
F_36 ( V_11 ) ;
F_31 ( V_10 ) ;
V_29:
F_47 ( & F_2 ( V_2 ) -> V_28 ) ;
return V_26 ;
}
int F_63 ( struct V_93 * V_94 , T_2 V_95 ,
struct V_96 * V_97 , struct V_1 * * V_98 )
{
struct V_1 * V_2 ;
int V_99 ;
if ( V_95 > V_94 -> V_100 ) {
F_41 ( V_41
L_4 ,
V_95 ) ;
return - V_27 ;
} else if ( V_95 < V_101 ) {
F_41 ( V_41
L_5 ,
V_95 ) ;
return - V_27 ;
}
V_2 = F_64 ( V_94 , NULL , V_102 ) ;
if ( F_25 ( ! V_2 ) )
return - V_103 ;
if ( ! ( V_2 -> V_104 & V_105 ) )
goto V_67;
V_99 = F_65 ( V_2 , V_106 , 0 ) ;
if ( V_99 )
goto V_107;
F_66 ( V_2 , V_95 ,
sizeof( struct V_17 ) ) ;
V_99 = F_67 ( V_2 , V_97 ) ;
if ( V_99 )
goto V_107;
F_68 ( V_2 ) ;
V_67:
* V_98 = V_2 ;
return 0 ;
V_107:
F_69 ( V_2 ) ;
return V_99 ;
}
