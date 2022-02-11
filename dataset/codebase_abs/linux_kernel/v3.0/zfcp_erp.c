static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 ,
V_4 | V_3 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_5 * V_7 ;
F_4 (curr_act, &act->adapter->erp_running_head, list)
if ( V_6 == V_7 )
return V_8 ;
return 0 ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_6 ( & V_6 -> V_9 , & V_6 -> V_2 -> V_10 ) ;
F_7 ( L_1 , V_6 ) ;
F_8 ( & V_2 -> V_11 ) ;
F_7 ( L_2 , V_6 ) ;
}
static void F_9 ( struct V_5 * V_6 )
{
V_6 -> V_12 |= V_13 ;
if ( F_3 ( V_6 ) == V_8 )
F_5 ( V_6 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
if ( F_12 ( & V_17 -> V_12 ) & V_18 )
F_9 ( & V_17 -> V_19 ) ;
}
static void F_13 ( struct V_20 * V_21 )
{
struct V_14 * V_15 ;
if ( F_12 ( & V_21 -> V_12 ) & V_18 )
F_9 ( & V_21 -> V_19 ) ;
else
F_14 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 )
F_10 ( V_15 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
if ( F_12 ( & V_2 -> V_12 ) & V_18 )
F_9 ( & V_2 -> V_19 ) ;
else {
F_16 ( & V_2 -> V_22 ) ;
F_4 (port, &adapter->port_list, list)
F_13 ( V_21 ) ;
F_17 ( & V_2 -> V_22 ) ;
}
}
static int F_18 ( int V_23 , struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_14 * V_15 )
{
int V_24 = V_23 ;
int V_25 , V_26 , V_27 ;
struct V_16 * V_17 ;
switch ( V_23 ) {
case V_28 :
V_17 = F_11 ( V_15 ) ;
V_25 = F_12 ( & V_17 -> V_12 ) ;
if ( V_25 & V_18 )
return 0 ;
V_26 = F_12 ( & V_21 -> V_12 ) ;
if ( ! ( V_26 & V_29 ) ||
V_26 & V_30 )
return 0 ;
if ( ! ( V_26 & V_4 ) )
V_24 = V_31 ;
case V_32 :
V_26 = F_12 ( & V_21 -> V_12 ) ;
if ( ! ( V_26 & V_33 ) )
V_24 = V_31 ;
case V_31 :
V_26 = F_12 ( & V_21 -> V_12 ) ;
if ( V_26 & V_18 )
return 0 ;
V_27 = F_12 ( & V_2 -> V_12 ) ;
if ( ! ( V_27 & V_29 ) ||
V_27 & V_30 )
return 0 ;
if ( V_26 & V_34 )
return V_24 ;
if ( ! ( V_27 & V_4 ) )
V_24 = V_35 ;
case V_35 :
V_27 = F_12 ( & V_2 -> V_12 ) ;
if ( V_27 & V_18 )
return 0 ;
if ( ! ( V_27 & V_29 ) &&
! ( V_27 & V_33 ) )
return 0 ;
}
return V_24 ;
}
static struct V_5 * F_19 ( int V_24 , T_1 V_36 ,
struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_14 * V_15 )
{
struct V_5 * V_19 ;
struct V_16 * V_17 ;
switch ( V_24 ) {
case V_28 :
V_17 = F_11 ( V_15 ) ;
if ( ! ( V_36 & V_37 ) )
if ( F_20 ( V_15 ) )
return NULL ;
F_21 ( V_18 ,
& V_17 -> V_12 ) ;
V_19 = & V_17 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_5 ) ) ;
V_19 -> V_21 = V_21 ;
V_19 -> V_15 = V_15 ;
if ( ! ( F_12 ( & V_17 -> V_12 ) &
V_29 ) )
V_36 |= V_38 ;
break;
case V_31 :
case V_32 :
if ( ! F_22 ( & V_21 -> V_39 ) )
return NULL ;
F_13 ( V_21 ) ;
F_21 ( V_18 , & V_21 -> V_12 ) ;
V_19 = & V_21 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_5 ) ) ;
V_19 -> V_21 = V_21 ;
if ( ! ( F_12 ( & V_21 -> V_12 ) & V_29 ) )
V_36 |= V_38 ;
break;
case V_35 :
F_23 ( & V_2 -> V_40 ) ;
F_15 ( V_2 ) ;
F_21 ( V_18 , & V_2 -> V_12 ) ;
V_19 = & V_2 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_5 ) ) ;
if ( ! ( F_12 ( & V_2 -> V_12 ) &
V_29 ) )
V_36 |= V_38 ;
break;
default:
return NULL ;
}
V_19 -> V_2 = V_2 ;
V_19 -> V_41 = V_24 ;
V_19 -> V_12 = V_36 ;
return V_19 ;
}
static int F_24 ( int V_23 , struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_14 * V_15 ,
char * V_42 , T_1 V_36 )
{
int V_43 = 1 , V_24 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_44 )
return - V_45 ;
V_24 = F_18 ( V_23 , V_2 , V_21 , V_15 ) ;
if ( ! V_24 )
goto V_46;
V_6 = F_19 ( V_24 , V_36 , V_2 , V_21 , V_15 ) ;
if ( ! V_6 )
goto V_46;
F_21 ( V_47 , & V_2 -> V_12 ) ;
++ V_2 -> V_48 ;
F_25 ( & V_6 -> V_9 , & V_2 -> V_10 ) ;
F_8 ( & V_2 -> V_11 ) ;
V_43 = 0 ;
V_46:
F_26 ( V_42 , V_2 , V_21 , V_15 , V_23 , V_24 ) ;
return V_43 ;
}
static int F_27 ( struct V_1 * V_2 ,
int V_49 , char * V_42 )
{
F_1 ( V_2 , V_49 ) ;
F_28 ( V_2 ) ;
if ( F_12 ( & V_2 -> V_12 ) & V_30 ) {
F_29 ( V_2 ,
V_30 ) ;
return - V_45 ;
}
return F_24 ( V_35 ,
V_2 , NULL , NULL , V_42 , 0 ) ;
}
void F_30 ( struct V_1 * V_2 , int V_50 , char * V_42 )
{
unsigned long V_51 ;
F_1 ( V_2 , V_50 ) ;
F_28 ( V_2 ) ;
F_31 ( & V_2 -> V_52 , V_51 ) ;
if ( F_12 ( & V_2 -> V_12 ) & V_30 )
F_29 ( V_2 ,
V_30 ) ;
else
F_24 ( V_35 , V_2 ,
NULL , NULL , V_42 , 0 ) ;
F_32 ( & V_2 -> V_52 , V_51 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_50 ,
char * V_42 )
{
int V_51 = V_29 | V_30 ;
F_30 ( V_2 , V_50 | V_51 , V_42 ) ;
}
void F_34 ( struct V_20 * V_21 , int V_50 , char * V_42 )
{
int V_51 = V_29 | V_30 ;
F_35 ( V_21 , V_50 | V_51 , V_42 ) ;
}
static void F_36 ( struct V_20 * V_21 , int V_50 )
{
F_37 ( V_21 ,
V_4 | V_50 ) ;
}
static void F_38 ( struct V_20 * V_21 , int V_50 ,
char * V_42 )
{
F_36 ( V_21 , V_50 ) ;
F_39 ( V_21 ) ;
if ( F_12 ( & V_21 -> V_12 ) & V_30 )
return;
F_24 ( V_32 ,
V_21 -> V_2 , V_21 , NULL , V_42 , 0 ) ;
}
void F_40 ( struct V_20 * V_21 , int V_50 , char * V_42 )
{
unsigned long V_51 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_31 ( & V_2 -> V_52 , V_51 ) ;
F_38 ( V_21 , V_50 , V_42 ) ;
F_32 ( & V_2 -> V_52 , V_51 ) ;
}
static int F_41 ( struct V_20 * V_21 , int V_50 , char * V_42 )
{
F_36 ( V_21 , V_50 ) ;
F_39 ( V_21 ) ;
if ( F_12 ( & V_21 -> V_12 ) & V_30 ) {
F_42 ( V_21 , V_30 ) ;
return - V_45 ;
}
return F_24 ( V_31 ,
V_21 -> V_2 , V_21 , NULL , V_42 , 0 ) ;
}
int F_35 ( struct V_20 * V_21 , int V_50 , char * V_42 )
{
int V_43 ;
unsigned long V_51 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_31 ( & V_2 -> V_52 , V_51 ) ;
V_43 = F_41 ( V_21 , V_50 , V_42 ) ;
F_32 ( & V_2 -> V_52 , V_51 ) ;
return V_43 ;
}
static void F_43 ( struct V_14 * V_15 , int V_49 )
{
F_44 ( V_15 ,
V_4 | V_49 ) ;
}
static void F_45 ( struct V_14 * V_15 , int V_50 , char * V_42 ,
T_1 V_36 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_1 * V_2 = V_17 -> V_21 -> V_2 ;
F_43 ( V_15 , V_50 ) ;
if ( F_12 ( & V_17 -> V_12 ) & V_30 )
return;
F_24 ( V_28 , V_2 ,
V_17 -> V_21 , V_15 , V_42 , V_36 ) ;
}
void F_46 ( struct V_14 * V_15 , int V_50 , char * V_42 )
{
unsigned long V_51 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_31 ( & V_2 -> V_52 , V_51 ) ;
F_45 ( V_15 , V_50 , V_42 , 0 ) ;
F_32 ( & V_2 -> V_52 , V_51 ) ;
}
void F_47 ( struct V_14 * V_15 , int V_50 , char * V_42 )
{
int V_51 = V_29 | V_30 ;
F_46 ( V_15 , V_50 | V_51 , V_42 ) ;
}
void F_48 ( struct V_14 * V_15 , char * V_42 )
{
unsigned long V_51 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_50 = V_29 | V_30 ;
F_31 ( & V_2 -> V_52 , V_51 ) ;
F_45 ( V_15 , V_50 , V_42 , V_37 ) ;
F_32 ( & V_2 -> V_52 , V_51 ) ;
F_49 ( V_2 ) ;
}
static int F_50 ( unsigned long V_3 , T_2 * V_12 )
{
return ( F_12 ( V_12 ) ^ V_3 ) & V_3 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( F_50 ( V_4 , & V_2 -> V_12 ) )
F_7 ( L_3 , & V_2 -> V_19 ) ;
F_21 ( V_4 , & V_2 -> V_12 ) ;
}
static void F_52 ( struct V_20 * V_21 )
{
if ( F_50 ( V_4 , & V_21 -> V_12 ) )
F_7 ( L_4 , & V_21 -> V_19 ) ;
F_21 ( V_4 , & V_21 -> V_12 ) ;
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
if ( F_50 ( V_4 , & V_17 -> V_12 ) )
F_7 ( L_5 , & F_11 ( V_15 ) -> V_19 ) ;
F_21 ( V_4 , & V_17 -> V_12 ) ;
}
static void F_54 ( struct V_5 * V_19 )
{
F_6 ( & V_19 -> V_9 , & V_19 -> V_2 -> V_53 ) ;
F_7 ( L_6 , V_19 ) ;
}
static void F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_54 * V_55 ;
if ( ! V_6 -> V_56 )
return;
F_56 ( & V_2 -> V_57 -> V_58 ) ;
V_55 = F_57 ( V_2 -> V_57 , V_6 -> V_56 ) ;
if ( V_55 && V_55 -> V_19 == V_6 ) {
if ( V_6 -> V_12 & ( V_13 |
V_59 ) ) {
V_55 -> V_12 |= V_60 ;
F_7 ( L_7 , V_6 ) ;
V_55 -> V_19 = NULL ;
}
if ( V_6 -> V_12 & V_59 )
F_7 ( L_8 , V_6 ) ;
if ( V_55 -> V_12 & V_60 )
V_6 -> V_56 = 0 ;
} else
V_6 -> V_56 = 0 ;
F_58 ( & V_2 -> V_57 -> V_58 ) ;
}
void F_59 ( struct V_5 * V_19 , unsigned long V_61 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long V_51 ;
F_31 ( & V_2 -> V_52 , V_51 ) ;
if ( F_3 ( V_19 ) == V_8 ) {
V_19 -> V_12 |= V_61 ;
F_5 ( V_19 ) ;
}
F_32 ( & V_2 -> V_52 , V_51 ) ;
}
void F_60 ( unsigned long V_62 )
{
struct V_5 * V_6 = (struct V_5 * ) V_62 ;
F_59 ( V_6 , V_59 ) ;
}
static void F_61 ( unsigned long V_62 )
{
F_59 ( (struct V_5 * ) V_62 , 0 ) ;
}
static void F_62 ( struct V_5 * V_19 )
{
F_63 ( & V_19 -> V_63 ) ;
V_19 -> V_63 . V_64 = F_61 ;
V_19 -> V_63 . V_62 = ( unsigned long ) V_19 ;
V_19 -> V_63 . V_65 = V_66 + V_67 ;
F_64 ( & V_19 -> V_63 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
int V_50 , char * V_42 )
{
struct V_20 * V_21 ;
F_16 ( & V_2 -> V_22 ) ;
F_4 (port, &adapter->port_list, list)
F_41 ( V_21 , V_50 , V_42 ) ;
F_17 ( & V_2 -> V_22 ) ;
}
static void F_66 ( struct V_20 * V_21 , int V_50 ,
char * V_42 )
{
struct V_14 * V_15 ;
F_14 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 )
F_45 ( V_15 , V_50 , V_42 , 0 ) ;
}
static void F_67 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_41 ) {
case V_35 :
F_27 ( V_6 -> V_2 , 0 , L_9 ) ;
break;
case V_32 :
F_38 ( V_6 -> V_21 , 0 , L_10 ) ;
break;
case V_31 :
F_41 ( V_6 -> V_21 , 0 , L_11 ) ;
break;
case V_28 :
F_45 ( V_6 -> V_15 , 0 , L_12 , 0 ) ;
break;
}
}
static void F_68 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_41 ) {
case V_35 :
F_65 ( V_6 -> V_2 , 0 , L_13 ) ;
break;
case V_32 :
F_41 ( V_6 -> V_21 , 0 , L_14 ) ;
break;
case V_31 :
F_66 ( V_6 -> V_21 , 0 , L_15 ) ;
break;
}
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
F_70 ( & V_2 -> V_52 , V_51 ) ;
if ( F_71 ( & V_2 -> V_10 ) &&
F_71 ( & V_2 -> V_53 ) ) {
F_72 ( V_47 ,
& V_2 -> V_12 ) ;
F_8 ( & V_2 -> V_68 ) ;
}
F_73 ( & V_2 -> V_52 , V_51 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
V_21 = F_75 ( V_2 , V_2 -> V_69 , 0 ,
V_2 -> V_70 ) ;
if ( F_76 ( V_21 ) )
return;
F_41 ( V_21 , 0 , L_16 ) ;
}
static int F_77 ( struct V_5 * V_19 )
{
int V_71 ;
int V_72 = 1 ;
struct V_1 * V_2 = V_19 -> V_2 ;
F_72 ( V_73 , & V_2 -> V_12 ) ;
for ( V_71 = 7 ; V_71 ; V_71 -- ) {
F_72 ( V_74 ,
& V_2 -> V_12 ) ;
F_78 ( & V_2 -> V_52 ) ;
F_54 ( V_19 ) ;
F_79 ( & V_2 -> V_52 ) ;
if ( F_80 ( V_19 ) ) {
F_72 ( V_74 ,
& V_2 -> V_12 ) ;
return V_75 ;
}
F_81 ( V_2 -> V_11 ,
! F_71 ( & V_2 -> V_10 ) ) ;
if ( V_19 -> V_12 & V_59 )
break;
if ( ! ( F_12 ( & V_2 -> V_12 ) &
V_74 ) )
break;
F_82 ( V_72 ) ;
V_72 *= 2 ;
}
F_72 ( V_74 ,
& V_2 -> V_12 ) ;
if ( ! ( F_12 ( & V_2 -> V_12 ) & V_73 ) )
return V_75 ;
if ( F_83 ( V_2 -> V_76 ) == V_77 )
F_74 ( V_2 ) ;
return V_78 ;
}
static int F_84 ( struct V_5 * V_6 )
{
int V_79 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_78 ( & V_2 -> V_52 ) ;
F_54 ( V_6 ) ;
F_79 ( & V_2 -> V_52 ) ;
V_79 = F_85 ( V_6 ) ;
if ( V_79 == - V_80 )
return V_78 ;
if ( V_79 )
return V_75 ;
F_7 ( L_17 , V_6 ) ;
F_81 ( V_2 -> V_11 ,
! F_71 ( & V_2 -> V_10 ) ) ;
F_7 ( L_18 , V_6 ) ;
if ( V_6 -> V_12 & V_59 )
return V_75 ;
return V_78 ;
}
static int F_86 ( struct V_5 * V_6 )
{
if ( F_77 ( V_6 ) == V_75 )
return V_75 ;
if ( F_84 ( V_6 ) == V_75 )
return V_75 ;
if ( F_87 ( V_6 -> V_2 -> V_81 . V_82 ,
V_6 -> V_2 -> V_83 , V_84 ) )
return V_75 ;
if ( F_87 ( V_6 -> V_2 -> V_81 . V_85 ,
V_6 -> V_2 -> V_83 , V_84 ) )
return V_75 ;
F_88 ( & V_6 -> V_2 -> V_86 , V_6 -> V_2 -> V_83 ) ;
if ( F_89 ( V_6 -> V_2 ) )
return V_75 ;
return V_78 ;
}
static void F_90 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_91 ( V_2 -> V_87 ) ;
F_92 ( V_2 ) ;
V_2 -> V_88 = 0 ;
F_93 ( V_2 -> V_89 ) ;
F_2 ( V_2 , V_33 ) ;
F_72 ( V_73 |
V_90 , & V_2 -> V_12 ) ;
}
static int F_94 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( F_95 ( V_2 -> V_87 ) ) {
F_72 ( V_73 |
V_90 ,
& V_2 -> V_12 ) ;
return V_75 ;
}
if ( F_86 ( V_6 ) ) {
F_90 ( V_6 ) ;
return V_75 ;
}
F_21 ( V_33 , & V_2 -> V_12 ) ;
return V_78 ;
}
static int F_96 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( F_12 ( & V_2 -> V_12 ) & V_33 ) {
F_90 ( V_6 ) ;
if ( V_6 -> V_12 & V_38 )
return V_91 ;
}
if ( F_94 ( V_6 ) ) {
F_82 ( 8 ) ;
return V_75 ;
}
return V_78 ;
}
static int F_97 ( struct V_5 * V_6 )
{
int V_43 ;
V_43 = F_98 ( V_6 ) ;
if ( V_43 == - V_92 )
return V_93 ;
V_6 -> V_94 = V_95 ;
if ( V_43 )
return V_75 ;
return V_96 ;
}
static void F_99 ( struct V_20 * V_21 )
{
F_72 ( V_97 , & V_21 -> V_12 ) ;
}
static int F_100 ( struct V_5 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
int V_12 = F_12 ( & V_21 -> V_12 ) ;
switch ( V_19 -> V_94 ) {
case V_98 :
F_99 ( V_21 ) ;
if ( ( V_12 & V_99 ) &&
( V_12 & V_33 ) )
return F_97 ( V_19 ) ;
else
return V_75 ;
case V_95 :
if ( ! ( V_12 & V_99 ) )
return V_78 ;
}
return V_75 ;
}
static int F_101 ( struct V_5 * V_19 )
{
int V_43 ;
V_43 = F_102 ( V_19 ) ;
if ( V_43 == - V_92 )
return V_93 ;
V_19 -> V_94 = V_100 ;
if ( V_43 )
return V_75 ;
return V_96 ;
}
static int F_103 ( struct V_5 * V_19 )
{
int V_43 ;
V_43 = F_104 ( V_19 ) ;
if ( V_43 == - V_92 )
return V_93 ;
V_19 -> V_94 = V_101 ;
if ( V_43 )
return V_75 ;
return V_96 ;
}
static int F_105 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
if ( V_21 -> V_102 != V_2 -> V_69 ) {
F_42 ( V_21 , V_30 ) ;
return V_75 ;
}
V_21 -> V_103 = V_2 -> V_70 ;
return F_103 ( V_6 ) ;
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
int V_26 = F_12 ( & V_21 -> V_12 ) ;
switch ( V_6 -> V_94 ) {
case V_98 :
case V_95 :
case V_100 :
if ( F_83 ( V_2 -> V_76 ) == V_77 )
return F_105 ( V_6 ) ;
if ( ! V_21 -> V_103 ) {
F_107 ( V_21 ) ;
return V_91 ;
}
return F_103 ( V_6 ) ;
case V_101 :
if ( V_26 & V_33 ) {
if ( ! V_21 -> V_103 ) {
F_107 ( V_21 ) ;
return V_91 ;
}
return V_78 ;
}
if ( V_21 -> V_103 && ! ( V_26 & V_34 ) ) {
V_21 -> V_103 = 0 ;
return V_75 ;
}
}
return V_75 ;
}
static int F_108 ( struct V_5 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
int V_26 = F_12 ( & V_21 -> V_12 ) ;
if ( ( V_26 & V_34 ) &&
! ( V_26 & V_33 ) )
goto V_104;
switch ( V_19 -> V_94 ) {
case V_98 :
F_99 ( V_21 ) ;
if ( V_26 & V_33 )
return F_101 ( V_19 ) ;
break;
case V_100 :
if ( V_26 & V_33 )
return V_75 ;
break;
}
V_104:
if ( V_19 -> V_12 & V_38 )
return V_91 ;
return F_106 ( V_19 ) ;
}
static void F_109 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_72 ( V_97 |
V_105 | V_106 ,
& V_17 -> V_12 ) ;
}
static int F_110 ( struct V_5 * V_19 )
{
int V_43 = F_111 ( V_19 ) ;
if ( V_43 == - V_92 )
return V_93 ;
V_19 -> V_94 = V_107 ;
if ( V_43 )
return V_75 ;
return V_96 ;
}
static int F_112 ( struct V_5 * V_19 )
{
int V_43 = F_113 ( V_19 ) ;
if ( V_43 == - V_92 )
return V_93 ;
V_19 -> V_94 = V_108 ;
if ( V_43 )
return V_75 ;
return V_96 ;
}
static int F_114 ( struct V_5 * V_19 )
{
struct V_14 * V_15 = V_19 -> V_15 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
switch ( V_19 -> V_94 ) {
case V_98 :
F_109 ( V_15 ) ;
if ( F_12 ( & V_17 -> V_12 ) & V_33 )
return F_110 ( V_19 ) ;
case V_107 :
if ( F_12 ( & V_17 -> V_12 ) & V_33 )
return V_75 ;
if ( V_19 -> V_12 & V_38 )
return V_91 ;
return F_112 ( V_19 ) ;
case V_108 :
if ( F_12 ( & V_17 -> V_12 ) & V_33 )
return V_78 ;
}
return V_75 ;
}
static int F_115 ( struct V_14 * V_15 , int V_109 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
switch ( V_109 ) {
case V_78 :
F_88 ( & V_17 -> V_110 , 0 ) ;
F_53 ( V_15 ) ;
break;
case V_75 :
F_116 ( & V_17 -> V_110 ) ;
if ( F_12 ( & V_17 -> V_110 ) > V_111 ) {
F_117 ( & V_17 -> V_21 -> V_2 -> V_112 -> V_39 ,
L_19
L_20 ,
( unsigned long long ) F_118 ( V_15 ) ,
( unsigned long long ) V_17 -> V_21 -> V_102 ) ;
F_119 ( V_15 ,
V_30 ) ;
}
break;
}
if ( F_12 ( & V_17 -> V_12 ) & V_30 ) {
F_43 ( V_15 , 0 ) ;
V_109 = V_91 ;
}
return V_109 ;
}
static int F_120 ( struct V_20 * V_21 , int V_109 )
{
switch ( V_109 ) {
case V_78 :
F_88 ( & V_21 -> V_110 , 0 ) ;
F_52 ( V_21 ) ;
break;
case V_75 :
if ( F_12 ( & V_21 -> V_12 ) & V_34 ) {
F_36 ( V_21 , 0 ) ;
V_109 = V_91 ;
}
F_116 ( & V_21 -> V_110 ) ;
if ( F_12 ( & V_21 -> V_110 ) > V_111 ) {
F_117 ( & V_21 -> V_2 -> V_112 -> V_39 ,
L_21 ,
( unsigned long long ) V_21 -> V_102 ) ;
F_42 ( V_21 ,
V_30 ) ;
}
break;
}
if ( F_12 ( & V_21 -> V_12 ) & V_30 ) {
F_36 ( V_21 , 0 ) ;
V_109 = V_91 ;
}
return V_109 ;
}
static int F_121 ( struct V_1 * V_2 ,
int V_109 )
{
switch ( V_109 ) {
case V_78 :
F_88 ( & V_2 -> V_110 , 0 ) ;
F_51 ( V_2 ) ;
break;
case V_75 :
F_116 ( & V_2 -> V_110 ) ;
if ( F_12 ( & V_2 -> V_110 ) > V_111 ) {
F_117 ( & V_2 -> V_112 -> V_39 ,
L_22
L_23 ) ;
F_29 ( V_2 ,
V_30 ) ;
}
break;
}
if ( F_12 ( & V_2 -> V_12 ) & V_30 ) {
F_1 ( V_2 , 0 ) ;
V_109 = V_91 ;
}
return V_109 ;
}
static int F_122 ( struct V_5 * V_19 ,
int V_109 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_14 * V_15 = V_19 -> V_15 ;
switch ( V_19 -> V_41 ) {
case V_28 :
V_109 = F_115 ( V_15 , V_109 ) ;
break;
case V_32 :
case V_31 :
V_109 = F_120 ( V_21 , V_109 ) ;
break;
case V_35 :
V_109 = F_121 ( V_2 , V_109 ) ;
break;
}
return V_109 ;
}
static int F_123 ( T_2 * V_113 , T_1 V_114 )
{
int V_12 = F_12 ( V_113 ) ;
if ( ( V_12 & V_29 ) &&
( V_114 & V_38 ) )
return 1 ;
if ( ! ( V_12 & V_29 ) &&
! ( V_114 & V_38 ) )
return 1 ;
return 0 ;
}
static int F_124 ( struct V_5 * V_6 , int V_79 )
{
int V_41 = V_6 -> V_41 ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 ;
T_1 V_114 = V_6 -> V_12 ;
switch ( V_41 ) {
case V_35 :
if ( F_123 ( & V_2 -> V_12 , V_114 ) ) {
F_27 ( V_2 ,
V_30 ,
L_24 ) ;
return V_91 ;
}
break;
case V_32 :
case V_31 :
if ( F_123 ( & V_21 -> V_12 , V_114 ) ) {
F_41 ( V_21 ,
V_30 ,
L_25 ) ;
return V_91 ;
}
break;
case V_28 :
V_17 = F_11 ( V_15 ) ;
if ( F_123 ( & V_17 -> V_12 , V_114 ) ) {
F_45 ( V_15 ,
V_30 ,
L_26 , 0 ) ;
return V_91 ;
}
break;
}
return V_79 ;
}
static void F_125 ( struct V_5 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_16 * V_17 ;
V_2 -> V_48 -- ;
if ( V_19 -> V_12 & V_115 ) {
V_2 -> V_116 -- ;
V_19 -> V_12 &= ~ V_115 ;
}
F_126 ( & V_19 -> V_9 ) ;
F_7 ( L_27 , V_19 ) ;
switch ( V_19 -> V_41 ) {
case V_28 :
V_17 = F_11 ( V_19 -> V_15 ) ;
F_72 ( V_18 ,
& V_17 -> V_12 ) ;
break;
case V_32 :
case V_31 :
F_72 ( V_18 ,
& V_19 -> V_21 -> V_12 ) ;
break;
case V_35 :
F_72 ( V_18 ,
& V_19 -> V_2 -> V_12 ) ;
break;
}
}
static void F_127 ( struct V_5 * V_6 , int V_109 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_14 * V_15 = V_6 -> V_15 ;
switch ( V_6 -> V_41 ) {
case V_28 :
if ( ! ( V_6 -> V_12 & V_37 ) )
F_128 ( V_15 ) ;
break;
case V_31 :
if ( V_109 == V_78 )
F_129 ( V_21 ) ;
case V_32 :
F_130 ( & V_21 -> V_39 ) ;
break;
case V_35 :
if ( V_109 == V_78 ) {
F_131 ( & V_2 -> V_117 ) ;
F_132 ( V_2 -> V_118 , & V_2 -> V_119 ) ;
F_132 ( V_2 -> V_118 , & V_2 -> V_120 ) ;
} else
F_133 ( & V_2 -> V_117 ) ;
F_134 ( & V_2 -> V_40 , V_121 ) ;
break;
}
}
static int F_135 ( struct V_5 * V_19 )
{
switch ( V_19 -> V_41 ) {
case V_35 :
return F_96 ( V_19 ) ;
case V_32 :
return F_100 ( V_19 ) ;
case V_31 :
return F_108 ( V_19 ) ;
case V_28 :
return F_114 ( V_19 ) ;
}
return V_75 ;
}
static int F_136 ( struct V_5 * V_19 )
{
int V_43 ;
unsigned long V_51 ;
struct V_1 * V_2 = V_19 -> V_2 ;
F_23 ( & V_2 -> V_40 ) ;
F_31 ( & V_2 -> V_52 , V_51 ) ;
F_55 ( V_19 ) ;
if ( V_19 -> V_12 & V_13 ) {
F_125 ( V_19 ) ;
V_43 = V_122 ;
goto V_123;
}
if ( V_19 -> V_12 & V_59 ) {
V_43 = V_75 ;
goto V_124;
}
F_54 ( V_19 ) ;
F_32 ( & V_2 -> V_52 , V_51 ) ;
V_43 = F_135 ( V_19 ) ;
F_31 ( & V_2 -> V_52 , V_51 ) ;
if ( V_19 -> V_12 & V_13 )
V_43 = V_96 ;
switch ( V_43 ) {
case V_93 :
if ( ! ( V_19 -> V_12 & V_115 ) ) {
++ V_2 -> V_116 ;
V_19 -> V_12 |= V_115 ;
}
if ( V_2 -> V_48 == V_2 -> V_116 )
F_27 ( V_2 , 0 , L_28 ) ;
else {
F_62 ( V_19 ) ;
V_43 = V_96 ;
}
goto V_123;
case V_96 :
if ( V_19 -> V_12 & V_115 ) {
-- V_2 -> V_116 ;
V_19 -> V_12 &= ~ V_115 ;
}
goto V_123;
}
V_124:
V_43 = F_122 ( V_19 , V_43 ) ;
F_125 ( V_19 ) ;
V_43 = F_124 ( V_19 , V_43 ) ;
if ( V_43 == V_91 )
goto V_123;
if ( V_43 == V_78 )
F_68 ( V_19 ) ;
if ( V_43 == V_75 )
F_67 ( V_19 ) ;
V_123:
F_32 ( & V_2 -> V_52 , V_51 ) ;
if ( V_43 != V_96 )
F_127 ( V_19 , V_43 ) ;
F_134 ( & V_2 -> V_40 , V_121 ) ;
return V_43 ;
}
static int F_137 ( void * V_62 )
{
struct V_1 * V_2 = (struct V_1 * ) V_62 ;
struct V_125 * V_126 ;
struct V_5 * V_6 ;
unsigned long V_51 ;
for (; ; ) {
F_138 ( V_2 -> V_11 ,
! F_71 ( & V_2 -> V_10 ) ||
F_139 () ) ;
if ( F_139 () )
break;
F_31 ( & V_2 -> V_52 , V_51 ) ;
V_126 = V_2 -> V_10 . V_126 ;
F_32 ( & V_2 -> V_52 , V_51 ) ;
if ( V_126 != & V_2 -> V_10 ) {
V_6 = F_140 ( V_126 , struct V_5 , V_9 ) ;
if ( F_136 ( V_6 ) != V_122 )
F_69 ( V_2 ) ;
}
}
return 0 ;
}
int F_141 ( struct V_1 * V_2 )
{
struct V_127 * V_128 ;
V_128 = F_142 ( F_137 , V_2 , L_29 ,
F_143 ( & V_2 -> V_112 -> V_39 ) ) ;
if ( F_76 ( V_128 ) ) {
F_117 ( & V_2 -> V_112 -> V_39 ,
L_30 ) ;
return F_144 ( V_128 ) ;
}
V_2 -> V_44 = V_128 ;
return 0 ;
}
void F_145 ( struct V_1 * V_2 )
{
F_146 ( V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
F_147 ( ! F_71 ( & V_2 -> V_10 ) ) ;
F_147 ( ! F_71 ( & V_2 -> V_53 ) ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_81 ( V_2 -> V_68 ,
! ( F_12 ( & V_2 -> V_12 ) &
V_47 ) ) ;
}
void F_29 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
unsigned long V_51 ;
T_1 V_129 = V_3 & V_130 ;
F_21 ( V_3 , & V_2 -> V_12 ) ;
if ( ! V_129 )
return;
F_70 ( & V_2 -> V_22 , V_51 ) ;
F_4 (port, &adapter->port_list, list)
F_21 ( V_129 , & V_21 -> V_12 ) ;
F_73 ( & V_2 -> V_22 , V_51 ) ;
F_14 (sdev, adapter->scsi_host)
F_21 ( V_129 , & F_11 ( V_15 ) -> V_12 ) ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
unsigned long V_51 ;
T_1 V_129 = V_3 & V_130 ;
T_1 V_131 = V_3 & V_30 ;
F_72 ( V_3 , & V_2 -> V_12 ) ;
if ( ! V_129 )
return;
if ( V_131 )
F_88 ( & V_2 -> V_110 , 0 ) ;
F_70 ( & V_2 -> V_22 , V_51 ) ;
F_4 (port, &adapter->port_list, list) {
F_72 ( V_129 , & V_21 -> V_12 ) ;
if ( V_131 )
F_88 ( & V_21 -> V_110 , 0 ) ;
}
F_73 ( & V_2 -> V_22 , V_51 ) ;
F_14 (sdev, adapter->scsi_host) {
F_72 ( V_129 , & F_11 ( V_15 ) -> V_12 ) ;
if ( V_131 )
F_88 ( & F_11 ( V_15 ) -> V_110 , 0 ) ;
}
}
void F_42 ( struct V_20 * V_21 , T_1 V_3 )
{
struct V_14 * V_15 ;
T_1 V_129 = V_3 & V_130 ;
F_21 ( V_3 , & V_21 -> V_12 ) ;
if ( ! V_129 )
return;
F_14 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 )
F_21 ( V_129 ,
& F_11 ( V_15 ) -> V_12 ) ;
}
void F_37 ( struct V_20 * V_21 , T_1 V_3 )
{
struct V_14 * V_15 ;
T_1 V_129 = V_3 & V_130 ;
T_1 V_131 = V_3 & V_30 ;
F_72 ( V_3 , & V_21 -> V_12 ) ;
if ( ! V_129 )
return;
if ( V_131 )
F_88 ( & V_21 -> V_110 , 0 ) ;
F_14 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 ) {
F_72 ( V_129 ,
& F_11 ( V_15 ) -> V_12 ) ;
if ( V_131 )
F_88 ( & F_11 ( V_15 ) -> V_110 , 0 ) ;
}
}
void F_119 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_21 ( V_3 , & V_17 -> V_12 ) ;
}
void F_44 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_72 ( V_3 , & V_17 -> V_12 ) ;
if ( V_3 & V_30 )
F_88 ( & V_17 -> V_110 , 0 ) ;
}
