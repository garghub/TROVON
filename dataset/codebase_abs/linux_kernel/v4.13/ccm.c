static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
unsigned long V_4 = F_2 ( F_3 ( V_3 ) ) ;
return ( void * ) F_4 ( ( V_5 * ) F_5 ( V_3 ) , V_4 + 1 ) ;
}
static int F_6 ( V_5 * V_6 , unsigned int V_7 , int V_8 )
{
T_1 V_9 ;
memset ( V_6 , 0 , V_8 ) ;
V_6 += V_8 ;
if ( V_8 >= 4 )
V_8 = 4 ;
else if ( V_7 > ( 1 << ( 8 * V_8 ) ) )
return - V_10 ;
V_9 = F_7 ( V_7 ) ;
memcpy ( V_6 - V_8 , ( V_5 * ) & V_9 + 4 - V_8 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 , const V_5 * V_13 ,
unsigned int V_14 )
{
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = V_16 -> V_20 ;
int V_21 = 0 ;
F_10 ( V_18 , V_22 ) ;
F_11 ( V_18 , F_12 ( V_12 ) &
V_22 ) ;
V_21 = F_13 ( V_18 , V_13 , V_14 ) ;
F_14 ( V_12 , F_15 ( V_18 ) &
V_23 ) ;
if ( V_21 )
goto V_24;
F_16 ( V_20 , V_22 ) ;
F_17 ( V_20 , F_12 ( V_12 ) &
V_22 ) ;
V_21 = F_18 ( V_20 , V_13 , V_14 ) ;
F_14 ( V_12 , F_19 ( V_20 ) &
V_23 ) ;
V_24:
return V_21 ;
}
static int F_20 ( struct V_11 * V_25 ,
unsigned int V_26 )
{
switch ( V_26 ) {
case 4 :
case 6 :
case 8 :
case 10 :
case 12 :
case 14 :
case 16 :
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_21 ( V_5 * V_28 , struct V_2 * V_3 ,
unsigned int V_29 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
unsigned int V_30 = V_3 -> V_31 [ 0 ] ;
unsigned int V_32 = V_30 + 1 ;
unsigned int V_33 ;
V_33 = F_22 ( V_12 ) ;
memcpy ( V_28 , V_3 -> V_31 , 16 ) ;
* V_28 |= ( 8 * ( ( V_33 - 2 ) / 2 ) ) ;
if ( V_3 -> V_34 )
* V_28 |= 64 ;
return F_6 ( V_28 + 16 - V_32 , V_29 , V_32 ) ;
}
static int F_23 ( V_5 * V_35 , unsigned int V_36 )
{
int V_37 = 0 ;
if ( V_36 < 65280 ) {
* ( V_38 * ) V_35 = F_24 ( V_36 ) ;
V_37 = 2 ;
} else {
* ( V_38 * ) V_35 = F_24 ( 0xfffe ) ;
* ( T_1 * ) & V_35 [ 2 ] = F_7 ( V_36 ) ;
V_37 = 6 ;
}
return V_37 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_39 * V_40 ,
unsigned int V_29 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_15 * V_16 = F_9 ( V_12 ) ;
F_26 ( V_42 , V_16 -> V_20 ) ;
unsigned int V_34 = V_3 -> V_34 ;
struct V_39 V_43 [ 3 ] ;
V_5 * V_44 = V_41 -> V_44 ;
V_5 * V_45 = V_41 -> V_45 ;
int V_46 , V_21 ;
V_21 = F_21 ( V_44 , V_3 , V_29 ) ;
if ( V_21 )
goto V_24;
F_27 ( V_43 , 3 ) ;
F_28 ( & V_43 [ 0 ] , V_44 , 16 ) ;
if ( V_34 ) {
V_46 = F_23 ( V_45 , V_34 ) ;
F_28 ( & V_43 [ 1 ] , V_45 , V_46 ) ;
F_29 ( V_43 , 3 , V_3 -> V_47 ) ;
} else {
V_46 = 0 ;
F_29 ( V_43 , 2 , V_3 -> V_47 ) ;
}
F_30 ( V_42 , V_16 -> V_20 ) ;
F_31 ( V_42 , V_41 -> V_48 , NULL , NULL ) ;
F_32 ( V_42 , V_43 , NULL , V_34 + V_46 + 16 ) ;
V_21 = F_33 ( V_42 ) ;
if ( V_21 )
goto V_24;
V_21 = F_34 ( V_42 ) ;
if ( V_21 )
goto V_24;
V_46 = 16 - ( V_34 + V_46 ) % 16 ;
if ( V_46 < 16 ) {
memset ( V_45 , 0 , V_46 ) ;
F_27 ( V_43 , 2 ) ;
F_28 ( & V_43 [ 0 ] , V_45 , V_46 ) ;
if ( V_40 )
F_29 ( V_43 , 2 , V_40 ) ;
V_40 = V_43 ;
V_29 += V_46 ;
}
F_32 ( V_42 , V_40 , V_41 -> V_44 , V_29 ) ;
V_21 = F_35 ( V_42 ) ;
V_24:
return V_21 ;
}
static void F_36 ( struct V_49 * V_50 , int V_21 )
{
struct V_2 * V_3 = V_50 -> V_9 ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_1 * V_41 = F_1 ( V_3 ) ;
V_5 * V_44 = V_41 -> V_44 ;
if ( ! V_21 )
F_37 ( V_44 , V_3 -> V_51 ,
V_3 -> V_34 + V_3 -> V_29 ,
F_22 ( V_12 ) , 1 ) ;
F_38 ( V_3 , V_21 ) ;
}
static inline int F_39 ( const V_5 * V_31 )
{
if ( 1 > V_31 [ 0 ] || V_31 [ 0 ] > 7 )
return - V_27 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , V_5 * V_52 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_39 * V_43 ;
V_5 * V_31 = V_3 -> V_31 ;
int V_21 ;
V_21 = F_39 ( V_31 ) ;
if ( V_21 )
return V_21 ;
V_41 -> V_48 = F_41 ( V_3 ) ;
memset ( V_31 + 15 - V_31 [ 0 ] , 0 , V_31 [ 0 ] + 1 ) ;
F_27 ( V_41 -> V_47 , 3 ) ;
F_28 ( V_41 -> V_47 , V_52 , 16 ) ;
V_43 = F_42 ( V_41 -> V_47 + 1 , V_3 -> V_47 , V_3 -> V_34 ) ;
if ( V_43 != V_41 -> V_47 + 1 )
F_29 ( V_41 -> V_47 , 2 , V_43 ) ;
if ( V_3 -> V_47 != V_3 -> V_51 ) {
F_27 ( V_41 -> V_51 , 3 ) ;
F_28 ( V_41 -> V_51 , V_52 , 16 ) ;
V_43 = F_42 ( V_41 -> V_51 + 1 , V_3 -> V_51 , V_3 -> V_34 ) ;
if ( V_43 != V_41 -> V_51 + 1 )
F_29 ( V_41 -> V_51 , 2 , V_43 ) ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_53 * V_54 = & V_41 -> V_54 ;
struct V_39 * V_51 ;
unsigned int V_29 = V_3 -> V_29 ;
V_5 * V_44 = V_41 -> V_44 ;
V_5 * V_31 = V_3 -> V_31 ;
int V_21 ;
V_21 = F_40 ( V_3 , V_44 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_25 ( V_3 , F_44 ( V_41 -> V_47 ) , V_29 ) ;
if ( V_21 )
return V_21 ;
V_51 = V_41 -> V_47 ;
if ( V_3 -> V_47 != V_3 -> V_51 )
V_51 = V_41 -> V_51 ;
F_45 ( V_54 , V_16 -> V_18 ) ;
F_46 ( V_54 , V_41 -> V_48 ,
F_36 , V_3 ) ;
F_47 ( V_54 , V_41 -> V_47 , V_51 , V_29 + 16 , V_31 ) ;
V_21 = F_48 ( V_54 ) ;
if ( V_21 )
return V_21 ;
F_37 ( V_44 , F_44 ( V_51 ) , V_29 ,
F_22 ( V_12 ) , 1 ) ;
return V_21 ;
}
static void F_49 ( struct V_49 * V_50 ,
int V_21 )
{
struct V_2 * V_3 = V_50 -> V_9 ;
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
unsigned int V_26 = F_22 ( V_12 ) ;
unsigned int V_29 = V_3 -> V_29 - V_26 ;
struct V_39 * V_51 ;
V_41 -> V_48 = 0 ;
V_51 = F_44 ( V_3 -> V_47 == V_3 -> V_51 ? V_41 -> V_47 : V_41 -> V_51 ) ;
if ( ! V_21 ) {
V_21 = F_25 ( V_3 , V_51 , V_29 ) ;
if ( ! V_21 && F_50 ( V_41 -> V_55 , V_41 -> V_44 , V_26 ) )
V_21 = - V_56 ;
}
F_38 ( V_3 , V_21 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_15 * V_16 = F_9 ( V_12 ) ;
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_53 * V_54 = & V_41 -> V_54 ;
struct V_39 * V_51 ;
unsigned int V_26 = F_22 ( V_12 ) ;
unsigned int V_29 = V_3 -> V_29 ;
V_5 * V_57 = V_41 -> V_55 ;
V_5 * V_44 = V_41 -> V_44 ;
V_5 * V_31 = V_3 -> V_31 ;
int V_21 ;
V_29 -= V_26 ;
V_21 = F_40 ( V_3 , V_57 ) ;
if ( V_21 )
return V_21 ;
F_37 ( V_57 , F_44 ( V_41 -> V_47 ) , V_29 ,
V_26 , 0 ) ;
V_51 = V_41 -> V_47 ;
if ( V_3 -> V_47 != V_3 -> V_51 )
V_51 = V_41 -> V_51 ;
F_45 ( V_54 , V_16 -> V_18 ) ;
F_46 ( V_54 , V_41 -> V_48 ,
F_49 , V_3 ) ;
F_47 ( V_54 , V_41 -> V_47 , V_51 , V_29 + 16 , V_31 ) ;
V_21 = F_52 ( V_54 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_25 ( V_3 , F_44 ( V_51 ) , V_29 ) ;
if ( V_21 )
return V_21 ;
if ( F_50 ( V_57 , V_44 , V_26 ) )
return - V_56 ;
return V_21 ;
}
static int F_53 ( struct V_11 * V_25 )
{
struct V_58 * V_59 = F_54 ( V_25 ) ;
struct V_60 * V_61 = F_55 ( V_59 ) ;
struct V_15 * V_16 = F_9 ( V_25 ) ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
unsigned long V_4 ;
int V_21 ;
V_20 = F_56 ( & V_61 -> V_20 ) ;
if ( F_57 ( V_20 ) )
return F_58 ( V_20 ) ;
V_18 = F_59 ( & V_61 -> V_18 ) ;
V_21 = F_58 ( V_18 ) ;
if ( F_57 ( V_18 ) )
goto V_62;
V_16 -> V_20 = V_20 ;
V_16 -> V_18 = V_18 ;
V_4 = F_2 ( V_25 ) ;
V_4 &= ~ ( F_60 () - 1 ) ;
F_61 (
V_25 ,
V_4 + sizeof( struct V_1 ) +
F_62 ( V_18 ) ) ;
return 0 ;
V_62:
F_63 ( V_20 ) ;
return V_21 ;
}
static void F_64 ( struct V_11 * V_25 )
{
struct V_15 * V_16 = F_9 ( V_25 ) ;
F_63 ( V_16 -> V_20 ) ;
F_65 ( V_16 -> V_18 ) ;
}
static void F_66 ( struct V_58 * V_59 )
{
struct V_60 * V_16 = F_55 ( V_59 ) ;
F_67 ( & V_16 -> V_20 ) ;
F_68 ( & V_16 -> V_18 ) ;
F_69 ( V_59 ) ;
}
static int F_70 ( struct V_63 * V_64 ,
struct V_65 * * V_66 ,
const char * V_67 ,
const char * V_68 ,
const char * V_69 )
{
struct V_70 * V_71 ;
struct V_58 * V_59 ;
struct V_72 * V_18 ;
struct V_73 * V_74 ;
struct V_75 * V_20 ;
struct V_60 * V_61 ;
int V_21 ;
V_71 = F_71 ( V_66 ) ;
if ( F_57 ( V_71 ) )
return F_58 ( V_71 ) ;
if ( ( V_71 -> type ^ V_76 ) & V_71 -> V_77 )
return - V_27 ;
V_74 = F_72 ( V_69 , & V_78 ,
V_79 ,
V_80 |
V_81 ) ;
if ( F_57 ( V_74 ) )
return F_58 ( V_74 ) ;
V_20 = F_73 ( V_74 ) ;
V_21 = - V_27 ;
if ( V_20 -> V_82 != 16 )
goto V_83;
V_59 = F_74 ( sizeof( * V_59 ) + sizeof( * V_61 ) , V_84 ) ;
V_21 = - V_85 ;
if ( ! V_59 )
goto V_83;
V_61 = F_55 ( V_59 ) ;
V_21 = F_75 ( & V_61 -> V_20 , V_20 ,
F_76 ( V_59 ) ) ;
if ( V_21 )
goto V_86;
F_77 ( & V_61 -> V_18 , F_76 ( V_59 ) ) ;
V_21 = F_78 ( & V_61 -> V_18 , V_68 , 0 ,
F_79 ( V_71 -> type ,
V_71 -> V_77 ) ) ;
if ( V_21 )
goto V_87;
V_18 = F_80 ( & V_61 -> V_18 ) ;
V_21 = - V_27 ;
if ( V_18 -> V_88 . V_89 != 1 )
goto V_90;
if ( F_81 ( V_18 ) != 16 )
goto V_90;
V_21 = - V_91 ;
if ( snprintf ( V_59 -> V_92 . V_88 . V_93 , V_94 ,
L_1 , V_18 -> V_88 . V_93 ,
V_20 -> V_88 . V_93 ) >= V_94 )
goto V_90;
memcpy ( V_59 -> V_92 . V_88 . V_95 , V_67 , V_94 ) ;
V_59 -> V_92 . V_88 . V_96 = V_18 -> V_88 . V_96 & V_81 ;
V_59 -> V_92 . V_88 . V_97 = ( V_20 -> V_88 . V_97 +
V_18 -> V_88 . V_97 ) / 2 ;
V_59 -> V_92 . V_88 . V_89 = 1 ;
V_59 -> V_92 . V_88 . V_98 = V_20 -> V_88 . V_98 |
V_18 -> V_88 . V_98 ;
V_59 -> V_92 . V_99 = 16 ;
V_59 -> V_92 . V_100 = F_82 ( V_18 ) ;
V_59 -> V_92 . V_101 = 16 ;
V_59 -> V_92 . V_88 . V_102 = sizeof( struct V_15 ) ;
V_59 -> V_92 . V_103 = F_53 ;
V_59 -> V_92 . exit = F_64 ;
V_59 -> V_92 . V_104 = F_8 ;
V_59 -> V_92 . V_105 = F_20 ;
V_59 -> V_92 . V_106 = F_43 ;
V_59 -> V_92 . V_107 = F_51 ;
V_59 -> free = F_66 ;
V_21 = F_83 ( V_64 , V_59 ) ;
if ( V_21 )
goto V_90;
V_83:
F_84 ( V_74 ) ;
return V_21 ;
V_90:
F_68 ( & V_61 -> V_18 ) ;
V_87:
F_67 ( & V_61 -> V_20 ) ;
V_86:
F_69 ( V_59 ) ;
goto V_83;
}
static int F_85 ( struct V_63 * V_64 , struct V_65 * * V_66 )
{
const char * V_108 ;
char V_68 [ V_94 ] ;
char V_69 [ V_94 ] ;
char V_67 [ V_94 ] ;
V_108 = F_86 ( V_66 [ 1 ] ) ;
if ( F_57 ( V_108 ) )
return F_58 ( V_108 ) ;
if ( snprintf ( V_68 , V_94 , L_2 ,
V_108 ) >= V_94 )
return - V_91 ;
if ( snprintf ( V_69 , V_94 , L_3 ,
V_108 ) >= V_94 )
return - V_91 ;
if ( snprintf ( V_67 , V_94 , L_4 , V_108 ) >=
V_94 )
return - V_91 ;
return F_70 ( V_64 , V_66 , V_67 , V_68 ,
V_69 ) ;
}
static int F_87 ( struct V_63 * V_64 ,
struct V_65 * * V_66 )
{
const char * V_68 ;
const char * V_108 ;
char V_67 [ V_94 ] ;
V_68 = F_86 ( V_66 [ 1 ] ) ;
if ( F_57 ( V_68 ) )
return F_58 ( V_68 ) ;
V_108 = F_86 ( V_66 [ 2 ] ) ;
if ( F_57 ( V_108 ) )
return F_58 ( V_108 ) ;
if ( snprintf ( V_67 , V_94 , L_1 ,
V_68 , V_108 ) >= V_94 )
return - V_91 ;
return F_70 ( V_64 , V_66 , V_67 , V_68 ,
V_108 ) ;
}
static int F_88 ( struct V_11 * V_109 , const V_5 * V_13 ,
unsigned int V_14 )
{
struct V_110 * V_16 = F_9 ( V_109 ) ;
struct V_11 * V_111 = V_16 -> V_111 ;
int V_21 ;
if ( V_14 < 3 )
return - V_27 ;
V_14 -= 3 ;
memcpy ( V_16 -> V_112 , V_13 + V_14 , 3 ) ;
F_89 ( V_111 , V_22 ) ;
F_14 ( V_111 , F_12 ( V_109 ) &
V_22 ) ;
V_21 = F_90 ( V_111 , V_13 , V_14 ) ;
F_14 ( V_109 , F_12 ( V_111 ) &
V_23 ) ;
return V_21 ;
}
static int F_91 ( struct V_11 * V_109 ,
unsigned int V_26 )
{
struct V_110 * V_16 = F_9 ( V_109 ) ;
switch ( V_26 ) {
case 8 :
case 12 :
case 16 :
break;
default:
return - V_27 ;
}
return F_92 ( V_16 -> V_111 , V_26 ) ;
}
static struct V_2 * F_93 ( struct V_2 * V_3 )
{
struct V_113 * V_114 = F_5 ( V_3 ) ;
struct V_2 * V_115 = & V_114 -> V_115 ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_110 * V_16 = F_9 ( V_12 ) ;
struct V_11 * V_111 = V_16 -> V_111 ;
struct V_39 * V_43 ;
V_5 * V_31 = F_4 ( ( V_5 * ) ( V_115 + 1 ) + F_94 ( V_111 ) ,
F_2 ( V_111 ) + 1 ) ;
V_31 [ 0 ] = 3 ;
memcpy ( V_31 + 1 , V_16 -> V_112 , 3 ) ;
memcpy ( V_31 + 4 , V_3 -> V_31 , 8 ) ;
F_37 ( V_31 + 16 , V_3 -> V_47 , 0 , V_3 -> V_34 - 8 , 0 ) ;
F_27 ( V_114 -> V_47 , 3 ) ;
F_28 ( V_114 -> V_47 , V_31 + 16 , V_3 -> V_34 - 8 ) ;
V_43 = F_42 ( V_114 -> V_47 + 1 , V_3 -> V_47 , V_3 -> V_34 ) ;
if ( V_43 != V_114 -> V_47 + 1 )
F_29 ( V_114 -> V_47 , 2 , V_43 ) ;
if ( V_3 -> V_47 != V_3 -> V_51 ) {
F_27 ( V_114 -> V_51 , 3 ) ;
F_28 ( V_114 -> V_51 , V_31 + 16 , V_3 -> V_34 - 8 ) ;
V_43 = F_42 ( V_114 -> V_51 + 1 , V_3 -> V_51 , V_3 -> V_34 ) ;
if ( V_43 != V_114 -> V_51 + 1 )
F_29 ( V_114 -> V_51 , 2 , V_43 ) ;
}
F_95 ( V_115 , V_111 ) ;
F_96 ( V_115 , V_3 -> V_88 . V_48 , V_3 -> V_88 . V_116 ,
V_3 -> V_88 . V_9 ) ;
F_97 ( V_115 , V_114 -> V_47 ,
V_3 -> V_47 == V_3 -> V_51 ? V_114 -> V_47 : V_114 -> V_51 ,
V_3 -> V_29 , V_31 ) ;
F_98 ( V_115 , V_3 -> V_34 - 8 ) ;
return V_115 ;
}
static int F_99 ( struct V_2 * V_3 )
{
if ( V_3 -> V_34 != 16 && V_3 -> V_34 != 20 )
return - V_27 ;
V_3 = F_93 ( V_3 ) ;
return F_100 ( V_3 ) ;
}
static int F_101 ( struct V_2 * V_3 )
{
if ( V_3 -> V_34 != 16 && V_3 -> V_34 != 20 )
return - V_27 ;
V_3 = F_93 ( V_3 ) ;
return F_102 ( V_3 ) ;
}
static int F_103 ( struct V_11 * V_25 )
{
struct V_58 * V_59 = F_54 ( V_25 ) ;
struct V_117 * V_118 = F_55 ( V_59 ) ;
struct V_110 * V_16 = F_9 ( V_25 ) ;
struct V_11 * V_12 ;
unsigned long V_4 ;
V_12 = F_104 ( V_118 ) ;
if ( F_57 ( V_12 ) )
return F_58 ( V_12 ) ;
V_16 -> V_111 = V_12 ;
V_4 = F_2 ( V_12 ) ;
V_4 &= ~ ( F_60 () - 1 ) ;
F_61 (
V_25 ,
sizeof( struct V_113 ) +
F_105 ( F_94 ( V_12 ) , F_60 () ) +
V_4 + 32 ) ;
return 0 ;
}
static void F_106 ( struct V_11 * V_25 )
{
struct V_110 * V_16 = F_9 ( V_25 ) ;
F_107 ( V_16 -> V_111 ) ;
}
static void F_108 ( struct V_58 * V_59 )
{
F_109 ( F_55 ( V_59 ) ) ;
F_69 ( V_59 ) ;
}
static int F_110 ( struct V_63 * V_64 ,
struct V_65 * * V_66 )
{
struct V_70 * V_71 ;
struct V_58 * V_59 ;
struct V_117 * V_118 ;
struct V_119 * V_92 ;
const char * V_120 ;
int V_21 ;
V_71 = F_71 ( V_66 ) ;
if ( F_57 ( V_71 ) )
return F_58 ( V_71 ) ;
if ( ( V_71 -> type ^ V_76 ) & V_71 -> V_77 )
return - V_27 ;
V_120 = F_86 ( V_66 [ 1 ] ) ;
if ( F_57 ( V_120 ) )
return F_58 ( V_120 ) ;
V_59 = F_74 ( sizeof( * V_59 ) + sizeof( * V_118 ) , V_84 ) ;
if ( ! V_59 )
return - V_85 ;
V_118 = F_55 ( V_59 ) ;
F_111 ( V_118 , F_76 ( V_59 ) ) ;
V_21 = F_112 ( V_118 , V_120 , 0 ,
F_79 ( V_71 -> type , V_71 -> V_77 ) ) ;
if ( V_21 )
goto V_121;
V_92 = F_113 ( V_118 ) ;
V_21 = - V_27 ;
if ( F_114 ( V_92 ) != 16 )
goto V_122;
if ( V_92 -> V_88 . V_89 != 1 )
goto V_122;
V_21 = - V_91 ;
if ( snprintf ( V_59 -> V_92 . V_88 . V_95 , V_94 ,
L_5 , V_92 -> V_88 . V_95 ) >=
V_94 ||
snprintf ( V_59 -> V_92 . V_88 . V_93 , V_94 ,
L_5 , V_92 -> V_88 . V_93 ) >=
V_94 )
goto V_122;
V_59 -> V_92 . V_88 . V_96 = V_92 -> V_88 . V_96 & V_81 ;
V_59 -> V_92 . V_88 . V_97 = V_92 -> V_88 . V_97 ;
V_59 -> V_92 . V_88 . V_89 = 1 ;
V_59 -> V_92 . V_88 . V_98 = V_92 -> V_88 . V_98 ;
V_59 -> V_92 . V_99 = 8 ;
V_59 -> V_92 . V_100 = F_115 ( V_92 ) ;
V_59 -> V_92 . V_101 = 16 ;
V_59 -> V_92 . V_88 . V_102 = sizeof( struct V_110 ) ;
V_59 -> V_92 . V_103 = F_103 ;
V_59 -> V_92 . exit = F_106 ;
V_59 -> V_92 . V_104 = F_88 ;
V_59 -> V_92 . V_105 = F_91 ;
V_59 -> V_92 . V_106 = F_99 ;
V_59 -> V_92 . V_107 = F_101 ;
V_59 -> free = F_108 ;
V_21 = F_83 ( V_64 , V_59 ) ;
if ( V_21 )
goto V_122;
V_24:
return V_21 ;
V_122:
F_109 ( V_118 ) ;
V_121:
F_69 ( V_59 ) ;
goto V_24;
}
static int F_116 ( struct V_123 * V_109 ,
const V_5 * V_124 , unsigned int V_14 )
{
struct V_125 * V_16 = F_117 ( V_109 ) ;
return F_118 ( V_16 -> V_111 , V_124 , V_14 ) ;
}
static int F_119 ( struct V_126 * V_127 )
{
struct V_128 * V_16 = F_120 ( V_127 ) ;
int V_129 = F_121 ( V_127 -> V_25 ) ;
V_5 * V_130 = ( V_5 * ) V_16 + F_122 ( V_127 -> V_25 ) - V_129 ;
V_16 -> V_37 = 0 ;
memset ( V_130 , 0 , V_129 ) ;
return 0 ;
}
static int F_123 ( struct V_126 * V_127 , const V_5 * V_131 ,
unsigned int V_37 )
{
struct V_123 * V_109 = V_127 -> V_25 ;
struct V_125 * V_132 = F_117 ( V_109 ) ;
struct V_128 * V_16 = F_120 ( V_127 ) ;
struct V_133 * V_25 = V_132 -> V_111 ;
int V_129 = F_121 ( V_109 ) ;
V_5 * V_130 = ( V_5 * ) V_16 + F_122 ( V_109 ) - V_129 ;
while ( V_37 > 0 ) {
unsigned int V_32 = F_124 ( V_37 , V_129 - V_16 -> V_37 ) ;
F_125 ( V_130 + V_16 -> V_37 , V_131 , V_32 ) ;
V_16 -> V_37 += V_32 ;
V_37 -= V_32 ;
V_131 += V_32 ;
if ( V_16 -> V_37 == V_129 ) {
F_126 ( V_25 , V_130 , V_130 ) ;
V_16 -> V_37 = 0 ;
}
}
return 0 ;
}
static int F_127 ( struct V_126 * V_127 , V_5 * V_24 )
{
struct V_123 * V_109 = V_127 -> V_25 ;
struct V_125 * V_132 = F_117 ( V_109 ) ;
struct V_128 * V_16 = F_120 ( V_127 ) ;
struct V_133 * V_25 = V_132 -> V_111 ;
int V_129 = F_121 ( V_109 ) ;
V_5 * V_130 = ( V_5 * ) V_16 + F_122 ( V_109 ) - V_129 ;
if ( V_16 -> V_37 )
F_126 ( V_25 , V_130 , V_130 ) ;
memcpy ( V_24 , V_130 , V_129 ) ;
return 0 ;
}
static int F_128 ( struct V_134 * V_25 )
{
struct V_133 * V_135 ;
struct V_136 * V_59 = ( void * ) V_25 -> V_137 ;
struct V_138 * V_118 = F_129 ( V_59 ) ;
struct V_125 * V_16 = F_130 ( V_25 ) ;
V_135 = F_131 ( V_118 ) ;
if ( F_57 ( V_135 ) )
return F_58 ( V_135 ) ;
V_16 -> V_111 = V_135 ;
return 0 ;
}
static void F_132 ( struct V_134 * V_25 )
{
struct V_125 * V_16 = F_130 ( V_25 ) ;
F_133 ( V_16 -> V_111 ) ;
}
static int F_134 ( struct V_63 * V_64 , struct V_65 * * V_66 )
{
struct V_139 * V_59 ;
struct V_73 * V_92 ;
int V_21 ;
V_21 = F_135 ( V_66 , V_140 ) ;
if ( V_21 )
return V_21 ;
V_92 = F_136 ( V_66 , V_141 ,
V_142 ) ;
if ( F_57 ( V_92 ) )
return F_58 ( V_92 ) ;
V_59 = F_137 ( L_6 , V_92 ) ;
V_21 = F_58 ( V_59 ) ;
if ( F_57 ( V_59 ) )
goto V_143;
V_21 = F_138 ( F_139 ( V_59 ) , V_92 ,
F_140 ( V_59 ) ,
V_142 ) ;
if ( V_21 )
goto V_121;
V_59 -> V_92 . V_88 . V_97 = V_92 -> V_97 ;
V_59 -> V_92 . V_88 . V_89 = 1 ;
V_59 -> V_92 . V_82 = V_92 -> V_89 ;
V_59 -> V_92 . V_144 = F_105 ( sizeof( struct V_128 ) ,
V_92 -> V_98 + 1 ) +
V_92 -> V_89 ;
V_59 -> V_92 . V_88 . V_102 = sizeof( struct V_125 ) ;
V_59 -> V_92 . V_88 . V_145 = F_128 ;
V_59 -> V_92 . V_88 . V_146 = F_132 ;
V_59 -> V_92 . V_103 = F_119 ;
V_59 -> V_92 . V_147 = F_123 ;
V_59 -> V_92 . V_148 = F_127 ;
V_59 -> V_92 . V_104 = F_116 ;
V_21 = F_141 ( V_64 , V_59 ) ;
V_121:
if ( V_21 )
F_142 ( F_140 ( V_59 ) ) ;
V_143:
F_84 ( V_92 ) ;
return V_21 ;
}
static int T_2 F_143 ( void )
{
int V_21 ;
V_21 = F_144 ( & V_149 ) ;
if ( V_21 )
goto V_24;
V_21 = F_144 ( & V_150 ) ;
if ( V_21 )
goto V_151;
V_21 = F_144 ( & V_152 ) ;
if ( V_21 )
goto V_153;
V_21 = F_144 ( & V_154 ) ;
if ( V_21 )
goto V_155;
V_24:
return V_21 ;
V_155:
F_145 ( & V_152 ) ;
V_153:
F_145 ( & V_150 ) ;
V_151:
F_144 ( & V_149 ) ;
goto V_24;
}
static void T_3 F_146 ( void )
{
F_145 ( & V_154 ) ;
F_145 ( & V_152 ) ;
F_145 ( & V_150 ) ;
F_145 ( & V_149 ) ;
}
