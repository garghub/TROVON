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
unsigned int V_15 = V_3 ;
if ( ! V_6 . V_7 -> V_16 -> V_17 -> V_18 )
return - V_19 ;
F_2 ( V_6 . V_7 -> V_16 ) ;
if ( V_6 . V_20 == V_21 ) {
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
V_13 = F_3 ( V_6 . V_7 -> V_16 , V_12 , 2 ) ;
if ( V_13 > 0 )
break;
F_4 ( V_23 , V_24 ) ;
}
} else {
while ( V_3 > 0 ) {
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
V_13 = F_3 ( V_6 . V_7 -> V_16 ,
& V_5 , 1 ) ;
if ( V_13 > 0 )
break;
F_4 ( V_23 ,
V_24 ) ;
}
if ( V_13 <= 0 )
goto V_25;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
if ( V_6 . V_26 ) {
V_15 = F_5 (unsigned int,
tpm_dev.adapterlimit,
len) ;
V_9 . V_3 = V_15 ;
}
F_4 ( V_23 ,
V_24 ) ;
V_13 = F_3 ( V_6 . V_7 -> V_16 ,
& V_9 , 1 ) ;
if ( V_13 > 0 ) {
if ( V_15 > V_3 )
V_3 = 0 ;
else
V_3 -= V_15 ;
V_9 . V_8 += V_15 ;
break;
}
if ( V_13 == - V_19 )
V_6 . V_26 =
V_27 ;
}
if ( V_13 <= 0 )
goto V_25;
}
}
V_25:
F_6 ( V_6 . V_7 -> V_16 ) ;
F_4 ( V_23 , V_24 ) ;
if ( V_13 <= 0 )
return - V_28 ;
return 0 ;
}
static int F_7 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 ,
unsigned int V_29 ,
unsigned int V_30 , T_1 V_31 )
{
int V_13 = - V_28 ;
int V_14 ;
struct V_4 V_5 = {
. V_1 = V_6 . V_7 -> V_1 ,
. V_3 = V_3 + 1 ,
. V_8 = V_6 . V_8
} ;
if ( V_3 > V_32 )
return - V_33 ;
if ( ! V_6 . V_7 -> V_16 -> V_17 -> V_18 )
return - V_19 ;
F_2 ( V_6 . V_7 -> V_16 ) ;
V_6 . V_8 [ 0 ] = V_1 ;
memcpy ( & ( V_6 . V_8 [ 1 ] ) , V_2 , V_3 ) ;
for ( V_14 = 0 ; V_14 < V_31 ; V_14 ++ ) {
V_13 = F_3 ( V_6 . V_7 -> V_16 , & V_5 , 1 ) ;
if ( V_13 > 0 )
break;
F_4 ( V_29 , V_30 ) ;
}
F_6 ( V_6 . V_7 -> V_16 ) ;
F_4 ( V_23 , V_24 ) ;
if ( V_13 <= 0 )
return - V_28 ;
return 0 ;
}
static int F_8 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 )
{
return F_7 ( V_1 , V_2 , V_3 , V_23 ,
V_24 , V_22 ) ;
}
static int F_9 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 )
{
return F_7 ( V_1 , V_2 , V_3 , V_34 ,
V_35 , V_36 ) ;
}
static bool F_10 ( struct V_37 * V_38 , int V_39 )
{
T_1 V_8 ;
int V_13 ;
V_13 = F_1 ( F_11 ( V_39 ) , & V_8 , 1 ) ;
if ( V_13 < 0 )
return false ;
if ( ( V_8 & ( V_40 | V_41 ) ) ==
( V_40 | V_41 ) ) {
V_6 . V_42 = V_39 ;
return true ;
}
return false ;
}
static void F_12 ( struct V_37 * V_38 , int V_39 , int V_43 )
{
T_1 V_8 ;
if ( F_1 ( F_11 ( V_39 ) , & V_8 , 1 ) < 0 )
return;
if ( V_43 || ( V_8 & ( V_44 | V_41 ) ) ==
( V_44 | V_41 ) ) {
V_8 = V_40 ;
F_8 ( F_11 ( V_39 ) , & V_8 , 1 ) ;
}
}
static int F_13 ( struct V_37 * V_38 , int V_39 )
{
unsigned long V_45 ;
T_1 V_8 = V_46 ;
if ( F_10 ( V_38 , V_39 ) )
return V_39 ;
F_8 ( F_11 ( V_39 ) , & V_8 , 1 ) ;
V_45 = V_47 + V_38 -> V_48 ;
do {
if ( F_10 ( V_38 , V_39 ) )
return V_39 ;
F_4 ( V_49 , V_50 ) ;
} while ( F_14 ( V_47 , V_45 ) );
return - V_51 ;
}
static T_1 F_15 ( struct V_37 * V_38 )
{
T_1 V_8 = 0xFF ;
T_1 V_52 = 0 ;
do {
if ( F_1 ( F_16 ( V_6 . V_42 ) , & V_8 , 1 ) < 0 )
return 0 ;
V_52 ++ ;
} while ( ( V_8 == 0xFF ) && V_52 < 10 );
return V_8 ;
}
static void F_17 ( struct V_37 * V_38 )
{
T_1 V_8 = V_53 ;
F_9 ( F_16 ( V_6 . V_42 ) , & V_8 , 1 ) ;
}
static T_3 F_18 ( struct V_37 * V_38 )
{
unsigned long V_45 ;
T_3 V_54 ;
T_1 V_8 [ 3 ] ;
V_45 = V_47 + V_38 -> V_55 ;
do {
if ( F_1 ( F_16 ( V_6 . V_42 ) + 1 , V_8 , 3 ) < 0 )
V_54 = 0 ;
else
V_54 = ( V_8 [ 2 ] << 16 ) + ( V_8 [ 1 ] << 8 ) + V_8 [ 0 ] ;
if ( V_54 )
return V_54 ;
F_4 ( V_49 , V_50 ) ;
} while ( F_14 ( V_47 , V_45 ) );
return - V_56 ;
}
static int F_19 ( struct V_37 * V_38 , T_1 V_57 , unsigned long V_58 ,
int * V_59 )
{
unsigned long V_45 ;
* V_59 = F_15 ( V_38 ) ;
if ( ( * V_59 != 0xFF ) && ( * V_59 & V_57 ) == V_57 )
return 0 ;
V_45 = V_47 + V_58 ;
do {
F_4 ( V_49 , V_50 ) ;
* V_59 = F_15 ( V_38 ) ;
if ( ( * V_59 & V_57 ) == V_57 )
return 0 ;
} while ( F_14 ( V_47 , V_45 ) );
return - V_51 ;
}
static int F_20 ( struct V_37 * V_38 , T_1 * V_8 , T_2 V_14 )
{
T_2 V_60 = 0 ;
T_3 V_54 ;
T_1 V_61 = 0 ;
int V_13 ;
while ( V_60 < V_14 ) {
V_54 = F_18 ( V_38 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_54 > ( V_14 - V_60 ) )
V_54 = V_14 - V_60 ;
V_13 = F_1 ( F_21 ( V_6 . V_42 ) ,
& ( V_8 [ V_60 ] ) , V_54 ) ;
if ( V_13 == 0 )
V_60 += V_54 ;
else if ( V_13 < 0 )
V_61 ++ ;
if ( V_61 > V_36 )
return - V_28 ;
}
return V_60 ;
}
static int F_22 ( struct V_37 * V_38 , T_1 * V_8 , T_2 V_14 )
{
int V_60 = 0 ;
int V_62 , V_59 ;
if ( V_14 < V_63 ) {
V_60 = - V_28 ;
goto V_25;
}
V_60 = F_20 ( V_38 , V_8 , V_63 ) ;
if ( V_60 < V_63 ) {
F_23 ( & V_38 -> V_64 , L_1 ) ;
goto V_25;
}
V_62 = F_24 ( * ( V_65 * ) ( V_8 + 2 ) ) ;
if ( ( T_2 ) V_62 > V_14 ) {
V_60 = - V_28 ;
goto V_25;
}
V_60 += F_20 ( V_38 , & V_8 [ V_63 ] ,
V_62 - V_63 ) ;
if ( V_60 < V_62 ) {
F_23 ( & V_38 -> V_64 , L_2 ) ;
V_60 = - V_51 ;
goto V_25;
}
F_19 ( V_38 , V_66 , V_38 -> V_67 , & V_59 ) ;
if ( V_59 & V_68 ) {
F_23 ( & V_38 -> V_64 , L_3 ) ;
V_60 = - V_28 ;
goto V_25;
}
V_25:
F_17 ( V_38 ) ;
F_4 ( V_69 , V_70 ) ;
F_12 ( V_38 , V_6 . V_42 , 0 ) ;
return V_60 ;
}
static int F_25 ( struct V_37 * V_38 , T_1 * V_8 , T_2 V_3 )
{
int V_13 , V_59 ;
T_3 V_54 ;
T_2 V_14 = 0 ;
T_1 V_61 = 0 ;
T_1 V_71 = V_72 ;
if ( V_3 > V_32 )
return - V_73 ;
if ( F_13 ( V_38 , 0 ) < 0 )
return - V_56 ;
V_59 = F_15 ( V_38 ) ;
if ( ( V_59 & V_53 ) == 0 ) {
F_17 ( V_38 ) ;
if ( F_19
( V_38 , V_53 ,
V_38 -> V_74 , & V_59 ) < 0 ) {
V_13 = - V_51 ;
goto V_75;
}
}
while ( V_14 < V_3 - 1 ) {
V_54 = F_18 ( V_38 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_54 > ( V_3 - 1 - V_14 ) )
V_54 = V_3 - 1 - V_14 ;
V_13 = F_8 ( F_21 ( V_6 . V_42 ) ,
& ( V_8 [ V_14 ] ) , V_54 ) ;
if ( V_13 == 0 )
V_14 += V_54 ;
else if ( V_13 < 0 )
V_61 ++ ;
if ( V_61 > V_36 ) {
V_13 = - V_28 ;
goto V_75;
}
F_19 ( V_38 , V_66 ,
V_38 -> V_67 , & V_59 ) ;
if ( ( V_59 & V_76 ) == 0 ) {
V_13 = - V_28 ;
goto V_75;
}
}
F_8 ( F_21 ( V_6 . V_42 ) , & ( V_8 [ V_14 ] ) , 1 ) ;
F_19 ( V_38 , V_66 , V_38 -> V_67 , & V_59 ) ;
if ( ( V_59 & V_76 ) != 0 ) {
V_13 = - V_28 ;
goto V_75;
}
F_8 ( F_16 ( V_6 . V_42 ) , & V_71 , 1 ) ;
return V_3 ;
V_75:
F_17 ( V_38 ) ;
F_4 ( V_69 , V_70 ) ;
F_12 ( V_38 , V_6 . V_42 , 0 ) ;
return V_13 ;
}
static bool F_26 ( struct V_37 * V_38 , T_1 V_59 )
{
return ( V_59 == V_53 ) ;
}
static int F_27 ( struct V_77 * V_64 )
{
T_4 V_78 ;
int V_13 = 0 ;
struct V_37 * V_38 ;
V_38 = F_28 ( V_64 , & V_79 ) ;
if ( F_29 ( V_38 ) )
return F_30 ( V_38 ) ;
V_38 -> V_48 = F_31 ( V_80 ) ;
V_38 -> V_74 = F_31 ( V_81 ) ;
V_38 -> V_67 = F_31 ( V_80 ) ;
V_38 -> V_55 = F_31 ( V_80 ) ;
if ( F_13 ( V_38 , 0 ) != 0 ) {
F_23 ( V_64 , L_4 ) ;
V_13 = - V_82 ;
goto V_75;
}
if ( F_1 ( F_32 ( 0 ) , ( T_1 * ) & V_78 , 4 ) < 0 ) {
F_23 ( V_64 , L_5 ) ;
V_13 = - V_28 ;
goto V_83;
}
if ( V_78 == V_84 ) {
V_6 . V_20 = V_21 ;
} else if ( V_78 == V_85 ) {
V_6 . V_20 = V_86 ;
} else {
F_23 ( V_64 , L_6 , V_78 ) ;
V_13 = - V_82 ;
goto V_83;
}
F_33 ( V_64 , L_7 , V_78 >> 16 ) ;
V_6 . V_38 = V_38 ;
return F_34 ( V_38 ) ;
V_83:
F_12 ( V_38 , V_6 . V_42 , 1 ) ;
V_6 . V_7 = NULL ;
V_75:
return V_13 ;
}
static int F_35 ( struct V_87 * V_7 ,
const struct V_88 * V_89 )
{
int V_13 ;
struct V_77 * V_64 = & ( V_7 -> V_64 ) ;
if ( V_6 . V_7 != NULL ) {
F_23 ( V_64 , L_8 ) ;
return - V_56 ;
}
if ( ! F_36 ( V_7 -> V_16 , V_90 ) ) {
F_23 ( V_64 , L_9 ) ;
return - V_82 ;
}
V_6 . V_7 = V_7 ;
V_13 = F_27 ( & V_7 -> V_64 ) ;
if ( V_13 != 0 ) {
V_6 . V_7 = NULL ;
V_13 = - V_82 ;
}
return V_13 ;
}
static int F_37 ( struct V_87 * V_7 )
{
struct V_37 * V_38 = V_6 . V_38 ;
F_38 ( V_38 ) ;
F_12 ( V_38 , V_6 . V_42 , 1 ) ;
V_6 . V_7 = NULL ;
return 0 ;
}
