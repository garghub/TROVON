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
static inline void F_5 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_14 = V_13 -> V_15 ;
}
static inline void F_6 ( struct V_12 * V_13 ,
struct V_10 * V_11 )
{
V_13 -> V_15 = V_11 -> V_14 ;
}
static int F_7 ( T_1 V_16 , const char * V_17 )
{
int V_18 ;
int V_19 ;
if ( ! V_16 || ! V_17 ) {
F_8 ( L_2 ) ;
V_18 = - V_20 ;
goto V_21;
}
if ( V_17 [ V_16 - 1 ] != 0 ) {
F_8 ( L_3 ) ;
V_18 = - V_20 ;
goto V_21;
}
F_9 ( V_22 , L_4 , V_17 ) ;
V_19 = F_10 ( V_17 ) ;
if ( V_19 == - 1 ) {
F_9 ( V_22 , L_5 , V_17 ) ;
V_18 = - V_20 ;
goto V_21;
}
F_9 ( V_22 , L_6 , V_17 , V_19 ) ;
V_18 = V_19 ;
V_21:
return V_18 ;
}
int F_11 ( unsigned int V_23 , unsigned long V_24 )
{
char * V_25 = NULL ;
struct V_12 * V_13 ;
struct V_26 * V_27 ;
struct V_28 * V_29 = NULL ;
int V_30 = 0 , V_16 = 0 ;
if ( V_23 == V_31 ) {
V_27 = (struct V_26 * ) V_24 ;
V_32 = V_27 -> V_33 ;
V_34 = V_27 -> V_35 ;
return 0 ;
}
F_9 ( V_22 , L_7 , V_23 ) ;
if ( F_12 ( & V_25 , & V_16 , ( void V_36 * ) V_24 ) ) {
F_8 ( L_8 ) ;
return - V_20 ;
}
V_13 = (struct V_12 * ) V_25 ;
switch ( V_23 ) {
case V_37 : {
struct V_38 * V_39 ;
if ( ! V_13 -> V_40 || ! V_13 -> V_41 ) {
F_8 ( L_9 ) ;
V_30 = - V_20 ;
goto V_21;
}
V_39 = F_13 ( V_13 -> V_40 , V_42 ) ;
if ( ! V_39 ) {
V_30 = - V_43 ;
goto V_21;
}
V_30 = F_14 ( V_39 , V_13 -> V_41 , V_13 -> V_40 ) ;
if ( ! V_30 )
V_30 = F_15 ( V_39 , V_13 -> V_40 ) ;
if ( ! V_30 )
V_30 = F_16 ( V_39 ) ;
F_17 ( V_39 ) ;
goto V_21;
}
case V_44 :
if ( ! V_13 -> V_45 ) {
F_8 ( L_10 ) ;
V_30 = - V_20 ;
goto V_21;
}
if ( strlen ( V_46 ) + 1 > V_13 -> V_47 ) {
F_8 ( L_11 ) ;
V_30 = - V_20 ;
goto V_21;
}
memcpy ( V_13 -> V_48 , V_46 ,
strlen ( V_46 ) + 1 ) ;
V_30 = F_18 ( ( void V_36 * ) V_24 , V_13 , V_16 ) ;
if ( V_30 )
V_30 = - V_49 ;
goto V_21;
case V_50 : {
int V_19 ;
V_19 = F_7 ( V_13 -> V_47 ,
V_13 -> V_45 ) ;
V_13 -> V_51 = V_19 ;
if ( V_19 < 0 ) {
V_30 = - V_20 ;
goto V_21;
}
V_30 = F_18 ( ( void V_36 * ) V_24 , V_13 ,
sizeof( * V_13 ) ) ;
if ( V_30 )
V_30 = - V_49 ;
goto V_21;
}
case V_52 : {
int V_19 ;
struct V_53 V_54 ;
if ( ! V_13 -> V_47 || ! V_13 -> V_45 ) {
F_8 ( L_12 ) ;
V_30 = - V_20 ;
goto V_21;
}
if ( V_13 -> V_45 [ V_13 -> V_47 - 1 ] != 0 ) {
F_8 ( L_13 ) ;
V_30 = - V_20 ;
goto V_21;
}
F_9 ( V_22 , L_4 , V_13 -> V_45 ) ;
F_19 ( & V_54 , V_13 -> V_45 ) ;
V_19 = F_20 ( & V_54 ) ;
V_13 -> V_51 = V_19 ;
if ( V_19 == - 1 ) {
F_9 ( V_22 , L_14 ,
V_13 -> V_45 ) ;
V_30 = - V_20 ;
goto V_21;
}
F_9 ( V_22 , L_6 , V_13 -> V_45 ,
V_19 ) ;
V_30 = F_18 ( ( void V_36 * ) V_24 , V_13 ,
sizeof( * V_13 ) ) ;
if ( V_30 )
V_30 = - V_49 ;
goto V_21;
}
case V_55 : {
F_9 ( V_22 , L_15 ,
V_13 -> V_45 ) ;
V_30 = 0 ;
goto V_21;
}
case V_56 : {
int V_57 = V_13 -> V_58 ;
char * V_59 , * V_60 ;
if ( ! V_13 -> V_45 ) {
F_8 ( L_10 ) ;
V_30 = - V_20 ;
goto V_21;
}
if ( V_13 -> V_47 < 128 ) {
F_8 ( L_11 ) ;
V_30 = - V_20 ;
goto V_21;
}
V_29 = F_21 ( V_57 ) ;
if ( ! V_29 ) {
V_30 = - V_9 ;
goto V_21;
}
if ( V_29 -> V_61 )
V_59 = L_16 ;
else if ( V_29 -> V_62 )
V_59 = L_17 ;
else if ( V_29 -> V_63 )
V_59 = L_18 ;
else
V_59 = L_19 ;
V_60 = ( char * ) V_13 -> V_48 ;
snprintf ( V_60 , V_16 - sizeof( * V_13 ) , L_20 ,
( int ) V_57 , V_59 , V_29 -> V_64 -> V_65 ,
V_29 -> V_66 , V_29 -> V_53 . V_54 ,
F_22 ( & V_29 -> V_67 ) ) ;
V_30 = F_18 ( ( void V_36 * ) V_24 , V_13 , V_16 ) ;
V_30 = 0 ;
goto V_21;
}
}
if ( V_13 -> V_51 == V_68 ) {
if ( V_13 -> V_69 <= 0 || ! V_13 -> V_70 ) {
V_30 = - V_20 ;
goto V_21;
}
if ( F_23 ( V_13 -> V_70 , V_71 ) >= V_71 ) {
V_30 = - V_20 ;
goto V_21;
}
V_29 = F_24 ( V_13 -> V_70 ) ;
} else if ( V_13 -> V_51 < F_25 () ) {
V_29 = F_21 ( V_13 -> V_51 ) ;
} else {
F_8 ( L_21 ) ;
V_30 = - V_20 ;
goto V_21;
}
if ( ! V_29 ) {
F_8 ( L_22 , V_13 -> V_51 ) ;
V_30 = - V_20 ;
goto V_21;
}
F_26 ( V_29 -> V_72 == V_73 ) ;
if ( ! V_29 -> V_62 || V_29 -> V_61 ) {
F_8 ( L_23 , V_13 -> V_51 ) ;
V_30 = - V_20 ;
goto V_21;
}
switch ( V_23 ) {
case V_74 : {
if ( ! V_29 -> V_63 ) {
F_8 ( L_24 , V_29 -> V_75 ) ;
V_30 = - V_76 ;
goto V_21;
}
F_9 ( V_77 , L_25 ,
V_29 -> V_66 ) ;
V_29 -> V_78 = 1 ;
V_30 = 0 ;
goto V_21;
}
default: {
V_30 = F_27 ( V_23 , V_29 -> V_79 , V_16 , V_13 , NULL ) ;
if ( V_30 )
goto V_21;
V_30 = F_18 ( ( void V_36 * ) V_24 , V_13 , V_16 ) ;
if ( V_30 )
V_30 = - V_49 ;
goto V_21;
}
}
V_21:
if ( V_25 )
F_28 ( V_25 , V_16 ) ;
return V_30 ;
}
static int F_29 ( void )
{
T_2 V_80 , V_81 ;
char V_25 [ 64 ] ;
int V_16 , V_82 = 0 ;
F_9 ( V_83 , L_26 , L_27 , L_28 , L_29 ) ;
F_9 ( V_83 , L_30 , ( T_2 ) V_84 ) ;
V_80 = V_84 ;
F_9 ( V_83 , L_31 , V_80 ) ;
if ( V_80 != V_84 ) {
F_8 ( L_32 ,
V_80 , ( int ) sizeof( V_80 ) ) ;
V_82 = - V_20 ;
}
V_16 = snprintf ( V_25 , sizeof( V_25 ) , L_29 , V_80 ) ;
if ( V_16 != 18 ) {
F_30 ( L_33 , V_25 , V_16 ) ;
V_82 = - V_20 ;
}
V_81 = V_84 ;
F_9 ( V_83 , L_31 , V_80 ) ;
if ( V_80 != V_84 ) {
F_8 ( L_32 ,
V_80 , ( int ) sizeof( V_80 ) ) ;
V_82 = - V_85 ;
}
if ( V_80 >> 8 != V_84 >> 8 ) {
F_8 ( L_32 ,
V_80 , ( int ) sizeof( V_80 ) ) ;
return - V_85 ;
}
if ( F_31 ( V_81 , 256 ) != ( V_80 & 255 ) ) {
F_8 ( L_34 , V_80 , V_80 & 255 ) ;
return - V_85 ;
}
if ( V_80 >> 8 != V_81 ) {
F_8 ( L_35 ,
V_80 , V_81 , V_80 >> 8 ) ;
return - V_85 ;
}
V_16 = snprintf ( V_25 , sizeof( V_25 ) , L_29 , V_80 ) ;
if ( V_16 != 18 ) {
F_30 ( L_33 , V_25 , V_16 ) ;
V_82 = - V_20 ;
}
V_16 = snprintf ( V_25 , sizeof( V_25 ) , L_27 , V_80 ) ;
if ( V_16 != 20 ) {
F_30 ( L_36 , V_25 , V_16 ) ;
V_82 = - V_20 ;
}
V_16 = snprintf ( V_25 , sizeof( V_25 ) , L_28 , V_80 ) ;
if ( V_16 != 2 ) {
F_30 ( L_37 , V_25 , V_16 ) ;
V_82 = - V_20 ;
}
if ( ( V_80 & ~ V_86 ) >= V_87 ) {
F_30 ( L_38 , V_80 ,
( T_2 ) V_87 ) ;
V_82 = - V_20 ;
}
return V_82 ;
}
static int T_3 F_32 ( void )
{
int V_88 , V_30 ;
int V_89 ( void ) ;
F_33 ( L_39 V_46 L_40 ) ;
F_34 ( & V_90 ) ;
F_35 () ;
V_30 = F_29 () ;
if ( V_30 == - V_85 )
return V_30 ;
F_36 () ;
V_30 = F_37 () ;
if ( V_30 )
return V_30 ;
F_38 ( & V_91 ) ;
V_30 = F_39 ( & V_92 ) ;
if ( V_30 ) {
F_8 ( L_41 , V_93 , V_30 ) ;
return V_30 ;
}
for ( V_88 = 0 ; V_88 < F_25 () ; V_88 ++ )
V_94 [ V_88 ] = NULL ;
if ( V_95 <= 512 << ( 20 - V_96 ) )
V_97 = V_95 / 4 ;
else
V_97 = V_95 / 2 ;
V_30 = F_40 () ;
if ( V_30 )
return V_30 ;
V_30 = F_41 () ;
if ( V_30 )
return V_30 ;
V_30 = F_42 () ;
if ( V_30 )
return V_30 ;
V_30 = F_43 () ;
if ( V_30 )
return V_30 ;
V_30 = F_44 () ;
if ( V_30 != 0 )
return V_30 ;
V_30 = F_45 () ;
if ( V_30 )
return V_30 ;
V_30 = V_89 () ;
return V_30 ;
}
static void F_46 ( void )
{
int V_88 ;
int V_98 ( void ) ;
V_98 () ;
F_47 ( & V_92 ) ;
for ( V_88 = 0 ; V_88 < F_25 () ; V_88 ++ ) {
struct V_28 * V_29 = F_21 ( V_88 ) ;
if ( V_29 && V_29 -> V_62 &&
F_48 ( V_29 ) && F_49 ( V_29 , V_99 ) ) {
F_26 ( V_29 -> V_72 == V_73 ) ;
F_49 ( V_29 , V_99 ) ( V_29 ) ;
}
}
F_50 () ;
F_51 () ;
F_52 () ;
F_53 () ;
F_54 () ;
F_55 () ;
F_56 () ;
F_57 () ;
}
