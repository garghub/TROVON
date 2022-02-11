static int F_1 ( void T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 1000 ;
while ( ! ( F_2 ( V_1 + V_4 ) & 0x80 ) ) {
if ( ! V_3 -- )
return - V_5 ;
F_3 () ;
}
* V_2 = F_2 ( V_1 + V_6 ) ;
return 0 ;
}
static int F_4 ( void T_1 * V_1 )
{
T_2 V_2 ;
F_5 ( 1 , V_1 + V_7 ) ;
F_6 ( 10 ) ;
F_5 ( 0 , V_1 + V_7 ) ;
if ( F_1 ( V_1 , & V_2 ) < 0 || V_2 != V_8 )
return - V_9 ;
return 0 ;
}
static int F_7 ( void T_1 * V_1 , T_2 V_10 )
{
int V_3 = 1000 ;
while ( F_2 ( V_1 + V_11 ) & 0x80 ) {
if ( ! V_3 -- )
return - V_5 ;
F_3 () ;
}
F_5 ( V_10 , V_1 + V_12 ) ;
return 0 ;
}
static int F_8 ( void T_1 * V_1 , T_2 * V_13 , T_2 * V_14 )
{
int V_15 ;
V_15 = F_7 ( V_1 , V_16 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_1 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_1 , V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_9 ( void T_1 * V_17 )
{
if ( ( F_2 ( V_17 + V_18 ) & 0x3f ) != V_19 )
return - V_9 ;
return 0 ;
}
static void F_10 ( void T_1 * V_17 , T_2 V_20 )
{
F_5 ( V_20 , V_17 + V_21 ) ;
}
static int F_11 ( struct V_22 * V_23 , unsigned int V_24 )
{
if ( ! V_25 [ V_24 ] )
return 0 ;
switch ( V_1 [ V_24 ] ) {
case V_26 :
F_12 ( V_23 , L_1 ) ;
return 0 ;
case 0x220 :
V_27 [ V_24 ] |= V_28 ;
break;
case 0x240 :
V_27 [ V_24 ] |= V_29 ;
break;
case 0x260 :
V_27 [ V_24 ] |= V_30 ;
break;
case 0x280 :
V_27 [ V_24 ] |= V_31 ;
break;
default:
F_12 ( V_23 , L_2 , V_1 [ V_24 ] ) ;
return 0 ;
}
switch ( V_17 [ V_24 ] ) {
case V_26 :
F_12 ( V_23 , L_3 ) ;
return 0 ;
case 0x530 :
V_27 [ V_24 ] |= V_32 | V_33 ;
break;
case 0x604 :
V_27 [ V_24 ] |= V_32 | V_34 ;
break;
case 0xe80 :
V_27 [ V_24 ] |= V_32 | V_35 ;
break;
case 0xf40 :
V_27 [ V_24 ] |= V_32 | V_36 ;
break;
default:
F_12 ( V_23 , L_4 , V_17 [ V_24 ] ) ;
return 0 ;
}
switch ( V_37 [ V_24 ] ) {
case V_38 :
F_12 ( V_23 , L_5 ) ;
return 0 ;
case 7 :
V_20 [ V_24 ] |= V_39 ;
break;
case 2 :
V_37 [ V_24 ] = 9 ;
case 9 :
V_20 [ V_24 ] |= V_40 ;
break;
case 10 :
V_20 [ V_24 ] |= V_41 ;
break;
case 11 :
V_20 [ V_24 ] |= V_42 ;
break;
default:
F_12 ( V_23 , L_6 , V_37 [ V_24 ] ) ;
return 0 ;
}
switch ( V_43 [ V_24 ] ) {
case V_44 :
F_12 ( V_23 , L_7 ) ;
return 0 ;
case 0 :
V_20 [ V_24 ] |= V_45 ;
break;
case 1 :
V_20 [ V_24 ] |= V_46 ;
break;
case 3 :
V_20 [ V_24 ] |= V_47 ;
break;
default:
F_12 ( V_23 , L_8 , V_43 [ V_24 ] ) ;
return 0 ;
}
if ( V_48 [ V_24 ] == V_44 || V_48 [ V_24 ] == V_43 [ V_24 ] ) {
V_48 [ V_24 ] = - 1 ;
goto V_49;
}
V_20 [ V_24 ] |= V_50 ;
switch ( V_48 [ V_24 ] ) {
case 0 :
break;
case 1 :
if ( V_43 [ V_24 ] == 0 )
break;
default:
F_12 ( V_23 , L_9 , V_48 [ V_24 ] ) ;
return 0 ;
}
V_49:
switch ( V_51 [ V_24 ] ) {
case V_26 :
F_13 ( V_23 , L_10 ) ;
V_51 [ V_24 ] = - 1 ;
goto V_52;
case 0x300 :
V_27 [ V_24 ] |= V_53 | V_54 ;
break;
case 0x330 :
V_27 [ V_24 ] |= V_53 | V_55 ;
break;
default:
F_12 ( V_23 , L_11 , V_51 [ V_24 ] ) ;
return 0 ;
}
switch ( V_56 [ V_24 ] ) {
case V_38 :
F_13 ( V_23 , L_12 ) ;
V_56 [ V_24 ] = - 1 ;
break;
case 2 :
V_56 [ V_24 ] = 9 ;
case 9 :
V_27 [ V_24 ] |= V_57 ;
break;
#ifdef F_14
case 3 :
V_27 [ V_24 ] |= V_58 ;
break;
#endif
case 5 :
V_27 [ V_24 ] |= V_59 ;
break;
case 7 :
V_27 [ V_24 ] |= V_60 ;
break;
#ifdef F_15
case 10 :
V_27 [ V_24 ] |= V_61 ;
break;
#endif
default:
F_12 ( V_23 , L_13 , V_56 [ V_24 ] ) ;
return 0 ;
}
if ( V_56 [ V_24 ] == V_37 [ V_24 ] ) {
F_12 ( V_23 , L_14 ) ;
return 0 ;
}
V_52:
switch ( V_62 [ V_24 ] ) {
case V_26 :
F_13 ( V_23 , L_15 ) ;
V_62 [ V_24 ] = - 1 ;
break;
case 0x388 :
break;
default:
F_12 ( V_23 , L_16 , V_62 [ V_24 ] ) ;
return 0 ;
}
V_27 [ V_24 ] |= V_63 ;
return 1 ;
}
static int F_16 ( struct V_64 * V_65 , T_2 * type )
{
T_2 V_13 ;
T_2 V_14 ;
int V_15 ;
V_15 = F_4 ( V_65 -> V_1 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_8 ( V_65 -> V_1 , & V_13 , & V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_13 != V_66 || V_14 != V_67 )
return - V_9 ;
V_15 = F_7 ( V_65 -> V_1 , V_68 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_65 -> V_1 , V_69 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_65 -> V_1 , type ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_17 ( struct V_64 * V_65 , T_2 V_70 )
{
int V_15 ;
V_15 = F_7 ( V_65 -> V_1 , V_71 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_65 -> V_1 , V_70 ) ;
if ( V_15 < 0 )
return V_15 ;
#ifdef F_14
V_15 = F_4 ( V_65 -> V_1 ) ;
if ( V_15 < 0 )
return V_15 ;
#endif
return 0 ;
}
static void F_18 ( struct V_64 * V_65 , T_3 V_27 )
{
T_2 V_72 = F_2 ( V_65 -> V_73 + V_74 ) ;
int V_75 ;
F_5 ( V_72 | 0x80 , V_65 -> V_73 + V_74 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
F_5 ( V_27 , V_65 -> V_73 + V_75 ) ;
V_27 >>= 8 ;
}
F_5 ( V_72 & 0x7f , V_65 -> V_73 + V_74 ) ;
F_19 ( 10 ) ;
}
static void F_20 ( struct V_64 * V_65 , T_3 V_27 )
{
int V_75 ;
for ( V_75 = V_76 ; V_75 ; V_75 -- ) {
T_2 V_72 = F_2 ( V_65 -> V_73 + V_75 - 1 ) ;
V_65 -> V_27 = ( V_65 -> V_27 << 8 ) | V_72 ;
}
V_27 |= V_65 -> V_27 & V_77 ;
F_18 ( V_65 , V_27 ) ;
}
static int F_21 ( struct V_64 * V_65 , T_2 V_20 )
{
int V_15 ;
V_15 = F_9 ( V_65 -> V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
F_10 ( V_65 -> V_17 , V_20 ) ;
V_15 = F_17 ( V_65 , V_78 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static void F_22 ( struct V_79 * V_80 )
{
struct V_64 * V_65 = V_80 -> V_81 ;
if ( V_65 -> V_17 ) {
F_10 ( V_65 -> V_17 , 0 ) ;
F_23 ( V_65 -> V_17 ) ;
F_24 ( V_65 -> V_82 ) ;
}
if ( V_65 -> V_73 ) {
F_18 ( V_65 , V_65 -> V_27 ) ;
F_23 ( V_65 -> V_73 ) ;
F_24 ( V_65 -> V_83 ) ;
}
if ( V_65 -> V_1 ) {
F_23 ( V_65 -> V_1 ) ;
F_24 ( V_65 -> V_84 ) ;
}
}
static int F_25 ( struct V_22 * V_23 , unsigned int V_24 )
{
struct V_64 * V_65 ;
struct V_85 * V_86 ;
struct V_79 * V_80 ;
T_2 type ;
int V_15 ;
V_15 = F_26 ( V_87 [ V_24 ] , V_88 [ V_24 ] , V_89 , sizeof *V_65 ,
& V_80 ) ;
if ( V_15 < 0 )
return V_15 ;
F_27 ( V_80 , V_23 ) ;
V_80 -> V_90 = F_22 ;
V_65 = V_80 -> V_81 ;
V_65 -> V_84 = F_28 ( V_1 [ V_24 ] , 16 , V_91 ) ;
if ( ! V_65 -> V_84 ) {
F_12 ( V_23 , L_17 , V_1 [ V_24 ] ,
V_1 [ V_24 ] + 15 ) ;
V_15 = - V_92 ;
goto error;
}
V_65 -> V_1 = F_29 ( V_1 [ V_24 ] , 16 ) ;
V_15 = F_16 ( V_65 , & type ) ;
if ( V_15 < 0 ) {
F_12 ( V_23 , L_18 , V_1 [ V_24 ] ) ;
goto error;
}
F_30 ( V_23 , L_19 , type , V_1 [ V_24 ] ) ;
V_65 -> V_83 = F_28 ( V_1 [ V_24 ] + V_93 ,
16 , V_91 ) ;
if ( ! V_65 -> V_83 ) {
F_12 ( V_23 , L_17 ,
V_1 [ V_24 ] + V_93 ,
V_1 [ V_24 ] + V_93 + 15 ) ;
V_15 = - V_92 ;
goto error;
}
V_65 -> V_73 = F_29 ( V_1 [ V_24 ] + V_93 , 16 ) ;
F_20 ( V_65 , V_27 [ V_24 ] ) ;
V_65 -> V_82 = F_28 ( V_17 [ V_24 ] , 4 , V_91 ) ;
if ( ! V_65 -> V_82 ) {
F_12 ( V_23 , L_17 , V_17 [ V_24 ] ,
V_17 [ V_24 ] + 3 ) ;
V_15 = - V_92 ;
goto error;
}
V_65 -> V_17 = F_29 ( V_17 [ V_24 ] , 4 ) ;
V_15 = F_21 ( V_65 , V_20 [ V_24 ] ) ;
if ( V_15 < 0 ) {
F_12 ( V_23 , L_20 ) ;
goto error;
}
strcpy ( V_80 -> V_94 , V_91 ) ;
strcpy ( V_80 -> V_95 , V_91 ) ;
sprintf ( V_80 -> V_96 , L_21 ,
V_80 -> V_95 , V_1 [ V_24 ] , V_17 [ V_24 ] , V_37 [ V_24 ] , V_43 [ V_24 ] ,
V_48 [ V_24 ] ) ;
V_15 = F_31 ( V_80 , V_17 [ V_24 ] + 4 , - 1 , V_37 [ V_24 ] , V_43 [ V_24 ] ,
V_48 [ V_24 ] , V_97 , 0 , & V_86 ) ;
if ( V_15 < 0 )
goto error;
V_15 = F_32 ( V_86 , 0 , NULL ) ;
if ( V_15 < 0 )
goto error;
V_15 = F_33 ( V_86 ) ;
if ( V_15 < 0 )
goto error;
V_15 = F_34 ( V_86 , 0 , NULL ) ;
if ( V_15 < 0 )
goto error;
if ( V_51 [ V_24 ] >= 0 ) {
V_15 = F_35 ( V_80 , 0 , V_98 ,
V_51 [ V_24 ] , 0 , V_56 [ V_24 ] , NULL ) ;
if ( V_15 < 0 )
goto error;
}
if ( V_62 [ V_24 ] >= 0 ) {
struct V_99 * V_100 ;
V_15 = F_36 ( V_80 , V_62 [ V_24 ] , V_62 [ V_24 ] + 2 ,
V_101 , 0 , & V_100 ) ;
if ( V_15 < 0 ) {
F_12 ( V_23 , L_22 , V_62 [ V_24 ] ) ;
goto error;
}
V_15 = F_37 ( V_100 , 1 , 2 ) ;
if ( V_15 < 0 )
goto error;
V_15 = F_38 ( V_100 , 0 , 1 , NULL ) ;
if ( V_15 < 0 )
goto error;
}
V_15 = F_39 ( V_80 ) ;
if ( V_15 < 0 )
goto error;
F_40 ( V_23 , V_80 ) ;
return 0 ;
error:
F_41 ( V_80 ) ;
return V_15 ;
}
static int F_42 ( struct V_22 * V_23 , unsigned int V_24 )
{
F_41 ( F_43 ( V_23 ) ) ;
F_40 ( V_23 , NULL ) ;
return 0 ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_102 , V_103 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_102 ) ;
}
