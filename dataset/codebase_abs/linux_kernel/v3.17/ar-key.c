static int F_1 ( const char * V_1 )
{
unsigned long V_2 ;
char * V_3 ;
V_2 = F_2 ( V_1 , & V_3 , 10 ) ;
if ( * V_3 != ':' || V_2 > 65535 )
return - V_4 ;
V_2 = F_2 ( V_3 + 1 , & V_3 , 10 ) ;
if ( * V_3 || V_2 < 1 || V_2 > 255 )
return - V_4 ;
return 0 ;
}
static int F_3 ( struct V_5 * V_6 ,
T_1 V_7 ,
const T_2 * V_8 , unsigned int V_9 )
{
struct V_10 * V_11 , * * V_12 ;
T_1 V_13 ;
T_3 V_14 ;
F_4 ( L_1 ,
F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , F_5 ( V_8 [ 2 ] ) , F_5 ( V_8 [ 3 ] ) ,
V_9 ) ;
if ( V_9 <= 8 * 4 )
return - V_15 ;
V_14 = F_5 ( V_8 [ 7 ] ) ;
F_6 ( L_2 , V_14 ) ;
if ( V_14 > V_16 )
return - V_15 ;
if ( V_9 < 8 * 4 + V_14 )
return - V_15 ;
V_13 = sizeof( * V_11 ) + sizeof( * V_11 -> V_17 ) + V_14 ;
V_6 -> V_18 = V_7 + V_13 ;
V_13 -= sizeof( * V_11 ) ;
V_11 = F_7 ( sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 )
return - V_20 ;
V_11 -> V_17 = F_7 ( V_13 , V_19 ) ;
if ( ! V_11 -> V_17 ) {
F_8 ( V_11 ) ;
return - V_20 ;
}
V_11 -> V_21 = V_22 ;
V_11 -> V_17 -> V_23 = V_14 ;
V_11 -> V_17 -> V_24 = F_5 ( V_8 [ 0 ] ) ;
V_11 -> V_17 -> V_25 = F_5 ( V_8 [ 1 ] ) ;
V_11 -> V_17 -> V_26 = F_5 ( V_8 [ 4 ] ) ;
V_11 -> V_17 -> V_27 = F_5 ( V_8 [ 5 ] ) ;
V_11 -> V_17 -> V_28 = F_5 ( V_8 [ 6 ] ) ;
memcpy ( & V_11 -> V_17 -> V_29 , & V_8 [ 2 ] , 8 ) ;
memcpy ( & V_11 -> V_17 -> V_30 , & V_8 [ 8 ] , V_14 ) ;
F_6 ( L_3 , V_11 -> V_21 ) ;
F_6 ( L_4 , V_11 -> V_17 -> V_23 ) ;
F_6 ( L_5 , V_11 -> V_17 -> V_27 ) ;
F_6 ( L_6 , V_11 -> V_17 -> V_25 ) ;
F_6 ( L_7 , V_11 -> V_17 -> V_28 ) ;
F_6 ( L_8 ,
V_11 -> V_17 -> V_29 [ 0 ] , V_11 -> V_17 -> V_29 [ 1 ] ,
V_11 -> V_17 -> V_29 [ 2 ] , V_11 -> V_17 -> V_29 [ 3 ] ,
V_11 -> V_17 -> V_29 [ 4 ] , V_11 -> V_17 -> V_29 [ 5 ] ,
V_11 -> V_17 -> V_29 [ 6 ] , V_11 -> V_17 -> V_29 [ 7 ] ) ;
if ( V_11 -> V_17 -> V_23 >= 8 )
F_6 ( L_9 ,
V_11 -> V_17 -> V_30 [ 0 ] , V_11 -> V_17 -> V_30 [ 1 ] ,
V_11 -> V_17 -> V_30 [ 2 ] , V_11 -> V_17 -> V_30 [ 3 ] ,
V_11 -> V_17 -> V_30 [ 4 ] , V_11 -> V_17 -> V_30 [ 5 ] ,
V_11 -> V_17 -> V_30 [ 6 ] , V_11 -> V_17 -> V_30 [ 7 ] ) ;
V_6 -> V_31 [ 0 ] = ( void * ) ( ( unsigned long ) V_6 -> V_31 [ 0 ] + 1 ) ;
for ( V_12 = (struct V_10 * * ) & V_6 -> V_32 [ 0 ] ;
* V_12 ;
V_12 = & ( * V_12 ) -> V_33 )
continue;
* V_12 = V_11 ;
if ( V_11 -> V_17 -> V_27 < V_6 -> V_27 )
V_6 -> V_27 = V_11 -> V_17 -> V_27 ;
F_9 ( L_10 ) ;
return 0 ;
}
static void F_10 ( struct V_34 * V_35 )
{
int V_36 ;
if ( V_35 -> V_37 ) {
for ( V_36 = V_35 -> V_38 - 1 ; V_36 >= 0 ; V_36 -- )
F_8 ( V_35 -> V_37 [ V_36 ] ) ;
F_8 ( V_35 -> V_37 ) ;
}
F_8 ( V_35 -> V_39 ) ;
}
static void F_11 ( struct V_40 * V_41 )
{
F_8 ( V_41 -> V_42 ) ;
}
static void F_12 ( struct V_43 * V_44 )
{
int V_36 ;
F_10 ( & V_44 -> V_45 ) ;
F_10 ( & V_44 -> V_46 ) ;
F_11 ( & V_44 -> V_47 ) ;
if ( V_44 -> V_48 ) {
for ( V_36 = V_44 -> V_49 - 1 ; V_36 >= 0 ; V_36 -- )
F_11 ( & V_44 -> V_48 [ V_36 ] ) ;
F_8 ( V_44 -> V_48 ) ;
}
if ( V_44 -> V_50 ) {
for ( V_36 = V_44 -> V_51 - 1 ; V_36 >= 0 ; V_36 -- )
F_11 ( & V_44 -> V_50 [ V_36 ] ) ;
F_8 ( V_44 -> V_50 ) ;
}
F_8 ( V_44 -> V_30 ) ;
F_8 ( V_44 -> V_52 ) ;
F_8 ( V_44 ) ;
}
static int F_13 ( struct V_34 * V_35 ,
const T_2 * * V_53 ,
unsigned int * V_54 )
{
const T_2 * V_8 = * V_53 ;
unsigned int V_9 = * V_54 , V_55 , V_36 , V_56 ;
if ( V_9 <= 12 )
return - V_4 ;
F_4 ( L_11 ,
F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , F_5 ( V_8 [ 2 ] ) , V_9 ) ;
V_55 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_55 <= 0 || V_55 > V_57 )
return - V_4 ;
V_35 -> V_38 = V_55 ;
if ( V_9 <= ( V_55 + 1 ) * 4 )
return - V_4 ;
V_35 -> V_37 = F_14 ( V_55 , sizeof( char * ) , V_19 ) ;
if ( ! V_35 -> V_37 )
return - V_20 ;
for ( V_36 = 0 ; V_36 < V_55 ; V_36 ++ ) {
if ( V_9 < 4 )
return - V_4 ;
V_56 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_56 <= 0 || V_56 > V_58 )
return - V_4 ;
if ( V_56 > V_9 )
return - V_4 ;
V_35 -> V_37 [ V_36 ] = F_15 ( V_56 + 1 , V_19 ) ;
if ( ! V_35 -> V_37 [ V_36 ] )
return - V_20 ;
memcpy ( V_35 -> V_37 [ V_36 ] , V_8 , V_56 ) ;
V_35 -> V_37 [ V_36 ] [ V_56 ] = 0 ;
V_56 = ( V_56 + 3 ) & ~ 3 ;
V_9 -= V_56 ;
V_8 += V_56 >> 2 ;
}
if ( V_9 < 4 )
return - V_4 ;
V_56 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_56 <= 0 || V_56 > V_59 )
return - V_4 ;
if ( V_56 > V_9 )
return - V_4 ;
V_35 -> V_39 = F_15 ( V_56 + 1 , V_19 ) ;
if ( ! V_35 -> V_39 )
return - V_20 ;
memcpy ( V_35 -> V_39 , V_8 , V_56 ) ;
V_35 -> V_39 [ V_56 ] = 0 ;
V_56 = ( V_56 + 3 ) & ~ 3 ;
V_9 -= V_56 ;
V_8 += V_56 >> 2 ;
F_6 ( L_12 , V_35 -> V_37 [ 0 ] , V_35 -> V_39 ) ;
* V_53 = V_8 ;
* V_54 = V_9 ;
F_9 ( L_13 , V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_40 * V_41 ,
T_1 V_60 ,
const T_2 * * V_53 ,
unsigned int * V_54 )
{
const T_2 * V_8 = * V_53 ;
unsigned int V_9 = * V_54 , V_61 ;
if ( V_9 <= 8 )
return - V_4 ;
F_4 ( L_14 ,
V_60 , F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , V_9 ) ;
V_41 -> V_62 = F_5 ( * V_8 ++ ) ;
V_61 = F_5 ( * V_8 ++ ) ;
V_9 -= 8 ;
if ( V_61 > V_60 )
return - V_4 ;
V_41 -> V_63 = V_61 ;
if ( V_61 > 0 ) {
V_41 -> V_42 = F_17 ( V_8 , V_61 , V_19 ) ;
if ( ! V_41 -> V_42 )
return - V_20 ;
V_61 = ( V_61 + 3 ) & ~ 3 ;
V_9 -= V_61 ;
V_8 += V_61 >> 2 ;
}
F_6 ( L_15 , V_41 -> V_62 , V_41 -> V_63 ) ;
* V_53 = V_8 ;
* V_54 = V_9 ;
F_9 ( L_13 , V_9 ) ;
return 0 ;
}
static int F_18 ( struct V_40 * * V_64 ,
T_4 * V_65 ,
T_4 V_66 ,
T_1 V_67 ,
const T_2 * * V_53 ,
unsigned int * V_54 )
{
struct V_40 * V_41 ;
const T_2 * V_8 = * V_53 ;
unsigned int V_9 = * V_54 , V_68 , V_36 ;
int V_69 ;
if ( V_9 < 4 )
return - V_4 ;
F_4 ( L_16 ,
V_66 , V_67 , F_5 ( V_8 [ 0 ] ) , V_9 ) ;
V_68 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_68 > V_66 )
return - V_4 ;
* V_65 = V_68 ;
if ( V_68 > 0 ) {
if ( V_9 <= ( V_68 + 1 ) * 4 )
return - V_4 ;
F_6 ( L_17 , V_68 ) ;
V_41 = F_14 ( V_68 , sizeof( struct V_40 ) ,
V_19 ) ;
if ( ! V_41 )
return - V_20 ;
* V_64 = V_41 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
V_69 = F_16 ( & V_41 [ V_36 ] ,
V_67 ,
& V_8 , & V_9 ) ;
if ( V_69 < 0 )
return V_69 ;
}
}
* V_53 = V_8 ;
* V_54 = V_9 ;
F_9 ( L_13 , V_9 ) ;
return 0 ;
}
static int F_19 ( T_4 * * V_70 , T_5 * V_71 ,
const T_2 * * V_53 , unsigned int * V_54 )
{
const T_2 * V_8 = * V_53 ;
unsigned int V_9 = * V_54 , V_61 ;
if ( V_9 <= 4 )
return - V_4 ;
F_4 ( L_18 , F_5 ( V_8 [ 0 ] ) , V_9 ) ;
V_61 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_61 > V_72 )
return - V_4 ;
* V_71 = V_61 ;
F_6 ( L_19 , V_61 ) ;
if ( V_61 > 0 ) {
* V_70 = F_17 ( V_8 , V_61 , V_19 ) ;
if ( ! * V_70 )
return - V_20 ;
V_61 = ( V_61 + 3 ) & ~ 3 ;
V_9 -= V_61 ;
V_8 += V_61 >> 2 ;
}
* V_53 = V_8 ;
* V_54 = V_9 ;
F_9 ( L_13 , V_9 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
T_1 V_7 ,
const T_2 * V_8 , unsigned int V_9 )
{
struct V_10 * V_11 , * * V_12 ;
struct V_43 * V_44 ;
const T_2 * V_73 = V_8 + ( V_9 >> 2 ) ;
int V_69 ;
F_4 ( L_1 ,
F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , F_5 ( V_8 [ 2 ] ) , F_5 ( V_8 [ 3 ] ) ,
V_9 ) ;
V_6 -> V_18 = V_7 + V_9 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 )
return - V_20 ;
V_44 = F_7 ( sizeof( * V_44 ) , V_19 ) ;
if ( ! V_44 ) {
F_8 ( V_11 ) ;
return - V_20 ;
}
V_11 -> V_21 = V_74 ;
V_11 -> V_75 = V_44 ;
V_69 = F_13 ( & V_44 -> V_45 , & V_8 , & V_9 ) ;
if ( V_69 < 0 )
goto error;
V_69 = F_13 ( & V_44 -> V_46 , & V_8 , & V_9 ) ;
if ( V_69 < 0 )
goto error;
V_69 = F_16 ( & V_44 -> V_47 , V_76 ,
& V_8 , & V_9 ) ;
if ( V_69 < 0 )
goto error;
if ( V_9 < 4 * 8 + 2 * 4 )
goto V_77;
V_44 -> V_78 = F_21 ( ( const V_79 * ) V_8 ) ;
V_8 += 2 ;
V_44 -> V_80 = F_21 ( ( const V_79 * ) V_8 ) ;
V_8 += 2 ;
V_44 -> V_81 = F_21 ( ( const V_79 * ) V_8 ) ;
V_8 += 2 ;
V_44 -> V_82 = F_21 ( ( const V_79 * ) V_8 ) ;
V_8 += 2 ;
V_44 -> V_83 = F_5 ( * V_8 ++ ) ;
V_44 -> V_84 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 * 8 + 2 * 4 ;
F_6 ( L_20 ,
V_44 -> V_78 , V_44 -> V_80 , V_44 -> V_81 ,
V_44 -> V_82 ) ;
F_6 ( L_21 , V_44 -> V_83 , V_44 -> V_84 ) ;
V_69 = F_18 ( & V_44 -> V_48 ,
& V_44 -> V_49 ,
V_85 ,
V_76 ,
& V_8 , & V_9 ) ;
if ( V_69 < 0 )
goto error;
F_22 ( ( V_73 - V_8 ) << 2 , == , V_9 ) ;
V_69 = F_19 ( & V_44 -> V_30 , & V_44 -> V_23 ,
& V_8 , & V_9 ) ;
if ( V_69 < 0 )
goto error;
V_69 = F_19 ( & V_44 -> V_52 , & V_44 -> V_86 ,
& V_8 , & V_9 ) ;
if ( V_69 < 0 )
goto error;
F_22 ( ( V_73 - V_8 ) << 2 , == , V_9 ) ;
V_69 = F_18 ( & V_44 -> V_50 ,
& V_44 -> V_51 ,
V_87 ,
V_88 ,
& V_8 , & V_9 ) ;
if ( V_69 < 0 )
goto error;
F_22 ( ( V_73 - V_8 ) << 2 , == , V_9 ) ;
if ( V_9 != 0 )
goto V_77;
for ( V_12 = (struct V_10 * * ) & V_6 -> V_32 [ 0 ] ;
* V_12 ;
V_12 = & ( * V_12 ) -> V_33 )
continue;
* V_12 = V_11 ;
if ( V_11 -> V_17 -> V_27 < V_6 -> V_27 )
V_6 -> V_27 = V_11 -> V_17 -> V_27 ;
F_9 ( L_10 ) ;
return 0 ;
V_77:
V_69 = - V_4 ;
error:
F_12 ( V_44 ) ;
F_8 ( V_11 ) ;
F_9 ( L_22 , V_69 ) ;
return V_69 ;
}
static int F_23 ( struct V_5 * V_6 )
{
const T_2 * V_8 = V_6 -> V_42 , * V_11 ;
const char * V_89 ;
unsigned int V_61 , V_56 , V_36 , V_90 , V_9 , V_91 ;
T_1 V_7 = V_6 -> V_7 ;
int V_69 ;
F_4 ( L_23 ,
F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , F_5 ( V_8 [ 2 ] ) , F_5 ( V_8 [ 3 ] ) ,
V_6 -> V_7 ) ;
if ( V_7 > V_92 )
goto V_93;
if ( V_7 & 3 )
goto V_93;
if ( F_5 ( * V_8 ++ ) != 0 )
goto V_93;
V_7 -= 4 ;
V_61 = F_5 ( * V_8 ++ ) ;
if ( V_61 < 1 || V_61 > V_94 )
goto V_93;
V_7 -= 4 ;
V_56 = ( V_61 + 3 ) & ~ 3 ;
if ( V_56 > V_7 )
goto V_93;
V_89 = ( const char * ) V_8 ;
for ( V_36 = 0 ; V_36 < V_61 ; V_36 ++ )
if ( ! isprint ( V_89 [ V_36 ] ) )
goto V_93;
if ( V_61 < V_56 )
for (; V_36 < V_56 ; V_36 ++ )
if ( V_89 [ V_36 ] )
goto V_93;
F_6 ( L_24 ,
V_61 , V_56 , V_61 , V_61 , ( const char * ) V_8 ) ;
V_7 -= V_56 ;
V_8 += V_56 >> 2 ;
if ( V_7 < 12 )
goto V_93;
V_90 = F_5 ( * V_8 ++ ) ;
V_7 -= 4 ;
F_6 ( L_25 , V_90 ) ;
if ( V_90 < 1 || V_90 > V_95 )
goto V_93;
V_11 = V_8 ;
V_36 = V_90 ;
do {
if ( V_7 < 8 )
goto V_93;
V_9 = F_5 ( * V_8 ++ ) ;
V_91 = F_5 ( * V_8 ) ;
V_7 -= 4 ;
F_6 ( L_26 , V_9 , V_7 , V_91 ) ;
if ( V_9 < 20 || V_9 > V_7 )
goto V_93;
V_7 -= ( V_9 + 3 ) & ~ 3 ;
V_8 += ( V_9 + 3 ) >> 2 ;
} while ( -- V_36 > 0 );
F_6 ( L_27 , V_7 ) ;
if ( V_7 != 0 )
goto V_93;
do {
V_8 = V_11 ;
V_9 = F_5 ( * V_8 ++ ) ;
V_11 = V_8 + ( ( V_9 + 3 ) >> 2 ) ;
V_91 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
F_6 ( L_28 , V_91 , V_8 , V_11 ) ;
switch ( V_91 ) {
case V_22 :
V_69 = F_3 ( V_6 , V_7 , V_8 , V_9 ) ;
if ( V_69 != 0 )
goto error;
break;
case V_74 :
V_69 = F_20 ( V_6 , V_7 , V_8 , V_9 ) ;
if ( V_69 != 0 )
goto error;
break;
default:
V_69 = - V_96 ;
goto error;
}
} while ( -- V_90 > 0 );
F_9 ( L_10 ) ;
return 0 ;
V_93:
F_9 ( L_29 ) ;
return - V_97 ;
error:
F_9 ( L_22 , V_69 ) ;
return V_69 ;
}
static int F_24 ( struct V_5 * V_6 )
{
const struct V_98 * V_99 ;
struct V_10 * V_11 , * * V_100 ;
T_1 V_13 ;
T_3 V_101 ;
int V_69 ;
F_4 ( L_30 , V_6 -> V_7 ) ;
if ( ! V_6 -> V_42 && V_6 -> V_7 == 0 )
return 0 ;
if ( V_6 -> V_7 > 7 * 4 ) {
V_69 = F_23 ( V_6 ) ;
if ( V_69 != - V_97 )
return V_69 ;
}
V_69 = - V_4 ;
if ( V_6 -> V_7 <= 4 || ! V_6 -> V_42 )
goto error;
memcpy ( & V_101 , V_6 -> V_42 , sizeof( V_101 ) ) ;
V_6 -> V_42 += sizeof( V_101 ) ;
V_6 -> V_7 -= sizeof( V_101 ) ;
F_6 ( L_31 , V_101 ) ;
V_69 = - V_15 ;
if ( V_101 != 1 )
goto error;
V_69 = - V_4 ;
if ( V_6 -> V_7 < sizeof( * V_99 ) )
goto error;
V_99 = V_6 -> V_42 ;
if ( V_6 -> V_7 != sizeof( * V_99 ) + V_99 -> V_102 )
goto error;
F_6 ( L_3 , V_99 -> V_21 ) ;
F_6 ( L_4 , V_99 -> V_102 ) ;
F_6 ( L_5 , V_99 -> V_27 ) ;
F_6 ( L_6 , V_99 -> V_25 ) ;
F_6 ( L_8 ,
V_99 -> V_29 [ 0 ] , V_99 -> V_29 [ 1 ] ,
V_99 -> V_29 [ 2 ] , V_99 -> V_29 [ 3 ] ,
V_99 -> V_29 [ 4 ] , V_99 -> V_29 [ 5 ] ,
V_99 -> V_29 [ 6 ] , V_99 -> V_29 [ 7 ] ) ;
if ( V_99 -> V_102 >= 8 )
F_6 ( L_9 ,
V_99 -> V_30 [ 0 ] , V_99 -> V_30 [ 1 ] ,
V_99 -> V_30 [ 2 ] , V_99 -> V_30 [ 3 ] ,
V_99 -> V_30 [ 4 ] , V_99 -> V_30 [ 5 ] ,
V_99 -> V_30 [ 6 ] , V_99 -> V_30 [ 7 ] ) ;
V_69 = - V_96 ;
if ( V_99 -> V_21 != V_22 )
goto error;
V_13 = sizeof( * V_11 -> V_17 ) + V_99 -> V_102 ;
V_6 -> V_18 = V_13 + sizeof( * V_11 ) ;
V_69 = - V_20 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 )
goto error;
V_11 -> V_17 = F_7 ( V_13 , V_19 ) ;
if ( ! V_11 -> V_17 )
goto V_103;
V_11 -> V_21 = V_22 ;
V_11 -> V_17 -> V_23 = V_99 -> V_102 ;
V_11 -> V_17 -> V_27 = V_99 -> V_27 ;
V_11 -> V_17 -> V_25 = V_99 -> V_25 ;
memcpy ( & V_11 -> V_17 -> V_29 , & V_99 -> V_29 , 8 ) ;
memcpy ( & V_11 -> V_17 -> V_30 , V_99 -> V_30 , V_99 -> V_102 ) ;
V_6 -> V_31 [ 0 ] = ( void * ) ( ( unsigned long ) V_6 -> V_31 [ 0 ] + 1 ) ;
V_100 = (struct V_10 * * ) & V_6 -> V_32 [ 0 ] ;
while ( * V_100 )
V_100 = & ( * V_100 ) -> V_33 ;
* V_100 = V_11 ;
if ( V_11 -> V_17 -> V_27 < V_6 -> V_27 )
V_6 -> V_27 = V_11 -> V_17 -> V_27 ;
V_11 = NULL ;
V_69 = 0 ;
V_103:
F_8 ( V_11 ) ;
error:
return V_69 ;
}
static void F_25 ( struct V_10 * V_11 )
{
struct V_10 * V_33 ;
for (; V_11 ; V_11 = V_33 ) {
V_33 = V_11 -> V_33 ;
switch ( V_11 -> V_21 ) {
case V_22 :
F_8 ( V_11 -> V_17 ) ;
break;
case V_74 :
if ( V_11 -> V_75 )
F_12 ( V_11 -> V_75 ) ;
break;
default:
F_26 ( V_104 L_32 ,
V_11 -> V_21 ) ;
F_27 () ;
}
F_8 ( V_11 ) ;
}
}
static void F_28 ( struct V_5 * V_6 )
{
F_25 ( V_6 -> V_32 [ 0 ] ) ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_105 * V_106 ;
F_4 ( L_30 , V_6 -> V_7 ) ;
if ( V_6 -> V_7 != 8 )
return - V_4 ;
memcpy ( & V_6 -> V_31 , V_6 -> V_42 , 8 ) ;
V_106 = F_30 ( L_33 , 0 , V_107 ) ;
if ( F_31 ( V_106 ) ) {
F_9 ( L_34 , F_32 ( V_106 ) ) ;
return F_32 ( V_106 ) ;
}
if ( F_33 ( V_106 , V_6 -> V_42 , 8 ) < 0 )
F_27 () ;
V_6 -> V_32 [ 0 ] = V_106 ;
F_9 ( L_10 ) ;
return 0 ;
}
static void F_34 ( struct V_5 * V_6 )
{
if ( V_6 -> V_32 [ 0 ] )
F_35 ( V_6 -> V_32 [ 0 ] ) ;
}
static void F_36 ( struct V_108 * V_108 )
{
F_25 ( V_108 -> V_32 . V_42 ) ;
}
static void F_37 ( struct V_108 * V_108 )
{
if ( V_108 -> V_32 . V_42 ) {
F_35 ( V_108 -> V_32 . V_42 ) ;
V_108 -> V_32 . V_42 = NULL ;
}
}
static void F_38 ( const struct V_108 * V_108 , struct V_109 * V_110 )
{
F_39 ( V_110 , V_108 -> V_111 ) ;
}
int F_40 ( struct V_112 * V_113 , char T_6 * V_114 , int V_115 )
{
struct V_108 * V_108 ;
char * V_111 ;
F_4 ( L_35 ) ;
if ( V_115 <= 0 || V_115 > V_116 - 1 )
return - V_4 ;
V_111 = F_15 ( V_115 + 1 , V_19 ) ;
if ( ! V_111 )
return - V_20 ;
if ( F_41 ( V_111 , V_114 , V_115 ) ) {
F_8 ( V_111 ) ;
return - V_117 ;
}
V_111 [ V_115 ] = 0 ;
V_108 = F_42 ( & V_118 , V_111 , NULL ) ;
if ( F_31 ( V_108 ) ) {
F_8 ( V_111 ) ;
F_9 ( L_34 , F_32 ( V_108 ) ) ;
return F_32 ( V_108 ) ;
}
V_113 -> V_108 = V_108 ;
F_8 ( V_111 ) ;
F_9 ( L_36 , V_108 -> V_119 ) ;
return 0 ;
}
int F_43 ( struct V_112 * V_113 , char T_6 * V_114 ,
int V_115 )
{
struct V_108 * V_108 ;
char * V_111 ;
F_4 ( L_35 ) ;
if ( V_115 <= 0 || V_115 > V_116 - 1 )
return - V_4 ;
V_111 = F_15 ( V_115 + 1 , V_19 ) ;
if ( ! V_111 )
return - V_20 ;
if ( F_41 ( V_111 , V_114 , V_115 ) ) {
F_8 ( V_111 ) ;
return - V_117 ;
}
V_111 [ V_115 ] = 0 ;
V_108 = F_42 ( & V_120 , V_111 , NULL ) ;
if ( F_31 ( V_108 ) ) {
F_8 ( V_111 ) ;
F_9 ( L_34 , F_32 ( V_108 ) ) ;
return F_32 ( V_108 ) ;
}
V_113 -> V_121 = V_108 ;
F_8 ( V_111 ) ;
F_9 ( L_36 , V_108 -> V_119 ) ;
return 0 ;
}
int F_44 ( struct V_122 * V_123 ,
const void * V_29 ,
T_7 V_27 ,
T_3 V_25 )
{
const struct V_124 * V_124 = F_45 () ;
struct V_108 * V_108 ;
int V_69 ;
struct {
T_3 V_101 ;
struct V_98 V_99 ;
} V_42 ;
F_4 ( L_35 ) ;
V_108 = F_46 ( & V_118 , L_37 ,
V_125 , V_126 , V_124 , 0 ,
V_127 ) ;
if ( F_31 ( V_108 ) ) {
F_9 ( L_38 , F_32 ( V_108 ) ) ;
return - V_20 ;
}
F_6 ( L_39 , F_47 ( V_108 ) ) ;
V_42 . V_101 = 1 ;
V_42 . V_99 . V_21 = V_22 ;
V_42 . V_99 . V_102 = 0 ;
V_42 . V_99 . V_27 = V_27 ;
V_42 . V_99 . V_25 = 0 ;
memcpy ( & V_42 . V_99 . V_29 , V_29 , sizeof( V_42 . V_99 . V_29 ) ) ;
V_69 = F_48 ( V_108 , & V_42 , sizeof( V_42 ) , NULL , NULL ) ;
if ( V_69 < 0 )
goto error;
V_123 -> V_108 = V_108 ;
F_9 ( L_40 , F_47 ( V_108 ) ) ;
return 0 ;
error:
F_49 ( V_108 ) ;
F_50 ( V_108 ) ;
F_9 ( L_41 , V_69 ) ;
return - V_20 ;
}
struct V_108 * F_51 ( const char * V_128 )
{
const struct V_124 * V_124 = F_45 () ;
struct V_108 * V_108 ;
int V_69 ;
V_108 = F_46 ( & V_118 , V_128 ,
V_125 , V_126 , V_124 ,
V_129 , V_127 ) ;
if ( F_31 ( V_108 ) )
return V_108 ;
V_69 = F_48 ( V_108 , NULL , 0 , NULL , NULL ) ;
if ( V_69 < 0 ) {
F_49 ( V_108 ) ;
F_50 ( V_108 ) ;
return F_52 ( V_69 ) ;
}
return V_108 ;
}
static long F_53 ( const struct V_108 * V_108 ,
char T_6 * V_130 , T_1 V_131 )
{
const struct V_10 * V_11 ;
const struct V_34 * V_35 ;
T_1 V_132 ;
T_2 T_6 * V_8 , * V_133 ;
T_3 V_134 , V_135 , V_136 , V_137 , V_138 ;
T_5 V_139 [ V_95 ] ;
int V_36 ;
F_4 ( L_35 ) ;
if ( memcmp ( V_108 -> V_111 , L_42 , 4 ) != 0 )
return - V_140 ;
V_134 = strlen ( V_108 -> V_111 + 4 ) ;
#define F_54 ( T_8 ) (((X) + 3) & ~3)
V_132 = 2 * 4 ;
V_132 += F_54 ( V_134 ) ;
V_132 += 1 * 4 ;
V_136 = 0 ;
for ( V_11 = V_108 -> V_32 . V_42 ; V_11 ; V_11 = V_11 -> V_33 ) {
V_135 = 4 ;
switch ( V_11 -> V_21 ) {
case V_22 :
V_135 += 8 * 4 ;
V_135 += F_54 ( V_11 -> V_17 -> V_23 ) ;
break;
case V_74 :
V_35 = & V_11 -> V_75 -> V_45 ;
V_135 += 4 + V_35 -> V_38 * 4 ;
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ )
V_135 += F_54 ( strlen ( V_35 -> V_37 [ V_36 ] ) ) ;
V_135 += 4 + F_54 ( strlen ( V_35 -> V_39 ) ) ;
V_35 = & V_11 -> V_75 -> V_46 ;
V_135 += 4 + V_35 -> V_38 * 4 ;
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ )
V_135 += F_54 ( strlen ( V_35 -> V_37 [ V_36 ] ) ) ;
V_135 += 4 + F_54 ( strlen ( V_35 -> V_39 ) ) ;
V_135 += 8 + F_54 ( V_11 -> V_75 -> V_47 . V_63 ) ;
V_135 += 4 * 8 + 2 * 4 ;
V_135 += 4 + V_11 -> V_75 -> V_49 * 8 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_75 -> V_49 ; V_36 ++ )
V_135 += F_54 ( V_11 -> V_75 -> V_48 [ V_36 ] . V_63 ) ;
V_135 += 4 + F_54 ( V_11 -> V_75 -> V_23 ) ;
V_135 += 4 + F_54 ( V_11 -> V_75 -> V_86 ) ;
V_135 += 4 + V_11 -> V_75 -> V_51 * 8 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_75 -> V_51 ; V_36 ++ )
V_135 += F_54 ( V_11 -> V_75 -> V_50 [ V_36 ] . V_63 ) ;
break;
default:
F_27 () ;
continue;
}
F_6 ( L_43 , V_136 , V_135 ) ;
F_22 ( V_135 , <= , V_92 ) ;
V_139 [ V_136 ++ ] = V_135 ;
V_132 += V_135 + 4 ;
}
#undef F_54
if ( ! V_130 || V_131 < V_132 )
return V_132 ;
V_8 = ( T_2 T_6 * ) V_130 ;
V_138 = 0 ;
#define F_55 ( T_9 ) \
do { \
__be32 y = htonl(x); \
if (put_user(y, xdr++) < 0) \
goto fault; \
} while(0)
#define F_56 ( T_10 , T_11 ) \
do { \
u32 _l = (l); \
ENCODE(l); \
if (copy_to_user(xdr, (s), _l) != 0) \
goto fault; \
if (_l & 3 && \
copy_to_user((u8 __user *)xdr + _l, &zero, 4 - (_l & 3)) != 0) \
goto fault; \
xdr += (_l + 3) >> 2; \
} while(0)
#define F_57 ( T_9 ) \
do { \
__be64 y = cpu_to_be64(x); \
if (copy_to_user(xdr, &y, 8) != 0) \
goto fault; \
xdr += 8 >> 2; \
} while(0)
#define F_58 ( T_11 ) \
do { \
const char *_s = (s); \
ENCODE_DATA(strlen(_s), _s); \
} while(0)
F_55 ( 0 ) ;
F_56 ( V_134 , V_108 -> V_111 + 4 ) ;
F_55 ( V_136 ) ;
V_137 = 0 ;
for ( V_11 = V_108 -> V_32 . V_42 ; V_11 ; V_11 = V_11 -> V_33 ) {
V_135 = V_139 [ V_137 ++ ] ;
F_55 ( V_135 ) ;
V_133 = V_8 ;
F_55 ( V_11 -> V_21 ) ;
switch ( V_11 -> V_21 ) {
case V_22 :
F_55 ( V_11 -> V_17 -> V_24 ) ;
F_55 ( V_11 -> V_17 -> V_25 ) ;
F_56 ( 8 , V_11 -> V_17 -> V_29 ) ;
F_55 ( V_11 -> V_17 -> V_26 ) ;
F_55 ( V_11 -> V_17 -> V_27 ) ;
F_55 ( V_11 -> V_17 -> V_28 ) ;
F_56 ( V_11 -> V_17 -> V_23 , V_11 -> V_17 -> V_30 ) ;
break;
case V_74 :
V_35 = & V_11 -> V_75 -> V_45 ;
F_55 ( V_35 -> V_38 ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ )
F_58 ( V_35 -> V_37 [ V_36 ] ) ;
F_58 ( V_35 -> V_39 ) ;
V_35 = & V_11 -> V_75 -> V_46 ;
F_55 ( V_35 -> V_38 ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ )
F_58 ( V_35 -> V_37 [ V_36 ] ) ;
F_58 ( V_35 -> V_39 ) ;
F_55 ( V_11 -> V_75 -> V_47 . V_62 ) ;
F_56 ( V_11 -> V_75 -> V_47 . V_63 ,
V_11 -> V_75 -> V_47 . V_42 ) ;
F_57 ( V_11 -> V_75 -> V_78 ) ;
F_57 ( V_11 -> V_75 -> V_80 ) ;
F_57 ( V_11 -> V_75 -> V_81 ) ;
F_57 ( V_11 -> V_75 -> V_82 ) ;
F_55 ( V_11 -> V_75 -> V_83 ) ;
F_55 ( V_11 -> V_75 -> V_84 ) ;
F_55 ( V_11 -> V_75 -> V_49 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_75 -> V_49 ; V_36 ++ ) {
F_55 ( V_11 -> V_75 -> V_48 [ V_36 ] . V_62 ) ;
F_56 ( V_11 -> V_75 -> V_48 [ V_36 ] . V_63 ,
V_11 -> V_75 -> V_48 [ V_36 ] . V_42 ) ;
}
F_56 ( V_11 -> V_75 -> V_23 , V_11 -> V_75 -> V_30 ) ;
F_56 ( V_11 -> V_75 -> V_86 , V_11 -> V_75 -> V_52 ) ;
F_55 ( V_11 -> V_75 -> V_51 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_75 -> V_51 ; V_36 ++ ) {
F_55 ( V_11 -> V_75 -> V_50 [ V_36 ] . V_62 ) ;
F_56 ( V_11 -> V_75 -> V_50 [ V_36 ] . V_63 ,
V_11 -> V_75 -> V_50 [ V_36 ] . V_42 ) ;
}
break;
default:
F_27 () ;
break;
}
F_22 ( ( unsigned long ) V_8 - ( unsigned long ) V_133 , == ,
V_135 ) ;
}
#undef F_58
#undef F_56
#undef F_57
#undef F_55
F_22 ( V_137 , == , V_136 ) ;
F_22 ( ( char T_6 * ) V_8 - V_130 , == , V_132 ) ;
F_9 ( L_44 , V_132 ) ;
return V_132 ;
V_141:
F_9 ( L_45 ) ;
return - V_117 ;
}
