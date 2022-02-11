static inline int F_1 ( enum V_1 V_2 ,
struct V_3 * * V_4 )
{
if ( V_2 == V_5 )
* V_4 = & ( V_6 -> V_7 ) ;
else if ( V_2 == V_8 )
* V_4 = & ( V_6 -> V_9 ) ;
else
return - V_10 ;
return 0 ;
}
static int F_2 ( enum V_1 V_2 ,
T_1 * V_11 , T_2 V_12 ,
enum V_13 V_14 )
{
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_1 ( V_2 , & V_4 ) ;
if ( V_15 < 0 )
return V_15 ;
switch ( V_14 ) {
case V_16 :
if ( V_12 > V_17 )
return - V_10 ;
break;
case V_18 :
if ( V_12 > V_17 )
return - V_10 ;
if ( ( V_12 > 0 ) && ( V_11 == NULL ) )
return - V_10 ;
break;
case V_19 :
if ( ( V_12 + V_4 -> V_20 ) >
V_17 )
return - V_10 ;
if ( ( V_12 > 0 ) && ( V_11 == NULL ) )
return - V_10 ;
break;
default:
F_3 ( L_1 , V_14 ) ;
return - V_10 ;
}
return 0 ;
}
static inline int F_4 ( T_1 V_21 , int V_22 )
{
T_1 V_23 ;
int V_15 ;
V_23 = V_21 | V_24 ;
V_23 <<= V_25 ;
V_23 |= V_22 ;
V_15 = F_5 ( V_26 ,
V_27 , ( T_2 * ) & V_23 ,
V_28 , NULL , 0 ) ;
return V_15 ;
}
static inline int F_6 ( T_1 V_21 , int V_22 )
{
T_1 V_23 ;
int V_15 ;
V_23 = V_21 | V_24 ;
V_15 = F_7 ( V_29 ,
V_22 , 0 , & V_23 , NULL ) ;
return V_15 ;
}
static int F_8 ( struct V_30 V_31 ,
enum V_13 V_14 )
{
T_2 V_32 , V_33 ;
int V_15 , V_22 , V_34 ;
T_1 * V_35 ;
T_1 V_36 ;
V_32 = V_31 . V_37 ;
V_33 = V_31 . V_38 ;
V_35 = V_31 . V_11 ;
V_15 = F_5 ( V_26 ,
V_39 , NULL , 0 ,
& V_36 , V_40 ) ;
if ( V_15 ) {
F_3 ( L_2 ) ;
return V_15 ;
}
F_9 ( V_36 ) ;
V_15 = F_5 ( V_26 ,
V_41 ,
( T_2 * ) & V_36 ,
V_42 ,
NULL , 0 ) ;
if ( V_15 ) {
F_3 ( L_3 ) ;
return V_15 ;
}
if ( V_14 == V_16 ) {
F_10 ( V_36 ) ;
V_15 = F_5 ( V_26 ,
V_41 ,
( T_2 * ) & V_36 ,
V_42 ,
NULL , 0 ) ;
if ( V_15 ) {
F_3 ( L_3 ) ;
return V_15 ;
}
V_6 -> V_9 . V_20 = 0 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
if ( F_4 (
V_6 -> V_9 . V_43 [ V_34 ] . V_21 ,
V_34 ) ) {
F_3 ( L_4 ,
V_6 -> V_9 . V_43 [ V_34 ] . V_21 ) ;
continue;
}
V_6 -> V_9 . V_20 ++ ;
}
}
if ( V_14 == V_18 ) {
F_10 ( V_36 ) ;
V_15 = F_5 ( V_26 ,
V_41 ,
( T_2 * ) & V_36 ,
V_42 ,
NULL , 0 ) ;
if ( V_15 ) {
F_3 ( L_3 ) ;
return V_15 ;
}
V_6 -> V_9 . V_20 = 0 ;
for ( V_22 = 0 ; V_22 < V_32 ; V_22 ++ ) {
V_6 -> V_9 . V_43 [ V_22 ] . V_21 =
V_35 [ V_22 ] ;
if ( F_4 (
V_6 -> V_9 . V_43 [ V_22 ] . V_21 ,
V_22 ) ) {
F_3 ( L_5 ,
V_35 [ V_22 ] ) ;
continue;
}
V_6 -> V_9 . V_20 ++ ;
}
}
if ( V_14 == V_19 ) {
for ( V_22 = V_6 -> V_9 . V_20 , V_34 = 0 ;
V_34 < V_32 ; V_22 ++ , V_34 ++ ) {
V_6 -> V_9 . V_43 [ V_22 ] . V_21 =
V_35 [ V_34 ] ;
if ( F_4 (
V_6 -> V_9 . V_43 [ V_22 ] . V_21 ,
V_22 ) ) {
F_3 ( L_6 ,
V_35 [ V_34 ] ) ;
continue;
}
V_6 -> V_9 . V_20 ++ ;
}
}
F_11 ( V_36 ) ;
F_12 ( V_36 ) ;
F_13 ( V_36 ) ;
V_36 |= V_33 ;
V_15 = F_5 ( V_26 ,
V_41 ,
( T_2 * ) & V_36 ,
V_42 , NULL , 0 ) ;
if ( V_15 ) {
F_3 ( L_7 ) ;
return V_15 ;
}
V_6 -> V_9 . V_44 = V_33 ;
return 0 ;
}
static int F_14 ( struct V_30 V_31 ,
enum V_13 V_14 )
{
T_2 V_45 , V_46 ;
int V_15 , V_22 , V_34 ;
T_1 * V_47 ;
T_1 V_36 ;
V_45 = V_31 . V_37 ;
V_46 = V_31 . V_38 ;
V_47 = V_31 . V_11 ;
V_15 = F_7 ( V_48 ,
0 , 0 , NULL , & V_36 ) ;
if ( V_15 ) {
F_3 ( L_8 ) ;
return V_15 ;
}
F_9 ( V_36 ) ;
V_15 = F_7 ( V_49 ,
0 , 0 , & V_36 , NULL ) ;
if ( V_15 ) {
F_3 ( L_9 ) ;
return V_15 ;
}
if ( V_14 == V_16 ) {
F_10 ( V_36 ) ;
V_15 = F_7 (
V_49 ,
0 , 0 , & V_36 , NULL ) ;
if ( V_15 ) {
F_3 ( L_9 ) ;
return V_15 ;
}
V_6 -> V_7 . V_20 = 0 ;
for ( V_34 = 0 ; V_34 < V_45 ; V_34 ++ ) {
if ( F_6 (
V_6 -> V_7 . V_43 [ V_34 ] . V_21 ,
V_34 ) ) {
F_3 ( L_10 ,
V_6 -> V_7 . V_43 [ V_34 ] . V_21 ) ;
continue;
}
V_6 -> V_7 . V_20 ++ ;
}
}
if ( V_14 == V_18 ) {
F_10 ( V_36 ) ;
V_15 = F_7 (
V_49 ,
0 , 0 , & V_36 , NULL ) ;
if ( V_15 ) {
F_3 ( L_9 ) ;
return V_15 ;
}
V_6 -> V_7 . V_20 = 0 ;
for ( V_22 = 0 ; V_22 < V_45 ; V_22 ++ ) {
V_6 -> V_7 . V_43 [ V_22 ] . V_21 =
V_47 [ V_22 ] ;
if ( F_6 (
V_6 -> V_7 . V_43 [ V_22 ] . V_21 ,
V_22 ) ) {
F_3 ( L_11 ,
V_47 [ V_22 ] ) ;
continue;
}
V_6 -> V_7 . V_20 ++ ;
}
}
if ( V_14 == V_19 ) {
for ( V_22 = V_6 -> V_7 . V_20 , V_34 = 0 ;
V_34 < V_45 ; V_22 ++ , V_34 ++ ) {
V_6 -> V_7 . V_43 [ V_22 ] . V_21 =
V_47 [ V_34 ] ;
if ( F_6 (
V_6 -> V_7 . V_43 [ V_22 ] . V_21 ,
V_22 ) ) {
F_3 ( L_12 ,
V_47 [ V_34 ] ) ;
continue;
}
V_6 -> V_7 . V_20 ++ ;
}
}
F_11 ( V_36 ) ;
F_12 ( V_36 ) ;
F_13 ( V_36 ) ;
V_36 |= V_46 ;
V_15 = F_7 ( V_49 ,
0 , 0 , & V_36 , NULL ) ;
if ( V_15 ) {
F_3 ( L_13 ) ;
return V_15 ;
}
V_6 -> V_7 . V_44 = V_46 ;
return 0 ;
}
static int F_15 ( struct V_30 V_50 ,
struct V_30 V_51 ,
enum V_13 V_14 )
{
int V_15 ;
F_16 ( & ( V_6 -> V_52 ) ) ;
if ( ( V_14 == V_18 ) && ( V_6 -> V_53 ) ) {
V_15 = - V_54 ;
goto V_55;
}
V_15 = F_2 ( V_5 , V_50 . V_11 ,
V_50 . V_37 , V_14 ) ;
if ( V_15 )
goto V_55;
V_15 = F_2 ( V_8 , V_51 . V_11 ,
V_51 . V_37 , V_14 ) ;
if ( V_15 )
goto V_55;
if ( V_51 . V_37 ) {
V_15 = F_8 ( V_51 , V_14 ) ;
if ( V_15 )
goto V_55;
}
if ( V_50 . V_37 ) {
V_15 = F_14 ( V_50 , V_14 ) ;
if ( V_15 )
goto V_55;
}
if ( ( V_14 == V_18 ) || ( V_14 == V_19 ) )
V_6 -> V_53 = true ;
else
V_6 -> V_53 = false ;
V_55:
F_17 ( & ( V_6 -> V_52 ) ) ;
return V_15 ;
}
static int F_18 ( struct V_56 * V_57 )
{
struct V_30 V_50 , V_51 ;
T_1 V_58 , V_59 , V_60 ;
int V_15 ;
V_15 = F_5 ( V_26 , V_61 ,
NULL , 0 , & V_58 , V_40 ) ;
if ( V_15 ) {
F_19 ( & V_57 -> V_62 , L_14 ) ;
return V_15 ;
}
V_59 = ( V_58 & V_63 ) >>
V_64 ;
V_60 = V_58 & V_65 ;
if ( ( V_59 < V_17 ) ||
( V_60 < V_17 ) ) {
F_19 ( & V_57 -> V_62 , L_15 ) ;
F_19 ( & V_57 -> V_62 , L_16 ,
V_59 , V_60 ) ;
return - V_66 ;
}
V_6 -> V_9 . V_67 = F_20 ( V_58 ) ;
V_6 -> V_9 . V_68 = F_21 ( V_58 ) ;
V_15 = F_7 ( V_69 , 0 , 0 ,
NULL , & V_58 ) ;
if ( V_15 ) {
F_19 ( & V_57 -> V_62 , L_17 ) ;
return V_15 ;
}
V_59 = ( V_58 & V_63 ) >>
V_64 ;
V_60 = V_58 & V_63 ;
if ( ( V_59 < V_17 ) ||
( V_60 < V_17 ) ) {
F_19 ( & V_57 -> V_62 , L_18 ) ;
F_19 ( & V_57 -> V_62 , L_16 ,
V_59 , V_60 ) ;
return - V_66 ;
}
V_6 -> V_7 . V_67 = F_20 ( V_58 ) ;
V_6 -> V_7 . V_68 = F_21 ( V_58 ) ;
V_50 . V_11 = NULL ;
V_50 . V_37 = V_70 ;
V_50 . V_38 = V_71 ;
V_51 . V_11 = NULL ;
V_51 . V_37 = V_70 ;
V_51 . V_38 = V_71 ;
V_15 = F_15 ( V_50 , V_51 ,
V_16 ) ;
if ( V_15 ) {
F_19 ( & V_57 -> V_62 , L_19 ) ;
return V_15 ;
}
return 0 ;
}
static int F_22 ( struct V_30 V_50 ,
struct V_30 V_51 )
{
int V_15 ;
if ( ( V_50 . V_37 > 0 ) &&
( F_23 ( V_50 . V_38 ) ) ) {
F_3 ( L_20 ) ;
return - V_10 ;
}
if ( ( V_51 . V_37 > 0 ) &&
( F_23 ( V_51 . V_38 ) ) ) {
F_3 ( L_21 ) ;
return - V_10 ;
}
V_15 = F_15 ( V_50 , V_51 ,
V_18 ) ;
if ( V_15 )
F_3 ( L_22 ) ;
return V_15 ;
}
static int F_24 ( T_2 V_46 , T_2 V_33 )
{
T_1 V_36 = 0 ;
int V_15 = 0 ;
F_16 ( & ( V_6 -> V_52 ) ) ;
if ( V_33 ) {
if ( F_23 ( V_33 ) ) {
F_3 ( L_21 ) ;
V_15 = - V_10 ;
goto V_55;
}
V_15 = F_5 ( V_26 ,
V_39 , NULL , 0 ,
& V_36 , V_40 ) ;
if ( V_15 ) {
F_3 ( L_2 ) ;
goto V_55;
}
F_9 ( V_36 ) ;
V_15 = F_5 ( V_26 ,
V_41 ,
( T_2 * ) & V_36 ,
V_42 ,
NULL , 0 ) ;
if ( V_15 ) {
F_3 ( L_3 ) ;
goto V_55;
}
F_11 ( V_36 ) ;
F_12 ( V_36 ) ;
F_13 ( V_36 ) ;
V_36 |= V_33 ;
V_15 = F_5 ( V_26 ,
V_41 ,
( T_2 * ) & V_36 ,
V_42 ,
NULL , 0 ) ;
if ( V_15 ) {
F_3 ( L_7 ) ;
goto V_55;
}
V_6 -> V_9 . V_44 = V_33 ;
}
if ( V_46 ) {
if ( F_23 ( V_46 ) ) {
F_3 ( L_20 ) ;
V_15 = - V_10 ;
goto V_55;
}
V_15 = F_7 (
V_48 ,
0 , 0 , NULL , & V_36 ) ;
if ( V_15 ) {
F_3 ( L_8 ) ;
goto V_55;
}
F_9 ( V_36 ) ;
V_15 = F_7 (
V_49 ,
0 , 0 , & V_36 , NULL ) ;
if ( V_15 ) {
F_3 ( L_9 ) ;
goto V_55;
}
F_11 ( V_36 ) ;
F_12 ( V_36 ) ;
F_13 ( V_36 ) ;
V_36 |= V_46 ;
V_15 = F_7 (
V_49 ,
0 , 0 , & V_36 , NULL ) ;
if ( V_15 ) {
F_3 ( L_13 ) ;
goto V_55;
}
V_6 -> V_7 . V_44 = V_46 ;
}
V_55:
F_17 ( & ( V_6 -> V_52 ) ) ;
return V_15 ;
}
static int F_25 ( T_2 * V_72 ,
T_2 * V_73 ,
T_2 * V_74 ,
T_2 * V_75 )
{
* V_72 = V_6 -> V_7 . V_67 ;
* V_73 = V_6 -> V_7 . V_68 ;
* V_74 = V_6 -> V_9 . V_67 ;
* V_75 = V_6 -> V_9 . V_68 ;
return 0 ;
}
static int F_26 ( void )
{
struct V_30 V_50 , V_51 ;
int V_15 ;
V_50 . V_11 = NULL ;
V_50 . V_37 = V_70 ;
V_50 . V_38 = V_71 ;
V_51 . V_11 = NULL ;
V_51 . V_37 = V_70 ;
V_51 . V_38 = V_71 ;
V_15 = F_15 ( V_50 , V_51 ,
V_16 ) ;
if ( V_15 )
F_3 ( L_23 ) ;
return V_15 ;
}
static int F_27 ( struct V_30 * V_7 ,
struct V_30 * V_9 ,
int V_76 , int V_77 )
{
T_1 * V_47 , * V_35 ;
T_1 V_22 ;
V_47 = V_7 -> V_11 ;
V_35 = V_9 -> V_11 ;
F_16 ( & ( V_6 -> V_52 ) ) ;
V_7 -> V_37 = V_6 -> V_7 . V_20 ;
V_9 -> V_37 = V_6 -> V_9 . V_20 ;
V_7 -> V_38 = V_6 -> V_7 . V_44 ;
V_9 -> V_38 = V_6 -> V_9 . V_44 ;
if ( ( V_76 < V_6 -> V_7 . V_20 ) ||
( V_77 < V_6 -> V_9 . V_20 ) ) {
F_17 ( & ( V_6 -> V_52 ) ) ;
return - V_10 ;
}
for ( V_22 = 0 ; V_22 < V_6 -> V_7 . V_20 ;
V_22 ++ ) {
V_47 [ V_22 ] =
V_6 -> V_7 . V_43 [ V_22 ] . V_21 ;
}
for ( V_22 = 0 ; V_22 < V_6 -> V_9 . V_20 ;
V_22 ++ ) {
V_35 [ V_22 ] =
V_6 -> V_9 . V_43 [ V_22 ] . V_21 ;
}
F_17 ( & ( V_6 -> V_52 ) ) ;
return 0 ;
}
static int F_28 ( T_2 V_45 , T_2 V_32 ,
T_1 * V_47 , T_1 * V_35 )
{
struct V_30 V_50 , V_51 ;
int V_15 ;
V_50 . V_11 = V_47 ;
V_50 . V_37 = V_45 ;
V_50 . V_38 = V_6 -> V_7 . V_44 ;
V_51 . V_11 = V_35 ;
V_51 . V_37 = V_32 ;
V_51 . V_38 = V_6 -> V_9 . V_44 ;
V_15 = F_15 ( V_50 , V_51 ,
V_19 ) ;
if ( V_15 )
F_3 ( L_24 ) ;
return V_15 ;
}
static int F_29 ( enum V_1 V_2 ,
struct V_78 * V_79 , T_2 V_12 )
{
struct V_3 * V_4 ;
T_3 V_80 , V_81 ;
int V_15 , V_22 , V_82 = 0 ;
V_15 = F_1 ( V_2 , & V_4 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_12 > V_4 -> V_20 )
V_12 = V_4 -> V_20 ;
do {
V_80 = F_30 ( V_4 -> V_83 ) ;
if ( ! V_80 ) {
F_3 ( L_25 ) ;
return - V_54 ;
}
V_79 -> V_84 = F_30 ( V_4 -> V_83 +
V_85 ) ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
V_79 -> V_59 [ V_22 ] =
F_30 ( V_4 -> V_83 + V_86 +
V_87 * V_22 ) ;
}
V_81 = F_30 ( V_4 -> V_83 ) ;
if ( ! V_81 ) {
F_3 ( L_25 ) ;
return - V_54 ;
}
if ( V_82 ++ > V_88 ) {
F_3 ( L_26 ) ;
return - V_54 ;
}
} while ( V_80 != V_81 );
V_79 -> V_89 = V_81 ;
return V_12 ;
}
static int F_31 ( enum V_1 V_2 ,
struct V_90 * V_91 ,
int V_12 , int V_92 )
{
int V_22 , V_93 , V_15 , V_94 = V_12 ;
struct V_78 V_79 ;
struct V_95 * V_11 ;
switch ( V_2 ) {
case V_5 :
V_11 = V_6 -> V_7 . V_43 ;
break;
case V_8 :
V_11 = V_6 -> V_9 . V_43 ;
break;
default:
F_3 ( L_27 , V_2 ) ;
return - V_10 ;
}
if ( ! V_92 )
V_94 = V_17 ;
V_15 = F_29 ( V_2 , & V_79 , V_94 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ( ! V_92 ) && ( V_12 > V_15 ) )
return - V_10 ;
if ( V_92 )
for ( V_22 = 0 ; V_22 < V_15 ; V_22 ++ ) {
V_91 [ V_22 ] . V_96 = V_79 . V_59 [ V_22 ] ;
V_91 [ V_22 ] . V_97 = V_11 [ V_22 ] . V_21 ;
}
else
for ( V_22 = 0 , V_94 = 0 ; ( V_22 < V_15 ) && ( V_94 < V_12 ) ;
V_22 ++ ) {
for ( V_93 = 0 ; V_93 < V_12 ; V_93 ++ ) {
if ( V_11 [ V_22 ] . V_21 ==
V_91 [ V_93 ] . V_97 ) {
V_91 [ V_93 ] . V_96 =
V_79 . V_59 [ V_22 ] ;
V_94 ++ ;
break;
}
}
}
return V_94 ;
}
static int F_32 ( enum V_1 V_2 ,
struct V_90 * V_91 , int V_12 , int V_92 )
{
int V_15 ;
F_16 ( & ( V_6 -> V_52 ) ) ;
V_15 = F_31 ( V_2 , V_91 ,
V_12 , V_92 ) ;
F_17 ( & ( V_6 -> V_52 ) ) ;
return V_15 ;
}
static int F_33 ( enum V_1 V_2 ,
T_1 * V_98 )
{
T_1 V_99 = 0 ;
int V_15 ;
if ( V_98 == NULL )
return - V_10 ;
F_16 ( & ( V_6 -> V_100 ) ) ;
switch ( V_2 ) {
case V_5 :
V_15 = F_7 (
V_101 ,
0 , 0 , NULL , & V_99 ) ;
if ( V_15 ) {
F_3 ( L_28 ) ;
goto V_55;
}
break;
case V_8 :
V_15 = F_5 ( V_26 ,
V_102 , NULL , 0 , & V_99 ,
V_40 ) ;
if ( V_15 ) {
F_3 ( L_29 ) ;
goto V_55;
}
break;
default:
F_3 ( L_27 , V_2 ) ;
V_15 = - V_10 ;
break;
}
F_34 ( V_99 , * V_98 ) ;
V_55:
F_17 ( & ( V_6 -> V_100 ) ) ;
return V_15 ;
}
static int F_35 ( enum V_1 V_2 ,
T_1 V_98 )
{
T_1 V_99 = 0 ;
int V_15 ;
V_98 &= V_103 ;
F_16 ( & ( V_6 -> V_100 ) ) ;
switch ( V_2 ) {
case V_5 :
V_15 = F_7 (
V_101 ,
0 , 0 , NULL , & V_99 ) ;
if ( V_15 ) {
F_3 ( L_28 ) ;
goto V_55;
}
F_36 ( V_99 ) ;
F_37 ( V_99 , V_98 ) ;
V_15 = F_7 (
V_104 ,
0 , 0 , & V_99 , NULL ) ;
if ( V_15 ) {
F_3 ( L_30 ) ;
goto V_55;
}
break;
case V_8 :
V_15 = F_5 ( V_26 ,
V_102 , NULL , 0 , & V_99 ,
V_40 ) ;
if ( V_15 ) {
F_3 ( L_29 ) ;
goto V_55;
}
F_36 ( V_99 ) ;
F_37 ( V_99 , V_98 ) ;
V_15 = F_5 ( V_26 ,
V_105 , ( T_2 * ) & V_99 ,
V_106 , NULL , 0 ) ;
if ( V_15 ) {
F_3 ( L_31 ) ;
goto V_55;
}
break;
default:
F_3 ( L_27 , V_2 ) ;
V_15 = - V_10 ;
break;
}
V_55:
F_17 ( & ( V_6 -> V_100 ) ) ;
return V_15 ;
}
static int F_38 ( struct V_56 * V_57 )
{
struct V_107 * V_108 = NULL , * V_109 = NULL ;
const struct V_110 * V_111 ;
int V_112 , V_15 = - V_66 ;
V_111 = F_39 ( V_113 ) ;
if ( ! V_111 )
return - V_114 ;
V_6 = (struct V_115 * ) V_111 -> V_116 ;
V_108 = F_40 ( V_57 , V_117 , 0 ) ;
if ( ! V_108 ) {
V_15 = - V_10 ;
goto V_55;
}
V_112 = F_41 ( V_108 ) ;
if ( ! F_42 ( & V_57 -> V_62 , V_108 -> V_118 , V_112 ,
V_57 -> V_119 ) ) {
V_15 = - V_54 ;
goto V_55;
}
V_6 -> V_7 . V_120 = V_108 -> V_118 ;
V_6 -> V_7 . V_121 = V_112 ;
V_109 = F_40 ( V_57 , V_117 , 1 ) ;
if ( ! V_109 ) {
V_15 = - V_10 ;
goto V_55;
}
V_112 = F_41 ( V_109 ) ;
if ( ! F_42 ( & V_57 -> V_62 , V_109 -> V_118 , V_112 ,
V_57 -> V_119 ) ) {
V_15 = - V_54 ;
goto V_55;
}
V_6 -> V_9 . V_120 = V_109 -> V_118 ;
V_6 -> V_9 . V_121 = V_112 ;
V_6 -> V_7 . V_83 = F_43 (
V_6 -> V_7 . V_120 ,
V_6 -> V_7 . V_121 ) ;
if ( ! V_6 -> V_7 . V_83 ) {
V_15 = - V_66 ;
goto V_55;
}
V_6 -> V_9 . V_83 = F_43 (
V_6 -> V_9 . V_120 ,
V_6 -> V_9 . V_121 ) ;
if ( ! V_6 -> V_9 . V_83 ) {
V_15 = - V_66 ;
goto V_55;
}
F_44 ( & V_6 -> V_52 ) ;
F_44 ( & V_6 -> V_100 ) ;
V_15 = F_18 ( V_57 ) ;
if ( V_15 )
goto V_55;
V_15 = F_45 ( & V_122 , V_6 ) ;
if ( V_15 ) {
F_19 ( & V_57 -> V_62 , L_32 ) ;
goto V_55;
}
return 0 ;
V_55:
if ( V_108 )
F_46 ( V_108 -> V_118 , F_41 ( V_108 ) ) ;
if ( V_109 )
F_46 ( V_109 -> V_118 , F_41 ( V_109 ) ) ;
if ( V_6 -> V_7 . V_83 )
F_47 ( V_6 -> V_7 . V_83 ) ;
if ( V_6 -> V_9 . V_83 )
F_47 ( V_6 -> V_9 . V_83 ) ;
F_19 ( & V_57 -> V_62 , L_33 ) ;
return V_15 ;
}
static int F_48 ( struct V_56 * V_57 )
{
F_49 () ;
F_47 ( V_6 -> V_7 . V_83 ) ;
F_47 ( V_6 -> V_9 . V_83 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
F_51 ( V_123 L_34 , V_124 ) ;
return F_52 ( & V_125 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_125 ) ;
}
