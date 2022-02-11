static inline void F_1 ( const struct V_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_4 . V_5 + V_2 . V_2 ) ;
}
static inline T_1 F_3 ( const struct V_1 V_2 )
{
return F_4 ( V_4 . V_5 + V_2 . V_2 ) ;
}
static void F_5 ( void )
{
F_6 ( L_1 ) ;
F_7 ( V_6 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_7 ( V_9 ) ;
F_7 ( V_10 ) ;
}
V_4 . V_11 = true ;
F_6 ( L_2 ) ;
}
static void F_9 ( void )
{
F_6 ( L_3 ) ;
if ( ! V_4 . V_11 )
return;
F_10 ( V_6 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_10 ( V_9 ) ;
F_10 ( V_10 ) ;
}
F_6 ( L_4 ) ;
}
void F_11 ( T_2 V_12 )
{
T_1 V_13 ;
F_12 ( V_12 > 3 || V_12 < 1 ) ;
V_13 = F_3 ( V_14 ) ;
V_13 = F_13 ( V_13 , 0xf , 19 , 15 ) ;
V_13 = F_13 ( V_13 , V_12 - 1 , 3 , 2 ) ;
V_13 = F_13 ( V_13 , 2 , 1 , 0 ) ;
F_1 ( V_14 , V_13 ) ;
V_13 = F_3 ( V_15 ) ;
V_13 = F_13 ( V_13 , 0x7 , 25 , 22 ) ;
V_13 = F_13 ( V_13 , 0xb , 16 , 11 ) ;
V_13 = F_13 ( V_13 , 0xb4 , 10 , 1 ) ;
F_1 ( V_15 , V_13 ) ;
}
int F_14 ( void )
{
unsigned long V_16 ;
F_15 ( 1 ) ;
F_16 ( V_15 , 1 , 18 , 18 ) ;
F_17 ( 1 ) ;
F_16 ( V_15 , 1 , 28 , 28 ) ;
V_16 = V_17 + F_18 ( 500 ) ;
while ( F_3 ( V_18 ) & ( 1 << 6 ) ) {
if ( F_19 ( V_17 , V_16 ) ) {
F_20 ( L_5 ) ;
goto V_19;
}
}
F_16 ( V_15 , 0 , 28 , 28 ) ;
V_16 = V_17 + F_18 ( 500 ) ;
while ( ! ( F_3 ( V_18 ) & ( 1 << 5 ) ) ) {
if ( F_19 ( V_17 , V_16 ) ) {
F_20 ( L_6 ) ;
goto V_19;
}
}
F_21 ( 1 ) ;
V_16 = V_17 + F_18 ( 500 ) ;
while ( ! ( F_3 ( V_18 ) & ( 1 << 2 ) ) ) {
if ( F_19 ( V_17 , V_16 ) ) {
F_20 ( L_7 ) ;
goto V_20;
}
}
return 0 ;
V_20:
F_21 ( 0 ) ;
V_19:
F_16 ( V_15 , 0 , 18 , 18 ) ;
F_15 ( 0 ) ;
return - V_21 ;
}
void F_22 ( void )
{
F_21 ( 0 ) ;
F_15 ( 0 ) ;
F_16 ( V_15 , 0 , 18 , 18 ) ;
}
const char * F_23 ( enum V_22 V_23 )
{
return V_24 [ V_23 ] ;
}
void F_24 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
unsigned long V_28 ;
const char * V_29 , * V_30 ;
unsigned long V_31 ;
if ( F_25 () )
return;
F_26 ( V_26 , L_8 ) ;
V_29 = F_23 ( V_32 ) ;
V_30 = F_27 ( V_32 ) ;
V_31 = F_28 ( V_4 . V_33 ) ;
if ( V_4 . V_34 ) {
V_27 = F_28 ( F_29 ( V_4 . V_34 ) ) ;
V_28 = F_28 ( V_4 . V_34 ) ;
F_26 ( V_26 , L_9 , V_27 ) ;
if ( F_30 () || F_31 () )
F_26 ( V_26 , L_10 ,
V_29 , V_30 ,
V_27 ,
V_27 / V_28 ,
V_31 ) ;
else
F_26 ( V_26 , L_11 ,
V_29 , V_30 ,
V_27 ,
V_27 / V_28 ,
V_31 ) ;
} else {
F_26 ( V_26 , L_12 ,
V_29 , V_30 ,
V_31 ) ;
}
F_32 () ;
}
void F_33 ( struct V_25 * V_26 )
{
#define F_34 ( T_3 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if ( F_25 () )
return;
F_34 ( V_35 ) ;
F_34 ( V_36 ) ;
F_34 ( V_37 ) ;
F_34 ( V_38 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_34 ( V_14 ) ;
F_34 ( V_15 ) ;
F_34 ( V_18 ) ;
}
F_32 () ;
#undef F_34
}
void F_35 ( enum V_22 V_23 )
{
struct V_39 * V_40 ;
int V_41 ;
T_2 V_42 , V_43 ;
switch ( V_23 ) {
case V_32 :
V_41 = 0 ;
break;
case V_44 :
V_41 = 1 ;
V_40 = F_36 ( 0 ) ;
F_37 ( V_40 ) ;
break;
case V_45 :
V_41 = 2 ;
V_40 = F_36 ( 1 ) ;
F_37 ( V_40 ) ;
break;
default:
F_38 () ;
}
F_39 ( V_46 , & V_42 , & V_43 ) ;
F_16 ( V_38 , V_41 , V_42 , V_43 ) ;
V_4 . V_47 = V_23 ;
}
void F_40 ( int V_48 ,
enum V_22 V_23 )
{
struct V_39 * V_40 ;
int V_41 ;
switch ( V_23 ) {
case V_32 :
V_41 = 0 ;
break;
case V_49 :
F_12 ( V_48 != 0 ) ;
V_41 = 1 ;
V_40 = F_36 ( 0 ) ;
F_41 ( V_40 ) ;
break;
case V_50 :
F_12 ( V_48 != 1 ) ;
V_41 = 1 ;
V_40 = F_36 ( 1 ) ;
F_41 ( V_40 ) ;
break;
default:
F_38 () ;
}
F_16 ( V_38 , V_41 , 1 , 1 ) ;
V_4 . V_51 [ V_48 ] = V_23 ;
}
void F_42 ( enum V_52 V_53 ,
enum V_22 V_23 )
{
struct V_39 * V_40 ;
int V_41 , V_54 , V_55 ;
if ( ! F_43 ( V_56 ) )
return;
switch ( V_23 ) {
case V_32 :
V_41 = 0 ;
break;
case V_44 :
F_12 ( V_53 != V_7 ) ;
V_41 = 1 ;
V_40 = F_36 ( 0 ) ;
F_37 ( V_40 ) ;
break;
case V_45 :
F_12 ( V_53 != V_57 ) ;
V_41 = 1 ;
V_40 = F_36 ( 1 ) ;
F_37 ( V_40 ) ;
break;
default:
F_38 () ;
}
V_55 = V_53 == V_7 ? 0 : 12 ;
F_16 ( V_38 , V_41 , V_55 , V_55 ) ;
V_54 = V_53 == V_7 ? 0 : 1 ;
V_4 . V_58 [ V_54 ] = V_23 ;
}
enum V_22 F_44 ( void )
{
return V_4 . V_47 ;
}
enum V_22 F_45 ( int V_48 )
{
return V_4 . V_51 [ V_48 ] ;
}
enum V_22 F_46 ( enum V_52 V_53 )
{
if ( F_43 ( V_56 ) ) {
int V_54 = V_53 == V_7 ? 0 : 1 ;
return V_4 . V_58 [ V_54 ] ;
} else {
return V_4 . V_47 ;
}
}
int F_47 ( struct V_59 * V_60 )
{
if ( V_4 . V_34 ) {
unsigned long V_61 ;
T_4 V_62 = 16 ;
if ( F_30 () || F_31 () )
V_62 = 32 ;
if ( V_60 -> V_63 > V_62 || V_60 -> V_63 == 0 )
return - V_64 ;
V_61 = F_28 ( F_29 ( V_4 . V_34 ) ) ;
V_60 -> V_65 = V_61 / V_60 -> V_63 ;
} else {
if ( V_60 -> V_63 != 0 )
return - V_64 ;
V_60 -> V_65 = F_28 ( V_4 . V_33 ) ;
}
return 0 ;
}
int F_48 ( struct V_59 * V_60 )
{
if ( V_4 . V_34 ) {
unsigned long V_61 ;
int T_3 ;
V_61 = F_28 ( F_29 ( V_4 . V_34 ) ) ;
F_6 ( L_13 , V_61 ) ;
T_3 = F_49 ( V_4 . V_34 , V_61 / V_60 -> V_63 ) ;
if ( T_3 )
return T_3 ;
} else {
if ( V_60 -> V_63 != 0 )
return - V_64 ;
}
F_6 ( L_14 , V_60 -> V_65 , V_60 -> V_63 ) ;
return 0 ;
}
int F_50 ( struct V_59 * V_60 )
{
V_60 -> V_65 = F_28 ( V_4 . V_33 ) ;
if ( V_4 . V_34 ) {
unsigned long V_61 ;
V_61 = F_28 ( F_29 ( V_4 . V_34 ) ) ;
if ( F_30 () || F_31 () )
V_60 -> V_63 = V_61 / ( V_60 -> V_65 ) ;
else
V_60 -> V_63 = V_61 / ( V_60 -> V_65 / 2 ) ;
} else {
V_60 -> V_63 = 0 ;
}
return 0 ;
}
unsigned long F_51 ( void )
{
if ( V_4 . V_34 )
return F_28 ( F_29 ( V_4 . V_34 ) ) ;
else
return 0 ;
}
int F_52 ( bool V_66 , unsigned long V_67 ,
struct V_59 * V_68 ,
struct V_69 * V_70 )
{
unsigned long V_61 ;
struct V_59 V_71 ;
struct V_69 V_72 ;
unsigned long V_65 , V_73 ;
T_4 V_63 , V_62 = 16 ;
int V_74 = 0 ;
int V_75 ;
V_61 = F_51 () ;
V_73 = F_53 ( V_76 ) ;
V_65 = F_28 ( V_4 . V_33 ) ;
if ( V_67 == V_4 . V_77 &&
( ( F_54 () && V_61 == V_4 . V_78 ) ||
V_4 . V_79 . V_65 == V_65 ) ) {
F_6 ( L_15 ) ;
* V_68 = V_4 . V_79 ;
* V_70 = V_4 . V_80 ;
return 0 ;
}
V_75 = V_81 ;
if ( V_75 &&
V_67 * V_75 > V_73 ) {
F_20 ( L_16
L_17
L_18 ) ;
V_75 = 0 ;
}
V_82:
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
if ( V_4 . V_34 == NULL ) {
struct V_69 V_83 ;
V_65 = F_28 ( V_4 . V_33 ) ;
V_63 = 1 ;
F_55 ( V_66 , V_67 , V_65 , & V_83 ) ;
V_74 = 1 ;
V_71 . V_65 = V_65 ;
V_71 . V_63 = V_63 ;
V_72 = V_83 ;
goto V_84;
} else {
if ( F_30 () || F_31 () )
V_62 = 32 ;
for ( V_63 = V_62 ; V_63 > 0 ; -- V_63 ) {
struct V_69 V_83 ;
if ( V_62 == 32 )
V_65 = V_61 / V_63 ;
else
V_65 = V_61 / V_63 * 2 ;
if ( V_65 > V_73 )
continue;
if ( V_75 &&
V_65 < V_67 * V_75 )
continue;
V_74 = 1 ;
F_55 ( V_66 , V_67 , V_65 , & V_83 ) ;
if ( abs ( V_83 . V_85 - V_67 ) <
abs ( V_72 . V_85 - V_67 ) ) {
V_71 . V_65 = V_65 ;
V_71 . V_63 = V_63 ;
V_72 = V_83 ;
if ( V_83 . V_85 == V_67 )
goto V_84;
}
}
}
V_84:
if ( ! V_74 ) {
if ( V_75 ) {
F_20 ( L_19
L_20
L_21 ) ;
V_75 = 0 ;
goto V_82;
}
F_20 ( L_19 ) ;
return - V_64 ;
}
if ( V_68 )
* V_68 = V_71 ;
if ( V_70 )
* V_70 = V_72 ;
V_4 . V_77 = V_67 ;
V_4 . V_78 = V_61 ;
V_4 . V_79 = V_71 ;
V_4 . V_80 = V_72 ;
return 0 ;
}
void F_56 ( enum V_86 type )
{
int V_13 = 0 ;
if ( type == V_87 )
V_13 = 0 ;
else if ( type == V_88 )
V_13 = 1 ;
else
F_38 () ;
F_16 ( V_38 , V_13 , 6 , 6 ) ;
}
void F_57 ( bool V_89 )
{
F_16 ( V_38 , V_89 , 5 , 5 ) ;
}
void F_58 ( enum V_90 V_91 )
{
F_16 ( V_38 , V_91 , 15 , 15 ) ;
}
enum V_90 F_59 ( void )
{
enum V_92 V_93 ;
V_93 = F_8 ( V_94 ) ;
if ( ( V_93 & V_95 ) == 0 )
return V_96 ;
return F_60 ( V_38 , 15 , 15 ) ;
}
static int F_61 ( void )
{
struct V_97 * V_97 ;
int T_3 ;
V_97 = F_62 ( & V_4 . V_98 -> V_99 , L_22 ) ;
if ( F_63 ( V_97 ) ) {
F_20 ( L_23 ) ;
T_3 = F_64 ( V_97 ) ;
goto V_100;
}
V_4 . V_33 = V_97 ;
if ( F_54 () ) {
V_97 = F_62 ( NULL , L_24 ) ;
if ( F_63 ( V_97 ) ) {
F_20 ( L_25 ) ;
T_3 = F_64 ( V_97 ) ;
goto V_100;
}
} else if ( F_31 () ) {
V_97 = F_62 ( NULL , L_26 ) ;
if ( F_63 ( V_97 ) ) {
F_20 ( L_27 ) ;
T_3 = F_64 ( V_97 ) ;
goto V_100;
}
} else {
V_97 = NULL ;
}
V_4 . V_34 = V_97 ;
return 0 ;
V_100:
if ( V_4 . V_33 )
F_65 ( V_4 . V_33 ) ;
if ( V_4 . V_34 )
F_65 ( V_4 . V_34 ) ;
return T_3 ;
}
static void F_66 ( void )
{
if ( V_4 . V_34 )
F_65 ( V_4 . V_34 ) ;
F_65 ( V_4 . V_33 ) ;
}
int F_25 ( void )
{
int T_3 ;
F_6 ( L_28 ) ;
T_3 = F_67 ( & V_4 . V_98 -> V_99 ) ;
F_68 ( T_3 < 0 ) ;
return T_3 < 0 ? T_3 : 0 ;
}
void F_32 ( void )
{
int T_3 ;
F_6 ( L_29 ) ;
T_3 = F_69 ( & V_4 . V_98 -> V_99 ) ;
F_68 ( T_3 < 0 ) ;
}
void F_70 ( struct V_25 * V_26 )
{
F_24 ( V_26 ) ;
F_71 ( V_26 ) ;
#ifdef F_72
F_73 ( V_26 ) ;
#endif
}
static int F_74 ( struct V_39 * V_98 )
{
struct V_101 * V_102 ;
T_1 V_103 ;
int T_3 ;
V_4 . V_98 = V_98 ;
V_102 = F_75 ( V_4 . V_98 , V_104 , 0 ) ;
if ( ! V_102 ) {
F_20 ( L_30 ) ;
T_3 = - V_64 ;
goto V_105;
}
V_4 . V_5 = F_76 ( V_102 -> V_42 , F_77 ( V_102 ) ) ;
if ( ! V_4 . V_5 ) {
F_20 ( L_31 ) ;
T_3 = - V_106 ;
goto V_105;
}
T_3 = F_61 () ;
if ( T_3 )
goto V_107;
F_78 ( & V_98 -> V_99 ) ;
T_3 = F_25 () ;
if ( T_3 )
goto V_108;
F_16 ( V_38 , 0 , 0 , 0 ) ;
#ifdef F_79
F_16 ( V_38 , 1 , 4 , 4 ) ;
F_16 ( V_38 , 1 , 3 , 3 ) ;
F_16 ( V_38 , 0 , 2 , 2 ) ;
#endif
V_4 . V_51 [ 0 ] = V_32 ;
V_4 . V_51 [ 1 ] = V_32 ;
V_4 . V_47 = V_32 ;
V_4 . V_58 [ 0 ] = V_32 ;
V_4 . V_58 [ 1 ] = V_32 ;
T_3 = F_80 () ;
if ( T_3 ) {
F_20 ( L_32 ) ;
goto V_109;
}
T_3 = F_81 () ;
if ( T_3 ) {
F_20 ( L_33 ) ;
goto V_110;
}
V_103 = F_3 ( V_35 ) ;
F_82 ( V_111 L_34 ,
F_83 ( V_103 , 7 , 4 ) , F_83 ( V_103 , 3 , 0 ) ) ;
F_32 () ;
return 0 ;
V_110:
F_84 () ;
V_109:
F_32 () ;
V_108:
F_85 ( & V_98 -> V_99 ) ;
F_66 () ;
V_107:
F_86 ( V_4 . V_5 ) ;
V_105:
return T_3 ;
}
static int F_87 ( struct V_39 * V_98 )
{
F_84 () ;
F_88 () ;
F_86 ( V_4 . V_5 ) ;
F_85 ( & V_98 -> V_99 ) ;
F_66 () ;
return 0 ;
}
static int F_89 ( struct V_112 * V_99 )
{
F_5 () ;
return 0 ;
}
static int F_90 ( struct V_112 * V_99 )
{
F_9 () ;
return 0 ;
}
int F_91 ( void )
{
return F_92 ( & V_113 ) ;
}
void F_93 ( void )
{
return F_94 ( & V_113 ) ;
}
