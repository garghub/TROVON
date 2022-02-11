static inline T_1 F_1 ( T_2 V_1 )
{
return ( ( T_1 ) V_1 ) * 128000ull ;
}
static inline T_1 F_2 ( T_2 V_1 , T_2 V_2 )
{
T_1 V_3 ;
if ( V_2 == 0 )
return 0 ;
V_3 = F_1 ( V_1 ) ;
F_3 ( V_3 , V_2 ) ;
return V_3 ;
}
static inline void F_4 ( void * V_4 , unsigned int V_5 )
{
register void * T_3 V_6 ( L_1 ) ;
register long T_4 V_6 ( L_2 ) ;
T_3 = V_4 ;
T_4 = V_5 ;
asm("schm" : : "d" (__gpr2), "d" (__gpr1) );
}
static int F_5 ( struct V_7 * V_8 , T_2 V_9 , int V_10 ,
unsigned long V_11 )
{
struct V_12 * V_13 = F_6 ( V_8 -> V_14 . V_15 ) ;
int V_3 ;
V_13 -> V_16 . V_9 = V_9 ;
V_13 -> V_16 . V_10 = V_10 ;
if ( V_10 )
V_13 -> V_16 . V_17 = V_11 ;
else
V_13 -> V_16 . V_18 = V_11 ;
V_3 = F_7 ( V_13 ) ;
if ( ! V_9 && V_3 == - V_19 ) {
V_3 = 0 ;
}
return V_3 ;
}
static void F_8 ( struct V_20 * V_20 )
{
struct V_21 * V_22 ;
V_22 = F_9 ( V_20 , struct V_21 , V_20 ) ;
F_10 ( V_22 ) ;
}
static int F_11 ( struct V_7 * V_8 , T_2 V_9 ,
int V_10 , unsigned long V_11 )
{
struct V_21 * V_22 ;
int V_3 ;
F_12 ( V_8 -> V_23 ) ;
if ( ! V_8 -> V_24 -> V_25 ) {
V_3 = - V_19 ;
goto V_26;
}
V_22 = F_13 ( sizeof( struct V_21 ) , V_27 ) ;
if ( ! V_22 ) {
V_3 = - V_28 ;
goto V_26;
}
F_14 ( & V_22 -> V_29 ) ;
F_15 ( & V_22 -> V_20 ) ;
V_22 -> V_9 = V_9 ;
V_22 -> V_10 = V_10 ;
V_22 -> V_11 = V_11 ;
V_3 = F_5 ( V_8 , V_9 , V_10 , V_11 ) ;
if ( V_3 != - V_30 )
goto V_31;
if ( V_8 -> V_24 -> V_32 != V_33 ) {
V_3 = - V_30 ;
goto V_31;
}
V_8 -> V_24 -> V_32 = V_34 ;
V_22 -> V_3 = V_35 ;
V_8 -> V_24 -> V_36 = V_22 ;
F_16 ( V_8 -> V_23 ) ;
if ( F_17 ( V_22 -> V_29 ,
V_22 -> V_3 != V_35 ) ) {
F_12 ( V_8 -> V_23 ) ;
if ( V_22 -> V_3 == V_35 ) {
V_22 -> V_3 = - V_37 ;
if ( V_8 -> V_24 -> V_32 == V_34 )
V_8 -> V_24 -> V_32 = V_33 ;
}
F_16 ( V_8 -> V_23 ) ;
}
F_12 ( V_8 -> V_23 ) ;
V_8 -> V_24 -> V_36 = NULL ;
V_3 = V_22 -> V_3 ;
V_31:
F_18 ( & V_22 -> V_20 , F_8 ) ;
V_26:
F_16 ( V_8 -> V_23 ) ;
return V_3 ;
}
void F_19 ( struct V_7 * V_8 )
{
struct V_21 * V_22 ;
V_22 = V_8 -> V_24 -> V_36 ;
if ( ! V_22 ) {
F_20 ( 1 ) ;
return;
}
F_21 ( & V_22 -> V_20 ) ;
V_22 -> V_3 = F_5 ( V_8 , V_22 -> V_9 , V_22 -> V_10 ,
V_22 -> V_11 ) ;
F_22 ( & V_22 -> V_29 ) ;
F_18 ( & V_22 -> V_20 , F_8 ) ;
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
void * V_38 ;
void * V_39 ;
struct V_40 * V_40 ;
V_13 = F_6 ( V_8 -> V_14 . V_15 ) ;
if ( F_24 ( V_13 ) )
return - V_19 ;
if ( F_25 ( & V_13 -> V_41 . V_42 ) & V_43 ) {
if ( ( ! ( F_26 ( & V_13 -> V_41 . V_42 ) & V_44 ) ) &&
( F_26 ( & V_13 -> V_41 . V_42 ) &
( V_45 | V_46 ) ) &&
( ! ( F_27 ( & V_13 -> V_41 . V_42 ) & V_47 ) ) )
return - V_30 ;
}
V_40 = V_8 -> V_24 -> V_25 ;
V_39 = V_40 -> V_39 ;
if ( ! memcmp ( V_40 -> V_48 , V_39 , V_40 -> V_49 ) )
return 0 ;
V_38 = F_13 ( V_40 -> V_49 , V_27 ) ;
if ( ! V_38 )
return - V_28 ;
do {
memcpy ( V_40 -> V_48 , V_39 , V_40 -> V_49 ) ;
memcpy ( V_38 , V_39 , V_40 -> V_49 ) ;
} while ( memcmp ( V_40 -> V_48 , V_38 , V_40 -> V_49 ) );
V_40 -> V_50 = F_28 () ;
F_10 ( V_38 ) ;
return 0 ;
}
static void F_29 ( struct V_20 * V_20 )
{
struct V_51 * V_52 ;
V_52 = F_9 ( V_20 , struct V_51 , V_20 ) ;
F_10 ( V_52 ) ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_51 * V_52 ;
int V_3 ;
unsigned long V_53 ;
F_31 ( V_8 -> V_23 , V_53 ) ;
if ( ! V_8 -> V_24 -> V_25 ) {
V_3 = - V_19 ;
goto V_26;
}
V_52 = F_13 ( sizeof( struct V_51 ) , V_27 ) ;
if ( ! V_52 ) {
V_3 = - V_28 ;
goto V_26;
}
F_14 ( & V_52 -> V_29 ) ;
F_15 ( & V_52 -> V_20 ) ;
V_3 = F_23 ( V_8 ) ;
if ( V_3 != - V_30 )
goto V_31;
if ( V_8 -> V_24 -> V_32 != V_33 ) {
V_3 = - V_30 ;
goto V_31;
}
V_8 -> V_24 -> V_32 = V_54 ;
V_52 -> V_3 = V_35 ;
V_8 -> V_24 -> V_36 = V_52 ;
F_32 ( V_8 -> V_23 , V_53 ) ;
if ( F_17 ( V_52 -> V_29 ,
V_52 -> V_3 != V_35 ) ) {
F_31 ( V_8 -> V_23 , V_53 ) ;
if ( V_52 -> V_3 == V_35 ) {
V_52 -> V_3 = - V_37 ;
if ( V_8 -> V_24 -> V_32 == V_54 )
V_8 -> V_24 -> V_32 = V_33 ;
}
F_32 ( V_8 -> V_23 , V_53 ) ;
}
F_31 ( V_8 -> V_23 , V_53 ) ;
V_8 -> V_24 -> V_36 = NULL ;
V_3 = V_52 -> V_3 ;
V_31:
F_18 ( & V_52 -> V_20 , F_29 ) ;
V_26:
F_32 ( V_8 -> V_23 , V_53 ) ;
return V_3 ;
}
void F_33 ( struct V_7 * V_8 )
{
struct V_51 * V_52 ;
V_52 = V_8 -> V_24 -> V_36 ;
if ( ! V_52 ) {
F_20 ( 1 ) ;
return;
}
F_21 ( & V_52 -> V_20 ) ;
V_52 -> V_3 = F_23 ( V_8 ) ;
F_22 ( & V_52 -> V_29 ) ;
F_18 ( & V_52 -> V_20 , F_29 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
struct V_40 * V_40 ;
F_12 ( V_8 -> V_23 ) ;
V_40 = V_8 -> V_24 -> V_25 ;
if ( V_40 ) {
memset ( V_40 -> V_48 , 0 , V_40 -> V_49 ) ;
memset ( V_40 -> V_39 , 0 , V_40 -> V_49 ) ;
V_40 -> V_50 = 0 ;
}
V_8 -> V_24 -> V_55 = F_28 () ;
F_16 ( V_8 -> V_23 ) ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_40 * V_40 )
{
struct V_25 * V_25 ;
struct V_56 * V_57 ;
int V_3 ;
F_12 ( V_8 -> V_23 ) ;
if ( ! F_36 ( & V_8 -> V_24 -> V_58 ) ) {
V_3 = - V_30 ;
goto V_26;
}
V_25 = V_59 . V_60 ;
F_37 (node, &cmb_area.list, cmb_list) {
struct V_40 * V_61 ;
V_61 = V_57 -> V_25 ;
if ( (struct V_25 * ) V_61 -> V_39 > V_25 )
break;
V_25 ++ ;
}
if ( V_25 - V_59 . V_60 >= V_59 . V_62 ) {
V_3 = - V_28 ;
goto V_26;
}
F_38 ( & V_8 -> V_24 -> V_58 , & V_57 -> V_58 ) ;
V_40 -> V_39 = V_25 ;
V_8 -> V_24 -> V_25 = V_40 ;
V_3 = 0 ;
V_26:
F_16 ( V_8 -> V_23 ) ;
return V_3 ;
}
static int F_39 ( struct V_7 * V_8 )
{
int V_3 ;
struct V_25 * V_60 ;
T_5 V_49 ;
struct V_40 * V_40 ;
V_40 = F_13 ( sizeof( struct V_40 ) , V_63 ) ;
if ( ! V_40 )
return - V_28 ;
V_40 -> V_48 = F_13 ( sizeof( struct V_25 ) , V_63 ) ;
if ( ! V_40 -> V_48 ) {
F_10 ( V_40 ) ;
return - V_28 ;
}
V_40 -> V_49 = sizeof( struct V_25 ) ;
F_40 ( & V_59 . V_64 ) ;
if ( ! V_59 . V_60 ) {
V_49 = sizeof( struct V_25 ) * V_59 . V_62 ;
F_20 ( ! F_36 ( & V_59 . V_65 ) ) ;
F_41 ( & V_59 . V_64 ) ;
V_60 = ( void * ) F_42 ( V_63 | V_66 ,
F_43 ( V_49 ) ) ;
F_40 ( & V_59 . V_64 ) ;
if ( V_59 . V_60 ) {
F_44 ( ( unsigned long ) V_60 , F_43 ( V_49 ) ) ;
} else if ( ! V_60 ) {
V_3 = - V_28 ;
goto V_26;
} else {
memset ( V_60 , 0 , V_49 ) ;
V_59 . V_60 = V_60 ;
F_4 ( V_59 . V_60 , V_67 ) ;
}
}
V_3 = F_35 ( V_8 , V_40 ) ;
V_26:
F_41 ( & V_59 . V_64 ) ;
if ( V_3 ) {
F_10 ( V_40 -> V_48 ) ;
F_10 ( V_40 ) ;
}
return V_3 ;
}
static void F_45 ( struct V_7 * V_8 )
{
struct V_56 * V_68 ;
struct V_40 * V_40 ;
F_40 ( & V_59 . V_64 ) ;
F_12 ( V_8 -> V_23 ) ;
V_68 = V_8 -> V_24 ;
V_40 = V_68 -> V_25 ;
V_68 -> V_25 = NULL ;
if ( V_40 )
F_10 ( V_40 -> V_48 ) ;
F_10 ( V_40 ) ;
F_46 ( & V_68 -> V_58 ) ;
if ( F_36 ( & V_59 . V_65 ) ) {
T_5 V_49 ;
V_49 = sizeof( struct V_25 ) * V_59 . V_62 ;
F_4 ( NULL , V_69 ) ;
F_44 ( ( unsigned long ) V_59 . V_60 , F_43 ( V_49 ) ) ;
V_59 . V_60 = NULL ;
}
F_16 ( V_8 -> V_23 ) ;
F_41 ( & V_59 . V_64 ) ;
}
static int F_47 ( struct V_7 * V_8 , T_2 V_9 )
{
T_6 V_70 ;
struct V_40 * V_40 ;
unsigned long V_53 ;
F_31 ( V_8 -> V_23 , V_53 ) ;
if ( ! V_8 -> V_24 -> V_25 ) {
F_32 ( V_8 -> V_23 , V_53 ) ;
return - V_71 ;
}
V_40 = V_8 -> V_24 -> V_25 ;
V_70 = V_9 ? (struct V_25 * ) V_40 -> V_39 - V_59 . V_60 : 0 ;
F_32 ( V_8 -> V_23 , V_53 ) ;
return F_11 ( V_8 , V_9 , 0 , V_70 ) ;
}
static T_1 F_48 ( struct V_7 * V_8 , int V_72 )
{
struct V_25 * V_25 ;
T_2 V_73 ;
int V_3 ;
unsigned long V_53 ;
V_3 = F_30 ( V_8 ) ;
if ( V_3 < 0 )
return 0 ;
F_31 ( V_8 -> V_23 , V_53 ) ;
if ( ! V_8 -> V_24 -> V_25 ) {
V_3 = 0 ;
goto V_26;
}
V_25 = ( (struct V_40 * ) V_8 -> V_24 -> V_25 ) -> V_48 ;
switch ( V_72 ) {
case V_74 :
V_3 = V_25 -> V_75 ;
goto V_26;
case V_76 :
V_3 = V_25 -> V_77 ;
goto V_26;
case V_78 :
V_73 = V_25 -> V_79 ;
break;
case V_80 :
V_73 = V_25 -> V_81 ;
break;
case V_82 :
V_73 = V_25 -> V_83 ;
break;
case V_84 :
V_73 = V_25 -> V_85 ;
break;
case V_86 :
V_73 = V_25 -> V_87 ;
break;
default:
V_3 = 0 ;
goto V_26;
}
V_3 = F_2 ( V_73 , V_25 -> V_77 ) ;
V_26:
F_32 ( V_8 -> V_23 , V_53 ) ;
return V_3 ;
}
static int F_49 ( struct V_7 * V_8 , struct V_88 * V_61 )
{
struct V_25 * V_25 ;
struct V_40 * V_40 ;
T_1 time ;
unsigned long V_53 ;
int V_3 ;
V_3 = F_30 ( V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
F_31 ( V_8 -> V_23 , V_53 ) ;
V_40 = V_8 -> V_24 -> V_25 ;
if ( ! V_40 ) {
V_3 = - V_19 ;
goto V_26;
}
if ( V_40 -> V_50 == 0 ) {
V_3 = - V_89 ;
goto V_26;
}
V_25 = V_40 -> V_48 ;
time = V_40 -> V_50 - V_8 -> V_24 -> V_55 ;
memset ( V_61 , 0 , sizeof( struct V_88 ) ) ;
V_61 -> V_49 = F_50 ( struct V_88 , V_90 ) ;
V_61 -> V_91 = ( time * 1000 ) >> 12 ;
V_61 -> V_75 = V_25 -> V_75 ;
V_61 -> V_77 = V_25 -> V_77 ;
V_61 -> V_79 = F_1 ( V_25 -> V_79 ) ;
V_61 -> V_81 = F_1 ( V_25 -> V_81 ) ;
V_61 -> V_83 =
F_1 ( V_25 -> V_83 ) ;
V_61 -> V_85
= F_1 ( V_25 -> V_85 ) ;
V_61 -> V_87
= F_1 ( V_25 -> V_87 ) ;
V_3 = 0 ;
V_26:
F_32 ( V_8 -> V_23 , V_53 ) ;
return V_3 ;
}
static void F_51 ( struct V_7 * V_8 )
{
F_34 ( V_8 ) ;
}
static int F_52 ( struct V_7 * V_8 )
{
int V_92 ;
F_12 ( V_8 -> V_23 ) ;
V_92 = ! ! V_8 -> V_24 -> V_25 ;
F_16 ( V_8 -> V_23 ) ;
return V_92 ;
}
static int F_53 ( struct V_7 * V_8 )
{
struct V_40 * V_40 ;
struct V_93 * V_93 ;
int V_3 = - V_28 ;
V_93 = F_54 ( V_94 , V_63 ) ;
if ( ! V_93 )
return V_3 ;
V_40 = F_13 ( sizeof( * V_40 ) , V_63 ) ;
if ( ! V_40 )
goto V_95;
V_40 -> V_48 = F_13 ( sizeof( struct V_93 ) , V_63 ) ;
if ( ! V_40 -> V_48 )
goto V_95;
V_40 -> V_49 = sizeof( * V_93 ) ;
V_40 -> V_39 = V_93 ;
F_40 ( & V_59 . V_64 ) ;
F_12 ( V_8 -> V_23 ) ;
if ( V_8 -> V_24 -> V_25 )
goto V_96;
V_8 -> V_24 -> V_25 = V_40 ;
if ( F_36 ( & V_59 . V_65 ) )
F_4 ( NULL , V_67 ) ;
F_38 ( & V_8 -> V_24 -> V_58 , & V_59 . V_65 ) ;
F_16 ( V_8 -> V_23 ) ;
F_41 ( & V_59 . V_64 ) ;
return 0 ;
V_96:
F_16 ( V_8 -> V_23 ) ;
F_41 ( & V_59 . V_64 ) ;
V_3 = - V_30 ;
V_95:
if ( V_40 )
F_10 ( V_40 -> V_48 ) ;
F_10 ( V_40 ) ;
F_55 ( V_94 , V_93 ) ;
return V_3 ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_40 * V_40 ;
F_40 ( & V_59 . V_64 ) ;
F_12 ( V_8 -> V_23 ) ;
V_40 = V_8 -> V_24 -> V_25 ;
V_8 -> V_24 -> V_25 = NULL ;
if ( V_40 ) {
F_10 ( V_40 -> V_48 ) ;
F_55 ( V_94 , V_40 -> V_39 ) ;
}
F_10 ( V_40 ) ;
F_46 ( & V_8 -> V_24 -> V_58 ) ;
if ( F_36 ( & V_59 . V_65 ) )
F_4 ( NULL , V_69 ) ;
F_16 ( V_8 -> V_23 ) ;
F_41 ( & V_59 . V_64 ) ;
}
static int F_57 ( struct V_7 * V_8 , T_2 V_9 )
{
unsigned long V_17 ;
struct V_40 * V_40 ;
unsigned long V_53 ;
F_31 ( V_8 -> V_23 , V_53 ) ;
if ( ! V_8 -> V_24 -> V_25 ) {
F_32 ( V_8 -> V_23 , V_53 ) ;
return - V_71 ;
}
V_40 = V_8 -> V_24 -> V_25 ;
V_17 = V_9 ? ( unsigned long ) V_40 -> V_39 : 0 ;
F_32 ( V_8 -> V_23 , V_53 ) ;
return F_11 ( V_8 , V_9 , 1 , V_17 ) ;
}
static T_1 F_58 ( struct V_7 * V_8 , int V_72 )
{
struct V_93 * V_25 ;
struct V_40 * V_40 ;
T_2 V_73 ;
int V_3 ;
unsigned long V_53 ;
V_3 = F_30 ( V_8 ) ;
if ( V_3 < 0 )
return 0 ;
F_31 ( V_8 -> V_23 , V_53 ) ;
V_40 = V_8 -> V_24 -> V_25 ;
if ( ! V_40 ) {
V_3 = 0 ;
goto V_26;
}
V_25 = V_40 -> V_48 ;
switch ( V_72 ) {
case V_74 :
V_3 = V_25 -> V_75 ;
goto V_26;
case V_76 :
V_3 = V_25 -> V_77 ;
goto V_26;
case V_78 :
V_73 = V_25 -> V_79 ;
break;
case V_80 :
V_73 = V_25 -> V_81 ;
break;
case V_82 :
V_73 = V_25 -> V_83 ;
break;
case V_84 :
V_73 = V_25 -> V_85 ;
break;
case V_86 :
V_73 = V_25 -> V_87 ;
break;
case V_97 :
V_73 = V_25 -> V_90 ;
break;
case V_98 :
V_73 = V_25 -> V_99 ;
break;
default:
V_3 = 0 ;
goto V_26;
}
V_3 = F_2 ( V_73 , V_25 -> V_77 ) ;
V_26:
F_32 ( V_8 -> V_23 , V_53 ) ;
return V_3 ;
}
static int F_59 ( struct V_7 * V_8 , struct V_88 * V_61 )
{
struct V_93 * V_25 ;
struct V_40 * V_40 ;
T_1 time ;
unsigned long V_53 ;
int V_3 ;
V_3 = F_30 ( V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
F_31 ( V_8 -> V_23 , V_53 ) ;
V_40 = V_8 -> V_24 -> V_25 ;
if ( ! V_40 ) {
V_3 = - V_19 ;
goto V_26;
}
if ( V_40 -> V_50 == 0 ) {
V_3 = - V_89 ;
goto V_26;
}
time = V_40 -> V_50 - V_8 -> V_24 -> V_55 ;
memset ( V_61 , 0 , sizeof( struct V_88 ) ) ;
V_61 -> V_49 = F_50 ( struct V_88 , V_90 ) ;
V_61 -> V_91 = ( time * 1000 ) >> 12 ;
V_25 = V_40 -> V_48 ;
V_61 -> V_75 = V_25 -> V_75 ;
V_61 -> V_77 = V_25 -> V_77 ;
V_61 -> V_79 = F_1 ( V_25 -> V_79 ) ;
V_61 -> V_81 = F_1 ( V_25 -> V_81 ) ;
V_61 -> V_83 =
F_1 ( V_25 -> V_83 ) ;
V_61 -> V_85
= F_1 ( V_25 -> V_85 ) ;
V_61 -> V_87
= F_1 ( V_25 -> V_87 ) ;
V_61 -> V_90 = F_1 ( V_25 -> V_90 ) ;
V_61 -> V_99
= F_1 ( V_25 -> V_99 ) ;
V_3 = 0 ;
V_26:
F_32 ( V_8 -> V_23 , V_53 ) ;
return V_3 ;
}
static void F_60 ( struct V_7 * V_8 )
{
F_34 ( V_8 ) ;
}
static T_5 F_61 ( struct V_100 * V_14 , char * V_101 , enum V_102 V_103 )
{
return sprintf ( V_101 , L_3 ,
( unsigned long long ) F_62 ( F_63 ( V_14 ) , V_103 ) ) ;
}
static T_5 F_64 ( struct V_100 * V_14 ,
struct V_104 * V_105 ,
char * V_101 )
{
struct V_7 * V_8 ;
long V_106 ;
unsigned long V_2 ;
struct V_40 * V_40 ;
V_8 = F_63 ( V_14 ) ;
V_2 = F_62 ( V_8 , V_76 ) ;
F_12 ( V_8 -> V_23 ) ;
V_40 = V_8 -> V_24 -> V_25 ;
if ( V_2 ) {
V_106 = V_40 -> V_50 -
V_8 -> V_24 -> V_55 ;
V_106 = ( V_106 * 1000 ) >> 12 ;
V_106 /= V_2 ;
} else
V_106 = - 1 ;
F_16 ( V_8 -> V_23 ) ;
return sprintf ( V_101 , L_4 , V_106 ) ;
}
static T_5 F_65 ( struct V_100 * V_14 ,
struct V_104 * V_105 ,
char * V_101 )
{
struct V_88 V_61 ;
T_1 V_107 ;
unsigned long V_108 , V_109 ;
int V_3 ;
V_3 = F_66 ( F_63 ( V_14 ) , & V_61 ) ;
if ( V_3 == - V_89 || V_3 == - V_19 )
return sprintf ( V_101 , L_5 ) ;
else if ( V_3 )
return V_3 ;
V_107 = V_61 . V_79 +
V_61 . V_81 +
V_61 . V_83 ;
while ( - 1ul < ( V_61 . V_91 | V_107 ) ) {
V_107 >>= 8 ;
V_61 . V_91 >>= 8 ;
}
V_108 = ( unsigned long ) V_61 . V_91 / 1000 ;
V_109 = ( unsigned long ) V_107 / V_108 ;
return sprintf ( V_101 , L_6 , V_109 / 10 , V_109 - ( V_109 / 10 ) * 10 ) ;
}
static T_5 F_67 ( struct V_100 * V_14 ,
struct V_104 * V_105 ,
char * V_101 )
{
struct V_7 * V_8 = F_63 ( V_14 ) ;
return sprintf ( V_101 , L_7 , F_52 ( V_8 ) ) ;
}
static T_5 F_68 ( struct V_100 * V_14 ,
struct V_104 * V_105 , const char * V_101 ,
T_7 V_110 )
{
struct V_7 * V_8 = F_63 ( V_14 ) ;
unsigned long V_73 ;
int V_3 ;
V_3 = F_69 ( V_101 , 16 , & V_73 ) ;
if ( V_3 )
return V_3 ;
switch ( V_73 ) {
case 0 :
V_3 = F_70 ( V_8 ) ;
break;
case 1 :
V_3 = F_71 ( V_8 ) ;
break;
default:
V_3 = - V_71 ;
}
return V_3 ? V_3 : V_110 ;
}
int F_72 ( struct V_7 * V_8 , int V_111 )
{
return V_112 -> V_113 ( V_8 , V_111 ? 2 : 0 ) ;
}
int F_71 ( struct V_7 * V_8 )
{
int V_3 = 0 ;
F_73 ( & V_8 -> V_14 ) ;
if ( F_52 ( V_8 ) ) {
V_112 -> V_114 ( V_8 ) ;
goto V_96;
}
F_74 ( & V_8 -> V_14 ) ;
V_3 = V_112 -> V_115 ( V_8 ) ;
if ( V_3 )
goto V_26;
V_112 -> V_114 ( V_8 ) ;
V_3 = F_75 ( & V_8 -> V_14 . V_116 , V_112 -> V_117 ) ;
if ( V_3 ) {
V_112 -> free ( V_8 ) ;
goto V_26;
}
V_3 = V_112 -> V_113 ( V_8 , 2 ) ;
if ( V_3 ) {
F_76 ( & V_8 -> V_14 . V_116 , V_112 -> V_117 ) ;
V_112 -> free ( V_8 ) ;
}
V_26:
if ( V_3 )
F_77 ( & V_8 -> V_14 ) ;
V_96:
F_78 ( & V_8 -> V_14 ) ;
return V_3 ;
}
int F_79 ( struct V_7 * V_8 )
{
int V_3 ;
V_3 = V_112 -> V_113 ( V_8 , 0 ) ;
if ( V_3 )
return V_3 ;
F_76 ( & V_8 -> V_14 . V_116 , V_112 -> V_117 ) ;
V_112 -> free ( V_8 ) ;
F_77 ( & V_8 -> V_14 ) ;
return V_3 ;
}
int F_70 ( struct V_7 * V_8 )
{
int V_3 ;
F_73 ( & V_8 -> V_14 ) ;
V_3 = F_79 ( V_8 ) ;
F_78 ( & V_8 -> V_14 ) ;
return V_3 ;
}
T_1 F_62 ( struct V_7 * V_8 , int V_72 )
{
return V_112 -> V_118 ( V_8 , V_72 ) ;
}
int F_66 ( struct V_7 * V_8 , struct V_88 * V_61 )
{
return V_112 -> V_119 ( V_8 , V_61 ) ;
}
int F_80 ( struct V_7 * V_8 )
{
V_112 -> V_114 ( V_8 ) ;
return V_112 -> V_113 ( V_8 , 2 ) ;
}
void F_81 ( void )
{
F_40 ( & V_59 . V_64 ) ;
if ( ! F_36 ( & V_59 . V_65 ) )
F_4 ( V_59 . V_60 , V_67 ) ;
F_41 ( & V_59 . V_64 ) ;
}
static int T_8 F_82 ( void )
{
V_94 = F_83 ( L_8 , sizeof( struct V_93 ) ,
F_84 ( struct V_93 ) , 0 , NULL ) ;
return V_94 ? 0 : - V_28 ;
}
static int T_8 F_85 ( void )
{
char * V_120 ;
char * V_121 ;
int V_3 ;
if ( V_122 == V_123 ) {
if ( ! V_124 . V_125 ) {
V_122 = V_126 ;
} else {
V_122 = V_127 ;
}
V_121 = L_9 ;
} else {
V_121 = L_10 ;
}
switch ( V_122 ) {
case V_126 :
V_120 = L_11 ;
V_112 = & V_128 ;
break;
case V_127 :
V_120 = L_12 ;
V_112 = & V_129 ;
V_3 = F_82 () ;
if ( V_3 )
return V_3 ;
break;
default:
return - V_71 ;
}
F_86 ( L_13
L_14 , V_120 , V_121 ) ;
return 0 ;
}
