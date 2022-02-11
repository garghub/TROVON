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
#ifdef F_7
switch ( V_7 ) {
case V_8 :
F_8 ( L_1 ) ;
break;
case V_9 :
F_8 ( L_2 ) ;
break;
case V_10 :
F_8 ( L_3 ) ;
break;
case V_11 :
F_8 ( L_4 ) ;
break;
}
#endif
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_12 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( & V_2 -> V_12 ) )
F_13 ( V_2 ) ;
}
struct V_1 * F_14 ( const T_1 * V_13 )
{
struct V_1 * V_2 = F_15 ( sizeof( struct V_1 ) , V_14 ) ;
if ( V_2 ) {
int V_15 ;
F_16 ( & V_2 -> V_12 , 2 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_17 ( & V_2 -> V_17 [ V_15 ] ) ;
V_2 -> V_18 = 0xffffffff ;
F_6 ( V_2 , V_8 ) ;
V_2 -> V_19 = V_20 ;
memcpy ( V_2 -> V_13 , V_13 , V_21 ) ;
if ( 0 != F_18 ( & V_2 -> V_22 ) ) {
F_19 ( V_2 ) ;
V_2 = NULL ;
}
F_17 ( & V_2 -> V_23 ) ;
F_20 ( & V_2 -> V_24 ) ;
F_20 ( & V_2 -> V_25 ) ;
V_2 -> V_26 = & V_2 -> V_24 ;
F_17 ( & V_2 -> V_27 ) ;
F_20 ( & V_2 -> V_28 ) ;
}
return V_2 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
F_8 ( L_5 ) ;
V_30 = V_2 -> V_28 . V_37 ;
while ( V_30 != & V_2 -> V_28 ) {
V_34 = F_21 ( V_30 , struct V_33 , V_38 ) ;
V_30 = V_30 -> V_37 ;
F_22 ( V_34 ) ;
}
V_30 = V_2 -> V_24 . V_37 ;
while ( V_30 != & V_2 -> V_24 ) {
V_32 = F_21 ( V_30 , struct V_31 , V_38 ) ;
V_30 = V_30 -> V_37 ;
if ( V_32 -> V_39 != NULL )
F_23 ( V_32 -> V_39 ) ;
F_24 ( V_2 , V_32 ) ;
}
F_25 ( & V_2 -> V_22 ) ;
V_30 = V_2 -> V_25 . V_37 ;
while ( V_30 != & V_2 -> V_25 ) {
V_36 = F_21 ( V_30 , struct V_35 , V_38 ) ;
V_30 = V_30 -> V_37 ;
F_19 ( V_36 ) ;
}
while ( V_2 -> V_40 ) {
V_30 = V_2 -> V_40 ;
V_2 -> V_40 = V_30 -> V_37 ;
F_19 ( F_21 ( V_30 , struct V_31 , V_38 ) ) ;
}
if ( V_2 -> V_41 )
F_26 ( V_2 -> V_41 ) ;
F_19 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 , T_2 V_42 , int V_3 )
{
const struct V_43 * V_44 ;
int V_45 = 0 ;
F_8 ( L_6 , V_42 , V_3 ) ;
for ( V_44 = V_46 ; V_44 < & V_46 [ V_16 ] ; V_44 ++ ) {
if ( V_42 & ( 1 << V_44 -> V_47 ) ) {
if ( V_44 -> V_48 ( V_2 , V_3 ) ) {
V_45 = - 1 ;
F_8 ( L_7 ,
V_44 -> V_47 ) ;
break;
}
F_28 () ;
V_2 -> V_49 |= ( 1 << V_44 -> V_47 ) ;
if ( V_3 )
V_2 -> V_50 &= ~ ( 1 << V_44 -> V_47 ) ;
F_29 () ;
}
}
return V_45 ;
}
void F_30 ( struct V_1 * V_2 , T_2 V_42 , int V_4 )
{
const struct V_43 * V_44 ;
F_8 ( L_8 , V_42 , V_4 ) ;
for ( V_44 = V_46 ; V_44 < & V_46 [ V_16 ] ; V_44 ++ ) {
if ( V_42 & ( 1 << V_44 -> V_47 ) ) {
F_28 () ;
if ( V_4 ) {
V_2 -> V_50 |= ( 1 << V_44 -> V_47 ) ;
} else {
V_2 -> V_49 &= ~ ( 1 << V_44 -> V_47 ) ;
V_2 -> V_50 &= ~ ( 1 << V_44 -> V_47 ) ;
}
F_29 () ;
V_44 -> V_51 ( V_2 , V_4 ) ;
}
}
}
void F_31 ( struct V_1 * V_2 , T_2 V_42 )
{
const struct V_43 * V_44 ;
int V_52 = 0 ;
for ( V_44 = V_46 ; V_44 < & V_46 [ V_16 ] ; V_44 ++ ) {
if ( V_44 -> V_53 && ( V_42 & ( 1 << V_44 -> V_47 ) ) ) {
if ( V_44 -> V_53 ( V_2 ) )
V_52 = 1 ;
}
}
if ( V_52 )
F_32 ( V_2 ) ;
if ( V_2 -> V_54 & V_55 ) {
int V_56 = 8 ;
while ( V_56 -- && ( F_33 ( V_2 ) >= 0 ) )
;
}
}
void F_34 ( struct V_1 * V_2 )
{
T_2 V_57 = 0 ;
F_8 ( L_9 , V_2 -> V_7 ) ;
F_35 ( V_2 ) ;
F_28 () ;
V_57 = V_2 -> V_49 ;
V_2 -> V_49 = 0 ;
V_2 -> V_50 = 0 ;
F_29 () ;
F_30 ( V_2 , V_57 , 0 ) ;
F_28 () ;
F_6 ( V_2 , V_10 ) ;
F_36 ( & V_2 -> V_38 ) ;
F_29 () ;
F_8 ( L_10 , F_37 ( & V_2 -> V_12 ) ) ;
F_38 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_58 = 0 ;
T_2 V_57 = 0 ;
F_28 () ;
if ( V_2 -> V_7 & ( V_11 | V_10 ) ) {
F_29 () ;
return 0 ;
}
if ( V_2 -> V_59 && V_2 -> V_60 ) {
F_6 ( V_2 , V_11 ) ;
V_2 -> V_61 = V_62 + V_2 -> V_59 ;
F_8 ( L_11 ,
V_62 , V_2 -> V_61 ) ;
} else {
V_58 = 1 ;
}
V_57 = V_2 -> V_49 ;
F_29 () ;
if ( V_58 ) {
F_34 ( V_2 ) ;
} else {
F_30 ( V_2 , V_57 , 1 ) ;
F_40 ( V_2 , V_63 , V_62 + V_2 -> V_59 , 1 ) ;
}
return V_58 ;
}
static struct V_31 * F_41 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = NULL ;
F_42 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_40 ) {
V_32 = F_21 ( V_2 -> V_40 , struct V_31 , V_38 ) ;
V_2 -> V_40 = V_2 -> V_40 -> V_37 ;
V_2 -> V_64 -- ;
}
F_43 ( & V_2 -> V_23 ) ;
if ( V_32 == NULL )
V_32 = F_44 ( sizeof( struct V_31 ) , V_14 ) ;
if ( V_32 ) {
V_32 -> V_65 = sizeof( struct V_66 ) ;
F_20 ( & V_32 -> V_38 ) ;
F_20 ( & V_32 -> V_67 ) ;
}
return V_32 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
V_2 -> V_68 -- ;
F_46 ( & V_32 -> V_38 ) ;
if ( V_2 -> V_64 < V_69 ) {
V_32 -> V_38 . V_37 = V_2 -> V_40 ;
V_2 -> V_40 = & V_32 -> V_38 ;
V_2 -> V_64 ++ ;
} else {
F_19 ( V_32 ) ;
}
F_47 ( V_70 , L_12 ,
V_2 -> V_68 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
F_42 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_64 < V_69 ) {
V_32 -> V_38 . V_37 = V_2 -> V_40 ;
V_2 -> V_40 = & V_32 -> V_38 ;
V_2 -> V_64 ++ ;
V_32 = NULL ;
}
F_43 ( & V_2 -> V_23 ) ;
F_19 ( V_32 ) ;
}
static void F_49 ( struct V_71 * V_39 )
{
struct V_66 * V_66 = (struct V_66 * ) F_50 ( V_39 ) ;
V_66 -> V_72 |= V_73 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_71 * V_39 )
{
struct V_66 * V_66 = (struct V_66 * ) F_50 ( V_39 ) ;
V_66 -> V_74 = V_2 -> V_75 & V_76 ;
}
int F_52 ( struct V_1 * V_2 , int V_77 )
{
struct V_31 * V_32 ;
if ( ( V_2 -> V_54 & V_78 ) != V_79 )
return - 1 ;
if ( V_2 -> V_80 >= V_81 )
return - 1 ;
if ( ! V_77 && ! F_53 ( & V_2 -> V_22 ) )
return - 1 ;
V_32 = F_41 ( V_2 ) ;
if ( V_32 == NULL )
return - 1 ;
V_32 -> V_39 = NULL ;
V_32 -> V_82 . V_72 =
( V_83 << V_84 ) | V_85 ;
++ V_2 -> V_86 ;
F_54 ( F_55 ( V_2 -> V_86 ) , & V_32 -> V_82 . V_87 ) ;
if ( V_77 == 0 ) {
F_56 ( & V_2 -> V_22 , 0 , & V_32 -> V_65 ,
V_2 -> V_19 , & V_32 -> V_67 ) ;
}
F_57 ( & V_2 -> V_23 ) ;
F_58 ( & V_32 -> V_38 , & V_2 -> V_24 ) ;
V_2 -> V_80 ++ ;
F_59 ( & V_2 -> V_23 ) ;
return 0 ;
}
static struct V_71 * F_60 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_71 * V_39 ;
struct V_88 * V_89 = V_2 -> V_41 ;
struct V_66 * V_66 ;
struct V_5 * V_6 ;
struct V_29 * V_30 ;
V_39 = F_61 ( V_32 -> V_65 + F_62 ( V_89 ) , V_14 ) ;
if ( V_39 == NULL )
return NULL ;
F_63 ( V_39 , F_64 ( V_89 ) ) ;
F_65 ( V_39 ) ;
V_39 -> V_89 = V_89 ;
V_39 -> V_90 = F_66 ( V_91 ) ;
if ( F_67 ( V_39 , V_89 , V_91 , V_2 -> V_13 ,
V_89 -> V_92 , V_39 -> V_93 ) < 0 )
goto V_94;
V_66 = (struct V_66 * ) F_68 ( V_39 , V_32 -> V_65 ) ;
V_32 -> V_82 . V_74 = V_2 -> V_75 & V_76 ;
memcpy ( V_66 , & V_32 -> V_82 , sizeof( struct V_66 ) ) ;
V_6 = (struct V_5 * ) ( V_66 + 1 ) ;
for ( V_30 = V_32 -> V_67 . V_37 ; V_30 != & V_32 -> V_67 ; V_30 = V_30 -> V_37 ) {
struct V_95 * V_96 ;
V_96 = F_21 ( V_30 , struct V_95 , V_38 ) ;
memcpy ( V_6 , V_96 -> V_97 , V_96 -> V_98 ) ;
V_6 = F_69 ( V_6 ) ;
}
return V_39 ;
V_94:
F_23 ( V_39 ) ;
return NULL ;
}
static void F_24 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_29 * V_30 ;
struct V_95 * V_96 ;
V_30 = V_32 -> V_67 . V_37 ;
while ( V_30 != & V_32 -> V_67 ) {
V_96 = F_21 ( V_30 , struct V_95 , V_38 ) ;
V_30 = V_30 -> V_37 ;
F_46 ( & V_96 -> V_38 ) ;
if ( V_96 -> V_99 )
V_96 -> V_99 ( V_2 , V_96 -> V_100 ) ;
F_42 ( & V_2 -> V_22 . V_101 ) ;
F_70 ( & V_2 -> V_22 , V_96 ) ;
F_43 ( & V_2 -> V_22 . V_101 ) ;
}
F_48 ( V_2 , V_32 ) ;
if ( V_2 -> V_22 . V_102 > V_2 -> V_22 . V_103 )
F_71 ( & V_2 -> V_22 ) ;
}
static int F_72 ( struct V_1 * V_2 , int V_104 )
{
struct V_71 * V_39 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
F_57 ( & V_2 -> V_23 ) ;
V_30 = V_2 -> V_26 -> V_37 ;
if ( V_30 == & V_2 -> V_24 ) {
F_59 ( & V_2 -> V_23 ) ;
return - 1 ;
}
V_32 = F_21 ( V_30 , struct V_31 , V_38 ) ;
if ( V_32 -> V_39 != NULL ) {
V_39 = V_32 -> V_39 ;
F_45 ( V_2 , V_32 ) ;
F_59 ( & V_2 -> V_23 ) ;
if ( V_104 )
F_49 ( V_39 ) ;
F_51 ( V_2 , V_39 ) ;
if ( ( int ) F_37 ( & V_105 ) <
V_106 ) {
if ( F_73 ( V_39 ) < 0 ) {
F_47 ( V_70 ,
L_13 ) ;
return - 1 ;
}
F_10 ( & V_105 ) ;
F_47 ( V_70 ,
L_14 ,
V_2 -> V_68 ) ;
return 0 ;
} else {
F_23 ( V_39 ) ;
F_47 ( V_70 , L_15 ) ;
return - 1 ;
}
}
V_2 -> V_26 = V_30 ;
V_39 = F_60 ( V_2 , V_32 ) ;
F_59 ( & V_2 -> V_23 ) ;
if ( V_104 )
F_49 ( V_39 ) ;
F_47 ( V_70 , L_16 , V_32 -> V_82 . V_87 ) ;
if ( V_39 ) {
if ( F_73 ( V_39 ) < 0 )
return - 1 ;
}
return 0 ;
}
void F_74 ( struct V_1 * V_2 , int V_107 )
{
while ( F_52 ( V_2 , 0 ) >= 0 )
V_107 ++ ;
switch ( V_2 -> V_54 & ( V_108 | V_55 ) ) {
case V_108 : {
V_107 += V_2 -> V_68 ;
if ( V_107 <= 0 )
goto V_109;
if ( V_107 > V_106 )
V_107 = V_106 ;
break;
}
case V_110 : {
if ( ( V_107 <= 0 ) && ( V_2 -> V_111 == 0 ) )
goto V_109;
break;
}
default: {
if ( V_107 <= 0 )
goto V_109;
break;
}
}
while ( V_107 -- ) {
if ( F_72 ( V_2 , V_107 ) < 0 )
break;
}
return;
V_109: F_52 ( V_2 , 1 ) ;
F_72 ( V_2 , 0 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_71 * V_39 ;
struct V_88 * V_89 = V_2 -> V_41 ;
struct V_66 * V_66 ;
struct V_5 * V_6 ;
struct V_29 * V_30 ;
struct V_29 V_112 ;
int V_65 = sizeof( struct V_66 ) ;
F_20 ( & V_112 ) ;
F_56 ( & V_2 -> V_22 , 1 , & V_65 ,
V_2 -> V_19 , & V_112 ) ;
if ( V_112 . V_37 == & V_112 )
return 0 ;
V_39 = F_61 ( V_65 + F_62 ( V_89 ) , V_14 ) ;
if ( V_39 == NULL ) {
F_8 ( L_17 ) ;
F_75 ( & V_2 -> V_22 , & V_112 ) ;
return - 1 ;
}
F_63 ( V_39 , F_64 ( V_89 ) ) ;
F_65 ( V_39 ) ;
V_39 -> V_89 = V_89 ;
V_39 -> V_90 = F_66 ( V_91 ) ;
if ( F_67 ( V_39 , V_89 , V_91 , V_2 -> V_13 ,
V_89 -> V_92 , V_39 -> V_93 ) < 0 ) {
F_23 ( V_39 ) ;
return - 1 ;
}
V_66 = (struct V_66 * ) F_68 ( V_39 , V_65 ) ;
V_66 -> V_72 = ( V_83 << V_84 ) | V_113 ;
V_66 -> V_74 = V_2 -> V_75 & V_76 ;
V_6 = (struct V_5 * ) ( V_66 + 1 ) ;
for ( V_30 = V_112 . V_37 ; V_30 != & V_112 ; V_30 = V_30 -> V_37 ) {
struct V_95 * V_96 ;
V_96 = F_21 ( V_30 , struct V_95 , V_38 ) ;
memcpy ( V_6 , V_96 -> V_97 , V_96 -> V_98 ) ;
V_6 = F_69 ( V_6 ) ;
}
F_73 ( V_39 ) ;
F_75 ( & V_2 -> V_22 , & V_112 ) ;
return 0 ;
}
void F_76 ( struct V_1 * V_2 , T_1 V_114 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_29 * V_115 = NULL ;
struct V_29 * V_116 = NULL ;
T_1 V_117 ;
T_3 V_87 ;
F_57 ( & V_2 -> V_23 ) ;
V_30 = V_2 -> V_24 . V_37 ;
while ( V_30 != & V_2 -> V_24 ) {
V_32 = F_21 ( V_30 , struct V_31 , V_38 ) ;
V_87 = F_77 ( F_78 ( & V_32 -> V_82 . V_87 ) ) ;
V_117 = ( V_114 - ( V_87 & V_76 ) ) & V_76 ;
if ( ( V_117 > V_118 ) || ( V_87 == 0 ) )
break;
F_47 ( V_70 , L_18 ,
V_87 , V_2 -> V_80 ) ;
if ( V_115 == NULL )
V_115 = V_30 ;
V_116 = V_30 ;
V_30 = V_30 -> V_37 ;
V_2 -> V_80 -- ;
}
if ( V_115 ) {
V_116 -> V_37 -> V_119 = & V_2 -> V_24 ;
V_2 -> V_24 . V_37 = V_116 -> V_37 ;
V_116 -> V_37 = NULL ;
}
V_2 -> V_26 = & V_2 -> V_24 ;
F_59 ( & V_2 -> V_23 ) ;
while ( V_115 ) {
V_32 = F_21 ( V_115 , struct V_31 , V_38 ) ;
V_115 = V_115 -> V_37 ;
F_24 ( V_2 , V_32 ) ;
}
}
static struct V_33 * F_79 ( struct V_1 * V_2 , T_1 V_120 )
{
struct V_29 * V_30 ;
struct V_33 * V_34 ;
F_80 (e, &pd->stream_list) {
V_34 = F_21 ( V_30 , struct V_33 , V_38 ) ;
if ( V_34 -> V_120 == V_120 )
return V_34 ;
}
return NULL ;
}
int F_81 ( struct V_1 * V_2 , T_1 V_120 )
{
struct V_33 * V_34 =
F_15 ( sizeof( struct V_33 ) , V_14 ) ;
if ( ! V_34 )
return - V_121 ;
V_34 -> V_120 = V_120 ;
F_42 ( & V_2 -> V_27 ) ;
if ( ! F_79 ( V_2 , V_120 ) ) {
F_82 ( & V_34 -> V_38 , & V_2 -> V_28 ) ;
V_34 = NULL ;
}
F_43 ( & V_2 -> V_27 ) ;
F_19 ( V_34 ) ;
return 0 ;
}
static void F_22 ( struct V_33 * V_34 )
{
F_23 ( V_34 -> V_39 ) ;
F_19 ( V_34 ) ;
}
int F_83 ( struct V_1 * V_2 , T_1 V_120 )
{
struct V_33 * V_34 ;
F_42 ( & V_2 -> V_27 ) ;
V_34 = F_79 ( V_2 , V_120 ) ;
if ( V_34 )
F_36 ( & V_34 -> V_38 ) ;
F_43 ( & V_2 -> V_27 ) ;
if ( V_34 )
F_22 ( V_34 ) ;
return 0 ;
}
static void F_84 ( struct V_71 * V_39 )
{
F_85 ( & V_105 ) ;
}
int F_86 ( struct V_1 * V_2 , T_1 V_120 , const T_1 * V_97 , int V_93 )
{
struct V_88 * V_89 = V_2 -> V_41 ;
struct V_33 * V_34 ;
T_1 V_122 = 0 ;
struct V_71 * V_39 = NULL ;
struct V_66 * V_66 = NULL ;
int V_123 = 0 ;
F_42 ( & V_2 -> V_27 ) ;
V_34 = F_79 ( V_2 , V_120 ) ;
if ( V_34 ) {
V_39 = V_34 -> V_39 ;
V_34 -> V_39 = NULL ;
V_122 = V_34 -> V_122 ;
V_34 -> V_122 = 0 ;
V_66 = V_34 -> V_66 ;
V_123 = V_34 -> V_123 ;
}
F_43 ( & V_2 -> V_27 ) ;
if ( ! V_34 )
return 0 ;
if ( ! V_39 ) {
V_39 = F_61 ( V_2 -> V_19 + F_62 ( V_89 ) ,
V_14 ) ;
if ( V_39 == NULL )
return 0 ;
F_63 ( V_39 , F_64 ( V_89 ) ) ;
F_65 ( V_39 ) ;
V_39 -> V_89 = V_89 ;
V_39 -> V_90 = F_66 ( V_91 ) ;
V_39 -> V_124 = 0x7 ;
V_123 = sizeof( struct V_66 ) + sizeof( struct V_125 ) ;
V_66 = (struct V_66 * ) F_68 ( V_39 , V_123 ) ;
}
memcpy ( F_68 ( V_39 , V_93 ) , V_97 , V_93 ) ;
V_123 += V_93 ;
if ( ++ V_122 < V_2 -> V_126 ) {
F_42 ( & V_2 -> V_27 ) ;
V_34 -> V_39 = V_39 ;
V_34 -> V_122 = V_122 ;
V_34 -> V_66 = V_66 ;
V_34 -> V_123 = V_123 ;
F_43 ( & V_2 -> V_27 ) ;
} else {
struct V_66 V_127 ;
struct V_125 V_128 ;
F_42 ( & V_2 -> V_27 ) ;
V_128 . V_129 = V_34 -> V_130 ;
V_34 -> V_130 += V_122 ;
F_43 ( & V_2 -> V_27 ) ;
V_127 . V_72 =
( V_83 << V_84 ) | V_113 ;
V_127 . V_74 = V_2 -> V_75 & V_76 ;
V_127 . V_87 = 0 ;
V_128 . V_131 = V_120 ;
V_128 . V_132 = V_133 ;
V_128 . V_134 = V_122 ;
memcpy ( V_66 , & V_127 , sizeof( V_127 ) ) ;
memcpy ( V_66 + 1 , & V_128 , sizeof( V_128 ) ) ;
if ( F_67 ( V_39 , V_89 , V_91 , V_2 -> V_13 ,
V_89 -> V_92 , V_39 -> V_93 ) < 0 )
goto V_109;
V_39 -> V_135 = F_84 ;
if ( ! ( V_2 -> V_54 & V_55 ) ) {
struct V_31 * V_136 = NULL ;
int V_137 = V_2 -> V_68 ;
if ( V_137 >= V_2 -> V_138 ) {
F_47 ( V_70 ,
L_19 ,
V_137 ) ;
goto V_109;
}
V_136 = F_41 ( V_2 ) ;
if ( V_136 == NULL )
goto V_109;
V_136 -> V_82 = V_127 ;
V_136 -> V_39 = V_39 ;
F_42 ( & V_2 -> V_23 ) ;
F_58 ( & V_136 -> V_38 , & V_2 -> V_24 ) ;
V_2 -> V_68 ++ ;
F_43 ( & V_2 -> V_23 ) ;
F_47 ( V_70 ,
L_20 ,
V_2 -> V_68 , V_2 -> V_80 ) ;
return 0 ;
}
if ( F_37 ( & V_105 ) < V_106 ) {
F_10 ( & V_105 ) ;
if ( F_73 ( V_39 ) < 0 )
return - 1 ;
else
return 0 ;
}
V_109: F_23 ( V_39 ) ;
return - 1 ;
}
return 0 ;
}
void F_87 ( void )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
if ( V_46 [ V_15 ] . V_139 )
V_46 [ V_15 ] . V_139 () ;
}
void F_88 ( void )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
if ( V_46 [ V_15 ] . V_140 )
V_46 [ V_15 ] . V_140 () ;
}
void F_89 ( struct V_1 * V_2 , T_1 V_47 , struct V_5 * V_6 )
{
const struct V_43 * V_44 ;
if ( V_47 == 0 || V_47 > V_16 )
return;
V_44 = & V_46 [ V_47 - 1 ] ;
V_44 -> V_141 ( V_2 , V_6 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_35 * V_32 ;
const struct V_43 * V_44 = & V_46 [ V_142 - 1 ] ;
while ( 1 ) {
F_28 () ;
if ( F_90 ( & V_2 -> V_25 ) ) {
F_29 () ;
break;
}
V_32 = F_91 ( & V_2 -> V_25 ,
struct V_35 , V_38 ) ;
F_36 ( & V_32 -> V_38 ) ;
F_29 () ;
if ( V_44 -> V_143 )
V_44 -> V_143 ( V_2 , V_32 -> V_120 , V_32 -> V_144 , V_32 -> V_93 ) ;
F_19 ( V_32 ) ;
}
}
