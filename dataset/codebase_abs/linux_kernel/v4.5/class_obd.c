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
if ( F_12 ( & V_25 , & V_16 , ( void * ) V_24 ) ) {
F_8 ( L_8 ) ;
return - V_20 ;
}
V_13 = (struct V_12 * ) V_25 ;
switch ( V_23 ) {
case V_36 : {
struct V_37 * V_38 ;
if ( ! V_13 -> V_39 || ! V_13 -> V_40 ) {
F_8 ( L_9 ) ;
V_30 = - V_20 ;
goto V_21;
}
V_38 = F_13 ( V_13 -> V_39 , V_41 ) ;
if ( ! V_38 ) {
V_30 = - V_42 ;
goto V_21;
}
V_30 = F_14 ( V_38 , V_13 -> V_40 ,
V_13 -> V_39 ) ;
if ( ! V_30 )
V_30 = F_15 ( V_38 , V_13 -> V_39 ) ;
if ( ! V_30 )
V_30 = F_16 ( V_38 ) ;
F_17 ( V_38 ) ;
goto V_21;
}
case V_43 :
if ( ! V_13 -> V_44 ) {
F_8 ( L_10 ) ;
V_30 = - V_20 ;
goto V_21;
}
if ( strlen ( V_45 ) + 1 > V_13 -> V_46 ) {
F_8 ( L_11 ) ;
V_30 = - V_20 ;
goto V_21;
}
memcpy ( V_13 -> V_47 , V_45 ,
strlen ( V_45 ) + 1 ) ;
V_30 = F_18 ( ( void * ) V_24 , V_13 , V_16 ) ;
if ( V_30 )
V_30 = - V_48 ;
goto V_21;
case V_49 : {
int V_19 ;
V_19 = F_7 ( V_13 -> V_46 ,
V_13 -> V_44 ) ;
V_13 -> V_50 = V_19 ;
if ( V_19 < 0 ) {
V_30 = - V_20 ;
goto V_21;
}
V_30 = F_18 ( ( void * ) V_24 , V_13 , sizeof( * V_13 ) ) ;
if ( V_30 )
V_30 = - V_48 ;
goto V_21;
}
case V_51 : {
int V_19 ;
struct V_52 V_53 ;
if ( ! V_13 -> V_46 || ! V_13 -> V_44 ) {
F_8 ( L_12 ) ;
V_30 = - V_20 ;
goto V_21;
}
if ( V_13 -> V_44 [ V_13 -> V_46 - 1 ] != 0 ) {
F_8 ( L_13 ) ;
V_30 = - V_20 ;
goto V_21;
}
F_9 ( V_22 , L_4 , V_13 -> V_44 ) ;
F_19 ( & V_53 , V_13 -> V_44 ) ;
V_19 = F_20 ( & V_53 ) ;
V_13 -> V_50 = V_19 ;
if ( V_19 == - 1 ) {
F_9 ( V_22 , L_14 ,
V_13 -> V_44 ) ;
V_30 = - V_20 ;
goto V_21;
}
F_9 ( V_22 , L_6 , V_13 -> V_44 ,
V_19 ) ;
V_30 = F_18 ( ( void * ) V_24 , V_13 , sizeof( * V_13 ) ) ;
if ( V_30 )
V_30 = - V_48 ;
goto V_21;
}
case V_54 : {
F_9 ( V_22 , L_15 ,
V_13 -> V_44 ) ;
V_30 = 0 ;
goto V_21;
}
case V_55 : {
int V_56 = V_13 -> V_57 ;
char * V_58 , * V_59 ;
if ( ! V_13 -> V_44 ) {
F_8 ( L_10 ) ;
V_30 = - V_20 ;
goto V_21;
}
if ( V_13 -> V_46 < 128 ) {
F_8 ( L_11 ) ;
V_30 = - V_20 ;
goto V_21;
}
V_29 = F_21 ( V_56 ) ;
if ( ! V_29 ) {
V_30 = - V_9 ;
goto V_21;
}
if ( V_29 -> V_60 )
V_58 = L_16 ;
else if ( V_29 -> V_61 )
V_58 = L_17 ;
else if ( V_29 -> V_62 )
V_58 = L_18 ;
else
V_58 = L_19 ;
V_59 = ( char * ) V_13 -> V_47 ;
snprintf ( V_59 , V_16 - sizeof( * V_13 ) , L_20 ,
( int ) V_56 , V_58 , V_29 -> V_63 -> V_64 ,
V_29 -> V_65 , V_29 -> V_52 . V_53 ,
F_22 ( & V_29 -> V_66 ) ) ;
V_30 = F_18 ( ( void * ) V_24 , V_13 , V_16 ) ;
V_30 = 0 ;
goto V_21;
}
}
if ( V_13 -> V_50 == V_67 ) {
if ( V_13 -> V_68 <= 0 || V_13 -> V_69 == NULL ) {
V_30 = - V_20 ;
goto V_21;
}
if ( F_23 ( V_13 -> V_69 , V_70 ) >= V_70 ) {
V_30 = - V_20 ;
goto V_21;
}
V_29 = F_24 ( V_13 -> V_69 ) ;
} else if ( V_13 -> V_50 < F_25 () ) {
V_29 = F_21 ( V_13 -> V_50 ) ;
} else {
F_8 ( L_21 ) ;
V_30 = - V_20 ;
goto V_21;
}
if ( V_29 == NULL ) {
F_8 ( L_22 , V_13 -> V_50 ) ;
V_30 = - V_20 ;
goto V_21;
}
F_26 ( V_29 -> V_71 == V_72 ) ;
if ( ! V_29 -> V_61 || V_29 -> V_60 ) {
F_8 ( L_23 , V_13 -> V_50 ) ;
V_30 = - V_20 ;
goto V_21;
}
switch ( V_23 ) {
case V_73 : {
if ( ! V_29 -> V_62 ) {
F_8 ( L_24 , V_29 -> V_74 ) ;
V_30 = - V_75 ;
goto V_21;
}
F_9 ( V_76 , L_25 ,
V_29 -> V_65 ) ;
V_29 -> V_77 = 1 ;
V_30 = 0 ;
goto V_21;
}
default: {
V_30 = F_27 ( V_23 , V_29 -> V_78 , V_16 , V_13 , NULL ) ;
if ( V_30 )
goto V_21;
V_30 = F_18 ( ( void * ) V_24 , V_13 , V_16 ) ;
if ( V_30 )
V_30 = - V_48 ;
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
T_2 V_79 , V_80 ;
char V_25 [ 64 ] ;
int V_16 , V_81 = 0 ;
F_9 ( V_82 , L_26 , L_27 , L_28 , L_29 ) ;
F_9 ( V_82 , L_30 , ( T_2 ) V_83 ) ;
V_79 = V_83 ;
F_9 ( V_82 , L_31 , V_79 ) ;
if ( V_79 != V_83 ) {
F_8 ( L_32 ,
V_79 , ( int ) sizeof( V_79 ) ) ;
V_81 = - V_20 ;
}
V_16 = snprintf ( V_25 , sizeof( V_25 ) , L_29 , V_79 ) ;
if ( V_16 != 18 ) {
F_30 ( L_33 , V_25 , V_16 ) ;
V_81 = - V_20 ;
}
V_80 = V_83 ;
F_9 ( V_82 , L_31 , V_79 ) ;
if ( V_79 != V_83 ) {
F_8 ( L_32 ,
V_79 , ( int ) sizeof( V_79 ) ) ;
V_81 = - V_84 ;
}
if ( V_79 >> 8 != V_83 >> 8 ) {
F_8 ( L_32 ,
V_79 , ( int ) sizeof( V_79 ) ) ;
return - V_84 ;
}
if ( F_31 ( V_80 , 256 ) != ( V_79 & 255 ) ) {
F_8 ( L_34 , V_79 , V_79 & 255 ) ;
return - V_84 ;
}
if ( V_79 >> 8 != V_80 ) {
F_8 ( L_35 ,
V_79 , V_80 , V_79 >> 8 ) ;
return - V_84 ;
}
V_16 = snprintf ( V_25 , sizeof( V_25 ) , L_29 , V_79 ) ;
if ( V_16 != 18 ) {
F_30 ( L_33 , V_25 , V_16 ) ;
V_81 = - V_20 ;
}
V_16 = snprintf ( V_25 , sizeof( V_25 ) , L_27 , V_79 ) ;
if ( V_16 != 20 ) {
F_30 ( L_36 , V_25 , V_16 ) ;
V_81 = - V_20 ;
}
V_16 = snprintf ( V_25 , sizeof( V_25 ) , L_28 , V_79 ) ;
if ( V_16 != 2 ) {
F_30 ( L_37 , V_25 , V_16 ) ;
V_81 = - V_20 ;
}
if ( ( V_79 & ~ V_85 ) >= V_86 ) {
F_30 ( L_38 , V_79 ,
( T_2 ) V_86 ) ;
V_81 = - V_20 ;
}
return V_81 ;
}
static int T_3 F_32 ( void )
{
int V_87 , V_30 ;
int V_88 ( void ) ;
F_33 ( L_39 V_45 L_40 ) ;
F_34 ( & V_89 ) ;
F_35 () ;
V_30 = F_29 () ;
if ( V_30 == - V_84 )
return V_30 ;
F_36 () ;
V_30 = F_37 () ;
if ( V_30 )
return V_30 ;
F_38 ( & V_90 ) ;
V_30 = F_39 ( & V_91 ) ;
if ( V_30 ) {
F_8 ( L_41 , V_92 , V_30 ) ;
return V_30 ;
}
for ( V_87 = 0 ; V_87 < F_25 () ; V_87 ++ )
V_93 [ V_87 ] = NULL ;
if ( V_94 <= 512 << ( 20 - V_95 ) )
V_96 = V_94 / 4 ;
else
V_96 = V_94 / 2 ;
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
V_30 = V_88 () ;
return V_30 ;
}
static void F_46 ( void )
{
int V_87 ;
int V_97 ( void ) ;
V_97 () ;
F_47 ( & V_91 ) ;
for ( V_87 = 0 ; V_87 < F_25 () ; V_87 ++ ) {
struct V_28 * V_29 = F_21 ( V_87 ) ;
if ( V_29 && V_29 -> V_61 &&
F_48 ( V_29 ) && F_49 ( V_29 , V_98 ) ) {
F_26 ( V_29 -> V_71 == V_72 ) ;
F_49 ( V_29 , V_98 ) ( V_29 ) ;
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
