static void
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 V_3 , V_4 ;
T_4 * V_5 ;
( void ) V_1 ;
F_2 ( V_2 -> V_6 != 0 ) ;
V_3 = F_3 () ;
V_5 = V_2 -> V_6 ;
V_2 -> V_6 = V_5 -> V_7 ;
F_4 ( V_3 ) ;
V_5 -> V_8 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = 0 ;
V_4 = F_3 () ;
F_5 ( V_5 ) ;
F_4 ( V_4 ) ;
}
static void
F_6 ( T_1 * V_1 , T_2 * V_2 )
{
T_5 V_11 = V_12 ;
while ( V_11 == V_11 ) {
T_4 * V_5 = V_2 -> V_6 ;
if ( V_5 == 0 )
break;
if ( F_7 ( V_5 ) !=
V_13 )
break;
F_8 ( V_5 ,
V_14 ) ;
V_11 = F_9 ( V_1 , V_5 -> V_9 ) ;
if ( V_11 == V_12 )
break;
F_8 ( V_5 ,
V_15 ) ;
V_5 -> V_8 ( V_1 , V_2 -> V_16 ,
V_5 -> V_9 , V_5 -> V_10 , V_11 ) ;
F_1 ( V_1 , V_2 ) ;
}
}
T_6
F_10 ( T_1 * V_1 , T_2 * V_2 ,
T_7 * V_17 , T_8 V_18 )
{
T_3 V_19 ;
T_4 * V_5 ;
T_4 * V_20 ;
T_3 V_4 ;
V_19 = F_3 () ;
if ( V_2 -> V_6 != 0 &&
V_2 -> V_6 -> V_9 == V_17 ) {
V_5 = V_2 -> V_6 ;
if ( ( F_7 ( V_5 ) ==
V_14 ) && ( ! V_18 ) ) {
F_4 ( V_19 ) ;
return V_21 ;
}
V_2 -> V_6 = V_5 -> V_7 ;
} else {
V_20 = V_2 -> V_6 ;
while ( V_20 != 0 && V_20 -> V_7 != 0 &&
V_20 -> V_7 -> V_9 != V_17 )
V_20 = V_20 -> V_7 ;
if ( V_20 == 0 || V_20 -> V_7 == 0 ) {
F_4 ( V_19 ) ;
return V_22 ;
}
V_5 = V_20 -> V_7 ;
V_20 -> V_7 = V_5 -> V_7 ;
}
if ( V_5 -> V_8 )
V_5 -> V_8 ( V_1 , V_2 -> V_16 , V_5 -> V_9 ,
V_5 -> V_10 , V_23 ) ;
V_4 = F_3 () ;
F_5 ( V_5 ) ;
F_4 ( V_4 ) ;
F_4 ( V_19 ) ;
return V_24 ;
}
void
F_11 ( T_1 * V_1 , T_2 * V_2 )
{
T_4 * V_25 = V_2 -> V_6 ;
while ( V_25 ) {
if ( F_7 ( V_2 -> V_6 ) !=
V_15 )
F_10 ( V_1 , V_2 ,
V_25 -> V_9 , V_26 ) ;
V_25 = V_25 -> V_7 ;
}
}
static T_8
F_12 ( T_2 * V_2 , T_7 * V_17 )
{
T_3 V_3 ;
T_4 * V_5 ;
V_3 = F_3 () ;
V_5 = V_2 -> V_6 ;
while ( V_5 ) {
if ( V_5 -> V_9 == V_17 ) {
F_4 ( V_3 ) ;
return V_26 ;
}
V_5 = V_5 -> V_7 ;
}
F_4 ( V_3 ) ;
return V_27 ;
}
void
F_13 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_9 V_28 ;
T_10 V_29 [ 4 ] ;
T_11 V_30 ;
for ( V_30 = 3 ; V_30 >= 0 ; V_30 -- )
V_29 [ V_30 ] = F_14 ( V_1 -> V_31 ,
F_15 ( V_32 + V_30 ) ) ;
V_28 = F_16 ( V_29 [ 0 ] ) ;
if ( V_28 >= V_33 ) {
F_17 ( L_1
L_2 , V_28 ) ;
return;
}
V_2 = V_1 -> V_28 [ V_28 ] ;
F_2 ( V_2 -> V_34 * sizeof( T_10 ) +
sizeof( V_29 ) <= sizeof( V_2 -> V_35 ) ) ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ )
V_2 -> V_35 [ V_2 -> V_34 ++ ] = V_29 [ V_30 ] ;
F_2 ( ( V_2 -> V_34 % 4 ) == 0 ) ;
V_1 -> V_36 = V_26 ;
}
void
F_18 ( T_1 * V_1 , T_10 * V_29 )
{
T_2 * V_2 ;
T_9 V_28 ;
T_10 * V_37 ;
T_7 * V_38 ;
T_9 V_39 ;
T_10 V_40 , V_41 ;
V_28 = F_16 ( V_29 [ 0 ] ) ;
if ( V_28 >= V_33 ) {
F_17 ( L_1
L_2 , V_28 ) ;
return;
}
V_2 = V_1 -> V_28 [ V_28 ] ;
if ( F_19 ( V_29 [ 0 ] ) ) {
F_2 ( V_2 -> V_17 != 0 ) ;
V_38 = V_2 -> V_17 ;
V_37 = & V_2 -> V_42 ;
} else {
if ( V_2 -> V_6 == 0 ||
F_7 ( V_2 -> V_6 )
!= V_14 ) {
F_17 ( L_3
L_4 ) ;
F_17 ( L_5 , V_28 ) ;
F_17 ( L_6
L_7 ,
V_29 [ 0 ] , V_29 [ 1 ] , V_29 [ 2 ] , V_29 [ 3 ] ) ;
if ( V_2 -> V_6 != 0 )
F_17 ( L_8 ,
V_2 -> V_6 -> V_4 ) ;
return;
}
F_2 ( V_2 -> V_6 -> V_10 != 0 ) ;
V_38 = V_2 -> V_6 -> V_10 ;
V_37 = & V_2 -> V_6 -> V_43 ;
}
if ( V_38 -> V_44 == 0 ) {
F_20 ( V_38 ,
F_21 ( V_29 [ 0 ] ) ) ;
F_22 ( V_38 , V_28 ) ;
if ( F_23 ( V_29 [ 0 ] ) ) {
* V_37 = V_38 -> V_43 ;
V_39 = 1 ;
} else {
F_2 ( V_38 -> V_43 >= V_29 [ 1 ] ) ;
* V_37 = ( V_29 [ 1 ] < V_38 -> V_43 ) ?
V_29 [ 1 ] : V_38 -> V_43 ;
V_39 = 2 ;
}
} else
V_39 = 1 ;
while ( V_38 -> V_44 < * V_37 && V_39 < 4 )
V_38 -> V_29 [ V_38 -> V_44 ++ ] = V_29 [ V_39 ++ ] ;
if ( F_23 ( V_29 [ 0 ] ) ) {
if ( ( V_2 -> V_45 > 0 ) &&
( V_2 -> V_45 <= V_2 -> V_34 ) ) {
V_41 = 0 ;
V_40 = V_2 -> V_45 ;
while ( V_40 < V_2 -> V_34 )
V_2 -> V_35 [ V_41 ++ ] =
V_2 -> V_35 [ V_40 ++ ] ;
V_2 -> V_45 = 0 ;
V_2 -> V_34 = V_41 ;
F_2 ( ( V_2 -> V_34 % 4 ) == 0 ) ;
}
if ( V_2 -> V_6 != 0 && V_38 ==
V_2 -> V_6 -> V_10 ) {
T_7 * V_46 =
V_2 -> V_6 -> V_10 ;
V_46 -> V_43 = V_2 -> V_6 -> V_43 ;
F_8 ( V_2 -> V_6 ,
V_15 ) ;
F_24 ( V_1 ) ;
V_2 -> V_6 -> V_8 ( V_1 , V_28 ,
V_2 -> V_6 -> V_9 ,
V_46 , V_12 ) ;
F_25 ( V_1 ) ;
F_1 ( V_1 , V_2 ) ;
F_6 ( V_1 , V_2 ) ;
} else {
T_7 * V_47 = V_2 -> V_17 ;
V_2 -> V_17 = 0 ;
if ( V_2 -> V_48 ) {
F_24 ( V_1 ) ;
V_2 -> V_48 ( V_1 , V_28 ,
V_47 , 0 , V_12 ) ;
F_25 ( V_1 ) ;
}
F_26 ( V_47 , 0 ,
V_28 , V_47 -> V_43 ) ;
V_2 -> V_17 = V_47 ;
}
}
}
void
F_27 ( T_1 * V_1 )
{
T_10 V_30 ;
while ( V_1 -> V_36 ) {
V_1 -> V_36 = V_27 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
T_10 V_49 ;
T_2 * V_2 = V_1 -> V_28 [ V_30 ] ;
F_2 ( ( V_2 -> V_34 % 4 ) == 0 ) ;
V_49 = 0 ;
while ( V_49 < V_2 -> V_34 ) {
V_2 -> V_45 = V_49 + 4 ;
F_18 ( V_1 ,
V_2 -> V_35 + V_49 ) ;
V_49 = V_2 -> V_45 ;
}
V_2 -> V_34 = 0 ;
}
}
}
void
F_28 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_50 == V_51 ) ;
F_13 ( V_1 ) ;
F_27 ( V_1 ) ;
}
T_5
F_29 ( T_1 * V_1 )
{
T_10 V_30 ;
if ( F_30 ( V_1 ) )
return V_52 ;
V_1 -> V_53 = V_27 ;
V_1 -> V_54 = V_27 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
V_1 -> V_28 [ V_30 ] = ( T_2 * )
F_31 ( sizeof( T_2 ) ) ;
if ( V_1 -> V_28 [ V_30 ] == 0 )
return V_55 ;
V_1 -> V_28 [ V_30 ] -> V_16 = ( T_9 ) V_30 ;
V_1 -> V_28 [ V_30 ] -> V_48 = 0 ;
V_1 -> V_28 [ V_30 ] -> V_6 = 0 ;
V_1 -> V_28 [ V_30 ] -> V_56 = 0 ;
V_1 -> V_28 [ V_30 ] -> V_17 = F_32 ( V_1 ,
0 , ( T_9 ) V_30 , V_57 [ V_30 ] ) ;
V_1 -> V_28 [ V_30 ] -> V_34 = 0 ;
if ( ! F_33
( & V_1 -> V_28 [ V_30 ] -> V_58 ) )
return V_59 ;
}
F_34 ( V_1 ) ;
return V_12 ;
}
T_5
F_35 ( T_1 * V_1 )
{
T_9 V_30 ;
T_5 V_11 = V_12 ;
T_2 * V_2 ;
T_3 V_3 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
V_2 = V_1 -> V_28 [ V_30 ] ;
if ( ! F_36 ( & V_2 -> V_58 ) )
return V_60 ;
while ( V_2 -> V_6 ) {
T_3 V_4 ;
T_4 * V_5 =
V_2 -> V_6 ;
F_8 ( V_5 ,
V_61 ) ;
V_5 -> V_8 ( V_1 , V_30 , V_5 -> V_9 ,
V_5 -> V_10 , V_23 ) ;
V_3 = F_3 () ;
V_2 -> V_6 = V_5 -> V_7 ;
F_4 ( V_3 ) ;
V_4 = F_3 () ;
F_5 ( V_5 ) ;
F_4 ( V_4 ) ;
}
F_37 ( V_1 , V_1 -> V_28 [ V_30 ] -> V_17 ) ;
F_38 ( V_1 -> V_28 [ V_30 ] ) ;
V_1 -> V_28 [ V_30 ] = 0 ;
}
F_39 ( V_1 ) ;
return V_11 ;
}
void
F_26 ( T_7 * V_17 ,
T_10 V_62 , T_10 V_28 , T_10 V_43 )
{
T_10 V_63 = sizeof( T_7 ) +
( V_43 - 1 ) * sizeof( T_10 ) ;
F_40 ( V_17 , 0 , V_63 ) ;
V_17 -> V_43 = V_43 ;
F_20 ( V_17 , V_62 ) ;
F_22 ( V_17 , V_28 ) ;
F_41 ( V_17 ) ;
}
T_7 *
F_32 ( T_1 * V_1 , T_10 V_62 ,
T_9 V_28 , T_10 V_43 )
{
T_7 * V_17 ;
T_3 V_4 ;
T_10 V_63 = sizeof( T_7 ) +
( V_43 - 1 ) * sizeof( T_10 ) ;
( void ) V_1 ;
V_4 = F_3 () ;
V_17 = F_42 ( V_63 ) ;
F_4 ( V_4 ) ;
if ( V_17 )
F_26 ( V_17 , V_62 , V_28 , V_43 ) ;
return V_17 ;
}
void
F_37 ( T_1 * V_1 , T_7 * V_17 )
{
T_3 V_4 ;
( void ) V_1 ;
( void ) V_17 ;
V_4 = F_3 () ;
F_5 ( V_17 ) ;
F_4 ( V_4 ) ;
}
void
F_43 ( T_7 * V_17 , T_10 V_43 )
{
T_10 V_63 = sizeof( T_7 ) +
( V_43 - 1 ) * sizeof( T_10 ) ;
F_40 ( V_17 , 0 , V_63 ) ;
V_17 -> V_43 = V_43 ;
F_44 ( V_17 ) ;
}
T_7 *
F_45 ( T_1 * V_1 , T_10 V_43 )
{
T_7 * V_17 ;
T_3 V_4 ;
T_10 V_63 = sizeof( T_7 ) +
( V_43 - 1 ) * sizeof( T_10 ) ;
( void ) V_1 ;
V_4 = F_3 () ;
V_17 = F_42 ( V_63 ) ;
F_4 ( V_4 ) ;
if ( V_17 )
F_43 ( V_17 , V_43 ) ;
return V_17 ;
}
void
F_46 ( T_1 * V_1 , T_7 * V_17 )
{
T_3 V_4 ;
( void ) V_1 ;
( void ) V_17 ;
V_4 = F_3 () ;
F_5 ( V_17 ) ;
F_4 ( V_4 ) ;
}
static T_10
F_47 (
T_1 * V_1 )
{
T_3 V_3 ;
T_8 V_64 = V_26 ;
T_10 V_65 = 0 , V_66 = 0xffff ;
while ( V_66 == V_66 ) {
V_3 = F_3 () ;
V_65 = F_14 ( V_1 -> V_31 , V_67 ) ;
if ( ( V_65 & V_68 ) == 0 ) {
F_4 ( V_3 ) ;
break;
}
F_13 ( V_1 ) ;
F_4 ( V_3 ) ;
}
V_66 = F_14 ( V_1 -> V_31 ,
V_69 ) & V_70 ;
while ( V_64 ) {
V_65 = F_14 ( V_1 -> V_31 ,
V_69 ) & V_70 ;
if ( V_65 == V_66 )
break;
V_66 = V_65 ;
}
return V_65 ;
}
static T_5
F_9 (
T_1 * V_1 ,
T_7 * V_17 )
{
int V_30 ;
T_10 V_71 , V_65 ;
T_11 V_72 ;
T_3 V_73 ;
#ifdef F_48
if ( F_49 ( V_17 ) ) {
switch ( F_50 ( V_17 ) ) {
case V_74 :
F_2 ( V_17 -> V_43 * 2 + 2 <
V_75 ) ;
break;
case V_76 :
F_2 ( V_17 -> V_43 * 2 + 2 <
V_77 ) ;
break;
case V_78 :
F_2 ( V_17 -> V_43 * 2 + 2 <
V_79 ) ;
break;
case V_80 :
F_2 ( V_17 -> V_43 * 2 + 2 <
V_81 ) ;
break;
}
}
#endif
if ( V_17 -> V_43 > 3 ) {
T_10 V_43 = V_17 -> V_43 ;
int V_82 = 0 ;
int V_39 = 1 ;
V_1 -> V_53 = V_26 ;
while ( V_82 < V_43 ) {
V_72 = V_83 ;
do {
V_65 = F_47 ( V_1 ) ;
} while ( V_65 && V_72 -- > 0 );
if ( V_65 ) {
F_17 (
L_9
L_10 ,
F_14 ( V_1 -> V_31 ,
V_84 ) ,
F_14 ( V_1 -> V_31 ,
V_85 ) ,
F_14 ( V_1 -> V_31 ,
V_86 ) ,
F_14 ( V_1 -> V_31 ,
V_87 ) ) ;
return V_88 ;
}
if ( V_1 -> V_54 ) {
V_1 -> V_53 = V_27 ;
V_1 -> V_54 = V_27 ;
return V_23 ;
}
V_73 = F_3 () ;
V_65 = F_14 ( V_1 -> V_31 ,
V_69 ) &
V_70 ;
if ( V_65 ) {
F_4 ( V_73 ) ;
continue;
}
if ( V_82 == 0 ) {
F_51 ( V_1 -> V_31 ,
V_85 , V_43 ) ;
V_39 = 2 ;
} else {
V_39 = 1 ;
}
while ( ( V_82 < V_43 ) && ( V_39 < 4 ) ) {
F_51 ( V_1 -> V_31 ,
F_15
( V_84 + V_39 ) ,
V_17 -> V_29 [ V_82 ++ ] ) ;
V_39 ++ ;
}
V_71 = V_17 -> V_89 ;
if ( V_82 == V_43 ) {
V_1 -> V_53 = V_27 ;
V_71 |= V_90 ;
}
if ( V_1 -> V_54 ) {
V_1 -> V_53 = V_27 ;
V_1 -> V_54 = V_27 ;
F_4 ( V_73 ) ;
return V_23 ;
}
F_51 ( V_1 -> V_31 ,
V_84 , V_71 ) ;
F_52 () ;
F_4 ( V_73 ) ;
}
} else {
V_91:
V_72 = V_83 ;
do {
V_65 = F_47 ( V_1 ) ;
} while ( V_65 && V_72 -- > 0 );
if ( V_65 ) {
F_17 (
L_11 ,
F_14 ( V_1 -> V_31 ,
V_84 ) ,
F_14 ( V_1 -> V_31 ,
V_85 ) ,
F_14 ( V_1 -> V_31 ,
V_86 ) ,
F_14 ( V_1 -> V_31 ,
V_87 ) ) ;
return V_88 ;
}
V_73 = F_3 () ;
V_65 = F_14 ( V_1 -> V_31 , V_69 ) &
V_70 ;
if ( V_65 ) {
F_4 ( V_73 ) ;
goto V_91;
}
V_65 = 0 ;
for ( V_30 = V_17 -> V_43 - 1 ; V_30 >= 0 ; V_30 -- )
F_51 ( V_1 -> V_31 ,
F_15 ( V_85 + V_30 ) ,
V_17 -> V_29 [ V_30 ] ) ;
F_51 ( V_1 -> V_31 , V_84 ,
V_17 -> V_89 | V_90 ) ;
F_52 () ;
F_4 ( V_73 ) ;
}
return V_12 ;
}
extern T_5
F_53 (
T_1 * V_1 ,
T_7 * V_92 ,
T_7 * V_10 ,
T_8 V_93 ,
T_12 V_94
)
{
T_2 * V_2 ;
T_10 V_89 = V_92 -> V_89 ;
T_9 V_28 ;
T_5 V_11 = V_12 ;
T_4 * V_5 ;
T_3 V_3 , V_4 ;
F_2 ( V_1 -> V_50 == V_51 ) ;
V_28 = F_16 ( V_89 ) ;
F_2 ( V_28 < V_33 ) ;
V_2 = V_1 -> V_28 [ V_28 ] ;
V_4 = F_3 () ;
V_5 = F_42 ( sizeof( T_4 ) ) ;
F_4 ( V_4 ) ;
if ( V_5 == 0 )
return V_55 ;
V_5 -> V_8 = V_94 ;
V_5 -> V_43 = 0 ;
V_5 -> V_7 = 0 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_9 = V_92 ;
V_5 -> V_4 = V_13 ;
if ( V_93 )
F_54 ( V_5 ) ;
V_3 = F_3 () ;
if ( V_2 -> V_6 == 0 ) {
V_2 -> V_6 = V_5 ;
V_2 -> V_56 = V_5 ;
} else {
V_2 -> V_56 -> V_7 = V_5 ;
V_2 -> V_56 = V_5 ;
}
F_4 ( V_3 ) ;
F_6 ( V_1 , V_2 ) ;
if ( ! F_55 ( V_1 ) ) {
V_3 = F_3 () ;
F_27 ( V_1 ) ;
F_4 ( V_3 ) ;
}
return V_11 ;
}
static void
F_56 (
T_1 * V_1 ,
T_9 V_28 ,
T_7 * V_9 ,
T_7 * V_10 ,
T_5 V_11 )
{
( void ) V_9 ;
( void ) V_10 ;
( void ) V_11 ;
F_2 ( V_1 -> V_50 == V_51 ) ;
V_1 -> V_95 = V_11 ;
F_57 ( & V_1 -> V_28 [ V_28 ] -> V_58 ) ;
}
T_5
F_58 (
T_1 * V_1 ,
T_7 * V_92 ,
T_7 * V_10
)
{
T_5 V_11 ;
T_9 V_28 ;
T_3 V_72 = 800 ;
T_2 * V_2 ;
V_28 = F_50 ( V_92 ) ;
F_2 ( V_28 < V_33 ) ;
V_2 = V_1 -> V_28 [ V_28 ] ;
V_11 = F_53 ( V_1 , V_92 , V_10 ,
V_26 , F_56 ) ;
if ( V_11 != V_12 )
return V_11 ;
while ( V_72 -- > 0 ) {
F_59 ( & V_2 -> V_58 , 10 ) ;
if ( ! F_12 ( V_2 , V_92 ) )
return V_1 -> V_95 ;
}
F_10 ( V_1 , V_2 , V_92 , V_26 ) ;
return V_88 ;
}
T_5
F_60 (
T_1 * V_1 ,
T_9 V_28 ,
T_12 V_94 )
{
T_2 * V_2 ;
F_2 ( V_28 < V_33 ) ;
V_2 = V_1 -> V_28 [ V_28 ] ;
V_2 -> V_48 = V_94 ;
return V_12 ;
}
void
F_61 (
T_7 * V_17 ,
T_3 V_49 ,
T_3 V_43 ,
void * V_96 )
{
T_10 V_97 ;
T_9 * V_98 = ( T_9 * ) V_96 ;
while ( V_43 > 1 ) {
V_97 = ( ( * V_98 ++ ) << 8 ) ;
V_97 |= ( * V_98 ++ ) ;
F_62 ( V_17 , V_49 , V_97 ) ;
V_49 ++ ;
V_43 -= 2 ;
}
if ( V_43 == 1 ) {
V_97 = ( * V_98 << 8 ) ;
F_62 ( V_17 , V_49 , V_97 ) ;
}
}
void
F_63 (
T_7 * V_17 ,
T_3 V_49 ,
T_3 V_43 ,
void * V_96 )
{
T_9 * V_98 = ( T_9 * ) V_96 ;
while ( V_43 -- > 0 ) {
T_10 V_99 = F_64
( V_17 , V_49 ++ ) ;
* V_98 ++ = ( T_9 ) ( ( V_99 >> 8 ) & 0xff ) ;
if ( V_43 ) {
V_43 -- ;
* V_98 ++ = ( T_9 ) ( V_99 & 0xff ) ;
}
}
}
extern T_5
F_65 (
T_1 * V_1 ,
T_9 V_28 ,
T_10 V_62 ,
T_9 V_100 )
{
T_5 V_11 ;
T_7 V_10 ;
T_7 * V_46 = & V_10 ;
F_40 ( V_46 , 0 , sizeof( V_10 ) ) ;
V_46 -> V_43 = 1 ;
F_44 ( V_46 ) ;
F_22 ( V_46 , V_28 ) ;
if ( V_100 )
F_66 ( V_46 ) ;
F_20 ( V_46 , V_101 ) ;
F_62 ( V_46 , 0 , V_62 ) ;
V_11 = F_9 ( V_1 , V_46 ) ;
return V_11 ;
}
extern T_5
F_67 (
T_1 * V_1 ,
T_9 V_28 ,
T_10 V_62 ,
T_10 V_43 ,
void * V_29 )
{
T_7 * V_46 ;
T_10 V_102 ;
T_9 V_103 [ 256 ] ;
if ( V_43 > 192 )
return V_104 ;
V_102 = V_43 / 2 ;
if ( V_43 % 2 )
V_102 ++ ;
V_102 ++ ;
V_46 = ( T_7 * ) V_103 ;
F_40 ( V_46 , 0 , sizeof( V_103 ) ) ;
V_46 -> V_43 = V_102 ;
F_22 ( V_46 , V_28 ) ;
F_20 ( V_46 , V_62 ) ;
F_62 ( V_46 , 0 , V_43 ) ;
F_61 ( V_46 , 1 , V_43 , V_29 ) ;
return F_9 ( V_1 , V_46 ) ;
}
static T_8
F_68 ( T_7 * V_105 ,
T_13 V_106 )
{
T_10 V_65 ;
T_9 type = F_69 ( V_105 ) ;
if ( F_50 ( V_105 ) !=
V_80 )
return V_27 ;
if ( ( V_106 == 0 ) && ( type == V_107 ) )
return V_26 ;
if ( type != V_108 )
return V_27 ;
V_65 = F_64 ( V_105 , 0 ) ;
if ( ( T_13 ) ( ( V_65 >> 13 ) & 1 ) != V_106 )
return V_27 ;
return V_26 ;
}
T_5
F_70 ( T_1 * V_1 ,
T_13 V_106 )
{
T_2 * V_2 ;
T_4 * V_5 ;
T_3 V_19 ;
V_2 = V_1 -> V_28 [ V_80 ] ;
if ( V_2 ) {
for ( V_5 = V_2 -> V_6 ; V_5 ;
V_5 = V_5 -> V_7 ) {
if ( F_68
( V_5 -> V_9 , V_106 ) ) {
F_10 ( V_1 , V_2 ,
V_5 -> V_9 , V_27 ) ;
break;
}
}
V_19 = F_3 () ;
if ( V_2 -> V_6 != 0 &&
F_68
( V_2 -> V_6 -> V_9 , V_106 ) &&
F_7 ( V_2 -> V_6 ) ==
V_14 ) {
F_17 ( L_12
L_13 ) ;
if ( V_1 -> V_53 )
V_1 -> V_54 = V_26 ;
else {
T_3 V_4 ;
V_5 = V_2 -> V_6 ;
if ( V_5 -> V_8 )
V_5 -> V_8 ( V_1 , V_2 -> V_16 ,
V_5 -> V_9 , V_5 -> V_10 ,
V_23 ) ;
V_2 -> V_6 = V_5 -> V_7 ;
V_4 = F_3 () ;
F_5 ( V_5 ) ;
F_4 ( V_4 ) ;
}
}
F_4 ( V_19 ) ;
}
return V_12 ;
}
