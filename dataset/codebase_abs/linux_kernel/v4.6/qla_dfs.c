static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 = V_4 -> V_14 . V_12 ;
F_2 ( V_2 , L_1 , V_4 -> V_15 ) ;
if ( V_13 ) {
F_2 ( V_2 , L_2 ) ;
F_3 ( & V_7 -> V_13 . V_16 , V_9 ) ;
F_4 (sess, &tgt->sess_list, sess_list_entry) {
F_2 ( V_2 , L_3 ,
V_11 -> V_17 . V_18 . V_19 , V_11 -> V_17 . V_18 . V_20 ,
V_11 -> V_17 . V_18 . V_21 , V_11 -> V_22 ,
V_11 -> V_23 ) ;
}
F_5 ( & V_7 -> V_13 . V_16 , V_9 ) ;
}
return 0 ;
}
static int
F_6 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
return F_7 ( V_25 , F_1 , V_4 ) ;
}
static int
F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_27 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_9 ( V_2 , L_4 ) ;
F_2 ( V_2 , L_5 ,
V_7 -> V_28 ) ;
F_2 ( V_2 , L_6 ,
V_7 -> V_29 ) ;
F_2 ( V_2 , L_7 ,
V_7 -> V_30 ) ;
F_2 ( V_2 , L_8 ,
V_7 -> V_31 ) ;
F_2 ( V_2 , L_9 , V_7 -> V_32 ) ;
F_2 ( V_2 , L_10 , V_7 -> V_33 ) ;
F_2 ( V_2 , L_11 , V_7 -> V_34 ) ;
F_2 ( V_2 , L_12 , V_7 -> V_35 ) ;
return 0 ;
}
static int
F_10 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_27 * V_4 = V_24 -> V_26 ;
return F_7 ( V_25 , F_8 , V_4 ) ;
}
static int
F_11 ( struct V_1 * V_2 , void * V_3 )
{
struct V_27 * V_4 = V_2 -> V_5 ;
F_9 ( V_2 , L_13 ) ;
F_2 ( V_2 , L_14 ,
V_4 -> V_36 . V_37 ) ;
F_2 ( V_2 , L_15 ,
V_4 -> V_36 . V_38 ) ;
F_2 ( V_2 , L_16 ,
V_4 -> V_36 . V_39 ) ;
F_2 ( V_2 , L_17 ,
V_4 -> V_36 . V_40 ) ;
F_2 ( V_2 , L_18 ,
V_4 -> V_36 . V_41 ) ;
F_2 ( V_2 , L_19 ,
V_4 -> V_36 . V_42 ) ;
F_2 ( V_2 , L_20 ,
V_4 -> V_36 . V_43 ) ;
F_2 ( V_2 , L_21 ,
V_4 -> V_36 . V_44 ) ;
F_2 ( V_2 , L_22 ,
V_4 -> V_36 . V_45 ) ;
return 0 ;
}
static int
F_12 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_27 * V_4 = V_24 -> V_26 ;
return F_7 ( V_25 , F_11 , V_4 ) ;
}
static int
F_13 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
T_2 V_46 ;
T_2 * V_47 ;
T_3 V_48 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_14 ( & V_7 -> V_49 ) ;
F_9 ( V_2 , L_23 ) ;
F_2 ( V_2 , L_24 , ( unsigned long long ) V_7 -> V_50 ) ;
F_2 ( V_2 , L_25 , ( unsigned long long ) V_7 -> V_51 ) ;
F_9 ( V_2 , L_26 ) ;
F_2 ( V_2 , L_27 ,
V_7 -> V_52 [ 0 ] , V_7 -> V_52 [ 2 ] , V_7 -> V_52 [ 3 ] , V_7 -> V_52 [ 4 ] ,
V_7 -> V_52 [ 5 ] , V_7 -> V_52 [ 6 ] ) ;
V_47 = ( T_2 * ) V_7 -> V_47 ;
V_48 = ( unsigned long long ) V_7 -> V_51 ;
for ( V_46 = 0 ; V_46 < F_15 ( V_7 -> V_53 ) / 4 ; V_46 ++ ) {
if ( V_46 % 8 == 0 )
F_2 ( V_2 , L_28 ,
( unsigned long long ) ( ( V_46 * 4 ) + V_48 ) ) ;
else
F_16 ( V_2 , ' ' ) ;
F_2 ( V_2 , L_29 , * V_47 ++ ) ;
}
F_9 ( V_2 , L_30 ) ;
F_17 ( & V_7 -> V_49 ) ;
return 0 ;
}
static int
F_18 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_54 ;
if ( ! V_7 -> V_9 . V_55 )
goto V_56;
F_14 ( & V_7 -> V_49 ) ;
V_54 = F_19 ( V_4 , & V_7 -> V_50 , & V_7 -> V_57 ) ;
if ( V_54 )
F_20 ( V_58 , V_4 , 0x705c ,
L_31 , V_54 ) ;
V_7 -> V_9 . V_55 = 0 ;
F_17 ( & V_7 -> V_49 ) ;
V_56:
return F_7 ( V_25 , F_13 , V_4 ) ;
}
static int
F_21 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_54 ;
if ( V_7 -> V_9 . V_55 )
goto V_56;
F_14 ( & V_7 -> V_49 ) ;
V_7 -> V_9 . V_55 = 1 ;
memset ( V_7 -> V_47 , 0 , F_15 ( V_7 -> V_53 ) ) ;
V_54 = F_22 ( V_4 , V_7 -> V_51 , V_7 -> V_53 ,
V_7 -> V_52 , & V_7 -> V_53 ) ;
if ( V_54 ) {
F_20 ( V_58 , V_4 , 0x700d ,
L_32 , V_54 ) ;
V_7 -> V_9 . V_55 = 0 ;
}
F_17 ( & V_7 -> V_49 ) ;
V_56:
return F_23 ( V_24 , V_25 ) ;
}
int
F_24 ( T_1 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
if ( ! F_25 ( V_7 ) && ! F_26 ( V_7 ) && ! F_27 ( V_7 ) &&
! F_28 ( V_7 ) )
goto V_56;
if ( ! V_7 -> V_47 )
goto V_56;
if ( V_59 )
goto V_60;
F_29 ( & V_61 , 0 ) ;
V_59 = F_30 ( V_62 , NULL ) ;
if ( ! V_59 ) {
F_31 ( V_63 , V_4 , 0x00f7 ,
L_33 ) ;
goto V_56;
}
V_60:
if ( V_7 -> V_64 )
goto V_65;
F_32 ( & V_7 -> V_49 ) ;
V_7 -> V_64 = F_30 ( V_4 -> V_15 , V_59 ) ;
if ( ! V_7 -> V_64 ) {
F_31 ( V_63 , V_4 , 0x00f8 ,
L_34 ) ;
goto V_56;
}
F_33 ( & V_61 ) ;
V_65:
V_7 -> V_66 = F_34 ( L_35 ,
V_67 , V_7 -> V_64 , V_4 , & V_68 ) ;
if ( ! V_7 -> V_66 ) {
F_31 ( V_63 , V_4 , 0x00fd ,
L_36 ) ;
goto V_56;
}
V_7 -> V_69 = F_34 ( L_37 , V_67 ,
V_7 -> V_64 , V_4 , & V_70 ) ;
if ( ! V_7 -> V_69 ) {
F_31 ( V_63 , V_4 , 0xd301 ,
L_38 ) ;
goto V_56;
}
V_7 -> V_71 = F_34 ( L_39 , V_67 , V_7 -> V_64 , V_4 ,
& V_72 ) ;
if ( ! V_7 -> V_71 ) {
F_31 ( V_63 , V_4 , 0x00f9 ,
L_40 ) ;
goto V_56;
}
V_7 -> V_13 . V_73 = F_34 ( L_41 ,
V_67 , V_7 -> V_64 , V_4 , & V_74 ) ;
if ( ! V_7 -> V_13 . V_73 ) {
F_31 ( V_63 , V_4 , 0xffff ,
L_42 ) ;
goto V_56;
}
V_56:
return 0 ;
}
int
F_35 ( T_1 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
if ( V_7 -> V_13 . V_73 ) {
F_36 ( V_7 -> V_13 . V_73 ) ;
V_7 -> V_13 . V_73 = NULL ;
}
if ( V_7 -> V_66 ) {
F_36 ( V_7 -> V_66 ) ;
V_7 -> V_66 = NULL ;
}
if ( V_7 -> V_69 ) {
F_36 ( V_7 -> V_69 ) ;
V_7 -> V_69 = NULL ;
}
if ( V_7 -> V_71 ) {
F_36 ( V_7 -> V_71 ) ;
V_7 -> V_71 = NULL ;
}
if ( V_7 -> V_64 ) {
F_36 ( V_7 -> V_64 ) ;
V_7 -> V_64 = NULL ;
F_37 ( & V_61 ) ;
}
if ( F_38 ( & V_61 ) == 0 &&
V_59 ) {
F_36 ( V_59 ) ;
V_59 = NULL ;
}
return 0 ;
}
