static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
return ( int ) V_3 -> V_5 ;
}
static int F_3 ( struct V_3 * V_3 ,
T_1 V_6 , T_1 V_7 )
{
T_1 V_8 [ 2 ] = { V_6 , V_7 } ;
int V_9 ;
V_9 = F_4 ( & V_3 -> V_10 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_3 -> V_11 , V_8 , 2 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_1 ,
V_9 ) ;
} else if ( V_9 != 2 ) {
F_6 ( V_3 -> V_2 ,
L_2
L_3 ,
V_9 ) ;
V_9 = - V_12 ;
} else {
V_9 = 0 ;
}
F_7 ( & V_3 -> V_10 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_6 , T_1 V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
return F_3 ( V_3 , V_6 , V_14 ) ;
}
static int F_9 ( struct V_3 * V_3 ,
T_1 V_6 , T_1 V_7 )
{
T_1 V_8 [ 2 ] = { V_6 , V_7 } ;
int V_9 ;
V_9 = F_4 ( & V_3 -> V_10 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_3 -> V_15 , V_8 , 2 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_4 ,
V_9 ) ;
} else if ( V_9 != 2 ) {
F_6 ( V_3 -> V_2 ,
L_5
L_3 ,
V_9 ) ;
V_9 = - V_12 ;
} else {
V_9 = 0 ;
}
F_7 ( & V_3 -> V_10 ) ;
return V_9 ;
}
static int F_10 ( struct V_3 * V_3 ,
T_1 V_6 , T_1 * V_7 )
{
int V_9 ;
V_9 = F_4 ( & V_3 -> V_10 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_3 -> V_11 , & V_6 , 1 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_6 ,
V_9 ) ;
goto V_16;
} else if ( V_9 != 1 ) {
F_6 ( V_3 -> V_2 ,
L_7
L_8 ,
V_9 ) ;
V_9 = - V_12 ;
goto V_16;
} else {
V_9 = 0 ;
}
V_9 = F_11 ( V_3 -> V_11 , V_7 , 1 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_9 ,
V_9 ) ;
goto V_16;
} else if ( V_9 != 1 ) {
F_6 ( V_3 -> V_2 ,
L_10
L_8 ,
V_9 ) ;
V_9 = - V_12 ;
goto V_16;
} else {
V_9 = 0 ;
}
V_16:
F_7 ( & V_3 -> V_10 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_6 ,
T_1 * V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
return F_10 ( V_3 , V_6 , V_14 ) ;
}
static int F_13 ( struct V_3 * V_3 ,
T_1 V_17 , T_1 * V_18 , T_1 V_19 )
{
int V_9 ;
if ( V_3 -> V_5 == 0xa0 ||
V_3 -> V_5 == 0xa1 )
return - V_12 ;
V_9 = F_4 ( & V_3 -> V_10 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_3 -> V_11 , & V_17 , 1 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_11 ,
V_9 ) ;
goto V_20;
} else if ( V_9 != 1 ) {
F_6 ( V_3 -> V_2 ,
L_12
L_8 ,
V_9 ) ;
V_9 = - V_12 ;
goto V_20;
}
V_9 = F_11 ( V_3 -> V_11 , V_18 , V_19 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_13 ,
V_9 ) ;
goto V_20;
} else if ( V_9 != V_19 ) {
F_6 ( V_3 -> V_2 ,
L_14
L_15 ,
V_9 , V_19 ) ;
V_9 = - V_12 ;
goto V_20;
}
V_9 = 0 ;
V_20:
F_7 ( & V_3 -> V_10 ) ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_13 ,
T_1 V_17 , T_1 * V_18 , T_1 V_19 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
return F_13 ( V_3 ,
V_17 , V_18 , V_19 ) ;
}
static int F_15 ( struct V_3 * V_3 ,
T_1 V_6 , T_1 V_21 , T_1 V_22 )
{
T_1 V_8 [ 2 ] = { V_6 , 0 } ;
int V_9 ;
V_9 = F_4 ( & V_3 -> V_10 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_3 -> V_11 , & V_6 , 1 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_16 ,
V_9 ) ;
goto V_23;
} else if ( V_9 != 1 ) {
F_6 ( V_3 -> V_2 ,
L_17
L_8 ,
V_9 ) ;
V_9 = - V_12 ;
goto V_23;
}
V_9 = F_11 ( V_3 -> V_11 , & V_8 [ 1 ] , 1 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_18 ,
V_9 ) ;
goto V_23;
} else if ( V_9 != 1 ) {
F_6 ( V_3 -> V_2 ,
L_19
L_8 ,
V_9 ) ;
V_9 = - V_12 ;
goto V_23;
}
V_8 [ 1 ] &= V_21 ;
V_8 [ 1 ] |= V_22 ;
V_9 = F_5 ( V_3 -> V_11 , V_8 , 2 ) ;
if ( V_9 < 0 ) {
F_6 ( V_3 -> V_2 ,
L_1 ,
V_9 ) ;
goto V_23;
} else if ( V_9 != 2 ) {
F_6 ( V_3 -> V_2 ,
L_2
L_3 ,
V_9 ) ;
V_9 = - V_12 ;
goto V_23;
}
V_9 = 0 ;
V_23:
F_7 ( & V_3 -> V_10 ) ;
return V_9 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_13 ,
T_1 V_6 , T_1 V_24 , T_1 V_25 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
return F_15 ( V_3 ,
V_6 , V_24 , ( V_24 & V_25 ) ) ;
}
int F_17 ( struct V_3 * V_3 ,
struct V_26 * V_27 )
{
return F_18 ( & V_3 -> V_28 ,
V_27 ) ;
}
int F_19 ( struct V_3 * V_3 ,
struct V_26 * V_27 )
{
return F_20 ( & V_3 -> V_28 ,
V_27 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
T_1 * V_29 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 ) ;
if ( ! V_3 -> V_30 )
return - V_31 ;
memcpy ( V_29 , V_3 -> V_32 , 3 ) ;
return 0 ;
}
static T_2 F_22 ( int V_33 , void * V_34 )
{
struct V_3 * V_3 = V_34 ;
T_1 V_35 [ 3 ] ;
T_3 V_36 ;
int V_9 ;
V_9 = F_13 ( V_3 , V_37 ,
V_35 , 3 ) ;
if ( V_9 )
goto V_38;
V_36 = ( V_35 [ 0 ] << 16 ) |
( V_35 [ 1 ] << 8 ) |
V_35 [ 2 ] ;
if ( ! V_3 -> V_30 ) {
V_3 -> V_32 [ 0 ] = V_35 [ 0 ] ;
V_3 -> V_32 [ 1 ] = V_35 [ 1 ] ;
V_3 -> V_32 [ 2 ] = V_35 [ 2 ] ;
V_3 -> V_30 = true ;
}
F_23 ( & V_3 -> V_28 ,
V_36 , NULL ) ;
F_24 ( V_3 -> V_2 ,
L_20 , V_36 ) ;
return V_39 ;
V_38:
F_24 ( V_3 -> V_2 ,
L_21 ) ;
return V_39 ;
}
static int F_25 ( struct V_40 * V_41 , void * V_42 )
{
struct V_3 * V_3 = V_41 -> V_43 ;
T_1 V_14 ;
T_1 V_6 ;
F_26 ( V_41 , L_22 ) ;
for ( V_6 = 0 ; V_6 < 0xff ; V_6 ++ ) {
F_10 ( V_3 , V_6 , & V_14 ) ;
F_26 ( V_41 , L_23 , V_6 , V_14 ) ;
}
return 0 ;
}
static int F_27 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
return F_28 ( V_45 , F_25 , V_44 -> V_46 ) ;
}
static T_4 F_29 ( struct V_45 * V_45 ,
const char T_5 * V_47 ,
T_6 V_48 , T_7 * V_49 )
{
struct V_50 * V_51 = V_45 -> V_52 ;
struct V_3 * V_3 = V_51 -> V_3 ;
char V_53 [ 32 ] ;
T_4 V_54 ;
int V_55 ;
unsigned long V_56 ;
int V_9 ;
int V_57 = 0 ;
V_54 = F_30 ( V_48 , ( sizeof( V_53 ) - 1 ) ) ;
if ( F_31 ( V_53 , V_47 , V_54 ) )
return - V_58 ;
V_53 [ V_54 ] = 0 ;
while ( ( V_57 < V_54 ) && ( V_53 [ V_57 ] == ' ' ) )
V_57 ++ ;
V_55 = V_57 ;
while ( ( V_57 < V_54 ) && ( V_53 [ V_57 ] != ' ' ) )
V_57 ++ ;
V_53 [ V_57 ] = '\0' ;
V_9 = F_32 ( & V_53 [ V_55 ] , 16 , & V_56 ) ;
if ( V_9 )
return V_9 ;
if ( V_56 > 0xff )
return - V_59 ;
if ( ! V_51 -> V_60 ) {
T_1 V_6 = ( T_1 ) V_56 ;
T_1 V_61 ;
F_10 ( V_3 , V_6 , & V_61 ) ;
F_33 ( V_3 -> V_2 ,
L_24 ,
V_6 , V_61 ) ;
} else {
int V_62 ;
unsigned long V_63 ;
T_1 V_6 = ( T_1 ) V_56 ;
T_1 V_14 ;
T_1 V_61 ;
V_57 ++ ;
while ( ( V_57 < V_54 ) && ( V_53 [ V_57 ] == ' ' ) )
V_57 ++ ;
V_62 = V_57 ;
while ( ( V_57 < V_54 ) && ( V_53 [ V_57 ] != ' ' ) )
V_57 ++ ;
V_53 [ V_57 ] = '\0' ;
V_9 = F_32 ( & V_53 [ V_62 ] , 16 , & V_63 ) ;
if ( V_9 )
return V_9 ;
if ( V_56 > 0xff )
return - V_59 ;
V_14 = ( T_1 ) V_63 ;
F_3 ( V_3 , V_6 , V_14 ) ;
F_10 ( V_3 , V_6 , & V_61 ) ;
F_33 ( V_3 -> V_2 ,
L_25
L_26 ,
V_6 , V_14 , V_61 ) ;
}
return V_54 ;
}
static void F_34 ( struct V_3 * V_3 )
{
int V_9 ;
V_64 = F_35 ( L_27 , NULL ) ;
if ( ! V_64 )
goto V_65;
V_66 = F_36 ( L_28 ,
V_67 , V_64 , V_3 ,
& V_68 ) ;
if ( ! V_66 ) {
V_9 = - V_69 ;
goto V_70;
}
V_71 . V_3 = V_3 ;
V_71 . V_60 = false ;
V_72 = F_36 ( L_29 ,
V_73 , V_64 , & V_71 ,
& V_74 ) ;
if ( ! V_72 ) {
V_9 = - V_69 ;
goto V_75;
}
V_76 . V_3 = V_3 ;
V_76 . V_60 = true ;
V_77 = F_36 ( L_30 ,
V_73 , V_64 , & V_76 ,
& V_74 ) ;
if ( ! V_77 ) {
V_9 = - V_69 ;
goto V_78;
}
return;
V_78:
F_37 ( V_72 ) ;
V_75:
F_37 ( V_66 ) ;
V_70:
F_37 ( V_64 ) ;
V_65:
return;
}
static inline void F_38 ( void )
{
F_37 ( V_77 ) ;
F_37 ( V_72 ) ;
F_37 ( V_66 ) ;
F_37 ( V_64 ) ;
}
static inline void F_34 ( struct V_3 * V_3 )
{
}
static inline void F_38 ( void )
{
}
static int F_39 ( struct V_3 * V_3 )
{
int V_9 = 0 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < F_40 ( V_79 ) ; V_57 ++ ) {
V_9 = F_3 ( V_3 ,
V_79 [ V_57 ] . V_80 ,
V_79 [ V_57 ] . V_81 ) ;
if ( V_9 )
goto V_82;
}
if ( V_3 -> V_5 == 0xc4 ) {
F_41 ( V_3 -> V_2 ,
L_31
L_32 ) ;
V_9 = F_9 ( V_3 ,
0x02 , 0x08 ) ;
}
V_82:
return V_9 ;
}
static int F_42 ( struct V_11 * V_83 ,
const struct V_84 * V_85 )
{
struct V_3 * V_3 ;
struct V_86 * V_87 =
V_83 -> V_2 . V_88 ;
int V_9 ;
int V_57 ;
V_3 = F_43 ( & V_83 -> V_2 , sizeof( struct V_3 ) , V_89 ) ;
if ( ! V_3 ) {
F_6 ( & V_83 -> V_2 , L_33 ) ;
return - V_69 ;
}
F_44 ( & V_3 -> V_10 ) ;
F_45 ( & V_3 -> V_28 ) ;
V_3 -> V_11 = V_83 ;
V_3 -> V_2 = & V_3 -> V_11 -> V_2 ;
F_46 ( V_83 , V_3 ) ;
V_9 = F_10 ( V_3 , V_90 ,
& V_3 -> V_5 ) ;
if ( V_9 ) {
F_6 ( & V_83 -> V_2 ,
L_34
L_35 ) ;
goto V_91;
}
for ( V_57 = 0 ; V_92 [ V_57 ] . V_85 != 0x0 ; V_57 ++ ) {
if ( V_92 [ V_57 ] . V_85 == V_3 -> V_5 ) {
if ( V_92 [ V_57 ] . V_93 != NULL ) {
snprintf ( & V_3 -> V_94 [ 0 ] ,
sizeof( V_3 -> V_94 ) - 1 ,
L_36 ,
V_92 [ V_57 ] . V_93 ) ;
break;
} else {
F_6 ( & V_83 -> V_2 ,
L_37 ) ;
goto V_91;
}
}
}
if ( V_92 [ V_57 ] . V_85 == 0x0 ) {
F_6 ( & V_83 -> V_2 , L_38 ,
V_3 -> V_5 ) ;
F_6 ( & V_83 -> V_2 , L_39
L_40 ) ;
goto V_91;
}
F_33 ( & V_83 -> V_2 , L_41 ,
& V_3 -> V_94 [ 0 ] ) ;
V_3 -> V_15 = F_47 ( V_83 -> V_95 ,
V_83 -> V_96 + 1 ) ;
if ( ! V_3 -> V_15 ) {
V_9 = - V_69 ;
goto V_97;
}
V_9 = F_39 ( V_3 ) ;
if ( V_9 )
goto V_82;
V_9 = F_48 ( & V_83 -> V_2 ,
V_83 -> V_33 , NULL , F_22 ,
V_98 , L_42 , V_3 ) ;
if ( V_9 )
goto V_99;
V_9 = F_49 ( & V_83 -> V_2 , & V_100 ) ;
if ( V_9 )
goto V_101;
for ( V_57 = 0 ; V_57 < F_40 ( V_102 ) ; V_57 ++ ) {
V_102 [ V_57 ] . V_88 = V_87 ;
V_102 [ V_57 ] . V_103 = sizeof( struct V_86 ) ;
}
V_9 = F_50 ( & V_83 -> V_2 , 0 , V_102 ,
F_40 ( V_102 ) , NULL , 0 , NULL ) ;
F_34 ( V_3 ) ;
return 0 ;
V_101:
V_99:
V_82:
F_51 ( V_3 -> V_15 ) ;
V_97:
V_91:
return V_9 ;
}
static int F_52 ( struct V_11 * V_83 )
{
struct V_3 * V_3 = F_53 ( V_83 ) ;
F_54 ( & V_83 -> V_2 ) ;
F_38 () ;
F_51 ( V_3 -> V_15 ) ;
return 0 ;
}
static int T_8 F_55 ( void )
{
return F_56 ( & V_104 ) ;
}
static void T_9 F_57 ( void )
{
F_58 ( & V_104 ) ;
}
