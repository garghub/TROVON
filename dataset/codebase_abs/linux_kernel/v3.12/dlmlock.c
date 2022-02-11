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
struct V_2 * V_8 ;
F_6 (tmplock, &res->granted, list) {
if ( ! F_7 ( V_8 -> V_9 . type , V_7 -> V_9 . type ) )
return 0 ;
}
F_6 (tmplock, &res->converting, list) {
if ( ! F_7 ( V_8 -> V_9 . type , V_7 -> V_9 . type ) )
return 0 ;
if ( ! F_7 ( V_8 -> V_9 . V_10 ,
V_7 -> V_9 . type ) )
return 0 ;
}
return 1 ;
}
static enum V_11 F_8 ( struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_2 * V_7 , int V_14 )
{
int V_15 = 0 , V_16 = 0 ;
enum V_11 V_17 = V_18 ;
F_9 ( 0 , L_2 , V_7 -> V_9 . type ) ;
F_10 ( & V_6 -> V_19 ) ;
V_17 = F_11 ( V_6 ) ;
if ( V_17 != V_18 &&
V_7 -> V_9 . V_20 != V_13 -> V_21 ) {
F_12 ( & V_6 -> V_19 ) ;
F_13 ( V_17 ) ;
return V_17 ;
}
F_14 ( V_6 ) ;
F_15 ( V_6 ) ;
if ( F_5 ( V_6 , V_7 ) ) {
F_9 ( 0 , L_3 ) ;
V_7 -> V_22 -> V_17 = V_18 ;
V_17 = V_18 ;
F_16 ( V_7 ) ;
F_17 ( & V_7 -> V_23 , & V_6 -> V_24 ) ;
if ( ! F_18 ( V_6 -> V_25 . V_26 ,
V_6 -> V_25 . V_27 ) ) {
V_16 = 1 ;
V_15 = 1 ;
} else {
F_9 ( 0 , L_4
L_5 , V_13 -> V_26 ,
V_7 -> V_9 . V_20 ) ;
}
} else {
if ( V_14 & V_28 ) {
V_17 = V_29 ;
if ( F_18 ( V_6 -> V_25 . V_26 ,
V_6 -> V_25 . V_27 ) ) {
F_9 ( 0 , L_6
L_5 , V_13 -> V_26 ,
V_7 -> V_9 . V_20 ) ;
}
} else {
V_17 = V_18 ;
F_16 ( V_7 ) ;
F_17 ( & V_7 -> V_23 , & V_6 -> V_30 ) ;
V_16 = 1 ;
}
}
F_12 ( & V_6 -> V_19 ) ;
F_19 ( & V_6 -> V_31 ) ;
if ( V_15 )
F_20 ( V_13 , V_7 ) ;
else
F_21 ( V_13 , V_6 ) ;
F_22 ( V_13 , V_6 ) ;
if ( V_16 )
F_23 ( V_13 , V_6 ) ;
return V_17 ;
}
void F_24 ( struct V_5 * V_6 ,
struct V_2 * V_7 )
{
F_25 ( & V_7 -> V_23 ) ;
V_7 -> V_22 -> V_14 &= ~ V_32 ;
}
static enum V_11 F_26 ( struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_2 * V_7 , int V_14 )
{
enum V_11 V_17 = V_33 ;
int V_34 = 1 ;
F_9 ( 0 , L_7 ,
V_7 -> V_9 . type , V_6 -> V_25 . V_27 ,
V_6 -> V_25 . V_26 , V_14 ) ;
F_10 ( & V_6 -> V_19 ) ;
F_14 ( V_6 ) ;
if ( V_6 -> V_35 == V_13 -> V_21 ) {
F_12 ( & V_6 -> V_19 ) ;
return V_36 ;
}
V_6 -> V_37 |= V_38 ;
F_16 ( V_7 ) ;
F_17 ( & V_7 -> V_23 , & V_6 -> V_30 ) ;
V_7 -> V_39 = 1 ;
F_12 ( & V_6 -> V_19 ) ;
V_17 = F_27 ( V_13 , V_6 , V_7 , V_14 ) ;
F_10 ( & V_6 -> V_19 ) ;
V_6 -> V_37 &= ~ V_38 ;
V_7 -> V_39 = 0 ;
if ( V_17 != V_18 ) {
if ( V_17 == V_36 &&
F_18 ( V_6 -> V_25 . V_26 ,
V_6 -> V_25 . V_27 ) ) {
F_9 ( 0 , L_8
L_9 ,
V_13 -> V_26 , V_6 -> V_35 ) ;
} else if ( V_17 != V_29 ) {
V_34 = 0 ;
F_13 ( V_17 ) ;
}
F_24 ( V_6 , V_7 ) ;
F_28 ( V_7 ) ;
} else if ( F_18 ( V_6 -> V_25 . V_26 ,
V_6 -> V_25 . V_27 ) ) {
F_9 ( 0 , L_10
L_11 ,
V_13 -> V_26 , V_13 -> V_21 , V_6 -> V_35 ) ;
F_29 ( & V_7 -> V_23 , & V_6 -> V_24 ) ;
}
F_12 ( & V_6 -> V_19 ) ;
if ( V_34 )
F_22 ( V_13 , V_6 ) ;
F_19 ( & V_6 -> V_31 ) ;
return V_17 ;
}
static enum V_11 F_27 ( struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_2 * V_7 , int V_14 )
{
struct V_40 V_41 ;
int V_42 , V_17 = 0 ;
enum V_11 V_43 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_44 = V_13 -> V_21 ;
V_41 . V_45 = V_7 -> V_9 . type ;
V_41 . V_46 = V_7 -> V_9 . V_46 ;
V_41 . V_47 = V_6 -> V_25 . V_27 ;
V_41 . V_14 = F_30 ( V_14 ) ;
memcpy ( V_41 . V_26 , V_6 -> V_25 . V_26 , V_41 . V_47 ) ;
V_42 = F_31 ( V_48 , V_13 -> V_49 , & V_41 ,
sizeof( V_41 ) , V_6 -> V_35 , & V_17 ) ;
if ( V_42 >= 0 ) {
V_43 = V_17 ;
if ( V_43 == V_50 ) {
F_9 ( V_51 , L_12
L_13
L_14 , V_13 -> V_26 , V_41 . V_47 ,
V_41 . V_26 , V_6 -> V_35 ) ;
F_32 ( V_6 ) ;
F_33 () ;
}
} else {
F_9 ( V_51 , L_15
L_16 , V_13 -> V_26 , V_41 . V_47 , V_41 . V_26 ,
V_42 , V_6 -> V_35 ) ;
if ( F_34 ( V_42 ) )
V_43 = V_36 ;
else
V_43 = F_35 ( V_42 ) ;
}
return V_43 ;
}
void F_16 ( struct V_2 * V_7 )
{
F_36 ( & V_7 -> V_52 ) ;
}
void F_28 ( struct V_2 * V_7 )
{
F_37 ( & V_7 -> V_52 , V_53 ) ;
}
static void V_53 ( struct V_54 * V_54 )
{
struct V_2 * V_7 ;
V_7 = F_38 ( V_54 , struct V_2 , V_52 ) ;
F_39 ( ! F_40 ( & V_7 -> V_23 ) ) ;
F_39 ( ! F_40 ( & V_7 -> V_55 ) ) ;
F_39 ( ! F_40 ( & V_7 -> V_56 ) ) ;
F_39 ( V_7 -> V_57 ) ;
F_39 ( V_7 -> V_58 ) ;
F_41 ( V_7 ) ;
if ( V_7 -> V_59 ) {
F_9 ( 0 , L_17 ) ;
F_42 ( V_7 -> V_22 ) ;
}
F_43 ( V_1 , V_7 ) ;
}
void F_44 ( struct V_2 * V_7 ,
struct V_5 * V_6 )
{
F_45 ( V_6 ) ;
V_7 -> V_60 = V_6 ;
}
static void F_41 ( struct V_2 * V_7 )
{
struct V_5 * V_6 ;
V_6 = V_7 -> V_60 ;
if ( V_6 ) {
V_7 -> V_60 = NULL ;
F_9 ( 0 , L_18 ) ;
F_46 ( V_6 ) ;
}
}
static void F_47 ( struct V_2 * V_61 , int type ,
T_1 V_20 , T_2 V_46 )
{
F_48 ( & V_61 -> V_23 ) ;
F_48 ( & V_61 -> V_55 ) ;
F_48 ( & V_61 -> V_56 ) ;
F_49 ( & V_61 -> V_19 ) ;
V_61 -> V_9 . type = type ;
V_61 -> V_9 . V_10 = V_62 ;
V_61 -> V_9 . V_63 = V_62 ;
V_61 -> V_9 . V_20 = V_20 ;
V_61 -> V_9 . V_64 = 0 ;
V_61 -> V_9 . V_23 = 0 ;
V_61 -> V_9 . V_14 = 0 ;
V_61 -> V_65 = NULL ;
V_61 -> V_66 = NULL ;
V_61 -> V_67 = NULL ;
V_61 -> V_9 . V_46 = F_50 ( V_46 ) ;
V_61 -> V_57 = 0 ;
V_61 -> V_58 = 0 ;
V_61 -> V_68 = 0 ;
V_61 -> V_39 = 0 ;
V_61 -> V_69 = 0 ;
V_61 -> V_70 = 0 ;
V_61 -> V_59 = 0 ;
F_51 ( & V_61 -> V_52 ) ;
}
struct V_2 * F_52 ( int type , T_1 V_20 , T_2 V_46 ,
struct V_71 * V_22 )
{
struct V_2 * V_7 ;
int V_72 = 0 ;
V_7 = F_53 ( V_1 , V_73 ) ;
if ( ! V_7 )
return NULL ;
if ( ! V_22 ) {
V_22 = F_54 ( sizeof( * V_22 ) , V_73 ) ;
if ( ! V_22 ) {
F_43 ( V_1 , V_7 ) ;
return NULL ;
}
V_72 = 1 ;
}
F_47 ( V_7 , type , V_20 , V_46 ) ;
if ( V_72 )
V_7 -> V_59 = 1 ;
V_7 -> V_22 = V_22 ;
V_22 -> V_74 = V_7 ;
return V_7 ;
}
int F_55 ( struct V_75 * V_76 , T_3 V_27 , void * V_77 ,
void * * V_78 )
{
struct V_12 * V_13 = V_77 ;
struct V_40 * V_41 = (struct V_40 * ) V_76 -> V_79 ;
struct V_5 * V_6 = NULL ;
struct V_2 * V_61 = NULL ;
struct V_71 * V_22 = NULL ;
enum V_11 V_17 = V_18 ;
char * V_26 ;
unsigned int V_47 ;
F_39 ( ! V_13 ) ;
if ( ! F_56 ( V_13 ) )
return V_50 ;
V_26 = V_41 -> V_26 ;
V_47 = V_41 -> V_47 ;
V_17 = V_50 ;
if ( ! F_57 ( V_13 ) ) {
F_9 ( V_51 , L_19
L_20 ,
V_13 -> V_26 , V_41 -> V_44 , V_47 , V_26 ) ;
F_13 ( V_17 ) ;
goto V_80;
}
V_17 = V_81 ;
if ( V_47 > V_82 ) {
F_13 ( V_17 ) ;
goto V_80;
}
V_17 = V_83 ;
V_61 = F_52 ( V_41 -> V_45 ,
V_41 -> V_44 ,
F_58 ( V_41 -> V_46 ) , NULL ) ;
if ( ! V_61 ) {
F_13 ( V_17 ) ;
goto V_80;
}
V_22 = V_61 -> V_22 ;
if ( F_59 ( V_41 -> V_14 ) & V_84 ) {
V_22 -> V_14 |= V_32 ;
F_9 ( 0 , L_21 ) ;
}
V_17 = V_85 ;
V_6 = F_60 ( V_13 , V_26 , V_47 ) ;
if ( ! V_6 ) {
F_13 ( V_17 ) ;
goto V_80;
}
F_10 ( & V_6 -> V_19 ) ;
V_17 = F_11 ( V_6 ) ;
F_12 ( & V_6 -> V_19 ) ;
if ( V_17 != V_18 ) {
F_9 ( 0 , L_22 ) ;
goto V_80;
}
F_44 ( V_61 , V_6 ) ;
V_17 = F_8 ( V_13 , V_6 , V_61 , F_59 ( V_41 -> V_14 ) ) ;
V_80:
if ( V_17 != V_18 )
if ( V_61 )
F_28 ( V_61 ) ;
if ( V_6 )
F_46 ( V_6 ) ;
F_61 ( V_13 ) ;
return V_17 ;
}
static inline void F_62 ( T_1 V_21 , T_2 * V_46 )
{
T_2 V_86 = V_21 ;
V_86 <<= 56 ;
F_10 ( & V_87 ) ;
* V_46 = ( V_88 | V_86 ) ;
if ( ++ V_88 & 0xff00000000000000ull ) {
F_9 ( 0 , L_23 ) ;
V_88 = 1 ;
}
F_12 ( & V_87 ) ;
}
enum V_11 F_63 ( struct V_12 * V_13 , int V_89 ,
struct V_71 * V_22 , int V_14 ,
const char * V_26 , int V_47 , T_4 * V_65 ,
void * V_77 , T_5 * V_66 )
{
enum V_11 V_17 ;
struct V_5 * V_6 = NULL ;
struct V_2 * V_7 = NULL ;
int V_90 = 0 , V_91 = 0 ;
if ( ! V_22 ) {
F_13 ( V_92 ) ;
return V_92 ;
}
V_17 = V_93 ;
if ( V_89 != V_94 && V_89 != V_95 && V_89 != V_96 ) {
F_13 ( V_17 ) ;
goto error;
}
if ( V_14 & ~ V_97 ) {
F_13 ( V_17 ) ;
goto error;
}
V_90 = ( V_14 & V_98 ) ;
V_91 = ( V_14 & V_99 ) ;
if ( V_91 &&
( ! F_18 ( V_26 , V_47 ) || V_90 ) ) {
F_13 ( V_17 ) ;
goto error;
}
if ( V_90 && ( V_14 & V_100 ) ) {
F_9 ( V_51 , L_24 ) ;
goto error;
}
if ( V_90 ) {
V_7 = V_22 -> V_74 ;
if ( ! V_7 ) {
F_9 ( V_51 , L_25
L_26 ) ;
goto error;
}
V_6 = V_7 -> V_60 ;
if ( ! V_6 ) {
F_9 ( V_51 , L_27
L_26 ) ;
goto error;
}
F_45 ( V_6 ) ;
if ( V_7 -> V_22 != V_22 || V_7 -> V_65 != V_65 ||
V_7 -> V_66 != V_66 || V_7 -> V_67 != V_77 ) {
V_17 = V_92 ;
F_9 ( V_51 , L_28
L_29 , V_22 , V_65 , V_66 , V_77 ) ;
F_9 ( V_51 , L_30
L_29 , V_7 -> V_22 , V_7 -> V_65 ,
V_7 -> V_66 , V_7 -> V_67 ) ;
goto error;
}
V_101:
F_64 ( V_13 ) ;
if ( V_6 -> V_35 == V_13 -> V_21 )
V_17 = F_65 ( V_13 , V_6 , V_7 , V_14 , V_89 ) ;
else
V_17 = F_66 ( V_13 , V_6 , V_7 , V_14 , V_89 ) ;
if ( V_17 == V_36 || V_17 == V_102 ||
V_17 == V_103 ) {
F_9 ( 0 , L_31
L_32 ) ;
F_67 ( 100 ) ;
goto V_101;
}
} else {
T_2 V_104 ;
V_17 = V_92 ;
if ( ! V_26 ) {
F_13 ( V_17 ) ;
goto error;
}
V_17 = V_81 ;
if ( V_47 > V_82 || V_47 < 1 ) {
F_13 ( V_17 ) ;
goto error;
}
F_62 ( V_13 -> V_21 , & V_104 ) ;
V_7 = F_52 ( V_89 , V_13 -> V_21 , V_104 , V_22 ) ;
if ( ! V_7 ) {
F_13 ( V_17 ) ;
goto error;
}
if ( ! V_91 )
F_64 ( V_13 ) ;
V_6 = F_68 ( V_13 , V_26 , V_47 , V_14 ) ;
if ( ! V_6 ) {
V_17 = V_85 ;
F_13 ( V_17 ) ;
goto error;
}
F_9 ( 0 , L_33 , V_89 , V_14 ) ;
F_9 ( 0 , L_34 , V_7 , V_6 ) ;
F_44 ( V_7 , V_6 ) ;
V_7 -> V_65 = V_65 ;
V_7 -> V_66 = V_66 ;
V_7 -> V_67 = V_77 ;
V_105:
if ( V_14 & V_106 ) {
F_9 ( 0 , L_35 ) ;
if ( V_89 < V_95 )
V_14 &= ~ V_106 ;
else {
V_14 |= V_84 ;
V_7 -> V_22 -> V_14 |= V_32 ;
}
}
if ( V_6 -> V_35 == V_13 -> V_21 )
V_17 = F_8 ( V_13 , V_6 , V_7 , V_14 ) ;
else
V_17 = F_26 ( V_13 , V_6 , V_7 , V_14 ) ;
if ( V_17 == V_36 || V_17 == V_102 ||
V_17 == V_103 ) {
F_67 ( 100 ) ;
if ( V_91 ) {
if ( V_17 != V_36 )
goto V_105;
F_69 ( V_13 , V_6 -> V_35 ,
V_107 ) ;
} else {
F_64 ( V_13 ) ;
goto V_105;
}
}
F_10 ( & V_6 -> V_19 ) ;
F_70 ( V_13 , V_6 ) ;
F_12 ( & V_6 -> V_19 ) ;
F_22 ( V_13 , V_6 ) ;
F_23 ( V_13 , V_6 ) ;
if ( V_17 != V_18 ) {
V_7 -> V_22 -> V_14 &= ~ V_32 ;
if ( V_17 != V_29 )
F_13 ( V_17 ) ;
goto error;
}
}
error:
if ( V_17 != V_18 ) {
if ( V_7 && ! V_90 )
F_28 ( V_7 ) ;
V_22 -> V_17 = V_17 ;
}
if ( V_6 )
F_46 ( V_6 ) ;
return V_17 ;
}
