int F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 , V_3 , NULL ) ;
if ( V_1 == NULL )
return - V_4 ;
return 0 ;
}
void F_3 ( void )
{
if ( V_1 )
F_4 ( V_1 ) ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_2 * V_7 )
{
struct V_8 * V_9 ;
struct V_2 * V_10 ;
F_6 (iter, &res->granted) {
V_10 = F_7 ( V_9 , struct V_2 , V_11 ) ;
if ( ! F_8 ( V_10 -> V_12 . type , V_7 -> V_12 . type ) )
return 0 ;
}
F_6 (iter, &res->converting) {
V_10 = F_7 ( V_9 , struct V_2 , V_11 ) ;
if ( ! F_8 ( V_10 -> V_12 . type , V_7 -> V_12 . type ) )
return 0 ;
if ( ! F_8 ( V_10 -> V_12 . V_13 ,
V_7 -> V_12 . type ) )
return 0 ;
}
return 1 ;
}
static enum V_14 F_9 ( struct V_15 * V_16 ,
struct V_5 * V_6 ,
struct V_2 * V_7 , int V_17 )
{
int V_18 = 0 , V_19 = 0 ;
enum V_14 V_20 = V_21 ;
F_10 ( 0 , L_2 , V_7 -> V_12 . type ) ;
F_11 ( & V_6 -> V_22 ) ;
V_20 = F_12 ( V_6 ) ;
if ( V_20 != V_21 &&
V_7 -> V_12 . V_23 != V_16 -> V_24 ) {
F_13 ( & V_6 -> V_22 ) ;
F_14 ( V_20 ) ;
return V_20 ;
}
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
if ( F_5 ( V_6 , V_7 ) ) {
F_10 ( 0 , L_3 ) ;
V_7 -> V_25 -> V_20 = V_21 ;
V_20 = V_21 ;
F_17 ( V_7 ) ;
F_18 ( & V_7 -> V_11 , & V_6 -> V_26 ) ;
if ( ! F_19 ( V_6 -> V_27 . V_28 ,
V_6 -> V_27 . V_29 ) ) {
V_19 = 1 ;
V_18 = 1 ;
} else {
F_10 ( 0 , L_4
L_5 , V_16 -> V_28 ,
V_7 -> V_12 . V_23 ) ;
}
} else {
if ( V_17 & V_30 ) {
V_20 = V_31 ;
if ( F_19 ( V_6 -> V_27 . V_28 ,
V_6 -> V_27 . V_29 ) ) {
F_10 ( 0 , L_6
L_5 , V_16 -> V_28 ,
V_7 -> V_12 . V_23 ) ;
}
} else {
V_20 = V_21 ;
F_17 ( V_7 ) ;
F_18 ( & V_7 -> V_11 , & V_6 -> V_32 ) ;
V_19 = 1 ;
}
}
F_13 ( & V_6 -> V_22 ) ;
F_20 ( & V_6 -> V_33 ) ;
if ( V_18 )
F_21 ( V_16 , V_7 ) ;
else
F_22 ( V_16 , V_6 ) ;
F_23 ( V_16 , V_6 ) ;
if ( V_19 )
F_24 ( V_16 , V_6 ) ;
return V_20 ;
}
void F_25 ( struct V_5 * V_6 ,
struct V_2 * V_7 )
{
F_26 ( & V_7 -> V_11 ) ;
V_7 -> V_25 -> V_17 &= ~ V_34 ;
}
static enum V_14 F_27 ( struct V_15 * V_16 ,
struct V_5 * V_6 ,
struct V_2 * V_7 , int V_17 )
{
enum V_14 V_20 = V_35 ;
int V_36 = 1 ;
F_10 ( 0 , L_7 ,
V_7 -> V_12 . type , V_6 -> V_27 . V_29 ,
V_6 -> V_27 . V_28 , V_17 ) ;
F_11 ( & V_6 -> V_22 ) ;
F_15 ( V_6 ) ;
if ( V_6 -> V_37 == V_16 -> V_24 ) {
F_13 ( & V_6 -> V_22 ) ;
return V_38 ;
}
V_6 -> V_39 |= V_40 ;
F_17 ( V_7 ) ;
F_18 ( & V_7 -> V_11 , & V_6 -> V_32 ) ;
V_7 -> V_41 = 1 ;
F_13 ( & V_6 -> V_22 ) ;
V_20 = F_28 ( V_16 , V_6 , V_7 , V_17 ) ;
F_11 ( & V_6 -> V_22 ) ;
V_6 -> V_39 &= ~ V_40 ;
V_7 -> V_41 = 0 ;
if ( V_20 != V_21 ) {
if ( V_20 == V_38 &&
F_19 ( V_6 -> V_27 . V_28 ,
V_6 -> V_27 . V_29 ) ) {
F_10 ( 0 , L_8
L_9 ,
V_16 -> V_28 , V_6 -> V_37 ) ;
} else if ( V_20 != V_31 ) {
V_36 = 0 ;
F_14 ( V_20 ) ;
}
F_25 ( V_6 , V_7 ) ;
F_29 ( V_7 ) ;
} else if ( F_19 ( V_6 -> V_27 . V_28 ,
V_6 -> V_27 . V_29 ) ) {
F_10 ( 0 , L_10
L_11 ,
V_16 -> V_28 , V_16 -> V_24 , V_6 -> V_37 ) ;
F_30 ( & V_7 -> V_11 , & V_6 -> V_26 ) ;
}
F_13 ( & V_6 -> V_22 ) ;
if ( V_36 )
F_23 ( V_16 , V_6 ) ;
F_20 ( & V_6 -> V_33 ) ;
return V_20 ;
}
static enum V_14 F_28 ( struct V_15 * V_16 ,
struct V_5 * V_6 ,
struct V_2 * V_7 , int V_17 )
{
struct V_42 V_43 ;
int V_44 , V_20 = 0 ;
enum V_14 V_45 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_46 = V_16 -> V_24 ;
V_43 . V_47 = V_7 -> V_12 . type ;
V_43 . V_48 = V_7 -> V_12 . V_48 ;
V_43 . V_49 = V_6 -> V_27 . V_29 ;
V_43 . V_17 = F_31 ( V_17 ) ;
memcpy ( V_43 . V_28 , V_6 -> V_27 . V_28 , V_43 . V_49 ) ;
V_44 = F_32 ( V_50 , V_16 -> V_51 , & V_43 ,
sizeof( V_43 ) , V_6 -> V_37 , & V_20 ) ;
if ( V_44 >= 0 ) {
V_45 = V_20 ;
if ( V_45 == V_52 ) {
F_10 ( V_53 , L_12
L_13
L_14 , V_16 -> V_28 , V_43 . V_49 ,
V_43 . V_28 , V_6 -> V_37 ) ;
F_33 ( V_6 ) ;
F_34 () ;
}
} else {
F_10 ( V_53 , L_15
L_16 , V_16 -> V_28 , V_43 . V_49 , V_43 . V_28 ,
V_44 , V_6 -> V_37 ) ;
if ( F_35 ( V_44 ) )
V_45 = V_38 ;
else
V_45 = F_36 ( V_44 ) ;
}
return V_45 ;
}
void F_17 ( struct V_2 * V_7 )
{
F_37 ( & V_7 -> V_54 ) ;
}
void F_29 ( struct V_2 * V_7 )
{
F_38 ( & V_7 -> V_54 , V_55 ) ;
}
static void V_55 ( struct V_56 * V_56 )
{
struct V_2 * V_7 ;
V_7 = F_39 ( V_56 , struct V_2 , V_54 ) ;
F_40 ( ! F_41 ( & V_7 -> V_11 ) ) ;
F_40 ( ! F_41 ( & V_7 -> V_57 ) ) ;
F_40 ( ! F_41 ( & V_7 -> V_58 ) ) ;
F_40 ( V_7 -> V_59 ) ;
F_40 ( V_7 -> V_60 ) ;
F_42 ( V_7 ) ;
if ( V_7 -> V_61 ) {
F_10 ( 0 , L_17 ) ;
F_43 ( V_7 -> V_25 ) ;
}
F_44 ( V_1 , V_7 ) ;
}
void F_45 ( struct V_2 * V_7 ,
struct V_5 * V_6 )
{
F_46 ( V_6 ) ;
V_7 -> V_62 = V_6 ;
}
static void F_42 ( struct V_2 * V_7 )
{
struct V_5 * V_6 ;
V_6 = V_7 -> V_62 ;
if ( V_6 ) {
V_7 -> V_62 = NULL ;
F_10 ( 0 , L_18 ) ;
F_47 ( V_6 ) ;
}
}
static void F_48 ( struct V_2 * V_63 , int type ,
T_1 V_23 , T_2 V_48 )
{
F_49 ( & V_63 -> V_11 ) ;
F_49 ( & V_63 -> V_57 ) ;
F_49 ( & V_63 -> V_58 ) ;
F_50 ( & V_63 -> V_22 ) ;
V_63 -> V_12 . type = type ;
V_63 -> V_12 . V_13 = V_64 ;
V_63 -> V_12 . V_65 = V_64 ;
V_63 -> V_12 . V_23 = V_23 ;
V_63 -> V_12 . V_66 = 0 ;
V_63 -> V_12 . V_11 = 0 ;
V_63 -> V_12 . V_17 = 0 ;
V_63 -> V_67 = NULL ;
V_63 -> V_68 = NULL ;
V_63 -> V_69 = NULL ;
V_63 -> V_12 . V_48 = F_51 ( V_48 ) ;
V_63 -> V_59 = 0 ;
V_63 -> V_60 = 0 ;
V_63 -> V_70 = 0 ;
V_63 -> V_41 = 0 ;
V_63 -> V_71 = 0 ;
V_63 -> V_72 = 0 ;
V_63 -> V_61 = 0 ;
F_52 ( & V_63 -> V_54 ) ;
}
struct V_2 * F_53 ( int type , T_1 V_23 , T_2 V_48 ,
struct V_73 * V_25 )
{
struct V_2 * V_7 ;
int V_74 = 0 ;
V_7 = F_54 ( V_1 , V_75 ) ;
if ( ! V_7 )
return NULL ;
if ( ! V_25 ) {
V_25 = F_55 ( sizeof( * V_25 ) , V_75 ) ;
if ( ! V_25 ) {
F_44 ( V_1 , V_7 ) ;
return NULL ;
}
V_74 = 1 ;
}
F_48 ( V_7 , type , V_23 , V_48 ) ;
if ( V_74 )
V_7 -> V_61 = 1 ;
V_7 -> V_25 = V_25 ;
V_25 -> V_76 = V_7 ;
return V_7 ;
}
int F_56 ( struct V_77 * V_78 , T_3 V_29 , void * V_79 ,
void * * V_80 )
{
struct V_15 * V_16 = V_79 ;
struct V_42 * V_43 = (struct V_42 * ) V_78 -> V_81 ;
struct V_5 * V_6 = NULL ;
struct V_2 * V_63 = NULL ;
struct V_73 * V_25 = NULL ;
enum V_14 V_20 = V_21 ;
char * V_28 ;
unsigned int V_49 ;
F_40 ( ! V_16 ) ;
if ( ! F_57 ( V_16 ) )
return V_52 ;
V_28 = V_43 -> V_28 ;
V_49 = V_43 -> V_49 ;
V_20 = V_52 ;
if ( ! F_58 ( V_16 ) ) {
F_10 ( V_53 , L_19
L_20 ,
V_16 -> V_28 , V_43 -> V_46 , V_49 , V_28 ) ;
F_14 ( V_20 ) ;
goto V_82;
}
V_20 = V_83 ;
if ( V_49 > V_84 ) {
F_14 ( V_20 ) ;
goto V_82;
}
V_20 = V_85 ;
V_63 = F_53 ( V_43 -> V_47 ,
V_43 -> V_46 ,
F_59 ( V_43 -> V_48 ) , NULL ) ;
if ( ! V_63 ) {
F_14 ( V_20 ) ;
goto V_82;
}
V_25 = V_63 -> V_25 ;
if ( F_60 ( V_43 -> V_17 ) & V_86 ) {
V_25 -> V_17 |= V_34 ;
F_10 ( 0 , L_21 ) ;
}
V_20 = V_87 ;
V_6 = F_61 ( V_16 , V_28 , V_49 ) ;
if ( ! V_6 ) {
F_14 ( V_20 ) ;
goto V_82;
}
F_11 ( & V_6 -> V_22 ) ;
V_20 = F_12 ( V_6 ) ;
F_13 ( & V_6 -> V_22 ) ;
if ( V_20 != V_21 ) {
F_10 ( 0 , L_22 ) ;
goto V_82;
}
F_45 ( V_63 , V_6 ) ;
V_20 = F_9 ( V_16 , V_6 , V_63 , F_60 ( V_43 -> V_17 ) ) ;
V_82:
if ( V_20 != V_21 )
if ( V_63 )
F_29 ( V_63 ) ;
if ( V_6 )
F_47 ( V_6 ) ;
F_62 ( V_16 ) ;
return V_20 ;
}
static inline void F_63 ( T_1 V_24 , T_2 * V_48 )
{
T_2 V_88 = V_24 ;
V_88 <<= 56 ;
F_11 ( & V_89 ) ;
* V_48 = ( V_90 | V_88 ) ;
if ( ++ V_90 & 0xff00000000000000ull ) {
F_10 ( 0 , L_23 ) ;
V_90 = 1 ;
}
F_13 ( & V_89 ) ;
}
enum V_14 F_64 ( struct V_15 * V_16 , int V_91 ,
struct V_73 * V_25 , int V_17 ,
const char * V_28 , int V_49 , T_4 * V_67 ,
void * V_79 , T_5 * V_68 )
{
enum V_14 V_20 ;
struct V_5 * V_6 = NULL ;
struct V_2 * V_7 = NULL ;
int V_92 = 0 , V_93 = 0 ;
if ( ! V_25 ) {
F_14 ( V_94 ) ;
return V_94 ;
}
V_20 = V_95 ;
if ( V_91 != V_96 && V_91 != V_97 && V_91 != V_98 ) {
F_14 ( V_20 ) ;
goto error;
}
if ( V_17 & ~ V_99 ) {
F_14 ( V_20 ) ;
goto error;
}
V_92 = ( V_17 & V_100 ) ;
V_93 = ( V_17 & V_101 ) ;
if ( V_93 &&
( ! F_19 ( V_28 , V_49 ) || V_92 ) ) {
F_14 ( V_20 ) ;
goto error;
}
if ( V_92 && ( V_17 & V_102 ) ) {
F_10 ( V_53 , L_24 ) ;
goto error;
}
if ( V_92 ) {
V_7 = V_25 -> V_76 ;
if ( ! V_7 ) {
F_10 ( V_53 , L_25
L_26 ) ;
goto error;
}
V_6 = V_7 -> V_62 ;
if ( ! V_6 ) {
F_10 ( V_53 , L_27
L_26 ) ;
goto error;
}
F_46 ( V_6 ) ;
if ( V_7 -> V_25 != V_25 || V_7 -> V_67 != V_67 ||
V_7 -> V_68 != V_68 || V_7 -> V_69 != V_79 ) {
V_20 = V_94 ;
F_10 ( V_53 , L_28
L_29 , V_25 , V_67 , V_68 , V_79 ) ;
F_10 ( V_53 , L_30
L_29 , V_7 -> V_25 , V_7 -> V_67 ,
V_7 -> V_68 , V_7 -> V_69 ) ;
goto error;
}
V_103:
F_65 ( V_16 ) ;
if ( V_6 -> V_37 == V_16 -> V_24 )
V_20 = F_66 ( V_16 , V_6 , V_7 , V_17 , V_91 ) ;
else
V_20 = F_67 ( V_16 , V_6 , V_7 , V_17 , V_91 ) ;
if ( V_20 == V_38 || V_20 == V_104 ||
V_20 == V_105 ) {
F_10 ( 0 , L_31
L_32 ) ;
F_68 ( 100 ) ;
goto V_103;
}
} else {
T_2 V_106 ;
V_20 = V_94 ;
if ( ! V_28 ) {
F_14 ( V_20 ) ;
goto error;
}
V_20 = V_83 ;
if ( V_49 > V_84 || V_49 < 1 ) {
F_14 ( V_20 ) ;
goto error;
}
F_63 ( V_16 -> V_24 , & V_106 ) ;
V_7 = F_53 ( V_91 , V_16 -> V_24 , V_106 , V_25 ) ;
if ( ! V_7 ) {
F_14 ( V_20 ) ;
goto error;
}
if ( ! V_93 )
F_65 ( V_16 ) ;
V_6 = F_69 ( V_16 , V_28 , V_49 , V_17 ) ;
if ( ! V_6 ) {
V_20 = V_87 ;
F_14 ( V_20 ) ;
goto error;
}
F_10 ( 0 , L_33 , V_91 , V_17 ) ;
F_10 ( 0 , L_34 , V_7 , V_6 ) ;
F_45 ( V_7 , V_6 ) ;
V_7 -> V_67 = V_67 ;
V_7 -> V_68 = V_68 ;
V_7 -> V_69 = V_79 ;
V_107:
if ( V_17 & V_108 ) {
F_10 ( 0 , L_35 ) ;
if ( V_91 < V_97 )
V_17 &= ~ V_108 ;
else {
V_17 |= V_86 ;
V_7 -> V_25 -> V_17 |= V_34 ;
}
}
if ( V_6 -> V_37 == V_16 -> V_24 )
V_20 = F_9 ( V_16 , V_6 , V_7 , V_17 ) ;
else
V_20 = F_27 ( V_16 , V_6 , V_7 , V_17 ) ;
if ( V_20 == V_38 || V_20 == V_104 ||
V_20 == V_105 ) {
F_68 ( 100 ) ;
if ( V_93 ) {
if ( V_20 != V_38 )
goto V_107;
F_70 ( V_16 , V_6 -> V_37 ,
V_109 ) ;
} else {
F_65 ( V_16 ) ;
goto V_107;
}
}
F_11 ( & V_6 -> V_22 ) ;
F_71 ( V_16 , V_6 ) ;
F_13 ( & V_6 -> V_22 ) ;
F_23 ( V_16 , V_6 ) ;
F_24 ( V_16 , V_6 ) ;
if ( V_20 != V_21 ) {
V_7 -> V_25 -> V_17 &= ~ V_34 ;
if ( V_20 != V_31 )
F_14 ( V_20 ) ;
goto error;
}
}
error:
if ( V_20 != V_21 ) {
if ( V_7 && ! V_92 )
F_29 ( V_7 ) ;
V_25 -> V_20 = V_20 ;
}
if ( V_6 )
F_47 ( V_6 ) ;
return V_20 ;
}
