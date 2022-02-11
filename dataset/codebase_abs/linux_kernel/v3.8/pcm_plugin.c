static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 = ( V_1 * 95 ) / 100 ;
unsigned int V_4 = ( V_1 * 105 ) / 100 ;
return V_2 >= V_3 && V_2 <= V_4 ;
}
static int F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 ;
T_2 V_10 ;
T_3 V_11 ;
unsigned int V_12 ;
struct V_13 * V_14 ;
if ( V_6 -> V_15 == V_16 ) {
V_9 = & V_6 -> V_17 ;
} else {
V_9 = & V_6 -> V_18 ;
}
if ( ( V_10 = F_3 ( V_9 -> V_9 ) ) < 0 )
return V_10 ;
V_11 = V_7 * V_9 -> V_19 * V_10 ;
if ( F_4 ( V_11 % 8 ) )
return - V_20 ;
V_11 /= 8 ;
if ( V_6 -> V_21 < V_7 ) {
F_5 ( V_6 -> V_22 ) ;
V_6 -> V_22 = F_6 ( V_11 ) ;
V_6 -> V_21 = V_7 ;
}
if ( ! V_6 -> V_22 ) {
V_6 -> V_21 = 0 ;
return - V_23 ;
}
V_14 = V_6 -> V_24 ;
if ( V_6 -> V_25 == V_26 ) {
for ( V_12 = 0 ; V_12 < V_9 -> V_19 ; V_12 ++ , V_14 ++ ) {
V_14 -> V_7 = V_7 ;
V_14 -> V_27 = 1 ;
V_14 -> V_28 = 0 ;
V_14 -> V_29 . V_30 = V_6 -> V_22 ;
V_14 -> V_29 . V_31 = V_12 * V_10 ;
V_14 -> V_29 . V_32 = V_9 -> V_19 * V_10 ;
}
} else if ( V_6 -> V_25 == V_33 ) {
if ( F_4 ( V_11 % V_9 -> V_19 ) )
return - V_34 ;
V_11 /= V_9 -> V_19 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_19 ; V_12 ++ , V_14 ++ ) {
V_14 -> V_7 = V_7 ;
V_14 -> V_27 = 1 ;
V_14 -> V_28 = 0 ;
V_14 -> V_29 . V_30 = V_6 -> V_22 + ( V_12 * V_11 ) ;
V_14 -> V_29 . V_31 = 0 ;
V_14 -> V_29 . V_32 = V_10 ;
}
} else
return - V_34 ;
return 0 ;
}
int F_7 ( struct V_35 * V_36 , T_1 V_7 )
{
int V_37 ;
if ( F_4 ( ! F_8 ( V_36 ) ) )
return - V_20 ;
if ( F_9 ( V_36 ) == V_16 ) {
struct V_5 * V_6 = F_8 ( V_36 ) ;
while ( V_6 -> V_38 ) {
if ( V_6 -> V_39 )
V_7 = V_6 -> V_39 ( V_6 , V_7 ) ;
if ( F_4 ( V_7 <= 0 ) )
return - V_20 ;
V_6 = V_6 -> V_38 ;
V_37 = F_2 ( V_6 , V_7 ) ;
if ( V_37 < 0 )
return V_37 ;
}
} else {
struct V_5 * V_6 = F_10 ( V_36 ) ;
while ( V_6 -> V_40 ) {
if ( V_6 -> V_41 )
V_7 = V_6 -> V_41 ( V_6 , V_7 ) ;
if ( F_4 ( V_7 <= 0 ) )
return - V_20 ;
V_6 = V_6 -> V_40 ;
V_37 = F_2 ( V_6 , V_7 ) ;
if ( V_37 < 0 )
return V_37 ;
}
}
return 0 ;
}
T_4 F_11 ( struct V_5 * V_6 ,
T_1 V_7 ,
struct V_13 * * V_19 )
{
* V_19 = V_6 -> V_24 ;
return V_7 ;
}
int F_12 ( struct V_35 * V_36 ,
const char * V_42 ,
struct V_8 * V_17 ,
struct V_8 * V_18 ,
T_3 V_43 ,
struct V_5 * * V_44 )
{
struct V_5 * V_6 ;
unsigned int V_19 ;
if ( F_4 ( ! V_36 ) )
return - V_20 ;
if ( F_4 ( ! V_17 || ! V_18 ) )
return - V_20 ;
V_6 = F_13 ( sizeof( * V_6 ) + V_43 , V_45 ) ;
if ( V_6 == NULL )
return - V_23 ;
V_6 -> V_42 = V_42 ;
V_6 -> V_36 = V_36 ;
V_6 -> V_15 = F_9 ( V_36 ) ;
V_6 -> V_25 = V_26 ;
V_6 -> V_17 = * V_17 ;
V_6 -> V_46 = F_3 ( V_17 -> V_9 ) ;
F_4 ( V_6 -> V_46 <= 0 ) ;
V_6 -> V_18 = * V_18 ;
V_6 -> V_47 = F_3 ( V_18 -> V_9 ) ;
F_4 ( V_6 -> V_47 <= 0 ) ;
if ( V_6 -> V_15 == V_16 )
V_19 = V_17 -> V_19 ;
else
V_19 = V_18 -> V_19 ;
V_6 -> V_24 = F_14 ( V_19 , sizeof( * V_6 -> V_24 ) , V_45 ) ;
if ( V_6 -> V_24 == NULL ) {
F_15 ( V_6 ) ;
return - V_23 ;
}
V_6 -> V_48 = F_11 ;
* V_44 = V_6 ;
return 0 ;
}
int F_15 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return 0 ;
if ( V_6 -> V_49 )
V_6 -> V_49 ( V_6 ) ;
F_16 ( V_6 -> V_24 ) ;
F_5 ( V_6 -> V_22 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
T_4 F_17 ( struct V_35 * V_36 , T_1 V_50 )
{
struct V_5 * V_6 , * V_51 , * V_52 ;
int V_15 ;
if ( F_4 ( ! V_36 ) )
return - V_20 ;
if ( V_50 == 0 )
return 0 ;
V_15 = F_9 ( V_36 ) ;
if ( V_15 == V_16 ) {
V_6 = F_10 ( V_36 ) ;
while ( V_6 && V_50 > 0 ) {
V_51 = V_6 -> V_40 ;
if ( V_6 -> V_41 )
V_50 = V_6 -> V_41 ( V_6 , V_50 ) ;
V_6 = V_51 ;
}
} else if ( V_15 == V_53 ) {
V_6 = F_8 ( V_36 ) ;
while ( V_6 && V_50 > 0 ) {
V_52 = V_6 -> V_38 ;
if ( V_6 -> V_39 )
V_50 = V_6 -> V_39 ( V_6 , V_50 ) ;
V_6 = V_52 ;
}
} else
F_18 () ;
return V_50 ;
}
T_4 F_19 ( struct V_35 * V_36 , T_1 V_54 )
{
struct V_5 * V_6 , * V_51 , * V_52 ;
T_4 V_7 ;
int V_15 ;
if ( F_4 ( ! V_36 ) )
return - V_20 ;
if ( V_54 == 0 )
return 0 ;
V_7 = V_54 ;
V_15 = F_9 ( V_36 ) ;
if ( V_15 == V_16 ) {
V_6 = F_8 ( V_36 ) ;
while ( V_6 && V_7 > 0 ) {
V_52 = V_6 -> V_38 ;
if ( V_6 -> V_39 ) {
V_7 = V_6 -> V_39 ( V_6 , V_7 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_6 = V_52 ;
}
} else if ( V_15 == V_53 ) {
V_6 = F_10 ( V_36 ) ;
while ( V_6 ) {
V_51 = V_6 -> V_40 ;
if ( V_6 -> V_41 ) {
V_7 = V_6 -> V_41 ( V_6 , V_7 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_6 = V_51 ;
}
} else
F_18 () ;
return V_7 ;
}
static int F_20 ( struct V_55 * V_56 , T_5 V_9 )
{
struct V_55 V_57 = * V_56 ;
T_6 V_58 = ( V_59 | V_60 |
V_61 | V_62 |
V_63 | V_64 |
V_65 | V_66 |
V_67 | V_68 |
V_69 | V_70 |
V_71 | V_72 |
V_73 | V_74 |
V_75 | V_76 ) ;
F_21 ( & V_57 , ( V_77 int ) V_78 ) ;
if ( V_57 . V_79 [ 0 ] & ( V_80 ) V_58 )
V_57 . V_79 [ 0 ] |= ( V_80 ) V_58 ;
if ( V_57 . V_79 [ 1 ] & ( V_80 ) ( V_58 >> 32 ) )
V_57 . V_79 [ 1 ] |= ( V_80 ) ( V_58 >> 32 ) ;
return F_22 ( & V_57 , ( V_77 int ) V_9 ) ;
}
T_5 F_23 ( T_5 V_9 ,
struct V_55 * V_81 )
{
int V_82 ;
if ( F_22 ( V_81 , ( V_77 int ) V_9 ) )
return V_9 ;
if ( ! F_20 ( V_81 , V_9 ) )
return ( V_77 T_5 ) - V_34 ;
if ( F_24 ( V_9 ) ) {
unsigned int V_10 = F_25 ( V_9 ) ;
int V_83 = F_26 ( V_9 ) > 0 ;
int V_84 = F_27 ( V_9 ) > 0 ;
unsigned int V_85 , V_86 = - 1 ;
T_5 V_87 = ( V_77 T_5 ) - 1 ;
for ( V_82 = 0 ; V_82 < F_28 ( V_88 ) ; V_82 ++ ) {
T_5 V_89 = V_88 [ V_82 ] ;
unsigned int V_90 ;
if ( ! F_22 ( V_81 , ( V_77 int ) V_89 ) )
continue;
V_90 = F_25 ( V_89 ) ;
if ( V_90 >= V_10 )
V_85 = V_90 - V_10 ;
else
V_85 = V_10 - V_90 + 32 ;
V_85 += F_26 ( V_89 ) != V_83 ;
V_85 += F_27 ( V_89 ) != V_84 ;
if ( V_85 < V_86 ) {
V_87 = V_89 ;
V_86 = V_85 ;
}
}
if ( ( V_77 int ) V_87 >= 0 )
return V_87 ;
else
return ( V_77 T_5 ) - V_34 ;
} else {
switch ( V_9 ) {
case V_78 :
for ( V_82 = 0 ; V_82 < F_28 ( V_88 ) ; ++ V_82 ) {
T_5 V_91 = V_88 [ V_82 ] ;
if ( F_22 ( V_81 , ( V_77 int ) V_91 ) )
return V_91 ;
}
default:
return ( V_77 T_5 ) - V_34 ;
}
}
}
int F_29 ( struct V_35 * V_36 ,
struct V_92 * V_93 ,
struct V_92 * V_94 )
{
struct V_8 V_95 ;
struct V_8 V_96 ;
struct V_8 V_97 ;
T_7 V_98 , V_99 ;
struct V_5 * V_6 = NULL ;
int V_37 ;
int V_15 = F_9 ( V_36 ) ;
int V_100 = ( F_30 ( V_94 ) == 1 ||
F_31 ( V_94 ) == V_26 ) ;
switch ( V_15 ) {
case V_16 :
V_96 . V_9 = F_32 ( V_94 ) ;
V_96 . V_101 = F_33 ( V_94 ) ;
V_96 . V_19 = F_30 ( V_94 ) ;
V_97 . V_9 = F_32 ( V_93 ) ;
V_97 . V_101 = F_33 ( V_93 ) ;
V_97 . V_19 = F_30 ( V_93 ) ;
V_98 = V_26 ;
V_99 = ( V_100 ? V_26 :
V_33 ) ;
break;
case V_53 :
V_96 . V_9 = F_32 ( V_93 ) ;
V_96 . V_101 = F_33 ( V_93 ) ;
V_96 . V_19 = F_30 ( V_93 ) ;
V_97 . V_9 = F_32 ( V_94 ) ;
V_97 . V_101 = F_33 ( V_94 ) ;
V_97 . V_19 = F_30 ( V_94 ) ;
V_98 = ( V_100 ? V_26 :
V_33 ) ;
V_99 = V_26 ;
break;
default:
F_18 () ;
return - V_34 ;
}
V_95 = V_97 ;
F_34 ( L_1 ,
V_97 . V_9 ,
V_97 . V_101 ,
V_97 . V_19 ) ;
F_34 ( L_2 ,
V_96 . V_9 ,
V_96 . V_101 ,
V_96 . V_19 ) ;
if ( ! F_1 ( V_97 . V_101 , V_96 . V_101 ) &&
! F_24 ( V_97 . V_9 ) ) {
if ( V_97 . V_9 != V_78 )
return - V_34 ;
V_95 . V_9 = V_102 ;
V_37 = F_35 ( V_36 ,
& V_97 , & V_95 ,
& V_6 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_36 ( V_6 ) ;
if ( V_37 < 0 ) {
F_15 ( V_6 ) ;
return V_37 ;
}
V_97 = V_95 ;
V_98 = V_99 ;
}
if ( V_97 . V_19 > V_96 . V_19 ) {
V_95 . V_19 = V_96 . V_19 ;
V_37 = F_37 ( V_36 , & V_97 , & V_95 , & V_6 ) ;
F_34 ( L_3 , V_97 . V_19 , V_95 . V_19 , V_37 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_36 ( V_6 ) ;
if ( V_37 < 0 ) {
F_15 ( V_6 ) ;
return V_37 ;
}
V_97 = V_95 ;
V_98 = V_99 ;
}
if ( ! F_1 ( V_97 . V_101 , V_96 . V_101 ) ) {
if ( V_97 . V_9 != V_102 ) {
V_95 . V_9 = V_102 ;
V_37 = F_38 ( V_36 ,
& V_97 , & V_95 ,
& V_6 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_36 ( V_6 ) ;
if ( V_37 < 0 ) {
F_15 ( V_6 ) ;
return V_37 ;
}
V_97 = V_95 ;
V_98 = V_99 ;
}
V_95 . V_101 = V_96 . V_101 ;
V_37 = F_39 ( V_36 ,
& V_97 , & V_95 ,
& V_6 ) ;
F_34 ( L_4 , V_97 . V_101 , V_95 . V_101 , V_37 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_36 ( V_6 ) ;
if ( V_37 < 0 ) {
F_15 ( V_6 ) ;
return V_37 ;
}
V_97 = V_95 ;
V_98 = V_99 ;
}
if ( V_97 . V_9 != V_96 . V_9 ) {
V_95 . V_9 = V_96 . V_9 ;
if ( V_97 . V_9 == V_78 ||
V_95 . V_9 == V_78 ) {
V_37 = F_35 ( V_36 ,
& V_97 , & V_95 ,
& V_6 ) ;
}
else if ( F_24 ( V_97 . V_9 ) &&
F_24 ( V_95 . V_9 ) ) {
V_37 = F_38 ( V_36 ,
& V_97 , & V_95 ,
& V_6 ) ;
}
else
return - V_34 ;
F_34 ( L_5 , V_97 . V_9 , V_95 . V_9 , V_37 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_36 ( V_6 ) ;
if ( V_37 < 0 ) {
F_15 ( V_6 ) ;
return V_37 ;
}
V_97 = V_95 ;
V_98 = V_99 ;
}
if ( V_97 . V_19 < V_96 . V_19 ) {
V_95 . V_19 = V_96 . V_19 ;
V_37 = F_37 ( V_36 , & V_97 , & V_95 , & V_6 ) ;
F_34 ( L_6 , V_97 . V_19 , V_95 . V_19 , V_37 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_36 ( V_6 ) ;
if ( V_37 < 0 ) {
F_15 ( V_6 ) ;
return V_37 ;
}
V_97 = V_95 ;
V_98 = V_99 ;
}
if ( V_98 != V_99 ) {
V_37 = F_40 ( V_36 ,
& V_97 ,
& V_95 ,
& V_6 ) ;
F_34 ( L_7 , V_37 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_36 ( V_6 ) ;
if ( V_37 < 0 ) {
F_15 ( V_6 ) ;
return V_37 ;
}
}
return 0 ;
}
T_4 F_41 ( struct V_35 * V_36 ,
char * V_22 ,
T_1 V_103 ,
struct V_13 * * V_19 )
{
struct V_5 * V_6 ;
struct V_13 * V_104 ;
struct V_8 * V_9 ;
int V_10 , V_105 , V_12 ;
int V_15 = F_9 ( V_36 ) ;
if ( F_4 ( ! V_22 ) )
return - V_20 ;
if ( V_15 == V_16 ) {
V_6 = F_8 ( V_36 ) ;
V_9 = & V_6 -> V_17 ;
} else {
V_6 = F_10 ( V_36 ) ;
V_9 = & V_6 -> V_18 ;
}
V_104 = V_6 -> V_24 ;
* V_19 = V_104 ;
if ( ( V_10 = F_3 ( V_9 -> V_9 ) ) < 0 )
return V_10 ;
V_105 = V_9 -> V_19 ;
if ( F_4 ( V_6 -> V_25 != V_26 &&
V_9 -> V_19 > 1 ) )
return - V_20 ;
for ( V_12 = 0 ; V_12 < V_105 ; V_12 ++ , V_104 ++ ) {
V_104 -> V_7 = V_103 ;
V_104 -> V_27 = 1 ;
V_104 -> V_28 = ( V_15 == V_53 ) ;
V_104 -> V_29 . V_30 = V_22 ;
V_104 -> V_29 . V_31 = V_12 * V_10 ;
V_104 -> V_29 . V_32 = V_105 * V_10 ;
}
return V_103 ;
}
T_4 F_42 ( struct V_35 * V_36 , struct V_13 * V_106 , T_1 V_11 )
{
struct V_5 * V_6 , * V_38 ;
struct V_13 * V_107 ;
int V_37 ;
T_4 V_7 = V_11 ;
V_6 = F_8 ( V_36 ) ;
while ( V_6 && V_7 > 0 ) {
if ( ( V_38 = V_6 -> V_38 ) != NULL ) {
T_4 V_108 = V_7 ;
if ( V_6 -> V_39 )
V_108 = V_6 -> V_39 ( V_6 , V_7 ) ;
if ( ( V_37 = V_38 -> V_48 ( V_38 , V_108 , & V_107 ) ) < 0 ) {
return V_37 ;
}
if ( V_37 != V_108 ) {
V_7 = V_37 ;
if ( V_6 -> V_41 )
V_7 = V_6 -> V_41 ( V_6 , V_108 ) ;
}
} else
V_107 = NULL ;
F_34 ( L_8 , V_6 -> V_42 , V_7 ) ;
if ( ( V_7 = V_6 -> V_109 ( V_6 , V_106 , V_107 , V_7 ) ) < 0 )
return V_7 ;
V_106 = V_107 ;
V_6 = V_38 ;
}
return F_17 ( V_36 , V_7 ) ;
}
T_4 F_43 ( struct V_35 * V_36 , struct V_13 * V_110 , T_1 V_11 )
{
struct V_5 * V_6 , * V_38 ;
struct V_13 * V_106 , * V_107 ;
T_4 V_7 = V_11 ;
int V_37 ;
V_7 = F_19 ( V_36 , V_7 ) ;
if ( V_7 < 0 )
return V_7 ;
V_106 = NULL ;
V_6 = F_8 ( V_36 ) ;
while ( V_6 && V_7 > 0 ) {
if ( ( V_38 = V_6 -> V_38 ) != NULL ) {
if ( ( V_37 = V_6 -> V_48 ( V_6 , V_7 , & V_107 ) ) < 0 ) {
return V_37 ;
}
V_7 = V_37 ;
} else {
V_107 = V_110 ;
}
F_34 ( L_9 , V_6 -> V_42 , V_7 ) ;
if ( ( V_7 = V_6 -> V_109 ( V_6 , V_106 , V_107 , V_7 ) ) < 0 )
return V_7 ;
V_6 = V_38 ;
V_106 = V_107 ;
}
return V_7 ;
}
int F_44 ( const struct V_111 * V_112 , T_3 V_113 ,
T_3 V_114 , T_5 V_9 )
{
unsigned char * V_115 ;
unsigned int V_116 ;
int V_10 ;
const unsigned char * V_117 ;
if ( ! V_112 -> V_30 )
return 0 ;
V_115 = V_112 -> V_30 + ( V_112 -> V_31 + V_112 -> V_32 * V_113 ) / 8 ;
V_10 = F_3 ( V_9 ) ;
if ( V_10 <= 0 )
return - V_34 ;
if ( V_112 -> V_32 == ( unsigned int ) V_10 && V_10 >= 8 )
return F_45 ( V_9 , V_115 , V_114 ) ;
V_117 = F_46 ( V_9 ) ;
if ( ! V_117 )
return - V_34 ;
V_116 = V_112 -> V_32 / 8 ;
if ( V_10 == 4 ) {
int V_118 = V_112 -> V_31 % 8 ;
int V_119 = V_112 -> V_32 % 8 ;
while ( V_114 -- > 0 ) {
if ( V_118 )
* V_115 &= 0xf0 ;
else
* V_115 &= 0x0f ;
V_115 += V_116 ;
V_118 += V_119 ;
if ( V_118 == 8 ) {
V_115 ++ ;
V_118 = 0 ;
}
}
} else {
V_10 /= 8 ;
while ( V_114 -- > 0 ) {
memcpy ( V_115 , V_117 , V_10 ) ;
V_115 += V_116 ;
}
}
return 0 ;
}
int F_47 ( const struct V_111 * V_120 , T_3 V_121 ,
const struct V_111 * V_112 , T_3 V_113 ,
T_3 V_114 , T_5 V_9 )
{
char * V_122 , * V_115 ;
int V_10 ;
int V_123 , V_116 ;
V_122 = V_120 -> V_30 + ( V_120 -> V_31 + V_120 -> V_32 * V_121 ) / 8 ;
if ( ! V_120 -> V_30 )
return F_44 ( V_112 , V_113 , V_114 , V_9 ) ;
V_115 = V_112 -> V_30 + ( V_112 -> V_31 + V_112 -> V_32 * V_113 ) / 8 ;
if ( ! V_112 -> V_30 )
return 0 ;
V_10 = F_3 ( V_9 ) ;
if ( V_10 <= 0 )
return - V_34 ;
if ( V_120 -> V_32 == ( unsigned int ) V_10 &&
V_112 -> V_32 == ( unsigned int ) V_10 && V_10 >= 8 ) {
T_3 V_124 = V_114 * V_10 / 8 ;
memcpy ( V_115 , V_122 , V_124 ) ;
return 0 ;
}
V_123 = V_120 -> V_32 / 8 ;
V_116 = V_112 -> V_32 / 8 ;
if ( V_10 == 4 ) {
int V_125 = V_120 -> V_31 % 8 ;
int V_126 = V_120 -> V_32 % 8 ;
int V_118 = V_112 -> V_31 % 8 ;
int V_119 = V_112 -> V_32 % 8 ;
while ( V_114 -- > 0 ) {
unsigned char V_127 ;
if ( V_125 )
V_127 = * V_122 & 0x0f ;
else
V_127 = ( * V_122 & 0xf0 ) >> 4 ;
if ( V_118 )
* V_115 = ( * V_115 & 0xf0 ) | V_127 ;
else
* V_115 = ( * V_115 & 0x0f ) | ( V_127 << 4 ) ;
V_122 += V_123 ;
V_125 += V_126 ;
if ( V_125 == 8 ) {
V_122 ++ ;
V_125 = 0 ;
}
V_115 += V_116 ;
V_118 += V_119 ;
if ( V_118 == 8 ) {
V_115 ++ ;
V_118 = 0 ;
}
}
} else {
V_10 /= 8 ;
while ( V_114 -- > 0 ) {
memcpy ( V_115 , V_122 , V_10 ) ;
V_122 += V_123 ;
V_115 += V_116 ;
}
}
return 0 ;
}
