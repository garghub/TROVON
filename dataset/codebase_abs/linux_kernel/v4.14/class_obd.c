int F_1 ( char * V_1 )
{
memset ( V_1 , 0 , V_2 ) ;
if ( strcmp ( V_3 , V_4 ) == 0 )
return 0 ;
if ( strcmp ( V_3 , V_5 ) == 0 ) {
snprintf ( V_1 , V_2 , L_1 ,
F_2 () ,
F_3 ( & V_6 , F_4 () ) ) ;
return 0 ;
}
if ( strcmp ( V_3 , V_7 ) == 0 ) {
strcpy ( V_1 , V_8 ) ;
return 0 ;
}
return - V_9 ;
}
static int F_5 ( T_1 V_10 , const char * V_11 )
{
int V_12 ;
int V_13 ;
if ( ! V_10 || ! V_11 ) {
F_6 ( L_2 ) ;
V_12 = - V_14 ;
goto V_15;
}
if ( V_11 [ V_10 - 1 ] != 0 ) {
F_6 ( L_3 ) ;
V_12 = - V_14 ;
goto V_15;
}
F_7 ( V_16 , L_4 , V_11 ) ;
V_13 = F_8 ( V_11 ) ;
if ( V_13 == - 1 ) {
F_7 ( V_16 , L_5 , V_11 ) ;
V_12 = - V_14 ;
goto V_15;
}
F_7 ( V_16 , L_6 , V_11 , V_13 ) ;
V_12 = V_13 ;
V_15:
return V_12 ;
}
int F_9 ( unsigned int V_17 , unsigned long V_18 )
{
char * V_19 = NULL ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = NULL ;
int V_26 = 0 , V_10 = 0 ;
if ( V_17 == V_27 ) {
V_23 = (struct V_22 * ) V_18 ;
V_28 = V_23 -> V_29 ;
V_30 = V_23 -> V_31 ;
return 0 ;
}
F_7 ( V_16 , L_7 , V_17 ) ;
if ( F_10 ( & V_19 , & V_10 , ( void V_32 * ) V_18 ) ) {
F_6 ( L_8 ) ;
return - V_14 ;
}
V_21 = (struct V_20 * ) V_19 ;
switch ( V_17 ) {
case V_33 : {
struct V_34 * V_35 ;
if ( ! V_21 -> V_36 || ! V_21 -> V_37 ) {
F_6 ( L_9 ) ;
V_26 = - V_14 ;
goto V_15;
}
V_35 = F_11 ( V_21 -> V_36 , V_38 ) ;
if ( ! V_35 ) {
V_26 = - V_39 ;
goto V_15;
}
if ( F_12 ( V_35 , V_21 -> V_37 , V_21 -> V_36 ) )
V_26 = - V_40 ;
if ( ! V_26 )
V_26 = F_13 ( V_35 , V_21 -> V_36 ) ;
if ( ! V_26 )
V_26 = F_14 ( V_35 ) ;
F_15 ( V_35 ) ;
goto V_15;
}
case V_41 :
if ( ! V_21 -> V_42 ) {
F_6 ( L_10 ) ;
V_26 = - V_14 ;
goto V_15;
}
if ( strlen ( V_43 ) + 1 > V_21 -> V_44 ) {
F_6 ( L_11 ) ;
V_26 = - V_14 ;
goto V_15;
}
memcpy ( V_21 -> V_45 , V_43 ,
strlen ( V_43 ) + 1 ) ;
if ( F_16 ( ( void V_32 * ) V_18 , V_21 , V_10 ) )
V_26 = - V_40 ;
goto V_15;
case V_46 : {
int V_13 ;
V_13 = F_5 ( V_21 -> V_44 ,
V_21 -> V_42 ) ;
V_21 -> V_47 = V_13 ;
if ( V_13 < 0 ) {
V_26 = - V_14 ;
goto V_15;
}
if ( F_16 ( ( void V_32 * ) V_18 , V_21 , sizeof( * V_21 ) ) )
V_26 = - V_40 ;
goto V_15;
}
case V_48 : {
int V_13 ;
struct V_49 V_50 ;
if ( ! V_21 -> V_44 || ! V_21 -> V_42 ) {
F_6 ( L_12 ) ;
V_26 = - V_14 ;
goto V_15;
}
if ( V_21 -> V_42 [ V_21 -> V_44 - 1 ] != 0 ) {
F_6 ( L_13 ) ;
V_26 = - V_14 ;
goto V_15;
}
F_7 ( V_16 , L_4 , V_21 -> V_42 ) ;
F_17 ( & V_50 , V_21 -> V_42 ) ;
V_13 = F_18 ( & V_50 ) ;
V_21 -> V_47 = V_13 ;
if ( V_13 == - 1 ) {
F_7 ( V_16 , L_14 ,
V_21 -> V_42 ) ;
V_26 = - V_14 ;
goto V_15;
}
F_7 ( V_16 , L_6 , V_21 -> V_42 ,
V_13 ) ;
if ( F_16 ( ( void V_32 * ) V_18 , V_21 , sizeof( * V_21 ) ) )
V_26 = - V_40 ;
goto V_15;
}
case V_51 : {
int V_52 = V_21 -> V_53 ;
char * V_54 , * V_55 ;
if ( ! V_21 -> V_42 ) {
F_6 ( L_10 ) ;
V_26 = - V_14 ;
goto V_15;
}
if ( V_21 -> V_44 < 128 ) {
F_6 ( L_11 ) ;
V_26 = - V_14 ;
goto V_15;
}
V_25 = F_19 ( V_52 ) ;
if ( ! V_25 ) {
V_26 = - V_9 ;
goto V_15;
}
if ( V_25 -> V_56 )
V_54 = L_15 ;
else if ( V_25 -> V_57 )
V_54 = L_16 ;
else if ( V_25 -> V_58 )
V_54 = L_17 ;
else
V_54 = L_18 ;
V_55 = ( char * ) V_21 -> V_45 ;
snprintf ( V_55 , V_10 - sizeof( * V_21 ) , L_19 ,
( int ) V_52 , V_54 , V_25 -> V_59 -> V_60 ,
V_25 -> V_61 , V_25 -> V_49 . V_50 ,
F_20 ( & V_25 -> V_62 ) ) ;
if ( F_16 ( ( void V_32 * ) V_18 , V_21 , V_10 ) )
V_26 = - V_40 ;
goto V_15;
}
}
if ( V_21 -> V_47 == V_63 ) {
if ( V_21 -> V_64 <= 0 || ! V_21 -> V_65 ) {
V_26 = - V_14 ;
goto V_15;
}
if ( F_21 ( V_21 -> V_65 , V_66 ) >= V_66 ) {
V_26 = - V_14 ;
goto V_15;
}
V_25 = F_22 ( V_21 -> V_65 ) ;
} else if ( V_21 -> V_47 < F_23 () ) {
V_25 = F_19 ( V_21 -> V_47 ) ;
} else {
F_6 ( L_20 ) ;
V_26 = - V_14 ;
goto V_15;
}
if ( ! V_25 ) {
F_6 ( L_21 , V_21 -> V_47 ) ;
V_26 = - V_14 ;
goto V_15;
}
F_24 ( V_25 -> V_67 == V_68 ) ;
if ( ! V_25 -> V_57 || V_25 -> V_56 ) {
F_6 ( L_22 , V_21 -> V_47 ) ;
V_26 = - V_14 ;
goto V_15;
}
switch ( V_17 ) {
case V_69 : {
if ( ! V_25 -> V_58 ) {
F_6 ( L_23 , V_25 -> V_70 ) ;
V_26 = - V_71 ;
goto V_15;
}
F_7 ( V_72 , L_24 ,
V_25 -> V_61 ) ;
V_25 -> V_73 = 1 ;
V_26 = 0 ;
goto V_15;
}
default: {
V_26 = F_25 ( V_17 , V_25 -> V_74 , V_10 , V_21 , NULL ) ;
if ( V_26 )
goto V_15;
if ( F_16 ( ( void V_32 * ) V_18 , V_21 , V_10 ) )
V_26 = - V_40 ;
goto V_15;
}
}
V_15:
F_26 ( V_19 ) ;
return V_26 ;
}
static int F_27 ( void )
{
T_2 V_75 , V_76 ;
char V_19 [ 64 ] ;
int V_10 , V_77 = 0 ;
F_7 ( V_78 , L_25 , L_26 , L_27 , L_28 ) ;
F_7 ( V_78 , L_29 , ( T_2 ) V_79 ) ;
V_75 = V_79 ;
F_7 ( V_78 , L_30 , V_75 ) ;
if ( V_75 != V_79 ) {
F_6 ( L_31 ,
V_75 , ( int ) sizeof( V_75 ) ) ;
V_77 = - V_14 ;
}
V_10 = snprintf ( V_19 , sizeof( V_19 ) , L_28 , V_75 ) ;
if ( V_10 != 18 ) {
F_28 ( L_32 , V_19 , V_10 ) ;
V_77 = - V_14 ;
}
V_76 = V_79 ;
F_7 ( V_78 , L_30 , V_75 ) ;
if ( V_75 != V_79 ) {
F_6 ( L_31 ,
V_75 , ( int ) sizeof( V_75 ) ) ;
V_77 = - V_80 ;
}
if ( V_75 >> 8 != V_79 >> 8 ) {
F_6 ( L_31 ,
V_75 , ( int ) sizeof( V_75 ) ) ;
return - V_80 ;
}
if ( F_29 ( V_76 , 256 ) != ( V_75 & 255 ) ) {
F_6 ( L_33 , V_75 , V_75 & 255 ) ;
return - V_80 ;
}
if ( V_75 >> 8 != V_76 ) {
F_6 ( L_34 ,
V_75 , V_76 , V_75 >> 8 ) ;
return - V_80 ;
}
V_10 = snprintf ( V_19 , sizeof( V_19 ) , L_28 , V_75 ) ;
if ( V_10 != 18 ) {
F_28 ( L_32 , V_19 , V_10 ) ;
V_77 = - V_14 ;
}
V_10 = snprintf ( V_19 , sizeof( V_19 ) , L_26 , V_75 ) ;
if ( V_10 != 20 ) {
F_28 ( L_35 , V_19 , V_10 ) ;
V_77 = - V_14 ;
}
V_10 = snprintf ( V_19 , sizeof( V_19 ) , L_27 , V_75 ) ;
if ( V_10 != 2 ) {
F_28 ( L_36 , V_19 , V_10 ) ;
V_77 = - V_14 ;
}
if ( ( V_75 & ~ V_81 ) >= V_82 ) {
F_28 ( L_37 , V_75 ,
( T_2 ) V_82 ) ;
V_77 = - V_14 ;
}
return V_77 ;
}
static int T_3 F_30 ( void )
{
int V_83 , V_26 ;
F_31 ( L_38 V_43 L_39 ) ;
F_32 ( & V_84 ) ;
F_33 () ;
V_26 = F_27 () ;
if ( V_26 )
return V_26 ;
F_34 () ;
V_26 = F_35 () ;
if ( V_26 )
return V_26 ;
F_36 ( & V_85 ) ;
V_26 = F_37 ( & V_86 ) ;
if ( V_26 ) {
F_6 ( L_40 , V_87 , V_26 ) ;
return V_26 ;
}
for ( V_83 = 0 ; V_83 < F_23 () ; V_83 ++ )
V_88 [ V_83 ] = NULL ;
if ( V_89 <= 512 << ( 20 - V_90 ) )
V_91 = V_89 / 4 ;
else
V_91 = V_89 / 2 ;
V_26 = F_38 () ;
if ( V_26 )
return V_26 ;
V_26 = F_39 () ;
if ( V_26 )
return V_26 ;
V_26 = F_40 () ;
if ( V_26 )
return V_26 ;
V_26 = F_41 () ;
if ( V_26 )
return V_26 ;
V_26 = F_42 () ;
if ( V_26 != 0 )
return V_26 ;
V_26 = F_43 () ;
if ( V_26 )
return V_26 ;
V_26 = F_44 () ;
return V_26 ;
}
static void F_45 ( void )
{
F_46 () ;
F_47 ( & V_86 ) ;
F_48 () ;
F_49 () ;
F_50 () ;
F_51 () ;
F_52 () ;
F_53 () ;
F_54 () ;
F_55 () ;
}
