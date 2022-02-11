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
else {
F_14 ( V_21 -> V_2 -> V_22 -> V_23 ) ;
F_15 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 )
F_10 ( V_15 ) ;
F_16 ( V_21 -> V_2 -> V_22 -> V_23 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
if ( F_12 ( & V_2 -> V_12 ) & V_18 )
F_9 ( & V_2 -> V_19 ) ;
else {
F_18 ( & V_2 -> V_24 ) ;
F_4 (port, &adapter->port_list, list)
F_13 ( V_21 ) ;
F_19 ( & V_2 -> V_24 ) ;
}
}
static int F_20 ( int V_25 , struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_14 * V_15 )
{
int V_26 = V_25 ;
int V_27 , V_28 , V_29 ;
struct V_16 * V_17 ;
switch ( V_25 ) {
case V_30 :
V_17 = F_11 ( V_15 ) ;
V_27 = F_12 ( & V_17 -> V_12 ) ;
if ( V_27 & V_18 )
return 0 ;
V_28 = F_12 ( & V_21 -> V_12 ) ;
if ( ! ( V_28 & V_31 ) ||
V_28 & V_32 )
return 0 ;
if ( ! ( V_28 & V_4 ) )
V_26 = V_33 ;
case V_34 :
V_28 = F_12 ( & V_21 -> V_12 ) ;
if ( ! ( V_28 & V_35 ) )
V_26 = V_33 ;
case V_33 :
V_28 = F_12 ( & V_21 -> V_12 ) ;
if ( V_28 & V_18 )
return 0 ;
V_29 = F_12 ( & V_2 -> V_12 ) ;
if ( ! ( V_29 & V_31 ) ||
V_29 & V_32 )
return 0 ;
if ( V_28 & V_36 )
return V_26 ;
if ( ! ( V_29 & V_4 ) )
V_26 = V_37 ;
case V_37 :
V_29 = F_12 ( & V_2 -> V_12 ) ;
if ( V_29 & V_18 )
return 0 ;
if ( ! ( V_29 & V_31 ) &&
! ( V_29 & V_35 ) )
return 0 ;
}
return V_26 ;
}
static struct V_5 * F_21 ( int V_26 , T_1 V_38 ,
struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_14 * V_15 )
{
struct V_5 * V_19 ;
struct V_16 * V_17 ;
switch ( V_26 ) {
case V_30 :
V_17 = F_11 ( V_15 ) ;
if ( ! ( V_38 & V_39 ) )
if ( F_22 ( V_15 ) )
return NULL ;
F_23 ( V_18 ,
& V_17 -> V_12 ) ;
V_19 = & V_17 -> V_19 ;
F_24 ( V_19 -> V_21 != V_21 ) ;
F_24 ( V_19 -> V_15 != V_15 ) ;
if ( ! ( F_12 ( & V_17 -> V_12 ) &
V_31 ) )
V_38 |= V_40 ;
break;
case V_33 :
case V_34 :
if ( ! F_25 ( & V_21 -> V_41 ) )
return NULL ;
F_13 ( V_21 ) ;
F_23 ( V_18 , & V_21 -> V_12 ) ;
V_19 = & V_21 -> V_19 ;
F_24 ( V_19 -> V_21 != V_21 ) ;
F_24 ( V_19 -> V_15 != NULL ) ;
if ( ! ( F_12 ( & V_21 -> V_12 ) & V_31 ) )
V_38 |= V_40 ;
break;
case V_37 :
F_26 ( & V_2 -> V_42 ) ;
F_17 ( V_2 ) ;
F_23 ( V_18 , & V_2 -> V_12 ) ;
V_19 = & V_2 -> V_19 ;
F_24 ( V_19 -> V_21 != NULL ) ;
F_24 ( V_19 -> V_15 != NULL ) ;
if ( ! ( F_12 ( & V_2 -> V_12 ) &
V_31 ) )
V_38 |= V_40 ;
break;
default:
return NULL ;
}
F_24 ( V_19 -> V_2 != V_2 ) ;
memset ( & V_19 -> V_9 , 0 , sizeof( V_19 -> V_9 ) ) ;
memset ( & V_19 -> V_43 , 0 , sizeof( V_19 -> V_43 ) ) ;
V_19 -> V_44 = V_45 ;
V_19 -> V_46 = 0 ;
V_19 -> V_47 = V_26 ;
V_19 -> V_12 = V_38 ;
return V_19 ;
}
static int F_27 ( int V_25 , struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_14 * V_15 ,
char * V_48 , T_1 V_38 )
{
int V_49 = 1 , V_26 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_50 )
return - V_51 ;
V_26 = F_20 ( V_25 , V_2 , V_21 , V_15 ) ;
if ( ! V_26 )
goto V_52;
V_6 = F_21 ( V_26 , V_38 , V_2 , V_21 , V_15 ) ;
if ( ! V_6 )
goto V_52;
F_23 ( V_53 , & V_2 -> V_12 ) ;
++ V_2 -> V_54 ;
F_28 ( & V_6 -> V_9 , & V_2 -> V_10 ) ;
F_8 ( & V_2 -> V_11 ) ;
V_49 = 0 ;
V_52:
F_29 ( V_48 , V_2 , V_21 , V_15 , V_25 , V_26 ) ;
return V_49 ;
}
static int F_30 ( struct V_1 * V_2 ,
int V_55 , char * V_48 )
{
F_1 ( V_2 , V_55 ) ;
F_31 ( V_2 ) ;
if ( F_12 ( & V_2 -> V_12 ) & V_32 ) {
F_32 ( V_2 ,
V_32 ) ;
return - V_51 ;
}
return F_27 ( V_37 ,
V_2 , NULL , NULL , V_48 , 0 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_56 , char * V_48 )
{
unsigned long V_57 ;
F_1 ( V_2 , V_56 ) ;
F_31 ( V_2 ) ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
if ( F_12 ( & V_2 -> V_12 ) & V_32 )
F_32 ( V_2 ,
V_32 ) ;
else
F_27 ( V_37 , V_2 ,
NULL , NULL , V_48 , 0 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_56 ,
char * V_48 )
{
int V_57 = V_31 | V_32 ;
F_33 ( V_2 , V_56 | V_57 , V_48 ) ;
}
void F_37 ( struct V_20 * V_21 , int V_56 , char * V_48 )
{
int V_57 = V_31 | V_32 ;
F_38 ( V_21 , V_56 | V_57 , V_48 ) ;
}
static void F_39 ( struct V_20 * V_21 , int V_56 )
{
F_40 ( V_21 ,
V_4 | V_56 ) ;
}
static void F_41 ( struct V_20 * V_21 , int V_56 ,
char * V_48 )
{
F_39 ( V_21 , V_56 ) ;
F_42 ( V_21 ) ;
if ( F_12 ( & V_21 -> V_12 ) & V_32 )
return;
F_27 ( V_34 ,
V_21 -> V_2 , V_21 , NULL , V_48 , 0 ) ;
}
void F_43 ( struct V_20 * V_21 , int V_56 , char * V_48 )
{
unsigned long V_57 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
F_41 ( V_21 , V_56 , V_48 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
}
static int F_44 ( struct V_20 * V_21 , int V_56 , char * V_48 )
{
F_39 ( V_21 , V_56 ) ;
F_42 ( V_21 ) ;
if ( F_12 ( & V_21 -> V_12 ) & V_32 ) {
F_45 ( V_21 , V_32 ) ;
return - V_51 ;
}
return F_27 ( V_33 ,
V_21 -> V_2 , V_21 , NULL , V_48 , 0 ) ;
}
int F_38 ( struct V_20 * V_21 , int V_56 , char * V_48 )
{
int V_49 ;
unsigned long V_57 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
V_49 = F_44 ( V_21 , V_56 , V_48 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
return V_49 ;
}
static void F_46 ( struct V_14 * V_15 , int V_55 )
{
F_47 ( V_15 ,
V_4 | V_55 ) ;
}
static void F_48 ( struct V_14 * V_15 , int V_56 , char * V_48 ,
T_1 V_38 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_1 * V_2 = V_17 -> V_21 -> V_2 ;
F_46 ( V_15 , V_56 ) ;
if ( F_12 ( & V_17 -> V_12 ) & V_32 )
return;
F_27 ( V_30 , V_2 ,
V_17 -> V_21 , V_15 , V_48 , V_38 ) ;
}
void F_49 ( struct V_14 * V_15 , int V_56 , char * V_48 )
{
unsigned long V_57 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
F_48 ( V_15 , V_56 , V_48 , 0 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
}
void F_50 ( struct V_14 * V_15 , int V_56 , char * V_48 )
{
int V_57 = V_31 | V_32 ;
F_49 ( V_15 , V_56 | V_57 , V_48 ) ;
}
void F_51 ( struct V_14 * V_15 , char * V_48 )
{
unsigned long V_57 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_56 = V_31 | V_32 ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
F_48 ( V_15 , V_56 , V_48 , V_39 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
F_52 ( V_2 ) ;
}
static int F_53 ( unsigned long V_3 , T_2 * V_12 )
{
return ( F_12 ( V_12 ) ^ V_3 ) & V_3 ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_53 ( V_4 , & V_2 -> V_12 ) )
F_7 ( L_3 , & V_2 -> V_19 ) ;
F_23 ( V_4 , & V_2 -> V_12 ) ;
}
static void F_55 ( struct V_20 * V_21 )
{
if ( F_53 ( V_4 , & V_21 -> V_12 ) )
F_7 ( L_4 , & V_21 -> V_19 ) ;
F_23 ( V_4 , & V_21 -> V_12 ) ;
}
static void F_56 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
if ( F_53 ( V_4 , & V_17 -> V_12 ) )
F_7 ( L_5 , & F_11 ( V_15 ) -> V_19 ) ;
F_23 ( V_4 , & V_17 -> V_12 ) ;
}
static void F_57 ( struct V_5 * V_19 )
{
F_6 ( & V_19 -> V_9 , & V_19 -> V_2 -> V_59 ) ;
F_7 ( L_6 , V_19 ) ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_60 * V_61 ;
if ( ! V_6 -> V_46 )
return;
F_14 ( & V_2 -> V_62 -> V_63 ) ;
V_61 = F_59 ( V_2 -> V_62 , V_6 -> V_46 ) ;
if ( V_61 && V_61 -> V_19 == V_6 ) {
if ( V_6 -> V_12 & ( V_13 |
V_64 ) ) {
V_61 -> V_12 |= V_65 ;
F_7 ( L_7 , V_6 ) ;
V_61 -> V_19 = NULL ;
}
if ( V_6 -> V_12 & V_64 )
F_7 ( L_8 , V_6 ) ;
if ( V_61 -> V_12 & V_65 )
V_6 -> V_46 = 0 ;
} else
V_6 -> V_46 = 0 ;
F_16 ( & V_2 -> V_62 -> V_63 ) ;
}
void F_60 ( struct V_5 * V_19 , unsigned long V_66 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long V_57 ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
if ( F_3 ( V_19 ) == V_8 ) {
V_19 -> V_12 |= V_66 ;
F_5 ( V_19 ) ;
}
F_35 ( & V_2 -> V_58 , V_57 ) ;
}
void F_61 ( unsigned long V_67 )
{
struct V_5 * V_6 = (struct V_5 * ) V_67 ;
F_60 ( V_6 , V_64 ) ;
}
static void F_62 ( unsigned long V_67 )
{
F_60 ( (struct V_5 * ) V_67 , 0 ) ;
}
static void F_63 ( struct V_5 * V_19 )
{
F_64 ( & V_19 -> V_43 , F_62 ,
( unsigned long ) V_19 ) ;
V_19 -> V_43 . V_68 = V_69 + V_70 ;
F_65 ( & V_19 -> V_43 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
int V_56 , char * V_48 )
{
struct V_20 * V_21 ;
F_18 ( & V_2 -> V_24 ) ;
F_4 (port, &adapter->port_list, list)
F_44 ( V_21 , V_56 , V_48 ) ;
F_19 ( & V_2 -> V_24 ) ;
}
static void F_67 ( struct V_20 * V_21 , int V_56 ,
char * V_48 )
{
struct V_14 * V_15 ;
F_14 ( V_21 -> V_2 -> V_22 -> V_23 ) ;
F_15 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 )
F_48 ( V_15 , V_56 , V_48 , 0 ) ;
F_16 ( V_21 -> V_2 -> V_22 -> V_23 ) ;
}
static void F_68 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_47 ) {
case V_37 :
F_30 ( V_6 -> V_2 , 0 , L_9 ) ;
break;
case V_34 :
F_41 ( V_6 -> V_21 , 0 , L_10 ) ;
break;
case V_33 :
F_44 ( V_6 -> V_21 , 0 , L_11 ) ;
break;
case V_30 :
F_48 ( V_6 -> V_15 , 0 , L_12 , 0 ) ;
break;
}
}
static void F_69 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_47 ) {
case V_37 :
F_66 ( V_6 -> V_2 , 0 , L_13 ) ;
break;
case V_34 :
F_44 ( V_6 -> V_21 , 0 , L_14 ) ;
break;
case V_33 :
F_67 ( V_6 -> V_21 , 0 , L_15 ) ;
break;
}
}
static void F_70 ( struct V_1 * V_2 )
{
unsigned long V_57 ;
F_71 ( & V_2 -> V_58 , V_57 ) ;
if ( F_72 ( & V_2 -> V_10 ) &&
F_72 ( & V_2 -> V_59 ) ) {
F_73 ( V_53 ,
& V_2 -> V_12 ) ;
F_8 ( & V_2 -> V_71 ) ;
}
F_74 ( & V_2 -> V_58 , V_57 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
V_21 = F_76 ( V_2 , V_2 -> V_72 , 0 ,
V_2 -> V_73 ) ;
if ( F_77 ( V_21 ) )
return;
F_44 ( V_21 , 0 , L_16 ) ;
}
static int F_78 ( struct V_5 * V_19 )
{
int V_74 ;
int V_75 = 1 ;
struct V_1 * V_2 = V_19 -> V_2 ;
F_73 ( V_76 , & V_2 -> V_12 ) ;
for ( V_74 = 7 ; V_74 ; V_74 -- ) {
F_73 ( V_77 ,
& V_2 -> V_12 ) ;
F_79 ( & V_2 -> V_58 ) ;
F_57 ( V_19 ) ;
F_80 ( & V_2 -> V_58 ) ;
if ( F_81 ( V_19 ) ) {
F_73 ( V_77 ,
& V_2 -> V_12 ) ;
return V_78 ;
}
F_82 ( V_2 -> V_11 ,
! F_72 ( & V_2 -> V_10 ) ) ;
if ( V_19 -> V_12 & V_64 )
break;
if ( ! ( F_12 ( & V_2 -> V_12 ) &
V_77 ) )
break;
F_83 ( V_75 ) ;
V_75 *= 2 ;
}
F_73 ( V_77 ,
& V_2 -> V_12 ) ;
if ( ! ( F_12 ( & V_2 -> V_12 ) & V_76 ) )
return V_78 ;
if ( F_84 ( V_2 -> V_22 ) == V_79 )
F_75 ( V_2 ) ;
return V_80 ;
}
static int F_85 ( struct V_5 * V_6 )
{
int V_81 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_79 ( & V_2 -> V_58 ) ;
F_57 ( V_6 ) ;
F_80 ( & V_2 -> V_58 ) ;
V_81 = F_86 ( V_6 ) ;
if ( V_81 == - V_82 )
return V_80 ;
if ( V_81 )
return V_78 ;
F_7 ( L_17 , V_6 ) ;
F_82 ( V_2 -> V_11 ,
! F_72 ( & V_2 -> V_10 ) ) ;
F_7 ( L_18 , V_6 ) ;
if ( V_6 -> V_12 & V_64 )
return V_78 ;
return V_80 ;
}
static int F_87 ( struct V_5 * V_6 )
{
if ( F_78 ( V_6 ) == V_78 )
return V_78 ;
if ( F_85 ( V_6 ) == V_78 )
return V_78 ;
if ( F_88 ( V_6 -> V_2 -> V_83 . V_84 ,
V_6 -> V_2 -> V_85 ) )
return V_78 ;
if ( F_88 ( V_6 -> V_2 -> V_83 . V_86 ,
V_6 -> V_2 -> V_85 ) )
return V_78 ;
F_89 ( & V_6 -> V_2 -> V_87 , V_6 -> V_2 -> V_85 ) ;
if ( F_90 ( V_6 -> V_2 ) )
return V_78 ;
return V_80 ;
}
static void F_91 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_92 ( V_2 -> V_88 ) ;
F_93 ( V_2 ) ;
V_2 -> V_89 = 0 ;
F_94 ( V_2 -> V_90 ) ;
F_2 ( V_2 , V_35 ) ;
F_73 ( V_76 |
V_91 , & V_2 -> V_12 ) ;
}
static int F_95 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( F_96 ( V_2 -> V_88 ) ) {
F_73 ( V_76 |
V_91 ,
& V_2 -> V_12 ) ;
return V_78 ;
}
if ( F_87 ( V_6 ) ) {
F_91 ( V_6 ) ;
return V_78 ;
}
F_23 ( V_35 , & V_2 -> V_12 ) ;
return V_80 ;
}
static int F_97 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( F_12 ( & V_2 -> V_12 ) & V_35 ) {
F_91 ( V_6 ) ;
if ( V_6 -> V_12 & V_40 )
return V_92 ;
}
if ( F_95 ( V_6 ) ) {
F_83 ( 8 ) ;
return V_78 ;
}
return V_80 ;
}
static int F_98 ( struct V_5 * V_6 )
{
int V_49 ;
V_49 = F_99 ( V_6 ) ;
if ( V_49 == - V_93 )
return V_94 ;
V_6 -> V_44 = V_95 ;
if ( V_49 )
return V_78 ;
return V_96 ;
}
static int F_100 ( struct V_5 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
int V_12 = F_12 ( & V_21 -> V_12 ) ;
switch ( V_19 -> V_44 ) {
case V_45 :
if ( ( V_12 & V_97 ) &&
( V_12 & V_35 ) )
return F_98 ( V_19 ) ;
else
return V_78 ;
case V_95 :
if ( ! ( V_12 & V_97 ) )
return V_80 ;
}
return V_78 ;
}
static int F_101 ( struct V_5 * V_19 )
{
int V_49 ;
V_49 = F_102 ( V_19 ) ;
if ( V_49 == - V_93 )
return V_94 ;
V_19 -> V_44 = V_98 ;
if ( V_49 )
return V_78 ;
return V_96 ;
}
static int F_103 ( struct V_5 * V_19 )
{
int V_49 ;
V_49 = F_104 ( V_19 ) ;
if ( V_49 == - V_93 )
return V_94 ;
V_19 -> V_44 = V_99 ;
if ( V_49 )
return V_78 ;
return V_96 ;
}
static int F_105 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
if ( V_21 -> V_100 != V_2 -> V_72 ) {
F_45 ( V_21 , V_32 ) ;
return V_78 ;
}
V_21 -> V_101 = V_2 -> V_73 ;
return F_103 ( V_6 ) ;
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
int V_28 = F_12 ( & V_21 -> V_12 ) ;
switch ( V_6 -> V_44 ) {
case V_45 :
case V_95 :
case V_98 :
if ( F_84 ( V_2 -> V_22 ) == V_79 )
return F_105 ( V_6 ) ;
if ( ! V_21 -> V_101 ) {
F_107 ( V_21 ) ;
return V_92 ;
}
return F_103 ( V_6 ) ;
case V_99 :
if ( V_28 & V_35 ) {
if ( ! V_21 -> V_101 ) {
F_107 ( V_21 ) ;
return V_92 ;
}
return V_80 ;
}
if ( V_21 -> V_101 && ! ( V_28 & V_36 ) ) {
V_21 -> V_101 = 0 ;
return V_78 ;
}
}
return V_78 ;
}
static int F_108 ( struct V_5 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
int V_28 = F_12 ( & V_21 -> V_12 ) ;
if ( ( V_28 & V_36 ) &&
! ( V_28 & V_35 ) )
goto V_102;
switch ( V_19 -> V_44 ) {
case V_45 :
if ( V_28 & V_35 )
return F_101 ( V_19 ) ;
break;
case V_98 :
if ( V_28 & V_35 )
return V_78 ;
break;
}
V_102:
if ( V_19 -> V_12 & V_40 )
return V_92 ;
return F_106 ( V_19 ) ;
}
static void F_109 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_73 ( V_103 ,
& V_17 -> V_12 ) ;
}
static int F_110 ( struct V_5 * V_19 )
{
int V_49 = F_111 ( V_19 ) ;
if ( V_49 == - V_93 )
return V_94 ;
V_19 -> V_44 = V_104 ;
if ( V_49 )
return V_78 ;
return V_96 ;
}
static int F_112 ( struct V_5 * V_19 )
{
int V_49 = F_113 ( V_19 ) ;
if ( V_49 == - V_93 )
return V_94 ;
V_19 -> V_44 = V_105 ;
if ( V_49 )
return V_78 ;
return V_96 ;
}
static int F_114 ( struct V_5 * V_19 )
{
struct V_14 * V_15 = V_19 -> V_15 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
switch ( V_19 -> V_44 ) {
case V_45 :
F_109 ( V_15 ) ;
if ( F_12 ( & V_17 -> V_12 ) & V_35 )
return F_110 ( V_19 ) ;
case V_104 :
if ( F_12 ( & V_17 -> V_12 ) & V_35 )
return V_78 ;
if ( V_19 -> V_12 & V_40 )
return V_92 ;
return F_112 ( V_19 ) ;
case V_105 :
if ( F_12 ( & V_17 -> V_12 ) & V_35 )
return V_80 ;
}
return V_78 ;
}
static int F_115 ( struct V_14 * V_15 , int V_106 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
switch ( V_106 ) {
case V_80 :
F_89 ( & V_17 -> V_107 , 0 ) ;
F_56 ( V_15 ) ;
break;
case V_78 :
F_116 ( & V_17 -> V_107 ) ;
if ( F_12 ( & V_17 -> V_107 ) > V_108 ) {
F_117 ( & V_17 -> V_21 -> V_2 -> V_109 -> V_41 ,
L_19
L_20 ,
( unsigned long long ) F_118 ( V_15 ) ,
( unsigned long long ) V_17 -> V_21 -> V_100 ) ;
F_119 ( V_15 ,
V_32 ) ;
}
break;
}
if ( F_12 ( & V_17 -> V_12 ) & V_32 ) {
F_46 ( V_15 , 0 ) ;
V_106 = V_92 ;
}
return V_106 ;
}
static int F_120 ( struct V_20 * V_21 , int V_106 )
{
switch ( V_106 ) {
case V_80 :
F_89 ( & V_21 -> V_107 , 0 ) ;
F_55 ( V_21 ) ;
break;
case V_78 :
if ( F_12 ( & V_21 -> V_12 ) & V_36 ) {
F_39 ( V_21 , 0 ) ;
V_106 = V_92 ;
}
F_116 ( & V_21 -> V_107 ) ;
if ( F_12 ( & V_21 -> V_107 ) > V_108 ) {
F_117 ( & V_21 -> V_2 -> V_109 -> V_41 ,
L_21 ,
( unsigned long long ) V_21 -> V_100 ) ;
F_45 ( V_21 ,
V_32 ) ;
}
break;
}
if ( F_12 ( & V_21 -> V_12 ) & V_32 ) {
F_39 ( V_21 , 0 ) ;
V_106 = V_92 ;
}
return V_106 ;
}
static int F_121 ( struct V_1 * V_2 ,
int V_106 )
{
switch ( V_106 ) {
case V_80 :
F_89 ( & V_2 -> V_107 , 0 ) ;
F_54 ( V_2 ) ;
break;
case V_78 :
F_116 ( & V_2 -> V_107 ) ;
if ( F_12 ( & V_2 -> V_107 ) > V_108 ) {
F_117 ( & V_2 -> V_109 -> V_41 ,
L_22
L_23 ) ;
F_32 ( V_2 ,
V_32 ) ;
}
break;
}
if ( F_12 ( & V_2 -> V_12 ) & V_32 ) {
F_1 ( V_2 , 0 ) ;
V_106 = V_92 ;
}
return V_106 ;
}
static int F_122 ( struct V_5 * V_19 ,
int V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_14 * V_15 = V_19 -> V_15 ;
switch ( V_19 -> V_47 ) {
case V_30 :
V_106 = F_115 ( V_15 , V_106 ) ;
break;
case V_34 :
case V_33 :
V_106 = F_120 ( V_21 , V_106 ) ;
break;
case V_37 :
V_106 = F_121 ( V_2 , V_106 ) ;
break;
}
return V_106 ;
}
static int F_123 ( T_2 * V_110 , T_1 V_111 )
{
int V_12 = F_12 ( V_110 ) ;
if ( ( V_12 & V_31 ) &&
( V_111 & V_40 ) )
return 1 ;
if ( ! ( V_12 & V_31 ) &&
! ( V_111 & V_40 ) )
return 1 ;
return 0 ;
}
static int F_124 ( struct V_5 * V_6 , int V_81 )
{
int V_47 = V_6 -> V_47 ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 ;
T_1 V_111 = V_6 -> V_12 ;
switch ( V_47 ) {
case V_37 :
if ( F_123 ( & V_2 -> V_12 , V_111 ) ) {
F_30 ( V_2 ,
V_32 ,
L_24 ) ;
return V_92 ;
}
break;
case V_34 :
case V_33 :
if ( F_123 ( & V_21 -> V_12 , V_111 ) ) {
F_44 ( V_21 ,
V_32 ,
L_25 ) ;
return V_92 ;
}
break;
case V_30 :
V_17 = F_11 ( V_15 ) ;
if ( F_123 ( & V_17 -> V_12 , V_111 ) ) {
F_48 ( V_15 ,
V_32 ,
L_26 , 0 ) ;
return V_92 ;
}
break;
}
return V_81 ;
}
static void F_125 ( struct V_5 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_16 * V_17 ;
V_2 -> V_54 -- ;
if ( V_19 -> V_12 & V_112 ) {
V_2 -> V_113 -- ;
V_19 -> V_12 &= ~ V_112 ;
}
F_126 ( & V_19 -> V_9 ) ;
F_7 ( L_27 , V_19 ) ;
switch ( V_19 -> V_47 ) {
case V_30 :
V_17 = F_11 ( V_19 -> V_15 ) ;
F_73 ( V_18 ,
& V_17 -> V_12 ) ;
break;
case V_34 :
case V_33 :
F_73 ( V_18 ,
& V_19 -> V_21 -> V_12 ) ;
break;
case V_37 :
F_73 ( V_18 ,
& V_19 -> V_2 -> V_12 ) ;
break;
}
}
static void F_127 ( struct V_20 * V_21 )
{
unsigned long V_57 ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_114 ;
struct V_115 * V_116 = V_2 -> V_22 ;
struct V_14 * V_15 ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
V_114 = F_12 ( & V_21 -> V_12 ) ;
if ( ( V_114 & V_4 ) == 0 ||
( V_114 & ( V_18 |
V_32 ) ) != 0 ) {
F_128 ( 4 , L_28 , & V_21 -> V_19 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
return;
}
F_14 ( V_116 -> V_23 ) ;
F_15 (sdev, shost) {
struct V_16 * V_117 = F_11 ( V_15 ) ;
int V_118 ;
if ( V_117 -> V_21 != V_21 )
continue;
V_118 = F_12 ( & V_117 -> V_12 ) ;
if ( ( V_118 & V_32 ) != 0 )
continue;
if ( ( V_118 & V_4 ) == 0 ||
( V_118 & V_18 ) != 0 ) {
F_128 ( 4 , L_29 , & V_117 -> V_19 ) ;
F_16 ( V_116 -> V_23 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
return;
}
}
F_129 ( V_21 ) ;
F_16 ( V_116 -> V_23 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
}
static void F_130 ( struct V_5 * V_6 , int V_106 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_14 * V_15 = V_6 -> V_15 ;
switch ( V_6 -> V_47 ) {
case V_30 :
if ( ! ( V_6 -> V_12 & V_39 ) )
F_131 ( V_15 ) ;
F_127 ( V_21 ) ;
break;
case V_33 :
if ( V_6 -> V_44 != V_45 )
if ( V_106 == V_80 )
F_127 ( V_21 ) ;
case V_34 :
F_132 ( & V_21 -> V_41 ) ;
break;
case V_37 :
if ( V_106 == V_80 ) {
F_133 ( & V_2 -> V_119 ) ;
F_134 ( V_2 ) ;
F_135 ( V_2 -> V_120 , & V_2 -> V_121 ) ;
} else
F_136 ( & V_2 -> V_119 ) ;
F_137 ( & V_2 -> V_42 , V_122 ) ;
break;
}
}
static int F_138 ( struct V_5 * V_19 )
{
switch ( V_19 -> V_47 ) {
case V_37 :
return F_97 ( V_19 ) ;
case V_34 :
return F_100 ( V_19 ) ;
case V_33 :
return F_108 ( V_19 ) ;
case V_30 :
return F_114 ( V_19 ) ;
}
return V_78 ;
}
static int F_139 ( struct V_5 * V_19 )
{
int V_49 ;
unsigned long V_57 ;
struct V_1 * V_2 = V_19 -> V_2 ;
F_26 ( & V_2 -> V_42 ) ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
F_58 ( V_19 ) ;
if ( V_19 -> V_12 & V_13 ) {
F_125 ( V_19 ) ;
V_49 = V_123 ;
goto V_124;
}
if ( V_19 -> V_12 & V_64 ) {
V_49 = V_78 ;
goto V_125;
}
F_57 ( V_19 ) ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
V_49 = F_138 ( V_19 ) ;
F_34 ( & V_2 -> V_58 , V_57 ) ;
if ( V_19 -> V_12 & V_13 )
V_49 = V_96 ;
switch ( V_49 ) {
case V_94 :
if ( ! ( V_19 -> V_12 & V_112 ) ) {
++ V_2 -> V_113 ;
V_19 -> V_12 |= V_112 ;
}
if ( V_2 -> V_54 == V_2 -> V_113 )
F_30 ( V_2 , 0 , L_30 ) ;
else {
F_63 ( V_19 ) ;
V_49 = V_96 ;
}
goto V_124;
case V_96 :
if ( V_19 -> V_12 & V_112 ) {
-- V_2 -> V_113 ;
V_19 -> V_12 &= ~ V_112 ;
}
goto V_124;
}
V_125:
V_49 = F_122 ( V_19 , V_49 ) ;
F_125 ( V_19 ) ;
V_49 = F_124 ( V_19 , V_49 ) ;
if ( V_49 == V_92 )
goto V_124;
if ( V_49 == V_80 )
F_69 ( V_19 ) ;
if ( V_49 == V_78 )
F_68 ( V_19 ) ;
V_124:
F_35 ( & V_2 -> V_58 , V_57 ) ;
if ( V_49 != V_96 )
F_130 ( V_19 , V_49 ) ;
F_137 ( & V_2 -> V_42 , V_122 ) ;
return V_49 ;
}
static int F_140 ( void * V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
struct V_126 * V_127 ;
struct V_5 * V_6 ;
unsigned long V_57 ;
for (; ; ) {
F_141 ( V_2 -> V_11 ,
! F_72 ( & V_2 -> V_10 ) ||
F_142 () ) ;
if ( F_142 () )
break;
F_34 ( & V_2 -> V_58 , V_57 ) ;
V_127 = V_2 -> V_10 . V_127 ;
F_35 ( & V_2 -> V_58 , V_57 ) ;
if ( V_127 != & V_2 -> V_10 ) {
V_6 = F_143 ( V_127 , struct V_5 , V_9 ) ;
if ( F_139 ( V_6 ) != V_123 )
F_70 ( V_2 ) ;
}
}
return 0 ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
V_129 = F_145 ( F_140 , V_2 , L_31 ,
F_146 ( & V_2 -> V_109 -> V_41 ) ) ;
if ( F_77 ( V_129 ) ) {
F_117 ( & V_2 -> V_109 -> V_41 ,
L_32 ) ;
return F_147 ( V_129 ) ;
}
V_2 -> V_50 = V_129 ;
return 0 ;
}
void F_148 ( struct V_1 * V_2 )
{
F_149 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
F_150 ( ! F_72 ( & V_2 -> V_10 ) ) ;
F_150 ( ! F_72 ( & V_2 -> V_59 ) ) ;
}
void F_52 ( struct V_1 * V_2 )
{
F_82 ( V_2 -> V_71 ,
! ( F_12 ( & V_2 -> V_12 ) &
V_53 ) ) ;
}
void F_32 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
unsigned long V_57 ;
T_1 V_130 = V_3 & V_131 ;
F_23 ( V_3 , & V_2 -> V_12 ) ;
if ( ! V_130 )
return;
F_71 ( & V_2 -> V_24 , V_57 ) ;
F_4 (port, &adapter->port_list, list)
F_23 ( V_130 , & V_21 -> V_12 ) ;
F_74 ( & V_2 -> V_24 , V_57 ) ;
F_151 ( V_2 -> V_22 -> V_23 , V_57 ) ;
F_15 (sdev, adapter->scsi_host)
F_23 ( V_130 , & F_11 ( V_15 ) -> V_12 ) ;
F_152 ( V_2 -> V_22 -> V_23 , V_57 ) ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
unsigned long V_57 ;
T_1 V_130 = V_3 & V_131 ;
T_1 V_132 = V_3 & V_32 ;
F_73 ( V_3 , & V_2 -> V_12 ) ;
if ( ! V_130 )
return;
if ( V_132 )
F_89 ( & V_2 -> V_107 , 0 ) ;
F_71 ( & V_2 -> V_24 , V_57 ) ;
F_4 (port, &adapter->port_list, list) {
F_73 ( V_130 , & V_21 -> V_12 ) ;
if ( V_132 )
F_89 ( & V_21 -> V_107 , 0 ) ;
}
F_74 ( & V_2 -> V_24 , V_57 ) ;
F_151 ( V_2 -> V_22 -> V_23 , V_57 ) ;
F_15 (sdev, adapter->scsi_host) {
F_73 ( V_130 , & F_11 ( V_15 ) -> V_12 ) ;
if ( V_132 )
F_89 ( & F_11 ( V_15 ) -> V_107 , 0 ) ;
}
F_152 ( V_2 -> V_22 -> V_23 , V_57 ) ;
}
void F_45 ( struct V_20 * V_21 , T_1 V_3 )
{
struct V_14 * V_15 ;
T_1 V_130 = V_3 & V_131 ;
unsigned long V_57 ;
F_23 ( V_3 , & V_21 -> V_12 ) ;
if ( ! V_130 )
return;
F_151 ( V_21 -> V_2 -> V_22 -> V_23 , V_57 ) ;
F_15 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 )
F_23 ( V_130 ,
& F_11 ( V_15 ) -> V_12 ) ;
F_152 ( V_21 -> V_2 -> V_22 -> V_23 , V_57 ) ;
}
void F_40 ( struct V_20 * V_21 , T_1 V_3 )
{
struct V_14 * V_15 ;
T_1 V_130 = V_3 & V_131 ;
T_1 V_132 = V_3 & V_32 ;
unsigned long V_57 ;
F_73 ( V_3 , & V_21 -> V_12 ) ;
if ( ! V_130 )
return;
if ( V_132 )
F_89 ( & V_21 -> V_107 , 0 ) ;
F_151 ( V_21 -> V_2 -> V_22 -> V_23 , V_57 ) ;
F_15 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 ) {
F_73 ( V_130 ,
& F_11 ( V_15 ) -> V_12 ) ;
if ( V_132 )
F_89 ( & F_11 ( V_15 ) -> V_107 , 0 ) ;
}
F_152 ( V_21 -> V_2 -> V_22 -> V_23 , V_57 ) ;
}
void F_119 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_23 ( V_3 , & V_17 -> V_12 ) ;
}
void F_47 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_73 ( V_3 , & V_17 -> V_12 ) ;
if ( V_3 & V_32 )
F_89 ( & V_17 -> V_107 , 0 ) ;
}
