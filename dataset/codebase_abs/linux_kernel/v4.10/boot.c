static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 , V_6 , & V_4 ) ;
if ( V_5 < 0 )
goto V_7;
V_4 |= V_3 ;
V_5 = F_3 ( V_2 , V_6 , V_4 ) ;
V_7:
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_5 ;
strncpy ( V_2 -> V_10 . V_11 , V_9 -> V_12 ,
sizeof( V_2 -> V_10 . V_11 ) ) ;
V_2 -> V_10 . V_11 [ sizeof( V_2 -> V_10 . V_11 ) - 1 ] = '\0' ;
V_5 = sscanf ( V_2 -> V_10 . V_11 + 4 , L_1 ,
& V_2 -> V_10 . V_13 [ 0 ] , & V_2 -> V_10 . V_13 [ 1 ] ,
& V_2 -> V_10 . V_13 [ 2 ] , & V_2 -> V_10 . V_13 [ 3 ] ,
& V_2 -> V_10 . V_13 [ 4 ] ) ;
if ( V_5 != 5 ) {
F_5 ( L_2 ) ;
memset ( V_2 -> V_10 . V_13 , 0 , sizeof( V_2 -> V_10 . V_13 ) ) ;
V_5 = - V_14 ;
goto V_7;
}
V_5 = F_6 ( V_2 ) ;
if ( V_5 < 0 )
goto V_7;
V_7:
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned int * V_13 = V_2 -> V_10 . V_13 ;
unsigned int * V_15 = ( V_2 -> V_16 == V_17 ) ?
V_2 -> V_18 : V_2 -> V_19 ;
char V_20 [ 32 ] = L_3 ;
int V_21 ;
if ( ( V_15 [ V_22 ] != V_23 ) &&
( V_15 [ V_22 ] != V_13 [ V_22 ] ) )
goto V_24;
if ( ( V_15 [ V_25 ] != V_23 ) &&
( V_15 [ V_25 ] != V_13 [ V_25 ] ) )
goto V_24;
if ( ( V_15 [ V_26 ] != V_23 ) &&
( V_15 [ V_26 ] != V_13 [ V_26 ] ) )
goto V_24;
if ( ( V_15 [ V_27 ] != V_23 ) &&
( V_15 [ V_27 ] > V_13 [ V_27 ] ) )
goto V_24;
if ( ( ( V_15 [ V_27 ] == V_23 ) ||
( V_15 [ V_27 ] == V_13 [ V_27 ] ) ) &&
( ( V_15 [ V_28 ] != V_23 ) &&
( V_15 [ V_28 ] > V_13 [ V_28 ] ) ) )
goto V_24;
return 0 ;
V_24:
for ( V_21 = 0 ; V_21 < V_29 ; V_21 ++ )
if ( V_15 [ V_21 ] == V_23 )
snprintf ( V_20 , sizeof( V_20 ) ,
L_4 , V_20 ) ;
else
snprintf ( V_20 , sizeof( V_20 ) ,
L_5 , V_20 , V_15 [ V_21 ] ) ;
F_8 ( L_6
L_7
L_8
L_9 ,
V_13 [ V_22 ] , V_13 [ V_25 ] ,
V_13 [ V_27 ] , V_13 [ V_26 ] ,
V_13 [ V_28 ] , V_20 ) ;
return - V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
T_2 V_30 = sizeof( * V_9 ) + V_2 -> V_31 ;
int V_5 ;
V_9 = F_10 ( V_30 , V_32 ) ;
if ( ! V_9 ) {
V_5 = - V_33 ;
goto V_7;
}
V_5 = F_11 ( V_2 , V_2 -> V_34 , V_9 , V_30 , false ) ;
if ( V_5 < 0 )
goto V_35;
V_5 = F_4 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
goto V_35;
V_5 = F_7 ( V_2 ) ;
if ( V_5 < 0 )
goto V_35;
V_5 = F_12 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
goto V_35;
V_35:
F_13 ( V_9 ) ;
V_7:
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_36 ,
T_2 V_37 , T_1 V_38 )
{
struct V_39 V_40 ;
int V_41 , V_42 , V_43 ;
T_3 * V_44 , * V_45 ;
int V_5 ;
F_15 ( V_46 , L_10 ) ;
F_15 ( V_46 , L_11 ,
V_37 , V_47 ) ;
if ( ( V_37 % 4 ) != 0 ) {
F_8 ( L_12 ) ;
return - V_48 ;
}
V_45 = F_10 ( V_47 , V_32 ) ;
if ( ! V_45 ) {
F_8 ( L_13 ) ;
return - V_33 ;
}
memcpy ( & V_40 , & V_2 -> V_49 [ V_50 ] , sizeof( V_40 ) ) ;
V_40 . V_51 . V_52 = V_38 ;
V_5 = F_16 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
goto V_7;
V_42 = 0 ;
V_43 = V_2 -> V_49 [ V_50 ] . V_51 . V_53 ;
while ( V_42 < V_37 / V_47 ) {
V_41 = V_38 + ( V_42 + 2 ) * V_47 ;
if ( V_41 > V_43 ) {
V_41 = V_38 + V_42 * V_47 ;
V_43 = V_42 * V_47 +
V_2 -> V_49 [ V_50 ] . V_51 . V_53 ;
V_40 . V_51 . V_52 = V_41 ;
V_5 = F_16 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
goto V_7;
}
V_41 = V_38 + V_42 * V_47 ;
V_44 = V_36 + V_42 * V_47 ;
memcpy ( V_45 , V_44 , V_47 ) ;
F_15 ( V_46 , L_14 ,
V_44 , V_41 ) ;
V_5 = F_17 ( V_2 , V_41 , V_45 , V_47 , false ) ;
if ( V_5 < 0 )
goto V_7;
V_42 ++ ;
}
V_41 = V_38 + V_42 * V_47 ;
V_44 = V_36 + V_42 * V_47 ;
memcpy ( V_45 , V_44 , V_37 % V_47 ) ;
F_15 ( V_46 , L_15 ,
V_37 % V_47 , V_44 , V_41 ) ;
V_5 = F_17 ( V_2 , V_41 , V_45 , V_37 % V_47 , false ) ;
V_7:
F_13 ( V_45 ) ;
return V_5 ;
}
int F_18 ( struct V_1 * V_2 )
{
T_1 V_54 , V_41 , V_30 ;
int V_5 = 0 ;
T_3 * V_55 ;
V_55 = V_2 -> V_55 ;
V_54 = F_19 ( ( V_56 * ) V_55 ) ;
V_55 += sizeof( T_1 ) ;
F_15 ( V_46 , L_16 , V_54 ) ;
while ( V_54 -- ) {
V_41 = F_19 ( ( V_56 * ) V_55 ) ;
V_55 += sizeof( T_1 ) ;
V_30 = F_19 ( ( V_56 * ) V_55 ) ;
V_55 += sizeof( T_1 ) ;
if ( V_30 > 300000 ) {
F_20 ( L_17 , V_30 ) ;
return - V_14 ;
}
F_15 ( V_46 , L_18 ,
V_54 , V_41 , V_30 ) ;
V_5 = F_14 ( V_2 , V_55 , V_30 , V_41 ) ;
if ( V_5 != 0 )
break;
V_55 += V_30 ;
}
return V_5 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = V_2 -> V_58 ;
struct V_59 * V_60 = F_22 ( & V_58 -> V_61 ) ;
const char * V_62 = L_19 ;
T_2 V_63 , V_64 ;
int V_21 ;
T_1 V_65 , V_66 ;
T_3 * V_67 , * V_68 ;
int V_5 ;
if ( V_2 -> V_69 == NULL ) {
F_8 ( L_20 ) ;
return - V_70 ;
}
if ( V_60 && V_60 -> V_71 )
V_62 = V_60 -> V_71 -> V_62 ;
if ( V_2 -> V_72 & V_73 ) {
struct V_74 * V_69 =
(struct V_74 * ) V_2 -> V_69 ;
if ( V_2 -> V_63 == sizeof( struct V_74 ) ||
V_2 -> V_63 == V_75 ) {
if ( V_69 -> V_76 . V_77 )
V_2 -> V_78 = true ;
}
if ( V_2 -> V_63 != sizeof( struct V_74 ) &&
( V_2 -> V_63 != V_75 ||
V_2 -> V_78 ) ) {
F_8 ( L_21 ,
V_62 , V_2 -> V_63 ,
sizeof( struct V_74 ) ) ;
F_13 ( V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
V_2 -> V_63 = 0 ;
return - V_79 ;
}
V_63 = sizeof( V_69 -> V_69 ) ;
V_67 = ( T_3 * ) V_69 -> V_69 ;
} else {
struct V_80 * V_69 = (struct V_80 * ) V_2 -> V_69 ;
if ( V_2 -> V_63 == sizeof( struct V_80 ) ) {
if ( V_69 -> V_76 . V_77 )
V_2 -> V_78 = true ;
} else {
F_8 ( L_21 ,
V_62 , V_2 -> V_63 ,
sizeof( struct V_80 ) ) ;
F_13 ( V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
V_2 -> V_63 = 0 ;
return - V_79 ;
}
V_63 = sizeof( V_69 -> V_69 ) ;
V_67 = ( T_3 * ) V_69 -> V_69 ;
}
V_67 [ 11 ] = V_2 -> V_81 [ 0 ] . V_41 [ 0 ] ;
V_67 [ 10 ] = V_2 -> V_81 [ 0 ] . V_41 [ 1 ] ;
V_67 [ 6 ] = V_2 -> V_81 [ 0 ] . V_41 [ 2 ] ;
V_67 [ 5 ] = V_2 -> V_81 [ 0 ] . V_41 [ 3 ] ;
V_67 [ 4 ] = V_2 -> V_81 [ 0 ] . V_41 [ 4 ] ;
V_67 [ 3 ] = V_2 -> V_81 [ 0 ] . V_41 [ 5 ] ;
while ( V_67 [ 0 ] ) {
V_64 = V_67 [ 0 ] ;
V_65 = ( V_67 [ 1 ] & 0xfe ) | ( ( T_1 ) ( V_67 [ 2 ] << 8 ) ) ;
V_65 += V_2 -> V_82 . V_83 . V_52 ;
V_67 += 3 ;
for ( V_21 = 0 ; V_21 < V_64 ; V_21 ++ ) {
if ( V_67 + 3 >= ( T_3 * ) V_2 -> V_69 + V_63 )
goto V_84;
V_66 = ( V_67 [ 0 ] | ( V_67 [ 1 ] << 8 )
| ( V_67 [ 2 ] << 16 ) | ( V_67 [ 3 ] << 24 ) ) ;
F_15 ( V_46 ,
L_22 ,
V_65 , V_66 ) ;
V_5 = F_23 ( V_2 , V_65 , V_66 ) ;
if ( V_5 < 0 )
return V_5 ;
V_67 += 4 ;
V_65 += 4 ;
}
if ( V_67 >= ( T_3 * ) V_2 -> V_69 + V_63 )
goto V_84;
}
V_67 = ( T_3 * ) V_2 -> V_69 +
F_24 ( V_67 - ( T_3 * ) V_2 -> V_69 + 7 , 4 ) ;
if ( V_67 >= ( T_3 * ) V_2 -> V_69 + V_63 )
goto V_84;
V_63 -= V_67 - ( T_3 * ) V_2 -> V_69 ;
V_5 = F_16 ( V_2 , & V_2 -> V_49 [ V_85 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_68 = F_25 ( V_67 , V_63 , V_32 ) ;
if ( ! V_68 )
return - V_33 ;
V_5 = F_26 ( V_2 , V_86 , V_68 , V_63 ,
false ) ;
F_13 ( V_68 ) ;
return V_5 ;
V_84:
F_8 ( L_23 ) ;
return - V_79 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_87 , V_5 ;
T_1 V_88 , V_89 ;
V_5 = F_16 ( V_2 , & V_2 -> V_49 [ V_90 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_91 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 , V_92 , & V_88 ) ;
if ( V_5 < 0 )
return V_5 ;
F_15 ( V_46 , L_24 , V_88 ) ;
if ( V_88 != V_2 -> V_10 . V_93 ) {
F_8 ( L_25 ) ;
return - V_48 ;
}
V_87 = 0 ;
while ( V_87 ++ < V_94 ) {
F_28 ( V_95 ) ;
V_5 = F_2 ( V_2 , V_96 , & V_89 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_89 == 0xffffffff ) {
F_8 ( L_26
L_27 ) ;
return - V_48 ;
}
else if ( V_89 & V_97 ) {
V_5 = F_3 ( V_2 , V_98 ,
V_97 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
}
}
if ( V_87 > V_94 ) {
F_8 ( L_28
L_29 ) ;
return - V_48 ;
}
V_5 = F_2 ( V_2 , V_99 , & V_2 -> V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
F_15 ( V_100 , L_30 , V_2 -> V_34 ) ;
V_5 = F_2 ( V_2 , V_101 , & V_2 -> V_102 [ 0 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_102 [ 1 ] = V_2 -> V_102 [ 0 ] + V_2 -> V_103 ;
F_15 ( V_100 , L_31 ,
V_2 -> V_102 [ 0 ] , V_2 -> V_102 [ 1 ] ) ;
V_5 = F_9 ( V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( L_32 ) ;
return V_5 ;
}
V_5 = F_29 ( V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( L_33 ) ;
return V_5 ;
}
V_5 = F_16 ( V_2 , & V_2 -> V_49 [ V_85 ] ) ;
return V_5 ;
}
