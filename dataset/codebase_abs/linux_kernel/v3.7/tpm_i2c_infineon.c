static int F_1 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 )
{
struct V_4 V_5 = { V_6 . V_7 -> V_1 , 0 , 1 , & V_1 } ;
struct V_4 V_8 = { V_6 . V_7 -> V_1 , V_9 , V_3 , V_2 } ;
int V_10 ;
int V_11 ;
if ( ! V_6 . V_7 -> V_12 -> V_13 -> V_14 )
return - V_15 ;
F_2 ( V_6 . V_7 -> V_12 ) ;
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ ) {
V_10 = F_3 ( V_6 . V_7 -> V_12 , & V_5 , 1 ) ;
if ( V_10 > 0 )
break;
F_4 ( V_17 , V_18 ) ;
}
if ( V_10 <= 0 )
goto V_19;
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ ) {
F_4 ( V_17 , V_18 ) ;
V_10 = F_3 ( V_6 . V_7 -> V_12 , & V_8 , 1 ) ;
if ( V_10 > 0 )
break;
}
V_19:
F_5 ( V_6 . V_7 -> V_12 ) ;
if ( V_10 <= 0 )
return - V_20 ;
return 0 ;
}
static int F_6 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 ,
unsigned int V_21 ,
unsigned int V_22 , T_1 V_23 )
{
int V_10 = - V_20 ;
int V_11 ;
struct V_4 V_5 = { V_6 . V_7 -> V_1 , 0 , V_3 + 1 , V_6 . V_24 } ;
if ( V_3 > V_25 )
return - V_26 ;
if ( ! V_6 . V_7 -> V_12 -> V_13 -> V_14 )
return - V_15 ;
F_2 ( V_6 . V_7 -> V_12 ) ;
V_6 . V_24 [ 0 ] = V_1 ;
memcpy ( & ( V_6 . V_24 [ 1 ] ) , V_2 , V_3 ) ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ ) {
V_10 = F_3 ( V_6 . V_7 -> V_12 , & V_5 , 1 ) ;
if ( V_10 > 0 )
break;
F_4 ( V_21 , V_22 ) ;
}
F_5 ( V_6 . V_7 -> V_12 ) ;
if ( V_10 <= 0 )
return - V_20 ;
return 0 ;
}
static int F_7 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_1 , V_2 , V_3 , V_17 ,
V_18 , V_16 ) ;
}
static int F_8 ( T_1 V_1 , T_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_1 , V_2 , V_3 , V_27 ,
V_28 , V_29 ) ;
}
static int F_9 ( struct V_30 * V_31 , int V_32 )
{
T_1 V_24 ;
int V_10 ;
V_10 = F_1 ( F_10 ( V_32 ) , & V_24 , 1 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ( V_24 & ( V_33 | V_34 ) ) ==
( V_33 | V_34 ) ) {
V_31 -> V_35 . V_36 = V_32 ;
return V_32 ;
}
return - V_20 ;
}
static void F_11 ( struct V_30 * V_31 , int V_32 , int V_37 )
{
T_1 V_24 ;
if ( F_1 ( F_10 ( V_32 ) , & V_24 , 1 ) < 0 )
return;
if ( V_37 || ( V_24 & ( V_38 | V_34 ) ) ==
( V_38 | V_34 ) ) {
V_24 = V_33 ;
F_7 ( F_10 ( V_32 ) , & V_24 , 1 ) ;
}
}
static int F_12 ( struct V_30 * V_31 , int V_32 )
{
unsigned long V_39 ;
T_1 V_24 = V_40 ;
if ( F_9 ( V_31 , V_32 ) >= 0 )
return V_32 ;
F_7 ( F_10 ( V_32 ) , & V_24 , 1 ) ;
V_39 = V_41 + V_31 -> V_35 . V_42 ;
do {
if ( F_9 ( V_31 , V_32 ) >= 0 )
return V_32 ;
F_4 ( V_43 , V_44 ) ;
} while ( F_13 ( V_41 , V_39 ) );
return - V_45 ;
}
static T_1 F_14 ( struct V_30 * V_31 )
{
T_1 V_24 ;
if ( F_1 ( F_15 ( V_31 -> V_35 . V_36 ) , & V_24 , 1 ) < 0 )
return 0 ;
else
return V_24 ;
}
static void F_16 ( struct V_30 * V_31 )
{
T_1 V_24 = V_46 ;
F_8 ( F_15 ( V_31 -> V_35 . V_36 ) , & V_24 , 1 ) ;
}
static T_3 F_17 ( struct V_30 * V_31 )
{
unsigned long V_39 ;
T_3 V_47 ;
T_1 V_24 [ 3 ] ;
V_39 = V_41 + V_31 -> V_35 . V_48 ;
do {
if ( F_1 ( F_15 ( V_31 -> V_35 . V_36 ) + 1 , V_24 , 3 ) < 0 )
V_47 = 0 ;
else
V_47 = ( V_24 [ 2 ] << 16 ) + ( V_24 [ 1 ] << 8 ) + V_24 [ 0 ] ;
if ( V_47 )
return V_47 ;
F_4 ( V_43 , V_44 ) ;
} while ( F_13 ( V_41 , V_39 ) );
return - V_49 ;
}
static int F_18 ( struct V_30 * V_31 , T_1 V_50 , unsigned long V_51 ,
int * V_52 )
{
unsigned long V_39 ;
* V_52 = F_14 ( V_31 ) ;
if ( ( * V_52 & V_50 ) == V_50 )
return 0 ;
V_39 = V_41 + V_51 ;
do {
F_4 ( V_43 , V_44 ) ;
* V_52 = F_14 ( V_31 ) ;
if ( ( * V_52 & V_50 ) == V_50 )
return 0 ;
} while ( F_13 ( V_41 , V_39 ) );
return - V_45 ;
}
static int F_19 ( struct V_30 * V_31 , T_1 * V_24 , T_2 V_11 )
{
T_2 V_53 = 0 ;
T_3 V_47 ;
T_1 V_54 = 0 ;
int V_10 ;
while ( V_53 < V_11 ) {
V_47 = F_17 ( V_31 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_47 > ( V_11 - V_53 ) )
V_47 = V_11 - V_53 ;
V_10 = F_1 ( F_20 ( V_31 -> V_35 . V_36 ) ,
& ( V_24 [ V_53 ] ) , V_47 ) ;
if ( V_10 == 0 )
V_53 += V_47 ;
else if ( V_10 < 0 )
V_54 ++ ;
if ( V_54 > V_29 )
return - V_20 ;
}
return V_53 ;
}
static int F_21 ( struct V_30 * V_31 , T_1 * V_24 , T_2 V_11 )
{
int V_53 = 0 ;
int V_55 , V_52 ;
if ( V_11 < V_56 ) {
V_53 = - V_20 ;
goto V_19;
}
V_53 = F_19 ( V_31 , V_24 , V_56 ) ;
if ( V_53 < V_56 ) {
F_22 ( V_31 -> V_57 , L_1 ) ;
goto V_19;
}
V_55 = F_23 ( * ( V_58 * ) ( V_24 + 2 ) ) ;
if ( ( T_2 ) V_55 > V_11 ) {
V_53 = - V_20 ;
goto V_19;
}
V_53 += F_19 ( V_31 , & V_24 [ V_56 ] ,
V_55 - V_56 ) ;
if ( V_53 < V_55 ) {
F_22 ( V_31 -> V_57 , L_2 ) ;
V_53 = - V_45 ;
goto V_19;
}
F_18 ( V_31 , V_59 , V_31 -> V_35 . V_60 , & V_52 ) ;
if ( V_52 & V_61 ) {
F_22 ( V_31 -> V_57 , L_3 ) ;
V_53 = - V_20 ;
goto V_19;
}
V_19:
F_16 ( V_31 ) ;
F_4 ( V_62 , V_63 ) ;
F_11 ( V_31 , V_31 -> V_35 . V_36 , 0 ) ;
return V_53 ;
}
static int F_24 ( struct V_30 * V_31 , T_1 * V_24 , T_2 V_3 )
{
int V_10 , V_52 ;
T_3 V_47 ;
T_2 V_11 = 0 ;
T_1 V_54 = 0 ;
T_1 V_64 = V_65 ;
if ( V_3 > V_25 )
return - V_66 ;
if ( F_12 ( V_31 , 0 ) < 0 )
return - V_49 ;
V_52 = F_14 ( V_31 ) ;
if ( ( V_52 & V_46 ) == 0 ) {
F_16 ( V_31 ) ;
if ( F_18
( V_31 , V_46 ,
V_31 -> V_35 . V_67 , & V_52 ) < 0 ) {
V_10 = - V_45 ;
goto V_68;
}
}
while ( V_11 < V_3 - 1 ) {
V_47 = F_17 ( V_31 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_47 > ( V_3 - 1 - V_11 ) )
V_47 = V_3 - 1 - V_11 ;
V_10 = F_7 ( F_20 ( V_31 -> V_35 . V_36 ) ,
& ( V_24 [ V_11 ] ) , V_47 ) ;
if ( V_10 == 0 )
V_11 += V_47 ;
else if ( V_10 < 0 )
V_54 ++ ;
if ( V_54 > V_29 ) {
V_10 = - V_20 ;
goto V_68;
}
F_18 ( V_31 , V_59 ,
V_31 -> V_35 . V_60 , & V_52 ) ;
if ( ( V_52 & V_69 ) == 0 ) {
V_10 = - V_20 ;
goto V_68;
}
}
F_7 ( F_20 ( V_31 -> V_35 . V_36 ) , & ( V_24 [ V_11 ] ) , 1 ) ;
F_18 ( V_31 , V_59 , V_31 -> V_35 . V_60 , & V_52 ) ;
if ( ( V_52 & V_69 ) != 0 ) {
V_10 = - V_20 ;
goto V_68;
}
F_7 ( F_15 ( V_31 -> V_35 . V_36 ) , & V_64 , 1 ) ;
return V_3 ;
V_68:
F_16 ( V_31 ) ;
F_4 ( V_62 , V_63 ) ;
F_11 ( V_31 , V_31 -> V_35 . V_36 , 0 ) ;
return V_10 ;
}
static int T_4 F_25 ( struct V_70 * V_57 )
{
T_5 V_35 ;
int V_10 = 0 ;
struct V_30 * V_31 ;
V_31 = F_26 ( V_57 , & V_71 ) ;
if ( ! V_31 ) {
V_10 = - V_72 ;
goto V_68;
}
V_31 -> V_35 . V_73 = 0 ;
V_31 -> V_35 . V_42 = F_27 ( V_74 ) ;
V_31 -> V_35 . V_67 = F_27 ( V_75 ) ;
V_31 -> V_35 . V_60 = F_27 ( V_74 ) ;
V_31 -> V_35 . V_48 = F_27 ( V_74 ) ;
if ( F_12 ( V_31 , 0 ) != 0 ) {
V_10 = - V_72 ;
goto V_76;
}
if ( F_1 ( F_28 ( 0 ) , ( T_1 * ) & V_35 , 4 ) < 0 ) {
V_10 = - V_20 ;
goto V_77;
}
V_35 = F_23 ( ( V_58 ) V_35 ) ;
if ( V_35 != V_78 ) {
V_10 = - V_72 ;
goto V_77;
}
F_29 ( V_57 , L_4 , V_35 >> 16 ) ;
F_30 ( & V_31 -> V_35 . V_79 ) ;
V_6 . V_31 = V_31 ;
F_31 ( V_31 ) ;
F_32 ( V_31 ) ;
return 0 ;
V_77:
F_11 ( V_31 , V_31 -> V_35 . V_36 , 1 ) ;
V_76:
F_33 ( V_31 ) ;
F_34 ( V_31 -> V_57 ) ;
V_31 -> V_57 -> V_80 = NULL ;
V_31 -> V_80 = NULL ;
V_6 . V_7 = NULL ;
F_35 ( V_31 -> V_57 , V_31 ) ;
V_68:
return V_10 ;
}
static int T_4 F_36 ( struct V_81 * V_7 ,
const struct V_82 * V_83 )
{
int V_10 ;
if ( V_6 . V_7 != NULL )
return - V_49 ;
if ( ! F_37 ( V_7 -> V_12 , V_84 ) ) {
F_22 ( & V_7 -> V_57 ,
L_5 ) ;
return - V_72 ;
}
V_7 -> V_85 = & V_86 ;
V_6 . V_7 = V_7 ;
V_10 = F_25 ( & V_7 -> V_57 ) ;
if ( V_10 != 0 ) {
V_7 -> V_85 = NULL ;
V_6 . V_7 = NULL ;
V_10 = - V_72 ;
}
return V_10 ;
}
static int T_6 F_38 ( struct V_81 * V_7 )
{
struct V_30 * V_31 = V_6 . V_31 ;
F_11 ( V_31 , V_31 -> V_35 . V_36 , 1 ) ;
F_33 ( V_31 ) ;
F_34 ( V_31 -> V_57 ) ;
V_31 -> V_57 -> V_80 = NULL ;
V_31 -> V_80 = NULL ;
V_6 . V_7 = NULL ;
F_35 ( V_31 -> V_57 , V_31 ) ;
return 0 ;
}
