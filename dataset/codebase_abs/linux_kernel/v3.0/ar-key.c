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
static int F_3 ( struct V_5 * V_5 , const T_1 * V_6 ,
unsigned V_7 )
{
struct V_8 * V_9 , * * V_10 ;
T_2 V_11 ;
T_3 V_12 ;
int V_13 ;
F_4 ( L_1 ,
F_5 ( V_6 [ 0 ] ) , F_5 ( V_6 [ 1 ] ) , F_5 ( V_6 [ 2 ] ) , F_5 ( V_6 [ 3 ] ) ,
V_7 ) ;
if ( V_7 <= 8 * 4 )
return - V_14 ;
V_12 = F_5 ( V_6 [ 7 ] ) ;
F_6 ( L_2 , V_12 ) ;
if ( V_12 > V_15 )
return - V_14 ;
if ( 8 * 4 + V_12 != V_7 )
return - V_14 ;
V_11 = sizeof( * V_9 ) + sizeof( * V_9 -> V_16 ) + V_12 ;
V_13 = F_7 ( V_5 , V_5 -> V_17 + V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 -= sizeof( * V_9 ) ;
V_9 = F_8 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 )
return - V_19 ;
V_9 -> V_16 = F_8 ( V_11 , V_18 ) ;
if ( ! V_9 -> V_16 ) {
F_9 ( V_9 ) ;
return - V_19 ;
}
V_9 -> V_20 = V_21 ;
V_9 -> V_16 -> V_22 = V_12 ;
V_9 -> V_16 -> V_23 = F_5 ( V_6 [ 0 ] ) ;
V_9 -> V_16 -> V_24 = F_5 ( V_6 [ 1 ] ) ;
V_9 -> V_16 -> V_25 = F_5 ( V_6 [ 4 ] ) ;
V_9 -> V_16 -> V_26 = F_5 ( V_6 [ 5 ] ) ;
V_9 -> V_16 -> V_27 = F_5 ( V_6 [ 6 ] ) ;
memcpy ( & V_9 -> V_16 -> V_28 , & V_6 [ 2 ] , 8 ) ;
memcpy ( & V_9 -> V_16 -> V_29 , & V_6 [ 8 ] , V_12 ) ;
F_6 ( L_3 , V_9 -> V_20 ) ;
F_6 ( L_4 , V_9 -> V_16 -> V_22 ) ;
F_6 ( L_5 , V_9 -> V_16 -> V_26 ) ;
F_6 ( L_6 , V_9 -> V_16 -> V_24 ) ;
F_6 ( L_7 , V_9 -> V_16 -> V_27 ) ;
F_6 ( L_8 ,
V_9 -> V_16 -> V_28 [ 0 ] , V_9 -> V_16 -> V_28 [ 1 ] ,
V_9 -> V_16 -> V_28 [ 2 ] , V_9 -> V_16 -> V_28 [ 3 ] ,
V_9 -> V_16 -> V_28 [ 4 ] , V_9 -> V_16 -> V_28 [ 5 ] ,
V_9 -> V_16 -> V_28 [ 6 ] , V_9 -> V_16 -> V_28 [ 7 ] ) ;
if ( V_9 -> V_16 -> V_22 >= 8 )
F_6 ( L_9 ,
V_9 -> V_16 -> V_29 [ 0 ] , V_9 -> V_16 -> V_29 [ 1 ] ,
V_9 -> V_16 -> V_29 [ 2 ] , V_9 -> V_16 -> V_29 [ 3 ] ,
V_9 -> V_16 -> V_29 [ 4 ] , V_9 -> V_16 -> V_29 [ 5 ] ,
V_9 -> V_16 -> V_29 [ 6 ] , V_9 -> V_16 -> V_29 [ 7 ] ) ;
V_5 -> V_30 . V_31 [ 0 ] ++ ;
for ( V_10 = (struct V_8 * * ) & V_5 -> V_32 . V_33 ;
* V_10 ;
V_10 = & ( * V_10 ) -> V_34 )
continue;
* V_10 = V_9 ;
if ( V_9 -> V_16 -> V_26 < V_5 -> V_26 )
V_5 -> V_26 = V_9 -> V_16 -> V_26 ;
F_10 ( L_10 ) ;
return 0 ;
}
static void F_11 ( struct V_35 * V_36 )
{
int V_37 ;
if ( V_36 -> V_38 ) {
for ( V_37 = V_36 -> V_39 - 1 ; V_37 >= 0 ; V_37 -- )
F_9 ( V_36 -> V_38 [ V_37 ] ) ;
F_9 ( V_36 -> V_38 ) ;
}
F_9 ( V_36 -> V_40 ) ;
}
static void F_12 ( struct V_41 * V_42 )
{
F_9 ( V_42 -> V_33 ) ;
}
static void F_13 ( struct V_43 * V_44 )
{
int V_37 ;
F_11 ( & V_44 -> V_45 ) ;
F_11 ( & V_44 -> V_46 ) ;
F_12 ( & V_44 -> V_47 ) ;
if ( V_44 -> V_48 ) {
for ( V_37 = V_44 -> V_49 - 1 ; V_37 >= 0 ; V_37 -- )
F_12 ( & V_44 -> V_48 [ V_37 ] ) ;
F_9 ( V_44 -> V_48 ) ;
}
if ( V_44 -> V_50 ) {
for ( V_37 = V_44 -> V_51 - 1 ; V_37 >= 0 ; V_37 -- )
F_12 ( & V_44 -> V_50 [ V_37 ] ) ;
F_9 ( V_44 -> V_50 ) ;
}
F_9 ( V_44 -> V_29 ) ;
F_9 ( V_44 -> V_52 ) ;
F_9 ( V_44 ) ;
}
static int F_14 ( struct V_35 * V_36 ,
const T_1 * * V_53 ,
unsigned * V_54 )
{
const T_1 * V_6 = * V_53 ;
unsigned V_7 = * V_54 , V_55 , V_37 , V_56 ;
if ( V_7 <= 12 )
return - V_4 ;
F_4 ( L_11 ,
F_5 ( V_6 [ 0 ] ) , F_5 ( V_6 [ 1 ] ) , F_5 ( V_6 [ 2 ] ) , V_7 ) ;
V_55 = F_5 ( * V_6 ++ ) ;
V_7 -= 4 ;
if ( V_55 <= 0 || V_55 > V_57 )
return - V_4 ;
V_36 -> V_39 = V_55 ;
if ( V_7 <= ( V_55 + 1 ) * 4 )
return - V_4 ;
V_36 -> V_38 = F_15 ( sizeof( char * ) , V_55 , V_18 ) ;
if ( ! V_36 -> V_38 )
return - V_19 ;
for ( V_37 = 0 ; V_37 < V_55 ; V_37 ++ ) {
if ( V_7 < 4 )
return - V_4 ;
V_56 = F_5 ( * V_6 ++ ) ;
V_7 -= 4 ;
if ( V_56 <= 0 || V_56 > V_58 )
return - V_4 ;
if ( V_56 > V_7 )
return - V_4 ;
V_36 -> V_38 [ V_37 ] = F_16 ( V_56 + 1 , V_18 ) ;
if ( ! V_36 -> V_38 [ V_37 ] )
return - V_19 ;
memcpy ( V_36 -> V_38 [ V_37 ] , V_6 , V_56 ) ;
V_36 -> V_38 [ V_37 ] [ V_56 ] = 0 ;
V_56 = ( V_56 + 3 ) & ~ 3 ;
V_7 -= V_56 ;
V_6 += V_56 >> 2 ;
}
if ( V_7 < 4 )
return - V_4 ;
V_56 = F_5 ( * V_6 ++ ) ;
V_7 -= 4 ;
if ( V_56 <= 0 || V_56 > V_59 )
return - V_4 ;
if ( V_56 > V_7 )
return - V_4 ;
V_36 -> V_40 = F_16 ( V_56 + 1 , V_18 ) ;
if ( ! V_36 -> V_40 )
return - V_19 ;
memcpy ( V_36 -> V_40 , V_6 , V_56 ) ;
V_36 -> V_40 [ V_56 ] = 0 ;
V_56 = ( V_56 + 3 ) & ~ 3 ;
V_7 -= V_56 ;
V_6 += V_56 >> 2 ;
F_6 ( L_12 , V_36 -> V_38 [ 0 ] , V_36 -> V_40 ) ;
* V_53 = V_6 ;
* V_54 = V_7 ;
F_10 ( L_13 , V_7 ) ;
return 0 ;
}
static int F_17 ( struct V_41 * V_42 ,
T_2 V_60 ,
const T_1 * * V_53 ,
unsigned * V_54 )
{
const T_1 * V_6 = * V_53 ;
unsigned V_7 = * V_54 , V_61 ;
if ( V_7 <= 8 )
return - V_4 ;
F_4 ( L_14 ,
V_60 , F_5 ( V_6 [ 0 ] ) , F_5 ( V_6 [ 1 ] ) , V_7 ) ;
V_42 -> V_62 = F_5 ( * V_6 ++ ) ;
V_61 = F_5 ( * V_6 ++ ) ;
V_7 -= 8 ;
if ( V_61 > V_60 )
return - V_4 ;
V_42 -> V_63 = V_61 ;
if ( V_61 > 0 ) {
V_42 -> V_33 = F_16 ( V_61 , V_18 ) ;
if ( ! V_42 -> V_33 )
return - V_19 ;
memcpy ( V_42 -> V_33 , V_6 , V_61 ) ;
V_61 = ( V_61 + 3 ) & ~ 3 ;
V_7 -= V_61 ;
V_6 += V_61 >> 2 ;
}
F_6 ( L_15 , V_42 -> V_62 , V_42 -> V_63 ) ;
* V_53 = V_6 ;
* V_54 = V_7 ;
F_10 ( L_13 , V_7 ) ;
return 0 ;
}
static int F_18 ( struct V_41 * * V_64 ,
T_4 * V_65 ,
T_4 V_66 ,
T_2 V_67 ,
const T_1 * * V_53 ,
unsigned * V_54 )
{
struct V_41 * V_42 ;
const T_1 * V_6 = * V_53 ;
unsigned V_7 = * V_54 , V_68 , V_37 ;
int V_13 ;
if ( V_7 < 4 )
return - V_4 ;
F_4 ( L_16 ,
V_66 , V_67 , F_5 ( V_6 [ 0 ] ) , V_7 ) ;
V_68 = F_5 ( * V_6 ++ ) ;
V_7 -= 4 ;
if ( V_68 < 0 || V_68 > V_66 )
return - V_4 ;
* V_65 = V_68 ;
if ( V_68 > 0 ) {
if ( V_7 <= ( V_68 + 1 ) * 4 )
return - V_4 ;
F_6 ( L_17 , V_68 ) ;
V_42 = F_15 ( sizeof( struct V_41 ) , V_68 ,
V_18 ) ;
if ( ! V_42 )
return - V_19 ;
* V_64 = V_42 ;
for ( V_37 = 0 ; V_37 < V_68 ; V_37 ++ ) {
V_13 = F_17 ( & V_42 [ V_37 ] ,
V_67 ,
& V_6 , & V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
* V_53 = V_6 ;
* V_54 = V_7 ;
F_10 ( L_13 , V_7 ) ;
return 0 ;
}
static int F_19 ( T_4 * * V_69 , T_5 * V_70 ,
const T_1 * * V_53 , unsigned * V_54 )
{
const T_1 * V_6 = * V_53 ;
unsigned V_7 = * V_54 , V_61 ;
if ( V_7 <= 4 )
return - V_4 ;
F_4 ( L_18 , F_5 ( V_6 [ 0 ] ) , V_7 ) ;
V_61 = F_5 ( * V_6 ++ ) ;
V_7 -= 4 ;
if ( V_61 > V_71 )
return - V_4 ;
* V_70 = V_61 ;
F_6 ( L_19 , V_61 ) ;
if ( V_61 > 0 ) {
* V_69 = F_16 ( V_61 , V_18 ) ;
if ( ! * V_69 )
return - V_19 ;
memcpy ( * V_69 , V_6 , V_61 ) ;
V_61 = ( V_61 + 3 ) & ~ 3 ;
V_7 -= V_61 ;
V_6 += V_61 >> 2 ;
}
* V_53 = V_6 ;
* V_54 = V_7 ;
F_10 ( L_13 , V_7 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_5 , const T_1 * V_6 ,
unsigned V_7 )
{
struct V_8 * V_9 , * * V_10 ;
struct V_43 * V_44 ;
const T_1 * V_72 = V_6 + ( V_7 >> 2 ) ;
int V_13 ;
F_4 ( L_1 ,
F_5 ( V_6 [ 0 ] ) , F_5 ( V_6 [ 1 ] ) , F_5 ( V_6 [ 2 ] ) , F_5 ( V_6 [ 3 ] ) ,
V_7 ) ;
V_13 = F_7 ( V_5 , V_5 -> V_17 + V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
V_9 = F_8 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 )
return - V_19 ;
V_44 = F_8 ( sizeof( * V_44 ) , V_18 ) ;
if ( ! V_44 ) {
F_9 ( V_9 ) ;
return - V_19 ;
}
V_9 -> V_20 = V_73 ;
V_9 -> V_74 = V_44 ;
V_13 = F_14 ( & V_44 -> V_45 , & V_6 , & V_7 ) ;
if ( V_13 < 0 )
goto error;
V_13 = F_14 ( & V_44 -> V_46 , & V_6 , & V_7 ) ;
if ( V_13 < 0 )
goto error;
V_13 = F_17 ( & V_44 -> V_47 , V_75 ,
& V_6 , & V_7 ) ;
if ( V_13 < 0 )
goto error;
if ( V_7 < 4 * 8 + 2 * 4 )
goto V_76;
V_44 -> V_77 = F_21 ( ( const V_78 * ) V_6 ) ;
V_6 += 2 ;
V_44 -> V_79 = F_21 ( ( const V_78 * ) V_6 ) ;
V_6 += 2 ;
V_44 -> V_80 = F_21 ( ( const V_78 * ) V_6 ) ;
V_6 += 2 ;
V_44 -> V_81 = F_21 ( ( const V_78 * ) V_6 ) ;
V_6 += 2 ;
V_44 -> V_82 = F_5 ( * V_6 ++ ) ;
V_44 -> V_83 = F_5 ( * V_6 ++ ) ;
V_7 -= 4 * 8 + 2 * 4 ;
F_6 ( L_20 ,
V_44 -> V_77 , V_44 -> V_79 , V_44 -> V_80 ,
V_44 -> V_81 ) ;
F_6 ( L_21 , V_44 -> V_82 , V_44 -> V_83 ) ;
V_13 = F_18 ( & V_44 -> V_48 ,
& V_44 -> V_49 ,
V_84 ,
V_75 ,
& V_6 , & V_7 ) ;
if ( V_13 < 0 )
goto error;
F_22 ( ( V_72 - V_6 ) << 2 , == , V_7 ) ;
V_13 = F_19 ( & V_44 -> V_29 , & V_44 -> V_22 ,
& V_6 , & V_7 ) ;
if ( V_13 < 0 )
goto error;
V_13 = F_19 ( & V_44 -> V_52 , & V_44 -> V_85 ,
& V_6 , & V_7 ) ;
if ( V_13 < 0 )
goto error;
F_22 ( ( V_72 - V_6 ) << 2 , == , V_7 ) ;
V_13 = F_18 ( & V_44 -> V_50 ,
& V_44 -> V_51 ,
V_86 ,
V_87 ,
& V_6 , & V_7 ) ;
if ( V_13 < 0 )
goto error;
F_22 ( ( V_72 - V_6 ) << 2 , == , V_7 ) ;
if ( V_7 != 0 )
goto V_76;
for ( V_10 = (struct V_8 * * ) & V_5 -> V_32 . V_33 ;
* V_10 ;
V_10 = & ( * V_10 ) -> V_34 )
continue;
* V_10 = V_9 ;
if ( V_9 -> V_16 -> V_26 < V_5 -> V_26 )
V_5 -> V_26 = V_9 -> V_16 -> V_26 ;
F_10 ( L_10 ) ;
return 0 ;
V_76:
V_13 = - V_4 ;
error:
F_13 ( V_44 ) ;
F_9 ( V_9 ) ;
F_10 ( L_22 , V_13 ) ;
return V_13 ;
}
static int F_23 ( struct V_5 * V_5 , const void * V_33 , T_2 V_17 )
{
const T_1 * V_6 = V_33 , * V_9 ;
const char * V_88 ;
unsigned V_61 , V_56 , V_37 , V_89 , V_7 , V_90 ;
int V_13 ;
F_4 ( L_23 ,
F_5 ( V_6 [ 0 ] ) , F_5 ( V_6 [ 1 ] ) , F_5 ( V_6 [ 2 ] ) , F_5 ( V_6 [ 3 ] ) ,
V_17 ) ;
if ( V_17 > V_91 )
goto V_92;
if ( V_17 & 3 )
goto V_92;
if ( F_5 ( * V_6 ++ ) != 0 )
goto V_92;
V_17 -= 4 ;
V_61 = F_5 ( * V_6 ++ ) ;
if ( V_61 < 1 || V_61 > V_93 )
goto V_92;
V_17 -= 4 ;
V_56 = ( V_61 + 3 ) & ~ 3 ;
if ( V_56 > V_17 )
goto V_92;
V_88 = ( const char * ) V_6 ;
for ( V_37 = 0 ; V_37 < V_61 ; V_37 ++ )
if ( ! isprint ( V_88 [ V_37 ] ) )
goto V_92;
if ( V_61 < V_56 )
for (; V_37 < V_56 ; V_37 ++ )
if ( V_88 [ V_37 ] )
goto V_92;
F_6 ( L_24 ,
V_61 , V_56 , V_61 , V_61 , ( const char * ) V_6 ) ;
V_17 -= V_56 ;
V_6 += V_56 >> 2 ;
if ( V_17 < 12 )
goto V_92;
V_89 = F_5 ( * V_6 ++ ) ;
V_17 -= 4 ;
F_6 ( L_25 , V_89 ) ;
if ( V_89 < 1 || V_89 > V_94 )
goto V_92;
V_9 = V_6 ;
V_37 = V_89 ;
do {
if ( V_17 < 8 )
goto V_92;
V_7 = F_5 ( * V_6 ++ ) ;
V_90 = F_5 ( * V_6 ) ;
V_17 -= 4 ;
F_6 ( L_26 , V_7 , V_17 , V_90 ) ;
if ( V_7 < 20 || V_7 > V_17 )
goto V_92;
V_17 -= ( V_7 + 3 ) & ~ 3 ;
V_6 += ( V_7 + 3 ) >> 2 ;
} while ( -- V_37 > 0 );
F_6 ( L_27 , V_17 ) ;
if ( V_17 != 0 )
goto V_92;
do {
V_6 = V_9 ;
V_7 = F_5 ( * V_6 ++ ) ;
V_9 = V_6 + ( ( V_7 + 3 ) >> 2 ) ;
V_90 = F_5 ( * V_6 ++ ) ;
V_7 -= 4 ;
F_6 ( L_28 , V_90 , V_6 , V_9 ) ;
switch ( V_90 ) {
case V_21 :
V_13 = F_3 ( V_5 , V_6 , V_7 ) ;
if ( V_13 != 0 )
goto error;
break;
case V_73 :
V_13 = F_20 ( V_5 , V_6 , V_7 ) ;
if ( V_13 != 0 )
goto error;
break;
default:
V_13 = - V_95 ;
goto error;
}
} while ( -- V_89 > 0 );
F_10 ( L_10 ) ;
return 0 ;
V_92:
F_10 ( L_29 ) ;
return - V_96 ;
error:
F_10 ( L_22 , V_13 ) ;
return V_13 ;
}
static int F_24 ( struct V_5 * V_5 , const void * V_33 , T_2 V_17 )
{
const struct V_97 * V_98 ;
struct V_8 * V_9 , * * V_99 ;
T_2 V_11 ;
T_3 V_100 ;
int V_13 ;
F_4 ( L_30 , F_25 ( V_5 ) , V_17 ) ;
if ( ! V_33 && V_17 == 0 )
return 0 ;
if ( V_17 > 7 * 4 ) {
V_13 = F_23 ( V_5 , V_33 , V_17 ) ;
if ( V_13 != - V_96 )
return V_13 ;
}
V_13 = - V_4 ;
if ( V_17 <= 4 || ! V_33 )
goto error;
memcpy ( & V_100 , V_33 , sizeof( V_100 ) ) ;
V_33 += sizeof( V_100 ) ;
V_17 -= sizeof( V_100 ) ;
F_6 ( L_31 , V_100 ) ;
V_13 = - V_14 ;
if ( V_100 != 1 )
goto error;
V_13 = - V_4 ;
if ( V_17 < sizeof( * V_98 ) )
goto error;
V_98 = V_33 ;
if ( V_17 != sizeof( * V_98 ) + V_98 -> V_101 )
goto error;
F_6 ( L_3 , V_98 -> V_20 ) ;
F_6 ( L_4 , V_98 -> V_101 ) ;
F_6 ( L_5 , V_98 -> V_26 ) ;
F_6 ( L_6 , V_98 -> V_24 ) ;
F_6 ( L_8 ,
V_98 -> V_28 [ 0 ] , V_98 -> V_28 [ 1 ] ,
V_98 -> V_28 [ 2 ] , V_98 -> V_28 [ 3 ] ,
V_98 -> V_28 [ 4 ] , V_98 -> V_28 [ 5 ] ,
V_98 -> V_28 [ 6 ] , V_98 -> V_28 [ 7 ] ) ;
if ( V_98 -> V_101 >= 8 )
F_6 ( L_9 ,
V_98 -> V_29 [ 0 ] , V_98 -> V_29 [ 1 ] ,
V_98 -> V_29 [ 2 ] , V_98 -> V_29 [ 3 ] ,
V_98 -> V_29 [ 4 ] , V_98 -> V_29 [ 5 ] ,
V_98 -> V_29 [ 6 ] , V_98 -> V_29 [ 7 ] ) ;
V_13 = - V_95 ;
if ( V_98 -> V_20 != V_21 )
goto error;
V_11 = sizeof( * V_9 -> V_16 ) + V_98 -> V_101 ;
V_13 = F_7 ( V_5 , V_11 + sizeof( * V_9 ) ) ;
if ( V_13 < 0 )
goto error;
V_13 = - V_19 ;
V_9 = F_8 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 )
goto error;
V_9 -> V_16 = F_8 ( V_11 , V_18 ) ;
if ( ! V_9 -> V_16 )
goto V_102;
V_9 -> V_20 = V_21 ;
V_9 -> V_16 -> V_22 = V_98 -> V_101 ;
V_9 -> V_16 -> V_26 = V_98 -> V_26 ;
V_9 -> V_16 -> V_24 = V_98 -> V_24 ;
memcpy ( & V_9 -> V_16 -> V_28 , & V_98 -> V_28 , 8 ) ;
memcpy ( & V_9 -> V_16 -> V_29 , V_98 -> V_29 , V_98 -> V_101 ) ;
V_5 -> V_30 . V_31 [ 0 ] ++ ;
V_99 = (struct V_8 * * ) & V_5 -> V_32 . V_33 ;
while ( * V_99 )
V_99 = & ( * V_99 ) -> V_34 ;
* V_99 = V_9 ;
if ( V_9 -> V_16 -> V_26 < V_5 -> V_26 )
V_5 -> V_26 = V_9 -> V_16 -> V_26 ;
V_9 = NULL ;
V_13 = 0 ;
V_102:
F_9 ( V_9 ) ;
error:
return V_13 ;
}
static int F_26 ( struct V_5 * V_5 , const void * V_33 ,
T_2 V_17 )
{
struct V_103 * V_104 ;
F_4 ( L_30 , F_25 ( V_5 ) , V_17 ) ;
if ( V_17 != 8 )
return - V_4 ;
memcpy ( & V_5 -> V_30 , V_33 , 8 ) ;
V_104 = F_27 ( L_32 , 0 , V_105 ) ;
if ( F_28 ( V_104 ) ) {
F_10 ( L_33 , F_29 ( V_104 ) ) ;
return F_29 ( V_104 ) ;
}
if ( F_30 ( V_104 , V_33 , 8 ) < 0 )
F_31 () ;
V_5 -> V_32 . V_33 = V_104 ;
F_10 ( L_10 ) ;
return 0 ;
}
static void F_32 ( struct V_5 * V_5 )
{
struct V_8 * V_9 ;
while ( ( V_9 = V_5 -> V_32 . V_33 ) ) {
V_5 -> V_32 . V_33 = V_9 -> V_34 ;
switch ( V_9 -> V_20 ) {
case V_21 :
F_9 ( V_9 -> V_16 ) ;
break;
case V_73 :
if ( V_9 -> V_74 )
F_13 ( V_9 -> V_74 ) ;
break;
default:
F_33 ( V_106 L_34 ,
V_9 -> V_20 ) ;
F_31 () ;
}
F_9 ( V_9 ) ;
}
}
static void F_34 ( struct V_5 * V_5 )
{
if ( V_5 -> V_32 . V_33 ) {
F_35 ( V_5 -> V_32 . V_33 ) ;
V_5 -> V_32 . V_33 = NULL ;
}
}
static void F_36 ( const struct V_5 * V_5 , struct V_107 * V_108 )
{
F_37 ( V_108 , V_5 -> V_109 ) ;
}
int F_38 ( struct V_110 * V_111 , char T_6 * V_112 , int V_113 )
{
struct V_5 * V_5 ;
char * V_109 ;
F_4 ( L_35 ) ;
if ( V_113 <= 0 || V_113 > V_114 - 1 )
return - V_4 ;
V_109 = F_16 ( V_113 + 1 , V_18 ) ;
if ( ! V_109 )
return - V_19 ;
if ( F_39 ( V_109 , V_112 , V_113 ) ) {
F_9 ( V_109 ) ;
return - V_115 ;
}
V_109 [ V_113 ] = 0 ;
V_5 = F_40 ( & V_116 , V_109 , NULL ) ;
if ( F_28 ( V_5 ) ) {
F_9 ( V_109 ) ;
F_10 ( L_33 , F_29 ( V_5 ) ) ;
return F_29 ( V_5 ) ;
}
V_111 -> V_5 = V_5 ;
F_9 ( V_109 ) ;
F_10 ( L_36 , V_5 -> V_117 ) ;
return 0 ;
}
int F_41 ( struct V_110 * V_111 , char T_6 * V_112 ,
int V_113 )
{
struct V_5 * V_5 ;
char * V_109 ;
F_4 ( L_35 ) ;
if ( V_113 <= 0 || V_113 > V_114 - 1 )
return - V_4 ;
V_109 = F_16 ( V_113 + 1 , V_18 ) ;
if ( ! V_109 )
return - V_19 ;
if ( F_39 ( V_109 , V_112 , V_113 ) ) {
F_9 ( V_109 ) ;
return - V_115 ;
}
V_109 [ V_113 ] = 0 ;
V_5 = F_40 ( & V_118 , V_109 , NULL ) ;
if ( F_28 ( V_5 ) ) {
F_9 ( V_109 ) ;
F_10 ( L_33 , F_29 ( V_5 ) ) ;
return F_29 ( V_5 ) ;
}
V_111 -> V_119 = V_5 ;
F_9 ( V_109 ) ;
F_10 ( L_36 , V_5 -> V_117 ) ;
return 0 ;
}
int F_42 ( struct V_120 * V_121 ,
const void * V_28 ,
T_7 V_26 ,
T_3 V_24 )
{
const struct V_122 * V_122 = F_43 () ;
struct V_5 * V_5 ;
int V_13 ;
struct {
T_3 V_100 ;
struct V_97 V_98 ;
} V_33 ;
F_4 ( L_35 ) ;
V_5 = F_44 ( & V_116 , L_37 , 0 , 0 , V_122 , 0 ,
V_123 ) ;
if ( F_28 ( V_5 ) ) {
F_10 ( L_38 , F_29 ( V_5 ) ) ;
return - V_19 ;
}
F_6 ( L_39 , F_25 ( V_5 ) ) ;
V_33 . V_100 = 1 ;
V_33 . V_98 . V_20 = V_21 ;
V_33 . V_98 . V_101 = 0 ;
V_33 . V_98 . V_26 = V_26 ;
V_33 . V_98 . V_24 = 0 ;
memcpy ( & V_33 . V_98 . V_28 , V_28 , sizeof( V_33 . V_98 . V_28 ) ) ;
V_13 = F_45 ( V_5 , & V_33 , sizeof( V_33 ) , NULL , NULL ) ;
if ( V_13 < 0 )
goto error;
V_121 -> V_5 = V_5 ;
F_10 ( L_40 , F_25 ( V_5 ) ) ;
return 0 ;
error:
F_46 ( V_5 ) ;
F_47 ( V_5 ) ;
F_10 ( L_41 , V_13 ) ;
return - V_19 ;
}
struct V_5 * F_48 ( const char * V_124 )
{
const struct V_122 * V_122 = F_43 () ;
struct V_5 * V_5 ;
int V_13 ;
V_5 = F_44 ( & V_116 , V_124 , 0 , 0 , V_122 ,
V_125 , V_123 ) ;
if ( F_28 ( V_5 ) )
return V_5 ;
V_13 = F_45 ( V_5 , NULL , 0 , NULL , NULL ) ;
if ( V_13 < 0 ) {
F_46 ( V_5 ) ;
F_47 ( V_5 ) ;
return F_49 ( V_13 ) ;
}
return V_5 ;
}
static long F_50 ( const struct V_5 * V_5 ,
char T_6 * V_126 , T_2 V_127 )
{
const struct V_8 * V_9 ;
const struct V_35 * V_36 ;
T_2 V_128 ;
T_1 T_6 * V_6 , * V_129 ;
T_3 V_130 , V_131 , V_132 , V_133 , V_134 ;
T_5 V_135 [ V_94 ] ;
int V_37 ;
F_4 ( L_35 ) ;
if ( memcmp ( V_5 -> V_109 , L_42 , 4 ) != 0 )
return - V_136 ;
V_130 = strlen ( V_5 -> V_109 + 4 ) ;
#define F_51 ( T_8 ) (((X) + 3) & ~3)
V_128 = 2 * 4 ;
V_128 += F_51 ( V_130 ) ;
V_128 += 1 * 4 ;
V_132 = 0 ;
for ( V_9 = V_5 -> V_32 . V_33 ; V_9 ; V_9 = V_9 -> V_34 ) {
V_131 = 4 ;
switch ( V_9 -> V_20 ) {
case V_21 :
V_131 += 8 * 4 ;
V_131 += F_51 ( V_9 -> V_16 -> V_22 ) ;
break;
case V_73 :
V_36 = & V_9 -> V_74 -> V_45 ;
V_131 += 4 + V_36 -> V_39 * 4 ;
for ( V_37 = 0 ; V_37 < V_36 -> V_39 ; V_37 ++ )
V_131 += F_51 ( strlen ( V_36 -> V_38 [ V_37 ] ) ) ;
V_131 += 4 + F_51 ( strlen ( V_36 -> V_40 ) ) ;
V_36 = & V_9 -> V_74 -> V_46 ;
V_131 += 4 + V_36 -> V_39 * 4 ;
for ( V_37 = 0 ; V_37 < V_36 -> V_39 ; V_37 ++ )
V_131 += F_51 ( strlen ( V_36 -> V_38 [ V_37 ] ) ) ;
V_131 += 4 + F_51 ( strlen ( V_36 -> V_40 ) ) ;
V_131 += 8 + F_51 ( V_9 -> V_74 -> V_47 . V_63 ) ;
V_131 += 4 * 8 + 2 * 4 ;
V_131 += 4 + V_9 -> V_74 -> V_49 * 8 ;
for ( V_37 = 0 ; V_37 < V_9 -> V_74 -> V_49 ; V_37 ++ )
V_131 += F_51 ( V_9 -> V_74 -> V_48 [ V_37 ] . V_63 ) ;
V_131 += 4 + F_51 ( V_9 -> V_74 -> V_22 ) ;
V_131 += 4 + F_51 ( V_9 -> V_74 -> V_85 ) ;
V_131 += 4 + V_9 -> V_74 -> V_51 * 8 ;
for ( V_37 = 0 ; V_37 < V_9 -> V_74 -> V_51 ; V_37 ++ )
V_131 += F_51 ( V_9 -> V_74 -> V_50 [ V_37 ] . V_63 ) ;
break;
default:
F_31 () ;
continue;
}
F_6 ( L_43 , V_132 , V_131 ) ;
F_22 ( V_131 , <= , V_91 ) ;
V_135 [ V_132 ++ ] = V_131 ;
V_128 += V_131 + 4 ;
}
#undef F_51
if ( ! V_126 || V_127 < V_128 )
return V_128 ;
V_6 = ( T_1 T_6 * ) V_126 ;
V_134 = 0 ;
#define F_52 ( V_31 ) \
do { \
__be32 y = htonl(x); \
if (put_user(y, xdr++) < 0) \
goto fault; \
} while(0)
#define F_53 ( T_9 , T_10 ) \
do { \
u32 _l = (l); \
ENCODE(l); \
if (copy_to_user(xdr, (s), _l) != 0) \
goto fault; \
if (_l & 3 && \
copy_to_user((u8 *)xdr + _l, &zero, 4 - (_l & 3)) != 0) \
goto fault; \
xdr += (_l + 3) >> 2; \
} while(0)
#define F_54 ( V_31 ) \
do { \
__be64 y = cpu_to_be64(x); \
if (copy_to_user(xdr, &y, 8) != 0) \
goto fault; \
xdr += 8 >> 2; \
} while(0)
#define F_55 ( T_10 ) \
do { \
const char *_s = (s); \
ENCODE_DATA(strlen(_s), _s); \
} while(0)
F_52 ( 0 ) ;
F_53 ( V_130 , V_5 -> V_109 + 4 ) ;
F_52 ( V_132 ) ;
V_133 = 0 ;
for ( V_9 = V_5 -> V_32 . V_33 ; V_9 ; V_9 = V_9 -> V_34 ) {
V_131 = V_135 [ V_133 ++ ] ;
F_52 ( V_131 ) ;
V_129 = V_6 ;
F_52 ( V_9 -> V_20 ) ;
switch ( V_9 -> V_20 ) {
case V_21 :
F_52 ( V_9 -> V_16 -> V_23 ) ;
F_52 ( V_9 -> V_16 -> V_24 ) ;
F_53 ( 8 , V_9 -> V_16 -> V_28 ) ;
F_52 ( V_9 -> V_16 -> V_25 ) ;
F_52 ( V_9 -> V_16 -> V_26 ) ;
F_52 ( V_9 -> V_16 -> V_27 ) ;
F_53 ( V_9 -> V_16 -> V_22 , V_9 -> V_16 -> V_29 ) ;
break;
case V_73 :
V_36 = & V_9 -> V_74 -> V_45 ;
F_52 ( V_36 -> V_39 ) ;
for ( V_37 = 0 ; V_37 < V_36 -> V_39 ; V_37 ++ )
F_55 ( V_36 -> V_38 [ V_37 ] ) ;
F_55 ( V_36 -> V_40 ) ;
V_36 = & V_9 -> V_74 -> V_46 ;
F_52 ( V_36 -> V_39 ) ;
for ( V_37 = 0 ; V_37 < V_36 -> V_39 ; V_37 ++ )
F_55 ( V_36 -> V_38 [ V_37 ] ) ;
F_55 ( V_36 -> V_40 ) ;
F_52 ( V_9 -> V_74 -> V_47 . V_62 ) ;
F_53 ( V_9 -> V_74 -> V_47 . V_63 ,
V_9 -> V_74 -> V_47 . V_33 ) ;
F_54 ( V_9 -> V_74 -> V_77 ) ;
F_54 ( V_9 -> V_74 -> V_79 ) ;
F_54 ( V_9 -> V_74 -> V_80 ) ;
F_54 ( V_9 -> V_74 -> V_81 ) ;
F_52 ( V_9 -> V_74 -> V_82 ) ;
F_52 ( V_9 -> V_74 -> V_83 ) ;
F_52 ( V_9 -> V_74 -> V_49 ) ;
for ( V_37 = 0 ; V_37 < V_9 -> V_74 -> V_49 ; V_37 ++ ) {
F_52 ( V_9 -> V_74 -> V_48 [ V_37 ] . V_62 ) ;
F_53 ( V_9 -> V_74 -> V_48 [ V_37 ] . V_63 ,
V_9 -> V_74 -> V_48 [ V_37 ] . V_33 ) ;
}
F_53 ( V_9 -> V_74 -> V_22 , V_9 -> V_74 -> V_29 ) ;
F_53 ( V_9 -> V_74 -> V_85 , V_9 -> V_74 -> V_52 ) ;
F_52 ( V_9 -> V_74 -> V_51 ) ;
for ( V_37 = 0 ; V_37 < V_9 -> V_74 -> V_51 ; V_37 ++ ) {
F_52 ( V_9 -> V_74 -> V_50 [ V_37 ] . V_62 ) ;
F_53 ( V_9 -> V_74 -> V_50 [ V_37 ] . V_63 ,
V_9 -> V_74 -> V_50 [ V_37 ] . V_33 ) ;
}
break;
default:
F_31 () ;
break;
}
F_22 ( ( unsigned long ) V_6 - ( unsigned long ) V_129 , == ,
V_131 ) ;
}
#undef F_55
#undef F_53
#undef F_54
#undef F_52
F_22 ( V_133 , == , V_132 ) ;
F_22 ( ( char T_6 * ) V_6 - V_126 , == , V_128 ) ;
F_10 ( L_44 , V_128 ) ;
return V_128 ;
V_137:
F_10 ( L_45 ) ;
return - V_115 ;
}
