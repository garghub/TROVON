int F_1 ( T_1 * V_1 , T_2 V_2 ) {
F_2 ( V_3 , V_2 ) ;
F_3 ( V_1 , V_2 ) ;
return 1 ;
}
static void F_4 ( T_2 V_4 ) {
if ( ! V_4 ) return;
if ( ! V_4 -> V_5 ) {
V_4 -> V_5 = TRUE ;
} else {
if ( V_4 -> V_6 )
F_5 ( V_4 -> V_7 ) ;
F_6 ( V_4 ) ;
}
}
void F_7 ( void ) {
while ( V_3 -> V_8 ) {
T_2 V_4 = ( T_2 ) F_8 ( V_3 , 0 ) ;
F_4 ( V_4 ) ;
}
}
T_2 * F_9 ( T_1 * V_1 , T_3 * V_7 ) {
T_2 V_4 = ( T_2 ) F_10 ( sizeof( struct V_9 ) ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_5 = FALSE ;
V_4 -> V_6 = FALSE ;
F_2 ( V_3 , V_4 ) ;
return F_3 ( V_1 , V_4 ) ;
}
T_4 F_11 ( T_1 * V_1 ) {
T_2 V_4 = F_12 ( V_1 , 1 ) ;
int V_8 = F_13 ( V_4 -> V_7 ) ;
char * V_10 = F_14 ( NULL , V_4 -> V_7 , 0 , V_8 ) ;
F_15 ( V_1 , L_1 , V_8 , V_10 ) ;
F_16 ( NULL , V_10 ) ;
F_17 ( 1 ) ;
}
static int F_18 ( T_1 * V_1 ) {
T_2 V_4 = F_19 ( V_1 , 1 ) ;
F_4 ( V_4 ) ;
return 0 ;
}
T_5 F_20 ( T_1 * V_1 ) {
T_2 V_4 = F_12 ( V_1 , 1 ) ;
F_21 ( V_1 , F_22 ( V_4 -> V_7 ) ) ;
F_17 ( 1 ) ;
}
T_5 F_23 ( T_1 * V_1 ) {
T_2 V_4 = F_12 ( V_1 , 1 ) ;
F_21 ( V_1 , F_13 ( V_4 -> V_7 ) ) ;
F_17 ( 1 ) ;
}
T_5 F_24 ( T_1 * V_1 ) {
#define F_25 2
T_2 V_4 = F_12 ( V_1 , 1 ) ;
int V_11 = ( int ) F_26 ( V_1 , F_25 , 0 ) ;
F_21 ( V_1 , F_27 ( V_4 -> V_7 , V_11 ) ) ;
F_17 ( 1 ) ;
}
T_5 F_28 ( T_1 * V_1 ) {
#define F_29 2
#define F_30 3
T_2 V_4 = F_12 ( V_1 , 1 ) ;
T_6 * V_12 ;
int V_11 = F_31 ( V_1 , F_29 , 0 ) ;
int V_8 = F_31 ( V_1 , F_30 , - 1 ) ;
if ( V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( V_8 < 0 ) {
V_8 = F_33 ( V_4 -> V_7 , V_11 ) ;
if ( V_8 < 0 ) {
F_32 ( V_1 , L_3 ) ;
return 0 ;
}
} else if ( ( V_13 ) ( V_8 + V_11 ) > F_13 ( V_4 -> V_7 ) ) {
F_32 ( V_1 , L_4 ) ;
return 0 ;
}
V_12 = F_34 () ;
F_35 ( V_12 , F_36 ( V_4 -> V_7 , V_11 , V_8 ) , V_8 ) ;
F_37 ( V_1 , V_12 ) ;
F_17 ( 1 ) ;
}
T_5 F_38 ( T_1 * V_1 ) {
T_2 V_4 = F_12 ( V_1 , 1 ) ;
F_21 ( V_1 , F_39 ( V_4 -> V_7 ) ) ;
F_17 ( 1 ) ;
}
T_4 F_40 ( T_1 * V_1 ) {
return 0 ;
}
T_5 F_41 ( T_1 * V_1 ) {
#define F_42 2
#define F_43 3
T_2 V_4 = F_12 ( V_1 , 1 ) ;
int V_11 = ( int ) F_26 ( V_1 , F_42 , 0 ) ;
int V_8 = ( int ) F_26 ( V_1 , F_43 , - 1 ) ;
if ( F_44 ( V_1 , V_4 -> V_7 , V_11 , V_8 ) ) {
F_17 ( 1 ) ;
}
return 0 ;
}
T_5 F_45 ( T_1 * V_1 ) {
#define F_46 2
#define F_47 3
T_2 V_4 = F_12 ( V_1 , 1 ) ;
int V_11 = ( int ) F_26 ( V_1 , F_46 , 0 ) ;
int V_8 = ( int ) F_26 ( V_1 , F_47 , - 1 ) ;
if ( ! V_4 ) return 0 ;
if ( V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( ( V_13 ) V_11 > F_13 ( V_4 -> V_7 ) ) {
F_48 ( F_45 , V_14 , L_5 ) ;
return 0 ;
}
if ( V_8 == - 1 ) {
V_8 = F_33 ( V_4 -> V_7 , V_11 ) ;
if ( V_8 < 0 ) {
F_32 ( V_1 , L_3 ) ;
return FALSE ;
}
} else if ( ( V_13 ) ( V_8 + V_11 ) > F_13 ( V_4 -> V_7 ) ) {
F_32 ( V_1 , L_4 ) ;
return FALSE ;
}
F_49 ( V_1 , F_36 ( V_4 -> V_7 , V_11 , V_8 ) , V_8 ) ;
F_17 ( 1 ) ;
}
T_4 F_50 ( T_1 * V_1 ) {
T_2 V_15 = F_12 ( V_1 , 1 ) ;
T_2 V_16 = F_12 ( V_1 , 2 ) ;
int V_17 = F_13 ( V_15 -> V_7 ) ;
int V_18 = F_13 ( V_16 -> V_7 ) ;
if ( V_17 == V_18 )
{
const T_7 * V_19 = F_36 ( V_15 -> V_7 , 0 , V_17 ) ;
const T_7 * V_20 = F_36 ( V_16 -> V_7 , 0 , V_18 ) ;
int V_21 = 0 ;
for (; V_21 < V_17 ; ++ V_21 ) {
if ( V_19 [ V_21 ] != V_20 [ V_21 ] ) {
F_51 ( V_1 , 0 ) ;
return 1 ;
}
}
F_51 ( V_1 , 1 ) ;
} else {
F_51 ( V_1 , 0 ) ;
}
return 1 ;
}
int F_52 ( T_1 * V_1 ) {
F_53 ( T_2 ) ;
V_3 = F_54 () ;
return 0 ;
}
static void F_55 ( T_8 V_22 ) {
if ( ! ( V_22 && V_22 -> V_4 ) ) return;
if ( ! V_22 -> V_4 -> V_5 ) {
V_22 -> V_4 -> V_5 = TRUE ;
} else {
F_4 ( V_22 -> V_4 ) ;
F_6 ( V_22 ) ;
}
}
void F_56 ( void ) {
while ( V_23 -> V_8 ) {
T_8 V_22 = ( T_8 ) F_8 ( V_23 , 0 ) ;
F_55 ( V_22 ) ;
}
}
T_9 F_44 ( T_1 * V_1 , T_3 * V_7 , int V_11 , int V_8 ) {
T_8 V_22 ;
if ( ! V_7 ) {
F_32 ( V_1 , L_2 ) ;
return FALSE ;
}
if ( V_8 == - 1 ) {
V_8 = F_33 ( V_7 , V_11 ) ;
if ( V_8 < 0 ) {
F_32 ( V_1 , L_3 ) ;
return FALSE ;
}
} else if ( ( V_13 ) ( V_8 + V_11 ) > F_13 ( V_7 ) ) {
F_32 ( V_1 , L_4 ) ;
return FALSE ;
}
V_22 = ( T_8 ) F_10 ( sizeof( struct V_24 ) ) ;
V_22 -> V_4 = ( T_2 ) F_10 ( sizeof( struct V_9 ) ) ;
V_22 -> V_4 -> V_7 = V_7 ;
V_22 -> V_4 -> V_5 = FALSE ;
V_22 -> V_4 -> V_6 = FALSE ;
V_22 -> V_11 = V_11 ;
V_22 -> V_8 = V_8 ;
F_57 ( V_1 , V_22 ) ;
return TRUE ;
}
T_10 F_58 ( T_1 * V_1 ) {
#define F_59 1
T_8 V_22 = F_60 ( V_1 , F_59 ) ;
T_2 V_4 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( F_61 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 + V_22 -> V_8 - 1 ) ) {
V_4 = ( T_2 ) F_10 ( sizeof( struct V_9 ) ) ;
V_4 -> V_5 = FALSE ;
V_4 -> V_6 = FALSE ;
V_4 -> V_7 = F_62 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 , V_22 -> V_8 , V_22 -> V_8 ) ;
return F_1 ( V_1 , V_4 ) ;
} else {
F_32 ( V_1 , L_6 ) ;
return 0 ;
}
}
T_5 F_63 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 1 :
F_21 ( V_1 , F_64 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 2 :
F_21 ( V_1 , F_65 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 3 :
F_21 ( V_1 , F_66 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 4 :
F_21 ( V_1 , F_67 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_7 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_68 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 1 :
F_21 ( V_1 , ( V_25 ) ( V_13 ) F_64 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 2 :
F_21 ( V_1 , F_69 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 3 :
F_21 ( V_1 , F_70 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 4 :
F_21 ( V_1 , F_71 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_8 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_72 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 1 :
F_73 ( V_1 , F_64 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 2 :
F_73 ( V_1 , F_65 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 3 :
F_73 ( V_1 , F_66 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 4 :
F_73 ( V_1 , F_67 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 5 :
F_73 ( V_1 , F_74 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 6 :
F_73 ( V_1 , F_75 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 7 :
F_73 ( V_1 , F_76 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 8 :
F_73 ( V_1 , F_77 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_9 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_78 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 1 :
F_73 ( V_1 , F_64 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 2 :
F_73 ( V_1 , F_69 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 3 :
F_73 ( V_1 , F_70 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 4 :
F_73 ( V_1 , F_71 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 5 :
F_73 ( V_1 , F_79 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 6 :
F_73 ( V_1 , F_80 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 7 :
F_73 ( V_1 , F_81 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 8 :
F_73 ( V_1 , F_82 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_10 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_83 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 1 :
F_21 ( V_1 , ( T_7 ) F_64 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 2 :
F_21 ( V_1 , ( V_26 ) F_65 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 4 :
F_21 ( V_1 , ( V_27 ) F_67 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_11 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_84 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 1 :
F_21 ( V_1 , ( T_7 ) F_64 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 2 :
F_21 ( V_1 , ( V_26 ) F_69 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 4 :
F_21 ( V_1 , ( V_27 ) F_71 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_12 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_85 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 1 :
F_86 ( V_1 , ( V_28 ) F_64 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 2 :
F_86 ( V_1 , ( V_29 ) F_65 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 4 :
F_86 ( V_1 , ( V_30 ) F_67 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 8 :
F_86 ( V_1 , ( V_31 ) F_77 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_13 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_87 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 1 :
F_86 ( V_1 , ( V_28 ) F_64 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 2 :
F_86 ( V_1 , ( V_29 ) F_69 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 4 :
F_86 ( V_1 , ( V_30 ) F_71 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 8 :
F_86 ( V_1 , ( V_31 ) F_82 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_14 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_88 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_22 -> V_8 ) {
case 4 :
F_21 ( V_1 , ( double ) F_89 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 8 :
F_21 ( V_1 , F_90 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_15 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_91 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
switch ( V_22 -> V_8 ) {
case 4 :
F_21 ( V_1 , F_92 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
return 1 ;
case 8 :
F_21 ( V_1 , F_93 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_17 ( 1 ) ;
default:
F_32 ( V_1 , L_16 , V_22 -> V_8 ) ;
return 0 ;
}
}
T_5 F_94 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
T_11 V_32 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( V_22 -> V_8 != 4 ) {
F_95 ( F_94 , L_17 ) ;
return 0 ;
}
V_32 = F_96 ( V_33 , 1 ) ;
F_97 ( NULL , V_32 , V_34 , sizeof( V_35 ) , V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ;
F_98 ( V_1 , V_32 ) ;
F_17 ( 1 ) ;
}
T_5 F_99 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
T_11 V_32 ;
V_35 V_36 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( V_22 -> V_8 != 4 ) {
F_95 ( F_94 , L_17 ) ;
return 0 ;
}
V_32 = F_96 ( V_33 , 1 ) ;
V_36 = F_100 ( F_101 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
F_102 ( NULL , V_32 , V_34 , sizeof( V_36 ) , & V_36 ) ;
F_98 ( V_1 , V_32 ) ;
F_17 ( 1 ) ;
}
T_5 F_103 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
T_11 V_32 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( V_22 -> V_8 != 6 ) {
F_95 ( F_103 , L_18 ) ;
return 0 ;
}
V_32 = F_96 ( V_33 , 1 ) ;
F_97 ( NULL , V_32 , V_37 , 6 , V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ;
F_98 ( V_1 , V_32 ) ;
F_17 ( 1 ) ;
}
T_5 F_104 ( T_1 * V_1 ) {
#define F_105 2
T_8 V_22 = F_60 ( V_1 , 1 ) ;
T_12 V_38 ;
const V_13 V_39 = ( V_13 ) F_26 ( V_1 , F_105 , 0 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
V_38 = F_96 ( V_40 , 1 ) ;
if ( V_39 == 0 ) {
if ( V_22 -> V_8 == 4 ) {
V_38 -> V_41 = F_67 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ;
V_38 -> V_42 = 0 ;
} else if ( V_22 -> V_8 == 8 ) {
V_38 -> V_41 = F_67 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ;
V_38 -> V_42 = F_67 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 + 4 ) ;
} else {
F_6 ( V_38 ) ;
F_95 ( F_104 , L_19 ) ;
return 0 ;
}
F_106 ( V_1 , V_38 ) ;
F_107 ( V_1 , V_22 -> V_8 ) ;
}
else if ( V_39 & ~ V_43 ) {
F_48 ( F_104 , V_44 , L_20 ) ;
}
else {
V_27 V_45 = 0 ;
V_40 * V_46 = F_108 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 , V_22 -> V_8 ,
V_39 , V_38 , & V_45 ) ;
if ( ! V_46 || V_45 == 0 ) {
F_6 ( V_38 ) ;
F_109 ( V_1 ) ;
F_109 ( V_1 ) ;
}
else {
F_106 ( V_1 , V_38 ) ;
F_107 ( V_1 , V_45 ) ;
}
}
F_17 ( 2 ) ;
}
T_5 F_110 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
T_12 V_38 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
V_38 = F_96 ( V_40 , 1 ) ;
if ( V_22 -> V_8 == 4 ) {
V_38 -> V_41 = F_71 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ;
V_38 -> V_42 = 0 ;
} else if ( V_22 -> V_8 == 8 ) {
V_38 -> V_41 = F_71 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ;
V_38 -> V_42 = F_71 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 + 4 ) ;
} else {
F_6 ( V_38 ) ;
F_95 ( F_104 , L_19 ) ;
return 0 ;
}
F_106 ( V_1 , V_38 ) ;
F_17 ( 1 ) ;
}
T_5 F_111 ( T_1 * V_1 ) {
#define F_112 2
T_8 V_22 = F_60 ( V_1 , 1 ) ;
V_13 V_39 = ( V_13 ) F_26 ( V_1 , F_112 , V_47 | V_48 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
F_49 ( V_1 , ( T_7 * ) F_113 ( F_114 () , V_22 -> V_4 -> V_7 , V_22 -> V_11 , V_22 -> V_8 , V_39 ) , V_22 -> V_8 ) ;
F_17 ( 1 ) ;
}
static int F_115 ( T_1 * V_1 , T_9 V_49 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
T_7 * V_10 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
V_10 = ( T_7 * ) F_113 ( F_114 () , V_22 -> V_4 -> V_7 , V_22 -> V_11 , V_22 -> V_8 , ( V_49 ? V_50 | V_51 : V_50 | V_52 ) ) ;
F_49 ( V_1 , V_10 , strlen ( V_10 ) ) ;
return 1 ;
}
T_5 F_116 ( T_1 * V_1 ) {
F_17 ( F_115 ( V_1 , FALSE ) ) ;
}
T_5 F_117 ( T_1 * V_1 ) {
F_17 ( F_115 ( V_1 , TRUE ) ) ;
}
T_5 F_118 ( T_1 * V_1 ) {
#define F_119 2
T_8 V_22 = F_60 ( V_1 , 1 ) ;
V_13 V_39 = ( V_13 ) F_26 ( V_1 , F_119 , V_47 | V_48 ) ;
V_27 V_11 ;
T_13 V_53 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_39 & V_54 ) {
case V_50 :
case V_55 :
V_11 = V_22 -> V_11 ;
do {
if ( ! F_120 ( V_22 -> V_4 -> V_7 , V_11 , 2 ) ) {
F_32 ( V_1 , L_3 ) ;
return 0 ;
}
V_53 = F_65 ( V_22 -> V_4 -> V_7 , V_11 ) ;
V_11 += 2 ;
} while( V_53 != 0 );
break;
default:
if ( F_121 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 , - 1 , 0 ) == - 1 ) {
F_32 ( V_1 , L_3 ) ;
return 0 ;
}
break;
}
F_122 ( V_1 , ( T_7 * ) F_123 ( F_114 () , V_22 -> V_4 -> V_7 , V_22 -> V_11 , NULL , V_39 ) ) ;
F_17 ( 1 ) ;
}
T_5 F_124 ( T_1 * V_1 ) {
#define F_125 2
T_8 V_22 = F_60 ( V_1 , 1 ) ;
V_13 V_39 = ( V_13 ) F_26 ( V_1 , F_125 , V_47 | V_48 ) ;
V_27 V_11 ;
T_13 V_53 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
switch ( V_39 & V_54 ) {
case V_50 :
case V_55 :
V_11 = V_22 -> V_11 ;
do {
if ( ! F_120 ( V_22 -> V_4 -> V_7 , V_11 , 2 ) ) {
F_32 ( V_1 , L_3 ) ;
return 0 ;
}
V_53 = F_65 ( V_22 -> V_4 -> V_7 , V_11 ) ;
V_11 += 2 ;
} while ( V_53 != 0 );
F_107 ( V_1 , F_126 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
break;
default:
if ( F_121 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 , - 1 , 0 ) == - 1 ) {
F_32 ( V_1 , L_3 ) ;
return 0 ;
}
F_107 ( V_1 , F_127 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 ) ) ;
break;
}
F_17 ( 1 ) ;
}
static int F_128 ( T_1 * V_1 , T_9 V_49 ) {
V_27 V_56 ;
T_8 V_22 = F_60 ( V_1 , 1 ) ;
V_27 V_11 ;
T_13 V_53 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
V_11 = V_22 -> V_11 ;
do {
if ( ! F_120 ( V_22 -> V_4 -> V_7 , V_11 , 2 ) ) {
F_32 ( V_1 , L_3 ) ;
return 0 ;
}
V_53 = F_65 ( V_22 -> V_4 -> V_7 , V_11 ) ;
V_11 += 2 ;
} while ( V_53 != 0 );
F_122 ( V_1 , ( T_7 * ) F_123 ( F_114 () , V_22 -> V_4 -> V_7 , V_22 -> V_11 , & V_56 ,
( V_49 ? V_50 | V_51 : V_50 | V_52 ) ) ) ;
F_107 ( V_1 , V_56 ) ;
return 2 ;
}
T_5 F_129 ( T_1 * V_1 ) {
F_17 ( F_128 ( V_1 , FALSE ) ) ;
}
T_5 F_130 ( T_1 * V_1 ) {
F_17 ( F_128 ( V_1 , TRUE ) ) ;
}
T_5 F_131 ( T_1 * V_1 ) {
#define F_132 2
T_8 V_22 = F_60 ( V_1 , 1 ) ;
T_6 * V_12 ;
const V_13 V_39 = ( V_13 ) F_26 ( V_1 , F_132 , 0 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( V_39 == 0 ) {
V_12 = F_34 () ;
F_35 ( V_12 , ( const V_57 * ) F_133 ( F_114 () , V_22 -> V_4 -> V_7 , V_22 -> V_11 , V_22 -> V_8 ) , V_22 -> V_8 ) ;
F_37 ( V_1 , V_12 ) ;
F_107 ( V_1 , V_22 -> V_8 ) ;
}
else if ( ( V_39 & V_58 ) == 0 ) {
F_48 ( F_104 , V_44 , L_20 ) ;
}
else {
V_27 V_45 = 0 ;
T_6 * V_46 ;
V_12 = F_34 () ;
V_46 = F_134 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 , V_22 -> V_8 ,
V_39 , V_12 , & V_45 ) ;
if ( ! V_46 || V_45 == 0 ) {
F_135 ( V_12 , TRUE ) ;
F_109 ( V_1 ) ;
F_109 ( V_1 ) ;
}
else {
F_37 ( V_1 , V_12 ) ;
F_107 ( V_1 , V_45 ) ;
}
}
F_17 ( 2 ) ;
}
T_5 F_136 ( T_1 * V_1 ) {
#define F_137 2
#define F_138 3
T_8 V_22 = F_60 ( V_1 , 1 ) ;
int V_59 = ( int ) F_26 ( V_1 , F_137 , 0 ) ;
int V_8 = ( int ) F_26 ( V_1 , F_138 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( ( V_59 + V_8 ) > ( V_22 -> V_8 << 3 ) ) {
F_32 ( V_1 , L_21 ) ;
return 0 ;
}
if ( V_8 <= 8 ) {
F_21 ( V_1 , ( V_25 ) ( V_13 ) F_139 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 * 8 + V_59 , V_8 ) ) ;
return 1 ;
} else if ( V_8 <= 16 ) {
F_21 ( V_1 , F_140 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 * 8 + V_59 , V_8 , FALSE ) ) ;
return 1 ;
} else if ( V_8 <= 32 ) {
F_21 ( V_1 , F_141 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 * 8 + V_59 , V_8 , FALSE ) ) ;
return 1 ;
} else if ( V_8 <= 64 ) {
F_73 ( V_1 , F_142 ( V_22 -> V_4 -> V_7 , V_22 -> V_11 * 8 + V_59 , V_8 , FALSE ) ) ;
F_17 ( 1 ) ;
} else {
F_32 ( V_1 , L_22 , V_8 ) ;
return 0 ;
}
}
T_5 F_143 ( T_1 * V_1 ) {
#define F_144 2
#define F_145 3
T_8 V_22 = F_60 ( V_1 , 1 ) ;
int V_11 = ( int ) F_26 ( V_1 , F_144 , 0 ) ;
int V_8 ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
V_8 = ( int ) F_26 ( V_1 , F_145 , V_22 -> V_8 - V_11 ) ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( V_11 >= V_22 -> V_8 || ( V_8 + V_11 ) > V_22 -> V_8 ) {
F_32 ( V_1 , L_4 ) ;
return 0 ;
}
if ( F_44 ( V_1 , V_22 -> V_4 -> V_7 , V_22 -> V_11 + V_11 , V_8 ) ) {
F_17 ( 1 ) ;
}
return 0 ;
}
T_5 F_146 ( T_1 * V_1 ) {
#define F_147 2
T_8 V_22 = F_60 ( V_1 , 1 ) ;
#ifdef F_148
const T_7 * V_60 = F_149 ( V_1 , F_147 , L_23 ) ;
T_3 * V_61 ;
#endif
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
#ifdef F_148
V_61 = F_150 ( V_22 -> V_4 -> V_7 , V_22 -> V_4 -> V_7 , V_22 -> V_11 , V_22 -> V_8 ) ;
if ( V_61 ) {
F_151 ( V_62 , V_61 , V_60 ) ;
if ( F_44 ( V_1 , V_61 , 0 , F_13 ( V_61 ) ) ) {
F_17 ( 1 ) ;
}
}
#else
F_32 ( V_1 , L_24 ) ;
#endif
return 0 ;
}
static int F_152 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
F_55 ( V_22 ) ;
return 0 ;
}
T_5 F_153 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
F_21 ( V_1 , ( V_25 ) V_22 -> V_8 ) ;
return 1 ;
}
T_5 F_154 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
F_21 ( V_1 , ( V_25 ) V_22 -> V_11 ) ;
return 1 ;
}
T_5 F_155 ( T_1 * V_1 ) {
#define F_156 2
#define F_157 3
T_8 V_22 = F_60 ( V_1 , 1 ) ;
int V_11 = ( int ) F_26 ( V_1 , F_156 , 0 ) ;
int V_8 = ( int ) F_26 ( V_1 , F_157 , - 1 ) ;
if ( ! V_22 || ! V_22 -> V_4 ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
if ( ( V_13 ) V_11 > F_13 ( V_22 -> V_4 -> V_7 ) ) {
F_48 ( F_155 , V_14 , L_5 ) ;
return 0 ;
}
if ( V_8 == - 1 ) {
V_8 = F_33 ( V_22 -> V_4 -> V_7 , V_11 ) ;
if ( V_8 < 0 ) {
F_32 ( V_1 , L_3 ) ;
return FALSE ;
}
} else if ( ( V_13 ) ( V_8 + V_11 ) > F_13 ( V_22 -> V_4 -> V_7 ) ) {
F_32 ( V_1 , L_4 ) ;
return FALSE ;
}
F_49 ( V_1 , F_36 ( V_22 -> V_4 -> V_7 , V_11 , V_8 ) , V_8 ) ;
F_17 ( 1 ) ;
}
T_4 F_158 ( T_1 * V_1 ) {
T_8 V_15 = F_60 ( V_1 , 1 ) ;
T_8 V_16 = F_60 ( V_1 , 2 ) ;
if ( V_15 -> V_8 == V_16 -> V_8 &&
V_15 -> V_8 <= F_33 ( V_15 -> V_4 -> V_7 , V_15 -> V_11 ) &&
V_16 -> V_8 <= F_33 ( V_16 -> V_4 -> V_7 , V_16 -> V_11 ) )
{
const T_7 * V_19 = F_36 ( V_15 -> V_4 -> V_7 , V_15 -> V_11 , V_15 -> V_8 ) ;
const T_7 * V_20 = F_36 ( V_16 -> V_4 -> V_7 , V_16 -> V_11 , V_16 -> V_8 ) ;
int V_21 = 0 ;
for (; V_21 < V_16 -> V_8 ; ++ V_21 ) {
if ( V_19 [ V_21 ] != V_20 [ V_21 ] ) {
F_51 ( V_1 , 0 ) ;
return 1 ;
}
}
F_51 ( V_1 , 1 ) ;
} else {
F_51 ( V_1 , 0 ) ;
}
return 1 ;
}
T_4 F_159 ( T_1 * V_1 ) {
T_8 V_22 = F_60 ( V_1 , 1 ) ;
char * V_10 = NULL ;
if ( ! ( V_22 && V_22 -> V_4 ) ) return 0 ;
if ( V_22 -> V_4 -> V_5 ) {
F_32 ( V_1 , L_2 ) ;
return 0 ;
}
V_10 = F_14 ( NULL , V_22 -> V_4 -> V_7 , V_22 -> V_11 , V_22 -> V_8 ) ;
F_122 ( V_1 , V_10 ) ;
F_16 ( NULL , V_10 ) ;
F_17 ( 1 ) ;
}
int F_160 ( T_1 * V_1 ) {
V_23 = F_54 () ;
F_53 ( T_8 ) ;
return 0 ;
}
