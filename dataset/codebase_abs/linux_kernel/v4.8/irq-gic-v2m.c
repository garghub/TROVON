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
V_32 = V_14 - V_7 -> V_33 ;
if ( V_32 < 0 || V_32 >= V_7 -> V_34 ) {
F_17 ( L_1 , V_14 ) ;
return;
}
F_18 ( & V_35 ) ;
F_19 ( V_32 , V_7 -> V_36 ) ;
F_20 ( & V_35 ) ;
}
static int F_21 ( struct V_18 * V_19 , unsigned int V_20 ,
unsigned int V_37 , void * args )
{
struct V_6 * V_7 = NULL , * V_38 ;
int V_14 , V_39 , V_23 = 0 ;
F_18 ( & V_35 ) ;
F_22 (tmp, &v2m_nodes, entry) {
V_39 = F_23 ( V_38 -> V_36 , V_38 -> V_34 ) ;
if ( V_39 < V_38 -> V_34 ) {
F_24 ( V_39 , V_38 -> V_36 ) ;
V_7 = V_38 ;
break;
}
}
F_20 ( & V_35 ) ;
if ( ! V_7 )
return - V_40 ;
V_14 = V_7 -> V_33 + V_39 ;
V_23 = F_11 ( V_19 , V_20 , V_14 ) ;
if ( V_23 ) {
F_16 ( V_7 , V_14 ) ;
return V_23 ;
}
F_25 ( V_19 , V_20 , V_14 ,
& V_41 , V_7 ) ;
return 0 ;
}
static void F_26 ( struct V_18 * V_19 ,
unsigned int V_20 , unsigned int V_37 )
{
struct V_1 * V_2 = F_15 ( V_19 , V_20 ) ;
struct V_6 * V_7 = F_8 ( V_2 ) ;
F_27 ( V_37 != 1 ) ;
F_16 ( V_7 , V_2 -> V_14 ) ;
F_28 ( V_19 , V_20 , V_37 ) ;
}
static bool F_29 ( T_3 V_42 , T_3 V_43 )
{
if ( V_42 < V_44 ) {
F_17 ( L_2 , V_42 ) ;
return false ;
}
if ( ( V_43 == 0 ) || ( V_42 + V_43 > V_45 ) ) {
F_17 ( L_3 ,
V_43 , V_45 - V_44 + 1 ) ;
return false ;
}
return true ;
}
static void F_30 ( void )
{
struct V_6 * V_7 , * V_38 ;
F_31 (v2m, tmp, &v2m_nodes, entry) {
F_32 ( & V_7 -> V_46 ) ;
F_33 ( V_7 -> V_36 ) ;
F_34 ( V_7 -> V_42 ) ;
F_35 ( F_36 ( V_7 -> V_25 ) ) ;
if ( F_13 ( V_7 -> V_25 ) )
F_37 ( V_7 -> V_25 ) ;
F_33 ( V_7 ) ;
}
}
static int F_38 ( struct V_18 * V_24 )
{
struct V_18 * V_47 , * V_48 , * V_49 ;
struct V_6 * V_7 ;
V_7 = F_39 ( & V_50 , struct V_6 , V_46 ) ;
if ( ! V_7 )
return 0 ;
V_47 = F_40 ( V_7 -> V_25 ,
& V_51 , V_7 ) ;
if ( ! V_47 ) {
F_17 ( L_4 ) ;
return - V_52 ;
}
V_47 -> V_53 = V_54 ;
V_47 -> V_24 = V_24 ;
V_48 = F_41 ( V_7 -> V_25 ,
& V_55 ,
V_47 ) ;
V_49 = F_42 ( V_7 -> V_25 ,
& V_56 ,
V_47 ) ;
if ( ! V_48 || ! V_49 ) {
F_17 ( L_5 ) ;
if ( V_49 )
F_43 ( V_49 ) ;
if ( V_48 )
F_43 ( V_48 ) ;
F_43 ( V_47 ) ;
return - V_52 ;
}
return 0 ;
}
static int T_4 F_44 ( struct V_57 * V_25 ,
T_3 V_33 , T_3 V_34 ,
struct V_58 * V_9 )
{
int V_59 ;
struct V_6 * V_7 ;
V_7 = F_45 ( sizeof( struct V_6 ) , V_60 ) ;
if ( ! V_7 ) {
F_17 ( L_6 ) ;
return - V_52 ;
}
F_46 ( & V_7 -> V_46 ) ;
V_7 -> V_25 = V_25 ;
memcpy ( & V_7 -> V_9 , V_9 , sizeof( struct V_58 ) ) ;
V_7 -> V_42 = F_47 ( V_7 -> V_9 . V_10 , F_48 ( & V_7 -> V_9 ) ) ;
if ( ! V_7 -> V_42 ) {
F_17 ( L_7 ) ;
V_59 = - V_52 ;
goto V_61;
}
if ( V_33 && V_34 ) {
V_7 -> V_33 = V_33 ;
V_7 -> V_34 = V_34 ;
} else {
T_3 V_62 = F_49 ( V_7 -> V_42 + V_63 ) ;
V_7 -> V_33 = F_50 ( V_62 ) ;
V_7 -> V_34 = F_51 ( V_62 ) ;
}
if ( ! F_29 ( V_7 -> V_33 , V_7 -> V_34 ) ) {
V_59 = - V_29 ;
goto V_64;
}
switch ( F_49 ( V_7 -> V_42 + V_65 ) ) {
case V_66 :
V_7 -> V_15 |= V_16 ;
V_7 -> V_17 = V_7 -> V_33 ;
break;
case V_67 :
V_7 -> V_15 |= V_16 ;
V_7 -> V_17 = 32 ;
break;
}
V_7 -> V_36 = F_45 ( sizeof( long ) * F_52 ( V_7 -> V_34 ) ,
V_60 ) ;
if ( ! V_7 -> V_36 ) {
V_59 = - V_52 ;
goto V_64;
}
F_53 ( & V_7 -> V_46 , & V_50 ) ;
F_54 ( L_8 , V_9 ,
V_7 -> V_33 , ( V_7 -> V_33 + V_7 -> V_34 - 1 ) ) ;
return 0 ;
V_64:
F_34 ( V_7 -> V_42 ) ;
V_61:
F_33 ( V_7 ) ;
return V_59 ;
}
static int T_4 F_55 ( struct V_57 * V_68 ,
struct V_18 * V_24 )
{
int V_59 = 0 ;
struct V_69 * V_70 = F_36 ( V_68 ) ;
struct V_69 * V_71 ;
for ( V_71 = F_56 ( V_70 , V_72 ) ; V_71 ;
V_71 = F_56 ( V_71 , V_72 ) ) {
T_3 V_33 = 0 , V_34 = 0 ;
struct V_58 V_9 ;
if ( ! F_57 ( V_71 , L_9 , NULL ) )
continue;
V_59 = F_58 ( V_71 , 0 , & V_9 ) ;
if ( V_59 ) {
F_17 ( L_10 ) ;
break;
}
if ( ! F_59 ( V_71 , L_11 ,
& V_33 ) &&
! F_59 ( V_71 , L_12 , & V_34 ) )
F_54 ( L_13 ,
V_33 , V_34 ) ;
V_59 = F_44 ( & V_71 -> V_25 , V_33 , V_34 , & V_9 ) ;
if ( V_59 ) {
F_35 ( V_71 ) ;
break;
}
}
if ( ! V_59 )
V_59 = F_38 ( V_24 ) ;
if ( V_59 )
F_30 () ;
return V_59 ;
}
static struct V_57 * F_60 ( struct V_73 * V_74 )
{
struct V_6 * V_3 ;
if ( F_61 ( V_75 <= 0 ) )
return NULL ;
V_3 = F_39 ( & V_50 , struct V_6 , V_46 ) ;
if ( ! V_3 )
return NULL ;
return V_3 -> V_25 ;
}
static int T_4
F_62 ( struct V_76 * V_77 ,
const unsigned long V_78 )
{
int V_59 ;
struct V_58 V_9 ;
T_3 V_33 = 0 , V_34 = 0 ;
struct V_79 * V_80 ;
struct V_57 * V_25 ;
V_80 = (struct V_79 * ) V_77 ;
if ( F_63 ( V_80 , V_78 ) )
return - V_29 ;
V_9 . V_10 = V_80 -> V_81 ;
V_9 . V_78 = V_80 -> V_81 + V_82 - 1 ;
V_9 . V_15 = V_83 ;
if ( V_80 -> V_15 & V_84 ) {
V_33 = V_80 -> V_85 ;
V_34 = V_80 -> V_86 ;
F_54 ( L_14 ,
V_33 , V_34 ) ;
}
V_25 = F_64 ( ( void * ) V_80 -> V_81 ) ;
if ( ! V_25 ) {
F_17 ( L_15 ) ;
return - V_29 ;
}
V_59 = F_44 ( V_25 , V_33 , V_34 , & V_9 ) ;
if ( V_59 )
F_37 ( V_25 ) ;
return V_59 ;
}
static int T_4 F_65 ( struct V_18 * V_24 )
{
int V_59 ;
if ( V_75 > 0 )
return 0 ;
V_75 = F_66 ( V_87 ,
F_62 , 0 ) ;
if ( V_75 <= 0 )
goto V_88;
V_59 = F_38 ( V_24 ) ;
if ( V_59 )
goto V_88;
F_67 ( & F_60 ) ;
return 0 ;
V_88:
F_30 () ;
return - V_29 ;
}
static int T_4 F_65 ( struct V_18 * V_24 )
{
return - V_29 ;
}
int T_4 F_68 ( struct V_57 * V_68 ,
struct V_18 * V_24 )
{
if ( F_12 ( V_68 ) )
return F_55 ( V_68 , V_24 ) ;
return F_65 ( V_24 ) ;
}
