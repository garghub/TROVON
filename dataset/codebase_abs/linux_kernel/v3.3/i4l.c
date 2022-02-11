static int F_1 ( int V_1 , int V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_1 ) ;
struct V_8 * V_9 ;
unsigned char * V_10 ;
unsigned V_11 ;
if ( ! V_7 ) {
F_3 ( L_1 , V_12 , V_1 ) ;
return - V_13 ;
}
if ( V_2 < 0 || V_2 >= V_7 -> V_14 ) {
F_4 ( V_7 -> V_15 , L_2 ,
V_12 , V_2 ) ;
return - V_13 ;
}
V_9 = & V_7 -> V_9 [ V_2 ] ;
if ( F_5 ( V_5 ) < 0 ) {
F_4 ( V_7 -> V_15 , L_3 , V_12 ) ;
return - V_16 ;
}
V_11 = V_5 -> V_11 ;
F_6 ( V_17 ,
L_4 ,
V_1 , V_2 , V_3 , V_11 ) ;
if ( ! V_11 ) {
if ( V_3 )
F_7 ( V_7 -> V_15 , L_5 ,
V_12 ) ;
return 0 ;
}
if ( V_11 > V_18 ) {
F_4 ( V_7 -> V_15 , L_6 ,
V_12 , V_11 ) ;
return - V_19 ;
}
if ( F_8 ( V_5 ) < V_20 ) {
F_4 ( V_7 -> V_15 , L_7 , V_12 ) ;
return - V_16 ;
}
F_9 ( V_5 , - V_20 ) ;
V_5 -> V_21 = V_20 ;
V_10 = F_10 ( V_5 ) ;
if ( V_3 ) {
V_10 [ 0 ] = V_11 & 0xff ;
V_10 [ 1 ] = V_11 >> 8 ;
} else {
V_10 [ 0 ] = V_10 [ 1 ] = 0 ;
}
F_6 ( V_22 , L_8 ,
V_11 , V_3 , V_10 [ 0 ] , V_10 [ 1 ] ) ;
return V_7 -> V_23 -> V_24 ( V_9 , V_5 ) ;
}
void F_11 ( struct V_8 * V_9 , struct V_4 * V_5 )
{
T_1 * V_25 = V_9 -> V_7 -> V_25 ;
unsigned char * V_10 = F_10 ( V_5 ) ;
unsigned V_11 ;
T_2 V_26 ;
++ V_9 -> V_27 ;
if ( V_5 -> V_11 )
F_12 ( V_9 -> V_7 -> V_15 , L_9 ,
V_12 , V_5 -> V_11 ) ;
V_11 = V_10 [ 0 ] + ( ( unsigned ) V_10 [ 1 ] << 8 ) ;
if ( V_11 ) {
F_6 ( V_22 , L_10 ,
V_9 -> V_7 -> V_28 , V_9 -> V_2 , V_11 ) ;
V_26 . V_29 = V_9 -> V_7 -> V_28 ;
V_26 . V_30 = V_31 ;
V_26 . V_32 = V_9 -> V_2 ;
V_26 . V_33 . V_34 = V_11 ;
V_25 -> V_35 ( & V_26 ) ;
}
}
void F_13 ( struct V_8 * V_9 , struct V_4 * V_5 )
{
T_1 * V_25 = V_9 -> V_7 -> V_25 ;
V_25 -> V_36 ( V_9 -> V_7 -> V_28 , V_9 -> V_2 , V_5 ) ;
V_9 -> V_37 ++ ;
}
void F_14 ( struct V_8 * V_9 )
{
T_1 * V_25 = V_9 -> V_7 -> V_25 ;
T_2 V_26 ;
if ( V_9 -> V_38 ) {
V_9 -> V_38 -- ;
return;
}
V_9 -> V_39 ++ ;
F_6 ( V_40 , L_11 ) ;
V_26 . V_29 = V_9 -> V_7 -> V_28 ;
V_26 . V_30 = V_41 ;
V_26 . V_32 = V_9 -> V_2 ;
V_26 . V_33 . V_42 = V_43 ;
V_25 -> V_35 ( & V_26 ) ;
}
static int F_15 ( T_2 * V_44 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_45 = 0 ;
char * * V_46 ;
int V_47 ;
int V_48 ;
T_3 V_49 ;
F_6 ( V_40 , L_12 ,
V_44 -> V_29 , V_44 -> V_30 , V_44 -> V_32 ) ;
V_7 = F_2 ( V_44 -> V_29 ) ;
if ( V_7 == NULL ) {
F_3 ( L_1 , V_12 , V_44 -> V_29 ) ;
return - V_13 ;
}
V_47 = V_44 -> V_32 & 0xff ;
switch ( V_44 -> V_30 ) {
case V_50 :
F_12 ( V_7 -> V_15 , L_13 ) ;
return - V_19 ;
case V_51 :
F_6 ( V_40 ,
L_14 ,
V_44 -> V_33 . V_52 . V_53 , V_44 -> V_33 . V_52 . V_54 ,
V_44 -> V_33 . V_52 . V_55 , V_44 -> V_33 . V_52 . V_56 ) ;
if ( V_47 >= V_7 -> V_14 ) {
F_4 ( V_7 -> V_15 ,
L_15 , V_47 ) ;
return - V_19 ;
}
V_9 = V_7 -> V_9 + V_47 ;
if ( ! F_16 ( V_9 ) ) {
F_4 ( V_7 -> V_15 , L_16 ) ;
return - V_57 ;
}
switch ( V_9 -> V_58 ) {
case V_59 :
V_9 -> V_60 = V_61 ;
break;
default:
V_9 -> V_60 = V_62 ;
}
F_17 ( V_9 -> V_63 ) ;
F_18 ( V_9 ) ;
V_46 = F_19 ( V_64 * ( sizeof *V_46 ) , V_65 ) ;
if ( ! V_46 ) {
F_20 ( V_9 ) ;
F_4 ( V_7 -> V_15 , L_17 ) ;
return - V_16 ;
}
V_49 = 3 + strlen ( V_44 -> V_33 . V_52 . V_53 ) ;
V_46 [ V_66 ] = F_21 ( V_49 , V_65 ) ;
if ( ! V_46 [ V_66 ] )
goto V_67;
if ( V_44 -> V_33 . V_52 . V_53 [ 0 ] == '*' &&
V_44 -> V_33 . V_52 . V_53 [ 1 ] == '*' ) {
V_46 [ V_68 ] = F_22 ( L_18 , V_65 ) ;
if ( ! V_46 [ V_68 ] )
goto V_67;
snprintf ( V_46 [ V_66 ] , V_49 ,
L_19 , V_44 -> V_33 . V_52 . V_53 + 2 ) ;
} else {
V_46 [ V_68 ] = F_22 ( L_20 , V_65 ) ;
if ( ! V_46 [ V_68 ] )
goto V_67;
snprintf ( V_46 [ V_66 ] , V_49 ,
L_19 , V_44 -> V_33 . V_52 . V_53 ) ;
}
V_49 = strlen ( V_44 -> V_33 . V_52 . V_54 ) ;
if ( V_49 ) {
V_49 += 8 ;
V_46 [ V_69 ] = F_21 ( V_49 , V_65 ) ;
if ( ! V_46 [ V_69 ] )
goto V_67;
snprintf ( V_46 [ V_69 ] , V_49 , L_21 ,
V_44 -> V_33 . V_52 . V_54 ) ;
}
switch ( V_44 -> V_33 . V_52 . V_55 ) {
case 1 :
V_46 [ V_70 ] = F_22 ( L_22 , V_65 ) ;
if ( ! V_46 [ V_70 ] )
goto V_67;
break;
case 7 :
default:
V_46 [ V_70 ] = F_22 ( L_23 , V_65 ) ;
if ( ! V_46 [ V_70 ] )
goto V_67;
}
V_46 [ V_71 ] = F_21 ( 9 , V_65 ) ;
if ( ! V_46 [ V_71 ] )
goto V_67;
snprintf ( V_46 [ V_71 ] , 9 , L_24 , V_9 -> V_58 ) ;
V_46 [ V_72 ] = F_21 ( 9 , V_65 ) ;
if ( ! V_46 [ V_72 ] )
goto V_67;
snprintf ( V_46 [ V_72 ] , 9 , L_25 ,
( unsigned ) V_9 -> V_2 + 1 ) ;
if ( ! F_23 ( V_7 , & V_9 -> V_73 , V_74 , V_46 ,
V_9 -> V_73 . V_75 , NULL ) ) {
for ( V_48 = 0 ; V_48 < V_64 ; ++ V_48 )
F_24 ( V_46 [ V_48 ] ) ;
F_24 ( V_46 ) ;
F_20 ( V_9 ) ;
return - V_16 ;
}
F_25 ( V_7 ) ;
break;
case V_76 :
F_6 ( V_40 , L_26 ) ;
if ( V_47 >= V_7 -> V_14 ) {
F_4 ( V_7 -> V_15 ,
L_27 , V_47 ) ;
return - V_19 ;
}
V_9 = V_7 -> V_9 + V_47 ;
switch ( V_9 -> V_58 ) {
case V_59 :
V_9 -> V_60 = V_61 ;
break;
default:
V_9 -> V_60 = V_62 ;
}
F_17 ( V_9 -> V_63 ) ;
F_18 ( V_9 ) ;
if ( ! F_23 ( V_7 , & V_9 -> V_73 ,
V_77 , NULL , 0 , NULL ) )
return - V_16 ;
F_25 ( V_7 ) ;
break;
case V_78 :
F_6 ( V_40 , L_28 ) ;
if ( V_47 >= V_7 -> V_14 ) {
F_4 ( V_7 -> V_15 ,
L_29 , V_47 ) ;
return - V_19 ;
}
V_9 = V_7 -> V_9 + V_47 ;
if ( ! F_23 ( V_7 , & V_9 -> V_73 ,
V_79 , NULL , 0 , NULL ) )
return - V_16 ;
F_25 ( V_7 ) ;
break;
case V_80 :
F_26 ( V_7 -> V_15 , L_30 ) ;
break;
case V_81 :
F_26 ( V_7 -> V_15 , L_31 ,
V_44 -> V_33 . V_82 ) ;
break;
case V_83 :
if ( V_47 >= V_7 -> V_14 ) {
F_4 ( V_7 -> V_15 ,
L_32 , V_47 ) ;
return - V_19 ;
}
V_9 = V_7 -> V_9 + V_47 ;
if ( V_9 -> V_84 & V_85 ) {
F_4 ( V_7 -> V_15 ,
L_33 , V_47 ) ;
return - V_19 ;
}
switch ( V_44 -> V_32 >> 8 ) {
case V_86 :
F_6 ( V_40 , L_34 ) ;
V_9 -> V_58 = V_59 ;
break;
case V_87 :
F_6 ( V_40 , L_35 ) ;
V_9 -> V_58 = V_88 ;
break;
default:
F_4 ( V_7 -> V_15 ,
L_36 ,
V_44 -> V_32 >> 8 ) ;
return - V_19 ;
}
break;
case V_89 :
F_6 ( V_40 , L_37 ) ;
if ( V_47 >= V_7 -> V_14 ) {
F_4 ( V_7 -> V_15 ,
L_38 , V_47 ) ;
return - V_19 ;
}
if ( V_44 -> V_32 >> 8 != V_90 ) {
F_4 ( V_7 -> V_15 ,
L_39 ,
V_44 -> V_32 >> 8 ) ;
return - V_19 ;
}
break;
default:
F_6 ( V_40 , L_40 ,
V_44 -> V_30 ) ;
return - V_19 ;
}
return V_45 ;
V_67:
F_4 ( V_9 -> V_7 -> V_15 , L_41 ) ;
for ( V_48 = 0 ; V_48 < V_64 ; ++ V_48 )
F_24 ( V_46 [ V_48 ] ) ;
F_24 ( V_46 ) ;
F_20 ( V_9 ) ;
return - V_16 ;
}
static void F_27 ( struct V_6 * V_7 , int V_91 )
{
T_1 * V_25 = V_7 -> V_25 ;
T_2 V_30 ;
V_30 . V_29 = V_7 -> V_28 ;
V_30 . V_30 = V_91 ;
V_30 . V_32 = 0 ;
V_25 -> V_35 ( & V_30 ) ;
}
static void F_28 ( struct V_8 * V_9 , int V_91 )
{
T_1 * V_25 = V_9 -> V_7 -> V_25 ;
T_2 V_30 ;
V_30 . V_29 = V_9 -> V_7 -> V_28 ;
V_30 . V_30 = V_91 ;
V_30 . V_32 = V_9 -> V_2 ;
V_25 -> V_35 ( & V_30 ) ;
}
int F_29 ( struct V_92 * V_73 )
{
struct V_6 * V_7 = V_73 -> V_7 ;
struct V_8 * V_9 = V_73 -> V_9 ;
T_1 * V_25 = V_7 -> V_25 ;
T_2 V_26 ;
int V_45 ;
V_26 . V_33 . V_52 . V_55 = 0 ;
V_26 . V_33 . V_52 . V_56 = 0 ;
V_26 . V_33 . V_52 . V_93 = 0 ;
V_26 . V_33 . V_52 . V_94 = 0 ;
if ( ! V_73 -> V_95 [ V_96 ] ) {
V_26 . V_33 . V_52 . V_55 = 1 ;
} else if ( ! strcmp ( V_73 -> V_95 [ V_96 ] , L_42 ) ) {
V_26 . V_33 . V_52 . V_55 = 7 ;
} else if ( ! strcmp ( V_73 -> V_95 [ V_96 ] , L_43 ) ) {
V_26 . V_33 . V_52 . V_55 = 1 ;
} else if ( ! strcmp ( V_73 -> V_95 [ V_96 ] , L_44 ) ) {
V_26 . V_33 . V_52 . V_55 = 1 ;
V_26 . V_33 . V_52 . V_56 = 2 ;
} else {
F_12 ( V_7 -> V_15 , L_45 ,
V_73 -> V_95 [ V_96 ] ) ;
return V_97 ;
}
if ( V_73 -> V_95 [ V_98 ] ) {
F_30 ( V_26 . V_33 . V_52 . V_53 , V_73 -> V_95 [ V_98 ] ,
sizeof V_26 . V_33 . V_52 . V_53 ) ;
} else
V_26 . V_33 . V_52 . V_53 [ 0 ] = 0 ;
if ( V_73 -> V_95 [ V_99 ] ) {
F_30 ( V_26 . V_33 . V_52 . V_54 , V_73 -> V_95 [ V_99 ] ,
sizeof V_26 . V_33 . V_52 . V_54 ) ;
} else
V_26 . V_33 . V_52 . V_54 [ 0 ] = 0 ;
if ( ! V_9 ) {
F_7 ( V_7 -> V_15 , L_46 ) ;
V_26 . V_30 = V_100 ;
V_26 . V_32 = 0 ;
} else {
F_6 ( V_40 , L_47 ) ;
V_26 . V_30 = V_101 ;
V_26 . V_32 = V_9 -> V_2 ;
}
V_26 . V_29 = V_7 -> V_28 ;
V_45 = V_25 -> V_35 ( & V_26 ) ;
F_6 ( V_40 , L_48 , V_45 ) ;
switch ( V_45 ) {
case 0 :
return V_97 ;
case 1 :
V_9 -> V_84 |= V_102 ;
return V_103 ;
case 2 :
return V_104 ;
case 3 :
F_12 ( V_7 -> V_15 ,
L_49 ) ;
return V_97 ;
case 4 :
return V_103 ;
case 5 :
F_12 ( V_7 -> V_15 ,
L_50 ) ;
return V_97 ;
default:
F_4 ( V_7 -> V_15 , L_51 , V_45 ) ;
return V_97 ;
}
}
void F_31 ( struct V_8 * V_9 )
{
F_6 ( V_40 , L_52 ) ;
F_28 ( V_9 , V_105 ) ;
}
void F_32 ( struct V_8 * V_9 )
{
F_6 ( V_40 , L_53 ) ;
F_28 ( V_9 , V_106 ) ;
}
void F_33 ( struct V_8 * V_9 )
{
F_6 ( V_40 , L_54 ) ;
F_28 ( V_9 , V_107 ) ;
}
void F_34 ( struct V_8 * V_9 )
{
F_6 ( V_40 , L_55 ) ;
F_28 ( V_9 , V_108 ) ;
}
void F_35 ( struct V_6 * V_7 )
{
F_6 ( V_40 , L_56 ) ;
F_27 ( V_7 , V_109 ) ;
}
void F_36 ( struct V_6 * V_7 )
{
F_6 ( V_40 , L_57 ) ;
F_27 ( V_7 , V_110 ) ;
}
int F_37 ( struct V_6 * V_7 , const char * V_111 )
{
T_1 * V_25 ;
V_25 = F_21 ( sizeof *V_25 , V_112 ) ;
if ( ! V_25 ) {
F_3 ( L_41 ) ;
return 0 ;
}
if ( snprintf ( V_25 -> V_113 , sizeof V_25 -> V_113 , L_58 , V_111 , V_7 -> V_114 )
>= sizeof V_25 -> V_113 ) {
F_3 ( L_59 , V_111 ) ;
F_24 ( V_25 ) ;
return 0 ;
}
V_25 -> V_115 = V_116 ;
V_25 -> V_14 = V_7 -> V_14 ;
V_25 -> V_117 = V_18 ;
V_25 -> V_118 = V_119 |
V_120 |
V_121 |
V_122 |
V_123 ;
V_25 -> V_124 = V_20 ;
V_25 -> V_30 = F_15 ;
V_25 -> V_125 = F_1 ;
V_25 -> V_126 = NULL ;
V_25 -> V_127 = NULL ;
V_25 -> V_36 = NULL ;
V_25 -> V_35 = NULL ;
if ( ! F_38 ( V_25 ) ) {
F_3 ( L_60 ) ;
F_24 ( V_25 ) ;
return 0 ;
}
V_7 -> V_25 = V_25 ;
V_7 -> V_28 = V_25 -> V_14 ;
V_7 -> V_128 = V_20 ;
return 1 ;
}
void F_39 ( struct V_6 * V_7 )
{
F_6 ( V_40 , L_61 ) ;
F_27 ( V_7 , V_129 ) ;
F_24 ( V_7 -> V_25 ) ;
V_7 -> V_25 = NULL ;
}
void F_40 ( void )
{
F_41 ( L_62 ) ;
}
void F_42 ( void )
{
}
