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
static T_1 F_6 ( const struct V_1 * V_2 ,
unsigned long V_7 )
{
return ( T_1 ) F_1 ( V_2 ) * V_7
+ 1 - F_2 ( V_2 ) -> V_6 ;
}
static unsigned long
F_7 ( const struct V_1 * V_2 ,
T_1 V_8 ,
T_1 V_9 )
{
return F_8 ( T_1 ,
F_1 ( V_2 ) -
F_5 ( V_2 , V_8 ) ,
V_9 - V_8 ) ;
}
static inline int F_9 ( const struct V_1 * V_2 ,
T_1 V_4 )
{
return F_3 ( V_2 , V_4 ) == 0 ;
}
static unsigned int
F_10 ( const struct V_1 * V_2 ,
struct V_10 * V_11 ,
void * V_12 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_12 + F_11 ( V_11 ) ;
unsigned int V_16 ;
V_16 = F_12 ( V_15 -> V_17 ) + V_13 ;
V_15 -> V_17 = F_13 ( V_16 ) ;
return V_16 ;
}
static unsigned int
F_14 ( const struct V_1 * V_2 ,
struct V_10 * V_11 ,
void * V_12 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_12 + F_11 ( V_11 ) ;
unsigned int V_16 ;
F_15 ( F_12 ( V_15 -> V_17 ) < V_13 ) ;
V_16 = F_12 ( V_15 -> V_17 ) - V_13 ;
V_15 -> V_17 = F_13 ( V_16 ) ;
return V_16 ;
}
static inline struct V_18 *
F_16 ( const struct V_1 * V_2 ,
struct V_10 * V_11 ,
void * V_12 )
{
return V_12 + F_11 ( V_11 ) ;
}
static struct V_14 *
F_17 ( const struct V_1 * V_2 , T_1 V_4 ,
struct V_10 * V_11 ,
void * V_12 )
{
return V_12 + F_11 ( V_11 ) + F_5 ( V_2 , V_4 ) *
F_2 ( V_2 ) -> V_19 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
void * V_12 )
{
struct V_14 * V_15 = V_12 + F_11 ( V_11 ) ;
T_2 V_20 = F_2 ( V_2 ) -> V_19 ;
int V_13 = F_1 ( V_2 ) ;
while ( V_13 -- > 0 ) {
F_19 ( V_15 ) ;
V_15 = ( void * ) V_15 + V_20 ;
}
}
static inline int F_20 ( struct V_1 * V_2 ,
struct V_10 * * V_21 )
{
return F_21 ( V_2 , 0 , 0 , NULL , V_21 ) ;
}
static inline int F_22 ( struct V_1 * V_2 ,
T_1 V_4 ,
int V_22 ,
struct V_10 * * V_21 )
{
return F_21 ( V_2 ,
F_3 ( V_2 , V_4 ) ,
V_22 , F_18 , V_21 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_23 , T_1 V_24 ,
T_1 * V_25 ,
struct V_10 * * V_21 )
{
unsigned long V_26 , V_27 , V_7 ;
int V_28 ;
if ( F_24 ( V_23 > V_24 ) )
return - V_29 ;
V_26 = F_3 ( V_2 , V_23 ) ;
V_27 = F_3 ( V_2 , V_24 ) ;
V_28 = F_25 ( V_2 , V_26 , V_27 , & V_7 , V_21 ) ;
if ( ! V_28 )
* V_25 = ( V_7 == V_26 ) ? V_23 :
F_6 ( V_2 , V_7 ) ;
return V_28 ;
}
static inline int F_26 ( struct V_1 * V_2 ,
T_1 V_4 )
{
return F_27 ( V_2 ,
F_3 ( V_2 , V_4 ) ) ;
}
int F_28 ( struct V_1 * V_2 ,
T_1 V_4 ,
int V_22 ,
struct V_14 * * V_30 ,
struct V_10 * * V_21 )
{
struct V_10 * V_31 , * V_32 ;
struct V_18 * V_33 ;
struct V_14 * V_15 ;
void * V_12 ;
int V_28 ;
if ( F_24 ( V_4 < 1 || V_4 > F_29 ( V_2 ) ||
( V_4 < F_29 ( V_2 ) && V_22 ) ) )
return - V_34 ;
F_30 ( & F_2 ( V_2 ) -> V_35 ) ;
V_28 = F_20 ( V_2 , & V_31 ) ;
if ( V_28 < 0 )
goto V_36;
V_28 = F_22 ( V_2 , V_4 , V_22 , & V_32 ) ;
if ( V_28 < 0 )
goto V_37;
V_12 = F_31 ( V_32 -> V_38 ) ;
V_15 = F_17 ( V_2 , V_4 , V_32 , V_12 ) ;
if ( F_32 ( V_15 ) ) {
if ( ! V_22 ) {
F_33 ( V_32 -> V_38 ) ;
F_34 ( V_32 ) ;
V_28 = - V_29 ;
goto V_37;
}
F_35 ( V_15 ) ;
if ( ! F_9 ( V_2 , V_4 ) )
F_10 ( V_2 , V_32 ,
V_12 , 1 ) ;
F_36 ( V_32 ) ;
V_12 = F_37 ( V_31 -> V_38 ) ;
V_33 = F_16 ( V_2 , V_31 ,
V_12 ) ;
F_38 ( & V_33 -> V_39 , 1 ) ;
F_39 ( V_12 ) ;
F_36 ( V_31 ) ;
F_40 ( V_2 ) ;
}
if ( V_30 != NULL )
* V_30 = V_15 ;
* V_21 = V_32 ;
V_37:
F_34 ( V_31 ) ;
V_36:
F_41 ( & F_2 ( V_2 ) -> V_35 ) ;
return V_28 ;
}
void F_42 ( struct V_1 * V_2 , T_1 V_4 ,
struct V_10 * V_11 )
{
F_33 ( V_11 -> V_38 ) ;
F_34 ( V_11 ) ;
}
int F_43 ( struct V_1 * V_2 ,
T_1 V_26 ,
T_1 V_27 )
{
struct V_10 * V_31 , * V_32 ;
struct V_18 * V_33 ;
struct V_14 * V_15 ;
T_2 V_20 = F_2 ( V_2 ) -> V_19 ;
T_1 V_4 ;
void * V_12 ;
unsigned long V_40 ;
int V_28 , V_41 , V_42 , V_43 , V_16 , V_44 ;
if ( F_24 ( V_26 == 0 || V_26 > V_27 ) ) {
F_44 ( V_45 L_1
L_2 , V_46 ,
( unsigned long long ) V_26 , ( unsigned long long ) V_27 ) ;
return - V_34 ;
}
F_30 ( & F_2 ( V_2 ) -> V_35 ) ;
V_28 = F_20 ( V_2 , & V_31 ) ;
if ( V_28 < 0 )
goto V_36;
V_40 = 0 ;
V_43 = 0 ;
for ( V_4 = V_26 ; V_4 < V_27 ; V_4 += V_41 ) {
V_41 = F_7 ( V_2 , V_4 , V_27 ) ;
V_28 = F_22 ( V_2 , V_4 , 0 , & V_32 ) ;
if ( V_28 < 0 ) {
if ( V_28 != - V_29 )
break;
V_28 = 0 ;
continue;
}
V_12 = F_37 ( V_32 -> V_38 ) ;
V_15 = F_17 (
V_2 , V_4 , V_32 , V_12 ) ;
V_42 = 0 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ , V_15 = ( void * ) V_15 + V_20 ) {
if ( F_45 ( V_15 ) ) {
V_43 ++ ;
} else if ( ! F_32 ( V_15 ) ) {
F_19 ( V_15 ) ;
V_42 ++ ;
}
}
if ( V_42 > 0 ) {
V_40 += V_42 ;
F_36 ( V_32 ) ;
F_40 ( V_2 ) ;
if ( ! F_9 ( V_2 , V_4 ) ) {
V_16 =
F_14 (
V_2 , V_32 , V_12 , V_42 ) ;
if ( V_16 == 0 ) {
F_39 ( V_12 ) ;
F_34 ( V_32 ) ;
V_28 =
F_26 (
V_2 , V_4 ) ;
if ( V_28 == 0 )
continue;
F_44 ( V_45
L_3 ,
V_46 ) ;
break;
}
}
}
F_39 ( V_12 ) ;
F_34 ( V_32 ) ;
}
if ( V_40 > 0 ) {
V_12 = F_37 ( V_31 -> V_38 ) ;
V_33 = F_16 ( V_2 , V_31 ,
V_12 ) ;
F_38 ( & V_33 -> V_39 , - ( V_47 ) V_40 ) ;
F_36 ( V_31 ) ;
F_40 ( V_2 ) ;
F_39 ( V_12 ) ;
}
F_34 ( V_31 ) ;
if ( V_43 > 0 )
V_28 = - V_48 ;
V_36:
F_41 ( & F_2 ( V_2 ) -> V_35 ) ;
return V_28 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_49 * V_50 )
{
V_50 -> V_51 = F_12 ( V_15 -> V_52 ) ;
V_50 -> V_53 = F_47 ( V_15 -> V_54 ) ;
V_50 -> V_55 = F_47 ( V_15 -> V_56 ) ;
V_50 -> V_57 = F_47 ( V_15 -> V_58 ) ;
V_50 -> V_59 = F_47 ( V_15 -> V_60 ) ;
V_50 -> V_61 = F_47 ( V_15 -> V_62 ) ;
V_50 -> V_63 = F_47 ( V_15 -> V_64 . V_65 ) ;
}
static T_3 F_48 ( struct V_1 * V_2 , T_1 * V_25 ,
void * V_66 , unsigned V_67 , T_2 V_68 )
{
struct V_14 * V_15 ;
struct V_49 * V_50 = V_66 ;
struct V_10 * V_11 ;
T_2 V_20 = F_2 ( V_2 ) -> V_19 ;
T_1 V_69 = F_29 ( V_2 ) , V_4 = * V_25 ;
void * V_12 ;
int V_13 , V_28 ;
int V_41 , V_44 ;
if ( V_4 == 0 )
return - V_29 ;
F_49 ( & F_2 ( V_2 ) -> V_35 ) ;
for ( V_13 = 0 ; V_13 < V_68 ; V_4 += V_41 ) {
V_28 = F_23 (
V_2 , V_4 , V_69 - 1 , & V_4 , & V_11 ) ;
if ( V_28 < 0 ) {
if ( F_50 ( V_28 == - V_29 ) )
break;
goto V_70;
}
V_41 = F_7 ( V_2 , V_4 , V_69 ) ;
V_12 = F_37 ( V_11 -> V_38 ) ;
V_15 = F_17 ( V_2 , V_4 , V_11 , V_12 ) ;
for ( V_44 = 0 ; V_44 < V_41 && V_13 < V_68 ; V_44 ++ , V_15 = ( void * ) V_15 + V_20 ) {
if ( ! F_32 ( V_15 ) ) {
F_46 ( V_2 , V_15 ,
V_50 ) ;
V_50 = ( void * ) V_50 + V_67 ;
V_13 ++ ;
}
}
F_39 ( V_12 ) ;
F_34 ( V_11 ) ;
}
V_28 = V_13 ;
if ( V_13 > 0 ) {
V_50 = ( void * ) V_50 - V_67 ;
* V_25 = V_50 -> V_53 + 1 ;
}
V_70:
F_51 ( & F_2 ( V_2 ) -> V_35 ) ;
return V_28 ;
}
static T_3 F_52 ( struct V_1 * V_2 , T_1 * V_25 ,
void * V_66 , unsigned V_67 , T_2 V_68 )
{
struct V_10 * V_11 ;
struct V_18 * V_33 ;
struct V_14 * V_15 ;
struct V_49 * V_50 = V_66 ;
T_1 V_8 = * V_25 , V_71 ;
unsigned long V_72 , V_73 ;
void * V_12 ;
int V_13 = 0 , V_28 ;
F_49 ( & F_2 ( V_2 ) -> V_35 ) ;
if ( V_8 == 0 ) {
V_28 = F_20 ( V_2 , & V_11 ) ;
if ( V_28 < 0 )
goto V_70;
V_12 = F_37 ( V_11 -> V_38 ) ;
V_33 = F_16 ( V_2 , V_11 , V_12 ) ;
V_8 = F_47 ( V_33 -> V_74 . V_65 ) ;
F_39 ( V_12 ) ;
F_34 ( V_11 ) ;
if ( V_8 == 0 ) {
V_28 = 0 ;
goto V_70;
}
} else if ( F_24 ( V_8 == ~ ( T_1 ) 0 ) ) {
V_28 = 0 ;
goto V_70;
}
V_72 = F_3 ( V_2 , V_8 ) ;
V_28 = F_22 ( V_2 , V_8 , 0 , & V_11 ) ;
if ( F_24 ( V_28 < 0 ) ) {
if ( V_28 == - V_29 )
V_28 = 0 ;
goto V_70;
}
V_12 = F_37 ( V_11 -> V_38 ) ;
while ( V_13 < V_68 ) {
V_15 = F_17 ( V_2 , V_8 , V_11 , V_12 ) ;
V_8 = ~ ( T_1 ) 0 ;
if ( F_24 ( F_32 ( V_15 ) ||
! F_45 ( V_15 ) ) )
break;
F_46 ( V_2 , V_15 , V_50 ) ;
V_50 = ( void * ) V_50 + V_67 ;
V_13 ++ ;
V_71 = F_47 ( V_15 -> V_64 . V_65 ) ;
if ( V_71 == 0 )
break;
V_73 = F_3 ( V_2 , V_71 ) ;
if ( V_72 != V_73 ) {
F_39 ( V_12 ) ;
F_34 ( V_11 ) ;
V_28 = F_22 ( V_2 , V_71 ,
0 , & V_11 ) ;
if ( F_24 ( V_28 < 0 ) ) {
F_15 ( V_28 == - V_29 ) ;
goto V_70;
}
V_12 = F_37 ( V_11 -> V_38 ) ;
}
V_8 = V_71 ;
V_72 = V_73 ;
}
F_39 ( V_12 ) ;
F_34 ( V_11 ) ;
* V_25 = V_8 ;
V_28 = V_13 ;
V_70:
F_51 ( & F_2 ( V_2 ) -> V_35 ) ;
return V_28 ;
}
T_3 F_53 ( struct V_1 * V_2 , T_1 * V_25 , int V_75 ,
void * V_66 , unsigned V_67 , T_2 V_68 )
{
switch ( V_75 ) {
case V_76 :
return F_48 ( V_2 , V_25 , V_66 , V_67 , V_68 ) ;
case V_77 :
return F_52 ( V_2 , V_25 , V_66 , V_67 , V_68 ) ;
default:
return - V_34 ;
}
}
int F_54 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_49 V_50 ;
T_1 V_5 = V_4 ;
T_3 V_68 ;
V_68 = F_48 ( V_2 , & V_5 , & V_50 , sizeof( V_50 ) , 1 ) ;
if ( V_68 < 0 )
return V_68 ;
else if ( V_68 == 0 || V_50 . V_53 != V_4 )
return - V_29 ;
else if ( F_55 ( & V_50 ) )
return - V_48 ;
return F_43 ( V_2 , V_4 , V_4 + 1 ) ;
}
static struct V_78 *
F_56 ( const struct V_1 * V_2 ,
T_1 V_4 ,
struct V_10 * V_11 ,
void * V_12 )
{
struct V_18 * V_33 ;
struct V_14 * V_15 ;
struct V_78 * V_79 ;
if ( V_4 != 0 ) {
V_15 = F_17 ( V_2 , V_4 , V_11 , V_12 ) ;
V_79 = & V_15 -> V_64 ;
} else {
V_33 = F_16 ( V_2 , V_11 , V_12 ) ;
V_79 = & V_33 -> V_74 ;
}
return V_79 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_10 * V_31 , * V_80 , * V_81 , * V_32 ;
struct V_18 * V_33 ;
struct V_14 * V_15 ;
struct V_78 * V_79 ;
T_1 V_8 , V_82 ;
unsigned long V_72 , V_83 ;
void * V_12 ;
int V_28 ;
if ( V_4 == 0 )
return - V_29 ;
F_30 ( & F_2 ( V_2 ) -> V_35 ) ;
V_28 = F_22 ( V_2 , V_4 , 0 , & V_32 ) ;
if ( V_28 < 0 )
goto V_36;
V_12 = F_37 ( V_32 -> V_38 ) ;
V_15 = F_17 ( V_2 , V_4 , V_32 , V_12 ) ;
if ( F_32 ( V_15 ) ) {
V_28 = - V_29 ;
F_39 ( V_12 ) ;
goto V_84;
}
if ( F_45 ( V_15 ) ) {
V_28 = 0 ;
F_39 ( V_12 ) ;
goto V_84;
}
F_39 ( V_12 ) ;
V_28 = F_20 ( V_2 , & V_31 ) ;
if ( V_28 < 0 )
goto V_84;
V_12 = F_37 ( V_31 -> V_38 ) ;
V_33 = F_16 ( V_2 , V_31 , V_12 ) ;
V_79 = & V_33 -> V_74 ;
V_80 = V_31 ;
F_58 ( V_80 ) ;
V_8 = 0 ;
V_72 = 0 ;
V_82 = F_47 ( V_79 -> V_85 ) ;
while ( V_82 > V_4 ) {
V_83 = F_3 ( V_2 , V_82 ) ;
V_8 = V_82 ;
if ( V_72 != V_83 ) {
F_39 ( V_12 ) ;
F_34 ( V_80 ) ;
V_28 = F_22 ( V_2 , V_8 ,
0 , & V_80 ) ;
if ( V_28 < 0 )
goto V_37;
V_12 = F_37 ( V_80 -> V_38 ) ;
}
V_72 = V_83 ;
V_15 = F_17 (
V_2 , V_8 , V_80 , V_12 ) ;
V_79 = & V_15 -> V_64 ;
V_82 = F_47 ( V_79 -> V_85 ) ;
}
F_39 ( V_12 ) ;
if ( V_82 != 0 ) {
V_28 = F_22 ( V_2 , V_82 , 0 ,
& V_81 ) ;
if ( V_28 < 0 )
goto V_86;
} else {
V_81 = V_31 ;
F_58 ( V_81 ) ;
}
V_12 = F_37 ( V_80 -> V_38 ) ;
V_79 = F_56 (
V_2 , V_8 , V_80 , V_12 ) ;
V_79 -> V_85 = F_59 ( V_4 ) ;
F_39 ( V_12 ) ;
V_12 = F_37 ( V_32 -> V_38 ) ;
V_15 = F_17 ( V_2 , V_4 , V_32 , V_12 ) ;
V_15 -> V_64 . V_65 = F_59 ( V_8 ) ;
V_15 -> V_64 . V_85 = F_59 ( V_82 ) ;
F_60 ( V_15 ) ;
F_39 ( V_12 ) ;
V_12 = F_37 ( V_81 -> V_38 ) ;
V_79 = F_56 (
V_2 , V_82 , V_81 , V_12 ) ;
V_79 -> V_65 = F_59 ( V_4 ) ;
F_39 ( V_12 ) ;
V_12 = F_37 ( V_31 -> V_38 ) ;
V_33 = F_16 ( V_2 , V_31 , V_12 ) ;
F_38 ( & V_33 -> V_87 , 1 ) ;
F_39 ( V_12 ) ;
F_36 ( V_81 ) ;
F_36 ( V_80 ) ;
F_36 ( V_32 ) ;
F_36 ( V_31 ) ;
F_40 ( V_2 ) ;
F_34 ( V_81 ) ;
V_86:
F_34 ( V_80 ) ;
V_37:
F_34 ( V_31 ) ;
V_84:
F_34 ( V_32 ) ;
V_36:
F_41 ( & F_2 ( V_2 ) -> V_35 ) ;
return V_28 ;
}
static int F_61 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_10 * V_31 , * V_88 , * V_81 , * V_32 ;
struct V_18 * V_33 ;
struct V_14 * V_15 ;
struct V_78 * V_79 ;
T_1 V_71 , V_82 ;
void * V_12 ;
int V_28 ;
if ( V_4 == 0 )
return - V_29 ;
F_30 ( & F_2 ( V_2 ) -> V_35 ) ;
V_28 = F_22 ( V_2 , V_4 , 0 , & V_32 ) ;
if ( V_28 < 0 )
goto V_36;
V_12 = F_37 ( V_32 -> V_38 ) ;
V_15 = F_17 ( V_2 , V_4 , V_32 , V_12 ) ;
if ( F_32 ( V_15 ) ) {
V_28 = - V_29 ;
F_39 ( V_12 ) ;
goto V_84;
}
if ( ! F_45 ( V_15 ) ) {
V_28 = 0 ;
F_39 ( V_12 ) ;
goto V_84;
}
V_79 = & V_15 -> V_64 ;
V_71 = F_47 ( V_79 -> V_65 ) ;
V_82 = F_47 ( V_79 -> V_85 ) ;
F_39 ( V_12 ) ;
V_28 = F_20 ( V_2 , & V_31 ) ;
if ( V_28 < 0 )
goto V_84;
if ( V_71 != 0 ) {
V_28 = F_22 ( V_2 , V_71 , 0 ,
& V_88 ) ;
if ( V_28 < 0 )
goto V_37;
} else {
V_88 = V_31 ;
F_58 ( V_88 ) ;
}
if ( V_82 != 0 ) {
V_28 = F_22 ( V_2 , V_82 , 0 ,
& V_81 ) ;
if ( V_28 < 0 )
goto V_89;
} else {
V_81 = V_31 ;
F_58 ( V_81 ) ;
}
V_12 = F_37 ( V_88 -> V_38 ) ;
V_79 = F_56 (
V_2 , V_71 , V_88 , V_12 ) ;
V_79 -> V_85 = F_59 ( V_82 ) ;
F_39 ( V_12 ) ;
V_12 = F_37 ( V_81 -> V_38 ) ;
V_79 = F_56 (
V_2 , V_82 , V_81 , V_12 ) ;
V_79 -> V_65 = F_59 ( V_71 ) ;
F_39 ( V_12 ) ;
V_12 = F_37 ( V_32 -> V_38 ) ;
V_15 = F_17 ( V_2 , V_4 , V_32 , V_12 ) ;
V_15 -> V_64 . V_65 = F_59 ( 0 ) ;
V_15 -> V_64 . V_85 = F_59 ( 0 ) ;
F_62 ( V_15 ) ;
F_39 ( V_12 ) ;
V_12 = F_37 ( V_31 -> V_38 ) ;
V_33 = F_16 ( V_2 , V_31 , V_12 ) ;
F_38 ( & V_33 -> V_87 , - 1 ) ;
F_39 ( V_12 ) ;
F_36 ( V_88 ) ;
F_36 ( V_81 ) ;
F_36 ( V_32 ) ;
F_36 ( V_31 ) ;
F_40 ( V_2 ) ;
F_34 ( V_81 ) ;
V_89:
F_34 ( V_88 ) ;
V_37:
F_34 ( V_31 ) ;
V_84:
F_34 ( V_32 ) ;
V_36:
F_41 ( & F_2 ( V_2 ) -> V_35 ) ;
return V_28 ;
}
int F_63 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_10 * V_11 ;
struct V_14 * V_15 ;
void * V_12 ;
int V_28 ;
if ( V_4 == 0 || V_4 >= F_29 ( V_2 ) )
return - V_29 ;
F_49 ( & F_2 ( V_2 ) -> V_35 ) ;
V_28 = F_22 ( V_2 , V_4 , 0 , & V_11 ) ;
if ( V_28 < 0 )
goto V_70;
V_12 = F_37 ( V_11 -> V_38 ) ;
V_15 = F_17 ( V_2 , V_4 , V_11 , V_12 ) ;
if ( F_32 ( V_15 ) )
V_28 = - V_29 ;
else
V_28 = F_45 ( V_15 ) ;
F_39 ( V_12 ) ;
F_34 ( V_11 ) ;
V_70:
F_51 ( & F_2 ( V_2 ) -> V_35 ) ;
return V_28 ;
}
int F_64 ( struct V_1 * V_2 , T_1 V_4 , int V_75 )
{
int V_28 ;
switch ( V_75 ) {
case V_76 :
if ( F_65 ( V_2 -> V_90 , V_4 ) )
V_28 = - V_48 ;
else
V_28 = F_61 ( V_2 , V_4 ) ;
return V_28 ;
case V_77 :
return F_57 ( V_2 , V_4 ) ;
default:
return - V_34 ;
}
}
int F_66 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_10 * V_11 ;
struct V_18 * V_33 ;
void * V_12 ;
int V_28 ;
F_49 ( & F_2 ( V_2 ) -> V_35 ) ;
V_28 = F_20 ( V_2 , & V_11 ) ;
if ( V_28 < 0 )
goto V_36;
V_12 = F_37 ( V_11 -> V_38 ) ;
V_33 = F_16 ( V_2 , V_11 , V_12 ) ;
V_92 -> V_93 = F_29 ( V_2 ) ;
V_92 -> V_94 = F_47 ( V_33 -> V_39 ) ;
V_92 -> V_95 = F_47 ( V_33 -> V_87 ) ;
F_39 ( V_12 ) ;
F_34 ( V_11 ) ;
V_36:
F_51 ( & F_2 ( V_2 ) -> V_35 ) ;
return V_28 ;
}
int F_67 ( struct V_96 * V_97 , T_2 V_98 ,
struct V_99 * V_100 , struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
int V_102 ;
if ( V_98 > V_97 -> V_103 ) {
F_44 ( V_45
L_4 ,
V_98 ) ;
return - V_34 ;
} else if ( V_98 < V_104 ) {
F_44 ( V_45
L_5 ,
V_98 ) ;
return - V_34 ;
}
V_2 = F_68 ( V_97 , NULL , V_105 ) ;
if ( F_24 ( ! V_2 ) )
return - V_106 ;
if ( ! ( V_2 -> V_107 & V_108 ) )
goto V_70;
V_102 = F_69 ( V_2 , V_109 , 0 ) ;
if ( V_102 )
goto V_110;
F_70 ( V_2 , V_98 ,
sizeof( struct V_18 ) ) ;
V_102 = F_71 ( V_2 , V_100 ) ;
if ( V_102 )
goto V_110;
F_72 ( V_2 ) ;
V_70:
* V_101 = V_2 ;
return 0 ;
V_110:
F_73 ( V_2 ) ;
return V_102 ;
}
