static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 ;
V_7 = V_2 -> V_8 . V_9 ;
V_7 -> V_10 [ 0 ] [ 0 ] = V_3 ;
memcpy ( & V_7 -> V_10 [ 0 ] [ 1 ] , V_4 , V_5 ) ;
return F_2 ( V_2 , V_7 -> V_10 [ 0 ] ,
V_5 + 1 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 )
{
T_1 V_11 = 0 ;
T_1 V_12 ;
V_12 = V_13 ;
V_11 = F_1 ( V_2 , V_3 , & V_12 , 1 ) ;
if ( V_11 == 2 )
V_11 = F_4 ( V_2 , V_4 , V_5 ) ;
return V_11 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_14 ;
F_6 ( V_2 , V_15 , & V_14 , 1 ) ;
F_7 ( V_2 , V_15 , & V_14 , 1 ) ;
F_6 ( V_2 , V_15 , & V_14 , 1 ) ;
}
static long F_8 ( struct V_16 * V_17 ,
unsigned long V_18 )
{
long V_11 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
V_7 = V_2 -> V_8 . V_9 ;
V_11 = F_10 (
& V_7 -> V_19 ,
V_18 ) ;
if ( V_11 > 0 )
F_11 ( F_12 ( V_7 -> V_20 ) ) ;
F_13 ( V_7 -> V_20 ) ;
return V_11 ;
}
static int F_14 ( struct V_16 * V_17 , bool V_21 ,
unsigned long V_18 )
{
int V_11 = 2 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
V_11 = F_8 ( V_17 , V_18 ) ;
if ( ! V_11 ) {
V_11 = - V_22 ;
} else {
F_5 ( V_2 ) ;
if ( V_21 )
V_11 = 1 ;
}
return V_11 ;
}
static void F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
T_1 V_12 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
V_12 = V_23 ;
F_7 ( V_2 , V_24 , & V_12 , 1 ) ;
if ( V_17 -> V_25 . V_26 )
F_14 ( V_17 , 1 , V_17 -> V_25 . V_27 ) ;
}
static T_1 F_16 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
T_1 V_12 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
F_6 ( V_2 , V_24 , & V_12 , 1 ) ;
return V_12 ;
}
static int F_17 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
T_1 V_12 ;
T_1 V_11 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
V_11 = F_6 ( V_2 , V_28 , & V_12 , 1 ) ;
if ( V_11 && ( V_12 &
( V_29 | V_30 ) ) ==
( V_29 | V_30 ) )
return V_17 -> V_25 . V_31 ;
return - V_32 ;
}
static int F_18 ( struct V_16 * V_17 )
{
unsigned long V_33 ;
long V_34 ;
struct V_1 * V_2 ;
T_1 V_12 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
if ( F_17 ( V_17 ) == V_17 -> V_25 . V_31 )
return V_17 -> V_25 . V_31 ;
V_12 = V_35 ;
V_34 = F_7 ( V_2 , V_28 , & V_12 , 1 ) ;
if ( V_34 < 0 )
goto V_36;
if ( V_17 -> V_25 . V_26 ) {
V_34 = F_14 ( V_17 , ( F_17
( V_17 ) >= 0 ) ,
V_17 -> V_25 . V_27 ) ;
if ( V_34 > 0 )
return V_17 -> V_25 . V_31 ;
} else {
V_33 = V_37 + V_17 -> V_25 . V_27 ;
do {
if ( F_17 ( V_17 ) >= 0 )
return V_17 -> V_25 . V_31 ;
F_19 ( V_38 ) ;
} while ( F_20 ( V_37 , V_33 ) );
}
V_34 = - V_32 ;
V_36:
return V_34 ;
}
static void F_21 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
T_1 V_12 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
V_12 = V_29 ;
F_7 ( V_2 , V_28 , & V_12 , 1 ) ;
}
static int F_22 ( struct V_16 * V_17 )
{
unsigned long V_33 ;
int V_39 , V_11 ;
T_1 V_40 , V_41 ;
struct V_1 * V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
V_33 = V_37 + V_17 -> V_25 . V_42 ;
do {
V_40 = V_24 + 1 ;
V_11 = F_6 ( V_2 , V_40 , & V_41 , 1 ) ;
if ( V_11 < 0 )
goto V_36;
V_40 = V_40 + 1 ;
V_39 = V_41 ;
V_11 = F_6 ( V_2 , V_40 , & V_41 , 1 ) ;
if ( V_11 < 0 )
goto V_36;
V_39 |= V_41 << 8 ;
if ( V_39 )
return V_39 ;
F_19 ( V_38 ) ;
} while ( F_20 ( V_37 , V_33 ) );
V_36:
return - V_22 ;
}
static int F_23 ( struct V_16 * V_17 , T_1 V_43 , unsigned long V_18 ,
T_3 * V_44 )
{
unsigned long V_33 ;
long V_34 ;
T_1 V_11 ;
if ( V_17 -> V_25 . V_26 ) {
V_34 = F_14 ( V_17 , ( ( F_16
( V_17 ) & V_43 ) ==
V_43 ) , V_18 ) ;
if ( V_34 > 0 )
return 0 ;
} else {
V_33 = V_37 + V_18 ;
do {
F_19 ( V_38 ) ;
V_11 = F_16 ( V_17 ) ;
if ( ( V_11 & V_43 ) == V_43 )
return 0 ;
} while ( F_20 ( V_37 , V_33 ) );
}
return - V_45 ;
}
static int F_24 ( struct V_16 * V_17 , T_1 * V_46 , T_4 V_47 )
{
int V_48 = 0 , V_39 , V_49 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
while ( V_48 < V_47 &&
F_23 ( V_17 ,
V_50 | V_51 ,
V_17 -> V_25 . V_52 ,
& V_17 -> V_25 . V_53 )
== 0 ) {
V_39 = F_22 ( V_17 ) ;
if ( V_39 < 0 )
return V_39 ;
V_49 = F_25 ( int , V_39 , V_47 - V_48 ) ;
F_6 ( V_2 , V_54 , V_46 + V_48 , V_49 ) ;
V_48 += V_49 ;
}
return V_48 ;
}
static T_5 F_26 ( int V_26 , void * V_55 )
{
struct V_16 * V_17 = V_55 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
F_27 ( V_26 ) ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
V_7 = V_2 -> V_8 . V_9 ;
F_28 ( & V_7 -> V_19 ) ;
return V_56 ;
}
static int F_29 ( struct V_16 * V_17 , unsigned char * V_46 ,
T_4 V_49 )
{
T_6 V_11 , V_57 , V_48 ;
int V_39 = 0 ;
int V_58 ;
T_1 V_12 ;
struct V_1 * V_2 ;
if ( V_17 == NULL )
return - V_22 ;
if ( V_49 < V_59 )
return - V_22 ;
V_2 = (struct V_1 * ) F_9 ( V_17 ) ;
V_2 -> V_60 = 0 ;
V_58 = F_18 ( V_17 ) ;
if ( V_58 < 0 )
return V_58 ;
V_11 = F_16 ( V_17 ) ;
if ( ( V_11 & V_23 ) == 0 ) {
F_15 ( V_17 ) ;
if ( F_23
( V_17 , V_23 , V_17 -> V_25 . V_61 ,
& V_17 -> V_25 . V_62 ) < 0 ) {
V_58 = - V_45 ;
goto V_63;
}
}
for ( V_57 = 0 ; V_57 < V_49 - 1 ; ) {
V_39 = F_22 ( V_17 ) ;
if ( V_39 < 0 )
return V_39 ;
V_48 = F_25 ( int , V_49 - V_57 - 1 , V_39 ) ;
V_58 = F_7 ( V_2 , V_54 , V_46 , V_48 ) ;
if ( V_58 < 0 )
goto V_63;
V_57 += V_48 ;
}
V_11 = F_16 ( V_17 ) ;
if ( ( V_11 & V_64 ) == 0 ) {
V_58 = - V_65 ;
goto V_63;
}
V_58 = F_7 ( V_2 , V_54 , V_46 + V_49 - 1 , 1 ) ;
if ( V_58 < 0 )
goto V_63;
V_11 = F_16 ( V_17 ) ;
if ( ( V_11 & V_64 ) != 0 ) {
V_58 = - V_65 ;
goto V_63;
}
V_12 = V_66 ;
F_7 ( V_2 , V_24 , & V_12 , 1 ) ;
return V_49 ;
V_63:
F_15 ( V_17 ) ;
F_21 ( V_17 ) ;
return V_58 ;
}
static int F_30 ( struct V_16 * V_17 , unsigned char * V_46 ,
T_4 V_47 )
{
int V_48 = 0 ;
int V_67 ;
if ( V_17 == NULL )
return - V_22 ;
if ( V_47 < V_59 ) {
V_48 = - V_65 ;
goto V_68;
}
V_48 = F_24 ( V_17 , V_46 , V_59 ) ;
if ( V_48 < V_59 ) {
F_31 ( V_17 -> V_8 , L_1 ) ;
goto V_68;
}
V_67 = F_32 ( * ( V_69 * ) ( V_46 + 2 ) ) ;
if ( V_67 > V_47 ) {
V_48 = - V_65 ;
goto V_68;
}
V_48 += F_24 ( V_17 , & V_46 [ V_59 ] ,
V_67 - V_59 ) ;
if ( V_48 < V_67 ) {
F_31 ( V_17 -> V_8 , L_2 ) ;
V_48 = - V_45 ;
goto V_68;
}
V_68:
V_17 -> V_70 -> V_71 ( V_17 ) ;
F_21 ( V_17 ) ;
return V_48 ;
}
static bool F_33 ( struct V_16 * V_17 , T_1 V_11 )
{
return ( V_11 == V_23 ) ;
}
static int
F_34 ( struct V_1 * V_2 , const struct V_72 * V_73 )
{
int V_74 ;
T_1 V_75 ;
struct V_16 * V_17 ;
struct V_6 * V_9 ;
if ( V_2 == NULL ) {
F_35 ( L_3 ,
V_76 ) ;
V_74 = - V_77 ;
goto V_36;
}
if ( ! F_36 ( V_2 -> V_78 , V_79 ) ) {
F_37 ( & V_2 -> V_8 , L_4 ) ;
V_74 = - V_77 ;
goto V_36;
}
V_17 = F_38 ( & V_2 -> V_8 , & V_80 ) ;
if ( ! V_17 ) {
F_37 ( & V_2 -> V_8 , L_5 ) ;
V_74 = - V_77 ;
goto V_36;
}
V_9 = V_2 -> V_8 . V_9 ;
if ( ! V_9 ) {
F_37 ( & V_2 -> V_8 , L_6 ) ;
V_74 = - V_77 ;
goto V_81;
}
V_9 -> V_10 [ 0 ] =
F_39 ( V_82 * sizeof( T_1 ) , V_83 ) ;
if ( V_9 -> V_10 [ 0 ] == NULL ) {
V_74 = - V_84 ;
goto V_81;
}
V_9 -> V_10 [ 1 ] =
F_39 ( V_82 * sizeof( T_1 ) , V_83 ) ;
if ( V_9 -> V_10 [ 1 ] == NULL ) {
V_74 = - V_84 ;
goto V_85;
}
F_9 ( V_17 ) = V_2 ;
V_17 -> V_25 . V_27 = F_40 ( V_86 ) ;
V_17 -> V_25 . V_61 = F_40 ( V_87 ) ;
V_17 -> V_25 . V_52 = F_40 ( V_86 ) ;
V_17 -> V_25 . V_42 = F_40 ( V_86 ) ;
V_17 -> V_25 . V_31 = V_88 ;
if ( V_89 ) {
V_74 = F_41 ( V_9 -> V_90 , L_7 ) ;
if ( V_74 )
goto V_91;
F_42 ( V_9 -> V_90 , 1 ) ;
}
if ( V_92 ) {
F_43 ( & V_9 -> V_19 ) ;
if ( F_18 ( V_17 ) != V_88 ) {
V_74 = - V_77 ;
goto V_93;
}
V_74 = F_41 ( V_9 -> V_20 , L_8 ) ;
if ( V_74 )
goto V_94;
F_5 ( V_2 ) ;
V_74 = F_44 ( F_12 ( V_9 -> V_20 ) ,
& F_26 ,
V_95 ,
L_9 , V_17 ) ;
if ( V_74 < 0 ) {
F_31 ( V_17 -> V_8 , L_10 ,
F_12 ( V_9 -> V_20 ) ) ;
goto V_96;
}
V_74 = F_6 ( V_2 , V_97 , & V_75 , 1 ) ;
if ( V_74 < 0 )
goto V_96;
V_75 |= V_98
| V_99
| V_100
| V_101
| V_102
| V_103 ;
V_74 = F_7 ( V_2 , V_97 , & V_75 , 1 ) ;
if ( V_74 < 0 )
goto V_96;
V_75 = V_104 ;
V_74 = F_7 ( V_2 , ( V_97 + 3 ) , & V_75 , 1 ) ;
if ( V_74 < 0 )
goto V_96;
V_74 = F_6 ( V_2 , V_15 , & V_75 , 1 ) ;
if ( V_74 < 0 )
goto V_96;
V_17 -> V_25 . V_26 = V_92 ;
F_45 ( V_17 ) ;
}
F_46 ( V_17 ) ;
F_47 ( V_17 ) ;
F_37 ( V_17 -> V_8 , L_11 ) ;
return 0 ;
V_96:
F_48 ( F_12 ( V_9 -> V_20 ) , ( void * ) V_17 ) ;
V_94:
if ( V_92 )
F_49 ( V_9 -> V_20 ) ;
V_91:
if ( V_89 )
F_49 ( V_9 -> V_90 ) ;
V_93:
F_50 ( V_9 -> V_10 [ 1 ] ) ;
V_9 -> V_10 [ 1 ] = NULL ;
V_85:
F_50 ( V_9 -> V_10 [ 0 ] ) ;
V_9 -> V_10 [ 0 ] = NULL ;
V_81:
F_51 ( V_17 -> V_8 ) ;
V_36:
F_35 ( L_12 ) ;
return V_74 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = (struct V_16 * ) F_53 ( V_2 ) ;
struct V_6 * V_7 =
( (struct V_1 * ) F_9 ( V_17 ) ) -> V_8 . V_9 ;
if ( V_7 != NULL ) {
F_48 ( V_7 -> V_20 , V_17 ) ;
F_49 ( V_7 -> V_20 ) ;
F_49 ( V_7 -> V_90 ) ;
F_51 ( V_17 -> V_8 ) ;
if ( V_7 -> V_10 [ 1 ] != NULL ) {
F_50 ( V_7 -> V_10 [ 1 ] ) ;
V_7 -> V_10 [ 1 ] = NULL ;
}
if ( V_7 -> V_10 [ 0 ] != NULL ) {
F_50 ( V_7 -> V_10 [ 0 ] ) ;
V_7 -> V_10 [ 0 ] = NULL ;
}
}
return 0 ;
}
static int F_54 ( struct V_105 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_9 ;
int V_58 = 0 ;
if ( V_89 ) {
F_42 ( V_7 -> V_90 , 0 ) ;
} else {
V_58 = F_55 ( V_8 ) ;
}
return V_58 ;
}
static int F_56 ( struct V_105 * V_8 )
{
struct V_16 * V_17 = F_57 ( V_8 ) ;
struct V_6 * V_7 = V_8 -> V_9 ;
int V_58 = 0 ;
if ( V_89 ) {
F_42 ( V_7 -> V_90 , 1 ) ;
V_58 = F_14 ( V_17 ,
( V_17 -> V_70 -> V_11 ( V_17 ) &
V_51 ) == V_51 ,
V_17 -> V_25 . V_61 ) ;
} else {
V_58 = F_58 ( V_8 ) ;
if ( ! V_58 )
F_47 ( V_17 ) ;
}
return V_58 ;
}
