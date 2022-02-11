static int F_1 ( void )
{
return 0 ;
}
static void F_2 ( void )
{
}
static int F_3 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , int V_4 )
{
}
static void F_5 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
}
void F_6 ( struct V_1 * V_2 , unsigned V_7 )
{
V_2 -> V_7 = V_7 ;
F_7 ( V_8 , 0 , 0 , 0 , V_7 ) ;
#ifdef F_8
switch ( V_7 ) {
case V_9 :
F_9 ( L_1 ) ;
break;
case V_10 :
F_9 ( L_2 ) ;
break;
case V_11 :
F_9 ( L_3 ) ;
break;
case V_12 :
F_9 ( L_4 ) ;
break;
}
#endif
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_13 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( F_13 ( & V_2 -> V_13 ) )
F_14 ( V_2 ) ;
}
struct V_1 * F_15 ( T_1 * V_14 )
{
struct V_1 * V_2 = F_16 ( sizeof( struct V_1 ) , V_15 ) ;
if ( V_2 ) {
int V_16 ;
F_17 ( & V_2 -> V_13 , 2 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
F_18 ( & V_2 -> V_18 [ V_16 ] ) ;
V_2 -> V_19 = 0xffffffff ;
F_6 ( V_2 , V_9 ) ;
V_2 -> V_20 = V_21 ;
memcpy ( V_2 -> V_14 , V_14 , V_22 ) ;
if ( 0 != F_19 ( & V_2 -> V_23 ) ) {
F_20 ( V_2 ) ;
V_2 = 0 ;
}
F_18 ( & V_2 -> V_24 ) ;
F_21 ( & V_2 -> V_25 ) ;
F_21 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = & V_2 -> V_25 ;
F_18 ( & V_2 -> V_28 ) ;
F_21 ( & V_2 -> V_29 ) ;
}
return V_2 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
F_9 ( L_5 ) ;
V_31 = V_2 -> V_29 . V_38 ;
while ( V_31 != & V_2 -> V_29 ) {
V_35 = F_22 ( V_31 , struct V_34 , V_39 ) ;
V_31 = V_31 -> V_38 ;
F_23 ( V_35 ) ;
}
V_31 = V_2 -> V_25 . V_38 ;
while ( V_31 != & V_2 -> V_25 ) {
V_33 = F_22 ( V_31 , struct V_32 , V_39 ) ;
V_31 = V_31 -> V_38 ;
if ( V_33 -> V_40 != NULL )
F_24 ( V_33 -> V_40 ) ;
F_25 ( V_2 , V_33 ) ;
}
F_26 ( & V_2 -> V_23 ) ;
V_31 = V_2 -> V_26 . V_38 ;
while ( V_31 != & V_2 -> V_26 ) {
V_37 = F_22 ( V_31 , struct V_36 , V_39 ) ;
V_31 = V_31 -> V_38 ;
F_20 ( V_37 ) ;
}
while ( V_2 -> V_41 ) {
V_31 = V_2 -> V_41 ;
V_2 -> V_41 = V_31 -> V_38 ;
F_20 ( F_22 ( V_31 , struct V_32 , V_39 ) ) ;
}
if ( V_2 -> V_42 )
F_27 ( V_2 -> V_42 ) ;
F_20 ( V_2 ) ;
}
int F_28 ( struct V_1 * V_2 , T_2 V_43 , int V_3 )
{
struct V_44 * V_45 ;
int V_46 = 0 ;
F_9 ( L_6 , V_43 , V_3 ) ;
for ( V_45 = V_47 ; V_45 < & V_47 [ V_17 ] ; V_45 ++ ) {
if ( V_43 & ( 1 << V_45 -> V_48 ) ) {
if ( V_45 -> V_49 ( V_2 , V_3 ) ) {
V_46 = - 1 ;
F_9 ( L_7 ,
V_45 -> V_48 ) ;
break;
}
F_29 () ;
V_2 -> V_50 |= ( 1 << V_45 -> V_48 ) ;
if ( V_3 )
V_2 -> V_51 &= ~ ( 1 << V_45 -> V_48 ) ;
F_30 () ;
}
}
return V_46 ;
}
void F_31 ( struct V_1 * V_2 , T_2 V_43 , int V_4 )
{
struct V_44 * V_45 ;
F_9 ( L_8 , V_43 , V_4 ) ;
for ( V_45 = V_47 ; V_45 < & V_47 [ V_17 ] ; V_45 ++ ) {
if ( V_43 & ( 1 << V_45 -> V_48 ) ) {
F_29 () ;
if ( V_4 ) {
V_2 -> V_51 |= ( 1 << V_45 -> V_48 ) ;
} else {
V_2 -> V_50 &= ~ ( 1 << V_45 -> V_48 ) ;
V_2 -> V_51 &= ~ ( 1 << V_45 -> V_48 ) ;
}
F_30 () ;
V_45 -> V_52 ( V_2 , V_4 ) ;
}
}
}
void F_32 ( struct V_1 * V_2 , T_2 V_43 )
{
struct V_44 * V_45 ;
int V_53 = 0 ;
for ( V_45 = V_47 ; V_45 < & V_47 [ V_17 ] ; V_45 ++ ) {
if ( V_45 -> V_54 && ( V_43 & ( 1 << V_45 -> V_48 ) ) ) {
if ( V_45 -> V_54 ( V_2 ) )
V_53 = 1 ;
}
}
if ( V_53 )
F_33 ( V_2 ) ;
if ( V_2 -> V_55 & V_56 ) {
int V_57 = 8 ;
while ( V_57 -- && ( F_34 ( V_2 ) >= 0 ) )
;
}
}
void F_35 ( struct V_1 * V_2 )
{
T_2 V_58 = 0 ;
F_9 ( L_9 , V_2 -> V_7 ) ;
F_36 ( V_2 ) ;
F_29 () ;
V_58 = V_2 -> V_50 ;
V_2 -> V_50 = 0 ;
V_2 -> V_51 = 0 ;
F_30 () ;
F_31 ( V_2 , V_58 , 0 ) ;
F_29 () ;
F_6 ( V_2 , V_11 ) ;
F_37 ( & V_2 -> V_39 ) ;
F_30 () ;
F_9 ( L_10 , F_38 ( & V_2 -> V_13 ) ) ;
F_39 ( V_2 , 0 ) ;
F_12 ( V_2 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_59 = 0 ;
T_2 V_58 = 0 ;
F_29 () ;
if ( V_2 -> V_7 & ( V_12 | V_11 ) ) {
F_30 () ;
return 0 ;
}
if ( V_2 -> V_60 && V_2 -> V_61 ) {
F_6 ( V_2 , V_12 ) ;
V_2 -> V_62 = V_63 + V_2 -> V_60 ;
F_9 ( L_11 ,
V_63 , V_2 -> V_62 ) ;
} else {
V_59 = 1 ;
}
V_58 = V_2 -> V_50 ;
F_30 () ;
if ( V_59 ) {
F_35 ( V_2 ) ;
} else {
F_31 ( V_2 , V_58 , 1 ) ;
F_41 ( V_2 , V_64 , V_63 + V_2 -> V_60 , 1 ) ;
}
return V_59 ;
}
static struct V_32 * F_42 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = 0 ;
F_43 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_41 ) {
V_33 = F_22 ( V_2 -> V_41 , struct V_32 , V_39 ) ;
V_2 -> V_41 = V_2 -> V_41 -> V_38 ;
V_2 -> V_65 -- ;
}
F_44 ( & V_2 -> V_24 ) ;
if ( V_33 == 0 )
V_33 = F_45 ( sizeof( struct V_32 ) , V_15 ) ;
if ( V_33 ) {
V_33 -> V_66 = sizeof( struct V_67 ) ;
F_21 ( & V_33 -> V_39 ) ;
F_21 ( & V_33 -> V_68 ) ;
}
return V_33 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
V_2 -> V_69 -- ;
F_47 ( & V_33 -> V_39 ) ;
if ( V_2 -> V_65 < V_70 ) {
V_33 -> V_39 . V_38 = V_2 -> V_41 ;
V_2 -> V_41 = & V_33 -> V_39 ;
V_2 -> V_65 ++ ;
} else {
F_20 ( V_33 ) ;
}
F_48 ( V_71 , L_12 ,
V_2 -> V_69 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
F_43 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_65 < V_70 ) {
V_33 -> V_39 . V_38 = V_2 -> V_41 ;
V_2 -> V_41 = & V_33 -> V_39 ;
V_2 -> V_65 ++ ;
V_33 = 0 ;
}
F_44 ( & V_2 -> V_24 ) ;
if ( V_33 )
F_20 ( V_33 ) ;
}
void F_50 ( struct V_72 * V_40 )
{
struct V_67 * V_67 = (struct V_67 * ) F_51 ( V_40 ) ;
V_67 -> V_73 |= V_74 ;
}
void F_52 ( struct V_1 * V_2 , struct V_72 * V_40 )
{
struct V_67 * V_67 = (struct V_67 * ) F_51 ( V_40 ) ;
V_67 -> V_75 = V_2 -> V_76 & V_77 ;
}
int F_53 ( struct V_1 * V_2 , int V_78 )
{
struct V_32 * V_33 ;
if ( ( V_2 -> V_55 & V_79 ) != V_80 )
return - 1 ;
if ( V_2 -> V_81 >= V_82 )
return - 1 ;
if ( ! V_78 && ! F_54 ( & V_2 -> V_23 ) )
return - 1 ;
V_33 = F_42 ( V_2 ) ;
if ( V_33 == 0 )
return - 1 ;
V_33 -> V_40 = NULL ;
V_33 -> V_83 . V_73 =
( V_84 << V_85 ) | V_86 ;
++ V_2 -> V_87 ;
F_55 ( F_56 ( V_2 -> V_87 ) , & V_33 -> V_83 . V_88 ) ;
if ( V_78 == 0 ) {
F_57 ( & V_2 -> V_23 , 0 , & V_33 -> V_66 ,
V_2 -> V_20 , & V_33 -> V_68 ) ;
}
F_58 ( & V_2 -> V_24 ) ;
F_59 ( & V_33 -> V_39 , & V_2 -> V_25 ) ;
V_2 -> V_81 ++ ;
F_60 ( & V_2 -> V_24 ) ;
return 0 ;
}
static struct V_72 * F_61 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_72 * V_40 = 0 ;
struct V_89 * V_90 = V_2 -> V_42 ;
struct V_67 * V_67 ;
struct V_5 * V_6 ;
struct V_30 * V_31 ;
V_40 = F_62 ( V_33 -> V_66 + F_63 ( V_90 ) , V_15 ) ;
if ( V_40 == 0 )
return 0 ;
F_64 ( V_40 , F_65 ( V_90 ) ) ;
F_66 ( V_40 ) ;
V_40 -> V_90 = V_90 ;
V_40 -> V_91 = F_67 ( V_92 ) ;
if ( F_68 ( V_40 , V_90 , V_92 , V_2 -> V_14 ,
V_90 -> V_93 , V_40 -> V_94 ) < 0 )
goto V_95;
V_67 = (struct V_67 * ) F_69 ( V_40 , V_33 -> V_66 ) ;
V_33 -> V_83 . V_75 = V_2 -> V_76 & V_77 ;
memcpy ( V_67 , & V_33 -> V_83 , sizeof( struct V_67 ) ) ;
V_6 = (struct V_5 * ) ( V_67 + 1 ) ;
for ( V_31 = V_33 -> V_68 . V_38 ; V_31 != & V_33 -> V_68 ; V_31 = V_31 -> V_38 ) {
struct V_96 * V_97 ;
V_97 = F_22 ( V_31 , struct V_96 , V_39 ) ;
memcpy ( V_6 , V_97 -> V_98 , V_97 -> V_99 ) ;
V_6 = F_70 ( V_6 ) ;
}
return V_40 ;
V_95:
F_24 ( V_40 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_30 * V_31 ;
struct V_96 * V_97 ;
V_31 = V_33 -> V_68 . V_38 ;
while ( V_31 != & V_33 -> V_68 ) {
V_97 = F_22 ( V_31 , struct V_96 , V_39 ) ;
V_31 = V_31 -> V_38 ;
F_47 ( & V_97 -> V_39 ) ;
if ( V_97 -> V_100 )
V_97 -> V_100 ( V_2 , V_97 -> V_101 ) ;
F_43 ( & V_2 -> V_23 . V_102 ) ;
F_71 ( & V_2 -> V_23 , V_97 ) ;
F_44 ( & V_2 -> V_23 . V_102 ) ;
}
F_49 ( V_2 , V_33 ) ;
if ( V_2 -> V_23 . V_103 > V_2 -> V_23 . V_104 )
F_72 ( & V_2 -> V_23 ) ;
}
static int F_73 ( struct V_1 * V_2 , int V_105 )
{
struct V_72 * V_40 ;
struct V_32 * V_33 ;
struct V_30 * V_31 ;
F_58 ( & V_2 -> V_24 ) ;
V_31 = V_2 -> V_27 -> V_38 ;
if ( V_31 == & V_2 -> V_25 ) {
F_60 ( & V_2 -> V_24 ) ;
return - 1 ;
}
V_33 = F_22 ( V_31 , struct V_32 , V_39 ) ;
if ( V_33 -> V_40 != NULL ) {
V_40 = V_33 -> V_40 ;
F_46 ( V_2 , V_33 ) ;
F_60 ( & V_2 -> V_24 ) ;
if ( V_105 )
F_50 ( V_40 ) ;
F_52 ( V_2 , V_40 ) ;
if ( ( int ) F_38 ( & V_106 ) <
V_107 ) {
if ( F_74 ( V_40 ) < 0 ) {
F_48 ( V_71 ,
L_13 ) ;
F_7 ( V_108 , 0 , 0 , 0 , 0 ) ;
return - 1 ;
}
F_11 ( & V_106 ) ;
F_48 ( V_71 ,
L_14 ,
V_2 -> V_69 ) ;
return 0 ;
} else {
F_24 ( V_40 ) ;
F_48 ( V_71 , L_15 ) ;
F_7 ( V_108 , 0 , 0 , 0 , 0 ) ;
return - 1 ;
}
}
V_2 -> V_27 = V_31 ;
V_40 = F_61 ( V_2 , V_33 ) ;
F_60 ( & V_2 -> V_24 ) ;
if ( V_105 )
F_50 ( V_40 ) ;
F_48 ( V_71 , L_16 , V_33 -> V_83 . V_88 ) ;
if ( V_40 ) {
F_7 ( V_109 ,
0 ,
( ( ( T_2 ) V_33 -> V_83 . V_73 ) << 8 ) | V_33 -> V_83 . V_75 ,
0 , V_33 -> V_83 . V_88 ) ;
if ( F_74 ( V_40 ) < 0 )
return - 1 ;
}
return 0 ;
}
void F_75 ( struct V_1 * V_2 , int V_110 )
{
while ( F_53 ( V_2 , 0 ) >= 0 )
V_110 ++ ;
switch ( V_2 -> V_55 & ( V_111 | V_56 ) ) {
case V_111 : {
V_110 += V_2 -> V_69 ;
if ( V_110 <= 0 )
goto V_112;
if ( V_110 > V_107 )
V_110 = V_107 ;
break;
}
case V_113 : {
if ( ( V_110 <= 0 ) && ( V_2 -> V_114 == 0 ) )
goto V_112;
break;
}
default: {
if ( V_110 <= 0 )
goto V_112;
break;
}
}
while ( V_110 -- ) {
if ( F_73 ( V_2 , V_110 ) < 0 )
break;
}
return;
V_112: F_53 ( V_2 , 1 ) ;
F_73 ( V_2 , 0 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_72 * V_40 = 0 ;
struct V_89 * V_90 = V_2 -> V_42 ;
struct V_67 * V_67 ;
struct V_5 * V_6 ;
struct V_30 * V_31 ;
struct V_30 V_115 ;
int V_66 = sizeof( struct V_67 ) ;
F_21 ( & V_115 ) ;
F_57 ( & V_2 -> V_23 , 1 , & V_66 ,
V_2 -> V_20 , & V_115 ) ;
if ( V_115 . V_38 == & V_115 )
return 0 ;
V_40 = F_62 ( V_66 + F_63 ( V_90 ) , V_15 ) ;
if ( V_40 == 0 ) {
F_9 ( L_17 ) ;
F_76 ( & V_2 -> V_23 , & V_115 ) ;
return - 1 ;
}
F_64 ( V_40 , F_65 ( V_90 ) ) ;
F_66 ( V_40 ) ;
V_40 -> V_90 = V_90 ;
V_40 -> V_91 = F_67 ( V_92 ) ;
if ( F_68 ( V_40 , V_90 , V_92 , V_2 -> V_14 ,
V_90 -> V_93 , V_40 -> V_94 ) < 0 ) {
F_24 ( V_40 ) ;
return - 1 ;
}
V_67 = (struct V_67 * ) F_69 ( V_40 , V_66 ) ;
V_67 -> V_73 = ( V_84 << V_85 ) | V_116 ;
V_67 -> V_75 = V_2 -> V_76 & V_77 ;
V_6 = (struct V_5 * ) ( V_67 + 1 ) ;
for ( V_31 = V_115 . V_38 ; V_31 != & V_115 ; V_31 = V_31 -> V_38 ) {
struct V_96 * V_97 ;
V_97 = F_22 ( V_31 , struct V_96 , V_39 ) ;
memcpy ( V_6 , V_97 -> V_98 , V_97 -> V_99 ) ;
V_6 = F_70 ( V_6 ) ;
}
F_7 ( V_117 , 0 , 0 , 0 , 0 ) ;
F_74 ( V_40 ) ;
F_76 ( & V_2 -> V_23 , & V_115 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 , T_1 V_118 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_30 * V_119 = 0 ;
struct V_30 * V_120 = 0 ;
T_1 V_121 ;
T_3 V_88 ;
F_58 ( & V_2 -> V_24 ) ;
V_31 = V_2 -> V_25 . V_38 ;
while ( V_31 != & V_2 -> V_25 ) {
V_33 = F_22 ( V_31 , struct V_32 , V_39 ) ;
V_88 = F_78 ( F_79 ( & V_33 -> V_83 . V_88 ) ) ;
V_121 = ( V_118 - ( V_88 & V_77 ) ) & V_77 ;
if ( ( V_121 > V_122 ) || ( V_88 == 0 ) )
break;
F_48 ( V_71 , L_18 ,
V_88 , V_2 -> V_81 ) ;
if ( V_119 == 0 )
V_119 = V_31 ;
V_120 = V_31 ;
V_31 = V_31 -> V_38 ;
V_2 -> V_81 -- ;
}
if ( V_119 ) {
V_120 -> V_38 -> V_123 = & V_2 -> V_25 ;
V_2 -> V_25 . V_38 = V_120 -> V_38 ;
V_120 -> V_38 = 0 ;
}
V_2 -> V_27 = & V_2 -> V_25 ;
F_60 ( & V_2 -> V_24 ) ;
while ( V_119 ) {
V_33 = F_22 ( V_119 , struct V_32 , V_39 ) ;
V_119 = V_119 -> V_38 ;
F_25 ( V_2 , V_33 ) ;
}
}
static struct V_34 * F_80 ( struct V_1 * V_2 , T_1 V_124 )
{
struct V_30 * V_31 ;
struct V_34 * V_35 ;
F_81 (e, &pd->stream_list) {
V_35 = F_22 ( V_31 , struct V_34 , V_39 ) ;
if ( V_35 -> V_124 == V_124 )
return V_35 ;
}
return 0 ;
}
int F_82 ( struct V_1 * V_2 , T_1 V_124 )
{
struct V_34 * V_35 =
F_16 ( sizeof( struct V_34 ) , V_15 ) ;
if ( ! V_35 )
return - V_125 ;
V_35 -> V_124 = V_124 ;
F_43 ( & V_2 -> V_28 ) ;
if ( ! F_80 ( V_2 , V_124 ) ) {
F_83 ( & V_35 -> V_39 , & V_2 -> V_29 ) ;
V_35 = 0 ;
}
F_44 ( & V_2 -> V_28 ) ;
if ( V_35 )
F_20 ( V_35 ) ;
return 0 ;
}
static void F_23 ( struct V_34 * V_35 )
{
F_24 ( V_35 -> V_40 ) ;
F_20 ( V_35 ) ;
}
int F_84 ( struct V_1 * V_2 , T_1 V_124 )
{
struct V_34 * V_35 ;
F_43 ( & V_2 -> V_28 ) ;
V_35 = F_80 ( V_2 , V_124 ) ;
if ( V_35 )
F_37 ( & V_35 -> V_39 ) ;
F_44 ( & V_2 -> V_28 ) ;
if ( V_35 )
F_23 ( V_35 ) ;
return 0 ;
}
static void F_85 ( struct V_72 * V_40 )
{
F_86 ( & V_106 ) ;
F_7 ( V_126 , F_38 ( & V_106 ) ,
0 , V_40 , 0 ) ;
}
int F_87 ( struct V_1 * V_2 , T_1 V_124 , T_1 * V_98 , int V_94 )
{
struct V_89 * V_90 = V_2 -> V_42 ;
struct V_34 * V_35 ;
T_1 V_127 = 0 ;
struct V_72 * V_40 = 0 ;
struct V_67 * V_67 = 0 ;
int V_128 = 0 ;
F_43 ( & V_2 -> V_28 ) ;
V_35 = F_80 ( V_2 , V_124 ) ;
if ( V_35 ) {
V_40 = V_35 -> V_40 ;
V_35 -> V_40 = 0 ;
V_127 = V_35 -> V_127 ;
V_35 -> V_127 = 0 ;
V_67 = V_35 -> V_67 ;
V_128 = V_35 -> V_128 ;
}
F_44 ( & V_2 -> V_28 ) ;
if ( ! V_35 )
return 0 ;
if ( ! V_40 ) {
V_40 = F_62 ( V_2 -> V_20 + F_63 ( V_90 ) ,
V_15 ) ;
if ( V_40 == 0 )
return 0 ;
F_64 ( V_40 , F_65 ( V_90 ) ) ;
F_66 ( V_40 ) ;
V_40 -> V_90 = V_90 ;
V_40 -> V_91 = F_67 ( V_92 ) ;
V_40 -> V_129 = 0x7 ;
V_128 = sizeof( struct V_67 ) + sizeof( struct V_130 ) ;
V_67 = (struct V_67 * ) F_69 ( V_40 , V_128 ) ;
}
memcpy ( F_69 ( V_40 , V_94 ) , V_98 , V_94 ) ;
V_128 += V_94 ;
if ( ++ V_127 < V_2 -> V_131 ) {
F_43 ( & V_2 -> V_28 ) ;
V_35 -> V_40 = V_40 ;
V_35 -> V_127 = V_127 ;
V_35 -> V_67 = V_67 ;
V_35 -> V_128 = V_128 ;
F_44 ( & V_2 -> V_28 ) ;
} else {
struct V_67 V_132 ;
struct V_130 V_133 ;
F_43 ( & V_2 -> V_28 ) ;
V_133 . V_134 = V_35 -> V_135 ;
V_35 -> V_135 += V_127 ;
F_44 ( & V_2 -> V_28 ) ;
V_132 . V_73 =
( V_84 << V_85 ) | V_116 ;
V_132 . V_75 = V_2 -> V_76 & V_77 ;
V_132 . V_88 = 0 ;
V_133 . V_136 = V_124 ;
V_133 . V_137 = V_138 ;
V_133 . V_139 = V_127 ;
memcpy ( V_67 , & V_132 , sizeof( V_132 ) ) ;
memcpy ( V_67 + 1 , & V_133 , sizeof( V_133 ) ) ;
if ( F_68 ( V_40 , V_90 , V_92 , V_2 -> V_14 ,
V_90 -> V_93 , V_40 -> V_94 ) < 0 )
goto V_112;
V_40 -> V_140 = F_85 ;
if ( ! ( V_2 -> V_55 & V_56 ) ) {
struct V_32 * V_141 = NULL ;
int V_142 = V_2 -> V_69 ;
if ( V_142 >= V_2 -> V_143 ) {
F_48 ( V_71 ,
L_19 ,
V_142 ) ;
goto V_112;
}
V_141 = F_42 ( V_2 ) ;
if ( V_141 == NULL )
goto V_112;
V_141 -> V_83 = V_132 ;
V_141 -> V_40 = V_40 ;
F_43 ( & V_2 -> V_24 ) ;
F_59 ( & V_141 -> V_39 , & V_2 -> V_25 ) ;
V_2 -> V_69 ++ ;
F_44 ( & V_2 -> V_24 ) ;
F_48 ( V_71 ,
L_20 ,
V_2 -> V_69 , V_2 -> V_81 ) ;
F_7 ( V_117 , V_127 , V_133 . V_134 ,
V_40 , F_38 ( & V_106 ) ) ;
return 0 ;
}
if ( F_38 ( & V_106 ) < V_107 ) {
F_11 ( & V_106 ) ;
F_7 ( V_117 , V_127 , V_133 . V_134 ,
V_40 , F_38 ( & V_106 ) ) ;
if ( F_74 ( V_40 ) < 0 ) {
F_7 ( V_108 , 0 , 0 , 0 , 0 ) ;
return - 1 ;
} else
return 0 ;
}
V_112: F_7 ( V_108 , 0 , 0 , 0 , 0 ) ;
F_24 ( V_40 ) ;
return - 1 ;
}
return 0 ;
}
void F_88 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( V_47 [ V_16 ] . V_144 )
V_47 [ V_16 ] . V_144 () ;
}
void F_89 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( V_47 [ V_16 ] . V_145 )
V_47 [ V_16 ] . V_145 () ;
}
void F_90 ( struct V_1 * V_2 , T_1 V_48 , struct V_5 * V_6 )
{
struct V_44 * V_45 ;
if ( V_48 == 0 || V_48 > V_17 )
return;
V_45 = & V_47 [ V_48 - 1 ] ;
V_45 -> V_146 ( V_2 , V_6 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_36 * V_33 ;
struct V_44 * V_45 = & V_47 [ V_147 - 1 ] ;
while ( 1 ) {
F_29 () ;
if ( F_91 ( & V_2 -> V_26 ) ) {
F_30 () ;
break;
}
V_33 = F_92 ( & V_2 -> V_26 ,
struct V_36 , V_39 ) ;
F_37 ( & V_33 -> V_39 ) ;
F_30 () ;
if ( V_45 -> V_148 )
V_45 -> V_148 ( V_2 , V_33 -> V_124 , V_33 -> V_149 , V_33 -> V_94 ) ;
F_20 ( V_33 ) ;
}
}
