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
V_11 -> V_18 = ( V_19 ) ( V_14 >> 32 ) ;
V_11 -> V_20 = ( V_19 ) ( V_14 ) ;
V_11 -> V_9 = V_9 -> V_21 ;
}
static int F_11 ( struct V_22 * V_23 ,
unsigned int V_24 ,
T_2 V_21 )
{
struct V_25 args ;
struct V_1 * V_2 ;
int V_26 ;
args . V_27 = V_23 -> V_28 -> V_29 ;
args . V_30 = 3 ;
args . args [ 0 ] = 0 ;
args . args [ 1 ] = V_21 - 32 ;
args . args [ 2 ] = V_31 ;
V_26 = F_12 ( V_23 , V_24 , 1 , & args ) ;
if ( V_26 )
return V_26 ;
V_2 = F_13 ( V_23 -> V_28 , V_24 ) ;
V_2 -> V_32 -> V_33 ( V_2 , V_31 ) ;
return 0 ;
}
static void F_14 ( struct V_12 * V_13 , unsigned int V_21 )
{
int V_34 ;
V_34 = V_21 - V_13 -> V_35 ;
if ( V_34 < 0 || V_34 >= V_13 -> V_36 ) {
F_15 ( L_1 , V_21 ) ;
return;
}
F_16 ( & V_13 -> V_37 ) ;
F_17 ( V_34 , V_13 -> V_38 ) ;
F_18 ( & V_13 -> V_37 ) ;
}
static int F_19 ( struct V_22 * V_23 , unsigned int V_24 ,
unsigned int V_39 , void * args )
{
struct V_12 * V_13 = V_23 -> V_40 ;
int V_21 , V_41 , V_26 = 0 ;
F_16 ( & V_13 -> V_37 ) ;
V_41 = F_20 ( V_13 -> V_38 , V_13 -> V_36 ) ;
if ( V_41 < V_13 -> V_36 )
F_21 ( V_41 , V_13 -> V_38 ) ;
else
V_26 = - V_42 ;
F_18 ( & V_13 -> V_37 ) ;
if ( V_26 )
return V_26 ;
V_21 = V_13 -> V_35 + V_41 ;
V_26 = F_11 ( V_23 , V_24 , V_21 ) ;
if ( V_26 ) {
F_14 ( V_13 , V_21 ) ;
return V_26 ;
}
F_22 ( V_23 , V_24 , V_21 ,
& V_43 , V_13 ) ;
return 0 ;
}
static void F_23 ( struct V_22 * V_23 ,
unsigned int V_24 , unsigned int V_39 )
{
struct V_1 * V_2 = F_13 ( V_23 , V_24 ) ;
struct V_12 * V_13 = F_10 ( V_2 ) ;
F_24 ( V_39 != 1 ) ;
F_14 ( V_13 , V_2 -> V_21 ) ;
F_25 ( V_23 , V_24 , V_39 ) ;
}
static bool F_26 ( V_19 V_44 , V_19 V_45 )
{
if ( V_44 < V_46 ) {
F_15 ( L_2 , V_44 ) ;
return false ;
}
if ( ( V_45 == 0 ) || ( V_44 + V_45 > V_47 ) ) {
F_15 ( L_3 ,
V_45 , V_47 - V_46 + 1 ) ;
return false ;
}
return true ;
}
static int T_3 F_27 ( struct V_48 * V_49 ,
struct V_22 * V_28 )
{
int V_6 ;
struct V_12 * V_13 ;
V_13 = F_28 ( sizeof( struct V_12 ) , V_50 ) ;
if ( ! V_13 ) {
F_15 ( L_4 ) ;
return - V_51 ;
}
V_6 = F_29 ( V_49 , 0 , & V_13 -> V_15 ) ;
if ( V_6 ) {
F_15 ( L_5 ) ;
goto V_52;
}
V_13 -> V_44 = F_30 ( V_13 -> V_15 . V_16 , F_31 ( & V_13 -> V_15 ) ) ;
if ( ! V_13 -> V_44 ) {
F_15 ( L_6 ) ;
V_6 = - V_51 ;
goto V_52;
}
if ( ! F_32 ( V_49 , L_7 , & V_13 -> V_35 ) &&
! F_32 ( V_49 , L_8 , & V_13 -> V_36 ) ) {
F_33 ( L_9 ,
V_13 -> V_35 , V_13 -> V_36 ) ;
} else {
V_19 V_53 = F_34 ( V_13 -> V_44 + V_54 ) ;
V_13 -> V_35 = F_35 ( V_53 ) ;
V_13 -> V_36 = F_36 ( V_53 ) ;
}
if ( ! F_26 ( V_13 -> V_35 , V_13 -> V_36 ) ) {
V_6 = - V_55 ;
goto V_56;
}
V_13 -> V_38 = F_28 ( sizeof( long ) * F_37 ( V_13 -> V_36 ) ,
V_50 ) ;
if ( ! V_13 -> V_38 ) {
V_6 = - V_51 ;
goto V_56;
}
V_13 -> V_23 = F_38 ( NULL , & V_57 , V_13 ) ;
if ( ! V_13 -> V_23 ) {
F_15 ( L_10 ) ;
V_6 = - V_51 ;
goto V_58;
}
V_13 -> V_23 -> V_28 = V_28 ;
V_13 -> V_59 . V_29 = V_49 ;
V_13 -> V_59 . V_23 = F_39 ( V_49 ,
& V_60 ,
V_13 -> V_23 ) ;
if ( ! V_13 -> V_59 . V_23 ) {
F_15 ( L_11 ) ;
V_6 = - V_51 ;
goto V_61;
}
F_40 ( & V_13 -> V_37 ) ;
V_6 = F_41 ( & V_13 -> V_59 ) ;
if ( V_6 ) {
F_15 ( L_12 ) ;
goto V_61;
}
F_33 ( L_13 , V_49 -> V_62 ,
( unsigned long ) V_13 -> V_15 . V_16 , ( unsigned long ) V_13 -> V_15 . V_63 ,
V_13 -> V_35 , ( V_13 -> V_35 + V_13 -> V_36 ) ) ;
return 0 ;
V_61:
if ( V_13 -> V_59 . V_23 )
F_42 ( V_13 -> V_59 . V_23 ) ;
if ( V_13 -> V_23 )
F_42 ( V_13 -> V_23 ) ;
V_58:
F_43 ( V_13 -> V_38 ) ;
V_56:
F_44 ( V_13 -> V_44 ) ;
V_52:
F_43 ( V_13 ) ;
return V_6 ;
}
int T_3 F_45 ( struct V_48 * V_49 , struct V_22 * V_28 )
{
int V_6 = 0 ;
struct V_48 * V_64 ;
for ( V_64 = F_46 ( V_49 , V_65 ) ; V_64 ;
V_64 = F_46 ( V_64 , V_65 ) ) {
if ( ! F_47 ( V_64 , L_14 , NULL ) )
continue;
V_6 = F_27 ( V_64 , V_28 ) ;
if ( V_6 ) {
F_48 ( V_49 ) ;
break;
}
}
return V_6 ;
}
