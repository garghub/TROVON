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
V_6 -> V_31 . V_32 [ 1 ] = ( void * ) ( ( unsigned long ) V_6 -> V_31 . V_32 [ 1 ] + 1 ) ;
for ( V_12 = (struct V_10 * * ) & V_6 -> V_31 . V_32 [ 0 ] ;
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
F_8 ( V_41 -> V_32 ) ;
}
static void F_12 ( struct V_42 * V_43 )
{
int V_36 ;
F_10 ( & V_43 -> V_44 ) ;
F_10 ( & V_43 -> V_45 ) ;
F_11 ( & V_43 -> V_46 ) ;
if ( V_43 -> V_47 ) {
for ( V_36 = V_43 -> V_48 - 1 ; V_36 >= 0 ; V_36 -- )
F_11 ( & V_43 -> V_47 [ V_36 ] ) ;
F_8 ( V_43 -> V_47 ) ;
}
if ( V_43 -> V_49 ) {
for ( V_36 = V_43 -> V_50 - 1 ; V_36 >= 0 ; V_36 -- )
F_11 ( & V_43 -> V_49 [ V_36 ] ) ;
F_8 ( V_43 -> V_49 ) ;
}
F_8 ( V_43 -> V_30 ) ;
F_8 ( V_43 -> V_51 ) ;
F_8 ( V_43 ) ;
}
static int F_13 ( struct V_34 * V_35 ,
const T_2 * * V_52 ,
unsigned int * V_53 )
{
const T_2 * V_8 = * V_52 ;
unsigned int V_9 = * V_53 , V_54 , V_36 , V_55 ;
if ( V_9 <= 12 )
return - V_4 ;
F_4 ( L_11 ,
F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , F_5 ( V_8 [ 2 ] ) , V_9 ) ;
V_54 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_54 <= 0 || V_54 > V_56 )
return - V_4 ;
V_35 -> V_38 = V_54 ;
if ( V_9 <= ( V_54 + 1 ) * 4 )
return - V_4 ;
V_35 -> V_37 = F_14 ( V_54 , sizeof( char * ) , V_19 ) ;
if ( ! V_35 -> V_37 )
return - V_20 ;
for ( V_36 = 0 ; V_36 < V_54 ; V_36 ++ ) {
if ( V_9 < 4 )
return - V_4 ;
V_55 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_55 <= 0 || V_55 > V_57 )
return - V_4 ;
if ( V_55 > V_9 )
return - V_4 ;
V_35 -> V_37 [ V_36 ] = F_15 ( V_55 + 1 , V_19 ) ;
if ( ! V_35 -> V_37 [ V_36 ] )
return - V_20 ;
memcpy ( V_35 -> V_37 [ V_36 ] , V_8 , V_55 ) ;
V_35 -> V_37 [ V_36 ] [ V_55 ] = 0 ;
V_55 = ( V_55 + 3 ) & ~ 3 ;
V_9 -= V_55 ;
V_8 += V_55 >> 2 ;
}
if ( V_9 < 4 )
return - V_4 ;
V_55 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_55 <= 0 || V_55 > V_58 )
return - V_4 ;
if ( V_55 > V_9 )
return - V_4 ;
V_35 -> V_39 = F_15 ( V_55 + 1 , V_19 ) ;
if ( ! V_35 -> V_39 )
return - V_20 ;
memcpy ( V_35 -> V_39 , V_8 , V_55 ) ;
V_35 -> V_39 [ V_55 ] = 0 ;
V_55 = ( V_55 + 3 ) & ~ 3 ;
V_9 -= V_55 ;
V_8 += V_55 >> 2 ;
F_6 ( L_12 , V_35 -> V_37 [ 0 ] , V_35 -> V_39 ) ;
* V_52 = V_8 ;
* V_53 = V_9 ;
F_9 ( L_13 , V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_40 * V_41 ,
T_1 V_59 ,
const T_2 * * V_52 ,
unsigned int * V_53 )
{
const T_2 * V_8 = * V_52 ;
unsigned int V_9 = * V_53 , V_60 ;
if ( V_9 <= 8 )
return - V_4 ;
F_4 ( L_14 ,
V_59 , F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , V_9 ) ;
V_41 -> V_61 = F_5 ( * V_8 ++ ) ;
V_60 = F_5 ( * V_8 ++ ) ;
V_9 -= 8 ;
if ( V_60 > V_59 )
return - V_4 ;
V_41 -> V_62 = V_60 ;
if ( V_60 > 0 ) {
V_41 -> V_32 = F_17 ( V_8 , V_60 , V_19 ) ;
if ( ! V_41 -> V_32 )
return - V_20 ;
V_60 = ( V_60 + 3 ) & ~ 3 ;
V_9 -= V_60 ;
V_8 += V_60 >> 2 ;
}
F_6 ( L_15 , V_41 -> V_61 , V_41 -> V_62 ) ;
* V_52 = V_8 ;
* V_53 = V_9 ;
F_9 ( L_13 , V_9 ) ;
return 0 ;
}
static int F_18 ( struct V_40 * * V_63 ,
T_4 * V_64 ,
T_4 V_65 ,
T_1 V_66 ,
const T_2 * * V_52 ,
unsigned int * V_53 )
{
struct V_40 * V_41 ;
const T_2 * V_8 = * V_52 ;
unsigned int V_9 = * V_53 , V_67 , V_36 ;
int V_68 ;
if ( V_9 < 4 )
return - V_4 ;
F_4 ( L_16 ,
V_65 , V_66 , F_5 ( V_8 [ 0 ] ) , V_9 ) ;
V_67 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_67 > V_65 )
return - V_4 ;
* V_64 = V_67 ;
if ( V_67 > 0 ) {
if ( V_9 <= ( V_67 + 1 ) * 4 )
return - V_4 ;
F_6 ( L_17 , V_67 ) ;
V_41 = F_14 ( V_67 , sizeof( struct V_40 ) ,
V_19 ) ;
if ( ! V_41 )
return - V_20 ;
* V_63 = V_41 ;
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ ) {
V_68 = F_16 ( & V_41 [ V_36 ] ,
V_66 ,
& V_8 , & V_9 ) ;
if ( V_68 < 0 )
return V_68 ;
}
}
* V_52 = V_8 ;
* V_53 = V_9 ;
F_9 ( L_13 , V_9 ) ;
return 0 ;
}
static int F_19 ( T_4 * * V_69 , T_5 * V_70 ,
const T_2 * * V_52 , unsigned int * V_53 )
{
const T_2 * V_8 = * V_52 ;
unsigned int V_9 = * V_53 , V_60 ;
if ( V_9 <= 4 )
return - V_4 ;
F_4 ( L_18 , F_5 ( V_8 [ 0 ] ) , V_9 ) ;
V_60 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
if ( V_60 > V_71 )
return - V_4 ;
* V_70 = V_60 ;
F_6 ( L_19 , V_60 ) ;
if ( V_60 > 0 ) {
* V_69 = F_17 ( V_8 , V_60 , V_19 ) ;
if ( ! * V_69 )
return - V_20 ;
V_60 = ( V_60 + 3 ) & ~ 3 ;
V_9 -= V_60 ;
V_8 += V_60 >> 2 ;
}
* V_52 = V_8 ;
* V_53 = V_9 ;
F_9 ( L_13 , V_9 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
T_1 V_7 ,
const T_2 * V_8 , unsigned int V_9 )
{
struct V_10 * V_11 , * * V_12 ;
struct V_42 * V_43 ;
const T_2 * V_72 = V_8 + ( V_9 >> 2 ) ;
int V_68 ;
F_4 ( L_1 ,
F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , F_5 ( V_8 [ 2 ] ) , F_5 ( V_8 [ 3 ] ) ,
V_9 ) ;
V_6 -> V_18 = V_7 + V_9 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 )
return - V_20 ;
V_43 = F_7 ( sizeof( * V_43 ) , V_19 ) ;
if ( ! V_43 ) {
F_8 ( V_11 ) ;
return - V_20 ;
}
V_11 -> V_21 = V_73 ;
V_11 -> V_74 = V_43 ;
V_68 = F_13 ( & V_43 -> V_44 , & V_8 , & V_9 ) ;
if ( V_68 < 0 )
goto error;
V_68 = F_13 ( & V_43 -> V_45 , & V_8 , & V_9 ) ;
if ( V_68 < 0 )
goto error;
V_68 = F_16 ( & V_43 -> V_46 , V_75 ,
& V_8 , & V_9 ) ;
if ( V_68 < 0 )
goto error;
if ( V_9 < 4 * 8 + 2 * 4 )
goto V_76;
V_43 -> V_77 = F_21 ( ( const V_78 * ) V_8 ) ;
V_8 += 2 ;
V_43 -> V_79 = F_21 ( ( const V_78 * ) V_8 ) ;
V_8 += 2 ;
V_43 -> V_80 = F_21 ( ( const V_78 * ) V_8 ) ;
V_8 += 2 ;
V_43 -> V_81 = F_21 ( ( const V_78 * ) V_8 ) ;
V_8 += 2 ;
V_43 -> V_82 = F_5 ( * V_8 ++ ) ;
V_43 -> V_83 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 * 8 + 2 * 4 ;
F_6 ( L_20 ,
V_43 -> V_77 , V_43 -> V_79 , V_43 -> V_80 ,
V_43 -> V_81 ) ;
F_6 ( L_21 , V_43 -> V_82 , V_43 -> V_83 ) ;
V_68 = F_18 ( & V_43 -> V_47 ,
& V_43 -> V_48 ,
V_84 ,
V_75 ,
& V_8 , & V_9 ) ;
if ( V_68 < 0 )
goto error;
F_22 ( ( V_72 - V_8 ) << 2 , == , V_9 ) ;
V_68 = F_19 ( & V_43 -> V_30 , & V_43 -> V_23 ,
& V_8 , & V_9 ) ;
if ( V_68 < 0 )
goto error;
V_68 = F_19 ( & V_43 -> V_51 , & V_43 -> V_85 ,
& V_8 , & V_9 ) ;
if ( V_68 < 0 )
goto error;
F_22 ( ( V_72 - V_8 ) << 2 , == , V_9 ) ;
V_68 = F_18 ( & V_43 -> V_49 ,
& V_43 -> V_50 ,
V_86 ,
V_87 ,
& V_8 , & V_9 ) ;
if ( V_68 < 0 )
goto error;
F_22 ( ( V_72 - V_8 ) << 2 , == , V_9 ) ;
if ( V_9 != 0 )
goto V_76;
for ( V_12 = (struct V_10 * * ) & V_6 -> V_31 . V_32 [ 0 ] ;
* V_12 ;
V_12 = & ( * V_12 ) -> V_33 )
continue;
* V_12 = V_11 ;
if ( V_11 -> V_17 -> V_27 < V_6 -> V_27 )
V_6 -> V_27 = V_11 -> V_17 -> V_27 ;
F_9 ( L_10 ) ;
return 0 ;
V_76:
V_68 = - V_4 ;
error:
F_12 ( V_43 ) ;
F_8 ( V_11 ) ;
F_9 ( L_22 , V_68 ) ;
return V_68 ;
}
static int F_23 ( struct V_5 * V_6 )
{
const T_2 * V_8 = V_6 -> V_32 , * V_11 ;
const char * V_88 ;
unsigned int V_60 , V_55 , V_36 , V_89 , V_9 , V_90 ;
T_1 V_7 = V_6 -> V_7 ;
int V_68 ;
F_4 ( L_23 ,
F_5 ( V_8 [ 0 ] ) , F_5 ( V_8 [ 1 ] ) , F_5 ( V_8 [ 2 ] ) , F_5 ( V_8 [ 3 ] ) ,
V_6 -> V_7 ) ;
if ( V_7 > V_91 )
goto V_92;
if ( V_7 & 3 )
goto V_92;
if ( F_5 ( * V_8 ++ ) != 0 )
goto V_92;
V_7 -= 4 ;
V_60 = F_5 ( * V_8 ++ ) ;
if ( V_60 < 1 || V_60 > V_93 )
goto V_92;
V_7 -= 4 ;
V_55 = ( V_60 + 3 ) & ~ 3 ;
if ( V_55 > V_7 )
goto V_92;
V_88 = ( const char * ) V_8 ;
for ( V_36 = 0 ; V_36 < V_60 ; V_36 ++ )
if ( ! isprint ( V_88 [ V_36 ] ) )
goto V_92;
if ( V_60 < V_55 )
for (; V_36 < V_55 ; V_36 ++ )
if ( V_88 [ V_36 ] )
goto V_92;
F_6 ( L_24 ,
V_60 , V_55 , V_60 , V_60 , ( const char * ) V_8 ) ;
V_7 -= V_55 ;
V_8 += V_55 >> 2 ;
if ( V_7 < 12 )
goto V_92;
V_89 = F_5 ( * V_8 ++ ) ;
V_7 -= 4 ;
F_6 ( L_25 , V_89 ) ;
if ( V_89 < 1 || V_89 > V_94 )
goto V_92;
V_11 = V_8 ;
V_36 = V_89 ;
do {
if ( V_7 < 8 )
goto V_92;
V_9 = F_5 ( * V_8 ++ ) ;
V_90 = F_5 ( * V_8 ) ;
V_7 -= 4 ;
F_6 ( L_26 , V_9 , V_7 , V_90 ) ;
if ( V_9 < 20 || V_9 > V_7 )
goto V_92;
V_7 -= ( V_9 + 3 ) & ~ 3 ;
V_8 += ( V_9 + 3 ) >> 2 ;
} while ( -- V_36 > 0 );
F_6 ( L_27 , V_7 ) ;
if ( V_7 != 0 )
goto V_92;
do {
V_8 = V_11 ;
V_9 = F_5 ( * V_8 ++ ) ;
V_11 = V_8 + ( ( V_9 + 3 ) >> 2 ) ;
V_90 = F_5 ( * V_8 ++ ) ;
V_9 -= 4 ;
F_6 ( L_28 , V_90 , V_8 , V_11 ) ;
switch ( V_90 ) {
case V_22 :
V_68 = F_3 ( V_6 , V_7 , V_8 , V_9 ) ;
if ( V_68 != 0 )
goto error;
break;
case V_73 :
V_68 = F_20 ( V_6 , V_7 , V_8 , V_9 ) ;
if ( V_68 != 0 )
goto error;
break;
default:
V_68 = - V_95 ;
goto error;
}
} while ( -- V_89 > 0 );
F_9 ( L_10 ) ;
return 0 ;
V_92:
F_9 ( L_29 ) ;
return - V_96 ;
error:
F_9 ( L_22 , V_68 ) ;
return V_68 ;
}
static int F_24 ( struct V_5 * V_6 )
{
const struct V_97 * V_98 ;
struct V_10 * V_11 , * * V_99 ;
T_1 V_13 ;
T_3 V_100 ;
int V_68 ;
F_4 ( L_30 , V_6 -> V_7 ) ;
if ( ! V_6 -> V_32 && V_6 -> V_7 == 0 )
return 0 ;
if ( V_6 -> V_7 > 7 * 4 ) {
V_68 = F_23 ( V_6 ) ;
if ( V_68 != - V_96 )
return V_68 ;
}
V_68 = - V_4 ;
if ( V_6 -> V_7 <= 4 || ! V_6 -> V_32 )
goto error;
memcpy ( & V_100 , V_6 -> V_32 , sizeof( V_100 ) ) ;
V_6 -> V_32 += sizeof( V_100 ) ;
V_6 -> V_7 -= sizeof( V_100 ) ;
F_6 ( L_31 , V_100 ) ;
V_68 = - V_15 ;
if ( V_100 != 1 )
goto error;
V_68 = - V_4 ;
if ( V_6 -> V_7 < sizeof( * V_98 ) )
goto error;
V_98 = V_6 -> V_32 ;
if ( V_6 -> V_7 != sizeof( * V_98 ) + V_98 -> V_101 )
goto error;
F_6 ( L_3 , V_98 -> V_21 ) ;
F_6 ( L_4 , V_98 -> V_101 ) ;
F_6 ( L_5 , V_98 -> V_27 ) ;
F_6 ( L_6 , V_98 -> V_25 ) ;
F_6 ( L_8 ,
V_98 -> V_29 [ 0 ] , V_98 -> V_29 [ 1 ] ,
V_98 -> V_29 [ 2 ] , V_98 -> V_29 [ 3 ] ,
V_98 -> V_29 [ 4 ] , V_98 -> V_29 [ 5 ] ,
V_98 -> V_29 [ 6 ] , V_98 -> V_29 [ 7 ] ) ;
if ( V_98 -> V_101 >= 8 )
F_6 ( L_9 ,
V_98 -> V_30 [ 0 ] , V_98 -> V_30 [ 1 ] ,
V_98 -> V_30 [ 2 ] , V_98 -> V_30 [ 3 ] ,
V_98 -> V_30 [ 4 ] , V_98 -> V_30 [ 5 ] ,
V_98 -> V_30 [ 6 ] , V_98 -> V_30 [ 7 ] ) ;
V_68 = - V_95 ;
if ( V_98 -> V_21 != V_22 )
goto error;
V_13 = sizeof( * V_11 -> V_17 ) + V_98 -> V_101 ;
V_6 -> V_18 = V_13 + sizeof( * V_11 ) ;
V_68 = - V_20 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 )
goto error;
V_11 -> V_17 = F_7 ( V_13 , V_19 ) ;
if ( ! V_11 -> V_17 )
goto V_102;
V_11 -> V_21 = V_22 ;
V_11 -> V_17 -> V_23 = V_98 -> V_101 ;
V_11 -> V_17 -> V_27 = V_98 -> V_27 ;
V_11 -> V_17 -> V_25 = V_98 -> V_25 ;
memcpy ( & V_11 -> V_17 -> V_29 , & V_98 -> V_29 , 8 ) ;
memcpy ( & V_11 -> V_17 -> V_30 , V_98 -> V_30 , V_98 -> V_101 ) ;
V_6 -> V_31 . V_32 [ 1 ] = ( void * ) ( ( unsigned long ) V_6 -> V_31 . V_32 [ 1 ] + 1 ) ;
V_99 = (struct V_10 * * ) & V_6 -> V_31 . V_32 [ 0 ] ;
while ( * V_99 )
V_99 = & ( * V_99 ) -> V_33 ;
* V_99 = V_11 ;
if ( V_11 -> V_17 -> V_27 < V_6 -> V_27 )
V_6 -> V_27 = V_11 -> V_17 -> V_27 ;
V_11 = NULL ;
V_68 = 0 ;
V_102:
F_8 ( V_11 ) ;
error:
return V_68 ;
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
case V_73 :
if ( V_11 -> V_74 )
F_12 ( V_11 -> V_74 ) ;
break;
default:
F_26 ( V_103 L_32 ,
V_11 -> V_21 ) ;
F_27 () ;
}
F_8 ( V_11 ) ;
}
}
static void F_28 ( struct V_5 * V_6 )
{
F_25 ( V_6 -> V_31 . V_32 [ 0 ] ) ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_104 * V_105 ;
F_4 ( L_30 , V_6 -> V_7 ) ;
if ( V_6 -> V_7 != 8 )
return - V_4 ;
memcpy ( & V_6 -> V_31 . V_32 [ 2 ] , V_6 -> V_32 , 8 ) ;
V_105 = F_30 ( L_33 , 0 , V_106 ) ;
if ( F_31 ( V_105 ) ) {
F_9 ( L_34 , F_32 ( V_105 ) ) ;
return F_32 ( V_105 ) ;
}
if ( F_33 ( V_105 , V_6 -> V_32 , 8 ) < 0 )
F_27 () ;
V_6 -> V_31 . V_32 [ 0 ] = V_105 ;
F_9 ( L_10 ) ;
return 0 ;
}
static void F_34 ( struct V_5 * V_6 )
{
if ( V_6 -> V_31 . V_32 [ 0 ] )
F_35 ( V_6 -> V_31 . V_32 [ 0 ] ) ;
}
static void F_36 ( struct V_107 * V_107 )
{
F_25 ( V_107 -> V_31 . V_32 [ 0 ] ) ;
}
static void F_37 ( struct V_107 * V_107 )
{
if ( V_107 -> V_31 . V_32 [ 0 ] ) {
F_35 ( V_107 -> V_31 . V_32 [ 0 ] ) ;
V_107 -> V_31 . V_32 [ 0 ] = NULL ;
}
}
static void F_38 ( const struct V_107 * V_107 , struct V_108 * V_109 )
{
F_39 ( V_109 , V_107 -> V_110 ) ;
}
int F_40 ( struct V_111 * V_112 , char T_6 * V_113 , int V_114 )
{
struct V_107 * V_107 ;
char * V_110 ;
F_4 ( L_35 ) ;
if ( V_114 <= 0 || V_114 > V_115 - 1 )
return - V_4 ;
V_110 = F_41 ( V_113 , V_114 ) ;
if ( F_31 ( V_110 ) )
return F_32 ( V_110 ) ;
V_107 = F_42 ( & V_116 , V_110 , NULL ) ;
if ( F_31 ( V_107 ) ) {
F_8 ( V_110 ) ;
F_9 ( L_34 , F_32 ( V_107 ) ) ;
return F_32 ( V_107 ) ;
}
V_112 -> V_107 = V_107 ;
F_8 ( V_110 ) ;
F_9 ( L_36 , V_107 -> V_117 ) ;
return 0 ;
}
int F_43 ( struct V_111 * V_112 , char T_6 * V_113 ,
int V_114 )
{
struct V_107 * V_107 ;
char * V_110 ;
F_4 ( L_35 ) ;
if ( V_114 <= 0 || V_114 > V_115 - 1 )
return - V_4 ;
V_110 = F_41 ( V_113 , V_114 ) ;
if ( F_31 ( V_110 ) )
return F_32 ( V_110 ) ;
V_107 = F_42 ( & V_118 , V_110 , NULL ) ;
if ( F_31 ( V_107 ) ) {
F_8 ( V_110 ) ;
F_9 ( L_34 , F_32 ( V_107 ) ) ;
return F_32 ( V_107 ) ;
}
V_112 -> V_119 = V_107 ;
F_8 ( V_110 ) ;
F_9 ( L_36 , V_107 -> V_117 ) ;
return 0 ;
}
int F_44 ( struct V_120 * V_121 ,
const void * V_29 ,
T_7 V_27 ,
T_3 V_25 )
{
const struct V_122 * V_122 = F_45 () ;
struct V_107 * V_107 ;
int V_68 ;
struct {
T_3 V_100 ;
struct V_97 V_98 ;
} V_32 ;
F_4 ( L_35 ) ;
V_107 = F_46 ( & V_116 , L_37 ,
V_123 , V_124 , V_122 , 0 ,
V_125 ) ;
if ( F_31 ( V_107 ) ) {
F_9 ( L_38 , F_32 ( V_107 ) ) ;
return - V_20 ;
}
F_6 ( L_39 , F_47 ( V_107 ) ) ;
V_32 . V_100 = 1 ;
V_32 . V_98 . V_21 = V_22 ;
V_32 . V_98 . V_101 = 0 ;
V_32 . V_98 . V_27 = V_27 ;
V_32 . V_98 . V_25 = 0 ;
memcpy ( & V_32 . V_98 . V_29 , V_29 , sizeof( V_32 . V_98 . V_29 ) ) ;
V_68 = F_48 ( V_107 , & V_32 , sizeof( V_32 ) , NULL , NULL ) ;
if ( V_68 < 0 )
goto error;
V_121 -> V_107 = V_107 ;
F_9 ( L_40 , F_47 ( V_107 ) ) ;
return 0 ;
error:
F_49 ( V_107 ) ;
F_50 ( V_107 ) ;
F_9 ( L_41 , V_68 ) ;
return - V_20 ;
}
struct V_107 * F_51 ( const char * V_126 )
{
const struct V_122 * V_122 = F_45 () ;
struct V_107 * V_107 ;
int V_68 ;
V_107 = F_46 ( & V_116 , V_126 ,
V_123 , V_124 , V_122 ,
V_127 , V_125 ) ;
if ( F_31 ( V_107 ) )
return V_107 ;
V_68 = F_48 ( V_107 , NULL , 0 , NULL , NULL ) ;
if ( V_68 < 0 ) {
F_49 ( V_107 ) ;
F_50 ( V_107 ) ;
return F_52 ( V_68 ) ;
}
return V_107 ;
}
static long F_53 ( const struct V_107 * V_107 ,
char T_6 * V_128 , T_1 V_129 )
{
const struct V_10 * V_11 ;
const struct V_34 * V_35 ;
T_1 V_130 ;
T_2 T_6 * V_8 , * V_131 ;
T_3 V_132 , V_133 , V_134 , V_135 , V_136 ;
T_5 V_137 [ V_94 ] ;
int V_36 ;
F_4 ( L_35 ) ;
if ( memcmp ( V_107 -> V_110 , L_42 , 4 ) != 0 )
return - V_138 ;
V_132 = strlen ( V_107 -> V_110 + 4 ) ;
#define F_54 ( T_8 ) (((X) + 3) & ~3)
V_130 = 2 * 4 ;
V_130 += F_54 ( V_132 ) ;
V_130 += 1 * 4 ;
V_134 = 0 ;
for ( V_11 = V_107 -> V_31 . V_32 [ 0 ] ; V_11 ; V_11 = V_11 -> V_33 ) {
V_133 = 4 ;
switch ( V_11 -> V_21 ) {
case V_22 :
V_133 += 8 * 4 ;
V_133 += F_54 ( V_11 -> V_17 -> V_23 ) ;
break;
case V_73 :
V_35 = & V_11 -> V_74 -> V_44 ;
V_133 += 4 + V_35 -> V_38 * 4 ;
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ )
V_133 += F_54 ( strlen ( V_35 -> V_37 [ V_36 ] ) ) ;
V_133 += 4 + F_54 ( strlen ( V_35 -> V_39 ) ) ;
V_35 = & V_11 -> V_74 -> V_45 ;
V_133 += 4 + V_35 -> V_38 * 4 ;
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ )
V_133 += F_54 ( strlen ( V_35 -> V_37 [ V_36 ] ) ) ;
V_133 += 4 + F_54 ( strlen ( V_35 -> V_39 ) ) ;
V_133 += 8 + F_54 ( V_11 -> V_74 -> V_46 . V_62 ) ;
V_133 += 4 * 8 + 2 * 4 ;
V_133 += 4 + V_11 -> V_74 -> V_48 * 8 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_74 -> V_48 ; V_36 ++ )
V_133 += F_54 ( V_11 -> V_74 -> V_47 [ V_36 ] . V_62 ) ;
V_133 += 4 + F_54 ( V_11 -> V_74 -> V_23 ) ;
V_133 += 4 + F_54 ( V_11 -> V_74 -> V_85 ) ;
V_133 += 4 + V_11 -> V_74 -> V_50 * 8 ;
for ( V_36 = 0 ; V_36 < V_11 -> V_74 -> V_50 ; V_36 ++ )
V_133 += F_54 ( V_11 -> V_74 -> V_49 [ V_36 ] . V_62 ) ;
break;
default:
F_27 () ;
continue;
}
F_6 ( L_43 , V_134 , V_133 ) ;
F_22 ( V_133 , <= , V_91 ) ;
V_137 [ V_134 ++ ] = V_133 ;
V_130 += V_133 + 4 ;
}
#undef F_54
if ( ! V_128 || V_129 < V_130 )
return V_130 ;
V_8 = ( T_2 T_6 * ) V_128 ;
V_136 = 0 ;
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
F_56 ( V_132 , V_107 -> V_110 + 4 ) ;
F_55 ( V_134 ) ;
V_135 = 0 ;
for ( V_11 = V_107 -> V_31 . V_32 [ 0 ] ; V_11 ; V_11 = V_11 -> V_33 ) {
V_133 = V_137 [ V_135 ++ ] ;
F_55 ( V_133 ) ;
V_131 = V_8 ;
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
case V_73 :
V_35 = & V_11 -> V_74 -> V_44 ;
F_55 ( V_35 -> V_38 ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ )
F_58 ( V_35 -> V_37 [ V_36 ] ) ;
F_58 ( V_35 -> V_39 ) ;
V_35 = & V_11 -> V_74 -> V_45 ;
F_55 ( V_35 -> V_38 ) ;
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ )
F_58 ( V_35 -> V_37 [ V_36 ] ) ;
F_58 ( V_35 -> V_39 ) ;
F_55 ( V_11 -> V_74 -> V_46 . V_61 ) ;
F_56 ( V_11 -> V_74 -> V_46 . V_62 ,
V_11 -> V_74 -> V_46 . V_32 ) ;
F_57 ( V_11 -> V_74 -> V_77 ) ;
F_57 ( V_11 -> V_74 -> V_79 ) ;
F_57 ( V_11 -> V_74 -> V_80 ) ;
F_57 ( V_11 -> V_74 -> V_81 ) ;
F_55 ( V_11 -> V_74 -> V_82 ) ;
F_55 ( V_11 -> V_74 -> V_83 ) ;
F_55 ( V_11 -> V_74 -> V_48 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_74 -> V_48 ; V_36 ++ ) {
F_55 ( V_11 -> V_74 -> V_47 [ V_36 ] . V_61 ) ;
F_56 ( V_11 -> V_74 -> V_47 [ V_36 ] . V_62 ,
V_11 -> V_74 -> V_47 [ V_36 ] . V_32 ) ;
}
F_56 ( V_11 -> V_74 -> V_23 , V_11 -> V_74 -> V_30 ) ;
F_56 ( V_11 -> V_74 -> V_85 , V_11 -> V_74 -> V_51 ) ;
F_55 ( V_11 -> V_74 -> V_50 ) ;
for ( V_36 = 0 ; V_36 < V_11 -> V_74 -> V_50 ; V_36 ++ ) {
F_55 ( V_11 -> V_74 -> V_49 [ V_36 ] . V_61 ) ;
F_56 ( V_11 -> V_74 -> V_49 [ V_36 ] . V_62 ,
V_11 -> V_74 -> V_49 [ V_36 ] . V_32 ) ;
}
break;
default:
F_27 () ;
break;
}
F_22 ( ( unsigned long ) V_8 - ( unsigned long ) V_131 , == ,
V_133 ) ;
}
#undef F_58
#undef F_56
#undef F_57
#undef F_55
F_22 ( V_135 , == , V_134 ) ;
F_22 ( ( char T_6 * ) V_8 - V_128 , == , V_130 ) ;
F_9 ( L_44 , V_130 ) ;
return V_130 ;
V_139:
F_9 ( L_45 ) ;
return - V_140 ;
}
