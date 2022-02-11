static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) ( ( void * ) V_3 -> V_4 +
F_1 ( struct V_5 , V_6 ) ) ;
}
static void F_2 ( struct V_7 * V_8 , int V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
F_3 ( & V_8 -> V_13 ) ;
if ( V_8 -> V_14 )
return;
V_8 -> V_14 = 1 ;
V_11 -> V_15 = V_9 ;
V_11 -> V_16 ( V_11 ) ;
}
static void F_4 ( struct V_7 * V_8 )
{
if ( V_8 -> V_12 -> V_17 )
F_5 ( & V_8 -> V_13 , V_8 -> V_12 -> V_17 ) ;
}
static void F_6 ( struct V_7 * V_8 , int V_9 ,
T_1 * V_18 )
{
V_18 -> error = V_9 ;
F_7 ( V_8 -> V_19 ) ;
V_8 -> V_19 = NULL ;
V_8 -> V_4 . V_20 ( V_8 , V_9 ) ;
}
static inline int F_8 ( struct V_7 * V_8 )
{
struct V_21 * V_10 = V_8 -> V_12 -> V_22 ;
return V_10 -> V_23 -> V_24 ( V_10 ) ;
}
static int F_9 ( T_1 * V_18 , struct V_2 * V_25 ,
unsigned int V_26 , T_2 V_27 )
{
struct V_7 * V_8 = (struct V_7 * ) V_18 -> V_28 . V_6 ;
struct V_1 * V_29 ;
struct V_2 * V_30 , * V_3 ;
T_2 V_31 = 0 , V_32 ;
T_3 V_33 ;
int V_9 ;
bool V_34 = false ;
if ( V_8 -> V_35 )
return 0 ;
V_30 = V_8 -> V_19 ;
if ( V_30 ) {
V_29 = V_1 ( V_30 ) ;
if ( F_10 ( V_29 -> V_36 ) ) {
V_31 = V_27 <= V_29 -> V_36 ?
V_27 : V_29 -> V_36 ;
V_29 -> V_36 -= V_31 ;
return V_31 ;
}
if ( F_10 ( V_26 ) ) {
V_25 = F_11 ( V_25 , V_37 ) ;
if ( ! V_25 ) {
F_12 ( V_8 -> V_38 . V_39 ) ;
V_18 -> error = - V_40 ;
return 0 ;
}
if ( ! F_13 ( V_25 , V_26 ) ) {
F_12 ( V_8 -> V_38 . V_39 ) ;
F_7 ( V_25 ) ;
V_18 -> error = - V_40 ;
return 0 ;
}
V_34 = true ;
V_26 = 0 ;
}
if ( ! V_8 -> V_41 ) {
V_9 = F_14 ( V_30 , V_37 ) ;
if ( V_9 ) {
F_12 ( V_8 -> V_38 . V_39 ) ;
V_18 -> error = V_9 ;
return 0 ;
}
if ( F_10 ( F_15 ( V_30 ) -> V_42 ) ) {
if ( F_16 ( V_30 -> V_43 ) ) {
V_18 -> error = - V_44 ;
return 0 ;
}
V_3 = F_17 ( 0 , V_37 ) ;
if ( ! V_3 ) {
F_12 ( V_8 -> V_38 . V_39 ) ;
V_18 -> error = - V_40 ;
return 0 ;
}
V_3 -> V_45 = V_30 -> V_45 ;
V_3 -> V_46 = V_30 -> V_45 ;
V_3 -> V_47 = V_30 -> V_47 ;
* V_1 ( V_3 ) = * V_1 ( V_30 ) ;
V_8 -> V_41 = & V_30 -> V_43 ;
F_15 ( V_3 ) -> V_42 = V_30 ;
V_8 -> V_19 = V_3 ;
V_30 = V_3 ;
} else {
V_8 -> V_41 =
& F_15 ( V_30 ) -> V_42 ;
}
}
}
while ( V_31 < V_27 ) {
V_3 = F_11 ( V_25 , V_37 ) ;
if ( ! V_3 ) {
F_12 ( V_8 -> V_38 . V_39 ) ;
V_18 -> error = - V_40 ;
break;
}
V_32 = V_27 - V_31 ;
V_30 = V_8 -> V_19 ;
if ( ! V_30 ) {
V_30 = V_3 ;
V_8 -> V_19 = V_30 ;
V_8 -> V_41 = NULL ;
V_29 = V_1 ( V_30 ) ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_8 . V_48 = V_26 + V_31 ;
} else {
V_9 = F_14 ( V_3 , V_37 ) ;
if ( V_9 ) {
F_12 ( V_8 -> V_38 . V_39 ) ;
V_18 -> error = V_9 ;
break;
}
V_29 = V_1 ( V_30 ) ;
* V_8 -> V_41 = V_3 ;
V_8 -> V_41 = & V_3 -> V_43 ;
V_30 -> V_46 += V_3 -> V_45 ;
V_30 -> V_45 += V_3 -> V_45 ;
V_30 -> V_47 += V_3 -> V_47 ;
}
if ( ! V_29 -> V_8 . V_49 ) {
T_3 V_45 ;
V_45 = (* V_8 -> V_4 . V_50 )( V_8 , V_30 ) ;
if ( ! V_45 ) {
if ( ! V_29 -> V_51 ) {
F_4 ( V_8 ) ;
}
V_29 -> V_51 += V_32 ;
V_31 += V_32 ;
F_12 ( V_8 -> V_38 . V_52 ) ;
F_16 ( V_31 != V_27 ) ;
break;
} else if ( V_45 < 0 ) {
if ( V_45 == - V_53 && V_29 -> V_51 ) {
V_45 = - V_54 ;
V_8 -> V_55 = 1 ;
} else {
V_8 -> V_56 = 1 ;
}
F_6 ( V_8 , V_45 , V_18 ) ;
break;
} else if ( V_45 > V_8 -> V_12 -> V_57 ) {
F_12 ( V_8 -> V_38 . V_58 ) ;
F_6 ( V_8 , - V_59 , V_18 ) ;
break;
} else if ( V_45 <= ( T_3 ) V_30 -> V_45 -
V_3 -> V_45 - V_29 -> V_8 . V_48 ) {
F_12 ( V_8 -> V_38 . V_60 ) ;
F_6 ( V_8 , - V_61 , V_18 ) ;
break;
}
V_29 -> V_8 . V_49 = V_45 ;
}
V_33 = ( T_3 ) ( V_29 -> V_51 + V_32 ) -
V_29 -> V_8 . V_49 ;
if ( V_33 < 0 ) {
if ( V_29 -> V_8 . V_49 - V_29 -> V_51 >
F_8 ( V_8 ) ) {
if ( ! V_29 -> V_51 ) {
F_4 ( V_8 ) ;
}
V_8 -> V_62 = V_29 -> V_8 . V_49 -
V_29 -> V_51 ;
V_29 -> V_51 += V_32 ;
V_29 -> V_36 = V_32 ;
F_18 ( V_8 -> V_38 . V_63 , V_32 ) ;
V_18 -> V_64 = 0 ;
break;
}
V_29 -> V_51 += V_32 ;
V_31 += V_32 ;
F_16 ( V_31 != V_27 ) ;
break;
}
F_16 ( V_33 > V_32 ) ;
V_31 += ( V_32 - V_33 ) ;
F_3 ( & V_8 -> V_13 ) ;
V_8 -> V_19 = NULL ;
F_12 ( V_8 -> V_38 . V_65 ) ;
V_8 -> V_4 . V_66 ( V_8 , V_30 ) ;
if ( F_10 ( V_8 -> V_35 ) ) {
break;
}
}
if ( V_34 )
F_7 ( V_25 ) ;
F_18 ( V_8 -> V_38 . V_63 , V_31 ) ;
return V_31 ;
}
static int F_19 ( struct V_7 * V_8 , int V_9 )
{
return V_9 ;
}
static int F_20 ( struct V_7 * V_8 )
{
struct V_21 * V_10 = V_8 -> V_12 -> V_22 ;
T_1 V_18 ;
V_18 . V_28 . V_6 = V_8 ;
V_18 . error = 0 ;
V_18 . V_64 = 1 ;
V_10 -> V_23 -> V_67 ( V_8 -> V_12 , & V_18 , F_9 ) ;
V_18 . error = V_8 -> V_4 . V_68 ( V_8 , V_18 . error ) ;
return V_18 . error ;
}
void F_21 ( struct V_7 * V_8 )
{
if ( F_10 ( V_8 -> V_14 ) )
return;
if ( F_22 ( V_8 -> V_12 ) ) {
F_23 ( V_69 , & V_8 -> V_70 ) ;
return;
}
if ( V_8 -> V_35 )
return;
if ( V_8 -> V_62 ) {
if ( F_8 ( V_8 ) >= V_8 -> V_62 )
V_8 -> V_62 = 0 ;
else
return;
}
if ( F_20 ( V_8 ) == - V_40 )
F_23 ( V_69 , & V_8 -> V_70 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
T_1 V_71 ;
struct V_10 * V_11 = V_8 -> V_12 ;
F_25 ( V_11 ) ;
if ( F_10 ( V_8 -> V_14 ) )
goto V_72;
if ( V_8 -> V_35 )
goto V_72;
V_71 . V_28 . V_6 = V_8 ;
if ( F_20 ( V_8 ) == - V_40 )
F_23 ( V_69 , & V_8 -> V_70 ) ;
V_72:
F_26 ( V_11 ) ;
}
static void F_27 ( struct V_73 * V_74 )
{
F_24 ( F_28 ( V_74 , struct V_7 , V_70 ) ) ;
}
static void F_29 ( unsigned long V_28 )
{
struct V_7 * V_8 = (struct V_7 * ) V_28 ;
F_12 ( V_8 -> V_38 . V_75 ) ;
F_25 ( V_8 -> V_12 ) ;
V_8 -> V_4 . V_20 ( V_8 , V_76 ) ;
F_26 ( V_8 -> V_12 ) ;
}
int F_30 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_77 * V_4 )
{
struct V_21 * V_10 = V_11 -> V_22 ;
if ( ! V_4 || ! V_4 -> V_66 || ! V_4 -> V_50 )
return - V_44 ;
if ( ! V_10 -> V_23 -> V_67 || ! V_10 -> V_23 -> V_24 )
return - V_78 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_12 = V_11 ;
F_31 ( & V_8 -> V_13 , F_29 ,
( unsigned long ) V_8 ) ;
F_32 ( & V_8 -> V_70 , F_27 ) ;
V_8 -> V_4 . V_66 = V_4 -> V_66 ;
V_8 -> V_4 . V_50 = V_4 -> V_50 ;
V_8 -> V_4 . V_68 = V_4 -> V_68 ? : F_19 ;
V_8 -> V_4 . V_20 = V_4 -> V_20 ? : F_2 ;
return 0 ;
}
void F_33 ( struct V_7 * V_8 )
{
V_8 -> V_35 = 0 ;
F_34 () ;
F_23 ( V_69 , & V_8 -> V_70 ) ;
}
void F_35 ( struct V_7 * V_8 )
{
F_16 ( ! V_8 -> V_14 ) ;
F_36 ( & V_8 -> V_13 ) ;
F_37 ( & V_8 -> V_70 ) ;
if ( V_8 -> V_19 ) {
F_7 ( V_8 -> V_19 ) ;
V_8 -> V_19 = NULL ;
}
}
void F_38 ( struct V_7 * V_8 )
{
V_8 -> V_14 = 1 ;
}
void F_39 ( struct V_7 * V_8 )
{
F_23 ( V_69 , & V_8 -> V_70 ) ;
}
static int T_4 F_40 ( void )
{
V_69 = F_41 ( L_1 ) ;
return 0 ;
}
static void T_5 F_42 ( void )
{
F_43 ( V_69 ) ;
}
