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
}
static int F_13 ( struct V_21 * V_22 ,
unsigned int V_23 ,
T_2 V_20 )
{
struct V_24 args ;
struct V_1 * V_2 ;
int V_25 ;
args . V_26 = V_22 -> V_27 -> V_28 ;
args . V_29 = 3 ;
args . args [ 0 ] = 0 ;
args . args [ 1 ] = V_20 - 32 ;
args . args [ 2 ] = V_30 ;
V_25 = F_14 ( V_22 , V_23 , 1 , & args ) ;
if ( V_25 )
return V_25 ;
V_2 = F_15 ( V_22 -> V_27 , V_23 ) ;
V_2 -> V_31 -> V_32 ( V_2 , V_30 ) ;
return 0 ;
}
static void F_16 ( struct V_12 * V_13 , unsigned int V_20 )
{
int V_33 ;
V_33 = V_20 - V_13 -> V_34 ;
if ( V_33 < 0 || V_33 >= V_13 -> V_35 ) {
F_17 ( L_1 , V_20 ) ;
return;
}
F_18 ( & V_13 -> V_36 ) ;
F_19 ( V_33 , V_13 -> V_37 ) ;
F_20 ( & V_13 -> V_36 ) ;
}
static int F_21 ( struct V_21 * V_22 , unsigned int V_23 ,
unsigned int V_38 , void * args )
{
struct V_12 * V_13 = V_22 -> V_39 ;
int V_20 , V_40 , V_25 = 0 ;
F_18 ( & V_13 -> V_36 ) ;
V_40 = F_22 ( V_13 -> V_37 , V_13 -> V_35 ) ;
if ( V_40 < V_13 -> V_35 )
F_23 ( V_40 , V_13 -> V_37 ) ;
else
V_25 = - V_41 ;
F_20 ( & V_13 -> V_36 ) ;
if ( V_25 )
return V_25 ;
V_20 = V_13 -> V_34 + V_40 ;
V_25 = F_13 ( V_22 , V_23 , V_20 ) ;
if ( V_25 ) {
F_16 ( V_13 , V_20 ) ;
return V_25 ;
}
F_24 ( V_22 , V_23 , V_20 ,
& V_42 , V_13 ) ;
return 0 ;
}
static void F_25 ( struct V_21 * V_22 ,
unsigned int V_23 , unsigned int V_38 )
{
struct V_1 * V_2 = F_15 ( V_22 , V_23 ) ;
struct V_12 * V_13 = F_10 ( V_2 ) ;
F_26 ( V_38 != 1 ) ;
F_16 ( V_13 , V_2 -> V_20 ) ;
F_27 ( V_22 , V_23 , V_38 ) ;
}
static bool F_28 ( T_3 V_43 , T_3 V_44 )
{
if ( V_43 < V_45 ) {
F_17 ( L_2 , V_43 ) ;
return false ;
}
if ( ( V_44 == 0 ) || ( V_43 + V_44 > V_46 ) ) {
F_17 ( L_3 ,
V_44 , V_46 - V_45 + 1 ) ;
return false ;
}
return true ;
}
static int T_4 F_29 ( struct V_47 * V_48 ,
struct V_21 * V_27 )
{
int V_6 ;
struct V_12 * V_13 ;
struct V_21 * V_49 , * V_50 , * V_51 ;
V_13 = F_30 ( sizeof( struct V_12 ) , V_52 ) ;
if ( ! V_13 ) {
F_17 ( L_4 ) ;
return - V_53 ;
}
V_6 = F_31 ( V_48 , 0 , & V_13 -> V_15 ) ;
if ( V_6 ) {
F_17 ( L_5 ) ;
goto V_54;
}
V_13 -> V_43 = F_32 ( V_13 -> V_15 . V_16 , F_33 ( & V_13 -> V_15 ) ) ;
if ( ! V_13 -> V_43 ) {
F_17 ( L_6 ) ;
V_6 = - V_53 ;
goto V_54;
}
if ( ! F_34 ( V_48 , L_7 , & V_13 -> V_34 ) &&
! F_34 ( V_48 , L_8 , & V_13 -> V_35 ) ) {
F_35 ( L_9 ,
V_13 -> V_34 , V_13 -> V_35 ) ;
} else {
T_3 V_55 = F_36 ( V_13 -> V_43 + V_56 ) ;
V_13 -> V_34 = F_37 ( V_55 ) ;
V_13 -> V_35 = F_38 ( V_55 ) ;
}
if ( ! F_28 ( V_13 -> V_34 , V_13 -> V_35 ) ) {
V_6 = - V_57 ;
goto V_58;
}
V_13 -> V_37 = F_30 ( sizeof( long ) * F_39 ( V_13 -> V_35 ) ,
V_52 ) ;
if ( ! V_13 -> V_37 ) {
V_6 = - V_53 ;
goto V_58;
}
V_49 = F_40 ( V_48 , & V_59 , V_13 ) ;
if ( ! V_49 ) {
F_17 ( L_10 ) ;
V_6 = - V_53 ;
goto V_60;
}
V_49 -> V_61 = V_62 ;
V_49 -> V_27 = V_27 ;
V_50 = F_41 ( V_48 , & V_63 ,
V_49 ) ;
V_51 = F_42 ( V_48 ,
& V_64 ,
V_49 ) ;
if ( ! V_50 || ! V_51 ) {
F_17 ( L_11 ) ;
V_6 = - V_53 ;
goto V_65;
}
F_43 ( & V_13 -> V_36 ) ;
F_35 ( L_12 , V_48 -> V_66 ,
( unsigned long ) V_13 -> V_15 . V_16 , ( unsigned long ) V_13 -> V_15 . V_67 ,
V_13 -> V_34 , ( V_13 -> V_34 + V_13 -> V_35 ) ) ;
return 0 ;
V_65:
if ( V_51 )
F_44 ( V_51 ) ;
if ( V_50 )
F_44 ( V_50 ) ;
if ( V_49 )
F_44 ( V_49 ) ;
V_60:
F_45 ( V_13 -> V_37 ) ;
V_58:
F_46 ( V_13 -> V_43 ) ;
V_54:
F_45 ( V_13 ) ;
return V_6 ;
}
int T_4 F_47 ( struct V_47 * V_48 , struct V_21 * V_27 )
{
int V_6 = 0 ;
struct V_47 * V_68 ;
for ( V_68 = F_48 ( V_48 , V_69 ) ; V_68 ;
V_68 = F_48 ( V_68 , V_69 ) ) {
if ( ! F_49 ( V_68 , L_13 , NULL ) )
continue;
V_6 = F_29 ( V_68 , V_27 ) ;
if ( V_6 ) {
F_50 ( V_48 ) ;
break;
}
}
return V_6 ;
}
