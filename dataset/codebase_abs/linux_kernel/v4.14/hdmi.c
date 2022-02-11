void F_1 ( struct V_1 * V_1 , bool V_2 )
{
T_1 V_3 = 0 ;
unsigned long V_4 ;
F_2 ( & V_1 -> V_5 , V_4 ) ;
if ( V_2 ) {
V_3 |= V_6 ;
if ( ! V_1 -> V_7 ) {
V_3 |= V_8 ;
F_3 ( V_1 , V_9 , V_3 ) ;
V_3 &= ~ V_8 ;
} else {
V_3 |= V_8 ;
}
} else {
V_3 = V_8 ;
}
F_3 ( V_1 , V_9 , V_3 ) ;
F_4 ( & V_1 -> V_5 , V_4 ) ;
F_5 ( L_1 ,
V_2 ? L_2 : L_3 , V_3 ) ;
}
static T_2 F_6 ( int V_10 , void * V_11 )
{
struct V_1 * V_1 = V_11 ;
F_7 ( V_1 -> V_12 ) ;
F_8 ( V_1 -> V_13 ) ;
if ( V_1 -> V_14 )
F_9 ( V_1 -> V_14 ) ;
return V_15 ;
}
static void F_10 ( struct V_1 * V_1 )
{
if ( V_1 -> V_16 ) {
F_11 ( V_1 -> V_16 ) ;
F_12 ( V_1 -> V_16 ) ;
}
F_13 ( V_1 ) ;
if ( V_1 -> V_17 ) {
F_14 ( V_1 -> V_17 ) ;
V_1 -> V_18 = NULL ;
V_1 -> V_17 = NULL ;
}
if ( V_1 -> V_13 )
F_15 ( V_1 -> V_13 ) ;
F_16 ( V_1 -> V_19 , NULL ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_20 * V_19 = V_1 -> V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_23 = F_18 ( V_19 -> V_24 . V_25 , L_4 , 0 ) ;
if ( ! V_23 ) {
F_19 ( & V_19 -> V_24 , L_5 ) ;
return - V_26 ;
}
V_21 = F_20 ( V_23 ) ;
if ( V_21 )
V_1 -> V_18 = F_21 ( V_21 ) ;
F_22 ( V_23 ) ;
if ( ! V_21 || ! V_1 -> V_18 ) {
F_19 ( & V_19 -> V_24 , L_6 ) ;
return - V_27 ;
}
V_1 -> V_17 = F_23 ( & V_21 -> V_24 ) ;
return 0 ;
}
static struct V_1 * F_24 ( struct V_20 * V_19 )
{
struct V_28 * V_29 = V_19 -> V_24 . V_30 ;
struct V_1 * V_1 = NULL ;
struct V_31 * V_32 ;
int V_33 , V_34 ;
V_1 = F_25 ( & V_19 -> V_24 , sizeof( * V_1 ) , V_35 ) ;
if ( ! V_1 ) {
V_34 = - V_36 ;
goto V_37;
}
V_1 -> V_19 = V_19 ;
V_1 -> V_29 = V_29 ;
F_26 ( & V_1 -> V_5 ) ;
V_1 -> V_38 = F_27 ( V_19 , V_29 -> V_39 , L_7 ) ;
if ( F_28 ( V_1 -> V_38 ) ) {
V_34 = F_29 ( V_1 -> V_38 ) ;
goto V_37;
}
V_32 = F_30 ( V_19 , V_40 ,
V_29 -> V_39 ) ;
V_1 -> V_41 = V_32 -> V_42 ;
V_1 -> V_43 = F_27 ( V_19 ,
V_29 -> V_44 , L_8 ) ;
if ( F_28 ( V_1 -> V_43 ) ) {
F_31 ( & V_19 -> V_24 , L_9 ) ;
V_1 -> V_43 = NULL ;
}
V_1 -> V_45 = F_25 ( & V_19 -> V_24 , sizeof( V_1 -> V_45 [ 0 ] ) *
V_29 -> V_46 , V_35 ) ;
if ( ! V_1 -> V_45 ) {
V_34 = - V_36 ;
goto V_37;
}
for ( V_33 = 0 ; V_33 < V_29 -> V_46 ; V_33 ++ ) {
struct V_47 * V_48 ;
V_48 = F_32 ( & V_19 -> V_24 ,
V_29 -> V_49 [ V_33 ] ) ;
if ( F_28 ( V_48 ) ) {
V_34 = F_29 ( V_48 ) ;
F_19 ( & V_19 -> V_24 , L_10 ,
V_29 -> V_49 [ V_33 ] , V_34 ) ;
goto V_37;
}
V_1 -> V_45 [ V_33 ] = V_48 ;
}
V_1 -> V_50 = F_25 ( & V_19 -> V_24 , sizeof( V_1 -> V_50 [ 0 ] ) *
V_29 -> V_51 , V_35 ) ;
if ( ! V_1 -> V_50 ) {
V_34 = - V_36 ;
goto V_37;
}
for ( V_33 = 0 ; V_33 < V_29 -> V_51 ; V_33 ++ ) {
struct V_47 * V_48 ;
V_48 = F_32 ( & V_19 -> V_24 ,
V_29 -> V_52 [ V_33 ] ) ;
if ( F_28 ( V_48 ) ) {
V_34 = F_29 ( V_48 ) ;
F_19 ( & V_19 -> V_24 , L_11 ,
V_29 -> V_52 [ V_33 ] , V_34 ) ;
goto V_37;
}
V_1 -> V_50 [ V_33 ] = V_48 ;
}
V_1 -> V_53 = F_25 ( & V_19 -> V_24 , sizeof( V_1 -> V_53 [ 0 ] ) *
V_29 -> V_54 , V_35 ) ;
if ( ! V_1 -> V_53 ) {
V_34 = - V_36 ;
goto V_37;
}
for ( V_33 = 0 ; V_33 < V_29 -> V_54 ; V_33 ++ ) {
struct V_55 * V_55 ;
V_55 = F_33 ( & V_19 -> V_24 , V_29 -> V_56 [ V_33 ] ) ;
if ( F_28 ( V_55 ) ) {
V_34 = F_29 ( V_55 ) ;
F_19 ( & V_19 -> V_24 , L_12 ,
V_29 -> V_56 [ V_33 ] , V_34 ) ;
goto V_37;
}
V_1 -> V_53 [ V_33 ] = V_55 ;
}
V_1 -> V_57 = F_25 ( & V_19 -> V_24 , sizeof( V_1 -> V_57 [ 0 ] ) *
V_29 -> V_58 , V_35 ) ;
if ( ! V_1 -> V_57 ) {
V_34 = - V_36 ;
goto V_37;
}
for ( V_33 = 0 ; V_33 < V_29 -> V_58 ; V_33 ++ ) {
struct V_55 * V_55 ;
V_55 = F_33 ( & V_19 -> V_24 , V_29 -> V_59 [ V_33 ] ) ;
if ( F_28 ( V_55 ) ) {
V_34 = F_29 ( V_55 ) ;
F_19 ( & V_19 -> V_24 , L_13 ,
V_29 -> V_59 [ V_33 ] , V_34 ) ;
goto V_37;
}
V_1 -> V_57 [ V_33 ] = V_55 ;
}
F_34 ( & V_19 -> V_24 ) ;
V_1 -> V_16 = F_35 ( L_14 , 0 ) ;
V_1 -> V_13 = F_36 ( V_1 ) ;
if ( F_28 ( V_1 -> V_13 ) ) {
V_34 = F_29 ( V_1 -> V_13 ) ;
F_19 ( & V_19 -> V_24 , L_15 , V_34 ) ;
V_1 -> V_13 = NULL ;
goto V_37;
}
V_34 = F_17 ( V_1 ) ;
if ( V_34 ) {
F_19 ( & V_19 -> V_24 , L_16 ) ;
goto V_37;
}
V_1 -> V_14 = F_37 ( V_1 ) ;
if ( F_28 ( V_1 -> V_14 ) ) {
F_38 ( & V_19 -> V_24 , L_17 ) ;
V_1 -> V_14 = NULL ;
}
return V_1 ;
V_37:
if ( V_1 )
F_10 ( V_1 ) ;
return F_39 ( V_34 ) ;
}
int F_40 ( struct V_1 * V_1 ,
struct V_60 * V_24 , struct V_61 * V_62 )
{
struct V_63 * V_64 = V_24 -> V_65 ;
struct V_20 * V_19 = V_1 -> V_19 ;
int V_34 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_62 = V_62 ;
F_41 ( & V_1 -> V_66 . V_67 ) ;
V_1 -> V_68 = F_42 ( V_1 ) ;
if ( F_28 ( V_1 -> V_68 ) ) {
V_34 = F_29 ( V_1 -> V_68 ) ;
F_19 ( V_24 -> V_24 , L_18 , V_34 ) ;
V_1 -> V_68 = NULL ;
goto V_37;
}
V_1 -> V_12 = F_43 ( V_1 ) ;
if ( F_28 ( V_1 -> V_12 ) ) {
V_34 = F_29 ( V_1 -> V_12 ) ;
F_19 ( V_24 -> V_24 , L_19 , V_34 ) ;
V_1 -> V_12 = NULL ;
goto V_37;
}
V_1 -> V_10 = F_44 ( V_19 -> V_24 . V_25 , 0 ) ;
if ( V_1 -> V_10 < 0 ) {
V_34 = V_1 -> V_10 ;
F_19 ( V_24 -> V_24 , L_20 , V_34 ) ;
goto V_37;
}
V_34 = F_45 ( & V_19 -> V_24 , V_1 -> V_10 ,
F_6 , V_69 | V_70 ,
L_21 , V_1 ) ;
if ( V_34 < 0 ) {
F_19 ( V_24 -> V_24 , L_22 ,
V_1 -> V_10 , V_34 ) ;
goto V_37;
}
V_62 -> V_68 = V_1 -> V_68 ;
V_64 -> V_71 [ V_64 -> V_72 ++ ] = V_1 -> V_68 ;
V_64 -> V_73 [ V_64 -> V_74 ++ ] = V_1 -> V_12 ;
F_16 ( V_19 , V_1 ) ;
return 0 ;
V_37:
if ( V_1 -> V_68 ) {
F_46 ( V_1 -> V_68 ) ;
V_1 -> V_68 = NULL ;
}
if ( V_1 -> V_12 ) {
V_1 -> V_12 -> V_75 -> V_76 ( V_1 -> V_12 ) ;
V_1 -> V_12 = NULL ;
}
return V_34 ;
}
static int F_47 ( struct V_22 * V_25 , const char * V_77 )
{
int V_78 ;
V_78 = F_48 ( V_25 , V_77 , 0 ) ;
if ( V_78 < 0 ) {
char V_79 [ 32 ] ;
snprintf ( V_79 , sizeof( V_79 ) , L_23 , V_77 ) ;
V_78 = F_48 ( V_25 , V_79 , 0 ) ;
if ( V_78 < 0 ) {
char V_80 [ 32 ] ;
if ( sscanf ( V_79 , L_24 , V_80 ) )
V_78 = F_48 ( V_25 , V_80 , 0 ) ;
}
if ( V_78 < 0 ) {
F_5 ( L_25 , V_77 , V_78 ) ;
V_78 = - 1 ;
}
}
return V_78 ;
}
static int F_49 ( struct V_81 * V_24 , void * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 )
{
struct V_1 * V_1 = F_50 ( V_24 ) ;
unsigned int V_87 ;
unsigned int V_88 = 0 ;
unsigned int V_89 ;
unsigned int V_90 = 0 ;
bool V_91 = false ;
F_51 ( V_24 , L_26 , V_86 -> V_92 ,
V_86 -> V_93 , V_86 -> V_94 . V_95 ) ;
switch ( V_86 -> V_94 . V_95 ) {
case 2 :
V_88 = 0 ;
V_87 = V_96 ;
break;
case 4 :
V_88 = 0x3 ;
V_87 = V_97 ;
break;
case 6 :
V_88 = 0x0B ;
V_87 = V_98 ;
break;
case 8 :
V_88 = 0x1F ;
V_87 = V_99 ;
break;
default:
return - V_100 ;
}
switch ( V_86 -> V_92 ) {
case 32000 :
V_89 = V_101 ;
break;
case 44100 :
V_89 = V_102 ;
break;
case 48000 :
V_89 = V_103 ;
break;
case 88200 :
V_89 = V_104 ;
break;
case 96000 :
V_89 = V_105 ;
break;
case 176400 :
V_89 = V_106 ;
break;
case 192000 :
V_89 = V_107 ;
break;
default:
F_19 ( V_24 , L_27 ,
V_86 -> V_92 ) ;
return - V_100 ;
}
F_52 ( V_1 , V_89 ) ;
F_53 ( V_1 , 1 , V_87 , V_88 ,
V_90 , V_91 ) ;
return 0 ;
}
static void F_54 ( struct V_81 * V_24 , void * V_82 )
{
struct V_1 * V_1 = F_50 ( V_24 ) ;
F_53 ( V_1 , 0 , 0 , 0 , 0 , 0 ) ;
}
static int F_55 ( struct V_1 * V_1 , struct V_81 * V_24 )
{
V_1 -> V_108 = F_56 ( V_24 ,
V_109 ,
V_110 ,
& V_111 ,
sizeof( V_111 ) ) ;
return F_57 ( V_1 -> V_108 ) ;
}
static int F_58 ( struct V_81 * V_24 , struct V_81 * V_112 , void * V_82 )
{
struct V_60 * V_113 = F_50 ( V_112 ) ;
struct V_63 * V_64 = V_113 -> V_65 ;
static struct V_28 * V_114 ;
struct V_1 * V_1 ;
struct V_22 * V_25 = V_24 -> V_25 ;
int V_33 , V_115 ;
V_114 = (struct V_28 * )
F_59 ( V_24 ) ;
if ( ! V_114 ) {
F_19 ( V_24 , L_28 , V_25 -> V_77 ) ;
return - V_26 ;
}
V_114 -> V_39 = L_29 ;
V_114 -> V_44 = L_30 ;
for ( V_33 = 0 ; V_33 < V_116 ; V_33 ++ ) {
V_114 -> V_117 [ V_33 ] . V_118 = F_47 ( V_25 ,
V_119 [ V_33 ] . V_77 ) ;
V_114 -> V_117 [ V_33 ] . V_120 = V_119 [ V_33 ] . V_120 ;
V_114 -> V_117 [ V_33 ] . V_121 = V_119 [ V_33 ] . V_121 ;
V_114 -> V_117 [ V_33 ] . V_122 = V_119 [ V_33 ] . V_122 ;
}
V_24 -> V_30 = V_114 ;
V_1 = F_24 ( F_60 ( V_24 ) ) ;
if ( F_28 ( V_1 ) )
return F_29 ( V_1 ) ;
V_64 -> V_1 = V_1 ;
V_115 = F_55 ( V_1 , V_24 ) ;
if ( V_115 ) {
F_61 ( L_31 , V_115 ) ;
V_1 -> V_108 = NULL ;
}
return 0 ;
}
static void F_62 ( struct V_81 * V_24 , struct V_81 * V_112 ,
void * V_82 )
{
struct V_60 * V_113 = F_50 ( V_112 ) ;
struct V_63 * V_64 = V_113 -> V_65 ;
if ( V_64 -> V_1 ) {
if ( V_64 -> V_1 -> V_108 )
F_63 ( V_64 -> V_1 -> V_108 ) ;
F_10 ( V_64 -> V_1 ) ;
V_64 -> V_1 = NULL ;
}
}
static int F_64 ( struct V_20 * V_19 )
{
return F_65 ( & V_19 -> V_24 , & V_123 ) ;
}
static int F_66 ( struct V_20 * V_19 )
{
F_67 ( & V_19 -> V_24 , & V_123 ) ;
return 0 ;
}
void T_3 F_68 ( void )
{
F_69 () ;
F_70 ( & V_124 ) ;
}
void T_4 F_71 ( void )
{
F_72 ( & V_124 ) ;
F_73 () ;
}
