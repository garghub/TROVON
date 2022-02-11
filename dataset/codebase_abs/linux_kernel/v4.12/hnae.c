static void
F_1 ( T_1 * V_1 , struct V_2 * V_3 , struct V_2 * V_4 )
{
unsigned long V_5 ;
F_2 ( V_1 , V_5 ) ;
F_3 ( V_3 , V_4 ) ;
F_4 ( V_1 , V_5 ) ;
}
static void F_5 ( T_1 * V_1 , struct V_2 * V_3 )
{
unsigned long V_5 ;
F_2 ( V_1 , V_5 ) ;
F_6 ( V_3 ) ;
F_4 ( V_1 , V_5 ) ;
}
static int F_7 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
unsigned int V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_10 ) ;
if ( ! V_12 )
return - V_13 ;
V_9 -> V_14 = V_12 ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
V_9 -> V_17 = F_10 ( V_12 ) ;
V_9 -> V_18 = F_11 ( V_7 ) ;
V_9 -> type = V_19 ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( F_13 ( ! V_9 -> V_14 ) )
return;
if ( V_9 -> type == V_20 )
F_14 ( (struct V_21 * ) V_9 -> V_14 ) ;
else if ( F_13 ( F_15 ( V_7 ) ) )
F_16 ( (struct V_11 * ) V_9 -> V_14 ) ;
V_9 -> V_14 = NULL ;
}
static int F_17 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_9 -> V_22 = F_18 ( F_19 ( V_7 ) , V_9 -> V_14 , 0 ,
V_9 -> V_18 , F_20 ( V_7 ) ) ;
if ( F_21 ( F_19 ( V_7 ) , V_9 -> V_22 ) )
return - V_23 ;
return 0 ;
}
static void F_22 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( V_9 -> type == V_20 )
F_23 ( F_19 ( V_7 ) , V_9 -> V_22 , V_9 -> V_18 ,
F_20 ( V_7 ) ) ;
else
F_24 ( F_19 ( V_7 ) , V_9 -> V_22 , V_9 -> V_18 ,
F_20 ( V_7 ) ) ;
}
static int F_25 ( struct V_24 * V_25 , const void * V_26 )
{
struct V_27 * V_28 = F_26 ( V_25 ) ;
if ( F_27 ( V_28 -> V_25 ) )
return ( V_26 == & V_28 -> V_25 -> V_29 -> V_30 ) ;
else if ( F_28 ( V_28 -> V_25 -> V_30 ) )
return ( V_26 == V_28 -> V_25 -> V_30 ) ;
F_29 ( V_25 , L_1 ) ;
return 0 ;
}
static struct V_27 * F_30 ( const struct V_31 * V_30 )
{
struct V_24 * V_25 ;
F_31 ( ! V_30 ) ;
V_25 = F_32 ( V_32 , NULL , V_30 , F_25 ) ;
return V_25 ? F_26 ( V_25 ) : NULL ;
}
static void F_33 ( struct V_6 * V_7 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_7 -> V_34 ; V_33 ++ )
F_34 ( V_7 , V_33 ) ;
}
static int F_35 ( struct V_6 * V_7 )
{
int V_33 , V_35 , V_36 ;
for ( V_33 = 0 ; V_33 < V_7 -> V_34 ; V_33 ++ ) {
V_36 = F_36 ( V_7 , V_33 ) ;
if ( V_36 )
goto V_37;
}
return 0 ;
V_37:
for ( V_35 = V_33 - 1 ; V_35 >= 0 ; V_35 -- )
F_34 ( V_7 , V_35 ) ;
return V_36 ;
}
static void F_37 ( struct V_6 * V_7 )
{
F_33 ( V_7 ) ;
F_23 ( F_19 ( V_7 ) , V_7 -> V_38 ,
V_7 -> V_34 * sizeof( V_7 -> V_39 [ 0 ] ) ,
F_20 ( V_7 ) ) ;
V_7 -> V_38 = 0 ;
F_38 ( V_7 -> V_39 ) ;
V_7 -> V_39 = NULL ;
}
static int F_39 ( struct V_6 * V_7 )
{
int V_40 = V_7 -> V_34 * sizeof( V_7 -> V_39 [ 0 ] ) ;
V_7 -> V_39 = F_40 ( V_40 , V_41 ) ;
if ( ! V_7 -> V_39 )
return - V_13 ;
V_7 -> V_38 = F_41 ( F_19 ( V_7 ) ,
V_7 -> V_39 , V_40 , F_20 ( V_7 ) ) ;
if ( F_21 ( F_19 ( V_7 ) , V_7 -> V_38 ) ) {
V_7 -> V_38 = 0 ;
F_38 ( V_7 -> V_39 ) ;
V_7 -> V_39 = NULL ;
return - V_13 ;
}
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
F_37 ( V_7 ) ;
F_38 ( V_7 -> V_42 ) ;
V_7 -> V_42 = NULL ;
V_7 -> V_43 = 0 ;
V_7 -> V_44 = 0 ;
}
static int
F_43 ( struct V_45 * V_46 , struct V_6 * V_7 , int V_5 )
{
int V_36 ;
if ( V_7 -> V_34 <= 0 || V_7 -> V_47 <= 0 )
return - V_48 ;
V_7 -> V_46 = V_46 ;
V_7 -> V_5 = V_5 ;
F_44 ( & V_7 -> V_1 ) ;
assert ( ! V_7 -> V_39 && ! V_7 -> V_42 && ! V_7 -> V_38 ) ;
assert ( V_7 -> V_44 == 0 ) ;
assert ( V_7 -> V_43 == 0 ) ;
V_7 -> V_42 = F_45 ( V_7 -> V_34 , sizeof( V_7 -> V_42 [ 0 ] ) ,
V_41 ) ;
if ( ! V_7 -> V_42 ) {
V_36 = - V_13 ;
goto V_49;
}
V_36 = F_39 ( V_7 ) ;
if ( V_36 )
goto V_50;
if ( F_15 ( V_7 ) ) {
V_36 = F_35 ( V_7 ) ;
if ( V_36 )
goto V_51;
}
return 0 ;
V_51:
F_37 ( V_7 ) ;
V_50:
F_38 ( V_7 -> V_42 ) ;
V_7 -> V_42 = NULL ;
V_49:
return V_36 ;
}
static int F_46 ( struct V_52 * V_53 , struct V_45 * V_46 ,
struct V_27 * V_25 )
{
int V_36 ;
V_46 -> V_25 = V_25 ;
V_46 -> V_54 = V_53 ;
V_36 = F_43 ( V_46 , & V_46 -> V_55 , V_46 -> V_55 . V_5 | V_56 ) ;
if ( V_36 )
goto V_49;
V_36 = F_43 ( V_46 , & V_46 -> V_57 , V_46 -> V_57 . V_5 & ~ V_56 ) ;
if ( V_36 )
goto V_58;
if ( V_25 -> V_59 -> V_60 )
V_25 -> V_59 -> V_60 ( V_46 ) ;
return 0 ;
V_58:
F_42 ( & V_46 -> V_55 ) ;
V_49:
return V_36 ;
}
static void F_47 ( struct V_45 * V_46 )
{
if ( V_46 -> V_25 -> V_59 -> V_61 )
V_46 -> V_25 -> V_59 -> V_61 ( V_46 ) ;
F_42 ( & V_46 -> V_55 ) ;
F_42 ( & V_46 -> V_57 ) ;
}
int F_48 ( struct V_62 * V_63 )
{
return F_49 ( & V_64 , V_63 ) ;
}
void F_50 ( struct V_62 * V_63 )
{
if ( F_51 ( & V_64 , V_63 ) )
F_29 ( NULL , L_2 ) ;
}
int F_52 ( struct V_52 * V_54 )
{
int V_33 , V_35 ;
int V_36 ;
for ( V_33 = 0 ; V_33 < V_54 -> V_65 ; V_33 ++ )
F_47 ( V_54 -> V_66 [ V_33 ] ) ;
if ( V_54 -> V_25 -> V_59 -> V_67 )
V_54 -> V_25 -> V_59 -> V_67 ( V_54 ) ;
for ( V_33 = 0 ; V_33 < V_54 -> V_65 ; V_33 ++ ) {
V_36 = F_46 ( V_54 , V_54 -> V_66 [ V_33 ] , V_54 -> V_25 ) ;
if ( V_36 )
goto V_68;
}
return 0 ;
V_68:
for ( V_35 = V_33 - 1 ; V_35 >= 0 ; V_35 -- )
F_47 ( V_54 -> V_66 [ V_35 ] ) ;
return V_36 ;
}
struct V_52 * F_53 ( struct V_24 * V_69 ,
const struct V_31 * V_30 ,
T_2 V_70 ,
struct V_71 * V_72 )
{
struct V_27 * V_25 ;
struct V_52 * V_54 ;
int V_33 , V_35 ;
int V_36 ;
V_25 = F_30 ( V_30 ) ;
if ( ! V_25 )
return F_54 ( - V_73 ) ;
V_54 = V_25 -> V_59 -> V_74 ( V_25 , V_70 ) ;
if ( F_55 ( V_54 ) ) {
F_56 ( & V_25 -> V_75 ) ;
return V_54 ;
}
V_54 -> V_25 = V_25 ;
V_54 -> V_69 = V_69 ;
V_54 -> V_72 = V_72 ? V_72 : & V_76 ;
V_54 -> V_77 = V_70 ;
for ( V_33 = 0 ; V_33 < V_54 -> V_65 ; V_33 ++ ) {
V_36 = F_46 ( V_54 , V_54 -> V_66 [ V_33 ] , V_25 ) ;
if ( V_36 )
goto V_68;
}
F_57 ( V_25 -> V_78 ) ;
F_1 ( & V_25 -> V_1 , & V_54 -> V_3 , & V_25 -> V_79 ) ;
return V_54 ;
V_68:
for ( V_35 = V_33 - 1 ; V_35 >= 0 ; V_35 -- )
F_47 ( V_54 -> V_66 [ V_35 ] ) ;
F_56 ( & V_25 -> V_75 ) ;
return F_54 ( - V_13 ) ;
}
void F_58 ( struct V_52 * V_53 )
{
struct V_27 * V_25 = V_53 -> V_25 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_53 -> V_65 ; V_33 ++ )
F_47 ( V_53 -> V_66 [ V_33 ] ) ;
if ( V_53 -> V_25 -> V_59 -> V_67 )
V_53 -> V_25 -> V_59 -> V_67 ( V_53 ) ;
F_5 ( & V_25 -> V_1 , & V_53 -> V_3 ) ;
if ( V_25 -> V_59 -> V_80 )
V_25 -> V_59 -> V_80 ( V_53 ) ;
F_59 ( V_25 -> V_78 ) ;
F_56 ( & V_25 -> V_75 ) ;
}
static void F_60 ( struct V_24 * V_25 )
{
}
int F_61 ( struct V_27 * V_28 , struct V_81 * V_78 )
{
static T_3 V_82 = F_62 ( - 1 ) ;
int V_36 ;
if ( ! V_28 -> V_25 )
return - V_73 ;
if ( ! V_28 -> V_59 || ! V_28 -> V_59 -> V_74 ||
! V_28 -> V_59 -> V_83 ||
! V_28 -> V_59 -> V_84 || ! V_28 -> V_59 -> V_85 )
return - V_48 ;
V_28 -> V_78 = V_78 ;
V_28 -> V_82 = ( int ) F_63 ( & V_82 ) ;
V_28 -> V_75 . V_86 = V_28 -> V_25 ;
V_28 -> V_75 . V_87 = V_32 ;
V_28 -> V_75 . V_88 = F_60 ;
( void ) F_64 ( & V_28 -> V_75 , L_3 , V_28 -> V_82 ) ;
V_36 = F_65 ( & V_28 -> V_75 ) ;
if ( V_36 )
return V_36 ;
F_57 ( V_89 ) ;
F_66 ( & V_28 -> V_79 ) ;
F_44 ( & V_28 -> V_1 ) ;
V_36 = F_67 ( & V_64 , V_90 , NULL ) ;
if ( V_36 )
F_68 ( V_28 -> V_25 ,
L_4 , V_28 -> V_91 ) ;
return 0 ;
}
void F_69 ( struct V_27 * V_28 )
{
F_70 ( & V_28 -> V_75 ) ;
F_59 ( V_89 ) ;
}
static int T_4 F_71 ( void )
{
V_32 = F_72 ( V_89 , L_5 ) ;
return F_73 ( V_32 ) ;
}
static void T_5 F_74 ( void )
{
F_75 ( V_32 ) ;
}
