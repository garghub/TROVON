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
F_6 ( L_1 ,
V_18 , V_19 ) ;
}
if ( V_4 -> V_17 [ V_18 ] )
return V_18 ;
V_9 = F_1 ( V_2 , V_4 , V_18 , V_18 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_18 ;
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
struct V_3 * V_4 ,
struct V_10 * V_31 ,
T_3 V_32 ,
T_3 V_33 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
struct V_7 * V_8 = NULL ;
struct V_34 * V_35 ;
unsigned long V_5 ;
unsigned long V_18 ;
unsigned long V_36 ;
unsigned long V_37 ;
int V_6 ;
unsigned long V_38 ;
F_12 ( & V_25 -> V_39 ) ;
V_35 = & V_25 -> V_40 [ V_31 -> V_14 ] ;
if ( V_31 -> V_12 + V_33 < V_33 ||
( V_31 -> V_12 + V_33 ) > V_35 -> V_41 ) {
F_6 ( L_2 ,
V_31 -> V_12 , 0 ,
V_31 -> V_12 , V_33 ,
V_35 -> V_41 ) ;
goto V_42;
}
V_5 = V_31 -> V_12 + V_32 +
( sizeof( struct V_43 ) << 3 ) ;
do {
V_38 = 0 ;
V_18 = V_5 >> ( V_2 -> V_44 + 3 ) ;
V_36 = V_5 % ( V_2 -> V_45 << 3 ) ;
if ( V_36 + V_33 > ( V_2 -> V_45 << 3 ) ) {
V_38 = V_36 + V_33 - ( V_2 -> V_45 << 3 ) ;
V_33 -= V_38 ;
}
V_6 = F_7 ( V_2 , V_4 , V_18 ) ;
if ( V_6 < 0 )
goto V_42;
V_8 = V_4 -> V_17 [ V_6 ] ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ ) {
if ( F_13 ( V_36 + V_37 , V_8 -> V_29 ) ) {
F_6 ( L_3 , V_36 + V_37 ) ;
F_6 ( L_4 ,
( ( char * ) V_8 -> V_29 ) [ ( V_36 + V_37 ) >> 3 ] ) ;
}
}
F_8 ( V_2 , V_25 -> V_15 , V_33 ) ;
F_14 ( V_8 ) ;
if ( V_38 ) {
V_5 += V_33 ;
V_33 = V_38 ;
}
} while ( V_38 );
V_42:
F_15 ( & V_25 -> V_39 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_4 V_22 , T_3 V_46 ,
T_3 V_47 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
int V_48 = 0 ;
int V_36 , V_5 , V_18 , V_49 ;
int V_19 , V_6 ;
struct V_7 * V_8 ;
T_5 V_50 ;
F_12 ( & V_25 -> V_39 ) ;
V_50 = V_25 -> V_40 [ V_22 ] . V_41 ;
if ( V_46 >= V_50 )
goto V_51;
if ( V_46 + V_47 > V_50 )
V_47 = V_50 - V_46 ;
do {
V_19 = F_17 ( V_2 , V_22 ) ;
V_5 = V_46 + ( sizeof( struct V_43 ) << 3 ) ;
V_18 = V_5 >> ( V_2 -> V_44 + 3 ) ;
V_49 = V_18 ? 0 : sizeof( struct V_43 ) ;
V_6 = F_7 ( V_2 , V_4 , V_18 ) ;
if ( V_6 < 0 )
goto V_51;
V_8 = V_4 -> V_17 [ V_6 ] ;
V_36 = V_5 % ( V_2 -> V_45 << 3 ) ;
while ( V_36 < ( V_2 -> V_45 << 3 ) && V_47 > 0 ) {
if ( ! F_18 ( V_36 , V_8 -> V_29 ) )
goto V_51;
V_47 -- ;
V_48 ++ ;
V_36 ++ ;
V_5 ++ ;
}
F_14 ( V_8 ) ;
} while ( V_47 > 0 );
V_51:
F_8 ( V_2 , V_22 , - V_48 ) ;
F_15 ( & V_25 -> V_39 ) ;
return V_48 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_22 ,
T_3 V_52 , int * V_53 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
int V_54 , V_36 = 0 , V_5 , V_18 , V_49 ;
int V_55 , V_19 , V_6 , V_37 ;
struct V_7 * V_8 = NULL ;
char * V_56 ;
int V_57 = 0 ;
* V_53 = - V_58 ;
F_12 ( & V_25 -> V_39 ) ;
V_59:
if ( V_52 >= V_25 -> V_40 [ V_22 ] . V_41 )
V_52 = 0 ;
V_19 = V_4 -> V_20 ;
V_5 = V_52 + ( sizeof( struct V_43 ) << 3 ) ;
V_18 = V_5 >> ( V_2 -> V_44 + 3 ) ;
V_49 = V_18 ? 0 : sizeof( struct V_43 ) ;
V_6 = F_7 ( V_2 , V_4 , V_18 ) ;
if ( V_6 < 0 )
goto V_42;
V_8 = V_4 -> V_17 [ V_6 ] ;
V_56 = F_20 ( ( char * ) V_8 -> V_29 + V_49 , 0xFF ,
V_2 -> V_45 - V_49 ) ;
if ( ( V_56 - ( ( char * ) V_8 -> V_29 ) ) < V_2 -> V_45 ) {
V_36 = V_5 % ( V_2 -> V_45 << 3 ) ;
if ( F_21 ( V_36 , V_8 -> V_29 ) )
goto V_60;
V_55 = ( V_36 + 63 ) & ~ 63 ;
V_36 = F_22 ( V_8 -> V_29 , V_55 , V_36 ) ;
if ( V_36 < V_55 )
goto V_60;
V_56 = F_20 ( ( char * ) V_8 -> V_29 + ( V_36 >> 3 ) , 0xFF ,
V_2 -> V_45 - ( ( V_36 + 7 ) >> 3 ) ) ;
V_54 = ( V_56 - ( ( char * ) V_8 -> V_29 ) ) << 3 ;
if ( V_54 < V_2 -> V_45 << 3 ) {
V_36 = V_54 ;
goto V_61;
}
V_54 = F_22 ( V_8 -> V_29 ,
V_2 -> V_45 << 3 , V_36 ) ;
if ( V_54 < V_2 -> V_45 << 3 ) {
V_36 = V_54 ;
goto V_60;
}
}
for ( V_37 = 0 ; V_37 < ( V_19 * 2 ) ; V_37 ++ ) {
V_18 ++ ;
if ( V_18 >= V_19 )
V_18 = 0 ;
V_49 = V_18 ? 0 : sizeof( struct V_43 ) ;
V_6 = F_7 ( V_2 , V_4 , V_18 ) ;
if ( V_6 < 0 )
goto V_42;
V_8 = V_4 -> V_17 [ V_6 ] ;
if ( V_37 < V_19 ) {
V_56 = F_20 ( ( char * ) V_8 -> V_29 + V_49 , 0xFF ,
V_2 -> V_45 - V_49 ) ;
if ( ( V_56 - ( ( char * ) V_8 -> V_29 ) ) < V_2 -> V_45 ) {
V_36 = ( V_56 - ( ( char * ) V_8 -> V_29 ) ) << 3 ;
break;
}
} else {
V_36 = F_22 ( V_8 -> V_29 ,
V_2 -> V_45 << 3 ,
V_49 << 3 ) ;
if ( V_36 < V_2 -> V_45 << 3 )
break;
}
}
if ( V_37 >= ( V_19 * 2 ) ) {
F_15 ( & V_25 -> V_39 ) ;
return V_57 ;
}
if ( V_36 < V_2 -> V_45 << 3 )
goto V_61;
else
V_36 = F_22 ( V_8 -> V_29 , V_2 -> V_45 << 3 ,
V_49 << 3 ) ;
if ( V_36 >= V_2 -> V_45 << 3 ) {
F_15 ( & V_25 -> V_39 ) ;
return 0 ;
}
V_61:
V_37 = 0 ;
while ( V_37 < 7 && V_36 > ( V_49 << 3 ) &&
F_21 ( V_36 - 1 , V_8 -> V_29 ) ) {
++ V_37 ;
-- V_36 ;
}
V_60:
V_57 = V_36 + ( V_18 << ( V_2 -> V_44 + 3 ) ) -
( sizeof( struct V_43 ) << 3 ) ;
if ( ! F_18 ( V_36 , V_8 -> V_29 ) ) {
F_6 ( L_5 , V_36 ) ;
goto V_59;
}
F_14 ( V_8 ) ;
F_8 ( V_2 , V_22 , - 1 ) ;
F_15 ( & V_25 -> V_39 ) ;
* V_53 = 0 ;
return V_57 ;
V_42:
* V_53 = - V_16 ;
F_15 ( & V_25 -> V_39 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
struct V_10 * V_31 ,
T_3 V_32 ,
T_3 V_33 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
struct V_34 * V_35 ;
T_3 V_64 , V_65 ;
T_3 V_66 ;
struct V_10 V_67 ;
struct V_68 V_69 , V_70 ;
T_6 V_71 ;
struct V_72 * V_73 ;
F_12 ( & V_25 -> V_39 ) ;
V_35 = & V_25 -> V_40 [ V_31 -> V_14 ] ;
if ( V_31 -> V_12 + V_33 < V_33 ||
( V_31 -> V_12 + V_33 ) > V_35 -> V_41 ) {
F_6 ( L_2 ,
V_31 -> V_12 , 0 ,
V_31 -> V_12 , V_33 ,
V_35 -> V_41 ) ;
goto V_42;
}
V_73 = F_24 ( V_63 ) ;
F_8 ( V_2 , V_25 -> V_15 , V_33 ) ;
V_64 = V_31 -> V_12 + V_32 ;
V_65 = V_31 -> V_12 + V_32 + V_33 - 1 ;
V_70 . V_32 = V_69 . V_32 = sizeof( struct V_74 ) ;
V_66 = 0 ;
V_70 . V_5 = V_69 . V_5 = V_73 -> V_75 ;
V_70 . V_8 = V_69 . V_8 = NULL ;
while ( V_33 &&
( V_71 = F_25 ( V_63 , & V_70 , & V_67 , & V_66 , 1 ) ) != - 1 ) {
if ( ( ( V_67 . V_12 +
( V_66 >> V_2 -> V_44 ) ) == V_64 ) ) {
if ( ( 0x3FFFFFFF - V_66 ) <
( V_33 << V_2 -> V_44 ) ) {
T_3 V_76 = ( ( 0x3FFFFFFF - V_66 ) >>
V_2 -> V_44 ) ;
V_33 -= V_76 ;
V_64 += V_76 ;
V_66 = ( V_71 << 30 ) |
( 0x40000000 - V_2 -> V_45 ) ;
} else {
V_66 = ( V_71 << 30 ) |
( V_66 +
( V_33 << V_2 -> V_44 ) ) ;
V_64 += V_33 ;
V_33 = 0 ;
}
F_26 ( V_63 , & V_69 , & V_67 , V_66 , 1 ) ;
} else if ( V_67 . V_12 == ( V_65 + 1 ) ) {
if ( ( 0x3FFFFFFF - V_66 ) <
( V_33 << V_2 -> V_44 ) ) {
T_3 V_76 = ( ( 0x3FFFFFFF - V_66 ) >>
V_2 -> V_44 ) ;
V_33 -= V_76 ;
V_65 -= V_76 ;
V_67 . V_12 -= V_76 ;
V_66 = ( V_71 << 30 ) |
( 0x40000000 - V_2 -> V_45 ) ;
} else {
V_67 . V_12 = V_64 ;
V_66 = ( V_71 << 30 ) |
( V_66 +
( V_33 << V_2 -> V_44 ) ) ;
V_65 -= V_33 ;
V_33 = 0 ;
}
F_26 ( V_63 , & V_69 , & V_67 , V_66 , 1 ) ;
}
if ( V_70 . V_8 != V_69 . V_8 ) {
V_69 . V_5 = V_70 . V_5 ;
F_27 ( V_69 . V_8 ) ;
F_28 ( V_70 . V_8 ) ;
V_69 . V_8 = V_70 . V_8 ;
V_69 . V_32 = 0 ;
} else {
V_69 . V_32 = V_70 . V_32 ;
}
}
if ( V_33 ) {
int V_77 ;
V_67 . V_12 = V_64 ;
V_66 = V_78 |
( V_33 << V_2 -> V_44 ) ;
if ( V_73 -> V_79 == V_80 )
V_77 = sizeof( struct V_81 ) ;
else if ( V_73 -> V_79 == V_82 )
V_77 = sizeof( struct V_83 ) ;
else {
F_27 ( V_69 . V_8 ) ;
F_27 ( V_70 . V_8 ) ;
goto V_42;
}
if ( V_70 . V_32 + ( 2 * V_77 ) > V_2 -> V_45 ) {
F_29 ( V_63 , V_67 . V_12 ,
& V_70 ) ;
V_67 . V_12 ++ ;
V_66 -= V_2 -> V_45 ;
}
if ( V_66 )
F_30 ( V_63 , & V_70 , & V_67 , V_66 , 1 ) ;
}
F_27 ( V_70 . V_8 ) ;
F_27 ( V_69 . V_8 ) ;
V_42:
F_15 ( & V_25 -> V_39 ) ;
return;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_62 * V_63 , T_4 V_22 ,
T_3 V_46 , T_3 V_47 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
int V_48 = 0 ;
T_3 V_66 , V_77 ;
struct V_10 V_67 ;
struct V_68 V_70 ;
T_6 V_71 = - 1 ;
struct V_72 * V_73 ;
if ( V_46 >= V_25 -> V_40 [ V_22 ] . V_41 )
return 0 ;
V_73 = F_24 ( V_63 ) ;
if ( V_73 -> V_79 == V_80 )
V_77 = sizeof( struct V_81 ) ;
else if ( V_73 -> V_79 == V_82 )
V_77 = sizeof( struct V_83 ) ;
else
return 0 ;
F_12 ( & V_25 -> V_39 ) ;
V_70 . V_32 = sizeof( struct V_74 ) ;
V_70 . V_5 = V_73 -> V_75 ;
V_70 . V_8 = NULL ;
V_67 . V_12 = 0xFFFFFFFF ;
while ( V_46 != V_67 . V_12 &&
( V_71 = F_25 ( V_63 , & V_70 , & V_67 , & V_66 , 1 ) ) != - 1 ) {
F_6 ( L_6 ,
V_67 . V_12 , V_66 , V_46 ) ;
;
}
if ( V_46 == V_67 . V_12 ) {
V_70 . V_32 -= V_77 ;
V_48 = ( V_66 >> V_2 -> V_44 ) ;
if ( V_48 > V_47 ) {
V_48 = V_47 ;
V_67 . V_12 += V_48 ;
V_66 -= ( V_48 << V_2 -> V_44 ) ;
F_26 ( V_63 , & V_70 , & V_67 ,
( V_71 << 30 ) | V_66 , 1 ) ;
} else
F_32 ( V_63 , V_70 , V_67 ,
( V_71 << 30 ) | V_66 ) ;
} else {
V_48 = 0 ;
}
F_27 ( V_70 . V_8 ) ;
if ( V_48 )
F_8 ( V_2 , V_22 , - V_48 ) ;
F_15 ( & V_25 -> V_39 ) ;
return V_48 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_62 * V_63 , T_4 V_22 ,
T_3 V_52 , int * V_53 )
{
struct V_24 * V_25 = F_2 ( V_2 ) ;
T_3 V_84 = 0xFFFFFFFF , V_85 = 0xFFFFFFFF ;
T_3 V_57 = 0 , V_77 ;
T_3 V_66 , V_86 = 0 ;
struct V_10 V_67 , V_87 ( V_88 ) ;
struct V_68 V_70 , V_89 ;
T_6 V_71 ;
struct V_72 * V_73 = F_24 ( V_63 ) ;
* V_53 = - V_58 ;
if ( V_73 -> V_79 == V_80 )
V_77 = sizeof( struct V_81 ) ;
else if ( V_73 -> V_79 == V_82 )
V_77 = sizeof( struct V_83 ) ;
else
return V_57 ;
F_12 ( & V_25 -> V_39 ) ;
if ( V_52 >= V_25 -> V_40 [ V_22 ] . V_41 )
V_52 = 0 ;
V_70 . V_32 = sizeof( struct V_74 ) ;
V_70 . V_5 = V_73 -> V_75 ;
V_70 . V_8 = V_89 . V_8 = NULL ;
while ( V_84 &&
( V_71 = F_25 ( V_63 , & V_70 , & V_67 , & V_66 , 1 ) ) != - 1 ) {
if ( V_52 >= V_67 . V_12 ) {
if ( V_52 < V_67 . V_12 +
( V_66 >> V_2 -> V_44 ) )
V_85 = 0 ;
else
V_85 = V_52 - V_67 . V_12 -
( V_66 >> V_2 -> V_44 ) ;
} else {
V_85 = V_67 . V_12 - V_52 ;
}
if ( V_85 < V_84 ) {
V_84 = V_85 ;
if ( V_89 . V_8 != V_70 . V_8 ) {
F_27 ( V_89 . V_8 ) ;
V_89 . V_8 = V_70 . V_8 ;
F_28 ( V_89 . V_8 ) ;
}
V_89 . V_5 = V_70 . V_5 ;
V_89 . V_32 = V_70 . V_32 - V_77 ;
V_88 = V_67 ;
V_86 = ( V_71 << 30 ) | V_66 ;
}
}
F_27 ( V_70 . V_8 ) ;
if ( V_84 == 0xFFFFFFFF ) {
F_27 ( V_89 . V_8 ) ;
F_15 ( & V_25 -> V_39 ) ;
return 0 ;
}
V_57 = V_88 . V_12 ;
V_88 . V_12 ++ ;
V_86 -= V_2 -> V_45 ;
if ( V_86 )
F_26 ( V_63 , & V_89 , & V_88 , V_86 , 1 ) ;
else
F_32 ( V_63 , V_89 , V_88 , V_86 ) ;
F_27 ( V_89 . V_8 ) ;
F_8 ( V_2 , V_22 , - 1 ) ;
F_15 ( & V_25 -> V_39 ) ;
* V_53 = 0 ;
return V_57 ;
}
void F_34 ( struct V_1 * V_2 , struct V_62 * V_62 ,
struct V_10 * V_31 , T_3 V_32 ,
T_3 V_33 )
{
T_4 V_22 = V_31 -> V_14 ;
struct V_34 * V_90 = & F_2 ( V_2 ) -> V_40 [ V_22 ] ;
if ( V_90 -> V_91 & V_92 ) {
F_11 ( V_2 , V_90 -> V_93 . V_94 ,
V_31 , V_32 , V_33 ) ;
} else if ( V_90 -> V_91 & V_95 ) {
F_23 ( V_2 , V_90 -> V_93 . V_96 ,
V_31 , V_32 , V_33 ) ;
} else if ( V_90 -> V_91 & V_97 ) {
F_11 ( V_2 , V_90 -> V_98 . V_94 ,
V_31 , V_32 , V_33 ) ;
} else if ( V_90 -> V_91 & V_99 ) {
F_23 ( V_2 , V_90 -> V_98 . V_96 ,
V_31 , V_32 , V_33 ) ;
}
if ( V_62 ) {
F_35 ( V_62 ,
( ( V_100 ) V_33 ) << V_2 -> V_44 ) ;
}
}
inline int F_36 ( struct V_1 * V_2 ,
struct V_62 * V_62 ,
T_4 V_22 , T_3 V_46 ,
T_3 V_47 )
{
struct V_34 * V_90 = & F_2 ( V_2 ) -> V_40 [ V_22 ] ;
int V_101 ;
if ( V_90 -> V_91 & V_92 )
V_101 = F_16 ( V_2 ,
V_90 -> V_93 . V_94 ,
V_22 , V_46 ,
V_47 ) ;
else if ( V_90 -> V_91 & V_95 )
V_101 = F_31 ( V_2 ,
V_90 -> V_93 . V_96 ,
V_22 , V_46 ,
V_47 ) ;
else if ( V_90 -> V_91 & V_97 )
V_101 = F_16 ( V_2 ,
V_90 -> V_98 . V_94 ,
V_22 , V_46 ,
V_47 ) ;
else if ( V_90 -> V_91 & V_99 )
V_101 = F_31 ( V_2 ,
V_90 -> V_98 . V_96 ,
V_22 , V_46 ,
V_47 ) ;
else
return 0 ;
if ( V_62 && V_101 > 0 )
F_37 ( V_62 , V_101 << V_2 -> V_44 ) ;
return V_101 ;
}
inline int F_38 ( struct V_1 * V_2 ,
struct V_62 * V_62 ,
T_4 V_22 , T_3 V_52 , int * V_53 )
{
struct V_34 * V_90 = & F_2 ( V_2 ) -> V_40 [ V_22 ] ;
int V_5 ;
if ( V_90 -> V_91 & V_92 )
V_5 = F_19 ( V_2 ,
V_90 -> V_93 . V_94 ,
V_22 , V_52 , V_53 ) ;
else if ( V_90 -> V_91 & V_95 )
V_5 = F_33 ( V_2 ,
V_90 -> V_93 . V_96 ,
V_22 , V_52 , V_53 ) ;
else if ( V_90 -> V_91 & V_97 )
V_5 = F_19 ( V_2 ,
V_90 -> V_98 . V_94 ,
V_22 , V_52 , V_53 ) ;
else if ( V_90 -> V_91 & V_99 )
V_5 = F_33 ( V_2 ,
V_90 -> V_98 . V_96 ,
V_22 , V_52 , V_53 ) ;
else {
* V_53 = - V_16 ;
return 0 ;
}
if ( V_62 && V_5 )
F_37 ( V_62 , V_2 -> V_45 ) ;
return V_5 ;
}
