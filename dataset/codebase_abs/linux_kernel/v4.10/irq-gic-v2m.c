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
F_11 ( V_3 -> V_18 , V_5 ) ;
}
static int F_12 ( struct V_19 * V_20 ,
unsigned int V_21 ,
T_2 V_14 )
{
struct V_22 V_23 ;
struct V_1 * V_2 ;
int V_24 ;
if ( F_13 ( V_20 -> V_25 -> V_26 ) ) {
V_23 . V_26 = V_20 -> V_25 -> V_26 ;
V_23 . V_27 = 3 ;
V_23 . V_28 [ 0 ] = 0 ;
V_23 . V_28 [ 1 ] = V_14 - 32 ;
V_23 . V_28 [ 2 ] = V_29 ;
} else if ( F_14 ( V_20 -> V_25 -> V_26 ) ) {
V_23 . V_26 = V_20 -> V_25 -> V_26 ;
V_23 . V_27 = 2 ;
V_23 . V_28 [ 0 ] = V_14 ;
V_23 . V_28 [ 1 ] = V_29 ;
} else {
return - V_30 ;
}
V_24 = F_15 ( V_20 , V_21 , 1 , & V_23 ) ;
if ( V_24 )
return V_24 ;
V_2 = F_16 ( V_20 -> V_25 , V_21 ) ;
V_2 -> V_31 -> V_32 ( V_2 , V_29 ) ;
return 0 ;
}
static void F_17 ( struct V_6 * V_7 , unsigned int V_14 )
{
int V_33 ;
V_33 = V_14 - V_7 -> V_34 ;
if ( V_33 < 0 || V_33 >= V_7 -> V_35 ) {
F_18 ( L_1 , V_14 ) ;
return;
}
F_19 ( & V_36 ) ;
F_20 ( V_33 , V_7 -> V_37 ) ;
F_21 ( & V_36 ) ;
}
static int F_22 ( struct V_19 * V_20 , unsigned int V_21 ,
unsigned int V_38 , void * args )
{
struct V_6 * V_7 = NULL , * V_39 ;
int V_14 , V_40 , V_24 = 0 ;
F_19 ( & V_36 ) ;
F_23 (tmp, &v2m_nodes, entry) {
V_40 = F_24 ( V_39 -> V_37 , V_39 -> V_35 ) ;
if ( V_40 < V_39 -> V_35 ) {
F_25 ( V_40 , V_39 -> V_37 ) ;
V_7 = V_39 ;
break;
}
}
F_21 ( & V_36 ) ;
if ( ! V_7 )
return - V_41 ;
V_14 = V_7 -> V_34 + V_40 ;
V_24 = F_12 ( V_20 , V_21 , V_14 ) ;
if ( V_24 ) {
F_17 ( V_7 , V_14 ) ;
return V_24 ;
}
F_26 ( V_20 , V_21 , V_14 ,
& V_42 , V_7 ) ;
return 0 ;
}
static void F_27 ( struct V_19 * V_20 ,
unsigned int V_21 , unsigned int V_38 )
{
struct V_1 * V_2 = F_16 ( V_20 , V_21 ) ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
F_28 ( V_38 != 1 ) ;
F_17 ( V_7 , V_2 -> V_14 ) ;
F_29 ( V_20 , V_21 , V_38 ) ;
}
static bool F_30 ( T_3 V_43 , T_3 V_44 )
{
if ( V_43 < V_45 ) {
F_18 ( L_2 , V_43 ) ;
return false ;
}
if ( ( V_44 == 0 ) || ( V_43 + V_44 > V_46 ) ) {
F_18 ( L_3 ,
V_44 , V_46 - V_45 + 1 ) ;
return false ;
}
return true ;
}
static void F_31 ( void )
{
struct V_6 * V_7 , * V_39 ;
F_32 (v2m, tmp, &v2m_nodes, entry) {
F_33 ( & V_7 -> V_47 ) ;
F_34 ( V_7 -> V_37 ) ;
F_35 ( V_7 -> V_43 ) ;
F_36 ( F_37 ( V_7 -> V_26 ) ) ;
if ( F_14 ( V_7 -> V_26 ) )
F_38 ( V_7 -> V_26 ) ;
F_34 ( V_7 ) ;
}
}
static int F_39 ( struct V_19 * V_25 )
{
struct V_19 * V_48 , * V_49 , * V_50 ;
struct V_6 * V_7 ;
V_7 = F_40 ( & V_51 , struct V_6 , V_47 ) ;
if ( ! V_7 )
return 0 ;
V_48 = F_41 ( V_7 -> V_26 ,
& V_52 , V_7 ) ;
if ( ! V_48 ) {
F_18 ( L_4 ) ;
return - V_53 ;
}
V_48 -> V_54 = V_55 ;
V_48 -> V_25 = V_25 ;
V_49 = F_42 ( V_7 -> V_26 ,
& V_56 ,
V_48 ) ;
V_50 = F_43 ( V_7 -> V_26 ,
& V_57 ,
V_48 ) ;
if ( ! V_49 || ! V_50 ) {
F_18 ( L_5 ) ;
if ( V_50 )
F_44 ( V_50 ) ;
if ( V_49 )
F_44 ( V_49 ) ;
F_44 ( V_48 ) ;
return - V_53 ;
}
return 0 ;
}
static int T_4 F_45 ( struct V_58 * V_26 ,
T_3 V_34 , T_3 V_35 ,
struct V_59 * V_9 )
{
int V_60 ;
struct V_6 * V_7 ;
V_7 = F_46 ( sizeof( struct V_6 ) , V_61 ) ;
if ( ! V_7 ) {
F_18 ( L_6 ) ;
return - V_53 ;
}
F_47 ( & V_7 -> V_47 ) ;
V_7 -> V_26 = V_26 ;
memcpy ( & V_7 -> V_9 , V_9 , sizeof( struct V_59 ) ) ;
V_7 -> V_43 = F_48 ( V_7 -> V_9 . V_10 , F_49 ( & V_7 -> V_9 ) ) ;
if ( ! V_7 -> V_43 ) {
F_18 ( L_7 ) ;
V_60 = - V_53 ;
goto V_62;
}
if ( V_34 && V_35 ) {
V_7 -> V_34 = V_34 ;
V_7 -> V_35 = V_35 ;
} else {
T_3 V_63 = F_50 ( V_7 -> V_43 + V_64 ) ;
V_7 -> V_34 = F_51 ( V_63 ) ;
V_7 -> V_35 = F_52 ( V_63 ) ;
}
if ( ! F_30 ( V_7 -> V_34 , V_7 -> V_35 ) ) {
V_60 = - V_30 ;
goto V_65;
}
switch ( F_50 ( V_7 -> V_43 + V_66 ) ) {
case V_67 :
V_7 -> V_15 |= V_16 ;
V_7 -> V_17 = V_7 -> V_34 ;
break;
case V_68 :
V_7 -> V_15 |= V_16 ;
V_7 -> V_17 = 32 ;
break;
}
V_7 -> V_37 = F_46 ( sizeof( long ) * F_53 ( V_7 -> V_35 ) ,
V_61 ) ;
if ( ! V_7 -> V_37 ) {
V_60 = - V_53 ;
goto V_65;
}
F_54 ( & V_7 -> V_47 , & V_51 ) ;
F_55 ( L_8 , V_9 ,
V_7 -> V_34 , ( V_7 -> V_34 + V_7 -> V_35 - 1 ) ) ;
return 0 ;
V_65:
F_35 ( V_7 -> V_43 ) ;
V_62:
F_34 ( V_7 ) ;
return V_60 ;
}
static int T_4 F_56 ( struct V_58 * V_69 ,
struct V_19 * V_25 )
{
int V_60 = 0 ;
struct V_70 * V_71 = F_37 ( V_69 ) ;
struct V_70 * V_72 ;
for ( V_72 = F_57 ( V_71 , V_73 ) ; V_72 ;
V_72 = F_57 ( V_72 , V_73 ) ) {
T_3 V_34 = 0 , V_35 = 0 ;
struct V_59 V_9 ;
if ( ! F_58 ( V_72 , L_9 , NULL ) )
continue;
V_60 = F_59 ( V_72 , 0 , & V_9 ) ;
if ( V_60 ) {
F_18 ( L_10 ) ;
break;
}
if ( ! F_60 ( V_72 , L_11 ,
& V_34 ) &&
! F_60 ( V_72 , L_12 , & V_35 ) )
F_55 ( L_13 ,
V_34 , V_35 ) ;
V_60 = F_45 ( & V_72 -> V_26 , V_34 , V_35 , & V_9 ) ;
if ( V_60 ) {
F_36 ( V_72 ) ;
break;
}
}
if ( ! V_60 )
V_60 = F_39 ( V_25 ) ;
if ( V_60 )
F_31 () ;
return V_60 ;
}
static struct V_58 * F_61 ( struct V_74 * V_75 )
{
struct V_6 * V_3 ;
if ( F_62 ( V_76 <= 0 ) )
return NULL ;
V_3 = F_40 ( & V_51 , struct V_6 , V_47 ) ;
if ( ! V_3 )
return NULL ;
return V_3 -> V_26 ;
}
static int T_4
F_63 ( struct V_77 * V_78 ,
const unsigned long V_79 )
{
int V_60 ;
struct V_59 V_9 ;
T_3 V_34 = 0 , V_35 = 0 ;
struct V_80 * V_81 ;
struct V_58 * V_26 ;
V_81 = (struct V_80 * ) V_78 ;
if ( F_64 ( V_81 , V_79 ) )
return - V_30 ;
V_9 . V_10 = V_81 -> V_82 ;
V_9 . V_79 = V_81 -> V_82 + V_83 - 1 ;
V_9 . V_15 = V_84 ;
if ( V_81 -> V_15 & V_85 ) {
V_34 = V_81 -> V_86 ;
V_35 = V_81 -> V_87 ;
F_55 ( L_14 ,
V_34 , V_35 ) ;
}
V_26 = F_65 ( ( void * ) V_81 -> V_82 ) ;
if ( ! V_26 ) {
F_18 ( L_15 ) ;
return - V_30 ;
}
V_60 = F_45 ( V_26 , V_34 , V_35 , & V_9 ) ;
if ( V_60 )
F_38 ( V_26 ) ;
return V_60 ;
}
static int T_4 F_66 ( struct V_19 * V_25 )
{
int V_60 ;
if ( V_76 > 0 )
return 0 ;
V_76 = F_67 ( V_88 ,
F_63 , 0 ) ;
if ( V_76 <= 0 )
goto V_89;
V_60 = F_39 ( V_25 ) ;
if ( V_60 )
goto V_89;
F_68 ( & F_61 ) ;
return 0 ;
V_89:
F_31 () ;
return - V_30 ;
}
static int T_4 F_66 ( struct V_19 * V_25 )
{
return - V_30 ;
}
int T_4 F_69 ( struct V_58 * V_69 ,
struct V_19 * V_25 )
{
if ( F_13 ( V_69 ) )
return F_56 ( V_69 , V_25 ) ;
return F_66 ( V_25 ) ;
}
