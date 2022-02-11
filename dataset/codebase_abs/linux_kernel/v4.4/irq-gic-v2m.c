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
} else {
return - V_35 ;
}
V_29 = F_15 ( V_25 , V_26 , 1 , & V_28 ) ;
if ( V_29 )
return V_29 ;
V_2 = F_16 ( V_25 -> V_30 , V_26 ) ;
V_2 -> V_36 -> V_37 ( V_2 , V_34 ) ;
return 0 ;
}
static void F_17 ( struct V_12 * V_13 , unsigned int V_20 )
{
int V_38 ;
V_38 = V_20 - V_13 -> V_23 ;
if ( V_38 < 0 || V_38 >= V_13 -> V_39 ) {
F_18 ( L_1 , V_20 ) ;
return;
}
F_19 ( & V_40 ) ;
F_20 ( V_38 , V_13 -> V_41 ) ;
F_21 ( & V_40 ) ;
}
static int F_22 ( struct V_24 * V_25 , unsigned int V_26 ,
unsigned int V_42 , void * args )
{
struct V_12 * V_13 = NULL , * V_43 ;
int V_20 , V_44 , V_29 = 0 ;
F_19 ( & V_40 ) ;
F_23 (tmp, &v2m_nodes, entry) {
V_44 = F_24 ( V_43 -> V_41 , V_43 -> V_39 ) ;
if ( V_44 < V_43 -> V_39 ) {
F_25 ( V_44 , V_43 -> V_41 ) ;
V_13 = V_43 ;
break;
}
}
F_21 ( & V_40 ) ;
if ( ! V_13 )
return - V_45 ;
V_20 = V_13 -> V_23 + V_44 ;
V_29 = F_13 ( V_25 , V_26 , V_20 ) ;
if ( V_29 ) {
F_17 ( V_13 , V_20 ) ;
return V_29 ;
}
F_26 ( V_25 , V_26 , V_20 ,
& V_46 , V_13 ) ;
return 0 ;
}
static void F_27 ( struct V_24 * V_25 ,
unsigned int V_26 , unsigned int V_42 )
{
struct V_1 * V_2 = F_16 ( V_25 , V_26 ) ;
struct V_12 * V_13 = F_10 ( V_2 ) ;
F_28 ( V_42 != 1 ) ;
F_17 ( V_13 , V_2 -> V_20 ) ;
F_29 ( V_25 , V_26 , V_42 ) ;
}
static bool F_30 ( T_3 V_47 , T_3 V_48 )
{
if ( V_47 < V_49 ) {
F_18 ( L_2 , V_47 ) ;
return false ;
}
if ( ( V_48 == 0 ) || ( V_47 + V_48 > V_50 ) ) {
F_18 ( L_3 ,
V_48 , V_50 - V_49 + 1 ) ;
return false ;
}
return true ;
}
static void F_31 ( void )
{
struct V_12 * V_13 , * V_43 ;
F_32 (v2m, tmp, &v2m_nodes, entry) {
F_33 ( & V_13 -> V_51 ) ;
F_34 ( V_13 -> V_41 ) ;
F_35 ( V_13 -> V_47 ) ;
F_36 ( V_13 -> V_52 ) ;
F_34 ( V_13 ) ;
}
}
static int F_37 ( struct V_24 * V_30 )
{
struct V_24 * V_53 , * V_54 , * V_55 ;
struct V_12 * V_13 ;
V_13 = F_38 ( & V_56 , struct V_12 , V_51 ) ;
if ( ! V_13 )
return 0 ;
V_53 = F_39 ( F_40 ( V_13 -> V_52 ) ,
& V_57 , V_13 ) ;
if ( ! V_53 ) {
F_18 ( L_4 ) ;
return - V_58 ;
}
V_53 -> V_59 = V_60 ;
V_53 -> V_30 = V_30 ;
V_54 = F_41 ( F_40 ( V_13 -> V_52 ) ,
& V_61 ,
V_53 ) ;
V_55 = F_42 ( F_40 ( V_13 -> V_52 ) ,
& V_62 ,
V_53 ) ;
if ( ! V_54 || ! V_55 ) {
F_18 ( L_5 ) ;
if ( V_55 )
F_43 ( V_55 ) ;
if ( V_54 )
F_43 ( V_54 ) ;
F_43 ( V_53 ) ;
return - V_58 ;
}
return 0 ;
}
static int T_4 F_44 ( struct V_63 * V_52 ,
struct V_24 * V_30 )
{
int V_6 ;
struct V_12 * V_13 ;
V_13 = F_45 ( sizeof( struct V_12 ) , V_64 ) ;
if ( ! V_13 ) {
F_18 ( L_6 ) ;
return - V_58 ;
}
F_46 ( & V_13 -> V_51 ) ;
V_13 -> V_52 = V_52 ;
V_6 = F_47 ( V_52 , 0 , & V_13 -> V_15 ) ;
if ( V_6 ) {
F_18 ( L_7 ) ;
goto V_65;
}
V_13 -> V_47 = F_48 ( V_13 -> V_15 . V_16 , F_49 ( & V_13 -> V_15 ) ) ;
if ( ! V_13 -> V_47 ) {
F_18 ( L_8 ) ;
V_6 = - V_58 ;
goto V_65;
}
if ( ! F_50 ( V_52 , L_9 , & V_13 -> V_23 ) &&
! F_50 ( V_52 , L_10 , & V_13 -> V_39 ) ) {
F_51 ( L_11 ,
V_13 -> V_23 , V_13 -> V_39 ) ;
} else {
T_3 V_66 = F_52 ( V_13 -> V_47 + V_67 ) ;
V_13 -> V_23 = F_53 ( V_66 ) ;
V_13 -> V_39 = F_54 ( V_66 ) ;
}
if ( ! F_30 ( V_13 -> V_23 , V_13 -> V_39 ) ) {
V_6 = - V_35 ;
goto V_68;
}
if ( F_52 ( V_13 -> V_47 + V_69 ) == V_70 )
V_13 -> V_21 |= V_22 ;
V_13 -> V_41 = F_45 ( sizeof( long ) * F_55 ( V_13 -> V_39 ) ,
V_64 ) ;
if ( ! V_13 -> V_41 ) {
V_6 = - V_58 ;
goto V_68;
}
F_56 ( & V_13 -> V_51 , & V_56 ) ;
F_51 ( L_12 , V_52 -> V_71 ,
( unsigned long ) V_13 -> V_15 . V_16 , ( unsigned long ) V_13 -> V_15 . V_72 ,
V_13 -> V_23 , ( V_13 -> V_23 + V_13 -> V_39 ) ) ;
return 0 ;
V_68:
F_35 ( V_13 -> V_47 ) ;
V_65:
F_34 ( V_13 ) ;
return V_6 ;
}
int T_4 F_57 ( struct V_63 * V_52 , struct V_24 * V_30 )
{
int V_6 = 0 ;
struct V_63 * V_73 ;
for ( V_73 = F_58 ( V_52 , V_74 ) ; V_73 ;
V_73 = F_58 ( V_73 , V_74 ) ) {
if ( ! F_59 ( V_73 , L_13 , NULL ) )
continue;
V_6 = F_44 ( V_73 , V_30 ) ;
if ( V_6 ) {
F_36 ( V_52 ) ;
break;
}
}
if ( ! V_6 )
V_6 = F_37 ( V_30 ) ;
if ( V_6 )
F_31 () ;
return V_6 ;
}
