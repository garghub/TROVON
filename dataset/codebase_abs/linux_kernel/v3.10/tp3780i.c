static void F_1 ( T_1 * V_1 )
{
T_2 * V_2 = & V_1 -> V_3 ;
unsigned short V_4 = V_2 -> V_4 ;
T_3 V_5 ;
T_4 V_6 ;
T_5 V_7 ;
F_2 ( V_8 , L_1 ) ;
F_3 ( V_7 ) = F_4 ( V_9 ) ;
V_7 . V_10 = 0 ;
F_5 ( V_9 , F_3 ( V_7 ) ) ;
F_3 ( V_6 ) = 0 ;
V_6 . V_11 = TRUE ;
V_6 . V_12 = TRUE ;
F_5 ( V_13 , F_3 ( V_6 ) ) ;
F_3 ( V_5 ) = 0 ;
V_5 . V_14 = 0 ;
V_5 . V_12 = TRUE ;
F_5 ( V_15 , F_3 ( V_5 ) ) ;
F_2 ( V_8 , L_2 ) ;
}
static T_6 F_6 ( int V_16 , void * V_17 )
{
F_7 ( V_8 ,
L_3 , V_16 , V_17 ) ;
return V_18 ;
}
static T_6 F_8 ( int V_16 , void * V_17 )
{
T_7 V_19 = & V_20 ;
T_2 * V_2 = & V_19 -> V_21 . V_3 ;
unsigned short V_4 = V_2 -> V_4 ;
unsigned short V_22 = 0 , V_23 , V_24 ;
F_7 ( V_8 ,
L_4 , V_16 , V_17 ) ;
if ( F_9 ( V_4 , & V_22 ) == 0 ) {
F_10 ( V_8 ,
L_5 ,
V_22 ) ;
V_23 = 1 ;
for ( V_24 = 1 ; V_24 <= 16 ; V_24 ++ ) {
if ( V_22 & V_23 ) {
V_22 &= ~ V_23 ;
F_7 ( V_8 ,
L_6 ,
V_24 , V_22 ) ;
if ( V_19 -> V_25 [ V_24 - 1 ] . V_26 == 0 ) {
V_19 -> V_25 [ V_24 - 1 ] . V_26 = 1 ;
}
F_10 ( V_8 ,
L_7 ,
V_19 -> V_25 [ V_24 - 1 ] . V_26 ) ;
if ( V_19 -> V_25 [ V_24 - 1 ] . V_27 == TRUE ) {
F_10 ( V_8 ,
L_8 ,
V_24 - 1 ) ;
F_11 ( & V_19 -> V_25 [ V_24 - 1 ] . V_28 ) ;
} else {
F_10 ( V_8 ,
L_9 ,
V_24 - 1 ) ;
}
}
if ( V_22 == 0 )
break;
V_23 = V_23 << 1 ;
}
} else {
F_2 ( V_8 ,
L_10 ) ;
}
F_2 ( V_8 , L_11 ) ;
return V_18 ;
}
int F_12 ( T_1 * V_1 )
{
int V_29 = 0 ;
T_2 * V_2 = & V_1 -> V_3 ;
F_10 ( V_8 , L_12 , V_1 ) ;
V_1 -> V_30 = FALSE ;
V_2 -> V_31 = FALSE ;
V_29 = F_13 () ;
if ( V_29 ) {
F_14 ( V_32 L_13 ) ;
} else {
if ( V_33 || V_34 || V_35 || V_36 ) {
V_29 = F_15 () ;
}
}
F_10 ( V_8 , L_14 , V_29 ) ;
return V_29 ;
}
int F_16 ( T_1 * V_1 )
{
int V_29 = 0 ;
F_10 ( V_8 ,
L_15 , V_1 ) ;
return V_29 ;
}
int F_17 ( T_1 * V_1 )
{
T_8 V_37 ;
T_2 * V_2 = & V_1 -> V_3 ;
F_10 ( V_8 ,
L_16 , V_1 ) ;
if ( F_18 ( & V_37 ) ) {
F_14 ( V_32 L_17 ) ;
return - V_38 ;
}
if (
( V_37 . V_39 == 0 )
|| ( V_37 . V_4 == 0 )
|| ( V_37 . V_40 == 0 )
|| ( V_37 . V_41 == 0 )
) {
F_14 ( V_32 L_18 ) ;
return - V_38 ;
}
V_2 -> V_30 = ( V_37 . V_30 && V_37 . V_42 ) ;
V_2 -> V_43 = V_37 . V_43 ;
V_2 -> V_44 = V_37 . V_39 ;
V_2 -> V_45 = V_37 . V_46 ;
V_2 -> V_4 = V_37 . V_4 ;
V_2 -> V_47 = V_37 . V_40 ;
V_2 -> V_41 = V_37 . V_41 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = V_51 ;
V_2 -> V_52 = V_53 ;
if ( V_2 -> V_30 && V_2 -> V_43 && V_2 -> V_44 == V_2 -> V_47 ) {
V_1 -> V_54 = V_1 -> V_55 = 1 ;
} else {
V_1 -> V_54 = V_1 -> V_55 = 0 ;
}
F_2 ( V_8 , L_19 ) ;
return 0 ;
}
int F_19 ( T_1 * V_1 )
{
int V_29 = 0 ;
T_2 * V_2 = & V_1 -> V_3 ;
struct V_56 * V_57 ;
F_10 ( V_8 ,
L_20 , V_1 ) ;
V_57 = F_20 ( V_2 -> V_4 , 16 , L_21 ) ;
if ( V_57 == NULL ) V_29 = - V_38 ;
if ( V_29 ) {
F_14 ( V_32 L_22 , V_2 -> V_4 ) ;
V_29 = - V_38 ;
}
F_10 ( V_8 , L_23 , V_29 ) ;
return V_29 ;
}
int F_21 ( T_1 * V_1 )
{
int V_29 = 0 ;
T_2 * V_2 = & V_1 -> V_3 ;
F_10 ( V_8 ,
L_24 , V_1 ) ;
F_22 ( V_2 -> V_4 & ( ~ 3 ) , 16 ) ;
if ( V_2 -> V_31 ) {
F_23 ( V_2 -> V_44 , NULL ) ;
V_2 -> V_31 = FALSE ;
}
F_10 ( V_8 ,
L_25 , V_29 ) ;
return V_29 ;
}
int F_24 ( T_1 * V_1 )
{
T_2 * V_2 = & V_1 -> V_3 ;
BOOLEAN V_58 = FALSE , V_59 = FALSE ;
F_10 ( V_8 , L_26 , V_1 ) ;
if ( V_1 -> V_30 ) {
F_14 ( V_32 L_27 ) ;
goto V_60;
}
if ( ! V_2 -> V_30 ) {
F_14 ( V_32 L_28 ) ;
goto V_60;
}
if (
( V_2 -> V_44 >= V_61 )
|| ( V_2 -> V_45 >= V_62 )
|| ( V_63 [ V_2 -> V_44 ] == 0xFFFF )
|| ( V_64 [ V_2 -> V_45 ] == 0xFFFF )
) {
F_14 ( V_32 L_29 , V_2 -> V_44 ) ;
goto V_60;
}
if (
( ( V_2 -> V_4 & 0xF00F ) != 0 )
|| ( V_2 -> V_4 & 0x0FF0 ) == 0
) {
F_14 ( V_32 L_30 , V_2 -> V_4 ) ;
goto V_60;
}
if ( V_2 -> V_43 ) {
if (
V_2 -> V_47 >= V_61
|| V_63 [ V_2 -> V_47 ] == 0xFFFF
) {
F_14 ( V_32 L_31 , V_2 -> V_47 ) ;
goto V_60;
}
switch ( V_2 -> V_41 ) {
case 0x03F8 :
case 0x02F8 :
case 0x03E8 :
case 0x02E8 :
break;
default:
F_14 ( L_32 , V_2 -> V_41 ) ;
goto V_60;
}
}
V_2 -> V_65 = V_2 -> V_66 = TRUE ;
V_2 -> V_67 = V_2 -> V_68 = TRUE ;
if ( V_1 -> V_54 ) {
V_2 -> V_65 = FALSE ;
}
if ( V_1 -> V_55 ) {
V_2 -> V_67 = FALSE ;
}
V_2 -> V_69 = V_70 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = V_78 ;
V_2 -> V_79 = V_80 ;
V_2 -> V_81 = V_82 ;
V_2 -> V_83 = V_84 ;
V_2 -> V_85 = V_86 ;
V_2 -> V_87 = V_88 ;
V_2 -> V_89 = V_90 ;
V_2 -> V_91 = V_92 ;
if ( F_25 ( V_2 -> V_47 , & F_6 , 0 , L_33 , NULL ) ) {
F_14 ( V_32 L_34 , V_2 -> V_47 ) ;
goto V_60;
} else {
F_23 ( V_2 -> V_47 , NULL ) ;
}
if ( F_25 ( V_2 -> V_44 , & F_8 , 0 , L_21 , NULL ) ) {
F_14 ( L_35 , V_2 -> V_44 ) ;
goto V_60;
} else {
F_7 ( V_8 ,
L_36 ,
V_2 -> V_44 , V_1 -> V_54 ) ;
V_59 = TRUE ;
V_2 -> V_31 = TRUE ;
}
F_26 ( FALSE ) ;
if ( F_26 ( TRUE ) ) {
F_14 ( V_32 L_37 ) ;
goto V_60;
} else {
V_58 = TRUE ;
}
if ( F_27 ( V_2 , V_63 , V_64 ) ) {
F_14 ( L_38 ) ;
goto V_60;
}
F_1 ( V_1 ) ;
V_1 -> V_30 = TRUE ;
F_2 ( V_8 , L_39 ) ;
return 0 ;
V_60:
F_14 ( L_40 ) ;
if ( V_58 )
F_26 ( FALSE ) ;
if ( V_59 ) {
F_23 ( V_2 -> V_44 , NULL ) ;
V_2 -> V_31 = FALSE ;
}
return - V_38 ;
}
int F_28 ( T_1 * V_1 )
{
int V_29 = 0 ;
T_2 * V_2 = & V_1 -> V_3 ;
F_10 ( V_8 , L_41 , V_1 ) ;
if ( V_1 -> V_30 ) {
F_29 ( & V_1 -> V_3 ) ;
if ( V_2 -> V_31 ) {
F_23 ( V_2 -> V_44 , NULL ) ;
V_2 -> V_31 = FALSE ;
}
F_26 ( FALSE ) ;
V_1 -> V_30 = FALSE ;
}
F_10 ( V_8 , L_42 , V_29 ) ;
return V_29 ;
}
int F_30 ( T_1 * V_1 )
{
int V_29 = 0 ;
T_2 * V_2 = & V_1 -> V_3 ;
F_10 ( V_8 , L_43 ,
V_1 ) ;
if ( F_31 ( V_2 ) == 0 ) {
F_1 ( V_1 ) ;
} else {
V_29 = - V_38 ;
}
F_10 ( V_8 , L_44 , V_29 ) ;
return V_29 ;
}
int F_32 ( T_1 * V_1 )
{
int V_29 = 0 ;
T_2 * V_2 = & V_1 -> V_3 ;
F_10 ( V_8 , L_45 , V_1 ) ;
if ( F_33 ( V_2 ) == 0 ) {
} else {
V_29 = - V_38 ;
}
F_10 ( V_8 , L_46 , V_29 ) ;
return V_29 ;
}
int F_34 ( T_1 * V_1 , T_9 * V_93 )
{
int V_29 = 0 ;
F_10 ( V_8 ,
L_47 , V_1 ) ;
V_93 -> V_94 = V_1 -> V_3 . V_52 ;
V_93 -> V_95 = V_1 -> V_3 . V_48 ;
V_93 -> V_96 = V_1 -> V_3 . V_50 ;
V_93 -> V_97 = V_1 -> V_3 . V_98 ;
V_93 -> V_99 [ 0 ] = 0x00010000 | V_100 ;
V_93 -> V_99 [ 1 ] = 0x00010000 | V_101 ;
V_93 -> V_99 [ 2 ] = 0x00010000 | V_102 ;
V_93 -> V_99 [ 3 ] = 0x00010000 | V_103 ;
V_93 -> V_99 [ 4 ] = 0x00010000 | V_104 ;
V_93 -> V_99 [ 5 ] = 0x00010000 | V_105 ;
V_93 -> V_99 [ 6 ] = 0x00010000 | V_106 ;
V_93 -> V_107 = 7 ;
memcpy ( V_93 -> V_108 , V_109 ,
sizeof( V_109 ) ) ;
memcpy ( V_93 -> V_110 , V_111 ,
sizeof( V_111 ) ) ;
F_2 ( V_8 ,
L_48 ) ;
return V_29 ;
}
int F_35 ( T_1 * V_1 , unsigned int V_112 ,
void T_10 * V_113 , unsigned int V_114 ,
unsigned long V_115 )
{
int V_29 = 0 ;
T_2 * V_2 = & V_1 -> V_3 ;
unsigned short V_4 = V_2 -> V_4 ;
BOOLEAN V_116 = 0 ;
F_36 ( V_8 ,
L_49 ,
V_1 , V_112 , V_113 , V_114 , V_115 ) ;
if ( V_1 -> V_30 ) {
switch ( V_112 ) {
case V_117 :
V_116 = F_37 ( V_4 , V_113 , V_114 , V_115 ) ;
break;
case V_118 :
V_116 = F_38 ( V_4 , V_113 , V_114 , V_115 ) ;
break;
case V_119 :
V_116 = F_39 ( V_4 , V_113 , V_114 , V_115 ) ;
break;
}
}
V_29 = ( V_116 ) ? - V_38 : 0 ;
F_10 ( V_8 , L_50 , V_29 ) ;
return V_29 ;
}
int F_40 ( T_1 * V_1 , unsigned int V_112 ,
void T_10 * V_113 , unsigned int V_114 ,
unsigned long V_115 )
{
int V_29 = 0 ;
T_2 * V_2 = & V_1 -> V_3 ;
unsigned short V_4 = V_2 -> V_4 ;
BOOLEAN V_116 = 0 ;
F_36 ( V_8 ,
L_51 ,
V_1 , V_112 , V_113 , V_114 , V_115 ) ;
if ( V_1 -> V_30 ) {
switch ( V_112 ) {
case V_120 :
V_116 = F_41 ( V_4 , V_113 , V_114 , V_115 ) ;
break;
case V_121 :
V_116 = F_42 ( V_4 , V_113 , V_114 , V_115 ) ;
break;
}
}
V_29 = ( V_116 ) ? - V_38 : 0 ;
F_10 ( V_8 ,
L_52 , V_29 ) ;
return V_29 ;
}
