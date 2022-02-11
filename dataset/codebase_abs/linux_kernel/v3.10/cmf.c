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
T_4 = V_5 ? 2 : 0 ;
asm("schm" : : "d" (__gpr2), "d" (__gpr1) );
}
static int F_5 ( struct V_7 * V_8 , T_2 V_9 , int V_10 ,
unsigned long V_11 )
{
struct V_12 * V_13 ;
V_13 = F_6 ( V_8 -> V_14 . V_15 ) ;
V_13 -> V_16 . V_9 = V_9 ;
V_13 -> V_16 . V_10 = V_10 ;
if ( V_10 )
V_13 -> V_16 . V_17 = V_11 ;
else
V_13 -> V_16 . V_18 = V_11 ;
return F_7 ( V_13 ) ;
}
static void F_8 ( struct V_19 * V_19 )
{
struct V_20 * V_21 ;
V_21 = F_9 ( V_19 , struct V_20 , V_19 ) ;
F_10 ( V_21 ) ;
}
static int F_11 ( struct V_7 * V_8 , T_2 V_9 ,
int V_10 , unsigned long V_11 )
{
struct V_20 * V_21 ;
int V_3 ;
F_12 ( V_8 -> V_22 ) ;
if ( ! V_8 -> V_23 -> V_24 ) {
V_3 = - V_25 ;
goto V_26;
}
V_21 = F_13 ( sizeof( struct V_20 ) , V_27 ) ;
if ( ! V_21 ) {
V_3 = - V_28 ;
goto V_26;
}
F_14 ( & V_21 -> V_29 ) ;
F_15 ( & V_21 -> V_19 ) ;
V_21 -> V_9 = V_9 ;
V_21 -> V_10 = V_10 ;
V_21 -> V_11 = V_11 ;
V_3 = F_5 ( V_8 , V_9 , V_10 , V_11 ) ;
if ( V_3 != - V_30 )
goto V_31;
if ( V_8 -> V_23 -> V_32 != V_33 ) {
V_3 = - V_30 ;
goto V_31;
}
V_8 -> V_23 -> V_32 = V_34 ;
V_21 -> V_3 = V_35 ;
V_8 -> V_23 -> V_36 = V_21 ;
F_16 ( V_8 -> V_22 ) ;
if ( F_17 ( V_21 -> V_29 ,
V_21 -> V_3 != V_35 ) ) {
F_12 ( V_8 -> V_22 ) ;
if ( V_21 -> V_3 == V_35 ) {
V_21 -> V_3 = - V_37 ;
if ( V_8 -> V_23 -> V_32 == V_34 )
V_8 -> V_23 -> V_32 = V_33 ;
}
F_16 ( V_8 -> V_22 ) ;
}
F_12 ( V_8 -> V_22 ) ;
V_8 -> V_23 -> V_36 = NULL ;
V_3 = V_21 -> V_3 ;
V_31:
F_18 ( & V_21 -> V_19 , F_8 ) ;
V_26:
F_16 ( V_8 -> V_22 ) ;
return V_3 ;
}
void F_19 ( struct V_7 * V_8 )
{
struct V_20 * V_21 ;
V_21 = V_8 -> V_23 -> V_36 ;
if ( ! V_21 ) {
F_20 ( 1 ) ;
return;
}
F_21 ( & V_21 -> V_19 ) ;
V_21 -> V_3 = F_5 ( V_8 , V_21 -> V_9 , V_21 -> V_10 ,
V_21 -> V_11 ) ;
F_22 ( & V_21 -> V_29 ) ;
F_18 ( & V_21 -> V_19 , F_8 ) ;
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
void * V_38 ;
void * V_39 ;
struct V_40 * V_40 ;
V_13 = F_6 ( V_8 -> V_14 . V_15 ) ;
if ( F_24 ( V_13 ) )
return - V_25 ;
if ( F_25 ( & V_13 -> V_41 . V_42 ) & V_43 ) {
if ( ( ! ( F_26 ( & V_13 -> V_41 . V_42 ) & V_44 ) ) &&
( F_26 ( & V_13 -> V_41 . V_42 ) &
( V_45 | V_46 ) ) &&
( ! ( F_27 ( & V_13 -> V_41 . V_42 ) & V_47 ) ) )
return - V_30 ;
}
V_40 = V_8 -> V_23 -> V_24 ;
V_39 = V_48 -> V_49 ( V_40 -> V_39 ) ;
if ( ! memcmp ( V_40 -> V_50 , V_39 , V_40 -> V_51 ) )
return 0 ;
V_38 = F_13 ( V_40 -> V_51 , V_27 ) ;
if ( ! V_38 )
return - V_28 ;
do {
memcpy ( V_40 -> V_50 , V_39 , V_40 -> V_51 ) ;
memcpy ( V_38 , V_39 , V_40 -> V_51 ) ;
} while ( memcmp ( V_40 -> V_50 , V_38 , V_40 -> V_51 ) );
V_40 -> V_52 = F_28 () ;
F_10 ( V_38 ) ;
return 0 ;
}
static void F_29 ( struct V_19 * V_19 )
{
struct V_53 * V_54 ;
V_54 = F_9 ( V_19 , struct V_53 , V_19 ) ;
F_10 ( V_54 ) ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_53 * V_54 ;
int V_3 ;
unsigned long V_55 ;
F_31 ( V_8 -> V_22 , V_55 ) ;
if ( ! V_8 -> V_23 -> V_24 ) {
V_3 = - V_25 ;
goto V_26;
}
V_54 = F_13 ( sizeof( struct V_53 ) , V_27 ) ;
if ( ! V_54 ) {
V_3 = - V_28 ;
goto V_26;
}
F_14 ( & V_54 -> V_29 ) ;
F_15 ( & V_54 -> V_19 ) ;
V_3 = F_23 ( V_8 ) ;
if ( V_3 != - V_30 )
goto V_31;
if ( V_8 -> V_23 -> V_32 != V_33 ) {
V_3 = - V_30 ;
goto V_31;
}
V_8 -> V_23 -> V_32 = V_56 ;
V_54 -> V_3 = V_35 ;
V_8 -> V_23 -> V_36 = V_54 ;
F_32 ( V_8 -> V_22 , V_55 ) ;
if ( F_17 ( V_54 -> V_29 ,
V_54 -> V_3 != V_35 ) ) {
F_31 ( V_8 -> V_22 , V_55 ) ;
if ( V_54 -> V_3 == V_35 ) {
V_54 -> V_3 = - V_37 ;
if ( V_8 -> V_23 -> V_32 == V_56 )
V_8 -> V_23 -> V_32 = V_33 ;
}
F_32 ( V_8 -> V_22 , V_55 ) ;
}
F_31 ( V_8 -> V_22 , V_55 ) ;
V_8 -> V_23 -> V_36 = NULL ;
V_3 = V_54 -> V_3 ;
V_31:
F_18 ( & V_54 -> V_19 , F_29 ) ;
V_26:
F_32 ( V_8 -> V_22 , V_55 ) ;
return V_3 ;
}
void F_33 ( struct V_7 * V_8 )
{
struct V_53 * V_54 ;
V_54 = V_8 -> V_23 -> V_36 ;
if ( ! V_54 ) {
F_20 ( 1 ) ;
return;
}
F_21 ( & V_54 -> V_19 ) ;
V_54 -> V_3 = F_23 ( V_8 ) ;
F_22 ( & V_54 -> V_29 ) ;
F_18 ( & V_54 -> V_19 , F_29 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
struct V_40 * V_40 ;
F_12 ( V_8 -> V_22 ) ;
V_40 = V_8 -> V_23 -> V_24 ;
if ( V_40 ) {
memset ( V_40 -> V_50 , 0 , V_40 -> V_51 ) ;
memset ( V_48 -> V_49 ( V_40 -> V_39 ) , 0 , V_40 -> V_51 ) ;
V_40 -> V_52 = 0 ;
}
V_8 -> V_23 -> V_57 = F_28 () ;
F_16 ( V_8 -> V_22 ) ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_40 * V_40 )
{
struct V_24 * V_24 ;
struct V_58 * V_59 ;
int V_3 ;
F_12 ( V_8 -> V_22 ) ;
if ( ! F_36 ( & V_8 -> V_23 -> V_60 ) ) {
V_3 = - V_30 ;
goto V_26;
}
V_24 = V_61 . V_62 ;
F_37 (node, &cmb_area.list, cmb_list) {
struct V_40 * V_63 ;
V_63 = V_59 -> V_24 ;
if ( (struct V_24 * ) V_63 -> V_39 > V_24 )
break;
V_24 ++ ;
}
if ( V_24 - V_61 . V_62 >= V_61 . V_64 ) {
V_3 = - V_28 ;
goto V_26;
}
F_38 ( & V_8 -> V_23 -> V_60 , & V_59 -> V_60 ) ;
V_40 -> V_39 = V_24 ;
V_8 -> V_23 -> V_24 = V_40 ;
V_3 = 0 ;
V_26:
F_16 ( V_8 -> V_22 ) ;
return V_3 ;
}
static int F_39 ( struct V_7 * V_8 )
{
int V_3 ;
struct V_24 * V_62 ;
T_5 V_51 ;
struct V_40 * V_40 ;
V_40 = F_13 ( sizeof( struct V_40 ) , V_65 ) ;
if ( ! V_40 )
return - V_28 ;
V_40 -> V_50 = F_13 ( sizeof( struct V_24 ) , V_65 ) ;
if ( ! V_40 -> V_50 ) {
F_10 ( V_40 ) ;
return - V_28 ;
}
V_40 -> V_51 = sizeof( struct V_24 ) ;
F_40 ( & V_61 . V_66 ) ;
if ( ! V_61 . V_62 ) {
V_51 = sizeof( struct V_24 ) * V_61 . V_64 ;
F_20 ( ! F_36 ( & V_61 . V_67 ) ) ;
F_41 ( & V_61 . V_66 ) ;
V_62 = ( void * ) F_42 ( V_65 | V_68 ,
F_43 ( V_51 ) ) ;
F_40 ( & V_61 . V_66 ) ;
if ( V_61 . V_62 ) {
F_44 ( ( unsigned long ) V_62 , F_43 ( V_51 ) ) ;
} else if ( ! V_62 ) {
V_3 = - V_28 ;
goto V_26;
} else {
memset ( V_62 , 0 , V_51 ) ;
V_61 . V_62 = V_62 ;
F_4 ( V_61 . V_62 , 1 ) ;
}
}
V_3 = F_35 ( V_8 , V_40 ) ;
V_26:
F_41 ( & V_61 . V_66 ) ;
if ( V_3 ) {
F_10 ( V_40 -> V_50 ) ;
F_10 ( V_40 ) ;
}
return V_3 ;
}
static void F_45 ( struct V_7 * V_8 )
{
struct V_58 * V_69 ;
struct V_40 * V_40 ;
F_40 ( & V_61 . V_66 ) ;
F_12 ( V_8 -> V_22 ) ;
V_69 = V_8 -> V_23 ;
if ( F_36 ( & V_69 -> V_60 ) ) {
goto V_26;
}
V_40 = V_69 -> V_24 ;
V_69 -> V_24 = NULL ;
if ( V_40 )
F_10 ( V_40 -> V_50 ) ;
F_10 ( V_40 ) ;
F_46 ( & V_69 -> V_60 ) ;
if ( F_36 ( & V_61 . V_67 ) ) {
T_5 V_51 ;
V_51 = sizeof( struct V_24 ) * V_61 . V_64 ;
F_4 ( NULL , 0 ) ;
F_44 ( ( unsigned long ) V_61 . V_62 , F_43 ( V_51 ) ) ;
V_61 . V_62 = NULL ;
}
V_26:
F_16 ( V_8 -> V_22 ) ;
F_41 ( & V_61 . V_66 ) ;
}
static int F_47 ( struct V_7 * V_8 , T_2 V_9 )
{
T_6 V_70 ;
struct V_40 * V_40 ;
unsigned long V_55 ;
F_31 ( V_8 -> V_22 , V_55 ) ;
if ( ! V_8 -> V_23 -> V_24 ) {
F_32 ( V_8 -> V_22 , V_55 ) ;
return - V_71 ;
}
V_40 = V_8 -> V_23 -> V_24 ;
V_70 = V_9 ? (struct V_24 * ) V_40 -> V_39 - V_61 . V_62 : 0 ;
F_32 ( V_8 -> V_22 , V_55 ) ;
return F_11 ( V_8 , V_9 , 0 , V_70 ) ;
}
static T_1 F_48 ( struct V_7 * V_8 , int V_72 )
{
struct V_24 * V_24 ;
T_2 V_73 ;
int V_3 ;
unsigned long V_55 ;
V_3 = F_30 ( V_8 ) ;
if ( V_3 < 0 )
return 0 ;
F_31 ( V_8 -> V_22 , V_55 ) ;
if ( ! V_8 -> V_23 -> V_24 ) {
V_3 = 0 ;
goto V_26;
}
V_24 = ( (struct V_40 * ) V_8 -> V_23 -> V_24 ) -> V_50 ;
switch ( V_72 ) {
case V_74 :
V_3 = V_24 -> V_75 ;
goto V_26;
case V_76 :
V_3 = V_24 -> V_77 ;
goto V_26;
case V_78 :
V_73 = V_24 -> V_79 ;
break;
case V_80 :
V_73 = V_24 -> V_81 ;
break;
case V_82 :
V_73 = V_24 -> V_83 ;
break;
case V_84 :
V_73 = V_24 -> V_85 ;
break;
case V_86 :
V_73 = V_24 -> V_87 ;
break;
default:
V_3 = 0 ;
goto V_26;
}
V_3 = F_2 ( V_73 , V_24 -> V_77 ) ;
V_26:
F_32 ( V_8 -> V_22 , V_55 ) ;
return V_3 ;
}
static int F_49 ( struct V_7 * V_8 , struct V_88 * V_63 )
{
struct V_24 * V_24 ;
struct V_40 * V_40 ;
T_1 time ;
unsigned long V_55 ;
int V_3 ;
V_3 = F_30 ( V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
F_31 ( V_8 -> V_22 , V_55 ) ;
V_40 = V_8 -> V_23 -> V_24 ;
if ( ! V_40 ) {
V_3 = - V_25 ;
goto V_26;
}
if ( V_40 -> V_52 == 0 ) {
V_3 = - V_89 ;
goto V_26;
}
V_24 = V_40 -> V_50 ;
time = V_40 -> V_52 - V_8 -> V_23 -> V_57 ;
memset ( V_63 , 0 , sizeof( struct V_88 ) ) ;
V_63 -> V_51 = F_50 ( struct V_88 , V_90 ) ;
V_63 -> V_91 = ( time * 1000 ) >> 12 ;
V_63 -> V_75 = V_24 -> V_75 ;
V_63 -> V_77 = V_24 -> V_77 ;
V_63 -> V_79 = F_1 ( V_24 -> V_79 ) ;
V_63 -> V_81 = F_1 ( V_24 -> V_81 ) ;
V_63 -> V_83 =
F_1 ( V_24 -> V_83 ) ;
V_63 -> V_85
= F_1 ( V_24 -> V_85 ) ;
V_63 -> V_87
= F_1 ( V_24 -> V_87 ) ;
V_3 = 0 ;
V_26:
F_32 ( V_8 -> V_22 , V_55 ) ;
return V_3 ;
}
static void F_51 ( struct V_7 * V_8 )
{
F_34 ( V_8 ) ;
}
static void * F_52 ( void * V_4 )
{
return V_4 ;
}
static inline struct V_92 * F_53 ( struct V_92 * V_93 )
{
unsigned long V_94 ;
V_94 = ( ( unsigned long ) V_93 + sizeof ( struct V_92 ) - sizeof( long ) ) &
~ ( sizeof ( struct V_92 ) - sizeof( long ) ) ;
return (struct V_92 * ) V_94 ;
}
static int F_54 ( struct V_7 * V_8 )
{
struct V_92 * V_92 ;
struct V_40 * V_40 ;
int V_3 ;
V_92 = F_13 ( sizeof ( * V_92 ) * 2 , V_65 ) ;
if ( ! V_92 )
return - V_28 ;
V_40 = F_13 ( sizeof( struct V_40 ) , V_65 ) ;
if ( ! V_40 ) {
V_3 = - V_28 ;
goto V_95;
}
V_40 -> V_50 = F_13 ( sizeof( struct V_92 ) , V_65 ) ;
if ( ! V_40 -> V_50 ) {
V_3 = - V_28 ;
goto V_95;
}
V_40 -> V_51 = sizeof( struct V_92 ) ;
F_12 ( V_8 -> V_22 ) ;
if ( V_8 -> V_23 -> V_24 ) {
F_16 ( V_8 -> V_22 ) ;
V_3 = - V_30 ;
goto V_95;
}
V_40 -> V_39 = V_92 ;
V_8 -> V_23 -> V_24 = V_40 ;
F_16 ( V_8 -> V_22 ) ;
F_40 ( & V_61 . V_66 ) ;
if ( F_36 ( & V_61 . V_67 ) )
F_4 ( NULL , 1 ) ;
F_38 ( & V_8 -> V_23 -> V_60 , & V_61 . V_67 ) ;
F_41 ( & V_61 . V_66 ) ;
return 0 ;
V_95:
if ( V_40 )
F_10 ( V_40 -> V_50 ) ;
F_10 ( V_40 ) ;
F_10 ( V_92 ) ;
return V_3 ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_40 * V_40 ;
F_12 ( V_8 -> V_22 ) ;
V_40 = V_8 -> V_23 -> V_24 ;
V_8 -> V_23 -> V_24 = NULL ;
if ( V_40 )
F_10 ( V_40 -> V_50 ) ;
F_10 ( V_40 ) ;
F_16 ( V_8 -> V_22 ) ;
F_40 ( & V_61 . V_66 ) ;
F_46 ( & V_8 -> V_23 -> V_60 ) ;
if ( F_36 ( & V_61 . V_67 ) )
F_4 ( NULL , 0 ) ;
F_41 ( & V_61 . V_66 ) ;
}
static int F_56 ( struct V_7 * V_8 , T_2 V_9 )
{
unsigned long V_17 ;
struct V_40 * V_40 ;
unsigned long V_55 ;
F_31 ( V_8 -> V_22 , V_55 ) ;
if ( ! V_8 -> V_23 -> V_24 ) {
F_32 ( V_8 -> V_22 , V_55 ) ;
return - V_71 ;
}
V_40 = V_8 -> V_23 -> V_24 ;
V_17 = V_9 ? ( unsigned long ) F_53 ( V_40 -> V_39 ) : 0 ;
F_32 ( V_8 -> V_22 , V_55 ) ;
return F_11 ( V_8 , V_9 , 1 , V_17 ) ;
}
static T_1 F_57 ( struct V_7 * V_8 , int V_72 )
{
struct V_92 * V_24 ;
struct V_40 * V_40 ;
T_2 V_73 ;
int V_3 ;
unsigned long V_55 ;
V_3 = F_30 ( V_8 ) ;
if ( V_3 < 0 )
return 0 ;
F_31 ( V_8 -> V_22 , V_55 ) ;
V_40 = V_8 -> V_23 -> V_24 ;
if ( ! V_40 ) {
V_3 = 0 ;
goto V_26;
}
V_24 = V_40 -> V_50 ;
switch ( V_72 ) {
case V_74 :
V_3 = V_24 -> V_75 ;
goto V_26;
case V_76 :
V_3 = V_24 -> V_77 ;
goto V_26;
case V_78 :
V_73 = V_24 -> V_79 ;
break;
case V_80 :
V_73 = V_24 -> V_81 ;
break;
case V_82 :
V_73 = V_24 -> V_83 ;
break;
case V_84 :
V_73 = V_24 -> V_85 ;
break;
case V_86 :
V_73 = V_24 -> V_87 ;
break;
case V_96 :
V_73 = V_24 -> V_90 ;
break;
case V_97 :
V_73 = V_24 -> V_98 ;
break;
default:
V_3 = 0 ;
goto V_26;
}
V_3 = F_2 ( V_73 , V_24 -> V_77 ) ;
V_26:
F_32 ( V_8 -> V_22 , V_55 ) ;
return V_3 ;
}
static int F_58 ( struct V_7 * V_8 , struct V_88 * V_63 )
{
struct V_92 * V_24 ;
struct V_40 * V_40 ;
T_1 time ;
unsigned long V_55 ;
int V_3 ;
V_3 = F_30 ( V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
F_31 ( V_8 -> V_22 , V_55 ) ;
V_40 = V_8 -> V_23 -> V_24 ;
if ( ! V_40 ) {
V_3 = - V_25 ;
goto V_26;
}
if ( V_40 -> V_52 == 0 ) {
V_3 = - V_89 ;
goto V_26;
}
time = V_40 -> V_52 - V_8 -> V_23 -> V_57 ;
memset ( V_63 , 0 , sizeof( struct V_88 ) ) ;
V_63 -> V_51 = F_50 ( struct V_88 , V_90 ) ;
V_63 -> V_91 = ( time * 1000 ) >> 12 ;
V_24 = V_40 -> V_50 ;
V_63 -> V_75 = V_24 -> V_75 ;
V_63 -> V_77 = V_24 -> V_77 ;
V_63 -> V_79 = F_1 ( V_24 -> V_79 ) ;
V_63 -> V_81 = F_1 ( V_24 -> V_81 ) ;
V_63 -> V_83 =
F_1 ( V_24 -> V_83 ) ;
V_63 -> V_85
= F_1 ( V_24 -> V_85 ) ;
V_63 -> V_87
= F_1 ( V_24 -> V_87 ) ;
V_63 -> V_90 = F_1 ( V_24 -> V_90 ) ;
V_63 -> V_98
= F_1 ( V_24 -> V_98 ) ;
V_3 = 0 ;
V_26:
F_32 ( V_8 -> V_22 , V_55 ) ;
return V_3 ;
}
static void F_59 ( struct V_7 * V_8 )
{
F_34 ( V_8 ) ;
}
static void * F_60 ( void * V_4 )
{
return F_53 ( V_4 ) ;
}
static T_5 F_61 ( struct V_99 * V_14 , char * V_100 , enum V_101 V_102 )
{
return sprintf ( V_100 , L_3 ,
( unsigned long long ) F_62 ( F_63 ( V_14 ) , V_102 ) ) ;
}
static T_5 F_64 ( struct V_99 * V_14 ,
struct V_103 * V_104 ,
char * V_100 )
{
struct V_7 * V_8 ;
long V_105 ;
unsigned long V_2 ;
struct V_40 * V_40 ;
V_8 = F_63 ( V_14 ) ;
V_2 = F_62 ( V_8 , V_76 ) ;
F_12 ( V_8 -> V_22 ) ;
V_40 = V_8 -> V_23 -> V_24 ;
if ( V_2 ) {
V_105 = V_40 -> V_52 -
V_8 -> V_23 -> V_57 ;
V_105 = ( V_105 * 1000 ) >> 12 ;
V_105 /= V_2 ;
} else
V_105 = - 1 ;
F_16 ( V_8 -> V_22 ) ;
return sprintf ( V_100 , L_4 , V_105 ) ;
}
static T_5 F_65 ( struct V_99 * V_14 ,
struct V_103 * V_104 ,
char * V_100 )
{
struct V_88 V_63 ;
T_1 V_106 ;
unsigned long V_107 , V_108 ;
int V_3 ;
V_3 = F_66 ( F_63 ( V_14 ) , & V_63 ) ;
if ( V_3 == - V_89 || V_3 == - V_25 )
return sprintf ( V_100 , L_5 ) ;
else if ( V_3 )
return V_3 ;
V_106 = V_63 . V_79 +
V_63 . V_81 +
V_63 . V_83 ;
while ( - 1ul < ( V_63 . V_91 | V_106 ) ) {
V_106 >>= 8 ;
V_63 . V_91 >>= 8 ;
}
V_107 = ( unsigned long ) V_63 . V_91 / 1000 ;
V_108 = ( unsigned long ) V_106 / V_107 ;
return sprintf ( V_100 , L_6 , V_108 / 10 , V_108 - ( V_108 / 10 ) * 10 ) ;
}
static T_5 F_67 ( struct V_99 * V_14 ,
struct V_103 * V_104 ,
char * V_100 )
{
return sprintf ( V_100 , L_7 , F_63 ( V_14 ) -> V_23 -> V_24 ? 1 : 0 ) ;
}
static T_5 F_68 ( struct V_99 * V_14 ,
struct V_103 * V_104 , const char * V_100 ,
T_7 V_93 )
{
struct V_7 * V_8 ;
int V_3 ;
unsigned long V_73 ;
V_3 = F_69 ( V_100 , 16 , & V_73 ) ;
if ( V_3 )
return V_3 ;
V_8 = F_63 ( V_14 ) ;
switch ( V_73 ) {
case 0 :
V_3 = F_70 ( V_8 ) ;
break;
case 1 :
V_3 = F_71 ( V_8 ) ;
break;
}
return V_93 ;
}
int F_72 ( struct V_7 * V_8 , int V_109 )
{
return V_48 -> V_110 ( V_8 , V_109 ? 2 : 0 ) ;
}
int F_71 ( struct V_7 * V_8 )
{
int V_3 ;
V_3 = V_48 -> V_111 ( V_8 ) ;
V_48 -> V_112 ( V_8 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_48 -> V_110 ( V_8 , 2 ) ;
if ( V_3 ) {
V_48 -> free ( V_8 ) ;
return V_3 ;
}
V_3 = F_73 ( & V_8 -> V_14 . V_113 , V_48 -> V_114 ) ;
if ( ! V_3 )
return 0 ;
V_48 -> V_110 ( V_8 , 0 ) ;
V_48 -> free ( V_8 ) ;
return V_3 ;
}
int F_70 ( struct V_7 * V_8 )
{
int V_3 ;
V_3 = V_48 -> V_110 ( V_8 , 0 ) ;
if ( V_3 )
return V_3 ;
V_48 -> free ( V_8 ) ;
F_74 ( & V_8 -> V_14 . V_113 , V_48 -> V_114 ) ;
return V_3 ;
}
T_1 F_62 ( struct V_7 * V_8 , int V_72 )
{
return V_48 -> V_115 ( V_8 , V_72 ) ;
}
int F_66 ( struct V_7 * V_8 , struct V_88 * V_63 )
{
return V_48 -> V_116 ( V_8 , V_63 ) ;
}
int F_75 ( struct V_7 * V_8 )
{
V_48 -> V_112 ( V_8 ) ;
return V_48 -> V_110 ( V_8 , 2 ) ;
}
static int T_8 F_76 ( void )
{
char * V_117 ;
char * V_118 = L_8 ;
if ( V_119 == V_120 ) {
if ( ! V_121 . V_122 ) {
V_119 = V_123 ;
} else {
V_119 = V_124 ;
}
V_118 = L_9 ;
} else {
V_118 = L_8 ;
}
switch ( V_119 ) {
case V_123 :
V_117 = L_10 ;
V_48 = & V_125 ;
break;
case V_124 :
V_117 = L_11 ;
V_48 = & V_126 ;
break;
default:
return 1 ;
}
F_77 ( L_12
L_13 , V_117 , V_118 ) ;
return 0 ;
}
