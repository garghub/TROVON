static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_8 ( V_3 ) ;
T_1 V_8 = V_7 -> V_9 . V_10 + V_11 ;
V_5 -> V_12 = F_9 ( V_8 ) ;
V_5 -> V_13 = F_10 ( V_8 ) ;
V_5 -> V_3 = V_3 -> V_14 ;
if ( V_7 -> V_15 & V_16 )
V_5 -> V_3 -= V_7 -> V_17 ;
}
static int F_11 ( struct V_18 * V_19 ,
unsigned int V_20 ,
T_2 V_14 )
{
struct V_21 V_22 ;
struct V_1 * V_2 ;
int V_23 ;
if ( F_12 ( V_19 -> V_24 -> V_25 ) ) {
V_22 . V_25 = V_19 -> V_24 -> V_25 ;
V_22 . V_26 = 3 ;
V_22 . V_27 [ 0 ] = 0 ;
V_22 . V_27 [ 1 ] = V_14 - 32 ;
V_22 . V_27 [ 2 ] = V_28 ;
} else if ( F_13 ( V_19 -> V_24 -> V_25 ) ) {
V_22 . V_25 = V_19 -> V_24 -> V_25 ;
V_22 . V_26 = 2 ;
V_22 . V_27 [ 0 ] = V_14 ;
V_22 . V_27 [ 1 ] = V_28 ;
} else {
return - V_29 ;
}
V_23 = F_14 ( V_19 , V_20 , 1 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_2 = F_15 ( V_19 -> V_24 , V_20 ) ;
V_2 -> V_30 -> V_31 ( V_2 , V_28 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 , unsigned int V_14 )
{
int V_32 ;
V_32 = V_14 - V_7 -> V_17 ;
if ( V_32 < 0 || V_32 >= V_7 -> V_33 ) {
F_17 ( L_1 , V_14 ) ;
return;
}
F_18 ( & V_34 ) ;
F_19 ( V_32 , V_7 -> V_35 ) ;
F_20 ( & V_34 ) ;
}
static int F_21 ( struct V_18 * V_19 , unsigned int V_20 ,
unsigned int V_36 , void * args )
{
struct V_6 * V_7 = NULL , * V_37 ;
int V_14 , V_38 , V_23 = 0 ;
F_18 ( & V_34 ) ;
F_22 (tmp, &v2m_nodes, entry) {
V_38 = F_23 ( V_37 -> V_35 , V_37 -> V_33 ) ;
if ( V_38 < V_37 -> V_33 ) {
F_24 ( V_38 , V_37 -> V_35 ) ;
V_7 = V_37 ;
break;
}
}
F_20 ( & V_34 ) ;
if ( ! V_7 )
return - V_39 ;
V_14 = V_7 -> V_17 + V_38 ;
V_23 = F_11 ( V_19 , V_20 , V_14 ) ;
if ( V_23 ) {
F_16 ( V_7 , V_14 ) ;
return V_23 ;
}
F_25 ( V_19 , V_20 , V_14 ,
& V_40 , V_7 ) ;
return 0 ;
}
static void F_26 ( struct V_18 * V_19 ,
unsigned int V_20 , unsigned int V_36 )
{
struct V_1 * V_2 = F_15 ( V_19 , V_20 ) ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
F_27 ( V_36 != 1 ) ;
F_16 ( V_7 , V_2 -> V_14 ) ;
F_28 ( V_19 , V_20 , V_36 ) ;
}
static bool F_29 ( T_3 V_41 , T_3 V_42 )
{
if ( V_41 < V_43 ) {
F_17 ( L_2 , V_41 ) ;
return false ;
}
if ( ( V_42 == 0 ) || ( V_41 + V_42 > V_44 ) ) {
F_17 ( L_3 ,
V_42 , V_44 - V_43 + 1 ) ;
return false ;
}
return true ;
}
static void F_30 ( void )
{
struct V_6 * V_7 , * V_37 ;
F_31 (v2m, tmp, &v2m_nodes, entry) {
F_32 ( & V_7 -> V_45 ) ;
F_33 ( V_7 -> V_35 ) ;
F_34 ( V_7 -> V_41 ) ;
F_35 ( F_36 ( V_7 -> V_25 ) ) ;
if ( F_13 ( V_7 -> V_25 ) )
F_37 ( V_7 -> V_25 ) ;
F_33 ( V_7 ) ;
}
}
static int F_38 ( struct V_18 * V_24 )
{
struct V_18 * V_46 , * V_47 , * V_48 ;
struct V_6 * V_7 ;
V_7 = F_39 ( & V_49 , struct V_6 , V_45 ) ;
if ( ! V_7 )
return 0 ;
V_46 = F_40 ( V_7 -> V_25 ,
& V_50 , V_7 ) ;
if ( ! V_46 ) {
F_17 ( L_4 ) ;
return - V_51 ;
}
V_46 -> V_52 = V_53 ;
V_46 -> V_24 = V_24 ;
V_47 = F_41 ( V_7 -> V_25 ,
& V_54 ,
V_46 ) ;
V_48 = F_42 ( V_7 -> V_25 ,
& V_55 ,
V_46 ) ;
if ( ! V_47 || ! V_48 ) {
F_17 ( L_5 ) ;
if ( V_48 )
F_43 ( V_48 ) ;
if ( V_47 )
F_43 ( V_47 ) ;
F_43 ( V_46 ) ;
return - V_51 ;
}
return 0 ;
}
static int T_4 F_44 ( struct V_56 * V_25 ,
T_3 V_17 , T_3 V_33 ,
struct V_57 * V_9 )
{
int V_58 ;
struct V_6 * V_7 ;
V_7 = F_45 ( sizeof( struct V_6 ) , V_59 ) ;
if ( ! V_7 ) {
F_17 ( L_6 ) ;
return - V_51 ;
}
F_46 ( & V_7 -> V_45 ) ;
V_7 -> V_25 = V_25 ;
memcpy ( & V_7 -> V_9 , V_9 , sizeof( struct V_57 ) ) ;
V_7 -> V_41 = F_47 ( V_7 -> V_9 . V_10 , F_48 ( & V_7 -> V_9 ) ) ;
if ( ! V_7 -> V_41 ) {
F_17 ( L_7 ) ;
V_58 = - V_51 ;
goto V_60;
}
if ( V_17 && V_33 ) {
V_7 -> V_17 = V_17 ;
V_7 -> V_33 = V_33 ;
} else {
T_3 V_61 = F_49 ( V_7 -> V_41 + V_62 ) ;
V_7 -> V_17 = F_50 ( V_61 ) ;
V_7 -> V_33 = F_51 ( V_61 ) ;
}
if ( ! F_29 ( V_7 -> V_17 , V_7 -> V_33 ) ) {
V_58 = - V_29 ;
goto V_63;
}
if ( F_49 ( V_7 -> V_41 + V_64 ) == V_65 )
V_7 -> V_15 |= V_16 ;
V_7 -> V_35 = F_45 ( sizeof( long ) * F_52 ( V_7 -> V_33 ) ,
V_59 ) ;
if ( ! V_7 -> V_35 ) {
V_58 = - V_51 ;
goto V_63;
}
F_53 ( & V_7 -> V_45 , & V_49 ) ;
F_54 ( L_8 , V_9 ,
V_7 -> V_17 , ( V_7 -> V_17 + V_7 -> V_33 - 1 ) ) ;
return 0 ;
V_63:
F_34 ( V_7 -> V_41 ) ;
V_60:
F_33 ( V_7 ) ;
return V_58 ;
}
static int T_4 F_55 ( struct V_56 * V_66 ,
struct V_18 * V_24 )
{
int V_58 = 0 ;
struct V_67 * V_68 = F_36 ( V_66 ) ;
struct V_67 * V_69 ;
for ( V_69 = F_56 ( V_68 , V_70 ) ; V_69 ;
V_69 = F_56 ( V_69 , V_70 ) ) {
T_3 V_17 = 0 , V_33 = 0 ;
struct V_57 V_9 ;
if ( ! F_57 ( V_69 , L_9 , NULL ) )
continue;
V_58 = F_58 ( V_69 , 0 , & V_9 ) ;
if ( V_58 ) {
F_17 ( L_10 ) ;
break;
}
if ( ! F_59 ( V_69 , L_11 ,
& V_17 ) &&
! F_59 ( V_69 , L_12 , & V_33 ) )
F_54 ( L_13 ,
V_17 , V_33 ) ;
V_58 = F_44 ( & V_69 -> V_25 , V_17 , V_33 , & V_9 ) ;
if ( V_58 ) {
F_35 ( V_69 ) ;
break;
}
}
if ( ! V_58 )
V_58 = F_38 ( V_24 ) ;
if ( V_58 )
F_30 () ;
return V_58 ;
}
static struct V_56 * F_60 ( struct V_71 * V_72 )
{
struct V_6 * V_3 ;
if ( F_61 ( V_73 <= 0 ) )
return NULL ;
V_3 = F_39 ( & V_49 , struct V_6 , V_45 ) ;
if ( ! V_3 )
return NULL ;
return V_3 -> V_25 ;
}
static int T_4
F_62 ( struct V_74 * V_75 ,
const unsigned long V_76 )
{
int V_58 ;
struct V_57 V_9 ;
T_3 V_17 = 0 , V_33 = 0 ;
struct V_77 * V_78 ;
struct V_56 * V_25 ;
V_78 = (struct V_77 * ) V_75 ;
if ( F_63 ( V_78 , V_76 ) )
return - V_29 ;
V_9 . V_10 = V_78 -> V_79 ;
V_9 . V_76 = V_78 -> V_79 + V_80 - 1 ;
V_9 . V_15 = V_81 ;
if ( V_78 -> V_15 & V_82 ) {
V_17 = V_78 -> V_83 ;
V_33 = V_78 -> V_84 ;
F_54 ( L_14 ,
V_17 , V_33 ) ;
}
V_25 = F_64 ( ( void * ) V_78 -> V_79 ) ;
if ( ! V_25 ) {
F_17 ( L_15 ) ;
return - V_29 ;
}
V_58 = F_44 ( V_25 , V_17 , V_33 , & V_9 ) ;
if ( V_58 )
F_37 ( V_25 ) ;
return V_58 ;
}
static int T_4 F_65 ( struct V_18 * V_24 )
{
int V_58 ;
if ( V_73 > 0 )
return 0 ;
V_73 = F_66 ( V_85 ,
F_62 , 0 ) ;
if ( V_73 <= 0 )
goto V_86;
V_58 = F_38 ( V_24 ) ;
if ( V_58 )
goto V_86;
F_67 ( & F_60 ) ;
return 0 ;
V_86:
F_30 () ;
return - V_29 ;
}
static int T_4 F_65 ( struct V_18 * V_24 )
{
return - V_29 ;
}
int T_4 F_68 ( struct V_56 * V_66 ,
struct V_18 * V_24 )
{
if ( F_12 ( V_66 ) )
return F_55 ( V_66 , V_24 ) ;
return F_65 ( V_24 ) ;
}
