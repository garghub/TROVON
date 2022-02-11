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
unsigned int * V_15 = V_2 -> V_16 ;
if ( V_15 [ V_17 ] != V_13 [ V_17 ] )
goto V_18;
if ( V_15 [ V_19 ] < V_13 [ V_19 ] )
goto V_7;
else if ( V_15 [ V_19 ] > V_13 [ V_19 ] )
goto V_18;
if ( V_15 [ V_20 ] < V_13 [ V_20 ] )
goto V_7;
else if ( V_15 [ V_20 ] > V_13 [ V_20 ] )
goto V_18;
if ( V_15 [ V_21 ] < V_13 [ V_21 ] )
goto V_7;
else if ( V_15 [ V_21 ] > V_13 [ V_21 ] )
goto V_18;
if ( V_15 [ V_22 ] < V_13 [ V_22 ] )
goto V_7;
else if ( V_15 [ V_22 ] > V_13 [ V_22 ] )
goto V_18;
V_7:
return 0 ;
V_18:
F_8 ( L_3
L_4
L_5
L_6 ,
V_13 [ V_17 ] , V_13 [ V_19 ] ,
V_13 [ V_20 ] , V_13 [ V_21 ] ,
V_13 [ V_22 ] , V_15 [ V_17 ] ,
V_15 [ V_19 ] , V_15 [ V_20 ] ,
V_15 [ V_21 ] , V_15 [ V_22 ] ) ;
return - V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
T_2 V_23 = sizeof( * V_9 ) + V_2 -> V_24 ;
int V_5 ;
V_9 = F_10 ( V_23 , V_25 ) ;
if ( ! V_9 ) {
V_5 = - V_26 ;
goto V_7;
}
V_5 = F_11 ( V_2 , V_2 -> V_27 , V_9 , V_23 , false ) ;
if ( V_5 < 0 )
goto V_28;
V_5 = F_4 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
goto V_28;
V_5 = F_7 ( V_2 ) ;
if ( V_5 < 0 )
goto V_28;
V_5 = F_12 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
goto V_28;
V_28:
F_13 ( V_9 ) ;
V_7:
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_29 ,
T_2 V_30 , T_1 V_31 )
{
struct V_32 V_33 ;
int V_34 , V_35 , V_36 ;
T_3 * V_37 , * V_38 ;
int V_5 ;
F_15 ( V_39 , L_7 ) ;
F_15 ( V_39 , L_8 ,
V_30 , V_40 ) ;
if ( ( V_30 % 4 ) != 0 ) {
F_8 ( L_9 ) ;
return - V_41 ;
}
V_38 = F_10 ( V_40 , V_25 ) ;
if ( ! V_38 ) {
F_8 ( L_10 ) ;
return - V_26 ;
}
memcpy ( & V_33 , & V_2 -> V_42 [ V_43 ] , sizeof( V_33 ) ) ;
V_33 . V_44 . V_45 = V_31 ;
V_5 = F_16 ( V_2 , & V_33 ) ;
if ( V_5 < 0 )
goto V_7;
V_35 = 0 ;
V_36 = V_2 -> V_42 [ V_43 ] . V_44 . V_46 ;
while ( V_35 < V_30 / V_40 ) {
V_34 = V_31 + ( V_35 + 2 ) * V_40 ;
if ( V_34 > V_36 ) {
V_34 = V_31 + V_35 * V_40 ;
V_36 = V_35 * V_40 +
V_2 -> V_42 [ V_43 ] . V_44 . V_46 ;
V_33 . V_44 . V_45 = V_34 ;
V_5 = F_16 ( V_2 , & V_33 ) ;
if ( V_5 < 0 )
goto V_7;
}
V_34 = V_31 + V_35 * V_40 ;
V_37 = V_29 + V_35 * V_40 ;
memcpy ( V_38 , V_37 , V_40 ) ;
F_15 ( V_39 , L_11 ,
V_37 , V_34 ) ;
V_5 = F_17 ( V_2 , V_34 , V_38 , V_40 , false ) ;
if ( V_5 < 0 )
goto V_7;
V_35 ++ ;
}
V_34 = V_31 + V_35 * V_40 ;
V_37 = V_29 + V_35 * V_40 ;
memcpy ( V_38 , V_37 , V_30 % V_40 ) ;
F_15 ( V_39 , L_12 ,
V_30 % V_40 , V_37 , V_34 ) ;
V_5 = F_17 ( V_2 , V_34 , V_38 , V_30 % V_40 , false ) ;
V_7:
F_13 ( V_38 ) ;
return V_5 ;
}
int F_18 ( struct V_1 * V_2 )
{
T_1 V_47 , V_34 , V_23 ;
int V_5 = 0 ;
T_3 * V_48 ;
V_48 = V_2 -> V_48 ;
V_47 = F_19 ( ( V_49 * ) V_48 ) ;
V_48 += sizeof( T_1 ) ;
F_15 ( V_39 , L_13 , V_47 ) ;
while ( V_47 -- ) {
V_34 = F_19 ( ( V_49 * ) V_48 ) ;
V_48 += sizeof( T_1 ) ;
V_23 = F_19 ( ( V_49 * ) V_48 ) ;
V_48 += sizeof( T_1 ) ;
if ( V_23 > 300000 ) {
F_20 ( L_14 , V_23 ) ;
return - V_14 ;
}
F_15 ( V_39 , L_15 ,
V_47 , V_34 , V_23 ) ;
V_5 = F_14 ( V_2 , V_48 , V_23 , V_34 ) ;
if ( V_5 != 0 )
break;
V_48 += V_23 ;
}
return V_5 ;
}
int F_21 ( struct V_1 * V_2 )
{
T_2 V_50 , V_51 ;
int V_52 ;
T_1 V_53 , V_54 ;
T_3 * V_55 , * V_56 ;
int V_5 ;
if ( V_2 -> V_57 == NULL ) {
F_8 ( L_16 ) ;
return - V_58 ;
}
if ( V_2 -> V_59 & V_60 ) {
struct V_61 * V_57 =
(struct V_61 * ) V_2 -> V_57 ;
if ( V_2 -> V_50 == sizeof( struct V_61 ) ||
V_2 -> V_50 == V_62 ) {
if ( V_57 -> V_63 . V_64 )
V_2 -> V_65 = true ;
}
if ( V_2 -> V_50 != sizeof( struct V_61 ) &&
( V_2 -> V_50 != V_62 ||
V_2 -> V_65 ) ) {
F_8 ( L_17 ,
V_2 -> V_50 , sizeof( struct V_61 ) ) ;
F_13 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_50 = 0 ;
return - V_66 ;
}
V_50 = sizeof( V_57 -> V_57 ) ;
V_55 = ( T_3 * ) V_57 -> V_57 ;
} else {
struct V_67 * V_57 = (struct V_67 * ) V_2 -> V_57 ;
if ( V_2 -> V_50 == sizeof( struct V_67 ) ) {
if ( V_57 -> V_63 . V_64 )
V_2 -> V_65 = true ;
} else {
F_8 ( L_17 ,
V_2 -> V_50 ,
sizeof( struct V_67 ) ) ;
F_13 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_50 = 0 ;
return - V_66 ;
}
V_50 = sizeof( V_57 -> V_57 ) ;
V_55 = ( T_3 * ) V_57 -> V_57 ;
}
V_55 [ 11 ] = V_2 -> V_68 [ 0 ] . V_34 [ 0 ] ;
V_55 [ 10 ] = V_2 -> V_68 [ 0 ] . V_34 [ 1 ] ;
V_55 [ 6 ] = V_2 -> V_68 [ 0 ] . V_34 [ 2 ] ;
V_55 [ 5 ] = V_2 -> V_68 [ 0 ] . V_34 [ 3 ] ;
V_55 [ 4 ] = V_2 -> V_68 [ 0 ] . V_34 [ 4 ] ;
V_55 [ 3 ] = V_2 -> V_68 [ 0 ] . V_34 [ 5 ] ;
while ( V_55 [ 0 ] ) {
V_51 = V_55 [ 0 ] ;
V_53 = ( V_55 [ 1 ] & 0xfe ) | ( ( T_1 ) ( V_55 [ 2 ] << 8 ) ) ;
V_53 += V_2 -> V_69 . V_70 . V_45 ;
V_55 += 3 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
if ( V_55 + 3 >= ( T_3 * ) V_2 -> V_57 + V_50 )
goto V_71;
V_54 = ( V_55 [ 0 ] | ( V_55 [ 1 ] << 8 )
| ( V_55 [ 2 ] << 16 ) | ( V_55 [ 3 ] << 24 ) ) ;
F_15 ( V_39 ,
L_18 ,
V_53 , V_54 ) ;
V_5 = F_22 ( V_2 , V_53 , V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
V_55 += 4 ;
V_53 += 4 ;
}
if ( V_55 >= ( T_3 * ) V_2 -> V_57 + V_50 )
goto V_71;
}
V_55 = ( T_3 * ) V_2 -> V_57 +
F_23 ( V_55 - ( T_3 * ) V_2 -> V_57 + 7 , 4 ) ;
if ( V_55 >= ( T_3 * ) V_2 -> V_57 + V_50 )
goto V_71;
V_50 -= V_55 - ( T_3 * ) V_2 -> V_57 ;
V_5 = F_16 ( V_2 , & V_2 -> V_42 [ V_72 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_56 = F_24 ( V_55 , V_50 , V_25 ) ;
if ( ! V_56 )
return - V_26 ;
V_5 = F_25 ( V_2 , V_73 , V_56 , V_50 ,
false ) ;
F_13 ( V_56 ) ;
return V_5 ;
V_71:
F_8 ( L_19 ) ;
return - V_66 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_74 , V_5 ;
T_1 V_75 , V_76 ;
V_5 = F_16 ( V_2 , & V_2 -> V_42 [ V_77 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_78 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 , V_79 , & V_75 ) ;
if ( V_5 < 0 )
return V_5 ;
F_15 ( V_39 , L_20 , V_75 ) ;
if ( V_75 != V_2 -> V_10 . V_80 ) {
F_8 ( L_21 ) ;
return - V_41 ;
}
V_74 = 0 ;
while ( V_74 ++ < V_81 ) {
F_27 ( V_82 ) ;
V_5 = F_2 ( V_2 , V_83 , & V_76 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_76 == 0xffffffff ) {
F_8 ( L_22
L_23 ) ;
return - V_41 ;
}
else if ( V_76 & V_84 ) {
V_5 = F_3 ( V_2 , V_85 ,
V_84 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
}
}
if ( V_74 > V_81 ) {
F_8 ( L_24
L_25 ) ;
return - V_41 ;
}
V_5 = F_2 ( V_2 , V_86 , & V_2 -> V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
F_15 ( V_87 , L_26 , V_2 -> V_27 ) ;
V_5 = F_2 ( V_2 , V_88 , & V_2 -> V_89 [ 0 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_89 [ 1 ] = V_2 -> V_89 [ 0 ] + sizeof( struct V_90 ) ;
F_15 ( V_87 , L_27 ,
V_2 -> V_89 [ 0 ] , V_2 -> V_89 [ 1 ] ) ;
V_5 = F_9 ( V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( L_28 ) ;
return V_5 ;
}
V_2 -> V_91 = V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 |
V_106 |
V_107 ;
V_5 = F_28 ( V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( L_29 ) ;
return V_5 ;
}
V_5 = F_16 ( V_2 , & V_2 -> V_42 [ V_72 ] ) ;
return V_5 ;
}
