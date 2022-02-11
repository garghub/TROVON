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
memset ( V_19 , 0 , sizeof( struct V_5 ) ) ;
V_19 -> V_21 = V_21 ;
V_19 -> V_15 = V_15 ;
if ( ! ( F_12 ( & V_17 -> V_12 ) &
V_31 ) )
V_38 |= V_40 ;
break;
case V_33 :
case V_34 :
if ( ! F_24 ( & V_21 -> V_41 ) )
return NULL ;
F_13 ( V_21 ) ;
F_23 ( V_18 , & V_21 -> V_12 ) ;
V_19 = & V_21 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_5 ) ) ;
V_19 -> V_21 = V_21 ;
if ( ! ( F_12 ( & V_21 -> V_12 ) & V_31 ) )
V_38 |= V_40 ;
break;
case V_37 :
F_25 ( & V_2 -> V_42 ) ;
F_17 ( V_2 ) ;
F_23 ( V_18 , & V_2 -> V_12 ) ;
V_19 = & V_2 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_5 ) ) ;
if ( ! ( F_12 ( & V_2 -> V_12 ) &
V_31 ) )
V_38 |= V_40 ;
break;
default:
return NULL ;
}
V_19 -> V_2 = V_2 ;
V_19 -> V_43 = V_26 ;
V_19 -> V_12 = V_38 ;
return V_19 ;
}
static int F_26 ( int V_25 , struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_14 * V_15 ,
char * V_44 , T_1 V_38 )
{
int V_45 = 1 , V_26 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_46 )
return - V_47 ;
V_26 = F_20 ( V_25 , V_2 , V_21 , V_15 ) ;
if ( ! V_26 )
goto V_48;
V_6 = F_21 ( V_26 , V_38 , V_2 , V_21 , V_15 ) ;
if ( ! V_6 )
goto V_48;
F_23 ( V_49 , & V_2 -> V_12 ) ;
++ V_2 -> V_50 ;
F_27 ( & V_6 -> V_9 , & V_2 -> V_10 ) ;
F_8 ( & V_2 -> V_11 ) ;
V_45 = 0 ;
V_48:
F_28 ( V_44 , V_2 , V_21 , V_15 , V_25 , V_26 ) ;
return V_45 ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_51 , char * V_44 )
{
F_1 ( V_2 , V_51 ) ;
F_30 ( V_2 ) ;
if ( F_12 ( & V_2 -> V_12 ) & V_32 ) {
F_31 ( V_2 ,
V_32 ) ;
return - V_47 ;
}
return F_26 ( V_37 ,
V_2 , NULL , NULL , V_44 , 0 ) ;
}
void F_32 ( struct V_1 * V_2 , int V_52 , char * V_44 )
{
unsigned long V_53 ;
F_1 ( V_2 , V_52 ) ;
F_30 ( V_2 ) ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
if ( F_12 ( & V_2 -> V_12 ) & V_32 )
F_31 ( V_2 ,
V_32 ) ;
else
F_26 ( V_37 , V_2 ,
NULL , NULL , V_44 , 0 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
}
void F_35 ( struct V_1 * V_2 , int V_52 ,
char * V_44 )
{
int V_53 = V_31 | V_32 ;
F_32 ( V_2 , V_52 | V_53 , V_44 ) ;
}
void F_36 ( struct V_20 * V_21 , int V_52 , char * V_44 )
{
int V_53 = V_31 | V_32 ;
F_37 ( V_21 , V_52 | V_53 , V_44 ) ;
}
static void F_38 ( struct V_20 * V_21 , int V_52 )
{
F_39 ( V_21 ,
V_4 | V_52 ) ;
}
static void F_40 ( struct V_20 * V_21 , int V_52 ,
char * V_44 )
{
F_38 ( V_21 , V_52 ) ;
F_41 ( V_21 ) ;
if ( F_12 ( & V_21 -> V_12 ) & V_32 )
return;
F_26 ( V_34 ,
V_21 -> V_2 , V_21 , NULL , V_44 , 0 ) ;
}
void F_42 ( struct V_20 * V_21 , int V_52 , char * V_44 )
{
unsigned long V_53 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
F_40 ( V_21 , V_52 , V_44 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
}
static int F_43 ( struct V_20 * V_21 , int V_52 , char * V_44 )
{
F_38 ( V_21 , V_52 ) ;
F_41 ( V_21 ) ;
if ( F_12 ( & V_21 -> V_12 ) & V_32 ) {
F_44 ( V_21 , V_32 ) ;
return - V_47 ;
}
return F_26 ( V_33 ,
V_21 -> V_2 , V_21 , NULL , V_44 , 0 ) ;
}
int F_37 ( struct V_20 * V_21 , int V_52 , char * V_44 )
{
int V_45 ;
unsigned long V_53 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
V_45 = F_43 ( V_21 , V_52 , V_44 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
return V_45 ;
}
static void F_45 ( struct V_14 * V_15 , int V_51 )
{
F_46 ( V_15 ,
V_4 | V_51 ) ;
}
static void F_47 ( struct V_14 * V_15 , int V_52 , char * V_44 ,
T_1 V_38 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_1 * V_2 = V_17 -> V_21 -> V_2 ;
F_45 ( V_15 , V_52 ) ;
if ( F_12 ( & V_17 -> V_12 ) & V_32 )
return;
F_26 ( V_30 , V_2 ,
V_17 -> V_21 , V_15 , V_44 , V_38 ) ;
}
void F_48 ( struct V_14 * V_15 , int V_52 , char * V_44 )
{
unsigned long V_53 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
F_47 ( V_15 , V_52 , V_44 , 0 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
}
void F_49 ( struct V_14 * V_15 , int V_52 , char * V_44 )
{
int V_53 = V_31 | V_32 ;
F_48 ( V_15 , V_52 | V_53 , V_44 ) ;
}
void F_50 ( struct V_14 * V_15 , char * V_44 )
{
unsigned long V_53 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_52 = V_31 | V_32 ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
F_47 ( V_15 , V_52 , V_44 , V_39 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
F_51 ( V_2 ) ;
}
static int F_52 ( unsigned long V_3 , T_2 * V_12 )
{
return ( F_12 ( V_12 ) ^ V_3 ) & V_3 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( F_52 ( V_4 , & V_2 -> V_12 ) )
F_7 ( L_3 , & V_2 -> V_19 ) ;
F_23 ( V_4 , & V_2 -> V_12 ) ;
}
static void F_54 ( struct V_20 * V_21 )
{
if ( F_52 ( V_4 , & V_21 -> V_12 ) )
F_7 ( L_4 , & V_21 -> V_19 ) ;
F_23 ( V_4 , & V_21 -> V_12 ) ;
}
static void F_55 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
if ( F_52 ( V_4 , & V_17 -> V_12 ) )
F_7 ( L_5 , & F_11 ( V_15 ) -> V_19 ) ;
F_23 ( V_4 , & V_17 -> V_12 ) ;
}
static void F_56 ( struct V_5 * V_19 )
{
F_6 ( & V_19 -> V_9 , & V_19 -> V_2 -> V_55 ) ;
F_7 ( L_6 , V_19 ) ;
}
static void F_57 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_56 * V_57 ;
if ( ! V_6 -> V_58 )
return;
F_14 ( & V_2 -> V_59 -> V_60 ) ;
V_57 = F_58 ( V_2 -> V_59 , V_6 -> V_58 ) ;
if ( V_57 && V_57 -> V_19 == V_6 ) {
if ( V_6 -> V_12 & ( V_13 |
V_61 ) ) {
V_57 -> V_12 |= V_62 ;
F_7 ( L_7 , V_6 ) ;
V_57 -> V_19 = NULL ;
}
if ( V_6 -> V_12 & V_61 )
F_7 ( L_8 , V_6 ) ;
if ( V_57 -> V_12 & V_62 )
V_6 -> V_58 = 0 ;
} else
V_6 -> V_58 = 0 ;
F_16 ( & V_2 -> V_59 -> V_60 ) ;
}
void F_59 ( struct V_5 * V_19 , unsigned long V_63 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long V_53 ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
if ( F_3 ( V_19 ) == V_8 ) {
V_19 -> V_12 |= V_63 ;
F_5 ( V_19 ) ;
}
F_34 ( & V_2 -> V_54 , V_53 ) ;
}
void F_60 ( unsigned long V_64 )
{
struct V_5 * V_6 = (struct V_5 * ) V_64 ;
F_59 ( V_6 , V_61 ) ;
}
static void F_61 ( unsigned long V_64 )
{
F_59 ( (struct V_5 * ) V_64 , 0 ) ;
}
static void F_62 ( struct V_5 * V_19 )
{
F_63 ( & V_19 -> V_65 ) ;
V_19 -> V_65 . V_66 = F_61 ;
V_19 -> V_65 . V_64 = ( unsigned long ) V_19 ;
V_19 -> V_65 . V_67 = V_68 + V_69 ;
F_64 ( & V_19 -> V_65 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
int V_52 , char * V_44 )
{
struct V_20 * V_21 ;
F_18 ( & V_2 -> V_24 ) ;
F_4 (port, &adapter->port_list, list)
F_43 ( V_21 , V_52 , V_44 ) ;
F_19 ( & V_2 -> V_24 ) ;
}
static void F_66 ( struct V_20 * V_21 , int V_52 ,
char * V_44 )
{
struct V_14 * V_15 ;
F_14 ( V_21 -> V_2 -> V_22 -> V_23 ) ;
F_15 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 )
F_47 ( V_15 , V_52 , V_44 , 0 ) ;
F_16 ( V_21 -> V_2 -> V_22 -> V_23 ) ;
}
static void F_67 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_43 ) {
case V_37 :
F_29 ( V_6 -> V_2 , 0 , L_9 ) ;
break;
case V_34 :
F_40 ( V_6 -> V_21 , 0 , L_10 ) ;
break;
case V_33 :
F_43 ( V_6 -> V_21 , 0 , L_11 ) ;
break;
case V_30 :
F_47 ( V_6 -> V_15 , 0 , L_12 , 0 ) ;
break;
}
}
static void F_68 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_43 ) {
case V_37 :
F_65 ( V_6 -> V_2 , 0 , L_13 ) ;
break;
case V_34 :
F_43 ( V_6 -> V_21 , 0 , L_14 ) ;
break;
case V_33 :
F_66 ( V_6 -> V_21 , 0 , L_15 ) ;
break;
}
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_53 ;
F_70 ( & V_2 -> V_54 , V_53 ) ;
if ( F_71 ( & V_2 -> V_10 ) &&
F_71 ( & V_2 -> V_55 ) ) {
F_72 ( V_49 ,
& V_2 -> V_12 ) ;
F_8 ( & V_2 -> V_70 ) ;
}
F_73 ( & V_2 -> V_54 , V_53 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
V_21 = F_75 ( V_2 , V_2 -> V_71 , 0 ,
V_2 -> V_72 ) ;
if ( F_76 ( V_21 ) )
return;
F_43 ( V_21 , 0 , L_16 ) ;
}
static int F_77 ( struct V_5 * V_19 )
{
int V_73 ;
int V_74 = 1 ;
struct V_1 * V_2 = V_19 -> V_2 ;
F_72 ( V_75 , & V_2 -> V_12 ) ;
for ( V_73 = 7 ; V_73 ; V_73 -- ) {
F_72 ( V_76 ,
& V_2 -> V_12 ) ;
F_78 ( & V_2 -> V_54 ) ;
F_56 ( V_19 ) ;
F_79 ( & V_2 -> V_54 ) ;
if ( F_80 ( V_19 ) ) {
F_72 ( V_76 ,
& V_2 -> V_12 ) ;
return V_77 ;
}
F_81 ( V_2 -> V_11 ,
! F_71 ( & V_2 -> V_10 ) ) ;
if ( V_19 -> V_12 & V_61 )
break;
if ( ! ( F_12 ( & V_2 -> V_12 ) &
V_76 ) )
break;
F_82 ( V_74 ) ;
V_74 *= 2 ;
}
F_72 ( V_76 ,
& V_2 -> V_12 ) ;
if ( ! ( F_12 ( & V_2 -> V_12 ) & V_75 ) )
return V_77 ;
if ( F_83 ( V_2 -> V_22 ) == V_78 )
F_74 ( V_2 ) ;
return V_79 ;
}
static int F_84 ( struct V_5 * V_6 )
{
int V_80 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_78 ( & V_2 -> V_54 ) ;
F_56 ( V_6 ) ;
F_79 ( & V_2 -> V_54 ) ;
V_80 = F_85 ( V_6 ) ;
if ( V_80 == - V_81 )
return V_79 ;
if ( V_80 )
return V_77 ;
F_7 ( L_17 , V_6 ) ;
F_81 ( V_2 -> V_11 ,
! F_71 ( & V_2 -> V_10 ) ) ;
F_7 ( L_18 , V_6 ) ;
if ( V_6 -> V_12 & V_61 )
return V_77 ;
return V_79 ;
}
static int F_86 ( struct V_5 * V_6 )
{
if ( F_77 ( V_6 ) == V_77 )
return V_77 ;
if ( F_84 ( V_6 ) == V_77 )
return V_77 ;
if ( F_87 ( V_6 -> V_2 -> V_82 . V_83 ,
V_6 -> V_2 -> V_84 ) )
return V_77 ;
if ( F_87 ( V_6 -> V_2 -> V_82 . V_85 ,
V_6 -> V_2 -> V_84 ) )
return V_77 ;
F_88 ( & V_6 -> V_2 -> V_86 , V_6 -> V_2 -> V_84 ) ;
if ( F_89 ( V_6 -> V_2 ) )
return V_77 ;
return V_79 ;
}
static void F_90 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_91 ( V_2 -> V_87 ) ;
F_92 ( V_2 ) ;
V_2 -> V_88 = 0 ;
F_93 ( V_2 -> V_89 ) ;
F_2 ( V_2 , V_35 ) ;
F_72 ( V_75 |
V_90 , & V_2 -> V_12 ) ;
}
static int F_94 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( F_95 ( V_2 -> V_87 ) ) {
F_72 ( V_75 |
V_90 ,
& V_2 -> V_12 ) ;
return V_77 ;
}
if ( F_86 ( V_6 ) ) {
F_90 ( V_6 ) ;
return V_77 ;
}
F_23 ( V_35 , & V_2 -> V_12 ) ;
return V_79 ;
}
static int F_96 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( F_12 ( & V_2 -> V_12 ) & V_35 ) {
F_90 ( V_6 ) ;
if ( V_6 -> V_12 & V_40 )
return V_91 ;
}
if ( F_94 ( V_6 ) ) {
F_82 ( 8 ) ;
return V_77 ;
}
return V_79 ;
}
static int F_97 ( struct V_5 * V_6 )
{
int V_45 ;
V_45 = F_98 ( V_6 ) ;
if ( V_45 == - V_92 )
return V_93 ;
V_6 -> V_94 = V_95 ;
if ( V_45 )
return V_77 ;
return V_96 ;
}
static int F_99 ( struct V_5 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
int V_12 = F_12 ( & V_21 -> V_12 ) ;
switch ( V_19 -> V_94 ) {
case V_97 :
if ( ( V_12 & V_98 ) &&
( V_12 & V_35 ) )
return F_97 ( V_19 ) ;
else
return V_77 ;
case V_95 :
if ( ! ( V_12 & V_98 ) )
return V_79 ;
}
return V_77 ;
}
static int F_100 ( struct V_5 * V_19 )
{
int V_45 ;
V_45 = F_101 ( V_19 ) ;
if ( V_45 == - V_92 )
return V_93 ;
V_19 -> V_94 = V_99 ;
if ( V_45 )
return V_77 ;
return V_96 ;
}
static int F_102 ( struct V_5 * V_19 )
{
int V_45 ;
V_45 = F_103 ( V_19 ) ;
if ( V_45 == - V_92 )
return V_93 ;
V_19 -> V_94 = V_100 ;
if ( V_45 )
return V_77 ;
return V_96 ;
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
if ( V_21 -> V_101 != V_2 -> V_71 ) {
F_44 ( V_21 , V_32 ) ;
return V_77 ;
}
V_21 -> V_102 = V_2 -> V_72 ;
return F_102 ( V_6 ) ;
}
static int F_105 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
int V_28 = F_12 ( & V_21 -> V_12 ) ;
switch ( V_6 -> V_94 ) {
case V_97 :
case V_95 :
case V_99 :
if ( F_83 ( V_2 -> V_22 ) == V_78 )
return F_104 ( V_6 ) ;
if ( ! V_21 -> V_102 ) {
F_106 ( V_21 ) ;
return V_91 ;
}
return F_102 ( V_6 ) ;
case V_100 :
if ( V_28 & V_35 ) {
if ( ! V_21 -> V_102 ) {
F_106 ( V_21 ) ;
return V_91 ;
}
return V_79 ;
}
if ( V_21 -> V_102 && ! ( V_28 & V_36 ) ) {
V_21 -> V_102 = 0 ;
return V_77 ;
}
}
return V_77 ;
}
static int F_107 ( struct V_5 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
int V_28 = F_12 ( & V_21 -> V_12 ) ;
if ( ( V_28 & V_36 ) &&
! ( V_28 & V_35 ) )
goto V_103;
switch ( V_19 -> V_94 ) {
case V_97 :
if ( V_28 & V_35 )
return F_100 ( V_19 ) ;
break;
case V_99 :
if ( V_28 & V_35 )
return V_77 ;
break;
}
V_103:
if ( V_19 -> V_12 & V_40 )
return V_91 ;
return F_105 ( V_19 ) ;
}
static void F_108 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_72 ( V_104 ,
& V_17 -> V_12 ) ;
}
static int F_109 ( struct V_5 * V_19 )
{
int V_45 = F_110 ( V_19 ) ;
if ( V_45 == - V_92 )
return V_93 ;
V_19 -> V_94 = V_105 ;
if ( V_45 )
return V_77 ;
return V_96 ;
}
static int F_111 ( struct V_5 * V_19 )
{
int V_45 = F_112 ( V_19 ) ;
if ( V_45 == - V_92 )
return V_93 ;
V_19 -> V_94 = V_106 ;
if ( V_45 )
return V_77 ;
return V_96 ;
}
static int F_113 ( struct V_5 * V_19 )
{
struct V_14 * V_15 = V_19 -> V_15 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
switch ( V_19 -> V_94 ) {
case V_97 :
F_108 ( V_15 ) ;
if ( F_12 ( & V_17 -> V_12 ) & V_35 )
return F_109 ( V_19 ) ;
case V_105 :
if ( F_12 ( & V_17 -> V_12 ) & V_35 )
return V_77 ;
if ( V_19 -> V_12 & V_40 )
return V_91 ;
return F_111 ( V_19 ) ;
case V_106 :
if ( F_12 ( & V_17 -> V_12 ) & V_35 )
return V_79 ;
}
return V_77 ;
}
static int F_114 ( struct V_14 * V_15 , int V_107 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
switch ( V_107 ) {
case V_79 :
F_88 ( & V_17 -> V_108 , 0 ) ;
F_55 ( V_15 ) ;
break;
case V_77 :
F_115 ( & V_17 -> V_108 ) ;
if ( F_12 ( & V_17 -> V_108 ) > V_109 ) {
F_116 ( & V_17 -> V_21 -> V_2 -> V_110 -> V_41 ,
L_19
L_20 ,
( unsigned long long ) F_117 ( V_15 ) ,
( unsigned long long ) V_17 -> V_21 -> V_101 ) ;
F_118 ( V_15 ,
V_32 ) ;
}
break;
}
if ( F_12 ( & V_17 -> V_12 ) & V_32 ) {
F_45 ( V_15 , 0 ) ;
V_107 = V_91 ;
}
return V_107 ;
}
static int F_119 ( struct V_20 * V_21 , int V_107 )
{
switch ( V_107 ) {
case V_79 :
F_88 ( & V_21 -> V_108 , 0 ) ;
F_54 ( V_21 ) ;
break;
case V_77 :
if ( F_12 ( & V_21 -> V_12 ) & V_36 ) {
F_38 ( V_21 , 0 ) ;
V_107 = V_91 ;
}
F_115 ( & V_21 -> V_108 ) ;
if ( F_12 ( & V_21 -> V_108 ) > V_109 ) {
F_116 ( & V_21 -> V_2 -> V_110 -> V_41 ,
L_21 ,
( unsigned long long ) V_21 -> V_101 ) ;
F_44 ( V_21 ,
V_32 ) ;
}
break;
}
if ( F_12 ( & V_21 -> V_12 ) & V_32 ) {
F_38 ( V_21 , 0 ) ;
V_107 = V_91 ;
}
return V_107 ;
}
static int F_120 ( struct V_1 * V_2 ,
int V_107 )
{
switch ( V_107 ) {
case V_79 :
F_88 ( & V_2 -> V_108 , 0 ) ;
F_53 ( V_2 ) ;
break;
case V_77 :
F_115 ( & V_2 -> V_108 ) ;
if ( F_12 ( & V_2 -> V_108 ) > V_109 ) {
F_116 ( & V_2 -> V_110 -> V_41 ,
L_22
L_23 ) ;
F_31 ( V_2 ,
V_32 ) ;
}
break;
}
if ( F_12 ( & V_2 -> V_12 ) & V_32 ) {
F_1 ( V_2 , 0 ) ;
V_107 = V_91 ;
}
return V_107 ;
}
static int F_121 ( struct V_5 * V_19 ,
int V_107 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_14 * V_15 = V_19 -> V_15 ;
switch ( V_19 -> V_43 ) {
case V_30 :
V_107 = F_114 ( V_15 , V_107 ) ;
break;
case V_34 :
case V_33 :
V_107 = F_119 ( V_21 , V_107 ) ;
break;
case V_37 :
V_107 = F_120 ( V_2 , V_107 ) ;
break;
}
return V_107 ;
}
static int F_122 ( T_2 * V_111 , T_1 V_112 )
{
int V_12 = F_12 ( V_111 ) ;
if ( ( V_12 & V_31 ) &&
( V_112 & V_40 ) )
return 1 ;
if ( ! ( V_12 & V_31 ) &&
! ( V_112 & V_40 ) )
return 1 ;
return 0 ;
}
static int F_123 ( struct V_5 * V_6 , int V_80 )
{
int V_43 = V_6 -> V_43 ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 ;
T_1 V_112 = V_6 -> V_12 ;
switch ( V_43 ) {
case V_37 :
if ( F_122 ( & V_2 -> V_12 , V_112 ) ) {
F_29 ( V_2 ,
V_32 ,
L_24 ) ;
return V_91 ;
}
break;
case V_34 :
case V_33 :
if ( F_122 ( & V_21 -> V_12 , V_112 ) ) {
F_43 ( V_21 ,
V_32 ,
L_25 ) ;
return V_91 ;
}
break;
case V_30 :
V_17 = F_11 ( V_15 ) ;
if ( F_122 ( & V_17 -> V_12 , V_112 ) ) {
F_47 ( V_15 ,
V_32 ,
L_26 , 0 ) ;
return V_91 ;
}
break;
}
return V_80 ;
}
static void F_124 ( struct V_5 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_16 * V_17 ;
V_2 -> V_50 -- ;
if ( V_19 -> V_12 & V_113 ) {
V_2 -> V_114 -- ;
V_19 -> V_12 &= ~ V_113 ;
}
F_125 ( & V_19 -> V_9 ) ;
F_7 ( L_27 , V_19 ) ;
switch ( V_19 -> V_43 ) {
case V_30 :
V_17 = F_11 ( V_19 -> V_15 ) ;
F_72 ( V_18 ,
& V_17 -> V_12 ) ;
break;
case V_34 :
case V_33 :
F_72 ( V_18 ,
& V_19 -> V_21 -> V_12 ) ;
break;
case V_37 :
F_72 ( V_18 ,
& V_19 -> V_2 -> V_12 ) ;
break;
}
}
static void F_126 ( struct V_20 * V_21 )
{
unsigned long V_53 ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_115 ;
struct V_116 * V_117 = V_2 -> V_22 ;
struct V_14 * V_15 ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
V_115 = F_12 ( & V_21 -> V_12 ) ;
if ( ( V_115 & V_4 ) == 0 ||
( V_115 & ( V_18 |
V_32 ) ) != 0 ) {
F_127 ( 4 , L_28 , & V_21 -> V_19 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
return;
}
F_14 ( V_117 -> V_23 ) ;
F_15 (sdev, shost) {
struct V_16 * V_118 = F_11 ( V_15 ) ;
int V_119 ;
if ( V_118 -> V_21 != V_21 )
continue;
V_119 = F_12 ( & V_118 -> V_12 ) ;
if ( ( V_119 & V_32 ) != 0 )
continue;
if ( ( V_119 & V_4 ) == 0 ||
( V_119 & V_18 ) != 0 ) {
F_127 ( 4 , L_29 , & V_118 -> V_19 ) ;
F_16 ( V_117 -> V_23 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
return;
}
}
F_128 ( V_21 ) ;
F_16 ( V_117 -> V_23 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
}
static void F_129 ( struct V_5 * V_6 , int V_107 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_14 * V_15 = V_6 -> V_15 ;
switch ( V_6 -> V_43 ) {
case V_30 :
if ( ! ( V_6 -> V_12 & V_39 ) )
F_130 ( V_15 ) ;
F_126 ( V_21 ) ;
break;
case V_33 :
if ( V_6 -> V_94 != V_97 )
if ( V_107 == V_79 )
F_126 ( V_21 ) ;
case V_34 :
F_131 ( & V_21 -> V_41 ) ;
break;
case V_37 :
if ( V_107 == V_79 ) {
F_132 ( & V_2 -> V_120 ) ;
F_133 ( V_2 ) ;
F_134 ( V_2 -> V_121 , & V_2 -> V_122 ) ;
} else
F_135 ( & V_2 -> V_120 ) ;
F_136 ( & V_2 -> V_42 , V_123 ) ;
break;
}
}
static int F_137 ( struct V_5 * V_19 )
{
switch ( V_19 -> V_43 ) {
case V_37 :
return F_96 ( V_19 ) ;
case V_34 :
return F_99 ( V_19 ) ;
case V_33 :
return F_107 ( V_19 ) ;
case V_30 :
return F_113 ( V_19 ) ;
}
return V_77 ;
}
static int F_138 ( struct V_5 * V_19 )
{
int V_45 ;
unsigned long V_53 ;
struct V_1 * V_2 = V_19 -> V_2 ;
F_25 ( & V_2 -> V_42 ) ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
F_57 ( V_19 ) ;
if ( V_19 -> V_12 & V_13 ) {
F_124 ( V_19 ) ;
V_45 = V_124 ;
goto V_125;
}
if ( V_19 -> V_12 & V_61 ) {
V_45 = V_77 ;
goto V_126;
}
F_56 ( V_19 ) ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
V_45 = F_137 ( V_19 ) ;
F_33 ( & V_2 -> V_54 , V_53 ) ;
if ( V_19 -> V_12 & V_13 )
V_45 = V_96 ;
switch ( V_45 ) {
case V_93 :
if ( ! ( V_19 -> V_12 & V_113 ) ) {
++ V_2 -> V_114 ;
V_19 -> V_12 |= V_113 ;
}
if ( V_2 -> V_50 == V_2 -> V_114 )
F_29 ( V_2 , 0 , L_30 ) ;
else {
F_62 ( V_19 ) ;
V_45 = V_96 ;
}
goto V_125;
case V_96 :
if ( V_19 -> V_12 & V_113 ) {
-- V_2 -> V_114 ;
V_19 -> V_12 &= ~ V_113 ;
}
goto V_125;
}
V_126:
V_45 = F_121 ( V_19 , V_45 ) ;
F_124 ( V_19 ) ;
V_45 = F_123 ( V_19 , V_45 ) ;
if ( V_45 == V_91 )
goto V_125;
if ( V_45 == V_79 )
F_68 ( V_19 ) ;
if ( V_45 == V_77 )
F_67 ( V_19 ) ;
V_125:
F_34 ( & V_2 -> V_54 , V_53 ) ;
if ( V_45 != V_96 )
F_129 ( V_19 , V_45 ) ;
F_136 ( & V_2 -> V_42 , V_123 ) ;
return V_45 ;
}
static int F_139 ( void * V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
struct V_127 * V_128 ;
struct V_5 * V_6 ;
unsigned long V_53 ;
for (; ; ) {
F_140 ( V_2 -> V_11 ,
! F_71 ( & V_2 -> V_10 ) ||
F_141 () ) ;
if ( F_141 () )
break;
F_33 ( & V_2 -> V_54 , V_53 ) ;
V_128 = V_2 -> V_10 . V_128 ;
F_34 ( & V_2 -> V_54 , V_53 ) ;
if ( V_128 != & V_2 -> V_10 ) {
V_6 = F_142 ( V_128 , struct V_5 , V_9 ) ;
if ( F_138 ( V_6 ) != V_124 )
F_69 ( V_2 ) ;
}
}
return 0 ;
}
int F_143 ( struct V_1 * V_2 )
{
struct V_129 * V_130 ;
V_130 = F_144 ( F_139 , V_2 , L_31 ,
F_145 ( & V_2 -> V_110 -> V_41 ) ) ;
if ( F_76 ( V_130 ) ) {
F_116 ( & V_2 -> V_110 -> V_41 ,
L_32 ) ;
return F_146 ( V_130 ) ;
}
V_2 -> V_46 = V_130 ;
return 0 ;
}
void F_147 ( struct V_1 * V_2 )
{
F_148 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
F_149 ( ! F_71 ( & V_2 -> V_10 ) ) ;
F_149 ( ! F_71 ( & V_2 -> V_55 ) ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_81 ( V_2 -> V_70 ,
! ( F_12 ( & V_2 -> V_12 ) &
V_49 ) ) ;
}
void F_31 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
unsigned long V_53 ;
T_1 V_131 = V_3 & V_132 ;
F_23 ( V_3 , & V_2 -> V_12 ) ;
if ( ! V_131 )
return;
F_70 ( & V_2 -> V_24 , V_53 ) ;
F_4 (port, &adapter->port_list, list)
F_23 ( V_131 , & V_21 -> V_12 ) ;
F_73 ( & V_2 -> V_24 , V_53 ) ;
F_150 ( V_2 -> V_22 -> V_23 , V_53 ) ;
F_15 (sdev, adapter->scsi_host)
F_23 ( V_131 , & F_11 ( V_15 ) -> V_12 ) ;
F_151 ( V_2 -> V_22 -> V_23 , V_53 ) ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
unsigned long V_53 ;
T_1 V_131 = V_3 & V_132 ;
T_1 V_133 = V_3 & V_32 ;
F_72 ( V_3 , & V_2 -> V_12 ) ;
if ( ! V_131 )
return;
if ( V_133 )
F_88 ( & V_2 -> V_108 , 0 ) ;
F_70 ( & V_2 -> V_24 , V_53 ) ;
F_4 (port, &adapter->port_list, list) {
F_72 ( V_131 , & V_21 -> V_12 ) ;
if ( V_133 )
F_88 ( & V_21 -> V_108 , 0 ) ;
}
F_73 ( & V_2 -> V_24 , V_53 ) ;
F_150 ( V_2 -> V_22 -> V_23 , V_53 ) ;
F_15 (sdev, adapter->scsi_host) {
F_72 ( V_131 , & F_11 ( V_15 ) -> V_12 ) ;
if ( V_133 )
F_88 ( & F_11 ( V_15 ) -> V_108 , 0 ) ;
}
F_151 ( V_2 -> V_22 -> V_23 , V_53 ) ;
}
void F_44 ( struct V_20 * V_21 , T_1 V_3 )
{
struct V_14 * V_15 ;
T_1 V_131 = V_3 & V_132 ;
unsigned long V_53 ;
F_23 ( V_3 , & V_21 -> V_12 ) ;
if ( ! V_131 )
return;
F_150 ( V_21 -> V_2 -> V_22 -> V_23 , V_53 ) ;
F_15 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 )
F_23 ( V_131 ,
& F_11 ( V_15 ) -> V_12 ) ;
F_151 ( V_21 -> V_2 -> V_22 -> V_23 , V_53 ) ;
}
void F_39 ( struct V_20 * V_21 , T_1 V_3 )
{
struct V_14 * V_15 ;
T_1 V_131 = V_3 & V_132 ;
T_1 V_133 = V_3 & V_32 ;
unsigned long V_53 ;
F_72 ( V_3 , & V_21 -> V_12 ) ;
if ( ! V_131 )
return;
if ( V_133 )
F_88 ( & V_21 -> V_108 , 0 ) ;
F_150 ( V_21 -> V_2 -> V_22 -> V_23 , V_53 ) ;
F_15 (sdev, port->adapter->scsi_host)
if ( F_11 ( V_15 ) -> V_21 == V_21 ) {
F_72 ( V_131 ,
& F_11 ( V_15 ) -> V_12 ) ;
if ( V_133 )
F_88 ( & F_11 ( V_15 ) -> V_108 , 0 ) ;
}
F_151 ( V_21 -> V_2 -> V_22 -> V_23 , V_53 ) ;
}
void F_118 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_23 ( V_3 , & V_17 -> V_12 ) ;
}
void F_46 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
F_72 ( V_3 , & V_17 -> V_12 ) ;
if ( V_3 & V_32 )
F_88 ( & V_17 -> V_108 , 0 ) ;
}
