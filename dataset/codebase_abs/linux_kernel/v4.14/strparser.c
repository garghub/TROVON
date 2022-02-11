static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) ( ( void * ) V_3 -> V_4 +
F_1 ( struct V_5 , V_6 ) ) ;
}
static void F_2 ( struct V_7 * V_8 , int V_9 )
{
F_3 ( & V_8 -> V_10 ) ;
if ( V_8 -> V_11 )
return;
V_8 -> V_11 = 1 ;
if ( V_8 -> V_12 ) {
struct V_13 * V_12 = V_8 -> V_12 ;
V_12 -> V_14 = V_9 ;
V_12 -> V_15 ( V_12 ) ;
}
}
static void F_4 ( struct V_7 * V_8 , long V_16 )
{
if ( V_16 )
F_5 ( V_17 , & V_8 -> V_10 , V_16 ) ;
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
if ( V_8 -> V_12 ) {
struct V_21 * V_13 = V_8 -> V_12 -> V_22 ;
return V_13 -> V_23 -> V_24 ( V_13 ) ;
}
return V_25 ;
}
static int F_9 ( T_1 * V_18 , struct V_2 * V_26 ,
unsigned int V_27 , T_2 V_28 ,
T_2 V_29 , long V_16 )
{
struct V_7 * V_8 = (struct V_7 * ) V_18 -> V_30 . V_6 ;
struct V_1 * V_31 ;
struct V_2 * V_32 , * V_3 ;
T_2 V_33 = 0 , V_34 ;
T_3 V_35 ;
int V_9 ;
bool V_36 = false ;
if ( V_8 -> V_37 )
return 0 ;
V_32 = V_8 -> V_19 ;
if ( V_32 ) {
V_31 = V_1 ( V_32 ) ;
if ( F_10 ( V_31 -> V_38 ) ) {
V_33 = V_28 <= V_31 -> V_38 ?
V_28 : V_31 -> V_38 ;
V_31 -> V_38 -= V_33 ;
return V_33 ;
}
if ( F_10 ( V_27 ) ) {
V_26 = F_11 ( V_26 , V_39 ) ;
if ( ! V_26 ) {
F_12 ( V_8 -> V_40 . V_41 ) ;
V_18 -> error = - V_42 ;
return 0 ;
}
if ( ! F_13 ( V_26 , V_27 ) ) {
F_12 ( V_8 -> V_40 . V_41 ) ;
F_7 ( V_26 ) ;
V_18 -> error = - V_42 ;
return 0 ;
}
V_36 = true ;
V_27 = 0 ;
}
if ( ! V_8 -> V_43 ) {
V_9 = F_14 ( V_32 , V_39 ) ;
if ( V_9 ) {
F_12 ( V_8 -> V_40 . V_41 ) ;
V_18 -> error = V_9 ;
return 0 ;
}
if ( F_10 ( F_15 ( V_32 ) -> V_44 ) ) {
if ( F_16 ( V_32 -> V_45 ) ) {
V_18 -> error = - V_46 ;
return 0 ;
}
V_3 = F_17 ( 0 , V_39 ) ;
if ( ! V_3 ) {
F_12 ( V_8 -> V_40 . V_41 ) ;
V_18 -> error = - V_42 ;
return 0 ;
}
V_3 -> V_47 = V_32 -> V_47 ;
V_3 -> V_48 = V_32 -> V_47 ;
V_3 -> V_49 = V_32 -> V_49 ;
* V_1 ( V_3 ) = * V_1 ( V_32 ) ;
V_8 -> V_43 = & V_32 -> V_45 ;
F_15 ( V_3 ) -> V_44 = V_32 ;
V_8 -> V_19 = V_3 ;
V_32 = V_3 ;
} else {
V_8 -> V_43 =
& F_15 ( V_32 ) -> V_44 ;
}
}
}
while ( V_33 < V_28 ) {
V_3 = F_11 ( V_26 , V_39 ) ;
if ( ! V_3 ) {
F_12 ( V_8 -> V_40 . V_41 ) ;
V_18 -> error = - V_42 ;
break;
}
V_34 = V_28 - V_33 ;
V_32 = V_8 -> V_19 ;
if ( ! V_32 ) {
V_32 = V_3 ;
V_8 -> V_19 = V_32 ;
V_8 -> V_43 = NULL ;
V_31 = V_1 ( V_32 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_8 . V_50 = V_27 + V_33 ;
} else {
V_9 = F_14 ( V_3 , V_39 ) ;
if ( V_9 ) {
F_12 ( V_8 -> V_40 . V_41 ) ;
V_18 -> error = V_9 ;
break;
}
V_31 = V_1 ( V_32 ) ;
* V_8 -> V_43 = V_3 ;
V_8 -> V_43 = & V_3 -> V_45 ;
V_32 -> V_48 += V_3 -> V_47 ;
V_32 -> V_47 += V_3 -> V_47 ;
V_32 -> V_49 += V_3 -> V_49 ;
}
if ( ! V_31 -> V_8 . V_51 ) {
T_3 V_47 ;
V_47 = (* V_8 -> V_4 . V_52 )( V_8 , V_32 ) ;
if ( ! V_47 ) {
if ( ! V_31 -> V_53 ) {
F_4 ( V_8 , V_16 ) ;
}
V_31 -> V_53 += V_34 ;
V_33 += V_34 ;
F_12 ( V_8 -> V_40 . V_54 ) ;
F_16 ( V_33 != V_28 ) ;
break;
} else if ( V_47 < 0 ) {
if ( V_47 == - V_55 && V_31 -> V_53 ) {
V_47 = - V_56 ;
V_8 -> V_57 = 1 ;
} else {
V_8 -> V_58 = 1 ;
}
F_6 ( V_8 , V_47 , V_18 ) ;
break;
} else if ( V_47 > V_29 ) {
F_12 ( V_8 -> V_40 . V_59 ) ;
F_6 ( V_8 , - V_60 , V_18 ) ;
break;
} else if ( V_47 <= ( T_3 ) V_32 -> V_47 -
V_3 -> V_47 - V_31 -> V_8 . V_50 ) {
F_12 ( V_8 -> V_40 . V_61 ) ;
F_6 ( V_8 , - V_62 , V_18 ) ;
break;
}
V_31 -> V_8 . V_51 = V_47 ;
}
V_35 = ( T_3 ) ( V_31 -> V_53 + V_34 ) -
V_31 -> V_8 . V_51 ;
if ( V_35 < 0 ) {
if ( V_31 -> V_8 . V_51 - V_31 -> V_53 >
F_8 ( V_8 ) ) {
if ( ! V_31 -> V_53 ) {
F_4 ( V_8 , V_16 ) ;
}
V_8 -> V_63 = V_31 -> V_8 . V_51 -
V_31 -> V_53 ;
V_31 -> V_53 += V_34 ;
V_31 -> V_38 = V_34 ;
F_18 ( V_8 -> V_40 . V_64 , V_34 ) ;
V_18 -> V_65 = 0 ;
break;
}
V_31 -> V_53 += V_34 ;
V_33 += V_34 ;
F_16 ( V_33 != V_28 ) ;
break;
}
F_16 ( V_35 > V_34 ) ;
V_33 += ( V_34 - V_35 ) ;
F_3 ( & V_8 -> V_10 ) ;
V_8 -> V_19 = NULL ;
F_12 ( V_8 -> V_40 . V_66 ) ;
V_8 -> V_4 . V_67 ( V_8 , V_32 ) ;
if ( F_10 ( V_8 -> V_37 ) ) {
break;
}
}
if ( V_36 )
F_7 ( V_26 ) ;
F_18 ( V_8 -> V_40 . V_64 , V_33 ) ;
return V_33 ;
}
int F_19 ( struct V_7 * V_8 , struct V_2 * V_26 ,
unsigned int V_27 , T_2 V_28 ,
T_2 V_29 , long V_16 )
{
T_1 V_18 ;
V_18 . V_30 . V_6 = V_8 ;
return F_9 ( & V_18 , V_26 , V_27 , V_28 ,
V_29 , V_16 ) ;
}
static int F_20 ( T_1 * V_18 , struct V_2 * V_26 ,
unsigned int V_27 , T_2 V_28 )
{
struct V_7 * V_8 = (struct V_7 * ) V_18 -> V_30 . V_6 ;
return F_9 ( V_18 , V_26 , V_27 , V_28 ,
V_8 -> V_12 -> V_68 , V_8 -> V_12 -> V_69 ) ;
}
static int F_21 ( struct V_7 * V_8 , int V_9 )
{
return V_9 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_21 * V_13 = V_8 -> V_12 -> V_22 ;
T_1 V_18 ;
if ( F_10 ( ! V_13 || ! V_13 -> V_23 || ! V_13 -> V_23 -> V_70 ) )
return - V_71 ;
V_18 . V_30 . V_6 = V_8 ;
V_18 . error = 0 ;
V_18 . V_65 = 1 ;
V_13 -> V_23 -> V_70 ( V_8 -> V_12 , & V_18 , F_20 ) ;
V_18 . error = V_8 -> V_4 . V_72 ( V_8 , V_18 . error ) ;
return V_18 . error ;
}
void F_23 ( struct V_7 * V_8 )
{
if ( F_10 ( V_8 -> V_11 ) )
return;
if ( F_24 ( V_8 -> V_12 ) ) {
F_25 ( V_17 , & V_8 -> V_73 ) ;
return;
}
if ( V_8 -> V_37 )
return;
if ( V_8 -> V_63 ) {
if ( F_8 ( V_8 ) >= V_8 -> V_63 )
V_8 -> V_63 = 0 ;
else
return;
}
if ( F_22 ( V_8 ) == - V_42 )
F_25 ( V_17 , & V_8 -> V_73 ) ;
}
static void F_26 ( struct V_7 * V_8 )
{
T_1 V_74 ;
V_8 -> V_4 . V_75 ( V_8 ) ;
if ( F_10 ( V_8 -> V_11 ) )
goto V_76;
if ( V_8 -> V_37 )
goto V_76;
V_74 . V_30 . V_6 = V_8 ;
if ( F_22 ( V_8 ) == - V_42 )
F_25 ( V_17 , & V_8 -> V_73 ) ;
V_76:
V_8 -> V_4 . V_77 ( V_8 ) ;
}
static void F_27 ( struct V_78 * V_79 )
{
F_26 ( F_28 ( V_79 , struct V_7 , V_73 ) ) ;
}
static void F_29 ( struct V_78 * V_79 )
{
struct V_7 * V_8 = F_28 ( V_79 , struct V_7 ,
V_10 . V_73 ) ;
F_12 ( V_8 -> V_40 . V_80 ) ;
V_8 -> V_4 . V_75 ( V_8 ) ;
V_8 -> V_4 . V_20 ( V_8 , V_81 ) ;
V_8 -> V_4 . V_77 ( V_8 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
F_31 ( V_8 -> V_12 ) ;
}
static void F_32 ( struct V_7 * V_8 )
{
F_33 ( V_8 -> V_12 ) ;
}
int F_34 ( struct V_7 * V_8 , struct V_13 * V_12 ,
const struct V_82 * V_4 )
{
if ( ! V_4 || ! V_4 -> V_67 || ! V_4 -> V_52 )
return - V_46 ;
if ( ! V_12 ) {
if ( ! V_4 -> V_75 || ! V_4 -> V_77 )
return - V_46 ;
}
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_12 = V_12 ;
V_8 -> V_4 . V_75 = V_4 -> V_75 ? : F_30 ;
V_8 -> V_4 . V_77 = V_4 -> V_77 ? : F_32 ;
V_8 -> V_4 . V_67 = V_4 -> V_67 ;
V_8 -> V_4 . V_52 = V_4 -> V_52 ;
V_8 -> V_4 . V_72 = V_4 -> V_72 ? : F_21 ;
V_8 -> V_4 . V_20 = V_4 -> V_20 ? : F_2 ;
F_35 ( & V_8 -> V_10 , F_29 ) ;
F_36 ( & V_8 -> V_73 , F_27 ) ;
return 0 ;
}
void F_37 ( struct V_7 * V_8 )
{
V_8 -> V_37 = 0 ;
F_38 () ;
F_25 ( V_17 , & V_8 -> V_73 ) ;
}
void F_39 ( struct V_7 * V_8 )
{
F_16 ( ! V_8 -> V_11 ) ;
F_40 ( & V_8 -> V_10 ) ;
F_41 ( & V_8 -> V_73 ) ;
if ( V_8 -> V_19 ) {
F_7 ( V_8 -> V_19 ) ;
V_8 -> V_19 = NULL ;
}
}
void F_42 ( struct V_7 * V_8 )
{
V_8 -> V_11 = 1 ;
}
void F_43 ( struct V_7 * V_8 )
{
F_25 ( V_17 , & V_8 -> V_73 ) ;
}
static int T_4 F_44 ( void )
{
V_17 = F_45 ( L_1 ) ;
return 0 ;
}
static void T_5 F_46 ( void )
{
F_47 ( V_17 ) ;
}
