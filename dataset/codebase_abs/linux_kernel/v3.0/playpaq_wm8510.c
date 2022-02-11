static struct V_1 F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_1 V_10 ;
unsigned int V_11 , V_12 , V_13 ;
unsigned int V_14 , V_15 ;
unsigned V_16 ;
V_11 = F_3 ( V_3 ) ;
V_13 = F_4 ( V_3 ) ;
V_12 = F_5 ( F_6 ( V_3 ) ) ;
V_14 = V_11 * V_12 * V_13 ;
V_10 . V_17 = F_7 ( V_9 -> V_18 ) ;
V_15 = V_10 . V_17 / V_14 ;
V_10 . V_19 = V_15 / 2 ;
if ( V_15 & 1 ) {
V_10 . V_19 ++ ;
}
V_10 . V_20 = V_12 - 1 ;
V_16 = ( V_10 . V_17 / ( V_10 . V_19 * 2 ) ) / ( 2 * ( V_10 . V_20 + 1 ) ) ;
F_8 ( L_1 ,
V_11 , V_16 ) ;
return V_10 ;
}
static int F_9 ( struct V_21 * V_22 ,
struct V_2 * V_3 )
{
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_4 * V_26 = V_24 -> V_26 ;
struct V_4 * V_5 = V_24 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned int V_27 = 0 , V_28 = 0 , V_29 = 0 ;
int V_30 ;
#if ! V_31 V_32
const unsigned int V_33 = ( V_34 |
V_35 |
V_36 ) ;
#else
struct V_1 V_10 ;
const unsigned int V_33 = ( V_34 |
V_35 |
V_37 ) ;
#endif
if ( V_9 == NULL ) {
F_10 ( L_2 ) ;
return - V_38 ;
}
switch ( F_3 ( V_3 ) ) {
case 48000 :
V_27 = 24576000 ;
V_29 = V_39 ;
V_28 = V_40 ;
break;
case 44100 :
V_27 = 22579200 ;
V_29 = V_39 ;
V_28 = V_40 ;
break;
case 22050 :
V_27 = 22579200 ;
V_29 = V_41 ;
V_28 = V_40 ;
break;
case 16000 :
V_27 = 24576000 ;
V_29 = V_42 ;
V_28 = V_40 ;
break;
case 11025 :
V_27 = 22579200 ;
V_29 = V_43 ;
V_28 = V_40 ;
break;
case 8000 :
V_27 = 24576000 ;
V_29 = V_44 ;
V_28 = V_40 ;
break;
default:
F_10 ( L_3 ,
F_3 ( V_3 ) ) ;
return - V_38 ;
}
V_30 = F_11 ( V_26 , V_33 ) ;
if ( V_30 < 0 ) {
F_10 ( L_4
L_5 ,
V_30 ) ;
return V_30 ;
}
V_30 = F_11 ( V_5 , V_33 ) ;
if ( V_30 < 0 ) {
F_10 ( L_4
L_6 ,
V_30 ) ;
return V_30 ;
}
#if V_31 V_32
V_10 = F_1 ( V_3 , V_5 ) ;
F_8 ( L_7 ,
V_10 . V_19 , V_10 . V_20 ) ;
V_30 = F_12 ( V_5 , V_45 , V_10 . V_19 ) ;
if ( V_30 < 0 ) {
F_10 ( L_8 ,
V_30 ) ;
return V_30 ;
}
V_30 = F_12 ( V_5 , V_46 ,
V_10 . V_20 ) ;
if ( V_30 < 0 ) {
F_10 ( L_4
L_9 ,
V_30 ) ;
return V_30 ;
}
#endif
F_8 ( L_4
L_10 ,
F_7 ( V_47 ) , V_27 , V_28 , V_29 ) ;
#if ! V_31 V_32
V_30 = F_12 ( V_26 , V_48 , V_28 ) ;
if ( V_30 < 0 ) {
F_10
( L_11 ,
V_30 ) ;
return V_30 ;
}
#endif
V_30 = F_13 ( V_26 , 0 , 0 ,
F_7 ( V_47 ) , V_27 ) ;
if ( V_30 < 0 ) {
F_10 ( L_12 ,
V_30 ) ;
return V_30 ;
}
V_30 = F_12 ( V_26 , V_49 , V_29 ) ;
if ( V_30 < 0 ) {
F_10 ( L_13 ,
V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int F_14 ( struct V_23 * V_24 )
{
struct V_50 * V_51 = V_24 -> V_51 ;
struct V_52 * V_53 = & V_51 -> V_53 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < F_15 ( V_55 ) ; V_54 ++ )
F_16 ( V_53 , & V_55 [ V_54 ] ) ;
F_17 ( V_53 , V_56 , F_15 ( V_56 ) ) ;
F_18 ( V_53 , L_14 ) ;
F_18 ( V_53 , L_15 ) ;
F_19 ( V_53 ) ;
F_12 ( V_24 -> V_26 , V_57 ,
V_58 | 4 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_30 = 0 ;
V_59 = F_21 ( NULL , L_16 ) ;
if ( F_22 ( V_59 ) ) {
V_59 = NULL ;
goto V_60;
}
V_61 = F_21 ( NULL , L_17 ) ;
if ( F_22 ( V_61 ) ) {
V_61 = NULL ;
goto V_62;
}
if ( F_23 ( V_59 , V_61 ) ) {
F_10 ( L_18
L_19 ) ;
goto V_63;
}
F_24 ( V_47 , 12000000 ) ;
F_25 ( V_47 ) ;
#if V_31 V_64
F_26 ( V_65 , V_66 , 0 ) ;
#endif
V_67 = F_27 ( L_20 , 0 ) ;
if ( V_67 == NULL ) {
V_30 = - V_68 ;
goto V_69;
}
F_28 ( V_67 , & V_70 ) ;
V_30 = F_29 ( V_67 ) ;
if ( V_30 ) {
F_10 ( L_21 ,
V_30 ) ;
goto V_71;
}
return 0 ;
V_71:
if ( V_67 != NULL ) {
F_30 ( V_67 ) ;
V_67 = NULL ;
}
V_69:
V_63:
if ( V_61 != NULL ) {
F_31 ( V_61 ) ;
V_61 = NULL ;
}
V_62:
if ( V_59 != NULL ) {
F_31 ( V_59 ) ;
V_59 = NULL ;
}
return V_30 ;
}
static void T_2 F_32 ( void )
{
if ( V_59 != NULL ) {
F_31 ( V_59 ) ;
V_59 = NULL ;
}
if ( V_61 != NULL ) {
F_31 ( V_61 ) ;
V_61 = NULL ;
}
#if V_31 V_64
F_33 ( V_65 ) ;
#endif
F_34 ( V_67 ) ;
V_67 = NULL ;
}
