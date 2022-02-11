static int F_1 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 )
{
struct V_4 V_5 = {
. V_1 = V_6 . V_7 -> V_1 ,
. V_3 = 1 ,
. V_8 = & V_1
} ;
struct V_4 V_9 = {
. V_1 = V_6 . V_7 -> V_1 ,
. V_10 = V_11 ,
. V_3 = V_3 ,
. V_8 = V_2
} ;
struct V_4 V_12 [] = { V_5 , V_9 } ;
int V_13 = 0 ;
int V_14 ;
if ( ! V_6 . V_7 -> V_15 -> V_16 -> V_17 )
return - V_18 ;
F_2 ( V_6 . V_7 -> V_15 ) ;
if ( V_6 . V_19 == V_20 ) {
for ( V_14 = 0 ; V_14 < V_21 ; V_14 ++ ) {
V_13 = F_3 ( V_6 . V_7 -> V_15 , V_12 , 2 ) ;
if ( V_13 > 0 )
break;
F_4 ( V_22 , V_23 ) ;
}
} else {
for ( V_14 = 0 ; V_14 < V_21 ; V_14 ++ ) {
V_13 = F_3 ( V_6 . V_7 -> V_15 , & V_5 , 1 ) ;
if ( V_13 > 0 )
break;
F_4 ( V_22 , V_23 ) ;
}
if ( V_13 <= 0 )
goto V_24;
for ( V_14 = 0 ; V_14 < V_21 ; V_14 ++ ) {
F_4 ( V_22 , V_23 ) ;
V_13 = F_3 ( V_6 . V_7 -> V_15 , & V_9 , 1 ) ;
if ( V_13 > 0 )
break;
}
}
V_24:
F_5 ( V_6 . V_7 -> V_15 ) ;
F_4 ( V_22 , V_23 ) ;
if ( V_13 <= 0 )
return - V_25 ;
return 0 ;
}
static int F_6 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 ,
unsigned int V_26 ,
unsigned int V_27 , T_1 V_28 )
{
int V_13 = - V_25 ;
int V_14 ;
struct V_4 V_5 = {
. V_1 = V_6 . V_7 -> V_1 ,
. V_3 = V_3 + 1 ,
. V_8 = V_6 . V_8
} ;
if ( V_3 > V_29 )
return - V_30 ;
if ( ! V_6 . V_7 -> V_15 -> V_16 -> V_17 )
return - V_18 ;
F_2 ( V_6 . V_7 -> V_15 ) ;
V_6 . V_8 [ 0 ] = V_1 ;
memcpy ( & ( V_6 . V_8 [ 1 ] ) , V_2 , V_3 ) ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
V_13 = F_3 ( V_6 . V_7 -> V_15 , & V_5 , 1 ) ;
if ( V_13 > 0 )
break;
F_4 ( V_26 , V_27 ) ;
}
F_5 ( V_6 . V_7 -> V_15 ) ;
F_4 ( V_22 , V_23 ) ;
if ( V_13 <= 0 )
return - V_25 ;
return 0 ;
}
static int F_7 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_1 , V_2 , V_3 , V_22 ,
V_23 , V_21 ) ;
}
static int F_8 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_1 , V_2 , V_3 , V_31 ,
V_32 , V_33 ) ;
}
static int F_9 ( struct V_34 * V_35 , int V_36 )
{
T_1 V_8 ;
int V_13 ;
V_13 = F_1 ( F_10 ( V_36 ) , & V_8 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ( V_8 & ( V_37 | V_38 ) ) ==
( V_37 | V_38 ) ) {
V_35 -> V_39 . V_40 = V_36 ;
return V_36 ;
}
return - V_25 ;
}
static void F_11 ( struct V_34 * V_35 , int V_36 , int V_41 )
{
T_1 V_8 ;
if ( F_1 ( F_10 ( V_36 ) , & V_8 , 1 ) < 0 )
return;
if ( V_41 || ( V_8 & ( V_42 | V_38 ) ) ==
( V_42 | V_38 ) ) {
V_8 = V_37 ;
F_7 ( F_10 ( V_36 ) , & V_8 , 1 ) ;
}
}
static int F_12 ( struct V_34 * V_35 , int V_36 )
{
unsigned long V_43 ;
T_1 V_8 = V_44 ;
if ( F_9 ( V_35 , V_36 ) >= 0 )
return V_36 ;
F_7 ( F_10 ( V_36 ) , & V_8 , 1 ) ;
V_43 = V_45 + V_35 -> V_39 . V_46 ;
do {
if ( F_9 ( V_35 , V_36 ) >= 0 )
return V_36 ;
F_4 ( V_47 , V_48 ) ;
} while ( F_13 ( V_45 , V_43 ) );
return - V_49 ;
}
static T_1 F_14 ( struct V_34 * V_35 )
{
T_1 V_8 = 0xFF ;
T_1 V_50 = 0 ;
do {
if ( F_1 ( F_15 ( V_35 -> V_39 . V_40 ) , & V_8 , 1 ) < 0 )
return 0 ;
V_50 ++ ;
} while ( ( V_8 == 0xFF ) && V_50 < 10 );
return V_8 ;
}
static void F_16 ( struct V_34 * V_35 )
{
T_1 V_8 = V_51 ;
F_8 ( F_15 ( V_35 -> V_39 . V_40 ) , & V_8 , 1 ) ;
}
static T_3 F_17 ( struct V_34 * V_35 )
{
unsigned long V_43 ;
T_3 V_52 ;
T_1 V_8 [ 3 ] ;
V_43 = V_45 + V_35 -> V_39 . V_53 ;
do {
if ( F_1 ( F_15 ( V_35 -> V_39 . V_40 ) + 1 , V_8 , 3 ) < 0 )
V_52 = 0 ;
else
V_52 = ( V_8 [ 2 ] << 16 ) + ( V_8 [ 1 ] << 8 ) + V_8 [ 0 ] ;
if ( V_52 )
return V_52 ;
F_4 ( V_47 , V_48 ) ;
} while ( F_13 ( V_45 , V_43 ) );
return - V_54 ;
}
static int F_18 ( struct V_34 * V_35 , T_1 V_55 , unsigned long V_56 ,
int * V_57 )
{
unsigned long V_43 ;
* V_57 = F_14 ( V_35 ) ;
if ( ( * V_57 != 0xFF ) && ( * V_57 & V_55 ) == V_55 )
return 0 ;
V_43 = V_45 + V_56 ;
do {
F_4 ( V_47 , V_48 ) ;
* V_57 = F_14 ( V_35 ) ;
if ( ( * V_57 & V_55 ) == V_55 )
return 0 ;
} while ( F_13 ( V_45 , V_43 ) );
return - V_49 ;
}
static int F_19 ( struct V_34 * V_35 , T_1 * V_8 , T_2 V_14 )
{
T_2 V_58 = 0 ;
T_3 V_52 ;
T_1 V_59 = 0 ;
int V_13 ;
while ( V_58 < V_14 ) {
V_52 = F_17 ( V_35 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_52 > ( V_14 - V_58 ) )
V_52 = V_14 - V_58 ;
V_13 = F_1 ( F_20 ( V_35 -> V_39 . V_40 ) ,
& ( V_8 [ V_58 ] ) , V_52 ) ;
if ( V_13 == 0 )
V_58 += V_52 ;
else if ( V_13 < 0 )
V_59 ++ ;
if ( V_59 > V_33 )
return - V_25 ;
}
return V_58 ;
}
static int F_21 ( struct V_34 * V_35 , T_1 * V_8 , T_2 V_14 )
{
int V_58 = 0 ;
int V_60 , V_57 ;
if ( V_14 < V_61 ) {
V_58 = - V_25 ;
goto V_24;
}
V_58 = F_19 ( V_35 , V_8 , V_61 ) ;
if ( V_58 < V_61 ) {
F_22 ( V_35 -> V_62 , L_1 ) ;
goto V_24;
}
V_60 = F_23 ( * ( V_63 * ) ( V_8 + 2 ) ) ;
if ( ( T_2 ) V_60 > V_14 ) {
V_58 = - V_25 ;
goto V_24;
}
V_58 += F_19 ( V_35 , & V_8 [ V_61 ] ,
V_60 - V_61 ) ;
if ( V_58 < V_60 ) {
F_22 ( V_35 -> V_62 , L_2 ) ;
V_58 = - V_49 ;
goto V_24;
}
F_18 ( V_35 , V_64 , V_35 -> V_39 . V_65 , & V_57 ) ;
if ( V_57 & V_66 ) {
F_22 ( V_35 -> V_62 , L_3 ) ;
V_58 = - V_25 ;
goto V_24;
}
V_24:
F_16 ( V_35 ) ;
F_4 ( V_67 , V_68 ) ;
F_11 ( V_35 , V_35 -> V_39 . V_40 , 0 ) ;
return V_58 ;
}
static int F_24 ( struct V_34 * V_35 , T_1 * V_8 , T_2 V_3 )
{
int V_13 , V_57 ;
T_3 V_52 ;
T_2 V_14 = 0 ;
T_1 V_59 = 0 ;
T_1 V_69 = V_70 ;
if ( V_3 > V_29 )
return - V_71 ;
if ( F_12 ( V_35 , 0 ) < 0 )
return - V_54 ;
V_57 = F_14 ( V_35 ) ;
if ( ( V_57 & V_51 ) == 0 ) {
F_16 ( V_35 ) ;
if ( F_18
( V_35 , V_51 ,
V_35 -> V_39 . V_72 , & V_57 ) < 0 ) {
V_13 = - V_49 ;
goto V_73;
}
}
while ( V_14 < V_3 - 1 ) {
V_52 = F_17 ( V_35 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_52 > ( V_3 - 1 - V_14 ) )
V_52 = V_3 - 1 - V_14 ;
V_13 = F_7 ( F_20 ( V_35 -> V_39 . V_40 ) ,
& ( V_8 [ V_14 ] ) , V_52 ) ;
if ( V_13 == 0 )
V_14 += V_52 ;
else if ( V_13 < 0 )
V_59 ++ ;
if ( V_59 > V_33 ) {
V_13 = - V_25 ;
goto V_73;
}
F_18 ( V_35 , V_64 ,
V_35 -> V_39 . V_65 , & V_57 ) ;
if ( ( V_57 & V_74 ) == 0 ) {
V_13 = - V_25 ;
goto V_73;
}
}
F_7 ( F_20 ( V_35 -> V_39 . V_40 ) , & ( V_8 [ V_14 ] ) , 1 ) ;
F_18 ( V_35 , V_64 , V_35 -> V_39 . V_65 , & V_57 ) ;
if ( ( V_57 & V_74 ) != 0 ) {
V_13 = - V_25 ;
goto V_73;
}
F_7 ( F_15 ( V_35 -> V_39 . V_40 ) , & V_69 , 1 ) ;
return V_3 ;
V_73:
F_16 ( V_35 ) ;
F_4 ( V_67 , V_68 ) ;
F_11 ( V_35 , V_35 -> V_39 . V_40 , 0 ) ;
return V_13 ;
}
static bool F_25 ( struct V_34 * V_35 , T_1 V_57 )
{
return ( V_57 == V_51 ) ;
}
static int F_26 ( struct V_75 * V_62 )
{
T_4 V_39 ;
int V_13 = 0 ;
struct V_34 * V_35 ;
V_35 = F_27 ( V_62 , & V_76 ) ;
if ( ! V_35 ) {
F_22 ( V_62 , L_4 ) ;
V_13 = - V_77 ;
goto V_73;
}
V_35 -> V_39 . V_78 = 0 ;
V_35 -> V_39 . V_46 = F_28 ( V_79 ) ;
V_35 -> V_39 . V_72 = F_28 ( V_80 ) ;
V_35 -> V_39 . V_65 = F_28 ( V_79 ) ;
V_35 -> V_39 . V_53 = F_28 ( V_79 ) ;
if ( F_12 ( V_35 , 0 ) != 0 ) {
F_22 ( V_62 , L_5 ) ;
V_13 = - V_77 ;
goto V_81;
}
if ( F_1 ( F_29 ( 0 ) , ( T_1 * ) & V_39 , 4 ) < 0 ) {
F_22 ( V_62 , L_6 ) ;
V_13 = - V_25 ;
goto V_82;
}
if ( V_39 == V_83 ) {
V_6 . V_19 = V_20 ;
} else if ( V_39 == V_84 ) {
V_6 . V_19 = V_85 ;
} else {
F_22 ( V_62 , L_7 , V_39 ) ;
V_13 = - V_77 ;
goto V_82;
}
F_30 ( V_62 , L_8 , V_39 >> 16 ) ;
F_31 ( & V_35 -> V_39 . V_86 ) ;
V_6 . V_35 = V_35 ;
F_32 ( V_35 ) ;
F_33 ( V_35 ) ;
return 0 ;
V_82:
F_11 ( V_35 , V_35 -> V_39 . V_40 , 1 ) ;
V_81:
F_34 ( V_35 ) ;
F_35 ( V_35 -> V_62 ) ;
V_35 -> V_62 -> V_87 = NULL ;
V_35 -> V_87 = NULL ;
V_6 . V_7 = NULL ;
F_36 ( V_35 -> V_62 , V_35 ) ;
V_73:
return V_13 ;
}
static int F_37 ( struct V_88 * V_7 ,
const struct V_89 * V_90 )
{
int V_13 ;
struct V_75 * V_62 = & ( V_7 -> V_62 ) ;
if ( V_6 . V_7 != NULL ) {
F_22 ( V_62 , L_9 ) ;
return - V_54 ;
}
if ( ! F_38 ( V_7 -> V_15 , V_91 ) ) {
F_22 ( V_62 , L_10 ) ;
return - V_77 ;
}
V_6 . V_7 = V_7 ;
V_13 = F_26 ( & V_7 -> V_62 ) ;
if ( V_13 != 0 ) {
V_6 . V_7 = NULL ;
V_13 = - V_77 ;
}
return V_13 ;
}
static int F_39 ( struct V_88 * V_7 )
{
struct V_34 * V_35 = V_6 . V_35 ;
F_11 ( V_35 , V_35 -> V_39 . V_40 , 1 ) ;
F_34 ( V_35 ) ;
F_35 ( V_35 -> V_62 ) ;
V_35 -> V_62 -> V_87 = NULL ;
V_35 -> V_87 = NULL ;
V_6 . V_7 = NULL ;
F_36 ( V_35 -> V_62 , V_35 ) ;
return 0 ;
}
