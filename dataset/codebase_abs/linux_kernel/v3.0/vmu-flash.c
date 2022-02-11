static struct V_1 * F_1 ( unsigned long V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_1 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_12 = V_4 -> V_14 ;
V_8 = V_12 -> V_8 ;
V_10 = F_2 ( V_8 ) ;
if ( V_2 >= V_10 -> V_15 [ V_5 ] . V_16 * V_10 -> V_17 )
goto V_18;
V_13 = V_2 / V_10 -> V_17 ;
if ( V_13 > V_10 -> V_15 [ V_5 ] . V_16 )
goto V_18;
V_6 = F_3 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_6 )
goto V_18;
V_6 -> V_13 = V_13 ;
V_6 -> V_20 = V_2 % V_10 -> V_17 ;
return V_6 ;
V_18:
return NULL ;
}
static void F_4 ( struct V_21 * V_22 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_8 = V_22 -> V_23 ;
V_10 = F_2 ( V_8 ) ;
if ( F_5 ( ! V_10 -> V_24 ) )
return;
memcpy ( V_10 -> V_24 , V_22 -> V_25 -> V_26 + 12 ,
V_10 -> V_17 / V_10 -> V_27 ) ;
}
static int F_6 ( unsigned int V_13 , unsigned char * V_26 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_7 * V_8 ;
int V_5 , error = 0 , V_28 , V_29 ;
unsigned char * V_24 = NULL ;
struct V_30 * V_31 ;
T_1 V_32 ;
V_12 = V_4 -> V_14 ;
V_8 = V_12 -> V_8 ;
V_5 = V_12 -> V_5 ;
V_10 = F_2 ( V_8 ) ;
V_31 = V_10 -> V_15 [ V_5 ] . V_31 ;
V_31 -> V_33 = 0 ;
if ( ! V_31 -> V_34 ) {
V_31 -> V_34 = F_3 ( V_10 -> V_17 , V_19 ) ;
if ( ! V_31 -> V_34 ) {
F_7 ( & V_8 -> V_23 , L_1
L_2 , V_8 -> V_35 ,
V_8 -> V_36 ) ;
error = - V_37 ;
goto V_38;
}
}
for ( V_28 = 0 ; V_28 < V_10 -> V_27 ; V_28 ++ ) {
V_32 = F_8 ( V_5 << 24 | V_28 << 16 | V_13 ) ;
if ( F_9 ( & V_8 -> V_39 ) == 1 ) {
F_10 ( V_8 -> V_40 ,
F_9 ( & V_8 -> V_39 ) == 0 , V_41 ) ;
if ( F_9 ( & V_8 -> V_39 ) == 1 ) {
F_11 ( & V_8 -> V_23 , L_3
L_4 , V_8 -> V_35 , V_8 -> V_36 ) ;
error = - V_42 ;
goto V_38;
}
}
F_12 ( & V_8 -> V_39 , 1 ) ;
V_24 = F_3 ( V_10 -> V_17 / V_10 -> V_27 , V_19 ) ;
if ( ! V_24 ) {
error = - V_37 ;
F_12 ( & V_8 -> V_39 , 0 ) ;
goto V_38;
}
V_10 -> V_24 = V_24 ;
F_13 ( V_8 , F_4 , 0 ,
V_43 ) ;
error = F_14 ( V_8 , V_43 ,
V_44 , 2 , & V_32 ) ;
V_29 = F_10 ( V_8 -> V_40 ,
( F_9 ( & V_8 -> V_39 ) == 0 ||
F_9 ( & V_8 -> V_39 ) == 2 ) , V_41 * 3 ) ;
if ( error || F_9 ( & V_8 -> V_39 ) == 2 ) {
if ( F_9 ( & V_8 -> V_39 ) == 2 )
error = - V_45 ;
F_12 ( & V_8 -> V_39 , 0 ) ;
V_10 -> V_24 = NULL ;
goto V_46;
}
if ( V_29 == 0 || V_29 == - V_47 ) {
V_10 -> V_24 = NULL ;
F_12 ( & V_8 -> V_39 , 0 ) ;
error = - V_48 ;
F_15 ( & ( V_8 -> V_22 -> V_49 ) ) ;
F_16 ( V_8 -> V_22 -> V_32 ) ;
V_8 -> V_22 -> V_32 = NULL ;
if ( V_29 == - V_47 ) {
F_17 ( & V_8 -> V_23 , L_5
L_6 ,
V_8 -> V_35 , V_8 -> V_36 , V_13 ) ;
} else
F_11 ( & V_8 -> V_23 , L_5
L_7 ,
V_8 -> V_35 , V_8 -> V_36 , V_13 ) ;
goto V_46;
}
memcpy ( V_26 + ( V_10 -> V_17 / V_10 -> V_27 ) * V_28 , V_24 ,
V_10 -> V_17 / V_10 -> V_27 ) ;
memcpy ( V_31 -> V_34 + ( V_10 -> V_17 / V_10 -> V_27 ) * V_28 ,
V_10 -> V_24 , V_10 -> V_17 / V_10 -> V_27 ) ;
V_10 -> V_24 = NULL ;
V_31 -> V_50 = V_13 ;
V_31 -> V_51 = V_52 ;
V_31 -> V_33 = 1 ;
F_16 ( V_24 ) ;
}
return error ;
V_46:
F_16 ( V_24 ) ;
V_38:
return error ;
}
static int F_18 ( unsigned int V_13 , const unsigned char * V_26 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_7 * V_8 ;
int V_5 , error , V_53 , V_28 , V_54 , V_29 ;
T_1 * V_32 ;
V_12 = V_4 -> V_14 ;
V_8 = V_12 -> V_8 ;
V_5 = V_12 -> V_5 ;
V_10 = F_2 ( V_8 ) ;
V_54 = V_10 -> V_17 / V_10 -> V_55 ;
V_32 = F_3 ( V_54 + 4 , V_19 ) ;
if ( ! V_32 ) {
error = - V_37 ;
goto V_56;
}
for ( V_28 = 0 ; V_28 < V_10 -> V_55 ; V_28 ++ ) {
V_32 [ 0 ] = F_8 ( V_5 << 24 | V_28 << 16 | V_13 ) ;
memcpy ( & V_32 [ 1 ] , V_26 + V_54 * V_28 , V_54 ) ;
if ( F_9 ( & V_8 -> V_39 ) == 1 ) {
F_10 ( V_8 -> V_40 ,
F_9 ( & V_8 -> V_39 ) == 0 , V_41 ) ;
if ( F_9 ( & V_8 -> V_39 ) == 1 ) {
error = - V_57 ;
F_11 ( & V_8 -> V_23 , L_8
L_9 ,
V_8 -> V_35 , V_8 -> V_36 ) ;
goto V_58;
}
}
F_12 ( & V_8 -> V_39 , 1 ) ;
V_53 = F_14 ( V_8 , V_43 ,
V_59 , V_54 / 4 + 2 , V_32 ) ;
V_29 = F_10 ( V_8 -> V_40 ,
F_9 ( & V_8 -> V_39 ) == 0 , V_41 / 10 ) ;
if ( V_53 ) {
error = - V_48 ;
F_12 ( & V_8 -> V_39 , 0 ) ;
goto V_58;
}
if ( F_9 ( & V_8 -> V_39 ) == 2 ) {
F_12 ( & V_8 -> V_39 , 0 ) ;
} else if ( V_29 == 0 || V_29 == - V_47 ) {
error = - V_48 ;
F_17 ( & V_8 -> V_23 , L_10
L_11
L_12 , V_8 -> V_35 ,
V_8 -> V_36 , V_13 , V_28 ) ;
F_12 ( & V_8 -> V_39 , 0 ) ;
F_16 ( V_8 -> V_22 -> V_32 ) ;
V_8 -> V_22 -> V_32 = NULL ;
F_15 ( & ( V_8 -> V_22 -> V_49 ) ) ;
goto V_58;
}
}
F_16 ( V_32 ) ;
return V_10 -> V_17 ;
V_58:
F_16 ( V_32 ) ;
V_56:
F_7 ( & V_8 -> V_23 , L_13 , V_8 -> V_35 ,
V_8 -> V_36 ) ;
return error ;
}
static unsigned char F_19 ( unsigned long V_20 , int * V_60 ,
struct V_3 * V_4 )
{
struct V_1 * V_6 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_7 * V_8 ;
unsigned char * V_26 , V_61 ;
int V_5 , error ;
V_12 = V_4 -> V_14 ;
V_8 = V_12 -> V_8 ;
V_5 = V_12 -> V_5 ;
V_10 = F_2 ( V_8 ) ;
* V_60 = 0 ;
V_26 = F_3 ( V_10 -> V_17 , V_19 ) ;
if ( ! V_26 ) {
* V_60 = 1 ;
V_61 = - V_37 ;
goto V_62;
}
V_6 = F_1 ( V_20 , V_4 , V_5 ) ;
if ( ! V_6 ) {
* V_60 = 3 ;
V_61 = - V_37 ;
goto V_63;
}
error = F_6 ( V_6 -> V_13 , V_26 , V_4 ) ;
if ( error ) {
V_61 = error ;
* V_60 = 2 ;
goto V_64;
}
V_61 = V_26 [ V_6 -> V_20 ] ;
V_64:
F_16 ( V_6 ) ;
V_63:
F_16 ( V_26 ) ;
V_62:
return V_61 ;
}
static int F_20 ( struct V_3 * V_4 , T_2 V_65 , T_3 V_66 ,
T_3 * V_67 , T_4 * V_26 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_30 * V_31 ;
struct V_1 * V_6 ;
int V_68 = 0 , V_60 , V_5 , V_69 , V_16 ;
unsigned char V_70 ;
if ( V_66 < 1 )
return - V_48 ;
V_12 = V_4 -> V_14 ;
V_8 = V_12 -> V_8 ;
V_5 = V_12 -> V_5 ;
V_10 = F_2 ( V_8 ) ;
V_16 = V_10 -> V_15 [ V_5 ] . V_16 ;
if ( V_65 + V_66 > V_16 * V_10 -> V_17 )
V_66 = V_16 * V_10 -> V_17 - V_65 ;
if ( V_66 == 0 )
return - V_48 ;
V_31 = V_10 -> V_15 [ V_5 ] . V_31 ;
do {
V_6 = F_1 ( V_65 + V_68 , V_4 , V_5 ) ;
if ( ! V_6 )
return - V_37 ;
if ( V_31 -> V_33 &&
F_21 ( V_52 , V_31 -> V_51 + V_41 ) &&
( V_31 -> V_50 == V_6 -> V_13 ) ) {
V_69 = V_10 -> V_17 - V_6 -> V_20 ;
if ( V_6 -> V_20 + V_66 - V_68 < V_10 -> V_17 ) {
memcpy ( V_26 + V_68 ,
V_31 -> V_34 + V_6 -> V_20 ,
V_66 - V_68 ) ;
V_68 = V_66 ;
} else {
memcpy ( V_26 + V_68 , V_31 -> V_34 +
V_6 -> V_20 , V_69 ) ;
V_68 += V_69 ;
}
} else {
V_70 = F_19 ( V_65 + V_68 , & V_60 , V_4 ) ;
if ( V_60 ) {
* V_67 = V_68 ;
F_16 ( V_6 ) ;
return V_70 ;
}
memset ( V_26 + V_68 , V_70 , 1 ) ;
V_68 ++ ;
}
F_16 ( V_6 ) ;
} while ( V_66 > V_68 );
* V_67 = V_68 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , T_2 V_71 , T_3 V_66 ,
T_3 * V_67 , const T_4 * V_26 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_68 = 0 , V_5 , error = 0 , V_16 ;
struct V_30 * V_31 ;
struct V_1 * V_6 ;
unsigned char * V_34 ;
V_12 = V_4 -> V_14 ;
V_8 = V_12 -> V_8 ;
V_5 = V_12 -> V_5 ;
V_10 = F_2 ( V_8 ) ;
if ( V_66 < 1 ) {
error = - V_48 ;
goto V_18;
}
V_16 = V_10 -> V_15 [ V_5 ] . V_16 ;
if ( V_71 + V_66 > V_16 * V_10 -> V_17 )
V_66 = V_16 * V_10 -> V_17 - V_71 ;
if ( V_66 == 0 ) {
error = - V_48 ;
goto V_18;
}
V_6 = F_1 ( V_71 , V_4 , V_5 ) ;
if ( ! V_6 ) {
error = - V_37 ;
goto V_18;
}
V_34 = F_3 ( V_10 -> V_17 , V_19 ) ;
if ( ! V_34 ) {
error = - V_37 ;
goto V_72;
}
do {
error = F_6 ( V_6 -> V_13 , V_34 , V_4 ) ;
if ( error )
goto V_73;
do {
V_34 [ V_6 -> V_20 ] = V_26 [ V_68 ] ;
V_6 -> V_20 ++ ;
V_68 ++ ;
if ( V_68 >= V_66 )
break;
} while ( V_6 -> V_20 < V_10 -> V_17 );
error = F_18 ( V_6 -> V_13 , V_34 , V_4 ) ;
V_31 = V_10 -> V_15 [ V_5 ] . V_31 ;
V_31 -> V_33 = 0 ;
if ( error != V_10 -> V_17 )
goto V_73;
V_6 -> V_13 ++ ;
V_6 -> V_20 = 0 ;
} while ( V_66 > V_68 );
F_16 ( V_34 ) ;
* V_67 = V_68 ;
F_16 ( V_6 ) ;
return 0 ;
V_73:
F_16 ( V_34 ) ;
V_72:
F_16 ( V_6 ) ;
V_18:
F_7 ( & V_8 -> V_23 , L_14 , error ) ;
return error ;
}
static void F_23 ( struct V_3 * V_4 )
{
}
static void F_24 ( struct V_21 * V_22 )
{
struct V_7 * V_8 ;
unsigned short * V_74 ;
struct V_9 * V_10 ;
T_1 V_75 ;
struct V_30 * V_31 ;
struct V_11 * V_12 ;
struct V_3 * V_76 ;
struct V_77 * V_78 ;
int error ;
V_8 = V_22 -> V_23 ;
V_10 = F_2 ( V_8 ) ;
V_74 = ( unsigned short * ) ( V_22 -> V_25 -> V_26 ) ;
V_10 -> V_79 = V_74 [ 12 ] ;
V_10 -> V_80 = V_74 [ 6 ] ;
F_25 ( & V_8 -> V_23 , L_15
L_16 , V_10 -> V_5 ,
V_10 -> V_79 , V_10 -> V_80 ) ;
V_78 = & V_10 -> V_15 [ V_10 -> V_5 ] ;
V_78 -> V_81 = V_10 -> V_79 ;
V_78 -> V_82 = V_10 -> V_80 ;
V_78 -> V_16 = V_10 -> V_80 + 1 ;
V_78 -> V_83 = F_3 ( 12 , V_19 ) ;
if ( ! V_78 -> V_83 )
goto V_84;
sprintf ( V_78 -> V_83 , L_17 ,
V_8 -> V_35 , V_8 -> V_36 , V_10 -> V_5 ) ;
V_76 = & V_10 -> V_4 [ V_10 -> V_5 ] ;
V_76 -> V_83 = V_78 -> V_83 ;
V_76 -> type = 8 ;
V_76 -> V_85 = V_86 | V_87 ;
V_76 -> V_88 = V_78 -> V_16 * V_10 -> V_17 ;
V_76 -> V_89 = V_10 -> V_17 ;
V_76 -> V_90 = F_22 ;
V_76 -> V_91 = F_20 ;
V_76 -> V_92 = F_23 ;
V_76 -> V_93 = V_10 -> V_17 ;
V_12 = F_3 ( sizeof( struct V_11 ) , V_19 ) ;
if ( ! V_12 )
goto V_94;
V_12 -> V_8 = V_8 ;
V_12 -> V_5 = V_10 -> V_5 ;
V_76 -> V_14 = V_12 ;
V_76 -> V_95 = V_96 ;
V_31 = F_26 ( sizeof( struct V_30 ) , V_19 ) ;
if ( ! V_31 )
goto V_97;
V_78 -> V_31 = V_31 ;
error = F_27 ( V_76 , NULL , 0 ) ;
if ( error )
goto V_98;
F_13 ( V_8 , NULL , 0 ,
V_43 ) ;
if ( ++ V_10 -> V_5 < V_10 -> V_99 ) {
V_75 = F_8 ( V_10 -> V_5 << 24 ) ;
F_13 ( V_8 , F_24 , 0 ,
V_43 ) ;
F_14 ( V_8 , V_43 ,
V_100 , 2 , & V_75 ) ;
}
return;
V_98:
F_7 ( & V_8 -> V_23 , L_18
L_19 , V_8 -> V_35 , V_8 -> V_36 , error ) ;
for ( error = 0 ; error <= V_10 -> V_5 ; error ++ ) {
F_16 ( ( ( V_10 -> V_15 ) [ error ] ) . V_31 ) ;
( ( V_10 -> V_15 ) [ error ] ) . V_31 = NULL ;
}
V_97:
V_94:
for ( error = 0 ; error <= V_10 -> V_5 ; error ++ ) {
F_16 ( ( ( V_10 -> V_4 ) [ error ] ) . V_14 ) ;
( ( V_10 -> V_4 ) [ error ] ) . V_14 = NULL ;
}
F_13 ( V_8 , NULL , 0 ,
V_43 ) ;
F_16 ( V_78 -> V_83 ) ;
V_84:
return;
}
static int T_5 F_28 ( struct V_7 * V_8 )
{
unsigned long V_101 , V_102 ;
int V_103 , error ;
struct V_9 * V_10 ;
T_6 V_75 = 0 ;
V_101 = F_29 ( V_8 -> V_104 . V_105 ) ;
V_103 = F_30 ( V_101 ) ;
V_102 = F_29 ( V_8 -> V_104 . V_106 [ V_103 - 1 ] ) ;
V_10 = F_3 ( sizeof( struct V_9 ) , V_19 ) ;
if ( ! V_10 ) {
error = - V_37 ;
goto V_107;
}
V_10 -> V_99 = ( V_102 >> 24 & 0xFF ) + 1 ;
V_10 -> V_17 = ( ( V_102 >> 16 & 0xFF ) + 1 ) << 5 ;
V_10 -> V_55 = V_102 >> 12 & 0xF ;
V_10 -> V_27 = V_102 >> 8 & 0xF ;
V_10 -> V_108 = V_102 >> 7 & 1 ;
V_10 -> V_5 = 0 ;
V_10 -> V_15 = F_3 ( sizeof( struct V_77 ) * V_10 -> V_99 ,
V_19 ) ;
if ( ! V_10 -> V_15 ) {
error = - V_37 ;
goto V_109;
}
V_10 -> V_4 = F_3 ( sizeof( struct V_3 ) * V_10 -> V_99 ,
V_19 ) ;
if ( ! V_10 -> V_4 ) {
error = - V_37 ;
goto V_110;
}
F_31 ( V_8 , V_10 ) ;
F_13 ( V_8 , F_24 , 0 ,
V_43 ) ;
if ( F_9 ( & V_8 -> V_39 ) == 1 ) {
F_10 ( V_8 -> V_40 ,
F_9 ( & V_8 -> V_39 ) == 0 , V_41 ) ;
if ( F_9 ( & V_8 -> V_39 ) == 1 ) {
F_11 ( & V_8 -> V_23 , L_20 ,
V_8 -> V_35 , V_8 -> V_36 ) ;
error = - V_42 ;
goto V_111;
}
}
F_12 ( & V_8 -> V_39 , 1 ) ;
error = F_14 ( V_8 , V_43 ,
V_100 , 2 , & V_75 ) ;
if ( error ) {
F_7 ( & V_8 -> V_23 , L_21
L_22 , V_8 -> V_35 , V_8 -> V_36 , error ) ;
goto V_110;
}
return 0 ;
V_111:
F_16 ( V_10 -> V_4 ) ;
V_110:
F_16 ( V_10 -> V_15 ) ;
V_109:
F_16 ( V_10 ) ;
V_107:
return error ;
}
static void T_7 F_32 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_28 ;
V_8 -> V_112 = NULL ;
V_10 = F_2 ( V_8 ) ;
for ( V_28 = 0 ; V_28 < V_10 -> V_99 ; V_28 ++ ) {
V_12 = ( ( V_10 -> V_4 ) [ V_28 ] ) . V_14 ;
V_12 -> V_8 = NULL ;
F_33 ( & ( ( V_10 -> V_4 ) [ V_28 ] ) ) ;
F_16 ( ( ( V_10 -> V_15 ) [ V_28 ] ) . V_83 ) ;
}
F_16 ( V_10 -> V_15 ) ;
F_16 ( V_10 -> V_4 ) ;
F_16 ( V_10 ) ;
}
static int F_34 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_28 ;
struct V_3 * V_4 ;
V_10 = F_2 ( V_8 ) ;
for ( V_28 = 0 ; V_28 < V_10 -> V_99 ; V_28 ++ ) {
V_4 = & ( ( V_10 -> V_4 ) [ V_28 ] ) ;
if ( V_4 -> V_113 > 0 )
return 0 ;
}
return 1 ;
}
static void F_35 ( struct V_7 * V_8 , void * V_25 )
{
enum V_114 error = ( ( int * ) V_25 ) [ 1 ] ;
switch ( error ) {
case V_115 :
F_11 ( & V_8 -> V_23 , V_116 L_23 ,
V_8 -> V_35 , V_8 -> V_36 ) ;
break;
case V_117 :
F_11 ( & V_8 -> V_23 , V_116 L_24 ,
V_8 -> V_35 , V_8 -> V_36 ) ;
break;
case V_118 :
F_11 ( & V_8 -> V_23 , V_116 L_25 ,
V_8 -> V_35 , V_8 -> V_36 ) ;
break;
case V_119 :
F_11 ( & V_8 -> V_23 , V_116 L_26 ,
V_8 -> V_35 , V_8 -> V_36 ) ;
break;
case V_120 :
F_11 ( & V_8 -> V_23 , V_116 L_27 ,
V_8 -> V_35 , V_8 -> V_36 ) ;
break;
case V_121 :
F_11 ( & V_8 -> V_23 , V_116 L_28 ,
V_8 -> V_35 , V_8 -> V_36 ) ;
break;
default:
F_11 ( & V_8 -> V_23 , V_116 L_29 ,
V_8 -> V_35 , V_8 -> V_36 , error ) ;
}
}
static int T_5 F_36 ( struct V_122 * V_23 )
{
int error ;
struct V_7 * V_8 = F_37 ( V_23 ) ;
struct V_123 * V_124 = F_38 ( V_23 -> V_125 ) ;
V_8 -> V_126 = F_34 ;
V_8 -> V_127 = F_35 ;
V_8 -> V_125 = V_124 ;
error = F_28 ( V_8 ) ;
if ( error )
return error ;
return 0 ;
}
static int T_7 F_39 ( struct V_122 * V_23 )
{
struct V_7 * V_8 = F_37 ( V_23 ) ;
F_32 ( V_8 ) ;
return 0 ;
}
static int T_8 F_40 ( void )
{
return F_41 ( & V_128 ) ;
}
static void T_9 F_42 ( void )
{
F_43 ( & V_128 ) ;
}
