static T_1
F_1 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
if ( V_1 == V_3 [ V_2 ] . V_1 ) {
return ( 100000000 / V_3 [ V_2 ] . V_4 ) ;
}
}
return ( 10000000 / ( V_1 * 4 * 10 ) ) ;
}
static void
F_3 ( struct V_5 * V_6 , char * V_7 , int V_8 )
{
if ( V_6 -> V_9 + V_8 > V_6 -> V_10 + V_6 -> V_11 )
V_8 = V_6 -> V_10 + V_6 -> V_11 - V_6 -> V_9 ;
if ( V_6 -> V_9 + V_8 < V_6 -> V_10 ) {
V_6 -> V_9 += V_8 ;
return;
}
if ( V_6 -> V_9 < V_6 -> V_10 ) {
T_2 V_12 ;
V_12 = V_6 -> V_10 - V_6 -> V_9 ;
V_7 += V_12 ;
V_6 -> V_9 += V_12 ;
V_8 -= V_12 ;
}
if ( V_8 > 0 ) {
memcpy ( V_6 -> V_13 , V_7 , V_8 ) ;
V_6 -> V_9 += V_8 ;
V_6 -> V_13 += V_8 ;
}
}
static int
F_4 ( struct V_5 * V_6 , char * V_14 , ... )
{
T_3 args ;
char V_15 [ 256 ] ;
int V_8 ;
va_start ( args , V_14 ) ;
V_8 = vsprintf ( V_15 , V_14 , args ) ;
va_end ( args ) ;
F_3 ( V_6 , V_15 , V_8 ) ;
return ( V_8 ) ;
}
static void
F_5 ( struct V_5 * V_6 , struct V_16 * V_17 )
{
T_1 V_18 ;
T_1 V_19 ;
T_1 V_20 ;
if ( V_17 -> V_4 == V_21 ) {
F_4 ( V_6 , L_1 ) ;
return;
}
V_18 = 3300 ;
V_19 = 0 ;
if ( V_17 -> V_10 != 0 ) {
V_19 = F_1 ( V_17 -> V_4 ) ;
V_18 = V_19 ;
}
V_18 *= ( 0x01 << V_17 -> V_22 ) ;
V_20 = V_18 / 1000 ;
if ( V_20 > 0 )
F_4 ( V_6 , L_2 , V_20 , V_18 % 1000 ) ;
else
F_4 ( V_6 , L_3 , V_18 ) ;
if ( V_19 != 0 ) {
int V_23 ;
V_23 = 0 ;
F_4 ( V_6 , L_4 , V_19 / 1000 , V_19 % 1000 ) ;
if ( ( V_17 -> V_24 & V_25 ) != 0 ) {
F_4 ( V_6 , L_5 ) ;
V_23 ++ ;
}
if ( ( V_17 -> V_24 & V_26 ) != 0 ) {
F_4 ( V_6 , L_6 , V_23 ? L_7 : L_8 ) ;
V_23 ++ ;
}
if ( ( V_17 -> V_24 & V_27 ) != 0 ) {
F_4 ( V_6 , L_6 , V_23 ? L_9 : L_10 ) ;
V_23 ++ ;
}
if ( ( V_17 -> V_24 & V_28 ) != 0 ) {
F_4 ( V_6 , L_6 ,
V_23 ? L_11 : L_12 ) ;
V_23 ++ ;
}
if ( ( V_17 -> V_24 & V_29 ) != 0 ) {
F_4 ( V_6 , L_6 ,
V_23 ? L_13 : L_14 ) ;
V_23 ++ ;
}
}
if ( V_17 -> V_22 > 0 ) {
if ( V_19 != 0 ) {
F_4 ( V_6 , L_15 ) ;
} else {
F_4 ( V_6 , L_16 ) ;
}
F_4 ( V_6 , L_17 , 8 * ( 0x01 << V_17 -> V_22 ) ) ;
} else if ( V_19 != 0 ) {
F_4 ( V_6 , L_18 ) ;
}
F_4 ( V_6 , L_19 ) ;
}
static void
F_6 ( struct V_30 * V_31 , struct V_5 * V_6 ,
T_1 V_32 , char V_33 , T_1 V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_17 ;
struct V_38 * V_39 ;
int V_40 ;
V_17 = F_7 ( V_31 , V_33 , V_32 ,
V_34 , & V_39 ) ;
F_4 ( V_6 , L_20 , V_34 ) ;
F_4 ( V_6 , L_21 ) ;
F_5 ( V_6 , & V_17 -> V_41 ) ;
V_36 = V_31 -> V_42 -> V_36 [ V_34 ] ;
if ( V_36 == NULL )
return;
F_4 ( V_6 , L_22 ) ;
F_5 ( V_6 , & V_17 -> V_43 ) ;
F_4 ( V_6 , L_23 ) ;
F_5 ( V_6 , & V_17 -> V_44 ) ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ ) {
struct V_46 * V_47 ;
V_47 = F_8 ( V_36 , V_40 ) ;
if ( V_47 == NULL )
continue;
F_9 ( V_6 , V_47 ) ;
}
}
static void
F_9 ( struct V_5 * V_6 , struct V_46 * V_48 )
{
struct V_49 * V_47 = F_10 ( V_48 ) ;
F_4 ( V_6 , L_24 ,
V_48 -> V_50 -> V_33 + 'A' ,
V_48 -> V_50 -> V_51 , V_48 -> V_40 ) ;
F_4 ( V_6 , L_25 , V_47 -> V_52 ) ;
F_4 ( V_6 , L_26 , V_47 -> V_53 ) ;
F_4 ( V_6 , L_27 , V_47 -> V_54 ) ;
F_4 ( V_6 , L_28 , V_47 -> V_55 ) ;
F_4 ( V_6 , L_29 , V_47 -> V_56 ) ;
}
static int
F_11 ( struct V_30 * V_31 , char * V_13 , int V_11 )
{
T_4 V_57 ;
int V_58 ;
T_5 V_59 ;
int V_60 ;
int V_61 ;
V_61 = - V_62 ;
F_12 ( V_31 , & V_59 ) ;
V_60 = F_13 ( V_31 ) ;
if ( ! V_60 )
F_14 ( V_31 ) ;
V_57 = F_15 ( V_31 ) ;
F_16 ( V_31 , V_63 , V_63 ) ;
if ( V_11 != sizeof( struct V_64 ) ) {
F_17 ( L_30 ) ;
goto V_65;
}
V_58 = F_18 ( (struct V_64 * ) V_13 ) ;
if ( V_58 == 0 ) {
F_17 ( L_31 ) ;
goto V_65;
}
V_58 = F_19 ( V_31 ) ;
if ( ! V_58 ) {
F_17 ( L_32 ) ;
goto V_65;
} else {
T_1 V_66 ;
if ( V_31 -> V_67 == NULL ) {
V_31 -> V_67 = F_20 ( sizeof( * V_31 -> V_67 ) , V_68 ) ;
if ( V_31 -> V_67 == NULL ) {
F_17 ( L_33
L_34 ) ;
goto V_65;
}
}
F_17 ( L_35 ) ;
V_66 = 32 * ( V_31 -> V_33 - 'A' ) ;
F_21 ( V_31 , ( V_69 * ) V_13 , V_66 ,
sizeof( struct V_64 ) / 2 ) ;
F_22 ( V_31 , ( V_70 * ) V_31 -> V_67 ,
V_66 , sizeof( struct V_64 ) / 2 ,
FALSE ) ;
F_23 ( V_31 ) ;
V_61 = V_11 ;
}
V_65:
F_24 ( V_31 , V_57 ) ;
if ( ! V_60 )
F_25 ( V_31 ) ;
F_26 ( V_31 , & V_59 ) ;
return ( V_61 ) ;
}
int
F_27 ( struct V_71 * V_72 , char * V_13 , char * * V_73 ,
T_2 V_10 , int V_11 , int V_74 )
{
struct V_30 * V_31 = * (struct V_30 * * ) V_72 -> V_75 ;
struct V_5 V_6 ;
char V_76 [ 256 ] ;
T_1 V_77 ;
T_1 V_2 ;
int V_78 ;
if ( V_74 == TRUE ) {
V_78 = F_11 ( V_31 , V_13 , V_11 ) ;
goto V_65;
}
if ( V_73 )
* V_73 = V_13 ;
V_6 . V_13 = V_13 ;
V_6 . V_11 = V_11 ;
V_6 . V_10 = V_10 ;
V_6 . V_9 = 0 ;
F_4 ( & V_6 , L_36 ,
V_79 ) ;
F_4 ( & V_6 , L_37 , V_31 -> V_80 ) ;
F_28 ( V_31 , V_76 ) ;
F_4 ( & V_6 , L_37 , V_76 ) ;
F_4 ( & V_6 , L_38 ,
V_31 -> V_81 . V_82 , V_83 ) ;
V_77 = 16 ;
if ( V_31 -> V_67 == NULL )
F_4 ( & V_6 , L_39 ) ;
else {
F_4 ( & V_6 , L_40 ) ;
for ( V_2 = 0 ; V_2 < sizeof( * V_31 -> V_67 ) / 2 ; V_2 ++ ) {
if ( ( ( V_2 % 8 ) == 0 ) && ( V_2 != 0 ) ) {
F_4 ( & V_6 , L_19 ) ;
}
F_4 ( & V_6 , L_41 ,
( ( V_70 * ) V_31 -> V_67 ) [ V_2 ] ) ;
}
F_4 ( & V_6 , L_19 ) ;
}
F_4 ( & V_6 , L_19 ) ;
if ( ( V_31 -> V_84 & V_85 ) == 0 )
V_77 = 8 ;
for ( V_2 = 0 ; V_2 < V_77 ; V_2 ++ ) {
F_6 ( V_31 , & V_6 , V_31 -> V_32 , 'A' ,
V_2 ) ;
}
V_78 = V_6 . V_9 > V_6 . V_10 ? V_6 . V_9 - V_6 . V_10 : 0 ;
V_65:
return ( V_78 ) ;
}
