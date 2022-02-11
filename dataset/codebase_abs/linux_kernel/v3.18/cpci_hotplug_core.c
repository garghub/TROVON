static int
F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 V_4 ;
memcpy ( & V_4 , V_1 -> V_4 , sizeof( struct V_3 ) ) ;
V_4 . V_5 = V_2 ;
return F_2 ( V_1 , & V_4 ) ;
}
static int
F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 V_4 ;
memcpy ( & V_4 , V_1 -> V_4 , sizeof( struct V_3 ) ) ;
V_4 . V_6 = V_2 ;
return F_2 ( V_1 , & V_4 ) ;
}
static int
F_4 ( struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_8 ;
int V_9 = 0 ;
F_5 ( L_1 , V_10 , F_6 ( V_7 ) ) ;
if ( V_11 -> V_12 -> V_13 )
V_9 = V_11 -> V_12 -> V_13 ( V_7 , 1 ) ;
return V_9 ;
}
static int
F_7 ( struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_8 ;
int V_9 = 0 ;
F_5 ( L_1 , V_10 , F_6 ( V_7 ) ) ;
F_8 ( & V_14 ) ;
F_5 ( L_2 , V_10 , F_6 ( V_7 ) ) ;
V_9 = F_9 ( V_7 ) ;
if ( V_9 ) {
F_10 ( L_3 ,
V_10 , F_6 ( V_7 ) ) ;
goto V_15;
}
F_5 ( L_4 , V_10 , F_6 ( V_7 ) ) ;
if ( F_11 ( V_7 ) ) {
F_10 ( L_5 ,
V_10 , F_6 ( V_7 ) ) ;
V_9 = - V_16 ;
goto V_15;
}
F_12 ( V_7 ) ;
if ( V_11 -> V_12 -> V_13 ) {
V_9 = V_11 -> V_12 -> V_13 ( V_7 , 0 ) ;
if ( V_9 )
goto V_15;
}
if ( F_3 ( V_7 -> V_1 , 0 ) )
F_13 ( L_6 ) ;
if ( V_7 -> V_17 ) {
V_7 -> V_17 = 0 ;
F_14 ( & V_17 ) ;
}
V_15:
F_15 ( & V_14 ) ;
return V_9 ;
}
static T_1
F_16 ( struct V_7 * V_7 )
{
T_1 V_18 = 1 ;
if ( V_11 -> V_12 -> V_19 )
V_18 = V_11 -> V_12 -> V_19 ( V_7 ) ;
return V_18 ;
}
static int
F_17 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_7 * V_7 = V_1 -> V_8 ;
* V_2 = F_16 ( V_7 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_7 * V_7 = V_1 -> V_8 ;
* V_2 = F_19 ( V_7 ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_1 , T_1 V_20 )
{
return F_21 ( V_1 -> V_8 , V_20 ) ;
}
static int
F_22 ( struct V_1 * V_1 , T_1 * V_2 )
{
* V_2 = V_1 -> V_4 -> V_6 ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_1 , T_1 * V_2 )
{
* V_2 = V_1 -> V_4 -> V_5 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_7 * V_7 = V_1 -> V_8 ;
F_25 ( V_7 -> V_1 -> V_4 ) ;
F_25 ( V_7 -> V_1 ) ;
if ( V_7 -> V_21 )
F_26 ( V_7 -> V_21 ) ;
F_25 ( V_7 ) ;
}
int
F_27 ( struct V_22 * V_23 , T_1 V_24 , T_1 V_25 )
{
struct V_7 * V_7 ;
struct V_1 * V_1 ;
struct V_3 * V_4 ;
char V_26 [ V_27 ] ;
int V_20 ;
int V_28 ;
if ( ! ( V_11 && V_23 ) )
return - V_16 ;
for ( V_28 = V_24 ; V_28 <= V_25 ; ++ V_28 ) {
V_7 = F_28 ( sizeof ( struct V_7 ) , V_29 ) ;
if ( ! V_7 ) {
V_20 = - V_30 ;
goto error;
}
V_1 =
F_28 ( sizeof ( struct V_1 ) , V_29 ) ;
if ( ! V_1 ) {
V_20 = - V_30 ;
goto V_31;
}
V_7 -> V_1 = V_1 ;
V_4 = F_28 ( sizeof ( struct V_3 ) , V_29 ) ;
if ( ! V_4 ) {
V_20 = - V_30 ;
goto V_32;
}
V_1 -> V_4 = V_4 ;
V_7 -> V_23 = V_23 ;
V_7 -> V_33 = V_28 ;
V_7 -> V_34 = F_29 ( V_28 , 0 ) ;
snprintf ( V_26 , V_27 , L_7 , V_23 -> V_33 , V_28 ) ;
V_1 -> V_8 = V_7 ;
V_1 -> V_35 = & F_24 ;
V_1 -> V_12 = & V_36 ;
F_5 ( L_8 , V_26 ) ;
V_4 -> V_37 = F_16 ( V_7 ) ;
V_4 -> V_38 = F_19 ( V_7 ) ;
F_5 ( L_9 , V_26 ) ;
V_20 = F_30 ( V_7 -> V_1 , V_23 , V_28 , V_26 ) ;
if ( V_20 ) {
F_10 ( L_10 , V_20 ) ;
goto V_39;
}
F_5 ( L_11 , F_6 ( V_7 ) ) ;
F_8 ( & V_14 ) ;
F_31 ( & V_7 -> V_40 , & V_40 ) ;
V_41 ++ ;
F_15 ( & V_14 ) ;
}
return 0 ;
V_39:
F_25 ( V_4 ) ;
V_32:
F_25 ( V_1 ) ;
V_31:
F_25 ( V_7 ) ;
error:
return V_20 ;
}
int
F_32 ( struct V_22 * V_23 )
{
struct V_7 * V_7 ;
struct V_7 * V_42 ;
int V_20 = 0 ;
F_8 ( & V_14 ) ;
if ( ! V_41 ) {
F_15 ( & V_14 ) ;
return - 1 ;
}
F_33 (slot, tmp, &slot_list, slot_list) {
if ( V_7 -> V_23 == V_23 ) {
F_34 ( & V_7 -> V_40 ) ;
V_41 -- ;
F_5 ( L_12 , F_6 ( V_7 ) ) ;
V_20 = F_35 ( V_7 -> V_1 ) ;
if ( V_20 ) {
F_10 ( L_13 ,
V_20 ) ;
break;
}
}
}
F_15 ( & V_14 ) ;
return V_20 ;
}
static T_2
F_36 ( int V_43 , void * V_44 )
{
F_5 ( L_14 ) ;
if ( ( V_11 -> V_45 & V_46 ) &&
! V_11 -> V_12 -> V_47 ( V_11 -> V_48 ) ) {
F_5 ( L_15 ) ;
return V_49 ;
}
V_11 -> V_12 -> V_50 () ;
F_37 ( V_51 ) ;
return V_52 ;
}
static int
F_38 ( int V_53 )
{
struct V_7 * V_7 ;
struct V_54 * V_21 ;
F_5 ( L_16 , V_10 ) ;
F_39 ( & V_14 ) ;
if ( ! V_41 ) {
F_40 ( & V_14 ) ;
return - 1 ;
}
F_41 (slot, &slot_list, slot_list) {
F_5 ( L_17 , V_10 , F_6 ( V_7 ) ) ;
if ( V_53 && F_42 ( V_7 ) )
F_5 ( L_18 ,
V_10 , F_6 ( V_7 ) ) ;
V_21 = F_43 ( V_7 -> V_23 , F_29 ( V_7 -> V_33 , 0 ) ) ;
if ( V_21 ) {
if ( F_3 ( V_7 -> V_1 , 1 ) )
F_13 ( L_6 ) ;
if ( F_1 ( V_7 -> V_1 , 1 ) )
F_13 ( L_19 ) ;
V_7 -> V_21 = V_21 ;
}
}
F_40 ( & V_14 ) ;
F_5 ( L_20 , V_10 ) ;
return 0 ;
}
static int
F_44 ( void )
{
struct V_7 * V_7 ;
int V_55 ;
int V_56 ;
T_3 V_57 ;
F_39 ( & V_14 ) ;
if ( ! V_41 ) {
F_40 ( & V_14 ) ;
F_10 ( L_21 ) ;
return - 1 ;
}
V_55 = V_56 = 0 ;
F_41 (slot, &slot_list, slot_list) {
F_5 ( L_17 , V_10 , F_6 ( V_7 ) ) ;
if ( F_42 ( V_7 ) ) {
if ( V_7 -> V_21 ) {
F_13 ( L_22 ,
F_6 ( V_7 ) ) ;
V_56 ++ ;
continue;
}
F_5 ( L_23 , V_10 , F_6 ( V_7 ) ) ;
V_57 = F_45 ( V_7 ) ;
F_5 ( L_24 ,
V_10 , F_6 ( V_7 ) , V_57 ) ;
F_5 ( L_25 ,
V_10 , F_6 ( V_7 ) ) ;
if ( F_46 ( V_7 ) ) {
F_10 ( L_26 ,
V_10 , F_6 ( V_7 ) ) ;
continue;
}
F_5 ( L_27 ,
V_10 , F_6 ( V_7 ) ) ;
V_57 = F_45 ( V_7 ) ;
F_5 ( L_28 ,
V_10 , F_6 ( V_7 ) , V_57 ) ;
if ( F_1 ( V_7 -> V_1 , 1 ) )
F_13 ( L_19 ) ;
if ( F_3 ( V_7 -> V_1 , 1 ) )
F_13 ( L_6 ) ;
F_47 ( V_7 ) ;
V_57 = F_45 ( V_7 ) ;
F_5 ( L_29 ,
V_10 , F_6 ( V_7 ) , V_57 ) ;
V_56 ++ ;
} else if ( F_48 ( V_7 ) ) {
F_5 ( L_30 ,
V_10 , F_6 ( V_7 ) ) ;
V_57 = F_45 ( V_7 ) ;
F_5 ( L_31 ,
V_10 , F_6 ( V_7 ) , V_57 ) ;
if ( ! V_7 -> V_17 ) {
if ( F_1 ( V_7 -> V_1 , 0 ) )
F_13 ( L_19 ) ;
V_7 -> V_17 = 1 ;
F_49 ( & V_17 ) ;
}
V_55 ++ ;
} else if ( V_7 -> V_17 ) {
V_57 = F_45 ( V_7 ) ;
if ( V_57 == 0xffff ) {
F_10 ( L_32 ,
F_6 ( V_7 ) ) ;
if ( F_3 ( V_7 -> V_1 , 0 ) )
F_13 ( L_6 ) ;
V_7 -> V_17 = 0 ;
F_14 ( & V_17 ) ;
}
}
}
F_40 ( & V_14 ) ;
F_5 ( L_33 ,
V_56 , V_55 , F_50 ( & V_17 ) ) ;
if ( V_56 || V_55 )
return V_55 ;
else if ( ! F_50 ( & V_17 ) ) {
F_10 ( L_34 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_51 ( void * V_44 )
{
int V_58 ;
F_5 ( L_35 , V_10 ) ;
while ( 1 ) {
F_5 ( L_36 ) ;
F_52 ( V_59 ) ;
F_53 () ;
if ( F_54 () )
break;
do {
V_58 = F_44 () ;
if ( V_58 > 0 ) {
F_55 ( 500 ) ;
} else if ( V_58 < 0 ) {
F_5 ( L_37 , V_10 ) ;
V_60 = 1 ;
goto V_61;
}
} while ( F_50 ( & V_17 ) && ! F_54 () );
if ( F_54 () )
break;
F_5 ( L_38 , V_10 ) ;
V_11 -> V_12 -> V_62 () ;
}
V_61:
return 0 ;
}
static int
F_56 ( void * V_44 )
{
int V_58 ;
while ( 1 ) {
if ( F_54 () || F_57 ( V_63 ) )
break;
if ( V_11 -> V_12 -> V_64 () ) {
do {
V_58 = F_44 () ;
if ( V_58 > 0 ) {
F_55 ( 500 ) ;
} else if ( V_58 < 0 ) {
F_5 ( L_37 , V_10 ) ;
V_60 = 1 ;
goto V_61;
}
} while ( F_50 ( & V_17 ) && ! F_54 () );
}
F_55 ( 100 ) ;
}
V_61:
return 0 ;
}
static int
F_58 ( void )
{
if ( V_11 -> V_43 )
V_51 = F_59 ( F_51 , NULL , L_39 ) ;
else
V_51 = F_59 ( F_56 , NULL , L_40 ) ;
if ( F_60 ( V_51 ) ) {
F_10 ( L_41 ) ;
return F_61 ( V_51 ) ;
}
V_60 = 0 ;
return 0 ;
}
static void
F_62 ( void )
{
F_63 ( V_51 ) ;
V_60 = 1 ;
}
int
F_64 ( struct V_65 * V_66 )
{
int V_20 = 0 ;
if ( V_11 )
return - 1 ;
if ( ! ( V_66 && V_66 -> V_12 ) )
return - V_67 ;
if ( V_66 -> V_43 ) {
if ( ! ( V_66 -> V_12 -> V_62 &&
V_66 -> V_12 -> V_50 ) )
V_20 = - V_67 ;
if ( F_65 ( V_66 -> V_43 ,
F_36 ,
V_66 -> V_45 ,
V_68 ,
V_66 -> V_48 ) ) {
F_10 ( L_42 ,
V_66 -> V_43 ) ;
V_20 = - V_16 ;
}
F_5 ( L_43 ,
V_10 , V_66 -> V_43 ) ;
}
if ( ! V_20 )
V_11 = V_66 ;
return V_20 ;
}
static void
F_66 ( void )
{
struct V_7 * V_7 ;
struct V_7 * V_42 ;
F_8 ( & V_14 ) ;
if ( ! V_41 )
goto V_69;
F_33 (slot, tmp, &slot_list, slot_list) {
F_34 ( & V_7 -> V_40 ) ;
F_35 ( V_7 -> V_1 ) ;
}
V_69:
F_15 ( & V_14 ) ;
return;
}
int
F_67 ( struct V_65 * V_70 )
{
int V_20 = 0 ;
if ( V_11 ) {
if ( ! V_60 )
F_62 () ;
if ( V_11 -> V_43 )
F_68 ( V_11 -> V_43 , V_11 -> V_48 ) ;
V_11 = NULL ;
F_66 () ;
} else
V_20 = - V_16 ;
return V_20 ;
}
int
F_69 ( void )
{
static int V_24 = 1 ;
int V_20 ;
F_5 ( L_16 , V_10 ) ;
if ( ! V_11 )
return - V_16 ;
F_39 ( & V_14 ) ;
if ( F_70 ( & V_40 ) ) {
F_40 ( & V_14 ) ;
return - V_16 ;
}
F_40 ( & V_14 ) ;
V_20 = F_38 ( V_24 ) ;
if ( V_24 )
V_24 = 0 ;
if ( V_20 )
return V_20 ;
V_20 = F_58 () ;
if ( V_20 )
return V_20 ;
F_5 ( L_44 , V_10 ) ;
if ( V_11 -> V_43 ) {
F_5 ( L_45 , V_10 ) ;
V_11 -> V_12 -> V_62 () ;
}
F_5 ( L_20 , V_10 ) ;
return 0 ;
}
int
F_71 ( void )
{
if ( ! V_11 )
return - V_16 ;
if ( V_11 -> V_43 ) {
F_5 ( L_46 , V_10 ) ;
V_11 -> V_12 -> V_50 () ;
}
F_62 () ;
return 0 ;
}
int T_4
F_72 ( int V_71 )
{
V_72 = V_71 ;
return 0 ;
}
void T_5
F_73 ( void )
{
F_71 () ;
F_67 ( V_11 ) ;
}
