static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_7 * V_8 = NULL ;
int V_9 = 0 ;
struct V_10 V_11 ;
V_11 . V_12 = V_4 -> V_13 ;
V_11 . V_14 = F_2 ( V_2 ) -> V_15 ;
V_8 = F_3 ( V_2 , F_4 ( V_2 , & V_11 , V_5 ) ) ;
if ( ! V_8 )
V_9 = - V_16 ;
V_4 -> V_17 [ V_6 ] = V_8 ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_18 )
{
int V_9 = 0 ;
int V_19 = V_4 -> V_20 ;
if ( V_18 >= V_19 ) {
F_6 ( L_1 , V_18 ,
V_19 ) ;
}
if ( V_4 -> V_17 [ V_18 ] ) {
return V_18 ;
} else {
V_9 = F_1 ( V_2 , V_4 , V_18 ,
V_18 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_18 ;
}
}
static inline int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_18 )
{
int V_21 ;
V_21 = F_5 ( V_2 , V_4 , V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! V_4 -> V_17 [ V_21 ] )
return - V_16 ;
return V_21 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_22 , T_2 V_23 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
if ( ! V_25 -> V_28 )
return;
V_27 = (struct V_26 * ) V_25 -> V_28 -> V_29 ;
F_9 ( & V_27 -> V_30 [ V_22 ] , V_23 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_31 * V_31 ,
struct V_3 * V_4 ,
struct V_10 * V_32 ,
T_3 V_33 ,
T_3 V_34 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
struct V_7 * V_8 = NULL ;
struct V_35 * V_36 ;
unsigned long V_5 ;
unsigned long V_18 ;
unsigned long V_37 ;
unsigned long V_38 ;
int V_6 ;
unsigned long V_39 ;
F_12 ( & V_25 -> V_40 ) ;
V_36 = & V_25 -> V_41 [ V_32 -> V_14 ] ;
if ( V_32 -> V_12 + V_34 < V_34 ||
( V_32 -> V_12 + V_34 ) > V_36 -> V_42 ) {
F_6 ( L_2 ,
V_32 -> V_12 , 0 , V_32 -> V_12 ,
V_34 , V_36 -> V_42 ) ;
goto V_43;
}
V_5 = V_32 -> V_12 + V_33 +
( sizeof( struct V_44 ) << 3 ) ;
do {
V_39 = 0 ;
V_18 = V_5 >> ( V_2 -> V_45 + 3 ) ;
V_37 = V_5 % ( V_2 -> V_46 << 3 ) ;
if ( V_37 + V_34 > ( V_2 -> V_46 << 3 ) ) {
V_39 = V_37 + V_34 - ( V_2 -> V_46 << 3 ) ;
V_34 -= V_39 ;
}
V_6 = F_7 ( V_2 , V_4 , V_18 ) ;
if ( V_6 < 0 )
goto V_43;
V_8 = V_4 -> V_17 [ V_6 ] ;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 ++ ) {
if ( F_13 ( V_37 + V_38 , V_8 -> V_29 ) ) {
F_6 ( L_3 , V_37 + V_38 ) ;
F_6 ( L_4 ,
( ( char * ) V_8 -> V_29 ) [ ( V_37 + V_38 ) >> 3 ] ) ;
}
}
F_8 ( V_2 , V_25 -> V_15 , V_34 ) ;
F_14 ( V_8 ) ;
if ( V_39 ) {
V_5 += V_34 ;
V_34 = V_39 ;
}
} while ( V_39 );
V_43:
F_15 ( & V_25 -> V_40 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_31 * V_31 ,
struct V_3 * V_4 ,
T_4 V_22 , T_3 V_47 ,
T_3 V_48 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
int V_49 = 0 ;
int V_37 , V_5 , V_18 , V_50 ;
int V_19 , V_6 ;
struct V_7 * V_8 ;
T_5 V_51 ;
F_12 ( & V_25 -> V_40 ) ;
V_51 = V_25 -> V_41 [ V_22 ] . V_42 ;
if ( V_47 >= V_51 )
goto V_52;
if ( V_47 + V_48 > V_51 )
V_48 = V_51 - V_47 ;
do {
V_19 = F_17 ( V_2 , V_22 ) ;
V_5 = V_47 + ( sizeof( struct V_44 ) << 3 ) ;
V_18 = V_5 >> ( V_2 -> V_45 + 3 ) ;
V_50 = V_18 ? 0 : sizeof( struct V_44 ) ;
V_6 = F_7 ( V_2 , V_4 , V_18 ) ;
if ( V_6 < 0 )
goto V_52;
V_8 = V_4 -> V_17 [ V_6 ] ;
V_37 = V_5 % ( V_2 -> V_46 << 3 ) ;
while ( V_37 < ( V_2 -> V_46 << 3 ) && V_48 > 0 ) {
if ( ! F_18 ( V_37 , V_8 -> V_29 ) )
goto V_52;
V_48 -- ;
V_49 ++ ;
V_37 ++ ;
V_5 ++ ;
}
F_14 ( V_8 ) ;
} while ( V_48 > 0 );
V_52:
F_8 ( V_2 , V_22 , - V_49 ) ;
F_15 ( & V_25 -> V_40 ) ;
return V_49 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_31 * V_31 ,
struct V_3 * V_4 , T_4 V_22 ,
T_3 V_53 , int * V_54 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
int V_55 , V_37 = 0 , V_5 , V_18 , V_50 ;
int V_56 , V_19 , V_6 , V_38 ;
struct V_7 * V_8 = NULL ;
char * V_57 ;
int V_58 = 0 ;
* V_54 = - V_59 ;
F_12 ( & V_25 -> V_40 ) ;
V_60:
if ( V_53 >= V_25 -> V_41 [ V_22 ] . V_42 )
V_53 = 0 ;
V_19 = V_4 -> V_20 ;
V_5 = V_53 + ( sizeof( struct V_44 ) << 3 ) ;
V_18 = V_5 >> ( V_2 -> V_45 + 3 ) ;
V_50 = V_18 ? 0 : sizeof( struct V_44 ) ;
V_6 = F_7 ( V_2 , V_4 , V_18 ) ;
if ( V_6 < 0 )
goto V_43;
V_8 = V_4 -> V_17 [ V_6 ] ;
V_57 = F_20 ( ( char * ) V_8 -> V_29 + V_50 , 0xFF ,
V_2 -> V_46 - V_50 ) ;
if ( ( V_57 - ( ( char * ) V_8 -> V_29 ) ) < V_2 -> V_46 ) {
V_37 = V_5 % ( V_2 -> V_46 << 3 ) ;
if ( F_21 ( V_37 , V_8 -> V_29 ) )
goto V_61;
V_56 = ( V_37 + 63 ) & ~ 63 ;
V_37 = F_22 ( V_8 -> V_29 , V_56 , V_37 ) ;
if ( V_37 < V_56 )
goto V_61;
V_57 = F_20 ( ( char * ) V_8 -> V_29 + ( V_37 >> 3 ) , 0xFF ,
V_2 -> V_46 - ( ( V_37 + 7 ) >> 3 ) ) ;
V_55 = ( V_57 - ( ( char * ) V_8 -> V_29 ) ) << 3 ;
if ( V_55 < V_2 -> V_46 << 3 ) {
V_37 = V_55 ;
goto V_62;
}
V_55 = F_22 ( V_8 -> V_29 ,
V_2 -> V_46 << 3 , V_37 ) ;
if ( V_55 < V_2 -> V_46 << 3 ) {
V_37 = V_55 ;
goto V_61;
}
}
for ( V_38 = 0 ; V_38 < ( V_19 * 2 ) ; V_38 ++ ) {
V_18 ++ ;
if ( V_18 >= V_19 )
V_18 = 0 ;
V_50 = V_18 ? 0 : sizeof( struct V_44 ) ;
V_6 = F_7 ( V_2 , V_4 , V_18 ) ;
if ( V_6 < 0 )
goto V_43;
V_8 = V_4 -> V_17 [ V_6 ] ;
if ( V_38 < V_19 ) {
V_57 = F_20 ( ( char * ) V_8 -> V_29 + V_50 , 0xFF ,
V_2 -> V_46 - V_50 ) ;
if ( ( V_57 - ( ( char * ) V_8 -> V_29 ) ) < V_2 -> V_46 ) {
V_37 = ( V_57 - ( ( char * ) V_8 -> V_29 ) ) << 3 ;
break;
}
} else {
V_37 = F_22 ( V_8 -> V_29 ,
V_2 -> V_46 << 3 ,
V_50 << 3 ) ;
if ( V_37 < V_2 -> V_46 << 3 )
break;
}
}
if ( V_38 >= ( V_19 * 2 ) ) {
F_15 ( & V_25 -> V_40 ) ;
return V_58 ;
}
if ( V_37 < V_2 -> V_46 << 3 )
goto V_62;
else
V_37 = F_22 ( V_8 -> V_29 , V_2 -> V_46 << 3 ,
V_50 << 3 ) ;
if ( V_37 >= V_2 -> V_46 << 3 ) {
F_15 ( & V_25 -> V_40 ) ;
return 0 ;
}
V_62:
V_38 = 0 ;
while ( V_38 < 7 && V_37 > ( V_50 << 3 ) &&
F_21 ( V_37 - 1 , V_8 -> V_29 ) ) {
++ V_38 ;
-- V_37 ;
}
V_61:
V_58 = V_37 + ( V_18 << ( V_2 -> V_45 + 3 ) ) -
( sizeof( struct V_44 ) << 3 ) ;
if ( ! F_18 ( V_37 , V_8 -> V_29 ) ) {
F_6 ( L_5 , V_37 ) ;
goto V_60;
}
F_14 ( V_8 ) ;
F_8 ( V_2 , V_22 , - 1 ) ;
F_15 ( & V_25 -> V_40 ) ;
* V_54 = 0 ;
return V_58 ;
V_43:
* V_54 = - V_16 ;
F_15 ( & V_25 -> V_40 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_31 * V_31 ,
struct V_31 * V_63 ,
struct V_10 * V_32 ,
T_3 V_33 ,
T_3 V_34 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
struct V_35 * V_36 ;
T_3 V_64 , V_65 ;
T_3 V_66 ;
struct V_10 V_67 ;
struct V_68 V_69 , V_70 ;
T_6 V_71 ;
int V_38 ;
struct V_72 * V_73 ;
F_12 ( & V_25 -> V_40 ) ;
V_36 = & V_25 -> V_41 [ V_32 -> V_14 ] ;
if ( V_32 -> V_12 + V_34 < V_34 ||
( V_32 -> V_12 + V_34 ) > V_36 -> V_42 ) {
F_6 ( L_2 ,
V_32 -> V_12 , 0 , V_32 -> V_12 , V_34 ,
V_36 -> V_42 ) ;
goto V_43;
}
V_73 = F_24 ( V_63 ) ;
F_8 ( V_2 , V_25 -> V_15 , V_34 ) ;
V_64 = V_32 -> V_12 + V_33 ;
V_65 = V_32 -> V_12 + V_33 + V_34 - 1 ;
V_70 . V_33 = V_69 . V_33 = sizeof( struct V_74 ) ;
V_66 = 0 ;
V_70 . V_5 = V_69 . V_5 = V_73 -> V_75 ;
V_70 . V_8 = V_69 . V_8 = NULL ;
while ( V_34 &&
( V_71 = F_25 ( V_63 , & V_70 , & V_67 , & V_66 , 1 ) ) != - 1 ) {
if ( ( ( V_67 . V_12 +
( V_66 >> V_2 -> V_45 ) ) == V_64 ) ) {
if ( ( 0x3FFFFFFF - V_66 ) <
( V_34 << V_2 -> V_45 ) ) {
T_3 V_76 = ( ( 0x3FFFFFFF - V_66 ) >>
V_2 -> V_45 ) ;
V_34 -= V_76 ;
V_64 += V_76 ;
V_66 = ( V_71 << 30 ) |
( 0x40000000 - V_2 -> V_46 ) ;
} else {
V_66 = ( V_71 << 30 ) |
( V_66 +
( V_34 << V_2 -> V_45 ) ) ;
V_64 += V_34 ;
V_34 = 0 ;
}
F_26 ( V_63 , & V_69 , & V_67 , V_66 , 1 ) ;
} else if ( V_67 . V_12 == ( V_65 + 1 ) ) {
if ( ( 0x3FFFFFFF - V_66 ) <
( V_34 << V_2 -> V_45 ) ) {
T_3 V_76 = ( ( 0x3FFFFFFF - V_66 ) >>
V_2 -> V_45 ) ;
V_34 -= V_76 ;
V_65 -= V_76 ;
V_67 . V_12 -= V_76 ;
V_66 = ( V_71 << 30 ) |
( 0x40000000 - V_2 -> V_46 ) ;
} else {
V_67 . V_12 = V_64 ;
V_66 = ( V_71 << 30 ) |
( V_66 +
( V_34 << V_2 -> V_45 ) ) ;
V_65 -= V_34 ;
V_34 = 0 ;
}
F_26 ( V_63 , & V_69 , & V_67 , V_66 , 1 ) ;
}
if ( V_70 . V_8 != V_69 . V_8 ) {
V_38 = - 1 ;
V_69 . V_5 = V_70 . V_5 ;
F_27 ( V_69 . V_8 ) ;
F_28 ( V_70 . V_8 ) ;
V_69 . V_8 = V_70 . V_8 ;
V_69 . V_33 = 0 ;
} else {
V_69 . V_33 = V_70 . V_33 ;
}
}
if ( V_34 ) {
int V_77 ;
struct V_78 * V_79 = NULL ;
struct V_80 * V_81 = NULL ;
struct V_82 * V_83 ;
V_67 . V_12 = V_64 ;
V_66 = V_84 |
( V_34 << V_2 -> V_45 ) ;
if ( V_73 -> V_85 == V_86 )
V_77 = sizeof( struct V_78 ) ;
else if ( V_73 -> V_85 == V_87 )
V_77 = sizeof( struct V_80 ) ;
else {
F_27 ( V_69 . V_8 ) ;
F_27 ( V_70 . V_8 ) ;
goto V_43;
}
if ( V_70 . V_33 + ( 2 * V_77 ) > V_2 -> V_46 ) {
unsigned char * V_88 , * V_89 ;
int V_90 ;
F_27 ( V_69 . V_8 ) ;
V_69 = V_70 ;
V_70 . V_5 . V_12 = V_67 . V_12 ;
V_67 . V_12 ++ ;
V_66 -= V_2 -> V_46 ;
V_70 . V_8 = F_3 ( V_2 ,
F_4 ( V_2 , & V_70 . V_5 , 0 ) ) ;
if ( ! V_70 . V_8 ) {
F_27 ( V_69 . V_8 ) ;
goto V_43;
}
V_83 = (struct V_82 * ) ( V_70 . V_8 -> V_29 ) ;
V_83 -> V_91 =
F_29 ( V_69 . V_5 . V_12 ) ;
if ( V_70 . V_33 + V_77 > V_2 -> V_46 ) {
V_90 = V_70 . V_33 ;
V_83 -> V_92 = F_29 ( V_77 ) ;
V_88 = V_73 -> V_93 . V_94 + V_70 . V_33
- V_77 ;
V_89 = V_70 . V_8 -> V_29 +
sizeof( struct V_82 ) ;
memcpy ( V_89 , V_88 , V_77 ) ;
V_70 . V_33 = sizeof( struct V_82 ) +
V_77 ;
} else {
V_90 = V_70 . V_33 + V_77 ;
V_83 -> V_92 = F_29 ( 0 ) ;
if ( V_69 . V_8 ) {
V_88 = V_69 . V_8 -> V_29 + V_70 . V_33 ;
V_83 = (struct V_82 * )
V_69 . V_8 -> V_29 ;
F_9 ( & V_83 -> V_92 ,
V_77 ) ;
} else {
V_88 = V_73 -> V_93 . V_94 +
V_70 . V_33 ;
V_73 -> V_95 += V_77 ;
F_30 ( V_63 ) ;
}
V_70 . V_33 = sizeof( struct V_82 ) ;
}
if ( V_25 -> V_96 >= 0x0200 )
F_31 ( V_70 . V_8 -> V_29 , V_97 ,
3 , 1 , V_70 . V_5 . V_12 ,
sizeof( struct V_98 ) ) ;
else
F_31 ( V_70 . V_8 -> V_29 , V_97 ,
2 , 1 , V_70 . V_5 . V_12 ,
sizeof( struct V_98 ) ) ;
switch ( V_73 -> V_85 ) {
case V_86 :
V_79 = (struct V_78 * ) V_88 ;
V_79 -> V_99 = F_29 (
V_100 |
V_2 -> V_46 ) ;
V_79 -> V_101 =
F_29 ( V_70 . V_5 . V_12 ) ;
break;
case V_87 :
V_81 = (struct V_80 * ) V_88 ;
V_81 -> V_99 = F_29 (
V_100 |
V_2 -> V_46 ) ;
V_81 -> V_102 =
F_32 ( V_70 . V_5 ) ;
break;
}
if ( V_69 . V_8 ) {
F_33 ( V_69 . V_8 -> V_29 , V_90 ) ;
F_14 ( V_69 . V_8 ) ;
} else {
F_30 ( V_63 ) ;
}
}
if ( V_66 ) {
F_26 ( V_63 , & V_70 , & V_67 , V_66 , 1 ) ;
if ( ! V_70 . V_8 ) {
V_73 -> V_95 += V_77 ;
F_30 ( V_63 ) ;
} else {
V_83 = (struct V_82 * ) V_70 . V_8 -> V_29 ;
F_9 ( & V_83 -> V_92 , V_77 ) ;
F_33 ( V_70 . V_8 -> V_29 , V_70 . V_33 ) ;
F_14 ( V_70 . V_8 ) ;
}
}
}
F_27 ( V_70 . V_8 ) ;
F_27 ( V_69 . V_8 ) ;
V_43:
F_15 ( & V_25 -> V_40 ) ;
return;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_31 * V_31 ,
struct V_31 * V_63 , T_4 V_22 ,
T_3 V_47 , T_3 V_48 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
int V_49 = 0 ;
T_3 V_66 , V_77 ;
struct V_10 V_67 ;
struct V_68 V_70 ;
T_6 V_71 = - 1 ;
struct V_72 * V_73 ;
if ( V_47 >= V_25 -> V_41 [ V_22 ] . V_42 )
return 0 ;
V_73 = F_24 ( V_63 ) ;
if ( V_73 -> V_85 == V_86 )
V_77 = sizeof( struct V_78 ) ;
else if ( V_73 -> V_85 == V_87 )
V_77 = sizeof( struct V_80 ) ;
else
return 0 ;
F_12 ( & V_25 -> V_40 ) ;
V_70 . V_33 = sizeof( struct V_74 ) ;
V_70 . V_5 = V_73 -> V_75 ;
V_70 . V_8 = NULL ;
V_67 . V_12 = 0xFFFFFFFF ;
while ( V_47 != V_67 . V_12 &&
( V_71 = F_25 ( V_63 , & V_70 , & V_67 , & V_66 , 1 ) ) != - 1 ) {
F_6 ( L_6 ,
V_67 . V_12 , V_66 , V_47 ) ;
;
}
if ( V_47 == V_67 . V_12 ) {
V_70 . V_33 -= V_77 ;
V_49 = ( V_66 >> V_2 -> V_45 ) ;
if ( V_49 > V_48 ) {
V_49 = V_48 ;
V_67 . V_12 += V_49 ;
V_66 -= ( V_49 << V_2 -> V_45 ) ;
F_26 ( V_63 , & V_70 , & V_67 ,
( V_71 << 30 ) | V_66 , 1 ) ;
} else
F_35 ( V_63 , V_70 , V_67 ,
( V_71 << 30 ) | V_66 ) ;
} else {
V_49 = 0 ;
}
F_27 ( V_70 . V_8 ) ;
if ( V_49 )
F_8 ( V_2 , V_22 , - V_49 ) ;
F_15 ( & V_25 -> V_40 ) ;
return V_49 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_31 * V_31 ,
struct V_31 * V_63 , T_4 V_22 ,
T_3 V_53 , int * V_54 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
T_3 V_103 = 0xFFFFFFFF , V_104 = 0xFFFFFFFF ;
T_3 V_58 = 0 , V_77 ;
T_3 V_66 , V_105 = 0 ;
struct V_10 V_67 , V_106 ( V_107 ) ;
struct V_68 V_70 , V_108 ;
T_6 V_71 ;
struct V_72 * V_73 = F_24 ( V_63 ) ;
* V_54 = - V_59 ;
if ( V_73 -> V_85 == V_86 )
V_77 = sizeof( struct V_78 ) ;
else if ( V_73 -> V_85 == V_87 )
V_77 = sizeof( struct V_80 ) ;
else
return V_58 ;
F_12 ( & V_25 -> V_40 ) ;
if ( V_53 >= V_25 -> V_41 [ V_22 ] . V_42 )
V_53 = 0 ;
V_70 . V_33 = sizeof( struct V_74 ) ;
V_70 . V_5 = V_73 -> V_75 ;
V_70 . V_8 = V_108 . V_8 = NULL ;
while ( V_103 &&
( V_71 = F_25 ( V_63 , & V_70 , & V_67 , & V_66 , 1 ) ) != - 1 ) {
if ( V_53 >= V_67 . V_12 ) {
if ( V_53 < V_67 . V_12 +
( V_66 >> V_2 -> V_45 ) )
V_104 = 0 ;
else
V_104 = V_53 - V_67 . V_12 -
( V_66 >> V_2 -> V_45 ) ;
} else {
V_104 = V_67 . V_12 - V_53 ;
}
if ( V_104 < V_103 ) {
V_103 = V_104 ;
if ( V_108 . V_8 != V_70 . V_8 ) {
F_27 ( V_108 . V_8 ) ;
V_108 . V_8 = V_70 . V_8 ;
F_28 ( V_108 . V_8 ) ;
}
V_108 . V_5 = V_70 . V_5 ;
V_108 . V_33 = V_70 . V_33 - V_77 ;
V_107 = V_67 ;
V_105 = ( V_71 << 30 ) | V_66 ;
}
}
F_27 ( V_70 . V_8 ) ;
if ( V_103 == 0xFFFFFFFF ) {
F_27 ( V_108 . V_8 ) ;
F_15 ( & V_25 -> V_40 ) ;
return 0 ;
}
V_58 = V_107 . V_12 ;
V_107 . V_12 ++ ;
V_105 -= V_2 -> V_46 ;
if ( V_105 )
F_26 ( V_63 , & V_108 , & V_107 , V_105 , 1 ) ;
else
F_35 ( V_63 , V_108 , V_107 , V_105 ) ;
F_27 ( V_108 . V_8 ) ;
F_8 ( V_2 , V_22 , - 1 ) ;
F_15 ( & V_25 -> V_40 ) ;
* V_54 = 0 ;
return V_58 ;
}
void F_37 ( struct V_1 * V_2 , struct V_31 * V_31 ,
struct V_10 * V_32 , T_3 V_33 ,
T_3 V_34 )
{
T_4 V_22 = V_32 -> V_14 ;
struct V_35 * V_109 = & F_2 ( V_2 ) -> V_41 [ V_22 ] ;
if ( V_109 -> V_110 & V_111 ) {
F_11 ( V_2 , V_31 , V_109 -> V_112 . V_113 ,
V_32 , V_33 , V_34 ) ;
} else if ( V_109 -> V_110 & V_114 ) {
F_23 ( V_2 , V_31 , V_109 -> V_112 . V_115 ,
V_32 , V_33 , V_34 ) ;
} else if ( V_109 -> V_110 & V_116 ) {
F_11 ( V_2 , V_31 , V_109 -> V_117 . V_113 ,
V_32 , V_33 , V_34 ) ;
} else if ( V_109 -> V_110 & V_118 ) {
F_23 ( V_2 , V_31 , V_109 -> V_117 . V_115 ,
V_32 , V_33 , V_34 ) ;
}
}
inline int F_38 ( struct V_1 * V_2 ,
struct V_31 * V_31 ,
T_4 V_22 , T_3 V_47 ,
T_3 V_48 )
{
struct V_35 * V_109 = & F_2 ( V_2 ) -> V_41 [ V_22 ] ;
if ( V_109 -> V_110 & V_111 )
return F_16 ( V_2 , V_31 ,
V_109 -> V_112 . V_113 ,
V_22 , V_47 ,
V_48 ) ;
else if ( V_109 -> V_110 & V_114 )
return F_34 ( V_2 , V_31 ,
V_109 -> V_112 . V_115 ,
V_22 , V_47 ,
V_48 ) ;
else if ( V_109 -> V_110 & V_116 )
return F_16 ( V_2 , V_31 ,
V_109 -> V_117 . V_113 ,
V_22 , V_47 ,
V_48 ) ;
else if ( V_109 -> V_110 & V_118 )
return F_34 ( V_2 , V_31 ,
V_109 -> V_117 . V_115 ,
V_22 , V_47 ,
V_48 ) ;
else
return 0 ;
}
inline int F_39 ( struct V_1 * V_2 ,
struct V_31 * V_31 ,
T_4 V_22 , T_3 V_53 , int * V_54 )
{
struct V_35 * V_109 = & F_2 ( V_2 ) -> V_41 [ V_22 ] ;
if ( V_109 -> V_110 & V_111 )
return F_19 ( V_2 , V_31 ,
V_109 -> V_112 . V_113 ,
V_22 , V_53 , V_54 ) ;
else if ( V_109 -> V_110 & V_114 )
return F_36 ( V_2 , V_31 ,
V_109 -> V_112 . V_115 ,
V_22 , V_53 , V_54 ) ;
else if ( V_109 -> V_110 & V_116 )
return F_19 ( V_2 , V_31 ,
V_109 -> V_117 . V_113 ,
V_22 , V_53 , V_54 ) ;
else if ( V_109 -> V_110 & V_118 )
return F_36 ( V_2 , V_31 ,
V_109 -> V_117 . V_115 ,
V_22 , V_53 , V_54 ) ;
else {
* V_54 = - V_16 ;
return 0 ;
}
}
