static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 |= V_3 ;
F_3 ( V_2 , V_5 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = sscanf ( V_2 -> V_7 . V_8 + 4 , L_1 ,
& V_2 -> V_7 . V_9 [ 0 ] , & V_2 -> V_7 . V_9 [ 1 ] ,
& V_2 -> V_7 . V_9 [ 2 ] , & V_2 -> V_7 . V_9 [ 3 ] ,
& V_2 -> V_7 . V_9 [ 4 ] ) ;
if ( V_6 != 5 ) {
F_5 ( L_2 ) ;
memset ( V_2 -> V_7 . V_9 , 0 , sizeof( V_2 -> V_7 . V_9 ) ) ;
return - V_10 ;
}
V_6 = F_6 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_6 ;
V_12 = F_8 ( sizeof( * V_12 ) , V_13 | V_14 ) ;
if ( ! V_12 ) {
F_9 ( L_3 ) ;
return - V_15 ;
}
F_10 ( V_2 , V_2 -> V_16 , V_12 , sizeof( * V_12 ) ,
false ) ;
strncpy ( V_2 -> V_7 . V_8 , V_12 -> V_17 ,
sizeof( V_2 -> V_7 . V_8 ) ) ;
F_11 ( V_12 ) ;
V_2 -> V_7 . V_8 [ sizeof( V_2 -> V_7 . V_8 ) - 1 ] = '\0' ;
V_6 = F_4 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_18 ,
T_2 V_19 , T_1 V_20 )
{
struct V_21 V_22 ;
int V_23 , V_24 , V_25 ;
T_3 * V_26 , * V_27 ;
F_13 ( V_28 , L_4 ) ;
F_13 ( V_28 , L_5 ,
V_19 , V_29 ) ;
if ( ( V_19 % 4 ) != 0 ) {
F_9 ( L_6 ) ;
return - V_30 ;
}
V_27 = F_8 ( V_29 , V_13 ) ;
if ( ! V_27 ) {
F_9 ( L_7 ) ;
return - V_15 ;
}
memcpy ( & V_22 , & V_2 -> V_31 [ V_32 ] , sizeof( V_22 ) ) ;
V_22 . V_33 . V_34 = V_20 ;
F_14 ( V_2 , & V_22 ) ;
V_24 = 0 ;
V_25 = V_2 -> V_31 [ V_32 ] . V_33 . V_35 ;
while ( V_24 < V_19 / V_29 ) {
V_23 = V_20 + ( V_24 + 2 ) * V_29 ;
if ( V_23 > V_25 ) {
V_23 = V_20 + V_24 * V_29 ;
V_25 = V_24 * V_29 +
V_2 -> V_31 [ V_32 ] . V_33 . V_35 ;
V_22 . V_33 . V_34 = V_23 ;
F_14 ( V_2 , & V_22 ) ;
}
V_23 = V_20 + V_24 * V_29 ;
V_26 = V_18 + V_24 * V_29 ;
memcpy ( V_27 , V_26 , V_29 ) ;
F_13 ( V_28 , L_8 ,
V_26 , V_23 ) ;
F_15 ( V_2 , V_23 , V_27 , V_29 , false ) ;
V_24 ++ ;
}
V_23 = V_20 + V_24 * V_29 ;
V_26 = V_18 + V_24 * V_29 ;
memcpy ( V_27 , V_26 , V_19 % V_29 ) ;
F_13 ( V_28 , L_9 ,
V_19 % V_29 , V_26 , V_23 ) ;
F_15 ( V_2 , V_23 , V_27 , V_19 % V_29 , false ) ;
F_11 ( V_27 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
T_1 V_36 , V_23 , V_37 ;
int V_6 = 0 ;
T_3 * V_38 ;
V_38 = V_2 -> V_38 ;
V_36 = F_17 ( ( V_39 * ) V_38 ) ;
V_38 += sizeof( T_1 ) ;
F_13 ( V_28 , L_10 , V_36 ) ;
while ( V_36 -- ) {
V_23 = F_17 ( ( V_39 * ) V_38 ) ;
V_38 += sizeof( T_1 ) ;
V_37 = F_17 ( ( V_39 * ) V_38 ) ;
V_38 += sizeof( T_1 ) ;
if ( V_37 > 300000 ) {
F_18 ( L_11 , V_37 ) ;
return - V_10 ;
}
F_13 ( V_28 , L_12 ,
V_36 , V_23 , V_37 ) ;
V_6 = F_12 ( V_2 , V_38 , V_37 , V_23 ) ;
if ( V_6 != 0 )
break;
V_38 += V_37 ;
}
return V_6 ;
}
int F_19 ( struct V_1 * V_2 )
{
T_2 V_40 , V_41 ;
int V_42 ;
T_1 V_43 , V_44 ;
T_3 * V_45 , * V_46 ;
if ( V_2 -> V_47 == NULL )
return - V_48 ;
if ( V_2 -> V_49 & V_50 ) {
struct V_51 * V_47 =
(struct V_51 * ) V_2 -> V_47 ;
if ( V_2 -> V_40 == sizeof( struct V_51 ) ||
V_2 -> V_40 == V_52 ) {
if ( V_47 -> V_53 . V_54 )
V_2 -> V_55 = true ;
}
if ( V_2 -> V_40 != sizeof( struct V_51 ) &&
( V_2 -> V_40 != V_52 ||
V_2 -> V_55 ) ) {
F_9 ( L_13 ,
V_2 -> V_40 , sizeof( struct V_51 ) ) ;
F_11 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
V_2 -> V_40 = 0 ;
return - V_56 ;
}
V_40 = sizeof( V_47 -> V_47 ) ;
V_45 = ( T_3 * ) V_47 -> V_47 ;
} else {
struct V_57 * V_47 = (struct V_57 * ) V_2 -> V_47 ;
if ( V_2 -> V_40 == sizeof( struct V_57 ) ) {
if ( V_47 -> V_53 . V_54 )
V_2 -> V_55 = true ;
} else {
F_9 ( L_13 ,
V_2 -> V_40 ,
sizeof( struct V_57 ) ) ;
F_11 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
V_2 -> V_40 = 0 ;
return - V_56 ;
}
V_40 = sizeof( V_47 -> V_47 ) ;
V_45 = ( T_3 * ) V_47 -> V_47 ;
}
V_45 [ 11 ] = V_2 -> V_58 [ 0 ] . V_23 [ 0 ] ;
V_45 [ 10 ] = V_2 -> V_58 [ 0 ] . V_23 [ 1 ] ;
V_45 [ 6 ] = V_2 -> V_58 [ 0 ] . V_23 [ 2 ] ;
V_45 [ 5 ] = V_2 -> V_58 [ 0 ] . V_23 [ 3 ] ;
V_45 [ 4 ] = V_2 -> V_58 [ 0 ] . V_23 [ 4 ] ;
V_45 [ 3 ] = V_2 -> V_58 [ 0 ] . V_23 [ 5 ] ;
while ( V_45 [ 0 ] ) {
V_41 = V_45 [ 0 ] ;
V_43 = ( V_45 [ 1 ] & 0xfe ) | ( ( T_1 ) ( V_45 [ 2 ] << 8 ) ) ;
V_43 += V_2 -> V_59 . V_60 . V_34 ;
V_45 += 3 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
if ( V_45 + 3 >= ( T_3 * ) V_2 -> V_47 + V_40 )
goto V_61;
V_44 = ( V_45 [ 0 ] | ( V_45 [ 1 ] << 8 )
| ( V_45 [ 2 ] << 16 ) | ( V_45 [ 3 ] << 24 ) ) ;
F_13 ( V_28 ,
L_14 ,
V_43 , V_44 ) ;
F_20 ( V_2 , V_43 , V_44 ) ;
V_45 += 4 ;
V_43 += 4 ;
}
if ( V_45 >= ( T_3 * ) V_2 -> V_47 + V_40 )
goto V_61;
}
V_45 = ( T_3 * ) V_2 -> V_47 +
F_21 ( V_45 - ( T_3 * ) V_2 -> V_47 + 7 , 4 ) ;
if ( V_45 >= ( T_3 * ) V_2 -> V_47 + V_40 )
goto V_61;
V_40 -= V_45 - ( T_3 * ) V_2 -> V_47 ;
F_14 ( V_2 , & V_2 -> V_31 [ V_62 ] ) ;
V_46 = F_22 ( V_45 , V_40 , V_13 ) ;
if ( ! V_46 )
return - V_15 ;
F_23 ( V_2 , V_63 ,
V_46 , V_40 , false ) ;
F_11 ( V_46 ) ;
return 0 ;
V_61:
F_9 ( L_15 ) ;
return - V_56 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_64 , V_6 ;
T_1 V_65 , V_66 ;
F_14 ( V_2 , & V_2 -> V_31 [ V_67 ] ) ;
F_1 ( V_2 , V_68 ) ;
V_65 = F_2 ( V_2 , V_69 ) ;
F_13 ( V_28 , L_16 , V_65 ) ;
if ( V_65 != V_2 -> V_7 . V_70 ) {
F_9 ( L_17 ) ;
return - V_30 ;
}
V_64 = 0 ;
while ( V_64 ++ < V_71 ) {
F_25 ( V_72 ) ;
V_66 = F_2 ( V_2 , V_73 ) ;
if ( V_66 == 0xffffffff ) {
F_9 ( L_18
L_19 ) ;
return - V_30 ;
}
else if ( V_66 & V_74 ) {
F_3 ( V_2 , V_75 ,
V_74 ) ;
break;
}
}
if ( V_64 > V_71 ) {
F_9 ( L_20
L_21 ) ;
return - V_30 ;
}
V_2 -> V_16 = F_2 ( V_2 , V_76 ) ;
F_13 ( V_77 , L_22 , V_2 -> V_16 ) ;
V_2 -> V_78 [ 0 ] = F_2 ( V_2 , V_79 ) ;
V_2 -> V_78 [ 1 ] = V_2 -> V_78 [ 0 ] + sizeof( struct V_80 ) ;
F_13 ( V_77 , L_23 ,
V_2 -> V_78 [ 0 ] , V_2 -> V_78 [ 1 ] ) ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( L_24 ) ;
return V_6 ;
}
V_2 -> V_81 = V_82 |
V_83 |
V_84 |
V_85 |
V_86 |
V_87 |
V_88 |
V_89 |
V_90 |
V_91 |
V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 ;
V_6 = F_26 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( L_25 ) ;
return V_6 ;
}
F_14 ( V_2 , & V_2 -> V_31 [ V_62 ] ) ;
return 0 ;
}
