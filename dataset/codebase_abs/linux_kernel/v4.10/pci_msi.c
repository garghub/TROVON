static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_7 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
unsigned long V_10 , V_11 ;
int V_12 ;
V_9 = V_6 -> V_13 ;
V_12 = V_9 -> V_14 ( V_6 , V_7 , & V_11 ) ;
if ( F_2 ( V_12 < 0 ) )
goto V_15;
V_10 = V_11 ;
for (; ; ) {
unsigned long V_16 ;
V_12 = V_9 -> V_17 ( V_6 , V_7 , & V_11 , & V_16 ) ;
if ( F_3 ( V_12 > 0 ) ) {
unsigned int V_1 ;
V_1 = V_6 -> V_18 [ V_16 - V_6 -> V_19 ] ;
F_4 ( V_1 ) ;
}
if ( F_2 ( V_12 < 0 ) )
goto V_20;
if ( V_12 == 0 )
break;
}
if ( F_3 ( V_11 != V_10 ) ) {
V_12 = V_9 -> V_21 ( V_6 , V_7 , V_11 ) ;
if ( F_2 ( V_12 < 0 ) )
goto V_22;
}
return V_23 ;
V_15:
F_5 ( V_24 L_1 ,
V_7 , V_12 ) ;
goto V_25;
V_20:
F_5 ( V_24 L_2
L_3 ,
V_11 , V_7 , V_12 ) ;
goto V_25;
V_22:
F_5 ( V_24 L_4
L_3 ,
V_11 , V_7 , V_12 ) ;
goto V_25;
V_25:
return V_26 ;
}
static T_2 F_6 ( struct V_5 * V_6 )
{
static F_7 ( V_27 ) ;
unsigned long V_28 ;
T_2 V_29 , V_30 ;
F_8 ( & V_27 , V_28 ) ;
V_30 = V_6 -> V_31 ;
V_29 = V_6 -> V_32 + V_30 ;
if ( ++ V_30 >= V_6 -> V_33 )
V_30 = 0 ;
V_6 -> V_31 = V_30 ;
F_9 ( & V_27 , V_28 ) ;
return V_29 ;
}
static int F_10 ( struct V_5 * V_6 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 -> V_35 ; V_34 ++ ) {
if ( ! F_11 ( V_34 , V_6 -> V_36 ) )
return V_34 + V_6 -> V_19 ;
}
return - V_37 ;
}
static void F_12 ( struct V_5 * V_6 , int V_35 )
{
V_35 -= V_6 -> V_19 ;
F_13 ( V_35 , V_6 -> V_36 ) ;
}
static int F_14 ( unsigned int * V_38 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = V_40 -> V_43 . V_44 . V_45 ;
const struct V_8 * V_9 = V_6 -> V_13 ;
struct V_46 V_47 ;
int V_16 , V_12 ;
T_2 V_7 ;
* V_38 = F_15 ( 0 , 0 ) ;
V_12 = - V_48 ;
if ( ! * V_38 )
goto V_49;
F_16 ( * V_38 , & V_50 , V_51 ,
L_5 ) ;
V_12 = F_10 ( V_6 ) ;
if ( F_2 ( V_12 < 0 ) )
goto V_52;
V_16 = V_12 ;
V_7 = F_6 ( V_6 ) ;
V_12 = V_9 -> V_53 ( V_6 , V_7 , V_16 ,
( V_42 -> V_54 . V_55 ? 1 : 0 ) ) ;
if ( V_12 )
goto V_56;
V_6 -> V_18 [ V_16 - V_6 -> V_19 ] = * V_38 ;
if ( V_42 -> V_54 . V_55 ) {
V_47 . V_57 = V_6 -> V_58 >> 32 ;
V_47 . V_59 = V_6 -> V_58 & 0xffffffff ;
} else {
V_47 . V_57 = 0 ;
V_47 . V_59 = V_6 -> V_60 ;
}
V_47 . V_61 = V_16 ;
F_17 ( * V_38 , V_42 ) ;
F_18 ( * V_38 , & V_47 ) ;
return 0 ;
V_56:
F_12 ( V_6 , V_16 ) ;
V_52:
F_19 ( * V_38 , NULL ) ;
F_20 ( * V_38 ) ;
* V_38 = 0 ;
V_49:
return V_12 ;
}
static void F_21 ( unsigned int V_1 ,
struct V_39 * V_40 )
{
struct V_5 * V_6 = V_40 -> V_43 . V_44 . V_45 ;
const struct V_8 * V_9 = V_6 -> V_13 ;
unsigned int V_35 ;
int V_34 , V_12 ;
for ( V_34 = 0 ; V_34 < V_6 -> V_35 ; V_34 ++ ) {
if ( V_6 -> V_18 [ V_34 ] == V_1 )
break;
}
if ( V_34 >= V_6 -> V_35 ) {
F_5 ( V_62 L_6 ,
V_6 -> V_63 , V_1 ) ;
return;
}
V_35 = V_6 -> V_19 + V_34 ;
V_6 -> V_18 [ V_34 ] = ~ 0U ;
V_12 = V_9 -> V_64 ( V_6 , V_35 ) ;
if ( V_12 ) {
F_5 ( V_62 L_7
L_8 ,
V_6 -> V_63 , V_35 , V_1 , V_12 ) ;
return;
}
F_12 ( V_6 , V_35 ) ;
F_19 ( V_1 , NULL ) ;
F_20 ( V_1 ) ;
}
static int F_22 ( struct V_5 * V_6 )
{
unsigned long V_65 , V_66 ;
V_66 = sizeof( unsigned long ) * 8 ;
V_65 = ( V_6 -> V_35 + ( V_66 - 1 ) ) & ~ ( V_66 - 1 ) ;
V_65 /= 8 ;
F_23 ( V_65 % sizeof( unsigned long ) ) ;
V_6 -> V_36 = F_24 ( V_65 , V_67 ) ;
if ( ! V_6 -> V_36 )
return - V_48 ;
return 0 ;
}
static void F_25 ( struct V_5 * V_6 )
{
F_26 ( V_6 -> V_36 ) ;
V_6 -> V_36 = NULL ;
}
static int F_27 ( struct V_5 * V_6 )
{
int V_65 , V_34 ;
V_65 = V_6 -> V_33 * sizeof( struct V_3 ) ;
V_6 -> V_68 = F_24 ( V_65 , V_67 ) ;
if ( ! V_6 -> V_68 )
return - V_48 ;
for ( V_34 = 0 ; V_34 < V_6 -> V_33 ; V_34 ++ ) {
struct V_3 * V_69 ;
V_69 = & V_6 -> V_68 [ V_34 ] ;
V_69 -> V_6 = V_6 ;
V_69 -> V_7 = V_6 -> V_32 + V_34 ;
}
V_65 = V_6 -> V_35 * sizeof( unsigned int ) ;
V_6 -> V_18 = F_24 ( V_65 , V_67 ) ;
if ( ! V_6 -> V_18 ) {
F_26 ( V_6 -> V_68 ) ;
V_6 -> V_68 = NULL ;
return - V_48 ;
}
return 0 ;
}
static void F_28 ( struct V_5 * V_6 )
{
F_26 ( V_6 -> V_68 ) ;
V_6 -> V_68 = NULL ;
F_26 ( V_6 -> V_18 ) ;
V_6 -> V_18 = NULL ;
}
static int F_29 ( struct V_5 * V_6 ,
const struct V_8 * V_9 ,
unsigned long V_7 ,
unsigned long V_70 )
{
int V_1 = V_9 -> V_71 ( V_6 , V_7 , V_70 ) ;
int V_12 , V_72 ;
if ( V_1 < 0 )
return V_1 ;
V_72 = V_6 -> V_73 ;
if ( V_72 != - 1 ) {
T_3 V_74 ;
F_30 ( & V_74 , F_31 ( V_72 ) ) ;
F_32 ( V_1 , & V_74 ) ;
}
V_12 = F_33 ( V_1 , F_1 , 0 ,
L_9 ,
& V_6 -> V_68 [ V_7 - V_6 -> V_32 ] ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 ,
const struct V_8 * V_9 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 -> V_33 ; V_34 ++ ) {
unsigned long V_7 = V_34 + V_6 -> V_32 ;
unsigned long V_70 = V_34 + V_6 -> V_75 ;
int V_12 ;
V_12 = F_29 ( V_6 , V_9 , V_7 , V_70 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
void F_35 ( struct V_5 * V_6 ,
const struct V_8 * V_9 )
{
const T_2 * V_76 ;
int V_77 ;
V_76 = F_36 ( V_6 -> V_78 -> V_43 . V_79 , L_10 , & V_77 ) ;
if ( ! V_76 || V_77 != 4 )
goto V_80;
V_6 -> V_33 = * V_76 ;
if ( V_6 -> V_33 ) {
const struct V_81 {
T_2 V_82 ;
T_2 V_83 ;
T_2 V_84 ;
} * V_85 ;
const struct V_86 {
T_2 V_87 ;
T_2 V_88 ;
} * V_89 ;
const struct V_90 {
T_2 V_91 ;
T_2 V_92 ;
T_2 V_93 ;
T_2 V_94 ;
T_2 V_95 ;
T_2 V_96 ;
} * V_97 ;
V_76 = F_36 ( V_6 -> V_78 -> V_43 . V_79 , L_11 , & V_77 ) ;
if ( ! V_76 || V_77 != 4 )
goto V_80;
V_6 -> V_98 = * V_76 ;
V_85 = F_36 ( V_6 -> V_78 -> V_43 . V_79 ,
L_12 , & V_77 ) ;
if ( ! V_85 )
V_85 = F_36 ( V_6 -> V_78 -> V_43 . V_79 ,
L_13 , & V_77 ) ;
if ( ! V_85 || V_77 != sizeof( struct V_81 ) )
goto V_80;
V_6 -> V_32 = V_85 -> V_82 ;
V_6 -> V_75 = V_85 -> V_84 ;
V_76 = F_36 ( V_6 -> V_78 -> V_43 . V_79 , L_14 , & V_77 ) ;
if ( ! V_76 || V_77 != 4 )
goto V_80;
V_6 -> V_35 = * V_76 ;
V_89 = F_36 ( V_6 -> V_78 -> V_43 . V_79 , L_15 , & V_77 ) ;
if ( ! V_89 || V_77 != sizeof( struct V_86 ) )
goto V_80;
V_6 -> V_19 = V_89 -> V_87 ;
V_76 = F_36 ( V_6 -> V_78 -> V_43 . V_79 , L_16 , & V_77 ) ;
if ( ! V_76 || V_77 != 4 )
goto V_80;
V_6 -> V_99 = * V_76 ;
V_76 = F_36 ( V_6 -> V_78 -> V_43 . V_79 , L_17 , & V_77 ) ;
if ( ! V_76 || V_77 != 4 )
goto V_80;
V_6 -> V_100 = * V_76 ;
V_97 = F_36 ( V_6 -> V_78 -> V_43 . V_79 , L_18 ,
& V_77 ) ;
if ( ! V_97 || V_77 != sizeof( struct V_90 ) )
goto V_80;
V_6 -> V_60 = ( ( V_101 ) V_97 -> V_91 << 32 ) |
( V_101 ) V_97 -> V_92 ;
V_6 -> V_58 = ( ( V_101 ) V_97 -> V_94 << 32 ) |
( V_101 ) V_97 -> V_95 ;
V_6 -> V_93 = V_97 -> V_93 ;
V_6 -> V_96 = V_97 -> V_96 ;
if ( F_22 ( V_6 ) )
goto V_80;
if ( F_27 ( V_6 ) ) {
F_25 ( V_6 ) ;
goto V_80;
}
if ( V_9 -> V_102 ( V_6 ) ) {
F_28 ( V_6 ) ;
F_25 ( V_6 ) ;
goto V_80;
}
if ( F_34 ( V_6 , V_9 ) ) {
V_9 -> V_103 ( V_6 ) ;
F_28 ( V_6 ) ;
F_25 ( V_6 ) ;
goto V_80;
}
F_5 ( V_104 L_19
L_20 ,
V_6 -> V_63 ,
V_6 -> V_32 , V_6 -> V_33 ,
V_6 -> V_98 ,
V_6 -> V_75 ) ;
F_5 ( V_104 L_21
L_22 ,
V_6 -> V_63 ,
V_6 -> V_19 , V_6 -> V_35 , V_6 -> V_99 ,
V_6 -> V_100 ) ;
F_5 ( V_104 L_23
L_24 ,
V_6 -> V_63 ,
V_6 -> V_60 , V_6 -> V_93 ,
V_6 -> V_58 , V_6 -> V_96 ) ;
F_5 ( V_104 L_25 ,
V_6 -> V_63 ,
F_37 ( V_6 -> V_105 ) ) ;
V_6 -> V_13 = V_9 ;
V_6 -> V_106 = F_14 ;
V_6 -> V_107 = F_21 ;
}
return;
V_80:
V_6 -> V_33 = 0 ;
F_5 ( V_104 L_26 , V_6 -> V_63 ) ;
}
