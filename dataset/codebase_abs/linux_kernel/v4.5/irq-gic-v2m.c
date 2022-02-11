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
static int F_7 ( struct V_1 * V_1 ,
const struct V_3 * V_4 , bool V_5 )
{
int V_6 ;
V_6 = F_8 ( V_1 , V_4 , V_5 ) ;
if ( V_6 == V_7 )
V_6 = V_8 ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_10 ( V_9 ) ;
T_1 V_14 = V_13 -> V_15 . V_16 + V_17 ;
V_11 -> V_18 = F_11 ( V_14 ) ;
V_11 -> V_19 = F_12 ( V_14 ) ;
V_11 -> V_9 = V_9 -> V_20 ;
if ( V_13 -> V_21 & V_22 )
V_11 -> V_9 -= V_13 -> V_23 ;
}
static int F_13 ( struct V_24 * V_25 ,
unsigned int V_26 ,
T_2 V_20 )
{
struct V_27 V_28 ;
struct V_1 * V_2 ;
int V_29 ;
if ( F_14 ( V_25 -> V_30 -> V_31 ) ) {
V_28 . V_31 = V_25 -> V_30 -> V_31 ;
V_28 . V_32 = 3 ;
V_28 . V_33 [ 0 ] = 0 ;
V_28 . V_33 [ 1 ] = V_20 - 32 ;
V_28 . V_33 [ 2 ] = V_34 ;
} else if ( F_15 ( V_25 -> V_30 -> V_31 ) ) {
V_28 . V_31 = V_25 -> V_30 -> V_31 ;
V_28 . V_32 = 2 ;
V_28 . V_33 [ 0 ] = V_20 ;
V_28 . V_33 [ 1 ] = V_34 ;
} else {
return - V_35 ;
}
V_29 = F_16 ( V_25 , V_26 , 1 , & V_28 ) ;
if ( V_29 )
return V_29 ;
V_2 = F_17 ( V_25 -> V_30 , V_26 ) ;
V_2 -> V_36 -> V_37 ( V_2 , V_34 ) ;
return 0 ;
}
static void F_18 ( struct V_12 * V_13 , unsigned int V_20 )
{
int V_38 ;
V_38 = V_20 - V_13 -> V_23 ;
if ( V_38 < 0 || V_38 >= V_13 -> V_39 ) {
F_19 ( L_1 , V_20 ) ;
return;
}
F_20 ( & V_40 ) ;
F_21 ( V_38 , V_13 -> V_41 ) ;
F_22 ( & V_40 ) ;
}
static int F_23 ( struct V_24 * V_25 , unsigned int V_26 ,
unsigned int V_42 , void * args )
{
struct V_12 * V_13 = NULL , * V_43 ;
int V_20 , V_44 , V_29 = 0 ;
F_20 ( & V_40 ) ;
F_24 (tmp, &v2m_nodes, entry) {
V_44 = F_25 ( V_43 -> V_41 , V_43 -> V_39 ) ;
if ( V_44 < V_43 -> V_39 ) {
F_26 ( V_44 , V_43 -> V_41 ) ;
V_13 = V_43 ;
break;
}
}
F_22 ( & V_40 ) ;
if ( ! V_13 )
return - V_45 ;
V_20 = V_13 -> V_23 + V_44 ;
V_29 = F_13 ( V_25 , V_26 , V_20 ) ;
if ( V_29 ) {
F_18 ( V_13 , V_20 ) ;
return V_29 ;
}
F_27 ( V_25 , V_26 , V_20 ,
& V_46 , V_13 ) ;
return 0 ;
}
static void F_28 ( struct V_24 * V_25 ,
unsigned int V_26 , unsigned int V_42 )
{
struct V_1 * V_2 = F_17 ( V_25 , V_26 ) ;
struct V_12 * V_13 = F_10 ( V_2 ) ;
F_29 ( V_42 != 1 ) ;
F_18 ( V_13 , V_2 -> V_20 ) ;
F_30 ( V_25 , V_26 , V_42 ) ;
}
static bool F_31 ( T_3 V_47 , T_3 V_48 )
{
if ( V_47 < V_49 ) {
F_19 ( L_2 , V_47 ) ;
return false ;
}
if ( ( V_48 == 0 ) || ( V_47 + V_48 > V_50 ) ) {
F_19 ( L_3 ,
V_48 , V_50 - V_49 + 1 ) ;
return false ;
}
return true ;
}
static void F_32 ( void )
{
struct V_12 * V_13 , * V_43 ;
F_33 (v2m, tmp, &v2m_nodes, entry) {
F_34 ( & V_13 -> V_51 ) ;
F_35 ( V_13 -> V_41 ) ;
F_36 ( V_13 -> V_47 ) ;
F_37 ( F_38 ( V_13 -> V_31 ) ) ;
if ( F_15 ( V_13 -> V_31 ) )
F_39 ( V_13 -> V_31 ) ;
F_35 ( V_13 ) ;
}
}
static int F_40 ( struct V_24 * V_30 )
{
struct V_24 * V_52 , * V_53 , * V_54 ;
struct V_12 * V_13 ;
V_13 = F_41 ( & V_55 , struct V_12 , V_51 ) ;
if ( ! V_13 )
return 0 ;
V_52 = F_42 ( V_13 -> V_31 ,
& V_56 , V_13 ) ;
if ( ! V_52 ) {
F_19 ( L_4 ) ;
return - V_57 ;
}
V_52 -> V_58 = V_59 ;
V_52 -> V_30 = V_30 ;
V_53 = F_43 ( V_13 -> V_31 ,
& V_60 ,
V_52 ) ;
V_54 = F_44 ( V_13 -> V_31 ,
& V_61 ,
V_52 ) ;
if ( ! V_53 || ! V_54 ) {
F_19 ( L_5 ) ;
if ( V_54 )
F_45 ( V_54 ) ;
if ( V_53 )
F_45 ( V_53 ) ;
F_45 ( V_52 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_4 F_46 ( struct V_62 * V_31 ,
T_3 V_23 , T_3 V_39 ,
struct V_63 * V_15 )
{
int V_6 ;
struct V_12 * V_13 ;
V_13 = F_47 ( sizeof( struct V_12 ) , V_64 ) ;
if ( ! V_13 ) {
F_19 ( L_6 ) ;
return - V_57 ;
}
F_48 ( & V_13 -> V_51 ) ;
V_13 -> V_31 = V_31 ;
memcpy ( & V_13 -> V_15 , V_15 , sizeof( struct V_63 ) ) ;
V_13 -> V_47 = F_49 ( V_13 -> V_15 . V_16 , F_50 ( & V_13 -> V_15 ) ) ;
if ( ! V_13 -> V_47 ) {
F_19 ( L_7 ) ;
V_6 = - V_57 ;
goto V_65;
}
if ( V_23 && V_39 ) {
V_13 -> V_23 = V_23 ;
V_13 -> V_39 = V_39 ;
} else {
T_3 V_66 = F_51 ( V_13 -> V_47 + V_67 ) ;
V_13 -> V_23 = F_52 ( V_66 ) ;
V_13 -> V_39 = F_53 ( V_66 ) ;
}
if ( ! F_31 ( V_13 -> V_23 , V_13 -> V_39 ) ) {
V_6 = - V_35 ;
goto V_68;
}
if ( F_51 ( V_13 -> V_47 + V_69 ) == V_70 )
V_13 -> V_21 |= V_22 ;
V_13 -> V_41 = F_47 ( sizeof( long ) * F_54 ( V_13 -> V_39 ) ,
V_64 ) ;
if ( ! V_13 -> V_41 ) {
V_6 = - V_57 ;
goto V_68;
}
F_55 ( & V_13 -> V_51 , & V_55 ) ;
F_56 ( L_8 , V_15 ,
V_13 -> V_23 , ( V_13 -> V_23 + V_13 -> V_39 - 1 ) ) ;
return 0 ;
V_68:
F_36 ( V_13 -> V_47 ) ;
V_65:
F_35 ( V_13 ) ;
return V_6 ;
}
static int T_4 F_57 ( struct V_62 * V_71 ,
struct V_24 * V_30 )
{
int V_6 = 0 ;
struct V_72 * V_73 = F_38 ( V_71 ) ;
struct V_72 * V_74 ;
for ( V_74 = F_58 ( V_73 , V_75 ) ; V_74 ;
V_74 = F_58 ( V_74 , V_75 ) ) {
T_3 V_23 = 0 , V_39 = 0 ;
struct V_63 V_15 ;
if ( ! F_59 ( V_74 , L_9 , NULL ) )
continue;
V_6 = F_60 ( V_74 , 0 , & V_15 ) ;
if ( V_6 ) {
F_19 ( L_10 ) ;
break;
}
if ( ! F_61 ( V_74 , L_11 ,
& V_23 ) &&
! F_61 ( V_74 , L_12 , & V_39 ) )
F_56 ( L_13 ,
V_23 , V_39 ) ;
V_6 = F_46 ( & V_74 -> V_31 , V_23 , V_39 , & V_15 ) ;
if ( V_6 ) {
F_37 ( V_74 ) ;
break;
}
}
if ( ! V_6 )
V_6 = F_40 ( V_30 ) ;
if ( V_6 )
F_32 () ;
return V_6 ;
}
static struct V_62 * F_62 ( struct V_76 * V_77 )
{
struct V_12 * V_9 ;
if ( F_63 ( V_78 <= 0 ) )
return NULL ;
V_9 = F_41 ( & V_55 , struct V_12 , V_51 ) ;
if ( ! V_9 )
return NULL ;
return V_9 -> V_31 ;
}
static int T_4
F_64 ( struct V_79 * V_80 ,
const unsigned long V_81 )
{
int V_6 ;
struct V_63 V_15 ;
T_3 V_23 = 0 , V_39 = 0 ;
struct V_82 * V_83 ;
struct V_62 * V_31 ;
V_83 = (struct V_82 * ) V_80 ;
if ( F_65 ( V_83 , V_81 ) )
return - V_35 ;
V_15 . V_16 = V_83 -> V_84 ;
V_15 . V_81 = V_83 -> V_84 + V_85 - 1 ;
V_15 . V_21 = V_86 ;
if ( V_83 -> V_21 & V_87 ) {
V_23 = V_83 -> V_88 ;
V_39 = V_83 -> V_89 ;
F_56 ( L_14 ,
V_23 , V_39 ) ;
}
V_31 = F_66 ( ( void * ) V_83 -> V_84 ) ;
if ( ! V_31 ) {
F_19 ( L_15 ) ;
return - V_35 ;
}
V_6 = F_46 ( V_31 , V_23 , V_39 , & V_15 ) ;
if ( V_6 )
F_39 ( V_31 ) ;
return V_6 ;
}
static int T_4 F_67 ( struct V_24 * V_30 )
{
int V_6 ;
if ( V_78 > 0 )
return 0 ;
V_78 = F_68 ( V_90 ,
F_64 , 0 ) ;
if ( V_78 <= 0 )
goto V_91;
V_6 = F_40 ( V_30 ) ;
if ( V_6 )
goto V_91;
F_69 ( & F_62 ) ;
return 0 ;
V_91:
F_32 () ;
return - V_35 ;
}
static int T_4 F_67 ( struct V_24 * V_30 )
{
return - V_35 ;
}
int T_4 F_70 ( struct V_62 * V_71 ,
struct V_24 * V_30 )
{
if ( F_14 ( V_71 ) )
return F_57 ( V_71 , V_30 ) ;
return F_67 ( V_30 ) ;
}
