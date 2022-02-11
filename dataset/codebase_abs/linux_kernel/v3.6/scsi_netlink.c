static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
int V_9 , V_10 ;
while ( V_2 -> V_11 >= F_2 ( 0 ) ) {
V_9 = 0 ;
V_4 = F_3 ( V_2 ) ;
if ( ( V_4 -> V_12 < ( sizeof( * V_4 ) + sizeof( * V_6 ) ) ) ||
( V_2 -> V_11 < V_4 -> V_12 ) ) {
F_4 ( V_13 L_1 ,
V_14 ) ;
return;
}
V_8 = F_5 ( V_4 -> V_12 ) ;
if ( V_8 > V_2 -> V_11 )
V_8 = V_2 -> V_11 ;
if ( V_4 -> V_15 != V_16 ) {
V_9 = - V_17 ;
goto V_18;
}
V_6 = F_6 ( V_4 ) ;
if ( ( V_6 -> V_19 != V_20 ) ||
( V_6 -> V_21 != V_22 ) ) {
V_9 = - V_23 ;
goto V_18;
}
if ( ! F_7 ( V_24 ) ) {
V_9 = - V_25 ;
goto V_18;
}
if ( V_4 -> V_12 < ( sizeof( * V_4 ) + V_6 -> V_26 ) ) {
F_4 ( V_13 L_2 ,
V_14 ) ;
goto V_18;
}
F_8 ( & V_27 , V_7 ) ;
V_10 = V_6 -> V_28 ;
if ( ( V_10 < V_29 ) &&
! ( V_30 [ V_10 ] . V_7 & V_31 ) &&
( V_30 [ V_10 ] . V_32 ) ) {
V_30 [ V_10 ] . V_33 ++ ;
F_9 ( & V_27 , V_7 ) ;
V_9 = V_30 [ V_10 ] . V_32 ( V_2 ) ;
F_8 ( & V_27 , V_7 ) ;
V_30 [ V_10 ] . V_33 -- ;
} else
V_9 = - V_34 ;
F_9 ( & V_27 , V_7 ) ;
V_18:
if ( ( V_9 ) || ( V_4 -> V_35 & V_36 ) )
F_10 ( V_2 , V_4 , V_9 ) ;
F_11 ( V_2 , V_8 ) ;
}
}
static int
F_12 ( struct V_37 * V_38 , unsigned long V_39 , void * V_40 )
{
struct V_41 * V_42 = V_40 ;
struct V_43 * V_44 ;
unsigned long V_7 ;
int V_10 ;
if ( V_42 -> V_45 != V_46 )
return V_47 ;
F_8 ( & V_27 , V_7 ) ;
V_48 |= V_49 ;
for ( V_10 = 0 ; V_10 < V_29 ; V_10 ++ ) {
if ( ! ( V_30 [ V_10 ] . V_7 & V_31 ) &&
( V_30 [ V_10 ] . V_50 ) ) {
F_9 ( & V_27 , V_7 ) ;
V_30 [ V_10 ] . V_50 ( V_38 , V_39 , V_40 ) ;
F_8 ( & V_27 , V_7 ) ;
}
}
F_13 (driver, &scsi_nl_drivers, next) {
if ( ! ( V_44 -> V_7 & V_31 ) &&
( V_44 -> V_51 ) ) {
F_9 ( & V_27 , V_7 ) ;
V_44 -> V_51 ( V_38 , V_39 , V_40 ) ;
F_8 ( & V_27 , V_7 ) ;
}
}
V_48 &= ~ V_49 ;
F_9 ( & V_27 , V_7 ) ;
return V_47 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_52 = F_6 ( V_4 ) ;
struct V_43 * V_44 ;
struct V_53 * V_54 ;
unsigned long V_7 ;
int V_9 = 0 , V_55 , V_56 ;
V_56 = F_15 ( V_2 ) -> V_56 ;
switch ( V_52 -> V_57 ) {
case V_58 :
{
struct V_59 * V_60 = F_6 ( V_4 ) ;
F_8 ( & V_27 , V_7 ) ;
V_55 = 0 ;
F_13 (driver, &scsi_nl_drivers, next) {
if ( V_44 -> V_61 == V_60 -> V_61 ) {
V_55 = 1 ;
break;
}
}
if ( ( ! V_55 ) || ( ! V_44 -> V_62 ) ) {
F_9 ( & V_27 , V_7 ) ;
V_9 = - V_63 ;
goto V_64;
}
if ( V_44 -> V_7 & V_31 ) {
F_9 ( & V_27 , V_7 ) ;
V_9 = - V_65 ;
goto V_64;
}
V_44 -> V_33 ++ ;
F_9 ( & V_27 , V_7 ) ;
V_54 = F_16 ( V_60 -> V_66 ) ;
if ( ! V_54 ) {
V_9 = - V_67 ;
goto V_68;
}
if ( V_54 -> V_69 != V_44 -> V_69 ) {
V_9 = - V_70 ;
goto V_71;
}
V_9 = V_44 -> V_62 ( V_54 , ( void * ) & V_60 [ 1 ] ,
V_60 -> V_72 , V_56 ) ;
V_71:
F_17 ( V_54 ) ;
V_68:
F_8 ( & V_27 , V_7 ) ;
V_44 -> V_33 -- ;
F_9 ( & V_27 , V_7 ) ;
break;
}
default:
V_9 = - V_73 ;
break;
}
V_64:
if ( V_9 )
F_4 ( V_13 L_3 ,
V_14 , V_52 -> V_57 , V_9 ) ;
return V_9 ;
}
int
F_18 ( T_2 V_10 ,
int (* V_32)( struct V_1 * ) ,
void (* V_50)( struct V_37 * , unsigned long , void * ) )
{
unsigned long V_7 ;
int V_9 = 0 ;
if ( V_10 >= V_29 )
return - V_70 ;
F_8 ( & V_27 , V_7 ) ;
if ( V_48 & V_49 ) {
F_9 ( & V_27 , V_7 ) ;
F_19 ( 1 ) ;
F_8 ( & V_27 , V_7 ) ;
}
if ( V_30 [ V_10 ] . V_32 || V_30 [ V_10 ] . V_50 ) {
V_9 = - V_74 ;
goto V_75;
}
V_30 [ V_10 ] . V_32 = V_32 ;
V_30 [ V_10 ] . V_50 = V_50 ;
V_30 [ V_10 ] . V_7 = 0 ;
V_30 [ V_10 ] . V_33 = 0 ;
V_75:
F_9 ( & V_27 , V_7 ) ;
return V_9 ;
}
void
F_20 ( T_2 V_10 )
{
unsigned long V_7 ;
F_8 ( & V_27 , V_7 ) ;
if ( V_48 & V_49 ) {
F_9 ( & V_27 , V_7 ) ;
F_19 ( 1 ) ;
F_8 ( & V_27 , V_7 ) ;
}
if ( V_10 < V_29 ) {
V_30 [ V_10 ] . V_7 |= V_31 ;
while ( V_30 [ V_10 ] . V_33 != 0 ) {
F_9 ( & V_27 , V_7 ) ;
F_21 ( V_76 / 4 ) ;
F_8 ( & V_27 , V_7 ) ;
}
V_30 [ V_10 ] . V_32 = NULL ;
V_30 [ V_10 ] . V_50 = NULL ;
V_30 [ V_10 ] . V_7 = 0 ;
}
F_9 ( & V_27 , V_7 ) ;
return;
}
int
F_22 ( T_3 V_61 , struct V_77 * V_69 ,
int (* F_23)( struct V_53 * V_54 , void * V_78 ,
T_1 V_11 , T_1 V_56 ) ,
void (* F_24)( struct V_37 * V_79 ,
unsigned long V_39 , void * V_80 ) )
{
struct V_43 * V_44 ;
unsigned long V_7 ;
V_44 = F_25 ( sizeof( * V_44 ) , V_81 ) ;
if ( F_26 ( ! V_44 ) ) {
F_4 ( V_82 L_4 , V_14 ) ;
return - V_83 ;
}
V_44 -> V_62 = F_23 ;
V_44 -> V_51 = F_24 ;
V_44 -> V_69 = V_69 ;
V_44 -> V_61 = V_61 ;
F_8 ( & V_27 , V_7 ) ;
if ( V_48 & V_49 ) {
F_9 ( & V_27 , V_7 ) ;
F_19 ( 1 ) ;
F_8 ( & V_27 , V_7 ) ;
}
F_27 ( & V_44 -> V_84 , & V_85 ) ;
F_9 ( & V_27 , V_7 ) ;
return 0 ;
}
void
F_28 ( T_3 V_61 )
{
struct V_43 * V_44 ;
unsigned long V_7 ;
F_8 ( & V_27 , V_7 ) ;
if ( V_48 & V_49 ) {
F_9 ( & V_27 , V_7 ) ;
F_19 ( 1 ) ;
F_8 ( & V_27 , V_7 ) ;
}
F_13 (driver, &scsi_nl_drivers, next) {
if ( V_44 -> V_61 == V_61 ) {
V_44 -> V_7 |= V_31 ;
while ( V_44 -> V_33 != 0 ) {
F_9 ( & V_27 , V_7 ) ;
F_21 ( V_76 / 4 ) ;
F_8 ( & V_27 , V_7 ) ;
}
F_29 ( & V_44 -> V_84 ) ;
F_30 ( V_44 ) ;
F_9 ( & V_27 , V_7 ) ;
return;
}
}
F_9 ( & V_27 , V_7 ) ;
F_4 ( V_82 L_5 ,
V_14 , ( unsigned long long ) V_61 ) ;
return;
}
void
F_31 ( void )
{
int error ;
struct V_86 V_87 = {
. V_88 = F_1 ,
. V_89 = V_90 ,
} ;
F_32 ( & V_85 ) ;
error = F_33 ( & V_91 ) ;
if ( error ) {
F_4 ( V_82 L_6 ,
V_14 , error ) ;
return;
}
V_92 = F_34 ( & V_93 , V_46 ,
V_94 , & V_87 ) ;
if ( ! V_92 ) {
F_4 ( V_82 L_7 ,
V_14 ) ;
F_35 ( & V_91 ) ;
return;
}
error = F_18 ( V_95 ,
F_14 , NULL ) ;
if ( error )
F_4 ( V_82 L_8
L_9 , V_14 , error ) ;
return;
}
void
F_36 ( void )
{
F_20 ( V_95 ) ;
if ( V_92 ) {
F_37 ( V_92 ) ;
F_35 ( & V_91 ) ;
}
return;
}
void
F_38 ( T_1 V_56 , struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
const char * V_96 ;
char * V_97 ;
T_1 V_11 , V_98 ;
int V_9 ;
if ( ! V_92 ) {
V_9 = - V_34 ;
V_96 = L_10 ;
goto V_99;
}
V_11 = F_2 ( V_6 -> V_26 ) ;
V_98 = F_2 ( V_11 ) ;
V_2 = F_39 ( V_98 , V_81 ) ;
if ( ! V_2 ) {
V_9 = - V_100 ;
V_96 = L_11 ;
goto V_99;
}
V_4 = F_40 ( V_2 , V_56 , 0 , V_16 , V_11 - sizeof( * V_4 ) , 0 ) ;
if ( ! V_4 ) {
V_9 = - V_100 ;
V_96 = L_12 ;
goto V_101;
}
V_97 = F_6 ( V_4 ) ;
memcpy ( V_97 , V_6 , V_6 -> V_26 ) ;
V_9 = F_41 ( V_92 , V_2 , V_56 ) ;
if ( V_9 < 0 ) {
V_96 = L_13 ;
goto V_99;
}
return;
V_101:
F_42 ( V_2 ) ;
V_99:
F_4 ( V_13
L_14
L_15 ,
V_14 , V_56 , V_6 -> V_28 , V_6 -> V_57 , V_6 -> V_26 ,
V_96 , V_9 ) ;
return;
}
int
F_43 ( T_1 V_56 , unsigned short V_66 , T_3 V_61 ,
char * V_102 , T_1 V_103 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_59 * V_60 ;
T_1 V_11 , V_98 ;
int V_9 ;
if ( ! V_92 ) {
V_9 = - V_34 ;
goto V_104;
}
V_11 = F_44 ( sizeof( * V_60 ) + V_103 ) ;
V_98 = F_2 ( V_11 ) ;
V_2 = F_39 ( V_98 , V_81 ) ;
if ( ! V_2 ) {
V_9 = - V_100 ;
goto V_104;
}
V_4 = F_40 ( V_2 , 0 , 0 , V_16 ,
V_98 - sizeof( * V_4 ) , 0 ) ;
if ( ! V_4 ) {
V_9 = - V_100 ;
goto V_105;
}
V_60 = F_6 ( V_4 ) ;
F_45 ( & V_60 -> V_52 , V_95 ,
V_58 , V_11 ) ;
V_60 -> V_61 = V_61 ;
V_60 -> V_66 = V_66 ;
V_60 -> V_72 = V_103 ;
memcpy ( & V_60 [ 1 ] , V_102 , V_103 ) ;
V_9 = F_41 ( V_92 , V_2 , V_56 ) ;
if ( V_9 )
goto V_104;
return 0 ;
V_105:
F_42 ( V_2 ) ;
V_104:
F_4 ( V_13
L_16 ,
V_14 , V_66 , V_9 ) ;
return V_9 ;
}
