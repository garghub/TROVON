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
static bool F_9 ( struct V_34 * V_35 , int V_36 )
{
T_1 V_8 ;
int V_13 ;
V_13 = F_1 ( F_10 ( V_36 ) , & V_8 , 1 ) ;
if ( V_13 < 0 )
return false ;
if ( ( V_8 & ( V_37 | V_38 ) ) ==
( V_37 | V_38 ) ) {
V_6 . V_39 = V_36 ;
return true ;
}
return false ;
}
static void F_11 ( struct V_34 * V_35 , int V_36 , int V_40 )
{
T_1 V_8 ;
if ( F_1 ( F_10 ( V_36 ) , & V_8 , 1 ) < 0 )
return;
if ( V_40 || ( V_8 & ( V_41 | V_38 ) ) ==
( V_41 | V_38 ) ) {
V_8 = V_37 ;
F_7 ( F_10 ( V_36 ) , & V_8 , 1 ) ;
}
}
static int F_12 ( struct V_34 * V_35 , int V_36 )
{
unsigned long V_42 ;
T_1 V_8 = V_43 ;
if ( F_9 ( V_35 , V_36 ) )
return V_36 ;
F_7 ( F_10 ( V_36 ) , & V_8 , 1 ) ;
V_42 = V_44 + V_35 -> V_45 ;
do {
if ( F_9 ( V_35 , V_36 ) )
return V_36 ;
F_4 ( V_46 , V_47 ) ;
} while ( F_13 ( V_44 , V_42 ) );
return - V_48 ;
}
static T_1 F_14 ( struct V_34 * V_35 )
{
T_1 V_8 = 0xFF ;
T_1 V_49 = 0 ;
do {
if ( F_1 ( F_15 ( V_6 . V_39 ) , & V_8 , 1 ) < 0 )
return 0 ;
V_49 ++ ;
} while ( ( V_8 == 0xFF ) && V_49 < 10 );
return V_8 ;
}
static void F_16 ( struct V_34 * V_35 )
{
T_1 V_8 = V_50 ;
F_8 ( F_15 ( V_6 . V_39 ) , & V_8 , 1 ) ;
}
static T_3 F_17 ( struct V_34 * V_35 )
{
unsigned long V_42 ;
T_3 V_51 ;
T_1 V_8 [ 3 ] ;
V_42 = V_44 + V_35 -> V_52 ;
do {
if ( F_1 ( F_15 ( V_6 . V_39 ) + 1 , V_8 , 3 ) < 0 )
V_51 = 0 ;
else
V_51 = ( V_8 [ 2 ] << 16 ) + ( V_8 [ 1 ] << 8 ) + V_8 [ 0 ] ;
if ( V_51 )
return V_51 ;
F_4 ( V_46 , V_47 ) ;
} while ( F_13 ( V_44 , V_42 ) );
return - V_53 ;
}
static int F_18 ( struct V_34 * V_35 , T_1 V_54 , unsigned long V_55 ,
int * V_56 )
{
unsigned long V_42 ;
* V_56 = F_14 ( V_35 ) ;
if ( ( * V_56 != 0xFF ) && ( * V_56 & V_54 ) == V_54 )
return 0 ;
V_42 = V_44 + V_55 ;
do {
F_4 ( V_46 , V_47 ) ;
* V_56 = F_14 ( V_35 ) ;
if ( ( * V_56 & V_54 ) == V_54 )
return 0 ;
} while ( F_13 ( V_44 , V_42 ) );
return - V_48 ;
}
static int F_19 ( struct V_34 * V_35 , T_1 * V_8 , T_2 V_14 )
{
T_2 V_57 = 0 ;
T_3 V_51 ;
T_1 V_58 = 0 ;
int V_13 ;
while ( V_57 < V_14 ) {
V_51 = F_17 ( V_35 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_51 > ( V_14 - V_57 ) )
V_51 = V_14 - V_57 ;
V_13 = F_1 ( F_20 ( V_6 . V_39 ) ,
& ( V_8 [ V_57 ] ) , V_51 ) ;
if ( V_13 == 0 )
V_57 += V_51 ;
else if ( V_13 < 0 )
V_58 ++ ;
if ( V_58 > V_33 )
return - V_25 ;
}
return V_57 ;
}
static int F_21 ( struct V_34 * V_35 , T_1 * V_8 , T_2 V_14 )
{
int V_57 = 0 ;
int V_59 , V_56 ;
if ( V_14 < V_60 ) {
V_57 = - V_25 ;
goto V_24;
}
V_57 = F_19 ( V_35 , V_8 , V_60 ) ;
if ( V_57 < V_60 ) {
F_22 ( & V_35 -> V_61 , L_1 ) ;
goto V_24;
}
V_59 = F_23 ( * ( V_62 * ) ( V_8 + 2 ) ) ;
if ( ( T_2 ) V_59 > V_14 ) {
V_57 = - V_25 ;
goto V_24;
}
V_57 += F_19 ( V_35 , & V_8 [ V_60 ] ,
V_59 - V_60 ) ;
if ( V_57 < V_59 ) {
F_22 ( & V_35 -> V_61 , L_2 ) ;
V_57 = - V_48 ;
goto V_24;
}
F_18 ( V_35 , V_63 , V_35 -> V_64 , & V_56 ) ;
if ( V_56 & V_65 ) {
F_22 ( & V_35 -> V_61 , L_3 ) ;
V_57 = - V_25 ;
goto V_24;
}
V_24:
F_16 ( V_35 ) ;
F_4 ( V_66 , V_67 ) ;
F_11 ( V_35 , V_6 . V_39 , 0 ) ;
return V_57 ;
}
static int F_24 ( struct V_34 * V_35 , T_1 * V_8 , T_2 V_3 )
{
int V_13 , V_56 ;
T_3 V_51 ;
T_2 V_14 = 0 ;
T_1 V_58 = 0 ;
T_1 V_68 = V_69 ;
if ( V_3 > V_29 )
return - V_70 ;
if ( F_12 ( V_35 , 0 ) < 0 )
return - V_53 ;
V_56 = F_14 ( V_35 ) ;
if ( ( V_56 & V_50 ) == 0 ) {
F_16 ( V_35 ) ;
if ( F_18
( V_35 , V_50 ,
V_35 -> V_71 , & V_56 ) < 0 ) {
V_13 = - V_48 ;
goto V_72;
}
}
while ( V_14 < V_3 - 1 ) {
V_51 = F_17 ( V_35 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_51 > ( V_3 - 1 - V_14 ) )
V_51 = V_3 - 1 - V_14 ;
V_13 = F_7 ( F_20 ( V_6 . V_39 ) ,
& ( V_8 [ V_14 ] ) , V_51 ) ;
if ( V_13 == 0 )
V_14 += V_51 ;
else if ( V_13 < 0 )
V_58 ++ ;
if ( V_58 > V_33 ) {
V_13 = - V_25 ;
goto V_72;
}
F_18 ( V_35 , V_63 ,
V_35 -> V_64 , & V_56 ) ;
if ( ( V_56 & V_73 ) == 0 ) {
V_13 = - V_25 ;
goto V_72;
}
}
F_7 ( F_20 ( V_6 . V_39 ) , & ( V_8 [ V_14 ] ) , 1 ) ;
F_18 ( V_35 , V_63 , V_35 -> V_64 , & V_56 ) ;
if ( ( V_56 & V_73 ) != 0 ) {
V_13 = - V_25 ;
goto V_72;
}
F_7 ( F_15 ( V_6 . V_39 ) , & V_68 , 1 ) ;
return V_3 ;
V_72:
F_16 ( V_35 ) ;
F_4 ( V_66 , V_67 ) ;
F_11 ( V_35 , V_6 . V_39 , 0 ) ;
return V_13 ;
}
static bool F_25 ( struct V_34 * V_35 , T_1 V_56 )
{
return ( V_56 == V_50 ) ;
}
static int F_26 ( struct V_74 * V_61 )
{
T_4 V_75 ;
int V_13 = 0 ;
struct V_34 * V_35 ;
V_35 = F_27 ( V_61 , & V_76 ) ;
if ( F_28 ( V_35 ) )
return F_29 ( V_35 ) ;
V_35 -> V_45 = F_30 ( V_77 ) ;
V_35 -> V_71 = F_30 ( V_78 ) ;
V_35 -> V_64 = F_30 ( V_77 ) ;
V_35 -> V_52 = F_30 ( V_77 ) ;
if ( F_12 ( V_35 , 0 ) != 0 ) {
F_22 ( V_61 , L_4 ) ;
V_13 = - V_79 ;
goto V_72;
}
if ( F_1 ( F_31 ( 0 ) , ( T_1 * ) & V_75 , 4 ) < 0 ) {
F_22 ( V_61 , L_5 ) ;
V_13 = - V_25 ;
goto V_80;
}
if ( V_75 == V_81 ) {
V_6 . V_19 = V_20 ;
} else if ( V_75 == V_82 ) {
V_6 . V_19 = V_83 ;
} else {
F_22 ( V_61 , L_6 , V_75 ) ;
V_13 = - V_79 ;
goto V_80;
}
F_32 ( V_61 , L_7 , V_75 >> 16 ) ;
V_6 . V_35 = V_35 ;
return F_33 ( V_35 ) ;
V_80:
F_11 ( V_35 , V_6 . V_39 , 1 ) ;
V_6 . V_7 = NULL ;
V_72:
return V_13 ;
}
static int F_34 ( struct V_84 * V_7 ,
const struct V_85 * V_86 )
{
int V_13 ;
struct V_74 * V_61 = & ( V_7 -> V_61 ) ;
if ( V_6 . V_7 != NULL ) {
F_22 ( V_61 , L_8 ) ;
return - V_53 ;
}
if ( ! F_35 ( V_7 -> V_15 , V_87 ) ) {
F_22 ( V_61 , L_9 ) ;
return - V_79 ;
}
V_6 . V_7 = V_7 ;
V_13 = F_26 ( & V_7 -> V_61 ) ;
if ( V_13 != 0 ) {
V_6 . V_7 = NULL ;
V_13 = - V_79 ;
}
return V_13 ;
}
static int F_36 ( struct V_84 * V_7 )
{
struct V_34 * V_35 = V_6 . V_35 ;
F_37 ( V_35 ) ;
F_11 ( V_35 , V_6 . V_39 , 1 ) ;
V_6 . V_7 = NULL ;
return 0 ;
}
