static void T_1 * F_1 ( void T_1 * V_1 , void T_1 * V_2 )
{
void T_1 * V_3 ;
void T_1 * V_4 ;
T_2 V_5 , V_6 , V_7 , V_8 ;
int V_9 = 0 ;
V_4 = ( V_2 - sizeof( struct V_10 ) + 1 ) ;
for ( V_3 = V_1 ; V_3 <= V_4 ; V_3 += 16 ) {
V_5 = F_2 ( V_3 + V_11 ) ;
V_6 = F_2 ( V_3 + V_12 ) ;
V_7 = F_2 ( V_3 + V_13 ) ;
V_8 = F_2 ( V_3 + V_14 ) ;
if ( V_5 == '$' &&
V_6 == 'H' &&
V_7 == 'R' &&
V_8 == 'T' ) {
V_9 = 1 ;
break;
}
}
if ( ! V_9 )
V_3 = NULL ;
F_3 ( L_1 , V_3 ) ;
return V_3 ;
}
int F_4 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
int V_21 ;
F_5 () ;
if ( V_18 -> V_22 == NULL )
V_18 -> V_22 = F_6 ( V_18 -> V_23 , F_7 ( V_18 -> V_24 , V_18 -> V_25 ) ) ;
if ( V_18 -> V_22 == NULL ) {
F_3 ( L_2 ) ;
V_21 = F_8 ( V_16 -> V_22 -> V_23 , F_7 ( V_18 -> V_24 , V_18 -> V_25 ) ) ;
if ( V_21 )
F_9 ( V_16 -> V_22 -> V_23 ) ;
V_18 -> V_22 = F_6 ( V_18 -> V_23 , F_7 ( V_18 -> V_24 , V_18 -> V_25 ) ) ;
if ( V_18 -> V_22 == NULL ) {
F_3 ( L_3 ) ;
goto V_26;
}
}
if ( V_18 -> V_22 -> V_27 == V_28 ) {
F_10 ( V_18 -> V_22 ) ;
V_20 = V_18 -> V_22 -> V_29 ;
if ( V_20 )
F_9 ( V_20 ) ;
}
F_11 ( V_18 -> V_22 ) ;
V_26:
F_12 () ;
return 0 ;
}
int F_13 ( struct V_17 * V_18 )
{
int V_30 ;
F_3 ( L_4 , V_31 , V_18 -> V_23 , V_18 -> V_24 , V_18 -> V_25 ) ;
F_5 () ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ ) {
struct V_22 * V_32 = F_6 ( V_18 -> V_23 , F_7 ( V_18 -> V_24 , V_30 ) ) ;
if ( V_32 ) {
F_11 ( V_32 ) ;
F_14 ( V_32 ) ;
}
}
F_12 () ;
return 0 ;
}
static int F_15 ( struct V_19 * V_23 , unsigned int V_33 , T_2 V_34 , T_3 * V_35 )
{
T_3 V_36 = 0 ;
if ( F_16 ( V_23 , V_33 , V_37 , & V_36 ) == - 1 )
return - 1 ;
if ( V_36 == 0xffffffff )
return - 1 ;
return F_16 ( V_23 , V_33 , V_34 , V_35 ) ;
}
int F_17 ( T_2 V_38 , T_2 V_39 , T_2 V_40 , T_2 V_41 )
{
int V_42 = 0 ;
if ( V_43 ) {
struct V_22 * V_44 ;
struct V_19 * V_45 ;
T_4 V_46 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_47 ) ;
V_45 = F_18 ( sizeof( * V_45 ) , V_47 ) ;
if ( ! V_44 || ! V_45 ) {
F_19 ( V_44 ) ;
F_19 ( V_45 ) ;
return - V_48 ;
}
V_44 -> V_33 = V_39 << 3 ;
V_44 -> V_23 = V_45 ;
V_45 -> V_49 = V_38 ;
F_3 ( L_5 ,
V_31 , V_39 , V_38 , V_40 , V_41 ) ;
V_42 = F_20 ( V_44 , V_40 - 1 , V_41 ) ;
F_19 ( V_44 ) ;
F_19 ( V_45 ) ;
F_3 ( L_6 , V_31 , V_42 ) ;
if ( ! V_42 )
return ! V_42 ;
V_46 = F_21 ( 0x4d0 ) ;
V_46 |= F_21 ( 0x4d1 ) << 8 ;
V_46 |= 0x01 << V_41 ;
F_22 ( ( T_2 ) ( V_46 & 0xFF ) , 0x4d0 ) ; F_22 ( ( T_2 ) ( ( V_46 &
0xFF00 ) >> 8 ) , 0x4d1 ) ; V_42 = 0 ; }
return V_42 ;
}
static int F_23 ( struct V_15 * V_16 , T_2 V_38 , T_2 * V_39 )
{
T_4 V_50 ;
T_3 V_51 ;
T_2 V_52 ;
V_16 -> V_19 -> V_49 = V_38 ;
for ( V_50 = 0 ; V_50 < 0xFF ; V_50 ++ ) {
if ( F_15 ( V_16 -> V_19 , V_50 , 0x08 , & V_51 ) == - 1 )
continue;
F_3 ( L_7 , V_38 , V_50 ) ;
if ( ( V_51 >> 8 ) != V_53 ) {
* V_39 = V_50 ;
F_3 ( L_8 ) ;
return 0 ;
}
}
for ( V_50 = 0 ; V_50 < 0xFF ; V_50 ++ ) {
if ( F_15 ( V_16 -> V_19 , V_50 , 0x08 , & V_51 ) == - 1 )
continue;
F_3 ( L_9 , V_38 , V_50 ) ;
if ( ( V_51 >> 8 ) == V_53 ) {
F_24 ( V_16 -> V_19 , F_7 ( V_50 , 0 ) , V_54 , & V_52 ) ;
F_3 ( L_10 , V_52 , V_50 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_25 ( struct V_15 * V_16 , T_2 * V_38 , T_2 * V_39 , T_2 V_55 , T_2 V_56 )
{
int V_57 , V_58 ;
T_3 V_51 ;
T_2 V_52 , V_50 , V_59 ;
V_58 = F_26 () ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 ) {
V_52 = V_60 -> V_61 [ V_57 ] . V_23 ;
V_50 = V_60 -> V_61 [ V_57 ] . V_33 ;
V_59 = V_60 -> V_61 [ V_57 ] . V_55 ;
if ( V_59 == V_55 ) {
* V_38 = V_52 ;
* V_39 = V_50 ;
V_16 -> V_19 -> V_49 = V_52 ;
F_16 ( V_16 -> V_19 , * V_39 , V_37 , & V_51 ) ;
if ( ! V_56 || ( V_51 == 0xffffffff ) )
return 0 ;
F_3 ( L_11 , * V_38 , * V_39 ) ;
F_16 ( V_16 -> V_19 , * V_39 , V_62 , & V_51 ) ;
F_3 ( L_12 , V_51 >> 8 , V_53 ) ;
if ( ( V_51 >> 8 ) == V_53 ) {
F_24 ( V_16 -> V_19 , * V_39 , V_54 , & V_52 ) ;
F_3 ( L_13 , V_52 ) ;
if ( F_23 ( V_16 , V_52 , V_39 ) == 0 ) {
* V_38 = V_52 ;
return 0 ;
}
} else
return 0 ;
}
}
return - 1 ;
}
int F_27 ( struct V_15 * V_16 , T_2 * V_38 , T_2 * V_39 , T_2 V_55 )
{
return F_25 ( V_16 , V_38 , V_39 , V_55 , 0 ) ;
}
int F_28 ( struct V_15 * V_16 , int V_63 , int V_64 )
{
long V_42 ;
T_2 V_65 ;
T_2 V_66 ;
T_3 V_67 ;
T_2 V_68 ;
struct V_17 * V_69 ;
int V_70 ;
int V_71 ;
int V_72 ;
int V_73 ;
int V_25 ;
T_2 V_74 ;
int V_24 = 0 ;
int V_75 = 0 ;
int V_76 ;
int V_77 ;
if ( V_64 ) {
V_71 = V_64 >> 4 ;
V_72 = V_71 + ( V_64 & 0x0F ) - 1 ;
} else {
V_71 = 0 ;
V_72 = 0x1F ;
}
V_16 -> V_19 -> V_49 = V_63 ;
for ( V_24 = V_71 ; V_24 <= V_72 ; V_24 ++ ) {
V_67 = 0xFFFFFFFF ;
V_42 = F_16 ( V_16 -> V_19 , F_7 ( V_24 , 0 ) , V_37 , & V_67 ) ;
if ( V_67 == 0xFFFFFFFF ) {
if ( V_64 ) {
V_69 = F_29 ( V_63 ) ;
if ( V_69 == NULL )
return 1 ;
V_69 -> V_23 = ( T_2 ) V_63 ;
V_69 -> V_24 = ( T_2 ) V_24 ;
V_69 -> V_25 = 0 ;
V_69 -> V_78 = 0 ;
V_69 -> V_79 = 0 ;
V_69 -> V_80 = 0 ;
}
continue;
}
V_42 = F_24 ( V_16 -> V_19 , F_7 ( V_24 , 0 ) , 0x0B , & V_65 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_24 ( V_16 -> V_19 , F_7 ( V_24 , 0 ) , V_81 , & V_66 ) ;
if ( V_42 )
return V_42 ;
if ( V_66 & 0x80 )
V_73 = 8 ;
else
V_73 = 1 ;
V_25 = 0 ;
do {
V_74 = 0 ;
if ( ( V_66 & 0x7F ) == V_28 ) {
V_42 = F_24 ( V_16 -> V_19 , F_7 ( V_24 , V_25 ) , V_54 , & V_68 ) ;
if ( V_42 ) {
return V_42 ;
} else {
V_70 = ( int ) V_68 ;
V_42 = F_28 ( V_16 , V_70 , 0 ) ;
if ( V_42 )
return V_42 ;
V_16 -> V_19 -> V_49 = V_63 ;
}
}
V_77 = 0 ;
V_69 = F_30 ( V_63 , V_24 , V_77 ++ ) ;
while ( V_69 &&
( V_69 -> V_25 != ( T_2 ) V_25 ) )
V_69 = F_30 ( V_63 , V_24 , V_77 ++ ) ;
if ( ! V_69 ) {
V_69 = F_29 ( V_63 ) ;
if ( V_69 == NULL )
return 1 ;
}
V_69 -> V_23 = ( T_2 ) V_63 ;
V_69 -> V_24 = ( T_2 ) V_24 ;
V_69 -> V_25 = ( T_2 ) V_25 ;
V_69 -> V_78 = 1 ;
V_69 -> V_80 = 0x10 ;
V_69 -> V_9 = V_74 ;
V_69 -> V_22 = F_6 ( V_69 -> V_23 , ( V_69 -> V_24 << 3 ) | V_69 -> V_25 ) ;
for ( V_75 = 0 ; V_75 < 0x20 ; V_75 ++ ) {
V_42 = F_16 ( V_16 -> V_19 , F_7 ( V_24 , V_25 ) , V_75 << 2 , ( T_3 * ) & ( V_69 -> V_82 [ V_75 ] ) ) ;
if ( V_42 )
return V_42 ;
}
F_11 ( V_69 -> V_22 ) ;
V_25 ++ ;
V_76 = 0 ;
while ( ( V_25 < V_73 ) && ( ! V_76 ) ) {
V_42 = F_16 ( V_16 -> V_19 , F_7 ( V_24 , V_25 ) , V_37 , & V_67 ) ;
if ( V_67 == 0xFFFFFFFF ) {
V_25 ++ ;
continue;
}
V_42 = F_24 ( V_16 -> V_19 , F_7 ( V_24 , V_25 ) , 0x0B , & V_65 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_24 ( V_16 -> V_19 , F_7 ( V_24 , V_25 ) , V_81 , & V_66 ) ;
if ( V_42 )
return V_42 ;
V_76 ++ ;
}
} while ( V_25 < V_73 );
}
return 0 ;
}
int F_31 ( struct V_15 * V_16 , struct V_17 * V_69 )
{
long V_42 ;
T_2 V_65 ;
T_2 V_66 ;
T_3 V_67 ;
T_2 V_68 ;
int V_70 ;
int V_73 ;
int V_25 = 0 ;
int V_75 = 0 ;
int V_76 ;
V_67 = 0xFFFFFFFF ;
V_16 -> V_19 -> V_49 = V_69 -> V_23 ;
F_16 ( V_16 -> V_19 , F_7 ( V_69 -> V_24 , 0 ) , V_37 , & V_67 ) ;
if ( V_67 == 0xFFFFFFFF )
return 2 ;
F_24 ( V_16 -> V_19 , F_7 ( V_69 -> V_24 , 0 ) , 0x0B , & V_65 ) ;
F_24 ( V_16 -> V_19 , F_7 ( V_69 -> V_24 , 0 ) , V_81 , & V_66 ) ;
if ( V_66 & 0x80 )
V_73 = 8 ;
else
V_73 = 1 ;
while ( V_25 < V_73 ) {
if ( ( V_66 & 0x7F ) == V_28 ) {
F_24 ( V_16 -> V_19 , F_7 ( V_69 -> V_24 , V_25 ) , V_54 , & V_68 ) ;
V_70 = ( int ) V_68 ;
V_42 = F_28 ( V_16 , V_70 , 0 ) ;
if ( V_42 )
return ( V_42 ) ;
V_16 -> V_19 -> V_49 = V_69 -> V_23 ;
}
V_69 -> V_9 = 0 ;
for ( V_75 = 0 ; V_75 < 0x20 ; V_75 ++ )
F_16 ( V_16 -> V_19 , F_7 ( V_69 -> V_24 , V_25 ) , V_75 << 2 , ( T_3 * ) & ( V_69 -> V_82 [ V_75 ] ) ) ;
V_25 ++ ;
V_76 = 0 ;
while ( ( V_25 < V_73 ) && ( ! V_76 ) ) {
F_16 ( V_16 -> V_19 , F_7 ( V_69 -> V_24 , V_25 ) , V_37 , & V_67 ) ;
if ( V_67 == 0xFFFFFFFF )
V_25 ++ ;
else {
F_24 ( V_16 -> V_19 , F_7 ( V_69 -> V_24 , V_25 ) , 0x0B , & V_65 ) ;
F_24 ( V_16 -> V_19 , F_7 ( V_69 -> V_24 , V_25 ) , V_81 , & V_66 ) ;
V_76 ++ ;
}
}
}
return 0 ;
}
int F_32 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
T_2 V_75 ;
T_2 V_66 ;
T_2 V_68 ;
T_2 type ;
int V_70 ;
T_3 V_83 ;
T_3 V_84 ;
T_3 V_42 ;
struct V_17 * V_85 ;
int V_77 = 0 ;
struct V_19 * V_19 = V_16 -> V_19 ;
unsigned int V_33 ;
V_18 = F_30 ( V_18 -> V_23 , V_18 -> V_24 , V_77 ++ ) ;
while ( V_18 != NULL ) {
V_19 -> V_49 = V_18 -> V_23 ;
V_33 = F_7 ( V_18 -> V_24 , V_18 -> V_25 ) ;
F_24 ( V_19 , V_33 , V_81 , & V_66 ) ;
if ( ( V_66 & 0x7F ) == V_28 ) {
F_24 ( V_19 , V_33 , V_54 , & V_68 ) ;
V_70 = ( int ) V_68 ;
V_85 = V_86 [ V_70 ] ;
while ( V_85 != NULL ) {
V_42 = F_32 ( V_16 , V_85 ) ;
if ( V_42 )
return V_42 ;
V_85 = V_85 -> V_85 ;
}
V_19 -> V_49 = V_18 -> V_23 ;
for ( V_75 = 0x10 ; V_75 <= 0x14 ; V_75 += 4 ) {
V_83 = 0xFFFFFFFF ;
F_33 ( V_19 , V_33 , V_75 , V_83 ) ;
F_16 ( V_19 , V_33 , V_75 , & V_84 ) ;
if ( V_84 ) {
if ( V_84 & 0x01L ) {
V_84 = V_84 & 0xFFFFFFFE ;
V_84 = ( ~ V_84 ) + 1 ;
type = 1 ;
} else {
V_84 = V_84 & 0xFFFFFFF0 ;
V_84 = ( ~ V_84 ) + 1 ;
type = 0 ;
}
} else {
V_84 = 0x0L ;
type = 0 ;
}
V_18 -> V_87 [ ( V_75 - 0x10 ) >> 2 ] =
V_84 ;
V_18 -> V_88 [ ( V_75 - 0x10 ) >> 2 ] = type ;
}
} else if ( ( V_66 & 0x7F ) == 0x00 ) {
for ( V_75 = 0x10 ; V_75 <= 0x24 ; V_75 += 4 ) {
V_83 = 0xFFFFFFFF ;
F_33 ( V_19 , V_33 , V_75 , V_83 ) ;
F_16 ( V_19 , V_33 , V_75 , & V_84 ) ;
if ( V_84 ) {
if ( V_84 & 0x01L ) {
V_84 = V_84 & 0xFFFFFFFE ;
V_84 = ( ~ V_84 ) + 1 ;
type = 1 ;
} else {
V_84 = V_84 & 0xFFFFFFF0 ;
V_84 = ( ~ V_84 ) + 1 ;
type = 0 ;
}
} else {
V_84 = 0x0L ;
type = 0 ;
}
V_18 -> V_87 [ ( V_75 - 0x10 ) >> 2 ] = V_84 ;
V_18 -> V_88 [ ( V_75 - 0x10 ) >> 2 ] = type ;
}
} else {
}
V_18 = F_30 ( V_18 -> V_23 , V_18 -> V_24 , V_77 ++ ) ;
}
return ( 0 ) ;
}
int F_34 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
T_2 V_75 ;
T_2 V_66 ;
T_2 V_68 ;
T_2 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_4 V_92 ;
T_4 V_93 ;
T_4 V_94 ;
T_4 V_95 ;
T_3 V_83 ;
T_3 V_96 ;
T_3 V_84 ;
int V_77 = 0 ;
struct V_97 * V_98 ;
struct V_97 * V_99 ;
struct V_97 * V_100 ;
struct V_97 * V_101 ;
struct V_19 * V_19 = V_16 -> V_19 ;
unsigned int V_33 ;
V_18 = F_30 ( V_18 -> V_23 , V_18 -> V_24 , V_77 ++ ) ;
while ( ( V_18 != NULL ) && V_18 -> V_78 ) {
V_19 -> V_49 = V_18 -> V_23 ;
V_33 = F_7 ( V_18 -> V_24 , V_18 -> V_25 ) ;
F_35 ( V_19 , V_33 , V_102 , & V_93 ) ;
V_92 = 0x00 ;
F_36 ( V_19 , V_33 , V_102 , V_92 ) ;
F_24 ( V_19 , V_33 , V_81 , & V_66 ) ;
if ( ( V_66 & 0x7F ) == V_28 ) {
V_92 = 0x00 ;
F_36 ( V_19 , V_33 , V_103 , V_92 ) ;
F_24 ( V_19 , V_33 , V_54 , & V_68 ) ;
F_24 ( V_19 , V_33 , V_104 , & V_89 ) ;
V_101 = F_18 ( sizeof( * V_101 ) , V_47 ) ;
if ( ! V_101 )
return - V_48 ;
V_101 -> V_84 = V_68 ;
V_101 -> V_105 = V_89 - V_68 + 1 ;
V_101 -> V_85 = V_18 -> V_106 ;
V_18 -> V_106 = V_101 ;
F_24 ( V_19 , V_33 , V_107 , & V_90 ) ;
F_24 ( V_19 , V_33 , V_108 , & V_91 ) ;
if ( ( V_90 <= V_91 ) && ( V_93 & 0x01 ) ) {
V_100 = F_18 ( sizeof( * V_100 ) , V_47 ) ;
if ( ! V_100 )
return - V_48 ;
V_100 -> V_84 = ( V_90 & 0xF0 ) << 8 ;
V_100 -> V_105 = ( V_91 - V_90 + 0x10 ) << 8 ;
V_100 -> V_85 = V_18 -> V_109 ;
V_18 -> V_109 = V_100 ;
}
F_35 ( V_19 , V_33 , V_110 , & V_94 ) ;
F_35 ( V_19 , V_33 , V_111 , & V_95 ) ;
if ( ( V_94 <= V_95 ) && ( V_93 & 0x02 ) ) {
V_98 = F_18 ( sizeof( * V_98 ) , V_47 ) ;
if ( ! V_98 )
return - V_48 ;
V_98 -> V_84 = V_94 << 16 ;
V_98 -> V_105 = ( V_95 - V_94 + 0x10 ) << 16 ;
V_98 -> V_85 = V_18 -> V_112 ;
V_18 -> V_112 = V_98 ;
}
F_35 ( V_19 , V_33 , V_113 , & V_94 ) ;
F_35 ( V_19 , V_33 , V_114 , & V_95 ) ;
if ( ( V_94 <= V_95 ) && ( V_93 & 0x02 ) ) {
V_99 = F_18 ( sizeof( * V_99 ) , V_47 ) ;
if ( ! V_99 )
return - V_48 ;
V_99 -> V_84 = V_94 << 16 ;
V_99 -> V_105 = ( V_95 - V_94 + 0x10 ) << 16 ;
V_99 -> V_85 = V_18 -> V_115 ;
V_18 -> V_115 = V_99 ;
}
for ( V_75 = 0x10 ; V_75 <= 0x14 ; V_75 += 4 ) {
F_16 ( V_19 , V_33 , V_75 , & V_96 ) ;
V_83 = 0xFFFFFFFF ;
F_33 ( V_19 , V_33 , V_75 , V_83 ) ;
F_16 ( V_19 , V_33 , V_75 , & V_84 ) ;
V_83 = V_84 ;
if ( V_84 ) {
if ( ( ( V_84 & 0x03L ) == 0x01 )
&& ( V_93 & 0x01 ) ) {
V_83 = V_84 & 0xFFFFFFFE ;
V_83 = ( ~ V_83 ) + 1 ;
V_100 = F_18 ( sizeof( * V_100 ) ,
V_47 ) ;
if ( ! V_100 )
return - V_48 ;
V_100 -> V_84 =
V_96 & ( ~ 0x03L ) ;
V_100 -> V_105 = V_83 ;
V_100 -> V_85 = V_18 -> V_109 ;
V_18 -> V_109 = V_100 ;
} else
if ( ( ( V_84 & 0x0BL ) == 0x08 )
&& ( V_93 & 0x02 ) ) {
V_83 = V_84 & 0xFFFFFFF0 ;
V_83 = ( ~ V_83 ) + 1 ;
V_99 = F_18 ( sizeof( * V_99 ) ,
V_47 ) ;
if ( ! V_99 )
return - V_48 ;
V_99 -> V_84 = V_96 & ( ~ 0x0FL ) ;
V_99 -> V_105 = V_83 ;
V_99 -> V_85 = V_18 -> V_115 ;
V_18 -> V_115 = V_99 ;
} else
if ( ( ( V_84 & 0x0BL ) == 0x00 )
&& ( V_93 & 0x02 ) ) {
V_83 = V_84 & 0xFFFFFFF0 ;
V_83 = ( ~ V_83 ) + 1 ;
V_98 = F_18 ( sizeof( * V_98 ) ,
V_47 ) ;
if ( ! V_98 )
return - V_48 ;
V_98 -> V_84 = V_96 & ( ~ 0x0FL ) ;
V_98 -> V_105 = V_83 ;
V_98 -> V_85 = V_18 -> V_112 ;
V_18 -> V_112 = V_98 ;
} else
return ( 1 ) ;
}
}
} else if ( ( V_66 & 0x7F ) == 0x00 ) {
for ( V_75 = 0x10 ; V_75 <= 0x24 ; V_75 += 4 ) {
F_16 ( V_19 , V_33 , V_75 , & V_96 ) ;
V_83 = 0xFFFFFFFF ;
F_33 ( V_19 , V_33 , V_75 , V_83 ) ;
F_16 ( V_19 , V_33 , V_75 , & V_84 ) ;
V_83 = V_84 ;
if ( V_84 ) {
if ( ( ( V_84 & 0x03L ) == 0x01 )
&& ( V_93 & 0x01 ) ) {
V_83 = V_84 & 0xFFFFFFFE ;
V_83 = ( ~ V_83 ) + 1 ;
V_100 = F_18 ( sizeof( * V_100 ) ,
V_47 ) ;
if ( ! V_100 )
return - V_48 ;
V_100 -> V_84 = V_96 & ( ~ 0x01L ) ;
V_100 -> V_105 = V_83 ;
V_100 -> V_85 = V_18 -> V_109 ;
V_18 -> V_109 = V_100 ;
} else
if ( ( ( V_84 & 0x0BL ) == 0x08 )
&& ( V_93 & 0x02 ) ) {
V_83 = V_84 & 0xFFFFFFF0 ;
V_83 = ( ~ V_83 ) + 1 ;
V_99 = F_18 ( sizeof( * V_99 ) ,
V_47 ) ;
if ( ! V_99 )
return - V_48 ;
V_99 -> V_84 = V_96 & ( ~ 0x0FL ) ;
V_99 -> V_105 = V_83 ;
V_99 -> V_85 = V_18 -> V_115 ;
V_18 -> V_115 = V_99 ;
} else
if ( ( ( V_84 & 0x0BL ) == 0x00 )
&& ( V_93 & 0x02 ) ) {
V_83 = V_84 & 0xFFFFFFF0 ;
V_83 = ( ~ V_83 ) + 1 ;
V_98 = F_18 ( sizeof( * V_98 ) ,
V_47 ) ;
if ( ! V_98 )
return - V_48 ;
V_98 -> V_84 = V_96 & ( ~ 0x0FL ) ;
V_98 -> V_105 = V_83 ;
V_98 -> V_85 = V_18 -> V_112 ;
V_18 -> V_112 = V_98 ;
} else
return ( 1 ) ;
}
}
}
V_18 = F_30 ( V_18 -> V_23 , V_18 -> V_24 , V_77 ++ ) ;
}
return 0 ;
}
int F_37 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_75 ;
T_2 V_66 ;
T_2 V_68 ;
int V_70 ;
struct V_17 * V_85 ;
T_3 V_32 ;
T_3 V_42 ;
int V_77 = 0 ;
struct V_19 * V_19 = V_16 -> V_19 ;
unsigned int V_33 ;
V_18 = F_30 ( V_18 -> V_23 , V_18 -> V_24 , V_77 ++ ) ;
while ( V_18 != NULL ) {
V_19 -> V_49 = V_18 -> V_23 ;
V_33 = F_7 ( V_18 -> V_24 , V_18 -> V_25 ) ;
for ( V_75 = 0x3C ; V_75 > 0 ; V_75 -= 4 )
F_33 ( V_19 , V_33 , V_75 , V_18 -> V_82 [ V_75 >> 2 ] ) ;
F_24 ( V_19 , V_33 , V_81 , & V_66 ) ;
if ( ( V_66 & 0x7F ) == V_28 ) {
F_24 ( V_19 , V_33 , V_54 , & V_68 ) ;
V_70 = ( int ) V_68 ;
V_85 = V_86 [ V_70 ] ;
while ( V_85 != NULL ) {
V_42 = F_37 ( V_16 , V_85 ) ;
if ( V_42 )
return V_42 ;
V_85 = V_85 -> V_85 ;
}
} else {
for ( V_75 = 16 ; V_75 < 40 ; V_75 += 4 ) {
F_16 ( V_19 , V_33 , V_75 , & V_32 ) ;
if ( V_32 != V_18 -> V_82 [ V_75 >> 2 ] ) {
F_3 ( L_14 , V_75 ) ;
F_3 ( L_15 , V_18 -> V_23 , V_18 -> V_24 , V_18 -> V_25 ) ;
F_3 ( L_16 , V_32 , V_18 -> V_82 [ V_75 >> 2 ] ) ;
return 1 ;
}
}
}
V_18 -> V_116 = 1 ;
V_18 = F_30 ( V_18 -> V_23 , V_18 -> V_24 , V_77 ++ ) ;
}
return 0 ;
}
int F_38 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
T_2 V_75 ;
T_2 V_66 ;
T_2 V_68 ;
T_2 type ;
T_3 V_83 = 0 ;
T_3 V_84 ;
T_3 V_42 ;
struct V_17 * V_85 ;
int V_77 = 0 ;
struct V_19 * V_19 = V_16 -> V_19 ;
unsigned int V_33 ;
if ( ! V_18 -> V_78 )
return ( V_117 ) ;
V_18 = F_30 ( V_18 -> V_23 , V_18 -> V_24 , V_77 ++ ) ;
while ( V_18 != NULL ) {
V_19 -> V_49 = V_18 -> V_23 ;
V_33 = F_7 ( V_18 -> V_24 , V_18 -> V_25 ) ;
F_16 ( V_19 , V_33 , V_37 , & V_83 ) ;
if ( V_83 == 0xFFFFFFFF )
return ( V_118 ) ;
if ( V_83 != V_18 -> V_82 [ 0 ] )
return ( V_119 ) ;
F_16 ( V_19 , V_33 , V_62 , & V_83 ) ;
if ( V_83 != V_18 -> V_82 [ 0x08 >> 2 ] )
return ( V_119 ) ;
F_24 ( V_19 , V_33 , V_81 , & V_66 ) ;
if ( ( V_66 & 0x7F ) == V_28 ) {
V_83 = V_18 -> V_82 [ 0x18 >> 2 ] ;
F_33 ( V_19 , V_33 , V_120 , V_83 ) ;
V_68 = ( V_83 >> 8 ) & 0xFF ;
V_85 = V_86 [ V_68 ] ;
while ( V_85 != NULL ) {
V_42 = F_38 ( V_16 , V_85 ) ;
if ( V_42 )
return V_42 ;
V_85 = V_85 -> V_85 ;
}
}
else if ( ( V_66 & 0x7F ) == V_121 ) {
F_16 ( V_19 , V_33 , V_122 , & V_83 ) ;
if ( V_83 != V_18 -> V_82 [ 0x2C >> 2 ] ) {
if ( ! ( ( V_18 -> V_82 [ 0 ] == 0xAE100E11 )
&& ( V_83 == 0x00L ) ) )
return ( V_119 ) ;
}
for ( V_75 = 0x10 ; V_75 <= 0x24 ; V_75 += 4 ) {
V_83 = 0xFFFFFFFF ;
F_33 ( V_19 , V_33 , V_75 , V_83 ) ;
F_16 ( V_19 , V_33 , V_75 , & V_84 ) ;
if ( V_84 ) {
if ( V_84 & 0x01L ) {
V_84 = V_84 & 0xFFFFFFFE ;
V_84 = ( ~ V_84 ) + 1 ;
type = 1 ;
} else {
V_84 = V_84 & 0xFFFFFFF0 ;
V_84 = ( ~ V_84 ) + 1 ;
type = 0 ;
}
} else {
V_84 = 0x0L ;
type = 0 ;
}
if ( V_18 -> V_87 [ ( V_75 - 0x10 ) >> 2 ] != V_84 )
return ( V_119 ) ;
if ( V_18 -> V_88 [ ( V_75 - 0x10 ) >> 2 ] != type )
return ( V_119 ) ;
}
}
else {
return ( V_123 ) ;
}
V_18 = F_30 ( V_18 -> V_23 , V_18 -> V_24 , V_77 ++ ) ;
}
return 0 ;
}
int F_39 ( struct V_15 * V_16 , void T_1 * V_124 )
{
T_2 V_32 ;
T_2 V_125 ;
T_2 V_126 ;
void T_1 * V_127 ;
void T_1 * V_128 ;
struct V_17 * V_18 = NULL ;
int V_129 = 10 , V_77 ;
T_3 V_130 , V_42 ;
struct V_97 * V_98 ;
struct V_97 * V_99 ;
struct V_97 * V_100 ;
struct V_97 * V_101 ;
V_128 = F_1 ( V_124 , V_124 + 0xffff ) ;
F_3 ( L_17 , V_128 ) ;
if ( V_128 == NULL )
return - V_131 ;
V_132 = F_40 ( V_128 + V_133 ) ;
F_3 ( L_18 , V_132 ) ;
V_32 = 0 ;
while ( V_132 ) {
if ( V_132 & 1 ) {
V_134 = V_32 ;
break;
}
V_132 = V_132 >> 1 ;
V_32 ++ ;
}
F_3 ( L_19 , V_134 ) ;
V_132 = V_132 >> 1 ;
V_32 ++ ;
while ( V_132 ) {
if ( V_132 & 1 ) {
V_135 = V_32 ;
break;
}
V_132 = V_132 >> 1 ;
V_32 ++ ;
}
F_3 ( L_20 , V_135 ) ;
V_132 = F_40 ( V_128 + V_136 ) ;
V_32 = 0 ;
if ( ! V_135 )
V_135 = V_16 -> V_137 ;
if ( ! V_134 )
V_134 = V_16 -> V_137 ;
F_3 ( L_21 , V_134 , V_135 ) ;
V_42 = F_41 ( V_124 , V_16 ) ;
if ( V_42 )
return V_42 ;
V_127 = V_128 + sizeof( struct V_10 ) ;
V_129 = F_2 ( V_128 + V_138 ) ;
F_3 ( L_22 , V_129 ) ;
if ( ! F_2 ( V_127 + V_139 ) )
return 1 ;
F_3 ( L_23 ) ;
while ( V_129 && F_2 ( V_127 + V_139 ) ) {
T_2 V_140 = F_2 ( V_127 + V_141 ) ;
T_2 V_142 = F_2 ( V_127 + V_143 ) ;
T_2 V_68 = F_2 ( V_127 + V_139 ) ;
T_2 V_144 = F_2 ( V_127 + V_145 ) ;
T_4 V_146 = F_42 ( V_127 + V_147 ) ;
T_4 V_148 = F_42 ( V_127 + V_149 ) ;
T_4 V_150 = F_42 ( V_127 + V_151 ) ;
T_4 V_152 = F_42 ( V_127 + V_153 ) ;
T_4 V_154 = F_42 ( V_127 + V_155 ) ;
T_4 V_156 = F_42 ( V_127 + V_157 ) ;
F_3 ( L_24 ,
V_140 , V_146 , V_148 , V_150 , V_152 , V_154 , V_156 ,
V_142 , V_68 , V_144 ) ;
if ( V_142 != V_16 -> V_23 ) {
V_129 -- ;
V_127 += sizeof( struct V_158 ) ;
continue;
}
V_16 -> V_19 -> V_49 = V_142 ;
F_16 ( V_16 -> V_19 , V_140 , V_37 , & V_130 ) ;
F_3 ( L_25 , V_130 ) ;
if ( V_130 != 0xFFFFFFFF ) {
V_77 = 0 ;
V_18 = F_30 ( V_142 , V_140 >> 3 , 0 ) ;
while ( V_18 && ( V_18 -> V_25 != ( V_140 & 0x07 ) ) ) {
F_3 ( L_26 , V_18 , V_142 , V_140 >> 3 , V_77 ) ;
V_18 = F_30 ( V_142 , V_140 >> 3 , V_77 ++ ) ;
}
if ( ! V_18 ) {
V_129 -- ;
V_127 += sizeof( struct V_158 ) ;
continue;
}
if ( V_68 != V_142 )
V_126 = 1 ;
else
V_126 = 0 ;
V_125 = 1 ;
} else {
V_125 = 0 ;
V_126 = 0 ;
}
V_130 = V_146 + V_148 ;
if ( ( V_146 ) && ( V_130 < 0x10000 ) ) {
V_100 = F_18 ( sizeof( * V_100 ) , V_47 ) ;
if ( ! V_100 )
return - V_48 ;
V_100 -> V_84 = V_146 ;
V_100 -> V_105 = V_148 ;
F_3 ( L_27 ,
V_100 -> V_84 , V_100 -> V_105 ) ;
F_3 ( L_28 , V_125 ) ;
if ( ! V_125 ) {
V_100 -> V_85 = V_16 -> V_109 ;
V_16 -> V_109 = V_100 ;
} else {
V_100 -> V_85 = V_18 -> V_109 ;
V_18 -> V_109 = V_100 ;
}
}
V_130 = V_150 + V_152 ;
if ( ( V_150 ) && ( V_130 < 0x10000 ) ) {
V_98 = F_18 ( sizeof( * V_98 ) , V_47 ) ;
if ( ! V_98 )
return - V_48 ;
V_98 -> V_84 = V_150 << 16 ;
V_98 -> V_105 = V_152 << 16 ;
F_3 ( L_29 ,
V_98 -> V_84 , V_98 -> V_105 ) ;
F_3 ( L_28 , V_125 ) ;
if ( ! V_125 ) {
V_98 -> V_85 = V_16 -> V_112 ;
V_16 -> V_112 = V_98 ;
} else {
V_98 -> V_85 = V_18 -> V_112 ;
V_18 -> V_112 = V_98 ;
}
}
V_130 = V_154 + V_156 ;
if ( ( V_154 ) && ( V_130 < 0x10000 ) ) {
V_99 = F_18 ( sizeof( * V_99 ) , V_47 ) ;
if ( ! V_99 )
return - V_48 ;
V_99 -> V_84 = V_154 << 16 ;
V_99 -> V_105 = V_156 << 16 ;
F_3 ( L_30 ,
V_99 -> V_84 , V_99 -> V_105 ) ;
F_3 ( L_28 , V_125 ) ;
if ( ! V_125 ) {
V_99 -> V_85 = V_16 -> V_115 ;
V_16 -> V_115 = V_99 ;
} else {
V_99 -> V_85 = V_18 -> V_115 ;
V_18 -> V_115 = V_99 ;
}
}
if ( V_68 && ( V_68 != V_142 ) ) {
V_101 = F_18 ( sizeof( * V_101 ) , V_47 ) ;
if ( ! V_101 )
return - V_48 ;
V_101 -> V_84 = V_68 ;
V_101 -> V_105 = V_144 - V_68 + 1 ;
F_3 ( L_31 ,
V_101 -> V_84 , V_101 -> V_105 ) ;
F_3 ( L_28 , V_125 ) ;
if ( ! V_125 ) {
V_101 -> V_85 = V_16 -> V_106 ;
V_16 -> V_106 = V_101 ;
} else {
V_101 -> V_85 = V_18 -> V_106 ;
V_18 -> V_106 = V_101 ;
}
}
V_129 -- ;
V_127 += sizeof( struct V_158 ) ;
}
V_42 = 1 ;
V_42 &= F_43 ( & ( V_16 -> V_112 ) ) ;
V_42 &= F_43 ( & ( V_16 -> V_115 ) ) ;
V_42 &= F_43 ( & ( V_16 -> V_109 ) ) ;
V_42 &= F_43 ( & ( V_16 -> V_106 ) ) ;
return V_42 ;
}
int F_44 ( struct V_17 * V_18 , struct V_159 * V_160 )
{
int V_42 = 0 ;
struct V_97 * V_161 ;
struct V_97 * V_162 ;
F_3 ( L_32 , V_31 ) ;
if ( ! V_18 )
return 1 ;
V_161 = V_18 -> V_109 ;
V_18 -> V_109 = NULL ;
while ( V_161 ) {
V_162 = V_161 -> V_85 ;
F_45 ( & ( V_160 -> V_109 ) , V_161 ) ;
V_161 = V_162 ;
}
V_161 = V_18 -> V_112 ;
V_18 -> V_112 = NULL ;
while ( V_161 ) {
V_162 = V_161 -> V_85 ;
F_45 ( & ( V_160 -> V_112 ) , V_161 ) ;
V_161 = V_162 ;
}
V_161 = V_18 -> V_115 ;
V_18 -> V_115 = NULL ;
while ( V_161 ) {
V_162 = V_161 -> V_85 ;
F_45 ( & ( V_160 -> V_115 ) , V_161 ) ;
V_161 = V_162 ;
}
V_161 = V_18 -> V_106 ;
V_18 -> V_106 = NULL ;
while ( V_161 ) {
V_162 = V_161 -> V_85 ;
F_45 ( & ( V_160 -> V_106 ) , V_161 ) ;
V_161 = V_162 ;
}
V_42 |= F_43 ( & ( V_160 -> V_112 ) ) ;
V_42 |= F_43 ( & ( V_160 -> V_115 ) ) ;
V_42 |= F_43 ( & ( V_160 -> V_109 ) ) ;
V_42 |= F_43 ( & ( V_160 -> V_106 ) ) ;
return V_42 ;
}
void F_46 ( struct V_159 * V_160 )
{
struct V_97 * V_163 , * V_164 ;
V_163 = V_160 -> V_109 ;
V_160 -> V_109 = NULL ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_85 ;
F_19 ( V_164 ) ;
}
V_163 = V_160 -> V_112 ;
V_160 -> V_112 = NULL ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_85 ;
F_19 ( V_164 ) ;
}
V_163 = V_160 -> V_115 ;
V_160 -> V_115 = NULL ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_85 ;
F_19 ( V_164 ) ;
}
V_163 = V_160 -> V_106 ;
V_160 -> V_106 = NULL ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_85 ;
F_19 ( V_164 ) ;
}
}
void F_47 ( struct V_17 * V_18 )
{
struct V_97 * V_163 , * V_164 ;
V_163 = V_18 -> V_109 ;
V_18 -> V_109 = NULL ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_85 ;
F_19 ( V_164 ) ;
}
V_163 = V_18 -> V_112 ;
V_18 -> V_112 = NULL ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_85 ;
F_19 ( V_164 ) ;
}
V_163 = V_18 -> V_115 ;
V_18 -> V_115 = NULL ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_85 ;
F_19 ( V_164 ) ;
}
V_163 = V_18 -> V_106 ;
V_18 -> V_106 = NULL ;
while ( V_163 ) {
V_164 = V_163 ;
V_163 = V_163 -> V_85 ;
F_19 ( V_164 ) ;
}
}
