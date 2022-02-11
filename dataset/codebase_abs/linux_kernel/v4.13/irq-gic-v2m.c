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
F_42 ( V_48 , V_54 ) ;
V_48 -> V_25 = V_25 ;
V_49 = F_43 ( V_7 -> V_26 ,
& V_55 ,
V_48 ) ;
V_50 = F_44 ( V_7 -> V_26 ,
& V_56 ,
V_48 ) ;
if ( ! V_49 || ! V_50 ) {
F_18 ( L_5 ) ;
if ( V_50 )
F_45 ( V_50 ) ;
if ( V_49 )
F_45 ( V_49 ) ;
F_45 ( V_48 ) ;
return - V_53 ;
}
return 0 ;
}
static int T_4 F_46 ( struct V_57 * V_26 ,
T_3 V_34 , T_3 V_35 ,
struct V_58 * V_9 )
{
int V_59 ;
struct V_6 * V_7 ;
V_7 = F_47 ( sizeof( struct V_6 ) , V_60 ) ;
if ( ! V_7 ) {
F_18 ( L_6 ) ;
return - V_53 ;
}
F_48 ( & V_7 -> V_47 ) ;
V_7 -> V_26 = V_26 ;
memcpy ( & V_7 -> V_9 , V_9 , sizeof( struct V_58 ) ) ;
V_7 -> V_43 = F_49 ( V_7 -> V_9 . V_10 , F_50 ( & V_7 -> V_9 ) ) ;
if ( ! V_7 -> V_43 ) {
F_18 ( L_7 ) ;
V_59 = - V_53 ;
goto V_61;
}
if ( V_34 && V_35 ) {
V_7 -> V_34 = V_34 ;
V_7 -> V_35 = V_35 ;
} else {
T_3 V_62 = F_51 ( V_7 -> V_43 + V_63 ) ;
V_7 -> V_34 = F_52 ( V_62 ) ;
V_7 -> V_35 = F_53 ( V_62 ) ;
}
if ( ! F_30 ( V_7 -> V_34 , V_7 -> V_35 ) ) {
V_59 = - V_30 ;
goto V_64;
}
switch ( F_51 ( V_7 -> V_43 + V_65 ) ) {
case V_66 :
V_7 -> V_15 |= V_16 ;
V_7 -> V_17 = V_7 -> V_34 ;
break;
case V_67 :
V_7 -> V_15 |= V_16 ;
V_7 -> V_17 = 32 ;
break;
}
V_7 -> V_37 = F_47 ( sizeof( long ) * F_54 ( V_7 -> V_35 ) ,
V_60 ) ;
if ( ! V_7 -> V_37 ) {
V_59 = - V_53 ;
goto V_64;
}
F_55 ( & V_7 -> V_47 , & V_51 ) ;
F_56 ( L_8 , V_9 ,
V_7 -> V_34 , ( V_7 -> V_34 + V_7 -> V_35 - 1 ) ) ;
return 0 ;
V_64:
F_35 ( V_7 -> V_43 ) ;
V_61:
F_34 ( V_7 ) ;
return V_59 ;
}
static int T_4 F_57 ( struct V_57 * V_68 ,
struct V_19 * V_25 )
{
int V_59 = 0 ;
struct V_69 * V_70 = F_37 ( V_68 ) ;
struct V_69 * V_71 ;
for ( V_71 = F_58 ( V_70 , V_72 ) ; V_71 ;
V_71 = F_58 ( V_71 , V_72 ) ) {
T_3 V_34 = 0 , V_35 = 0 ;
struct V_58 V_9 ;
if ( ! F_59 ( V_71 , L_9 , NULL ) )
continue;
V_59 = F_60 ( V_71 , 0 , & V_9 ) ;
if ( V_59 ) {
F_18 ( L_10 ) ;
break;
}
if ( ! F_61 ( V_71 , L_11 ,
& V_34 ) &&
! F_61 ( V_71 , L_12 , & V_35 ) )
F_56 ( L_13 ,
V_34 , V_35 ) ;
V_59 = F_46 ( & V_71 -> V_26 , V_34 , V_35 , & V_9 ) ;
if ( V_59 ) {
F_36 ( V_71 ) ;
break;
}
}
if ( ! V_59 )
V_59 = F_39 ( V_25 ) ;
if ( V_59 )
F_31 () ;
return V_59 ;
}
static struct V_57 * F_62 ( struct V_73 * V_74 )
{
struct V_6 * V_3 ;
if ( F_63 ( V_75 <= 0 ) )
return NULL ;
V_3 = F_40 ( & V_51 , struct V_6 , V_47 ) ;
if ( ! V_3 )
return NULL ;
return V_3 -> V_26 ;
}
static int T_4
F_64 ( struct V_76 * V_77 ,
const unsigned long V_78 )
{
int V_59 ;
struct V_58 V_9 ;
T_3 V_34 = 0 , V_35 = 0 ;
struct V_79 * V_80 ;
struct V_57 * V_26 ;
V_80 = (struct V_79 * ) V_77 ;
if ( F_65 ( V_80 , V_78 ) )
return - V_30 ;
V_9 . V_10 = V_80 -> V_81 ;
V_9 . V_78 = V_80 -> V_81 + V_82 - 1 ;
V_9 . V_15 = V_83 ;
if ( V_80 -> V_15 & V_84 ) {
V_34 = V_80 -> V_85 ;
V_35 = V_80 -> V_86 ;
F_56 ( L_14 ,
V_34 , V_35 ) ;
}
V_26 = F_66 ( ( void * ) V_80 -> V_81 ) ;
if ( ! V_26 ) {
F_18 ( L_15 ) ;
return - V_30 ;
}
V_59 = F_46 ( V_26 , V_34 , V_35 , & V_9 ) ;
if ( V_59 )
F_38 ( V_26 ) ;
return V_59 ;
}
static int T_4 F_67 ( struct V_19 * V_25 )
{
int V_59 ;
if ( V_75 > 0 )
return 0 ;
V_75 = F_68 ( V_87 ,
F_64 , 0 ) ;
if ( V_75 <= 0 )
goto V_88;
V_59 = F_39 ( V_25 ) ;
if ( V_59 )
goto V_88;
F_69 ( & F_62 ) ;
return 0 ;
V_88:
F_31 () ;
return - V_30 ;
}
static int T_4 F_67 ( struct V_19 * V_25 )
{
return - V_30 ;
}
int T_4 F_70 ( struct V_57 * V_68 ,
struct V_19 * V_25 )
{
if ( F_13 ( V_68 ) )
return F_57 ( V_68 , V_25 ) ;
return F_67 ( V_25 ) ;
}
